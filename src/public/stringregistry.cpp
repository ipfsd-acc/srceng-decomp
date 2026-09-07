// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: public/stringregistry.cpp
// Functions: 8
// ============================================================

#include "public\stringregistry.h"

//------------------------------------------------------------------------------
// Address: 0x10173E80
// Name: public: void CUtlDict<int,unsigned short>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlDict<int,unsigned short>::RemoveAll(CUtlDict<int,unsigned short> *this)
{
  unsigned __int16 i; // si

  for ( i = CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::FirstInorder(this: &this->m_Elements.m_Tree);
        i != 0xFFFF;
        i = CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::NextInorder(
              this: &this->m_Elements.m_Tree,
              i) )
  {
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)this->m_Elements.m_Tree.m_Elements.m_pMemory[i].m_Data.key);
  }
  CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::RemoveAll(this: &this->m_Elements.m_Tree);
}

//------------------------------------------------------------------------------
// Address: 0x10173EE0
// Name: public: int CStringRegistry::GetStringID(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CStringRegistry::GetStringID(CStringRegistry *this, const char *stringText)
{
  StringTable_t *m_pStringList; // ecx
  unsigned __int16 v4; // si
  StringTable_t *v5; // ecx
  CUtlMap<char const *,int,unsigned short>::Node_t search; // [esp+Ch] [ebp-8h] BYREF

  m_pStringList = this->m_pStringList;
  if ( stringText != nullptr )
  {
    search.key = stringText;
    v4 = CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
           this: &m_pStringList->m_Elements.m_Tree,
           &search);
  }
  else
  {
    v4 = -1;
  }
  v5 = this->m_pStringList;
  if ( v4 >= this->m_pStringList->m_Elements.m_Tree.m_Elements.m_nAllocationCount
    || v4 > v5->m_Elements.m_Tree.m_LastAlloc.index
    || CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::LeftChild(
         this: &v5->m_Elements.m_Tree,
         i: v4) == v4 )
  {
    return -1;
  }
  else
  {
    return this->m_pStringList->m_Elements.m_Tree.m_Elements.m_pMemory[v4].m_Data.elem;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10173F50
// Name: public: char const __near * CStringRegistry::GetStringForKey(unsigned short)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CStringRegistry::GetStringForKey(CStringRegistry *this, unsigned __int16 key)
{
  StringTable_t *m_pStringList; // ecx

  m_pStringList = this->m_pStringList;
  if ( key >= m_pStringList->m_Elements.m_Tree.m_Elements.m_nAllocationCount
    || key > m_pStringList->m_Elements.m_Tree.m_LastAlloc.index
    || CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::LeftChild(
         this: &m_pStringList->m_Elements.m_Tree,
         i: key) == key )
  {
    return nullptr;
  }
  else
  {
    return this->m_pStringList->m_Elements.m_Tree.m_Elements.m_pMemory[key].m_Data.key;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10173FA0
// Name: public: void CStringRegistry::ClearStrings(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CStringRegistry::ClearStrings(CStringRegistry *this)
{
  CUtlDict<int,unsigned short>::RemoveAll(this: this->m_pStringList);
}

//------------------------------------------------------------------------------
// Address: 0x10174020
// Name: public: CStringRegistry::CStringRegistry(void)
// Source: json
//------------------------------------------------------------------------------
CStringRegistry *__thiscall CStringRegistry::CStringRegistry(CStringRegistry *this)
{
  StringTable_t *v2; // eax

  v2 = (StringTable_t *)MemAlloc_Alloc(nSize: 0x1Cu);
  if ( v2 != nullptr )
  {
    v2->m_Elements.m_Tree.m_LessFunc.m_LessFunc = nullptr;
    v2->m_Elements.m_Tree.m_Elements.m_pMemory = nullptr;
    v2->m_Elements.m_Tree.m_Elements.m_nAllocationCount = 0;
    v2->m_Elements.m_Tree.m_Elements.m_nGrowSize = 0;
    v2->m_Elements.m_Tree.m_Root = -1;
    v2->m_Elements.m_Tree.m_NumElements = 0;
    v2->m_Elements.m_Tree.m_FirstFree = -1;
    v2->m_Elements.m_Tree.m_LastAlloc.index = -1;
    v2->m_Elements.m_Tree.m_pElements = v2->m_Elements.m_Tree.m_Elements.m_pMemory;
    if ( v2->m_Elements.m_Tree.m_LessFunc.m_LessFunc == nullptr )
    {
      v2->m_Elements.m_Tree.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))CaselessStringLessThan;
      this->m_pStringList = v2;
      return this;
    }
  }
  else
  {
    v2 = nullptr;
  }
  this->m_pStringList = v2;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10174080
// Name: public: unsigned short CUtlDict<int,unsigned short>::Insert(char const __near *,int const __near &)
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CUtlDict<int,unsigned short>::Insert(
        CUtlDict<int,unsigned short> *this,
        const char *pName,
        int *element)
{
  char *v4; // eax
  int v5; // edx
  CUtlMap<char const *,int,unsigned short>::Node_t insert; // [esp+8h] [ebp-8h] BYREF

  if ( pName != nullptr && (v4 = (char *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: strlen(pName) + 1)) != nullptr )
    strcpy(v4, pName);
  else
    v4 = nullptr;
  v5 = *element;
  insert.key = v4;
  insert.elem = v5;
  return CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Insert(
           this: &this->m_Elements.m_Tree,
           a2: pName,
           &insert);
}

//------------------------------------------------------------------------------
// Address: 0x101740F0
// Name: public: unsigned short CStringRegistry::AddString(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CStringRegistry::AddString(CStringRegistry *this, const char *stringText, int stringID)
{
  return CUtlDict<int,unsigned short>::Insert(this: this->m_pStringList, pName: stringText, element: &stringID);
}

//------------------------------------------------------------------------------
// Address: 0x10174110
// Name: public: CStringRegistry::~CStringRegistry(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CStringRegistry::~CStringRegistry(CStringRegistry *this)
{
  StringTable_t *m_pStringList; // esi

  m_pStringList = this->m_pStringList;
  if ( this->m_pStringList != nullptr )
  {
    CUtlDict<int,unsigned short>::RemoveAll(this: this->m_pStringList);
    CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::~CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>(this: &m_pStringList->m_Elements.m_Tree);
    C_BaseEntity::operator delete(pMem: m_pStringList);
  }
}

// ============================================================
// Overlay from server (Missing functions)
// ============================================================
namespace server {

//------------------------------------------------------------------------------
// Address: 0x10227020
// Name: public: void CUtlDict<int,unsigned short>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlDict<int,unsigned short>::RemoveAll(CUtlDict<int,unsigned short> *this)
{
  unsigned __int16 i; // si

  for ( i = CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::FirstInorder(this: &this->m_Elements.m_Tree);
        i != 0xFFFF;
        i = CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::NextInorder(
              this: &this->m_Elements.m_Tree,
              i) )
  {
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)this->m_Elements.m_Tree.m_Elements.m_pMemory[i].m_Data.key);
  }
  CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::RemoveAll(this: &this->m_Elements.m_Tree);
}

//------------------------------------------------------------------------------
// Address: 0x10227080
// Name: public: int CStringRegistry::GetStringID(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CStringRegistry::GetStringID(CStringRegistry *this, const char *stringText)
{
  StringTable_t *m_pStringList; // ecx
  unsigned __int16 v4; // si
  StringTable_t *v5; // ecx
  CUtlMap<char const *,int,unsigned short>::Node_t search; // [esp+Ch] [ebp-8h] BYREF

  m_pStringList = this->m_pStringList;
  if ( stringText != nullptr )
  {
    search.key = stringText;
    v4 = CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
           this: &m_pStringList->m_Elements.m_Tree,
           &search);
  }
  else
  {
    v4 = -1;
  }
  v5 = this->m_pStringList;
  if ( v4 >= this->m_pStringList->m_Elements.m_Tree.m_Elements.m_nAllocationCount
    || v4 > v5->m_Elements.m_Tree.m_LastAlloc.index
    || CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::LeftChild(
         this: &v5->m_Elements.m_Tree,
         i: v4) == v4 )
  {
    return -1;
  }
  else
  {
    return this->m_pStringList->m_Elements.m_Tree.m_Elements.m_pMemory[v4].m_Data.elem;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102270F0
// Name: public: char const __near * CStringRegistry::GetStringText(int)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CStringRegistry::GetStringText(CStringRegistry *this, int stringID)
{
  unsigned __int16 Inorder; // ax
  UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short> *m_pMemory; // ebx

  Inorder = CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::FirstInorder(this: &this->m_pStringList->m_Elements.m_Tree);
  if ( Inorder == 0xFFFF )
    return nullptr;
  while ( 1 )
  {
    m_pMemory = this->m_pStringList->m_Elements.m_Tree.m_Elements.m_pMemory;
    if ( m_pMemory[Inorder].m_Data.elem == stringID )
      break;
    Inorder = CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::NextInorder(
                this: &this->m_pStringList->m_Elements.m_Tree,
                i: Inorder);
    if ( Inorder == 0xFFFF )
      return nullptr;
  }
  return m_pMemory[Inorder].m_Data.key;
}

//------------------------------------------------------------------------------
// Address: 0x10227150
// Name: public: char const __near * CStringRegistry::GetStringForKey(unsigned short)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CStringRegistry::GetStringForKey(CStringRegistry *this, unsigned __int16 key)
{
  StringTable_t *m_pStringList; // ecx

  m_pStringList = this->m_pStringList;
  if ( key >= m_pStringList->m_Elements.m_Tree.m_Elements.m_nAllocationCount
    || key > m_pStringList->m_Elements.m_Tree.m_LastAlloc.index
    || CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::LeftChild(
         this: &m_pStringList->m_Elements.m_Tree,
         i: key) == key )
  {
    return nullptr;
  }
  else
  {
    return this->m_pStringList->m_Elements.m_Tree.m_Elements.m_pMemory[key].m_Data.key;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102271A0
// Name: public: int CStringRegistry::GetIDForKey(unsigned short)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CStringRegistry::GetIDForKey(CStringRegistry *this, unsigned __int16 key)
{
  StringTable_t *m_pStringList; // ecx

  m_pStringList = this->m_pStringList;
  if ( key >= m_pStringList->m_Elements.m_Tree.m_Elements.m_nAllocationCount
    || key > m_pStringList->m_Elements.m_Tree.m_LastAlloc.index
    || CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::LeftChild(
         this: &m_pStringList->m_Elements.m_Tree,
         i: key) == key )
  {
    return 0;
  }
  else
  {
    return this->m_pStringList->m_Elements.m_Tree.m_Elements.m_pMemory[key].m_Data.elem;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102271F0
// Name: public: void CStringRegistry::ClearStrings(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CStringRegistry::ClearStrings(CStringRegistry *this)
{
  CUtlDict<int,unsigned short>::RemoveAll(this: this->m_pStringList);
}

//------------------------------------------------------------------------------
// Address: 0x10227200
// Name: public: unsigned short CStringRegistry::First(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CStringRegistry::First(CStringRegistry *this)
{
  return CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::FirstInorder(this: &this->m_pStringList->m_Elements.m_Tree);
}

//------------------------------------------------------------------------------
// Address: 0x10227210
// Name: public: unsigned short CStringRegistry::Next(unsigned short)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CStringRegistry::Next(CStringRegistry *this, unsigned __int16 key)
{
  return CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::NextInorder(
           this: &this->m_pStringList->m_Elements.m_Tree,
           i: key);
}

//------------------------------------------------------------------------------
// Address: 0x10227290
// Name: public: CStringRegistry::CStringRegistry(void)
// Source: json
//------------------------------------------------------------------------------
CStringRegistry *__thiscall CStringRegistry::CStringRegistry(CStringRegistry *this)
{
  StringTable_t *v2; // eax

  v2 = (StringTable_t *)operator new(nSize: 0x1Cu);
  if ( v2 != nullptr )
  {
    v2->m_Elements.m_Tree.m_LessFunc.m_LessFunc = nullptr;
    v2->m_Elements.m_Tree.m_Elements.m_pMemory = nullptr;
    v2->m_Elements.m_Tree.m_Elements.m_nAllocationCount = 0;
    v2->m_Elements.m_Tree.m_Elements.m_nGrowSize = 0;
    v2->m_Elements.m_Tree.m_Root = -1;
    v2->m_Elements.m_Tree.m_NumElements = 0;
    v2->m_Elements.m_Tree.m_FirstFree = -1;
    v2->m_Elements.m_Tree.m_LastAlloc.index = -1;
    v2->m_Elements.m_Tree.m_pElements = v2->m_Elements.m_Tree.m_Elements.m_pMemory;
    if ( v2->m_Elements.m_Tree.m_LessFunc.m_LessFunc == nullptr )
    {
      v2->m_Elements.m_Tree.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))CaselessStringLessThan;
      this->m_pStringList = v2;
      return this;
    }
  }
  else
  {
    v2 = nullptr;
  }
  this->m_pStringList = v2;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x102272F0
// Name: public: unsigned short CUtlDict<int,unsigned short>::Insert(char const __near *,int const __near &)
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CUtlDict<int,unsigned short>::Insert(
        CUtlDict<int,unsigned short> *this,
        const char *pName,
        int *element)
{
  char *v4; // eax
  int v5; // edx
  CUtlMap<char const *,int,unsigned short>::Node_t insert; // [esp+8h] [ebp-8h] BYREF

  if ( pName != nullptr && (v4 = (char *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: strlen(pName) + 1)) != nullptr )
    strcpy(v4, pName);
  else
    v4 = nullptr;
  v5 = *element;
  insert.key = v4;
  insert.elem = v5;
  return CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Insert(
           this: &this->m_Elements.m_Tree,
           &insert);
}

//------------------------------------------------------------------------------
// Address: 0x10227360
// Name: public: unsigned short CStringRegistry::AddString(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CStringRegistry::AddString(CStringRegistry *this, const char *stringText, int stringID)
{
  return CUtlDict<int,unsigned short>::Insert(this: this->m_pStringList, pName: stringText, element: &stringID);
}

//------------------------------------------------------------------------------
// Address: 0x10227380
// Name: public: CStringRegistry::~CStringRegistry(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CStringRegistry::~CStringRegistry(CStringRegistry *this)
{
  StringTable_t *m_pStringList; // esi

  m_pStringList = this->m_pStringList;
  if ( this->m_pStringList != nullptr )
  {
    CUtlDict<int,unsigned short>::RemoveAll(this: this->m_pStringList);
    CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::~CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>(this: &m_pStringList->m_Elements.m_Tree);
    free(pMem: m_pStringList);
  }
}

} // namespace server
