// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: vgui2/src/system.cpp
// Functions: 38
// ============================================================

#include "vgui2\src\system.h"

//------------------------------------------------------------------------------
// Address: 0x100140B0
// Name: GetMainApplicationWindowHWND_EnumProc
// Source: json
//------------------------------------------------------------------------------
int __stdcall GetMainApplicationWindowHWND_EnumProc(HWND hWnd, HWND *lParam)
{
  HWND v2; // esi

  v2 = hWnd;
  GetWindowThreadProcessId(hWnd, lpdwProcessId: (LPDWORD)&hWnd);
  if ( (HWND)GetCurrentProcessId() != hWnd || !IsWindowVisible(hWnd: v2) || !IsWindowEnabled(hWnd: v2) )
    return 1;
  *lParam = v2;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10014100
// Name: GetMainApplicationWindowHWND
// Source: json
//------------------------------------------------------------------------------
HWND__ *__cdecl GetMainApplicationWindowHWND()
{
  DWORD CurrentThreadId; // esi
  HWND__ *i; // eax
  HWND__ *result; // eax
  tagGUITHREADINFO gti; // [esp+4h] [ebp-34h] BYREF
  HWND__ *hWnd; // [esp+34h] [ebp-4h] BYREF

  hWnd = nullptr;
  CurrentThreadId = GetCurrentThreadId();
  memset(dst: (unsigned __int8 *)&gti, value: 0, count: sizeof(gti));
  gti.cbSize = 48;
  GetGUIThreadInfo(idThread: CurrentThreadId, pgui: &gti);
  hWnd = gti.hwndActive;
  if ( gti.hwndActive != nullptr )
  {
    for ( i = GetParent(hWnd: gti.hwndActive); i != nullptr; i = GetParent(hWnd: i) )
      hWnd = i;
  }
  result = hWnd;
  if ( hWnd == nullptr )
  {
    EnumWindows(lpEnumFunc: (WNDENUMPROC)GetMainApplicationWindowHWND_EnumProc, lParam: (LPARAM)&hWnd);
    return hWnd;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10014190
// Name: public: virtual void CSystem::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSystem::Shutdown(CSystem *this)
{
  KeyValues *m_pUserConfigData; // ecx

  m_pUserConfigData = this->m_pUserConfigData;
  if ( m_pUserConfigData != nullptr )
  {
    KeyValues::deleteThis(this: m_pUserConfigData);
    this->m_pUserConfigData = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100141B0
// Name: public: virtual void CSystem::RunFrame(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSystem::RunFrame(CSystem *this)
{
  __int64 v2; // rax
  int v3; // eax
  int v4; // ecx
  int v5; // edx
  int y; // [esp+4h] [ebp-8h] BYREF
  int x; // [esp+8h] [ebp-4h] BYREF

  this->m_flFrameTime = this->GetTickCount(this);
  if ( this->m_bStaticWatchForComputerUse )
  {
    vgui::g_pInput->GetCursorPos(this: vgui::g_pInput, a2: &x, a3: &y);
    v2 = y + x - this->m_iStaticMouseOldY - this->m_iStaticMouseOldX;
    if ( (int)((HIDWORD(v2) ^ v2) - HIDWORD(v2)) > 50 )
    {
      v3 = this->GetTimeMillis(this);
      v4 = x;
      v5 = y;
      this->m_StaticLastComputerUseTime = (double)v3 * 0.001;
      this->m_iStaticMouseOldX = v4;
      this->m_iStaticMouseOldY = v5;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10014230
// Name: public: virtual double CSystem::GetFrameTime(void)
// Source: json
//------------------------------------------------------------------------------
long double __thiscall CSystem::GetFrameTime(CSystem *this)
{
  return this->m_flFrameTime;
}

//------------------------------------------------------------------------------
// Address: 0x10014240
// Name: public: virtual double CSystem::GetCurrentTime(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
long double __thiscall CSystem::GetCurrentTime(CSystem *this)
{
  return _Plat_FloatTime(this);
}

//------------------------------------------------------------------------------
// Address: 0x10014250
// Name: public: virtual long CSystem::GetTimeMillis(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSystem::GetTimeMillis(CSystem *this)
{
  return (int)(this->GetTickCount(this) * 1000.0);
}

//------------------------------------------------------------------------------
// Address: 0x10014270
// Name: public: virtual void CSystem::ShellExecute(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSystem::ShellExecute(CSystem *this, const char *command, const char *file)
{
  ShellExecuteA(
    hwnd: nullptr,
    lpOperation: command,
    lpFile: file,
    lpParameters: nullptr,
    lpDirectory: nullptr,
    nShowCmd: 1);
}

//------------------------------------------------------------------------------
// Address: 0x10014290
// Name: public: virtual void CSystem::ShellExecuteExA(char const __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSystem::ShellExecuteExA(CSystem *this, const char *command, const char *file, const char *pParams)
{
  ShellExecuteA(
    hwnd: nullptr,
    lpOperation: command,
    lpFile: file,
    lpParameters: pParams,
    lpDirectory: nullptr,
    nShowCmd: 1);
}

//------------------------------------------------------------------------------
// Address: 0x100142B0
// Name: public: virtual void CSystem::SetClipboardImage(void __near *,int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSystem::SetClipboardImage(CSystem *this, HBITMAP__ *pWnd, int x1, int y1, int x2, HWND__ *y2)
{
  HDC DC; // esi
  int v8; // ebx
  HDC CompatibleDC; // edi
  HWND DesktopWindow; // eax
  HBITMAP__ *hBmMem; // [esp+0h] [ebp-4h]
  HBITMAP__ *hBmOld; // [esp+Ch] [ebp+8h]
  int x2a; // [esp+18h] [ebp+14h]
  HWND__ *hWnd; // [esp+1Ch] [ebp+18h]

  if ( x2 > x1 && (int)y2 > y1 )
  {
    hWnd = (HWND__ *)pWnd;
    if ( pWnd != nullptr || (hWnd = GetMainApplicationWindowHWND()) != nullptr )
    {
      DC = GetDC(hWnd);
      v8 = (int)y2 - y1;
      CompatibleDC = CreateCompatibleDC(hdc: DC);
      x2a = x2 - x1;
      hBmMem = CreateCompatibleBitmap(hdc: DC, cx: x2a, cy: v8);
      hBmOld = (HBITMAP__ *)SelectObject(hdc: CompatibleDC, h: hBmMem);
      BitBlt(hdc: CompatibleDC, x: 0, y: 0, cx: x2a, cy: v8, hdcSrc: DC, x1, y1, rop: 0xCC0020u);
      SelectObject(hdc: CompatibleDC, h: hBmOld);
      DeleteDC(hdc: CompatibleDC);
      ReleaseDC(hWnd, hDC: DC);
      DesktopWindow = GetDesktopWindow();
      if ( OpenClipboard(hWndNewOwner: DesktopWindow) )
      {
        EmptyClipboard();
        if ( hBmMem != nullptr )
          SetClipboardData(uFormat: 2u, hMem: hBmMem);
        CloseClipboard();
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100143A0
// Name: public: virtual void CSystem::SetClipboardText(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSystem::SetClipboardText(CSystem *this, char *text, int textLen)
{
  HWND DesktopWindow; // eax
  HGLOBAL v4; // eax
  void *v5; // esi
  unsigned __int8 *v6; // eax
  unsigned __int8 *v7; // edi

  if ( text != nullptr && textLen > 0 )
  {
    DesktopWindow = GetDesktopWindow();
    if ( OpenClipboard(hWndNewOwner: DesktopWindow) )
    {
      EmptyClipboard();
      v4 = GlobalAlloc(uFlags: 2u, dwBytes: textLen + 1);
      v5 = v4;
      if ( v4 != nullptr )
      {
        v6 = (unsigned __int8 *)GlobalLock(hMem: v4);
        v7 = v6;
        if ( v6 != nullptr )
        {
          memset(dst: v6, value: 0, count: textLen + 1);
          memcpy(dst: v7, src: (unsigned __int8 *)text, count: textLen);
          GlobalUnlock(hMem: v5);
          SetClipboardData(uFormat: 1u, hMem: v5);
        }
      }
      CloseClipboard();
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10014420
// Name: public: virtual void CSystem::SetClipboardText(wchar_t const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSystem::SetClipboardText(CSystem *this, wchar_t *text, int textLen)
{
  HWND DesktopWindow; // eax
  unsigned int v4; // ebx
  HGLOBAL v5; // eax
  void *v6; // esi
  unsigned __int8 *v7; // edi

  if ( text != nullptr && textLen > 0 )
  {
    DesktopWindow = GetDesktopWindow();
    if ( OpenClipboard(hWndNewOwner: DesktopWindow) )
    {
      EmptyClipboard();
      v4 = 2 * textLen;
      v5 = GlobalAlloc(uFlags: 2u, dwBytes: 2 * textLen + 2);
      v6 = v5;
      if ( v5 != nullptr )
      {
        v7 = (unsigned __int8 *)GlobalLock(hMem: v5);
        if ( v7 != nullptr )
        {
          memset(dst: v7, value: 0, count: v4 + 2);
          memcpy(dst: v7, src: (unsigned __int8 *)text, count: v4);
          GlobalUnlock(hMem: v6);
          SetClipboardData(uFormat: 0xDu, hMem: v6);
        }
      }
      CloseClipboard();
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100144B0
// Name: public: virtual int CSystem::GetClipboardTextCount(void)
// Source: json
//------------------------------------------------------------------------------
SIZE_T __thiscall CSystem::GetClipboardTextCount(CSystem *this)
{
  SIZE_T v1; // esi
  HWND DesktopWindow; // eax
  HANDLE ClipboardData; // eax

  v1 = 0;
  DesktopWindow = GetDesktopWindow();
  if ( OpenClipboard(hWndNewOwner: DesktopWindow) )
  {
    ClipboardData = GetClipboardData(uFormat: 1u);
    if ( ClipboardData != nullptr )
      v1 = GlobalSize(hMem: ClipboardData);
    CloseClipboard();
  }
  return v1;
}

//------------------------------------------------------------------------------
// Address: 0x100144F0
// Name: public: virtual int CSystem::GetClipboardText(int,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSystem::GetClipboardText(CSystem *this, int offset, char *buf, int bufLen)
{
  signed int v4; // esi
  HWND DesktopWindow; // eax
  HANDLE ClipboardData; // eax
  void *v7; // edi
  unsigned __int8 *v9; // eax

  v4 = 0;
  if ( buf != nullptr && bufLen > 0 )
  {
    DesktopWindow = GetDesktopWindow();
    if ( OpenClipboard(hWndNewOwner: DesktopWindow) )
    {
      ClipboardData = GetClipboardData(uFormat: 0xDu);
      v7 = ClipboardData;
      if ( ClipboardData != nullptr )
      {
        v4 = GlobalSize(hMem: ClipboardData) - offset;
        if ( v4 <= 0 )
        {
          CloseClipboard();
          return 0;
        }
        if ( bufLen < v4 )
          v4 = bufLen;
        v9 = (unsigned __int8 *)GlobalLock(hMem: v7);
        if ( v9 != nullptr )
        {
          memcpy(dst: (unsigned __int8 *)buf, src: &v9[offset], count: v4);
          GlobalUnlock(hMem: v7);
        }
      }
      CloseClipboard();
    }
  }
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x10014580
// Name: public: virtual int CSystem::GetClipboardText(int,wchar_t __near *,int)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CSystem::GetClipboardText(CSystem *this, int offset, wchar_t *buf, int bufLen)
{
  HWND DesktopWindow; // eax
  HANDLE ClipboardData; // eax
  void *v6; // edi
  signed int v7; // esi
  unsigned __int8 *v8; // eax

  if ( buf != nullptr && bufLen > 0 )
  {
    DesktopWindow = GetDesktopWindow();
    if ( OpenClipboard(hWndNewOwner: DesktopWindow) )
    {
      ClipboardData = GetClipboardData(uFormat: 0xDu);
      v6 = ClipboardData;
      if ( ClipboardData != nullptr )
      {
        v7 = GlobalSize(hMem: ClipboardData) - offset;
        if ( v7 > 0 )
        {
          if ( bufLen < v7 )
            v7 = bufLen;
          v8 = (unsigned __int8 *)GlobalLock(hMem: v6);
          if ( v8 != nullptr )
          {
            memcpy(dst: (unsigned __int8 *)buf, src: &v8[2 * offset], count: v7);
            GlobalUnlock(hMem: v6);
            CloseClipboard();
            return (unsigned int)v7 >> 1;
          }
        }
      }
    }
    CloseClipboard();
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10014620
// Name: staticSplitRegistryKey
// Source: json
//------------------------------------------------------------------------------
char __cdecl staticSplitRegistryKey(char *key, char *key0, char *key0Len)
{
  int v4; // eax
  int v5; // esi
  int v6; // eax
  int v7; // edi

  if ( key == nullptr )
    return 0;
  v4 = strlen(key);
  v5 = v4;
  if ( v4 <= 0 )
    return 0;
  v6 = v4 - 1;
  v7 = -1;
  if ( v5 - 1 < 0 )
    return 0;
  do
  {
    if ( key[v6] == 92 )
      break;
    v7 = v6--;
  }
  while ( v6 >= 0 );
  if ( v7 == -1 )
    return 0;
  vgui::vgui_strcpy(dst: key0, dstLen: v7 + 1, src: key);
  vgui::vgui_strcpy(dst: key0Len, dstLen: v5 - v7 + 1, src: &key[v7]);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100146A0
// Name: public: virtual bool CSystem::SetRegistryString(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CSystem::SetRegistryString(CSystem *this, HKEY__ *key, const char *value)
{
  char *v3; // edi
  int v4; // esi
  const BYTE *v5; // edi
  char key1[256]; // [esp+8h] [ebp-200h] BYREF
  char key0[256]; // [esp+108h] [ebp-100h] BYREF

  v3 = (char *)key;
  v4 = -2147483647;
  if ( strncmp(first: (const char *)key, last: "HKEY_LOCAL_MACHINE", count: 0x12u) == 0 )
  {
    v4 = -2147483646;
    v3 += 19;
  }
  else if ( strncmp(first: v3, last: "HKEY_CURRENT_USER", count: 0x11u) == 0 )
  {
    v3 += 18;
  }
  if ( staticSplitRegistryKey(key: v3, key0, key0Len: key1) != 0 )
  {
    v5 = (const BYTE *)value;
    if ( RegCreateKeyExA(
           hKey: (HKEY)v4,
           lpSubKey: key0,
           Reserved: 0,
           lpClass: nullptr,
           dwOptions: 0,
           samDesired: value != nullptr ? 131078 : 983103,
           lpSecurityAttributes: nullptr,
           phkResult: &key,
           lpdwDisposition: nullptr) == 0 )
    {
      if ( RegSetValueExA(
             hKey: key,
             lpValueName: key1,
             Reserved: 0,
             dwType: 1u,
             lpData: v5,
             cbData: strlen((const char *)v5) + 1) == 0 )
      {
        RegCloseKey(hKey: key);
        return 1;
      }
      RegCloseKey(hKey: key);
    }
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10014790
// Name: public: virtual bool CSystem::GetRegistryString(char const __near *,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CSystem::GetRegistryString(CSystem *this, char *key, HKEY__ *value, const char *valueLen)
{
  unsigned __int8 *v4; // ebx
  char *v6; // esi
  int v7; // edi
  const char *v8; // [esp-14h] [ebp-218h]
  char key1[256]; // [esp+4h] [ebp-200h] BYREF
  char key0[256]; // [esp+104h] [ebp-100h] BYREF

  v4 = (unsigned __int8 *)value;
  if ( value == nullptr )
    return 0;
  v6 = key;
  v8 = key;
  *(_BYTE *)value = 0;
  v7 = -2147483647;
  if ( strncmp(first: v8, last: "HKEY_LOCAL_MACHINE", count: 0x12u) == 0 )
  {
    v7 = -2147483646;
    v6 += 19;
  }
  else if ( strncmp(first: v6, last: "HKEY_CURRENT_USER", count: 0x11u) == 0 )
  {
    v6 += 18;
  }
  if ( staticSplitRegistryKey(key: v6, key0, key0Len: key1) != 0
    && RegOpenKeyExA(hKey: (HKEY)v7, lpSubKey: key0, ulOptions: 0, samDesired: 0x20019u, phkResult: &value) == 0 )
  {
    key = (char *)valueLen;
    if ( RegQueryValueExA(
           hKey: value,
           lpValueName: key1,
           lpReserved: nullptr,
           lpType: nullptr,
           lpData: v4,
           lpcbData: (LPDWORD)&key) == 0 )
    {
      RegCloseKey(hKey: value);
      return 1;
    }
    RegCloseKey(hKey: value);
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10014870
// Name: public: virtual bool CSystem::SetRegistryInteger(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CSystem::SetRegistryInteger(CSystem *this, HKEY__ *key, int value)
{
  char *v3; // esi
  int v4; // edi
  char key1[256]; // [esp+8h] [ebp-200h] BYREF
  char key0[256]; // [esp+108h] [ebp-100h] BYREF

  v3 = (char *)key;
  v4 = -2147483647;
  if ( strncmp(first: (const char *)key, last: "HKEY_LOCAL_MACHINE", count: 0x12u) == 0 )
  {
    v4 = -2147483646;
    v3 += 19;
  }
  else if ( strncmp(first: v3, last: "HKEY_CURRENT_USER", count: 0x11u) == 0 )
  {
    v3 += 18;
  }
  if ( staticSplitRegistryKey(key: v3, key0, key0Len: key1) != 0
    && RegCreateKeyExA(
         hKey: (HKEY)v4,
         lpSubKey: key0,
         Reserved: 0,
         lpClass: nullptr,
         dwOptions: 0,
         samDesired: 0x20006u,
         lpSecurityAttributes: nullptr,
         phkResult: &key,
         lpdwDisposition: nullptr) == 0 )
  {
    if ( RegSetValueExA(hKey: key, lpValueName: key1, Reserved: 0, dwType: 4u, lpData: (const BYTE *)&value, cbData: 4u) == 0 )
    {
      RegCloseKey(hKey: key);
      return 1;
    }
    RegCloseKey(hKey: key);
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10014940
// Name: public: virtual bool CSystem::GetRegistryInteger(char const __near *,int __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CSystem::GetRegistryInteger(CSystem *this, HKEY__ *key, int *value)
{
  char *v3; // esi
  int v4; // edi
  char key1[256]; // [esp+8h] [ebp-204h] BYREF
  char key0[256]; // [esp+108h] [ebp-104h] BYREF
  unsigned int len; // [esp+208h] [ebp-4h] BYREF

  v3 = (char *)key;
  v4 = -2147483647;
  if ( strncmp(first: (const char *)key, last: "HKEY_LOCAL_MACHINE", count: 0x12u) == 0 )
  {
    v4 = -2147483646;
    v3 += 19;
  }
  else if ( strncmp(first: v3, last: "HKEY_CURRENT_USER", count: 0x11u) == 0 )
  {
    v3 += 18;
  }
  if ( staticSplitRegistryKey(key: v3, key0, key0Len: key1) != 0
    && RegOpenKeyExA(hKey: (HKEY)v4, lpSubKey: key0, ulOptions: 0, samDesired: 0x20019u, phkResult: &key) == 0 )
  {
    len = 4;
    if ( RegQueryValueExA(
           hKey: key,
           lpValueName: key1,
           lpReserved: nullptr,
           lpType: nullptr,
           lpData: (LPBYTE)value,
           lpcbData: &len) == 0 )
    {
      RegCloseKey(hKey: key);
      return 1;
    }
    RegCloseKey(hKey: key);
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10014A10
// Name: public: virtual bool CSystem::DeleteRegistryKey(char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CSystem::DeleteRegistryKey(CSystem *this, const char *key)
{
  const char *v2; // esi

  v2 = key;
  if ( strncmp(first: key, last: "HKEY_LOCAL_MACHINE", count: 0x12u) == 0 )
    return SHDeleteKeyA(hkey: HKEY_LOCAL_MACHINE, pszSubKey: key + 19) == 0;
  if ( strncmp(first: key, last: "HKEY_CURRENT_USER", count: 0x11u) == 0 )
    v2 = key + 18;
  return SHDeleteKeyA(hkey: HKEY_CURRENT_USER, pszSubKey: v2) == 0;
}

//------------------------------------------------------------------------------
// Address: 0x10014A80
// Name: public: virtual bool CSystem::SetWatchForComputerUse(bool)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CSystem::SetWatchForComputerUse(CSystem *this, bool state)
{
  if ( state != this->m_bStaticWatchForComputerUse )
    this->m_bStaticWatchForComputerUse = state;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10014AA0
// Name: public: virtual double CSystem::GetTimeSinceLastUse(void)
// Source: json
//------------------------------------------------------------------------------
long double __thiscall CSystem::GetTimeSinceLastUse(CSystem *this)
{
  if ( this->m_bStaticWatchForComputerUse )
    return (double)this->GetTimeMillis(this) * 0.001 - this->m_StaticLastComputerUseTime;
  else
    return 0.0;
}

//------------------------------------------------------------------------------
// Address: 0x10014AD0
// Name: public: virtual int CSystem::GetAvailableDrives(char __near *,int)
// Source: json
//------------------------------------------------------------------------------
DWORD __thiscall CSystem::GetAvailableDrives(CSystem *this, char *buf, DWORD bufLen)
{
  return GetLogicalDriveStringsA(nBufferLength: bufLen, lpBuffer: buf);
}

//------------------------------------------------------------------------------
// Address: 0x10014AF0
// Name: public: virtual double CSystem::GetFreeDiskSpace(char const __near *)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CSystem::GetFreeDiskSpace(CSystem *this, const char *path)
{
  int v2; // eax
  _ULARGE_INTEGER v3; // kr00_8
  char buf[260]; // [esp+0h] [ebp-11Ch] BYREF
  _ULARGE_INTEGER totalBytes; // [esp+104h] [ebp-18h] BYREF
  _ULARGE_INTEGER totalFreeBytes; // [esp+10Ch] [ebp-10h] BYREF
  _ULARGE_INTEGER userFreeBytes; // [esp+114h] [ebp-8h] BYREF

  strcpy(buf, path);
  strstr(str1: (unsigned __int8 *)buf, str2: "\\");
  if ( v2 != 0 )
    *(_BYTE *)(v2 + 1) = 0;
  if ( !GetDiskFreeSpaceExA(
          lpDirectoryName: buf,
          lpFreeBytesAvailableToCaller: &userFreeBytes,
          lpTotalNumberOfBytes: &totalBytes,
          lpTotalNumberOfFreeBytes: &totalFreeBytes) )
    return 0.0;
  v3 = userFreeBytes;
  userFreeBytes.QuadPart &= 0x8000000000000000uLL;
  return (double)v3.QuadPart;
}

//------------------------------------------------------------------------------
// Address: 0x10014B90
// Name: public: virtual class KeyValues __near * CSystem::GetUserConfigFileData(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
KeyValues *__thiscall CSystem::GetUserConfigFileData(CSystem *this, const char *dialogName, int dialogID)
{
  char buf[256]; // [esp+4h] [ebp-100h] BYREF

  if ( this->m_pUserConfigData == nullptr )
    return nullptr;
  if ( dialogID == 0 )
    return KeyValues::FindKey(this: this->m_pUserConfigData, keyName: dialogName, bCreate: true);
  V_snprintf(pDest: buf, maxLen: 256, pFormat: "%s_%d", dialogName, dialogID);
  return KeyValues::FindKey(this: this->m_pUserConfigData, keyName: buf, bCreate: true);
}

//------------------------------------------------------------------------------
// Address: 0x10014C00
// Name: public: virtual void CSystem::SetUserConfigFile(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSystem::SetUserConfigFile(CSystem *this, char *fileName, char *pathName)
{
  KeyValues *v4; // eax
  KeyValues *v5; // eax

  if ( this->m_pUserConfigData == nullptr )
  {
    v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v4 != nullptr )
      v5 = KeyValues::KeyValues(this: v4, setName: "UserConfigData");
    else
      v5 = nullptr;
    this->m_pUserConfigData = v5;
  }
  strncpy(dest: (unsigned __int8 *)this->m_szFileName, source: (unsigned __int8 *)fileName, count: 0x103u);
  strncpy(dest: (unsigned __int8 *)this->m_szPathID, source: (unsigned __int8 *)pathName, count: 0x103u);
  KeyValues::UsesEscapeSequences(this: this->m_pUserConfigData, state: true);
  if ( g_pFullFileSystem != nullptr )
    KeyValues::LoadFromFile(
      this: this->m_pUserConfigData,
      filesystem: &g_pFullFileSystem->IBaseFileSystem,
      resourceName: this->m_szFileName,
      pathID: this->m_szPathID,
      pfnEvaluateSymbolProc: nullptr);
  else
    KeyValues::LoadFromFile(
      this: this->m_pUserConfigData,
      filesystem: nullptr,
      resourceName: this->m_szFileName,
      pathID: this->m_szPathID,
      pfnEvaluateSymbolProc: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x10014CA0
// Name: public: virtual void CSystem::SaveUserConfigFile(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSystem::SaveUserConfigFile(CSystem *this)
{
  KeyValues *m_pUserConfigData; // ecx

  m_pUserConfigData = this->m_pUserConfigData;
  if ( m_pUserConfigData != nullptr )
  {
    if ( g_pFullFileSystem != nullptr )
      KeyValues::SaveToFile(
        this: m_pUserConfigData,
        filesystem: &g_pFullFileSystem->IBaseFileSystem,
        resourceName: this->m_szFileName,
        pathID: this->m_szPathID);
    else
      KeyValues::SaveToFile(
        this: m_pUserConfigData,
        filesystem: nullptr,
        resourceName: this->m_szFileName,
        pathID: this->m_szPathID);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10014CE0
// Name: public: virtual bool CSystem::CommandLineParamExists(char const __near *)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CSystem::CommandLineParamExists(CSystem *this, char *paramName)
{
  unsigned __int8 *v2; // eax
  int v3; // eax

  v2 = (unsigned __int8 *)this->GetFullCommandLine(this);
  strstr(str1: v2, str2: (unsigned __int8 *)paramName);
  return v3 != 0;
}

//------------------------------------------------------------------------------
// Address: 0x10014D10
// Name: public: virtual bool CSystem::GetCommandLineParamValue(char const __near *,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CSystem::GetCommandLineParamValue(CSystem *this, char *paramName, char *value, int valueBufferSize)
{
  unsigned __int8 *v4; // eax
  int v5; // eax
  char token[512]; // [esp+4h] [ebp-200h] BYREF

  v4 = (unsigned __int8 *)this->GetFullCommandLine(this);
  strstr(str1: v4, str2: (unsigned __int8 *)paramName);
  if ( v5 == 0 )
    return 0;
  ParseFile(pFileBytes: (char *)(v5 + strlen(paramName)), pToken: token, pWasQuoted: nullptr, pCharSet: nullptr);
  strncpy(dest: (unsigned __int8 *)value, source: (unsigned __int8 *)token, count: valueBufferSize - 1);
  value[valueBufferSize - 1] = 0;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10014D90
// Name: public: virtual char const __near * CSystem::GetFullCommandLine(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
LPSTR __stdcall CSystem::GetFullCommandLine()
{
  return GetCommandLineA();
}

//------------------------------------------------------------------------------
// Address: 0x10014DA0
// Name: public: virtual enum ButtonCode_t CSystem::KeyCode_VirtualKeyToVGUI(int)
// Source: json
//------------------------------------------------------------------------------
ButtonCode_t __thiscall CSystem::KeyCode_VirtualKeyToVGUI(CSystem *this, int keyCode)
{
  return KeyCode_VirtualKeyToVGUI(key: keyCode);
}

//------------------------------------------------------------------------------
// Address: 0x10014DC0
// Name: public: virtual bool CSystem::GetCurrentTimeAndDate(int __near *,int __near *,int __near *,int __near *,int __near *,int __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CSystem::GetCurrentTimeAndDate(
        CSystem *this,
        int *year,
        int *month,
        int *dayOfWeek,
        int *day,
        int *hour,
        int *minute,
        int *second)
{
  _SYSTEMTIME time; // [esp+0h] [ebp-10h] BYREF

  GetLocalTime(lpSystemTime: &time);
  if ( year != nullptr )
    *year = time.wYear;
  if ( month != nullptr )
    *month = time.wMonth;
  if ( dayOfWeek != nullptr )
    *dayOfWeek = time.wDayOfWeek;
  if ( day != nullptr )
    *day = time.wDay;
  if ( hour != nullptr )
    *hour = time.wHour;
  if ( minute != nullptr )
    *minute = time.wMinute;
  if ( second != nullptr )
    *second = time.wSecond;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10014E40
// Name: public: virtual bool CSystem::CreateShortcut(char const __near *,char const __near *,char const __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CSystem::CreateShortcut(
        CSystem *this,
        IShellLinkA *linkFileName,
        IPersistFile *targetPath,
        const char *arguments,
        const char *workingDirectory,
        const char *iconFile)
{
  const char *v6; // esi
  char v7; // bl
  IShellLinkA *v8; // eax
  int v9; // edx
  char v10; // cl
  wchar_t wsz[260]; // [esp+8h] [ebp-33Ch] BYREF
  char temp[260]; // [esp+210h] [ebp-134h] BYREF
  _stat64i32 statBuf; // [esp+314h] [ebp-30h] BYREF

  v6 = (const char *)linkFileName;
  v7 = 0;
  v8 = linkFileName;
  v9 = temp - (char *)linkFileName;
  do
  {
    v10 = (char)v8->__vftable;
    *((_BYTE *)&v8->__vftable + v9) = v8->__vftable;
    v8 = (IShellLinkA *)((char *)v8 + 1);
  }
  while ( v10 != 0 );
  if ( _stat64i32(name: v6, buf: &statBuf) != -1 )
    return 0;
  if ( CoCreateInstance(
         rclsid: &CLSID_ShellLink,
         pUnkOuter: nullptr,
         dwClsContext: 1u,
         riid: &IID_IShellLinkA,
         ppv: (LPVOID *)&linkFileName) >= 0 )
  {
    linkFileName->SetPath(this: linkFileName, a2: (const char *)targetPath);
    linkFileName->SetArguments(this: linkFileName, a2: arguments);
    if ( workingDirectory != nullptr && *workingDirectory != 0 )
      linkFileName->SetWorkingDirectory(this: linkFileName, a2: workingDirectory);
    if ( iconFile != nullptr && *iconFile != 0 )
      linkFileName->SetIconLocation(this: linkFileName, a2: iconFile, a3: 0);
    if ( linkFileName->QueryInterface(this: linkFileName, a2: &IID_IPersistFile, a3: (void **)&targetPath) >= 0 )
    {
      MultiByteToWideChar(
        CodePage: 0,
        dwFlags: 1u,
        lpMultiByteStr: temp,
        cbMultiByte: -1,
        lpWideCharStr: wsz,
        cchWideChar: 260);
      if ( targetPath->Save(this: targetPath, a2: wsz, a3: 1) >= 0 )
        v7 = 1;
      targetPath->Release(this: targetPath);
    }
    linkFileName->Release(this: linkFileName);
  }
  return v7;
}

//------------------------------------------------------------------------------
// Address: 0x10014F80
// Name: public: virtual bool CSystem::GetShortcutTarget(char const __near *,char __near *,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
BOOL __userpurge CSystem::GetShortcutTarget@<eax>(
        CSystem *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>,
        IShellLinkA *linkFileName,
        IPersistFile *targetPath,
        char *arguments,
        int destBufferSizes)
{
  IShellLinkA *v7; // eax
  int v8; // edx
  char v9; // cl
  IPersistFile *v10; // edi
  char *v11; // ebx
  int v12; // esi
  wchar_t wsz[260]; // [esp+0h] [ebp-30Ch] BYREF
  char temp[260]; // [esp+208h] [ebp-104h] BYREF

  v7 = linkFileName;
  v8 = temp - (char *)linkFileName;
  do
  {
    v9 = (char)v7->__vftable;
    *((_BYTE *)&v7->__vftable + v8) = v7->__vftable;
    v7 = (IShellLinkA *)((char *)v7 + 1);
  }
  while ( v9 != 0 );
  strlwr(string: temp);
  v10 = targetPath;
  v11 = arguments;
  LOBYTE(targetPath->__vftable) = 0;
  *v11 = 0;
  if ( CoCreateInstance(
         rclsid: &CLSID_ShellLink,
         pUnkOuter: nullptr,
         dwClsContext: 1u,
         riid: &IID_IShellLinkA,
         ppv: (LPVOID *)&linkFileName) >= 0 )
  {
    if ( ((int (__stdcall *)(IShellLinkA *, GUID *, IPersistFile **, int))linkFileName->QueryInterface)(
           a1: linkFileName,
           a2: &IID_IPersistFile,
           a3: &targetPath,
           a4: a3) >= 0 )
    {
      MultiByteToWideChar(
        CodePage: 0,
        dwFlags: 1u,
        lpMultiByteStr: temp,
        cbMultiByte: -1,
        lpWideCharStr: wsz,
        cchWideChar: 260);
      if ( ((int (__stdcall *)(IPersistFile *, wchar_t *, _DWORD, int))targetPath->Load)(
             a1: targetPath,
             a2: wsz,
             a3: 0,
             a4: a2) >= 0 )
      {
        v12 = destBufferSizes;
        linkFileName->GetPath(this: linkFileName, a2: (char *)v10, a3: destBufferSizes, a4: nullptr, a5: 2u);
        linkFileName->GetArguments(this: linkFileName, a2: v11, a3: v12);
      }
      ((void (__cdecl *)(IPersistFile *))targetPath->Release)(a1: targetPath);
    }
    ((void (__cdecl *)(IShellLinkA *))linkFileName->Release)(a1: linkFileName);
  }
  return LOBYTE(v10->__vftable) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x10015080
// Name: public: virtual bool CSystem::ModifyShortcutTarget(char const __near *,char const __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CSystem::ModifyShortcutTarget(
        CSystem *this,
        IShellLinkA *linkFileName,
        const char *targetPath,
        const char *arguments,
        const char *workingDirectory)
{
  IShellLinkA *v5; // eax
  char v6; // bl
  int v7; // edx
  char v8; // cl
  wchar_t wsz[260]; // [esp+4h] [ebp-310h] BYREF
  char temp[260]; // [esp+20Ch] [ebp-108h] BYREF
  IPersistFile *ppf; // [esp+310h] [ebp-4h] BYREF

  v5 = linkFileName;
  v6 = 0;
  v7 = temp - (char *)linkFileName;
  do
  {
    v8 = (char)v5->__vftable;
    *((_BYTE *)&v5->__vftable + v7) = v5->__vftable;
    v5 = (IShellLinkA *)((char *)v5 + 1);
  }
  while ( v8 != 0 );
  strlwr(string: temp);
  if ( CoCreateInstance(
         rclsid: &CLSID_ShellLink,
         pUnkOuter: nullptr,
         dwClsContext: 1u,
         riid: &IID_IShellLinkA,
         ppv: (LPVOID *)&linkFileName) >= 0 )
  {
    if ( linkFileName->QueryInterface(this: linkFileName, a2: &IID_IPersistFile, a3: (void **)&ppf) >= 0 )
    {
      MultiByteToWideChar(
        CodePage: 0,
        dwFlags: 1u,
        lpMultiByteStr: temp,
        cbMultiByte: -1,
        lpWideCharStr: wsz,
        cchWideChar: 260);
      if ( ppf->Load(this: ppf, a2: wsz, a3: 0) >= 0 )
      {
        linkFileName->SetPath(this: linkFileName, a2: targetPath);
        linkFileName->SetArguments(this: linkFileName, a2: arguments);
        linkFileName->SetWorkingDirectory(this: linkFileName, a2: workingDirectory);
        v6 = 1;
        ppf->Save(this: ppf, a2: wsz, a3: 1);
      }
      ppf->Release(this: ppf);
    }
    linkFileName->Release(this: linkFileName);
  }
  return v6;
}

//------------------------------------------------------------------------------
// Address: 0x10015190
// Name: public: virtual char const __near * CSystem::GetDesktopFolderPath(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CSystem::GetDesktopFolderPath(CSystem *this)
{
  folderPath[0] = 0;
  if ( this->GetRegistryString(
         this,
         a2: "HKEY_CURRENT_USER\\Software\\Microsoft\\Windows\\CurrentVersion\\Explorer\\Shell Folders\\Desktop",
         a3: folderPath,
         a4: 260)
    && strlen(folderPath) > 6
    || SHGetSpecialFolderPathA(hwnd: nullptr, pszPath: folderPath, csidl: 0, fCreate: false) && strlen(folderPath) > 6 )
  {
    return folderPath;
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10014180
// Name: __CreateCSystemISystem_interface
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CSystem *__cdecl _CreateCSystemISystem_interface()
{
  return &g_System;
}
