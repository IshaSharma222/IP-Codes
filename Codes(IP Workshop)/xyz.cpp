#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<iostream>

using namespace std;
using namespace cv;
int main()
{int i,j,k,Sum=0;
Mat img= imread("index.jpg",0);
Mat img1(img.rows,img.cols,CV_8UC1,Scalar(0));
for(k=0;k<img.cols;++k)
{for(i=k;i<k+3;++i)
	{for(j=0;j<3;++j)
	{Sum+=img.at<uchar>(k,i);
	
	img1.at<uchar>(k,i)=Sum/9;
	
	}
	}
}
namedWindow("A",WINDOW_NORMAL);
imshow("A",img1);
waitKey(0);
return 0;
}	
