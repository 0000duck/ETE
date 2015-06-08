// XCurvObj.cpp: implementation of the XCurvobj  class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "xCurvObject.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

XCurvObj::XCurvObj()
	{
	InitCurve();
	m_ObjectType = OBJECT_CURVE;
	}
XCurvObj::~XCurvObj()
	{
	FinalRelease();
	}


void XCurvObj::InitCurve()
	{	
	/*m_pMaterial = NULL;
	m_pTexture = NULL;*/
	m_fpKnots		= NULL;
	m_vpUser		= NULL;

	m_bSetValue	= false;
	m_iKnots		= 0;             
	m_iOrder		= 0;                
	m_iCurveType	= 0;        
	m_fWidth		= 0.5;
	m_bClosed		= false;
	m_bShowCtrl	= false;	
	//m_pNurbsObj	= gluNewNurbsRenderer();
	//gluNurbsProperty( m_pNurbsObj, GLU_SAMPLING_TOLERANCE, 25.0f);
	}



//
//// ���ò���
//void XCurvObj::SetMaterial(Material *mat)
//{
//	if(m_pMaterial!=NULL)
//		m_pMaterial->Release();	// Container.h
//
//	m_pMaterial=mat;
//	if(mat!=NULL)
//	m_pMaterial->AddRef();
//}
//
//// ��ȡ SurfObject �Ĳ���
//Material * XCurvObj::GetMaterial(void) const
//{
//	return m_pMaterial;
//}
//
//
//// ��������
//void XCurvObj::SetTexture(Texture2D * texture)
//{
//	if(m_pTexture!=NULL)
//		m_pTexture->Release();	// Container.h
//
//	m_pTexture=texture;
//	if(texture!=NULL)
//	m_pTexture->AddRef();
//}
//
//// ��ȡ����
//Texture2D * XCurvObj::GetTexture(void) const
//{
//	return m_pTexture;
//}


// ����
//void XCurvObj::Draw(void)
//	{
//	if(!m_bSetValue)
//		return;
//	if(!this->IsShown())
//		return;
//	//GraphicalObject::Draw();
//	//if(m_pMaterial!=NULL) 
//	//{
//	//// ����������ر�����ʲ������ã���ʱ�����ʵ�Diffuse��ɫ��Ϊ��ǰ��ɫ
//	//	float color[3];
//	//	m_pMaterial->GetDiffuseColor(color);
//	//	glColor3fv(color);
//	//	m_pMaterial->Apply();
//	//}
//
//	//if(m_pTexture!=NULL)	
//	//{
//	//	glEnable(GL_TEXTURE_2D);
//	//	m_pTexture->Apply();
//	//}
//	if(m_bSelected)
//		{
//		this->DrawBndBox();
//		}
//	ApplyColor();
//	int flag;	
//	glGetIntegerv(GL_LIGHTING, &flag);
//	if(flag)	
//		glDisable(GL_LIGHTING);
//		{	
//		glLineWidth(m_fWidth);
//		gluBeginCurve( m_pNurbsObj);
//		gluNurbsCurve(
//			m_pNurbsObj, 
//			m_iKnots, 
//			m_fpKnots,
//			4,
//			m_fCtrlPoints.m[0],
//			m_iOrder,
//			GL_MAP1_VERTEX_4);
//		gluEndCurve( m_pNurbsObj);
//		}
//	//test
//	//m_bShowCtrl = true;
//	//test end
//	if (m_bShowCtrl)
//		{
//		/*GLubyte OpenGL_bits[] = {
//		0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 
//		0x7f, 0xfb, 0xff, 0xff, 0xff, 0x01,
//		0x7f, 0xfb, 0xff, 0xff, 0xff, 0x01, 
//		0x00, 0x03, 0x00, 0x00, 0x00, 0x00,
//		0x3e, 0x8f, 0xb7, 0xf9, 0xfc, 0x01, 
//		0x63, 0xdb, 0xb0, 0x8d, 0x0d, 0x00,
//		0x63, 0xdb, 0xb7, 0x8d, 0x0d, 0x00, 
//		0x63, 0xdb, 0xb6, 0x8d, 0x0d, 0x00,
//		0x63, 0x8f, 0xf3, 0xcc, 0x0d, 0x00, 
//		0x63, 0x00, 0x00, 0x0c, 0x4c, 0x0a,
//		0x63, 0x00, 0x00, 0x0c, 0x4c, 0x0e, 
//		0x63, 0x00, 0x00, 0x8c, 0xed, 0x0e,
//		0x3e, 0x00, 0x00, 0xf8, 0x0c, 0x00, 
//		};*/
//		int m_iPntSize = 2;
//		GLfloat x, y, z;
//		glColor3f(0.f,0.8f,0.8f);
//		glPointSize(m_iPntSize);
//		glEnable(GL_POINT_SMOOTH);
//
//		glBegin(GL_POINTS);
//		for (int i=0; i<m_fCtrlPoints.RowCount(); i++)
//			{
//			x = m_fCtrlPoints.m[i][0]/m_fCtrlPoints.m[i][3];
//			y = m_fCtrlPoints.m[i][1]/m_fCtrlPoints.m[i][3];
//			z = m_fCtrlPoints.m[i][2]/m_fCtrlPoints.m[i][3];
//			glVertex3f(x,y,z);
//			}
//		glEnd();
//		glDisable(GL_POINT_SMOOTH);
//		glColor3f(0.3f,0.3f,0.3f);
//		glBegin(GL_LINE_STRIP);
//		for (i=0; i<m_fCtrlPoints.RowCount(); i++)
//			{
//			x = m_fCtrlPoints.m[i][0]/m_fCtrlPoints.m[i][3];
//			y = m_fCtrlPoints.m[i][1]/m_fCtrlPoints.m[i][3];
//			z = m_fCtrlPoints.m[i][2]/m_fCtrlPoints.m[i][3];
//			glVertex3f(x,y,z);
//
//			}
//		glEnd();
//		}
//	if(flag) glEnable(GL_LIGHTING);
//	glDisable(GL_TEXTURE_2D);
//	}
//
	
void XCurvObj::FinalRelease()
{
	//Container::FinalRelease();
	//if( m_pNurbsObj!=NULL)
	//	{
	//	gluDeleteNurbsRenderer( m_pNurbsObj);
	//	m_pNurbsObj = NULL;
	//	}
	/*if(m_pMaterial!=NULL) 
		m_pMaterial->Release(); 
	if(m_pTexture!=NULL) 
		m_pTexture->Release();*/
	if(m_fpKnots!=NULL) 
		{
		delete []m_fpKnots;
		m_fpKnots = NULL;
		}
	if(m_vpUser!=NULL) 
		{
		delete []m_vpUser;
		m_vpUser = NULL;
		}
	
	m_fCtrlPoints.Destroy();
	/*m_BoundBox.m_BoxVertex.Destroy();
	m_BoundBox.m_SCBox.Destroy();*/
	
}

XCurvObj& XCurvObj::operator=( const XCurvObj&  SourceCld)
	{
	if( &SourceCld != this)
		{
			if(this->m_iCurveType == OBJECT_CURVE)
				this->FinalRelease();
		*(XGeomBase*)this = SourceCld;


		m_fWidth		= SourceCld.m_fWidth;
		//m_BinArray = NULL;
		this->m_fCtrlPoints = SourceCld.m_fCtrlPoints;
		this->m_fMaxPara	= SourceCld.m_fMaxPara;
		this->m_fMinPara	= SourceCld.m_fMinPara;
		this->m_iKnots		= SourceCld.m_iKnots;
		m_fpKnots = new float[m_iKnots];
		for(int i =0; i< m_iKnots; i++)
			m_fpKnots[i] = SourceCld.m_fpKnots[i];
		this->m_iCurveType	= SourceCld.m_iCurveType;
		this->m_iOrder		= SourceCld.m_iOrder;
		//m_pNurbsObj = gluNewNurbsRenderer();
		//gluNurbsProperty( m_pNurbsObj, GLU_SAMPLING_TOLERANCE, 25.0f);	
		}
	return *this;
	}

// ��ȡ�������С����ֵ(minx,miny,minz)���������ֵ(maxx, maxy, maxz)
void XCurvObj::UpdateBndBox(void) 
	{
	int i=0,j=0;
	PNT  tempmin;
	if(this->m_bObjChanged)
		{
		m_bObjChanged = false;
		for(j=0;j<m_fCtrlPoints.RowCount();j++)
			{
			for(i = 0 ;i<3;i++)
				{
				tempmin[i]=m_fCtrlPoints.m[j][i]/m_fCtrlPoints.m[j][3];
				}
			this->m_BndBox.AddVertex(tempmin);
			}
		}	
	}

	void XCurvObj::Translate(const PNT& delt_t)
	{
	this->m_bDispChanged = true;

	}
	void XCurvObj::Rotate(const Ti_Rotation& R)
	{
	this->m_bDispChanged = true;
	}

//
//// ��ȡ����İ�Χ��(cx,cy,cz) Ϊ�������꣬radius Ϊ�뾶
//void XCurvObj::GetBoundSphere(float *radius, float *cx, float *cy, float *cz)
//{
//	float minx,miny,minz;
//	float maxx,maxy,maxz;
//	GetMinMax(&minx, &miny, &minz,&maxx, &maxy, &maxz);
//	*cx=(minx+maxx)/2;
//	*cy=(miny+maxy)/2;
//	*cz=(minz+maxz)/2;
//	*radius=sqrt((minx-*cx)*(minx-*cx)+
//		(miny-*cy)*(miny-*cy)+
//		(minz-*cz)*(minz-*cz));
//
//
//}
//	
//// ��ȡ����İ�Χ�У�(cx,cy,cz) Ϊ�������꣬
//void XCurvObj::GetBoundBox(float *dx, float *dy, float *dz, 
//							float *cx, float *cy, float *cz)
//{
//	float minx,miny,minz;
//	float maxx,maxy,maxz;
//	GetMinMax(&minx, &miny, &minz,&maxx, &maxy, &maxz);
//	*cx=(minx+maxx)/2;
//	*cy=(miny+maxy)/2;
//	*cz=(minz+maxz)/2;
//	*dx=(maxx-minx);
//	*dy=(maxy-miny);
//	*dz=(maxz-minz);
//}

void XCurvObj::SetFromIgs(CDArray & curve,	int nctrl,
			  int degree,	int unit)
	{

	if(m_bSetValue){
		delete 	[]m_fpKnots;
		}
int i,k;
float unitpara=1.;
m_iOrder = degree+1;
m_iKnots = nctrl+m_iOrder;	 //nctrl������Ƶ����

m_fpKnots = new float[m_iKnots];

for(i=0;i<m_iKnots;i++)
	{	
	m_fpKnots[i]=curve[i];
	}
m_fMinPara = m_fpKnots[m_iOrder-1];
m_fMaxPara = m_fpKnots[m_iKnots-m_iOrder+1];

m_fCtrlPoints.Create(nctrl,4);

for(i=0;i<nctrl;i++)
m_fCtrlPoints.m[i][3]=curve[m_iKnots+i];
///////////////////////////////////////////
//1��Ӣ��             7������            //
//2������		      8��Mils��0.001Ӣ�� //
//3���ο�15����	      9��΢��			 //
//4��Ӣ��             10������           //
//5��Ӣ��             11��΢Ӣ��         //
//6����	                                 //
///////////////////////////////////////////

switch(unit)
	{
	case 6:	unitpara=1000.; break;	
	case 7:	unitpara=1000000.;break;
	case 9:	unitpara=0.001f;break;
	case 10:	unitpara=10.;break;
	default: unitpara=1.;
		break;
	}

for(i=0;i<nctrl;i++){
	for(k=0;k<3;k++){					    
		m_fCtrlPoints.m[i][k]=curve[m_iKnots+nctrl+3*i+k]
	*curve[m_iKnots+i]*unitpara;
		}
	}

m_bSetValue=true;

	}


/*********************************************************************
* ��������:XCurvObj::GetCtrlPoints
* ˵��:��ȡ���Ƶ�
* ��ڲ���:
* ����ֵ:
* inline const Ti_Matrix<float> &  -- 
* ����: ��ƽ�� 
* ʱ�� : 2003-05-24 21:25:22 
*********************************************************************/

 const Ti_Matrix<float> & XCurvObj::GetCtrlPoints() const
	{
	return  m_fCtrlPoints;
	}

 Ti_Matrix<float> & XCurvObj::GetCtrlPoints() 
	{
	return  m_fCtrlPoints;
	}


