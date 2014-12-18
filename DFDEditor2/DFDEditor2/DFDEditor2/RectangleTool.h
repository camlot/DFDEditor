#pragma once
class Element;
class DiagramEditor;
#include "CreateTool.h"

class RectangleTool : public CreateTool
{
public:
	RectangleTool();
	RectangleTool(DiagramEditor *d);
	~RectangleTool();
	void Press(CPoint pos, HWND hWnd);
	void CreateElement(CPoint pos, Element *&e);
	void Update(CPoint pos);
};

