#include "StdAfx.h"
#include "XMTDev.h"

#pragma comment(lib, "./Libraries/XMT_USB/DLL_XMT_USB.lib")
#pragma comment(lib, "./Libraries/CyUsb/cyApi.lib")

CXMTDev::CXMTDev(void)
	: m_eInterfaceType(DEV_INTERFACE_NONE),
	m_bDevInterfaceOK(false)
{
	m_eInterfaceType = DEV_INTERFACE_USB;
	m_num_device = 0;
	Now_control_mcu_address = 1;
}


CXMTDev::~CXMTDev(void)
{
}


// ��ʼ���õ��Ľӿ�
int CXMTDev::InitDevInterface( ST_INTERFACE_PARA stIntfPara )
{
	BOOL bInitDevOK = FALSE;

	//�豸�Ѿ���
	if (m_bDevInterfaceOK)
	{
		return TRUE;
	}

	m_pUsbDev = std::make_shared<CCyUSBDevice>();

	int deviceNumber = NUM_OF_TOTAL_USB_DEVICE_LABVIEW();

	m_num_device = deviceNumber - 1;

	bool flag_usb_openOrClose = IsOpenUsbDevice_LABVIEW();
	if(!flag_usb_openOrClose)
	{
		if(!Open_Num_Of_USB_LABVIEW(deviceNumber))
			AfxMessageBox(TEXT(" USB ��ʼ��ʧ�ܣ���ص������ͶϿ�USB�����Լ���������ȿ�������5�������USB�������ٿ������!"));
		return	 FALSE;
	}

	m_bDevInterfaceOK = TRUE;

	//if (DEV_INTERFACE_COM == m_eInterfaceType)
	//{
	//	TRACE("XMT::Initializing COM interface ....\n");
	//	m_pSerialDev = std::make_shared<CMSComm>();

	//	CString strComInit;
	//	if(m_pSerialDev->GetPortOpen())
	//		m_pSerialDev->SetPortOpen(FALSE);//��GetPortOpen()���������ڵļ�����˿�    
	//	m_pSerialDev->SetCommPort(stIntfPara.com.iSerialNum); // ָ�����ں�
	//	strComInit.Format(_T("%d"), stIntfPara.com.iBraudRate);
	//	strComInit+=",N,8,1";
	//	m_pSerialDev->SetSettings(strComInit); // ͨ�Ų�������
	//	m_pSerialDev->SetInBufferSize(1024); // ָ�����ջ�������С
	//	m_pSerialDev->SetOutBufferSize(1024);//���ͻ�����
	//	m_pSerialDev->SetInBufferCount(0); // ��ս��ջ�����
	//	m_pSerialDev->SetInputMode(1); // �������ݻ�ȡ��ʽ
	//	m_pSerialDev->SetInputLen(0); // ���ö�ȡ��ʽ
	//	m_pSerialDev->SetPortOpen(1); // ��ָ���Ĵ���
	//	m_pSerialDev->GetInput();//��Ԥ���������������������

	//	m_bDevInterfaceOK = TRUE;
	//}
	//else if (DEV_INTERFACE_USB == m_eInterfaceType)
	//{
	//	
	//	TRACE("XMT::Initializing USB interface ....\n");

	//	m_pUsbDev = std::make_shared<CCyUSBDevice>();

	//	int num_of_USB = NUM_OF_TOTAL_USB_DEVICE_LABVIEW();

	//	if (num_of_USB == 0)
	//	{
	//		TRACE("Has no usb device connected \r\n");
	//		return USB_DEVICE_NOT_EXIST;
	//	}

	//	bInitDevOK =m_pUsbDev->Open(num_of_USB -1);

	//


	//	if (bInitDevOK)
	//	{
	//		read_system_T_P_R(10,'A','B','C');
	//		Read_V_S_Status(1);
	//		m_bDevInterfaceOK = TRUE;
	//		return TRUE;
	//	}

	//	TRACE("OpenUsb Failed \r\n");

		
	//}
	//else
	//{
	//	
	//}

	return USB_DEVICE_NOT_OPEN;;
}


