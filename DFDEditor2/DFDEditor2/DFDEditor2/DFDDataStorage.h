#pragma once
#include "Element.h"
class DFDDataStorage : public Element
{
private:
	int a,//�м�㵽��߾���
		b;//�м�㵽�ϱ�ֱ�߾���
public:
	DFDDataStorage(int type, CPoint midPoint, CString text);
	~DFDDataStorage();
	bool Contains(CPoint pos);
};
