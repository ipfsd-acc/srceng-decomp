// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: hammer/torusdlg.cpp
// Functions: 13
// ============================================================

#include "hammer\torusdlg.h"

//------------------------------------------------------------------------------
// Address: 0x101027C0
// Name: public: virtual CTorusDlg::~CTorusDlg(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTorusDlg::~CTorusDlg(CTorusDlg *this)
{
  this->__vftable = (CTorusDlg_vtbl *)&CTorusDlg::`vftable';
  CStatic::~CStatic(this: &this->m_cTopViewPreview);
  CStatic::~CStatic(this: &this->m_cPreview);
  CEdit::~CEdit(this: &this->m_cArc);
  CSpinButtonCtrl::~CSpinButtonCtrl(this: &this->m_cArcSpin);
  CEdit::~CEdit(this: &this->m_cSides);
  CSpinButtonCtrl::~CSpinButtonCtrl(this: &this->m_cSidesSpin);
  CEdit::~CEdit(this: &this->m_cWallWidth);
  CSpinButtonCtrl::~CSpinButtonCtrl(this: &this->m_cWallWidthSpin);
  CSpinButtonCtrl::~CSpinButtonCtrl(this: &this->m_cStartAngleSpin);
  CDialog::~CDialog(this);
}

//------------------------------------------------------------------------------
// Address: 0x10102890
// Name: public: float CTorusDlg::GetTorusCrossSectionRadius(void)const
// Source: json
//------------------------------------------------------------------------------
double __thiscall CTorusDlg::GetTorusCrossSectionRadius(CTorusDlg *this)
{
  float m_fCrossSectionRadius; // xmm2_4
  float flTorusRadius; // [esp+0h] [ebp-4h]

  m_fCrossSectionRadius = this->m_fCrossSectionRadius;
  flTorusRadius = m_fCrossSectionRadius;
  if ( m_fCrossSectionRadius > (float)((float)(this->bmaxs.x - this->bmins.x) * 0.25) )
  {
    m_fCrossSectionRadius = (float)(this->bmaxs.x - this->bmins.x) * 0.25;
    flTorusRadius = m_fCrossSectionRadius;
  }
  if ( m_fCrossSectionRadius > (float)((float)(this->bmaxs.y - this->bmins.y) * 0.25) )
    return (float)((float)(this->bmaxs.y - this->bmins.y) * 0.25);
  return flTorusRadius;
}

//------------------------------------------------------------------------------
// Address: 0x10102920
// Name: protected: virtual void CTorusDlg::DoDataExchange(class CDataExchange __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTorusDlg::DoDataExchange(CTorusDlg *this, CDataExchange *pDX)
{
  float v4; // xmm0_4
  int *p_m_iAddHeight; // [esp+14h] [ebp+8h]

  DDX_Control(pDX, nIDC: (HWND__ *)0x543, rControl: (HWND__ *)&this->m_cStartAngleSpin);
  DDX_Control(pDX, nIDC: (HWND__ *)0x3F0, rControl: (HWND__ *)&this->m_cWallWidthSpin);
  DDX_Control(pDX, nIDC: (HWND__ *)0x53C, rControl: (HWND__ *)&this->m_cWallWidth);
  DDX_Control(pDX, nIDC: (HWND__ *)0x53D, rControl: (HWND__ *)&this->m_cSidesSpin);
  DDX_Control(pDX, nIDC: (HWND__ *)0x540, rControl: (HWND__ *)&this->m_cSides);
  DDX_Control(pDX, nIDC: (HWND__ *)0x53F, rControl: (HWND__ *)&this->m_cArcSpin);
  DDX_Control(pDX, nIDC: (HWND__ *)0x53E, rControl: (HWND__ *)&this->m_cArc);
  DDX_Control(pDX, nIDC: (HWND__ *)0x43A, rControl: (HWND__ *)&this->m_cPreview);
  DDX_Control(pDX, nIDC: (HWND__ *)0x634, rControl: (HWND__ *)&this->m_cTopViewPreview);
  DDX_Text(pDX, nIDC: (HWND__ *)0x540, value: &this->m_iSides);
  DDV_MinMaxInt(pDX, value: this->m_iSides, minVal: 3, maxVal: 2048);
  DDX_Text(pDX, nIDC: (HWND__ *)0x53C, value: &this->m_iWallWidth);
  p_m_iAddHeight = &this->m_iAddHeight;
  DDX_Text(pDX, nIDC: (HWND__ *)0x545, value: &this->m_iAddHeight);
  DDX_Text(pDX, nIDC: (HWND__ *)0x53E, value: (CDataExchange *)&this->m_fArc);
  DDV_MinMaxFloat(pDX, value: &this->m_fArc, minVal: 8.0, maxVal: 360.0);
  DDX_Text(pDX, nIDC: (HWND__ *)0x542, value: (CDataExchange *)&this->m_fAngle);
  DDV_MinMaxFloat(pDX, value: &this->m_fAngle, minVal: -360.0, maxVal: 360.0);
  DDX_Text(pDX, nIDC: (HWND__ *)0x546, value: (CDataExchange *)&this->m_fRotationArc);
  DDV_MinMaxFloat(pDX, value: &this->m_fRotationArc, minVal: 0.0, maxVal: 3600.0);
  DDX_Text(pDX, nIDC: (HWND__ *)0x633, value: (CDataExchange *)&this->m_fRotationAngle);
  DDV_MinMaxFloat(pDX, value: &this->m_fRotationAngle, minVal: -360.0, maxVal: 360.0);
  DDX_Text(pDX, nIDC: (HWND__ *)0x544, value: &this->m_iRotationSides);
  DDV_MinMaxInt(pDX, value: this->m_iRotationSides, minVal: 3, maxVal: 2048);
  DDX_Text(pDX, nIDC: (HWND__ *)0x547, value: (CDataExchange *)&this->m_fCrossSectionRadius);
  DDV_MinMaxFloat(pDX, value: &this->m_fCrossSectionRadius, minVal: 0.0, maxVal: 5000.0);
  if ( pDX->m_bSaveAndValidate != 0 )
  {
    v4 = this->bmaxs.z - this->bmins.z;
    if ( (float)*p_m_iAddHeight > v4 )
      *p_m_iAddHeight = (int)v4;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10102B80
// Name: protected: virtual int CTorusDlg::OnInitDialog(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CTorusDlg::OnInitDialog(CTorusDlg *this)
{
  CDialog::OnInitDialog(this);
  SendMessageA(hWnd: this->m_cArcSpin.m_hWnd, Msg: 0x465u, wParam: 0, lParam: 524648);
  SendMessageA(hWnd: this->m_cSidesSpin.m_hWnd, Msg: 0x465u, wParam: 0, lParam: 196708);
  SendMessageA(
    hWnd: this->m_cWallWidthSpin.m_hWnd,
    Msg: 0x465u,
    wParam: 0,
    lParam: LOWORD(this->m_iMaxWallWidth) | 0x20000);
  SendMessageA(hWnd: this->m_cStartAngleSpin.m_hWnd, Msg: 0x465u, wParam: 0, lParam: 360);
  CWnd::ShowWindow(this: &this->m_cPreview, nCmdShow: 0);
  CWnd::ShowWindow(this: &this->m_cTopViewPreview, nCmdShow: 0);
  this->bInitialized = 1;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10102C20
// Name: protected: void CTorusDlg::OnTorusPreview(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTorusDlg::OnTorusPreview(CTorusDlg *this)
{
  HWND__ *m_hWnd; // [esp-Ch] [ebp-10h]

  m_hWnd = this->m_hWnd;
  this->bInitialized = 1;
  InvalidateRect(hWnd: m_hWnd, lpRect: nullptr, bErase: true);
  UpdateWindow(hWnd: this->m_hWnd);
}

//------------------------------------------------------------------------------
// Address: 0x10102C50
// Name: protected: void CTorusDlg::OnCircle(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTorusDlg::OnCircle(CTorusDlg *this)
{
  HWND__ *m_hWnd; // [esp-Ch] [ebp-10h]

  SendMessageA(hWnd: this->m_cArcSpin.m_hWnd, Msg: 0x467u, wParam: 0, lParam: 360);
  m_hWnd = this->m_hWnd;
  this->bInitialized = 1;
  InvalidateRect(hWnd: m_hWnd, lpRect: nullptr, bErase: true);
  UpdateWindow(hWnd: this->m_hWnd);
}

//------------------------------------------------------------------------------
// Address: 0x10102C90
// Name: protected: void CTorusDlg::OnComputeRadius(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTorusDlg::OnComputeRadius(CTorusDlg *this)
{
  int m_iAddHeight; // ecx
  float m_fRotationArc; // xmm4_4
  float v4; // xmm0_4
  float m_iWallWidth; // xmm0_4
  HWND__ *m_hWnd; // [esp-Ch] [ebp-10h]

  CWnd::UpdateData(this, bSaveAndValidate: 1);
  m_iAddHeight = this->m_iAddHeight;
  m_fRotationArc = this->m_fRotationArc;
  v4 = (float)(this->bmaxs.z - this->bmins.z) - (float)m_iAddHeight;
  if ( (m_fRotationArc > 360.0 || m_fRotationArc == 360.0 && m_iAddHeight != 0)
    && v4 > (float)((float)((float)m_iAddHeight * 360.0) / m_fRotationArc) )
  {
    v4 = (float)((float)m_iAddHeight * 360.0) / m_fRotationArc;
  }
  if ( v4 > (float)((float)(this->bmaxs.x - this->bmins.x) * 0.5) )
    v4 = (float)(this->bmaxs.x - this->bmins.x) * 0.5;
  if ( v4 > (float)((float)(this->bmaxs.y - this->bmins.y) * 0.5) )
    v4 = (float)(this->bmaxs.y - this->bmins.y) * 0.5;
  m_iWallWidth = v4 * 0.5;
  if ( (float)this->m_iWallWidth > m_iWallWidth )
    m_iWallWidth = (float)this->m_iWallWidth;
  this->m_fCrossSectionRadius = m_iWallWidth;
  CWnd::UpdateData(this, bSaveAndValidate: 0);
  m_hWnd = this->m_hWnd;
  this->bInitialized = 1;
  InvalidateRect(hWnd: m_hWnd, lpRect: nullptr, bErase: true);
  UpdateWindow(hWnd: this->m_hWnd);
}

//------------------------------------------------------------------------------
// Address: 0x10102D80
// Name: public: void CTorusDlg::SaveValues(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTorusDlg::SaveValues(CTorusDlg *this)
{
  CAfxStringMgr *StringManager; // eax
  AFX_MODULE_STATE *ModuleState; // eax
  AFX_MODULE_STATE *v4; // eax
  AFX_MODULE_STATE *v5; // eax
  AFX_MODULE_STATE *v6; // eax
  AFX_MODULE_STATE *v7; // eax
  AFX_MODULE_STATE *v8; // eax
  char *m_pszData; // edi
  AFX_MODULE_STATE *v10; // eax
  AFX_MODULE_STATE *v11; // eax
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > v12; // [esp+10h] [ebp-10h] BYREF
  int v13; // [esp+1Ch] [ebp-4h]

  StringManager = AfxGetStringManager();
  if ( StringManager == nullptr )
    ATL::AtlThrowImpl(hr: -2147467259);
  v12.m_pszData = (char *)&StringManager->GetNilString(this: StringManager)[1];
  v13 = 1;
  ModuleState = AfxGetModuleState();
  ModuleState->m_pCurrentWinApp->WriteProfileInt(
    this: ModuleState->m_pCurrentWinApp,
    a2: pszSection_1,
    a3: "Wall Width",
    a4: this->m_iWallWidth);
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::Format(this: &v12, pszFormat: "%f", this->m_fArc);
  v4 = AfxGetModuleState();
  v4->m_pCurrentWinApp->WriteProfileStringA(this: v4->m_pCurrentWinApp, a2: pszSection_1, a3: "Arc_", a4: v12.m_pszData);
  v5 = AfxGetModuleState();
  v5->m_pCurrentWinApp->WriteProfileInt(this: v5->m_pCurrentWinApp, a2: pszSection_1, a3: "Sides", a4: this->m_iSides);
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::Format(this: &v12, pszFormat: "%f", this->m_fAngle);
  v6 = AfxGetModuleState();
  v6->m_pCurrentWinApp->WriteProfileStringA(
    this: v6->m_pCurrentWinApp,
    a2: pszSection_1,
    a3: "Start Angle_",
    a4: v12.m_pszData);
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::Format(
    this: &v12,
    pszFormat: "%f",
    this->m_fRotationArc);
  v7 = AfxGetModuleState();
  v7->m_pCurrentWinApp->WriteProfileStringA(
    this: v7->m_pCurrentWinApp,
    a2: pszSection_1,
    a3: "Rotation Arc_",
    a4: v12.m_pszData);
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::Format(
    this: &v12,
    pszFormat: "%f",
    this->m_fRotationAngle);
  v8 = AfxGetModuleState();
  m_pszData = v12.m_pszData;
  v8->m_pCurrentWinApp->WriteProfileStringA(
    this: v8->m_pCurrentWinApp,
    a2: pszSection_1,
    a3: "Rotation Start Angle_",
    a4: v12.m_pszData);
  v10 = AfxGetModuleState();
  v10->m_pCurrentWinApp->WriteProfileInt(
    this: v10->m_pCurrentWinApp,
    a2: pszSection_1,
    a3: "Rotation Sides",
    a4: this->m_iRotationSides);
  v11 = AfxGetModuleState();
  v11->m_pCurrentWinApp->WriteProfileInt(
    this: v11->m_pCurrentWinApp,
    a2: pszSection_1,
    a3: "Add Height",
    a4: this->m_iAddHeight);
  v13 = -1;
  if ( _InterlockedDecrement((volatile signed __int32 *)m_pszData - 1) <= 0 )
    (*(void (__thiscall **)(_DWORD, char *))(**((_DWORD **)m_pszData - 4) + 4))(
      a1: *((_DWORD *)m_pszData - 4),
      a2: m_pszData - 16);
}

//------------------------------------------------------------------------------
// Address: 0x10102FD0
// Name: public: CTorusDlg::CTorusDlg(class Vector __near &,class Vector __near &,class CWnd __near *)
// Source: json
//------------------------------------------------------------------------------
CTorusDlg *__thiscall CTorusDlg::CTorusDlg(CTorusDlg *this, Vector *boxmins, Vector *boxmaxs, CWnd *pParent)
{
  Vector *v5; // eax
  double z; // st7
  Vector *v7; // eax
  CAfxStringMgr *StringManager; // eax
  AFX_MODULE_STATE *ModuleState; // eax
  AFX_MODULE_STATE *v10; // eax
  ATL::CStringData *v11; // eax
  char *p_z; // eax
  AFX_MODULE_STATE *v13; // eax
  AFX_MODULE_STATE *v14; // eax
  ATL::CStringData *v15; // eax
  char *v16; // eax
  AFX_MODULE_STATE *v17; // eax
  ATL::CStringData *v18; // eax
  char *v19; // eax
  AFX_MODULE_STATE *v20; // eax
  AFX_MODULE_STATE *v21; // eax
  ATL::CStringData *v22; // eax
  char *v23; // eax
  CWnd *v24; // edi
  AFX_MODULE_STATE *v25; // eax
  int v26; // eax
  float v27; // xmm0_4
  int m_iAddHeight; // ecx
  float m_fRotationArc; // xmm4_4
  float v30; // xmm0_4
  float m_iWallWidth; // xmm0_4

  CDialog::CDialog(this, nIDTemplate: 0x140u, pParentWnd: pParent);
  this->__vftable = (CTorusDlg_vtbl *)&CTorusDlg::`vftable';
  pParent = &this->m_cStartAngleSpin;
  CWnd::CWnd(this: &this->m_cStartAngleSpin);
  this->m_cStartAngleSpin.__vftable = (CSpinButtonCtrl_vtbl *)&CSpinButtonCtrl::`vftable';
  pParent = &this->m_cWallWidthSpin;
  CWnd::CWnd(this: &this->m_cWallWidthSpin);
  this->m_cWallWidthSpin.__vftable = (CSpinButtonCtrl_vtbl *)&CSpinButtonCtrl::`vftable';
  pParent = &this->m_cWallWidth;
  CWnd::CWnd(this: &this->m_cWallWidth);
  this->m_cWallWidth.__vftable = (CEdit_vtbl *)&CEdit::`vftable';
  pParent = &this->m_cSidesSpin;
  CWnd::CWnd(this: &this->m_cSidesSpin);
  this->m_cSidesSpin.__vftable = (CSpinButtonCtrl_vtbl *)&CSpinButtonCtrl::`vftable';
  pParent = &this->m_cSides;
  CWnd::CWnd(this: &this->m_cSides);
  this->m_cSides.__vftable = (CEdit_vtbl *)&CEdit::`vftable';
  pParent = &this->m_cArcSpin;
  CWnd::CWnd(this: &this->m_cArcSpin);
  this->m_cArcSpin.__vftable = (CSpinButtonCtrl_vtbl *)&CSpinButtonCtrl::`vftable';
  pParent = &this->m_cArc;
  CWnd::CWnd(this: &this->m_cArc);
  this->m_cArc.__vftable = (CEdit_vtbl *)&CEdit::`vftable';
  pParent = &this->m_cPreview;
  CWnd::CWnd(this: &this->m_cPreview);
  this->m_cPreview.__vftable = (CStatic_vtbl *)&CStatic::`vftable';
  pParent = &this->m_cTopViewPreview;
  CWnd::CWnd(this: &this->m_cTopViewPreview);
  this->m_cTopViewPreview.__vftable = (CStatic_vtbl *)&CStatic::`vftable';
  v5 = boxmins;
  this->bmins.x = boxmins->x;
  this->bmins.y = v5->y;
  z = v5->z;
  v7 = boxmaxs;
  this->bmins.z = z;
  this->bmaxs = *v7;
  this->m_iSides = 0;
  this->m_iWallWidth = 0;
  this->m_iAddHeight = 0;
  this->m_fArc = 0.0;
  this->m_fAngle = 0.0;
  this->m_fRotationArc = 0.0;
  this->m_fRotationAngle = 0.0;
  this->m_iRotationSides = 0;
  this->m_fCrossSectionRadius = 0.0;
  StringManager = AfxGetStringManager();
  if ( StringManager == nullptr )
    ATL::AtlThrowImpl(hr: -2147467259);
  pParent = (CWnd *)&StringManager->GetNilString(this: StringManager)[1];
  ModuleState = AfxGetModuleState();
  this->m_iWallWidth = ModuleState->m_pCurrentWinApp->GetProfileIntA(
                         this: ModuleState->m_pCurrentWinApp,
                         a2: pszSection_1,
                         a3: "Wall Width",
                         a4: 32);
  v10 = AfxGetModuleState();
  v11 = (ATL::CStringData *)v10->m_pCurrentWinApp->GetProfileStringA(
                              this: v10->m_pCurrentWinApp,
                              result: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&boxmins,
                              a3: pszSection_1,
                              a4: "Arc_",
                              a5: "360");
  ATL::CSimpleStringT<char,0>::operator=(this: (ATL::CSimpleStringT<char,0> *)&pParent, strSrc: v11);
  p_z = (char *)&boxmins[-2].z;
  if ( _InterlockedDecrement((volatile signed __int32 *)&boxmins[-1].z) <= 0 )
    (*(void (__stdcall **)(char *))(**(_DWORD **)p_z + 4))(a1: p_z);
  this->m_fArc = atof(nptr: (const char *)pParent);
  v13 = AfxGetModuleState();
  this->m_iSides = v13->m_pCurrentWinApp->GetProfileIntA(
                     this: v13->m_pCurrentWinApp,
                     a2: pszSection_1,
                     a3: "Sides",
                     a4: 16);
  v14 = AfxGetModuleState();
  v15 = (ATL::CStringData *)v14->m_pCurrentWinApp->GetProfileStringA(
                              this: v14->m_pCurrentWinApp,
                              result: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&boxmins,
                              a3: pszSection_1,
                              a4: "Start Angle_",
                              a5: "0");
  ATL::CSimpleStringT<char,0>::operator=(this: (ATL::CSimpleStringT<char,0> *)&pParent, strSrc: v15);
  v16 = (char *)&boxmins[-2].z;
  if ( _InterlockedDecrement((volatile signed __int32 *)&boxmins[-1].z) <= 0 )
    (*(void (__stdcall **)(char *))(**(_DWORD **)v16 + 4))(a1: v16);
  this->m_fAngle = atof(nptr: (const char *)pParent);
  v17 = AfxGetModuleState();
  v18 = (ATL::CStringData *)v17->m_pCurrentWinApp->GetProfileStringA(
                              this: v17->m_pCurrentWinApp,
                              result: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&boxmins,
                              a3: pszSection_1,
                              a4: "Rotation Arc_",
                              a5: "360");
  ATL::CSimpleStringT<char,0>::operator=(this: (ATL::CSimpleStringT<char,0> *)&pParent, strSrc: v18);
  v19 = (char *)&boxmins[-2].z;
  if ( _InterlockedDecrement((volatile signed __int32 *)&boxmins[-1].z) <= 0 )
    (*(void (__stdcall **)(char *))(**(_DWORD **)v19 + 4))(a1: v19);
  this->m_fRotationArc = atof(nptr: (const char *)pParent);
  v20 = AfxGetModuleState();
  this->m_iRotationSides = v20->m_pCurrentWinApp->GetProfileIntA(
                             this: v20->m_pCurrentWinApp,
                             a2: pszSection_1,
                             a3: "Rotation Sides",
                             a4: 16);
  v21 = AfxGetModuleState();
  v22 = (ATL::CStringData *)v21->m_pCurrentWinApp->GetProfileStringA(
                              this: v21->m_pCurrentWinApp,
                              result: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&boxmins,
                              a3: pszSection_1,
                              a4: "Rotation Start Angle_",
                              a5: "0");
  ATL::CSimpleStringT<char,0>::operator=(this: (ATL::CSimpleStringT<char,0> *)&pParent, strSrc: v22);
  v23 = (char *)&boxmins[-2].z;
  if ( _InterlockedDecrement((volatile signed __int32 *)&boxmins[-1].z) <= 0 )
    (*(void (__stdcall **)(char *))(**(_DWORD **)v23 + 4))(a1: v23);
  v24 = pParent;
  this->m_fRotationAngle = atof(nptr: (const char *)pParent);
  v25 = AfxGetModuleState();
  v26 = v25->m_pCurrentWinApp->GetProfileIntA(this: v25->m_pCurrentWinApp, a2: pszSection_1, a3: "Add Height", a4: 0);
  this->m_iAddHeight = v26;
  v27 = this->bmaxs.z - this->bmins.z;
  if ( (float)v26 > v27 )
    this->m_iAddHeight = (int)v27;
  m_iAddHeight = this->m_iAddHeight;
  m_fRotationArc = this->m_fRotationArc;
  v30 = (float)(this->bmaxs.z - this->bmins.z) - (float)m_iAddHeight;
  if ( (m_fRotationArc > 360.0 || m_fRotationArc == 360.0 && m_iAddHeight != 0)
    && v30 > (float)((float)((float)m_iAddHeight * 360.0) / m_fRotationArc) )
  {
    v30 = (float)((float)m_iAddHeight * 360.0) / m_fRotationArc;
  }
  if ( v30 > (float)((float)(this->bmaxs.x - this->bmins.x) * 0.5) )
    v30 = (float)(this->bmaxs.x - this->bmins.x) * 0.5;
  if ( v30 > (float)((float)(this->bmaxs.y - this->bmins.y) * 0.5) )
    v30 = (float)(this->bmaxs.y - this->bmins.y) * 0.5;
  m_iWallWidth = v30 * 0.5;
  if ( (float)this->m_iWallWidth > m_iWallWidth )
    m_iWallWidth = (float)this->m_iWallWidth;
  this->m_fCrossSectionRadius = m_iWallWidth;
  if ( _InterlockedDecrement((volatile signed __int32 *)&v24[-1].m_pMFCCtrlContainer) <= 0 )
    ((void (__thiscall *)(COleDropTarget *, COleDropTarget **))v24[-1].m_pDropTarget->dtr_CObject)(
      a1: v24[-1].m_pDropTarget,
      a2: &v24[-1].m_pDropTarget);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10103520
// Name: public: void CTorusDlg::DrawTorusCrossSection(class CDC __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTorusDlg::DrawTorusCrossSection(CTorusDlg *this, CDC *pDC)
{
  _EXCEPTION_REGISTRATION_RECORD *ExceptionList; // eax
  void *v3; // esp
  HPEN Pen; // eax
  CFont *v5; // eax
  HWND v6; // edx
  float v7; // xmm1_4
  float v8; // xmm0_4
  float v9; // xmm2_4
  int v10; // ebx
  __int64 v11; // rdi
  float v12; // xmm1_4
  float v13; // xmm2_4
  int v14; // eax
  float v15; // xmm1_4
  float v16; // xmm3_4
  float v17; // xmm0_4
  float v18; // xmm0_4
  float v19; // xmm1_4
  int v20; // eax
  float v21; // xmm0_4
  float v22; // xmm2_4
  float v23; // xmm3_4
  float v24; // xmm4_4
  float v25; // xmm5_4
  float v26; // xmm1_4
  float v27; // xmm6_4
  float v28[8192]; // [esp+2Ch] [ebp-10078h] BYREF
  float v29[8192]; // [esp+802Ch] [ebp-8078h] BYREF
  CPoint v30; // [esp+1002Ch] [ebp-78h] BYREF
  float v31; // [esp+10034h] [ebp-70h]
  float v32; // [esp+10038h] [ebp-6Ch]
  float v33; // [esp+10040h] [ebp-64h]
  float v34; // [esp+10044h] [ebp-60h]
  float v35; // [esp+1004Ch] [ebp-58h]
  float v36; // [esp+10050h] [ebp-54h]
  float v37; // [esp+10058h] [ebp-4Ch]
  float v38; // [esp+1005Ch] [ebp-48h]
  CFont *v39; // [esp+10064h] [ebp-40h]
  int v40; // [esp+10068h] [ebp-3Ch]
  tagRECT v41; // [esp+1006Ch] [ebp-38h] BYREF
  float v42; // [esp+1007Ch] [ebp-28h]
  float v43; // [esp+10080h] [ebp-24h]
  CGdiObject v44; // [esp+10084h] [ebp-20h] BYREF
  int v45; // [esp+1008Ch] [ebp-18h]
  int y; // [esp+10090h] [ebp-14h]
  int v47; // [esp+10094h] [ebp-10h]
  _EXCEPTION_REGISTRATION_RECORD *v48; // [esp+10098h] [ebp-Ch]
  void *v49; // [esp+1009Ch] [ebp-8h]
  int v50; // [esp+100A0h] [ebp-4h]

  v50 = -1;
  ExceptionList = NtCurrentTeb()->NtTib.ExceptionList;
  v49 = &_ehhandler__DrawTorusCrossSection_CTorusDlg__QAEXPAVCDC___Z;
  v48 = ExceptionList;
  v3 = alloca(65644);
  HIDWORD(v11) = this;
  CWnd::UpdateData(this, bSaveAndValidate: 1);
  v44.m_hObject = nullptr;
  v44.__vftable = (CGdiObject_vtbl *)&CPen::`vftable';
  v50 = 1;
  Pen = CreatePen(iStyle: 0, cWidth: 1, color: 0xFFFFFFu);
  CGdiObject::Attach(this: &v44, hObject: Pen);
  v5 = CDC::SelectObject(this: pDC, pFont: (CFont *)&v44);
  v6 = *(HWND *)(HIDWORD(v11) + 66556);
  v39 = v5;
  memset(&v41, 0, sizeof(v41));
  GetWindowRect(hWnd: v6, lpRect: &v41);
  CWnd::ScreenToClient(this: (CWnd *)HIDWORD(v11), lpRect: (tagPOINT *)&v41);
  v7 = *(float *)(HIDWORD(v11) + 65700) - *(float *)(HIDWORD(v11) + 65688);
  v8 = *(float *)(HIDWORD(v11) + 66788);
  v9 = *(float *)(HIDWORD(v11) + 65704) - *(float *)(HIDWORD(v11) + 65692);
  v45 = v41.bottom - v41.top;
  v10 = v41.left + (v41.right - v41.left) / 2;
  LODWORD(v11) = v41.top + (v41.bottom - v41.top) / 2;
  v12 = v7 * 0.25;
  if ( v8 > v12 )
    v8 = v12;
  v13 = v9 * 0.25;
  if ( v8 > v13 )
    v8 = v13;
  v14 = *(_DWORD *)(HIDWORD(v11) + 66760);
  if ( (float)v14 > v8 )
    v14 = (int)v8;
  v15 = *(float *)(HIDWORD(v11) + 65708) - *(float *)(HIDWORD(v11) + 65696);
  v16 = v8 - (float)v14;
  *(float *)&v47 = v16;
  if ( v15 == 0.0 )
  {
    v43 = 1.0;
    v42 = 1.0;
  }
  else
  {
    v17 = v8 * 2.0;
    if ( v17 > v15 )
      v15 = v17;
    v42 = (float)(v41.right - v41.left) * (float)(1.0 / v15);
    v43 = (float)v45 * (float)(1.0 / v15);
  }
  v18 = *(float *)(HIDWORD(v11) + 66764);
  v19 = *(float *)(HIDWORD(v11) + 66768);
  HIDWORD(v11) = *(_DWORD *)(HIDWORD(v11) + 66756);
  *(float *)&v45 = v18;
  y = LODWORD(v19);
  v30.y = HIDWORD(v11);
  MakeArcCenterRadius(
    a1: v11,
    xCenter: 0.0,
    yCenter: 0.0,
    xrad: (float)v14 + v16,
    yrad: (float)v14 + v16,
    npoints: SHIDWORD(v11),
    start_ang: v19,
    fArc: v18,
    points: (float (*)[2])v29);
  MakeArcCenterRadius(
    a1: v11,
    xCenter: 0.0,
    yCenter: 0.0,
    xrad: *(float *)&v47,
    yrad: *(float *)&v47,
    npoints: SHIDWORD(v11),
    start_ang: *(float *)&y,
    fArc: *(float *)&v45,
    points: (float (*)[2])v28);
  if ( SHIDWORD(v11) > 0 )
  {
    v20 = 1;
    v40 = HIDWORD(v11) + 1;
    v47 = 1;
    HIDWORD(v11) = 0;
    y = v30.y;
    while ( 1 )
    {
      if ( v20 >= v40 )
        v20 = 0;
      v21 = *(float *)((char *)v29 + HIDWORD(v11));
      v22 = v29[2 * v20];
      v23 = v29[2 * v20 + 1];
      v24 = v28[2 * v20];
      v25 = v28[2 * v20 + 1];
      v26 = *(float *)((char *)&v29[1] + HIDWORD(v11));
      v27 = *(float *)((char *)v28 + HIDWORD(v11));
      v38 = *(float *)((char *)&v28[1] + HIDWORD(v11));
      v31 = v21 * v42;
      v32 = v26 * v43;
      v33 = v22 * v42;
      v34 = v23 * v43;
      v35 = v24 * v42;
      v36 = v25 * v43;
      v37 = v27 * v42;
      v38 = v38 * v43;
      CDC::MoveTo(this: pDC, result: &v30, x: v10 + (int)(float)(v22 * v42), y: v11 - (int)(float)(v23 * v43));
      CDC::LineTo(this: pDC, x: v10 + (int)v31, y: v11 - (int)v32);
      CDC::LineTo(this: pDC, x: v10 + (int)v37, y: v11 - (int)v38);
      CDC::LineTo(this: pDC, x: v10 + (int)v35, y: v11 - (int)v36);
      ++v47;
      HIDWORD(v11) += 8;
      if ( --y == 0 )
        break;
      v20 = v47;
    }
  }
  if ( *(float *)&v45 != 360.0 )
    CDC::LineTo(this: pDC, x: v10 + (int)v33, y: v11 - (int)v34);
  CDC::SelectObject(this: pDC, pFont: v39);
  v44.__vftable = (CGdiObject_vtbl *)&CPen::`vftable';
  v50 = -1;
  CGdiObject::~CGdiObject(this: &v44);
}

//------------------------------------------------------------------------------
// Address: 0x10103920
// Name: public: void CTorusDlg::DrawTorusTopView(class CDC __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTorusDlg::DrawTorusTopView(CTorusDlg *this, CDC *pDC)
{
  _EXCEPTION_REGISTRATION_RECORD *ExceptionList; // eax
  void *v3; // esp
  HPEN Pen; // eax
  CFont *v6; // eax
  HWND__ *m_hWnd; // edx
  float x; // xmm4_4
  float v9; // xmm0_4
  __int64 v10; // rdi
  float v11; // xmm0_4
  float y; // xmm6_4
  float v13; // xmm0_4
  float v14; // xmm1_4
  int m_iRotationSides; // eax
  float m_fRotationArc; // xmm7_4
  float v17; // xmm2_4
  float m_fCrossSectionRadius; // xmm0_4
  float v19; // xmm1_4
  float v20; // xmm2_4
  float v21; // xmm3_4
  int v22; // ecx
  int v23; // xmm4_4
  float v24; // xmm1_4
  float v25; // xmm2_4
  float v26; // xmm1_4
  int v27; // eax
  int v28; // ebx
  float v29; // xmm1_4
  float v30; // xmm3_4
  float v31; // xmm0_4
  float v32; // xmm2_4
  float v33; // xmm4_4
  float v34; // xmm5_4
  float v35; // xmm6_4
  float v36[8192]; // [esp+2Ch] [ebp-1008Ch] BYREF
  float v37[8192]; // [esp+802Ch] [ebp-808Ch] BYREF
  CPoint v38; // [esp+1002Ch] [ebp-8Ch] BYREF
  float v39; // [esp+10034h] [ebp-84h]
  float v40; // [esp+10038h] [ebp-80h]
  float v41; // [esp+10040h] [ebp-78h]
  float v42; // [esp+10044h] [ebp-74h]
  float v43; // [esp+1004Ch] [ebp-6Ch]
  float v44; // [esp+10050h] [ebp-68h]
  float v45; // [esp+10058h] [ebp-60h]
  float v46; // [esp+1005Ch] [ebp-5Ch]
  float v47; // [esp+10064h] [ebp-54h]
  float v48; // [esp+10068h] [ebp-50h]
  CFont *v49; // [esp+10070h] [ebp-48h]
  tagRECT v50; // [esp+10074h] [ebp-44h] BYREF
  float v51; // [esp+10084h] [ebp-34h]
  float v52; // [esp+10088h] [ebp-30h]
  CGdiObject v53; // [esp+1008Ch] [ebp-2Ch] BYREF
  float v54; // [esp+10094h] [ebp-24h]
  int v55; // [esp+10098h] [ebp-20h]
  float v56; // [esp+1009Ch] [ebp-1Ch]
  int v57; // [esp+100A0h] [ebp-18h]
  int v58; // [esp+100A4h] [ebp-14h]
  float m_fRotationAngle; // [esp+100A8h] [ebp-10h]
  _EXCEPTION_REGISTRATION_RECORD *v60; // [esp+100ACh] [ebp-Ch]
  void *v61; // [esp+100B0h] [ebp-8h]
  int v62; // [esp+100B4h] [ebp-4h]

  v62 = -1;
  ExceptionList = NtCurrentTeb()->NtTib.ExceptionList;
  v61 = &_ehhandler__DrawTorusTopView_CTorusDlg__QAEXPAVCDC___Z;
  v60 = ExceptionList;
  v3 = alloca(65664);
  CWnd::UpdateData(this, bSaveAndValidate: 1);
  v53.m_hObject = nullptr;
  v53.__vftable = (CGdiObject_vtbl *)&CPen::`vftable';
  v62 = 1;
  Pen = CreatePen(iStyle: 0, cWidth: 1, color: 0xFFFFFFu);
  CGdiObject::Attach(this: &v53, hObject: Pen);
  v6 = CDC::SelectObject(this: pDC, pFont: (CFont *)&v53);
  m_hWnd = this->m_cTopViewPreview.m_hWnd;
  v49 = v6;
  memset(&v50, 0, sizeof(v50));
  GetWindowRect(hWnd: m_hWnd, lpRect: &v50);
  CWnd::ScreenToClient(this, lpRect: (tagPOINT *)&v50);
  x = this->bmins.x;
  v9 = this->bmaxs.x;
  v57 = v50.bottom - v50.top;
  LODWORD(v10) = v50.left + (v50.right - v50.left) / 2;
  HIDWORD(v10) = v50.top + (v50.bottom - v50.top) / 2;
  v11 = v9 - x;
  if ( v11 == 0.0 )
    v54 = 1.0;
  else
    v54 = (float)(v50.right - v50.left) / v11;
  y = this->bmins.y;
  v13 = this->bmaxs.y - y;
  if ( v13 == 0.0 )
    v56 = 1.0;
  else
    v56 = (float)v57 / v13;
  v14 = this->bmaxs.x - this->bmins.x;
  m_iRotationSides = this->m_iRotationSides;
  m_fRotationArc = this->m_fRotationArc;
  v17 = this->bmaxs.y - this->bmins.y;
  m_fRotationAngle = this->m_fRotationAngle;
  m_fCrossSectionRadius = this->m_fCrossSectionRadius;
  v19 = v14 * 0.25;
  *(float *)&v57 = m_fRotationArc;
  v58 = m_iRotationSides;
  if ( m_fCrossSectionRadius > v19 )
    m_fCrossSectionRadius = v19;
  v20 = v17 * 0.25;
  if ( m_fCrossSectionRadius > v20 )
    m_fCrossSectionRadius = v20;
  v21 = (float)(this->bmaxs.x + x) * 0.5;
  v22 = (int)(float)(m_fCrossSectionRadius * 2.0);
  *(float *)&v23 = (float)(this->bmaxs.y + y) * 0.5;
  v24 = (float)(this->bmaxs.x - v21) - (float)v22;
  v25 = (float)(this->bmaxs.y - *(float *)&v23) - (float)v22;
  v55 = LODWORD(v21);
  v38.y = v23;
  v52 = v24;
  v51 = v25;
  if ( v24 < 0.0 )
  {
    v24 = 0.0;
    v52 = 0.0;
  }
  if ( v25 < 0.0 )
  {
    v25 = 0.0;
    v51 = 0.0;
  }
  MakeArcCenterRadius(
    a1: v10,
    xCenter: v21,
    yCenter: *(float *)&v23,
    xrad: (float)v22 + v24,
    yrad: (float)v22 + v25,
    npoints: m_iRotationSides,
    start_ang: m_fRotationAngle,
    fArc: m_fRotationArc,
    points: (float (*)[2])v37);
  MakeArcCenterRadius(
    a1: v10,
    xCenter: *(float *)&v55,
    yCenter: *(float *)&v38.y,
    xrad: v52,
    yrad: v51,
    npoints: v58,
    start_ang: m_fRotationAngle,
    fArc: *(float *)&v57,
    points: (float (*)[2])v36);
  v26 = this->bmins.y;
  v47 = (float)((float)(this->bmaxs.x - this->bmins.x) * 0.5) + this->bmins.x;
  v48 = (float)((float)(this->bmaxs.y - v26) * 0.5) + v26;
  if ( v58 > 0 )
  {
    v27 = 1;
    v55 = v58 + 1;
    LODWORD(m_fRotationAngle) = 1;
    v28 = 0;
    while ( 1 )
    {
      if ( v27 >= v55 )
        v27 = 0;
      v29 = v37[v28 + 1];
      v30 = v37[2 * v27 + 1];
      v31 = (float)(v37[v28] - v47) * v54;
      v32 = v37[2 * v27];
      v33 = v36[2 * v27];
      v34 = v36[2 * v27 + 1];
      v35 = v36[v28];
      v46 = v36[v28 + 1];
      v39 = v31;
      v40 = (float)(v29 - v48) * v56;
      v41 = (float)(v32 - v47) * v54;
      v42 = (float)(v30 - v48) * v56;
      v43 = (float)(v33 - v47) * v54;
      v44 = (float)(v34 - v48) * v56;
      v45 = (float)(v35 - v47) * v54;
      v46 = (float)(v46 - v48) * v56;
      CDC::MoveTo(this: pDC, result: &v38, x: v10 + (int)v41, y: HIDWORD(v10) - (int)v42);
      CDC::LineTo(this: pDC, x: v10 + (int)v39, y: HIDWORD(v10) - (int)v40);
      CDC::LineTo(this: pDC, x: v10 + (int)v45, y: HIDWORD(v10) - (int)v46);
      CDC::LineTo(this: pDC, x: v10 + (int)v43, y: HIDWORD(v10) - (int)v44);
      ++LODWORD(m_fRotationAngle);
      v28 += 2;
      if ( --v58 == 0 )
        break;
      v27 = LODWORD(m_fRotationAngle);
    }
  }
  if ( *(float *)&v57 != 360.0 )
    CDC::LineTo(this: pDC, x: v10 + (int)v41, y: HIDWORD(v10) - (int)v42);
  CDC::SelectObject(this: pDC, pFont: v49);
  v53.__vftable = (CGdiObject_vtbl *)&CPen::`vftable';
  v62 = -1;
  CGdiObject::~CGdiObject(this: &v53);
}

//------------------------------------------------------------------------------
// Address: 0x10103E20
// Name: protected: void CTorusDlg::OnPaint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTorusDlg::OnPaint(CTorusDlg *this)
{
  HWND__ *m_hWnd; // [esp-8h] [ebp-94h]
  CPaintDC dc; // [esp+Ch] [ebp-80h] BYREF
  CRect rcPreview; // [esp+60h] [ebp-2Ch] BYREF
  CBrush black; // [esp+70h] [ebp-1Ch] BYREF
  CBrush grey; // [esp+78h] [ebp-14h] BYREF
  int v7; // [esp+88h] [ebp-4h]

  CPaintDC::CPaintDC(this: &dc, pWnd: this);
  v7 = 0;
  CBrush::CBrush(this: &black, crColor: 0);
  LOBYTE(v7) = 1;
  CBrush::CBrush(this: &grey, crColor: 0x808080u);
  LOBYTE(v7) = 2;
  m_hWnd = this->m_cPreview.m_hWnd;
  memset(&rcPreview, 0, sizeof(rcPreview));
  GetWindowRect(hWnd: m_hWnd, lpRect: &rcPreview);
  CWnd::ScreenToClient(this, lpRect: (tagPOINT *)&rcPreview);
  FillRect(hDC: dc.m_hDC, lprc: &rcPreview, hbr: (HBRUSH)black.m_hObject);
  CTorusDlg::DrawTorusCrossSection(this, pDC: &dc);
  InflateRect(lprc: &rcPreview, dx: 1, dy: 1);
  FrameRect(hDC: dc.m_hDC, lprc: &rcPreview, hbr: (HBRUSH)grey.m_hObject);
  ValidateRect(hWnd: this->m_hWnd, lpRect: &rcPreview);
  GetWindowRect(hWnd: this->m_cTopViewPreview.m_hWnd, lpRect: &rcPreview);
  CWnd::ScreenToClient(this, lpRect: (tagPOINT *)&rcPreview);
  FillRect(hDC: dc.m_hDC, lprc: &rcPreview, hbr: (HBRUSH)black.m_hObject);
  CTorusDlg::DrawTorusTopView(this, pDC: &dc);
  InflateRect(lprc: &rcPreview, dx: 1, dy: 1);
  FrameRect(hDC: dc.m_hDC, lprc: &rcPreview, hbr: (HBRUSH)grey.m_hObject);
  ValidateRect(hWnd: this->m_hWnd, lpRect: &rcPreview);
  this->bInitialized = 1;
  grey.__vftable = (CBrush_vtbl *)&CBrush::`vftable';
  LOBYTE(v7) = 1;
  CGdiObject::~CGdiObject(this: &grey);
  black.__vftable = (CBrush_vtbl *)&CBrush::`vftable';
  LOBYTE(v7) = 0;
  CGdiObject::~CGdiObject(this: &black);
  v7 = -1;
  CPaintDC::~CPaintDC(this: &dc);
}

//------------------------------------------------------------------------------
// Address: 0x10103FA0
// Name: protected: virtual struct AFX_MSGMAP const __near * CTorusDlg::GetMessageMap(void)const
// Source: json
//------------------------------------------------------------------------------
const AFX_MSGMAP *__thiscall CTorusDlg::GetMessageMap(CTorusDlg *this)
{
  return (const AFX_MSGMAP *)&off_105F4634;
}
