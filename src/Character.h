
#ifndef SRC_CHARACTER_H_
#define SRC_CHARACTER_H_

#pragma once

#include <cv.hpp>
#include <highgui.h>

#include "CharacterUnit.h"

using namespace cv;
using namespace std;

class Character {

	protected:

		cv::Mat			image;

		Point			pos,
						last,
						stay,
						start;

		double 			rangeStay;
		int				curMove;

		CharacterUnit	*chars;

		bool			stayed,
						cleared;

		string			detectedChars;

	protected:

		Point			*A();
		Point			*M();
		int				charsSize();

	protected:

		void			incDetectedChars(char c);

		bool			cord(Point p);

		void			clear();
		double			pointLineDist(Point p1, Point p2, Point p);
		bool			matchCord(Point p1, Point p2);
		bool			matchCord(Point p1, Point p2, double range);

		bool 			isStay(Point p1, Point p2, double range);
		bool			isOnWay(Point p1, Point p2, Point p, double range);

		bool			checkWay(CharacterUnit &unit, Point p0, Point pD, Point p, double range);
		char 			match(Point &p0, Point p, double range);

		void			preProcess();

	public:

						Character();
		virtual 		~Character();

	public:

		void 			process();

		void 			setImage(const Mat& img);

	public:

		bool			hasCleared();
		bool			hasStayed();

		int 			getCurMove();
		Point			getPos();
		Point			getLast();
		Point			getStay();
		Point			getStart();

		string 			getStrChord();
		string			getStrAvaChars();
		string			getStrDetectedChars();
};

#endif
