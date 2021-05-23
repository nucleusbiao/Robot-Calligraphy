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


Mat src; 

// down 变量用于判断按键是否按下
bool down = false;
Point prept = Point(-1, -1);
Point curpt = Point(-1, -1);
void on_mouse(int event, int x, int y, int flags, void* ustc)
{

	if (event == CV_EVENT_LBUTTONDOWN)    //按键按下
	{
		prept = Point(x, y);
		cout << x << " " << y << endl;

		down = true;
	}
	else if (event == CV_EVENT_LBUTTONUP)     //按键放开
		down = false;
	//右键按下且鼠标移动并划一条线以验证整体轨迹是一条直线
	//if (down == true && event == CV_EVENT_MOUSEMOVE)
	//line(src, prept, curpt, Scalar(255, 0, 0), 5);

	if (down == true )    //右键按下且鼠标移动
	{
		curpt = cvPoint(x, y);
		cv::Point point;//特征点，用以画在图像中 
		//特征点坐标
		point.x = x;
		point.y = y;
		//鼠标按下画一个半径为5个像素格长度的实心白点
		cv::circle(src, point, 5, cv::Scalar(255, 255, 255), -1);
		waitKey(3);        //可以解决画图时卡顿的问题
		imshow("point", src);
		prept = curpt;
	}


}

