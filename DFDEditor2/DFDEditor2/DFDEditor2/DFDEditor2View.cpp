
// DFDEditor2View.cpp : CDFDEditor2View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "DFDEditor2.h"
#endif

#include "DFDEditor2Doc.h"
#include "DFDEditor2View.h"
#include"MainFrm.h"
#include"DiagramEditor.h"
#include"Diagram.h"

#include<vector>
#ifdef _DEBUG
#define new DEBUG_NEW
#endif

using std::vector;


// CDFDEditor2View

IMPLEMENT_DYNCREATE(CDFDEditor2View, CView)

BEGIN_MESSAGE_MAP(CDFDEditor2View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_32771, &CDFDEditor2View::OnRectangle)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_COMMAND(ID_32773, &CDFDEditor2View::OnEllipse)
	ON_COMMAND(ID_32774, &CDFDEditor2View::OnDataStorage)
	ON_COMMAND(ID_32775, &CDFDEditor2View::OnStream)
	ON_WM_RBUTTONDOWN()
	ON_WM_RBUTTONUP()
	ON_WM_LBUTTONDBLCLK()
	ON_COMMAND(ID_32776, &CDFDEditor2View::OnLookup)
END_MESSAGE_MAP()

// CDFDEditor2View 构造/析构

CDFDEditor2View::CDFDEditor2View()
{
	// TODO:  在此处添加构造代码
	x = 0; y = 0; type = 0;
	pressState = 0;
	highlight = false;
}

CDFDEditor2View::~CDFDEditor2View()
{
}

BOOL CDFDEditor2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CDFDEditor2View 绘制

void CDFDEditor2View::OnDraw(CDC* pDC)
{
	CDFDEditor2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	CPen *pen;
	CDC MemDC; //首先定义一个显示设备对象 
	CBitmap MemBitmap;//定义一个位图对象 
	CRect rect;
	this->GetWindowRect(&rect);

	//随后建立与屏幕显示兼容的内存显示设备 
	MemDC.CreateCompatibleDC(NULL);
	//这时还不能绘图，因为没有地方画 ^_^ 
	//下面建立一个与屏幕显示兼容的位图，至于位图的大小嘛，可以用窗口的大小 
	
	MemBitmap.CreateCompatibleBitmap(pDC, rect.Width(),rect.Height());

	//将位图选入到内存显示设备中 
	//只有选入了位图的内存显示设备才有地方绘图，画到指定的位图上 
	CBitmap *pOldBit = MemDC.SelectObject(&MemBitmap);

	//先用背景色将位图清除干净，这里我用的是白色作为背景 
	//你也可以用自己应该用的颜色 
	MemDC.FillSolidRect(0, 0, rect.Width(), rect.Height(), RGB(255, 255, 255));

	//绘图 
	//MemDC.MoveTo(……);
	//MemDC.LineTo(……);













	// TODO:  在此处为本机数据添加绘制代码
	if (highlight){
		pen = new CPen(PS_SOLID, 5, RGB(255, 0, 0));
		MemDC.SelectObject(pen);
	}
	switch (type){
	case 1: MemDC.Rectangle(x - 60, y - 40, x + 60, y + 40);
		break;
	case 2: MemDC.Ellipse(x - 50, y - 50, x + 50, y + 50);
		break;
	case 3: MemDC.MoveTo(x - 60, y + 20);
		MemDC.LineTo(x + 60, y + 20);
		MemDC.MoveTo(x - 60, y + 40);
		MemDC.LineTo(x + 60, y + 40);
		break;
	case 4: MemDC.MoveTo(x - 60, y - 40);
		MemDC.LineTo(x, y - 40);
		MemDC.LineTo(x, y + 40);
		MemDC.LineTo(x + 60, y + 40);
		break;
	default:;
	}
	if (pDoc->d){   // 遍历当前窗口对应的图形，画出所有图元
		pen = new CPen(PS_SOLID, 1, RGB(0, 0, 0));
		MemDC.SelectObject(pen);
		vector<CPoint*>poss;
		vector<int>types;
		vector<CString>strs;
		vector<CPoint*>::iterator it1;
		vector<int>::iterator it2;
		vector<CString>::iterator it3;
		pDoc->d->DrawDiagram(poss, types, strs);
		for (it1 = poss.begin(), it2 = types.begin(), it3 = strs.begin(); it1 != poss.end(); it1++,it2++,it3++){
			switch ((*it2)){
			case 1: MemDC.Rectangle((*it1)->x - 60, (*it1)->y - 40, (*it1)->x + 60, (*it1)->y + 40);
				MemDC.TextOutW((*it1)->x - 20, (*it1)->y - 20, (*it3));
				break;
			case 2: MemDC.Ellipse((*it1)->x - 50, (*it1)->y - 50, (*it1)->x + 50, (*it1)->y + 50);
				MemDC.TextOutW((*it1)->x - 20, (*it1)->y - 20, (*it3));
				break;
			case 3: MemDC.MoveTo((*it1)->x - 60, (*it1)->y + 20);
				MemDC.LineTo((*it1)->x + 60, (*it1)->y + 20);
				MemDC.MoveTo((*it1)->x - 60, (*it1)->y + 40);
				MemDC.LineTo((*it1)->x + 60, (*it1)->y + 40);
				MemDC.TextOutW((*it1)->x - 20, (*it1)->y - 20, (*it3));
				break;
			case 4: MemDC.MoveTo((*it1)->x - 60, (*it1)->y - 40);
				MemDC.LineTo((*it1)->x, (*it1)->y - 40);
				MemDC.LineTo((*it1)->x, (*it1)->y + 40);
				MemDC.LineTo((*it1)->x + 60, (*it1)->y + 40);
				MemDC.TextOutW((*it1)->x - 20, (*it1)->y - 20, (*it3));
				break;
			default:;
			}
		}
	}

	type = 0;

	//将内存中的图拷贝到屏幕上进行显示 
	pDC->BitBlt(0, 0, rect.Width(), rect.Height(), &MemDC, 0, 0, SRCCOPY);

	//绘图完成后的清理 
	MemBitmap.DeleteObject();
	MemDC.DeleteDC();
}


