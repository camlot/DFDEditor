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
	int GetState();
	CPoint GetStart();
	CPoint GetEnd();
	void ContainsPoint(CPoint pos);
	void Onsize(CPoint pos);
	void Offset(CPoint pos, CPoint oldpos);
	bool Contains(CPoint pos);  // 移动的时候需要找mid点，end点和start点的最小和最大界，然后判断是否包含
	bool CompareStartElementWith(Element *e);
	bool CompareEndElementWith(Element *e);
	bool StartisInfieldof(Element *e, CPoint pos);  // 起始点在图元e中
	bool EndisInfieldof(Element *e, CPoint pos);  // 终止点在图元e中
	void SetStartElement(Element *e);  // 设置起始点连接的图元
	void SetEndElement(Element *e);  // 设置终止点连接的图元
	void SetControlState(int state);  // 
	Element* getStartElement();  // 返回开始点连接的图元
	Element* getEndElement();  // 返回结束点连接的图元
};


