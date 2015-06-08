/////////////////////////////////////////////////////////////////////////////////////////
//			file name : Ti_Rotation.h   
//
//			File Description : 
//				Rotation operation
//			created by Xiaoming Du 10/27/2004
//
//			Modification Record:	
//////////////////////////////////////////////////////////////////////////////////////////
#pragma once
#include "math_algorithm.h"
#include "pnt.h"
const  float  DELTA_ROT = 0.000001f;
class  MATH_ALGORITHM_API Ti_Rotation
	{
  	///////////////////////////////////////////////////////////////////////
	//            data 
	////////////////////////////////////////////////////////////////////////
	public:
		PNT		 m_Axis ;	// Unit Vector  
		double	 m_Angle;	// 0 - 360 degree

  	///////////////////////////////////////////////////////////////////////
	//            construction  / destruction 
	////////////////////////////////////////////////////////////////////////
	public:	
		Ti_Rotation(
			const float& fX=0.0f,
			const  float& fY=0.0f, 
			const float&  fZ=1.0f, 
			const double& fAngle=0.0f);

		Ti_Rotation(const PNT& Axis, const double& fAngle=0.0f);
		Ti_Rotation	operator *(const  Ti_Rotation& R2)const;
		PNT  VectorTransform(const PNT& V)const;
		void Convert2RPY(double &zangle, double &yangle, double &xangle);// rhe return angle represent in radian
		/*Get rotation from two vectors , that means v1 will align to v2 after rotation*/
		void RotationFromVecs(const PNT& V1, const PNT& V2);
		void  RotationToMatrix(double  M[4][4]);
		void  MatrixToRotation(double  M[4][4]);
	};


class  QUATERNION
{
public:
  	///////////////////////////////////////////////////////////////////////
	//            data 
	////////////////////////////////////////////////////////////////////////
	double x, y, z, w;

	QUATERNION(double fX, double fY, double fZ, double fW=0.0f)
	{ x=fX; y=fY; z=fZ; w=fW; }
	QUATERNION(void)
	{
	 x = 0; y = 0; z = 1; w = 0;
	}
	~QUATERNION(void)
	{
	}

// ��Ԫ����ģ������ֵ = |A|
  double QuaternionMagnitude();

// ��Ԫ���һ��
// ��� |A|=0�����ֵ = A�����ֵ = A/(|A|)
  void  QuaternionNormalize();

// ��Ԫ������
// ��� |A|=0�����ֵ = A���������ֵ = A ����
  void  QuaternionInverse(QUATERNION  &A);

// ��Ԫ�鹲�����ֵ = A �Ĺ���
  void  QuaternionConjugate(QUATERNION &A);

// ��Ԫ����ӣ�����ֵ = A + B
  QUATERNION operator +   (const QUATERNION& B);

// ��Ԫ�����������ֵ = A - B
  QUATERNION operator -   (const QUATERNION& B);

// ��Ԫ�����ţ�����ֵ = s * A 
  QUATERNION operator *  ( const double& s);

// ��Ԫ����ˣ�����ֵ = A * B

  QUATERNION operator *  ( const QUATERNION& B);  

// Spherical Linear Interpolation Between two Quaternions, 0 < t < 1
  QUATERNION QuaternionSlerp(const QUATERNION& from, const QUATERNION& to,const  double& t);

/*_____________________________________________________
 |                                                     
 |   Ϊ��߼������ܣ����±任�������ٶ�
 |
 |   ������� R Q V �Ѿ������� Normalize ����    
 |_____________________________________________________*/


/*------------------------------------------------------------------*/
/*----------------------  QUATERNION �� Ti_Rotation  ------------------*/

// �� Ti_Rotation �ṹ��ʾ�� QUATERNION
  friend QUATERNION RotationToQuaternion(const Ti_Rotation& R);

// �� QUATERNION �ṹ��ʾ�� Ti_Rotation
  Ti_Rotation   QuaternionToRotation();

/*------------------------------------------------------------------*/
/*----------------------  QUATERNION �� Matrix  --------------------*/

// �� QUATERNION �ṹ��ʾ�� Matrix
  void QuaternionToMatrix(double M[4][4]);

// �� Matrix �ṹ��ʾ�� QUATERNION
// Ҫ�� Matrix ��һ����ת����,�����ܵõ���ȷ���
  void MatrixToQuaternion( double M[4][4]);

/*------------------------------------------------------------------*/
/*-----------------------  QUATERNION �� VECTOR  -------------------*/


// ��ʸ��������ά�ռ��һ�㣩��ʾ����Ԫ��
  QUATERNION VectorToQuaternion(const PNT& V);

// ����Ԫ����鲿��ʸ����ʾ
  PNT     QuaternionToVector();

// V ���� Q �任��Ϊ V', �������� V'
  PNT VectorTransform(const PNT& V);
};