// CDFDEditor2View 打印

BOOL CDFDEditor2View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CDFDEditor2View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  添加额外的打印前进行的初始化过程
}

void CDFDEditor2View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  添加打印后进行的清理过程
}


// CDFDEditor2View 诊断

#ifdef _DEBUG
void CDFDEditor2View::AssertValid() const
{
	CView::AssertValid();
}

void CDFDEditor2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CDFDEditor2Doc* CDFDEditor2View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDFDEditor2Doc)));
	return (CDFDEditor2Doc*)m_pDocument;
}
#endif //_DEBUG

void CDFDEditor2View::SetXY(int x, int y, int type, bool highlight){
	this->x = x;
	this->y = y;
	this->type = type;
	this->highlight = highlight;
}

// CDFDEditor2View 消息处理程序


void CDFDEditor2View::OnRectangle()
{
	// TODO:  在此添加命令处理程序代码
	//CDFDEditor2Doc *pDoc = GetDocument();
	//pDoc->de->Menu(1);
	CMainFrame *pMainFrame = (CMainFrame*)AfxGetMainWnd();
	pMainFrame->de->Menu(1);
}


void CDFDEditor2View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值
	pressState = 1;
	CMainFrame *pMainFrame = (CMainFrame*)AfxGetMainWnd();
	pMainFrame->de->Press(point);
	//CView::OnLButtonDown(nFlags, point);
}


void CDFDEditor2View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值

	//CView::OnLButtonUp(nFlags, point);
	CMainFrame *pMainFrame = (CMainFrame*)AfxGetMainWnd();
	pMainFrame->de->Release(point);
	pressState = 0;
}


void CDFDEditor2View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值

	//CView::OnMouseMove(nFlags, point);
	if (pressState == 1){
		CMainFrame *pMainFrame = (CMainFrame*)AfxGetMainWnd();
		pMainFrame->de->Move(point);
	}
}


void CDFDEditor2View::OnEllipse()
{
	// TODO:  在此添加命令处理程序代码
	CMainFrame *pMainFrame = (CMainFrame*)AfxGetMainWnd();
	pMainFrame->de->Menu(2);
}


void CDFDEditor2View::OnDataStorage()
{
	// TODO:  在此添加命令处理程序代码
	CMainFrame *pMainFrame = (CMainFrame*)AfxGetMainWnd();
	pMainFrame->de->Menu(3);
}


void CDFDEditor2View::OnStream()
{
	// TODO:  在此添加命令处理程序代码
	CMainFrame *pMainFrame = (CMainFrame*)AfxGetMainWnd();
	pMainFrame->de->Menu(4);
}

void CDFDEditor2View::OnLookup()
{
	// TODO:  在此添加命令处理程序代码
	CMainFrame *pMainFrame = (CMainFrame*)AfxGetMainWnd();
	pMainFrame->de->Menu(5);
}

void CDFDEditor2View::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值

	//CView::OnRButtonDown(nFlags, point);
	CMainFrame *pMainFrame = (CMainFrame*)AfxGetMainWnd();
	pMainFrame->de->RightPress(point);
}


void CDFDEditor2View::OnRButtonUp(UINT nFlags, CPoint point)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值

	//CView::OnRButtonUp(nFlags, point);
	CMainFrame *pMainFrame = (CMainFrame*)AfxGetMainWnd();
	pMainFrame->de->RightRelease(point);
}


void CDFDEditor2View::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值

	//CView::OnLButtonDblClk(nFlags, point);
	CMainFrame *pMainFrame = (CMainFrame*)AfxGetMainWnd();
	pMainFrame->de->DoubleClick(point);
}


