#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<iostream>
using namespace std;
using namespace cv;

void abc(int,void*);
Mat img= imread("a.png",1);
Mat img1(img.rows,img.cols,CV_8UC3,Scalar(0,0,0));
int b_low = 0,b_high = 255,g_low = 0,g_high = 255,r_low = 0,r_high = 255;
void abc(int low, void*q)
{int i,j;
	for(i=0;i<img.rows;++i)
	{
		for(j=0;j<img.cols;++j)		
		{
		if((img.at<Vec3b>(i,j)[0]<=b_high)&&(img.at<Vec3b>(i,j)[0]>=b_low)&&(img.at<Vec3b>(i,j)[1]<=g_high)&&(img.at<Vec3b>(i,j)[1]>=g_low)&&(img.at<Vec3b>(i,j)[2]>=r_low)&&(img.at<Vec3b>(i,j)[2]<=r_high))
		 {img1.at<Vec3b>(i,j)[0]=img.at<Vec3b>(i,j)[0];
		  img1.at<Vec3b>(i,j)[1]=img.at<Vec3b>(i,j)[1];
	          img1.at<Vec3b>(i,j)[2]=img.at<Vec3b>(i,j)[2];
			}
		else img1.at<Vec3b>(i,j)={0,0,0};
		}
	}
imshow("A",img1);

}

int main()
{int i,j;
//int a=0,b=0,c=0,d=0,e=0,f=0;


namedWindow("A",WINDOW_NORMAL);
createTrackbar("b_low","A",&b_low,255,abc,NULL);
createTrackbar("b_high","A",&b_high,255,abc,NULL);
createTrackbar("g_low","A",&g_low,255,abc,NULL);
createTrackbar("g_high","A",&g_high,255,abc,NULL);
createTrackbar("r_low","A",&r_low,255,abc,NULL);
createTrackbar("r_high","A",&r_high,255,abc,NULL);


waitKey(0);
return 0;
}



