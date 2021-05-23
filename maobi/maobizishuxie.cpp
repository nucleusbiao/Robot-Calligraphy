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
	//�����жϵı���
	int a;
	int b;
	int c;
	int d;

	//Mat�ಢ�涨ͼ��ߴ�
	src = imread("D:\\TEST\\NEWTEST\\maobi\\maobi\\picture1.png", IMREAD_COLOR);
	Size srcSize = Size(1024, 1024);  //��������ָ���ߴ�
	resize(src, src, srcSize, 0, 0, INTER_LINEAR);


	lena = imread("D:\\TEST\\NEWTEST\\maobi\\maobi\\picture1.png", IMREAD_COLOR);
	Size lenaSize = Size(1024, 1024);  //��������ָ���ߴ�
	resize(lena, lena, lenaSize, 0, 0, INTER_LINEAR);



	img = imread("D:\\TEST\\NEWTEST\\maobi\\maobi\\picture1.png", IMREAD_COLOR);
	Size imgSize = Size(1024, 1024);  //��������ָ���ߴ�
	resize(img, img, imgSize, 0, 0, INTER_LINEAR);


	filling = imread("img/picture2.png", COLOR_BGR2GRAY);
	Size fillingSize = Size(1024, 1024);  //��������ָ���ߴ�
	resize(filling, filling, fillingSize, 0, 0, INTER_LINEAR);




	//ͨ�������ȡ����
	cout << "�Ƿ���Ҫ���е�������ȡ" << endl;
	cout << "1��ʾ�ǣ�2��ʾ��" << endl;
	cin >> a;
	if (a == 1) {
		//�������ӻ�����
		namedWindow("point");
		setMouseCallback("point", on_mouse, 0);//�ؼ����ú���
		resizeWindow("point", 1024, 1024); //�ı䴰�ڴ�С
		imshow("point", src);
		waitKey(0);
		destroyWindow("point");

	}


	//������Ŀ��������Ŀ�����صľ���
	cout << "�Ƿ���Ҫ������Ŀ���������صļ���" << endl;
	cout << "1��ʾ�ǣ�2��ʾ��" << endl;
	cin >> b;
	if (b == 1)
	{

		int pointx, pointy;
		int minimum;
		cout << "�����������" << endl;
		cout << "�������������-1ʱ��������ѭ��" << endl;
		while (cin >> pointx >> pointy)
		{
			if (pointx != -1 && pointy != -1)
			{

				minimumdistance(pointx, pointy, &minimum);
				cout << "minl= " << minimum << endl;
				//���Զ�ë�ʵ�Z������ּ�
				/*
				if (minimum <= 5)
				{
					cout << "ë���ڴ˴�Z����������Ϊ0mm" << endl;

				}
				else if (minimum >0 && minimum <= 10)
				{
					cout << "ë���ڴ˴�Z����������Ϊ2mm" << endl;
				}
				else if (minimum > 10 && minimum <= 20)
				{
					cout << "ë���ڴ˴�Z����������Ϊ4mm" << endl;
				}
				else if (minimum > 20 && minimum <= 25)
				{
					cout << "ë���ڴ˴�Z����������Ϊ6mm" << endl;
				}
				else if (minimum > 25 && minimum <= 30)
				{
					cout << "ë���ڴ˴�Z����������Ϊ8mm" << endl;
				}
				else if (minimum > 30)
				{
					cout << "ë���ڴ˴�Z����������Ϊ1cm" << endl;
				}
				*/

				//������ʾ������ı���
				cv::Point point;//�����㣬���Ի���ͼ����  
				point.x = pointx;//��������ͼ���к�����  
				point.y = pointy;//��������ͼ����������  
				cv::circle(lena, point, minimum, cv::Scalar(255, 0, 0), 2);//��ͼ���л��������㣬minimum��Բ�İ뾶 

				namedWindow("ӡ����ȡͼ", 0);//��������
				resizeWindow("ӡ����ȡͼ", 1024, 1024); //�ı䴰�ڴ�С
				imshow("ӡ����ȡͼ", lena);
				waitKey(2000);
				destroyWindow("ӡ����ȡͼ");
			}
			if (pointx == -1 || pointy == -1)
			{
				break;
			}

		}


	}
	/*
	imshow("ӡ����ȡͼ", lena);
	waitKey(5000);
	destroyWindow("ӡ����ȡͼ");
   */

	cout << "�Ƿ�ͨ���������л�ͼ" << endl;
	cout << "�����������1������������2" << endl;
	cin >> c;
	if (c == 1)
	{
		int pointx1, pointy1, minimum1, pointx0, pointy0, minimum0, x1, y1, x0, y0;
		int i = 0;
		getframe();
		cout << "������������" << endl;
		cout << "֮�������������-1ʱֹͣ�滭,���루1,1��ʱ���������л�" << endl;
		/*
		//ͨ�����ߵķ�ʽ����дЧ������ģ��
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
						cout << "��������һ�������" << endl;
					}
				}
				else
				{
					break;
				}
			}

	}

	*/


	//ͨ������ķ�ʽ����Ч��ģ��
		int s = 0;
		while (cin >> x1 >> y1)
		{
			if (x1 == 1 && y1 == 1)
			{
				cout << "�����������±ʻ��������" << endl;
				cin >> x0 >> y0;
				cout << "�������±ʻ��ĵڶ�������" << endl;
				cin >> x1 >> y1;
			}
			if (x1 != -1 && y1 != -1)
			{
				if (s == 0)
				{
					x0 = x1;
					y0 = y1;
					s++;
					cout << "��������һ�������" << endl;
					cin >> x1 >> y1;
				}
				if (s != 0)
				{
					int minimum2, minimum3;
					int x[16];
					int y[16];
					//�����������ٻ������ɸ��㣬����Ϊ�ܹ�16����
					for (int i = 0; i <= 15; i++)
					{
						x[i] = x0 + ((abs(x1 - x0)) / 15)*i;
						y[i] = y0 + ((abs(y1 - y0)) / 15)*i;
						minimumdistance(x[i], y[i], &minimum2);
						minimum3 = minimum2;
						cv::Point point;//�����㣬���Ի���ͼ����  
						point.x = x[i];//��������ͼ���к�����  
						point.y = y[i];//��������ͼ����������  
						cv::circle(filling, point, minimum3, cv::Scalar(255, 0, 0), -1);//��ͼ���л��������㣬minimum��Բ�İ뾶
					}
					imwrite("D:\\TEST\\NEWTEST\\maobi\\maobi\\img\\picture3.png", filling);
					namedWindow("Ч����ʾͼ", 0);//��������
					resizeWindow("Ч����ʾͼ", 1024, 1024); //�ı䴰�ڴ�С
					imshow("Ч����ʾͼ", filling);

					waitKey(1500);
					destroyWindow("Ч����ʾͼ");
					x0 = x1;
					y0 = y1;
					cout << "��������һ�������" << endl;
				}
				
				}
			

			else {
				break;
			}

			}
		
		}
     //��ͨ�������õ���Ч��ͼ�뾭��������ԭͼ�������ƶȶԱ�

	 cout << "�Ƿ����ͼ�����ƶȱȽ�" << endl;
	 cout << "����1���бȽ�����2������" << endl;
		cin >> d;
		if (d == 1)
		{
			Mat change0 = imread("D:\\TEST\\NEWTEST\\maobi\\maobi\\picture1.png");
			Size change0Size = Size(1024, 1024);  //��������ָ���ߴ�
			resize(change0, change0, change0Size, 0, 0, INTER_LINEAR);
			Mat graychange;
			Mat graychangeThresh;
			//��ԭͼת��Ϊ�Ҷ�ͼ
			cvtColor(change0, graychange, CV_BGR2GRAY);
			//��ͼ��������ظ�ĻҶ�ֵ���ж�ֵ��
			threshold(graychange, graychangeThresh, 230, 255, CV_THRESH_BINARY_INV);

			//����ͼ����Ϊ�ڵװ�������Ҫ������������
			//bitwise_not(graychangeThresh, change1);

			imwrite("D:\\TEST\\NEWTEST\\maobi\\maobi\\img\\picture4.png", graychangeThresh);//д��imgĿ¼��

			Mat orgImg = imread("D:\\TEST\\NEWTEST\\maobi\\maobi\\img\\picture4.png");

			Mat drawimg = imread("D:\\TEST\\NEWTEST\\maobi\\maobi\\img\\picture3.png");

			aHash(drawimg, orgImg);
		}

		waitKey(6000);
		return  0;

	}
