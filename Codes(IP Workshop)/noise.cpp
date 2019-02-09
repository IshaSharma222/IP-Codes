//DILUTION->EROSION (CLOSING)
#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<iostream>
using namespace std;
using namespace cv;
Mat img= imread("j.png",0);
Mat img1(img.rows,img.cols,CV_8UC1,Scalar(0));
int isvalid(int i, int j)
{
if(i!=0  && i!= img.rows-1 && j!=0 && j!=img.cols-1)
return 1;
else return 0;
}
int maxm(int a[9])
{
int max1=a[0];
int i;
for(i=0;i<9;++i)
{
	if(max1<a[i])
	max1=a[i];}
return max1;
}
int minm(int a[9])
{
int min1=a[0];
int i;
for(i=0;i<9;++i)
{ 
	if(min1>a[i])
	min1=a[i];
return min1;
}
}
int main()
{
int i,j;
int arr[9];
for(i=0;i<img.rows;++i)
{
	for(j=0;j<img.cols;++j)
	{
	int b = isvalid(i,j);
	if(b==1)
	{
	arr[0]=img.at<uchar>(i,j);
	arr[1]=img.at<uchar>(i-1,j);
	arr[2]=img.at<uchar>(i-1,j-1);
	arr[3]=img.at<uchar>(i,j-1);
	arr[4]=img.at<uchar>(i+1,j);
	arr[5]=img.at<uchar>(i,j+1);
	arr[6]=img.at<uchar>(i+1,j+1);
	arr[7]=img.at<uchar>(i-1,j+1);
	arr[8]=img.at<uchar>(i+1,j-1);	
	img1.at<uchar>(i,j)=maxm(arr);
	}
}}
for(i=0;i<img.rows;++i)
{
	for(j=0;j<img.cols;++j)
	{
	int b = isvalid(i,j);
	if(b==1)
	{
	arr[0]=img1.at<uchar>(i,j);
	arr[1]=img1.at<uchar>(i-1,j);
	arr[2]=img1.at<uchar>(i-1,j-1);
	arr[3]=img1.at<uchar>(i,j-1);
	arr[4]=img1.at<uchar>(i+1,j);
	arr[5]=img1.at<uchar>(i,j+1);
	arr[6]=img1.at<uchar>(i+1,j+1);
	arr[7]=img1.at<uchar>(i-1,j+1);
	arr[8]=img1.at<uchar>(i+1,j-1);	
	img1.at<uchar>(i,j)=minm(arr);
	}
}}
namedWindow("A",WINDOW_NORMAL);
imwrite("Noise(Closing).jpg",img1);
imshow("A",img1);
waitKey(0);
return 0;
}