/*********************************************************************
* ��������:XCurvObj::GetKnots
* ˵��:��ȡ�ڵ�ʸ��
* ��ڲ���:
* ����ֵ:
* inline const float *  -- 
* ����: ��ƽ�� 
* ʱ�� : 2003-05-24 21:24:10 
*********************************************************************/
float * XCurvObj::GetKnots()
	{
	return  m_fpKnots;
	}

//yk0805: ��u0Ϊ��ʼ����,��epsilonΪ u[k+1]-u[k] ����ֹ����,��LMţ�ٵ�������curve��ѡȡ��p����ĵ�,���ƽ����u* ����u0
PNT XCurvObj::GetNearestPnt(const PNT& p, float& u0, const float epsilon)
{
	//��curve c(u) = [x(u), y(u), z(u)]T ����p(xp, yp,zp)����� c(u*)��
	//Ҫ��С����Ŀ�꺯����||c(u) - p||^2
	//����LM�㷨����ţ�ٵ����� u[k+1] = u[k] - Df(u[k]) / DDf(u[k]) ����� u* ����ֹ������|u[k+1] - u[k]| <epsilon��
	//���У�Df = JT*r,���� J = [x' y' z']T, r = [x-xp, y-yp, z-zp]
	//DDf =(Լ���ڣ�LM�㷨)= JT*J = x'*x' + y'*y' + z'*z'
	float u2, u1 = u0;
	float xprime, yprime, zprime;
	float DF, DDF;
	do{
	xprime = GetTanVector(u1)[0];
	yprime = GetTanVector(u1)[1];
	zprime = GetTanVector(u1)[2];
	DF = xprime * (PointAt(u1)[0] - p[0]) + yprime * (PointAt(u1)[1] - p[1]) + zprime * (PointAt(u1)[2] - p[2]);
	DDF = xprime*xprime + yprime*yprime + zprime*zprime;
	u2 = u1 - DF/DDF;
	u1 = u2;
	}while (fabs(u2 - u1) > epsilon);	
	u0 = u2; //���ƽ����u*����u0
	return PointAt(u2); //nearest point under the tolerance of epsilon
}

/*********************************************************************
* ��������:XCurvObj::GetKnotsCount
* ˵��:��ȡ�ڵ�����
* ��ڲ���:
* ����ֵ:
* inline int  -- 
* ����: ��ƽ�� 
* ʱ�� : 2003-05-24 21:26:46 
*********************************************************************/
int XCurvObj::GetKnotsCount() const
	{
	return m_iKnots;
	}


/*********************************************************************
* ��������:XCurvObj::CreateInterp
* ˵��:����һϵ�е����ݵ㣬��ֵ����һ��B�������ߣ�Ĭ��Ϊ3��
* ��ڲ���:
* const CVArray & dataPoints -- 
* int degree -- 
* ����ֵ:
* bool  -- 
* ����: ��ƽ�� 
* ʱ�� : 2003-05-24 21:17:00 
*********************************************************************/
bool XCurvObj::CreateInterp(const CVArray & dataPoints,int degree)
	{
	//chordLengthParam(Q,ub)
	//T chordLengthParam(const Vector< Point_nD<T,N> >& Q, Vector<T> &ub)
	if(dataPoints.GetSize()<=1)
		{
		m_bSetValue = false;
		return false;
		}
	int i;
	CVArray newDataPoints;
	newDataPoints.SetAtGrow(0,dataPoints[0]);
	for(i=1;i<dataPoints.GetSize();i++)
		{
		if((dataPoints[i]-dataPoints[i-1])*(dataPoints[i]-dataPoints[i-1])<1e-3)
			continue;
		newDataPoints.Add(dataPoints[i]); 
		}

	int ubNum = newDataPoints.GetSize();
	if(ubNum<=1) 
		{
		m_bSetValue = false;
		return false;
		}


	float totalChord = 0.;
	float * ub = new float[ubNum];
	ub[0] = 0.;

	if(degree > ubNum-1) 
		degree = ubNum - 1;

	for(i=1;i<ubNum;i++)
		{
		totalChord += sqrt((newDataPoints[i]-newDataPoints[i-1]) *(newDataPoints[i]-newDataPoints[i-1]));
		}

	if(totalChord > 0)
		{
		for(i=1;i<ubNum-1;i++)
			{
			ub[i] = ub[i-1] + sqrt((newDataPoints[i]-newDataPoints[i-1])*(newDataPoints[i]-newDataPoints[i-1]))/totalChord ;		
			}
		ub[ubNum-1] = 1.0 ; 
		}
	else{
		for(i=1;i<ubNum-1;i++)
			{
			ub[i] = float(i)/float(ubNum-1) ;
			}
		ub[ubNum-1] = 1.0 ;
		}//end
	m_iOrder = degree+1;
	m_iKnots = ubNum + m_iOrder;
	if(m_fpKnots!=NULL)
		{
		delete 	[]m_fpKnots;
		}
	m_fpKnots = new float[m_iKnots];
	m_fCtrlPoints.Create(ubNum,4);

	int j ;
	for(j=1; j<ubNum-degree; j++)
		{
		m_fpKnots[j+degree] = 0.0 ;
		for(int i=j;i<j+degree;++i)
			m_fpKnots[j+degree] += ub[i] ;
		m_fpKnots[j+degree] /= (float)degree ;
		}
	for(j=0;j<=degree; j++)
		m_fpKnots[j] = 0.0 ;
	for(j=m_iKnots-degree-1;j<m_iKnots;j++)
		m_fpKnots[j] = 1.0 ;

	m_fMinPara = m_fpKnots[m_iOrder-1];
	m_fMaxPara = m_fpKnots[m_iKnots-m_iOrder+1];
	//end
	// Initialize the basis matrix A
	float * tempN = new float[m_iOrder];
	Ti_Matrix<double> A,xx,qq;
	A.Create(ubNum,ubNum);
	xx.Create(ubNum,3);
	qq.Create(ubNum,3);


	for(i=1;i<ubNum-1;i++)
		{
		int span = FindSpan(ub[i]);
		Basisfuns(ub[i],span,tempN) ;
		for(j=0;j<=m_iOrder-1;j++) 
			A.m[i][span-m_iOrder+1+j] = (double)tempN[j] ;
		}
	A.m[0][0]  = 1.0 ;
	A.m[ubNum-1][ubNum-1] = 1.0 ;


	for(i=0;i<ubNum;i++)
		{
		qq.m[i][0] = newDataPoints[i][0] ;
		qq.m[i][1] = newDataPoints[i][1] ;
		qq.m[i][2] = newDataPoints[i][2] ;
		}

	if(!A.Invert(1e-12)) 
		{
		delete []ub;
		delete []tempN;
		return false;
		}
	xx.Multiply(A,qq);

	for(i=0;i<ubNum;i++)
		{
		for(j=0;j<3;j++)
			m_fCtrlPoints.m[i][j]=xx.m[i][j];

		m_fCtrlPoints.m[i][3]=1.;
		}
	m_iCurveType = 1;
	m_bSetValue = true;
	delete []ub;
	delete []tempN;
	return true;
	}



int XCurvObj::FindSpan(float u)const
	{
	if(u>=m_fpKnots[m_fCtrlPoints.RowCount()]) 
		return m_fCtrlPoints.RowCount() - 1 ;
	if(u<=m_fpKnots[m_iOrder - 1])
		return m_iOrder - 1 ;

	int low  = 0 ;
	int high = m_fCtrlPoints.RowCount()+1 ; 
	int mid = (low+high)/2 ;

	while(u<m_fpKnots[mid] || u>= m_fpKnots[mid+1])
		{
		if(u<m_fpKnots[mid])
			high = mid ;
		else
			low = mid ;
		mid = (low+high)/2 ;
		}
return mid ;
	}

void XCurvObj::Basisfuns(float u, int i, float * N)const
	{
	float * left = new float[2*m_iOrder]  ;
	float * right = &left[m_iOrder] ; 
	float temp,saved ;

	N[0] = 1.0 ;
	for(int j=1; j<= m_iOrder-1; j++)
		{
		left[j] = u-m_fpKnots[i+1-j] ;
		right[j] = m_fpKnots[i+j]-u ;
		saved = 0.0 ;
		for(int r=0 ; r<j; r++)
			{
			temp = N[r]/(right[r+1]+left[j-r]) ;
			N[r] = saved+right[r+1] * temp ;
			saved = left[j-r] * temp ;
			}
		N[j] = saved ;
		}
	delete []left;	
	}


/*********************************************************************
* ��������:XCurvObj::ComputeDerivation
* ˵��:�������ߵ�n�׵�����n��deriDegree
*      
* ��ڲ���:
* float u -- 
*  int deriDegree -- 
*  CVArray &ders -- 
* ����ֵ:
* void  -- 
* ����: ��ƽ�� 
* ʱ�� : 2003-05-20 19:48:31 
*********************************************************************/
void XCurvObj::ComputeDerivation(float u, int deriDegree, CVArray &ders) 
	{
	int minDegree = (deriDegree < m_iOrder-1)?deriDegree:(m_iOrder - 1) ;
	int span ;
	int i,j;

	Ti_Matrix<double> derF(minDegree +1,m_iOrder) ;
	Ti_Matrix<double> derH(deriDegree +1,4);
	ders.SetSize(deriDegree+1) ;

	span = FindSpan(u) ;
	DerBasisfuns(minDegree,u,span,derF) ;
	for(i=minDegree;i>=0;i--)
		{
		derH.m[i][0] =derH.m[i][1] =derH.m[i][2] = derH.m[i][3] = 0 ;
		for( j = m_iOrder-1;j>=0;j--)
			{
			derH.m[i][0] += derF.m[i][j] * m_fCtrlPoints.m[span-m_iOrder+1+j][0] ;
			derH.m[i][1] += derF.m[i][j] * m_fCtrlPoints.m[span-m_iOrder+1+j][1] ;
			derH.m[i][2] += derF.m[i][j] * m_fCtrlPoints.m[span-m_iOrder+1+j][2] ;
			derH.m[i][3] += derF.m[i][j] * m_fCtrlPoints.m[span-m_iOrder+1+j][3];
			}
		}

	//static 
	Ti_Matrix<double> Bin(1,1) ;
	if(Bin.RowCount() != deriDegree+1)
		{
		Bin.Create(deriDegree+1,deriDegree+1) ;
		int n,k ;
		// Setup the first line
		Bin.m[0][0] = 1.0 ;
		for(k=Bin.ColCount()-1;k>0;k--)
			Bin.m[0][k] = 0.0 ;
		// Setup the other lines
		for(n=0;n<Bin.RowCount()-1;n++)
			{
			Bin.m[n+1][0] = 1.0 ;
			for(k=1;k<Bin.ColCount();k++)
				{
				if(n+1<k)
					Bin.m[n][k] = 0.0 ;
				else
					Bin.m[n+1][k] = Bin.m[n][k] + Bin.m[n][k-1] ;
				}
			}
		}

	// Compute the derivative at the parmeter u
	PNT v(0,0,0);
	for(i=0;i<=deriDegree;i++)
		{
		ders[i] = v;
		}
	for(int k=0;k<=deriDegree;k++)
		{
		v[0] = derH[k][0] ;
		v[1] = derH[k][1] ;
		v[2] = derH[k][2] ;
		for(i=k ;i>0 ;i--)
			{
			v[0] -= (Bin.m[k][i]*derH[i][3])*ders[k-i][0];
			v[1] -= (Bin.m[k][i]*derH[i][3])*ders[k-i][1];
			v[2] -= (Bin.m[k][i]*derH[i][3])*ders[k-i][2];
			}
		ders[k] = v/derH[0][3] ;		
		}
	}

