#include "stdafx.h"
#include "LookupTool.h"
#include "DiagramEditor.h"
#include "Diagram.h"
#include"Element.h"

LookupTool::LookupTool(){

}

LookupTool::LookupTool(DiagramEditor *d)
{
	de = d;
}


LookupTool::~LookupTool()
{
}

void LookupTool::Press(CPoint pos, HWND hWnd){
	Diagram *d = NULL;
	Element *e = NULL;

	this->Select(d, hWnd);
	if (d){
		//this->SetCurrentD(d);
		de->SetCurrentD(d);
		de->SetCurrentD(d);

		if (d->Find(pos, e)){  // 点中某一图元
			//this->SetCurrentE(e);
			de->SetCurrentE(e);
			de->Highlight();
		}
		else{
			//this->ClearCurrentE();
			de->ClearCurrentE();
			de->ClearCurrentTool();
			de->Redraw(pos, 0, false);
		}
	}
}
void LookupTool::FindRoutes(Element *e){

}