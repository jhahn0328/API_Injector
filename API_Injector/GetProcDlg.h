#pragma once
#include "afxcmn.h"
#include <tlhelp32.h> 
#include <windows.h> 
#include <tchar.h>
#include "API_InjectorDlg.h"
// CGetProcDlg ��ȭ �����Դϴ�.

class CGetProcDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CGetProcDlg)

public:
	CGetProcDlg(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CGetProcDlg();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_GET_PROC_Dlg };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	CListCtrl m_ctrl_proc;
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedRefresh();
};