// �ر��豸�ӿ�
void CXMTDev::DeInitDevInterface(void)
{
	if (!m_bDevInterfaceOK)
	{
		return;
	}

	////���豸�Ѿ���ʼ��
	//if (DEV_INTERFACE_COM == m_eInterfaceType)
	//{

	//}
	//else if (DEV_INTERFACE_USB == m_eInterfaceType)
	//{
	//	m_pUsbDev->Close();

	//	BOOL isOpen = m_pUsbDev->IsOpen();

	//	if (isOpen)
	//	{
	//		TRACE(_T("Close Device Failed!"));
	//	}
	//}
	//else
	//{

	//}
}


// ���豸�ӿڽ�������
BOOL CXMTDev::ShakeHandWithDevInterface(void)
{
	if (!m_bDevInterfaceOK)
	{
		return false;
	}

	//���豸�Ѿ���ʼ��
	if (DEV_INTERFACE_COM == m_eInterfaceType)
	{

	}
	else if (DEV_INTERFACE_USB == m_eInterfaceType)
	{
	}
	else
	{

	}
	
	return true;
}

void CXMTDev::SetSz()
{
	int address;//��ַ��
	int Command_B3;//ָ����
	int Command_B4;//ָ����
	unsigned char Channel_Num;
	unsigned char SetFlag;


	address = Now_control_mcu_address;   //��ַ��
	Command_B3 = 20; //ָ����
	Command_B4 = 0; //ָ����
	Channel_Num = 0;//ͨ��
	SetFlag = 'D';//'A':ģ��,'D':����;

	XMT_COMMAND_Assist_SetFlag(address,
		Command_B3,
		Command_B4,
		Channel_Num,
		SetFlag
		);
}

void CXMTDev::SetCloseState()
{
	int address_ma;//��ַ��

	int Command_B3;//ָ����
	int Command_B4;//ָ����
	int Channel_Num;//ͨ����
	unsigned char SetFlag;//��־λ 

	address_ma = Now_control_mcu_address;   //��ַ��
	Command_B3 = 18; //ָ����
	Command_B4 = 0; //ָ����
	Channel_Num = 0;  //ͨ����
	SetFlag  = 'C'; //�ջ�  
	//����Э����
	//����  18 20 22 
	XMT_COMMAND_Assist_SetFlag(address_ma,
		Command_B3,
		Command_B4,
		Channel_Num,
		SetFlag
		);
}

BOOL CXMTDev::GetCloseState()
{
	int address;//��ַ��
	int Command_B3;//ָ����
	int Command_B4;//ָ����
	unsigned char Channel_Num;


	address = Now_control_mcu_address;   //��ַ��
	Command_B3 = 19; //ָ����
	Command_B4 = 0; //ָ����
	Channel_Num = 0;

	unsigned char  tmp_data;

	//��ȡflag���� 19 21 23 
	tmp_data =  XMT_COMMAND_Assist_ReadFlag(address,
		Command_B3,
		Command_B4,
		Channel_Num
		);
	return (tmp_data=='C'); //�ջ�
}
BOOL CXMTDev::CheckLoopState()
{
	SetSz();

	SetCloseState();

	if (!GetCloseState())
	{
		TRACE(TEXT("���ñջ�״̬ʧ��"));
		return FALSE;
	}

	return TRUE;


	/*int iLoopState;

	if(NO_ERR != GetLoopConfig(1, &iLoopState))
	{
		TRACE(TEXT("GetLoopConfig(1, &iLoopState) failed"));
		return FALSE;
	}
	if(LOOP_CLOSE != iLoopState)
	{
		TRACE(TEXT("iLoopState != LOOP_Close failed"));
		return FALSE;
	}*/
	return TRUE;
}


// ��λ����

/*
	  �����ʽ: SendSiglePosCmd('S','A',m_point_MVS);
	  ����˵��: ����һ·λ������
	  ͨ    ��: 'A'---һ·ͨ��
	            'B'---��·ͨ��
			    'C'---��·ͨ��
	  
	  ��    ��: point_MVS �����λ����ֵ ����ֵӦ������Сλ�ƺ����λ������
				V_OR_S ���ջ�ѡ�� 'V'���� 'S'�ջ�

	  ��������: ****
*/
int CXMTDev::SendSinglePosCmd(LOOP_STATUS V_or_S, int iChannel, double point_MVS)
{
	int address_ma;//��ַ��

	int Command_B3;//ָ����
	int Command_B4;//ָ����
	int Channel_Num;//ͨ����
	double Send_data_temp;
	Send_data_temp = point_MVS;//���͵�����ֵ ģ������

	address_ma = Now_control_mcu_address;   //��ַ��
	Command_B3 = 1; //ָ����
	Command_B4 = 0; //ָ����
	Channel_Num = 0;  //ͨ����
	XMT_COMMAND_SinglePoint(address_ma,Command_B3,Command_B4,Channel_Num,Send_data_temp);

	return NO_ERR;
}

