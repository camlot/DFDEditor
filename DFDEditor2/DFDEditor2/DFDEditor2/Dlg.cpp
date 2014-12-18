// Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "DFDEditor2.h"
#include "Dlg.h"
#include "afxdialogex.h"


// CDlg 对话框

IMPLEMENT_DYNAMIC(CDlg, CDialogEx)

CDlg::CDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDlg::IDD, pParent)
{

}

CDlg::~CDlg()
{
}

void CDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, newtext);
}


BEGIN_MESSAGE_MAP(CDlg, CDialogEx)
END_MESSAGE_MAP()


// CDlg 消息处理程序
