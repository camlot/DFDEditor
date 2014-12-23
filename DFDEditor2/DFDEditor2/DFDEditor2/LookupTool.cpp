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
	this->Select(d, hWnd);  //���ݴ��ھ���ҵ�ͼ��
	if (d){
		de->SetCurrentD(d);  // ���õ�ǰͼ��
		if (d->Find(pos, e)){
			de->SetCurrentE(e);
			if (e->isSource())  // ����Source������·���յ㣩
			{
				vector<Element*> elems;
				elems.push_back(e);
				d->FindStreams(elems);  // ����·�������
			}
		}
		else{
			//this->ClearCurrentE();
			de->ClearCurrentE();
			de->ClearCurrentTool();
			//de->Redraw(pos, 0, false);
			//de->Redraw(false);
		}
		de->Redraw(false);
		/*queue<DFDProcess*> mainfathers;
		currentd->ClearOnRoute(mainfathers);
		this->ClearProcessOnRoutes(mainfathers);
		de->SetCurrentE(e);*/
	}
}

void LookupTool::DoubleClick(CPoint, HWND hWnd)
{
	HWND h;
	if (currente->isProcess())
	{
		DFDProcess *tmpp = (DFDProcess*)currente;  // ��ǰ˫����ͼԪ��Process
		if (tmpp->getOnRoutes())
		{
			if (tmpp->hasSubDiagram()){  // ���Process����ͼ
				h = de->SearchDiagramtoProcess(currentd, tmpp);  // ���Ҷ�Ӧ��ͼ
				this->OpenDiagramtoProcess(h, currentd);   // �򿪵�ǰ��ͼ
				vector<Element*> endElems;
				currentd->FindEndElements(endElems);
				currentd->FindStreams(endElems);
				de->Redraw(false);
			}
			else AfxMessageBox(_T("This process do not have sub-diagram!"));  // ���û����ͼ������ʾû��
		}
		//queue<DFDProcess*> mainfathers;
		//currentd->ClearOnRoute(mainfathers);
		//this->ClearProcessOnRoutes(mainfathers);
	}

}

void LookupTool::OpenDiagramtoProcess(HWND hWnd, Diagram *d)
{
	CChildFrame *pcProcessFrame = (CChildFrame*)CChildFrame::FromHandle(hWnd);
	pcProcessFrame->MDIActivate();
	ShowWindow(hWnd, SW_SHOWNORMAL);
	de->ClearCurrentE();

	de->SetCurrentD(d);
	de->Redraw(false);
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
	//vector<DFDProcess*>::iterator it;
	Diagram* tmpd = NULL;
	while (!fathers.empty())
	{
		if (fathers.front()->hasSubDiagram())
		{
			de->SearchDiagramtoProcess(tmpd, fathers.front());  // Ѱ�ҵ�ǰProcess����ͼ
			tmpd->ClearHighlight();
			tmpd->ClearOnRoute(fathers);
			fathers.pop();
			ClearProcessOnRoutes(fathers);
		}
	}
}
