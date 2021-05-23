#include <iostream>  
#include <opencv2/opencv.hpp>  
#include <opencv2/highgui/highgui.hpp>  
#include<math.h>
#include <opencv2\imgproc\types_c.h>
#include <opencv2/highgui/highgui_c.h>

using namespace std;
using namespace cv;

Mat img ;

void getframe() {

	
	
	//图像骨架化提取
	Mat DstPic, edge, grayImage;

	//创建与src同类型和同大小的矩阵
	DstPic.create(img.size(), img.type());

	//将原始图转化为灰度图
	cvtColor(img, grayImage, COLOR_BGR2GRAY);

	//先使用3*3内核来降噪
	blur(grayImage, edge, Size(3, 3));

	//运行canny算子
	Canny(edge, edge, 3, 9, 3);

	namedWindow("Canny算法轮廓提取效果", 0);//创建窗口
	resizeWindow("Canny算法轮廓提取效果", 1024, 1024); //改变窗口大小
	imshow("Canny算法轮廓提取效果", edge);
	waitKey(2000);
	destroyWindow("Canny算法轮廓提取效果");
	//写入一张新图片到img路径下
	imwrite("D:\\TEST\\NEWTEST\\maobi\\maobi\\img\\picture2.png", edge);//写到img目录下

}
