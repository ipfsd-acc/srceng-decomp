// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: hammer/grouplist.cpp
// Functions: 5
// ============================================================

#include "hammer\grouplist.h"

//------------------------------------------------------------------------------
// Address: 0x100BD3B0
// Name: public: CGroupList::CGroupList(void)
// Source: json
//------------------------------------------------------------------------------
CGroupList *__thiscall CGroupList::CGroupList(CGroupList *this)
{
  CTreeList::CTreeList(this);
  this->__vftable = (CGroupList_vtbl *)&CGroupList::`vftable';
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100BD400
// Name: public: virtual CGroupList::~CGroupList(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGroupList::~CGroupList(CGroupList *this)
{
  this->__vftable = (CGroupList_vtbl *)&CGroupList::`vftable';
  CTreeList::~CTreeList(this);
}

//------------------------------------------------------------------------------
// Address: 0x100BD440
// Name: public: virtual void CGroupList::OnRenameItem(void __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGroupList::OnRenameItem(CGroupList *this, unsigned __int8 *pItem, char *pszText)
{
  if ( pItem != nullptr && pszText != nullptr )
    strncpy(dest: pItem + 25, source: (unsigned __int8 *)pszText, count: 0x80u);
}

//------------------------------------------------------------------------------
// Address: 0x100BD470
// Name: public: void CGroupList::UpdateVisGroup(class CVisGroup __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGroupList::UpdateVisGroup(CGroupList *this, CVisGroup *pVisGroup)
{
  CTreeList::UpdateItem(this, pItem: pVisGroup, pszText: pVisGroup->m_szName);
}

//------------------------------------------------------------------------------
// Address: 0x100BD4F0
// Name: public: void CGroupList::AddVisGroup(class CVisGroup __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGroupList::AddVisGroup(CGroupList *this, CVisGroup *pVisGroup)
{
  int i; // edi

  CTreeList::AddItem(
    this,
    pItem: pVisGroup,
    pParent: (struct _TREEITEM *)pVisGroup->m_pParent,
    pText: pVisGroup->m_szName,
    bHasCheckBox: true);
  for ( i = 0; i < pVisGroup->m_Children.m_Size; ++i )
    CGroupList::AddVisGroup(this, pVisGroup: pVisGroup->m_Children.m_Memory.m_pMemory[i]);
}
