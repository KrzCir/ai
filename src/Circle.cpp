
#include "Circle.h"

Circle::Circle(const Mat& img) : Shape(img)
{

}

Circle::~Circle()
{
    
}

Mat Circle::Find()
{
	Mat imgHSV, img;

	//Convert the captured frame from BGR to HSV
	cv::cvtColor(image, imgHSV, COLOR_BGR2HSV);

	// range to colors ?
	cv::inRange(imgHSV, getControl()->getLowHSV(), getControl()->getHighHSV(), img);

	//morphological opening (remove small objects from the foreground)
	cv::erode(img, img, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)) );
	cv::dilate(img, img, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)) );

	//morphological closing (fill small holes in the foreground)
	cv::dilate(img, img, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)) );
	cv::erode(img, img, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)) );

	return img;
}
