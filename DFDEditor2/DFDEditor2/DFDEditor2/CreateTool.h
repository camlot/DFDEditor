#pragma once
class Element;

#include "Tool.h"

class CreateTool : public Tool
{
public:
	CreateTool();
	~CreateTool();
	virtual void Press(CPoint pos, HWND hWnd){}
	void Move(CPoint pos, CPoint oldpos);
	void Release(CPoint pos);
	virtual void CreateElement(CPoint pos, Element *&e);
	virtual void Update(CPoint pos);
};

