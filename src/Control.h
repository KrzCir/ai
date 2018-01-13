#pragma once

#include <cv.hpp>
#include <highgui.h>

using namespace std;
using namespace cv;

class Control{

	protected:

		int lowHSV[3];
		int highHSV[3];

	public:

		Control();
		~Control();

		Scalar getLowHSV();
		Scalar getHighHSV();

		void setLowHSV(int h, int s, int v);
		void setHighHSV(int h, int s, int v);
};
