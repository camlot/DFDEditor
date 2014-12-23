#pragma once
class Element;
class DFDProcess;

#include<vector>
#include <queue>
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
	void RightPress();
	void DoubleClick(CPoint, HWND hWnd);
	void OpenDiagramtoProcess(HWND hWnd, Diagram *d);  // 打开Process的子图
	void ClearProcessOnRoutes(queue<DFDProcess*>& fathers);
};


