// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/cstrike15/gameui/sys_utils.cpp
// Functions: 8
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x101E8490
// Name: void Sys_SetLastError(unsigned long)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Sys_SetLastError(DWORD error)
{
  SetLastError(dwErrCode: error);
}

//------------------------------------------------------------------------------
// Address: 0x101E84A0
// Name: unsigned long Sys_GetLastError(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
DWORD __stdcall Sys_GetLastError()
{
  return GetLastError();
}

//------------------------------------------------------------------------------
// Address: 0x101E84B0
// Name: int Sys_CreateMutex(char const __near *)
// Source: json
//------------------------------------------------------------------------------
HANDLE __cdecl Sys_CreateMutex(const char *mutexName)
{
  return CreateMutexA(lpMutexAttributes: nullptr, bInitialOwner: false, lpName: mutexName);
}

//------------------------------------------------------------------------------
// Address: 0x101E84D0
// Name: void Sys_ReleaseMutex(int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Sys_ReleaseMutex(void *mutexHandle)
{
  ReleaseMutex(hMutex: mutexHandle);
}

//------------------------------------------------------------------------------
// Address: 0x101E84E0
// Name: unsigned int Sys_WaitForSingleObject(int,int)
// Source: json
//------------------------------------------------------------------------------
DWORD __cdecl Sys_WaitForSingleObject(void *mutexHandle, DWORD milliseconds)
{
  return WaitForSingleObject(hHandle: mutexHandle, dwMilliseconds: milliseconds);
}

//------------------------------------------------------------------------------
// Address: 0x101E8500
// Name: unsigned int Sys_RegisterWindowMessage(char const __near *)
// Source: json
//------------------------------------------------------------------------------
UINT __cdecl Sys_RegisterWindowMessage(const char *msgName)
{
  return RegisterWindowMessageA(lpString: msgName);
}

//------------------------------------------------------------------------------
// Address: 0x101E8510
// Name: void Sys_EnumWindows(void __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Sys_EnumWindows(int (__stdcall *callbackFunction)(HWND__ *, int), LPARAM lparam)
{
  EnumWindows(lpEnumFunc: callbackFunction, lParam: lparam);
}

//------------------------------------------------------------------------------
// Address: 0x101E8530
// Name: void Sys_PostMessage(int,unsigned int,unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Sys_PostMessage(HWND wnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
  PostMessageA(hWnd: wnd, Msg: msg, wParam, lParam);
}
