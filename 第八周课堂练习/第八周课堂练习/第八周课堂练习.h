
// �ڰ��ܿ�����ϰ.h : �ڰ��ܿ�����ϰ Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// C�ڰ��ܿ�����ϰApp:
// �йش����ʵ�֣������ �ڰ��ܿ�����ϰ.cpp
//

class C�ڰ��ܿ�����ϰApp : public CWinAppEx
{
public:
	C�ڰ��ܿ�����ϰApp();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern C�ڰ��ܿ�����ϰApp theApp;
