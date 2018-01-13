
#ifndef SRC_CHARACTERUNIT_H_
#define SRC_CHARACTERUNIT_H_

#pragma once

#include <cv.hpp>
#include <highgui.h>

using namespace cv;
using namespace std;

class CharacterUnit {

	protected:

		char	name;
		int 	size;
		Point	*cords;
		int		curPos;
		bool	match;

	public:

		CharacterUnit(char _name, int _size, Point *_cords);
		virtual ~CharacterUnit();

		char	getName();
		int		getSize();
		Point	*getCords();

		bool	getMatch();
		void	setMatch(bool arg);

		int		getCurPos();
		Point	getPos(Point p);
		Point	getPos(Point p, int i);

		void	nextPos();

		void 	clear();
};

#endif
