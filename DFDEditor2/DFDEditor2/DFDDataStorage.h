#pragma once
#include "Element.h"
class DFDDataStorage : public Element
{
private:
	int a,//中间点到左边距离
		b;//中间点到上边直线距离
public:
	DFDDataStorage(int type, CPoint midPoint, CString text);
	~DFDDataStorage();
	bool Contains(CPoint pos);
};
