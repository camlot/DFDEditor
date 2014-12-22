#include "stdafx.h"
#include "LookupTool.h"
#include "DiagramEditor.h"
#include "Diagram.h"
#include"Element.h"
#include "DFDProcess.h"
#include"MainFrm.h"
#include"ChildFrm.h"

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
	currentd->ClearHighlight();
	this->Select(d, hWnd);  //根据窗口句柄找到图形
	if (d){
		de->SetCurrentD(d);  // 设置当前图形
		if (d->Find(pos, e)){
			de->SetCurrentE(e);
			if (e->isSource())  // 点中Source（查找路径终点）
			{
				vector<Element*> elems;
				elems.push_back(e);
				d->FindStreams(elems);  // 查找路径并标记
			}
		}
		de->Redraw(false);
	}
}

void LookupTool::DoubleClick(CPoint, HWND hWnd)
{
	HWND h;
	if (currente->isProcess())
	{
		DFDProcess *tmpp = (DFDProcess*)currente;  // 当前双击的图元是Process
		if (tmpp->getOnRoutes())
		{

			if (tmpp->hasSubDiagram()){  // 如果Process有子图
				h = de->SearchDiagramtoProcess(currentd);  // 查找对应子图
				this->OpenDiagramtoProcess(h, currentd);   // 打开当前子图
				vector<Element*> endElems;
				currentd->FindEndElements(endElems);
				currentd->FindStreams(endElems);
				de->Redraw(false);
			}
			else AfxMessageBox(_T("This process do not have sub-diagram!"));  // 如果没有子图弹窗提示没有
		}
	}

}

void LookupTool::OpenDiagramtoProcess(HWND hWnd, Diagram *d)
{
	CChildFrame *pcProcessFrame = (CChildFrame*)CChildFrame::FromHandle(hWnd);
	pcProcessFrame->MDIActivate();
	ShowWindow(hWnd, SW_SHOWNORMAL);

	//this->SetCurrentD(d);
	//de->ClearCurrentE();
	de->SetCurrentD(d);
	de->Redraw(false);
}
