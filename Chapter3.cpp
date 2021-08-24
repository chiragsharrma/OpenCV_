#include<opencv2/imgcodecs.hpp>
#include<opencv2/highgui.hpp>
#include<opencv2/imgproc.hpp>
#include<iostream>


using namespace cv;
using namespace std;

void main() {

	string path = "Resources/test.png";
	Mat img = imread(path);
	Mat imgResize, imgcrop;
	//cout << img.size() << endl;
	Rect roi(100, 100, 300, 250);    //rect is an data type like Mat. just a Rectangle.and 4 parameteres like 4 sides of rectangle.
	imgcrop = img(roi);   //stored the cropped image in imgCrop variable. roi is a function name.

	resize(img, imgResize, Size(),0.5,0.5);//scaled the image instead of manually giving the size.

	imshow("Image", img);
	imshow("Image resized", imgResize);
	imshow("image cropped", imgcrop);   // to output it on screen.
	//like we got the output.
	waitKey(0);     //we saw two data types Mat for matrix and Rect for Rectangle.
					//Rect is used for cropping images by giving dimensions as function parameters.
}					//(size(kernel)) and (existing file,output file) fashion.
