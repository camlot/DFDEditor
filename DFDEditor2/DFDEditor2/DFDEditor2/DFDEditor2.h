
// DFDEditor2.h : DFDEditor2 Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CDFDEditor2App:
// �йش����ʵ�֣������ DFDEditor2.cpp
//

class CDFDEditor2App : public CWinAppEx
{
public:
	CDFDEditor2App();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	afx_msg void OnFileNew();
	DECLARE_MESSAGE_MAP()
};

extern CDFDEditor2App theApp;
