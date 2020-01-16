#pragma once
#include "afxcmn.h"
#include <tlhelp32.h> 
#include <windows.h> 
#include <tchar.h>
#include "API_InjectorDlg.h"
// CGetProcDlg 대화 상자입니다.

class CGetProcDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CGetProcDlg)

public:
	CGetProcDlg(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CGetProcDlg();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_GET_PROC_Dlg };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	CListCtrl m_ctrl_proc;
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedRefresh();
};
