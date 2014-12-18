#include "stdafx.h"
#include "DFDProcess.h"


DFDProcess::DFDProcess(int type, CPoint midPoint, CString text)
{
	this->type = type;
	this->midPoint = midPoint;
	this->text = text;
	this->radix = 50;
	subDiagramState = false;
}


DFDProcess::~DFDProcess()
{
}

bool DFDProcess::hasSubDiagram(){  // 返回是否有子图
	return this->subDiagramState;
}
void DFDProcess::setSubDiagram(){
	subDiagramState = true;
}
bool DFDProcess::Contains(CPoint pos){
	if (pos.x >= this->midPoint.x - radix && pos.x <= this->midPoint.x + radix &&
		pos.y >= this->midPoint.y - radix && pos.y <= this->midPoint.y + radix){
		return true;
	}
	else return false;
}