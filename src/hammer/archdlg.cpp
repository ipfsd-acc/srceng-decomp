// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: hammer/archdlg.cpp
// Functions: 10
// ============================================================

#include "hammer\archdlg.h"

//------------------------------------------------------------------------------
// Address: 0x100BD530
// Name: public: virtual CArchDlg::~CArchDlg(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CArchDlg::~CArchDlg(CArchDlg *this)
{
  this->__vftable = (CArchDlg_vtbl *)&CArchDlg::`vftable';
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
// Address: 0x100BD620
// Name: protected: virtual void CArchDlg::DoDataExchange(class CDataExchange __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CArchDlg::DoDataExchange(CArchDlg *this, CDataExchange *pDX)
{
  CArchDlg *v2; // edi

  v2 = this;
  DDX_Control(pDX, nIDC: (HWND__ *)0x543, rControl: (HWND__ *)&this->m_cStartAngleSpin);
  DDX_Control(pDX, nIDC: (HWND__ *)0x3F0, rControl: (HWND__ *)&v2->m_cWallWidthSpin);
  DDX_Control(pDX, nIDC: (HWND__ *)0x53C, rControl: (HWND__ *)&v2->m_cWallWidth);
  DDX_Control(pDX, nIDC: (HWND__ *)0x53D, rControl: (HWND__ *)&v2->m_cSidesSpin);
  DDX_Control(pDX, nIDC: (HWND__ *)0x540, rControl: (HWND__ *)&v2->m_cSides);
  DDX_Control(pDX, nIDC: (HWND__ *)0x53F, rControl: (HWND__ *)&v2->m_cArcSpin);
  DDX_Control(pDX, nIDC: (HWND__ *)0x53E, rControl: (HWND__ *)&v2->m_cArc);
  DDX_Control(pDX, nIDC: (HWND__ *)0x43A, rControl: (HWND__ *)&v2->m_cPreview);
  DDX_Text(pDX, nIDC: (HWND__ *)0x53C, value: &v2->m_iWallWidth);
  DDX_Text(pDX, nIDC: (HWND__ *)0x540, value: &v2->m_iSides);
  DDV_MinMaxInt(pDX, value: v2->m_iSides, minVal: 3, maxVal: 2048);
  DDX_Text(pDX, nIDC: (HWND__ *)0x545, value: &v2->m_iAddHeight);
  DDX_Text(pDX, nIDC: 1342, value: &v2->m_fArc);
  DDV_MinMaxFloat(pDX, value: &v2->m_fArc, minVal: 8.0, maxVal: 360.0);
  v2 = (CArchDlg *)((char *)v2 + 66652);
  DDX_Text(pDX, nIDC: 1346, value: (float *)v2);
  DDV_MinMaxFloat(pDX, value: (const float *)v2, minVal: 0.0, maxVal: 360.0);
}

//------------------------------------------------------------------------------
// Address: 0x100BD780
// Name: protected: void CArchDlg::OnCircle(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CArchDlg::OnCircle(CArchDlg *this)
{
  SendMessageA(hWnd: this->m_cArcSpin.m_hWnd, Msg: 0x467u, wParam: 0, lParam: 360);
}

//------------------------------------------------------------------------------
// Address: 0x100BD7A0
// Name: protected: virtual int CArchDlg::OnInitDialog(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CArchDlg::OnInitDialog(CArchDlg *this)
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
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100BD830
// Name: protected: void CArchDlg::OnArchPreview(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CArchDlg::OnArchPreview(CArchDlg *this)
{
  CWnd::UpdateData(this, bSaveAndValidate: 1);
  InvalidateRect(hWnd: this->m_hWnd, lpRect: nullptr, bErase: true);
  UpdateWindow(hWnd: this->m_hWnd);
}

//------------------------------------------------------------------------------
// Address: 0x100BD860
// Name: public: void CArchDlg::SaveValues(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CArchDlg::SaveValues(CArchDlg *this)
{
  CAfxStringMgr *StringManager; // eax
  AFX_MODULE_STATE *ModuleState; // eax
  AFX_MODULE_STATE *v4; // eax
  AFX_MODULE_STATE *v5; // eax
  AFX_MODULE_STATE *v6; // eax
  char *m_pszData; // edi
  AFX_MODULE_STATE *v8; // eax
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > v9; // [esp+10h] [ebp-10h] BYREF
  int v10; // [esp+1Ch] [ebp-4h]

  StringManager = AfxGetStringManager();
  if ( StringManager == nullptr )
    ATL::AtlThrowImpl(hr: -2147467259);
  v9.m_pszData = (char *)&StringManager->GetNilString(this: StringManager)[1];
  v10 = 1;
  ModuleState = AfxGetModuleState();
  ModuleState->m_pCurrentWinApp->WriteProfileInt(
    this: ModuleState->m_pCurrentWinApp,
    a2: pszSection_0,
    a3: "Wall Width",
    a4: this->m_iWallWidth);
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::Format(this: &v9, pszFormat: "%f", this->m_fArc);
  v4 = AfxGetModuleState();
  v4->m_pCurrentWinApp->WriteProfileStringA(this: v4->m_pCurrentWinApp, a2: pszSection_0, a3: "Arc_", a4: v9.m_pszData);
  v5 = AfxGetModuleState();
  v5->m_pCurrentWinApp->WriteProfileInt(this: v5->m_pCurrentWinApp, a2: pszSection_0, a3: "Sides", a4: this->m_iSides);
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::Format(this: &v9, pszFormat: "%f", this->m_fAngle);
  v6 = AfxGetModuleState();
  m_pszData = v9.m_pszData;
  v6->m_pCurrentWinApp->WriteProfileStringA(
    this: v6->m_pCurrentWinApp,
    a2: pszSection_0,
    a3: "Start Angle_",
    a4: v9.m_pszData);
  v8 = AfxGetModuleState();
  v8->m_pCurrentWinApp->WriteProfileInt(
    this: v8->m_pCurrentWinApp,
    a2: pszSection_0,
    a3: "Add Height",
    a4: this->m_iAddHeight);
  v10 = -1;
  if ( _InterlockedDecrement((volatile signed __int32 *)m_pszData - 1) <= 0 )
    (*(void (__thiscall **)(_DWORD, char *))(**((_DWORD **)m_pszData - 4) + 4))(
      a1: *((_DWORD *)m_pszData - 4),
      a2: m_pszData - 16);
}

//------------------------------------------------------------------------------
// Address: 0x100BD9F0
// Name: public: CArchDlg::CArchDlg(class Vector __near &,class Vector __near &,class CWnd __near *)
// Source: json
//------------------------------------------------------------------------------
CArchDlg *__thiscall CArchDlg::CArchDlg(CArchDlg *this, Vector *boxmins, Vector *boxmaxs, CWnd *pParent)
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
  CWnd *v17; // edi
  AFX_MODULE_STATE *v18; // eax

  CDialog::CDialog(this, nIDTemplate: 0xF7u, pParentWnd: pParent);
  this->__vftable = (CArchDlg_vtbl *)&CArchDlg::`vftable';
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
  StringManager = AfxGetStringManager();
  if ( StringManager == nullptr )
    ATL::AtlThrowImpl(hr: -2147467259);
  pParent = (CWnd *)&StringManager->GetNilString(this: StringManager)[1];
  ModuleState = AfxGetModuleState();
  this->m_iWallWidth = ModuleState->m_pCurrentWinApp->GetProfileIntA(
                         this: ModuleState->m_pCurrentWinApp,
                         a2: pszSection_0,
                         a3: "Wall Width",
                         a4: 32);
  v10 = AfxGetModuleState();
  v11 = (ATL::CStringData *)v10->m_pCurrentWinApp->GetProfileStringA(
                              this: v10->m_pCurrentWinApp,
                              result: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&boxmins,
                              a3: pszSection_0,
                              a4: "Arc_",
                              a5: "180");
  ATL::CSimpleStringT<char,0>::operator=(this: (ATL::CSimpleStringT<char,0> *)&pParent, strSrc: v11);
  p_z = (char *)&boxmins[-2].z;
  if ( _InterlockedDecrement((volatile signed __int32 *)&boxmins[-1].z) <= 0 )
    (*(void (__stdcall **)(char *))(**(_DWORD **)p_z + 4))(a1: p_z);
  this->m_fArc = atof(nptr: (const char *)pParent);
  v13 = AfxGetModuleState();
  this->m_iSides = v13->m_pCurrentWinApp->GetProfileIntA(
                     this: v13->m_pCurrentWinApp,
                     a2: pszSection_0,
                     a3: "Sides",
                     a4: 8);
  v14 = AfxGetModuleState();
  v15 = (ATL::CStringData *)v14->m_pCurrentWinApp->GetProfileStringA(
                              this: v14->m_pCurrentWinApp,
                              result: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&boxmins,
                              a3: pszSection_0,
                              a4: "Start Angle_",
                              a5: "0");
  ATL::CSimpleStringT<char,0>::operator=(this: (ATL::CSimpleStringT<char,0> *)&pParent, strSrc: v15);
  v16 = (char *)&boxmins[-2].z;
  if ( _InterlockedDecrement((volatile signed __int32 *)&boxmins[-1].z) <= 0 )
    (*(void (__stdcall **)(char *))(**(_DWORD **)v16 + 4))(a1: v16);
  v17 = pParent;
  this->m_fAngle = atof(nptr: (const char *)pParent);
  v18 = AfxGetModuleState();
  this->m_iAddHeight = v18->m_pCurrentWinApp->GetProfileIntA(
                         this: v18->m_pCurrentWinApp,
                         a2: pszSection_0,
                         a3: "Add Height",
                         a4: 0);
  if ( _InterlockedDecrement((volatile signed __int32 *)&v17[-1].m_pMFCCtrlContainer) <= 0 )
    ((void (__thiscall *)(COleDropTarget *, COleDropTarget **))v17[-1].m_pDropTarget->dtr_CObject)(
      a1: v17[-1].m_pDropTarget,
      a2: &v17[-1].m_pDropTarget);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100BDD30
// Name: public: void CArchDlg::DrawArch(class CDC __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CArchDlg::DrawArch(CArchDlg *this, CDC *pDC)
{
  _EXCEPTION_REGISTRATION_RECORD *ExceptionList; // eax
  void *v3; // esp
  HPEN Pen; // eax
  CFont *v6; // eax
  HWND__ *m_hWnd; // edx
  float x; // xmm4_4
  float v9; // xmm5_4
  __int64 v10; // rdi
  float y; // xmm2_4
  float v12; // xmm3_4
  float m_fAngle; // xmm1_4
  int m_iSides; // eax
  int m_iWallWidth; // ecx
  float v16; // xmm3_4
  float v17; // xmm0_4
  float v18; // xmm1_4
  float v19; // xmm2_4
  int i; // eax
  int v21; // eax
  int v22; // ebx
  float v23; // xmm0_4
  float v24; // xmm1_4
  float v25; // xmm3_4
  float v26; // xmm4_4
  float v27; // xmm5_4
  float v28; // xmm2_4
  float v29; // xmm6_4
  float v30[8192]; // [esp+2Ch] [ebp-10080h] BYREF
  float v31[8192]; // [esp+802Ch] [ebp-8080h] BYREF
  CPoint v32; // [esp+1002Ch] [ebp-80h] BYREF
  float v33; // [esp+10034h] [ebp-78h]
  float v34; // [esp+10038h] [ebp-74h]
  float v35; // [esp+10040h] [ebp-6Ch]
  float v36; // [esp+10044h] [ebp-68h]
  float v37; // [esp+1004Ch] [ebp-60h]
  float v38; // [esp+10050h] [ebp-5Ch]
  float v39; // [esp+10058h] [ebp-54h]
  float v40; // [esp+1005Ch] [ebp-50h]
  float v41; // [esp+10064h] [ebp-48h]
  float v42; // [esp+10068h] [ebp-44h]
  CFont *v43; // [esp+10070h] [ebp-3Ch]
  tagRECT v44; // [esp+10074h] [ebp-38h] BYREF
  CGdiObject v45; // [esp+10084h] [ebp-28h] BYREF
  float v46; // [esp+1008Ch] [ebp-20h]
  int v47; // [esp+10090h] [ebp-1Ch]
  float v48; // [esp+10094h] [ebp-18h]
  int v49; // [esp+10098h] [ebp-14h]
  int v50; // [esp+1009Ch] [ebp-10h]
  _EXCEPTION_REGISTRATION_RECORD *v51; // [esp+100A0h] [ebp-Ch]
  void *v52; // [esp+100A4h] [ebp-8h]
  int v53; // [esp+100A8h] [ebp-4h]

  v53 = -1;
  ExceptionList = NtCurrentTeb()->NtTib.ExceptionList;
  v52 = &_ehhandler__DrawArch_CArchDlg__QAEXPAVCDC___Z;
  v51 = ExceptionList;
  v3 = alloca(65652);
  v45.m_hObject = nullptr;
  v45.__vftable = (CGdiObject_vtbl *)&CPen::`vftable';
  v53 = 1;
  Pen = CreatePen(iStyle: 0, cWidth: 1, color: 0xFFFFFFu);
  CGdiObject::Attach(this: &v45, hObject: Pen);
  v6 = CDC::SelectObject(this: pDC, pFont: (CFont *)&v45);
  m_hWnd = this->m_cPreview.m_hWnd;
  v43 = v6;
  memset(&v44, 0, sizeof(v44));
  GetWindowRect(hWnd: m_hWnd, lpRect: &v44);
  CWnd::ScreenToClient(this, lpRect: &v44);
  x = this->bmaxs.x;
  v9 = this->bmins.x;
  LODWORD(v48) = v44.bottom - v44.top;
  HIDWORD(v10) = v44.left + (v44.right - v44.left) / 2;
  LODWORD(v10) = v44.top + (v44.bottom - v44.top) / 2;
  if ( (float)(x - v9) == 0.0 )
    v46 = 1.0;
  else
    v46 = (float)(v44.right - v44.left) / (float)(x - v9);
  y = this->bmaxs.y;
  v12 = this->bmins.y;
  if ( (float)(y - v12) == 0.0 )
    v48 = 1.0;
  else
    v48 = (float)SLODWORD(v48) / (float)(y - v12);
  m_fAngle = this->m_fAngle;
  m_iSides = this->m_iSides;
  m_iWallWidth = this->m_iWallWidth;
  v32.y = LODWORD(this->m_fArc);
  v47 = LODWORD(m_fAngle);
  v49 = m_iSides;
  v50 = m_iWallWidth;
  MakeArc(
    a1: v10,
    x1: v9,
    y1: v12,
    x2: x,
    y2: y,
    npoints: m_iSides,
    start_ang: m_fAngle,
    fArc: *(float *)&v32.y,
    points: (float (*)[2])v30);
  MakeArc(
    a1: v10,
    x1: (float)v50 + this->bmins.x,
    y1: this->bmins.y + (float)v50,
    x2: this->bmaxs.x - (float)v50,
    y2: this->bmaxs.y - (float)v50,
    npoints: v49,
    start_ang: *(float *)&v47,
    fArc: *(float *)&v32.y,
    points: (float (*)[2])v31);
  v16 = this->bmaxs.x - this->bmins.x;
  v17 = (float)(this->bmaxs.x + this->bmins.x) * 0.5;
  v18 = (float)(this->bmins.y + this->bmaxs.y) * 0.5;
  v19 = (float)(2 * v50 + 8);
  v41 = v17;
  v42 = v18;
  if ( v19 >= v16 || v19 >= (float)(this->bmaxs.y - this->bmins.y) )
  {
    for ( i = 0; i < 4096; ++i )
    {
      v31[2 * i] = v17;
      v31[2 * i + 1] = v18;
    }
  }
  if ( v49 > 0 )
  {
    v21 = 1;
    v47 = v49 + 1;
    v50 = 1;
    v22 = 0;
    while ( 1 )
    {
      if ( v21 >= v47 )
        v21 = 0;
      v23 = (float)(v30[v22] - v41) * v46;
      v24 = v30[v22 + 1];
      v25 = v30[2 * v21 + 1];
      v26 = v31[2 * v21];
      v27 = v31[2 * v21 + 1];
      v28 = v30[2 * v21] - v41;
      v29 = v31[v22];
      v40 = v31[v22 + 1];
      v33 = v23;
      v34 = (float)(v24 - v42) * v48;
      v35 = v28 * v46;
      v36 = (float)(v25 - v42) * v48;
      v37 = (float)(v26 - v41) * v46;
      v38 = (float)(v27 - v42) * v48;
      v39 = (float)(v29 - v41) * v46;
      v40 = (float)(v40 - v42) * v48;
      CDC::MoveTo(this: pDC, result: &v32, x: HIDWORD(v10) + (int)v23, y: v10 - (int)v34);
      CDC::LineTo(this: pDC, x: HIDWORD(v10) + (int)v35, y: v10 - (int)v36);
      CDC::LineTo(this: pDC, x: HIDWORD(v10) + (int)v37, y: v10 - (int)v38);
      CDC::LineTo(this: pDC, x: HIDWORD(v10) + (int)v39, y: v10 - (int)v40);
      ++v50;
      v22 += 2;
      if ( --v49 == 0 )
        break;
      v21 = v50;
    }
  }
  CDC::SelectObject(this: pDC, pFont: v43);
  v45.__vftable = (CGdiObject_vtbl *)&CPen::`vftable';
  v53 = -1;
  CGdiObject::~CGdiObject(this: &v45);
}

//------------------------------------------------------------------------------
// Address: 0x100BE180
// Name: protected: void CArchDlg::OnPaint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CArchDlg::OnPaint(CArchDlg *this)
{
  HWND__ *m_hWnd; // [esp-8h] [ebp-90h]
  CPaintDC dc; // [esp+8h] [ebp-80h] BYREF
  CRect rcPreview; // [esp+5Ch] [ebp-2Ch] BYREF
  CBrush black; // [esp+6Ch] [ebp-1Ch] BYREF
  CBrush grey; // [esp+74h] [ebp-14h] BYREF
  int v7; // [esp+84h] [ebp-4h]

  CPaintDC::CPaintDC(this: &dc, pWnd: this);
  v7 = 0;
  CBrush::CBrush(this: &black, crColor: 0);
  LOBYTE(v7) = 1;
  CBrush::CBrush(this: &grey, crColor: 0x808080u);
  LOBYTE(v7) = 2;
  m_hWnd = this->m_cPreview.m_hWnd;
  memset(&rcPreview, 0, sizeof(rcPreview));
  GetWindowRect(hWnd: m_hWnd, lpRect: &rcPreview);
  CWnd::ScreenToClient(this, lpRect: &rcPreview);
  FillRect(hDC: dc.m_hDC, lprc: &rcPreview, hbr: (HBRUSH)black.m_hObject);
  CArchDlg::DrawArch(this, pDC: &dc);
  InflateRect(lprc: &rcPreview, dx: 1, dy: 1);
  FrameRect(hDC: dc.m_hDC, lprc: &rcPreview, hbr: (HBRUSH)grey.m_hObject);
  ValidateRect(hWnd: this->m_hWnd, lpRect: &rcPreview);
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
// Address: 0x100BE290
// Name: protected: virtual struct AFX_MSGMAP const __near * CArchDlg::GetMessageMap(void)const
// Source: json
//------------------------------------------------------------------------------
const AFX_MSGMAP *__thiscall CArchDlg::GetMessageMap(CArchDlg *this)
{
  return (const AFX_MSGMAP *)&off_105E89D0;
}
