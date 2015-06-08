#include "PosController.h"
#include <exception>
#include <xutility>

const float MAX_DISANCE_LIMIT = 60.0f;

PosController* PosController::pInstance = nullptr; 
CCriticalSection PosController::m_sCriticalSection; 
static bool EqualToZero(float f)
{
	const float EPSINON = 0.00001f;
	if (f > -EPSINON && f < EPSINON)
	{
		return true;
	}
	return false;
}


PosController::PosController(void)
{
	Initialize();
}


PosController::~PosController(void)
{
}

void PosController::Initialize()
{
	pciState	= false;
	curAxis		= X_Axis;
	curZStart	= curStart = 0.02;
	curZSpeed	= curSpeed = 0.06;
	curZAcc		= curAcc   = 0.01;

	m_xPercent = 0.0f;
	m_yPercent = 0.0f;
	m_zPercent = 0.0f;

}


bool PosController::ShakeHandWithDevInterface()
{
	//���ƿ���ʼ��
	int nCard = 0;
	nCard = d1000_board_init();
	if (nCard <= 0)
	{
		//MessageBox(NULL,TEXT("��ʼ��ʧ��"),TEXT("���ƿ���ʼ��ʧ�ܣ���ر����г��������!"),MB_OK);
		return false;
	}

	try
	{
		d1000_set_pls_outmode(X_Axis, 0);  //pulse/dir ģʽ��������������Ч
		d1000_set_pls_outmode(Y_Axis, 0);  //pulse/dir ģʽ��������������Ч
		d1000_set_pls_outmode(Z_Axis, 0);  //pulse/dir ģʽ��������������Ч
	}
	catch(std::exception & e)
	{
		//MessageBox(NULL,TEXT("��ʼ��ʧ��"),TEXT("���ƿ���ʼ��ʧ�ܣ���ر����г��������!"),MB_OK);
		return false;
	}

	pciState = true;
	return true;

}
/// <summary>
/// ����ֱ���˶�����
/// </summary>
/// <param name="UseAxis">��ţ�0��X   1��Y   2��Z   3��T</param>
/// <param name="UseStart"></param>
/// <param name="UseAcc"></param>
/// <param name="UseSpeed"></param>
/// <param name="UseMove"></param>�˶�����: 
void PosController::axisMove( int UseAxis,  double UseStart, double UseAcc, double UseSpeed, double UseMove )
{
	if (!check_Val(UseStart, MAX_START_SPEED/*,  HT_Public.AxisName[this.UseAxis] + " ����ʼ�ٶȱ�����������ֻ����[ 0-" + MaxStartSpeed.ToString().Trim() + " ]֮����ֵ��"*/))
	{
		return;
	}
	if (!check_Val(UseAcc, MAX_ACC_SPEED/*, HT_Public.AxisName[this.UseAxis] + " ��Ӽ��ٶȱ�����������ֻ����[ 0-" + MaxAccSpeed.ToString().Trim() + " ]֮����ֵ��"*/))
	{
		return;
	}
	if (!check_Val(UseSpeed, MAX_RUN_SPEED/*, HT_Public.AxisName[this.UseAxis] + " �������ٶȱ���Ϊ��������ֻ����[ 0-" + MaxRunSpeed.ToString().Trim() + " ]֮����ֵ��"*/))
	{
		return;
	}

	// 	if (!check_Val(UseMove, 0/*, HT_Public.AxisName[this.UseAxis] + " ������λ�Ʊ���Ϊ������"*/))
	// 	{
	// 		return;
	// 	}

	double UseEncConst = PulseUnit[UseAxis];  //��ȡ���嵱��

	int start   = (int)(UseStart * UseEncConst);		    //�����ٶ�
	double fAcc = (double)(UseAcc * UseEncConst);				//���ٶ�
	int speed   = (int)(UseSpeed * UseEncConst);		    //�����ٶ�
	int move    = (int)(UseMove * UseEncConst);			//���в���

	if (!isConnected()) 
	{
		return;
	}
	//��⵱�����Ƿ����˶�
	if (!checkAxisDown(UseAxis)) 
	{
		return;
	}
	//������Ƿ񵽼���
	if (!check_Limit(UseAxis, UseMove,true)) 
	{
		//MessageBox(NULL, TEXT("����!"), TEXT("���˶������ޣ��뷴���˶���"),MB_OK);
		return;
	}
	//ֹͣ��ǰ��
	int Ret = d1000_immediate_stop(UseAxis);
	d1000_start_t_move(UseAxis, move, start, speed, fAcc);
}

