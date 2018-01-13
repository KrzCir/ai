
#pragma once

#include <iostream>
#include <cstdlib>
#include <vector>
#include <cmath>
#include <string>

#include <cv.hpp>
#include <highgui.h>

#include "Control.h"

using namespace std;
using namespace cv;

class Shape{

	protected:

		int *lowThreshold;
		int *maxThreshold;

		Mat image;

		Control	*control;

    public:

        Shape(const Mat& img);
        virtual ~Shape();

        void setImage(const Mat& img);
        void setLowTreshold(int *low);
        void setMaxTreshold(int *max);
        int *getLowTreshold();
        int *getMaxTreshold();

        void setControl(Control *c);
        Control *getControl();

        double Angle( cv::Point pt1, cv::Point pt2, cv::Point pt0 );
        virtual Mat Find();
};
