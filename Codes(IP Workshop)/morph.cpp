#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<iostream>
using namespace std;
using namespace cv;
Mat img1= imread("lenna.jpg",1);
Mat img2= imread("rubik.jpg",1);
Mat img(img1.rows,img1.cols,CV_8UC3,Scalar(0,0,0));
int x=0;
void abc(int a, void*q)
{
	int i,j;
	for(i=0;i<img1.rows;i++)
	{
		for(j=0;j<img2.cols;j++)
		img.at<Vec3b>(i,j)[0]=(x*img1.at<Vec3b>(i,j)[0]+(100-x)*img2.at<Vec3b>(i,j)[0])/100;
		img.at<Vec3b>(i,j)[1]=(x*img1.at<Vec3b>(i,j)[1]+(100-x)*img2.at<Vec3b>(i,j)[1])/100;
		img.at<Vec3b>(i,j)[2]=(x*img1.at<Vec3b>(i,j)[2]+(100-x)*img2.at<Vec3b>(i,j)[2])/100;
	}
imshow("Morph",img);
}
int main()
{
namedWindow("Morph",WINDOW_NORMAL);
createTrackbar("x","Morph",&x,100,abc,NULL);
waitKey(0);
return 0;
}
