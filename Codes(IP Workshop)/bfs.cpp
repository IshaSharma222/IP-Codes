#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
using namespace cv;
Mat img= imread("dfs_path.jpg",0);
Mat img1(img.rows,img.cols,CV_8UC1,Scalar(0));
queue<Point2d>q;
int isvalid(int i, int j)
{
if(i!=0  && i!= img.rows-1 && j!=0 && j!=img.cols-1)
return 1;
else return 0;
}

int bfs(Point start)
{
	int a,k,l,count=0;
	int mark[1000][1000];
	for(k=0;k<1000;k++)
	{	for(l=0;l<1000;l++)
		mark[k][l]=0;}  
		int i = start.y;
		int j= start.x;  
		a=isvalid(i,j);
		if((a==1)&&(mark[i][j]!=1))
		{ 
			q.push(start);
			while(!q.empty()) 
		 	{ q.pop();
		  	mark[i][j]=1;
		  	count = bfs(i,j);
		  	count++;
		 	}
		}
	else img1.at<uchar>(i,j)=255;
	return count;
	}
int main()
{
int i,j,n;

for(i=0;i<img.rows;++i)
{
	for(j=0;j<img.cols;++j)
	{
		if(img.at<uchar>(i,j)==0)
		{ Point p;
		  p.x=j;      p.y=i;
	          n=bfs(p);
		}
	}
}
cout<<n;
namedWindow("BFS",WINDOW_NORMAL);
imshow("BFS",img1);
waitKey(0);
return 0;
}

	 		
