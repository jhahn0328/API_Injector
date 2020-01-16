#pragma once
#include <tlhelp32.h> 

typedef BOOL(WINAPI *LPFN_ISWOW64PROCESS) (HANDLE, PBOOL);
static LPFN_ISWOW64PROCESS fnIsWow64Process;

static DWORD FindProcessID(LPCTSTR szProcessName){
	USES_CONVERSION;
	DWORD dwPID = 0xFFFFFFFF;
	HANDLE hSnapShot = INVALID_HANDLE_VALUE;
	PROCESSENTRY32 pe;

	// Get the snapshot of the system
	pe.dwSize = sizeof(PROCESSENTRY32); // 296d (128h)
	hSnapShot = CreateToolhelp32Snapshot(TH32CS_SNAPALL, NULL); // ProcessID = 0

	// find process
	Process32First(hSnapShot, &pe);
	do
	{
		if (!_stricmp(W2A(szProcessName), W2A(pe.szExeFile)))
		{
			dwPID = pe.th32ProcessID;
			break;
		}
	} while (Process32Next(hSnapShot, &pe));

	CloseHandle(hSnapShot);

	return dwPID;
}

static BOOL InjectDll(DWORD dwPID, LPCTSTR szDllName){
	USES_CONVERSION;
	HANDLE hProcess, hThread;
	LPVOID pRemoteBuf;
	DWORD dwBufSize = lstrlen(szDllName) + 1;
	LPTHREAD_START_ROUTINE pThreadProc;

	// #1. dwPID�� �̿��Ͽ� ��� ���μ����� �ڵ��� ����
	if (!(hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, dwPID)))
		return FALSE;

	// #2. ��� ���μ��� �޸𸮿� szDllName ũ�⸸ŭ �޸� �Ҵ�
	pRemoteBuf = VirtualAllocEx(hProcess, NULL, dwBufSize, MEM_COMMIT, PAGE_READWRITE);

	// #3. �Ҵ� ���� �޸𸮿� dll ��θ� ��
	WriteProcessMemory(hProcess, pRemoteBuf, (LPVOID)W2A(szDllName), dwBufSize, NULL);

	// #4. LoadLibraryA() API �ּҸ� ����
	pThreadProc = (LPTHREAD_START_ROUTINE)GetProcAddress(GetModuleHandle(L"kernel32.dll"), "LoadLibraryA");

	// #5. ���μ����� ������ ����
	hThread = CreateRemoteThread(hProcess, NULL, 0, pThreadProc, pRemoteBuf, 0, NULL);
	WaitForSingleObject(hThread, INFINITE);

	CloseHandle(hThread);
	CloseHandle(hProcess);

	return TRUE;
}

static BOOL IsWow64(DWORD pPID){
BOOL bIsWow64 = FALSE;
HANDLE hProcess = NULL;
fnIsWow64Process = (LPFN_ISWOW64PROCESS)GetProcAddress(
GetModuleHandle(TEXT("kernel32")), "IsWow64Process");
hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pPID);
if (!fnIsWow64Process(hProcess, &bIsWow64))
{
//handle error
}
return bIsWow64;
}