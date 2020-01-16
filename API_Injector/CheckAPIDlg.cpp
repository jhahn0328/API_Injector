// CheckAPIDlg.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "API_Injector.h"
#include "CheckAPIDlg.h"
#include "afxdialogex.h"


// CCheckAPIDlg ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CCheckAPIDlg, CDialogEx)

CCheckAPIDlg::CCheckAPIDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CCheckAPIDlg::IDD, pParent)
{

}

CCheckAPIDlg::~CCheckAPIDlg()
{
}

void CCheckAPIDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDCHK_CREATEFILEA, m_chk_createfileA);
	DDX_Control(pDX, IDCHK_READFILE, m_chk_readfile);
	DDX_Control(pDX, IDCHK_WRITEFILE, m_chk_writefile);
	DDX_Control(pDX, IDCHK_CREATEFILEW, m_chk_createfileW);
	DDX_Control(pDX, IDCHK_READFILEEX, m_chk_readfileEx);
	DDX_Control(pDX, IDCHK_WRITEFILEEX, m_chk_writefileEx);
	DDX_Control(pDX, IDCHK_StartDocW, m_chk_StartDocW);
	DDX_Control(pDX, IDCHK_STARTPAGE, m_chk_StartPage);
	DDX_Control(pDX, IDCHK_END_DOC, m_chk_EndDoc);
	DDX_Control(pDX, IDCHK_CLOSEHANDLE, m_chk_closehandle);
	DDX_Control(pDX, IDCHK_SETFILEPOINTER, m_chk_SetFilePointer);
	DDX_Control(pDX, IDCHK_SETFILEPOINTEREX, m_chk_SetFilePointerEx);
	DDX_Control(pDX, IDCHK_GETFILESIZE, m_chk_GetFileSize);
	DDX_Control(pDX, IDCHK_GETFILESIZEEX, m_chk_GetFileSizeEx);
	DDX_Control(pDX, IDCHK_MOVEFILE, m_chk_MoveFile);
	DDX_Control(pDX, IDCHK_MOVEFILEEX, m_chk_MoveFileEx);
	DDX_Control(pDX, IDCHK_COPYFILE, m_chk_CopyFile);
	DDX_Control(pDX, IDCHK_COPYFILEEX, m_chk_CopyFileEx);
	DDX_Control(pDX, IDCHK_StartDocA, m_chk_StartDocA);
	DDX_Control(pDX, IDCHK_CREATEWINDOWEXW, m_chk_CreateWindowExW);
	DDX_Control(pDX, IDCHK_CREATEWINDOWEXA, m_chk_CreateWindowExA);
	DDX_Control(pDX, IDCHK_CREATEDCW, m_chk_CreateDCW);
	DDX_Control(pDX, IDCHK_CREATEDCA, m_chk_CreateDCA);
}


