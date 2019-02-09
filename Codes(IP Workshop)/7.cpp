#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<iostream>
using namespace std;
using namespace cv;
int main()
{
int i,j,a;
Mat img=imread("lenna.jpg",1);
Mat img1(img.rows,img.cols,CV_8UC3,Scalar(0,0,0));
cout<<"Enter angle(in degrees)\n";
cin>>a;
for(i=0;i<img.rows/2;++i)
{
	for(j=0;j<img.cols/2;++j)
	{
	img1.at<Vec3b>(((img.rows/2)-i),((img.cols/2)-j))[0]=img.at<Vec3b>(i*cos(a)-j*sin(a),i*sin(a)+j*cos(a))[0];
	img1.at<Vec3b>(((img.rows/2)-i),((img.cols/2)-j))[1]=img.at<Vec3b>(i*cos(a)-j*sin(a),i*sin(a)+j*cos(a))[1];
	img1.at<Vec3b>(((img.rows/2)-i),((img.cols/2)-j))[2]=img.at<Vec3b>(i*cos(a)-j*sin(a),i*sin(a)+j*cos(a))[2];
	}
}
for(i=img.rows/2;i<img.rows;++i)
{
	for(j=img.cols/2;j<img.cols;++j)
	{
	img1.at<Vec3b>((i-(img.rows/2)),(j-(img.cols/2)))[0]=img.at<Vec3b>(i*cos(a)-j*sin(a),i*sin(a)+j*cos(a))[0];
	img1.at<Vec3b>((i-(img.rows/2)),(j-(img.cols/2)))[1]=img.at<Vec3b>(i*cos(a)-j*sin(a),i*sin(a)+j*cos(a))[1];
	img1.at<Vec3b>((i-(img.rows/2)),(j-(img.cols/2)))[2]=img.at<Vec3b>(i*cos(a)-j*sin(a),i*sin(a)+j*cos(a))[2];
	}
}
namedWindow("Rotation",WINDOW_NORMAL);
imshow("Rotation",img1);
waitKey(0);
return 0;
}
