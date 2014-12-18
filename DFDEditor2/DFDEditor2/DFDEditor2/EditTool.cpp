#include "stdafx.h"
#include "EditTool.h"
#include"Tool.h"
#include"Element.h"
#include"DFDStream.h"
#include"Diagram.h"
#include"DiagramEditor.h"
#include"Dlg.h"
#include"DFDEditor2.h"
#include"MainFrm.h"
#include"ChildFrm.h"

EditTool::EditTool(){

}

EditTool::EditTool(DiagramEditor *d)
{
	currente = NULL;
	currentd = NULL;
	de = d;
}


EditTool::~EditTool()
{
}

void EditTool::Press(CPoint pos, HWND hWnd){
	Diagram *d = NULL;
	Element *e = NULL;

	this->Select(d, hWnd);
	if (d){
		//this->SetCurrentD(d);
		de->SetCurrentD(d);

		if (d->Find(pos, e)){  // 点中某一图元
			//this->SetCurrentE(e);
			if (e->isStream()) //如果点击的是流
			{
				Stream *str = (Stream*)e;
				str->ContainsPoint(pos); //如果点击到流的端点，则根据端点设置相应状态位
			}
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
void EditTool::RightPress(CPoint pos, HWND hWnd){
	Diagram *d = NULL;
	Element *e = NULL;

	this->Select(d, hWnd);
	if (d){
		//this->SetCurrentD(d);
		de->SetCurrentD(d);
		d->Find(pos, e);
		if (e){
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
void EditTool::DoubleClick(CPoint pos, HWND hWnd){
	Diagram *d = NULL;
	Element *e = NULL;
	HWND h = NULL;

	this->Select(d, hWnd);
	if (d){
		//this->SetCurrentD(d);
		de->SetCurrentD(d);
		d->Find(pos, e);
		if (e){
			//this->SetCurrentE(e);
			de->SetCurrentE(e);
			de->Highlight();
			d = NULL;
			if (e->isProcess()){
				if (e->hasSubDiagram()){
					h = de->SearchDiagramtoProcess(d);
					this->OpenDiagramtoProcess(h, d);
				}
				//h = de->SearchDiagramtoProcess(d);
				//if (h && d) OpenDiagramtoProcess(h, d);
				else this->CreateNewDiagram();
			}
		}
		else{
			//this->ClearCurrentE();
			de->ClearCurrentE();
			de->ClearCurrentTool();
			de->Redraw(pos, 0, false);
		}
	}
}
void EditTool::Move(CPoint pos){
	if (this->hasCurrentE() && de->hasCurrentE()){
		if (currente->isStream())
		{
			Stream *t = (Stream*)currente;
			if (t->getState()!=0)
			{
				t->Onsize(pos);
				de->Highlight();
			}	
			else {
				currente->Offset(pos);
				de->Highlight();
			}
		}
		
		else{
			currente->Offset(pos);
			de->Highlight();
		}
		
	}
	if (currente && currente->isStream()){
		
		Stream *tempse = (Stream*)currente;
		currentd->SetStartElementforStream(tempse, tempse->getStart());
		currentd->SetEndElementforStream(tempse, tempse->getEnd());
		
	}
	else if(currente){
		currentd->SetElementforStreambyElement(currente, pos);
	}
}
void EditTool::Release(CPoint pos){
	/*if (currente->isStream()){
		CPoint p;
		p.SetPoint(pos.x - 60, pos.y - 40);
		currentd->SetStartElementforStream(currente, p);
		p.SetPoint(pos.x + 60, pos.y + 40);
		currentd->SetEndElementforStream(currente, p);
	}
	else{
		currentd->SetElementforStreambyElement(currente, pos);
	}*/

	if (currente && currente->isStream()){
		Stream *tempse = (Stream*)currente;
	     tempse->setControstate(0);
	}
	
}
void EditTool::RightRelease(CPoint pos){
	CDlg dlg; 
	int response = dlg.DoModal();
	if (response == IDOK){
		//de->UpdateText(dlg.newtext);
		currente->SetText(dlg.newtext);
	}
	de->Highlight();

}
void EditTool::Remove(Element *currente){

}
void EditTool::CreateNewDiagram(){
	Diagram *oldD = currentd;
	::SendMessage(::AfxGetMainWnd()->m_hWnd, WM_COMMAND, ID_FILE_NEW, 0);
	CMainFrame *pMainFrame = (CMainFrame*)AfxGetMainWnd();
	CChildFrame *pChildFrame = (CChildFrame*)pMainFrame->GetActiveFrame();
	HWND hWnd = pChildFrame->m_hWnd;
	if (!hWnd) AfxMessageBox(_T("Top Window Not found!"));

	oldD->InsertMap(currente, hWnd);
	currente->setSubDiagram();
	//this->ClearCurrentE();
	de->ClearCurrentE();
}
void EditTool::OpenDiagramtoProcess(HWND hWnd, Diagram *d){
	CChildFrame *pcProcessFrame = (CChildFrame*)CChildFrame::FromHandle(hWnd);
	pcProcessFrame->MDIActivate();
	ShowWindow(hWnd, SW_SHOWNORMAL);

	//this->SetCurrentD(d);
	de->SetCurrentD(d);
	de->Redraw();
}