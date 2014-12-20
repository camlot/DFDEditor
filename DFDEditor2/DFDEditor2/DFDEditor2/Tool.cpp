#include "stdafx.h"
#include "Tool.h"
#include"DiagramEditor.h"

Tool::Tool()
{
}


Tool::~Tool()
{
}
bool Tool::hasCurrentE(){
	if (currente) return true;
	else return false;
}
void Tool::SetCurrentE(Element *e){
	this->currente = e;
}
void Tool::SetCurrentD(Diagram *d){
	this->currentd = d;
}
void Tool::ClearCurrentE(){
	this->currente = NULL;
}

/*void Tool::getDiagramEditor(DiagramEditor *d){
	this->de = d;
}*/

void Tool::Select(Diagram *&d, HWND hWnd){
	de->SearchDiagram(hWnd, d);
}

void Tool::SetType(ToolType type)
{
	this->type = type;
}

ToolType Tool::GetType()
{
	return this->type;
}
