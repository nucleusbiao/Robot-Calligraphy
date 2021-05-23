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

	
	
	//ͼ��Ǽܻ���ȡ
	Mat DstPic, edge, grayImage;

	//������srcͬ���ͺ�ͬ��С�ľ���
	DstPic.create(img.size(), img.type());

	//��ԭʼͼת��Ϊ�Ҷ�ͼ
	cvtColor(img, grayImage, COLOR_BGR2GRAY);

	//��ʹ��3*3�ں�������
	blur(grayImage, edge, Size(3, 3));

	//����canny����
	Canny(edge, edge, 3, 9, 3);

	namedWindow("Canny�㷨������ȡЧ��", 0);//��������
	resizeWindow("Canny�㷨������ȡЧ��", 1024, 1024); //�ı䴰�ڴ�С
	imshow("Canny�㷨������ȡЧ��", edge);
	waitKey(2000);
	destroyWindow("Canny�㷨������ȡЧ��");
	//д��һ����ͼƬ��img·����
	imwrite("D:\\TEST\\NEWTEST\\maobi\\maobi\\img\\picture2.png", edge);//д��imgĿ¼��

}
