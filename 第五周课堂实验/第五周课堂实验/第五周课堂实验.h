
// �����ܿ���ʵ��.h : �����ܿ���ʵ�� Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// C�����ܿ���ʵ��App:
// �йش����ʵ�֣������ �����ܿ���ʵ��.cpp
//

class C�����ܿ���ʵ��App : public CWinAppEx
{
public:
	C�����ܿ���ʵ��App();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern C�����ܿ���ʵ��App theApp;
