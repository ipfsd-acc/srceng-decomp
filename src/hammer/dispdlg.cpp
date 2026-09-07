// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: hammer/dispdlg.cpp
// Functions: 77
// ============================================================

#include "hammer\dispdlg.h"

//------------------------------------------------------------------------------
// Address: 0x100BE710
// Name: public: virtual CDispPaintDistDlg::~CDispPaintDistDlg(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDispPaintDistDlg::~CDispPaintDistDlg(CDispPaintDistDlg *this)
{
  this->__vftable = (CDispPaintDistDlg_vtbl *)&CDispPaintDistDlg::`vftable';
  if ( this->m_comboboxBrush.m_hWnd != nullptr )
    CWnd::Detach(this: &this->m_comboboxBrush);
  CComboBox::~CComboBox(this: &this->m_comboboxAxis);
  CIconComboBox::~CIconComboBox(this: &this->m_comboboxBrush);
  CEdit::~CEdit(this: &this->m_editRadius);
  CEdit::~CEdit(this: &this->m_editDistance);
  CSliderCtrl::~CSliderCtrl(this: &this->m_sliderRadius);
  CSliderCtrl::~CSliderCtrl(this: &this->m_sliderDistance);
  CDialog::~CDialog(this);
}

//------------------------------------------------------------------------------
// Address: 0x100BE7D0
// Name: protected: void CDispPaintDistDlg::UpdateAxis(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDispPaintDistDlg::UpdateAxis(CDispPaintDistDlg *this, int nAxis)
{
  CToolDisplace *DisplacementTool; // eax

  DisplacementTool = GetDisplacementTool();
  if ( DisplacementTool != nullptr )
  {
    switch ( nAxis )
    {
      case 0:
        DisplacementTool->m_iPaintAxis = 0;
        DisplacementTool->m_vecPaintAxis.x = 1.0;
        DisplacementTool->m_vecPaintAxis.y = 0.0;
        DisplacementTool->m_vecPaintAxis.z = 0.0;
        break;
      case 1:
        DisplacementTool->m_iPaintAxis = 1;
        DisplacementTool->m_vecPaintAxis.x = 0.0;
        DisplacementTool->m_vecPaintAxis.y = 1.0;
        DisplacementTool->m_vecPaintAxis.z = 0.0;
        break;
      case 2:
        DisplacementTool->m_iPaintAxis = 2;
        goto LABEL_8;
      case 3:
        DisplacementTool->m_iPaintAxis = 3;
        DisplacementTool->m_vecPaintAxis.x = 0.0;
        DisplacementTool->m_vecPaintAxis.y = 0.0;
        DisplacementTool->m_vecPaintAxis.z = 0.0;
        break;
      case 4:
        DisplacementTool->m_iPaintAxis = 4;
LABEL_8:
        DisplacementTool->m_vecPaintAxis.x = 0.0;
        DisplacementTool->m_vecPaintAxis.y = 0.0;
        DisplacementTool->m_vecPaintAxis.z = 1.0;
        break;
      default:
        return;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100BE8D0
// Name: protected: void CDispPaintDistDlg::OnCheckAutoSew(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDispPaintDistDlg::OnCheckAutoSew(CDispPaintDistDlg *this)
{
  CToolDisplace *DisplacementTool; // eax

  DisplacementTool = GetDisplacementTool();
  if ( DisplacementTool != nullptr )
    DisplacementTool->m_bAutoSew = !DisplacementTool->m_bAutoSew;
}

//------------------------------------------------------------------------------
// Address: 0x100BE8F0
// Name: public: virtual CPaintSculptDlg::~CPaintSculptDlg(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPaintSculptDlg::~CPaintSculptDlg(CPaintSculptDlg *this)
{
  CSculptPushOptions *m_PushOptions; // ecx
  CSculptCarveOptions *m_CarveOptions; // ecx
  CSculptBlendOptions *m_BlendOptions; // ecx

  this->__vftable = (CPaintSculptDlg_vtbl *)&CPaintSculptDlg::`vftable';
  m_PushOptions = this->m_PushOptions;
  if ( m_PushOptions != nullptr )
    ((void (__thiscall *)(CSculptPushOptions *, int))m_PushOptions->dtr_CObject)(a1: m_PushOptions, a2: 1);
  m_CarveOptions = this->m_CarveOptions;
  if ( m_CarveOptions != nullptr )
    ((void (__thiscall *)(CSculptCarveOptions *, int))m_CarveOptions->dtr_CObject)(a1: m_CarveOptions, a2: 1);
  m_BlendOptions = this->m_BlendOptions;
  if ( m_BlendOptions != nullptr )
    ((void (__thiscall *)(CSculptBlendOptions *, int))m_BlendOptions->dtr_CObject)(a1: m_BlendOptions, a2: 1);
  CButton::~CButton(this: &this->m_BlendButton);
  CButton::~CButton(this: &this->m_ProjectButton);
  CButton::~CButton(this: &this->m_CarveButton);
  CButton::~CButton(this: &this->m_PushButton);
  CButton::~CButton(this: &this->m_AutoSew);
  CStatic::~CStatic(this: &this->m_SculptOptionsLoc);
  CDialog::~CDialog(this);
}

