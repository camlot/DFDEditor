#pragma once
#include "Element.h"
#include"stdafx.h"
class Stream : public Element
{
private:
	Element *startE;
	Element *endE;
	int a; //����
	int b; //����
	int controlstate; //0δѡ�п��Ƶ㣬1����Ƶ㣬2�ҿ��Ƶ�
public:
	Stream(int type, CPoint midPoint, CString text);
	~Stream();
	int getState();
	bool FindControl(CPoint pos);
	bool OnsizeControl(CPoint pos);
	bool Contains(CPoint pos);
};


