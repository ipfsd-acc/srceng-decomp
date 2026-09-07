// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/c_te_legacytempents.cpp
// Functions: 167
// ============================================================

#include "game\client\c_te_legacytempents.h"

//------------------------------------------------------------------------------
// Address: 0x100103F0
// Name: public: static class CUtlLinkedList<class C_BaseCombatWeapon __near *,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<class C_BaseCombatWeapon __near *,unsigned short>,unsigned short>> __near & C_BaseCombatWeapon::GetWeaponList(void)
// Source: json
//------------------------------------------------------------------------------
CUtlLinkedList<C_BaseCombatWeapon *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<C_BaseCombatWeapon *,unsigned short>,unsigned short> > *__cdecl C_BaseCombatWeapon::GetWeaponList()
{
  return &g_WeaponList.m_list;
}

//------------------------------------------------------------------------------
// Address: 0x1002A230
// Name: protected: unsigned short CUtlLinkedList<class C_RopeKeyframe __near *,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<class C_RopeKeyframe __near *,unsigned short>,unsigned short>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<C_RopeKeyframe *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<C_RopeKeyframe *,unsigned short>,unsigned short>>::AllocInternal(
        CUtlLinkedList<C_RopeKeyframe *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<C_RopeKeyframe *,unsigned short>,unsigned short> > *this,
        bool multilist)
{
  int m_FirstFree; // ecx
  int m_nAllocationCount; // ecx
  unsigned __int16 index; // ax
  int result; // eax
  int v7; // ecx
  unsigned __int16 v8; // ax
  UtlLinkedListElem_t<C_RopeKeyframe *,unsigned short> *v9; // ecx

  m_FirstFree = this->m_FirstFree;
  if ( (_WORD)m_FirstFree != 0xFFFF )
  {
    result = m_FirstFree;
    this->m_FirstFree = this->m_Memory.m_pMemory[m_FirstFree].m_Next;
LABEL_22:
    v9 = &this->m_Memory.m_pMemory[(unsigned __int16)result];
    if ( multilist )
    {
      v9->m_Next = -1;
      v9->m_Previous = -1;
    }
    else
    {
      v9->m_Next = result;
      v9->m_Previous = result;
    }
    return result;
  }
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( this->m_LastAlloc.index >= m_nAllocationCount )
  {
    m_nAllocationCount = this->m_Memory.m_nAllocationCount;
    LOWORD(result) = (m_nAllocationCount > 0) - 1;
  }
  else
  {
    index = this->m_LastAlloc.index;
    if ( (unsigned __int16)(index + 1) >= m_nAllocationCount )
      LOWORD(result) = -1;
    else
      LOWORD(result) = index + 1;
  }
  if ( (unsigned __int16)result >= m_nAllocationCount )
  {
    CUtlMemory<UtlLinkedListElem_t<CParticleEffectBinding *,unsigned short>,unsigned short>::Grow(
      this: &this->m_Memory,
      num: 1);
    this->m_pElements = this->m_Memory.m_pMemory;
    v7 = this->m_Memory.m_nAllocationCount;
    if ( this->m_LastAlloc.index >= v7 )
    {
      v7 = this->m_Memory.m_nAllocationCount;
      LOWORD(result) = (v7 > 0) - 1;
    }
    else
    {
      v8 = this->m_LastAlloc.index;
      LOWORD(result) = (unsigned __int16)(v8 + 1) >= v7 ? -1 : v8 + 1;
    }
    if ( (unsigned __int16)result >= v7 )
    {
      if ( `CUtlLinkedList<C_RopeKeyframe *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<C_RopeKeyframe *,unsigned short>,unsigned short>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<C_RopeKeyframe *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<C_RopeKeyframe *,unsigned short>,unsigned short>>::AllocInternal'::`12'::__executeCount;
        _Warning(a1: "CUtlLinkedList overflow! (exhausted memory allocator)\n");
      }
      return 0xFFFF;
    }
  }
  if ( (_WORD)result != 0xFFFF )
  {
    ++this->m_NumAlloced;
    this->m_LastAlloc.index = result;
    result = (unsigned __int16)result;
    goto LABEL_22;
  }
  if ( `CUtlLinkedList<C_RopeKeyframe *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<C_RopeKeyframe *,unsigned short>,unsigned short>>::AllocInternal'::`19'::__executeCount >= 10 )
    return 0xFFFF;
  ++`CUtlLinkedList<C_RopeKeyframe *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<C_RopeKeyframe *,unsigned short>,unsigned short>>::AllocInternal'::`19'::__executeCount;
  _Warning(a1: "CUtlLinkedList overflow! (exhausted index range)\n");
  return 0xFFFF;
}

//------------------------------------------------------------------------------
// Address: 0x1002DD80
// Name: public: void CUtlLinkedList<struct JiggleData,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<struct JiggleData,unsigned short>,unsigned short>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<JiggleData,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<JiggleData,unsigned short>,unsigned short>>::RemoveAll(
        CUtlLinkedList<JiggleData,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<JiggleData,unsigned short>,unsigned short> > *this)
{
  unsigned __int16 m_Head; // dx
  UtlLinkedListElem_t<JiggleData,unsigned short> *v2; // esi
  unsigned __int16 m_Next; // ax
  unsigned __int16 m_FirstFree; // dx
  unsigned __int16 v5; // ax

  if ( this->m_LastAlloc.index != 0xFFFF )
  {
    m_Head = this->m_Head;
    if ( m_Head != 0xFFFF )
    {
      do
      {
        v2 = &this->m_Memory.m_pMemory[m_Head];
        m_Next = v2->m_Next;
        v2->m_Previous = m_Head;
        if ( m_Next == 0xFFFF )
          m_FirstFree = this->m_FirstFree;
        else
          m_FirstFree = m_Next;
        v2->m_Next = m_FirstFree;
        m_Head = m_Next;
      }
      while ( m_Next != 0xFFFF );
    }
    v5 = this->m_Head;
    if ( v5 != 0xFFFF )
      this->m_FirstFree = v5;
    *(_DWORD *)&this->m_Head = -1;
    this->m_ElementCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003E360
// Name: protected: unsigned short CUtlLinkedList<class C_BaseEntity __near *,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<class C_BaseEntity __near *,unsigned short>,unsigned short>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<C_BaseEntity *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<C_BaseEntity *,unsigned short>,unsigned short>>::AllocInternal(
        CUtlLinkedList<C_BaseEntity *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<C_BaseEntity *,unsigned short>,unsigned short> > *this,
        bool multilist)
{
  int m_FirstFree; // ecx
  int m_nAllocationCount; // ecx
  unsigned __int16 index; // ax
  int result; // eax
  int v7; // ecx
  unsigned __int16 v8; // ax
  UtlLinkedListElem_t<C_BaseEntity *,unsigned short> *v9; // ecx

  m_FirstFree = this->m_FirstFree;
  if ( (_WORD)m_FirstFree != 0xFFFF )
  {
    result = m_FirstFree;
    this->m_FirstFree = this->m_Memory.m_pMemory[m_FirstFree].m_Next;
LABEL_22:
    v9 = &this->m_Memory.m_pMemory[(unsigned __int16)result];
    if ( multilist )
    {
      v9->m_Next = -1;
      v9->m_Previous = -1;
    }
    else
    {
      v9->m_Next = result;
      v9->m_Previous = result;
    }
    return result;
  }
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( this->m_LastAlloc.index >= m_nAllocationCount )
  {
    m_nAllocationCount = this->m_Memory.m_nAllocationCount;
    LOWORD(result) = (m_nAllocationCount > 0) - 1;
  }
  else
  {
    index = this->m_LastAlloc.index;
    if ( (unsigned __int16)(index + 1) >= m_nAllocationCount )
      LOWORD(result) = -1;
    else
      LOWORD(result) = index + 1;
  }
  if ( (unsigned __int16)result >= m_nAllocationCount )
  {
    CUtlMemory<UtlLinkedListElem_t<CParticleEffectBinding *,unsigned short>,unsigned short>::Grow(
      (CUtlMemory<UtlLinkedListElem_t<C_RopeKeyframe *,unsigned short>,unsigned short> *)this,
      num: 1);
    this->m_pElements = this->m_Memory.m_pMemory;
    v7 = this->m_Memory.m_nAllocationCount;
    if ( this->m_LastAlloc.index >= v7 )
    {
      v7 = this->m_Memory.m_nAllocationCount;
      LOWORD(result) = (v7 > 0) - 1;
    }
    else
    {
      v8 = this->m_LastAlloc.index;
      LOWORD(result) = (unsigned __int16)(v8 + 1) >= v7 ? -1 : v8 + 1;
    }
    if ( (unsigned __int16)result >= v7 )
    {
      if ( `CUtlLinkedList<C_BaseEntity *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<C_BaseEntity *,unsigned short>,unsigned short>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<C_BaseEntity *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<C_BaseEntity *,unsigned short>,unsigned short>>::AllocInternal'::`12'::__executeCount;
        _Warning(a1: "CUtlLinkedList overflow! (exhausted memory allocator)\n");
      }
      return 0xFFFF;
    }
  }
  if ( (_WORD)result != 0xFFFF )
  {
    ++this->m_NumAlloced;
    this->m_LastAlloc.index = result;
    result = (unsigned __int16)result;
    goto LABEL_22;
  }
  if ( `CUtlLinkedList<C_BaseEntity *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<C_BaseEntity *,unsigned short>,unsigned short>>::AllocInternal'::`19'::__executeCount >= 10 )
    return 0xFFFF;
  ++`CUtlLinkedList<C_BaseEntity *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<C_BaseEntity *,unsigned short>,unsigned short>>::AllocInternal'::`19'::__executeCount;
  _Warning(a1: "CUtlLinkedList overflow! (exhausted index range)\n");
  return 0xFFFF;
}

//------------------------------------------------------------------------------
// Address: 0x1006D760
// Name: protected: unsigned short CUtlLinkedList<struct Panel_t,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<struct Panel_t,unsigned short>,unsigned short>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<Panel_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<Panel_t,unsigned short>,unsigned short>>::AllocInternal(
        CUtlLinkedList<Panel_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<Panel_t,unsigned short>,unsigned short> > *this,
        bool multilist)
{
  int m_FirstFree; // ecx
  int m_nAllocationCount; // ecx
  unsigned __int16 index; // ax
  int result; // eax
  int v7; // ecx
  unsigned __int16 v8; // ax
  UtlLinkedListElem_t<Panel_t,unsigned short> *v9; // ecx

  m_FirstFree = this->m_FirstFree;
  if ( (_WORD)m_FirstFree != 0xFFFF )
  {
    result = m_FirstFree;
    this->m_FirstFree = this->m_Memory.m_pMemory[m_FirstFree].m_Next;
LABEL_22:
    v9 = &this->m_Memory.m_pMemory[(unsigned __int16)result];
    if ( multilist )
    {
      v9->m_Next = -1;
      v9->m_Previous = -1;
    }
    else
    {
      v9->m_Next = result;
      v9->m_Previous = result;
    }
    return result;
  }
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( this->m_LastAlloc.index >= m_nAllocationCount )
  {
    m_nAllocationCount = this->m_Memory.m_nAllocationCount;
    LOWORD(result) = (m_nAllocationCount > 0) - 1;
  }
  else
  {
    index = this->m_LastAlloc.index;
    if ( (unsigned __int16)(index + 1) >= m_nAllocationCount )
      LOWORD(result) = -1;
    else
      LOWORD(result) = index + 1;
  }
  if ( (unsigned __int16)result >= m_nAllocationCount )
  {
    CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CPixelVisibilityQuery,unsigned short>::List_t,unsigned short>,unsigned short>::Grow(
      (CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short> *)this,
      num: 1);
    this->m_pElements = this->m_Memory.m_pMemory;
    v7 = this->m_Memory.m_nAllocationCount;
    if ( this->m_LastAlloc.index >= v7 )
    {
      v7 = this->m_Memory.m_nAllocationCount;
      LOWORD(result) = (v7 > 0) - 1;
    }
    else
    {
      v8 = this->m_LastAlloc.index;
      LOWORD(result) = (unsigned __int16)(v8 + 1) >= v7 ? -1 : v8 + 1;
    }
    if ( (unsigned __int16)result >= v7 )
    {
      if ( `CUtlLinkedList<Panel_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<Panel_t,unsigned short>,unsigned short>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<Panel_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<Panel_t,unsigned short>,unsigned short>>::AllocInternal'::`12'::__executeCount;
        _Warning(a1: "CUtlLinkedList overflow! (exhausted memory allocator)\n");
      }
      return 0xFFFF;
    }
  }
  if ( (_WORD)result != 0xFFFF )
  {
    ++this->m_NumAlloced;
    this->m_LastAlloc.index = result;
    result = (unsigned __int16)result;
    goto LABEL_22;
  }
  if ( `CUtlLinkedList<Panel_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<Panel_t,unsigned short>,unsigned short>>::AllocInternal'::`19'::__executeCount >= 10 )
    return 0xFFFF;
  ++`CUtlLinkedList<Panel_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<Panel_t,unsigned short>,unsigned short>>::AllocInternal'::`19'::__executeCount;
  _Warning(a1: "CUtlLinkedList overflow! (exhausted index range)\n");
  return 0xFFFF;
}

//------------------------------------------------------------------------------
// Address: 0x1006E5E0
// Name: public: void CUtlLinkedList<struct Panel_t,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<struct Panel_t,unsigned short>,unsigned short>>::LinkAfter(unsigned short,unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<Panel_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<Panel_t,unsigned short>,unsigned short>>::LinkAfter(
        CUtlLinkedList<Panel_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<Panel_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 after,
        unsigned __int16 elem)
{
  UtlLinkedListElem_t<Panel_t,unsigned short> *v4; // eax
  UtlLinkedListElem_t<Panel_t,unsigned short> *v5; // ecx
  int m_Next; // eax

  if ( elem < this->m_Memory.m_nAllocationCount
    && elem <= this->m_LastAlloc.index
    && this->m_Memory.m_pMemory[elem].m_Previous != elem )
  {
    CUtlLinkedList<Panel_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<Panel_t,unsigned short>,unsigned short>>::Unlink(
      (CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short> > *)this,
      elem);
  }
  v4 = &this->m_Memory.m_pMemory[elem];
  v4->m_Previous = after;
  if ( after == 0xFFFF )
  {
    v4->m_Next = this->m_Head;
    this->m_Head = elem;
  }
  else
  {
    v5 = &this->m_Memory.m_pMemory[after];
    v4->m_Next = v5->m_Next;
    v5->m_Next = elem;
  }
  m_Next = v4->m_Next;
  if ( (_WORD)m_Next == 0xFFFF )
  {
    ++this->m_ElementCount;
    this->m_Tail = elem;
  }
  else
  {
    this->m_Memory.m_pMemory[m_Next].m_Previous = elem;
    ++this->m_ElementCount;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1007B170
// Name: protected: unsigned short CUtlLinkedList<struct CUtlMultiList<class CPixelVisSet,unsigned short>::List_t,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<struct CUtlMultiList<class CPixelVisSet,unsigned short>::List_t,unsigned short>,unsigned short>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<CUtlMultiList<CPixelVisSet,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CPixelVisSet,unsigned short>::List_t,unsigned short>,unsigned short>>::AllocInternal(
        CUtlLinkedList<CUtlMultiList<CPixelVisSet,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CPixelVisSet,unsigned short>::List_t,unsigned short>,unsigned short> > *this,
        bool multilist)
{
  int m_FirstFree; // ecx
  int m_nAllocationCount; // ecx
  unsigned __int16 index; // ax
  int result; // eax
  int v7; // ecx
  unsigned __int16 v8; // ax
  UtlLinkedListElem_t<CUtlMultiList<CPixelVisSet,unsigned short>::List_t,unsigned short> *v9; // ecx

  m_FirstFree = this->m_FirstFree;
  if ( (_WORD)m_FirstFree != 0xFFFF )
  {
    result = m_FirstFree;
    this->m_FirstFree = this->m_Memory.m_pMemory[m_FirstFree].m_Next;
LABEL_22:
    v9 = &this->m_Memory.m_pMemory[(unsigned __int16)result];
    if ( multilist )
    {
      v9->m_Next = -1;
      v9->m_Previous = -1;
    }
    else
    {
      v9->m_Next = result;
      v9->m_Previous = result;
    }
    return result;
  }
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( this->m_LastAlloc.index >= m_nAllocationCount )
  {
    m_nAllocationCount = this->m_Memory.m_nAllocationCount;
    LOWORD(result) = (m_nAllocationCount > 0) - 1;
  }
  else
  {
    index = this->m_LastAlloc.index;
    if ( (unsigned __int16)(index + 1) >= m_nAllocationCount )
      LOWORD(result) = -1;
    else
      LOWORD(result) = index + 1;
  }
  if ( (unsigned __int16)result >= m_nAllocationCount )
  {
    CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CPixelVisibilityQuery,unsigned short>::List_t,unsigned short>,unsigned short>::Grow(
      (CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short> *)this,
      num: 1);
    this->m_pElements = this->m_Memory.m_pMemory;
    v7 = this->m_Memory.m_nAllocationCount;
    if ( this->m_LastAlloc.index >= v7 )
    {
      v7 = this->m_Memory.m_nAllocationCount;
      LOWORD(result) = (v7 > 0) - 1;
    }
    else
    {
      v8 = this->m_LastAlloc.index;
      LOWORD(result) = (unsigned __int16)(v8 + 1) >= v7 ? -1 : v8 + 1;
    }
    if ( (unsigned __int16)result >= v7 )
    {
      if ( `CUtlLinkedList<CUtlMultiList<CPixelVisSet,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CPixelVisSet,unsigned short>::List_t,unsigned short>,unsigned short>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<CUtlMultiList<CPixelVisSet,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CPixelVisSet,unsigned short>::List_t,unsigned short>,unsigned short>>::AllocInternal'::`12'::__executeCount;
        _Warning(a1: "CUtlLinkedList overflow! (exhausted memory allocator)\n");
      }
      return 0xFFFF;
    }
  }
  if ( (_WORD)result != 0xFFFF )
  {
    ++this->m_NumAlloced;
    this->m_LastAlloc.index = result;
    result = (unsigned __int16)result;
    goto LABEL_22;
  }
  if ( `CUtlLinkedList<CUtlMultiList<CPixelVisSet,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CPixelVisSet,unsigned short>::List_t,unsigned short>,unsigned short>>::AllocInternal'::`19'::__executeCount >= 10 )
    return 0xFFFF;
  ++`CUtlLinkedList<CUtlMultiList<CPixelVisSet,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CPixelVisSet,unsigned short>::List_t,unsigned short>,unsigned short>>::AllocInternal'::`19'::__executeCount;
  _Warning(a1: "CUtlLinkedList overflow! (exhausted index range)\n");
  return 0xFFFF;
}

//------------------------------------------------------------------------------
// Address: 0x1007B2F0
// Name: protected: unsigned short CUtlLinkedList<struct CUtlMultiList<class CPixelVisibilityQuery,unsigned short>::List_t,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<struct CUtlMultiList<class CPixelVisibilityQuery,unsigned short>::List_t,unsigned short>,unsigned short>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<CUtlMultiList<CPixelVisibilityQuery,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CPixelVisibilityQuery,unsigned short>::List_t,unsigned short>,unsigned short>>::AllocInternal(
        CUtlLinkedList<CUtlMultiList<CPixelVisibilityQuery,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CPixelVisibilityQuery,unsigned short>::List_t,unsigned short>,unsigned short> > *this,
        bool multilist)
{
  int m_FirstFree; // ecx
  int m_nAllocationCount; // ecx
  unsigned __int16 index; // ax
  int result; // eax
  int v7; // ecx
  unsigned __int16 v8; // ax
  UtlLinkedListElem_t<CUtlMultiList<CPixelVisibilityQuery,unsigned short>::List_t,unsigned short> *v9; // ecx

  m_FirstFree = this->m_FirstFree;
  if ( (_WORD)m_FirstFree != 0xFFFF )
  {
    result = m_FirstFree;
    this->m_FirstFree = this->m_Memory.m_pMemory[m_FirstFree].m_Next;
LABEL_22:
    v9 = &this->m_Memory.m_pMemory[(unsigned __int16)result];
    if ( multilist )
    {
      v9->m_Next = -1;
      v9->m_Previous = -1;
    }
    else
    {
      v9->m_Next = result;
      v9->m_Previous = result;
    }
    return result;
  }
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( this->m_LastAlloc.index >= m_nAllocationCount )
  {
    m_nAllocationCount = this->m_Memory.m_nAllocationCount;
    LOWORD(result) = (m_nAllocationCount > 0) - 1;
  }
  else
  {
    index = this->m_LastAlloc.index;
    if ( (unsigned __int16)(index + 1) >= m_nAllocationCount )
      LOWORD(result) = -1;
    else
      LOWORD(result) = index + 1;
  }
  if ( (unsigned __int16)result >= m_nAllocationCount )
  {
    CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CPixelVisibilityQuery,unsigned short>::List_t,unsigned short>,unsigned short>::Grow(
      (CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short> *)this,
      num: 1);
    this->m_pElements = this->m_Memory.m_pMemory;
    v7 = this->m_Memory.m_nAllocationCount;
    if ( this->m_LastAlloc.index >= v7 )
    {
      v7 = this->m_Memory.m_nAllocationCount;
      LOWORD(result) = (v7 > 0) - 1;
    }
    else
    {
      v8 = this->m_LastAlloc.index;
      LOWORD(result) = (unsigned __int16)(v8 + 1) >= v7 ? -1 : v8 + 1;
    }
    if ( (unsigned __int16)result >= v7 )
    {
      if ( `CUtlLinkedList<CUtlMultiList<CPixelVisibilityQuery,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CPixelVisibilityQuery,unsigned short>::List_t,unsigned short>,unsigned short>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<CUtlMultiList<CPixelVisibilityQuery,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CPixelVisibilityQuery,unsigned short>::List_t,unsigned short>,unsigned short>>::AllocInternal'::`12'::__executeCount;
        _Warning(a1: "CUtlLinkedList overflow! (exhausted memory allocator)\n");
      }
      return 0xFFFF;
    }
  }
  if ( (_WORD)result != 0xFFFF )
  {
    ++this->m_NumAlloced;
    this->m_LastAlloc.index = result;
    result = (unsigned __int16)result;
    goto LABEL_22;
  }
  if ( `CUtlLinkedList<CUtlMultiList<CPixelVisibilityQuery,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CPixelVisibilityQuery,unsigned short>::List_t,unsigned short>,unsigned short>>::AllocInternal'::`19'::__executeCount >= 10 )
    return 0xFFFF;
  ++`CUtlLinkedList<CUtlMultiList<CPixelVisibilityQuery,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CPixelVisibilityQuery,unsigned short>::List_t,unsigned short>,unsigned short>>::AllocInternal'::`19'::__executeCount;
  _Warning(a1: "CUtlLinkedList overflow! (exhausted index range)\n");
  return 0xFFFF;
}

//------------------------------------------------------------------------------
// Address: 0x10084590
// Name: public: void CUtlLinkedList<struct CRopeManager::RopeQueuedRenderCache_t,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<struct CRopeManager::RopeQueuedRenderCache_t,unsigned short>,unsigned short>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CRopeManager::RopeQueuedRenderCache_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CRopeManager::RopeQueuedRenderCache_t,unsigned short>,unsigned short>>::RemoveAll(
        CUtlLinkedList<CRopeManager::RopeQueuedRenderCache_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CRopeManager::RopeQueuedRenderCache_t,unsigned short>,unsigned short> > *this)
{
  unsigned __int16 m_Head; // dx
  UtlLinkedListElem_t<CRopeManager::RopeQueuedRenderCache_t,unsigned short> *v2; // esi
  unsigned __int16 m_Next; // ax
  unsigned __int16 m_FirstFree; // dx
  unsigned __int16 v5; // ax

  if ( this->m_LastAlloc.index != 0xFFFF )
  {
    m_Head = this->m_Head;
    if ( m_Head != 0xFFFF )
    {
      do
      {
        v2 = &this->m_Memory.m_pMemory[m_Head];
        m_Next = v2->m_Next;
        v2->m_Previous = m_Head;
        if ( m_Next == 0xFFFF )
          m_FirstFree = this->m_FirstFree;
        else
          m_FirstFree = m_Next;
        v2->m_Next = m_FirstFree;
        m_Head = m_Next;
      }
      while ( m_Next != 0xFFFF );
    }
    v5 = this->m_Head;
    if ( v5 != 0xFFFF )
      this->m_FirstFree = v5;
    *(_DWORD *)&this->m_Head = -1;
    this->m_ElementCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10084600
// Name: protected: int CUtlLinkedList<class C_RopeKeyframe __near *,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<class C_RopeKeyframe __near *,int>,int>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<C_RopeKeyframe *,int,0,int,CUtlMemory<UtlLinkedListElem_t<C_RopeKeyframe *,int>,int>>::AllocInternal(
        CUtlLinkedList<C_RopeKeyframe *,int,0,int,CUtlMemory<UtlLinkedListElem_t<C_RopeKeyframe *,int>,int> > *this,
        bool multilist)
{
  int result; // eax
  int index; // eax
  int m_nAllocationCount; // ecx
  int v6; // eax
  int v7; // ecx
  UtlLinkedListElem_t<C_RopeKeyframe *,int> *v8; // ecx

  result = this->m_FirstFree;
  if ( result != -1 )
  {
    this->m_FirstFree = this->m_Memory.m_pMemory[result].m_Next;
LABEL_23:
    v8 = &this->m_Memory.m_pMemory[result];
    if ( multilist )
    {
      v8->m_Next = -1;
      v8->m_Previous = -1;
    }
    else
    {
      v8->m_Next = result;
      v8->m_Previous = result;
    }
    return result;
  }
  index = this->m_LastAlloc.index;
  if ( index < 0 || (m_nAllocationCount = this->m_Memory.m_nAllocationCount, index >= m_nAllocationCount) )
  {
    m_nAllocationCount = this->m_Memory.m_nAllocationCount;
    result = (m_nAllocationCount > 0) - 1;
  }
  else
  {
    result = index + 1;
    if ( result < 0 || result >= m_nAllocationCount )
      result = -1;
  }
  if ( result < 0 || result >= m_nAllocationCount )
  {
    CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int>::Grow(
      (CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int> *)this,
      num: 1);
    this->m_pElements = this->m_Memory.m_pMemory;
    v6 = this->m_LastAlloc.index;
    if ( v6 < 0 || (v7 = this->m_Memory.m_nAllocationCount, v6 >= v7) )
    {
      v7 = this->m_Memory.m_nAllocationCount;
      result = (v7 > 0) - 1;
    }
    else
    {
      result = v6 + 1;
      if ( result < 0 || result >= v7 )
        result = -1;
    }
    if ( result < 0 || result >= v7 )
    {
      if ( `CUtlLinkedList<C_RopeKeyframe *,int,0,int,CUtlMemory<UtlLinkedListElem_t<C_RopeKeyframe *,int>,int>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<C_RopeKeyframe *,int,0,int,CUtlMemory<UtlLinkedListElem_t<C_RopeKeyframe *,int>,int>>::AllocInternal'::`12'::__executeCount;
        _Warning(a1: "CUtlLinkedList overflow! (exhausted memory allocator)\n");
      }
      return -1;
    }
  }
  ++this->m_NumAlloced;
  this->m_LastAlloc.index = result;
  goto LABEL_23;
}

//------------------------------------------------------------------------------
// Address: 0x10084730
// Name: protected: unsigned short CUtlLinkedList<struct CRopeManager::RopeQueuedRenderCache_t,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<struct CRopeManager::RopeQueuedRenderCache_t,unsigned short>,unsigned short>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<CRopeManager::RopeQueuedRenderCache_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CRopeManager::RopeQueuedRenderCache_t,unsigned short>,unsigned short>>::AllocInternal(
        CUtlLinkedList<CRopeManager::RopeQueuedRenderCache_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CRopeManager::RopeQueuedRenderCache_t,unsigned short>,unsigned short> > *this,
        bool multilist)
{
  int m_FirstFree; // ecx
  int m_nAllocationCount; // ecx
  unsigned __int16 index; // ax
  int result; // eax
  int v7; // ecx
  unsigned __int16 v8; // ax
  UtlLinkedListElem_t<CRopeManager::RopeQueuedRenderCache_t,unsigned short> *m_pMemory; // edx
  int v10; // ecx
  UtlLinkedListElem_t<CRopeManager::RopeQueuedRenderCache_t,unsigned short> *v11; // ecx

  m_FirstFree = this->m_FirstFree;
  if ( (_WORD)m_FirstFree != 0xFFFF )
  {
    result = m_FirstFree;
    this->m_FirstFree = this->m_Memory.m_pMemory[m_FirstFree].m_Next;
LABEL_22:
    if ( multilist )
    {
      v11 = &this->m_Memory.m_pMemory[(unsigned __int16)result];
      v11->m_Next = -1;
      v11->m_Previous = -1;
    }
    else
    {
      m_pMemory = this->m_Memory.m_pMemory;
      v10 = (unsigned __int16)result;
      m_pMemory[v10].m_Next = result;
      m_pMemory[v10].m_Previous = result;
    }
    return result;
  }
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( this->m_LastAlloc.index >= m_nAllocationCount )
  {
    m_nAllocationCount = this->m_Memory.m_nAllocationCount;
    LOWORD(result) = (m_nAllocationCount > 0) - 1;
  }
  else
  {
    index = this->m_LastAlloc.index;
    if ( (unsigned __int16)(index + 1) >= m_nAllocationCount )
      LOWORD(result) = -1;
    else
      LOWORD(result) = index + 1;
  }
  if ( (unsigned __int16)result >= m_nAllocationCount )
  {
    CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,CBaseAchievement *,unsigned short>::Node_t,unsigned short>,unsigned short>::Grow(
      (CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,CBaseAchievement *,unsigned short>::Node_t,unsigned short>,unsigned short> *)this,
      num: 1);
    this->m_pElements = this->m_Memory.m_pMemory;
    v7 = this->m_Memory.m_nAllocationCount;
    if ( this->m_LastAlloc.index >= v7 )
    {
      v7 = this->m_Memory.m_nAllocationCount;
      LOWORD(result) = (v7 > 0) - 1;
    }
    else
    {
      v8 = this->m_LastAlloc.index;
      LOWORD(result) = (unsigned __int16)(v8 + 1) >= v7 ? -1 : v8 + 1;
    }
    if ( (unsigned __int16)result >= v7 )
    {
      if ( `CUtlLinkedList<CRopeManager::RopeQueuedRenderCache_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CRopeManager::RopeQueuedRenderCache_t,unsigned short>,unsigned short>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<CRopeManager::RopeQueuedRenderCache_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CRopeManager::RopeQueuedRenderCache_t,unsigned short>,unsigned short>>::AllocInternal'::`12'::__executeCount;
        _Warning(a1: "CUtlLinkedList overflow! (exhausted memory allocator)\n");
      }
      return 0xFFFF;
    }
  }
  if ( (_WORD)result != 0xFFFF )
  {
    ++this->m_NumAlloced;
    this->m_LastAlloc.index = result;
    result = (unsigned __int16)result;
    goto LABEL_22;
  }
  if ( `CUtlLinkedList<CRopeManager::RopeQueuedRenderCache_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CRopeManager::RopeQueuedRenderCache_t,unsigned short>,unsigned short>>::AllocInternal'::`19'::__executeCount >= 10 )
    return 0xFFFF;
  ++`CUtlLinkedList<CRopeManager::RopeQueuedRenderCache_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CRopeManager::RopeQueuedRenderCache_t,unsigned short>,unsigned short>>::AllocInternal'::`19'::__executeCount;
  _Warning(a1: "CUtlLinkedList overflow! (exhausted index range)\n");
  return 0xFFFF;
}

//------------------------------------------------------------------------------
// Address: 0x10084E70
// Name: public: void CUtlLinkedList<class CDataChangedEvent,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<class CDataChangedEvent,unsigned short>,unsigned short>>::Unlink(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CDataChangedEvent,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CDataChangedEvent,unsigned short>,unsigned short>>::Unlink(
        CUtlLinkedList<CRopeManager::RopeQueuedRenderCache_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CRopeManager::RopeQueuedRenderCache_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 elem)
{
  unsigned __int16 v2; // bx
  UtlLinkedListElem_t<CRopeManager::RopeQueuedRenderCache_t,unsigned short> *v3; // eax
  int m_Previous; // edi
  unsigned __int16 m_Next; // dx

  v2 = elem;
  if ( elem < this->m_Memory.m_nAllocationCount && elem <= this->m_LastAlloc.index )
  {
    v3 = &this->m_Memory.m_pMemory[elem];
    if ( v3->m_Previous != elem )
    {
      m_Previous = v3->m_Previous;
      m_Next = v3->m_Next;
      if ( (_WORD)m_Previous == 0xFFFF )
      {
        this->m_Head = m_Next;
      }
      else
      {
        this->m_Memory.m_pMemory[m_Previous].m_Next = m_Next;
        v2 = elem;
      }
      if ( m_Next == 0xFFFF )
        this->m_Tail = m_Previous;
      else
        this->m_Memory.m_pMemory[m_Next].m_Previous = m_Previous;
      v3->m_Next = v2;
      v3->m_Previous = v2;
      --this->m_ElementCount;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10086850
// Name: public: int CUtlLinkedList<class C_RopeKeyframe __near *,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<class C_RopeKeyframe __near *,int>,int>>::AddToTail(class C_RopeKeyframe __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<C_RopeKeyframe *,int,0,int,CUtlMemory<UtlLinkedListElem_t<C_RopeKeyframe *,int>,int>>::AddToTail(
        CUtlLinkedList<C_RopeKeyframe *,int,0,int,CUtlMemory<UtlLinkedListElem_t<C_RopeKeyframe *,int>,int> > *this,
        C_RopeKeyframe **src)
{
  int result; // eax
  int v4; // edi
  UtlLinkedListElem_t<C_RopeKeyframe *,int> *m_pMemory; // eax
  unsigned int v6; // ecx
  int m_Tail; // edx
  UtlLinkedListElem_t<C_RopeKeyframe *,int> *v8; // esi

  result = CUtlLinkedList<C_RopeKeyframe *,int,0,int,CUtlMemory<UtlLinkedListElem_t<C_RopeKeyframe *,int>,int>>::AllocInternal(
             this,
             multilist: false);
  v4 = result;
  if ( result != -1 )
  {
    CUtlLinkedList<vgui::MenuItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::MenuItem *,int>,int>>::Unlink(
      (CUtlLinkedList<vgui::TreeNode *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int> > *)this,
      elem: result);
    m_pMemory = this->m_Memory.m_pMemory;
    v6 = v4;
    m_pMemory[v6].m_Next = -1;
    m_Tail = this->m_Tail;
    m_pMemory[v6].m_Previous = m_Tail;
    this->m_Tail = v4;
    if ( m_Tail == -1 )
      this->m_Head = v4;
    else
      this->m_Memory.m_pMemory[m_Tail].m_Next = v4;
    ++this->m_ElementCount;
    v8 = &this->m_Memory.m_pMemory[v6];
    if ( v8 != nullptr )
      v8->m_Element = *src;
    return v4;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100868C0
// Name: public: bool CUtlLinkedList<class C_RopeKeyframe __near *,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<class C_RopeKeyframe __near *,int>,int>>::FindAndRemove(class C_RopeKeyframe __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CUtlLinkedList<C_RopeKeyframe *,int,0,int,CUtlMemory<UtlLinkedListElem_t<C_RopeKeyframe *,int>,int>>::FindAndRemove(
        CUtlLinkedList<C_RopeKeyframe *,int,0,int,CUtlMemory<UtlLinkedListElem_t<C_RopeKeyframe *,int>,int> > *this,
        C_RopeKeyframe **src)
{
  int m_Head; // esi
  UtlLinkedListElem_t<C_RopeKeyframe *,int> *m_pMemory; // edx

  m_Head = this->m_Head;
  if ( m_Head == -1 )
    return 0;
  m_pMemory = this->m_Memory.m_pMemory;
  while ( m_pMemory[m_Head].m_Element != *src )
  {
    m_Head = m_pMemory[m_Head].m_Next;
    if ( m_Head == -1 )
      return 0;
  }
  CUtlLinkedList<vgui::MenuItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::MenuItem *,int>,int>>::Unlink(
    (CUtlLinkedList<vgui::TreeNode *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int> > *)this,
    elem: m_Head);
  this->m_Memory.m_pMemory[m_Head].m_Next = this->m_FirstFree;
  this->m_FirstFree = m_Head;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100920A0
// Name: public: void CUtlLinkedList<class CTeslaInfo,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<class CTeslaInfo,int>,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CTeslaInfo,int,0,int,CUtlMemory<UtlLinkedListElem_t<CTeslaInfo,int>,int>>::RemoveAll(
        CUtlLinkedList<CTeslaInfo,int,0,int,CUtlMemory<UtlLinkedListElem_t<CTeslaInfo,int>,int> > *this)
{
  int m_Head; // eax
  UtlLinkedListElem_t<CTeslaInfo,int> *v2; // esi
  int m_Next; // edx
  int m_FirstFree; // eax
  int v5; // eax

  if ( this->m_LastAlloc.index != -1 )
  {
    m_Head = this->m_Head;
    if ( m_Head != -1 )
    {
      do
      {
        v2 = &this->m_Memory.m_pMemory[m_Head];
        m_Next = v2->m_Next;
        v2->m_Previous = m_Head;
        if ( m_Next == -1 )
          m_FirstFree = this->m_FirstFree;
        else
          m_FirstFree = m_Next;
        v2->m_Next = m_FirstFree;
        m_Head = m_Next;
      }
      while ( m_Next != -1 );
    }
    v5 = this->m_Head;
    if ( v5 != -1 )
      this->m_FirstFree = v5;
    this->m_Head = -1;
    this->m_Tail = -1;
    this->m_ElementCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10092100
// Name: protected: int CUtlLinkedList<class CTeslaInfo,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<class CTeslaInfo,int>,int>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<CTeslaInfo,int,0,int,CUtlMemory<UtlLinkedListElem_t<CTeslaInfo,int>,int>>::AllocInternal(
        CUtlLinkedList<CTeslaInfo,int,0,int,CUtlMemory<UtlLinkedListElem_t<CTeslaInfo,int>,int> > *this,
        bool multilist)
{
  int result; // eax
  int index; // eax
  int m_nAllocationCount; // ecx
  int v6; // eax
  int v7; // ecx
  UtlLinkedListElem_t<CTeslaInfo,int> *v8; // ecx

  result = this->m_FirstFree;
  if ( result != -1 )
  {
    this->m_FirstFree = this->m_Memory.m_pMemory[result].m_Next;
LABEL_23:
    v8 = &this->m_Memory.m_pMemory[result];
    if ( multilist )
    {
      v8->m_Next = -1;
      v8->m_Previous = -1;
    }
    else
    {
      v8->m_Next = result;
      v8->m_Previous = result;
    }
    return result;
  }
  index = this->m_LastAlloc.index;
  if ( index < 0 || (m_nAllocationCount = this->m_Memory.m_nAllocationCount, index >= m_nAllocationCount) )
  {
    m_nAllocationCount = this->m_Memory.m_nAllocationCount;
    result = (m_nAllocationCount > 0) - 1;
  }
  else
  {
    result = index + 1;
    if ( result < 0 || result >= m_nAllocationCount )
      result = -1;
  }
  if ( result < 0 || result >= m_nAllocationCount )
  {
    CUtlMemory<UtlLinkedListElem_t<CTeslaInfo,int>,int>::Grow(
      (CUtlMemory<vgui::AnimationController::ActiveAnimation_t,int> *)this,
      num: 1);
    this->m_pElements = this->m_Memory.m_pMemory;
    v6 = this->m_LastAlloc.index;
    if ( v6 < 0 || (v7 = this->m_Memory.m_nAllocationCount, v6 >= v7) )
    {
      v7 = this->m_Memory.m_nAllocationCount;
      result = (v7 > 0) - 1;
    }
    else
    {
      result = v6 + 1;
      if ( result < 0 || result >= v7 )
        result = -1;
    }
    if ( result < 0 || result >= v7 )
    {
      if ( `CUtlLinkedList<CTeslaInfo,int,0,int,CUtlMemory<UtlLinkedListElem_t<CTeslaInfo,int>,int>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<CTeslaInfo,int,0,int,CUtlMemory<UtlLinkedListElem_t<CTeslaInfo,int>,int>>::AllocInternal'::`12'::__executeCount;
        _Warning(a1: "CUtlLinkedList overflow! (exhausted memory allocator)\n");
      }
      return -1;
    }
  }
  ++this->m_NumAlloced;
  this->m_LastAlloc.index = result;
  goto LABEL_23;
}

//------------------------------------------------------------------------------
// Address: 0x10092230
// Name: public: void CUtlLinkedList<class CTeslaInfo,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<class CTeslaInfo,int>,int>>::Unlink(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CTeslaInfo,int,0,int,CUtlMemory<UtlLinkedListElem_t<CTeslaInfo,int>,int>>::Unlink(
        CUtlLinkedList<CTeslaInfo,int,0,int,CUtlMemory<UtlLinkedListElem_t<CTeslaInfo,int>,int> > *this,
        int elem)
{
  UtlLinkedListElem_t<CTeslaInfo,int> *v2; // eax
  int m_Next; // edx
  int m_Previous; // edi
  int v5; // edx

  if ( elem >= 0 && elem < this->m_Memory.m_nAllocationCount && elem <= this->m_LastAlloc.index )
  {
    v2 = &this->m_Memory.m_pMemory[elem];
    if ( v2->m_Previous != elem )
    {
      m_Next = v2->m_Next;
      m_Previous = v2->m_Previous;
      if ( m_Previous == -1 )
        this->m_Head = m_Next;
      else
        this->m_Memory.m_pMemory[m_Previous].m_Next = m_Next;
      if ( m_Next == -1 )
      {
        v5 = v2->m_Previous;
        --this->m_ElementCount;
        this->m_Tail = v5;
      }
      else
      {
        this->m_Memory.m_pMemory[m_Next].m_Previous = v2->m_Previous;
        --this->m_ElementCount;
      }
      v2->m_Next = elem;
      v2->m_Previous = elem;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100924C0
// Name: public: int CUtlLinkedList<class CTeslaInfo,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<class CTeslaInfo,int>,int>>::AddToTail(class CTeslaInfo const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<CTeslaInfo,int,0,int,CUtlMemory<UtlLinkedListElem_t<CTeslaInfo,int>,int>>::AddToTail(
        CUtlLinkedList<CTeslaInfo,int,0,int,CUtlMemory<UtlLinkedListElem_t<CTeslaInfo,int>,int> > *this,
        const CTeslaInfo *src)
{
  int result; // eax
  int v4; // ebx
  UtlLinkedListElem_t<CTeslaInfo,int> *m_pMemory; // ecx
  unsigned int v6; // eax
  int m_Tail; // edx
  UtlLinkedListElem_t<CTeslaInfo,int> *v8; // edi

  result = CUtlLinkedList<CTeslaInfo,int,0,int,CUtlMemory<UtlLinkedListElem_t<CTeslaInfo,int>,int>>::AllocInternal(
             this,
             multilist: false);
  v4 = result;
  if ( result != -1 )
  {
    CUtlLinkedList<CTeslaInfo,int,0,int,CUtlMemory<UtlLinkedListElem_t<CTeslaInfo,int>,int>>::Unlink(this, elem: result);
    m_pMemory = this->m_Memory.m_pMemory;
    v6 = v4;
    m_pMemory[v6].m_Next = -1;
    m_Tail = this->m_Tail;
    m_pMemory[v6].m_Previous = m_Tail;
    this->m_Tail = v4;
    if ( m_Tail == -1 )
      this->m_Head = v4;
    else
      this->m_Memory.m_pMemory[m_Tail].m_Next = v4;
    ++this->m_ElementCount;
    v8 = &this->m_Memory.m_pMemory[v6];
    if ( v8 != nullptr )
      qmemcpy(v8, src, 0x3Cu);
    return v4;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1009AA10
// Name: protected: unsigned short CUtlLinkedList<class CDataChangedEvent,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<class CDataChangedEvent,unsigned short>,unsigned short>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<CDataChangedEvent,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CDataChangedEvent,unsigned short>,unsigned short>>::AllocInternal(
        CUtlLinkedList<CDataChangedEvent,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CDataChangedEvent,unsigned short>,unsigned short> > *this,
        bool multilist)
{
  int m_FirstFree; // ecx
  int m_nAllocationCount; // ecx
  unsigned __int16 index; // ax
  int result; // eax
  int v7; // ecx
  unsigned __int16 v8; // ax
  UtlLinkedListElem_t<CDataChangedEvent,unsigned short> *m_pMemory; // edx
  int v10; // ecx
  UtlLinkedListElem_t<CDataChangedEvent,unsigned short> *v11; // ecx

  m_FirstFree = this->m_FirstFree;
  if ( (_WORD)m_FirstFree != 0xFFFF )
  {
    result = m_FirstFree;
    this->m_FirstFree = this->m_Memory.m_pMemory[m_FirstFree].m_Next;
LABEL_22:
    if ( multilist )
    {
      v11 = &this->m_Memory.m_pMemory[(unsigned __int16)result];
      v11->m_Next = -1;
      v11->m_Previous = -1;
    }
    else
    {
      m_pMemory = this->m_Memory.m_pMemory;
      v10 = (unsigned __int16)result;
      m_pMemory[v10].m_Next = result;
      m_pMemory[v10].m_Previous = result;
    }
    return result;
  }
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( this->m_LastAlloc.index >= m_nAllocationCount )
  {
    m_nAllocationCount = this->m_Memory.m_nAllocationCount;
    LOWORD(result) = (m_nAllocationCount > 0) - 1;
  }
  else
  {
    index = this->m_LastAlloc.index;
    if ( (unsigned __int16)(index + 1) >= m_nAllocationCount )
      LOWORD(result) = -1;
    else
      LOWORD(result) = index + 1;
  }
  if ( (unsigned __int16)result >= m_nAllocationCount )
  {
    CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,CBaseAchievement *,unsigned short>::Node_t,unsigned short>,unsigned short>::Grow(
      (CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,CBaseAchievement *,unsigned short>::Node_t,unsigned short>,unsigned short> *)this,
      num: 1);
    this->m_pElements = this->m_Memory.m_pMemory;
    v7 = this->m_Memory.m_nAllocationCount;
    if ( this->m_LastAlloc.index >= v7 )
    {
      v7 = this->m_Memory.m_nAllocationCount;
      LOWORD(result) = (v7 > 0) - 1;
    }
    else
    {
      v8 = this->m_LastAlloc.index;
      LOWORD(result) = (unsigned __int16)(v8 + 1) >= v7 ? -1 : v8 + 1;
    }
    if ( (unsigned __int16)result >= v7 )
    {
      if ( `CUtlLinkedList<CDataChangedEvent,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CDataChangedEvent,unsigned short>,unsigned short>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<CDataChangedEvent,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CDataChangedEvent,unsigned short>,unsigned short>>::AllocInternal'::`12'::__executeCount;
        _Warning(a1: "CUtlLinkedList overflow! (exhausted memory allocator)\n");
      }
      return 0xFFFF;
    }
  }
  if ( (_WORD)result != 0xFFFF )
  {
    ++this->m_NumAlloced;
    this->m_LastAlloc.index = result;
    result = (unsigned __int16)result;
    goto LABEL_22;
  }
  if ( `CUtlLinkedList<CDataChangedEvent,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CDataChangedEvent,unsigned short>,unsigned short>>::AllocInternal'::`19'::__executeCount >= 10 )
    return 0xFFFF;
  ++`CUtlLinkedList<CDataChangedEvent,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CDataChangedEvent,unsigned short>,unsigned short>>::AllocInternal'::`19'::__executeCount;
  _Warning(a1: "CUtlLinkedList overflow! (exhausted index range)\n");
  return 0xFFFF;
}

//------------------------------------------------------------------------------
// Address: 0x1009D310
// Name: public: void CUtlLinkedList<struct CRopeManager::RopeQueuedRenderCache_t,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<struct CRopeManager::RopeQueuedRenderCache_t,unsigned short>,unsigned short>>::LinkBefore(unsigned short,unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CRopeManager::RopeQueuedRenderCache_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CRopeManager::RopeQueuedRenderCache_t,unsigned short>,unsigned short>>::LinkBefore(
        CUtlLinkedList<CRopeManager::RopeQueuedRenderCache_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CRopeManager::RopeQueuedRenderCache_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 before,
        unsigned __int16 elem)
{
  UtlLinkedListElem_t<CRopeManager::RopeQueuedRenderCache_t,unsigned short> *m_pMemory; // ebx
  unsigned __int16 m_Tail; // dx

  CUtlLinkedList<CDataChangedEvent,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CDataChangedEvent,unsigned short>,unsigned short>>::Unlink(
    this,
    elem);
  m_pMemory = this->m_Memory.m_pMemory;
  this->m_Memory.m_pMemory[elem].m_Next = before;
  if ( before == 0xFFFF )
  {
    m_Tail = this->m_Tail;
    m_pMemory[elem].m_Previous = m_Tail;
    this->m_Tail = elem;
  }
  else
  {
    m_Tail = m_pMemory[before].m_Previous;
    m_pMemory[elem].m_Previous = m_Tail;
    m_pMemory[before].m_Previous = elem;
  }
  if ( m_Tail == 0xFFFF )
  {
    ++this->m_ElementCount;
    this->m_Head = elem;
  }
  else
  {
    m_pMemory[m_Tail].m_Next = elem;
    ++this->m_ElementCount;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A2710
// Name: public: void CUtlLinkedList<struct CClientThinkList::ThinkEntry_t,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<struct CClientThinkList::ThinkEntry_t,unsigned short>,unsigned short>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CClientThinkList::ThinkEntry_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CClientThinkList::ThinkEntry_t,unsigned short>,unsigned short>>::RemoveAll(
        CUtlLinkedList<CClientThinkList::ThinkEntry_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CClientThinkList::ThinkEntry_t,unsigned short>,unsigned short> > *this)
{
  unsigned __int16 m_Head; // si
  UtlLinkedListElem_t<CClientThinkList::ThinkEntry_t,unsigned short> *v2; // edx
  unsigned __int16 m_Next; // ax
  unsigned __int16 m_FirstFree; // si
  unsigned __int16 v5; // ax

  if ( this->m_LastAlloc.index != 0xFFFF )
  {
    m_Head = this->m_Head;
    if ( m_Head != 0xFFFF )
    {
      do
      {
        v2 = &this->m_Memory.m_pMemory[m_Head];
        m_Next = v2->m_Next;
        v2->m_Previous = m_Head;
        if ( m_Next == 0xFFFF )
          m_FirstFree = this->m_FirstFree;
        else
          m_FirstFree = m_Next;
        v2->m_Next = m_FirstFree;
        m_Head = m_Next;
      }
      while ( m_Next != 0xFFFF );
    }
    v5 = this->m_Head;
    if ( v5 != 0xFFFF )
      this->m_FirstFree = v5;
    *(_DWORD *)&this->m_Head = -1;
    this->m_ElementCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A2780
// Name: public: void CUtlLinkedList<struct CClientThinkList::ThinkEntry_t,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<struct CClientThinkList::ThinkEntry_t,unsigned short>,unsigned short>>::Unlink(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CClientThinkList::ThinkEntry_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CClientThinkList::ThinkEntry_t,unsigned short>,unsigned short>>::Unlink(
        CUtlLinkedList<CClientThinkList::ThinkEntry_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CClientThinkList::ThinkEntry_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 elem)
{
  unsigned __int16 v2; // di
  UtlLinkedListElem_t<CClientThinkList::ThinkEntry_t,unsigned short> *v3; // eax
  int m_Previous; // ebx
  unsigned __int16 m_Next; // dx

  v2 = elem;
  if ( elem < this->m_Memory.m_nAllocationCount && elem <= this->m_LastAlloc.index )
  {
    v3 = &this->m_Memory.m_pMemory[elem];
    if ( v3->m_Previous != elem )
    {
      m_Previous = v3->m_Previous;
      m_Next = v3->m_Next;
      if ( (_WORD)m_Previous == 0xFFFF )
      {
        this->m_Head = m_Next;
      }
      else
      {
        this->m_Memory.m_pMemory[m_Previous].m_Next = m_Next;
        v2 = elem;
      }
      if ( m_Next == 0xFFFF )
        this->m_Tail = m_Previous;
      else
        this->m_Memory.m_pMemory[m_Next].m_Previous = m_Previous;
      v3->m_Next = v2;
      v3->m_Previous = v2;
      --this->m_ElementCount;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A2A00
// Name: public: void CUtlLinkedList<struct CClientThinkList::ThinkEntry_t,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<struct CClientThinkList::ThinkEntry_t,unsigned short>,unsigned short>>::LinkBefore(unsigned short,unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CClientThinkList::ThinkEntry_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CClientThinkList::ThinkEntry_t,unsigned short>,unsigned short>>::LinkBefore(
        CUtlLinkedList<CClientThinkList::ThinkEntry_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CClientThinkList::ThinkEntry_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 before,
        unsigned __int16 elem)
{
  UtlLinkedListElem_t<CClientThinkList::ThinkEntry_t,unsigned short> *m_pMemory; // edx
  UtlLinkedListElem_t<CClientThinkList::ThinkEntry_t,unsigned short> *v5; // ecx
  unsigned __int16 m_Tail; // ax
  UtlLinkedListElem_t<CClientThinkList::ThinkEntry_t,unsigned short> *v7; // ebx

  CUtlLinkedList<CClientThinkList::ThinkEntry_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CClientThinkList::ThinkEntry_t,unsigned short>,unsigned short>>::Unlink(
    this,
    elem);
  m_pMemory = this->m_Memory.m_pMemory;
  v5 = &this->m_Memory.m_pMemory[elem];
  v5->m_Next = before;
  if ( before == 0xFFFF )
  {
    m_Tail = this->m_Tail;
    v5->m_Previous = m_Tail;
    this->m_Tail = elem;
  }
  else
  {
    v7 = &m_pMemory[before];
    m_Tail = v7->m_Previous;
    v5->m_Previous = m_Tail;
    v7->m_Previous = elem;
  }
  if ( m_Tail == 0xFFFF )
  {
    ++this->m_ElementCount;
    this->m_Head = elem;
  }
  else
  {
    m_pMemory[m_Tail].m_Next = elem;
    ++this->m_ElementCount;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A2A90
// Name: protected: unsigned short CUtlLinkedList<struct CClientThinkList::ThinkEntry_t,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<struct CClientThinkList::ThinkEntry_t,unsigned short>,unsigned short>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<CClientThinkList::ThinkEntry_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CClientThinkList::ThinkEntry_t,unsigned short>,unsigned short>>::AllocInternal(
        CUtlLinkedList<CClientThinkList::ThinkEntry_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CClientThinkList::ThinkEntry_t,unsigned short>,unsigned short> > *this,
        bool multilist)
{
  int m_FirstFree; // ecx
  int m_nAllocationCount; // ecx
  unsigned __int16 index; // ax
  int result; // eax
  int v7; // ecx
  unsigned __int16 v8; // ax
  UtlLinkedListElem_t<CClientThinkList::ThinkEntry_t,unsigned short> *v9; // ecx

  m_FirstFree = this->m_FirstFree;
  if ( (_WORD)m_FirstFree != 0xFFFF )
  {
    result = m_FirstFree;
    this->m_FirstFree = this->m_Memory.m_pMemory[m_FirstFree].m_Next;
LABEL_22:
    v9 = &this->m_Memory.m_pMemory[(unsigned __int16)result];
    if ( multilist )
    {
      v9->m_Next = -1;
      v9->m_Previous = -1;
    }
    else
    {
      v9->m_Next = result;
      v9->m_Previous = result;
    }
    return result;
  }
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( this->m_LastAlloc.index >= m_nAllocationCount )
  {
    m_nAllocationCount = this->m_Memory.m_nAllocationCount;
    LOWORD(result) = (m_nAllocationCount > 0) - 1;
  }
  else
  {
    index = this->m_LastAlloc.index;
    if ( (unsigned __int16)(index + 1) >= m_nAllocationCount )
      LOWORD(result) = -1;
    else
      LOWORD(result) = index + 1;
  }
  if ( (unsigned __int16)result >= m_nAllocationCount )
  {
    CUtlMemory<UtlRBTreeNode_t<C_BaseFlex::FS_LocalToGlobal_t,unsigned short>,unsigned short>::Grow(
      (CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,CControllerMap::button_t,unsigned short>::Node_t,unsigned short>,unsigned short> *)this,
      num: 1);
    this->m_pElements = this->m_Memory.m_pMemory;
    v7 = this->m_Memory.m_nAllocationCount;
    if ( this->m_LastAlloc.index >= v7 )
    {
      v7 = this->m_Memory.m_nAllocationCount;
      LOWORD(result) = (v7 > 0) - 1;
    }
    else
    {
      v8 = this->m_LastAlloc.index;
      LOWORD(result) = (unsigned __int16)(v8 + 1) >= v7 ? -1 : v8 + 1;
    }
    if ( (unsigned __int16)result >= v7 )
    {
      if ( `CUtlLinkedList<CClientThinkList::ThinkEntry_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CClientThinkList::ThinkEntry_t,unsigned short>,unsigned short>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<CClientThinkList::ThinkEntry_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CClientThinkList::ThinkEntry_t,unsigned short>,unsigned short>>::AllocInternal'::`12'::__executeCount;
        _Warning(a1: "CUtlLinkedList overflow! (exhausted memory allocator)\n");
      }
      return 0xFFFF;
    }
  }
  if ( (_WORD)result != 0xFFFF )
  {
    ++this->m_NumAlloced;
    this->m_LastAlloc.index = result;
    result = (unsigned __int16)result;
    goto LABEL_22;
  }
  if ( `CUtlLinkedList<CClientThinkList::ThinkEntry_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CClientThinkList::ThinkEntry_t,unsigned short>,unsigned short>>::AllocInternal'::`19'::__executeCount >= 10 )
    return 0xFFFF;
  ++`CUtlLinkedList<CClientThinkList::ThinkEntry_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CClientThinkList::ThinkEntry_t,unsigned short>,unsigned short>>::AllocInternal'::`19'::__executeCount;
  _Warning(a1: "CUtlLinkedList overflow! (exhausted index range)\n");
  return 0xFFFF;
}

//------------------------------------------------------------------------------
// Address: 0x100A2E40
// Name: public: unsigned short CUtlLinkedList<struct CClientThinkList::ThinkEntry_t,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<struct CClientThinkList::ThinkEntry_t,unsigned short>,unsigned short>>::AddToTail(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<CClientThinkList::ThinkEntry_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CClientThinkList::ThinkEntry_t,unsigned short>,unsigned short>>::AddToTail(
        CUtlLinkedList<CClientThinkList::ThinkEntry_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CClientThinkList::ThinkEntry_t,unsigned short>,unsigned short> > *this)
{
  int v2; // esi
  int result; // eax
  UtlLinkedListElem_t<CClientThinkList::ThinkEntry_t,unsigned short> *v4; // eax

  v2 = (unsigned __int16)CUtlLinkedList<CClientThinkList::ThinkEntry_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CClientThinkList::ThinkEntry_t,unsigned short>,unsigned short>>::AllocInternal(
                           this,
                           multilist: false);
  result = 0xFFFF;
  if ( (_WORD)v2 != 0xFFFF )
  {
    CUtlLinkedList<CClientThinkList::ThinkEntry_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CClientThinkList::ThinkEntry_t,unsigned short>,unsigned short>>::LinkBefore(
      this,
      before: 0xFFFFu,
      elem: v2);
    v4 = &this->m_Memory.m_pMemory[v2];
    if ( v4 != nullptr )
      v4->m_Element.m_hEnt.m_Index = -1;
    return v2;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100A4110
// Name: protected: unsigned short CUtlLinkedList<class CClientEntityList::CPVSNotifyInfo,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<class CClientEntityList::CPVSNotifyInfo,unsigned short>,unsigned short>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<CClientEntityList::CPVSNotifyInfo,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CClientEntityList::CPVSNotifyInfo,unsigned short>,unsigned short>>::AllocInternal(
        CUtlLinkedList<CClientEntityList::CPVSNotifyInfo,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CClientEntityList::CPVSNotifyInfo,unsigned short>,unsigned short> > *this,
        bool multilist)
{
  int m_FirstFree; // ecx
  int m_nAllocationCount; // ecx
  unsigned __int16 index; // ax
  int result; // eax
  int v7; // ecx
  unsigned __int16 v8; // ax
  UtlLinkedListElem_t<CClientEntityList::CPVSNotifyInfo,unsigned short> *m_pMemory; // edx
  int v10; // ecx
  UtlLinkedListElem_t<CClientEntityList::CPVSNotifyInfo,unsigned short> *v11; // ecx

  m_FirstFree = this->m_FirstFree;
  if ( (_WORD)m_FirstFree != 0xFFFF )
  {
    result = m_FirstFree;
    this->m_FirstFree = this->m_Memory.m_pMemory[m_FirstFree].m_Next;
LABEL_22:
    if ( multilist )
    {
      v11 = &this->m_Memory.m_pMemory[(unsigned __int16)result];
      v11->m_Next = -1;
      v11->m_Previous = -1;
    }
    else
    {
      m_pMemory = this->m_Memory.m_pMemory;
      v10 = (unsigned __int16)result;
      m_pMemory[v10].m_Next = result;
      m_pMemory[v10].m_Previous = result;
    }
    return result;
  }
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( this->m_LastAlloc.index >= m_nAllocationCount )
  {
    m_nAllocationCount = this->m_Memory.m_nAllocationCount;
    LOWORD(result) = (m_nAllocationCount > 0) - 1;
  }
  else
  {
    index = this->m_LastAlloc.index;
    if ( (unsigned __int16)(index + 1) >= m_nAllocationCount )
      LOWORD(result) = -1;
    else
      LOWORD(result) = index + 1;
  }
  if ( (unsigned __int16)result >= m_nAllocationCount )
  {
    CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,CBaseAchievement *,unsigned short>::Node_t,unsigned short>,unsigned short>::Grow(
      (CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,CBaseAchievement *,unsigned short>::Node_t,unsigned short>,unsigned short> *)this,
      num: 1);
    this->m_pElements = this->m_Memory.m_pMemory;
    v7 = this->m_Memory.m_nAllocationCount;
    if ( this->m_LastAlloc.index >= v7 )
    {
      v7 = this->m_Memory.m_nAllocationCount;
      LOWORD(result) = (v7 > 0) - 1;
    }
    else
    {
      v8 = this->m_LastAlloc.index;
      LOWORD(result) = (unsigned __int16)(v8 + 1) >= v7 ? -1 : v8 + 1;
    }
    if ( (unsigned __int16)result >= v7 )
    {
      if ( `CUtlLinkedList<CClientEntityList::CPVSNotifyInfo,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CClientEntityList::CPVSNotifyInfo,unsigned short>,unsigned short>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<CClientEntityList::CPVSNotifyInfo,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CClientEntityList::CPVSNotifyInfo,unsigned short>,unsigned short>>::AllocInternal'::`12'::__executeCount;
        _Warning(a1: "CUtlLinkedList overflow! (exhausted memory allocator)\n");
      }
      return 0xFFFF;
    }
  }
  if ( (_WORD)result != 0xFFFF )
  {
    ++this->m_NumAlloced;
    this->m_LastAlloc.index = result;
    result = (unsigned __int16)result;
    goto LABEL_22;
  }
  if ( `CUtlLinkedList<CClientEntityList::CPVSNotifyInfo,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CClientEntityList::CPVSNotifyInfo,unsigned short>,unsigned short>>::AllocInternal'::`19'::__executeCount >= 10 )
    return 0xFFFF;
  ++`CUtlLinkedList<CClientEntityList::CPVSNotifyInfo,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CClientEntityList::CPVSNotifyInfo,unsigned short>,unsigned short>>::AllocInternal'::`19'::__executeCount;
  _Warning(a1: "CUtlLinkedList overflow! (exhausted index range)\n");
  return 0xFFFF;
}

//------------------------------------------------------------------------------
// Address: 0x100A8040
// Name: public: void CUtlLinkedList<struct CClientLeafSystem::RenderableInfo_t,unsigned short,0,unsigned int,class CUtlMemory<struct UtlLinkedListElem_t<struct CClientLeafSystem::RenderableInfo_t,unsigned short>,unsigned int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CClientLeafSystem::RenderableInfo_t,unsigned short,0,unsigned int,CUtlMemory<UtlLinkedListElem_t<CClientLeafSystem::RenderableInfo_t,unsigned short>,unsigned int>>::RemoveAll(
        CUtlLinkedList<CClientLeafSystem::RenderableInfo_t,unsigned short,0,unsigned int,CUtlMemory<UtlLinkedListElem_t<CClientLeafSystem::RenderableInfo_t,unsigned short>,unsigned int> > *this)
{
  unsigned int m_Head; // edx
  UtlLinkedListElem_t<CClientLeafSystem::RenderableInfo_t,unsigned short> *v2; // esi
  unsigned int m_Next; // eax
  unsigned int m_FirstFree; // edx
  unsigned int v5; // eax

  if ( this->m_LastAlloc.index != -1 )
  {
    m_Head = this->m_Head;
    if ( m_Head != 0xFFFF )
    {
      do
      {
        v2 = &this->m_Memory.m_pMemory[m_Head];
        m_Next = v2->m_Next;
        v2->m_Previous = m_Head;
        if ( m_Next == 0xFFFF )
          m_FirstFree = this->m_FirstFree;
        else
          LOWORD(m_FirstFree) = m_Next;
        v2->m_Next = m_FirstFree;
        m_Head = m_Next;
      }
      while ( m_Next != 0xFFFF );
    }
    v5 = this->m_Head;
    if ( v5 != 0xFFFF )
      this->m_FirstFree = v5;
    this->m_Head = 0xFFFF;
    this->m_Tail = 0xFFFF;
    this->m_ElementCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A80B0
// Name: protected: unsigned int CUtlLinkedList<struct CClientLeafSystem::RenderableInfo_t,unsigned short,0,unsigned int,class CUtlMemory<struct UtlLinkedListElem_t<struct CClientLeafSystem::RenderableInfo_t,unsigned short>,unsigned int>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
signed int __thiscall CUtlLinkedList<CClientLeafSystem::RenderableInfo_t,unsigned short,0,unsigned int,CUtlMemory<UtlLinkedListElem_t<CClientLeafSystem::RenderableInfo_t,unsigned short>,unsigned int>>::AllocInternal(
        CUtlLinkedList<CClientLeafSystem::RenderableInfo_t,unsigned short,0,unsigned int,CUtlMemory<UtlLinkedListElem_t<CClientLeafSystem::RenderableInfo_t,unsigned short>,unsigned int> > *this,
        bool multilist)
{
  unsigned int m_FirstFree; // ecx
  signed int index; // eax
  int m_nAllocationCount; // ecx
  signed int result; // eax
  signed int v7; // eax
  int v8; // ecx
  UtlLinkedListElem_t<CClientLeafSystem::RenderableInfo_t,unsigned short> *m_pMemory; // ecx
  unsigned int v10; // edx
  UtlLinkedListElem_t<CClientLeafSystem::RenderableInfo_t,unsigned short> *v11; // ecx

  m_FirstFree = this->m_FirstFree;
  if ( m_FirstFree != 0xFFFF )
  {
    result = m_FirstFree;
    this->m_FirstFree = this->m_Memory.m_pMemory[m_FirstFree].m_Next;
LABEL_27:
    m_pMemory = this->m_Memory.m_pMemory;
    v10 = result;
    if ( multilist )
    {
      v11 = &m_pMemory[v10];
      v11->m_Next = -1;
      v11->m_Previous = -1;
    }
    else
    {
      m_pMemory[v10].m_Next = result;
      m_pMemory[v10].m_Previous = result;
    }
    return result;
  }
  index = this->m_LastAlloc.index;
  if ( index < 0 || (m_nAllocationCount = this->m_Memory.m_nAllocationCount, index >= m_nAllocationCount) )
  {
    m_nAllocationCount = this->m_Memory.m_nAllocationCount;
    result = (m_nAllocationCount > 0) - 1;
  }
  else
  {
    result = index + 1;
    if ( result < 0 || result >= m_nAllocationCount )
      result = -1;
  }
  if ( result < 0 || result >= m_nAllocationCount )
  {
    CUtlMemory<ParticleControlPoint_t,int>::Grow((CUtlMemory<CSceneEventInfo,int> *)this, num: 1);
    this->m_pElements = this->m_Memory.m_pMemory;
    v7 = this->m_LastAlloc.index;
    if ( v7 < 0 || (v8 = this->m_Memory.m_nAllocationCount, v7 >= v8) )
    {
      v8 = this->m_Memory.m_nAllocationCount;
      result = (v8 > 0) - 1;
    }
    else
    {
      result = v7 + 1;
      if ( result < 0 || result >= v8 )
        result = -1;
    }
    if ( result < 0 || result >= v8 )
    {
      if ( `CUtlLinkedList<CClientLeafSystem::RenderableInfo_t,unsigned short,0,unsigned int,CUtlMemory<UtlLinkedListElem_t<CClientLeafSystem::RenderableInfo_t,unsigned short>,unsigned int>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<CClientLeafSystem::RenderableInfo_t,unsigned short,0,unsigned int,CUtlMemory<UtlLinkedListElem_t<CClientLeafSystem::RenderableInfo_t,unsigned short>,unsigned int>>::AllocInternal'::`12'::__executeCount;
        _Warning(a1: "CUtlLinkedList overflow! (exhausted memory allocator)\n");
      }
      return 0xFFFF;
    }
  }
  if ( (unsigned __int16)result == result && (_WORD)result != 0xFFFF )
  {
    ++this->m_NumAlloced;
    this->m_LastAlloc.index = result;
    goto LABEL_27;
  }
  if ( `CUtlLinkedList<CClientLeafSystem::RenderableInfo_t,unsigned short,0,unsigned int,CUtlMemory<UtlLinkedListElem_t<CClientLeafSystem::RenderableInfo_t,unsigned short>,unsigned int>>::AllocInternal'::`19'::__executeCount >= 10 )
    return 0xFFFF;
  ++`CUtlLinkedList<CClientLeafSystem::RenderableInfo_t,unsigned short,0,unsigned int,CUtlMemory<UtlLinkedListElem_t<CClientLeafSystem::RenderableInfo_t,unsigned short>,unsigned int>>::AllocInternal'::`19'::__executeCount;
  _Warning(a1: "CUtlLinkedList overflow! (exhausted index range)\n");
  return 0xFFFF;
}

//------------------------------------------------------------------------------
// Address: 0x100A81F0
// Name: protected: unsigned int CUtlLinkedList<struct CClientLeafSystem::ShadowInfo_t,unsigned short,0,unsigned int,class CUtlMemory<struct UtlLinkedListElem_t<struct CClientLeafSystem::ShadowInfo_t,unsigned short>,unsigned int>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
signed int __thiscall CUtlLinkedList<CClientLeafSystem::ShadowInfo_t,unsigned short,0,unsigned int,CUtlMemory<UtlLinkedListElem_t<CClientLeafSystem::ShadowInfo_t,unsigned short>,unsigned int>>::AllocInternal(
        CUtlLinkedList<CClientLeafSystem::ShadowInfo_t,unsigned short,0,unsigned int,CUtlMemory<UtlLinkedListElem_t<CClientLeafSystem::ShadowInfo_t,unsigned short>,unsigned int> > *this,
        bool multilist)
{
  unsigned int m_FirstFree; // ecx
  signed int index; // eax
  int m_nAllocationCount; // ecx
  signed int result; // eax
  signed int v7; // eax
  int v8; // ecx
  UtlLinkedListElem_t<CClientLeafSystem::ShadowInfo_t,unsigned short> *m_pMemory; // ecx
  unsigned int v10; // edx
  UtlLinkedListElem_t<CClientLeafSystem::ShadowInfo_t,unsigned short> *v11; // ecx

  m_FirstFree = this->m_FirstFree;
  if ( m_FirstFree != 0xFFFF )
  {
    result = m_FirstFree;
    this->m_FirstFree = this->m_Memory.m_pMemory[m_FirstFree].m_Next;
LABEL_27:
    m_pMemory = this->m_Memory.m_pMemory;
    if ( multilist )
    {
      v11 = &m_pMemory[result];
      v11->m_Next = -1;
      v11->m_Previous = -1;
    }
    else
    {
      v10 = result;
      m_pMemory[v10].m_Next = result;
      m_pMemory[v10].m_Previous = result;
    }
    return result;
  }
  index = this->m_LastAlloc.index;
  if ( index < 0 || (m_nAllocationCount = this->m_Memory.m_nAllocationCount, index >= m_nAllocationCount) )
  {
    m_nAllocationCount = this->m_Memory.m_nAllocationCount;
    result = (m_nAllocationCount > 0) - 1;
  }
  else
  {
    result = index + 1;
    if ( result < 0 || result >= m_nAllocationCount )
      result = -1;
  }
  if ( result < 0 || result >= m_nAllocationCount )
  {
    CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int>::Grow(
      (CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int> *)this,
      num: 1);
    this->m_pElements = this->m_Memory.m_pMemory;
    v7 = this->m_LastAlloc.index;
    if ( v7 < 0 || (v8 = this->m_Memory.m_nAllocationCount, v7 >= v8) )
    {
      v8 = this->m_Memory.m_nAllocationCount;
      result = (v8 > 0) - 1;
    }
    else
    {
      result = v7 + 1;
      if ( result < 0 || result >= v8 )
        result = -1;
    }
    if ( result < 0 || result >= v8 )
    {
      if ( `CUtlLinkedList<CClientLeafSystem::ShadowInfo_t,unsigned short,0,unsigned int,CUtlMemory<UtlLinkedListElem_t<CClientLeafSystem::ShadowInfo_t,unsigned short>,unsigned int>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<CClientLeafSystem::ShadowInfo_t,unsigned short,0,unsigned int,CUtlMemory<UtlLinkedListElem_t<CClientLeafSystem::ShadowInfo_t,unsigned short>,unsigned int>>::AllocInternal'::`12'::__executeCount;
        _Warning(a1: "CUtlLinkedList overflow! (exhausted memory allocator)\n");
      }
      return 0xFFFF;
    }
  }
  if ( (unsigned __int16)result == result && (_WORD)result != 0xFFFF )
  {
    ++this->m_NumAlloced;
    this->m_LastAlloc.index = result;
    goto LABEL_27;
  }
  if ( `CUtlLinkedList<CClientLeafSystem::ShadowInfo_t,unsigned short,0,unsigned int,CUtlMemory<UtlLinkedListElem_t<CClientLeafSystem::ShadowInfo_t,unsigned short>,unsigned int>>::AllocInternal'::`19'::__executeCount >= 10 )
    return 0xFFFF;
  ++`CUtlLinkedList<CClientLeafSystem::ShadowInfo_t,unsigned short,0,unsigned int,CUtlMemory<UtlLinkedListElem_t<CClientLeafSystem::ShadowInfo_t,unsigned short>,unsigned int>>::AllocInternal'::`19'::__executeCount;
  _Warning(a1: "CUtlLinkedList overflow! (exhausted index range)\n");
  return 0xFFFF;
}

//------------------------------------------------------------------------------
// Address: 0x100A8330
// Name: protected: unsigned int CUtlLinkedList<struct CBidirectionalSet<int,unsigned short,unsigned short,unsigned int>::BucketListInfo_t,unsigned short,1,unsigned int,class CUtlMemory<struct UtlLinkedListElem_t<struct CBidirectionalSet<int,unsigned short,unsigned short,unsigned int>::BucketListInfo_t,unsigned short>,unsigned int>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<CBidirectionalSet<int,unsigned short,unsigned short,unsigned int>::BucketListInfo_t,unsigned short,1,unsigned int,CUtlMemory<UtlLinkedListElem_t<CBidirectionalSet<int,unsigned short,unsigned short,unsigned int>::BucketListInfo_t,unsigned short>,unsigned int>>::AllocInternal(
        CUtlLinkedList<CBidirectionalSet<int,unsigned short,unsigned short,unsigned int>::BucketListInfo_t,unsigned short,1,unsigned int,CUtlMemory<UtlLinkedListElem_t<CBidirectionalSet<int,unsigned short,unsigned short,unsigned int>::BucketListInfo_t,unsigned short>,unsigned int> > *this,
        bool multilist)
{
  int result; // eax
  signed int index; // eax
  int m_nAllocationCount; // ecx
  signed int v6; // eax
  int v7; // ecx
  UtlLinkedListElem_t<CBidirectionalSet<int,unsigned short,unsigned short,unsigned int>::BucketListInfo_t,unsigned short> *v8; // ecx

  result = this->m_FirstFree;
  if ( result != 0xFFFF )
  {
    this->m_FirstFree = this->m_Memory.m_pMemory[result].m_Next;
LABEL_27:
    v8 = &this->m_Memory.m_pMemory[result];
    if ( multilist )
    {
      v8->m_Next = -1;
      v8->m_Previous = -1;
    }
    else
    {
      v8->m_Next = result;
      v8->m_Previous = result;
    }
    return result;
  }
  index = this->m_LastAlloc.index;
  if ( index < 0 || (m_nAllocationCount = this->m_Memory.m_nAllocationCount, index >= m_nAllocationCount) )
  {
    m_nAllocationCount = this->m_Memory.m_nAllocationCount;
    result = (m_nAllocationCount > 0) - 1;
  }
  else
  {
    result = index + 1;
    if ( result < 0 || result >= m_nAllocationCount )
      result = -1;
  }
  if ( result < 0 || result >= m_nAllocationCount )
  {
    CUtlMemory<CEntityDataInstantiator<StepSimulationData>::HashEntry,int>::Grow(
      (CUtlMemory<vgui::PropertySheet::Page_t,int> *)this,
      num: 1);
    this->m_pElements = this->m_Memory.m_pMemory;
    v6 = this->m_LastAlloc.index;
    if ( v6 < 0 || (v7 = this->m_Memory.m_nAllocationCount, v6 >= v7) )
    {
      v7 = this->m_Memory.m_nAllocationCount;
      result = (v7 > 0) - 1;
    }
    else
    {
      result = v6 + 1;
      if ( result < 0 || result >= v7 )
        result = -1;
    }
    if ( result < 0 || result >= v7 )
    {
      if ( `CUtlLinkedList<CBidirectionalSet<int,unsigned short,unsigned short,unsigned int>::BucketListInfo_t,unsigned short,1,unsigned int,CUtlMemory<UtlLinkedListElem_t<CBidirectionalSet<int,unsigned short,unsigned short,unsigned int>::BucketListInfo_t,unsigned short>,unsigned int>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<CBidirectionalSet<int,unsigned short,unsigned short,unsigned int>::BucketListInfo_t,unsigned short,1,unsigned int,CUtlMemory<UtlLinkedListElem_t<CBidirectionalSet<int,unsigned short,unsigned short,unsigned int>::BucketListInfo_t,unsigned short>,unsigned int>>::AllocInternal'::`12'::__executeCount;
        _Warning(a1: "CUtlLinkedList overflow! (exhausted memory allocator)\n");
      }
      return 0xFFFF;
    }
  }
  if ( (unsigned __int16)result == result && (_WORD)result != 0xFFFF )
  {
    ++this->m_NumAlloced;
    this->m_LastAlloc.index = result;
    goto LABEL_27;
  }
  if ( `CUtlLinkedList<CBidirectionalSet<int,unsigned short,unsigned short,unsigned int>::BucketListInfo_t,unsigned short,1,unsigned int,CUtlMemory<UtlLinkedListElem_t<CBidirectionalSet<int,unsigned short,unsigned short,unsigned int>::BucketListInfo_t,unsigned short>,unsigned int>>::AllocInternal'::`19'::__executeCount >= 10 )
    return 0xFFFF;
  ++`CUtlLinkedList<CBidirectionalSet<int,unsigned short,unsigned short,unsigned int>::BucketListInfo_t,unsigned short,1,unsigned int,CUtlMemory<UtlLinkedListElem_t<CBidirectionalSet<int,unsigned short,unsigned short,unsigned int>::BucketListInfo_t,unsigned short>,unsigned int>>::AllocInternal'::`19'::__executeCount;
  _Warning(a1: "CUtlLinkedList overflow! (exhausted index range)\n");
  return 0xFFFF;
}

//------------------------------------------------------------------------------
// Address: 0x100A8470
// Name: protected: unsigned int CUtlLinkedList<struct CBidirectionalSet<int,unsigned short,unsigned short,unsigned int>::ElementListInfo_t,unsigned short,1,unsigned int,class CUtlMemory<struct UtlLinkedListElem_t<struct CBidirectionalSet<int,unsigned short,unsigned short,unsigned int>::ElementListInfo_t,unsigned short>,unsigned int>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<CBidirectionalSet<int,unsigned short,unsigned short,unsigned int>::ElementListInfo_t,unsigned short,1,unsigned int,CUtlMemory<UtlLinkedListElem_t<CBidirectionalSet<int,unsigned short,unsigned short,unsigned int>::ElementListInfo_t,unsigned short>,unsigned int>>::AllocInternal(
        CUtlLinkedList<CBidirectionalSet<int,unsigned short,unsigned short,unsigned int>::ElementListInfo_t,unsigned short,1,unsigned int,CUtlMemory<UtlLinkedListElem_t<CBidirectionalSet<int,unsigned short,unsigned short,unsigned int>::ElementListInfo_t,unsigned short>,unsigned int> > *this,
        bool multilist)
{
  int result; // eax
  signed int index; // eax
  int m_nAllocationCount; // ecx
  signed int v6; // eax
  int v7; // ecx
  UtlLinkedListElem_t<CBidirectionalSet<int,unsigned short,unsigned short,unsigned int>::ElementListInfo_t,unsigned short> *v8; // ecx

  result = this->m_FirstFree;
  if ( result != 0xFFFF )
  {
    this->m_FirstFree = this->m_Memory.m_pMemory[result].m_Next;
LABEL_27:
    v8 = &this->m_Memory.m_pMemory[result];
    if ( multilist )
    {
      v8->m_Next = -1;
      v8->m_Previous = -1;
    }
    else
    {
      v8->m_Next = result;
      v8->m_Previous = result;
    }
    return result;
  }
  index = this->m_LastAlloc.index;
  if ( index < 0 || (m_nAllocationCount = this->m_Memory.m_nAllocationCount, index >= m_nAllocationCount) )
  {
    m_nAllocationCount = this->m_Memory.m_nAllocationCount;
    result = (m_nAllocationCount > 0) - 1;
  }
  else
  {
    result = index + 1;
    if ( result < 0 || result >= m_nAllocationCount )
      result = -1;
  }
  if ( result < 0 || result >= m_nAllocationCount )
  {
    CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int>::Grow(
      (CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int> *)this,
      num: 1);
    this->m_pElements = this->m_Memory.m_pMemory;
    v6 = this->m_LastAlloc.index;
    if ( v6 < 0 || (v7 = this->m_Memory.m_nAllocationCount, v6 >= v7) )
    {
      v7 = this->m_Memory.m_nAllocationCount;
      result = (v7 > 0) - 1;
    }
    else
    {
      result = v6 + 1;
      if ( result < 0 || result >= v7 )
        result = -1;
    }
    if ( result < 0 || result >= v7 )
    {
      if ( `CUtlLinkedList<CBidirectionalSet<int,unsigned short,unsigned short,unsigned int>::ElementListInfo_t,unsigned short,1,unsigned int,CUtlMemory<UtlLinkedListElem_t<CBidirectionalSet<int,unsigned short,unsigned short,unsigned int>::ElementListInfo_t,unsigned short>,unsigned int>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<CBidirectionalSet<int,unsigned short,unsigned short,unsigned int>::ElementListInfo_t,unsigned short,1,unsigned int,CUtlMemory<UtlLinkedListElem_t<CBidirectionalSet<int,unsigned short,unsigned short,unsigned int>::ElementListInfo_t,unsigned short>,unsigned int>>::AllocInternal'::`12'::__executeCount;
        _Warning(a1: "CUtlLinkedList overflow! (exhausted memory allocator)\n");
      }
      return 0xFFFF;
    }
  }
  if ( (unsigned __int16)result == result && (_WORD)result != 0xFFFF )
  {
    ++this->m_NumAlloced;
    this->m_LastAlloc.index = result;
    goto LABEL_27;
  }
  if ( `CUtlLinkedList<CBidirectionalSet<int,unsigned short,unsigned short,unsigned int>::ElementListInfo_t,unsigned short,1,unsigned int,CUtlMemory<UtlLinkedListElem_t<CBidirectionalSet<int,unsigned short,unsigned short,unsigned int>::ElementListInfo_t,unsigned short>,unsigned int>>::AllocInternal'::`19'::__executeCount >= 10 )
    return 0xFFFF;
  ++`CUtlLinkedList<CBidirectionalSet<int,unsigned short,unsigned short,unsigned int>::ElementListInfo_t,unsigned short,1,unsigned int,CUtlMemory<UtlLinkedListElem_t<CBidirectionalSet<int,unsigned short,unsigned short,unsigned int>::ElementListInfo_t,unsigned short>,unsigned int>>::AllocInternal'::`19'::__executeCount;
  _Warning(a1: "CUtlLinkedList overflow! (exhausted index range)\n");
  return 0xFFFF;
}

//------------------------------------------------------------------------------
// Address: 0x100A85B0
// Name: protected: unsigned int CUtlLinkedList<struct CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned int>::BucketListInfo_t,unsigned short,1,unsigned int,class CUtlMemory<struct UtlLinkedListElem_t<struct CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned int>::BucketListInfo_t,unsigned short>,unsigned int>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned int>::BucketListInfo_t,unsigned short,1,unsigned int,CUtlMemory<UtlLinkedListElem_t<CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned int>::BucketListInfo_t,unsigned short>,unsigned int>>::AllocInternal(
        CUtlLinkedList<CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned int>::BucketListInfo_t,unsigned short,1,unsigned int,CUtlMemory<UtlLinkedListElem_t<CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned int>::BucketListInfo_t,unsigned short>,unsigned int> > *this,
        bool multilist)
{
  int result; // eax
  signed int index; // eax
  int m_nAllocationCount; // ecx
  signed int v6; // eax
  int v7; // ecx
  UtlLinkedListElem_t<CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned int>::BucketListInfo_t,unsigned short> *v8; // ecx

  result = this->m_FirstFree;
  if ( result != 0xFFFF )
  {
    this->m_FirstFree = this->m_Memory.m_pMemory[result].m_Next;
LABEL_27:
    v8 = &this->m_Memory.m_pMemory[result];
    if ( multilist )
    {
      v8->m_Next = -1;
      v8->m_Previous = -1;
    }
    else
    {
      v8->m_Next = result;
      v8->m_Previous = result;
    }
    return result;
  }
  index = this->m_LastAlloc.index;
  if ( index < 0 || (m_nAllocationCount = this->m_Memory.m_nAllocationCount, index >= m_nAllocationCount) )
  {
    m_nAllocationCount = this->m_Memory.m_nAllocationCount;
    result = (m_nAllocationCount > 0) - 1;
  }
  else
  {
    result = index + 1;
    if ( result < 0 || result >= m_nAllocationCount )
      result = -1;
  }
  if ( result < 0 || result >= m_nAllocationCount )
  {
    CUtlMemory<CEntityDataInstantiator<StepSimulationData>::HashEntry,int>::Grow(
      (CUtlMemory<vgui::PropertySheet::Page_t,int> *)this,
      num: 1);
    this->m_pElements = this->m_Memory.m_pMemory;
    v6 = this->m_LastAlloc.index;
    if ( v6 < 0 || (v7 = this->m_Memory.m_nAllocationCount, v6 >= v7) )
    {
      v7 = this->m_Memory.m_nAllocationCount;
      result = (v7 > 0) - 1;
    }
    else
    {
      result = v6 + 1;
      if ( result < 0 || result >= v7 )
        result = -1;
    }
    if ( result < 0 || result >= v7 )
    {
      if ( `CUtlLinkedList<CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned int>::BucketListInfo_t,unsigned short,1,unsigned int,CUtlMemory<UtlLinkedListElem_t<CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned int>::BucketListInfo_t,unsigned short>,unsigned int>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned int>::BucketListInfo_t,unsigned short,1,unsigned int,CUtlMemory<UtlLinkedListElem_t<CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned int>::BucketListInfo_t,unsigned short>,unsigned int>>::AllocInternal'::`12'::__executeCount;
        _Warning(a1: "CUtlLinkedList overflow! (exhausted memory allocator)\n");
      }
      return 0xFFFF;
    }
  }
  if ( (unsigned __int16)result == result && (_WORD)result != 0xFFFF )
  {
    ++this->m_NumAlloced;
    this->m_LastAlloc.index = result;
    goto LABEL_27;
  }
  if ( `CUtlLinkedList<CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned int>::BucketListInfo_t,unsigned short,1,unsigned int,CUtlMemory<UtlLinkedListElem_t<CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned int>::BucketListInfo_t,unsigned short>,unsigned int>>::AllocInternal'::`19'::__executeCount >= 10 )
    return 0xFFFF;
  ++`CUtlLinkedList<CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned int>::BucketListInfo_t,unsigned short,1,unsigned int,CUtlMemory<UtlLinkedListElem_t<CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned int>::BucketListInfo_t,unsigned short>,unsigned int>>::AllocInternal'::`19'::__executeCount;
  _Warning(a1: "CUtlLinkedList overflow! (exhausted index range)\n");
  return 0xFFFF;
}

//------------------------------------------------------------------------------
// Address: 0x100A86F0
// Name: protected: unsigned int CUtlLinkedList<struct CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned int>::ElementListInfo_t,unsigned short,1,unsigned int,class CUtlMemory<struct UtlLinkedListElem_t<struct CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned int>::ElementListInfo_t,unsigned short>,unsigned int>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned int>::ElementListInfo_t,unsigned short,1,unsigned int,CUtlMemory<UtlLinkedListElem_t<CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned int>::ElementListInfo_t,unsigned short>,unsigned int>>::AllocInternal(
        CUtlLinkedList<CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned int>::ElementListInfo_t,unsigned short,1,unsigned int,CUtlMemory<UtlLinkedListElem_t<CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned int>::ElementListInfo_t,unsigned short>,unsigned int> > *this,
        bool multilist)
{
  int result; // eax
  signed int index; // eax
  int m_nAllocationCount; // ecx
  signed int v6; // eax
  int v7; // ecx
  UtlLinkedListElem_t<CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned int>::ElementListInfo_t,unsigned short> *v8; // ecx

  result = this->m_FirstFree;
  if ( result != 0xFFFF )
  {
    this->m_FirstFree = this->m_Memory.m_pMemory[result].m_Next;
LABEL_27:
    v8 = &this->m_Memory.m_pMemory[result];
    if ( multilist )
    {
      v8->m_Next = -1;
      v8->m_Previous = -1;
    }
    else
    {
      v8->m_Next = result;
      v8->m_Previous = result;
    }
    return result;
  }
  index = this->m_LastAlloc.index;
  if ( index < 0 || (m_nAllocationCount = this->m_Memory.m_nAllocationCount, index >= m_nAllocationCount) )
  {
    m_nAllocationCount = this->m_Memory.m_nAllocationCount;
    result = (m_nAllocationCount > 0) - 1;
  }
  else
  {
    result = index + 1;
    if ( result < 0 || result >= m_nAllocationCount )
      result = -1;
  }
  if ( result < 0 || result >= m_nAllocationCount )
  {
    CUtlMemory<CEntityDataInstantiator<StepSimulationData>::HashEntry,int>::Grow(
      (CUtlMemory<vgui::PropertySheet::Page_t,int> *)this,
      num: 1);
    this->m_pElements = this->m_Memory.m_pMemory;
    v6 = this->m_LastAlloc.index;
    if ( v6 < 0 || (v7 = this->m_Memory.m_nAllocationCount, v6 >= v7) )
    {
      v7 = this->m_Memory.m_nAllocationCount;
      result = (v7 > 0) - 1;
    }
    else
    {
      result = v6 + 1;
      if ( result < 0 || result >= v7 )
        result = -1;
    }
    if ( result < 0 || result >= v7 )
    {
      if ( `CUtlLinkedList<CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned int>::ElementListInfo_t,unsigned short,1,unsigned int,CUtlMemory<UtlLinkedListElem_t<CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned int>::ElementListInfo_t,unsigned short>,unsigned int>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned int>::ElementListInfo_t,unsigned short,1,unsigned int,CUtlMemory<UtlLinkedListElem_t<CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned int>::ElementListInfo_t,unsigned short>,unsigned int>>::AllocInternal'::`12'::__executeCount;
        _Warning(a1: "CUtlLinkedList overflow! (exhausted memory allocator)\n");
      }
      return 0xFFFF;
    }
  }
  if ( (unsigned __int16)result == result && (_WORD)result != 0xFFFF )
  {
    ++this->m_NumAlloced;
    this->m_LastAlloc.index = result;
    goto LABEL_27;
  }
  if ( `CUtlLinkedList<CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned int>::ElementListInfo_t,unsigned short,1,unsigned int,CUtlMemory<UtlLinkedListElem_t<CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned int>::ElementListInfo_t,unsigned short>,unsigned int>>::AllocInternal'::`19'::__executeCount >= 10 )
    return 0xFFFF;
  ++`CUtlLinkedList<CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned int>::ElementListInfo_t,unsigned short,1,unsigned int,CUtlMemory<UtlLinkedListElem_t<CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned int>::ElementListInfo_t,unsigned short>,unsigned int>>::AllocInternal'::`19'::__executeCount;
  _Warning(a1: "CUtlLinkedList overflow! (exhausted index range)\n");
  return 0xFFFF;
}

//------------------------------------------------------------------------------
// Address: 0x100A98A0
// Name: public: void CUtlLinkedList<struct CClientLeafSystem::ShadowInfo_t,unsigned short,0,unsigned int,class CUtlMemory<struct UtlLinkedListElem_t<struct CClientLeafSystem::ShadowInfo_t,unsigned short>,unsigned int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CClientLeafSystem::ShadowInfo_t,unsigned short,0,unsigned int,CUtlMemory<UtlLinkedListElem_t<CClientLeafSystem::ShadowInfo_t,unsigned short>,unsigned int>>::RemoveAll(
        CUtlLinkedList<CClientLeafSystem::ShadowInfo_t,unsigned short,0,unsigned int,CUtlMemory<UtlLinkedListElem_t<CClientLeafSystem::ShadowInfo_t,unsigned short>,unsigned int> > *this)
{
  unsigned int m_Head; // edx
  UtlLinkedListElem_t<CClientLeafSystem::ShadowInfo_t,unsigned short> *v2; // esi
  unsigned int m_Next; // eax
  unsigned int m_FirstFree; // edx
  unsigned int v5; // eax

  if ( this->m_LastAlloc.index != -1 )
  {
    m_Head = this->m_Head;
    if ( m_Head != 0xFFFF )
    {
      do
      {
        v2 = &this->m_Memory.m_pMemory[m_Head];
        m_Next = v2->m_Next;
        v2->m_Previous = m_Head;
        if ( m_Next == 0xFFFF )
          m_FirstFree = this->m_FirstFree;
        else
          LOWORD(m_FirstFree) = m_Next;
        v2->m_Next = m_FirstFree;
        m_Head = m_Next;
      }
      while ( m_Next != 0xFFFF );
    }
    v5 = this->m_Head;
    if ( v5 != 0xFFFF )
      this->m_FirstFree = v5;
    this->m_Head = 0xFFFF;
    this->m_Tail = 0xFFFF;
    this->m_ElementCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A9910
// Name: public: void CUtlLinkedList<struct CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned int>::ElementListInfo_t,unsigned short,1,unsigned int,class CUtlMemory<struct UtlLinkedListElem_t<struct CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned int>::ElementListInfo_t,unsigned short>,unsigned int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned int>::ElementListInfo_t,unsigned short,1,unsigned int,CUtlMemory<UtlLinkedListElem_t<CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned int>::ElementListInfo_t,unsigned short>,unsigned int>>::RemoveAll(
        CUtlLinkedList<CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned int>::ElementListInfo_t,unsigned short,1,unsigned int,CUtlMemory<UtlLinkedListElem_t<CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned int>::ElementListInfo_t,unsigned short>,unsigned int> > *this)
{
  unsigned int index; // edx
  signed int v2; // eax
  UtlLinkedListElem_t<CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned int>::ElementListInfo_t,unsigned short> *v3; // edx

  index = this->m_LastAlloc.index;
  if ( index != -1 )
  {
    v2 = (this->m_Memory.m_nAllocationCount > 0) - 1;
    if ( this->m_Memory.m_nAllocationCount > 0 )
    {
      do
      {
        if ( v2 >= 0 && v2 < this->m_Memory.m_nAllocationCount && v2 <= index )
        {
          v3 = &this->m_Memory.m_pMemory[v2];
          if ( v3->m_Previous != v2 || v3->m_Next == v2 )
          {
            v3->m_Previous = v2;
            v3->m_Next = this->m_FirstFree;
            this->m_FirstFree = v2;
          }
        }
        index = this->m_LastAlloc.index;
        if ( v2 == index )
          break;
        if ( ++v2 < 0 || v2 >= this->m_Memory.m_nAllocationCount )
          v2 = -1;
      }
      while ( v2 != -1 );
    }
    this->m_Head = 0xFFFF;
    this->m_Tail = 0xFFFF;
    this->m_ElementCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A9990
// Name: public: void CUtlLinkedList<struct CBidirectionalSet<int,unsigned short,unsigned short,unsigned int>::ElementListInfo_t,unsigned short,1,unsigned int,class CUtlMemory<struct UtlLinkedListElem_t<struct CBidirectionalSet<int,unsigned short,unsigned short,unsigned int>::ElementListInfo_t,unsigned short>,unsigned int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CBidirectionalSet<int,unsigned short,unsigned short,unsigned int>::ElementListInfo_t,unsigned short,1,unsigned int,CUtlMemory<UtlLinkedListElem_t<CBidirectionalSet<int,unsigned short,unsigned short,unsigned int>::ElementListInfo_t,unsigned short>,unsigned int>>::RemoveAll(
        CUtlLinkedList<CBidirectionalSet<int,unsigned short,unsigned short,unsigned int>::ElementListInfo_t,unsigned short,1,unsigned int,CUtlMemory<UtlLinkedListElem_t<CBidirectionalSet<int,unsigned short,unsigned short,unsigned int>::ElementListInfo_t,unsigned short>,unsigned int> > *this)
{
  unsigned int index; // edx
  signed int v2; // eax
  UtlLinkedListElem_t<CBidirectionalSet<int,unsigned short,unsigned short,unsigned int>::ElementListInfo_t,unsigned short> *v3; // edx

  index = this->m_LastAlloc.index;
  if ( index != -1 )
  {
    v2 = (this->m_Memory.m_nAllocationCount > 0) - 1;
    if ( this->m_Memory.m_nAllocationCount > 0 )
    {
      do
      {
        if ( v2 >= 0 && v2 < this->m_Memory.m_nAllocationCount && v2 <= index )
        {
          v3 = &this->m_Memory.m_pMemory[v2];
          if ( v3->m_Previous != v2 || v3->m_Next == v2 )
          {
            v3->m_Previous = v2;
            v3->m_Next = this->m_FirstFree;
            this->m_FirstFree = v2;
          }
        }
        index = this->m_LastAlloc.index;
        if ( v2 == index )
          break;
        if ( ++v2 < 0 || v2 >= this->m_Memory.m_nAllocationCount )
          v2 = -1;
      }
      while ( v2 != -1 );
    }
    this->m_Head = 0xFFFF;
    this->m_Tail = 0xFFFF;
    this->m_ElementCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A9A10
// Name: public: void CUtlLinkedList<struct CClientLeafSystem::RenderableInfo_t,unsigned short,0,unsigned int,class CUtlMemory<struct UtlLinkedListElem_t<struct CClientLeafSystem::RenderableInfo_t,unsigned short>,unsigned int>>::Unlink(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CClientLeafSystem::RenderableInfo_t,unsigned short,0,unsigned int,CUtlMemory<UtlLinkedListElem_t<CClientLeafSystem::RenderableInfo_t,unsigned short>,unsigned int>>::Unlink(
        CUtlLinkedList<CClientLeafSystem::RenderableInfo_t,unsigned short,0,unsigned int,CUtlMemory<UtlLinkedListElem_t<CClientLeafSystem::RenderableInfo_t,unsigned short>,unsigned int> > *this,
        int elem)
{
  UtlLinkedListElem_t<CClientLeafSystem::RenderableInfo_t,unsigned short> *v2; // eax
  int m_Previous; // ebx
  unsigned int m_Next; // edx
  unsigned int v5; // edx

  if ( elem >= 0 && elem < this->m_Memory.m_nAllocationCount && elem <= this->m_LastAlloc.index )
  {
    v2 = &this->m_Memory.m_pMemory[elem];
    if ( v2->m_Previous != elem )
    {
      m_Previous = v2->m_Previous;
      m_Next = v2->m_Next;
      if ( (_WORD)m_Previous == 0xFFFF )
        this->m_Head = m_Next;
      else
        this->m_Memory.m_pMemory[m_Previous].m_Next = m_Next;
      if ( (_WORD)m_Next == 0xFFFF )
      {
        v5 = v2->m_Previous;
        --this->m_ElementCount;
        this->m_Tail = v5;
      }
      else
      {
        this->m_Memory.m_pMemory[(unsigned __int16)m_Next].m_Previous = v2->m_Previous;
        --this->m_ElementCount;
      }
      v2->m_Next = elem;
      v2->m_Previous = elem;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A9AB0
// Name: public: void CUtlLinkedList<struct CClientLeafSystem::ShadowInfo_t,unsigned short,0,unsigned int,class CUtlMemory<struct UtlLinkedListElem_t<struct CClientLeafSystem::ShadowInfo_t,unsigned short>,unsigned int>>::Unlink(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CClientLeafSystem::ShadowInfo_t,unsigned short,0,unsigned int,CUtlMemory<UtlLinkedListElem_t<CClientLeafSystem::ShadowInfo_t,unsigned short>,unsigned int>>::Unlink(
        CUtlLinkedList<CClientLeafSystem::ShadowInfo_t,unsigned short,0,unsigned int,CUtlMemory<UtlLinkedListElem_t<CClientLeafSystem::ShadowInfo_t,unsigned short>,unsigned int> > *this,
        int elem)
{
  UtlLinkedListElem_t<CClientLeafSystem::ShadowInfo_t,unsigned short> *v2; // eax
  int m_Previous; // ebx
  unsigned int m_Next; // edx
  unsigned int v5; // edx

  if ( elem >= 0 && elem < this->m_Memory.m_nAllocationCount && elem <= this->m_LastAlloc.index )
  {
    v2 = &this->m_Memory.m_pMemory[elem];
    if ( v2->m_Previous != elem )
    {
      m_Previous = v2->m_Previous;
      m_Next = v2->m_Next;
      if ( (_WORD)m_Previous == 0xFFFF )
        this->m_Head = m_Next;
      else
        this->m_Memory.m_pMemory[m_Previous].m_Next = m_Next;
      if ( (_WORD)m_Next == 0xFFFF )
      {
        v5 = v2->m_Previous;
        --this->m_ElementCount;
        this->m_Tail = v5;
      }
      else
      {
        this->m_Memory.m_pMemory[(unsigned __int16)m_Next].m_Previous = v2->m_Previous;
        --this->m_ElementCount;
      }
      v2->m_Next = elem;
      v2->m_Previous = elem;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A9B50
// Name: public: void CUtlLinkedList<struct CBidirectionalSet<int,unsigned short,unsigned short,unsigned int>::ElementListInfo_t,unsigned short,1,unsigned int,class CUtlMemory<struct UtlLinkedListElem_t<struct CBidirectionalSet<int,unsigned short,unsigned short,unsigned int>::ElementListInfo_t,unsigned short>,unsigned int>>::Unlink(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CBidirectionalSet<int,unsigned short,unsigned short,unsigned int>::ElementListInfo_t,unsigned short,1,unsigned int,CUtlMemory<UtlLinkedListElem_t<CBidirectionalSet<int,unsigned short,unsigned short,unsigned int>::ElementListInfo_t,unsigned short>,unsigned int>>::Unlink(
        CUtlLinkedList<CBidirectionalSet<int,unsigned short,unsigned short,unsigned int>::ElementListInfo_t,unsigned short,1,unsigned int,CUtlMemory<UtlLinkedListElem_t<CBidirectionalSet<int,unsigned short,unsigned short,unsigned int>::ElementListInfo_t,unsigned short>,unsigned int> > *this,
        int elem)
{
  UtlLinkedListElem_t<CBidirectionalSet<int,unsigned short,unsigned short,unsigned int>::ElementListInfo_t,unsigned short> *v2; // eax
  int m_Previous; // ebx
  unsigned int m_Next; // edx
  unsigned int v5; // edx

  if ( elem >= 0 && elem < this->m_Memory.m_nAllocationCount && elem <= this->m_LastAlloc.index )
  {
    v2 = &this->m_Memory.m_pMemory[elem];
    if ( v2->m_Previous != elem )
    {
      m_Previous = v2->m_Previous;
      m_Next = v2->m_Next;
      if ( (_WORD)m_Previous == 0xFFFF )
        this->m_Head = m_Next;
      else
        this->m_Memory.m_pMemory[m_Previous].m_Next = m_Next;
      if ( (_WORD)m_Next == 0xFFFF )
      {
        v5 = v2->m_Previous;
        --this->m_ElementCount;
        this->m_Tail = v5;
      }
      else
      {
        this->m_Memory.m_pMemory[(unsigned __int16)m_Next].m_Previous = v2->m_Previous;
        --this->m_ElementCount;
      }
      v2->m_Next = elem;
      v2->m_Previous = elem;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A9BF0
// Name: public: void CUtlLinkedList<struct CBidirectionalSet<int,unsigned short,unsigned short,unsigned int>::BucketListInfo_t,unsigned short,1,unsigned int,class CUtlMemory<struct UtlLinkedListElem_t<struct CBidirectionalSet<int,unsigned short,unsigned short,unsigned int>::BucketListInfo_t,unsigned short>,unsigned int>>::Unlink(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CBidirectionalSet<int,unsigned short,unsigned short,unsigned int>::BucketListInfo_t,unsigned short,1,unsigned int,CUtlMemory<UtlLinkedListElem_t<CBidirectionalSet<int,unsigned short,unsigned short,unsigned int>::BucketListInfo_t,unsigned short>,unsigned int>>::Unlink(
        CUtlLinkedList<CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned int>::ElementListInfo_t,unsigned short,1,unsigned int,CUtlMemory<UtlLinkedListElem_t<CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned int>::ElementListInfo_t,unsigned short>,unsigned int> > *this,
        int elem)
{
  UtlLinkedListElem_t<CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned int>::ElementListInfo_t,unsigned short> *m_pMemory; // edx
  unsigned __int16 *p_m_Previous; // ebx
  unsigned int m_Next; // esi
  unsigned __int16 *p_m_Next; // ecx
  unsigned int v7; // edx

  if ( elem >= 0 && elem < this->m_Memory.m_nAllocationCount && elem <= this->m_LastAlloc.index )
  {
    m_pMemory = this->m_Memory.m_pMemory;
    if ( this->m_Memory.m_pMemory[elem].m_Previous != elem )
    {
      p_m_Previous = &m_pMemory[elem].m_Previous;
      m_Next = m_pMemory[elem].m_Next;
      p_m_Next = &m_pMemory[elem].m_Next;
      if ( *p_m_Previous == 0xFFFF )
        this->m_Head = m_Next;
      else
        m_pMemory[*p_m_Previous].m_Next = m_Next;
      v7 = *p_m_Previous;
      if ( (_WORD)m_Next == 0xFFFF )
      {
        --this->m_ElementCount;
        *p_m_Previous = elem;
        this->m_Tail = v7;
      }
      else
      {
        this->m_Memory.m_pMemory[(unsigned __int16)m_Next].m_Previous = v7;
        --this->m_ElementCount;
        *p_m_Previous = elem;
      }
      *p_m_Next = elem;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A9FF0
// Name: public: void CUtlLinkedList<struct CBidirectionalSet<int,unsigned short,unsigned short,unsigned int>::ElementListInfo_t,unsigned short,1,unsigned int,class CUtlMemory<struct UtlLinkedListElem_t<struct CBidirectionalSet<int,unsigned short,unsigned short,unsigned int>::ElementListInfo_t,unsigned short>,unsigned int>>::LinkBefore(unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CBidirectionalSet<int,unsigned short,unsigned short,unsigned int>::ElementListInfo_t,unsigned short,1,unsigned int,CUtlMemory<UtlLinkedListElem_t<CBidirectionalSet<int,unsigned short,unsigned short,unsigned int>::ElementListInfo_t,unsigned short>,unsigned int>>::LinkBefore(
        CUtlLinkedList<CBidirectionalSet<int,unsigned short,unsigned short,unsigned int>::ElementListInfo_t,unsigned short,1,unsigned int,CUtlMemory<UtlLinkedListElem_t<CBidirectionalSet<int,unsigned short,unsigned short,unsigned int>::ElementListInfo_t,unsigned short>,unsigned int> > *this,
        unsigned int before,
        unsigned int elem)
{
  UtlLinkedListElem_t<CBidirectionalSet<int,unsigned short,unsigned short,unsigned int>::ElementListInfo_t,unsigned short> *m_pMemory; // edx
  UtlLinkedListElem_t<CBidirectionalSet<int,unsigned short,unsigned short,unsigned int>::ElementListInfo_t,unsigned short> *v5; // ecx
  unsigned __int16 m_Tail; // ax
  UtlLinkedListElem_t<CBidirectionalSet<int,unsigned short,unsigned short,unsigned int>::ElementListInfo_t,unsigned short> *v7; // ebx

  CUtlLinkedList<CBidirectionalSet<int,unsigned short,unsigned short,unsigned int>::ElementListInfo_t,unsigned short,1,unsigned int,CUtlMemory<UtlLinkedListElem_t<CBidirectionalSet<int,unsigned short,unsigned short,unsigned int>::ElementListInfo_t,unsigned short>,unsigned int>>::Unlink(
    this,
    elem);
  m_pMemory = this->m_Memory.m_pMemory;
  v5 = &this->m_Memory.m_pMemory[elem];
  v5->m_Next = before;
  if ( before == 0xFFFF )
  {
    m_Tail = this->m_Tail;
    v5->m_Previous = m_Tail;
    this->m_Tail = elem;
  }
  else
  {
    v7 = &m_pMemory[before];
    m_Tail = v7->m_Previous;
    v5->m_Previous = m_Tail;
    v7->m_Previous = elem;
  }
  if ( m_Tail == 0xFFFF )
  {
    ++this->m_ElementCount;
    this->m_Head = elem;
  }
  else
  {
    m_pMemory[m_Tail].m_Next = elem;
    ++this->m_ElementCount;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100AA070
// Name: public: void CUtlLinkedList<struct CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned int>::ElementListInfo_t,unsigned short,1,unsigned int,class CUtlMemory<struct UtlLinkedListElem_t<struct CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned int>::ElementListInfo_t,unsigned short>,unsigned int>>::LinkBefore(unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned int>::ElementListInfo_t,unsigned short,1,unsigned int,CUtlMemory<UtlLinkedListElem_t<CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned int>::ElementListInfo_t,unsigned short>,unsigned int>>::LinkBefore(
        CUtlLinkedList<CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned int>::ElementListInfo_t,unsigned short,1,unsigned int,CUtlMemory<UtlLinkedListElem_t<CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned int>::ElementListInfo_t,unsigned short>,unsigned int> > *this,
        unsigned int before,
        unsigned int elem)
{
  UtlLinkedListElem_t<CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned int>::ElementListInfo_t,unsigned short> *m_pMemory; // eax
  unsigned __int16 m_Tail; // cx
  unsigned __int16 *p_m_Previous; // edx

  CUtlLinkedList<CBidirectionalSet<int,unsigned short,unsigned short,unsigned int>::BucketListInfo_t,unsigned short,1,unsigned int,CUtlMemory<UtlLinkedListElem_t<CBidirectionalSet<int,unsigned short,unsigned short,unsigned int>::BucketListInfo_t,unsigned short>,unsigned int>>::Unlink(
    this,
    elem);
  m_pMemory = this->m_Memory.m_pMemory;
  this->m_Memory.m_pMemory[elem].m_Next = before;
  if ( before == 0xFFFF )
  {
    m_Tail = this->m_Tail;
    m_pMemory[elem].m_Previous = m_Tail;
    this->m_Tail = elem;
  }
  else
  {
    p_m_Previous = &m_pMemory[before].m_Previous;
    m_Tail = *p_m_Previous;
    m_pMemory[elem].m_Previous = *p_m_Previous;
    *p_m_Previous = elem;
  }
  if ( m_Tail == 0xFFFF )
  {
    ++this->m_ElementCount;
    this->m_Head = elem;
  }
  else
  {
    m_pMemory[m_Tail].m_Next = elem;
    ++this->m_ElementCount;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100AA1F0
// Name: public: void CUtlLinkedList<struct CClientLeafSystem::RenderableInfo_t,unsigned short,0,unsigned int,class CUtlMemory<struct UtlLinkedListElem_t<struct CClientLeafSystem::RenderableInfo_t,unsigned short>,unsigned int>>::LinkBefore(unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CClientLeafSystem::RenderableInfo_t,unsigned short,0,unsigned int,CUtlMemory<UtlLinkedListElem_t<CClientLeafSystem::RenderableInfo_t,unsigned short>,unsigned int>>::LinkBefore(
        CUtlLinkedList<CClientLeafSystem::RenderableInfo_t,unsigned short,0,unsigned int,CUtlMemory<UtlLinkedListElem_t<CClientLeafSystem::RenderableInfo_t,unsigned short>,unsigned int> > *this,
        unsigned int before,
        unsigned int elem)
{
  UtlLinkedListElem_t<CClientLeafSystem::RenderableInfo_t,unsigned short> *m_pMemory; // ebx
  unsigned int v5; // eax
  unsigned __int16 m_Tail; // dx

  CUtlLinkedList<CClientLeafSystem::RenderableInfo_t,unsigned short,0,unsigned int,CUtlMemory<UtlLinkedListElem_t<CClientLeafSystem::RenderableInfo_t,unsigned short>,unsigned int>>::Unlink(
    this,
    elem);
  m_pMemory = this->m_Memory.m_pMemory;
  v5 = elem;
  this->m_Memory.m_pMemory[elem].m_Next = before;
  if ( before == 0xFFFF )
  {
    m_Tail = this->m_Tail;
    m_pMemory[v5].m_Previous = m_Tail;
    this->m_Tail = elem;
  }
  else
  {
    m_Tail = m_pMemory[before].m_Previous;
    m_pMemory[v5].m_Previous = m_Tail;
    m_pMemory[before].m_Previous = elem;
  }
  if ( m_Tail == 0xFFFF )
  {
    ++this->m_ElementCount;
    this->m_Head = elem;
  }
  else
  {
    m_pMemory[m_Tail].m_Next = elem;
    ++this->m_ElementCount;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100AA270
// Name: public: void CUtlLinkedList<struct CClientLeafSystem::ShadowInfo_t,unsigned short,0,unsigned int,class CUtlMemory<struct UtlLinkedListElem_t<struct CClientLeafSystem::ShadowInfo_t,unsigned short>,unsigned int>>::LinkBefore(unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CClientLeafSystem::ShadowInfo_t,unsigned short,0,unsigned int,CUtlMemory<UtlLinkedListElem_t<CClientLeafSystem::ShadowInfo_t,unsigned short>,unsigned int>>::LinkBefore(
        CUtlLinkedList<CClientLeafSystem::ShadowInfo_t,unsigned short,0,unsigned int,CUtlMemory<UtlLinkedListElem_t<CClientLeafSystem::ShadowInfo_t,unsigned short>,unsigned int> > *this,
        unsigned int before,
        unsigned int elem)
{
  UtlLinkedListElem_t<CClientLeafSystem::ShadowInfo_t,unsigned short> *m_pMemory; // ebx
  unsigned __int16 m_Tail; // dx

  CUtlLinkedList<CClientLeafSystem::ShadowInfo_t,unsigned short,0,unsigned int,CUtlMemory<UtlLinkedListElem_t<CClientLeafSystem::ShadowInfo_t,unsigned short>,unsigned int>>::Unlink(
    this,
    elem);
  m_pMemory = this->m_Memory.m_pMemory;
  this->m_Memory.m_pMemory[elem].m_Next = before;
  if ( before == 0xFFFF )
  {
    m_Tail = this->m_Tail;
    m_pMemory[elem].m_Previous = m_Tail;
    this->m_Tail = elem;
  }
  else
  {
    m_Tail = m_pMemory[before].m_Previous;
    m_pMemory[elem].m_Previous = m_Tail;
    m_pMemory[before].m_Previous = elem;
  }
  if ( m_Tail == 0xFFFF )
  {
    ++this->m_ElementCount;
    this->m_Head = elem;
  }
  else
  {
    m_pMemory[m_Tail].m_Next = elem;
    ++this->m_ElementCount;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B50F0
// Name: protected: unsigned short CUtlLinkedList<struct CTextureAllocator::TextureInfo_t,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<struct CTextureAllocator::TextureInfo_t,unsigned short>,unsigned short>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<CTextureAllocator::TextureInfo_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CTextureAllocator::TextureInfo_t,unsigned short>,unsigned short>>::AllocInternal(
        CUtlLinkedList<CTextureAllocator::TextureInfo_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CTextureAllocator::TextureInfo_t,unsigned short>,unsigned short> > *this,
        bool multilist)
{
  int m_FirstFree; // ecx
  int m_nAllocationCount; // ecx
  unsigned __int16 index; // ax
  int result; // eax
  int v7; // ecx
  unsigned __int16 v8; // ax
  UtlLinkedListElem_t<CTextureAllocator::TextureInfo_t,unsigned short> *v9; // ecx

  m_FirstFree = this->m_FirstFree;
  if ( (_WORD)m_FirstFree != 0xFFFF )
  {
    result = m_FirstFree;
    this->m_FirstFree = this->m_Memory.m_pMemory[m_FirstFree].m_Next;
LABEL_22:
    v9 = &this->m_Memory.m_pMemory[(unsigned __int16)result];
    if ( multilist )
    {
      v9->m_Next = -1;
      v9->m_Previous = -1;
    }
    else
    {
      v9->m_Next = result;
      v9->m_Previous = result;
    }
    return result;
  }
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( this->m_LastAlloc.index >= m_nAllocationCount )
  {
    m_nAllocationCount = this->m_Memory.m_nAllocationCount;
    LOWORD(result) = (m_nAllocationCount > 0) - 1;
  }
  else
  {
    index = this->m_LastAlloc.index;
    if ( (unsigned __int16)(index + 1) >= m_nAllocationCount )
      LOWORD(result) = -1;
    else
      LOWORD(result) = index + 1;
  }
  if ( (unsigned __int16)result >= m_nAllocationCount )
  {
    CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CPixelVisibilityQuery,unsigned short>::List_t,unsigned short>,unsigned short>::Grow(
      (CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short> *)this,
      num: 1);
    this->m_pElements = this->m_Memory.m_pMemory;
    v7 = this->m_Memory.m_nAllocationCount;
    if ( this->m_LastAlloc.index >= v7 )
    {
      v7 = this->m_Memory.m_nAllocationCount;
      LOWORD(result) = (v7 > 0) - 1;
    }
    else
    {
      v8 = this->m_LastAlloc.index;
      LOWORD(result) = (unsigned __int16)(v8 + 1) >= v7 ? -1 : v8 + 1;
    }
    if ( (unsigned __int16)result >= v7 )
    {
      if ( `CUtlLinkedList<CTextureAllocator::TextureInfo_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CTextureAllocator::TextureInfo_t,unsigned short>,unsigned short>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<CTextureAllocator::TextureInfo_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CTextureAllocator::TextureInfo_t,unsigned short>,unsigned short>>::AllocInternal'::`12'::__executeCount;
        _Warning(a1: "CUtlLinkedList overflow! (exhausted memory allocator)\n");
      }
      return 0xFFFF;
    }
  }
  if ( (_WORD)result != 0xFFFF )
  {
    ++this->m_NumAlloced;
    this->m_LastAlloc.index = result;
    result = (unsigned __int16)result;
    goto LABEL_22;
  }
  if ( `CUtlLinkedList<CTextureAllocator::TextureInfo_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CTextureAllocator::TextureInfo_t,unsigned short>,unsigned short>>::AllocInternal'::`19'::__executeCount >= 10 )
    return 0xFFFF;
  ++`CUtlLinkedList<CTextureAllocator::TextureInfo_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CTextureAllocator::TextureInfo_t,unsigned short>,unsigned short>>::AllocInternal'::`19'::__executeCount;
  _Warning(a1: "CUtlLinkedList overflow! (exhausted index range)\n");
  return 0xFFFF;
}

//------------------------------------------------------------------------------
// Address: 0x100B5270
// Name: public: void CUtlLinkedList<struct CUtlMultiList<class CPixelVisSet,unsigned short>::List_t,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<struct CUtlMultiList<class CPixelVisSet,unsigned short>::List_t,unsigned short>,unsigned short>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CUtlMultiList<CPixelVisSet,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CPixelVisSet,unsigned short>::List_t,unsigned short>,unsigned short>>::RemoveAll(
        CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short> > *this)
{
  unsigned __int16 m_Head; // si
  UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short> *v2; // edx
  unsigned __int16 m_Next; // ax
  unsigned __int16 m_FirstFree; // si
  unsigned __int16 v5; // ax

  if ( this->m_LastAlloc.index != 0xFFFF )
  {
    m_Head = this->m_Head;
    if ( m_Head != 0xFFFF )
    {
      do
      {
        v2 = &this->m_Memory.m_pMemory[m_Head];
        m_Next = v2->m_Next;
        v2->m_Previous = m_Head;
        if ( m_Next == 0xFFFF )
          m_FirstFree = this->m_FirstFree;
        else
          m_FirstFree = m_Next;
        v2->m_Next = m_FirstFree;
        m_Head = m_Next;
      }
      while ( m_Next != 0xFFFF );
    }
    v5 = this->m_Head;
    if ( v5 != 0xFFFF )
      this->m_FirstFree = v5;
    *(_DWORD *)&this->m_Head = -1;
    this->m_ElementCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B52E0
// Name: protected: unsigned short CUtlLinkedList<struct CClientShadowMgr::ClientShadow_t,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<struct CClientShadowMgr::ClientShadow_t,unsigned short>,unsigned short>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<CClientShadowMgr::ClientShadow_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CClientShadowMgr::ClientShadow_t,unsigned short>,unsigned short>>::AllocInternal(
        CUtlLinkedList<CClientShadowMgr::ClientShadow_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CClientShadowMgr::ClientShadow_t,unsigned short>,unsigned short> > *this,
        bool multilist)
{
  int m_FirstFree; // ecx
  int m_nAllocationCount; // ecx
  unsigned __int16 index; // ax
  int result; // eax
  int v7; // ecx
  unsigned __int16 v8; // ax
  unsigned int v9; // ecx
  UtlLinkedListElem_t<CClientShadowMgr::ClientShadow_t,unsigned short> *m_pMemory; // edx
  UtlLinkedListElem_t<CClientShadowMgr::ClientShadow_t,unsigned short> *v11; // ecx

  m_FirstFree = this->m_FirstFree;
  if ( (_WORD)m_FirstFree != 0xFFFF )
  {
    result = m_FirstFree;
    this->m_FirstFree = this->m_Memory.m_pMemory[m_FirstFree].m_Next;
LABEL_22:
    v9 = (unsigned __int16)result;
    if ( multilist )
    {
      v11 = &this->m_Memory.m_pMemory[v9];
      v11->m_Next = -1;
      v11->m_Previous = -1;
    }
    else
    {
      m_pMemory = this->m_Memory.m_pMemory;
      m_pMemory[v9].m_Next = result;
      m_pMemory[v9].m_Previous = result;
    }
    return result;
  }
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( this->m_LastAlloc.index >= m_nAllocationCount )
  {
    m_nAllocationCount = this->m_Memory.m_nAllocationCount;
    LOWORD(result) = (m_nAllocationCount > 0) - 1;
  }
  else
  {
    index = this->m_LastAlloc.index;
    if ( (unsigned __int16)(index + 1) >= m_nAllocationCount )
      LOWORD(result) = -1;
    else
      LOWORD(result) = index + 1;
  }
  if ( (unsigned __int16)result >= m_nAllocationCount )
  {
    CUtlMemory<UtlLinkedListElem_t<CClientShadowMgr::ClientShadow_t,unsigned short>,unsigned short>::Grow(
      this: &this->m_Memory,
      num: 1);
    this->m_pElements = this->m_Memory.m_pMemory;
    v7 = this->m_Memory.m_nAllocationCount;
    if ( this->m_LastAlloc.index >= v7 )
    {
      v7 = this->m_Memory.m_nAllocationCount;
      LOWORD(result) = (v7 > 0) - 1;
    }
    else
    {
      v8 = this->m_LastAlloc.index;
      LOWORD(result) = (unsigned __int16)(v8 + 1) >= v7 ? -1 : v8 + 1;
    }
    if ( (unsigned __int16)result >= v7 )
    {
      if ( `CUtlLinkedList<CClientShadowMgr::ClientShadow_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CClientShadowMgr::ClientShadow_t,unsigned short>,unsigned short>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<CClientShadowMgr::ClientShadow_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CClientShadowMgr::ClientShadow_t,unsigned short>,unsigned short>>::AllocInternal'::`12'::__executeCount;
        _Warning(a1: "CUtlLinkedList overflow! (exhausted memory allocator)\n");
      }
      return 0xFFFF;
    }
  }
  if ( (_WORD)result != 0xFFFF )
  {
    ++this->m_NumAlloced;
    this->m_LastAlloc.index = result;
    result = (unsigned __int16)result;
    goto LABEL_22;
  }
  if ( `CUtlLinkedList<CClientShadowMgr::ClientShadow_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CClientShadowMgr::ClientShadow_t,unsigned short>,unsigned short>>::AllocInternal'::`19'::__executeCount >= 10 )
    return 0xFFFF;
  ++`CUtlLinkedList<CClientShadowMgr::ClientShadow_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CClientShadowMgr::ClientShadow_t,unsigned short>,unsigned short>>::AllocInternal'::`19'::__executeCount;
  _Warning(a1: "CUtlLinkedList overflow! (exhausted index range)\n");
  return 0xFFFF;
}

//------------------------------------------------------------------------------
// Address: 0x100B5570
// Name: protected: unsigned short CUtlLinkedList<struct CUtlMultiList<struct CTextureAllocator::FragmentInfo_t,unsigned short>::List_t,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<struct CUtlMultiList<struct CTextureAllocator::FragmentInfo_t,unsigned short>::List_t,unsigned short>,unsigned short>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<CUtlMultiList<CTextureAllocator::FragmentInfo_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CTextureAllocator::FragmentInfo_t,unsigned short>::List_t,unsigned short>,unsigned short>>::AllocInternal(
        CUtlLinkedList<CUtlMultiList<CTextureAllocator::FragmentInfo_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CTextureAllocator::FragmentInfo_t,unsigned short>::List_t,unsigned short>,unsigned short> > *this,
        bool multilist)
{
  int m_FirstFree; // ecx
  int m_nAllocationCount; // ecx
  unsigned __int16 index; // ax
  int result; // eax
  int v7; // ecx
  unsigned __int16 v8; // ax
  UtlLinkedListElem_t<CUtlMultiList<CTextureAllocator::FragmentInfo_t,unsigned short>::List_t,unsigned short> *v9; // ecx

  m_FirstFree = this->m_FirstFree;
  if ( (_WORD)m_FirstFree != 0xFFFF )
  {
    result = m_FirstFree;
    this->m_FirstFree = this->m_Memory.m_pMemory[m_FirstFree].m_Next;
LABEL_22:
    v9 = &this->m_Memory.m_pMemory[(unsigned __int16)result];
    if ( multilist )
    {
      v9->m_Next = -1;
      v9->m_Previous = -1;
    }
    else
    {
      v9->m_Next = result;
      v9->m_Previous = result;
    }
    return result;
  }
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( this->m_LastAlloc.index >= m_nAllocationCount )
  {
    m_nAllocationCount = this->m_Memory.m_nAllocationCount;
    LOWORD(result) = (m_nAllocationCount > 0) - 1;
  }
  else
  {
    index = this->m_LastAlloc.index;
    if ( (unsigned __int16)(index + 1) >= m_nAllocationCount )
      LOWORD(result) = -1;
    else
      LOWORD(result) = index + 1;
  }
  if ( (unsigned __int16)result >= m_nAllocationCount )
  {
    CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CPixelVisibilityQuery,unsigned short>::List_t,unsigned short>,unsigned short>::Grow(
      (CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short> *)this,
      num: 1);
    this->m_pElements = this->m_Memory.m_pMemory;
    v7 = this->m_Memory.m_nAllocationCount;
    if ( this->m_LastAlloc.index >= v7 )
    {
      v7 = this->m_Memory.m_nAllocationCount;
      LOWORD(result) = (v7 > 0) - 1;
    }
    else
    {
      v8 = this->m_LastAlloc.index;
      LOWORD(result) = (unsigned __int16)(v8 + 1) >= v7 ? -1 : v8 + 1;
    }
    if ( (unsigned __int16)result >= v7 )
    {
      if ( `CUtlLinkedList<CUtlMultiList<CTextureAllocator::FragmentInfo_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CTextureAllocator::FragmentInfo_t,unsigned short>::List_t,unsigned short>,unsigned short>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<CUtlMultiList<CTextureAllocator::FragmentInfo_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CTextureAllocator::FragmentInfo_t,unsigned short>::List_t,unsigned short>,unsigned short>>::AllocInternal'::`12'::__executeCount;
        _Warning(a1: "CUtlLinkedList overflow! (exhausted memory allocator)\n");
      }
      return 0xFFFF;
    }
  }
  if ( (_WORD)result != 0xFFFF )
  {
    ++this->m_NumAlloced;
    this->m_LastAlloc.index = result;
    result = (unsigned __int16)result;
    goto LABEL_22;
  }
  if ( `CUtlLinkedList<CUtlMultiList<CTextureAllocator::FragmentInfo_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CTextureAllocator::FragmentInfo_t,unsigned short>::List_t,unsigned short>,unsigned short>>::AllocInternal'::`19'::__executeCount >= 10 )
    return 0xFFFF;
  ++`CUtlLinkedList<CUtlMultiList<CTextureAllocator::FragmentInfo_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CTextureAllocator::FragmentInfo_t,unsigned short>::List_t,unsigned short>,unsigned short>>::AllocInternal'::`19'::__executeCount;
  _Warning(a1: "CUtlLinkedList overflow! (exhausted index range)\n");
  return 0xFFFF;
}

//------------------------------------------------------------------------------
// Address: 0x100B7C40
// Name: public: void CUtlLinkedList<struct CClientShadowMgr::ClientShadow_t,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<struct CClientShadowMgr::ClientShadow_t,unsigned short>,unsigned short>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CClientShadowMgr::ClientShadow_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CClientShadowMgr::ClientShadow_t,unsigned short>,unsigned short>>::RemoveAll(
        CUtlLinkedList<CClientShadowMgr::ClientShadow_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CClientShadowMgr::ClientShadow_t,unsigned short>,unsigned short> > *this)
{
  unsigned __int16 m_Head; // bx
  UtlLinkedListElem_t<CClientShadowMgr::ClientShadow_t,unsigned short> *m_pMemory; // ecx
  int v3; // esi
  unsigned __int16 m_Next; // di
  UtlLinkedListElem_t<CClientShadowMgr::ClientShadow_t,unsigned short> *v5; // esi
  unsigned __int16 m_FirstFree; // ax
  unsigned __int16 v7; // ax
  CUtlLinkedList<CClientShadowMgr::ClientShadow_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CClientShadowMgr::ClientShadow_t,unsigned short>,unsigned short> > *v8; // [esp+0h] [ebp-4h]

  v8 = this;
  if ( this->m_LastAlloc.index != 0xFFFF )
  {
    m_Head = this->m_Head;
    if ( m_Head != 0xFFFF )
    {
      do
      {
        m_pMemory = this->m_Memory.m_pMemory;
        v3 = m_Head;
        m_Next = m_pMemory[v3].m_Next;
        v5 = &m_pMemory[v3];
        CTextureReference::~CTextureReference(this: &v5->m_Element.m_ShadowDepthTexture);
        v5->m_Previous = m_Head;
        if ( m_Next == 0xFFFF )
          m_FirstFree = v8->m_FirstFree;
        else
          m_FirstFree = m_Next;
        this = v8;
        v5->m_Next = m_FirstFree;
        m_Head = m_Next;
      }
      while ( m_Next != 0xFFFF );
    }
    v7 = this->m_Head;
    if ( v7 != 0xFFFF )
      this->m_FirstFree = v7;
    *(_DWORD *)&this->m_Head = -1;
    this->m_ElementCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B8390
// Name: public: void CUtlLinkedList<struct Panel_t,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<struct Panel_t,unsigned short>,unsigned short>>::Unlink(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<Panel_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<Panel_t,unsigned short>,unsigned short>>::Unlink(
        CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 elem)
{
  unsigned __int16 v2; // di
  UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short> *v3; // eax
  int m_Previous; // ebx
  unsigned __int16 m_Next; // dx

  v2 = elem;
  if ( elem < this->m_Memory.m_nAllocationCount && elem <= this->m_LastAlloc.index )
  {
    v3 = &this->m_Memory.m_pMemory[elem];
    if ( v3->m_Previous != elem )
    {
      m_Previous = v3->m_Previous;
      m_Next = v3->m_Next;
      if ( (_WORD)m_Previous == 0xFFFF )
      {
        this->m_Head = m_Next;
      }
      else
      {
        this->m_Memory.m_pMemory[m_Previous].m_Next = m_Next;
        v2 = elem;
      }
      if ( m_Next == 0xFFFF )
        this->m_Tail = m_Previous;
      else
        this->m_Memory.m_pMemory[m_Next].m_Previous = m_Previous;
      v3->m_Next = v2;
      v3->m_Previous = v2;
      --this->m_ElementCount;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B8420
// Name: public: void CUtlLinkedList<struct CClientShadowMgr::ClientShadow_t,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<struct CClientShadowMgr::ClientShadow_t,unsigned short>,unsigned short>>::Unlink(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CClientShadowMgr::ClientShadow_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CClientShadowMgr::ClientShadow_t,unsigned short>,unsigned short>>::Unlink(
        CUtlLinkedList<CClientShadowMgr::ClientShadow_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CClientShadowMgr::ClientShadow_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 elem)
{
  unsigned __int16 v2; // bx
  UtlLinkedListElem_t<CClientShadowMgr::ClientShadow_t,unsigned short> *v3; // eax
  int m_Previous; // edi
  unsigned __int16 m_Next; // dx

  v2 = elem;
  if ( elem < this->m_Memory.m_nAllocationCount && elem <= this->m_LastAlloc.index )
  {
    v3 = &this->m_Memory.m_pMemory[elem];
    if ( v3->m_Previous != elem )
    {
      m_Previous = v3->m_Previous;
      m_Next = v3->m_Next;
      if ( (_WORD)m_Previous == 0xFFFF )
      {
        this->m_Head = m_Next;
      }
      else
      {
        this->m_Memory.m_pMemory[m_Previous].m_Next = m_Next;
        v2 = elem;
      }
      if ( m_Next == 0xFFFF )
        this->m_Tail = m_Previous;
      else
        this->m_Memory.m_pMemory[m_Next].m_Previous = m_Previous;
      v3->m_Next = v2;
      v3->m_Previous = v2;
      --this->m_ElementCount;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B99E0
// Name: public: void CUtlLinkedList<struct CUtlMultiList<class CPixelVisSet,unsigned short>::List_t,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<struct CUtlMultiList<class CPixelVisSet,unsigned short>::List_t,unsigned short>,unsigned short>>::LinkBefore(unsigned short,unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CUtlMultiList<CPixelVisSet,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CPixelVisSet,unsigned short>::List_t,unsigned short>,unsigned short>>::LinkBefore(
        CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 before,
        unsigned __int16 elem)
{
  UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short> *m_pMemory; // edx
  UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short> *v5; // ecx
  unsigned __int16 m_Tail; // ax
  UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short> *v7; // ebx

  CUtlLinkedList<Panel_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<Panel_t,unsigned short>,unsigned short>>::Unlink(
    this,
    elem);
  m_pMemory = this->m_Memory.m_pMemory;
  v5 = &this->m_Memory.m_pMemory[elem];
  v5->m_Next = before;
  if ( before == 0xFFFF )
  {
    m_Tail = this->m_Tail;
    v5->m_Previous = m_Tail;
    this->m_Tail = elem;
  }
  else
  {
    v7 = &m_pMemory[before];
    m_Tail = v7->m_Previous;
    v5->m_Previous = m_Tail;
    v7->m_Previous = elem;
  }
  if ( m_Tail == 0xFFFF )
  {
    ++this->m_ElementCount;
    this->m_Head = elem;
  }
  else
  {
    m_pMemory[m_Tail].m_Next = elem;
    ++this->m_ElementCount;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B9A70
// Name: public: void CUtlLinkedList<struct CClientShadowMgr::ClientShadow_t,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<struct CClientShadowMgr::ClientShadow_t,unsigned short>,unsigned short>>::LinkBefore(unsigned short,unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CClientShadowMgr::ClientShadow_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CClientShadowMgr::ClientShadow_t,unsigned short>,unsigned short>>::LinkBefore(
        CUtlLinkedList<CClientShadowMgr::ClientShadow_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CClientShadowMgr::ClientShadow_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 before,
        unsigned __int16 elem)
{
  UtlLinkedListElem_t<CClientShadowMgr::ClientShadow_t,unsigned short> *m_pMemory; // ebx
  unsigned int v5; // eax
  unsigned __int16 m_Tail; // dx
  int v7; // ecx

  CUtlLinkedList<CClientShadowMgr::ClientShadow_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CClientShadowMgr::ClientShadow_t,unsigned short>,unsigned short>>::Unlink(
    this,
    elem);
  m_pMemory = this->m_Memory.m_pMemory;
  v5 = elem;
  this->m_Memory.m_pMemory[v5].m_Next = before;
  if ( before == 0xFFFF )
  {
    m_Tail = this->m_Tail;
    m_pMemory[v5].m_Previous = m_Tail;
    this->m_Tail = elem;
  }
  else
  {
    v7 = before;
    m_Tail = m_pMemory[v7].m_Previous;
    m_pMemory[v5].m_Previous = m_Tail;
    m_pMemory[v7].m_Previous = elem;
  }
  if ( m_Tail == 0xFFFF )
  {
    ++this->m_ElementCount;
    this->m_Head = elem;
  }
  else
  {
    m_pMemory[m_Tail].m_Next = elem;
    ++this->m_ElementCount;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100BD9A0
// Name: public: unsigned short CUtlLinkedList<struct CClientShadowMgr::ClientShadow_t,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<struct CClientShadowMgr::ClientShadow_t,unsigned short>,unsigned short>>::AddToTail(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<CClientShadowMgr::ClientShadow_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CClientShadowMgr::ClientShadow_t,unsigned short>,unsigned short>>::AddToTail(
        CUtlLinkedList<CClientShadowMgr::ClientShadow_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CClientShadowMgr::ClientShadow_t,unsigned short>,unsigned short> > *this)
{
  int v2; // ebx
  int result; // eax
  UtlLinkedListElem_t<CClientShadowMgr::ClientShadow_t,unsigned short> *v4; // esi
  bool v5; // zf
  CBitVec<1> *p_m_SplitScreenBits; // esi

  v2 = (unsigned __int16)CUtlLinkedList<CClientShadowMgr::ClientShadow_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CClientShadowMgr::ClientShadow_t,unsigned short>,unsigned short>>::AllocInternal(
                           this,
                           multilist: false);
  result = 0xFFFF;
  if ( (_WORD)v2 != 0xFFFF )
  {
    CUtlLinkedList<CClientShadowMgr::ClientShadow_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CClientShadowMgr::ClientShadow_t,unsigned short>,unsigned short>>::LinkBefore(
      this,
      before: 0xFFFFu,
      elem: v2);
    v4 = &this->m_Memory.m_pMemory[v2];
    if ( v4 != nullptr )
    {
      v4->m_Element.m_Entity.m_Index = -1;
      CTextureReference::CTextureReference(this: &v4->m_Element.m_ShadowDepthTexture);
      v5 = &v4->m_Element.m_SplitScreenBits == nullptr;
      p_m_SplitScreenBits = &v4->m_Element.m_SplitScreenBits;
      p_m_SplitScreenBits[-2].m_Ints[0] = -1;
      if ( !v5 )
        p_m_SplitScreenBits->m_Ints[0] = 0;
    }
    return v2;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100C7910
// Name: public: static bool CDefOps<class C_BaseEntity __near *>::LessFunc(class C_BaseEntity __near * const __near &,class C_BaseEntity __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl CDefOps<C_BaseEntity *>::LessFunc(
        const C_BaseFlex::FS_LocalToGlobal_t *lhs,
        const C_BaseFlex::FS_LocalToGlobal_t *rhs)
{
  return lhs->m_Key < rhs->m_Key;
}

//------------------------------------------------------------------------------
// Address: 0x100D1C20
// Name: protected: unsigned short CUtlLinkedList<class CEnvWindShared __near *,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<class CEnvWindShared __near *,unsigned short>,unsigned short>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<CEnvWindShared *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CEnvWindShared *,unsigned short>,unsigned short>>::AllocInternal(
        CUtlLinkedList<CEnvWindShared *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CEnvWindShared *,unsigned short>,unsigned short> > *this,
        bool multilist)
{
  int m_FirstFree; // ecx
  int m_nAllocationCount; // ecx
  unsigned __int16 index; // ax
  int result; // eax
  int v7; // ecx
  unsigned __int16 v8; // ax
  UtlLinkedListElem_t<CEnvWindShared *,unsigned short> *v9; // ecx

  m_FirstFree = this->m_FirstFree;
  if ( (_WORD)m_FirstFree != 0xFFFF )
  {
    result = m_FirstFree;
    this->m_FirstFree = this->m_Memory.m_pMemory[m_FirstFree].m_Next;
LABEL_22:
    v9 = &this->m_Memory.m_pMemory[(unsigned __int16)result];
    if ( multilist )
    {
      v9->m_Next = -1;
      v9->m_Previous = -1;
    }
    else
    {
      v9->m_Next = result;
      v9->m_Previous = result;
    }
    return result;
  }
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( this->m_LastAlloc.index >= m_nAllocationCount )
  {
    m_nAllocationCount = this->m_Memory.m_nAllocationCount;
    LOWORD(result) = (m_nAllocationCount > 0) - 1;
  }
  else
  {
    index = this->m_LastAlloc.index;
    if ( (unsigned __int16)(index + 1) >= m_nAllocationCount )
      LOWORD(result) = -1;
    else
      LOWORD(result) = index + 1;
  }
  if ( (unsigned __int16)result >= m_nAllocationCount )
  {
    CUtlMemory<UtlLinkedListElem_t<CParticleEffectBinding *,unsigned short>,unsigned short>::Grow(
      (CUtlMemory<UtlLinkedListElem_t<C_RopeKeyframe *,unsigned short>,unsigned short> *)this,
      num: 1);
    this->m_pElements = this->m_Memory.m_pMemory;
    v7 = this->m_Memory.m_nAllocationCount;
    if ( this->m_LastAlloc.index >= v7 )
    {
      v7 = this->m_Memory.m_nAllocationCount;
      LOWORD(result) = (v7 > 0) - 1;
    }
    else
    {
      v8 = this->m_LastAlloc.index;
      LOWORD(result) = (unsigned __int16)(v8 + 1) >= v7 ? -1 : v8 + 1;
    }
    if ( (unsigned __int16)result >= v7 )
    {
      if ( `CUtlLinkedList<CEnvWindShared *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CEnvWindShared *,unsigned short>,unsigned short>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<CEnvWindShared *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CEnvWindShared *,unsigned short>,unsigned short>>::AllocInternal'::`12'::__executeCount;
        _Warning(a1: "CUtlLinkedList overflow! (exhausted memory allocator)\n");
      }
      return 0xFFFF;
    }
  }
  if ( (_WORD)result != 0xFFFF )
  {
    ++this->m_NumAlloced;
    this->m_LastAlloc.index = result;
    result = (unsigned __int16)result;
    goto LABEL_22;
  }
  if ( `CUtlLinkedList<CEnvWindShared *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CEnvWindShared *,unsigned short>,unsigned short>>::AllocInternal'::`19'::__executeCount >= 10 )
    return 0xFFFF;
  ++`CUtlLinkedList<CEnvWindShared *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CEnvWindShared *,unsigned short>,unsigned short>>::AllocInternal'::`19'::__executeCount;
  _Warning(a1: "CUtlLinkedList overflow! (exhausted index range)\n");
  return 0xFFFF;
}

//------------------------------------------------------------------------------
// Address: 0x100D2340
// Name: public: void CUtlLinkedList<struct CBreakableHelper::BreakableList_t,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<struct CBreakableHelper::BreakableList_t,unsigned short>,unsigned short>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CBreakableHelper::BreakableList_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CBreakableHelper::BreakableList_t,unsigned short>,unsigned short>>::RemoveAll(
        CUtlLinkedList<CEnvWindShared::WindVariationEvent_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CEnvWindShared::WindVariationEvent_t,unsigned short>,unsigned short> > *this)
{
  unsigned __int16 m_Head; // si
  UtlLinkedListElem_t<CEnvWindShared::WindVariationEvent_t,unsigned short> *v2; // edx
  unsigned __int16 m_Next; // ax
  unsigned __int16 m_FirstFree; // si
  unsigned __int16 v5; // ax

  if ( this->m_LastAlloc.index != 0xFFFF )
  {
    m_Head = this->m_Head;
    if ( m_Head != 0xFFFF )
    {
      do
      {
        v2 = &this->m_Memory.m_pMemory[m_Head];
        m_Next = v2->m_Next;
        v2->m_Previous = m_Head;
        if ( m_Next == 0xFFFF )
          m_FirstFree = this->m_FirstFree;
        else
          m_FirstFree = m_Next;
        v2->m_Next = m_FirstFree;
        m_Head = m_Next;
      }
      while ( m_Next != 0xFFFF );
    }
    v5 = this->m_Head;
    if ( v5 != 0xFFFF )
      this->m_FirstFree = v5;
    *(_DWORD *)&this->m_Head = -1;
    this->m_ElementCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D23B0
// Name: public: bool CUtlLinkedList<class C_BaseEntity __near *,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<class C_BaseEntity __near *,unsigned short>,unsigned short>>::FindAndRemove(class C_BaseEntity __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CUtlLinkedList<C_BaseEntity *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<C_BaseEntity *,unsigned short>,unsigned short>>::FindAndRemove(
        CUtlLinkedList<CEnvWindShared *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CEnvWindShared *,unsigned short>,unsigned short> > *this,
        CEnvWindShared **src)
{
  unsigned __int16 m_Head; // si
  UtlLinkedListElem_t<CEnvWindShared *,unsigned short> *m_pMemory; // edx

  m_Head = this->m_Head;
  if ( m_Head == 0xFFFF )
    return 0;
  m_pMemory = this->m_Memory.m_pMemory;
  while ( m_pMemory[m_Head].m_Element != *src )
  {
    m_Head = m_pMemory[m_Head].m_Next;
    if ( m_Head == 0xFFFF )
      return 0;
  }
  CUtlLinkedList<CEffectMaterial *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CEffectMaterial *,unsigned short>,unsigned short>>::Unlink(
    (CUtlLinkedList<C_RopeKeyframe *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<C_RopeKeyframe *,unsigned short>,unsigned short> > *)this,
    elem: m_Head);
  this->m_Memory.m_pMemory[m_Head].m_Next = this->m_FirstFree;
  this->m_FirstFree = m_Head;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100EB4D0
// Name: protected: unsigned short CUtlLinkedList<class CGlowOverlay __near *,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<class CGlowOverlay __near *,unsigned short>,unsigned short>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<CGlowOverlay *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CGlowOverlay *,unsigned short>,unsigned short>>::AllocInternal(
        CUtlLinkedList<CGlowOverlay *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CGlowOverlay *,unsigned short>,unsigned short> > *this,
        bool multilist)
{
  int m_FirstFree; // ecx
  int m_nAllocationCount; // ecx
  unsigned __int16 index; // ax
  int result; // eax
  int v7; // ecx
  unsigned __int16 v8; // ax
  UtlLinkedListElem_t<CGlowOverlay *,unsigned short> *v9; // ecx

  m_FirstFree = this->m_FirstFree;
  if ( (_WORD)m_FirstFree != 0xFFFF )
  {
    result = m_FirstFree;
    this->m_FirstFree = this->m_Memory.m_pMemory[m_FirstFree].m_Next;
LABEL_22:
    v9 = &this->m_Memory.m_pMemory[(unsigned __int16)result];
    if ( multilist )
    {
      v9->m_Next = -1;
      v9->m_Previous = -1;
    }
    else
    {
      v9->m_Next = result;
      v9->m_Previous = result;
    }
    return result;
  }
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( this->m_LastAlloc.index >= m_nAllocationCount )
  {
    m_nAllocationCount = this->m_Memory.m_nAllocationCount;
    LOWORD(result) = (m_nAllocationCount > 0) - 1;
  }
  else
  {
    index = this->m_LastAlloc.index;
    if ( (unsigned __int16)(index + 1) >= m_nAllocationCount )
      LOWORD(result) = -1;
    else
      LOWORD(result) = index + 1;
  }
  if ( (unsigned __int16)result >= m_nAllocationCount )
  {
    CUtlMemory<UtlLinkedListElem_t<CParticleEffectBinding *,unsigned short>,unsigned short>::Grow(
      (CUtlMemory<UtlLinkedListElem_t<C_RopeKeyframe *,unsigned short>,unsigned short> *)this,
      num: 1);
    this->m_pElements = this->m_Memory.m_pMemory;
    v7 = this->m_Memory.m_nAllocationCount;
    if ( this->m_LastAlloc.index >= v7 )
    {
      v7 = this->m_Memory.m_nAllocationCount;
      LOWORD(result) = (v7 > 0) - 1;
    }
    else
    {
      v8 = this->m_LastAlloc.index;
      LOWORD(result) = (unsigned __int16)(v8 + 1) >= v7 ? -1 : v8 + 1;
    }
    if ( (unsigned __int16)result >= v7 )
    {
      if ( `CUtlLinkedList<CGlowOverlay *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CGlowOverlay *,unsigned short>,unsigned short>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<CGlowOverlay *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CGlowOverlay *,unsigned short>,unsigned short>>::AllocInternal'::`12'::__executeCount;
        _Warning(a1: "CUtlLinkedList overflow! (exhausted memory allocator)\n");
      }
      return 0xFFFF;
    }
  }
  if ( (_WORD)result != 0xFFFF )
  {
    ++this->m_NumAlloced;
    this->m_LastAlloc.index = result;
    result = (unsigned __int16)result;
    goto LABEL_22;
  }
  if ( `CUtlLinkedList<CGlowOverlay *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CGlowOverlay *,unsigned short>,unsigned short>>::AllocInternal'::`19'::__executeCount >= 10 )
    return 0xFFFF;
  ++`CUtlLinkedList<CGlowOverlay *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CGlowOverlay *,unsigned short>,unsigned short>>::AllocInternal'::`19'::__executeCount;
  _Warning(a1: "CUtlLinkedList overflow! (exhausted index range)\n");
  return 0xFFFF;
}

//------------------------------------------------------------------------------
// Address: 0x100EC450
// Name: public: void CUtlLinkedList<class CGlowOverlay __near *,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<class CGlowOverlay __near *,unsigned short>,unsigned short>>::PurgeAndDeleteElements(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CGlowOverlay *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CGlowOverlay *,unsigned short>,unsigned short>>::PurgeAndDeleteElements(
        CUtlLinkedList<CGlowOverlay *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CGlowOverlay *,unsigned short>,unsigned short> > *this)
{
  unsigned __int16 m_Head; // ax
  unsigned __int16 m_Next; // di
  CGlowOverlay *m_Element; // eax
  UtlLinkedListElem_t<CGlowOverlay *,unsigned short> *m_pMemory; // ecx

  m_Head = this->m_Head;
  if ( m_Head != 0xFFFF )
  {
    do
    {
      m_Next = this->m_Memory.m_pMemory[m_Head].m_Next;
      m_Element = this->m_Memory.m_pMemory[m_Head].m_Element;
      if ( m_Element != nullptr )
        ((void (__thiscall *)(CGlowOverlay *, int))m_Element->dtr_CGlowOverlay)(a1: m_Element, a2: 1);
      m_Head = m_Next;
    }
    while ( m_Next != 0xFFFF );
  }
  CUtlLinkedList<CEnvWindShared *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CEnvWindShared *,unsigned short>,unsigned short>>::RemoveAll((CUtlLinkedList<C_BaseCombatWeapon *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<C_BaseCombatWeapon *,unsigned short>,unsigned short> > *)this);
  if ( this->m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
  this->m_FirstFree = -1;
  m_pMemory = this->m_Memory.m_pMemory;
  *(_DWORD *)&this->m_NumAlloced = -65536;
  this->m_pElements = m_pMemory;
}

//------------------------------------------------------------------------------
// Address: 0x100EC4E0
// Name: public: void CUtlLinkedList<class CEnvWindShared __near *,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<class CEnvWindShared __near *,unsigned short>,unsigned short>>::LinkBefore(unsigned short,unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CEnvWindShared *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CEnvWindShared *,unsigned short>,unsigned short>>::LinkBefore(
        CUtlLinkedList<C_RopeKeyframe *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<C_RopeKeyframe *,unsigned short>,unsigned short> > *this,
        unsigned __int16 before,
        unsigned __int16 elem)
{
  UtlLinkedListElem_t<C_RopeKeyframe *,unsigned short> *m_pMemory; // edx
  UtlLinkedListElem_t<C_RopeKeyframe *,unsigned short> *v5; // ecx
  unsigned __int16 m_Tail; // ax
  UtlLinkedListElem_t<C_RopeKeyframe *,unsigned short> *v7; // ebx

  CUtlLinkedList<CEffectMaterial *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CEffectMaterial *,unsigned short>,unsigned short>>::Unlink(
    this,
    elem);
  m_pMemory = this->m_Memory.m_pMemory;
  v5 = &this->m_Memory.m_pMemory[elem];
  v5->m_Next = before;
  if ( before == 0xFFFF )
  {
    m_Tail = this->m_Tail;
    v5->m_Previous = m_Tail;
    this->m_Tail = elem;
  }
  else
  {
    v7 = &m_pMemory[before];
    m_Tail = v7->m_Previous;
    v5->m_Previous = m_Tail;
    v7->m_Previous = elem;
  }
  if ( m_Tail == 0xFFFF )
  {
    ++this->m_ElementCount;
    this->m_Head = elem;
  }
  else
  {
    m_pMemory[m_Tail].m_Next = elem;
    ++this->m_ElementCount;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100F6AF0
// Name: protected: unsigned short CUtlLinkedList<char const __near *,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<char const __near *,unsigned short>,unsigned short>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<char const *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<char const *,unsigned short>,unsigned short>>::AllocInternal(
        CUtlLinkedList<char const *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<char const *,unsigned short>,unsigned short> > *this,
        bool multilist)
{
  int m_FirstFree; // ecx
  int m_nAllocationCount; // ecx
  unsigned __int16 index; // ax
  int result; // eax
  int v7; // ecx
  unsigned __int16 v8; // ax
  UtlLinkedListElem_t<char const *,unsigned short> *v9; // ecx

  m_FirstFree = this->m_FirstFree;
  if ( (_WORD)m_FirstFree != 0xFFFF )
  {
    result = m_FirstFree;
    this->m_FirstFree = this->m_Memory.m_pMemory[m_FirstFree].m_Next;
LABEL_22:
    v9 = &this->m_Memory.m_pMemory[(unsigned __int16)result];
    if ( multilist )
    {
      v9->m_Next = -1;
      v9->m_Previous = -1;
    }
    else
    {
      v9->m_Next = result;
      v9->m_Previous = result;
    }
    return result;
  }
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( this->m_LastAlloc.index >= m_nAllocationCount )
  {
    m_nAllocationCount = this->m_Memory.m_nAllocationCount;
    LOWORD(result) = (m_nAllocationCount > 0) - 1;
  }
  else
  {
    index = this->m_LastAlloc.index;
    if ( (unsigned __int16)(index + 1) >= m_nAllocationCount )
      LOWORD(result) = -1;
    else
      LOWORD(result) = index + 1;
  }
  if ( (unsigned __int16)result >= m_nAllocationCount )
  {
    CUtlMemory<UtlLinkedListElem_t<CParticleEffectBinding *,unsigned short>,unsigned short>::Grow(
      (CUtlMemory<UtlLinkedListElem_t<C_RopeKeyframe *,unsigned short>,unsigned short> *)this,
      num: 1);
    this->m_pElements = this->m_Memory.m_pMemory;
    v7 = this->m_Memory.m_nAllocationCount;
    if ( this->m_LastAlloc.index >= v7 )
    {
      v7 = this->m_Memory.m_nAllocationCount;
      LOWORD(result) = (v7 > 0) - 1;
    }
    else
    {
      v8 = this->m_LastAlloc.index;
      LOWORD(result) = (unsigned __int16)(v8 + 1) >= v7 ? -1 : v8 + 1;
    }
    if ( (unsigned __int16)result >= v7 )
    {
      if ( `CUtlLinkedList<char const *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<char const *,unsigned short>,unsigned short>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<char const *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<char const *,unsigned short>,unsigned short>>::AllocInternal'::`12'::__executeCount;
        _Warning(a1: "CUtlLinkedList overflow! (exhausted memory allocator)\n");
      }
      return 0xFFFF;
    }
  }
  if ( (_WORD)result != 0xFFFF )
  {
    ++this->m_NumAlloced;
    this->m_LastAlloc.index = result;
    result = (unsigned __int16)result;
    goto LABEL_22;
  }
  if ( `CUtlLinkedList<char const *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<char const *,unsigned short>,unsigned short>>::AllocInternal'::`19'::__executeCount >= 10 )
    return 0xFFFF;
  ++`CUtlLinkedList<char const *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<char const *,unsigned short>,unsigned short>>::AllocInternal'::`19'::__executeCount;
  _Warning(a1: "CUtlLinkedList overflow! (exhausted index range)\n");
  return 0xFFFF;
}

//------------------------------------------------------------------------------
// Address: 0x100F6E20
// Name: public: void CUtlLinkedList<char const __near *,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<char const __near *,unsigned short>,unsigned short>>::LinkAfter(unsigned short,unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<char const *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<char const *,unsigned short>,unsigned short>>::LinkAfter(
        CUtlLinkedList<char const *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<char const *,unsigned short>,unsigned short> > *this,
        unsigned __int16 after,
        unsigned __int16 elem)
{
  UtlLinkedListElem_t<char const *,unsigned short> *v4; // eax
  UtlLinkedListElem_t<char const *,unsigned short> *v5; // ecx
  int m_Next; // eax

  if ( elem < this->m_Memory.m_nAllocationCount
    && elem <= this->m_LastAlloc.index
    && this->m_Memory.m_pMemory[elem].m_Previous != elem )
  {
    CUtlLinkedList<CEffectMaterial *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CEffectMaterial *,unsigned short>,unsigned short>>::Unlink(
      (CUtlLinkedList<C_RopeKeyframe *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<C_RopeKeyframe *,unsigned short>,unsigned short> > *)this,
      elem);
  }
  v4 = &this->m_Memory.m_pMemory[elem];
  v4->m_Previous = after;
  if ( after == 0xFFFF )
  {
    v4->m_Next = this->m_Head;
    this->m_Head = elem;
  }
  else
  {
    v5 = &this->m_Memory.m_pMemory[after];
    v4->m_Next = v5->m_Next;
    v5->m_Next = elem;
  }
  m_Next = v4->m_Next;
  if ( (_WORD)m_Next == 0xFFFF )
  {
    ++this->m_ElementCount;
    this->m_Tail = elem;
  }
  else
  {
    this->m_Memory.m_pMemory[m_Next].m_Previous = elem;
    ++this->m_ElementCount;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100F9700
// Name: protected: unsigned short CUtlLinkedList<class CAsyncCaption __near *,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<class CAsyncCaption __near *,unsigned short>,unsigned short>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<CAsyncCaption *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CAsyncCaption *,unsigned short>,unsigned short>>::AllocInternal(
        CUtlLinkedList<CAsyncCaption *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CAsyncCaption *,unsigned short>,unsigned short> > *this,
        bool multilist)
{
  int m_FirstFree; // ecx
  int m_nAllocationCount; // ecx
  unsigned __int16 index; // ax
  int result; // eax
  int v7; // ecx
  unsigned __int16 v8; // ax
  UtlLinkedListElem_t<CAsyncCaption *,unsigned short> *v9; // ecx

  m_FirstFree = this->m_FirstFree;
  if ( (_WORD)m_FirstFree != 0xFFFF )
  {
    result = m_FirstFree;
    this->m_FirstFree = this->m_Memory.m_pMemory[m_FirstFree].m_Next;
LABEL_22:
    v9 = &this->m_Memory.m_pMemory[(unsigned __int16)result];
    if ( multilist )
    {
      v9->m_Next = -1;
      v9->m_Previous = -1;
    }
    else
    {
      v9->m_Next = result;
      v9->m_Previous = result;
    }
    return result;
  }
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( this->m_LastAlloc.index >= m_nAllocationCount )
  {
    m_nAllocationCount = this->m_Memory.m_nAllocationCount;
    LOWORD(result) = (m_nAllocationCount > 0) - 1;
  }
  else
  {
    index = this->m_LastAlloc.index;
    if ( (unsigned __int16)(index + 1) >= m_nAllocationCount )
      LOWORD(result) = -1;
    else
      LOWORD(result) = index + 1;
  }
  if ( (unsigned __int16)result >= m_nAllocationCount )
  {
    CUtlMemory<UtlLinkedListElem_t<CParticleEffectBinding *,unsigned short>,unsigned short>::Grow(
      (CUtlMemory<UtlLinkedListElem_t<C_RopeKeyframe *,unsigned short>,unsigned short> *)this,
      num: 1);
    this->m_pElements = this->m_Memory.m_pMemory;
    v7 = this->m_Memory.m_nAllocationCount;
    if ( this->m_LastAlloc.index >= v7 )
    {
      v7 = this->m_Memory.m_nAllocationCount;
      LOWORD(result) = (v7 > 0) - 1;
    }
    else
    {
      v8 = this->m_LastAlloc.index;
      LOWORD(result) = (unsigned __int16)(v8 + 1) >= v7 ? -1 : v8 + 1;
    }
    if ( (unsigned __int16)result >= v7 )
    {
      if ( `CUtlLinkedList<CAsyncCaption *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CAsyncCaption *,unsigned short>,unsigned short>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<CAsyncCaption *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CAsyncCaption *,unsigned short>,unsigned short>>::AllocInternal'::`12'::__executeCount;
        _Warning(a1: "CUtlLinkedList overflow! (exhausted memory allocator)\n");
      }
      return 0xFFFF;
    }
  }
  if ( (_WORD)result != 0xFFFF )
  {
    ++this->m_NumAlloced;
    this->m_LastAlloc.index = result;
    result = (unsigned __int16)result;
    goto LABEL_22;
  }
  if ( `CUtlLinkedList<CAsyncCaption *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CAsyncCaption *,unsigned short>,unsigned short>>::AllocInternal'::`19'::__executeCount >= 10 )
    return 0xFFFF;
  ++`CUtlLinkedList<CAsyncCaption *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CAsyncCaption *,unsigned short>,unsigned short>>::AllocInternal'::`19'::__executeCount;
  _Warning(a1: "CUtlLinkedList overflow! (exhausted index range)\n");
  return 0xFFFF;
}

//------------------------------------------------------------------------------
// Address: 0x100FAE10
// Name: public: void CUtlLinkedList<class CEnvWindShared __near *,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<class CEnvWindShared __near *,unsigned short>,unsigned short>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CEnvWindShared *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CEnvWindShared *,unsigned short>,unsigned short>>::RemoveAll(
        CUtlLinkedList<C_BaseCombatWeapon *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<C_BaseCombatWeapon *,unsigned short>,unsigned short> > *this)
{
  unsigned __int16 m_Head; // dx
  UtlLinkedListElem_t<C_BaseCombatWeapon *,unsigned short> *v2; // esi
  unsigned __int16 m_Next; // ax
  unsigned __int16 m_FirstFree; // dx
  unsigned __int16 v5; // ax

  if ( this->m_LastAlloc.index != 0xFFFF )
  {
    m_Head = this->m_Head;
    if ( m_Head != 0xFFFF )
    {
      do
      {
        v2 = &this->m_Memory.m_pMemory[m_Head];
        m_Next = v2->m_Next;
        v2->m_Previous = m_Head;
        if ( m_Next == 0xFFFF )
          m_FirstFree = this->m_FirstFree;
        else
          m_FirstFree = m_Next;
        v2->m_Next = m_FirstFree;
        m_Head = m_Next;
      }
      while ( m_Next != 0xFFFF );
    }
    v5 = this->m_Head;
    if ( v5 != 0xFFFF )
      this->m_FirstFree = v5;
    *(_DWORD *)&this->m_Head = -1;
    this->m_ElementCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100FB120
// Name: public: void CUtlLinkedList<class CEffectMaterial __near *,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<class CEffectMaterial __near *,unsigned short>,unsigned short>>::Unlink(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CEffectMaterial *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CEffectMaterial *,unsigned short>,unsigned short>>::Unlink(
        CUtlLinkedList<C_RopeKeyframe *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<C_RopeKeyframe *,unsigned short>,unsigned short> > *this,
        unsigned __int16 elem)
{
  unsigned __int16 v2; // bx
  UtlLinkedListElem_t<C_RopeKeyframe *,unsigned short> *m_pMemory; // eax
  int m_Previous; // edi
  unsigned __int16 *p_m_Next; // edx
  unsigned __int16 v7; // cx

  v2 = elem;
  if ( elem < this->m_Memory.m_nAllocationCount && elem <= this->m_LastAlloc.index )
  {
    m_pMemory = this->m_Memory.m_pMemory;
    if ( this->m_Memory.m_pMemory[elem].m_Previous != elem )
    {
      m_Previous = m_pMemory[elem].m_Previous;
      p_m_Next = &m_pMemory[elem].m_Next;
      v7 = *p_m_Next;
      if ( (_WORD)m_Previous == 0xFFFF )
      {
        this->m_Head = v7;
      }
      else
      {
        m_pMemory[m_Previous].m_Next = v7;
        v2 = elem;
      }
      if ( v7 == 0xFFFF )
        this->m_Tail = m_Previous;
      else
        this->m_Memory.m_pMemory[v7].m_Previous = m_Previous;
      *p_m_Next = v2;
      --this->m_ElementCount;
      m_pMemory[elem].m_Previous = v2;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10119800
// Name: protected: unsigned short CUtlLinkedList<struct JiggleData,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<struct JiggleData,unsigned short>,unsigned short>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<JiggleData,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<JiggleData,unsigned short>,unsigned short>>::AllocInternal(
        CUtlLinkedList<JiggleData,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<JiggleData,unsigned short>,unsigned short> > *this,
        bool multilist)
{
  int m_FirstFree; // ecx
  int m_nAllocationCount; // ecx
  unsigned __int16 index; // ax
  int result; // eax
  int v7; // ecx
  unsigned __int16 v8; // ax
  unsigned int v9; // ecx
  UtlLinkedListElem_t<JiggleData,unsigned short> *m_pMemory; // edx
  UtlLinkedListElem_t<JiggleData,unsigned short> *v11; // ecx

  m_FirstFree = this->m_FirstFree;
  if ( (_WORD)m_FirstFree != 0xFFFF )
  {
    result = m_FirstFree;
    this->m_FirstFree = this->m_Memory.m_pMemory[m_FirstFree].m_Next;
LABEL_22:
    v9 = (unsigned __int16)result;
    if ( multilist )
    {
      v11 = &this->m_Memory.m_pMemory[v9];
      v11->m_Next = -1;
      v11->m_Previous = -1;
    }
    else
    {
      m_pMemory = this->m_Memory.m_pMemory;
      m_pMemory[v9].m_Next = result;
      m_pMemory[v9].m_Previous = result;
    }
    return result;
  }
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( this->m_LastAlloc.index >= m_nAllocationCount )
  {
    m_nAllocationCount = this->m_Memory.m_nAllocationCount;
    LOWORD(result) = (m_nAllocationCount > 0) - 1;
  }
  else
  {
    index = this->m_LastAlloc.index;
    if ( (unsigned __int16)(index + 1) >= m_nAllocationCount )
      LOWORD(result) = -1;
    else
      LOWORD(result) = index + 1;
  }
  if ( (unsigned __int16)result >= m_nAllocationCount )
  {
    CUtlMemory<UtlLinkedListElem_t<JiggleData,unsigned short>,unsigned short>::Grow(this: &this->m_Memory, num: 1);
    this->m_pElements = this->m_Memory.m_pMemory;
    v7 = this->m_Memory.m_nAllocationCount;
    if ( this->m_LastAlloc.index >= v7 )
    {
      v7 = this->m_Memory.m_nAllocationCount;
      LOWORD(result) = (v7 > 0) - 1;
    }
    else
    {
      v8 = this->m_LastAlloc.index;
      LOWORD(result) = (unsigned __int16)(v8 + 1) >= v7 ? -1 : v8 + 1;
    }
    if ( (unsigned __int16)result >= v7 )
    {
      if ( `CUtlLinkedList<JiggleData,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<JiggleData,unsigned short>,unsigned short>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<JiggleData,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<JiggleData,unsigned short>,unsigned short>>::AllocInternal'::`12'::__executeCount;
        _Warning(a1: "CUtlLinkedList overflow! (exhausted memory allocator)\n");
      }
      return 0xFFFF;
    }
  }
  if ( (_WORD)result != 0xFFFF )
  {
    ++this->m_NumAlloced;
    this->m_LastAlloc.index = result;
    result = (unsigned __int16)result;
    goto LABEL_22;
  }
  if ( `CUtlLinkedList<JiggleData,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<JiggleData,unsigned short>,unsigned short>>::AllocInternal'::`19'::__executeCount >= 10 )
    return 0xFFFF;
  ++`CUtlLinkedList<JiggleData,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<JiggleData,unsigned short>,unsigned short>>::AllocInternal'::`19'::__executeCount;
  _Warning(a1: "CUtlLinkedList overflow! (exhausted index range)\n");
  return 0xFFFF;
}

//------------------------------------------------------------------------------
// Address: 0x10119980
// Name: public: void CUtlLinkedList<struct JiggleData,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<struct JiggleData,unsigned short>,unsigned short>>::Unlink(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<JiggleData,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<JiggleData,unsigned short>,unsigned short>>::Unlink(
        CUtlLinkedList<JiggleData,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<JiggleData,unsigned short>,unsigned short> > *this,
        unsigned __int16 elem)
{
  unsigned __int16 v2; // bx
  UtlLinkedListElem_t<JiggleData,unsigned short> *v3; // eax
  int m_Previous; // edi
  unsigned __int16 m_Next; // dx

  v2 = elem;
  if ( elem < this->m_Memory.m_nAllocationCount && elem <= this->m_LastAlloc.index )
  {
    v3 = &this->m_Memory.m_pMemory[elem];
    if ( v3->m_Previous != elem )
    {
      m_Previous = v3->m_Previous;
      m_Next = v3->m_Next;
      if ( (_WORD)m_Previous == 0xFFFF )
      {
        this->m_Head = m_Next;
      }
      else
      {
        this->m_Memory.m_pMemory[m_Previous].m_Next = m_Next;
        v2 = elem;
      }
      if ( m_Next == 0xFFFF )
        this->m_Tail = m_Previous;
      else
        this->m_Memory.m_pMemory[m_Next].m_Previous = m_Previous;
      v3->m_Next = v2;
      v3->m_Previous = v2;
      --this->m_ElementCount;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10119A10
// Name: public: void CUtlLinkedList<struct JiggleData,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<struct JiggleData,unsigned short>,unsigned short>>::LinkAfter(unsigned short,unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<JiggleData,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<JiggleData,unsigned short>,unsigned short>>::LinkAfter(
        CUtlLinkedList<JiggleData,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<JiggleData,unsigned short>,unsigned short> > *this,
        unsigned __int16 after,
        unsigned __int16 elem)
{
  UtlLinkedListElem_t<JiggleData,unsigned short> *v4; // edi
  UtlLinkedListElem_t<JiggleData,unsigned short> *v5; // eax
  int m_Next; // eax

  if ( elem < this->m_Memory.m_nAllocationCount
    && elem <= this->m_LastAlloc.index
    && this->m_Memory.m_pMemory[elem].m_Previous != elem )
  {
    CUtlLinkedList<JiggleData,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<JiggleData,unsigned short>,unsigned short>>::Unlink(
      this,
      elem);
  }
  v4 = &this->m_Memory.m_pMemory[elem];
  v4->m_Previous = after;
  if ( after == 0xFFFF )
  {
    v4->m_Next = this->m_Head;
    this->m_Head = elem;
  }
  else
  {
    v5 = &this->m_Memory.m_pMemory[after];
    v4->m_Next = v5->m_Next;
    v5->m_Next = elem;
  }
  m_Next = v4->m_Next;
  if ( (_WORD)m_Next == 0xFFFF )
  {
    ++this->m_ElementCount;
    this->m_Tail = elem;
  }
  else
  {
    this->m_Memory.m_pMemory[m_Next].m_Previous = elem;
    ++this->m_ElementCount;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10131680
// Name: protected: unsigned short CUtlLinkedList<class CEffectMaterial __near *,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<class CEffectMaterial __near *,unsigned short>,unsigned short>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<CEffectMaterial *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CEffectMaterial *,unsigned short>,unsigned short>>::AllocInternal(
        CUtlLinkedList<CEffectMaterial *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CEffectMaterial *,unsigned short>,unsigned short> > *this,
        bool multilist)
{
  int m_FirstFree; // ecx
  int m_nAllocationCount; // ecx
  unsigned __int16 index; // ax
  int result; // eax
  int v7; // ecx
  unsigned __int16 v8; // ax
  UtlLinkedListElem_t<CEffectMaterial *,unsigned short> *v9; // ecx

  m_FirstFree = this->m_FirstFree;
  if ( (_WORD)m_FirstFree != 0xFFFF )
  {
    result = m_FirstFree;
    this->m_FirstFree = this->m_Memory.m_pMemory[m_FirstFree].m_Next;
LABEL_22:
    v9 = &this->m_Memory.m_pMemory[(unsigned __int16)result];
    if ( multilist )
    {
      v9->m_Next = -1;
      v9->m_Previous = -1;
    }
    else
    {
      v9->m_Next = result;
      v9->m_Previous = result;
    }
    return result;
  }
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( this->m_LastAlloc.index >= m_nAllocationCount )
  {
    m_nAllocationCount = this->m_Memory.m_nAllocationCount;
    LOWORD(result) = (m_nAllocationCount > 0) - 1;
  }
  else
  {
    index = this->m_LastAlloc.index;
    if ( (unsigned __int16)(index + 1) >= m_nAllocationCount )
      LOWORD(result) = -1;
    else
      LOWORD(result) = index + 1;
  }
  if ( (unsigned __int16)result >= m_nAllocationCount )
  {
    CUtlMemory<UtlLinkedListElem_t<CParticleEffectBinding *,unsigned short>,unsigned short>::Grow(
      (CUtlMemory<UtlLinkedListElem_t<C_RopeKeyframe *,unsigned short>,unsigned short> *)this,
      num: 1);
    this->m_pElements = this->m_Memory.m_pMemory;
    v7 = this->m_Memory.m_nAllocationCount;
    if ( this->m_LastAlloc.index >= v7 )
    {
      v7 = this->m_Memory.m_nAllocationCount;
      LOWORD(result) = (v7 > 0) - 1;
    }
    else
    {
      v8 = this->m_LastAlloc.index;
      LOWORD(result) = (unsigned __int16)(v8 + 1) >= v7 ? -1 : v8 + 1;
    }
    if ( (unsigned __int16)result >= v7 )
    {
      if ( `CUtlLinkedList<CEffectMaterial *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CEffectMaterial *,unsigned short>,unsigned short>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<CEffectMaterial *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CEffectMaterial *,unsigned short>,unsigned short>>::AllocInternal'::`12'::__executeCount;
        _Warning(a1: "CUtlLinkedList overflow! (exhausted memory allocator)\n");
      }
      return 0xFFFF;
    }
  }
  if ( (_WORD)result != 0xFFFF )
  {
    ++this->m_NumAlloced;
    this->m_LastAlloc.index = result;
    result = (unsigned __int16)result;
    goto LABEL_22;
  }
  if ( `CUtlLinkedList<CEffectMaterial *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CEffectMaterial *,unsigned short>,unsigned short>>::AllocInternal'::`19'::__executeCount >= 10 )
    return 0xFFFF;
  ++`CUtlLinkedList<CEffectMaterial *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CEffectMaterial *,unsigned short>,unsigned short>>::AllocInternal'::`19'::__executeCount;
  _Warning(a1: "CUtlLinkedList overflow! (exhausted index range)\n");
  return 0xFFFF;
}

//------------------------------------------------------------------------------
// Address: 0x10131800
// Name: protected: unsigned short CUtlLinkedList<class CParticleEffectBinding __near *,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<class CParticleEffectBinding __near *,unsigned short>,unsigned short>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<CParticleEffectBinding *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CParticleEffectBinding *,unsigned short>,unsigned short>>::AllocInternal(
        CUtlLinkedList<CParticleEffectBinding *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CParticleEffectBinding *,unsigned short>,unsigned short> > *this,
        bool multilist)
{
  int m_FirstFree; // ecx
  int m_nAllocationCount; // ecx
  unsigned __int16 index; // ax
  int result; // eax
  int v7; // ecx
  unsigned __int16 v8; // ax
  UtlLinkedListElem_t<CParticleEffectBinding *,unsigned short> *v9; // ecx

  m_FirstFree = this->m_FirstFree;
  if ( (_WORD)m_FirstFree != 0xFFFF )
  {
    result = m_FirstFree;
    this->m_FirstFree = this->m_Memory.m_pMemory[m_FirstFree].m_Next;
LABEL_22:
    v9 = &this->m_Memory.m_pMemory[(unsigned __int16)result];
    if ( multilist )
    {
      v9->m_Next = -1;
      v9->m_Previous = -1;
    }
    else
    {
      v9->m_Next = result;
      v9->m_Previous = result;
    }
    return result;
  }
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( this->m_LastAlloc.index >= m_nAllocationCount )
  {
    m_nAllocationCount = this->m_Memory.m_nAllocationCount;
    LOWORD(result) = (m_nAllocationCount > 0) - 1;
  }
  else
  {
    index = this->m_LastAlloc.index;
    if ( (unsigned __int16)(index + 1) >= m_nAllocationCount )
      LOWORD(result) = -1;
    else
      LOWORD(result) = index + 1;
  }
  if ( (unsigned __int16)result >= m_nAllocationCount )
  {
    CUtlMemory<UtlLinkedListElem_t<CParticleEffectBinding *,unsigned short>,unsigned short>::Grow(
      (CUtlMemory<UtlLinkedListElem_t<C_RopeKeyframe *,unsigned short>,unsigned short> *)this,
      num: 1);
    this->m_pElements = this->m_Memory.m_pMemory;
    v7 = this->m_Memory.m_nAllocationCount;
    if ( this->m_LastAlloc.index >= v7 )
    {
      v7 = this->m_Memory.m_nAllocationCount;
      LOWORD(result) = (v7 > 0) - 1;
    }
    else
    {
      v8 = this->m_LastAlloc.index;
      LOWORD(result) = (unsigned __int16)(v8 + 1) >= v7 ? -1 : v8 + 1;
    }
    if ( (unsigned __int16)result >= v7 )
    {
      if ( `CUtlLinkedList<CParticleEffectBinding *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CParticleEffectBinding *,unsigned short>,unsigned short>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<CParticleEffectBinding *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CParticleEffectBinding *,unsigned short>,unsigned short>>::AllocInternal'::`12'::__executeCount;
        _Warning(a1: "CUtlLinkedList overflow! (exhausted memory allocator)\n");
      }
      return 0xFFFF;
    }
  }
  if ( (_WORD)result != 0xFFFF )
  {
    ++this->m_NumAlloced;
    this->m_LastAlloc.index = result;
    result = (unsigned __int16)result;
    goto LABEL_22;
  }
  if ( `CUtlLinkedList<CParticleEffectBinding *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CParticleEffectBinding *,unsigned short>,unsigned short>>::AllocInternal'::`19'::__executeCount >= 10 )
    return 0xFFFF;
  ++`CUtlLinkedList<CParticleEffectBinding *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CParticleEffectBinding *,unsigned short>,unsigned short>>::AllocInternal'::`19'::__executeCount;
  _Warning(a1: "CUtlLinkedList overflow! (exhausted index range)\n");
  return 0xFFFF;
}

//------------------------------------------------------------------------------
// Address: 0x10162FA0
// Name: protected: unsigned short CUtlLinkedList<class CRagdollEntry,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<class CRagdollEntry,unsigned short>,unsigned short>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<CRagdollEntry,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CRagdollEntry,unsigned short>,unsigned short>>::AllocInternal(
        CUtlLinkedList<CRagdollEntry,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CRagdollEntry,unsigned short>,unsigned short> > *this,
        bool multilist)
{
  int m_FirstFree; // ecx
  int m_nAllocationCount; // ecx
  unsigned __int16 index; // ax
  int result; // eax
  int v7; // ecx
  unsigned __int16 v8; // ax
  UtlLinkedListElem_t<CRagdollEntry,unsigned short> *v9; // ecx

  m_FirstFree = this->m_FirstFree;
  if ( (_WORD)m_FirstFree != 0xFFFF )
  {
    result = m_FirstFree;
    this->m_FirstFree = this->m_Memory.m_pMemory[m_FirstFree].m_Next;
LABEL_22:
    v9 = &this->m_Memory.m_pMemory[(unsigned __int16)result];
    if ( multilist )
    {
      v9->m_Next = -1;
      v9->m_Previous = -1;
    }
    else
    {
      v9->m_Next = result;
      v9->m_Previous = result;
    }
    return result;
  }
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( this->m_LastAlloc.index >= m_nAllocationCount )
  {
    m_nAllocationCount = this->m_Memory.m_nAllocationCount;
    LOWORD(result) = (m_nAllocationCount > 0) - 1;
  }
  else
  {
    index = this->m_LastAlloc.index;
    if ( (unsigned __int16)(index + 1) >= m_nAllocationCount )
      LOWORD(result) = -1;
    else
      LOWORD(result) = index + 1;
  }
  if ( (unsigned __int16)result >= m_nAllocationCount )
  {
    CUtlMemory<UtlLinkedListElem_t<CRagdollEntry,unsigned short>,unsigned short>::Grow(
      (CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> *)this,
      num: 1);
    this->m_pElements = this->m_Memory.m_pMemory;
    v7 = this->m_Memory.m_nAllocationCount;
    if ( this->m_LastAlloc.index >= v7 )
    {
      v7 = this->m_Memory.m_nAllocationCount;
      LOWORD(result) = (v7 > 0) - 1;
    }
    else
    {
      v8 = this->m_LastAlloc.index;
      LOWORD(result) = (unsigned __int16)(v8 + 1) >= v7 ? -1 : v8 + 1;
    }
    if ( (unsigned __int16)result >= v7 )
    {
      if ( `CUtlLinkedList<CRagdollEntry,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CRagdollEntry,unsigned short>,unsigned short>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<CRagdollEntry,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CRagdollEntry,unsigned short>,unsigned short>>::AllocInternal'::`12'::__executeCount;
        _Warning(a1: "CUtlLinkedList overflow! (exhausted memory allocator)\n");
      }
      return 0xFFFF;
    }
  }
  if ( (_WORD)result != 0xFFFF )
  {
    ++this->m_NumAlloced;
    this->m_LastAlloc.index = result;
    result = (unsigned __int16)result;
    goto LABEL_22;
  }
  if ( `CUtlLinkedList<CRagdollEntry,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CRagdollEntry,unsigned short>,unsigned short>>::AllocInternal'::`19'::__executeCount >= 10 )
    return 0xFFFF;
  ++`CUtlLinkedList<CRagdollEntry,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CRagdollEntry,unsigned short>,unsigned short>>::AllocInternal'::`19'::__executeCount;
  _Warning(a1: "CUtlLinkedList overflow! (exhausted index range)\n");
  return 0xFFFF;
}

//------------------------------------------------------------------------------
// Address: 0x101BB560
// Name: public: void CUtlLinkedList<class CAddonModel,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<class CAddonModel,int>,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CAddonModel,int,0,int,CUtlMemory<UtlLinkedListElem_t<CAddonModel,int>,int>>::RemoveAll(
        CUtlLinkedList<CAddonModel,int,0,int,CUtlMemory<UtlLinkedListElem_t<CAddonModel,int>,int> > *this)
{
  int m_Head; // eax
  UtlLinkedListElem_t<CAddonModel,int> *v2; // esi
  int m_Next; // edx
  int m_FirstFree; // eax
  int v5; // eax

  if ( this->m_LastAlloc.index != -1 )
  {
    m_Head = this->m_Head;
    if ( m_Head != -1 )
    {
      do
      {
        v2 = &this->m_Memory.m_pMemory[m_Head];
        m_Next = v2->m_Next;
        v2->m_Previous = m_Head;
        if ( m_Next == -1 )
          m_FirstFree = this->m_FirstFree;
        else
          m_FirstFree = m_Next;
        v2->m_Next = m_FirstFree;
        m_Head = m_Next;
      }
      while ( m_Next != -1 );
    }
    v5 = this->m_Head;
    if ( v5 != -1 )
      this->m_FirstFree = v5;
    this->m_Head = -1;
    this->m_Tail = -1;
    this->m_ElementCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101BB5C0
// Name: protected: int CUtlLinkedList<class C_CSPlayer::CCSSoundEvent,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<class C_CSPlayer::CCSSoundEvent,int>,int>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<C_CSPlayer::CCSSoundEvent,int,0,int,CUtlMemory<UtlLinkedListElem_t<C_CSPlayer::CCSSoundEvent,int>,int>>::AllocInternal(
        CUtlLinkedList<C_CSPlayer::CCSSoundEvent,int,0,int,CUtlMemory<UtlLinkedListElem_t<C_CSPlayer::CCSSoundEvent,int>,int> > *this,
        bool multilist)
{
  int m_FirstFree; // ecx
  int index; // eax
  int m_nAllocationCount; // ecx
  int result; // eax
  int v7; // eax
  int v8; // ecx
  UtlLinkedListElem_t<C_CSPlayer::CCSSoundEvent,int> *m_pMemory; // ecx

  m_FirstFree = this->m_FirstFree;
  if ( m_FirstFree != -1 )
  {
    result = m_FirstFree;
    this->m_FirstFree = this->m_Memory.m_pMemory[m_FirstFree].m_Next;
LABEL_23:
    m_pMemory = this->m_Memory.m_pMemory;
    if ( multilist )
    {
      m_pMemory[result].m_Next = -1;
      m_pMemory[result].m_Previous = -1;
    }
    else
    {
      m_pMemory[result].m_Next = result;
      m_pMemory[result].m_Previous = result;
    }
    return result;
  }
  index = this->m_LastAlloc.index;
  if ( index < 0 || (m_nAllocationCount = this->m_Memory.m_nAllocationCount, index >= m_nAllocationCount) )
  {
    m_nAllocationCount = this->m_Memory.m_nAllocationCount;
    result = (m_nAllocationCount > 0) - 1;
  }
  else
  {
    result = index + 1;
    if ( result < 0 || result >= m_nAllocationCount )
      result = -1;
  }
  if ( result < 0 || result >= m_nAllocationCount )
  {
    CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int>::Grow(
      (CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int> *)this,
      num: 1);
    this->m_pElements = this->m_Memory.m_pMemory;
    v7 = this->m_LastAlloc.index;
    if ( v7 < 0 || (v8 = this->m_Memory.m_nAllocationCount, v7 >= v8) )
    {
      v8 = this->m_Memory.m_nAllocationCount;
      result = (v8 > 0) - 1;
    }
    else
    {
      result = v7 + 1;
      if ( result < 0 || result >= v8 )
        result = -1;
    }
    if ( result < 0 || result >= v8 )
    {
      if ( `CUtlLinkedList<C_CSPlayer::CCSSoundEvent,int,0,int,CUtlMemory<UtlLinkedListElem_t<C_CSPlayer::CCSSoundEvent,int>,int>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<C_CSPlayer::CCSSoundEvent,int,0,int,CUtlMemory<UtlLinkedListElem_t<C_CSPlayer::CCSSoundEvent,int>,int>>::AllocInternal'::`12'::__executeCount;
        _Warning(a1: "CUtlLinkedList overflow! (exhausted memory allocator)\n");
      }
      return -1;
    }
  }
  ++this->m_NumAlloced;
  this->m_LastAlloc.index = result;
  goto LABEL_23;
}

//------------------------------------------------------------------------------
// Address: 0x101BB6F0
// Name: protected: int CUtlLinkedList<class CAddonModel,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<class CAddonModel,int>,int>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<CAddonModel,int,0,int,CUtlMemory<UtlLinkedListElem_t<CAddonModel,int>,int>>::AllocInternal(
        CUtlLinkedList<CAddonModel,int,0,int,CUtlMemory<UtlLinkedListElem_t<CAddonModel,int>,int> > *this,
        bool multilist)
{
  int result; // eax
  int index; // eax
  int m_nAllocationCount; // ecx
  int v6; // eax
  int v7; // ecx
  UtlLinkedListElem_t<CAddonModel,int> *v8; // ecx

  result = this->m_FirstFree;
  if ( result != -1 )
  {
    this->m_FirstFree = this->m_Memory.m_pMemory[result].m_Next;
LABEL_23:
    v8 = &this->m_Memory.m_pMemory[result];
    if ( multilist )
    {
      v8->m_Next = -1;
      v8->m_Previous = -1;
    }
    else
    {
      v8->m_Next = result;
      v8->m_Previous = result;
    }
    return result;
  }
  index = this->m_LastAlloc.index;
  if ( index < 0 || (m_nAllocationCount = this->m_Memory.m_nAllocationCount, index >= m_nAllocationCount) )
  {
    m_nAllocationCount = this->m_Memory.m_nAllocationCount;
    result = (m_nAllocationCount > 0) - 1;
  }
  else
  {
    result = index + 1;
    if ( result < 0 || result >= m_nAllocationCount )
      result = -1;
  }
  if ( result < 0 || result >= m_nAllocationCount )
  {
    CUtlMemory<CUtlVector<CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry,CUtlMemory<CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry,int>>,int>::Grow(
      (CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> *)this,
      num: 1);
    this->m_pElements = this->m_Memory.m_pMemory;
    v6 = this->m_LastAlloc.index;
    if ( v6 < 0 || (v7 = this->m_Memory.m_nAllocationCount, v6 >= v7) )
    {
      v7 = this->m_Memory.m_nAllocationCount;
      result = (v7 > 0) - 1;
    }
    else
    {
      result = v6 + 1;
      if ( result < 0 || result >= v7 )
        result = -1;
    }
    if ( result < 0 || result >= v7 )
    {
      if ( `CUtlLinkedList<CAddonModel,int,0,int,CUtlMemory<UtlLinkedListElem_t<CAddonModel,int>,int>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<CAddonModel,int,0,int,CUtlMemory<UtlLinkedListElem_t<CAddonModel,int>,int>>::AllocInternal'::`12'::__executeCount;
        _Warning(a1: "CUtlLinkedList overflow! (exhausted memory allocator)\n");
      }
      return -1;
    }
  }
  ++this->m_NumAlloced;
  this->m_LastAlloc.index = result;
  goto LABEL_23;
}

//------------------------------------------------------------------------------
// Address: 0x101BBE80
// Name: public: void CUtlLinkedList<class CAddonModel,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<class CAddonModel,int>,int>>::Unlink(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CAddonModel,int,0,int,CUtlMemory<UtlLinkedListElem_t<CAddonModel,int>,int>>::Unlink(
        CUtlLinkedList<CAddonModel,int,0,int,CUtlMemory<UtlLinkedListElem_t<CAddonModel,int>,int> > *this,
        int elem)
{
  UtlLinkedListElem_t<CAddonModel,int> *v2; // eax
  int m_Next; // edx
  int m_Previous; // edi
  int v5; // edx

  if ( elem >= 0 && elem < this->m_Memory.m_nAllocationCount && elem <= this->m_LastAlloc.index )
  {
    v2 = &this->m_Memory.m_pMemory[elem];
    if ( v2->m_Previous != elem )
    {
      m_Next = v2->m_Next;
      m_Previous = v2->m_Previous;
      if ( m_Previous == -1 )
        this->m_Head = m_Next;
      else
        this->m_Memory.m_pMemory[m_Previous].m_Next = m_Next;
      if ( m_Next == -1 )
      {
        v5 = v2->m_Previous;
        --this->m_ElementCount;
        this->m_Tail = v5;
      }
      else
      {
        this->m_Memory.m_pMemory[m_Next].m_Previous = v2->m_Previous;
        --this->m_ElementCount;
      }
      v2->m_Next = elem;
      v2->m_Previous = elem;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101BD870
// Name: public: int CUtlLinkedList<class C_CSPlayer::CCSSoundEvent,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<class C_CSPlayer::CCSSoundEvent,int>,int>>::AddToTail(class C_CSPlayer::CCSSoundEvent const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<C_CSPlayer::CCSSoundEvent,int,0,int,CUtlMemory<UtlLinkedListElem_t<C_CSPlayer::CCSSoundEvent,int>,int>>::AddToTail(
        CUtlLinkedList<C_CSPlayer::CCSSoundEvent,int,0,int,CUtlMemory<UtlLinkedListElem_t<C_CSPlayer::CCSSoundEvent,int>,int> > *this,
        const C_CSPlayer::CCSSoundEvent *src)
{
  int result; // eax
  int v4; // edi
  UtlLinkedListElem_t<C_CSPlayer::CCSSoundEvent,int> *m_pMemory; // eax
  unsigned int v6; // edx
  int m_Tail; // ecx
  UtlLinkedListElem_t<C_CSPlayer::CCSSoundEvent,int> *v8; // esi

  result = CUtlLinkedList<C_CSPlayer::CCSSoundEvent,int,0,int,CUtlMemory<UtlLinkedListElem_t<C_CSPlayer::CCSSoundEvent,int>,int>>::AllocInternal(
             this,
             multilist: false);
  v4 = result;
  if ( result != -1 )
  {
    CUtlLinkedList<C_CSPlayer::CCSSoundEvent,int,0,int,CUtlMemory<UtlLinkedListElem_t<C_CSPlayer::CCSSoundEvent,int>,int>>::Unlink(
      (CUtlLinkedList<vgui::PanelListPanel::dataitem_s,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int> > *)this,
      elem: result);
    m_pMemory = this->m_Memory.m_pMemory;
    v6 = v4;
    m_pMemory[v6].m_Next = -1;
    m_Tail = this->m_Tail;
    m_pMemory[v6].m_Previous = m_Tail;
    this->m_Tail = v4;
    if ( m_Tail == -1 )
      this->m_Head = v4;
    else
      this->m_Memory.m_pMemory[m_Tail].m_Next = v4;
    ++this->m_ElementCount;
    v8 = &this->m_Memory.m_pMemory[v6];
    if ( v8 != nullptr )
      v8->m_Element = *src;
    return v4;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101BD8E0
// Name: public: int CUtlLinkedList<class CAddonModel,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<class CAddonModel,int>,int>>::AddToTail(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<CAddonModel,int,0,int,CUtlMemory<UtlLinkedListElem_t<CAddonModel,int>,int>>::AddToTail(
        CUtlLinkedList<CAddonModel,int,0,int,CUtlMemory<UtlLinkedListElem_t<CAddonModel,int>,int> > *this)
{
  int result; // eax
  int v3; // edi
  UtlLinkedListElem_t<CAddonModel,int> *m_pMemory; // eax
  unsigned int v5; // ecx
  int m_Tail; // edx
  UtlLinkedListElem_t<CAddonModel,int> *v7; // esi

  result = CUtlLinkedList<CAddonModel,int,0,int,CUtlMemory<UtlLinkedListElem_t<CAddonModel,int>,int>>::AllocInternal(
             this,
             multilist: false);
  v3 = result;
  if ( result != -1 )
  {
    CUtlLinkedList<CAddonModel,int,0,int,CUtlMemory<UtlLinkedListElem_t<CAddonModel,int>,int>>::Unlink(
      this,
      elem: result);
    m_pMemory = this->m_Memory.m_pMemory;
    v5 = v3;
    m_pMemory[v5].m_Next = -1;
    m_Tail = this->m_Tail;
    m_pMemory[v5].m_Previous = m_Tail;
    this->m_Tail = v3;
    if ( m_Tail == -1 )
      this->m_Head = v3;
    else
      this->m_Memory.m_pMemory[m_Tail].m_Next = v3;
    ++this->m_ElementCount;
    v7 = &this->m_Memory.m_pMemory[v5];
    if ( v7 != nullptr )
      v7->m_Element.m_hEnt.m_Index = -1;
    return v3;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102406A0
// Name: public: void CUtlLinkedList<class CPrecipitationParticle,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<class CPrecipitationParticle,unsigned short>,unsigned short>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CPrecipitationParticle,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CPrecipitationParticle,unsigned short>,unsigned short>>::RemoveAll(
        CUtlLinkedList<CPrecipitationParticle,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CPrecipitationParticle,unsigned short>,unsigned short> > *this)
{
  unsigned __int16 m_Head; // si
  UtlLinkedListElem_t<CPrecipitationParticle,unsigned short> *v2; // edx
  unsigned __int16 m_Next; // ax
  unsigned __int16 m_FirstFree; // si
  unsigned __int16 v5; // ax

  if ( this->m_LastAlloc.index != 0xFFFF )
  {
    m_Head = this->m_Head;
    if ( m_Head != 0xFFFF )
    {
      do
      {
        v2 = &this->m_Memory.m_pMemory[m_Head];
        m_Next = v2->m_Next;
        v2->m_Previous = m_Head;
        if ( m_Next == 0xFFFF )
          m_FirstFree = this->m_FirstFree;
        else
          m_FirstFree = m_Next;
        v2->m_Next = m_FirstFree;
        m_Head = m_Next;
      }
      while ( m_Next != 0xFFFF );
    }
    v5 = this->m_Head;
    if ( v5 != 0xFFFF )
      this->m_FirstFree = v5;
    *(_DWORD *)&this->m_Head = -1;
    this->m_ElementCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10240710
// Name: protected: unsigned short CUtlLinkedList<class CPrecipitationParticle,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<class CPrecipitationParticle,unsigned short>,unsigned short>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<CPrecipitationParticle,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CPrecipitationParticle,unsigned short>,unsigned short>>::AllocInternal(
        CUtlLinkedList<CPrecipitationParticle,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CPrecipitationParticle,unsigned short>,unsigned short> > *this,
        bool multilist)
{
  int m_FirstFree; // ecx
  int m_nAllocationCount; // ecx
  unsigned __int16 index; // ax
  int result; // eax
  int v7; // ecx
  unsigned __int16 v8; // ax
  UtlLinkedListElem_t<CPrecipitationParticle,unsigned short> *m_pMemory; // edx
  int v10; // ecx
  UtlLinkedListElem_t<CPrecipitationParticle,unsigned short> *v11; // ecx

  m_FirstFree = this->m_FirstFree;
  if ( (_WORD)m_FirstFree != 0xFFFF )
  {
    result = m_FirstFree;
    this->m_FirstFree = this->m_Memory.m_pMemory[m_FirstFree].m_Next;
LABEL_22:
    if ( multilist )
    {
      v11 = &this->m_Memory.m_pMemory[(unsigned __int16)result];
      v11->m_Next = -1;
      v11->m_Previous = -1;
    }
    else
    {
      m_pMemory = this->m_Memory.m_pMemory;
      v10 = (unsigned __int16)result;
      m_pMemory[v10].m_Next = result;
      m_pMemory[v10].m_Previous = result;
    }
    return result;
  }
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( this->m_LastAlloc.index >= m_nAllocationCount )
  {
    m_nAllocationCount = this->m_Memory.m_nAllocationCount;
    LOWORD(result) = (m_nAllocationCount > 0) - 1;
  }
  else
  {
    index = this->m_LastAlloc.index;
    if ( (unsigned __int16)(index + 1) >= m_nAllocationCount )
      LOWORD(result) = -1;
    else
      LOWORD(result) = index + 1;
  }
  if ( (unsigned __int16)result >= m_nAllocationCount )
  {
    CUtlMemory<UtlLinkedListElem_t<CPrecipitationParticle,unsigned short>,unsigned short>::Grow(
      this: &this->m_Memory,
      num: 1);
    this->m_pElements = this->m_Memory.m_pMemory;
    v7 = this->m_Memory.m_nAllocationCount;
    if ( this->m_LastAlloc.index >= v7 )
    {
      v7 = this->m_Memory.m_nAllocationCount;
      LOWORD(result) = (v7 > 0) - 1;
    }
    else
    {
      v8 = this->m_LastAlloc.index;
      LOWORD(result) = (unsigned __int16)(v8 + 1) >= v7 ? -1 : v8 + 1;
    }
    if ( (unsigned __int16)result >= v7 )
    {
      if ( `CUtlLinkedList<CPrecipitationParticle,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CPrecipitationParticle,unsigned short>,unsigned short>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<CPrecipitationParticle,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CPrecipitationParticle,unsigned short>,unsigned short>>::AllocInternal'::`12'::__executeCount;
        _Warning(a1: "CUtlLinkedList overflow! (exhausted memory allocator)\n");
      }
      return 0xFFFF;
    }
  }
  if ( (_WORD)result != 0xFFFF )
  {
    ++this->m_NumAlloced;
    this->m_LastAlloc.index = result;
    result = (unsigned __int16)result;
    goto LABEL_22;
  }
  if ( `CUtlLinkedList<CPrecipitationParticle,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CPrecipitationParticle,unsigned short>,unsigned short>>::AllocInternal'::`19'::__executeCount >= 10 )
    return 0xFFFF;
  ++`CUtlLinkedList<CPrecipitationParticle,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CPrecipitationParticle,unsigned short>,unsigned short>>::AllocInternal'::`19'::__executeCount;
  _Warning(a1: "CUtlLinkedList overflow! (exhausted index range)\n");
  return 0xFFFF;
}

//------------------------------------------------------------------------------
// Address: 0x10241240
// Name: public: void CUtlLinkedList<class CPrecipitationParticle,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<class CPrecipitationParticle,unsigned short>,unsigned short>>::Unlink(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CPrecipitationParticle,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CPrecipitationParticle,unsigned short>,unsigned short>>::Unlink(
        CUtlLinkedList<CPrecipitationParticle,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CPrecipitationParticle,unsigned short>,unsigned short> > *this,
        unsigned __int16 elem)
{
  unsigned __int16 v2; // di
  UtlLinkedListElem_t<CPrecipitationParticle,unsigned short> *v3; // eax
  int m_Previous; // ebx
  unsigned __int16 m_Next; // dx

  v2 = elem;
  if ( elem < this->m_Memory.m_nAllocationCount && elem <= this->m_LastAlloc.index )
  {
    v3 = &this->m_Memory.m_pMemory[elem];
    if ( v3->m_Previous != elem )
    {
      m_Previous = v3->m_Previous;
      m_Next = v3->m_Next;
      if ( (_WORD)m_Previous == 0xFFFF )
      {
        this->m_Head = m_Next;
      }
      else
      {
        this->m_Memory.m_pMemory[m_Previous].m_Next = m_Next;
        v2 = elem;
      }
      if ( m_Next == 0xFFFF )
        this->m_Tail = m_Previous;
      else
        this->m_Memory.m_pMemory[m_Next].m_Previous = m_Previous;
      v3->m_Next = v2;
      v3->m_Previous = v2;
      --this->m_ElementCount;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10241460
// Name: public: void CUtlLinkedList<class CPrecipitationParticle,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<class CPrecipitationParticle,unsigned short>,unsigned short>>::LinkBefore(unsigned short,unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CPrecipitationParticle,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CPrecipitationParticle,unsigned short>,unsigned short>>::LinkBefore(
        CUtlLinkedList<CPrecipitationParticle,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CPrecipitationParticle,unsigned short>,unsigned short> > *this,
        unsigned __int16 before,
        unsigned __int16 elem)
{
  UtlLinkedListElem_t<CPrecipitationParticle,unsigned short> *m_pMemory; // ebx
  unsigned __int16 m_Tail; // dx

  CUtlLinkedList<CPrecipitationParticle,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CPrecipitationParticle,unsigned short>,unsigned short>>::Unlink(
    this,
    elem);
  m_pMemory = this->m_Memory.m_pMemory;
  this->m_Memory.m_pMemory[elem].m_Next = before;
  if ( before == 0xFFFF )
  {
    m_Tail = this->m_Tail;
    m_pMemory[elem].m_Previous = m_Tail;
    this->m_Tail = elem;
  }
  else
  {
    m_Tail = m_pMemory[before].m_Previous;
    m_pMemory[elem].m_Previous = m_Tail;
    m_pMemory[before].m_Previous = elem;
  }
  if ( m_Tail == 0xFFFF )
  {
    ++this->m_ElementCount;
    this->m_Head = elem;
  }
  else
  {
    m_pMemory[m_Tail].m_Next = elem;
    ++this->m_ElementCount;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10241D30
// Name: public: void CUtlLinkedList<class CPrecipitationParticle,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<class CPrecipitationParticle,unsigned short>,unsigned short>>::Remove(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CPrecipitationParticle,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CPrecipitationParticle,unsigned short>,unsigned short>>::Remove(
        CUtlLinkedList<CPrecipitationParticle,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CPrecipitationParticle,unsigned short>,unsigned short> > *this,
        unsigned __int16 elem)
{
  CUtlLinkedList<CPrecipitationParticle,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CPrecipitationParticle,unsigned short>,unsigned short>>::Unlink(
    this,
    elem);
  this->m_Memory.m_pMemory[elem].m_Next = this->m_FirstFree;
  this->m_FirstFree = elem;
}

//------------------------------------------------------------------------------
// Address: 0x1025B9B0
// Name: public: virtual void PrecacheEffectMuzzleFlashPrecache::CResourcePrecacher::Cache(class IPrecacheHandler __near *,bool,struct ResourceList_t__ __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall PrecacheEffectMuzzleFlashPrecache::CResourcePrecacher::Cache(
        PrecacheEffectMuzzleFlashPrecache::CResourcePrecacher *this,
        IPrecacheHandler *pPrecacheHandler,
        BOOL bPrecache,
        struct ResourceList_t__ *hResourceList,
        bool bIgnoreConditionals)
{
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: MATERIAL,
    a3: "effects/muzzleflash1",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: MATERIAL,
    a3: "effects/muzzleflash2",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: MATERIAL,
    a3: "effects/muzzleflash3",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: MATERIAL,
    a3: "effects/muzzleflash4",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: MATERIAL,
    a3: "effects/muzzleflash1_noz",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: MATERIAL,
    a3: "effects/muzzleflash2_noz",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: MATERIAL,
    a3: "effects/muzzleflash3_noz",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: MATERIAL,
    a3: "effects/muzzleflash4_noz",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x1025BA60
// Name: public: virtual void CTempEnts::LevelInit(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTempEnts::LevelInit(CTempEnts *this)
{
  this->m_pSpriteMuzzleFlash[0] = engine->LoadModel(this: engine, a2: "sprites/ar2_muzzle1.vmt", a3: 0);
  this->m_pSpriteMuzzleFlash[1] = engine->LoadModel(this: engine, a2: "sprites/muzzleflash4.vmt", a3: 0);
  this->m_pSpriteMuzzleFlash[2] = engine->LoadModel(this: engine, a2: "sprites/muzzleflash4.vmt", a3: 0);
  this->m_pSpriteAR2Flash[0] = engine->LoadModel(this: engine, a2: "sprites/ar2_muzzle1b.vmt", a3: 0);
  this->m_pSpriteAR2Flash[1] = engine->LoadModel(this: engine, a2: "sprites/ar2_muzzle2b.vmt", a3: 0);
  this->m_pSpriteAR2Flash[2] = engine->LoadModel(this: engine, a2: "sprites/ar2_muzzle3b.vmt", a3: 0);
  this->m_pSpriteAR2Flash[3] = engine->LoadModel(this: engine, a2: "sprites/ar2_muzzle4b.vmt", a3: 0);
  this->m_pSpriteCombineFlash[0] = engine->LoadModel(this: engine, a2: "effects/combinemuzzle1.vmt", a3: 0);
  this->m_pSpriteCombineFlash[1] = engine->LoadModel(this: engine, a2: "effects/combinemuzzle2.vmt", a3: 0);
  this->m_pShells[0] = engine->LoadModel(this: engine, a2: "models/weapons/shell.mdl", a3: 0);
  this->m_pShells[1] = engine->LoadModel(this: engine, a2: "models/weapons/rifleshell.mdl", a3: 0);
  this->m_pShells[2] = engine->LoadModel(this: engine, a2: "models/weapons/shotgun_shell.mdl", a3: 0);
  this->m_pCS_9MMShell = engine->LoadModel(this: engine, a2: "models/Shells/shell_9mm.mdl", a3: 0);
  this->m_pCS_57Shell = engine->LoadModel(this: engine, a2: "models/Shells/shell_57.mdl", a3: 0);
  this->m_pCS_12GaugeShell = engine->LoadModel(this: engine, a2: "models/Shells/shell_12gauge.mdl", a3: 0);
  this->m_pCS_556Shell = engine->LoadModel(this: engine, a2: "models/Shells/shell_556.mdl", a3: 0);
  this->m_pCS_762NATOShell = engine->LoadModel(this: engine, a2: "models/Shells/shell_762nato.mdl", a3: 0);
  this->m_pCS_338MAGShell = engine->LoadModel(this: engine, a2: "models/Shells/shell_338mag.mdl", a3: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1025BC30
// Name: public: virtual void CTempEnts::Init(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTempEnts::Init(CTempEnts *this)
{
  this->m_pSpriteMuzzleFlash[0] = nullptr;
  this->m_pSpriteMuzzleFlash[1] = nullptr;
  this->m_pSpriteMuzzleFlash[2] = nullptr;
  this->m_pSpriteAR2Flash[0] = nullptr;
  this->m_pSpriteAR2Flash[1] = nullptr;
  this->m_pSpriteAR2Flash[2] = nullptr;
  this->m_pSpriteAR2Flash[3] = nullptr;
  this->m_pSpriteCombineFlash[0] = nullptr;
  this->m_pSpriteCombineFlash[1] = nullptr;
  this->m_pShells[0] = nullptr;
  this->m_pShells[1] = nullptr;
  this->m_pShells[2] = nullptr;
  this->m_pCS_9MMShell = nullptr;
  this->m_pCS_57Shell = nullptr;
  this->m_pCS_12GaugeShell = nullptr;
  this->m_pCS_556Shell = nullptr;
  this->m_pCS_762NATOShell = nullptr;
  this->m_pCS_338MAGShell = nullptr;
  this->Clear(this);
}

//------------------------------------------------------------------------------
// Address: 0x1025BCA0
// Name: public: virtual void CTempEnts::LevelShutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTempEnts::LevelShutdown(CTempEnts *this)
{
  this->Clear(this);
}

//------------------------------------------------------------------------------
// Address: 0x1025BCB0
// Name: private: void CTempEnts::CacheMuzzleFlashes(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTempEnts::CacheMuzzleFlashes(CTempEnts *this)
{
  int v2; // esi
  CParticleSubTexture **m_Material_MuzzleFlash_Player; // edi
  CParticleMgr *v4; // eax
  int v5; // esi
  CParticleSubTexture **m_Material_MuzzleFlash_NPC; // edi
  CParticleMgr *v7; // eax
  int v8; // esi
  CParticleSubTexture **m_Material_Combine_MuzzleFlash_Player; // edi
  CParticleMgr *v10; // eax
  int v11; // esi
  CParticleSubTexture **m_Material_Combine_MuzzleFlash_NPC; // edi
  CParticleMgr *v13; // eax
  const char *v14; // [esp-4h] [ebp-10h]
  const char *v15; // [esp-4h] [ebp-10h]
  const char *v16; // [esp-4h] [ebp-10h]
  const char *v17; // [esp-4h] [ebp-10h]

  v2 = 0;
  m_Material_MuzzleFlash_Player = this->m_Material_MuzzleFlash_Player;
  do
  {
    if ( *m_Material_MuzzleFlash_Player == nullptr )
    {
      v14 = VarArgs(format: "effects/muzzleflash%d_noz", v2 + 1);
      v4 = ParticleMgr();
      *m_Material_MuzzleFlash_Player = CParticleMgr::GetPMaterial(this: v4, pMaterialName: v14);
    }
    ++v2;
    ++m_Material_MuzzleFlash_Player;
  }
  while ( v2 < 4 );
  v5 = 0;
  m_Material_MuzzleFlash_NPC = this->m_Material_MuzzleFlash_NPC;
  do
  {
    if ( *m_Material_MuzzleFlash_NPC == nullptr )
    {
      v15 = VarArgs(format: "effects/muzzleflash%d", v5 + 1);
      v7 = ParticleMgr();
      *m_Material_MuzzleFlash_NPC = CParticleMgr::GetPMaterial(this: v7, pMaterialName: v15);
    }
    ++v5;
    ++m_Material_MuzzleFlash_NPC;
  }
  while ( v5 < 4 );
  v8 = 0;
  m_Material_Combine_MuzzleFlash_Player = this->m_Material_Combine_MuzzleFlash_Player;
  do
  {
    if ( *m_Material_Combine_MuzzleFlash_Player == nullptr )
    {
      v16 = VarArgs(format: "effects/combinemuzzle%d_noz", v8 + 1);
      v10 = ParticleMgr();
      *m_Material_Combine_MuzzleFlash_Player = CParticleMgr::GetPMaterial(this: v10, pMaterialName: v16);
    }
    ++v8;
    ++m_Material_Combine_MuzzleFlash_Player;
  }
  while ( v8 < 2 );
  v11 = 0;
  m_Material_Combine_MuzzleFlash_NPC = this->m_Material_Combine_MuzzleFlash_NPC;
  do
  {
    if ( *m_Material_Combine_MuzzleFlash_NPC == nullptr )
    {
      v17 = VarArgs(format: "effects/combinemuzzle%d", v11 + 1);
      v13 = ParticleMgr();
      *m_Material_Combine_MuzzleFlash_NPC = CParticleMgr::GetPMaterial(this: v13, pMaterialName: v17);
    }
    ++v11;
    ++m_Material_Combine_MuzzleFlash_NPC;
  }
  while ( v11 < 2 );
}

//------------------------------------------------------------------------------
// Address: 0x1025BDA0
// Name: public: C_LocalTempEntity::C_LocalTempEntity(void)
// Source: json
//------------------------------------------------------------------------------
C_LocalTempEntity *__thiscall C_LocalTempEntity::C_LocalTempEntity(C_LocalTempEntity *this)
{
  C_BaseAnimating::C_BaseAnimating(this);
  this->C_SpriteRenderer::__vftable = (C_SpriteRenderer_vtbl *)&C_SpriteRenderer::`vftable';
  this->C_BaseAnimating::C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable = (C_LocalTempEntity_vtbl *)&C_LocalTempEntity::`vftable'{for `IClientUnknown'};
  this->C_BaseAnimating::C_BaseEntity::IClientEntity::IClientRenderable::__vftable = (IClientRenderable_vtbl *)&C_LocalTempEntity::`vftable'{for `IClientRenderable'};
  this->C_BaseAnimating::C_BaseEntity::IClientEntity::IClientNetworkable::__vftable = (IClientNetworkable_vtbl *)&C_LocalTempEntity::`vftable'{for `IClientNetworkable'};
  this->C_BaseAnimating::C_BaseEntity::IClientEntity::IClientThinkable::__vftable = (IClientThinkable_vtbl *)&C_LocalTempEntity::`vftable'{for `IClientThinkable'};
  this->C_BaseAnimating::C_BaseEntity::IClientModelRenderable::__vftable = (IClientModelRenderable_vtbl *)&C_LocalTempEntity::`vftable'{for `C_BaseAnimating'};
  this->C_SpriteRenderer::__vftable = (C_SpriteRenderer_vtbl *)&C_LocalTempEntity::`vftable'{for `C_SpriteRenderer'};
  this->m_vecTempEntAcceleration.x = 0.0;
  this->m_vecTempEntAcceleration.y = 0.0;
  this->m_vecTempEntAcceleration.z = 0.0;
  this->m_pfnDrawHelper = nullptr;
  this->m_pszImpactEffect = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1025BE10
// Name: public: virtual void C_LocalTempEntity::Prepare(struct model_t __near *,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_LocalTempEntity::Prepare(C_LocalTempEntity *this, struct model_t *pmodel, float time)
{
  void (__thiscall *Clear)(C_BaseEntity *); // eax

  C_BaseEntity::Interp_SetupMappings(this, map: &this->m_VarMap);
  Clear = this->Clear;
  this->index = -1;
  Clear(this);
  this->flags = 0;
  this->die = time + 0.75;
  C_BaseEntity::SetModelPointer(this, pModel: pmodel);
  C_BaseEntity::SetRenderMode(this, nRenderMode: kRenderNormal, bForceUpdate: false);
  C_BaseEntity::SetRenderFX(this, nRenderFX: kRenderFxNone, flStartTime: 3.4028235e38, flDuration: 0.0);
  C_BaseAnimating::SetBody(this, iBody: 0);
  C_BaseAnimating::SetSkin(this, iSkin: 0);
  this->fadeSpeed = 0.5;
  this->hitSound = 0;
  this->m_nFlickerFrame = 0;
  this->m_bParticleCollision = false;
  this->clientIndex = -1;
  this->bounceFactor = 1.0;
}

//------------------------------------------------------------------------------
// Address: 0x1025BEF0
// Name: private: int C_LocalTempEntity::DrawStudioModel(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall C_LocalTempEntity::DrawStudioModel(C_LocalTempEntity *this, int flags)
{
  IClientRenderable *v3; // edi
  IVModelInfoClient_vtbl *v4; // ebx
  int v5; // eax
  IMDLCache *v6; // ebx
  CStudioHdr *m_pStudioHdr; // eax
  int (__cdecl *m_pfnDrawHelper)(C_LocalTempEntity *, int); // eax
  int v10; // eax
  IVModelRender_vtbl *v11; // ebx
  int v12; // eax
  int v13; // eax
  int v14; // eax
  int v15; // eax
  int v16; // eax
  int v17; // esi
  IMDLCache *cacheCriticalSection; // [esp+Ch] [ebp-4h]

  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "C_LocalTempEntity::DrawStudioModel",
    a3: 0,
    a4: "Other_Model_Rendering",
    a5: false,
    a6: 4);
  v3 = &this->IClientRenderable;
  if ( this->GetModel(this: &this->IClientRenderable) == nullptr )
    goto LABEL_9;
  v4 = modelinfo->__vftable;
  v5 = (int)v3->GetModel(this: &this->IClientRenderable);
  if ( v4->GetModelType(this: modelinfo, a2: (const struct model_t *)v5) != 3 )
    goto LABEL_9;
  v6 = mdlcache;
  cacheCriticalSection = mdlcache;
  mdlcache->BeginLock(this: mdlcache);
  if ( this->m_pStudioHdr == nullptr && v3->GetModel(this: &this->IClientRenderable) != nullptr )
    C_BaseAnimating::LockStudioHdr(this);
  m_pStudioHdr = this->m_pStudioHdr;
  if ( m_pStudioHdr == nullptr || m_pStudioHdr->m_pStudioHdr == nullptr )
  {
    v6->EndLock(this: v6);
LABEL_9:
    CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
    return 0;
  }
  m_pfnDrawHelper = this->m_pfnDrawHelper;
  if ( m_pfnDrawHelper != nullptr )
  {
    v10 = m_pfnDrawHelper(a1: this, a2: flags);
  }
  else
  {
    v11 = modelrender->__vftable;
    v12 = ((int (__thiscall *)(IClientRenderable *, int, _DWORD, _DWORD))v3->GetBody)(
            a1: &this->IClientRenderable,
            a2: this->m_nHitboxSet,
            a3: 0,
            a4: 0);
    v13 = ((int (__thiscall *)(IClientRenderable *, int))v3->GetSkin)(a1: &this->IClientRenderable, a2: v12);
    v14 = ((int (__thiscall *)(C_LocalTempEntity *, int))this->GetAbsAngles)(a1: this, a2: v13);
    v15 = ((int (__thiscall *)(C_LocalTempEntity *, int))this->GetAbsOrigin)(a1: this, a2: v14);
    v16 = ((int (__thiscall *)(IClientRenderable *, int))v3->GetModel)(a1: &this->IClientRenderable, a2: v15);
    v10 = ((int (__thiscall *)(IVModelRender *, int, IClientRenderable *, int, int, int))v11->DrawModel)(
            a1: modelrender,
            a2: flags,
            a3: &this->IClientRenderable,
            a4: 0xFFFF,
            a5: this->index,
            a6: v16);
    v6 = cacheCriticalSection;
  }
  v17 = v10;
  v6->EndLock(this: v6);
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
  return v17;
}

//------------------------------------------------------------------------------
// Address: 0x1025C040
// Name: public: virtual bool C_LocalTempEntity::IsActive(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall C_LocalTempEntity::IsActive(C_LocalTempEntity *this)
{
  float v2; // xmm0_4
  char v3; // bl
  int v4; // eax

  v2 = this->die - *(float *)(gpGlobals.m_Index + 12);
  v3 = 1;
  if ( v2 < 0.0 )
  {
    if ( SLOBYTE(this->flags) >= 0 )
    {
      v3 = 0;
    }
    else
    {
      if ( this->m_nRenderMode == 0 )
        C_BaseEntity::SetRenderMode(this, nRenderMode: kRenderTransTexture, bForceUpdate: false);
      v4 = (int)(float)((float)((float)(this->fadeSpeed * v2) + 1.0) * (float)this->tempent_renderamt);
      if ( v4 <= 0 )
      {
        v3 = 0;
        v4 = 0;
      }
      C_BaseEntity::SetRenderAlpha(this, a: v4);
    }
  }
  if ( (this->flags & 0x400000) != 0 )
    return this->die != 0.0;
  else
    return v3;
}

//------------------------------------------------------------------------------
// Address: 0x1025C100
// Name: private: int CTempEnts::AddVisibleTempEntity(class C_LocalTempEntity __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CTempEnts::AddVisibleTempEntity(CTempEnts *this, C_LocalTempEntity *pEntity)
{
  int result; // eax
  IVModelInfoClient_vtbl *v3; // esi
  int v4; // eax
  int i; // esi
  Vector model_maxs; // [esp+20h] [ebp-18h] BYREF
  Vector model_mins; // [esp+2Ch] [ebp-Ch] BYREF

  result = (int)pEntity->GetModel(this: &pEntity->IClientRenderable);
  if ( result != 0 )
  {
    v3 = modelinfo->__vftable;
    v4 = ((int (__thiscall *)(IClientRenderable *, Vector *, Vector *))pEntity->GetModel)(
           a1: &pEntity->IClientRenderable,
           a2: &model_mins,
           a3: &model_maxs);
    ((void (__thiscall *)(IVModelInfoClient *, int))v3->GetModelBounds)(a1: modelinfo, a2: v4);
    for ( i = 0; i < 12; i += 4 )
    {
      pEntity->GetAbsOrigin(this: pEntity);
      pEntity->GetAbsOrigin(this: pEntity);
    }
    pEntity->index = -1;
    C_BaseEntity::AddToLeafSystem(this: pEntity, bRenderWithViewModels: false);
    return 1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1025C190
// Name: private: void CTempEnts::MuzzleFlash_SMG1_NPC(class CBaseHandle,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTempEnts::MuzzleFlash_SMG1_NPC(CTempEnts *this, CBaseHandle hEntity, int attachmentIndex)
{
  FX_MuzzleEffectAttached(scale: 1.0, hEntity, attachmentIndex, pFlashColor: nullptr, bOneFrame: true);
}

//------------------------------------------------------------------------------
// Address: 0x1025C1C0
// Name: private: void CTempEnts::MuzzleFlash_Pistol_NPC(class CBaseHandle,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTempEnts::MuzzleFlash_Pistol_NPC(CTempEnts *this, CBaseHandle hEntity, int attachmentIndex)
{
  FX_MuzzleEffectAttached(scale: 0.5, hEntity, attachmentIndex, pFlashColor: nullptr, bOneFrame: true);
}

//------------------------------------------------------------------------------
// Address: 0x1025C1F0
// Name: private: void CTempEnts::MuzzleFlash_RPG_NPC(class CBaseHandle,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTempEnts::MuzzleFlash_RPG_NPC(CTempEnts *this, CBaseHandle hEntity, int attachmentIndex)
{
  FX_MuzzleEffectAttached(scale: 1.5, hEntity, attachmentIndex, pFlashColor: nullptr, bOneFrame: false);
}

//------------------------------------------------------------------------------
// Address: 0x1025C290
// Name: public: virtual int C_LocalTempEntity::DrawModel(int,struct RenderableInstance_t const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall C_LocalTempEntity::DrawModel(C_LocalTempEntity *this, int flags, const RenderableInstance_t *instance)
{
  IClientThinkable *(__thiscall *GetClientThinkable)(IClientUnknown *); // edx
  int result; // eax
  const Vector *v6; // edi
  float *v7; // eax
  float v8; // xmm0_4
  double v9; // xmm0_8
  float v10; // xmm0_4
  double v11; // xmm0_8
  IVModelInfoClient_vtbl *v12; // edi
  IClientThinkable *v13; // eax
  int v14; // eax
  const Vector *v15; // eax
  int model_low; // edx
  int v17; // ebx
  const struct model_t *v18; // eax
  const Vector *v19; // [esp-4h] [ebp-50h]
  const QAngle *v20; // [esp+0h] [ebp-4Ch]
  float frame; // [esp+4h] [ebp-48h]
  int v22; // [esp+Ch] [ebp-40h]
  RenderMode_t v23; // [esp+10h] [ebp-3Ch]
  int RenderAlpha; // [esp+18h] [ebp-34h]
  int v25; // [esp+1Ch] [ebp-30h]
  int v26; // [esp+20h] [ebp-2Ch]
  int v27; // [esp+24h] [ebp-28h]
  float scale; // [esp+28h] [ebp-24h]
  Vector vecDelta; // [esp+3Ch] [ebp-10h] BYREF
  int drawn; // [esp+48h] [ebp-4h]
  C_BaseEntity *flagsa; // [esp+54h] [ebp+8h]

  GetClientThinkable = this->GetClientThinkable;
  drawn = 0;
  result = (int)GetClientThinkable(this);
  if ( result != 0 )
  {
    if ( ((int)this->m_pfnDrawHelper & 0x800000) != 0 )
    {
      v6 = MainViewOrigin(nSlot: 0);
      v7 = (float *)(*(int (__thiscall **)(char *))(*((_DWORD *)this - 1) + 40))(a1: (char *)this - 4);
      vecDelta.x = *v7 - v6->x;
      vecDelta.y = v7[1] - v6->y;
      vecDelta.z = v7[2] - v6->z;
      VectorNormalize(vec: &vecDelta);
      v8 = (float)((float)(this->m_vecNormal.x * vecDelta.y) + (float)(*(float *)&this->tempent_renderamt * vecDelta.x))
         + (float)(this->m_vecNormal.y * vecDelta.z);
      if ( v8 > 0.0 )
      {
        if ( v8 >= 0.3 )
          v9 = 0.3;
        else
          v9 = v8;
        v10 = v9;
        if ( (float)((float)SLODWORD(this->m_vecTempEntAngVelocity.z)
                   - (float)((float)SLODWORD(this->m_vecTempEntAngVelocity.z) * (float)(v10 * 3.3333333))) >= 1.0 )
          v11 = (float)((float)SLODWORD(this->m_vecTempEntAngVelocity.z)
                      - (float)((float)SLODWORD(this->m_vecTempEntAngVelocity.z) * (float)(v10 * 3.3333333)));
        else
          v11 = 1.0;
        C_BaseEntity::SetRenderAlpha(this: (C_LocalTempEntity *)((char *)this - 4), a: (unsigned __int8)(int)v11);
      }
    }
    v12 = modelinfo->__vftable;
    v13 = this->GetClientThinkable(this);
    v14 = v12->GetModelType(this: modelinfo, a2: (const struct model_t *)v13) - 2;
    if ( v14 != 0 )
    {
      if ( v14 == 1 )
      {
        result = C_LocalTempEntity::DrawStudioModel(this: (C_LocalTempEntity *)((char *)this - 4), flags);
        drawn = result;
        return result;
      }
    }
    else
    {
      if ( (int)this->GetAbsOrigin(this) <= 0 )
      {
        flagsa = nullptr;
      }
      else
      {
        v15 = this->GetAbsOrigin(this);
        flagsa = CClientEntityList::GetBaseEntity(this: (CClientEntityList *)cl_entitylist.m_Index, entnum: (int)v15);
      }
      model_low = LOBYTE(this->model);
      v17 = (unsigned __int8)this->m_iName[258];
      scale = this->m_vecNormal.z;
      v27 = BYTE2(this->model);
      v26 = BYTE1(this->model);
      drawn = (unsigned __int8)this->m_iName[259];
      v25 = model_low;
      RenderAlpha = C_BaseEntity::GetRenderAlpha(this: (C_LocalTempEntity *)((char *)this - 4));
      v23 = drawn;
      v22 = ((int (__thiscall *)(C_LocalTempEntity *))this->KeyValue)(a1: this);
      frame = this->m_flFrameRate;
      v20 = (const QAngle *)(*(int (__thiscall **)(char *))(*((_DWORD *)this - 1) + 44))(a1: (char *)this - 4);
      v19 = (const Vector *)(*(int (__thiscall **)(char *))(*((_DWORD *)this - 1) + 40))(a1: (char *)this - 4);
      v18 = (const struct model_t *)this->GetClientThinkable(this);
      return C_SpriteRenderer::DrawSprite(
               this: (C_SpriteRenderer *)(&this->m_vecRenderOriginOverride + 1),
               a2: v17,
               entity: (C_LocalTempEntity *)((char *)this - 4),
               model: v18,
               origin: v19,
               angles: v20,
               frame,
               attachedto: flagsa,
               attachmentindex: v22,
               rendermode: v23,
               renderfx: v17,
               alpha: RenderAlpha,
               r: v25,
               g: v26,
               b: v27,
               scale,
               flHDRColorScale: 1.0);
    }
    return drawn;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1025C4F0
// Name: public: virtual bool C_LocalTempEntity::Frame(float,int)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
char __userpurge C_LocalTempEntity::Frame@<al>(
        C_LocalTempEntity *this@<ecx>,
        IHandleEntity_vtbl *a2@<ebp>,
        float frametime,
        int framenumber)
{
  Vector *p_m_vecTempEntVelocity; // edi
  float v6; // xmm1_4
  float v7; // xmm2_4
  int flags; // eax
  int v9; // eax
  float *v10; // eax
  float v11; // xmm0_4
  float m_flSpriteScale; // xmm1_4
  float v13; // xmm0_4
  float z; // xmm0_4
  __m128 v15; // xmm1
  double v16; // xmm0_8
  __m128 v17; // xmm0
  __m128i v18; // xmm0
  double v19; // xmm0_8
  double LocalOriginDim; // st7
  double v21; // st6
  unsigned int v22; // xmm0_4
  __m128 v23; // xmm0
  double v24; // xmm0_8
  __m128 z_low; // xmm0
  double v26; // xmm0_8
  const Vector *LocalOrigin; // eax
  float v28; // xmm0_4
  int v29; // eax
  float v30; // xmm0_4
  bool v31; // cf
  float v33; // xmm0_4
  const QAngle *LocalAngles; // eax
  __int128 v35; // xmm0
  unsigned int m_Index; // eax
  __int64 v37; // xmm0_8
  int m_nValue; // ecx
  int v39; // edx
  int m_CollisionGroup; // ecx
  const Vector *v41; // eax
  C_BaseEntity *BaseEntity; // eax
  const Vector *v43; // eax
  int v44; // eax
  float bounceFactor; // xmm0_4
  float v46; // xmm1_4
  int clientIndex; // edx
  int v48; // eax
  void *v49; // eax
  void *v50; // eax
  int v51; // edx
  int v52; // eax
  int v53; // eax
  float v54; // ecx
  float y; // xmm1_4
  float v56; // xmm3_4
  float v57; // xmm0_4
  const QAngle *v58; // eax
  Vector *v59; // eax
  float v60; // ecx
  int v61; // eax
  float v62; // xmm0_4
  float v63; // xmm1_4
  float v64; // xmm0_4
  float v65; // xmm3_4
  bool v66; // cc
  float v67; // xmm4_4
  float v68; // xmm3_4
  float v69; // xmm1_4
  float v70; // xmm0_4
  bool v71; // cc
  float v72; // xmm2_4
  C_BaseEntity *OwnerEntity; // [esp+Ch] [ebp-128h]
  int flTime; // [esp+10h] [ebp-124h]
  float flValue; // [esp+14h] [ebp-120h]
  Vector startpos; // [esp+20h] [ebp-114h] BYREF
  CEffectData data; // [esp+2Ch] [ebp-108h] BYREF
  float v78; // [esp+90h] [ebp-A4h]
  CGameTrace trace; // [esp+94h] [ebp-A0h] BYREF
  float v80; // [esp+E8h] [ebp-4Ch]
  unsigned int v81; // [esp+ECh] [ebp-48h]
  float gravitySlow; // [esp+F0h] [ebp-44h]
  float gravity; // [esp+F4h] [ebp-40h] BYREF
  CBaseHandle v84; // [esp+F8h] [ebp-3Ch] BYREF
  Vector traceFraction; // [esp+FCh] [ebp-38h] OVERLAPPED BYREF
  __int128 traceNormal; // [esp+108h] [ebp-2Ch] OVERLAPPED BYREF
  Vector vecWind; // [esp+118h] [ebp-1Ch] BYREF
  float v88; // [esp+124h] [ebp-10h] BYREF
  IHandleEntity v89; // [esp+128h] [ebp-Ch] BYREF
  CTraceFilterWorldOnly traceFilter; // [esp+12Ch] [ebp-8h]
  CTraceFilterWorldOnly_vtbl *retaddr; // [esp+134h] [ebp+0h]

  v89.__vftable = a2;
  traceFilter.__vftable = retaddr;
  gravity = *(float *)(gpGlobals.m_Index + 12) * 5.5;
  LODWORD(v80) = COERCE_UNSIGNED_INT(sv_gravity.m_pParent->m_Value.m_fValue * frametime) ^ _mask__NegFloat_;
  *(float *)&trace.hitbox = v80 * 0.5;
  gravitySlow = 1.0;
  this->m_vecPrevLocalOrigin = *C_BaseEntity::GetLocalOrigin(this);
  p_m_vecTempEntVelocity = &this->m_vecTempEntVelocity;
  v6 = (float)(this->m_vecTempEntAcceleration.y * frametime) + this->m_vecTempEntVelocity.y;
  v7 = (float)(this->m_vecTempEntAcceleration.z * frametime) + this->m_vecTempEntVelocity.z;
  this->m_vecTempEntVelocity.x = (float)(this->m_vecTempEntAcceleration.x * frametime) + this->m_vecTempEntVelocity.x;
  this->m_vecTempEntVelocity.y = v6;
  this->m_vecTempEntVelocity.z = v7;
  flags = this->flags;
  if ( (flags & 0x8000) != 0 )
  {
    v9 = (*(int (__thiscall **)(unsigned int, _DWORD))(*(_DWORD *)(cl_entitylist.m_Index + 131092) + 12))(
           a1: cl_entitylist.m_Index + 131092,
           a2: this->clientIndex);
    if ( v9 == 0 )
      goto LABEL_11;
    v10 = (float *)(*(int (__thiscall **)(int))(*(_DWORD *)v9 + 40))(a1: v9);
    *((float *)&traceNormal + 1) = this->tentOffset.x + *v10;
    *((float *)&traceNormal + 2) = this->tentOffset.y + v10[1];
    v11 = this->tentOffset.z + v10[2];
  }
  else
  {
    if ( (flags & 1) != 0 )
    {
      m_flSpriteScale = this->m_flSpriteScale;
      this->x = (float)(p_m_vecTempEntVelocity->x * frametime) + this->x;
      v13 = (float)(this->m_vecTempEntVelocity.y * frametime) + this->y;
      this->y = v13;
      v84.m_Index = LODWORD(v13);
      z = this->m_vecTempEntVelocity.z;
      v88 = m_flSpriteScale;
      v15 = (__m128)*(unsigned int *)(gpGlobals.m_Index + 12);
      *(float *)&v81 = z;
      v15.m128_f32[0] = v15.m128_f32[0] + z;
      __libm_sse2_sin(X: (__m128i)_mm_cvtps_pd(v15));
      *(float *)&v16 = v16;
      vecWind.z = (float)(*(float *)&v16 * (float)(v88 * 10.0)) + this->x;
      v17 = (__m128)v81;
      v17.m128_f32[0] = *(float *)&v81 + gravity;
      v18 = (__m128i)_mm_cvtps_pd(v17);
      *(double *)v18.m128i_i64 = *(double *)v18.m128i_i64 + 0.7;
      __libm_sse2_sin(X: v18);
      *(float *)&v84.m_Index = v19 * (float)(v88 * 8.0) + *(float *)&v84.m_Index;
      LocalOriginDim = C_BaseEntity::GetLocalOriginDim(this, iDim: 2);
      v21 = frametime * this->m_vecTempEntVelocity.z;
      *(_QWORD *)((char *)&traceNormal + 4) = __PAIR64__(v84.m_Index, LODWORD(vecWind.z));
      *((float *)&traceNormal + 3) = LocalOriginDim + v21;
      C_BaseEntity::SetLocalOrigin(this, origin: (const Vector *)((char *)&traceNormal + 4));
      goto LABEL_11;
    }
    if ( (flags & 0x400) != 0 )
    {
      *(float *)&v22 = gravity + this->m_vecTempEntVelocity.z;
      v84.m_Index = (unsigned int)&v88;
      LODWORD(vecWind.z) = &gravity;
      v81 = v22;
      v88 = cos(*(float *)&v22);
      gravity = sin(*(float *)&v22);
      v23 = (__m128)*(unsigned int *)(gpGlobals.m_Index + 12);
      LODWORD(vecWind.z) = v23.m128_i32[0];
      v23.m128_f32[0] = v23.m128_f32[0] * 20.0;
      __libm_sse2_sin(X: (__m128i)_mm_cvtps_pd(v23));
      *(float *)&v24 = v24;
      traceFraction.x = (float)(*(float *)&v24 * 8.0) + (float)(p_m_vecTempEntVelocity->x * frametime);
      z_low = (__m128)LODWORD(vecWind.z);
      z_low.m128_f32[0] = vecWind.z * 30.0;
      __libm_sse2_sin(X: (__m128i)_mm_cvtps_pd(z_low));
      *(float *)&v26 = v26;
      traceFraction.y = (float)(*(float *)&v26 * 4.0) + (float)(this->m_vecTempEntVelocity.y * frametime);
      traceFraction.z = frametime * this->m_vecTempEntVelocity.z;
      LocalOrigin = C_BaseEntity::GetLocalOrigin(this);
      v28 = LocalOrigin->x + traceFraction.x;
    }
    else
    {
      traceFraction.x = p_m_vecTempEntVelocity->x * frametime;
      traceFraction.y = this->m_vecTempEntVelocity.y * frametime;
      traceFraction.z = this->m_vecTempEntVelocity.z * frametime;
      LocalOrigin = C_BaseEntity::GetLocalOrigin(this);
      v28 = traceFraction.x + LocalOrigin->x;
    }
    *((float *)&traceNormal + 1) = v28;
    *((float *)&traceNormal + 2) = LocalOrigin->y + traceFraction.y;
    v11 = LocalOrigin->z + traceFraction.z;
  }
  *((float *)&traceNormal + 3) = v11;
  C_BaseEntity::SetLocalOrigin(this, origin: (const Vector *)((char *)&traceNormal + 4));
LABEL_11:
  v29 = this->flags;
  if ( (v29 & 0x100) != 0 )
  {
    v30 = (float)(this->m_flFrameRate * frametime) + this->m_flFrame;
    v31 = v30 < this->m_flFrameMax;
    this->m_flFrame = v30;
    if ( !v31 )
    {
      this->m_flFrame = v30 - (float)(int)v30;
      if ( (v29 & 0x10000) == 0 )
      {
        this->die = 0.0;
        return 0;
      }
    }
  }
  else if ( (v29 & 0x800) != 0 )
  {
    v33 = (float)(frametime * 10.0) + this->m_flFrame;
    v31 = v33 < this->m_flFrameMax;
    this->m_flFrame = v33;
    if ( !v31 )
      this->m_flFrame = v33 - (float)(int)v33;
  }
  if ( (v29 & 0x20000) != 0 )
    this->m_flSpriteScale = (float)(frametime * 0.5) + this->m_flSpriteScale;
  if ( (v29 & 4) != 0 )
  {
    traceFraction.x = this->m_vecTempEntAngVelocity.x * frametime;
    traceFraction.y = this->m_vecTempEntAngVelocity.y * frametime;
    traceFraction.z = this->m_vecTempEntAngVelocity.z * frametime;
    LocalAngles = C_BaseEntity::GetLocalAngles(this);
    *((float *)&traceNormal + 1) = LocalAngles->x + traceFraction.x;
    *((float *)&traceNormal + 2) = LocalAngles->y + traceFraction.y;
    *((float *)&traceNormal + 3) = LocalAngles->z + traceFraction.z;
    C_BaseEntity::SetLocalAngles(this, angles: (const QAngle *)((char *)&traceNormal + 4));
  }
  else if ( (v29 & 0x4000000) != 0 )
  {
    v35 = 0;
    *(float *)&v35 = fsqrt(
                       (float)((float)(p_m_vecTempEntVelocity->x * p_m_vecTempEntVelocity->x)
                             + (float)(this->m_vecTempEntVelocity.y * this->m_vecTempEntVelocity.y))
                     + (float)(this->m_vecTempEntVelocity.z * this->m_vecTempEntVelocity.z));
    traceNormal = v35;
    if ( *(float *)&v35 > 0.0 )
    {
      VectorAngles(forward: &this->m_vecTempEntVelocity, angles: (QAngle *)((char *)&traceNormal + 4));
      C_BaseEntity::SetAbsAngles(this, absAngles: (const QAngle *)((char *)&traceNormal + 4));
    }
  }
  m_Index = this->flags;
  v84.m_Index = m_Index;
  if ( (m_Index & 0x1020) != 0 )
  {
    memset((void *)&traceFraction, 0, sizeof(traceFraction));
    if ( (m_Index & 0x1000) != 0 )
    {
      v37 = *(_QWORD *)&this->m_vecPrevLocalOrigin.x;
      HIDWORD(traceNormal) = LODWORD(this->m_vecPrevLocalOrigin.z);
      *(_QWORD *)((char *)&traceNormal + 4) = v37;
      if ( cl_fasttempentcollision.m_pParent != nullptr )
      {
        m_nValue = cl_fasttempentcollision.m_pParent->m_Value.m_nValue;
        if ( m_nValue > 0 && (m_Index & 0x10000000) != 0 )
        {
          v39 = m_nValue + this->m_iLastCollisionFrame;
          vecWind.z = *(float *)(gpGlobals.m_Index + 4);
          if ( v39 > SLODWORD(vecWind.z) )
            goto LABEL_75;
          if ( Vector::operator!=(this: &this->m_vLastCollisionOrigin, src: &vec3_origin) )
          {
            *(_QWORD *)((char *)&traceNormal + 4) = *(_QWORD *)&this->m_vLastCollisionOrigin.x;
            HIDWORD(traceNormal) = LODWORD(this->m_vLastCollisionOrigin.z);
          }
          this->m_iLastCollisionFrame = LODWORD(vecWind.z);
          m_Index = v84.m_Index;
        }
      }
      m_CollisionGroup = 0;
      if ( (m_Index & 0x2000000) != 0 )
        m_CollisionGroup = this->m_CollisionGroup;
      flTime = m_CollisionGroup;
      OwnerEntity = C_BaseEntity::GetOwnerEntity(this);
      v41 = C_BaseEntity::GetLocalOrigin(this);
      UTIL_TraceLine(
        a1: &v89,
        a2: (int)this,
        vecAbsStart: (const Vector *)((char *)&traceNormal + 4),
        vecAbsEnd: v41,
        mask: 0x200400Bu,
        ignore: OwnerEntity,
        collisionGroup: flTime,
        ptr: (CGameTrace *)&data.m_nColor);
      if ( trace.plane.normal.z != 1.0 )
      {
        if ( CGameTrace::DidHitWorld(this: (CGameTrace *)&data.m_nColor)
          || (BaseEntity = CClientEntityList::GetBaseEntity(
                             this: (CClientEntityList *)cl_entitylist.m_Index,
                             entnum: this->clientIndex),
              *(C_BaseEntity **)&trace.surface.surfaceProps != BaseEntity) )
        {
          gravitySlow = trace.plane.normal.z;
          traceFraction = trace.endpos;
        }
      }
      this->m_vLastCollisionOrigin = trace.startpos;
    }
    else
    {
      if ( (m_Index & 0x20) == 0 )
        goto LABEL_75;
      LODWORD(vecWind.z) = &CTraceFilterWorldOnly::`vftable';
      v43 = C_BaseEntity::GetLocalOrigin(this);
      UTIL_TraceLine(
        a1: (int)&v89,
        a2: (int)this,
        vecAbsStart: &this->m_vecPrevLocalOrigin,
        vecAbsEnd: v43,
        mask: 0x200400Bu,
        pFilter: (ITraceFilter *)&vecWind.z,
        ptr: (CGameTrace *)&data.m_nColor);
      if ( trace.plane.normal.z == 1.0 )
        goto LABEL_75;
      gravitySlow = trace.plane.normal.z;
      traceFraction = trace.endpos;
    }
    if ( gravitySlow != 1.0 )
    {
      C_BaseEntity::SetLocalOrigin(this, origin: &trace.startpos);
      v44 = this->flags;
      bounceFactor = this->bounceFactor;
      v88 = bounceFactor;
      if ( (v44 & 0xA) != 0 )
      {
        bounceFactor = bounceFactor * 0.5;
        v88 = bounceFactor;
        if ( traceFraction.z > 0.9 )
        {
          v46 = this->m_vecTempEntVelocity.z;
          if ( v46 <= 0.0 && v46 >= (float)(v80 * 3.0) )
          {
            v88 = 0.0;
            this->flags = v44 & 0xFFFFFFC1;
            C_BaseEntity::SetLocalAnglesDim(this, iDim: 0, flValue: 0.0);
            C_BaseEntity::SetLocalAnglesDim(this, iDim: 2, flValue: 0.0);
            bounceFactor = v88;
          }
        }
      }
      if ( (this->flags & 0x1000000) != 0 )
      {
        C_BaseEntity::OnTranslucencyTypeChanged(this);
        this->flags &= ~0x1000000u;
        bounceFactor = v88;
      }
      if ( this->hitSound != 0 )
      {
        ((void (__stdcall *)(C_LocalTempEntity *, _DWORD))tempents->PlaySound)(a1: this, a2: LODWORD(bounceFactor));
        bounceFactor = v88;
      }
      if ( this->m_pszImpactEffect != nullptr )
      {
        CEffectData::CEffectData(this: (CEffectData *)&startpos);
        startpos = trace.startpos;
        data.m_vOrigin.x = *(float *)&data.m_nColor;
        LOWORD(data.m_flMagnitude) = trace.dispFlags;
        LODWORD(data.m_vOrigin.y) = data.m_iEffectName;
        *(_DWORD *)&data.m_nSurfaceProp = trace.hitgroup;
        clientIndex = this->clientIndex;
        data.m_vOrigin.z = v78;
        data.m_nAttachmentIndex = 0;
        v48 = (*(int (__thiscall **)(unsigned int, int))(*(_DWORD *)(cl_entitylist.m_Index + 131092) + 12))(
                a1: cl_entitylist.m_Index + 131092,
                a2: clientIndex);
        if ( v48 != 0 )
        {
          v49 = (void *)(v48 + 8);
          if ( v49 != nullptr )
          {
            v50 = __RTDynamicCast(
                    inptr: v49,
                    VfDelta: 0,
                    SrcType: &IClientNetworkable `RTTI Type Descriptor',
                    TargetType: &C_BasePlayer `RTTI Type Descriptor',
                    isReference: 0);
            if ( v50 != nullptr )
              data.m_nAttachmentIndex = (*(int (__thiscall **)(void *))(*(_DWORD *)v50 + 332))(a1: v50);
          }
        }
        if ( *(_DWORD *)&trace.surface.surfaceProps != 0 )
        {
          v51 = *(_DWORD *)(*(_DWORD *)&trace.surface.surfaceProps + 8);
          LODWORD(vecWind.z) = (CBaseHandle)cl_entitylist.m_Index;
          v52 = (*(int (__thiscall **)(int))(v51 + 40))(a1: *(_DWORD *)&trace.surface.surfaceProps + 8);
          LODWORD(data.m_vAngles.y) = (CBaseHandle)CClientEntityList::EntIndexToHandle(
                                                     this: (CClientEntityList *)LODWORD(vecWind.z),
                                                     result: &v84,
                                                     entnum: v52)->m_Index;
        }
        DispatchEffect(pName: this->m_pszImpactEffect, data: (const CEffectData *)&startpos);
        bounceFactor = v88;
      }
      if ( (this->flags & 0x8000000) != 0 )
      {
        CParticleProperty::StopEmission(
          this: &this->m_Particles,
          pEffect: nullptr,
          bWakeOnStop: false,
          bDestroyAsleepSystems: false,
          bForceRemoveInstantly: false,
          bPlayEndCap: false);
        bounceFactor = v88;
        this->m_bParticleCollision = true;
      }
      v53 = this->flags;
      if ( (v53 & 0x4000) != 0 )
      {
        this->flags = v53 & 0xFFFFFF7F;
        this->die = *(float *)(gpGlobals.m_Index + 12);
      }
      else if ( (v53 & 0x40000) != 0 )
      {
        if ( !CGameTrace::DidHitWorld(this: (CGameTrace *)&data.m_nColor) || (trace.allsolid & 4) != 0 )
        {
          this->flags &= ~0x80u;
          this->die = *(float *)(gpGlobals.m_Index + 12);
        }
        else
        {
          p_m_vecTempEntVelocity->x = vec3_origin.x;
          this->m_vecTempEntVelocity.y = vec3_origin.y;
          this->m_vecTempEntVelocity.z = vec3_origin.z;
          this->m_vecTempEntAcceleration = vec3_origin;
          this->flags &= 0xFFFFEFDF;
        }
      }
      else
      {
        if ( bounceFactor != 0.0 )
        {
          v54 = this->m_vecTempEntVelocity.z;
          y = traceFraction.y;
          *(_QWORD *)((char *)&traceNormal + 4) = *(_QWORD *)&p_m_vecTempEntVelocity->x;
          v56 = traceFraction.z;
          *((float *)&traceNormal + 3) = v54;
          v57 = (float)((float)((float)(*((float *)&traceNormal + 2) * traceFraction.y)
                              + (float)(*((float *)&traceNormal + 1) * traceFraction.x))
                      + (float)(v54 * traceFraction.z))
              * -2.0;
          p_m_vecTempEntVelocity->x = (float)(v57 * traceFraction.x) + p_m_vecTempEntVelocity->x;
          this->m_vecTempEntVelocity.y = (float)(y * v57) + this->m_vecTempEntVelocity.y;
          this->m_vecTempEntVelocity.z = (float)(v56 * v57) + this->m_vecTempEntVelocity.z;
          flValue = -C_BaseEntity::GetLocalAnglesDim(this, iDim: 1);
          C_BaseEntity::SetLocalAnglesDim(this, iDim: 1, flValue);
          bounceFactor = v88;
        }
        if ( bounceFactor != 1.0 )
        {
          p_m_vecTempEntVelocity->x = p_m_vecTempEntVelocity->x * bounceFactor;
          this->m_vecTempEntVelocity.y = this->m_vecTempEntVelocity.y * bounceFactor;
          this->m_vecTempEntVelocity.z = this->m_vecTempEntVelocity.z * bounceFactor;
          v58 = C_BaseEntity::GetLocalAngles(this);
          *((float *)&traceNormal + 1) = v58->x * 0.89999998;
          *((float *)&traceNormal + 2) = v58->y * 0.89999998;
          *((float *)&traceNormal + 3) = v58->z * 0.89999998;
          C_BaseEntity::SetLocalAngles(this, angles: (const QAngle *)((char *)&traceNormal + 4));
        }
      }
    }
  }
LABEL_75:
  if ( (this->flags & 0x40) != 0 && framenumber == this->m_nFlickerFrame )
  {
    LODWORD(vecWind.z) = effects->CL_AllocDlight(this: effects, a2: 0x10000000);
    v59 = C_BaseEntity::GetLocalOrigin(this);
    v60 = vecWind.z;
    *(Vector *)(LODWORD(vecWind.z) + 4) = *v59;
    *(_DWORD *)(LODWORD(v60) + 16) = 1114636288;
    *(_WORD *)(LODWORD(v60) + 20) = 30975;
    *(_BYTE *)(LODWORD(v60) + 22) = 0;
    *(float *)(LODWORD(v60) + 24) = *(float *)(gpGlobals.m_Index + 12) + 0.01;
  }
  if ( gravitySlow == 1.0 )
  {
    v61 = this->flags;
    if ( (v61 & 2) != 0 )
    {
      v62 = v80;
    }
    else
    {
      if ( (v61 & 8) == 0 )
        goto LABEL_84;
      v62 = *(float *)&trace.hitbox;
    }
    this->m_vecTempEntVelocity.z = v62 + this->m_vecTempEntVelocity.z;
  }
LABEL_84:
  if ( (this->flags & 0x200000) == 0 )
    return 1;
  GetWindspeedAtTime(flTime: *(float *)(gpGlobals.m_Index + 12), vecVelocity: (Vector *)((char *)&traceNormal + 4));
  v63 = *((float *)&traceNormal + 1);
  if ( *((float *)&traceNormal + 1) > p_m_vecTempEntVelocity->x )
  {
    v64 = frametime;
    v65 = (float)(frametime * 50.0) + p_m_vecTempEntVelocity->x;
    p_m_vecTempEntVelocity->x = v65;
    v66 = v65 <= v63;
    goto LABEL_89;
  }
  v64 = frametime;
  if ( p_m_vecTempEntVelocity->x != *((float *)&traceNormal + 1) )
  {
    v67 = p_m_vecTempEntVelocity->x - (float)(frametime * 50.0);
    p_m_vecTempEntVelocity->x = v67;
    v66 = v63 <= v67;
LABEL_89:
    if ( !v66 )
      p_m_vecTempEntVelocity->x = v63;
  }
  v68 = this->m_vecTempEntVelocity.y;
  v69 = *((float *)&traceNormal + 2);
  if ( *((float *)&traceNormal + 2) > v68 )
  {
    v70 = (float)(v64 * 50.0) + v68;
    this->m_vecTempEntVelocity.y = v70;
    v71 = v70 <= v69;
    goto LABEL_95;
  }
  if ( v68 > *((float *)&traceNormal + 2) )
  {
    v72 = this->m_vecTempEntVelocity.y - (float)(v64 * 50.0);
    this->m_vecTempEntVelocity.y = v72;
    v71 = v69 <= v72;
LABEL_95:
    if ( !v71 )
      this->m_vecTempEntVelocity.y = v69;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1025D210
// Name: private: void CTempEnts::MuzzleFlash_Combine_Player(class CBaseHandle,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTempEnts::MuzzleFlash_Combine_Player(CTempEnts *this, CBaseHandle hEntity, int attachmentIndex)
{
  CTempEnts *v3; // ebx
  int v4; // edi
  CLocalSpaceEmitter *m_pObj; // esi
  int v6; // eax
  Particle *v7; // eax
  Particle *v8; // esi
  double v9; // st7
  char v10; // al
  int v11; // eax
  CLocalSpaceEmitter *v12; // esi
  int v13; // eax
  Particle *v14; // eax
  Particle *v15; // esi
  char v16; // al
  Vector offset; // [esp+60h] [ebp-20h] BYREF
  int v18; // [esp+6Ch] [ebp-14h]
  CTempEnts *v19; // [esp+70h] [ebp-10h]
  float flScale; // [esp+74h] [ebp-Ch]
  int i; // [esp+78h] [ebp-8h]
  CSmartPtr<CLocalSpaceEmitter,CRefCountAccessor> pSimple; // [esp+7Ch] [ebp-4h] BYREF
  int attachmentIndexa; // [esp+8Ch] [ebp+Ch]

  v3 = this;
  v19 = this;
  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "MuzzleFlash_Combine_Player",
    a3: 0,
    a4: "Particle/Effect_Rendering",
    a5: false,
    a6: 4);
  CLocalSpaceEmitter::Create(
    result: &pSimple,
    pDebugName: "MuzzleFlash",
    hEntity,
    nAttachment: attachmentIndex,
    fFlags: 1);
  CTempEnts::CacheMuzzleFlashes(this: v3);
  flScale = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
              a1: random,
              a2: 0x40000000,
              a3: 1074790400);
  CSimpleEmitter::SetDrawBeforeViewModel(this: pSimple.m_pObj, state: true);
  v4 = 11;
  i = 1;
  attachmentIndexa = 11;
  while ( 1 )
  {
    m_pObj = pSimple.m_pObj;
    offset.x = (float)((float)i * 8.0) * flScale;
    offset.y = offset.x * 0.0;
    offset.z = offset.x * 0.0;
    v6 = random->RandomInt(this: random, a2: 0, a3: 1);
    v7 = CParticleEffect::AddParticle(
           this: m_pObj,
           particleSize: 0x3Cu,
           material: v3->m_Material_Combine_MuzzleFlash_Player[v6],
           origin: &offset);
    v8 = v7;
    if ( v7 == nullptr )
      break;
    *(_QWORD *)&v7[1].m_Pos.y = 1020054733;
    v7[1].m_pPrev = nullptr;
    v7[1].m_pNext = nullptr;
    v7[1].m_pSubTexture = nullptr;
    LOWORD(v7[2].m_pPrev) = -1;
    BYTE2(v7[2].m_pPrev) = random->RandomInt(this: random, a2: 0, a3: 55) - 56;
    *(_WORD *)((char *)&v8[2].m_pPrev + 3) = -1;
    v9 = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
           a1: random,
           a2: 1086324736,
           a3: 1090519040);
    v18 = (int)(v9 * (double)attachmentIndexa * 0.083333336 * flScale);
    v10 = v18;
    BYTE1(v8[2].m_pNext) = v18;
    BYTE2(v8[2].m_pNext) = v10;
    v11 = random->RandomInt(this: random, a2: 0, a3: 360);
    ++i;
    --v4;
    v8[1].m_Pos.x = (float)v11;
    v8[2].m_pSubTexture = nullptr;
    attachmentIndexa = v4;
    if ( v4 <= 6 )
    {
      v12 = pSimple.m_pObj;
      v13 = random->RandomInt(this: random, a2: 0, a3: 1);
      v14 = CParticleEffect::AddParticle(
              this: v12,
              particleSize: 0x3Cu,
              material: v19->m_Material_Combine_MuzzleFlash_Player[v13],
              origin: &vec3_origin);
      v15 = v14;
      if ( v14 != nullptr )
      {
        *(_QWORD *)&v14[1].m_Pos.y = 1020054733;
        v14[1].m_pPrev = nullptr;
        v14[1].m_pNext = nullptr;
        v14[1].m_pSubTexture = nullptr;
        LOWORD(v14[2].m_pPrev) = -1;
        BYTE2(v14[2].m_pPrev) = -1;
        HIBYTE(v14[2].m_pPrev) = random->RandomInt(this: random, a2: 64, a3: 128);
        LOBYTE(v15[2].m_pNext) = 32;
        v18 = (int)((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
                     a1: random,
                     a2: 1092616192,
                     a3: 1098907648);
        v16 = v18;
        BYTE1(v15[2].m_pNext) = v18;
        BYTE2(v15[2].m_pNext) = v16;
        v15[1].m_Pos.x = (float)random->RandomInt(this: random, a2: 0, a3: 360);
        v15[2].m_pSubTexture = nullptr;
      }
      break;
    }
    v3 = v19;
  }
  if ( pSimple.m_pObj != nullptr )
    CParticleEffect::Release(this: pSimple.m_pObj);
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
}

//------------------------------------------------------------------------------
// Address: 0x1025D500
// Name: private: void CTempEnts::MuzzleFlash_Combine_NPC(class CBaseHandle,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTempEnts::MuzzleFlash_Combine_NPC(CTempEnts *this, CBaseHandle hEntity, int attachmentIndex)
{
  int v3; // edi
  CLocalSpaceEmitter *m_pObj; // esi
  int v5; // eax
  Particle *v6; // eax
  Particle *v7; // esi
  float v8; // xmm0_4
  float v9; // xmm1_4
  float v10; // xmm0_4
  double v11; // st7
  char v12; // al
  int v13; // edi
  CLocalSpaceEmitter *v14; // esi
  float v15; // xmm0_4
  int v16; // eax
  Particle *v17; // eax
  Particle *v18; // esi
  float v19; // xmm1_4
  double v20; // st7
  char v21; // al
  int v22; // eax
  int v23; // edi
  CLocalSpaceEmitter *v24; // esi
  float v25; // xmm1_4
  int v26; // eax
  Particle *v27; // eax
  Particle *v28; // esi
  float v29; // xmm1_4
  double v30; // st7
  char v31; // al
  int v32; // eax
  int v33; // edi
  CLocalSpaceEmitter *v34; // esi
  int v35; // eax
  Particle *v36; // eax
  Particle *v37; // esi
  float v38; // xmm2_4
  double v39; // st7
  char v40; // al
  int v41; // eax
  Particle *v42; // eax
  Particle *v43; // esi
  double v44; // st7
  double v45; // st7
  C_BaseEntity *BaseEntityFromHandle; // eax
  IVEfx_vtbl *v47; // esi
  int v48; // eax
  int v49; // esi
  int v50; // eax
  matrix3x4_t matAttachment; // [esp+B8h] [ebp-60h] BYREF
  Vector origin; // [esp+E8h] [ebp-30h]
  Vector offset; // [esp+F4h] [ebp-24h] BYREF
  int v54; // [esp+100h] [ebp-18h]
  int i; // [esp+104h] [ebp-14h]
  float burstSpeed; // [esp+108h] [ebp-10h]
  float flScale; // [esp+10Ch] [ebp-Ch]
  CSmartPtr<CLocalSpaceEmitter,CRefCountAccessor> pSimple; // [esp+110h] [ebp-8h] BYREF
  int v59; // [esp+114h] [ebp-4h]

  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "MuzzleFlash_Combine_NPC",
    a3: 0,
    a4: "Particle/Effect_Rendering",
    a5: false,
    a6: 4);
  CLocalSpaceEmitter::Create(
    result: &pSimple,
    pDebugName: "MuzzleFlash_Combine_NPC",
    hEntity,
    nAttachment: attachmentIndex,
    fFlags: 0);
  flScale = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
              a1: random,
              a2: 1065353216,
              a3: 1069547520);
  burstSpeed = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
                 a1: random,
                 a2: 1112014848,
                 a3: 1125515264);
  v3 = 1;
  while ( 1 )
  {
    m_pObj = pSimple.m_pObj;
    *(float *)&i = (float)v3;
    offset.x = (float)((float)v3 * 2.0) * flScale;
    offset.y = offset.x * 0.0;
    offset.z = offset.x * 0.0;
    v5 = random->RandomInt(this: random, a2: 0, a3: 1);
    v6 = CParticleEffect::AddParticle(
           this: m_pObj,
           particleSize: 0x3Cu,
           material: g_Mat_Combine_Muzzleflash[v5],
           origin: &offset);
    v7 = v6;
    if ( v6 == nullptr )
      break;
    v6[1].m_Pos.y = 0.1;
    v8 = burstSpeed;
    v6[1].m_Pos.z = 0.0;
    v9 = v8;
    v10 = v8 * 0.0;
    *(float *)&v6[1].m_pSubTexture = v10;
    *(float *)&v6[1].m_pPrev = v9;
    *(float *)&v6[1].m_pNext = v10;
    LOBYTE(v6[2].m_pPrev) = -1;
    BYTE1(v6[2].m_pPrev) = -1;
    BYTE2(v6[2].m_pPrev) = -1;
    HIBYTE(v6[2].m_pPrev) = -1;
    LOBYTE(v6[2].m_pNext) = 0;
    v11 = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
            a1: random,
            a2: 1086324736,
            a3: 1090519040);
    v54 = (int)(v11 * (7.5 - *(float *)&i) * 0.16666667 * flScale);
    v12 = v54;
    BYTE1(v7[2].m_pNext) = v54;
    BYTE2(v7[2].m_pNext) = v12;
    ++v3;
    v7[1].m_Pos.x = (float)random->RandomInt(this: random, a2: 0, a3: 360);
    v7[2].m_pSubTexture = nullptr;
    if ( v3 >= 6 )
    {
      burstSpeed = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
                     a1: random,
                     a2: 1112014848,
                     a3: 1125515264);
      v13 = 5;
      i = 1;
      v59 = 5;
      while ( 1 )
      {
        v14 = pSimple.m_pObj;
        v15 = (float)i * flScale;
        offset.x = v15 * 0.0;
        offset.y = v15;
        offset.z = v15 * -1.0;
        v16 = random->RandomInt(this: random, a2: 0, a3: 1);
        v17 = CParticleEffect::AddParticle(
                this: v14,
                particleSize: 0x3Cu,
                material: g_Mat_Combine_Muzzleflash[v16],
                origin: &offset);
        v18 = v17;
        if ( v17 == nullptr )
          goto LABEL_19;
        v19 = burstSpeed;
        v17[1].m_Pos.y = 0.2;
        v17[1].m_Pos.z = 0.0;
        *(float *)&v17[1].m_pPrev = (float)(v19 * 0.0) * 0.25;
        *(float *)&v17[1].m_pNext = v19 * 0.25;
        *(float *)&v17[1].m_pSubTexture = (float)(v19 * -1.0) * 0.25;
        LOBYTE(v17[2].m_pPrev) = -1;
        BYTE1(v17[2].m_pPrev) = -1;
        BYTE2(v17[2].m_pPrev) = -1;
        HIBYTE(v17[2].m_pPrev) = -1;
        LOBYTE(v17[2].m_pNext) = 0;
        v20 = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
                a1: random,
                a2: 0x40000000,
                a3: 1082130432);
        v54 = (int)(v20 * (double)v59 * 0.33333334 * flScale);
        v21 = v54;
        BYTE1(v18[2].m_pNext) = v54;
        BYTE2(v18[2].m_pNext) = v21;
        v22 = random->RandomInt(this: random, a2: 0, a3: 360);
        ++i;
        --v13;
        v18[1].m_Pos.x = (float)v22;
        v18[2].m_pSubTexture = nullptr;
        v59 = v13;
        if ( v13 <= 0 )
        {
          burstSpeed = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
                         a1: random,
                         a2: 1112014848,
                         a3: 1125515264);
          v23 = 5;
          i = 1;
          v59 = 5;
          while ( 1 )
          {
            v24 = pSimple.m_pObj;
            v25 = (float)i * flScale;
            offset.x = v25 * -0.0;
            offset.y = v25 * -1.0;
            offset.z = v25 * -1.0;
            v26 = random->RandomInt(this: random, a2: 0, a3: 1);
            v27 = CParticleEffect::AddParticle(
                    this: v24,
                    particleSize: 0x3Cu,
                    material: g_Mat_Combine_Muzzleflash[v26],
                    origin: &offset);
            v28 = v27;
            if ( v27 == nullptr )
              goto LABEL_19;
            v29 = burstSpeed;
            v27[1].m_Pos.y = 0.2;
            v27[1].m_Pos.z = 0.0;
            *(float *)&v27[1].m_pPrev = (float)(COERCE_FLOAT(LODWORD(v29) ^ _mask__NegFloat_) * 0.0) * 0.25;
            *(float *)&v27[1].m_pNext = COERCE_FLOAT(LODWORD(v29) ^ _mask__NegFloat_) * 0.25;
            *(float *)&v27[1].m_pSubTexture = COERCE_FLOAT(LODWORD(v29) ^ _mask__NegFloat_) * 0.25;
            LOBYTE(v27[2].m_pPrev) = -1;
            BYTE1(v27[2].m_pPrev) = -1;
            BYTE2(v27[2].m_pPrev) = -1;
            HIBYTE(v27[2].m_pPrev) = -1;
            LOBYTE(v27[2].m_pNext) = 0;
            v30 = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
                    a1: random,
                    a2: 0x40000000,
                    a3: 1082130432);
            v54 = (int)(v30 * (double)v59 * 0.33333334 * flScale);
            v31 = v54;
            BYTE1(v28[2].m_pNext) = v54;
            BYTE2(v28[2].m_pNext) = v31;
            v32 = random->RandomInt(this: random, a2: 0, a3: 360);
            ++i;
            --v23;
            v28[1].m_Pos.x = (float)v32;
            v28[2].m_pSubTexture = nullptr;
            v59 = v23;
            if ( v23 <= 0 )
            {
              burstSpeed = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
                             a1: random,
                             a2: 1112014848,
                             a3: 1125515264);
              v33 = 5;
              i = 1;
              v59 = 5;
              while ( 1 )
              {
                v34 = pSimple.m_pObj;
                offset.x = (float)((float)i * flScale) * 0.0;
                offset.y = offset.x;
                offset.z = (float)i * flScale;
                v35 = random->RandomInt(this: random, a2: 0, a3: 1);
                v36 = CParticleEffect::AddParticle(
                        this: v34,
                        particleSize: 0x3Cu,
                        material: g_Mat_Combine_Muzzleflash[v35],
                        origin: &offset);
                v37 = v36;
                if ( v36 == nullptr )
                  goto LABEL_19;
                v38 = burstSpeed;
                v36[1].m_Pos.y = 0.2;
                v36[1].m_Pos.z = 0.0;
                *(float *)&v36[1].m_pNext = (float)(v38 * 0.0) * 0.25;
                *(float *)&v36[1].m_pPrev = (float)(v38 * 0.0) * 0.25;
                *(float *)&v36[1].m_pSubTexture = v38 * 0.25;
                LOBYTE(v36[2].m_pPrev) = -1;
                BYTE1(v36[2].m_pPrev) = -1;
                BYTE2(v36[2].m_pPrev) = -1;
                HIBYTE(v36[2].m_pPrev) = -1;
                LOBYTE(v36[2].m_pNext) = 0;
                v39 = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
                        a1: random,
                        a2: 0x40000000,
                        a3: 1082130432);
                v54 = (int)(v39 * (double)v59 * 0.33333334 * flScale);
                v40 = v54;
                BYTE1(v37[2].m_pNext) = v54;
                BYTE2(v37[2].m_pNext) = v40;
                v41 = random->RandomInt(this: random, a2: 0, a3: 360);
                ++i;
                --v33;
                v37[1].m_Pos.x = (float)v41;
                v37[2].m_pSubTexture = nullptr;
                v59 = v33;
                if ( v33 <= 0 )
                {
                  v42 = CParticleEffect::AddParticle(
                          this: pSimple.m_pObj,
                          particleSize: 0x3Cu,
                          material: dword_1066E420,
                          origin: &vec3_origin);
                  v43 = v42;
                  if ( v42 != nullptr )
                  {
                    v42[1].m_Pos.z = 0.0;
                    v42[1].m_Pos.y = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
                                       a1: random,
                                       a2: 1050253722,
                                       a3: 1053609165);
                    v43[1].m_pPrev = nullptr;
                    v43[1].m_pNext = nullptr;
                    v43[1].m_pSubTexture = nullptr;
                    LOBYTE(v43[2].m_pPrev) = -1;
                    BYTE1(v43[2].m_pPrev) = -1;
                    BYTE2(v43[2].m_pPrev) = -1;
                    HIBYTE(v43[2].m_pPrev) = -1;
                    LOBYTE(v43[2].m_pNext) = 0;
                    v44 = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
                            a1: random,
                            a2: 1094713344,
                            a3: 1098907648);
                    v45 = v44 * flScale;
                    BYTE2(v43[2].m_pNext) = 0;
                    v54 = (int)v45;
                    BYTE1(v43[2].m_pNext) = (int)v45;
                    v43[1].m_Pos.x = (float)random->RandomInt(this: random, a2: 0, a3: 360);
                    v43[2].m_pSubTexture = nullptr;
                    if ( FX_GetAttachmentTransform(hEntity, attachmentIndex, transform: &matAttachment) != 0 )
                    {
                      origin.x = matAttachment.m_flMatVal[0][3];
                      origin.y = matAttachment.m_flMatVal[1][3];
                      origin.z = matAttachment.m_flMatVal[2][3];
                      if ( muzzleflash_light.m_pParent != nullptr && muzzleflash_light.m_pParent->m_Value.m_nValue != 0 )
                      {
                        BaseEntityFromHandle = CClientEntityList::GetBaseEntityFromHandle(
                                                 this: (CClientEntityList *)cl_entitylist.m_Index,
                                                 hEnt: hEntity);
                        if ( BaseEntityFromHandle != nullptr )
                        {
                          v47 = effects->__vftable;
                          v48 = BaseEntityFromHandle->entindex(this: &BaseEntityFromHandle->IClientNetworkable);
                          v49 = (int)v47->CL_AllocElight(this: effects, a2: v48 + 0x40000000);
                          *(Vector *)(v49 + 4) = origin;
                          *(_WORD *)(v49 + 20) = -32704;
                          *(_BYTE *)(v49 + 22) = -1;
                          *(_BYTE *)(v49 + 23) = 5;
                          v50 = random->RandomInt(this: random, a2: 32, a3: 128);
                          *(float *)(v49 + 16) = (float)v50;
                          *(float *)(v49 + 28) = (float)v50 * 20.0;
                          *(float *)(v49 + 24) = *(float *)(gpGlobals.m_Index + 12) + 0.050000001;
                        }
                      }
                    }
                  }
                  goto LABEL_19;
                }
              }
            }
          }
        }
      }
    }
  }
LABEL_19:
  if ( pSimple.m_pObj != nullptr )
    CParticleEffect::Release(this: pSimple.m_pObj);
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
}

//------------------------------------------------------------------------------
// Address: 0x1025DDA0
// Name: private: void CTempEnts::MuzzleFlash_SMG1_Player(class CBaseHandle,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTempEnts::MuzzleFlash_SMG1_Player(CTempEnts *this, CBaseHandle hEntity, int attachmentIndex)
{
  int v4; // edi
  CLocalSpaceEmitter *m_pObj; // esi
  int v6; // eax
  Particle *v7; // eax
  Particle *v8; // esi
  double v9; // st7
  char v10; // al
  int v11; // eax
  Vector offset; // [esp+40h] [ebp-20h] BYREF
  int v13; // [esp+4Ch] [ebp-14h]
  CTempEnts *v14; // [esp+50h] [ebp-10h]
  float flScale; // [esp+54h] [ebp-Ch]
  int i; // [esp+58h] [ebp-8h]
  CSmartPtr<CLocalSpaceEmitter,CRefCountAccessor> pSimple; // [esp+5Ch] [ebp-4h] BYREF
  int attachmentIndexa; // [esp+6Ch] [ebp+Ch]

  v14 = this;
  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "MuzzleFlash_SMG1_Player",
    a3: 0,
    a4: "Particle/Effect_Rendering",
    a5: false,
    a6: 4);
  CLocalSpaceEmitter::Create(
    result: &pSimple,
    pDebugName: "MuzzleFlash_SMG1_Player",
    hEntity,
    nAttachment: attachmentIndex,
    fFlags: 1);
  CTempEnts::CacheMuzzleFlashes(this);
  flScale = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
              a1: random,
              a2: 1067450368,
              a3: 1069547520);
  CSimpleEmitter::SetDrawBeforeViewModel(this: pSimple.m_pObj, state: true);
  v4 = 7;
  i = 1;
  attachmentIndexa = 7;
  do
  {
    m_pObj = pSimple.m_pObj;
    offset.x = (float)((float)i * 8.0) * flScale;
    offset.y = offset.x * 0.0;
    offset.z = offset.x * 0.0;
    v6 = random->RandomInt(this: random, a2: 0, a3: 3);
    v7 = CParticleEffect::AddParticle(
           this: m_pObj,
           particleSize: 0x3Cu,
           material: v14->m_Material_MuzzleFlash_Player[v6],
           origin: &offset);
    v8 = v7;
    if ( v7 == nullptr )
      break;
    *(_QWORD *)&v7[1].m_Pos.y = 1020054733;
    v7[1].m_pPrev = nullptr;
    v7[1].m_pNext = nullptr;
    v7[1].m_pSubTexture = nullptr;
    LOBYTE(v7[2].m_pPrev) = -1;
    BYTE1(v7[2].m_pPrev) = -1;
    BYTE2(v7[2].m_pPrev) = random->RandomInt(this: random, a2: 0, a3: 55) - 56;
    HIBYTE(v8[2].m_pPrev) = -1;
    LOBYTE(v8[2].m_pNext) = -1;
    v9 = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
           a1: random,
           a2: 1086324736,
           a3: 1090519040);
    v13 = (int)(v9 * (double)attachmentIndexa * 0.16666667 * flScale);
    v10 = v13;
    BYTE1(v8[2].m_pNext) = v13;
    BYTE2(v8[2].m_pNext) = v10;
    v11 = random->RandomInt(this: random, a2: 0, a3: 360);
    ++i;
    --v4;
    v8[1].m_Pos.x = (float)v11;
    v8[2].m_pSubTexture = nullptr;
    attachmentIndexa = v4;
  }
  while ( v4 > 2 );
  if ( pSimple.m_pObj != nullptr )
    CParticleEffect::Release(this: pSimple.m_pObj);
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
}

//------------------------------------------------------------------------------
// Address: 0x1025DFA0
// Name: private: void CTempEnts::MuzzleFlash_Shotgun_Player(class CBaseHandle,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTempEnts::MuzzleFlash_Shotgun_Player(CTempEnts *this, CBaseHandle hEntity, int attachmentIndex)
{
  int v4; // edi
  CSimpleEmitter *m_pObj; // esi
  float v6; // xmm0_4
  int v7; // eax
  Particle *v8; // eax
  Particle *v9; // esi
  double v10; // st7
  char v11; // al
  int v12; // eax
  QAngle angles; // [esp+40h] [ebp-5Ch] BYREF
  Vector offset; // [esp+4Ch] [ebp-50h] BYREF
  Vector forward; // [esp+58h] [ebp-44h] BYREF
  Vector bbMin; // [esp+64h] [ebp-38h] BYREF
  Vector bbMax; // [esp+70h] [ebp-2Ch] BYREF
  Vector origin; // [esp+7Ch] [ebp-20h] BYREF
  int v19; // [esp+88h] [ebp-14h]
  CTempEnts *v20; // [esp+8Ch] [ebp-10h]
  float flScale; // [esp+90h] [ebp-Ch]
  int i; // [esp+94h] [ebp-8h]
  CSmartPtr<CSimpleEmitter,CRefCountAccessor> pSimple; // [esp+98h] [ebp-4h] BYREF
  int attachmentIndexa; // [esp+A8h] [ebp+Ch]

  v20 = this;
  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "MuzzleFlash_Shotgun_Player",
    a3: 0,
    a4: "Particle/Effect_Rendering",
    a5: false,
    a6: 4);
  CSimpleEmitter::Create(result: &pSimple, pDebugName: "MuzzleFlash_Shotgun_Player");
  CSimpleEmitter::SetDrawBeforeViewModel(this: pSimple.m_pObj, state: true);
  CTempEnts::CacheMuzzleFlashes(this);
  FX_GetAttachmentTransform(hEntity, attachmentIndex, &origin, &angles);
  bbMax.x = origin.x + 4.0;
  bbMax.y = origin.y + 4.0;
  bbMax.z = origin.z + 4.0;
  bbMin.x = origin.x - 4.0;
  bbMin.y = origin.y - 4.0;
  bbMin.z = origin.z - 4.0;
  CParticleEffectBinding::SetBBox(this: &pSimple.m_pObj->m_ParticleEffect, &bbMin, &bbMax, bDisableAutoUpdate: true);
  AngleVectors(&angles, &forward, right: nullptr, up: nullptr);
  flScale = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
              a1: random,
              a2: 1067450368,
              a3: 1069547520);
  v4 = 7;
  i = 1;
  attachmentIndexa = 7;
  do
  {
    m_pObj = pSimple.m_pObj;
    v6 = (float)((float)i * 8.0) * flScale;
    offset.x = (float)(forward.x * v6) + origin.x;
    offset.y = (float)(forward.y * v6) + origin.y;
    offset.z = (float)(forward.z * v6) + origin.z;
    v7 = random->RandomInt(this: random, a2: 0, a3: 3);
    v8 = CParticleEffect::AddParticle(
           this: m_pObj,
           particleSize: 0x3Cu,
           material: v20->m_Material_MuzzleFlash_Player[v7],
           origin: &offset);
    v9 = v8;
    if ( v8 == nullptr )
      break;
    *(_QWORD *)&v8[1].m_Pos.y = 953267991;
    v8[1].m_pPrev = nullptr;
    v8[1].m_pNext = nullptr;
    v8[1].m_pSubTexture = nullptr;
    LOBYTE(v8[2].m_pPrev) = -1;
    BYTE1(v8[2].m_pPrev) = -1;
    BYTE2(v8[2].m_pPrev) = random->RandomInt(this: random, a2: 0, a3: 55) - 56;
    HIBYTE(v9[2].m_pPrev) = -1;
    LOBYTE(v9[2].m_pNext) = -1;
    v10 = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
            a1: random,
            a2: 1086324736,
            a3: 1090519040);
    v19 = (int)(v10 * (double)attachmentIndexa * 0.16666667 * flScale);
    v11 = v19;
    BYTE1(v9[2].m_pNext) = v19;
    BYTE2(v9[2].m_pNext) = v11;
    v12 = random->RandomInt(this: random, a2: 0, a3: 360);
    ++i;
    --v4;
    v9[1].m_Pos.x = (float)v12;
    v9[2].m_pSubTexture = nullptr;
    attachmentIndexa = v4;
  }
  while ( v4 > 2 );
  if ( pSimple.m_pObj != nullptr )
    CParticleEffect::Release(this: pSimple.m_pObj);
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
}

//------------------------------------------------------------------------------
// Address: 0x1025E240
// Name: private: void CTempEnts::MuzzleFlash_357_Player(class CBaseHandle,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTempEnts::MuzzleFlash_357_Player(CTempEnts *this, CBaseHandle hEntity, int attachmentIndex)
{
  Particle *v4; // eax
  Particle *v5; // esi
  float y; // xmm1_4
  float z; // xmm2_4
  char v8; // al
  unsigned __int8 v9; // al
  int v10; // edi
  int v11; // ebx
  CSimpleEmitter *m_pObj; // esi
  float v13; // xmm0_4
  int v14; // eax
  Particle *v15; // eax
  Particle *v16; // esi
  double v17; // st7
  char v18; // al
  QAngle angles; // [esp+80h] [ebp-58h] BYREF
  Vector bbMin; // [esp+8Ch] [ebp-4Ch] BYREF
  Vector bbMax; // [esp+98h] [ebp-40h] BYREF
  Vector offset; // [esp+A4h] [ebp-34h] BYREF
  Vector origin; // [esp+B0h] [ebp-28h] BYREF
  Vector forward; // [esp+BCh] [ebp-1Ch] BYREF
  int v25; // [esp+C8h] [ebp-10h]
  CTempEnts *v26; // [esp+CCh] [ebp-Ch]
  float flScale; // [esp+D0h] [ebp-8h]
  CSmartPtr<CSimpleEmitter,CRefCountAccessor> pSimple; // [esp+D4h] [ebp-4h] BYREF
  float attachmentIndexb; // [esp+E4h] [ebp+Ch]
  int attachmentIndexa; // [esp+E4h] [ebp+Ch]

  v26 = this;
  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "MuzzleFlash_357_Player",
    a3: 0,
    a4: "Particle/Effect_Rendering",
    a5: false,
    a6: 4);
  CSimpleEmitter::Create(result: &pSimple, pDebugName: "MuzzleFlash_357_Player");
  CSimpleEmitter::SetDrawBeforeViewModel(this: pSimple.m_pObj, state: true);
  CTempEnts::CacheMuzzleFlashes(this);
  FX_GetAttachmentTransform(hEntity, attachmentIndex, &origin, &angles);
  bbMax.x = origin.x + 4.0;
  bbMax.y = origin.y + 4.0;
  bbMax.z = origin.z + 4.0;
  bbMin.x = origin.x - 4.0;
  bbMin.y = origin.y - 4.0;
  bbMin.z = origin.z - 4.0;
  CParticleEffectBinding::SetBBox(this: &pSimple.m_pObj->m_ParticleEffect, &bbMin, &bbMax, bDisableAutoUpdate: true);
  AngleVectors(&angles, &forward, right: nullptr, up: nullptr);
  offset.x = (float)(forward.x * 8.0) + origin.x;
  offset.y = (float)(forward.y * 8.0) + origin.y;
  offset.z = (float)(forward.z * 8.0) + origin.z;
  v4 = CParticleEffect::AddParticle(
         this: pSimple.m_pObj,
         particleSize: 0x3Cu,
         material: g_Mat_DustPuff[0],
         origin: &offset);
  v5 = v4;
  if ( v4 != nullptr )
  {
    v4[1].m_Pos.z = 0.0;
    v4[1].m_Pos.y = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
                      a1: random,
                      a2: 1056964608,
                      a3: 1065353216);
    v5[1].m_pPrev = nullptr;
    v5[1].m_pNext = nullptr;
    v5[1].m_pSubTexture = nullptr;
    attachmentIndexb = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
                         a1: random,
                         a2: 1090519040,
                         a3: 1115684864);
    y = forward.y;
    z = forward.z;
    *(float *)&v5[1].m_pPrev = attachmentIndexb * forward.x;
    *(float *)&v5[1].m_pNext = y * attachmentIndexb;
    *(float *)&v5[1].m_pSubTexture = z * attachmentIndexb;
    *(float *)&v5[1].m_pSubTexture = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
                                       a1: random,
                                       a2: 1082130432,
                                       a3: 1098907648)
                                   + *(float *)&v5[1].m_pSubTexture;
    v8 = random->RandomInt(this: random, a2: 200, a3: 255);
    LOBYTE(v5[2].m_pPrev) = v8;
    BYTE1(v5[2].m_pPrev) = v8;
    BYTE2(v5[2].m_pPrev) = v8;
    HIBYTE(v5[2].m_pPrev) = random->RandomInt(this: random, a2: 64, a3: 128);
    LOBYTE(v5[2].m_pNext) = 0;
    v9 = random->RandomInt(this: random, a2: 2, a3: 4);
    BYTE1(v5[2].m_pNext) = v9;
    BYTE2(v5[2].m_pNext) = (int)(float)((float)v9 * 8.0);
    v5[1].m_Pos.x = (float)random->RandomInt(this: random, a2: 0, a3: 360);
    *(float *)&v5[2].m_pSubTexture = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
                                       a1: random,
                                       a2: -1090519040,
                                       a3: 1056964608);
    flScale = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
                a1: random,
                a2: 1067450368,
                a3: 1069547520);
    v10 = 7;
    v11 = 1;
    attachmentIndexa = 7;
    do
    {
      m_pObj = pSimple.m_pObj;
      v13 = (float)((float)v11 * 8.0) * flScale;
      offset.x = (float)(forward.x * v13) + origin.x;
      offset.y = (float)(forward.y * v13) + origin.y;
      offset.z = (float)(forward.z * v13) + origin.z;
      v14 = random->RandomInt(this: random, a2: 0, a3: 3);
      v15 = CParticleEffect::AddParticle(
              this: m_pObj,
              particleSize: 0x3Cu,
              material: v26->m_Material_MuzzleFlash_Player[v14],
              origin: &offset);
      v16 = v15;
      if ( v15 == nullptr )
        break;
      *(_QWORD *)&v15[1].m_Pos.y = 1008981770;
      v15[1].m_pPrev = nullptr;
      v15[1].m_pNext = nullptr;
      v15[1].m_pSubTexture = nullptr;
      LOWORD(v15[2].m_pPrev) = -1;
      BYTE2(v15[2].m_pPrev) = random->RandomInt(this: random, a2: 0, a3: 55) - 56;
      *(_WORD *)((char *)&v16[2].m_pPrev + 3) = -1;
      v17 = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
              a1: random,
              a2: 1086324736,
              a3: 1090519040);
      v25 = (int)(v17 * (double)attachmentIndexa * 0.16666667 * flScale);
      v18 = v25;
      BYTE1(v16[2].m_pNext) = v25;
      BYTE2(v16[2].m_pNext) = v18;
      --v10;
      v16[1].m_Pos.x = (float)random->RandomInt(this: random, a2: 0, a3: 360);
      ++v11;
      v16[2].m_pSubTexture = nullptr;
      attachmentIndexa = v10;
    }
    while ( v10 > 2 );
  }
  if ( pSimple.m_pObj != nullptr )
    CParticleEffect::Release(this: pSimple.m_pObj);
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
}

//------------------------------------------------------------------------------
// Address: 0x1025E6D0
// Name: private: void CTempEnts::MuzzleFlash_Pistol_Player(class CBaseHandle,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTempEnts::MuzzleFlash_Pistol_Player(CTempEnts *this, CBaseHandle hEntity, int attachmentIndex)
{
  Particle *v4; // eax
  Particle *v5; // esi
  float y; // xmm1_4
  float z; // xmm2_4
  char v8; // al
  unsigned __int8 v9; // al
  int v10; // edi
  int v11; // ebx
  CSimpleEmitter *m_pObj; // esi
  float v13; // xmm0_4
  int v14; // eax
  Particle *v15; // eax
  Particle *v16; // esi
  double v17; // st7
  char v18; // al
  QAngle angles; // [esp+88h] [ebp-58h] BYREF
  Vector bbMin; // [esp+94h] [ebp-4Ch] BYREF
  Vector bbMax; // [esp+A0h] [ebp-40h] BYREF
  Vector offset; // [esp+ACh] [ebp-34h] BYREF
  Vector origin; // [esp+B8h] [ebp-28h] BYREF
  Vector forward; // [esp+C4h] [ebp-1Ch] BYREF
  int v25; // [esp+D0h] [ebp-10h]
  CTempEnts *v26; // [esp+D4h] [ebp-Ch]
  float flScale; // [esp+D8h] [ebp-8h]
  CSmartPtr<CSimpleEmitter,CRefCountAccessor> pSimple; // [esp+DCh] [ebp-4h] BYREF
  float attachmentIndexb; // [esp+ECh] [ebp+Ch]
  int attachmentIndexa; // [esp+ECh] [ebp+Ch]

  v26 = this;
  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "MuzzleFlash_Pistol_Player",
    a3: 0,
    a4: "Particle/Effect_Rendering",
    a5: false,
    a6: 4);
  CSimpleEmitter::Create(result: &pSimple, pDebugName: "MuzzleFlash_Pistol_Player");
  CSimpleEmitter::SetDrawBeforeViewModel(this: pSimple.m_pObj, state: true);
  CTempEnts::CacheMuzzleFlashes(this);
  FX_GetAttachmentTransform(hEntity, attachmentIndex, &origin, &angles);
  bbMax.x = origin.x + 4.0;
  bbMax.y = origin.y + 4.0;
  bbMax.z = origin.z + 4.0;
  bbMin.x = origin.x - 4.0;
  bbMin.y = origin.y - 4.0;
  bbMin.z = origin.z - 4.0;
  CParticleEffectBinding::SetBBox(this: &pSimple.m_pObj->m_ParticleEffect, &bbMin, &bbMax, bDisableAutoUpdate: true);
  AngleVectors(&angles, &forward, right: nullptr, up: nullptr);
  offset.x = (float)(forward.x * 8.0) + origin.x;
  offset.y = (float)(forward.y * 8.0) + origin.y;
  offset.z = (float)(forward.z * 8.0) + origin.z;
  if ( random->RandomInt(this: random, a2: 0, a3: 3) == 0 )
  {
LABEL_4:
    flScale = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
                a1: random,
                a2: 1065353216,
                a3: 1067450368);
    v10 = 7;
    v11 = 1;
    attachmentIndexa = 7;
    do
    {
      m_pObj = pSimple.m_pObj;
      v13 = (float)((float)v11 * 4.0) * flScale;
      offset.x = (float)(forward.x * v13) + origin.x;
      offset.y = (float)(forward.y * v13) + origin.y;
      offset.z = (float)(forward.z * v13) + origin.z;
      v14 = random->RandomInt(this: random, a2: 0, a3: 3);
      v15 = CParticleEffect::AddParticle(
              this: m_pObj,
              particleSize: 0x3Cu,
              material: v26->m_Material_MuzzleFlash_Player[v14],
              origin: &offset);
      v16 = v15;
      if ( v15 == nullptr )
        break;
      *(_QWORD *)&v15[1].m_Pos.y = 1008981770;
      v15[1].m_pPrev = nullptr;
      v15[1].m_pNext = nullptr;
      v15[1].m_pSubTexture = nullptr;
      LOWORD(v15[2].m_pPrev) = -1;
      BYTE2(v15[2].m_pPrev) = random->RandomInt(this: random, a2: 0, a3: 55) - 56;
      *(_WORD *)((char *)&v16[2].m_pPrev + 3) = -1;
      v17 = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
              a1: random,
              a2: 1086324736,
              a3: 1090519040);
      v25 = (int)(v17 * (double)attachmentIndexa * 0.16666667 * flScale);
      v18 = v25;
      BYTE1(v16[2].m_pNext) = v25;
      BYTE2(v16[2].m_pNext) = v18;
      --v10;
      v16[1].m_Pos.x = (float)random->RandomInt(this: random, a2: 0, a3: 360);
      ++v11;
      v16[2].m_pSubTexture = nullptr;
      attachmentIndexa = v10;
    }
    while ( v10 > 2 );
    goto LABEL_7;
  }
  v4 = CParticleEffect::AddParticle(
         this: pSimple.m_pObj,
         particleSize: 0x3Cu,
         material: g_Mat_DustPuff[0],
         origin: &offset);
  v5 = v4;
  if ( v4 != nullptr )
  {
    v4[1].m_Pos.z = 0.0;
    v4[1].m_Pos.y = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
                      a1: random,
                      a2: 1048576000,
                      a3: 1056964608);
    v5[1].m_pPrev = nullptr;
    v5[1].m_pNext = nullptr;
    v5[1].m_pSubTexture = nullptr;
    attachmentIndexb = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
                         a1: random,
                         a2: 1111490560,
                         a3: 1115684864);
    y = forward.y;
    z = forward.z;
    *(float *)&v5[1].m_pPrev = attachmentIndexb * forward.x;
    *(float *)&v5[1].m_pNext = y * attachmentIndexb;
    *(float *)&v5[1].m_pSubTexture = z * attachmentIndexb;
    *(float *)&v5[1].m_pSubTexture = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
                                       a1: random,
                                       a2: 1082130432,
                                       a3: 1098907648)
                                   + *(float *)&v5[1].m_pSubTexture;
    v8 = random->RandomInt(this: random, a2: 200, a3: 255);
    LOBYTE(v5[2].m_pPrev) = v8;
    BYTE1(v5[2].m_pPrev) = v8;
    BYTE2(v5[2].m_pPrev) = v8;
    HIBYTE(v5[2].m_pPrev) = random->RandomInt(this: random, a2: 64, a3: 128);
    LOBYTE(v5[2].m_pNext) = 0;
    v9 = random->RandomInt(this: random, a2: 2, a3: 4);
    BYTE1(v5[2].m_pNext) = v9;
    BYTE2(v5[2].m_pNext) = (int)(float)((float)v9 * 4.0);
    v5[1].m_Pos.x = (float)random->RandomInt(this: random, a2: 0, a3: 360);
    *(float *)&v5[2].m_pSubTexture = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
                                       a1: random,
                                       a2: -1110651699,
                                       a3: 1036831949);
    goto LABEL_4;
  }
LABEL_7:
  if ( pSimple.m_pObj != nullptr )
    CParticleEffect::Release(this: pSimple.m_pObj);
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
}

//------------------------------------------------------------------------------
// Address: 0x1025ED30
// Name: protected: unsigned short CUtlLinkedList<class C_LocalTempEntity __near *,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<class C_LocalTempEntity __near *,unsigned short>,unsigned short>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<C_LocalTempEntity *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<C_LocalTempEntity *,unsigned short>,unsigned short>>::AllocInternal(
        CUtlLinkedList<C_LocalTempEntity *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<C_LocalTempEntity *,unsigned short>,unsigned short> > *this,
        bool multilist)
{
  int m_FirstFree; // ecx
  int m_nAllocationCount; // ecx
  unsigned __int16 index; // ax
  int result; // eax
  int v7; // ecx
  unsigned __int16 v8; // ax
  UtlLinkedListElem_t<C_LocalTempEntity *,unsigned short> *v9; // ecx

  m_FirstFree = this->m_FirstFree;
  if ( (_WORD)m_FirstFree != 0xFFFF )
  {
    result = m_FirstFree;
    this->m_FirstFree = this->m_Memory.m_pMemory[m_FirstFree].m_Next;
LABEL_22:
    v9 = &this->m_Memory.m_pMemory[(unsigned __int16)result];
    if ( multilist )
    {
      v9->m_Next = -1;
      v9->m_Previous = -1;
    }
    else
    {
      v9->m_Next = result;
      v9->m_Previous = result;
    }
    return result;
  }
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( this->m_LastAlloc.index >= m_nAllocationCount )
  {
    m_nAllocationCount = this->m_Memory.m_nAllocationCount;
    LOWORD(result) = (m_nAllocationCount > 0) - 1;
  }
  else
  {
    index = this->m_LastAlloc.index;
    if ( (unsigned __int16)(index + 1) >= m_nAllocationCount )
      LOWORD(result) = -1;
    else
      LOWORD(result) = index + 1;
  }
  if ( (unsigned __int16)result >= m_nAllocationCount )
  {
    CUtlMemory<UtlLinkedListElem_t<CParticleEffectBinding *,unsigned short>,unsigned short>::Grow(
      (CUtlMemory<UtlLinkedListElem_t<C_RopeKeyframe *,unsigned short>,unsigned short> *)this,
      num: 1);
    this->m_pElements = this->m_Memory.m_pMemory;
    v7 = this->m_Memory.m_nAllocationCount;
    if ( this->m_LastAlloc.index >= v7 )
    {
      v7 = this->m_Memory.m_nAllocationCount;
      LOWORD(result) = (v7 > 0) - 1;
    }
    else
    {
      v8 = this->m_LastAlloc.index;
      LOWORD(result) = (unsigned __int16)(v8 + 1) >= v7 ? -1 : v8 + 1;
    }
    if ( (unsigned __int16)result >= v7 )
    {
      if ( `CUtlLinkedList<C_LocalTempEntity *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<C_LocalTempEntity *,unsigned short>,unsigned short>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<C_LocalTempEntity *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<C_LocalTempEntity *,unsigned short>,unsigned short>>::AllocInternal'::`12'::__executeCount;
        _Warning(a1: "CUtlLinkedList overflow! (exhausted memory allocator)\n");
      }
      return 0xFFFF;
    }
  }
  if ( (_WORD)result != 0xFFFF )
  {
    ++this->m_NumAlloced;
    this->m_LastAlloc.index = result;
    result = (unsigned __int16)result;
    goto LABEL_22;
  }
  if ( `CUtlLinkedList<C_LocalTempEntity *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<C_LocalTempEntity *,unsigned short>,unsigned short>>::AllocInternal'::`19'::__executeCount >= 10 )
    return 0xFFFF;
  ++`CUtlLinkedList<C_LocalTempEntity *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<C_LocalTempEntity *,unsigned short>,unsigned short>>::AllocInternal'::`19'::__executeCount;
  _Warning(a1: "CUtlLinkedList overflow! (exhausted index range)\n");
  return 0xFFFF;
}

//------------------------------------------------------------------------------
// Address: 0x1025EEB0
// Name: protected: unsigned short CUtlLinkedList<struct CBreakableHelper::BreakableList_t,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<struct CBreakableHelper::BreakableList_t,unsigned short>,unsigned short>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<CBreakableHelper::BreakableList_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CBreakableHelper::BreakableList_t,unsigned short>,unsigned short>>::AllocInternal(
        CUtlLinkedList<CBreakableHelper::BreakableList_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CBreakableHelper::BreakableList_t,unsigned short>,unsigned short> > *this,
        bool multilist)
{
  int m_FirstFree; // ecx
  int m_nAllocationCount; // ecx
  unsigned __int16 index; // ax
  int result; // eax
  int v7; // ecx
  unsigned __int16 v8; // ax
  UtlLinkedListElem_t<CBreakableHelper::BreakableList_t,unsigned short> *v9; // ecx

  m_FirstFree = this->m_FirstFree;
  if ( (_WORD)m_FirstFree != 0xFFFF )
  {
    result = m_FirstFree;
    this->m_FirstFree = this->m_Memory.m_pMemory[m_FirstFree].m_Next;
LABEL_22:
    v9 = &this->m_Memory.m_pMemory[(unsigned __int16)result];
    if ( multilist )
    {
      v9->m_Next = -1;
      v9->m_Previous = -1;
    }
    else
    {
      v9->m_Next = result;
      v9->m_Previous = result;
    }
    return result;
  }
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( this->m_LastAlloc.index >= m_nAllocationCount )
  {
    m_nAllocationCount = this->m_Memory.m_nAllocationCount;
    LOWORD(result) = (m_nAllocationCount > 0) - 1;
  }
  else
  {
    index = this->m_LastAlloc.index;
    if ( (unsigned __int16)(index + 1) >= m_nAllocationCount )
      LOWORD(result) = -1;
    else
      LOWORD(result) = index + 1;
  }
  if ( (unsigned __int16)result >= m_nAllocationCount )
  {
    CUtlMemory<UtlLinkedListElem_t<CRagdollEntry,unsigned short>,unsigned short>::Grow(
      (CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> *)this,
      num: 1);
    this->m_pElements = this->m_Memory.m_pMemory;
    v7 = this->m_Memory.m_nAllocationCount;
    if ( this->m_LastAlloc.index >= v7 )
    {
      v7 = this->m_Memory.m_nAllocationCount;
      LOWORD(result) = (v7 > 0) - 1;
    }
    else
    {
      v8 = this->m_LastAlloc.index;
      LOWORD(result) = (unsigned __int16)(v8 + 1) >= v7 ? -1 : v8 + 1;
    }
    if ( (unsigned __int16)result >= v7 )
    {
      if ( `CUtlLinkedList<CBreakableHelper::BreakableList_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CBreakableHelper::BreakableList_t,unsigned short>,unsigned short>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<CBreakableHelper::BreakableList_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CBreakableHelper::BreakableList_t,unsigned short>,unsigned short>>::AllocInternal'::`12'::__executeCount;
        _Warning(a1: "CUtlLinkedList overflow! (exhausted memory allocator)\n");
      }
      return 0xFFFF;
    }
  }
  if ( (_WORD)result != 0xFFFF )
  {
    ++this->m_NumAlloced;
    this->m_LastAlloc.index = result;
    result = (unsigned __int16)result;
    goto LABEL_22;
  }
  if ( `CUtlLinkedList<CBreakableHelper::BreakableList_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CBreakableHelper::BreakableList_t,unsigned short>,unsigned short>>::AllocInternal'::`19'::__executeCount >= 10 )
    return 0xFFFF;
  ++`CUtlLinkedList<CBreakableHelper::BreakableList_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CBreakableHelper::BreakableList_t,unsigned short>,unsigned short>>::AllocInternal'::`19'::__executeCount;
  _Warning(a1: "CUtlLinkedList overflow! (exhausted index range)\n");
  return 0xFFFF;
}

//------------------------------------------------------------------------------
// Address: 0x1025F230
// Name: public: class Vector const __near * CBreakableHelper::GetLightingOrigin(class C_LocalTempEntity __near *)
// Source: json
//------------------------------------------------------------------------------
const Vector *__thiscall CBreakableHelper::GetLightingOrigin(CBreakableHelper *this, C_LocalTempEntity *entity)
{
  int m_Head; // eax
  unsigned int v3; // esi
  C_LocalTempEntity *v4; // edi
  UtlLinkedListElem_t<CBreakableHelper::BreakableList_t,unsigned short> *m_pMemory; // ecx
  int v6; // eax
  unsigned int context; // edx
  UtlLinkedListElem_t<CBreakableHelper::BreakableList_t,unsigned short> *v8; // eax

  m_Head = this->m_Breakables.m_Head;
  v3 = 0;
  v4 = nullptr;
  if ( m_Head == 0xFFFF )
    return nullptr;
  m_pMemory = this->m_Breakables.m_Memory.m_pMemory;
  while ( 1 )
  {
    v6 = (unsigned __int16)m_Head;
    context = m_pMemory[v6].m_Element.context;
    v8 = &m_pMemory[v6];
    if ( context != v3 )
    {
      v4 = v8->m_Element.entity;
      v3 = context;
    }
    if ( v8->m_Element.entity == entity )
      break;
    m_Head = v8->m_Next;
    if ( m_Head == 0xFFFF )
      return nullptr;
  }
  if ( v4 == nullptr )
    return nullptr;
  else
    return v4->GetAbsOrigin(this: v4);
}

//------------------------------------------------------------------------------
// Address: 0x1025F2A0
// Name: int BreakModelDrawHelper(class C_LocalTempEntity __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl BreakModelDrawHelper(C_LocalTempEntity *entity, int flags)
{
  int index; // eax
  IClientRenderable_vtbl *v3; // edx
  const struct model_t *v4; // eax
  IClientRenderable_vtbl *v5; // edx
  int v6; // eax
  IClientRenderable_vtbl *v7; // edx
  float v8; // xmm0_4
  const QAngle *(__thiscall *GetRenderAngles)(IClientRenderable *); // eax
  int v10; // eax
  IClientRenderable_vtbl *v11; // edx
  float v12; // xmm0_4
  int (__thiscall *GetSkin)(IClientRenderable *); // eax
  int v14; // eax
  IClientRenderable_vtbl *v15; // edx
  int v16; // eax
  const Vector *LightingOrigin; // eax
  ModelRenderInfo_t sInfo; // [esp+Ch] [ebp-44h] BYREF

  memset(&sInfo.pModelToWorld, 0, 12);
  sInfo.flags = flags;
  if ( entity != nullptr )
    sInfo.pRenderable = &entity->IClientRenderable;
  else
    sInfo.pRenderable = nullptr;
  index = entity->index;
  sInfo.instance = -1;
  v3 = entity->C_BaseAnimating::C_BaseEntity::IClientEntity::IClientRenderable::__vftable;
  sInfo.entity_index = index;
  v4 = v3->GetModel(this: &entity->IClientRenderable);
  v5 = entity->C_BaseAnimating::C_BaseEntity::IClientEntity::IClientRenderable::__vftable;
  sInfo.pModel = v4;
  v6 = (int)v5->GetRenderOrigin(this: &entity->IClientRenderable);
  v7 = entity->C_BaseAnimating::C_BaseEntity::IClientEntity::IClientRenderable::__vftable;
  sInfo.origin.x = *(float *)v6;
  sInfo.origin.y = *(float *)(v6 + 4);
  v8 = *(float *)(v6 + 8);
  GetRenderAngles = v7->GetRenderAngles;
  sInfo.origin.z = v8;
  v10 = (int)GetRenderAngles(this: &entity->IClientRenderable);
  v11 = entity->C_BaseAnimating::C_BaseEntity::IClientEntity::IClientRenderable::__vftable;
  sInfo.angles.x = *(float *)v10;
  sInfo.angles.y = *(float *)(v10 + 4);
  v12 = *(float *)(v10 + 8);
  GetSkin = v11->GetSkin;
  sInfo.angles.z = v12;
  v14 = GetSkin(this: &entity->IClientRenderable);
  v15 = entity->C_BaseAnimating::C_BaseEntity::IClientEntity::IClientRenderable::__vftable;
  sInfo.skin = v14;
  v16 = v15->GetBody(this: &entity->IClientRenderable);
  sInfo.hitboxset = entity->m_nHitboxSet;
  sInfo.body = v16;
  LightingOrigin = CBreakableHelper::GetLightingOrigin(this: &g_BreakableHelper, entity);
  if ( LightingOrigin != nullptr )
    sInfo.pLightingOrigin = LightingOrigin;
  return modelrender->DrawModelEx(this: modelrender, a2: &sInfo);
}

//------------------------------------------------------------------------------
// Address: 0x1025F390
// Name: public: virtual void CTempEnts::KillAttachedTents(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTempEnts::KillAttachedTents(CTempEnts *this, int client)
{
  int i; // eax
  int v3; // eax
  C_LocalTempEntity *m_Element; // edx

  if ( client <= 0 || client > *(_DWORD *)(gpGlobals.m_Index + 20) )
  {
    _Warning(a1: "Bad client in KillAttachedTents()!\n");
  }
  else
  {
    for ( i = this->m_TempEnts.m_Head; i != 0xFFFF; i = this->m_TempEnts.m_Memory.m_pMemory[v3].m_Next )
    {
      v3 = (unsigned __int16)i;
      m_Element = this->m_TempEnts.m_Memory.m_pMemory[v3].m_Element;
      if ( (m_Element->flags & 0x8000) != 0 && m_Element->clientIndex == client )
        m_Element->die = *(float *)(gpGlobals.m_Index + 12);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1025F410
// Name: private: void CTempEnts::MuzzleFlash_Shotgun_NPC(class CBaseHandle,int)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CTempEnts::MuzzleFlash_Shotgun_NPC(
        CTempEnts *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>,
        int a4@<esi>,
        CBaseHandle hEntity,
        CParticleEffect *attachmentIndex)
{
  CParticleEffect *v6; // esi
  IClientRenderable *ClientRenderableFromHandle; // eax
  int v8; // ebx
  Particle *v9; // eax
  Particle *v10; // edi
  IUniformRandomStream *v11; // ecx
  IUniformRandomStream *v12; // ecx
  IUniformRandomStream *v13; // ecx
  double v14; // st7
  CTrailParticles *v15; // eax
  CTrailParticles *v16; // edi
  CParticleEffect *v17; // esi
  int v18; // ebx
  Particle *v19; // eax
  Particle *v20; // edi
  IUniformRandomStream *v21; // ecx
  IUniformRandomStream *v22; // ecx
  IUniformRandomStream *v23; // ecx
  float (__thiscall *RandomFloat)(IUniformRandomStream *, float, float); // eax
  double v25; // st7
  double v26; // st7
  QAngle angles; // [esp+38h] [ebp-2Ch] BYREF
  Vector origin; // [esp+44h] [ebp-20h] BYREF
  Vector forward; // [esp+50h] [ebp-14h] BYREF
  int numEmbers; // [esp+5Ch] [ebp-8h]
  int dot; // [esp+60h] [ebp-4h]

  v6 = attachmentIndex;
  FX_MuzzleEffectAttached(scale: 0.75, hEntity, (int)attachmentIndex, pFlashColor: nullptr, bOneFrame: false);
  ClientRenderableFromHandle = CClientEntityList::GetClientRenderableFromHandle(
                                 this: (CClientEntityList *)cl_entitylist.m_Index,
                                 hEnt: hEntity);
  if ( ClientRenderableFromHandle == nullptr )
    return;
  ((void (__thiscall *)(IClientRenderable *, CParticleEffect *, Vector *, QAngle *, int, int, int))ClientRenderableFromHandle->GetAttachment_2)(
    a1: ClientRenderableFromHandle,
    a2: v6,
    a3: &origin,
    a4: &angles,
    a5: a3,
    a6: a4,
    a7: a2);
  AngleVectors(&angles, &forward);
  if ( random->RandomInt(this: random, a2: 0, a3: 2) != 0 )
    goto LABEL_8;
  CEmberEffect::Create(
    result: (CSmartPtr<CEmberEffect,CRefCountAccessor> *)&attachmentIndex,
    pDebugName: "muzzle_embers");
  CParticleEffect::SetSortOrigin(this: attachmentIndex, vSortOrigin: &origin);
  v8 = 0;
  *(float *)&dot = COERCE_FLOAT(random->RandomInt(this: random, a2: 0, a3: 4));
  if ( dot <= 0 )
  {
LABEL_6:
    if ( attachmentIndex != nullptr )
      CParticleEffect::Release(this: attachmentIndex);
LABEL_8:
    v15 = (CTrailParticles *)MemAlloc_Alloc(nSize: 0x184u);
    if ( v15 != nullptr )
      v16 = CTrailParticles::CTrailParticles(this: v15, pDebugName: "MuzzleFlash_Shotgun_NPC");
    else
      v16 = nullptr;
    v17 = nullptr;
    attachmentIndex = nullptr;
    if ( v16 != nullptr )
    {
      CParticleEffect::AddRef(this: v16);
      attachmentIndex = v16;
      v17 = v16;
    }
    CParticleEffect::SetSortOrigin(this: v17, vSortOrigin: &origin);
    LODWORD(v17[1].m_ParticleEffect.m_LastMax.y) |= 4u;
    v17[1].m_ParticleEffect.m_LastMin.y = 0.0;
    v18 = 0;
    numEmbers = random->RandomInt(this: random, a2: 4, a3: 8);
    if ( numEmbers > 0 )
    {
      do
      {
        v19 = CParticleEffect::AddParticle(this: v17, particleSize: 0x38u, material: g_Mat_SMG_Muzzleflash[0], &origin);
        v20 = v19;
        if ( v19 == nullptr )
          break;
        v19[1].m_Pos.z = 0.0;
        v19[1].m_Pos.y = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
                           a1: random,
                           a2: 1036831949,
                           a3: 1045220557);
        *(float *)&v20[1].m_pPrev = _RandomFloat(this: v21, a2: -0.050000001, a3: 0.050000001);
        *(float *)&v20[1].m_pNext = _RandomFloat(this: v22, a2: -0.050000001, a3: 0.050000001);
        *(float *)&v20[1].m_pSubTexture = _RandomFloat(this: v23, a2: -0.050000001, a3: 0.050000001);
        *(float *)&v20[1].m_pPrev = *(float *)&v20[1].m_pPrev + forward.x;
        *(float *)&v20[1].m_pNext = *(float *)&v20[1].m_pNext + forward.y;
        *(float *)&v20[1].m_pSubTexture = *(float *)&v20[1].m_pSubTexture + forward.z;
        VectorNormalize(vec: (Vector *)&v20[1]);
        VectorNormalize(vec: &forward);
        RandomFloat = random->RandomFloat;
        *(float *)&dot = (1.0
                        - fabs(
                            *(float *)&v20[1].m_pNext * forward.y
                          + *(float *)&v20[1].m_pPrev * forward.x
                          + *(float *)&v20[1].m_pSubTexture * forward.z))
                       * 20.0;
        v25 = ((double (__cdecl *)(int, int))RandomFloat)(a1: 1132462080, a2: 1149239296);
        v26 = v25 * (1.0 - *(float *)&dot);
        *(float *)&v20[1].m_pPrev = *(float *)&v20[1].m_pPrev * v26;
        *(float *)&v20[1].m_pNext = *(float *)&v20[1].m_pNext * v26;
        *(float *)&v20[1].m_pSubTexture = v26 * *(float *)&v20[1].m_pSubTexture;
        v20[1].m_Pos.x = NAN;
        v20[2].m_pPrev = (Particle *)1028443341;
        *(float *)&v20[2].m_pNext = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
                                      a1: random,
                                      a2: 1048576000,
                                      a3: 1056964608);
        v17 = attachmentIndex;
        ++v18;
      }
      while ( v18 < numEmbers );
    }
    CParticleEffect::Release(this: v17);
    return;
  }
  while ( 1 )
  {
    v9 = CParticleEffect::AddParticle(
           this: attachmentIndex,
           particleSize: 0x3Cu,
           material: g_Mat_SMG_Muzzleflash[0],
           &origin);
    v10 = v9;
    if ( v9 == nullptr )
      break;
    v9[1].m_Pos.z = 0.0;
    v9[1].m_Pos.y = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
                      a1: random,
                      a2: 1045220557,
                      a3: 1053609165);
    *(float *)&v10[1].m_pPrev = _RandomFloat(this: v11, a2: -0.050000001, a3: 0.050000001);
    *(float *)&v10[1].m_pNext = _RandomFloat(this: v12, a2: -0.050000001, a3: 0.050000001);
    *(float *)&v10[1].m_pSubTexture = _RandomFloat(this: v13, a2: -0.050000001, a3: 0.050000001);
    *(float *)&v10[1].m_pPrev = forward.x + *(float *)&v10[1].m_pPrev;
    *(float *)&v10[1].m_pNext = *(float *)&v10[1].m_pNext + forward.y;
    *(float *)&v10[1].m_pSubTexture = *(float *)&v10[1].m_pSubTexture + forward.z;
    VectorNormalize(vec: (Vector *)&v10[1]);
    v14 = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
            a1: random,
            a2: 1115684864,
            a3: 1132462080);
    ++v8;
    *(float *)&v10[1].m_pPrev = v14 * *(float *)&v10[1].m_pPrev;
    *(float *)&v10[1].m_pNext = *(float *)&v10[1].m_pNext * v14;
    *(float *)&v10[1].m_pSubTexture = v14 * *(float *)&v10[1].m_pSubTexture;
    v10[2].m_pPrev = (Particle *)-12549889;
    LOWORD(v10[2].m_pNext) = 256;
    BYTE2(v10[2].m_pNext) = 0;
    v10[1].m_Pos.x = 0.0;
    v10[2].m_pSubTexture = nullptr;
    if ( v8 >= dot )
      goto LABEL_6;
  }
  if ( attachmentIndex != nullptr )
    CParticleEffect::Release(this: attachmentIndex);
}

//------------------------------------------------------------------------------
// Address: 0x1025F9A0
// Name: public: void CUtlLinkedList<struct CBreakableHelper::BreakableList_t,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<struct CBreakableHelper::BreakableList_t,unsigned short>,unsigned short>>::Unlink(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CBreakableHelper::BreakableList_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CBreakableHelper::BreakableList_t,unsigned short>,unsigned short>>::Unlink(
        CUtlLinkedList<CRagdollEntry,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CRagdollEntry,unsigned short>,unsigned short> > *this,
        unsigned __int16 elem)
{
  unsigned __int16 v2; // di
  UtlLinkedListElem_t<CRagdollEntry,unsigned short> *v3; // eax
  int m_Previous; // ebx
  unsigned __int16 m_Next; // dx

  v2 = elem;
  if ( elem < this->m_Memory.m_nAllocationCount && elem <= this->m_LastAlloc.index )
  {
    v3 = &this->m_Memory.m_pMemory[elem];
    if ( v3->m_Previous != elem )
    {
      m_Previous = v3->m_Previous;
      m_Next = v3->m_Next;
      if ( (_WORD)m_Previous == 0xFFFF )
      {
        this->m_Head = m_Next;
      }
      else
      {
        this->m_Memory.m_pMemory[m_Previous].m_Next = m_Next;
        v2 = elem;
      }
      if ( m_Next == 0xFFFF )
        this->m_Tail = m_Previous;
      else
        this->m_Memory.m_pMemory[m_Next].m_Previous = m_Previous;
      v3->m_Next = v2;
      v3->m_Previous = v2;
      --this->m_ElementCount;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102600B0
// Name: public: virtual void CTempEnts::PhysicsProp(int,int,class Vector const __near &,class QAngle const __near &,class Vector const __near &,int,int,struct color24)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTempEnts::PhysicsProp(
        CTempEnts *this,
        int modelindex,
        int skin,
        const Vector *pos,
        const QAngle *angles,
        const Vector *vel,
        char flags,
        unsigned int effects,
        color24 renderColor)
{
  C_PhysPropClientside *New; // esi
  const struct model_t *v10; // eax
  const char *v11; // eax
  const struct model_t *v12; // eax
  IPhysicsObject *m_pPhysicsObject; // ecx
  int BodygroupCount; // eax
  IUniformRandomStream *v15; // ecx
  int v16; // eax
  int v17; // [esp-10h] [ebp-2Ch]
  int v18; // [esp-Ch] [ebp-28h]
  int v19; // [esp-8h] [ebp-24h]
  Vector mins; // [esp+4h] [ebp-18h] BYREF
  Vector maxs; // [esp+10h] [ebp-Ch] BYREF

  New = C_PhysPropClientside::CreateNew();
  if ( New != nullptr )
  {
    v10 = modelinfo->GetModel(this: modelinfo, a2: modelindex);
    if ( v10 != nullptr )
    {
      v11 = modelinfo->GetModelName(this: modelinfo, a2: v10);
      C_BaseEntity::SetModelName(this: New, name: v11);
      C_BaseAnimating::SetSkin(this: New, iSkin: skin);
      C_BaseEntity::SetAbsOrigin(this: New, absOrigin: pos);
      C_BaseEntity::SetAbsAngles(this: New, absAngles: angles);
      New->SetPhysicsMode(this: &New->IBreakableWithPropData, a2: 3);
      C_BaseEntity::SetEffects(this: New, nEffects: effects);
      if ( New->m_clrRender.m_Value.r != renderColor.r )
        New->m_clrRender.m_Value.r = renderColor.r;
      if ( New->m_clrRender.m_Value.g != renderColor.g )
        New->m_clrRender.m_Value.g = renderColor.g;
      if ( New->m_clrRender.m_Value.b != renderColor.b )
        New->m_clrRender.m_Value.b = renderColor.b;
      if ( (flags & 1) != 0 )
      {
        C_BaseEntity::SetModelIndex(this: New, index: modelindex);
        C_BaseEntity::SetCollisionGroup(this: New, collisionGroup: 17);
        C_BaseEntity::SetAbsVelocity(this: New, vecAbsVelocity: vel);
        v12 = (const struct model_t *)((int (__thiscall *)(IClientRenderable *, int, int, int))New->GetModel)(
                                        a1: &New->IClientRenderable,
                                        a2: v17,
                                        a3: v18,
                                        a4: v19);
        if ( v12 != nullptr )
        {
          modelinfo->GetModelBounds(this: modelinfo, a2: v12, a3: &mins, a4: &maxs);
          CCollisionProperty::SetCollisionBounds(this: &New->m_Collision, &mins, &maxs);
        }
        New->Spawn(this: New);
        New->SetHealth(this: New, a2: 0);
        New->Break(this: New);
      }
      else if ( C_PhysPropClientside::Initialize(this: New) != 0 )
      {
        m_pPhysicsObject = New->m_pPhysicsObject;
        if ( m_pPhysicsObject != nullptr )
        {
          m_pPhysicsObject->AddVelocity(this: m_pPhysicsObject, a2: vel, a3: nullptr);
          if ( (flags & 2) != 0 )
          {
            BodygroupCount = C_BaseAnimating::GetBodygroupCount(this: New, iGroup: 0);
            v16 = _RandomInt(this: v15, a2: 0, a3: BodygroupCount - 1);
            C_BaseAnimating::SetBodygroup(this: New, iGroup: 0, iValue: v16);
          }
        }
        else
        {
          New->Release(this: &New->IClientNetworkable);
        }
      }
      else
      {
        ((void (__thiscall *)(IClientNetworkable *, int, int))New->Release)(
          a1: &New->IClientNetworkable,
          a2: v17,
          a3: v18);
      }
    }
    else
    {
      DevMsg(a1: "CTempEnts::PhysicsProp: model index %i not found\n", modelinfo);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10260280
// Name: public: virtual void CTempEnts::Sprite_Smoke(class C_LocalTempEntity __near *,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTempEnts::Sprite_Smoke(CTempEnts *this, C_LocalTempEntity *pTemp, float scale)
{
  unsigned __int8 v3; // al
  float flDuration; // [esp+8h] [ebp-8h]

  if ( pTemp != nullptr )
  {
    C_BaseEntity::SetRenderMode(this: pTemp, nRenderMode: kRenderTransAlpha, bForceUpdate: false);
    C_BaseEntity::SetRenderFX(this: pTemp, nRenderFX: kRenderFxNone, flStartTime: 3.4028235e38, flDuration: 0.0);
    pTemp->m_vecTempEntVelocity.x = 0.0;
    pTemp->m_vecTempEntVelocity.y = 0.0;
    pTemp->m_vecTempEntVelocity.z = 30.0;
    v3 = random->RandomInt(this: random, a2: 20, a3: 35);
    if ( pTemp->m_clrRender.m_Value.r != v3 )
      pTemp->m_clrRender.m_Value.r = v3;
    if ( pTemp->m_clrRender.m_Value.g != v3 )
      pTemp->m_clrRender.m_Value.g = v3;
    if ( pTemp->m_clrRender.m_Value.b != v3 )
      pTemp->m_clrRender.m_Value.b = v3;
    C_BaseEntity::SetRenderAlpha(this: pTemp, a: 255);
    flDuration = C_BaseEntity::GetLocalOriginDim(this: pTemp, iDim: 2) + 20.0;
    C_BaseEntity::SetLocalOriginDim(this: pTemp, iDim: 2, flValue: flDuration);
    pTemp->m_flSpriteScale = scale;
    pTemp->flags = 0x200000;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10260350
// Name: public: virtual void CTempEnts::MuzzleFlash(int,class CBaseHandle,int,bool)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CTempEnts::MuzzleFlash(
        CTempEnts *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>,
        int a4@<esi>,
        int type,
        CBaseHandle hEntity,
        CParticleEffect *attachmentIndex,
        bool firstPerson)
{
  switch ( type )
  {
    case 1:
      if ( firstPerson )
        CTempEnts::MuzzleFlash_Shotgun_Player(this, hEntity, (int)attachmentIndex);
      else
        CTempEnts::MuzzleFlash_Shotgun_NPC(this, a2, a3, a4, hEntity, attachmentIndex);
      break;
    case 2:
      if ( firstPerson )
        CTempEnts::MuzzleFlash_SMG1_Player(this, hEntity, (int)attachmentIndex);
      else
        CTempEnts::MuzzleFlash_SMG1_NPC(this, hEntity, (int)attachmentIndex);
      break;
    case 4:
      if ( firstPerson )
        CTempEnts::MuzzleFlash_Pistol_Player(this, hEntity, (int)attachmentIndex);
      else
        CTempEnts::MuzzleFlash_Pistol_NPC(this, hEntity, (int)attachmentIndex);
      break;
    case 5:
      if ( firstPerson )
        CTempEnts::MuzzleFlash_Combine_Player(this, hEntity, (int)attachmentIndex);
      else
        CTempEnts::MuzzleFlash_Combine_NPC(this, hEntity, (int)attachmentIndex);
      break;
    case 6:
      if ( firstPerson )
        CTempEnts::MuzzleFlash_357_Player(this, hEntity, (int)attachmentIndex);
      break;
    case 7:
      if ( !firstPerson )
        CTempEnts::MuzzleFlash_RPG_NPC(this, hEntity, (int)attachmentIndex);
      break;
    default:
      return;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10260450
// Name: public: virtual void CTempEnts::Sprite_Explode(class C_LocalTempEntity __near *,float,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTempEnts::Sprite_Explode(CTempEnts *this, C_LocalTempEntity *pTemp, float scale, char flags)
{
  int v4; // eax
  float flValue; // [esp+Ch] [ebp-8h]

  if ( pTemp != nullptr )
  {
    if ( (flags & 1) != 0 )
    {
      C_BaseEntity::SetRenderMode(this: pTemp, nRenderMode: kRenderNormal, bForceUpdate: false);
      C_BaseEntity::SetRenderAlpha(this: pTemp, a: 255);
    }
    else
    {
      if ( (flags & 0x10) != 0 )
        C_BaseEntity::SetRenderMode(this: pTemp, nRenderMode: kRenderTransAlpha, bForceUpdate: false);
      else
        C_BaseEntity::SetRenderMode(this: pTemp, nRenderMode: kRenderTransAdd, bForceUpdate: false);
      C_BaseEntity::SetRenderAlpha(this: pTemp, a: 180);
    }
    if ( (flags & 0x20) != 0 )
    {
      v4 = random->RandomInt(this: random, a2: 0, a3: 360);
      C_BaseEntity::SetLocalAnglesDim(this: pTemp, iDim: 2, flValue: (float)v4);
    }
    C_BaseEntity::SetRenderFX(this: pTemp, nRenderFX: kRenderFxNone, flStartTime: 3.4028235e38, flDuration: 0.0);
    pTemp->m_vecTempEntVelocity.x = 0.0;
    pTemp->m_vecTempEntVelocity.y = 0.0;
    pTemp->m_vecTempEntVelocity.z = 8.0;
    if ( pTemp->m_clrRender.m_Value.r != 0xFF )
      pTemp->m_clrRender.m_Value.r = -1;
    if ( pTemp->m_clrRender.m_Value.g != 0xFF )
      pTemp->m_clrRender.m_Value.g = -1;
    if ( pTemp->m_clrRender.m_Value.b != 0xFF )
      pTemp->m_clrRender.m_Value.b = -1;
    flValue = C_BaseEntity::GetLocalOriginDim(this: pTemp, iDim: 2) + 10.0;
    C_BaseEntity::SetLocalOriginDim(this: pTemp, iDim: 2, flValue);
    pTemp->m_flSpriteScale = scale;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10260560
// Name: public: virtual void CTempEnts::Clear(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTempEnts::Clear(CTempEnts *this)
{
  int i; // eax
  int v3; // esi
  C_LocalTempEntity *m_Element; // edi

  for ( i = this->m_TempEnts.m_Head; i != 0xFFFF; i = this->m_TempEnts.m_Memory.m_pMemory[v3].m_Next )
  {
    v3 = (unsigned __int16)i;
    m_Element = this->m_TempEnts.m_Memory.m_pMemory[v3].m_Element;
    if ( m_Element != nullptr )
      ((void (__thiscall *)(C_LocalTempEntity *, _DWORD))m_Element->dtr_IHandleEntity)(a1: m_Element, a2: 0);
    CUtlMemoryPool::Free(this: &this->m_TempEntsPool, memBlock: m_Element);
  }
  CUtlLinkedList<CEnvWindShared *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CEnvWindShared *,unsigned short>,unsigned short>>::RemoveAll(this: (CUtlLinkedList<C_BaseCombatWeapon *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<C_BaseCombatWeapon *,unsigned short>,unsigned short> > *)&this->m_TempEnts);
  CUtlLinkedList<CBreakableHelper::BreakableList_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CBreakableHelper::BreakableList_t,unsigned short>,unsigned short>>::RemoveAll(this: (CUtlLinkedList<CEnvWindShared::WindVariationEvent_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CEnvWindShared::WindVariationEvent_t,unsigned short>,unsigned short> > *)&g_BreakableHelper);
  g_BreakableHelper.m_nCurrentContext = 0;
}

//------------------------------------------------------------------------------
// Address: 0x102605D0
// Name: public: void CUtlLinkedList<struct CBreakableHelper::BreakableList_t,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<struct CBreakableHelper::BreakableList_t,unsigned short>,unsigned short>>::LinkBefore(unsigned short,unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CBreakableHelper::BreakableList_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CBreakableHelper::BreakableList_t,unsigned short>,unsigned short>>::LinkBefore(
        CUtlLinkedList<CRagdollEntry,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CRagdollEntry,unsigned short>,unsigned short> > *this,
        unsigned __int16 before,
        unsigned __int16 elem)
{
  UtlLinkedListElem_t<CRagdollEntry,unsigned short> *m_pMemory; // edx
  UtlLinkedListElem_t<CRagdollEntry,unsigned short> *v5; // ecx
  unsigned __int16 m_Tail; // ax
  UtlLinkedListElem_t<CRagdollEntry,unsigned short> *v7; // ebx

  CUtlLinkedList<CBreakableHelper::BreakableList_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CBreakableHelper::BreakableList_t,unsigned short>,unsigned short>>::Unlink(
    this,
    elem);
  m_pMemory = this->m_Memory.m_pMemory;
  v5 = &this->m_Memory.m_pMemory[elem];
  v5->m_Next = before;
  if ( before == 0xFFFF )
  {
    m_Tail = this->m_Tail;
    v5->m_Previous = m_Tail;
    this->m_Tail = elem;
  }
  else
  {
    v7 = &m_pMemory[before];
    m_Tail = v7->m_Previous;
    v5->m_Previous = m_Tail;
    v7->m_Previous = elem;
  }
  if ( m_Tail == 0xFFFF )
  {
    ++this->m_ElementCount;
    this->m_Head = elem;
  }
  else
  {
    m_pMemory[m_Tail].m_Next = elem;
    ++this->m_ElementCount;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10260660
// Name: public: virtual void CTempEnts::PlaySound(class C_LocalTempEntity __near *,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTempEnts::PlaySound(CTempEnts *this, C_LocalTempEntity *pTemp, float damp)
{
  int hitSound; // eax
  char v4; // bl
  const char *v5; // esi
  int v6; // eax
  int v7; // edi
  int v8; // eax
  float v9; // xmm0_4
  float v10; // xmm0_4
  double v11; // xmm0_8
  int pitch; // esi
  C_LocalTempEntity_vtbl *v13; // eax
  const Vector *(__thiscall *GetAbsOrigin)(IClientEntity *); // edx
  CLocalPlayerFilter filter; // [esp+8h] [ebp-11Ch] BYREF
  EmitSound_t ep; // [esp+28h] [ebp-FCh] BYREF
  CSoundParameters params; // [esp+70h] [ebp-B4h] BYREF
  float fvol; // [esp+130h] [ebp+Ch]

  hitSound = pTemp->hitSound;
  v4 = 0;
  if ( hitSound > 32 )
  {
    if ( hitSound > 1024 )
    {
      if ( hitSound == 2048 )
      {
        v5 = "Bounce.PistolShell";
      }
      else
      {
        if ( hitSound != 4096 )
          return;
        v5 = "Bounce.ShotgunShell";
      }
    }
    else if ( hitSound == 1024 )
    {
      v5 = "Bounce.RifleShell";
    }
    else
    {
      v6 = hitSound - 64;
      if ( v6 != 0 )
      {
        if ( v6 != 64 )
          return;
        v5 = "Bounce.ShotgunShell";
        v4 = 1;
      }
      else
      {
        v5 = "Bounce.Concrete";
      }
    }
LABEL_21:
    v7 = (int)fabs(pTemp->m_vecTempEntVelocity.z);
    if ( v4 != 0 )
    {
      if ( v7 >= 200 )
      {
LABEL_26:
        params.pitch = 100;
        params.pitchlow = 100;
        params.pitchhigh = 100;
        params.channel = 0;
        params.volume = 1.0;
        params.soundlevel = SNDLVL_NORM;
        params.soundname[0] = 0;
        params.play_to_owner_only = false;
        params.count = 0;
        params.delay_msec = 0;
        params.m_nSoundEntryVersion = 1;
        params.m_hSoundScriptHandle = -1;
        params.m_pOperatorsKV = nullptr;
        params.m_nRandomSeed = -1;
        if ( C_BaseEntity::GetParametersForSound(soundname: v5, &params, actormodel: nullptr) && damp > 0.0 )
        {
          v9 = (float)v7;
          if ( v4 != 0 )
          {
            v10 = v9 * 0.0028571428;
            if ( v10 <= 1.0 )
              v11 = v10;
            else
              v11 = 1.0;
          }
          else
          {
            v11 = v9 * 0.002222222222222222;
            if ( v11 > 1.0 )
              v11 = 1.0;
          }
          fvol = params.volume * v11;
          if ( random->RandomInt(this: random, a2: 0, a3: 3) != 0 || v4 != 0 )
            pitch = params.pitch;
          else
            pitch = random->RandomInt(this: random, a2: params.pitchlow, a3: params.pitchhigh);
          CLocalPlayerFilter::CLocalPlayerFilter(this: &filter);
          EmitSound_t::EmitSound_t(this: &ep);
          ep.m_pSoundName = params.soundname;
          ep.m_nChannel = params.channel;
          v13 = pTemp->C_BaseAnimating::C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable;
          ep.m_SoundLevel = params.soundlevel;
          GetAbsOrigin = v13->GetAbsOrigin;
          ep.m_flVolume = fvol;
          ep.m_nPitch = pitch;
          ep.m_pOrigin = GetAbsOrigin(this: pTemp);
          C_BaseEntity::EmitSound(&filter, iEntIndex: 0, params: &ep);
          CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>::~CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&ep.m_UtlVecSoundOrigin);
          C_RecipientFilter::~C_RecipientFilter(this: &filter);
        }
        return;
      }
      v8 = random->RandomInt(this: random, a2: 0, a3: 3);
    }
    else
    {
      v8 = random->RandomInt(this: random, a2: 0, a3: 5);
    }
    if ( v8 != 0 )
      return;
    goto LABEL_26;
  }
  if ( hitSound == 32 )
  {
    v5 = "Bounce.Shell";
    v4 = 1;
    goto LABEL_21;
  }
  switch ( hitSound )
  {
    case 1:
      v5 = "Bounce.Glass";
      goto LABEL_21;
    case 2:
      v5 = "Bounce.Metal";
      goto LABEL_21;
    case 4:
      v5 = "Bounce.Flesh";
      goto LABEL_21;
    case 8:
      v5 = "Bounce.Wood";
      goto LABEL_21;
    case 16:
      v5 = "Bounce.Shrapnel";
      goto LABEL_21;
    default:
      return;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10260940
// Name: public: void CBreakableHelper::Remove(class C_LocalTempEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBreakableHelper::Remove(CBreakableHelper *this, C_LocalTempEntity *entity)
{
  unsigned __int16 m_Head; // bx
  int v4; // esi
  UtlLinkedListElem_t<CBreakableHelper::BreakableList_t,unsigned short> *v5; // eax
  unsigned __int16 m_Next; // cx
  unsigned __int16 n; // [esp+8h] [ebp-4h]

  m_Head = this->m_Breakables.m_Head;
  if ( m_Head != 0xFFFF )
  {
    do
    {
      v4 = m_Head;
      v5 = &this->m_Breakables.m_Memory.m_pMemory[v4];
      m_Next = v5->m_Next;
      n = m_Next;
      if ( v5->m_Element.entity == entity )
      {
        CUtlLinkedList<CBreakableHelper::BreakableList_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CBreakableHelper::BreakableList_t,unsigned short>,unsigned short>>::Unlink(
          (CUtlLinkedList<CRagdollEntry,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CRagdollEntry,unsigned short>,unsigned short> > *)this,
          elem: m_Head);
        this->m_Breakables.m_Memory.m_pMemory[v4].m_Next = this->m_Breakables.m_FirstFree;
        m_Next = n;
        this->m_Breakables.m_FirstFree = m_Head;
      }
      m_Head = m_Next;
    }
    while ( m_Next != 0xFFFF );
  }
}

//------------------------------------------------------------------------------
// Address: 0x102609B0
// Name: private: void CTempEnts::TempEntFree(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTempEnts::TempEntFree(CTempEnts *this, unsigned __int16 index)
{
  CUtlLinkedList<C_LocalTempEntity *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<C_LocalTempEntity *,unsigned short>,unsigned short> > *p_m_TempEnts; // ebx
  int v3; // edi
  C_LocalTempEntity *m_Element; // esi
  CBaseHandle *v5; // eax

  p_m_TempEnts = &this->m_TempEnts;
  v3 = index;
  m_Element = this->m_TempEnts.m_Memory.m_pMemory[v3].m_Element;
  if ( m_Element != nullptr )
  {
    CUtlLinkedList<CEffectMaterial *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CEffectMaterial *,unsigned short>,unsigned short>>::Unlink(
      this: (CUtlLinkedList<C_RopeKeyframe *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<C_RopeKeyframe *,unsigned short>,unsigned short> > *)&this->m_TempEnts,
      elem: index);
    p_m_TempEnts->m_Memory.m_pMemory[v3].m_Next = p_m_TempEnts->m_FirstFree;
    p_m_TempEnts->m_FirstFree = index;
    C_BaseEntity::RemoveFromLeafSystem(this: m_Element);
    if ( (m_Element->flags & 0x8000000) != 0 )
    {
      if ( !m_Element->m_bParticleCollision )
        CParticleProperty::StopEmission(
          this: &m_Element->m_Particles,
          pEffect: nullptr,
          bWakeOnStop: false,
          bDestroyAsleepSystems: false,
          bForceRemoveInstantly: false,
          bPlayEndCap: false);
      v5 = m_Element->GetRefEHandle(this: m_Element);
      CBaseEntityList::RemoveEntity(this: (CBaseEntityList *)cl_entitylist.m_Index, handle: (CBaseHandle)v5->m_Index);
    }
    CBreakableHelper::Remove(this: &g_BreakableHelper, entity: m_Element);
    ((void (__thiscall *)(C_LocalTempEntity *, _DWORD))m_Element->dtr_IHandleEntity)(a1: m_Element, a2: 0);
    CUtlMemoryPool::Free(this: &this->m_TempEntsPool, memBlock: m_Element);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10260A70
// Name: private: bool CTempEnts::FreeLowPriorityTempEnt(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CTempEnts::FreeLowPriorityTempEnt(CTempEnts *this)
{
  int m_Head; // edi
  UtlLinkedListElem_t<C_LocalTempEntity *,unsigned short> *m_pMemory; // edx
  UtlLinkedListElem_t<C_LocalTempEntity *,unsigned short> *v4; // edx
  CUtlLinkedList<C_RopeKeyframe *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<C_RopeKeyframe *,unsigned short>,unsigned short> > *p_m_TempEnts; // ecx
  int v6; // ebx
  C_LocalTempEntity *m_Element; // esi
  CBaseHandle *v8; // eax

  m_Head = this->m_TempEnts.m_Head;
  if ( m_Head == 0xFFFF )
    return 0;
  m_pMemory = this->m_TempEnts.m_Memory.m_pMemory;
  while ( m_pMemory[(unsigned __int16)m_Head].m_Element->priority != 0 )
  {
    m_Head = m_pMemory[(unsigned __int16)m_Head].m_Next;
    if ( m_Head == 0xFFFF )
      return 0;
  }
  v4 = this->m_TempEnts.m_Memory.m_pMemory;
  p_m_TempEnts = (CUtlLinkedList<C_RopeKeyframe *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<C_RopeKeyframe *,unsigned short>,unsigned short> > *)&this->m_TempEnts;
  v6 = (unsigned __int16)m_Head;
  m_Element = v4[v6].m_Element;
  if ( m_Element != nullptr )
  {
    CUtlLinkedList<CEffectMaterial *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CEffectMaterial *,unsigned short>,unsigned short>>::Unlink(
      this: p_m_TempEnts,
      elem: m_Head);
    this->m_TempEnts.m_Memory.m_pMemory[v6].m_Next = this->m_TempEnts.m_FirstFree;
    this->m_TempEnts.m_FirstFree = m_Head;
    C_BaseEntity::RemoveFromLeafSystem(this: m_Element);
    if ( (m_Element->flags & 0x8000000) != 0 )
    {
      if ( !m_Element->m_bParticleCollision )
        CParticleProperty::StopEmission(
          this: &m_Element->m_Particles,
          pEffect: nullptr,
          bWakeOnStop: false,
          bDestroyAsleepSystems: false,
          bForceRemoveInstantly: false,
          bPlayEndCap: false);
      v8 = m_Element->GetRefEHandle(this: m_Element);
      CBaseEntityList::RemoveEntity(this: (CBaseEntityList *)cl_entitylist.m_Index, handle: (CBaseHandle)v8->m_Index);
    }
    CBreakableHelper::Remove(this: &g_BreakableHelper, entity: m_Element);
    ((void (__thiscall *)(C_LocalTempEntity *, _DWORD))m_Element->dtr_IHandleEntity)(a1: m_Element, a2: 0);
    CUtlMemoryPool::Free(this: &this->m_TempEntsPool, memBlock: m_Element);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10260B60
// Name: public: virtual void CTempEnts::Update(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTempEnts::Update(CTempEnts *this)
{
  float v2; // xmm0_4
  int m_Next; // eax
  UtlLinkedListElem_t<C_LocalTempEntity *,unsigned short> *v4; // ecx
  int v5; // esi
  int m_Head; // ebx
  UtlLinkedListElem_t<C_LocalTempEntity *,unsigned short> *m_pMemory; // ecx
  C_LocalTempEntity *m_Element; // esi
  int flags; // eax
  int next; // [esp+14h] [ebp-8h]

  if ( this->m_TempEnts.m_ElementCount == 0 || !engine->IsInGame(this: engine) )
    return;
  v2 = *(float *)(gpGlobals.m_Index + 16);
  gTempEntFrame = ((_BYTE)gTempEntFrame + 1) & 0x1F;
  if ( v2 != 0.0 )
  {
    m_Head = this->m_TempEnts.m_Head;
    if ( m_Head == 0xFFFF )
      return;
    while ( 1 )
    {
      m_pMemory = this->m_TempEnts.m_Memory.m_pMemory;
      m_Element = m_pMemory[(unsigned __int16)m_Head].m_Element;
      next = m_pMemory[(unsigned __int16)m_Head].m_Next;
      if ( m_Element->IsActive(this: m_Element)
        && m_Element->Frame(this: m_Element, a2: COERCE_FLOAT(LODWORD(v2)), a3: gTempEntFrame) )
      {
        if ( CTempEnts::AddVisibleTempEntity(this, pEntity: m_Element) != 0 )
          goto LABEL_15;
        flags = m_Element->flags;
        if ( (flags & 0x2000) != 0 )
          goto LABEL_15;
        m_Element->die = *(float *)(gpGlobals.m_Index + 12);
        m_Element->flags = flags & 0xFFFFFF7F;
      }
      CTempEnts::TempEntFree(this, index: m_Head);
LABEL_15:
      LOWORD(m_Head) = next;
      if ( next == 0xFFFF )
        return;
    }
  }
  m_Next = this->m_TempEnts.m_Head;
  if ( m_Next != 0xFFFF )
  {
    v4 = this->m_TempEnts.m_Memory.m_pMemory;
    do
    {
      v5 = (unsigned __int16)m_Next;
      CTempEnts::AddVisibleTempEntity(this, pEntity: v4[v5].m_Element);
      v4 = this->m_TempEnts.m_Memory.m_pMemory;
      m_Next = v4[v5].m_Next;
    }
    while ( m_Next != 0xFFFF );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10260CA0
// Name: protected: class C_LocalTempEntity __near * CTempEnts::TempEntAlloc(class Vector const __near &,struct model_t __near *)
// Source: json
//------------------------------------------------------------------------------
C_LocalTempEntity *__thiscall CTempEnts::TempEntAlloc(CTempEnts *this, const Vector *org, struct model_t *model)
{
  C_LocalTempEntity *v5; // eax
  C_BaseEntity *v6; // esi
  unsigned __int16 v7; // ax
  int v8; // ebx
  UtlLinkedListElem_t<C_LocalTempEntity *,unsigned short> *v9; // eax
  int v10; // ecx
  int v11; // eax

  if ( model != nullptr )
  {
    if ( this->m_TempEnts.m_ElementCount < 0x1F4u
      && (v5 = (C_LocalTempEntity *)CUtlMemoryPool::AllocZero(this: &this->m_TempEntsPool), v6 = v5, v5 != nullptr) )
    {
      C_LocalTempEntity::C_LocalTempEntity(this: v5);
      v7 = CUtlLinkedList<C_LocalTempEntity *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<C_LocalTempEntity *,unsigned short>,unsigned short>>::AllocInternal(
             this: &this->m_TempEnts,
             multilist: false);
      v8 = v7;
      if ( v7 != 0xFFFF )
      {
        CUtlLinkedList<CEnvWindShared *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CEnvWindShared *,unsigned short>,unsigned short>>::LinkBefore(
          this: (CUtlLinkedList<C_RopeKeyframe *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<C_RopeKeyframe *,unsigned short>,unsigned short> > *)&this->m_TempEnts,
          before: 0xFFFFu,
          elem: v7);
        v9 = &this->m_TempEnts.m_Memory.m_pMemory[v8];
        if ( v9 != nullptr )
          v9->m_Element = (C_LocalTempEntity *)v6;
      }
      ((void (__thiscall *)(C_BaseEntity *, struct model_t *, _DWORD))v6->IClientEntity::IClientUnknown::IHandleEntity::__vftable[1].TestHitboxes)(
        a1: v6,
        a2: model,
        a3: *(_DWORD *)(gpGlobals.m_Index + 12));
      v6[1].m_Particles.m_pOuter = nullptr;
      C_BaseEntity::SetAbsOrigin(this: v6, absOrigin: org);
      C_BaseEntity::AddToLeafSystem(this: v6, bRenderWithViewModels: false);
      v11 = _CommandLine(a1: v10);
      (*(void (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v11 + 12))(a1: v11, a2: "-tools", a3: 0);
      return (C_LocalTempEntity *)v6;
    }
    else
    {
      _DevWarning(a1: 1, a2: "Overflow %d temporary ents!\n", 500);
      return nullptr;
    }
  }
  else
  {
    _DevWarning(a1: 1, a2: "Can't create temporary entity with NULL model!\n");
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10260DA0
// Name: protected: class C_LocalTempEntity __near * CTempEnts::TempEntAllocHigh(class Vector const __near &,struct model_t __near *)
// Source: json
//------------------------------------------------------------------------------
C_LocalTempEntity *__thiscall CTempEnts::TempEntAllocHigh(CTempEnts *this, const Vector *org, struct model_t *model)
{
  C_BaseEntity *v5; // esi
  C_LocalTempEntity *v6; // eax
  C_LocalTempEntity *v7; // eax
  unsigned __int16 v8; // ax
  int v9; // ebx
  UtlLinkedListElem_t<C_LocalTempEntity *,unsigned short> *v10; // eax
  int v11; // ecx
  int v12; // eax

  if ( model == nullptr )
  {
    _DevWarning(a1: 1, a2: "temporary ent model invalid\n");
    return nullptr;
  }
  if ( this->m_TempEnts.m_ElementCount >= 0x1F4u )
  {
    v5 = nullptr;
    goto LABEL_7;
  }
  v6 = (C_LocalTempEntity *)CUtlMemoryPool::AllocZero(this: &this->m_TempEntsPool);
  v5 = v6;
  if ( v6 != nullptr )
  {
    C_LocalTempEntity::C_LocalTempEntity(this: v6);
LABEL_7:
    if ( v5 != nullptr )
      goto LABEL_14;
  }
  CTempEnts::FreeLowPriorityTempEnt(this);
  if ( this->m_TempEnts.m_ElementCount < 0x1F4u )
  {
    v7 = (C_LocalTempEntity *)CUtlMemoryPool::AllocZero(this: &this->m_TempEntsPool);
    v5 = v7;
    if ( v7 == nullptr )
    {
LABEL_13:
      _DevWarning(a1: 1, a2: "Couldn't alloc a high priority TENT (max %i)!\n", 500);
      return nullptr;
    }
    C_LocalTempEntity::C_LocalTempEntity(this: v7);
  }
  else
  {
    v5 = nullptr;
  }
  if ( v5 == nullptr )
    goto LABEL_13;
LABEL_14:
  v8 = CUtlLinkedList<C_LocalTempEntity *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<C_LocalTempEntity *,unsigned short>,unsigned short>>::AllocInternal(
         this: &this->m_TempEnts,
         multilist: false);
  v9 = v8;
  if ( v8 != 0xFFFF )
  {
    CUtlLinkedList<CEnvWindShared *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CEnvWindShared *,unsigned short>,unsigned short>>::LinkBefore(
      this: (CUtlLinkedList<C_RopeKeyframe *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<C_RopeKeyframe *,unsigned short>,unsigned short> > *)&this->m_TempEnts,
      before: 0xFFFFu,
      elem: v8);
    v10 = &this->m_TempEnts.m_Memory.m_pMemory[v9];
    if ( v10 != nullptr )
      v10->m_Element = (C_LocalTempEntity *)v5;
  }
  ((void (__thiscall *)(C_BaseEntity *, struct model_t *, _DWORD))v5->IClientEntity::IClientUnknown::IHandleEntity::__vftable[1].TestHitboxes)(
    a1: v5,
    a2: model,
    a3: *(_DWORD *)(gpGlobals.m_Index + 12));
  v5[1].m_Particles.m_pOuter = (C_BaseEntity *)1;
  C_BaseEntity::SetLocalOrigin(this: v5, origin: org);
  C_BaseEntity::AddToLeafSystem(this: v5, bRenderWithViewModels: false);
  v12 = _CommandLine(a1: v11);
  if ( (*(int (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v12 + 12))(a1: v12, a2: "-tools", a3: 0) != 0 )
    CBaseEntityList::AddNonNetworkableEntity(
      this: (CBaseEntityList *)cl_entitylist.m_Index,
      result: (CBaseHandle *)&model,
      pEnt: v5);
  return (C_LocalTempEntity *)v5;
}

//------------------------------------------------------------------------------
// Address: 0x10260EE0
// Name: public: virtual void CTempEnts::RocketFlare(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTempEnts::RocketFlare(CTempEnts *this, const Vector *pos)
{
  const struct model_t *v2; // esi
  int v3; // edi
  C_LocalTempEntity *v4; // eax
  C_LocalTempEntity *v5; // esi
  int v6; // edi

  v2 = engine->LoadModel(this: engine, a2: "sprites/animglow01.vmt", a3: 0);
  if ( v2 != nullptr )
  {
    v3 = modelinfo->GetModelFrameCount(this: modelinfo, a2: v2);
    v4 = CTempEnts::TempEntAlloc(this, org: pos, model: v2);
    v5 = v4;
    if ( v4 != nullptr )
    {
      v6 = v3 - 1;
      v4->m_flFrameMax = (float)v6;
      C_BaseEntity::SetRenderMode(this: v4, nRenderMode: kRenderGlow, bForceUpdate: false);
      C_BaseEntity::SetRenderFX(this: v5, nRenderFX: kRenderFxNoDissipation, flStartTime: 3.4028235e38, flDuration: 0.0);
      v5->tempent_renderamt = 255;
      v5->m_flFrameRate = 1.0;
      v5->m_flFrame = (float)random->RandomInt(this: random, a2: 0, a3: v6);
      v5->m_flSpriteScale = 1.0;
      C_BaseEntity::SetAbsOrigin(this: v5, absOrigin: pos);
      v5->die = *(float *)(gpGlobals.m_Index + 12) + 0.01;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10260FF0
// Name: public: void CClassMemoryPool<class C_LocalTempEntity>::Clear(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CClassMemoryPool<C_LocalTempEntity>::Clear(
        CClassMemoryPool<C_LocalTempEntity> *this@<ecx>,
        int a2@<edi>)
{
  CClassMemoryPool<C_LocalTempEntity> *v2; // ebx
  void *m_pHeadOfFreeList; // eax
  unsigned __int16 v4; // ax
  unsigned __int16 v5; // dx
  unsigned __int16 v6; // cx
  int v7; // esi
  UtlRBTreeNode_t<void *,unsigned short> *m_pMemory; // eax
  int v9; // esi
  int v10; // edx
  CUtlMemoryPool::CBlob *m_pNext; // edi
  char *m_Data; // esi
  unsigned int v13; // ebx
  CUtlRBTree<void *,unsigned short,bool (__cdecl*)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short> > freeBlocks; // [esp+Ch] [ebp-2Ch] BYREF
  CClassMemoryPool<C_LocalTempEntity> *v15; // [esp+28h] [ebp-10h]
  unsigned __int16 parent[2]; // [esp+2Ch] [ebp-Ch] BYREF
  void *pCurFree; // [esp+30h] [ebp-8h] BYREF
  bool leftchild; // [esp+37h] [ebp-1h] BYREF

  v2 = this;
  m_pHeadOfFreeList = this->m_pHeadOfFreeList;
  v15 = this;
  memset(&freeBlocks.m_Elements, 0, sizeof(freeBlocks.m_Elements));
  *(_DWORD *)&freeBlocks.m_Root = 0xFFFF;
  *(_DWORD *)&freeBlocks.m_FirstFree = -1;
  freeBlocks.m_pElements = nullptr;
  freeBlocks.m_LessFunc = (bool (__cdecl *)(void *const *, void *const *))CDefOps<C_BaseEntity *>::LessFunc;
  for ( pCurFree = m_pHeadOfFreeList; pCurFree != nullptr; pCurFree = *(void **)pCurFree )
  {
    *(_DWORD *)parent = 0xFFFF;
    leftchild = false;
    CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::FindInsertionPosition(
      this: &freeBlocks,
      insert: &pCurFree,
      parent,
      &leftchild);
    v4 = CUtlRBTree<CWorldListCache::Entry_t *,unsigned short,CWorldListCache::CEntryComparator,CUtlMemory<UtlRBTreeNode_t<CWorldListCache::Entry_t *,unsigned short>,unsigned short>>::NewNode(
           this: (CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> > *)&freeBlocks,
           (const char *)a2);
    v5 = parent[0];
    v6 = v4;
    v7 = 3 * v4;
    m_pMemory = freeBlocks.m_Elements.m_pMemory;
    v9 = 4 * v7;
    *(unsigned __int16 *)((char *)&freeBlocks.m_Elements.m_pMemory->m_Right + v9) = -1;
    *(unsigned __int16 *)((char *)&m_pMemory->m_Left + v9) = -1;
    *(unsigned __int16 *)((char *)&m_pMemory->m_Tag + v9) = 0;
    a2 = 0xFFFF;
    *(unsigned __int16 *)((char *)&m_pMemory->m_Parent + v9) = v5;
    if ( v5 == 0xFFFF )
    {
      freeBlocks.m_Root = v6;
    }
    else
    {
      v10 = v5;
      if ( leftchild )
        m_pMemory[v10].m_Left = v6;
      else
        m_pMemory[v10].m_Right = v6;
    }
    CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::InsertRebalance(
      this: &freeBlocks,
      elem: v6);
    ++freeBlocks.m_NumElements;
    if ( (UtlRBTreeNode_t<void *,unsigned short> *)((char *)freeBlocks.m_Elements.m_pMemory + v9) != (UtlRBTreeNode_t<void *,unsigned short> *)-8 )
      *(void **)((char *)&freeBlocks.m_Elements.m_pMemory->m_Data + v9) = pCurFree;
  }
  m_pNext = v2->m_BlobHead.m_pNext;
  if ( m_pNext != &v2->m_BlobHead )
  {
    do
    {
      m_Data = m_pNext->m_Data;
      v13 = (unsigned int)&m_pNext->m_Data[m_pNext->m_NumBytes];
      if ( (unsigned int)m_pNext->m_Data < v13 )
      {
        do
        {
          *(_DWORD *)parent = m_Data;
          if ( CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Find(
                 this: &freeBlocks,
                 search: (void *const *)parent) == 0xFFFF )
            (**(void (__thiscall ***)(char *, _DWORD))m_Data)(a1: m_Data, a2: 0);
          m_Data += 3440;
        }
        while ( (unsigned int)m_Data < v13 );
      }
      m_pNext = m_pNext->m_pNext;
    }
    while ( m_pNext != &v15->m_BlobHead );
    v2 = v15;
  }
  CUtlMemoryPool::Clear(this: v2);
  CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::RemoveAll(this: &freeBlocks);
  if ( freeBlocks.m_Elements.m_nGrowSize >= 0 && freeBlocks.m_Elements.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: freeBlocks.m_Elements.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x10261180
// Name: public: virtual CTempEnts::~CTempEnts(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTempEnts::~CTempEnts(CTempEnts *this)
{
  this->__vftable = (CTempEnts_vtbl *)&CTempEnts::`vftable';
  CClassMemoryPool<C_LocalTempEntity>::Clear(this: &this->m_TempEntsPool);
  CUtlLinkedList<CEnvWindShared *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CEnvWindShared *,unsigned short>,unsigned short>>::RemoveAll(this: (CUtlLinkedList<C_BaseCombatWeapon *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<C_BaseCombatWeapon *,unsigned short>,unsigned short> > *)&this->m_TempEnts);
  CUtlLinkedList<CEnvWindShared *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CEnvWindShared *,unsigned short>,unsigned short>>::RemoveAll(this: (CUtlLinkedList<C_BaseCombatWeapon *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<C_BaseCombatWeapon *,unsigned short>,unsigned short> > *)&this->m_TempEnts);
  if ( this->m_TempEnts.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_TempEnts.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_TempEnts.m_Memory.m_pMemory);
      this->m_TempEnts.m_Memory.m_pMemory = nullptr;
    }
    this->m_TempEnts.m_Memory.m_nAllocationCount = 0;
  }
  CUtlMemoryPool::~CUtlMemoryPool(this: &this->m_TempEntsPool);
  this->__vftable = (CTempEnts_vtbl *)&ITempEnts::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x102611E0
// Name: public: virtual void CTempEnts::FizzEffect(class C_BaseEntity __near *,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTempEnts::FizzEffect(
        CTempEnts *this,
        C_BaseEntity *pent,
        const struct model_t *modelIndex,
        int density,
        int current)
{
  const struct model_t *(__thiscall *GetModel)(IClientRenderable *); // edx
  IVModelInfoClient_vtbl *v6; // esi
  int v7; // ebx
  int v8; // eax
  int v9; // esi
  int v10; // edi
  int v11; // eax
  int v12; // eax
  C_LocalTempEntity *v13; // eax
  C_LocalTempEntity *v14; // esi
  int v15; // eax
  float v16; // xmm1_4
  float v17; // xmm2_4
  float v18; // xmm1_4
  Vector maxs; // [esp+48h] [ebp-3Ch] BYREF
  Vector origin; // [esp+54h] [ebp-30h] BYREF
  Vector mins; // [esp+60h] [ebp-24h] BYREF
  float maxHeight; // [esp+6Ch] [ebp-18h]
  CTempEnts *v23; // [esp+70h] [ebp-14h]
  int depth; // [esp+74h] [ebp-10h]
  float speed; // [esp+78h] [ebp-Ch]
  float xspeed; // [esp+7Ch] [ebp-8h]
  float yspeed; // [esp+80h] [ebp-4h]
  C_BaseEntity *penta; // [esp+8Ch] [ebp+8h]
  const struct model_t *model; // [esp+90h] [ebp+Ch]
  int densitya; // [esp+94h] [ebp+10h]
  float frameCounta; // [esp+98h] [ebp+14h]
  int frameCount; // [esp+98h] [ebp+14h]

  GetModel = pent->GetModel;
  v23 = this;
  if ( (int)GetModel(this: &pent->IClientRenderable) != 0 && modelIndex != nullptr )
  {
    model = modelinfo->GetModel(this: modelinfo, a2: modelIndex);
    if ( model != nullptr )
    {
      v6 = modelinfo->__vftable;
      v7 = density + 1;
      v8 = ((int (__thiscall *)(IClientRenderable *, Vector *, Vector *))pent->GetModel)(
             a1: &pent->IClientRenderable,
             a2: &mins,
             a3: &maxs);
      ((void (__thiscall *)(IVModelInfoClient *, int))v6->GetModelBounds)(a1: modelinfo, a2: v8);
      maxHeight = maxs.z - mins.z;
      v9 = (int)(float)(maxs.x - mins.x);
      depth = (int)(float)(maxs.y - mins.y);
      speed = (float)current;
      frameCounta = C_BaseEntity::GetLocalAngles(this: pent)->y * 3.141592653589793 * 0.005555555555555556;
      xspeed = cos(frameCounta);
      yspeed = sin(frameCounta);
      xspeed = xspeed * speed;
      yspeed = yspeed * speed;
      v10 = 0;
      frameCount = modelinfo->GetModelFrameCount(this: modelinfo, a2: model);
      if ( density + 1 > 0 )
      {
        penta = (C_BaseEntity *)(v9 - 1);
        densitya = depth - 1;
        do
        {
          v11 = random->RandomInt(this: random, a2: 0, a3: (int)penta);
          origin.x = (float)v11 + mins.x;
          v12 = random->RandomInt(this: random, a2: 0, a3: densitya);
          origin.y = (float)v12 + mins.y;
          origin.z = mins.z;
          v13 = CTempEnts::TempEntAlloc(this: v23, org: &origin, model);
          v14 = v13;
          if ( v13 == nullptr )
            break;
          v13->flags |= 1u;
          v13->x = origin.x;
          v13->y = origin.y;
          v15 = random->RandomInt(this: random, a2: 80, a3: 140);
          v16 = yspeed;
          v17 = xspeed;
          v14->m_vecTempEntVelocity.z = (float)v15;
          v14->m_vecTempEntVelocity.y = v16;
          v18 = maxHeight;
          v14->m_vecTempEntVelocity.x = v17;
          v14->die = (float)((float)(v18 / (float)v15) + *(float *)(gpGlobals.m_Index + 12)) - 0.1;
          v14->m_flFrame = (float)random->RandomInt(this: random, a2: 0, a3: frameCount - 1);
          v14->m_flSpriteScale = 1.0
                               / ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
                                   a1: random,
                                   a2: 0x40000000,
                                   a3: 1084227584);
          C_BaseEntity::SetRenderMode(this: v14, nRenderMode: kRenderTransAlpha, bForceUpdate: false);
          C_BaseEntity::SetRenderAlpha(this: v14, a: 255);
          ++v10;
        }
        while ( v10 < v7 );
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102614A0
// Name: public: virtual void CTempEnts::Bubbles(class Vector const __near &,class Vector const __near &,float,int,int,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTempEnts::Bubbles(
        CTempEnts *this,
        const Vector *mins,
        const Vector *maxs,
        float height,
        int modelIndex,
        int count,
        float speed)
{
  const struct model_t *v7; // esi
  int v8; // eax
  int y; // edx
  float v10; // xmm0_4
  int z; // eax
  C_LocalTempEntity *v12; // eax
  C_LocalTempEntity *v13; // esi
  int v14; // eax
  float v15; // xmm1_4
  float v16; // xmm1_4
  int v17; // eax
  Vector origin; // [esp+4Ch] [ebp-24h] BYREF
  int frameCount; // [esp+58h] [ebp-18h]
  float v20; // [esp+5Ch] [ebp-14h]
  CTempEnts *v21; // [esp+60h] [ebp-10h]
  const struct model_t *model; // [esp+64h] [ebp-Ch]
  int i; // [esp+68h] [ebp-8h]
  float sine; // [esp+6Ch] [ebp-4h]
  float cosine; // [esp+84h] [ebp+14h]

  v21 = this;
  if ( modelIndex != 0 )
  {
    v7 = modelinfo->GetModel(this: modelinfo, a2: modelIndex);
    model = v7;
    if ( v7 != nullptr )
    {
      frameCount = modelinfo->GetModelFrameCount(this: modelinfo, a2: v7);
      i = 0;
      if ( count > 0 )
      {
        while ( 1 )
        {
          v8 = ((int (__stdcall *)(int, int))random->RandomInt)(a1: (int)mins->x, a2: (int)maxs->x);
          y = (int)maxs->y;
          origin.x = (float)v8;
          v10 = (float)((int (__stdcall *)(int, int))random->RandomInt)(a1: (int)mins->y, a2: y);
          z = (int)maxs->z;
          origin.y = v10;
          origin.z = (float)((int (__stdcall *)(int, int))random->RandomInt)(a1: (int)mins->z, a2: z);
          v12 = CTempEnts::TempEntAlloc(this: v21, org: &origin, model: v7);
          v13 = v12;
          if ( v12 == nullptr )
            break;
          v12->flags |= 1u;
          v12->x = origin.x;
          v12->y = origin.y;
          v20 = (float)random->RandomInt(this: random, a2: -3, a3: 3);
          cosine = cos(v20);
          sine = sin(v20);
          v14 = random->RandomInt(this: random, a2: 80, a3: 140);
          v15 = sine * speed;
          v13->m_vecTempEntVelocity.x = cosine * speed;
          v13->m_vecTempEntVelocity.y = v15;
          v13->m_vecTempEntVelocity.z = (float)v14;
          v16 = (float)((float)(height - (float)(origin.z - mins->z)) / (float)v14) + *(float *)(gpGlobals.m_Index + 12);
          v17 = frameCount;
          v13->die = v16 - 0.1;
          v13->m_flFrame = (float)random->RandomInt(this: random, a2: 0, a3: v17 - 1);
          v13->m_flSpriteScale = 1.0
                               / ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
                                   a1: random,
                                   a2: 1082130432,
                                   a3: 1098907648);
          C_BaseEntity::SetRenderMode(this: v13, nRenderMode: kRenderTransAlpha, bForceUpdate: false);
          if ( v13->m_clrRender.m_Value.r != 0xFF )
            v13->m_clrRender.m_Value.r = -1;
          if ( v13->m_clrRender.m_Value.g != 0xFF )
            v13->m_clrRender.m_Value.g = -1;
          if ( v13->m_clrRender.m_Value.b != 0xFF )
            v13->m_clrRender.m_Value.b = -1;
          C_BaseEntity::SetRenderAlpha(this: v13, a: 192);
          if ( ++i >= count )
            break;
          v7 = model;
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10261710
// Name: public: virtual void CTempEnts::BubbleTrail(class Vector const __near &,class Vector const __near &,float,int,int,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTempEnts::BubbleTrail(
        CTempEnts *this,
        const Vector *start,
        const Vector *end,
        float flWaterZ,
        int modelIndex,
        int count,
        float speed)
{
  const struct model_t *v7; // esi
  C_LocalTempEntity *v9; // eax
  C_LocalTempEntity *v10; // esi
  double v11; // xmm0_8
  int v12; // eax
  double v13; // xmm0_8
  float v14; // [esp+3Ch] [ebp-2Ch]
  Vector origin; // [esp+48h] [ebp-20h] BYREF
  int frameCount; // [esp+54h] [ebp-14h]
  float zspeed; // [esp+58h] [ebp-10h]
  CTempEnts *v18; // [esp+5Ch] [ebp-Ch]
  const struct model_t *model; // [esp+60h] [ebp-8h]
  int i; // [esp+64h] [ebp-4h]
  float dist; // [esp+74h] [ebp+Ch]
  unsigned int angle; // [esp+7Ch] [ebp+14h]

  v18 = this;
  if ( modelIndex != 0 )
  {
    v7 = modelinfo->GetModel(this: modelinfo, a2: modelIndex);
    model = v7;
    if ( v7 != nullptr )
    {
      frameCount = modelinfo->GetModelFrameCount(this: modelinfo, a2: v7);
      i = 0;
      if ( count > 0 )
      {
        while ( 1 )
        {
          dist = ((double (__thiscall *)(IUniformRandomStream *, _DWORD, int))random->RandomFloat)(
                   a1: random,
                   a2: 0,
                   a3: 1065353216);
          origin.x = (float)((float)(end->x - start->x) * dist) + start->x;
          origin.y = (float)((float)(end->y - start->y) * dist) + start->y;
          origin.z = (float)((float)(end->z - start->z) * dist) + start->z;
          v9 = CTempEnts::TempEntAlloc(this: v18, org: &origin, model: v7);
          v10 = v9;
          if ( v9 == nullptr )
            break;
          v9->flags |= 1u;
          v9->x = origin.x;
          v9->y = origin.y;
          *(float *)&angle = (float)random->RandomInt(this: random, a2: -3, a3: 3);
          zspeed = (float)random->RandomInt(this: random, a2: 80, a3: 140);
          __libm_sse2_cos(X: (__m128i)_mm_cvtps_pd((__m128)angle));
          *(float *)&v11 = v11;
          v14 = *(float *)&v11 * speed;
          __libm_sse2_sin(X: (__m128i)_mm_cvtps_pd((__m128)angle));
          v12 = frameCount;
          *(float *)&v13 = v13;
          v10->m_vecTempEntVelocity.y = *(float *)&v13 * speed;
          *(float *)&v13 = zspeed;
          v10->m_vecTempEntVelocity.x = v14;
          v10->m_vecTempEntVelocity.z = *(float *)&v13;
          v10->die = (float)((float)((float)(flWaterZ - origin.z) / *(float *)&v13) + *(float *)(gpGlobals.m_Index + 12))
                   - 0.1;
          v10->m_flFrame = (float)random->RandomInt(this: random, a2: 0, a3: v12 - 1);
          v10->m_flSpriteScale = 1.0
                               / ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
                                   a1: random,
                                   a2: 1082130432,
                                   a3: 1090519040);
          C_BaseEntity::SetRenderMode(this: v10, nRenderMode: kRenderTransAlpha, bForceUpdate: false);
          if ( v10->m_clrRender.m_Value.r != 0xFF )
            v10->m_clrRender.m_Value.r = -1;
          if ( v10->m_clrRender.m_Value.g != 0xFF )
            v10->m_clrRender.m_Value.g = -1;
          if ( v10->m_clrRender.m_Value.b != 0xFF )
            v10->m_clrRender.m_Value.b = -1;
          C_BaseEntity::SetRenderAlpha(this: v10, a: 192);
          if ( ++i >= count )
            break;
          v7 = model;
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10261990
// Name: public: virtual void CTempEnts::BreakModel(class Vector const __near &,class QAngle const __near &,class Vector const __near &,class Vector const __near &,float,float,int,int,char)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CTempEnts::BreakModel(
        CTempEnts *this@<ecx>,
        float a2@<ebx>,
        float a3@<edi>,
        int a4@<esi>,
        const Vector *pos,
        const QAngle *angles,
        const Vector *size,
        const Vector *dir,
        float randRange,
        float life,
        int count,
        int modelIndex,
        char flags)
{
  const struct model_t *v13; // edi
  int v14; // ebx
  int (__thiscall *GetModelFrameCount)(struct IVModelInfoClient *, const struct model_t *); // eax
  const Vector *v16; // esi
  int m_nValue; // eax
  C_LocalTempEntity *v18; // eax
  C_LocalTempEntity *v19; // esi
  int v20; // eax
  float z; // xmm0_4
  float (__thiscall *RandomFloat)(IUniformRandomStream *, float, float); // eax
  double v23; // st7
  IUniformRandomStream_vtbl *v24; // edx
  double v25; // st7
  IUniformRandomStream_vtbl *v26; // edx
  double v27; // st7
  double v28; // st7
  double v29; // st7
  double v30; // st6
  unsigned int m_nCurrentContext; // ebx
  unsigned __int16 v32; // ax
  int v33; // edi
  UtlLinkedListElem_t<CBreakableHelper::BreakableList_t,unsigned short> *v34; // eax
  matrix3x4_t transform; // [esp+84h] [ebp-70h] BYREF
  Vector vecSpot; // [esp+B4h] [ebp-40h] BYREF
  float v40; // [esp+C0h] [ebp-34h]
  float v41; // [esp+C4h] [ebp-30h]
  Vector vecLocalSpot; // [esp+CCh] [ebp-28h] BYREF
  float v43; // [esp+D8h] [ebp-1Ch]
  float y; // [esp+DCh] [ebp-18h]
  int v45; // [esp+E0h] [ebp-14h]
  CTempEnts *v46; // [esp+E4h] [ebp-10h]
  const struct model_t *pModel; // [esp+E8h] [ebp-Ch]
  int v48; // [esp+ECh] [ebp-8h]
  int frameCount; // [esp+F0h] [ebp-4h]
  int i; // [esp+FCh] [ebp+8h]
  float anglesa; // [esp+100h] [ebp+Ch]
  float anglesb; // [esp+100h] [ebp+Ch]
  float anglesc; // [esp+100h] [ebp+Ch]
  float anglesd; // [esp+100h] [ebp+Ch]

  v46 = this;
  if ( modelIndex != 0 )
  {
    v13 = modelinfo->GetModel(this: modelinfo, a2: modelIndex);
    pModel = v13;
    if ( v13 != nullptr )
    {
      v14 = flags;
      GetModelFrameCount = modelinfo->GetModelFrameCount;
      v48 = flags;
      v16 = size;
      frameCount = GetModelFrameCount(this: modelinfo, a2: v13);
      if ( count == 0 )
        count = (int)((float)((float)((float)(size->x + size->z) * size->y) + (float)(size->x * size->z))
                    * 0.002314814814814815);
      if ( func_break_max_pieces.m_pParent != nullptr )
        m_nValue = func_break_max_pieces.m_pParent->m_Value.m_nValue;
      else
        m_nValue = 0;
      if ( count > m_nValue )
      {
        if ( func_break_max_pieces.m_pParent != nullptr )
          count = func_break_max_pieces.m_pParent->m_Value.m_nValue;
        else
          count = 0;
      }
      AngleMatrix(angles, position: pos, matrix: &transform);
      i = 0;
      if ( count > 0 )
      {
        while ( 1 )
        {
          anglesa = v16->x;
          vecLocalSpot.x = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
                             a1: random,
                             a2: -1090519040,
                             a3: 1056964608)
                         * anglesa;
          anglesb = v16->y;
          vecLocalSpot.y = ((double (__stdcall *)(int, int))random->RandomFloat)(a1: -1090519040, a2: 1056964608)
                         * anglesb;
          anglesc = v16->z;
          vecLocalSpot.z = ((double (__stdcall *)(int, int))random->RandomFloat)(a1: -1090519040, a2: 1056964608)
                         * anglesc;
          VectorTransform(in1: &vecLocalSpot.x, in2: &transform, out: &vecSpot.x);
          v18 = CTempEnts::TempEntAlloc(this: v46, org: &vecSpot, model: v13);
          v19 = v18;
          if ( v18 == nullptr )
            break;
          v18->hitSound = v14;
          if ( ((int (__thiscall *)(IVModelInfoClient *, const struct model_t *, int, _DWORD, _DWORD))modelinfo->GetModelType)(
                 a1: modelinfo,
                 a2: v13,
                 a3: a4,
                 a4: LODWORD(a2),
                 a5: LODWORD(a3)) == 2 )
          {
            v19->m_flFrame = (float)random->RandomInt(this: random, a2: 0, a3: frameCount - 1);
          }
          else if ( modelinfo->GetModelType(this: modelinfo, a2: v13) == 3 )
          {
            v20 = random->RandomInt(this: random, a2: 0, a3: frameCount - 1);
            C_BaseAnimating::SetBody(this: v19, iBody: v20);
          }
          v19->flags |= 0xA8u;
          if ( random->RandomInt(this: random, a2: 0, a3: 255) < 200 )
          {
            v19->flags |= 4u;
            v19->m_vecTempEntAngVelocity.x = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
                                               a1: random,
                                               a2: -1015021568,
                                               a3: 1132396544);
            v19->m_vecTempEntAngVelocity.y = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
                                               a1: random,
                                               a2: -1015021568,
                                               a3: 1132396544);
            v19->m_vecTempEntAngVelocity.z = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
                                               a1: random,
                                               a2: -1015021568,
                                               a3: 1132396544);
          }
          if ( random->RandomInt(this: random, a2: 0, a3: 255) < 100 && (flags & 0x10) != 0 )
            v19->flags |= 0x10u;
          if ( (flags & 0x21) != 0 )
          {
            C_BaseEntity::SetRenderMode(this: v19, nRenderMode: kRenderTransTexture, bForceUpdate: false);
            C_BaseEntity::SetRenderAlpha(this: v19, a: 128);
            v19->tempent_renderamt = 128;
            v19->bounceFactor = 0.30000001;
          }
          else
          {
            C_BaseEntity::SetRenderMode(this: v19, nRenderMode: kRenderNormal, bForceUpdate: false);
            v19->tempent_renderamt = 255;
          }
          z = dir->z;
          y = dir->y;
          anglesd = dir->x;
          RandomFloat = random->RandomFloat;
          v43 = z;
          a3 = randRange;
          v45 = LODWORD(randRange) ^ _mask__NegFloat_;
          v23 = ((double (__thiscall *)(IUniformRandomStream *, unsigned int))RandomFloat)(
                  a1: random,
                  a2: LODWORD(randRange) ^ (unsigned int)_mask__NegFloat_);
          v24 = random->__vftable;
          v40 = v23 + anglesd;
          a2 = randRange;
          a4 = v45;
          v25 = ((double (__thiscall *)(IUniformRandomStream *))v24->RandomFloat)(a1: random);
          v26 = random->__vftable;
          v41 = v25 + y;
          v27 = ((double (__thiscall *)(IUniformRandomStream *, _DWORD, _DWORD))v26->RandomFloat)(
                  a1: random,
                  a2: 0,
                  a3: LODWORD(randRange));
          v28 = v27 + v43;
          v19->m_vecTempEntVelocity.x = v40;
          v19->m_vecTempEntVelocity.y = v41;
          v19->m_vecTempEntVelocity.z = v28;
          v29 = ((double (__thiscall *)(IUniformRandomStream *, _DWORD, int))random->RandomFloat)(
                  a1: random,
                  a2: 0,
                  a3: 1065353216);
          v30 = *(float *)(gpGlobals.m_Index + 12);
          v19->m_pfnDrawHelper = BreakModelDrawHelper;
          v19->die = v29 + v30 + life;
          if ( (flags & 0x80) == 0 )
            ++g_BreakableHelper.m_nCurrentContext;
          m_nCurrentContext = g_BreakableHelper.m_nCurrentContext;
          v32 = CUtlLinkedList<CBreakableHelper::BreakableList_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CBreakableHelper::BreakableList_t,unsigned short>,unsigned short>>::AllocInternal(
                  this: &g_BreakableHelper.m_Breakables,
                  multilist: false);
          v33 = v32;
          if ( v32 != 0xFFFF )
          {
            CUtlLinkedList<CBreakableHelper::BreakableList_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CBreakableHelper::BreakableList_t,unsigned short>,unsigned short>>::LinkBefore(
              this: (CUtlLinkedList<CRagdollEntry,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CRagdollEntry,unsigned short>,unsigned short> > *)&g_BreakableHelper,
              before: 0xFFFFu,
              elem: v32);
            v34 = &g_BreakableHelper.m_Breakables.m_Memory.m_pMemory[v33];
            if ( v34 != nullptr )
            {
              v34->m_Element.context = m_nCurrentContext;
              v34->m_Element.entity = v19;
            }
          }
          if ( ++i >= count )
            break;
          v14 = v48;
          v13 = pModel;
          v16 = size;
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10261E50
// Name: public: virtual class C_LocalTempEntity __near * CTempEnts::ClientProjectile(class Vector const __near &,class Vector const __near &,class Vector const __near &,int,int,class C_BaseEntity __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
C_LocalTempEntity *__thiscall CTempEnts::ClientProjectile(
        CTempEnts *this,
        const Vector *vecOrigin,
        const Vector *vecVelocity,
        const Vector *vecAcceleration,
        int modelIndex,
        int lifetime,
        C_BaseEntity *pOwner,
        const char *pszImpactEffect,
        const char *pszParticleEffect)
{
  int v9; // esi
  struct model_t *v11; // eax
  C_LocalTempEntity *v13; // esi
  C_BaseEntity *v14; // edi
  __int16 v15; // ax
  const char *v16; // edi
  QAngle angles; // [esp+Ch] [ebp-Ch] BYREF

  v9 = modelIndex;
  if ( modelIndex == 0 )
    return nullptr;
  v11 = modelinfo->GetModel(this: modelinfo, a2: modelIndex);
  if ( v11 == nullptr )
  {
    _Warning(a1: "ClientProjectile: No model %d!\n", v9);
    return nullptr;
  }
  v13 = CTempEnts::TempEntAlloc(this, org: vecOrigin, model: v11);
  if ( v13 == nullptr )
    return nullptr;
  v13->m_vecTempEntVelocity = *vecVelocity;
  v13->m_vecTempEntAcceleration = *vecAcceleration;
  VectorAngles(forward: vecVelocity, &angles);
  C_BaseEntity::SetAbsAngles(this: v13, absAngles: &angles);
  C_BaseEntity::SetAbsOrigin(this: v13, absOrigin: vecOrigin);
  v14 = pOwner;
  v13->die = (float)lifetime + *(float *)(gpGlobals.m_Index + 12);
  v13->flags = 67375104;
  if ( v14 != nullptr )
    v15 = v14->entindex(this: &v14->IClientNetworkable);
  else
    v15 = 0;
  v13->clientIndex = v15;
  C_BaseEntity::SetOwnerEntity(this: v13, pOwner: v14);
  v16 = pszParticleEffect;
  v13->m_pszImpactEffect = pszImpactEffect;
  if ( v16 != nullptr )
  {
    CBaseEntityList::AddNonNetworkableEntity(
      this: (CBaseEntityList *)cl_entitylist.m_Index,
      result: (CBaseHandle *)&modelIndex,
      pEnt: v13);
    CParticleProperty::Create(
      this: &v13->m_Particles,
      pszParticleName: v16,
      iAttachType: PATTACH_ABSORIGIN_FOLLOW,
      iAttachmentPoint: -1,
      vecOriginOffset: vec3_origin,
      matOffset: nullptr);
    v13->flags |= 0x8000000u;
    v13->m_pszParticleEffect = v16;
  }
  return v13;
}

//------------------------------------------------------------------------------
// Address: 0x10261FB0
// Name: public: virtual class C_LocalTempEntity __near * CTempEnts::TempSprite(class Vector const __near &,class Vector const __near &,float,int,int,int,float,float,int,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
C_LocalTempEntity *__thiscall CTempEnts::TempSprite(
        CTempEnts *this,
        const Vector *pos,
        const Vector *dir,
        float scale,
        int modelIndex,
        RenderMode_t rendermode,
        RenderFx_t renderfx,
        float a,
        float life,
        int flags,
        const Vector *normal)
{
  const struct model_t *v13; // esi
  int v14; // ebx
  C_LocalTempEntity *v15; // eax
  C_LocalTempEntity *v16; // esi

  if ( modelIndex == 0 )
    return nullptr;
  v13 = modelinfo->GetModel(this: modelinfo, a2: modelIndex);
  if ( v13 == nullptr )
  {
    _Warning(a1: "No model %d!\n", modelIndex);
    return nullptr;
  }
  v14 = modelinfo->GetModelFrameCount(this: modelinfo, a2: v13);
  v15 = CTempEnts::TempEntAlloc(this, org: pos, model: v13);
  v16 = v15;
  if ( v15 == nullptr )
    return nullptr;
  v15->m_flFrameMax = (float)(v14 - 1);
  v15->m_flFrameRate = 10.0;
  C_BaseEntity::SetRenderMode(this: v15, nRenderMode: rendermode, bForceUpdate: false);
  C_BaseEntity::SetRenderFX(this: v16, nRenderFX: renderfx, flStartTime: 3.4028235e38, flDuration: 0.0);
  v16->m_flSpriteScale = scale;
  v16->tempent_renderamt = (int)(float)(a * 255.0);
  v16->m_vecNormal = *normal;
  if ( v16->m_clrRender.m_Value.r != 0xFF )
    v16->m_clrRender.m_Value.r = -1;
  if ( v16->m_clrRender.m_Value.g != 0xFF )
    v16->m_clrRender.m_Value.g = -1;
  if ( v16->m_clrRender.m_Value.b != 0xFF )
    v16->m_clrRender.m_Value.b = -1;
  C_BaseEntity::SetRenderAlpha(this: v16, a: (unsigned __int8)(int)(float)(a * 255.0));
  v16->flags |= flags;
  v16->m_vecTempEntVelocity = *dir;
  C_BaseEntity::SetLocalOrigin(this: v16, origin: pos);
  if ( life == 0.0 )
    v16->die = (double)v14 * 0.1 + *(float *)(gpGlobals.m_Index + 12) + 1.0;
  else
    v16->die = *(float *)(gpGlobals.m_Index + 12) + life;
  v16->m_flFrame = 0.0;
  return v16;
}

//------------------------------------------------------------------------------
// Address: 0x10262190
// Name: public: virtual void CTempEnts::Sprite_Spray(class Vector const __near &,class Vector const __near &,int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CTempEnts::Sprite_Spray(
        CTempEnts *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>,
        int a4@<esi>,
        const Vector *pos,
        const Vector *dir,
        const struct model_t *modelIndex,
        int count,
        int speed,
        int iRand)
{
  struct model_t *v11; // esi
  int v12; // eax
  int v13; // ebx
  C_LocalTempEntity *v15; // eax
  C_LocalTempEntity *v16; // esi
  float v17; // xmm0_4
  float flDuration; // [esp+30h] [ebp-20h]
  float velocity; // [esp+34h] [ebp-1Ch]
  float velocity_4; // [esp+38h] [ebp-18h]
  float velocity_8; // [esp+3Ch] [ebp-14h]
  int frameCount; // [esp+40h] [ebp-10h]
  float znoise; // [esp+4Ch] [ebp-4h]
  float dira; // [esp+5Ch] [ebp+Ch]
  float dirb; // [esp+5Ch] [ebp+Ch]
  float dirc; // [esp+5Ch] [ebp+Ch]
  float dird; // [esp+5Ch] [ebp+Ch]
  const struct model_t *pModel; // [esp+60h] [ebp+10h]
  float noise; // [esp+6Ch] [ebp+1Ch]

  noise = (float)iRand * 0.0099999998;
  znoise = noise * 1.5;
  if ( (float)(noise * 1.5) > 1.0 )
    znoise = 1.0;
  v11 = (struct model_t *)((int (__thiscall *)(IVModelInfoClient *, const struct model_t *, int, int))modelinfo->GetModel)(
                            a1: modelinfo,
                            a2: modelIndex,
                            a3,
                            a4);
  pModel = v11;
  if ( v11 != nullptr )
  {
    v12 = ((int (__thiscall *)(IVModelInfoClient *, struct model_t *, int))modelinfo->GetModelFrameCount)(
            a1: modelinfo,
            a2: v11,
            a3: a2);
    v13 = 0;
    frameCount = v12 - 1;
    if ( count > 0 )
    {
      while ( 1 )
      {
        v15 = CTempEnts::TempEntAlloc(this, org: pos, model: v11);
        v16 = v15;
        if ( v15 == nullptr )
          break;
        C_BaseEntity::SetRenderMode(this: v15, nRenderMode: kRenderTransAlpha, bForceUpdate: false);
        if ( v16->m_clrRender.m_Value.r != 0xFF )
          v16->m_clrRender.m_Value.r = -1;
        if ( v16->m_clrRender.m_Value.g != 0xFF )
          v16->m_clrRender.m_Value.g = -1;
        if ( v16->m_clrRender.m_Value.b != 0xFF )
          v16->m_clrRender.m_Value.b = -1;
        C_BaseEntity::SetRenderAlpha(this: v16, a: 255);
        v16->tempent_renderamt = 255;
        C_BaseEntity::SetRenderFX(
          this: v16,
          nRenderFX: kRenderFxNoDissipation,
          flStartTime: 3.4028235e38,
          flDuration: 0.0);
        v16->flags |= 0x88u;
        v16->m_flSpriteScale = 0.5;
        v16->fadeSpeed = 2.0;
        dira = dir->x;
        velocity = ((double (__thiscall *)(IUniformRandomStream *, unsigned int, _DWORD))random->RandomFloat)(
                     a1: random,
                     a2: LODWORD(noise) ^ (unsigned int)_mask__NegFloat_,
                     a3: LODWORD(noise))
                 + dira;
        dirb = dir->y;
        velocity_4 = ((double (__stdcall *)(unsigned int, _DWORD))random->RandomFloat)(
                       a1: LODWORD(noise) ^ (unsigned int)_mask__NegFloat_,
                       a2: LODWORD(noise))
                   + dirb;
        dirc = dir->z;
        velocity_8 = ((double (__stdcall *)(_DWORD, _DWORD))random->RandomFloat)(a1: 0, a2: LODWORD(znoise)) + dirc;
        flDuration = (double)speed * 1.2;
        v17 = (double)speed * 0.8;
        dird = ((double (__thiscall *)(IUniformRandomStream *, _DWORD, _DWORD))random->RandomFloat)(
                 a1: random,
                 a2: LODWORD(v17),
                 a3: LODWORD(flDuration));
        v16->m_vecTempEntVelocity.x = dird * velocity;
        v16->m_vecTempEntVelocity.y = dird * velocity_4;
        v16->m_vecTempEntVelocity.z = dird * velocity_8;
        C_BaseEntity::SetLocalOrigin(this: v16, origin: pos);
        v16->die = *(float *)(gpGlobals.m_Index + 12) + 0.35;
        ++v13;
        v16->m_flFrame = (float)random->RandomInt(this: random, a2: 0, a3: frameCount);
        if ( v13 >= count )
          break;
        v11 = pModel;
      }
    }
  }
  else
  {
    _Warning(a1: "No model %d!\n", modelIndex);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10262440
// Name: public: virtual void CTempEnts::Sprite_Trail(class Vector const __near &,class Vector const __near &,int,int,float,float,float,int,float)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CTempEnts::Sprite_Trail(
        CTempEnts *this@<ecx>,
        int a2@<ebx>,
        const Vector *vecStart,
        const Vector *vecEnd,
        const struct model_t *modelIndex,
        int nCount,
        float flLife,
        float flSize,
        float flAmplitude,
        int nRenderamt,
        float flSpeed)
{
  const struct model_t *v12; // edi
  const Vector *v13; // esi
  float v14; // xmm1_4
  float v15; // xmm2_4
  int v16; // ebx
  float v17; // xmm0_4
  float v18; // xmm1_4
  C_LocalTempEntity *v19; // eax
  C_LocalTempEntity *v20; // esi
  int (__thiscall *RandomInt)(IUniformRandomStream *, int, int); // eax
  int v22; // eax
  float v23; // xmm0_4
  int (__thiscall *v24)(IUniformRandomStream *, int, int); // eax
  int v25; // eax
  float v26; // xmm0_4
  int (__thiscall *v27)(IUniformRandomStream *, int, int); // eax
  int v28; // eax
  float v29; // xmm0_4
  int v30; // edi
  Vector vecDir; // [esp+3Ch] [ebp-38h] BYREF
  Vector vecPos; // [esp+48h] [ebp-2Ch] BYREF
  Vector vecDelta; // [esp+54h] [ebp-20h]
  Vector vecVel; // [esp+60h] [ebp-14h]
  int flFrameCount; // [esp+6Ch] [ebp-8h]
  CTempEnts *v37; // [esp+70h] [ebp-4h]
  const struct model_t *pModel; // [esp+84h] [ebp+10h]
  float flAmplitudea; // [esp+94h] [ebp+20h]

  v37 = this;
  v12 = modelinfo->GetModel(this: modelinfo, a2: modelIndex);
  pModel = v12;
  if ( v12 != nullptr )
  {
    v13 = vecStart;
    flFrameCount = modelinfo->GetModelFrameCount(this: modelinfo, a2: v12);
    v14 = vecEnd->y - vecStart->y;
    v15 = vecEnd->z - vecStart->z;
    vecDelta.x = vecEnd->x - vecStart->x;
    vecDelta.y = v14;
    vecDelta.z = v15;
    vecDir = vecDelta;
    VectorNormalize(vec: &vecDir);
    v16 = 0;
    flAmplitudea = flAmplitude * 0.00390625;
    if ( nCount > 0 )
    {
      while ( 1 )
      {
        v17 = 0.0;
        if ( v16 != 0 )
        {
          v17 = (double)v16 / ((double)nCount - 1.0);
          vecPos.x = (float)(v17 * vecDelta.x) + v13->x;
          v18 = v17 * vecDelta.y;
        }
        else
        {
          vecPos.x = (float)(vecDelta.x * 0.0) + v13->x;
          v18 = vecDelta.y * 0.0;
        }
        vecPos.y = v18 + v13->y;
        vecPos.z = (float)(vecDelta.z * v17) + v13->z;
        v19 = CTempEnts::TempEntAlloc(this: v37, org: &vecPos, model: v12);
        v20 = v19;
        if ( v19 == nullptr )
          break;
        v19->flags |= 0x8A8u;
        RandomInt = random->RandomInt;
        vecVel.x = vecDir.x * flSpeed;
        vecVel.y = vecDir.y * flSpeed;
        vecVel.z = vecDir.z * flSpeed;
        v22 = ((int (__thiscall *)(IUniformRandomStream *, int, int, int))RandomInt)(
                a1: random,
                a2: -127,
                a3: 128,
                a4: a2);
        v23 = (float)((float)v22 * flAmplitudea) + vecVel.x;
        v24 = random->RandomInt;
        vecVel.x = v23;
        v25 = v24(this: random, a2: -127, a3: 128);
        v26 = (float)((float)v25 * flAmplitudea) + vecVel.y;
        v27 = random->RandomInt;
        vecVel.y = v26;
        v28 = v27(this: random, a2: -127, a3: 128);
        v29 = (float)((float)v28 * flAmplitudea) + vecVel.z;
        v20->m_vecTempEntVelocity.x = vecVel.x;
        v20->m_vecTempEntVelocity.y = vecVel.y;
        v20->m_vecTempEntVelocity.z = v29;
        C_BaseEntity::SetLocalOrigin(this: v20, origin: &vecPos);
        v20->m_flSpriteScale = flSize;
        C_BaseEntity::SetRenderMode(this: v20, nRenderMode: kRenderGlow, bForceUpdate: false);
        C_BaseEntity::SetRenderFX(
          this: v20,
          nRenderFX: kRenderFxNoDissipation,
          flStartTime: 3.4028235e38,
          flDuration: 0.0);
        v20->tempent_renderamt = nRenderamt;
        if ( v20->m_clrRender.m_Value.r != 0xFF )
          v20->m_clrRender.m_Value.r = -1;
        if ( v20->m_clrRender.m_Value.g != 0xFF )
          v20->m_clrRender.m_Value.g = -1;
        if ( v20->m_clrRender.m_Value.b != 0xFF )
          v20->m_clrRender.m_Value.b = -1;
        v30 = flFrameCount - 1;
        a2 = flFrameCount - 1;
        v20->m_flFrame = (float)((int (__thiscall *)(IUniformRandomStream *, _DWORD))random->RandomInt)(
                                  a1: random,
                                  a2: 0);
        v20->m_flFrameMax = (float)v30;
        ++v16;
        v20->die = ((double (__thiscall *)(IUniformRandomStream *, _DWORD, int))random->RandomFloat)(
                     a1: random,
                     a2: 0,
                     a3: 1082130432)
                 + *(float *)(gpGlobals.m_Index + 12)
                 + flLife;
        if ( v16 >= nCount )
          break;
        v12 = pModel;
        v13 = vecStart;
      }
    }
  }
  else
  {
    _Warning(a1: "No model %d!\n", modelIndex);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10262760
// Name: public: virtual void CTempEnts::AttachTentToPlayer(int,int,float,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTempEnts::AttachTentToPlayer(CTempEnts *this, int client, int modelIndex, float zoffset, float life)
{
  int v5; // esi
  struct model_t *v6; // ebx
  float *v7; // eax
  C_LocalTempEntity *v8; // eax
  C_LocalTempEntity *v9; // esi
  float v10; // xmm0_4
  IClientRenderable_vtbl *v11; // edx
  IVModelInfoClient_vtbl *v12; // edi
  int v13; // eax
  int v14; // eax
  Vector position; // [esp+1Ch] [ebp-10h] BYREF
  CTempEnts *v16; // [esp+28h] [ebp-4h]

  v16 = this;
  if ( client <= 0 || client > *(_DWORD *)(gpGlobals.m_Index + 20) )
  {
    _Warning(a1: "Bad client in AttachTentToPlayer()!\n");
  }
  else
  {
    v5 = (*(int (__thiscall **)(unsigned int, int))(*(_DWORD *)(cl_entitylist.m_Index + 131092) + 12))(
           a1: cl_entitylist.m_Index + 131092,
           a2: client);
    if ( v5 != 0 )
    {
      v6 = modelinfo->GetModel(this: modelinfo, a2: modelIndex);
      if ( v6 != nullptr )
      {
        v7 = (float *)(*(int (__thiscall **)(int))(*(_DWORD *)v5 + 40))(a1: v5);
        position.x = *v7;
        position.y = v7[1];
        position.z = v7[2] + zoffset;
        v8 = CTempEnts::TempEntAllocHigh(this: v16, org: &position, model: v6);
        v9 = v8;
        if ( v8 != nullptr )
        {
          C_BaseEntity::SetRenderMode(this: v8, nRenderMode: kRenderNormal, bForceUpdate: false);
          C_BaseEntity::SetRenderAlpha(this: v9, a: 255);
          v9->tempent_renderamt = 255;
          C_BaseEntity::SetRenderFX(
            this: v9,
            nRenderFX: kRenderFxNoDissipation,
            flStartTime: 3.4028235e38,
            flDuration: 0.0);
          v9->clientIndex = client;
          v9->tentOffset.x = 0.0;
          v9->tentOffset.y = 0.0;
          v9->tentOffset.z = zoffset;
          v10 = *(float *)(gpGlobals.m_Index + 12) + life;
          v9->flags |= 0xA000u;
          v11 = v9->C_BaseAnimating::C_BaseEntity::IClientEntity::IClientRenderable::__vftable;
          v9->die = v10;
          v12 = modelinfo->__vftable;
          v13 = (int)v11->GetModel(this: &v9->IClientRenderable);
          if ( v12->GetModelType(this: modelinfo, a2: (const struct model_t *)v13) == 2 )
          {
            v14 = modelinfo->GetModelFrameCount(this: modelinfo, a2: v6);
            v9->flags |= 0x10100u;
            v9->m_flFrameMax = (float)(v14 - 1);
            v9->m_flFrameRate = 10.0;
          }
          else
          {
            v9->m_flFrameMax = 0.0;
          }
          v9->m_flFrame = 0.0;
        }
        else
        {
          _Warning(a1: "No temp ent.\n");
        }
      }
      else
      {
        _Warning(a1: "No model %d!\n", modelIndex);
      }
    }
    else
    {
      _Warning(a1: "Couldn't get IClientEntity for %i\n", client);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10262960
// Name: public: virtual void CTempEnts::RicochetSprite(class Vector const __near &,struct model_t __near *,float,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTempEnts::RicochetSprite(
        CTempEnts *this,
        const Vector *pos,
        struct model_t *pmodel,
        float duration,
        float scale)
{
  C_LocalTempEntity *v5; // eax
  C_LocalTempEntity *v6; // esi
  float v7; // xmm0_4

  v5 = CTempEnts::TempEntAlloc(this, org: pos, model: pmodel);
  v6 = v5;
  if ( v5 != nullptr )
  {
    C_BaseEntity::SetRenderMode(this: v5, nRenderMode: kRenderGlow, bForceUpdate: false);
    C_BaseEntity::SetRenderFX(this: v6, nRenderFX: kRenderFxNoDissipation, flStartTime: 3.4028235e38, flDuration: 0.0);
    C_BaseEntity::SetRenderAlpha(this: v6, a: 200);
    v6->tempent_renderamt = 200;
    v6->m_flSpriteScale = scale;
    v6->flags = 128;
    v6->m_vecTempEntVelocity = vec3_origin;
    C_BaseEntity::SetLocalOrigin(this: v6, origin: pos);
    v6->fadeSpeed = 8.0;
    v6->die = *(float *)(gpGlobals.m_Index + 12);
    v6->m_flFrame = 0.0;
    v7 = (float)(45 * random->RandomInt(this: random, a2: 0, a3: 7));
    C_BaseEntity::SetLocalAnglesDim(this: v6, iDim: 2, flValue: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10262A70
// Name: public: virtual void CTempEnts::BloodSprite(class Vector const __near &,int,int,int,int,int,int,float)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CTempEnts::BloodSprite(
        CTempEnts *this@<ecx>,
        int a2@<edi>,
        int a3@<esi>,
        const Vector *org,
        unsigned __int8 r,
        unsigned __int8 g,
        unsigned __int8 b,
        int a,
        int modelIndex,
        int modelIndex2,
        float size)
{
  const struct model_t *v12; // esi
  int v13; // edi
  C_LocalTempEntity *v14; // eax
  C_LocalTempEntity *v15; // esi
  float v16; // xmm0_4
  float v17; // xmm0_4

  if ( modelIndex != 0 )
  {
    v12 = modelinfo->GetModel(this: modelinfo, a2: modelIndex);
    if ( v12 != nullptr )
    {
      v13 = modelinfo->GetModelFrameCount(this: modelinfo, a2: v12);
      v14 = CTempEnts::TempEntAllocHigh(this, org, model: v12);
      v15 = v14;
      if ( v14 != nullptr )
      {
        C_BaseEntity::SetRenderMode(this: v14, nRenderMode: kRenderTransTexture, bForceUpdate: false);
        C_BaseEntity::SetRenderFX(this: v15, nRenderFX: kRenderFxNone, flStartTime: 3.4028235e38, flDuration: 0.0);
        v15->m_flSpriteScale = ((double (__thiscall *)(IUniformRandomStream *, _DWORD, _DWORD, int, int))random->RandomFloat)(
                                 a1: random,
                                 a2: size * 0.039999999,
                                 a3: size * 0.028571429,
                                 a4: a2,
                                 a5: a3);
        v15->flags = 256;
        if ( v15->m_clrRender.m_Value.r != r )
          v15->m_clrRender.m_Value.r = r;
        if ( v15->m_clrRender.m_Value.g != g )
          v15->m_clrRender.m_Value.g = g;
        if ( v15->m_clrRender.m_Value.b != b )
          v15->m_clrRender.m_Value.b = b;
        C_BaseEntity::SetRenderAlpha(this: v15, a);
        v15->tempent_renderamt = C_BaseEntity::GetRenderAlpha(this: v15);
        v15->m_vecTempEntVelocity = vec3_origin;
        v16 = (float)(4 * v13);
        v15->m_flFrameRate = v16;
        v15->die = (float)((float)v13 / v16) + *(float *)(gpGlobals.m_Index + 12);
        v15->m_flFrame = 0.0;
        v15->m_flFrameMax = (float)(v13 - 1);
        v15->bounceFactor = 0.0;
        v17 = (float)random->RandomInt(this: random, a2: 0, a3: 360);
        C_BaseEntity::SetLocalAnglesDim(this: v15, iDim: 2, flValue: v17);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10262C30
// Name: public: virtual class C_LocalTempEntity __near * CTempEnts::DefaultSprite(class Vector const __near &,int,float)
// Source: json
//------------------------------------------------------------------------------
C_LocalTempEntity *__userpurge CTempEnts::DefaultSprite@<eax>(
        CTempEnts *this@<ecx>,
        int a2@<edi>,
        const Vector *pos,
        int spriteIndex,
        float framerate)
{
  C_LocalTempEntity *result; // eax
  const struct model_t *v6; // eax
  const struct model_t *v7; // esi
  int v8; // edi
  C_LocalTempEntity *v9; // esi
  float v10; // xmm0_4

  if ( *(float *)(gpGlobals.m_Index + 16) == 0.0 )
    return nullptr;
  v6 = (const struct model_t *)((int (__thiscall *)(IVModelInfoClient *, int, int))modelinfo->GetModel)(
                                 a1: modelinfo,
                                 a2: spriteIndex,
                                 a3: a2);
  v7 = v6;
  if ( spriteIndex != 0 && v6 != nullptr && modelinfo->GetModelType(this: modelinfo, a2: v6) == 2 )
  {
    v8 = modelinfo->GetModelFrameCount(this: modelinfo, a2: v7);
    result = CTempEnts::TempEntAlloc(this, org: pos, model: v7);
    v9 = result;
    if ( result != nullptr )
    {
      result->flags |= 0x100u;
      result->m_flFrameMax = (float)(v8 - 1);
      result->m_flSpriteScale = 1.0;
      v10 = framerate;
      if ( framerate == 0.0 )
        v10 = 10.0;
      result->m_flFrameRate = v10;
      result->die = (float)((float)v8 / v10) + *(float *)(gpGlobals.m_Index + 12);
      result->m_flFrame = 0.0;
      C_BaseEntity::SetLocalOrigin(this: result, origin: pos);
      return v9;
    }
  }
  else
  {
    _DevWarning(a1: 1, a2: "No Sprite %d!\n", spriteIndex);
    return nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10262D60
// Name: public: virtual class C_LocalTempEntity __near * CTempEnts::SpawnTempModel(struct model_t __near *,class Vector const __near &,class QAngle const __near &,class Vector const __near &,float,int)
// Source: json
//------------------------------------------------------------------------------
C_LocalTempEntity *__thiscall CTempEnts::SpawnTempModel(
        CTempEnts *this,
        struct model_t *pModel,
        const Vector *vecOrigin,
        const QAngle *vecAngles,
        const Vector *vecVelocity,
        float flLifeTime,
        int iFlags)
{
  C_LocalTempEntity *result; // eax
  C_LocalTempEntity *v8; // esi

  result = CTempEnts::TempEntAlloc(this, org: vecOrigin, model: pModel);
  v8 = result;
  if ( result != nullptr )
  {
    C_BaseEntity::SetAbsAngles(this: result, absAngles: vecAngles);
    C_BaseAnimating::SetBody(this: v8, iBody: 0);
    v8->flags |= iFlags;
    v8->m_vecTempEntAngVelocity.x = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
                                      a1: random,
                                      a2: -1015087104,
                                      a3: 1132396544);
    v8->m_vecTempEntAngVelocity.y = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
                                      a1: random,
                                      a2: -1015087104,
                                      a3: 1132396544);
    v8->m_vecTempEntAngVelocity.z = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
                                      a1: random,
                                      a2: -1015087104,
                                      a3: 1132396544);
    C_BaseEntity::SetRenderMode(this: v8, nRenderMode: kRenderNormal, bForceUpdate: false);
    v8->tempent_renderamt = 255;
    v8->m_vecTempEntVelocity = *vecVelocity;
    v8->die = *(float *)(gpGlobals.m_Index + 12) + flLifeTime;
    return v8;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1036E390
// Name: protected: unsigned short CUtlLinkedList<struct CUtlMultiList<struct CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<struct CUtlMultiList<struct CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>>::AllocInternal(
        CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short> > *this,
        bool multilist)
{
  int m_FirstFree; // ecx
  int m_nAllocationCount; // ecx
  unsigned __int16 index; // ax
  int result; // eax
  int v7; // ecx
  unsigned __int16 v8; // ax
  UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short> *v9; // ecx

  m_FirstFree = this->m_FirstFree;
  if ( (_WORD)m_FirstFree != 0xFFFF )
  {
    result = m_FirstFree;
    this->m_FirstFree = this->m_Memory.m_pMemory[m_FirstFree].m_Next;
LABEL_22:
    v9 = &this->m_Memory.m_pMemory[(unsigned __int16)result];
    if ( multilist )
    {
      v9->m_Next = -1;
      v9->m_Previous = -1;
    }
    else
    {
      v9->m_Next = result;
      v9->m_Previous = result;
    }
    return result;
  }
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( this->m_LastAlloc.index >= m_nAllocationCount )
  {
    m_nAllocationCount = this->m_Memory.m_nAllocationCount;
    LOWORD(result) = (m_nAllocationCount > 0) - 1;
  }
  else
  {
    index = this->m_LastAlloc.index;
    if ( (unsigned __int16)(index + 1) >= m_nAllocationCount )
      LOWORD(result) = -1;
    else
      LOWORD(result) = index + 1;
  }
  if ( (unsigned __int16)result >= m_nAllocationCount )
  {
    CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CPixelVisibilityQuery,unsigned short>::List_t,unsigned short>,unsigned short>::Grow(
      this: &this->m_Memory,
      num: 1);
    this->m_pElements = this->m_Memory.m_pMemory;
    v7 = this->m_Memory.m_nAllocationCount;
    if ( this->m_LastAlloc.index >= v7 )
    {
      v7 = this->m_Memory.m_nAllocationCount;
      LOWORD(result) = (v7 > 0) - 1;
    }
    else
    {
      v8 = this->m_LastAlloc.index;
      LOWORD(result) = (unsigned __int16)(v8 + 1) >= v7 ? -1 : v8 + 1;
    }
    if ( (unsigned __int16)result >= v7 )
    {
      if ( `CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>>::AllocInternal'::`12'::__executeCount;
        _Warning(a1: "CUtlLinkedList overflow! (exhausted memory allocator)\n");
      }
      return 0xFFFF;
    }
  }
  if ( (_WORD)result != 0xFFFF )
  {
    ++this->m_NumAlloced;
    this->m_LastAlloc.index = result;
    result = (unsigned __int16)result;
    goto LABEL_22;
  }
  if ( `CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>>::AllocInternal'::`19'::__executeCount >= 10 )
    return 0xFFFF;
  ++`CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>>::AllocInternal'::`19'::__executeCount;
  _Warning(a1: "CUtlLinkedList overflow! (exhausted index range)\n");
  return 0xFFFF;
}

//------------------------------------------------------------------------------
// Address: 0x10387500
// Name: public: void CClassMemoryPool<struct PanelAnimationMap>::Clear(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CClassMemoryPool<PanelAnimationMap>::Clear(
        CClassMemoryPool<PanelAnimationMap> *this@<ecx>,
        int a2@<edi>)
{
  void *m_pHeadOfFreeList; // eax
  unsigned __int16 v3; // ax
  unsigned __int16 v4; // dx
  unsigned __int16 v5; // cx
  int v6; // esi
  UtlRBTreeNode_t<void *,unsigned short> *m_pMemory; // eax
  int v8; // esi
  int v9; // edx
  CClassMemoryPool<PanelAnimationMap> *m_pNext; // edi
  unsigned int p_m_pHeadOfFreeList; // esi
  void *v12; // eax
  CUtlRBTree<void *,unsigned short,bool (__cdecl*)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short> > freeBlocks; // [esp+Ch] [ebp-30h] BYREF
  PanelAnimationMap *pLimit; // [esp+28h] [ebp-14h]
  unsigned __int16 parent[2]; // [esp+2Ch] [ebp-10h] BYREF
  CUtlMemoryPool *v16; // [esp+30h] [ebp-Ch]
  void *pCurFree; // [esp+34h] [ebp-8h] BYREF
  bool leftchild; // [esp+3Bh] [ebp-1h] BYREF

  m_pHeadOfFreeList = this->m_pHeadOfFreeList;
  v16 = this;
  memset(&freeBlocks.m_Elements, 0, sizeof(freeBlocks.m_Elements));
  *(_DWORD *)&freeBlocks.m_Root = 0xFFFF;
  *(_DWORD *)&freeBlocks.m_FirstFree = -1;
  freeBlocks.m_pElements = nullptr;
  freeBlocks.m_LessFunc = (bool (__cdecl *)(void *const *, void *const *))CDefOps<C_BaseEntity *>::LessFunc;
  pCurFree = m_pHeadOfFreeList;
  if ( m_pHeadOfFreeList != nullptr )
  {
    do
    {
      *(_DWORD *)parent = 0xFFFF;
      leftchild = false;
      CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::FindInsertionPosition(
        this: &freeBlocks,
        insert: &pCurFree,
        parent,
        &leftchild);
      v3 = CUtlRBTree<CWorldListCache::Entry_t *,unsigned short,CWorldListCache::CEntryComparator,CUtlMemory<UtlRBTreeNode_t<CWorldListCache::Entry_t *,unsigned short>,unsigned short>>::NewNode(
             this: (CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> > *)&freeBlocks,
             (const char *)a2);
      v4 = parent[0];
      v5 = v3;
      v6 = 3 * v3;
      m_pMemory = freeBlocks.m_Elements.m_pMemory;
      v8 = 4 * v6;
      *(unsigned __int16 *)((char *)&freeBlocks.m_Elements.m_pMemory->m_Right + v8) = -1;
      *(unsigned __int16 *)((char *)&m_pMemory->m_Left + v8) = -1;
      *(unsigned __int16 *)((char *)&m_pMemory->m_Tag + v8) = 0;
      a2 = 0xFFFF;
      *(unsigned __int16 *)((char *)&m_pMemory->m_Parent + v8) = v4;
      if ( v4 == 0xFFFF )
      {
        freeBlocks.m_Root = v5;
      }
      else
      {
        v9 = v4;
        if ( leftchild )
          m_pMemory[v9].m_Left = v5;
        else
          m_pMemory[v9].m_Right = v5;
      }
      CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::InsertRebalance(
        this: &freeBlocks,
        elem: v5);
      ++freeBlocks.m_NumElements;
      if ( (UtlRBTreeNode_t<void *,unsigned short> *)((char *)freeBlocks.m_Elements.m_pMemory + v8) != (UtlRBTreeNode_t<void *,unsigned short> *)-8 )
        *(void **)((char *)&freeBlocks.m_Elements.m_pMemory->m_Data + v8) = pCurFree;
      pCurFree = *(void **)pCurFree;
    }
    while ( pCurFree != nullptr );
    this = (CClassMemoryPool<PanelAnimationMap> *)v16;
  }
  m_pNext = (CClassMemoryPool<PanelAnimationMap> *)this->m_BlobHead.m_pNext;
  if ( m_pNext != (CClassMemoryPool<PanelAnimationMap> *)&this->m_BlobHead )
  {
    do
    {
      p_m_pHeadOfFreeList = (unsigned int)&m_pNext->m_pHeadOfFreeList;
      pLimit = (PanelAnimationMap *)((char *)&m_pNext->m_pHeadOfFreeList + m_pNext->m_GrowMode);
      if ( &m_pNext->m_pHeadOfFreeList < (void **)pLimit )
      {
        do
        {
          *(_DWORD *)parent = p_m_pHeadOfFreeList;
          if ( CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::Find(
                 this: &freeBlocks,
                 search: (void *const *)parent) == 0xFFFF )
          {
            *(_DWORD *)(p_m_pHeadOfFreeList + 12) = 0;
            if ( *(int *)(p_m_pHeadOfFreeList + 8) >= 0 )
            {
              if ( *(_DWORD *)p_m_pHeadOfFreeList != 0 )
              {
                _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *(void **)p_m_pHeadOfFreeList);
                *(_DWORD *)p_m_pHeadOfFreeList = 0;
              }
              *(_DWORD *)(p_m_pHeadOfFreeList + 4) = 0;
            }
            v12 = *(void **)p_m_pHeadOfFreeList;
            *(_DWORD *)(p_m_pHeadOfFreeList + 16) = *(_DWORD *)p_m_pHeadOfFreeList;
            if ( *(int *)(p_m_pHeadOfFreeList + 8) >= 0 )
            {
              if ( v12 != nullptr )
              {
                _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v12);
                *(_DWORD *)p_m_pHeadOfFreeList = 0;
              }
              *(_DWORD *)(p_m_pHeadOfFreeList + 4) = 0;
            }
          }
          p_m_pHeadOfFreeList += 28;
        }
        while ( p_m_pHeadOfFreeList < (unsigned int)pLimit );
      }
      m_pNext = (CClassMemoryPool<PanelAnimationMap> *)m_pNext->m_BlocksPerBlob;
    }
    while ( m_pNext != (CClassMemoryPool<PanelAnimationMap> *)&v16->m_BlobHead );
    this = (CClassMemoryPool<PanelAnimationMap> *)v16;
  }
  CUtlMemoryPool::Clear(this);
  CUtlRBTree<void *,unsigned short,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short>>::RemoveAll(this: &freeBlocks);
  if ( freeBlocks.m_Elements.m_nGrowSize >= 0 && freeBlocks.m_Elements.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: freeBlocks.m_Elements.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x103A5850
// Name: protected: unsigned char CUtlLinkedList<struct vgui::ListPanel::column_t,unsigned char,0,unsigned char,class CUtlMemory<struct UtlLinkedListElem_t<struct vgui::ListPanel::column_t,unsigned char>,unsigned char>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 __thiscall CUtlLinkedList<vgui::ListPanel::column_t,unsigned char,0,unsigned char,CUtlMemory<UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char>,unsigned char>>::AllocInternal(
        CUtlLinkedList<vgui::ListPanel::column_t,unsigned char,0,unsigned char,CUtlMemory<UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char>,unsigned char> > *this,
        bool multilist)
{
  unsigned __int8 result; // al
  int index; // eax
  int m_nAllocationCount; // ecx
  unsigned __int8 v6; // al
  int v7; // ecx
  unsigned __int8 v8; // al
  UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char> *v9; // ecx

  result = this->m_FirstFree;
  if ( result != 0xFF )
  {
    this->m_FirstFree = this->m_Memory.m_pMemory[result].m_Next;
LABEL_22:
    v9 = &this->m_Memory.m_pMemory[result];
    if ( multilist )
    {
      *(_WORD *)&v9->m_Previous = -1;
    }
    else
    {
      v9->m_Next = result;
      v9->m_Previous = result;
    }
    return result;
  }
  index = this->m_LastAlloc.index;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( index >= m_nAllocationCount )
  {
    m_nAllocationCount = this->m_Memory.m_nAllocationCount;
    result = (m_nAllocationCount > 0) - 1;
  }
  else
  {
    v6 = this->m_LastAlloc.index;
    if ( (unsigned __int8)(v6 + 1) >= m_nAllocationCount )
      result = -1;
    else
      result = v6 + 1;
  }
  if ( result >= m_nAllocationCount )
  {
    CUtlMemory<UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char>,unsigned char>::Grow(
      this: &this->m_Memory,
      num: 1);
    this->m_pElements = this->m_Memory.m_pMemory;
    v7 = this->m_Memory.m_nAllocationCount;
    if ( this->m_LastAlloc.index >= v7 )
    {
      v7 = this->m_Memory.m_nAllocationCount;
      result = (v7 > 0) - 1;
    }
    else
    {
      v8 = this->m_LastAlloc.index;
      result = (unsigned __int8)(v8 + 1) >= v7 ? -1 : v8 + 1;
    }
    if ( result >= v7 )
    {
      if ( `CUtlLinkedList<vgui::ListPanel::column_t,unsigned char,0,unsigned char,CUtlMemory<UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char>,unsigned char>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<vgui::ListPanel::column_t,unsigned char,0,unsigned char,CUtlMemory<UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char>,unsigned char>>::AllocInternal'::`12'::__executeCount;
        _Warning(a1: "CUtlLinkedList overflow! (exhausted memory allocator)\n");
      }
      return -1;
    }
  }
  if ( result != 0xFF )
  {
    ++this->m_NumAlloced;
    this->m_LastAlloc.index = result;
    goto LABEL_22;
  }
  if ( `CUtlLinkedList<vgui::ListPanel::column_t,unsigned char,0,unsigned char,CUtlMemory<UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char>,unsigned char>>::AllocInternal'::`19'::__executeCount >= 10 )
    return -1;
  ++`CUtlLinkedList<vgui::ListPanel::column_t,unsigned char,0,unsigned char,CUtlMemory<UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char>,unsigned char>>::AllocInternal'::`19'::__executeCount;
  _Warning(a1: "CUtlLinkedList overflow! (exhausted index range)\n");
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x103A59B0
// Name: protected: int CUtlLinkedList<class vgui::FastSortListPanelItem __near *,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<class vgui::FastSortListPanelItem __near *,int>,int>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<vgui::FastSortListPanelItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::FastSortListPanelItem *,int>,int>>::AllocInternal(
        CUtlLinkedList<vgui::FastSortListPanelItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::FastSortListPanelItem *,int>,int> > *this,
        bool multilist)
{
  int result; // eax
  int index; // eax
  int m_nAllocationCount; // ecx
  int v6; // eax
  int v7; // ecx
  UtlLinkedListElem_t<vgui::FastSortListPanelItem *,int> *v8; // ecx

  result = this->m_FirstFree;
  if ( result != -1 )
  {
    this->m_FirstFree = this->m_Memory.m_pMemory[result].m_Next;
LABEL_23:
    v8 = &this->m_Memory.m_pMemory[result];
    if ( multilist )
    {
      v8->m_Next = -1;
      v8->m_Previous = -1;
    }
    else
    {
      v8->m_Next = result;
      v8->m_Previous = result;
    }
    return result;
  }
  index = this->m_LastAlloc.index;
  if ( index < 0 || (m_nAllocationCount = this->m_Memory.m_nAllocationCount, index >= m_nAllocationCount) )
  {
    m_nAllocationCount = this->m_Memory.m_nAllocationCount;
    result = (m_nAllocationCount > 0) - 1;
  }
  else
  {
    result = index + 1;
    if ( result < 0 || result >= m_nAllocationCount )
      result = -1;
  }
  if ( result < 0 || result >= m_nAllocationCount )
  {
    CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int>::Grow(
      (CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int> *)this,
      num: 1);
    this->m_pElements = this->m_Memory.m_pMemory;
    v6 = this->m_LastAlloc.index;
    if ( v6 < 0 || (v7 = this->m_Memory.m_nAllocationCount, v6 >= v7) )
    {
      v7 = this->m_Memory.m_nAllocationCount;
      result = (v7 > 0) - 1;
    }
    else
    {
      result = v6 + 1;
      if ( result < 0 || result >= v7 )
        result = -1;
    }
    if ( result < 0 || result >= v7 )
    {
      if ( `CUtlLinkedList<vgui::FastSortListPanelItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::FastSortListPanelItem *,int>,int>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<vgui::FastSortListPanelItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::FastSortListPanelItem *,int>,int>>::AllocInternal'::`12'::__executeCount;
        _Warning(a1: "CUtlLinkedList overflow! (exhausted memory allocator)\n");
      }
      return -1;
    }
  }
  ++this->m_NumAlloced;
  this->m_LastAlloc.index = result;
  goto LABEL_23;
}

//------------------------------------------------------------------------------
// Address: 0x103A7CD0
// Name: public: void CUtlLinkedList<struct vgui::ListPanel::column_t,unsigned char,0,unsigned char,class CUtlMemory<struct UtlLinkedListElem_t<struct vgui::ListPanel::column_t,unsigned char>,unsigned char>>::Unlink(unsigned char)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<vgui::ListPanel::column_t,unsigned char,0,unsigned char,CUtlMemory<UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char>,unsigned char>>::Unlink(
        CUtlLinkedList<vgui::ListPanel::column_t,unsigned char,0,unsigned char,CUtlMemory<UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char>,unsigned char> > *this,
        unsigned __int8 elem)
{
  UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char> *v2; // eax
  unsigned __int8 m_Next; // dl
  unsigned __int8 m_Previous; // bl

  if ( elem < this->m_Memory.m_nAllocationCount && elem <= this->m_LastAlloc.index )
  {
    v2 = &this->m_Memory.m_pMemory[elem];
    if ( v2->m_Previous != elem )
    {
      m_Next = v2->m_Next;
      m_Previous = v2->m_Previous;
      if ( m_Previous == 0xFF )
        this->m_Head = m_Next;
      else
        this->m_Memory.m_pMemory[m_Previous].m_Next = m_Next;
      if ( m_Next == 0xFF )
      {
        --this->m_ElementCount;
        this->m_Tail = m_Previous;
      }
      else
      {
        this->m_Memory.m_pMemory[m_Next].m_Previous = m_Previous;
        --this->m_ElementCount;
      }
      v2->m_Next = elem;
      v2->m_Previous = elem;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x103A82F0
// Name: public: void CUtlLinkedList<struct vgui::ListPanel::column_t,unsigned char,0,unsigned char,class CUtlMemory<struct UtlLinkedListElem_t<struct vgui::ListPanel::column_t,unsigned char>,unsigned char>>::LinkBefore(unsigned char,unsigned char)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<vgui::ListPanel::column_t,unsigned char,0,unsigned char,CUtlMemory<UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char>,unsigned char>>::LinkBefore(
        CUtlLinkedList<vgui::ListPanel::column_t,unsigned char,0,unsigned char,CUtlMemory<UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char>,unsigned char> > *this,
        unsigned __int8 before,
        unsigned __int8 elem)
{
  UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char> *m_pMemory; // edi
  UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char> *v5; // ecx
  unsigned __int8 m_Tail; // al

  CUtlLinkedList<vgui::ListPanel::column_t,unsigned char,0,unsigned char,CUtlMemory<UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char>,unsigned char>>::Unlink(
    this,
    elem);
  m_pMemory = this->m_Memory.m_pMemory;
  v5 = &this->m_Memory.m_pMemory[elem];
  v5->m_Next = before;
  if ( before == 0xFF )
  {
    m_Tail = this->m_Tail;
    this->m_Tail = elem;
  }
  else
  {
    m_Tail = m_pMemory[before].m_Previous;
    m_pMemory[before].m_Previous = elem;
  }
  v5->m_Previous = m_Tail;
  if ( m_Tail == 0xFF )
  {
    ++this->m_ElementCount;
    this->m_Head = elem;
  }
  else
  {
    m_pMemory[m_Tail].m_Next = elem;
    ++this->m_ElementCount;
  }
}

//------------------------------------------------------------------------------
// Address: 0x103A9100
// Name: public: int CUtlLinkedList<class vgui::FastSortListPanelItem __near *,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<class vgui::FastSortListPanelItem __near *,int>,int>>::AddToTail(class vgui::FastSortListPanelItem __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<vgui::FastSortListPanelItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::FastSortListPanelItem *,int>,int>>::AddToTail(
        CUtlLinkedList<vgui::FastSortListPanelItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::FastSortListPanelItem *,int>,int> > *this,
        vgui::FastSortListPanelItem **src)
{
  int result; // eax
  int v4; // edi
  UtlLinkedListElem_t<vgui::FastSortListPanelItem *,int> *m_pMemory; // eax
  unsigned int v6; // ecx
  int m_Tail; // edx
  UtlLinkedListElem_t<vgui::FastSortListPanelItem *,int> *v8; // esi

  result = CUtlLinkedList<vgui::FastSortListPanelItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::FastSortListPanelItem *,int>,int>>::AllocInternal(
             this,
             multilist: false);
  v4 = result;
  if ( result != -1 )
  {
    CUtlLinkedList<vgui::MenuItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::MenuItem *,int>,int>>::Unlink(
      (CUtlLinkedList<vgui::TreeNode *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int> > *)this,
      elem: result);
    m_pMemory = this->m_Memory.m_pMemory;
    v6 = v4;
    m_pMemory[v6].m_Next = -1;
    m_Tail = this->m_Tail;
    m_pMemory[v6].m_Previous = m_Tail;
    this->m_Tail = v4;
    if ( m_Tail == -1 )
      this->m_Head = v4;
    else
      this->m_Memory.m_pMemory[m_Tail].m_Next = v4;
    ++this->m_ElementCount;
    v8 = &this->m_Memory.m_pMemory[v6];
    if ( v8 != nullptr )
      v8->m_Element = *src;
    return v4;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103A9170
// Name: public: unsigned char CUtlLinkedList<struct vgui::ListPanel::column_t,unsigned char,0,unsigned char,class CUtlMemory<struct UtlLinkedListElem_t<struct vgui::ListPanel::column_t,unsigned char>,unsigned char>>::InsertBefore(unsigned char)
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 __thiscall CUtlLinkedList<vgui::ListPanel::column_t,unsigned char,0,unsigned char,CUtlMemory<UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char>,unsigned char>>::InsertBefore(
        CUtlLinkedList<vgui::ListPanel::column_t,unsigned char,0,unsigned char,CUtlMemory<UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char>,unsigned char> > *this,
        unsigned __int8 before)
{
  unsigned __int8 result; // al
  unsigned __int8 v4; // bl
  UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char> *v5; // eax

  result = CUtlLinkedList<vgui::ListPanel::column_t,unsigned char,0,unsigned char,CUtlMemory<UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char>,unsigned char>>::AllocInternal(
             this,
             multilist: false);
  v4 = result;
  if ( result != 0xFF )
  {
    CUtlLinkedList<vgui::ListPanel::column_t,unsigned char,0,unsigned char,CUtlMemory<UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char>,unsigned char>>::LinkBefore(
      this,
      before,
      elem: result);
    v5 = &this->m_Memory.m_pMemory[v4];
    if ( v5 != nullptr )
    {
      v5->m_Element.m_SortedTree.m_LessFunc = nullptr;
      v5->m_Element.m_SortedTree.m_Elements.m_pMemory = nullptr;
      v5->m_Element.m_SortedTree.m_Elements.m_nAllocationCount = 0;
      v5->m_Element.m_SortedTree.m_Elements.m_nGrowSize = 0;
      v5->m_Element.m_SortedTree.m_Root = -1;
      v5->m_Element.m_SortedTree.m_FirstFree = -1;
      v5->m_Element.m_SortedTree.m_NumElements = 0;
      v5->m_Element.m_SortedTree.m_LastAlloc.index = -1;
      v5->m_Element.m_SortedTree.m_pElements = v5->m_Element.m_SortedTree.m_Elements.m_pMemory;
    }
    return v4;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103A9610
// Name: public: void CUtlLinkedList<struct vgui::ListPanel::column_t,unsigned char,0,unsigned char,class CUtlMemory<struct UtlLinkedListElem_t<struct vgui::ListPanel::column_t,unsigned char>,unsigned char>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<vgui::ListPanel::column_t,unsigned char,0,unsigned char,CUtlMemory<UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char>,unsigned char>>::RemoveAll(
        CUtlLinkedList<vgui::ListPanel::column_t,unsigned char,0,unsigned char,CUtlMemory<UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char>,unsigned char> > *this)
{
  unsigned __int8 m_Head; // al
  UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char> *m_pMemory; // ecx
  int v3; // eax
  unsigned __int8 m_Next; // bl
  UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char> *v5; // edi
  unsigned __int8 v6; // al
  unsigned __int8 v7; // al
  CUtlLinkedList<vgui::ListPanel::column_t,unsigned char,0,unsigned char,CUtlMemory<UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char>,unsigned char> > *v8; // [esp+0h] [ebp-8h]
  unsigned __int8 i; // [esp+7h] [ebp-1h]

  v8 = this;
  if ( this->m_LastAlloc.index != 0xFF )
  {
    m_Head = this->m_Head;
    i = m_Head;
    if ( m_Head != 0xFF )
    {
      while ( 1 )
      {
        m_pMemory = this->m_Memory.m_pMemory;
        v3 = m_Head;
        m_Next = m_pMemory[v3].m_Next;
        v5 = &m_pMemory[v3];
        CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::RemoveAll(this: &v5->m_Element.m_SortedTree);
        v5->m_Element.m_SortedTree.m_FirstFree = -1;
        if ( v5->m_Element.m_SortedTree.m_Elements.m_nGrowSize >= 0 )
        {
          if ( v5->m_Element.m_SortedTree.m_Elements.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v5->m_Element.m_SortedTree.m_Elements.m_pMemory);
            v5->m_Element.m_SortedTree.m_Elements.m_pMemory = nullptr;
          }
          v5->m_Element.m_SortedTree.m_Elements.m_nAllocationCount = 0;
        }
        v5->m_Element.m_SortedTree.m_LastAlloc.index = -1;
        if ( v5->m_Element.m_SortedTree.m_Elements.m_nGrowSize >= 0 )
        {
          if ( v5->m_Element.m_SortedTree.m_Elements.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v5->m_Element.m_SortedTree.m_Elements.m_pMemory);
            v5->m_Element.m_SortedTree.m_Elements.m_pMemory = nullptr;
          }
          v5->m_Element.m_SortedTree.m_Elements.m_nAllocationCount = 0;
        }
        v5->m_Previous = i;
        v6 = m_Next == 0xFF ? v8->m_FirstFree : m_Next;
        this = v8;
        v5->m_Next = v6;
        i = m_Next;
        if ( m_Next == 0xFF )
          break;
        m_Head = m_Next;
      }
    }
    v7 = this->m_Head;
    if ( v7 != 0xFF )
      this->m_FirstFree = v7;
    *(_WORD *)&this->m_Head = -1;
    this->m_ElementCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x103AAA40
// Name: protected: int CUtlLinkedList<class vgui::ListViewItem __near *,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<class vgui::ListViewItem __near *,int>,int>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<vgui::ListViewItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::ListViewItem *,int>,int>>::AllocInternal(
        CUtlLinkedList<vgui::ListViewItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::ListViewItem *,int>,int> > *this,
        bool multilist)
{
  int result; // eax
  int index; // eax
  int m_nAllocationCount; // ecx
  int v6; // eax
  int v7; // ecx
  UtlLinkedListElem_t<vgui::ListViewItem *,int> *v8; // ecx

  result = this->m_FirstFree;
  if ( result != -1 )
  {
    this->m_FirstFree = this->m_Memory.m_pMemory[result].m_Next;
LABEL_23:
    v8 = &this->m_Memory.m_pMemory[result];
    if ( multilist )
    {
      v8->m_Next = -1;
      v8->m_Previous = -1;
    }
    else
    {
      v8->m_Next = result;
      v8->m_Previous = result;
    }
    return result;
  }
  index = this->m_LastAlloc.index;
  if ( index < 0 || (m_nAllocationCount = this->m_Memory.m_nAllocationCount, index >= m_nAllocationCount) )
  {
    m_nAllocationCount = this->m_Memory.m_nAllocationCount;
    result = (m_nAllocationCount > 0) - 1;
  }
  else
  {
    result = index + 1;
    if ( result < 0 || result >= m_nAllocationCount )
      result = -1;
  }
  if ( result < 0 || result >= m_nAllocationCount )
  {
    CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int>::Grow(
      (CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int> *)this,
      num: 1);
    this->m_pElements = this->m_Memory.m_pMemory;
    v6 = this->m_LastAlloc.index;
    if ( v6 < 0 || (v7 = this->m_Memory.m_nAllocationCount, v6 >= v7) )
    {
      v7 = this->m_Memory.m_nAllocationCount;
      result = (v7 > 0) - 1;
    }
    else
    {
      result = v6 + 1;
      if ( result < 0 || result >= v7 )
        result = -1;
    }
    if ( result < 0 || result >= v7 )
    {
      if ( `CUtlLinkedList<vgui::ListViewItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::ListViewItem *,int>,int>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<vgui::ListViewItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::ListViewItem *,int>,int>>::AllocInternal'::`12'::__executeCount;
        _Warning(a1: "CUtlLinkedList overflow! (exhausted memory allocator)\n");
      }
      return -1;
    }
  }
  ++this->m_NumAlloced;
  this->m_LastAlloc.index = result;
  goto LABEL_23;
}

//------------------------------------------------------------------------------
// Address: 0x103AB1C0
// Name: public: void CUtlLinkedList<class vgui::MenuItem __near *,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<class vgui::MenuItem __near *,int>,int>>::Unlink(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<vgui::MenuItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::MenuItem *,int>,int>>::Unlink(
        CUtlLinkedList<vgui::TreeNode *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int> > *this,
        int elem)
{
  UtlLinkedListElem_t<vgui::TreeNode *,int> *v2; // eax
  int m_Next; // edx
  int m_Previous; // edi
  int v5; // edx

  if ( elem >= 0 && elem < this->m_Memory.m_nAllocationCount && elem <= this->m_LastAlloc.index )
  {
    v2 = &this->m_Memory.m_pMemory[elem];
    if ( v2->m_Previous != elem )
    {
      m_Next = v2->m_Next;
      m_Previous = v2->m_Previous;
      if ( m_Previous == -1 )
        this->m_Head = m_Next;
      else
        this->m_Memory.m_pMemory[m_Previous].m_Next = m_Next;
      if ( m_Next == -1 )
      {
        v5 = v2->m_Previous;
        --this->m_ElementCount;
        this->m_Tail = v5;
      }
      else
      {
        this->m_Memory.m_pMemory[m_Next].m_Previous = v2->m_Previous;
        --this->m_ElementCount;
      }
      v2->m_Next = elem;
      v2->m_Previous = elem;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x103AC290
// Name: public: int CUtlLinkedList<class vgui::ListViewItem __near *,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<class vgui::ListViewItem __near *,int>,int>>::AddToTail(class vgui::ListViewItem __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<vgui::ListViewItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::ListViewItem *,int>,int>>::AddToTail(
        CUtlLinkedList<vgui::ListViewItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::ListViewItem *,int>,int> > *this,
        vgui::ListViewItem **src)
{
  int result; // eax
  int v4; // edi
  UtlLinkedListElem_t<vgui::ListViewItem *,int> *m_pMemory; // eax
  unsigned int v6; // ecx
  int m_Tail; // edx
  UtlLinkedListElem_t<vgui::ListViewItem *,int> *v8; // esi

  result = CUtlLinkedList<vgui::ListViewItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::ListViewItem *,int>,int>>::AllocInternal(
             this,
             multilist: false);
  v4 = result;
  if ( result != -1 )
  {
    CUtlLinkedList<vgui::MenuItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::MenuItem *,int>,int>>::Unlink(
      (CUtlLinkedList<vgui::TreeNode *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int> > *)this,
      elem: result);
    m_pMemory = this->m_Memory.m_pMemory;
    v6 = v4;
    m_pMemory[v6].m_Next = -1;
    m_Tail = this->m_Tail;
    m_pMemory[v6].m_Previous = m_Tail;
    this->m_Tail = v4;
    if ( m_Tail == -1 )
      this->m_Head = v4;
    else
      this->m_Memory.m_pMemory[m_Tail].m_Next = v4;
    ++this->m_ElementCount;
    v8 = &this->m_Memory.m_pMemory[v6];
    if ( v8 != nullptr )
      v8->m_Element = *src;
    return v4;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103AD810
// Name: public: bool CUtlLinkedList<class vgui::MenuItem __near *,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<class vgui::MenuItem __near *,int>,int>>::IsValidIndex(int)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CUtlLinkedList<vgui::MenuItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::MenuItem *,int>,int>>::IsValidIndex(
        CUtlLinkedList<vgui::MenuItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::MenuItem *,int>,int> > *this,
        int i)
{
  UtlLinkedListElem_t<vgui::MenuItem *,int> *m_pMemory; // ecx
  bool v4; // zf
  UtlLinkedListElem_t<vgui::MenuItem *,int> *v5; // ecx

  if ( i < 0 || i >= this->m_Memory.m_nAllocationCount || i > this->m_LastAlloc.index )
    return false;
  m_pMemory = this->m_Memory.m_pMemory;
  v4 = m_pMemory[i].m_Previous == i;
  v5 = &m_pMemory[i];
  return !v4 || v5->m_Next == i;
}

//------------------------------------------------------------------------------
// Address: 0x103ADEB0
// Name: protected: int CUtlLinkedList<class vgui::MenuItem __near *,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<class vgui::MenuItem __near *,int>,int>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<vgui::MenuItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::MenuItem *,int>,int>>::AllocInternal(
        CUtlLinkedList<vgui::MenuItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::MenuItem *,int>,int> > *this,
        bool multilist)
{
  int result; // eax
  int index; // eax
  int m_nAllocationCount; // ecx
  int v6; // eax
  int v7; // ecx
  UtlLinkedListElem_t<vgui::MenuItem *,int> *v8; // ecx

  result = this->m_FirstFree;
  if ( result != -1 )
  {
    this->m_FirstFree = this->m_Memory.m_pMemory[result].m_Next;
LABEL_23:
    v8 = &this->m_Memory.m_pMemory[result];
    if ( multilist )
    {
      v8->m_Next = -1;
      v8->m_Previous = -1;
    }
    else
    {
      v8->m_Next = result;
      v8->m_Previous = result;
    }
    return result;
  }
  index = this->m_LastAlloc.index;
  if ( index < 0 || (m_nAllocationCount = this->m_Memory.m_nAllocationCount, index >= m_nAllocationCount) )
  {
    m_nAllocationCount = this->m_Memory.m_nAllocationCount;
    result = (m_nAllocationCount > 0) - 1;
  }
  else
  {
    result = index + 1;
    if ( result < 0 || result >= m_nAllocationCount )
      result = -1;
  }
  if ( result < 0 || result >= m_nAllocationCount )
  {
    CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int>::Grow(
      (CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int> *)this,
      num: 1);
    this->m_pElements = this->m_Memory.m_pMemory;
    v6 = this->m_LastAlloc.index;
    if ( v6 < 0 || (v7 = this->m_Memory.m_nAllocationCount, v6 >= v7) )
    {
      v7 = this->m_Memory.m_nAllocationCount;
      result = (v7 > 0) - 1;
    }
    else
    {
      result = v6 + 1;
      if ( result < 0 || result >= v7 )
        result = -1;
    }
    if ( result < 0 || result >= v7 )
    {
      if ( `CUtlLinkedList<vgui::MenuItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::MenuItem *,int>,int>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<vgui::MenuItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::MenuItem *,int>,int>>::AllocInternal'::`12'::__executeCount;
        _Warning(a1: "CUtlLinkedList overflow! (exhausted memory allocator)\n");
      }
      return -1;
    }
  }
  ++this->m_NumAlloced;
  this->m_LastAlloc.index = result;
  goto LABEL_23;
}

//------------------------------------------------------------------------------
// Address: 0x103B0520
// Name: public: int CUtlLinkedList<class vgui::MenuItem __near *,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<class vgui::MenuItem __near *,int>,int>>::AddToTail(class vgui::MenuItem __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<vgui::MenuItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::MenuItem *,int>,int>>::AddToTail(
        CUtlLinkedList<vgui::MenuItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::MenuItem *,int>,int> > *this,
        vgui::MenuItem **src)
{
  int result; // eax
  int v4; // edi
  UtlLinkedListElem_t<vgui::MenuItem *,int> *m_pMemory; // eax
  unsigned int v6; // ecx
  int m_Tail; // edx
  UtlLinkedListElem_t<vgui::MenuItem *,int> *v8; // esi

  result = CUtlLinkedList<vgui::MenuItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::MenuItem *,int>,int>>::AllocInternal(
             this,
             multilist: false);
  v4 = result;
  if ( result != -1 )
  {
    CUtlLinkedList<vgui::MenuItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::MenuItem *,int>,int>>::Unlink(
      (CUtlLinkedList<vgui::TreeNode *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int> > *)this,
      elem: result);
    m_pMemory = this->m_Memory.m_pMemory;
    v6 = v4;
    m_pMemory[v6].m_Next = -1;
    m_Tail = this->m_Tail;
    m_pMemory[v6].m_Previous = m_Tail;
    this->m_Tail = v4;
    if ( m_Tail == -1 )
      this->m_Head = v4;
    else
      this->m_Memory.m_pMemory[m_Tail].m_Next = v4;
    ++this->m_ElementCount;
    v8 = &this->m_Memory.m_pMemory[v6];
    if ( v8 != nullptr )
      v8->m_Element = *src;
    return v4;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103B9120
// Name: protected: int CUtlLinkedList<class vgui::TreeNode __near *,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<class vgui::TreeNode __near *,int>,int>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<vgui::TreeNode *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int>>::AllocInternal(
        CUtlLinkedList<vgui::TreeNode *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int> > *this,
        bool multilist)
{
  int result; // eax
  int index; // eax
  int m_nAllocationCount; // ecx
  int v6; // eax
  int v7; // ecx
  UtlLinkedListElem_t<vgui::TreeNode *,int> *v8; // ecx

  result = this->m_FirstFree;
  if ( result != -1 )
  {
    this->m_FirstFree = this->m_Memory.m_pMemory[result].m_Next;
LABEL_23:
    v8 = &this->m_Memory.m_pMemory[result];
    if ( multilist )
    {
      v8->m_Next = -1;
      v8->m_Previous = -1;
    }
    else
    {
      v8->m_Next = result;
      v8->m_Previous = result;
    }
    return result;
  }
  index = this->m_LastAlloc.index;
  if ( index < 0 || (m_nAllocationCount = this->m_Memory.m_nAllocationCount, index >= m_nAllocationCount) )
  {
    m_nAllocationCount = this->m_Memory.m_nAllocationCount;
    result = (m_nAllocationCount > 0) - 1;
  }
  else
  {
    result = index + 1;
    if ( result < 0 || result >= m_nAllocationCount )
      result = -1;
  }
  if ( result < 0 || result >= m_nAllocationCount )
  {
    CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int>::Grow(this: &this->m_Memory, num: 1);
    this->m_pElements = this->m_Memory.m_pMemory;
    v6 = this->m_LastAlloc.index;
    if ( v6 < 0 || (v7 = this->m_Memory.m_nAllocationCount, v6 >= v7) )
    {
      v7 = this->m_Memory.m_nAllocationCount;
      result = (v7 > 0) - 1;
    }
    else
    {
      result = v6 + 1;
      if ( result < 0 || result >= v7 )
        result = -1;
    }
    if ( result < 0 || result >= v7 )
    {
      if ( `CUtlLinkedList<vgui::TreeNode *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<vgui::TreeNode *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int>>::AllocInternal'::`12'::__executeCount;
        _Warning(a1: "CUtlLinkedList overflow! (exhausted memory allocator)\n");
      }
      return -1;
    }
  }
  ++this->m_NumAlloced;
  this->m_LastAlloc.index = result;
  goto LABEL_23;
}

//------------------------------------------------------------------------------
// Address: 0x103BDEA0
// Name: protected: int CUtlLinkedList<struct vgui::PanelListPanel::dataitem_s,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<struct vgui::PanelListPanel::dataitem_s,int>,int>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<vgui::PanelListPanel::dataitem_s,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int>>::AllocInternal(
        CUtlLinkedList<vgui::PanelListPanel::dataitem_s,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int> > *this,
        bool multilist)
{
  int m_FirstFree; // ecx
  int index; // eax
  int m_nAllocationCount; // ecx
  int result; // eax
  int v7; // eax
  int v8; // ecx
  UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int> *m_pMemory; // ecx

  m_FirstFree = this->m_FirstFree;
  if ( m_FirstFree != -1 )
  {
    result = m_FirstFree;
    this->m_FirstFree = this->m_Memory.m_pMemory[m_FirstFree].m_Next;
LABEL_23:
    m_pMemory = this->m_Memory.m_pMemory;
    if ( multilist )
    {
      m_pMemory[result].m_Next = -1;
      m_pMemory[result].m_Previous = -1;
    }
    else
    {
      m_pMemory[result].m_Next = result;
      m_pMemory[result].m_Previous = result;
    }
    return result;
  }
  index = this->m_LastAlloc.index;
  if ( index < 0 || (m_nAllocationCount = this->m_Memory.m_nAllocationCount, index >= m_nAllocationCount) )
  {
    m_nAllocationCount = this->m_Memory.m_nAllocationCount;
    result = (m_nAllocationCount > 0) - 1;
  }
  else
  {
    result = index + 1;
    if ( result < 0 || result >= m_nAllocationCount )
      result = -1;
  }
  if ( result < 0 || result >= m_nAllocationCount )
  {
    CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int>::Grow(this: &this->m_Memory, num: 1);
    this->m_pElements = this->m_Memory.m_pMemory;
    v7 = this->m_LastAlloc.index;
    if ( v7 < 0 || (v8 = this->m_Memory.m_nAllocationCount, v7 >= v8) )
    {
      v8 = this->m_Memory.m_nAllocationCount;
      result = (v8 > 0) - 1;
    }
    else
    {
      result = v7 + 1;
      if ( result < 0 || result >= v8 )
        result = -1;
    }
    if ( result < 0 || result >= v8 )
    {
      if ( `CUtlLinkedList<vgui::PanelListPanel::dataitem_s,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<vgui::PanelListPanel::dataitem_s,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int>>::AllocInternal'::`12'::__executeCount;
        _Warning(a1: "CUtlLinkedList overflow! (exhausted memory allocator)\n");
      }
      return -1;
    }
  }
  ++this->m_NumAlloced;
  this->m_LastAlloc.index = result;
  goto LABEL_23;
}

//------------------------------------------------------------------------------
// Address: 0x103BDFD0
// Name: public: void CUtlLinkedList<class C_CSPlayer::CCSSoundEvent,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<class C_CSPlayer::CCSSoundEvent,int>,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<C_CSPlayer::CCSSoundEvent,int,0,int,CUtlMemory<UtlLinkedListElem_t<C_CSPlayer::CCSSoundEvent,int>,int>>::RemoveAll(
        CUtlLinkedList<vgui::PanelListPanel::dataitem_s,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int> > *this)
{
  int m_Head; // edx
  UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int> *v2; // esi
  int m_Next; // eax
  int m_FirstFree; // edx
  int v5; // eax

  if ( this->m_LastAlloc.index != -1 )
  {
    m_Head = this->m_Head;
    if ( m_Head != -1 )
    {
      do
      {
        v2 = &this->m_Memory.m_pMemory[m_Head];
        m_Next = v2->m_Next;
        v2->m_Previous = m_Head;
        if ( m_Next == -1 )
          m_FirstFree = this->m_FirstFree;
        else
          m_FirstFree = m_Next;
        v2->m_Next = m_FirstFree;
        m_Head = m_Next;
      }
      while ( m_Next != -1 );
    }
    v5 = this->m_Head;
    if ( v5 != -1 )
      this->m_FirstFree = v5;
    this->m_Head = -1;
    this->m_Tail = -1;
    this->m_ElementCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x103BE030
// Name: public: void CUtlLinkedList<class C_CSPlayer::CCSSoundEvent,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<class C_CSPlayer::CCSSoundEvent,int>,int>>::Unlink(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<C_CSPlayer::CCSSoundEvent,int,0,int,CUtlMemory<UtlLinkedListElem_t<C_CSPlayer::CCSSoundEvent,int>,int>>::Unlink(
        CUtlLinkedList<vgui::PanelListPanel::dataitem_s,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int> > *this,
        int elem)
{
  UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int> *v2; // eax
  int m_Next; // edx
  int m_Previous; // ebx
  int v5; // edx

  if ( elem >= 0 && elem < this->m_Memory.m_nAllocationCount && elem <= this->m_LastAlloc.index )
  {
    v2 = &this->m_Memory.m_pMemory[elem];
    if ( v2->m_Previous != elem )
    {
      m_Next = v2->m_Next;
      m_Previous = v2->m_Previous;
      if ( m_Previous == -1 )
        this->m_Head = m_Next;
      else
        this->m_Memory.m_pMemory[m_Previous].m_Next = m_Next;
      if ( m_Next == -1 )
      {
        v5 = v2->m_Previous;
        --this->m_ElementCount;
        this->m_Tail = v5;
      }
      else
      {
        this->m_Memory.m_pMemory[m_Next].m_Previous = v2->m_Previous;
        --this->m_ElementCount;
      }
      v2->m_Next = elem;
      v2->m_Previous = elem;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x103C8F80
// Name: protected: int CUtlLinkedList<class vgui::CItemButton __near *,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<class vgui::CItemButton __near *,int>,int>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<vgui::CItemButton *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::CItemButton *,int>,int>>::AllocInternal(
        CUtlLinkedList<vgui::CItemButton *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::CItemButton *,int>,int> > *this,
        bool multilist)
{
  int result; // eax
  int index; // eax
  int m_nAllocationCount; // ecx
  int v6; // eax
  int v7; // ecx
  UtlLinkedListElem_t<vgui::CItemButton *,int> *v8; // ecx

  result = this->m_FirstFree;
  if ( result != -1 )
  {
    this->m_FirstFree = this->m_Memory.m_pMemory[result].m_Next;
LABEL_23:
    v8 = &this->m_Memory.m_pMemory[result];
    if ( multilist )
    {
      v8->m_Next = -1;
      v8->m_Previous = -1;
    }
    else
    {
      v8->m_Next = result;
      v8->m_Previous = result;
    }
    return result;
  }
  index = this->m_LastAlloc.index;
  if ( index < 0 || (m_nAllocationCount = this->m_Memory.m_nAllocationCount, index >= m_nAllocationCount) )
  {
    m_nAllocationCount = this->m_Memory.m_nAllocationCount;
    result = (m_nAllocationCount > 0) - 1;
  }
  else
  {
    result = index + 1;
    if ( result < 0 || result >= m_nAllocationCount )
      result = -1;
  }
  if ( result < 0 || result >= m_nAllocationCount )
  {
    CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int>::Grow(
      (CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int> *)this,
      num: 1);
    this->m_pElements = this->m_Memory.m_pMemory;
    v6 = this->m_LastAlloc.index;
    if ( v6 < 0 || (v7 = this->m_Memory.m_nAllocationCount, v6 >= v7) )
    {
      v7 = this->m_Memory.m_nAllocationCount;
      result = (v7 > 0) - 1;
    }
    else
    {
      result = v6 + 1;
      if ( result < 0 || result >= v7 )
        result = -1;
    }
    if ( result < 0 || result >= v7 )
    {
      if ( `CUtlLinkedList<vgui::CItemButton *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::CItemButton *,int>,int>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<vgui::CItemButton *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::CItemButton *,int>,int>>::AllocInternal'::`12'::__executeCount;
        _Warning(a1: "CUtlLinkedList overflow! (exhausted memory allocator)\n");
      }
      return -1;
    }
  }
  ++this->m_NumAlloced;
  this->m_LastAlloc.index = result;
  goto LABEL_23;
}

//------------------------------------------------------------------------------
// Address: 0x103C9CA0
// Name: public: void CUtlLinkedList<class vgui::TreeNode __near *,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<class vgui::TreeNode __near *,int>,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<vgui::TreeNode *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int>>::RemoveAll(
        CUtlLinkedList<vgui::TreeNode *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int> > *this)
{
  int m_Head; // eax
  UtlLinkedListElem_t<vgui::TreeNode *,int> *v2; // esi
  int m_Next; // edx
  int m_FirstFree; // eax
  int v5; // eax

  if ( this->m_LastAlloc.index != -1 )
  {
    m_Head = this->m_Head;
    if ( m_Head != -1 )
    {
      do
      {
        v2 = &this->m_Memory.m_pMemory[m_Head];
        m_Next = v2->m_Next;
        v2->m_Previous = m_Head;
        if ( m_Next == -1 )
          m_FirstFree = this->m_FirstFree;
        else
          m_FirstFree = m_Next;
        v2->m_Next = m_FirstFree;
        m_Head = m_Next;
      }
      while ( m_Next != -1 );
    }
    v5 = this->m_Head;
    if ( v5 != -1 )
      this->m_FirstFree = v5;
    this->m_Head = -1;
    this->m_Tail = -1;
    this->m_ElementCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1042C5F0
// Name: PrecacheEffectMuzzleFlashPrecache::_dynamic_initializer_for__s_ResourcePrecacher__
// Source: json
//------------------------------------------------------------------------------
CBaseResourcePrecacher *PrecacheEffectMuzzleFlashPrecache::_dynamic_initializer_for__s_ResourcePrecacher__()
{
  CBaseResourcePrecacher *result; // eax

  result = CBaseResourcePrecacher::sm_pFirst[0];
  PrecacheEffectMuzzleFlashPrecache::s_ResourcePrecacher.m_pNext = CBaseResourcePrecacher::sm_pFirst[0];
  CBaseResourcePrecacher::sm_pFirst[0] = &PrecacheEffectMuzzleFlashPrecache::s_ResourcePrecacher;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1006E690
// Name: _C_BreakableSurface_CreateObject
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IClientNetworkable *__cdecl C_BreakableSurface_CreateObject(int entnum, int serialNum)
{
  C_BreakableSurface *v2; // eax
  C_BreakableSurface *v3; // eax
  C_BreakableSurface *v4; // esi

  v2 = (C_BreakableSurface *)C_BaseEntity::operator new(stAllocateBlock: 0xDB0u);
  if ( v2 == nullptr )
    return nullptr;
  v3 = C_BreakableSurface::C_BreakableSurface(this: v2);
  v4 = v3;
  if ( v3 == nullptr )
    return nullptr;
  v3->Init(this: v3, a2: entnum, a3: serialNum);
  return &v4->IClientNetworkable;
}

//------------------------------------------------------------------------------
// Address: 0x1006E710
// Name: struct datamap_t __near * DataMapInit<class C_BreakableSurface>(class C_BreakableSurface __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<C_BreakableSurface>()
{
  if ( (_S5_39 & 1) == 0 )
  {
    _S5_39 |= 1u;
    nameHolder_7.m_pszBase = "C_BreakableSurface";
    nameHolder_7.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_7.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_7.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_7.m_Names.m_Size = 0;
    nameHolder_7.m_Names.m_pElements = nullptr;
    nameHolder_7.m_nLenBase = 18;
    atexit(func: DataMapInit_C_BreakableSurface__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  C_BreakableSurface::m_DataMap.baseMap = &C_BaseEntity::m_DataMap;
  C_BreakableSurface::m_DataMap.dataNumFields = 1;
  C_BreakableSurface::m_DataMap.dataDesc = &dataDesc_7[1];
  return &C_BreakableSurface::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x101BD950
// Name: _C_CSPlayer_CreateObject
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IClientNetworkable *__cdecl C_CSPlayer_CreateObject(int entnum, int serialNum)
{
  C_CSPlayer *v2; // eax
  C_CSPlayer *v3; // eax
  C_CSPlayer *v4; // esi

  v2 = (C_CSPlayer *)C_BaseEntity::operator new(stAllocateBlock: 0x1CB8u);
  if ( v2 == nullptr )
    return nullptr;
  v3 = C_CSPlayer::C_CSPlayer(this: v2);
  v4 = v3;
  if ( v3 == nullptr )
    return nullptr;
  v3->Init(this: v3, a2: entnum, a3: serialNum);
  return &v4->IClientNetworkable;
}

//------------------------------------------------------------------------------
// Address: 0x102412E0
// Name: _C_Embers_CreateObject
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IClientNetworkable *__cdecl C_Embers_CreateObject(int entnum, int serialNum)
{
  C_Embers *v2; // eax
  C_Embers *v3; // eax
  C_Embers *v4; // esi

  v2 = (C_Embers *)C_BaseEntity::operator new(stAllocateBlock: 0x9A0u);
  if ( v2 == nullptr )
    return nullptr;
  v3 = C_Embers::C_Embers(this: v2);
  v4 = v3;
  if ( v3 == nullptr )
    return nullptr;
  v3->Init(this: v3, a2: entnum, a3: serialNum);
  return &v4->IClientNetworkable;
}

//------------------------------------------------------------------------------
// Address: 0x10241D60
// Name: _C_PrecipitationBlocker_CreateObject
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IClientNetworkable *__cdecl C_PrecipitationBlocker_CreateObject(int entnum, int serialNum)
{
  C_PrecipitationBlocker *v2; // eax
  C_PrecipitationBlocker *v3; // eax
  C_PrecipitationBlocker *v4; // esi

  v2 = (C_PrecipitationBlocker *)C_BaseEntity::operator new(stAllocateBlock: 0x980u);
  if ( v2 == nullptr )
    return nullptr;
  v3 = C_PrecipitationBlocker::C_PrecipitationBlocker(this: v2);
  v4 = v3;
  if ( v3 == nullptr )
    return nullptr;
  v3->Init(this: v3, a2: entnum, a3: serialNum);
  return &v4->IClientNetworkable;
}
