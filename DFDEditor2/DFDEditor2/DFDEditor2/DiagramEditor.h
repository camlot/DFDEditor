#pragma once
class Tool;
class RectangleTool;
class EllipseTool;
class LineTool;
class StreamTool;
class EditTool;
class LookupTool;
class Element;
class Diagram;
class CMainFrame;
class CChildFrame;


#include<vector>
#include<map>
using namespace std;

class DiagramEditor
{
private:
	CMainFrame *cpMainFrame;
	CChildFrame *cpChildFrame;

	Element *currente;  // 指向当前图元
	Diagram *currentd;  // 指向当前图形
	Tool *currenttool;  
	vector<Diagram*> ds;  // 保存所有图形
	map<HWND, Diagram*> WindowtoDiagram;
	//map<Element*, Diagram*>ElementtoDiagram;
	RectangleTool *rt;  // 矩形工具类
	EllipseTool *et;  //  椭圆工具类
	LineTool *lt;  // 线型工具类
	StreamTool *st;  // 连接线工具类
	EditTool *edt;  // 编辑图元工具类
	LookupTool *lkt;  // 查找路径工具类
public:
	DiagramEditor();
	~DiagramEditor();
	bool hasCurrentE();  // 当前有选中的图元
	void InsertMap(HWND hWnd, Diagram *d);  // 
	void Menu(int item);  // 菜单选项（创建何种类型图元）
	void SetCurrentE(Element *e);  // 设置当前图元
	void SetCurrentD(Diagram *d);  // 设置当前图形
	void SetCurrentTool(Tool *t);  // 
	void ClearCurrentE();
	void ClearCurrentTool();
	void AddDiagram();
	void SearchDiagram(HWND hWnd, Diagram *&d);
	void Press(CPoint pos);
	void RightPress(CPoint pos);
	void DoubleClick(CPoint pos);
	void Release(CPoint pos);
	void RightRelease(CPoint pos);
	void Remove();
	void Redraw(CPoint pos, int type, bool highlight);
	void Redraw();
	void Highlight();
	void Move(CPoint pos);
	void Focus(CPoint pos, Element *e);
	void EndCreate(Element *e);
	//void UpdateText(CString s);
	//void UpdatePosition(CPoint pos);
	HWND SearchDiagramtoProcess(Diagram *&d);
	//void CreateDiagramtoProcess();
};

