
#include "CharacterUnit.h"

CharacterUnit::CharacterUnit(char _name, int _size, Point *_cords)
{
	this->name 	= _name;
	this->size 	= _size;
	this->cords = _cords;
	this->match = false;
}

void CharacterUnit::clear(){
	curPos = 0;
	match = true;
}

CharacterUnit::~CharacterUnit()
{
	delete [] this->cords;
}

char CharacterUnit::getName(){
	return this->name;
}

int	CharacterUnit::getSize(){
	return this->size;
}

Point *CharacterUnit::getCords()
{
	return this->cords;
}

bool CharacterUnit::getMatch(){
	return this->match;
}

void CharacterUnit::setMatch(bool arg){
		this->match = arg;
}

int CharacterUnit::getCurPos(){
	return this->curPos;
}

Point CharacterUnit::getPos(Point p){
	return getPos(p, curPos);
}

Point CharacterUnit::getPos(Point p, int i){
	return Point(this->cords[i].x + p.x, this->cords[i].y + p.y);
}

void CharacterUnit::nextPos(){
	curPos++;
}
