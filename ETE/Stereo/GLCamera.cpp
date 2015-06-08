#include "../stdafx.h"
#include "glcamera.h"
#include "gl\gl.h"
#include "gl\glu.h"

// ���캯��
GLCamera::GLCamera(void)
{
	m_fNearZ		=-100;
	m_fFarZ		=100;
	m_fAspect		=1.0f;	
	m_fOrthoWidth	=30.0f;
	m_fOrthoHeight	=30.0f;	
}

// ��������
GLCamera::~GLCamera(void)
{
	// �ͷ��������
}


// �����Ӽ���
void GLCamera::SetViewVolume(const float& width, const float& height, const float& zNear, const float& zFar)
{
	// ���õ�һЩȱʡֵ
	int viewport[4];
	glGetIntegerv(GL_VIEWPORT, viewport);
	if(viewport[2]==0) 
		viewport[2]=1; 
	if(viewport[3]==0) 
		viewport[3]=1; 
	m_iViewportWidth=viewport[2]; 
	m_iViewportHeight=viewport[3]; 
	m_fAspect = float(m_iViewportWidth)/float(m_iViewportHeight);	

	m_fNearZ	= zNear;
	m_fFarZ	= zFar;
	if(width<height*m_fAspect)
	{
		m_fOrthoWidth	= width;
		m_fOrthoHeight  =width/m_fAspect;
	}
	else
	{
		m_fOrthoHeight  =height;
		m_fOrthoWidth	=height*m_fAspect;
	}
	m_bProjectionChanged=TRUE;	// ͶӰ״̬���ı�,�����ú��� Projection
}

//// ��ȡ�Ӽ���Ŀ�߱������ӽǡ���ƽ�桢Զƽ��
void GLCamera::GetViewVolume(float&width, float&height, float &zNear,  float &zFar)
{
	width		= m_fOrthoWidth;
	height  		= m_fOrthoHeight;
	zNear		= m_fNearZ;
	zFar		= m_fFarZ;
}

// ��ȡ��ƽ��ͶӰ���Ӽ���Ŀ��
void GLCamera::GetViewVolume( float &orthoWidth,  float &orthoHeight)
{
	orthoWidth	= m_fOrthoWidth;
	orthoHeight= m_fOrthoHeight;
}

const float& GLCamera::GetViewAspectRatio()const
{
return this->m_fAspect;
}
// ʵʩ����任
void GLCamera::ApplyForMouseSelect(CPoint start,CPoint end)
	{
	m_bProjectionChanged=TRUE;	// ��Ҫ����
	
	int viewport[4];
	int width,height;
	if( abs(end.x-start.x)<2&&abs(end.y-start.y)<2 )
		width=height=2;
	else 
	{
		width=abs(end.x-start.x);
		height=abs(end.y-start.y);
	}
	glGetIntegerv(GL_VIEWPORT, viewport);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	// 2x2 pixel
    gluPickMatrix((start.x+end.x)/2, viewport[3]-(start.y+end.y)/2, width, height, viewport);
	glOrtho(-m_fOrthoWidth*0.5f, m_fOrthoWidth*0.5f, 
				-m_fOrthoHeight*0.5f, m_fOrthoHeight*0.5f, m_fNearZ, m_fFarZ);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();	// �������������ϵ�ı任		?
	}

void GLCamera::Apply(void)
{
		
	// ͶӰ״̬���ı�,�����ú��� Projection
	if(m_bProjectionChanged)
	{
		Projection();	
		m_bProjectionChanged=FALSE;
	}
//	glLoadIdentity();	// �������������ϵ�ı任  ?
//	LoadMatrix_FOTW();  // SceneNode::LoadMatrix_FOTW()
}


// ʵʩͶӰ�任
void GLCamera::Projection(void)
{
	//if(!m_bJitter)
	{
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
// 		glOrtho(-m_fOrthoWidth*0.5f, m_fOrthoWidth*0.5f, 
// 					-m_fOrthoHeight*0.5f, m_fOrthoHeight*0.5f, m_fNearZ, m_fFarZ);
		glOrtho(0, m_fOrthoWidth, 
			0, m_fOrthoHeight, m_fNearZ, m_fFarZ);
		glMatrixMode(GL_MODELVIEW);
	}
	//else if(m_bJitter)	// �ظ�ǿ��
	//{
	//	float scalex, scaley;
	//	float dx, dy;
	//	const float _PI_ = 3.1415926f;

	//	glMatrixMode(GL_PROJECTION);
	//	glLoadIdentity();

	//	scalex=	m_fOrthoWidth/m_iViewportWidth; 
	//	scaley=	m_fOrthoHeight/m_iViewportHeight;
	//	dx=-0.5f*m_fJitterX * scalex;
	//	dy=-0.5f*m_fJitterY * scaley;
	//	glOrtho(-m_fOrthoWidth*0.5f+dx, m_fOrthoWidth*0.5f+dx, 
	//				-m_fOrthoHeight*0.5f+dy, m_fOrthoHeight*0.5f+dy, m_fNearZ, m_fFarZ);

	//	glMatrixMode(GL_MODELVIEW);

	//}
}

// ��Ӧ WM_SIZE
void GLCamera::ResizeWindow(void)
{
	SetViewVolume(m_fOrthoWidth, m_fOrthoHeight, m_fNearZ, m_fFarZ);
}

// ���������ʮ�֡���״
void GLCamera::Draw(void)
{
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	glOrtho(-m_fOrthoWidth/2, m_fOrthoWidth/2, 
			-m_fOrthoHeight/2, m_fOrthoHeight/2, -50, 50);
	glMatrixMode(GL_MODELVIEW);
	glPopMatrix();
}