/// <summary>
/// �����˶�����
/// </summary>
/// <param name="UseAxis">��ţ�0��X   1��Y   2��Z   3��T</param>
/// <param name="UseStart"></param>
/// <param name="UseAcc"></param>
/// <param name="UseSpeed"></param>
/// <param name="UseMove"></param>�˶�����: 
void PosController::axisXYMove( double UseStart, double UseAcc, double UseSpeed)
{
	if (!check_Val(UseStart, MAX_START_SPEED/*,  HT_Public.AxisName[this.UseAxis] + " ����ʼ�ٶȱ�����������ֻ����[ 0-" + MaxStartSpeed.ToString().Trim() + " ]֮����ֵ��"*/))
	{
		return;
	}
	if (!check_Val(UseAcc, MAX_ACC_SPEED/*, HT_Public.AxisName[this.UseAxis] + " ��Ӽ��ٶȱ�����������ֻ����[ 0-" + MaxAccSpeed.ToString().Trim() + " ]֮����ֵ��"*/))
	{
		return;
	}
	if (!check_Val(UseSpeed, MAX_RUN_SPEED/*, HT_Public.AxisName[this.UseAxis] + " �������ٶȱ���Ϊ��������ֻ����[ 0-" + MaxRunSpeed.ToString().Trim() + " ]֮����ֵ��"*/))
	{
		return;
	}

	// 	if (!check_Val(UseMove, 0/*, HT_Public.AxisName[this.UseAxis] + " ������λ�Ʊ���Ϊ������"*/))
	// 	{
	// 		return;
	// 	}

	double UseEncConst = PulseUnit[X_Axis];  //��ȡ���嵱��


	float tempPercent = min(abs(m_xPercent), abs(m_yPercent));

	int start   = (int)(UseStart * UseEncConst * tempPercent);		    //�����ٶ�
	double fAcc = (double)(UseAcc * UseEncConst * tempPercent);				//���ٶ�
	int speed   = (int)(UseSpeed * UseEncConst * tempPercent);		    //�����ٶ�
	
	if (!isConnected()) 
	{
		return;
	}
	//��⵱�����Ƿ����˶�
	if (!checkAxisDown(X_Axis) || !checkAxisDown(Y_Axis)) 
	{
		return;
	}

	long DistArray[2] = {0};
	DistArray[0] = getUserMove(m_xPercent) * UseEncConst; 
	DistArray[1]= getUserMove(m_yPercent) * UseEncConst;

	//������Ƿ񵽼���
	if (!check_Limit(X_Axis, getUserMove(m_xPercent),true))
	{
		YMove();
		return;
	}
	if (!check_Limit(Y_Axis, getUserMove(m_yPercent), true))
	{
		XMove();
		return;
	}

	//ֹͣ��ǰ��
	d1000_immediate_stop(X_Axis);
	d1000_immediate_stop(Y_Axis);


	short AxisArray[2] = {X_Axis, Y_Axis};
	d1000_start_t_line (2,AxisArray,DistArray, start, speed,fAcc);
}




/// <summary>
/// ������Ƿ񵽼���λ��
/// </summary>
/// <param name="UseAxis">��ţ�0��X   1��Y   2��Z   3��T</param>
/// <param name="UseMove">�˶��г̣�������֮��</param>
/// <param name="ifMsg">�Ƿ񵯳���ʾ</param>
/// <returns></returns>
bool PosController::check_Limit(int UseAxis, double UseMove,bool ifMsg)
{

	int plState = 0;
	int BitNo=0;
	bool lmtState = true;
	switch (UseAxis)
	{ 
	case 0:
		BitNo = UseMove >= 0 ? 4 : 5;
		break;
	case 1:
		BitNo = UseMove >= 0 ? 6 : 7;
		break;
	case 2:
		BitNo = UseMove >= 0 ? 8 : 9;
		break;
	}

	//if (ifMsg) HT_Public.Msg(BitNo.ToString());

	plState = d1000_in_bit(BitNo); //1��ʾ��Ч��0��ʾ��Ч


	if (plState == 0 && UseMove > 0)
	{
		//if (ifMsg) HT_Public.Msg(HT_Public.AxisName[UseAxis] + " ���ѵ�������λ�ã��뷴������!");
		lmtState= false;
	}
	if (plState == 0 && UseMove < 0)
	{
		//if (ifMsg) HT_Public.Msg(HT_Public.AxisName[UseAxis] + " ���ѵ�������λ�ã��뷴������!");
		lmtState= false;
	}
	return lmtState;
}

bool PosController::isConnected()
{
	return pciState;
}

bool PosController::check_Val(double nowVal, double maxValue)
{
	if ( nowVal <= 0 || nowVal > maxValue )
	{
		return false;
	}
	return true;
}

