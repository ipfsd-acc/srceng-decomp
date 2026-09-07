// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: hammer/progdlg.cpp
// Functions: 19
// ============================================================

#include "hammer\progdlg.h"

//------------------------------------------------------------------------------
// Address: 0x100F3F10
// Name: protected: virtual void CProgressDlg::OnCancel(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CProgressDlg::OnCancel(CProgressDlg *this)
{
  this->m_bCancel = 1;
}

//------------------------------------------------------------------------------
// Address: 0x100F3F20
// Name: protected: void CProgressDlg::PumpMessages(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CProgressDlg::PumpMessages(CProgressDlg *this)
{
  tagMSG msg; // [esp+4h] [ebp-20h] BYREF
  CWnd *v2; // [esp+20h] [ebp-4h]

  v2 = this;
  while ( PeekMessageA(lpMsg: &msg, hWnd: nullptr, wMsgFilterMin: 0, wMsgFilterMax: 0, wRemoveMsg: 1u) )
  {
    if ( CWnd::IsDialogMessageA(this: v2, lpMsg: &msg) == 0 )
    {
      TranslateMessage(lpMsg: &msg);
      DispatchMessageA(lpMsg: &msg);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100F3FC0
// Name: public: CProgressDlg::CProgressDlg(unsigned int)
// Source: json
//------------------------------------------------------------------------------
CProgressDlg *__thiscall CProgressDlg::CProgressDlg(CProgressDlg *this, unsigned int nCaptionID)
{
  CDialog::CDialog(this);
  this->__vftable = (CProgressDlg_vtbl *)&CProgressDlg::`vftable';
  CWnd::CWnd(this: &this->m_Progress);
  this->m_Progress.__vftable = (CProgressCtrl_vtbl *)&CProgressCtrl::`vftable';
  this->m_nCaptionID = 104;
  if ( nCaptionID != 0 )
    this->m_nCaptionID = nCaptionID;
  this->m_bCancel = 0;
  this->m_nLower = 0;
  this->m_nUpper = 100;
  this->m_nStep = 10;
  this->m_bParentDisabled = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100F4070
// Name: public: virtual int CProgressDlg::DestroyWindow(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CProgressDlg::DestroyWindow(CProgressDlg *this)
{
  CWnd *m_pParentWnd; // ecx

  if ( this->m_bParentDisabled != 0 )
  {
    m_pParentWnd = this->m_pParentWnd;
    if ( m_pParentWnd != nullptr )
      CWnd::EnableWindow(this: m_pParentWnd, bEnable: 1);
  }
  this->m_bParentDisabled = 0;
  return CWnd::DestroyWindow(this);
}

//------------------------------------------------------------------------------
// Address: 0x100F40A0
// Name: public: int CProgressDlg::Create(class CWnd __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CProgressDlg::Create(CProgressDlg *this, CWnd *pParent)
{
  CWnd *SafeOwner; // eax
  CWnd *m_pParentWnd; // ecx

  SafeOwner = CWnd::GetSafeOwner(pParent, pWndTop: nullptr);
  this->m_pParentWnd = SafeOwner;
  if ( SafeOwner != nullptr && CWnd::IsWindowEnabled(this: SafeOwner) != 0 )
  {
    CWnd::EnableWindow(this: this->m_pParentWnd, bEnable: 0);
    this->m_bParentDisabled = 1;
  }
  if ( CDialog::Create(this, lpszTemplateName: (const char *)0x67, pParentWnd: pParent) != 0 )
    return 1;
  if ( this->m_bParentDisabled != 0 )
  {
    m_pParentWnd = this->m_pParentWnd;
    if ( m_pParentWnd != nullptr )
      CWnd::EnableWindow(this: m_pParentWnd, bEnable: 1);
  }
  this->m_bParentDisabled = 0;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x100F4130
// Name: protected: virtual void CProgressDlg::DoDataExchange(class CDataExchange __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CProgressDlg::DoDataExchange(CProgressDlg *this, CDataExchange *pDX)
{
  DDX_Control(pDX, nIDC: (HWND__ *)0x3EB, rControl: (HWND__ *)&this->m_Progress);
}

//------------------------------------------------------------------------------
// Address: 0x100F4150
// Name: public: void CProgressDlg::SetRange(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CProgressDlg::SetRange(CProgressDlg *this, int nLower, int nUpper)
{
  this->m_nUpper = nUpper;
  this->m_nLower = nLower;
  SendMessageA(
    hWnd: this->m_Progress.m_hWnd,
    Msg: 0x401u,
    wParam: 0,
    lParam: (unsigned __int16)nLower | ((unsigned __int16)nUpper << 16));
}

//------------------------------------------------------------------------------
// Address: 0x100F4190
// Name: public: int CProgressDlg::SetStep(int)
// Source: json
//------------------------------------------------------------------------------
LRESULT __thiscall CProgressDlg::SetStep(CProgressDlg *this, int nStep)
{
  this->m_nStep = nStep;
  return SendMessageA(hWnd: this->m_Progress.m_hWnd, Msg: 0x404u, wParam: nStep, lParam: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100F41C0
// Name: public: virtual CProgressDlg::~CProgressDlg(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CProgressDlg::~CProgressDlg(CProgressDlg *this)
{
  CWnd *m_pParentWnd; // ecx

  this->__vftable = (CProgressDlg_vtbl *)&CProgressDlg::`vftable';
  if ( this->m_hWnd != nullptr )
  {
    if ( this->m_bParentDisabled != 0 )
    {
      m_pParentWnd = this->m_pParentWnd;
      if ( m_pParentWnd != nullptr )
        CWnd::EnableWindow(this: m_pParentWnd, bEnable: 1);
    }
    this->m_bParentDisabled = 0;
    CWnd::DestroyWindow(this);
  }
  CProgressCtrl::~CProgressCtrl(this: &this->m_Progress);
  CDialog::~CDialog(this);
}

//------------------------------------------------------------------------------
// Address: 0x100F4280
// Name: protected: void CProgressDlg::UpdatePercent(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CProgressDlg::UpdatePercent(CProgressDlg *this, const unsigned __int8 *nNewPos)
{
  CWnd *DlgItem; // edi
  int v4; // esi
  CAfxStringMgr *StringManager; // eax
  CAfxStringMgr *v6; // eax
  const char *v7; // esi
  char *v8; // eax
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > strCur; // [esp+8h] [ebp-10h] BYREF
  int v10; // [esp+14h] [ebp-4h]

  DlgItem = CWnd::GetDlgItem(this, nID: 1004);
  v4 = 100 * (int)&nNewPos[-this->m_nLower] / (this->m_nUpper - this->m_nLower);
  if ( v4 != 100 )
    v4 %= -100;
  StringManager = AfxGetStringManager();
  if ( StringManager == nullptr )
    ATL::AtlThrowImpl(hr: -2147467259);
  nNewPos = (const unsigned __int8 *)&StringManager->GetNilString(this: StringManager)[1];
  v10 = 1;
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::Format(
    this: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&nNewPos,
    pszFormat: "%d%c",
    v4,
    37);
  v6 = AfxGetStringManager();
  if ( v6 == nullptr )
    ATL::AtlThrowImpl(hr: -2147467259);
  strCur.m_pszData = (char *)&v6->GetNilString(this: v6)[1];
  LOBYTE(v10) = 3;
  CWnd::GetWindowTextA(this: DlgItem, rString: &strCur);
  v7 = (const char *)nNewPos;
  if ( nNewPos == nullptr )
    ATL::AtlThrowImpl(hr: -2147467259);
  if ( _mbscmp(s1: (const unsigned __int8 *)strCur.m_pszData, s2: nNewPos) != 0 )
    CWnd::SetWindowTextA(this: DlgItem, lpszString: v7);
  LOBYTE(v10) = 1;
  v8 = strCur.m_pszData - 16;
  if ( _InterlockedDecrement((volatile signed __int32 *)strCur.m_pszData - 1) <= 0 )
    (*(void (__stdcall **)(char *))(**(_DWORD **)v8 + 4))(a1: v8);
  v10 = -1;
  if ( _InterlockedDecrement((volatile signed __int32 *)v7 - 1) <= 0 )
    (*(void (__thiscall **)(_DWORD, const char *))(**((_DWORD **)v7 - 4) + 4))(a1: *((_DWORD *)v7 - 4), a2: v7 - 16);
}

//------------------------------------------------------------------------------
// Address: 0x100F43F0
// Name: protected: virtual int CProgressDlg::OnInitDialog(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CProgressDlg::OnInitDialog(CProgressDlg *this)
{
  CAfxStringMgr *StringManager; // eax
  char *m_pszData; // ebx
  unsigned int m_nCaptionID; // edi
  HINSTANCE__ *StringResourceHandle; // eax
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > strCaption; // [esp+Ch] [ebp-10h] BYREF
  int v8; // [esp+18h] [ebp-4h]

  CDialog::OnInitDialog(this);
  SendMessageA(
    hWnd: this->m_Progress.m_hWnd,
    Msg: 0x401u,
    wParam: 0,
    lParam: LOWORD(this->m_nLower) | (LOWORD(this->m_nUpper) << 16));
  SendMessageA(hWnd: this->m_Progress.m_hWnd, Msg: 0x404u, wParam: this->m_nStep, lParam: 0);
  SendMessageA(hWnd: this->m_Progress.m_hWnd, Msg: 0x402u, wParam: this->m_nLower, lParam: 0);
  StringManager = AfxGetStringManager();
  if ( StringManager == nullptr )
    ATL::AtlThrowImpl(hr: -2147467259);
  m_pszData = (char *)&StringManager->GetNilString(this: StringManager)[1];
  strCaption.m_pszData = m_pszData;
  v8 = 1;
  m_nCaptionID = this->m_nCaptionID;
  StringResourceHandle = AfxFindStringResourceHandle(__formal: m_nCaptionID);
  if ( StringResourceHandle != nullptr )
  {
    ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::LoadStringA(
      this: &strCaption,
      hInstance: StringResourceHandle,
      nID: m_nCaptionID);
    m_pszData = strCaption.m_pszData;
  }
  CWnd::SetWindowTextA(this, lpszString: m_pszData);
  v8 = -1;
  if ( _InterlockedDecrement((volatile signed __int32 *)m_pszData - 1) <= 0 )
    (*(void (__thiscall **)(_DWORD, char *))(**((_DWORD **)m_pszData - 4) + 4))(
      a1: *((_DWORD *)m_pszData - 4),
      a2: m_pszData - 16);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100F4500
// Name: public: int CProgressDlg::SetPos(int)
// Source: json
//------------------------------------------------------------------------------
LRESULT __thiscall CProgressDlg::SetPos(CProgressDlg *this, const unsigned __int8 *nPos)
{
  LRESULT v3; // ebx

  CProgressDlg::PumpMessages(this);
  v3 = SendMessageA(hWnd: this->m_Progress.m_hWnd, Msg: 0x402u, wParam: (WPARAM)nPos, lParam: 0);
  CProgressDlg::UpdatePercent(this, nNewPos: nPos);
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x100F4540
// Name: public: int CProgressDlg::StepIt(void)
// Source: json
//------------------------------------------------------------------------------
LRESULT __thiscall CProgressDlg::StepIt(CProgressDlg *this)
{
  LRESULT v2; // edi

  CProgressDlg::PumpMessages(this);
  v2 = SendMessageA(hWnd: this->m_Progress.m_hWnd, Msg: 0x405u, wParam: 0, lParam: 0);
  CProgressDlg::UpdatePercent(this, nNewPos: (const unsigned __int8 *)(v2 + this->m_nStep));
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x1034AA13
// Name: public: virtual int CProgressCtrl::Create(unsigned long,struct tagRECT const __near &,class CWnd __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CProgressCtrl::Create(
        CProgressCtrl *this,
        unsigned int dwStyle,
        const tagRECT *rect,
        CWnd *pParentWnd,
        unsigned int nID)
{
  AfxEndDeferRegisterClass(fToRegister: 512);
  return this->Create(
           this,
           a2: "msctls_progress32",
           a3: nullptr,
           a4: dwStyle,
           a5: rect,
           a6: pParentWnd,
           a7: nID,
           a8: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x1034AA46
// Name: public: virtual CProgressCtrl::~CProgressCtrl(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CProgressCtrl::~CProgressCtrl(CProgressCtrl *this)
{
  this->__vftable = (CProgressCtrl_vtbl *)&CProgressCtrl::`vftable';
  CWnd::DestroyWindow(this);
  CWnd::~CWnd(this);
}

//------------------------------------------------------------------------------
// Address: 0x1034ABD8
// Name: public: virtual struct CRuntimeClass __near * CProgressCtrl::GetRuntimeClass(void)const
// Source: json
//------------------------------------------------------------------------------
CRuntimeClass *__thiscall CProgressCtrl::GetRuntimeClass(CProgressCtrl *this)
{
  return &CProgressCtrl::classCProgressCtrl;
}

//------------------------------------------------------------------------------
// Address: 0x1034AA77
// Name: public: virtual int CHeaderCtrl::Create(unsigned long,struct tagRECT const __near &,class CWnd __near *,unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CHeaderCtrl::Create(
        CHeaderCtrl *this,
        unsigned int dwStyle,
        const tagRECT *rect,
        CWnd *pParentWnd,
        unsigned int nID)
{
  AfxEndDeferRegisterClass(fToRegister: 1024);
  return this->Create(this, a2: "SysHeader32", a3: nullptr, a4: dwStyle, a5: rect, a6: pParentWnd, a7: nID, a8: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x1034AAAA
// Name: public: virtual CHeaderCtrl::~CHeaderCtrl(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CHeaderCtrl::~CHeaderCtrl(CHeaderCtrl *this)
{
  this->__vftable = (CHeaderCtrl_vtbl *)&CHeaderCtrl::`vftable';
  CWnd::DestroyWindow(this);
  CWnd::~CWnd(this);
}

//------------------------------------------------------------------------------
// Address: 0x1034ABDE
// Name: public: virtual struct CRuntimeClass __near * CHeaderCtrl::GetRuntimeClass(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CRuntimeClass *__thiscall CHeaderCtrl::GetRuntimeClass(CHeaderCtrl *this)
{
  return &CHeaderCtrl::classCHeaderCtrl;
}
