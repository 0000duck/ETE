#pragma once
#include "stdafx.h"
#include "ETESystemPublicDefine.h"
#include <windows.h>
#include <opencv.hpp>

using namespace cv;
static Mat toGrayscale(InputArray _src) {
	Mat src = _src.getMat();
	// only allow one channel
	if(src.channels() != 1) {
		CV_Error(CV_StsBadArg, "Only Matrices with one channel are supported");
	}
	// create and return normalized image
	Mat dst;
	cv::normalize(_src, dst, 0, 255, NORM_MINMAX, CV_8UC1);
	return dst;
}

static Mat generateMat(const Mat& mat, int left)
{
	Mat GrayScale = toGrayscale(mat);
	Mat m = Mat::zeros(VIEW_HEIGHT, VIEW_WIDTH, CV_8UC1);
	for (int r = 0; r <  VIEW_HEIGHT; r++)
	{
		for (int c = 0; c < mat.cols; c++)
		{
			m.ptr(r)[c+left] = GrayScale.ptr(r)[c];
		}
	}
	return m;
}

static void BitMatToWnd(CWnd* pWnd, cv::Mat img, CRect *Roi)
{
	if(img.empty()) 
		return;

	CRect drect; 
	drect.CopyRect(Roi);

	CClientDC dc(pWnd); 
	HDC hDC =dc.GetSafeHdc();

	//�ڴ��е�ͼ�����ݿ�������Ļ�� 
	BYTE *bitBuffer = NULL; 
	BITMAPINFO *bitMapinfo = NULL;

	int ichannels =img.channels(); 
	if( ichannels == 1) 
	{ 
		bitBuffer = new BYTE[40+4*256]; 
	} 
	else if( ichannels == 3) 
	{ 
		bitBuffer = new BYTE[sizeof(BITMAPINFO)]; 
	} 
	else 
	{ 
		return; 
	}


	if(bitBuffer == NULL) 
	{ 
		return; 
	}


	bitMapinfo = (BITMAPINFO *)bitBuffer; 
	bitMapinfo->bmiHeader.biSize = sizeof(BITMAPINFOHEADER); 
	bitMapinfo->bmiHeader.biHeight = -img.rows; //����߶�Ϊ���ģ�λͼ����ʼλ�������½ǡ�����߶�Ϊ������ʼλ�������Ͻǡ� 
	bitMapinfo->bmiHeader.biWidth = img.cols; 
	bitMapinfo->bmiHeader.biPlanes = 1; // Ŀ���豸�ļ��𣬱���Ϊ1 
	bitMapinfo->bmiHeader.biBitCount = ichannels *8; // ÿ�����������λ����������1(˫ɫ), 4(16ɫ)��8(256ɫ)��24(���ɫ)֮һ 
	bitMapinfo->bmiHeader.biCompression = BI_RGB; //λͼѹ�����ͣ������� 0(��ѹ��), 1(BI_RLE8ѹ������)��2(BI_RLE4ѹ������)֮һ 
	bitMapinfo->bmiHeader.biSizeImage = 0; // λͼ�Ĵ�С�����ֽ�Ϊ��λ 
	bitMapinfo->bmiHeader.biXPelsPerMeter = 0; // λͼˮƽ�ֱ��ʣ�ÿ�������� 
	bitMapinfo->bmiHeader.biYPelsPerMeter = 0; // λͼ��ֱ�ֱ��ʣ�ÿ�������� 
	bitMapinfo->bmiHeader.biClrUsed = 0; // λͼʵ��ʹ�õ���ɫ���е���ɫ�� 
	bitMapinfo->bmiHeader.biClrImportant = 0; // λͼ��ʾ��������Ҫ����ɫ��

	if(ichannels == 1) 
	{ 
		for(int i=0; i<256; i++) 
		{ //��ɫ��ȡֵ��Χ (0-255) 
			bitMapinfo->bmiColors[i].rgbBlue =bitMapinfo->bmiColors[i].rgbGreen =bitMapinfo->bmiColors[i].rgbRed =(BYTE) i; 
		}

		bitMapinfo->bmiHeader.biClrUsed = 256; // λͼʵ��ʹ�õ���ɫ���е���ɫ�� 
	} 
	SetStretchBltMode(hDC, COLORONCOLOR);


	StretchDIBits(hDC, 
		drect.left, 
		0, 
		drect.right, //��ʾ���ڿ�� 
		drect.bottom, //��ʾ���ڸ߶� 
		0, 
		0, 
		img.cols, //ͼ���� 
		img.rows, //ͼ��߶� 
		img.data, 
		bitMapinfo, 
		DIB_RGB_COLORS, 
		SRCCOPY 
		);

	delete []bitBuffer;
}
