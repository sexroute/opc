
// OPCClient.h : OPCClient Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// COPCClientApp:
// �йش����ʵ�֣������ OPCClient.cpp
//

class COPCClientApp : public CWinApp
{
public:
	COPCClientApp();


// ��д
public:
	virtual BOOL InitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern COPCClientApp theApp;
