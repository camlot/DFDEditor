#include "stdafx.h"
#include "Element.h"

Element::Element(){
	this->isHighlight = false;
}

Element::~Element()
{
}
CPoint Element::GetMidPoint(){
	return midPoint;
}
CString Element::GetText(){
	return text;
}
void Element::SetText(CString s){ // 设置图元文本
	this->text = s;
}
bool Element::isProcess(){  // 是否是加工（有子图）
	if (this->type == 2) return true;
	else return false;
}
bool Element::isStream(){   // 是否是流（需要为流设置起始终止元素）
	if (this->type == 4) return true;
	else return false;
}
bool Element::isSource(){  
	if (this->type == 1) return true;
	else return false;
}
bool Element::isDataStorage(){   
	if (this->type == 3) return true;
	else return false;
}
void Element::Offset(CPoint pos, CPoint oldpos){ // 位移（移动图元）
	this->midPoint += pos - oldpos;
}

void Element::SetHighlightFlag(bool isHighlight)
{
	this->isHighlight = isHighlight;
}

bool Element::GetHighlightFlag()
{
	bool high = this->isHighlight;
	return this->isHighlight;
}
