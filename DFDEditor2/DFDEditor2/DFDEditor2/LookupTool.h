#pragma once
class Element;

#include "Tool.h"
#include<list>

using namespace std;

class LookupTool : public Tool
{
private:
	list<Element*>ElementQueue;
public:
	LookupTool();
	LookupTool(DiagramEditor *d);
	~LookupTool();
	void Press(CPoint pos, HWND hWnd);
	void FindRoutes(Element *e);
};


