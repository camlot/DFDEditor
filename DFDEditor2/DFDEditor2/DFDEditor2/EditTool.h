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
	void Press(CPoint pos, HWND hWnd);  // 单击
	void RightPress(CPoint pos, HWND hWnd);  // 右击->修改名字
	void DoubleClick(CPoint pos, HWND hWnd);  // 双击->创建子图
	void Move(CPoint pos, CPoint oldpos);  // 移动图元
	void Release(CPoint pos);  // 鼠标左键释放
	void RightRelease(CPoint pos);  // 鼠标右键释放
	void GotoFatherWnd();  // 打开父窗口（对应ESC）
	void Remove();  // 删除图元（对应DELETE）
	void CreateNewDiagram();  // 创建新图形
	void OpenDiagramtoProcess(HWND hWnd, Diagram *d);  // 打开Process的子图
};
