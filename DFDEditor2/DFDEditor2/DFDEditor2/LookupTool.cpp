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
				queue<DFDProcess*> mainfathers;
				currentd->ClearOnRoute(mainfathers);
				this->ClearProcessOnRoutes(mainfathers);
				vector<Element*> elems;
				elems.push_back(e);
				d->FindStreams(elems);  // ����·�������
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
	this->Select(d, hWnd);  //���ݴ��ھ���ҵ�ͼ��
	if (d){
		de->SetCurrentD(d);  // ���õ�ǰͼ��
		if (d->Find(pos, e)){
			de->SetCurrentE(e);
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
	pcProcessFrame->MDIActivate();  // �����
	ShowWindow(hWnd, SW_SHOWNORMAL);  // ��ʾ����
	de->ClearCurrentE();  // �����ǰ�����elements����һ��ͼ��process��
	de->SetCurrentD(d);  // ���õ�ǰͼ��Ϊd
	de->Redraw(false);  // �ػ�
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
		de->SearchDiagramtoProcess(tmpd, fathers.front());  // Ѱ�ҵ�ǰProcess����ͼ
		tmpd->ClearHighlight();
		tmpd->ClearOnRoute(fathers);
		fathers.pop();
		ClearProcessOnRoutes(fathers);
	}
}
