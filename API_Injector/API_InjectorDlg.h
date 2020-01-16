
// API_InjectorDlg.h : ��� ����
//

#pragma once
#include "GetProcDlg.h"
#include "CheckAPIDlg.h"
#include "afxwin.h"

// CAPI_InjectorDlg ��ȭ ����
class CAPI_InjectorDlg : public CDialogEx
{
// �����Դϴ�.
public:
	CAPI_InjectorDlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_API_INJECTOR_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV �����Դϴ�.


// �����Դϴ�.
protected:
	HICON m_hIcon;

	// ������ �޽��� �� �Լ�
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
