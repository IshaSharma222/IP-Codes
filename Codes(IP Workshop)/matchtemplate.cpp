#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<iostream>
using namespace std;
using namespace cv;
Mat img=imread("coins.jpeg",1);
Mat templ=imread("temp.jpeg",1);
Mat output(img.rows,img.cols,CV_8UC1,Scalar(0));
int main()
{
	matchTemplate(img,templ,output,CV_TM_SQDIFF_NORMED);
	namedWindow("Temp",WINDOW_NORMAL);
	imshow("Temp",output);
	waitKey(0);
	return 0;
}
