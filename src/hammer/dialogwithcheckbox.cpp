// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: hammer/dialogwithcheckbox.cpp
// Functions: 9
// ============================================================

#include "hammer\dialogwithcheckbox.h"

//------------------------------------------------------------------------------
// Address: 0x100BE2A0
// Name: public: virtual struct CRuntimeClass __near * CDialogWithCheckbox::GetRuntimeClass(void)const
// Source: json
//------------------------------------------------------------------------------
CRuntimeClass *__thiscall CDialogWithCheckbox::GetRuntimeClass(CDialogWithCheckbox *this)
{
  return &CDialogWithCheckbox::classCDialogWithCheckbox;
}

//------------------------------------------------------------------------------
// Address: 0x100BE2B0
// Name: public: void CDialogWithCheckbox::OnBnClickedCancel(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDialogWithCheckbox::OnBnClickedCancel(CDialogWithCheckbox *this)
{
  void (*OnCancel)(void); // edx

  OnCancel = (void (*)(void))this->OnCancel;
  *(_WORD *)&this->m_bCheckMark = 0;
  OnCancel();
}

//------------------------------------------------------------------------------
// Address: 0x100BE2D0
// Name: public: bool CDialogWithCheckbox::IsCheckboxChecked(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDialogWithCheckbox::IsCheckboxChecked(CDialogWithCheckbox *this)
{
  return this->m_bCheckMark;
}

//------------------------------------------------------------------------------
// Address: 0x100BE2E0
// Name: protected: virtual void CDialogWithCheckbox::DoDataExchange(class CDataExchange __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDialogWithCheckbox::DoDataExchange(CDialogWithCheckbox *this, CDataExchange *pDX)
{
  DDX_Control(pDX, nIDC: (HWND__ *)0x6B5, rControl: (HWND__ *)&this->m_IconControl);
  DDX_Control(pDX, nIDC: (HWND__ *)0x6C3, rControl: (HWND__ *)&this->m_CheckmarkControl);
  DDX_Text(pDX, nIDC: (HWND__ *)0x6C4, value: &this->m_strDialogText);
  DDX_Text(pDX, nIDC: (HWND__ *)0x6C6, value: &this->m_strCheckboxText);
}

//------------------------------------------------------------------------------
// Address: 0x100BE340
// Name: public: void CDialogWithCheckbox::OnBnClickedOk(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDialogWithCheckbox::OnBnClickedOk(CDialogWithCheckbox *this)
{
  bool v2; // zf
  void (__thiscall *OnOK)(CDialog *); // eax

  v2 = SendMessageA(hWnd: this->m_CheckmarkControl.m_hWnd, Msg: 0xF0u, wParam: 0, lParam: 0) == 0;
  OnOK = this->OnOK;
  this->m_bCheckMark = !v2;
  this->m_bClickedOk = true;
  OnOK(this);
}