int CXMTDev::SendMultiPosCmdEx(LOOP_STATUS V_or_S, int iChannel, float point_MVS[], int num)
{
	LOOP_STATUS loopStatus = LOOP_NONE;

	if(!m_bDevInterfaceOK || !m_pUsbDev)
		return SEND_CMD_ERR;


	unsigned char chV_or_S = 'N';
	unsigned char chChannel = 'N';

	if (chV_or_S == LOOP_OPEN)
	{
		chV_or_S = 'V';
	}
	else
	{
		chV_or_S = 'S';
	}

	chChannel = 'A' + (iChannel - 1);
	float curPos = 0.0;

	for(int i = 0; i < num; ++i)
	{
		SendSinglePosCmd(V_or_S, iChannel, point_MVS[i]);
		SleepMs(50);
	}
	

	return NO_ERR;
}

void CXMTDev::SleepMs(int timesspan)
{
	long   timeon   =   GetTickCount();
	long   timeoff   =   timeon;
	MSG   msg;
	do{
		if   (::PeekMessage(&msg,NULL,0,0,PM_REMOVE))   {   //��Windows��Ϣ������ȡ����Ϣ
			if   (msg.message==   WM_QUIT)//�����ϢΪ�˳��������˳���Ϣ
			{
				::PostQuitMessage(-1);
			}
			if(!AfxGetApp()-> PreTranslateMessage(&msg))//����޷�Ԥ������Ϣ
			{
				::TranslateMessage(&msg);//ת����Ϣ
				::DispatchMessage(&msg);//������Ϣ
			}
			timeoff   =   GetTickCount();
		}
	}while(timeoff-timeon <timesspan);
}

// ��λ���
int CXMTDev::SendMultiPosCmd(float fengfengzhi, float pinlv, float pianzhi)
{
	//������
	//��·����  12 13 
	unsigned char address;
	unsigned char Command_B3;
	unsigned char Command_B4;
	unsigned char Channel_Num;
	unsigned char WaveType;

	//��ֵ    
	address = Now_control_mcu_address;   //��ַ��

	Command_B3 = 13; //ָ����
	Command_B4 = 0; //ָ����
	Channel_Num = 0;  //ͨ����
	WaveType = 	'J';

	//������
	//��·����  12 13 
	XMT_COMMAND_WaveSetHighSingle(address,
		Command_B3,
		Command_B4,
		Channel_Num,
		WaveType,
		fengfengzhi,
		pinlv,
		pianzhi
		);		
	return 0;
}

void CXMTDev::Stop()
{
	int address;//��ַ��
	int Command_B3;//ָ����
	int Command_B4;//ָ���� 


	address = Now_control_mcu_address;   //��ַ��
	Command_B3 = 14; //ָ����
	Command_B4 = 0; //ָ����


	XMT_COMMAND_WaveSetHighSingleStop(address,
		Command_B3,
		Command_B4
		);
}

// ��ȡ���ջ�״̬
LOOP_STATUS CXMTDev::Read_V_S_Status(int iChannel)
{

	LOOP_STATUS loopStatus = LOOP_NONE;

	if(!m_bDevInterfaceOK || !m_pUsbDev)
		return loopStatus;

	if(iChannel < 0 || iChannel > 3)
		return loopStatus;

	DEV_LOOP_IO_CONFIGURATION_INFO devLoopAndIOConiguration;

	if (NO_ERR != GetLoopAndIOConfiguration(&devLoopAndIOConiguration))
	{
		return loopStatus;
	}

	unsigned char chLoopState;

	switch(iChannel)
	{
	case 1:
		chLoopState = devLoopAndIOConiguration.LoopState_ch1;
		break;
	case 2:
		chLoopState = devLoopAndIOConiguration.LoopState_ch2;
		break;
	case 3:
		chLoopState = devLoopAndIOConiguration.LoopState_ch3;
		break;
	}

    if(chLoopState == 'O')
	{
		loopStatus = LOOP_OPEN;
	}
	else
	{
		loopStatus = LOOP_CLOSE;
	}

	return loopStatus;
}


