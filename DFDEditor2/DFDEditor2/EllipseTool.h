#pragma once
class Element;
class DiagramEditor;
#include "CreateTool.h"

class EllipseTool : public CreateTool
{
public:
	EllipseTool();
	EllipseTool(DiagramEditor *d);
	~EllipseTool();
	void Press(CPoint pos, HWND hWnd);
	void CreateElement(CPoint pos, Element *&e);
	void Update(CPoint pos);
};


