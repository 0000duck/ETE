
// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the DLL_XMT_USB_EXPORTS
// symbol defined on the command line. this symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// DLL_XMT_USB_API functions as being imported from a DLL, wheras this DLL sees symbols
// defined with this macro as being exported.

/********************������о����Ƽ����޹�˾************************************/
/********************���������ϸ��������41��************************************/
/********************��ַ:www.xmtkj.com      ************************************/
/********************�鳤:chengfeng	         ************************************/
/********************����:yuelilei           ************************************/
/********************�汾��:201010           ************************************/
/********************ʹ��˵��:���ļ������ı�˵��*********************************/
/********************��̬�ⰲȫ���Է���ʹ��  ************************************/
/********************��ȷʹ���Լ����͵�ѹ������**********************************/
//#include "stdafx.h"

#include "./Libraries/CyUsb/CyAPI.h"
#define DllExport   __declspec( dllexport ) 

#ifdef DLL_XMT_USB_EXPORTS
#define DLL_XMT_USB_API __declspec(dllexport)
#else
#define DLL_XMT_USB_API __declspec(dllimport)
#endif

// This class is exported from the DLL_XMT_USB.dll
//CCyUSBDevice *cyusb = new CCyUSBDevice(NULL); //����һ��USB��ȫ�ֱ���
class  DLL_XMT_USB_API CDLL_XMT_USB {
public:
	CDLL_XMT_USB(void);
	// TODO: add your methods here.
	
	unsigned char* DataAnla_length_command(int f,unsigned char kk[2]); //������ת��Ϊ�ַ�����ȥ
	unsigned char copy_arr_data(unsigned char target[],unsigned char source[],int num); //ת��������ڲ�������
    void copy_arr_xmt_yll(unsigned char target[],unsigned char source[]);//����У��λ
	void send_num_of_char(unsigned char send_arr[],int num,CCyUSBDevice *USBDevice); //��������
	void send_num_of_char(unsigned char send_arr[],int num); //��������
	void send_num_char(unsigned char arry[],int num_of_arr,CCyUSBDevice *USBDevice);
	void send_num_char(unsigned char arry[],int num_of_arr);
	unsigned char *  DataAnla(float f,unsigned char kk[4]);
	unsigned char copy_arr_data_float(unsigned char target[],unsigned char source[],int num); //����������ת����ȥ
    int CalData_char(unsigned char kk0,unsigned char kk1);//����ת�� ������
	float CalData(unsigned char kk0,unsigned char kk1,unsigned char kk2,unsigned char kk3);//����ת�� ������	
};

//�й���USB�豸����
 DllExport bool New_USB_VIR_DEVICE(CCyUSBDevice *new_USB_DEVICE); //���һ��USB�豸
 DllExport bool  IsOpen_Num_Of_USB(CCyUSBDevice *USBDevice,int NUM_OF_USB); //���ñ�ŵ�USB�豸�Ƿ�ʼ��ת
 DllExport int  Open_Num_Of_USB(CCyUSBDevice *USBDevice,int NUM_OF_USB);//ͨ�����������ƶ�USB�豸Ҫ����
 DllExport int  NUM_OF_TOTAL_USB_DEVICE(CCyUSBDevice *USBDevice); //������ڿ�����USB�豸

 DllExport int  NUM_OF_TOTAL_USB_DEVICE_LABVIEW(); //������ڿ�����USB�豸


//о����Ƽ����޹�˾ ��׼�� ��̬��
 DllExport void  SEND_V_COMMAND_SINGLE(CCyUSBDevice *USBDevice,int command_length,unsigned char a1,unsigned char b1,unsigned char c1,float data); //���͵�������
 DllExport void  read_system_T_P_R(CCyUSBDevice *USBDevice,int lenght_command,unsigned char char_t,unsigned char char_p,unsigned char char_r); //��ϵͳ����	
//��ϵͳ��ѹ
 DllExport void read_System_V_S(CCyUSBDevice *USBDevice,int lenght_command,unsigned char char_t,unsigned char char_d,unsigned char char_v,unsigned char char_a); //��ϵͳ��ѹ λ��ֵ
 DllExport float read_System_real_V_S_and_fuzai(unsigned char a1,unsigned char b1,unsigned char c1); //RVN�����ĵ�ѹ����ֵ