void XCurvObj::DerBasisfuns(int n, float u, int span, Ti_Matrix<double> &ders)
	{
	double * left = new double[2*m_iOrder]  ;
	double * right = &left[m_iOrder] ; 
	double temp,saved ;

	Ti_Matrix<double> ndu(m_iOrder,m_iOrder) ;
	int j,r ;

	ders.Create(n+1,m_iOrder) ;

	ndu.m[0][0] = 1.0 ;
	for(j=1; j<= m_iOrder-1 ;j++){
		left[j] = u - m_fpKnots[span+1-j] ;
		right[j] = m_fpKnots[span+j] - u ;
		saved = 0.0 ;

		for(r=0;r<j ; r++){
			// Lower triangle
			ndu.m[j][r] = right[r+1]+left[j-r] ;
			temp = ndu.m[r][j-1]/ndu.m[j][r] ;
			// Upper triangle
			ndu.m[r][j] = saved+right[r+1] * temp ;
			saved = left[j-r] * temp ;
			}

	ndu.m[j][j] = saved ;
		}

for(j = m_iOrder-1;j>=0;j--)
ders.m[0][j] = ndu.m[j][m_iOrder-1] ;

// Compute the derivatives
Ti_Matrix<double> a(2,m_iOrder) ;//����
for(r=0;r<=m_iOrder-1;r++){
	int s1,s2 ;
	s1 = 0 ; s2 = 1 ; // alternate rows in array a
	a.m[0][0] = 1.0 ;
	// Compute the kth derivative

	for(int k=1;k<=n;k++){
		double d ;
		int rk,pk,j1,j2 ;
		d = 0.0 ;
		rk = r-k ; pk = m_iOrder-1-k ;

		if(r>=k){
			a.m[s2][0] = a.m[s1][0]/ndu.m[pk+1][rk] ;
			d = a.m[s2][0]*ndu.m[rk][pk] ;
			}

	if(rk>=-1){
		j1 = 1 ;
		}
	else{
		j1 = -rk ;
		}

if(r-1 <= pk){
	j2 = k-1 ;
	}
else{
	j2 = m_iOrder-1-r ;
	}

for(j=j1;j<=j2;j++){
	a.m[s2][j] = (a.m[s1][j]-a.m[s1][j-1])/ndu.m[pk+1][rk+j] ;
	d += a.m[s2][j]*ndu.m[rk+j][pk] ;
	}

if(r<=pk){
	a.m[s2][k] = -a[s1][k-1]/ndu[pk+1][r] ;
	d += a.m[s2][k]*ndu.m[r][pk] ;
	}
ders.m[k][r] = d ;
j = s1 ; s1 = s2 ; s2 = j ; // Switch rows
		}
	}
// Multiply through by the correct factors
r = m_iOrder-1 ;
for(int k=1;k<=n;k++)
	{
	for(j=m_iOrder-1;j>=0;j--)
		ders.m[k][j] *= r ;
	r *= m_iOrder-1-k ;		
	}
delete []left;
	}


/*********************************************************************
* ��������:XCurvObj::ComputeCurvature
* ˵��:����������ָ��λ�õ����ʣ���λ���ɲ���u����
* ��ڲ���:
* float u -- 
* ����ֵ:
* double  -- 
* ����: ��ƽ�� 
* ʱ�� : 2003-05-22 11:25:53 
*********************************************************************/
double XCurvObj::ComputeCurvature(float u)
	{

	int deriDegree=2;	
	CVArray aders;
	ComputeDerivation(u,deriDegree,aders);

	double CurvRadius ;
	if ((CurvRadius = (aders[1])*(aders[1])
		*(aders[1]).Length()/(aders[1]^aders[2]).Length())>1e300)
		CurvRadius = -1;
	return CurvRadius; 
	}


/*********************************************************************
* ��������:XCurvObj::GetTanVector
* ˵��:�õ�������ָ��λ�õ���ʸ������λ���ɲ���u����
* ��ڲ���:
* float u -- 
* ����ֵ:
* const PNT &  -- 
* ����: ��ƽ�� 
* ʱ�� : 2003-05-24 20:59:22 
*********************************************************************/
const PNT XCurvObj::GetTanVector(float u) 
	{
	int deriDegree = 1;	
	CVArray aders;

	ComputeDerivation(u,deriDegree,aders);

	return PNT(aders[1]); 	
	}

void XCurvObj::ResetKnot()
	{

	if ( m_fpKnots[m_iOrder-1]<0 || m_fpKnots[m_iKnots-m_iOrder+1]>1
		|| fabs(m_fpKnots[m_iKnots-m_iOrder+1]-m_fpKnots[m_iOrder-1]-1)>1e-8)
		{
		double min = m_fpKnots[m_iOrder-1];
		double interu = m_fpKnots[m_iKnots-m_iOrder+1]-m_fpKnots[m_iOrder-1];
		for (int i=0 ; i< m_iKnots; i++)
			{
			m_fpKnots[i] = (m_fpKnots[i]-min)/interu;
			}
		}	
	m_fMinPara = 0;
	m_fMaxPara = 1;
	}

/*********************************************************************
* ��������:XCurvObj::PointAt
* ˵��:����������ָ��λ�õ���ά���꣬��λ���ɲ���u����
* ��ڲ���:
* float u -- ����ֵ
* ����ֵ:
* const PNT &  -- �����ά����
* ����: ��ƽ�� 
* ʱ�� : 2003-05-24 20:43:58 
*********************************************************************/
const PNT XCurvObj::PointAt(float u)const 
	{
	float * tempN = new float[m_iOrder]; 
	double HPoint[4] = {0};
	int span = FindSpan(u) ;
	Basisfuns(u,span,tempN) ;

	for(int i = m_iOrder-1,j; i>=0; i--) 
		for(j = 0; j<4; j++)
			{
			HPoint[j] += tempN[i] * m_fCtrlPoints.m[span-m_iOrder+i+1][j] ;
			}

		PNT Point(HPoint[0]/HPoint[3],HPoint[1]/HPoint[3],HPoint[2]/HPoint[3]);		;

		delete []tempN;
		return Point ; 
	}

/*********************************************************************
* ��������:XCurvObj::SetboolValue
* ˵��:���ò�����m_bSetValue��ֵ
* ��ڲ���:
* bool SetValue -- 
* ����ֵ:
* void  -- 
* ����: ��ƽ�� 
* ʱ�� : 2003-05-24 20:58:20 
*********************************************************************/
void XCurvObj::SetBoolValue(bool  SetValue)
	{
	m_bSetValue = SetValue;
	}

void XCurvObj::ChangeUnits(bool bmm2inch)
	{
	if(bmm2inch)
		{
		int i,j;
		for( i=0; i<this->m_fCtrlPoints.RowCount(); i++)
			for(j=0;j<3;j++)
			m_fCtrlPoints.m[i][j] /= 25.4f;
		}
	else
		{
		int i,j;
		for( i=0; i<m_fCtrlPoints.RowCount(); i++)
			for(j=0;j<3;j++)
			m_fCtrlPoints.m[i][j] *= 25.4f;
		}
	//XGraphicObj::ChangeUnits(bmm2inch);
	}

/*********************************************************************
* ��������:XCurvObj
* ˵��:�������Ĺ��캯��������	Knots , Order ,CurveType,Closed ,
*       SetValue����Ĭ�ϲ���
* ��ڲ���:
* const Ti_Matrix<float> & CtrlPoints -- ���Ƶ�
*  const float * pKnots -- �ڵ�ʸ��
*  int Knots  -- �ڵ���
*  int Order  -- ����
*  int CurveType -- ��������
*  bool Closed  -- �Ƿ�պ�
*  bool SetValue  -- �Ƿ�ֵ
* ����ֵ:
* XCurvObj::  -- 
* ����: ��ƽ�� 
* ʱ�� : 2003-05-24 20:45:33 
*********************************************************************/
XCurvObj::XCurvObj(const Ti_Matrix<float> & CtrlPoints,
			 const float * pKnots,	
			 int  	Knots ,                     
			 int	    Order ,
			 int	 CurveType,
			 bool	Closed ,
			 bool    SetValue ) 
			 :m_fCtrlPoints(CtrlPoints), 
			 m_iKnots(Knots),
			 m_iOrder(Order),
			 m_iCurveType(CurveType),
			 m_bClosed(Closed),
			 m_bSetValue(SetValue)
	{
	/*m_pMaterial = NULL;
	m_pTexture  = NULL;*/
	m_vpUser = NULL;

	if(m_iKnots<=0)
		{ 
		m_fpKnots = NULL;
		m_bSetValue = false;
		}
	else {	
		m_fpKnots = new float[m_iKnots];
		for(int i=0; i<m_iKnots; i++)
			m_fpKnots[i] = pKnots[i];
		m_fMinPara = m_fpKnots[m_iOrder-1];
		m_fMaxPara = m_fpKnots[m_iKnots-m_iOrder+1];
		}
	if(m_fCtrlPoints.ColCount()<4)
	{
	m_fCtrlPoints.Create(CtrlPoints.RowCount(),4);
	int i,j;
	for( i=0;i<CtrlPoints.RowCount();i++)
		for(j=0;j<CtrlPoints.ColCount();j++)
			m_fCtrlPoints.m[i][j] += CtrlPoints.m[i][j];

	}
	m_bShowCtrl = false;
	//m_pNurbsObj = gluNewNurbsRenderer();
	//gluNurbsProperty( m_pNurbsObj, GLU_SAMPLING_TOLERANCE, 25.0f);
	}


/*********************************************************************
* ��������:XCurvObj
* ˵��:�������캯����ע��
* ��ڲ���:
* const XCurvObj & curve -- ���Ƶ�m_vpUserָ��δ����
* ����ֵ:
* XCurvObj::  -- 
* ����: ��ƽ�� 
* ʱ�� : 2003-05-24 20:45:33 
*********************************************************************/
XCurvObj::XCurvObj(const XCurvObj & curve)
:m_fCtrlPoints(curve.m_fCtrlPoints),
m_iKnots(curve.m_iKnots),
m_iOrder(curve.m_iOrder),
m_iCurveType(curve.m_iCurveType),
m_bClosed(curve.m_bClosed),
m_bSetValue(curve.m_bSetValue),
m_fMinPara(curve.m_fMinPara),
m_fMaxPara(curve.m_fMaxPara),
m_bShowCtrl(curve.m_bShowCtrl)
	{
		//m_pNurbsObj = NULL;
		//*this = curve;
	this->m_ObjectType = OBJECT_CURVE;
	m_fpKnots = new float[m_iKnots];
	for(int i=0; i<m_iKnots; i++)
		m_fpKnots[i] = curve.m_fpKnots[i];
	this->m_Name = curve.m_Name;

	/*	m_vpUser = new void[sizeof(curve.m_vpUser)/sizeof(*curve.m_vpUser)];
	for(int i=0; i<sizeof(curve.m_vpUser)/sizeof(*curve.m_vpUser); i++)
	{
	m_vpUser[i] = curve.m_vpUser[i];
	}*/
	m_vpUser = NULL;

	/*m_pMaterial = curve.m_pMaterial;
	m_pTexture = curve.m_pTexture;
	if(m_pMaterial!=NULL) m_pMaterial->AddRef();
	if(m_pTexture!=NULL) m_pTexture->AddRef();*/

	//m_pNurbsObj = gluNewNurbsRenderer();
	//gluNurbsProperty( m_pNurbsObj, GLU_SAMPLING_TOLERANCE, 25.0f);

	}


/*********************************************************************
* ��������:XCurvObj::GetMinMaxPara
* ˵��:�õ����ߵ���С��������ֵ
* ��ڲ���:
* float &min -- 
*  float &max -- 
* ����ֵ:
* void  -- 
* ����: ��ƽ�� 
* ʱ�� : 2003-05-24 22:04:29 
*********************************************************************/
void XCurvObj::GetMinMaxPara(float &min, float &max) const
	{
	min = m_fMinPara;
	max = m_fMaxPara; 
	}

