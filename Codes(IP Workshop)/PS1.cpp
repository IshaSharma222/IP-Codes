#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<opencv2/core/core.hpp>
#include<iostream>
#include<stdio.h>
using namespace cv;
using namespace std;
int main()
{
    VideoCapture vid(0);
    Mat img;
    Mat frame;
    Mat img2;
    while(1)
    {
	int a,y,z;
        vid>>frame;
        vid>>img;
        for(int i=0;i<frame.rows;i++)
        {
            for(int j=0;j<frame.cols;j++)
            {
                if(frame.at<Vec3b>(i,j)[0]<18 || frame.at<Vec3b>(i,j)[0]>148)
                    img.at<Vec3b>(i,j)={0,0,0};
                if(frame.at<Vec3b>(i,j)[1]<14 || frame.at<Vec3b>(i,j)[1]>130)
                    img.at<Vec3b>(i,j)={0,0,0};
                if(frame.at<Vec3b>(i,j)[2]<159|| frame.at<Vec3b>(i,j)[2]>255)
                    img.at<Vec3b>(i,j)={0,0,0};
            }
        }
        erode(img,img,Mat());
	dilate(img,img,Mat());
        blur(img,img,Size(3,3));
        vector<vector<Point>>contours;
        vector<Vec4i>hierarchy;
        Canny(img,img2,80,3*80,3);
        findContours(img2,contours,hierarchy,CV_RETR_TREE,CV_CHAIN_APPROX_SIMPLE,Point(0,0));
        Mat contour=Mat::zeros(img2.size(),CV_8UC3);
        for( int i = 0; i< contours.size(); i++ )
        {
            	Scalar color( 255, 255, 255 );
            	drawContours(contour, contours, i, color, 2, 8, hierarchy, 0, Point() );
        }
        imshow("window",contour);
        int area=0;
        for (int i = 0;  i < contours.size();  i++)
	{   
            	if(area < contourArea(contours[i]))
            	{
                area=contourArea(contours[i]);  
	   	}
        }
        cout<<"Area ="<<area<<endl;
	if(area>30000 && area<50000)
  	a=0;
	else if(area>80000)
	a=-127;
	else if(area<8000 && area>1000)
	a=127;
	else if(area<1000)
	a=0;
	else
	a=127-127*area/40000;
	cout<<"X="<<a<<endl;
        Mat grey,binary;
        cvtColor( contour, grey, COLOR_BGR2GRAY );
        threshold( grey, binary, 50,255,THRESH_BINARY );
        Moments m = moments(binary,true);
        int cx=m.m10/m.m00;
        int cy=m.m01/m.m00;
        z=frame.cols/2-cx;
        if(z>-30 && z<30)
            y=0;
        else if(z>100)
            y=127;
        else if(z<-100)
            y=-127;
        else 
            y=z*127/90;
        cout<<"Angular speed="<<y<<endl;
        waitKey(150);
    }
    return 0;
}
