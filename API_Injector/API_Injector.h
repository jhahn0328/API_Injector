
// API_Injector.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// CAPI_InjectorApp:
// �� Ŭ������ ������ ���ؼ��� API_Injector.cpp�� �����Ͻʽÿ�.
//

class CAPI_InjectorApp : public CWinApp
{
public:
	CAPI_InjectorApp();

// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};

extern CAPI_InjectorApp theApp;