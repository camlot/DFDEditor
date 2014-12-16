#include "stdafx.h"
#include "Element.h"

Element::Element(){

}

Element::~Element()
{
}

void Element::SetText(CString s){ // 设置图元文本
	this->text = s;
}
bool Element::isProcess(){  // 是否是加工（有子图）
	if (this->type == 2) return true;
	else return false;
}
void Element::Offset(CPoint pos){ // 位移（移动图元）
	this->midPoint = pos;
}