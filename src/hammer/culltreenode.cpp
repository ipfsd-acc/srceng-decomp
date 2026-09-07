// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: hammer/culltreenode.cpp
// Functions: 9
// ============================================================

#include "hammer\culltreenode.h"

//------------------------------------------------------------------------------
// Address: 0x10017C10
// Name: public: void CCullTreeNode::AddCullTreeChild(class CCullTreeNode __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCullTreeNode::AddCullTreeChild(CCullTreeNode *this, CCullTreeNode *pChild)
{
  int m_nAllocationCount; // eax
  CUtlVector<CCullTreeNode *,CUtlMemory<CCullTreeNode *,int> > *p_m_Children; // esi
  int m_Size; // edi
  CCullTreeNode **m_pMemory; // ecx
  int v6; // eax
  CCullTreeNode **v7; // eax

  m_nAllocationCount = this->m_Children.m_Memory.m_nAllocationCount;
  p_m_Children = &this->m_Children;
  m_Size = this->m_Children.m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CVisGroup *,int>::Grow(this: &p_m_Children->m_Memory, num: m_Size - m_nAllocationCount + 1);
  ++p_m_Children->m_Size;
  m_pMemory = p_m_Children->m_Memory.m_pMemory;
  v6 = p_m_Children->m_Size - m_Size - 1;
  p_m_Children->m_pElements = p_m_Children->m_Memory.m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v6);
  v7 = &p_m_Children->m_Memory.m_pMemory[m_Size];
  if ( v7 != nullptr )
    *v7 = pChild;
}

