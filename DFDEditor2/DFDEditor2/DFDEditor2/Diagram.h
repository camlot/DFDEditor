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
	vector<Element*> elems;  // 保存图形中的图元
	map<Element*, HWND> proess2Diagram;

public:
	Diagram();
	~Diagram();
	void add(Element* e);
	bool Find(CPoint pos, Element *&e);
	bool FindStream(Element *e, list<Element*>&ElementQueue);
	HWND SearchWnd(Element *e);
	void SetElementforStreambyElement(Element *e, CPoint pos); // e是除stream类型其他类型时使用
	void SetStartElementforStream(Stream *se, CPoint pos);  // e是stream类型时使用
	void SetEndElementforStream(Stream *se, CPoint pos);
	void Remove(Element *currente);
	//void DrawDiagram(map<CPoint*, int>&drawdiagram);
	void DrawDiagram(vector<CPoint>&poss, vector<int>&types, vector<CString>&strs,CPoint startmidend[][3]);
	//void DrawDiagram(vector<CPoint*>&poss, vector<int>&types, vector<CString>&strs, CPoint startmidend[][3]);
	void InsertMap(Element *e, HWND hWnd);
	void FindStreams(queue<Element*>& elemq);  // 找到连接线
};


