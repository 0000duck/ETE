/*_____________________________________________________
 XCurvObject.h
        Calculator: b-spline curve related functions
		Created by Pinghai Yang
		Revised by Xiaoming Du at Dec 24, 2004

 _____________________________________________________*/

//////////////////////////////////////////////////////////////////////
#pragma once

#include "xcloud.h"
#include "ti_matrix.h"
//#include "xgeombase.h"
#include "xgeneralcurve.h"
typedef CArray <double, double> CDArray;
typedef CArray <PNT,PNT> CVArray;

class  AFX_EXT_CLASS XCurvObj : public XGeneralCurve  
{
public:
	void ResetKnot();
	//
	bool LeastSquaresFromCloud(XCloud  & cloud,int degree,int iCtrlCount);
	bool LeastSquaresClosedFromCloud(XCloud & cloud,int degree,int iCtrlCount);
	//construct interpolate curve from sorted cloud
	bool InterpFromCloud(XCloud  & cloud, int degree);
	//�ӵ��ƹ���պϵĲ�ֵ���ߣ�Ҫ����Ʊ��������Ѿ��ź���
	bool InterpClosedFromCloud(XCloud & cloud,int degree);
	//��ȡ���ߵ�����
	inline int GetCurveType() const {return m_iCurveType;}
	//��ȡ���ߵĽ���
	inline int GetOrder() const {return m_iOrder;}
	//�������ߵ�����
	inline void SetCurveType(int type){m_iCurveType = type;}
	//��С�����������
	bool LeastSquares(const CVArray & dataPoints,int degree = 3,int iCtrlCount = 20);
	bool LeastSquaresClosed(const CVArray & dataPoints,int degree = 3,int iCtrlCount = 20);
	//��ȡ������С��������
	void GetMinMaxPara(float & min,float & max) const;
	//���ò�����m_bSetValue��ֵ
	void  SetBoolValue(bool SetValue);
	void  ShowCtrol(bool bshow)
		{
		m_bShowCtrl = bshow;
		}
	void SetCurveWidth(float width)
		{
		m_fWidth = width;
		}
		float & GetCurveWidth()
		{
			return m_fWidth;
}
	void ChangeUnits(bool bmm2inch= true);			
	//����������ָ��λ�õ���ά���꣬��λ���ɲ���u����
	const PNT  PointAt(float u)const  ;
	
	//�õ�������ָ��λ�õ���ʸ������λ���ɲ���u����
	const PNT  GetTanVector(float u) ;
	
	//����������ָ��λ�õ����ʣ���λ���ɲ���u����
	double ComputeCurvature(float u) ;
	
	//�������ߵ�n�׵�����n��deriDegree
	void ComputeDerivation(float u, int deriDegree,CVArray & ders) ;
	
	//����һϵ�е����ݵ㣬��ֵ����һ������յ�B�������ߣ�Ĭ��Ϊ3��
	bool CreateInterp(const CVArray & dataPoints,int degree=3);
	//����һϵ�е����ݵ㣬��ֵ����һ������յ�B�������ߣ�Ĭ��Ϊ3��(��ָ���ڵ�ʸ��)
	bool CreateInterp(const CVArray & dataPoints,float * ub,int degree=3);
	//����һϵ�е����ݵ�(��ε�)����ֵ����һ������յ�B�������ߣ�Ĭ��Ϊ3��(��ָ���ڵ�ʸ��)
	bool CreateInterpH(const Ti_Matrix<float> & dataPoints,float * ub,float * knots,int degree=3);
	
	//����һϵ�е����ݵ㣬��ֵ����һ����յ�B�������ߣ�Ĭ��Ϊ3��
	bool CreateInterpClosed(const CVArray & dataPoints,int degree=3);
	
	
	//��ȡ�ڵ�����
	int GetKnotsCount() const;
	
	//��ȡ�ڵ�ʸ��
    float * GetKnots();
	//yk0805: ��u0Ϊ��ʼ��������epsilonΪ u[k+1]-u[k] ����ֹ��������LMţ�ٵ�������curve��ѡȡ��pnt����ĵ㣬���ƽ����u* ����u0
	PNT GetNearestPnt(const PNT& pnt, float& u0, const float epsilon);

	//��ȡ���Ƶ�
	Ti_Matrix<float> & GetCtrlPoints();
	const Ti_Matrix<float> & GetCtrlPoints() const;
	//��ArchiveObject�����CreateREObject�������ã�
	//����ͨ��IGES������������
	void SetFromIgs(CDArray & curve,
		int nctrl,
		int degree,
		int unit);
	
	//�޲������캯��
	XCurvObj();
	
