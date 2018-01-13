
#include "Control.h"

Control::Control()
{
	// set default value
	//this->setLowHSV(170,150,60);
	this->setLowHSV(150,115,0);
	this->setHighHSV(179,255,255);
	// end set default valueControl

	cv::namedWindow("Control", CV_WINDOW_AUTOSIZE);

	for (int i=0; i<3; i++)
		createTrackbar("Low"+std::to_string(i), "Control", &lowHSV[i], 255);

	for (int i=0; i<3; i++)
		createTrackbar("High"+std::to_string(i), "Control", &highHSV[i], 255);
}

Control::~Control()
{

}

void Control::setHighHSV(int h, int s, int v)
{
	this->highHSV[0] = h;
	this->highHSV[1] = s;
	this->highHSV[2] = v;
}

void Control::setLowHSV(int h, int s, int v)
{
	this->lowHSV[0] = h;
	this->lowHSV[1] = s;
	this->lowHSV[2] = v;
}

Scalar Control::getHighHSV()
{
	return Scalar(highHSV[0],highHSV[1],highHSV[2]);
}

Scalar Control::getLowHSV()
{
	return Scalar(lowHSV[0],lowHSV[1],lowHSV[2]);
}
