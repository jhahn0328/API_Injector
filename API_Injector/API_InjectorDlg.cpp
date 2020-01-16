
// API_InjectorDlg.cpp : ���� ����
//

#include "stdafx.h"
#include "API_Injector.h"
#include "API_InjectorDlg.h"
#include "afxdialogex.h"
#include "common.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ���� ���α׷� ������ ���Ǵ� CAboutDlg ��ȭ �����Դϴ�.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

// �����Դϴ�.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CAPI_InjectorDlg ��ȭ ����



CAPI_InjectorDlg::CAPI_InjectorDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CAPI_InjectorDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CAPI_InjectorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	//  DDX_Control(pDX, IDEDT_EXEC_PROC, m_edit_new_proc);
	//  DDX_Control(pDX, IDEDT_NEW_PROC, m_edit_exec_proc);
	DDX_Control(pDX, IDEDT_DLL, m_edit_dll);
	DDX_Control(pDX, IDEDT_EXEC_PROC, m_edit_exec_proc);
	DDX_Control(pDX, IDEDT_NEW_PROC, m_edit_new_proc);
}

BEGIN_MESSAGE_MAP(CAPI_InjectorDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDB_SEAR_EXEC_PROC, &CAPI_InjectorDlg::OnBnClickedSearExecProc)
	ON_BN_CLICKED(IDB_SEAR_NEW_PROC, &CAPI_InjectorDlg::OnBnClickedSearNewProc)
	ON_BN_CLICKED(IDB_SEAR_DLL, &CAPI_InjectorDlg::OnBnClickedSearDll)
	ON_BN_CLICKED(IDCBT_EXEC_INJECT, &CAPI_InjectorDlg::OnBnClickedExecInject)
	ON_BN_CLICKED(IDBT_NEW_INJECT, &CAPI_InjectorDlg::OnBnClickedNewInject)
	ON_BN_CLICKED(IDBT_FIND_API, &CAPI_InjectorDlg::OnBnClickedFindApi)
END_MESSAGE_MAP()


// CAPI_InjectorDlg �޽��� ó����

BOOL CAPI_InjectorDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// �ý��� �޴��� "����..." �޴� �׸��� �߰��մϴ�.

	// IDM_ABOUTBOX�� �ý��� ��� ������ �־�� �մϴ�.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// �� ��ȭ ������ �������� �����մϴ�.  ���� ���α׷��� �� â�� ��ȭ ���ڰ� �ƴ� ��쿡��
	//  �����ӿ�ũ�� �� �۾��� �ڵ����� �����մϴ�.
	SetIcon(m_hIcon, TRUE);			// ū �������� �����մϴ�.
	SetIcon(m_hIcon, FALSE);		// ���� �������� �����մϴ�.

	// TODO: ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
	//EDIT�ڽ� �ʱ�ȭ
	m_edit_new_proc.SetWindowTextW(L"C:\\Program Files (x86)\\Notepad++\\notepad++.exe");
	m_edit_exec_proc.SetWindowTextW(L"notepad++.exe");
	m_edit_dll.SetWindowTextW(L"C:\\mydll\\dll1.dll");

	CString strFilePath;
	strFilePath.Format(L"%s\\Data.ini", GetExePath());
	//ini �ʱ�ȭ
	INIWriteString(L"Module", L"Inclusive", L"notepad++.exe", strFilePath);
	INIWriteString(L"API", L"CreateFileW", L"FALSE", strFilePath);
	INIWriteString(L"API", L"CreateFileA", L"FALSE", strFilePath);
	INIWriteString(L"API", L"ReadFile", L"FALSE", strFilePath);
	INIWriteString(L"API", L"ReadFileEx", L"FALSE", strFilePath);
	INIWriteString(L"API", L"WriteFile", L"FALSE", strFilePath);
	INIWriteString(L"API", L"WriteFileEx", L"FALSE", strFilePath);
	INIWriteString(L"API", L"SetFilePointer", L"FALSE", strFilePath);
	INIWriteString(L"API", L"SetFilePointerEx", L"FALSE", strFilePath);
	INIWriteString(L"API", L"GetFileSize", L"FALSE", strFilePath);
	INIWriteString(L"API", L"GetFileSizeEx", L"FALSE", strFilePath);
	INIWriteString(L"API", L"MoveFile", L"FALSE", strFilePath);
	INIWriteString(L"API", L"MoveFileEx", L"FALSE", strFilePath);
	INIWriteString(L"API", L"CopyFile", L"FALSE", strFilePath);
	INIWriteString(L"API", L"CopyFileEx", L"FALSE", strFilePath);
	INIWriteString(L"API", L"StartDocW", L"FALSE", strFilePath);
	INIWriteString(L"API", L"StartPage", L"FALSE", strFilePath);
	INIWriteString(L"API", L"EndDoc", L"FALSE", strFilePath);
	INIWriteString(L"API", L"StartDocA", L"FALSE", strFilePath);
	INIWriteString(L"API", L"CreateWindowExW", L"FALSE", strFilePath);
	INIWriteString(L"API", L"CreateWindowExA", L"FALSE", strFilePath);
	INIWriteString(L"API", L"CreateDCW", L"FALSE", strFilePath);
	INIWriteString(L"API", L"CreateDCA", L"FALSE", strFilePath);
	return TRUE;  // ��Ŀ���� ��Ʈ�ѿ� �������� ������ TRUE�� ��ȯ�մϴ�.
}

