#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/core/core.hpp>
#include<iostream>
using namespace std;
using namespace cv;
int main()
{
	int i,j;
	Mat img=imread("lenna.jpg",1);
	Mat swap(img.rows,img.cols,CV_8UC3,Scalar(0,0,0));
	for(i=0;i<img.rows;i++)
	{
		for(j=0;j<img.cols;j++)
		{
		swap.at<Vec3b>(i,j)=img.at<Vec3b>(i,img.cols-j-1);
		}
	}
	namedWindow("A",WINDOW_NORMAL);
	imshow("A",swap);
	namedWindow("B",WINDOW_NORMAL);
	imshow("B",img);
	waitKey(0);
	return 0;
}
