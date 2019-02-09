#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<iostream>
using namespace std;
using namespace cv;
Mat img=imread("contour.png",0);
Mat output(img.rows,img.cols,CV_8UC1,Scalar(0));
int thresh = 100;
int max_thresh = 255;
void thresh_callback(int,void*)
{
Mat canny_output;
  vector<vector<Point> > contours;
  vector<Vec4i> hierarchy;

  /// Detect edges using canny
  Canny( img, output, thresh, thresh*2, 3 );
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
	 namedWindow("Contours",CV_WINDOW_AUTOSIZE);
	
	createTrackbar( " Canny thresh:", "Contours", &thresh, max_thresh, thresh_callback );
	 thresh_callback(0,0);

	
	waitKey(0);
	return 0;
}
