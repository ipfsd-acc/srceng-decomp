// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/xbox/vxconsole/progress.cpp
// Functions: 8
// ============================================================

#include "utils\xbox\vxconsole\progress.h"

//------------------------------------------------------------------------------
// Address: 0x00414750
// Name: long Progress_WndProc(struct HWND__ __near *,unsigned int,unsigned int,long)
// Source: json
//------------------------------------------------------------------------------
LRESULT __stdcall Progress_WndProc(HWND__ *hwnd, UINT message, HDC wParam, LONG *lParam)
{
  _DWORD *WindowLongA; // eax
  LONG v6; // eax

  if ( message > 0x111 )
  {
    if ( message == 312 )
    {
      SetBkColor(hdc: wParam, color: g_backgroundColor);
      SetTextColor(hdc: wParam, color: g_textColor);
      return (LRESULT)g_hBackgroundBrush;
    }
    return DefWindowProcA(hWnd: hwnd, Msg: message, (WPARAM)wParam, (LPARAM)lParam);
  }
  if ( message != 273 )
  {
    if ( message == 1 )
    {
      SetWindowLongA(hWnd: hwnd, nIndex: -21, dwNewLong: *lParam);
      return 0;
    }
    if ( message == 2 )
    {
      WindowLongA = (_DWORD *)GetWindowLongA(hWnd: hwnd, nIndex: -21);
      if ( WindowLongA != nullptr )
        *WindowLongA = 0;
      return 0;
    }
    return DefWindowProcA(hWnd: hwnd, Msg: message, (WPARAM)wParam, (LPARAM)lParam);
  }
  if ( (_WORD)wParam != 105 )
    return DefWindowProcA(hWnd: hwnd, Msg: message, (WPARAM)wParam, (LPARAM)lParam);
  v6 = GetWindowLongA(hWnd: hwnd, nIndex: -21);
  if ( v6 != 0 )
    *(_BYTE *)(v6 + 28) = 1;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00414810
// Name: private: void CProgress::Update(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CProgress::Update(CProgress *this)
{
  tagMSG msg; // [esp+4h] [ebp-1Ch] BYREF

  while ( PeekMessageA(lpMsg: &msg, hWnd: nullptr, wMsgFilterMin: 0, wMsgFilterMax: 0, wRemoveMsg: 3u) )
  {
    if ( TranslateAcceleratorA(hWnd: g_hDlgMain, hAccTable: g_hAccel, lpMsg: &msg) == 0 )
    {
      TranslateMessage(lpMsg: &msg);
      DispatchMessageA(lpMsg: &msg);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00414880
// Name: public: bool CProgress::IsCancel(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CProgress::IsCancel(CProgress *this)
{
  return this->m_bCancelPressed;
}

//------------------------------------------------------------------------------
// Address: 0x00414890
// Name: public: void CProgress::SetMeter(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CProgress::SetMeter(CProgress *this, WPARAM currentPos, int range)
{
  HWND__ *m_hWndMeter; // eax
  int m_range; // eax
  int v6; // eax
  char buff[16]; // [esp+4h] [ebp-10h] BYREF

  if ( this->m_hWnd != nullptr && this->m_hWndPercent != nullptr )
  {
    m_hWndMeter = this->m_hWndMeter;
    if ( m_hWndMeter != nullptr )
    {
      if ( range >= 0 )
      {
        SendMessageA(hWnd: m_hWndMeter, Msg: 0x401u, wParam: 0, lParam: (unsigned __int16)range << 16);
        this->m_range = range;
      }
      SendMessageA(hWnd: this->m_hWndMeter, Msg: 0x402u, wParam: currentPos, lParam: 0);
      m_range = this->m_range;
      if ( m_range <= 0 )
      {
        v6 = 0;
      }
      else
      {
        v6 = (int)(float)((float)((float)(int)currentPos * 100.0) / (float)m_range);
        if ( v6 > 100 )
          v6 = 100;
      }
      sprintf(string: buff, format: "%d%%", v6);
      SetWindowTextA(hWnd: this->m_hWndPercent, lpString: buff);
      CProgress::Update(this);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00414950
// Name: public: void CProgress::SetStatus(char const __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CProgress::SetStatus(CProgress *this, const char *line1, const char *line2, const char *line3)
{
  if ( this->m_hWnd != nullptr )
  {
    if ( line1 != nullptr )
      SetWindowTextA(hWnd: this->m_hWndStatus1, lpString: line1);
    if ( line2 != nullptr )
      SetWindowTextA(hWnd: this->m_hWndStatus2, lpString: line2);
    if ( line3 != nullptr )
      SetWindowTextA(hWnd: this->m_hWndStatus3, lpString: line3);
    CProgress::Update(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004149A0
// Name: public: void CProgress::Open(char const __near *,bool,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CProgress::Open(CProgress *this, const char *title, bool canCancel, bool bHasMeter)
{
  HWND__ *Window; // eax
  HWND__ *v6; // eax
  int v7; // ecx
  HWND__ *v8; // eax
  int v9; // ecx
  HWND__ *v10; // eax
  HWND__ *v11; // eax
  HWND__ *v12; // eax
  tagRECT parentRect; // [esp+8h] [ebp-24h] BYREF
  tagRECT clientRect; // [esp+18h] [ebp-14h] BYREF
  int dialogHeight; // [esp+28h] [ebp-4h]
  const char *titlea; // [esp+34h] [ebp+8h]

  dialogHeight = 170;
  if ( !canCancel )
    dialogHeight = 145;
  if ( !bHasMeter )
    dialogHeight -= GetSystemMetrics(nIndex: 20);
  Window = CreateWindowExA(
             dwExStyle: 0x200u,
             lpClassName: "PROGRESSCLASS",
             lpWindowName: title,
             dwStyle: 0x80C00000,
             X: 0,
             Y: 0,
             nWidth: 425,
             nHeight: dialogHeight,
             hWndParent: g_hDlgMain,
             hMenu: nullptr,
             hInstance: g_hInstance,
             lpParam: this);
  this->m_hWnd = Window;
  if ( Window != nullptr )
  {
    GetClientRect(hWnd: Window, lpRect: &clientRect);
    v6 = CreateWindowExA(
           dwExStyle: 0,
           lpClassName: "Static",
           lpWindowName: &defValue,
           dwStyle: 0x5000C000u,
           X: 8,
           Y: 10,
           nWidth: clientRect.right - clientRect.left - 66,
           nHeight: 20,
           hWndParent: this->m_hWnd,
           hMenu: (HMENU)0x64,
           hInstance: g_hInstance,
           lpParam: nullptr);
    v7 = clientRect.right - clientRect.left;
    this->m_hWndStatus1 = v6;
    v8 = CreateWindowExA(
           dwExStyle: 0,
           lpClassName: "Static",
           lpWindowName: &defValue,
           dwStyle: 0x50008000u,
           X: 8,
           Y: 30,
           nWidth: v7 - 66,
           nHeight: 20,
           hWndParent: this->m_hWnd,
           hMenu: (HMENU)0x65,
           hInstance: g_hInstance,
           lpParam: nullptr);
    v9 = clientRect.right - clientRect.left;
    this->m_hWndStatus2 = v8;
    this->m_hWndStatus3 = CreateWindowExA(
                            dwExStyle: 0,
                            lpClassName: "Static",
                            lpWindowName: &defValue,
                            dwStyle: 0x50008000u,
                            X: 8,
                            Y: 50,
                            nWidth: v9 - 66,
                            nHeight: 20,
                            hWndParent: this->m_hWnd,
                            hMenu: (HMENU)0x66,
                            hInstance: g_hInstance,
                            lpParam: nullptr);
    SendMessageA(hWnd: this->m_hWndStatus1, Msg: 0x30u, wParam: (WPARAM)g_hProportionalFont, lParam: 1);
    SendMessageA(hWnd: this->m_hWndStatus2, Msg: 0x30u, wParam: (WPARAM)g_hProportionalFont, lParam: 1);
    SendMessageA(hWnd: this->m_hWndStatus3, Msg: 0x30u, wParam: (WPARAM)g_hProportionalFont, lParam: 1);
    if ( bHasMeter )
    {
      v10 = CreateWindowExA(
              dwExStyle: 0,
              lpClassName: "Static",
              lpWindowName: "0%",
              dwStyle: 0x50000002u,
              X: clientRect.right - clientRect.left - 66,
              Y: 50,
              nWidth: 50,
              nHeight: 20,
              hWndParent: this->m_hWnd,
              hMenu: (HMENU)0x67,
              hInstance: g_hInstance,
              lpParam: nullptr);
      this->m_hWndPercent = v10;
      SendMessageA(hWnd: v10, Msg: 0x30u, wParam: (WPARAM)g_hProportionalFont, lParam: 1);
      titlea = (const char *)GetSystemMetrics(nIndex: 20);
      v11 = CreateWindowExA(
              dwExStyle: 0x200u,
              lpClassName: "msctls_progress32",
              lpWindowName: nullptr,
              dwStyle: 0x50000000u,
              X: (clientRect.left + clientRect.right) / 2 - (clientRect.right - clientRect.left - 16) / 2,
              Y: 70,
              nWidth: clientRect.right - clientRect.left - 16,
              nHeight: (int)titlea,
              hWndParent: this->m_hWnd,
              hMenu: (HMENU)0x68,
              hInstance: g_hInstance,
              lpParam: nullptr);
      this->m_hWndMeter = v11;
      SendMessageA(hWnd: v11, Msg: 0x401u, wParam: 0, lParam: 0);
      SendMessageA(hWnd: this->m_hWndMeter, Msg: 0x402u, wParam: 0, lParam: 0);
    }
    else
    {
      this->m_hWndPercent = nullptr;
      this->m_hWndMeter = nullptr;
    }
    this->m_bCancelPressed = false;
    if ( canCancel )
    {
      v12 = CreateWindowExA(
              dwExStyle: 0,
              lpClassName: "Button",
              lpWindowName: "Cancel",
              dwStyle: 0x50000000u,
              X: (clientRect.left + clientRect.right) / 2 - 40,
              Y: clientRect.bottom - 33,
              nWidth: 80,
              nHeight: 25,
              hWndParent: this->m_hWnd,
              hMenu: (HMENU)0x69,
              hInstance: g_hInstance,
              lpParam: nullptr);
      this->m_hWndCancel = v12;
      SendMessageA(hWnd: v12, Msg: 0x30u, wParam: (WPARAM)g_hProportionalFont, lParam: 1);
    }
    GetWindowRect(hWnd: g_hDlgMain, lpRect: &parentRect);
    MoveWindow(
      hWnd: this->m_hWnd,
      X: (parentRect.right + parentRect.left) / 2 - 212,
      Y: (parentRect.top + parentRect.bottom) / 2 - dialogHeight / 2,
      nWidth: 425,
      nHeight: dialogHeight,
      bRepaint: false);
    ShowWindow(hWnd: this->m_hWnd, nCmdShow: 1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00414C80
// Name: public: CProgress::~CProgress(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CProgress::~CProgress(CProgress *this)
{
  if ( this->m_hWnd != nullptr )
  {
    DestroyWindow(hWnd: this->m_hWnd);
    this->m_hWnd = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00414CA0
// Name: public: CProgress::CProgress(void)
// Source: json
//------------------------------------------------------------------------------
CProgress *__thiscall CProgress::CProgress(CProgress *this)
{
  tagWNDCLASSA wndclass; // [esp+8h] [ebp-28h] BYREF

  wndclass.style = 0;
  wndclass.lpfnWndProc = (int (__stdcall *)(HWND__ *, unsigned int, unsigned int, int))Progress_WndProc;
  wndclass.cbClsExtra = 0;
  wndclass.cbWndExtra = 4;
  wndclass.hInstance = g_hInstance;
  wndclass.hIcon = (HICON__ *)g_hIcons;
  wndclass.hCursor = LoadCursorA(hInstance: nullptr, lpCursorName: (LPCSTR)0x7F00);
  wndclass.hbrBackground = (HBRUSH__ *)g_hBackgroundBrush;
  wndclass.lpszMenuName = nullptr;
  wndclass.lpszClassName = "PROGRESSCLASS";
  RegisterClassA(lpWndClass: &wndclass);
  this->m_hWnd = nullptr;
  this->m_bCancelPressed = false;
  return this;
}
