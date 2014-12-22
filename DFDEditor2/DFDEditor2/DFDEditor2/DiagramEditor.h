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
class CDFDEditor2Doc;
class CDFDEditor2View;


#include<vector>
#include<map>
using namespace std;

class DiagramEditor
{
private:
	CMainFrame *cpMainFrame;
	CChildFrame *cpChildFrame;
	//CDFDEditor2Doc *cpDoc;
	//CDFDEditor2View *cpView;

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
	void Press(CPoint pos);  // ����������
	void DoubleClick(CPoint pos);  // ������˫��
	void Release(CPoint pos);  // �������ͷ�
	void RightPress(CPoint pos);  // ����Ҽ�����
	void RightRelease(CPoint pos);  // ����Ҽ��ͷ�
	void ExitEdit();
	void Remove();  // ɾ��ͼԪ����
	//void Redraw(CPoint pos, int type, bool highlight);
	//void Redraw();
	void Draw(Element *doce, Diagram *docd, bool original, CPoint pos, CDC *pDC);
	void Redraw(bool original);
	void DrawOriginal(CDC *pDC,CPoint pos);
	//void Highlight();
	void Highlight(CDC *pDC);
	void Move(CPoint pos, CPoint oldpos);
	void Focus(CDC *pDC);
	void EndCreate(Element *e);
	//void UpdateText(CString s);
	//void UpdatePosition(CPoint pos);
	HWND SearchDiagramtoProcess(Diagram *&d);
	//void CreateDiagramtoProcess();
};

