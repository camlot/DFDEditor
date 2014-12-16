#include "stdafx.h"
#include "StreamTool.h"
#include"DiagramEditor.h"
//#include"Element.h"
#include"DFDStream.h"

StreamTool::StreamTool()
{
}

StreamTool::StreamTool(DiagramEditor *d){
	de = d;
}

StreamTool::~StreamTool()
{
}

void StreamTool::Press(CPoint pos,HWND hWnd){
	Diagram *d = NULL;
	this->Select(d, hWnd);
	if (d){
		SetCurrentD(d);
		de->SetCurrentD(d);
		de->Redraw(pos, 4, false);
	}
}

void StreamTool::CreateElement(CPoint pos, Element *&e){
	string str = "Stream";
	CString s;
	s = str.c_str();
	e = new Stream(4, pos, s);
}

void StreamTool::Update(CPoint pos){
	de->Redraw(pos, 4, false);
}