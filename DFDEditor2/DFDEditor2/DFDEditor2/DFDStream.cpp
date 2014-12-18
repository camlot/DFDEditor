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
bool Stream::startisInfieldof(Element *e, CPoint pos){
	if (e->isProcess()){
		if (this->midPoint.x - a >= pos.x - 50 && this->midPoint.x - a <= pos.x + 50
			&& this->midPoint.y - b >= pos.y - 50 && this->midPoint.y - b <= pos.y + 50){
			return true;
		}
		else return false;
	}
	else{
		if (this->midPoint.x - a >= pos.x - 60 && this->midPoint.x - a <= pos.x + 60
			&& this->midPoint.y - b >= pos.y - 40 && this->midPoint.y - b <= pos.y + 40){
			return true;
		}
		else return false;
	}
}
bool Stream::endisInfieldof(Element *e, CPoint pos){
	if (e->isProcess()){
		if (this->midPoint.x + a >= pos.x - 50 && this->midPoint.x + a <= pos.x + 50
			&& this->midPoint.y + b >= pos.y - 50 && this->midPoint.y + b <= pos.y + 50){
			return true;
		}
		else return false;
	}
	else{
		if (this->midPoint.x + a >= pos.x - 60 && this->midPoint.x + a <= pos.x + 60
			&& this->midPoint.y + b >= pos.y - 40 && this->midPoint.y + b <= pos.y + 40){
			return true;
		}
		else return false;
	}
}
bool Stream::Contains(CPoint pos){
	if (pos.x >= this->midPoint.x - a && pos.x <= this->midPoint.x + a &&
		pos.y >= this->midPoint.y - b && pos.y <= this->midPoint.y + b){
		return true;
	}
	else return false;
	
}
void Stream::setStartElement(Element *e){
	this->startE = e;
}
void Stream::setEndElement(Element *e){
	this->endE = e;
}