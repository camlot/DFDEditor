// Dlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "DFDEditor2.h"
#include "Dlg.h"
#include "afxdialogex.h"


// CDlg �Ի���

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


// CDlg ��Ϣ�������
