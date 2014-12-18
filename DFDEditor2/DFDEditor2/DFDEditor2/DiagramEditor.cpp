#include "stdafx.h"
#include "DiagramEditor.h"
#include"Tool.h"
#include"RectangleTool.h"
#include"EllipseTool.h"
#include"LineTool.h"
#include"StreamTool.h"
#include"EditTool.h"
#include"LookupTool.h"
#include"Element.h"
#include"Diagram.h"
#include"MainFrm.h"
#include"ChildFrm.h"
#include"DFDEditor2View.h"
#include"DFDEditor2Doc.h"

DiagramEditor::DiagramEditor()
{
	currente = NULL;
	currentd = NULL;
	currenttool = NULL;
	cpMainFrame = NULL;
	cpChildFrame = NULL;

	rt = new RectangleTool(this);
	et = new EllipseTool(this);
	lt = new LineTool(this);
	st = new StreamTool(this);
	edt = new EditTool(this);
	lkt = new LookupTool(this);

	currenttool = edt;
}


DiagramEditor::~DiagramEditor()
{

}
bool DiagramEditor::hasCurrentE(){
	if (currente) return true;
	else return false;
}
void DiagramEditor::InsertMap(HWND hWnd, Diagram *d){
	WindowtoDiagram.insert(pair<HWND, Diagram*>(hWnd, d));
}

