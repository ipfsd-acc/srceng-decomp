// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/vmpi/vmpi_service_ui/shell_icon_mgr.cpp
// Functions: 7
// ============================================================

#include "utils\vmpi\vmpi_service_ui\shell_icon_mgr.h"

//------------------------------------------------------------------------------
// Address: 0x00401EC0
// Name: public: CShellIconMgr::CShellIconMgr(void)
// Source: json
//------------------------------------------------------------------------------
CShellIconMgr *__thiscall CShellIconMgr::CShellIconMgr(CShellIconMgr *this)
{
  this->m_hWnd = nullptr;
  this->m_hWndClass = 0;
  this->m_uTaskbarRestart = -1;
  this->m_iCurIconResourceID = 0;
  this->m_pHelper = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00401EE0
// Name: public: void CShellIconMgr::Term(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShellIconMgr::Term(CShellIconMgr *this)
{
  HINSTANCE v2; // eax
  HWND__ *m_hWnd; // edi
  _NOTIFYICONDATAA data; // [esp+8h] [ebp-1FCh] BYREF

  if ( this->m_hWndClass != 0 )
  {
    v2 = this->m_pHelper->GetHInstance(this: this->m_pHelper);
    UnregisterClassA(lpClassName: "VMPI_ShellIconMgr", hInstance: v2);
    this->m_hWndClass = 0;
  }
  m_hWnd = this->m_hWnd;
  if ( this->m_hWnd != nullptr )
  {
    memset(dst: (unsigned __int8 *)&data, value: 0, count: sizeof(data));
    data.cbSize = 508;
    data.hWnd = m_hWnd;
    Shell_NotifyIconA(dwMessage: 2u, lpData: &data);
    DestroyWindow(hWnd: this->m_hWnd);
    this->m_hWnd = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00401F60
// Name: public: void CShellIconMgr::ChangeIcon(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShellIconMgr::ChangeIcon(CShellIconMgr *this, int iIconResourceID)
{
  IShellIconMgrHelper *m_pHelper; // ecx
  HINSTANCE v4; // eax
  _NOTIFYICONDATAA data; // [esp+8h] [ebp-1FCh] BYREF

  memset(dst: (unsigned __int8 *)&data, value: 0, count: sizeof(data));
  data.hWnd = this->m_hWnd;
  m_pHelper = this->m_pHelper;
  data.cbSize = 508;
  data.uFlags = 2;
  v4 = (HINSTANCE)m_pHelper->GetHInstance(this: m_pHelper);
  data.hIcon = LoadIconA(hInstance: v4, lpIconName: (LPCSTR)(unsigned __int16)iIconResourceID);
  Shell_NotifyIconA(dwMessage: 1u, lpData: &data);
  this->m_iCurIconResourceID = iIconResourceID;
}

//------------------------------------------------------------------------------
// Address: 0x00401FE0
// Name: private: void CShellIconMgr::CreateTrayIcon(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShellIconMgr::CreateTrayIcon(CShellIconMgr *this)
{
  HWND__ *m_hWnd; // edx
  const char *m_iCurIconResourceID_low; // eax
  IShellIconMgrHelper *m_pHelper; // ecx
  HINSTANCE v5; // eax
  HICON__ *IconA; // eax
  const char *m_pToolTip; // [esp-8h] [ebp-208h]
  const char *v8; // [esp-4h] [ebp-204h]
  _NOTIFYICONDATAA data; // [esp+4h] [ebp-1FCh] BYREF

  memset(dst: (unsigned __int8 *)&data, value: 0, count: sizeof(data));
  m_hWnd = this->m_hWnd;
  m_iCurIconResourceID_low = (const char *)LOWORD(this->m_iCurIconResourceID);
  data.uCallbackMessage = this->m_iCallbackMessage;
  m_pHelper = this->m_pHelper;
  data.cbSize = 508;
  data.uFlags = 7;
  data.hWnd = m_hWnd;
  v8 = m_iCurIconResourceID_low;
  v5 = (HINSTANCE)m_pHelper->GetHInstance(this: m_pHelper);
  IconA = LoadIconA(hInstance: v5, lpIconName: v8);
  m_pToolTip = this->m_pToolTip;
  data.hIcon = IconA;
  V_strncpy(pDest: data.szTip, pSrc: m_pToolTip, maxLen: 128);
  Shell_NotifyIconA(dwMessage: 0, lpData: &data);
}

//------------------------------------------------------------------------------
// Address: 0x00402070
// Name: private: static long CShellIconMgr::StaticWindowProc(struct HWND__ __near *,unsigned int,unsigned int,long)
// Source: json
//------------------------------------------------------------------------------
LRESULT __stdcall CShellIconMgr::StaticWindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
  CShellIconMgr *WindowLongA; // eax

  WindowLongA = (CShellIconMgr *)GetWindowLongA(hWnd: hwnd, nIndex: -21);
  if ( WindowLongA == nullptr || hwnd != WindowLongA->m_hWnd )
    return DefWindowProcA(hWnd: hwnd, Msg: uMsg, wParam, lParam);
  if ( uMsg != WindowLongA->m_uTaskbarRestart )
    return WindowLongA->m_pHelper->WindowProc(this: WindowLongA->m_pHelper, a2: hwnd, a3: uMsg, a4: wParam, a5: lParam);
  CShellIconMgr::CreateTrayIcon(this: WindowLongA);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x004020F0
// Name: public: CShellIconMgr::~CShellIconMgr(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall CShellIconMgr::~CShellIconMgr(CShellIconMgr *this)
{
  CShellIconMgr::Term(this);
}

//------------------------------------------------------------------------------
// Address: 0x00402100
// Name: public: bool CShellIconMgr::Init(class IShellIconMgrHelper __near *,char const __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CShellIconMgr::Init(
        CShellIconMgr *this,
        IShellIconMgrHelper *pHelper,
        const char *pToolTip,
        int iCallbackMessage,
        int iIconResourceID)
{
  HINSTANCE__ *(__thiscall *GetHInstance)(IShellIconMgrHelper *); // eax
  ATOM v7; // ax
  HINSTANCE v9; // eax
  HWND__ *Window; // eax
  UINT v11; // eax
  HWND__ *m_hWnd; // [esp-Ch] [ebp-3Ch]
  tagWNDCLASSA wndclass; // [esp+8h] [ebp-28h] BYREF

  CShellIconMgr::Term(this);
  this->m_iCallbackMessage = iCallbackMessage;
  this->m_pToolTip = pToolTip;
  this->m_pHelper = pHelper;
  GetHInstance = pHelper->GetHInstance;
  wndclass.style = 0;
  *(_QWORD *)&wndclass.cbClsExtra = 0;
  wndclass.lpfnWndProc = CShellIconMgr::StaticWindowProc;
  wndclass.hInstance = GetHInstance(this: pHelper);
  wndclass.hIcon = nullptr;
  wndclass.hCursor = LoadCursorA(hInstance: nullptr, lpCursorName: (LPCSTR)0x7F00);
  wndclass.hbrBackground = (HBRUSH__ *)GetStockObject(i: 4);
  wndclass.lpszMenuName = nullptr;
  wndclass.lpszClassName = "VMPI_ShellIconMgr";
  v7 = RegisterClassA(lpWndClass: &wndclass);
  this->m_hWndClass = v7;
  if ( v7 == 0 )
  {
    _Warning(a1: "RegisterClass failed.\n");
LABEL_3:
    CShellIconMgr::Term(this);
    return 0;
  }
  v9 = (HINSTANCE)pHelper->GetHInstance(this: pHelper);
  Window = CreateWindowExA(
             dwExStyle: 0,
             lpClassName: "VMPI_ShellIconMgr",
             lpWindowName: "VMPI_ShellIconMgr",
             dwStyle: 0x8000000u,
             X: 0,
             Y: 0,
             nWidth: 0,
             nHeight: 0,
             hWndParent: nullptr,
             hMenu: nullptr,
             hInstance: v9,
             lpParam: this);
  this->m_hWnd = Window;
  if ( Window == nullptr )
  {
    _Warning(a1: "CreateWindow failed.\n");
    goto LABEL_3;
  }
  v11 = RegisterWindowMessageA(lpString: "TaskbarCreated");
  m_hWnd = this->m_hWnd;
  this->m_uTaskbarRestart = v11;
  SetWindowLongA(hWnd: m_hWnd, nIndex: -21, dwNewLong: (LONG)this);
  UpdateWindow(hWnd: this->m_hWnd);
  this->m_iCurIconResourceID = iIconResourceID;
  CShellIconMgr::CreateTrayIcon(this);
  return 1;
}
