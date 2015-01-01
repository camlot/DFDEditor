
// DFDEditor2View.cpp : CDFDEditor2View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
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
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_32771, &CDFDEditor2View::OnSource)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_COMMAND(ID_32773, &CDFDEditor2View::OnProcess)
	ON_COMMAND(ID_32774, &CDFDEditor2View::OnDataStorage)
	ON_COMMAND(ID_32775, &CDFDEditor2View::OnStream)
	ON_WM_RBUTTONDOWN()
	ON_WM_RBUTTONUP()
	ON_WM_LBUTTONDBLCLK()
	ON_COMMAND(ID_32776, &CDFDEditor2View::OnLookup)
	ON_WM_KEYDOWN()
	ON_WM_CLOSE()
END_MESSAGE_MAP()

// CDFDEditor2View ����/����

CDFDEditor2View::CDFDEditor2View()
{
	// TODO:  �ڴ˴����ӹ������
	//x = 0; y = 0; type = 0;
	pressState = 0;
	//pos = NULL;
	//highlight = false;
}

CDFDEditor2View::~CDFDEditor2View()
{
}

BOOL CDFDEditor2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CDFDEditor2View ����

void CDFDEditor2View::OnDraw(CDC* pDC)
{
	CDFDEditor2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	//CPen *pen;
	//CDC MemDC; //���ȶ���һ����ʾ�豸���� 
	//CBitmap MemBitmap;//����һ��λͼ���� 
	//CRect rect;
	//this->GetWindowRect(&rect);

	/*
	//���������Ļ��ʾ���ݵ��ڴ���ʾ�豸 
	MemDC.CreateCompatibleDC(NULL);
	//��ʱ�����ܻ�ͼ����Ϊû�еط��� ^_^ 
	//���潨��һ������Ļ��ʾ���ݵ�λͼ������λͼ�Ĵ�С������ô��ڵĴ�С 
	
	MemBitmap.CreateCompatibleBitmap(pDC, rect.Width(),rect.Height());

	//��λͼѡ�뵽�ڴ���ʾ�豸�� 
	//ֻ��ѡ����λͼ���ڴ���ʾ�豸���еط���ͼ������ָ����λͼ�� 
	CBitmap *pOldBit = MemDC.SelectObject(&MemBitmap);

	//���ñ���ɫ��λͼ����ɾ����������õ��ǰ�ɫ��Ϊ���� 
	//��Ҳ�������Լ�Ӧ���õ���ɫ 
	MemDC.FillSolidRect(0, 0, rect.Width(), rect.Height(), RGB(255, 255, 255));

	//��ͼ 
	//MemDC.MoveTo(����);
	//MemDC.LineTo(����);
	*/


	// TODO:  �ڴ˴�Ϊ�����������ӻ��ƴ���
	/*if (highlight){
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
		MemDC.LineTo(x-60, y);
		MemDC.LineTo(x + 60, y);
		MemDC.LineTo(x + 60, y + 40);
		break;
	default:;
	}*/
	CMainFrame *pMainFrame = (CMainFrame*)AfxGetMainWnd();
	pMainFrame->de->Draw(GetDocument()->e, GetDocument()->d, pDoc->original, pDoc->pos, pDC);
	
	/*if (pDoc->d){   // ������ǰ���ڶ�Ӧ��ͼ�Σ���������ͼԪ
		pen = new CPen(PS_SOLID, 1, RGB(0, 0, 0));
		pDC->SelectObject(pen);
		vector<CPoint*>poss;
		vector<int>types;
		vector<CString>strs;
		vector<CPoint*>::iterator it1;
		vector<int>::iterator it2;
		vector<CString>::iterator it3;
		CPoint startmidend[20][3];
		pDoc->d->DrawDiagram(poss, types, strs, startmidend);
		int i = 0;
		for (it1 = poss.begin(), it2 = types.begin(), it3 = strs.begin(); it1 != poss.end(); it1++,it2++,it3++){
			switch ((*it2)){
			case 1: pDC->Rectangle((*it1)->x - 60, (*it1)->y - 40, (*it1)->x + 60, (*it1)->y + 40);
				pDC->TextOutW((*it1)->x - 20, (*it1)->y - 20, (*it3));
				break;
			case 2: pDC->Ellipse((*it1)->x - 50, (*it1)->y - 50, (*it1)->x + 50, (*it1)->y + 50);
				pDC->TextOutW((*it1)->x - 20, (*it1)->y - 20, (*it3));
				break;
			case 3: pDC->MoveTo((*it1)->x - 60, (*it1)->y + 20);
				pDC->LineTo((*it1)->x + 60, (*it1)->y + 20);
				pDC->MoveTo((*it1)->x - 60, (*it1)->y + 40);
				pDC->LineTo((*it1)->x + 60, (*it1)->y + 40);
				pDC->TextOutW((*it1)->x - 20, (*it1)->y - 20, (*it3));
				break;
			case 4: //pDC->MoveTo((*it1)->x - 60, (*it1)->y - 40);
				//pDC->LineTo((*it1)->x, (*it1)->y - 40);
				//pDC->LineTo((*it1)->x, (*it1)->y + 40);
				//pDC->LineTo((*it1)->x + 60, (*it1)->y + 40);
				//pDC->TextOutW((*it1)->x - 20, (*it1)->y - 20, (*it3));
				//pDC->MoveTo()
				pDC->MoveTo(startmidend[i][0].x, startmidend[i][0].y);
				pDC->LineTo(startmidend[i][0].x, startmidend[i][1].y);
				pDC->LineTo(startmidend[i][2].x, startmidend[i][1].y);
				pDC->LineTo(startmidend[i][2].x, startmidend[i][2].y);
				pDC->TextOutW((*it1)->x - 20, (*it1)->y - 20, (*it3));
				i++;
				break;
			default:;
			}
		}
	}*/
	

	//type = 0;

	//���ڴ��е�ͼ��������Ļ�Ͻ�����ʾ 
	//pDC->BitBlt(0, 0, rect.Width(), rect.Height(), &MemDC, 0, 0, SRCCOPY);

	//��ͼ��ɺ������ 
	//MemBitmap.DeleteObject();
	//MemDC.DeleteDC();
}