//���Ͳ�������
 DllExport void send_T_Wave(CCyUSBDevice *USBDevice,int lenght_command,unsigned char char_T,unsigned char char_W,unsigned char char_channel,unsigned char char_type_wave,float fuzhi,float fHz,float pianyi);
 DllExport void write_System_IO(CCyUSBDevice *USBDevice,int length_command,unsigned char char_t,unsigned char char_i,unsigned char char_n,unsigned char_IO); //дIO������
 DllExport void read_System_real_info_IO(unsigned char receive_char_info[],unsigned char a1,unsigned char b1); //��ϵͳ�Ŀ��ջ��Լ�IO״̬
//2010_09_14 �����й���USB���͵Ĳ������� �Լ� ֹͣ�Ŀ�������
 DllExport void send_wave_mode_CH_H_S(CCyUSBDevice *USBDevice,int lenght_command,unsigned char char_t,unsigned char char_m,unsigned char char_a,unsigned char char_H_h_s,unsigned char_L_h_s);
//���յ���USB������ ������
//2010.09.14 ����
 DllExport void read_System_real_info_wave_begin_stop(unsigned char wave_begin_stop[],unsigned char a1,unsigned char b1);
 DllExport void read_System_real_info_16(float receive_info_data[],unsigned char a1,unsigned char b1);  //��ϵͳ����Ϣ ���λ��
 DllExport void write_system_fuzai(CCyUSBDevice *USBDevice,int lenght_command,unsigned char char_t,unsigned char char_l,unsigned char char_r,unsigned char char_n,float data); //����д��������
 DllExport void read_system_fuzai(CCyUSBDevice *USBDevice,int lenght_command,unsigned char char_t,unsigned char char_l,unsigned char char_r,unsigned char char_n);  //������
 DllExport bool BOOL_CONNECT_USB_XE(void); //USB�豸�Ƿ��������� ����false ��ʾ��������  ����true��ʾ��������

 
 //���ٵ��㸨������ ����������ת��Ϊ USB ���͵�ģʽ ���ظ����� unsigned char send_ARR[]
 DllExport void SEND_V_COMMAND_SINGLE_pro(int command_length,unsigned char a1,unsigned char b1,unsigned char c1,float data,unsigned char send_ARR[]);
 //���β�  ȷ�����͵���
 DllExport void send_num_char_pro(CCyUSBDevice *USBDevice,unsigned char arry[2][14],int num_of_arr,double um_sec,double SEND_ALL_POINT); //um_sec�������ʱ�� SEND_ALL_POINT���͵������ 
 //���β�  ȷ������ʱ��
 DllExport void send_num_char_pro_SEC(CCyUSBDevice *USBDevice,unsigned char arry[2][14],int num_of_arr,double um_sec,double Using_time); //Using_timeͨ������ʱ������ʱ



 //���ٷ��������������� 
 //��ʱ��ʱ��ͨ������CPUʱ�� ʹ�øĳ�����ʹ�ø���CPU 
 //����ļ��ʱ����СΪ500΢�� Ҳ��������send_time�е�Ԫ����СΪ0.5
 //send_data[]���͵�����Ԫ��
 //send_time[]��������һһ��Ӧ��ռ��ʱ��
 //�������ݵĸ���
 //CHANNELѡ�������ͨ�� 'A'һ· 'B'��· 'C'��· 
 //V_OR_S ���ջ�ѡ�� 'V'���� 'S'�ջ�
 //USing_time �ĺ�������ʱ�� 1��Ӧ1��(���ʱ��)-����CPUʱ����
 DllExport void SEND_ARR_DATA_TIME_NUM(CCyUSBDevice *USBDevice,float send_data[],float send_time[],int SEND_NUM,char CHANNEL,char V_OR_S,float USing_time);
 

 //���ٷ��������������� 
 //��ʱ��ʱ��ͨ������CPUʱ�� ʹ�øĳ�����ʹ�ø���CPU 
 //����ļ��ʱ����СΪ500΢�� Ҳ��������send_time�е�Ԫ����СΪ0.5
 //send_data[]���͵�����Ԫ��
 //send_time[]��������һһ��Ӧ��ռ��ʱ��
 //�������ݵĸ���
 //CHANNELѡ�������ͨ�� 'A'һ· 'B'��· 'C'��· 
 //V_OR_S ���ջ�ѡ�� 'V'���� 'S'�ջ�
 //double SEND_POINT ���͵��ܵ���
 DllExport void SEND_ARR_DATA_TIME_NUM_NUMPOINT(CCyUSBDevice *USBDevice,float send_data[],float send_time[],int SEND_NUM,char CHANNEL,char V_OR_S,double SEND_POINT);


 DllExport void  read_system_T_P_R(int lenght_command,unsigned char char_t,unsigned char char_p,unsigned char char_r); //��ϵͳ����	
 DllExport char send_abc();
 DllExport char send_DATA();

 DLL_XMT_USB_API void  receive_usb_info(CCyUSBDevice  *USBDevice,unsigned char receive_arr[]);//��ȡ��USB������ֵ
 DLL_XMT_USB_API void  receive_usb_info_16(CCyUSBDevice  *USBDevice,unsigned char receive_arr[]); //��ȡ��USB������ֵ  20120218����
 void DLL_XMT_USB_API receive_pro_16(CCyUSBDevice *USBDevice,unsigned char reciv[]); //z��ȡ��ѹ �� ��λ�Ƶ����� 
 
 //DLL FOR LABVIEW or simple command for XE_XMT_USB_PRO
