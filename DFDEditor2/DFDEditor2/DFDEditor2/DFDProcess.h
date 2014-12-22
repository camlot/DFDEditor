#pragma once
#include "Element.h"
class DFDProcess : public Element
{
private:
	int radix;//半径
	bool subDiagramState;//是否有子图标志
	bool onRoutes;  // 是否经过查找routes
public:
	DFDProcess(int type, CPoint midPoint, CString text);
	~DFDProcess();
	bool hasSubDiagram();  // 返回是否有子图
	void setSubDiagram();
	void setOnRoutes(bool has);
	bool getOnRoutes();
	bool Contains(CPoint pos);
};