// ��ȡλ������ϵͳ��Ϣ
int CXMTDev::ReadSysInfo(ST_XMT_SYS_INFO *stSysInfo)
{
	if(!m_bDevInterfaceOK || !m_pUsbDev)
		return USB_DEVICE_NOT_OPEN;

	//��ϵͳ����
	//read_system_T_P_R(m_pUsbDev.get(), 10, 'T', 'P', 'R');

    /*
	  �����ʽ: read_system_T_P_R(10,'T','P','R');
	  �����: 10/2=5
	  ����˵��: read_system_T_P_R(10,'T','P','R');
	            ��ȡ��λ����ϵͳ��Ϣ
	*/
	Sleep(200);
	float recive_data_usb[9];	
	//read_System_real_info_16(recive_data_usb,'R','P');

	stSysInfo->systemMinV = recive_data_usb[0];
	stSysInfo->systemMaxV = recive_data_usb[1];

	stSysInfo->systemMinStep = recive_data_usb[2];
	stSysInfo->systemMaxStep_ch1 = recive_data_usb[3];
	stSysInfo->systemMaxStep_ch2 = recive_data_usb[4];
	stSysInfo->systemMaxStep_ch3 = recive_data_usb[5];
	
	stSysInfo->systemPower_ch1 = recive_data_usb[6];
	stSysInfo->systemPower_ch2 = recive_data_usb[7];
	stSysInfo->systemPower_ch3 = recive_data_usb[8];
	
	return SEND_CMD_OK;
}


// ���ø���
int CXMTDev::SetLoadSz(int iChannel, float LoadSz )
{
	if(!m_bDevInterfaceOK || !m_pUsbDev)
		return USB_DEVICE_NOT_OPEN;

	if(iChannel < 0 || iChannel > 3)
		return CHANNEL_NOT_EXSIT;

	unsigned char chChannel = 'A' + (iChannel - 1);

	//write_system_fuzai(m_pUsbDev.get(), 16, 'T', 'L', 'W', chChannel, LoadSz);	 //�궨һ·����

	/*
	  �����ʽ: write_system_fuzai(16,'T','L','W','A',1.9);	 //�궨һ·����
	  �����: 16/2=8
	  ����˵��: �궨һ·����
	  ͨ    ��: 'A'---һ·ͨ��
	            'B'---��·ͨ��
			    'C'---��·ͨ��
	  ��    ��: 1.9 Ϊ�궨��һ·ͨ���ĸ�����ֵ ����ֵ����ʵ�������д

	  ��������: ****
	*/

	return SEND_CMD_OK;
}


// ��ȡ����
int CXMTDev::GetLoadSz(int iChannel, float *LoadSz)
{
	if(!m_bDevInterfaceOK || !m_pUsbDev)
		return USB_DEVICE_NOT_OPEN;

	if(iChannel < 0 || iChannel > 3)
		return CHANNEL_NOT_EXSIT;

	unsigned char chChannel = 'A' + (iChannel - 1);

	float float_fzai;

	//read_system_fuzai(m_pUsbDev.get(), 12, 'T', 'L', 'R', chChannel);
	 /*
	  �����ʽ: read_system_T_P_R(10,'T','R','A');
	  �����: 10/2=5
	  ����˵��: read_system_T_P_R(10,'T','R','A');
	  ͨ    ��: ����Ԥ����ȡ1·�ĸ�����ֵ 
	            ͨ  ��
	                  'A'---һ·ͨ��
	                  'B'---��·ͨ��
					  'C'---��·ͨ��
	         
	*/
	Sleep(200);
	//float_fzai = read_System_real_V_S_and_fuzai('R', 'L', chChannel); //���ݲ�ͬ������������
	 /*
	  �����ʽ:  read_System_real_V_S_and_fuzai('R','L','A'); ��������������
	  �����: **
	  ����˵��: ��λ����USB�˿ڶ�ȡһ·��ѹ����(��������)  read_System_real_V_S_and_fuzai('R','L','A');
	  ͨ    ��: ��ȡ1·�ĸ�����ֵ 
		        ͨ  ��
		        'A'---һ·ͨ��
		        'B'---��·ͨ��			    
				'C'---��·ͨ��

	  ��������: ʹ��float_fzai������������Ϣ 
	*/

	*LoadSz = float_fzai;

	return SEND_CMD_OK;
}


