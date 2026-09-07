// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/vmpi/vmpi_service_ui/simplestringdlg.cpp
// Functions: 6
// ============================================================

#include "utils\vmpi\vmpi_service_ui\simplestringdlg.h"

//------------------------------------------------------------------------------
// Address: 0x00402230
// Name: protected: int CSimpleStringDlg::DlgProc(struct HWND__ __near *,unsigned int,unsigned int,long)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSimpleStringDlg::DlgProc(
        CSimpleStringDlg *this,
        HWND__ *hwndDlg,
        unsigned int uMsg,
        unsigned int wParam,
        int lParam)
{
  const char *v7; // eax
  HWND DlgItem; // eax
  const char *v9; // [esp-Ch] [ebp-10h]

  if ( uMsg == 272 )
  {
    this->m_hWnd = hwndDlg;
    SetWindowLongA(hWnd: hwndDlg, nIndex: -21, dwNewLong: (LONG)this);
    v7 = CUtlString::Get(this: &this->m_sTitle);
    SetWindowTextA(hWnd: this->m_hWnd, lpString: v7);
    v9 = CUtlString::Get(this: &this->m_sValue);
    DlgItem = GetDlgItem(hDlg: hwndDlg, nIDDlgItem: 1001);
    SetWindowTextA(hWnd: DlgItem, lpString: v9);
  }
  else if ( uMsg == 273 )
  {
    if ( wParam == 1 )
    {
      this->OnOk(this);
      return 0;
    }
    if ( wParam == 2 )
    {
      this->OnCancel(this);
      return 0;
    }
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x004022B0
// Name: public: virtual void CSimpleStringDlg::OnOk(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSimpleStringDlg::OnOk(CSimpleStringDlg *this)
{
  HWND DlgItem; // eax
  char text[256]; // [esp+4h] [ebp-100h] BYREF

  memset(text, 0, sizeof(text));
  DlgItem = GetDlgItem(hDlg: this->m_hWnd, nIDDlgItem: 1001);
  GetWindowTextA(hWnd: DlgItem, lpString: text, nMaxCount: 256);
  CUtlString::operator=(this: &this->m_sValue, src: text);
  EndDialog(hDlg: this->m_hWnd, nResult: 1);
}

//------------------------------------------------------------------------------
// Address: 0x00402320
// Name: public: virtual void CSimpleStringDlg::OnCancel(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSimpleStringDlg::OnCancel(CSimpleStringDlg *this)
{
  EndDialog(hDlg: this->m_hWnd, nResult: 2);
}

//------------------------------------------------------------------------------
// Address: 0x00402330
// Name: protected: static int CSimpleStringDlg::StaticSimpleStringDlgProc(struct HWND__ __near *,unsigned int,unsigned int,long)
// Source: json
//------------------------------------------------------------------------------
int __stdcall CSimpleStringDlg::StaticSimpleStringDlgProc(
        HWND__ *hwndDlg,
        unsigned int uMsg,
        unsigned int wParam,
        CSimpleStringDlg *lParam)
{
  CSimpleStringDlg *WindowLongA; // eax

  if ( uMsg == 272 )
    return CSimpleStringDlg::DlgProc(this: lParam, hwndDlg, uMsg: 0x110u, wParam, (int)lParam);
  WindowLongA = (CSimpleStringDlg *)GetWindowLongA(hWnd: hwndDlg, nIndex: -21);
  if ( WindowLongA != nullptr )
    return CSimpleStringDlg::DlgProc(this: WindowLongA, hwndDlg, uMsg, wParam, (int)lParam);
  else
    return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00402390
// Name: public: int CSimpleStringDlg::Show(struct HWND__ __near *,class CUtlString,class CUtlString)
// Source: json
//------------------------------------------------------------------------------
INT_PTR __thiscall CSimpleStringDlg::Show(
        CSimpleStringDlg *this,
        HWND__ *hParent,
        CUtlString sTitle,
        CUtlString sInitialValue)
{
  INT_PTR v5; // edi

  CUtlString::operator=(this: &this->m_sTitle, src: &sTitle);
  CUtlString::operator=(this: &this->m_sValue, src: &sInitialValue);
  v5 = DialogBoxParamA(
         hInstance: g_hInstance,
         lpTemplateName: (LPCSTR)0x82,
         hWndParent: hParent,
         lpDialogFunc: (DLGPROC)CSimpleStringDlg::StaticSimpleStringDlgProc,
         dwInitParam: (LPARAM)this);
  sTitle.m_Storage.m_nActualLength = 0;
  if ( sTitle.m_Storage.m_Memory.m_nGrowSize >= 0 )
  {
    if ( sTitle.m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: sTitle.m_Storage.m_Memory.m_pMemory);
      sTitle.m_Storage.m_Memory.m_pMemory = nullptr;
    }
    sTitle.m_Storage.m_Memory.m_nAllocationCount = 0;
  }
  sInitialValue.m_Storage.m_nActualLength = 0;
  if ( sInitialValue.m_Storage.m_Memory.m_nGrowSize >= 0 && sInitialValue.m_Storage.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: sInitialValue.m_Storage.m_Memory.m_pMemory);
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x00402420
// Name: public: CSimpleStringDlg::CSimpleStringDlg(void)
// Source: json
//------------------------------------------------------------------------------
CSimpleStringDlg *__thiscall CSimpleStringDlg::CSimpleStringDlg(CSimpleStringDlg *this)
{
  this->__vftable = (CSimpleStringDlg_vtbl *)&CSimpleStringDlg::`vftable';
  CUtlString::CUtlString(this: &this->m_sTitle);
  CUtlString::CUtlString(this: &this->m_sValue);
  this->m_hWnd = nullptr;
  return this;
}
