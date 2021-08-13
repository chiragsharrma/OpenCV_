#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

//importing images

//void main() {
//	string path = "Resources/test.png";
//	Mat img = imread(path);
//	imshow("image", img);
//	waitKey(0);
//
//
//}

//VIDEO PART

void main() {

	string path = "Resources/test_video.mp4";
	VideoCapture cap(path);
	Mat img;

	while (true) {

		cap.read(img);
		imshow("Image", img);
		waitKey(1);

	}
}