	//���������캯��
	XCurvObj(
		const Ti_Matrix<float> & CtrlPoints,
		const float * pKnots,	
		int  	Knots = 0,                     
		int	    Order = 0,
		int		CurveType = 0,
		bool	bClosed = false,
		bool    SetValue = true);
	

	//�������캯��
	XCurvObj(const XCurvObj & curve);
	//��������
	virtual ~XCurvObj();
	////���ò���
	//void SetMaterial(Material *mat);
	////��ȡ����
	//Material* GetMaterial(void) const;

	////��������
	//void SetTexture(Texture2D *texture);
	////��ȡ����
	//Texture2D* GetTexture(void) const;
	XCurvObj& operator=( const XCurvObj& SourceCld );
	
	// ��ȡ�������С����ֵ(minx,miny,minz)���������ֵ(maxx, maxy, maxz)
	virtual void UpdateBndBox() ;

	//// ��ȡ����İ�Χ��(cx,cy,cz) Ϊ�������꣬radius Ϊ�뾶
	//virtual void GetBoundSphere(float *radius, float *cx, float *cy, float *cz) ;
	//
	//// ��ȡ����İ�Χ�У�(cx,cy,cz) Ϊ�������꣬
	//virtual void GetBoundBox(float *dx, float *dy, float *dz, 
	//						 float *cx, float *cy, float *cz) ;


	// ����
	//virtual void Draw(void);
	//�ͷ��ڴ棬����ǰ����
	void FinalRelease();

	//���߷�����
	 void CurveReversal();

	//���߲���ڵ㺯��
	void CurveKnotIns(float u,int r);

	//���߽ڵ��ض���
	void CurveKnotRefine(float* X, int r);

	//���߷ֽ⺯��
	void CurveDecompose();

	//�������׺���
	void CurveDegreeElevate(int t);

	//���߽��׺���
	int CurveDegreeReduce(float TOL);

	//�����������Ķ���ʽϵ��
	int Bin(int a, int b);
	//��׳�
	long int Factor(int a);

	//��������������Сֵ
	int Min2i(int a, int b);
	//���������������ֵ
	int Max2i(int a, int b);

	virtual void Translate(const PNT& delt_t);
	virtual void Rotate(const Ti_Rotation& R);

protected:
	bool    m_bShowCtrl;	
	//���߲����Ƿ���ȷ����
	bool    m_bSetValue;

	//�����Ƿ�պ�
	bool   	m_bClosed;
	// curve width
	float        m_fWidth;
	// �ڵ����� 
	int		m_iKnots;
	
	// B-�������߽���
	int		m_iOrder;

	/*B-������������
	0  �Ǿ�������b������(NURBS)
	1  ����ʽb������(һ��b����)
	2  ֱ��
	3  Բ��Բ��
	*/
	int		m_iCurveType;  
	
	// minimum param value  ��С����ֵ 
	float		m_fMinPara;
	
	 // maximum param value ������ֵ
	float		m_fMaxPara;                  
	
	// bspline knot array,�ڵ�
	float*	m_fpKnots;                  
	
	//control points,���Ƶ�
	Ti_Matrix<float> m_fCtrlPoints;					
	
    //�û��Զ���ָ��
	void*   m_vpUser;             // user pointer will be  
	
	//// ���ò���
	//Material*    m_pMaterial;
 //   
	//// ��������
	//Texture2D*   m_pTexture;
	
	//OpenGL��Ⱦ��
//	GLUnurbsObj* m_pNurbsObj;
protected:
	//���߳�ʼ������
	void InitCurve(void);
	//����B��������������n�׵���
	void DerBasisfuns(int n,float u,int span,Ti_Matrix<double> & ders);
	//����B����������
	void Basisfuns(float u,int i,float * N)const;
	//ȷ������ֵ�����Ľڵ����䣬��������������
	int FindSpan(float u) const;
};

//
/////////////////
////��������ȫ�ֺ���ʵ����XCurvObj.cpp
//friend bool AfxSetHelix(bool direction,
//									  float turns,
//									  float radius,
//									  float pitch,
//									  float spointc[3],
//									  float spoints[3],
//									  float orient[3],
//									  int & n_knot, CDArray & knot,
//									  int & n_ctrl, CDArray & ctrl);
//
//friend bool AfxSetHelixSurf(bool direction,
//										  float turns,
//										  float radius,
//										  float pitch,
//										  float spointc_1[3],
//										  float spointc_2[3],
//										  float spoints[3],
//										  float orient[3],
//										  int & n_knot, CDArray & knot,
//										  int & n_ctrl, CDArray & ctrl);
//};
