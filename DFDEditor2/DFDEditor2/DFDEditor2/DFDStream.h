#pragma once
#include "Element.h"
#include"stdafx.h"
class Stream : public Element
{
private:
	Element *startE;  // 起始点连接的图元
	Element *endE;  // 终止点连接的图元
	//int a; //长轴
	//int b; //短轴
	CPoint start;
	CPoint end;
	int controlstate; //0未选中控制点，1左控制点，2右控制点
public:
	Stream(int type, CPoint midPoint, CString text);
	~Stream();
	int getState();
	CPoint getStart();
	CPoint getEnd();
	void ContainsPoint(CPoint pos);
	bool Onsize(CPoint pos);
	void Offset(CPoint pos0);
	bool Contains(CPoint pos);
	bool startisInfieldof(Element *e, CPoint pos);
	bool endisInfieldof(Element *e, CPoint pos);
	void setStartElement(Element *e);
	void setEndElement(Element *e);
	void setControstate(int state);
	Element* getStartElement();  // 返回开始点连接的图元
	Element* getEndElement();  // 返回结束点连接的图元
};