int DLL_XMT_USB_API NUM_OF_TOTAL_USB_DEVICE_labview(void); //������ڿ�����USB�豸
int DLL_XMT_USB_API Open_Num_Of_USB_labview(int NUM_OF_USB);//���ӱ��ΪNUM��USB�����豸
int DLL_XMT_USB_API send_UPMUC_CONTROL_DATA(int NUM_OF_USB);


//////////////////////////////////////////////////////////////////////////
//�����ѹ��������
//����ϵͳ��ѹ
DllExport int send_volt_labview(float send_data,char channel_type); //���͵������� channel_type->>>A B C
//��ȡϵͳ��ѹ����
DLL_XMT_USB_API void read_System_V_labview(unsigned char CHANNEL_TYPE); //���Ͷ�ȡ ��ϵͳ��ѹ���� channel_type->>>A B C
//��ȡʵ��ϵͳ��ѹ����
DLL_XMT_USB_API float read_System_real_V_labview(unsigned char CHANNEL_TYPE); //��ϵͳ��ѹ channel_type->>>A B C

DLL_XMT_USB_API void  receive_usb_V_AND_MOVE(CCyUSBDevice  *USBDevice,unsigned char receive_arr[]); //��ȡ��USB������ֵ
void DLL_XMT_USB_API receive_pro_v_move_only(CCyUSBDevice *USBDevice,unsigned char reciv[]); //z��ȡ��ѹ �� ��λ�Ƶ�����



//ѡ�� �߼���������   ��·ͬʱ���� ����λ 
DLL_XMT_USB_API void  SEND_VVV_COMMAND_SINGLE(CCyUSBDevice *USBDevice,int command_length,unsigned char a1,unsigned char b1,unsigned char flag_A,float data1,unsigned char flag_B,float data2,unsigned char flag_C,float data3);
 DLL_XMT_USB_API void  send_VVV_labview(unsigned char flag_A,float data1,unsigned char flag_B,float data2,unsigned char flag_C,float data3);
////////////////////////////////////////////////// ////////////////////////


