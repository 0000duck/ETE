#pragma once

/*
*	Create by Jianbo 2013-11-3
*/
#include "mscomm.h"
#include "./Libraries/CyUsb/CyAPI.h"
#include "./Libraries/XMT_USB/DLL_XMT_USB.h"
#include "ETESystemPublicDefine.h"

#include <boost/smart_ptr.hpp>

class CXMTDev
{
public:
	CXMTDev(void);
	~CXMTDev(void);

public:
	// ��ʼ���õ��Ľӿ�
	int InitDevInterface(ST_INTERFACE_PARA stIntfPara);
	// �ر��豸�ӿ�
	void DeInitDevInterface(void);
	
private:
	// ʹ�ýӿ����ͣ�USB or Com...��
	unsigned char m_eInterfaceType;
	boost::shared_ptr<CMSComm> m_pSerialDev;
	boost::shared_ptr<CCyUSBDevice> m_pUsbDev;
	// ��ǰ�豸�ӿ�״̬
	BOOL m_bDevInterfaceOK;
public:
	// ���豸�ӿڽ�������
	BOOL ShakeHandWithDevInterface(void);
	// ��λ����
	int SendSinglePosCmd(LOOP_STATUS V_or_S, int iChannel, float point_MVS);
	// ��ȡ��������
	int ReadSiglePosCmd(LOOP_STATUS V_or_S, int iChannel, float *Val_VS);

	// ��λ���
	int SendMultiPosCmd(LOOP_STATUS loopStatus, int iChannel, float send_data[], float send_time[], int iArrSz);
	// ��ȡ���ջ�״̬
	LOOP_STATUS Read_V_S_Status(int iChannel);
	// ��ȡλ������ϵͳ��Ϣ
	int ReadSysInfo(ST_XMT_SYS_INFO *stSysInfo);
	// ���ø���
	int SetLoadSz(int iChannel, float LoadSz );
	// ��ȡ����
	int GetLoadSz(int iChannel, float *LoadSz);
	// �����豸��ͣ�ٶ�
	int SetDevStartAndStopSpeed(int iChannel, ST_DEV_START_STOP_SPEED stSpeed);
	// ��ȡ�豸��ͣ�ٶ�
	int GetDevStartAndStopSpeedAllChannel(ST_DEV_START_STOP_SPEED *stSpeed);
	// ʹ����λ��ͨ��USB����
	int EnablePCConsole(void);
	// ����IO����
	int SetIOConfig(int iChannel, int IO_type);
	// ��ȡIO����
	int GetIOConfig(int iChannel, int *IO_type);
	// ��ȡ���ջ�����
	int GetLoopConfig(int iChannel, int *Loop_type);
	// ��ȡϵͳ���ջ���IO������Ϣ
	int GetLoopAndIOConfiguration(DEV_LOOP_IO_CONFIGURATION_INFO *pConfiguration);
	// ���ò���
	int SetWaveConfiguration(int iChannel, int iWaveIdx, float amp, float freq, float pZhi);
	// ��ʼ����
	int StartWave(void);
	// ֹͣ����
	int StopWave(void);
	void SleepMs(int timesspan);
	int SendMultiPosCmdEx(LOOP_STATUS V_or_S, int iChannel, float point_MVS[], int num);
	BOOL CheckLoopState();
};

