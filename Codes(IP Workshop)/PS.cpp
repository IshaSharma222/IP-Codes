#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<iostream>
using namespace std;
using namespace cv;

//void abc(int,void*);
//Mat img= imread("red.jpg",1);

Mat img1(img.rows,img.cols,CV_8UC3,Scalar(0,0,0));
Mat output(img.rows,img.cols,CV_8UC3,Scalar(0,0,0));
int b_low = 3,b_high = 255,g_low = 36,g_high = 255,r_low = 244,r_high = 255;
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

imshow("Threshold",img1);
waitKey(0);
}
int thresh = 100;
int max_thresh = 255;
void thresh_callback(int,void*)
{
Mat canny_output;
  vector<vector<Point> > contours;
  vector<Vec4i> hierarchy;

  /// Detect edges using canny
  Canny( img1, output, thresh, thresh*2, 3 );
  /// Find contours
  findContours( output, contours, hierarchy, CV_RETR_TREE, CV_CHAIN_APPROX_SIMPLE, Point(0, 0) );

  /// Draw contours
  Mat drawing = Mat::zeros( output.size(), CV_8UC3 );
  for( int i = 0; i< contours.size(); i++ )
     {
       Scalar color = Scalar( rand()&255, rand()&255, rand()&255 );
       drawContours( drawing, contours, i, color, 2, 8, hierarchy, 0, Point() );
     }

  /// Show in a window
  namedWindow( "Contours", CV_WINDOW_AUTOSIZE );
  imshow( "Contours", drawing );
}

int main()
{
int i,j;
int a,b;

VideoCapture vid(0);
Mat frame;
while(1)
{
	/*vid.read(img);
	imshow("win",img);
	if (waitKey(50)>=0);*/
	vid>>frame;
	Mat img(frame.rows,frame.cols,CV_8UC3,Scalar(0,0,0));
	namedWindow("Contours",CV_WINDOW_AUTOSIZE);
	namedWindow("A",WINDOW_NORMAL);
	namedWindow("Threshold",WINDOW_NORMAL);
	createTrackbar("b_low","A",&b_low,255,abc,NULL);
	createTrackbar("b_high","A",&b_high,255,abc,NULL);
	createTrackbar("g_low","A",&g_low,255,abc,NULL);
	createTrackbar("g_high","A",&g_high,255,abc,NULL);
	createTrackbar("r_low","A",&r_low,255,abc,NULL);
	createTrackbar("r_high","A",&r_high,255,abc,NULL);
	createTrackbar("Canny Thresh:","Contours",&thresh, max_thresh, thresh_callback);
	thresh_callback(0,0);
	waitKey(50);
}
Mat img2;

 

return 0;
}
	
