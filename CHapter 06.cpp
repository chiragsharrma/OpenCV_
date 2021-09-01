#include<opencv2/imgcodecs.hpp>
#include<opencv2/highgui.hpp>
#include<opencv2/imgproc.hpp>
#include<iostream>     

//COLOR DETECTION 
using namespace std;
using namespace cv;

Mat imgHSV, mask;
//COLOR DETECTION- FIRST I WILL DO THE HSV DETECTION HUGH SATURATION VALUE 
//(HSV) HUGH HAS HIGHEST AT 179 SATURATION AND VALUE HAS AT 255. 

int hmin = 0, smin = 110, vmin = 153;   ///color values that i observed in the image.
int hmax = 19, smax = 240, vmax = 255;    // these values are to see the image masked i.e in black and white. these value can be anything according to us.
												//now i will create a trackbar window by namedWindow() then i will create the trackbars

void main() {
	string path = "Resources/lambo.png";
	Mat img = imread(path);
	cvtColor(img, imgHSV, COLOR_BGR2HSV); 

	namedWindow("Trackbars", (640, 200));
	createTrackbar("hue min", "Trackbars", &hmin, 179); ///createTrackbar(name of trackbar,window of trackbar,address of value we want to associate,max value of that quantity )
	createTrackbar("hue max", "Trackbars", &hmax, 179);    //HSV trackbars
	createTrackbar("sat min", "Trackbars", &smin, 255);
	createTrackbar("sat max", "Trackbars", &smax, 255);
	createTrackbar("val min", "Trackbars", &vmin, 255);
	createTrackbar("val max", "Trackbars", &vmax, 255);

	while (true) {
		//now its converted to hsv now i will use the inRange function (current image variable, lower limit,upper limit, output image variable)
		Scalar lower(hmin, smin, vmin);   //(hue minimum value,saturation minimum value,value minimum)
		Scalar upper(hmax, smax, vmax);

		inRange(imgHSV, lower, upper, mask);    //output i am storing in mask variable.

		imshow("Image", img);
		imshow("Image HSV", imgHSV);
		imshow("Image mask", mask);

		waitKey(1);
	}
}