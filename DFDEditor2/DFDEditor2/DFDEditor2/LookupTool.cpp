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
	type = LOOKUPTOOL;
}


LookupTool::~LookupTool()
{
}

void LookupTool::Press(CPoint pos, HWND hWnd){
	Diagram *d = NULL;
	Element *e = NULL;

	this->Select(d, hWnd);  //���ݴ��ھ���ҵ�ͼ��
	if (d){
		de->SetCurrentD(d);  // ���õ�ǰͼ��

		if (d->Find(pos, e) && e->isSource()){  // ����Source������·���յ㣩
			FindRoutes(d,e);  // ����
			///////////////////////////
			/*de->SetCurrentE(e); 
			de->Highlight(); *//////////////////////////
		}
		else{  // δ����Source
			//this->ClearCurrentE();
			//de->ClearCurrentE();  // ��յ�ǰ���е�ͼԪ
			//de->ClearCurrentTool();  // �ͷŵ�ǰtool
			//de->Redraw(pos, 0, false);  // ����

		}
	}
}

void LookupTool::DoubleClick(CPoint, HWND hWnd)
{

}


void LookupTool::FindRoutes(Diagram*d, Element *e){
	routes.push_back(e);
	d->FindStreams(routes);

}