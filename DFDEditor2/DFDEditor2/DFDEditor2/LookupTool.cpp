#include<queue>
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

		if (d->Find(pos, e) && e->isSource()){  // 点中Source
			queue<Element*> tmpElements;
			
			de->SetCurrentE(e);
			//de->Highlight();
			de->Redraw(NULL);
			
		}
		else{  // 未点中Source
			//this->ClearCurrentE();
			de->ClearCurrentE();  // 清空当前持有的图元
			de->ClearCurrentTool();  // 释放当前tool
			//de->Redraw(pos, 0, false);  // 不高亮
			de->Redraw(NULL);
		}
	}
}
void LookupTool::FindRoutes(Element *e){

}