//////////////////////////////////////////////////////////////////////////
//����λ�ƿ�������
DllExport int send_Move_labview(float send_data,char channel_type); //���͵������� channel_type->>>A B C
//��ȡϵͳ��ѹ����
DLL_XMT_USB_API void read_System_Move_labview(unsigned char CHANNEL_TYPE); //���Ͷ�ȡ ��ϵͳ��ѹ����
//��ȡʵ��ϵͳ��ѹ����
DLL_XMT_USB_API float read_System_real_Move_labview(unsigned char CHANNEL_TYPE); //��ϵͳ��ѹ
//////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////// 
//�¼����ȡϵͳ��·һͬ�����ݵ����
DLL_XMT_USB_API void read_System_VVV_labview(unsigned char CHANNEL_TYPE); //���Ͷ�ȡ ϵͳ��·λ�ƻ��ǵ�ѹ���� 'C'
DLL_XMT_USB_API void read_System_VVV_SSS(CCyUSBDevice *USBDevice,int lenght_command,unsigned char char_t,unsigned char char_d,unsigned char char_v); //��ϵͳ��ѹ λ��ֵ

DLL_XMT_USB_API void read_System_real_VVV_labview(unsigned char flag_ABC[3],float data_road_ABC[3]); //��ϵͳ��ѹ
DLL_XMT_USB_API void read_System_real_VVV_labview_DLL(unsigned char flag_ABC[3],float data_road_ABC[3]); //RVN�����ĵ�ѹ����ֵ
DLL_XMT_USB_API void read_System_real_VVV_flag_ABC_flag_arr_labview(unsigned char &flag_ABC_1,unsigned char &flag_ABC_2,unsigned char &flag_ABC_3,float &data_road_ABC_1,float &data_road_ABC_2,float &data_road_ABC_3); //��ϵͳ��ѹ
//////////////////////////////////////////////////////////////////////////
//���ο�������
//�������ݷ�������
DLL_XMT_USB_API void send_T_Wave_labview(unsigned char CHANNEL_TYPE,unsigned char WAVE_TYPE,float FUZHI,float P_Hz,float P_Zhi);
//���ο�ʼ,ֹͣ����
DLL_XMT_USB_API void send_T_Wave_Star_or_Fianl_labview(unsigned char Flag_wave_begin_or_Fianl); //Flag_wave_begin_or_Fianl 'S'<==>START,'F'<==>FINAL
//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////
//IO�ڹ���

//IO���趨����
DLL_XMT_USB_API void write_System_IO_labview(unsigned char CHANNEL_TYPE,unsigned char IO_Flag); //һ·��� 'I'Ϊ����ģʽ 'O' Ϊ���ģʽ

//��ȡIO��״̬����
DLL_XMT_USB_API void read_System_IO_labview(unsigned char READ_FLAG); //READ_FLAG = 'R'

//��ȡIO��״̬
DLL_XMT_USB_API void read_System_real_info_IO_labview(unsigned char receive_char_info[6]);
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
//////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////
/* IO�տ������� �������ⲿ������XEϵ�е�Դ��ͬ����� 20120607*/
DLL_XMT_USB_API void control_XE_channel_IO(CCyUSBDevice *USBDevice,int lenght_command,unsigned char char_t,unsigned char char_l,unsigned char char_n,unsigned char tmp_flag_begin,unsigned char tmp_flag_end); //����д��������
DLL_XMT_USB_API void control_XE_channel_IO_labview(unsigned char CHANNEL_TYPE,unsigned char flag_begin,unsigned char flag_end);

/*  ���� ���� IO����� ���������źŸ��ⲿ�豸ʹ֮����XEϵ�е�Դ����Ϲ�����
control_XE_channel_IO_labview('A','1','0'); //ͨ��һ· IO�� ���ø� �ӳ�Լ150΢�� Ȼ���õ�
control_XE_channel_IO_labview('A','0','1'); //ͨ��һ· IO�� ���õ� �ӳ�Լ150΢�� Ȼ���ø�

control_XE_channel_IO_labview('B','1','0'); //ͨ����· IO�� ���ø� �ӳ�Լ150΢�� Ȼ���õ�
control_XE_channel_IO_labview('B','0','1'); //ͨ����· IO�� ���õ� �ӳ�Լ150΢�� Ȼ���ø�

control_XE_channel_IO_labview('C','1','0'); //ͨ����· IO�� ���ø� �ӳ�Լ150΢�� Ȼ���õ�
control_XE_channel_IO_labview('C','0','1'); //ͨ����· IO�� ���õ� �ӳ�Լ150΢�� Ȼ���ø�
*/
////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////
//���ò�����ͣ�ٶ�

