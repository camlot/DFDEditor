#include "stdafx.h"
#include "StreamTool.h"
#include"DiagramEditor.h"
#include"Diagram.h"
#include"DFDStream.h"

StreamTool::StreamTool()
{
}

StreamTool::StreamTool(DiagramEditor *d){
	de = d;
	type = CREATTOOL;
}

StreamTool::~StreamTool()
{
}

void StreamTool::Press(CPoint pos,HWND hWnd){
	Diagram *d = NULL;
	this->Select(d, hWnd);
	if (d){
		//SetCurrentD(d);
		de->SetCurrentD(d);
		de->Redraw(pos, 4, false);
	}
}

void StreamTool::CreateElement(CPoint pos, Element *&e){
	string str = "Stream";
	CString s;
	CPoint p;
	s = str.c_str();
	e = new Stream(4, pos, s);
	if (e->isStream()){
		p.SetPoint(pos.x - 60, pos.y - 40);
		Stream *tempse = (Stream*)e;
		currentd->SetStartElementforStream(tempse, p);
		p.SetPoint(pos.x + 60, pos.y + 40);
		currentd->SetEndElementforStream(tempse, p);
	}
}

void StreamTool::Update(CPoint pos){
	de->Redraw(pos, 4, false);
}