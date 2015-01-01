#pragma once
#include"stdafx.h"
//#include<string>
using namespace std;

class Element
{
protected:
	bool isHighlight;  // �Ƿ������־
	int type;//ͼԪ����־
	CPoint midPoint;//ͼ���м��
	CString text;//ͼԪ����
public:
	Element();
	//Element(int type, CPoint midPoint, CString text);
	~Element();
	CPoint GetMidPoint();  // ��ȡͼԪ�е�
	CString GetText();  // ��ȡͼԪ�ı�
	void SetText(CString s);  // ����ͼԪ�ı�
	void SetHighlightFlag(bool isHighlight);
	bool GetHighlightFlag();
	virtual bool Contains(CPoint pos){ return true; }  // �ж�������Ƿ���ͼԪ�ڲ�
	//virtual bool startisInfieldof(Element *e, CPoint pos){ return false; }
	//virtual bool endisInfieldof(Element *e, CPoint pos){ return false; }

	//virtual bool hasSubDiagram(){ return true;}
	//virtual void setSubDiagram(){}
	//virtual void setStartElement(Element *e){}
	//virtual void setEndElement(Element *e){}
	bool isProcess();  // �Ƿ��Ǽӹ�������ͼ��

	bool isStream();   // �Ƿ������������ߣ�
	bool isSource();  // �Ƿ���Դ��������ͼ���յ㣩
	bool isDataStorage();  // �Ƿ��Ǵ洢
	virtual void Offset(CPoint pos, CPoint oldpos);  // λ�ƣ��ƶ�ͼԪ��
};