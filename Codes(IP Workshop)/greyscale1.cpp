#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<iostream>
using namespace std;
using namespace cv;
int main()
{
int i,j;
Mat img= imread("lenna.jpg",1);
Mat img1(img.rows,img.cols,CV_8UC1,Scalar(0));
for(i=0;i<img.rows;++i)
{
	for(j=0;j<img.cols;++j)
	{
		img1.at<uchar>(i,j)=(img.at<Vec3b>(i,j)[0]+img.at<Vec3b>(i,j)[1]+img.at<Vec3b>(i,j)[2])/3;
	}
}
namedWindow("A",WINDOW_NORMAL);
imshow("A",img1);
waitKey(0);
return 0;
}
