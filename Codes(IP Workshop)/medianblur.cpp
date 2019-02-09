#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
using namespace cv;
Mat img= imread("index.jpg",0);
Mat img1(img.rows,img.cols,CV_8UC1,Scalar(0));
int isvalid(int i, int j)
{
if(i!=0  && i!= img.rows-1 && j!=0 && j!=img.cols-1)
return 1;
else return 0;
}

int main()
{int i,j,k,Sum=0;
int arr[9];

for(i=0;i<img.rows;++i)
{
	for(j=0;j<img.cols;++j)
	{ int a = isvalid(i,j);
	if(a==1)
	{arr[0]=img.at<uchar>(i,j);
	arr[1]=img.at<uchar>(i-1,j);
	arr[2]=img.at<uchar>(i-1,j-1);
	arr[3]=img.at<uchar>(i,j-1);
	arr[4]=img.at<uchar>(i+1,j);
	arr[5]=img.at<uchar>(i,j+1);
	arr[6]=img.at<uchar>(i+1,j+1);
	arr[7]=img.at<uchar>(i-1,j+1);
	arr[8]=img.at<uchar>(i+1,j-1);
	int n = sizeof(arr)/sizeof(arr[0]);
	sort(arr,arr + n);
	img1.at<uchar>(i,j)=arr[4];
	}}
}
namedWindow("Median Blur",WINDOW_NORMAL);
imshow("A",img1);
waitKey(0);
return 0;
}
