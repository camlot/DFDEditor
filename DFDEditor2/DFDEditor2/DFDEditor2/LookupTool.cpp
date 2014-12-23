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
				queue<DFDProcess*> mainfathers;
				currentd->ClearOnRoute(mainfathers);
				this->ClearProcessOnRoutes(mainfathers);
				vector<Element*> elems;
				elems.push_back(e);
				d->FindStreams(elems);  // 查找路径并标记
			}
		}
		else{
			queue<DFDProcess*> mainfathers;
			currentd->ClearOnRoute(mainfathers);
			this->ClearProcessOnRoutes(mainfathers);
			d->ClearHighlight();
			de->ClearCurrentE();
			//de->ClearCurrentTool();
		}
		de->Redraw(false);
	}

}

void LookupTool::DoubleClick(CPoint pos, HWND hWnd)
{
	Diagram *d = NULL;
	Element *e = NULL;
	HWND h;
	this->Select(d, hWnd);  //根据窗口句柄找到图形
	if (d){
		de->SetCurrentD(d);  // 设置当前图形
		if (d->Find(pos, e)){
			de->SetCurrentE(e);
			if (currente->isProcess())
			{
				DFDProcess *tmpp = (DFDProcess*)currente;  // 当前双击的图元是Process
				if (tmpp->getOnRoutes())
				{
					if (tmpp->hasSubDiagram()){  // 如果Process有子图
						h = de->SearchDiagramtoProcess(currentd, tmpp);  // 查找对应子图
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
		else{
			de->ClearCurrentE();
			de->ClearCurrentTool();
		}
		de->Redraw(false);
	}
}

void LookupTool::OpenDiagramtoProcess(HWND hWnd, Diagram *d)
{
	CChildFrame *pcProcessFrame = (CChildFrame*)CChildFrame::FromHandle(hWnd);
	pcProcessFrame->MDIActivate();  // 激活窗口
	ShowWindow(hWnd, SW_SHOWNORMAL);  // 显示窗口
	de->ClearCurrentE();  // 清除当前保存的elements（上一张图的process）
	de->SetCurrentD(d);  // 设置当前图形为d
	de->Redraw(false);  // 重绘
}

void LookupTool::RightPress()
{
	currentd->ClearHighlight();
	queue<DFDProcess*> mainfathers;
	currentd->ClearOnRoute(mainfathers);
	this->ClearProcessOnRoutes(mainfathers);
}

void LookupTool::ClearProcessOnRoutes(queue<DFDProcess*>& fathers)
{
	Diagram* tmpd = NULL;
	while (!fathers.empty())
	{
		de->SearchDiagramtoProcess(tmpd, fathers.front());  // 寻找当前Process的子图
		tmpd->ClearHighlight();
		tmpd->ClearOnRoute(fathers);
		fathers.pop();
		ClearProcessOnRoutes(fathers);
	}
}
