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
		de->Redraw(false);
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
				h = de->SearchDiagramtoProcess(currentd);  // ���Ҷ�Ӧ��ͼ
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
