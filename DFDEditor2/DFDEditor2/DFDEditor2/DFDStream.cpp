#include "stdafx.h"
#include "DFDStream.h"


Stream::Stream(int type, CPoint midPoint, CString text)
{
	this->type = type;
	this->midPoint = midPoint;
	this->text = text;
	//this->a = 60;
	//this->b = 40;
	startE = NULL;
	endE = NULL;
	start.SetPoint(midPoint.x - 60, midPoint.y - 40);
	end.SetPoint(midPoint.x + 60, midPoint.y + 40);
	controlstate = 0;
}


Stream::~Stream()
{
}
CPoint Stream::getStart(){
	return this->start;
}
CPoint Stream::getEnd(){
	return this->end;
}
int Stream::getState(){
	return this->controlstate;
}
void Stream::ContainsPoint(CPoint pos){
	if (pos.x >= this->start.x - 5 && pos.x <= this->start.x + 5 && pos.y >= start.y -5 && pos.y <= start.y + 5)
	{
		this->setControstate(1);
	}
	if (pos.x >= this->end.x - 5 && pos.x <= this->end.x + 5 && pos.y >= end.y - 5 && pos.y <= end.y + 5)
	{
		this->setControstate(2);
	}
	
}
void Stream::Onsize(CPoint pos){
	if (controlstate == 1) //选中左控制点
	{
		start.SetPoint(pos.x, pos.y);
	}
	if (controlstate == 2)//选中右控制点
	{
		end.SetPoint(pos.x, pos.y);
	}
	//this->midPoint.x = (start.x + end.x) / 2;
	midPoint.SetPoint((this->start.x + this->end.x) / 2, this->midPoint.y);
}
void Stream::Offset(CPoint pos, CPoint oldpos){
	//this->start.x += pos.x - this->midPoint.x;
	//this->start.y += pos.y - this->midPoint.y;
	//this->end.x += pos.x - this->midPoint.x;
	//this->end.y += pos.y - this->midPoint.y;
	this->start += pos - oldpos;
	this->end += pos - oldpos;
	this->midPoint += pos - oldpos;
}
bool Stream::startisInfieldof(Element *e, CPoint pos){
	if (e->isProcess()){
		if (this->start.x >= pos.x - 50 && this->start.x <= pos.x + 50
			&& this->start.y >= pos.y - 50 && this->start.y <= pos.y + 50){
			return true;
		}
		else return false;
	}
	else{
		if (this->start.x >= pos.x - 60 && this->start.x <= pos.x + 60
			&& this->start.y >= pos.y - 40 && this->start.y <= pos.y + 40){
			return true;
		}
		else return false;
	}
}
bool Stream::endisInfieldof(Element *e, CPoint pos){
	if (e->isProcess()){
		if (this->end.x >= pos.x - 50 && this->end.x <= pos.x + 50
			&& this->end.y >= pos.y - 50 && this->end.y <= pos.y + 50){
			return true;
		}
		else return false;
	}
	else{
		if (this->end.x >= pos.x - 60 && this->end.x <= pos.x + 60
			&& this->end.y >= pos.y - 40 && this->end.y <= pos.y + 40){
			return true;
		}
		else return false;
	}
}
bool Stream::Contains(CPoint pos){ //移动的时候需要找mid点，end点和start点的最小和最大界，然后判断是否包含

	int Maxx = (start.x > this->getmidPoint().x ? (start.x > end.x ? start.x : end.x) : (this->getmidPoint().x > end.x ? this->getmidPoint().x : end.x));
	int Maxy = (start.y > this->getmidPoint().y ? (start.y > end.y ? start.y : end.y) : (this->getmidPoint().y > end.y ? this->getmidPoint().y : end.y));
	int Minx = (start.x < this->getmidPoint().x ? (start.x < end.x ? start.x : end.x) : (this->getmidPoint().x < end.x ? this->getmidPoint().x : end.x));
	int Miny = (start.y < this->getmidPoint().y ? (start.y < end.y ? start.y : end.y) : (this->getmidPoint().y < end.y ? this->getmidPoint().y : end.y));

	if (pos.x >= Minx-5 && pos.x <= Maxx+5 &&
		pos.y >=Miny-5 && pos.y <=Maxy+5){
		return true;
	}
	else return false;
}
bool Stream::CompareStartElementWith(Element *e){
	if (this->startE == e) return true;
	else return false;
}
bool Stream::CompareEndElementWith(Element *e){
	if (this->endE == e) return true;
	else return false;
}
void Stream::setStartElement(Element *e){
	this->startE = e;
}
void Stream::setEndElement(Element *e){
	this->endE = e;
}

void Stream::setControstate(int state){
	this->controlstate = state;

}