// �����豸��ͣ�ٶ�
int CXMTDev::SetDevStartAndStopSpeed(int iChannel, ST_DEV_START_STOP_SPEED stSpeed)
{
	if(!m_bDevInterfaceOK || !m_pUsbDev)
		return USB_DEVICE_NOT_OPEN;

	if(iChannel < 0 || iChannel > 3)
		return CHANNEL_NOT_EXSIT;

	unsigned char chChannel = 'A' + (iChannel - 1);

	unsigned char chStartSpeed, chStopSpeed;

	switch(iChannel)
	{
	case 1:
		chStartSpeed = stSpeed.startSpeed_ch1;
		chStopSpeed = stSpeed.stopSpeed_ch1;
		break;
	case 2:
		chStartSpeed = stSpeed.startSpeed_ch2;
		chStopSpeed = stSpeed.stopSpeed_ch2;
		break;
	case 3:
		chStartSpeed = stSpeed.startSpeed_ch3;
		chStopSpeed = stSpeed.stopSpeed_ch3;
		break;
	default:
		chStartSpeed = 'L';
		chStopSpeed = 'L';
	}
	//��ʼ //ֹͣ
	//send_wave_mode_CH_H_S(m_pUsbDev.get(), 14, 'T', 'M', chChannel, chStartSpeed, chStopSpeed);

	//���ò�����ͣ�ٶ�
   	/*
	  �����ʽ:  send_wave_mode_CH_H_S(14,'T','M','A','H','H');
	  �����:  14/2=7
	  ����˵��:  send_wave_mode_CH_H_S(14,'T','M','A',WAVE_BEGIN_SPEED,WAVE_END_SPEED); 
	           ͨ  ��: 
	             'A'---һ·ͨ��
	             'B'---��·ͨ��
			     'C'---��·ͨ��
               WAVE_BEGIN_SPEED:  ������ʼ�ٶ� 'H'��ʾ���� 'S'��ʾ����
	           WAVE_END_SPEED  :  ����ֹͣ�ٶ� 'H'��ʾ���� 'S'��ʾ����			  
	/*  
	  ����:
	  USER_USB.send_wave_mode_CH_H_S(14,'T','M','A','H','S'); //һ·����Ϊ��
	  
	  USER_USB.send_wave_mode_CH_H_S(14,'T','M','B','H','H');
		
	  USER_USB.send_wave_mode_CH_H_S(14,'T','M','C','H','H');	
	*/
	return SEND_CMD_OK;
}


// ��ȡ�豸��ͣ�ٶ�
int CXMTDev::GetDevStartAndStopSpeedAllChannel(ST_DEV_START_STOP_SPEED *stSpeed)
{
	if(!m_bDevInterfaceOK || !m_pUsbDev)
		return USB_DEVICE_NOT_OPEN;

#if 0
	if(iChannel < 0 || iChannel > 3)
		return CHANNEL_NOT_EXSIT;

	char chChannel = 'A' + (iChannel - 1);
#endif

	//read_system_T_P_R(m_pUsbDev.get(),10,'T','M','R');//��ȡ��λ���Ĳ��ε�����ģʽ	

	/*
	  �����ʽ: read_system_T_P_R(10,'T','M','R');
	  �����: 10/2=5
	  ����˵��: read_system_T_P_R(10,'T','M','R');
	  ͨ    ��: ��ȡ��λ���Ĳ��ε�����ģʽ
	*/

	Sleep(200);
	unsigned char  recive_data_usb_wave_send_mode[6];	
	//read_System_real_info_wave_begin_stop(recive_data_usb_wave_send_mode,'R','M');

	/*
	  �����ʽ:  read_System_real_info_wave_begin_stop(recive_data_usb_wave_send_mode,'R','M'); ��������������
	  �����: **
	  ����˵��: ��λ����USB�˿ڶ�ȡ1,2,3·������ͣ�ٶ� , read_System_real_info_wave_begin_stop(recive_data_usb_wave_send_mode,'R','M');
	  ͨ    ��: ��ȡ1��2��3·,������ͣ�ٶ�
	  ��������: ʹ��recive_data_usb_wave_send_mode[6]����������1,2,3·���ε���ͣ���ٶ�
	            ����״̬��Ϣ����1��2��3·ͨ����·���ε���ͣ���ٶ�
                recive_data_usb_wave_send_mode[0] -- һ·ͨ�����ε���ͣ���ٶ���Ϣ('H'---����,'S'---����)
				recive_data_usb_wave_send_mode[1] -- һ·ͨ�����ε���ͣ���ٶ���Ϣ('H'---����,'S'---����)

				recive_data_usb_wave_send_mode[2] -- ��·ͨ�����ε���ͣ���ٶ���Ϣ('H'---����,'S'---����)
                recive_data_usb_wave_send_mode[3] -- ��·ͨ�����ε���ͣ���ٶ���Ϣ('H'---����,'S'---����)

				recive_data_usb_wave_send_mode[4] -- ��·ͨ�����ε���ͣ���ٶ���Ϣ('H'---����,'S'---����)
				recive_data_usb_wave_send_mode[5] -- ��·ͨ�����ε���ͣ���ٶ���Ϣ('H'---����,'S'---����)
	*/

	stSpeed->startSpeed_ch1 = recive_data_usb_wave_send_mode[0];
	stSpeed->stopSpeed_ch1 = recive_data_usb_wave_send_mode[1];

	stSpeed->startSpeed_ch2 = recive_data_usb_wave_send_mode[2];
	stSpeed->stopSpeed_ch2 = recive_data_usb_wave_send_mode[3];

	stSpeed->startSpeed_ch3 = recive_data_usb_wave_send_mode[4];
	stSpeed->stopSpeed_ch3 = recive_data_usb_wave_send_mode[5];

	return SEND_CMD_OK;
}


