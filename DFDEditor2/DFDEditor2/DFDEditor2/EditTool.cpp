#include "stdafx.h"
#include "EditTool.h"
#include"Tool.h"
#include"Element.h"
#include"DFDStream.h"
#include"DFDProcess.h"
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
	type = EDITTOOL;
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
			//de->Highlight();
			de->Redraw(false);
		}
		else{
			//this->ClearCurrentE();
			de->ClearCurrentE();
			de->ClearCurrentTool();
			//de->Redraw(pos, 0, false);
			de->Redraw(false); // 释放highlight
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
			//de->Highlight();
			de->Redraw(false);
		}
		else{
			//this->ClearCurrentE();
			de->ClearCurrentE();
			de->ClearCurrentTool();
			//de->Redraw(pos, 0, false);
			de->Redraw(false);
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
			//de->Highlight();
			//de->Redraw(false);
			//d = NULL;

			if (currente->isProcess()){ // 如果该图元是Process
				DFDProcess *temppe = (DFDProcess*)currente;  //
				if (temppe->hasSubDiagram()){
					h = de->SearchDiagramtoProcess(currentd);  //
					this->OpenDiagramtoProcess(h, currentd);   //
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
			//de->Redraw(pos, 0, false);
			de->Redraw(false);
		}
	}
}
void EditTool::Move(CPoint pos, CPoint oldpos){
	if (this->hasCurrentE() && de->hasCurrentE()){
		if (currente->isStream())
		{
			Stream *t = (Stream*)currente;
			if (t->GetState()!=0)
			{
				t->Onsize(pos);
				//de->Highlight();
				de->Redraw(false);
			}	
			else {
				currente->Offset(pos, oldpos);
				//de->Highlight();
				de->Redraw(false);
			}
		}
		else{
			queue<Stream*> streamq;
			currente->Offset(pos, oldpos);
			int startNum = currentd->FindStreams(currente, streamq);  // 查找与原移动图元连接的连接线
			while (startNum > 0)
			{
				//streamq.front()->SetStartElement(currente);
				//streamq.front()->SetStart(streamq.front()->GetStart() + (pos - oldpos));
				streamq.front()->StartFollowElement(currente);
				streamq.pop();
				startNum--;
			}
			while (!streamq.empty())
			{
				//streamq.front()->SetEndElement(currente);
				//streamq.front()->SetEnd(streamq.front()->GetEnd() + (pos - oldpos));
				streamq.front()->EndFollowElement(currente);
				streamq.pop();
			}
			//de->Highlight();
			de->Redraw(false);
		}
		
	}
	/*if (currente && currente->isStream()){
		
		Stream *tempse = (Stream*)currente;
		currentd->SetStartElementforStream(tempse, tempse->getStart());
		currentd->SetEndElementforStream(tempse, tempse->getEnd());
		
	}
	else if(currente){
		currentd->SetElementforStreambyElement(currente, pos);
	}*/
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
		currentd->SetStartElementforStream(tempse, tempse->GetStart());
		currentd->SetEndElementforStream(tempse, tempse->GetEnd());

	}
	else if (currente){
		currentd->SetElementforStreambyElement(currente, currente->GetMidPoint());
	}
	else{}
	if (currente && currente->isStream()){
		Stream *tempse = (Stream*)currente;
	     tempse->SetControlState(0);
	}
	de->Redraw(false);
}
void EditTool::RightRelease(CPoint pos){
	CDlg dlg; 
	int response = dlg.DoModal();
	if (response == IDOK){
		//de->UpdateText(dlg.newtext);
		currente->SetText(dlg.newtext);
	}
	//de->Highlight();
	de->Redraw(false);

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
	DFDProcess *temppe = (DFDProcess*)currente;
	temppe->setSubDiagram();
	//this->ClearCurrentE();
	de->ClearCurrentE();
}
void EditTool::OpenDiagramtoProcess(HWND hWnd, Diagram *d){
	CChildFrame *pcProcessFrame = (CChildFrame*)CChildFrame::FromHandle(hWnd);
	pcProcessFrame->MDIActivate();
	ShowWindow(hWnd, SW_SHOWNORMAL);

	//this->SetCurrentD(d);
	de->ClearCurrentE();
	de->SetCurrentD(d);
	de->Redraw(false);
}