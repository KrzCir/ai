
#include "Character.h"

Character::Character()
{
	this->rangeStay = 25;
	this->last = Point(-1,-1);
	this->stay = Point(-1,-1);

	this->curMove = 0;
	this->detectedChars = "";
	this->cleared = false;

	chars = new CharacterUnit[2]
	{
		CharacterUnit('M', 4, M() ),
		CharacterUnit('A', 4, A() )
	};
}

Character::~Character()
{
	delete [] chars;
}

// -----------------------------------------------
// Getters

string Character::getStrChord()
{
	return "x["+std::to_string(pos.x)+"] y["+std::to_string(pos.y)+"]"
		+ " x["+std::to_string(stay.x)+"] y["+std::to_string(stay.y)+"]"
		+ " "+std::to_string(curMove);
}

string Character::getStrAvaChars()
{
	string	res = "";

	for (int cLen=0; cLen<charsSize() && chars[cLen].getMatch(); cLen++)
		res += chars[cLen].getName();

	return res;
}

string Character::getStrDetectedChars(){
	return this->detectedChars;
}

int Character::getCurMove(){
	return this->curMove;
}

Point Character::getPos(){
	return this->pos;
}

Point Character::getLast(){
	return this->last;
}

Point Character::getStay(){
	return this->stay;
}

Point Character::getStart(){
	return this->start;
}


// -----------------------------------------------
// Setters
void Character::setImage(const Mat& img)
{
	this->image = img;
}


// -----------------------------------------------
bool Character::hasStayed(){
	return this->stayed;
}

bool Character::hasCleared(){
	return this->cleared;
}

// -----------------------------------------------
int Character::charsSize(){
	return 2;
}

Point *Character::A()
{
	return new Point[4]{
		Point(+50,-100),
		Point(+50,+100),
		Point(-50,-50),
		Point(-50,0)
	};
}

Point *Character::M(){
	return new Point[4]{
		Point(0,-100),
		Point(+50,+50),
		Point(+40,-50),
		Point(0,+100)
	};
}

bool Character::cord(Point p){
	return p.x >= 0 && p.y >= 0;
}

// http://matma4u.pl/topic/31296-odleglosc-punktu-od-odcinka/
double Character::pointLineDist(Point p1, Point p2, Point p)
{
	double A = p2.y - p1.y, B = p2.x - p1.x;
    return abs(A * (p1.x - p.x) + B * (p.y - p1.y)) / sqrt(A * A + B * B);
}

bool Character::matchCord(Point p1, Point p2)
{
	return 	(p1.x == p2.x && p1.y == p2.y);
}

bool Character::matchCord(Point p1, Point p2, double range)
{
	return	(p1.x > p2.x ? (p1.x - p2.x) <= range : (p2.x - p1.x) <= range)
		&&	(p1.y > p2.y ? (p1.y - p2.y) <= range : (p2.y - p1.y) <= range);
}

bool Character::isOnWay(Point p1, Point p2, Point p, double range)
{
	double d = this->pointLineDist(p1,p2,p);
	return d >= range*-1 && d <= range;
}

bool Character::isStay(Point p1, Point p2, double range)
{
	return this->matchCord(p1,p2)
		|| this->matchCord(p1,p2,range);
}

bool Character::checkWay(CharacterUnit &unit, Point p0, Point pD, Point p, double range)
{
	bool ret = false;

	// sprawdz czy jest juz u celu
	if (matchCord(pD,p,range))
	{
		ret = true;
	}

	// sprawdz czy jest na drodze u celu
	else if (isOnWay(p0,pD,p,range))
	{

	}

	// jest poza celem
	else
	{
		unit.setMatch(false);
	}

	return ret;
}

// za³o¿enia: posX != lastX && posY != lastY
char Character::match(Point &p0, Point p, double range)
{
	char c = ' ';

	for (int cLen=0; cLen<charsSize() && chars[cLen].getMatch(); cLen++)
	{
		if (checkWay(chars[cLen], p0, chars[cLen].getPos(p0), p, range))
		{
			p0 = p;
			chars[cLen].nextPos();

			// sprawdzenie czy przeszedl wszystkie sciezki
			if (chars[cLen].getSize() <= chars[cLen].getCurPos())
				c = chars[cLen].getName();
		}
	}

	return c;
}

void Character::incDetectedChars(char c)
{
	if (c != ' ')
		this->detectedChars += c;
}

void Character::clear()
{
	this->curMove = 0;

	// ustaw wszystkie jako pasujace
	for (int i=0; i<charsSize(); i++)
	{
		chars[i].setMatch(true);
		chars[i].clear();
	}

	this->cleared = true;

	this->stay = Point(-1,-1);
	this->start = Point(-1,-1);
}

void Character::preProcess(){
	this->cleared = false;
	this->stayed = false;
}

void Character::process()
{
	preProcess();

	Moments oMoments = moments(image);

	if (oMoments.m00 > 10000)
	{
		pos = Point( oMoments.m10 / oMoments.m00, oMoments.m01 / oMoments.m00);

		if (cord(pos))
		{
			if (cord(stay))
			{
				stayed = isStay(pos,stay,rangeStay);

				if (!stayed)
				{
					incDetectedChars(match(start, pos, rangeStay));

					curMove++;
					stay = pos;
				}
			}

			// pierwsze pojawienie sie obiektu
			else
			{
				stay = pos;
				start = pos;
			}

			last = pos;
		}
	}

	else
	{
		clear();
	}

}
