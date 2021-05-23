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
#include "coordinate.h"
#include"pixel.h"
#include"frame.h"
#include"drawline.h"
#include"compare2.h"

using namespace cv;
using namespace std;


int main()
{
	//进行判断的变量
	int a;
	int b;
	int c;
	int d;

	//Mat类并规定图像尺寸
	src = imread("D:\\TEST\\NEWTEST\\maobi\\maobi\\picture1.png", IMREAD_COLOR);
	Size srcSize = Size(1024, 1024);  //填入任意指定尺寸
	resize(src, src, srcSize, 0, 0, INTER_LINEAR);


	lena = imread("D:\\TEST\\NEWTEST\\maobi\\maobi\\picture1.png", IMREAD_COLOR);
	Size lenaSize = Size(1024, 1024);  //填入任意指定尺寸
	resize(lena, lena, lenaSize, 0, 0, INTER_LINEAR);



	img = imread("D:\\TEST\\NEWTEST\\maobi\\maobi\\picture1.png", IMREAD_COLOR);
	Size imgSize = Size(1024, 1024);  //填入任意指定尺寸
	resize(img, img, imgSize, 0, 0, INTER_LINEAR);


	filling = imread("img/picture2.png", COLOR_BGR2GRAY);
	Size fillingSize = Size(1024, 1024);  //填入任意指定尺寸
	resize(filling, filling, fillingSize, 0, 0, INTER_LINEAR);




	//通过点击获取坐标
	cout << "是否需要进行点的坐标获取" << endl;
	cout << "1表示是，2表示否" << endl;
	cin >> a;
	if (a == 1) {
		//创建可视化窗口
		namedWindow("point");
		setMouseCallback("point", on_mouse, 0);//关键内置函数
		resizeWindow("point", 1024, 1024); //改变窗口大小
		imshow("point", src);
		waitKey(0);
		destroyWindow("point");

	}


	//计算离目标点最近的目标像素的距离
	cout << "是否需要进行离目标点最近像素的计算" << endl;
	cout << "1表示是，2表示否" << endl;
	cin >> b;
	if (b == 1)
	{

		int pointx, pointy;
		int minimum;
		cout << "请输入坐标点" << endl;
		cout << "输入点的坐标存在-1时跳出计算循环" << endl;
		while (cin >> pointx >> pointy)
		{
			if (pointx != -1 && pointy != -1)
			{

				minimumdistance(pointx, pointy, &minimum);
				cout << "minl= " << minimum << endl;
				//尝试对毛笔的Z轴坐标分级
				/*
				if (minimum <= 5)
				{
					cout << "毛笔在此处Z轴的相对坐标为0mm" << endl;

				}
				else if (minimum >0 && minimum <= 10)
				{
					cout << "毛笔在此处Z轴的相对坐标为2mm" << endl;
				}
				else if (minimum > 10 && minimum <= 20)
				{
					cout << "毛笔在此处Z轴的相对坐标为4mm" << endl;
				}
				else if (minimum > 20 && minimum <= 25)
				{
					cout << "毛笔在此处Z轴的相对坐标为6mm" << endl;
				}
				else if (minimum > 25 && minimum <= 30)
				{
					cout << "毛笔在此处Z轴的相对坐标为8mm" << endl;
				}
				else if (minimum > 30)
				{
					cout << "毛笔在此处Z轴的相对坐标为1cm" << endl;
				}
				*/

				//创建表示点坐标的变量
				cv::Point point;//特征点，用以画在图像中  
				point.x = pointx;//特征点在图像中横坐标  
				point.y = pointy;//特征点在图像中纵坐标  
				cv::circle(lena, point, minimum, cv::Scalar(255, 0, 0), 2);//在图像中画出特征点，minimum是圆的半径 

				namedWindow("印痕提取图", 0);//创建窗口
				resizeWindow("印痕提取图", 1024, 1024); //改变窗口大小
				imshow("印痕提取图", lena);
				waitKey(2000);
				destroyWindow("印痕提取图");
			}
			if (pointx == -1 || pointy == -1)
			{
				break;
			}

		}


	}
	/*
	imshow("印痕提取图", lena);
	waitKey(5000);
	destroyWindow("印痕提取图");
   */

	cout << "是否通过输入点进行绘图" << endl;
	cout << "如果进行输入1不进行则输入2" << endl;
	cin >> c;
	if (c == 1)
	{
		int pointx1, pointy1, minimum1, pointx0, pointy0, minimum0, x1, y1, x0, y0;
		int i = 0;
		getframe();
		cout << "请输入点的坐标" << endl;
		cout << "之后输入坐标存在-1时停止绘画,输入（1,1）时用于坐标切换" << endl;
		/*
		//通过画线的方式对书写效果进行模拟
			while (cin >> pointx1 >> pointy1)
			{
				if (pointx1 != -1 && pointy1 != -1)
				{
					if (i == 0)
					{
						minimumdistance(pointx1, pointy1, &minimum1);
						pointx0 = pointx1;
						pointy0 = pointy1;
						minimum0 = minimum1;

						i++;
					}
					if (i!=0)
					{
						minimumdistance(pointx1, pointy1, &minimum1);
						line(pointx0, pointy0, pointx1, pointy1, minimum0, minimum1);

						pointx0 = pointx1;
						pointy0 = pointy1;
						minimum0 = minimum1;
						cout << "请输入下一点的坐标" << endl;
					}
				}
				else
				{
					break;
				}
			}

	}

	*/


	//通过画点的方式进行效果模拟
		int s = 0;
		while (cin >> x1 >> y1)
		{
			if (x1 == 1 && y1 == 1)
			{
				cout << "请重新输入新笔划起点坐标" << endl;
				cin >> x0 >> y0;
				cout << "请输入新笔划的第二点坐标" << endl;
				cin >> x1 >> y1;
			}
			if (x1 != -1 && y1 != -1)
			{
				if (s == 0)
				{
					x0 = x1;
					y0 = y1;
					s++;
					cout << "请输入下一点的坐标" << endl;
					cin >> x1 >> y1;
				}
				if (s != 0)
				{
					int minimum2, minimum3;
					int x[16];
					int y[16];
					//在两个点中再划分若干个点，例程为总共16个点
					for (int i = 0; i <= 15; i++)
					{
						x[i] = x0 + ((abs(x1 - x0)) / 15)*i;
						y[i] = y0 + ((abs(y1 - y0)) / 15)*i;
						minimumdistance(x[i], y[i], &minimum2);
						minimum3 = minimum2;
						cv::Point point;//特征点，用以画在图像中  
						point.x = x[i];//特征点在图像中横坐标  
						point.y = y[i];//特征点在图像中纵坐标  
						cv::circle(filling, point, minimum3, cv::Scalar(255, 0, 0), -1);//在图像中画出特征点，minimum是圆的半径
					}
					imwrite("D:\\TEST\\NEWTEST\\maobi\\maobi\\img\\picture3.png", filling);
					namedWindow("效果显示图", 0);//创建窗口
					resizeWindow("效果显示图", 1024, 1024); //改变窗口大小
					imshow("效果显示图", filling);

					waitKey(1500);
					destroyWindow("效果显示图");
					x0 = x1;
					y0 = y1;
					cout << "请输入下一点的坐标" << endl;
				}
				
				}
			

			else {
				break;
			}

			}
		
		}
     //将通过输入点得到的效果图与经过处理后的原图进行相似度对比

	 cout << "是否进行图像相似度比较" << endl;
	 cout << "输入1进行比较输入2不进行" << endl;
		cin >> d;
		if (d == 1)
		{
			Mat change0 = imread("D:\\TEST\\NEWTEST\\maobi\\maobi\\picture1.png");
			Size change0Size = Size(1024, 1024);  //填入任意指定尺寸
			resize(change0, change0, change0Size, 0, 0, INTER_LINEAR);
			Mat graychange;
			Mat graychangeThresh;
			//将原图转化为灰度图
			cvtColor(change0, graychange, CV_BGR2GRAY);
			//对图像各个像素格的灰度值进行二值化
			threshold(graychange, graychangeThresh, 230, 255, CV_THRESH_BINARY_INV);

			//假如图像本身为黑底白字则需要运行以下命令
			//bitwise_not(graychangeThresh, change1);

			imwrite("D:\\TEST\\NEWTEST\\maobi\\maobi\\img\\picture4.png", graychangeThresh);//写到img目录下

			Mat orgImg = imread("D:\\TEST\\NEWTEST\\maobi\\maobi\\img\\picture4.png");

			Mat drawimg = imread("D:\\TEST\\NEWTEST\\maobi\\maobi\\img\\picture3.png");

			aHash(drawimg, orgImg);
		}

		waitKey(6000);
		return  0;

	}