/*********************************************************************
* ��������:XCurvObj::LeastSquares
* ˵��:�����������
* ��ڲ���:
* const CVArray & dataPoints -- ����ĵ���
* int degree -- ���ߵĴ���
* int iCtrlCount -- ���߿��Ƶ����
* ����ֵ:
* bool  -- �Ƿ�ɹ����
* ����: ��ƽ�� 
* ʱ�� : 2003-05-26 19:56:51 
*********************************************************************/
bool XCurvObj::LeastSquares(const CVArray & dataPoints,int degree,int iCtrlCount)
	{
	int i,j,span;
	int ubNum = dataPoints.GetSize();
	if(ubNum<=1) 
		{
		m_bSetValue = false;
		return false;
		}
	float totalChord = 0.;
	float * ub = new float[ubNum];
	ub[0] = 0.;

	for(i=1;i<ubNum;i++)
		{
		totalChord += (dataPoints[i] - dataPoints[i-1]).Length() ;
		}
	if(totalChord > 0)
		{
		for(i=1;i<ubNum-1;++i)
			{
			ub[i] = ub[i-1] + (dataPoints[i] - dataPoints[i-1]).Length()/totalChord ;
			ub[ubNum-1] = 1.0 ; // 
			}
		}
	else{
		for(i=1;i<ubNum-1;++i)
			ub[i] = float(i)/float(ubNum-1) ;
		ub[ubNum-1] = 1.0 ;
		}
	if(degree > ubNum-1)
		degree = ubNum - 1;
	if(iCtrlCount > ubNum) 
		iCtrlCount = ubNum ;
	if(degree > iCtrlCount - 1) 
		degree = iCtrlCount - 1 ;
	m_iOrder = degree+1;
	m_iKnots = iCtrlCount + m_iOrder;
	m_fCtrlPoints.Create(iCtrlCount,4);
	if(m_fpKnots!=NULL)
		{
		delete 	[]m_fpKnots;
		}
	m_fpKnots = new float[m_iKnots];

	double sub;
	double factor = (double)(ubNum)/(double)(iCtrlCount) ; 

	for(i=0;i<m_iKnots;i++)
		m_fpKnots[i]=1.;
	for(i=0;i<m_iOrder;i++)
		m_fpKnots[i]=0.;

	for(j=1;j<iCtrlCount-m_iOrder+1;j++)
		{
		m_fpKnots[m_iOrder-1+j] = 0.0 ;
		for(int k=j;k<j+m_iOrder-1;k++)
			{
			i = (int)(k*factor) ;
			sub = double(k*factor)-i ;
			m_fpKnots[m_iOrder-1+j] += sub*ub[int((k-1)*factor)]+(1 - sub)*ub[i] ;
			}
		m_fpKnots[m_iOrder-1+j] /= m_iOrder - 1 ;
		}
	CVArray R,rk; 
	float * funs = new float[m_iOrder] ;
	Ti_Matrix<double> N(ubNum,iCtrlCount);
	R.SetSize(iCtrlCount), rk.SetSize(ubNum);

	R[0] = dataPoints[0];
	R[iCtrlCount-1] = dataPoints[ubNum-1] ;
	N.m[0][0] = 1.0 ;
	N.m[ubNum-1][iCtrlCount-1] = 1.0 ;

	for(i=0;i<ubNum;i++)
		{
		span = FindSpan(ub[i]) ;
		Basisfuns(ub[i],span,funs);
		for(j=0; j<=m_iOrder-1; ++j)
			{ 
			N.m[i][span-m_iOrder+1+j] = (double)funs[j] ;
			}
		rk[i] = dataPoints[i] - dataPoints[0]*N.m[i][0]- dataPoints[ubNum-1]*N.m[i][iCtrlCount-1] ;  
		}

	for(i=0;i<iCtrlCount;i++)
		{
		R[i]= PNT() ;
		for(j=0;j<ubNum;j++)
			R[i] = R[i] + N.m[j][i]*rk[j] ;
		if(R[i][0]*R[i][0]<1e-10 && R[i][1]*R[i][1]<1e-10 
			&& R[i][2]*R[i][2]<1e-10)
			{
			delete []ub;
			delete []funs;
			return false ; 
			}
		}

	// �ⷽ��      N^T*N*P = R
	// ����ֻ����������
	if(iCtrlCount - 2>0)
		{ 
		Ti_Matrix<double> X(iCtrlCount-2,3),
			B(iCtrlCount-2,3),Ns(ubNum-2,iCtrlCount-2) ;

		for(i=0;i<B.RowCount();i++)
			{
			B.m[i][0] = R[i+1][0] ;
			B.m[i][1] = R[i+1][1] ;
			B.m[i][2] = R[i+1][2] ;
			}

		for(i=1;i<=ubNum-2;i++)
			for(j=1;j<=iCtrlCount-2;j++)	
				Ns.m[i-1][j-1] = N.m[i][j];
		//�ⷽ��(transpose(Ns)*Ns,B,X) ;
		Ti_Matrix<double> NsTrans,Prod;
		NsTrans.Create(ubNum-2,iCtrlCount-2);

		for(i=0;i<ubNum-2;i++)
			for(j=0;j<iCtrlCount-2;j++)		
				NsTrans.m[i][j]=Ns.m[i][j];

		NsTrans.Transpose();
		Prod.Create(iCtrlCount-2,iCtrlCount-2);
		Prod.Multiply(NsTrans,Ns);

		if(!Prod.Invert(1e-12)) 
			{
			delete []ub;
			delete []funs;
			return false;
			}
		X.Multiply(Prod,B);

		for(i=0;i<iCtrlCount;i++)
			m_fCtrlPoints[i][3] = 1.0 ;
		for(i=0;i<X.RowCount();i++)
			for(j=0;j<X.ColCount();j++)
				m_fCtrlPoints[i+1][j] = X.m[i][j] ;
		}
	m_fCtrlPoints.m[0][0] = dataPoints[0][0] ;
	m_fCtrlPoints.m[0][1] = dataPoints[0][1] ;
	m_fCtrlPoints.m[0][2] = dataPoints[0][2] ;

	m_fCtrlPoints.m[iCtrlCount-1][0] = dataPoints[ubNum-1][0] ;
	m_fCtrlPoints.m[iCtrlCount-1][1] = dataPoints[ubNum-1][1] ;
	m_fCtrlPoints.m[iCtrlCount-1][2] = dataPoints[ubNum-1][2] ;

	m_fMinPara = m_fpKnots[m_iOrder-1];
	m_fMaxPara = m_fpKnots[m_iKnots-m_iOrder+1];
	
	m_iCurveType = 1;
	m_bSetValue = true;
	delete []ub;
	delete []funs;
	return true;
	}

bool XCurvObj::LeastSquaresClosed(const CVArray & dataPoints,int degree,int iCtrlCount)
		{
		int i,j,span;

		CVArray newDataPoints;
		PNT t1,t2;
		t1 = dataPoints[0]*0.333f + dataPoints[dataPoints.GetSize()-1]*0.667f;
		t2 = dataPoints[0]*0.667f + dataPoints[dataPoints.GetSize()-1]*0.333f;
		newDataPoints.SetAtGrow(0,t1);
		newDataPoints.Append(dataPoints);
		newDataPoints.Add(t2);

		int ubNum = newDataPoints.GetSize();
		if(ubNum<=1)
			{
			m_bSetValue = false;
			return false;
			}

		float totalChord = 0.;
		float * ub = new float[ubNum];
		ub[0] = 0.;

		for(i=1;i<ubNum;i++)
			{
			totalChord += (newDataPoints[i] - newDataPoints[i-1]).Length() ;
			}

		if(totalChord > 0)
			{
			for(i=1;i<ubNum-1;++i)
				{
				ub[i] = ub[i-1] + (newDataPoints[i] - newDataPoints[i-1]).Length()/totalChord ;
				ub[ubNum-1] = 1.0 ; // ע��Բ��
				}
			}
		else{
			for(i=1;i<ubNum-1;++i)
				ub[i] = float(i)/float(ubNum-1) ;
			ub[ubNum-1] = 1.0 ;
			}//end
	if(degree > ubNum-1) degree = ubNum - 1;
	if(iCtrlCount > ubNum) iCtrlCount = ubNum ;
	if(degree > iCtrlCount - 1) degree = iCtrlCount - 1 ;
	m_iOrder = degree+1;
	m_iKnots = iCtrlCount + m_iOrder;
	m_fCtrlPoints.Create(iCtrlCount,4);
	if(m_fpKnots!=NULL)
		{
		delete 	[]m_fpKnots;
		}
	m_fpKnots = new float[m_iKnots];

	double sub;
	double factor = (double)(ubNum)/(double)(iCtrlCount) ; 

	for(i=0;i<m_iKnots;i++)
		m_fpKnots[i]=1.;
	for(i=0;i<m_iOrder;i++)
		m_fpKnots[i]=0.;

	for(j=1;j<iCtrlCount-m_iOrder+1;j++)
		{
		m_fpKnots[m_iOrder-1+j] = 0.0 ;

		for(int k=j;k<j+m_iOrder-1;k++)
			{
			i = (int)(k*factor) ;
			sub = double(k*factor)-i ;
			m_fpKnots[m_iOrder-1+j] += sub*ub[int((k-1)*factor)]+(1 - sub)*ub[i] ;
			}
		m_fpKnots[m_iOrder-1+j] /= m_iOrder - 1 ;
		}
	m_fpKnots[m_iOrder-1] = 0.0;
	m_fpKnots[iCtrlCount] = 1.0;

	for(j=0;j<degree; j++)
		{
		m_fpKnots[j] = m_fpKnots[j+iCtrlCount-degree] - 1.0 ;
		}

	for(j=iCtrlCount+1;j<m_iKnots;j++)
		{
		m_fpKnots[j] = 1.0 + m_fpKnots[j-iCtrlCount+degree] ;
		}


	/////////////////////////////////////////////////////////
	iCtrlCount = iCtrlCount - degree;
	CVArray R,rk; 
	float * funs = new float[m_iOrder] ;
	Ti_Matrix<double> N(ubNum,iCtrlCount);
	R.SetSize(iCtrlCount),rk.SetSize(ubNum);


	for(i=0;i<ubNum;i++)
		{
		span = FindSpan(ub[i]) ;
		Basisfuns(ub[i],span,funs);
		for(j=0; j<=m_iOrder-1; ++j)
			{ 
			N.m[i][(span-m_iOrder+1+j)%iCtrlCount] = (double)funs[j] ;
			}

		rk[i] = newDataPoints[i] - N.m[i][0]*newDataPoints[0]
	-N.m[i][iCtrlCount-1]*newDataPoints[ubNum-1] ;  

		}

	Ti_Matrix<double> NsTrans,Prod;
	NsTrans.Create(ubNum,iCtrlCount);
	Ti_Matrix<double> X(iCtrlCount,3),B(iCtrlCount,3);

	for(i=0;i<iCtrlCount;i++)
		{
		for(j=0;j<ubNum;j++)
			{
			PNT qp = newDataPoints[j];
			double Nji = N.m[j][i];		
			B.m[i][0] += Nji * qp[0]; 
			B.m[i][1] += Nji * qp[1]; 
			B.m[i][2] += Nji * qp[2]; 			
			}
		}

	// �ⷽ��      N^T*N*P = R

	for(i=0;i<ubNum;i++)
		{
		for(j=0;j<iCtrlCount;j++)
			{	
			NsTrans.m[i][j]=N.m[i][j];
			}
		}

	NsTrans.Transpose();
	Prod.Create(iCtrlCount,iCtrlCount);
	Prod.Multiply(NsTrans,N);

	if(!Prod.Invert(1e-12)) 
		{
		delete []ub;
		delete []funs;
		return false;
		}
	X.Multiply(Prod,B);

	iCtrlCount = iCtrlCount + degree;
	for(i=0;i<iCtrlCount;i++)
		{
		m_fCtrlPoints[i][3] = 1.0 ;
		}
	for(i=0;i<iCtrlCount;i++)
		{
		for(j=0;j<3;j++)
			{
			m_fCtrlPoints[i][j] = X.m[i%(X.RowCount())][j] ;
			}
		}

	m_fMinPara = m_fpKnots[m_iOrder-1];
	m_fMaxPara = m_fpKnots[m_iKnots-m_iOrder+1];

	m_iCurveType = 1;
	m_bSetValue = true;
	delete []ub;
	delete []funs;
	return true;
		}



/*********************************************************************
* ��������:XCurvObj::InterpFromCloud
* ˵��:�ӵ��ƹ����ֵ���ߣ�Ҫ����Ʊ��������Ѿ��ź���
* ��ڲ���:
* XCloud * cloud -- ���ƶ���
*  int degree -- ���ߴ���
* ����ֵ:
* bool  -- �Ƿ�ɹ�
* ����: ��ƽ�� 
* ʱ�� : 2003-05-30 20:17:51 
*********************************************************************/
bool XCurvObj::InterpFromCloud(XCloud & cloud, int degree)
	{
	/*const PNT * pPoint = cloud.m();
	if(pPoint==NULL) return false;*/
	int iNum = cloud.GetPntNum();
	if(iNum <= 0)	return false;

	CVArray Points;	
	Points.SetSize(iNum);	
	for(int i=0;i<iNum;i++)
		{
		cloud.GetPoint(i, Points[i]);		
		}
	return CreateInterp(Points,degree);
	}


/*********************************************************************
* ��������:XCurvObj::InterpClosedFromCloud
* ˵��:�ӵ��ƹ���պϲ�ֵ���ߣ�Ҫ����Ʊ��������Ѿ��ź���
* ��ڲ���:
* XCloud * cloud -- ���ƶ���
*  int degree -- ���ߴ���
* ����ֵ:
* bool  -- �Ƿ�ɹ�
* ����: ��ƽ�� 
* ʱ�� : 2003-05-30 20:19:51 
*********************************************************************/
bool XCurvObj::InterpClosedFromCloud(XCloud &cloud, int degree)
	{

	/*const PNT * pPoint = cloud->GetPoint();
	if(pPoint==NULL) return false;*/
	int iNum = cloud.GetPntNum();
	if(iNum <= 0)	return false;

	CVArray Points;	
	Points.SetSize(iNum);	
	for(int i=0;i<iNum;i++)
		{
		cloud.GetPoint(i, Points[i] );		
		}
	return CreateInterpClosed(Points,degree);	
	}


