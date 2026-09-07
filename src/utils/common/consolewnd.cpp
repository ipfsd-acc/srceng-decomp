// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/common/consolewnd.cpp
// Functions: 13
// ============================================================

#include "utils\common\consolewnd.h"

//------------------------------------------------------------------------------
// Address: 0x00401000
// Name: public: virtual void CConsoleWnd::SetVisible(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CConsoleWnd::SetVisible(CConsoleWnd *this, bool bVisible)
{
  LRESULT v3; // eax

  ShowWindow(hWnd: this->m_hWnd, nCmdShow: bVisible ? 9 : 0);
  if ( bVisible )
  {
    ShowWindow(hWnd: this->m_hWnd, nCmdShow: 5);
    SetWindowPos(hWnd: this->m_hWnd, hWndInsertAfter: HWND_MESSAGE|0x2, X: 0, Y: 0, cx: 0, cy: 0, uFlags: 3u);
    UpdateWindow(hWnd: this->m_hWnd);
    v3 = SendMessageA(hWnd: this->m_hEditControl, Msg: 0xD5u, wParam: 0, lParam: 0);
    SendMessageA(hWnd: this->m_hEditControl, Msg: 0xB1u, wParam: v3, lParam: v3);
    this->m_bVisible = bVisible;
  }
  else
  {
    SetWindowPos(hWnd: this->m_hWnd, hWndInsertAfter: nullptr, X: 0, Y: 0, cx: 0, cy: 0, uFlags: 0x283u);
    this->m_bVisible = false;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004010A0
// Name: public: virtual bool CConsoleWnd::IsVisible(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CConsoleWnd::IsVisible(CConsoleWnd *this)
{
  return this->m_bVisible;
}

//------------------------------------------------------------------------------
// Address: 0x004010B0
// Name: public: virtual void CConsoleWnd::SetTitle(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CConsoleWnd::SetTitle(CConsoleWnd *this, const char *pTitle)
{
  SetWindowTextA(hWnd: this->m_hWnd, lpString: pTitle);
}

//------------------------------------------------------------------------------
// Address: 0x004010D0
// Name: private: void CConsoleWnd::RepositionEditControl(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CConsoleWnd::RepositionEditControl(CConsoleWnd *this)
{
  tagRECT rcMain; // [esp+8h] [ebp-10h] BYREF

  GetClientRect(hWnd: this->m_hWnd, lpRect: &rcMain);
  SetWindowPos(
    hWnd: this->m_hEditControl,
    hWndInsertAfter: nullptr,
    X: rcMain.left + 5,
    Y: rcMain.top + 5,
    cx: rcMain.right - 5 - (rcMain.left + 5),
    cy: rcMain.bottom - 5 - (rcMain.top + 5),
    uFlags: 4u);
}

//------------------------------------------------------------------------------
// Address: 0x00401120
// Name: public: virtual void CConsoleWnd::SetDeleteOnClose(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CConsoleWnd::SetDeleteOnClose(CConsoleWnd *this, bool bDelete)
{
  this->m_bDeleteOnClose = bDelete;
}

//------------------------------------------------------------------------------
// Address: 0x00401130
// Name: void ClearEditControl(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ClearEditControl(HWND hWnd)
{
  LPARAM v1; // eax

  v1 = SendMessageA(hWnd, Msg: 0xD5u, wParam: 0, lParam: 0);
  SendMessageA(hWnd, Msg: 0xB1u, wParam: 0, lParam: v1);
  SendMessageA(hWnd, Msg: 0xC2u, wParam: 0, lParam: (LPARAM)str);
}

//------------------------------------------------------------------------------
// Address: 0x00401170
// Name: void FormatAndSendToEditControl(void __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl FormatAndSendToEditControl(HWND hWnd, const char *pText)
{
  const char *v2; // ebx
  char *v3; // eax
  char v4; // cl
  LRESULT v5; // eax
  LRESULT v6; // eax
  char outMsg[1024]; // [esp+Ch] [ebp-400h] BYREF

  v2 = pText;
  v3 = outMsg;
  while ( *v2 != 0 )
  {
    v4 = *v2;
    if ( *v2 == 10 )
      *v3++ = 13;
    *v3++ = v4;
    ++v2;
    if ( v3 - outMsg >= 1020 )
    {
      *v3 = 0;
      v5 = SendMessageA(hWnd, Msg: 0xD5u, wParam: 0, lParam: 0);
      SendMessageA(hWnd, Msg: 0xB1u, wParam: v5, lParam: v5);
      SendMessageA(hWnd, Msg: 0xC2u, wParam: 0, lParam: (LPARAM)outMsg);
      v3 = outMsg;
    }
  }
  *v3 = 0;
  v6 = SendMessageA(hWnd, Msg: 0xD5u, wParam: 0, lParam: 0);
  SendMessageA(hWnd, Msg: 0xB1u, wParam: v6, lParam: v6);
  SendMessageA(hWnd, Msg: 0xC2u, wParam: 0, lParam: (LPARAM)outMsg);
}

//------------------------------------------------------------------------------
// Address: 0x00401220
// Name: public: virtual void CConsoleWnd::PrintToConsole(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CConsoleWnd::PrintToConsole(CConsoleWnd *this, const char *pMsg)
{
  HWND__ *m_hEditControl; // edi
  LPARAM v4; // eax

  if ( this->m_nCurrentChars >= 0x4000 )
  {
    m_hEditControl = this->m_hEditControl;
    this->m_nCurrentChars = 0;
    v4 = SendMessageA(hWnd: m_hEditControl, Msg: 0xD5u, wParam: 0, lParam: 0);
    SendMessageA(hWnd: m_hEditControl, Msg: 0xB1u, wParam: 0, lParam: v4);
    SendMessageA(hWnd: m_hEditControl, Msg: 0xC2u, wParam: 0, lParam: (LPARAM)str);
  }
  FormatAndSendToEditControl(hWnd: this->m_hEditControl, pText: pMsg);
  this->m_nCurrentChars += strlen(pMsg);
}

//------------------------------------------------------------------------------
// Address: 0x004012A0
// Name: private: int CConsoleWnd::WindowProc(struct HWND__ __near *,unsigned int,unsigned int,long)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CConsoleWnd::WindowProc(
        CConsoleWnd *this,
        HWND__ *hwndDlg,
        unsigned int uMsg,
        unsigned int wParam,
        int lParam)
{
  CConsoleWnd_vtbl *v6; // eax

  if ( hwndDlg != this->m_hWnd )
    return 0;
  if ( uMsg > 0x110 )
  {
    if ( uMsg != 274 || wParam != 61536 )
      return 0;
    v6 = this->__vftable;
    if ( this->m_bDeleteOnClose )
    {
      ((void (*)(void))v6->Release)();
      return 0;
    }
    else
    {
      ((void (__stdcall *)(_DWORD))v6->SetVisible)(a1: 0);
      return 1;
    }
  }
  else
  {
    if ( uMsg != 272 && uMsg != 5 )
    {
      if ( uMsg == 24 )
        this->m_bVisible = wParam != 0;
      return 0;
    }
    CConsoleWnd::RepositionEditControl(this);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00401310
// Name: private: static int CConsoleWnd::StaticWindowProc(struct HWND__ __near *,unsigned int,unsigned int,long)
// Source: json
//------------------------------------------------------------------------------
int __stdcall CConsoleWnd::StaticWindowProc(HWND__ *hwndDlg, unsigned int uMsg, unsigned int wParam, int lParam)
{
  CConsoleWnd *WindowLongA; // eax

  WindowLongA = (CConsoleWnd *)GetWindowLongA(hWnd: hwndDlg, nIndex: -21);
  if ( WindowLongA != nullptr )
    return CConsoleWnd::WindowProc(this: WindowLongA, hwndDlg, uMsg, wParam, lParam);
  else
    return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00401350
// Name: public: bool CConsoleWnd::Init(void __near *,int,int,bool)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CConsoleWnd::Init(
        CConsoleWnd *this,
        HINSTANCE hInstance,
        unsigned __int16 dialogResourceID,
        int editControlID,
        bool bVisible)
{
  HWND__ *DialogParamA; // eax
  HWND__ *DlgItem; // eax

  DialogParamA = CreateDialogParamA(
                   hInstance,
                   lpTemplateName: (LPCSTR)dialogResourceID,
                   hWndParent: nullptr,
                   lpDialogFunc: CConsoleWnd::StaticWindowProc,
                   dwInitParam: 0);
  this->m_hWnd = DialogParamA;
  if ( DialogParamA == nullptr )
    return 0;
  SetWindowLongA(hWnd: DialogParamA, nIndex: -21, dwNewLong: (LONG)this);
  if ( bVisible )
    ShowWindow(hWnd: this->m_hWnd, nCmdShow: 5);
  DlgItem = GetDlgItem(hDlg: this->m_hWnd, nIDDlgItem: editControlID);
  this->m_hEditControl = DlgItem;
  if ( DlgItem == nullptr )
    return 0;
  CConsoleWnd::RepositionEditControl(this);
  this->m_bVisible = bVisible;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004013D0
// Name: public: virtual void CConsoleWnd::Release(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CConsoleWnd::Release(CConsoleWnd *this)
{
  HWND__ *m_hWnd; // eax

  if ( this != nullptr )
  {
    m_hWnd = this->m_hWnd;
    this->__vftable = (CConsoleWnd_vtbl *)&CConsoleWnd::`vftable';
    if ( m_hWnd != nullptr )
    {
      DestroyWindow(hWnd: m_hWnd);
      this->m_hWnd = nullptr;
    }
    free(pMem: this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00401400
// Name: class IConsoleWnd __near * CreateConsoleWnd(void __near *,int,int,bool)
// Source: json
//------------------------------------------------------------------------------
CConsoleWnd *__cdecl CreateConsoleWnd(
        HINSTANCE hInstance,
        unsigned __int16 dialogResourceID,
        int editControlID,
        bool bVisible)
{
  CConsoleWnd *v4; // eax
  CConsoleWnd *v5; // esi

  v4 = (CConsoleWnd *)operator new(nSize: 0x14u);
  if ( v4 != nullptr )
  {
    v4->__vftable = (CConsoleWnd_vtbl *)&CConsoleWnd::`vftable';
    v4->m_hEditControl = nullptr;
    v4->m_hWnd = nullptr;
    *(_WORD *)&v4->m_bVisible = 0;
    v4->m_nCurrentChars = 0;
    v5 = v4;
  }
  else
  {
    v5 = nullptr;
  }
  if ( CConsoleWnd::Init(this: v5, hInstance, dialogResourceID, editControlID, bVisible) != 0 )
    return v5;
  v5->Release(this: v5);
  return nullptr;
}
