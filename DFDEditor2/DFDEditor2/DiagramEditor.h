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

	Element *currente;
	Diagram *currentd;
	Tool *currenttool;
	vector<Diagram*>ds;
	map<HWND, Diagram*>WindowtoDiagram;
	//map<Element*, Diagram*>ElementtoDiagram;
	RectangleTool *rt;
	EllipseTool *et;
	LineTool *lt;
	StreamTool *st;
	EditTool *edt;
	LookupTool *lkt;
public:
	DiagramEditor();
	~DiagramEditor();
	bool hasCurrentE();
	void InsertMap(HWND hWnd, Diagram *d);
	void Menu(int item);
	void SetCurrentE(Element *e);
	void SetCurrentD(Diagram *d);
	void SetCurrentTool(Tool *t);
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