void DiagramEditor::Menu(int item){
	switch (item){
	case 1: SetCurrentTool(rt);
		break;
	case 2: SetCurrentTool(et);
		break;
	case 3: SetCurrentTool(lt);
		break;
	case 4: SetCurrentTool(st);
		break;
	default:;
	}
}
void DiagramEditor::SetCurrentE(Element *e){
	currente = e;
	rt->SetCurrentE(e);
	et->SetCurrentE(e);
	lt->SetCurrentE(e);
	st->SetCurrentE(e);
	edt->SetCurrentE(e);
	lkt->SetCurrentE(e);
}
void DiagramEditor::SetCurrentD(Diagram *d){
	currentd = d;
	rt->SetCurrentD(d);
	et->SetCurrentD(d);
	lt->SetCurrentD(d);
	st->SetCurrentD(d);
	edt->SetCurrentD(d);
	lkt->SetCurrentD(d);
}
void DiagramEditor::SetCurrentTool(Tool *t){
	currenttool = t;
}
void DiagramEditor::ClearCurrentE(){
	currente = NULL;
	rt->ClearCurrentE();
	et->ClearCurrentE();
	lt->ClearCurrentE();
	st->ClearCurrentE();
	edt->ClearCurrentE();
	lkt->ClearCurrentE();
}
void DiagramEditor::ClearCurrentTool(){
	currenttool = edt;
}
void DiagramEditor::AddDiagram(){
	cpMainFrame = (CMainFrame*)AfxGetMainWnd();
	cpChildFrame = (CChildFrame*)cpMainFrame->GetActiveFrame();
	Diagram *d = new Diagram();
	HWND hWnd = cpChildFrame->m_hWnd;

	ds.push_back(d);
	this->InsertMap(hWnd, d);
	SetCurrentD(d);
	currenttool->SetCurrentD(d);
}
void DiagramEditor::SearchDiagram(HWND hWnd, Diagram *&d){
	map<HWND, Diagram*>::iterator it;
	for (it = WindowtoDiagram.begin(); it != WindowtoDiagram.end(); it++){
		if (it->first == hWnd){
			d = it->second;
			//AfxMessageBox(_T("Window Found."));
			return;
		}
	}
	AfxMessageBox(_T("Window Not Found."));
}
void DiagramEditor::Press(CPoint pos){
	//Diagram *d = NULL;

	cpMainFrame = (CMainFrame*)AfxGetMainWnd();
	cpChildFrame = (CChildFrame*)cpMainFrame->GetActiveFrame();
	HWND hWnd = cpChildFrame->m_hWnd;
	if (!hWnd) AfxMessageBox(_T("Top Window Not found!"));

	//currenttool->Select(d, hWnd);
	//SetCurrentD(d);
	currenttool->Press(pos, hWnd);
}
void DiagramEditor::RightPress(CPoint pos){
	//SetCurrentTool(edt);
	cpMainFrame = (CMainFrame*)AfxGetMainWnd();
	cpChildFrame = (CChildFrame*)cpMainFrame->GetActiveFrame();
	HWND hWnd = cpChildFrame->m_hWnd;
	if (!hWnd) AfxMessageBox(_T("Top Window Not found!"));

	//edt->RightPress(pos, hWnd);
	EditTool *newet = (EditTool*)currenttool;
	newet->RightPress(pos, hWnd);
}
void DiagramEditor::DoubleClick(CPoint pos){
	cpMainFrame = (CMainFrame*)AfxGetMainWnd();
	cpChildFrame = (CChildFrame*)cpMainFrame->GetActiveFrame();
	HWND hWnd = cpChildFrame->m_hWnd;
	if (!hWnd) AfxMessageBox(_T("Top Window Not found!"));
	
	EditTool *newet = (EditTool*)currenttool;
	//currenttool->DoubleClick(pos, hWnd);
	newet->DoubleClick(pos, hWnd);
}
void DiagramEditor::Release(CPoint pos){
	currenttool->Release(pos);
	ClearCurrentTool();
}
void DiagramEditor::RightRelease(CPoint pos){
	if (hasCurrentE()){
		EditTool *newet = (EditTool*)currenttool;
		newet->RightRelease(pos);
		ClearCurrentTool();
	}
}
void DiagramEditor::Remove(){

}
void DiagramEditor::Redraw(CPoint pos,int type, bool highlight){

	CDFDEditor2View *cpView = (CDFDEditor2View*)cpChildFrame->GetActiveView();
	cpView->SetXY(pos.x, pos.y, type, highlight);
	cpView->GetDocument()->d = currentd;
	cpView->Invalidate();

}
void DiagramEditor::Redraw(){
	cpMainFrame = (CMainFrame*)AfxGetMainWnd();
	cpChildFrame = (CChildFrame*)cpMainFrame->GetActiveFrame();
	CDFDEditor2View *cpView = (CDFDEditor2View*)cpChildFrame->GetActiveView();
	cpView->GetDocument()->d = currentd;
	cpView->Invalidate();
}
void DiagramEditor::Highlight(){
	this->Redraw(currente->midPoint, currente->type, true);
}
void DiagramEditor::Move(CPoint pos){
	currenttool->Move(pos);
}
void DiagramEditor::Focus(CPoint pos, Element *e){

}
void DiagramEditor::EndCreate(Element *e){
	//currentd->add(e);
	//currenttool->SetCurrentE(e);
	this->SetCurrentE(e);
	Highlight();
	CDFDEditor2View *cpView = (CDFDEditor2View*)cpChildFrame->GetActiveView();
	cpView->Invalidate();
}
/*void DiagramEditor::UpdateText(CString s){
	currente->SetText(s);
}
void DiagramEditor::UpdatePosition(CPoint pos){
	currente->Offset(pos);
}*/
HWND DiagramEditor::SearchDiagramtoProcess(Diagram *&d){
	HWND hWnd = currentd->SearchWnd(currente);
	if(hWnd) this->SearchDiagram(hWnd, d);  // d «∑µªÿ÷µ
	return hWnd;
	/*map<Element*, Diagram*>::iterator it;
	for (it = ElementtoDiagram.begin(); it != ElementtoDiagram.end(); it++){
		if (it->first == currente){
			d = it->second;
		}
		break;
	}*/
}
/*void DiagramEditor::CreateDiagramtoProcess(){
	Diagram *oldD = currentd;
	::SendMessage(::AfxGetMainWnd()->m_hWnd, WM_COMMAND, ID_FILE_NEW, 0);
	cpMainFrame = (CMainFrame*)AfxGetMainWnd();
	cpChildFrame = (CChildFrame*)cpMainFrame->GetActiveFrame();
	HWND hWnd = cpChildFrame->m_hWnd;
	if (!hWnd) AfxMessageBox(_T("Top Window Not found!"));

	oldD->InsertMap(currente, hWnd);
	currente->setSubDiagram();
	ClearCurrentE();
}*/