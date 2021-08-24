#include<opencv2/imgcodecs.hpp>
#include<opencv2/highgui.hpp>
#include<opencv2/imgproc.hpp>
#include<iostream>


using namespace cv;
using namespace std;

void main() {
	//blank image.
		Mat img(512, 512, CV_8UC3, Scalar(0, 0, 0));  //Scalar(BGR), cv_8 bits unsigned colours 3
		circle(img, Point(256, 256), 155, Scalar(0, 69, 255),FILLED);
		//Point is a data type for defining centre points of circle here. 
		//scalar is to define colours.
		rectangle(img, Point(130, 226), Point(382, 286), Scalar(0, 0, 0),FILLED);
		//point(x,y),point(x1,y1).
		line(img, Point(130, 296), Point(382, 296), Scalar(0, 0, 0), 2);
		//2 is the thickness of line.
		putText(img, "nemesis", Point(137, 262), FONT_HERSHEY_DUPLEX, 2 , Scalar(0,69, 255), 2);
		imshow("Image", img);
		//last 2 is thickness and first occurence of 2 is colour. font hershey is font type.
		waitKey(0);			//putText is used to write text over output image. 
}
