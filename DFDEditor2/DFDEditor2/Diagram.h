#pragma once
class Element;
#pragma warning (disable:4786)
#include<vector>
#include<map>
#include<list>
//#include<string>

using std::vector;
using std::map;
using std::list;
using std::string;

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
	void Remove(Element *currente);
	//void DrawDiagram(map<CPoint*, int>&drawdiagram);
	void DrawDiagram(vector<CPoint*>&poss, vector<int>&types, vector<CString>&strs);
	void InsertMap(Element *e, HWND hWnd);
};