// CDFDEditor2View ��ӡ

BOOL CDFDEditor2View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CDFDEditor2View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ���Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CDFDEditor2View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ���Ӵ�ӡ����е���������
}


// CDFDEditor2View ���

#ifdef _DEBUG
void CDFDEditor2View::AssertValid() const
{
	CView::AssertValid();
}

void CDFDEditor2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CDFDEditor2Doc* CDFDEditor2View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDFDEditor2Doc)));
	return (CDFDEditor2Doc*)m_pDocument;
}
#endif //_DEBUG

/*void CDFDEditor2View::SetXY(int x, int y, int type, bool highlight){
	this->x = x;
	this->y = y;
	this->type = type;
	this->highlight = highlight;
}*/
//void CDFDEditor2View::SetPos(CPoint *pos){
	//this->pos = pos;
//}

// CDFDEditor2View ��Ϣ��������


void CDFDEditor2View::OnSource()
{
	// TODO:  �ڴ�����������������
	//CDFDEditor2Doc *pDoc = GetDocument();
	//pDoc->de->Menu(1);
	CMainFrame *pMainFrame = (CMainFrame*)AfxGetMainWnd();
	pMainFrame->de->Menu(1);
}


void CDFDEditor2View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO:  �ڴ�������Ϣ������������/�����Ĭ��ֵ
	pressState = 1;
	GetDocument()->SetPos(point);
	oldpos = point;
	CMainFrame *pMainFrame = (CMainFrame*)AfxGetMainWnd();
	pMainFrame->de->Press(point);
	//CView::OnLButtonDown(nFlags, point);
}


void CDFDEditor2View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO:  �ڴ�������Ϣ������������/�����Ĭ��ֵ

	//CView::OnLButtonUp(nFlags, point);
	GetDocument()->SetPos(point);
	CMainFrame *pMainFrame = (CMainFrame*)AfxGetMainWnd();
	pMainFrame->de->Release(point);
	pressState = 0;
	oldpos = 0;
}


void CDFDEditor2View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO:  �ڴ�������Ϣ������������/�����Ĭ��ֵ

	//CView::OnMouseMove(nFlags, point);
	if (pressState == 1){
		GetDocument()->SetPos(point);
		CMainFrame *pMainFrame = (CMainFrame*)AfxGetMainWnd();
		pMainFrame->de->Move(point, this->oldpos);
		this->oldpos = point;
	}
}


void CDFDEditor2View::OnProcess()
{
	// TODO:  �ڴ�����������������
	CMainFrame *pMainFrame = (CMainFrame*)AfxGetMainWnd();
	pMainFrame->de->Menu(2);
}


void CDFDEditor2View::OnDataStorage()
{
	// TODO:  �ڴ�����������������
	CMainFrame *pMainFrame = (CMainFrame*)AfxGetMainWnd();
	pMainFrame->de->Menu(3);
}


void CDFDEditor2View::OnStream()
{
	// TODO:  �ڴ�����������������
	CMainFrame *pMainFrame = (CMainFrame*)AfxGetMainWnd();
	pMainFrame->de->Menu(4);
}

void CDFDEditor2View::OnLookup()
{
	// TODO:  �ڴ�����������������
	CMainFrame *pMainFrame = (CMainFrame*)AfxGetMainWnd();
	pMainFrame->de->Menu(5);
}

void CDFDEditor2View::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO:  �ڴ�������Ϣ������������/�����Ĭ��ֵ

	//CView::OnRButtonDown(nFlags, point);
	GetDocument()->SetPos(point);
	CMainFrame *pMainFrame = (CMainFrame*)AfxGetMainWnd();

	pMainFrame->de->RightPress(point);
}


void CDFDEditor2View::OnRButtonUp(UINT nFlags, CPoint point)
{
	// TODO:  �ڴ�������Ϣ������������/�����Ĭ��ֵ

	//CView::OnRButtonUp(nFlags, point);
	GetDocument()->SetPos(point);
	CMainFrame *pMainFrame = (CMainFrame*)AfxGetMainWnd();
	pMainFrame->de->RightRelease(point);
}


void CDFDEditor2View::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO:  �ڴ�������Ϣ������������/�����Ĭ��ֵ

	//CView::OnLButtonDblClk(nFlags, point);
	GetDocument()->SetPos(point);
	CMainFrame *pMainFrame = (CMainFrame*)AfxGetMainWnd();
	pMainFrame->de->DoubleClick(point);
}




void CDFDEditor2View::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO:  �ڴ�������Ϣ������������/�����Ĭ��ֵ
	if (nChar == VK_DELETE)
	{
		CMainFrame *pMainFrame = (CMainFrame*)AfxGetMainWnd();
		pMainFrame->de->Remove();
	}
	else if (nChar == VK_ESCAPE)
	{
		CMainFrame *pMainFrame = (CMainFrame*)AfxGetMainWnd();
		pMainFrame->de->ExitEdit();
	}
	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}