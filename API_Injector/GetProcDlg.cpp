// GetProcDlg.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "API_Injector.h"
#include "GetProcDlg.h"
#include "afxdialogex.h"
#include "common.h"


// CGetProcDlg 대화 상자입니다.

IMPLEMENT_DYNAMIC(CGetProcDlg, CDialogEx)

//BOOL IsWow64(DWORD pPID);
//typedef BOOL(WINAPI *LPFN_ISWOW64PROCESS) (HANDLE, PBOOL);
//LPFN_ISWOW64PROCESS fnIsWow64Process;

CGetProcDlg::CGetProcDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CGetProcDlg::IDD, pParent)
{

}

CGetProcDlg::~CGetProcDlg()
{
}

void CGetProcDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDLST_PROC, m_ctrl_proc);
}


BEGIN_MESSAGE_MAP(CGetProcDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &CGetProcDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDBT_REFRESH, &CGetProcDlg::OnBnClickedRefresh)
END_MESSAGE_MAP()


// CGetProcDlg 메시지 처리기입니다.


BOOL CGetProcDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	m_ctrl_proc.SetExtendedStyle(LVS_EX_FULLROWSELECT);
	CRect rect;
	m_ctrl_proc.GetClientRect(&rect);
	m_ctrl_proc.InsertColumn(0, _T("PID"), LVCFMT_LEFT, 100);
	m_ctrl_proc.InsertColumn(1, _T("프로세스 이름"), LVCFMT_LEFT, rect.Width() - 150);
	m_ctrl_proc.InsertColumn(2, _T("형식"), LVCFMT_LEFT, rect.Width() - 50);

	BOOL bGet = FALSE;
	char buf[260] = "";
	HANDLE hSnapshot;
	PROCESSENTRY32 ppe;     //구성된 자료구조를 저장하기 위한 엔트리.  

	hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);//system 프로세서(pid=0)의 상태를 읽어 온다   
	ppe.dwSize = sizeof(PROCESSENTRY32);                        //엔트리 구조체 사이즈를 정해준다.  
	bGet = Process32First(hSnapshot, &ppe);                     //엔트리 중 자료를 가져온다.  

	while (bGet)
	{
		WideCharToMultiByte(CP_ACP, 0, ppe.szExeFile, 260, buf, 260, NULL, NULL);
		CString PID;
		PID.Format(_T("%d"), ppe.th32ProcessID);
		CString pcs_name(buf);

		m_ctrl_proc.InsertItem(0, PID);
		m_ctrl_proc.SetItem(0, 1, LVIF_TEXT, pcs_name, 0, 0, 0, NULL);
		if (IsWow64(ppe.th32ProcessID) == TRUE){
			m_ctrl_proc.SetItem(0, 2, LVIF_TEXT, _T("x86"), 0, 0, 0, NULL);
		}
		else{
			m_ctrl_proc.SetItem(0, 2, LVIF_TEXT, _T("x64"), 0, 0, 0, NULL);
		}
		bGet = Process32Next(hSnapshot, &ppe);
	}

	CloseHandle(hSnapshot);
	return TRUE;  // return TRUE unless you set the focus to a control
	// 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}
//프로세스 선택버튼
void CGetProcDlg::OnBnClickedOk()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	POSITION pos = NULL;
	int nItemIdx = 0;
	CString ProcessName;
	CAPI_InjectorDlg *pParent = (CAPI_InjectorDlg *)GetParent();

	pos = m_ctrl_proc.GetFirstSelectedItemPosition();

	if (NULL != pos)
	{
		nItemIdx = m_ctrl_proc.GetNextSelectedItem(pos);
	}
	ProcessName = m_ctrl_proc.GetItemText(nItemIdx, 1);
	pParent->GetDlgItem(IDEDT_EXEC_PROC)->SetWindowText(ProcessName);
	CDialogEx::OnOK();
}

//새로고침 버튼
void CGetProcDlg::OnBnClickedRefresh()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	BOOL bGet = FALSE;
	char buf[260] = "";
	HANDLE hSnapshot;
	PROCESSENTRY32 ppe;     //구성된 자료구조를 저장하기 위한 엔트리.  

	hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);//system 프로세서(pid=0)의 상태를 읽어 온다   
	ppe.dwSize = sizeof(PROCESSENTRY32);                        //엔트리 구조체 사이즈를 정해준다.  
	bGet = Process32First(hSnapshot, &ppe);                     //엔트리 중 자료를 가져온다.  

	while (bGet)
	{
		WideCharToMultiByte(CP_ACP, 0, ppe.szExeFile, 260, buf, 260, NULL, NULL);
		CString PID;
		PID.Format(_T("%d"), ppe.th32ProcessID);
		CString pcs_name(buf);

		m_ctrl_proc.InsertItem(0, PID);
		m_ctrl_proc.SetItem(0, 1, LVIF_TEXT, pcs_name, 0, 0, 0, NULL);
		if (IsWow64(ppe.th32ProcessID) == TRUE){
			m_ctrl_proc.SetItem(0, 2, LVIF_TEXT, _T("x86"), 0, 0, 0, NULL);
		}
		else{
			m_ctrl_proc.SetItem(0, 2, LVIF_TEXT, _T("x64"), 0, 0, 0, NULL);
		}
		bGet = Process32Next(hSnapshot, &ppe);
	}

	CloseHandle(hSnapshot);
}
