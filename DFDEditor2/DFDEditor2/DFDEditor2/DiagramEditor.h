#pragma once
class Tool;
class RectangleTool;
class EllipseTool;
class LineTool;
class StreamTool;
class EditTool;
class LookupTool;
class Element;
class Diagram;
class CMainFrame;
class CChildFrame;


#include<vector>
#include<map>
using namespace std;

class DiagramEditor
{
private:
	CMainFrame *cpMainFrame;
	CChildFrame *cpChildFrame;

	Element *currente;  // ָ��ǰͼԪ
	Diagram *currentd;  // ָ��ǰͼ��
	Tool *currenttool;  
	vector<Diagram*> ds;  // ��������ͼ��
	map<HWND, Diagram*> WindowtoDiagram;  // ���ھ����Ӧͼ�ε�ӳ��
	//map<Element*, Diagram*>ElementtoDiagram;
	RectangleTool *rt;  // ���ι�����
	EllipseTool *et;  //  ��Բ������
	LineTool *lt;  // ���͹�����
	StreamTool *st;  // �����߹�����
	EditTool *edt;  // �༭ͼԪ������
	LookupTool *lkt;  // ����·��������
public:
	DiagramEditor();
	~DiagramEditor();
	bool hasCurrentE();  // ��ǰ��ѡ�е�ͼԪ
	void InsertMap(HWND hWnd, Diagram *d);  // ���������ͼ��ӳ��
	void Menu(int item);  // �˵�ѡ�������������ͼԪ��
	void SetCurrentE(Element *e);  // ���õ�ǰͼԪ
	void SetCurrentD(Diagram *d);  // ���õ�ǰͼ��
	void SetCurrentTool(Tool *t);  // 
	void ClearCurrentE();
	void ClearCurrentTool();
	void AddDiagram();  // �½�ͼ��
	void SearchDiagram(HWND hWnd, Diagram *&d);  // ���ݾ�����Ҷ�Ӧͼ�β�����
	void Press(CPoint pos);
	void RightPress(CPoint pos);
	void DoubleClick(CPoint pos);
	void Release(CPoint pos);
	void RightRelease(CPoint pos);
	void Remove();
	void Redraw(CPoint pos, int type, bool highlight);
	void Redraw();
	void Highlight();
	void Move(CPoint pos);
	void Focus(CPoint pos, Element *e);
	void EndCreate(Element *e);
	//void UpdateText(CString s);
	//void UpdatePosition(CPoint pos);
	HWND SearchDiagramtoProcess(Diagram *&d);
	//void CreateDiagramtoProcess();
};

