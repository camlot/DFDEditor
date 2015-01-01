#pragma once
#include"stdafx.h"
//#include<string>
using namespace std;

class Element
{
protected:
	bool isHighlight;  // 是否高亮标志
	int type;//图元类别标志
	CPoint midPoint;//图形中间点
	CString text;//图元名称
public:
	Element();
	//Element(int type, CPoint midPoint, CString text);
	~Element();
	CPoint GetMidPoint();  // 获取图元中点
	CString GetText();  // 获取图元文本
	void SetText(CString s);  // 设置图元文本
	void SetHighlightFlag(bool isHighlight);
	bool GetHighlightFlag();
	virtual bool Contains(CPoint pos){ return true; }  // 判定传入点是否在图元内部
	//virtual bool startisInfieldof(Element *e, CPoint pos){ return false; }
	//virtual bool endisInfieldof(Element *e, CPoint pos){ return false; }

	//virtual bool hasSubDiagram(){ return true;}
	//virtual void setSubDiagram(){}
	//virtual void setStartElement(Element *e){}
	//virtual void setEndElement(Element *e){}
	bool isProcess();  // 是否是加工（有子图）

	bool isStream();   // 是否是流（连接线）
	bool isSource();  // 是否是源（查找子图的终点）
	bool isDataStorage();  // 是否是存储
	virtual void Offset(CPoint pos, CPoint oldpos);  // 位移（移动图元）
};