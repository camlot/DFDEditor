
// DFDEditor2View.h : CDFDEditor2View ��Ľӿ�
//

#pragma once
class CDFDEditor2Doc;

class CDFDEditor2View : public CView
{
private:
	int x, y, type;
	int pressState;
	bool highlight;

protected: // �������л�����
	CDFDEditor2View();
	DECLARE_DYNCREATE(CDFDEditor2View)

// ����
public:
	CDFDEditor2Doc* GetDocument() const;
	void SetXY(int x, int y, int type, bool highlight);

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// ʵ��
public:
	virtual ~CDFDEditor2View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnSource();  // �˵��ѡ��Դ(Source)
	afx_msg void OnProcess();  // �˵��ѡ�мӹ�(Process)
	afx_msg void OnDataStorage();  // �˵��ѡ�д洢(DataStorage)
	afx_msg void OnStream();   // �˵��ѡ����(Stream)
	afx_msg void OnLookup();  // �˵��ѡ�в���·��
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);  // �ͷ�����Ҽ�
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);  // �ͷ�������
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);  // ��������Ҽ�
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);  // �ͷ�����Ҽ�
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);  // ˫��������
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);  // ����ƶ�
};

#ifndef _DEBUG  // DFDEditor2View.cpp �еĵ��԰汾
inline CDFDEditor2Doc* CDFDEditor2View::GetDocument() const
   { return reinterpret_cast<CDFDEditor2Doc*>(m_pDocument); }
#endif

