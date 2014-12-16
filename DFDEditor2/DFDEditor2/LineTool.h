#pragma once
class Element;
class DiagramEditor;
#include "CreateTool.h"

class LineTool : public CreateTool
{
public:
	LineTool();
	LineTool(DiagramEditor *d);
	~LineTool();
	void Press(CPoint pos, HWND hWnd);
	void CreateElement(CPoint pos, Element *&e);
	void Update(CPoint pos);
};


