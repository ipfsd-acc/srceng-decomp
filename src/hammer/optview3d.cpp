// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: hammer/optview3d.cpp
// Functions: 9
// ============================================================

#include "hammer\optview3d.h"

//------------------------------------------------------------------------------
// Address: 0x100F14B0
// Name: public: virtual struct CRuntimeClass __near * COPTView3D::GetRuntimeClass(void)const
// Source: json
//------------------------------------------------------------------------------
CRuntimeClass *__thiscall COPTView3D::GetRuntimeClass(COPTView3D *this)
{
  return &COPTView3D::classCOPTView3D;
}

//------------------------------------------------------------------------------
// Address: 0x100F14C0
// Name: public: virtual COPTView3D::~COPTView3D(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COPTView3D::~COPTView3D(COPTView3D *this)
{
  this->__vftable = (COPTView3D_vtbl *)&COPTView3D::`vftable';
  CSliderCtrl::~CSliderCtrl(this: &this->m_TimeToMaxSpeed);
  CStatic::~CStatic(this: &this->m_TimeToMaxSpeedText);
  CSliderCtrl::~CSliderCtrl(this: &this->m_ForwardSpeedMax);
  CStatic::~CStatic(this: &this->m_ForwardSpeedText);
  CSliderCtrl::~CSliderCtrl(this: &this->m_DetailDistance);
  CStatic::~CStatic(this: &this->m_DetailDistanceText);
  CSliderCtrl::~CSliderCtrl(this: &this->m_ModelDistance);
  CStatic::~CStatic(this: &this->m_ModelDistanceText);
  CSliderCtrl::~CSliderCtrl(this: &this->m_cBackPlane);
  CStatic::~CStatic(this: &this->m_cBackText);
  CPropertyPage::~CPropertyPage(this);
}

//------------------------------------------------------------------------------
// Address: 0x100F15A0
// Name: protected: virtual int COPTView3D::OnInitDialog(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall COPTView3D::OnInitDialog(COPTView3D *this)
{
  this->m_bOldFilterTextures = Options.view3d.bFilterTextures;
  CDialog::OnInitDialog(this);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100F15C0
// Name: public: virtual int COPTView3D::OnApply(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall COPTView3D::OnApply(COPTView3D *this)
{
  if ( Options.view3d.bFilterTextures != this->m_bOldFilterTextures )
    AfxMessageBox(
      lpszText: "The changes to the 'Filter textures' setting will not take effect for any currently visible textures. Close all 3D"
      " views and reopen them for the new setting to completely take effect.",
      nType: 0,
      nIDHelp: 0);
  COptions::PerformChanges(this: &Options, dwOptionsChanged: 8);
  return CPropertyPage::OnApply(this);
}

//------------------------------------------------------------------------------
// Address: 0x100F1600
// Name: public: COPTView3D::COPTView3D(void)
// Source: json
//------------------------------------------------------------------------------
COPTView3D *__thiscall COPTView3D::COPTView3D(COPTView3D *this)
{
  CPropertyPage::CPropertyPage(this, nIDTemplate: 0xC7u, nIDCaption: 0, dwSize: 0x38u);
  this->__vftable = (COPTView3D_vtbl *)&COPTView3D::`vftable';
  CWnd::CWnd(this: &this->m_cBackText);
  this->m_cBackText.__vftable = (CStatic_vtbl *)&CStatic::`vftable';
  CWnd::CWnd(this: &this->m_cBackPlane);
  this->m_cBackPlane.__vftable = (CSliderCtrl_vtbl *)&CSliderCtrl::`vftable';
  CWnd::CWnd(this: &this->m_ModelDistanceText);
  this->m_ModelDistanceText.__vftable = (CStatic_vtbl *)&CStatic::`vftable';
  CWnd::CWnd(this: &this->m_ModelDistance);
  this->m_ModelDistance.__vftable = (CSliderCtrl_vtbl *)&CSliderCtrl::`vftable';
  CWnd::CWnd(this: &this->m_DetailDistanceText);
  this->m_DetailDistanceText.__vftable = (CStatic_vtbl *)&CStatic::`vftable';
  CWnd::CWnd(this: &this->m_DetailDistance);
  this->m_DetailDistance.__vftable = (CSliderCtrl_vtbl *)&CSliderCtrl::`vftable';
  CWnd::CWnd(this: &this->m_ForwardSpeedText);
  this->m_ForwardSpeedText.__vftable = (CStatic_vtbl *)&CStatic::`vftable';
  CWnd::CWnd(this: &this->m_ForwardSpeedMax);
  this->m_ForwardSpeedMax.__vftable = (CSliderCtrl_vtbl *)&CSliderCtrl::`vftable';
  CWnd::CWnd(this: &this->m_TimeToMaxSpeedText);
  this->m_TimeToMaxSpeedText.__vftable = (CStatic_vtbl *)&CStatic::`vftable';
  CWnd::CWnd(this: &this->m_TimeToMaxSpeed);
  this->m_TimeToMaxSpeed.__vftable = (CSliderCtrl_vtbl *)&CSliderCtrl::`vftable';
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100F17B0
// Name: public: static class CObject __near * COPTView3D::CreateObject(void)
// Source: json
//------------------------------------------------------------------------------
COPTView3D *__stdcall COPTView3D::CreateObject()
{
  COPTView3D *v0; // eax

  v0 = (COPTView3D *)operator new(nSize: 0x534u);
  if ( v0 != nullptr )
    return COPTView3D::COPTView3D(this: v0);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x100F1810
// Name: protected: virtual void COPTView3D::DoDataExchange(class CDataExchange __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COPTView3D::DoDataExchange(COPTView3D *this, CDataExchange *pDX)
{
  CDataExchange *v2; // edi
  CStatic *p_m_cBackText; // ebx
  CAfxStringMgr *StringManager; // eax
  LRESULT v6; // eax
  LRESULT v7; // eax
  LRESULT v8; // eax
  LRESULT v9; // eax
  LRESULT v10; // eax
  CDataExchange *v11; // esi
  CStatic *p_m_TimeToMaxSpeedText; // [esp+14h] [ebp-10h]

  v2 = pDX;
  p_m_cBackText = &this->m_cBackText;
  DDX_Control(pDX, nIDC: (HWND__ *)0x504, rControl: (HWND__ *)&this->m_cBackText);
  DDX_Control(pDX: v2, nIDC: (HWND__ *)0x503, rControl: (HWND__ *)&this->m_cBackPlane);
  DDX_Control(pDX: v2, nIDC: (HWND__ *)0x587, rControl: (HWND__ *)&this->m_ModelDistanceText);
  DDX_Control(pDX: v2, nIDC: (HWND__ *)0x586, rControl: (HWND__ *)&this->m_ModelDistance);
  DDX_Control(pDX: v2, nIDC: (HWND__ *)0x585, rControl: (HWND__ *)&this->m_DetailDistanceText);
  DDX_Control(pDX: v2, nIDC: (HWND__ *)0x584, rControl: (HWND__ *)&this->m_DetailDistance);
  DDX_Control(pDX: v2, nIDC: (HWND__ *)0x592, rControl: (HWND__ *)&this->m_ForwardSpeedText);
  DDX_Control(pDX: v2, nIDC: (HWND__ *)0x590, rControl: (HWND__ *)&this->m_ForwardSpeedMax);
  p_m_TimeToMaxSpeedText = &this->m_TimeToMaxSpeedText;
  DDX_Control(pDX: v2, nIDC: (HWND__ *)0x593, rControl: (HWND__ *)&this->m_TimeToMaxSpeedText);
  DDX_Control(pDX: v2, nIDC: (HWND__ *)0x591, rControl: (HWND__ *)&this->m_TimeToMaxSpeed);
  DDX_Check(pDX: (HWND__ *)v2, nIDC: (HWND__ *)0x5AC, value: &Options.view3d.bFilterTextures);
  DDX_Check(pDX: (HWND__ *)v2, nIDC: (HWND__ *)0x4C5, value: &Options.view3d.bReverseY);
  DDX_Check(pDX: (HWND__ *)v2, nIDC: (HWND__ *)0x57A, value: &Options.view3d.bUseMouseLook);
  DDX_Check(pDX: (HWND__ *)v2, nIDC: (HWND__ *)0x588, value: &Options.view3d.bAnimateModels);
  DDX_Check(pDX: (HWND__ *)v2, nIDC: (HWND__ *)0x5B4, value: &Options.view3d.bReverseSelection);
  DDX_Text(pDX: v2, nIDC: (HWND__ *)0x67B, value: (CDataExchange *)&Options.view3d.fFOV);
  if ( (int)Options.view3d.fFOV < 30 || (int)Options.view3d.fFOV > 100 )
  {
    AfxMessageBox(lpszText: "FOV must be 30-100.", nType: 0x30u, nIDHelp: 0);
    CDataExchange::Fail(this: v2);
  }
  CSliderCtrl::SetRange(this: &this->m_cBackPlane, nMin: 500, nMax: 10000, bRedraw: 1u);
  CSliderCtrl::SetRange(this: &this->m_ModelDistance, nMin: 0, nMax: 10000, bRedraw: 1u);
  CSliderCtrl::SetRange(this: &this->m_DetailDistance, nMin: 0, nMax: 10000, bRedraw: 1u);
  CSliderCtrl::SetRange(this: &this->m_ForwardSpeedMax, nMin: 100, nMax: 10000, bRedraw: 1u);
  CSliderCtrl::SetRange(this: &this->m_TimeToMaxSpeed, nMin: 0, nMax: 10000, bRedraw: 1u);
  if ( v2->m_bSaveAndValidate != 0 )
  {
    Options.view3d.iBackPlane = SendMessageA(hWnd: this->m_cBackPlane.m_hWnd, Msg: 0x400u, wParam: 0, lParam: 0);
    Options.view3d.nModelDistance = SendMessageA(hWnd: this->m_ModelDistance.m_hWnd, Msg: 0x400u, wParam: 0, lParam: 0);
    Options.view3d.nDetailDistance = SendMessageA(
                                       hWnd: this->m_DetailDistance.m_hWnd,
                                       Msg: 0x400u,
                                       wParam: 0,
                                       lParam: 0);
    Options.view3d.nForwardSpeedMax = SendMessageA(
                                        hWnd: this->m_ForwardSpeedMax.m_hWnd,
                                        Msg: 0x400u,
                                        wParam: 0,
                                        lParam: 0);
    Options.view3d.nTimeToMaxSpeed = SendMessageA(
                                       hWnd: this->m_TimeToMaxSpeed.m_hWnd,
                                       Msg: 0x400u,
                                       wParam: 0,
                                       lParam: 0);
  }
  else
  {
    StringManager = AfxGetStringManager();
    if ( StringManager == nullptr )
      ATL::AtlThrowImpl(hr: -2147467259);
    pDX = (CDataExchange *)&StringManager->GetNilString(this: StringManager)[1];
    SendMessageA(hWnd: this->m_cBackPlane.m_hWnd, Msg: 0x405u, wParam: 1u, lParam: Options.view3d.iBackPlane);
    v6 = SendMessageA(hWnd: this->m_cBackPlane.m_hWnd, Msg: 0x400u, wParam: 0, lParam: 0);
    ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::Format(
      this: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&pDX,
      pszFormat: "%d",
      v6);
    CWnd::SetWindowTextA(this: p_m_cBackText, lpszString: (const char *)pDX);
    SendMessageA(hWnd: this->m_ModelDistance.m_hWnd, Msg: 0x405u, wParam: 1u, lParam: Options.view3d.nModelDistance);
    v7 = SendMessageA(hWnd: this->m_ModelDistance.m_hWnd, Msg: 0x400u, wParam: 0, lParam: 0);
    ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::Format(
      this: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&pDX,
      pszFormat: "%d",
      v7);
    CWnd::SetWindowTextA(this: &this->m_ModelDistanceText, lpszString: (const char *)pDX);
    SendMessageA(hWnd: this->m_DetailDistance.m_hWnd, Msg: 0x405u, wParam: 1u, lParam: Options.view3d.nDetailDistance);
    v8 = SendMessageA(hWnd: this->m_DetailDistance.m_hWnd, Msg: 0x400u, wParam: 0, lParam: 0);
    ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::Format(
      this: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&pDX,
      pszFormat: "%d",
      v8);
    CWnd::SetWindowTextA(this: &this->m_DetailDistanceText, lpszString: (const char *)pDX);
    SendMessageA(hWnd: this->m_ForwardSpeedMax.m_hWnd, Msg: 0x405u, wParam: 1u, lParam: Options.view3d.nForwardSpeedMax);
    v9 = SendMessageA(hWnd: this->m_ForwardSpeedMax.m_hWnd, Msg: 0x400u, wParam: 0, lParam: 0);
    ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::Format(
      this: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&pDX,
      pszFormat: "%d",
      v9);
    CWnd::SetWindowTextA(this: &this->m_ForwardSpeedText, lpszString: (const char *)pDX);
    SendMessageA(hWnd: this->m_TimeToMaxSpeed.m_hWnd, Msg: 0x405u, wParam: 1u, lParam: Options.view3d.nTimeToMaxSpeed);
    v10 = SendMessageA(hWnd: this->m_TimeToMaxSpeed.m_hWnd, Msg: 0x400u, wParam: 0, lParam: 0);
    ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::Format(
      this: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&pDX,
      pszFormat: "%.2f sec",
      (float)((float)v10 * 0.001));
    v11 = pDX;
    CWnd::SetWindowTextA(this: p_m_TimeToMaxSpeedText, lpszString: (const char *)pDX);
    if ( _InterlockedDecrement(&v11[-1].m_bEditLastControl) <= 0 )
      (*(void (__thiscall **)(int, CDataExchange *))(*(_DWORD *)v11[-1].m_bSaveAndValidate + 4))(
        a1: v11[-1].m_bSaveAndValidate,
        a2: v11 - 1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100F1C70
// Name: protected: void COPTView3D::OnHScroll(unsigned int,unsigned int,class CScrollBar __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COPTView3D::OnHScroll(
        COPTView3D *this,
        unsigned int nSBCode,
        unsigned int nPos,
        CScrollBar *pScrollBar)
{
  HWND__ *m_hWnd; // eax
  HWND__ *v6; // ecx
  LRESULT v7; // edi
  CAfxStringMgr *StringManager; // eax
  CMainFrame *MainWnd; // edi
  HWND__ *v10; // ecx
  LRESULT v11; // edi
  CAfxStringMgr *v12; // eax
  CMainFrame *v13; // edi
  HWND__ *v14; // ecx
  LRESULT v15; // edi
  CMainFrame *v16; // edi
  char *v17; // eax
  HWND__ *v18; // ecx
  LRESULT v19; // edi
  float v20; // [esp+14h] [ebp-14h]
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > v21; // [esp+18h] [ebp-10h] BYREF
  int v22; // [esp+24h] [ebp-4h]

  m_hWnd = pScrollBar->m_hWnd;
  v6 = this->m_cBackPlane.m_hWnd;
  if ( m_hWnd == v6 )
  {
    v7 = SendMessageA(hWnd: v6, Msg: 0x400u, wParam: 0, lParam: 0);
    StringManager = AfxGetStringManager();
    if ( StringManager == nullptr )
      ATL::AtlThrowImpl(hr: -2147467259);
    v21.m_pszData = (char *)&StringManager->GetNilString(this: StringManager)[1];
    v22 = 1;
    ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::Format(this: &v21, pszFormat: "%d", v7);
    CWnd::SetWindowTextA(this: &this->m_cBackText, lpszString: v21.m_pszData);
    MainWnd = GetMainWnd();
    if ( MainWnd != nullptr )
    {
      Options.view3d.iBackPlane = SendMessageA(hWnd: this->m_cBackPlane.m_hWnd, Msg: 0x400u, wParam: 0, lParam: 0);
      CMainFrame::UpdateAllDocViews(this: MainWnd, dwCmd: 0x900u);
    }
  }
  else
  {
    v10 = this->m_ModelDistance.m_hWnd;
    if ( m_hWnd == v10 )
    {
      v11 = SendMessageA(hWnd: v10, Msg: 0x400u, wParam: 0, lParam: 0);
      v12 = AfxGetStringManager();
      if ( v12 == nullptr )
        ATL::AtlThrowImpl(hr: -2147467259);
      v21.m_pszData = (char *)&v12->GetNilString(this: v12)[1];
      v22 = 4;
      ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::Format(this: &v21, pszFormat: "%d", v11);
      CWnd::SetWindowTextA(this: &this->m_ModelDistanceText, lpszString: v21.m_pszData);
      v13 = GetMainWnd();
      if ( v13 != nullptr )
      {
        Options.view3d.nModelDistance = SendMessageA(
                                          hWnd: this->m_ModelDistance.m_hWnd,
                                          Msg: 0x400u,
                                          wParam: 0,
                                          lParam: 0);
        CMainFrame::UpdateAllDocViews(this: v13, dwCmd: 0x940u);
      }
    }
    else
    {
      v14 = this->m_DetailDistance.m_hWnd;
      if ( m_hWnd != v14 )
      {
        v18 = this->m_ForwardSpeedMax.m_hWnd;
        if ( m_hWnd == v18 )
        {
          v19 = SendMessageA(hWnd: v18, Msg: 0x400u, wParam: 0, lParam: 0);
          ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>(this: &v21);
          v22 = 8;
          ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::Format(this: &v21, pszFormat: "%d", v19);
          CWnd::SetWindowTextA(this: &this->m_ForwardSpeedText, lpszString: v21.m_pszData);
        }
        else
        {
          if ( m_hWnd != this->m_TimeToMaxSpeed.m_hWnd )
            goto LABEL_23;
          v20 = (float)CSliderCtrl::GetPos(this: &this->m_TimeToMaxSpeed) * 0.001;
          ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>(this: &v21);
          v22 = 9;
          ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::Format(this: &v21, pszFormat: "%.2f sec", v20);
          CWnd::SetWindowTextA(this: &this->m_TimeToMaxSpeedText, lpszString: v21.m_pszData);
        }
        v22 = -1;
        ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::~CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>(this: &v21);
        goto LABEL_23;
      }
      v15 = SendMessageA(hWnd: v14, Msg: 0x400u, wParam: 0, lParam: 0);
      ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>(this: &v21);
      v22 = 6;
      ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::Format(this: &v21, pszFormat: "%d", v15);
      CWnd::SetWindowTextA(this: &this->m_DetailDistanceText, lpszString: v21.m_pszData);
      v16 = GetMainWnd();
      if ( v16 != nullptr )
      {
        Options.view3d.nDetailDistance = SendMessageA(
                                           hWnd: this->m_DetailDistance.m_hWnd,
                                           Msg: 0x400u,
                                           wParam: 0,
                                           lParam: 0);
        CMainFrame::UpdateAllDocViews(this: v16, dwCmd: 0x940u);
      }
    }
  }
  v22 = -1;
  v17 = v21.m_pszData - 16;
  if ( _InterlockedDecrement((volatile signed __int32 *)v21.m_pszData - 1) <= 0 )
    (*(void (__stdcall **)(char *))(**(_DWORD **)v17 + 4))(a1: v17);
LABEL_23:
  CWnd::OnHScroll(this, __formal: nSBCode, a3: nPos, pScrollBar);
}

//------------------------------------------------------------------------------
// Address: 0x100F1F80
// Name: protected: virtual struct AFX_MSGMAP const __near * COPTView3D::GetMessageMap(void)const
// Source: json
//------------------------------------------------------------------------------
const AFX_MSGMAP *__thiscall COPTView3D::GetMessageMap(COPTView3D *this)
{
  return (const AFX_MSGMAP *)&off_105F11B4;
}