// ��ȡ��������
int CXMTDev::ReadSiglePosCmd(LOOP_STATUS V_or_S, int iChannel, float *Val_VS)
{

	//LOOP_STATUS loopStatus = LOOP_NONE;

	//if(!m_bDevInterfaceOK || !m_pUsbDev)
	//	return USB_DEVICE_NOT_OPEN;

	//loopStatus = Read_V_S_Status(iChannel);

	//if (LOOP_NONE == loopStatus || V_or_S != loopStatus)
	//{
	//	return SEND_CMD_ERR;
	//}

	//unsigned char chV_or_S = 'N';
	//unsigned char chChannel = 'N';

	//if (chV_or_S == LOOP_OPEN)
	//{
	//	chV_or_S = 'V';
	//}
	//else
	//{
	//	chV_or_S = 'S';
	//}

	//chChannel = 'A' + (iChannel - 1);

	//read_System_V_S(m_pUsbDev.get(), 12, 'T', 'D', chV_or_S, chChannel);
	///*
	//  �����ʽ: read_System_V_S(12,'T','D','V','A');
	//  �����:12/2=6
	//  ����˵��:����Ԥ����ȡһ·��ѹ����  read_System_V_S(12,'T','D','V','A');
	//  ͨ    ��:'A'---һ·ͨ��
	//           'B'---��·ͨ��
	//		   'C'---��·ͨ��
	//*/
	//Sleep(200);
	//*Val_VS = read_System_real_V_S_and_fuzai('R', chV_or_S, chChannel);
	///*
	//  �����ʽ: read_System_real_V_S_and_fuzai('R','V','A'); ��������������
	//  �����: **
	//  ����˵��:��λ����USB�˿ڶ�ȡһ·��ѹ����(��������)  read_System_real_V_S_and_fuzai('R','V','A');
	//  ͨ    ��:'A'---һ·ͨ��
	//           'B'---��·ͨ��
	//		   'C'---��·ͨ��
	//  ��������:һ·�ĵ�ѹ��ֵ(��ȡ��һ·�ĵ�ѹ��ֵ)
	//*/
	return SEND_CMD_OK;
}


// ʹ����λ��ͨ��USB����
int CXMTDev::EnablePCConsole(void)
{
	//if(!m_bDevInterfaceOK || !m_pUsbDev)
	//	return USB_DEVICE_NOT_OPEN;

	//read_system_T_P_R(m_pUsbDev.get(),10,'A','B','C'); //������λ���������� 'A','B','C'��֪ͨ��λ������ͨ��׼�� 10/2=5Ϊͨ������ĳ���

	return NO_ERR;
}


