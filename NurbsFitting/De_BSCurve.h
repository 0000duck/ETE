// De_BSCurve.h: interface for the De_BSCurve class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_DE_BSCURVE_H__60CE6974_D773_11D2_A87D_000021E5AAC2__INCLUDED_)
#define AFX_DE_BSCURVE_H__60CE6974_D773_11D2_A87D_000021E5AAC2__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include <afxtempl.h>
#include "De_BSCKont.h"
#include "De_BPnt.h"
#include "De_IntplPnt.h"
#include "Re_Pnt3D.h"
#include "Re_Vector.h"
    
class AFX_CLASS_EXPORT De_BSCurve  
{
public:
	De_BSCurve();
public:
	De_BSCKnotArray		m_KnotArray;      //�ڵ�����
	De_BPntArray		m_CtrlPntArray;   //���ƶ�������
	De_IntplPntArray	m_DrawData;		  //������ɢ�����ݵ�(��ͼ��)
	De_IntplPntArray	m_IntplPntArray;  //��ֵ��
	int					m_Degree;         //����
	int					m_Close;          //0, open; 1,close
	int					m_StartCond;      //0, �гֶ�; 2, �����; 1, ���ɶ�
	int					m_EndCond;        //0, �гֶ�; 2, �����; 1, ���ɶ�
	int                 m_iEndConstrain;  //0, two end constrain, 1,start constrain 2,end constrain 
	int					m_BndNum;		  //��ΪNurbsƬ�ı߽����Ŀ
	BOOL				m_IsPicked;
	BOOL                m_bReverse;       // head->end ����ƶ������в�ͬ=1 ��ͬ����0
	BOOL				m_IsBlanked;
	UINT				m_ColorIndex;     // ���� ��ɫֵ 
	double Normal_star[3],Normal_end[3];  //������ĩ�˵�Ŀ�߽���ʸ
	De_BPntArray		m_D1CtrlPntArray; //��ʸ���ƶ�������
	De_BPntArray		m_D2CtrlPntArray; //��ʸ���ƶ�������
	De_BPntArray		m_D3CtrlPntArray; //��ʸ���ƶ�������
	BOOL				m_U_direction;
	int					m_SweepCurIndex;
	BOOL                m_IsPlane;        //�Ƿ�ƽ������
	Re_Vector           m_PVector;        //����ƽ��ķ�ʸ

	//jjjj2008
	bool KnotOK;
	double star_nx,star_ny,star_nz,end_nx,end_ny,end_nz; //
	Re_Pnt3D BreakPnt; //
	Re_Pnt3DArray BreakPntArray;
	bool CurveDivide; //


public:
	bool CurveKnotCheck();
	void InsertKnot(double u,int i);

	virtual ~De_BSCurve();
	De_BSCurve(const De_BSCurve&);
	De_BSCurve &operator =(De_BSCurve);

	void	Init();
	BOOL	CalKnot();
	BOOL	CalCtrlPntNew() ;
	void	EndConstrain(int,int,int,int,double &,double &,double &,
			double &,double &,double &,double &,double &);
	BOOL	CalBase(int,int ,double ,double * );
	int 	FindInter(int ,int& );
	void	CalLineSec(int,int,int,int);
	void	CalCurSec(int,int,int,int);
	BOOL	CalCtrlPnt();                 /////////
	BOOL	CalCloseCtrlPnt(int,int);
	int 	CalPnt(double,double&,double&,double&);   ///////
	BOOL    UniformKnot(int Ctrl);
	void	CopyHeadEndPnt();

	void	KnotStandardization();						// ���ʸ����׼��
    double  TolLength();                                // �����ܳ���

	BOOL	InsertKnot(int,int,int,double);				// Bs���߽�����
	double	CalTangent(double,Re_Pnt3D &);				// ������һ�����ʸ
	De_BSCurve KontInsert(double u_ins, int rtims);
	BOOL	DiscreteKnot(Re_Pnt3DArray& pntarray);// 
	BOOL	ReCreateIntplPnts();



};
typedef CArray<De_BSCurve,De_BSCurve> De_BSCurveArray;

#endif // !defined(AFX_DE_BSCURVE_H__60CE6974_D773_11D2_A87D_000021E5AAC2__INCLUDED_)

