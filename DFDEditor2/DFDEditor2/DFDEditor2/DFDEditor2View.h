
// DFDEditor2View.h : CDFDEditor2View 类的接口
//

#pragma once
class CDFDEditor2Doc;

class CDFDEditor2View : public CView
{
private:
	int x, y, type;
	int pressState;
	bool highlight;

protected: // 仅从序列化创建
	CDFDEditor2View();
	DECLARE_DYNCREATE(CDFDEditor2View)

// 特性
public:
	CDFDEditor2Doc* GetDocument() const;
	void SetXY(int x, int y, int type, bool highlight);

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
	afx_msg void OnSource();  // 菜单项：选中源(Source)
	afx_msg void OnProcess();  // 菜单项：选中加工(Process)
	afx_msg void OnDataStorage();  // 菜单项：选中存储(DataStorage)
	afx_msg void OnStream();   // 菜单项：选中流(Stream)
	afx_msg void OnLookup();  // 菜单项：选中查找路径
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);  // 释放鼠标右键
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);  // 释放鼠标左键
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);  // 按下鼠标右键
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);  // 释放鼠标右键
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);  // 双击鼠标左键
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);  // 鼠标移动
};

#ifndef _DEBUG  // DFDEditor2View.cpp 中的调试版本
inline CDFDEditor2Doc* CDFDEditor2View::GetDocument() const
   { return reinterpret_cast<CDFDEditor2Doc*>(m_pDocument); }
#endif

