#pragma once
#include "resource.h"       // main symbols

// CDlg 对话框

class CDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CDlg)

public:
	CDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDlg();
	CString newtext;
// 对话框数据
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	DECLARE_MESSAGE_MAP()
};
