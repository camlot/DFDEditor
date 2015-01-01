#include "stdafx.h"
#include "DFDSource.h"


DFDSource::DFDSource(int type, CPoint midPoint, CString text)
{
	this->type = type;
	this->midPoint = midPoint;
	this->text = text;
	this->a = 60;
	this->b = 40;
}


DFDSource::~DFDSource()
{
}

bool DFDSource::Contains(CPoint pos){
	if (pos.x >= this->midPoint.x - a && pos.x <= this->midPoint.x + a &&
		pos.y >= this->midPoint.y - b && pos.y <= this->midPoint.y + b){
		return true;
	}
	else return false;
}