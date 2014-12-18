#include "stdafx.h"
#include "RectangleTool.h"
//#include"Element.h"
#include"DiagramEditor.h"
#include"Diagram.h"
//#include"string.h"
#include"DFDSource.h"
//#include<cstring.h>

RectangleTool::RectangleTool(){

}

RectangleTool::RectangleTool(DiagramEditor *d)
{
	currente = NULL;
	currentd = NULL;
	de = d;
}


RectangleTool::~RectangleTool()
{
}

void RectangleTool::Press(CPoint pos, HWND hWnd){
	Diagram *d = NULL;
	this->Select(d, hWnd);
	if (d){
		//SetCurrentD(d);
		de->SetCurrentD(d);
		de->Redraw(pos, 1, false);
	}
}
void RectangleTool::CreateElement(CPoint pos, Element *&e){
	string str = "Source";
	CString s;
	s = str.c_str();
	e = new DFDSource(1, pos, s);
	currentd->SetElementforStreambyElement(e, pos);
}
void RectangleTool::Update(CPoint pos){
	de->Redraw(pos, 1, false);
}
