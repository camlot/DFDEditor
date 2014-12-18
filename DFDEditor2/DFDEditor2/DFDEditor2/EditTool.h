#pragma once
class Element;
class Diagram;

#include"Tool.h"

class EditTool : public Tool
{
public:
	EditTool();
	EditTool(DiagramEditor *d);
	~EditTool();
	void Press(CPoint pos, HWND hWnd);
	void RightPress(CPoint pos, HWND hWnd);
	void DoubleClick(CPoint pos, HWND hWnd);
	void Move(CPoint pos);
	void Release(CPoint pos);
	void RightRelease(CPoint pos);
	void Remove(Element *currente);
	void CreateNewDiagram();
	void OpenDiagramtoProcess(HWND hWnd, Diagram *d);
};

