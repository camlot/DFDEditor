
// ChildFrm.cpp : CChildFrame ���ʵ��
//

#include "stdafx.h"
#include "DFDEditor2.h"

#include "ChildFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CChildFrame

IMPLEMENT_DYNCREATE(CChildFrame, CMDIChildWnd)

BEGIN_MESSAGE_MAP(CChildFrame, CMDIChildWnd)
	ON_COMMAND(ID_32772, &CChildFrame::OnDiagram)
END_MESSAGE_MAP()

// CChildFrame ����/����

CChildFrame::CChildFrame()
{
	// TODO:  �ڴ���ӳ�Ա��ʼ������
}

CChildFrame::~CChildFrame()
{
}


BOOL CChildFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  �ڴ˴�ͨ���޸� CREATESTRUCT cs ���޸Ĵ��������ʽ
	if( !CMDIChildWnd::PreCreateWindow(cs) )
		return FALSE;

	return TRUE;
}

// CChildFrame ���

#ifdef _DEBUG
void CChildFrame::AssertValid() const
{
	CMDIChildWnd::AssertValid();
}

void CChildFrame::Dump(CDumpContext& dc) const
{
	CMDIChildWnd::Dump(dc);
}
#endif //_DEBUG

// CChildFrame ��Ϣ�������


void CChildFrame::OnDiagram()
{
	// TODO:  �ڴ���������������
	/*CChildFrame *childfrm = new CChildFrame();
	CMainFrame *pMainFrame = (CMainFrame*)AfxGetMainWnd();
	CChildFrame *pChildFrame = (CChildFrame*)pMainFrame->GetActiveFrame();
	HWND hWnd = pChildFrame->m_hWnd;

	Diagram *d = new Diagram();
	pMainFrame->de->InsertMap(hWnd, d);*/
}
