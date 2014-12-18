#pragma once
class Element;
class DiagramEditor;
#include "CreateTool.h"

class StreamTool : public CreateTool
{
public:
	StreamTool();
	StreamTool(DiagramEditor *d);
	~StreamTool();
	void Press(CPoint pos, HWND hWnd);
	void CreateElement(CPoint pos, Element *&e);
	void Update(CPoint pos);
};

