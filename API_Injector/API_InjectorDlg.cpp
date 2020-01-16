
// API_InjectorDlg.cpp : 구현 파일
//

#include "stdafx.h"
#include "API_Injector.h"
#include "API_InjectorDlg.h"
#include "afxdialogex.h"
#include "common.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
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


// CAPI_InjectorDlg 대화 상자



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


// CAPI_InjectorDlg 메시지 처리기

BOOL CAPI_InjectorDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
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

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.
	//EDIT박스 초기화
	m_edit_new_proc.SetWindowTextW(L"C:\\Program Files (x86)\\Notepad++\\notepad++.exe");
	m_edit_exec_proc.SetWindowTextW(L"notepad++.exe");
	m_edit_dll.SetWindowTextW(L"C:\\mydll\\dll1.dll");

	CString strFilePath;
	strFilePath.Format(L"%s\\Data.ini", GetExePath());
	//ini 초기화
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
	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
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

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 응용 프로그램의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CAPI_InjectorDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CAPI_InjectorDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


//기존프로세스 찾기 버튼
void CAPI_InjectorDlg::OnBnClickedSearExecProc()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CGetProcDlg dlg;
	if (IDOK == dlg.DoModal()){

	}
}

//새로운 프로그램 찾기 버튼
void CAPI_InjectorDlg::OnBnClickedSearNewProc()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	TCHAR szFilter[] = _T(/*"Image(*.png, *.gif, *.jpg)|*.png;*.gif;*.jpg*/"|All Files(*.*)|*.*||");
	CFileDialog dlg(TRUE, NULL, NULL, OFN_HIDEREADONLY, szFilter);
	if (IDOK == dlg.DoModal())
	{
		//
		// 선택 파일정보 얻기
		// strPathName      "C:/Images/Picture1.jpg"
		// strFileName      "Picture1.jpg"
		// strFolderPath    "C:/Images"

		CString strPathName = dlg.GetPathName();
		CString strFileName = dlg.GetFileName();
		CString strFolderPath = dlg.GetFolderPath();
		GetDlgItem(IDEDT_NEW_PROC)->SetWindowText(strPathName);

	}
}

//DLL찾기 버튼
void CAPI_InjectorDlg::OnBnClickedSearDll()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	TCHAR szFilter[] = _T(/*"Image(*.png, *.gif, *.jpg)|*.png;*.gif;*.jpg*/"|All Files(*.*)|*.*||");
	CFileDialog dlg(TRUE, NULL, NULL, OFN_HIDEREADONLY, szFilter);
	if (IDOK == dlg.DoModal())
	{
		//
		// 선택 파일정보 얻기
		// strPathName      "C:/Images/Picture1.jpg"
		// strFileName      "Picture1.jpg"
		// strFolderPath    "C:/Images"

		CString strPathName = dlg.GetPathName();
		CString strFileName = dlg.GetFileName();
		CString strFolderPath = dlg.GetFolderPath();
		CString tmp_cmp = strPathName.Right(4);
		if (tmp_cmp.Compare(L".dll") != 0){
			AfxMessageBox(L"dll파일을 선택하여 주십시오");
			return;
		}
		GetDlgItem(IDEDT_DLL)->SetWindowText(strPathName);
	}
}

//실행중인 프로세스에 인젝트 버튼
void CAPI_InjectorDlg::OnBnClickedExecInject()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	DWORD dwPID = 0xFFFFFFFF;
	CString cs_proc;
	CString cs_dll;
	GetDlgItemText(IDEDT_EXEC_PROC, cs_proc);
	GetDlgItemText(IDEDT_DLL, cs_dll);
	//프로세스 PID찾기
	dwPID = FindProcessID(cs_proc);
	if (dwPID == 0xFFFFFFFF)
	{
		AfxMessageBox(L"프로세스를 찾지 못하였습니다");
		return;
	}
	//인젝션 함수
	InjectDll(dwPID, cs_dll);
	AfxMessageBox(L"인젝트 완료");
}

//새로운 프로그램에 인젝트 버튼
void CAPI_InjectorDlg::OnBnClickedNewInject()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CString cs_proc;
	CString cs_tmp = L"0";
	int i = 0;
	STARTUPINFO si = { 0, };    //구조체 선언, 초기화
	PROCESS_INFORMATION pi;
	//신규 프로그램 실행
	GetDlgItemText(IDEDT_NEW_PROC, cs_proc);
	ZeroMemory(&si, sizeof(si));
	si.cb = sizeof(si);
	ZeroMemory(&pi, sizeof(pi));
	CreateProcess(cs_proc,NULL,NULL,NULL,FALSE,0,NULL,NULL,&si,&pi);//pi pid가져오기

	DWORD dwPID = 0xFFFFFFFF;
	CString cs_dll;

	GetDlgItemText(IDEDT_DLL, cs_dll);
	//구조체에서 PID가져오기
	dwPID = pi.dwProcessId;
	if (dwPID == 0xFFFFFFFF||cs_proc.Compare(L"")==0)
	{
		AfxMessageBox(L"프로세스를 찾지 못하였습니다");
		return;
	}
	InjectDll(dwPID, cs_dll);
	AfxMessageBox(L"인젝트 완료");
}



//api 선택버튼
void CAPI_InjectorDlg::OnBnClickedFindApi()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CCheckAPIDlg dlg;
	if (IDOK == dlg.DoModal()){

	}
}