/*********************************************************************
* ��������:XCurvObj::CreateInterpClosed
* ˵��:����һϵ�е����ݵ㣬��ֵ����һ���պ�B�������ߣ�Ĭ��Ϊ3��
* ��ڲ���:
* const CVArray & dataPoints -- 
* int degree -- 
* ����ֵ:
* bool  -- 
* ����: ��ƽ�� 
* ʱ�� : 2003-05-30 20:28:59 
*********************************************************************/
bool XCurvObj::CreateInterpClosed(const CVArray & dataPoints,  int degree)
	{
	if(dataPoints.GetSize()<=1)
		{
		m_bSetValue = false;
		return false;
		}
	int i;
	CVArray newDataPoints;
	newDataPoints.SetAtGrow(0,dataPoints[0]);
	for(i=1;i<dataPoints.GetSize();i++)
		{
		if((dataPoints[i]-dataPoints[i-1]).Length()<1e-3) continue;
		newDataPoints.Add(dataPoints[i]); 
		}	
	int ubNum = newDataPoints.GetSize();
	if(ubNum<=1) 
		{
		m_bSetValue = false;
		return false;
		}
	PNT t = 0.5 * (newDataPoints[0] + newDataPoints[ubNum-1]);
	newDataPoints.InsertAt(0,t);
	for(i=0;i<degree;i++)
		{
		newDataPoints.Add(newDataPoints[i]);
		}
	ubNum = newDataPoints.GetSize();

	float totalChord = 0.;
	float * ub = new float[ubNum];
	ub[0] = 0.;

	for(i=1;i<=ubNum-degree;i++)
		{
		totalChord += (newDataPoints[i]-newDataPoints[i-1]).Length() ;
		}

	if(totalChord > 0)
		{
		for(i=1;i<ubNum;i++)
			{
			ub[i] = ub[i-1] + (newDataPoints[i]-newDataPoints[i-1]).Length();
			}
		for(i=1;i<ubNum;i++)
			{
			ub[i] /= totalChord;
			}
		}
	else{
		for(i=1;i<ubNum;i++)
			{
			ub[i] = float(i)/float(ubNum-2) ;
			}
		}

//end

m_iOrder = degree+1;
m_iKnots = ubNum + m_iOrder;

if(m_fpKnots!=NULL)
	{
	delete 	[]m_fpKnots;
	}
m_fpKnots = new float[m_iKnots];
m_fCtrlPoints.Create(ubNum,4);

int j,index;
for(j=0; j<ubNum-degree+1; j++)
	{
	index = j + degree  ;
	m_fpKnots[index] = 0.0 ;
	for(int i=j;i<=j+degree-1;i++)
		m_fpKnots[index] += ub[i] ;
	m_fpKnots[index] /= (float)degree ;
	}

for(j=0;j<degree; j++)
	{
	m_fpKnots[j] = m_fpKnots[j+ubNum-degree] - m_fpKnots[ubNum] + m_fpKnots[m_iOrder-1];
	}

for(j=ubNum+1;j<m_iKnots;j++)
	{
	m_fpKnots[j] = m_fpKnots[ubNum] + m_fpKnots[j-ubNum+degree] - m_fpKnots[m_iOrder-1];
	}
//ResetKnot();
m_fMinPara = m_fpKnots[m_iOrder-1];
m_fMaxPara = m_fpKnots[m_iKnots-m_iOrder+1];

//end
// Initialize the basis matrix A
float * tempN = new float[m_iOrder];
Ti_Matrix<double> A,xx,qq;
A.Create(ubNum-degree,ubNum-degree);
xx.Create(ubNum-degree,3);
qq.Create(ubNum-degree,3);

for(i=0;i<ubNum-degree;i++)
	{
	int span = FindSpan(ub[i]);
	Basisfuns(ub[i],span,tempN) ;
	for(j=span-degree;j<=span;j++) 
		A.m[i][j%(ubNum-degree)] = (double)tempN[j-span+degree] ;
	}

for(i=0;i<ubNum-degree;i++)
	{
	qq.m[i][0] = newDataPoints[i][0] ;
	qq.m[i][1] = newDataPoints[i][1] ;
	qq.m[i][2] = newDataPoints[i][2] ;
	}

if(!A.Invert(1e-12)) 
	{
	delete []ub;
	delete []tempN;
	return false;
	}
xx.Multiply(A,qq);

for(i=0;i<ubNum-degree;i++)
	{
	for(j=0;j<3;j++)
		{
		m_fCtrlPoints.m[i][j] = xx.m[i][j];
		}	
	m_fCtrlPoints.m[i][3] = 1.;
	}

for(i=ubNum-degree;i<ubNum;i++)
	{
	for(j=0;j<3;j++)
		{
		m_fCtrlPoints.m[i][j] = xx.m[i-ubNum+degree][j];
		}		
	m_fCtrlPoints.m[i][3]=1.;
	}
m_iCurveType = 1;
m_bSetValue = true;
ResetKnot();
delete []ub;
delete []tempN;
return true;

	}


bool XCurvObj::LeastSquaresFromCloud(XCloud  & cloud,int degree,int iCtrlCount)
	{
	/*const PNT * pPoint = cloud->GetPoint();
	if(pPoint==NULL) return false;*/
	int iNum = cloud.GetPntNum();
	if(iNum <= 0)	return false;

	CVArray Points;	
	Points.SetSize(iNum);	
	for(int i=0;i<iNum;i++)
		{
		cloud.GetPoint(i, Points[i] );		
		}
	return LeastSquares(Points,degree,iCtrlCount);	
	}

bool XCurvObj::LeastSquaresClosedFromCloud(XCloud & cloud,int degree,int iCtrlCount)
	{	
	int iNum = cloud.GetPntNum();
	if(iNum <= 0)	return false;

	CVArray Points;	
	Points.SetSize(iNum);	
	for(int i=0;i<iNum;i++)
		{
		cloud.GetPoint(i, Points[i] );		
		}
	return LeastSquaresClosed(Points,degree,iCtrlCount);	
	}



bool XCurvObj::CreateInterp(const CVArray & dataPoints, float * ub,int degree)
	{

	int i;	
	int ubNum = dataPoints.GetSize();
	if(ubNum<=1) 
		{
		m_bSetValue = false;
		return false;
		}

	if(degree > ubNum-1) degree = ubNum - 1;	

	m_iOrder = degree+1;
	m_iKnots = ubNum + m_iOrder;
	if(m_fpKnots!=NULL){
		delete 	[]m_fpKnots;
		}
m_fpKnots = new float[m_iKnots];
m_fCtrlPoints.Create(ubNum,4);

int j ;
for(j=1; j<ubNum-degree; j++){
	m_fpKnots[j+degree] = 0.0 ;
	for(int i=j;i<j+degree;++i)
		m_fpKnots[j+degree] += ub[i] ;
	m_fpKnots[j+degree] /= (float)degree ;
	}
for(j=0;j<=degree; j++)
m_fpKnots[j] = 0.0 ;
for(j=m_iKnots-degree-1;j<m_iKnots;j++)
m_fpKnots[j] = 1.0 ;

m_fMinPara = m_fpKnots[m_iOrder-1];
m_fMaxPara = m_fpKnots[m_iKnots-m_iOrder+1];
//end
// Initialize the basis matrix A
float * tempN = new float[m_iOrder];
Ti_Matrix<double> A,xx,qq;
A.Create(ubNum,ubNum);
xx.Create(ubNum,3);
qq.Create(ubNum,3);


for(i=1;i<ubNum-1;i++){
	int span = FindSpan(ub[i]);
	Basisfuns(ub[i],span,tempN) ;
	for(j=0;j<=m_iOrder-1;j++) 
		A.m[i][span-m_iOrder+1+j] = (double)tempN[j] ;
	}
A.m[0][0]  = 1.0 ;
A.m[ubNum-1][ubNum-1] = 1.0 ;


for(i=0;i<ubNum;i++){
	qq.m[i][0] = dataPoints[i][0] ;
	qq.m[i][1] = dataPoints[i][1] ;
	qq.m[i][2] = dataPoints[i][2] ;
	}

if(!A.Invert(1e-12)) 
	{
	delete []ub;
	delete []tempN;
	return false;
	}
xx.Multiply(A,qq);

for(i=0;i<ubNum;i++)
	{
	for(j=0;j<3;j++)
		m_fCtrlPoints.m[i][j]=xx.m[i][j];

	m_fCtrlPoints.m[i][3]=1.;
	}
m_iCurveType = 1;
m_bSetValue = true;
delete []tempN;
return true;
	}



bool XCurvObj::CreateInterpH(const Ti_Matrix<float> & dataPoints,float * ub,float * knots,int degree)
	{

	int i;
	int ubNum = dataPoints.RowCount();
	if(ubNum<=1) {
		m_bSetValue = false;
		return false;
		}

if(degree > ubNum-1) degree = ubNum - 1;

m_iOrder = degree+1;
m_iKnots = ubNum + m_iOrder;
if(m_fpKnots!=NULL){
	delete 	[]m_fpKnots;
	}
m_fpKnots = new float[m_iKnots];
m_fCtrlPoints.Create(ubNum,4);

int j ;
for(j=0; j<m_iKnots; j++){
	m_fpKnots[j] = knots[j] ;
	}

m_fMinPara = m_fpKnots[m_iOrder-1];
m_fMaxPara = m_fpKnots[m_iKnots-m_iOrder+1];
//end
// Initialize the basis matrix A
float * tempN = new float[m_iOrder];
Ti_Matrix<double> A,xx,qq;
A.Create(ubNum,ubNum);
xx.Create(ubNum,4);
qq.Create(ubNum,4);


for(i=1;i<ubNum-1;i++){
	int span = FindSpan(ub[i]);
	Basisfuns(ub[i],span,tempN) ;
	for(j=0;j<=m_iOrder-1;j++) 
		A.m[i][span-m_iOrder+1+j] = (double)tempN[j] ;
	}
A.m[0][0]  = 1.0 ;
A.m[ubNum-1][ubNum-1] = 1.0 ;


for(i=0;i<ubNum;i++){
	for(j=0;j<4;j++){
		qq.m[i][j] = dataPoints.m[i][j] ;		
		}
	}

if(!A.Invert(1e-12)) 
	{
	delete []ub;
	delete []tempN;
	return false;
	}
xx.Multiply(A,qq);

for(i=0;i<ubNum;i++){
	for(j=0;j<4;j++){
		m_fCtrlPoints.m[i][j]=xx.m[i][j];
		}

	}
m_iCurveType = 1;
m_bSetValue = true;
delete []tempN;
return true;
	}

/*********************************************************************
* ��������:XCurvObj::CurveReversal
* ˵��:���߷���
* ��ڲ���:
* void -- 
* ����ֵ:
* void -- 
* ����: liuhui 
* ʱ�� : 2003-07-22 15:06:40 
*********************************************************************/
void XCurvObj::CurveReversal()
	{
	int i,j;
	int m,p,n;//�ڵ��ţ����������Ƶ���
	m = m_iKnots - 1;
	p = m_iOrder - 1;
	n = m_iKnots - m_iOrder - 1;
	float* u;//�ݴ�ڵ�ʸ��
	u = new float[m_iKnots];
	for(i=0; i<m_iKnots; i++)
		{
		u[i] = m_fpKnots[i];
		}
	Ti_Matrix<float> tempoint;//�ݴ���Ƶ�
	tempoint = m_fCtrlPoints;
	delete []m_fpKnots;
	m_fpKnots = new float[m_iKnots];
	for(i=0; i<=m; i++)
		{
		m_fpKnots[m-i] = -u[i] + u[0] + u[m];
		}
	m_fCtrlPoints.Destroy();
	m_fCtrlPoints.Create(n+1, 4);
	for(i=0; i<=n; i++)//���ÿ��Ƶ�
		{
		for(j=0; j<4; j++)
			{
			m_fCtrlPoints.m[i][j] = tempoint.m[n-i][j];
			}
		}
	tempoint.Destroy();
	delete []u;
	}

