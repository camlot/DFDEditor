#pragma once
#include "Element.h"
class DFDProcess : public Element
{
private:
	int radix;//�뾶
	bool subDiagramState;//�Ƿ�����ͼ��־
public:
	DFDProcess(int type, CPoint midPoint, CString text);
	~DFDProcess();
	bool hasSubDiagram();  // �����Ƿ�����ͼ
	void setSubDiagram();
	bool Contains(CPoint pos);
};
