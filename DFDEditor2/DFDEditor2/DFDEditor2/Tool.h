#pragma once
class DiagramEditor;
class Element;
class Diagram;

class Tool
{
protected:
	Diagram *currentd;
	Element *currente;
	DiagramEditor *de;
public:
	Tool();
	~Tool();
	bool hasCurrentE();
	void SetCurrentE(Element *e);
	void SetCurrentD(Diagram *d);
	void ClearCurrentE();
	//void getDiagramEditor(DiagramEditor *d);
	virtual void Press(CPoint pos, HWND hWnd){}
	virtual void Move(CPoint pos, CPoint oldpos){}
	//virtual void Move(CPoint pos, Element *currente){}
	virtual void Release(CPoint pos){}
	//virtual void Release(CPoint pos, Element *currente){}
	//virtual void RightPress(CPoint pos, HWND hWnd){}
	//virtual void RightRelease(CPoint pos){}
	//virtual void DoubleClick(CPoint pos, HWND hWnd){}
	void Select(Diagram *&d, HWND hWnd);   
};

