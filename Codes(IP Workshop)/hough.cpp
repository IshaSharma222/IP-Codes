#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<iostream>
#include<math.h>
using namespace std;
using namespace cv;
Mat img= imread("pentagon.png",0);
double diag= sqrt((img.rows*img.rows)+(img.cols*img.cols));
Mat img1(2*diag,300,CV_8UC1,Scalar(0));

int main()
{
	int o,i,j,k,x;
	namedWindow("Hough",WINDOW_NORMAL);
	namedWindow("Hough2",WINDOW_NORMAL);
	imshow("Hough",img1);
	imshow("Hough2",img);
	for(i=0;i<img.rows;i++)
	{
		for(j=0;j<img.cols;j++)
		{	//cout<<1;
			if(img.at<uchar>(i,j)>=130)
			{	
				imshow("Hough",img1);
				
				waitKey(5);
				for(o=1;o<=180;o++)
				{
					double x=(3.14/180)*o;
					double r=(j*cos(x))+(i*sin(x));
					cout<<r<<endl;
					img1.at<uchar>(diag-r,o)+=15;
					
				}
			}
		}
	}
waitKey(0);
return 0;
}

