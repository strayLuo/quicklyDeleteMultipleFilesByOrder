
// quicklyDeleteMultipleFilesByOrder.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CquicklyDeleteMultipleFilesByOrderApp:
// �йش����ʵ�֣������ quicklyDeleteMultipleFilesByOrder.cpp
//

class CquicklyDeleteMultipleFilesByOrderApp : public CWinApp
{
public:
	CquicklyDeleteMultipleFilesByOrderApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CquicklyDeleteMultipleFilesByOrderApp theApp;