/*********************************************************************
* ��������:XCurvObj::CurveKnotIns
* ˵��:���߲���ڵ㡣
* ��ڲ���:
* float u -- ������Ľڵ㣻
int r -- �ڵ����Ĵ�����
* ����ֵ:
* void -- 
* ����: liuhui 
* ʱ�� : 2003-07-24 11:33:19 
*********************************************************************/
void XCurvObj::CurveKnotIns(float u,int r)
	{
	int i,j,x,L;//ѭ������
	int np,p,k,s;//���Ƶ��ţ����ߴ������ڵ����λ�ñ�ţ��ڵ�ԭ���ظ���
	s = 0;//�ٶ�ԭ���ظ���Ϊ0
	float* UP;//�ݴ�ڵ�ʸ��
	Ti_Matrix<float> Pw;//�ݴ���Ƶ����
	Ti_Matrix<float> Rw;
	int nq;//����ڵ����Ƶ���
	int mp;//�ڵ���
	float alpha;
	float ERR; ERR = 0.001f;//��ʱ

	np = m_iKnots - m_iOrder - 1;
	p = m_iOrder - 1;
	UP = new float[m_iKnots];
	for(i=0; i<m_iKnots; i++)
		{
		UP[i] = m_fpKnots[i];
		}
	Pw = m_fCtrlPoints;
	mp = np + p + 1;
	nq = np + r;
	Rw.Create(p+1, 4);

	//���������λ�ñ�ż��ڵ�ԭ���ظ��� k & s
	for(i=m_iKnots-1; i>=0; i--)
		{
		if( (u-UP[i]) > -0.00001)//think about 0.00001
			break;
		}
	k = i;
	for(i=0; i<m_iKnots; i++)
		{
		if( fabs(u-UP[i]) < ERR/10.0 )
			s++;
		}
	if(r+s > p)
		{
		AfxMessageBox(TEXT("�ڵ��ظ��ȴ������ߴ������ڵ����ʧ�ܣ�"));
		Pw.Destroy();
		Rw.Destroy();
		delete []UP;
		return;
		}
	/*	CString str;
	str.Format("�����λ��k��%d\n�ڵ�ԭ���ظ���s��%d",k,s);
	AfxMessageBox(str);
	*/    
	//�����µĽڵ�ʸ��
	delete []m_fpKnots;
	m_iKnots = m_iKnots + r;
	m_fpKnots = new float[m_iKnots];
	for(i=0; i<=k; i++)
		{
		m_fpKnots[i] = UP[i];
		}
	for(i=1; i<=r; i++)
		{
		m_fpKnots[k+i] = u;
		}
	for(i=k+1; i<=mp; i++)
		{
		m_fpKnots[i+r] = UP[i];
		}

	//��������Ŀ��Ƶ�
	m_fCtrlPoints.Destroy();
	m_fCtrlPoints.Create(nq+1, 4);
	for(i=0; i<=k-p; i++)
		{
		for(x=0; x<4; x++)
			{
			m_fCtrlPoints.m[i][x] = Pw.m[i][x];
			}
		}
	for(i=k-s; i<=np; i++)
		{
		for(x=0; x<4; x++)
			{
			m_fCtrlPoints.m[i+r][x] = Pw.m[i][x];
			}
		}
	for(i=0; i<=p-s; i++)
		{
		for(x=0; x<4; x++)
			{
			Rw.m[i][x] = Pw.m[k-p+i][x];
			}
		}

	//����ڵ�r��
	for(j=1; j<=r; j++)
		{
		L = k-p+j;
		for(i=0; i<=p-j-s; i++)
			{
			alpha = (u-UP[L+i])/(UP[i+k+1]-UP[L+i]);
			for(x=0; x<4; x++)
				{
				Rw.m[i][x] = alpha*Rw.m[i+1][x] + (1.0-alpha)*Rw.m[i][x];
				}
			}
		for(x=0; x<4; x++)
			{
			m_fCtrlPoints.m[L][x] = Rw.m[0][x];
			m_fCtrlPoints.m[k+r-j-s][x] = Rw.m[p-j-s][x];
			}
		}

	//�������µĿ��Ƶ�
	for(i=L+1; i<k-s; i++)
		{
		for(x=0; x<4; x++)
			{
			m_fCtrlPoints.m[i][x] = Rw.m[i-L][x];
			}
		}
	Pw.Destroy();
	Rw.Destroy();
	delete []UP;
	}

/*********************************************************************
* ��������:XCurvObj::CurveKnotRefine
* ˵��:���߽ڵ��ض��塣
* ��ڲ���:
* float* X -- ������Ľڵ�ʸ����
int r -- �ڵ�ʸ����ĩβ��ţ�
* ����ֵ:
* void -- 
* ����: liuhui 
* ʱ�� : 2003-07-26 18:59:34 
*********************************************************************/
void XCurvObj::CurveKnotRefine(float* X, int r)
	{
	int i,j,k,l,x,ind;//ѭ������
	int a,b;
	int n,p,m,s;//n-ԭ�п��Ƶ�ĩβ��ţ�p-���ߴ�����m-�ڵ�ʸ��ĩβ��ţ�s-�ڵ�ԭ���ظ���
	float alpha;
	float* U;//�ݴ�ڵ�ʸ��
	Ti_Matrix<float> Pw;//�ݴ���Ƶ�
	float ERR; ERR = 0.001f;//��ʱ

	n = m_iKnots - m_iOrder - 1;
	p = m_iOrder - 1;
	U = new float[m_iKnots];
	for(i=0; i<m_iKnots; i++)
		{
		U[i] = m_fpKnots[i];
		}
	Pw = m_fCtrlPoints;
	m = n+p+1;

	//����a��b��ʹ��Ua<=Xi<Ub��
	for(i=m_iKnots-1; i>=0; i--)
		{
		if( (X[0]-U[i]) > -0.00001)//think about 0.00001
			break;
		}
	a = i;
	for(i=m_iKnots-1; i>=0; i--)
		{
		if( (X[r]-U[i]) > -0.00001)
			break;
		}
	b = i+1;
	for(i=0; i<=r; i++)
		{
		l = 0; //X�еĽڵ��ظ���
		s = 0; //U�еĽڵ��ظ���
		for(j=i; j<=r; j++)
			{
			if( fabs(X[j]-X[i]) < ERR/10.0 )
				l++;
			else
				break;
			}		
		for(k=0; k<m_iKnots; k++)
			{
			if( fabs(U[k]-X[i]) < ERR/10.0 )
				s++;
			}
		i = j;
		if(l+s > p)
			{
			AfxMessageBox(_T("�ڵ��ض�����ͼʹ�ڵ��ظ��ȴ������ߴ������ڵ��ض���ʧ�ܣ�"));
			Pw.Destroy();
			delete []U;
			return;
			}
		}

	//���벻��Ľڵ�ʸ���Ϳ��Ƶ�
	m_fCtrlPoints.Destroy();
	m_fCtrlPoints.Create(n+1+r+1, 4);
	for(j=0; j<=a-p; j++)
		{
		for(x=0; x<4; x++)
			{
			m_fCtrlPoints.m[j][x] = Pw.m[j][x];
			}
		}
	for(j=b-1; j<=n; j++)
		{
		for(x=0; x<4; x++)
			{
			m_fCtrlPoints.m[j+r+1][x] = Pw.m[j][x];
			}
		}
	delete []m_fpKnots;
	m_iKnots = m_iKnots + r + 1;
	m_fpKnots = new float[m_iKnots];
	for(j=0; j<=a; j++)
		{
		m_fpKnots[j] = U[j];
		}
	for(j=b+p; j<=m; j++)
		{
		m_fpKnots[j+r+1] = U[j];
		}
	i = b+p-1;
	k = b+p+r;

	//�������ڵ�
	for(j=r; j>=0; j--)
		{
		//		while(X[j] <= U[i] && i > a) //think about <=
		while( (X[j]-U[i])<0.00001 && i>a ) //think about 0.00001
			{
			for(x=0; x<4; x++)
				{
				m_fCtrlPoints.m[k-p-1][x] = Pw.m[i-p-1][x];
				}
			m_fpKnots[k] = U[i];
			k = k-1;
			i = i-1;
			}
		for(x=0; x<4; x++)
			{
			m_fCtrlPoints.m[k-p-1][x] = m_fCtrlPoints.m[k-p][x];
			}
		for(l=1; l<=p; l++)
			{
			ind = k-p+l;
			alpha = m_fpKnots[k+l] - X[j];
			if( fabs(fabs(alpha)-0.0) < 0.000001 )
				{
				for(x=0; x<4; x++)
					{
					m_fCtrlPoints.m[ind-1][x] = m_fCtrlPoints.m[ind][x];
					}
				}
			else
				{
				alpha = alpha/(m_fpKnots[k+l] - U[i-p+l]);
				for(x=0; x<4; x++)
					{
					m_fCtrlPoints.m[ind-1][x] = alpha*m_fCtrlPoints.m[ind-1][x] + (1.0-alpha)*m_fCtrlPoints.m[ind][x];
					}
				}
			}
		m_fpKnots[k] = X[j];
		k = k-1;
		}
	Pw.Destroy();
	delete []U;
	}

/*********************************************************************
* ��������:XCurvObj::CurveDecompose
* ˵��:���߷ֽ⣬�ֽ��Ŀ��Ƶ�洢��ԭ���Ŀ��Ƶ�����С�
* ��ڲ���:
* void --
* ����ֵ:
* void -- 
* ����: liuhui 
* ʱ�� : 2003-07-27 20:09:06 
*********************************************************************/
void XCurvObj::CurveDecompose()
	{
	int i,j,k,l,x;//ѭ������
	int n,p,m;//n-���Ƶ��ţ�p-���ߴ�����m-�ڵ�ʸ�����
	int a,b,mult,r,save,s;
	float numer,alpha;
	float* alphas;
	float* U;
	Ti_Matrix<float> Pw;
	int nb;//�ֽ���Bezier���߶���
	float ERR; ERR = 0.001f;//��ʱ

	n = m_iKnots - m_iOrder - 1;
	p = m_iOrder - 1;
	m = m_iKnots - 1;
	U = new float[m_iKnots];
	for(i=0; i<m_iKnots; i++)
		{
		U[i] = m_fpKnots[i];
		}
	Pw = m_fCtrlPoints;
	alphas = new float[p-1];

	//����ֽ���Bezier���߶���
	nb = 0;
	for(i=0; i<m; )
		{
		for(j=i; j<m; j++)
			{
			if( fabs(U[j]-U[i]) > ERR/10.0 )
				break;
			}
		if(j!=m)
			nb++;
		i = j;
		}

	//����ֽ��Ľڵ�ʸ��
	m_iKnots = (nb+1)*p + 2;
	delete []m_fpKnots;
	m_fpKnots = new float[m_iKnots];
	for(i=0; i<=p; i++)
		{
		m_fpKnots[i] = U[0];
		}
	for(i=0; i<=p; i++)
		{
		m_fpKnots[m_iKnots-1-i] = U[m];
		}
	k=0;
	for(i=1; i<nb; i++)
		{
		for(; k<m; )
			{
			for(l=k; l<m; l++)
				{
				if( fabs(U[l]-U[k]) > ERR/10.0 )
					break;
				}
			k = l;
			break;
			}
		for(j=0; j<p; j++)
			{
			m_fpKnots[1+i*p+j] = U[l];
			}
		}

	//Ϊ�ֽ��Ŀ��Ƶ�������ռ�
	m_fCtrlPoints.Destroy();
	m_fCtrlPoints.Create((p+1)*nb-(nb-1), 4);

	a = p;
	b = p+1;
	nb = 0;
	for(i=0; i<=p; i++)
		{
		for(x=0; x<4; x++)
			{
			m_fCtrlPoints.m[p*nb+i][x] = Pw.m[i][x];
			}
		}
	while(b < m)
		{
		i = b;
		while( b<m && fabs(U[b+1]-U[b])<ERR/10.0 )
			b++;
		mult = b-i+1;//�ڵ��ظ���
		if(mult < p)
			{
			numer = U[b] - U[a];//alpha�ķ���
			//���㲢�洢��ֵ
			for(j=p; j>mult; j--)
				{
				alphas[j-mult-1] = numer/(U[a+j]-U[a]);
				}
			r = p-mult;
			for(j=1; j<=r; j++)//����ڵ�r��
				{
				save = r-j;
				s = mult + j;
				for(k=p; k>=s; k--)
					{
					alpha = alphas[k-s];
					for(x=0; x<4; x++)
						{
						m_fCtrlPoints.m[p*nb+k][x] = alpha*m_fCtrlPoints.m[p*nb+k][x] + (1.0-alpha)*m_fCtrlPoints.m[p*nb+(k-1)][x];
						}
					}
				if(b < m)//��һ�εĿ��Ƶ�
					{
					for(x=0; x<4; x++)
						{
						m_fCtrlPoints.m[p*(nb+1)+save][x] = m_fCtrlPoints.m[p*nb+p][x];
						}
					}
				}//for r
			}//if mult<p
		nb = nb + 1;//�����һ��Bezier����
		if(b < m)//��һ�γ�ʼ��
			{
			for(i=p-mult; i<=p; i++)
				{
				for(x=0; x<4; x++)
					{
					m_fCtrlPoints.m[p*nb+i][x] = Pw.m[b-p+i][x];
					}
				}
			a = b;
			b = b+1;
			}
		}//while b<m
	Pw.Destroy();
	delete []U;
	delete []alphas;
	}