void CAPI_InjectorDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// ��ȭ ���ڿ� �ּ�ȭ ���߸� �߰��� ��� �������� �׸�����
//  �Ʒ� �ڵ尡 �ʿ��մϴ�.  ����/�� ���� ����ϴ� MFC ���� ���α׷��� ��쿡��
//  �����ӿ�ũ���� �� �۾��� �ڵ����� �����մϴ�.

void CAPI_InjectorDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // �׸��⸦ ���� ����̽� ���ؽ�Ʈ�Դϴ�.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Ŭ���̾�Ʈ �簢������ �������� ����� ����ϴ�.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// �������� �׸��ϴ�.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// ����ڰ� �ּ�ȭ�� â�� ���� ���ȿ� Ŀ���� ǥ�õǵ��� �ý��ۿ���
//  �� �Լ��� ȣ���մϴ�.
HCURSOR CAPI_InjectorDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


//�������μ��� ã�� ��ư
void CAPI_InjectorDlg::OnBnClickedSearExecProc()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	CGetProcDlg dlg;
	if (IDOK == dlg.DoModal()){

	}
}

//���ο� ���α׷� ã�� ��ư
void CAPI_InjectorDlg::OnBnClickedSearNewProc()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	TCHAR szFilter[] = _T(/*"Image(*.png, *.gif, *.jpg)|*.png;*.gif;*.jpg*/"|All Files(*.*)|*.*||");
	CFileDialog dlg(TRUE, NULL, NULL, OFN_HIDEREADONLY, szFilter);
	if (IDOK == dlg.DoModal())
	{
		//
		// ���� �������� ���
		// strPathName      "C:/Images/Picture1.jpg"
		// strFileName      "Picture1.jpg"
		// strFolderPath    "C:/Images"

		CString strPathName = dlg.GetPathName();
		CString strFileName = dlg.GetFileName();
		CString strFolderPath = dlg.GetFolderPath();
		GetDlgItem(IDEDT_NEW_PROC)->SetWindowText(strPathName);

	}
}

//DLLã�� ��ư
void CAPI_InjectorDlg::OnBnClickedSearDll()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	TCHAR szFilter[] = _T(/*"Image(*.png, *.gif, *.jpg)|*.png;*.gif;*.jpg*/"|All Files(*.*)|*.*||");
	CFileDialog dlg(TRUE, NULL, NULL, OFN_HIDEREADONLY, szFilter);
	if (IDOK == dlg.DoModal())
	{
		//
		// ���� �������� ���
		// strPathName      "C:/Images/Picture1.jpg"
		// strFileName      "Picture1.jpg"
		// strFolderPath    "C:/Images"

		CString strPathName = dlg.GetPathName();
		CString strFileName = dlg.GetFileName();
		CString strFolderPath = dlg.GetFolderPath();
		CString tmp_cmp = strPathName.Right(4);
		if (tmp_cmp.Compare(L".dll") != 0){
			AfxMessageBox(L"dll������ �����Ͽ� �ֽʽÿ�");
			return;
		}
		GetDlgItem(IDEDT_DLL)->SetWindowText(strPathName);
	}
}

//�������� ���μ����� ����Ʈ ��ư
void CAPI_InjectorDlg::OnBnClickedExecInject()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	DWORD dwPID = 0xFFFFFFFF;
	CString cs_proc;
	CString cs_dll;
	GetDlgItemText(IDEDT_EXEC_PROC, cs_proc);
	GetDlgItemText(IDEDT_DLL, cs_dll);
	//���μ��� PIDã��
	dwPID = FindProcessID(cs_proc);
	if (dwPID == 0xFFFFFFFF)
	{
		AfxMessageBox(L"���μ����� ã�� ���Ͽ����ϴ�");
		return;
	}
	//������ �Լ�
	InjectDll(dwPID, cs_dll);
	AfxMessageBox(L"����Ʈ �Ϸ�");
}

//���ο� ���α׷��� ����Ʈ ��ư
void CAPI_InjectorDlg::OnBnClickedNewInject()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	CString cs_proc;
	CString cs_tmp = L"0";
	int i = 0;
	STARTUPINFO si = { 0, };    //����ü ����, �ʱ�ȭ
	PROCESS_INFORMATION pi;
	//�ű� ���α׷� ����
	GetDlgItemText(IDEDT_NEW_PROC, cs_proc);
	ZeroMemory(&si, sizeof(si));
	si.cb = sizeof(si);
	ZeroMemory(&pi, sizeof(pi));
	CreateProcess(cs_proc,NULL,NULL,NULL,FALSE,0,NULL,NULL,&si,&pi);//pi pid��������

	DWORD dwPID = 0xFFFFFFFF;
	CString cs_dll;

	GetDlgItemText(IDEDT_DLL, cs_dll);
	//����ü���� PID��������
	dwPID = pi.dwProcessId;
	if (dwPID == 0xFFFFFFFF||cs_proc.Compare(L"")==0)
	{
		AfxMessageBox(L"���μ����� ã�� ���Ͽ����ϴ�");
		return;
	}
	InjectDll(dwPID, cs_dll);
	AfxMessageBox(L"����Ʈ �Ϸ�");
}



//api ���ù�ư
void CAPI_InjectorDlg::OnBnClickedFindApi()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	CCheckAPIDlg dlg;
	if (IDOK == dlg.DoModal()){

	}
}
