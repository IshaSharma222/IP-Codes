#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"
#include <iostream>
#include <stdio.h>
#include <bits/stdc++.h>
using namespace cv;
using namespace std;

int main()
{
    Mat img1=imread("66.jpg",0);
    Mat img2=imread("88.jpg",0);
    Mat img3=imread("l31.jpg",0);
    double tan,theta,thetad;
    for(int i=0;i<img1.rows;i++)
    {
        for(int j=0;j<img1.cols;j++)
        {
            if(img1.at<uchar>(i,j)>100)
                img1.at<uchar>(i,j)=255;
            else
                img1.at<uchar>(i,j)=0;
        }
    }
    for(int i=0;i<img2.rows;i++)
    {
        for(int j=0;j<img2.cols;j++)
        {
            if(img2.at<uchar>(i,j)>25)
                img2.at<uchar>(i,j)=255;
            else
                img2.at<uchar>(i,j)=0;
        }
    }
    for(int i=0;i<img3.rows;i++)
    {
        for(int j=0;j<img3.cols;j++)
        {
            if(img3.at<uchar>(i,j)>100)
                img3.at<uchar>(i,j)=255;
            else
                img3.at<uchar>(i,j)=0;
        }
    }
 	dilate(img1,img1,Mat());
    erode(img1,img1,Mat());
    dilate(img2,img2,Mat());
    erode(img2,img2,Mat());
    dilate(img3,img3,Mat());
    erode(img3,img3,Mat());
   namedWindow("1",WINDOW_NORMAL);
namedWindow("2",WINDOW_NORMAL);
namedWindow("2",WINDOW_NORMAL);
imshow("1",img1);
imshow("2",img2);
imshow("3",img3);
    waitKey(0);
    return 0;

}
