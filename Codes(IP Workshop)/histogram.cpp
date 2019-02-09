#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<iostream>
using namespace std;
using namespace cv;
int main()
{
Mat img=imread("lowcontrast.PNG",0);

int i,j,k;
int arr[256];
for(i=0;i<256;i++) arr[i]=0;
for(i=0;i<img.rows;i++)
{
	for(j=0;j<img.cols;j++)
	{
		for(k=0;k<256;k++)
		{		
		if((img.at<uchar>(i,j))==k) arr[k]++;
		}
	}
}
int max=arr[0];
for(i=0;i<256;++i)
{if(max<arr[i]) max=arr[i];}
Mat img1(max*10+100,256*50,CV_8UC1,Scalar(0));

for(j=0;j<256;j++)
{
	for(k=j*50;k<j*50+50;k++)
	{	
		for(i=0;i<arr[j]*10;i++)
		{
		img1.at<uchar>(img1.rows-i-1,k)=255;
		}
	}
}
namedWindow("a",WINDOW_NORMAL);
imshow("a",img1);
imwrite("histogram4.jpg",img1);
waitKey(0);
return 0;	
}
