// GetProcDlg.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "API_Injector.h"
#include "GetProcDlg.h"
#include "afxdialogex.h"
#include "common.h"


// CGetProcDlg ��ȭ �����Դϴ�.

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


// CGetProcDlg �޽��� ó�����Դϴ�.


BOOL CGetProcDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
	m_ctrl_proc.SetExtendedStyle(LVS_EX_FULLROWSELECT);
	CRect rect;
	m_ctrl_proc.GetClientRect(&rect);
	m_ctrl_proc.InsertColumn(0, _T("PID"), LVCFMT_LEFT, 100);
	m_ctrl_proc.InsertColumn(1, _T("���μ��� �̸�"), LVCFMT_LEFT, rect.Width() - 150);
	m_ctrl_proc.InsertColumn(2, _T("����"), LVCFMT_LEFT, rect.Width() - 50);

	BOOL bGet = FALSE;
	char buf[260] = "";
	HANDLE hSnapshot;
	PROCESSENTRY32 ppe;     //������ �ڷᱸ���� �����ϱ� ���� ��Ʈ��.  

	hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);//system ���μ���(pid=0)�� ���¸� �о� �´�   
	ppe.dwSize = sizeof(PROCESSENTRY32);                        //��Ʈ�� ����ü ����� �����ش�.  
	bGet = Process32First(hSnapshot, &ppe);                     //��Ʈ�� �� �ڷḦ �����´�.  

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
	// ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}
//���μ��� ���ù�ư
void CGetProcDlg::OnBnClickedOk()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
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

//���ΰ�ħ ��ư
void CGetProcDlg::OnBnClickedRefresh()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	BOOL bGet = FALSE;
	char buf[260] = "";
	HANDLE hSnapshot;
	PROCESSENTRY32 ppe;     //������ �ڷᱸ���� �����ϱ� ���� ��Ʈ��.  

	hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);//system ���μ���(pid=0)�� ���¸� �о� �´�   
	ppe.dwSize = sizeof(PROCESSENTRY32);                        //��Ʈ�� ����ü ����� �����ش�.  
	bGet = Process32First(hSnapshot, &ppe);                     //��Ʈ�� �� �ڷḦ �����´�.  

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
