// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/xbox/vxconsole/assert_dialog.cpp
// Functions: 2
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x00401000
// Name: int AssertDialogProc(struct HWND__ __near *,unsigned int,unsigned int,long)
// Source: json
//------------------------------------------------------------------------------
int __stdcall AssertDialogProc(HWND__ *hDlg, unsigned int uMsg, unsigned int wParam, int lParam)
{
  int result; // eax
  HWND DesktopWindow; // eax
  HWND v6; // [esp-8h] [ebp-28h]
  tagRECT rcDesktop; // [esp+0h] [ebp-20h] BYREF
  tagRECT rcDlg; // [esp+10h] [ebp-10h] BYREF

  switch ( uMsg )
  {
    case 0x100u:
LABEL_12:
      if ( wParam == 2 )
      {
        v6 = hDlg;
LABEL_14:
        g_AssertAction = ASSERT_ACTION_IGNORE_THIS;
        EndDialog(hDlg: v6, nResult: 0);
      }
      return 1;
    case 0x110u:
      SetWindowTextA(hWnd: hDlg, lpString: "Xbox 360 Assert!");
      SetDlgItemTextA(hDlg, nIDDlgItem: 1000, lpString: g_AssertInfo);
      GetWindowRect(hWnd: hDlg, lpRect: &rcDlg);
      DesktopWindow = GetDesktopWindow();
      GetWindowRect(hWnd: DesktopWindow, lpRect: &rcDesktop);
      SetWindowPos(
        hWnd: hDlg,
        hWndInsertAfter: nullptr,
        X: (rcDesktop.right + rcDlg.left - rcDlg.right - rcDesktop.left) / 2,
        Y: (rcDesktop.bottom + rcDlg.top - rcDlg.bottom - rcDesktop.top) / 2,
        cx: 0,
        cy: 0,
        uFlags: 1u);
      return 1;
    case 0x111u:
      switch ( (__int16)wParam )
      {
        case 1002:
          g_AssertAction = ASSERT_ACTION_IGNORE_FILE;
          EndDialog(hDlg, nResult: 0);
          result = 1;
          break;
        case 1005:
          v6 = hDlg;
          goto LABEL_14;
        case 1006:
          g_AssertAction = ASSERT_ACTION_BREAK;
          EndDialog(hDlg, nResult: 0);
          result = 1;
          break;
        case 1008:
          g_AssertAction = ASSERT_ACTION_IGNORE_ALL;
          EndDialog(hDlg, nResult: 0);
          result = 1;
          break;
        case 1009:
          g_AssertAction = ASSERT_ACTION_IGNORE_ALWAYS;
          EndDialog(hDlg, nResult: 0);
          result = 1;
          break;
        default:
          goto LABEL_12;
      }
      break;
    default:
      return 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004011A0
// Name: int rc_Assert(char __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl rc_Assert(char *commandPtr)
{
  char *Token; // eax
  char *i; // eax
  unsigned __int8 *v3; // eax
  FLASHWINFO flashWInfo; // [esp+4h] [ebp-1Ch] BYREF
  int retAddr; // [esp+18h] [ebp-8h] BYREF
  int xboxRetVal; // [esp+1Ch] [ebp-4h] BYREF

  flashWInfo.cbSize = 20;
  flashWInfo.hwnd = g_hDlgMain;
  flashWInfo.dwFlags = 15;
  flashWInfo.uCount = 0;
  flashWInfo.dwTimeout = 1000;
  FlashWindowEx(pfwi: &flashWInfo);
  Token = GetToken(ppTokenStream: &commandPtr);
  if ( *Token == 0 || sscanf(string: Token, format: "%x", &retAddr) != 1 )
    return -1;
  for ( i = commandPtr; *i == 32; commandPtr = i )
    ++i;
  g_AssertInfo = i;
  strchr(string: (unsigned __int8 *)i, chr: 9u);
  while ( v3 != nullptr )
  {
    *v3 = 10;
    strchr(string: v3, chr: 9u);
  }
  g_AssertAction = ASSERT_ACTION_BREAK;
  g_AssertDialogActive = true;
  DialogBoxParamA(
    hInstance: g_hInstance,
    lpTemplateName: (LPCSTR)0x65,
    hWndParent: g_hDlgMain,
    lpDialogFunc: AssertDialogProc,
    dwInitParam: 0);
  g_AssertDialogActive = false;
  xboxRetVal = _byteswap_ulong(g_AssertAction);
  DmSetMemory(a1: retAddr, a2: 4, a3: &xboxRetVal, a4: 0);
  return 0;
}
