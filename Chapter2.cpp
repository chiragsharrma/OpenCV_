#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;
 

//Basic functions:- colour conversion of image

void main() {

	string path = "Resources/test.png";
	Mat img = imread(path);
	Mat imgGray, imgBlur, imgCanny,imgDia,imgerode ;
	cvtColor(img, imgGray, COLOR_BGR2GRAY);   //converts input image color to gray.
	
	//image blur here:-

	GaussianBlur(img, imgBlur, Size(7, 7), 5, 0); 
	// Parameters are (input image,output image,kernalSize,sigmaX,sigmaY)
	
	//edge detection:- most of the time we use canny edge detection.
	Canny(imgBlur, imgCanny, 50, 150);
	Mat kernel = getStructuringElement(MORPH_RECT, Size(3, 3));  //structuring elements are used in c++ before image dilation
	//in case of python we use numpy library to define kernel before dilation.

	dilate(imgCanny, imgDia, kernel);
	erode(imgDia, imgerode, kernel);
	imshow("Image", img);                     //shows original image.
	imshow("ImageGray", imgGray);             //shows converted image to gray here.
	imshow("ImageBlur", imgBlur);             //shows blurred image.
	
		imshow("Image Canny", imgCanny); //shows edges in image.
		imshow("Image Dilation", imgDia);  //shows dilated image.
		imshow("Image Erosion", imgerode);



	waitKey(0);
	
	
	
	
	//erosion is opposite of dilation e.g it decreases the thickness of edges. erode(), is its function.
	//* most of the time images have joined edges or not clear and ambiguous edges so to make them clear
	//we use image dilation after image detection. it will increase their thickness and make them detectable.
}