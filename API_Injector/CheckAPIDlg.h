#pragma once
#include "afxwin.h"


// CCheckAPIDlg 대화 상자입니다.

class CCheckAPIDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CCheckAPIDlg)

public:
	CCheckAPIDlg(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CCheckAPIDlg();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_CHK_API };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	CButton m_chk_createfileA;
	CButton m_chk_readfile;
	CButton m_chk_writefile;
	CButton m_chk_createfileW;
	CButton m_chk_readfileEx;
	CButton m_chk_writefileEx;
	virtual BOOL OnInitDialog();
	CButton m_chk_StartDocW;
	CButton m_chk_StartPage;
	CButton m_chk_EndDoc;
	CButton m_chk_closehandle;
	CButton m_chk_SetFilePointer;
	CButton m_chk_SetFilePointerEx;
	CButton m_chk_GetFileSize;
	CButton m_chk_GetFileSizeEx;
	CButton m_chk_MoveFile;
	CButton m_chk_MoveFileEx;
	CButton m_chk_CopyFile;
	CButton m_chk_CopyFileEx;
	CButton m_chk_StartDocA;
	CButton m_chk_CreateWindowExW;
	CButton m_chk_CreateWindowExA;
	CButton m_chk_CreateDCW;
	CButton m_chk_CreateDCA;
};
