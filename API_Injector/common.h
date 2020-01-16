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

	// #1. dwPID를 이용하여 대상 프로세스의 핸들을 구함
	if (!(hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, dwPID)))
		return FALSE;

	// #2. 대상 프로세스 메모리에 szDllName 크기만큼 메모리 할당
	pRemoteBuf = VirtualAllocEx(hProcess, NULL, dwBufSize, MEM_COMMIT, PAGE_READWRITE);

	// #3. 할당 받은 메모리에 dll 경로를 씀
	WriteProcessMemory(hProcess, pRemoteBuf, (LPVOID)W2A(szDllName), dwBufSize, NULL);

	// #4. LoadLibraryA() API 주소를 구함
	pThreadProc = (LPTHREAD_START_ROUTINE)GetProcAddress(GetModuleHandle(L"kernel32.dll"), "LoadLibraryA");

	// #5. 프로세스에 스레드 실행
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