bool PosController::checkAxisDown( int CurAxis )
{
	int ret;
	ret = d1000_check_done(CurAxis);
	if (ERR_OK == ret)
	{
		//if (ifMsg) HT_Public.Msg("�Բ���" + HT_Public.AxisName[CurAxis] + " �����������У�");
		return false;
	}
	return true;
}
/// <summary>
/// ��ͣ������
/// </summary>
void PosController::stop_All()
{
	if (!isConnected()) 
	{
		return;
	}
	axisStop(X_Axis, false);
	axisStop(Y_Axis, false);
	axisStop(Z_Axis, false);
}

/// <summary>
/// ����١�����ֹͣ
/// </summary>
/// <param name="CurAxis">��ţ�0��X   1��Y   2��Z   3��T</param>
/// <param name="ifDecStop">true������ֹͣ  false:����ֹͣ</param>
void PosController::axisStop(int CurAxis, bool ifDecStop)
{
	if (!isConnected()) 
	{
		return;
	}

	int Ret;
	if (ifDecStop)
	{
		Ret = d1000_decel_stop(CurAxis);
	}
	else
	{
		Ret = d1000_immediate_stop(CurAxis);
	}
}

void PosController::XMove()
{
	//TODO:Need to set value
	curAxis  = X_Axis;
	axisMove(curAxis,curStart,curAcc,curSpeed,getUserMove(m_xPercent));
}


void PosController::YMove()
{
	//TODO:Need to set value
	curAxis  = Y_Axis;
	axisMove(curAxis,curStart,curAcc,curSpeed,getUserMove(m_yPercent));
}

void PosController::ZMove()
{
	//TODO:Need to set value
	curAxis  = Z_Axis;
	axisMove(curAxis,curZStart,curZAcc,curZSpeed,getUserMove(m_zPercent));
}


void PosController::Close()
{
	if (pciState)
	{
		stop_All();
		//�رտ�����
		d1000_board_close();
		pciState = false;
	}
}

void PosController::SetSpeed( double speed )
{
	if (curSpeed != speed)
	{
		curSpeed = speed;
	}
}

void PosController::MultiMove(float xPercent, float yPercent, float zPercent)
{
	m_xPercent = xPercent;
	m_yPercent = yPercent;
	m_zPercent = zPercent;
	
	if (!EqualToZero(zPercent))
	{
		ZMove();
		return;
	}

	if (!EqualToZero(xPercent) && !EqualToZero(yPercent))
	{
		XYMove();
		return;
	}
	if(!EqualToZero(xPercent))
	{
		XMove();
		return;
	}
	
	if (!EqualToZero(yPercent))
	{
		YMove();
	}
}

void PosController::XYMove()
{
	axisXYMove(curStart, curAcc, curSpeed);
}


float PosController::getUserMove(float f)
{
	if (f < 0)
	{
		return MAX_DISANCE_LIMIT;
	}
	else
	{
		return -MAX_DISANCE_LIMIT;
	}
}

void PosController::SetZSpeed(float factor)
{
	curZStart	= 0.02 * factor;
	curZSpeed	= 0.06 * factor;
	curZAcc		= 0.01 * factor;
}

void PosController::SetXYSpeed(int factor)
{
	curStart = 0.02 * factor;
	curSpeed = 0.06 * factor;
	curAcc	 = 0.01 * factor;
}

double PosController::GetCurrZPosition()
{
	long pposition = 0;
	pposition = d1000_get_command_pos(Z_Axis);
	return (double)pposition / PulseUnit[Z_Axis];
}

void PosController::SetCurrZPosition(double dfPos)
{
	d1000_set_command_pos(Z_Axis, dfPos);
}



PosController * PosController::GetInstance()
{
	if(pInstance == nullptr)  
	{   //double check  
		m_sCriticalSection.Lock();           //��lockʵ���̰߳�ȫ������Դ�����࣬ʵ���쳣��ȫ  
		//ʹ����Դ�����࣬���׳��쳣��ʱ����Դ���������ᱻ�������������Ƿ�������������Ϊ�쳣�׳��������������  
		pInstance = new PosController();
		if (!pInstance)
		{
			return nullptr;
		}
		if(!pInstance->ShakeHandWithDevInterface())
		{
			TRACE(TEXT("m_piezoPtr->ShakeHandWithDevInterface() Failed"));
			return nullptr;
		}
		m_sCriticalSection.Unlock();
	}  
	return pInstance;  
}

void PosController::Destroy()
{
	if (pInstance)
	{
		delete pInstance;
		pInstance = nullptr;
	}
}





