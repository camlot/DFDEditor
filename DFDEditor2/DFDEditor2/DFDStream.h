#pragma once
#include "Element.h"
#include"stdafx.h"
class Stream : public Element
{
private:
	Element *startE;
	Element *endE;
	int a; //长轴
	int b; //短轴
	int controlstate; //0未选中控制点，1左控制点，2右控制点
public:
	Stream(int type, CPoint midPoint, CString text);
	~Stream();
	int getState();
	bool FindControl(CPoint pos);
	bool OnsizeControl(CPoint pos);
	bool Contains(CPoint pos);
};


