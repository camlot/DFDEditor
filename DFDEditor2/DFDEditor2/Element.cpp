#include "stdafx.h"
#include "Element.h"

Element::Element(){

}

Element::~Element()
{
}

void Element::SetText(CString s){ // ����ͼԪ�ı�
	this->text = s;
}
bool Element::isProcess(){  // �Ƿ��Ǽӹ�������ͼ��
	if (this->type == 2) return true;
	else return false;
}
void Element::Offset(CPoint pos){ // λ�ƣ��ƶ�ͼԪ��
	this->midPoint = pos;
}