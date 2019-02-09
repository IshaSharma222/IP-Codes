#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<iostream>
using namespace std;
using namespace cv;
int ma(int,int,int);
int mi(int,int,int);
int main()
{
int i,j;
Mat img= imread("lenna.jpg",1);
Mat img1(img.rows,img.cols,CV_8UC1,Scalar(0));
for(i=0;i<img.rows;++i)
{
	for(j=0;j<img.cols;++j)
	{
		img1.at<uchar>(i,j)=(   ma( img.at<Vec3b>(i,j)[0],img.at<Vec3b>(i,j)[1],img.at<Vec3b>(i,j)[2] )  +  mi( img.at<Vec3b>(i,j)[0],img.at<Vec3b>(i,j)[1],img.at<Vec3b>(i,j)[2] ) )/2;
	}
}
namedWindow("A",WINDOW_NORMAL);
imshow("A",img1);
waitKey(0);
return 0;
}
int ma(int a, int b, int c)
{
	int max1;
	if((a>=b)&&(a>=c))
	max1=a;
	else if((b>=a)&&(b>=c))
	max1=b;
	else //if((c>=a)&&(c>=b))
	max1=c;
	return max1;
}
int mi(int a, int b, int c)
{
	int min1;
	if((a<=b)&&(a<=c))
	min1=a;
	else if((b<=a)&&(b<=c))
	min1=b;
	else// if((c<=a)&&(c<=b))
	min1=c;
	return min1;
}
	