/*********************************************************************
* ��������:XCurvObj::CurveDegreeElevate
* ˵��:�������ס�
* ��ڲ���:
* int t -- �������״�����
* ����ֵ:
* void -- 
* ����: liuhui 
* ʱ�� : 2003-07-29 16:46:47 
*********************************************************************/
void XCurvObj::CurveDegreeElevate(int t)
	{
	int i,j,k,x;//ѭ������
	int n,p,m;//n-���Ƶ��ţ�p-���ߴ�����m-�ڵ�ʸ����š�
	float* U;//�ݴ�ڵ�ʸ��
	Ti_Matrix<float> Pw;//�ݴ���Ƶ�
	float ERR; ERR = 0.01f;
	n = m_iKnots - m_iOrder - 1;
	p = m_iOrder - 1;
	m = n+p+1;
	U = new float[m_iKnots];
	for(i=0; i<m_iKnots; i++)
		{
		U[i] = m_fpKnots[i];
		}
	Pw = m_fCtrlPoints;

	int ph,ph2,mpi,mh,kind,r,a,b,cind,nb,inter,mul,oldr,lbz,rbz,save,s,
		first,last,tr,kj;
	float inv,ua,ub,numer,den,bet,alpha,gam;
	Ti_Matrix<float> bezalfs;    bezalfs.Create(p+t+1, p+1);//�м����
	Ti_Matrix<float> bpts;    bpts.Create(p+1, 4);
	Ti_Matrix<float> ebpts;    ebpts.Create(p+t+1, 4);
	Ti_Matrix<float> Nextbpts;    Nextbpts.Create(p-1, 4);
	float* alphas;    alphas = new float[p-1];	
	m_iOrder = m_iOrder + t;//��������t�Σ�m_iOrder״̬�������ı�
	ph = p+t;//���׺�Ĵ���
	ph2 = ph/2;

	//����Bezier���߶�����ϵ����ϵ���ڸ������߶���ͨ�õġ�
	bezalfs.m[0][0] = bezalfs.m[ph][p] = 1.0f;
	for(i=1; i<=ph2; i++)
		{
		inv = 1.0f/(float)Bin(ph,i);
		mpi = Min2i(p,i);
		for(j=Max2i(0, i-t); j<=mpi; j++)
			bezalfs.m[i][j] = inv*(float)Bin(p,j)*(float)Bin(t,i-j);
		}
	for(i=ph2+1; i<=ph-1; i++)
		{
		mpi = Min2i(p,i);
		for(j=Max2i(0,i-t); j<=mpi; j++)
			bezalfs.m[i][j] = bezalfs.m[ph-i][p-j];
		}
	mh = ph;//�µĽڵ�ʸ�����
	kind = ph+1;
	r = -1;
	a = p;
	b = p+1;
	cind = 1;
	ua = U[0];

	//���Ƶ�ͽڵ�ʸ����ʼ��
	nb = 0; //���߷ֽ��Bezier����
	for(i=0; i<m; )
		{
		for(j=i; j<m; j++)
			{
			if( fabs(U[j]-U[i]) > ERR/10.0 )
				break;
			}
		if(j!=m)
			nb++;
		i = j;
		}
	inter = nb-1; //��ͬ���м�ڵ����
	m_iKnots = m_iKnots + t*(inter+2);//��������t�Σ�m_iKnots״̬�������ı�
	delete []m_fpKnots;
	m_fpKnots = new float[m_iKnots];
	for(i=0; i<=ph; i++)
		m_fpKnots[i] = ua;
	m_fCtrlPoints.Destroy();
	m_fCtrlPoints.Create(m_iKnots-m_iOrder, 4);
	for(x=0; x<4; x++)
		{
		m_fCtrlPoints.m[0][x] = Pw.m[0][x];
		}

	//��ʼ����1��Bezier���߶�
	for(i=0; i<=p; i++)
		{
		for(x=0; x<4; x++)
			{
			bpts.m[i][x] = Pw.m[i][x];
			}
		}
	while(b<m)//�Խڵ���������ѭ��
		{
		i = b;
		while(b<m && fabs(U[b+1]-U[b])<ERR/10.0 )
			b = b+1;
		mul = b-i+1;//�ڵ��ظ���
		mh = mh+mul+t;
		ub = U[b];
		oldr = r;
		r = p - mul;
		//����ڵ� u(b) r��
		if(oldr>0) 
			lbz = (oldr+2)/2;
		else
			lbz = 1;
		if(r>0)
			rbz = ph-(r+1)/2;
		else
			rbz = ph;
		if(r>0) //����ڵ������Bezier���߶�
			{
			numer = ub-ua;
			for(k=p; k>mul; k--)
				alphas[k-mul-1] = numer/(U[a+k]-ua);
			for(j=1; j<=r; j++)
				{
				save = r-j;
				s = mul+j;
				for(k=p; k>=s; k--)
					{
					for(x=0; x<4; x++)
						{
						bpts.m[k][x] = alphas[k-s]*bpts.m[k][x]+(1.0-alphas[k-s])*bpts.m[k-1][x];
						}
					}
				for(x=0; x<4; x++)
					{
					Nextbpts.m[save][x] = bpts.m[p][x];
					}
				}
			}//����ڵ����

		for(i=lbz; i<=ph; i++)  //Bezier��������
			{  //���� lbz,...,ph ���õ�
			for(x=0; x<4; x++)
				{
				ebpts.m[i][x] = 0.0f;
				}
			mpi = Min2i(p, i);
			for(j=Max2i(0,i-t); j<=mpi; j++)
				{
				for(x=0; x<4; x++)
					{
					ebpts.m[i][x] = ebpts.m[i][x] + bezalfs.m[i][j]*bpts.m[j][x];
					}
				}
			}//Bezier�������׽���

		if(oldr>1) //�Ƴ��ڵ� u=U[a] oldr��(think about)
			//		if(oldr>0) //why?
			{
			//			AfxMessageBox("��Ҫ�Ƴ��ڵ�");
			first = kind - 2;
			last = kind;
			den = ub - ua;
			bet = (ub-m_fpKnots[kind-1])/den;
			for(tr=1; tr<oldr; tr++)//�ڵ��Ƴ�ѭ��
				//			for(tr=1; tr<=oldr; tr++)
				{
				//				AfxMessageBox("�ڵ��Ƴ�ѭ��");
				i = first;
				j = last;
				kj = j-kind+1;
				while(j-i > tr)//ÿһ���Ƴ���ѭ�����Ҽ����µĿ��Ƶ�
					{
					if(i<cind)
						{
						alpha = (ub-m_fpKnots[i])/(ua-m_fpKnots[i]);
						for(x=0; x<4; x++)
							{
							m_fCtrlPoints.m[i][x] = alpha*m_fCtrlPoints.m[i][x] + (1.0-alpha)*m_fCtrlPoints.m[i-1][x];
							}
						}
					if(j>=lbz)
						{
						if(j-tr <= kind-ph+oldr)
							{
							gam = (ub-m_fpKnots[j-tr])/den;
							for(x=0; x<4; x++)
								{
								ebpts.m[kj][x] = gam*ebpts.m[kj][x] + (1.0-gam)*ebpts.m[kj+1][x];
								}
							}
						else
							{
							for(x=0; x<4; x++)
								{
								ebpts.m[kj][x] = bet*ebpts.m[kj][x] + (1.0-bet)*ebpts.m[kj+1][x];
								}
							}
						}//if j>=lbz
					i = i+1;
					j = j-1;
					kj = kj-1;
					}
				first = first-1;
				last = last+1;
				}//for tr �Ƴ��ڵ�ѭ��
			}//if oldr>1
		//�ڵ�u=U[a]�Ƴ�����

		//����ڵ�ua
		if(a != p)
			{
			for(i=0; i<ph-oldr; i++)
				{
				m_fpKnots[kind] = ua;
				kind = kind+1;
				}
			}

		//������Ƶ�
		for(j=lbz; j<=rbz; j++)
			{
			for(x=0; x<4; x++)
				{
				m_fCtrlPoints.m[cind][x] = ebpts.m[j][x];				
				}
			cind = cind+1;
			}

		//Ϊ��һ��ѭ����׼��
		if(b<m)
			{
			for(j=0; j<r; j++)
				{
				for(x=0; x<4; x++)
					{
					bpts.m[j][x] = Nextbpts.m[j][x];
					}
				}
			for(j=r; j<=p; j++)
				{
				for(x=0; x<4; x++)
					{
					bpts.m[j][x] = Pw.m[b-p+j][x];
					}
				}
			a = b;
			b = b+1;
			ua = ub;
			}
		else //�����ڵ�ѭ��,����ʣ��Ľڵ�
			{
			for(i=0; i<=ph; i++)
				{
				m_fpKnots[kind+i] = ub;
				}
			}
		}//while b<m,���������ڵ�ѭ��

	//����ռ�
	Pw.Destroy();
	bezalfs.Destroy();
	bpts.Destroy();
	ebpts.Destroy();
	Nextbpts.Destroy();
	delete []U;
	delete []alphas;
	}

/*********************************************************************
* ��������:XCurvObj::Bin
* ˵��:�����������Ķ���ʽϵ����
* ��ڲ���:
* int a��int b -- ����������
* ����ֵ:
* int -- ���������Ķ���ʽϵ����
* ����: liuhui 
* ʱ�� : 2003-07-29 17:38:52 
*********************************************************************/
int XCurvObj::Bin(int a, int b)
	{
	long int result;
	result = Factor(a)/( Factor(b)*Factor(a-b) );
	return (int)result;
	}

/*********************************************************************
* ��������:XCurvObj::Factor
* ˵��:�������Ľ׳ˡ�
* ��ڲ���:
* int a -- ������
* ����ֵ:
* long int -- �����Ľ׳ˡ�
* ����: liuhui 
* ʱ�� : 2003-07-29 17:43:11 
*********************************************************************/
long int XCurvObj::Factor(int a)
	{
	int i;
	long int result;
	result = 1;
	for(i=1; i<=a; i++)
		result = result*(long int)i;
	return result;
	}

/*********************************************************************
* ��������:XCurvObj::Min2i
* ˵��:��������������Сֵ��
* ��ڲ���:
* int a��int b -- ����������
* ����ֵ:
* int -- ������������Сֵ��
* ����: liuhui 
* ʱ�� : 2003-07-29 17:29:15 
*********************************************************************/
int XCurvObj::Min2i(int a,int b)
	{
	int result;
	result = (a<=b)?a:b;
	return result;
	}

/*********************************************************************
* ��������:XCurvObj::Max2i
* ˵��:���������������ֵ��
* ��ڲ���:
* int a��int b -- ����������
* ����ֵ:
* int -- �������������ֵ��
* ����: liuhui 
* ʱ�� : 2003-07-29 17:31:00 
*********************************************************************/
int XCurvObj::Max2i(int a, int b)
	{
	int result;
	result = (a>=b)?a:b;
	return result;
	}