// ����IO����
int CXMTDev::SetIOConfig(int iChannel, int IO_type)
{
	if(!m_bDevInterfaceOK || !m_pUsbDev)
		return USB_DEVICE_NOT_OPEN;

	if(iChannel < 0 || iChannel > 3)
		return CHANNEL_NOT_EXSIT;

	if(IO_type != IO_INPUT && IO_type != IO_OUTPUT)
		return IO_SETTING_INVALID;

	unsigned char chChannel = 'A' + (iChannel - 1);

	unsigned char chIOtype;
	if (IO_type == IO_INPUT)
	{
		chIOtype = 'I';
	}
	else if (IO_type == IO_OUTPUT)
	{
		chIOtype = 'O';
	}

	//дIO��
   // write_System_IO(m_pUsbDev.get(), 12, 'T', 'I', chChannel, chIOtype); //һ·��� 'I'Ϊ����ģʽ
	
	/*
	  �����ʽ: write_System_IO(12,'T','I','A','O'); //һ·��� 'I'Ϊ����ģʽ
	  �����: 12/2=6
	  ����˵��: write_System_IO(12,'T','I','A','O'); //һ·��� 'I'Ϊ����ģʽ
	  ͨ    ��:'A'---һ·ͨ��
	           'B'---��·ͨ��
			   'C'---��·ͨ��
	  �������:
	           'O'---���
			   'I'---����  
	*/
	return NO_ERR;
}


// ��ȡIO����
int CXMTDev::GetIOConfig(int iChannel, int *IO_type)
{
	if(!m_bDevInterfaceOK || !m_pUsbDev)
		return USB_DEVICE_NOT_OPEN;

	if(iChannel < 0 || iChannel > 3)
		return CHANNEL_NOT_EXSIT;

	DEV_LOOP_IO_CONFIGURATION_INFO devLoopAndIOConiguration;

	if (NO_ERR != GetLoopAndIOConfiguration(&devLoopAndIOConiguration))
	{
		return GET_LOOP_IO_INFO_ERR;
	}

	unsigned char chIOState;

	switch(iChannel)
	{
	case 1:
		chIOState = devLoopAndIOConiguration.IOState_ch1;
		break;
	case 2:
		chIOState = devLoopAndIOConiguration.IOState_ch2;
		break;
	case 3:
		chIOState = devLoopAndIOConiguration.IOState_ch3;
		break;
	}

	if(chIOState == 'O')
	{
		*IO_type = IO_OUTPUT;
	}
	else
	{
		*IO_type = IO_OUTPUT;
	}

	return NO_ERR;
}

int CXMTDev::GetLoopConfig(int iChannel, int *Loop_type)
{
	if(!m_bDevInterfaceOK || !m_pUsbDev)
		return USB_DEVICE_NOT_OPEN;

	if(iChannel < 0 || iChannel > 3)
		return CHANNEL_NOT_EXSIT;

	DEV_LOOP_IO_CONFIGURATION_INFO devLoopAndIOConiguration;

	if (NO_ERR != GetLoopAndIOConfiguration(&devLoopAndIOConiguration))
	{
		return GET_LOOP_IO_INFO_ERR;
	}

	unsigned char chLoopState;

	switch(iChannel)
	{
	case 1:
		chLoopState = devLoopAndIOConiguration.LoopState_ch1;
		break;
	case 2:
		chLoopState = devLoopAndIOConiguration.LoopState_ch2;
		break;
	case 3:
		chLoopState = devLoopAndIOConiguration.LoopState_ch3;
		break;
	}

	if(chLoopState == 'O')
	{
		*Loop_type = LOOP_OPEN;
	}
	else
	{
		*Loop_type = LOOP_CLOSE;
	}

	return NO_ERR;
}

