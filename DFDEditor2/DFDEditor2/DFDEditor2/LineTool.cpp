#include "stdafx.h"
#include "LineTool.h"
//#include"Element.h"
#include"Diagram.h"
#include"DFDDataStorage.h"
#include"DiagramEditor.h"

LineTool::LineTool(){

}

LineTool::LineTool(DiagramEditor *d)
{
	currente = NULL;
	currentd = NULL;
	de = d;
}


LineTool::~LineTool()
{
}
void LineTool::Press(CPoint pos, HWND hWnd){
	Diagram *d = NULL;
	this->Select(d, hWnd);
	if (d){
		//SetCurrentD(d);
		de->SetCurrentD(d);
		de->Redraw(pos, 3, false);
	}
}
void LineTool::CreateElement(CPoint pos, Element *&e){
	string str = "DataStorage";
	CString s;
	s = str.c_str();
	e = new DFDDataStorage(3, pos, s);
	currentd->SetElementforStreambyElement(e, pos);
}
void LineTool::Update(CPoint pos){
	de->Redraw(pos, 3, false);
}
