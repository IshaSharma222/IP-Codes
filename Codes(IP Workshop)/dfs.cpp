#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
using namespace cv;
Mat img= imread("dfs_path.jpg",0);
int isvalid(int i, int j)
{
if(i!=0  && i!= img.rows-1 && j!=0 && j!=img.cols-1)
return 1;
else return 0;
}
void dfs(int i, int j)
{ imshow("Path",img);
  waitKey(15);
	 int a =isvalid(i,j);
		if(a==1);
		{ /*if(i==(img.rows-1))  && (j==(img.cols-1)))
			exit(0);*/
			if((img.at<uchar>(i,j+1)!=0)&&(isvalid(i,j+1)))
			{	
				img.at<uchar>(i,j+1)=0;
				dfs(i,j+1);
			}
			else if((img.at<uchar>(i+1,j)!=0)&&(isvalid(i+1,j)))
			{
				img.at<uchar>(i+1,j)=0;
				dfs(i+1,j);
			}
			else if((img.at<uchar>(i-1,j)!=0)&&(isvalid(i-1,j)))
			{
				img.at<uchar>(i-1,j)!=0;
				dfs(i-1,j);
			}
			else if(isvalid(i,j-1)) 
			{
				img.at<uchar>(i,j-1)=0;
				dfs(i,j-1);
			}
		}
}

int main()
{ int i,j;
namedWindow("Path",WINDOW_NORMAL);
for(i=0;i<img.rows;i++)
{
	for(j=0;j<img.cols;j++)
	{
		dfs(i,j);
		
	}
}
return 0;
}

