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
	map<Element*, HWND> process2Diagram;   // 

public:
	Diagram();
	~Diagram();
	void Add(Element* e);  // 添加图元
	bool Find(CPoint pos, Element *&e);  // 根据坐标查找图元
	HWND SearchWnd(Element *e);  // 查找图元（Process）对应的窗口句柄
	void SetElementforStreambyElement(Element *e, CPoint pos); // e是除stream类型其他类型时使用
	void SetStartElementforStream(Stream *se, CPoint pos);  // e是stream类型时使用
	void SetEndElementforStream(Stream *se, CPoint pos);
	void Remove(Element *e);  // 从图形中删除图元e
	//void DrawDiagram(map<CPoint*, int>&drawdiagram);
	void DrawDiagram(vector<CPoint>&poss, vector<int>&types, vector<CString>&strs,CPoint startmidend[][3]);
	//void DrawDiagram(vector<CPoint*>&poss, vector<int>&types, vector<CString>&strs, CPoint startmidend[][3]);
	void InsertMap(Element *e, HWND hWnd);  // 向Map中插入<Process,HWND>对
	int FindStreams(Element* currente, queue<Stream*>& elemq); // 根据结束图元查找所有以该图元为终点的路径
	void FindStreams(vector<Element*>& elemq);  // 查找路径-找到该图中的连接线
	void Highlight(CDC *pDC);
	void ClearHighlight();
};


