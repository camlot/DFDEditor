
// DFDEditor2View.h : CDFDEditor2View 类的接口
//

#pragma once
class CDFDEditor2Doc;

class CDFDEditor2View : public CView
{
private:
	//int x, y, type;
	int pressState;
	CPoint oldpos;
	//bool highlight;
	//CPoint *pos;

protected: // 仅从序列化创建
	CDFDEditor2View();
	DECLARE_DYNCREATE(CDFDEditor2View)

// 特性
public:
	CDFDEditor2Doc* GetDocument() const;
	//void SetXY(int x, int y, int type, bool highlight);
	//void SetPos(CPoint *pos);

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~CDFDEditor2View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnRectangle();
	afx_msg void OnEllipse();
	afx_msg void OnDataStorage();
	afx_msg void OnStream();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLookup();
};

#ifndef _DEBUG  // DFDEditor2View.cpp 中的调试版本
inline CDFDEditor2Doc* CDFDEditor2View::GetDocument() const
   { return reinterpret_cast<CDFDEditor2Doc*>(m_pDocument); }
#endif

