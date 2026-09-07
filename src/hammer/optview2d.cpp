// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: hammer/optview2d.cpp
// Functions: 8
// ============================================================

#include "hammer\optview2d.h"

//------------------------------------------------------------------------------
// Address: 0x100F0FE0
// Name: public: virtual struct CRuntimeClass __near * COPTView2D::GetRuntimeClass(void)const
// Source: json
//------------------------------------------------------------------------------
CRuntimeClass *__thiscall COPTView2D::GetRuntimeClass(COPTView2D *this)
{
  return &COPTView2D::classCOPTView2D;
}

//------------------------------------------------------------------------------
// Address: 0x100F0FF0
// Name: public: virtual COPTView2D::~COPTView2D(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COPTView2D::~COPTView2D(COPTView2D *this)
{
  this->__vftable = (COPTView2D_vtbl *)&COPTView2D::`vftable';
  CSliderCtrl::~CSliderCtrl(this: &this->m_cGridIntensity);
  CPropertyPage::~CPropertyPage(this);
}

//------------------------------------------------------------------------------
// Address: 0x100F1050
// Name: protected: virtual int COPTView2D::OnInitDialog(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall COPTView2D::OnInitDialog(COPTView2D *this)
{
  CWnd *DlgItem; // eax
  CWnd *v3; // esi

  DlgItem = CWnd::GetDlgItem(this, nID: 1465);
  v3 = DlgItem;
  if ( DlgItem != nullptr )
  {
    CWnd::EnableWindow(this: DlgItem, bEnable: 0);
    CWnd::ShowWindow(this: v3, nCmdShow: 0);
  }
  CDialog::OnInitDialog(this);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100F1090
// Name: public: virtual int COPTView2D::OnApply(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall COPTView2D::OnApply(COPTView2D *this)
{
  COptions::PerformChanges(this: &Options, dwOptionsChanged: 4);
  return CPropertyPage::OnApply(this);
}

//------------------------------------------------------------------------------
// Address: 0x100F10B0
// Name: public: COPTView2D::COPTView2D(void)
// Source: json
//------------------------------------------------------------------------------
COPTView2D *__thiscall COPTView2D::COPTView2D(COPTView2D *this)
{
  CPropertyPage::CPropertyPage(this, nIDTemplate: 0xB3u, nIDCaption: 0, dwSize: 0x38u);
  this->__vftable = (COPTView2D_vtbl *)&COPTView2D::`vftable';
  CWnd::CWnd(this: &this->m_cGridIntensity);
  this->m_cGridIntensity.__vftable = (CSliderCtrl_vtbl *)&CSliderCtrl::`vftable';
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100F1190
// Name: protected: virtual struct AFX_MSGMAP const __near * COPTView2D::GetMessageMap(void)const
// Source: json
//------------------------------------------------------------------------------
const AFX_MSGMAP *__thiscall COPTView2D::GetMessageMap(COPTView2D *this)
{
  return (const AFX_MSGMAP *)&off_105F0EF0;
}

//------------------------------------------------------------------------------
// Address: 0x100F11A0
// Name: public: static class CObject __near * COPTView2D::CreateObject(void)
// Source: json
//------------------------------------------------------------------------------
CPropertyPage *__stdcall COPTView2D::CreateObject()
{
  CPropertyPage *v0; // eax
  CPropertyPage *v1; // esi

  v0 = (CPropertyPage *)operator new(nSize: 0x11Cu);
  v1 = v0;
  if ( v0 == nullptr )
    return nullptr;
  CPropertyPage::CPropertyPage(this: v0, nIDTemplate: 0xB3u, nIDCaption: 0, dwSize: 0x38u);
  v1->__vftable = (CPropertyPage_vtbl *)&COPTView2D::`vftable';
  CWnd::CWnd(this: v1 + 1);
  v1[1].__vftable = (CPropertyPage_vtbl *)&CSliderCtrl::`vftable';
  return v1;
}

//------------------------------------------------------------------------------
// Address: 0x100F1250
// Name: protected: virtual void COPTView2D::DoDataExchange(class CDataExchange __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COPTView2D::DoDataExchange(COPTView2D *this, CDataExchange *pDX)
{
  CDataExchange *v2; // esi
  CSliderCtrl *p_m_cGridIntensity; // edi
  CAfxStringMgr *StringManager; // eax
  CDataExchange *v6; // eax

  v2 = pDX;
  p_m_cGridIntensity = &this->m_cGridIntensity;
  DDX_Control(pDX, nIDC: (HWND__ *)0x4FB, rControl: (HWND__ *)&this->m_cGridIntensity);
  CSliderCtrl::SetRange(this: p_m_cGridIntensity, nMin: 10, nMax: 100, bRedraw: 1u);
  DDX_Check(pDX: (HWND__ *)v2, nIDC: (HWND__ *)0x482, value: &Options.view2d.bCrosshairs);
  DDX_Check(pDX: (HWND__ *)v2, nIDC: (HWND__ *)0x484, value: &Options.view2d.bGroupCarve);
  DDX_Check(pDX: (HWND__ *)v2, nIDC: (HWND__ *)0x48B, value: &Options.view2d.bRotateConstrain);
  DDX_Check(pDX: (HWND__ *)v2, nIDC: (HWND__ *)0x48D, value: &Options.view2d.bScrollbars);
  DDX_Check(pDX: (HWND__ *)v2, nIDC: (HWND__ *)0x48E, value: &Options.view2d.bDrawVertices);
  DDX_Check(pDX: (HWND__ *)v2, nIDC: (HWND__ *)0x48F, value: &Options.view2d.bDrawModels);
  DDX_Check(pDX: (HWND__ *)v2, nIDC: (HWND__ *)0x4C9, value: &Options.view2d.bWhiteOnBlack);
  DDX_Check(pDX: (HWND__ *)v2, nIDC: (HWND__ *)0x4F6, value: &Options.view2d.bGridHigh10);
  DDX_Check(pDX: (HWND__ *)v2, nIDC: (HWND__ *)0x4F7, value: &Options.view2d.bHideSmallGrid);
  DDX_Check(pDX: (HWND__ *)v2, nIDC: (HWND__ *)0x502, value: &Options.view2d.bOrientPrimitives);
  DDX_Check(pDX: (HWND__ *)v2, nIDC: (HWND__ *)0x501, value: &Options.view2d.bNudge);
  DDX_Check(pDX: (HWND__ *)v2, nIDC: (HWND__ *)0x503, value: &Options.view2d.bAutoSelect);
  DDX_Check(pDX: (HWND__ *)v2, nIDC: (HWND__ *)0x505, value: &Options.view2d.bSelectbyhandles);
  DDX_Check(pDX: (HWND__ *)v2, nIDC: (HWND__ *)0x50F, value: &Options.view2d.bKeepclonegroup);
  DDX_Check(pDX: (HWND__ *)v2, nIDC: (HWND__ *)0x529, value: &Options.view2d.bGridHigh64);
  DDX_Check(pDX: (HWND__ *)v2, nIDC: (HWND__ *)0x5B9, value: &Options.view2d.bGridHigh1024);
  DDX_Check(pDX: (HWND__ *)v2, nIDC: (HWND__ *)0x533, value: &Options.view2d.bCenteroncamera);
  DDX_Check(pDX: (HWND__ *)v2, nIDC: (HWND__ *)0x547, value: &Options.view2d.bUsegroupcolors);
  DDX_Check(pDX: (HWND__ *)v2, nIDC: (HWND__ *)0x52A, value: &Options.view2d.bGridDots);
  DDX_Text(pDX: v2, nIDC: (HWND__ *)0x50A, value: &Options.view2d.iGridHighSpec);
  StringManager = AfxGetStringManager();
  if ( StringManager == nullptr )
    ATL::AtlThrowImpl(hr: -2147467259);
  pDX = (CDataExchange *)&StringManager->GetNilString(this: StringManager)[1];
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::Format(
    this: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&pDX,
    pszFormat: "%d",
    Options.view2d.iDefaultGrid);
  DDX_CBString(
    pDX: (HWND__ *)v2,
    nIDC: (HWND__ *)0x3EF,
    value: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&pDX);
  if ( v2->m_bSaveAndValidate != 0 )
  {
    Options.view2d.iDefaultGrid = atoi(nptr: (const char *)pDX);
    Options.view2d.iGridIntensity = SendMessageA(hWnd: this->m_cGridIntensity.m_hWnd, Msg: 0x400u, wParam: 0, lParam: 0);
  }
  else
  {
    SendMessageA(hWnd: this->m_cGridIntensity.m_hWnd, Msg: 0x405u, wParam: 1u, lParam: Options.view2d.iGridIntensity);
  }
  v6 = pDX - 1;
  if ( _InterlockedDecrement(&pDX[-1].m_bEditLastControl) <= 0 )
    (*(void (__stdcall **)(CDataExchange *))(*(_DWORD *)v6->m_bSaveAndValidate + 4))(a1: v6);
}
