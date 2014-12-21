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
void Element::SetText(CString s){ // ����ͼԪ�ı�
	this->text = s;
}
bool Element::isProcess(){  // �Ƿ��Ǽӹ�������ͼ��
	if (this->type == 2) return true;
	else return false;
}
bool Element::isStream(){   // �Ƿ���������ҪΪ��������ʼ��ֹԪ�أ�
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
void Element::Offset(CPoint pos, CPoint oldpos){ // λ�ƣ��ƶ�ͼԪ��
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