/*********************************************************************
* ��������:XCurvObj::CurveDegreeReduce
* ˵��:���߽��ף���p�ν���p-1�Ρ�
* ��ڲ���:
* float TOL -- ���߽��׵�����ƫ����û����塣
* ����ֵ:
* int -- ����0��ʾ���׳ɹ�������1��ʾ����ʧ�ܡ�
* ����: liuhui 
* ʱ�� : 2003-07-31 9:24:57 
*********************************************************************/
int XCurvObj::CurveDegreeReduce(float TOL)
	{
	int i,j,k,x;//ѭ������
	int n,p,m,nh,ph,mh;//n�����Ƶ��ţ�p�����ߴ�����m���ڵ�ʸ�����
	//nh�����׺���Ƶ��ţ�ph�����ߴ�����mh���ڵ�ʸ�����
	float* U;//�ݴ�ڵ�ʸ��
	float* Uh;//�ݴ潵�׺�Ľڵ�ʸ��
	Ti_Matrix<float> Qw,Pw;//Qw������ǰ���Ƶ����Pw�����׺���Ƶ����
	float ERR; ERR=0.001f;
	n = m_iKnots - m_iOrder - 1;
	p = m_iOrder - 1;
	m = n + p + 1;
	ph = p - 1;//����1��
	U = new float[m_iKnots];
	for(i=0; i<m_iKnots; i++)
		{
		U[i] = m_fpKnots[i];
		}
	Qw = m_fCtrlPoints;//׼����������
	Ti_Matrix<float> bpts;//��ǰ��Bezier���߶εĿ��Ƶ�
	Ti_Matrix<float> Nextbpts;//��һ��Bezier���߶�����ߵĿ��Ƶ�
	Ti_Matrix<float> rbpts;//���׺��Bezier���߶εĿ��Ƶ�
	Ti_Matrix<float> PrL,PrR,A;
	float* alphas;//�ڵ��������еĦ�ֵ
	float* e;//ƫ������
	bpts.Create(p+1, 4);//����ǰBezier���߶ο��Ƶ����Ϊp+1��
	Nextbpts.Create(p-1, 4);
	rbpts.Create(p, 4);//���׺�Bezier���߶ο��Ƶ����Ϊp��
	PrL.Create(1, 4);
	PrR.Create(1, 4);
	A.Create(1, 4);
	alphas = new float[p-1];
	e = new float[m];//ÿһ���ڵ㷶Χ����һ���ۼӵ�ƫ��ֵ

	//��Bezier���׹����е�ϵ������������p����
	float* bezalfs;
	bezalfs = new float[p];
	for(i=0; i<p; i++)
		{
		bezalfs[i] = (float)i/(float)p;
		}

	//������ʼ��
	int kind,r,a,b,cind,mult,nb,inter,oldr,lbz,rb,//rb��Bezier���׹����к���Ҫ��һ������
		save,s,first,last,kj,K,q,L,ii;
	float numer,MaxErr,alfa,beta,delta,Br;
	mh = ph;
	kind = ph + 1;//�µĽڵ�ʸ�����
	r = -1;
	a = p;
	b = p + 1;
	cind = 1;//�µĿ��Ƶ���
	//	mult = p;
	rb = (p-1)/2;///////////

	//Ѱ�Ҳ�ͬ���м�ڵ�ĸ���
	nb = 0; //���߷ֽ��Bezier����
	for(i=0; i<m; )
		{
		for(j=i; j<m; j++)
			{
			if( fabs(U[j]-U[i]) > ERR/10.0 )
				break;
			}
		if(j!=m)
			nb++;
		i = j;
		}
	inter = nb-1; //��ͬ���м�ڵ����
	//�µĽڵ�ʸ���Ϳ��Ƶ�����ʼ��
	mh = m - inter - 2;
	Uh = new float[mh+1];
	nh = n - inter - 1;
	Pw.Create(nh+1, 4);
	mh = ph;
	for(x=0; x<4; x++)
		{
		Pw.m[0][x] = Qw.m[0][x];
		}
	for(i=0; i<=ph; i++)
		{
		Uh[i] = U[0];
		}

	//��ʼ����1��Bezier���߶�
	for(i=0; i<=p; i++)
		{
		for(x=0; x<4; x++)
			{
			bpts.m[i][x] = Qw.m[i][x];
			}
		}
	//��ʼ��ƫ������
	for(i=0; i<m; i++)
		{
		e[i] = 0.0f;
		}

	while(b < m)//�ڵ�ʸ��ѭ��
		{
		i = b;
		while(b<m && fabs(U[b+1]-U[b])<ERR/10.0 )
			b = b + 1;
		mult = b - i + 1;
		mh = mh + mult - 1;
		oldr = r;
		r = p - mult;
		if(oldr > 0)
			lbz = (oldr+2)/2;
		else
			lbz = 1;

		//����ڵ�r��
		if(r > 0)
			{
			numer = U[b] - U[a];
			//			for(k=p; k>=mult; k--) //notice the index range of an array
			for(k=p; k>mult; k--)
				{
				alphas[k-mult-1] = numer/(U[a+k]-U[a]);
				}
			for(j=1; j<=r; j++)
				{
				save = r - j;
				s = mult + j;
				for(k=p; k>=s; k--)
					{
					for(x=0; x<4; x++)
						{
						bpts.m[k][x] = alphas[k-s]*bpts.m[k][x]
					+(1.0-alphas[k-s])*bpts.m[k-1][x];
						}
					}
				for(x=0; x<4; x++)
					{
					Nextbpts.m[save][x] = bpts.m[p][x];
					}
				}
			}//ͨ���ڵ������һ��Bezier����

		//Bezier���߶ν��ף�ÿһ�ν��׵Ĺ�����һ���ģ���ͬ�Ľ����ǿ��Ƶ�
		if(p%2==0) //pΪż�������
			{
			for(x=0; x<4; x++)
				{
				rbpts.m[0][x] = bpts.m[0][x];
				rbpts.m[p-1][x] = bpts.m[p][x];
				for(i=1; i<=rb; i++)
					{
					rbpts.m[i][x] = (bpts.m[i][x]-bezalfs[i]*rbpts.m[i-1][x])/(1.0-bezalfs[i]);
					}
				for(i=p-2; i>=rb+1; i--)
					{
					rbpts.m[i][x] = (bpts.m[i+1][x]-(1.0-bezalfs[i+1])*rbpts.m[i+1][x])/(bezalfs[i+1]);
					}
				}
			MaxErr = sqrt((rbpts.m[rb+1][0]-(bpts.m[rb][0]+bpts.m[rb+1][0])/2.0f)*(rbpts.m[rb+1][0]-(bpts.m[rb][0]+bpts.m[rb+1][0])/2.0f)
				+(rbpts.m[rb+1][1]-(bpts.m[rb][1]+bpts.m[rb+1][1])/2.0f)*(rbpts.m[rb+1][1]-(bpts.m[rb][1]+bpts.m[rb+1][1])/2.0f)
				+(rbpts.m[rb+1][2]-(bpts.m[rb][2]+bpts.m[rb+1][2])/2.0f)*(rbpts.m[rb+1][2]-(bpts.m[rb][2]+bpts.m[rb+1][2])/2.0f)
				+(rbpts.m[rb+1][3]-(bpts.m[rb][3]+bpts.m[rb+1][3])/2.0f)*(rbpts.m[rb+1][3]-(bpts.m[rb][3]+bpts.m[rb+1][3])/2.0f));
			}
		else //pΪ���������
			{
			for(x=0; x<4; x++)
				{
				rbpts.m[0][x] = bpts.m[0][x];
				rbpts.m[p-1][x] = bpts.m[p][x];
				for(i=1; i<=rb-1; i++)
					{
					rbpts.m[i][x] = (bpts.m[i][x]-bezalfs[i]*rbpts.m[i-1][x])/(1.0-bezalfs[i]);
					}
				for(i=p-2; i>=rb+1; i--)
					{
					rbpts.m[i][x] = (bpts.m[i+1][x]-(1.0-bezalfs[i+1])*rbpts.m[i+1][x])/(bezalfs[i+1]);
					}
				PrL.m[0][x] = (bpts.m[rb][x]-bezalfs[rb]*rbpts.m[rb-1][x])/(1.0-bezalfs[rb]);
				PrR.m[0][x] = (bpts.m[rb+1][x]-(1.0-bezalfs[rb+1])*rbpts.m[rb+1][x])/(bezalfs[rb+1]);
				rbpts.m[rb][x] = (PrL.m[0][x]+PrR.m[0][x])/2.0f;
				}
			MaxErr = sqrt((PrL.m[0][0]-PrR.m[0][0])*(PrL.m[0][0]-PrR.m[0][0])
				+(PrL.m[0][1]-PrR.m[0][1])*(PrL.m[0][1]-PrR.m[0][1])
				+(PrL.m[0][2]-PrR.m[0][2])*(PrL.m[0][2]-PrR.m[0][2])
				+(PrL.m[0][3]-PrR.m[0][3])*(PrL.m[0][3]-PrR.m[0][3]));
			}
		e[a] = e[a] + MaxErr;
		if(e[a] > TOL)//���߲��ܱ�����
			{
			Qw.Destroy();
			Pw.Destroy();
			bpts.Destroy();
			Nextbpts.Destroy();
			rbpts.Destroy();
			PrL.Destroy();
			PrR.Destroy();
			A.Destroy();
			delete []U;
			delete []Uh;
			delete []alphas;
			delete []e;
			delete []bezalfs;
			return 1;
			}

		//�Ƴ�����Ľڵ�(think about!)
		if(oldr > 0)
			{
			first = kind;
			last = kind;
			for(k=0; k<oldr; k++)
				{
				i = first;
				j = last;
				kj = j - kind;
				while(j-i > k)
					{
					alfa = (U[a]-Uh[i-1])/(U[b]-Uh[i-1]);
					beta = (U[a]-Uh[j-k-1])/(U[b]-Uh[j-k-1]);
					for(x=0; x<4; x++)
						{
						Pw.m[i-1][x] = (Pw.m[i-1][x]-(1.0-alfa)*Pw.m[i-2][x])/alfa;
						rbpts.m[kj][x] = (rbpts.m[kj][x]-beta*rbpts.m[kj+1][x])/(1.0-beta);
						}
					i = i + 1;
					j = j - 1;
					kj = kj - 1;
					}
				//����ڵ��Ƴ���������ƫ��
				if(j-i < k)
					Br = sqrt((Pw.m[i-2][0]-rbpts.m[kj+1][0])*(Pw.m[i-2][0]-rbpts.m[kj+1][0])
					+(Pw.m[i-2][1]-rbpts.m[kj+1][1])*(Pw.m[i-2][1]-rbpts.m[kj+1][1])
					+(Pw.m[i-2][2]-rbpts.m[kj+1][2])*(Pw.m[i-2][2]-rbpts.m[kj+1][2])
					+(Pw.m[i-2][3]-rbpts.m[kj+1][3])*(Pw.m[i-2][3]-rbpts.m[kj+1][3]));
				else
					{
					delta = (U[a]-Uh[i-1])/(U[b]-Uh[i-1]);
					for(x=0; x<4; x++)
						{
						A.m[0][x] = delta*rbpts.m[kj+1][x]+(1.0-delta)*Pw.m[i-2][x];
						}
					Br = sqrt((Pw.m[i-1][0]-A.m[0][0])*(Pw.m[i-1][0]-A.m[0][0])
						+(Pw.m[i-1][1]-A.m[0][1])*(Pw.m[i-1][1]-A.m[0][1])
						+(Pw.m[i-1][2]-A.m[0][2])*(Pw.m[i-1][2]-A.m[0][2])
						+(Pw.m[i-1][3]-A.m[0][3])*(Pw.m[i-1][3]-A.m[0][3]));
					}
				//����ƫ������
				K = a + oldr - k;
				q = (2*p-k+1)/2;
				L = K - q;
				for(ii=L; ii<=a; ii++)//These knot spans were affected 
					{
					e[ii] = e[ii] + Br;
					if(e[ii] > TOL)//���߲��ܱ�����
						{
						Qw.Destroy();
						Pw.Destroy();
						bpts.Destroy();
						Nextbpts.Destroy();
						rbpts.Destroy();
						PrL.Destroy();
						PrR.Destroy();
						A.Destroy();
						delete []U;
						delete []Uh;
						delete []alphas;
						delete []e;
						delete []bezalfs;
						return 1;
						}
					}
				first = first - 1;
				last = last + 1;
				}//for k=0; k<oldr; k++
			cind = i - 1;
			}//if(oldr > 0)

		//�����µĽڵ�ʸ���Ϳ��Ƶ�
		if(a!=p)
			for(i=0; i<ph-oldr; i++)
				{
				Uh[kind] = U[a];
				kind = kind + 1;
				}
			for(i=lbz; i<=ph; i++)
				{
				for(x=0; x<4; x++)
					{
					Pw.m[cind][x] = rbpts.m[i][x];
					}
				cind = cind + 1;
				}

			//Ϊ��һѭ����׼��
			if(b<m)
				{
				for(x=0; x<4; x++)
					{
					for(i=0; i<r; i++)
						{
						bpts.m[i][x] = Nextbpts.m[i][x];
						}
					for(i=r; i<=p; i++)
						{
						bpts.m[i][x] = Qw.m[b-p+i][x];
						}
					}
				a = b;
				b = b+1;
				}
			else
				{
				for(i=0; i<=ph; i++)
					Uh[kind+i] = U[b];
				}
		}//while b<m

	//�ı�ԭ�нڵ�ʸ���Ϳ��Ƶ����
	delete []m_fpKnots;
	m_iKnots = mh + 1;
	m_fpKnots = new float[m_iKnots];
	for(i=0; i<m_iKnots; i++)
		{
		m_fpKnots[i] = Uh[i];
		}
	m_fCtrlPoints.Destroy();
	m_fCtrlPoints.Create(nh+1, 4);
	for(i=0; i<nh+1; i++)
		{
		for(x=0; x<4; x++)
			{
			m_fCtrlPoints.m[i][x] = Pw.m[i][x];
			}
		}
	m_iOrder = ph + 1;

	Qw.Destroy();
	Pw.Destroy();
	bpts.Destroy();
	Nextbpts.Destroy();
	rbpts.Destroy();
	PrL.Destroy();
	PrR.Destroy();
	A.Destroy();
	delete []U;
	delete []Uh;
	delete []alphas;
	delete []e;
	delete []bezalfs;
	return 0;
	}