// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: hammer/editprefabdlg.cpp
// Functions: 7
// ============================================================

#include "hammer\editprefabdlg.h"

//------------------------------------------------------------------------------
// Address: 0x100C5B00
// Name: public: void CEditPrefabDlg::SetRanges(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEditPrefabDlg::SetRanges(CEditPrefabDlg *this, int iMaxDescript, int iMaxName)
{
  if ( iMaxDescript != -1 )
    this->iMaxDescriptChars = iMaxDescript;
  if ( iMaxName != -1 )
    this->iMaxNameChars = iMaxName;
}

//------------------------------------------------------------------------------
// Address: 0x100C5B30
// Name: protected: virtual void CEditPrefabDlg::DoDataExchange(class CDataExchange __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEditPrefabDlg::DoDataExchange(CEditPrefabDlg *this, CDataExchange *pDX)
{
  DDX_Control(pDX, nIDC: (HWND__ *)0x3EF, rControl: (HWND__ *)&this->m_CreateIn);
  DDX_Control(pDX, nIDC: (HWND__ *)0x3F1, rControl: (HWND__ *)&this->m_Name);
  DDX_Control(pDX, nIDC: (HWND__ *)0x4B4, rControl: (HWND__ *)&this->m_Descript);
  DDX_Text(pDX, nIDC: (HWND__ *)0x4B4, value: &this->m_strDescript);
  DDX_Text(pDX, nIDC: (HWND__ *)0x3F1, value: &this->m_strName);
  DDV_MaxChars(pDX, value: &this->m_strDescript, nChars: this->iMaxDescriptChars);
  DDV_MaxChars(pDX, value: &this->m_strName, nChars: this->iMaxNameChars);
}

