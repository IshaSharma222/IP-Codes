#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<iostream>
#include<math.h>
using namespace std;
using namespace cv;

Mat img=imread("rubik.jpg",0);

int isvalid(int i, int j)
{
if(i!=0  && i!= img.rows-1 && j!=0 && j!=img.cols-1)
return 1;
else return 0;
}

void abc(int low,void *q)
{Mat img1(img.rows,img.cols,CV_8UC1,Scalar(0));
int i,j,k,a,gx, gy;
double c;
for(i=0;i<img.rows;++i)
{
	for(j=0;j<img.cols;++j)
	{ int a = isvalid(i,j);
	{if(a==1)
	gx=(0*img.at<uchar>(i,j))+ (0*img.at<uchar>(i-1,j))+ (-1*img.at<uchar>(i-1,j-1)) +(-1*img.at<uchar>(i,j-1))+(0*img.at<uchar>(i+1,j)) + (1*img.at<uchar>(i,j+1))+ (1*img.at<uchar>(i+1,j+1))+(1*img.at<uchar>(i-1,j+1))+(-1*img.at<uchar>(i+1,j-1));
	gy=(0*img.at<uchar>(i,j))+ (1*img.at<uchar>(i-1,j))+ (1*img.at<uchar>(i-1,j-1)) +(0*img.at<uchar>(i,j-1))+(-1*img.at<uchar>(i+1,j)) + (0*img.at<uchar>(i,j+1))+ (-1*img.at<uchar>(i+1,j+1))+(1*img.at<uchar>(i-1,j+1))+(-1*img.at<uchar>(i+1,j-1));
	c=sqrt((gx*gx)+(gy*gy));
	if(c>low)
	img1.at<uchar>(i,j)=255;
	}
}}

imshow("Edge",img1);}
int main()
{int b=0;
namedWindow("Edge",WINDOW_NORMAL);
createTrackbar("T","Edge",&b,255,abc,NULL);
waitKey(0);
return 0;
}
