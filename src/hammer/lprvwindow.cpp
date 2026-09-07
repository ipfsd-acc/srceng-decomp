// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: hammer/lprvwindow.cpp
// Functions: 8
// ============================================================

#include "hammer\lprvwindow.h"

//------------------------------------------------------------------------------
// Address: 0x10053090
// Name: public: CLightingPreviewResultsWindow::CLightingPreviewResultsWindow(void)
// Source: json
//------------------------------------------------------------------------------
CLightingPreviewResultsWindow *__thiscall CLightingPreviewResultsWindow::CLightingPreviewResultsWindow(
        CLightingPreviewResultsWindow *this)
{
  CWnd::CWnd(this);
  this->__vftable = (CLightingPreviewResultsWindow_vtbl *)&CLightingPreviewResultsWindow::`vftable';
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10053140
// Name: protected: void CLightingPreviewResultsWindow::OnClose(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLightingPreviewResultsWindow::OnClose(CLightingPreviewResultsWindow *this)
{
  CMainFrame *MainWnd; // eax

  MainWnd = GetMainWnd();
  CMainFrame::GlobalNotify(this: MainWnd, nCode: 1032);
  CWnd::Default(this);
}

//------------------------------------------------------------------------------
// Address: 0x10053160
// Name: protected: void CLightingPreviewResultsWindow::OnPaint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLightingPreviewResultsWindow::OnPaint(CLightingPreviewResultsWindow *this)
{
  HWND__ *m_hWnd; // [esp-8h] [ebp-A8h]
  CPaintDC dc; // [esp+8h] [ebp-98h] BYREF
  tagBITMAPINFOHEADER mybmh; // [esp+5Ch] [ebp-44h] BYREF
  CRect clientrect; // [esp+84h] [ebp-1Ch] BYREF
  int v6; // [esp+9Ch] [ebp-4h]

  CPaintDC::CPaintDC(this: &dc, pWnd: this);
  v6 = 0;
  m_hWnd = this->m_hWnd;
  memset(&clientrect, 0, sizeof(clientrect));
  GetClientRect(hWnd: m_hWnd, lpRect: &clientrect);
  if ( g_pLPreviewOutputBitmap != nullptr )
  {
    mybmh.biHeight = -g_pLPreviewOutputBitmap->m_nHeight;
    mybmh.biSize = 40;
    mybmh.biWidth = g_pLPreviewOutputBitmap->m_nWidth;
    *(_DWORD *)&mybmh.biPlanes = 2097153;
    mybmh.biCompression = 0;
    mybmh.biSizeImage = g_pLPreviewOutputBitmap->m_nWidth * g_pLPreviewOutputBitmap->m_nHeight;
    StretchDIBits(
      hdc: dc.m_hDC,
      xDest: clientrect.left,
      yDest: clientrect.top,
      DestWidth: clientrect.right - clientrect.left + 1,
      DestHeight: clientrect.bottom - clientrect.top + 1,
      xSrc: 0,
      ySrc: 0,
      SrcWidth: g_pLPreviewOutputBitmap->m_nWidth,
      SrcHeight: g_pLPreviewOutputBitmap->m_nHeight,
      lpBits: g_pLPreviewOutputBitmap->m_pBits,
      lpbmi: (const BITMAPINFO *)&mybmh,
      iUsage: 0,
      rop: 0xCC0020u);
  }
  v6 = -1;
  CPaintDC::~CPaintDC(this: &dc);
}

//------------------------------------------------------------------------------
// Address: 0x10053240
// Name: protected: virtual struct AFX_MSGMAP const __near * CLightingPreviewResultsWindow::GetMessageMap(void)const
// Source: json
//------------------------------------------------------------------------------
const AFX_MSGMAP *__thiscall CLightingPreviewResultsWindow::GetMessageMap(CLightingPreviewResultsWindow *this)
{
  return (const AFX_MSGMAP *)&off_105DC974;
}

//------------------------------------------------------------------------------
// Address: 0x10053250
// Name: public: void CLightingPreviewResultsWindow::Create(class CWnd __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLightingPreviewResultsWindow::Create(CLightingPreviewResultsWindow *this, CWnd *pParentWnd)
{
  CAfxStringMgr *StringManager; // eax
  HCURSOR CursorA; // eax
  const char *v5; // eax
  int v6; // ecx
  HBRUSH__ *StockObject; // [esp-8h] [ebp-28h]
  tagRECT rect; // [esp+4h] [ebp-1Ch] BYREF
  int v9; // [esp+1Ch] [ebp-4h]

  if ( (_S1_1 & 1) == 0 )
  {
    _S1_1 |= 1u;
    v9 = 0;
    StringManager = AfxGetStringManager();
    if ( StringManager == nullptr )
      ATL::AtlThrowImpl(hr: -2147467259);
    LPreviewWndClassName.m_pszData = (char *)&StringManager->GetNilString(this: StringManager)[1];
    atexit(func: CLightingPreviewResultsWindow::Create_::_2_::_dynamic_atexit_destructor_for__LPreviewWndClassName__);
    v9 = -1;
  }
  if ( *((_DWORD *)LPreviewWndClassName.m_pszData - 3) == 0 )
  {
    StockObject = (HBRUSH__ *)GetStockObject(i: 4);
    CursorA = LoadCursorA(hInstance: nullptr, lpCursorName: (LPCSTR)0x7F00);
    v5 = AfxRegisterWndClass(nClassStyle: 0xBu, hCursor: CursorA, hbrBackground: StockObject, hIcon: nullptr);
    if ( v5 != nullptr )
      v6 = strlen(v5);
    else
      v6 = 0;
    ATL::CSimpleStringT<char,0>::SetString(this: &LPreviewWndClassName, pszSrc: v5, nLength: v6);
  }
  rect.right = 600;
  rect.bottom = 600;
  rect.left = 500;
  rect.top = 500;
  CWnd::CreateEx(
    this,
    dwExStyle: 0,
    lpszClassName: LPreviewWndClassName.m_pszData,
    lpszWindowName: "LightingPreviewWindow",
    dwStyle: 0xCF0000u,
    &rect,
    pParentWnd: nullptr,
    nID: 0,
    lpParam: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x105CA760
// Name: _CLightingPreviewResultsWindow::Create_::_2_::_dynamic_atexit_destructor_for__LPreviewWndClassName__
// Source: json
//------------------------------------------------------------------------------
void __cdecl CLightingPreviewResultsWindow::Create_::_2_::_dynamic_atexit_destructor_for__LPreviewWndClassName__()
{
  char *v0; // eax

  v0 = LPreviewWndClassName.m_pszData - 16;
  if ( _InterlockedDecrement((volatile signed __int32 *)LPreviewWndClassName.m_pszData - 1) <= 0 )
    (*(void (__stdcall **)(char *))(**(_DWORD **)v0 + 4))(a1: v0);
}

//------------------------------------------------------------------------------
// Address: 0x105CA7B0
// Name: _dynamic_atexit_destructor_for__gd__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__gd__()
{
  GameData::~GameData(this: &gd);
}

//------------------------------------------------------------------------------
// Address: 0x105CA7C0
// Name: _dynamic_atexit_destructor_for__mcm_CManifestInstance__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mcm_CManifestInstance__()
{
  CMapClassManager::~CMapClassManager(this: &mcm_CManifestInstance);
}