//------------------------------------------------------------------------------
// Address: 0x100C5BC0
// Name: protected: void CEditPrefabDlg::OnSelchangeCreatein(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEditPrefabDlg::OnSelchangeCreatein(CEditPrefabDlg *this)
{
  WPARAM v2; // eax

  v2 = SendMessageA(hWnd: this->m_CreateIn.m_hWnd, Msg: 0x147u, wParam: 0, lParam: 0);
  this->m_dwLibraryID = SendMessageA(hWnd: this->m_CreateIn.m_hWnd, Msg: 0x150u, wParam: v2, lParam: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100C5C00
// Name: protected: virtual int CEditPrefabDlg::OnInitDialog(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CEditPrefabDlg::OnInitDialog(CEditPrefabDlg *this)
{
  CWnd *DlgItem; // eax
  CPrefabLibrary *i; // edi
  WPARAM v5; // eax
  WPARAM v6; // eax
  __POSITION *p; // [esp+8h] [ebp-4h] BYREF

  CDialog::OnInitDialog(this);
  if ( this->m_bEnableLibrary != 0 )
  {
    CWnd::SetWindowTextA(this, lpszString: "Create Prefab");
    p = (__POSITION *)1;
    for ( i = CPrefabLibrary::EnumLibraries(&p, eType: LibType_None);
          i != nullptr;
          i = CPrefabLibrary::EnumLibraries(&p, eType: LibType_None) )
    {
      v5 = SendMessageA(hWnd: this->m_CreateIn.m_hWnd, Msg: 0x143u, wParam: 0, lParam: (LPARAM)i->m_szName);
      SendMessageA(hWnd: this->m_CreateIn.m_hWnd, Msg: 0x151u, wParam: v5, lParam: i->dwID);
    }
    SendMessageA(hWnd: this->m_CreateIn.m_hWnd, Msg: 0x14Eu, wParam: 0, lParam: 0);
    v6 = SendMessageA(hWnd: this->m_CreateIn.m_hWnd, Msg: 0x147u, wParam: 0, lParam: 0);
    this->m_dwLibraryID = SendMessageA(hWnd: this->m_CreateIn.m_hWnd, Msg: 0x150u, wParam: v6, lParam: 0);
    return 1;
  }
  else
  {
    DlgItem = CWnd::GetDlgItem(this, nID: 1207);
    SendMessageA(hWnd: DlgItem->m_hWnd, Msg: 0xBu, wParam: 0, lParam: 0);
    SendMessageA(hWnd: this->m_CreateIn.m_hWnd, Msg: 0xBu, wParam: 0, lParam: 0);
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100C5D10
// Name: protected: virtual struct AFX_MSGMAP const __near * CEditPrefabDlg::GetMessageMap(void)const
// Source: json
//------------------------------------------------------------------------------
const AFX_MSGMAP *__thiscall CEditPrefabDlg::GetMessageMap(CEditPrefabDlg *this)
{
  return (const AFX_MSGMAP *)&off_105EA3B0;
}

//------------------------------------------------------------------------------
// Address: 0x100C5D20
// Name: public: CEditPrefabDlg::CEditPrefabDlg(class CWnd __near *)
// Source: json
//------------------------------------------------------------------------------
CEditPrefabDlg *__thiscall CEditPrefabDlg::CEditPrefabDlg(CEditPrefabDlg *this, CWnd *pParent)
{
  CAfxStringMgr *StringManager; // eax
  CAfxStringMgr *v4; // eax

  CDialog::CDialog(this, nIDTemplate: 0xCEu, pParentWnd: pParent);
  this->__vftable = (CEditPrefabDlg_vtbl *)&CEditPrefabDlg::`vftable';
  CWnd::CWnd(this: &this->m_CreateIn);
  this->m_CreateIn.__vftable = (CComboBox_vtbl *)&CComboBox::`vftable';
  CWnd::CWnd(this: &this->m_Name);
  this->m_Name.__vftable = (CEdit_vtbl *)&CEdit::`vftable';
  CWnd::CWnd(this: &this->m_Descript);
  this->m_Descript.__vftable = (CEdit_vtbl *)&CEdit::`vftable';
  StringManager = AfxGetStringManager();
  if ( StringManager == nullptr )
    ATL::AtlThrowImpl(hr: -2147467259);
  this->m_strDescript.m_pszData = (char *)&StringManager->GetNilString(this: StringManager)[1];
  v4 = AfxGetStringManager();
  if ( v4 == nullptr )
    ATL::AtlThrowImpl(hr: -2147467259);
  this->m_strName.m_pszData = (char *)&v4->GetNilString(this: v4)[1];
  ATL::CSimpleStringT<char,0>::SetString(this: &this->m_strDescript, pszSrc: &var, nLength: 0);
  ATL::CSimpleStringT<char,0>::SetString(this: &this->m_strName, pszSrc: &var, nLength: 0);
  this->iMaxDescriptChars = 80;
  this->iMaxNameChars = 30;
  this->m_bEnableLibrary = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100C5E80
// Name: public: virtual CEditPrefabDlg::~CEditPrefabDlg(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEditPrefabDlg::~CEditPrefabDlg(CEditPrefabDlg *this)
{
  volatile signed __int32 *v2; // eax
  volatile signed __int32 *v3; // eax

  v2 = (volatile signed __int32 *)(this->m_strName.m_pszData - 16);
  if ( _InterlockedDecrement(v2 + 3) <= 0 )
    (*(void (__stdcall **)(volatile signed __int32 *))(**(_DWORD **)v2 + 4))(a1: v2);
  v3 = (volatile signed __int32 *)(this->m_strDescript.m_pszData - 16);
  if ( _InterlockedDecrement(v3 + 3) <= 0 )
    (*(void (__stdcall **)(volatile signed __int32 *))(**(_DWORD **)v3 + 4))(a1: v3);
  CEdit::~CEdit(this: &this->m_Descript);
  CEdit::~CEdit(this: &this->m_Name);
  CComboBox::~CComboBox(this: &this->m_CreateIn);
  CDialog::~CDialog(this);
}
