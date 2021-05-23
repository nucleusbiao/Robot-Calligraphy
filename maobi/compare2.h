#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <opencv2\imgproc\types_c.h>
#include <opencv2/highgui/highgui_c.h>
#include <fstream>
#include <string>
#include <vector>


using namespace cv;
using namespace std;







void aHash(Mat matSrc1, Mat matSrc2)
{   //重新设定两个Mat类变量读取的图像规格
	Mat matDst1, matDst2;
	cv::resize(matSrc1, matDst1, cv::Size(8, 8), 0, 0, cv::INTER_CUBIC);
	cv::resize(matSrc2, matDst2, cv::Size(8, 8), 0, 0, cv::INTER_CUBIC);

	//转换图像格式
	cv::cvtColor(matDst1, matDst1, CV_BGR2GRAY);
	cv::cvtColor(matDst2, matDst2, CV_BGR2GRAY);

	int iAvg1 = 0, iAvg2 = 0;
	int arr1[64], arr2[64];

	for (int i = 0; i < 8; i++)
	{
		//用两个指针指向读取到的色彩信息
		uchar* data1 = matDst1.ptr<uchar>(i);
		uchar* data2 = matDst2.ptr<uchar>(i);

		int tmp = i * 8;

		for (int j = 0; j < 8; j++)
		{
			int tmp1 = tmp + j;

			arr1[tmp1] = data1[j] / 4 * 4;
			arr2[tmp1] = data2[j] / 4 * 4;

			iAvg1 += arr1[tmp1];
			iAvg2 += arr2[tmp1];
		}
	}

	//读取灰度平均值
	iAvg1 /= 64;
	iAvg2 /= 64;

	for (int i = 0; i < 64; i++)
	{
		arr1[i] = (arr1[i] >= iAvg1) ? 1 : 0;
		arr2[i] = (arr2[i] >= iAvg2) ? 1 : 0;
	}

	int iDiffNum = 0;

	for (int i = 0; i < 64; i++)
	{
		if (arr1[i] != arr2[i])
			++iDiffNum;
	}
	//return iDiffNum;
	cout << iDiffNum<<endl;
}
