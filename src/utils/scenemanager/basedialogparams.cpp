// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/scenemanager/basedialogparams.cpp
// Functions: 1
// ============================================================

#include "utils\scenemanager\basedialogparams.h"

//------------------------------------------------------------------------------
// Address: 0x00404F00
// Name: public: void CBaseDialogParams::PositionSelf(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseDialogParams::PositionSelf(CBaseDialogParams *this, HWND self)
{
  int SystemMetrics; // eax
  int v4; // ecx
  int v5; // [esp-Ch] [ebp-38h]
  int v6; // [esp-8h] [ebp-34h]
  int rcParent_8; // [esp+14h] [ebp-18h]
  tagRECT rcDlg; // [esp+1Ch] [ebp-10h] BYREF

  GetWindowRect(hWnd: self, lpRect: &rcDlg);
  rcParent_8 = GetSystemMetrics(nIndex: 16);
  SystemMetrics = GetSystemMetrics(nIndex: 17);
  v4 = rcDlg.bottom - rcDlg.top;
  v6 = rcDlg.bottom - rcDlg.top;
  v5 = rcDlg.right - rcDlg.left;
  if ( this->m_bPositionDialog )
    MoveWindow(hWnd: self, X: this->m_nLeft, Y: this->m_nTop - v4 - 5, nWidth: v5, nHeight: v6, bRepaint: true);
  else
    MoveWindow(
      hWnd: self,
      X: (rcParent_8 - (rcDlg.right - rcDlg.left)) / 2,
      Y: (SystemMetrics - v4) / 2,
      nWidth: v5,
      nHeight: v6,
      bRepaint: true);
}
