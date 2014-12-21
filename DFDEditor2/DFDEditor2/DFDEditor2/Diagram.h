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
	void add(Element* e);
	bool Find(CPoint pos, Element *&e);
	int FindStreams(Element* currente, queue<Stream*>& elemq); // ���ݽ���ͼԪ���������Ը�ͼԪΪ�յ��·��
	HWND SearchWnd(Element *e);
	void SetElementforStreambyElement(Element *e, CPoint pos); // e�ǳ�stream������������ʱʹ��
	void SetStartElementforStream(Stream *se, CPoint pos);  // e��stream����ʱʹ��
	void SetEndElementforStream(Stream *se, CPoint pos);
	void Remove(Element *currente);
	//void DrawDiagram(map<CPoint*, int>&drawdiagram);
	void DrawDiagram(vector<CPoint>&poss, vector<int>&types, vector<CString>&strs,CPoint startmidend[][3]);
	//void DrawDiagram(vector<CPoint*>&poss, vector<int>&types, vector<CString>&strs, CPoint startmidend[][3]);
	void InsertMap(Element *e, HWND hWnd);
	void FindStreams(vector<Element*>& elemq);  // �ҵ�������
};


