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
	Mat img1(img.rows/2,img.cols/2,CV_8UC3,Scalar(0,0,0));
	for(i=0;i<img.rows/2;++i)
	{
		for(j=0;j<img.cols*2;++j)
		{
		img1.at<Vec3b>(i,j)[0]=img.at<Vec3b>(i*2,j*2)[0];
		img1.at<Vec3b>(i,j)[1]=img.at<Vec3b>(i*2,j*2)[1];
		img1.at<Vec3b>(i,j)[2]=img.at<Vec3b>(i*2,j*2)[2];
		}
	}
	namedWindow("Changed",WINDOW_AUTOSIZE);
	namedWindow("Original",WINDOW_AUTOSIZE);
	imshow("Changed",img1);
	imshow("Original",img);
	waitKey(0);
	return 0;
}