//------------------------------------------------------------------------------
// Address: 0x100BE380
// Name: public: virtual int CDialogWithCheckbox::OnInitDialog(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDialogWithCheckbox::OnInitDialog(CDialogWithCheckbox *this)
{
  CWnd *DlgItem; // eax
  HICON IconA; // eax

  CDialog::OnInitDialog(this);
  CWnd::SetWindowTextA(this, lpszString: this->m_strTitleText.m_pszData);
  SendMessageA(hWnd: this->m_CheckmarkControl.m_hWnd, Msg: 0xF1u, wParam: this->m_bDefaultCheckState, lParam: 0);
  if ( this->m_bCheckMarkDisabled )
  {
    CWnd::EnableWindow(this: &this->m_CheckmarkControl, bEnable: 0);
    DlgItem = CWnd::GetDlgItem(this, nID: 1734);
    CWnd::EnableWindow(this: DlgItem, bEnable: 0);
  }
  IconA = LoadIconA(hInstance: nullptr, lpIconName: (LPCSTR)0x7F01);
  SendMessageA(hWnd: this->m_IconControl.m_hWnd, Msg: 0x170u, wParam: (WPARAM)IconA, lParam: 0);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100BE410
// Name: public: virtual CDialogWithCheckbox::~CDialogWithCheckbox(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDialogWithCheckbox::~CDialogWithCheckbox(CDialogWithCheckbox *this)
{
  volatile signed __int32 *v2; // eax
  volatile signed __int32 *v3; // eax
  volatile signed __int32 *v4; // eax

  this->__vftable = (CDialogWithCheckbox_vtbl *)&CDialogWithCheckbox::`vftable';
  v2 = (volatile signed __int32 *)(this->m_strCheckboxText.m_pszData - 16);
  if ( _InterlockedDecrement(v2 + 3) <= 0 )
    (*(void (__stdcall **)(volatile signed __int32 *))(**(_DWORD **)v2 + 4))(a1: v2);
  v3 = (volatile signed __int32 *)(this->m_strDialogText.m_pszData - 16);
  if ( _InterlockedDecrement(v3 + 3) <= 0 )
    (*(void (__stdcall **)(volatile signed __int32 *))(**(_DWORD **)v3 + 4))(a1: v3);
  v4 = (volatile signed __int32 *)(this->m_strTitleText.m_pszData - 16);
  if ( _InterlockedDecrement(v4 + 3) <= 0 )
    (*(void (__stdcall **)(volatile signed __int32 *))(**(_DWORD **)v4 + 4))(a1: v4);
  CStatic::~CStatic(this: &this->m_IconControl);
  CButton::~CButton(this: &this->m_CheckmarkControl);
  CStatic::~CStatic(this: &this->m_DialogTextControl);
  CDialog::~CDialog(this);
}

//------------------------------------------------------------------------------
// Address: 0x100BE520
// Name: protected: virtual struct AFX_MSGMAP const __near * CDialogWithCheckbox::GetMessageMap(void)const
// Source: json
//------------------------------------------------------------------------------
const AFX_MSGMAP *__thiscall CDialogWithCheckbox::GetMessageMap(CDialogWithCheckbox *this)
{
  return (const AFX_MSGMAP *)&off_105E8AB4;
}

//------------------------------------------------------------------------------
// Address: 0x100BE560
// Name: public: CDialogWithCheckbox::CDialogWithCheckbox(char const __near *,char const __near *,char const __near *,bool,bool,class CWnd __near *)
// Source: json
//------------------------------------------------------------------------------
CDialogWithCheckbox *__thiscall CDialogWithCheckbox::CDialogWithCheckbox(
        CDialogWithCheckbox *this,
        const char *pszTitleText,
        const char *pszDialogText,
        const char *pszCheckboxText,
        bool bCheckState,
        bool bDisabled,
        CWnd *pParent)
{
  CAfxStringMgr *StringManager; // eax
  int v9; // eax
  int v10; // eax
  int v11; // eax

  CDialog::CDialog(this, nIDTemplate: 0x167u, pParentWnd: pParent);
  this->__vftable = (CDialogWithCheckbox_vtbl *)&CDialogWithCheckbox::`vftable';
  CWnd::CWnd(this: &this->m_DialogTextControl);
  this->m_DialogTextControl.__vftable = (CStatic_vtbl *)&CStatic::`vftable';
  CWnd::CWnd(this: &this->m_CheckmarkControl);
  this->m_CheckmarkControl.__vftable = (CButton_vtbl *)&CButton::`vftable';
  CWnd::CWnd(this: &this->m_IconControl);
  this->m_IconControl.__vftable = (CStatic_vtbl *)&CStatic::`vftable';
  StringManager = AfxGetStringManager();
  if ( StringManager == nullptr )
    ATL::AtlThrowImpl(hr: -2147467259);
  this->m_strTitleText.m_pszData = (char *)&StringManager->GetNilString(this: StringManager)[1];
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>(
    this: &this->m_strDialogText,
    pszSrc: &var);
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>(
    this: &this->m_strCheckboxText,
    pszSrc: &var);
  this->m_bCheckMarkDisabled = bDisabled;
  this->m_bDefaultCheckState = bCheckState;
  *(_WORD *)&this->m_bCheckMark = 0;
  if ( pszTitleText != nullptr )
    v9 = strlen(pszTitleText);
  else
    v9 = 0;
  ATL::CSimpleStringT<char,0>::SetString(this: &this->m_strTitleText, pszSrc: pszTitleText, nLength: v9);
  if ( pszDialogText != nullptr )
    v10 = strlen(pszDialogText);
  else
    v10 = 0;
  ATL::CSimpleStringT<char,0>::SetString(this: &this->m_strDialogText, pszSrc: pszDialogText, nLength: v10);
  if ( pszCheckboxText != nullptr )
    v11 = strlen(pszCheckboxText);
  else
    v11 = 0;
  ATL::CSimpleStringT<char,0>::SetString(this: &this->m_strCheckboxText, pszSrc: pszCheckboxText, nLength: v11);
  return this;
}
