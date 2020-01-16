
// API_InjectorDlg.h : 헤더 파일
//

#pragma once
#include "GetProcDlg.h"
#include "CheckAPIDlg.h"
#include "afxwin.h"

// CAPI_InjectorDlg 대화 상자
class CAPI_InjectorDlg : public CDialogEx
{
// 생성입니다.
public:
	CAPI_InjectorDlg(CWnd* pParent = NULL);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
	enum { IDD = IDD_API_INJECTOR_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedSearExecProc();
	afx_msg void OnBnClickedSearNewProc();
	afx_msg void OnBnClickedSearDll();
	afx_msg void OnBnClickedExecInject();
	afx_msg void OnBnClickedNewInject();
	afx_msg void OnBnClickedFindApi();
//	CEdit m_edit_new_proc;
//	CEdit m_edit_exec_proc;
	CEdit m_edit_dll;
	CEdit m_edit_exec_proc;
	CEdit m_edit_new_proc;
};
