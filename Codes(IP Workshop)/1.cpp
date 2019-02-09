#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<iostream>
using namespace std;
using namespace cv;
int main()
{
	int i,j;
	Mat img(50,50,CV_8UC3, Scalar(0,0,0));
	for(i=0;i<50;i++)
	{
		for(j=0;j<50;j++)
		{
			if(i<=j) img.at<Vec3b>(i,j)[2]=255;
			if(i>j) img.at<Vec3b>(i,j)= {0,255,255};
		}
	}
	namedWindow("win",WINDOW_NORMAL);
	imshow("win",img);
	waitKey(0);
	return 0;
}
