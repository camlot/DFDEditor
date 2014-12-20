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

	this->Select(d, hWnd);  //根据窗口句柄找到图形
	if (d){
		de->SetCurrentD(d);  // 设置当前图形

		if (d->Find(pos, e) && e->isSource()){  // 点中Source（查找路径终点）
			FindRoutes(d,e);  // 传入
			///////////////////////////
			/*de->SetCurrentE(e); 
			de->Highlight(); *//////////////////////////
		}
		else{  // 未点中Source
			//this->ClearCurrentE();
			//de->ClearCurrentE();  // 清空当前持有的图元
			//de->ClearCurrentTool();  // 释放当前tool
			//de->Redraw(pos, 0, false);  // 高亮

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