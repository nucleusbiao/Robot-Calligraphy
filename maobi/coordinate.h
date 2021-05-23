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

// down ���������жϰ����Ƿ���
bool down = false;
Point prept = Point(-1, -1);
Point curpt = Point(-1, -1);
void on_mouse(int event, int x, int y, int flags, void* ustc)
{

	if (event == CV_EVENT_LBUTTONDOWN)    //��������
	{
		prept = Point(x, y);
		cout << x << " " << y << endl;

		down = true;
	}
	else if (event == CV_EVENT_LBUTTONUP)     //�����ſ�
		down = false;
	//�Ҽ�����������ƶ�����һ��������֤����켣��һ��ֱ��
	//if (down == true && event == CV_EVENT_MOUSEMOVE)
	//line(src, prept, curpt, Scalar(255, 0, 0), 5);

	if (down == true )    //�Ҽ�����������ƶ�
	{
		curpt = cvPoint(x, y);
		cv::Point point;//�����㣬���Ի���ͼ���� 
		//����������
		point.x = x;
		point.y = y;
		//��갴�»�һ���뾶Ϊ5�����ظ񳤶ȵ�ʵ�İ׵�
		cv::circle(src, point, 5, cv::Scalar(255, 255, 255), -1);
		waitKey(3);        //���Խ����ͼʱ���ٵ�����
		imshow("point", src);
		prept = curpt;
	}


}

