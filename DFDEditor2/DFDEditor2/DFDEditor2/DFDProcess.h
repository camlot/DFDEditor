#pragma once
#include "Element.h"
class DFDProcess : public Element
{
private:
	int radix;//�뾶
	bool subDiagramState;//�Ƿ�����ͼ��־
	bool onRoutes;  // �Ƿ񾭹�����routes
public:
	DFDProcess(int type, CPoint midPoint, CString text);
	~DFDProcess();
	bool hasSubDiagram();  // �����Ƿ�����ͼ
	void setSubDiagram();
	void setOnRoutes(bool has);
	bool getOnRoutes();
	bool Contains(CPoint pos);
};
