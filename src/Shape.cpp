
#include "Shape.h"

Shape::~Shape()
{
	delete this->control;
	delete this->lowThreshold;
	delete this->maxThreshold;
};

Shape::Shape(const Mat& img)
{
	this->setImage(img);

	this->lowThreshold = new int(16);	//45;
	this->maxThreshold = new int(100);
};

void Shape::setImage(const Mat& img)
{
	this->image = img;
};

int *Shape::getLowTreshold()
{
	return this->lowThreshold;
}

int *Shape::getMaxTreshold()
{
	return this->maxThreshold;
}

void Shape::setLowTreshold(int *low)
{
	this->lowThreshold = low;
}

void Shape::setMaxTreshold(int *max)
{
	this->maxThreshold = max;
}

double Shape::Angle( cv::Point pt1, cv::Point pt2, cv::Point pt0 ) {
	double dx1 = pt1.x - pt0.x;
	double dy1 = pt1.y - pt0.y;
	double dx2 = pt2.x - pt0.x;
	double dy2 = pt2.y - pt0.y;
	return ( dx1*dx2 + dy1*dy2 )/sqrt( ( dx1*dx1 + dy1*dy1 )*( dx2*dx2 + dy2*dy2 ) + 1e-10 );
}

Mat Shape::Find()
{
	return this->image;
}

Control *Shape::getControl()
{
	return this->control;
}

void Shape::setControl(Control *c)
{
	this->control = c;
}
