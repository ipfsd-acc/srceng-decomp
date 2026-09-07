// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: hammer/newvisgroupdlg.cpp
// Functions: 10
// ============================================================

#include "hammer\newvisgroupdlg.h"

//------------------------------------------------------------------------------
// Address: 0x100D5000
// Name: protected: virtual void CNewVisGroupDlg::OnOK(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNewVisGroupDlg::OnOK(CNewVisGroupDlg *this)
{
  CDialog::OnOK(this);
  s_bLastHideObjects = this->m_bHideObjects;
}

//------------------------------------------------------------------------------
// Address: 0x100D5020
// Name: protected: void CNewVisGroupDlg::OnPlaceInExistingVisGroup(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNewVisGroupDlg::OnPlaceInExistingVisGroup(CNewVisGroupDlg *this)
{
  CWnd *DlgItem; // eax
  CWnd *v3; // eax

  DlgItem = CWnd::GetDlgItem(this, nID: 1009);
  CWnd::EnableWindow(this: DlgItem, bEnable: 0);
  v3 = CWnd::GetDlgItem(this, nID: 1634);
  CWnd::EnableWindow(this: v3, bEnable: 1);
}

//------------------------------------------------------------------------------
// Address: 0x100D5050
// Name: protected: void CNewVisGroupDlg::OnCreateNewVisGroup(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNewVisGroupDlg::OnCreateNewVisGroup(CNewVisGroupDlg *this)
{
  CWnd *DlgItem; // eax
  CWnd *v3; // eax

  DlgItem = CWnd::GetDlgItem(this, nID: 1009);
  CWnd::EnableWindow(this: DlgItem, bEnable: 1);
  v3 = CWnd::GetDlgItem(this, nID: 1634);
  CWnd::EnableWindow(this: v3, bEnable: 0);
  this->m_pPickedVisGroup = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x100D5090
// Name: protected: long CNewVisGroupDlg::OnSelChangeGroupList(unsigned int,long)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CNewVisGroupDlg::OnSelChangeGroupList(CNewVisGroupDlg *this, unsigned int wParam, unsigned int lParam)
{
  this->m_pPickedVisGroup = (CVisGroup *)CTreeList::GetSelectedItem(this: &this->m_cGroupList);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x100D50B0
// Name: protected: virtual void CNewVisGroupDlg::DoDataExchange(class CDataExchange __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNewVisGroupDlg::DoDataExchange(CNewVisGroupDlg *this, CDataExchange *pDX)
{
  DDX_Check((HWND__ *)pDX, nIDC: (HWND__ *)0x661, value: &this->m_bRemoveFromOtherGroups);
  DDX_Check((HWND__ *)pDX, nIDC: (HWND__ *)0x663, value: &this->m_bHideObjects);
  DDX_Text(pDX, nIDC: (HWND__ *)0x3F1, value: &this->m_strName);
}

//------------------------------------------------------------------------------
// Address: 0x100D5100
// Name: protected: void CNewVisGroupDlg::UpdateGroupList(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNewVisGroupDlg::UpdateGroupList(CNewVisGroupDlg *this)
{
  CMapDoc *v2; // ebx
  int v3; // esi
  int nCount; // [esp+8h] [ebp-8h]
  CVisGroup *pGroup; // [esp+Ch] [ebp-4h]

  SendMessageA(hWnd: this->m_cGroupList.m_hWnd, Msg: 0xBu, wParam: 0, lParam: 0);
  CTreeList::DeleteAllItems(this: &this->m_cGroupList);
  v2 = CMapDoc::m_pMapDoc;
  if ( CMapDoc::m_pMapDoc != nullptr )
  {
    v3 = 0;
    nCount = CMapDoc::VisGroups_GetRootCount(this: CMapDoc::m_pMapDoc);
    if ( nCount > 0 )
    {
      do
      {
        pGroup = CMapDoc::VisGroups_GetRootVisGroup(this: v2, nIndex: v3);
        if ( _V_stricmp(s1: pGroup->m_szName, s2: "Auto") != 0 )
          CGroupList::AddVisGroup(this: &this->m_cGroupList, pVisGroup: pGroup);
        ++v3;
      }
      while ( v3 < nCount );
    }
  }
  CTreeList::ExpandAll(this: &this->m_cGroupList);
  SendMessageA(hWnd: this->m_cGroupList.m_hWnd, Msg: 0xBu, wParam: 1u, lParam: 0);
  InvalidateRect(hWnd: this->m_cGroupList.m_hWnd, lpRect: nullptr, bErase: true);
}

//------------------------------------------------------------------------------
// Address: 0x100D51B0
// Name: protected: virtual struct AFX_MSGMAP const __near * CNewVisGroupDlg::GetMessageMap(void)const
// Source: json
//------------------------------------------------------------------------------
const AFX_MSGMAP *__thiscall CNewVisGroupDlg::GetMessageMap(CNewVisGroupDlg *this)
{
  return (const AFX_MSGMAP *)&off_105EDA08;
}

//------------------------------------------------------------------------------
// Address: 0x100D51C0
// Name: protected: virtual int CNewVisGroupDlg::OnInitDialog(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CNewVisGroupDlg::OnInitDialog(CNewVisGroupDlg *this)
{
  CWnd *DlgItem; // eax
  CWnd *v3; // eax

  this->m_bHideObjects = s_bLastHideObjects;
  CDialog::OnInitDialog(this);
  DlgItem = CWnd::GetDlgItem(this, nID: 1643);
  SendMessageA(hWnd: DlgItem->m_hWnd, Msg: 0xF1u, wParam: 1u, lParam: 0);
  CWnd::SubclassDlgItem(this: &this->m_cGroupList, nID: 0x662u, pParent: this);
  CNewVisGroupDlg::UpdateGroupList(this);
  v3 = CWnd::GetDlgItem(this, nID: 1634);
  CWnd::EnableWindow(this: v3, bEnable: 0);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100D5230
// Name: public: CNewVisGroupDlg::CNewVisGroupDlg(class ATL::CStringT<char,class StrTraitMFC<char,class ATL::ChTraitsCRT<char>>> __near &,class CWnd __near *)
// Source: json
//------------------------------------------------------------------------------
CNewVisGroupDlg *__thiscall CNewVisGroupDlg::CNewVisGroupDlg(
        CNewVisGroupDlg *this,
        ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *str,
        CWnd *pParent)
{
  CAfxStringMgr *StringManager; // eax

  CDialog::CDialog(this, nIDTemplate: 0x142u, pParentWnd: pParent);
  this->__vftable = (CNewVisGroupDlg_vtbl *)&CNewVisGroupDlg::`vftable';
  CGroupList::CGroupList(this: &this->m_cGroupList);
  StringManager = AfxGetStringManager();
  if ( StringManager == nullptr )
    ATL::AtlThrowImpl(hr: -2147467259);
  this->m_strName.m_pszData = (char *)&StringManager->GetNilString(this: StringManager)[1];
  this->m_pPickedVisGroup = nullptr;
  ATL::CSimpleStringT<char,0>::operator=(this: &this->m_strName, strSrc: (ATL::CStringData *)str);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100D5380
// Name: public: void CNewVisGroupDlg::GetName(class ATL::CStringT<char,class StrTraitMFC<char,class ATL::ChTraitsCRT<char>>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNewVisGroupDlg::GetName(
        CNewVisGroupDlg *this,
        ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *str)
{
  ATL::CSimpleStringT<char,0>::operator=(this: str, strSrc: (ATL::CStringData *)&this->m_strName);
}
