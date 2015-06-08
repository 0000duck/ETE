

#include "stdafx.h"		
#include <math.h>		
#include <assert.h>
#include "..\include\ti_trackball.h"


Ti_Trackball::Ti_Trackball(void)
{
	m_iWidth	=	m_iHeight	= 400;	
	m_iCenterX	=	m_iCenterY	= 200;
	m_iRadius	=	200;
	m_iMouseX	=	m_iMouseY	=	1;
	m_start = PNT(0,0,1);
}

Ti_Trackball::~Ti_Trackball(void)
{

}

// �����������Ϊ���ڵ�����
void Ti_Trackball::SetTrackWindow(const int& iWidth, const int& iHeight)
{
	m_iWidth   = iWidth;
	m_iHeight  = iHeight;
	m_iCenterX = m_iWidth/2;
	m_iCenterY = m_iHeight/2;
	m_iRadius  = (m_iWidth > m_iHeight) ? m_iCenterY : m_iCenterX ;
}

// �����������Ϊ��������(centerX, centerY) 
void Ti_Trackball::SetTrackWindow(const int& iWidth, const int& iHeight, const int& iCenterX, const int& iCenterY)
{
	m_iWidth   = iWidth;
	m_iHeight  = iHeight;
	m_iCenterX = iCenterX;
	m_iCenterY = iCenterY;
	m_iRadius  = (m_iWidth > m_iHeight) ? m_iCenterY : m_iCenterX ;
}

// �����(mouseX, mouseY)ͶӰ������һ�� P
// ����ֵ��Ϊ���ĵ�P��ʸ��
PNT Ti_Trackball::MouseToVector(const int& iMouseX, const int& iMouseY)
{
	PNT V(0,0,0);
	if(m_iCenterX >= m_iWidth/2)  
		V[0]=float(iMouseX-m_iCenterX)/float(m_iCenterX);
	else
		V[0]=float(iMouseX-m_iCenterX)/float(m_iWidth-m_iCenterX);

	if(m_iCenterY >= m_iHeight/2)  
		V[1]=float(m_iCenterY-iMouseY)/float(m_iCenterY);
	else
		V[1]=float(m_iCenterY-iMouseY)/float(m_iHeight-m_iCenterY);

	double d=V.Length();
	V[2]=float( cos((PIE/ 2.0) * ((d < 1.0) ? d : 1.0)) );
	V.Normalize();
	return V;
}

// ����հ������ʱ������ (mouseX, mouseY)
void Ti_Trackball::Start(const int& iMouseX, const int& iMouseY)
{
	m_iMouseX=iMouseX;
	m_iMouseY=iMouseY;
	m_start=MouseToVector(m_iMouseX, m_iMouseY);
}

// ����ƶ� (dx,dy), ������ת�� axis ��Ƕ� angle 
void Ti_Trackball::Tracking(const float& iDx, const float& iDy, PNT&axis, float&fAngle)
{
	m_iMouseX+=iDx;
	m_iMouseY+=iDy;
	m_stop=MouseToVector(m_iMouseX, m_iMouseY);
	axis=m_start^m_stop; // cross product
	axis.Normalize();
	

	const float ANGLE_SCALE=2.0f;	// �������һ���ǶȷŴ�ϵ��
	if(fabs(m_start*m_stop)>1)
		{
		fAngle = 0;
		return;
		}
	fAngle=float(ANGLE_SCALE*acos(m_start*m_stop)/PIE*180.0);
	
	// �����������С�Ƕȣ����� Rotation ��������
	const float	DELTA_ANGLE=0.00001f;
	if(fAngle < DELTA_ANGLE)	
		fAngle=DELTA_ANGLE;
	m_start=m_stop; // ��Ҫ����
}
