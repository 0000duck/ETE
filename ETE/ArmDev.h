#pragma once

#include "SerialPort.h"
#include "ETESystemPublicDefine.h"

class ArmDev
{
public:
	static ArmDev *GetInstance();  
	static ArmDev *pInstance;  
	static CCriticalSection m_sCriticalSection;
	void Destroy();

	// ��ʼ���õ��Ľӿ�
	BOOL InitDevInterface();
	// �ر��豸�ӿ�
	void DeInitDevInterface(void);
	// ���豸�ӿڽ�������
	BOOL ShakeHandWithDevInterface(void);
	// ����ѡ��ģʽ
	BOOL ConfigParameters(ST_ARM_CONSOLE_DEV_INF_PARA stIntfPara);

	BOOL SetPulseNum( BYTE num );
	BOOL SetPeriod( BYTE period );
	BOOL SetTriggerNum( int howManyTime);
	BOOL SetDelay( BYTE delay);
	BOOL SetWhiteStrength(int strength);
	BOOL SetBlueStrength(int strength);
	BOOL StartNewTrigger();
	BOOL SetNewTriggerEnter();
	BOOL SetNewTriggerLeave();

	BOOL StartTrigger();
	BOOL SetTriggerEnter();
	BOOL SetTriggerLeave();
	BOOL SetTriggerPeriod(int triggerPeriod);
private:
	ArmDev();
	~ArmDev(void);
private:
	CSerialPort* m_pSerialPort;
	// ��ǰ�豸�ӿ�״̬
	BOOL m_bDevInterfaceOK;
	CMD_FORMAT m_cmdDetail;
	void initCmdPara();
	// ��������
	BOOL SendCmd();

};