//------------------------------------------------------------------------------
// Address: 0x10018000
// Name: public: void CCullTreeNode::AddCullTreeObject(class CMapClass __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCullTreeNode::AddCullTreeObject(CCullTreeNode *this, CMapClass *pObject)
{
  CUtlReference<CMapClass> *m_pHead; // eax
  CUtlReferenceVector<CMapClass> *p_m_Objects; // esi
  bool v4; // dl
  CUtlReference<CMapClass> *v5; // eax
  CUtlReference<CMapClass> src; // [esp+Ch] [ebp-18h] BYREF
  int v7; // [esp+20h] [ebp-4h]

  src.m_pPrev = nullptr;
  src.m_pNext = nullptr;
  src.m_pObject = pObject;
  if ( pObject != nullptr )
  {
    m_pHead = pObject->m_References.m_pHead;
    src.m_pNext = m_pHead;
    if ( m_pHead != nullptr )
      m_pHead->m_pPrev = &src;
    src.m_pPrev = nullptr;
    pObject->m_References.m_pHead = &src;
  }
  v7 = 0;
  p_m_Objects = &this->m_Objects;
  v4 = CUtlVector<CUtlReference<CMapClass>,CUtlBlockMemory<CUtlReference<CMapClass>,int>>::Find(
         this: &this->m_Objects,
         &src) != -1;
  v7 = -1;
  if ( src.m_pObject != nullptr )
  {
    if ( src.m_pPrev != nullptr )
    {
      src.m_pPrev->m_pNext = src.m_pNext;
      if ( src.m_pNext != nullptr )
        src.m_pNext->m_pPrev = src.m_pPrev;
    }
    else if ( src.m_pObject->m_References.m_pHead == &src )
    {
      src.m_pObject->m_References.m_pHead = src.m_pNext;
      if ( src.m_pNext != nullptr )
        src.m_pNext->m_pPrev = nullptr;
    }
    memset(&src, 0, sizeof(src));
  }
  if ( !v4 )
  {
    src.m_pPrev = nullptr;
    src.m_pNext = nullptr;
    src.m_pObject = pObject;
    if ( pObject != nullptr )
    {
      v5 = pObject->m_References.m_pHead;
      src.m_pNext = v5;
      if ( v5 != nullptr )
        v5->m_pPrev = &src;
      src.m_pPrev = nullptr;
      pObject->m_References.m_pHead = &src;
    }
    v7 = 1;
    CUtlVector<CUtlReference<CMapClass>,CUtlBlockMemory<CUtlReference<CMapClass>,int>>::InsertBefore(
      this: p_m_Objects,
      elem: p_m_Objects->m_Size,
      &src);
    v7 = -1;
    if ( src.m_pObject != nullptr )
    {
      if ( src.m_pPrev != nullptr )
      {
        src.m_pPrev->m_pNext = src.m_pNext;
        if ( src.m_pNext != nullptr )
          src.m_pNext->m_pPrev = src.m_pPrev;
      }
      else if ( src.m_pObject->m_References.m_pHead == &src )
      {
        src.m_pObject->m_References.m_pHead = src.m_pNext;
        if ( src.m_pNext != nullptr )
          src.m_pNext->m_pPrev = nullptr;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10018150
// Name: public: void CCullTreeNode::AddCullTreeObjectRecurse(class CMapClass __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCullTreeNode::AddCullTreeObjectRecurse(CCullTreeNode *this, CMapClass *pObject)
{
  int m_Size; // ebx
  int i; // esi
  Vector ObjMins; // [esp+8h] [ebp-18h] BYREF
  Vector ObjMaxs; // [esp+14h] [ebp-Ch] BYREF

  CMapClass::GetCullBox(this: pObject, mins: &ObjMins, maxs: &ObjMaxs);
  if ( BoxesIntersect(mins1: &ObjMins, maxs1: &ObjMaxs, mins2: &this->bmins, maxs2: &this->bmaxs) )
  {
    m_Size = this->m_Children.m_Size;
    if ( m_Size != 0 )
    {
      for ( i = 0; i < m_Size; ++i )
        CCullTreeNode::AddCullTreeObjectRecurse(this: this->m_Children.m_Memory.m_pMemory[i], pObject);
    }
    else
    {
      CCullTreeNode::AddCullTreeObject(this, pObject);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100181D0
// Name: public: void CCullTreeNode::RemoveAllCullTreeObjects(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCullTreeNode::RemoveAllCullTreeObjects(CCullTreeNode *this)
{
  CUtlReferenceVector<CMapClass>::RemoveAll(this: &this->m_Objects);
}

//------------------------------------------------------------------------------
// Address: 0x100181E0
// Name: public: void CCullTreeNode::RemoveCullTreeObject(class CMapClass __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCullTreeNode::RemoveCullTreeObject(CCullTreeNode *this, CMapClass *pObject)
{
  CUtlReference<CMapClass> *m_pHead; // edx
  CUtlReferenceVector<CMapClass> *p_m_Objects; // esi
  int v4; // eax
  CUtlReference<CMapClass> src; // [esp+8h] [ebp-18h] BYREF
  int v6; // [esp+1Ch] [ebp-4h]

  src.m_pPrev = nullptr;
  src.m_pNext = nullptr;
  src.m_pObject = pObject;
  if ( pObject != nullptr )
  {
    m_pHead = pObject->m_References.m_pHead;
    src.m_pNext = m_pHead;
    if ( m_pHead != nullptr )
      m_pHead->m_pPrev = &src;
    src.m_pPrev = nullptr;
    pObject->m_References.m_pHead = &src;
  }
  v6 = 0;
  p_m_Objects = &this->m_Objects;
  v4 = CUtlVector<CUtlReference<CMapClass>,CUtlBlockMemory<CUtlReference<CMapClass>,int>>::Find(
         this: &this->m_Objects,
         &src);
  if ( v4 != -1 )
    CUtlReferenceVector<CMapClass>::FastRemove(this: p_m_Objects, elem: v4);
  v6 = -1;
  if ( src.m_pObject != nullptr )
  {
    if ( src.m_pPrev != nullptr )
    {
      src.m_pPrev->m_pNext = src.m_pNext;
      if ( src.m_pNext != nullptr )
        src.m_pNext->m_pPrev = src.m_pPrev;
    }
    else if ( src.m_pObject->m_References.m_pHead == &src )
    {
      src.m_pObject->m_References.m_pHead = src.m_pNext;
      if ( src.m_pNext != nullptr )
        src.m_pNext->m_pPrev = nullptr;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100182B0
// Name: public: void CCullTreeNode::RemoveCullTreeObjectRecurse(class CMapClass __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCullTreeNode::RemoveCullTreeObjectRecurse(CCullTreeNode *this, CMapClass *pObject)
{
  int i; // esi

  CCullTreeNode::RemoveCullTreeObject(this, pObject);
  for ( i = 0; i < this->m_Children.m_Size; ++i )
    CCullTreeNode::RemoveCullTreeObjectRecurse(this: this->m_Children.m_Memory.m_pMemory[i], pObject);
}

//------------------------------------------------------------------------------
// Address: 0x100182F0
// Name: public: void CCullTreeNode::UpdateCullTreeObjectRecurse(class CMapClass __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCullTreeNode::UpdateCullTreeObjectRecurse(CCullTreeNode *this, CMapClass *pObject)
{
  int m_Size; // ebx
  int i; // esi
  Vector mins; // [esp+Ch] [ebp-18h] BYREF
  Vector maxs; // [esp+18h] [ebp-Ch] BYREF

  m_Size = this->m_Children.m_Size;
  if ( m_Size != 0 )
  {
    for ( i = 0; i < m_Size; ++i )
      CCullTreeNode::UpdateCullTreeObjectRecurse(this: this->m_Children.m_Memory.m_pMemory[i], pObject);
  }
  else
  {
    CMapClass::GetCullBox(this: pObject, &mins, &maxs);
    if ( BoxesIntersect(mins1: &mins, maxs1: &maxs, mins2: &this->bmins, maxs2: &this->bmaxs) )
      CCullTreeNode::AddCullTreeObject(this, pObject);
    else
      CCullTreeNode::RemoveCullTreeObject(this, pObject);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10018420
// Name: public: CCullTreeNode::~CCullTreeNode(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCullTreeNode::~CCullTreeNode(CCullTreeNode *this)
{
  CUtlVector<CCullTreeNode *,CUtlMemory<CCullTreeNode *,int> > *p_m_Children; // esi

  this->__vftable = (CCullTreeNode_vtbl *)&CCullTreeNode::`vftable';
  CUtlVector<CUtlReference<CMapClass>,CUtlBlockMemory<CUtlReference<CMapClass>,int>>::~CUtlVector<CUtlReference<CMapClass>,CUtlBlockMemory<CUtlReference<CMapClass>,int>>(this: &this->m_Objects);
  p_m_Children = &this->m_Children;
  p_m_Children->m_Size = 0;
  if ( p_m_Children->m_Memory.m_nGrowSize >= 0 )
  {
    if ( p_m_Children->m_Memory.m_pMemory != nullptr )
    {
      free(pMem: p_m_Children->m_Memory.m_pMemory);
      p_m_Children->m_Memory.m_pMemory = nullptr;
    }
    p_m_Children->m_Memory.m_nAllocationCount = 0;
  }
  p_m_Children->m_pElements = p_m_Children->m_Memory.m_pMemory;
  if ( p_m_Children->m_Memory.m_nGrowSize >= 0 )
  {
    if ( p_m_Children->m_Memory.m_pMemory != nullptr )
    {
      free(pMem: p_m_Children->m_Memory.m_pMemory);
      p_m_Children->m_Memory.m_pMemory = nullptr;
    }
    p_m_Children->m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100184C0
// Name: public: CCullTreeNode::CCullTreeNode(void)
// Source: json
//------------------------------------------------------------------------------
CCullTreeNode *__thiscall CCullTreeNode::CCullTreeNode(CCullTreeNode *this)
{
  CCullTreeNode **m_pMemory; // ecx

  BoundBox::BoundBox(this);
  this->__vftable = (CCullTreeNode_vtbl *)&CCullTreeNode::`vftable';
  this->m_Children.m_Memory.m_pMemory = nullptr;
  this->m_Children.m_Memory.m_nAllocationCount = 0;
  this->m_Children.m_Memory.m_nGrowSize = 0;
  m_pMemory = this->m_Children.m_Memory.m_pMemory;
  this->m_Children.m_Size = 0;
  this->m_Children.m_pElements = m_pMemory;
  this->m_Objects.m_Memory.m_pMemory = nullptr;
  this->m_Objects.m_Memory.m_nBlocks = 0;
  *((_DWORD *)&this->m_Objects.m_Memory + 2) = 0;
  CUtlBlockMemory<CUtlReference<CMapEntity>,int>::Init(this: &this->m_Objects.m_Memory, nGrowSize: 0, nInitSize: 0);
  this->m_Objects.m_Size = 0;
  this->m_Objects.m_pElements = nullptr;
  return this;
}
