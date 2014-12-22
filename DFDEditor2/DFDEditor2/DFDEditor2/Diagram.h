#pragma once
class Element;
class Stream;
#pragma warning (disable:4786)
#include<vector>
#include <queue>
#include<map>
#include<list>
//#include<string>

using std::vector;
using std::map;
using std::list;
using std::string;
using std::queue;

class Diagram
{
private:
	vector<Element*> elems;  // ����ͼ���е�ͼԪ
	map<Element*, HWND> process2Diagram;   // 

public:
	Diagram();
	~Diagram();
	void Add(Element* e);  // ���ͼԪ
	bool Find(CPoint pos, Element *&e);  // �����������ͼԪ
	HWND SearchWnd(Element *e);  // ����ͼԪ��Process����Ӧ�Ĵ��ھ��
	void SetElementforStreambyElement(Element *e, CPoint pos); // e�ǳ�stream������������ʱʹ��
	void SetStartElementforStream(Stream *se, CPoint pos);  // e��stream����ʱʹ��
	void SetEndElementforStream(Stream *se, CPoint pos);
	void Remove(Element *e);  // ��ͼ����ɾ��ͼԪe
	//void DrawDiagram(map<CPoint*, int>&drawdiagram);
	void DrawDiagram(vector<CPoint>&poss, vector<int>&types, vector<CString>&strs,CPoint startmidend[][3]);
	//void DrawDiagram(vector<CPoint*>&poss, vector<int>&types, vector<CString>&strs, CPoint startmidend[][3]);
	void InsertMap(Element *e, HWND hWnd);  // ��Map�в���<Process,HWND>��
	int FindStreams(Element* currente, queue<Stream*>& elemq); // ���ݽ���ͼԪ���������Ը�ͼԪΪ�յ��·��
	void FindStreams(vector<Element*>& elemq);  // ����·��-�ҵ���ͼ�е�������
	void Highlight(CDC *pDC);
	void ClearHighlight();
};


