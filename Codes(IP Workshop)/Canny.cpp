#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<iostream>
#include<math.h>
using namespace std;
using namespace cv;

Mat img=imread("rubik.jpg",0);

int isvalid(int i, int j)
{
if(i!=0  && i!= img.rows-1 && j!=0 && j!=img.cols-1)
return 1;
else return 0;
}

void abc(int low,void *q)
{
Mat img1(img.rows,img.cols,CV_8UC1,Scalar(0));
Canny(img,img1,low,3*low,3);
imshow("Edge",img1);}
int main()
{int b=0;
namedWindow("Edge",WINDOW_NORMAL);
createTrackbar("T","Edge",&b,255,abc,NULL);
waitKey(0);
return 0;
}