void DLL_XMT_USB_API send_wave_mode_CH_H_S_labview(unsigned char CHANNEL_TYPE,unsigned char WAVE_BEGIN_SPEED,unsigned char WAVE_END_SPEED);
//���ò�����ͣ�ٶ�
/*
�����ʽ:  send_wave_mode_CH_H_S_labview('A','H','H');

  ͨ  ��: 
  'A'---һ·ͨ��
  'B'---��·ͨ��
  'C'---��·ͨ��
  WAVE_BEGIN_SPEED:  ������ʼ�ٶ� 'H'��ʾ���� 'S'��ʾ����
  WAVE_END_SPEED  :  ����ֹͣ�ٶ� 'H'��ʾ���� 'S'��ʾ����			  
  /*  
  ����:
  send_wave_mode_CH_H_S_labview(14,'T','M','A','H','S'); //һ·����Ϊ��
  send_wave_mode_CH_H_S_labview(14,'T','M','B','H','H');
  send_wave_mode_CH_H_S_labview(14,'T','M','C','H','H');	
*/

//��������ͣ�ٶ�����
void DLL_XMT_USB_API read_Systeml_info_wave_begin_stop_labview(unsigned char READ_FLAG);  //READ_FLAG = 'R'
//��������ͣ�ٶ�״̬
void DLL_XMT_USB_API read_System_real_info_wave_begin_stop_labview(unsigned char recive_data_usb_wave_send_mode[6]);
/*
�����ʽ:  read_System_real_info_wave_begin_stop_labview(recive_data_usb_wave_send_mode,'R','M'); ��������������
�����: **
����˵��: ��λ����USB�˿ڶ�ȡ1,2,3·������ͣ�ٶ� , read_System_real_info_wave_begin_stop_labview(recive_data_usb_wave_send_mode,'R','M');
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



//////////////////////////////////////////////////////////////////////////
//��ȡϵͳ������Ϣ����
DLL_XMT_USB_API void read_system_states_labview(unsigned char READ_FLAG); //READ_FLAG = 'R'

//��ȡϵͳ������Ϣ
DLL_XMT_USB_API void read_system_states_real_labview(float recive_data_usb[9]);
/*
�����ʽ: ��������������
�����: **
����˵��: ��λ����USB�˿ڶ�ȡ1,2,3·ϵͳ��Ϣ
ͨ    ��: ��ȡ1��2��3·,������ͣ�ٶ�
��������: ʹ��recive_data_usb[9]����������1,2,3·��Ϣ
����״̬��Ϣ����1��2��3·ͨ����·ϵͳ��Ϣ
recive_data_usb[0] ---  ϵͳ��С��ѹ
recive_data_usb[1] ---  ϵͳ����ѹ
recive_data_usb[2] ---  ϵͳ��Сλ��
recive_data_usb[3] ---  һ·�ջ��մ����λ��
recive_data_usb[4] ---  ��·�ջ��մ����λ��
recive_data_usb[5] ---  ��·�ջ��մ����λ��
recive_data_usb[6] ---  һ·����
recive_data_usb[7] ---  ��·����
recive_data_usb[8] ---  ��·����
*/
//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////
//ϵͳ������������
//д��������
DLL_XMT_USB_API void write_system_fuzai_labview(unsigned char CHANNEL_TYPE,float fuzai_data);
/*
�����ʽ: write_system_fuzai_labview('A',1.9);

ͨ    ��: 
'A'---һ·ͨ��
'B'---��·ͨ��
'C'---��·ͨ��
��    ��: 1.9 Ϊ�궨��һ·ͨ���ĸ�����ֵ ����ֵ����ʵ�������д

��������: *****/


