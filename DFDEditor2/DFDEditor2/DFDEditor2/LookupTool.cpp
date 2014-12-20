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

		if (d->Find(pos, e) && e->isSource()){  // ����Source
			queue<Element*> tmpElements;
			
			de->SetCurrentE(e);
			//de->Highlight();
			de->Redraw(NULL);
			
		}
		else{  // δ����Source
			//this->ClearCurrentE();
			de->ClearCurrentE();  // ��յ�ǰ���е�ͼԪ
			de->ClearCurrentTool();  // �ͷŵ�ǰtool
			//de->Redraw(pos, 0, false);  // ������
			de->Redraw(NULL);
		}
	}
}
void LookupTool::FindRoutes(Element *e){

}