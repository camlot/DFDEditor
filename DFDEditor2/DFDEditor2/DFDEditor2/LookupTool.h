#pragma once
class Element;

#include<vector>
#include<list>
#include "Tool.h"

using namespace std;

class LookupTool : public Tool
{
private:
	vector<Element*> routes;  //保存所有Stream
public:
	LookupTool();
	LookupTool(DiagramEditor *d);
	~LookupTool();
	void Press(CPoint pos, HWND hWnd);
	void DoubleClick(CPoint, HWND hWnd);
	void OpenDiagramtoProcess(HWND hWnd, Diagram *d);  // 打开Process的子图
};


