#include <iostream>
#include <opencv2/opencv.hpp>  
#include <opencv2/highgui/highgui.hpp>  
#include<math.h>
#include <opencv2\imgproc\types_c.h>
#include <opencv2/highgui/highgui_c.h>
using namespace std;
using namespace cv;

Mat filling ;

void line(int x1, int y1,int x2, int y2,int radius1,int radius2)
{
	int radius;
	cv::Point start = cv::Point(x1, y1); //ֱ�����
	cv::Point end = cv::Point(x2, y2);   //ֱ���յ�
	radius = radius1 + radius2;
	cv::line(filling, start, end, cv::Scalar(255, 255, 255), radius);
	namedWindow("ֱ�߻滭Ч��ͼ", 0);//��������
	resizeWindow("ֱ�߻滭Ч��ͼ", 1024, 1024); //�ı䴰�ڴ�С
	imshow("ֱ�߻滭Ч��ͼ", filling);
	waitKey(2000);
	destroyWindow("ֱ�߻滭Ч��ͼ");

	//д��һ����ͼƬ��img·����
	imwrite("D:\\TEST\\NEWTEST\\maobi\\maobi\\img\\picture3.png", filling);//д��imgĿ¼��

}