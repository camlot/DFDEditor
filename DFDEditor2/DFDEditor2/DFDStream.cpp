#include "stdafx.h"
#include "DFDStream.h"


Stream::Stream(int type, CPoint midPoint, CString text)
{
	this->type = type;
	this->midPoint = midPoint;
	this->text = text;
	this->a = 60;
	this->b = 40;
	startE = NULL;
	endE = NULL;
	controlstate = 0;
}


Stream::~Stream()
{
}

int Stream::getState(){
	return 0;
}
bool Stream::FindControl(CPoint pos){
	return true;
}
bool Stream::OnsizeControl(CPoint pos){
	return true;
}
bool Stream::Contains(CPoint pos){
	if (pos.x > this->midPoint.x - a && pos.x<this->midPoint.x + a &&
		pos.y>this->midPoint.y - b && pos.y < this->midPoint.y + b){
		return true;
	}
	else return false;
}