#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<iostream>
using namespace std;
using namespace cv;

void abc(int,void*);
Mat img= imread("lenna.jpg",1);
Mat img1(img.rows,img.cols,CV_8UC1,Scalar(0));
int main()
{int i,j;
int a=0;

for(i=0;i<img.rows;++i)
{
	for(j=0;j<img.cols;++j)
	{
		img1.at<uchar>(i,j)=(0.07*(img.at<Vec3b>(i,j)[0])+(0.72*img.at<Vec3b>(i,j)[1])+(0.21*img.at<Vec3b>(i,j)[2]));
	}
}
namedWindow("A",WINDOW_NORMAL);
createTrackbar("xyz","A",&a,255,abc,NULL);

waitKey(0);
return 0;
}
void abc(int low, void*q)
{int i,j;
	for(i=0;i<img.rows;++i)
	{
		for(j=0;j<img.cols;++j)		
		{
		if(img.at<Vec3b>(i,j)[2]>low)
		 img1.at<uchar>(i,j)=255;
		else img1.at<uchar>(i,j)=0;
		}
	}
imshow("A",img1);
}

