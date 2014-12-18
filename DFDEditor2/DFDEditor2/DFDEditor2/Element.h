#pragma once
#include"stdafx.h"
//#include<string>
using namespace std;

class Element
{
public:

	int type;//图元类别标志
	CPoint midPoint;//图形中间点
	CString text;//图元名称

public:
	Element();
	//Element(int type, CPoint midPoint, CString text);
	~Element();
	void SetText(CString s);  // 设置图元文本
	virtual bool Contains(CPoint pos){ return true; }  // 判定是否被选中
	virtual bool startisInfieldof(Element *e, CPoint pos){ return false; }
	virtual bool endisInfieldof(Element *e, CPoint pos){ return false; }
	virtual bool hasSubDiagram(){ return true;}
	virtual void setSubDiagram(){}
	virtual void setStartElement(Element *e){}
	virtual void setEndElement(Element *e){}
	bool isProcess();  // 是否是加工（有子图）
	bool isStream();
	bool isSource();
	bool isDataStorage();
	void Offset(CPoint pos);  // 位移（移动图元）
};