// ��ȡϵͳ���ջ���IO������Ϣ
int CXMTDev::GetLoopAndIOConfiguration(DEV_LOOP_IO_CONFIGURATION_INFO *pConfiguration)
{
	if(!m_bDevInterfaceOK || !m_pUsbDev)
		return USB_DEVICE_NOT_OPEN;

	//��IO��״̬
    //read_system_T_P_R(m_pUsbDev.get(),10,'T','T','R');
	/*
	  �����ʽ: read_system_T_P_R(10,'T','T','R');
	  �����: 10/2=5
	  ����˵��: read_system_T_P_R(10,'T','T','R');
	  ͨ    ��: ����Ԥ����ȡ1��2��3·��IO��״̬����  
	*/
	Sleep(200);
	unsigned char temp_io_info[6];
	//read_System_real_info_IO(temp_io_info,'R','T');	 //���������IO�ڵ�״̬���

	/*
	  �����ʽ:  read_System_real_info_IO(temp_io_info,'R','T'); ��������������
	  �����: **
	  ����˵��: ��λ����USB�˿ڶ�ȡһ·��ѹ����(��������)  read_System_real_V_S_and_fuzai('R','V','A');
	  ͨ    ��: ��ȡ1��2��3·��IO��״̬����
	  ��������: ʹ��temp_io_info[6]�������ӽ���IO�ڵ�״̬��Ϣ 
	            ����״̬��Ϣ����1��2��3·ͨ����IO�ڵ�������Ϣ 
                temp_io_info[0] -- һ·ͨ�����ջ���Ϣ('I'---�ջ�,'O'---����)
				temp_io_info[1] -- ��·ͨ�����ջ���Ϣ('I'---�ջ�,'O'---����)
				temp_io_info[2] -- ��·ͨ�����ջ���Ϣ('I'---�ջ�,'O'---����)

                temp_io_info[3] -- һ·ͨ��IO��Ϣ('I'---���� ,'O'---���)
				temp_io_info[4] -- ��·ͨ��IO��Ϣ('I'---���� ,'O'---���)
				temp_io_info[5] -- ��·ͨ��IO��Ϣ('I'---���� ,'O'---���)
	*/

	pConfiguration->LoopState_ch1 = temp_io_info[0];
	pConfiguration->LoopState_ch2 = temp_io_info[1];
	pConfiguration->LoopState_ch3 = temp_io_info[2];

	pConfiguration->IOState_ch1 = temp_io_info[3];
	pConfiguration->IOState_ch2 = temp_io_info[4];
	pConfiguration->IOState_ch3 = temp_io_info[5];

	return NO_ERR;
}


// ���ò���
int CXMTDev::SetWaveConfiguration(int iChannel, int iWaveIdx, float amp, float freq, float pZhi)
{
	if(!m_bDevInterfaceOK || !m_pUsbDev)
		return USB_DEVICE_NOT_OPEN;

	if(iChannel < 0 || iChannel > 3)
		return CHANNEL_NOT_EXSIT;

	if(iWaveIdx < 0 || iWaveIdx > 4)
		return SEL_WAVE_TYPE_ERR;

	unsigned char chChannel = 'A' + (iChannel - 1);
	unsigned char chWaveType = 'A' + (iWaveIdx - 1);

	/*������ص�Э�����*/
	//send_T_Wave(m_pUsbDev.get(), 24, 'T', 'W', chChannel, chWaveType, amp, freq, pZhi);

	/*
	  �����ʽ: send_T_Wave(24,'T','W','A','A',3,3,3);
	  �����: 24/2=12
	  ����˵��: send_T_Wave(24,'T','W','A','A',3,3,3);

      ��   ��:
	  send_T_Wave(24,'T','W',CHANNEL_TYPE,WAVE_TYPE,FUZHI,P_Hz,P_Zhi);
	  
	            CHANNEL_TYPE: ͨ    ��
				             'A'---һ·ͨ��
							 'B'---��·ͨ��
							 'C'---��·ͨ��
				   WAVE_TYPE:
				             'A'--- ����
				             'B'--- ����
							 'C'--- ���ǲ�
							 'D'--- ��ݲ�
                   FUZHI    : ��ֵ
                   P_Hz     : Ƶ��
                   P_Zhi    : ƫִ					
	*/
	return NO_ERR;
}


// ��ʼ����
int CXMTDev::StartWave(void)
{
	if(!m_bDevInterfaceOK || !m_pUsbDev)
		return USB_DEVICE_NOT_OPEN;

	//read_system_T_P_R(m_pUsbDev.get(), 10, 'T', 'W', 'S');

	return NO_ERR;
}


// ֹͣ����
int CXMTDev::StopWave(void)
{
	if(!m_bDevInterfaceOK || !m_pUsbDev)
		return USB_DEVICE_NOT_OPEN;

	//read_system_T_P_R(m_pUsbDev.get(), 10, 'T', 'W', 'F');

	return NO_ERR;
}
