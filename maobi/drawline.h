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
	cv::Point start = cv::Point(x1, y1); //直线起点
	cv::Point end = cv::Point(x2, y2);   //直线终点
	radius = radius1 + radius2;
	cv::line(filling, start, end, cv::Scalar(255, 255, 255), radius);
	namedWindow("直线绘画效果图", 0);//创建窗口
	resizeWindow("直线绘画效果图", 1024, 1024); //改变窗口大小
	imshow("直线绘画效果图", filling);
	waitKey(2000);
	destroyWindow("直线绘画效果图");

	//写入一张新图片到img路径下
	imwrite("D:\\TEST\\NEWTEST\\maobi\\maobi\\img\\picture3.png", filling);//写到img目录下

}