#pragma once
#include "XGeneralCurve.h"

class  AFX_EXT_CLASS XLine : public XGeneralCurve
{
public:
	XLine(PNT &s, PNT &e);
	XLine(void);
	~XLine(void);

public:
	XLine& operator = (const XLine& aLine);
	PNT MiddlePoint();  
	void Initial();
	void Set(PNT &s,PNT &e);
	bool GetDelFlag();
	void SetDelFlag(bool flag);
	void SetCoff();
	void SetLineStyle(int ls);

	double GetLen();	
	float Distance(PNT &pt);		//�㵽ֱ�ߵ���̾���
	float SectDistance(PNT &pt);	//�㵽�߶ε���̾���
	float FallProportion(PNT &pt);	//�ҵ�����㣬�����ظ���������߶��еķָ����
	PNT NearPt(PNT &pt);			//�߶��Ͼ���pt����ĵ�
	PNT GetProjectPt(PNT &pt);		//����ֱ���ϵ�pt������ĵ�

public:
	void UpdateBndBox();
	void ChangeUnits(bool bmm2inch );
	virtual void SetUnit(const int& unit);
	virtual void InitObject();
	virtual void Translate(const PNT& delt_t);
	virtual void Rotate(const Ti_Rotation& R);

	//by JM
	double		mL0, mL1, mL2;		//mL0 * x + mL1 * y + mL2 = 0
	float		m_LineWidth;
	int			m_Track;			//only use in edgebreak -JM
	int			m_LineStyle;
	PNT			m_AnPnt;        //record the position of annotation
	void   Extend(double lm);

	//by jm Feb 7th 2006 *************************************************//
	bool        m_bShowBox;
	double		m_BoxLLeft[3];   //the lower left point to define the box
	double		m_BoxURight[3];  //the upper right point to define the box
	int		    m_FitPntNum;  //the pnt number fitted to line
	double      m_RMS;        //the rms error when fitting
	void		SetShowBox(bool flag);
	bool		GetShowBox();
	bool		SetBox(double left[3], double right[3]);

	//by jm Feb 14 2006 *******************************//
	int			m_st;
	int			m_ed;

protected:
	bool m_DelFlag;					//�����Ƿ��ɾ����־λ��true����ɾ����false������ɾ����
	//PNT	m_StartPt, m_EndPt;		//Start and end points for line segment��ȷ��m_StartPt�����ĽϽ���m_EndPt�����Ľ�Զ

};