//------------------------------------------------------------------------------
// Address: 0x100BE9D0
// Name: public: virtual CDispPaintDataDlg::~CDispPaintDataDlg(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDispPaintDataDlg::~CDispPaintDataDlg(CDispPaintDataDlg *this)
{
  this->__vftable = (CDispPaintDataDlg_vtbl *)&CDispPaintDataDlg::`vftable';
  if ( this->m_comboboxBrush.m_hWnd != nullptr )
    CWnd::Detach(this: &this->m_comboboxBrush);
  CEdit::~CEdit(this: &this->m_editValue);
  CSliderCtrl::~CSliderCtrl(this: &this->m_sliderValue);
  CComboBox::~CComboBox(this: &this->m_comboboxType);
  CIconComboBox::~CIconComboBox(this: &this->m_comboboxBrush);
  CDialog::~CDialog(this);
}

//------------------------------------------------------------------------------
// Address: 0x100BEAA0
// Name: public: int CSliderCtrl::GetPos(void)const
// Source: json
//------------------------------------------------------------------------------
LRESULT __thiscall CSliderCtrl::GetPos(CSliderCtrl *this)
{
  return SendMessageA(hWnd: this->m_hWnd, Msg: 0x400u, wParam: 0, lParam: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100BEAC0
// Name: public: CDispCreateDlg::CDispCreateDlg(class CWnd __near *)
// Source: json
//------------------------------------------------------------------------------
CDispCreateDlg *__thiscall CDispCreateDlg::CDispCreateDlg(CDispCreateDlg *this, CWnd *pParent)
{
  CDialog::CDialog(this, nIDTemplate: 0x133u, pParentWnd: pParent);
  this->__vftable = (CDispCreateDlg_vtbl *)&CDispCreateDlg::`vftable';
  CWnd::CWnd(this: &this->m_editPower);
  this->m_editPower.__vftable = (CEdit_vtbl *)&CEdit::`vftable';
  CWnd::CWnd(this: &this->m_spinPower);
  this->m_spinPower.__vftable = (CSpinButtonCtrl_vtbl *)&CSpinButtonCtrl::`vftable';
  this->m_Power = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100BEB60
// Name: public: virtual CDispCreateDlg::~CDispCreateDlg(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDispCreateDlg::~CDispCreateDlg(CDispCreateDlg *this)
{
  CSpinButtonCtrl::~CSpinButtonCtrl(this: &this->m_spinPower);
  CEdit::~CEdit(this: &this->m_editPower);
  CDialog::~CDialog(this);
}

//------------------------------------------------------------------------------
// Address: 0x100BEC30
// Name: public: virtual int CDispCreateDlg::OnInitDialog(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDispCreateDlg::OnInitDialog(CDispCreateDlg *this)
{
  void *p_m_editPower; // eax
  HWND__ *v3; // eax

  CDialog::OnInitDialog(this);
  CWnd::SetDlgItemInt(this, nID: 1009, nValue: 3u, bSigned: 1);
  p_m_editPower = &this->m_editPower;
  if ( this != (CDispCreateDlg *)-152 )
    p_m_editPower = this->m_editPower.m_hWnd;
  v3 = (HWND__ *)SendMessageA(hWnd: this->m_spinPower.m_hWnd, Msg: 0x469u, wParam: (WPARAM)p_m_editPower, lParam: 0);
  CWnd::FromHandle(hWnd: v3);
  SendMessageA(hWnd: this->m_spinPower.m_hWnd, Msg: 0x465u, wParam: 0, lParam: 131076);
  SendMessageA(hWnd: this->m_spinPower.m_hWnd, Msg: 0x467u, wParam: 0, lParam: 3);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100BECB0
// Name: public: virtual void CDispCreateDlg::DoDataExchange(class CDataExchange __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDispCreateDlg::DoDataExchange(CDispCreateDlg *this, CDataExchange *pDX)
{
  unsigned int *p_m_Power; // esi

  DDX_Control(pDX, nIDC: (HWND__ *)0x3F0, rControl: (HWND__ *)&this->m_spinPower);
  DDX_Control(pDX, nIDC: (HWND__ *)0x3F1, rControl: (HWND__ *)&this->m_editPower);
  p_m_Power = &this->m_Power;
  DDX_Text(pDX, nIDC: (HWND__ *)0x3F1, value: p_m_Power);
  if ( *p_m_Power < 2 )
    *p_m_Power = 2;
  if ( *p_m_Power > 4 )
    *p_m_Power = 4;
}

//------------------------------------------------------------------------------
// Address: 0x100BED10
// Name: protected: void CDispCreateDlg::OnVScroll(unsigned int,unsigned int,class CScrollBar __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDispCreateDlg::OnVScroll(
        CDispCreateDlg *this,
        unsigned int nSBCode,
        unsigned int nPos,
        CScrollBar *pScrollBar)
{
  SendMessageA(hWnd: this->m_spinPower.m_hWnd, Msg: 0x467u, wParam: 0, lParam: (unsigned __int16)nPos);
  CWnd::SetDlgItemInt(this, nID: 1009, nValue: nPos, bSigned: 1);
}

//------------------------------------------------------------------------------
// Address: 0x100BED50
// Name: public: CDispNoiseDlg::CDispNoiseDlg(class CWnd __near *)
// Source: json
//------------------------------------------------------------------------------
CDispNoiseDlg *__thiscall CDispNoiseDlg::CDispNoiseDlg(CDispNoiseDlg *this, CWnd *pParent)
{
  CDialog::CDialog(this, nIDTemplate: 0x134u, pParentWnd: pParent);
  this->__vftable = (CDispNoiseDlg_vtbl *)&CDispNoiseDlg::`vftable';
  CWnd::CWnd(this: &this->m_editMin);
  this->m_editMin.__vftable = (CEdit_vtbl *)&CEdit::`vftable';
  CWnd::CWnd(this: &this->m_editMax);
  this->m_editMax.__vftable = (CEdit_vtbl *)&CEdit::`vftable';
  CWnd::CWnd(this: &this->m_spinMin);
  this->m_spinMin.__vftable = (CSpinButtonCtrl_vtbl *)&CSpinButtonCtrl::`vftable';
  CWnd::CWnd(this: &this->m_spinMax);
  this->m_spinMax.__vftable = (CSpinButtonCtrl_vtbl *)&CSpinButtonCtrl::`vftable';
  *(_QWORD *)&this->m_Min = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100BEE40
// Name: public: virtual CDispNoiseDlg::~CDispNoiseDlg(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDispNoiseDlg::~CDispNoiseDlg(CDispNoiseDlg *this)
{
  CSpinButtonCtrl::~CSpinButtonCtrl(this: &this->m_spinMax);
  CSpinButtonCtrl::~CSpinButtonCtrl(this: &this->m_spinMin);
  CEdit::~CEdit(this: &this->m_editMax);
  CEdit::~CEdit(this: &this->m_editMin);
  CDialog::~CDialog(this);
}

//------------------------------------------------------------------------------
// Address: 0x100BEF50
// Name: public: virtual void CDispNoiseDlg::DoDataExchange(class CDataExchange __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDispNoiseDlg::DoDataExchange(CDispNoiseDlg *this, CDataExchange *pDX)
{
  DDX_Control(pDX, nIDC: (HWND__ *)0x3F0, rControl: (HWND__ *)&this->m_spinMin);
  DDX_Control(pDX, nIDC: (HWND__ *)0x602, rControl: (HWND__ *)&this->m_spinMax);
  DDX_Control(pDX, nIDC: (HWND__ *)0x3F1, rControl: (HWND__ *)&this->m_editMin);
  DDX_Control(pDX, nIDC: (HWND__ *)0x603, rControl: (HWND__ *)&this->m_editMax);
  DDX_Text(pDX, nIDC: 1009, value: &this->m_Min);
  DDX_Text(pDX, nIDC: 1539, value: &this->m_Max);
}

//------------------------------------------------------------------------------
// Address: 0x100BEFD0
// Name: public: CDispPaintDistDlg::CDispPaintDistDlg(class CWnd __near *)
// Source: json
//------------------------------------------------------------------------------
CDispPaintDistDlg *__thiscall CDispPaintDistDlg::CDispPaintDistDlg(CDispPaintDistDlg *this, CWnd *pParent)
{
  CDialog::CDialog(this, nIDTemplate: 0x135u, pParentWnd: pParent);
  this->__vftable = (CDispPaintDistDlg_vtbl *)&CDispPaintDistDlg::`vftable';
  CWnd::CWnd(this: &this->m_sliderDistance);
  this->m_sliderDistance.__vftable = (CSliderCtrl_vtbl *)&CSliderCtrl::`vftable';
  CWnd::CWnd(this: &this->m_sliderRadius);
  this->m_sliderRadius.__vftable = (CSliderCtrl_vtbl *)&CSliderCtrl::`vftable';
  CWnd::CWnd(this: &this->m_editDistance);
  this->m_editDistance.__vftable = (CEdit_vtbl *)&CEdit::`vftable';
  CWnd::CWnd(this: &this->m_editRadius);
  this->m_editRadius.__vftable = (CEdit_vtbl *)&CEdit::`vftable';
  CIconComboBox::CIconComboBox(this: &this->m_comboboxBrush);
  CWnd::CWnd(this: &this->m_comboboxAxis);
  this->m_comboboxAxis.__vftable = (CComboBox_vtbl *)&CComboBox::`vftable';
  this->m_DialogPosRect.left = 0;
  this->m_DialogPosRect.top = 0;
  this->m_DialogPosRect.right = 0;
  this->m_DialogPosRect.bottom = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100BF120
// Name: public: virtual void CDispPaintDistDlg::DoDataExchange(class CDataExchange __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDispPaintDistDlg::DoDataExchange(CDispPaintDistDlg *this, CDataExchange *pDX)
{
  DDX_Control(pDX, nIDC: (HWND__ *)0x608, rControl: (HWND__ *)&this->m_sliderDistance);
  DDX_Control(pDX, nIDC: (HWND__ *)0x60B, rControl: (HWND__ *)&this->m_sliderRadius);
  DDX_Control(pDX, nIDC: (HWND__ *)0x60E, rControl: (HWND__ *)&this->m_editDistance);
  DDX_Control(pDX, nIDC: (HWND__ *)0x5AA, rControl: (HWND__ *)&this->m_editRadius);
  DDX_Control(pDX, nIDC: (HWND__ *)0x609, rControl: (HWND__ *)&this->m_comboboxAxis);
}

//------------------------------------------------------------------------------
// Address: 0x100BF190
// Name: protected: void CDispPaintDistDlg::OnComboBoxBrushGeo(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDispPaintDistDlg::OnComboBoxBrushGeo(CDispPaintDistDlg *this)
{
  CToolDisplace *DisplacementTool; // esi
  LRESULT v3; // eax
  unsigned int m_uiEffect; // ecx
  unsigned int v5; // ecx
  CDispMapImageFilterManager *p_m_FilterSmoothMgr; // ecx

  DisplacementTool = GetDisplacementTool();
  if ( DisplacementTool != nullptr )
  {
    v3 = SendMessageA(hWnd: this->m_comboboxBrush.m_hWnd, Msg: 0x147u, wParam: 0, lParam: 0);
    if ( v3 != -1 )
    {
      m_uiEffect = DisplacementTool->m_uiEffect;
      if ( m_uiEffect != 0 )
      {
        v5 = m_uiEffect - 1;
        if ( v5 != 0 )
        {
          if ( v5 != 1 )
            return;
          p_m_FilterSmoothMgr = &DisplacementTool->m_FilterSmoothMgr;
        }
        else
        {
          p_m_FilterSmoothMgr = &DisplacementTool->m_FilterRaiseToMgr;
        }
      }
      else
      {
        p_m_FilterSmoothMgr = &DisplacementTool->m_FilterRaiseLowerMgr;
      }
      if ( p_m_FilterSmoothMgr != nullptr && v3 >= 0 && v3 < p_m_FilterSmoothMgr->m_FilterCount )
        p_m_FilterSmoothMgr->m_ActiveFilter = v3;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100BF1F0
// Name: protected: void CDispPaintDistDlg::OnComboBoxAxis(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDispPaintDistDlg::OnComboBoxAxis(CDispPaintDistDlg *this)
{
  LRESULT v2; // eax

  if ( GetDisplacementTool() != nullptr )
  {
    v2 = SendMessageA(hWnd: this->m_comboboxAxis.m_hWnd, Msg: 0x147u, wParam: 0, lParam: 0);
    if ( v2 != -1 )
      CDispPaintDistDlg::UpdateAxis(this, nAxis: v2);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100BF230
// Name: protected: void CDispPaintDistDlg::OnBrushTypeSoftEdge(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDispPaintDistDlg::OnBrushTypeSoftEdge(CDispPaintDistDlg *this)
{
  CToolDisplace *DisplacementTool; // eax
  CWnd *DlgItem; // eax
  CWnd *v4; // eax

  DisplacementTool = GetDisplacementTool();
  if ( DisplacementTool != nullptr )
  {
    DisplacementTool->m_uiBrushType = 0;
    DlgItem = CWnd::GetDlgItem(this, nID: 1584);
    SendMessageA(hWnd: DlgItem->m_hWnd, Msg: 0xF1u, wParam: 1u, lParam: 0);
    v4 = CWnd::GetDlgItem(this, nID: 1585);
    SendMessageA(hWnd: v4->m_hWnd, Msg: 0xF1u, wParam: 0, lParam: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100BF290
// Name: protected: void CDispPaintDistDlg::OnBrushTypeHardEdge(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDispPaintDistDlg::OnBrushTypeHardEdge(CDispPaintDistDlg *this)
{
  CToolDisplace *DisplacementTool; // eax
  CWnd *DlgItem; // eax
  CWnd *v4; // eax

  DisplacementTool = GetDisplacementTool();
  if ( DisplacementTool != nullptr )
  {
    DisplacementTool->m_uiBrushType = 1;
    DlgItem = CWnd::GetDlgItem(this, nID: 1584);
    SendMessageA(hWnd: DlgItem->m_hWnd, Msg: 0xF1u, wParam: 0, lParam: 0);
    v4 = CWnd::GetDlgItem(this, nID: 1585);
    SendMessageA(hWnd: v4->m_hWnd, Msg: 0xF1u, wParam: 1u, lParam: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100BF2F0
// Name: protected: void CDispPaintDistDlg::OnDestroy(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDispPaintDistDlg::OnDestroy(CDispPaintDistDlg *this)
{
  CToolDisplace *DisplacementTool; // eax

  GetWindowRect(hWnd: this->m_hWnd, lpRect: &this->m_DialogPosRect);
  DisplacementTool = GetDisplacementTool();
  if ( DisplacementTool != nullptr )
  {
    this->m_nPrevEffect = DisplacementTool->m_uiEffect;
    this->m_nPrevPaintAxis = DisplacementTool->m_iPaintAxis;
    this->m_vecPrevPaintAxis.x = DisplacementTool->m_vecPaintAxis.x;
    this->m_vecPrevPaintAxis.y = DisplacementTool->m_vecPaintAxis.y;
    this->m_vecPrevPaintAxis.z = DisplacementTool->m_vecPaintAxis.z;
    if ( DisplacementTool->m_bSpatial )
      DisplacementTool->m_bSpatial = false;
  }
  this->m_nPrevBrush = SendMessageA(hWnd: this->m_comboboxBrush.m_hWnd, Msg: 0x147u, wParam: 0, lParam: 0);
  CWnd::Detach(this: &this->m_comboboxBrush);
}

//------------------------------------------------------------------------------
// Address: 0x100BF380
// Name: public: CPaintSculptDlg::CPaintSculptDlg(class CWnd __near *)
// Source: json
//------------------------------------------------------------------------------
CPaintSculptDlg *__thiscall CPaintSculptDlg::CPaintSculptDlg(CPaintSculptDlg *this, CWnd *pParent)
{
  CSculptPushOptions *v3; // eax
  CSculptPushOptions *v4; // eax
  CSculptCarveOptions *v5; // eax
  CSculptCarveOptions *v6; // eax
  CSculptBlendOptions *v7; // eax
  CSculptBlendOptions *v8; // eax

  CDialog::CDialog(this, nIDTemplate: 0x15Fu, pParentWnd: pParent);
  this->__vftable = (CPaintSculptDlg_vtbl *)&CPaintSculptDlg::`vftable';
  this->m_DialogPosRect.left = 0;
  this->m_DialogPosRect.top = 0;
  this->m_DialogPosRect.right = 0;
  this->m_DialogPosRect.bottom = 0;
  CWnd::CWnd(this: &this->m_SculptOptionsLoc);
  this->m_SculptOptionsLoc.__vftable = (CStatic_vtbl *)&CStatic::`vftable';
  CWnd::CWnd(this: &this->m_AutoSew);
  this->m_AutoSew.__vftable = (CButton_vtbl *)&CButton::`vftable';
  CWnd::CWnd(this: &this->m_PushButton);
  this->m_PushButton.__vftable = (CButton_vtbl *)&CButton::`vftable';
  CWnd::CWnd(this: &this->m_CarveButton);
  this->m_CarveButton.__vftable = (CButton_vtbl *)&CButton::`vftable';
  CWnd::CWnd(this: &this->m_ProjectButton);
  this->m_ProjectButton.__vftable = (CButton_vtbl *)&CButton::`vftable';
  CWnd::CWnd(this: &this->m_BlendButton);
  this->m_BlendButton.__vftable = (CButton_vtbl *)&CButton::`vftable';
  this->m_bAutoSew = true;
  this->m_SculptMode = SCULPT_MODE_PUSH;
  v3 = (CSculptPushOptions *)operator new(nSize: 0x528u);
  if ( v3 != nullptr )
    v4 = CSculptPushOptions::CSculptPushOptions(this: v3, pParent: nullptr);
  else
    v4 = nullptr;
  this->m_PushOptions = v4;
  v5 = (CSculptCarveOptions *)operator new(nSize: 0x68Cu);
  if ( v5 != nullptr )
    v6 = CSculptCarveOptions::CSculptCarveOptions(this: v5, pParent: nullptr);
  else
    v6 = nullptr;
  this->m_CarveOptions = v6;
  v7 = (CSculptBlendOptions *)operator new(nSize: 0xC98u);
  if ( v7 != nullptr )
    v8 = CSculptBlendOptions::CSculptBlendOptions(this: v7, pParent: nullptr);
  else
    v8 = nullptr;
  this->m_BlendOptions = v8;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100BF570
// Name: public: virtual void CPaintSculptDlg::DoDataExchange(class CDataExchange __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPaintSculptDlg::DoDataExchange(CPaintSculptDlg *this, CDataExchange *pDX)
{
  DDX_Control(pDX, nIDC: (HWND__ *)0x69F, rControl: (HWND__ *)&this->m_SculptOptionsLoc);
  DDX_Control(pDX, nIDC: (HWND__ *)0x607, rControl: (HWND__ *)&this->m_AutoSew);
  DDX_Control(pDX, nIDC: (HWND__ *)0x670, rControl: (HWND__ *)&this->m_PushButton);
  DDX_Control(pDX, nIDC: (HWND__ *)0x671, rControl: (HWND__ *)&this->m_CarveButton);
  DDX_Control(pDX, nIDC: (HWND__ *)0x6A0, rControl: (HWND__ *)&this->m_ProjectButton);
  DDX_Control(pDX, nIDC: (HWND__ *)0x672, rControl: (HWND__ *)&this->m_BlendButton);
}

//------------------------------------------------------------------------------
// Address: 0x100BF5F0
// Name: protected: void CPaintSculptDlg::OnCheckAutoSew(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPaintSculptDlg::OnCheckAutoSew(CPaintSculptDlg *this)
{
  this->m_bAutoSew = SendMessageA(hWnd: this->m_AutoSew.m_hWnd, Msg: 0xF0u, wParam: 0, lParam: 0) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x100BF620
// Name: protected: void CPaintSculptDlg::OnLButtonUp(unsigned int,class CPoint)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPaintSculptDlg::OnLButtonUp(CPaintSculptDlg *this, unsigned int nFlags, CPoint point)
{
  CToolDisplace *DisplacementTool; // eax
  void *v5; // eax

  DisplacementTool = GetDisplacementTool();
  if ( DisplacementTool != nullptr )
  {
    v5 = __RTDynamicCast(
           inptr: DisplacementTool->m_SculptTool,
           VfDelta: 0,
           SrcType: &CSculptTool `RTTI Type Descriptor',
           TargetType: &CSculptPainter `RTTI Type Descriptor',
           isReference: 0);
    if ( v5 != nullptr )
      (*(void (__thiscall **)(void *, unsigned int, int, int))(*(_DWORD *)v5 + 32))(
        a1: v5,
        a2: nFlags,
        a3: point.x,
        a4: point.y);
  }
  CWnd::Default(this);
}

//------------------------------------------------------------------------------
// Address: 0x100BF680
// Name: protected: void CPaintSculptDlg::OnLButtonDown(unsigned int,class CPoint)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPaintSculptDlg::OnLButtonDown(CPaintSculptDlg *this, unsigned int nFlags, CPoint point)
{
  CToolDisplace *DisplacementTool; // eax
  void *v5; // eax

  DisplacementTool = GetDisplacementTool();
  if ( DisplacementTool != nullptr )
  {
    v5 = __RTDynamicCast(
           inptr: DisplacementTool->m_SculptTool,
           VfDelta: 0,
           SrcType: &CSculptTool `RTTI Type Descriptor',
           TargetType: &CSculptPainter `RTTI Type Descriptor',
           isReference: 0);
    if ( v5 != nullptr )
      (*(void (__thiscall **)(void *, unsigned int, int, int))(*(_DWORD *)v5 + 36))(
        a1: v5,
        a2: nFlags,
        a3: point.x,
        a4: point.y);
  }
  CWnd::Default(this);
}

//------------------------------------------------------------------------------
// Address: 0x100BF6E0
// Name: protected: void CPaintSculptDlg::OnMouseMove(unsigned int,class CPoint)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPaintSculptDlg::OnMouseMove(CPaintSculptDlg *this, unsigned int nFlags, CPoint point)
{
  CToolDisplace *DisplacementTool; // eax
  void *v5; // eax

  DisplacementTool = GetDisplacementTool();
  if ( DisplacementTool != nullptr )
  {
    v5 = __RTDynamicCast(
           inptr: DisplacementTool->m_SculptTool,
           VfDelta: 0,
           SrcType: &CSculptTool `RTTI Type Descriptor',
           TargetType: &CSculptPainter `RTTI Type Descriptor',
           isReference: 0);
    if ( v5 != nullptr )
      (*(void (__thiscall **)(void *, unsigned int, int, int))(*(_DWORD *)v5 + 40))(
        a1: v5,
        a2: nFlags,
        a3: point.x,
        a4: point.y);
  }
  CWnd::Default(this);
}

//------------------------------------------------------------------------------
// Address: 0x100BF740
// Name: protected: void CPaintSculptDlg::OnDestroy(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPaintSculptDlg::OnDestroy(CPaintSculptDlg *this)
{
  CToolDisplace *DisplacementTool; // eax
  CToolDisplace *v2; // esi
  CWnd *v3; // eax

  GetWindowRect(hWnd: this->m_hWnd, lpRect: &this->m_DialogPosRect);
  DisplacementTool = GetDisplacementTool();
  v2 = DisplacementTool;
  if ( DisplacementTool != nullptr )
  {
    CToolDisplace::GetSelectedDisps(this: DisplacementTool);
    v3 = (CWnd *)__RTDynamicCast(
                   inptr: v2->m_SculptTool,
                   VfDelta: 0,
                   SrcType: &CSculptTool `RTTI Type Descriptor',
                   TargetType: &CDialog `RTTI Type Descriptor',
                   isReference: 0);
    if ( v3 != nullptr )
      CWnd::ShowWindow(this: v3, nCmdShow: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100BF790
// Name: protected: void CPaintSculptDlg::SetActiveMode(enum CPaintSculptDlg::SculptMode)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPaintSculptDlg::SetActiveMode(CPaintSculptDlg *this, CPaintSculptDlg::SculptMode NewMode)
{
  HWND__ *m_hWnd; // edx
  CToolDisplace *DisplacementTool; // eax
  CToolDisplace *v5; // edi
  CWnd *v6; // eax
  CPaintSculptDlg::SculptMode m_SculptMode; // eax
  __int32 v8; // eax
  CSculptBlendOptions *m_BlendOptions; // esi
  CSculptCarveOptions *m_CarveOptions; // esi
  CSculptPushOptions *m_PushOptions; // esi

  m_hWnd = this->m_PushButton.m_hWnd;
  this->m_SculptMode = NewMode;
  SendMessageA(hWnd: m_hWnd, Msg: 0xF1u, wParam: NewMode == SCULPT_MODE_PUSH, lParam: 0);
  SendMessageA(hWnd: this->m_CarveButton.m_hWnd, Msg: 0xF1u, wParam: this->m_SculptMode == SCULPT_MODE_CARVE, lParam: 0);
  SendMessageA(
    hWnd: this->m_ProjectButton.m_hWnd,
    Msg: 0xF1u,
    wParam: this->m_SculptMode == SCULPT_MODE_PROJECT,
    lParam: 0);
  SendMessageA(hWnd: this->m_BlendButton.m_hWnd, Msg: 0xF1u, wParam: this->m_SculptMode == SCULPT_MODE_BLEND, lParam: 0);
  DisplacementTool = GetDisplacementTool();
  v5 = DisplacementTool;
  if ( DisplacementTool != nullptr )
  {
    CToolDisplace::GetSelectedDisps(this: DisplacementTool);
    v6 = (CWnd *)__RTDynamicCast(
                   inptr: v5->m_SculptTool,
                   VfDelta: 0,
                   SrcType: &CSculptTool `RTTI Type Descriptor',
                   TargetType: &CDialog `RTTI Type Descriptor',
                   isReference: 0);
    if ( v6 != nullptr )
      CWnd::ShowWindow(this: v6, nCmdShow: 0);
    m_SculptMode = this->m_SculptMode;
    if ( m_SculptMode != SCULPT_MODE_PUSH )
    {
      v8 = m_SculptMode - 1;
      if ( v8 != 0 )
      {
        if ( v8 != 2 )
          return;
        CWnd::ShowWindow(this: this->m_BlendOptions, nCmdShow: 5);
        m_BlendOptions = this->m_BlendOptions;
        if ( m_BlendOptions != nullptr )
        {
          v5->m_SculptTool = &m_BlendOptions->CSculptPainter;
          return;
        }
      }
      else
      {
        CWnd::ShowWindow(this: this->m_CarveOptions, nCmdShow: 5);
        m_CarveOptions = this->m_CarveOptions;
        if ( m_CarveOptions != nullptr )
        {
          v5->m_SculptTool = &m_CarveOptions->CSculptPainter;
          return;
        }
      }
    }
    else
    {
      CWnd::ShowWindow(this: this->m_PushOptions, nCmdShow: 5);
      m_PushOptions = this->m_PushOptions;
      if ( m_PushOptions != nullptr )
      {
        v5->m_SculptTool = &m_PushOptions->CSculptPainter;
        return;
      }
    }
    v5->m_SculptTool = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100BF900
// Name: public: CDispPaintDataDlg::CDispPaintDataDlg(class CWnd __near *)
// Source: json
//------------------------------------------------------------------------------
CDispPaintDataDlg *__thiscall CDispPaintDataDlg::CDispPaintDataDlg(CDispPaintDataDlg *this, CWnd *pParent)
{
  CDialog::CDialog(this, nIDTemplate: 0x136u, pParentWnd: pParent);
  this->__vftable = (CDispPaintDataDlg_vtbl *)&CDispPaintDataDlg::`vftable';
  CIconComboBox::CIconComboBox(this: &this->m_comboboxBrush);
  CWnd::CWnd(this: &this->m_comboboxType);
  this->m_comboboxType.__vftable = (CComboBox_vtbl *)&CComboBox::`vftable';
  CWnd::CWnd(this: &this->m_sliderValue);
  this->m_sliderValue.__vftable = (CSliderCtrl_vtbl *)&CSliderCtrl::`vftable';
  CWnd::CWnd(this: &this->m_editValue);
  this->m_editValue.__vftable = (CEdit_vtbl *)&CEdit::`vftable';
  this->m_DialogPosRect.left = 0;
  this->m_DialogPosRect.top = 0;
  this->m_DialogPosRect.right = 0;
  this->m_DialogPosRect.bottom = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100BFA10
// Name: public: virtual void CDispPaintDataDlg::DoDataExchange(class CDataExchange __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDispPaintDataDlg::DoDataExchange(CDispPaintDataDlg *this, CDataExchange *pDX)
{
  DDX_Control(pDX, nIDC: (HWND__ *)0x61A, rControl: (HWND__ *)&this->m_sliderValue);
  DDX_Control(pDX, nIDC: (HWND__ *)0x3F1, rControl: (HWND__ *)&this->m_editValue);
  DDX_Control(pDX, nIDC: (HWND__ *)0x61C, rControl: (HWND__ *)&this->m_comboboxType);
}

//------------------------------------------------------------------------------
// Address: 0x100BFA60
// Name: protected: void CDispPaintDataDlg::OnComboBoxBrushData(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDispPaintDataDlg::OnComboBoxBrushData(CDispPaintDataDlg *this)
{
  CToolDisplace *DisplacementTool; // esi
  LRESULT v3; // eax
  unsigned int m_uiEffect; // ecx
  unsigned int v5; // ecx
  CDispMapImageFilterManager *p_m_FilterSmoothMgr; // ecx

  DisplacementTool = GetDisplacementTool();
  if ( DisplacementTool != nullptr )
  {
    v3 = SendMessageA(hWnd: this->m_comboboxBrush.m_hWnd, Msg: 0x147u, wParam: 0, lParam: 0);
    if ( v3 != -1 )
    {
      m_uiEffect = DisplacementTool->m_uiEffect;
      if ( m_uiEffect != 0 )
      {
        v5 = m_uiEffect - 1;
        if ( v5 != 0 )
        {
          if ( v5 != 1 )
            return;
          p_m_FilterSmoothMgr = &DisplacementTool->m_FilterSmoothMgr;
        }
        else
        {
          p_m_FilterSmoothMgr = &DisplacementTool->m_FilterRaiseToMgr;
        }
      }
      else
      {
        p_m_FilterSmoothMgr = &DisplacementTool->m_FilterRaiseLowerMgr;
      }
      if ( p_m_FilterSmoothMgr != nullptr && v3 >= 0 && v3 < p_m_FilterSmoothMgr->m_FilterCount )
        p_m_FilterSmoothMgr->m_ActiveFilter = v3;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100BFAC0
// Name: protected: void CPaintSculptDlg::OnClose(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPaintSculptDlg::OnClose(CDispPaintDataDlg *this)
{
  CToolDisplace *DisplacementTool; // eax
  HWND Parent; // eax
  CWnd *v4; // eax

  DisplacementTool = GetDisplacementTool();
  if ( DisplacementTool != nullptr )
    DisplacementTool->m_uiTool = 1;
  Parent = GetParent(hWnd: this->m_hWnd);
  v4 = CWnd::FromHandle(hWnd: Parent);
  if ( v4 != nullptr )
    CFaceEditDispPage::SetTool(this: (CFaceEditDispPage *)&v4[18].m_xConnPtContainer, tool: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100BFB00
// Name: protected: void CDispPaintDataDlg::OnDestroy(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDispPaintDataDlg::OnDestroy(CDispPaintDataDlg *this)
{
  CToolDisplace *DisplacementTool; // eax

  GetWindowRect(hWnd: this->m_hWnd, lpRect: &this->m_DialogPosRect);
  DisplacementTool = GetDisplacementTool();
  if ( DisplacementTool != nullptr )
  {
    this->m_uiPrevEffect = DisplacementTool->m_uiEffect;
    this->m_fPrevPaintValue = DisplacementTool->m_flPaintValueData;
  }
  this->m_iPrevBrush = SendMessageA(hWnd: this->m_comboboxBrush.m_hWnd, Msg: 0x147u, wParam: 0, lParam: 0);
  CWnd::Detach(this: &this->m_comboboxBrush);
}

//------------------------------------------------------------------------------
// Address: 0x100BFB60
// Name: protected: void CDispPaintDistDlg::InitBrushType(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDispPaintDistDlg::InitBrushType(CDispPaintDistDlg *this)
{
  CToolDisplace *DisplacementTool; // eax
  CToolDisplace *v3; // ebx
  unsigned int m_uiBrushType; // eax
  CWnd *DlgItem; // eax
  CWnd *v6; // eax
  CWnd *v7; // eax
  CWnd *v8; // eax
  CWnd *v9; // eax
  CWnd *v10; // eax
  CWnd *v11; // eax
  CWnd *v12; // eax

  DisplacementTool = GetDisplacementTool();
  v3 = DisplacementTool;
  if ( DisplacementTool != nullptr )
  {
    m_uiBrushType = DisplacementTool->m_uiBrushType;
    if ( m_uiBrushType != 0 )
    {
      if ( m_uiBrushType == 1 )
      {
        DlgItem = CWnd::GetDlgItem(this, nID: 1584);
        SendMessageA(hWnd: DlgItem->m_hWnd, Msg: 0xF1u, wParam: 0, lParam: 0);
        v6 = CWnd::GetDlgItem(this, nID: 1585);
        SendMessageA(hWnd: v6->m_hWnd, Msg: 0xF1u, wParam: 1u, lParam: 0);
      }
    }
    else
    {
      v7 = CWnd::GetDlgItem(this, nID: 1584);
      SendMessageA(hWnd: v7->m_hWnd, Msg: 0xF1u, wParam: 1u, lParam: 0);
      v8 = CWnd::GetDlgItem(this, nID: 1585);
      SendMessageA(hWnd: v8->m_hWnd, Msg: 0xF1u, wParam: 0, lParam: 0);
    }
    if ( v3->m_bSpatial )
    {
      v9 = CWnd::GetDlgItem(this, nID: 1584);
      CWnd::EnableWindow(this: v9, bEnable: 1);
      v10 = CWnd::GetDlgItem(this, nID: 1585);
      CWnd::EnableWindow(this: v10, bEnable: 1);
    }
    else
    {
      v11 = CWnd::GetDlgItem(this, nID: 1584);
      CWnd::EnableWindow(this: v11, bEnable: 0);
      v12 = CWnd::GetDlgItem(this, nID: 1585);
      CWnd::EnableWindow(this: v12, bEnable: 0);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100BFC60
// Name: public: virtual int CPaintSculptDlg::OnInitDialog(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CPaintSculptDlg::OnInitDialog(CPaintSculptDlg *this)
{
  tagRECT ThisLoc; // [esp+4h] [ebp-20h] BYREF
  tagRECT OptionsLoc; // [esp+14h] [ebp-10h] BYREF

  CDialog::OnInitDialog(this);
  if ( GetDisplacementTool() == nullptr )
    return 0;
  if ( bInit_0 )
    CWnd::SetWindowPos(
      this,
      pWndInsertAfter: &CWnd::wndTop,
      x: this->m_DialogPosRect.left,
      y: this->m_DialogPosRect.top,
      cx: this->m_DialogPosRect.right - this->m_DialogPosRect.left,
      cy: this->m_DialogPosRect.bottom - this->m_DialogPosRect.top,
      nFlags: 4u);
  else
    bInit_0 = true;
  SendMessageA(hWnd: this->m_AutoSew.m_hWnd, Msg: 0xF1u, wParam: this->m_bAutoSew, lParam: 0);
  this->m_PushOptions->m_PaintOwner = this;
  this->m_CarveOptions->m_PaintOwner = this;
  this->m_BlendOptions->m_PaintOwner = this;
  if ( this->m_PushOptions->Create(this: this->m_PushOptions, a2: 352u, a3: this) == 0
    || this->m_CarveOptions->Create(this: this->m_CarveOptions, a2: 354u, a3: this) == 0
    || this->m_BlendOptions->Create(this: this->m_BlendOptions, a2: 1725u, a3: this) == 0 )
  {
    return 0;
  }
  GetWindowRect(hWnd: this->m_SculptOptionsLoc.m_hWnd, lpRect: &OptionsLoc);
  GetWindowRect(hWnd: this->m_hWnd, lpRect: &ThisLoc);
  CWnd::SetWindowPos(
    this: this->m_PushOptions,
    pWndInsertAfter: nullptr,
    x: 10,
    y: OptionsLoc.top - ThisLoc.top - 20,
    cx: 0,
    cy: 0,
    nFlags: 0x41u);
  CWnd::SetWindowPos(
    this: this->m_CarveOptions,
    pWndInsertAfter: nullptr,
    x: 10,
    y: OptionsLoc.top - ThisLoc.top - 20,
    cx: 0,
    cy: 0,
    nFlags: 0x41u);
  CWnd::SetWindowPos(
    this: this->m_BlendOptions,
    pWndInsertAfter: nullptr,
    x: 10,
    y: OptionsLoc.top - ThisLoc.top - 20,
    cx: 0,
    cy: 0,
    nFlags: 0x41u);
  CWnd::ShowWindow(this: this->m_PushOptions, nCmdShow: 0);
  CWnd::ShowWindow(this: this->m_CarveOptions, nCmdShow: 0);
  CWnd::ShowWindow(this: this->m_BlendOptions, nCmdShow: 0);
  CWnd::EnableWindow(this: &this->m_ProjectButton, bEnable: 0);
  CPaintSculptDlg::SetActiveMode(this, NewMode: this->m_SculptMode);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100BFE30
// Name: protected: void CPaintSculptDlg::OnBnClickedSculptPush(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPaintSculptDlg::OnBnClickedSculptPush(CPaintSculptDlg *this)
{
  CPaintSculptDlg::SetActiveMode(this, NewMode: SCULPT_MODE_PUSH);
}

//------------------------------------------------------------------------------
// Address: 0x100BFE40
// Name: protected: void CPaintSculptDlg::OnBnClickedSculptCarve(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPaintSculptDlg::OnBnClickedSculptCarve(CPaintSculptDlg *this)
{
  CPaintSculptDlg::SetActiveMode(this, NewMode: SCULPT_MODE_CARVE);
}

//------------------------------------------------------------------------------
// Address: 0x100BFE50
// Name: protected: void CPaintSculptDlg::OnBnClickedSculptBlend(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPaintSculptDlg::OnBnClickedSculptBlend(CPaintSculptDlg *this)
{
  CPaintSculptDlg::SetActiveMode(this, NewMode: SCULPT_MODE_BLEND);
}

//------------------------------------------------------------------------------
// Address: 0x100BFE60
// Name: protected: virtual struct AFX_MSGMAP const __near * CDispCreateDlg::GetMessageMap(void)const
// Source: json
//------------------------------------------------------------------------------
const AFX_MSGMAP *__thiscall CDispCreateDlg::GetMessageMap(CDispCreateDlg *this)
{
  return (const AFX_MSGMAP *)&off_105E95D4;
}

//------------------------------------------------------------------------------
// Address: 0x100BFE70
// Name: protected: void CDispPaintDistDlg::OnEditDistance(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDispPaintDistDlg::OnEditDistance(CDispPaintDistDlg *this)
{
  CAfxStringMgr *StringManager; // eax
  CToolDisplace *DisplacementTool; // edi
  float v4; // xmm0_4
  LPARAM v5; // eax
  char *v6; // eax
  float flDistance; // [esp+8h] [ebp-14h]
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > strDistance; // [esp+Ch] [ebp-10h] BYREF
  int v9; // [esp+18h] [ebp-4h]

  StringManager = AfxGetStringManager();
  if ( StringManager == nullptr )
    ATL::AtlThrowImpl(hr: -2147467259);
  strDistance.m_pszData = (char *)&StringManager->GetNilString(this: StringManager)[1];
  v9 = 1;
  CWnd::GetWindowTextA(this: &this->m_editDistance, rString: &strDistance);
  flDistance = atof(nptr: strDistance.m_pszData);
  DisplacementTool = GetDisplacementTool();
  if ( DisplacementTool != nullptr )
  {
    v4 = flDistance;
    if ( flDistance != this->m_flPrevDistance )
    {
      v5 = (int)flDistance;
      if ( (int)flDistance >= 0 )
      {
        if ( v5 > 60 )
          v5 = 60;
      }
      else
      {
        v5 = 0;
      }
      SendMessageA(hWnd: this->m_sliderDistance.m_hWnd, Msg: 0x405u, wParam: 1u, lParam: v5);
      v4 = flDistance;
    }
    DisplacementTool->m_iPaintChannel = 0;
    DisplacementTool->m_flPaintValueGeo = v4;
    this->m_flPrevDistance = v4;
  }
  v9 = -1;
  v6 = strDistance.m_pszData - 16;
  if ( _InterlockedDecrement((volatile signed __int32 *)strDistance.m_pszData - 1) <= 0 )
    (*(void (__stdcall **)(char *))(**(_DWORD **)v6 + 4))(a1: v6);
}

//------------------------------------------------------------------------------
// Address: 0x100BFF80
// Name: protected: void CDispPaintDistDlg::OnEditRadius(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDispPaintDistDlg::OnEditRadius(CDispPaintDistDlg *this)
{
  CAfxStringMgr *StringManager; // eax
  CToolDisplace *DisplacementTool; // edi
  float v4; // xmm0_4
  LPARAM v5; // eax
  char *v6; // eax
  float flRadius; // [esp+8h] [ebp-14h]
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > strRadius; // [esp+Ch] [ebp-10h] BYREF
  int v9; // [esp+18h] [ebp-4h]

  StringManager = AfxGetStringManager();
  if ( StringManager == nullptr )
    ATL::AtlThrowImpl(hr: -2147467259);
  strRadius.m_pszData = (char *)&StringManager->GetNilString(this: StringManager)[1];
  v9 = 1;
  CWnd::GetWindowTextA(this: &this->m_editRadius, rString: &strRadius);
  flRadius = atof(nptr: strRadius.m_pszData);
  DisplacementTool = GetDisplacementTool();
  if ( DisplacementTool != nullptr )
  {
    v4 = flRadius;
    if ( flRadius != this->m_flPrevRadius )
    {
      v5 = (int)flRadius;
      if ( (int)flRadius >= 1 )
      {
        if ( v5 > 1024 )
          v5 = 1024;
      }
      else
      {
        v5 = 1;
      }
      SendMessageA(hWnd: this->m_sliderRadius.m_hWnd, Msg: 0x405u, wParam: 1u, lParam: v5);
      v4 = flRadius;
    }
    DisplacementTool->m_flSpatialRadius = v4;
    this->m_flPrevRadius = v4;
  }
  v9 = -1;
  v6 = strRadius.m_pszData - 16;
  if ( _InterlockedDecrement((volatile signed __int32 *)strRadius.m_pszData - 1) <= 0 )
    (*(void (__stdcall **)(char *))(**(_DWORD **)v6 + 4))(a1: v6);
}

//------------------------------------------------------------------------------
// Address: 0x100C0090
// Name: protected: void CDispPaintDataDlg::OnEditValue(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDispPaintDataDlg::OnEditValue(CDispPaintDataDlg *this)
{
  CAfxStringMgr *StringManager; // eax
  CToolDisplace *DisplacementTool; // esi
  LPARAM v4; // eax
  char *v5; // eax
  float fValue; // [esp+8h] [ebp-14h]
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > strValue; // [esp+Ch] [ebp-10h] BYREF
  int v8; // [esp+18h] [ebp-4h]

  StringManager = AfxGetStringManager();
  if ( StringManager == nullptr )
    ATL::AtlThrowImpl(hr: -2147467259);
  strValue.m_pszData = (char *)&StringManager->GetNilString(this: StringManager)[1];
  v8 = 1;
  CWnd::GetWindowTextA(this: &this->m_editValue, rString: &strValue);
  fValue = atof(nptr: strValue.m_pszData);
  DisplacementTool = GetDisplacementTool();
  if ( DisplacementTool != nullptr )
  {
    v4 = (int)fValue;
    if ( (int)fValue >= 1 )
    {
      if ( v4 > 255 )
        v4 = 255;
    }
    else
    {
      v4 = 1;
    }
    SendMessageA(hWnd: this->m_sliderValue.m_hWnd, Msg: 0x405u, wParam: 1u, lParam: v4);
    DisplacementTool->m_iPaintChannel = 1;
    DisplacementTool->m_flPaintValueData = fValue;
  }
  v8 = -1;
  v5 = strValue.m_pszData - 16;
  if ( _InterlockedDecrement((volatile signed __int32 *)strValue.m_pszData - 1) <= 0 )
    (*(void (__stdcall **)(char *))(**(_DWORD **)v5 + 4))(a1: v5);
}

//------------------------------------------------------------------------------
// Address: 0x100C0190
// Name: protected: virtual struct AFX_MSGMAP const __near * CPaintSculptDlg::GetMessageMap(void)const
// Source: json
//------------------------------------------------------------------------------
const AFX_MSGMAP *__thiscall CPaintSculptDlg::GetMessageMap(CPaintSculptDlg *this)
{
  return (const AFX_MSGMAP *)&off_105E960C;
}

//------------------------------------------------------------------------------
// Address: 0x100C01A0
// Name: protected: void CDispNoiseDlg::OnSpinUpDown(struct tagNMHDR __near *,long __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDispNoiseDlg::OnSpinUpDown(CDispNoiseDlg *this, ATL::CStringData *pNMHDR, int *pResult)
{
  tagNMHDR *v3; // ebx
  unsigned int nDataLength; // eax
  CWnd *v6; // edi
  CAfxStringMgr *v7; // eax
  float v8; // xmm0_4
  CWnd *DlgItem; // edi
  CAfxStringMgr *StringManager; // eax
  float v11; // xmm0_4
  unsigned int *v12; // eax
  float v13; // [esp+14h] [ebp-10h]
  float v14; // [esp+14h] [ebp-10h]

  v3 = (tagNMHDR *)pNMHDR;
  nDataLength = pNMHDR->nDataLength;
  if ( nDataLength == 1008 )
  {
    DlgItem = CWnd::GetDlgItem(this, nID: 1009);
    StringManager = AfxGetStringManager();
    if ( StringManager == nullptr )
      ATL::AtlThrowImpl(hr: -2147467259);
    pNMHDR = StringManager->GetNilString(this: StringManager) + 1;
    CWnd::GetWindowTextA(
      this: DlgItem,
      rString: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&pNMHDR);
    v14 = atof(nptr: (const char *)pNMHDR);
    this->m_Min = v14;
    v11 = v14 - (float)((float)(int)v3[1].idFrom * 0.5);
    this->m_Min = v11;
    ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::Format(
      this: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&pNMHDR,
      pszFormat: "%4.2f",
      v11);
    CWnd::SetWindowTextA(this: DlgItem, lpszString: (const char *)pNMHDR);
    *pResult = 0;
  }
  else
  {
    if ( nDataLength != 1538 )
      return;
    v6 = CWnd::GetDlgItem(this, nID: 1539);
    v7 = AfxGetStringManager();
    if ( v7 == nullptr )
      ATL::AtlThrowImpl(hr: -2147467259);
    pNMHDR = v7->GetNilString(this: v7) + 1;
    CWnd::GetWindowTextA(this: v6, rString: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&pNMHDR);
    v13 = atof(nptr: (const char *)pNMHDR);
    this->m_Max = v13;
    v8 = v13 - (float)((float)(int)v3[1].idFrom * 0.5);
    this->m_Max = v8;
    ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::Format(
      this: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&pNMHDR,
      pszFormat: "%4.2f",
      v8);
    CWnd::SetWindowTextA(this: v6, lpszString: (const char *)pNMHDR);
    *pResult = 0;
  }
  v12 = (unsigned int *)&pNMHDR[-1];
  if ( _InterlockedDecrement(&pNMHDR[-1].nRefs) <= 0 )
    (*(void (__stdcall **)(unsigned int *))(*(_DWORD *)*v12 + 4))(a1: v12);
}

//------------------------------------------------------------------------------
// Address: 0x100C0370
// Name: protected: void CDispPaintDistDlg::UpdateEditBoxDistance(float,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDispPaintDistDlg::UpdateEditBoxDistance(
        CDispPaintDistDlg *this,
        float flDistance,
        ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > bForceInit)
{
  CAfxStringMgr *StringManager; // eax
  char *m_pszData; // esi

  if ( flDistance != this->m_flPrevDistance || LOBYTE(bForceInit.m_pszData) != 0 )
  {
    StringManager = AfxGetStringManager();
    if ( StringManager == nullptr )
      ATL::AtlThrowImpl(hr: -2147467259);
    bForceInit.m_pszData = (char *)&StringManager->GetNilString(this: StringManager)[1];
    ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::Format(
      this: &bForceInit,
      pszFormat: "%4.2f",
      flDistance);
    m_pszData = bForceInit.m_pszData;
    CWnd::SetWindowTextA(this: &this->m_editDistance, lpszString: bForceInit.m_pszData);
    if ( _InterlockedDecrement((volatile signed __int32 *)m_pszData - 1) <= 0 )
      (*(void (__thiscall **)(_DWORD, char *))(**((_DWORD **)m_pszData - 4) + 4))(
        a1: *((_DWORD *)m_pszData - 4),
        a2: m_pszData - 16);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100C0440
// Name: protected: void CDispPaintDistDlg::UpdateEditBoxRadius(float,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDispPaintDistDlg::UpdateEditBoxRadius(
        CDispPaintDistDlg *this,
        float flRadius,
        ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > bForceInit)
{
  CAfxStringMgr *StringManager; // eax
  char *m_pszData; // esi

  if ( flRadius != this->m_flPrevRadius || LOBYTE(bForceInit.m_pszData) != 0 )
  {
    StringManager = AfxGetStringManager();
    if ( StringManager == nullptr )
      ATL::AtlThrowImpl(hr: -2147467259);
    bForceInit.m_pszData = (char *)&StringManager->GetNilString(this: StringManager)[1];
    ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::Format(
      this: &bForceInit,
      pszFormat: "%4.2f",
      flRadius);
    m_pszData = bForceInit.m_pszData;
    CWnd::SetWindowTextA(this: &this->m_editRadius, lpszString: bForceInit.m_pszData);
    if ( _InterlockedDecrement((volatile signed __int32 *)m_pszData - 1) <= 0 )
      (*(void (__thiscall **)(_DWORD, char *))(**((_DWORD **)m_pszData - 4) + 4))(
        a1: *((_DWORD *)m_pszData - 4),
        a2: m_pszData - 16);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100C0510
// Name: protected: void CDispPaintDistDlg::OnHScroll(unsigned int,unsigned int,class CScrollBar __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDispPaintDistDlg::OnHScroll(
        CDispPaintDistDlg *this,
        unsigned int nSBCode,
        unsigned int nPos,
        CScrollBar *pScrollBar)
{
  CToolDisplace *DisplacementTool; // edi
  CWnd *DlgItem; // eax
  float v7; // xmm0_4
  char *v8; // eax
  CWnd *v9; // eax
  float v10; // xmm0_4
  char *v11; // eax
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > v12; // [esp+18h] [ebp-10h] BYREF
  int v13; // [esp+24h] [ebp-4h]

  DisplacementTool = GetDisplacementTool();
  if ( DisplacementTool != nullptr )
  {
    DlgItem = CWnd::GetDlgItem(this, nID: 1544);
    if ( DlgItem != nullptr )
    {
      v7 = (float)SendMessageA(hWnd: DlgItem->m_hWnd, Msg: 0x400u, wParam: 0, lParam: 0);
      if ( v7 != this->m_flPrevDistance )
      {
        DisplacementTool->m_iPaintChannel = 0;
        DisplacementTool->m_flPaintValueGeo = v7;
        ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>(this: &v12);
        v13 = 0;
        ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::Format(this: &v12, pszFormat: "%4.2f", v7);
        CWnd::SetWindowTextA(this: &this->m_editDistance, lpszString: v12.m_pszData);
        v13 = -1;
        v8 = v12.m_pszData - 16;
        if ( _InterlockedDecrement((volatile signed __int32 *)v12.m_pszData - 1) <= 0 )
          (*(void (__stdcall **)(char *))(**(_DWORD **)v8 + 4))(a1: v8);
      }
    }
    v9 = CWnd::GetDlgItem(this, nID: 1547);
    if ( v9 != nullptr )
    {
      v10 = (float)SendMessageA(hWnd: v9->m_hWnd, Msg: 0x400u, wParam: 0, lParam: 0);
      if ( v10 != this->m_flPrevRadius )
      {
        DisplacementTool->m_flSpatialRadius = v10;
        ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>(this: &v12);
        v13 = 2;
        ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::Format(this: &v12, pszFormat: "%4.2f", v10);
        CWnd::SetWindowTextA(this: &this->m_editRadius, lpszString: v12.m_pszData);
        v13 = -1;
        v11 = v12.m_pszData - 16;
        if ( _InterlockedDecrement((volatile signed __int32 *)v12.m_pszData - 1) <= 0 )
          (*(void (__stdcall **)(char *))(**(_DWORD **)v11 + 4))(a1: v11);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100C06C0
// Name: protected: void CDispPaintDataDlg::InitValue(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDispPaintDataDlg::InitValue(CDispPaintDataDlg *this)
{
  CEdit *p_m_editValue; // ebx
  HWND__ *m_hWnd; // eax
  HWND__ *v4; // eax
  CToolDisplace *DisplacementTool; // eax
  float m_fPrevPaintValue; // xmm0_4
  LPARAM v7; // eax
  CAfxStringMgr *StringManager; // eax
  char *m_pszData; // esi
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > v10; // [esp+14h] [ebp-10h] BYREF
  int v11; // [esp+20h] [ebp-4h]

  p_m_editValue = &this->m_editValue;
  if ( this == (CDispPaintDataDlg *)-504 )
    m_hWnd = nullptr;
  else
    m_hWnd = this->m_editValue.m_hWnd;
  v4 = (HWND__ *)SendMessageA(hWnd: this->m_sliderValue.m_hWnd, Msg: 0x420u, wParam: 0, lParam: (LPARAM)m_hWnd);
  CWnd::FromHandle(hWnd: v4);
  CSliderCtrl::SetRange(this: &this->m_sliderValue, nMin: 1, nMax: 255, bRedraw: 0);
  SendMessageA(hWnd: this->m_sliderValue.m_hWnd, Msg: 0x414u, wParam: 0x19u, lParam: 0);
  DisplacementTool = GetDisplacementTool();
  if ( DisplacementTool != nullptr )
  {
    m_fPrevPaintValue = this->m_fPrevPaintValue;
    DisplacementTool->m_iPaintChannel = 1;
    DisplacementTool->m_flPaintValueData = m_fPrevPaintValue;
    v7 = (int)this->m_fPrevPaintValue;
    if ( v7 >= 1 )
    {
      if ( v7 > 255 )
        v7 = 255;
    }
    else
    {
      v7 = 1;
    }
    SendMessageA(hWnd: this->m_sliderValue.m_hWnd, Msg: 0x405u, wParam: 1u, lParam: v7);
    StringManager = AfxGetStringManager();
    if ( StringManager == nullptr )
      ATL::AtlThrowImpl(hr: -2147467259);
    v10.m_pszData = (char *)&StringManager->GetNilString(this: StringManager)[1];
    v11 = 1;
    ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::Format(
      this: &v10,
      pszFormat: "%4.2f",
      this->m_fPrevPaintValue);
    m_pszData = v10.m_pszData;
    CWnd::SetWindowTextA(this: p_m_editValue, lpszString: v10.m_pszData);
    v11 = -1;
    if ( _InterlockedDecrement((volatile signed __int32 *)m_pszData - 1) <= 0 )
      (*(void (__thiscall **)(_DWORD, char *))(**((_DWORD **)m_pszData - 4) + 4))(
        a1: *((_DWORD *)m_pszData - 4),
        a2: m_pszData - 16);
  }
  else
  {
    SendMessageA(hWnd: this->m_sliderValue.m_hWnd, Msg: 0x405u, wParam: 1u, lParam: 15);
    CWnd::SetWindowTextA(this: p_m_editValue, lpszString: "15.00");
  }
}

//------------------------------------------------------------------------------
// Address: 0x100C0850
// Name: protected: void CDispPaintDataDlg::OnHScroll(unsigned int,unsigned int,class CScrollBar __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDispPaintDataDlg::OnHScroll(
        CDispPaintDataDlg *this,
        unsigned int nSBCode,
        unsigned int nPos,
        CScrollBar *pScrollBar)
{
  CToolDisplace *DisplacementTool; // esi
  CWnd *DlgItem; // eax
  CAfxStringMgr *StringManager; // eax
  char *m_pszData; // esi
  float v9; // [esp+10h] [ebp-14h]
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > v10; // [esp+14h] [ebp-10h] BYREF
  int v11; // [esp+20h] [ebp-4h]

  DisplacementTool = GetDisplacementTool();
  if ( DisplacementTool != nullptr )
  {
    DlgItem = CWnd::GetDlgItem(this, nID: 1562);
    if ( DlgItem != nullptr )
    {
      v9 = (float)SendMessageA(hWnd: DlgItem->m_hWnd, Msg: 0x400u, wParam: 0, lParam: 0);
      DisplacementTool->m_iPaintChannel = 1;
      DisplacementTool->m_flPaintValueData = v9;
      StringManager = AfxGetStringManager();
      if ( StringManager == nullptr )
        ATL::AtlThrowImpl(hr: -2147467259);
      v10.m_pszData = (char *)&StringManager->GetNilString(this: StringManager)[1];
      v11 = 1;
      ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::Format(this: &v10, pszFormat: "%4.2f", v9);
      m_pszData = v10.m_pszData;
      CWnd::SetWindowTextA(this: &this->m_editValue, lpszString: v10.m_pszData);
      v11 = -1;
      if ( _InterlockedDecrement((volatile signed __int32 *)m_pszData - 1) <= 0 )
        (*(void (__thiscall **)(_DWORD, char *))(**((_DWORD **)m_pszData - 4) + 4))(
          a1: *((_DWORD *)m_pszData - 4),
          a2: m_pszData - 16);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100C0960
// Name: protected: void CDispPaintDistDlg::InitDistance(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDispPaintDistDlg::InitDistance(CDispPaintDistDlg *this)
{
  void *p_m_editDistance; // eax
  HWND__ *v3; // eax
  CToolDisplace *DisplacementTool; // eax
  LPARAM m_flPrevDistance; // eax

  p_m_editDistance = &this->m_editDistance;
  if ( this != (CDispPaintDistDlg *)-380 )
    p_m_editDistance = this->m_editDistance.m_hWnd;
  v3 = (HWND__ *)SendMessageA(
                   hWnd: this->m_sliderDistance.m_hWnd,
                   Msg: 0x420u,
                   wParam: 0,
                   lParam: (LPARAM)p_m_editDistance);
  CWnd::FromHandle(hWnd: v3);
  CSliderCtrl::SetRange(this: &this->m_sliderDistance, nMin: 0, nMax: 60, bRedraw: 0);
  DisplacementTool = GetDisplacementTool();
  if ( DisplacementTool != nullptr )
  {
    this->m_flPrevDistance = DisplacementTool->m_flPaintValueGeo;
    m_flPrevDistance = (int)this->m_flPrevDistance;
    if ( m_flPrevDistance >= 0 )
    {
      if ( m_flPrevDistance > 60 )
        m_flPrevDistance = 60;
    }
    else
    {
      m_flPrevDistance = 0;
    }
    SendMessageA(hWnd: this->m_sliderDistance.m_hWnd, Msg: 0x405u, wParam: 1u, lParam: m_flPrevDistance);
    CDispPaintDistDlg::UpdateEditBoxDistance(
      this,
      flDistance: this->m_flPrevDistance,
      bForceInit: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > >)1);
  }
  else
  {
    SendMessageA(hWnd: this->m_sliderDistance.m_hWnd, Msg: 0x405u, wParam: 1u, lParam: 1);
    CDispPaintDistDlg::UpdateEditBoxDistance(
      this,
      flDistance: 1.0,
      bForceInit: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > >)1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100C0A30
// Name: protected: void CDispPaintDistDlg::EnableSliderRadius(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDispPaintDistDlg::EnableSliderRadius(CDispPaintDistDlg *this)
{
  CToolDisplace *DisplacementTool; // eax
  float m_flSpatialRadius; // xmm0_4
  LPARAM v4; // eax

  CWnd::EnableWindow(this: &this->m_sliderRadius, bEnable: 1);
  CWnd::EnableWindow(this: &this->m_editRadius, bEnable: 1);
  DisplacementTool = GetDisplacementTool();
  if ( DisplacementTool != nullptr )
  {
    m_flSpatialRadius = DisplacementTool->m_flSpatialRadius;
    v4 = (int)m_flSpatialRadius;
    this->m_flPrevRadius = m_flSpatialRadius;
    if ( (int)m_flSpatialRadius >= 1 )
    {
      if ( v4 > 1024 )
        v4 = 1024;
    }
    else
    {
      v4 = 1;
    }
    SendMessageA(hWnd: this->m_sliderRadius.m_hWnd, Msg: 0x405u, wParam: 1u, lParam: v4);
    CDispPaintDistDlg::UpdateEditBoxRadius(
      this,
      flRadius: this->m_flPrevRadius,
      bForceInit: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > >)1);
  }
  else
  {
    SendMessageA(hWnd: this->m_sliderRadius.m_hWnd, Msg: 0x405u, wParam: 1u, lParam: 1);
    CDispPaintDistDlg::UpdateEditBoxRadius(
      this,
      flRadius: 1.0,
      bForceInit: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > >)1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100C0AE0
// Name: public: void CDispPaintDistDlg::UpdateSpatialData(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDispPaintDistDlg::UpdateSpatialData(CDispPaintDistDlg *this)
{
  CToolDisplace *DisplacementTool; // eax
  float m_flSpatialRadius; // xmm0_4
  LPARAM v4; // eax

  DisplacementTool = GetDisplacementTool();
  if ( DisplacementTool != nullptr )
  {
    m_flSpatialRadius = DisplacementTool->m_flSpatialRadius;
    v4 = (int)m_flSpatialRadius;
    this->m_flPrevRadius = m_flSpatialRadius;
    if ( (int)m_flSpatialRadius >= 1 )
    {
      if ( v4 > 1024 )
        v4 = 1024;
    }
    else
    {
      v4 = 1;
    }
    SendMessageA(hWnd: this->m_sliderRadius.m_hWnd, Msg: 0x405u, wParam: 1u, lParam: v4);
    CDispPaintDistDlg::UpdateEditBoxRadius(
      this,
      flRadius: this->m_flPrevRadius,
      bForceInit: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > >)1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100C0B50
// Name: protected: void CDispPaintDistDlg::FilterComboBoxBrushGeo(unsigned int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDispPaintDistDlg::FilterComboBoxBrushGeo(CDispPaintDistDlg *this, unsigned int nEffect, bool bInit)
{
  signed int i; // esi
  CToolDisplace *DisplacementTool; // eax
  CDispMapImageFilterManager *p_m_FilterRaiseToMgr; // ebx
  int m_FilterCount; // eax
  int v8; // edi
  const ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *v9; // esi
  AFX_MODULE_STATE *ModuleState; // eax
  char *v11; // eax
  char v12; // cl
  char *v13; // eax
  HWND__ *m_hWnd; // [esp-10h] [ebp-130h]
  char v15; // [esp+7h] [ebp-119h] BYREF
  char appDir[260]; // [esp+8h] [ebp-118h] BYREF
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > iconFilename; // [esp+10Ch] [ebp-14h] BYREF
  CDispPaintDistDlg *v18; // [esp+110h] [ebp-10h]
  int v19; // [esp+11Ch] [ebp-4h]
  const ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > **nEffecta; // [esp+128h] [ebp+8h]

  m_hWnd = this->m_comboboxBrush.m_hWnd;
  v18 = this;
  for ( i = SendMessageA(hWnd: m_hWnd, Msg: 0x146u, wParam: 0, lParam: 0) - 1; i >= 0; --i )
    CIconComboBox::DeleteIcon(this: &this->m_comboboxBrush, ndx: i);
  DisplacementTool = GetDisplacementTool();
  if ( DisplacementTool != nullptr )
  {
    if ( nEffect != 0 )
    {
      if ( nEffect == 1 )
      {
        p_m_FilterRaiseToMgr = &DisplacementTool->m_FilterRaiseToMgr;
      }
      else
      {
        if ( nEffect != 2 )
          return;
        p_m_FilterRaiseToMgr = &DisplacementTool->m_FilterSmoothMgr;
      }
    }
    else
    {
      p_m_FilterRaiseToMgr = &DisplacementTool->m_FilterRaiseLowerMgr;
    }
    if ( p_m_FilterRaiseToMgr != nullptr )
    {
      m_FilterCount = p_m_FilterRaiseToMgr->m_FilterCount;
      v8 = 0;
      if ( m_FilterCount > 0 )
      {
        nEffecta = (const ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > **)p_m_FilterRaiseToMgr->m_pFilterList;
        do
        {
          if ( v8 >= 0 )
          {
            if ( v8 < m_FilterCount )
              v9 = *nEffecta;
            else
              v9 = nullptr;
          }
          else
          {
            v9 = nullptr;
          }
          ModuleState = AfxGetModuleState();
          CHammer::GetDirectory(this: (CHammer *)ModuleState->m_pCurrentWinApp, dir: DIR_PROGRAM, p: appDir);
          v11 = &v15;
          do
            v12 = *++v11;
          while ( v12 != 0 );
          strcpy(v11, "filters\\");
          ATL::operator+(result: &iconFilename, psz1: appDir, str2: v9 + 8);
          v19 = 0;
          CIconComboBox::AddIcon(this: &v18->m_comboboxBrush, pIconName: iconFilename.m_pszData);
          v19 = -1;
          v13 = iconFilename.m_pszData - 16;
          if ( _InterlockedDecrement((volatile signed __int32 *)iconFilename.m_pszData - 1) <= 0 )
            (*(void (__stdcall **)(char *))(**(_DWORD **)v13 + 4))(a1: v13);
          m_FilterCount = p_m_FilterRaiseToMgr->m_FilterCount;
          ++nEffecta;
          ++v8;
        }
        while ( v8 < m_FilterCount );
      }
      if ( bInit )
        SendMessageA(hWnd: v18->m_comboboxBrush.m_hWnd, Msg: 0x14Eu, wParam: v18->m_nPrevBrush, lParam: 0);
      else
        SendMessageA(hWnd: v18->m_comboboxBrush.m_hWnd, Msg: 0x14Eu, wParam: 0, lParam: 0);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100C0D00
// Name: protected: void CDispPaintDistDlg::OnCheckSpatial(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDispPaintDistDlg::OnCheckSpatial(CDispPaintDistDlg *this)
{
  CToolDisplace *DisplacementTool; // eax
  bool v3; // cl
  CWnd *DlgItem; // eax
  CWnd *v5; // eax
  CWnd *v6; // eax
  CWnd *v7; // eax

  DisplacementTool = GetDisplacementTool();
  if ( DisplacementTool != nullptr )
  {
    v3 = !DisplacementTool->m_bSpatial;
    DisplacementTool->m_bSpatial = v3;
    if ( v3 )
    {
      CDispPaintDistDlg::EnableSliderRadius(this);
      CWnd::EnableWindow(this: &this->m_comboboxBrush, bEnable: 0);
      DlgItem = CWnd::GetDlgItem(this, nID: 1584);
      CWnd::EnableWindow(this: DlgItem, bEnable: 1);
      v5 = CWnd::GetDlgItem(this, nID: 1585);
      CWnd::EnableWindow(this: v5, bEnable: 1);
    }
    else
    {
      CWnd::EnableWindow(this: &this->m_sliderRadius, bEnable: 0);
      CWnd::EnableWindow(this: &this->m_editRadius, bEnable: 0);
      CWnd::EnableWindow(this: &this->m_comboboxBrush, bEnable: 1);
      v6 = CWnd::GetDlgItem(this, nID: 1584);
      CWnd::EnableWindow(this: v6, bEnable: 0);
      v7 = CWnd::GetDlgItem(this, nID: 1585);
      CWnd::EnableWindow(this: v7, bEnable: 0);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100C0DC0
// Name: protected: void CDispPaintDistDlg::OnEffectRaiseLowerGeo(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDispPaintDistDlg::OnEffectRaiseLowerGeo(CDispPaintDistDlg *this)
{
  CToolDisplace *DisplacementTool; // eax
  CWnd *DlgItem; // eax
  CWnd *v4; // eax
  CWnd *v5; // eax

  DisplacementTool = GetDisplacementTool();
  if ( DisplacementTool != nullptr )
  {
    DisplacementTool->m_uiEffect = 0;
    DlgItem = CWnd::GetDlgItem(this, nID: 1192);
    SendMessageA(hWnd: DlgItem->m_hWnd, Msg: 0xF1u, wParam: 1u, lParam: 0);
    v4 = CWnd::GetDlgItem(this, nID: 1541);
    SendMessageA(hWnd: v4->m_hWnd, Msg: 0xF1u, wParam: 0, lParam: 0);
    v5 = CWnd::GetDlgItem(this, nID: 1542);
    SendMessageA(hWnd: v5->m_hWnd, Msg: 0xF1u, wParam: 0, lParam: 0);
    CDispPaintDistDlg::FilterComboBoxBrushGeo(this, nEffect: 0, bInit: false);
    CDispPaintDistDlg::OnComboBoxBrushGeo(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100C0E50
// Name: protected: void CDispPaintDistDlg::OnEffectRaiseToGeo(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDispPaintDistDlg::OnEffectRaiseToGeo(CDispPaintDistDlg *this)
{
  CToolDisplace *DisplacementTool; // eax
  CWnd *DlgItem; // eax
  CWnd *v4; // eax
  CWnd *v5; // eax

  DisplacementTool = GetDisplacementTool();
  if ( DisplacementTool != nullptr )
  {
    DisplacementTool->m_uiEffect = 1;
    DlgItem = CWnd::GetDlgItem(this, nID: 1192);
    SendMessageA(hWnd: DlgItem->m_hWnd, Msg: 0xF1u, wParam: 0, lParam: 0);
    v4 = CWnd::GetDlgItem(this, nID: 1541);
    SendMessageA(hWnd: v4->m_hWnd, Msg: 0xF1u, wParam: 1u, lParam: 0);
    v5 = CWnd::GetDlgItem(this, nID: 1542);
    SendMessageA(hWnd: v5->m_hWnd, Msg: 0xF1u, wParam: 0, lParam: 0);
    CDispPaintDistDlg::FilterComboBoxBrushGeo(this, nEffect: 1u, bInit: false);
    CDispPaintDistDlg::OnComboBoxBrushGeo(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100C0EE0
// Name: protected: void CDispPaintDistDlg::OnEffectSmoothGeo(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDispPaintDistDlg::OnEffectSmoothGeo(CDispPaintDistDlg *this)
{
  CToolDisplace *DisplacementTool; // eax
  CWnd *DlgItem; // eax
  CWnd *v4; // eax
  CWnd *v5; // eax

  DisplacementTool = GetDisplacementTool();
  if ( DisplacementTool != nullptr )
  {
    DisplacementTool->m_uiEffect = 2;
    DlgItem = CWnd::GetDlgItem(this, nID: 1192);
    SendMessageA(hWnd: DlgItem->m_hWnd, Msg: 0xF1u, wParam: 0, lParam: 0);
    v4 = CWnd::GetDlgItem(this, nID: 1541);
    SendMessageA(hWnd: v4->m_hWnd, Msg: 0xF1u, wParam: 0, lParam: 0);
    v5 = CWnd::GetDlgItem(this, nID: 1542);
    SendMessageA(hWnd: v5->m_hWnd, Msg: 0xF1u, wParam: 1u, lParam: 0);
    CDispPaintDistDlg::FilterComboBoxBrushGeo(this, nEffect: 2u, bInit: false);
    CDispPaintDistDlg::OnComboBoxBrushGeo(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100C0F70
// Name: protected: void CDispPaintDataDlg::FilterComboBoxBrushData(unsigned int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDispPaintDataDlg::FilterComboBoxBrushData(CDispPaintDataDlg *this, unsigned int uiEffect, bool bInit)
{
  signed int i; // esi
  CToolDisplace *DisplacementTool; // eax
  CDispMapImageFilterManager *p_m_FilterRaiseToMgr; // ebx
  int m_FilterCount; // eax
  int v8; // edi
  const ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *v9; // esi
  AFX_MODULE_STATE *ModuleState; // eax
  char *v11; // eax
  char v12; // cl
  char *v13; // eax
  HWND__ *m_hWnd; // [esp-10h] [ebp-130h]
  char v15; // [esp+7h] [ebp-119h] BYREF
  char appDir[260]; // [esp+8h] [ebp-118h] BYREF
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > iconFilename; // [esp+10Ch] [ebp-14h] BYREF
  CDispPaintDataDlg *v18; // [esp+110h] [ebp-10h]
  int v19; // [esp+11Ch] [ebp-4h]
  const ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > **uiEffecta; // [esp+128h] [ebp+8h]

  m_hWnd = this->m_comboboxBrush.m_hWnd;
  v18 = this;
  for ( i = SendMessageA(hWnd: m_hWnd, Msg: 0x146u, wParam: 0, lParam: 0) - 1; i >= 0; --i )
    CIconComboBox::DeleteIcon(this: &this->m_comboboxBrush, ndx: i);
  DisplacementTool = GetDisplacementTool();
  if ( DisplacementTool != nullptr )
  {
    if ( uiEffect != 0 )
    {
      if ( uiEffect == 1 )
      {
        p_m_FilterRaiseToMgr = &DisplacementTool->m_FilterRaiseToMgr;
      }
      else
      {
        if ( uiEffect != 2 )
          return;
        p_m_FilterRaiseToMgr = &DisplacementTool->m_FilterSmoothMgr;
      }
    }
    else
    {
      p_m_FilterRaiseToMgr = &DisplacementTool->m_FilterRaiseLowerMgr;
    }
    if ( p_m_FilterRaiseToMgr != nullptr )
    {
      m_FilterCount = p_m_FilterRaiseToMgr->m_FilterCount;
      v8 = 0;
      if ( m_FilterCount > 0 )
      {
        uiEffecta = (const ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > **)p_m_FilterRaiseToMgr->m_pFilterList;
        do
        {
          if ( v8 >= 0 )
          {
            if ( v8 < m_FilterCount )
              v9 = *uiEffecta;
            else
              v9 = nullptr;
          }
          else
          {
            v9 = nullptr;
          }
          ModuleState = AfxGetModuleState();
          CHammer::GetDirectory(this: (CHammer *)ModuleState->m_pCurrentWinApp, dir: DIR_PROGRAM, p: appDir);
          v11 = &v15;
          do
            v12 = *++v11;
          while ( v12 != 0 );
          strcpy(v11, "filters\\");
          ATL::operator+(result: &iconFilename, psz1: appDir, str2: v9 + 8);
          v19 = 0;
          CIconComboBox::AddIcon(this: &v18->m_comboboxBrush, pIconName: iconFilename.m_pszData);
          v19 = -1;
          v13 = iconFilename.m_pszData - 16;
          if ( _InterlockedDecrement((volatile signed __int32 *)iconFilename.m_pszData - 1) <= 0 )
            (*(void (__stdcall **)(char *))(**(_DWORD **)v13 + 4))(a1: v13);
          m_FilterCount = p_m_FilterRaiseToMgr->m_FilterCount;
          ++uiEffecta;
          ++v8;
        }
        while ( v8 < m_FilterCount );
      }
      if ( bInit )
        SendMessageA(hWnd: v18->m_comboboxBrush.m_hWnd, Msg: 0x14Eu, wParam: v18->m_iPrevBrush, lParam: 0);
      else
        SendMessageA(hWnd: v18->m_comboboxBrush.m_hWnd, Msg: 0x14Eu, wParam: 0, lParam: 0);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100C1120
// Name: protected: void CDispPaintDataDlg::OnEffectRaiseLowerData(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDispPaintDataDlg::OnEffectRaiseLowerData(CDispPaintDataDlg *this)
{
  CToolDisplace *DisplacementTool; // eax
  CWnd *DlgItem; // eax
  CWnd *v4; // eax
  CWnd *v5; // eax

  DisplacementTool = GetDisplacementTool();
  if ( DisplacementTool != nullptr )
  {
    DisplacementTool->m_uiEffect = 0;
    DlgItem = CWnd::GetDlgItem(this, nID: 1192);
    SendMessageA(hWnd: DlgItem->m_hWnd, Msg: 0xF1u, wParam: 1u, lParam: 0);
    v4 = CWnd::GetDlgItem(this, nID: 1560);
    SendMessageA(hWnd: v4->m_hWnd, Msg: 0xF1u, wParam: 0, lParam: 0);
    v5 = CWnd::GetDlgItem(this, nID: 1561);
    SendMessageA(hWnd: v5->m_hWnd, Msg: 0xF1u, wParam: 0, lParam: 0);
    CDispPaintDataDlg::FilterComboBoxBrushData(this, uiEffect: 0, bInit: false);
    CDispPaintDataDlg::OnComboBoxBrushData(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100C11B0
// Name: protected: void CDispPaintDataDlg::OnEffectRaiseToData(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDispPaintDataDlg::OnEffectRaiseToData(CDispPaintDataDlg *this)
{
  CToolDisplace *DisplacementTool; // eax
  CWnd *DlgItem; // eax
  CWnd *v4; // eax
  CWnd *v5; // eax

  DisplacementTool = GetDisplacementTool();
  if ( DisplacementTool != nullptr )
  {
    DisplacementTool->m_uiEffect = 1;
    DlgItem = CWnd::GetDlgItem(this, nID: 1192);
    SendMessageA(hWnd: DlgItem->m_hWnd, Msg: 0xF1u, wParam: 0, lParam: 0);
    v4 = CWnd::GetDlgItem(this, nID: 1560);
    SendMessageA(hWnd: v4->m_hWnd, Msg: 0xF1u, wParam: 1u, lParam: 0);
    v5 = CWnd::GetDlgItem(this, nID: 1561);
    SendMessageA(hWnd: v5->m_hWnd, Msg: 0xF1u, wParam: 0, lParam: 0);
    CDispPaintDataDlg::FilterComboBoxBrushData(this, uiEffect: 1u, bInit: false);
    CDispPaintDataDlg::OnComboBoxBrushData(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100C1240
// Name: protected: void CDispPaintDataDlg::OnEffectSmoothData(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDispPaintDataDlg::OnEffectSmoothData(CDispPaintDataDlg *this)
{
  CToolDisplace *DisplacementTool; // eax
  CWnd *DlgItem; // eax
  CWnd *v4; // eax
  CWnd *v5; // eax

  DisplacementTool = GetDisplacementTool();
  if ( DisplacementTool != nullptr )
  {
    DisplacementTool->m_uiEffect = 2;
    DlgItem = CWnd::GetDlgItem(this, nID: 1192);
    SendMessageA(hWnd: DlgItem->m_hWnd, Msg: 0xF1u, wParam: 0, lParam: 0);
    v4 = CWnd::GetDlgItem(this, nID: 1560);
    SendMessageA(hWnd: v4->m_hWnd, Msg: 0xF1u, wParam: 0, lParam: 0);
    v5 = CWnd::GetDlgItem(this, nID: 1561);
    SendMessageA(hWnd: v5->m_hWnd, Msg: 0xF1u, wParam: 1u, lParam: 0);
    CDispPaintDataDlg::FilterComboBoxBrushData(this, uiEffect: 2u, bInit: false);
    CDispPaintDataDlg::OnComboBoxBrushData(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100C12D0
// Name: protected: virtual struct AFX_MSGMAP const __near * CDispNoiseDlg::GetMessageMap(void)const
// Source: json
//------------------------------------------------------------------------------
const AFX_MSGMAP *__thiscall CDispNoiseDlg::GetMessageMap(CDispNoiseDlg *this)
{
  return (const AFX_MSGMAP *)&off_105E9730;
}

//------------------------------------------------------------------------------
// Address: 0x100C12E0
// Name: protected: void CDispPaintDistDlg::InitRadius(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDispPaintDistDlg::InitRadius(CDispPaintDistDlg *this)
{
  void *p_m_editRadius; // eax
  HWND__ *v3; // eax
  CWnd *DlgItem; // eax
  CToolDisplace *pTool; // [esp+Ch] [ebp-4h]

  p_m_editRadius = &this->m_editRadius;
  if ( this != (CDispPaintDistDlg *)-496 )
    p_m_editRadius = this->m_editRadius.m_hWnd;
  v3 = (HWND__ *)SendMessageA(hWnd: this->m_sliderRadius.m_hWnd, Msg: 0x420u, wParam: 0, lParam: (LPARAM)p_m_editRadius);
  CWnd::FromHandle(hWnd: v3);
  CSliderCtrl::SetRange(this: &this->m_sliderRadius, nMin: 1, nMax: 1024, bRedraw: 0);
  SendMessageA(hWnd: this->m_sliderRadius.m_hWnd, Msg: 0x414u, wParam: 0x10u, lParam: 0);
  pTool = GetDisplacementTool();
  if ( pTool != nullptr )
  {
    DlgItem = CWnd::GetDlgItem(this, nID: 1548);
    if ( pTool->m_bSpatial )
    {
      SendMessageA(hWnd: DlgItem->m_hWnd, Msg: 0xF1u, wParam: 1u, lParam: 0);
      CDispPaintDistDlg::EnableSliderRadius(this);
      CWnd::EnableWindow(this: &this->m_comboboxBrush, bEnable: 0);
    }
    else
    {
      SendMessageA(hWnd: DlgItem->m_hWnd, Msg: 0xF1u, wParam: 0, lParam: 0);
      CWnd::EnableWindow(this: &this->m_sliderRadius, bEnable: 0);
      CWnd::EnableWindow(this: &this->m_editRadius, bEnable: 0);
      CWnd::EnableWindow(this: &this->m_comboboxBrush, bEnable: 1);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100C13D0
// Name: protected: bool CDispPaintDistDlg::InitComboBoxBrushGeo(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDispPaintDistDlg::InitComboBoxBrushGeo(CDispPaintDistDlg *this)
{
  CWnd *DlgItem; // eax
  CToolDisplace *DisplacementTool; // eax
  unsigned int m_nPrevEffect; // ecx
  unsigned int v5; // ecx
  CWnd *v7; // eax
  CWnd *v8; // eax
  CWnd *v9; // eax
  CWnd *v10; // eax
  CWnd *v11; // eax
  CWnd *v12; // eax
  CWnd *v13; // eax
  CWnd *v14; // eax
  CWnd *v15; // eax

  DlgItem = CWnd::GetDlgItem(this, nID: 1007);
  CWnd::Attach(this: &this->m_comboboxBrush, hWndNew: DlgItem->m_hWnd);
  CIconComboBox::Init(this: &this->m_comboboxBrush);
  SendMessageA(
    hWnd: this->m_comboboxBrush.m_hWnd,
    Msg: 0x153u,
    wParam: 0xFFFFFFFF,
    lParam: (unsigned __int16)(LOWORD(this->m_comboboxBrush.m_IconSize.cy) + 2));
  DisplacementTool = GetDisplacementTool();
  if ( DisplacementTool != nullptr )
  {
    DisplacementTool->m_uiEffect = this->m_nPrevEffect;
    m_nPrevEffect = this->m_nPrevEffect;
    if ( m_nPrevEffect != 0 )
    {
      v5 = m_nPrevEffect - 1;
      if ( v5 != 0 )
      {
        if ( v5 == 1 )
        {
          DisplacementTool->m_uiEffect = 2;
          v7 = CWnd::GetDlgItem(this, nID: 1192);
          SendMessageA(hWnd: v7->m_hWnd, Msg: 0xF1u, wParam: 0, lParam: 0);
          v8 = CWnd::GetDlgItem(this, nID: 1541);
          SendMessageA(hWnd: v8->m_hWnd, Msg: 0xF1u, wParam: 0, lParam: 0);
          v9 = CWnd::GetDlgItem(this, nID: 1542);
          SendMessageA(hWnd: v9->m_hWnd, Msg: 0xF1u, wParam: 1u, lParam: 0);
          CDispPaintDistDlg::FilterComboBoxBrushGeo(this, nEffect: 2u, bInit: true);
          CDispPaintDistDlg::OnComboBoxBrushGeo(this);
          return 1;
        }
        else
        {
          return 0;
        }
      }
      else
      {
        DisplacementTool->m_uiEffect = 1;
        v10 = CWnd::GetDlgItem(this, nID: 1192);
        SendMessageA(hWnd: v10->m_hWnd, Msg: 0xF1u, wParam: 0, lParam: 0);
        v11 = CWnd::GetDlgItem(this, nID: 1541);
        SendMessageA(hWnd: v11->m_hWnd, Msg: 0xF1u, wParam: 1u, lParam: 0);
        v12 = CWnd::GetDlgItem(this, nID: 1542);
        SendMessageA(hWnd: v12->m_hWnd, Msg: 0xF1u, wParam: 0, lParam: 0);
        CDispPaintDistDlg::FilterComboBoxBrushGeo(this, nEffect: 1u, bInit: true);
        CDispPaintDistDlg::OnComboBoxBrushGeo(this);
        return 1;
      }
    }
    else
    {
      DisplacementTool->m_uiEffect = 0;
      v13 = CWnd::GetDlgItem(this, nID: 1192);
      SendMessageA(hWnd: v13->m_hWnd, Msg: 0xF1u, wParam: 1u, lParam: 0);
      v14 = CWnd::GetDlgItem(this, nID: 1541);
      SendMessageA(hWnd: v14->m_hWnd, Msg: 0xF1u, wParam: 0, lParam: 0);
      v15 = CWnd::GetDlgItem(this, nID: 1542);
      SendMessageA(hWnd: v15->m_hWnd, Msg: 0xF1u, wParam: 0, lParam: 0);
      CDispPaintDistDlg::FilterComboBoxBrushGeo(this, nEffect: 0, bInit: true);
      CDispPaintDistDlg::OnComboBoxBrushGeo(this);
      return 1;
    }
  }
  else
  {
    CDispPaintDistDlg::OnEffectRaiseLowerGeo(this);
    CDispPaintDistDlg::OnComboBoxBrushGeo(this);
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100C15B0
// Name: protected: bool CDispPaintDistDlg::InitComboBoxAxis(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDispPaintDistDlg::InitComboBoxAxis(CDispPaintDistDlg *this)
{
  CAfxStringMgr *StringManager; // eax
  CToolDisplace *DisplacementTool; // ebx
  LRESULT v4; // eax
  char *v5; // eax
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > strPaintDir; // [esp+Ch] [ebp-10h] BYREF
  int v8; // [esp+18h] [ebp-4h]

  StringManager = AfxGetStringManager();
  if ( StringManager == nullptr )
    ATL::AtlThrowImpl(hr: -2147467259);
  strPaintDir.m_pszData = (char *)&StringManager->GetNilString(this: StringManager)[1];
  v8 = 1;
  ATL::CSimpleStringT<char,0>::SetString(this: &strPaintDir, pszSrc: "X-Axis", nLength: 6);
  SendMessageA(hWnd: this->m_comboboxAxis.m_hWnd, Msg: 0x143u, wParam: 0, lParam: (LPARAM)strPaintDir.m_pszData);
  ATL::CSimpleStringT<char,0>::SetString(this: &strPaintDir, pszSrc: "Y-Axis", nLength: 6);
  SendMessageA(hWnd: this->m_comboboxAxis.m_hWnd, Msg: 0x143u, wParam: 0, lParam: (LPARAM)strPaintDir.m_pszData);
  ATL::CSimpleStringT<char,0>::SetString(this: &strPaintDir, pszSrc: "Z-Axis", nLength: 6);
  SendMessageA(hWnd: this->m_comboboxAxis.m_hWnd, Msg: 0x143u, wParam: 0, lParam: (LPARAM)strPaintDir.m_pszData);
  ATL::CSimpleStringT<char,0>::SetString(this: &strPaintDir, pszSrc: "Subdiv Normal", nLength: 13);
  SendMessageA(hWnd: this->m_comboboxAxis.m_hWnd, Msg: 0x143u, wParam: 0, lParam: (LPARAM)strPaintDir.m_pszData);
  ATL::CSimpleStringT<char,0>::SetString(this: &strPaintDir, pszSrc: "Face Normal", nLength: 11);
  SendMessageA(hWnd: this->m_comboboxAxis.m_hWnd, Msg: 0x143u, wParam: 0, lParam: (LPARAM)strPaintDir.m_pszData);
  DisplacementTool = GetDisplacementTool();
  if ( DisplacementTool != nullptr )
  {
    SendMessageA(hWnd: this->m_comboboxAxis.m_hWnd, Msg: 0x14Eu, wParam: this->m_nPrevPaintAxis, lParam: 0);
    DisplacementTool->m_iPaintAxis = this->m_nPrevPaintAxis;
    DisplacementTool->m_vecPaintAxis.x = this->m_vecPrevPaintAxis.x;
    DisplacementTool->m_vecPaintAxis.y = this->m_vecPrevPaintAxis.y;
    DisplacementTool->m_vecPaintAxis.z = this->m_vecPrevPaintAxis.z;
  }
  else
  {
    SendMessageA(hWnd: this->m_comboboxAxis.m_hWnd, Msg: 0x14Eu, wParam: 4u, lParam: 0);
    if ( GetDisplacementTool() != nullptr )
    {
      v4 = SendMessageA(hWnd: this->m_comboboxAxis.m_hWnd, Msg: 0x147u, wParam: 0, lParam: 0);
      if ( v4 != -1 )
        CDispPaintDistDlg::UpdateAxis(this, nAxis: v4);
    }
  }
  v8 = -1;
  v5 = strPaintDir.m_pszData - 16;
  if ( _InterlockedDecrement((volatile signed __int32 *)strPaintDir.m_pszData - 1) <= 0 )
    (*(void (__stdcall **)(char *))(**(_DWORD **)v5 + 4))(a1: v5);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100C1780
// Name: protected: bool CDispPaintDataDlg::InitComboBoxBrushData(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDispPaintDataDlg::InitComboBoxBrushData(CDispPaintDataDlg *this)
{
  CWnd *DlgItem; // eax
  CToolDisplace *DisplacementTool; // eax
  unsigned int m_uiPrevEffect; // ecx
  unsigned int v5; // ecx
  CWnd *v7; // eax
  CWnd *v8; // eax
  CWnd *v9; // eax
  CWnd *v10; // eax
  CWnd *v11; // eax
  CWnd *v12; // eax
  CWnd *v13; // eax
  CWnd *v14; // eax
  CWnd *v15; // eax

  DlgItem = CWnd::GetDlgItem(this, nID: 1007);
  CWnd::Attach(this: &this->m_comboboxBrush, hWndNew: DlgItem->m_hWnd);
  CIconComboBox::Init(this: &this->m_comboboxBrush);
  SendMessageA(
    hWnd: this->m_comboboxBrush.m_hWnd,
    Msg: 0x153u,
    wParam: 0xFFFFFFFF,
    lParam: (unsigned __int16)(LOWORD(this->m_comboboxBrush.m_IconSize.cy) + 2));
  DisplacementTool = GetDisplacementTool();
  if ( DisplacementTool != nullptr )
  {
    DisplacementTool->m_uiEffect = this->m_uiPrevEffect;
    m_uiPrevEffect = this->m_uiPrevEffect;
    if ( m_uiPrevEffect != 0 )
    {
      v5 = m_uiPrevEffect - 1;
      if ( v5 != 0 )
      {
        if ( v5 == 1 )
        {
          DisplacementTool->m_uiEffect = 2;
          v7 = CWnd::GetDlgItem(this, nID: 1192);
          SendMessageA(hWnd: v7->m_hWnd, Msg: 0xF1u, wParam: 0, lParam: 0);
          v8 = CWnd::GetDlgItem(this, nID: 1560);
          SendMessageA(hWnd: v8->m_hWnd, Msg: 0xF1u, wParam: 0, lParam: 0);
          v9 = CWnd::GetDlgItem(this, nID: 1561);
          SendMessageA(hWnd: v9->m_hWnd, Msg: 0xF1u, wParam: 1u, lParam: 0);
          CDispPaintDataDlg::FilterComboBoxBrushData(this, uiEffect: 2u, bInit: true);
          CDispPaintDataDlg::OnComboBoxBrushData(this);
          return 1;
        }
        else
        {
          return 0;
        }
      }
      else
      {
        DisplacementTool->m_uiEffect = 1;
        v10 = CWnd::GetDlgItem(this, nID: 1192);
        SendMessageA(hWnd: v10->m_hWnd, Msg: 0xF1u, wParam: 0, lParam: 0);
        v11 = CWnd::GetDlgItem(this, nID: 1560);
        SendMessageA(hWnd: v11->m_hWnd, Msg: 0xF1u, wParam: 1u, lParam: 0);
        v12 = CWnd::GetDlgItem(this, nID: 1561);
        SendMessageA(hWnd: v12->m_hWnd, Msg: 0xF1u, wParam: 0, lParam: 0);
        CDispPaintDataDlg::FilterComboBoxBrushData(this, uiEffect: 1u, bInit: true);
        CDispPaintDataDlg::OnComboBoxBrushData(this);
        return 1;
      }
    }
    else
    {
      DisplacementTool->m_uiEffect = 0;
      v13 = CWnd::GetDlgItem(this, nID: 1192);
      SendMessageA(hWnd: v13->m_hWnd, Msg: 0xF1u, wParam: 1u, lParam: 0);
      v14 = CWnd::GetDlgItem(this, nID: 1560);
      SendMessageA(hWnd: v14->m_hWnd, Msg: 0xF1u, wParam: 0, lParam: 0);
      v15 = CWnd::GetDlgItem(this, nID: 1561);
      SendMessageA(hWnd: v15->m_hWnd, Msg: 0xF1u, wParam: 0, lParam: 0);
      CDispPaintDataDlg::FilterComboBoxBrushData(this, uiEffect: 0, bInit: true);
      CDispPaintDataDlg::OnComboBoxBrushData(this);
      return 1;
    }
  }
  else
  {
    CDispPaintDataDlg::OnEffectRaiseLowerData(this);
    CDispPaintDataDlg::OnComboBoxBrushData(this);
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100C1960
// Name: public: virtual int CDispNoiseDlg::OnInitDialog(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDispNoiseDlg::OnInitDialog(CDispNoiseDlg *this)
{
  void *p_m_editMin; // eax
  HWND__ *v3; // eax
  void *p_m_editMax; // eax
  HWND__ *v5; // eax
  char *v6; // eax
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > strZero; // [esp+8h] [ebp-10h] BYREF
  int v9; // [esp+14h] [ebp-4h]

  CDialog::OnInitDialog(this);
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>(
    this: &strZero,
    pszSrc: "0.0");
  v9 = 0;
  CWnd::SetDlgItemTextA(this, nID: 1009, lpszString: strZero.m_pszData);
  CWnd::SetDlgItemTextA(this, nID: 1539, lpszString: strZero.m_pszData);
  p_m_editMin = &this->m_editMin;
  if ( this != (CDispNoiseDlg *)-156 )
    p_m_editMin = this->m_editMin.m_hWnd;
  v3 = (HWND__ *)SendMessageA(hWnd: this->m_spinMin.m_hWnd, Msg: 0x469u, wParam: (WPARAM)p_m_editMin, lParam: 0);
  CWnd::FromHandle(hWnd: v3);
  p_m_editMax = &this->m_editMax;
  if ( this != (CDispNoiseDlg *)-272 )
    p_m_editMax = this->m_editMax.m_hWnd;
  v5 = (HWND__ *)SendMessageA(hWnd: this->m_spinMax.m_hWnd, Msg: 0x469u, wParam: (WPARAM)p_m_editMax, lParam: 0);
  CWnd::FromHandle(hWnd: v5);
  v9 = -1;
  v6 = strZero.m_pszData - 16;
  if ( _InterlockedDecrement((volatile signed __int32 *)strZero.m_pszData - 1) <= 0 )
    (*(void (__stdcall **)(char *))(**(_DWORD **)v6 + 4))(a1: v6);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100C1A40
// Name: protected: virtual struct AFX_MSGMAP const __near * CDispPaintDistDlg::GetMessageMap(void)const
// Source: json
//------------------------------------------------------------------------------
const AFX_MSGMAP *__thiscall CDispPaintDistDlg::GetMessageMap(CDispPaintDistDlg *this)
{
  return (const AFX_MSGMAP *)&off_105E978C;
}

//------------------------------------------------------------------------------
// Address: 0x100C1A50
// Name: public: virtual int CDispPaintDistDlg::OnInitDialog(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDispPaintDistDlg::OnInitDialog(CDispPaintDistDlg *this)
{
  int result; // eax

  CDialog::OnInitDialog(this);
  result = (int)GetDisplacementTool();
  if ( result != 0 )
  {
    if ( *(_BYTE *)(result + 1173) == 0 )
      *(_BYTE *)(result + 1173) = 1;
    if ( bInit_1 )
    {
      CWnd::SetWindowPos(
        this,
        pWndInsertAfter: &CWnd::wndTop,
        x: this->m_DialogPosRect.left,
        y: this->m_DialogPosRect.top,
        cx: this->m_DialogPosRect.right - this->m_DialogPosRect.left,
        cy: this->m_DialogPosRect.bottom - this->m_DialogPosRect.top,
        nFlags: 4u);
    }
    else
    {
      this->m_flPrevDistance = 1.0;
      this->m_flPrevRadius = 1.0;
      this->m_nPrevBrush = 0;
      this->m_nPrevEffect = *(_DWORD *)(result + 16);
      this->m_nPrevPaintAxis = *(_DWORD *)(result + 1156);
      this->m_vecPrevPaintAxis.x = *(float *)(result + 1160);
      bInit_1 = true;
      this->m_vecPrevPaintAxis.y = *(float *)(result + 1164);
      this->m_vecPrevPaintAxis.z = *(float *)(result + 1168);
    }
    CDispPaintDistDlg::InitComboBoxBrushGeo(this);
    CDispPaintDistDlg::InitComboBoxAxis(this);
    CDispPaintDistDlg::InitDistance(this);
    CDispPaintDistDlg::InitRadius(this);
    CDispPaintDistDlg::InitBrushType(this);
    return 1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100C1B40
// Name: protected: virtual struct AFX_MSGMAP const __near * CDispPaintDataDlg::GetMessageMap(void)const
// Source: json
//------------------------------------------------------------------------------
const AFX_MSGMAP *__thiscall CDispPaintDataDlg::GetMessageMap(CDispPaintDataDlg *this)
{
  return (const AFX_MSGMAP *)&off_105E9934;
}

//------------------------------------------------------------------------------
// Address: 0x100C1B50
// Name: protected: bool CDispPaintDataDlg::InitComboBoxType(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDispPaintDataDlg::InitComboBoxType(CDispPaintDataDlg *this)
{
  char *v2; // eax
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > strType; // [esp+8h] [ebp-10h] BYREF
  int v5; // [esp+14h] [ebp-4h]

  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>(
    this: &strType,
    pszSrc: "Alpha");
  v5 = 0;
  SendMessageA(hWnd: this->m_comboboxType.m_hWnd, Msg: 0x143u, wParam: 0, lParam: (LPARAM)strType.m_pszData);
  SendMessageA(hWnd: this->m_comboboxType.m_hWnd, Msg: 0x14Eu, wParam: 0, lParam: 0);
  CWnd::EnableWindow(this: &this->m_comboboxType, bEnable: 0);
  v5 = -1;
  v2 = strType.m_pszData - 16;
  if ( _InterlockedDecrement((volatile signed __int32 *)strType.m_pszData - 1) <= 0 )
    (*(void (__stdcall **)(char *))(**(_DWORD **)v2 + 4))(a1: v2);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100C1C00
// Name: public: virtual int CDispPaintDataDlg::OnInitDialog(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDispPaintDataDlg::OnInitDialog(CDispPaintDataDlg *this)
{
  CToolDisplace *DisplacementTool; // eax

  CDialog::OnInitDialog(this);
  if ( bInit_2 )
  {
    CWnd::SetWindowPos(
      this,
      pWndInsertAfter: &CWnd::wndTop,
      x: this->m_DialogPosRect.left,
      y: this->m_DialogPosRect.top,
      cx: this->m_DialogPosRect.right - this->m_DialogPosRect.left,
      cy: this->m_DialogPosRect.bottom - this->m_DialogPosRect.top,
      nFlags: 4u);
  }
  else
  {
    DisplacementTool = GetDisplacementTool();
    if ( DisplacementTool != nullptr )
    {
      this->m_uiPrevEffect = DisplacementTool->m_uiEffect;
      this->m_fPrevPaintValue = DisplacementTool->m_flPaintValueData;
      this->m_iPrevBrush = 0;
      bInit_2 = true;
    }
  }
  CDispPaintDataDlg::InitValue(this);
  CDispPaintDataDlg::InitComboBoxBrushData(this);
  CDispPaintDataDlg::InitComboBoxType(this);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1034A9AF
// Name: public: virtual int CSliderCtrl::Create(unsigned long,struct tagRECT const __near &,class CWnd __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSliderCtrl::Create(
        CSliderCtrl *this,
        unsigned int dwStyle,
        const tagRECT *rect,
        CWnd *pParentWnd,
        unsigned int nID)
{
  AfxEndDeferRegisterClass(fToRegister: 4096);
  return this->Create(
           this,
           a2: "msctls_trackbar32",
           a3: nullptr,
           a4: dwStyle,
           a5: rect,
           a6: pParentWnd,
           a7: nID,
           a8: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x1034A9E2
// Name: public: virtual CSliderCtrl::~CSliderCtrl(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSliderCtrl::~CSliderCtrl(CSliderCtrl *this)
{
  this->__vftable = (CSliderCtrl_vtbl *)&CSliderCtrl::`vftable';
  CWnd::DestroyWindow(this);
  CWnd::~CWnd(this);
}

//------------------------------------------------------------------------------
// Address: 0x1034ABD2
// Name: public: virtual struct CRuntimeClass __near * CSliderCtrl::GetRuntimeClass(void)const
// Source: json
//------------------------------------------------------------------------------
CRuntimeClass *__thiscall CSliderCtrl::GetRuntimeClass(CSliderCtrl *this)
{
  return &CSliderCtrl::classCSliderCtrl;
}

//------------------------------------------------------------------------------
// Address: 0x1034ACEE
// Name: public: void CSliderCtrl::SetRange(int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSliderCtrl::SetRange(CSliderCtrl *this, LPARAM nMin, LPARAM nMax, WPARAM bRedraw)
{
  SendMessageA(hWnd: this->m_hWnd, Msg: 0x407u, wParam: bRedraw, lParam: nMin);
  SendMessageA(hWnd: this->m_hWnd, Msg: 0x408u, wParam: bRedraw, lParam: nMax);
}
