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
	void Press(CPoint pos, HWND hWnd);  // 
	void RightPress(CPoint pos, HWND hWnd);  // 右击->修改名字
	void DoubleClick(CPoint pos, HWND hWnd);  // 双击->创建子图
	void Move(CPoint pos, CPoint oldpos);  // 移动图元
	void Release(CPoint pos);
	void RightRelease(CPoint pos);
	void GotoFatherWnd();
	void Remove(Element *currente);
	void CreateNewDiagram();
	void OpenDiagramtoProcess(HWND hWnd, Diagram *d);  // 打开Process的子图
};