BEGIN_MESSAGE_MAP(CCheckAPIDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &CCheckAPIDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// CCheckAPIDlg �޽��� ó�����Դϴ�.


BOOL CCheckAPIDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
	


	return TRUE;  // return TRUE unless you set the focus to a control
	// ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}
//ini API���� 
void CCheckAPIDlg::OnBnClickedOk()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	CString strFilePath;
	strFilePath.Format(L"%s\\Data.ini", GetExePath());

	if (m_chk_createfileA.GetCheck() == 1){
		//üũ�Ǿ��� ��� 
		INIWriteString(L"API", L"CreateFileA", L"TRUE", strFilePath);
	}
	else{
		//üũ �ȵǾ��� ���
		INIWriteString(L"API", L"CreateFileA", L"FALSE", strFilePath);
	}

	if (m_chk_createfileW.GetCheck() == 1){
		//üũ�Ǿ��� ��� 
		INIWriteString(L"API", L"CreateFileW", L"TRUE", strFilePath);
	}
	else{
		//üũ �ȵǾ��� ���
		INIWriteString(L"API", L"CreateFileW", L"FALSE", strFilePath);
	}

	if (m_chk_readfile.GetCheck() == 1){
		//üũ�Ǿ��� ��� 
		INIWriteString(L"API", L"ReadFile", L"TRUE", strFilePath);
	}
	else{
		//üũ �ȵǾ��� ���
		INIWriteString(L"API", L"ReadFile", L"FALSE", strFilePath);
	}

	if (m_chk_readfileEx.GetCheck() == 1){
		//üũ�Ǿ��� ��� 
		INIWriteString(L"API", L"ReadFileEx", L"TRUE", strFilePath);
	}
	else{
		//üũ �ȵǾ��� ���
		INIWriteString(L"API", L"ReadFileEx", L"FALSE", strFilePath);
	}

	if (m_chk_writefile.GetCheck() == 1){
		//üũ�Ǿ��� ��� 
		INIWriteString(L"API", L"WriteFile", L"TRUE", strFilePath);
	}
	else{
		//üũ �ȵǾ��� ���
		INIWriteString(L"API", L"WriteFile", L"FALSE", strFilePath);
	}
	if (m_chk_writefileEx.GetCheck() == 1){
		//üũ�Ǿ��� ��� 
		INIWriteString(L"API", L"WriteFileEx", L"TRUE", strFilePath);
	}
	else{
		//üũ �ȵǾ��� ���
		INIWriteString(L"API", L"WriteFileEx", L"FALSE", strFilePath);
	}
	if (m_chk_StartDocW.GetCheck() == 1){
		INIWriteString(L"API", L"StartDocW", L"TRUE", strFilePath);
	}
	else{
		INIWriteString(L"API", L"StartDocW", L"FALSE", strFilePath);
	}
	if (m_chk_StartPage.GetCheck() == 1){
		INIWriteString(L"API", L"StartPage", L"TRUE", strFilePath);
	}
	else{
		INIWriteString(L"API", L"StartPage", L"FALSE", strFilePath);
	}
	if (m_chk_EndDoc.GetCheck() == 1){
		INIWriteString(L"API", L"EndDoc", L"TRUE", strFilePath);
	}
	else{
		INIWriteString(L"API", L"EndDoc", L"FALSE", strFilePath);
	}
	if (m_chk_closehandle.GetCheck() == 1){
		INIWriteString(L"API", L"CloseHandle", L"TRUE", strFilePath);
	}
	else{
		INIWriteString(L"API", L"CloseHandle", L"FALSE", strFilePath);
	}
	if (m_chk_SetFilePointer.GetCheck() == 1){
		INIWriteString(L"API", L"SetFilePointer", L"TRUE", strFilePath);
	}
	else{
		INIWriteString(L"API", L"SetFilePointer", L"FALSE", strFilePath);
	}
	if (m_chk_SetFilePointerEx.GetCheck() == 1){
		INIWriteString(L"API", L"SetFilePointerEx", L"TRUE", strFilePath);
	}
	else{
		INIWriteString(L"API", L"SetFilePointerEx", L"FALSE", strFilePath);
	}
	if (m_chk_GetFileSize.GetCheck() == 1){
		INIWriteString(L"API", L"GetFileSize", L"TRUE", strFilePath);
	}
	else{
		INIWriteString(L"API", L"GetFileSize", L"FALSE", strFilePath);
	}
	if (m_chk_GetFileSizeEx.GetCheck() == 1){
		INIWriteString(L"API", L"GetFileSizeEx", L"TRUE", strFilePath);
	}
	else{
		INIWriteString(L"API", L"GetFileSizeEx", L"FALSE", strFilePath);
	}
	if (m_chk_MoveFile.GetCheck() == 1){
		INIWriteString(L"API", L"MoveFile", L"TRUE", strFilePath);
	}
	else{
		INIWriteString(L"API", L"MoveFile", L"FALSE", strFilePath);
	}
	if (m_chk_MoveFileEx.GetCheck() == 1){
		INIWriteString(L"API", L"MoveFileEx", L"TRUE", strFilePath);
	}
	else{
		INIWriteString(L"API", L"MoveFileEx", L"FALSE", strFilePath);
	}
	if (m_chk_CopyFile.GetCheck() == 1){
		INIWriteString(L"API", L"CopyFile", L"TRUE", strFilePath);
	}
	else{
		INIWriteString(L"API", L"CopyFile", L"FALSE", strFilePath);
	}
	if (m_chk_CopyFileEx.GetCheck() == 1){
		INIWriteString(L"API", L"CopyFileEx", L"TRUE", strFilePath);
	}
	else{
		INIWriteString(L"API", L"CopyFileEx", L"FALSE", strFilePath);
	}
	if (m_chk_StartDocA.GetCheck() == 1){
		INIWriteString(L"API", L"StartDocA", L"TRUE", strFilePath);
	}
	else{
		INIWriteString(L"API", L"StartDocA", L"FALSE", strFilePath);
	}
	if (m_chk_CreateWindowExW.GetCheck() == 1){
		INIWriteString(L"API", L"CreateWindowExW", L"TRUE", strFilePath);
	}
	else{
		INIWriteString(L"API", L"CreateWindowExW", L"FALSE", strFilePath);
	}
	if (m_chk_CreateWindowExA.GetCheck() == 1){
		INIWriteString(L"API", L"CreateWindowExA", L"TRUE", strFilePath);
	}
	else{
		INIWriteString(L"API", L"CreateWindowExA", L"FALSE", strFilePath);
	}
	if (m_chk_CreateDCW.GetCheck() == 1){
		INIWriteString(L"API", L"CreateDCW", L"TRUE", strFilePath);
	}
	else{
		INIWriteString(L"API", L"CreateDCW", L"FALSE", strFilePath);
	}
	if (m_chk_CreateDCA.GetCheck() == 1){
		INIWriteString(L"API", L"CreateDCA", L"TRUE", strFilePath);
	}
	else{
		INIWriteString(L"API", L"CreateDCA", L"FALSE", strFilePath);
	}
	CDialogEx::OnOK();
}