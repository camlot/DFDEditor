#include "stdafx.h"
#include "EllipseTool.h"
//#include"Element.h"
#include"DiagramEditor.h"
#include"DFDProcess.h"

EllipseTool::EllipseTool(){

}

EllipseTool::EllipseTool(DiagramEditor *d)
{
	currente = NULL;
	currentd = NULL;
	de = d;
}


EllipseTool::~EllipseTool()
{
}
void EllipseTool::Press(CPoint pos, HWND hWnd){
	Diagram *d = NULL;
	this->Select(d, hWnd);
	if (d){
		SetCurrentD(d);
		de->SetCurrentD(d);
		de->Redraw(pos, 2, false);
	}
}

void EllipseTool::CreateElement(CPoint pos, Element *&e){
	string str = "Process";
	CString s;
	s = str.c_str();
	e = new DFDProcess(2, pos, s);
}
void EllipseTool::Update(CPoint pos){
	de->Redraw(pos, 2, false);
}
