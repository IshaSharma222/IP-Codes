#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<iostream>
using namespace std;
using namespace cv;
int main()
{
	int i,j;
	Mat img(50,50,CV_8UC1, Scalar(0));
	for(i=0;i<50;i++)
	{
		for(j=0;j<50;j++)
		{
			if((i+j)%2==0) img.at<uchar>(i,j)=0;
			else img.at<uchar>(i,j)=255;
		}
	}
	namedWindow("win",WINDOW_NORMAL);
	imshow("win",img);
	waitKey(0);
	return 0;
}
