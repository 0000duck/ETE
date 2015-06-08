/////////////////////////////////////////////////////////////////////////////////////////
//			file name : Ti_Trackball.h   
//
//			File Description : 
//				which is used for mouse rotation operation
//			created by Xiaoming Du 10/27/2004
//
//			Modification Record:	
//////////////////////////////////////////////////////////////////////////////////////////
#pragma once
#include "math_algorithm.h"
#include "pnt.h"
class MATH_ALGORITHM_API Ti_Trackball
	{

	protected:
	// �����(mouseX, mouseY)ͶӰ������һ�� P
	// ����ֵ��Ϊ���ĵ�P��ʸ��
	int    m_iWidth,   m_iHeight;	// ���ڵĿ��
	float    m_iCenterX, m_iCenterY;	// ����������
	int    m_iRadius;				// ������뾶
	float    m_iMouseX,  m_iMouseY;	// ���λ��
	PNT m_start;	// �հ���ʱ�����ͶӰʸ��
	PNT m_stop;	// �ƶ�(dx,dy)ʱ�����ͶӰʸ��

	public:
		Ti_Trackball(void);
		~Ti_Trackball(void);
public:
	// �����������Ϊ���ڵ�����
	void SetTrackWindow(const int& iWidth,const  int&  iHeight);

	// �����������Ϊ��������(centerX, centerY) 
	void SetTrackWindow(const int & iWidth, const int & iHeight, const int & iCenterX, const int & iCenterY);

	// ����հ������ʱ������ (mouseX, mouseY)
	void Start(const int & iMouseX, const int & iMouseY);

	// ����ƶ� (dx,dy), ������ת�� axis ��Ƕ� angle 
	void Tracking(const float & iDx, const float & iDy, PNT& axis, float &fAngle);
	PNT MouseToVector(const int&  iMouseX, const int& iMouseY);
	};
