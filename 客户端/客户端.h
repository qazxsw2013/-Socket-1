
// �ͻ���.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// C�ͻ���App: 
// �йش����ʵ�֣������ �ͻ���.cpp
//

class C�ͻ���App : public CWinApp
{
public:
	C�ͻ���App();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern C�ͻ���App theApp;