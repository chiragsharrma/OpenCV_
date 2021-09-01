#include<opencv2/imgproc.hpp>
#include<opencv2/highgui.hpp>
#include<opencv2/imgcodecs.hpp>
#include<iostream>

using namespace std;
using namespace cv;
//to detect the shapoes in image
//we will use the canny edge detector and we will detect the edges and contour of image.

Mat imgGray, imgBlur, imgCanny, imgDil, imgErode;

void getCountours(Mat img, Mat imgDil) {
	
	vector<vector<point> > countours;
	vector<Vec4i> hierarchy;

	findContours(imgDil, countours, hierarchy, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);
	drawContours(img, countours, -1, Scalar(255, 0, 255), 2);//inbuilt function. scalar is color.
}

int main(){ 

	string path = "Resources/shapes.png";
	Mat img = imread(path);
	
	cvtColor(img, imgGray, COLOR_BGR2GRAY);
	GaussianBlur(imgGray, imgBlur, Size(3, 3), 3, 0);

	Canny(imgBlur, imgCanny, 25, 75);
	Mat kernel = getStructuringElement(MORPH_RECT, Size(3, 3));
	dilate(imgCanny, imgDil, kernel);

	getCountours(imgDil, img);

	imshow("image", img);
	/*imshow("image gray", imgGray);
	imshow("img Blur", imgBlur);
	imshow("img Canny", imgCanny);
	imshow("image dilation", imgDil)*///gap between image points converts in solid line.
	waitKey(0);


}