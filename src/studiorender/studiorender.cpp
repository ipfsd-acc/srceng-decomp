// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: studiorender/studiorender.cpp
// Functions: 93
// ============================================================

#include "studiorender\studiorender.h"

//------------------------------------------------------------------------------
// Address: 0x10003EE0
// Name: public: void CUtlLinkedList<struct DecalVertex_t,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<struct DecalVertex_t,unsigned short>,unsigned short>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<DecalVertex_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<DecalVertex_t,unsigned short>,unsigned short>>::RemoveAll(
        CUtlLinkedList<DecalVertex_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<DecalVertex_t,unsigned short>,unsigned short> > *this)
{
  unsigned __int16 m_Head; // si
  UtlLinkedListElem_t<DecalVertex_t,unsigned short> *v2; // edx
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
// Address: 0x10003F50
// Name: public: void CUtlLinkedList<struct CStudioRender::Decal_t,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<struct CStudioRender::Decal_t,unsigned short>,unsigned short>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CStudioRender::Decal_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CStudioRender::Decal_t,unsigned short>,unsigned short>>::RemoveAll(
        CUtlLinkedList<CStudioRender::Decal_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CStudioRender::Decal_t,unsigned short>,unsigned short> > *this)
{
  unsigned __int16 m_Head; // si
  UtlLinkedListElem_t<CStudioRender::Decal_t,unsigned short> *v2; // edx
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
// Address: 0x10003FC0
// Name: public: void CUtlLinkedList<struct CStudioRender::DecalHistory_t,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<struct CStudioRender::DecalHistory_t,unsigned short>,unsigned short>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CStudioRender::DecalHistory_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CStudioRender::DecalHistory_t,unsigned short>,unsigned short>>::RemoveAll(
        CUtlLinkedList<CStudioRender::DecalHistory_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CStudioRender::DecalHistory_t,unsigned short>,unsigned short> > *this)
{
  unsigned __int16 m_Head; // si
  UtlLinkedListElem_t<CStudioRender::DecalHistory_t,unsigned short> *v2; // edx
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
// Address: 0x10004030
// Name: protected: unsigned short CUtlLinkedList<struct CStudioRender::DecalMaterial_t,unsigned short,1,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<struct CStudioRender::DecalMaterial_t,unsigned short>,unsigned short>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<CStudioRender::DecalMaterial_t,unsigned short,1,unsigned short,CUtlMemory<UtlLinkedListElem_t<CStudioRender::DecalMaterial_t,unsigned short>,unsigned short>>::AllocInternal(
        CUtlLinkedList<CStudioRender::DecalMaterial_t,unsigned short,1,unsigned short,CUtlMemory<UtlLinkedListElem_t<CStudioRender::DecalMaterial_t,unsigned short>,unsigned short> > *this,
        bool multilist)
{
  int m_FirstFree; // ecx
  int m_nAllocationCount; // ecx
  unsigned __int16 index; // ax
  int result; // eax
  int v7; // ecx
  unsigned __int16 v8; // ax
  unsigned int v9; // ecx
  UtlLinkedListElem_t<CStudioRender::DecalMaterial_t,unsigned short> *m_pMemory; // edx
  UtlLinkedListElem_t<CStudioRender::DecalMaterial_t,unsigned short> *v11; // ecx

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
    CUtlMemory<UtlLinkedListElem_t<CStudioRender::DecalMaterial_t,unsigned short>,unsigned short>::Grow(
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
      if ( `CUtlLinkedList<CStudioRender::DecalMaterial_t,unsigned short,1,unsigned short,CUtlMemory<UtlLinkedListElem_t<CStudioRender::DecalMaterial_t,unsigned short>,unsigned short>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<CStudioRender::DecalMaterial_t,unsigned short,1,unsigned short,CUtlMemory<UtlLinkedListElem_t<CStudioRender::DecalMaterial_t,unsigned short>,unsigned short>>::AllocInternal'::`12'::__executeCount;
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
  if ( `CUtlLinkedList<CStudioRender::DecalMaterial_t,unsigned short,1,unsigned short,CUtlMemory<UtlLinkedListElem_t<CStudioRender::DecalMaterial_t,unsigned short>,unsigned short>>::AllocInternal'::`19'::__executeCount >= 10 )
    return 0xFFFF;
  ++`CUtlLinkedList<CStudioRender::DecalMaterial_t,unsigned short,1,unsigned short,CUtlMemory<UtlLinkedListElem_t<CStudioRender::DecalMaterial_t,unsigned short>,unsigned short>>::AllocInternal'::`19'::__executeCount;
  _Warning(a1: "CUtlLinkedList overflow! (exhausted index range)\n");
  return 0xFFFF;
}

//------------------------------------------------------------------------------
// Address: 0x100041B0
// Name: protected: unsigned short CUtlLinkedList<struct DecalVertex_t,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<struct DecalVertex_t,unsigned short>,unsigned short>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<DecalVertex_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<DecalVertex_t,unsigned short>,unsigned short>>::AllocInternal(
        CUtlLinkedList<DecalVertex_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<DecalVertex_t,unsigned short>,unsigned short> > *this,
        bool multilist)
{
  int m_FirstFree; // ecx
  int m_nAllocationCount; // ecx
  unsigned __int16 index; // ax
  int result; // eax
  int v7; // ecx
  unsigned __int16 v8; // ax
  UtlLinkedListElem_t<DecalVertex_t,unsigned short> *m_pMemory; // edx
  int v10; // ecx
  UtlLinkedListElem_t<DecalVertex_t,unsigned short> *v11; // ecx

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
    CUtlMemory<UtlLinkedListElem_t<DecalVertex_t,unsigned short>,unsigned short>::Grow(this: &this->m_Memory, num: 1);
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
      if ( `CUtlLinkedList<DecalVertex_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<DecalVertex_t,unsigned short>,unsigned short>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<DecalVertex_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<DecalVertex_t,unsigned short>,unsigned short>>::AllocInternal'::`12'::__executeCount;
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
  if ( `CUtlLinkedList<DecalVertex_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<DecalVertex_t,unsigned short>,unsigned short>>::AllocInternal'::`19'::__executeCount >= 10 )
    return 0xFFFF;
  ++`CUtlLinkedList<DecalVertex_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<DecalVertex_t,unsigned short>,unsigned short>>::AllocInternal'::`19'::__executeCount;
  _Warning(a1: "CUtlLinkedList overflow! (exhausted index range)\n");
  return 0xFFFF;
}

//------------------------------------------------------------------------------
// Address: 0x10004330
// Name: protected: unsigned short CUtlLinkedList<struct CStudioRender::Decal_t,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<struct CStudioRender::Decal_t,unsigned short>,unsigned short>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<CStudioRender::Decal_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CStudioRender::Decal_t,unsigned short>,unsigned short>>::AllocInternal(
        CUtlLinkedList<CStudioRender::Decal_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CStudioRender::Decal_t,unsigned short>,unsigned short> > *this,
        bool multilist)
{
  int m_FirstFree; // ecx
  int m_nAllocationCount; // ecx
  unsigned __int16 index; // ax
  int result; // eax
  int v7; // ecx
  unsigned __int16 v8; // ax
  UtlLinkedListElem_t<CStudioRender::Decal_t,unsigned short> *v9; // ecx

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
    CUtlMemory<UtlLinkedListElem_t<CStudioRender::Decal_t,unsigned short>,unsigned short>::Grow(
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
      if ( `CUtlLinkedList<CStudioRender::Decal_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CStudioRender::Decal_t,unsigned short>,unsigned short>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<CStudioRender::Decal_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CStudioRender::Decal_t,unsigned short>,unsigned short>>::AllocInternal'::`12'::__executeCount;
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
  if ( `CUtlLinkedList<CStudioRender::Decal_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CStudioRender::Decal_t,unsigned short>,unsigned short>>::AllocInternal'::`19'::__executeCount >= 10 )
    return 0xFFFF;
  ++`CUtlLinkedList<CStudioRender::Decal_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CStudioRender::Decal_t,unsigned short>,unsigned short>>::AllocInternal'::`19'::__executeCount;
  _Warning(a1: "CUtlLinkedList overflow! (exhausted index range)\n");
  return 0xFFFF;
}

//------------------------------------------------------------------------------
// Address: 0x100044B0
// Name: protected: unsigned short CUtlLinkedList<struct CStudioRender::DecalHistory_t,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<struct CStudioRender::DecalHistory_t,unsigned short>,unsigned short>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<CStudioRender::DecalHistory_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CStudioRender::DecalHistory_t,unsigned short>,unsigned short>>::AllocInternal(
        CUtlLinkedList<CStudioRender::DecalHistory_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CStudioRender::DecalHistory_t,unsigned short>,unsigned short> > *this,
        bool multilist)
{
  int m_FirstFree; // ecx
  int m_nAllocationCount; // ecx
  unsigned __int16 index; // ax
  int result; // eax
  int v7; // ecx
  unsigned __int16 v8; // ax
  UtlLinkedListElem_t<CStudioRender::DecalHistory_t,unsigned short> *v9; // ecx

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
    CUtlMemory<UtlLinkedListElem_t<CStudioRender::DecalHistory_t,unsigned short>,unsigned short>::Grow(
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
      if ( `CUtlLinkedList<CStudioRender::DecalHistory_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CStudioRender::DecalHistory_t,unsigned short>,unsigned short>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<CStudioRender::DecalHistory_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CStudioRender::DecalHistory_t,unsigned short>,unsigned short>>::AllocInternal'::`12'::__executeCount;
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
  if ( `CUtlLinkedList<CStudioRender::DecalHistory_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CStudioRender::DecalHistory_t,unsigned short>,unsigned short>>::AllocInternal'::`19'::__executeCount >= 10 )
    return 0xFFFF;
  ++`CUtlLinkedList<CStudioRender::DecalHistory_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CStudioRender::DecalHistory_t,unsigned short>,unsigned short>>::AllocInternal'::`19'::__executeCount;
  _Warning(a1: "CUtlLinkedList overflow! (exhausted index range)\n");
  return 0xFFFF;
}

//------------------------------------------------------------------------------
// Address: 0x100066A0
// Name: public: void CUtlLinkedList<struct CStudioRender::DecalMaterial_t,unsigned short,1,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<struct CStudioRender::DecalMaterial_t,unsigned short>,unsigned short>>::Unlink(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CStudioRender::DecalMaterial_t,unsigned short,1,unsigned short,CUtlMemory<UtlLinkedListElem_t<CStudioRender::DecalMaterial_t,unsigned short>,unsigned short>>::Unlink(
        CUtlLinkedList<CStudioRender::DecalMaterial_t,unsigned short,1,unsigned short,CUtlMemory<UtlLinkedListElem_t<CStudioRender::DecalMaterial_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 elem)
{
  unsigned __int16 v2; // bx
  UtlLinkedListElem_t<CStudioRender::DecalMaterial_t,unsigned short> *v3; // eax
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
// Address: 0x10006820
// Name: public: void CUtlLinkedList<struct DecalVertex_t,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<struct DecalVertex_t,unsigned short>,unsigned short>>::Unlink(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<DecalVertex_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<DecalVertex_t,unsigned short>,unsigned short>>::Unlink(
        CUtlLinkedList<DecalVertex_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<DecalVertex_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 elem)
{
  unsigned __int16 v2; // di
  UtlLinkedListElem_t<DecalVertex_t,unsigned short> *v3; // eax
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
// Address: 0x100068C0
// Name: public: void CUtlLinkedList<struct CStudioRender::Decal_t,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<struct CStudioRender::Decal_t,unsigned short>,unsigned short>>::Unlink(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CStudioRender::Decal_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CStudioRender::Decal_t,unsigned short>,unsigned short>>::Unlink(
        CUtlLinkedList<CStudioRender::Decal_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CStudioRender::Decal_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 elem)
{
  unsigned __int16 v2; // di
  UtlLinkedListElem_t<CStudioRender::Decal_t,unsigned short> *v3; // eax
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
// Address: 0x10006950
// Name: public: void CUtlLinkedList<struct CStudioRender::DecalHistory_t,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<struct CStudioRender::DecalHistory_t,unsigned short>,unsigned short>>::Unlink(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CStudioRender::DecalHistory_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CStudioRender::DecalHistory_t,unsigned short>,unsigned short>>::Unlink(
        CUtlLinkedList<CStudioRender::DecalHistory_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CStudioRender::DecalHistory_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 elem)
{
  unsigned __int16 v2; // di
  UtlLinkedListElem_t<CStudioRender::DecalHistory_t,unsigned short> *v3; // eax
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
// Address: 0x100069E0
// Name: protected: int CUtlLinkedList<struct CStudioRender::DecalLRU_t,int,1,int,class CUtlFixedMemory<struct UtlLinkedListElem_t<struct CStudioRender::DecalLRU_t,int>>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
CUtlFixedMemory<UtlLinkedListElem_t<CStudioRender::DecalLRU_t,int> >::BlockHeader_t *__thiscall CUtlLinkedList<CStudioRender::DecalLRU_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CStudioRender::DecalLRU_t,int>>>::AllocInternal(
        CUtlLinkedList<CStudioRender::DecalLRU_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CStudioRender::DecalLRU_t,int> > > *this,
        bool multilist)
{
  CUtlFixedMemory<UtlLinkedListElem_t<CStudioRender::DecalLRU_t,int> >::BlockHeader_t *result; // eax
  CUtlFixedMemory<UtlLinkedListElem_t<CStudioRender::DecalLRU_t,int> >::BlockHeader_t *m_pBlockHeader; // eax
  CUtlFixedMemory<UtlLinkedListElem_t<CStudioRender::DecalLRU_t,int> >::Iterator_t *p_m_LastAlloc; // esi
  int m_nIndex; // ecx
  CUtlFixedMemory<UtlLinkedListElem_t<CStudioRender::DecalModelList_t,int> >::Iterator_t *v7; // eax
  CUtlFixedMemory<UtlLinkedListElem_t<CStudioRender::DecalLRU_t,int> >::BlockHeader_t *v8; // ecx
  int v9; // eax
  int v10; // ecx
  CUtlFixedMemory<UtlLinkedListElem_t<CStudioRender::DecalModelList_t,int> >::Iterator_t *v11; // eax
  int v12; // esi
  CUtlFixedMemory<UtlLinkedListElem_t<CStudioRender::DecalModelList_t,int> >::Iterator_t v13; // [esp+Ch] [ebp-18h] BYREF
  CUtlFixedMemory<UtlLinkedListElem_t<CStudioRender::DecalModelList_t,int> >::Iterator_t v14; // [esp+14h] [ebp-10h] BYREF
  CUtlFixedMemory<UtlLinkedListElem_t<CStudioRender::DecalModelList_t,int> >::Iterator_t v15; // [esp+1Ch] [ebp-8h] BYREF

  result = (CUtlFixedMemory<UtlLinkedListElem_t<CStudioRender::DecalLRU_t,int> >::BlockHeader_t *)this->m_FirstFree;
  if ( result != nullptr )
  {
    this->m_FirstFree = result[1].m_nBlockSize;
LABEL_36:
    if ( multilist )
    {
      result[1].m_nBlockSize = 0;
      result[1].m_pNext = nullptr;
    }
    else
    {
      result[1].m_nBlockSize = (int)result;
      result[1].m_pNext = result;
    }
    return result;
  }
  m_pBlockHeader = this->m_LastAlloc.m_pBlockHeader;
  p_m_LastAlloc = &this->m_LastAlloc;
  if ( m_pBlockHeader != nullptr
    && (m_nIndex = this->m_LastAlloc.m_nIndex) >= 0
    && m_nIndex < m_pBlockHeader->m_nBlockSize )
  {
    v7 = CUtlFixedMemory<UtlLinkedListElem_t<CStudioRender::DecalLRU_t,int>>::Next(
           (CUtlFixedMemory<UtlLinkedListElem_t<CStudioRender::DecalModelList_t,int> > *)this,
           result: &v13,
           it: (const CUtlFixedMemory<UtlLinkedListElem_t<CStudioRender::DecalModelList_t,int> >::Iterator_t *)&this->m_LastAlloc);
  }
  else
  {
    if ( this->m_Memory.m_pBlocks != nullptr )
    {
      v15.m_pBlockHeader = (CUtlFixedMemory<UtlLinkedListElem_t<CStudioRender::DecalModelList_t,int> >::BlockHeader_t *)this->m_Memory.m_pBlocks;
      v15.m_nIndex = 0;
    }
    else
    {
      v15.m_pBlockHeader = nullptr;
      v15.m_nIndex = -1;
    }
    v14 = v15;
    v7 = &v14;
  }
  v8 = (CUtlFixedMemory<UtlLinkedListElem_t<CStudioRender::DecalLRU_t,int> >::BlockHeader_t *)v7->m_pBlockHeader;
  v9 = v7->m_nIndex;
  if ( v8 == nullptr || v9 < 0 || v9 >= v8->m_nBlockSize )
  {
    CUtlFixedMemory<UtlLinkedListElem_t<CStudioRender::DecalLRU_t,int>>::Grow(this: &this->m_Memory, num: 1);
    this->m_pElements = nullptr;
    if ( p_m_LastAlloc->m_pBlockHeader != nullptr
      && (v10 = this->m_LastAlloc.m_nIndex) >= 0
      && v10 < p_m_LastAlloc->m_pBlockHeader->m_nBlockSize )
    {
      v11 = CUtlFixedMemory<UtlLinkedListElem_t<CStudioRender::DecalLRU_t,int>>::Next(
              (CUtlFixedMemory<UtlLinkedListElem_t<CStudioRender::DecalModelList_t,int> > *)this,
              result: &v14,
              it: (const CUtlFixedMemory<UtlLinkedListElem_t<CStudioRender::DecalModelList_t,int> >::Iterator_t *)&this->m_LastAlloc);
    }
    else
    {
      if ( this->m_Memory.m_pBlocks != nullptr )
      {
        v14.m_pBlockHeader = (CUtlFixedMemory<UtlLinkedListElem_t<CStudioRender::DecalModelList_t,int> >::BlockHeader_t *)this->m_Memory.m_pBlocks;
        v14.m_nIndex = 0;
      }
      else
      {
        v14.m_pBlockHeader = nullptr;
        v14.m_nIndex = -1;
      }
      v15 = v14;
      v11 = &v15;
    }
    v8 = (CUtlFixedMemory<UtlLinkedListElem_t<CStudioRender::DecalLRU_t,int> >::BlockHeader_t *)v11->m_pBlockHeader;
    v9 = v11->m_nIndex;
    if ( v8 == nullptr || v9 < 0 || v9 >= v8->m_nBlockSize )
    {
      if ( `CUtlLinkedList<CStudioRender::DecalLRU_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CStudioRender::DecalLRU_t,int>>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<CStudioRender::DecalLRU_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CStudioRender::DecalLRU_t,int>>>::AllocInternal'::`12'::__executeCount;
        _Warning(a1: "CUtlLinkedList overflow! (exhausted memory allocator)\n");
      }
      return nullptr;
    }
  }
  if ( &v8[2 * v9] != (CUtlFixedMemory<UtlLinkedListElem_t<CStudioRender::DecalLRU_t,int> >::BlockHeader_t *)-8 )
  {
    this->m_LastAlloc.m_nIndex = v9;
    p_m_LastAlloc->m_pBlockHeader = v8;
    v12 = this->m_LastAlloc.m_nIndex;
    if ( v12 >= 0 && v12 < v8->m_nBlockSize )
    {
      ++this->m_NumAlloced;
      result = &v8[2 * v12 + 1];
    }
    else
    {
      result = nullptr;
      ++this->m_NumAlloced;
    }
    goto LABEL_36;
  }
  if ( `CUtlLinkedList<CStudioRender::DecalLRU_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CStudioRender::DecalLRU_t,int>>>::AllocInternal'::`19'::__executeCount >= 10 )
    return nullptr;
  ++`CUtlLinkedList<CStudioRender::DecalLRU_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CStudioRender::DecalLRU_t,int>>>::AllocInternal'::`19'::__executeCount;
  _Warning(a1: "CUtlLinkedList overflow! (exhausted index range)\n");
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10006B70
// Name: protected: int CUtlLinkedList<struct CStudioRender::DecalModelList_t,int,1,int,class CUtlFixedMemory<struct UtlLinkedListElem_t<struct CStudioRender::DecalModelList_t,int>>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<CStudioRender::DecalModelList_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CStudioRender::DecalModelList_t,int>>>::AllocInternal(
        CUtlLinkedList<CStudioRender::DecalModelList_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CStudioRender::DecalModelList_t,int> > > *this,
        bool multilist)
{
  int result; // eax
  CUtlFixedMemory<UtlLinkedListElem_t<CStudioRender::DecalModelList_t,int> >::BlockHeader_t *m_pBlockHeader; // eax
  CUtlFixedMemory<UtlLinkedListElem_t<CStudioRender::DecalModelList_t,int> >::Iterator_t *p_m_LastAlloc; // esi
  int m_nIndex; // ecx
  CUtlFixedMemory<UtlLinkedListElem_t<CStudioRender::DecalModelList_t,int> >::Iterator_t *v7; // eax
  CUtlFixedMemory<UtlLinkedListElem_t<CStudioRender::DecalModelList_t,int> >::BlockHeader_t *v8; // ecx
  int v9; // eax
  int v10; // ecx
  CUtlFixedMemory<UtlLinkedListElem_t<CStudioRender::DecalModelList_t,int> >::Iterator_t *v11; // eax
  int v12; // esi
  CUtlFixedMemory<UtlLinkedListElem_t<CStudioRender::DecalModelList_t,int> >::Iterator_t v13; // [esp+Ch] [ebp-18h] BYREF
  CUtlFixedMemory<UtlLinkedListElem_t<CStudioRender::DecalModelList_t,int> >::Iterator_t v14; // [esp+14h] [ebp-10h] BYREF
  CUtlFixedMemory<UtlLinkedListElem_t<CStudioRender::DecalModelList_t,int> >::Iterator_t v15; // [esp+1Ch] [ebp-8h] BYREF

  result = this->m_FirstFree;
  if ( result != 0 )
  {
    this->m_FirstFree = *(_DWORD *)(result + 16);
LABEL_36:
    if ( multilist )
    {
      *(_DWORD *)(result + 16) = 0;
      *(_DWORD *)(result + 12) = 0;
    }
    else
    {
      *(_DWORD *)(result + 16) = result;
      *(_DWORD *)(result + 12) = result;
    }
    return result;
  }
  m_pBlockHeader = this->m_LastAlloc.m_pBlockHeader;
  p_m_LastAlloc = &this->m_LastAlloc;
  if ( m_pBlockHeader != nullptr
    && (m_nIndex = this->m_LastAlloc.m_nIndex) >= 0
    && m_nIndex < m_pBlockHeader->m_nBlockSize )
  {
    v7 = CUtlFixedMemory<UtlLinkedListElem_t<CStudioRender::DecalLRU_t,int>>::Next(
           this: &this->m_Memory,
           result: &v13,
           it: &this->m_LastAlloc);
  }
  else
  {
    if ( this->m_Memory.m_pBlocks != nullptr )
    {
      v15.m_pBlockHeader = this->m_Memory.m_pBlocks;
      v15.m_nIndex = 0;
    }
    else
    {
      v15.m_pBlockHeader = nullptr;
      v15.m_nIndex = -1;
    }
    v14 = v15;
    v7 = &v14;
  }
  v8 = v7->m_pBlockHeader;
  v9 = v7->m_nIndex;
  if ( v8 == nullptr || v9 < 0 || v9 >= v8->m_nBlockSize )
  {
    CUtlFixedMemory<UtlLinkedListElem_t<CStudioRender::DecalModelList_t,int>>::Grow(this: &this->m_Memory, num: 1);
    this->m_pElements = nullptr;
    if ( p_m_LastAlloc->m_pBlockHeader != nullptr
      && (v10 = this->m_LastAlloc.m_nIndex) >= 0
      && v10 < p_m_LastAlloc->m_pBlockHeader->m_nBlockSize )
    {
      v11 = CUtlFixedMemory<UtlLinkedListElem_t<CStudioRender::DecalLRU_t,int>>::Next(
              this: &this->m_Memory,
              result: &v14,
              it: &this->m_LastAlloc);
    }
    else
    {
      if ( this->m_Memory.m_pBlocks != nullptr )
      {
        v14.m_pBlockHeader = this->m_Memory.m_pBlocks;
        v14.m_nIndex = 0;
      }
      else
      {
        v14.m_pBlockHeader = nullptr;
        v14.m_nIndex = -1;
      }
      v15 = v14;
      v11 = &v15;
    }
    v8 = v11->m_pBlockHeader;
    v9 = v11->m_nIndex;
    if ( v8 == nullptr || v9 < 0 || v9 >= v8->m_nBlockSize )
    {
      if ( `CUtlLinkedList<CStudioRender::DecalModelList_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CStudioRender::DecalModelList_t,int>>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<CStudioRender::DecalModelList_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CStudioRender::DecalModelList_t,int>>>::AllocInternal'::`12'::__executeCount;
        _Warning(a1: "CUtlLinkedList overflow! (exhausted memory allocator)\n");
      }
      return 0;
    }
  }
  if ( (CUtlFixedMemory<UtlLinkedListElem_t<CStudioRender::DecalModelList_t,int> >::BlockHeader_t *)((char *)v8 + 20 * v9) != (CUtlFixedMemory<UtlLinkedListElem_t<CStudioRender::DecalModelList_t,int> >::BlockHeader_t *)-8 )
  {
    this->m_LastAlloc.m_nIndex = v9;
    p_m_LastAlloc->m_pBlockHeader = v8;
    v12 = this->m_LastAlloc.m_nIndex;
    if ( v12 >= 0 && v12 < v8->m_nBlockSize )
    {
      ++this->m_NumAlloced;
      result = (int)&v8[1] + 20 * v12;
    }
    else
    {
      result = 0;
      ++this->m_NumAlloced;
    }
    goto LABEL_36;
  }
  if ( `CUtlLinkedList<CStudioRender::DecalModelList_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CStudioRender::DecalModelList_t,int>>>::AllocInternal'::`19'::__executeCount >= 10 )
    return 0;
  ++`CUtlLinkedList<CStudioRender::DecalModelList_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CStudioRender::DecalModelList_t,int>>>::AllocInternal'::`19'::__executeCount;
  _Warning(a1: "CUtlLinkedList overflow! (exhausted index range)\n");
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10006D00
// Name: public: void CUtlLinkedList<struct CStudioRender::DecalMaterial_t,unsigned short,1,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<struct CStudioRender::DecalMaterial_t,unsigned short>,unsigned short>>::LinkBefore(unsigned short,unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CStudioRender::DecalMaterial_t,unsigned short,1,unsigned short,CUtlMemory<UtlLinkedListElem_t<CStudioRender::DecalMaterial_t,unsigned short>,unsigned short>>::LinkBefore(
        CUtlLinkedList<CStudioRender::DecalMaterial_t,unsigned short,1,unsigned short,CUtlMemory<UtlLinkedListElem_t<CStudioRender::DecalMaterial_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 before,
        unsigned __int16 elem)
{
  UtlLinkedListElem_t<CStudioRender::DecalMaterial_t,unsigned short> *m_pMemory; // ebx
  unsigned int v5; // eax
  unsigned __int16 m_Tail; // dx
  int v7; // ecx

  CUtlLinkedList<CStudioRender::DecalMaterial_t,unsigned short,1,unsigned short,CUtlMemory<UtlLinkedListElem_t<CStudioRender::DecalMaterial_t,unsigned short>,unsigned short>>::Unlink(
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
// Address: 0x10006D90
// Name: public: void CUtlLinkedList<struct DecalVertex_t,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<struct DecalVertex_t,unsigned short>,unsigned short>>::LinkBefore(unsigned short,unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<DecalVertex_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<DecalVertex_t,unsigned short>,unsigned short>>::LinkBefore(
        CUtlLinkedList<DecalVertex_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<DecalVertex_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 before,
        unsigned __int16 elem)
{
  UtlLinkedListElem_t<DecalVertex_t,unsigned short> *m_pMemory; // ebx
  unsigned __int16 m_Tail; // dx

  CUtlLinkedList<DecalVertex_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<DecalVertex_t,unsigned short>,unsigned short>>::Unlink(
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
// Address: 0x10006E20
// Name: public: void CUtlLinkedList<struct CStudioRender::Decal_t,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<struct CStudioRender::Decal_t,unsigned short>,unsigned short>>::LinkBefore(unsigned short,unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CStudioRender::Decal_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CStudioRender::Decal_t,unsigned short>,unsigned short>>::LinkBefore(
        CUtlLinkedList<CStudioRender::Decal_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CStudioRender::Decal_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 before,
        unsigned __int16 elem)
{
  UtlLinkedListElem_t<CStudioRender::Decal_t,unsigned short> *m_pMemory; // edx
  UtlLinkedListElem_t<CStudioRender::Decal_t,unsigned short> *v5; // ecx
  unsigned __int16 m_Tail; // ax
  UtlLinkedListElem_t<CStudioRender::Decal_t,unsigned short> *v7; // ebx

  CUtlLinkedList<CStudioRender::Decal_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CStudioRender::Decal_t,unsigned short>,unsigned short>>::Unlink(
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
// Address: 0x10006EB0
// Name: public: void CUtlLinkedList<struct CStudioRender::DecalHistory_t,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<struct CStudioRender::DecalHistory_t,unsigned short>,unsigned short>>::LinkBefore(unsigned short,unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CStudioRender::DecalHistory_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CStudioRender::DecalHistory_t,unsigned short>,unsigned short>>::LinkBefore(
        CUtlLinkedList<CStudioRender::DecalHistory_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CStudioRender::DecalHistory_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 before,
        unsigned __int16 elem)
{
  UtlLinkedListElem_t<CStudioRender::DecalHistory_t,unsigned short> *m_pMemory; // edx
  UtlLinkedListElem_t<CStudioRender::DecalHistory_t,unsigned short> *v5; // ecx
  unsigned __int16 m_Tail; // ax
  UtlLinkedListElem_t<CStudioRender::DecalHistory_t,unsigned short> *v7; // ebx

  CUtlLinkedList<CStudioRender::DecalHistory_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CStudioRender::DecalHistory_t,unsigned short>,unsigned short>>::Unlink(
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
// Address: 0x10006F40
// Name: public: void CUtlLinkedList<struct CStudioRender::DecalLRU_t,int,1,int,class CUtlFixedMemory<struct UtlLinkedListElem_t<struct CStudioRender::DecalLRU_t,int>>>::LinkBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CStudioRender::DecalLRU_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CStudioRender::DecalLRU_t,int>>>::LinkBefore(
        CUtlLinkedList<CStudioRender::DecalLRU_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CStudioRender::DecalLRU_t,int> > > *this,
        int before,
        int elem)
{
  int v4; // eax
  int v5; // eax
  int m_Tail; // eax

  if ( elem != 0
    && !CUtlFixedMemory<UtlLinkedListElem_t<CStudioRender::DecalLRU_t,int>>::IsIdxAfter(
          this: &this->m_Memory,
          i: elem,
          it: &this->m_LastAlloc) )
  {
    v4 = *(_DWORD *)(elem + 8);
    if ( v4 != elem )
    {
      if ( v4 != 0 )
        *(_DWORD *)(v4 + 12) = *(_DWORD *)(elem + 12);
      else
        this->m_Head = *(_DWORD *)(elem + 12);
      v5 = *(_DWORD *)(elem + 12);
      if ( v5 != 0 )
        *(_DWORD *)(v5 + 8) = *(_DWORD *)(elem + 8);
      else
        this->m_Tail = *(_DWORD *)(elem + 8);
      *(_DWORD *)(elem + 12) = elem;
      *(_DWORD *)(elem + 8) = elem;
      --this->m_ElementCount;
    }
  }
  *(_DWORD *)(elem + 12) = before;
  if ( before != 0 )
  {
    m_Tail = *(_DWORD *)(before + 8);
    *(_DWORD *)(before + 8) = elem;
  }
  else
  {
    m_Tail = this->m_Tail;
    this->m_Tail = elem;
  }
  *(_DWORD *)(elem + 8) = m_Tail;
  if ( m_Tail != 0 )
  {
    *(_DWORD *)(m_Tail + 12) = elem;
    ++this->m_ElementCount;
  }
  else
  {
    ++this->m_ElementCount;
    this->m_Head = elem;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100070A0
// Name: public: void CUtlLinkedList<struct CStudioRender::DecalModelList_t,int,1,int,class CUtlFixedMemory<struct UtlLinkedListElem_t<struct CStudioRender::DecalModelList_t,int>>>::LinkBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CStudioRender::DecalModelList_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CStudioRender::DecalModelList_t,int>>>::LinkBefore(
        CUtlLinkedList<CStudioRender::DecalModelList_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CStudioRender::DecalModelList_t,int> > > *this,
        int before,
        int elem)
{
  int v4; // eax
  int v5; // eax
  int m_Tail; // eax

  if ( elem != 0
    && !CUtlFixedMemory<UtlLinkedListElem_t<CStudioRender::DecalModelList_t,int>>::IsIdxAfter(
          this: &this->m_Memory,
          i: elem,
          it: &this->m_LastAlloc) )
  {
    v4 = *(_DWORD *)(elem + 12);
    if ( v4 != elem )
    {
      if ( v4 != 0 )
        *(_DWORD *)(v4 + 16) = *(_DWORD *)(elem + 16);
      else
        this->m_Head = *(_DWORD *)(elem + 16);
      v5 = *(_DWORD *)(elem + 16);
      if ( v5 != 0 )
        *(_DWORD *)(v5 + 12) = *(_DWORD *)(elem + 12);
      else
        this->m_Tail = *(_DWORD *)(elem + 12);
      *(_DWORD *)(elem + 16) = elem;
      *(_DWORD *)(elem + 12) = elem;
      --this->m_ElementCount;
    }
  }
  *(_DWORD *)(elem + 16) = before;
  if ( before != 0 )
  {
    m_Tail = *(_DWORD *)(before + 12);
    *(_DWORD *)(before + 12) = elem;
  }
  else
  {
    m_Tail = this->m_Tail;
    this->m_Tail = elem;
  }
  *(_DWORD *)(elem + 12) = m_Tail;
  if ( m_Tail != 0 )
  {
    *(_DWORD *)(m_Tail + 16) = elem;
    ++this->m_ElementCount;
  }
  else
  {
    ++this->m_ElementCount;
    this->m_Head = elem;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000E410
// Name: protected: bool CUtlHash<struct studiohwdata_t __near *,bool (*)(struct studiohwdata_t __near * const __near &,struct studiohwdata_t __near * const __near &),unsigned int (*)(struct studiohwdata_t __near * const __near &)>::DoFind(struct studiohwdata_t __near * const __near &,unsigned int __near *,int __near *)const
// Source: json
//------------------------------------------------------------------------------
char __thiscall CUtlHash<studiohwdata_t *,bool (__cdecl *)(studiohwdata_t * const &,studiohwdata_t * const &),unsigned int (__cdecl *)(studiohwdata_t * const &)>::DoFind(
        CUtlHash<studiohwdata_t *,bool (__cdecl*)(studiohwdata_t * const &,studiohwdata_t * const &),unsigned int (__cdecl*)(studiohwdata_t * const &)> *this,
        studiohwdata_t *const *src,
        unsigned int *pBucket,
        int *pIndex)
{
  unsigned int v5; // eax
  unsigned int v6; // edx
  CUtlVector<studiohwdata_t *,CUtlMemory<studiohwdata_t *,int> > *v7; // ebx
  int m_Size; // eax
  int v9; // esi
  int keyDataCount; // [esp+18h] [ebp+Ch]

  v5 = this->m_KeyFunc(a1: src);
  if ( this->m_bPowerOfTwo )
    v6 = v5 & this->m_ModMask;
  else
    v6 = v5 % this->m_Buckets.m_Size;
  *pBucket = v6;
  v7 = &this->m_Buckets.m_Memory.m_pMemory[v6];
  m_Size = v7->m_Size;
  v9 = 0;
  keyDataCount = m_Size;
  if ( m_Size > 0 )
  {
    do
    {
      if ( this->m_CompareFunc(a1: &v7->m_Memory.m_pMemory[v9], a2: src) )
        break;
      ++v9;
    }
    while ( v9 < keyDataCount );
    m_Size = keyDataCount;
  }
  if ( v9 == m_Size )
    return 0;
  *pIndex = v9;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100111D0
// Name: public: void CCachedRenderData::ComputeFlexedVertex_StreamOffset<struct mstudiovertanim_t>(struct studiohdr_t __near *,struct mstudioflex_t __near *,struct mstudiovertanim_t __near *,int,float,float,float,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCachedRenderData::ComputeFlexedVertex_StreamOffset<mstudiovertanim_t>(
        CCachedRenderData *this,
        studiohdr_t *pStudioHdr,
        mstudioflex_t *pflex,
        mstudiovertanim_t *pvanim,
        int vertCount,
        float w1,
        float w2,
        float w3,
        float w4)
{
  float flVertAnimFixedPointScale; // xmm6_4
  unsigned __int8 *p_side; // esi
  int v12; // ecx
  float v13; // xmm0_4
  CCachedRenderData::CacheIndex_t *m_pFirstThinFlexIndex; // eax
  float v15; // xmm1_4
  float v16; // xmm2_4
  float v17; // xmm3_4
  float v18; // xmm4_4
  float v19; // xmm5_4
  CachedPosNorm_t *ThinFlexVertex; // eax
  float v21; // xmm0_4
  float v22; // xmm1_4
  float v23; // xmm5_4
  float v24; // xmm2_4
  float v25; // [esp-4h] [ebp-44h]
  float vPosition_12; // [esp+1Ch] [ebp-24h]
  int w34; // [esp+2Ch] [ebp-14h]
  float w12; // [esp+30h] [ebp-10h]

  if ( (pStudioHdr->flags & 0x200000) != 0 )
    flVertAnimFixedPointScale = pStudioHdr->flVertAnimFixedPointScale;
  else
    flVertAnimFixedPointScale = 0.00024414062;
  w12 = flVertAnimFixedPointScale;
  w34 = 0;
  if ( pflex->numverts > 0 )
  {
    p_side = &pvanim->side;
    do
    {
      v12 = *(unsigned __int16 *)(p_side - 3);
      if ( v12 < vertCount )
      {
        v13 = (float)*(p_side - 1);
        vPosition_12 = (float)*p_side;
        m_pFirstThinFlexIndex = this->m_pFirstThinFlexIndex;
        v15 = (float)*(__int16 *)(p_side + 1) * flVertAnimFixedPointScale;
        v16 = (float)*(__int16 *)(p_side + 3) * flVertAnimFixedPointScale;
        v17 = (float)*(__int16 *)(p_side + 5) * flVertAnimFixedPointScale;
        v18 = (float)*(__int16 *)(p_side + 7) * flVertAnimFixedPointScale;
        v19 = (float)*(__int16 *)(p_side + 9) * flVertAnimFixedPointScale;
        v25 = (float)*(__int16 *)(p_side + 11) * flVertAnimFixedPointScale;
        if ( m_pFirstThinFlexIndex != nullptr && m_pFirstThinFlexIndex[v12].m_Tag == this->m_CurrentTag )
        {
          ThinFlexVertex = &this->m_pThinFlexVerts[m_pFirstThinFlexIndex[v12].m_VertexIndex];
        }
        else
        {
          ThinFlexVertex = CCachedRenderData::CreateThinFlexVertex(this, vertex: v12);
          ThinFlexVertex->m_Position = (Vector4DAligned)xmmword_1006E580;
          ThinFlexVertex->m_Normal = (Vector4DAligned)xmmword_1006E580;
        }
        v21 = (float)((float)((float)((float)((float)(v13 * 0.0039215689) * (float)(w3 - w4)) + w4)
                            - (float)((float)((float)(v13 * 0.0039215689) * (float)(w1 - w2)) + w2))
                    * (float)(vPosition_12 * 0.0039215689))
            + (float)((float)((float)(v13 * 0.0039215689) * (float)(w1 - w2)) + w2);
        flVertAnimFixedPointScale = w12;
        ThinFlexVertex->m_Position.x = (float)(v15 * v21) + ThinFlexVertex->m_Position.x;
        ThinFlexVertex->m_Position.y = (float)(v16 * v21) + ThinFlexVertex->m_Position.y;
        ThinFlexVertex->m_Position.w = (float)(v21 * 0.0) + ThinFlexVertex->m_Position.w;
        ThinFlexVertex->m_Position.z = (float)(v17 * v21) + ThinFlexVertex->m_Position.z;
        v22 = (float)(v21 * 0.0) + ThinFlexVertex->m_Normal.w;
        v23 = (float)(v19 * v21) + ThinFlexVertex->m_Normal.y;
        v24 = (float)(v25 * v21) + ThinFlexVertex->m_Normal.z;
        ThinFlexVertex->m_Normal.x = (float)(v18 * v21) + ThinFlexVertex->m_Normal.x;
        ThinFlexVertex->m_Normal.y = v23;
        ThinFlexVertex->m_Normal.z = v24;
        ThinFlexVertex->m_Normal.w = v22;
      }
      p_side += 16;
      ++w34;
    }
    while ( w34 < pflex->numverts );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10011430
// Name: public: void CCachedRenderData::ComputeFlexedVertex_StreamOffset<struct mstudiovertanim_wrinkle_t>(struct studiohdr_t __near *,struct mstudioflex_t __near *,struct mstudiovertanim_wrinkle_t __near *,int,float,float,float,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCachedRenderData::ComputeFlexedVertex_StreamOffset<mstudiovertanim_wrinkle_t>(
        CCachedRenderData *this,
        studiohdr_t *pStudioHdr,
        mstudioflex_t *pflex,
        mstudiovertanim_wrinkle_t *pvanim,
        int vertCount,
        float w1,
        float w2,
        float w3,
        float w4)
{
  float flVertAnimFixedPointScale; // xmm6_4
  unsigned __int8 *p_side; // esi
  int v12; // ecx
  float v13; // xmm0_4
  CCachedRenderData::CacheIndex_t *m_pFirstThinFlexIndex; // eax
  float v15; // xmm1_4
  float v16; // xmm2_4
  float v17; // xmm3_4
  float v18; // xmm4_4
  float v19; // xmm5_4
  CachedPosNorm_t *ThinFlexVertex; // eax
  float v21; // xmm0_4
  float v22; // xmm5_4
  float v23; // xmm1_4
  float v24; // xmm0_4
  float v25; // [esp-8h] [ebp-48h]
  float v26; // [esp-4h] [ebp-44h]
  float vPosition_12; // [esp+1Ch] [ebp-24h]
  int w34; // [esp+2Ch] [ebp-14h]
  float w12; // [esp+30h] [ebp-10h]

  if ( (pStudioHdr->flags & 0x200000) != 0 )
    flVertAnimFixedPointScale = pStudioHdr->flVertAnimFixedPointScale;
  else
    flVertAnimFixedPointScale = 0.00024414062;
  w12 = flVertAnimFixedPointScale;
  w34 = 0;
  if ( pflex->numverts > 0 )
  {
    p_side = &pvanim->side;
    do
    {
      v12 = *(unsigned __int16 *)(p_side - 3);
      if ( v12 < vertCount )
      {
        v13 = (float)*(p_side - 1);
        vPosition_12 = (float)*p_side;
        m_pFirstThinFlexIndex = this->m_pFirstThinFlexIndex;
        v25 = (float)*(__int16 *)(p_side + 9) * flVertAnimFixedPointScale;
        v15 = (float)*(__int16 *)(p_side + 1) * flVertAnimFixedPointScale;
        v16 = (float)*(__int16 *)(p_side + 3) * flVertAnimFixedPointScale;
        v17 = (float)*(__int16 *)(p_side + 5) * flVertAnimFixedPointScale;
        v18 = (float)*(__int16 *)(p_side + 13) * flVertAnimFixedPointScale;
        v19 = (float)*(__int16 *)(p_side + 7) * flVertAnimFixedPointScale;
        v26 = (float)*(__int16 *)(p_side + 11) * flVertAnimFixedPointScale;
        if ( m_pFirstThinFlexIndex != nullptr && m_pFirstThinFlexIndex[v12].m_Tag == this->m_CurrentTag )
        {
          ThinFlexVertex = &this->m_pThinFlexVerts[m_pFirstThinFlexIndex[v12].m_VertexIndex];
        }
        else
        {
          ThinFlexVertex = CCachedRenderData::CreateThinFlexVertex(this, vertex: v12);
          ThinFlexVertex->m_Position = (Vector4DAligned)xmmword_1006E580;
          ThinFlexVertex->m_Normal = (Vector4DAligned)xmmword_1006E580;
        }
        v21 = (float)((float)((float)((float)((float)(v13 * 0.0039215689) * (float)(w3 - w4)) + w4)
                            - (float)((float)((float)(v13 * 0.0039215689) * (float)(w1 - w2)) + w2))
                    * (float)(vPosition_12 * 0.0039215689))
            + (float)((float)((float)(v13 * 0.0039215689) * (float)(w1 - w2)) + w2);
        flVertAnimFixedPointScale = w12;
        ThinFlexVertex->m_Position.x = (float)(v15 * v21) + ThinFlexVertex->m_Position.x;
        ThinFlexVertex->m_Position.y = (float)(v16 * v21) + ThinFlexVertex->m_Position.y;
        ThinFlexVertex->m_Position.z = (float)(v17 * v21) + ThinFlexVertex->m_Position.z;
        ThinFlexVertex->m_Position.w = (float)(v18 * v21) + ThinFlexVertex->m_Position.w;
        ThinFlexVertex->m_Normal.y = (float)(v25 * v21) + ThinFlexVertex->m_Normal.y;
        v22 = (float)(v19 * v21) + ThinFlexVertex->m_Normal.x;
        v23 = (float)(v26 * v21) + ThinFlexVertex->m_Normal.z;
        v24 = (float)(v21 * 0.0) + ThinFlexVertex->m_Normal.w;
        ThinFlexVertex->m_Normal.x = v22;
        ThinFlexVertex->m_Normal.z = v23;
        ThinFlexVertex->m_Normal.w = v24;
      }
      p_side += 18;
      ++w34;
    }
    while ( w34 < pflex->numverts );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004B2D0
// Name: bool FacesRenderedInfoCompareFunc(struct IStudioRender::FacesRenderedInfo_t const __near &,struct IStudioRender::FacesRenderedInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl FacesRenderedInfoCompareFunc(
        const IStudioRender::FacesRenderedInfo_t *a,
        const IStudioRender::FacesRenderedInfo_t *b)
{
  return a->pStudioHdr == b->pStudioHdr;
}

//------------------------------------------------------------------------------
// Address: 0x1004B2F0
// Name: private: void CStudioRender::InitDebugMaterials(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CStudioRender::InitDebugMaterials(CStudioRender *this)
{
  IMaterial *v2; // eax
  IMaterial *v3; // eax
  IMaterial *v4; // eax
  IMaterial *v5; // eax
  IMaterial *v6; // eax
  IMaterial *v7; // eax
  IMaterial *v8; // eax
  IMaterial *v9; // eax
  IMaterial *v10; // eax
  IMaterial *v11; // eax
  IMaterial *v12; // eax
  IMaterial *v13; // eax
  KeyValues *v14; // eax
  KeyValues *v15; // edi
  IMaterial *v16; // eax
  KeyValues *v17; // eax
  KeyValues *v18; // edi
  IMaterial *v19; // eax
  KeyValues *v20; // eax
  KeyValues *v21; // edi
  IMaterial *v22; // eax
  KeyValues *v23; // eax
  KeyValues *v24; // edi
  IMaterial *v25; // eax
  KeyValues *v26; // eax
  KeyValues *v27; // edi
  IMaterial *v28; // eax
  KeyValues *v29; // eax
  KeyValues *v30; // edi
  IMaterial *v31; // eax
  KeyValues *v32; // eax
  KeyValues *v33; // edi
  IMaterial *v34; // eax
  KeyValues *v35; // eax
  KeyValues *v36; // edi
  IMaterial *v37; // eax
  KeyValues *v38; // eax
  KeyValues *v39; // eax

  v2 = g_pMaterialSystem->FindMaterial(
         this: g_pMaterialSystem,
         a2: "//platform/materials/debug/debugmrmwireframe",
         a3: "Other textures",
         a4: 1,
         a5: 0);
  this->m_pMaterialWireframe[0][0] = v2;
  v2->IncrementReferenceCount(this: v2);
  v3 = g_pMaterialSystem->FindMaterial(
         this: g_pMaterialSystem,
         a2: "//platform/materials/debug/debugmrmwireframezbuffer",
         a3: "Other textures",
         a4: 1,
         a5: 0);
  this->m_pMaterialWireframe[1][0] = v3;
  v3->IncrementReferenceCount(this: v3);
  v4 = g_pMaterialSystem->FindMaterial(
         this: g_pMaterialSystem,
         a2: "//platform/materials/debug/debugmrmwireframedisplaced",
         a3: "Other textures",
         a4: 1,
         a5: 0);
  this->m_pMaterialWireframe[0][1] = v4;
  v4->IncrementReferenceCount(this: v4);
  v5 = g_pMaterialSystem->FindMaterial(
         this: g_pMaterialSystem,
         a2: "//platform/materials/debug/debugmrmwireframezbufferdisplaced",
         a3: "Other textures",
         a4: 1,
         a5: 0);
  this->m_pMaterialWireframe[1][1] = v5;
  v5->IncrementReferenceCount(this: v5);
  v6 = g_pMaterialSystem->FindMaterial(
         this: g_pMaterialSystem,
         a2: "//platform/materials/debug/debugmrmnormals",
         a3: "Other textures",
         a4: 1,
         a5: 0);
  this->m_pMaterialMRMNormals = v6;
  v6->IncrementReferenceCount(this: v6);
  v7 = g_pMaterialSystem->FindMaterial(
         this: g_pMaterialSystem,
         a2: "//platform/materials/debug/debugvertexcolor",
         a3: "Other textures",
         a4: 1,
         a5: 0);
  this->m_pMaterialTangentFrame = v7;
  v7->IncrementReferenceCount(this: v7);
  v8 = g_pMaterialSystem->FindMaterial(
         this: g_pMaterialSystem,
         a2: "//platform/materials/debug/debugtranslucentmodelhulls",
         a3: "Other textures",
         a4: 1,
         a5: 0);
  this->m_pMaterialTranslucentModelHulls = v8;
  v8->IncrementReferenceCount(this: v8);
  v9 = g_pMaterialSystem->FindMaterial(
         this: g_pMaterialSystem,
         a2: "//platform/materials/debug/debugsolidmodelhulls",
         a3: "Other textures",
         a4: 1,
         a5: 0);
  this->m_pMaterialSolidModelHulls = v9;
  v9->IncrementReferenceCount(this: v9);
  v10 = g_pMaterialSystem->FindMaterial(
          this: g_pMaterialSystem,
          a2: "//platform/materials/debug/additivevertexcolorvertexalpha",
          a3: "Other textures",
          a4: 1,
          a5: 0);
  this->m_pMaterialAdditiveVertexColorVertexAlpha = v10;
  v10->IncrementReferenceCount(this: v10);
  v11 = g_pMaterialSystem->FindMaterial(
          this: g_pMaterialSystem,
          a2: "//platform/materials/debug/debugmodelbones",
          a3: "Other textures",
          a4: 1,
          a5: 0);
  this->m_pMaterialModelBones = v11;
  v11->IncrementReferenceCount(this: v11);
  v12 = g_pMaterialSystem->FindMaterial(
          this: g_pMaterialSystem,
          a2: "//platform/materials/debug/env_cubemap_model",
          a3: "Other textures",
          a4: 1,
          a5: 0);
  this->m_pMaterialModelEnvCubemap = v12;
  v12->IncrementReferenceCount(this: v12);
  v13 = g_pMaterialSystem->FindMaterial(
          this: g_pMaterialSystem,
          a2: "//platform/materials/debug/debugworldwireframe",
          a3: "Other textures",
          a4: 1,
          a5: 0);
  this->m_pMaterialWorldWireframe = v13;
  v13->IncrementReferenceCount(this: v13);
  v14 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v14 != nullptr )
    v15 = KeyValues::KeyValues(this: v14, setName: "DepthWrite");
  else
    v15 = nullptr;
  KeyValues::SetInt(this: v15, keyName: "$no_fullbright", value: 1);
  KeyValues::SetInt(this: v15, keyName: "$alphatest", value: 0);
  KeyValues::SetInt(this: v15, keyName: "$nocull", value: 0);
  KeyValues::SetInt(this: v15, keyName: "$treesway", value: 0);
  v16 = g_pMaterialSystem->FindProceduralMaterial(
          this: g_pMaterialSystem,
          a2: "__DepthWrite000",
          a3: "Other textures",
          a4: v15);
  this->m_pDepthWrite[0][0][0] = v16;
  v16->IncrementReferenceCount(this: v16);
  v17 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v17 != nullptr )
    v18 = KeyValues::KeyValues(this: v17, setName: "DepthWrite");
  else
    v18 = nullptr;
  KeyValues::SetInt(this: v18, keyName: "$no_fullbright", value: 1);
  KeyValues::SetInt(this: v18, keyName: "$alphatest", value: 0);
  KeyValues::SetInt(this: v18, keyName: "$nocull", value: 1);
  KeyValues::SetInt(this: v18, keyName: "$treesway", value: 0);
  v19 = g_pMaterialSystem->FindProceduralMaterial(
          this: g_pMaterialSystem,
          a2: "__DepthWrite010",
          a3: "Other textures",
          a4: v18);
  this->m_pDepthWrite[0][1][0] = v19;
  v19->IncrementReferenceCount(this: v19);
  v20 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v20 != nullptr )
    v21 = KeyValues::KeyValues(this: v20, setName: "DepthWrite");
  else
    v21 = nullptr;
  KeyValues::SetInt(this: v21, keyName: "$no_fullbright", value: 1);
  KeyValues::SetInt(this: v21, keyName: "$alphatest", value: 1);
  KeyValues::SetInt(this: v21, keyName: "$nocull", value: 0);
  KeyValues::SetInt(this: v21, keyName: "$treesway", value: 0);
  v22 = g_pMaterialSystem->FindProceduralMaterial(
          this: g_pMaterialSystem,
          a2: "__DepthWrite100",
          a3: "Other textures",
          a4: v21);
  this->m_pDepthWrite[1][0][0] = v22;
  v22->IncrementReferenceCount(this: v22);
  v23 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v23 != nullptr )
    v24 = KeyValues::KeyValues(this: v23, setName: "DepthWrite");
  else
    v24 = nullptr;
  KeyValues::SetInt(this: v24, keyName: "$no_fullbright", value: 1);
  KeyValues::SetInt(this: v24, keyName: "$alphatest", value: 1);
  KeyValues::SetInt(this: v24, keyName: "$nocull", value: 1);
  KeyValues::SetInt(this: v24, keyName: "$treesway", value: 0);
  v25 = g_pMaterialSystem->FindProceduralMaterial(
          this: g_pMaterialSystem,
          a2: "__DepthWrite110",
          a3: "Other textures",
          a4: v24);
  this->m_pDepthWrite[1][1][0] = v25;
  v25->IncrementReferenceCount(this: v25);
  v26 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v26 != nullptr )
    v27 = KeyValues::KeyValues(this: v26, setName: "DepthWrite");
  else
    v27 = nullptr;
  KeyValues::SetInt(this: v27, keyName: "$no_fullbright", value: 1);
  KeyValues::SetInt(this: v27, keyName: "$alphatest", value: 0);
  KeyValues::SetInt(this: v27, keyName: "$nocull", value: 0);
  KeyValues::SetInt(this: v27, keyName: "$treesway", value: 1);
  v28 = g_pMaterialSystem->FindProceduralMaterial(
          this: g_pMaterialSystem,
          a2: "__DepthWrite001",
          a3: "Other textures",
          a4: v27);
  this->m_pDepthWrite[0][0][1] = v28;
  v28->IncrementReferenceCount(this: v28);
  v29 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v29 != nullptr )
    v30 = KeyValues::KeyValues(this: v29, setName: "DepthWrite");
  else
    v30 = nullptr;
  KeyValues::SetInt(this: v30, keyName: "$no_fullbright", value: 1);
  KeyValues::SetInt(this: v30, keyName: "$alphatest", value: 0);
  KeyValues::SetInt(this: v30, keyName: "$nocull", value: 1);
  KeyValues::SetInt(this: v30, keyName: "$treesway", value: 1);
  v31 = g_pMaterialSystem->FindProceduralMaterial(
          this: g_pMaterialSystem,
          a2: "__DepthWrite011",
          a3: "Other textures",
          a4: v30);
  this->m_pDepthWrite[0][1][1] = v31;
  v31->IncrementReferenceCount(this: v31);
  v32 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v32 != nullptr )
    v33 = KeyValues::KeyValues(this: v32, setName: "DepthWrite");
  else
    v33 = nullptr;
  KeyValues::SetInt(this: v33, keyName: "$no_fullbright", value: 1);
  KeyValues::SetInt(this: v33, keyName: "$alphatest", value: 1);
  KeyValues::SetInt(this: v33, keyName: "$nocull", value: 0);
  KeyValues::SetInt(this: v33, keyName: "$treesway", value: 1);
  v34 = g_pMaterialSystem->FindProceduralMaterial(
          this: g_pMaterialSystem,
          a2: "__DepthWrite101",
          a3: "Other textures",
          a4: v33);
  this->m_pDepthWrite[1][0][1] = v34;
  v34->IncrementReferenceCount(this: v34);
  v35 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v35 != nullptr )
    v36 = KeyValues::KeyValues(this: v35, setName: "DepthWrite");
  else
    v36 = nullptr;
  KeyValues::SetInt(this: v36, keyName: "$no_fullbright", value: 1);
  KeyValues::SetInt(this: v36, keyName: "$alphatest", value: 1);
  KeyValues::SetInt(this: v36, keyName: "$nocull", value: 1);
  KeyValues::SetInt(this: v36, keyName: "$treesway", value: 1);
  v37 = g_pMaterialSystem->FindProceduralMaterial(
          this: g_pMaterialSystem,
          a2: "__DepthWrite111",
          a3: "Other textures",
          a4: v36);
  this->m_pDepthWrite[1][1][1] = v37;
  v37->IncrementReferenceCount(this: v37);
  v38 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v38 != nullptr )
    v39 = KeyValues::KeyValues(this: v38, setName: "EyeGlint");
  else
    v39 = nullptr;
  this->m_pGlintBuildMaterial = g_pMaterialSystem->CreateMaterial(
                                  this: g_pMaterialSystem,
                                  a2: "___glintbuildmaterial",
                                  a3: v39);
}

//------------------------------------------------------------------------------
// Address: 0x1004B960
// Name: private: void CStudioRender::ShutdownDebugMaterials(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CStudioRender::ShutdownDebugMaterials(CStudioRender *this)
{
  IMaterial **v2; // esi
  int j; // ebx
  IMaterial *m_pMaterialMRMNormals; // ecx
  IMaterial *m_pMaterialTangentFrame; // ecx
  IMaterial *m_pMaterialTranslucentModelHulls; // ecx
  IMaterial *m_pMaterialSolidModelHulls; // ecx
  IMaterial *m_pMaterialAdditiveVertexColorVertexAlpha; // ecx
  IMaterial *m_pMaterialModelBones; // ecx
  IMaterial *m_pMaterialModelEnvCubemap; // ecx
  IMaterial *m_pMaterialWorldWireframe; // ecx
  int k; // esi
  IMaterial **v13; // eax
  IMaterial *m_pGlintBuildMaterial; // ecx
  int i; // [esp+Ch] [ebp-4h]

  v2 = this->m_pMaterialWireframe[0];
  for ( i = 2; i != 0; --i )
  {
    for ( j = 2; j != 0; --j )
    {
      if ( *v2 != nullptr )
      {
        (*v2)->DecrementReferenceCount(this: *v2);
        *v2 = nullptr;
      }
      ++v2;
    }
  }
  m_pMaterialMRMNormals = this->m_pMaterialMRMNormals;
  if ( m_pMaterialMRMNormals != nullptr )
  {
    m_pMaterialMRMNormals->DecrementReferenceCount(this: m_pMaterialMRMNormals);
    this->m_pMaterialMRMNormals = nullptr;
  }
  m_pMaterialTangentFrame = this->m_pMaterialTangentFrame;
  if ( m_pMaterialTangentFrame != nullptr )
  {
    m_pMaterialTangentFrame->DecrementReferenceCount(this: m_pMaterialTangentFrame);
    this->m_pMaterialTangentFrame = nullptr;
  }
  m_pMaterialTranslucentModelHulls = this->m_pMaterialTranslucentModelHulls;
  if ( m_pMaterialTranslucentModelHulls != nullptr )
  {
    m_pMaterialTranslucentModelHulls->DecrementReferenceCount(this: m_pMaterialTranslucentModelHulls);
    this->m_pMaterialTranslucentModelHulls = nullptr;
  }
  m_pMaterialSolidModelHulls = this->m_pMaterialSolidModelHulls;
  if ( m_pMaterialSolidModelHulls != nullptr )
  {
    m_pMaterialSolidModelHulls->DecrementReferenceCount(this: m_pMaterialSolidModelHulls);
    this->m_pMaterialSolidModelHulls = nullptr;
  }
  m_pMaterialAdditiveVertexColorVertexAlpha = this->m_pMaterialAdditiveVertexColorVertexAlpha;
  if ( m_pMaterialAdditiveVertexColorVertexAlpha != nullptr )
  {
    m_pMaterialAdditiveVertexColorVertexAlpha->DecrementReferenceCount(this: m_pMaterialAdditiveVertexColorVertexAlpha);
    this->m_pMaterialAdditiveVertexColorVertexAlpha = nullptr;
  }
  m_pMaterialModelBones = this->m_pMaterialModelBones;
  if ( m_pMaterialModelBones != nullptr )
  {
    m_pMaterialModelBones->DecrementReferenceCount(this: m_pMaterialModelBones);
    this->m_pMaterialModelBones = nullptr;
  }
  m_pMaterialModelEnvCubemap = this->m_pMaterialModelEnvCubemap;
  if ( m_pMaterialModelEnvCubemap != nullptr )
  {
    m_pMaterialModelEnvCubemap->DecrementReferenceCount(this: m_pMaterialModelEnvCubemap);
    this->m_pMaterialModelEnvCubemap = nullptr;
  }
  m_pMaterialWorldWireframe = this->m_pMaterialWorldWireframe;
  if ( m_pMaterialWorldWireframe != nullptr )
  {
    m_pMaterialWorldWireframe->DecrementReferenceCount(this: m_pMaterialWorldWireframe);
    this->m_pMaterialWorldWireframe = nullptr;
  }
  for ( k = 0; k < 8; ++k )
  {
    v13 = &this->m_pDepthWrite[(k >> 2) & 1][(k >> 1) & 1][k & 1];
    if ( *v13 != nullptr )
      (*v13)->DecrementReferenceCount(this: *v13);
  }
  m_pGlintBuildMaterial = this->m_pGlintBuildMaterial;
  if ( m_pGlintBuildMaterial != nullptr )
  {
    m_pGlintBuildMaterial->DecrementReferenceCount(this: m_pGlintBuildMaterial);
    this->m_pGlintBuildMaterial = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004BAC0
// Name: public: enum InitReturnVal_t CStudioRender::Init(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CStudioRender::Init(CStudioRender *this)
{
  if ( g_pMaterialSystem == nullptr || g_pMaterialSystemHardwareConfig == nullptr )
    return 0;
  ((void (__stdcall *)(void (__cdecl *)(void *(__cdecl **)(const char *, int *), int)))g_pMaterialSystem->AddReleaseFunc)(a1: _heap_term);
  g_pMaterialSystem->AddRestoreFunc(this: g_pMaterialSystem, a2: (void (__cdecl *)(int))_heap_term);
  CStudioRender::InitDebugMaterials(this);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1004BB10
// Name: public: void CStudioRender::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CStudioRender::Shutdown(CStudioRender *this)
{
  CStudioRender::UncacheGlint(this);
  CStudioRender::ShutdownDebugMaterials(this);
  if ( g_pMaterialSystem != nullptr )
  {
    g_pMaterialSystem->RemoveReleaseFunc(this: g_pMaterialSystem, a2: (void (__cdecl *)(int))_heap_term);
    g_pMaterialSystem->RemoveRestoreFunc(this: g_pMaterialSystem, a2: (void (__cdecl *)(int))_heap_term);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004BB50
// Name: private: static bool CStudioRender::SortLessFunc(struct MeshRenderData_t const __near &,struct MeshRenderData_t const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl CStudioRender::SortLessFunc(const MeshRenderData_t *left, const MeshRenderData_t *right)
{
  IMaterial *m_pMaterial; // edx
  IMaterial *v3; // esi
  bool v4; // cf
  bool result; // al
  IMesh *m_pMesh; // edx
  IMesh *v7; // esi
  StudioArrayInstanceData_t *m_pInstance; // eax
  StudioArrayInstanceData_t *v9; // ecx
  ITexture *m_pEnvCubemapTexture; // edx
  ITexture *v11; // esi
  MaterialLightingState_t *m_pLightingState; // edx
  MaterialLightingState_t *v13; // esi

  m_pMaterial = left->m_pMaterial;
  v3 = right->m_pMaterial;
  v4 = v3 < m_pMaterial;
  if ( v3 != m_pMaterial )
    return v4;
  m_pMesh = left->m_pGroup->BaseMeshRenderData_t::m_pMesh;
  v7 = right->m_pGroup->BaseMeshRenderData_t::m_pMesh;
  v4 = v7 < m_pMesh;
  if ( v7 != m_pMesh )
    return v4;
  m_pInstance = left->m_pInstance;
  v9 = right->m_pInstance;
  m_pEnvCubemapTexture = m_pInstance->m_pEnvCubemapTexture;
  v11 = v9->m_pEnvCubemapTexture;
  v4 = v11 < m_pEnvCubemapTexture;
  if ( v11 != m_pEnvCubemapTexture )
    return v4;
  m_pLightingState = m_pInstance->m_pLightingState;
  v13 = v9->m_pLightingState;
  result = m_pLightingState != nullptr;
  if ( (m_pLightingState != nullptr) == (v13 != nullptr) && m_pLightingState != nullptr )
    return m_pLightingState->m_nLocalLightCount > v13->m_nLocalLightCount;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1004BBB0
// Name: private: static bool CStudioRender::SortLessFunc2(struct MeshRenderData2_t const __near &,struct MeshRenderData2_t const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl CStudioRender::SortLessFunc2(const MeshRenderData2_t *left, const MeshRenderData2_t *right)
{
  IMaterial *m_pMaterial; // edx
  IMaterial *v3; // eax
  __int16 m_nCompressionType; // ax
  __int16 m_nMeshBoneCount; // dx
  StudioArrayInstanceData_t *m_pInstance; // eax
  StudioArrayInstanceData_t *v8; // esi
  unsigned __int8 v9; // dl
  unsigned __int8 v10; // bl
  bool v11; // cf
  ITexture *m_pEnvCubemapTexture; // edx
  ITexture *v13; // ebx
  IMesh *m_pMesh; // edx
  IMesh *v15; // ecx
  MaterialLightingState_t *m_pLightingState; // eax
  MaterialLightingState_t *v17; // esi

  m_pMaterial = right->m_pMaterial;
  v3 = left->m_pMaterial;
  if ( m_pMaterial != v3 )
    return m_pMaterial < v3;
  m_nCompressionType = left->m_nCompressionType;
  m_nMeshBoneCount = right->m_nCompressionType;
  if ( m_nCompressionType != m_nMeshBoneCount )
    return m_nCompressionType > m_nMeshBoneCount;
  m_nCompressionType = left->m_nMeshBoneCount;
  m_nMeshBoneCount = right->m_nMeshBoneCount;
  if ( m_nCompressionType != m_nMeshBoneCount )
    return m_nCompressionType > m_nMeshBoneCount;
  m_pInstance = left->m_pInstance;
  v8 = right->m_pInstance;
  v9 = m_pInstance->m_pColorMeshInfo != nullptr;
  v10 = v8->m_pColorMeshInfo != nullptr;
  v11 = v9 < v10;
  if ( v9 != v10 )
    return v11;
  m_pEnvCubemapTexture = m_pInstance->m_pEnvCubemapTexture;
  v13 = v8->m_pEnvCubemapTexture;
  v11 = v13 < m_pEnvCubemapTexture;
  if ( v13 != m_pEnvCubemapTexture )
    return v11;
  m_pMesh = left->m_pGroup->BaseMeshRenderData_t::m_pMesh;
  v15 = right->m_pGroup->BaseMeshRenderData_t::m_pMesh;
  v11 = v15 < m_pMesh;
  if ( v15 != m_pMesh )
    return v11;
  m_pLightingState = m_pInstance->m_pLightingState;
  v17 = v8->m_pLightingState;
  if ( (m_pLightingState != nullptr) != (v17 != nullptr) )
    return m_pLightingState != nullptr;
  if ( m_pLightingState != nullptr )
    return m_pLightingState->m_nLocalLightCount > v17->m_nLocalLightCount;
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x1004BC60
// Name: private: void CStudioRender::BuildForcedMaterialRenderList(struct MeshRenderData_t __near *,int __near *,struct StudioModelArrayInfo_t const __near &,struct StudioRenderContext_t const __near &,int,struct StudioArrayInstanceData_t __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CStudioRender::BuildForcedMaterialRenderList(
        CStudioRender *this,
        MeshRenderData_t *pRenderData,
        int *pTotalStripCount,
        const StudioModelArrayInfo_t *drawInfo,
        const StudioRenderContext_t *rc,
        int nCount,
        StudioArrayInstanceData_t *pInstanceData,
        int nInstanceStride)
{
  studiohdr_t *m_pStudioHdr; // esi
  StudioArrayInstanceData_t *v9; // edi
  int v10; // ecx
  int v11; // edx
  int v12; // eax
  studiomeshdata_t *v13; // edi
  int v14; // edx
  MeshRenderData_t *v15; // esi
  studiomeshgroup_t *m_pMeshGroup; // eax
  studiomeshgroup_t *v17; // eax
  bool v18; // zf
  mstudiomodel_t *pSubmodel; // [esp+Ch] [ebp-2Ch]
  studiohdr_t *pStudioHdr; // [esp+10h] [ebp-28h]
  mstudiomesh_t *pMesh; // [esp+14h] [ebp-24h]
  studiomeshdata_t *pMeshDataBase; // [esp+18h] [ebp-20h]
  int nBody; // [esp+1Ch] [ebp-1Ch]
  int v24; // [esp+20h] [ebp-18h]
  int v25; // [esp+24h] [ebp-14h]
  int body; // [esp+28h] [ebp-10h]
  int v27; // [esp+2Ch] [ebp-Ch]
  int meshIndex; // [esp+30h] [ebp-8h]
  StudioArrayInstanceData_t *pCurInstance; // [esp+34h] [ebp-4h]
  int g; // [esp+50h] [ebp+18h]
  int nRenderDataCount; // [esp+54h] [ebp+1Ch]

  m_pStudioHdr = drawInfo->m_pStudioHdr;
  v9 = pInstanceData;
  pStudioHdr = m_pStudioHdr;
  *pTotalStripCount = 0;
  pCurInstance = pInstanceData;
  nRenderDataCount = 0;
  if ( nCount > 0 )
  {
    v24 = nCount;
    do
    {
      pMeshDataBase = drawInfo->m_pHardwareData->m_pLODs[v9->m_nLOD].m_pMeshData;
      nBody = v9->m_nBody;
      body = 0;
      if ( m_pStudioHdr->numbodyparts > 0 )
      {
        v10 = 0;
        v25 = 0;
        do
        {
          meshIndex = 0;
          v11 = (int)m_pStudioHdr
              + 148
              * (nBody / *(int *)((char *)&m_pStudioHdr->checksum + v10 + m_pStudioHdr->bodypartindex)
               % *(int *)((char *)&m_pStudioHdr->version + v10 + m_pStudioHdr->bodypartindex))
              + v10
              + m_pStudioHdr->bodypartindex
              + *(_DWORD *)&m_pStudioHdr->name[v10 + m_pStudioHdr->bodypartindex];
          pSubmodel = (mstudiomodel_t *)v11;
          if ( *(int *)(v11 + 72) > 0 )
          {
            v12 = 0;
            v27 = 0;
            do
            {
              g = 0;
              pMesh = (mstudiomesh_t *)(*(_DWORD *)(v11 + 76) + v11 + v12);
              v13 = &pMeshDataBase[pMesh->meshid];
              if ( v13->m_NumGroup > 0 )
              {
                v14 = 0;
                v15 = &pRenderData[nRenderDataCount];
                do
                {
                  m_pMeshGroup = v13->m_pMeshGroup;
                  ++nRenderDataCount;
                  v15->m_pMaterial = rc->m_pForcedMaterial;
                  v17 = &m_pMeshGroup[v14];
                  v15->m_pInstance = pCurInstance;
                  v15->m_pGroup = v17;
                  v15->m_pMesh = pMesh;
                  *pTotalStripCount += v17->m_NumStrips;
                  ++v15;
                  ++v14;
                  ++g;
                }
                while ( g < v13->m_NumGroup );
                m_pStudioHdr = pStudioHdr;
                v11 = (int)pSubmodel;
              }
              v12 = v27 + 116;
              ++meshIndex;
              v27 += 116;
            }
            while ( meshIndex < *(_DWORD *)(v11 + 72) );
            v9 = pCurInstance;
          }
          v10 = v25 + 16;
          ++body;
          v25 += 16;
        }
        while ( body < m_pStudioHdr->numbodyparts );
      }
      v9 = (StudioArrayInstanceData_t *)((char *)v9 + nInstanceStride);
      v18 = v24-- == 1;
      pCurInstance = v9;
    }
    while ( !v18 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004BDC0
// Name: private: void CStudioRender::BuildForcedMaterialRenderList(struct MeshRenderData2_t __near *,int __near *,struct StudioModelArrayInfo2_t const __near &,struct StudioRenderContext_t const __near &,int,struct StudioArrayData_t __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CStudioRender::BuildForcedMaterialRenderList(
        CStudioRender *this,
        MeshRenderData2_t *pRenderData,
        int *pTotalStripCount,
        const StudioModelArrayInfo2_t *drawInfo,
        const StudioRenderContext_t *rc,
        int nCount,
        StudioArrayData_t *pArrayData,
        int nInstanceStride)
{
  int v8; // ecx
  int v9; // edi
  studiohwdata_t **p_m_pHardwareData; // eax
  studiohdr_t *v11; // esi
  StudioArrayInstanceData_t *v12; // ebx
  int v13; // edx
  int v14; // ecx
  int v15; // eax
  mstudiomesh_t *v16; // ecx
  studiomeshdata_t *v17; // ebx
  MeshRenderData2_t *i; // eax
  studiomeshgroup_t *v19; // esi
  MeshRenderData2_t *v20; // edi
  IMaterial *m_pForcedMaterial; // eax
  bool v22; // zf
  mstudiomodel_t *pSubmodel; // [esp+4h] [ebp-40h]
  studiohdr_t *pStudioHdr; // [esp+8h] [ebp-3Ch]
  MeshRenderData2_t *v25; // [esp+Ch] [ebp-38h]
  mstudiomesh_t *pMesh; // [esp+10h] [ebp-34h]
  studiomeshdata_t *pMeshDataBase; // [esp+14h] [ebp-30h]
  int nBody; // [esp+18h] [ebp-2Ch]
  int v29; // [esp+1Ch] [ebp-28h]
  studiohwdata_t **v30; // [esp+20h] [ebp-24h]
  int v31; // [esp+24h] [ebp-20h]
  int body; // [esp+28h] [ebp-1Ch]
  int meshIndex; // [esp+2Ch] [ebp-18h]
  int g; // [esp+30h] [ebp-14h]
  StudioArrayInstanceData_t *pCurInstance; // [esp+34h] [ebp-10h]
  int v36; // [esp+38h] [ebp-Ch]
  int v37; // [esp+3Ch] [ebp-8h]
  int nRenderDataCount; // [esp+40h] [ebp-4h]
  StudioArrayData_t *pArrayDataa; // [esp+60h] [ebp+1Ch]

  v8 = nCount;
  v9 = 0;
  *pTotalStripCount = 0;
  nRenderDataCount = 0;
  if ( nCount > 0 )
  {
    p_m_pHardwareData = &pArrayData->m_pHardwareData;
    v30 = &pArrayData->m_pHardwareData;
    v29 = nCount;
    while ( 1 )
    {
      v11 = (studiohdr_t *)*(p_m_pHardwareData - 1);
      v12 = (StudioArrayInstanceData_t *)p_m_pHardwareData[1];
      pStudioHdr = v11;
      pCurInstance = v12;
      v31 = v8;
      do
      {
        pMeshDataBase = (*p_m_pHardwareData)->m_pLODs[v12->m_nLOD].m_pMeshData;
        nBody = v12->m_nBody;
        body = 0;
        if ( v11->numbodyparts > 0 )
        {
          v36 = 0;
          do
          {
            meshIndex = 0;
            v13 = (int)v11
                + 148
                * (nBody / *(int *)((char *)&v11->checksum + v36 + v11->bodypartindex)
                 % *(int *)((char *)&v11->version + v36 + v11->bodypartindex))
                + v36
                + v11->bodypartindex
                + *(_DWORD *)&v11->name[v36 + v11->bodypartindex];
            pSubmodel = (mstudiomodel_t *)v13;
            if ( *(int *)(v13 + 72) > 0 )
            {
              v37 = 0;
              do
              {
                v14 = v37 + *(_DWORD *)(v13 + 76);
                v15 = *(_DWORD *)(v14 + v13 + 32);
                v16 = (mstudiomesh_t *)(v13 + v14);
                v17 = &pMeshDataBase[v15];
                pMesh = v16;
                g = 0;
                if ( v17->m_NumGroup > 0 )
                {
                  pArrayDataa = nullptr;
                  for ( i = &pRenderData[v9]; ; i = v25 )
                  {
                    v19 = (studiomeshgroup_t *)((char *)pArrayDataa + (unsigned int)v17->m_pMeshGroup);
                    ++nRenderDataCount;
                    v20 = i;
                    v25 = i + 1;
                    m_pForcedMaterial = rc->m_pForcedMaterial;
                    v20->m_pInstance = pCurInstance;
                    v20->m_pMaterial = m_pForcedMaterial;
                    v20->m_pGroup = v19;
                    v20->m_pMesh = v16;
                    v20->m_nCompressionType = (v19->m_pMesh->GetVertexFormat(this: v19->m_pMesh) & 0x400) != 0;
                    pArrayDataa = (StudioArrayData_t *)((char *)pArrayDataa + 44);
                    v20->m_nMeshBoneCount = (v19->m_pMesh->GetVertexFormat(this: v19->m_pMesh) >> 12) & 7;
                    *pTotalStripCount += v19->m_NumStrips;
                    if ( ++g >= v17->m_NumGroup )
                      break;
                    v16 = pMesh;
                  }
                  v11 = pStudioHdr;
                  v13 = (int)pSubmodel;
                  v9 = nRenderDataCount;
                }
                v37 += 116;
                ++meshIndex;
              }
              while ( meshIndex < *(_DWORD *)(v13 + 72) );
              v12 = pCurInstance;
            }
            v36 += 16;
            ++body;
          }
          while ( body < v11->numbodyparts );
          p_m_pHardwareData = v30;
        }
        v12 = (StudioArrayInstanceData_t *)((char *)v12 + nInstanceStride);
        v22 = v31-- == 1;
        pCurInstance = v12;
      }
      while ( !v22 );
      p_m_pHardwareData += 4;
      v22 = v29-- == 1;
      v30 = p_m_pHardwareData;
      if ( v22 )
        break;
      v8 = nCount;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004BF80
// Name: private: void CStudioRender::RestoreMeshes(int,struct BaseMeshRenderData_t __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CStudioRender::RestoreMeshes(
        CStudioRender *this,
        int nCount,
        BaseMeshRenderData_t *pRenderData,
        int nStride)
{
  mstudiomesh_t **p_m_pMesh; // edi
  studiomeshgroup_t *v6; // esi

  if ( nCount > 0 )
  {
    p_m_pMesh = &pRenderData->m_pMesh;
    do
    {
      v6 = (studiomeshgroup_t *)*(p_m_pMesh - 1);
      if ( v6->m_MeshNeedsRestore )
      {
        if ( (v6->m_pMesh->GetVertexFormat(this: v6->m_pMesh) & 0x400) != 0 )
          CStudioRender::R_StudioRestoreMesh<1>(this, pmesh: *p_m_pMesh, pMeshData: v6);
        else
          CStudioRender::R_StudioRestoreMesh<0>(this, pmesh: *p_m_pMesh, pMeshData: v6);
        v6->m_MeshNeedsRestore = false;
      }
      p_m_pMesh = (mstudiomesh_t **)((char *)p_m_pMesh + nStride);
      --nCount;
    }
    while ( nCount != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004C000
// Name: private: void CStudioRender::DrawMeshRenderData(class IMatRenderContext __near *,struct StudioModelArrayInfo_t const __near &,int,struct MeshRenderData_t __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CStudioRender::DrawMeshRenderData(
        CStudioRender *this,
        IMatRenderContext *pRenderContext,
        const StudioModelArrayInfo_t *drawInfo,
        int nCount,
        MeshRenderData_t *pRenderData,
        int nTotalStripCount,
        int nFlashlightMask)
{
  void *v7; // esp
  MeshRenderData_t *v8; // edi
  StudioArrayInstanceData_t *m_pInstance; // esi
  studiomeshgroup_t *m_pGroup; // ebx
  IMesh *m_pMesh; // ecx
  IMaterial *m_pMaterial; // edx
  const MeshInstanceData_t *v14; // edi
  ITexture *m_pEnvCubemapTexture; // edx
  OptimizedModel::StripHeader_t *v16; // ecx
  const MeshInstanceData_t *v17; // eax
  ColorMeshInfo_t *m_pColorMeshInfo; // edx
  const IVertexBuffer **p_m_pMesh; // edi
  int v20; // edx
  int numBoneStateChanges; // edx
  MeshBoneRemap_t *v22; // edx
  IMesh *v23; // edx
  IIndexBuffer *v24; // edx
  bool v25; // zf
  int v26; // edi
  IMatRenderContext *v27; // esi
  int v28; // [esp+0h] [ebp-28h] BYREF
  const MeshInstanceData_t *v29; // [esp+Ch] [ebp-1Ch]
  int v30; // [esp+10h] [ebp-18h]
  IMesh *v31; // [esp+14h] [ebp-14h]
  const MeshInstanceData_t *v32; // [esp+18h] [ebp-10h]
  IMaterial *v33; // [esp+1Ch] [ebp-Ch]
  int numBones; // [esp+20h] [ebp-8h]
  int v35; // [esp+24h] [ebp-4h]
  MeshRenderData_t *v36; // [esp+34h] [ebp+Ch]
  int v37; // [esp+38h] [ebp+10h]
  int v38; // [esp+3Ch] [ebp+14h]
  bool v39; // [esp+43h] [ebp+1Bh]

  v35 = 0;
  v7 = alloca(76 * nTotalStripCount);
  v39 = drawInfo->m_pStudioHdr->numbones > 1;
  v32 = (const MeshInstanceData_t *)&v28;
  v33 = nullptr;
  v31 = nullptr;
  numBones = 0;
  if ( nCount <= 0 )
    goto LABEL_28;
  v8 = pRenderData;
  v36 = pRenderData;
  v30 = nCount;
  do
  {
    m_pInstance = v8->m_pInstance;
    if ( nFlashlightMask == 0 || (nFlashlightMask & m_pInstance->m_nFlashlightUsage) != 0 )
    {
      if ( v33 != v8->m_pMaterial || (m_pGroup = v8->m_pGroup, v31 != v8->m_pGroup->BaseMeshRenderData_t::m_pMesh) )
      {
        if ( v35 > 0 )
        {
          pRenderContext->SetNumBoneWeights(this: pRenderContext, a2: v39 ? numBones : 0);
          pRenderContext->Bind(this: pRenderContext, a2: v33, a3: nullptr);
          pRenderContext->DrawInstances(this: pRenderContext, a2: v35, a3: v32);
        }
        m_pGroup = v8->m_pGroup;
        m_pMesh = v8->m_pGroup->BaseMeshRenderData_t::m_pMesh;
        m_pMaterial = v8->m_pMaterial;
        v35 = 0;
        numBones = 0;
        v31 = m_pMesh;
        v33 = m_pMaterial;
      }
      v38 = 0;
      if ( m_pGroup->m_NumStrips > 0 )
      {
        v14 = &v32[v35];
        v37 = 0;
        do
        {
          m_pEnvCubemapTexture = m_pInstance->m_pEnvCubemapTexture;
          v16 = &m_pGroup->m_pStripData[v37];
          ++v35;
          v17 = v14;
          v14->m_pEnvCubemap = m_pEnvCubemapTexture;
          v14->m_pPoseToWorld = m_pInstance->m_pPoseToWorld;
          v14->m_pLightingState = m_pInstance->m_pLightingState;
          m_pColorMeshInfo = m_pInstance->m_pColorMeshInfo;
          v29 = ++v14;
          if ( m_pColorMeshInfo != nullptr )
          {
            p_m_pMesh = (const IVertexBuffer **)&m_pColorMeshInfo[m_pGroup->m_ColorMeshID].m_pMesh;
            v17->m_pColorBuffer = *p_m_pMesh;
            v20 = (int)p_m_pMesh[2];
            v14 = v29;
          }
          else
          {
            v20 = 0;
            v17->m_pColorBuffer = nullptr;
          }
          v17->m_nColorVertexOffsetInBytes = v20;
          numBoneStateChanges = v16->numBoneStateChanges;
          v17->m_nBoneCount = numBoneStateChanges;
          if ( numBoneStateChanges <= 0 )
            v22 = nullptr;
          else
            v22 = (MeshBoneRemap_t *)((char *)v16 + v16->boneStateChangeOffset);
          v17->m_pBoneRemap = v22;
          v17->m_nIndexOffset = v16->indexOffset;
          v17->m_nIndexCount = v16->numIndices;
          v17->m_nPrimType = MATERIAL_TRIANGLES;
          v17->m_pVertexBuffer = v36->m_pGroup->BaseMeshRenderData_t::m_pMesh;
          v23 = v36->m_pGroup->BaseMeshRenderData_t::m_pMesh;
          if ( v23 != nullptr )
            v24 = &v23->IIndexBuffer;
          else
            v24 = nullptr;
          v17->m_pIndexBuffer = v24;
          v17->m_nVertexOffsetInBytes = 0;
          v17->m_pStencilState = m_pInstance->m_pStencilState;
          v17->m_DiffuseModulation.x = m_pInstance->m_DiffuseModulation.x;
          v17->m_DiffuseModulation.y = m_pInstance->m_DiffuseModulation.y;
          v17->m_DiffuseModulation.z = m_pInstance->m_DiffuseModulation.z;
          v17->m_DiffuseModulation.w = m_pInstance->m_DiffuseModulation.w;
          v17->m_nLightmapPageId = -4;
          if ( numBones <= v16->numBones )
            numBones = v16->numBones;
          ++v37;
          ++v38;
        }
        while ( v38 < m_pGroup->m_NumStrips );
        v8 = v36;
      }
    }
    ++v8;
    v25 = v30-- == 1;
    v36 = v8;
  }
  while ( !v25 );
  v26 = v35;
  if ( v35 <= 0 )
  {
LABEL_28:
    v27 = pRenderContext;
  }
  else
  {
    v27 = pRenderContext;
    pRenderContext->SetNumBoneWeights(this: pRenderContext, a2: v39 ? numBones : 0);
    v27->Bind(this: v27, a2: v33, a3: nullptr);
    v27->DrawInstances(this: v27, a2: v26, a3: v32);
  }
  v27->SetNumBoneWeights(this: v27, a2: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1004C240
// Name: private: void CStudioRender::DrawMeshRenderData(class IMatRenderContext __near *,struct StudioModelArrayInfo2_t const __near &,int,struct MeshRenderData2_t __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CStudioRender::DrawMeshRenderData(
        CStudioRender *this,
        IMatRenderContext *pRenderContext,
        const StudioModelArrayInfo2_t *drawInfo,
        int nCount,
        MeshRenderData2_t *pRenderData,
        int nTotalStripCount,
        int nFlashlightMask)
{
  void *v7; // esp
  int v8; // ecx
  __int16 *p_m_nCompressionType; // edi
  int v10; // esi
  char v11; // al
  IMaterial *v13; // edx
  int v14; // ecx
  int v15; // edi
  bool v16; // cc
  const MeshInstanceData_t *v17; // ebx
  const ITexture *v18; // edx
  int v19; // ecx
  const MeshInstanceData_t *v20; // eax
  int v21; // edx
  const IVertexBuffer **v22; // edi
  int v23; // edx
  int v24; // edx
  MeshBoneRemap_t *v25; // edx
  const IIndexBuffer *v26; // edx
  const IIndexBuffer *v27; // edx
  bool v28; // zf
  int v29; // edi
  IMatRenderContext *v30; // esi
  int v31; // [esp+0h] [ebp-30h] BYREF
  int v32; // [esp+Ch] [ebp-24h]
  int v33; // [esp+10h] [ebp-20h]
  int v34; // [esp+14h] [ebp-1Ch]
  int v35; // [esp+18h] [ebp-18h]
  const MeshInstanceData_t *v36; // [esp+1Ch] [ebp-14h]
  int v37; // [esp+20h] [ebp-10h]
  IMaterial *v38; // [esp+24h] [ebp-Ch]
  int v39; // [esp+28h] [ebp-8h]
  int v40; // [esp+2Ch] [ebp-4h]
  int v41; // [esp+40h] [ebp+10h]
  char v42; // [esp+43h] [ebp+13h]
  __int16 *v43; // [esp+44h] [ebp+14h]
  char v44; // [esp+4Bh] [ebp+1Bh]

  v40 = 0;
  v7 = alloca(76 * nTotalStripCount);
  v8 = 0;
  v36 = (const MeshInstanceData_t *)&v31;
  v38 = nullptr;
  v39 = 0;
  v37 = 0;
  v35 = -1;
  v44 = 0;
  if ( nCount <= 0 )
    goto LABEL_30;
  p_m_nCompressionType = &pRenderData->m_nCompressionType;
  v43 = &pRenderData->m_nCompressionType;
  v33 = nCount;
  do
  {
    v10 = *((_DWORD *)p_m_nCompressionType - 1);
    if ( nFlashlightMask == 0 || (nFlashlightMask & *(_DWORD *)(v10 + 40)) != 0 )
    {
      v11 = *(_DWORD *)(v10 + 48) != 0;
      v42 = v11;
      if ( v38 != *((IMaterial **)p_m_nCompressionType - 2)
        || v35 != *p_m_nCompressionType
        || v8 != p_m_nCompressionType[1]
        || v44 != v11 )
      {
        if ( v40 > 0 )
        {
          pRenderContext->SetNumBoneWeights(this: pRenderContext, a2: v8 <= 0 ? 0 : v39);
          pRenderContext->Bind(this: pRenderContext, a2: v38, a3: nullptr);
          pRenderContext->DrawInstances(this: pRenderContext, a2: v40, a3: v36);
          v11 = v42;
        }
        v13 = *((IMaterial **)p_m_nCompressionType - 2);
        v40 = 0;
        v39 = 0;
        v35 = *p_m_nCompressionType;
        v14 = p_m_nCompressionType[1];
        v38 = v13;
        v37 = v14;
        v44 = v11;
      }
      v15 = *((_DWORD *)p_m_nCompressionType - 4);
      v16 = *(_DWORD *)(v15 + 4) <= 0;
      v32 = v15;
      v34 = 0;
      if ( !v16 )
      {
        v17 = &v36[v40];
        v41 = 0;
        do
        {
          v18 = *(const ITexture **)(v10 + 32);
          v19 = v41 + *(_DWORD *)(v15 + 12);
          ++v40;
          v20 = v17;
          v17->m_pEnvCubemap = v18;
          v17->m_pPoseToWorld = *(matrix3x4_t **)(v10 + 12);
          v17->m_pLightingState = *(MaterialLightingState_t **)(v10 + 24);
          v21 = *(_DWORD *)(v10 + 48);
          ++v17;
          if ( v21 != 0 )
          {
            v22 = (const IVertexBuffer **)(v21 + 16 * *(__int16 *)(v15 + 38));
            v20->m_pColorBuffer = *v22;
            v23 = (int)v22[2];
            v15 = v32;
          }
          else
          {
            v23 = 0;
            v20->m_pColorBuffer = nullptr;
          }
          v20->m_nColorVertexOffsetInBytes = v23;
          v24 = *(_DWORD *)(v19 + 19);
          v20->m_nBoneCount = v24;
          if ( v24 <= 0 )
            v25 = nullptr;
          else
            v25 = (MeshBoneRemap_t *)(v19 + *(_DWORD *)(v19 + 23));
          v20->m_pBoneRemap = v25;
          v20->m_nIndexOffset = *(_DWORD *)(v19 + 4);
          v20->m_nIndexCount = *(_DWORD *)v19;
          v20->m_nPrimType = MATERIAL_TRIANGLES;
          v20->m_pVertexBuffer = **((const IVertexBuffer ***)v43 - 4);
          v26 = **((const IIndexBuffer ***)v43 - 4);
          if ( v26 != nullptr )
            v27 = v26 + 1;
          else
            v27 = nullptr;
          v20->m_pIndexBuffer = v27;
          v20->m_nVertexOffsetInBytes = 0;
          v20->m_pStencilState = *(struct ShaderStencilState_t **)(v10 + 44);
          v20->m_DiffuseModulation.x = *(float *)(v10 + 52);
          v20->m_DiffuseModulation.y = *(float *)(v10 + 56);
          v20->m_DiffuseModulation.z = *(float *)(v10 + 60);
          v20->m_DiffuseModulation.w = *(float *)(v10 + 64);
          v20->m_nLightmapPageId = -4;
          if ( v39 <= *(__int16 *)(v19 + 16) )
            v39 = *(__int16 *)(v19 + 16);
          v41 += 35;
          ++v34;
        }
        while ( v34 < *(_DWORD *)(v15 + 4) );
      }
      p_m_nCompressionType = v43;
      v8 = v37;
    }
    p_m_nCompressionType += 10;
    v28 = v33-- == 1;
    v43 = p_m_nCompressionType;
  }
  while ( !v28 );
  v29 = v40;
  if ( v40 <= 0 )
  {
LABEL_30:
    v30 = pRenderContext;
  }
  else
  {
    v30 = pRenderContext;
    pRenderContext->SetNumBoneWeights(this: pRenderContext, a2: v8 <= 0 ? 0 : v39);
    v30->Bind(this: v30, a2: v38, a3: nullptr);
    v30->DrawInstances(this: v30, a2: v29, a3: v36);
  }
  v30->SetNumBoneWeights(this: v30, a2: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1004C4B0
// Name: private: static bool CStudioRender::SortDecalsLessFunc(struct CStudioRender::DecalRenderData_t const __near &,struct CStudioRender::DecalRenderData_t const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl CStudioRender::SortDecalsLessFunc(
        const CStudioRender::DecalRenderData_t *left,
        const CStudioRender::DecalRenderData_t *right)
{
  IMaterial *m_pMaterial; // ecx
  IMaterial *v3; // esi
  bool v4; // cf
  bool result; // al
  StudioArrayInstanceData_t *m_pInstance; // ecx
  StudioArrayInstanceData_t *v7; // eax
  ITexture *m_pEnvCubemapTexture; // edx
  ITexture *v9; // esi
  MaterialLightingState_t *m_pLightingState; // edx
  MaterialLightingState_t *v11; // esi

  m_pMaterial = left->m_pDecalMaterial->m_pMaterial;
  v3 = right->m_pDecalMaterial->m_pMaterial;
  v4 = v3 < m_pMaterial;
  if ( v3 != m_pMaterial )
    return v4;
  m_pInstance = right->m_pInstance;
  v7 = left->m_pInstance;
  m_pEnvCubemapTexture = v7->m_pEnvCubemapTexture;
  v9 = m_pInstance->m_pEnvCubemapTexture;
  v4 = v9 < m_pEnvCubemapTexture;
  if ( v9 != m_pEnvCubemapTexture )
    return v4;
  m_pLightingState = v7->m_pLightingState;
  v11 = m_pInstance->m_pLightingState;
  result = m_pLightingState != nullptr;
  if ( (m_pLightingState != nullptr) == (v11 != nullptr) && m_pLightingState != nullptr )
    return m_pLightingState->m_nLocalLightCount > v11->m_nLocalLightCount;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1004C510
// Name: private: void CStudioRender::GetDepthWriteMaterial(class IMaterial __near * __near *,bool __near *,bool __near *,class IMaterial __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CStudioRender::GetDepthWriteMaterial(
        CStudioRender *this,
        IMaterial **ppDepthMaterial,
        bool *pIsAlphaTested,
        bool *pUsesTreeSway,
        IMaterial *pSrcMaterial)
{
  IMaterialVar *v6; // edi
  IMaterialVar *v7; // ebx
  BOOL v8; // edi
  BOOL v9; // esi
  BOOL v10; // eax

  v6 = pSrcMaterial->FindVarFast(this: pSrcMaterial, a2: "$basetexture", a3: &originalTextureVarCache);
  v7 = pSrcMaterial->FindVarFast(this: pSrcMaterial, a2: "$treesway", a3: &nOriginalTreeSwayVarCache);
  v8 = pSrcMaterial->IsAlphaTested(this: pSrcMaterial) && (*((_BYTE *)v6 + 28) & 0xF) == 3;
  v9 = pSrcMaterial->IsTwoSided(this: pSrcMaterial);
  v10 = v7 != nullptr && v7->GetIntValueInternal(this: v7) != 0;
  *ppDepthMaterial = this->m_pDepthWrite[v8][v9][v10];
  *pIsAlphaTested = v8;
  *pUsesTreeSway = v10;
}

//------------------------------------------------------------------------------
// Address: 0x1004C5D0
// Name: private: void CStudioRender::SetupAlphaTestedDepthWrite(class IMaterial __near *,class IMaterial __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CStudioRender::SetupAlphaTestedDepthWrite(
        CStudioRender *this,
        IMaterial *pDepthMaterial,
        IMaterial *pSrcMaterial)
{
  IMaterialVar *v4; // edi
  IMaterialVar *v5; // eax
  IMaterialVar *v7; // ebx
  IMaterialVar *v8; // esi
  int v9; // eax
  int v10; // eax
  IMaterialVar *pOriginalAlphaRefVar; // [esp+48h] [ebp-8h]
  IMaterialVar *pOriginalTextureFrameVar; // [esp+4Ch] [ebp-4h]
  IMaterialVar *pTextureFrameVar; // [esp+58h] [ebp+8h]
  IMaterial *pSrcMateriala; // [esp+5Ch] [ebp+Ch]
  float pSrcMaterialb; // [esp+5Ch] [ebp+Ch]

  v4 = pSrcMaterial->FindVarFast(this: pSrcMaterial, a2: "$basetexture", a3: &originalTextureVarCache_0);
  pOriginalTextureFrameVar = pSrcMaterial->FindVarFast(
                               this: pSrcMaterial,
                               a2: "$frame",
                               a3: &originalTextureFrameVarCache);
  v5 = pSrcMaterial->FindVarFast(this: pSrcMaterial, a2: "$AlphaTestReference", a3: &originalAlphaRefCache);
  pOriginalAlphaRefVar = v5;
  v7 = pDepthMaterial->FindVarFast(this: pDepthMaterial, a2: "$basetexture", a3: &textureVarCache);
  pTextureFrameVar = pDepthMaterial->FindVarFast(this: pDepthMaterial, a2: "$frame", a3: &textureFrameVarCache);
  v8 = pDepthMaterial->FindVarFast(this: pDepthMaterial, a2: "$AlphaTestReference", a3: &alphaRefCache);
  if ( (*((_BYTE *)v4 + 28) & 0xF) == 3 )
  {
    if ( v7 != nullptr )
    {
      pSrcMateriala = (IMaterial *)v7->__vftable;
      v9 = v4->GetTextureValue(this: v4);
      ((void (__thiscall *)(IMaterialVar *, int))pSrcMateriala[15].__vftable)(a1: v7, a2: v9);
    }
    if ( pTextureFrameVar != nullptr && pOriginalTextureFrameVar != nullptr )
    {
      v10 = pOriginalTextureFrameVar->GetIntValueInternal(this: pOriginalTextureFrameVar);
      pTextureFrameVar->SetIntValue(this: pTextureFrameVar, a2: v10);
    }
    if ( v8 != nullptr && pOriginalAlphaRefVar != nullptr )
    {
      pSrcMaterialb = pOriginalAlphaRefVar->GetFloatValueInternal(this: pOriginalAlphaRefVar);
      ((void (__thiscall *)(IMaterialVar *, _DWORD))v8->SetFloatValue)(a1: v8, a2: LODWORD(pSrcMaterialb));
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004C6F0
// Name: private: void CStudioRender::SetupTreeSwayDepthWrite(class IMaterial __near *,class IMaterial __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CStudioRender::SetupTreeSwayDepthWrite(
        CStudioRender *this,
        IMaterial *pDepthMaterial,
        IMaterial *pSrcMaterial)
{
  unsigned int i; // esi
  IMaterialVar *v4; // edi
  IMaterialVar *v5; // eax
  IMaterialVar *v6; // ebx
  float v7; // [esp+20h] [ebp-4h]

  for ( i = 0; i < 14; ++i )
  {
    v4 = pSrcMaterial->FindVarFast(this: pSrcMaterial, a2: paramNames[i], a3: &originalVarCache[i]);
    v5 = pDepthMaterial->FindVarFast(this: pDepthMaterial, a2: paramNames[i], a3: &varCache[i]);
    v6 = v5;
    if ( v4 != nullptr && v5 != nullptr )
    {
      v7 = v4->GetFloatValueInternal(this: v4);
      ((void (__thiscall *)(IMaterialVar *, _DWORD))v6->SetFloatValue)(a1: v6, a2: LODWORD(v7));
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004C780
// Name: private: static bool CStudioRender::ShadowSortLessFunc(struct ShadowMeshRenderData_t const __near &,struct ShadowMeshRenderData_t const __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl CStudioRender::ShadowSortLessFunc(const ShadowMeshRenderData_t *left, const ShadowMeshRenderData_t *right)
{
  IMaterial *m_pMaterial; // edx
  IMaterial *v3; // esi
  bool v4; // cf
  IMaterial *v5; // edx
  IMaterial *v6; // esi
  IMaterial *m_pSrcMaterial; // edx
  IMaterial *v8; // esi
  __int32 m_nCompressionType; // edx
  __int32 m_nMeshBoneCount; // esi

  m_pMaterial = left->m_pMaterial;
  v3 = right->m_pMaterial;
  v4 = v3 < m_pMaterial;
  if ( v3 == m_pMaterial )
  {
    if ( !left->m_bIsAlphaTested
      || !right->m_bIsAlphaTested
      || (v5 = left->m_pSrcMaterial, v6 = right->m_pSrcMaterial, v4 = v6 < v5, v6 == v5) )
    {
      if ( !left->m_bUsesTreeSway
        || !right->m_bUsesTreeSway
        || (m_pSrcMaterial = left->m_pSrcMaterial,
            v8 = right->m_pSrcMaterial,
            v4 = v8 < m_pSrcMaterial,
            v8 == m_pSrcMaterial) )
      {
        m_nCompressionType = left->m_nCompressionType;
        m_nMeshBoneCount = right->m_nCompressionType;
        if ( m_nCompressionType != m_nMeshBoneCount )
          return m_nCompressionType > m_nMeshBoneCount;
        m_nCompressionType = left->m_nMeshBoneCount;
        m_nMeshBoneCount = right->m_nMeshBoneCount;
        if ( m_nCompressionType != m_nMeshBoneCount )
          return m_nCompressionType > m_nMeshBoneCount;
        return right->m_pGroup->BaseMeshRenderData_t::m_pMesh < left->m_pGroup->BaseMeshRenderData_t::m_pMesh;
      }
    }
  }
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x1004C7F0
// Name: private: void CStudioRender::DrawShadowMeshRenderData(class IMatRenderContext __near *,int,struct ShadowMeshRenderData_t __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CStudioRender::DrawShadowMeshRenderData(
        CStudioRender *this,
        IMatRenderContext *pRenderContext,
        int nCount,
        ShadowMeshRenderData_t *pRenderData,
        int nTotalStripCount)
{
  IMaterial *v5; // esi
  void *v6; // esp
  char v7; // cl
  IMaterial *v8; // edi
  VertexCompressionType_t *p_m_nCompressionType; // ebx
  VertexCompressionType_t v11; // ecx
  IMaterial *v12; // edx
  IMaterial *v13; // eax
  int v14; // ecx
  const IVertexBuffer **v15; // esi
  const MeshInstanceData_t *v16; // edi
  int v17; // edx
  int v18; // ecx
  const MeshInstanceData_t *v19; // eax
  int v20; // edx
  MeshBoneRemap_t *v21; // edx
  int v22; // edx
  int v23; // ebx
  IMatRenderContext *v24; // esi
  int v25; // [esp+0h] [ebp-38h] BYREF
  int v26; // [esp+Ch] [ebp-2Ch]
  int v27; // [esp+10h] [ebp-28h]
  int v28; // [esp+14h] [ebp-24h]
  const MeshInstanceData_t *v29; // [esp+18h] [ebp-20h]
  IMaterial *v30; // [esp+1Ch] [ebp-1Ch]
  int v31; // [esp+20h] [ebp-18h]
  CStudioRender *v32; // [esp+24h] [ebp-14h]
  IMaterial *pSrcMaterial; // [esp+28h] [ebp-10h]
  int v34; // [esp+2Ch] [ebp-Ch]
  int v35; // [esp+30h] [ebp-8h]
  char v36; // [esp+37h] [ebp-1h]
  int v37; // [esp+44h] [ebp+Ch]
  int v38; // [esp+48h] [ebp+10h]
  char v39; // [esp+4Fh] [ebp+17h]

  v5 = nullptr;
  v32 = this;
  v35 = 0;
  v6 = alloca(76 * nTotalStripCount);
  v7 = 0;
  v8 = nullptr;
  v29 = (const MeshInstanceData_t *)&v25;
  v34 = 0;
  v31 = 0;
  v30 = nullptr;
  pSrcMaterial = nullptr;
  v36 = 0;
  v39 = 0;
  v28 = -1;
  if ( nCount <= 0 )
    goto LABEL_37;
  p_m_nCompressionType = &pRenderData->m_nCompressionType;
  v27 = nCount;
  while ( 1 )
  {
    v26 = *((_DWORD *)p_m_nCompressionType - 2);
    if ( v8 != *((IMaterial **)p_m_nCompressionType - 3)
      || v7 != 0 && v5 != *((IMaterial **)p_m_nCompressionType - 1)
      || v39 != 0 && v5 != *((IMaterial **)p_m_nCompressionType - 1)
      || v28 != *p_m_nCompressionType
      || v31 != *((_DWORD *)p_m_nCompressionType + 1) )
    {
      if ( v35 > 0 )
      {
        if ( v7 != 0 )
          CStudioRender::SetupAlphaTestedDepthWrite(this: v32, pDepthMaterial: v8, pSrcMaterial: v5);
        if ( v39 != 0 )
          CStudioRender::SetupTreeSwayDepthWrite(this: v32, pDepthMaterial: v8, pSrcMaterial: v5);
        pRenderContext->SetNumBoneWeights(this: pRenderContext, a2: v31 <= 0 ? 0 : v34);
        pRenderContext->Bind(this: pRenderContext, a2: v8, a3: nullptr);
        pRenderContext->DrawInstances(this: pRenderContext, a2: v35, a3: v29);
      }
      v11 = *p_m_nCompressionType;
      v12 = *((IMaterial **)p_m_nCompressionType - 3);
      v35 = 0;
      v34 = 0;
      v13 = *((IMaterial **)p_m_nCompressionType - 1);
      v28 = v11;
      v14 = *((_DWORD *)p_m_nCompressionType + 1);
      v30 = v12;
      LOBYTE(v12) = *((_BYTE *)p_m_nCompressionType + 8);
      v8 = v30;
      pSrcMaterial = v13;
      LOBYTE(v13) = *((_BYTE *)p_m_nCompressionType + 9);
      v31 = v14;
      v36 = (char)v12;
      v39 = (char)v13;
      v7 = (char)v12;
    }
    v15 = *((const IVertexBuffer ***)p_m_nCompressionType - 5);
    v38 = 0;
    if ( (int)v15[1] > 0 )
    {
      v16 = &v29[v35];
      v37 = 0;
      do
      {
        v17 = v26;
        v18 = (int)v15[3] + v37;
        ++v35;
        v19 = v16;
        v16->m_pEnvCubemap = nullptr;
        v16->m_pPoseToWorld = *(matrix3x4_t **)(v17 + 12);
        v16->m_pLightingState = nullptr;
        v20 = *(_DWORD *)(v18 + 19);
        ++v16;
        v19->m_nBoneCount = v20;
        if ( v20 <= 0 )
          v21 = nullptr;
        else
          v21 = (MeshBoneRemap_t *)(v18 + *(_DWORD *)(v18 + 23));
        v19->m_pBoneRemap = v21;
        v19->m_nIndexOffset = *(_DWORD *)(v18 + 4);
        v19->m_nIndexCount = *(_DWORD *)v18;
        v19->m_nPrimType = MATERIAL_TRIANGLES;
        v19->m_pColorBuffer = nullptr;
        v19->m_nColorVertexOffsetInBytes = 0;
        v19->m_pStencilState = nullptr;
        v19->m_pVertexBuffer = *v15;
        if ( *v15 != nullptr )
          v22 = (int)&(*v15)[1];
        else
          v22 = 0;
        v19->m_pIndexBuffer = (const IIndexBuffer *)v22;
        v19->m_nVertexOffsetInBytes = 0;
        v19->m_DiffuseModulation.x = 1.0;
        v19->m_DiffuseModulation.y = 1.0;
        v19->m_DiffuseModulation.z = 1.0;
        v19->m_DiffuseModulation.w = 1.0;
        v19->m_nLightmapPageId = -4;
        if ( v34 <= *(__int16 *)(v18 + 16) )
          v34 = *(__int16 *)(v18 + 16);
        v37 += 35;
        ++v38;
      }
      while ( v38 < (int)v15[1] );
      v8 = v30;
      v7 = v36;
    }
    p_m_nCompressionType += 8;
    if ( --v27 == 0 )
      break;
    v5 = pSrcMaterial;
  }
  v23 = v35;
  if ( v35 <= 0 )
  {
LABEL_37:
    v24 = pRenderContext;
  }
  else
  {
    if ( v7 != 0 )
      CStudioRender::SetupAlphaTestedDepthWrite(this: v32, pDepthMaterial: v8, pSrcMaterial);
    if ( v39 != 0 )
      CStudioRender::SetupTreeSwayDepthWrite(this: v32, pDepthMaterial: v8, pSrcMaterial);
    v24 = pRenderContext;
    pRenderContext->SetNumBoneWeights(this: pRenderContext, a2: v31 <= 0 ? 0 : v34);
    v24->Bind(this: v24, a2: v8, a3: nullptr);
    v24->DrawInstances(this: v24, a2: v23, a3: v29);
  }
  v24->SetNumBoneWeights(this: v24, a2: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1004CA80
// Name: private: void CStudioRender::ComputeDiffuseModulation(class Vector4D __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CStudioRender::ComputeDiffuseModulation(CStudioRender *this, Vector4D *pDiffuseModulation)
{
  StudioRenderContext_t *m_pRC; // eax
  float v3; // xmm0_4
  float v4; // xmm1_4
  float m_AlphaMod; // xmm2_4

  m_pRC = this->m_pRC;
  if ( m_pRC->m_nForcedMaterialType == OVERRIDE_DEPTH_WRITE )
  {
    pDiffuseModulation->x = 1.0;
    pDiffuseModulation->z = 1.0;
    pDiffuseModulation->w = 1.0;
    pDiffuseModulation->y = 1.0;
  }
  else
  {
    v3 = m_pRC->m_ColorMod[1];
    v4 = m_pRC->m_ColorMod[2];
    m_AlphaMod = m_pRC->m_AlphaMod;
    pDiffuseModulation->x = m_pRC->m_ColorMod[0];
    pDiffuseModulation->z = v4;
    pDiffuseModulation->w = m_AlphaMod;
    pDiffuseModulation->y = v3;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004CAF0
// Name: unsigned int FacesRenderedInfoKeyFunc(struct IStudioRender::FacesRenderedInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
unsigned int __cdecl FacesRenderedInfoKeyFunc(const IStudioRender::FacesRenderedInfo_t *a)
{
  return ((unsigned int)a->pStudioHdr >> 24)
       + 33
       * ((unsigned __int8)BYTE2(a->pStudioHdr)
        + 33 * ((unsigned __int8)BYTE1(a->pStudioHdr) + 33 * ((unsigned __int8)a->pStudioHdr - 1431655766)));
}

//------------------------------------------------------------------------------
// Address: 0x1004CB40
// Name: int FacesRenderedInfoSort(void const __near *,void const __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl FacesRenderedInfoSort(_DWORD *a, _DWORD *b)
{
  return b[1] < a[1] ? -1 : 1;
}

//------------------------------------------------------------------------------
// Address: 0x1004CB60
// Name: void std::_Push_heap<struct MeshRenderData2_t __near *,int,struct MeshRenderData2_t,bool (*)(struct MeshRenderData2_t const __near &,struct MeshRenderData2_t const __near &)>(struct MeshRenderData2_t __near *,int,int,struct MeshRenderData2_t __near &&,bool (*)(struct MeshRenderData2_t const __near &,struct MeshRenderData2_t const __near &))
// Source: json
//------------------------------------------------------------------------------
void __cdecl std::_Push_heap<MeshRenderData2_t *,int,MeshRenderData2_t,bool (__cdecl *)(MeshRenderData2_t const &,MeshRenderData2_t const &)>(
        MeshRenderData2_t *_First,
        int _Hole,
        int _Top,
        MeshRenderData2_t *_Val,
        bool (__cdecl *_Pred)(const MeshRenderData2_t *, const MeshRenderData2_t *))
{
  int v5; // edi
  int i; // esi
  MeshRenderData2_t *v7; // ebx
  MeshRenderData2_t *v8; // eax

  v5 = _Hole;
  for ( i = (_Hole - 1) / 2; _Top < v5; i = (i - 1) / 2 )
  {
    v7 = &_First[i];
    if ( !_Pred(a1: v7, a2: _Val) )
      break;
    v8 = &_First[v5];
    *(_QWORD *)&v8->m_pGroup = *(_QWORD *)&v7->m_pGroup;
    *(_QWORD *)&v8->m_pMaterial = *(_QWORD *)&v7->m_pMaterial;
    *(_DWORD *)&v8->m_nCompressionType = *(_DWORD *)&v7->m_nCompressionType;
    v5 = i;
  }
  _First[v5] = *_Val;
}

//------------------------------------------------------------------------------
// Address: 0x1004CC00
// Name: void std::_Push_heap<struct CStudioRender::DecalRenderData_t __near *,int,struct CStudioRender::DecalRenderData_t,bool (*)(struct CStudioRender::DecalRenderData_t const __near &,struct CStudioRender::DecalRenderData_t const __near &)>(struct CStudioRender::DecalRenderData_t __near *,int,int,struct CStudioRender::DecalRenderData_t __near &&,bool (*)(struct CStudioRender::DecalRenderData_t const __near &,struct CStudioRender::DecalRenderData_t const __near &))
// Source: json
//------------------------------------------------------------------------------
void __cdecl std::_Push_heap<CStudioRender::DecalRenderData_t *,int,CStudioRender::DecalRenderData_t,bool (__cdecl *)(CStudioRender::DecalRenderData_t const &,CStudioRender::DecalRenderData_t const &)>(
        CStudioRender::DecalRenderData_t *_First,
        int _Hole,
        int _Top,
        CStudioRender::DecalRenderData_t *_Val,
        bool (__cdecl *_Pred)(const CStudioRender::DecalRenderData_t *, const CStudioRender::DecalRenderData_t *))
{
  int v5; // edi
  int i; // esi
  CStudioRender::DecalRenderData_t *v7; // ebx
  CStudioRender::DecalRenderData_t *v8; // eax

  v5 = _Hole;
  for ( i = (_Hole - 1) / 2; _Top < v5; i = (i - 1) / 2 )
  {
    v7 = &_First[i];
    if ( !_Pred(a1: v7, a2: _Val) )
      break;
    v8 = &_First[v5];
    v5 = i;
    *(_QWORD *)&v8->m_pDecalMaterial = *(_QWORD *)&v7->m_pDecalMaterial;
    *(_QWORD *)&v8->m_pRenderMaterial = *(_QWORD *)&v7->m_pRenderMaterial;
  }
  _First[v5] = *_Val;
}

//------------------------------------------------------------------------------
// Address: 0x1004CC80
// Name: void std::_Push_heap<struct ShadowMeshRenderData_t __near *,int,struct ShadowMeshRenderData_t,bool (*)(struct ShadowMeshRenderData_t const __near &,struct ShadowMeshRenderData_t const __near &)>(struct ShadowMeshRenderData_t __near *,int,int,struct ShadowMeshRenderData_t __near &&,bool (*)(struct ShadowMeshRenderData_t const __near &,struct ShadowMeshRenderData_t const __near &))
// Source: json
//------------------------------------------------------------------------------
void __cdecl std::_Push_heap<ShadowMeshRenderData_t *,int,ShadowMeshRenderData_t,bool (__cdecl *)(ShadowMeshRenderData_t const &,ShadowMeshRenderData_t const &)>(
        ShadowMeshRenderData_t *_First,
        int _Hole,
        int _Top,
        ShadowMeshRenderData_t *_Val,
        bool (__cdecl *_Pred)(const ShadowMeshRenderData_t *, const ShadowMeshRenderData_t *))
{
  int v5; // ebx
  int i; // edi
  ShadowMeshRenderData_t *v7; // esi
  ShadowMeshRenderData_t *v8; // eax

  v5 = _Hole;
  for ( i = (_Hole - 1) / 2; _Top < v5; i = (i - 1) / 2 )
  {
    v7 = &_First[i];
    if ( !_Pred(a1: v7, a2: _Val) )
      break;
    v8 = &_First[v5];
    v5 = i;
    *(_QWORD *)&v8->m_pGroup = *(_QWORD *)&v7->m_pGroup;
    *(_QWORD *)&v8->m_pMaterial = *(_QWORD *)&v7->m_pMaterial;
    *(_QWORD *)&v8->m_pSrcMaterial = *(_QWORD *)&v7->m_pSrcMaterial;
    *(_QWORD *)&v8->m_nMeshBoneCount = *(_QWORD *)&v7->m_nMeshBoneCount;
  }
  _First[v5] = *_Val;
}

//------------------------------------------------------------------------------
// Address: 0x1004CD30
// Name: public: void CUtlMemory<struct CStudioRender::ShadowState_t,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<CStudioRender::ShadowState_t,int>::Grow(
        CUtlMemory<CStudioRender::ShadowState_t,int> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  CStudioRender::ShadowState_t *m_pMemory; // ecx

  m_nGrowSize = this->m_nGrowSize;
  if ( m_nGrowSize >= 0 )
  {
    m_nAllocationCount = this->m_nAllocationCount;
    v5 = m_nAllocationCount + num;
    if ( m_nGrowSize != 0 )
    {
      m_nAllocationCount = m_nGrowSize * ((v5 - 1) / m_nGrowSize + 1);
    }
    else
    {
      if ( m_nAllocationCount == 0 )
        m_nAllocationCount = 2;
      if ( m_nAllocationCount >= v5 )
        goto LABEL_13;
      do
        m_nAllocationCount *= 2;
      while ( m_nAllocationCount < v5 );
    }
    if ( m_nAllocationCount < v5 )
    {
      if ( m_nAllocationCount != 0 || v5 > -1 )
      {
        do
          m_nAllocationCount = (v5 + m_nAllocationCount) / 2;
        while ( m_nAllocationCount < v5 );
      }
      else
      {
        m_nAllocationCount = -1;
      }
    }
LABEL_13:
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (CStudioRender::ShadowState_t *)_realloc_crt(ptr: m_pMemory, size: 20 * m_nAllocationCount);
    else
      this->m_pMemory = (CStudioRender::ShadowState_t *)operator new(nSize: 20 * m_nAllocationCount);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004CDD0
// Name: private: void CStudioRender::DrawModelArrayFlashlight(class IMatRenderContext __near *,struct StudioModelArrayInfo_t const __near &,int,struct MeshRenderData_t __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CStudioRender::DrawModelArrayFlashlight(
        CStudioRender *this,
        IMatRenderContext *pRenderContext,
        const StudioModelArrayInfo_t *drawInfo,
        int nCount,
        MeshRenderData_t *pRenderData,
        int nTotalStripCount)
{
  int m_nFlashlightCount; // edi
  FlashlightInstance_t *v8; // edi
  const FlashlightState_t *p_m_FlashlightState; // ebx
  void *v10; // esp
  IMaterial **p_m_pMaterial; // eax
  int i; // ecx
  bool v13; // zf
  unsigned __int8 v14[12]; // [esp+0h] [ebp-24h] BYREF
  const FlashlightState_t *state; // [esp+Ch] [ebp-18h]
  int v16; // [esp+10h] [ebp-14h]
  CStudioRender *v17; // [esp+14h] [ebp-10h]
  MeshRenderData_t *pTempData; // [esp+18h] [ebp-Ch]
  unsigned int v19; // [esp+1Ch] [ebp-8h]
  int nFlashlightMask; // [esp+20h] [ebp-4h]
  char bDoScissor_3; // [esp+2Fh] [ebp+Bh]

  m_nFlashlightCount = drawInfo->m_nFlashlightCount;
  v17 = this;
  if ( m_nFlashlightCount != 0 )
  {
    pRenderContext->SetFlashlightMode(this: pRenderContext, a2: true);
    if ( r_flashlightscissor.m_pParent == nullptr
      || r_flashlightscissor.m_pParent->m_Value.m_nValue == 0
      || (bDoScissor_3 = 1, pRenderContext->GetRenderTarget(this: pRenderContext) != nullptr) )
    {
      bDoScissor_3 = 0;
    }
    nFlashlightMask = 1;
    if ( m_nFlashlightCount > 0 )
    {
      v19 = 0;
      v16 = m_nFlashlightCount;
      do
      {
        v8 = &drawInfo->m_pFlashlights[v19 / 0x144];
        p_m_FlashlightState = &v8->m_FlashlightState;
        state = &v8->m_FlashlightState;
        if ( bDoScissor_3 != 0 && v8->m_FlashlightState.m_bScissor )
          pRenderContext->PushScissorRect(
            this: pRenderContext,
            a2: v8->m_FlashlightState.m_nLeft,
            a3: v8->m_FlashlightState.m_nTop,
            a4: v8->m_FlashlightState.m_nRight,
            a5: v8->m_FlashlightState.m_nBottom);
        if ( v8->m_pDebugMaterial != nullptr )
        {
          v10 = alloca(16 * nCount);
          pTempData = (MeshRenderData_t *)v14;
          memcpy(dst: v14, src: (unsigned __int8 *)pRenderData, count: 16 * nCount);
          if ( nCount > 0 )
          {
            p_m_pMaterial = &pTempData->m_pMaterial;
            for ( i = nCount; i != 0; --i )
            {
              *p_m_pMaterial = v8->m_pDebugMaterial;
              p_m_pMaterial += 4;
            }
          }
          pRenderContext->SetFlashlightMode(this: pRenderContext, a2: false);
          CStudioRender::DrawMeshRenderData(
            this: v17,
            pRenderContext,
            drawInfo,
            nCount,
            pRenderData: pTempData,
            nTotalStripCount,
            nFlashlightMask);
          pRenderContext->SetFlashlightMode(this: pRenderContext, a2: true);
          p_m_FlashlightState = state;
        }
        else
        {
          pRenderContext->SetFlashlightStateEx(
            this: pRenderContext,
            a2: p_m_FlashlightState,
            a3: &v8->m_WorldToTexture,
            a4: v8->m_pFlashlightDepthTexture);
          CStudioRender::DrawMeshRenderData(
            this: v17,
            pRenderContext,
            drawInfo,
            nCount,
            pRenderData,
            nTotalStripCount,
            nFlashlightMask);
        }
        if ( bDoScissor_3 != 0 && p_m_FlashlightState->m_bScissor )
          pRenderContext->PopScissorRect(this: pRenderContext);
        v19 += 324;
        v13 = v16-- == 1;
        nFlashlightMask = __ROL4__(nFlashlightMask, 1);
      }
      while ( !v13 );
    }
    pRenderContext->SetFlashlightMode(this: pRenderContext, a2: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004CF80
// Name: private: void CStudioRender::DrawModelArrayFlashlight(class IMatRenderContext __near *,struct StudioModelArrayInfo2_t const __near &,int,struct MeshRenderData2_t __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CStudioRender::DrawModelArrayFlashlight(
        CStudioRender *this,
        IMatRenderContext *pRenderContext,
        const StudioModelArrayInfo2_t *drawInfo,
        int nCount,
        MeshRenderData2_t *pRenderData,
        int nTotalStripCount)
{
  int m_nFlashlightCount; // edi
  FlashlightInstance_t *v8; // edi
  const FlashlightState_t *p_m_FlashlightState; // ebx
  void *v10; // esp
  IMaterial **p_m_pMaterial; // eax
  int i; // ecx
  bool v13; // zf
  unsigned __int8 v14[12]; // [esp+0h] [ebp-24h] BYREF
  const FlashlightState_t *state; // [esp+Ch] [ebp-18h]
  int v16; // [esp+10h] [ebp-14h]
  CStudioRender *v17; // [esp+14h] [ebp-10h]
  MeshRenderData2_t *pTempData; // [esp+18h] [ebp-Ch]
  unsigned int v19; // [esp+1Ch] [ebp-8h]
  int nFlashlightMask; // [esp+20h] [ebp-4h]
  char bDoScissor_3; // [esp+2Fh] [ebp+Bh]

  m_nFlashlightCount = drawInfo->m_nFlashlightCount;
  v17 = this;
  if ( m_nFlashlightCount != 0 )
  {
    pRenderContext->SetFlashlightMode(this: pRenderContext, a2: true);
    if ( r_flashlightscissor.m_pParent == nullptr
      || r_flashlightscissor.m_pParent->m_Value.m_nValue == 0
      || (bDoScissor_3 = 1, pRenderContext->GetRenderTarget(this: pRenderContext) != nullptr) )
    {
      bDoScissor_3 = 0;
    }
    nFlashlightMask = 1;
    if ( m_nFlashlightCount > 0 )
    {
      v19 = 0;
      v16 = m_nFlashlightCount;
      do
      {
        v8 = &drawInfo->m_pFlashlights[v19 / 0x144];
        p_m_FlashlightState = &v8->m_FlashlightState;
        state = &v8->m_FlashlightState;
        if ( bDoScissor_3 != 0 && v8->m_FlashlightState.m_bScissor )
          pRenderContext->PushScissorRect(
            this: pRenderContext,
            a2: v8->m_FlashlightState.m_nLeft,
            a3: v8->m_FlashlightState.m_nTop,
            a4: v8->m_FlashlightState.m_nRight,
            a5: v8->m_FlashlightState.m_nBottom);
        if ( v8->m_pDebugMaterial != nullptr )
        {
          v10 = alloca(20 * nCount);
          pTempData = (MeshRenderData2_t *)v14;
          memcpy(dst: v14, src: (unsigned __int8 *)pRenderData, count: 20 * nCount);
          if ( nCount > 0 )
          {
            p_m_pMaterial = &pTempData->m_pMaterial;
            for ( i = nCount; i != 0; --i )
            {
              *p_m_pMaterial = v8->m_pDebugMaterial;
              p_m_pMaterial += 5;
            }
          }
          pRenderContext->SetFlashlightMode(this: pRenderContext, a2: false);
          CStudioRender::DrawMeshRenderData(
            this: v17,
            pRenderContext,
            drawInfo,
            nCount,
            pRenderData: pTempData,
            nTotalStripCount,
            nFlashlightMask);
          pRenderContext->SetFlashlightMode(this: pRenderContext, a2: true);
          p_m_FlashlightState = state;
        }
        else
        {
          pRenderContext->SetFlashlightStateEx(
            this: pRenderContext,
            a2: p_m_FlashlightState,
            a3: &v8->m_WorldToTexture,
            a4: v8->m_pFlashlightDepthTexture);
          CStudioRender::DrawMeshRenderData(
            this: v17,
            pRenderContext,
            drawInfo,
            nCount,
            pRenderData,
            nTotalStripCount,
            nFlashlightMask);
        }
        if ( bDoScissor_3 != 0 && p_m_FlashlightState->m_bScissor )
          pRenderContext->PopScissorRect(this: pRenderContext);
        v19 += 324;
        v13 = v16-- == 1;
        nFlashlightMask = __ROL4__(nFlashlightMask, 1);
      }
      while ( !v13 );
    }
    pRenderContext->SetFlashlightMode(this: pRenderContext, a2: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004D140
// Name: private: void CStudioRender::DrawModelArrayFlashlightDecals(class IMatRenderContext __near *,struct studiohdr_t __near *,int,struct FlashlightInstance_t __near *,int,struct CStudioRender::DecalRenderData_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CStudioRender::DrawModelArrayFlashlightDecals(
        CStudioRender *this,
        IMatRenderContext *pRenderContext,
        studiohdr_t *pStudioHdr,
        int nFlashlightCount,
        CStudioRender::DecalRenderData_t *pFlashlights,
        int nCount,
        CStudioRender::DecalRenderData_t *pRenderData)
{
  int *p_m_bIsVertexLit; // edi
  void *v10; // esp
  int *v11; // eax
  int i; // ecx
  bool v13; // zf
  unsigned __int8 v14[8]; // [esp+0h] [ebp-14h] BYREF
  int v15; // [esp+8h] [ebp-Ch] BYREF
  int v16; // [esp+Ch] [ebp-8h]
  CStudioRender *v17; // [esp+10h] [ebp-4h]
  int pRenderContexta; // [esp+1Ch] [ebp+8h]
  char bDoScissor_3; // [esp+27h] [ebp+13h]

  v17 = this;
  if ( nFlashlightCount != 0 )
  {
    pRenderContext->SetFlashlightMode(this: pRenderContext, a2: true);
    if ( r_flashlightscissor.m_pParent == nullptr
      || r_flashlightscissor.m_pParent->m_Value.m_nValue == 0
      || (bDoScissor_3 = 1, pRenderContext->GetRenderTarget(this: pRenderContext) != nullptr) )
    {
      bDoScissor_3 = 0;
    }
    pRenderContexta = 1;
    if ( nFlashlightCount > 0 )
    {
      p_m_bIsVertexLit = (int *)&pFlashlights[15].m_bIsVertexLit;
      v16 = nFlashlightCount;
      do
      {
        if ( bDoScissor_3 != 0 && *((_BYTE *)p_m_bIsVertexLit - 15) != 0 )
          pRenderContext->PushScissorRect(
            this: pRenderContext,
            a2: *(p_m_bIsVertexLit - 3),
            a3: *(p_m_bIsVertexLit - 2),
            a4: *(p_m_bIsVertexLit - 1),
            a5: *p_m_bIsVertexLit);
        if ( *(p_m_bIsVertexLit - 63) != 0 )
        {
          v10 = alloca(16 * nCount);
          memcpy(dst: v14, src: (unsigned __int8 *)pRenderData, count: 16 * nCount);
          if ( nCount > 0 )
          {
            v11 = &v15;
            for ( i = nCount; i != 0; --i )
            {
              *v11 = *(p_m_bIsVertexLit - 63);
              v11 += 4;
            }
          }
          pRenderContext->SetFlashlightMode(this: pRenderContext, a2: false);
          CStudioRender::DrawModelArrayDecals(
            this: v17,
            pRenderContext,
            pStudioHdr,
            (studiohdr_t *)nCount,
            pRenderData: (StudioArrayInstanceData_t *)v14,
            nFlashlightMask: pRenderContexta);
          pRenderContext->SetFlashlightMode(this: pRenderContext, a2: true);
        }
        else
        {
          pRenderContext->SetFlashlightStateEx(
            this: pRenderContext,
            a2: (const FlashlightState_t *)(p_m_bIsVertexLit - 62),
            a3: (const VMatrix *)(p_m_bIsVertexLit + 1),
            a4: (ITexture *)p_m_bIsVertexLit[17]);
          CStudioRender::DrawModelArrayDecals(
            this: v17,
            pRenderContext,
            pStudioHdr,
            (studiohdr_t *)nCount,
            (StudioArrayInstanceData_t *)pRenderData,
            nFlashlightMask: pRenderContexta);
        }
        if ( bDoScissor_3 != 0 && *((_BYTE *)p_m_bIsVertexLit - 15) != 0 )
          pRenderContext->PopScissorRect(this: pRenderContext);
        p_m_bIsVertexLit += 81;
        v13 = v16-- == 1;
        pRenderContexta = __ROL4__(pRenderContexta, 1);
      }
      while ( !v13 );
    }
    pRenderContext->SetFlashlightMode(this: pRenderContext, a2: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004D2D0
// Name: void std::_Adjust_heap<struct MeshRenderData_t __near *,int,struct MeshRenderData_t,bool (*)(struct MeshRenderData_t const __near &,struct MeshRenderData_t const __near &)>(struct MeshRenderData_t __near *,int,int,struct MeshRenderData_t __near &&,bool (*)(struct MeshRenderData_t const __near &,struct MeshRenderData_t const __near &))
// Source: json
//------------------------------------------------------------------------------
void __cdecl std::_Adjust_heap<MeshRenderData_t *,int,MeshRenderData_t,bool (__cdecl *)(MeshRenderData_t const &,MeshRenderData_t const &)>(
        CStudioRender::DecalRenderData_t *_First,
        int _Hole,
        int _Bottom,
        CStudioRender::DecalRenderData_t *_Val,
        bool (__cdecl *_Pred)(const CStudioRender::DecalRenderData_t *, const CStudioRender::DecalRenderData_t *))
{
  int v5; // eax
  int v6; // ebx
  int v7; // esi
  bool v8; // zf
  int v9; // ecx
  __int64 v10; // xmm0_8
  int i; // esi
  const CStudioRender::DecalRenderData_t *_Bottoma; // [esp+1Ch] [ebp+10h]

  v5 = _Bottom;
  v6 = _Hole;
  v7 = 2 * _Hole + 2;
  v8 = v7 == _Bottom;
  if ( v7 < _Bottom )
  {
    do
    {
      if ( _Pred(a1: &_First[v7], a2: &_First[v7 - 1]) )
        --v7;
      v9 = v6;
      v6 = v7;
      *(_QWORD *)&_First[v9].m_pDecalMaterial = *(_QWORD *)&_First[v7].m_pDecalMaterial;
      v10 = *(_QWORD *)&_First[v7].m_pRenderMaterial;
      v7 = 2 * v7 + 2;
      *(_QWORD *)&_First[v9].m_pRenderMaterial = v10;
    }
    while ( v7 < _Bottom );
    v5 = _Bottom;
    v8 = v7 == _Bottom;
  }
  if ( v8 )
  {
    _First[v6] = _First[v5 - 1];
    v6 = v5 - 1;
  }
  for ( i = (v6 - 1) / 2; _Hole < v6; i = (i - 1) / 2 )
  {
    _Bottoma = &_First[i];
    if ( !_Pred(a1: _Bottoma, a2: _Val) )
      break;
    _First[v6] = *_Bottoma;
    v6 = i;
  }
  _First[v6] = *_Val;
}

//------------------------------------------------------------------------------
// Address: 0x1004D3E0
// Name: void std::_Adjust_heap<struct MeshRenderData2_t __near *,int,struct MeshRenderData2_t,bool (*)(struct MeshRenderData2_t const __near &,struct MeshRenderData2_t const __near &)>(struct MeshRenderData2_t __near *,int,int,struct MeshRenderData2_t __near &&,bool (*)(struct MeshRenderData2_t const __near &,struct MeshRenderData2_t const __near &))
// Source: json
//------------------------------------------------------------------------------
void __cdecl std::_Adjust_heap<MeshRenderData2_t *,int,MeshRenderData2_t,bool (__cdecl *)(MeshRenderData2_t const &,MeshRenderData2_t const &)>(
        MeshRenderData2_t *_First,
        int _Hole,
        int _Bottom,
        MeshRenderData2_t *_Val,
        bool (__cdecl *_Pred)(const MeshRenderData2_t *, const MeshRenderData2_t *))
{
  int v5; // eax
  int v6; // edi
  int v7; // esi
  bool v8; // zf
  MeshRenderData2_t *v9; // eax
  MeshRenderData2_t *v10; // ecx
  MeshRenderData2_t *v11; // ecx
  int i; // esi
  const MeshRenderData2_t *_Bottoma; // [esp+1Ch] [ebp+10h]

  v5 = _Bottom;
  v6 = _Hole;
  v7 = 2 * _Hole + 2;
  v8 = v7 == _Bottom;
  if ( v7 < _Bottom )
  {
    do
    {
      if ( _Pred(a1: &_First[v7], a2: &_First[v7 - 1]) )
        --v7;
      v9 = &_First[v7];
      v10 = &_First[v6];
      *(_QWORD *)&v10->m_pGroup = *(_QWORD *)&v9->m_pGroup;
      *(_QWORD *)&v10->m_pMaterial = *(_QWORD *)&v9->m_pMaterial;
      v6 = v7;
      v7 = 2 * v7 + 2;
      *(_DWORD *)&v10->m_nCompressionType = *(_DWORD *)&v9->m_nCompressionType;
    }
    while ( v7 < _Bottom );
    v5 = _Bottom;
    v8 = v7 == _Bottom;
  }
  if ( v8 )
  {
    v11 = &_First[v5 - 1];
    _First[v6] = *v11;
    v6 = v5 - 1;
  }
  for ( i = (v6 - 1) / 2; _Hole < v6; i = (i - 1) / 2 )
  {
    _Bottoma = &_First[i];
    if ( !_Pred(a1: _Bottoma, a2: _Val) )
      break;
    _First[v6] = *_Bottoma;
    v6 = i;
  }
  _First[v6] = *_Val;
}

//------------------------------------------------------------------------------
// Address: 0x1004D500
// Name: void std::_Adjust_heap<struct ShadowMeshRenderData_t __near *,int,struct ShadowMeshRenderData_t,bool (*)(struct ShadowMeshRenderData_t const __near &,struct ShadowMeshRenderData_t const __near &)>(struct ShadowMeshRenderData_t __near *,int,int,struct ShadowMeshRenderData_t __near &&,bool (*)(struct ShadowMeshRenderData_t const __near &,struct ShadowMeshRenderData_t const __near &))
// Source: json
//------------------------------------------------------------------------------
void __cdecl std::_Adjust_heap<ShadowMeshRenderData_t *,int,ShadowMeshRenderData_t,bool (__cdecl *)(ShadowMeshRenderData_t const &,ShadowMeshRenderData_t const &)>(
        ShadowMeshRenderData_t *_First,
        int _Hole,
        int _Bottom,
        ShadowMeshRenderData_t *_Val,
        bool (__cdecl *_Pred)(const ShadowMeshRenderData_t *, const ShadowMeshRenderData_t *))
{
  int v5; // edx
  int v6; // ebx
  int v7; // esi
  bool v8; // zf
  ShadowMeshRenderData_t *v9; // eax
  ShadowMeshRenderData_t *v10; // ecx
  ShadowMeshRenderData_t *v11; // ecx
  int v12; // ecx
  int v13; // ebx
  ShadowMeshRenderData_t *v14; // esi
  ShadowMeshRenderData_t *v15; // eax
  int _Top; // [esp+Ch] [ebp-4h]
  int _Bottoma; // [esp+20h] [ebp+10h]

  v5 = _Bottom;
  v6 = _Hole;
  v7 = 2 * _Hole + 2;
  _Top = _Hole;
  v8 = v7 == _Bottom;
  if ( v7 < _Bottom )
  {
    do
    {
      if ( _Pred(a1: &_First[v7], a2: &_First[v7 - 1]) )
        --v7;
      v9 = &_First[v7];
      v10 = &_First[v6];
      *(_QWORD *)&v10->m_pGroup = *(_QWORD *)&v9->m_pGroup;
      *(_QWORD *)&v10->m_pMaterial = *(_QWORD *)&v9->m_pMaterial;
      _Hole = v7;
      v6 = v7;
      *(_QWORD *)&v10->m_pSrcMaterial = *(_QWORD *)&v9->m_pSrcMaterial;
      v7 = 2 * v7 + 2;
      *(_QWORD *)&v10->m_nMeshBoneCount = *(_QWORD *)&v9->m_nMeshBoneCount;
    }
    while ( v7 < _Bottom );
    v5 = _Bottom;
    v8 = v7 == _Bottom;
  }
  if ( v8 )
  {
    v11 = &_First[v5 - 1];
    _First[v6] = *v11;
    _Hole = v5 - 1;
    v6 = v5 - 1;
  }
  v12 = v6;
  _Bottoma = v6;
  v13 = (v6 - 1) / 2;
  if ( _Top < _Hole )
  {
    do
    {
      v14 = &_First[v13];
      if ( !_Pred(a1: v14, a2: _Val) )
        break;
      v15 = &_First[_Bottoma];
      *(_QWORD *)&v15->m_pGroup = *(_QWORD *)&v14->m_pGroup;
      *(_QWORD *)&v15->m_pMaterial = *(_QWORD *)&v14->m_pMaterial;
      *(_QWORD *)&v15->m_pSrcMaterial = *(_QWORD *)&v14->m_pSrcMaterial;
      *(_QWORD *)&v15->m_nMeshBoneCount = *(_QWORD *)&v14->m_nMeshBoneCount;
      _Bottoma = v13;
      v13 = (v13 - 1) / 2;
    }
    while ( _Top < _Bottoma );
    v12 = _Bottoma;
  }
  _First[v12] = *_Val;
}

//------------------------------------------------------------------------------
// Address: 0x1004D670
// Name: public: void CUtlMemory<struct IStudioRender::FacesRenderedInfo_t,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<IStudioRender::FacesRenderedInfo_t,int>::Grow(
        CUtlMemory<IStudioRender::FacesRenderedInfo_t,int> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  IStudioRender::FacesRenderedInfo_t *m_pMemory; // ecx

  m_nGrowSize = this->m_nGrowSize;
  if ( m_nGrowSize >= 0 )
  {
    m_nAllocationCount = this->m_nAllocationCount;
    v5 = m_nAllocationCount + num;
    if ( m_nGrowSize != 0 )
    {
      m_nAllocationCount = m_nGrowSize * ((v5 - 1) / m_nGrowSize + 1);
    }
    else
    {
      if ( m_nAllocationCount == 0 )
        m_nAllocationCount = 3;
      if ( m_nAllocationCount >= v5 )
        goto LABEL_13;
      do
        m_nAllocationCount *= 2;
      while ( m_nAllocationCount < v5 );
    }
    if ( m_nAllocationCount < v5 )
    {
      if ( m_nAllocationCount != 0 || v5 > -1 )
      {
        do
          m_nAllocationCount = (v5 + m_nAllocationCount) / 2;
        while ( m_nAllocationCount < v5 );
      }
      else
      {
        m_nAllocationCount = -1;
      }
    }
LABEL_13:
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (IStudioRender::FacesRenderedInfo_t *)_realloc_crt(
                                                                ptr: m_pMemory,
                                                                size: 12 * m_nAllocationCount);
    else
      this->m_pMemory = (IStudioRender::FacesRenderedInfo_t *)operator new(nSize: 12 * m_nAllocationCount);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004D710
// Name: private: void CStudioRender::SetLightingRenderState(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CStudioRender::SetLightingRenderState(CStudioRender *this)
{
  IMatRenderContext *v2; // esi
  StudioRenderContext_t *m_pRC; // eax
  IMatRenderContext_vtbl *v4; // edx

  v2 = g_pMaterialSystem->GetRenderContext(this: g_pMaterialSystem);
  if ( v2 != nullptr )
    v2->BeginRender(this: v2);
  v2->SetAmbientLightCube(this: v2, a2: this->m_pRC->m_LightBoxColors);
  m_pRC = this->m_pRC;
  v4 = v2->__vftable;
  if ( (*((_BYTE *)&m_pRC->m_Config.StudioRenderConfig_t + 37) & 8) != 0 )
    v4->DisableAllLocalLights(this: v2);
  else
    v4->SetLights(this: v2, a2: m_pRC->m_NumLocalLights, a3: m_pRC->m_LocalLights);
  v2->EndRender(this: v2);
  v2->Release(this: v2);
}

//------------------------------------------------------------------------------
// Address: 0x1004D790
// Name: public: void CStudioRender::DrawModel(struct DrawModelInfo_t const __near &,struct StudioRenderContext_t const __near &,struct matrix3x4_t __near *,struct FlexWeights_t const __near &,int)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CStudioRender::DrawModel(
        CStudioRender *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>,
        int info,
        StudioRenderContext_t *rc,
        matrix3x4_t *pBoneToWorld,
        const FlexWeights_t *flex,
        int flags)
{
  float *m_pFlexDelayedWeights; // edx
  int v10; // eax
  IMatRenderContext *v11; // edi
  StudioRenderContext_t *m_pRC; // ecx
  StudioRenderContext_t *v13; // ecx
  studiohdr_t *m_pStudioHdr; // ecx
  matrix3x4_t *m_PoseToWorld; // edx
  studioloddata_t *v17; // ecx
  __int16 v18; // ax
  int v19; // ecx
  Vector *p_m_ViewOrigin; // [esp-8h] [ebp-10h]
  int boneMask; // [esp+10h] [ebp+8h]
  char flexConfig_3; // [esp+17h] [ebp+Fh]
  matrix3x4_t *pBoneToWorlda; // [esp+18h] [ebp+10h]
  char bWireframe_3; // [esp+1Fh] [ebp+17h]

  if ( cl_skipslowpath.m_pParent == nullptr || cl_skipslowpath.m_pParent->m_Value.m_nValue == 0 )
  {
    this->m_pRC = rc;
    this->m_pFlexWeights = flex->m_pFlexWeights;
    m_pFlexDelayedWeights = flex->m_pFlexDelayedWeights;
    this->m_pBoneToWorld = pBoneToWorld;
    this->m_pFlexDelayedWeights = m_pFlexDelayedWeights;
    v10 = ((int (__thiscall *)(IMaterialSystem *, int, int))g_pMaterialSystem->GetRenderContext)(
            a1: g_pMaterialSystem,
            a2: a3,
            a3: a2);
    v11 = (IMatRenderContext *)v10;
    if ( v10 != 0 )
      (*(void (__thiscall **)(int))(*(_DWORD *)v10 + 8))(a1: v10);
    m_pRC = this->m_pRC;
    flexConfig_3 = (*((_BYTE *)&m_pRC->m_Config.StudioRenderConfig_t + 36) & 0x40) != 0;
    if ( (flags & 4) != 0 )
      *((_BYTE *)&m_pRC->m_Config.StudioRenderConfig_t + 36) &= ~0x40u;
    v13 = this->m_pRC;
    bWireframe_3 = *((_BYTE *)&v13->m_Config.StudioRenderConfig_t + 36) >> 7;
    if ( (flags & 0x80u) != 0 )
      *((_BYTE *)&v13->m_Config.StudioRenderConfig_t + 36) |= 0x80u;
    boneMask = 1024 << *(_DWORD *)(info + 28);
    v11->MatrixMode(this: v11, a2: MATERIAL_MODEL);
    v11->PushMatrix(this: v11);
    v11->LoadIdentity(this: v11);
    CCachedRenderData::StartModel(this: &this->m_VertexCache);
    this->m_pStudioHdr = *(studiohdr_t **)info;
    this->m_pStudioMeshes = *(studiomeshdata_t **)(32 * *(_DWORD *)(info + 28) + *(_DWORD *)(*(_DWORD *)(info + 4) + 8));
    m_pStudioHdr = this->m_pStudioHdr;
    p_m_ViewOrigin = &this->m_pRC->m_ViewOrigin;
    m_PoseToWorld = this->m_PoseToWorld;
    this->m_pStudioHWData = *(studiohwdata_t **)(info + 4);
    ComputePoseToWorld(
      pPoseToWorld: m_PoseToWorld,
      pStudioHdr: m_pStudioHdr,
      boneMask,
      vecViewOrigin: p_m_ViewOrigin,
      pBoneToWorld);
    v11->IsCullingEnabledForSinglePassFlashlight(this: v11);
    v17 = (studioloddata_t *)(32 * *(_DWORD *)(info + 28) + *(_DWORD *)(*(_DWORD *)(info + 4) + 8));
    CStudioRender::R_StudioRenderModel(
      this,
      pRenderContext: v11,
      skin: *(_DWORD *)(info + 12),
      body: *(_DWORD *)(info + 16),
      hitboxset: *(_DWORD *)(info + 20),
      pEntity: *(void **)(info + 24),
      ppMaterials: v17->ppMaterials,
      pMaterialFlags: v17->pMaterialFlags,
      flags,
      boneMask,
      lod: *(_DWORD *)(info + 28),
      pColorMeshes: *(ColorMeshInfo_t **)(info + 32));
    v11->IsCullingEnabledForSinglePassFlashlight(this: v11);
    if ( this->m_pStudioMeshes != nullptr )
    {
      v18 = flags;
      if ( (flags & 0x200) == 0 )
      {
        if ( (flags & 0x20) == 0 )
        {
          CStudioRender::DrawShadows(this, (const DrawModelInfo_t *)info, flags, boneMask);
          v18 = flags;
        }
        v19 = v18 & 3;
        pBoneToWorlda = (matrix3x4_t *)v19;
        if ( v19 != 2 )
        {
          if ( (v18 & 0x800) == 0 )
          {
            CStudioRender::DrawDecal(
              this,
              a2: (int)this,
              drawInfo: (const DrawModelInfo_t *)info,
              lod: *(_DWORD *)(info + 28),
              body: *(_DWORD *)(info + 16));
            v19 = (int)pBoneToWorlda;
            v18 = flags;
          }
          if ( v19 != 2 && (flags & 0x20) == 0 && (v18 & 0x800) == 0 )
            CStudioRender::DrawFlashlightDecals(this, (const DrawModelInfo_t *)info, lod: *(_DWORD *)(info + 28));
        }
      }
    }
    v11->MatrixMode(this: v11, a2: MATERIAL_MODEL);
    v11->PopMatrix(this: v11);
    *((_BYTE *)&this->m_pRC->m_Config.StudioRenderConfig_t + 36) ^= (*((_BYTE *)&this->m_pRC->m_Config.StudioRenderConfig_t
                                                                     + 36)
                                                                   ^ (flexConfig_3 << 6))
                                                                  & 0x40;
    *((_BYTE *)&this->m_pRC->m_Config.StudioRenderConfig_t + 36) = (bWireframe_3 << 7)
                                                                 | *((_BYTE *)&this->m_pRC->m_Config.StudioRenderConfig_t
                                                                   + 36)
                                                                 & 0x7F;
    v11->SetNumBoneWeights(this: v11, a2: 0);
    this->m_pRC = nullptr;
    this->m_pBoneToWorld = nullptr;
    this->m_pFlexWeights = nullptr;
    this->m_pFlexDelayedWeights = nullptr;
    this->m_pStudioHdr = nullptr;
    this->m_pStudioMeshes = nullptr;
    this->m_pStudioHWData = nullptr;
    v11->EndRender(this: v11);
    v11->Release(this: v11);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004DA00
// Name: public: void CStudioRender::DrawModelStaticProp(struct DrawModelInfo_t const __near &,struct StudioRenderContext_t const __near &,struct matrix3x4_t const __near &,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CStudioRender::DrawModelStaticProp(
        CStudioRender *this,
        const DrawModelInfo_t *info,
        StudioRenderContext_t *rc,
        const matrix3x4_t *rootToWorld,
        int flags)
{
  IMatRenderContext *v6; // eax
  matrix3x4_t *m_PoseToWorld; // edx
  StudioRenderContext_t *m_pRC; // ecx
  char v9; // bl
  StudioRenderContext_t *v10; // ecx
  char v11; // bl
  int m_Lod; // ecx
  studioloddata_t *v14; // eax
  __int16 v15; // ax
  int v16; // ecx
  IMatRenderContext *v17; // edi
  IMatRenderContext *pRenderContext; // [esp+8h] [ebp-4h]
  const DrawModelInfo_t *infoa; // [esp+14h] [ebp+8h]
  char bWireframe_3; // [esp+1Bh] [ebp+Fh]
  int lod; // [esp+1Ch] [ebp+10h]

  if ( cl_skipslowpath.m_pParent == nullptr || cl_skipslowpath.m_pParent->m_Value.m_nValue == 0 )
  {
    this->m_pRC = rc;
    v6 = g_pMaterialSystem->GetRenderContext(this: g_pMaterialSystem);
    pRenderContext = v6;
    if ( v6 != nullptr )
      v6->BeginRender(this: v6);
    m_PoseToWorld = this->m_PoseToWorld;
    this->m_StaticPropRootToWorld = *rootToWorld;
    *m_PoseToWorld = *rootToWorld;
    this->m_pBoneToWorld = &this->m_StaticPropRootToWorld;
    m_pRC = this->m_pRC;
    v9 = *((_BYTE *)&m_pRC->m_Config.StudioRenderConfig_t + 36);
    *((_BYTE *)&m_pRC->m_Config.StudioRenderConfig_t + 36) = v9 & 0xBF;
    v10 = this->m_pRC;
    v11 = (v9 & 0x40) != 0;
    bWireframe_3 = *((_BYTE *)&v10->m_Config.StudioRenderConfig_t + 36) >> 7;
    if ( (flags & 0x80u) != 0 )
      *((_BYTE *)&v10->m_Config.StudioRenderConfig_t + 36) |= 0x80u;
    m_Lod = info->m_Lod;
    this->m_pStudioHdr = info->m_pStudioHdr;
    this->m_pStudioMeshes = info->m_pHardwareData->m_pLODs[m_Lod].m_pMeshData;
    this->m_pStudioHWData = info->m_pHardwareData;
    v14 = &info->m_pHardwareData->m_pLODs[m_Lod];
    lod = m_Lod;
    CStudioRender::R_StudioRenderModel(
      this,
      pRenderContext,
      skin: info->m_Skin,
      body: info->m_Body,
      hitboxset: info->m_HitboxSet,
      pEntity: info->m_pClientEntity,
      ppMaterials: v14->ppMaterials,
      pMaterialFlags: v14->pMaterialFlags,
      flags,
      boneMask: 524032,
      lod: m_Lod,
      pColorMeshes: info->m_pColorMeshes);
    v15 = flags;
    if ( (flags & 0x200) == 0 )
    {
      if ( (flags & 0x20) == 0 )
      {
        CStudioRender::DrawShadows(this, info, flags, boneMask: 524032);
        v15 = flags;
      }
      v16 = v15 & 3;
      infoa = (const DrawModelInfo_t *)v16;
      if ( v16 != 2 )
      {
        if ( (v15 & 0x800) == 0 )
        {
          CStudioRender::DrawDecal(this, a2: (int)this, drawInfo: info, lod, body: info->m_Body);
          v16 = (int)infoa;
          v15 = flags;
        }
        if ( v16 != 2 && (flags & 0x20) == 0 && (v15 & 0x800) == 0 )
          CStudioRender::DrawFlashlightDecals(this, info, lod);
      }
    }
    v17 = pRenderContext;
    *((_BYTE *)&this->m_pRC->m_Config.StudioRenderConfig_t + 36) ^= (*((_BYTE *)&this->m_pRC->m_Config.StudioRenderConfig_t
                                                                     + 36)
                                                                   ^ (v11 << 6))
                                                                  & 0x40;
    *((_BYTE *)&this->m_pRC->m_Config.StudioRenderConfig_t + 36) = *((_BYTE *)&this->m_pRC->m_Config.StudioRenderConfig_t
                                                                   + 36)
                                                                 & 0x7F
                                                                 | (bWireframe_3 << 7);
    pRenderContext->SetNumBoneWeights(this: pRenderContext, a2: 0);
    this->m_pBoneToWorld = nullptr;
    this->m_pRC = nullptr;
    this->m_pStudioHdr = nullptr;
    this->m_pStudioMeshes = nullptr;
    this->m_pStudioHWData = nullptr;
    v17->EndRender(this: v17);
    v17->Release(this: v17);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004DC40
// Name: void std::_Make_heap<struct MeshRenderData2_t __near *,int,struct MeshRenderData2_t,bool (*)(struct MeshRenderData2_t const __near &,struct MeshRenderData2_t const __near &)>(struct MeshRenderData2_t __near *,struct MeshRenderData2_t __near *,bool (*)(struct MeshRenderData2_t const __near &,struct MeshRenderData2_t const __near &),int __near *,struct MeshRenderData2_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl std::_Make_heap<MeshRenderData2_t *,int,MeshRenderData2_t,bool (__cdecl *)(MeshRenderData2_t const &,MeshRenderData2_t const &)>(
        MeshRenderData2_t *_First,
        MeshRenderData2_t *_Last,
        bool (__cdecl *_Pred)(const MeshRenderData2_t *, const MeshRenderData2_t *))
{
  int v4; // ecx
  int v5; // eax
  int v6; // esi
  MeshRenderData2_t *v7; // edx
  __int64 v8; // xmm0_8
  MeshRenderData2_t *v9; // edx
  int v10; // eax
  int v11; // esi
  __int64 v12; // xmm0_8
  int v13; // edx
  int v14; // edi
  bool v15; // zf
  MeshRenderData2_t *v16; // eax
  MeshRenderData2_t *v17; // ecx
  MeshRenderData2_t *v18; // edx
  MeshRenderData2_t *v19; // esi
  MeshRenderData2_t _Val; // [esp+4h] [ebp-1Ch] BYREF
  int v21; // [esp+18h] [ebp-8h]
  MeshRenderData2_t *v22; // [esp+1Ch] [ebp-4h]
  int _Hole; // [esp+28h] [ebp+8h]
  int _Bottom; // [esp+2Ch] [ebp+Ch]

  v4 = _Last - _First;
  v5 = v4 / 2;
  _Bottom = v4;
  if ( v4 / 2 > 0 )
  {
    v6 = 2 * v5 + 2;
    v7 = &_First[v5];
    while ( 1 )
    {
      v8 = *(_QWORD *)&v7[-1].m_pGroup;
      v9 = v7 - 1;
      v10 = v5 - 1;
      v11 = v6 - 2;
      *(_QWORD *)&_Val.m_pGroup = v8;
      v12 = *(_QWORD *)&v9->m_pMaterial;
      v22 = v9;
      v13 = *(_DWORD *)&v9->m_nCompressionType;
      _Hole = v10;
      v21 = v11;
      *(_QWORD *)&_Val.m_pMaterial = v12;
      *(_DWORD *)&_Val.m_nCompressionType = v13;
      v14 = v10;
      v15 = v11 == v4;
      if ( v11 < v4 )
      {
        do
        {
          if ( _Pred(a1: &_First[v11], a2: &_First[v11 - 1]) )
            --v11;
          v16 = &_First[v11];
          v17 = &_First[v14];
          *(_QWORD *)&v17->m_pGroup = *(_QWORD *)&v16->m_pGroup;
          *(_QWORD *)&v17->m_pMaterial = *(_QWORD *)&v16->m_pMaterial;
          v14 = v11;
          v11 = 2 * v11 + 2;
          *(_DWORD *)&v17->m_nCompressionType = *(_DWORD *)&v16->m_nCompressionType;
        }
        while ( v11 < _Bottom );
        v4 = _Bottom;
        v10 = _Hole;
        v15 = v11 == _Bottom;
      }
      if ( v15 )
      {
        v18 = &_First[v4 - 1];
        v19 = &_First[v14];
        *(_QWORD *)&v19->m_pGroup = *(_QWORD *)&v18->m_pGroup;
        *(_QWORD *)&v19->m_pMaterial = *(_QWORD *)&v18->m_pMaterial;
        *(_DWORD *)&v19->m_nCompressionType = *(_DWORD *)&v18->m_nCompressionType;
        v14 = v4 - 1;
      }
      std::_Push_heap<MeshRenderData2_t *,int,MeshRenderData2_t,bool (__cdecl *)(MeshRenderData2_t const &,MeshRenderData2_t const &)>(
        _First,
        _Hole: v14,
        _Top: v10,
        &_Val,
        _Pred);
      if ( _Hole <= 0 )
        break;
      v5 = _Hole;
      v4 = _Bottom;
      v7 = v22;
      v6 = v21;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004DD60
// Name: void std::_Make_heap<struct CStudioRender::DecalRenderData_t __near *,int,struct CStudioRender::DecalRenderData_t,bool (*)(struct CStudioRender::DecalRenderData_t const __near &,struct CStudioRender::DecalRenderData_t const __near &)>(struct CStudioRender::DecalRenderData_t __near *,struct CStudioRender::DecalRenderData_t __near *,bool (*)(struct CStudioRender::DecalRenderData_t const __near &,struct CStudioRender::DecalRenderData_t const __near &),int __near *,struct CStudioRender::DecalRenderData_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl std::_Make_heap<CStudioRender::DecalRenderData_t *,int,CStudioRender::DecalRenderData_t,bool (__cdecl *)(CStudioRender::DecalRenderData_t const &,CStudioRender::DecalRenderData_t const &)>(
        CStudioRender::DecalRenderData_t *_First,
        CStudioRender::DecalRenderData_t *_Last,
        bool (__cdecl *_Pred)(const CStudioRender::DecalRenderData_t *, const CStudioRender::DecalRenderData_t *))
{
  int v4; // ecx
  int v5; // eax
  int v6; // esi
  CStudioRender::DecalRenderData_t *i; // edx
  __int64 v8; // xmm0_8
  CStudioRender::DecalRenderData_t *v9; // edx
  int v10; // eax
  int v11; // esi
  __int64 v12; // xmm0_8
  int v13; // ebx
  bool v14; // zf
  int v15; // ecx
  __int64 v16; // xmm0_8
  int v17; // ebx
  CStudioRender::DecalRenderData_t _Val; // [esp+4h] [ebp-18h] BYREF
  int v19; // [esp+14h] [ebp-8h]
  CStudioRender::DecalRenderData_t *v20; // [esp+18h] [ebp-4h]
  int _Hole; // [esp+24h] [ebp+8h]
  int _Bottom; // [esp+28h] [ebp+Ch]

  v4 = _Last - _First;
  v5 = v4 / 2;
  _Bottom = v4;
  if ( v4 / 2 > 0 )
  {
    v6 = 2 * v5 + 2;
    for ( i = &_First[v5]; ; i = v20 )
    {
      v8 = *(_QWORD *)&i[-1].m_pDecalMaterial;
      v9 = i - 1;
      v10 = v5 - 1;
      v11 = v6 - 2;
      *(_QWORD *)&_Val.m_pDecalMaterial = v8;
      v12 = *(_QWORD *)&v9->m_pRenderMaterial;
      _Hole = v10;
      v20 = v9;
      v19 = v11;
      *(_QWORD *)&_Val.m_pRenderMaterial = v12;
      v13 = v10;
      v14 = v11 == v4;
      if ( v11 < v4 )
      {
        do
        {
          if ( _Pred(a1: &_First[v11], a2: &_First[v11 - 1]) )
            --v11;
          v15 = v13;
          v13 = v11;
          *(_QWORD *)&_First[v15].m_pDecalMaterial = *(_QWORD *)&_First[v11].m_pDecalMaterial;
          v16 = *(_QWORD *)&_First[v11].m_pRenderMaterial;
          v11 = 2 * v11 + 2;
          *(_QWORD *)&_First[v15].m_pRenderMaterial = v16;
        }
        while ( v11 < _Bottom );
        v4 = _Bottom;
        v10 = _Hole;
        v14 = v11 == _Bottom;
      }
      if ( v14 )
      {
        v17 = v13;
        *(_QWORD *)&_First[v17].m_pDecalMaterial = *(_QWORD *)&_First[v4 - 1].m_pDecalMaterial;
        *(_QWORD *)&_First[v17].m_pRenderMaterial = *(_QWORD *)&_First[v4 - 1].m_pRenderMaterial;
        v13 = v4 - 1;
      }
      std::_Push_heap<CStudioRender::DecalRenderData_t *,int,CStudioRender::DecalRenderData_t,bool (__cdecl *)(CStudioRender::DecalRenderData_t const &,CStudioRender::DecalRenderData_t const &)>(
        _First,
        _Hole: v13,
        _Top: v10,
        &_Val,
        _Pred);
      if ( _Hole <= 0 )
        break;
      v5 = _Hole;
      v4 = _Bottom;
      v6 = v19;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004DE70
// Name: void std::_Make_heap<struct ShadowMeshRenderData_t __near *,int,struct ShadowMeshRenderData_t,bool (*)(struct ShadowMeshRenderData_t const __near &,struct ShadowMeshRenderData_t const __near &)>(struct ShadowMeshRenderData_t __near *,struct ShadowMeshRenderData_t __near *,bool (*)(struct ShadowMeshRenderData_t const __near &,struct ShadowMeshRenderData_t const __near &),int __near *,struct ShadowMeshRenderData_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl std::_Make_heap<ShadowMeshRenderData_t *,int,ShadowMeshRenderData_t,bool (__cdecl *)(ShadowMeshRenderData_t const &,ShadowMeshRenderData_t const &)>(
        ShadowMeshRenderData_t *_First,
        ShadowMeshRenderData_t *_Last,
        bool (__cdecl *_Pred)(const ShadowMeshRenderData_t *, const ShadowMeshRenderData_t *))
{
  int v4; // ecx
  int v5; // eax
  int v6; // esi
  ShadowMeshRenderData_t *i; // edx
  __int64 v8; // xmm0_8
  ShadowMeshRenderData_t *v9; // edx
  int v10; // eax
  int v11; // esi
  __int64 v12; // xmm0_8
  int v13; // ebx
  bool v14; // zf
  ShadowMeshRenderData_t *v15; // eax
  ShadowMeshRenderData_t *v16; // ecx
  ShadowMeshRenderData_t *v17; // edx
  ShadowMeshRenderData_t *v18; // ebx
  ShadowMeshRenderData_t _Val; // [esp+4h] [ebp-28h] BYREF
  int v20; // [esp+24h] [ebp-8h]
  ShadowMeshRenderData_t *v21; // [esp+28h] [ebp-4h]
  int _Hole; // [esp+34h] [ebp+8h]
  int _Bottom; // [esp+38h] [ebp+Ch]

  v4 = _Last - _First;
  v5 = v4 / 2;
  _Bottom = v4;
  if ( v4 / 2 > 0 )
  {
    v6 = 2 * v5 + 2;
    for ( i = &_First[v5]; ; i = v21 )
    {
      v8 = *(_QWORD *)&i[-1].m_pGroup;
      v9 = i - 1;
      *(_QWORD *)&_Val.m_pGroup = v8;
      *(_QWORD *)&_Val.m_pMaterial = *(_QWORD *)&v9->m_pMaterial;
      v10 = v5 - 1;
      v11 = v6 - 2;
      *(_QWORD *)&_Val.m_pSrcMaterial = *(_QWORD *)&v9->m_pSrcMaterial;
      v12 = *(_QWORD *)&v9->m_nMeshBoneCount;
      _Hole = v10;
      v21 = v9;
      v20 = v11;
      *(_QWORD *)&_Val.m_nMeshBoneCount = v12;
      v13 = v10;
      v14 = v11 == v4;
      if ( v11 < v4 )
      {
        do
        {
          if ( _Pred(a1: &_First[v11], a2: &_First[v11 - 1]) )
            --v11;
          v15 = &_First[v11];
          v16 = &_First[v13];
          *(_QWORD *)&v16->m_pGroup = *(_QWORD *)&v15->m_pGroup;
          *(_QWORD *)&v16->m_pMaterial = *(_QWORD *)&v15->m_pMaterial;
          v13 = v11;
          *(_QWORD *)&v16->m_pSrcMaterial = *(_QWORD *)&v15->m_pSrcMaterial;
          v11 = 2 * v11 + 2;
          *(_QWORD *)&v16->m_nMeshBoneCount = *(_QWORD *)&v15->m_nMeshBoneCount;
        }
        while ( v11 < _Bottom );
        v4 = _Bottom;
        v10 = _Hole;
        v14 = v11 == _Bottom;
      }
      if ( v14 )
      {
        v17 = &_First[v4 - 1];
        v18 = &_First[v13];
        *(_QWORD *)&v18->m_pGroup = *(_QWORD *)&v17->m_pGroup;
        *(_QWORD *)&v18->m_pMaterial = *(_QWORD *)&v17->m_pMaterial;
        *(_QWORD *)&v18->m_pSrcMaterial = *(_QWORD *)&v17->m_pSrcMaterial;
        *(_QWORD *)&v18->m_nMeshBoneCount = *(_QWORD *)&v17->m_nMeshBoneCount;
        v13 = v4 - 1;
      }
      std::_Push_heap<ShadowMeshRenderData_t *,int,ShadowMeshRenderData_t,bool (__cdecl *)(ShadowMeshRenderData_t const &,ShadowMeshRenderData_t const &)>(
        _First,
        _Hole: v13,
        _Top: v10,
        &_Val,
        _Pred);
      if ( _Hole <= 0 )
        break;
      v5 = _Hole;
      v4 = _Bottom;
      v6 = v20;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004DFB0
// Name: protected: bool CUtlHash<struct IStudioRender::FacesRenderedInfo_t,bool (*)(struct IStudioRender::FacesRenderedInfo_t const __near &,struct IStudioRender::FacesRenderedInfo_t const __near &),unsigned int (*)(struct IStudioRender::FacesRenderedInfo_t const __near &)>::DoFind(struct IStudioRender::FacesRenderedInfo_t const __near &,unsigned int __near *,int __near *)const
// Source: json
//------------------------------------------------------------------------------
char __thiscall CUtlHash<IStudioRender::FacesRenderedInfo_t,bool (__cdecl *)(IStudioRender::FacesRenderedInfo_t const &,IStudioRender::FacesRenderedInfo_t const &),unsigned int (__cdecl *)(IStudioRender::FacesRenderedInfo_t const &)>::DoFind(
        CUtlHash<IStudioRender::FacesRenderedInfo_t,bool (__cdecl*)(IStudioRender::FacesRenderedInfo_t const &,IStudioRender::FacesRenderedInfo_t const &),unsigned int (__cdecl*)(IStudioRender::FacesRenderedInfo_t const &)> *this,
        const IStudioRender::FacesRenderedInfo_t *src,
        unsigned int *pBucket,
        int *pIndex)
{
  unsigned int v5; // eax
  unsigned int v6; // edx
  unsigned int v7; // edx
  int m_Size; // ecx
  CUtlVector<IStudioRender::FacesRenderedInfo_t,CUtlMemory<IStudioRender::FacesRenderedInfo_t,int> > *v9; // eax
  int v10; // edi
  int v11; // ebx
  const CUtlVector<IStudioRender::FacesRenderedInfo_t,CUtlMemory<IStudioRender::FacesRenderedInfo_t,int> > *bucket; // [esp+8h] [ebp-4h]
  int keyDataCount; // [esp+18h] [ebp+Ch]

  v5 = this->m_KeyFunc(a1: src);
  if ( this->m_bPowerOfTwo )
    v6 = v5 & this->m_ModMask;
  else
    v6 = v5 % this->m_Buckets.m_Size;
  *pBucket = v6;
  v7 = v6;
  m_Size = this->m_Buckets.m_Memory.m_pMemory[v7].m_Size;
  v9 = &this->m_Buckets.m_Memory.m_pMemory[v7];
  v10 = 0;
  bucket = v9;
  keyDataCount = m_Size;
  if ( m_Size > 0 )
  {
    v11 = 0;
    while ( !this->m_CompareFunc(a1: &v9->m_Memory.m_pMemory[v11], a2: src) )
    {
      ++v10;
      ++v11;
      if ( v10 >= keyDataCount )
        break;
      v9 = (CUtlVector<IStudioRender::FacesRenderedInfo_t,CUtlMemory<IStudioRender::FacesRenderedInfo_t,int> > *)bucket;
    }
    m_Size = keyDataCount;
  }
  if ( v10 == m_Size )
    return 0;
  *pIndex = v10;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1004E050
// Name: public: void CStudioRender::BeginFrame(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CStudioRender::BeginFrame(CStudioRender *this)
{
  int m_Size; // esi
  int v2; // edx

  if ( mat_rendered_faces_count_0.m_pParent != nullptr && mat_rendered_faces_count_0.m_pParent->m_Value.m_nValue != 0
    || mat_print_top_model_vert_counts_0.m_pParent != nullptr
    && mat_print_top_model_vert_counts_0.m_pParent->m_Value.m_nValue != 0 )
  {
    m_Size = this->m_ModelFaceCountHash.m_Buckets.m_Size;
    if ( m_Size > 0 )
    {
      v2 = 0;
      do
      {
        this->m_ModelFaceCountHash.m_Buckets.m_Memory.m_pMemory[v2++].m_Size = 0;
        --m_Size;
      }
      while ( m_Size != 0 );
    }
  }
  CStudioRender::PrecacheGlint(this);
}

//------------------------------------------------------------------------------
// Address: 0x1004E0A0
// Name: public: void CStudioRender::ClearAllShadows(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CStudioRender::ClearAllShadows(CStudioRender *this)
{
  this->m_ShadowState.m_Size = 0;
}

//------------------------------------------------------------------------------
// Address: 0x1004E0B0
// Name: private: int CStudioRender::CountDecalMeshesToDraw(int,struct StudioArrayInstanceData_t __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CStudioRender::CountDecalMeshesToDraw(
        CStudioRender *this,
        int nCount,
        StudioArrayInstanceData_t *pInstanceData,
        int nInstanceStride)
{
  int result; // eax
  int i; // ebx
  StudioDecalHandle_t__ *m_Decals; // edx
  unsigned __int16 j; // dx

  result = 0;
  if ( nCount > 0 )
  {
    for ( i = nCount; i != 0; --i )
    {
      m_Decals = pInstanceData->m_Decals;
      if ( m_Decals != nullptr )
      {
        for ( j = *(_WORD *)(32 * pInstanceData->m_nLOD + *((_DWORD *)m_Decals + 1)); j != 0xFFFF; ++result )
          j = this->m_DecalMaterial.m_Memory.m_pMemory[j].m_Next;
      }
      pInstanceData = (StudioArrayInstanceData_t *)((char *)pInstanceData + nInstanceStride);
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1004E180
// Name: public: void CUtlLinkedList<struct CStudioRender::DecalLRU_t,int,1,int,class CUtlFixedMemory<struct UtlLinkedListElem_t<struct CStudioRender::DecalLRU_t,int>>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CStudioRender::DecalLRU_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CStudioRender::DecalLRU_t,int>>>::RemoveAll(
        CUtlLinkedList<CStudioRender::DecalLRU_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CStudioRender::DecalLRU_t,int> > > *this)
{
  CUtlFixedMemory<UtlLinkedListElem_t<CStudioRender::DecalModelList_t,int> > *v1; // esi
  CUtlFixedMemory<UtlLinkedListElem_t<CStudioRender::DecalModelList_t,int> >::Iterator_t *i; // eax
  CUtlFixedMemory<UtlLinkedListElem_t<CStudioRender::DecalLRU_t,int> >::BlockHeader_t *m_pBlockHeader; // edi
  int m_nIndex; // ebx
  CUtlFixedMemory<UtlLinkedListElem_t<CStudioRender::DecalLRU_t,int> > *v5; // eax
  CUtlFixedMemory<UtlLinkedListElem_t<CStudioRender::DecalModelList_t,int> >::Iterator_t result; // [esp+4h] [ebp-14h] BYREF
  CUtlFixedMemory<UtlLinkedListElem_t<CStudioRender::DecalLRU_t,int> >::Iterator_t it; // [esp+Ch] [ebp-Ch] BYREF
  CUtlFixedMemory<UtlLinkedListElem_t<CStudioRender::DecalLRU_t,int> > *p_m_Memory; // [esp+14h] [ebp-4h]

  v1 = (CUtlFixedMemory<UtlLinkedListElem_t<CStudioRender::DecalModelList_t,int> > *)this;
  p_m_Memory = &this->m_Memory;
  if ( this->m_LastAlloc.m_pBlockHeader != nullptr || this->m_LastAlloc.m_nIndex != -1 )
  {
    if ( this->m_Memory.m_pBlocks != nullptr )
    {
      result.m_pBlockHeader = (CUtlFixedMemory<UtlLinkedListElem_t<CStudioRender::DecalModelList_t,int> >::BlockHeader_t *)this->m_Memory.m_pBlocks;
      result.m_nIndex = 0;
    }
    else
    {
      result.m_pBlockHeader = nullptr;
      result.m_nIndex = -1;
    }
    for ( i = &result;
          ;
          i = CUtlFixedMemory<UtlLinkedListElem_t<CStudioRender::DecalLRU_t,int>>::Next(
                this: v1,
                &result,
                (const CUtlFixedMemory<UtlLinkedListElem_t<CStudioRender::DecalModelList_t,int> >::Iterator_t *)&it) )
    {
      m_pBlockHeader = (CUtlFixedMemory<UtlLinkedListElem_t<CStudioRender::DecalLRU_t,int> >::BlockHeader_t *)i->m_pBlockHeader;
      m_nIndex = i->m_nIndex;
      it.m_nIndex = m_nIndex;
      it.m_pBlockHeader = m_pBlockHeader;
      if ( m_pBlockHeader != nullptr )
      {
        if ( m_nIndex >= 0 && m_nIndex < m_pBlockHeader->m_nBlockSize )
        {
          if ( &m_pBlockHeader[2 * m_nIndex] == (CUtlFixedMemory<UtlLinkedListElem_t<CStudioRender::DecalLRU_t,int> >::BlockHeader_t *)-8
            || CUtlFixedMemory<UtlLinkedListElem_t<CStudioRender::DecalLRU_t,int>>::IsIdxAfter(
                 this: p_m_Memory,
                 i: (unsigned int)&m_pBlockHeader[2 * m_nIndex + 1],
                 it: (const CUtlFixedMemory<UtlLinkedListElem_t<CStudioRender::DecalLRU_t,int> >::Iterator_t *)&p_m_Memory[2].m_nGrowSize)
            || m_pBlockHeader[2 * m_nIndex + 2].m_pNext == &m_pBlockHeader[2 * m_nIndex + 1]
            && (CUtlFixedMemory<UtlLinkedListElem_t<CStudioRender::DecalLRU_t,int> >::BlockHeader_t *)m_pBlockHeader[2 * m_nIndex + 2].m_nBlockSize != &m_pBlockHeader[2 * m_nIndex + 1] )
          {
            v1 = (CUtlFixedMemory<UtlLinkedListElem_t<CStudioRender::DecalModelList_t,int> > *)p_m_Memory;
          }
          else
          {
            v5 = p_m_Memory;
            m_pBlockHeader[2 * m_nIndex + 2].m_pNext = &m_pBlockHeader[2 * m_nIndex + 1];
            m_pBlockHeader[2 * m_nIndex + 2].m_nBlockSize = v5[1].m_nGrowSize;
            v5[1].m_nGrowSize = (int)&m_pBlockHeader[2 * m_nIndex + 1];
            v1 = (CUtlFixedMemory<UtlLinkedListElem_t<CStudioRender::DecalModelList_t,int> > *)v5;
          }
        }
      }
      else if ( m_nIndex == -1 )
      {
        break;
      }
      if ( m_pBlockHeader == (CUtlFixedMemory<UtlLinkedListElem_t<CStudioRender::DecalLRU_t,int> >::BlockHeader_t *)v1[2].m_nGrowSize
        && (CUtlFixedMemory<UtlLinkedListElem_t<CStudioRender::DecalModelList_t,int> >::BlockHeader_t *)m_nIndex == v1[3].m_pBlocks )
      {
        break;
      }
    }
    v1[1].m_pBlocks = nullptr;
    v1[1].m_nAllocationCount = 0;
    v1[2].m_pBlocks = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004E250
// Name: public: void CUtlLinkedList<struct CStudioRender::DecalModelList_t,int,1,int,class CUtlFixedMemory<struct UtlLinkedListElem_t<struct CStudioRender::DecalModelList_t,int>>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CStudioRender::DecalModelList_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CStudioRender::DecalModelList_t,int>>>::RemoveAll(
        CUtlLinkedList<CStudioRender::DecalModelList_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CStudioRender::DecalModelList_t,int> > > *this)
{
  CUtlLinkedList<CStudioRender::DecalModelList_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CStudioRender::DecalModelList_t,int> > > *v1; // esi
  CUtlFixedMemory<UtlLinkedListElem_t<CStudioRender::DecalModelList_t,int> >::Iterator_t *i; // eax
  CUtlFixedMemory<UtlLinkedListElem_t<CStudioRender::DecalModelList_t,int> >::BlockHeader_t *m_pBlockHeader; // ebx
  int m_nIndex; // edi
  CUtlFixedMemory<UtlLinkedListElem_t<CStudioRender::DecalModelList_t,int> > *v5; // eax
  CUtlFixedMemory<UtlLinkedListElem_t<CStudioRender::DecalModelList_t,int> >::Iterator_t result; // [esp+4h] [ebp-14h] BYREF
  CUtlFixedMemory<UtlLinkedListElem_t<CStudioRender::DecalModelList_t,int> >::Iterator_t it; // [esp+Ch] [ebp-Ch] BYREF
  CUtlFixedMemory<UtlLinkedListElem_t<CStudioRender::DecalModelList_t,int> > *p_m_Memory; // [esp+14h] [ebp-4h]

  v1 = this;
  p_m_Memory = &this->m_Memory;
  if ( this->m_LastAlloc.m_pBlockHeader != nullptr || this->m_LastAlloc.m_nIndex != -1 )
  {
    if ( this->m_Memory.m_pBlocks != nullptr )
    {
      result.m_pBlockHeader = this->m_Memory.m_pBlocks;
      result.m_nIndex = 0;
    }
    else
    {
      result.m_pBlockHeader = nullptr;
      result.m_nIndex = -1;
    }
    for ( i = &result;
          ;
          i = CUtlFixedMemory<UtlLinkedListElem_t<CStudioRender::DecalLRU_t,int>>::Next(
                this: &v1->m_Memory,
                &result,
                &it) )
    {
      m_pBlockHeader = i->m_pBlockHeader;
      m_nIndex = i->m_nIndex;
      it.m_nIndex = m_nIndex;
      it.m_pBlockHeader = m_pBlockHeader;
      if ( m_pBlockHeader != nullptr )
      {
        if ( m_nIndex >= 0 && m_nIndex < m_pBlockHeader->m_nBlockSize )
        {
          if ( (CUtlFixedMemory<UtlLinkedListElem_t<CStudioRender::DecalModelList_t,int> >::BlockHeader_t *)((char *)m_pBlockHeader + 20 * m_nIndex) == (CUtlFixedMemory<UtlLinkedListElem_t<CStudioRender::DecalModelList_t,int> >::BlockHeader_t *)-8
            || CUtlFixedMemory<UtlLinkedListElem_t<CStudioRender::DecalModelList_t,int>>::IsIdxAfter(
                 this: p_m_Memory,
                 i: (unsigned int)&m_pBlockHeader[1] + 20 * m_nIndex,
                 it: (const CUtlFixedMemory<UtlLinkedListElem_t<CStudioRender::DecalModelList_t,int> >::Iterator_t *)&p_m_Memory[2].m_nGrowSize)
            || *((CUtlFixedMemory<UtlLinkedListElem_t<CStudioRender::DecalModelList_t,int> >::BlockHeader_t **)&m_pBlockHeader[2].m_nBlockSize
               + 5 * m_nIndex) == (CUtlFixedMemory<UtlLinkedListElem_t<CStudioRender::DecalModelList_t,int> >::BlockHeader_t *)((char *)&m_pBlockHeader[1] + 20 * m_nIndex)
            && *(&m_pBlockHeader[3].m_pNext + 5 * m_nIndex) != (CUtlFixedMemory<UtlLinkedListElem_t<CStudioRender::DecalModelList_t,int> >::BlockHeader_t *)((char *)&m_pBlockHeader[1] + 20 * m_nIndex) )
          {
            v1 = (CUtlLinkedList<CStudioRender::DecalModelList_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CStudioRender::DecalModelList_t,int> > > *)p_m_Memory;
          }
          else
          {
            v5 = p_m_Memory;
            *(&m_pBlockHeader[2].m_nBlockSize + 5 * m_nIndex) = (int)m_pBlockHeader + 20 * m_nIndex + 8;
            *((_DWORD *)&m_pBlockHeader[3].m_pNext + 5 * m_nIndex) = v5[1].m_nGrowSize;
            v5[1].m_nGrowSize = (int)&m_pBlockHeader[1] + 20 * m_nIndex;
            v1 = (CUtlLinkedList<CStudioRender::DecalModelList_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CStudioRender::DecalModelList_t,int> > > *)v5;
          }
        }
      }
      else if ( m_nIndex == -1 )
      {
        break;
      }
      if ( m_pBlockHeader == v1->m_LastAlloc.m_pBlockHeader && m_nIndex == v1->m_LastAlloc.m_nIndex )
        break;
    }
    v1->m_Head = 0;
    v1->m_Tail = 0;
    v1->m_ElementCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004E420
// Name: public: void CUtlHash<struct studiohwdata_t __near *,bool (*)(struct studiohwdata_t __near * const __near &,struct studiohwdata_t __near * const __near &),unsigned int (*)(struct studiohwdata_t __near * const __near &)>::Purge(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlHash<studiohwdata_t *,bool (__cdecl *)(studiohwdata_t * const &,studiohwdata_t * const &),unsigned int (__cdecl *)(studiohwdata_t * const &)>::Purge(
        CUtlHash<studiohwdata_t *,bool (__cdecl*)(studiohwdata_t * const &,studiohwdata_t * const &),unsigned int (__cdecl*)(studiohwdata_t * const &)> *this)
{
  int v1; // edi
  int m_Size; // ebx
  CUtlVector<studiohwdata_t *,CUtlMemory<studiohwdata_t *,int> > *v3; // esi
  CUtlHash<studiohwdata_t *,bool (__cdecl*)(studiohwdata_t * const &,studiohwdata_t * const &),unsigned int (__cdecl*)(studiohwdata_t * const &)> *v4; // [esp+0h] [ebp-4h]

  v4 = this;
  if ( this->m_Buckets.m_Size > 0 )
  {
    v1 = 0;
    m_Size = this->m_Buckets.m_Size;
    do
    {
      v3 = &this->m_Buckets.m_Memory.m_pMemory[v1];
      v3->m_Size = 0;
      if ( v3->m_Memory.m_nGrowSize >= 0 )
      {
        if ( v3->m_Memory.m_pMemory != nullptr )
        {
          free(pMem: v3->m_Memory.m_pMemory);
          this = v4;
          v3->m_Memory.m_pMemory = nullptr;
        }
        v3->m_Memory.m_nAllocationCount = 0;
      }
      ++v1;
      --m_Size;
      v3->m_pElements = v3->m_Memory.m_pMemory;
    }
    while ( m_Size != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004E480
// Name: void std::_Sort_heap<struct MeshRenderData2_t __near *,bool (*)(struct MeshRenderData2_t const __near &,struct MeshRenderData2_t const __near &)>(struct MeshRenderData2_t __near *,struct MeshRenderData2_t __near *,bool (*)(struct MeshRenderData2_t const __near &,struct MeshRenderData2_t const __near &))
// Source: json
//------------------------------------------------------------------------------
void __cdecl std::_Sort_heap<MeshRenderData2_t *,bool (__cdecl *)(MeshRenderData2_t const &,MeshRenderData2_t const &)>(
        MeshRenderData2_t *_First,
        MeshRenderData2_t *_Last,
        bool (__cdecl *_Pred)(const MeshRenderData2_t *, const MeshRenderData2_t *))
{
  int v3; // ecx
  MeshRenderData2_t *v4; // esi
  int v5; // edx
  MeshRenderData2_t _Val; // [esp+8h] [ebp-14h] BYREF

  v3 = (char *)_Last - (char *)_First;
  if ( _Last - _First > 1 )
  {
    v4 = _Last - 1;
    do
    {
      v5 = *(_DWORD *)&v4->m_nCompressionType;
      *(_QWORD *)&_Val.m_pGroup = *(_QWORD *)&v4->m_pGroup;
      *(_QWORD *)&_Val.m_pMaterial = *(_QWORD *)&v4->m_pMaterial;
      *v4 = *_First;
      *(_DWORD *)&_Val.m_nCompressionType = v5;
      std::_Adjust_heap<MeshRenderData2_t *,int,MeshRenderData2_t,bool (__cdecl *)(MeshRenderData2_t const &,MeshRenderData2_t const &)>(
        _First,
        _Hole: 0,
        _Bottom: (v3 - 20) / 20,
        &_Val,
        _Pred);
      v3 = (char *)--v4 - (char *)_First + 20;
    }
    while ( v3 / 20 > 1 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004E530
// Name: void std::_Sort_heap<struct CStudioRender::DecalRenderData_t __near *,bool (*)(struct CStudioRender::DecalRenderData_t const __near &,struct CStudioRender::DecalRenderData_t const __near &)>(struct CStudioRender::DecalRenderData_t __near *,struct CStudioRender::DecalRenderData_t __near *,bool (*)(struct CStudioRender::DecalRenderData_t const __near &,struct CStudioRender::DecalRenderData_t const __near &))
// Source: json
//------------------------------------------------------------------------------
void __cdecl std::_Sort_heap<CStudioRender::DecalRenderData_t *,bool (__cdecl *)(CStudioRender::DecalRenderData_t const &,CStudioRender::DecalRenderData_t const &)>(
        CStudioRender::DecalRenderData_t *_First,
        CStudioRender::DecalRenderData_t *_Last,
        bool (__cdecl *_Pred)(const CStudioRender::DecalRenderData_t *, const CStudioRender::DecalRenderData_t *))
{
  int v3; // eax
  CStudioRender::DecalRenderData_t *v4; // esi
  CStudioRender::DecalRenderData_t _Val; // [esp+4h] [ebp-10h] BYREF

  v3 = (char *)_Last - (char *)_First;
  if ( (int)(((char *)_Last - (char *)_First) & 0xFFFFFFF0) > 16 )
  {
    v4 = _Last - 1;
    do
    {
      _Val = *v4;
      *v4 = *_First;
      std::_Adjust_heap<MeshRenderData_t *,int,MeshRenderData_t,bool (__cdecl *)(MeshRenderData_t const &,MeshRenderData_t const &)>(
        _First,
        _Hole: 0,
        _Bottom: (v3 - 16) >> 4,
        &_Val,
        _Pred);
      v3 = (char *)--v4 - (char *)_First + 16;
    }
    while ( (int)(v3 & 0xFFFFFFF0) > 16 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004E5B0
// Name: void std::_Sort_heap<struct ShadowMeshRenderData_t __near *,bool (*)(struct ShadowMeshRenderData_t const __near &,struct ShadowMeshRenderData_t const __near &)>(struct ShadowMeshRenderData_t __near *,struct ShadowMeshRenderData_t __near *,bool (*)(struct ShadowMeshRenderData_t const __near &,struct ShadowMeshRenderData_t const __near &))
// Source: json
//------------------------------------------------------------------------------
void __cdecl std::_Sort_heap<ShadowMeshRenderData_t *,bool (__cdecl *)(ShadowMeshRenderData_t const &,ShadowMeshRenderData_t const &)>(
        ShadowMeshRenderData_t *_First,
        ShadowMeshRenderData_t *_Last,
        bool (__cdecl *_Pred)(const ShadowMeshRenderData_t *, const ShadowMeshRenderData_t *))
{
  int v3; // eax
  ShadowMeshRenderData_t *v4; // esi
  ShadowMeshRenderData_t _Val; // [esp+4h] [ebp-20h] BYREF

  v3 = (char *)_Last - (char *)_First;
  if ( (int)(((char *)_Last - (char *)_First) & 0xFFFFFFE0) > 32 )
  {
    v4 = _Last - 1;
    do
    {
      _Val = *v4;
      *v4 = *_First;
      std::_Adjust_heap<ShadowMeshRenderData_t *,int,ShadowMeshRenderData_t,bool (__cdecl *)(ShadowMeshRenderData_t const &,ShadowMeshRenderData_t const &)>(
        _First,
        _Hole: 0,
        _Bottom: (v3 - 32) >> 5,
        &_Val,
        _Pred);
      v3 = (char *)--v4 - (char *)_First + 32;
    }
    while ( (int)(v3 & 0xFFFFFFE0) > 32 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004E710
// Name: public: void CStudioRender::AddShadow(class IMaterial __near *,void __near *,struct FlashlightState_t __near *,class VMatrix __near *,class ITexture __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CStudioRender::AddShadow(
        CStudioRender *this,
        IMaterial *pMaterial,
        void *pProxyData,
        FlashlightState_t *pFlashlightState,
        VMatrix *pWorldToTexture,
        ITexture *pFlashlightDepthTexture)
{
  int m_nAllocationCount; // eax
  CUtlVector<CStudioRender::ShadowState_t,CUtlMemory<CStudioRender::ShadowState_t,int> > *p_m_ShadowState; // esi
  int m_Size; // edi
  CStudioRender::ShadowState_t *m_pMemory; // ecx
  int v10; // eax
  CStudioRender::ShadowState_t *v11; // eax

  m_nAllocationCount = this->m_ShadowState.m_Memory.m_nAllocationCount;
  p_m_ShadowState = &this->m_ShadowState;
  m_Size = this->m_ShadowState.m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CStudioRender::ShadowState_t,int>::Grow(
      this: &p_m_ShadowState->m_Memory,
      num: m_Size - m_nAllocationCount + 1);
  ++p_m_ShadowState->m_Size;
  m_pMemory = p_m_ShadowState->m_Memory.m_pMemory;
  v10 = p_m_ShadowState->m_Size - m_Size - 1;
  p_m_ShadowState->m_pElements = p_m_ShadowState->m_Memory.m_pMemory;
  if ( v10 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 20 * v10);
  v11 = &p_m_ShadowState->m_Memory.m_pMemory[m_Size];
  v11->m_pMaterial = pMaterial;
  v11->m_pProxyData = pProxyData;
  v11->m_pFlashlightState = pFlashlightState;
  v11->m_pWorldToTexture = pWorldToTexture;
  v11->m_pFlashlightDepthTexture = pFlashlightDepthTexture;
}

//------------------------------------------------------------------------------
// Address: 0x1004E790
// Name: int BuildFacesRenderedInfoListForMostRecentFrame(class CUtlVector<struct IStudioRender::FacesRenderedInfo_t,class CUtlMemory<struct IStudioRender::FacesRenderedInfo_t,int>> __near &,class CUtlHash<struct studiohwdata_t __near *,bool (*)(struct studiohwdata_t __near * const __near &,struct studiohwdata_t __near * const __near &),unsigned int (*)(struct studiohwdata_t __near * const __near &)> __near &)
// Source: json
//------------------------------------------------------------------------------
int __cdecl BuildFacesRenderedInfoListForMostRecentFrame(
        CUtlVector<IStudioRender::FacesRenderedInfo_t,CUtlMemory<IStudioRender::FacesRenderedInfo_t,int> > *items,
        CUtlHash<studiohwdata_t *,bool (__cdecl*)(studiohwdata_t * const &,studiohwdata_t * const &),unsigned int (__cdecl*)(studiohwdata_t * const &)> *hash)
{
  CUtlHash<studiohwdata_t *,bool (__cdecl*)(studiohwdata_t * const &,studiohwdata_t * const &),unsigned int (__cdecl*)(studiohwdata_t * const &)> *v2; // esi
  int m_Size; // ecx
  int v4; // eax
  int *p_m_Size; // edx
  int v6; // eax
  unsigned int v7; // ecx
  studiohwdata_t *v8; // ebx
  int v9; // esi
  int m_nAllocationCount; // eax
  IStudioRender::FacesRenderedInfo_t *m_pMemory; // ecx
  int v12; // eax
  IStudioRender::FacesRenderedInfo_t *v13; // eax
  int v14; // edx
  signed int v15; // eax
  int v16; // ecx
  int *v17; // esi
  __int64 item; // [esp+8h] [ebp-14h]
  unsigned int item_8; // [esp+10h] [ebp-Ch]
  int nTotal; // [esp+14h] [ebp-8h]
  unsigned int h; // [esp+18h] [ebp-4h]

  v2 = hash;
  m_Size = hash->m_Buckets.m_Size;
  v4 = 0;
  nTotal = 0;
  if ( m_Size <= 0 )
  {
LABEL_5:
    v6 = -1;
  }
  else
  {
    p_m_Size = &hash->m_Buckets.m_Memory.m_pMemory->m_Size;
    while ( *p_m_Size <= 0 )
    {
      ++v4;
      p_m_Size += 5;
      if ( v4 >= m_Size )
        goto LABEL_5;
    }
    v6 = v4 << 16;
  }
  h = v6;
  if ( v6 != -1 )
  {
    while ( 1 )
    {
      v7 = h;
      v8 = v2->m_Buckets.m_Memory.m_pMemory[HIWORD(h)].m_Memory.m_pMemory[(unsigned __int16)h];
      if ( v8->m_pStudioHdr != nullptr )
      {
        v9 = items->m_Size;
        LODWORD(item) = v8->m_pStudioHdr;
        m_nAllocationCount = items->m_Memory.m_nAllocationCount;
        HIDWORD(item) = v8->m_NumFacesRenderedThisFrame;
        item_8 = v8->m_NumTimesRenderedThisFrame;
        if ( v9 + 1 > m_nAllocationCount )
          CUtlMemory<IStudioRender::FacesRenderedInfo_t,int>::Grow(
            this: &items->m_Memory,
            num: v9 - m_nAllocationCount + 1);
        ++items->m_Size;
        m_pMemory = items->m_Memory.m_pMemory;
        v12 = items->m_Size - v9 - 1;
        items->m_pElements = items->m_Memory.m_pMemory;
        if ( v12 > 0 )
          _V_memmove(dest: &m_pMemory[v9 + 1], src: &m_pMemory[v9], count: 12 * v12);
        v13 = &items->m_Memory.m_pMemory[v9];
        if ( v13 != nullptr )
        {
          *(_QWORD *)&v13->pStudioHdr = item;
          v13->nRenderCount = item_8;
        }
        nTotal += v8->m_NumFacesRenderedThisFrame;
        v2 = hash;
        v7 = h;
      }
      v14 = v2->m_Buckets.m_Size;
      v16 = v7 + 1;
      v15 = HIWORD(v16);
      v16 = (unsigned __int16)v16;
      if ( v15 >= v14 )
        break;
      v17 = &hash->m_Buckets.m_Memory.m_pMemory[v15].m_Size;
      while ( v16 >= *v17 )
      {
        ++v15;
        v16 = 0;
        v17 += 5;
        if ( v15 >= v14 )
          goto LABEL_24;
      }
      h = v16 | (v15 << 16);
      if ( h == -1 )
        break;
      v2 = hash;
    }
  }
LABEL_24:
  qsort(
    base: items->m_Memory.m_pMemory,
    num: items->m_Size,
    width: 0xCu,
    comp: (int (__cdecl *)(const void *, const void *))FacesRenderedInfoSort);
  return nTotal;
}

//------------------------------------------------------------------------------
// Address: 0x1004E8E0
// Name: public: void CStudioRender::GatherRenderedFaceInfo(void (*)(int,struct IStudioRender::FacesRenderedInfo_t __near *,int))
// Source: json
//------------------------------------------------------------------------------
void __thiscall CStudioRender::GatherRenderedFaceInfo(
        CStudioRender *this,
        void (__cdecl *pFunc)(int, IStudioRender::FacesRenderedInfo_t *, int))
{
  int m_nValue; // edi
  int v3; // eax
  int m_Size; // ecx
  CUtlVector<IStudioRender::FacesRenderedInfo_t,CUtlMemory<IStudioRender::FacesRenderedInfo_t,int> > items; // [esp+4h] [ebp-14h] BYREF

  if ( mat_print_top_model_vert_counts_0.m_pParent != nullptr )
  {
    m_nValue = mat_print_top_model_vert_counts_0.m_pParent->m_Value.m_nValue;
    if ( m_nValue != 0 )
    {
      memset(&items, 0, sizeof(items));
      v3 = BuildFacesRenderedInfoListForMostRecentFrame(&items, hash: &this->m_ModelFaceCountHash);
      m_Size = items.m_Size;
      if ( items.m_Size > 0 )
      {
        if ( m_nValue < items.m_Size )
          m_Size = m_nValue;
        pFunc(a1: m_Size, a2: items.m_Memory.m_pMemory, a3: v3);
      }
      CUtlVector<IStudioRender::FacesRenderedInfo_t,CUtlMemory<IStudioRender::FacesRenderedInfo_t,int>>::~CUtlVector<IStudioRender::FacesRenderedInfo_t,CUtlMemory<IStudioRender::FacesRenderedInfo_t,int>>(this: &items);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004E950
// Name: private: int CStudioRender::CountMeshesToDraw(struct StudioModelArrayInfo_t const __near &,int,struct StudioArrayInstanceData_t __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CStudioRender::CountMeshesToDraw(
        CStudioRender *this,
        const StudioModelArrayInfo_t *drawInfo,
        int nCount,
        StudioArrayInstanceData_t *pInstanceData,
        int nInstanceStride,
        int nTimesRendered)
{
  StudioArrayInstanceData_t *v6; // edx
  int result; // eax
  studiohwdata_t *m_pHardwareData; // esi
  studiomeshdata_t *m_pMeshData; // ebx
  studiohdr_t *m_pStudioHdr; // eax
  int v11; // edi
  _DWORD *v12; // ecx
  int v13; // esi
  int v14; // eax
  char *v15; // edx
  int v16; // ecx
  unsigned int v17; // ecx
  char *v18; // eax
  bool v19; // zf
  int meshIndex; // [esp+0h] [ebp-2Ch]
  int nBody; // [esp+4h] [ebp-28h]
  int bodypartindex; // [esp+8h] [ebp-24h]
  int v24; // [esp+14h] [ebp-18h]
  int numbodyparts; // [esp+18h] [ebp-14h]
  int v26; // [esp+20h] [ebp-Ch]
  StudioArrayInstanceData_t *pCurInstance; // [esp+24h] [ebp-8h]
  bool bCountRenderedFaces; // [esp+2Bh] [ebp-1h]
  int nCounta; // [esp+38h] [ebp+Ch]
  int nTotalMeshCount; // [esp+3Ch] [ebp+10h]

  bCountRenderedFaces = mat_rendered_faces_count_0.m_pParent != nullptr
                     && mat_rendered_faces_count_0.m_pParent->m_Value.m_nValue != 0
                     || mat_print_top_model_vert_counts_0.m_pParent != nullptr
                     && mat_print_top_model_vert_counts_0.m_pParent->m_Value.m_nValue != 0;
  v6 = pInstanceData;
  result = 0;
  pCurInstance = pInstanceData;
  nTotalMeshCount = 0;
  if ( nCount > 0 )
  {
    v24 = nCount;
    do
    {
      m_pHardwareData = drawInfo->m_pHardwareData;
      m_pMeshData = m_pHardwareData->m_pLODs[v6->m_nLOD].m_pMeshData;
      if ( bCountRenderedFaces )
      {
        studiohwdata_t::UpdateFacesRenderedCount(
          this: m_pHardwareData,
          pStudioHdr: drawInfo->m_pStudioHdr,
          hwDataHash: &this->m_ModelFaceCountHash,
          nLOD: v6->m_nLOD,
          nInstances: nTimesRendered,
          nFacesOverride: -1);
        v6 = pCurInstance;
      }
      nBody = v6->m_nBody;
      m_pStudioHdr = drawInfo->m_pStudioHdr;
      if ( m_pStudioHdr->numbodyparts > 0 )
      {
        bodypartindex = m_pStudioHdr->bodypartindex;
        nCounta = 0;
        numbodyparts = m_pStudioHdr->numbodyparts;
        while ( 1 )
        {
          v11 = 0;
          v12 = (int *)((char *)&m_pStudioHdr->id + bodypartindex + nCounta);
          v13 = 0;
          v26 = 0;
          v14 = 0;
          v15 = (char *)&v12[37 * (nBody / v12[2] % v12[1])] + v12[3];
          v16 = *((_DWORD *)v15 + 18);
          if ( v16 >= 2 )
          {
            v17 = ((unsigned int)(v16 - 2) >> 1) + 1;
            v18 = &v15[*((_DWORD *)v15 + 19) + 148];
            meshIndex = 2 * v17;
            do
            {
              v11 = m_pMeshData[*(_DWORD *)v18].m_NumGroup + v26;
              v13 += m_pMeshData[*((_DWORD *)v18 - 29)].m_NumGroup;
              v18 += 232;
              --v17;
              v26 = v11;
            }
            while ( v17 != 0 );
            v14 = meshIndex;
          }
          if ( v14 < *((_DWORD *)v15 + 18) )
            nTotalMeshCount += m_pMeshData[*(_DWORD *)&v15[116 * v14 + 32 + *((_DWORD *)v15 + 19)]].m_NumGroup;
          nCounta += 16;
          nTotalMeshCount += v13 + v11;
          if ( --numbodyparts == 0 )
            break;
          m_pStudioHdr = drawInfo->m_pStudioHdr;
        }
        v6 = pCurInstance;
      }
      v6 = (StudioArrayInstanceData_t *)((char *)v6 + nInstanceStride);
      v19 = v24-- == 1;
      pCurInstance = v6;
    }
    while ( !v19 );
    return nTotalMeshCount;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1004EAC0
// Name: private: int CStudioRender::CountMeshesToDraw(struct StudioModelArrayInfo2_t const __near &,int,struct StudioArrayData_t __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CStudioRender::CountMeshesToDraw(
        CStudioRender *this,
        const StudioModelArrayInfo2_t *drawInfo,
        int nCount,
        StudioArrayInstanceData_t *pArrayData,
        int nInstanceStride,
        int nTimesRendered)
{
  int *p_m_pPoseToWorld; // esi
  int *p_m_nLOD; // ecx
  studiohwdata_t *v8; // edi
  studiomeshdata_t *m_pMeshData; // ebx
  int v10; // eax
  int v11; // edi
  _DWORD *v12; // ecx
  int v13; // esi
  int v14; // eax
  char *v15; // edx
  int v16; // ecx
  unsigned int v17; // ecx
  char *v18; // eax
  bool v19; // zf
  int meshIndex; // [esp+0h] [ebp-34h]
  int nBody; // [esp+4h] [ebp-30h]
  int v23; // [esp+8h] [ebp-2Ch]
  int v24; // [esp+Ch] [ebp-28h]
  int v26; // [esp+14h] [ebp-20h]
  int *v27; // [esp+18h] [ebp-1Ch]
  int j; // [esp+1Ch] [ebp-18h]
  int v29; // [esp+20h] [ebp-14h]
  int v30; // [esp+28h] [ebp-Ch]
  int nTotalMeshCount; // [esp+2Ch] [ebp-8h]
  bool bCountRenderedFaces; // [esp+33h] [ebp-1h]
  int nCounta; // [esp+40h] [ebp+Ch]
  StudioArrayInstanceData_t *pCurInstance; // [esp+44h] [ebp+10h]

  bCountRenderedFaces = mat_rendered_faces_count_0.m_pParent != nullptr
                     && mat_rendered_faces_count_0.m_pParent->m_Value.m_nValue != 0
                     || mat_print_top_model_vert_counts_0.m_pParent != nullptr
                     && mat_print_top_model_vert_counts_0.m_pParent->m_Value.m_nValue != 0;
  nTotalMeshCount = 0;
  if ( nCount <= 0 )
    return 0;
  p_m_pPoseToWorld = (int *)&pArrayData->m_pPoseToWorld;
  v27 = (int *)&pArrayData->m_pPoseToWorld;
  v26 = nCount;
  do
  {
    p_m_nLOD = (int *)*(p_m_pPoseToWorld - 1);
    pCurInstance = (StudioArrayInstanceData_t *)p_m_nLOD;
    for ( j = 0; j < *p_m_pPoseToWorld; pCurInstance = (StudioArrayInstanceData_t *)p_m_nLOD )
    {
      v8 = (studiohwdata_t *)*(p_m_pPoseToWorld - 2);
      m_pMeshData = v8->m_pLODs[*p_m_nLOD].m_pMeshData;
      if ( bCountRenderedFaces )
      {
        studiohwdata_t::UpdateFacesRenderedCount(
          this: v8,
          pStudioHdr: (studiohdr_t *)*(p_m_pPoseToWorld - 3),
          hwDataHash: &this->m_ModelFaceCountHash,
          nLOD: *p_m_nLOD,
          nInstances: nTimesRendered,
          nFacesOverride: -1);
        p_m_nLOD = &pCurInstance->m_nLOD;
      }
      v10 = *(p_m_pPoseToWorld - 3);
      nBody = p_m_nLOD[1];
      v24 = v10;
      if ( *(int *)(v10 + 232) > 0 )
      {
        v23 = *(_DWORD *)(v10 + 236);
        nCounta = 0;
        v29 = *(_DWORD *)(v10 + 232);
        while ( 1 )
        {
          v11 = 0;
          v12 = (_DWORD *)(v10 + nCounta + v23);
          v13 = 0;
          v30 = 0;
          v14 = 0;
          v15 = (char *)&v12[37 * (nBody / v12[2] % v12[1])] + v12[3];
          v16 = *((_DWORD *)v15 + 18);
          if ( v16 >= 2 )
          {
            v17 = ((unsigned int)(v16 - 2) >> 1) + 1;
            v18 = &v15[*((_DWORD *)v15 + 19) + 148];
            meshIndex = 2 * v17;
            do
            {
              v11 = m_pMeshData[*(_DWORD *)v18].m_NumGroup + v30;
              v13 += m_pMeshData[*((_DWORD *)v18 - 29)].m_NumGroup;
              v18 += 232;
              --v17;
              v30 = v11;
            }
            while ( v17 != 0 );
            v14 = meshIndex;
          }
          if ( v14 < *((_DWORD *)v15 + 18) )
            nTotalMeshCount += m_pMeshData[*(_DWORD *)&v15[116 * v14 + 32 + *((_DWORD *)v15 + 19)]].m_NumGroup;
          nCounta += 16;
          nTotalMeshCount += v13 + v11;
          if ( --v29 == 0 )
            break;
          v10 = v24;
        }
        p_m_pPoseToWorld = v27;
        p_m_nLOD = &pCurInstance->m_nLOD;
      }
      p_m_nLOD = (int *)((char *)p_m_nLOD + nInstanceStride);
      ++j;
    }
    p_m_pPoseToWorld += 4;
    v19 = v26-- == 1;
    v27 = p_m_pPoseToWorld;
  }
  while ( !v19 );
  return nTotalMeshCount;
}

//------------------------------------------------------------------------------
// Address: 0x1004EC70
// Name: private: int CStudioRender::BuildSortedRenderList(struct MeshRenderData_t __near *,int __near *,struct StudioModelArrayInfo_t const __near &,int,struct StudioArrayInstanceData_t __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CStudioRender::BuildSortedRenderList(
        CStudioRender *this,
        CStudioRender::DecalRenderData_t *pRenderData,
        int *pTotalStripCount,
        const StudioModelArrayInfo_t *drawInfo,
        int nCount,
        StudioArrayInstanceData_t *pInstanceData,
        int nInstanceStride,
        char nFlags)
{
  studiohdr_t *m_pStudioHdr; // edi
  int v9; // ebx
  __int16 *v11; // edx
  int *p_m_nBody; // ecx
  studioloddata_t *v13; // eax
  studiomeshdata_t *m_pMeshData; // esi
  int v15; // eax
  int v16; // ebx
  mstudiomesh_t *v17; // esi
  studiomeshdata_t *v18; // edi
  char v19; // al
  MeshRenderData_t *v20; // edx
  studiomeshgroup_t *v21; // eax
  bool v22; // zf
  __int16 *pSkinRefBase; // [esp+10h] [ebp-40h]
  studiohdr_t *pStudioHdr; // [esp+14h] [ebp-3Ch]
  mstudiomodel_t *pSubmodel; // [esp+18h] [ebp-38h]
  IMaterial *pMaterial; // [esp+1Ch] [ebp-34h]
  IMaterial **ppMaterials; // [esp+20h] [ebp-30h]
  studiomeshdata_t *pMeshDataBase; // [esp+24h] [ebp-2Ch]
  int nBody; // [esp+28h] [ebp-28h]
  int v31; // [esp+2Ch] [ebp-24h]
  int body; // [esp+30h] [ebp-20h]
  int meshIndex; // [esp+34h] [ebp-1Ch]
  int g; // [esp+38h] [ebp-18h]
  __int16 *pSkinRef; // [esp+3Ch] [ebp-14h]
  int v36; // [esp+40h] [ebp-10h]
  int v37; // [esp+44h] [ebp-Ch]
  int nRenderDataCount; // [esp+48h] [ebp-8h]
  int *nCounta; // [esp+64h] [ebp+14h]
  StudioArrayInstanceData_t *pInstanceDataa; // [esp+68h] [ebp+18h]

  m_pStudioHdr = drawInfo->m_pStudioHdr;
  v9 = 0;
  v11 = (__int16 *)((char *)m_pStudioHdr + m_pStudioHdr->skinindex);
  pStudioHdr = m_pStudioHdr;
  pSkinRefBase = v11;
  *pTotalStripCount = 0;
  nRenderDataCount = 0;
  if ( nCount > 0 )
  {
    p_m_nBody = &pInstanceData->m_nBody;
    nCounta = &pInstanceData->m_nBody;
    v31 = nCount;
    do
    {
      v13 = &drawInfo->m_pHardwareData->m_pLODs[*(p_m_nBody - 1)];
      m_pMeshData = v13->m_pMeshData;
      ppMaterials = v13->ppMaterials;
      v15 = p_m_nBody[1];
      pMeshDataBase = m_pMeshData;
      pSkinRef = v11;
      if ( v15 > 0 && v15 < m_pStudioHdr->numskinfamilies )
        pSkinRef = &v11[v15 * m_pStudioHdr->numskinref];
      nBody = *p_m_nBody;
      body = 0;
      if ( m_pStudioHdr->numbodyparts > 0 )
      {
        v36 = 0;
        do
        {
          meshIndex = 0;
          v16 = (int)m_pStudioHdr
              + 148
              * (nBody / *(int *)((char *)&m_pStudioHdr->checksum + v36 + m_pStudioHdr->bodypartindex)
               % *(int *)((char *)&m_pStudioHdr->version + v36 + m_pStudioHdr->bodypartindex))
              + v36
              + m_pStudioHdr->bodypartindex
              + *(_DWORD *)&m_pStudioHdr->name[v36 + m_pStudioHdr->bodypartindex];
          pSubmodel = (mstudiomodel_t *)v16;
          if ( *(int *)(v16 + 72) > 0 )
          {
            v37 = 0;
            do
            {
              v17 = (mstudiomesh_t *)(*(_DWORD *)(v16 + 76) + v16 + v37);
              v18 = &pMeshDataBase[v17->meshid];
              pMaterial = ppMaterials[pSkinRef[v17->material]];
              v19 = ((int (__thiscall *)(IMaterial *, int))pMaterial->IsTranslucentUnderModulation)(
                      a1: pMaterial,
                      a2: p_m_nBody[15]);
              if ( ((nFlags & 1) == 0 || v19 == 0) && ((nFlags & 2) == 0 || v19 != 0) )
              {
                g = 0;
                if ( v18->m_NumGroup > 0 )
                {
                  pInstanceDataa = nullptr;
                  v20 = (MeshRenderData_t *)&pRenderData[nRenderDataCount];
                  do
                  {
                    v21 = (studiomeshgroup_t *)((char *)pInstanceDataa + (unsigned int)v18->m_pMeshGroup);
                    ++nRenderDataCount;
                    pInstanceDataa = (StudioArrayInstanceData_t *)((char *)pInstanceDataa + 44);
                    v20->m_pMaterial = pMaterial;
                    v20->m_pGroup = v21;
                    v20->m_pInstance = (StudioArrayInstanceData_t *)(nCounta - 1);
                    v20->m_pMesh = v17;
                    *pTotalStripCount += v21->m_NumStrips;
                    ++v20;
                    ++g;
                  }
                  while ( g < v18->m_NumGroup );
                  v16 = (int)pSubmodel;
                }
              }
              v37 += 116;
              p_m_nBody = nCounta;
              ++meshIndex;
            }
            while ( meshIndex < *(_DWORD *)(v16 + 72) );
            m_pStudioHdr = pStudioHdr;
          }
          v36 += 16;
          ++body;
        }
        while ( body < m_pStudioHdr->numbodyparts );
        v11 = pSkinRefBase;
      }
      p_m_nBody = (int *)((char *)p_m_nBody + nInstanceStride);
      v22 = v31-- == 1;
      nCounta = p_m_nBody;
    }
    while ( !v22 );
    v9 = nRenderDataCount;
  }
  if ( 16 * v9 > 16 )
    std::_Make_heap<CStudioRender::DecalRenderData_t *,int,CStudioRender::DecalRenderData_t,bool (__cdecl *)(CStudioRender::DecalRenderData_t const &,CStudioRender::DecalRenderData_t const &)>(
      _First: pRenderData,
      _Last: &pRenderData[v9],
      _Pred: (bool (__cdecl *)(const CStudioRender::DecalRenderData_t *, const CStudioRender::DecalRenderData_t *))CStudioRender::SortLessFunc);
  std::_Sort_heap<CStudioRender::DecalRenderData_t *,bool (__cdecl *)(CStudioRender::DecalRenderData_t const &,CStudioRender::DecalRenderData_t const &)>(
    _First: pRenderData,
    _Last: &pRenderData[v9],
    _Pred: (bool (__cdecl *)(const CStudioRender::DecalRenderData_t *, const CStudioRender::DecalRenderData_t *))CStudioRender::SortLessFunc);
  return v9;
}

//------------------------------------------------------------------------------
// Address: 0x1004EE80
// Name: private: int CStudioRender::BuildSortedRenderList(struct MeshRenderData2_t __near *,int __near *,struct StudioModelArrayInfo2_t const __near &,int,struct StudioArrayData_t __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CStudioRender::BuildSortedRenderList(
        CStudioRender *this,
        MeshRenderData2_t *pRenderData,
        int *pTotalStripCount,
        const StudioModelArrayInfo2_t *drawInfo,
        StudioArrayInstanceData_t *nCount,
        StudioArrayData_t *pArrayData,
        int nInstanceStride,
        char nFlags)
{
  int v8; // ebx
  int *p_m_nCount; // edx
  studiohdr_t *v10; // ebx
  StudioArrayInstanceData_t *v11; // ecx
  __int16 *v12; // esi
  studiomeshdata_t **v13; // eax
  studiomeshdata_t *v14; // edi
  int m_nSkin; // eax
  int v16; // esi
  int v17; // ebx
  int *p_m_NumGroup; // edi
  IMaterial *v19; // eax
  mstudiomesh_t *v20; // ebx
  char v21; // al
  MeshRenderData2_t *j; // eax
  studiomeshgroup_t *v23; // esi
  MeshRenderData2_t *v24; // edi
  bool v25; // zf
  __int16 *pSkinRefBase; // [esp+10h] [ebp-50h]
  studiohdr_t *pStudioHdr; // [esp+14h] [ebp-4Ch]
  mstudiomodel_t *pSubmodel; // [esp+18h] [ebp-48h]
  IMaterial *pMaterial; // [esp+1Ch] [ebp-44h]
  MeshRenderData2_t *v31; // [esp+20h] [ebp-40h]
  IMaterial **ppMaterials; // [esp+24h] [ebp-3Ch]
  studiomeshdata_t *pMeshDataBase; // [esp+28h] [ebp-38h]
  int nBody; // [esp+2Ch] [ebp-34h]
  StudioArrayInstanceData_t *v35; // [esp+30h] [ebp-30h]
  int *v36; // [esp+34h] [ebp-2Ch]
  int i; // [esp+38h] [ebp-28h]
  int body; // [esp+3Ch] [ebp-24h]
  int meshIndex; // [esp+40h] [ebp-20h]
  studiomeshdata_t *pMeshData; // [esp+44h] [ebp-1Ch]
  int g; // [esp+48h] [ebp-18h]
  __int16 *pSkinRef; // [esp+4Ch] [ebp-14h]
  int v43; // [esp+50h] [ebp-10h]
  int v44; // [esp+54h] [ebp-Ch]
  int nRenderDataCount; // [esp+58h] [ebp-8h]
  StudioArrayInstanceData_t *pCurInstance; // [esp+74h] [ebp+14h]
  StudioArrayData_t *pArrayDataa; // [esp+78h] [ebp+18h]

  *pTotalStripCount = 0;
  v8 = 0;
  nRenderDataCount = 0;
  if ( (int)nCount > 0 )
  {
    p_m_nCount = &pArrayData->m_nCount;
    v36 = &pArrayData->m_nCount;
    v35 = nCount;
    do
    {
      v10 = (studiohdr_t *)*(p_m_nCount - 3);
      v11 = (StudioArrayInstanceData_t *)*(p_m_nCount - 1);
      v12 = (__int16 *)((char *)v10 + v10->skinindex);
      pStudioHdr = v10;
      pSkinRefBase = v12;
      pCurInstance = v11;
      for ( i = 0; i < *p_m_nCount; pCurInstance = v11 )
      {
        v13 = (studiomeshdata_t **)(*(_DWORD *)(*(p_m_nCount - 2) + 8) + 32 * v11->m_nLOD);
        v14 = *v13;
        ppMaterials = (IMaterial **)v13[3];
        m_nSkin = v11->m_nSkin;
        pMeshDataBase = v14;
        pSkinRef = v12;
        if ( m_nSkin > 0 && m_nSkin < v10->numskinfamilies )
          pSkinRef = &v12[m_nSkin * v10->numskinref];
        nBody = v11->m_nBody;
        body = 0;
        if ( v10->numbodyparts > 0 )
        {
          v43 = 0;
          do
          {
            meshIndex = 0;
            v16 = (int)v10
                + 148
                * (nBody / *(int *)((char *)&v10->checksum + v43 + v10->bodypartindex)
                 % *(int *)((char *)&v10->version + v43 + v10->bodypartindex))
                + v43
                + v10->bodypartindex
                + *(_DWORD *)&v10->name[v43 + v10->bodypartindex];
            pSubmodel = (mstudiomodel_t *)v16;
            if ( *(int *)(v16 + 72) > 0 )
            {
              v44 = 0;
              do
              {
                v17 = v44 + *(_DWORD *)(v16 + 76);
                p_m_NumGroup = &pMeshDataBase[*(_DWORD *)(v17 + v16 + 32)].m_NumGroup;
                v19 = ppMaterials[pSkinRef[*(_DWORD *)(v17 + v16)]];
                v20 = (mstudiomesh_t *)(v16 + v17);
                pMaterial = v19;
                pMeshData = (studiomeshdata_t *)p_m_NumGroup;
                v21 = ((int (__thiscall *)(IMaterial *, _DWORD))v19->IsTranslucentUnderModulation)(
                        a1: v19,
                        a2: LODWORD(v11->m_DiffuseModulation.w));
                if ( ((nFlags & 1) == 0 || v21 == 0) && ((nFlags & 2) == 0 || v21 != 0) )
                {
                  g = 0;
                  if ( *p_m_NumGroup > 0 )
                  {
                    pArrayDataa = nullptr;
                    for ( j = &pRenderData[nRenderDataCount]; ; j = v31 )
                    {
                      v23 = (studiomeshgroup_t *)((char *)pArrayDataa + p_m_NumGroup[1]);
                      ++nRenderDataCount;
                      v24 = j;
                      v31 = j + 1;
                      j->m_pMaterial = pMaterial;
                      j->m_pGroup = v23;
                      j->m_pInstance = pCurInstance;
                      j->m_pMesh = v20;
                      j->m_nCompressionType = (v23->m_pMesh->GetVertexFormat(this: v23->m_pMesh) & 0x400) != 0;
                      pArrayDataa = (StudioArrayData_t *)((char *)pArrayDataa + 44);
                      v24->m_nMeshBoneCount = (v23->m_pMesh->GetVertexFormat(this: v23->m_pMesh) >> 12) & 7;
                      *pTotalStripCount += v23->m_NumStrips;
                      if ( ++g >= pMeshData->m_NumGroup )
                        break;
                      p_m_NumGroup = &pMeshData->m_NumGroup;
                    }
                    v16 = (int)pSubmodel;
                  }
                }
                v44 += 116;
                v11 = pCurInstance;
                ++meshIndex;
              }
              while ( meshIndex < *(_DWORD *)(v16 + 72) );
              v10 = pStudioHdr;
            }
            v43 += 16;
            ++body;
          }
          while ( body < v10->numbodyparts );
          v12 = pSkinRefBase;
          p_m_nCount = v36;
        }
        v11 = (StudioArrayInstanceData_t *)((char *)v11 + nInstanceStride);
        ++i;
      }
      p_m_nCount += 4;
      v25 = v35 == (StudioArrayInstanceData_t *)1;
      v35 = (StudioArrayInstanceData_t *)((char *)v35 - 1);
      v36 = p_m_nCount;
    }
    while ( !v25 );
    v8 = nRenderDataCount;
  }
  if ( 20 * v8 / 20 > 1 )
    std::_Make_heap<MeshRenderData2_t *,int,MeshRenderData2_t,bool (__cdecl *)(MeshRenderData2_t const &,MeshRenderData2_t const &)>(
      _First: pRenderData,
      _Last: &pRenderData[v8],
      _Pred: CStudioRender::SortLessFunc2);
  std::_Sort_heap<MeshRenderData2_t *,bool (__cdecl *)(MeshRenderData2_t const &,MeshRenderData2_t const &)>(
    _First: pRenderData,
    _Last: &pRenderData[v8],
    _Pred: CStudioRender::SortLessFunc2);
  return v8;
}

//------------------------------------------------------------------------------
// Address: 0x1004F130
// Name: private: int CStudioRender::BuildSortedDecalRenderList(struct CStudioRender::DecalRenderData_t __near *,int,struct StudioArrayInstanceData_t __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CStudioRender::BuildSortedDecalRenderList(
        CStudioRender *this,
        CStudioRender::DecalRenderData_t *pDecalRenderData,
        int nCount,
        StudioArrayInstanceData_t *pInstanceData,
        int nInstanceStride)
{
  StudioArrayInstanceData_t *v5; // edx
  int v6; // esi
  StudioDecalHandle_t__ *m_Decals; // eax
  unsigned __int16 m_Next; // ax
  CStudioRender::DecalRenderData_t *v9; // ebx
  int v10; // edi
  UtlLinkedListElem_t<CStudioRender::DecalMaterial_t,unsigned short> *v11; // eax
  CStudioRender::DecalRenderData_t *v12; // esi
  bool v13; // al
  bool v14; // zf
  CStudioRender::DecalRenderData_t *v15; // ebx
  IMaterial **p_m_pRenderMaterial; // eax
  int i; // edx
  CStudioRender *v19; // [esp+Ch] [ebp-8h]
  int nDecalMeshCount; // [esp+10h] [ebp-4h]

  v5 = pInstanceData;
  v6 = 0;
  v19 = this;
  nDecalMeshCount = 0;
  if ( nCount > 0 )
  {
    do
    {
      m_Decals = v5->m_Decals;
      if ( m_Decals != nullptr )
      {
        m_Next = *(_WORD *)(32 * v5->m_nLOD + *((_DWORD *)m_Decals + 1));
        if ( m_Next != 0xFFFF )
        {
          v9 = &pDecalRenderData[v6];
          do
          {
            v10 = m_Next;
            v11 = &this->m_DecalMaterial.m_Memory.m_pMemory[v10];
            if ( v11->m_Element.m_Indices.m_Size != 0 )
            {
              ++nDecalMeshCount;
              v12 = v9;
              v9->m_pDecalMaterial = &v11->m_Element;
              v9->m_pInstance = v5;
              v9->m_pRenderMaterial = v11->m_Element.m_pMaterial;
              ++v9;
              v13 = v11->m_Element.m_pMaterial->IsVertexLit(this: v11->m_Element.m_pMaterial);
              this = v19;
              v5 = pInstanceData;
              v12->m_bIsVertexLit = v13;
              v6 = nDecalMeshCount;
            }
            m_Next = this->m_DecalMaterial.m_Memory.m_pMemory[v10].m_Next;
          }
          while ( m_Next != 0xFFFF );
        }
      }
      v5 = (StudioArrayInstanceData_t *)((char *)v5 + nInstanceStride);
      v14 = nCount-- == 1;
      pInstanceData = v5;
    }
    while ( !v14 );
  }
  if ( (*((_BYTE *)&this->m_pRC->m_Config.StudioRenderConfig_t + 37) & 0x20) != 0 && v6 > 0 )
  {
    v15 = pDecalRenderData;
    p_m_pRenderMaterial = &pDecalRenderData->m_pRenderMaterial;
    for ( i = v6; i != 0; --i )
    {
      *p_m_pRenderMaterial = this->m_pMaterialWireframe[0][0];
      p_m_pRenderMaterial += 4;
    }
  }
  else
  {
    v15 = pDecalRenderData;
  }
  if ( 16 * v6 > 16 )
    std::_Make_heap<CStudioRender::DecalRenderData_t *,int,CStudioRender::DecalRenderData_t,bool (__cdecl *)(CStudioRender::DecalRenderData_t const &,CStudioRender::DecalRenderData_t const &)>(
      _First: v15,
      _Last: &v15[v6],
      _Pred: CStudioRender::SortDecalsLessFunc);
  std::_Sort_heap<CStudioRender::DecalRenderData_t *,bool (__cdecl *)(CStudioRender::DecalRenderData_t const &,CStudioRender::DecalRenderData_t const &)>(
    _First: v15,
    _Last: &v15[v6],
    _Pred: CStudioRender::SortDecalsLessFunc);
  return v6;
}

//------------------------------------------------------------------------------
// Address: 0x1004F250
// Name: public: void CStudioRender::DrawModelArray(struct StudioModelArrayInfo_t const __near &,struct StudioRenderContext_t const __near &,int,struct StudioArrayInstanceData_t __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CStudioRender::DrawModelArray(
        CStudioRender *this,
        const StudioModelArrayInfo_t *drawInfo,
        StudioRenderContext_t *rc,
        int nCount,
        StudioArrayInstanceData_t *pInstanceData,
        studiohdr_t *nInstanceStride,
        char nFlags)
{
  IMatRenderContext *v8; // eax
  IMatRenderContext *v9; // esi
  void *v11; // esp
  bool v12; // zf
  void *v13; // esp
  _BYTE v14[12]; // [esp+0h] [ebp-14h] BYREF
  MeshRenderData_t *pRenderData; // [esp+Ch] [ebp-8h]
  bool bDoShadows; // [esp+13h] [ebp-1h]
  int nTotalMeshCount; // [esp+1Ch] [ebp+8h]

  this->m_pRC = rc;
  v8 = g_pMaterialSystem->GetRenderContext(this: g_pMaterialSystem);
  v9 = v8;
  if ( v8 != nullptr )
    v8->BeginRender(this: v8);
  v9->MatrixMode(this: v9, a2: MATERIAL_MODEL);
  v9->PushMatrix(this: v9);
  v9->LoadIdentity(this: v9);
  bDoShadows = (nFlags & 0x20) == 0;
  nTotalMeshCount = CStudioRender::CountMeshesToDraw(
                      this,
                      drawInfo,
                      nCount,
                      pInstanceData,
                      (int)nInstanceStride,
                      nTimesRendered: 0);
  v11 = alloca(16 * nTotalMeshCount);
  v12 = rc->m_pForcedMaterial == nullptr;
  pRenderData = (MeshRenderData_t *)v14;
  if ( v12 )
    nTotalMeshCount = CStudioRender::BuildSortedRenderList(
                        this,
                        pRenderData: (CStudioRender::DecalRenderData_t *)v14,
                        pTotalStripCount: (int *)&rc,
                        drawInfo,
                        nCount,
                        pInstanceData,
                        (int)nInstanceStride,
                        nFlags);
  else
    CStudioRender::BuildForcedMaterialRenderList(
      this,
      pRenderData: (MeshRenderData_t *)v14,
      pTotalStripCount: (int *)&rc,
      drawInfo,
      rc,
      nCount,
      pInstanceData,
      (int)nInstanceStride);
  CStudioRender::RestoreMeshes(this, nCount: nTotalMeshCount, pRenderData, nStride: 16);
  CStudioRender::DrawMeshRenderData(
    this,
    pRenderContext: v9,
    drawInfo,
    nCount: nTotalMeshCount,
    pRenderData,
    nTotalStripCount: (int)rc,
    nFlashlightMask: 0);
  if ( bDoShadows )
    CStudioRender::DrawModelArrayFlashlight(
      this,
      pRenderContext: v9,
      drawInfo,
      nCount: nTotalMeshCount,
      pRenderData,
      nTotalStripCount: (int)rc);
  v13 = alloca(16 * CStudioRender::CountDecalMeshesToDraw(this, nCount, pInstanceData, (int)nInstanceStride));
  rc = (StudioRenderContext_t *)v14;
  nInstanceStride = (studiohdr_t *)CStudioRender::BuildSortedDecalRenderList(
                                     this,
                                     pDecalRenderData: (CStudioRender::DecalRenderData_t *)v14,
                                     nCount,
                                     pInstanceData,
                                     (int)nInstanceStride);
  CStudioRender::DrawModelArrayDecals(
    this,
    pRenderContext: v9,
    pStudioHdr: drawInfo->m_pStudioHdr,
    nCount: nInstanceStride,
    pRenderData: (StudioArrayInstanceData_t *)rc,
    nFlashlightMask: 0);
  if ( bDoShadows )
    CStudioRender::DrawModelArrayFlashlightDecals(
      this,
      pRenderContext: v9,
      pStudioHdr: drawInfo->m_pStudioHdr,
      nFlashlightCount: drawInfo->m_nFlashlightCount,
      pFlashlights: (CStudioRender::DecalRenderData_t *)drawInfo->m_pFlashlights,
      nCount: (int)nInstanceStride,
      pRenderData: (CStudioRender::DecalRenderData_t *)rc);
  v9->MatrixMode(this: v9, a2: MATERIAL_MODEL);
  v9->PopMatrix(this: v9);
  v9->SetNumBoneWeights(this: v9, a2: 0);
  v9->EndRender(this: v9);
  v9->Release(this: v9);
}

//------------------------------------------------------------------------------
// Address: 0x1004F420
// Name: public: void CStudioRender::DrawModelArray2(struct StudioModelArrayInfo2_t const __near &,struct StudioRenderContext_t const __near &,int,struct StudioArrayData_t __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CStudioRender::DrawModelArray2(
        CStudioRender *this,
        const StudioModelArrayInfo2_t *drawInfo,
        StudioRenderContext_t *rc,
        StudioArrayInstanceData_t *nCount,
        StudioArrayInstanceData_t *pArrayData,
        int nInstanceStride,
        char nFlags)
{
  IMatRenderContext *v8; // eax
  IMatRenderContext *v9; // esi
  int v10; // ebx
  void *v11; // esp
  bool v12; // zf
  int *p_m_pPoseToWorld; // ebx
  void *v14; // esp
  StudioRenderContext_t *v15; // eax
  studiohdr_t *v16; // [esp-10h] [ebp-24h]
  int v17; // [esp-Ch] [ebp-20h]
  StudioArrayInstanceData_t *v18; // [esp-8h] [ebp-1Ch]
  _BYTE v19[12]; // [esp+0h] [ebp-14h] BYREF
  MeshRenderData2_t *pRenderData; // [esp+Ch] [ebp-8h]
  bool bDoShadows; // [esp+13h] [ebp-1h]

  this->m_pRC = rc;
  v8 = g_pMaterialSystem->GetRenderContext(this: g_pMaterialSystem);
  v9 = v8;
  if ( v8 != nullptr )
    v8->BeginRender(this: v8);
  v9->MatrixMode(this: v9, a2: MATERIAL_MODEL);
  v9->PushMatrix(this: v9);
  v9->LoadIdentity(this: v9);
  bDoShadows = (nFlags & 0x20) == 0;
  v10 = CStudioRender::CountMeshesToDraw(this, drawInfo, (int)nCount, pArrayData, nInstanceStride, nTimesRendered: 0);
  v11 = alloca(20 * v10);
  v12 = rc->m_pForcedMaterial == nullptr;
  pRenderData = (MeshRenderData2_t *)v19;
  if ( v12 )
    v10 = CStudioRender::BuildSortedRenderList(
            this,
            pRenderData: (MeshRenderData2_t *)v19,
            pTotalStripCount: (int *)&rc,
            drawInfo,
            nCount,
            (StudioArrayData_t *)pArrayData,
            nInstanceStride,
            nFlags);
  else
    CStudioRender::BuildForcedMaterialRenderList(
      this,
      pRenderData: (MeshRenderData2_t *)v19,
      pTotalStripCount: (int *)&rc,
      drawInfo,
      rc,
      (int)nCount,
      (StudioArrayData_t *)pArrayData,
      nInstanceStride);
  CStudioRender::RestoreMeshes(this, nCount: v10, pRenderData, nStride: 20);
  CStudioRender::DrawMeshRenderData(
    this,
    pRenderContext: v9,
    drawInfo,
    nCount: v10,
    pRenderData,
    nTotalStripCount: (int)rc,
    nFlashlightMask: 0);
  if ( bDoShadows )
    CStudioRender::DrawModelArrayFlashlight(
      this,
      pRenderContext: v9,
      drawInfo,
      nCount: v10,
      pRenderData,
      nTotalStripCount: (int)rc);
  if ( (int)nCount > 0 )
  {
    p_m_pPoseToWorld = (int *)&pArrayData->m_pPoseToWorld;
    for ( pArrayData = nCount; pArrayData != nullptr; pArrayData = (StudioArrayInstanceData_t *)((char *)pArrayData - 1) )
    {
      v14 = alloca(
              16
            * CStudioRender::CountDecalMeshesToDraw(
                this,
                nCount: *p_m_pPoseToWorld,
                pInstanceData: (StudioArrayInstanceData_t *)*(p_m_pPoseToWorld - 1),
                nInstanceStride));
      v18 = (StudioArrayInstanceData_t *)*(p_m_pPoseToWorld - 1);
      v17 = *p_m_pPoseToWorld;
      nCount = (StudioArrayInstanceData_t *)v19;
      v15 = (StudioRenderContext_t *)CStudioRender::BuildSortedDecalRenderList(
                                       this,
                                       pDecalRenderData: (CStudioRender::DecalRenderData_t *)v19,
                                       nCount: v17,
                                       pInstanceData: v18,
                                       nInstanceStride);
      v16 = (studiohdr_t *)*(p_m_pPoseToWorld - 3);
      rc = v15;
      CStudioRender::DrawModelArrayDecals(
        this,
        pRenderContext: v9,
        pStudioHdr: v16,
        nCount: (studiohdr_t *)v15,
        pRenderData: nCount,
        nFlashlightMask: 0);
      if ( bDoShadows )
        CStudioRender::DrawModelArrayFlashlightDecals(
          this,
          pRenderContext: v9,
          pStudioHdr: (studiohdr_t *)*(p_m_pPoseToWorld - 3),
          nFlashlightCount: drawInfo->m_nFlashlightCount,
          pFlashlights: (CStudioRender::DecalRenderData_t *)drawInfo->m_pFlashlights,
          nCount: (int)rc,
          pRenderData: (CStudioRender::DecalRenderData_t *)nCount);
      p_m_pPoseToWorld += 4;
    }
  }
  v9->MatrixMode(this: v9, a2: MATERIAL_MODEL);
  v9->PopMatrix(this: v9);
  v9->SetNumBoneWeights(this: v9, a2: 0);
  v9->EndRender(this: v9);
  v9->Release(this: v9);
}

//------------------------------------------------------------------------------
// Address: 0x1004F610
// Name: private: int CStudioRender::CountMeshesToDraw(int,struct StudioArrayData_t __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CStudioRender::CountMeshesToDraw(
        CStudioRender *this,
        int nCount,
        StudioShadowArrayInstanceData_t *pShadowData,
        int nInstanceStride)
{
  int *p_m_pPoseToWorld; // esi
  int *p_m_nLOD; // ecx
  studiohwdata_t *v6; // edi
  studiomeshdata_t *m_pMeshData; // ebx
  int v8; // eax
  int v9; // edi
  _DWORD *v10; // ecx
  int v11; // esi
  int v12; // eax
  char *v13; // edx
  int v14; // ecx
  unsigned int v15; // ecx
  char *v16; // eax
  bool v17; // zf
  int meshIndex; // [esp+0h] [ebp-34h]
  int nBody; // [esp+4h] [ebp-30h]
  int v21; // [esp+8h] [ebp-2Ch]
  int v22; // [esp+Ch] [ebp-28h]
  int v24; // [esp+14h] [ebp-20h]
  int *v25; // [esp+18h] [ebp-1Ch]
  int j; // [esp+1Ch] [ebp-18h]
  int v27; // [esp+20h] [ebp-14h]
  int v28; // [esp+28h] [ebp-Ch]
  int nTotalMeshCount; // [esp+2Ch] [ebp-8h]
  bool bCountRenderedFaces; // [esp+33h] [ebp-1h]
  int nCounta; // [esp+3Ch] [ebp+8h]
  StudioShadowArrayInstanceData_t *pCurInstance; // [esp+40h] [ebp+Ch]

  bCountRenderedFaces = mat_rendered_faces_count_0.m_pParent != nullptr
                     && mat_rendered_faces_count_0.m_pParent->m_Value.m_nValue != 0
                     || mat_print_top_model_vert_counts_0.m_pParent != nullptr
                     && mat_print_top_model_vert_counts_0.m_pParent->m_Value.m_nValue != 0;
  nTotalMeshCount = 0;
  if ( nCount <= 0 )
    return 0;
  p_m_pPoseToWorld = (int *)&pShadowData->m_pPoseToWorld;
  v25 = (int *)&pShadowData->m_pPoseToWorld;
  v24 = nCount;
  do
  {
    p_m_nLOD = (int *)*(p_m_pPoseToWorld - 1);
    pCurInstance = (StudioShadowArrayInstanceData_t *)p_m_nLOD;
    for ( j = 0; j < *p_m_pPoseToWorld; pCurInstance = (StudioShadowArrayInstanceData_t *)p_m_nLOD )
    {
      v6 = (studiohwdata_t *)*(p_m_pPoseToWorld - 2);
      m_pMeshData = v6->m_pLODs[*p_m_nLOD].m_pMeshData;
      if ( bCountRenderedFaces )
      {
        studiohwdata_t::UpdateFacesRenderedCount(
          this: v6,
          pStudioHdr: (studiohdr_t *)*(p_m_pPoseToWorld - 3),
          hwDataHash: &this->m_ModelFaceCountHash,
          nLOD: *p_m_nLOD,
          nInstances: 1,
          nFacesOverride: -1);
        p_m_nLOD = &pCurInstance->m_nLOD;
      }
      v8 = *(p_m_pPoseToWorld - 3);
      nBody = p_m_nLOD[1];
      v22 = v8;
      if ( *(int *)(v8 + 232) > 0 )
      {
        v21 = *(_DWORD *)(v8 + 236);
        nCounta = 0;
        v27 = *(_DWORD *)(v8 + 232);
        while ( 1 )
        {
          v9 = 0;
          v10 = (_DWORD *)(v8 + nCounta + v21);
          v11 = 0;
          v28 = 0;
          v12 = 0;
          v13 = (char *)&v10[37 * (nBody / v10[2] % v10[1])] + v10[3];
          v14 = *((_DWORD *)v13 + 18);
          if ( v14 >= 2 )
          {
            v15 = ((unsigned int)(v14 - 2) >> 1) + 1;
            v16 = &v13[*((_DWORD *)v13 + 19) + 148];
            meshIndex = 2 * v15;
            do
            {
              v9 = m_pMeshData[*(_DWORD *)v16].m_NumGroup + v28;
              v11 += m_pMeshData[*((_DWORD *)v16 - 29)].m_NumGroup;
              v16 += 232;
              --v15;
              v28 = v9;
            }
            while ( v15 != 0 );
            v12 = meshIndex;
          }
          if ( v12 < *((_DWORD *)v13 + 18) )
            nTotalMeshCount += m_pMeshData[*(_DWORD *)&v13[116 * v12 + 32 + *((_DWORD *)v13 + 19)]].m_NumGroup;
          nCounta += 16;
          nTotalMeshCount += v11 + v9;
          if ( --v27 == 0 )
            break;
          v8 = v22;
        }
        p_m_pPoseToWorld = v25;
        p_m_nLOD = &pCurInstance->m_nLOD;
      }
      p_m_nLOD = (int *)((char *)p_m_nLOD + nInstanceStride);
      ++j;
    }
    p_m_pPoseToWorld += 4;
    v17 = v24-- == 1;
    v25 = p_m_pPoseToWorld;
  }
  while ( !v17 );
  return nTotalMeshCount;
}

//------------------------------------------------------------------------------
// Address: 0x1004F7B0
// Name: private: int CStudioRender::BuildShadowRenderList(struct ShadowMeshRenderData_t __near *,int __near *,int,struct StudioArrayData_t __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CStudioRender::BuildShadowRenderList(
        CStudioRender *this,
        ShadowMeshRenderData_t *pRenderData,
        int *pTotalStripCount,
        int nCount,
        StudioArrayData_t *pShadowData,
        int nInstanceStride)
{
  int v6; // ebx
  int *p_m_nCount; // ecx
  studiohdr_t *v8; // edi
  StudioShadowArrayInstanceData_t *v9; // ebx
  __int16 *v10; // edx
  bool v11; // cc
  int v12; // eax
  studiomeshdata_t *v13; // esi
  int m_nSkin; // eax
  _DWORD *v15; // ecx
  int v16; // edx
  mstudiomodel_t *v17; // esi
  int v18; // eax
  studiomeshdata_t *v19; // edi
  IMaterial *v20; // ebx
  bool (__thiscall *IsTranslucentUnderModulation)(IMaterial *, float); // eax
  ShadowMeshRenderData_t *v22; // ebx
  studiomeshgroup_t *v23; // edi
  BOOL v24; // eax
  StudioShadowArrayInstanceData_t *v25; // ecx
  ShadowMeshRenderData_t *v26; // esi
  IMaterial *v27; // ecx
  unsigned __int64 v28; // rax
  char v29; // cl
  studiomeshdata_t *v30; // ecx
  bool v31; // zf
  __int16 *pSkinRefBase; // [esp+10h] [ebp-5Ch]
  studiohdr_t *pStudioHdr; // [esp+14h] [ebp-58h]
  mstudiomodel_t *pSubmodel; // [esp+18h] [ebp-54h]
  IMaterial *pMaterial; // [esp+1Ch] [ebp-50h]
  IMaterial *pDepthMaterial; // [esp+20h] [ebp-4Ch] BYREF
  mstudiomesh_t *pMesh; // [esp+24h] [ebp-48h]
  CStudioRender *v39; // [esp+28h] [ebp-44h]
  IMaterial **ppMaterials; // [esp+2Ch] [ebp-40h]
  studiomeshdata_t *pMeshDataBase; // [esp+30h] [ebp-3Ch]
  int nBody; // [esp+34h] [ebp-38h]
  int v43; // [esp+38h] [ebp-34h]
  int *v44; // [esp+3Ch] [ebp-30h]
  int j; // [esp+40h] [ebp-2Ch]
  int body; // [esp+44h] [ebp-28h]
  int meshIndex; // [esp+48h] [ebp-24h]
  studiomeshdata_t *pMeshData; // [esp+4Ch] [ebp-20h]
  int g; // [esp+50h] [ebp-1Ch]
  __int16 *pSkinRef; // [esp+54h] [ebp-18h]
  StudioShadowArrayInstanceData_t *pCurInstance; // [esp+58h] [ebp-14h]
  int v52; // [esp+5Ch] [ebp-10h]
  int v53; // [esp+60h] [ebp-Ch]
  unsigned int v54; // [esp+64h] [ebp-8h]
  int nRenderDataCount; // [esp+68h] [ebp-4h]

  *pTotalStripCount = 0;
  v6 = 0;
  v39 = this;
  nRenderDataCount = 0;
  if ( nCount > 0 )
  {
    p_m_nCount = &pShadowData->m_nCount;
    v44 = &pShadowData->m_nCount;
    v43 = nCount;
    do
    {
      v8 = (studiohdr_t *)*(p_m_nCount - 3);
      v9 = (StudioShadowArrayInstanceData_t *)*(p_m_nCount - 1);
      v10 = (__int16 *)((char *)v8 + v8->skinindex);
      v11 = *p_m_nCount <= 0;
      pStudioHdr = v8;
      pSkinRefBase = v10;
      pCurInstance = v9;
      j = 0;
      if ( !v11 )
      {
        do
        {
          v12 = *(_DWORD *)(*(p_m_nCount - 2) + 8) + 32 * v9->m_nLOD;
          v13 = *(studiomeshdata_t **)v12;
          ppMaterials = *(IMaterial ***)(v12 + 12);
          m_nSkin = v9->m_nSkin;
          pMeshDataBase = v13;
          pSkinRef = v10;
          if ( m_nSkin > 0 && m_nSkin < v8->numskinfamilies )
            pSkinRef = &v10[m_nSkin * v8->numskinref];
          nBody = v9->m_nBody;
          body = 0;
          if ( v8->numbodyparts > 0 )
          {
            v52 = 0;
            do
            {
              v15 = (int *)((char *)&v8->id + v52 + v8->bodypartindex);
              v16 = nBody / v15[2] % v15[1];
              meshIndex = 0;
              v17 = (mstudiomodel_t *)((char *)&v15[37 * v16] + v15[3]);
              pSubmodel = v17;
              if ( v17->nummeshes > 0 )
              {
                v53 = 0;
                do
                {
                  v18 = v53 + v17->meshindex;
                  v19 = &pMeshDataBase[*(_DWORD *)&v17->name[v18 + 32]];
                  pMesh = (mstudiomesh_t *)&v17->name[v18];
                  v20 = ppMaterials[pSkinRef[*(_DWORD *)&v17->name[v18]]];
                  IsTranslucentUnderModulation = v20->IsTranslucentUnderModulation;
                  pMeshData = v19;
                  pMaterial = v20;
                  if ( ((unsigned __int8 (__thiscall *)(IMaterial *, int))IsTranslucentUnderModulation)(
                         a1: v20,
                         a2: 1065353216) == 0 )
                  {
                    HIBYTE(nCount) = 0;
                    HIBYTE(pShadowData) = 0;
                    CStudioRender::GetDepthWriteMaterial(
                      this: v39,
                      ppDepthMaterial: &pDepthMaterial,
                      pIsAlphaTested: (bool *)&nCount + 3,
                      pUsesTreeSway: (bool *)&pShadowData + 3,
                      pSrcMaterial: v20);
                    g = 0;
                    if ( v19->m_NumGroup > 0 )
                    {
                      v22 = &pRenderData[nRenderDataCount];
                      v54 = 0;
                      while ( 1 )
                      {
                        v23 = &v19->m_pMeshGroup[v54 / 0x2C];
                        v24 = (v23->m_pMesh->GetVertexFormat(this: v23->m_pMesh) & 0x400) != 0;
                        v25 = pCurInstance;
                        ++nRenderDataCount;
                        v26 = v22;
                        v22->m_pMesh = pMesh;
                        v22->m_pInstance = v25;
                        v27 = pDepthMaterial;
                        v22->m_pSrcMaterial = pMaterial;
                        v22->m_pGroup = v23;
                        v22->m_pMaterial = v27;
                        v22->m_nCompressionType = v24;
                        ++v22;
                        v28 = v23->m_pMesh->GetVertexFormat(this: v23->m_pMesh);
                        v29 = HIBYTE(pShadowData);
                        v54 += 44;
                        v26->m_nMeshBoneCount = (v28 >> 12) & 7;
                        v26->m_bIsAlphaTested = HIBYTE(nCount);
                        v26->m_bUsesTreeSway = v29;
                        v30 = pMeshData;
                        *pTotalStripCount += v23->m_NumStrips;
                        if ( ++g >= v30->m_NumGroup )
                          break;
                        v19 = pMeshData;
                      }
                      v17 = pSubmodel;
                    }
                  }
                  v53 += 116;
                  ++meshIndex;
                }
                while ( meshIndex < v17->nummeshes );
                v8 = pStudioHdr;
                v9 = pCurInstance;
              }
              v52 += 16;
              ++body;
            }
            while ( body < v8->numbodyparts );
            p_m_nCount = v44;
            v10 = pSkinRefBase;
          }
          v9 = (StudioShadowArrayInstanceData_t *)((char *)v9 + nInstanceStride);
          ++j;
          pCurInstance = v9;
        }
        while ( j < *p_m_nCount );
      }
      p_m_nCount += 4;
      v31 = v43-- == 1;
      v44 = p_m_nCount;
    }
    while ( !v31 );
    v6 = nRenderDataCount;
  }
  if ( 32 * v6 > 32 )
    std::_Make_heap<ShadowMeshRenderData_t *,int,ShadowMeshRenderData_t,bool (__cdecl *)(ShadowMeshRenderData_t const &,ShadowMeshRenderData_t const &)>(
      _First: pRenderData,
      _Last: &pRenderData[v6],
      _Pred: (bool (__cdecl *)(const ShadowMeshRenderData_t *, const ShadowMeshRenderData_t *))CStudioRender::ShadowSortLessFunc);
  std::_Sort_heap<ShadowMeshRenderData_t *,bool (__cdecl *)(ShadowMeshRenderData_t const &,ShadowMeshRenderData_t const &)>(
    _First: pRenderData,
    _Last: &pRenderData[v6],
    _Pred: (bool (__cdecl *)(const ShadowMeshRenderData_t *, const ShadowMeshRenderData_t *))CStudioRender::ShadowSortLessFunc);
  return v6;
}

//------------------------------------------------------------------------------
// Address: 0x1004FA50
// Name: public: void CStudioRender::DrawModelShadowArray(struct StudioRenderContext_t const __near &,int,struct StudioArrayData_t __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CStudioRender::DrawModelShadowArray(
        CStudioRender *this,
        StudioRenderContext_t *rc,
        int nCount,
        StudioShadowArrayInstanceData_t *pShadowData,
        int nInstanceStride,
        int flags)
{
  IMatRenderContext *v7; // eax
  IMatRenderContext *v8; // esi
  void *v9; // esp
  BaseMeshRenderData_t v10; // [esp+0h] [ebp-Ch] BYREF
  int nTotalMeshCount; // [esp+1Ch] [ebp+10h]

  this->m_pRC = rc;
  v7 = g_pMaterialSystem->GetRenderContext(this: g_pMaterialSystem);
  v8 = v7;
  if ( v7 != nullptr )
    v7->BeginRender(this: v7);
  v8->MatrixMode(this: v8, a2: MATERIAL_MODEL);
  v8->PushMatrix(this: v8);
  v8->LoadIdentity(this: v8);
  v9 = alloca(32 * CStudioRender::CountMeshesToDraw(this, nCount, pShadowData, nInstanceStride));
  nTotalMeshCount = CStudioRender::BuildShadowRenderList(
                      this,
                      pRenderData: (ShadowMeshRenderData_t *)&v10,
                      pTotalStripCount: &nInstanceStride,
                      nCount,
                      (StudioArrayData_t *)pShadowData,
                      nInstanceStride);
  CStudioRender::RestoreMeshes(this, nCount: nTotalMeshCount, pRenderData: &v10, nStride: 32);
  CStudioRender::DrawShadowMeshRenderData(
    this,
    pRenderContext: v8,
    nCount: nTotalMeshCount,
    pRenderData: (ShadowMeshRenderData_t *)&v10,
    nTotalStripCount: nInstanceStride);
  v8->MatrixMode(this: v8, a2: MATERIAL_MODEL);
  v8->PopMatrix(this: v8);
  v8->SetNumBoneWeights(this: v8, a2: 0);
  v8->EndRender(this: v8);
  v8->Release(this: v8);
}

//------------------------------------------------------------------------------
// Address: 0x1004FB40
// Name: public: void CStudioRender::DrawModelArrayStaticProp(struct DrawModelInfo_t const __near &,struct StudioRenderContext_t const __near &,int,struct MeshInstanceData_t const __near *,struct ColorMeshInfo_t __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CStudioRender::DrawModelArrayStaticProp(
        CStudioRender *this,
        const DrawModelInfo_t *info,
        StudioRenderContext_t *rc,
        int nInstanceCount,
        const MeshInstanceData_t *pInstanceData,
        ColorMeshInfo_t **pColorMeshes)
{
  CStudioRender *v6; // esi
  IMatRenderContext *v7; // eax
  IMatRenderContext *m_pObject; // edi
  StudioRenderContext_t *m_pRC; // edx
  const DrawModelInfo_t *v10; // ebx
  bool v11; // cl
  StudioRenderContext_t *v12; // edx
  unsigned __int8 v13; // al
  int m_Lod; // eax
  studiohdr_t *m_pStudioHdr; // eax
  int v16; // ecx
  int skinindex; // ecx
  int m_Skin; // edx
  __int16 *v19; // ecx
  studiomeshdata_t *m_pStudioMeshes; // edx
  mstudiomesh_t *v21; // eax
  int meshid; // ecx
  bool v23; // zf
  studiohwdata_t *m_pHardwareData; // ecx
  studiomeshgroup_t *v25; // ebx
  IMesh *m_pMesh; // edi
  int v27; // eax
  const MeshInstanceData_t *v28; // esi
  OptimizedModel::StripHeader_t *v29; // esi
  IMesh_vtbl *v30; // ebx
  int PrimitiveTypeForStripHeaderFlags; // eax
  mstudiomodel_t *m_pSubModel; // edx
  int v33; // [esp-14h] [ebp-6Ch]
  void *m_pClientEntity; // [esp-10h] [ebp-68h]
  ColorMeshInfo_t *m_pColorMeshes; // [esp-Ch] [ebp-64h]
  int lod; // [esp+8h] [ebp-50h]
  Vector4D *p_m_DiffuseModulation; // [esp+10h] [ebp-48h]
  StudioModelLighting_t lighting; // [esp+14h] [ebp-44h] BYREF
  int i; // [esp+18h] [ebp-40h]
  int j; // [esp+1Ch] [ebp-3Ch]
  int strip; // [esp+20h] [ebp-38h]
  mstudiomesh_t *pmesh; // [esp+24h] [ebp-34h]
  int v44; // [esp+28h] [ebp-30h]
  int *pMaterialFlags; // [esp+2Ch] [ebp-2Ch]
  int nFacesPerModel; // [esp+30h] [ebp-28h]
  int v47; // [esp+34h] [ebp-24h]
  CMatRenderContextPtr pRenderContext; // [esp+38h] [ebp-20h]
  studiomeshdata_t *pMeshData; // [esp+3Ch] [ebp-1Ch]
  unsigned int v50; // [esp+40h] [ebp-18h]
  studiomeshgroup_t *pGroup; // [esp+44h] [ebp-14h]
  unsigned int v52; // [esp+48h] [ebp-10h]
  __int16 *pskinref; // [esp+4Ch] [ebp-Ch]
  int k; // [esp+50h] [ebp-8h]
  bool bWireframe; // [esp+57h] [ebp-1h]
  char flexConfig_3; // [esp+67h] [ebp+Fh]

  v6 = this;
  this->m_pRC = rc;
  v7 = g_pMaterialSystem->GetRenderContext(this: g_pMaterialSystem);
  m_pObject = v7;
  pRenderContext.m_pObject = v7;
  if ( v7 != nullptr )
    v7->BeginRender(this: v7);
  m_pObject->SetNumBoneWeights(this: m_pObject, a2: 0);
  m_pObject->MatrixMode(this: m_pObject, a2: MATERIAL_MODEL);
  m_pRC = v6->m_pRC;
  v10 = info;
  v11 = (*((_BYTE *)&m_pRC->m_Config.StudioRenderConfig_t + 36) & 0x40) != 0;
  *((_BYTE *)&m_pRC->m_Config.StudioRenderConfig_t + 36) &= ~0x40u;
  v12 = v6->m_pRC;
  v13 = *((_BYTE *)&v12->m_Config.StudioRenderConfig_t + 36);
  flexConfig_3 = v11;
  bWireframe = v13 >> 7;
  *((_BYTE *)&v12->m_Config.StudioRenderConfig_t + 36) = v13 & 0x7F;
  *((_BYTE *)v6 + 3685872) &= 0xFCu;
  m_Lod = info->m_Lod;
  v6->m_pStudioHdr = info->m_pStudioHdr;
  lod = m_Lod;
  m_Lod *= 32;
  v6->m_pStudioMeshes = *(studiomeshdata_t **)((char *)&info->m_pHardwareData->m_pLODs->m_pMeshData + m_Lod);
  v44 = m_Lod;
  v6->m_pStudioHWData = info->m_pHardwareData;
  m_pStudioHdr = v6->m_pStudioHdr;
  v16 = (int)m_pStudioHdr + m_pStudioHdr->bodypartindex + *(_DWORD *)&m_pStudioHdr->name[m_pStudioHdr->bodypartindex];
  v6->m_pSubModel = (mstudiomodel_t *)v16;
  j = v16;
  skinindex = m_pStudioHdr->skinindex;
  pMaterialFlags = *(int **)((char *)&info->m_pHardwareData->m_pLODs->pMaterialFlags + v44);
  m_Skin = info->m_Skin;
  v19 = (__int16 *)((char *)m_pStudioHdr + skinindex);
  pskinref = v19;
  if ( m_Skin > 0 && m_Skin < m_pStudioHdr->numskinfamilies )
    pskinref = &v19[m_Skin * m_pStudioHdr->numskinref];
  nFacesPerModel = 0;
  i = 0;
  if ( *(int *)(j + 72) > 0 )
  {
    v47 = 0;
    do
    {
      m_pStudioMeshes = v6->m_pStudioMeshes;
      v21 = (mstudiomesh_t *)&v6->m_pSubModel->name[v47 + v6->m_pSubModel->meshindex];
      meshid = v21->meshid;
      v23 = m_pStudioMeshes[meshid].m_NumGroup == 0;
      pmesh = v21;
      pMeshData = &m_pStudioMeshes[meshid];
      if ( !v23 && pMaterialFlags != nullptr )
      {
        m_pColorMeshes = v10->m_pColorMeshes;
        m_pClientEntity = v10->m_pClientEntity;
        v33 = pMaterialFlags[pskinref[v21->material]];
        m_pHardwareData = v10->m_pHardwareData;
        lighting = LIGHTING_HARDWARE;
        if ( CStudioRender::R_StudioSetupSkinAndLighting(
               this: v6,
               pRenderContext: m_pObject,
               index: pskinref[v21->material],
               ppMaterials: *(IMaterial ***)((char *)&m_pHardwareData->m_pLODs->ppMaterials + v44),
               materialFlags: v33,
               pClientRenderable: m_pClientEntity,
               pColorMeshes: m_pColorMeshes,
               &lighting) != nullptr )
        {
          j = 0;
          if ( pMeshData->m_NumGroup > 0 )
          {
            v50 = 0;
            do
            {
              v25 = &pMeshData->m_pMeshGroup[v50 / 0x2C];
              v23 = !v25->m_MeshNeedsRestore;
              pGroup = v25;
              if ( !v23 )
              {
                if ( (v25->m_pMesh->GetVertexFormat(this: v25->m_pMesh) & 0x400) != 0 )
                  CStudioRender::R_StudioRestoreMesh<1>(this: v6, pmesh, pMeshData: v25);
                CStudioRender::R_StudioRestoreMesh<0>(this: v6, pmesh, pMeshData: v25);
                v25->m_MeshNeedsRestore = false;
              }
              m_pMesh = v25->m_pMesh;
              v27 = 0;
              k = 0;
              if ( nInstanceCount > 0 )
              {
                while ( 1 )
                {
                  v28 = &pInstanceData[v27];
                  if ( v28->m_pEnvCubemap != nullptr )
                  {
                    pRenderContext.m_pObject->BindLocalCubemap(
                      this: pRenderContext.m_pObject,
                      a2: (ITexture *)v28->m_pEnvCubemap);
                    v27 = k;
                  }
                  if ( pColorMeshes[v27] != nullptr )
                    m_pMesh->SetColorMesh(
                      this: m_pMesh,
                      a2: pColorMeshes[v27][v25->m_ColorMeshID].m_pMesh,
                      a3: pColorMeshes[v27][v25->m_ColorMeshID].m_nVertOffsetInBytes);
                  else
                    m_pMesh->SetColorMesh(this: m_pMesh, a2: nullptr, a3: 0);
                  pRenderContext.m_pObject->LoadMatrix(this: pRenderContext.m_pObject, a2: v28->m_pPoseToWorld);
                  strip = 0;
                  if ( v25->m_NumStrips > 0 )
                  {
                    p_m_DiffuseModulation = &v28->m_DiffuseModulation;
                    v52 = 0;
                    do
                    {
                      v29 = &v25->m_pStripData[v52 / 0x23];
                      v30 = m_pMesh->IVertexBuffer::__vftable;
                      PrimitiveTypeForStripHeaderFlags = GetPrimitiveTypeForStripHeaderFlags(Flags: v29->flags);
                      v30->SetPrimitiveType(
                        this: m_pMesh,
                        a2: (MaterialPrimitiveType_t)PrimitiveTypeForStripHeaderFlags);
                      m_pMesh->DrawModulated(
                        this: m_pMesh,
                        a2: p_m_DiffuseModulation,
                        a3: v29->indexOffset,
                        a4: v29->numIndices);
                      if ( k == 0 )
                        nFacesPerModel += v29->numIndices / 3;
                      v52 += 35;
                      ++strip;
                      v25 = pGroup;
                    }
                    while ( strip < pGroup->m_NumStrips );
                  }
                  if ( ++k >= nInstanceCount )
                    break;
                  v27 = k;
                }
                v6 = this;
              }
              m_pMesh->SetColorMesh(this: m_pMesh, a2: nullptr, a3: 0);
              v50 += 44;
              ++j;
            }
            while ( j < pMeshData->m_NumGroup );
            m_pObject = pRenderContext.m_pObject;
            v10 = info;
          }
        }
      }
      m_pSubModel = v6->m_pSubModel;
      v47 += 116;
      ++i;
    }
    while ( i < m_pSubModel->nummeshes );
  }
  if ( mat_rendered_faces_count_0.m_pParent != nullptr && mat_rendered_faces_count_0.m_pParent->m_Value.m_nValue != 0
    || mat_print_top_model_vert_counts_0.m_pParent != nullptr
    && mat_print_top_model_vert_counts_0.m_pParent->m_Value.m_nValue != 0 )
  {
    studiohwdata_t::UpdateFacesRenderedCount(
      this: v6->m_pStudioHWData,
      pStudioHdr: v6->m_pStudioHdr,
      hwDataHash: &v6->m_ModelFaceCountHash,
      nLOD: lod,
      nInstances: nInstanceCount,
      nFacesOverride: nFacesPerModel);
  }
  *((_BYTE *)&v6->m_pRC->m_Config.StudioRenderConfig_t + 36) ^= (*((_BYTE *)&v6->m_pRC->m_Config.StudioRenderConfig_t
                                                                 + 36)
                                                               ^ (flexConfig_3 << 6))
                                                              & 0x40;
  *((_BYTE *)&v6->m_pRC->m_Config.StudioRenderConfig_t + 36) = *((_BYTE *)&v6->m_pRC->m_Config.StudioRenderConfig_t + 36)
                                                             & 0x7F
                                                             | (bWireframe << 7);
  v6->m_pRC = nullptr;
  v6->m_pStudioHdr = nullptr;
  v6->m_pStudioMeshes = nullptr;
  v6->m_pStudioHWData = nullptr;
  m_pObject->EndRender(this: m_pObject);
  m_pObject->Release(this: m_pObject);
}

//------------------------------------------------------------------------------
// Address: 0x1004FFB0
// Name: public: void CUtlLinkedList<struct CStudioRender::DecalMaterial_t,unsigned short,1,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<struct CStudioRender::DecalMaterial_t,unsigned short>,unsigned short>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CStudioRender::DecalMaterial_t,unsigned short,1,unsigned short,CUtlMemory<UtlLinkedListElem_t<CStudioRender::DecalMaterial_t,unsigned short>,unsigned short>>::RemoveAll(
        CUtlLinkedList<CStudioRender::DecalMaterial_t,unsigned short,1,unsigned short,CUtlMemory<UtlLinkedListElem_t<CStudioRender::DecalMaterial_t,unsigned short>,unsigned short> > *this)
{
  unsigned __int16 index; // dx
  unsigned __int16 v3; // si
  unsigned __int16 v4; // ax
  UtlLinkedListElem_t<CStudioRender::DecalMaterial_t,unsigned short> *v5; // edi
  CUtlMemory<UtlLinkedListElem_t<CStudioRender::DecalMaterial_t,unsigned short>,unsigned short>::Iterator_t it; // [esp+8h] [ebp-4h]

  index = this->m_LastAlloc.index;
  if ( index != 0xFFFF )
  {
    v3 = (this->m_Memory.m_nAllocationCount > 0) - 1;
    it.index = v3;
    if ( this->m_Memory.m_nAllocationCount > 0 )
    {
      do
      {
        v4 = v3;
        if ( v3 < this->m_Memory.m_nAllocationCount && v3 <= index )
        {
          v5 = &this->m_Memory.m_pMemory[v3];
          if ( v5->m_Previous != v3 || v5->m_Next == v3 )
          {
            CStudioRender::DecalMaterial_t::~DecalMaterial_t(this: &this->m_Memory.m_pMemory[v3].m_Element);
            v5->m_Previous = v3;
            v5->m_Next = this->m_FirstFree;
            v4 = v3;
            this->m_FirstFree = v3;
          }
        }
        index = this->m_LastAlloc.index;
        if ( v3 == index )
          break;
        v3 = v4 + 1;
        if ( (unsigned __int16)(it.index + 1) >= this->m_Memory.m_nAllocationCount )
          v3 = -1;
        it.index = v3;
      }
      while ( v3 != 0xFFFF );
    }
    *(_DWORD *)&this->m_Head = -1;
    this->m_ElementCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10050070
// Name: void UpdateAndSpewFacesRenderedHistory(class CUtlVector<struct IStudioRender::FacesRenderedInfo_t,class CUtlMemory<struct IStudioRender::FacesRenderedInfo_t,int>> __near &,int,int,int,bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl UpdateAndSpewFacesRenderedHistory(
        CUtlVector<IStudioRender::FacesRenderedInfo_t,CUtlMemory<IStudioRender::FacesRenderedInfo_t,int> > *newItems,
        int nTotal,
        int nSpewFromCurrentFrame,
        int nSpewFromHistory,
        bool bClearHistory)
{
  int v5; // ecx
  int v6; // ebx
  int v7; // ecx
  int v8; // edi
  IStudioRender::FacesRenderedInfo_t *v9; // eax
  int *p_m_nGrowSize; // edx
  int *v11; // edx
  int *v12; // edx
  int *v13; // edx
  int *v14; // edx
  int m_Size; // edi
  unsigned int v16; // edi
  unsigned int nRenderCount; // ebx
  char *name; // edx
  double v19; // st7
  CUtlVector<IStudioRender::FacesRenderedInfo_t,CUtlMemory<IStudioRender::FacesRenderedInfo_t,int> > *m_pMemory; // edi
  int *v21; // eax
  int i; // ecx
  int v23; // ebx
  IStudioRender::FacesRenderedInfo_t *v24; // esi
  unsigned int v25; // eax
  IStudioRender::FacesRenderedInfo_t *v26; // eax
  unsigned int v27; // ecx
  IStudioRender::FacesRenderedInfo_t *v28; // edx
  unsigned int v29; // eax
  int v30; // eax
  signed int v31; // ebx
  int *p_m_Size; // ecx
  int v33; // eax
  unsigned int k; // edi
  signed int v35; // esi
  IStudioRender::FacesRenderedInfo_t *v36; // eax
  signed int v37; // eax
  int v38; // ecx
  int *v39; // edx
  IStudioRender::FacesRenderedInfo_t *v40; // edi
  int v41; // edx
  int v42; // eax
  unsigned int *m; // esi
  int v44; // ecx
  unsigned int v45; // edi
  unsigned int v46; // ecx
  CUtlVector<IStudioRender::FacesRenderedInfo_t,CUtlMemory<IStudioRender::FacesRenderedInfo_t,int> > *v47; // esi
  int n; // ebx
  const char *v49; // [esp-10h] [ebp-54h]
  CUtlHash<IStudioRender::FacesRenderedInfo_t,bool (__cdecl*)(IStudioRender::FacesRenderedInfo_t const &,IStudioRender::FacesRenderedInfo_t const &),unsigned int (__cdecl*)(IStudioRender::FacesRenderedInfo_t const &)> topItemHash; // [esp+0h] [ebp-44h] BYREF
  CUtlMemory<IStudioRender::FacesRenderedInfo_t,int> v51; // [esp+24h] [ebp-20h] BYREF
  signed int v52; // [esp+30h] [ebp-14h]
  IStudioRender::FacesRenderedInfo_t *v53; // [esp+34h] [ebp-10h]
  unsigned int nFaceCount; // [esp+38h] [ebp-Ch] BYREF
  unsigned int pBucket; // [esp+3Ch] [ebp-8h] BYREF
  int pIndex; // [esp+40h] [ebp-4h] BYREF
  int j; // [esp+5Ch] [ebp+18h]
  int ja; // [esp+5Ch] [ebp+18h]
  IStudioRender::FacesRenderedInfo_t *jb; // [esp+5Ch] [ebp+18h]
  int jc; // [esp+5Ch] [ebp+18h]

  v51.m_nGrowSize = 0;
  v52 = 0;
  v53 = nullptr;
  if ( bClearHistory )
  {
    nOldestItem = 0;
    nItems = 0;
  }
  else if ( nTotal != 0 )
  {
    v5 = nItems;
    v6 = (nOldestItem + nItems) % 20;
    if ( nItems == 20 )
      nOldestItem = (nOldestItem + 1) % 20;
    ++nItems;
    if ( v5 + 1 >= 20 )
      nItems = 20;
    v7 = 2;
    v8 = 3;
    v9 = &history[v6][1];
    do
    {
      if ( v7 - 2 >= newItems->m_Size )
        p_m_nGrowSize = &v51.m_nGrowSize;
      else
        p_m_nGrowSize = (int *)&newItems->m_Memory.m_pMemory[v8 - 3];
      *(_QWORD *)&v9[-1].pStudioHdr = *(_QWORD *)p_m_nGrowSize;
      v9[-1].nRenderCount = p_m_nGrowSize[2];
      if ( v7 - 1 >= newItems->m_Size )
        v11 = &v51.m_nGrowSize;
      else
        v11 = (int *)&newItems->m_Memory.m_pMemory[v8 - 2];
      *(_QWORD *)&v9->pStudioHdr = *(_QWORD *)v11;
      v9->nRenderCount = v11[2];
      if ( v7 >= newItems->m_Size )
        v12 = &v51.m_nGrowSize;
      else
        v12 = (int *)&newItems->m_Memory.m_pMemory[v8 - 1];
      *(_QWORD *)&v9[1].pStudioHdr = *(_QWORD *)v12;
      v9[1].nRenderCount = v12[2];
      if ( v7 + 1 >= newItems->m_Size )
        v13 = &v51.m_nGrowSize;
      else
        v13 = (int *)&newItems->m_Memory.m_pMemory[v8];
      *(_QWORD *)&v9[2].pStudioHdr = *(_QWORD *)v13;
      v9[2].nRenderCount = v13[2];
      if ( v7 + 2 >= newItems->m_Size )
        v14 = &v51.m_nGrowSize;
      else
        v14 = (int *)&newItems->m_Memory.m_pMemory[v8 + 1];
      *(_QWORD *)&v9[3].pStudioHdr = *(_QWORD *)v14;
      v7 += 5;
      v9[3].nRenderCount = v14[2];
      v8 += 5;
      v9 += 5;
    }
    while ( v7 - 2 < 20 );
    m_Size = nSpewFromCurrentFrame;
    if ( nSpewFromCurrentFrame >= newItems->m_Size )
      m_Size = newItems->m_Size;
    if ( m_Size != 0 )
    {
      _Msg(a1: "Faces rendered this frame, by model:\n");
      if ( m_Size > 0 )
      {
        j = 0;
        for ( pIndex = m_Size; pIndex != 0; --pIndex )
        {
          nRenderCount = newItems->m_Memory.m_pMemory[j].nRenderCount;
          name = newItems->m_Memory.m_pMemory[j].pStudioHdr->name;
          nFaceCount = newItems->m_Memory.m_pMemory[j].nFaceCount;
          v16 = nFaceCount;
          v19 = (double)nFaceCount;
          nFaceCount = nRenderCount;
          _Msg(a1: "%-7d (%-3d times, %-7d avg) %s\n", v16, nRenderCount, (int)(v19 / (double)nRenderCount), name);
          ++j;
        }
      }
    }
    else if ( lastSpewTime + 0.25 <= _Plat_FloatTime() )
    {
      lastSpewTime = _Plat_FloatTime();
      memset(&topItemHash, 0, 20);
      topItemHash.m_CompareFunc = (bool (__cdecl *)(const IStudioRender::FacesRenderedInfo_t *, const IStudioRender::FacesRenderedInfo_t *))FacesRenderedInfoCompareFunc;
      topItemHash.m_KeyFunc = FacesRenderedInfoKeyFunc;
      CUtlVector<CUtlVector<IStudioRender::FacesRenderedInfo_t,CUtlMemory<IStudioRender::FacesRenderedInfo_t,int>>,CUtlMemory<CUtlVector<IStudioRender::FacesRenderedInfo_t,CUtlMemory<IStudioRender::FacesRenderedInfo_t,int>>,int>>::RemoveAll(this: (CUtlVector<CUtlVector<studiohwdata_t *,CUtlMemory<studiohwdata_t *,int> >,CUtlMemory<CUtlVector<studiohwdata_t *,CUtlMemory<studiohwdata_t *,int> >,int> > *)&topItemHash);
      CUtlVector<CUtlVector<IStudioRender::FacesRenderedInfo_t,CUtlMemory<IStudioRender::FacesRenderedInfo_t,int>>,CUtlMemory<CUtlVector<IStudioRender::FacesRenderedInfo_t,CUtlMemory<IStudioRender::FacesRenderedInfo_t,int>>,int>>::InsertMultipleBefore(
        this: &topItemHash.m_Buckets,
        elem: topItemHash.m_Buckets.m_Size,
        num: 64);
      m_pMemory = topItemHash.m_Buckets.m_Memory.m_pMemory;
      v21 = &topItemHash.m_Buckets.m_Memory.m_pMemory->m_Memory.m_nGrowSize;
      for ( i = 64; i != 0; --i )
      {
        v21[1] = 0;
        *v21 = 0;
        v21 += 5;
      }
      topItemHash.m_bPowerOfTwo = true;
      topItemHash.m_ModMask = 63;
      for ( ja = 0; ja < nItems; ++ja )
      {
        v23 = 20;
        v24 = history[(ja + nOldestItem) % 20];
        do
        {
          if ( v24->nFaceCount != 0 )
          {
            pIndex = 0;
            if ( CUtlHash<IStudioRender::FacesRenderedInfo_t,bool (__cdecl *)(IStudioRender::FacesRenderedInfo_t const &,IStudioRender::FacesRenderedInfo_t const &),unsigned int (__cdecl *)(IStudioRender::FacesRenderedInfo_t const &)>::DoFind(
                   this: &topItemHash,
                   src: v24,
                   &pBucket,
                   &pIndex) == 0
              || (v25 = pIndex | (pBucket << 16)) == -1 )
            {
              if ( CUtlHash<IStudioRender::FacesRenderedInfo_t,bool (__cdecl *)(IStudioRender::FacesRenderedInfo_t const &,IStudioRender::FacesRenderedInfo_t const &),unsigned int (__cdecl *)(IStudioRender::FacesRenderedInfo_t const &)>::DoFind(
                     this: &topItemHash,
                     src: v24,
                     pBucket: &nFaceCount,
                     &pIndex) == 0 )
                CUtlVector<IStudioRender::FacesRenderedInfo_t,CUtlMemory<IStudioRender::FacesRenderedInfo_t,int>>::InsertBefore(
                  this: &m_pMemory[nFaceCount],
                  elem: m_pMemory[nFaceCount].m_Size,
                  src: v24);
            }
            else
            {
              v26 = m_pMemory[HIWORD(v25)].m_Memory.m_pMemory;
              v27 = v26[(unsigned __int16)pIndex].nFaceCount;
              v28 = &v26[(unsigned __int16)pIndex];
              v29 = v24->nFaceCount;
              if ( v29 <= v27 )
                v29 = v27;
              v28->nFaceCount = v29;
            }
          }
          ++v24;
          --v23;
        }
        while ( v23 != 0 );
      }
      v30 = 0;
      v31 = 0;
      memset(&v51, 0, sizeof(v51));
      v52 = 0;
      v53 = nullptr;
      if ( topItemHash.m_Buckets.m_Size <= 0 )
      {
LABEL_51:
        v33 = -1;
      }
      else
      {
        p_m_Size = &m_pMemory->m_Size;
        while ( *p_m_Size <= 0 )
        {
          ++v30;
          p_m_Size += 5;
          if ( v30 >= topItemHash.m_Buckets.m_Size )
            goto LABEL_51;
        }
        v33 = v30 << 16;
      }
      for ( k = v33; k != -1; k = v38 | (v37 << 16) )
      {
        jb = &topItemHash.m_Buckets.m_Memory.m_pMemory[HIWORD(k)].m_Memory.m_pMemory[(unsigned __int16)k];
        v35 = v31;
        if ( v31 + 1 > v51.m_nAllocationCount )
        {
          CUtlMemory<IStudioRender::FacesRenderedInfo_t,int>::Grow(this: &v51, num: v31 - v51.m_nAllocationCount + 1);
          v31 = v52;
        }
        v52 = ++v31;
        v53 = v51.m_pMemory;
        if ( v31 - v35 - 1 > 0 )
          _V_memmove(dest: &v51.m_pMemory[v35 + 1], src: &v51.m_pMemory[v35], count: 12 * (v31 - v35 - 1));
        v36 = &v51.m_pMemory[v35];
        if ( v36 != nullptr )
        {
          *(_QWORD *)&v36->pStudioHdr = *(_QWORD *)&jb->pStudioHdr;
          v36->nRenderCount = jb->nRenderCount;
        }
        v37 = (k + 1) >> 16;
        v38 = (unsigned __int16)(k + 1);
        if ( v37 >= topItemHash.m_Buckets.m_Size )
          break;
        v39 = &topItemHash.m_Buckets.m_Memory.m_pMemory[v37].m_Size;
        while ( v38 >= *v39 )
        {
          ++v37;
          v38 = 0;
          v39 += 5;
          if ( v37 >= topItemHash.m_Buckets.m_Size )
            goto LABEL_66;
        }
      }
LABEL_66:
      v40 = v51.m_pMemory;
      qsort(
        base: v51.m_pMemory,
        num: v31,
        width: 0xCu,
        comp: (int (__cdecl *)(const void *, const void *))FacesRenderedInfoSort);
      v41 = nSpewFromHistory;
      v42 = 0;
      for ( m = &v40->nFaceCount; ; m += 3 )
      {
        jc = v42;
        v44 = v41;
        if ( v41 >= 20 )
          v44 = 20;
        if ( v42 >= v44 )
          break;
        if ( v42 < v31 )
        {
          v45 = *m;
          v46 = *m;
          v49 = (const char *)(*(m - 1) + 12);
          nFaceCount = m[1];
          ConMsg(a1: "%-7d (%-3d times, %-7d avg) %s\n", v45, nFaceCount, (int)((double)v46 / (double)nFaceCount), v49);
          v42 = jc;
          v41 = nSpewFromHistory;
          v31 = v52;
          v40 = v51.m_pMemory;
        }
        ++v42;
      }
      ConMsg(a1: "%-7d total model faces rendered this frame (mat_rendered_faces_count)\n", nTotal);
      if ( v51.m_nGrowSize >= 0 && v40 != nullptr )
        free(pMem: v40);
      if ( topItemHash.m_Buckets.m_Size > 0 )
      {
        v47 = topItemHash.m_Buckets.m_Memory.m_pMemory;
        for ( n = topItemHash.m_Buckets.m_Size; n != 0; --n )
        {
          v47->m_Size = 0;
          if ( v47->m_Memory.m_nGrowSize >= 0 )
          {
            if ( v47->m_Memory.m_pMemory != nullptr )
            {
              free(pMem: v47->m_Memory.m_pMemory);
              v47->m_Memory.m_pMemory = nullptr;
            }
            v47->m_Memory.m_nAllocationCount = 0;
          }
          v47->m_pElements = v47->m_Memory.m_pMemory;
          ++v47;
        }
      }
      CUtlVector<CUtlVector<IStudioRender::FacesRenderedInfo_t,CUtlMemory<IStudioRender::FacesRenderedInfo_t,int>>,CUtlMemory<CUtlVector<IStudioRender::FacesRenderedInfo_t,CUtlMemory<IStudioRender::FacesRenderedInfo_t,int>>,int>>::RemoveAll(this: (CUtlVector<CUtlVector<studiohwdata_t *,CUtlMemory<studiohwdata_t *,int> >,CUtlMemory<CUtlVector<studiohwdata_t *,CUtlMemory<studiohwdata_t *,int> >,int> > *)&topItemHash);
      if ( topItemHash.m_Buckets.m_Memory.m_nGrowSize >= 0 && topItemHash.m_Buckets.m_Memory.m_pMemory != nullptr )
        free(pMem: topItemHash.m_Buckets.m_Memory.m_pMemory);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100505B0
// Name: public: void CStudioRender::UpdateModelFaceCounts(int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CStudioRender::UpdateModelFaceCounts(
        CStudioRender *this,
        int nSpewFromCurrentFrame,
        bool bClearHistory)
{
  IStudioRender::FacesRenderedInfo_t *m_pMemory; // edx
  int v4; // eax
  int m_nValue; // ecx
  CUtlVector<IStudioRender::FacesRenderedInfo_t,CUtlMemory<IStudioRender::FacesRenderedInfo_t,int> > items; // [esp+4h] [ebp-14h] BYREF

  m_pMemory = nullptr;
  memset(&items, 0, sizeof(items));
  if ( bClearHistory )
  {
    nOldestItem = 0;
    nItems = 0;
  }
  else if ( mat_rendered_faces_count_0.m_pParent != nullptr
         && mat_rendered_faces_count_0.m_pParent->m_Value.m_nValue != 0 )
  {
    v4 = BuildFacesRenderedInfoListForMostRecentFrame(&items, hash: &this->m_ModelFaceCountHash);
    if ( mat_rendered_faces_count_0.m_pParent != nullptr )
      m_nValue = mat_rendered_faces_count_0.m_pParent->m_Value.m_nValue;
    else
      m_nValue = 0;
    UpdateAndSpewFacesRenderedHistory(
      newItems: &items,
      nTotal: v4,
      nSpewFromCurrentFrame,
      nSpewFromHistory: m_nValue,
      bClearHistory: false);
    ConVar::SetValue(this: (ConVar *)&mat_rendered_faces_count_0.IConVar, value: 0);
    m_pMemory = items.m_Memory.m_pMemory;
  }
  if ( items.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
    free(pMem: m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x10050650
// Name: mat_rendered_faces_spew
// Source: json
//------------------------------------------------------------------------------
void __cdecl mat_rendered_faces_spew(const CCommand *args)
{
  int v1; // eax

  if ( args->m_nArgc <= 1 )
    v1 = 0x7FFFFFFF;
  else
    v1 = V_atoi(str: args->m_ppArgv[1]);
  if ( mat_rendered_faces_count_0.m_pParent != nullptr && mat_rendered_faces_count_0.m_pParent->m_Value.m_nValue != 0 )
    CStudioRender::UpdateModelFaceCounts(this: &g_StudioRender, nSpewFromCurrentFrame: v1, bClearHistory: false);
  else
    _Msg(a1: "ERROR: mat_rendered_faces_count must be set in order to use mat_rendered_faces_spew\n");
}

//------------------------------------------------------------------------------
// Address: 0x100506B0
// Name: public: CUtlHash<struct studiohwdata_t __near *,bool (*)(struct studiohwdata_t __near * const __near &,struct studiohwdata_t __near * const __near &),unsigned int (*)(struct studiohwdata_t __near * const __near &)>::~CUtlHash<struct studiohwdata_t __near *,bool (*)(struct studiohwdata_t __near * const __near &,struct studiohwdata_t __near * const __near &),unsigned int (*)(struct studiohwdata_t __near * const __near &)>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlHash<studiohwdata_t *,bool (__cdecl *)(studiohwdata_t * const &,studiohwdata_t * const &),unsigned int (__cdecl *)(studiohwdata_t * const &)>::~CUtlHash<studiohwdata_t *,bool (__cdecl *)(studiohwdata_t * const &,studiohwdata_t * const &),unsigned int (__cdecl *)(studiohwdata_t * const &)>(
        CUtlHash<studiohwdata_t *,bool (__cdecl*)(studiohwdata_t * const &,studiohwdata_t * const &),unsigned int (__cdecl*)(studiohwdata_t * const &)> *this)
{
  bool v2; // sf
  CUtlVector<studiohwdata_t *,CUtlMemory<studiohwdata_t *,int> > *m_pMemory; // eax

  CUtlHash<studiohwdata_t *,bool (__cdecl *)(studiohwdata_t * const &,studiohwdata_t * const &),unsigned int (__cdecl *)(studiohwdata_t * const &)>::Purge(this);
  CUtlVector<CUtlVector<IStudioRender::FacesRenderedInfo_t,CUtlMemory<IStudioRender::FacesRenderedInfo_t,int>>,CUtlMemory<CUtlVector<IStudioRender::FacesRenderedInfo_t,CUtlMemory<IStudioRender::FacesRenderedInfo_t,int>>,int>>::RemoveAll(this: &this->m_Buckets);
  if ( this->m_Buckets.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Buckets.m_Memory.m_pMemory != nullptr )
    {
      free(pMem: this->m_Buckets.m_Memory.m_pMemory);
      this->m_Buckets.m_Memory.m_pMemory = nullptr;
    }
    this->m_Buckets.m_Memory.m_nAllocationCount = 0;
  }
  v2 = this->m_Buckets.m_Memory.m_nGrowSize < 0;
  m_pMemory = this->m_Buckets.m_Memory.m_pMemory;
  this->m_Buckets.m_pElements = this->m_Buckets.m_Memory.m_pMemory;
  if ( !v2 )
  {
    if ( m_pMemory != nullptr )
    {
      free(pMem: m_pMemory);
      this->m_Buckets.m_Memory.m_pMemory = nullptr;
    }
    this->m_Buckets.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10050710
// Name: public: void CStudioRender::EndFrame(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CStudioRender::EndFrame(CStudioRender *this)
{
  CStudioRender::UpdateModelFaceCounts(this, nSpewFromCurrentFrame: 0, bClearHistory: false);
}

//------------------------------------------------------------------------------
// Address: 0x10050720
// Name: public: CCachedRenderData::~CCachedRenderData(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCachedRenderData::~CCachedRenderData(CCachedRenderData *this)
{
  CUtlVector<CUtlVector<CUtlVector<CCachedRenderData::CacheDict_t,CUtlMemory<CCachedRenderData::CacheDict_t,int> >,CUtlMemory<CUtlVector<CCachedRenderData::CacheDict_t,CUtlMemory<CCachedRenderData::CacheDict_t,int> >,int> >,CUtlMemory<CUtlVector<CUtlVector<CCachedRenderData::CacheDict_t,CUtlMemory<CCachedRenderData::CacheDict_t,int> >,CUtlMemory<CUtlVector<CCachedRenderData::CacheDict_t,CUtlMemory<CCachedRenderData::CacheDict_t,int> >,int> >,int> > *p_m_CacheDict; // esi
  bool v2; // sf
  CUtlVector<CUtlVector<CCachedRenderData::CacheDict_t,CUtlMemory<CCachedRenderData::CacheDict_t,int> >,CUtlMemory<CUtlVector<CCachedRenderData::CacheDict_t,CUtlMemory<CCachedRenderData::CacheDict_t,int> >,int> > *m_pMemory; // eax

  p_m_CacheDict = &this->m_CacheDict;
  CUtlVector<CUtlVector<CUtlVector<CCachedRenderData::CacheDict_t,CUtlMemory<CCachedRenderData::CacheDict_t,int>>,CUtlMemory<CUtlVector<CCachedRenderData::CacheDict_t,CUtlMemory<CCachedRenderData::CacheDict_t,int>>,int>>,CUtlMemory<CUtlVector<CUtlVector<CCachedRenderData::CacheDict_t,CUtlMemory<CCachedRenderData::CacheDict_t,int>>,CUtlMemory<CUtlVector<CCachedRenderData::CacheDict_t,CUtlMemory<CCachedRenderData::CacheDict_t,int>>,int>>,int>>::RemoveAll(this: &this->m_CacheDict);
  if ( p_m_CacheDict->m_Memory.m_nGrowSize >= 0 )
  {
    if ( p_m_CacheDict->m_Memory.m_pMemory != nullptr )
    {
      free(pMem: p_m_CacheDict->m_Memory.m_pMemory);
      p_m_CacheDict->m_Memory.m_pMemory = nullptr;
    }
    p_m_CacheDict->m_Memory.m_nAllocationCount = 0;
  }
  v2 = p_m_CacheDict->m_Memory.m_nGrowSize < 0;
  m_pMemory = p_m_CacheDict->m_Memory.m_pMemory;
  p_m_CacheDict->m_pElements = p_m_CacheDict->m_Memory.m_pMemory;
  if ( !v2 )
  {
    if ( m_pMemory != nullptr )
    {
      free(pMem: m_pMemory);
      p_m_CacheDict->m_Memory.m_pMemory = nullptr;
    }
    p_m_CacheDict->m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10050780
// Name: public: CStudioRender::~CStudioRender(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CStudioRender::~CStudioRender(CStudioRender *this)
{
  matrix3x4_t *m_PoseToWorld; // eax
  matrix3x4_t *m_PoseToDecal; // eax
  CUtlFixedMemory<UtlLinkedListElem_t<CStudioRender::DecalLRU_t,int> >::BlockHeader_t *m_pBlocks; // edi
  CStudioRender::ShadowState_t *m_pMemory; // eax
  CUtlFixedMemory<UtlLinkedListElem_t<CStudioRender::DecalModelList_t,int> >::BlockHeader_t *v6; // edi
  CUtlFixedMemory<UtlLinkedListElem_t<CStudioRender::DecalLRU_t,int> >::BlockHeader_t *v7; // [esp-8h] [ebp-10h]
  CUtlFixedMemory<UtlLinkedListElem_t<CStudioRender::DecalModelList_t,int> >::BlockHeader_t *v8; // [esp-8h] [ebp-10h]

  m_PoseToWorld = this->m_PoseToWorld;
  if ( m_PoseToWorld != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *(void **)(((unsigned int)m_PoseToWorld & 0xFFFFFFFC) - 4));
  m_PoseToDecal = this->m_PoseToDecal;
  if ( m_PoseToDecal != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *(void **)(((unsigned int)m_PoseToDecal & 0xFFFFFFFC) - 4));
  CUtlHash<studiohwdata_t *,bool (__cdecl *)(studiohwdata_t * const &,studiohwdata_t * const &),unsigned int (__cdecl *)(studiohwdata_t * const &)>::~CUtlHash<studiohwdata_t *,bool (__cdecl *)(studiohwdata_t * const &,studiohwdata_t * const &),unsigned int (__cdecl *)(studiohwdata_t * const &)>(this: &this->m_ModelFaceCountHash);
  CUtlVector<__m128,CUtlMemoryAligned<__m128,16>>::~CUtlVector<__m128,CUtlMemoryAligned<__m128,16>>(this: &this->m_vSkinnedSubDVertices);
  CUtlLinkedList<CStudioRender::DecalLRU_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CStudioRender::DecalLRU_t,int>>>::RemoveAll(this: &this->m_DecalLRU);
  if ( this->m_DecalLRU.m_Memory.m_pBlocks != nullptr )
  {
    m_pBlocks = this->m_DecalLRU.m_Memory.m_pBlocks;
    do
    {
      v7 = m_pBlocks;
      m_pBlocks = m_pBlocks->m_pNext;
      free(pMem: v7);
    }
    while ( m_pBlocks != nullptr );
    this->m_DecalLRU.m_Memory.m_pBlocks = nullptr;
    this->m_DecalLRU.m_Memory.m_nAllocationCount = 0;
  }
  CCachedRenderData::~CCachedRenderData(this: &this->m_VertexCache);
  this->m_ShadowState.m_Size = 0;
  if ( this->m_ShadowState.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_ShadowState.m_Memory.m_pMemory != nullptr )
    {
      free(pMem: this->m_ShadowState.m_Memory.m_pMemory);
      this->m_ShadowState.m_Memory.m_pMemory = nullptr;
    }
    this->m_ShadowState.m_Memory.m_nAllocationCount = 0;
  }
  m_pMemory = this->m_ShadowState.m_Memory.m_pMemory;
  this->m_ShadowState.m_pElements = m_pMemory;
  if ( this->m_ShadowState.m_Memory.m_nGrowSize >= 0 )
  {
    if ( m_pMemory != nullptr )
    {
      free(pMem: m_pMemory);
      this->m_ShadowState.m_Memory.m_pMemory = nullptr;
    }
    this->m_ShadowState.m_Memory.m_nAllocationCount = 0;
  }
  CUtlLinkedList<CStudioRender::DecalModelList_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CStudioRender::DecalModelList_t,int>>>::RemoveAll(this: &this->m_DecalList);
  v6 = this->m_DecalList.m_Memory.m_pBlocks;
  if ( v6 != nullptr )
  {
    do
    {
      v8 = v6;
      v6 = v6->m_pNext;
      free(pMem: v8);
    }
    while ( v6 != nullptr );
    this->m_DecalList.m_Memory.m_pBlocks = nullptr;
    this->m_DecalList.m_Memory.m_nAllocationCount = 0;
  }
  CUtlLinkedList<CStudioRender::DecalMaterial_t,unsigned short,1,unsigned short,CUtlMemory<UtlLinkedListElem_t<CStudioRender::DecalMaterial_t,unsigned short>,unsigned short>>::RemoveAll(this: &this->m_DecalMaterial);
  if ( this->m_DecalMaterial.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_DecalMaterial.m_Memory.m_pMemory != nullptr )
    {
      free(pMem: this->m_DecalMaterial.m_Memory.m_pMemory);
      this->m_DecalMaterial.m_Memory.m_pMemory = nullptr;
    }
    this->m_DecalMaterial.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100508B0
// Name: public: CStudioRender::CStudioRender(void)
// Source: json
//------------------------------------------------------------------------------
CStudioRender *__thiscall CStudioRender::CStudioRender(CStudioRender *this)
{
  UtlLinkedListElem_t<CStudioRender::DecalMaterial_t,unsigned short> *m_pMemory; // eax
  int i; // eax
  void *v4; // eax
  matrix3x4_t *v5; // ecx
  void *v6; // eax
  matrix3x4_t *v7; // ecx

  this->m_DecalMaterial.m_Memory.m_pMemory = nullptr;
  this->m_DecalMaterial.m_Memory.m_nAllocationCount = 0;
  this->m_DecalMaterial.m_Memory.m_nGrowSize = 0;
  this->m_DecalMaterial.m_LastAlloc.index = -1;
  *(_DWORD *)&this->m_DecalMaterial.m_FirstFree = 0xFFFF;
  m_pMemory = this->m_DecalMaterial.m_Memory.m_pMemory;
  *(_DWORD *)&this->m_DecalMaterial.m_Head = -1;
  this->m_DecalMaterial.m_pElements = m_pMemory;
  this->m_DecalMaterial.m_NumAlloced = 0;
  this->m_DecalList.m_Memory.m_pBlocks = nullptr;
  this->m_DecalList.m_Memory.m_nAllocationCount = 0;
  this->m_DecalList.m_Memory.m_nGrowSize = 0;
  this->m_DecalList.m_LastAlloc.m_pBlockHeader = nullptr;
  this->m_DecalList.m_LastAlloc.m_nIndex = -1;
  this->m_DecalList.m_Head = 0;
  this->m_DecalList.m_Tail = 0;
  this->m_DecalList.m_FirstFree = 0;
  this->m_DecalList.m_ElementCount = 0;
  this->m_DecalList.m_NumAlloced = 0;
  this->m_DecalList.m_pElements = nullptr;
  this->m_DecalMutex.m_ownerID = 0;
  this->m_DecalMutex.m_depth = 0;
  this->m_ShadowState.m_Memory.m_pMemory = nullptr;
  this->m_ShadowState.m_Memory.m_nAllocationCount = 0;
  this->m_ShadowState.m_Memory.m_nGrowSize = 0;
  this->m_ShadowState.m_Size = 0;
  this->m_ShadowState.m_pElements = nullptr;
  CCachedRenderData::CCachedRenderData(this: &this->m_VertexCache);
  this->m_DecalLRU.m_Memory.m_pBlocks = nullptr;
  this->m_DecalLRU.m_Memory.m_nAllocationCount = 0;
  this->m_DecalLRU.m_Memory.m_nGrowSize = 0;
  this->m_DecalLRU.m_LastAlloc.m_pBlockHeader = nullptr;
  this->m_DecalLRU.m_LastAlloc.m_nIndex = -1;
  this->m_DecalLRU.m_Head = 0;
  this->m_DecalLRU.m_Tail = 0;
  this->m_DecalLRU.m_FirstFree = 0;
  this->m_DecalLRU.m_ElementCount = 0;
  this->m_DecalLRU.m_NumAlloced = 0;
  this->m_DecalLRU.m_pElements = nullptr;
  this->m_vSkinnedSubDVertices.m_Memory.m_pMemory = nullptr;
  this->m_vSkinnedSubDVertices.m_Memory.m_nAllocationCount = 0;
  this->m_vSkinnedSubDVertices.m_Memory.m_nGrowSize = 0;
  this->m_vSkinnedSubDVertices.m_Size = 0;
  this->m_vSkinnedSubDVertices.m_pElements = nullptr;
  this->m_ModelFaceCountHash.m_Buckets.m_Memory.m_pMemory = nullptr;
  this->m_ModelFaceCountHash.m_Buckets.m_Memory.m_nAllocationCount = 0;
  this->m_ModelFaceCountHash.m_Buckets.m_Memory.m_nGrowSize = 0;
  this->m_ModelFaceCountHash.m_Buckets.m_Size = 0;
  this->m_ModelFaceCountHash.m_Buckets.m_pElements = nullptr;
  this->m_ModelFaceCountHash.m_CompareFunc = (bool (__cdecl *)(studiohwdata_t *const *, studiohwdata_t *const *))FacesRenderedInfoCompareFunc;
  this->m_ModelFaceCountHash.m_KeyFunc = (unsigned int (__cdecl *)(studiohwdata_t *const *))FacesRenderedInfoKeyFunc;
  CUtlVector<CUtlVector<IStudioRender::FacesRenderedInfo_t,CUtlMemory<IStudioRender::FacesRenderedInfo_t,int>>,CUtlMemory<CUtlVector<IStudioRender::FacesRenderedInfo_t,CUtlMemory<IStudioRender::FacesRenderedInfo_t,int>>,int>>::RemoveAll(this: &this->m_ModelFaceCountHash.m_Buckets);
  CUtlVector<CUtlVector<IStudioRender::FacesRenderedInfo_t,CUtlMemory<IStudioRender::FacesRenderedInfo_t,int>>,CUtlMemory<CUtlVector<IStudioRender::FacesRenderedInfo_t,CUtlMemory<IStudioRender::FacesRenderedInfo_t,int>>,int>>::InsertMultipleBefore(
    this: (CUtlVector<CUtlVector<IStudioRender::FacesRenderedInfo_t,CUtlMemory<IStudioRender::FacesRenderedInfo_t,int> >,CUtlMemory<CUtlVector<IStudioRender::FacesRenderedInfo_t,CUtlMemory<IStudioRender::FacesRenderedInfo_t,int> >,int> > *)&this->m_ModelFaceCountHash,
    elem: this->m_ModelFaceCountHash.m_Buckets.m_Size,
    num: 1024);
  for ( i = 0; i < 1024; ++i )
  {
    this->m_ModelFaceCountHash.m_Buckets.m_Memory.m_pMemory[i].m_Size = 0;
    this->m_ModelFaceCountHash.m_Buckets.m_Memory.m_pMemory[i].m_Memory.m_nGrowSize = 0;
  }
  this->m_ModelFaceCountHash.m_bPowerOfTwo = true;
  this->m_ModelFaceCountHash.m_ModMask = 1023;
  this->m_pRC = nullptr;
  this->m_pBoneToWorld = nullptr;
  this->m_pFlexWeights = nullptr;
  this->m_pFlexDelayedWeights = nullptr;
  this->m_pStudioHdr = nullptr;
  this->m_pStudioMeshes = nullptr;
  this->m_pSubModel = nullptr;
  this->m_pStudioHWData = nullptr;
  this->m_pGlintTexture = nullptr;
  *(_DWORD *)&this->m_GlintWidth = 0;
  this->m_pCurrentFlashlight = nullptr;
  _g_pMemAlloc->PushAllocDbgInfo(this: _g_pMemAlloc, a2: "studiorender.cpp", a3: 82);
  v4 = _g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 12323);
  if ( v4 != nullptr )
  {
    v5 = (matrix3x4_t *)(((unsigned int)v4 + 35) & 0xFFFFFFE0);
    LODWORD(v5[-1].m_flMatVal[2][3]) = v4;
  }
  else
  {
    v5 = nullptr;
  }
  this->m_PoseToWorld = v5;
  v6 = _g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 12323);
  if ( v6 != nullptr )
  {
    v7 = (matrix3x4_t *)(((unsigned int)v6 + 35) & 0xFFFFFFE0);
    LODWORD(v7[-1].m_flMatVal[2][3]) = v6;
  }
  else
  {
    v7 = nullptr;
  }
  this->m_PoseToDecal = v7;
  _g_pMemAlloc->PopAllocDbgInfo(this: _g_pMemAlloc);
  this->m_nDecalId = 1;
  return this;
}
