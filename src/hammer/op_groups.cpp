// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: hammer/op_groups.cpp
// Functions: 14
// ============================================================

#include "hammer\op_groups.h"

//------------------------------------------------------------------------------
// Address: 0x100D53E0
// Name: public: virtual void COP_Groups::SetMultiEdit(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COP_Groups::SetMultiEdit(CObjectPage *this, bool b)
{
  this->m_bMultiEdit = b;
}

//------------------------------------------------------------------------------
// Address: 0x100E4B90
// Name: public: virtual struct CRuntimeClass __near * COP_Groups::GetRuntimeClass(void)const
// Source: json
//------------------------------------------------------------------------------
CRuntimeClass *__thiscall COP_Groups::GetRuntimeClass(COP_Groups *this)
{
  return &COP_Groups::classCOP_Groups;
}

//------------------------------------------------------------------------------
// Address: 0x100E4BA0
// Name: protected: long COP_Groups::OnListToggleState(unsigned int,long)
// Source: json
//------------------------------------------------------------------------------
int __thiscall COP_Groups::OnListToggleState(
        COP_Groups *this,
        CParticleOperatorDefinition<C_OP_RenderProjected> *wParam,
        int lParam)
{
  if ( !CParticleOperatorDefinition<C_INIT_RandomTrailLength>::IsObsolete(this: wParam) )
    CTreeList::SetCheck(this: &this->m_cGroups, pItem: wParam, nCheckState: lParam);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x100E4BD0
// Name: protected: void COP_Groups::OnSetFocus(class CWnd __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COP_Groups::OnSetFocus(COP_Groups *this, CWnd *pOld)
{
  CWnd::OnSetFocus(this, __formal: pOld);
}

//------------------------------------------------------------------------------
// Address: 0x100E4BE0
// Name: protected: void COP_Groups::OnSize(unsigned int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COP_Groups::OnSize(COP_Groups *this, unsigned int nType, unsigned int cx, int cy)
{
  CAnchorMgr::OnSize(this: &this->m_AnchorMgr);
}

//------------------------------------------------------------------------------
// Address: 0x100E4BF0
// Name: protected: virtual void COP_Groups::DoDataExchange(class CDataExchange __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COP_Groups::DoDataExchange(COP_Groups *this, CDataExchange *pDX)
{
  DDX_Control(pDX, nIDC: (HWND__ *)0x443, rControl: (HWND__ *)&this->m_EditGroupsControl);
}

//------------------------------------------------------------------------------
// Address: 0x100E4C10
// Name: public: void COP_Groups::UpdateGroupList(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COP_Groups::UpdateGroupList(COP_Groups *this)
{
  COP_Groups *v1; // esi
  int v2; // ebx
  CMapDoc *v3; // edi
  CVisGroup *RootVisGroup; // esi
  int nCount; // [esp+4h] [ebp-Ch]
  CVisGroup *pAuto; // [esp+8h] [ebp-8h]

  v1 = this;
  if ( IsWindow(hWnd: this->m_hWnd) )
  {
    v2 = 0;
    SendMessageA(hWnd: v1->m_cGroups.m_hWnd, Msg: 0xBu, wParam: 0, lParam: 0);
    CTreeList::DeleteAllItems(this: &v1->m_cGroups);
    v3 = CMapDoc::m_pMapDoc;
    pAuto = nullptr;
    if ( CMapDoc::m_pMapDoc != nullptr )
    {
      nCount = CMapDoc::VisGroups_GetRootCount(this: CMapDoc::m_pMapDoc);
      if ( nCount > 0 )
      {
        do
        {
          RootVisGroup = CMapDoc::VisGroups_GetRootVisGroup(this: v3, nIndex: v2);
          if ( _V_stricmp(s1: RootVisGroup->m_szName, s2: "Auto") != 0 )
            CGroupList::AddVisGroup(this: &this->m_cGroups, pVisGroup: RootVisGroup);
          else
            pAuto = RootVisGroup;
          ++v2;
        }
        while ( v2 < nCount );
        if ( pAuto != nullptr )
          CGroupList::AddVisGroup(this: &this->m_cGroups, pVisGroup: pAuto);
        v1 = this;
      }
    }
    CTreeList::ExpandAll(this: &v1->m_cGroups);
    if ( pAuto != nullptr )
      CTreeList::CollapseItem(this: &v1->m_cGroups, pItem: pAuto);
    SendMessageA(hWnd: v1->m_cGroups.m_hWnd, Msg: 0xBu, wParam: 1u, lParam: 0);
    InvalidateRect(hWnd: v1->m_cGroups.m_hWnd, lpRect: nullptr, bErase: true);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E4D10
// Name: protected: virtual int COP_Groups::OnInitDialog(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall COP_Groups::OnInitDialog(COP_Groups *this)
{
  HWND__ *m_hWnd; // eax
  CAnchorDef anchorDefs[2]; // [esp+8h] [ebp-58h] BYREF

  CDialog::OnInitDialog(this);
  CWnd::SubclassDlgItem(this: &this->m_cGroups, nID: 0x449u, pParent: this);
  CTreeList::EnableChecks(this: &this->m_cGroups);
  CAnchorDef::CAnchorDef(this: anchorDefs, dlgItemID: 1097, eSimpleAnchor: k_eSimpleAnchorAllSides);
  CAnchorDef::CAnchorDef(this: &anchorDefs[1], dlgItemID: 1091, eSimpleAnchor: k_eSimpleAnchorBottomRight);
  if ( this != nullptr )
    m_hWnd = this->m_hWnd;
  else
    m_hWnd = nullptr;
  CAnchorMgr::Init(this: &this->m_AnchorMgr, hParentWnd: m_hWnd, pAnchors: anchorDefs, nAnchors: 2);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100E4D90
// Name: public: virtual void COP_Groups::UpdateData(int,void __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COP_Groups::UpdateData(COP_Groups *this, int Mode, CMapClass *pData, bool bCanEdit)
{
  COP_Groups *v4; // edi
  CTreeList *p_m_cGroups; // edi
  int v6; // ebx
  int i; // esi
  CClassOutput *v8; // eax
  int v9; // ebx
  int j; // esi
  CVisGroup *v11; // eax
  int ItemCount; // eax
  int v13; // esi
  CVisGroup *Output; // eax
  int nCount; // [esp+1Ch] [ebp+10h]

  v4 = this;
  CObjectPage::UpdateData(this, Mode, pData, bCanEdit);
  if ( IsWindow(hWnd: v4->m_hWnd) )
  {
    if ( Mode == 1 )
    {
      ItemCount = CTreeList::GetItemCount(this: &v4->m_cGroups);
      v13 = 0;
      for ( nCount = ItemCount; v13 < nCount; ++v13 )
      {
        if ( s_checkState[v13] != -1 )
        {
          Output = (CVisGroup *)GDclass::GetOutput(this: (GDclass *)&v4->m_cGroups, nIndex: v13);
          if ( CMapClass::IsInVisGroup(this: pData, pVisGroup: Output) != s_checkState[v13] )
            s_checkState[v13] = -1;
        }
      }
    }
    else if ( Mode != 0 )
    {
      if ( Mode == 2 )
      {
        p_m_cGroups = &v4->m_cGroups;
        v6 = CTreeList::GetItemCount(this: p_m_cGroups);
        for ( i = 0; i < v6; ++i )
        {
          v8 = GDclass::GetOutput(this: (GDclass *)p_m_cGroups, nIndex: i);
          CTreeList::SetCheck(this: p_m_cGroups, pItem: v8, nCheckState: s_checkState[i]);
        }
        v4 = this;
      }
    }
    else
    {
      COP_Groups::UpdateGroupList(this: v4);
      v9 = CTreeList::GetItemCount(this: &v4->m_cGroups);
      for ( j = 0; j < v9; ++j )
      {
        v11 = (CVisGroup *)GDclass::GetOutput(this: (GDclass *)&v4->m_cGroups, nIndex: j);
        s_checkState[j] = CMapClass::IsInVisGroup(this: pData, pVisGroup: v11);
      }
    }
    CWnd::EnableWindow(this: &v4->m_cGroups, bEnable: v4->m_bCanEdit);
    CWnd::EnableWindow(this: &v4->m_EditGroupsControl, bEnable: v4->m_bCanEdit);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E4EE0
// Name: protected: void COP_Groups::OnEditgroups(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COP_Groups::OnEditgroups(COP_Groups *this)
{
  CEditGroups dlg; // [esp+4h] [ebp-250h] BYREF
  CColorBox *p_m_cColorBox; // [esp+244h] [ebp-10h]
  int v4; // [esp+250h] [ebp-4h]

  CEditGroups::CEditGroups(this: &dlg, pParent: nullptr);
  v4 = 0;
  CDialog::DoModal(this: &dlg);
  COP_Groups::UpdateGroupList(this);
  v4 = 3;
  p_m_cColorBox = &dlg.m_cColorBox;
  CStatic::~CStatic(this: &dlg.m_cColorBox);
  LOBYTE(v4) = 2;
  CGroupList::~CGroupList(this: &dlg.m_cGroupList);
  LOBYTE(v4) = 1;
  CEdit::~CEdit(this: &dlg.m_cName);
  v4 = -1;
  CDialog::~CDialog(this: &dlg);
}

//------------------------------------------------------------------------------
// Address: 0x100E4F80
// Name: protected: virtual struct AFX_MSGMAP const __near * COP_Groups::GetMessageMap(void)const
// Source: json
//------------------------------------------------------------------------------
const AFX_MSGMAP *__thiscall COP_Groups::GetMessageMap(COP_Groups *this)
{
  return (const AFX_MSGMAP *)&off_105EEF2C;
}

//------------------------------------------------------------------------------
// Address: 0x100E4F90
// Name: public: COP_Groups::COP_Groups(void)
// Source: json
//------------------------------------------------------------------------------
COP_Groups *__thiscall COP_Groups::COP_Groups(COP_Groups *this)
{
  CPropertyPage::CPropertyPage(this, nIDTemplate: 0x94u, nIDCaption: 0, dwSize: 0x38u);
  this->__vftable = (COP_Groups_vtbl *)&CObjectPage::`vftable';
  this->m_bMultiEdit = false;
  this->m_bFirstTimeActive = false;
  this->__vftable = (COP_Groups_vtbl *)&COP_Groups::`vftable';
  CAnchorMgr::CAnchorMgr(this: &this->m_AnchorMgr);
  CGroupList::CGroupList(this: &this->m_cGroups);
  CWnd::CWnd(this: &this->m_EditGroupsControl);
  this->m_EditGroupsControl.__vftable = (CButton_vtbl *)&CButton::`vftable';
  this->m_pEditObjectRuntimeClass = &editCMapClass::classeditCMapClass;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100E50E0
// Name: public: virtual bool COP_Groups::SaveData(enum SaveData_Reason_t)
// Source: json
//------------------------------------------------------------------------------
char __thiscall COP_Groups::SaveData(COP_Groups *this, SaveData_Reason_t reason)
{
  COP_Groups *v2; // ebx
  CVisGroup *Output; // esi
  const CUtlReferenceVector<CMapClass> *m_pObjectList; // edx
  int j; // esi
  CMapClass *m_pObject; // eax
  CUtlReference<CMapClass> *v8; // ecx
  CMapClass *v9; // ecx
  HWND__ *m_hWnd; // [esp-4h] [ebp-34h]
  CUtlReference<CMapClass> *m_pHead; // [esp+4h] [ebp-2Ch] BYREF
  CUtlReference<CMapClass> *v12; // [esp+8h] [ebp-28h]
  CMapClass *v13; // [esp+Ch] [ebp-24h]
  int nCount; // [esp+10h] [ebp-20h]
  COP_Groups *v15; // [esp+14h] [ebp-1Ch]
  int nCheck; // [esp+18h] [ebp-18h]
  CVisGroup *pVisGroup; // [esp+1Ch] [ebp-14h]
  int i; // [esp+20h] [ebp-10h]
  int v19; // [esp+2Ch] [ebp-4h]

  v2 = this;
  m_hWnd = this->m_hWnd;
  v15 = this;
  if ( !IsWindow(hWnd: m_hWnd) )
    return 0;
  nCount = CTreeList::GetItemCount(this: &v2->m_cGroups);
  for ( i = 0; i < nCount; ++i )
  {
    Output = (CVisGroup *)GDclass::GetOutput(this: (GDclass *)&v2->m_cGroups, nIndex: i);
    pVisGroup = Output;
    if ( !CParticleOperatorDefinition<C_INIT_RandomTrailLength>::IsObsolete(this: (CParticleOperatorDefinition<C_OP_RenderProjected> *)Output) )
    {
      nCheck = CTreeList::GetCheck(this: &v2->m_cGroups, pItem: Output);
      if ( nCheck != -1 )
      {
        m_pObjectList = v2->m_pObjectList;
        for ( j = 0; j < m_pObjectList->m_Size; ++j )
        {
          m_pObject = m_pObjectList->m_Memory.m_pMemory[j >> (*((int *)&m_pObjectList->m_Memory + 2) >> 27)][j & ((32 * *((_DWORD *)&m_pObjectList->m_Memory + 2)) >> 5)].m_pObject;
          if ( m_pObject != nullptr )
          {
            v13 = m_pObjectList->m_Memory.m_pMemory[j >> (*((int *)&m_pObjectList->m_Memory + 2) >> 27)][j & ((32 * *((_DWORD *)&m_pObjectList->m_Memory + 2)) >> 5)].m_pObject;
            m_pHead = m_pObject->m_References.m_pHead;
            v8 = m_pObject->m_References.m_pHead;
            if ( v8 != nullptr )
              v8->m_pPrev = (CUtlReference<CMapClass> *)&m_pHead;
            v12 = nullptr;
            m_pObject->m_References.m_pHead = (CUtlReference<CMapClass> *)&m_pHead;
          }
          v9 = v13;
          v19 = -1;
          if ( v13 != nullptr )
          {
            if ( v12 != nullptr )
            {
              v12->m_pNext = m_pHead;
              if ( m_pHead != nullptr )
                m_pHead->m_pPrev = v12;
            }
            else if ( (CUtlReference<CMapClass> **)v13->m_References.m_pHead == &m_pHead )
            {
              v13->m_References.m_pHead = m_pHead;
              if ( m_pHead != nullptr )
                m_pHead->m_pPrev = nullptr;
            }
            v12 = nullptr;
            m_pHead = nullptr;
            v13 = nullptr;
          }
          if ( nCheck != 0 )
            v9->AddVisGroup(this: v9, a2: pVisGroup);
          else
            CMapClass::RemoveVisGroup(this: v9, pVisGroup);
          v2 = v15;
          m_pObjectList = v15->m_pObjectList;
        }
      }
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100E5280
// Name: public: static class CObject __near * COP_Groups::CreateObject(void)
// Source: json
//------------------------------------------------------------------------------
COP_Groups *__stdcall COP_Groups::CreateObject()
{
  COP_Groups *v0; // eax

  v0 = (COP_Groups *)operator new(nSize: 0x210u);
  if ( v0 != nullptr )
    return COP_Groups::COP_Groups(this: v0);
  else
    return nullptr;
}