//��ȡϵͳ��������
DLL_XMT_USB_API void read_system_fuzai_labview(unsigned char CHANNEL_TYPE);
//��ȡϵͳ����״̬
DLL_XMT_USB_API float read_system_fuzai_real_labview(unsigned char CHANNEL_TYPE);
/*
�����ʽ:  read_system_fuzai_real_labview(unsigned char CHANNEL_TYPE) ��������������
����˵��: ��λ����USB�˿ڶ�ȡһ·��ѹ����(��������)  read_system_fuzai_real_labview('R','L','A');
ͨ    ��: 
��ȡ1·�ĸ�����ֵ 
ͨ  ��
'A'---һ·ͨ��
'B'---��·ͨ��			    
'C'---��·ͨ��
��������: ʹ��float_fzai������������Ϣ  
*/


//20120213 ����
/*
   //�������Ķ�ȡϵͳ�ĳ��� 20120213 ����
*/
///////////////////////////////////////
//�������Ķ�ȡϵͳ�ĳ���
DLL_XMT_USB_API int read_System_Bulk_from_USB(CCyUSBDevice *USBDevice,int lenght_command,int length_read,unsigned char char_t,unsigned char char_d,unsigned char char_v,unsigned char char_a);

DLL_XMT_USB_API void read_System_Bulk_labview(int length_of_read,unsigned char CHANNEL_TYPE); //������ȡ��صĵ�ѹ �Լ� λ������

//��ȡʵ��ϵͳ��ѹ���� ����
DLL_XMT_USB_API int read_System_real_Bulk_labview(unsigned char receive[],unsigned char CHANNEL_TYPE);  //�ⲿ���� ����vc++����labview�ȱ������
DLL_XMT_USB_API int read_System_real_Bulk(unsigned char receive[],unsigned char CHANNEL_TYPE);   //��̬���ڲ���װʹ�õĺ���

DLL_XMT_USB_API int receive_usb_Bulk_V_AND_MOVE(CCyUSBDevice  *USBDevice,unsigned char receive_arr[]); //��ȡϵͳ�����ݵ�������

DLL_XMT_USB_API void receive_pro_bulk_v_move_only(CCyUSBDevice *USBDevice,unsigned char reciv[]); //z��ȡ��ѹ �� ��λ�Ƶ�����

DLL_XMT_USB_API void begin_Read_data_for_bulk_labview(unsigned char channel_type);
////////////////////////////////////////




//////////////////////////////////////////////////////////////////////////
//ͬʱ����1��2��3·������Ӧ�ĵ�ѹ�Լ�λ������ ͨ����λ���Զ��жϿ��ջ� ��λ��ֻҪ��дһ����·�Ŀ������ݡ�
DLL_XMT_USB_API void xmt_usb_send_all_data_labview(float A_CHANNEL_data,float B_CHANNEL_data,float C_CHANNEL_data);  //����һ· ��· ��· ���� ����USB��ʽ������ 
/*
�����ʽ:  xmt_usb_send_all_data(float data_01,float data_02,float data_03);
����˵��:  //ͬʱ����1��2��3·������Ӧ�ĵ�ѹ�Լ�λ������ ͨ����λ���Զ��жϿ��ջ� ��λ��ֻҪ��дһ����·�Ŀ������ݡ�
ͨ    ��:  A_CHANNEL_data,B_CHANNEL_data,C_CHANNEL_data �ֱ�Ϊһ· ��· ��·����
����λ������һ· ��· ��·���� ׼��ͬʱ���
*/
//����Ϊо����Ƽ����޹�˾ ����ʹ�õĲ��ֶ�̬�����о���칫˾����ʹ�� �û�ʹ�ÿ��ܻᵼ��ϵͳ�������ǻ����𻵻���Ӳ���𻵻��������˺�������
DllExport void write_system_canshu(CCyUSBDevice *USBDevice,int lenght_command,unsigned char char_t,unsigned char char_p,unsigned char char_w,float min_v,float max_v,float min_move,float move_01,float move_02,float move_03,float gl_01,float gl_02,float gl_03); //дϵͳ����

DllExport void write_system_canshu_labview(int lenght_command,unsigned char char_t,unsigned char char_p,unsigned char char_w,float min_v,float max_v,float min_move,float move_01,float move_02,float move_03,float gl_01,float gl_02,float gl_03); //дϵͳ����


DLL_XMT_USB_API int fnDLL_XMT_USB(void);
