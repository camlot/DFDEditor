#pragma once
#include"stdafx.h"
//#include<string>
using namespace std;

class Element
{
public:

	int type;//ͼԪ����־
	CPoint midPoint;//ͼ���м��
	CString text;//ͼԪ����

public:
	Element();
	//Element(int type, CPoint midPoint, CString text);
	~Element();
	void SetText(CString s);  // ����ͼԪ�ı�
	virtual bool Contains(CPoint pos){ return true; }  // �ж��Ƿ�ѡ��
	virtual bool hasSubDiagram(){ return true;}
	virtual void setSubDiagram(){}
	bool isProcess();  // �Ƿ��Ǽӹ�������ͼ��
	void Offset(CPoint pos);  // λ�ƣ��ƶ�ͼԪ��
};