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
CPoint Stream::GetStart(){
	return this->start;
}
CPoint Stream::GetEnd(){
	return this->end;
}
int Stream::GetState(){
	return this->controlstate;
}
void Stream::SetStart(CPoint pos){
	this->start = pos;
}
void Stream::SetEnd(CPoint pos){
	this->end = pos;
}
void Stream::ContainsPoint(CPoint pos){
	if (pos.x >= this->start.x - 5 && pos.x <= this->start.x + 5 && pos.y >= start.y -5 && pos.y <= start.y + 5)
	{
		this->SetControlState(1);
	}
	if (pos.x >= this->end.x - 5 && pos.x <= this->end.x + 5 && pos.y >= end.y - 5 && pos.y <= end.y + 5)
	{
		this->SetControlState(2);
	}
	
}
void Stream::Onsize(CPoint pos){
	if (controlstate == 1) //选中左控制点
	{
		//start.SetPoint(pos.x, pos.y);
		SetStart(pos);
	}
	if (controlstate == 2)//选中右控制点
	{
		//end.SetPoint(pos.x, pos.y);
		SetEnd(pos);
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
void Stream::StartFollowElement(Element *e){
	int cx, cy;
	if (e->isProcess()){
		cx = 50; cy = 50;
	}
	else{
		cx = 60, cy = 40;
	}
	if (e->Contains(CPoint(this->GetStart().x, this->getmidPoint().y))){
		if (this->GetStart().x <= this->getmidPoint().x){
			this->SetStart(CPoint(e->getmidPoint().x + cx, e->getmidPoint().y));
		}
		else{
			this->SetStart(CPoint(e->getmidPoint().x - cx, e->getmidPoint().y));
		}
	}
	else{
		if (this->GetStart().y <= this->getmidPoint().y){
			this->SetStart(CPoint(e->getmidPoint().x, e->getmidPoint().y + cy));
		}
		else{
			this->SetStart(CPoint(e->getmidPoint().x, e->getmidPoint().y - cy));
		}
	}
}
void Stream::EndFollowElement(Element *e){
	int cx, cy;
	if (e->isProcess()){
		cx = 50; cy = 50;
	}
	else{
		cx = 60, cy = 40;
	}
	if (e->Contains(CPoint(this->GetEnd().x, this->getmidPoint().y))){
		if (this->GetEnd().x <= this->getmidPoint().x){
			this->SetEnd(CPoint(e->getmidPoint().x + cx, e->getmidPoint().y));
		}
		else{
			this->SetEnd(CPoint(e->getmidPoint().x - cx, e->getmidPoint().y));
		}
	}
	else{
		if (this->GetEnd().y <= this->getmidPoint().y){
			this->SetEnd(CPoint(e->getmidPoint().x, e->getmidPoint().y + cy));
		}
		else{
			this->SetEnd(CPoint(e->getmidPoint().x, e->getmidPoint().y - cy));
		}
	}
}
bool Stream::StartisInfieldof(Element *e, CPoint pos){
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
bool Stream::EndisInfieldof(Element *e, CPoint pos){
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
bool Stream::Contains(CPoint pos){ 

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
void Stream::SetStartElement(Element *e){
	if (e != NULL)
	{
		this->startE = e;
		//this->start.x = e->getmidPoint().x;
		//this->start.y = e->getmidPoint().y + 10;
		midPoint.SetPoint((this->start.x + this->end.x) / 2, this->midPoint.y);
	}
	else this->startE = NULL;
}
void Stream::SetEndElement(Element *e){
	if (e != NULL)
	{
		this->endE = e;
		//this->end.x = e->getmidPoint().x;
		//this->end.y = e->getmidPoint().y + 10;
		midPoint.SetPoint((this->start.x + this->end.x) / 2, this->midPoint.y);
	}
	else this->endE = NULL;
}

void Stream::SetControlState(int state){
	this->controlstate = state;
}

Element* Stream::getStartElement()
{
	return this->startE;
}

Element* Stream::getEndElement()
{
	return this->endE;
}
