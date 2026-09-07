// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: hammer/cordonlist.cpp
// Functions: 4
// ============================================================

#include "hammer\cordonlist.h"

//------------------------------------------------------------------------------
// Address: 0x100BD240
// Name: public: CCordonList::CCordonList(void)
// Source: json
//------------------------------------------------------------------------------
CCordonList *__thiscall CCordonList::CCordonList(CCordonList *this)
{
  CTreeList::CTreeList(this);
  this->__vftable = (CCordonList_vtbl *)&CCordonList::`vftable';
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100BD290
// Name: public: virtual CCordonList::~CCordonList(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCordonList::~CCordonList(CCordonList *this)
{
  this->__vftable = (CCordonList_vtbl *)&CCordonList::`vftable';
  CTreeList::~CTreeList(this);
}

//------------------------------------------------------------------------------
// Address: 0x100BD2D0
// Name: public: virtual void CCordonList::OnRenameItem(void __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCordonList::OnRenameItem(CCordonList *this, CUtlString **pItem, const char *pszText)
{
  if ( pItem != nullptr && pszText != nullptr && pItem[1] == nullptr )
    CUtlString::Set(this: *pItem, pValue: pszText);
}

//------------------------------------------------------------------------------
// Address: 0x100BD300
// Name: public: void CCordonList::AddCordon(struct CordonListItem_t __near *,struct CordonListItem_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCordonList::AddCordon(CCordonList *this, CordonListItem_t *pCordon, CordonListItem_t *pParent)
{
  const char *v4; // eax

  if ( pCordon->m_pBox != nullptr )
  {
    CTreeList::AddItem(this, pItem: pCordon, (struct _TREEITEM *)pParent, pText: "box", bHasCheckBox: false);
  }
  else
  {
    v4 = CUtlString::operator char const *(this: &pCordon->m_pCordon->m_szName);
    CTreeList::AddItem(this, pItem: pCordon, (struct _TREEITEM *)pParent, pText: v4, bHasCheckBox: true);
  }
}
