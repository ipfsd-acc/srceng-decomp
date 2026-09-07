// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/hlmv/sys_win.cpp
// Functions: 1
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x00428820
// Name: void Sys_CopyStringToClipboard(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Sys_CopyStringToClipboard(const char *pOut)
{
  int v1; // esi
  HGLOBAL v2; // edi
  char *v3; // eax

  if ( pOut != nullptr && OpenClipboard(hWndNewOwner: nullptr) && EmptyClipboard() )
  {
    EmptyClipboard();
    v1 = _V_strlen(str: pOut) + 1;
    v2 = GlobalAlloc(uFlags: 0x2000u, dwBytes: v1);
    v3 = (char *)GlobalLock(hMem: v2);
    V_strncpy(pDest: v3, pSrc: pOut, maxLen: v1);
    GlobalUnlock(hMem: v2);
    SetClipboardData(uFormat: 1u, hMem: v2);
    CloseClipboard();
  }
}
