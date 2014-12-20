#pragma once
#include "Element.h"
#include"stdafx.h"
class Stream : public Element
{
private:
	Element *startE;  // ��ʼ�����ӵ�ͼԪ
	Element *endE;  // ��ֹ�����ӵ�ͼԪ
	//int a; //����
	//int b; //����
	CPoint start;
	CPoint end;
	int controlstate; //0δѡ�п��Ƶ㣬1����Ƶ㣬2�ҿ��Ƶ�
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
	Element* getStartElement();  // ���ؿ�ʼ�����ӵ�ͼԪ
	Element* getEndElement();  // ���ؽ��������ӵ�ͼԪ
};


