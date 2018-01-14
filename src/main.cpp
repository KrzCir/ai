#include <iostream>
#include <cstdlib>
#include <vector>
#include <cmath>
#include <string>

#include <cstdlib>
#include <iostream>

#include <cv.hpp>
#include <highgui.h>

#include "Circle.h"
#include "Control.h"
#include "Character.h"

using namespace std;
using namespace cv;

void grid(Mat& img)
{
	int size = 100;	// rozmiar kratki
	int high = 3;	// liczba kratek

	for (int j=1; j<high+1; j++)
	{
		cv::line(img, Point(0,size*j), Point(1000,size*j), Scalar(0,0,255), 2);
		for (int i=0; i<10; i++)
			cv::line(img, Point(i*size,size*j), Point(i*size,size*(j+1)), Scalar(0,0,255), 2);
	}
	cv::line(img, Point(0,size*(high+1)), Point(1000,size*(high+1)), Scalar(0,0,255), 2);
}

int main( int argc, char** argv )
{
	VideoCapture cap(0);

    if ( !cap.isOpened() )
   	{
        cout << "Brak kamerki" << endl;
        return -1;
   	}

    Mat	img, imgLines, imgRes;

    Shape		*shape	= new Circle(img);
    Character	*c = new Character();

	cap.read(img);

	imgLines = Mat::zeros( img.size(), CV_8UC3 );

	shape->setControl( new Control() );

	do {
		cap.read(img);

		// efekt lustrzany (zmiana kierunku, right to left)
		cv::flip(img, img, 1);

		shape->setImage(img);

		imgRes = shape->Find();
		if (!imgRes.empty())
		{
			c->setImage(imgRes);

			c->process();

			//grid(img);

			putText(img, c->getStrChord(), Point(10, 10), FONT_HERSHEY_PLAIN, 1.0, CV_RGB(0,255,0), 2.0);
			putText(img, "Ava: "+c->getStrAvaChars(), Point(10, 30), FONT_HERSHEY_PLAIN, 1.0, CV_RGB(0,255,0), 2.0);
			putText(img, "Res: "+c->getStrDetectedChars(), Point(10, 40), FONT_HERSHEY_PLAIN, 1.0, CV_RGB(0,255,0), 2.0);

			if (c->hasCleared())
			{
				imgLines = Mat::zeros( img.size(), CV_8UC3 );
			}
			else
			{
				if (c->hasStayed())
				{
					putText(img, "stay", Point(10,20), FONT_HERSHEY_PLAIN, 1.0, CV_RGB(0,255,0), 2.0);
				}
				else
				{
					cv::line(imgLines, c->getPos(), c->getLast(), Scalar(0,0,255), 2);
				}
			}

		}

		img = img + imgLines;
	 	cv::imshow("Original", img);
	 	cv::imshow("Result Image", imgRes);

	} while ( ( waitKey( 1 ) & 0x0ff ) != 27 );

    delete shape;
    delete c;

    return 0;
}

