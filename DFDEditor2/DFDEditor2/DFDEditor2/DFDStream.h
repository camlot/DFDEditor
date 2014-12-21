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
	int GetState();
	CPoint GetStart();
	CPoint GetEnd();
	void ContainsPoint(CPoint pos);
	void Onsize(CPoint pos);
	void Offset(CPoint pos, CPoint oldpos);
	bool Contains(CPoint pos);  // �ƶ���ʱ����Ҫ��mid�㣬end���start�����С�����磬Ȼ���ж��Ƿ����
	bool CompareStartElementWith(Element *e);
	bool CompareEndElementWith(Element *e);
	bool StartisInfieldof(Element *e, CPoint pos);  // ��ʼ����ͼԪe��
	bool EndisInfieldof(Element *e, CPoint pos);  // ��ֹ����ͼԪe��
	void SetStartElement(Element *e);  // ������ʼ�����ӵ�ͼԪ
	void SetEndElement(Element *e);  // ������ֹ�����ӵ�ͼԪ
	void SetControlState(int state);  // 
	Element* getStartElement();  // ���ؿ�ʼ�����ӵ�ͼԪ
	Element* getEndElement();  // ���ؽ��������ӵ�ͼԪ
};


