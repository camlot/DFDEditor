#include "stdafx.h"
#include "CreateTool.h"
//#include"Element.h"
#include"Diagram.h"
#include"DiagramEditor.h"

CreateTool::CreateTool()
{
}


CreateTool::~CreateTool()
{
}

//void CreateTool::Press(CPoint pos){
	//CDC *pDC = new CDC();

	//de->Redraw(pos,1);
//}
void CreateTool::Move(CPoint pos){
	this->Update(pos);
}
void CreateTool::Release(CPoint pos){
	Element *e;
	this->CreateElement(pos, e);
	currentd->add(e);
	this->SetCurrentE(e);
	de->EndCreate(e);
}
