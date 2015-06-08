/////////////////////////////////////////////////////////////////////////////////////////
//			file name : GLCamera.h   
//
//			File Description : 
//				this file is for camera setting:
//				
//				
//			Created by Xiaoming Du 11/4/2004
//
//			Modification Record:	
//////////////////////////////////////////////////////////////////////////////////////////
#pragma once

class GLCamera
{

protected:

	BOOL		m_bProjectionChanged;	// ͶӰ״̬���ı�,�����ú��� Projection
	float			m_fNearZ;			// �ӵ����ƽ��ľ���
	float			m_fFarZ;			// �ӵ���Զƽ��ľ���
	float			m_fOrthoWidth;	// ƽ��ͶӰƽ��Ŀ�ȣ��������ã�
	float			m_fOrthoHeight;	// ƽ��ͶӰƽ��ĸ߶ȣ��������ã�
	int			m_iViewportWidth;	// �����Ŀ�ȣ���λ���أ�
	int			m_iViewportHeight;// �����ĸ߶ȣ���λ���أ�
	float			m_fAspect;		// �����Ŀ�߱���

public:
	GLCamera(void);
   ~GLCamera(void);

public: 

	// ִ������任������ Projection ��
	void ApplyForMouseSelect(CPoint start,CPoint end);
	void Apply(void);
	void Draw(void);
	// ��Ӧ WM_SIZE
	void ResizeWindow(void); 

public: //----------------------- Set&Get ���� --------------------------
	// ���á���ȡ�Ӽ��壨����͸��ͶӰ��ƽ��ͶӰ��
	// fOrthoZ  �����ڼ���ƽ��ͶӰ���Ӽ���
	void SetViewVolume(const float& width, const float &height,
					   const float &fNearZ, const  float &fFarZ);
	
	// ��ȡ�Ӽ���Ŀ�߱������ӽǡ���ƽ�桢Զƽ��
	void GetViewVolume(float& width, float &height,
					   float &fNearZ, float &fFarZ);

	// ��ȡ��ƽ��ͶӰ���Ӽ���Ŀ��
	void GetViewVolume( float &fOrthoWidth, float  &fOrthoHeight);
	const float& GetViewAspectRatio()const;

protected:
	// ʵʩͶӰ�任
	void Projection(void);

};


