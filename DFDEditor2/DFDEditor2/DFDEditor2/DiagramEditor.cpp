#include "stdafx.h"
#include "DiagramEditor.h"
#include"Tool.h"
#include"RectangleTool.h"
#include"EllipseTool.h"
#include"LineTool.h"
#include"StreamTool.h"
#include"EditTool.h"
#include"LookupTool.h"
#include"DFDStream.h"
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
	//cpDoc = NULL;
	//cpView = NULL;

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
	this->ClearCurrentE();
	switch (item){
	case 1: 
		SetCurrentTool(rt);
		break;
	case 2: SetCurrentTool(et);
		break;
	case 3: SetCurrentTool(lt);
		break;
	case 4: SetCurrentTool(st);
		break;
	case 5: SetCurrentTool(lkt);
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
	CDFDEditor2Doc *cpDoc = (CDFDEditor2Doc*)cpChildFrame->GetActiveDocument();
	Diagram *d = new Diagram();
	HWND hWnd = cpChildFrame->m_hWnd;

	ds.push_back(d);  // 存入图形数组中
	this->InsertMap(hWnd, d);
	SetCurrentD(d);
	currenttool->SetCurrentD(d);
	cpDoc->SetDiagram(d);
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
	if (!hWnd) AfxMessageBox(_T("Top Window Not Found!"));

	//currenttool->Select(d, hWnd);
	//SetCurrentD(d);
	currenttool->Press(pos, hWnd);
}
void DiagramEditor::RightPress(CPoint pos){
	//SetCurrentTool(edt);
	cpMainFrame = (CMainFrame*)AfxGetMainWnd();
	cpChildFrame = (CChildFrame*)cpMainFrame->GetActiveFrame();
	HWND hWnd = cpChildFrame->m_hWnd;
	if (!hWnd) AfxMessageBox(_T("Top Window Not Found!"));

	//edt->RightPress(pos, hWnd);
	EditTool *newet = (EditTool*)currenttool;
	newet->RightPress(pos, hWnd);
}
void DiagramEditor::DoubleClick(CPoint pos){
	cpMainFrame = (CMainFrame*)AfxGetMainWnd();
	cpChildFrame = (CChildFrame*)cpMainFrame->GetActiveFrame();
	HWND hWnd = cpChildFrame->m_hWnd;

	if (!hWnd) AfxMessageBox(_T("Top Window Not Found!"));
	
	if (currenttool->GetType() == EDITTOOL)
	{
		EditTool *newet = (EditTool*)currenttool;
		newet->DoubleClick(pos, hWnd);
	}
	else if (currenttool->GetType() == LOOKUPTOOL)
	{
		LookupTool *newlkt = (LookupTool*)currenttool;
		newlkt->DoubleClick(pos, hWnd);
	}

}
void DiagramEditor::Release(CPoint pos){
	if (currenttool->GetType() != LOOKUPTOOL)
	{
		currenttool->Release(pos);
		ClearCurrentTool();
	}
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
/*void DiagramEditor::Redraw(CPoint pos,int type, bool highlight){
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
}*/
void DiagramEditor::Redraw(bool original){
	cpMainFrame = (CMainFrame*)AfxGetMainWnd();
	cpChildFrame = (CChildFrame*)cpMainFrame->GetActiveFrame();
	CDFDEditor2Doc *cpDoc = (CDFDEditor2Doc*)cpChildFrame->GetActiveDocument();
	CDFDEditor2View *cpView = (CDFDEditor2View*)cpChildFrame->GetActiveView();
	CDC *pDC = new CDC();
	//cpView->SetPos(pos);
	cpDoc->SetOri(original);
	//cpDoc->SetDiagram(currentd);
	//cpView->GetDocument()->d = currentd;
	cpDoc->SetDiagram(currentd);  // 修改当前活动窗口文档类Doc中的对应图形
	cpDoc->SetElement(currente);  // 修改当前活动窗口文档类Doc中的对应活动图元
	cpView->Invalidate();  // 重绘当前活动窗口
	//cpView->UpdateWindow();
	//cpView->OnDraw(pDC);
}
void DiagramEditor::Draw(Element *doce, Diagram *docd, bool original, CPoint pos, CDC *pDC){
	//cpChildFrame = (CChildFrame*)cpMainFrame->GetActiveFrame();
	//cpDoc = (CDFDEditor2Doc*)cpChildFrame->GetActiveDocument();
	//cpView = (CDFDEditor2View*)cpChildFrame->GetActiveView();
	if (!currente && original && (currenttool == rt || currenttool == et || currenttool == lt || currenttool == st)){
		this->DrawOriginal(pDC, pos);  //需要各种createtool的头一个操作是clearelement 
	}
	if (docd){   // 遍历当前窗口对应的图形，画出所有图元
		this->SetCurrentD(docd);
		CPen *pen = new CPen(PS_SOLID, 1, RGB(0, 0, 0));
		pDC->SelectObject(pen);
		vector<CPoint>poss;
		vector<int>types;
		vector<CString>strs;
		vector<CPoint>::iterator it1;
		vector<int>::iterator it2;
		vector<CString>::iterator it3;
		CPoint startmidend[20][3];
		docd->DrawDiagram(poss, types, strs, startmidend);
		int i = 0;
		for (it1 = poss.begin(), it2 = types.begin(), it3 = strs.begin(); it1 != poss.end(); it1++, it2++, it3++){
			switch ((*it2)){
			case 1: 
				pDC->Rectangle((*it1).x - 60, (*it1).y - 40, (*it1).x + 60, (*it1).y + 40);
				//pDC->TextOutW((*it1).x - 20, (*it1).y, (*it3));
				break;
			case 2: 
				pDC->Ellipse((*it1).x - 50, (*it1).y - 50, (*it1).x + 50, (*it1).y + 50);
				//pDC->TextOutW((*it1).x - 20, (*it1).y, (*it3));
				break;
			case 3: 
				pDC->MoveTo((*it1).x - 60, (*it1).y + 20);
				pDC->LineTo((*it1).x + 60, (*it1).y + 20);
				pDC->MoveTo((*it1).x - 60, (*it1).y + 40);
				pDC->LineTo((*it1).x + 60, (*it1).y + 40);
				//pDC->TextOutW((*it1).x - 20, (*it1).y, (*it3));
				break;
			case 4:
				pDC->MoveTo(startmidend[i][0].x, startmidend[i][0].y);
				pDC->LineTo(startmidend[i][0].x, startmidend[i][1].y);
				pDC->LineTo(startmidend[i][2].x, startmidend[i][1].y);
				pDC->LineTo(startmidend[i][2].x, startmidend[i][2].y);
				//pDC->TextOutW((*it1).x - 20, (*it1).y, (*it3));
				i++;
				break;
			default:;
			}
			pDC->TextOutW((*it1).x - 20, (*it1).y - 10, (*it3));
		}
	}
	if (doce){
		this->SetCurrentE(doce);
		this->Highlight(pDC);
	}
	//if (currente && cpChildFrame == (CChildFrame*)cpMainFrame->GetActiveFrame()){
		//this->Highlight(pDC);
	//}

}
void DiagramEditor::DrawOriginal(CDC *pDC,CPoint pos){
	//if (highlight){
		//pen = new CPen(PS_SOLID, 5, RGB(255, 0, 0));
		//MemDC.SelectObject(pen);
	//}
	if (currenttool == rt){
		pDC->Rectangle(pos.x - 60, pos.y - 40, pos.x + 60, pos.y + 40);
	}
	else if (currenttool == et){
		pDC->Ellipse(pos.x - 50, pos.y - 50, pos.x + 50, pos.y + 50);
	}
	else if (currenttool == lt){
		pDC->MoveTo(pos.x - 60, pos.y + 20);
		pDC->LineTo(pos.x + 60, pos.y + 20);
		pDC->MoveTo(pos.x - 60, pos.y + 40);
		pDC->LineTo(pos.x + 60, pos.y + 40);
	}
	else if (currenttool == st){
		pDC->MoveTo(pos.x - 60, pos.y - 40);
		pDC->LineTo(pos.x - 60, pos.y);
		pDC->LineTo(pos.x + 60, pos.y);
		pDC->LineTo(pos.x + 60, pos.y + 40);
	}
	else{}
	/*switch (type){
	case 1: pDC->Rectangle(pos.x - 60, pos.y - 40, pos.x + 60, pos.y + 40);
		break;
	case 2: pDC->Ellipse(pos.x - 50, pos.y - 50, pos.x + 50, pos.y + 50);
		break;
	case 3: pDC->MoveTo(pos.x - 60, pos.y + 20);
		pDC->LineTo(pos.x + 60, pos.y + 20);
		pDC->MoveTo(pos.x - 60, pos.y + 40);
		pDC->LineTo(pos.x + 60, pos.y + 40);
		break;
	case 4: pDC->MoveTo(pos.x - 60, pos.y - 40);
		pDC->LineTo(pos.x - 60, pos.y);
		pDC->LineTo(pos.x + 60, pos.y);
		pDC->LineTo(pos.x + 60, pos.y + 40);
		break;
	default:;
	}*/
}
/*void DiagramEditor::Highlight(){
	this->Redraw(currente->midPoint, currente->type, true);
}*/
void DiagramEditor::Highlight(CDC *pDC){
	CPen *pen = new CPen(PS_SOLID, 5, RGB(255, 0, 0));
	pDC->SelectObject(pen);
	CPoint mp = currente->getmidPoint();
	if (currente->isSource()){
		pDC->Rectangle(mp.x - 60, mp.y - 40, mp.x + 60, mp.y + 40);
	}
	else if (currente->isProcess()){
		pDC->Ellipse(mp.x - 50, mp.y - 50, mp.x + 50, mp.y + 50);
	}
	else if (currente->isDataStorage()){
		pDC->MoveTo(mp.x - 60, mp.y + 20);
		pDC->LineTo(mp.x + 60, mp.y + 20);
		pDC->MoveTo(mp.x - 60, mp.y + 40);
		pDC->LineTo(mp.x + 60, mp.y + 40);
	}
	else{
		Stream *tempse = (Stream*)currente;
		CPoint start = tempse->getStart();
		CPoint end = tempse->getEnd();
		CPoint mid = tempse->getmidPoint();
		pDC->MoveTo(start.x, start.y);
		pDC->LineTo(start.x, mid.y);
		pDC->LineTo(end.x, mid.y);
		pDC->LineTo(end.x, end.y);
		this->Focus(pDC);
	}
	pDC->TextOutW(mp.x - 20, mp.y - 10, currente->getText());
}
void DiagramEditor::Move(CPoint pos, CPoint oldpos){
	currenttool->Move(pos, oldpos);
}
void DiagramEditor::Focus(CDC *pDC){
	Stream *tempse = (Stream*)currente;
	CPen *pen = new CPen(PS_SOLID, 2, RGB(255, 0, 0));
	pDC->SelectObject(pen);
	pDC->Rectangle(tempse->getStart().x - 5, tempse->getStart().y - 5, tempse->getStart().x + 5, tempse->getStart().y + 5);
	//pen->CreatePen(PS_SOLID, 2, RGB(0, 0, 255));
	pen = new CPen(PS_SOLID, 2, RGB(0, 0, 255));
	pDC->SelectObject(pen);
	pDC->Rectangle(tempse->getEnd().x - 5, tempse->getEnd().y - 5, tempse->getEnd().x + 5, tempse->getEnd().y + 5);
}
void DiagramEditor::EndCreate(Element *e){
	//currentd->add(e);
	//currenttool->SetCurrentE(e);
	this->SetCurrentE(e);
	//Highlight();
	this->Redraw(false);
	//CDFDEditor2View *cpView = (CDFDEditor2View*)cpChildFrame->GetActiveView();
	//cpView->Invalidate();
}
/*void DiagramEditor::UpdateText(CString s){
	currente->SetText(s);
}
void DiagramEditor::UpdatePosition(CPoint pos){
	currente->Offset(pos);
}*/
HWND DiagramEditor::SearchDiagramtoProcess(Diagram *&d){
	HWND hWnd = currentd->SearchWnd(currente);
	if(hWnd) this->SearchDiagram(hWnd, d);  // d是返回值
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