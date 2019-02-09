#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<iostream>

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


for(i=0;i<img.rows;++i)
{
	for(j=0;j<img.cols;++j)
	{ int a = isvalid(i,j);
	if(a==1)
	img1.at<uchar>(i,j)=(img.at<uchar>(i,j)+ img.at<uchar>(i-1,j)+ img.at<uchar>(i-1,j-1) +img.at<uchar>(i,j-1)+img.at<uchar>(i+1,j) + img.at<uchar>(i,j+1)+ img.at<uchar>(i+1,j+1)+img.at<uchar>(i-1,j+1)+img.at<uchar>(i+1,j-1))/9;
	}
}
namedWindow("A",WINDOW_NORMAL);
imshow("A",img1);
waitKey(0);
return 0;
}
