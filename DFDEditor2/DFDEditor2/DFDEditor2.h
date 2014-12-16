
// DFDEditor2.h : DFDEditor2 应用程序的主头文件
//
#pragma once

#ifndef __AFXWIN_H__
	#error "在包含此文件之前包含“stdafx.h”以生成 PCH 文件"
#endif

#include "resource.h"       // 主符号


// CDFDEditor2App:
// 有关此类的实现，请参阅 DFDEditor2.cpp
//

class CDFDEditor2App : public CWinAppEx
{
public:
	CDFDEditor2App();


// 重写
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// 实现
	afx_msg void OnAppAbout();
	afx_msg void OnFileNew();
	DECLARE_MESSAGE_MAP()
};

extern CDFDEditor2App theApp;
