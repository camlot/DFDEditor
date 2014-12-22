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

	Element *currente;  // 指向当前图元
	Diagram *currentd;  // 指向当前图形
	Tool *currenttool;  
	vector<Diagram*> ds;  // 保存所有图形
	map<HWND, Diagram*> WindowtoDiagram;  // 窗口句柄对应图形的映射
	//map<Element*, Diagram*>ElementtoDiagram;
	RectangleTool *rt;  // 矩形工具类
	EllipseTool *et;  //  椭圆工具类
	LineTool *lt;  // 线型工具类
	StreamTool *st;  // 连接线工具类
	EditTool *edt;  // 编辑图元工具类
	LookupTool *lkt;  // 查找路径工具类
public:
	DiagramEditor();
	~DiagramEditor();
	bool hasCurrentE();  // 当前有选中的图元
	void InsertMap(HWND hWnd, Diagram *d);  // 创建句柄与图形映射
	void Menu(int item);  // 菜单选项（创建何种类型图元）
	void SetCurrentE(Element *e);  // 设置当前图元
	void SetCurrentD(Diagram *d);  // 设置当前图形
	void SetCurrentTool(Tool *t);  // 
	void ClearCurrentE();
	void ClearCurrentTool();
	void AddDiagram();  // 新建图形
	void SearchDiagram(HWND hWnd, Diagram *&d);  // 根据句柄查找对应图形并返回
	void Press(CPoint pos);  // 鼠标左键按下
	void DoubleClick(CPoint pos);  // 鼠标左键双击
	void Release(CPoint pos);  // 鼠标左键释放
	void RightPress(CPoint pos);  // 鼠标右键按下
	void RightRelease(CPoint pos);  // 鼠标右键释放
	void ExitEdit();
	void Remove();  // 删除图元操作
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

