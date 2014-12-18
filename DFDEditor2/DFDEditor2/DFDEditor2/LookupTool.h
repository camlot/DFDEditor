#pragma once
class Element;

#include<vector>
#include<list>
#include "Tool.h"

using namespace std;

class LookupTool : public Tool
{
private:
	vector<list<Element*>> ElementQueue;  //��ά���鱣��n��·��
public:
	LookupTool();
	LookupTool(DiagramEditor *d);
	~LookupTool();
	void Press(CPoint pos, HWND hWnd);
	void FindRoutes(Element *e);
};


