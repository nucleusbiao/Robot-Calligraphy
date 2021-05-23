#include <iostream>  
#include <opencv2/opencv.hpp>  
#include <opencv2/highgui/highgui.hpp>  
#include<math.h>
#include <opencv2\imgproc\types_c.h>
#include <opencv2/highgui/highgui_c.h>

using namespace std;
using namespace cv;
Mat lena;


//±éÑ°ÏñËØµã
void minimumdistance(int pointx, int pointy, int* min_length)
{


	int absx = 0, absy = 0;
    int l;
	int minl = 10000;

	for (int y = 0; y < lena.rows; y++)
	{
		for (int x = 0; x < lena.cols; x++)
		{
			uchar *data = lena.ptr<uchar>(y);
			int b = data[3 * x];
			//cout << "blue_pixel = " << b << endl;
			int g = data[3 * x + 1];
			//cout << "green_pixel = " << g << endl;
			int r = data[3 * x + 2];
			//cout << "red_pixel = " << r << endl;

			if (b == 255 && g == 255 && r == 255)
			{
				absx = abs(x - pointx);
				absy = abs(y - pointy);
				l = sqrt(pow(absx, 2) + pow(absy, 2));

				if (l <= minl)
				{
					minl = l;
				}
			}



		}

	}
	
	*min_length = minl;

  }













//»­·½¿ò
/*

void minimumdistance(int pointx, int pointy, int* min_length)
{


	int absx = 0, absy = 0;
	int l;
	int minl = 10000;
	int pointx1,pointx2,pointy1,pointy2;
	pointx1=pointx-60;
	pointx2=pointx+60;
    pointy1=pointy-60;
	pointy2=pointy+60;
	for (int y = pointy1); y < pointy2; y++)
	{
		for (int x = pointx1; x < pointx2; x++)
		{
			uchar *data = lena.ptr<uchar>(y);
			int b = data[3 * x];
			//cout << "blue_pixel = " << b << endl;
			int g = data[3 * x + 1];
			//cout << "green_pixel = " << g << endl;
			int r = data[3 * x + 2];
			//cout << "red_pixel = " << r << endl;

			if (b == 255 && g == 255 && r == 255)
			{
				absx = abs(x - pointx);
				absy = abs(y - pointy);
				l = sqrt(pow(absx, 2) + pow(absy, 2));

				if (l <= minl)
				{
					minl = l;
				}
			}



		}

	}

	*min_length = minl;

  }

*/

//¼«×ø±ê

  /*
  void minimumdistance(int pointx, int pointy, int* min_length)
  {
	  int i;
	  int n;
	  int x, y,l,minl,absx,absy;

	  for (i = 1; i <= 100; i++)
	  {
		  for (n = 0; n <= 360; n++)
		  {
			  x = pointx + i * cos(n);
			  y = pointy + i * sin(n);
			  uchar *data = lena.ptr<uchar>(y);
			  int b = data[3 * x];
			  //cout << "blue_pixel = " << b << endl;
			  int g = data[3 * x + 1];
			  //cout << "green_pixel = " << g << endl;
			  int r = data[3 * x + 2];
			  //cout << "red_pixel = " << r << endl;
			  if (b == 255 && g == 255 && r == 255)
			  {
				  absx = abs(x - pointx);
				  absy = abs(y - pointy);
				  l = sqrt(pow(absx, 2) + pow(absy, 2));

				  if (l <= minl)
				  {
					  minl = l;
				  }
			  }
		  }
	  }
	  *min_length = minl;
  }
  */