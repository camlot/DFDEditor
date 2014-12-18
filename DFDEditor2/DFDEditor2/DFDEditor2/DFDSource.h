#pragma once
#include "Element.h"
class DFDSource : public Element
{
private:
	int a;
	int	b;

public:
	DFDSource(int type, CPoint midPoint, CString text);
	~DFDSource();
	bool Contains(CPoint pos);
};