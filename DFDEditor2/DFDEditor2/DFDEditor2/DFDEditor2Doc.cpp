
// DFDEditor2Doc.cpp : CDFDEditor2Doc ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "DFDEditor2.h"
#endif

#include "DFDEditor2Doc.h"
#include"DiagramEditor.h"
#include"Diagram.h"
#include"MainFrm.h"
#include"ChildFrm.h"


#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CDFDEditor2Doc

IMPLEMENT_DYNCREATE(CDFDEditor2Doc, CDocument)

BEGIN_MESSAGE_MAP(CDFDEditor2Doc, CDocument)
END_MESSAGE_MAP()


// CDFDEditor2Doc ����/����

CDFDEditor2Doc::CDFDEditor2Doc()
{
	// TODO:  �ڴ����һ���Թ������
	d = NULL;
	//pos = NULL;
	e = NULL;
	original = false;
}

CDFDEditor2Doc::~CDFDEditor2Doc()
{
}

BOOL CDFDEditor2Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO:  �ڴ�������³�ʼ������
	// (SDI �ĵ������ø��ĵ�)

	return TRUE;
}




// CDFDEditor2Doc ���л�

void CDFDEditor2Doc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO:  �ڴ���Ӵ洢����
	}
	else
	{
		// TODO:  �ڴ���Ӽ��ش���
	}
}

#ifdef SHARED_HANDLERS

// ����ͼ��֧��
void CDFDEditor2Doc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// �޸Ĵ˴����Ի����ĵ�����
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// ������������֧��
void CDFDEditor2Doc::InitializeSearchContent()
{
	CString strSearchContent;
	// ���ĵ����������������ݡ�
	// ���ݲ���Ӧ�ɡ�;���ָ�

	// ����:     strSearchContent = _T("point;rectangle;circle;ole object;")��
	SetSearchContent(strSearchContent);
}

void CDFDEditor2Doc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = NULL;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != NULL)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// CDFDEditor2Doc ���

#ifdef _DEBUG
void CDFDEditor2Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CDFDEditor2Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CDFDEditor2Doc ����
void CDFDEditor2Doc::SetOri(bool o){
	this->original = o;
}
void CDFDEditor2Doc::SetPos(CPoint pos){
	this->pos = pos;
}
void CDFDEditor2Doc::SetDiagram(Diagram *d){
	this->d = d;
}
void CDFDEditor2Doc::SetElement(Element *e){
	this->e = e;
}