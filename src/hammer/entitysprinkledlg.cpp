// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: hammer/entitysprinkledlg.cpp
// Functions: 17
// ============================================================

#include "hammer\entitysprinkledlg.h"

//------------------------------------------------------------------------------
// Address: 0x100C88A0
// Name: public: virtual struct CRuntimeClass __near * CEntitySprinkleDlg::GetRuntimeClass(void)const
// Source: json
//------------------------------------------------------------------------------
CRuntimeClass *__thiscall CEntitySprinkleDlg::GetRuntimeClass(CEntitySprinkleDlg *this)
{
  return &CEntitySprinkleDlg::classCEntitySprinkleDlg;
}

//------------------------------------------------------------------------------
// Address: 0x100C88B0
// Name: public: virtual CEntitySprinkleDlg::~CEntitySprinkleDlg(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEntitySprinkleDlg::~CEntitySprinkleDlg(CEntitySprinkleDlg *this)
{
  this->__vftable = (CEntitySprinkleDlg_vtbl *)&CEntitySprinkleDlg::`vftable';
  CButton::~CButton(this: &this->m_RandomYawControl);
  CButton::~CButton(this: &this->m_DefinitionGridSizeControl);
  CStatic::~CStatic(this: &this->m_SprinkleDensityDisplayControl);
  CComboBox::~CComboBox(this: &this->m_SprinkleTypeControl);
  CEdit::~CEdit(this: &this->m_GridSizeYControl);
  CEdit::~CEdit(this: &this->m_GridSizeXControl);
  CEdit::~CEdit(this: &this->m_GridOffsetYControl);
  CEdit::~CEdit(this: &this->m_GridOffsetXControl);
  CSliderCtrl::~CSliderCtrl(this: &this->m_SprinkleDensityControl);
  CComboBox::~CComboBox(this: &this->m_SprinkleModeControl);
  CDialog::~CDialog(this);
}

//------------------------------------------------------------------------------
// Address: 0x100C8990
// Name: public: void CEntitySprinkleDlg::OnBnClickedSprinkleUseGrid(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEntitySprinkleDlg::OnBnClickedSprinkleUseGrid(CEntitySprinkleDlg *this)
{
  int m_nGridSpacing; // eax
  char temp[128]; // [esp+4h] [ebp-80h] BYREF

  if ( CMapDoc::m_pMapDoc != nullptr )
  {
    m_nGridSpacing = CMapDoc::m_pMapDoc->m_nGridSpacing;
    if ( m_nGridSpacing <= 1 )
      m_nGridSpacing = 1;
    sprintf(string: temp, format: "%d", m_nGridSpacing);
    CWnd::SetWindowTextA(this: &this->m_GridSizeXControl, lpszString: temp);
    CWnd::SetWindowTextA(this: &this->m_GridSizeYControl, lpszString: temp);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100C89F0
// Name: public: CEntitySprinkleDlg::CEntitySprinkleDlg(void)
// Source: json
//------------------------------------------------------------------------------
CEntitySprinkleDlg *__thiscall CEntitySprinkleDlg::CEntitySprinkleDlg(CEntitySprinkleDlg *this)
{
  CDialog::CDialog(this, nIDTemplate: 0x165u, pParentWnd: nullptr);
  this->__vftable = (CEntitySprinkleDlg_vtbl *)&CEntitySprinkleDlg::`vftable';
  CWnd::CWnd(this: &this->m_SprinkleModeControl);
  this->m_SprinkleModeControl.__vftable = (CComboBox_vtbl *)&CComboBox::`vftable';
  CWnd::CWnd(this: &this->m_SprinkleDensityControl);
  this->m_SprinkleDensityControl.__vftable = (CSliderCtrl_vtbl *)&CSliderCtrl::`vftable';
  CWnd::CWnd(this: &this->m_GridOffsetXControl);
  this->m_GridOffsetXControl.__vftable = (CEdit_vtbl *)&CEdit::`vftable';
  CWnd::CWnd(this: &this->m_GridOffsetYControl);
  this->m_GridOffsetYControl.__vftable = (CEdit_vtbl *)&CEdit::`vftable';
  CWnd::CWnd(this: &this->m_GridSizeXControl);
  this->m_GridSizeXControl.__vftable = (CEdit_vtbl *)&CEdit::`vftable';
  CWnd::CWnd(this: &this->m_GridSizeYControl);
  this->m_GridSizeYControl.__vftable = (CEdit_vtbl *)&CEdit::`vftable';
  CWnd::CWnd(this: &this->m_SprinkleTypeControl);
  this->m_SprinkleTypeControl.__vftable = (CComboBox_vtbl *)&CComboBox::`vftable';
  CWnd::CWnd(this: &this->m_SprinkleDensityDisplayControl);
  this->m_SprinkleDensityDisplayControl.__vftable = (CStatic_vtbl *)&CStatic::`vftable';
  CWnd::CWnd(this: &this->m_DefinitionGridSizeControl);
  this->m_DefinitionGridSizeControl.__vftable = (CButton_vtbl *)&CButton::`vftable';
  CWnd::CWnd(this: &this->m_RandomYawControl);
  this->m_RandomYawControl.__vftable = (CButton_vtbl *)&CButton::`vftable';
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100C8BA0
// Name: protected: virtual void CEntitySprinkleDlg::DoDataExchange(class CDataExchange __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEntitySprinkleDlg::DoDataExchange(CEntitySprinkleDlg *this, CDataExchange *pDX)
{
  DDX_Control(pDX, nIDC: (HWND__ *)0x6A8, rControl: (HWND__ *)&this->m_SprinkleModeControl);
  DDX_Control(pDX, nIDC: (HWND__ *)0x6A7, rControl: (HWND__ *)&this->m_SprinkleDensityControl);
  DDX_Control(pDX, nIDC: (HWND__ *)0x3F1, rControl: (HWND__ *)&this->m_GridOffsetXControl);
  DDX_Control(pDX, nIDC: (HWND__ *)0x6A9, rControl: (HWND__ *)&this->m_GridOffsetYControl);
  DDX_Control(pDX, nIDC: (HWND__ *)0x3F2, rControl: (HWND__ *)&this->m_GridSizeXControl);
  DDX_Control(pDX, nIDC: (HWND__ *)0x6AA, rControl: (HWND__ *)&this->m_GridSizeYControl);
  DDX_Control(pDX, nIDC: (HWND__ *)0x6AB, rControl: (HWND__ *)&this->m_SprinkleTypeControl);
  DDX_Control(pDX, nIDC: (HWND__ *)0x6AC, rControl: (HWND__ *)&this->m_SprinkleDensityDisplayControl);
  DDX_Control(pDX, nIDC: (HWND__ *)0x679, rControl: (HWND__ *)&this->m_DefinitionGridSizeControl);
  DDX_Control(pDX, nIDC: (HWND__ *)0x6AD, rControl: (HWND__ *)&this->m_RandomYawControl);
}

//------------------------------------------------------------------------------
// Address: 0x100C8C70
// Name: public: void CEntitySprinkleDlg::SetSprinkleTypes(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEntitySprinkleDlg::SetSprinkleTypes(CEntitySprinkleDlg *this, KeyValues *pSprinkleInfo)
{
  KeyValues *i; // esi
  const char *Name; // eax
  WPARAM v5; // eax
  WPARAM nSelection; // [esp+Ch] [ebp-8h]
  LRESULT nCount; // [esp+10h] [ebp-4h]

  nSelection = SendMessageA(hWnd: this->m_SprinkleTypeControl.m_hWnd, Msg: 0x147u, wParam: 0, lParam: 0);
  nCount = SendMessageA(hWnd: this->m_SprinkleTypeControl.m_hWnd, Msg: 0x146u, wParam: 0, lParam: 0);
  SendMessageA(hWnd: this->m_SprinkleTypeControl.m_hWnd, Msg: 0x14Bu, wParam: 0, lParam: 0);
  for ( i = KeyValues::GetFirstSubKey(this: pSprinkleInfo); i != nullptr; i = KeyValues::GetNextKey(this: i) )
  {
    Name = KeyValues::GetName(this: i);
    v5 = SendMessageA(hWnd: this->m_SprinkleTypeControl.m_hWnd, Msg: 0x143u, wParam: 0, lParam: (LPARAM)Name);
    SendMessageA(hWnd: this->m_SprinkleTypeControl.m_hWnd, Msg: 0x151u, wParam: v5, lParam: (LPARAM)i);
  }
  if ( nCount != 0 )
    SendMessageA(hWnd: this->m_SprinkleTypeControl.m_hWnd, Msg: 0x14Eu, wParam: nSelection, lParam: 0);
  else
    SendMessageA(hWnd: this->m_SprinkleTypeControl.m_hWnd, Msg: 0x14Eu, wParam: 0, lParam: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100C8D50
// Name: public: class KeyValues __near * CEntitySprinkleDlg::GetSprinkleType(void)
// Source: json
//------------------------------------------------------------------------------
KeyValues *__thiscall CEntitySprinkleDlg::GetSprinkleType(CEntitySprinkleDlg *this)
{
  WPARAM v2; // eax

  v2 = SendMessageA(hWnd: this->m_SprinkleTypeControl.m_hWnd, Msg: 0x147u, wParam: 0, lParam: 0);
  if ( v2 == -1 )
    return nullptr;
  else
    return (KeyValues *)SendMessageA(hWnd: this->m_SprinkleTypeControl.m_hWnd, Msg: 0x150u, wParam: v2, lParam: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100C8D90
// Name: public: int CEntitySprinkleDlg::GetSprinkleMode(void)
// Source: json
//------------------------------------------------------------------------------
LRESULT __thiscall CEntitySprinkleDlg::GetSprinkleMode(CEntitySprinkleDlg *this)
{
  return SendMessageA(hWnd: this->m_SprinkleModeControl.m_hWnd, Msg: 0x147u, wParam: 0, lParam: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100C8DB0
// Name: public: int CEntitySprinkleDlg::GetSprinkleDensity(void)
// Source: json
//------------------------------------------------------------------------------
LRESULT __thiscall CEntitySprinkleDlg::GetSprinkleDensity(CEntitySprinkleDlg *this)
{
  return SendMessageA(hWnd: this->m_SprinkleDensityControl.m_hWnd, Msg: 0x400u, wParam: 0, lParam: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100C8DD0
// Name: public: void CEntitySprinkleDlg::OnBnClickedSprinkleDefinitionGridSize(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEntitySprinkleDlg::OnBnClickedSprinkleDefinitionGridSize(CEntitySprinkleDlg *this)
{
  LRESULT v2; // eax
  CEdit *p_m_GridSizeXControl; // ecx

  v2 = SendMessageA(hWnd: this->m_DefinitionGridSizeControl.m_hWnd, Msg: 0xF0u, wParam: 0, lParam: 0);
  p_m_GridSizeXControl = &this->m_GridSizeXControl;
  if ( v2 == 1 )
  {
    CWnd::EnableWindow(this: p_m_GridSizeXControl, bEnable: 0);
    CWnd::EnableWindow(this: &this->m_GridSizeYControl, bEnable: 0);
  }
  else
  {
    CWnd::EnableWindow(this: p_m_GridSizeXControl, bEnable: 1);
    CWnd::EnableWindow(this: &this->m_GridSizeYControl, bEnable: 1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100C8E20
// Name: public: void CEntitySprinkleDlg::OnNMCustomdrawSprinkleDensity(struct tagNMHDR __near *,long __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEntitySprinkleDlg::OnNMCustomdrawSprinkleDensity(
        CEntitySprinkleDlg *this,
        tagNMHDR *pNMHDR,
        int *pResult)
{
  LRESULT v4; // eax
  char temp[128]; // [esp+4h] [ebp-80h] BYREF

  v4 = SendMessageA(hWnd: this->m_SprinkleDensityControl.m_hWnd, Msg: 0x400u, wParam: 0, lParam: 0);
  sprintf(string: temp, format: "%d%%", v4);
  CWnd::SetWindowTextA(this: &this->m_SprinkleDensityDisplayControl, lpszString: temp);
  *pResult = 0;
}

//------------------------------------------------------------------------------
// Address: 0x100C8E80
// Name: public: bool CEntitySprinkleDlg::UseDefinitionGridSize(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CEntitySprinkleDlg::UseDefinitionGridSize(CEntitySprinkleDlg *this)
{
  return SendMessageA(hWnd: this->m_DefinitionGridSizeControl.m_hWnd, Msg: 0xF0u, wParam: 0, lParam: 0) == 1;
}

//------------------------------------------------------------------------------
// Address: 0x100C8EA0
// Name: public: void CEntitySprinkleDlg::OnClose(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEntitySprinkleDlg::OnClose(CEntitySprinkleDlg *this)
{
  CToolManager *v2; // eax

  v2 = ToolManager();
  CToolManager::SetTool(this: v2, eNewTool: TOOL_PICK_ENTITY);
  CWnd::Default(this);
}

//------------------------------------------------------------------------------
// Address: 0x100C8EC0
// Name: public: bool CEntitySprinkleDlg::UseRandomYaw(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CEntitySprinkleDlg::UseRandomYaw(CEntitySprinkleDlg *this)
{
  return SendMessageA(hWnd: this->m_RandomYawControl.m_hWnd, Msg: 0xF0u, wParam: 0, lParam: 0) == 1;
}

//------------------------------------------------------------------------------
// Address: 0x100C8EE0
// Name: public: virtual int CEntitySprinkleDlg::OnInitDialog(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CEntitySprinkleDlg::OnInitDialog(CEntitySprinkleDlg *this)
{
  int m_nGridSpacing; // eax
  LRESULT v3; // eax
  CEdit *p_m_GridSizeXControl; // ecx
  char string[128]; // [esp+8h] [ebp-80h] BYREF

  CDialog::OnInitDialog(this);
  SendMessageA(hWnd: this->m_SprinkleModeControl.m_hWnd, Msg: 0x143u, wParam: 0, lParam: (LPARAM)"Additive");
  SendMessageA(hWnd: this->m_SprinkleModeControl.m_hWnd, Msg: 0x143u, wParam: 0, lParam: (LPARAM)"Subtractive");
  SendMessageA(hWnd: this->m_SprinkleModeControl.m_hWnd, Msg: 0x143u, wParam: 0, lParam: (LPARAM)"Replace");
  SendMessageA(hWnd: this->m_SprinkleModeControl.m_hWnd, Msg: 0x143u, wParam: 0, lParam: (LPARAM)"Overwrite");
  SendMessageA(hWnd: this->m_SprinkleModeControl.m_hWnd, Msg: 0x14Eu, wParam: 0, lParam: 0);
  CSliderCtrl::SetRange(this: &this->m_SprinkleDensityControl, nMin: 0, nMax: 100, bRedraw: 0);
  SendMessageA(hWnd: this->m_SprinkleDensityControl.m_hWnd, Msg: 0x414u, wParam: 0xAu, lParam: 0);
  SendMessageA(hWnd: this->m_SprinkleDensityControl.m_hWnd, Msg: 0x417u, wParam: 0, lParam: 10);
  SendMessageA(hWnd: this->m_SprinkleDensityControl.m_hWnd, Msg: 0x415u, wParam: 0, lParam: 10);
  SendMessageA(hWnd: this->m_SprinkleDensityControl.m_hWnd, Msg: 0x405u, wParam: 1u, lParam: 25);
  SendMessageA(hWnd: this->m_DefinitionGridSizeControl.m_hWnd, Msg: 0xF1u, wParam: 1u, lParam: 0);
  if ( CMapDoc::m_pMapDoc != nullptr )
  {
    m_nGridSpacing = CMapDoc::m_pMapDoc->m_nGridSpacing;
    if ( m_nGridSpacing <= 1 )
      m_nGridSpacing = 1;
    sprintf(string, format: "%d", m_nGridSpacing);
    CWnd::SetWindowTextA(this: &this->m_GridSizeXControl, lpszString: string);
    CWnd::SetWindowTextA(this: &this->m_GridSizeYControl, lpszString: string);
  }
  v3 = SendMessageA(hWnd: this->m_DefinitionGridSizeControl.m_hWnd, Msg: 0xF0u, wParam: 0, lParam: 0);
  p_m_GridSizeXControl = &this->m_GridSizeXControl;
  if ( v3 == 1 )
  {
    CWnd::EnableWindow(this: p_m_GridSizeXControl, bEnable: 0);
    CWnd::EnableWindow(this: &this->m_GridSizeYControl, bEnable: 0);
  }
  else
  {
    CWnd::EnableWindow(this: p_m_GridSizeXControl, bEnable: 1);
    CWnd::EnableWindow(this: &this->m_GridSizeYControl, bEnable: 1);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100C9060
// Name: protected: virtual struct AFX_MSGMAP const __near * CEntitySprinkleDlg::GetMessageMap(void)const
// Source: json
//------------------------------------------------------------------------------
const AFX_MSGMAP *__thiscall CEntitySprinkleDlg::GetMessageMap(CEntitySprinkleDlg *this)
{
  return (const AFX_MSGMAP *)&off_105EADB4;
}

//------------------------------------------------------------------------------
// Address: 0x100C9070
// Name: public: void CEntitySprinkleDlg::GetGridSize(float __near &,float __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEntitySprinkleDlg::GetGridSize(CEntitySprinkleDlg *this, float *flGridXSize, float *flGridYSize)
{
  CAfxStringMgr *StringManager; // eax
  char *v5; // eax
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > Text; // [esp+4h] [ebp-10h] BYREF
  int v7; // [esp+10h] [ebp-4h]

  StringManager = AfxGetStringManager();
  if ( StringManager == nullptr )
    ATL::AtlThrowImpl(hr: -2147467259);
  Text.m_pszData = (char *)&StringManager->GetNilString(this: StringManager)[1];
  v7 = 1;
  CWnd::GetWindowTextA(this: &this->m_GridSizeXControl, rString: &Text);
  *flGridXSize = atof(nptr: Text.m_pszData);
  CWnd::GetWindowTextA(this: &this->m_GridSizeYControl, rString: &Text);
  *flGridYSize = atof(nptr: Text.m_pszData);
  v7 = -1;
  v5 = Text.m_pszData - 16;
  if ( _InterlockedDecrement((volatile signed __int32 *)Text.m_pszData - 1) <= 0 )
    (*(void (__stdcall **)(char *))(**(_DWORD **)v5 + 4))(a1: v5);
}
