
// stdafx.cpp : ǥ�� ���� ���ϸ� ��� �ִ� �ҽ� �����Դϴ�.
// API_Injector.pch�� �̸� �����ϵ� ����� �˴ϴ�.
// stdafx.obj���� �̸� �����ϵ� ���� ������ ���Ե˴ϴ�.

#include "stdafx.h"

CCriticalSection g_criticalExe;

CString INIReadString(CString strAppName, CString strKeyName, CString strFilePath){
	TCHAR szReturnString[1024] = { 0, };
	memset(szReturnString, NULL, 1024);
	GetPrivateProfileString(strAppName,strKeyName,L"",szReturnString,1024,strFilePath);
	CString str;
	str.Format(L"%s", szReturnString);

	return str;
}

void INIWriteString(CString strAppName, CString strKeyName, CString strValue, CString strFilePath){
	WritePrivateProfileString(strAppName,strKeyName,strValue,strFilePath);
}

CString GetExePath(){
	g_criticalExe.Lock();

	static TCHAR pBuf[256] = { 0, };
	memset(pBuf, NULL, sizeof(pBuf));
	GetModuleFileName(NULL, pBuf, sizeof(pBuf));
	CString strFilePath;
	strFilePath.Format(_T("%s"), pBuf);
	strFilePath = strFilePath.Left(strFilePath.ReverseFind(_T('\\')));
	g_criticalExe.Unlock();
	return strFilePath;
}