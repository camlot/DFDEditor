#pragma once
#include "resource.h"       // main symbols

// CDlg �Ի���

class CDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CDlg)

public:
	CDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDlg();
	CString newtext;
// �Ի�������
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	DECLARE_MESSAGE_MAP()
};
