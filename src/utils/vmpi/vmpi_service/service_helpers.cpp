// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/vmpi/vmpi_service/service_helpers.cpp
// Functions: 7
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x004036F0
// Name: void ServiceHelpers_Init(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ServiceHelpers_Init()
{
  InitializeCriticalSection(lpCriticalSection: &g_CtrlHandlerMutex);
}

//------------------------------------------------------------------------------
// Address: 0x00403700
// Name: void ServiceHelpers_ExitEarly(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ServiceHelpers_ExitEarly()
{
  EnterCriticalSection(lpCriticalSection: &g_CtrlHandlerMutex);
  g_bShouldExit = true;
  LeaveCriticalSection(lpCriticalSection: &g_CtrlHandlerMutex);
}

//------------------------------------------------------------------------------
// Address: 0x00403720
// Name: bool ServiceHelpers_ShouldExit(void)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl ServiceHelpers_ShouldExit()
{
  volatile bool v0; // bl

  EnterCriticalSection(lpCriticalSection: &g_CtrlHandlerMutex);
  v0 = g_bShouldExit;
  LeaveCriticalSection(lpCriticalSection: &g_CtrlHandlerMutex);
  return v0;
}

//------------------------------------------------------------------------------
// Address: 0x00403750
// Name: char __near * GetLastErrorString(void)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl GetLastErrorString()
{
  DWORD LastError; // eax
  void *lpMsgBuf; // [esp+0h] [ebp-4h] BYREF

  LastError = GetLastError();
  FormatMessageA(
    dwFlags: 0x1300u,
    lpSource: nullptr,
    dwMessageId: LastError,
    dwLanguageId: 0x400u,
    lpBuffer: (LPSTR)&lpMsgBuf,
    nSize: 0,
    Arguments: nullptr);
  strncpy(dest: (unsigned __int8 *)err, source: (unsigned __int8 *)lpMsgBuf, count: 0x800u);
  LocalFree(hMem: lpMsgBuf);
  err[2047] = 0;
  return err;
}

//------------------------------------------------------------------------------
// Address: 0x004037B0
// Name: void MyServiceCtrlHandler(unsigned long)
// Source: json
//------------------------------------------------------------------------------
void __stdcall MyServiceCtrlHandler(unsigned int Opcode)
{
  DWORD v1; // eax
  DWORD LastError; // eax

  if ( Opcode == 1 )
  {
    EnterCriticalSection(lpCriticalSection: &g_CtrlHandlerMutex);
    g_bShouldExit = true;
    LeaveCriticalSection(lpCriticalSection: &g_CtrlHandlerMutex);
    MyServiceStatus.dwWin32ExitCode = 0;
    MyServiceStatus.dwCurrentState = 1;
    if ( !SetServiceStatus(hServiceStatus: MyServiceStatusHandle, lpServiceStatus: &MyServiceStatus) )
    {
      LastError = GetLastError();
      _Msg(a1: "[MY_SERVICE] SetServiceStatus error %ld\n", LastError);
    }
    _Msg(a1: "[MY_SERVICE] Leaving MyService \n", 0);
  }
  else
  {
    if ( Opcode != 4 )
      _Msg(a1: "[MY_SERVICE] Unrecognized opcode %ld\n", Opcode);
    if ( !SetServiceStatus(hServiceStatus: MyServiceStatusHandle, lpServiceStatus: &MyServiceStatus) )
    {
      v1 = GetLastError();
      _Msg(a1: "[MY_SERVICE] SetServiceStatus error %ld\n", v1);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00403870
// Name: void MyServiceStart(unsigned long,char __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __stdcall MyServiceStart(unsigned int argc, char **argv)
{
  SERVICE_STATUS_HANDLE v2; // eax
  DWORD v3; // eax
  DWORD LastError; // eax

  MyServiceStatus.dwServiceType = 48;
  MyServiceStatus.dwCurrentState = 2;
  MyServiceStatus.dwControlsAccepted = 1;
  MyServiceStatus.dwWin32ExitCode = 0;
  MyServiceStatus.dwServiceSpecificExitCode = 0;
  MyServiceStatus.dwCheckPoint = 0;
  MyServiceStatus.dwWaitHint = 0;
  v2 = RegisterServiceCtrlHandlerA(lpServiceName: "MyService", lpHandlerProc: MyServiceCtrlHandler);
  MyServiceStatusHandle = v2;
  if ( v2 != nullptr )
  {
    MyServiceStatus.dwCurrentState = 4;
    if ( !SetServiceStatus(hServiceStatus: v2, lpServiceStatus: &MyServiceStatus) )
    {
      LastError = GetLastError();
      _Msg(a1: "[MY_SERVICE] SetServiceStatus error %ld\n", LastError);
    }
    g_pInternalServiceFn(a1: g_pInternalServiceParam);
    MyServiceStatus.dwCurrentState = 1;
    MyServiceStatus.dwWin32ExitCode = 0;
    MyServiceStatus.dwServiceSpecificExitCode = 0;
    SetServiceStatus(hServiceStatus: MyServiceStatusHandle, lpServiceStatus: &MyServiceStatus);
    _Msg(a1: "[MY_SERVICE] Returning the Main Thread \n", 0);
  }
  else
  {
    v3 = GetLastError();
    _Msg(a1: "[MY_SERVICE] RegisterServiceCtrlHandler failed %d\n", v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00403960
// Name: bool ServiceHelpers_StartService(char const __near *,void (*)(void __near *),void __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl ServiceHelpers_StartService(char *pServiceName, void (__cdecl *pFn)(void *), void *pParam)
{
  const char *LastErrorString; // eax
  _SERVICE_TABLE_ENTRYA DispatchTable[2]; // [esp+0h] [ebp-10h] BYREF

  DispatchTable[0].lpServiceName = pServiceName;
  DispatchTable[1].lpServiceName = nullptr;
  DispatchTable[1].lpServiceProc = nullptr;
  DispatchTable[0].lpServiceProc = MyServiceStart;
  g_pInternalServiceFn = pFn;
  g_pInternalServiceParam = pParam;
  if ( StartServiceCtrlDispatcherA(lpServiceStartTable: DispatchTable) )
    return 1;
  LastErrorString = GetLastErrorString();
  _Msg(a1: "StartServiceCtrlDispatcher error = '%s'\n", LastErrorString);
  return 0;
}
