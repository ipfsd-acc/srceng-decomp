// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: materialsystem/shaderapidx9/vertexshaderdx8.cpp
// Functions: 127
// ============================================================

#include "materialsystem\shaderapidx9\vertexshaderdx8.h"

//------------------------------------------------------------------------------
// Address: 0x1000CA90
// Name: public: int CUtlVector<unsigned short,class CUtlMemory<unsigned short,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<unsigned short,CUtlMemory<unsigned short,int>>::InsertMultipleBefore(
        CUtlVector<unsigned short,CUtlMemory<unsigned short,int> > *this,
        int elem,
        int num)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  unsigned __int16 *m_pMemory; // ecx
  int v8; // eax
  int v9; // eax

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<unsigned short,int>::Grow(this: &this->m_Memory, num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v8 = this->m_Size;
  this->m_pElements = this->m_Memory.m_pMemory;
  v9 = v8 - elem - num;
  if ( v9 > 0 && num > 0 )
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 2 * v9);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x10014AD0
// Name: public: void CUtlFixedMemory<struct UtlLinkedListElem_t<struct Texture_t,int>>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlFixedMemory<UtlLinkedListElem_t<Texture_t,int>>::Grow(
        CUtlFixedMemory<UtlLinkedListElem_t<Texture_t,int> > *this,
        int num)
{
  int m_nGrowSize; // esi
  CUtlFixedMemory<UtlLinkedListElem_t<Texture_t,int> >::BlockHeader_t *v4; // ebx
  CUtlFixedMemory<UtlLinkedListElem_t<Texture_t,int> >::BlockHeader_t *m_pBlocks; // eax

  if ( num > 0 )
  {
    m_nGrowSize = this->m_nGrowSize;
    if ( m_nGrowSize == 0 )
    {
      m_nGrowSize = this->m_nAllocationCount;
      if ( m_nGrowSize == 0 )
        m_nGrowSize = 1;
    }
    if ( m_nGrowSize < num )
      m_nGrowSize *= (m_nGrowSize + num - 1) / m_nGrowSize;
    this->m_nAllocationCount += m_nGrowSize;
    v4 = (CUtlFixedMemory<UtlLinkedListElem_t<Texture_t,int> >::BlockHeader_t *)_g_pMemAlloc->Alloc_2(
                                                                                  this: _g_pMemAlloc,
                                                                                  a2: 80 * m_nGrowSize + 8);
    if ( v4 == nullptr )
      _Error(a1: "CUtlFixedMemory overflow!\n");
    m_pBlocks = this->m_pBlocks;
    v4->m_pNext = nullptr;
    v4->m_nBlockSize = m_nGrowSize;
    if ( m_pBlocks != nullptr )
    {
      for ( ; m_pBlocks->m_pNext != nullptr; m_pBlocks = m_pBlocks->m_pNext )
        ;
      m_pBlocks->m_pNext = v4;
    }
    else
    {
      this->m_pBlocks = v4;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10014B60
// Name: public: void CUtlMemory<void (*)(class D3DDeviceWrapper __near *,struct DynamicState_t const __near &,struct DynamicState_t __near &,bool),int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<void (__cdecl *)(D3DDeviceWrapper *,DynamicState_t const &,DynamicState_t &,bool),int>::Grow(
        CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  CUtlSymbolTable::StringPool_t **m_pMemory; // edx
  unsigned int v7; // [esp-4h] [ebp-Ch]

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
        m_nAllocationCount = 8;
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
    v7 = 4 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (CUtlSymbolTable::StringPool_t **)_g_pMemAlloc->Realloc_2(
                                                            this: _g_pMemAlloc,
                                                            a2: m_pMemory,
                                                            a3: v7);
    else
      this->m_pMemory = (CUtlSymbolTable::StringPool_t **)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10017D30
// Name: public: bool CUtlFixedMemory<struct UtlLinkedListElem_t<struct Texture_t,int>>::IsIdxAfter(int,class CUtlFixedMemory<struct UtlLinkedListElem_t<struct Texture_t,int>>::Iterator_t const __near &)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CUtlFixedMemory<UtlLinkedListElem_t<Texture_t,int>>::IsIdxAfter(
        CUtlFixedMemory<UtlLinkedListElem_t<Texture_t,int> > *this,
        unsigned int i,
        const CUtlFixedMemory<UtlLinkedListElem_t<Texture_t,int> >::Iterator_t *it)
{
  CUtlFixedMemory<UtlLinkedListElem_t<Texture_t,int> >::BlockHeader_t *m_pBlockHeader; // eax
  int m_nIndex; // ecx
  CUtlFixedMemory<UtlLinkedListElem_t<Texture_t,int> >::BlockHeader_t *m_pNext; // eax

  m_pBlockHeader = it->m_pBlockHeader;
  if ( it->m_pBlockHeader == nullptr )
    return false;
  m_nIndex = it->m_nIndex;
  if ( m_nIndex < 0 || m_nIndex >= m_pBlockHeader->m_nBlockSize )
    return false;
  if ( i >= (unsigned int)&m_pBlockHeader[1] && i < (unsigned int)&m_pBlockHeader[10 * m_pBlockHeader->m_nBlockSize + 1] )
    return (int)i > (int)&m_pBlockHeader[10 * m_nIndex + 1];
  m_pNext = m_pBlockHeader->m_pNext;
  if ( m_pNext == nullptr )
    return false;
  while ( i < (unsigned int)&m_pNext[1] || i >= (unsigned int)&m_pNext[10 * m_pNext->m_nBlockSize + 1] )
  {
    m_pNext = m_pNext->m_pNext;
    if ( m_pNext == nullptr )
      return false;
  }
  return true;
}

//------------------------------------------------------------------------------
// Address: 0x1001DA80
// Name: protected: int CUtlLinkedList<struct Texture_t,int,1,int,class CUtlFixedMemory<struct UtlLinkedListElem_t<struct Texture_t,int>>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
CUtlFixedMemory<UtlLinkedListElem_t<Texture_t,int> >::BlockHeader_t *__thiscall CUtlLinkedList<Texture_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<Texture_t,int>>>::AllocInternal(
        CUtlLinkedList<Texture_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<Texture_t,int> > > *this,
        bool multilist)
{
  CUtlFixedMemory<UtlLinkedListElem_t<Texture_t,int> >::BlockHeader_t *result; // eax
  CUtlFixedMemory<UtlLinkedListElem_t<Texture_t,int> >::BlockHeader_t *m_pBlockHeader; // eax
  CUtlFixedMemory<UtlLinkedListElem_t<Texture_t,int> >::Iterator_t *p_m_LastAlloc; // esi
  int m_nIndex; // ecx
  CUtlFixedMemory<UtlLinkedListElem_t<Texture_t,int> >::Iterator_t *v7; // eax
  CUtlFixedMemory<UtlLinkedListElem_t<Texture_t,int> >::BlockHeader_t *v8; // ecx
  int v9; // eax
  int v10; // ecx
  CUtlFixedMemory<UtlLinkedListElem_t<Texture_t,int> >::Iterator_t *v11; // eax
  int v12; // esi
  CUtlFixedMemory<UtlLinkedListElem_t<Texture_t,int> >::Iterator_t v13; // [esp+Ch] [ebp-18h] BYREF
  CUtlFixedMemory<UtlLinkedListElem_t<Texture_t,int> >::Iterator_t v14; // [esp+14h] [ebp-10h] BYREF
  CUtlFixedMemory<UtlLinkedListElem_t<Texture_t,int> >::Iterator_t v15; // [esp+1Ch] [ebp-8h] BYREF

  result = (CUtlFixedMemory<UtlLinkedListElem_t<Texture_t,int> >::BlockHeader_t *)this->m_FirstFree;
  if ( result != nullptr )
  {
    this->m_FirstFree = result[9].m_nBlockSize;
LABEL_36:
    if ( multilist )
    {
      result[9].m_nBlockSize = 0;
      result[9].m_pNext = nullptr;
    }
    else
    {
      result[9].m_nBlockSize = (int)result;
      result[9].m_pNext = result;
    }
    return result;
  }
  m_pBlockHeader = this->m_LastAlloc.m_pBlockHeader;
  p_m_LastAlloc = &this->m_LastAlloc;
  if ( m_pBlockHeader != nullptr
    && (m_nIndex = this->m_LastAlloc.m_nIndex) >= 0
    && m_nIndex < m_pBlockHeader->m_nBlockSize )
  {
    v7 = CUtlFixedMemory<UtlLinkedListElem_t<IDirect3DPixelShader9 *,int>>::Next(
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
    CUtlFixedMemory<UtlLinkedListElem_t<Texture_t,int>>::Grow(this: &this->m_Memory, num: 1);
    this->m_pElements = nullptr;
    if ( p_m_LastAlloc->m_pBlockHeader != nullptr
      && (v10 = this->m_LastAlloc.m_nIndex) >= 0
      && v10 < p_m_LastAlloc->m_pBlockHeader->m_nBlockSize )
    {
      v11 = CUtlFixedMemory<UtlLinkedListElem_t<IDirect3DPixelShader9 *,int>>::Next(
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
      if ( `CUtlLinkedList<Texture_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<Texture_t,int>>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<Texture_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<Texture_t,int>>>::AllocInternal'::`12'::__executeCount;
        _Warning(a1: "CUtlLinkedList overflow! (exhausted memory allocator)\n");
      }
      return nullptr;
    }
  }
  if ( &v8[10 * v9] != (CUtlFixedMemory<UtlLinkedListElem_t<Texture_t,int> >::BlockHeader_t *)-8 )
  {
    this->m_LastAlloc.m_nIndex = v9;
    p_m_LastAlloc->m_pBlockHeader = v8;
    v12 = this->m_LastAlloc.m_nIndex;
    if ( v12 >= 0 && v12 < v8->m_nBlockSize )
    {
      ++this->m_NumAlloced;
      result = &v8[10 * v12 + 1];
    }
    else
    {
      result = nullptr;
      ++this->m_NumAlloced;
    }
    goto LABEL_36;
  }
  if ( `CUtlLinkedList<Texture_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<Texture_t,int>>>::AllocInternal'::`19'::__executeCount >= 10 )
    return nullptr;
  ++`CUtlLinkedList<Texture_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<Texture_t,int>>>::AllocInternal'::`19'::__executeCount;
  _Warning(a1: "CUtlLinkedList overflow! (exhausted index range)\n");
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10021D50
// Name: public: void CUtlLinkedList<struct Texture_t,int,1,int,class CUtlFixedMemory<struct UtlLinkedListElem_t<struct Texture_t,int>>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<Texture_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<Texture_t,int>>>::RemoveAll(
        CUtlLinkedList<Texture_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<Texture_t,int> > > *this)
{
  CUtlLinkedList<Texture_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<Texture_t,int> > > *v1; // esi
  CUtlFixedMemory<UtlLinkedListElem_t<Texture_t,int> >::Iterator_t *i; // eax
  CUtlFixedMemory<UtlLinkedListElem_t<Texture_t,int> >::BlockHeader_t *m_pBlockHeader; // ebx
  int m_nIndex; // edi
  CUtlFixedMemory<UtlLinkedListElem_t<Texture_t,int> > *v5; // eax
  CUtlFixedMemory<UtlLinkedListElem_t<Texture_t,int> >::Iterator_t result; // [esp+4h] [ebp-14h] BYREF
  CUtlFixedMemory<UtlLinkedListElem_t<Texture_t,int> >::Iterator_t it; // [esp+Ch] [ebp-Ch] BYREF
  CUtlFixedMemory<UtlLinkedListElem_t<Texture_t,int> > *p_m_Memory; // [esp+14h] [ebp-4h]

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
          i = CUtlFixedMemory<UtlLinkedListElem_t<IDirect3DPixelShader9 *,int>>::Next(this: &v1->m_Memory, &result, &it) )
    {
      m_pBlockHeader = i->m_pBlockHeader;
      m_nIndex = i->m_nIndex;
      it.m_nIndex = m_nIndex;
      it.m_pBlockHeader = m_pBlockHeader;
      if ( m_pBlockHeader != nullptr )
      {
        if ( m_nIndex >= 0 && m_nIndex < m_pBlockHeader->m_nBlockSize )
        {
          if ( &m_pBlockHeader[10 * m_nIndex] == (CUtlFixedMemory<UtlLinkedListElem_t<Texture_t,int> >::BlockHeader_t *)-8
            || CUtlFixedMemory<UtlLinkedListElem_t<Texture_t,int>>::IsIdxAfter(
                 this: p_m_Memory,
                 i: (unsigned int)&m_pBlockHeader[10 * m_nIndex + 1],
                 it: (const CUtlFixedMemory<UtlLinkedListElem_t<Texture_t,int> >::Iterator_t *)&p_m_Memory[2].m_nGrowSize)
            || m_pBlockHeader[10 * m_nIndex + 10].m_pNext == &m_pBlockHeader[10 * m_nIndex + 1]
            && (CUtlFixedMemory<UtlLinkedListElem_t<Texture_t,int> >::BlockHeader_t *)m_pBlockHeader[10 * m_nIndex + 10].m_nBlockSize != &m_pBlockHeader[10 * m_nIndex + 1] )
          {
            v1 = (CUtlLinkedList<Texture_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<Texture_t,int> > > *)p_m_Memory;
          }
          else
          {
            v5 = p_m_Memory;
            m_pBlockHeader[10 * m_nIndex + 10].m_pNext = &m_pBlockHeader[10 * m_nIndex + 1];
            m_pBlockHeader[10 * m_nIndex + 10].m_nBlockSize = v5[1].m_nGrowSize;
            v5[1].m_nGrowSize = (int)&m_pBlockHeader[10 * m_nIndex + 1];
            v1 = (CUtlLinkedList<Texture_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<Texture_t,int> > > *)v5;
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
// Address: 0x10022270
// Name: public: void CUtlLinkedList<struct Texture_t,int,1,int,class CUtlFixedMemory<struct UtlLinkedListElem_t<struct Texture_t,int>>>::Purge(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<Texture_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<Texture_t,int>>>::Purge(
        CUtlLinkedList<Texture_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<Texture_t,int> > > *this)
{
  CUtlFixedMemory<UtlLinkedListElem_t<Texture_t,int> >::BlockHeader_t *m_pBlocks; // esi
  CUtlFixedMemory<UtlLinkedListElem_t<Texture_t,int> >::BlockHeader_t *v3; // [esp-4h] [ebp-10h]

  CUtlLinkedList<Texture_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<Texture_t,int>>>::RemoveAll(this);
  m_pBlocks = this->m_Memory.m_pBlocks;
  if ( this->m_Memory.m_pBlocks != nullptr )
  {
    do
    {
      v3 = m_pBlocks;
      m_pBlocks = m_pBlocks->m_pNext;
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v3);
    }
    while ( m_pBlocks != nullptr );
    this->m_Memory.m_pBlocks = nullptr;
    this->m_Memory.m_nAllocationCount = 0;
  }
  this->m_FirstFree = 0;
  this->m_NumAlloced = 0;
  this->m_pElements = nullptr;
  this->m_LastAlloc.m_pBlockHeader = nullptr;
  this->m_LastAlloc.m_nIndex = -1;
}

//------------------------------------------------------------------------------
// Address: 0x100246A0
// Name: public: void CUtlMemory<struct ShaderDisplayMode_t,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<ShaderDisplayMode_t,int>::Grow(CUtlMemory<ShaderDisplayMode_t,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  ShaderDisplayMode_t *m_pMemory; // edx
  unsigned int v7; // [esp-4h] [ebp-Ch]

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
    v7 = 24 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (ShaderDisplayMode_t *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (ShaderDisplayMode_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10024DE0
// Name: public: bool CUtlVector<void (*)(void),class CUtlMemory<void (*)(void),int>>::FindAndRemove(void (*const __near &)(void))
// Source: json
//------------------------------------------------------------------------------
char __thiscall CUtlVector<void (__cdecl *)(void),CUtlMemory<void (__cdecl *)(void),int>>::FindAndRemove(
        CUtlVector<IShaderDeviceDependentObject *,CUtlMemory<IShaderDeviceDependentObject *,int> > *this,
        IShaderDeviceDependentObject **src)
{
  int m_Size; // edx
  int v4; // eax
  IShaderDeviceDependentObject **m_pMemory; // ebx
  IShaderDeviceDependentObject **i; // ecx
  int v8; // edx

  m_Size = this->m_Size;
  v4 = 0;
  if ( m_Size <= 0 )
    return 0;
  m_pMemory = this->m_Memory.m_pMemory;
  for ( i = this->m_Memory.m_pMemory; *i != *src; ++i )
  {
    if ( ++v4 >= m_Size )
      return 0;
  }
  if ( v4 == -1 )
    return 0;
  v8 = m_Size - v4 - 1;
  if ( v8 > 0 )
    _V_memmove(dest: &m_pMemory[v4], src: &m_pMemory[v4 + 1], count: 4 * v8);
  --this->m_Size;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10024E50
// Name: public: int CUtlVector<struct ShaderDisplayMode_t,class CUtlMemory<struct ShaderDisplayMode_t,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<ShaderDisplayMode_t,CUtlMemory<ShaderDisplayMode_t,int>>::InsertMultipleBefore(
        CUtlVector<ShaderDisplayMode_t,CUtlMemory<ShaderDisplayMode_t,int> > *this,
        int elem,
        int num)
{
  int v3; // edi
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  ShaderDisplayMode_t *m_pMemory; // ecx
  int v9; // eax
  int v10; // ecx
  ShaderDisplayMode_t *v11; // eax

  v3 = num;
  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<ShaderDisplayMode_t,int>::Grow(this: &this->m_Memory, num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v9 = this->m_Size - elem - num;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v9 <= 0 )
    goto LABEL_8;
  if ( num > 0 )
  {
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 24 * v9);
LABEL_8:
    if ( num > 0 )
    {
      v10 = elem;
      do
      {
        v11 = &this->m_Memory.m_pMemory[v10];
        if ( v11 != nullptr )
        {
          *(_QWORD *)&v11->m_nVersion = 0;
          *(_QWORD *)&v11->m_nHeight = 0;
          *(_QWORD *)&v11->m_nRefreshRateNumerator = 0;
          v11->m_nVersion = 1;
        }
        ++v10;
        --v3;
      }
      while ( v3 != 0 );
    }
  }
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x1002B3C0
// Name: public: void CUtlMemory<class CUtlVector<struct CTransitionTable::TransitionList_t,class CUtlMemory<struct CTransitionTable::TransitionList_t,int>>,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<CUtlVector<CTransitionTable::TransitionList_t,CUtlMemory<CTransitionTable::TransitionList_t,int>>,int>::Grow(
        CUtlMemory<CUtlVector<CTransitionTable::TransitionList_t,CUtlMemory<CTransitionTable::TransitionList_t,int> >,int> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  CUtlVector<CTransitionTable::TransitionList_t,CUtlMemory<CTransitionTable::TransitionList_t,int> > *m_pMemory; // edx
  unsigned int v7; // [esp-4h] [ebp-Ch]

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
    v7 = 20 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (CUtlVector<CTransitionTable::TransitionList_t,CUtlMemory<CTransitionTable::TransitionList_t,int> > *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (CUtlVector<CTransitionTable::TransitionList_t,CUtlMemory<CTransitionTable::TransitionList_t,int> > *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002BDB0
// Name: public: void CUtlVector<class CUtlVector<struct CTransitionTable::TransitionList_t,class CUtlMemory<struct CTransitionTable::TransitionList_t,int>>,class CUtlMemory<class CUtlVector<struct CTransitionTable::TransitionList_t,class CUtlMemory<struct CTransitionTable::TransitionList_t,int>>,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CUtlVector<CTransitionTable::TransitionList_t,CUtlMemory<CTransitionTable::TransitionList_t,int>>,CUtlMemory<CUtlVector<CTransitionTable::TransitionList_t,CUtlMemory<CTransitionTable::TransitionList_t,int>>,int>>::RemoveAll(
        CUtlVector<CUtlVector<CTransitionTable::TransitionList_t,CUtlMemory<CTransitionTable::TransitionList_t,int> >,CUtlMemory<CUtlVector<CTransitionTable::TransitionList_t,CUtlMemory<CTransitionTable::TransitionList_t,int> >,int> > *this)
{
  int v1; // ebx
  int v2; // eax
  char *v3; // esi
  void *v4; // eax
  int v5; // [esp+4h] [ebp-8h]
  CUtlVector<CUtlVector<CTransitionTable::TransitionList_t,CUtlMemory<CTransitionTable::TransitionList_t,int> >,CUtlMemory<CUtlVector<CTransitionTable::TransitionList_t,CUtlMemory<CTransitionTable::TransitionList_t,int> >,int> > *v6; // [esp+8h] [ebp-4h]

  v1 = this->m_Size - 1;
  v6 = this;
  if ( v1 < 0 )
  {
    this->m_Size = 0;
  }
  else
  {
    v2 = 20 * v1;
    v5 = 20 * v1;
    do
    {
      v3 = (char *)this->m_Memory.m_pMemory + v2;
      *((_DWORD *)v3 + 3) = 0;
      if ( *((int *)v3 + 2) >= 0 )
      {
        if ( *(_DWORD *)v3 != 0 )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *(void **)v3);
          this = v6;
          *(_DWORD *)v3 = 0;
        }
        *((_DWORD *)v3 + 1) = 0;
      }
      v4 = *(void **)v3;
      *((_DWORD *)v3 + 4) = *(_DWORD *)v3;
      if ( *((int *)v3 + 2) >= 0 )
      {
        if ( v4 != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v4);
          this = v6;
          *(_DWORD *)v3 = 0;
        }
        *((_DWORD *)v3 + 1) = 0;
      }
      --v1;
      v2 = v5 - 20;
      v5 -= 20;
    }
    while ( v1 >= 0 );
    this->m_Size = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002C1C0
// Name: public: CUtlVector<class CUtlVector<struct CTransitionTable::TransitionList_t,class CUtlMemory<struct CTransitionTable::TransitionList_t,int>>,class CUtlMemory<class CUtlVector<struct CTransitionTable::TransitionList_t,class CUtlMemory<struct CTransitionTable::TransitionList_t,int>>,int>>::~CUtlVector<class CUtlVector<struct CTransitionTable::TransitionList_t,class CUtlMemory<struct CTransitionTable::TransitionList_t,int>>,class CUtlMemory<class CUtlVector<struct CTransitionTable::TransitionList_t,class CUtlMemory<struct CTransitionTable::TransitionList_t,int>>,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CUtlVector<CTransitionTable::TransitionList_t,CUtlMemory<CTransitionTable::TransitionList_t,int>>,CUtlMemory<CUtlVector<CTransitionTable::TransitionList_t,CUtlMemory<CTransitionTable::TransitionList_t,int>>,int>>::~CUtlVector<CUtlVector<CTransitionTable::TransitionList_t,CUtlMemory<CTransitionTable::TransitionList_t,int>>,CUtlMemory<CUtlVector<CTransitionTable::TransitionList_t,CUtlMemory<CTransitionTable::TransitionList_t,int>>,int>>(
        CUtlVector<CUtlVector<CTransitionTable::TransitionList_t,CUtlMemory<CTransitionTable::TransitionList_t,int> >,CUtlMemory<CUtlVector<CTransitionTable::TransitionList_t,CUtlMemory<CTransitionTable::TransitionList_t,int> >,int> > *this)
{
  bool v2; // sf
  CUtlVector<CTransitionTable::TransitionList_t,CUtlMemory<CTransitionTable::TransitionList_t,int> > *m_pMemory; // eax

  CUtlVector<CUtlVector<CTransitionTable::TransitionList_t,CUtlMemory<CTransitionTable::TransitionList_t,int>>,CUtlMemory<CUtlVector<CTransitionTable::TransitionList_t,CUtlMemory<CTransitionTable::TransitionList_t,int>>,int>>::RemoveAll(this);
  if ( this->m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
  v2 = this->m_Memory.m_nGrowSize < 0;
  m_pMemory = this->m_Memory.m_pMemory;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( !v2 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002E6D0
// Name: PatchPixelShaderForAtiMsaaHack
// Source: json
//------------------------------------------------------------------------------
void __usercall PatchPixelShaderForAtiMsaaHack(unsigned int *pShader@<eax>, unsigned int dwTexCoordMask)
{
  unsigned int *v2; // edi
  unsigned int v3; // edx
  unsigned int v4; // edx
  unsigned int v5; // ecx
  int v6; // edx
  unsigned int v7; // eax
  unsigned int v8; // [esp+4h] [ebp-4h]

  if ( *pShader == -65024 )
  {
    v2 = pShader + 1;
    if ( pShader != (unsigned int *)-4 )
    {
      while ( 1 )
      {
        v3 = *v2;
        v8 = *v2;
        if ( (unsigned __int16)*v2 == 31 )
          break;
        if ( (unsigned __int16)*v2 != 65534 )
        {
          if ( (unsigned __int16)*v2 == 0xFFFF )
            return;
          goto LABEL_17;
        }
        v4 = HIWORD(v3);
LABEL_18:
        v2 += v4 + 1;
        if ( v2 == nullptr )
          return;
      }
      if ( (v2[1] & 0x78000000) == 0 )
      {
        v5 = v2[2];
        if ( ((v5 >> 8) & 0x18) + ((v5 >> 28) & 7) == 3 )
        {
          v6 = 1;
          v7 = 0;
          while ( (dwTexCoordMask & v6) != v6 || (v5 & 0x7FF) != v7 )
          {
            ++v7;
            v6 *= 2;
            if ( v7 >= 0x10 )
              goto LABEL_16;
          }
          v2[2] = v5 | 0x400000;
LABEL_16:
          v3 = v8;
        }
      }
LABEL_17:
      v4 = HIBYTE(v3) & 0xF;
      goto LABEL_18;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002E780
// Name: private: void CShaderManager::CreateStaticShaders(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderManager::CreateStaticShaders(CShaderManager *this)
{
  D3DDeviceWrapper *v1; // esi
  unsigned int psIllegalMaterial[11]; // [esp+4h] [ebp-2Ch] BYREF

  psIllegalMaterial[0] = -65279;
  psIllegalMaterial[1] = 81;
  psIllegalMaterial[2] = -1609629696;
  psIllegalMaterial[3] = 0;
  psIllegalMaterial[4] = 1065353216;
  psIllegalMaterial[5] = 0;
  psIllegalMaterial[6] = 1065353216;
  psIllegalMaterial[7] = 1;
  psIllegalMaterial[8] = -2146500608;
  psIllegalMaterial[9] = -1595670528;
  psIllegalMaterial[10] = 0xFFFF;
  v1 = Dx9Device();
  D3DDeviceWrapper::Synchronize(this: v1);
  v1->m_pD3DDevice->CreatePixelShader(
    this: v1->m_pD3DDevice,
    a2: psIllegalMaterial,
    a3: (IDirect3DPixelShader9 **)&s_pIllegalMaterialPS);
}

//------------------------------------------------------------------------------
// Address: 0x1002E800
// Name: private: void __near * CShaderManager::OpenFileAndLoadHeader(char const __near *,struct ShaderHeader_t __near *)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall CShaderManager::OpenFileAndLoadHeader(
        CShaderManager *this,
        const char *pFileName,
        ShaderHeader_t *pHeader)
{
  void *result; // eax
  void *v4; // esi
  int m_nVersion; // eax

  result = g_pFullFileSystem->Open(this: &g_pFullFileSystem->IBaseFileSystem, a2: pFileName, a3: "rb", a4: "PLATFORM");
  v4 = result;
  if ( result != nullptr )
  {
    if ( pHeader == nullptr )
      return v4;
    g_pFullFileSystem->Read(this: &g_pFullFileSystem->IBaseFileSystem, a2: pHeader, a3: 28, a4: result);
    m_nVersion = pHeader->m_nVersion;
    if ( pHeader->m_nVersion == 4 || pHeader->m_nVersion > 4 && m_nVersion <= 6 )
    {
      return v4;
    }
    else
    {
      _Warning(a1: "Shader %s is the wrong version %d, expecting %d\n", pFileName, m_nVersion, 6);
      g_pFullFileSystem->Close(this: &g_pFullFileSystem->IBaseFileSystem, a2: v4);
      return nullptr;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1002E890
// Name: public: virtual void __near * CShaderManager::GetCurrentVertexShader(void)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall CShaderManager::GetCurrentVertexShader(CShaderManager *this)
{
  return this->m_HardwareVertexShader;
}

//------------------------------------------------------------------------------
// Address: 0x1002E8A0
// Name: public: virtual void __near * CShaderManager::GetCurrentPixelShader(void)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall CShaderManager::GetCurrentPixelShader(CShaderManager *this)
{
  return this->m_HardwarePixelShader;
}

//------------------------------------------------------------------------------
// Address: 0x1002E8B0
// Name: public: virtual void CShaderManager::ResetShaderState(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderManager::ResetShaderState(CShaderManager *this)
{
  void (__thiscall *SetVertexShader)(struct CShaderManager *, int); // edx

  SetVertexShader = this->SetVertexShader;
  this->m_HardwareVertexShader = (void *)-1;
  this->m_HardwarePixelShader = (void *)-1;
  ((void (__stdcall *)(int))SetVertexShader)(a1: -1);
  this->SetPixelShader(this, a2: -1);
}

//------------------------------------------------------------------------------
// Address: 0x1002E8E0
// Name: mat_shadercount
// Source: json
//------------------------------------------------------------------------------
void __cdecl mat_shadercount()
{
  _Warning(a1: "Num Pixel Shaders = %d Vertex Shaders=%d\n", s_NumPixelShadersCreated, s_NumVertexShadersCreated);
  s_NumVertexShadersCreated = 0;
  s_NumPixelShadersCreated = 0;
}

//------------------------------------------------------------------------------
// Address: 0x1002E910
// Name: public: virtual unsigned int CShaderBuffer<struct ID3DXBuffer>::GetSize(void)const
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CShaderBuffer<ID3DXBuffer>::GetSize(CShaderBuffer<ID3DXBuffer> *this)
{
  if ( this->m_pBlob != nullptr )
    return this->m_pBlob->GetBufferSize(this: this->m_pBlob);
  else
    return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1002E930
// Name: public: virtual void const __near * CShaderBuffer<struct ID3DXBuffer>::GetBits(void)const
// Source: json
//------------------------------------------------------------------------------
void *__thiscall CShaderBuffer<ID3DXBuffer>::GetBits(CShaderBuffer<ID3DXBuffer> *this)
{
  if ( this->m_pBlob != nullptr )
    return this->m_pBlob->GetBufferPointer(this: this->m_pBlob);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1002E950
// Name: public: virtual void CShaderBuffer<struct ID3DXBuffer>::Release(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderBuffer<ID3DXBuffer>::Release(CShaderBuffer<ID3DXBuffer> *this)
{
  if ( this->m_pBlob != nullptr )
    this->m_pBlob->Release(this: this->m_pBlob);
  free(pMem: this);
}

//------------------------------------------------------------------------------
// Address: 0x1002E970
// Name: int BinarySearchCombos<struct StaticComboAliasRecord_t>(unsigned int,int,struct StaticComboAliasRecord_t const __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl BinarySearchCombos<StaticComboAliasRecord_t>(
        unsigned int nStaticComboID,
        int nCombos,
        const StaticComboAliasRecord_t *pRecords)
{
  int v3; // edi
  int v4; // esi
  int v5; // eax
  unsigned int m_nStaticComboID; // ecx

  v3 = nCombos;
  v4 = 1;
  if ( nCombos < 1 )
    return -1;
  while ( 1 )
  {
    v5 = (v3 + v4) / 2;
    m_nStaticComboID = pRecords[v5 - 1].m_nStaticComboID;
    if ( nStaticComboID >= m_nStaticComboID )
      break;
    v3 = v5 - 1;
LABEL_6:
    if ( v3 < v4 )
      return -1;
  }
  if ( nStaticComboID > m_nStaticComboID )
  {
    v4 = v5 + 1;
    goto LABEL_6;
  }
  return v5 - 1;
}

//------------------------------------------------------------------------------
// Address: 0x1002E9C0
// Name: public: void CUtlFixedMemory<struct UtlLinkedListElem_t<struct IDirect3DPixelShader9 __near *,int>>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlFixedMemory<UtlLinkedListElem_t<IDirect3DPixelShader9 *,int>>::Grow(
        CUtlFixedMemory<UtlLinkedListElem_t<IDirect3DPixelShader9 *,int> > *this,
        int num)
{
  int m_nGrowSize; // esi
  CUtlFixedMemory<UtlLinkedListElem_t<IDirect3DPixelShader9 *,int> >::BlockHeader_t *v4; // ebx
  CUtlFixedMemory<UtlLinkedListElem_t<IDirect3DPixelShader9 *,int> >::BlockHeader_t *m_pBlocks; // eax

  if ( num > 0 )
  {
    m_nGrowSize = this->m_nGrowSize;
    if ( m_nGrowSize == 0 )
    {
      m_nGrowSize = this->m_nAllocationCount;
      if ( m_nGrowSize == 0 )
        m_nGrowSize = 3;
    }
    if ( m_nGrowSize < num )
      m_nGrowSize *= (m_nGrowSize + num - 1) / m_nGrowSize;
    this->m_nAllocationCount += m_nGrowSize;
    v4 = (CUtlFixedMemory<UtlLinkedListElem_t<IDirect3DPixelShader9 *,int> >::BlockHeader_t *)_g_pMemAlloc->Alloc_2(
                                                                                                this: _g_pMemAlloc,
                                                                                                a2: 12 * m_nGrowSize + 8);
    if ( v4 == nullptr )
      _Error(a1: "CUtlFixedMemory overflow!\n");
    m_pBlocks = this->m_pBlocks;
    v4->m_pNext = nullptr;
    v4->m_nBlockSize = m_nGrowSize;
    if ( m_pBlocks != nullptr )
    {
      for ( ; m_pBlocks->m_pNext != nullptr; m_pBlocks = m_pBlocks->m_pNext )
        ;
      m_pBlocks->m_pNext = v4;
    }
    else
    {
      this->m_pBlocks = v4;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002EA50
// Name: public: void CUtlFixedMemory<struct UtlLinkedListElem_t<struct CShaderManager::ShaderLookup_t,int>>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlFixedMemory<UtlLinkedListElem_t<CShaderManager::ShaderLookup_t,int>>::Grow(
        CUtlFixedMemory<UtlLinkedListElem_t<CShaderManager::ShaderLookup_t,int> > *this,
        int num)
{
  int m_nGrowSize; // esi
  CUtlFixedMemory<UtlLinkedListElem_t<CShaderManager::ShaderLookup_t,int> >::BlockHeader_t *v4; // ebx
  CUtlFixedMemory<UtlLinkedListElem_t<CShaderManager::ShaderLookup_t,int> >::BlockHeader_t *m_pBlocks; // eax

  if ( num > 0 )
  {
    m_nGrowSize = this->m_nGrowSize;
    if ( m_nGrowSize == 0 )
    {
      m_nGrowSize = this->m_nAllocationCount;
      if ( m_nGrowSize == 0 )
        m_nGrowSize = 1;
    }
    if ( m_nGrowSize < num )
      m_nGrowSize *= (m_nGrowSize + num - 1) / m_nGrowSize;
    this->m_nAllocationCount += m_nGrowSize;
    v4 = (CUtlFixedMemory<UtlLinkedListElem_t<CShaderManager::ShaderLookup_t,int> >::BlockHeader_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 52 * m_nGrowSize + 8);
    if ( v4 == nullptr )
      _Error(a1: "CUtlFixedMemory overflow!\n");
    m_pBlocks = this->m_pBlocks;
    v4->m_pNext = nullptr;
    v4->m_nBlockSize = m_nGrowSize;
    if ( m_pBlocks != nullptr )
    {
      for ( ; m_pBlocks->m_pNext != nullptr; m_pBlocks = m_pBlocks->m_pNext )
        ;
      m_pBlocks->m_pNext = v4;
    }
    else
    {
      this->m_pBlocks = v4;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002EAE0
// Name: public: void CUtlFixedMemory<struct UtlLinkedListElem_t<struct ShaderFileCache_t,int>>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlFixedMemory<UtlLinkedListElem_t<ShaderFileCache_t,int>>::Grow(
        CUtlFixedMemory<UtlLinkedListElem_t<ShaderFileCache_t,int> > *this,
        int num)
{
  int m_nGrowSize; // esi
  CUtlFixedMemory<UtlLinkedListElem_t<ShaderFileCache_t,int> >::BlockHeader_t *v4; // ebx
  CUtlFixedMemory<UtlLinkedListElem_t<ShaderFileCache_t,int> >::BlockHeader_t *m_pBlocks; // eax

  if ( num > 0 )
  {
    m_nGrowSize = this->m_nGrowSize;
    if ( m_nGrowSize == 0 )
    {
      m_nGrowSize = this->m_nAllocationCount;
      if ( m_nGrowSize == 0 )
        m_nGrowSize = 1;
    }
    if ( m_nGrowSize < num )
      m_nGrowSize *= (m_nGrowSize + num - 1) / m_nGrowSize;
    this->m_nAllocationCount += m_nGrowSize;
    v4 = (CUtlFixedMemory<UtlLinkedListElem_t<ShaderFileCache_t,int> >::BlockHeader_t *)_g_pMemAlloc->Alloc_2(
                                                                                          this: _g_pMemAlloc,
                                                                                          a2: 132 * m_nGrowSize + 8);
    if ( v4 == nullptr )
      _Error(a1: "CUtlFixedMemory overflow!\n");
    m_pBlocks = this->m_pBlocks;
    v4->m_pNext = nullptr;
    v4->m_nBlockSize = m_nGrowSize;
    if ( m_pBlocks != nullptr )
    {
      for ( ; m_pBlocks->m_pNext != nullptr; m_pBlocks = m_pBlocks->m_pNext )
        ;
      m_pBlocks->m_pNext = v4;
    }
    else
    {
      this->m_pBlocks = v4;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002EB70
// Name: public: void CUtlMemory<struct StaticComboRecord_t,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<StaticComboRecord_t,int>::Grow(
        CUtlMemory<CMeshMgr::VertexBufferLookup_t,int> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  CMeshMgr::VertexBufferLookup_t *m_pMemory; // edx
  unsigned int v7; // [esp-4h] [ebp-Ch]

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
        m_nAllocationCount = 4;
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
    v7 = 8 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (CMeshMgr::VertexBufferLookup_t *)_g_pMemAlloc->Realloc_2(
                                                            this: _g_pMemAlloc,
                                                            a2: m_pMemory,
                                                            a3: v7);
    else
      this->m_pMemory = (CMeshMgr::VertexBufferLookup_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002EC10
// Name: CreateD3DVertexShader
// Source: json
//------------------------------------------------------------------------------
void *__usercall CreateD3DVertexShader@<eax>(unsigned int *pByteCode@<edi>, void *a2@<ecx>, int a3@<esi>)
{
  D3DDeviceWrapper *v3; // esi
  void *hShader; // [esp+0h] [ebp-4h] BYREF

  hShader = a2;
  if ( r_emulategl.m_pParent != nullptr && r_emulategl.m_pParent->m_Value.m_nValue != 0 )
    D3DXGetShaderVersion(a1: pByteCode);
  v3 = Dx9Device();
  D3DDeviceWrapper::Synchronize(this: v3);
  if ( ((int (__stdcall *)(IDirect3DDevice9 *, unsigned int *, void **, int))v3->m_pD3DDevice->CreateVertexShader)(
         a1: v3->m_pD3DDevice,
         a2: pByteCode,
         a3: &hShader,
         a4: a3) < 0 )
    return nullptr;
  ++s_NumVertexShadersCreated;
  return hShader;
}

//------------------------------------------------------------------------------
// Address: 0x1002EC70
// Name: CreateD3DPixelShader
// Source: json
//------------------------------------------------------------------------------
void *__usercall CreateD3DPixelShader@<eax>(unsigned int *pByteCode@<edi>, unsigned int nCentroidMask@<eax>)
{
  D3DDeviceWrapper *v4; // esi
  void *shader; // [esp+4h] [ebp-4h] BYREF

  if ( pByteCode == nullptr )
    return nullptr;
  if ( nCentroidMask != 0
    && g_pMaterialSystemHardwareConfig->NeedsATICentroidHack(this: g_pMaterialSystemHardwareConfig)
    && !g_pMaterialSystemHardwareConfig->SuppressPixelShaderCentroidHackFixup(this: g_pMaterialSystemHardwareConfig) )
  {
    PatchPixelShaderForAtiMsaaHack(pShader: pByteCode, dwTexCoordMask: nCentroidMask);
  }
  if ( r_emulategl.m_pParent != nullptr && r_emulategl.m_pParent->m_Value.m_nValue != 0 )
    D3DXGetShaderVersion(a1: pByteCode);
  v4 = Dx9Device();
  D3DDeviceWrapper::Synchronize(this: v4);
  if ( v4->m_pD3DDevice->CreatePixelShader(this: v4->m_pD3DDevice, a2: pByteCode, a3: (IDirect3DPixelShader9 **)&shader) < 0 )
    return nullptr;
  ++s_NumPixelShadersCreated;
  return shader;
}

//------------------------------------------------------------------------------
// Address: 0x1002ED00
// Name: public: virtual void CShaderManager::Init(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderManager::Init(CShaderManager *this)
{
  int v2; // ecx
  int v3; // eax

  if ( g_pShaderUtil->InEditorMode(this: g_pShaderUtil)
    || (v3 = _CommandLine(a1: v2),
        (*(int (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v3 + 12))(a1: v3, a2: "-shadersondemand", a3: 0) != 0) )
  {
    this->m_bCreateShadersOnDemand = true;
    CShaderManager::CreateStaticShaders(this);
  }
  else
  {
    this->m_bCreateShadersOnDemand = false;
    CShaderManager::CreateStaticShaders(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002ED50
// Name: public: virtual class IShaderBuffer __near * CShaderManager::CompileShader(char const __near *,unsigned int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
IShaderBuffer *__thiscall CShaderManager::CompileShader(
        CShaderManager *this,
        char *pProgram,
        ID3DXBuffer *nBufLen,
        ID3DXBuffer *pShaderVersion)
{
  const char *v4; // eax
  _DWORD *v6; // eax
  ID3DXBuffer *v7; // ecx
  _DWORD *v8; // esi

  if ( D3DXCompileShader(
         a1: pProgram,
         a2: (unsigned int)nBufLen,
         a3: nullptr,
         a4: nullptr,
         a5: (int)"main",
         a6: (int)pShaderVersion,
         a7: 512,
         a8: (int)&nBufLen,
         a9: &pShaderVersion,
         a10: 0) >= 0 )
  {
    v6 = operator new(nSize: 8u);
    if ( v6 != nullptr )
    {
      v7 = nBufLen;
      *v6 = &CShaderBuffer<ID3DXBuffer>::`vftable';
      v6[1] = v7;
      v8 = v6;
    }
    else
    {
      v8 = nullptr;
    }
    if ( pShaderVersion != nullptr )
      pShaderVersion->Release(this: pShaderVersion);
    return (IShaderBuffer *)v8;
  }
  else
  {
    if ( pShaderVersion != nullptr )
    {
      v4 = (const char *)pShaderVersion->GetBufferPointer(this: pShaderVersion);
      _Warning(a1: "Shader compilation failed! Reported the following errors:\n%s\n", v4);
      pShaderVersion->Release(this: pShaderVersion);
    }
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002EDF0
// Name: private: void CShaderManager::SetVertexShaderState_Internal(void __near *,struct memhandle_t__ __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderManager::SetVertexShaderState_Internal(
        CShaderManager *this,
        IDirect3DVertexShader9 *shader,
        memhandle_t__ *hCachedShader)
{
  D3DDeviceWrapper *v4; // eax
  D3DDeviceWrapper *v5; // esi
  unsigned int *m_pOutputPtr; // eax

  if ( (_S2_0 & 1) == 0 )
  {
    _S2_0 |= 1u;
    counter_10.m_pCounter = CVProfile::FindOrCreateCounter(
                              this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
                              a2: "vertex shader change",
                              a3: COUNTER_GROUP_DEFAULT);
    atexit(func: CShaderManager::SetVertexShaderState_Internal_::_4_::_dynamic_atexit_destructor_for___counter__);
  }
  ++*counter_10.m_pCounter;
  v4 = Dx9Device();
  v5 = v4;
  if ( v4->m_pASyncThreadHandle != nullptr )
  {
    if ( v4->m_PushBufferFreeSlots < 2 )
      D3DDeviceWrapper::SubmitPushBufferAndGetANewOne(this: v4);
    m_pOutputPtr = v5->m_pOutputPtr;
    v5->m_PushBufferFreeSlots -= 2;
    *m_pOutputPtr = 6;
    *++v5->m_pOutputPtr = (unsigned int)shader;
    ++v5->m_pOutputPtr;
    this->m_HardwareVertexShader = shader;
  }
  else
  {
    v4->m_pD3DDevice->SetVertexShader(this: v4->m_pD3DDevice, a2: shader);
    this->m_HardwareVertexShader = shader;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002EEA0
// Name: private: void CShaderManager::SetPixelShaderState_Internal(void __near *,struct memhandle_t__ __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderManager::SetPixelShaderState_Internal(
        CShaderManager *this,
        IDirect3DPixelShader9 *shader,
        memhandle_t__ *hCachedShader)
{
  D3DDeviceWrapper *v4; // eax
  D3DDeviceWrapper *v5; // esi
  unsigned int *m_pOutputPtr; // eax

  if ( (_S3_0 & 1) == 0 )
  {
    _S3_0 |= 1u;
    counter_11.m_pCounter = CVProfile::FindOrCreateCounter(
                              this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
                              a2: "pixel shader change",
                              a3: COUNTER_GROUP_DEFAULT);
    atexit(func: CShaderManager::SetPixelShaderState_Internal_::_4_::_dynamic_atexit_destructor_for___counter__);
  }
  ++*counter_11.m_pCounter;
  v4 = Dx9Device();
  v5 = v4;
  if ( v4->m_pASyncThreadHandle != nullptr )
  {
    if ( v4->m_PushBufferFreeSlots < 2 )
      D3DDeviceWrapper::SubmitPushBufferAndGetANewOne(this: v4);
    m_pOutputPtr = v5->m_pOutputPtr;
    v5->m_PushBufferFreeSlots -= 2;
    *m_pOutputPtr = 5;
    *++v5->m_pOutputPtr = (unsigned int)shader;
    ++v5->m_pOutputPtr;
    this->m_HardwarePixelShader = shader;
  }
  else
  {
    v4->m_pD3DDevice->SetPixelShader(this: v4->m_pD3DDevice, a2: shader);
    this->m_HardwarePixelShader = shader;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002EF50
// Name: public: class CUtlFixedMemory<struct UtlLinkedListElem_t<struct IDirect3DPixelShader9 __near *,int>>::Iterator_t CUtlFixedMemory<struct UtlLinkedListElem_t<struct IDirect3DPixelShader9 __near *,int>>::Next(class CUtlFixedMemory<struct UtlLinkedListElem_t<struct IDirect3DPixelShader9 __near *,int>>::Iterator_t const __near &)const
// Source: json
//------------------------------------------------------------------------------
CUtlFixedMemory<UtlLinkedListElem_t<IDirect3DVertexShader9 *,int> >::Iterator_t *__thiscall CUtlFixedMemory<UtlLinkedListElem_t<IDirect3DPixelShader9 *,int>>::Next(
        CUtlFixedMemory<UtlLinkedListElem_t<Texture_t,int> > *this,
        CUtlFixedMemory<UtlLinkedListElem_t<IDirect3DVertexShader9 *,int> >::Iterator_t *result,
        const CUtlFixedMemory<UtlLinkedListElem_t<Texture_t,int> >::Iterator_t *it)
{
  CUtlFixedMemory<UtlLinkedListElem_t<Texture_t,int> >::BlockHeader_t *m_pBlockHeader; // ecx
  int m_nIndex; // eax
  CUtlFixedMemory<UtlLinkedListElem_t<Texture_t,int> >::BlockHeader_t *m_pNext; // ecx
  CUtlFixedMemory<UtlLinkedListElem_t<Texture_t,int> >::Iterator_t v7; // [esp+0h] [ebp-8h]

  m_pBlockHeader = it->m_pBlockHeader;
  if ( it->m_pBlockHeader != nullptr && (m_nIndex = it->m_nIndex) >= 0 && m_nIndex < m_pBlockHeader->m_nBlockSize )
  {
    if ( m_nIndex + 1 >= m_pBlockHeader->m_nBlockSize )
    {
      m_pNext = m_pBlockHeader->m_pNext;
      if ( m_pNext != nullptr )
      {
        v7 = (CUtlFixedMemory<UtlLinkedListElem_t<Texture_t,int> >::Iterator_t)(unsigned int)m_pNext;
      }
      else
      {
        v7.m_pBlockHeader = nullptr;
        v7.m_nIndex = -1;
      }
      *(CUtlFixedMemory<UtlLinkedListElem_t<Texture_t,int> >::Iterator_t *)result = v7;
      return result;
    }
    else
    {
      result->m_pBlockHeader = (CUtlFixedMemory<UtlLinkedListElem_t<IDirect3DVertexShader9 *,int> >::BlockHeader_t *)m_pBlockHeader;
      result->m_nIndex = m_nIndex + 1;
      return result;
    }
  }
  else
  {
    result->m_pBlockHeader = nullptr;
    result->m_nIndex = -1;
    return result;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002EFD0
// Name: public: bool CUtlFixedMemory<struct UtlLinkedListElem_t<struct IDirect3DPixelShader9 __near *,int>>::IsIdxAfter(int,class CUtlFixedMemory<struct UtlLinkedListElem_t<struct IDirect3DPixelShader9 __near *,int>>::Iterator_t const __near &)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CUtlFixedMemory<UtlLinkedListElem_t<IDirect3DPixelShader9 *,int>>::IsIdxAfter(
        CUtlFixedMemory<UtlLinkedListElem_t<IDirect3DPixelShader9 *,int> > *this,
        unsigned int i,
        const CUtlFixedMemory<UtlLinkedListElem_t<IDirect3DPixelShader9 *,int> >::Iterator_t *it)
{
  CUtlFixedMemory<UtlLinkedListElem_t<IDirect3DPixelShader9 *,int> >::BlockHeader_t *m_pBlockHeader; // eax
  int m_nIndex; // ecx
  CUtlFixedMemory<UtlLinkedListElem_t<IDirect3DPixelShader9 *,int> >::BlockHeader_t *m_pNext; // eax

  m_pBlockHeader = it->m_pBlockHeader;
  if ( it->m_pBlockHeader == nullptr )
    return false;
  m_nIndex = it->m_nIndex;
  if ( m_nIndex < 0 || m_nIndex >= m_pBlockHeader->m_nBlockSize )
    return false;
  if ( i >= (unsigned int)&m_pBlockHeader[1] && i < (unsigned int)&m_pBlockHeader[1] + 12 * m_pBlockHeader->m_nBlockSize )
    return (int)i > (int)&m_pBlockHeader[1] + 12 * m_nIndex;
  m_pNext = m_pBlockHeader->m_pNext;
  if ( m_pNext == nullptr )
    return false;
  while ( i < (unsigned int)&m_pNext[1] || i >= (unsigned int)&m_pNext[1] + 12 * m_pNext->m_nBlockSize )
  {
    m_pNext = m_pNext->m_pNext;
    if ( m_pNext == nullptr )
      return false;
  }
  return true;
}

//------------------------------------------------------------------------------
// Address: 0x1002F050
// Name: public: bool CUtlFixedMemory<struct UtlLinkedListElem_t<struct CShaderManager::ShaderLookup_t,int>>::IsIdxAfter(int,class CUtlFixedMemory<struct UtlLinkedListElem_t<struct CShaderManager::ShaderLookup_t,int>>::Iterator_t const __near &)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CUtlFixedMemory<UtlLinkedListElem_t<CShaderManager::ShaderLookup_t,int>>::IsIdxAfter(
        CUtlFixedMemory<UtlLinkedListElem_t<CShaderManager::ShaderLookup_t,int> > *this,
        unsigned int i,
        const CUtlFixedMemory<UtlLinkedListElem_t<CShaderManager::ShaderLookup_t,int> >::Iterator_t *it)
{
  CUtlFixedMemory<UtlLinkedListElem_t<CShaderManager::ShaderLookup_t,int> >::BlockHeader_t *m_pBlockHeader; // eax
  int m_nIndex; // edx
  CUtlFixedMemory<UtlLinkedListElem_t<CShaderManager::ShaderLookup_t,int> >::BlockHeader_t *m_pNext; // eax

  m_pBlockHeader = it->m_pBlockHeader;
  if ( it->m_pBlockHeader == nullptr )
    return false;
  m_nIndex = it->m_nIndex;
  if ( m_nIndex < 0 || m_nIndex >= m_pBlockHeader->m_nBlockSize )
    return false;
  if ( i >= (unsigned int)&m_pBlockHeader[1] && i < (unsigned int)&m_pBlockHeader[1] + 52 * m_pBlockHeader->m_nBlockSize )
    return (int)i > (int)&m_pBlockHeader[1] + 52 * m_nIndex;
  m_pNext = m_pBlockHeader->m_pNext;
  if ( m_pNext == nullptr )
    return false;
  while ( i < (unsigned int)&m_pNext[1] || i >= (unsigned int)&m_pNext[1] + 52 * m_pNext->m_nBlockSize )
  {
    m_pNext = m_pNext->m_pNext;
    if ( m_pNext == nullptr )
      return false;
  }
  return true;
}

//------------------------------------------------------------------------------
// Address: 0x1002F0D0
// Name: public: bool CUtlFixedMemory<struct UtlLinkedListElem_t<struct ShaderFileCache_t,int>>::IsIdxAfter(int,class CUtlFixedMemory<struct UtlLinkedListElem_t<struct ShaderFileCache_t,int>>::Iterator_t const __near &)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CUtlFixedMemory<UtlLinkedListElem_t<ShaderFileCache_t,int>>::IsIdxAfter(
        CUtlFixedMemory<UtlLinkedListElem_t<ShaderFileCache_t,int> > *this,
        unsigned int i,
        const CUtlFixedMemory<UtlLinkedListElem_t<ShaderFileCache_t,int> >::Iterator_t *it)
{
  CUtlFixedMemory<UtlLinkedListElem_t<ShaderFileCache_t,int> >::BlockHeader_t *m_pBlockHeader; // eax
  int m_nIndex; // edx
  CUtlFixedMemory<UtlLinkedListElem_t<ShaderFileCache_t,int> >::BlockHeader_t *m_pNext; // eax

  m_pBlockHeader = it->m_pBlockHeader;
  if ( it->m_pBlockHeader == nullptr )
    return false;
  m_nIndex = it->m_nIndex;
  if ( m_nIndex < 0 || m_nIndex >= m_pBlockHeader->m_nBlockSize )
    return false;
  if ( i >= (unsigned int)&m_pBlockHeader[1]
    && i < (unsigned int)&m_pBlockHeader[1] + 132 * m_pBlockHeader->m_nBlockSize )
  {
    return (int)i > (int)&m_pBlockHeader[1] + 132 * m_nIndex;
  }
  m_pNext = m_pBlockHeader->m_pNext;
  if ( m_pNext == nullptr )
    return false;
  while ( i < (unsigned int)&m_pNext[1] || i >= (unsigned int)&m_pNext[1] + 132 * m_pNext->m_nBlockSize )
  {
    m_pNext = m_pNext->m_pNext;
    if ( m_pNext == nullptr )
      return false;
  }
  return true;
}

//------------------------------------------------------------------------------
// Address: 0x1002F150
// Name: public: virtual void CShaderManager::BindVertexShader(struct VertexShaderHandle_t__ __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderManager::BindVertexShader(CShaderManager *this, IDirect3DVertexShader9 **hVertexShader)
{
  if ( this->m_HardwareVertexShader != *hVertexShader )
    CShaderManager::SetVertexShaderState_Internal(this, shader: *hVertexShader, hCachedShader: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x1002F170
// Name: public: virtual void CShaderManager::BindPixelShader(struct PixelShaderHandle_t__ __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderManager::BindPixelShader(CShaderManager *this, IDirect3DPixelShader9 **hPixelShader)
{
  if ( this->m_HardwarePixelShader != *hPixelShader )
    CShaderManager::SetPixelShaderState_Internal(this, shader: *hPixelShader, hCachedShader: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x1002F190
// Name: public: int CUtlVector<struct StaticComboAliasRecord_t,class CUtlMemory<struct StaticComboAliasRecord_t,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<StaticComboAliasRecord_t,CUtlMemory<StaticComboAliasRecord_t,int>>::InsertMultipleBefore(
        CUtlVector<StaticComboAliasRecord_t,CUtlMemory<StaticComboAliasRecord_t,int> > *this,
        int elem,
        int num)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  StaticComboAliasRecord_t *m_pMemory; // ecx
  int v8; // eax
  int v9; // eax

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<StaticComboRecord_t,int>::Grow(
      (CUtlMemory<CMeshMgr::VertexBufferLookup_t,int> *)this,
      num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v8 = this->m_Size;
  this->m_pElements = this->m_Memory.m_pMemory;
  v9 = v8 - elem - num;
  if ( v9 > 0 && num > 0 )
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 8 * v9);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x1002F200
// Name: protected: int CUtlLinkedList<struct IDirect3DVertexShader9 __near *,int,1,int,class CUtlFixedMemory<struct UtlLinkedListElem_t<struct IDirect3DVertexShader9 __near *,int>>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<IDirect3DVertexShader9 *,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<IDirect3DVertexShader9 *,int>>>::AllocInternal(
        CUtlLinkedList<IDirect3DVertexShader9 *,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<IDirect3DVertexShader9 *,int> > > *this,
        bool multilist)
{
  int result; // eax
  CUtlFixedMemory<UtlLinkedListElem_t<IDirect3DVertexShader9 *,int> >::BlockHeader_t *m_pBlockHeader; // eax
  CUtlFixedMemory<UtlLinkedListElem_t<IDirect3DVertexShader9 *,int> >::Iterator_t *p_m_LastAlloc; // esi
  int m_nIndex; // ecx
  CUtlFixedMemory<UtlLinkedListElem_t<IDirect3DVertexShader9 *,int> >::BlockHeader_t **v7; // eax
  CUtlFixedMemory<UtlLinkedListElem_t<IDirect3DVertexShader9 *,int> >::BlockHeader_t *v8; // ecx
  int v9; // eax
  int v10; // ecx
  CUtlFixedMemory<UtlLinkedListElem_t<IDirect3DVertexShader9 *,int> >::Iterator_t *v11; // eax
  int v12; // esi
  CUtlFixedMemory<UtlLinkedListElem_t<Texture_t,int> >::Iterator_t v13; // [esp+Ch] [ebp-18h] BYREF
  CUtlFixedMemory<UtlLinkedListElem_t<Texture_t,int> >::Iterator_t v14; // [esp+14h] [ebp-10h] BYREF
  CUtlFixedMemory<UtlLinkedListElem_t<Texture_t,int> >::Iterator_t v15; // [esp+1Ch] [ebp-8h] BYREF

  result = this->m_FirstFree;
  if ( result != 0 )
  {
    this->m_FirstFree = *(_DWORD *)(result + 8);
LABEL_36:
    if ( multilist )
    {
      *(_DWORD *)(result + 8) = 0;
      *(_DWORD *)(result + 4) = 0;
    }
    else
    {
      *(_DWORD *)(result + 8) = result;
      *(_DWORD *)(result + 4) = result;
    }
    return result;
  }
  m_pBlockHeader = this->m_LastAlloc.m_pBlockHeader;
  p_m_LastAlloc = &this->m_LastAlloc;
  if ( m_pBlockHeader != nullptr
    && (m_nIndex = this->m_LastAlloc.m_nIndex) >= 0
    && m_nIndex < m_pBlockHeader->m_nBlockSize )
  {
    v7 = (CUtlFixedMemory<UtlLinkedListElem_t<IDirect3DVertexShader9 *,int> >::BlockHeader_t **)CUtlFixedMemory<UtlLinkedListElem_t<IDirect3DPixelShader9 *,int>>::Next(
                                                                                                  (CUtlFixedMemory<UtlLinkedListElem_t<Texture_t,int> > *)this,
                                                                                                  result: (CUtlFixedMemory<UtlLinkedListElem_t<IDirect3DVertexShader9 *,int> >::Iterator_t *)&v13,
                                                                                                  it: (const CUtlFixedMemory<UtlLinkedListElem_t<Texture_t,int> >::Iterator_t *)&this->m_LastAlloc);
  }
  else
  {
    if ( this->m_Memory.m_pBlocks != nullptr )
    {
      v15.m_pBlockHeader = (CUtlFixedMemory<UtlLinkedListElem_t<Texture_t,int> >::BlockHeader_t *)this->m_Memory.m_pBlocks;
      v15.m_nIndex = 0;
    }
    else
    {
      v15.m_pBlockHeader = nullptr;
      v15.m_nIndex = -1;
    }
    v14 = v15;
    v7 = (CUtlFixedMemory<UtlLinkedListElem_t<IDirect3DVertexShader9 *,int> >::BlockHeader_t **)&v14;
  }
  v8 = *v7;
  v9 = (int)v7[1];
  if ( v8 == nullptr || v9 < 0 || v9 >= v8->m_nBlockSize )
  {
    CUtlFixedMemory<UtlLinkedListElem_t<IDirect3DPixelShader9 *,int>>::Grow(
      (CUtlFixedMemory<UtlLinkedListElem_t<IDirect3DPixelShader9 *,int> > *)this,
      num: 1);
    this->m_pElements = nullptr;
    if ( p_m_LastAlloc->m_pBlockHeader != nullptr
      && (v10 = this->m_LastAlloc.m_nIndex) >= 0
      && v10 < p_m_LastAlloc->m_pBlockHeader->m_nBlockSize )
    {
      v11 = CUtlFixedMemory<UtlLinkedListElem_t<IDirect3DPixelShader9 *,int>>::Next(
              (CUtlFixedMemory<UtlLinkedListElem_t<Texture_t,int> > *)this,
              result: (CUtlFixedMemory<UtlLinkedListElem_t<IDirect3DVertexShader9 *,int> >::Iterator_t *)&v14,
              it: (const CUtlFixedMemory<UtlLinkedListElem_t<Texture_t,int> >::Iterator_t *)&this->m_LastAlloc);
    }
    else
    {
      if ( this->m_Memory.m_pBlocks != nullptr )
      {
        v14.m_pBlockHeader = (CUtlFixedMemory<UtlLinkedListElem_t<Texture_t,int> >::BlockHeader_t *)this->m_Memory.m_pBlocks;
        v14.m_nIndex = 0;
      }
      else
      {
        v14.m_pBlockHeader = nullptr;
        v14.m_nIndex = -1;
      }
      v15 = v14;
      v11 = (CUtlFixedMemory<UtlLinkedListElem_t<IDirect3DVertexShader9 *,int> >::Iterator_t *)&v15;
    }
    v8 = v11->m_pBlockHeader;
    v9 = v11->m_nIndex;
    if ( v8 == nullptr || v9 < 0 || v9 >= v8->m_nBlockSize )
    {
      if ( `CUtlLinkedList<IDirect3DVertexShader9 *,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<IDirect3DVertexShader9 *,int>>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<IDirect3DVertexShader9 *,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<IDirect3DVertexShader9 *,int>>>::AllocInternal'::`12'::__executeCount;
        _Warning(a1: "CUtlLinkedList overflow! (exhausted memory allocator)\n");
      }
      return 0;
    }
  }
  if ( (CUtlFixedMemory<UtlLinkedListElem_t<IDirect3DVertexShader9 *,int> >::BlockHeader_t *)((char *)v8 + 12 * v9) != (CUtlFixedMemory<UtlLinkedListElem_t<IDirect3DVertexShader9 *,int> >::BlockHeader_t *)-8 )
  {
    this->m_LastAlloc.m_nIndex = v9;
    p_m_LastAlloc->m_pBlockHeader = v8;
    v12 = this->m_LastAlloc.m_nIndex;
    if ( v12 >= 0 && v12 < v8->m_nBlockSize )
    {
      ++this->m_NumAlloced;
      result = (int)&v8[1] + 12 * v12;
    }
    else
    {
      result = 0;
      ++this->m_NumAlloced;
    }
    goto LABEL_36;
  }
  if ( `CUtlLinkedList<IDirect3DVertexShader9 *,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<IDirect3DVertexShader9 *,int>>>::AllocInternal'::`19'::__executeCount >= 10 )
    return 0;
  ++`CUtlLinkedList<IDirect3DVertexShader9 *,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<IDirect3DVertexShader9 *,int>>>::AllocInternal'::`19'::__executeCount;
  _Warning(a1: "CUtlLinkedList overflow! (exhausted index range)\n");
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1002F390
// Name: protected: int CUtlLinkedList<struct IDirect3DPixelShader9 __near *,int,1,int,class CUtlFixedMemory<struct UtlLinkedListElem_t<struct IDirect3DPixelShader9 __near *,int>>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<IDirect3DPixelShader9 *,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<IDirect3DPixelShader9 *,int>>>::AllocInternal(
        CUtlLinkedList<IDirect3DPixelShader9 *,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<IDirect3DPixelShader9 *,int> > > *this,
        bool multilist)
{
  int result; // eax
  CUtlFixedMemory<UtlLinkedListElem_t<IDirect3DPixelShader9 *,int> >::BlockHeader_t *m_pBlockHeader; // eax
  CUtlFixedMemory<UtlLinkedListElem_t<IDirect3DPixelShader9 *,int> >::Iterator_t *p_m_LastAlloc; // esi
  int m_nIndex; // ecx
  CUtlFixedMemory<UtlLinkedListElem_t<IDirect3DPixelShader9 *,int> >::BlockHeader_t **v7; // eax
  CUtlFixedMemory<UtlLinkedListElem_t<IDirect3DPixelShader9 *,int> >::BlockHeader_t *v8; // ecx
  int v9; // eax
  int v10; // ecx
  CUtlFixedMemory<UtlLinkedListElem_t<IDirect3DVertexShader9 *,int> >::Iterator_t *v11; // eax
  int v12; // esi
  CUtlFixedMemory<UtlLinkedListElem_t<Texture_t,int> >::Iterator_t v13; // [esp+Ch] [ebp-18h] BYREF
  CUtlFixedMemory<UtlLinkedListElem_t<Texture_t,int> >::Iterator_t v14; // [esp+14h] [ebp-10h] BYREF
  CUtlFixedMemory<UtlLinkedListElem_t<Texture_t,int> >::Iterator_t v15; // [esp+1Ch] [ebp-8h] BYREF

  result = this->m_FirstFree;
  if ( result != 0 )
  {
    this->m_FirstFree = *(_DWORD *)(result + 8);
LABEL_36:
    if ( multilist )
    {
      *(_DWORD *)(result + 8) = 0;
      *(_DWORD *)(result + 4) = 0;
    }
    else
    {
      *(_DWORD *)(result + 8) = result;
      *(_DWORD *)(result + 4) = result;
    }
    return result;
  }
  m_pBlockHeader = this->m_LastAlloc.m_pBlockHeader;
  p_m_LastAlloc = &this->m_LastAlloc;
  if ( m_pBlockHeader != nullptr
    && (m_nIndex = this->m_LastAlloc.m_nIndex) >= 0
    && m_nIndex < m_pBlockHeader->m_nBlockSize )
  {
    v7 = (CUtlFixedMemory<UtlLinkedListElem_t<IDirect3DPixelShader9 *,int> >::BlockHeader_t **)CUtlFixedMemory<UtlLinkedListElem_t<IDirect3DPixelShader9 *,int>>::Next(
                                                                                                 (CUtlFixedMemory<UtlLinkedListElem_t<Texture_t,int> > *)this,
                                                                                                 result: (CUtlFixedMemory<UtlLinkedListElem_t<IDirect3DVertexShader9 *,int> >::Iterator_t *)&v13,
                                                                                                 it: (const CUtlFixedMemory<UtlLinkedListElem_t<Texture_t,int> >::Iterator_t *)&this->m_LastAlloc);
  }
  else
  {
    if ( this->m_Memory.m_pBlocks != nullptr )
    {
      v15.m_pBlockHeader = (CUtlFixedMemory<UtlLinkedListElem_t<Texture_t,int> >::BlockHeader_t *)this->m_Memory.m_pBlocks;
      v15.m_nIndex = 0;
    }
    else
    {
      v15.m_pBlockHeader = nullptr;
      v15.m_nIndex = -1;
    }
    v14 = v15;
    v7 = (CUtlFixedMemory<UtlLinkedListElem_t<IDirect3DPixelShader9 *,int> >::BlockHeader_t **)&v14;
  }
  v8 = *v7;
  v9 = (int)v7[1];
  if ( v8 == nullptr || v9 < 0 || v9 >= v8->m_nBlockSize )
  {
    CUtlFixedMemory<UtlLinkedListElem_t<IDirect3DPixelShader9 *,int>>::Grow(this: &this->m_Memory, num: 1);
    this->m_pElements = nullptr;
    if ( p_m_LastAlloc->m_pBlockHeader != nullptr
      && (v10 = this->m_LastAlloc.m_nIndex) >= 0
      && v10 < p_m_LastAlloc->m_pBlockHeader->m_nBlockSize )
    {
      v11 = CUtlFixedMemory<UtlLinkedListElem_t<IDirect3DPixelShader9 *,int>>::Next(
              (CUtlFixedMemory<UtlLinkedListElem_t<Texture_t,int> > *)this,
              result: (CUtlFixedMemory<UtlLinkedListElem_t<IDirect3DVertexShader9 *,int> >::Iterator_t *)&v14,
              it: (const CUtlFixedMemory<UtlLinkedListElem_t<Texture_t,int> >::Iterator_t *)&this->m_LastAlloc);
    }
    else
    {
      if ( this->m_Memory.m_pBlocks != nullptr )
      {
        v14.m_pBlockHeader = (CUtlFixedMemory<UtlLinkedListElem_t<Texture_t,int> >::BlockHeader_t *)this->m_Memory.m_pBlocks;
        v14.m_nIndex = 0;
      }
      else
      {
        v14.m_pBlockHeader = nullptr;
        v14.m_nIndex = -1;
      }
      v15 = v14;
      v11 = (CUtlFixedMemory<UtlLinkedListElem_t<IDirect3DVertexShader9 *,int> >::Iterator_t *)&v15;
    }
    v8 = (CUtlFixedMemory<UtlLinkedListElem_t<IDirect3DPixelShader9 *,int> >::BlockHeader_t *)v11->m_pBlockHeader;
    v9 = v11->m_nIndex;
    if ( v8 == nullptr || v9 < 0 || v9 >= v8->m_nBlockSize )
    {
      if ( `CUtlLinkedList<IDirect3DPixelShader9 *,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<IDirect3DPixelShader9 *,int>>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<IDirect3DPixelShader9 *,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<IDirect3DPixelShader9 *,int>>>::AllocInternal'::`12'::__executeCount;
        _Warning(a1: "CUtlLinkedList overflow! (exhausted memory allocator)\n");
      }
      return 0;
    }
  }
  if ( (CUtlFixedMemory<UtlLinkedListElem_t<IDirect3DPixelShader9 *,int> >::BlockHeader_t *)((char *)v8 + 12 * v9) != (CUtlFixedMemory<UtlLinkedListElem_t<IDirect3DPixelShader9 *,int> >::BlockHeader_t *)-8 )
  {
    this->m_LastAlloc.m_nIndex = v9;
    p_m_LastAlloc->m_pBlockHeader = v8;
    v12 = this->m_LastAlloc.m_nIndex;
    if ( v12 >= 0 && v12 < v8->m_nBlockSize )
    {
      ++this->m_NumAlloced;
      result = (int)&v8[1] + 12 * v12;
    }
    else
    {
      result = 0;
      ++this->m_NumAlloced;
    }
    goto LABEL_36;
  }
  if ( `CUtlLinkedList<IDirect3DPixelShader9 *,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<IDirect3DPixelShader9 *,int>>>::AllocInternal'::`19'::__executeCount >= 10 )
    return 0;
  ++`CUtlLinkedList<IDirect3DPixelShader9 *,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<IDirect3DPixelShader9 *,int>>>::AllocInternal'::`19'::__executeCount;
  _Warning(a1: "CUtlLinkedList overflow! (exhausted index range)\n");
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1002F520
// Name: protected: int CUtlLinkedList<struct CShaderManager::ShaderLookup_t,int,1,int,class CUtlFixedMemory<struct UtlLinkedListElem_t<struct CShaderManager::ShaderLookup_t,int>>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<CShaderManager::ShaderLookup_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CShaderManager::ShaderLookup_t,int>>>::AllocInternal(
        CUtlLinkedList<CShaderManager::ShaderLookup_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CShaderManager::ShaderLookup_t,int> > > *this,
        bool multilist)
{
  int result; // eax
  CUtlFixedMemory<UtlLinkedListElem_t<CShaderManager::ShaderLookup_t,int> >::BlockHeader_t *m_pBlockHeader; // eax
  CUtlFixedMemory<UtlLinkedListElem_t<CShaderManager::ShaderLookup_t,int> >::Iterator_t *p_m_LastAlloc; // esi
  int m_nIndex; // ecx
  CUtlFixedMemory<UtlLinkedListElem_t<CShaderManager::ShaderLookup_t,int> >::BlockHeader_t **v7; // eax
  CUtlFixedMemory<UtlLinkedListElem_t<CShaderManager::ShaderLookup_t,int> >::BlockHeader_t *v8; // ecx
  int v9; // eax
  int v10; // ecx
  CUtlFixedMemory<UtlLinkedListElem_t<IDirect3DVertexShader9 *,int> >::Iterator_t *v11; // eax
  int v12; // esi
  CUtlFixedMemory<UtlLinkedListElem_t<Texture_t,int> >::Iterator_t v13; // [esp+Ch] [ebp-18h] BYREF
  CUtlFixedMemory<UtlLinkedListElem_t<Texture_t,int> >::Iterator_t v14; // [esp+14h] [ebp-10h] BYREF
  CUtlFixedMemory<UtlLinkedListElem_t<Texture_t,int> >::Iterator_t v15; // [esp+1Ch] [ebp-8h] BYREF

  result = this->m_FirstFree;
  if ( result != 0 )
  {
    this->m_FirstFree = *(_DWORD *)(result + 48);
LABEL_36:
    if ( multilist )
    {
      *(_DWORD *)(result + 48) = 0;
      *(_DWORD *)(result + 44) = 0;
    }
    else
    {
      *(_DWORD *)(result + 48) = result;
      *(_DWORD *)(result + 44) = result;
    }
    return result;
  }
  m_pBlockHeader = this->m_LastAlloc.m_pBlockHeader;
  p_m_LastAlloc = &this->m_LastAlloc;
  if ( m_pBlockHeader != nullptr
    && (m_nIndex = this->m_LastAlloc.m_nIndex) >= 0
    && m_nIndex < m_pBlockHeader->m_nBlockSize )
  {
    v7 = (CUtlFixedMemory<UtlLinkedListElem_t<CShaderManager::ShaderLookup_t,int> >::BlockHeader_t **)CUtlFixedMemory<UtlLinkedListElem_t<IDirect3DPixelShader9 *,int>>::Next((CUtlFixedMemory<UtlLinkedListElem_t<Texture_t,int> > *)this, result: (CUtlFixedMemory<UtlLinkedListElem_t<IDirect3DVertexShader9 *,int> >::Iterator_t *)&v13, it: (const CUtlFixedMemory<UtlLinkedListElem_t<Texture_t,int> >::Iterator_t *)&this->m_LastAlloc);
  }
  else
  {
    if ( this->m_Memory.m_pBlocks != nullptr )
    {
      v15.m_pBlockHeader = (CUtlFixedMemory<UtlLinkedListElem_t<Texture_t,int> >::BlockHeader_t *)this->m_Memory.m_pBlocks;
      v15.m_nIndex = 0;
    }
    else
    {
      v15.m_pBlockHeader = nullptr;
      v15.m_nIndex = -1;
    }
    v14 = v15;
    v7 = (CUtlFixedMemory<UtlLinkedListElem_t<CShaderManager::ShaderLookup_t,int> >::BlockHeader_t **)&v14;
  }
  v8 = *v7;
  v9 = (int)v7[1];
  if ( v8 == nullptr || v9 < 0 || v9 >= v8->m_nBlockSize )
  {
    CUtlFixedMemory<UtlLinkedListElem_t<CShaderManager::ShaderLookup_t,int>>::Grow(this: &this->m_Memory, num: 1);
    this->m_pElements = nullptr;
    if ( p_m_LastAlloc->m_pBlockHeader != nullptr
      && (v10 = this->m_LastAlloc.m_nIndex) >= 0
      && v10 < p_m_LastAlloc->m_pBlockHeader->m_nBlockSize )
    {
      v11 = CUtlFixedMemory<UtlLinkedListElem_t<IDirect3DPixelShader9 *,int>>::Next(
              (CUtlFixedMemory<UtlLinkedListElem_t<Texture_t,int> > *)this,
              result: (CUtlFixedMemory<UtlLinkedListElem_t<IDirect3DVertexShader9 *,int> >::Iterator_t *)&v14,
              it: (const CUtlFixedMemory<UtlLinkedListElem_t<Texture_t,int> >::Iterator_t *)&this->m_LastAlloc);
    }
    else
    {
      if ( this->m_Memory.m_pBlocks != nullptr )
      {
        v14.m_pBlockHeader = (CUtlFixedMemory<UtlLinkedListElem_t<Texture_t,int> >::BlockHeader_t *)this->m_Memory.m_pBlocks;
        v14.m_nIndex = 0;
      }
      else
      {
        v14.m_pBlockHeader = nullptr;
        v14.m_nIndex = -1;
      }
      v15 = v14;
      v11 = (CUtlFixedMemory<UtlLinkedListElem_t<IDirect3DVertexShader9 *,int> >::Iterator_t *)&v15;
    }
    v8 = (CUtlFixedMemory<UtlLinkedListElem_t<CShaderManager::ShaderLookup_t,int> >::BlockHeader_t *)v11->m_pBlockHeader;
    v9 = v11->m_nIndex;
    if ( v8 == nullptr || v9 < 0 || v9 >= v8->m_nBlockSize )
    {
      if ( `CUtlLinkedList<CShaderManager::ShaderLookup_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CShaderManager::ShaderLookup_t,int>>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<CShaderManager::ShaderLookup_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CShaderManager::ShaderLookup_t,int>>>::AllocInternal'::`12'::__executeCount;
        _Warning(a1: "CUtlLinkedList overflow! (exhausted memory allocator)\n");
      }
      return 0;
    }
  }
  if ( (CUtlFixedMemory<UtlLinkedListElem_t<CShaderManager::ShaderLookup_t,int> >::BlockHeader_t *)((char *)v8 + 52 * v9) != (CUtlFixedMemory<UtlLinkedListElem_t<CShaderManager::ShaderLookup_t,int> >::BlockHeader_t *)-8 )
  {
    this->m_LastAlloc.m_nIndex = v9;
    p_m_LastAlloc->m_pBlockHeader = v8;
    v12 = this->m_LastAlloc.m_nIndex;
    if ( v12 >= 0 && v12 < v8->m_nBlockSize )
    {
      ++this->m_NumAlloced;
      result = (int)&v8[1] + 52 * v12;
    }
    else
    {
      result = 0;
      ++this->m_NumAlloced;
    }
    goto LABEL_36;
  }
  if ( `CUtlLinkedList<CShaderManager::ShaderLookup_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CShaderManager::ShaderLookup_t,int>>>::AllocInternal'::`19'::__executeCount >= 10 )
    return 0;
  ++`CUtlLinkedList<CShaderManager::ShaderLookup_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CShaderManager::ShaderLookup_t,int>>>::AllocInternal'::`19'::__executeCount;
  _Warning(a1: "CUtlLinkedList overflow! (exhausted index range)\n");
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1002F6C0
// Name: protected: int CUtlLinkedList<struct ShaderFileCache_t,int,1,int,class CUtlFixedMemory<struct UtlLinkedListElem_t<struct ShaderFileCache_t,int>>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<ShaderFileCache_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<ShaderFileCache_t,int>>>::AllocInternal(
        CUtlLinkedList<ShaderFileCache_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<ShaderFileCache_t,int> > > *this,
        bool multilist)
{
  int result; // eax
  CUtlFixedMemory<UtlLinkedListElem_t<ShaderFileCache_t,int> >::BlockHeader_t *m_pBlockHeader; // eax
  CUtlFixedMemory<UtlLinkedListElem_t<ShaderFileCache_t,int> >::Iterator_t *p_m_LastAlloc; // esi
  int m_nIndex; // ecx
  CUtlFixedMemory<UtlLinkedListElem_t<ShaderFileCache_t,int> >::BlockHeader_t **v7; // eax
  CUtlFixedMemory<UtlLinkedListElem_t<ShaderFileCache_t,int> >::BlockHeader_t *v8; // ecx
  int v9; // eax
  int v10; // ecx
  CUtlFixedMemory<UtlLinkedListElem_t<IDirect3DVertexShader9 *,int> >::Iterator_t *v11; // eax
  int v12; // esi
  CUtlFixedMemory<UtlLinkedListElem_t<Texture_t,int> >::Iterator_t v13; // [esp+Ch] [ebp-18h] BYREF
  CUtlFixedMemory<UtlLinkedListElem_t<Texture_t,int> >::Iterator_t v14; // [esp+14h] [ebp-10h] BYREF
  CUtlFixedMemory<UtlLinkedListElem_t<Texture_t,int> >::Iterator_t v15; // [esp+1Ch] [ebp-8h] BYREF

  result = this->m_FirstFree;
  if ( result != 0 )
  {
    this->m_FirstFree = *(_DWORD *)(result + 128);
LABEL_36:
    if ( multilist )
    {
      *(_DWORD *)(result + 128) = 0;
      *(_DWORD *)(result + 124) = 0;
    }
    else
    {
      *(_DWORD *)(result + 128) = result;
      *(_DWORD *)(result + 124) = result;
    }
    return result;
  }
  m_pBlockHeader = this->m_LastAlloc.m_pBlockHeader;
  p_m_LastAlloc = &this->m_LastAlloc;
  if ( m_pBlockHeader != nullptr
    && (m_nIndex = this->m_LastAlloc.m_nIndex) >= 0
    && m_nIndex < m_pBlockHeader->m_nBlockSize )
  {
    v7 = (CUtlFixedMemory<UtlLinkedListElem_t<ShaderFileCache_t,int> >::BlockHeader_t **)CUtlFixedMemory<UtlLinkedListElem_t<IDirect3DPixelShader9 *,int>>::Next(
                                                                                           (CUtlFixedMemory<UtlLinkedListElem_t<Texture_t,int> > *)this,
                                                                                           result: (CUtlFixedMemory<UtlLinkedListElem_t<IDirect3DVertexShader9 *,int> >::Iterator_t *)&v13,
                                                                                           it: (const CUtlFixedMemory<UtlLinkedListElem_t<Texture_t,int> >::Iterator_t *)&this->m_LastAlloc);
  }
  else
  {
    if ( this->m_Memory.m_pBlocks != nullptr )
    {
      v15.m_pBlockHeader = (CUtlFixedMemory<UtlLinkedListElem_t<Texture_t,int> >::BlockHeader_t *)this->m_Memory.m_pBlocks;
      v15.m_nIndex = 0;
    }
    else
    {
      v15.m_pBlockHeader = nullptr;
      v15.m_nIndex = -1;
    }
    v14 = v15;
    v7 = (CUtlFixedMemory<UtlLinkedListElem_t<ShaderFileCache_t,int> >::BlockHeader_t **)&v14;
  }
  v8 = *v7;
  v9 = (int)v7[1];
  if ( v8 == nullptr || v9 < 0 || v9 >= v8->m_nBlockSize )
  {
    CUtlFixedMemory<UtlLinkedListElem_t<ShaderFileCache_t,int>>::Grow(this: &this->m_Memory, num: 1);
    this->m_pElements = nullptr;
    if ( p_m_LastAlloc->m_pBlockHeader != nullptr
      && (v10 = this->m_LastAlloc.m_nIndex) >= 0
      && v10 < p_m_LastAlloc->m_pBlockHeader->m_nBlockSize )
    {
      v11 = CUtlFixedMemory<UtlLinkedListElem_t<IDirect3DPixelShader9 *,int>>::Next(
              (CUtlFixedMemory<UtlLinkedListElem_t<Texture_t,int> > *)this,
              result: (CUtlFixedMemory<UtlLinkedListElem_t<IDirect3DVertexShader9 *,int> >::Iterator_t *)&v14,
              it: (const CUtlFixedMemory<UtlLinkedListElem_t<Texture_t,int> >::Iterator_t *)&this->m_LastAlloc);
    }
    else
    {
      if ( this->m_Memory.m_pBlocks != nullptr )
      {
        v14.m_pBlockHeader = (CUtlFixedMemory<UtlLinkedListElem_t<Texture_t,int> >::BlockHeader_t *)this->m_Memory.m_pBlocks;
        v14.m_nIndex = 0;
      }
      else
      {
        v14.m_pBlockHeader = nullptr;
        v14.m_nIndex = -1;
      }
      v15 = v14;
      v11 = (CUtlFixedMemory<UtlLinkedListElem_t<IDirect3DVertexShader9 *,int> >::Iterator_t *)&v15;
    }
    v8 = (CUtlFixedMemory<UtlLinkedListElem_t<ShaderFileCache_t,int> >::BlockHeader_t *)v11->m_pBlockHeader;
    v9 = v11->m_nIndex;
    if ( v8 == nullptr || v9 < 0 || v9 >= v8->m_nBlockSize )
    {
      if ( `CUtlLinkedList<ShaderFileCache_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<ShaderFileCache_t,int>>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<ShaderFileCache_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<ShaderFileCache_t,int>>>::AllocInternal'::`12'::__executeCount;
        _Warning(a1: "CUtlLinkedList overflow! (exhausted memory allocator)\n");
      }
      return 0;
    }
  }
  if ( (CUtlFixedMemory<UtlLinkedListElem_t<ShaderFileCache_t,int> >::BlockHeader_t *)((char *)v8 + 132 * v9) != (CUtlFixedMemory<UtlLinkedListElem_t<ShaderFileCache_t,int> >::BlockHeader_t *)-8 )
  {
    this->m_LastAlloc.m_nIndex = v9;
    p_m_LastAlloc->m_pBlockHeader = v8;
    v12 = this->m_LastAlloc.m_nIndex;
    if ( v12 >= 0 && v12 < v8->m_nBlockSize )
    {
      ++this->m_NumAlloced;
      result = (int)&v8[1] + 132 * v12;
    }
    else
    {
      result = 0;
      ++this->m_NumAlloced;
    }
    goto LABEL_36;
  }
  if ( `CUtlLinkedList<ShaderFileCache_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<ShaderFileCache_t,int>>>::AllocInternal'::`19'::__executeCount >= 10 )
    return 0;
  ++`CUtlLinkedList<ShaderFileCache_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<ShaderFileCache_t,int>>>::AllocInternal'::`19'::__executeCount;
  _Warning(a1: "CUtlLinkedList overflow! (exhausted index range)\n");
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1002F870
// Name: void BitchAboutSkippedCombo(char const __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __usercall BitchAboutSkippedCombo(
        int a1@<ebx>,
        int a2@<edi>,
        int a3@<esi>,
        const char *pShaderName,
        int nStaticComboID,
        int nDynamicComboID)
{
  unsigned __int16 m_Id; // ax
  const ShaderComboSemantics_t *v7; // esi
  const ShaderComboInformation_t *v9; // edi
  int v10; // ecx
  const ShaderComboInformation_t *v11; // edi
  int v12; // ecx
  char path[260]; // [esp+0h] [ebp-110h] BYREF
  int v15; // [esp+104h] [ebp-Ch]
  int i; // [esp+108h] [ebp-8h]
  unsigned int v17; // [esp+10Ch] [ebp-4h] BYREF

  V_strncpy(pDest: path, pSrc: pShaderName, maxLen: 260);
  V_FileBase(in: path, out: path, maxlen: 260);
  m_Id = CUtlSymbolTable::Find(
           this: &s_ShaderComboInfoByName.m_SymbolTable,
           result: (CUtlSymbol *)&v17 + 1,
           pString: path)->m_Id;
  if ( m_Id == 0xFFFF )
  {
    _Warning(a1: "Can't find combo info for skipped combo!  Tell a programmer!!!\n");
  }
  else
  {
    v7 = s_ShaderComboInfoByName.m_Vector.m_Memory.m_pMemory[m_Id];
    _Warning(a1: "static combos: ", a2, a3, a1);
    i = 0;
    if ( v7->nStaticShaderComboArrayCount > 0 )
    {
      v17 = 0;
      do
      {
        v9 = &v7->pStaticShaderComboArray[v17 / 0xC];
        v10 = v9->m_nComboMax - v9->m_nComboMin + 1;
        v15 = nStaticComboID / v10;
        _Warning(a1: "%s=%d ", v9->m_pComboName, nStaticComboID % v10);
        v17 += 12;
        nStaticComboID = v15;
        ++i;
      }
      while ( i < v7->nStaticShaderComboArrayCount );
    }
    _Warning(a1: "\n");
    if ( nDynamicComboID != -1 )
    {
      _Warning(a1: "dynamic combos: ");
      i = 0;
      if ( v7->nDynamicShaderComboArrayCount > 0 )
      {
        v17 = 0;
        do
        {
          v11 = &v7->pDynamicShaderComboArray[v17 / 0xC];
          v12 = v11->m_nComboMax - v11->m_nComboMin + 1;
          v15 = nDynamicComboID / v12;
          _Warning(a1: "%s=%d ", v11->m_pComboName, nDynamicComboID % v12);
          v17 += 12;
          nDynamicComboID = v15;
          ++i;
        }
        while ( i < v7->nDynamicShaderComboArrayCount );
      }
      _Warning(a1: "\n");
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002F9B0
// Name: public: virtual void CShaderManager::ClearVertexAndPixelShaderRefCounts(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderManager::ClearVertexAndPixelShaderRefCounts(CShaderManager *this)
{
  int i; // eax
  int j; // eax

  for ( i = this->m_VertexShaderDict.m_Head; i != 0; i = *(_DWORD *)(i + 48) )
    *(_DWORD *)(i + 28) = 0;
  for ( j = this->m_PixelShaderDict.m_Head; j != 0; j = *(_DWORD *)(j + 48) )
    *(_DWORD *)(j + 28) = 0;
}

//------------------------------------------------------------------------------
// Address: 0x1002F9E0
// Name: public: virtual void CShaderManager::SetVertexShader(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderManager::SetVertexShader(CShaderManager *this, int shader)
{
  int m_nVertexShaderIndex; // eax
  unsigned int **v5; // edi
  void *v6; // ecx
  const char *v7; // eax
  const char *v8; // eax
  int v9; // [esp-8h] [ebp-18h]
  int v10; // [esp-8h] [ebp-18h]
  int v11; // [esp-4h] [ebp-14h]
  int v12; // [esp-4h] [ebp-14h]
  IDirect3DVertexShader9 *dxshader; // [esp+Ch] [ebp-4h]
  int vshIndex; // [esp+18h] [ebp+8h]

  if ( shader == -1 )
  {
    if ( this->m_HardwareVertexShader != nullptr )
      CShaderManager::SetVertexShaderState_Internal(this, shader: nullptr, hCachedShader: nullptr);
  }
  else
  {
    m_nVertexShaderIndex = this->m_nVertexShaderIndex;
    vshIndex = m_nVertexShaderIndex;
    if ( m_nVertexShaderIndex < 0 )
    {
      vshIndex = 0;
      m_nVertexShaderIndex = 0;
    }
    if ( (*(_BYTE *)(shader + 24) & 2) == 0 )
    {
      dxshader = *(IDirect3DVertexShader9 **)(*(_DWORD *)(shader + 16) + 4 * m_nVertexShaderIndex);
      if ( dxshader == nullptr )
      {
        if ( !this->m_bCreateShadersOnDemand
          || (v5 = (unsigned int **)(*(_DWORD *)(shader + 20) + 24 * m_nVertexShaderIndex),
              CUtlSymbolTable::String(this: &this->m_ShaderSymbolTable, id: *(CUtlSymbol *)shader),
              dxshader = (IDirect3DVertexShader9 *)CreateD3DVertexShader(pByteCode: *v5, a2: v6, a3: shader),
              *(_DWORD *)(*(_DWORD *)(shader + 16) + 4 * vshIndex) = dxshader,
              dxshader == nullptr) )
        {
          if ( s_bFirst )
          {
            s_bFirst = false;
            _Warning(a1: "*************************************************\n");
            _Warning(
              a1: "!!!!!Using invalid shader combo!!!!!  Consult a programmer and tell them to build debug materialsystem.dll"
              " and stdshader*.dll.  Run with \"mat_bufferprimitives 0\" and look for CMaterial in the call stack and see"
              " what m_pDebugName is.  You are likely using a shader combo that has been skipped.\n");
            v11 = this->m_nVertexShaderIndex;
            v9 = *(_DWORD *)(shader + 4);
            v7 = CUtlSymbolTable::String(this: &this->m_ShaderSymbolTable, id: *(CUtlSymbol *)shader);
            _Warning(a1: "Shader: %s static: %d dynamic: %d\n", v7, v9, v11);
            v12 = this->m_nVertexShaderIndex;
            v10 = *(_DWORD *)(shader + 4);
            v8 = CUtlSymbolTable::String(this: &this->m_ShaderSymbolTable, id: *(CUtlSymbol *)shader);
            BitchAboutSkippedCombo(
              a1: (int)this,
              a2: (int)_Warning,
              a3: shader,
              pShaderName: v8,
              nStaticComboID: v10,
              nDynamicComboID: v12);
            _Warning(a1: "*************************************************\n");
          }
        }
      }
      if ( this->m_HardwareVertexShader != dxshader )
        CShaderManager::SetVertexShaderState_Internal(this, shader: dxshader, hCachedShader: nullptr);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002FB10
// Name: public: virtual void CShaderManager::SetPixelShader(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderManager::SetPixelShader(CShaderManager *this, CUtlSymbol *shader)
{
  int m_nPixelShaderIndex; // edi
  const char *v5; // eax
  int v6; // edi
  const char *v7; // eax
  const char *v8; // eax
  int v9; // [esp-8h] [ebp-18h]
  int v10; // [esp-8h] [ebp-18h]
  int v11; // [esp-4h] [ebp-14h]
  int v12; // [esp-4h] [ebp-14h]
  int v13; // [esp-4h] [ebp-14h]
  int pshIndex; // [esp+Ch] [ebp-4h]
  IDirect3DPixelShader9 *dxshader; // [esp+18h] [ebp+8h]

  if ( shader == (CUtlSymbol *)-1 )
  {
    if ( this->m_HardwarePixelShader != nullptr )
      CShaderManager::SetPixelShaderState_Internal(this, shader: nullptr, hCachedShader: nullptr);
  }
  else
  {
    m_nPixelShaderIndex = this->m_nPixelShaderIndex;
    pshIndex = m_nPixelShaderIndex;
    if ( m_nPixelShaderIndex <= *(_DWORD *)&shader[4].m_Id )
    {
      if ( (shader[12].m_Id & 2) != 0 )
      {
        _Warning(a1: "***** Trying to set a pixel shader that failed loading!\n");
      }
      else
      {
        dxshader = *(IDirect3DPixelShader9 **)(*(_DWORD *)&shader[8].m_Id + 4 * m_nPixelShaderIndex);
        if ( dxshader == nullptr )
        {
          if ( !this->m_bCreateShadersOnDemand
            || (v6 = *(_DWORD *)&shader[10].m_Id + 24 * m_nPixelShaderIndex,
                CUtlSymbolTable::String(this: &this->m_ShaderSymbolTable, id: (CUtlSymbol)shader->m_Id),
                dxshader = (IDirect3DPixelShader9 *)CreateD3DPixelShader(
                                                      pByteCode: *(unsigned int **)v6,
                                                      nCentroidMask: *(_DWORD *)(v6 + 20)),
                *(_DWORD *)(*(_DWORD *)&shader[8].m_Id + 4 * pshIndex) = dxshader,
                dxshader == nullptr) )
          {
            if ( s_bFirst_0 )
            {
              s_bFirst_0 = false;
              _Warning(a1: "*************************************************\n");
              _Warning(
                a1: "!!!!!Using invalid pixel shader combo!!!!!  Consult a programmer and tell them to build debug materialsy"
                "stem.dll and stdshader*.dll.  Run with \"mat_bufferprimitives 0\" and look for CMaterial in the call sta"
                "ck and see what m_pDebugName is.  You are likely using a shader combo that has been skipped.\n");
              v12 = this->m_nPixelShaderIndex;
              v9 = *(_DWORD *)&shader[2].m_Id;
              v7 = CUtlSymbolTable::String(this: &this->m_ShaderSymbolTable, id: (CUtlSymbol)shader->m_Id);
              _Warning(a1: "Shader: %s static: %d dynamic: %d\n", v7, v9, v12);
              v13 = this->m_nPixelShaderIndex;
              v10 = *(_DWORD *)&shader[2].m_Id;
              v8 = CUtlSymbolTable::String(this: &this->m_ShaderSymbolTable, id: (CUtlSymbol)shader->m_Id);
              BitchAboutSkippedCombo(
                a1: (int)this,
                a2: (int)_Warning,
                a3: (int)shader,
                pShaderName: v8,
                nStaticComboID: v10,
                nDynamicComboID: v13);
              _Warning(a1: "*************************************************\n");
            }
          }
        }
        if ( this->m_HardwarePixelShader != dxshader )
          CShaderManager::SetPixelShaderState_Internal(this, shader: dxshader, hCachedShader: nullptr);
      }
    }
    else
    {
      if ( this->m_HardwarePixelShader != nullptr )
        CShaderManager::SetPixelShaderState_Internal(this, shader: nullptr, hCachedShader: nullptr);
      v11 = *(_DWORD *)&shader[4].m_Id;
      v5 = CUtlSymbol::String(this: shader);
      _Warning(a1: "***** Invalid pixel shader index (out of range) for %s (%d of %d).\n", v5, m_nPixelShaderIndex, v11);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002FC80
// Name: public: void CShaderManager::SpewVertexAndPixelShaders(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderManager::SpewVertexAndPixelShaders(CShaderManager *this)
{
  CShaderManager *v1; // ebx
  int i; // esi
  int m_Head; // esi
  int v4; // edx
  int v5; // esi
  int v6; // ebx
  int totalPixelShaderSets; // [esp+Ch] [ebp-10h]
  int totalVertexShaderSets; // [esp+10h] [ebp-Ch]
  int totalVertexShaders; // [esp+14h] [ebp-8h]
  CUtlSymbolTable *p_m_ShaderSymbolTable; // [esp+18h] [ebp-4h]

  v1 = this;
  _Msg(a1: "\nShader File Cache:\n");
  for ( i = v1->m_ShaderFileCache.m_Head; i != 0; v1 = this )
  {
    CUtlSymbolTable::String(this: &v1->m_ShaderSymbolTable, id: *(CUtlSymbol *)(i + 2));
    _Msg(a1: "Total Combos:%9d Static:%9d Dynamic:%7d SeekTable:%7d Ver:%d '%s'\n");
    i = *(_DWORD *)(i + 128);
  }
  _Msg(a1: "\n");
  m_Head = v1->m_VertexShaderDict.m_Head;
  totalVertexShaders = 0;
  for ( totalVertexShaderSets = 0; m_Head != 0; ++totalVertexShaderSets )
  {
    CUtlSymbolTable::String(this: &v1->m_ShaderSymbolTable, id: *(CUtlSymbol *)m_Head);
    _Msg(a1: "vsh 0x%8.8x: static combo:%9d dynamic combos:%6d refcount:%4d \"%s\"\n");
    v4 = *(_DWORD *)(m_Head + 12);
    m_Head = *(_DWORD *)(m_Head + 48);
    totalVertexShaders += v4;
  }
  v5 = this->m_PixelShaderDict.m_Head;
  v6 = 0;
  totalPixelShaderSets = 0;
  if ( v5 != 0 )
  {
    p_m_ShaderSymbolTable = &this->m_ShaderSymbolTable;
    do
    {
      CUtlSymbolTable::String(this: p_m_ShaderSymbolTable, id: *(CUtlSymbol *)v5);
      _Msg(a1: "psh 0x%8.8x: static combo:%9d dynamic combos:%6d refcount:%4d \"%s\"\n");
      v6 += *(_DWORD *)(v5 + 12);
      v5 = *(_DWORD *)(v5 + 48);
      ++totalPixelShaderSets;
    }
    while ( v5 != 0 );
  }
  _Msg(a1: "Total unique vertex shaders: %d\n");
  _Msg(a1: "Total vertex shader sets: %d\n");
  _Msg(a1: "Total unique pixel shaders: %d\n");
  _Msg(a1: "Total pixel shader sets: %d\n");
}

//------------------------------------------------------------------------------
// Address: 0x1002FDD0
// Name: mat_spewvertexandpixelshaders
// Source: json
//------------------------------------------------------------------------------
void __cdecl mat_spewvertexandpixelshaders()
{
  CShaderManager::SpewVertexAndPixelShaders(this: (CShaderManager *)g_pShaderManager);
}

//------------------------------------------------------------------------------
// Address: 0x1002FDE0
// Name: public: CUtlVector<struct CTransitionTable::ShadowStateDictEntry_t,class CUtlMemory<struct CTransitionTable::ShadowStateDictEntry_t,int>>::~CUtlVector<struct CTransitionTable::ShadowStateDictEntry_t,class CUtlMemory<struct CTransitionTable::ShadowStateDictEntry_t,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CTransitionTable::ShadowStateDictEntry_t,CUtlMemory<CTransitionTable::ShadowStateDictEntry_t,int>>::~CUtlVector<CTransitionTable::ShadowStateDictEntry_t,CUtlMemory<CTransitionTable::ShadowStateDictEntry_t,int>>(
        CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *this)
{
  bool v2; // sf
  CUtlSymbolTable::StringPool_t **m_pMemory; // eax

  v2 = this->m_Memory.m_nGrowSize < 0;
  this->m_Size = 0;
  if ( !v2 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
  v2 = this->m_Memory.m_nGrowSize < 0;
  m_pMemory = this->m_Memory.m_pMemory;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( !v2 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002FE50
// Name: public: void CUtlLinkedList<struct IDirect3DPixelShader9 __near *,int,1,int,class CUtlFixedMemory<struct UtlLinkedListElem_t<struct IDirect3DPixelShader9 __near *,int>>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<IDirect3DPixelShader9 *,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<IDirect3DPixelShader9 *,int>>>::RemoveAll(
        CUtlLinkedList<IDirect3DPixelShader9 *,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<IDirect3DPixelShader9 *,int> > > *this)
{
  CUtlFixedMemory<UtlLinkedListElem_t<Texture_t,int> > *v1; // esi
  void *i; // eax
  CUtlFixedMemory<UtlLinkedListElem_t<IDirect3DPixelShader9 *,int> >::BlockHeader_t *v3; // ebx
  int v4; // edi
  CUtlFixedMemory<UtlLinkedListElem_t<IDirect3DPixelShader9 *,int> > *v5; // eax
  CUtlFixedMemory<UtlLinkedListElem_t<Texture_t,int> >::Iterator_t result; // [esp+4h] [ebp-14h] BYREF
  CUtlFixedMemory<UtlLinkedListElem_t<IDirect3DPixelShader9 *,int> >::Iterator_t it; // [esp+Ch] [ebp-Ch] BYREF
  CUtlFixedMemory<UtlLinkedListElem_t<IDirect3DPixelShader9 *,int> > *p_m_Memory; // [esp+14h] [ebp-4h]

  v1 = (CUtlFixedMemory<UtlLinkedListElem_t<Texture_t,int> > *)this;
  p_m_Memory = &this->m_Memory;
  if ( this->m_LastAlloc.m_pBlockHeader != nullptr || this->m_LastAlloc.m_nIndex != -1 )
  {
    if ( this->m_Memory.m_pBlocks != nullptr )
    {
      result.m_pBlockHeader = (CUtlFixedMemory<UtlLinkedListElem_t<Texture_t,int> >::BlockHeader_t *)this->m_Memory.m_pBlocks;
      result.m_nIndex = 0;
    }
    else
    {
      result.m_pBlockHeader = nullptr;
      result.m_nIndex = -1;
    }
    for ( i = &result;
          ;
          i = CUtlFixedMemory<UtlLinkedListElem_t<IDirect3DPixelShader9 *,int>>::Next(
                this: v1,
                (CUtlFixedMemory<UtlLinkedListElem_t<IDirect3DVertexShader9 *,int> >::Iterator_t *)&result,
                (const CUtlFixedMemory<UtlLinkedListElem_t<Texture_t,int> >::Iterator_t *)&it) )
    {
      v3 = *(CUtlFixedMemory<UtlLinkedListElem_t<IDirect3DPixelShader9 *,int> >::BlockHeader_t **)i;
      v4 = *((_DWORD *)i + 1);
      it.m_nIndex = v4;
      it.m_pBlockHeader = v3;
      if ( v3 != nullptr )
      {
        if ( v4 >= 0 && v4 < v3->m_nBlockSize )
        {
          if ( (CUtlFixedMemory<UtlLinkedListElem_t<IDirect3DPixelShader9 *,int> >::BlockHeader_t *)((char *)v3 + 12 * v4) == (CUtlFixedMemory<UtlLinkedListElem_t<IDirect3DPixelShader9 *,int> >::BlockHeader_t *)-8
            || CUtlFixedMemory<UtlLinkedListElem_t<IDirect3DPixelShader9 *,int>>::IsIdxAfter(
                 this: p_m_Memory,
                 i: (unsigned int)&v3[1] + 12 * v4,
                 it: (const CUtlFixedMemory<UtlLinkedListElem_t<IDirect3DPixelShader9 *,int> >::Iterator_t *)&p_m_Memory[2].m_nGrowSize)
            || *((CUtlFixedMemory<UtlLinkedListElem_t<IDirect3DPixelShader9 *,int> >::BlockHeader_t **)&v3[1].m_nBlockSize
               + 3 * v4) == (CUtlFixedMemory<UtlLinkedListElem_t<IDirect3DPixelShader9 *,int> >::BlockHeader_t *)((char *)&v3[1] + 12 * v4)
            && *(&v3[2].m_pNext + 3 * v4) != (CUtlFixedMemory<UtlLinkedListElem_t<IDirect3DPixelShader9 *,int> >::BlockHeader_t *)((char *)&v3[1] + 12 * v4) )
          {
            v1 = (CUtlFixedMemory<UtlLinkedListElem_t<Texture_t,int> > *)p_m_Memory;
          }
          else
          {
            v5 = p_m_Memory;
            *(&v3[1].m_nBlockSize + 3 * v4) = (int)v3 + 12 * v4 + 8;
            *((_DWORD *)&v3[2].m_pNext + 3 * v4) = v5[1].m_nGrowSize;
            v5[1].m_nGrowSize = (int)&v3[1] + 12 * v4;
            v1 = (CUtlFixedMemory<UtlLinkedListElem_t<Texture_t,int> > *)v5;
          }
        }
      }
      else if ( v4 == -1 )
      {
        break;
      }
      if ( v3 == (CUtlFixedMemory<UtlLinkedListElem_t<IDirect3DPixelShader9 *,int> >::BlockHeader_t *)v1[2].m_nGrowSize
        && (CUtlFixedMemory<UtlLinkedListElem_t<Texture_t,int> >::BlockHeader_t *)v4 == v1[3].m_pBlocks )
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
// Address: 0x1002FF20
// Name: public: void CUtlLinkedList<struct CShaderManager::ShaderLookup_t,int,1,int,class CUtlFixedMemory<struct UtlLinkedListElem_t<struct CShaderManager::ShaderLookup_t,int>>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CShaderManager::ShaderLookup_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CShaderManager::ShaderLookup_t,int>>>::RemoveAll(
        CUtlLinkedList<CShaderManager::ShaderLookup_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CShaderManager::ShaderLookup_t,int> > > *this)
{
  CUtlFixedMemory<UtlLinkedListElem_t<Texture_t,int> > *v1; // esi
  void *i; // eax
  CUtlFixedMemory<UtlLinkedListElem_t<CShaderManager::ShaderLookup_t,int> >::BlockHeader_t *v3; // edi
  int v4; // ebx
  CUtlFixedMemory<UtlLinkedListElem_t<CShaderManager::ShaderLookup_t,int> > *v5; // eax
  CUtlFixedMemory<UtlLinkedListElem_t<Texture_t,int> >::Iterator_t result; // [esp+4h] [ebp-14h] BYREF
  CUtlFixedMemory<UtlLinkedListElem_t<CShaderManager::ShaderLookup_t,int> >::Iterator_t it; // [esp+Ch] [ebp-Ch] BYREF
  CUtlFixedMemory<UtlLinkedListElem_t<CShaderManager::ShaderLookup_t,int> > *p_m_Memory; // [esp+14h] [ebp-4h]

  v1 = (CUtlFixedMemory<UtlLinkedListElem_t<Texture_t,int> > *)this;
  p_m_Memory = &this->m_Memory;
  if ( this->m_LastAlloc.m_pBlockHeader != nullptr || this->m_LastAlloc.m_nIndex != -1 )
  {
    if ( this->m_Memory.m_pBlocks != nullptr )
    {
      result.m_pBlockHeader = (CUtlFixedMemory<UtlLinkedListElem_t<Texture_t,int> >::BlockHeader_t *)this->m_Memory.m_pBlocks;
      result.m_nIndex = 0;
    }
    else
    {
      result.m_pBlockHeader = nullptr;
      result.m_nIndex = -1;
    }
    for ( i = &result;
          ;
          i = CUtlFixedMemory<UtlLinkedListElem_t<IDirect3DPixelShader9 *,int>>::Next(
                this: v1,
                (CUtlFixedMemory<UtlLinkedListElem_t<IDirect3DVertexShader9 *,int> >::Iterator_t *)&result,
                (const CUtlFixedMemory<UtlLinkedListElem_t<Texture_t,int> >::Iterator_t *)&it) )
    {
      v3 = *(CUtlFixedMemory<UtlLinkedListElem_t<CShaderManager::ShaderLookup_t,int> >::BlockHeader_t **)i;
      v4 = *((_DWORD *)i + 1);
      it.m_nIndex = v4;
      it.m_pBlockHeader = v3;
      if ( v3 != nullptr )
      {
        if ( v4 >= 0 && v4 < v3->m_nBlockSize )
        {
          if ( (CUtlFixedMemory<UtlLinkedListElem_t<CShaderManager::ShaderLookup_t,int> >::BlockHeader_t *)((char *)v3 + 52 * v4) == (CUtlFixedMemory<UtlLinkedListElem_t<CShaderManager::ShaderLookup_t,int> >::BlockHeader_t *)-8
            || CUtlFixedMemory<UtlLinkedListElem_t<CShaderManager::ShaderLookup_t,int>>::IsIdxAfter(
                 this: p_m_Memory,
                 i: (unsigned int)&v3[1] + 52 * v4,
                 it: (const CUtlFixedMemory<UtlLinkedListElem_t<CShaderManager::ShaderLookup_t,int> >::Iterator_t *)&p_m_Memory[2].m_nGrowSize)
            || *((CUtlFixedMemory<UtlLinkedListElem_t<CShaderManager::ShaderLookup_t,int> >::BlockHeader_t **)&v3[6].m_nBlockSize
               + 13 * v4) == (CUtlFixedMemory<UtlLinkedListElem_t<CShaderManager::ShaderLookup_t,int> >::BlockHeader_t *)((char *)&v3[1] + 52 * v4)
            && *(&v3[7].m_pNext + 13 * v4) != (CUtlFixedMemory<UtlLinkedListElem_t<CShaderManager::ShaderLookup_t,int> >::BlockHeader_t *)((char *)&v3[1] + 52 * v4) )
          {
            v1 = (CUtlFixedMemory<UtlLinkedListElem_t<Texture_t,int> > *)p_m_Memory;
          }
          else
          {
            v5 = p_m_Memory;
            *(&v3[6].m_nBlockSize + 13 * v4) = (int)v3 + 52 * v4 + 8;
            *((_DWORD *)&v3[7].m_pNext + 13 * v4) = v5[1].m_nGrowSize;
            v5[1].m_nGrowSize = (int)&v3[1] + 52 * v4;
            v1 = (CUtlFixedMemory<UtlLinkedListElem_t<Texture_t,int> > *)v5;
          }
        }
      }
      else if ( v4 == -1 )
      {
        break;
      }
      if ( v3 == (CUtlFixedMemory<UtlLinkedListElem_t<CShaderManager::ShaderLookup_t,int> >::BlockHeader_t *)v1[2].m_nGrowSize
        && (CUtlFixedMemory<UtlLinkedListElem_t<Texture_t,int> >::BlockHeader_t *)v4 == v1[3].m_pBlocks )
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
// Address: 0x1002FFF0
// Name: public: int CUtlVector<struct ShaderComboSemantics_t const __near *,class CUtlMemory<struct ShaderComboSemantics_t const __near *,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<ShaderComboSemantics_t const *,CUtlMemory<ShaderComboSemantics_t const *,int>>::InsertMultipleBefore(
        CUtlVector<ShaderComboSemantics_t const *,CUtlMemory<ShaderComboSemantics_t const *,int> > *this,
        int elem,
        int num)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  const ShaderComboSemantics_t **m_pMemory; // ecx
  int v8; // eax
  int v9; // eax

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<void (__cdecl *)(D3DDeviceWrapper *,DynamicState_t const &,DynamicState_t &,bool),int>::Grow(
      (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)this,
      num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v8 = this->m_Size;
  this->m_pElements = this->m_Memory.m_pMemory;
  v9 = v8 - elem - num;
  if ( v9 > 0 && num > 0 )
    _V_memmove(dest: &m_pMemory[elem] + num, src: &m_pMemory[elem], count: 4 * v9);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x10030060
// Name: public: void CUtlLinkedList<struct ShaderFileCache_t,int,1,int,class CUtlFixedMemory<struct UtlLinkedListElem_t<struct ShaderFileCache_t,int>>>::Unlink(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<ShaderFileCache_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<ShaderFileCache_t,int>>>::Unlink(
        CUtlLinkedList<ShaderFileCache_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<ShaderFileCache_t,int> > > *this,
        unsigned int elem)
{
  int v3; // ecx
  int v4; // eax

  if ( elem != 0
    && !CUtlFixedMemory<UtlLinkedListElem_t<ShaderFileCache_t,int>>::IsIdxAfter(
          this: &this->m_Memory,
          i: elem,
          it: &this->m_LastAlloc)
    && *(_DWORD *)(elem + 124) != elem )
  {
    v3 = *(_DWORD *)(elem + 124);
    v4 = *(_DWORD *)(elem + 128);
    if ( v3 != 0 )
      *(_DWORD *)(v3 + 128) = v4;
    else
      this->m_Head = v4;
    if ( v4 != 0 )
    {
      *(_DWORD *)(v4 + 124) = v3;
      --this->m_ElementCount;
    }
    else
    {
      --this->m_ElementCount;
      this->m_Tail = v3;
    }
    *(_DWORD *)(elem + 128) = elem;
    *(_DWORD *)(elem + 124) = elem;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100300D0
// Name: public: ShaderFileCache_t::~ShaderFileCache_t(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ShaderFileCache_t::~ShaderFileCache_t(ShaderFileCache_t *this)
{
  CUtlVector<CTransitionTable::ShadowStateDictEntry_t,CUtlMemory<CTransitionTable::ShadowStateDictEntry_t,int>>::~CUtlVector<CTransitionTable::ShadowStateDictEntry_t,CUtlMemory<CTransitionTable::ShadowStateDictEntry_t,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&this->m_StaticComboDupRecords);
  CUtlVector<CTransitionTable::ShadowStateDictEntry_t,CUtlMemory<CTransitionTable::ShadowStateDictEntry_t,int>>::~CUtlVector<CTransitionTable::ShadowStateDictEntry_t,CUtlMemory<CTransitionTable::ShadowStateDictEntry_t,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&this->m_StaticComboRecords);
  if ( this->m_ReferenceCombo.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_ReferenceCombo.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_ReferenceCombo.m_Memory.m_pMemory);
      this->m_ReferenceCombo.m_Memory.m_pMemory = nullptr;
    }
    this->m_ReferenceCombo.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10030110
// Name: public: void CUtlLinkedList<struct IDirect3DVertexShader9 __near *,int,1,int,class CUtlFixedMemory<struct UtlLinkedListElem_t<struct IDirect3DVertexShader9 __near *,int>>>::Free(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<IDirect3DVertexShader9 *,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<IDirect3DVertexShader9 *,int>>>::Free(
        CUtlLinkedList<IDirect3DPixelShader9 *,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<IDirect3DPixelShader9 *,int> > > *this,
        int elem)
{
  int v3; // eax
  int v4; // eax

  if ( elem != 0
    && !CUtlFixedMemory<UtlLinkedListElem_t<IDirect3DPixelShader9 *,int>>::IsIdxAfter(
          this: &this->m_Memory,
          i: elem,
          it: &this->m_LastAlloc) )
  {
    v3 = *(_DWORD *)(elem + 4);
    if ( v3 != elem )
    {
      if ( v3 != 0 )
        *(_DWORD *)(v3 + 8) = *(_DWORD *)(elem + 8);
      else
        this->m_Head = *(_DWORD *)(elem + 8);
      v4 = *(_DWORD *)(elem + 8);
      if ( v4 != 0 )
        *(_DWORD *)(v4 + 4) = *(_DWORD *)(elem + 4);
      else
        this->m_Tail = *(_DWORD *)(elem + 4);
      *(_DWORD *)(elem + 8) = elem;
      *(_DWORD *)(elem + 4) = elem;
      --this->m_ElementCount;
    }
  }
  *(_DWORD *)(elem + 8) = this->m_FirstFree;
  this->m_FirstFree = elem;
}

//------------------------------------------------------------------------------
// Address: 0x10030180
// Name: public: void CUtlLinkedList<struct IDirect3DPixelShader9 __near *,int,1,int,class CUtlFixedMemory<struct UtlLinkedListElem_t<struct IDirect3DPixelShader9 __near *,int>>>::LinkBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<IDirect3DPixelShader9 *,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<IDirect3DPixelShader9 *,int>>>::LinkBefore(
        CUtlLinkedList<IDirect3DPixelShader9 *,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<IDirect3DPixelShader9 *,int> > > *this,
        int before,
        int elem)
{
  int v4; // eax
  int v5; // eax
  int m_Tail; // eax

  if ( elem != 0
    && !CUtlFixedMemory<UtlLinkedListElem_t<IDirect3DPixelShader9 *,int>>::IsIdxAfter(
          this: &this->m_Memory,
          i: elem,
          it: &this->m_LastAlloc) )
  {
    v4 = *(_DWORD *)(elem + 4);
    if ( v4 != elem )
    {
      if ( v4 != 0 )
        *(_DWORD *)(v4 + 8) = *(_DWORD *)(elem + 8);
      else
        this->m_Head = *(_DWORD *)(elem + 8);
      v5 = *(_DWORD *)(elem + 8);
      if ( v5 != 0 )
        *(_DWORD *)(v5 + 4) = *(_DWORD *)(elem + 4);
      else
        this->m_Tail = *(_DWORD *)(elem + 4);
      *(_DWORD *)(elem + 8) = elem;
      *(_DWORD *)(elem + 4) = elem;
      --this->m_ElementCount;
    }
  }
  *(_DWORD *)(elem + 8) = before;
  if ( before != 0 )
  {
    m_Tail = *(_DWORD *)(before + 4);
    *(_DWORD *)(before + 4) = elem;
  }
  else
  {
    m_Tail = this->m_Tail;
    this->m_Tail = elem;
  }
  *(_DWORD *)(elem + 4) = m_Tail;
  if ( m_Tail != 0 )
  {
    *(_DWORD *)(m_Tail + 8) = elem;
    ++this->m_ElementCount;
  }
  else
  {
    ++this->m_ElementCount;
    this->m_Head = elem;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10030210
// Name: public: void CUtlLinkedList<struct CShaderManager::ShaderLookup_t,int,1,int,class CUtlFixedMemory<struct UtlLinkedListElem_t<struct CShaderManager::ShaderLookup_t,int>>>::LinkBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CShaderManager::ShaderLookup_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CShaderManager::ShaderLookup_t,int>>>::LinkBefore(
        CUtlLinkedList<CShaderManager::ShaderLookup_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CShaderManager::ShaderLookup_t,int> > > *this,
        int before,
        int elem)
{
  int v4; // eax
  int v5; // eax
  int m_Tail; // eax

  if ( elem != 0
    && !CUtlFixedMemory<UtlLinkedListElem_t<CShaderManager::ShaderLookup_t,int>>::IsIdxAfter(
          this: &this->m_Memory,
          i: elem,
          it: &this->m_LastAlloc) )
  {
    v4 = *(_DWORD *)(elem + 44);
    if ( v4 != elem )
    {
      if ( v4 != 0 )
        *(_DWORD *)(v4 + 48) = *(_DWORD *)(elem + 48);
      else
        this->m_Head = *(_DWORD *)(elem + 48);
      v5 = *(_DWORD *)(elem + 48);
      if ( v5 != 0 )
        *(_DWORD *)(v5 + 44) = *(_DWORD *)(elem + 44);
      else
        this->m_Tail = *(_DWORD *)(elem + 44);
      *(_DWORD *)(elem + 48) = elem;
      *(_DWORD *)(elem + 44) = elem;
      --this->m_ElementCount;
    }
  }
  *(_DWORD *)(elem + 48) = before;
  if ( before != 0 )
  {
    m_Tail = *(_DWORD *)(before + 44);
    *(_DWORD *)(before + 44) = elem;
  }
  else
  {
    m_Tail = this->m_Tail;
    this->m_Tail = elem;
  }
  *(_DWORD *)(elem + 44) = m_Tail;
  if ( m_Tail != 0 )
  {
    *(_DWORD *)(m_Tail + 48) = elem;
    ++this->m_ElementCount;
  }
  else
  {
    ++this->m_ElementCount;
    this->m_Head = elem;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100302A0
// Name: public: void CUtlVector<unsigned char,class CUtlMemory<unsigned char,int>>::SetSize(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<unsigned char,CUtlMemory<unsigned char,int>>::SetSize(
        CUtlVector<unsigned char,CUtlMemory<unsigned char,int> > *this,
        int size)
{
  int m_nAllocationCount; // eax
  unsigned __int8 *m_pMemory; // ecx
  int v5; // eax

  this->m_Size = 0;
  if ( size != 0 )
  {
    m_nAllocationCount = this->m_Memory.m_nAllocationCount;
    if ( size > m_nAllocationCount )
      CUtlMemory<unsigned char,int>::Grow(this: &this->m_Memory, num: size - m_nAllocationCount);
    this->m_Size += size;
    m_pMemory = this->m_Memory.m_pMemory;
    v5 = this->m_Size - size;
    this->m_pElements = this->m_Memory.m_pMemory;
    if ( v5 > 0 && size > 0 )
      _V_memmove(dest: &m_pMemory[size], src: m_pMemory, count: v5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100302F0
// Name: public: int CUtlLinkedList<struct ShaderFileCache_t,int,1,int,class CUtlFixedMemory<struct UtlLinkedListElem_t<struct ShaderFileCache_t,int>>>::InsertBefore(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<ShaderFileCache_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<ShaderFileCache_t,int>>>::InsertBefore(
        CUtlLinkedList<ShaderFileCache_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<ShaderFileCache_t,int> > > *this,
        int before)
{
  unsigned int v3; // eax
  int v4; // esi
  int m_Tail; // eax

  v3 = CUtlLinkedList<ShaderFileCache_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<ShaderFileCache_t,int>>>::AllocInternal(
         this,
         multilist: false);
  v4 = v3;
  if ( v3 == 0 )
    return 0;
  CUtlLinkedList<ShaderFileCache_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<ShaderFileCache_t,int>>>::Unlink(
    this,
    elem: v3);
  *(_DWORD *)(v4 + 128) = before;
  if ( before != 0 )
  {
    m_Tail = *(_DWORD *)(before + 124);
    *(_DWORD *)(v4 + 124) = m_Tail;
    *(_DWORD *)(before + 124) = v4;
  }
  else
  {
    m_Tail = this->m_Tail;
    *(_DWORD *)(v4 + 124) = m_Tail;
    this->m_Tail = v4;
  }
  if ( m_Tail != 0 )
    *(_DWORD *)(m_Tail + 128) = v4;
  else
    this->m_Head = v4;
  ++this->m_ElementCount;
  *(_DWORD *)v4 = -1;
  CUtlBuffer::CUtlBuffer(this: (CUtlBuffer *)(v4 + 36), growSize: 0, initSize: 0, nFlags: 0);
  *(_DWORD *)(v4 + 84) = 0;
  *(_DWORD *)(v4 + 88) = 0;
  *(_DWORD *)(v4 + 92) = 0;
  *(_DWORD *)(v4 + 96) = 0;
  *(_DWORD *)(v4 + 100) = 0;
  *(_DWORD *)(v4 + 104) = 0;
  *(_DWORD *)(v4 + 108) = 0;
  *(_DWORD *)(v4 + 112) = 0;
  *(_DWORD *)(v4 + 116) = 0;
  *(_DWORD *)(v4 + 120) = 0;
  *(_DWORD *)(v4 + 4) = 0;
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x10030390
// Name: public: virtual void CShaderManager::DestroyVertexShader(struct VertexShaderHandle_t__ __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderManager::DestroyVertexShader(CShaderManager *this, VertexShaderHandle_t__ *hShader)
{
  if ( hShader != nullptr )
  {
    (*(void (__stdcall **)(_DWORD))(**(_DWORD **)hShader + 8))(a1: *(_DWORD *)hShader);
    CUtlLinkedList<IDirect3DVertexShader9 *,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<IDirect3DVertexShader9 *,int>>>::Free(
      this: (CUtlLinkedList<IDirect3DPixelShader9 *,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<IDirect3DPixelShader9 *,int> > > *)&this->m_RawVertexShaderDict,
      elem: (int)hShader);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100303C0
// Name: public: virtual void CShaderManager::DestroyPixelShader(struct PixelShaderHandle_t__ __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderManager::DestroyPixelShader(CShaderManager *this, PixelShaderHandle_t__ *hShader)
{
  if ( hShader != nullptr )
  {
    (*(void (__stdcall **)(_DWORD))(**(_DWORD **)hShader + 8))(a1: *(_DWORD *)hShader);
    CUtlLinkedList<IDirect3DVertexShader9 *,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<IDirect3DVertexShader9 *,int>>>::Free(
      this: &this->m_RawPixelShaderDict,
      elem: (int)hShader);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100303F0
// Name: public: bool CShaderManager::CreateDynamicCombos_Ver4(void __near *,unsigned char __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CShaderManager::CreateDynamicCombos_Ver4(
        CShaderManager *this,
        void *pContext,
        unsigned __int8 *pComboBuffer)
{
  ShaderFileCache_t *v4; // edi
  int m_nNumStaticCombos; // eax
  int v6; // esi
  unsigned __int8 *v7; // edx
  void *v8; // esp
  int v9; // eax
  int v10; // ecx
  int v11; // eax
  int v12; // esi
  unsigned __int8 *v13; // edi
  bool v14; // zf
  int v15; // esi
  void *D3DVertexShader; // eax
  void *v17; // ecx
  int v19; // [esp-4h] [ebp-38h]
  int v20; // [esp+0h] [ebp-34h] BYREF
  CUtlSymbol id[2]; // [esp+Ch] [ebp-28h]
  int nOriginalSize; // [esp+10h] [ebp-24h] BYREF
  int nReferenceComboSizeForDiffs; // [esp+14h] [ebp-20h]
  int i; // [esp+18h] [ebp-1Ch]
  ShaderFileCache_t *pFileCache; // [esp+1Ch] [ebp-18h]
  unsigned __int8 *pReferenceShader; // [esp+20h] [ebp-14h]
  void *hardwareShader; // [esp+24h] [ebp-10h]
  unsigned __int8 *pDiffOutputBuffer; // [esp+28h] [ebp-Ch]
  int nStartingOffset; // [esp+2Ch] [ebp-8h]
  int v30; // [esp+30h] [ebp-4h]
  char bOK_3; // [esp+3Fh] [ebp+Bh]

  v4 = *((ShaderFileCache_t **)pContext + 8);
  m_nNumStaticCombos = v4->m_Header.m_nNumStaticCombos;
  v6 = 0;
  v7 = nullptr;
  *(_DWORD *)&id[0].m_Id = this;
  pFileCache = v4;
  nReferenceComboSizeForDiffs = m_nNumStaticCombos;
  pReferenceShader = nullptr;
  pDiffOutputBuffer = nullptr;
  if ( m_nNumStaticCombos != 0 )
  {
    pReferenceShader = v4->m_ReferenceCombo.m_Memory.m_pMemory;
    v8 = alloca(m_nNumStaticCombos);
    v7 = pReferenceShader;
    pDiffOutputBuffer = (unsigned __int8 *)&v20;
  }
  bOK_3 = 1;
  nStartingOffset = 0;
  i = 0;
  if ( v4->m_Header.m_nDynamicCombos > 0 )
  {
    v30 = 0;
    do
    {
      v9 = *((_DWORD *)pContext + 10);
      v10 = *(_DWORD *)(v9 + 8 * v6);
      v11 = v9 + 8 * v6;
      if ( v10 != -1 )
      {
        if ( nStartingOffset == 0 )
          nStartingOffset = v10;
        if ( *(int *)(v11 + 4) > 0 )
        {
          v12 = *(_DWORD *)(v11 + 4);
          v13 = &pComboBuffer[v10 + *((_DWORD *)pContext + 9) - nStartingOffset];
          if ( v7 != nullptr )
          {
            ApplyDiffs(
              OldBlock: v7,
              DiffList: v13,
              OldSize: nReferenceComboSizeForDiffs,
              DiffListSize: v12,
              ResultListSize: &nOriginalSize,
              Output: pDiffOutputBuffer,
              OutSize: nReferenceComboSizeForDiffs);
            v13 = pDiffOutputBuffer;
            v12 = nOriginalSize;
          }
          v14 = *(_BYTE *)(*(_DWORD *)&id[0].m_Id + 296) == 0;
          hardwareShader = nullptr;
          if ( v14 )
          {
            CUtlSymbolTable::String(
              this: (CUtlSymbolTable *)(*(_DWORD *)&id[0].m_Id + 100),
              id: *(CUtlSymbol *)pContext);
            if ( pFileCache->m_bVertexShader )
            {
              D3DVertexShader = CreateD3DVertexShader(pByteCode: (unsigned int *)v13, a2: v17, a3: v12);
            }
            else
            {
              D3DVertexShader = CreateD3DPixelShader(
                                  pByteCode: (unsigned int *)v13,
                                  nCentroidMask: pFileCache->m_Header.m_nCentroidMask);
              hardwareShader = D3DVertexShader;
            }
            if ( D3DVertexShader == nullptr )
            {
              bOK_3 = 0;
              break;
            }
          }
          else
          {
            CUtlVector<unsigned char,CUtlMemory<unsigned char,int>>::SetSize(
              this: (CUtlVector<unsigned char,CUtlMemory<unsigned char,int> > *)(v30 + *((_DWORD *)pContext + 5)),
              size: v12);
            v19 = v12;
            v15 = v30;
            _V_memcpy(dest: *(void **)(v30 + *((_DWORD *)pContext + 5)), src: v13, count: v19);
            if ( pFileCache->m_bVertexShader )
              *(_DWORD *)(v15 + *((_DWORD *)pContext + 5) + 20) = 0;
            else
              *(_DWORD *)(v15 + *((_DWORD *)pContext + 5) + 20) = pFileCache->m_Header.m_nCentroidMask;
            D3DVertexShader = hardwareShader;
          }
          v4 = pFileCache;
          v6 = i;
          *(_DWORD *)(*((_DWORD *)pContext + 4) + 4 * i) = D3DVertexShader;
          v7 = pReferenceShader;
        }
      }
      v30 += 24;
      i = ++v6;
    }
    while ( v6 < v4->m_Header.m_nDynamicCombos );
  }
  free(pMem: *((void **)pContext + 10));
  *((_DWORD *)pContext + 10) = 0;
  return bOK_3;
}

//------------------------------------------------------------------------------
// Address: 0x10030570
// Name: public: bool CShaderManager::CreateDynamicCombos_Ver5(void __near *,unsigned char __near *,char __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CShaderManager::CreateDynamicCombos_Ver5(
        CShaderManager *this,
        ShaderFileCache_t **pContext,
        unsigned __int8 *pComboBuffer,
        char *debugLabel)
{
  ShaderFileCache_t **v4; // esi
  unsigned __int8 *v5; // ebx
  unsigned __int8 *v6; // eax
  unsigned int v7; // edi
  unsigned int v8; // ebx
  unsigned int v9; // ecx
  unsigned __int8 *v10; // edi
  unsigned __int8 *v11; // ebx
  unsigned int v12; // eax
  int v13; // eax
  int *v14; // edi
  int v15; // eax
  int v16; // ebx
  ShaderFileCache_t *v17; // edx
  char *v18; // edi
  int v19; // ecx
  int v20; // ecx
  CUtlMemory<unsigned char,int> *v21; // esi
  int m_nAllocationCount; // eax
  unsigned __int8 *m_pMemory; // edx
  int v24; // eax
  void *D3DPixelShader; // eax
  D3DDeviceWrapper *v26; // esi
  unsigned __int8 *v28; // [esp+Ch] [ebp-28h]
  void *v30; // [esp+14h] [ebp-20h] BYREF
  ShaderFileCache_t *pFileCache; // [esp+18h] [ebp-1Ch]
  int iIndex; // [esp+1Ch] [ebp-18h] BYREF
  void *hardwareShader; // [esp+20h] [ebp-14h]
  int v34; // [esp+24h] [ebp-10h]
  unsigned __int8 *pUnpackBuffer; // [esp+28h] [ebp-Ch]
  unsigned __int8 *pCompressedShaders; // [esp+2Ch] [ebp-8h]
  CLZMA lzDecoder; // [esp+33h] [ebp-1h] BYREF
  char bOK_3; // [esp+43h] [ebp+Fh]

  v4 = pContext;
  v5 = (unsigned __int8 *)pContext[9] + (_DWORD)pComboBuffer;
  pFileCache = pContext[8];
  v6 = (unsigned __int8 *)operator new(nSize: 0x20000u);
  pUnpackBuffer = v6;
  bOK_3 = 1;
  while ( 1 )
  {
    v7 = *(_DWORD *)v5;
    pCompressedShaders = v5 + 4;
    v8 = v7;
    if ( v7 == -1 )
      break;
    v9 = v7 & 0xC0000000;
    if ( (v7 & 0xC0000000) != 0 )
    {
      if ( v9 == 0x40000000 )
      {
        v11 = pCompressedShaders;
        v12 = CLZMA::Uncompress(this: &lzDecoder, pInput: pCompressedShaders, pOutput: v6, pCallback: nullptr);
        pCompressedShaders = &v11[v7 & 0x3FFFFFFF];
        v8 = v12;
      }
      else if ( v9 == 0x80000000 )
      {
        v8 = v7 & 0x3FFFFFFF;
        v10 = pCompressedShaders;
        memcpy(dst: v6, src: pCompressedShaders, count: v8);
        pCompressedShaders = &v10[v8];
      }
      else
      {
        _Error(a1: " unrecognized shader compression type = file corrupt?");
        bOK_3 = 0;
      }
    }
    else
    {
      iIndex = 0x20000;
      v13 = BZ2_bzBuffToBuffDecompress(
              dest: (char *)v6,
              destLen: (unsigned int *)&iIndex,
              source: (char *)pCompressedShaders,
              sourceLen: v7,
              small: 1,
              verbosity: 0);
      if ( v13 < 0 )
      {
        _Warning(a1: "BZIP Error (%d) decompressing shader", v13);
        bOK_3 = 0;
      }
      pCompressedShaders += v7;
      v8 = iIndex;
    }
    v14 = (int *)pUnpackBuffer;
    v28 = &pUnpackBuffer[v8];
    if ( pUnpackBuffer < &pUnpackBuffer[v8] )
    {
      do
      {
        v15 = *v14;
        v16 = v14[1];
        v17 = v4[1];
        v18 = (char *)(v14 + 2);
        v19 = v15;
        hardwareShader = nullptr;
        iIndex = v15;
        if ( v15 >= (int)v17 )
        {
          iIndex = v15 - (_DWORD)v17;
          v19 = v15 - (_DWORD)v17;
        }
        if ( this->m_bCreateShadersOnDemand )
        {
          v20 = 24 * v19;
          v21 = (CUtlMemory<unsigned char,int> *)((char *)v4[5] + v20);
          v34 = v20;
          v21[1].m_pMemory = nullptr;
          if ( v16 != 0 )
          {
            m_nAllocationCount = v21->m_nAllocationCount;
            if ( v16 > m_nAllocationCount )
            {
              CUtlMemory<unsigned char,int>::Grow(this: v21, num: v16 - m_nAllocationCount);
              v20 = v34;
            }
            v21[1].m_pMemory += v16;
            m_pMemory = v21->m_pMemory;
            v24 = (int)&v21[1].m_pMemory[-v16];
            v21[1].m_nAllocationCount = (int)v21->m_pMemory;
            if ( v24 > 0 && v16 > 0 )
            {
              _V_memmove(dest: &m_pMemory[v16], src: m_pMemory, count: v24);
              v20 = v34;
            }
          }
          v4 = pContext;
          _V_memcpy(dest: *(void **)((char *)&pContext[5]->m_Name.m_Id + v20), src: v18, count: v16);
          if ( pFileCache->m_bVertexShader )
            *(unsigned int *)((char *)&pContext[5]->m_Header.m_nCentroidMask + v34) = 0;
          else
            *(unsigned int *)((char *)&pContext[5]->m_Header.m_nCentroidMask + v34) = pFileCache->m_Header.m_nCentroidMask;
          D3DPixelShader = hardwareShader;
        }
        else
        {
          CUtlSymbolTable::String(this: &this->m_ShaderSymbolTable, id: *(CUtlSymbol *)v4);
          if ( pFileCache->m_bVertexShader )
          {
            if ( r_emulategl.m_pParent != nullptr && r_emulategl.m_pParent->m_Value.m_nValue != 0 )
              D3DXGetShaderVersion(a1: v18);
            v26 = Dx9Device();
            D3DDeviceWrapper::Synchronize(this: v26);
            if ( v26->m_pD3DDevice->CreateVertexShader(
                   this: v26->m_pD3DDevice,
                   a2: (const unsigned int *)v18,
                   a3: (IDirect3DVertexShader9 **)&v30) >= 0 )
            {
              ++s_NumVertexShadersCreated;
              D3DPixelShader = v30;
              v4 = pContext;
            }
            else
            {
              v4 = pContext;
              v30 = nullptr;
              D3DPixelShader = nullptr;
            }
          }
          else
          {
            D3DPixelShader = CreateD3DPixelShader(
                               pByteCode: (unsigned int *)v18,
                               nCentroidMask: pFileCache->m_Header.m_nCentroidMask);
            hardwareShader = D3DPixelShader;
          }
          if ( D3DPixelShader == nullptr )
          {
            _Warning(a1: "failed to create shader\n");
            v6 = pUnpackBuffer;
            bOK_3 = 0;
            goto LABEL_40;
          }
          v4[3] = (ShaderFileCache_t *)((char *)v4[3] + 1);
        }
        v14 = (int *)&v18[v16];
        *((_DWORD *)&v4[4]->m_Name.m_Id + iIndex) = D3DPixelShader;
      }
      while ( v14 < (int *)v28 );
    }
    v6 = pUnpackBuffer;
    if ( bOK_3 == 0 )
      break;
    v5 = pCompressedShaders;
  }
LABEL_40:
  free(pMem: v6);
  return bOK_3;
}

//------------------------------------------------------------------------------
// Address: 0x10030810
// Name: private: void CShaderManager::DestroyVertexShader(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderManager::DestroyVertexShader(CShaderManager *this, int shader)
{
  int i; // esi
  int v4; // eax
  bool v5; // zf
  _DWORD *v6; // eax
  int v7; // eax
  void *v8; // ecx
  int v9; // ebx
  int v10; // edx
  int v11; // ebx
  int v12; // esi
  bool v13; // sf
  void *v14; // eax
  int v15; // eax
  int v16; // eax
  int shadera; // [esp+14h] [ebp+8h]

  for ( i = 0; i < *(_DWORD *)(shader + 8); ++i )
  {
    v4 = *(_DWORD *)(shader + 16);
    v5 = *(_DWORD *)(v4 + 4 * i) == 0;
    v6 = (_DWORD *)(v4 + 4 * i);
    if ( !v5 )
      (*(void (__stdcall **)(_DWORD))(*(_DWORD *)*v6 + 8))(a1: *v6);
  }
  free(pMem: *(void **)(shader + 16));
  v7 = *(_DWORD *)(shader + 20);
  *(_DWORD *)(shader + 16) = 0;
  if ( v7 != 0 )
  {
    v8 = (void *)(v7 - 4);
    v9 = *(_DWORD *)(v7 - 4);
    v10 = 3 * v9;
    v11 = v9 - 1;
    shadera = v7 - 4;
    v12 = v7 + 8 * v10;
    if ( v11 >= 0 )
    {
      do
      {
        v12 -= 24;
        v13 = *(int *)(v12 + 8) < 0;
        *(_DWORD *)(v12 + 12) = 0;
        if ( !v13 )
        {
          if ( *(_DWORD *)v12 != 0 )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *(void **)v12);
            *(_DWORD *)v12 = 0;
          }
          *(_DWORD *)(v12 + 4) = 0;
        }
        v13 = *(int *)(v12 + 8) < 0;
        v14 = *(void **)v12;
        *(_DWORD *)(v12 + 16) = *(_DWORD *)v12;
        if ( !v13 )
        {
          if ( v14 != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v14);
            *(_DWORD *)v12 = 0;
          }
          *(_DWORD *)(v12 + 4) = 0;
        }
        --v11;
      }
      while ( v11 >= 0 );
      v8 = (void *)shadera;
    }
    free(pMem: v8);
    *(_DWORD *)(shader + 20) = 0;
  }
  if ( shader != 0
    && !CUtlFixedMemory<UtlLinkedListElem_t<CShaderManager::ShaderLookup_t,int>>::IsIdxAfter(
          this: &this->m_VertexShaderDict.m_Memory,
          i: shader,
          it: &this->m_VertexShaderDict.m_LastAlloc) )
  {
    v15 = *(_DWORD *)(shader + 44);
    if ( v15 != shader )
    {
      if ( v15 != 0 )
        *(_DWORD *)(v15 + 48) = *(_DWORD *)(shader + 48);
      else
        this->m_VertexShaderDict.m_Head = *(_DWORD *)(shader + 48);
      v16 = *(_DWORD *)(shader + 48);
      if ( v16 != 0 )
        *(_DWORD *)(v16 + 44) = *(_DWORD *)(shader + 44);
      else
        this->m_VertexShaderDict.m_Tail = *(_DWORD *)(shader + 44);
      *(_DWORD *)(shader + 48) = shader;
      *(_DWORD *)(shader + 44) = shader;
      --this->m_VertexShaderDict.m_ElementCount;
    }
  }
  *(_DWORD *)(shader + 48) = this->m_VertexShaderDict.m_FirstFree;
  this->m_VertexShaderDict.m_FirstFree = shader;
}

//------------------------------------------------------------------------------
// Address: 0x10030950
// Name: private: void CShaderManager::DestroyPixelShader(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderManager::DestroyPixelShader(CShaderManager *this, int pixelShader)
{
  int i; // esi
  int v4; // eax
  bool v5; // zf
  _DWORD *v6; // eax
  int v7; // eax
  void *v8; // ecx
  int v9; // ebx
  int v10; // edx
  int v11; // ebx
  int v12; // esi
  bool v13; // sf
  void *v14; // eax
  int v15; // eax
  int v16; // eax
  int pixelShadera; // [esp+14h] [ebp+8h]

  for ( i = 0; i < *(_DWORD *)(pixelShader + 8); ++i )
  {
    v4 = *(_DWORD *)(pixelShader + 16);
    v5 = *(_DWORD *)(v4 + 4 * i) == 0;
    v6 = (_DWORD *)(v4 + 4 * i);
    if ( !v5 )
      (*(void (__stdcall **)(_DWORD))(*(_DWORD *)*v6 + 8))(a1: *v6);
  }
  free(pMem: *(void **)(pixelShader + 16));
  v7 = *(_DWORD *)(pixelShader + 20);
  *(_DWORD *)(pixelShader + 16) = 0;
  if ( v7 != 0 )
  {
    v8 = (void *)(v7 - 4);
    v9 = *(_DWORD *)(v7 - 4);
    v10 = 3 * v9;
    v11 = v9 - 1;
    pixelShadera = v7 - 4;
    v12 = v7 + 8 * v10;
    if ( v11 >= 0 )
    {
      do
      {
        v12 -= 24;
        v13 = *(int *)(v12 + 8) < 0;
        *(_DWORD *)(v12 + 12) = 0;
        if ( !v13 )
        {
          if ( *(_DWORD *)v12 != 0 )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *(void **)v12);
            *(_DWORD *)v12 = 0;
          }
          *(_DWORD *)(v12 + 4) = 0;
        }
        v13 = *(int *)(v12 + 8) < 0;
        v14 = *(void **)v12;
        *(_DWORD *)(v12 + 16) = *(_DWORD *)v12;
        if ( !v13 )
        {
          if ( v14 != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v14);
            *(_DWORD *)v12 = 0;
          }
          *(_DWORD *)(v12 + 4) = 0;
        }
        --v11;
      }
      while ( v11 >= 0 );
      v8 = (void *)pixelShadera;
    }
    free(pMem: v8);
    *(_DWORD *)(pixelShader + 20) = 0;
  }
  if ( pixelShader != 0
    && !CUtlFixedMemory<UtlLinkedListElem_t<CShaderManager::ShaderLookup_t,int>>::IsIdxAfter(
          this: &this->m_PixelShaderDict.m_Memory,
          i: pixelShader,
          it: &this->m_PixelShaderDict.m_LastAlloc) )
  {
    v15 = *(_DWORD *)(pixelShader + 44);
    if ( v15 != pixelShader )
    {
      if ( v15 != 0 )
        *(_DWORD *)(v15 + 48) = *(_DWORD *)(pixelShader + 48);
      else
        this->m_PixelShaderDict.m_Head = *(_DWORD *)(pixelShader + 48);
      v16 = *(_DWORD *)(pixelShader + 48);
      if ( v16 != 0 )
        *(_DWORD *)(v16 + 44) = *(_DWORD *)(pixelShader + 44);
      else
        this->m_PixelShaderDict.m_Tail = *(_DWORD *)(pixelShader + 44);
      *(_DWORD *)(pixelShader + 48) = pixelShader;
      *(_DWORD *)(pixelShader + 44) = pixelShader;
      --this->m_PixelShaderDict.m_ElementCount;
    }
  }
  *(_DWORD *)(pixelShader + 48) = this->m_PixelShaderDict.m_FirstFree;
  this->m_PixelShaderDict.m_FirstFree = pixelShader;
}

//------------------------------------------------------------------------------
// Address: 0x10030A90
// Name: public: void CUtlLinkedList<struct ShaderFileCache_t,int,1,int,class CUtlFixedMemory<struct UtlLinkedListElem_t<struct ShaderFileCache_t,int>>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<ShaderFileCache_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<ShaderFileCache_t,int>>>::RemoveAll(
        CUtlLinkedList<ShaderFileCache_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<ShaderFileCache_t,int> > > *this)
{
  CUtlFixedMemory<UtlLinkedListElem_t<Texture_t,int> > *v1; // esi
  void *i; // eax
  CUtlFixedMemory<UtlLinkedListElem_t<ShaderFileCache_t,int> >::BlockHeader_t *v3; // edi
  int v4; // ebx
  CUtlFixedMemory<UtlLinkedListElem_t<ShaderFileCache_t,int> > *v5; // eax
  CUtlFixedMemory<UtlLinkedListElem_t<Texture_t,int> >::Iterator_t result; // [esp+4h] [ebp-14h] BYREF
  CUtlFixedMemory<UtlLinkedListElem_t<ShaderFileCache_t,int> >::Iterator_t it; // [esp+Ch] [ebp-Ch] BYREF
  CUtlFixedMemory<UtlLinkedListElem_t<ShaderFileCache_t,int> > *p_m_Memory; // [esp+14h] [ebp-4h]

  v1 = (CUtlFixedMemory<UtlLinkedListElem_t<Texture_t,int> > *)this;
  p_m_Memory = &this->m_Memory;
  if ( this->m_LastAlloc.m_pBlockHeader != nullptr || this->m_LastAlloc.m_nIndex != -1 )
  {
    if ( this->m_Memory.m_pBlocks != nullptr )
    {
      result.m_pBlockHeader = (CUtlFixedMemory<UtlLinkedListElem_t<Texture_t,int> >::BlockHeader_t *)this->m_Memory.m_pBlocks;
      result.m_nIndex = 0;
    }
    else
    {
      result.m_pBlockHeader = nullptr;
      result.m_nIndex = -1;
    }
    for ( i = &result;
          ;
          i = CUtlFixedMemory<UtlLinkedListElem_t<IDirect3DPixelShader9 *,int>>::Next(
                this: v1,
                (CUtlFixedMemory<UtlLinkedListElem_t<IDirect3DVertexShader9 *,int> >::Iterator_t *)&result,
                (const CUtlFixedMemory<UtlLinkedListElem_t<Texture_t,int> >::Iterator_t *)&it) )
    {
      v3 = *(CUtlFixedMemory<UtlLinkedListElem_t<ShaderFileCache_t,int> >::BlockHeader_t **)i;
      v4 = *((_DWORD *)i + 1);
      it.m_nIndex = v4;
      it.m_pBlockHeader = v3;
      if ( v3 != nullptr )
      {
        if ( v4 >= 0 && v4 < v3->m_nBlockSize )
        {
          if ( (CUtlFixedMemory<UtlLinkedListElem_t<ShaderFileCache_t,int> >::BlockHeader_t *)((char *)v3 + 132 * v4) == (CUtlFixedMemory<UtlLinkedListElem_t<ShaderFileCache_t,int> >::BlockHeader_t *)-8
            || CUtlFixedMemory<UtlLinkedListElem_t<ShaderFileCache_t,int>>::IsIdxAfter(
                 this: p_m_Memory,
                 i: (unsigned int)&v3[1] + 132 * v4,
                 it: (const CUtlFixedMemory<UtlLinkedListElem_t<ShaderFileCache_t,int> >::Iterator_t *)&p_m_Memory[2].m_nGrowSize)
            || *((CUtlFixedMemory<UtlLinkedListElem_t<ShaderFileCache_t,int> >::BlockHeader_t **)&v3[16].m_nBlockSize
               + 33 * v4) == (CUtlFixedMemory<UtlLinkedListElem_t<ShaderFileCache_t,int> >::BlockHeader_t *)((char *)&v3[1] + 132 * v4)
            && *(&v3[17].m_pNext + 33 * v4) != (CUtlFixedMemory<UtlLinkedListElem_t<ShaderFileCache_t,int> >::BlockHeader_t *)((char *)&v3[1] + 132 * v4) )
          {
            v1 = (CUtlFixedMemory<UtlLinkedListElem_t<Texture_t,int> > *)p_m_Memory;
          }
          else
          {
            CUtlVector<CTransitionTable::ShadowStateDictEntry_t,CUtlMemory<CTransitionTable::ShadowStateDictEntry_t,int>>::~CUtlVector<CTransitionTable::ShadowStateDictEntry_t,CUtlMemory<CTransitionTable::ShadowStateDictEntry_t,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)((char *)&v3[14] + 132 * v4));
            CUtlVector<CTransitionTable::ShadowStateDictEntry_t,CUtlMemory<CTransitionTable::ShadowStateDictEntry_t,int>>::~CUtlVector<CTransitionTable::ShadowStateDictEntry_t,CUtlMemory<CTransitionTable::ShadowStateDictEntry_t,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)(&v3[11].m_nBlockSize + 33 * v4));
            if ( *(&v3[6].m_nBlockSize + 33 * v4) >= 0 )
            {
              if ( *(&v3[5].m_nBlockSize + 33 * v4) != 0 )
              {
                _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *((void **)&v3[5].m_nBlockSize + 33 * v4));
                *(&v3[5].m_nBlockSize + 33 * v4) = 0;
              }
              *((_DWORD *)&v3[6].m_pNext + 33 * v4) = 0;
            }
            v5 = p_m_Memory;
            *(&v3[16].m_nBlockSize + 33 * v4) = (int)v3 + 132 * v4 + 8;
            *((_DWORD *)&v3[17].m_pNext + 33 * v4) = v5[1].m_nGrowSize;
            v5[1].m_nGrowSize = (int)&v3[1] + 132 * v4;
            v1 = (CUtlFixedMemory<UtlLinkedListElem_t<Texture_t,int> > *)v5;
          }
        }
      }
      else if ( v4 == -1 )
      {
        break;
      }
      if ( v3 == (CUtlFixedMemory<UtlLinkedListElem_t<ShaderFileCache_t,int> >::BlockHeader_t *)v1[2].m_nGrowSize
        && (CUtlFixedMemory<UtlLinkedListElem_t<Texture_t,int> >::BlockHeader_t *)v4 == v1[3].m_pBlocks )
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
// Address: 0x10030BB0
// Name: public: virtual struct VertexShaderHandle_t__ __near * CShaderManager::CreateVertexShader(class IShaderBuffer __near *)
// Source: json
//------------------------------------------------------------------------------
VertexShaderHandle_t__ *__thiscall CShaderManager::CreateVertexShader(
        CShaderManager *this,
        IShaderBuffer *pShaderBuffer)
{
  const void *(__thiscall *GetBits)(IShaderBuffer *); // edx
  int v3; // ebx
  D3DDeviceWrapper *v4; // edi
  unsigned int (__thiscall *GetSize)(IShaderBuffer *); // edx
  VertexShaderHandle_t__ *result; // eax
  VertexShaderHandle_t__ *v7; // esi
  IDirect3DVertexShader9 *pVertexShader; // [esp+10h] [ebp-4h] BYREF

  GetBits = pShaderBuffer->GetBits;
  pVertexShader = nullptr;
  v3 = (int)GetBits(this: pShaderBuffer);
  v4 = Dx9Device();
  D3DDeviceWrapper::Synchronize(this: v4);
  if ( v4->m_pD3DDevice->CreateVertexShader(this: v4->m_pD3DDevice, a2: (const unsigned int *)v3, a3: &pVertexShader) < 0
    || pVertexShader == nullptr )
  {
    return nullptr;
  }
  GetSize = pShaderBuffer->GetSize;
  ++s_NumVertexShadersCreated;
  GetSize(this: pShaderBuffer);
  pShaderBuffer->GetBits(this: pShaderBuffer);
  result = (VertexShaderHandle_t__ *)CUtlLinkedList<IDirect3DVertexShader9 *,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<IDirect3DVertexShader9 *,int>>>::AllocInternal(
                                       this: &this->m_RawVertexShaderDict,
                                       multilist: false);
  v7 = result;
  if ( result != nullptr )
  {
    CUtlLinkedList<IDirect3DPixelShader9 *,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<IDirect3DPixelShader9 *,int>>>::LinkBefore(
      this: (CUtlLinkedList<IDirect3DPixelShader9 *,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<IDirect3DPixelShader9 *,int> > > *)&this->m_RawVertexShaderDict,
      before: 0,
      elem: (int)result);
    *(_DWORD *)v7 = pVertexShader;
    return v7;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10030C60
// Name: public: virtual struct PixelShaderHandle_t__ __near * CShaderManager::CreatePixelShader(class IShaderBuffer __near *)
// Source: json
//------------------------------------------------------------------------------
PixelShaderHandle_t__ *__thiscall CShaderManager::CreatePixelShader(CShaderManager *this, IShaderBuffer *pShaderBuffer)
{
  const void *(__thiscall *GetBits)(IShaderBuffer *); // edx
  int v3; // ebx
  D3DDeviceWrapper *v4; // edi
  unsigned int (__thiscall *GetSize)(IShaderBuffer *); // edx
  PixelShaderHandle_t__ *result; // eax
  PixelShaderHandle_t__ *v7; // esi
  IDirect3DPixelShader9 *pPixelShader; // [esp+10h] [ebp-4h] BYREF

  GetBits = pShaderBuffer->GetBits;
  pPixelShader = nullptr;
  v3 = (int)GetBits(this: pShaderBuffer);
  v4 = Dx9Device();
  D3DDeviceWrapper::Synchronize(this: v4);
  if ( v4->m_pD3DDevice->CreatePixelShader(this: v4->m_pD3DDevice, a2: (const unsigned int *)v3, a3: &pPixelShader) < 0
    || pPixelShader == nullptr )
  {
    return nullptr;
  }
  GetSize = pShaderBuffer->GetSize;
  ++s_NumPixelShadersCreated;
  GetSize(this: pShaderBuffer);
  pShaderBuffer->GetBits(this: pShaderBuffer);
  result = (PixelShaderHandle_t__ *)CUtlLinkedList<IDirect3DPixelShader9 *,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<IDirect3DPixelShader9 *,int>>>::AllocInternal(
                                      this: &this->m_RawPixelShaderDict,
                                      multilist: false);
  v7 = result;
  if ( result != nullptr )
  {
    CUtlLinkedList<IDirect3DPixelShader9 *,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<IDirect3DPixelShader9 *,int>>>::LinkBefore(
      this: &this->m_RawPixelShaderDict,
      before: 0,
      elem: (int)result);
    *(_DWORD *)v7 = pPixelShader;
    return v7;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10030D10
// Name: private: bool CShaderManager::LoadAndCreateShaders(struct CShaderManager::ShaderLookup_t __near &,bool,char __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CShaderManager::LoadAndCreateShaders(
        CShaderManager *this,
        CShaderManager::ShaderLookup_t *lookup,
        int bVertexShader,
        char *debugLabel)
{
  CShaderManager::ShaderLookup_t *v4; // ebx
  int m_Head; // eax
  unsigned __int16 v7; // cx
  int v8; // esi
  ShaderHeader_t *v9; // eax
  const char *v10; // eax
  void *Header; // edi
  const char *v13; // eax
  const char *v14; // eax
  unsigned __int16 v15; // cx
  unsigned __int16 v16; // cx
  ShaderHeader_t *v17; // eax
  char v18; // dl
  bool v19; // cc
  int m_nNumStaticCombos; // eax
  int v21; // eax
  ShaderHeader_t *v22; // eax
  CShaderManager *v23; // eax
  int v24; // ecx
  int *v25; // eax
  int v26; // ecx
  _DWORD *v27; // eax
  int v28; // ecx
  CShaderManager::ShaderStaticCombos_t::ShaderCreationData_t *v29; // eax
  ShaderHeader_t *v30; // ecx
  int i; // eax
  ShaderDictionaryEntry_t *v32; // eax
  int v33; // ecx
  void (__thiscall *Seek)(IBaseFileSystem *, void *, int, FileSystemSeek_t); // edx
  const char *v35; // eax
  int *p_m_Offset; // eax
  int m_nDynamicCombos; // edx
  const char *v38; // eax
  StaticComboAliasRecord_t *m_pMemory; // eax
  StaticComboRecord_t *v40; // eax
  int v41; // eax
  int v42; // eax
  const char *v43; // edi
  int v44; // ecx
  int v45; // edx
  CShaderManager::ShaderLookup_t *v46; // eax
  unsigned int v47; // esi
  unsigned int v48; // eax
  IFileSystem_vtbl *v49; // edx
  void *(__thiscall *AllocOptimalReadBuffer)(IFileSystem *, void *, unsigned int, unsigned int); // eax
  CShaderManager::ShaderLookup_t *v51; // eax
  IBaseFileSystem_vtbl *v52; // edx
  char DynamicCombos_Ver5; // al
  StaticComboAliasRecord_t *v54; // eax
  StaticComboRecord_t *v55; // eax
  int v56; // [esp-8h] [ebp-1B4h]
  unsigned int v57; // [esp-8h] [ebp-1B4h]
  unsigned __int16 m_Id; // [esp-4h] [ebp-1B0h]
  const StaticComboAliasRecord_t *v59; // [esp-4h] [ebp-1B0h]
  char filename[260]; // [esp+Ch] [ebp-1A0h] BYREF
  unsigned int nBufferAlign; // [esp+110h] [ebp-9Ch] BYREF
  unsigned int nOffsetAlign; // [esp+114h] [ebp-98h] BYREF
  ShaderFileCache_t fileCacheLookup; // [esp+118h] [ebp-94h] BYREF
  unsigned int nSizeAlign; // [esp+194h] [ebp-18h] BYREF
  int nDictionaryOffset; // [esp+198h] [ebp-14h]
  IBaseFileSystem *v66; // [esp+19Ch] [ebp-10h]
  CUtlSymbolTable *p_m_ShaderSymbolTable; // [esp+1A0h] [ebp-Ch]
  CShaderManager *v68; // [esp+1A4h] [ebp-8h]
  ShaderHeader_t *pHeader; // [esp+1A8h] [ebp-4h]

  v4 = lookup;
  m_Id = lookup->m_Name.m_Id;
  v68 = this;
  p_m_ShaderSymbolTable = &this->m_ShaderSymbolTable;
  lookup = (CShaderManager::ShaderLookup_t *)CUtlSymbolTable::String(
                                               this: &this->m_ShaderSymbolTable,
                                               id: (CUtlSymbol)m_Id);
  *(_DWORD *)&fileCacheLookup.m_Name.m_Id = -1;
  CUtlBuffer::CUtlBuffer(this: &fileCacheLookup.m_ReferenceCombo, growSize: 0, initSize: 0, nFlags: 0);
  m_Head = this->m_ShaderFileCache.m_Head;
  v7 = v4->m_Name.m_Id;
  memset(&fileCacheLookup.m_StaticComboRecords, 0, 40);
  fileCacheLookup.m_Header.m_nVersion = 0;
  fileCacheLookup.m_Name.m_Id = v7;
  fileCacheLookup.m_bVertexShader = bVertexShader;
  if ( m_Head != 0 )
  {
    while ( *(_WORD *)m_Head != v7 || *(_BYTE *)(m_Head + 32) != (_BYTE)bVertexShader )
    {
      m_Head = *(_DWORD *)(m_Head + 128);
      if ( m_Head == 0 )
        goto LABEL_5;
    }
  }
  else
  {
LABEL_5:
    m_Head = CUtlLinkedList<ShaderFileCache_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<ShaderFileCache_t,int>>>::InsertBefore(
               this: &this->m_ShaderFileCache,
               before: 0);
  }
  v8 = m_Head;
  v9 = (ShaderHeader_t *)(m_Head + 4);
  v4->m_hShaderFileCache = v8;
  pHeader = v9;
  if ( v9->m_nVersion != 0 )
  {
    v10 = CUtlSymbolTable::String(this: p_m_ShaderSymbolTable, id: *(CUtlSymbol *)(v8 + 2));
    Header = CShaderManager::OpenFileAndLoadHeader(this: v68, pFileName: v10, pHeader: nullptr);
    if ( Header == nullptr )
    {
      CUtlVector<CTransitionTable::ShadowStateDictEntry_t,CUtlMemory<CTransitionTable::ShadowStateDictEntry_t,int>>::~CUtlVector<CTransitionTable::ShadowStateDictEntry_t,CUtlMemory<CTransitionTable::ShadowStateDictEntry_t,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&fileCacheLookup.m_StaticComboDupRecords);
      CUtlVector<CTransitionTable::ShadowStateDictEntry_t,CUtlMemory<CTransitionTable::ShadowStateDictEntry_t,int>>::~CUtlVector<CTransitionTable::ShadowStateDictEntry_t,CUtlMemory<CTransitionTable::ShadowStateDictEntry_t,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&fileCacheLookup.m_StaticComboRecords);
      if ( fileCacheLookup.m_ReferenceCombo.m_Memory.m_nGrowSize >= 0
        && fileCacheLookup.m_ReferenceCombo.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: fileCacheLookup.m_ReferenceCombo.m_Memory.m_pMemory);
      }
      return false;
    }
  }
  else
  {
    _V_memset(dest: v9, fill: 0, count: 28);
    v13 = "vsh";
    if ( (_BYTE)bVertexShader == 0 )
      v13 = "psh";
    V_snprintf(pDest: filename, maxLen: 260, pFormat: "shaders\\%s\\%s.vcs", v13, (const char *)lookup);
    Header = CShaderManager::OpenFileAndLoadHeader(this: v68, pFileName: filename, pHeader);
    if ( Header != nullptr )
    {
      v4->m_Flags |= 1u;
    }
    else
    {
      V_snprintf(pDest: filename, maxLen: 260, pFormat: "shaders\\fxc\\%s.vcs", (const char *)lookup);
      Header = CShaderManager::OpenFileAndLoadHeader(this: v68, pFileName: filename, pHeader);
      if ( Header == nullptr )
      {
        v4->m_Flags |= 2u;
        v14 = "vertex";
        if ( (_BYTE)bVertexShader == 0 )
          v14 = "pixel";
        _Warning(a1: "Couldn't load %s shader %s\n", v14, (const char *)lookup);
        ShaderFileCache_t::~ShaderFileCache_t(this: &fileCacheLookup);
        return false;
      }
    }
    v15 = v4->m_Name.m_Id;
    v4->m_Flags = pHeader->m_nFlags;
    *(_WORD *)v8 = v15;
    v16 = CUtlSymbolTable::AddString(this: p_m_ShaderSymbolTable, result: (CUtlSymbol *)&lookup + 1, pString: filename)->m_Id;
    v17 = pHeader;
    v18 = bVertexShader;
    *(_WORD *)(v8 + 2) = v16;
    v19 = v17->m_nVersion < 5;
    *(_BYTE *)(v8 + 32) = v18;
    m_nNumStaticCombos = v17->m_nNumStaticCombos;
    if ( v19 )
    {
      bVertexShader = m_nNumStaticCombos;
      if ( m_nNumStaticCombos != 0 )
      {
        CUtlBuffer::EnsureCapacity(this: (CUtlBuffer *)(v8 + 36), num: m_nNumStaticCombos);
        g_pFullFileSystem->Read(
          this: &g_pFullFileSystem->IBaseFileSystem,
          a2: *(void **)(v8 + 36),
          a3: bVertexShader,
          a4: Header);
      }
    }
    else
    {
      if ( *(_DWORD *)(v8 + 96) < m_nNumStaticCombos )
        CUtlVector<StaticComboAliasRecord_t,CUtlMemory<StaticComboAliasRecord_t,int>>::InsertMultipleBefore(
          this: (CUtlVector<StaticComboAliasRecord_t,CUtlMemory<StaticComboAliasRecord_t,int> > *)(v8 + 84),
          elem: *(_DWORD *)(v8 + 96),
          num: m_nNumStaticCombos - *(_DWORD *)(v8 + 96));
      g_pFullFileSystem->Read(
        this: &g_pFullFileSystem->IBaseFileSystem,
        a2: *(void **)(v8 + 84),
        a3: 8 * pHeader->m_nNumStaticCombos,
        a4: Header);
      if ( pHeader->m_nVersion == 6 )
      {
        g_pFullFileSystem->Read(this: &g_pFullFileSystem->IBaseFileSystem, a2: &bVertexShader, a3: 4, a4: Header);
        v21 = bVertexShader;
        if ( bVertexShader != 0 )
        {
          if ( *(_DWORD *)(v8 + 116) < bVertexShader )
          {
            CUtlVector<StaticComboAliasRecord_t,CUtlMemory<StaticComboAliasRecord_t,int>>::InsertMultipleBefore(
              this: (CUtlVector<StaticComboAliasRecord_t,CUtlMemory<StaticComboAliasRecord_t,int> > *)(v8 + 104),
              elem: *(_DWORD *)(v8 + 116),
              num: bVertexShader - *(_DWORD *)(v8 + 116));
            v21 = bVertexShader;
          }
          g_pFullFileSystem->Read(
            this: &g_pFullFileSystem->IBaseFileSystem,
            a2: *(void **)(v8 + 104),
            a3: 8 * v21,
            a4: Header);
        }
      }
    }
  }
  v22 = pHeader;
  v4->m_ShaderStaticCombos.m_nCount = pHeader->m_nDynamicCombos;
  v4->m_ShaderStaticCombos.m_pHardwareShaders = (void **)operator new(nSize: 4 * v22->m_nDynamicCombos);
  v23 = v68;
  v4->m_ShaderStaticCombos.m_nNumDynamicCombosAfterSkips = 0;
  if ( v23->m_bCreateShadersOnDemand )
  {
    bVertexShader = pHeader->m_nDynamicCombos;
    v24 = (24 * (unsigned __int64)(unsigned int)bVertexShader) >> 32 != 0 ? -1 : 24 * bVertexShader;
    v25 = (int *)operator new(nSize: __CFADD__(v24, 4) ? -1 : v24 + 4);
    if ( v25 != nullptr )
    {
      v26 = bVertexShader;
      *v25 = bVertexShader;
      v27 = v25 + 1;
      v28 = v26 - 1;
      for ( bVertexShader = (int)v27; v28 >= 0; --v28 )
      {
        *v27 = 0;
        v27[1] = 0;
        v27[2] = 0;
        v27[3] = 0;
        v27[4] = 0;
        v27 += 6;
      }
      v29 = (CShaderManager::ShaderStaticCombos_t::ShaderCreationData_t *)bVertexShader;
    }
    else
    {
      v29 = nullptr;
    }
    v4->m_ShaderStaticCombos.m_pCreationData = v29;
  }
  v30 = pHeader;
  for ( i = 0; i < v30->m_nDynamicCombos; ++i )
    v4->m_ShaderStaticCombos.m_pHardwareShaders[i] = nullptr;
  v19 = v30->m_nVersion < 5;
  bVertexShader = 0;
  lookup = nullptr;
  if ( v19 )
  {
    nDictionaryOffset = pHeader->m_nNumStaticCombos + 28;
    v66 = nullptr;
    v32 = (ShaderDictionaryEntry_t *)operator new(nSize: 8 * pHeader->m_nDynamicCombos);
    v33 = nDictionaryOffset;
    v4->m_pComboDictionary = v32;
    Seek = g_pFullFileSystem->Seek;
    v66 = &g_pFullFileSystem->IBaseFileSystem;
    Seek(
      this: &g_pFullFileSystem->IBaseFileSystem,
      a2: Header,
      a3: v33 + 8 * v4->m_nStaticIndex,
      a4: FILESYSTEM_SEEK_HEAD);
    if ( g_pFullFileSystem->Read(
           this: &g_pFullFileSystem->IBaseFileSystem,
           a2: v4->m_pComboDictionary,
           a3: 8 * pHeader->m_nDynamicCombos,
           a4: Header) == 0 )
    {
      g_pFullFileSystem->Close(this: &g_pFullFileSystem->IBaseFileSystem, a2: Header);
      v35 = CUtlSymbolTable::String(this: p_m_ShaderSymbolTable, id: *(CUtlSymbol *)(v8 + 2));
      _Warning(a1: "Shader '%s' - Cannot read, skipping.\n", v35);
      CUtlVector<CTransitionTable::ShadowStateDictEntry_t,CUtlMemory<CTransitionTable::ShadowStateDictEntry_t,int>>::~CUtlVector<CTransitionTable::ShadowStateDictEntry_t,CUtlMemory<CTransitionTable::ShadowStateDictEntry_t,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&fileCacheLookup.m_StaticComboDupRecords);
      CUtlVector<CTransitionTable::ShadowStateDictEntry_t,CUtlMemory<CTransitionTable::ShadowStateDictEntry_t,int>>::~CUtlVector<CTransitionTable::ShadowStateDictEntry_t,CUtlMemory<CTransitionTable::ShadowStateDictEntry_t,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&fileCacheLookup.m_StaticComboRecords);
      if ( fileCacheLookup.m_ReferenceCombo.m_Memory.m_nGrowSize < 0
        || fileCacheLookup.m_ReferenceCombo.m_Memory.m_pMemory == nullptr )
      {
        return false;
      }
      goto LABEL_43;
    }
    if ( pHeader->m_nDynamicCombos <= 0 )
      goto LABEL_52;
    p_m_Offset = &v4->m_pComboDictionary->m_Offset;
    m_nDynamicCombos = pHeader->m_nDynamicCombos;
    do
    {
      if ( *p_m_Offset != -1 )
      {
        if ( bVertexShader == 0 )
          bVertexShader = *p_m_Offset;
        lookup = (CShaderManager::ShaderLookup_t *)(*p_m_Offset + p_m_Offset[1]);
      }
      p_m_Offset += 2;
      --m_nDynamicCombos;
    }
    while ( m_nDynamicCombos != 0 );
    if ( bVertexShader == 0 )
    {
LABEL_52:
      g_pFullFileSystem->Close(this: &g_pFullFileSystem->IBaseFileSystem, a2: Header);
      v38 = CUtlSymbolTable::String(this: p_m_ShaderSymbolTable, id: *(CUtlSymbol *)(v8 + 2));
      _Warning(a1: "Shader '%s' - All dynamic combos skipped. This is bad!\n", v38);
      m_pMemory = fileCacheLookup.m_StaticComboDupRecords.m_Memory.m_pMemory;
      fileCacheLookup.m_StaticComboDupRecords.m_Size = 0;
      if ( fileCacheLookup.m_StaticComboDupRecords.m_Memory.m_nGrowSize >= 0 )
      {
        if ( fileCacheLookup.m_StaticComboDupRecords.m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: fileCacheLookup.m_StaticComboDupRecords.m_Memory.m_pMemory);
          m_pMemory = nullptr;
          fileCacheLookup.m_StaticComboDupRecords.m_Memory.m_pMemory = nullptr;
        }
        fileCacheLookup.m_StaticComboDupRecords.m_Memory.m_nAllocationCount = 0;
      }
      fileCacheLookup.m_StaticComboDupRecords.m_pElements = m_pMemory;
      if ( fileCacheLookup.m_StaticComboDupRecords.m_Memory.m_nGrowSize >= 0 )
      {
        if ( m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
          fileCacheLookup.m_StaticComboDupRecords.m_Memory.m_pMemory = nullptr;
        }
        fileCacheLookup.m_StaticComboDupRecords.m_Memory.m_nAllocationCount = 0;
      }
      v40 = fileCacheLookup.m_StaticComboRecords.m_Memory.m_pMemory;
      fileCacheLookup.m_StaticComboRecords.m_Size = 0;
      if ( fileCacheLookup.m_StaticComboRecords.m_Memory.m_nGrowSize >= 0 )
      {
        if ( fileCacheLookup.m_StaticComboRecords.m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: fileCacheLookup.m_StaticComboRecords.m_Memory.m_pMemory);
          v40 = nullptr;
          fileCacheLookup.m_StaticComboRecords.m_Memory.m_pMemory = nullptr;
        }
        fileCacheLookup.m_StaticComboRecords.m_Memory.m_nAllocationCount = 0;
      }
      fileCacheLookup.m_StaticComboRecords.m_pElements = v40;
      if ( fileCacheLookup.m_StaticComboRecords.m_Memory.m_nGrowSize >= 0 )
      {
        if ( v40 != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v40);
          fileCacheLookup.m_StaticComboRecords.m_Memory.m_pMemory = nullptr;
        }
        fileCacheLookup.m_StaticComboRecords.m_Memory.m_nAllocationCount = 0;
      }
      if ( fileCacheLookup.m_ReferenceCombo.m_Memory.m_nGrowSize >= 0
        && fileCacheLookup.m_ReferenceCombo.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: fileCacheLookup.m_ReferenceCombo.m_Memory.m_pMemory);
      }
      return false;
    }
  }
  else
  {
    v59 = *(const StaticComboAliasRecord_t **)(v8 + 104);
    v56 = *(_DWORD *)(v8 + 116);
    bVertexShader = v4->m_nStaticIndex / *(_DWORD *)(v8 + 12);
    v41 = BinarySearchCombos<StaticComboAliasRecord_t>(nStaticComboID: bVertexShader, nCombos: v56, pRecords: v59);
    if ( v41 != -1 )
      bVertexShader = *(_DWORD *)(*(_DWORD *)(v8 + 104) + 8 * v41 + 4);
    if ( pHeader->m_nVersion < 5
      || (v42 = BinarySearchCombos<StaticComboAliasRecord_t>(
                  nStaticComboID: bVertexShader,
                  nCombos: pHeader->m_nNumStaticCombos,
                  pRecords: *(const StaticComboAliasRecord_t **)(v8 + 84))) == -1 )
    {
      g_pFullFileSystem->Close(this: &g_pFullFileSystem->IBaseFileSystem, a2: Header);
      v4->m_Flags |= 2u;
      v43 = CUtlSymbolTable::String(this: p_m_ShaderSymbolTable, id: *(CUtlSymbol *)(v8 + 2));
      _Warning(a1: "*************************************************\n");
      _Warning(
        a1: "Shader '%s' - Couldn't load combo %d of shader (dyn=%d)\n",
        v43,
        v4->m_nStaticIndex,
        *(_DWORD *)(v8 + 12));
      BitchAboutSkippedCombo(
        a1: (int)v4,
        a2: (int)v43,
        a3: v8,
        pShaderName: v43,
        nStaticComboID: v4->m_nStaticIndex / *(_DWORD *)(v8 + 12),
        nDynamicComboID: -1);
      _Warning(a1: "*************************************************\n");
      CUtlVector<CTransitionTable::ShadowStateDictEntry_t,CUtlMemory<CTransitionTable::ShadowStateDictEntry_t,int>>::~CUtlVector<CTransitionTable::ShadowStateDictEntry_t,CUtlMemory<CTransitionTable::ShadowStateDictEntry_t,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&fileCacheLookup.m_StaticComboDupRecords);
      CUtlVector<CTransitionTable::ShadowStateDictEntry_t,CUtlMemory<CTransitionTable::ShadowStateDictEntry_t,int>>::~CUtlVector<CTransitionTable::ShadowStateDictEntry_t,CUtlMemory<CTransitionTable::ShadowStateDictEntry_t,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&fileCacheLookup.m_StaticComboRecords);
      if ( fileCacheLookup.m_ReferenceCombo.m_Memory.m_nGrowSize >= 0
        && fileCacheLookup.m_ReferenceCombo.m_Memory.m_pMemory != nullptr )
      {
LABEL_43:
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: fileCacheLookup.m_ReferenceCombo.m_Memory.m_pMemory);
        return false;
      }
      return false;
    }
    v44 = *(_DWORD *)(v8 + 84);
    v45 = *(_DWORD *)(v44 + 8 * v42 + 4);
    v46 = *(CShaderManager::ShaderLookup_t **)(v44 + 8 * v42 + 12);
    bVertexShader = v45;
    lookup = v46;
  }
  g_pFullFileSystem->GetOptimalIOConstraints(
    this: g_pFullFileSystem,
    a2: Header,
    a3: &nOffsetAlign,
    a4: &nSizeAlign,
    a5: &nBufferAlign);
  v47 = bVertexShader & ~(nOffsetAlign - 1);
  v48 = ~(nSizeAlign - 1) & ((unsigned int)lookup + nSizeAlign - v47 - 1);
  v4->m_nDataOffset = bVertexShader - v47;
  v49 = g_pFullFileSystem->IAppSystem::__vftable;
  v57 = v48;
  nDictionaryOffset = v48;
  AllocOptimalReadBuffer = v49->AllocOptimalReadBuffer;
  HIBYTE(bVertexShader) = 1;
  v51 = (CShaderManager::ShaderLookup_t *)AllocOptimalReadBuffer(this: g_pFullFileSystem, a2: Header, a3: v57, a4: v47);
  v52 = g_pFullFileSystem->IBaseFileSystem::__vftable;
  lookup = v51;
  v52->Seek(this: &g_pFullFileSystem->IBaseFileSystem, a2: Header, a3: v47, a4: FILESYSTEM_SEEK_HEAD);
  if ( g_pFullFileSystem->Read(this: &g_pFullFileSystem->IBaseFileSystem, a2: lookup, a3: nDictionaryOffset, a4: Header) != 0 )
  {
    if ( pHeader->m_nVersion >= 5 )
      DynamicCombos_Ver5 = CShaderManager::CreateDynamicCombos_Ver5(
                             this: v68,
                             pContext: (ShaderFileCache_t **)v4,
                             pComboBuffer: (unsigned __int8 *)lookup,
                             debugLabel);
    else
      DynamicCombos_Ver5 = CShaderManager::CreateDynamicCombos_Ver4(
                             this: v68,
                             pContext: v4,
                             pComboBuffer: (unsigned __int8 *)lookup);
    HIBYTE(bVertexShader) = DynamicCombos_Ver5;
  }
  g_pFullFileSystem->FreeOptimalReadBuffer(this: g_pFullFileSystem, a2: lookup);
  g_pFullFileSystem->Close(this: &g_pFullFileSystem->IBaseFileSystem, a2: Header);
  if ( HIBYTE(bVertexShader) == 0 )
    v4->m_Flags |= 2u;
  v54 = fileCacheLookup.m_StaticComboDupRecords.m_Memory.m_pMemory;
  fileCacheLookup.m_StaticComboDupRecords.m_Size = 0;
  if ( fileCacheLookup.m_StaticComboDupRecords.m_Memory.m_nGrowSize >= 0 )
  {
    if ( fileCacheLookup.m_StaticComboDupRecords.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: fileCacheLookup.m_StaticComboDupRecords.m_Memory.m_pMemory);
      v54 = nullptr;
      fileCacheLookup.m_StaticComboDupRecords.m_Memory.m_pMemory = nullptr;
    }
    fileCacheLookup.m_StaticComboDupRecords.m_Memory.m_nAllocationCount = 0;
  }
  fileCacheLookup.m_StaticComboDupRecords.m_pElements = v54;
  if ( fileCacheLookup.m_StaticComboDupRecords.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v54 != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v54);
      fileCacheLookup.m_StaticComboDupRecords.m_Memory.m_pMemory = nullptr;
    }
    fileCacheLookup.m_StaticComboDupRecords.m_Memory.m_nAllocationCount = 0;
  }
  v55 = fileCacheLookup.m_StaticComboRecords.m_Memory.m_pMemory;
  fileCacheLookup.m_StaticComboRecords.m_Size = 0;
  if ( fileCacheLookup.m_StaticComboRecords.m_Memory.m_nGrowSize >= 0 )
  {
    if ( fileCacheLookup.m_StaticComboRecords.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: fileCacheLookup.m_StaticComboRecords.m_Memory.m_pMemory);
      v55 = nullptr;
      fileCacheLookup.m_StaticComboRecords.m_Memory.m_pMemory = nullptr;
    }
    fileCacheLookup.m_StaticComboRecords.m_Memory.m_nAllocationCount = 0;
  }
  fileCacheLookup.m_StaticComboRecords.m_pElements = v55;
  if ( fileCacheLookup.m_StaticComboRecords.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v55 != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v55);
      fileCacheLookup.m_StaticComboRecords.m_Memory.m_pMemory = nullptr;
    }
    fileCacheLookup.m_StaticComboRecords.m_Memory.m_nAllocationCount = 0;
  }
  if ( fileCacheLookup.m_ReferenceCombo.m_Memory.m_nGrowSize >= 0
    && fileCacheLookup.m_ReferenceCombo.m_Memory.m_pMemory != nullptr )
  {
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: fileCacheLookup.m_ReferenceCombo.m_Memory.m_pMemory);
  }
  return HIBYTE(bVertexShader);
}

//------------------------------------------------------------------------------
// Address: 0x10031590
// Name: public: virtual int CShaderManager::CreateVertexShader(char const __near *,int,char __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CShaderManager::CreateVertexShader(
        CShaderManager *this,
        const char *pFileName,
        int nStaticVshIndex,
        char *debugLabel)
{
  unsigned __int16 m_Id; // cx
  int m_Head; // eax
  int v8; // eax
  int v9; // esi
  int v10; // ecx
  unsigned int m_hShaderFileCache; // edx
  int m_nDataOffset; // eax
  __int64 v13; // xmm0_8
  CShaderManager::ShaderLookup_t lookup; // [esp+8h] [ebp-2Ch]

  if ( pFileName == nullptr )
    return -1;
  lookup.m_ShaderStaticCombos.m_pHardwareShaders = nullptr;
  lookup.m_ShaderStaticCombos.m_pCreationData = nullptr;
  m_Id = CUtlSymbolTable::AddString(
           this: &this->m_ShaderSymbolTable,
           result: (CUtlSymbol *)&pFileName + 1,
           pString: pFileName)->m_Id;
  m_Head = this->m_VertexShaderDict.m_Head;
  lookup.m_Name.m_Id = m_Id;
  if ( m_Head != 0 )
  {
    while ( *(_WORD *)m_Head != m_Id || *(_DWORD *)(m_Head + 4) != nStaticVshIndex )
    {
      m_Head = *(_DWORD *)(m_Head + 48);
      if ( m_Head == 0 )
        goto LABEL_7;
    }
    v9 = m_Head;
    goto LABEL_10;
  }
LABEL_7:
  v8 = CUtlLinkedList<CShaderManager::ShaderLookup_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CShaderManager::ShaderLookup_t,int>>>::AllocInternal(
         this: &this->m_VertexShaderDict,
         multilist: false);
  v9 = v8;
  if ( v8 != 0 )
  {
    CUtlLinkedList<CShaderManager::ShaderLookup_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CShaderManager::ShaderLookup_t,int>>>::LinkBefore(
      this: &this->m_VertexShaderDict,
      before: 0,
      elem: v8);
    v10 = nStaticVshIndex;
    m_hShaderFileCache = lookup.m_hShaderFileCache;
    *(_WORD *)v9 = lookup.m_Name.m_Id;
    m_nDataOffset = lookup.m_nDataOffset;
    *(_QWORD *)(v9 + 8) = 0;
    v13 = *(_QWORD *)&lookup.m_ShaderStaticCombos.m_pHardwareShaders;
    *(_DWORD *)(v9 + 4) = v10;
    *(_QWORD *)(v9 + 16) = v13;
    *(_DWORD *)(v9 + 24) = 0;
    *(_DWORD *)(v9 + 28) = 0;
    *(_DWORD *)(v9 + 32) = m_hShaderFileCache;
    *(_DWORD *)(v9 + 36) = m_nDataOffset;
    *(_DWORD *)(v9 + 40) = 0;
  }
  else
  {
    v9 = 0;
  }
  if ( CShaderManager::LoadAndCreateShaders(
         this,
         lookup: (CShaderManager::ShaderLookup_t *)v9,
         bVertexShader: 1,
         debugLabel) )
  {
LABEL_10:
    ++*(_DWORD *)(v9 + 28);
    return v9;
  }
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x10031670
// Name: public: virtual int CShaderManager::CreatePixelShader(char const __near *,int,char __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CShaderManager::CreatePixelShader(
        CShaderManager *this,
        const char *pFileName,
        int nStaticPshIndex,
        char *debugLabel)
{
  unsigned __int16 m_Id; // cx
  int m_Head; // eax
  int v8; // eax
  int v9; // esi
  int v10; // ecx
  unsigned int m_hShaderFileCache; // edx
  int m_nDataOffset; // eax
  __int64 v13; // xmm0_8
  CShaderManager::ShaderLookup_t lookup; // [esp+8h] [ebp-2Ch]

  if ( pFileName == nullptr )
    return -1;
  lookup.m_ShaderStaticCombos.m_pHardwareShaders = nullptr;
  lookup.m_ShaderStaticCombos.m_pCreationData = nullptr;
  m_Id = CUtlSymbolTable::AddString(
           this: &this->m_ShaderSymbolTable,
           result: (CUtlSymbol *)&pFileName + 1,
           pString: pFileName)->m_Id;
  m_Head = this->m_PixelShaderDict.m_Head;
  lookup.m_Name.m_Id = m_Id;
  if ( m_Head != 0 )
  {
    while ( *(_WORD *)m_Head != m_Id || *(_DWORD *)(m_Head + 4) != nStaticPshIndex )
    {
      m_Head = *(_DWORD *)(m_Head + 48);
      if ( m_Head == 0 )
        goto LABEL_7;
    }
    v9 = m_Head;
    goto LABEL_10;
  }
LABEL_7:
  v8 = CUtlLinkedList<CShaderManager::ShaderLookup_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CShaderManager::ShaderLookup_t,int>>>::AllocInternal(
         this: &this->m_PixelShaderDict,
         multilist: false);
  v9 = v8;
  if ( v8 != 0 )
  {
    CUtlLinkedList<CShaderManager::ShaderLookup_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CShaderManager::ShaderLookup_t,int>>>::LinkBefore(
      this: &this->m_PixelShaderDict,
      before: 0,
      elem: v8);
    v10 = nStaticPshIndex;
    m_hShaderFileCache = lookup.m_hShaderFileCache;
    *(_WORD *)v9 = lookup.m_Name.m_Id;
    m_nDataOffset = lookup.m_nDataOffset;
    *(_QWORD *)(v9 + 8) = 0;
    v13 = *(_QWORD *)&lookup.m_ShaderStaticCombos.m_pHardwareShaders;
    *(_DWORD *)(v9 + 4) = v10;
    *(_QWORD *)(v9 + 16) = v13;
    *(_DWORD *)(v9 + 24) = 0;
    *(_DWORD *)(v9 + 28) = 0;
    *(_DWORD *)(v9 + 32) = m_hShaderFileCache;
    *(_DWORD *)(v9 + 36) = m_nDataOffset;
    *(_DWORD *)(v9 + 40) = 0;
  }
  else
  {
    v9 = 0;
  }
  if ( CShaderManager::LoadAndCreateShaders(
         this,
         lookup: (CShaderManager::ShaderLookup_t *)v9,
         bVertexShader: 0,
         debugLabel) )
  {
LABEL_10:
    ++*(_DWORD *)(v9 + 28);
    return v9;
  }
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x10031750
// Name: public: virtual void CShaderManager::PurgeUnusedVertexAndPixelShaders(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderManager::PurgeUnusedVertexAndPixelShaders(CShaderManager *this)
{
  int m_Head; // eax
  int v3; // esi
  int v4; // eax
  int v5; // esi

  m_Head = this->m_VertexShaderDict.m_Head;
  if ( m_Head != 0 )
  {
    do
    {
      v3 = *(_DWORD *)(m_Head + 48);
      if ( *(int *)(m_Head + 28) <= 0 )
        CShaderManager::DestroyVertexShader(this, shader: m_Head);
      m_Head = v3;
    }
    while ( v3 != 0 );
  }
  v4 = this->m_PixelShaderDict.m_Head;
  if ( v4 != 0 )
  {
    do
    {
      v5 = *(_DWORD *)(v4 + 48);
      if ( *(int *)(v4 + 28) <= 0 )
        CShaderManager::DestroyPixelShader(this, pixelShader: v4);
      v4 = v5;
    }
    while ( v5 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x100317A0
// Name: public: virtual void CShaderManager::AddShaderComboInformation(struct ShaderComboSemantics_t const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderManager::AddShaderComboInformation(
        CShaderManager *this,
        const ShaderComboSemantics_t *pSemantics)
{
  const ShaderComboSemantics_t *v2; // edi
  int v3; // esi

  v2 = pSemantics;
  if ( CUtlSymbolTable::Find(
         this: &s_ShaderComboInfoByName.m_SymbolTable,
         result: (CUtlSymbol *)&pSemantics + 1,
         pString: pSemantics->pShaderName)->m_Id == 0xFFFF )
  {
    CUtlSymbolTable::AddString(
      this: &s_ShaderComboInfoByName.m_SymbolTable,
      result: (CUtlSymbol *)&pSemantics,
      pString: v2->pShaderName);
    v3 = (unsigned __int16)pSemantics;
    if ( s_ShaderComboInfoByName.m_Vector.m_Size <= (unsigned __int16)pSemantics
      && s_ShaderComboInfoByName.m_Vector.m_Size < (unsigned __int16)pSemantics + 1 )
    {
      CUtlVector<ShaderComboSemantics_t const *,CUtlMemory<ShaderComboSemantics_t const *,int>>::InsertMultipleBefore(
        this: &s_ShaderComboInfoByName.m_Vector,
        elem: s_ShaderComboInfoByName.m_Vector.m_Size,
        num: (unsigned __int16)pSemantics + 1 - s_ShaderComboInfoByName.m_Vector.m_Size);
    }
    s_ShaderComboInfoByName.m_Vector.m_Memory.m_pMemory[v3] = v2;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10031810
// Name: public: void CUtlLinkedList<struct ShaderFileCache_t,int,1,int,class CUtlFixedMemory<struct UtlLinkedListElem_t<struct ShaderFileCache_t,int>>>::Purge(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<ShaderFileCache_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<ShaderFileCache_t,int>>>::Purge(
        CUtlLinkedList<ShaderFileCache_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<ShaderFileCache_t,int> > > *this)
{
  CUtlFixedMemory<UtlLinkedListElem_t<ShaderFileCache_t,int> >::BlockHeader_t *m_pBlocks; // esi
  CUtlFixedMemory<UtlLinkedListElem_t<ShaderFileCache_t,int> >::BlockHeader_t *v3; // [esp-4h] [ebp-10h]

  CUtlLinkedList<ShaderFileCache_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<ShaderFileCache_t,int>>>::RemoveAll(this);
  m_pBlocks = this->m_Memory.m_pBlocks;
  if ( this->m_Memory.m_pBlocks != nullptr )
  {
    do
    {
      v3 = m_pBlocks;
      m_pBlocks = m_pBlocks->m_pNext;
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v3);
    }
    while ( m_pBlocks != nullptr );
    this->m_Memory.m_pBlocks = nullptr;
    this->m_Memory.m_nAllocationCount = 0;
  }
  this->m_FirstFree = 0;
  this->m_NumAlloced = 0;
  this->m_pElements = nullptr;
  this->m_LastAlloc.m_pBlockHeader = nullptr;
  this->m_LastAlloc.m_nIndex = -1;
}

//------------------------------------------------------------------------------
// Address: 0x10031860
// Name: public: virtual CShaderManager::~CShaderManager(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderManager::~CShaderManager(CShaderManager *this)
{
  CUtlFixedMemory<UtlLinkedListElem_t<ShaderFileCache_t,int> >::BlockHeader_t *m_pBlocks; // esi
  CUtlFixedMemory<UtlLinkedListElem_t<IDirect3DPixelShader9 *,int> >::BlockHeader_t *v3; // esi
  CUtlFixedMemory<UtlLinkedListElem_t<IDirect3DVertexShader9 *,int> >::BlockHeader_t *v4; // esi
  CUtlFixedMemory<UtlLinkedListElem_t<CShaderManager::ShaderLookup_t,int> >::BlockHeader_t *v5; // esi
  CUtlFixedMemory<UtlLinkedListElem_t<CShaderManager::ShaderLookup_t,int> >::BlockHeader_t *v6; // esi
  CUtlFixedMemory<UtlLinkedListElem_t<ShaderFileCache_t,int> >::BlockHeader_t *v7; // [esp-4h] [ebp-10h]
  CUtlFixedMemory<UtlLinkedListElem_t<IDirect3DPixelShader9 *,int> >::BlockHeader_t *v8; // [esp-4h] [ebp-10h]
  CUtlFixedMemory<UtlLinkedListElem_t<IDirect3DVertexShader9 *,int> >::BlockHeader_t *v9; // [esp-4h] [ebp-10h]
  CUtlFixedMemory<UtlLinkedListElem_t<CShaderManager::ShaderLookup_t,int> >::BlockHeader_t *v10; // [esp-4h] [ebp-10h]
  CUtlFixedMemory<UtlLinkedListElem_t<CShaderManager::ShaderLookup_t,int> >::BlockHeader_t *v11; // [esp-4h] [ebp-10h]

  this->__vftable = (CShaderManager_vtbl *)&CShaderManager::`vftable';
  CUtlLinkedList<ShaderFileCache_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<ShaderFileCache_t,int>>>::RemoveAll(this: &this->m_ShaderFileCache);
  m_pBlocks = this->m_ShaderFileCache.m_Memory.m_pBlocks;
  if ( m_pBlocks != nullptr )
  {
    do
    {
      v7 = m_pBlocks;
      m_pBlocks = m_pBlocks->m_pNext;
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v7);
    }
    while ( m_pBlocks != nullptr );
    this->m_ShaderFileCache.m_Memory.m_pBlocks = nullptr;
    this->m_ShaderFileCache.m_Memory.m_nAllocationCount = 0;
  }
  CUtlLinkedList<IDirect3DPixelShader9 *,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<IDirect3DPixelShader9 *,int>>>::RemoveAll(this: &this->m_RawPixelShaderDict);
  v3 = this->m_RawPixelShaderDict.m_Memory.m_pBlocks;
  if ( v3 != nullptr )
  {
    do
    {
      v8 = v3;
      v3 = v3->m_pNext;
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v8);
    }
    while ( v3 != nullptr );
    this->m_RawPixelShaderDict.m_Memory.m_pBlocks = nullptr;
    this->m_RawPixelShaderDict.m_Memory.m_nAllocationCount = 0;
  }
  CUtlLinkedList<IDirect3DPixelShader9 *,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<IDirect3DPixelShader9 *,int>>>::RemoveAll(this: (CUtlLinkedList<IDirect3DPixelShader9 *,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<IDirect3DPixelShader9 *,int> > > *)&this->m_RawVertexShaderDict);
  v4 = this->m_RawVertexShaderDict.m_Memory.m_pBlocks;
  if ( v4 != nullptr )
  {
    do
    {
      v9 = v4;
      v4 = v4->m_pNext;
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v9);
    }
    while ( v4 != nullptr );
    this->m_RawVertexShaderDict.m_Memory.m_pBlocks = nullptr;
    this->m_RawVertexShaderDict.m_Memory.m_nAllocationCount = 0;
  }
  CUtlSymbolTable::~CUtlSymbolTable(this: &this->m_ShaderSymbolTable);
  CUtlLinkedList<CShaderManager::ShaderLookup_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CShaderManager::ShaderLookup_t,int>>>::RemoveAll(this: &this->m_PixelShaderDict);
  v5 = this->m_PixelShaderDict.m_Memory.m_pBlocks;
  if ( v5 != nullptr )
  {
    do
    {
      v10 = v5;
      v5 = v5->m_pNext;
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v10);
    }
    while ( v5 != nullptr );
    this->m_PixelShaderDict.m_Memory.m_pBlocks = nullptr;
    this->m_PixelShaderDict.m_Memory.m_nAllocationCount = 0;
  }
  CUtlLinkedList<CShaderManager::ShaderLookup_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CShaderManager::ShaderLookup_t,int>>>::RemoveAll(this: &this->m_VertexShaderDict);
  v6 = this->m_VertexShaderDict.m_Memory.m_pBlocks;
  if ( v6 != nullptr )
  {
    do
    {
      v11 = v6;
      v6 = v6->m_pNext;
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v11);
    }
    while ( v6 != nullptr );
    this->m_VertexShaderDict.m_Memory.m_pBlocks = nullptr;
    this->m_VertexShaderDict.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10031990
// Name: public: void CShaderManager::DestroyAllShaders(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderManager::DestroyAllShaders(CShaderManager *this)
{
  int m_Head; // eax
  int v3; // edi
  int v4; // eax
  int v5; // edi

  m_Head = this->m_VertexShaderDict.m_Head;
  if ( m_Head != 0 )
  {
    do
    {
      v3 = *(_DWORD *)(m_Head + 48);
      CShaderManager::DestroyVertexShader(this, shader: m_Head);
      m_Head = v3;
    }
    while ( v3 != 0 );
  }
  v4 = this->m_PixelShaderDict.m_Head;
  if ( v4 != 0 )
  {
    do
    {
      v5 = *(_DWORD *)(v4 + 48);
      CShaderManager::DestroyPixelShader(this, pixelShader: v4);
      v4 = v5;
    }
    while ( v5 != 0 );
  }
  CUtlLinkedList<ShaderFileCache_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<ShaderFileCache_t,int>>>::Purge(this: &this->m_ShaderFileCache);
}

//------------------------------------------------------------------------------
// Address: 0x100319E0
// Name: public: CShaderManager::CShaderManager(void)
// Source: json
//------------------------------------------------------------------------------
CShaderManager *__thiscall CShaderManager::CShaderManager(CShaderManager *this)
{
  this->__vftable = (CShaderManager_vtbl *)&CShaderManager::`vftable';
  this->m_VertexShaderDict.m_Memory.m_pBlocks = nullptr;
  this->m_VertexShaderDict.m_Memory.m_nAllocationCount = 0;
  this->m_VertexShaderDict.m_Memory.m_nGrowSize = 32;
  this->m_VertexShaderDict.m_LastAlloc.m_pBlockHeader = nullptr;
  this->m_VertexShaderDict.m_LastAlloc.m_nIndex = -1;
  this->m_VertexShaderDict.m_Head = 0;
  this->m_VertexShaderDict.m_Tail = 0;
  this->m_VertexShaderDict.m_FirstFree = 0;
  this->m_VertexShaderDict.m_ElementCount = 0;
  this->m_VertexShaderDict.m_NumAlloced = 0;
  this->m_VertexShaderDict.m_pElements = nullptr;
  this->m_PixelShaderDict.m_Memory.m_pBlocks = nullptr;
  this->m_PixelShaderDict.m_Memory.m_nAllocationCount = 0;
  this->m_PixelShaderDict.m_Memory.m_nGrowSize = 32;
  this->m_PixelShaderDict.m_LastAlloc.m_pBlockHeader = nullptr;
  this->m_PixelShaderDict.m_LastAlloc.m_nIndex = -1;
  this->m_PixelShaderDict.m_Head = 0;
  this->m_PixelShaderDict.m_Tail = 0;
  this->m_PixelShaderDict.m_FirstFree = 0;
  this->m_PixelShaderDict.m_ElementCount = 0;
  this->m_PixelShaderDict.m_NumAlloced = 0;
  this->m_PixelShaderDict.m_pElements = nullptr;
  CUtlSymbolTable::CUtlSymbolTable(this: &this->m_ShaderSymbolTable, growSize: 0, initSize: 32, caseInsensitive: true);
  this->m_RawVertexShaderDict.m_Memory.m_pBlocks = nullptr;
  this->m_RawVertexShaderDict.m_Memory.m_nAllocationCount = 0;
  this->m_RawVertexShaderDict.m_Memory.m_nGrowSize = 0;
  this->m_RawVertexShaderDict.m_LastAlloc.m_pBlockHeader = nullptr;
  this->m_RawVertexShaderDict.m_LastAlloc.m_nIndex = -1;
  this->m_RawVertexShaderDict.m_Head = 0;
  this->m_RawVertexShaderDict.m_Tail = 0;
  this->m_RawVertexShaderDict.m_FirstFree = 0;
  this->m_RawVertexShaderDict.m_ElementCount = 0;
  this->m_RawVertexShaderDict.m_NumAlloced = 0;
  this->m_RawVertexShaderDict.m_pElements = nullptr;
  this->m_RawPixelShaderDict.m_Memory.m_pBlocks = nullptr;
  this->m_RawPixelShaderDict.m_Memory.m_nAllocationCount = 0;
  this->m_RawPixelShaderDict.m_Memory.m_nGrowSize = 0;
  this->m_RawPixelShaderDict.m_LastAlloc.m_pBlockHeader = nullptr;
  this->m_RawPixelShaderDict.m_LastAlloc.m_nIndex = -1;
  this->m_RawPixelShaderDict.m_Head = 0;
  this->m_RawPixelShaderDict.m_Tail = 0;
  this->m_RawPixelShaderDict.m_FirstFree = 0;
  this->m_RawPixelShaderDict.m_ElementCount = 0;
  this->m_RawPixelShaderDict.m_NumAlloced = 0;
  this->m_RawPixelShaderDict.m_pElements = nullptr;
  this->m_ShaderFileCache.m_Memory.m_pBlocks = nullptr;
  this->m_ShaderFileCache.m_Memory.m_nAllocationCount = 0;
  this->m_ShaderFileCache.m_Memory.m_nGrowSize = 32;
  this->m_ShaderFileCache.m_LastAlloc.m_pBlockHeader = nullptr;
  this->m_ShaderFileCache.m_LastAlloc.m_nIndex = -1;
  this->m_ShaderFileCache.m_Head = 0;
  this->m_ShaderFileCache.m_Tail = 0;
  this->m_ShaderFileCache.m_FirstFree = 0;
  this->m_ShaderFileCache.m_ElementCount = 0;
  this->m_ShaderFileCache.m_NumAlloced = 0;
  this->m_ShaderFileCache.m_pElements = nullptr;
  this->m_bCreateShadersOnDemand = false;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10031B50
// Name: public: virtual void CShaderManager::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderManager::Shutdown(CShaderManager *this)
{
  CShaderManager::DestroyAllShaders(this);
  if ( s_pIllegalMaterialPS != nullptr )
  {
    (*(void (__stdcall **)(void *))(*(_DWORD *)s_pIllegalMaterialPS + 8))(a1: s_pIllegalMaterialPS);
    s_pIllegalMaterialPS = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10056FFA
// Name: public: virtual unsigned long D3DXMath::CMatrixStack::Release(void)
// Source: json
//------------------------------------------------------------------------------
int __stdcall D3DXMath::CMatrixStack::Release(D3DXMath::CMatrixStack *this)
{
  bool v1; // zf
  int v2; // esi

  v1 = (*((_DWORD *)this + 4))-- == 1;
  v2 = *((_DWORD *)this + 4);
  if ( v1 )
    D3DXMath::CMatrixStack::`scalar deleting destructor'(this, a2: 1);
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x10074A81
// Name: public: virtual unsigned long D3DXShader::CConstantTable::Release(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __stdcall D3DXShader::CConstantTable::Release(D3DXShader::CConstantTable *this)
{
  int v1; // eax
  int v2; // esi

  v1 = *((_DWORD *)this + 1);
  v2 = v1 - 1;
  *((_DWORD *)this + 1) = v1 - 1;
  if ( v1 == 1 )
    D3DXShader::CConstantTable::`scalar deleting destructor'(this, a2: 1);
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x1007546F
// Name: public: virtual unsigned long D3DXCore::CBuffer::Release(void)
// Source: json
//------------------------------------------------------------------------------
int __stdcall D3DXCore::CBuffer::Release(D3DXCore::CBuffer *this)
{
  int v1; // eax
  int v2; // esi

  v1 = *((_DWORD *)this + 1);
  v2 = v1 - 1;
  *((_DWORD *)this + 1) = v1 - 1;
  if ( v1 == 1 )
    (*(void (__thiscall **)(D3DXCore::CBuffer *, int))(*(_DWORD *)this + 20))(a1: this, a2: 1);
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x100D3EA0
// Name: public: void CUtlMemory<class CUtlString,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<CUtlString,int>::Grow(CUtlMemory<CUtlString,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  CUtlString *m_pMemory; // edx
  unsigned int v7; // [esp-4h] [ebp-Ch]

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
    v7 = 16 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (CUtlString *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (CUtlString *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100F56A0
// Name: _CShaderManager::SetVertexShaderState_Internal_::_4_::_dynamic_atexit_destructor_for___counter__
// Source: json
//------------------------------------------------------------------------------
void __cdecl CShaderManager::SetVertexShaderState_Internal_::_4_::_dynamic_atexit_destructor_for___counter__()
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x100F56B0
// Name: _CShaderManager::SetPixelShaderState_Internal_::_4_::_dynamic_atexit_destructor_for___counter__
// Source: json
//------------------------------------------------------------------------------
void __cdecl CShaderManager::SetPixelShaderState_Internal_::_4_::_dynamic_atexit_destructor_for___counter__()
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x10057019
// Name: D3DXCreateMatrixStack(x,x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __stdcall D3DXCreateMatrixStack(int a1, D3DXMath::CMatrixStack **a2)
{
  D3DXMath::CMatrixStack *v3; // eax
  D3DXMath::CMatrixStack *v4; // esi
  int v5; // edi

  if ( a2 == nullptr )
    return -2005530516;
  v3 = (D3DXMath::CMatrixStack *)operator new(nSize: 0x14u);
  if ( v3 != nullptr )
    v4 = D3DXMath::CMatrixStack::CMatrixStack(this: v3);
  else
    v4 = nullptr;
  if ( v4 == nullptr )
    return -2147024882;
  v5 = D3DXMath::CMatrixStack::Initialize(this: v4, a2: 16);
  if ( v5 >= 0 )
  {
    *a2 = v4;
    return 0;
  }
  else
  {
    (*(void (__stdcall **)(D3DXMath::CMatrixStack *))(*(_DWORD *)v4 + 8))(a1: v4);
    return v5;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10057077
// Name: D3DXCompileShader(x,x,x,x,x,x,x,x,x,x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __stdcall D3DXCompileShader(
        void *a1,
        unsigned int a2,
        struct _D3DXMACRO *a3,
        struct ID3DXInclude *a4,
        char *a5,
        char *a6,
        int a7,
        struct ID3DXBuffer **a8,
        struct ID3DXBuffer **a9,
        struct ID3DXConstantTable **a10)
{
  _BYTE v12[24]; // [esp+Ch] [ebp-370h] BYREF
  _BYTE v13[664]; // [esp+24h] [ebp-358h] BYREF
  _BYTE v14[184]; // [esp+2BCh] [ebp-C0h] BYREF
  struct ID3DXConstantTable *v15; // [esp+374h] [ebp-8h] BYREF
  struct ID3DXBuffer *v16; // [esp+378h] [ebp-4h] BYREF
  int v17; // [esp+3A0h] [ebp+24h]

  v16 = nullptr;
  v15 = nullptr;
  D3DXShader::CPreProcessor::CPreProcessor(this: (D3DXShader::CPreProcessor *)v12);
  if ( a8 != nullptr )
    *a8 = nullptr;
  if ( a10 != nullptr )
    *a10 = nullptr;
  if ( (a7 & 0xFFFFF9C0) != 0 )
  {
    v17 = -2005530516;
  }
  else
  {
    v17 = D3DXShader::CPreProcessor::InitializeFromMemory(
            this: (D3DXShader::CPreProcessor *)v12,
            a2: a1,
            a3: a2,
            a4: a3,
            a5: a4);
    if ( v17 >= 0 )
    {
      D3DXShader::CCompiler::CCompiler(this: (D3DXShader::CCompiler *)v14);
      v17 = D3DXShader::CCompiler::Compile(
              this: (D3DXShader::CCompiler *)v14,
              a2: (struct D3DXShader::CPreProcessor *)v12,
              a3: nullptr,
              a4: a5,
              a5: 0,
              a6,
              a7: a7 | 0x100,
              a8: &v16,
              a9: &v15);
      if ( v17 >= 0 )
      {
        D3DXShader::CCompiler::~CCompiler(this: (D3DXShader::CCompiler *)v14);
        if ( D3DXShader::CTErrors::GetErrorCount(this: (D3DXShader::CTErrors *)v13) != 0 )
        {
          v17 = -2005529767;
        }
        else
        {
          if ( a8 != nullptr )
          {
            *a8 = v16;
            v16 = nullptr;
          }
          if ( a10 != nullptr )
          {
            *a10 = v15;
            v15 = nullptr;
          }
        }
      }
      else
      {
        D3DXShader::CCompiler::~CCompiler(this: (D3DXShader::CCompiler *)v14);
      }
    }
  }
  if ( a9 != nullptr )
    D3DXShader::CTErrors::GetErrorBuffer(this: (D3DXShader::CTErrors *)v13, a2: a9);
  if ( v15 != nullptr )
  {
    ((void (__cdecl *)(struct ID3DXConstantTable *))v15->Release)(a1: v15);
    v15 = nullptr;
  }
  if ( v16 != nullptr )
  {
    ((void (__cdecl *)(struct ID3DXBuffer *))v16->Release)(a1: v16);
    v16 = nullptr;
  }
  D3DXShader::CPreProcessor::~CPreProcessor(this: (D3DXShader::CPreProcessor *)v12);
  return v17;
}

//------------------------------------------------------------------------------
// Address: 0x100571A9
// Name: D3DXFindShaderComment(x,x,x,x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __stdcall D3DXFindShaderComment(_DWORD *a1, int a2, _DWORD *a3, _DWORD *a4)
{
  _DWORD *v4; // ebx
  unsigned int v6; // eax
  unsigned int *i; // ecx
  unsigned int v8; // eax
  int v9; // esi
  unsigned int v10; // eax

  if ( a3 != nullptr )
    *a3 = 0;
  v4 = a4;
  if ( a4 != nullptr )
    *a4 = 0;
  if ( a1 == nullptr )
    return -2005530516;
  v6 = *a1 & 0xFFFF0000;
  if ( v6 != 1180172288 && v6 != 1415053312 && v6 != 2147352576 && v6 != 2147418112 && v6 != -131072 && v6 != -65536 )
    return -2005529767;
  for ( i = a1 + 1; ; ++i )
  {
    v8 = *i;
    if ( (*i & 0x80000000) == 0 )
    {
      v9 = (unsigned __int16)*i;
      if ( v9 == 0xFFFF )
        return 1;
      if ( v9 == 65534 )
        break;
      if ( (unsigned __int16)*a1 >= 0x200u )
      {
        v10 = HIBYTE(v8) & 0xF;
LABEL_28:
        i += v10;
        goto LABEL_31;
      }
      if ( v9 == 81 )
        i += 5;
    }
LABEL_31:
    v4 = a4;
  }
  v10 = HIWORD(v8) & 0x7FFF;
  if ( v10 <= 1 || a2 != i[1] )
    goto LABEL_28;
  if ( a3 != nullptr )
    *a3 = i + 2;
  if ( v4 != nullptr )
    *v4 = 4 * v10 - 4;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10057290
// Name: D3DXGetShaderVersion(x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __stdcall D3DXGetShaderVersion(int a1)
{
  int result; // eax

  result = a1;
  if ( a1 != 0 )
    return *(_DWORD *)a1;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100572C3
// Name: D3DXGetTargetDescByName(x,x,x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __stdcall D3DXGetTargetDescByName(const char *a1, int a2, _DWORD *a3)
{
  unsigned int v3; // edx
  int v5; // eax
  unsigned int v6; // eax
  int v7; // ecx
  int v8; // eax
  unsigned int v9; // [esp+0h] [ebp-4h]

  v3 = 0;
  if ( a1 == nullptr )
    return -2005530516;
  v5 = 44;
  v9 = 44;
  while ( 1 )
  {
    v6 = (v3 + v5) >> 1;
    v7 = strcmp((&off_1013FBF8)[3 * v6], a1);
    if ( v7 == 0 )
      break;
    if ( v7 >= 0 )
      v9 = v6;
    else
      v3 = v6 + 1;
    v5 = v9;
    if ( v3 >= v9 )
      return -2147467259;
  }
  v8 = 3 * v6;
  if ( (a2 & dword_1013FC00[v8]) != a2 )
    return -2147467259;
  if ( a3 != nullptr )
  {
    *a3 = (&off_1013FBF8)[v8];
    a3[1] = (&off_1013FBF8)[v8 + 1];
    a3[2] = (&off_1013FBF8)[v8 + 2];
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10057361
// Name: D3DXGetTargetDescByVersion(x,x,x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __stdcall D3DXGetTargetDescByVersion(int a1, int a2, _DWORD *a3)
{
  int v3; // ecx
  const char *v4; // eax
  int v5; // edx
  char **v7; // esi

  v3 = 44;
  v4 = "vs_3_0";
  while ( 1 )
  {
    v5 = *((_DWORD *)v4 - 4);
    v4 -= 12;
    --v3;
    if ( v5 == a1 && (a2 & *(_DWORD *)v4) == a2 )
      break;
    if ( v4 <= (const char *)dword_1013FC00 )
      return -2147467259;
  }
  if ( a3 != nullptr )
  {
    v7 = &(&off_1013FBF8)[3 * v3];
    *a3 = *v7++;
    a3[1] = *v7;
    a3[2] = v7[1];
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x100573B0
// Name: D3DXGetShaderConstantTable(x,x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __stdcall D3DXGetShaderConstantTable(unsigned int *a1, D3DXShader::CConstantTable **a2)
{
  D3DXShader::CConstantTable *v2; // esi
  unsigned int v4; // eax
  D3DXShader::CConstantTable *v5; // eax
  int v6; // edi

  v2 = nullptr;
  if ( a2 != nullptr )
    *a2 = nullptr;
  if ( a1 == nullptr || a2 == nullptr )
    return -2005530516;
  v4 = *a1 & 0xFFFF0000;
  if ( v4 != -131072 && v4 != -65536 )
    goto LABEL_14;
  v5 = (D3DXShader::CConstantTable *)operator new(nSize: 0x20u);
  if ( v5 != nullptr )
    v2 = (D3DXShader::CConstantTable *)D3DXShader::CConstantTable::CConstantTable(this: v5);
  if ( v2 == nullptr )
    return -2147024882;
  v6 = D3DXShader::CConstantTable::Initialize(this: v2, a2: a1, a3: nullptr);
  if ( v6 < 0 )
  {
    D3DXShader::CConstantTable::`scalar deleting destructor'(this: v2, a2: 1);
    return v6;
  }
  else
  {
LABEL_14:
    *a2 = v2;
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10057431
// Name: void c_D3DXPSGPUpdateSkinnedMesh(struct D3DXMATRIX const __near *,struct D3DXMATRIX const __near *,unsigned char __near *,unsigned char __near *,unsigned long,unsigned long,unsigned char __near * __near *,unsigned char __near * __near *,unsigned char __near *,unsigned long,float __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __stdcall c_D3DXPSGPUpdateSkinnedMesh(
        const struct D3DXMATRIX *a1,
        const struct D3DXMATRIX *a2,
        unsigned __int8 *a3,
        unsigned __int8 *a4,
        unsigned __int8 **a5,
        unsigned int a6,
        unsigned __int8 **a7,
        float **a8,
        unsigned __int8 *a9,
        unsigned int a10,
        float *a11)
{
  unsigned int v11; // esi
  unsigned __int8 *v12; // ecx
  float *v13; // edx
  float *v14; // ebx
  unsigned __int8 *v15; // edi
  unsigned __int8 *v16; // esi
  float *v17; // esi
  unsigned int v18; // eax
  double v19; // st7
  unsigned int v20; // edi
  float *v21; // eax
  bool v22; // zf
  unsigned int v23; // ecx
  float *v24; // esi
  unsigned int v25; // ebx
  double v26; // st7
  unsigned int v27; // esi
  float *v28; // edi
  unsigned __int8 v29; // al
  const struct D3DXMATRIX *v30; // eax
  unsigned __int8 *v31; // edi
  unsigned __int8 *v32; // esi
  unsigned __int8 **v33; // eax
  _DWORD *v34; // ebx
  unsigned __int8 *v35; // edi
  _BYTE v36[8]; // [esp+Ch] [ebp-338h] BYREF
  char v37; // [esp+14h] [ebp-330h] BYREF
  unsigned int v38; // [esp+318h] [ebp-2Ch]
  BOOL v39; // [esp+31Ch] [ebp-28h]
  float v40; // [esp+320h] [ebp-24h] BYREF
  float v41; // [esp+324h] [ebp-20h]
  float v42; // [esp+328h] [ebp-1Ch]
  unsigned __int8 *v43; // [esp+32Ch] [ebp-18h]
  float v44; // [esp+330h] [ebp-14h] BYREF
  float v45; // [esp+334h] [ebp-10h]
  float v46; // [esp+338h] [ebp-Ch]
  float *v47; // [esp+33Ch] [ebp-8h]
  int v48; // [esp+340h] [ebp-4h]
  unsigned __int8 **v49; // [esp+364h] [ebp+20h]
  float v50; // [esp+374h] [ebp+30h]

  v11 = 12 * a10;
  v38 = 12 * a10;
  v39 = 12 * a10 != a6;
  if ( a2 == nullptr )
    a2 = a1;
  if ( a10 == 2 )
  {
    if ( *a9 != 0 || a9[1] != 3 )
    {
      if ( a9[1] != 0 || *a9 != 3 )
        goto LABEL_22;
      v12 = a7[1];
      v48 = *(int *)a7;
      v14 = a8[1];
      v47 = *a8;
      v13 = v47;
    }
    else
    {
      v12 = *a7;
      v48 = *((int *)a7 + 1);
      v13 = a8[1];
      v14 = *a8;
      v47 = v13;
    }
    v43 = v12;
    if ( v12 != nullptr )
    {
      if ( a5 != nullptr )
      {
        v49 = a5;
        do
        {
          if ( v39 )
          {
            v15 = a4;
            a4 += a6;
            qmemcpy(v15, a3, 4 * (a6 >> 2));
            v16 = &a3[4 * (a6 >> 2)];
            a3 += a6;
            qmemcpy(&v15[4 * (a6 >> 2)], v16, a6 & 3);
          }
          v17 = a11;
          *v14 = 0.0;
          v14[1] = 0.0;
          v14[2] = 0.0;
          *v13 = 0.0;
          v13[1] = 0.0;
          v13[2] = 0.0;
          if ( *a11 >= 0.0 )
          {
            do
            {
              v18 = (unsigned int)(__int64)*v17 >> 1;
              v19 = (double)(int)(2 * v18);
              if ( (v18 & 0x40000000) != 0 )
                v19 = v19 + 4294967300.0;
              v20 = v18 << 6;
              v50 = *v17 - v19;
              D3DXVec3TransformCoord(a1: &v44, a2: v43, a3: &a1[v18]);
              D3DXVec3TransformNormal(a1: &v40, a2: v48, a3: (char *)a2 + v20);
              v21 = v47;
              ++v17;
              v44 = v44 * v50;
              v45 = v45 * v50;
              v46 = v46 * v50;
              v40 = v40 * v50;
              v41 = v41 * v50;
              v42 = v42 * v50;
              *v14 = v44 + *v14;
              v14[1] = v45 + v14[1];
              v14[2] = v46 + v14[2];
              *v21 = v40 + *v21;
              v21[1] = v41 + v21[1];
              v21[2] = v42 + v21[2];
            }
            while ( *v17 >= 0.0 );
            v13 = v47;
          }
          v43 += a6;
          v48 += a6;
          v13 = (float *)((char *)v13 + a6);
          v14 = (float *)((char *)v14 + a6);
          v22 = v49 == (unsigned __int8 **)1;
          v49 = (unsigned __int8 **)((char *)v49 - 1);
          v47 = v13;
          a11 = v17 + 1;
        }
        while ( !v22 );
      }
      return;
    }
  }
LABEL_22:
  v47 = nullptr;
  if ( a5 != nullptr )
  {
    while ( 1 )
    {
      v23 = v11;
      v24 = a11;
      memset(v36, 0, v23);
      while ( *v24 >= 0.0 )
      {
        v25 = (unsigned int)(__int64)*v24 >> 1;
        v48 = 2 * v25;
        v26 = *v24 - (double)(2 * v25);
        v27 = 0;
        *(float *)&v48 = v26;
        if ( a10 != 0 )
        {
          v28 = (float *)&v37;
          do
          {
            v29 = a9[v27];
            if ( v29 != 0 )
            {
              if ( v29 == 3 )
              {
                v30 = &a2[v25];
              }
              else
              {
                if ( v29 <= 5u || v29 > 7u )
                  return;
                v30 = &a1[v25];
              }
              D3DXVec3TransformNormal(a1: &v44, a2: a7[v27], a3: v30);
            }
            else
            {
              D3DXVec3TransformCoord(a1: &v44, a2: a7[v27], a3: &a1[v25]);
            }
            ++v27;
            v44 = v44 * *(float *)&v48;
            v45 = v45 * *(float *)&v48;
            v46 = v46 * *(float *)&v48;
            *(v28 - 2) = v44 + *(v28 - 2);
            *(v28 - 1) = v45 + *(v28 - 1);
            *v28 = v46 + *v28;
            v28 += 3;
          }
          while ( v27 < a10 );
        }
        v24 = ++a11;
      }
      if ( v39 )
      {
        v31 = a4;
        a4 += a6;
        qmemcpy(v31, a3, 4 * (a6 >> 2));
        v32 = &a3[4 * (a6 >> 2)];
        a3 += a6;
        qmemcpy(&v31[4 * (a6 >> 2)], v32, a6 & 3);
      }
      if ( a10 != 0 )
      {
        v33 = (unsigned __int8 **)a8;
        v34 = v36;
        v48 = a10;
        do
        {
          v35 = *v33;
          *(_DWORD *)v35 = *v34;
          v35 += 4;
          *(_DWORD *)v35 = v34[1];
          *((_DWORD *)v35 + 1) = v34[2];
          *v33 += a6;
          *(unsigned __int8 **)((char *)v33 + (char *)a7 - (char *)a8) += a6;
          v34 += 3;
          ++v33;
          --v48;
        }
        while ( *(float *)&v48 != 0.0 );
      }
      ++a11;
      v47 = (float *)((char *)v47 + 1);
      if ( v47 >= (float *)a5 )
        break;
      v11 = v38;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100577AB
// Name: void CalculateEdgeControlPoint(struct D3DXVECTOR3 __near *,struct D3DXVECTOR3 __near *,struct D3DXVECTOR3 __near *,float,struct D3DXVECTOR3 __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __stdcall CalculateEdgeControlPoint(
        struct D3DXVECTOR3 *a1,
        struct D3DXVECTOR3 *a2,
        struct D3DXVECTOR3 *a3,
        float a4,
        struct D3DXVECTOR3 *a5)
{
  double v5; // st7
  double v6; // st6
  double v7; // st7
  double v8; // st6
  float v9; // [esp+8h] [ebp-Ch]
  float v10; // [esp+Ch] [ebp-8h]

  *a5 = *a1;
  a5->x = a5->x - a2->x;
  a5->y = a5->y - a2->y;
  v5 = a5->z - a2->z;
  a5->z = v5;
  v6 = v5 * a3->z + a3->x * a5->x + a5->y * a3->y;
  v9 = v6 * a3->x;
  v10 = v6 * a3->y;
  a5->z = v5 - v6 * a3->z;
  v7 = (a5->x - v9) * a4;
  a5->x = v7;
  v8 = (a5->y - v10) * a4;
  a5->y = v8;
  a5->z = a4 * a5->z;
  a5->x = v7 + a2->x;
  a5->y = v8 + a2->y;
  a5->z = a2->z + a5->z;
}

//------------------------------------------------------------------------------
// Address: 0x1005784A
// Name: void c_D3DXPSGPTessellateNPatch(struct D3DXVECTOR3 __near *,struct D3DXVECTOR2 __near *,unsigned long,float __near *,float __near *,float __near *,float __near *,unsigned long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __stdcall c_D3DXPSGPTessellateNPatch(
        struct D3DXVECTOR3 *a1,
        struct D3DXVECTOR2 *a2,
        unsigned int a3,
        float *a4,
        float *a5,
        float *a6,
        float *a7,
        unsigned int a8)
{
  char *v9; // eax
  char *v10; // eax
  double v11; // st6
  unsigned int v12; // edx
  double v13; // st5
  float *p_y; // eax
  double v15; // st4
  double v16; // st3
  double v17; // st2
  double v18; // st1
  float *v19; // ecx
  double v20; // st0
  unsigned int v21; // edx
  float *v22; // eax
  int v23; // edx
  float *v24; // edi
  float v25[68]; // [esp+14h] [ebp-1C8h] BYREF
  float v26[10]; // [esp+124h] [ebp-B8h] BYREF
  float v27; // [esp+14Ch] [ebp-90h]
  float v28; // [esp+154h] [ebp-88h]
  float v29; // [esp+15Ch] [ebp-80h]
  float v30; // [esp+160h] [ebp-7Ch]
  struct D3DXVECTOR3 v31; // [esp+164h] [ebp-78h] BYREF
  struct D3DXVECTOR3 v32; // [esp+170h] [ebp-6Ch] BYREF
  struct D3DXVECTOR3 v33; // [esp+17Ch] [ebp-60h] BYREF
  struct D3DXVECTOR3 v34; // [esp+188h] [ebp-54h] BYREF
  float v35; // [esp+194h] [ebp-48h]
  float v36; // [esp+198h] [ebp-44h]
  float i; // [esp+19Ch] [ebp-40h]
  struct D3DXVECTOR3 v38; // [esp+1A0h] [ebp-3Ch] BYREF
  struct D3DXVECTOR3 v39; // [esp+1ACh] [ebp-30h] BYREF
  struct D3DXVECTOR3 v40; // [esp+1B8h] [ebp-24h] BYREF
  struct D3DXVECTOR3 v41; // [esp+1C4h] [ebp-18h] BYREF
  struct D3DXVECTOR3 v42; // [esp+1D0h] [ebp-Ch] BYREF
  struct D3DXVECTOR3 *v43; // [esp+1E4h] [ebp+8h]
  float v44; // [esp+1F8h] [ebp+1Ch]

  v31.x = *a5;
  v31.y = a5[1];
  v31.z = a5[2];
  v39.x = *a6;
  v39.y = a6[1];
  v39.z = a6[2];
  v42.x = *a7;
  v42.y = a7[1];
  v42.z = a7[2];
  CalculateEdgeControlPoint(a1: &v39, a2: &v31, a3: a1, a4: 0.33333334, a5: &v32);
  CalculateEdgeControlPoint(a1: &v42, a2: &v31, a3: a1, a4: 0.33333334, a5: &v33);
  CalculateEdgeControlPoint(a1: &v31, a2: &v39, a3: a1 + 1, a4: 0.33333334, a5: &v34);
  CalculateEdgeControlPoint(a1: &v31, a2: &v42, a3: a1 + 2, a4: 0.33333334, a5: &v38);
  CalculateEdgeControlPoint(a1: &v42, a2: &v39, a3: a1 + 1, a4: 0.33333334, a5: &v40);
  CalculateEdgeControlPoint(a1: &v39, a2: &v42, a3: a1 + 2, a4: 0.33333334, a5: &v41);
  i = v33.z + v32.z;
  v35 = v34.x + v33.x + v32.x;
  v35 = v38.x + v35;
  v36 = v38.y + v34.y + v33.y + v32.y;
  v36 = v40.y + v36;
  i = v40.z + v38.z + v34.z + i;
  v35 = v41.x + v40.x + v35;
  v36 = v41.y + v36;
  v35 = v35 * 0.25;
  v36 = v36 * 0.25;
  v30 = v39.z + v31.z;
  v27 = v42.x + v39.x + v31.x;
  v9 = nullptr;
  v43 = nullptr;
  v28 = v42.z + v30;
  v29 = (v42.y + v39.y + v31.y) * 0.166666;
  v30 = v28 * 0.166666;
  v35 = v35 - v27 * 0.166666;
  v36 = v36 - v29;
  for ( i = (v41.z + i) * 0.25 - v30; (unsigned int)v43 < a3; v43 = (struct D3DXVECTOR3 *)((char *)v43 + 1) )
  {
    v10 = (char *)(8 * (_DWORD)v9);
    v11 = *(float *)((char *)&a2->x + (_DWORD)v10);
    v12 = 0;
    v13 = *(float *)((char *)&a2->y + (_DWORD)v10);
    p_y = &v31.y;
    v15 = 1.0 - v11 - v13;
    v26[0] = v13 * v13 * v13;
    v44 = v15 * v13;
    v26[1] = v15 * v13 * v13 * 3.0;
    v26[2] = v13 * v13 * v11 * 3.0;
    v26[3] = v15 * v15 * v13 * 3.0;
    v26[4] = v44 * v11 * 6.0;
    v26[5] = v13 * v11 * v11 * 3.0;
    v26[6] = v15 * v15 * v15;
    v26[7] = v15 * v15 * v11 * 3.0;
    v26[8] = v15 * v11 * v11 * 3.0;
    v26[9] = v11 * v11 * v11;
    v16 = 0.0;
    v17 = 0.0;
    v18 = 0.0;
    do
    {
      v19 = &v26[v12++];
      v16 = v16 + *(p_y - 1) * *v19;
      v20 = *v19 * *p_y;
      p_y += 3;
      v17 = v17 + v20;
      v18 = v18 + *(p_y - 2) * *v19;
    }
    while ( v12 < 0xA );
    v21 = a8;
    v25[2] = v18;
    v25[1] = v17;
    v25[0] = v16;
    if ( a8 > 3 )
    {
      v22 = a6 + 3;
      v23 = a8 - 3;
      do
      {
        *(float *)((char *)v22 + (char *)v25 - (char *)a6) = v11 * *(float *)((char *)v22 + (char *)a7 - (char *)a6)
                                                           + v13 * *(float *)((char *)v22 + (char *)a5 - (char *)a6)
                                                           + v15 * *v22;
        ++v22;
        --v23;
      }
      while ( v23 != 0 );
      v21 = a8;
    }
    v24 = a4;
    a4 += v21;
    qmemcpy(v24, v25, 4 * v21);
    v9 = (char *)&v43->x + 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10057BA3
// Name: sub_10057BA3
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __stdcall sub_10057BA3(unsigned __int8 *a1, LPCSTR lpValueName, unsigned __int8 *Type, unsigned int cbData)
{
  LSTATUS v4; // esi
  BOOL result; // eax
  HKEY__ *phkResult; // [esp+0h] [ebp-4h] BYREF

  phkResult = nullptr;
  result = false;
  if ( RegOpenKeyA(hKey: HKEY_LOCAL_MACHINE, lpSubKey: "Software\\Microsoft\\Direct3D", &phkResult) == 0 )
  {
    v4 = RegQueryValueExA(
           hKey: phkResult,
           lpValueName,
           lpReserved: nullptr,
           lpType: (LPDWORD)&Type,
           lpData: Type,
           lpcbData: &cbData);
    RegCloseKey(hKey: phkResult);
    if ( v4 == 0 && Type == a1 )
      return true;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10057C02
// Name: sub_10057C02
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int sub_10057C02()
{
  _DWORD v11[7]; // [esp-Ch] [ebp-4Ch] BYREF
  int v12; // [esp+10h] [ebp-30h]
  int v13; // [esp+14h] [ebp-2Ch]
  char v14[16]; // [esp+18h] [ebp-28h] BYREF
  int v15; // [esp+2Ch] [ebp-14h]
  _DWORD *v16; // [esp+30h] [ebp-10h]
  int v17; // [esp+3Ch] [ebp-4h]

  v16 = v11;
  v15 = 0;
  strcpy(v14, "GenuineIntel");
  _EAX = 0;
  __asm { cpuid }
  v12 = _EAX;
  v11[4] = _EBX;
  v11[5] = _EDX;
  v11[6] = _ECX;
  v17 = -1;
  if ( _EAX == 0 )
    return v15;
  _EAX = 1;
  __asm { cpuid }
  v12 = _EAX;
  v13 = _EDX;
  if ( (_EDX & 0x2000000) != 0 )
    v15 |= 4u;
  if ( (v13 & 0x4000000) != 0 )
    return v15 | 8;
  return v15;
}

//------------------------------------------------------------------------------
// Address: 0x10057CB3
// Name: D3DXCpuOptimizations(x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __stdcall D3DXCpuOptimizations(unsigned int Type)
{
  unsigned int v2; // [esp+Ch] [ebp-4h] BYREF

  D3DXCheckNewDelete();
  if ( Type != 0 )
  {
    if ( g_CpuOptimization == 0xFFFF )
    {
      g_CpuOptimization = 0;
      qmemcpy(g_D3DXFastTable, g_D3DXFastTableC, sizeof(g_D3DXFastTable));
      x86_D3DXInitFastTable(a1: (struct D3DXFASTTABLE *)&g_D3DXFastTable);
      if ( !sub_10057BA3(a1: (unsigned __int8 *)4, lpValueName: "DisablePSGP", (unsigned __int8 *)&Type, cbData: 4u) )
        Type = 0;
      if ( sub_10057BA3(
             a1: (unsigned __int8 *)4,
             lpValueName: "DisableD3DXPSGP",
             Type: (unsigned __int8 *)&v2,
             cbData: 4u) )
      {
        Type = v2;
      }
      if ( Type != 1 )
      {
        if ( Type == 2 || !IsProcessorFeaturePresent(ProcessorFeature: 7u) )
        {
          if ( (sub_10057C02() & 8) != 0 )
          {
            sse2_D3DXInitFastTable(a1: (struct D3DXFASTTABLE *)&g_D3DXFastTable);
            g_CpuOptimization = 2;
          }
          else if ( IsProcessorFeaturePresent(ProcessorFeature: 6u) )
          {
            sse_D3DXInitFastTable(a1: (struct D3DXFASTTABLE *)&g_D3DXFastTable);
            g_CpuOptimization = 3;
          }
        }
        else
        {
          x3d_D3DXInitFastTable(a1: (struct D3DXFASTTABLE *)&g_D3DXFastTable);
          g_CpuOptimization = 1;
        }
      }
    }
  }
  else
  {
    g_CpuOptimization = 0xFFFF;
    qmemcpy(g_D3DXFastTable, g_D3DXFastTableC, sizeof(g_D3DXFastTable));
  }
  return g_CpuOptimization;
}

//------------------------------------------------------------------------------
// Address: 0x10057DB6
// Name: void D3DXShader::Enter(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void D3DXShader::Enter()
{
  while ( InterlockedCompareExchange(Destination: &D3DXShader::g_SpinLock, Exchange: 1, Comperand: 0) == 1 )
    Sleep(dwMilliseconds: 1u);
  if ( D3DXShader::g_NumContenders == 0 )
    InitializeCriticalSection(lpCriticalSection: &D3DXShader::g_CriticalSection);
  ++D3DXShader::g_NumContenders;
  InterlockedExchange(Target: &D3DXShader::g_SpinLock, Value: 0);
  EnterCriticalSection(lpCriticalSection: &D3DXShader::g_CriticalSection);
}

//------------------------------------------------------------------------------
// Address: 0x10057E0B
// Name: void D3DXShader::Leave(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void D3DXShader::Leave()
{
  LeaveCriticalSection(lpCriticalSection: &D3DXShader::g_CriticalSection);
  while ( InterlockedCompareExchange(Destination: &D3DXShader::g_SpinLock, Exchange: 1, Comperand: 0) == 1 )
    Sleep(dwMilliseconds: 1u);
  if ( --D3DXShader::g_NumContenders == 0 )
    DeleteCriticalSection(lpCriticalSection: &D3DXShader::g_CriticalSection);
  InterlockedExchange(Target: &D3DXShader::g_SpinLock, Value: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10057E5C
// Name: public: D3DXShader::CPPDefine::CPPDefine(char const __near *,class D3DXShader::CNode __near *,class D3DXShader::CNode __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
D3DXShader::CPPDefine *__thiscall D3DXShader::CPPDefine::CPPDefine(
        D3DXShader::CPPDefine *this,
        const char *a2,
        struct D3DXShader::CNode *a3,
        struct D3DXShader::CNode *a4)
{
  *((_DWORD *)this + 3) = 0;
  *((_DWORD *)this + 4) = 0;
  *(_DWORD *)this = a2;
  *((_DWORD *)this + 1) = a3;
  *((_DWORD *)this + 2) = a4;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10057E80
// Name: public: D3DXShader::CPPConditional::CPPConditional(int,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
D3DXShader::CPPConditional *__thiscall D3DXShader::CPPConditional::CPPConditional(
        D3DXShader::CPPConditional *this,
        int a2,
        int a3)
{
  *((_DWORD *)this + 2) = 0;
  *((_DWORD *)this + 3) = 0;
  *(_DWORD *)this = a2;
  *((_DWORD *)this + 1) = a3;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10057E9E
// Name: public: D3DXShader::CPPConditional::~CPPConditional(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall D3DXShader::CPPConditional::~CPPConditional(D3DXShader::CPPConditional *this)
{
  void *v1; // esi

  v1 = *((void **)this + 3);
  if ( v1 != nullptr )
  {
    D3DXShader::CPPConditional::~CPPConditional(this: *((D3DXShader::CPPConditional **)this + 3));
    free(pMem: v1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10057EB8
// Name: public: D3DXShader::CPPInclude::CPPInclude(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
D3DXShader::CPPInclude *__thiscall D3DXShader::CPPInclude::CPPInclude(D3DXShader::CPPInclude *this)
{
  D3DXShader::CTokenize::CTokenize(this);
  D3DXCore::CFile::CFile(this: (D3DXShader::CPPInclude *)((char *)this + 60));
  D3DXCore::CResource::CResource(this: (D3DXShader::CPPInclude *)((char *)this + 76));
  *((_DWORD *)this + 14) = 0;
  *((_DWORD *)this + 22) = 0;
  *((_DWORD *)this + 25) = 0;
  *((_DWORD *)this + 26) = 0;
  *((_DWORD *)this + 23) = 0;
  *((_DWORD *)this + 24) = 0;
  *((_DWORD *)this + 27) = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10057EED
// Name: public: D3DXShader::CPPInclude::~CPPInclude(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall D3DXShader::CPPInclude::~CPPInclude(D3DXShader::CPPInclude *this)
{
  D3DXShader::CPPDefine *v2; // ecx
  void *v3; // edi

  v2 = *((D3DXShader::CPPDefine **)this + 14);
  if ( v2 != nullptr )
    D3DXShader::CPPDefine::`scalar deleting destructor'(this: v2, a2: 1);
  v3 = *((void **)this + 27);
  if ( v3 != nullptr )
  {
    D3DXShader::CPPInclude::~CPPInclude(this: *((D3DXShader::CPPInclude **)this + 27));
    free(pMem: v3);
  }
  if ( *((_DWORD *)this + 22) != 0 && *((_DWORD *)this + 25) != 0 )
    (*(void (__stdcall **)(_DWORD, _DWORD))(**((_DWORD **)this + 22) + 4))(
      a1: *((_DWORD *)this + 22),
      a2: *((_DWORD *)this + 25));
  D3DXCore::CResource::~CResource(this: (D3DXShader::CPPInclude *)((char *)this + 76));
  D3DXCore::CFile::~CFile(this: (D3DXShader::CPPInclude *)((char *)this + 60));
  D3DXShader::CNodeState::Print(this);
}

//------------------------------------------------------------------------------
// Address: 0x10057F67
// Name: public: long D3DXShader::CPPInclude::InitializeFromFile(void const __near *,int,class D3DXCore::CAlloc __near *,struct D3DXShader::D3DXTOKEN __near *,class D3DXShader::CTErrors __near *,struct ID3DXInclude __near *,enum _D3DXINCLUDE_TYPE,void const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CPPInclude::InitializeFromFile(
        D3DXShader::CPPInclude *this,
        const char *lpWideCharStr,
        int a3,
        struct D3DXCore::CAlloc *a4,
        struct D3DXShader::D3DXTOKEN *a5,
        struct D3DXShader::CTErrors *a6,
        struct ID3DXInclude *a7,
        enum _D3DXINCLUDE_TYPE a8,
        const void *a9)
{
  unsigned int v10; // kr00_4
  unsigned __int8 *v11; // eax
  unsigned int *v12; // edi
  const void **v13; // esi
  int result; // eax
  DWORD FullPathNameA; // esi
  unsigned __int8 *v16; // eax
  unsigned __int8 *v17; // eax
  unsigned int v18; // ecx
  int v19; // esi
  LPSTR FilePart; // [esp+Ch] [ebp-120h] BYREF
  struct D3DXShader::D3DXTOKEN *v21; // [esp+10h] [ebp-11Ch]
  struct D3DXShader::CTErrors *v22; // [esp+14h] [ebp-118h]
  struct D3DXCore::CAlloc *v23; // [esp+18h] [ebp-114h]
  unsigned int v24; // [esp+1Ch] [ebp-110h]
  LPCSTR lpFileName; // [esp+20h] [ebp-10Ch]
  char MultiByteStr[260]; // [esp+24h] [ebp-108h] BYREF

  v23 = a4;
  v21 = a5;
  v22 = a6;
  lpFileName = lpWideCharStr;
  v24 = (unsigned int)a9;
  *((_DWORD *)this + 22) = a7;
  if ( a3 != 0 )
  {
    WideCharToMultiByte(
      CodePage: 0xFDE9u,
      dwFlags: 0,
      (LPCWCH)lpWideCharStr,
      cchWideChar: -1,
      lpMultiByteStr: MultiByteStr,
      cbMultiByte: 260,
      lpDefaultChar: nullptr,
      lpUsedDefaultChar: nullptr);
    lpFileName = MultiByteStr;
  }
  if ( a7 != nullptr )
  {
    v10 = strlen(lpFileName);
    v11 = D3DXCore::CAlloc::Alloc(this: v23, a2: v10 + 1, a3: 1u);
    *((_DWORD *)this + 23) = v11;
    if ( v11 != nullptr )
    {
      qmemcpy(v11, lpFileName, v10 + 1);
      v12 = (unsigned int *)((char *)this + 104);
      v13 = (const void **)((char *)this + 100);
      v24 = (***((int (__stdcall ****)(_DWORD, enum _D3DXINCLUDE_TYPE, _DWORD, unsigned int, char *, char *))this + 22))(
              a1: *((_DWORD *)this + 22),
              a2: a8,
              a3: *((_DWORD *)this + 23),
              a4: v24,
              a5: (char *)this + 100,
              a6: (char *)this + 104);
      if ( (v24 & 0x80000000) != 0 )
      {
        D3DXShader::CTErrors::Error(
          this: v22,
          a2: v21,
          a3: 0x5E3u,
          format: "failed to open source file: '%s'",
          lpFileName);
        return v24;
      }
      goto LABEL_15;
    }
    return -2147024882;
  }
  FullPathNameA = GetFullPathNameA(lpFileName, nBufferLength: 0, lpBuffer: nullptr, lpFilePart: nullptr);
  v24 = FullPathNameA + 1;
  v16 = D3DXCore::CAlloc::Alloc(this: v23, a2: FullPathNameA + 1, a3: 1u);
  *((_DWORD *)this + 24) = v16;
  if ( v16 == nullptr )
    return -2147024882;
  v17 = D3DXCore::CAlloc::Alloc(this: v23, a2: v24, a3: 1u);
  *((_DWORD *)this + 23) = v17;
  if ( v17 == nullptr )
    return -2147024882;
  GetFullPathNameA(lpFileName, nBufferLength: FullPathNameA, lpBuffer: *((LPSTR *)this + 24), lpFilePart: &FilePart);
  v18 = v24;
  *(_BYTE *)(FullPathNameA + *((_DWORD *)this + 24)) = 0;
  qmemcpy(*((void **)this + 23), *((const void **)this + 24), v18);
  if ( FilePart != nullptr )
    *FilePart = 0;
  v19 = D3DXCore::CFile::Open(
          this: (D3DXShader::CPPInclude *)((char *)this + 60),
          lpWideCharStr: *((LPCWCH *)this + 23),
          a3: 0);
  if ( v19 < 0 )
  {
    D3DXShader::CTErrors::Error(this: v22, a2: v21, a3: 0x5E3u, format: "failed to open source file: '%s'", lpFileName);
    return v19;
  }
  v13 = (const void **)((char *)this + 100);
  *((_DWORD *)this + 25) = *((_DWORD *)this + 17);
  v12 = (unsigned int *)((char *)this + 104);
  *((_DWORD *)this + 26) = *((_DWORD *)this + 18);
LABEL_15:
  result = D3DXShader::CTokenize::Initialize(
             this,
             a2: *v13,
             a3: *v12,
             a4: *((const char **)this + 23),
             a5: 1u,
             a6: v23,
             a7: v22);
  if ( result >= 0 )
    return 0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1005819B
// Name: public: long D3DXShader::CPPInclude::InitializeFromMemory(void const __near *,unsigned int,class D3DXCore::CAlloc __near *,class D3DXShader::CTErrors __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CPPInclude::InitializeFromMemory(
        D3DXShader::CPPInclude *this,
        void *a2,
        unsigned int a3,
        struct D3DXCore::CAlloc *a4,
        struct D3DXShader::CTErrors *a5)
{
  int result; // eax

  if ( a3 != 0 && a2 == nullptr )
    return -2005530516;
  *((_DWORD *)this + 25) = a2;
  *((_DWORD *)this + 26) = a3;
  result = D3DXShader::CTokenize::Initialize(this, a2, a3, a4: nullptr, a5: 1u, a6: a4, a7: a5);
  if ( result >= 0 )
    return 0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100581D6
// Name: public: D3DXShader::CPPBlock::CPPBlock(unsigned long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
D3DXShader::CPPBlock *__thiscall D3DXShader::CPPBlock::CPPBlock(D3DXShader::CPPBlock *this, unsigned int a2)
{
  *((_DWORD *)this + 1) = 0;
  *(_DWORD *)this = a2;
  *((_DWORD *)this + 2) = 1;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100581F1
// Name: public: D3DXShader::CPPBlock::~CPPBlock(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall D3DXShader::CPPBlock::~CPPBlock(D3DXShader::CPPBlock *this)
{
  void *v1; // esi

  v1 = *((void **)this + 1);
  if ( v1 != nullptr )
  {
    D3DXShader::CPPBlock::~CPPBlock(this: *((D3DXShader::CPPBlock **)this + 1));
    free(pMem: v1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1005822C
// Name: public: D3DXShader::CPPPragmaDef::~CPPPragmaDef(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall D3DXShader::CPPPragmaDef::~CPPPragmaDef(D3DXShader::CPPPragmaDef *this)
{
  void *v1; // esi

  v1 = *((void **)this + 10);
  if ( v1 != nullptr )
  {
    D3DXShader::CPPPragmaDef::~CPPPragmaDef(this: *((D3DXShader::CPPPragmaDef **)this + 10));
    free(pMem: v1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10074AA5
// Name: public: class D3DXShader::CConstant __near * D3DXShader::CConstant::GetConstantByName(char const __near *,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
struct D3DXShader::CConstant *__thiscall D3DXShader::CConstant::GetConstantByName(
        D3DXShader::CConstant *this,
        const char *a2,
        unsigned int a3)
{
  char v4; // al
  unsigned int v5; // edi
  D3DXShader::CConstant *ConstantElement; // eax
  int i; // edi
  D3DXShader::CConstant *v8; // ecx
  const char *v11; // [esp+18h] [ebp+8h]
  unsigned int v12; // [esp+1Ch] [ebp+Ch]

  while ( 1 )
  {
    while ( isspace(c: *a2) != 0 )
      ++a2;
    v4 = *a2;
    if ( *a2 == 0 )
      return this;
    if ( v4 != 91 )
      break;
    do
      ++a2;
    while ( isspace(c: *a2) != 0 );
    if ( isdigit(c: *a2) == 0 )
      return nullptr;
    v5 = 0;
    while ( isdigit(c: *a2) != 0 )
      v5 = *a2++ + 10 * v5 - 48;
    while ( isspace(c: *a2) != 0 )
      ++a2;
    if ( *a2 != 93 )
      return nullptr;
    ConstantElement = D3DXShader::CConstant::GetConstantElement(this, a2: v5);
    if ( ConstantElement == nullptr )
      return nullptr;
    a3 = 0;
    ++a2;
LABEL_34:
    this = ConstantElement;
  }
  if ( v4 == 46 )
    goto LABEL_20;
  if ( a3 != 0 )
  {
    while ( isspace(c: *a2) != 0 )
LABEL_20:
      ++a2;
    for ( i = 0; isalnum(c: a2[i]) != 0 || a2[i] == 95; ++i )
      ;
    if ( i != 0 )
    {
      v8 = this;
      v12 = 0;
      v11 = (const char *)*(unsigned __int16 *)(*((_DWORD *)this + 6) + 10);
      while ( v12 < (unsigned int)v11 )
      {
        if ( *(_DWORD *)(*(_DWORD *)(*((_DWORD *)v8 + 14) + 4 * v12) + 4) != 0 && sub_10071792(a1: i) == 0 )
        {
          ConstantElement = D3DXShader::CConstant::GetConstantMember(this, a2: v12);
          if ( ConstantElement == nullptr )
            return nullptr;
          a3 = 0;
          a2 += i;
          goto LABEL_34;
        }
        ++v12;
        v8 = this;
      }
    }
  }
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10074BF3
// Name: public: long D3DXShader::CConstantTable::FindConstantByName(char const __near *,class D3DXShader::CConstant __near * __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CConstantTable::FindConstantByName(
        D3DXShader::CConstantTable *this,
        const char *a2,
        struct D3DXShader::CConstant **a3)
{
  const char *v3; // edi
  D3DXShader::CConstantTable *v4; // ebx
  int v6; // eax
  unsigned int v7; // esi
  int v8; // edi
  int v9; // eax
  _DWORD *v10; // eax
  const char *v11; // ecx
  char *v12; // eax
  const char *v13; // eax
  struct D3DXShader::CConstant **ConstantByName; // eax
  const char *j; // edi
  const char *v16; // edi
  const char *v17; // eax
  const char *v18; // [esp+8h] [ebp-18h]
  char *v19; // [esp+Ch] [ebp-14h]
  const char *v20; // [esp+10h] [ebp-10h]
  unsigned int v22; // [esp+18h] [ebp-8h]
  int i; // [esp+1Ch] [ebp-4h]
  const char *v24; // [esp+28h] [ebp+8h]
  const char *v25; // [esp+28h] [ebp+8h]

  v3 = a2;
  v4 = this;
  if ( (int)a2 >= 0 )
  {
    v20 = a2;
    if ( isspace(c: *a2) != 0 )
    {
      do
        ++v3;
      while ( isspace(c: *v3) != 0 );
      v20 = v3;
    }
    if ( isalnum(c: *v3) != 0 || *v3 == 95 || *v3 == 36 )
    {
      for ( i = 1; isalnum(c: v3[i]) != 0 || v3[i] == 95; ++i )
        ;
      v6 = *((_DWORD *)v4 + 4);
      v7 = 0;
      v22 = 0;
      v8 = *((_DWORD *)v4 + 2) + *(_DWORD *)(v6 + 16);
      v24 = *(const char **)(v6 + 12);
      if ( v24 != nullptr )
      {
        do
        {
          v7 = (unsigned int)&v24[v22] >> 1;
          v9 = sub_10071792(a1: i);
          if ( v9 == 0 )
            break;
          if ( v9 >= 0 )
            v24 = (const char *)((unsigned int)&v24[v22] >> 1);
          else
            v22 = v7 + 1;
        }
        while ( v22 < (unsigned int)v24 );
        v4 = this;
      }
      if ( (const char *)v22 == v24 )
        return -2005530516;
      v10 = (_DWORD *)(v8 + 20 * v7);
      v11 = (const char *)(*((_DWORD *)v4 + 2) + *v10);
      v18 = v11;
      if ( v7 != 0 )
      {
        v12 = (char *)(v10 - 5);
        v19 = v12;
        do
        {
          v13 = (const char *)(*((_DWORD *)v4 + 2) + *(_DWORD *)v12);
          if ( v11 != v13 && strcmp(v11, v13) != 0 )
            break;
          --v7;
          v12 = v19 - 20;
          v19 -= 20;
        }
        while ( v7 != 0 );
      }
      ConstantByName = (struct D3DXShader::CConstant **)D3DXShader::CConstant::GetConstantByName(
                                                          this: *(D3DXShader::CConstant **)(*((_DWORD *)v4 + 5) + 4 * v7),
                                                          a2: &v20[i],
                                                          a3: 0);
      if ( ConstantByName == nullptr )
      {
        return -2005530516;
      }
      else
      {
        for ( j = (const char *)(v8 + 20 * v7); ; j = v25 )
        {
          *a3 = (struct D3DXShader::CConstant *)ConstantByName;
          a3 = ConstantByName + 9;
          ++v7;
          v16 = j + 20;
          v25 = v16;
          if ( v7 >= *(_DWORD *)(*((_DWORD *)v4 + 4) + 12) )
            break;
          v17 = (const char *)(*((_DWORD *)v4 + 2) + *(_DWORD *)v16);
          if ( v18 != v17 && strcmp(v18, v17) != 0 )
            break;
          ConstantByName = (struct D3DXShader::CConstant **)D3DXShader::CConstant::GetConstantByName(
                                                              this: *(D3DXShader::CConstant **)(*((_DWORD *)v4 + 5) + 4 * v7),
                                                              a2: &v20[i],
                                                              a3: 0);
          if ( ConstantByName == nullptr )
            return -2005530516;
        }
        return 0;
      }
    }
    else
    {
      return -2005530516;
    }
  }
  else
  {
    *a3 = (struct D3DXShader::CConstant *)-(int)a2;
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10074DFA
// Name: public: virtual long D3DXShader::CConstantTable::GetConstantDesc(char const __near *,struct _D3DXCONSTANT_DESC __near *,unsigned int __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __stdcall D3DXShader::CConstantTable::GetConstantDesc(
        D3DXShader::CConstantTable *this,
        char *a2,
        struct _D3DXCONSTANT_DESC *a3,
        unsigned int *a4)
{
  struct _D3DXCONSTANT_DESC *v4; // ebx
  unsigned int *v5; // edi
  int result; // eax
  D3DXShader::CConstant *v7; // ecx
  unsigned int v8; // edx
  unsigned int v9; // esi
  D3DXShader::CConstant *i; // eax
  int v11; // ecx

  v4 = a3;
  v5 = a4;
  if ( a3 == nullptr && a4 == nullptr )
    return -2005530516;
  if ( (int)a2 >= 0 )
  {
    result = D3DXShader::CConstantTable::FindConstantByName(this, a2, (struct D3DXShader::CConstant **)&a3);
    if ( result < 0 )
      return result;
    v7 = (D3DXShader::CConstant *)a3;
  }
  else
  {
    v7 = (D3DXShader::CConstant *)-(int)a2;
  }
  v8 = 0;
  v9 = 1;
  for ( i = v7; i != nullptr; ++v8 )
    i = *((D3DXShader::CConstant **)i + 9);
  if ( v5 != nullptr )
  {
    if ( *v5 != 0 )
      v9 = *v5;
    if ( v9 > v8 )
      v9 = v8;
    *v5 = v8;
  }
  if ( v4 != nullptr )
  {
    while ( v7 != nullptr && v9 != 0 )
    {
      result = D3DXShader::CConstant::GetDesc(this: v7, a2: v4);
      if ( result < 0 )
        return result;
      v7 = *(D3DXShader::CConstant **)(v11 + 36);
      ++v4;
      --v9;
    }
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10074E85
// Name: public: virtual unsigned int D3DXShader::CConstantTable::GetSamplerIndex(char const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __stdcall D3DXShader::CConstantTable::GetSamplerIndex(D3DXShader::CConstantTable *this, int a2)
{
  int v2; // eax

  if ( a2 >= 0 )
  {
    if ( D3DXShader::CConstantTable::FindConstantByName(
           this,
           (const char *)a2,
           a3: (struct D3DXShader::CConstant **)&a2) < 0 )
      return -1;
    v2 = a2;
  }
  else
  {
    v2 = -a2;
  }
  if ( *(_WORD *)(v2 + 8) != 3 )
    return -1;
  return *(unsigned __int16 *)(v2 + 10);
}

//------------------------------------------------------------------------------
// Address: 0x10074EBD
// Name: public: virtual char const __near * D3DXShader::CConstantTable::GetConstant(char const __near *,unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
const char *__stdcall D3DXShader::CConstantTable::GetConstant(
        D3DXShader::CConstantTable *this,
        char *a2,
        unsigned int a3)
{
  int ConstantMember; // eax

  if ( a2 != nullptr )
  {
    if ( (int)a2 >= 0 )
    {
      if ( D3DXShader::CConstantTable::FindConstantByName(this, a2, a3: &this) < 0 )
        return nullptr;
    }
    else
    {
      this = (D3DXShader::CConstantTable *)-(int)a2;
    }
    ConstantMember = (int)D3DXShader::CConstant::GetConstantMember(this, a2: a3);
    if ( ConstantMember != 0 )
      return (const char *)-ConstantMember;
  }
  else if ( a3 < *((_DWORD *)this + 6) )
  {
    ConstantMember = *(_DWORD *)(*((_DWORD *)this + 5) + 4 * a3);
    return (const char *)-ConstantMember;
  }
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10074F0D
// Name: public: virtual char const __near * D3DXShader::CConstantTable::GetConstantByName(char const __near *,char const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
const char *__stdcall D3DXShader::CConstantTable::GetConstantByName(int this, char *a2, char *a3)
{
  int ConstantByName; // eax

  if ( a2 != nullptr )
  {
    if ( (int)a2 >= 0 )
    {
      if ( D3DXShader::CConstantTable::FindConstantByName(
             (D3DXShader::CConstantTable *)this,
             a2,
             a3: (struct D3DXShader::CConstant **)&this) < 0 )
        return nullptr;
    }
    else
    {
      this = -(int)a2;
    }
    ConstantByName = (int)D3DXShader::CConstant::GetConstantByName((D3DXShader::CConstant *)this, a2: a3, a3: 1u);
    if ( ConstantByName != 0 )
      return (const char *)-ConstantByName;
  }
  else
  {
    if ( (int)a3 < 0 )
    {
      ConstantByName = -(int)a3;
      return (const char *)-ConstantByName;
    }
    if ( D3DXShader::CConstantTable::FindConstantByName(
           (D3DXShader::CConstantTable *)this,
           a2: a3,
           a3: (struct D3DXShader::CConstant **)&this) >= 0 )
    {
      ConstantByName = this;
      return (const char *)-ConstantByName;
    }
  }
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10074F6D
// Name: public: virtual char const __near * D3DXShader::CConstantTable::GetConstantElement(char const __near *,unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
const char *__stdcall D3DXShader::CConstantTable::GetConstantElement(
        D3DXShader::CConstantTable *this,
        int a2,
        unsigned int a3)
{
  int ConstantElement; // eax

  if ( a2 >= 0 )
  {
    if ( D3DXShader::CConstantTable::FindConstantByName(
           this,
           (const char *)a2,
           a3: (struct D3DXShader::CConstant **)&a2) < 0 )
      return nullptr;
  }
  else
  {
    a2 = -a2;
  }
  ConstantElement = (int)D3DXShader::CConstant::GetConstantElement(this: (D3DXShader::CConstant *)a2, a2: a3);
  if ( ConstantElement == 0 )
    return nullptr;
  return (const char *)-ConstantElement;
}

//------------------------------------------------------------------------------
// Address: 0x100F56C0
// Name: _dynamic_atexit_destructor_for__mat_spewvertexandpixelshaders_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_spewvertexandpixelshaders_command__()
{
  ConCommand::~ConCommand(this: &mat_spewvertexandpixelshaders_command);
}

//------------------------------------------------------------------------------
// Address: 0x100F56D0
// Name: _dynamic_atexit_destructor_for__mat_shadercount_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_shadercount_command__()
{
  ConCommand::~ConCommand(this: &mat_shadercount_command);
}

//------------------------------------------------------------------------------
// Address: 0x100F56E0
// Name: _dynamic_atexit_destructor_for__s_ShaderComboInfoByName__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_ShaderComboInfoByName__()
{
  CUtlSymbolTable::~CUtlSymbolTable(this: &s_ShaderComboInfoByName.m_SymbolTable);
  CUtlVector<CTransitionTable::ShadowStateDictEntry_t,CUtlMemory<CTransitionTable::ShadowStateDictEntry_t,int>>::~CUtlVector<CTransitionTable::ShadowStateDictEntry_t,CUtlMemory<CTransitionTable::ShadowStateDictEntry_t,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&s_ShaderComboInfoByName);
}

//------------------------------------------------------------------------------
// Address: 0x100F5700
// Name: _dynamic_atexit_destructor_for__s_ShaderManager__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_ShaderManager__()
{
  CShaderManager::~CShaderManager(this: &s_ShaderManager);
}

//------------------------------------------------------------------------------
// Address: 0x100F5710
// Name: _dynamic_atexit_destructor_for__s_EmptyConVar__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_EmptyConVar__()
{
  s_EmptyConVar.ConVar::ConCommandBase::__vftable = (CEmptyConVar_vtbl *)&ConVar::`vftable'{for `ConCommandBase'};
  s_EmptyConVar.ConVar::IConVar::__vftable = (IConVar_vtbl *)&ConVar::`vftable'{for `IConVar'};
  if ( s_EmptyConVar.m_Value.m_pszString != nullptr )
  {
    free(pMem: s_EmptyConVar.m_Value.m_pszString);
    s_EmptyConVar.m_Value.m_pszString = nullptr;
  }
  CUtlVector<CTransitionTable::ShadowStateDictEntry_t,CUtlMemory<CTransitionTable::ShadowStateDictEntry_t,int>>::~CUtlVector<CTransitionTable::ShadowStateDictEntry_t,CUtlMemory<CTransitionTable::ShadowStateDictEntry_t,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&s_EmptyConVar.m_fnChangeCallbacks);
  s_EmptyConVar.ConVar::ConCommandBase::__vftable = (CEmptyConVar_vtbl *)&ConCommandBase::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x100F5760
// Name: _dynamic_atexit_destructor_for__g_ExpressionEvaluator__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_ExpressionEvaluator__()
{
  CExpressionEvaluator::~CExpressionEvaluator(this: &g_ExpressionEvaluator);
}

//------------------------------------------------------------------------------
// Address: 0x100F5770
// Name: _dynamic_atexit_destructor_for__g_CleanupSymbolTable__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CleanupSymbolTable__()
{
  CUtlSymbolTableMT *v0; // esi

  v0 = CUtlSymbol::s_pSymbolTable;
  if ( CUtlSymbol::s_pSymbolTable != nullptr )
  {
    CUtlSymbolTable::RemoveAll(this: CUtlSymbol::s_pSymbolTable);
    CUtlVector<CTransitionTable::ShadowStateDictEntry_t,CUtlMemory<CTransitionTable::ShadowStateDictEntry_t,int>>::~CUtlVector<CTransitionTable::ShadowStateDictEntry_t,CUtlMemory<CTransitionTable::ShadowStateDictEntry_t,int>>(this: &v0->m_StringPools);
    CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::~CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>(this: &v0->m_Lookup);
    free(pMem: v0);
  }
  CUtlSymbol::s_pSymbolTable = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x100F57B0
// Name: _dynamic_atexit_destructor_for__vtMissing__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__vtMissing__()
{
  VariantClear(pvarg: &vtMissing);
}

// ============================================================
// Overlay from shaderapidx10 (Missing functions)
// ============================================================
namespace shaderapidx10 {

//------------------------------------------------------------------------------
// Address: 0x1000B200
// Name: public: void CUtlMemory<struct StaticComboRecord_t,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<StaticComboRecord_t,int>::Grow(
        CUtlMemory<CMeshMgr::VertexBufferLookup_t,int> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  CMeshMgr::VertexBufferLookup_t *m_pMemory; // edx
  unsigned int v7; // [esp-4h] [ebp-Ch]

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
        m_nAllocationCount = 4;
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
    v7 = 8 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (CMeshMgr::VertexBufferLookup_t *)_g_pMemAlloc->Realloc_2(
                                                            this: _g_pMemAlloc,
                                                            a2: m_pMemory,
                                                            a3: v7);
    else
      this->m_pMemory = (CMeshMgr::VertexBufferLookup_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000C320
// Name: public: void CUtlVector<unsigned char,class CUtlMemory<unsigned char,int>>::EnsureCapacity(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<unsigned char,CUtlMemory<unsigned char,int>>::EnsureCapacity(
        CUtlVector<unsigned char,CUtlMemory<unsigned char,int> > *this,
        int num)
{
  unsigned __int8 *m_pMemory; // eax
  bool v4; // zf
  unsigned __int8 *v5; // eax

  if ( this->m_Memory.m_nAllocationCount >= num )
  {
    this->m_pElements = this->m_Memory.m_pMemory;
  }
  else if ( this->m_Memory.m_nGrowSize < 0 )
  {
    this->m_pElements = this->m_Memory.m_pMemory;
  }
  else
  {
    m_pMemory = this->m_Memory.m_pMemory;
    v4 = this->m_Memory.m_pMemory == nullptr;
    this->m_Memory.m_nAllocationCount = num;
    if ( v4 )
      v5 = (unsigned __int8 *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: num);
    else
      v5 = (unsigned __int8 *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: num);
    this->m_Memory.m_pMemory = v5;
    this->m_pElements = v5;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000C380
// Name: public: int CUtlVector<unsigned char,class CUtlMemoryAligned<unsigned char,32>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<unsigned char,CUtlMemoryAligned<unsigned char,32>>::InsertMultipleBefore(
        CUtlVector<unsigned char,CUtlMemoryAligned<unsigned char,32> > *this,
        int elem,
        int num)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  unsigned __int8 *m_pMemory; // ecx
  int v8; // eax
  int v9; // eax

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemoryAligned<unsigned char,32>::Grow(this: &this->m_Memory, num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v8 = this->m_Size;
  this->m_pElements = this->m_Memory.m_pMemory;
  v9 = v8 - elem - num;
  if ( v9 > 0 && num > 0 )
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: v9);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x1000C440
// Name: public: int CUtlVector<unsigned char,class CUtlMemory<unsigned char,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<unsigned char,CUtlMemory<unsigned char,int>>::InsertMultipleBefore(
        CUtlVector<unsigned char,CUtlMemory<unsigned char,int> > *this,
        int elem,
        int num)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  unsigned __int8 *m_pMemory; // ecx
  int v8; // eax
  int v9; // eax

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<CTransitionTable::TransitionOp_t,int>::Grow(
      this: &this->m_Memory,
      num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v8 = this->m_Size;
  this->m_pElements = this->m_Memory.m_pMemory;
  v9 = v8 - elem - num;
  if ( v9 > 0 && num > 0 )
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: v9);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x1000C8F0
// Name: public: int CUtlVector<unsigned short,class CUtlMemory<unsigned short,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<unsigned short,CUtlMemory<unsigned short,int>>::InsertMultipleBefore(
        CUtlVector<unsigned short,CUtlMemory<unsigned short,int> > *this,
        int elem,
        int num)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  unsigned __int16 *m_pMemory; // ecx
  int v8; // eax
  int v9; // eax

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<unsigned short,int>::Grow(this: &this->m_Memory, num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v8 = this->m_Size;
  this->m_pElements = this->m_Memory.m_pMemory;
  v9 = v8 - elem - num;
  if ( v9 > 0 && num > 0 )
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 2 * v9);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x100168E0
// Name: public: void CUtlFixedMemory<struct UtlLinkedListElem_t<struct Texture_t,int>>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlFixedMemory<UtlLinkedListElem_t<Texture_t,int>>::Grow(
        CUtlFixedMemory<UtlLinkedListElem_t<Texture_t,int> > *this,
        int num)
{
  int m_nGrowSize; // esi
  CUtlFixedMemory<UtlLinkedListElem_t<Texture_t,int> >::BlockHeader_t *v4; // ebx
  CUtlFixedMemory<UtlLinkedListElem_t<Texture_t,int> >::BlockHeader_t *m_pBlocks; // eax
  bool v6; // zf

  if ( num > 0 )
  {
    m_nGrowSize = this->m_nGrowSize;
    if ( m_nGrowSize == 0 )
    {
      m_nGrowSize = this->m_nAllocationCount;
      if ( m_nGrowSize == 0 )
        m_nGrowSize = 1;
    }
    if ( m_nGrowSize < num )
      m_nGrowSize *= (m_nGrowSize + num - 1) / m_nGrowSize;
    this->m_nAllocationCount += m_nGrowSize;
    v4 = (CUtlFixedMemory<UtlLinkedListElem_t<Texture_t,int> >::BlockHeader_t *)_g_pMemAlloc->Alloc_2(
                                                                                  this: _g_pMemAlloc,
                                                                                  a2: 96 * m_nGrowSize + 8);
    if ( v4 == nullptr )
      _Error(a1: "CUtlFixedMemory overflow!\n");
    m_pBlocks = this->m_pBlocks;
    v6 = this->m_pBlocks == nullptr;
    v4->m_pNext = nullptr;
    v4->m_nBlockSize = m_nGrowSize;
    if ( v6 )
    {
      this->m_pBlocks = v4;
    }
    else
    {
      for ( ; m_pBlocks->m_pNext != nullptr; m_pBlocks = m_pBlocks->m_pNext )
        ;
      m_pBlocks->m_pNext = v4;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001A8B0
// Name: public: class CUtlFixedMemory<struct UtlLinkedListElem_t<struct CShaderManager::ShaderLookup_t,int>>::Iterator_t CUtlFixedMemory<struct UtlLinkedListElem_t<struct CShaderManager::ShaderLookup_t,int>>::First(void)const
// Source: json
//------------------------------------------------------------------------------
CUtlFixedMemory<UtlLinkedListElem_t<IDirect3DVertexShader9 *,int> >::Iterator_t *__thiscall CUtlFixedMemory<UtlLinkedListElem_t<CShaderManager::ShaderLookup_t,int>>::First(
        CUtlFixedMemory<UtlLinkedListElem_t<Texture_t,int> > *this,
        CUtlFixedMemory<UtlLinkedListElem_t<IDirect3DVertexShader9 *,int> >::Iterator_t *result)
{
  CUtlFixedMemory<UtlLinkedListElem_t<Texture_t,int> >::Iterator_t v4; // 0:^0.8

  if ( this->m_pBlocks != nullptr )
  {
    v4.m_pBlockHeader = this->m_pBlocks;
    v4.m_nIndex = 0;
  }
  else
  {
    v4.m_pBlockHeader = nullptr;
    v4.m_nIndex = -1;
  }
  *(CUtlFixedMemory<UtlLinkedListElem_t<Texture_t,int> >::Iterator_t *)result = v4;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1001A8F0
// Name: public: void CUtlFixedMemory<struct UtlLinkedListElem_t<struct Texture_t,int>>::Init(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlFixedMemory<UtlLinkedListElem_t<Texture_t,int>>::Init(
        CUtlFixedMemory<UtlLinkedListElem_t<Texture_t,int> > *this,
        int nGrowSize,
        int nInitSize)
{
  CUtlFixedMemory<UtlLinkedListElem_t<Texture_t,int> >::BlockHeader_t *m_pBlocks; // esi
  CUtlFixedMemory<UtlLinkedListElem_t<Texture_t,int> >::BlockHeader_t *v5; // eax

  m_pBlocks = this->m_pBlocks;
  if ( this->m_pBlocks != nullptr )
  {
    do
    {
      v5 = m_pBlocks;
      m_pBlocks = m_pBlocks->m_pNext;
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v5);
    }
    while ( m_pBlocks != nullptr );
    this->m_pBlocks = nullptr;
    this->m_nAllocationCount = 0;
  }
  this->m_nGrowSize = nGrowSize;
  CUtlFixedMemory<UtlLinkedListElem_t<Texture_t,int>>::Grow(this, num: nInitSize);
}

//------------------------------------------------------------------------------
// Address: 0x1001A940
// Name: public: bool CUtlFixedMemory<struct UtlLinkedListElem_t<struct Texture_t,int>>::IsIdxAfter(int,class CUtlFixedMemory<struct UtlLinkedListElem_t<struct Texture_t,int>>::Iterator_t const __near &)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CUtlFixedMemory<UtlLinkedListElem_t<Texture_t,int>>::IsIdxAfter(
        CUtlFixedMemory<UtlLinkedListElem_t<Texture_t,int> > *this,
        unsigned int i,
        const CUtlFixedMemory<UtlLinkedListElem_t<Texture_t,int> >::Iterator_t *it)
{
  CUtlFixedMemory<UtlLinkedListElem_t<Texture_t,int> >::BlockHeader_t *m_pBlockHeader; // eax
  int m_nIndex; // ecx
  CUtlFixedMemory<UtlLinkedListElem_t<Texture_t,int> >::BlockHeader_t *m_pNext; // eax

  m_pBlockHeader = it->m_pBlockHeader;
  if ( it->m_pBlockHeader == nullptr )
    return false;
  m_nIndex = it->m_nIndex;
  if ( m_nIndex < 0 || m_nIndex >= m_pBlockHeader->m_nBlockSize )
    return false;
  if ( i >= (unsigned int)&m_pBlockHeader[1] && i < (unsigned int)&m_pBlockHeader[12 * m_pBlockHeader->m_nBlockSize + 1] )
    return (int)i > (int)&m_pBlockHeader[12 * m_nIndex + 1];
  m_pNext = m_pBlockHeader->m_pNext;
  if ( m_pNext == nullptr )
    return false;
  while ( i < (unsigned int)&m_pNext[1] || i >= (unsigned int)&m_pNext[12 * m_pNext->m_nBlockSize + 1] )
  {
    m_pNext = m_pNext->m_pNext;
    if ( m_pNext == nullptr )
      return false;
  }
  return true;
}

//------------------------------------------------------------------------------
// Address: 0x10020940
// Name: protected: int CUtlLinkedList<struct Texture_t,int,1,int,class CUtlFixedMemory<struct UtlLinkedListElem_t<struct Texture_t,int>>>::AllocInternal(bool)
// Source: json
//------------------------------------------------------------------------------
CUtlFixedMemory<UtlLinkedListElem_t<Texture_t,int> >::BlockHeader_t *__thiscall CUtlLinkedList<Texture_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<Texture_t,int>>>::AllocInternal(
        CUtlLinkedList<Texture_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<Texture_t,int> > > *this,
        bool multilist)
{
  CUtlFixedMemory<UtlLinkedListElem_t<Texture_t,int> >::BlockHeader_t *result; // eax
  CUtlFixedMemory<UtlLinkedListElem_t<Texture_t,int> >::BlockHeader_t *m_pBlockHeader; // eax
  CUtlFixedMemory<UtlLinkedListElem_t<Texture_t,int> >::Iterator_t *p_m_LastAlloc; // esi
  int m_nIndex; // ecx
  CUtlFixedMemory<UtlLinkedListElem_t<Texture_t,int> >::Iterator_t *v7; // eax
  CUtlFixedMemory<UtlLinkedListElem_t<Texture_t,int> >::BlockHeader_t *v8; // ecx
  bool v9; // zf
  int v10; // eax
  int v11; // ecx
  CUtlFixedMemory<UtlLinkedListElem_t<IDirect3DVertexShader9 *,int> >::Iterator_t *v12; // eax
  int v13; // esi
  CUtlFixedMemory<UtlLinkedListElem_t<Texture_t,int> >::Iterator_t v14; // [esp+Ch] [ebp-18h] BYREF
  CUtlFixedMemory<UtlLinkedListElem_t<Texture_t,int> >::Iterator_t v15; // [esp+14h] [ebp-10h] BYREF
  CUtlFixedMemory<UtlLinkedListElem_t<Texture_t,int> >::Iterator_t v16; // [esp+1Ch] [ebp-8h] BYREF

  result = (CUtlFixedMemory<UtlLinkedListElem_t<Texture_t,int> >::BlockHeader_t *)this->m_FirstFree;
  if ( result != nullptr )
  {
    this->m_FirstFree = result[11].m_nBlockSize;
LABEL_33:
    if ( multilist )
    {
      result[11].m_nBlockSize = 0;
      result[11].m_pNext = nullptr;
    }
    else
    {
      result[11].m_nBlockSize = (int)result;
      result[11].m_pNext = result;
    }
    return result;
  }
  m_pBlockHeader = this->m_LastAlloc.m_pBlockHeader;
  p_m_LastAlloc = &this->m_LastAlloc;
  if ( m_pBlockHeader != nullptr
    && (m_nIndex = this->m_LastAlloc.m_nIndex) >= 0
    && m_nIndex < m_pBlockHeader->m_nBlockSize )
  {
    v7 = CUtlFixedMemory<UtlLinkedListElem_t<CShaderDeviceDx10::GeometryShader_t,int>>::Next(
           this: &this->m_Memory,
           result: &v15,
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
    v7 = &v15;
  }
  v8 = v7->m_pBlockHeader;
  v9 = v7->m_pBlockHeader == nullptr;
  v10 = v7->m_nIndex;
  if ( v9 || v10 < 0 || v10 >= v8->m_nBlockSize )
  {
    CUtlFixedMemory<UtlLinkedListElem_t<Texture_t,int>>::Grow(this: &this->m_Memory, num: 1);
    this->m_pElements = nullptr;
    if ( p_m_LastAlloc->m_pBlockHeader != nullptr
      && (v11 = this->m_LastAlloc.m_nIndex) >= 0
      && v11 < p_m_LastAlloc->m_pBlockHeader->m_nBlockSize )
    {
      v12 = (CUtlFixedMemory<UtlLinkedListElem_t<IDirect3DVertexShader9 *,int> >::Iterator_t *)CUtlFixedMemory<UtlLinkedListElem_t<CShaderDeviceDx10::GeometryShader_t,int>>::Next(
                                                                                                 this: &this->m_Memory,
                                                                                                 result: &v14,
                                                                                                 it: &this->m_LastAlloc);
    }
    else
    {
      v12 = CUtlFixedMemory<UtlLinkedListElem_t<CShaderManager::ShaderLookup_t,int>>::First(
              this: &this->m_Memory,
              result: (CUtlFixedMemory<UtlLinkedListElem_t<IDirect3DVertexShader9 *,int> >::Iterator_t *)&v16);
    }
    v8 = (CUtlFixedMemory<UtlLinkedListElem_t<Texture_t,int> >::BlockHeader_t *)v12->m_pBlockHeader;
    v9 = v12->m_pBlockHeader == nullptr;
    v10 = v12->m_nIndex;
    if ( v9 || v10 < 0 || v10 >= v8->m_nBlockSize )
    {
      if ( _executeCount_0 < 10 )
      {
        ++_executeCount_0;
        _Warning(a1: "CUtlLinkedList overflow! (exhausted memory allocator)\n");
      }
      return nullptr;
    }
  }
  if ( &v8[12 * v10] != (CUtlFixedMemory<UtlLinkedListElem_t<Texture_t,int> >::BlockHeader_t *)-8 )
  {
    this->m_LastAlloc.m_nIndex = v10;
    p_m_LastAlloc->m_pBlockHeader = v8;
    if ( v8 != nullptr && (v13 = this->m_LastAlloc.m_nIndex) >= 0 && v13 < v8->m_nBlockSize )
    {
      ++this->m_NumAlloced;
      result = &v8[12 * v13 + 1];
    }
    else
    {
      result = nullptr;
      ++this->m_NumAlloced;
    }
    goto LABEL_33;
  }
  if ( _executeCount >= 10 )
    return nullptr;
  ++_executeCount;
  _Warning(a1: "CUtlLinkedList overflow! (exhausted index range)\n");
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10025B50
// Name: public: void CUtlLinkedList<struct Texture_t,int,1,int,class CUtlFixedMemory<struct UtlLinkedListElem_t<struct Texture_t,int>>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<Texture_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<Texture_t,int>>>::RemoveAll(
        CUtlLinkedList<Texture_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<Texture_t,int> > > *this)
{
  CUtlFixedMemory<UtlLinkedListElem_t<Texture_t,int> >::Iterator_t *i; // eax
  CUtlFixedMemory<UtlLinkedListElem_t<Texture_t,int> >::BlockHeader_t *m_pBlockHeader; // ebx
  bool v4; // zf
  int m_nIndex; // edi
  CUtlFixedMemory<UtlLinkedListElem_t<Texture_t,int> >::Iterator_t it; // [esp+10h] [ebp-10h] BYREF
  CUtlFixedMemory<UtlLinkedListElem_t<Texture_t,int> >::Iterator_t result; // [esp+18h] [ebp-8h] BYREF

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
          i = CUtlFixedMemory<UtlLinkedListElem_t<CShaderDeviceDx10::GeometryShader_t,int>>::Next(
                this: &this->m_Memory,
                &result,
                &it) )
    {
      m_pBlockHeader = i->m_pBlockHeader;
      v4 = i->m_pBlockHeader == nullptr;
      m_nIndex = i->m_nIndex;
      it.m_nIndex = m_nIndex;
      it.m_pBlockHeader = m_pBlockHeader;
      if ( v4 )
      {
        if ( m_nIndex == -1 )
          break;
      }
      else if ( m_nIndex >= 0
             && m_nIndex < m_pBlockHeader->m_nBlockSize
             && &m_pBlockHeader[12 * m_nIndex] != (CUtlFixedMemory<UtlLinkedListElem_t<Texture_t,int> >::BlockHeader_t *)-8
             && !CUtlFixedMemory<UtlLinkedListElem_t<Texture_t,int>>::IsIdxAfter(
                   this: &this->m_Memory,
                   i: (unsigned int)&m_pBlockHeader[12 * m_nIndex + 1],
                   it: &this->m_LastAlloc)
             && (m_pBlockHeader[12 * m_nIndex + 12].m_pNext != &m_pBlockHeader[12 * m_nIndex + 1]
              || (CUtlFixedMemory<UtlLinkedListElem_t<Texture_t,int> >::BlockHeader_t *)m_pBlockHeader[12 * m_nIndex + 12].m_nBlockSize == &m_pBlockHeader[12 * m_nIndex + 1]) )
      {
        m_pBlockHeader[12 * m_nIndex + 12].m_pNext = &m_pBlockHeader[12 * m_nIndex + 1];
        m_pBlockHeader[12 * m_nIndex + 12].m_nBlockSize = this->m_FirstFree;
        this->m_FirstFree = (int)&m_pBlockHeader[12 * m_nIndex + 1];
      }
      if ( m_pBlockHeader == this->m_LastAlloc.m_pBlockHeader && m_nIndex == this->m_LastAlloc.m_nIndex )
        break;
    }
    this->m_Head = 0;
    this->m_Tail = 0;
    this->m_ElementCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10026000
// Name: public: void CUtlLinkedList<struct Texture_t,int,1,int,class CUtlFixedMemory<struct UtlLinkedListElem_t<struct Texture_t,int>>>::Purge(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<Texture_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<Texture_t,int>>>::Purge(
        CUtlLinkedList<Texture_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<Texture_t,int> > > *this)
{
  CUtlFixedMemory<UtlLinkedListElem_t<Texture_t,int> >::BlockHeader_t *m_pBlocks; // esi
  CUtlFixedMemory<UtlLinkedListElem_t<Texture_t,int> >::BlockHeader_t *v3; // eax

  CUtlLinkedList<Texture_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<Texture_t,int>>>::RemoveAll(this);
  m_pBlocks = this->m_Memory.m_pBlocks;
  if ( this->m_Memory.m_pBlocks != nullptr )
  {
    do
    {
      v3 = m_pBlocks;
      m_pBlocks = m_pBlocks->m_pNext;
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v3);
    }
    while ( m_pBlocks != nullptr );
    this->m_Memory.m_pBlocks = nullptr;
    this->m_Memory.m_nAllocationCount = 0;
  }
  this->m_FirstFree = 0;
  this->m_NumAlloced = 0;
  this->m_pElements = nullptr;
  this->m_LastAlloc.m_pBlockHeader = nullptr;
  this->m_LastAlloc.m_nIndex = -1;
}

//------------------------------------------------------------------------------
// Address: 0x10028280
// Name: public: void CUtlMemory<struct ShaderDisplayMode_t,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<ShaderDisplayMode_t,int>::Grow(CUtlMemory<ShaderDisplayMode_t,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  ShaderDisplayMode_t *m_pMemory; // edx
  unsigned int v7; // [esp-4h] [ebp-Ch]

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
    v7 = 24 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (ShaderDisplayMode_t *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (ShaderDisplayMode_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10028720
// Name: public: void CUtlMemory<void (*)(struct ID3D10Device __near *,struct ShaderStateDx10_t const __near &,struct ShaderStateDx10_t __near &,bool),int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<void (__cdecl *)(ID3D10Device *,ShaderStateDx10_t const &,ShaderStateDx10_t &,bool),int>::Grow(
        CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  CUtlSymbolTable::StringPool_t **m_pMemory; // edx
  unsigned int v7; // [esp-4h] [ebp-Ch]

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
        m_nAllocationCount = 8;
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
    v7 = 4 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (CUtlSymbolTable::StringPool_t **)_g_pMemAlloc->Realloc_2(
                                                            this: _g_pMemAlloc,
                                                            a2: m_pMemory,
                                                            a3: v7);
    else
      this->m_pMemory = (CUtlSymbolTable::StringPool_t **)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100289A0
// Name: public: bool CUtlVector<void (*)(void),class CUtlMemory<void (*)(void),int>>::FindAndRemove(void (*const __near &)(void))
// Source: json
//------------------------------------------------------------------------------
char __thiscall CUtlVector<void (__cdecl *)(void),CUtlMemory<void (__cdecl *)(void),int>>::FindAndRemove(
        CUtlVector<IShaderDeviceDependentObject *,CUtlMemory<IShaderDeviceDependentObject *,int> > *this,
        IShaderDeviceDependentObject **src)
{
  int m_Size; // edx
  int v4; // eax
  IShaderDeviceDependentObject **m_pMemory; // ebx
  IShaderDeviceDependentObject **i; // ecx
  int v8; // edx

  m_Size = this->m_Size;
  v4 = 0;
  if ( m_Size <= 0 )
    return 0;
  m_pMemory = this->m_Memory.m_pMemory;
  for ( i = this->m_Memory.m_pMemory; *i != *src; ++i )
  {
    if ( ++v4 >= m_Size )
      return 0;
  }
  if ( v4 == -1 )
    return 0;
  v8 = m_Size - v4 - 1;
  if ( v8 > 0 )
    _V_memmove(dest: &m_pMemory[v4], src: &m_pMemory[v4 + 1], count: 4 * v8);
  --this->m_Size;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10028A00
// Name: public: int CUtlVector<void (*)(class D3DDeviceWrapper __near *,struct DynamicState_t const __near &,struct DynamicState_t __near &,bool),class CUtlMemory<void (*)(class D3DDeviceWrapper __near *,struct DynamicState_t const __near &,struct DynamicState_t __near &,bool),int>>::InsertBefore(int,void (*const __near &)(class D3DDeviceWrapper __near *,struct DynamicState_t const __near &,struct DynamicState_t __near &,bool))
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<void (__cdecl *)(D3DDeviceWrapper *,DynamicState_t const &,DynamicState_t &,bool),CUtlMemory<void (__cdecl *)(D3DDeviceWrapper *,DynamicState_t const &,DynamicState_t &,bool),int>>::InsertBefore(
        CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *this,
        int elem,
        CUtlSymbolTable::StringPool_t **src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CUtlSymbolTable::StringPool_t **m_pMemory; // ecx
  int v7; // eax
  bool v8; // zf
  CUtlSymbolTable::StringPool_t **v9; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<void (__cdecl *)(ID3D10Device *,ShaderStateDx10_t const &,ShaderStateDx10_t &,bool),int>::Grow(
      this: &this->m_Memory,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  v8 = this->m_Size - elem == 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 >= 0 && !v8 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 4 * v7);
  v9 = &this->m_Memory.m_pMemory[elem];
  if ( v9 != nullptr )
    *v9 = *src;
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x10028A70
// Name: public: int CUtlVector<struct ShaderDisplayMode_t,class CUtlMemory<struct ShaderDisplayMode_t,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<ShaderDisplayMode_t,CUtlMemory<ShaderDisplayMode_t,int>>::InsertMultipleBefore(
        CUtlVector<ShaderDisplayMode_t,CUtlMemory<ShaderDisplayMode_t,int> > *this,
        int elem,
        int num)
{
  int v3; // edi
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  ShaderDisplayMode_t *m_pMemory; // ecx
  int v9; // eax
  int v10; // ecx
  ShaderDisplayMode_t *v11; // eax

  v3 = num;
  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<ShaderDisplayMode_t,int>::Grow(this: &this->m_Memory, num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v9 = this->m_Size - elem - num;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v9 <= 0 )
    goto LABEL_8;
  if ( num > 0 )
  {
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 24 * v9);
LABEL_8:
    if ( num > 0 )
    {
      v10 = elem;
      do
      {
        v11 = &this->m_Memory.m_pMemory[v10];
        if ( v11 != nullptr )
        {
          *(_QWORD *)&v11->m_nVersion = 0;
          *(_QWORD *)&v11->m_nHeight = 0;
          *(_QWORD *)&v11->m_nRefreshRateNumerator = 0;
          v11->m_nVersion = 1;
        }
        ++v10;
        --v3;
      }
      while ( v3 != 0 );
    }
  }
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x100299B0
// Name: public: virtual void const __near * CShaderBuffer<struct ID3DXBuffer>::GetBits(void)const
// Source: json
//------------------------------------------------------------------------------
void *__thiscall CShaderBuffer<ID3DXBuffer>::GetBits(CShaderBuffer<ID3D10Blob> *this)
{
  if ( this->m_pBlob != nullptr )
    return this->m_pBlob->GetBufferPointer(this: this->m_pBlob);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x100299D0
// Name: public: virtual void CShaderBuffer<struct ID3D10Blob>::Release(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderBuffer<ID3D10Blob>::Release(CShaderBuffer<ID3D10Blob> *this)
{
  if ( this->m_pBlob != nullptr )
    this->m_pBlob->Release(this: this->m_pBlob);
  free(pMem: this);
}

//------------------------------------------------------------------------------
// Address: 0x100299F0
// Name: public: void CUtlFixedMemory<struct UtlLinkedListElem_t<struct CShaderDeviceDx10::GeometryShader_t,int>>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlFixedMemory<UtlLinkedListElem_t<CShaderDeviceDx10::GeometryShader_t,int>>::Grow(
        CUtlFixedMemory<UtlLinkedListElem_t<CShaderDeviceDx10::PixelShader_t,int> > *this,
        int num)
{
  int m_nGrowSize; // esi
  CUtlFixedMemory<UtlLinkedListElem_t<CShaderDeviceDx10::PixelShader_t,int> >::BlockHeader_t *v4; // ebx
  CUtlFixedMemory<UtlLinkedListElem_t<CShaderDeviceDx10::PixelShader_t,int> >::BlockHeader_t *m_pBlocks; // eax
  bool v6; // zf

  if ( num > 0 )
  {
    m_nGrowSize = this->m_nGrowSize;
    if ( m_nGrowSize == 0 )
    {
      m_nGrowSize = this->m_nAllocationCount;
      if ( m_nGrowSize == 0 )
        m_nGrowSize = 2;
    }
    if ( m_nGrowSize < num )
      m_nGrowSize *= (m_nGrowSize + num - 1) / m_nGrowSize;
    this->m_nAllocationCount += m_nGrowSize;
    v4 = (CUtlFixedMemory<UtlLinkedListElem_t<CShaderDeviceDx10::PixelShader_t,int> >::BlockHeader_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 16 * m_nGrowSize + 8);
    if ( v4 == nullptr )
      _Error(a1: "CUtlFixedMemory overflow!\n");
    m_pBlocks = this->m_pBlocks;
    v6 = this->m_pBlocks == nullptr;
    v4->m_pNext = nullptr;
    v4->m_nBlockSize = m_nGrowSize;
    if ( v6 )
    {
      this->m_pBlocks = v4;
    }
    else
    {
      for ( ; m_pBlocks->m_pNext != nullptr; m_pBlocks = m_pBlocks->m_pNext )
        ;
      m_pBlocks->m_pNext = v4;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10029BC0
// Name: public: void CUtlFixedMemory<struct UtlLinkedListElem_t<struct CShaderDeviceDx10::PixelShader_t,int>>::Init(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlFixedMemory<UtlLinkedListElem_t<CShaderDeviceDx10::PixelShader_t,int>>::Init(
        CUtlFixedMemory<UtlLinkedListElem_t<CShaderDeviceDx10::PixelShader_t,int> > *this,
        int nGrowSize,
        int nInitSize)
{
  CUtlFixedMemory<UtlLinkedListElem_t<CShaderDeviceDx10::PixelShader_t,int> >::BlockHeader_t *m_pBlocks; // esi
  CUtlFixedMemory<UtlLinkedListElem_t<CShaderDeviceDx10::PixelShader_t,int> >::BlockHeader_t *v5; // eax

  m_pBlocks = this->m_pBlocks;
  if ( this->m_pBlocks != nullptr )
  {
    do
    {
      v5 = m_pBlocks;
      m_pBlocks = m_pBlocks->m_pNext;
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v5);
    }
    while ( m_pBlocks != nullptr );
    this->m_pBlocks = nullptr;
    this->m_nAllocationCount = 0;
  }
  this->m_nGrowSize = nGrowSize;
  CUtlFixedMemory<UtlLinkedListElem_t<CShaderDeviceDx10::GeometryShader_t,int>>::Grow(this, num: nInitSize);
}

//------------------------------------------------------------------------------
// Address: 0x10029C10
// Name: public: bool CUtlFixedMemory<struct UtlLinkedListElem_t<struct CShaderDeviceDx10::VertexShader_t,int>>::IsIdxAfter(int,class CUtlFixedMemory<struct UtlLinkedListElem_t<struct CShaderDeviceDx10::VertexShader_t,int>>::Iterator_t const __near &)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CUtlFixedMemory<UtlLinkedListElem_t<CShaderDeviceDx10::VertexShader_t,int>>::IsIdxAfter(
        CUtlFixedMemory<UtlLinkedListElem_t<CShaderDeviceDx10::VertexShader_t,int> > *this,
        unsigned int i,
        const CUtlFixedMemory<UtlLinkedListElem_t<CShaderDeviceDx10::VertexShader_t,int> >::Iterator_t *it)
{
  CUtlFixedMemory<UtlLinkedListElem_t<CShaderDeviceDx10::VertexShader_t,int> >::BlockHeader_t *m_pBlockHeader; // eax
  int m_nIndex; // edx
  CUtlFixedMemory<UtlLinkedListElem_t<CShaderDeviceDx10::VertexShader_t,int> >::BlockHeader_t *m_pNext; // eax

  m_pBlockHeader = it->m_pBlockHeader;
  if ( it->m_pBlockHeader == nullptr )
    return false;
  m_nIndex = it->m_nIndex;
  if ( m_nIndex < 0 || m_nIndex >= m_pBlockHeader->m_nBlockSize )
    return false;
  if ( i >= (unsigned int)&m_pBlockHeader[1] && i < (unsigned int)&m_pBlockHeader[1] + 52 * m_pBlockHeader->m_nBlockSize )
    return (int)i > (int)&m_pBlockHeader[1] + 52 * m_nIndex;
  m_pNext = m_pBlockHeader->m_pNext;
  if ( m_pNext == nullptr )
    return false;
  while ( i < (unsigned int)&m_pNext[1] || i >= (unsigned int)&m_pNext[1] + 52 * m_pNext->m_nBlockSize )
  {
    m_pNext = m_pNext->m_pNext;
    if ( m_pNext == nullptr )
      return false;
  }
  return true;
}

//------------------------------------------------------------------------------
// Address: 0x10029C90
// Name: public: bool CUtlFixedMemory<struct UtlLinkedListElem_t<struct CShaderDeviceDx10::GeometryShader_t,int>>::IsIdxAfter(int,class CUtlFixedMemory<struct UtlLinkedListElem_t<struct CShaderDeviceDx10::GeometryShader_t,int>>::Iterator_t const __near &)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CUtlFixedMemory<UtlLinkedListElem_t<CShaderDeviceDx10::GeometryShader_t,int>>::IsIdxAfter(
        CUtlFixedMemory<UtlLinkedListElem_t<CShaderDeviceDx10::PixelShader_t,int> > *this,
        unsigned int i,
        const CUtlFixedMemory<UtlLinkedListElem_t<CShaderDeviceDx10::PixelShader_t,int> >::Iterator_t *it)
{
  CUtlFixedMemory<UtlLinkedListElem_t<CShaderDeviceDx10::PixelShader_t,int> >::BlockHeader_t *m_pBlockHeader; // eax
  int m_nIndex; // edx
  CUtlFixedMemory<UtlLinkedListElem_t<CShaderDeviceDx10::PixelShader_t,int> >::BlockHeader_t *m_pNext; // eax

  m_pBlockHeader = it->m_pBlockHeader;
  if ( it->m_pBlockHeader == nullptr )
    return false;
  m_nIndex = it->m_nIndex;
  if ( m_nIndex < 0 || m_nIndex >= m_pBlockHeader->m_nBlockSize )
    return false;
  if ( i >= (unsigned int)&m_pBlockHeader[1] && i < (unsigned int)&m_pBlockHeader[2 * m_pBlockHeader->m_nBlockSize + 1] )
    return (int)i > (int)&m_pBlockHeader[2 * m_nIndex + 1];
  m_pNext = m_pBlockHeader->m_pNext;
  if ( m_pNext == nullptr )
    return false;
  while ( i < (unsigned int)&m_pNext[1] || i >= (unsigned int)&m_pNext[2 * m_pNext->m_nBlockSize + 1] )
  {
    m_pNext = m_pNext->m_pNext;
    if ( m_pNext == nullptr )
      return false;
  }
  return true;
}

//------------------------------------------------------------------------------
// Address: 0x1002A1C0
// Name: public: void CUtlLinkedList<struct CShaderManager::ShaderLookup_t,int,1,int,class CUtlFixedMemory<struct UtlLinkedListElem_t<struct CShaderManager::ShaderLookup_t,int>>>::Unlink(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CShaderManager::ShaderLookup_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CShaderManager::ShaderLookup_t,int>>>::Unlink(
        CUtlLinkedList<CShaderDeviceDx10::VertexShader_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CShaderDeviceDx10::VertexShader_t,int> > > *this,
        unsigned int elem)
{
  int v3; // ecx
  int v4; // eax

  if ( elem != 0
    && !CUtlFixedMemory<UtlLinkedListElem_t<CShaderDeviceDx10::VertexShader_t,int>>::IsIdxAfter(
          this: &this->m_Memory,
          i: elem,
          it: &this->m_LastAlloc)
    && *(_DWORD *)(elem + 44) != elem )
  {
    v3 = *(_DWORD *)(elem + 44);
    v4 = *(_DWORD *)(elem + 48);
    if ( v3 != 0 )
      *(_DWORD *)(v3 + 48) = v4;
    else
      this->m_Head = v4;
    if ( v4 != 0 )
    {
      *(_DWORD *)(v4 + 44) = v3;
      --this->m_ElementCount;
    }
    else
    {
      --this->m_ElementCount;
      this->m_Tail = v3;
    }
    *(_DWORD *)(elem + 48) = elem;
    *(_DWORD *)(elem + 44) = elem;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002A220
// Name: protected: int CUtlLinkedList<struct CShaderDeviceDx10::VertexShader_t,int,1,int,class CUtlFixedMemory<struct UtlLinkedListElem_t<struct CShaderDeviceDx10::VertexShader_t,int>>>::AllocInternal(bool)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<CShaderDeviceDx10::VertexShader_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CShaderDeviceDx10::VertexShader_t,int>>>::AllocInternal(
        CUtlLinkedList<CShaderDeviceDx10::VertexShader_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CShaderDeviceDx10::VertexShader_t,int> > > *this,
        bool multilist)
{
  int result; // eax
  CUtlFixedMemory<UtlLinkedListElem_t<CShaderDeviceDx10::VertexShader_t,int> >::BlockHeader_t *m_pBlockHeader; // eax
  CUtlFixedMemory<UtlLinkedListElem_t<CShaderDeviceDx10::VertexShader_t,int> >::Iterator_t *p_m_LastAlloc; // esi
  int m_nIndex; // ecx
  CUtlFixedMemory<UtlLinkedListElem_t<Texture_t,int> >::Iterator_t *v7; // eax
  CUtlFixedMemory<UtlLinkedListElem_t<CShaderDeviceDx10::VertexShader_t,int> >::BlockHeader_t *v8; // ecx
  bool v9; // zf
  int v10; // eax
  int v11; // ecx
  CUtlFixedMemory<UtlLinkedListElem_t<IDirect3DVertexShader9 *,int> >::Iterator_t *v12; // eax
  int v13; // esi
  CUtlFixedMemory<UtlLinkedListElem_t<Texture_t,int> >::Iterator_t v14; // [esp+Ch] [ebp-18h] BYREF
  CUtlFixedMemory<UtlLinkedListElem_t<Texture_t,int> >::Iterator_t v15; // [esp+14h] [ebp-10h] BYREF
  CUtlFixedMemory<UtlLinkedListElem_t<Texture_t,int> >::Iterator_t v16; // [esp+1Ch] [ebp-8h] BYREF

  result = this->m_FirstFree;
  if ( result != 0 )
  {
    this->m_FirstFree = *(_DWORD *)(result + 48);
LABEL_33:
    if ( multilist )
    {
      *(_DWORD *)(result + 48) = 0;
      *(_DWORD *)(result + 44) = 0;
    }
    else
    {
      *(_DWORD *)(result + 48) = result;
      *(_DWORD *)(result + 44) = result;
    }
    return result;
  }
  m_pBlockHeader = this->m_LastAlloc.m_pBlockHeader;
  p_m_LastAlloc = &this->m_LastAlloc;
  if ( m_pBlockHeader != nullptr
    && (m_nIndex = this->m_LastAlloc.m_nIndex) >= 0
    && m_nIndex < m_pBlockHeader->m_nBlockSize )
  {
    v7 = CUtlFixedMemory<UtlLinkedListElem_t<CShaderDeviceDx10::GeometryShader_t,int>>::Next(
           (CUtlFixedMemory<UtlLinkedListElem_t<Texture_t,int> > *)this,
           result: &v15,
           it: (const CUtlFixedMemory<UtlLinkedListElem_t<Texture_t,int> >::Iterator_t *)&this->m_LastAlloc);
  }
  else
  {
    if ( this->m_Memory.m_pBlocks != nullptr )
    {
      v14.m_pBlockHeader = (CUtlFixedMemory<UtlLinkedListElem_t<Texture_t,int> >::BlockHeader_t *)this->m_Memory.m_pBlocks;
      v14.m_nIndex = 0;
    }
    else
    {
      v14.m_pBlockHeader = nullptr;
      v14.m_nIndex = -1;
    }
    v15 = v14;
    v7 = &v15;
  }
  v8 = (CUtlFixedMemory<UtlLinkedListElem_t<CShaderDeviceDx10::VertexShader_t,int> >::BlockHeader_t *)v7->m_pBlockHeader;
  v9 = v7->m_pBlockHeader == nullptr;
  v10 = v7->m_nIndex;
  if ( v9 || v10 < 0 || v10 >= v8->m_nBlockSize )
  {
    CUtlFixedMemory<UtlLinkedListElem_t<CShaderDeviceDx10::VertexShader_t,int>>::Grow(this: &this->m_Memory, num: 1);
    this->m_pElements = nullptr;
    if ( p_m_LastAlloc->m_pBlockHeader != nullptr
      && (v11 = this->m_LastAlloc.m_nIndex) >= 0
      && v11 < p_m_LastAlloc->m_pBlockHeader->m_nBlockSize )
    {
      v12 = (CUtlFixedMemory<UtlLinkedListElem_t<IDirect3DVertexShader9 *,int> >::Iterator_t *)CUtlFixedMemory<UtlLinkedListElem_t<CShaderDeviceDx10::GeometryShader_t,int>>::Next(
                                                                                                 (CUtlFixedMemory<UtlLinkedListElem_t<Texture_t,int> > *)this,
                                                                                                 result: &v14,
                                                                                                 it: (const CUtlFixedMemory<UtlLinkedListElem_t<Texture_t,int> >::Iterator_t *)&this->m_LastAlloc);
    }
    else
    {
      v12 = CUtlFixedMemory<UtlLinkedListElem_t<CShaderManager::ShaderLookup_t,int>>::First(
              (CUtlFixedMemory<UtlLinkedListElem_t<Texture_t,int> > *)this,
              result: (CUtlFixedMemory<UtlLinkedListElem_t<IDirect3DVertexShader9 *,int> >::Iterator_t *)&v16);
    }
    v8 = (CUtlFixedMemory<UtlLinkedListElem_t<CShaderDeviceDx10::VertexShader_t,int> >::BlockHeader_t *)v12->m_pBlockHeader;
    v9 = v12->m_pBlockHeader == nullptr;
    v10 = v12->m_nIndex;
    if ( v9 || v10 < 0 || v10 >= v8->m_nBlockSize )
    {
      if ( _executeCount_2 < 10 )
      {
        ++_executeCount_2;
        _Warning(a1: "CUtlLinkedList overflow! (exhausted memory allocator)\n");
      }
      return 0;
    }
  }
  if ( (CUtlFixedMemory<UtlLinkedListElem_t<CShaderDeviceDx10::VertexShader_t,int> >::BlockHeader_t *)((char *)v8 + 52 * v10) != (CUtlFixedMemory<UtlLinkedListElem_t<CShaderDeviceDx10::VertexShader_t,int> >::BlockHeader_t *)-8 )
  {
    this->m_LastAlloc.m_nIndex = v10;
    p_m_LastAlloc->m_pBlockHeader = v8;
    if ( v8 != nullptr && (v13 = this->m_LastAlloc.m_nIndex) >= 0 && v13 < v8->m_nBlockSize )
    {
      ++this->m_NumAlloced;
      result = (int)&v8[1] + 52 * v13;
    }
    else
    {
      result = 0;
      ++this->m_NumAlloced;
    }
    goto LABEL_33;
  }
  if ( _executeCount_1 >= 10 )
    return 0;
  ++_executeCount_1;
  _Warning(a1: "CUtlLinkedList overflow! (exhausted index range)\n");
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1002A3A0
// Name: protected: int CUtlLinkedList<struct CShaderDeviceDx10::GeometryShader_t,int,1,int,class CUtlFixedMemory<struct UtlLinkedListElem_t<struct CShaderDeviceDx10::GeometryShader_t,int>>>::AllocInternal(bool)
// Source: json
//------------------------------------------------------------------------------
CUtlFixedMemory<UtlLinkedListElem_t<CShaderDeviceDx10::GeometryShader_t,int> >::BlockHeader_t *__thiscall CUtlLinkedList<CShaderDeviceDx10::GeometryShader_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CShaderDeviceDx10::GeometryShader_t,int>>>::AllocInternal(
        CUtlLinkedList<CShaderDeviceDx10::GeometryShader_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CShaderDeviceDx10::GeometryShader_t,int> > > *this,
        bool multilist)
{
  CUtlFixedMemory<UtlLinkedListElem_t<CShaderDeviceDx10::GeometryShader_t,int> >::BlockHeader_t *result; // eax
  CUtlFixedMemory<UtlLinkedListElem_t<CShaderDeviceDx10::GeometryShader_t,int> >::BlockHeader_t *m_pBlockHeader; // eax
  CUtlFixedMemory<UtlLinkedListElem_t<CShaderDeviceDx10::GeometryShader_t,int> >::Iterator_t *p_m_LastAlloc; // esi
  int m_nIndex; // ecx
  CUtlFixedMemory<UtlLinkedListElem_t<Texture_t,int> >::Iterator_t *v7; // eax
  CUtlFixedMemory<UtlLinkedListElem_t<CShaderDeviceDx10::GeometryShader_t,int> >::BlockHeader_t *v8; // ecx
  bool v9; // zf
  int v10; // eax
  int v11; // ecx
  CUtlFixedMemory<UtlLinkedListElem_t<IDirect3DVertexShader9 *,int> >::Iterator_t *v12; // eax
  int v13; // esi
  CUtlFixedMemory<UtlLinkedListElem_t<Texture_t,int> >::Iterator_t v14; // [esp+Ch] [ebp-18h] BYREF
  CUtlFixedMemory<UtlLinkedListElem_t<Texture_t,int> >::Iterator_t v15; // [esp+14h] [ebp-10h] BYREF
  CUtlFixedMemory<UtlLinkedListElem_t<Texture_t,int> >::Iterator_t v16; // [esp+1Ch] [ebp-8h] BYREF

  result = (CUtlFixedMemory<UtlLinkedListElem_t<CShaderDeviceDx10::GeometryShader_t,int> >::BlockHeader_t *)this->m_FirstFree;
  if ( result != nullptr )
  {
    this->m_FirstFree = result[1].m_nBlockSize;
LABEL_33:
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
    v7 = CUtlFixedMemory<UtlLinkedListElem_t<CShaderDeviceDx10::GeometryShader_t,int>>::Next(
           (CUtlFixedMemory<UtlLinkedListElem_t<Texture_t,int> > *)this,
           result: &v15,
           it: (const CUtlFixedMemory<UtlLinkedListElem_t<Texture_t,int> >::Iterator_t *)&this->m_LastAlloc);
  }
  else
  {
    if ( this->m_Memory.m_pBlocks != nullptr )
    {
      v14.m_pBlockHeader = (CUtlFixedMemory<UtlLinkedListElem_t<Texture_t,int> >::BlockHeader_t *)this->m_Memory.m_pBlocks;
      v14.m_nIndex = 0;
    }
    else
    {
      v14.m_pBlockHeader = nullptr;
      v14.m_nIndex = -1;
    }
    v15 = v14;
    v7 = &v15;
  }
  v8 = (CUtlFixedMemory<UtlLinkedListElem_t<CShaderDeviceDx10::GeometryShader_t,int> >::BlockHeader_t *)v7->m_pBlockHeader;
  v9 = v7->m_pBlockHeader == nullptr;
  v10 = v7->m_nIndex;
  if ( v9 || v10 < 0 || v10 >= v8->m_nBlockSize )
  {
    CUtlFixedMemory<UtlLinkedListElem_t<CShaderDeviceDx10::GeometryShader_t,int>>::Grow(
      (CUtlFixedMemory<UtlLinkedListElem_t<CShaderDeviceDx10::PixelShader_t,int> > *)this,
      num: 1);
    this->m_pElements = nullptr;
    if ( p_m_LastAlloc->m_pBlockHeader != nullptr
      && (v11 = this->m_LastAlloc.m_nIndex) >= 0
      && v11 < p_m_LastAlloc->m_pBlockHeader->m_nBlockSize )
    {
      v12 = (CUtlFixedMemory<UtlLinkedListElem_t<IDirect3DVertexShader9 *,int> >::Iterator_t *)CUtlFixedMemory<UtlLinkedListElem_t<CShaderDeviceDx10::GeometryShader_t,int>>::Next(
                                                                                                 (CUtlFixedMemory<UtlLinkedListElem_t<Texture_t,int> > *)this,
                                                                                                 result: &v14,
                                                                                                 it: (const CUtlFixedMemory<UtlLinkedListElem_t<Texture_t,int> >::Iterator_t *)&this->m_LastAlloc);
    }
    else
    {
      v12 = CUtlFixedMemory<UtlLinkedListElem_t<CShaderManager::ShaderLookup_t,int>>::First(
              (CUtlFixedMemory<UtlLinkedListElem_t<Texture_t,int> > *)this,
              result: (CUtlFixedMemory<UtlLinkedListElem_t<IDirect3DVertexShader9 *,int> >::Iterator_t *)&v16);
    }
    v8 = (CUtlFixedMemory<UtlLinkedListElem_t<CShaderDeviceDx10::GeometryShader_t,int> >::BlockHeader_t *)v12->m_pBlockHeader;
    v9 = v12->m_pBlockHeader == nullptr;
    v10 = v12->m_nIndex;
    if ( v9 || v10 < 0 || v10 >= v8->m_nBlockSize )
    {
      if ( _executeCount_4 < 10 )
      {
        ++_executeCount_4;
        _Warning(a1: "CUtlLinkedList overflow! (exhausted memory allocator)\n");
      }
      return nullptr;
    }
  }
  if ( &v8[2 * v10] != (CUtlFixedMemory<UtlLinkedListElem_t<CShaderDeviceDx10::GeometryShader_t,int> >::BlockHeader_t *)-8 )
  {
    this->m_LastAlloc.m_nIndex = v10;
    p_m_LastAlloc->m_pBlockHeader = v8;
    if ( v8 != nullptr && (v13 = this->m_LastAlloc.m_nIndex) >= 0 && v13 < v8->m_nBlockSize )
    {
      ++this->m_NumAlloced;
      result = &v8[2 * v13 + 1];
    }
    else
    {
      result = nullptr;
      ++this->m_NumAlloced;
    }
    goto LABEL_33;
  }
  if ( _executeCount_3 >= 10 )
    return nullptr;
  ++_executeCount_3;
  _Warning(a1: "CUtlLinkedList overflow! (exhausted index range)\n");
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1002A520
// Name: public: void CUtlLinkedList<struct CShaderDeviceDx10::GeometryShader_t,int,1,int,class CUtlFixedMemory<struct UtlLinkedListElem_t<struct CShaderDeviceDx10::GeometryShader_t,int>>>::Unlink(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CShaderDeviceDx10::GeometryShader_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CShaderDeviceDx10::GeometryShader_t,int>>>::Unlink(
        CUtlLinkedList<CShaderDeviceDx10::PixelShader_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CShaderDeviceDx10::PixelShader_t,int> > > *this,
        unsigned int elem)
{
  int v3; // ecx
  int v4; // eax

  if ( elem != 0
    && !CUtlFixedMemory<UtlLinkedListElem_t<CShaderDeviceDx10::GeometryShader_t,int>>::IsIdxAfter(
          this: &this->m_Memory,
          i: elem,
          it: &this->m_LastAlloc)
    && *(_DWORD *)(elem + 8) != elem )
  {
    v3 = *(_DWORD *)(elem + 8);
    v4 = *(_DWORD *)(elem + 12);
    if ( v3 != 0 )
      *(_DWORD *)(v3 + 12) = v4;
    else
      this->m_Head = v4;
    if ( v4 != 0 )
    {
      *(_DWORD *)(v4 + 8) = v3;
      --this->m_ElementCount;
    }
    else
    {
      --this->m_ElementCount;
      this->m_Tail = v3;
    }
    *(_DWORD *)(elem + 12) = elem;
    *(_DWORD *)(elem + 8) = elem;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002A580
// Name: protected: int CUtlLinkedList<struct CShaderDeviceDx10::PixelShader_t,int,1,int,class CUtlFixedMemory<struct UtlLinkedListElem_t<struct CShaderDeviceDx10::PixelShader_t,int>>>::AllocInternal(bool)
// Source: json
//------------------------------------------------------------------------------
CUtlFixedMemory<UtlLinkedListElem_t<CShaderDeviceDx10::PixelShader_t,int> >::BlockHeader_t *__thiscall CUtlLinkedList<CShaderDeviceDx10::PixelShader_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CShaderDeviceDx10::PixelShader_t,int>>>::AllocInternal(
        CUtlLinkedList<CShaderDeviceDx10::PixelShader_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CShaderDeviceDx10::PixelShader_t,int> > > *this,
        bool multilist)
{
  CUtlFixedMemory<UtlLinkedListElem_t<CShaderDeviceDx10::PixelShader_t,int> >::BlockHeader_t *result; // eax
  CUtlFixedMemory<UtlLinkedListElem_t<CShaderDeviceDx10::PixelShader_t,int> >::BlockHeader_t *m_pBlockHeader; // eax
  CUtlFixedMemory<UtlLinkedListElem_t<CShaderDeviceDx10::PixelShader_t,int> >::Iterator_t *p_m_LastAlloc; // esi
  int m_nIndex; // ecx
  CUtlFixedMemory<UtlLinkedListElem_t<Texture_t,int> >::Iterator_t *v7; // eax
  CUtlFixedMemory<UtlLinkedListElem_t<CShaderDeviceDx10::PixelShader_t,int> >::BlockHeader_t *v8; // ecx
  bool v9; // zf
  int v10; // eax
  int v11; // ecx
  CUtlFixedMemory<UtlLinkedListElem_t<IDirect3DVertexShader9 *,int> >::Iterator_t *v12; // eax
  int v13; // esi
  CUtlFixedMemory<UtlLinkedListElem_t<Texture_t,int> >::Iterator_t v14; // [esp+Ch] [ebp-18h] BYREF
  CUtlFixedMemory<UtlLinkedListElem_t<Texture_t,int> >::Iterator_t v15; // [esp+14h] [ebp-10h] BYREF
  CUtlFixedMemory<UtlLinkedListElem_t<Texture_t,int> >::Iterator_t v16; // [esp+1Ch] [ebp-8h] BYREF

  result = (CUtlFixedMemory<UtlLinkedListElem_t<CShaderDeviceDx10::PixelShader_t,int> >::BlockHeader_t *)this->m_FirstFree;
  if ( result != nullptr )
  {
    this->m_FirstFree = result[1].m_nBlockSize;
LABEL_33:
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
    v7 = CUtlFixedMemory<UtlLinkedListElem_t<CShaderDeviceDx10::GeometryShader_t,int>>::Next(
           (CUtlFixedMemory<UtlLinkedListElem_t<Texture_t,int> > *)this,
           result: &v15,
           it: (const CUtlFixedMemory<UtlLinkedListElem_t<Texture_t,int> >::Iterator_t *)&this->m_LastAlloc);
  }
  else
  {
    if ( this->m_Memory.m_pBlocks != nullptr )
    {
      v14.m_pBlockHeader = (CUtlFixedMemory<UtlLinkedListElem_t<Texture_t,int> >::BlockHeader_t *)this->m_Memory.m_pBlocks;
      v14.m_nIndex = 0;
    }
    else
    {
      v14.m_pBlockHeader = nullptr;
      v14.m_nIndex = -1;
    }
    v15 = v14;
    v7 = &v15;
  }
  v8 = (CUtlFixedMemory<UtlLinkedListElem_t<CShaderDeviceDx10::PixelShader_t,int> >::BlockHeader_t *)v7->m_pBlockHeader;
  v9 = v7->m_pBlockHeader == nullptr;
  v10 = v7->m_nIndex;
  if ( v9 || v10 < 0 || v10 >= v8->m_nBlockSize )
  {
    CUtlFixedMemory<UtlLinkedListElem_t<CShaderDeviceDx10::GeometryShader_t,int>>::Grow(this: &this->m_Memory, num: 1);
    this->m_pElements = nullptr;
    if ( p_m_LastAlloc->m_pBlockHeader != nullptr
      && (v11 = this->m_LastAlloc.m_nIndex) >= 0
      && v11 < p_m_LastAlloc->m_pBlockHeader->m_nBlockSize )
    {
      v12 = (CUtlFixedMemory<UtlLinkedListElem_t<IDirect3DVertexShader9 *,int> >::Iterator_t *)CUtlFixedMemory<UtlLinkedListElem_t<CShaderDeviceDx10::GeometryShader_t,int>>::Next(
                                                                                                 (CUtlFixedMemory<UtlLinkedListElem_t<Texture_t,int> > *)this,
                                                                                                 result: &v14,
                                                                                                 it: (const CUtlFixedMemory<UtlLinkedListElem_t<Texture_t,int> >::Iterator_t *)&this->m_LastAlloc);
    }
    else
    {
      v12 = CUtlFixedMemory<UtlLinkedListElem_t<CShaderManager::ShaderLookup_t,int>>::First(
              (CUtlFixedMemory<UtlLinkedListElem_t<Texture_t,int> > *)this,
              result: (CUtlFixedMemory<UtlLinkedListElem_t<IDirect3DVertexShader9 *,int> >::Iterator_t *)&v16);
    }
    v8 = (CUtlFixedMemory<UtlLinkedListElem_t<CShaderDeviceDx10::PixelShader_t,int> >::BlockHeader_t *)v12->m_pBlockHeader;
    v9 = v12->m_pBlockHeader == nullptr;
    v10 = v12->m_nIndex;
    if ( v9 || v10 < 0 || v10 >= v8->m_nBlockSize )
    {
      if ( _executeCount_6 < 10 )
      {
        ++_executeCount_6;
        _Warning(a1: "CUtlLinkedList overflow! (exhausted memory allocator)\n");
      }
      return nullptr;
    }
  }
  if ( &v8[2 * v10] != (CUtlFixedMemory<UtlLinkedListElem_t<CShaderDeviceDx10::PixelShader_t,int> >::BlockHeader_t *)-8 )
  {
    this->m_LastAlloc.m_nIndex = v10;
    p_m_LastAlloc->m_pBlockHeader = v8;
    if ( v8 != nullptr && (v13 = this->m_LastAlloc.m_nIndex) >= 0 && v13 < v8->m_nBlockSize )
    {
      ++this->m_NumAlloced;
      result = &v8[2 * v13 + 1];
    }
    else
    {
      result = nullptr;
      ++this->m_NumAlloced;
    }
    goto LABEL_33;
  }
  if ( _executeCount_5 >= 10 )
    return nullptr;
  ++_executeCount_5;
  _Warning(a1: "CUtlLinkedList overflow! (exhausted index range)\n");
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1002AC90
// Name: public: void CUtlLinkedList<struct CShaderDeviceDx10::GeometryShader_t,int,1,int,class CUtlFixedMemory<struct UtlLinkedListElem_t<struct CShaderDeviceDx10::GeometryShader_t,int>>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CShaderDeviceDx10::GeometryShader_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CShaderDeviceDx10::GeometryShader_t,int>>>::RemoveAll(
        CUtlLinkedList<CShaderDeviceDx10::PixelShader_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CShaderDeviceDx10::PixelShader_t,int> > > *this)
{
  CUtlFixedMemory<UtlLinkedListElem_t<Texture_t,int> >::Iterator_t *i; // eax
  CUtlFixedMemory<UtlLinkedListElem_t<CShaderDeviceDx10::PixelShader_t,int> >::BlockHeader_t *m_pBlockHeader; // edi
  bool v4; // zf
  int m_nIndex; // ebx
  CUtlFixedMemory<UtlLinkedListElem_t<CShaderDeviceDx10::PixelShader_t,int> >::Iterator_t it; // [esp+10h] [ebp-10h] BYREF
  CUtlFixedMemory<UtlLinkedListElem_t<Texture_t,int> >::Iterator_t result; // [esp+18h] [ebp-8h] BYREF

  if ( this->m_LastAlloc.m_pBlockHeader != nullptr || this->m_LastAlloc.m_nIndex != -1 )
  {
    if ( this->m_Memory.m_pBlocks != nullptr )
    {
      result.m_pBlockHeader = (CUtlFixedMemory<UtlLinkedListElem_t<Texture_t,int> >::BlockHeader_t *)this->m_Memory.m_pBlocks;
      result.m_nIndex = 0;
    }
    else
    {
      result.m_pBlockHeader = nullptr;
      result.m_nIndex = -1;
    }
    for ( i = &result;
          ;
          i = CUtlFixedMemory<UtlLinkedListElem_t<CShaderDeviceDx10::GeometryShader_t,int>>::Next(
                (CUtlFixedMemory<UtlLinkedListElem_t<Texture_t,int> > *)this,
                &result,
                (const CUtlFixedMemory<UtlLinkedListElem_t<Texture_t,int> >::Iterator_t *)&it) )
    {
      m_pBlockHeader = (CUtlFixedMemory<UtlLinkedListElem_t<CShaderDeviceDx10::PixelShader_t,int> >::BlockHeader_t *)i->m_pBlockHeader;
      v4 = i->m_pBlockHeader == nullptr;
      m_nIndex = i->m_nIndex;
      it.m_nIndex = m_nIndex;
      it.m_pBlockHeader = m_pBlockHeader;
      if ( v4 )
      {
        if ( m_nIndex == -1 )
          break;
      }
      else if ( m_nIndex >= 0
             && m_nIndex < m_pBlockHeader->m_nBlockSize
             && &m_pBlockHeader[2 * m_nIndex] != (CUtlFixedMemory<UtlLinkedListElem_t<CShaderDeviceDx10::PixelShader_t,int> >::BlockHeader_t *)-8
             && !CUtlFixedMemory<UtlLinkedListElem_t<CShaderDeviceDx10::GeometryShader_t,int>>::IsIdxAfter(
                   this: &this->m_Memory,
                   i: (unsigned int)&m_pBlockHeader[2 * m_nIndex + 1],
                   it: &this->m_LastAlloc)
             && (m_pBlockHeader[2 * m_nIndex + 2].m_pNext != &m_pBlockHeader[2 * m_nIndex + 1]
              || (CUtlFixedMemory<UtlLinkedListElem_t<CShaderDeviceDx10::PixelShader_t,int> >::BlockHeader_t *)m_pBlockHeader[2 * m_nIndex + 2].m_nBlockSize == &m_pBlockHeader[2 * m_nIndex + 1]) )
      {
        m_pBlockHeader[2 * m_nIndex + 2].m_pNext = &m_pBlockHeader[2 * m_nIndex + 1];
        m_pBlockHeader[2 * m_nIndex + 2].m_nBlockSize = this->m_FirstFree;
        this->m_FirstFree = (int)&m_pBlockHeader[2 * m_nIndex + 1];
      }
      if ( m_pBlockHeader == this->m_LastAlloc.m_pBlockHeader && m_nIndex == this->m_LastAlloc.m_nIndex )
        break;
    }
    this->m_Head = 0;
    this->m_Tail = 0;
    this->m_ElementCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002B570
// Name: public: int CUtlLinkedList<struct CShaderDeviceDx10::GeometryShader_t,int,1,int,class CUtlFixedMemory<struct UtlLinkedListElem_t<struct CShaderDeviceDx10::GeometryShader_t,int>>>::AddToTail(void)
// Source: json
//------------------------------------------------------------------------------
CUtlFixedMemory<UtlLinkedListElem_t<CShaderDeviceDx10::GeometryShader_t,int> >::BlockHeader_t *__thiscall CUtlLinkedList<CShaderDeviceDx10::GeometryShader_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CShaderDeviceDx10::GeometryShader_t,int>>>::AddToTail(
        CUtlLinkedList<CShaderDeviceDx10::GeometryShader_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CShaderDeviceDx10::GeometryShader_t,int> > > *this)
{
  CUtlFixedMemory<UtlLinkedListElem_t<CShaderDeviceDx10::GeometryShader_t,int> >::BlockHeader_t *result; // eax
  CUtlFixedMemory<UtlLinkedListElem_t<CShaderDeviceDx10::GeometryShader_t,int> >::BlockHeader_t *v3; // esi
  int m_Tail; // eax

  result = CUtlLinkedList<CShaderDeviceDx10::GeometryShader_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CShaderDeviceDx10::GeometryShader_t,int>>>::AllocInternal(
             this,
             multilist: false);
  v3 = result;
  if ( result != nullptr )
  {
    CUtlLinkedList<CShaderDeviceDx10::GeometryShader_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CShaderDeviceDx10::GeometryShader_t,int>>>::Unlink(
      (CUtlLinkedList<CShaderDeviceDx10::PixelShader_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CShaderDeviceDx10::PixelShader_t,int> > > *)this,
      elem: (unsigned int)result);
    v3[1].m_nBlockSize = 0;
    m_Tail = this->m_Tail;
    v3[1].m_pNext = (CUtlFixedMemory<UtlLinkedListElem_t<CShaderDeviceDx10::GeometryShader_t,int> >::BlockHeader_t *)m_Tail;
    this->m_Tail = (int)v3;
    if ( m_Tail != 0 )
    {
      *(_DWORD *)(m_Tail + 12) = v3;
      ++this->m_ElementCount;
    }
    else
    {
      ++this->m_ElementCount;
      this->m_Head = (int)v3;
    }
    return v3;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1002B5C0
// Name: public: int CUtlLinkedList<struct CShaderDeviceDx10::PixelShader_t,int,1,int,class CUtlFixedMemory<struct UtlLinkedListElem_t<struct CShaderDeviceDx10::PixelShader_t,int>>>::AddToTail(void)
// Source: json
//------------------------------------------------------------------------------
CUtlFixedMemory<UtlLinkedListElem_t<CShaderDeviceDx10::PixelShader_t,int> >::BlockHeader_t *__thiscall CUtlLinkedList<CShaderDeviceDx10::PixelShader_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CShaderDeviceDx10::PixelShader_t,int>>>::AddToTail(
        CUtlLinkedList<CShaderDeviceDx10::PixelShader_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CShaderDeviceDx10::PixelShader_t,int> > > *this)
{
  CUtlFixedMemory<UtlLinkedListElem_t<CShaderDeviceDx10::PixelShader_t,int> >::BlockHeader_t *result; // eax
  CUtlFixedMemory<UtlLinkedListElem_t<CShaderDeviceDx10::PixelShader_t,int> >::BlockHeader_t *v3; // esi
  int m_Tail; // eax

  result = CUtlLinkedList<CShaderDeviceDx10::PixelShader_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CShaderDeviceDx10::PixelShader_t,int>>>::AllocInternal(
             this,
             multilist: false);
  v3 = result;
  if ( result != nullptr )
  {
    CUtlLinkedList<CShaderDeviceDx10::GeometryShader_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CShaderDeviceDx10::GeometryShader_t,int>>>::Unlink(
      this,
      elem: (unsigned int)result);
    v3[1].m_nBlockSize = 0;
    m_Tail = this->m_Tail;
    v3[1].m_pNext = (CUtlFixedMemory<UtlLinkedListElem_t<CShaderDeviceDx10::PixelShader_t,int> >::BlockHeader_t *)m_Tail;
    this->m_Tail = (int)v3;
    if ( m_Tail != 0 )
    {
      *(_DWORD *)(m_Tail + 12) = v3;
      ++this->m_ElementCount;
    }
    else
    {
      ++this->m_ElementCount;
      this->m_Head = (int)v3;
    }
    return v3;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1002B9E0
// Name: public: int CUtlLinkedList<struct CShaderDeviceDx10::VertexShader_t,int,1,int,class CUtlFixedMemory<struct UtlLinkedListElem_t<struct CShaderDeviceDx10::VertexShader_t,int>>>::InsertBefore(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<CShaderDeviceDx10::VertexShader_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CShaderDeviceDx10::VertexShader_t,int>>>::InsertBefore(
        CUtlLinkedList<CShaderDeviceDx10::VertexShader_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CShaderDeviceDx10::VertexShader_t,int> > > *this,
        int before)
{
  unsigned int v3; // eax
  int v4; // esi
  int m_Tail; // eax

  v3 = CUtlLinkedList<CShaderDeviceDx10::VertexShader_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CShaderDeviceDx10::VertexShader_t,int>>>::AllocInternal(
         this,
         multilist: false);
  v4 = v3;
  if ( v3 == 0 )
    return 0;
  CUtlLinkedList<CShaderManager::ShaderLookup_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CShaderManager::ShaderLookup_t,int>>>::Unlink(
    this,
    elem: v3);
  *(_DWORD *)(v4 + 48) = before;
  if ( before != 0 )
  {
    m_Tail = *(_DWORD *)(before + 44);
    *(_DWORD *)(v4 + 44) = m_Tail;
    *(_DWORD *)(before + 44) = v4;
  }
  else
  {
    m_Tail = this->m_Tail;
    *(_DWORD *)(v4 + 44) = m_Tail;
    this->m_Tail = v4;
  }
  if ( m_Tail != 0 )
    *(_DWORD *)(m_Tail + 48) = v4;
  else
    this->m_Head = v4;
  ++this->m_ElementCount;
  *(_DWORD *)(v4 + 16) = CShaderDeviceDx10::InputLayoutLessFunc;
  *(_DWORD *)(v4 + 20) = 0;
  *(_DWORD *)(v4 + 24) = 0;
  *(_DWORD *)(v4 + 28) = 0;
  *(_WORD *)(v4 + 32) = -1;
  *(_WORD *)(v4 + 36) = -1;
  *(_WORD *)(v4 + 34) = 0;
  *(_WORD *)(v4 + 38) = -1;
  *(_DWORD *)(v4 + 40) = *(_DWORD *)(v4 + 20);
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x1002BA70
// Name: public: void CUtlLinkedList<struct CShaderDeviceDx10::VertexShader_t,int,1,int,class CUtlFixedMemory<struct UtlLinkedListElem_t<struct CShaderDeviceDx10::VertexShader_t,int>>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CShaderDeviceDx10::VertexShader_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CShaderDeviceDx10::VertexShader_t,int>>>::RemoveAll(
        CUtlLinkedList<CShaderDeviceDx10::VertexShader_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CShaderDeviceDx10::VertexShader_t,int> > > *this)
{
  CUtlFixedMemory<UtlLinkedListElem_t<Texture_t,int> >::Iterator_t *i; // eax
  CUtlFixedMemory<UtlLinkedListElem_t<CShaderDeviceDx10::VertexShader_t,int> >::BlockHeader_t *m_pBlockHeader; // edi
  bool v4; // zf
  int m_nIndex; // ebx
  CUtlFixedMemory<UtlLinkedListElem_t<CShaderDeviceDx10::VertexShader_t,int> >::Iterator_t it; // [esp+10h] [ebp-10h] BYREF
  CUtlFixedMemory<UtlLinkedListElem_t<Texture_t,int> >::Iterator_t result; // [esp+18h] [ebp-8h] BYREF

  if ( this->m_LastAlloc.m_pBlockHeader != nullptr || this->m_LastAlloc.m_nIndex != -1 )
  {
    if ( this->m_Memory.m_pBlocks != nullptr )
    {
      result.m_pBlockHeader = (CUtlFixedMemory<UtlLinkedListElem_t<Texture_t,int> >::BlockHeader_t *)this->m_Memory.m_pBlocks;
      result.m_nIndex = 0;
    }
    else
    {
      result.m_pBlockHeader = nullptr;
      result.m_nIndex = -1;
    }
    for ( i = &result;
          ;
          i = CUtlFixedMemory<UtlLinkedListElem_t<CShaderDeviceDx10::GeometryShader_t,int>>::Next(
                (CUtlFixedMemory<UtlLinkedListElem_t<Texture_t,int> > *)this,
                &result,
                (const CUtlFixedMemory<UtlLinkedListElem_t<Texture_t,int> >::Iterator_t *)&it) )
    {
      m_pBlockHeader = (CUtlFixedMemory<UtlLinkedListElem_t<CShaderDeviceDx10::VertexShader_t,int> >::BlockHeader_t *)i->m_pBlockHeader;
      v4 = i->m_pBlockHeader == nullptr;
      m_nIndex = i->m_nIndex;
      it.m_nIndex = m_nIndex;
      it.m_pBlockHeader = m_pBlockHeader;
      if ( v4 )
      {
        if ( m_nIndex == -1 )
          break;
      }
      else if ( m_nIndex >= 0
             && m_nIndex < m_pBlockHeader->m_nBlockSize
             && (CUtlFixedMemory<UtlLinkedListElem_t<CShaderDeviceDx10::VertexShader_t,int> >::BlockHeader_t *)((char *)m_pBlockHeader + 52 * m_nIndex) != (CUtlFixedMemory<UtlLinkedListElem_t<CShaderDeviceDx10::VertexShader_t,int> >::BlockHeader_t *)-8
             && !CUtlFixedMemory<UtlLinkedListElem_t<CShaderDeviceDx10::VertexShader_t,int>>::IsIdxAfter(
                   this: &this->m_Memory,
                   i: (unsigned int)&m_pBlockHeader[1] + 52 * m_nIndex,
                   it: &this->m_LastAlloc)
             && (*((CUtlFixedMemory<UtlLinkedListElem_t<CShaderDeviceDx10::VertexShader_t,int> >::BlockHeader_t **)&m_pBlockHeader[6].m_nBlockSize
                 + 13 * m_nIndex) != (CUtlFixedMemory<UtlLinkedListElem_t<CShaderDeviceDx10::VertexShader_t,int> >::BlockHeader_t *)((char *)&m_pBlockHeader[1] + 52 * m_nIndex)
              || *(&m_pBlockHeader[7].m_pNext + 13 * m_nIndex) == (CUtlFixedMemory<UtlLinkedListElem_t<CShaderDeviceDx10::VertexShader_t,int> >::BlockHeader_t *)((char *)&m_pBlockHeader[1] + 52 * m_nIndex)) )
      {
        CUtlRBTree<CShaderDeviceDx10::InputLayout_t,unsigned short,bool (__cdecl *)(CShaderDeviceDx10::InputLayout_t const &,CShaderDeviceDx10::InputLayout_t const &),CUtlMemory<UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short>,unsigned short>>::~CUtlRBTree<CShaderDeviceDx10::InputLayout_t,unsigned short,bool (__cdecl *)(CShaderDeviceDx10::InputLayout_t const &,CShaderDeviceDx10::InputLayout_t const &),CUtlMemory<UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short>,unsigned short>>(this: (CUtlRBTree<CShaderDeviceDx10::InputLayout_t,unsigned short,bool (__cdecl*)(CShaderDeviceDx10::InputLayout_t const &,CShaderDeviceDx10::InputLayout_t const &),CUtlMemory<UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short>,unsigned short> > *)((char *)&m_pBlockHeader[3] + 52 * m_nIndex));
        *(&m_pBlockHeader[6].m_nBlockSize + 13 * m_nIndex) = (int)m_pBlockHeader + 52 * m_nIndex + 8;
        *((_DWORD *)&m_pBlockHeader[7].m_pNext + 13 * m_nIndex) = this->m_FirstFree;
        this->m_FirstFree = (int)&m_pBlockHeader[1] + 52 * m_nIndex;
      }
      if ( m_pBlockHeader == this->m_LastAlloc.m_pBlockHeader && m_nIndex == this->m_LastAlloc.m_nIndex )
        break;
    }
    this->m_Head = 0;
    this->m_Tail = 0;
    this->m_ElementCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10031720
// Name: public: void CUtlMemory<struct ShadowState_t,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<ShadowState_t,int>::Grow(CUtlMemory<ShadowState_t,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  ShadowState_t *m_pMemory; // edx
  unsigned int v7; // [esp-4h] [ebp-Ch]

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
        m_nAllocationCount = 1;
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
    v7 = 72 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (ShadowState_t *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (ShadowState_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100317C0
// Name: public: void CUtlMemory<class CUtlVector<struct CTransitionTable::TransitionList_t,class CUtlMemory<struct CTransitionTable::TransitionList_t,int>>,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<CUtlVector<CTransitionTable::TransitionList_t,CUtlMemory<CTransitionTable::TransitionList_t,int>>,int>::Grow(
        CUtlMemory<CUtlVector<CTransitionTable::TransitionList_t,CUtlMemory<CTransitionTable::TransitionList_t,int> >,int> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  CUtlVector<CTransitionTable::TransitionList_t,CUtlMemory<CTransitionTable::TransitionList_t,int> > *m_pMemory; // edx
  unsigned int v7; // [esp-4h] [ebp-Ch]

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
    v7 = 20 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (CUtlVector<CTransitionTable::TransitionList_t,CUtlMemory<CTransitionTable::TransitionList_t,int> > *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (CUtlVector<CTransitionTable::TransitionList_t,CUtlMemory<CTransitionTable::TransitionList_t,int> > *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10032B50
// Name: public: int CUtlVector<struct ShadowState_t,class CUtlMemory<struct ShadowState_t,int>>::InsertBefore(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<ShadowState_t,CUtlMemory<ShadowState_t,int>>::InsertBefore(
        CUtlVector<ShadowState_t,CUtlMemory<ShadowState_t,int> > *this,
        int elem)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  ShadowState_t *m_pMemory; // ecx
  int v6; // eax
  int v7; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<ShadowState_t,int>::Grow(this: &this->m_Memory, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v6 = this->m_Size;
  this->m_pElements = this->m_Memory.m_pMemory;
  v7 = v6 - elem - 1;
  if ( v7 > 0 )
    _V_memmove(dest: (void *)&m_pMemory[elem + 1], src: &m_pMemory[elem], count: 72 * v7);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x10032BB0
// Name: public: int CUtlVector<struct CTransitionTable::SnapshotShaderState_t,class CUtlMemory<struct CTransitionTable::SnapshotShaderState_t,int>>::InsertBefore(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CTransitionTable::SnapshotShaderState_t,CUtlMemory<CTransitionTable::SnapshotShaderState_t,int>>::InsertBefore(
        CUtlVector<CTransitionTable::SnapshotShaderState_t,CUtlMemory<CTransitionTable::SnapshotShaderState_t,int> > *this,
        int elem)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CTransitionTable::SnapshotShaderState_t *m_pMemory; // ecx
  int v6; // eax
  int v7; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CTransitionTable::SnapshotShaderState_t,int>::Grow(
      this: &this->m_Memory,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v6 = this->m_Size;
  this->m_pElements = this->m_Memory.m_pMemory;
  v7 = v6 - elem - 1;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 32 * v7);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x10032CF0
// Name: public: int CUtlVector<class CUtlVector<struct CTransitionTable::TransitionList_t,class CUtlMemory<struct CTransitionTable::TransitionList_t,int>>,class CUtlMemory<class CUtlVector<struct CTransitionTable::TransitionList_t,class CUtlMemory<struct CTransitionTable::TransitionList_t,int>>,int>>::InsertBefore(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CUtlVector<CTransitionTable::TransitionList_t,CUtlMemory<CTransitionTable::TransitionList_t,int>>,CUtlMemory<CUtlVector<CTransitionTable::TransitionList_t,CUtlMemory<CTransitionTable::TransitionList_t,int>>,int>>::InsertBefore(
        CUtlVector<CUtlVector<CTransitionTable::TransitionList_t,CUtlMemory<CTransitionTable::TransitionList_t,int> >,CUtlMemory<CUtlVector<CTransitionTable::TransitionList_t,CUtlMemory<CTransitionTable::TransitionList_t,int> >,int> > *this,
        int elem)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CUtlVector<CTransitionTable::TransitionList_t,CUtlMemory<CTransitionTable::TransitionList_t,int> > *m_pMemory; // ecx
  int v6; // eax
  bool v7; // zf
  CUtlVector<CTransitionTable::TransitionList_t,CUtlMemory<CTransitionTable::TransitionList_t,int> > *v8; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CUtlVector<CTransitionTable::TransitionList_t,CUtlMemory<CTransitionTable::TransitionList_t,int>>,int>::Grow(
      this: &this->m_Memory,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v6 = this->m_Size - elem - 1;
  v7 = this->m_Size - elem == 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v6 >= 0 && !v7 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 20 * v6);
  v8 = &this->m_Memory.m_pMemory[elem];
  if ( v8 != nullptr )
  {
    v8->m_Memory.m_pMemory = nullptr;
    v8->m_Memory.m_nAllocationCount = 0;
    v8->m_Memory.m_nGrowSize = 0;
    v8->m_Size = 0;
    v8->m_pElements = nullptr;
  }
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x10033440
// Name: public: void CUtlVector<class CUtlVector<struct CTransitionTable::TransitionList_t,class CUtlMemory<struct CTransitionTable::TransitionList_t,int>>,class CUtlMemory<class CUtlVector<struct CTransitionTable::TransitionList_t,class CUtlMemory<struct CTransitionTable::TransitionList_t,int>>,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CUtlVector<CTransitionTable::TransitionList_t,CUtlMemory<CTransitionTable::TransitionList_t,int>>,CUtlMemory<CUtlVector<CTransitionTable::TransitionList_t,CUtlMemory<CTransitionTable::TransitionList_t,int>>,int>>::RemoveAll(
        CUtlVector<CUtlVector<CTransitionTable::TransitionList_t,CUtlMemory<CTransitionTable::TransitionList_t,int> >,CUtlMemory<CUtlVector<CTransitionTable::TransitionList_t,CUtlMemory<CTransitionTable::TransitionList_t,int> >,int> > *this)
{
  int v1; // ebx
  int v2; // ebp
  CUtlVector<CTransitionTable::TransitionList_t,CUtlMemory<CTransitionTable::TransitionList_t,int> > *v3; // esi
  bool v4; // sf
  CTransitionTable::TransitionList_t *m_pMemory; // eax
  CUtlVector<CUtlVector<CTransitionTable::TransitionList_t,CUtlMemory<CTransitionTable::TransitionList_t,int> >,CUtlMemory<CUtlVector<CTransitionTable::TransitionList_t,CUtlMemory<CTransitionTable::TransitionList_t,int> >,int> > *v6; // [esp+8h] [ebp-4h]

  v1 = this->m_Size - 1;
  v6 = this;
  if ( v1 < 0 )
  {
    this->m_Size = 0;
  }
  else
  {
    v2 = v1;
    do
    {
      v3 = &this->m_Memory.m_pMemory[v2];
      v4 = v3->m_Memory.m_nGrowSize < 0;
      v3->m_Size = 0;
      if ( !v4 )
      {
        if ( v3->m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v3->m_Memory.m_pMemory);
          this = v6;
          v3->m_Memory.m_pMemory = nullptr;
        }
        v3->m_Memory.m_nAllocationCount = 0;
      }
      v4 = v3->m_Memory.m_nGrowSize < 0;
      m_pMemory = v3->m_Memory.m_pMemory;
      v3->m_pElements = v3->m_Memory.m_pMemory;
      if ( !v4 )
      {
        if ( m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
          this = v6;
          v3->m_Memory.m_pMemory = nullptr;
        }
        v3->m_Memory.m_nAllocationCount = 0;
      }
      --v1;
      --v2;
    }
    while ( v1 >= 0 );
    this->m_Size = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100337A0
// Name: public: CUtlVector<class CUtlVector<struct CTransitionTable::TransitionList_t,class CUtlMemory<struct CTransitionTable::TransitionList_t,int>>,class CUtlMemory<class CUtlVector<struct CTransitionTable::TransitionList_t,class CUtlMemory<struct CTransitionTable::TransitionList_t,int>>,int>>::~CUtlVector<class CUtlVector<struct CTransitionTable::TransitionList_t,class CUtlMemory<struct CTransitionTable::TransitionList_t,int>>,class CUtlMemory<class CUtlVector<struct CTransitionTable::TransitionList_t,class CUtlMemory<struct CTransitionTable::TransitionList_t,int>>,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CUtlVector<CTransitionTable::TransitionList_t,CUtlMemory<CTransitionTable::TransitionList_t,int>>,CUtlMemory<CUtlVector<CTransitionTable::TransitionList_t,CUtlMemory<CTransitionTable::TransitionList_t,int>>,int>>::~CUtlVector<CUtlVector<CTransitionTable::TransitionList_t,CUtlMemory<CTransitionTable::TransitionList_t,int>>,CUtlMemory<CUtlVector<CTransitionTable::TransitionList_t,CUtlMemory<CTransitionTable::TransitionList_t,int>>,int>>(
        CUtlVector<CUtlVector<CTransitionTable::TransitionList_t,CUtlMemory<CTransitionTable::TransitionList_t,int> >,CUtlMemory<CUtlVector<CTransitionTable::TransitionList_t,CUtlMemory<CTransitionTable::TransitionList_t,int> >,int> > *this)
{
  bool v2; // sf
  CUtlVector<CTransitionTable::TransitionList_t,CUtlMemory<CTransitionTable::TransitionList_t,int> > *m_pMemory; // eax

  CUtlVector<CUtlVector<CTransitionTable::TransitionList_t,CUtlMemory<CTransitionTable::TransitionList_t,int>>,CUtlMemory<CUtlVector<CTransitionTable::TransitionList_t,CUtlMemory<CTransitionTable::TransitionList_t,int>>,int>>::RemoveAll(this);
  if ( this->m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
  v2 = this->m_Memory.m_nGrowSize < 0;
  m_pMemory = this->m_Memory.m_pMemory;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( !v2 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100356C0
// Name: PatchPixelShaderForAtiMsaaHack
// Source: json
//------------------------------------------------------------------------------
void __usercall PatchPixelShaderForAtiMsaaHack(unsigned int *pShader@<eax>, unsigned int dwTexCoordMask)
{
  unsigned int *v2; // edi
  unsigned int v3; // ebx
  unsigned int v4; // ebx
  unsigned int v5; // ecx
  int v6; // edx
  unsigned int v7; // eax

  if ( *pShader == -65024 )
  {
    v2 = pShader + 1;
    if ( pShader != (unsigned int *)-4 )
    {
      while ( 1 )
      {
        v3 = *v2;
        if ( (unsigned __int16)*v2 == 31 )
          break;
        if ( (unsigned __int16)*v2 != 65534 )
        {
          if ( (unsigned __int16)*v2 == 0xFFFF )
            return;
          goto LABEL_16;
        }
        v4 = HIWORD(v3);
LABEL_17:
        v2 += v4 + 1;
        if ( v2 == nullptr )
          return;
      }
      if ( (v2[1] & 0x78000000) == 0 )
      {
        v5 = v2[2];
        if ( ((v5 >> 8) & 0x18) + ((v5 >> 28) & 7) == 3 )
        {
          v6 = 1;
          v7 = 0;
          while ( (dwTexCoordMask & v6) != v6 || (v5 & 0x7FF) != v7 )
          {
            ++v7;
            v6 *= 2;
            if ( v7 >= 0x10 )
              goto LABEL_16;
          }
          v2[2] = v5 | 0x400000;
        }
      }
LABEL_16:
      v4 = HIBYTE(v3) & 0xF;
      goto LABEL_17;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10035770
// Name: private: void CShaderManager::CreateStaticShaders(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderManager::CreateStaticShaders(CShaderManager *this)
{
  D3DDeviceWrapper *v1; // esi
  unsigned int psIllegalMaterial[11]; // [esp+0h] [ebp-30h] BYREF
  int v3; // [esp+2Ch] [ebp-4h]

  psIllegalMaterial[1] = -65279;
  psIllegalMaterial[2] = 81;
  psIllegalMaterial[3] = -1609629696;
  psIllegalMaterial[4] = 0;
  psIllegalMaterial[5] = 1065353216;
  psIllegalMaterial[6] = 0;
  psIllegalMaterial[7] = 1065353216;
  psIllegalMaterial[8] = 1;
  psIllegalMaterial[9] = -2146500608;
  psIllegalMaterial[10] = -1595670528;
  v3 = 0xFFFF;
  v1 = Dx9Device();
  D3DDeviceWrapper::Synchronize(this: v1);
  v1->m_pD3DDevice->CreatePixelShader(
    this: v1->m_pD3DDevice,
    a2: &psIllegalMaterial[1],
    a3: (IDirect3DPixelShader9 **)&s_pIllegalMaterialPS);
}

//------------------------------------------------------------------------------
// Address: 0x100357F0
// Name: private: void __near * CShaderManager::OpenFileAndLoadHeader(char const __near *,struct ShaderHeader_t __near *)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall CShaderManager::OpenFileAndLoadHeader(
        CShaderManager *this,
        const char *pFileName,
        ShaderHeader_t *pHeader)
{
  void *result; // eax
  void *v4; // esi
  int m_nVersion; // eax

  result = g_pFullFileSystem->Open(this: &g_pFullFileSystem->IBaseFileSystem, a2: pFileName, a3: "rb", a4: "PLATFORM");
  v4 = result;
  if ( result != nullptr )
  {
    if ( pHeader == nullptr )
      return v4;
    g_pFullFileSystem->Read(this: &g_pFullFileSystem->IBaseFileSystem, a2: pHeader, a3: 28, a4: result);
    m_nVersion = pHeader->m_nVersion;
    if ( pHeader->m_nVersion == 4 || pHeader->m_nVersion > 4 && m_nVersion <= 6 )
    {
      return v4;
    }
    else
    {
      _Warning(a1: "Shader %s is the wrong version %d, expecting %d\n", pFileName, m_nVersion, 6);
      g_pFullFileSystem->Close(this: &g_pFullFileSystem->IBaseFileSystem, a2: v4);
      return nullptr;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10035880
// Name: public: virtual void __near * CShaderManager::GetCurrentVertexShader(void)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall CShaderManager::GetCurrentVertexShader(CShaderManager *this)
{
  return this->m_HardwareVertexShader;
}

//------------------------------------------------------------------------------
// Address: 0x10035890
// Name: public: virtual void __near * CShaderManager::GetCurrentPixelShader(void)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall CShaderManager::GetCurrentPixelShader(CShaderManager *this)
{
  return this->m_HardwarePixelShader;
}

//------------------------------------------------------------------------------
// Address: 0x100358A0
// Name: public: virtual void CShaderManager::ResetShaderState(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderManager::ResetShaderState(CShaderManager *this)
{
  void (__thiscall *SetVertexShader)(struct CShaderManager *, int); // edx

  SetVertexShader = this->SetVertexShader;
  this->m_HardwareVertexShader = (void *)-1;
  this->m_HardwarePixelShader = (void *)-1;
  ((void (__stdcall *)(int))SetVertexShader)(a1: -1);
  this->SetPixelShader(this, a2: -1);
}

//------------------------------------------------------------------------------
// Address: 0x100358D0
// Name: mat_shadercount
// Source: json
//------------------------------------------------------------------------------
void __cdecl mat_shadercount()
{
  _Warning(a1: "Num Pixel Shaders = %d Vertex Shaders=%d\n", s_NumPixelShadersCreated, s_NumVertexShadersCreated);
  s_NumVertexShadersCreated = 0;
  s_NumPixelShadersCreated = 0;
}

//------------------------------------------------------------------------------
// Address: 0x10035900
// Name: public: virtual unsigned int CShaderBuffer<struct ID3D10Blob>::GetSize(void)const
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CShaderBuffer<ID3D10Blob>::GetSize(CShaderBuffer<ID3D10Blob> *this)
{
  if ( this->m_pBlob != nullptr )
    return this->m_pBlob->GetBufferSize(this: this->m_pBlob);
  else
    return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10035920
// Name: int BinarySearchCombos<struct StaticComboAliasRecord_t>(unsigned int,int,struct StaticComboAliasRecord_t const __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl BinarySearchCombos<StaticComboAliasRecord_t>(
        unsigned int nStaticComboID,
        int nCombos,
        const StaticComboAliasRecord_t *pRecords)
{
  int v3; // edi
  int v4; // esi
  int v5; // eax
  unsigned int m_nStaticComboID; // ecx

  v3 = nCombos;
  v4 = 1;
  if ( nCombos < 1 )
    return -1;
  while ( 1 )
  {
    v5 = (v3 + v4) / 2;
    m_nStaticComboID = pRecords[v5 - 1].m_nStaticComboID;
    if ( nStaticComboID >= m_nStaticComboID )
      break;
    v3 = v5 - 1;
LABEL_6:
    if ( v3 < v4 )
      return -1;
  }
  if ( nStaticComboID > m_nStaticComboID )
  {
    v4 = v5 + 1;
    goto LABEL_6;
  }
  return v5 - 1;
}

//------------------------------------------------------------------------------
// Address: 0x10035970
// Name: public: void CUtlFixedMemory<struct UtlLinkedListElem_t<struct IDirect3DPixelShader9 __near *,int>>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlFixedMemory<UtlLinkedListElem_t<IDirect3DPixelShader9 *,int>>::Grow(
        CUtlFixedMemory<UtlLinkedListElem_t<IDirect3DPixelShader9 *,int> > *this,
        int num)
{
  int m_nGrowSize; // esi
  CUtlFixedMemory<UtlLinkedListElem_t<IDirect3DPixelShader9 *,int> >::BlockHeader_t *v4; // ebx
  CUtlFixedMemory<UtlLinkedListElem_t<IDirect3DPixelShader9 *,int> >::BlockHeader_t *m_pBlocks; // eax
  bool v6; // zf

  if ( num > 0 )
  {
    m_nGrowSize = this->m_nGrowSize;
    if ( m_nGrowSize == 0 )
    {
      m_nGrowSize = this->m_nAllocationCount;
      if ( m_nGrowSize == 0 )
        m_nGrowSize = 3;
    }
    if ( m_nGrowSize < num )
      m_nGrowSize *= (m_nGrowSize + num - 1) / m_nGrowSize;
    this->m_nAllocationCount += m_nGrowSize;
    v4 = (CUtlFixedMemory<UtlLinkedListElem_t<IDirect3DPixelShader9 *,int> >::BlockHeader_t *)_g_pMemAlloc->Alloc_2(
                                                                                                this: _g_pMemAlloc,
                                                                                                a2: 12 * m_nGrowSize + 8);
    if ( v4 == nullptr )
      _Error(a1: "CUtlFixedMemory overflow!\n");
    m_pBlocks = this->m_pBlocks;
    v6 = this->m_pBlocks == nullptr;
    v4->m_pNext = nullptr;
    v4->m_nBlockSize = m_nGrowSize;
    if ( v6 )
    {
      this->m_pBlocks = v4;
    }
    else
    {
      for ( ; m_pBlocks->m_pNext != nullptr; m_pBlocks = m_pBlocks->m_pNext )
        ;
      m_pBlocks->m_pNext = v4;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10035A00
// Name: public: void CUtlFixedMemory<struct UtlLinkedListElem_t<struct CShaderDeviceDx10::VertexShader_t,int>>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlFixedMemory<UtlLinkedListElem_t<CShaderDeviceDx10::VertexShader_t,int>>::Grow(
        CUtlFixedMemory<UtlLinkedListElem_t<CShaderDeviceDx10::VertexShader_t,int> > *this,
        int num)
{
  int m_nGrowSize; // esi
  CUtlFixedMemory<UtlLinkedListElem_t<CShaderDeviceDx10::VertexShader_t,int> >::BlockHeader_t *v4; // ebx
  CUtlFixedMemory<UtlLinkedListElem_t<CShaderDeviceDx10::VertexShader_t,int> >::BlockHeader_t *m_pBlocks; // eax
  bool v6; // zf

  if ( num > 0 )
  {
    m_nGrowSize = this->m_nGrowSize;
    if ( m_nGrowSize == 0 )
    {
      m_nGrowSize = this->m_nAllocationCount;
      if ( m_nGrowSize == 0 )
        m_nGrowSize = 1;
    }
    if ( m_nGrowSize < num )
      m_nGrowSize *= (m_nGrowSize + num - 1) / m_nGrowSize;
    this->m_nAllocationCount += m_nGrowSize;
    v4 = (CUtlFixedMemory<UtlLinkedListElem_t<CShaderDeviceDx10::VertexShader_t,int> >::BlockHeader_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 52 * m_nGrowSize + 8);
    if ( v4 == nullptr )
      _Error(a1: "CUtlFixedMemory overflow!\n");
    m_pBlocks = this->m_pBlocks;
    v6 = this->m_pBlocks == nullptr;
    v4->m_pNext = nullptr;
    v4->m_nBlockSize = m_nGrowSize;
    if ( v6 )
    {
      this->m_pBlocks = v4;
    }
    else
    {
      for ( ; m_pBlocks->m_pNext != nullptr; m_pBlocks = m_pBlocks->m_pNext )
        ;
      m_pBlocks->m_pNext = v4;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10035A90
// Name: public: void CUtlFixedMemory<struct UtlLinkedListElem_t<struct ShaderFileCache_t,int>>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlFixedMemory<UtlLinkedListElem_t<ShaderFileCache_t,int>>::Grow(
        CUtlFixedMemory<UtlLinkedListElem_t<ShaderFileCache_t,int> > *this,
        int num)
{
  int m_nGrowSize; // esi
  CUtlFixedMemory<UtlLinkedListElem_t<ShaderFileCache_t,int> >::BlockHeader_t *v4; // ebx
  CUtlFixedMemory<UtlLinkedListElem_t<ShaderFileCache_t,int> >::BlockHeader_t *m_pBlocks; // eax
  bool v6; // zf

  if ( num > 0 )
  {
    m_nGrowSize = this->m_nGrowSize;
    if ( m_nGrowSize == 0 )
    {
      m_nGrowSize = this->m_nAllocationCount;
      if ( m_nGrowSize == 0 )
        m_nGrowSize = 1;
    }
    if ( m_nGrowSize < num )
      m_nGrowSize *= (m_nGrowSize + num - 1) / m_nGrowSize;
    this->m_nAllocationCount += m_nGrowSize;
    v4 = (CUtlFixedMemory<UtlLinkedListElem_t<ShaderFileCache_t,int> >::BlockHeader_t *)_g_pMemAlloc->Alloc_2(
                                                                                          this: _g_pMemAlloc,
                                                                                          a2: 132 * m_nGrowSize + 8);
    if ( v4 == nullptr )
      _Error(a1: "CUtlFixedMemory overflow!\n");
    m_pBlocks = this->m_pBlocks;
    v6 = this->m_pBlocks == nullptr;
    v4->m_pNext = nullptr;
    v4->m_nBlockSize = m_nGrowSize;
    if ( v6 )
    {
      this->m_pBlocks = v4;
    }
    else
    {
      for ( ; m_pBlocks->m_pNext != nullptr; m_pBlocks = m_pBlocks->m_pNext )
        ;
      m_pBlocks->m_pNext = v4;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10035B20
// Name: CreateD3DVertexShader
// Source: json
//------------------------------------------------------------------------------
int __usercall CreateD3DVertexShader@<eax>(unsigned int *pByteCode@<edi>, int a2@<ecx>)
{
  D3DDeviceWrapper *v2; // esi
  int v4; // [esp+Ch] [ebp-4h] BYREF

  v4 = a2;
  if ( r_emulategl.m_pParent->m_Value.m_nValue != 0 )
    D3DXGetShaderVersion(a1: pByteCode);
  v2 = Dx9Device();
  D3DDeviceWrapper::Synchronize(this: v2);
  if ( v2->m_pD3DDevice->CreateVertexShader(this: v2->m_pD3DDevice, a2: pByteCode, a3: (IDirect3DVertexShader9 **)&v4) < 0 )
    return 0;
  ++s_NumVertexShadersCreated;
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x10035B70
// Name: CreateD3DPixelShader
// Source: json
//------------------------------------------------------------------------------
int __usercall CreateD3DPixelShader@<eax>(unsigned int *pByteCode@<edi>, unsigned int nCentroidMask@<eax>)
{
  D3DDeviceWrapper *v4; // esi
  int v5; // [esp+Ch] [ebp-4h] BYREF

  if ( pByteCode == nullptr )
    return 0;
  if ( nCentroidMask != 0
    && g_pMaterialSystemHardwareConfig->NeedsATICentroidHack(this: g_pMaterialSystemHardwareConfig)
    && !g_pMaterialSystemHardwareConfig->SuppressPixelShaderCentroidHackFixup(this: g_pMaterialSystemHardwareConfig) )
  {
    PatchPixelShaderForAtiMsaaHack(pShader: pByteCode, dwTexCoordMask: nCentroidMask);
  }
  if ( r_emulategl.m_pParent->m_Value.m_nValue != 0 )
    D3DXGetShaderVersion(a1: pByteCode);
  v4 = Dx9Device();
  D3DDeviceWrapper::Synchronize(this: v4);
  if ( v4->m_pD3DDevice->CreatePixelShader(this: v4->m_pD3DDevice, a2: pByteCode, a3: (IDirect3DPixelShader9 **)&v5) < 0 )
    return 0;
  ++s_NumPixelShadersCreated;
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x10035C00
// Name: public: virtual class IShaderBuffer __near * CShaderManager::CompileShader(char const __near *,unsigned int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
IShaderBuffer *__thiscall CShaderManager::CompileShader(
        CShaderManager *this,
        const char *pProgram,
        ID3DXBuffer *nBufLen,
        ID3DXBuffer *pShaderVersion)
{
  const char *v4; // eax
  _DWORD *v6; // eax
  unsigned int v7; // ecx
  _DWORD *v8; // esi

  if ( D3DXCompileShader(
         a1: pProgram,
         a2: nBufLen,
         a3: 0,
         a4: 0,
         a5: "main",
         a6: pShaderVersion,
         a7: 512,
         a8: &nBufLen,
         a9: &pShaderVersion,
         a10: 0) >= 0 )
  {
    v6 = operator new(nSize: 8u);
    if ( v6 != nullptr )
    {
      v7 = (unsigned int)nBufLen;
      *v6 = &CShaderBuffer<ID3DXBuffer>::`vftable';
      v6[1] = v7;
      v8 = v6;
    }
    else
    {
      v8 = nullptr;
    }
    if ( pShaderVersion != nullptr )
      pShaderVersion->Release(this: pShaderVersion);
    return (IShaderBuffer *)v8;
  }
  else
  {
    if ( pShaderVersion != nullptr )
    {
      v4 = (const char *)pShaderVersion->GetBufferPointer(this: pShaderVersion);
      _Warning(a1: "Shader compilation failed! Reported the following errors:\n%s\n", v4);
      pShaderVersion->Release(this: pShaderVersion);
    }
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10035CA0
// Name: private: void CShaderManager::SetVertexShaderState(void __near *,struct memhandle_t__ __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderManager::SetVertexShaderState(
        CShaderManager *this,
        IDirect3DVertexShader9 *shader,
        memhandle_t__ *hCachedShader)
{
  D3DDeviceWrapper *v4; // eax
  D3DDeviceWrapper *v5; // esi
  unsigned int *m_pOutputPtr; // eax

  if ( this->m_HardwareVertexShader != shader )
  {
    if ( (_S2_2 & 1) == 0 )
    {
      _S2_2 |= 1u;
      counter_21.m_pCounter = CVProfile::FindOrCreateCounter(
                                this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
                                a2: "vertex shader change",
                                a3: COUNTER_GROUP_DEFAULT);
      atexit(func: CShaderManager::SetVertexShaderState_::_7_::_dynamic_atexit_destructor_for___counter__);
    }
    ++*counter_21.m_pCounter;
    v4 = Dx9Device();
    v5 = v4;
    if ( v4->m_pASyncThreadHandle != nullptr )
    {
      if ( v4->m_PushBufferFreeSlots < 2 )
        D3DDeviceWrapper::SubmitPushBufferAndGetANewOne(this: v4);
      m_pOutputPtr = v5->m_pOutputPtr;
      v5->m_PushBufferFreeSlots -= 2;
      *m_pOutputPtr = 6;
      *++v5->m_pOutputPtr = (unsigned int)shader;
      ++v5->m_pOutputPtr;
      this->m_HardwareVertexShader = shader;
    }
    else
    {
      v4->m_pD3DDevice->SetVertexShader(this: v4->m_pD3DDevice, a2: shader);
      this->m_HardwareVertexShader = shader;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10035D50
// Name: private: void CShaderManager::SetPixelShaderState(void __near *,struct memhandle_t__ __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderManager::SetPixelShaderState(
        CShaderManager *this,
        IDirect3DPixelShader9 *shader,
        memhandle_t__ *hCachedShader)
{
  D3DDeviceWrapper *v4; // eax
  D3DDeviceWrapper *v5; // esi
  unsigned int *m_pOutputPtr; // eax

  if ( this->m_HardwarePixelShader != shader )
  {
    if ( (_S3_1 & 1) == 0 )
    {
      _S3_1 |= 1u;
      counter_22.m_pCounter = CVProfile::FindOrCreateCounter(
                                this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
                                a2: "pixel shader change",
                                a3: COUNTER_GROUP_DEFAULT);
      atexit(func: CShaderManager::SetPixelShaderState_::_7_::_dynamic_atexit_destructor_for___counter__);
    }
    ++*counter_22.m_pCounter;
    v4 = Dx9Device();
    v5 = v4;
    if ( v4->m_pASyncThreadHandle != nullptr )
    {
      if ( v4->m_PushBufferFreeSlots < 2 )
        D3DDeviceWrapper::SubmitPushBufferAndGetANewOne(this: v4);
      m_pOutputPtr = v5->m_pOutputPtr;
      v5->m_PushBufferFreeSlots -= 2;
      *m_pOutputPtr = 5;
      *++v5->m_pOutputPtr = (unsigned int)shader;
      ++v5->m_pOutputPtr;
      this->m_HardwarePixelShader = shader;
    }
    else
    {
      v4->m_pD3DDevice->SetPixelShader(this: v4->m_pD3DDevice, a2: shader);
      this->m_HardwarePixelShader = shader;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10035E00
// Name: public: class CUtlFixedMemory<struct UtlLinkedListElem_t<struct CShaderDeviceDx10::GeometryShader_t,int>>::Iterator_t CUtlFixedMemory<struct UtlLinkedListElem_t<struct CShaderDeviceDx10::GeometryShader_t,int>>::Next(class CUtlFixedMemory<struct UtlLinkedListElem_t<struct CShaderDeviceDx10::GeometryShader_t,int>>::Iterator_t const __near &)const
// Source: json
//------------------------------------------------------------------------------
CUtlFixedMemory<UtlLinkedListElem_t<IDirect3DVertexShader9 *,int> >::Iterator_t *__thiscall CUtlFixedMemory<UtlLinkedListElem_t<CShaderDeviceDx10::GeometryShader_t,int>>::Next(
        CUtlFixedMemory<UtlLinkedListElem_t<Texture_t,int> > *this,
        CUtlFixedMemory<UtlLinkedListElem_t<IDirect3DVertexShader9 *,int> >::Iterator_t *result,
        const CUtlFixedMemory<UtlLinkedListElem_t<Texture_t,int> >::Iterator_t *it)
{
  CUtlFixedMemory<UtlLinkedListElem_t<Texture_t,int> >::BlockHeader_t *m_pBlockHeader; // ecx
  int m_nIndex; // eax
  CUtlFixedMemory<UtlLinkedListElem_t<Texture_t,int> >::BlockHeader_t *m_pNext; // ecx
  CUtlFixedMemory<UtlLinkedListElem_t<Texture_t,int> >::Iterator_t v7; // [esp+0h] [ebp-8h]

  m_pBlockHeader = it->m_pBlockHeader;
  if ( it->m_pBlockHeader != nullptr && (m_nIndex = it->m_nIndex) >= 0 && m_nIndex < m_pBlockHeader->m_nBlockSize )
  {
    if ( m_nIndex + 1 >= m_pBlockHeader->m_nBlockSize )
    {
      m_pNext = m_pBlockHeader->m_pNext;
      if ( m_pNext != nullptr )
      {
        v7 = (CUtlFixedMemory<UtlLinkedListElem_t<Texture_t,int> >::Iterator_t)(unsigned int)m_pNext;
      }
      else
      {
        v7.m_pBlockHeader = nullptr;
        v7.m_nIndex = -1;
      }
      *(CUtlFixedMemory<UtlLinkedListElem_t<Texture_t,int> >::Iterator_t *)result = v7;
      return result;
    }
    else
    {
      result->m_pBlockHeader = (CUtlFixedMemory<UtlLinkedListElem_t<IDirect3DVertexShader9 *,int> >::BlockHeader_t *)m_pBlockHeader;
      result->m_nIndex = m_nIndex + 1;
      return result;
    }
  }
  else
  {
    result->m_pBlockHeader = nullptr;
    result->m_nIndex = -1;
    return result;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10035E80
// Name: public: void CUtlFixedMemory<struct UtlLinkedListElem_t<struct IDirect3DPixelShader9 __near *,int>>::Init(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlFixedMemory<UtlLinkedListElem_t<IDirect3DPixelShader9 *,int>>::Init(
        CUtlFixedMemory<UtlLinkedListElem_t<IDirect3DPixelShader9 *,int> > *this,
        int nGrowSize,
        int nInitSize)
{
  CUtlFixedMemory<UtlLinkedListElem_t<IDirect3DPixelShader9 *,int> >::BlockHeader_t *m_pBlocks; // esi
  CUtlFixedMemory<UtlLinkedListElem_t<IDirect3DPixelShader9 *,int> >::BlockHeader_t *v5; // eax

  m_pBlocks = this->m_pBlocks;
  if ( this->m_pBlocks != nullptr )
  {
    do
    {
      v5 = m_pBlocks;
      m_pBlocks = m_pBlocks->m_pNext;
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v5);
    }
    while ( m_pBlocks != nullptr );
    this->m_pBlocks = nullptr;
    this->m_nAllocationCount = 0;
  }
  this->m_nGrowSize = nGrowSize;
  CUtlFixedMemory<UtlLinkedListElem_t<IDirect3DPixelShader9 *,int>>::Grow(this, num: nInitSize);
}

//------------------------------------------------------------------------------
// Address: 0x10035ED0
// Name: public: void CUtlFixedMemory<struct UtlLinkedListElem_t<struct CShaderDeviceDx10::VertexShader_t,int>>::Init(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlFixedMemory<UtlLinkedListElem_t<CShaderDeviceDx10::VertexShader_t,int>>::Init(
        CUtlFixedMemory<UtlLinkedListElem_t<CShaderDeviceDx10::VertexShader_t,int> > *this,
        int nGrowSize,
        int nInitSize)
{
  CUtlFixedMemory<UtlLinkedListElem_t<CShaderDeviceDx10::VertexShader_t,int> >::BlockHeader_t *m_pBlocks; // esi
  CUtlFixedMemory<UtlLinkedListElem_t<CShaderDeviceDx10::VertexShader_t,int> >::BlockHeader_t *v5; // eax

  m_pBlocks = this->m_pBlocks;
  if ( this->m_pBlocks != nullptr )
  {
    do
    {
      v5 = m_pBlocks;
      m_pBlocks = m_pBlocks->m_pNext;
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v5);
    }
    while ( m_pBlocks != nullptr );
    this->m_pBlocks = nullptr;
    this->m_nAllocationCount = 0;
  }
  this->m_nGrowSize = nGrowSize;
  CUtlFixedMemory<UtlLinkedListElem_t<CShaderDeviceDx10::VertexShader_t,int>>::Grow(this, num: nInitSize);
}

//------------------------------------------------------------------------------
// Address: 0x10035F20
// Name: struct CShaderManager::ShaderLookup_t __near * CopyConstruct<struct CShaderManager::ShaderLookup_t>(struct CShaderManager::ShaderLookup_t __near *,struct CShaderManager::ShaderLookup_t const __near &)
// Source: json
//------------------------------------------------------------------------------
CShaderManager::ShaderLookup_t *__cdecl CopyConstruct<CShaderManager::ShaderLookup_t>(
        CShaderManager::ShaderLookup_t *pMemory,
        const CShaderManager::ShaderLookup_t *src)
{
  CShaderManager::ShaderLookup_t *result; // eax

  result = pMemory;
  if ( pMemory == nullptr )
    return nullptr;
  *pMemory = *src;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10035F70
// Name: public: void CUtlFixedMemory<struct UtlLinkedListElem_t<struct ShaderFileCache_t,int>>::Init(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlFixedMemory<UtlLinkedListElem_t<ShaderFileCache_t,int>>::Init(
        CUtlFixedMemory<UtlLinkedListElem_t<ShaderFileCache_t,int> > *this,
        int nGrowSize,
        int nInitSize)
{
  CUtlFixedMemory<UtlLinkedListElem_t<ShaderFileCache_t,int> >::BlockHeader_t *m_pBlocks; // esi
  CUtlFixedMemory<UtlLinkedListElem_t<ShaderFileCache_t,int> >::BlockHeader_t *v5; // eax

  m_pBlocks = this->m_pBlocks;
  if ( this->m_pBlocks != nullptr )
  {
    do
    {
      v5 = m_pBlocks;
      m_pBlocks = m_pBlocks->m_pNext;
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v5);
    }
    while ( m_pBlocks != nullptr );
    this->m_pBlocks = nullptr;
    this->m_nAllocationCount = 0;
  }
  this->m_nGrowSize = nGrowSize;
  CUtlFixedMemory<UtlLinkedListElem_t<ShaderFileCache_t,int>>::Grow(this, num: nInitSize);
}

//------------------------------------------------------------------------------
// Address: 0x10035FC0
// Name: public: bool CUtlFixedMemory<struct UtlLinkedListElem_t<struct IDirect3DPixelShader9 __near *,int>>::IsIdxAfter(int,class CUtlFixedMemory<struct UtlLinkedListElem_t<struct IDirect3DPixelShader9 __near *,int>>::Iterator_t const __near &)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CUtlFixedMemory<UtlLinkedListElem_t<IDirect3DPixelShader9 *,int>>::IsIdxAfter(
        CUtlFixedMemory<UtlLinkedListElem_t<IDirect3DPixelShader9 *,int> > *this,
        unsigned int i,
        const CUtlFixedMemory<UtlLinkedListElem_t<IDirect3DPixelShader9 *,int> >::Iterator_t *it)
{
  CUtlFixedMemory<UtlLinkedListElem_t<IDirect3DPixelShader9 *,int> >::BlockHeader_t *m_pBlockHeader; // eax
  int m_nIndex; // ecx
  CUtlFixedMemory<UtlLinkedListElem_t<IDirect3DPixelShader9 *,int> >::BlockHeader_t *m_pNext; // eax

  m_pBlockHeader = it->m_pBlockHeader;
  if ( it->m_pBlockHeader == nullptr )
    return false;
  m_nIndex = it->m_nIndex;
  if ( m_nIndex < 0 || m_nIndex >= m_pBlockHeader->m_nBlockSize )
    return false;
  if ( i >= (unsigned int)&m_pBlockHeader[1] && i < (unsigned int)&m_pBlockHeader[1] + 12 * m_pBlockHeader->m_nBlockSize )
    return (int)i > (int)&m_pBlockHeader[1] + 12 * m_nIndex;
  m_pNext = m_pBlockHeader->m_pNext;
  if ( m_pNext == nullptr )
    return false;
  while ( i < (unsigned int)&m_pNext[1] || i >= (unsigned int)&m_pNext[1] + 12 * m_pNext->m_nBlockSize )
  {
    m_pNext = m_pNext->m_pNext;
    if ( m_pNext == nullptr )
      return false;
  }
  return true;
}

//------------------------------------------------------------------------------
// Address: 0x10036040
// Name: public: bool CUtlFixedMemory<struct UtlLinkedListElem_t<struct ShaderFileCache_t,int>>::IsIdxAfter(int,class CUtlFixedMemory<struct UtlLinkedListElem_t<struct ShaderFileCache_t,int>>::Iterator_t const __near &)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CUtlFixedMemory<UtlLinkedListElem_t<ShaderFileCache_t,int>>::IsIdxAfter(
        CUtlFixedMemory<UtlLinkedListElem_t<ShaderFileCache_t,int> > *this,
        unsigned int i,
        const CUtlFixedMemory<UtlLinkedListElem_t<ShaderFileCache_t,int> >::Iterator_t *it)
{
  CUtlFixedMemory<UtlLinkedListElem_t<ShaderFileCache_t,int> >::BlockHeader_t *m_pBlockHeader; // eax
  int m_nIndex; // edx
  CUtlFixedMemory<UtlLinkedListElem_t<ShaderFileCache_t,int> >::BlockHeader_t *m_pNext; // eax

  m_pBlockHeader = it->m_pBlockHeader;
  if ( it->m_pBlockHeader == nullptr )
    return false;
  m_nIndex = it->m_nIndex;
  if ( m_nIndex < 0 || m_nIndex >= m_pBlockHeader->m_nBlockSize )
    return false;
  if ( i >= (unsigned int)&m_pBlockHeader[1]
    && i < (unsigned int)&m_pBlockHeader[1] + 132 * m_pBlockHeader->m_nBlockSize )
  {
    return (int)i > (int)&m_pBlockHeader[1] + 132 * m_nIndex;
  }
  m_pNext = m_pBlockHeader->m_pNext;
  if ( m_pNext == nullptr )
    return false;
  while ( i < (unsigned int)&m_pNext[1] || i >= (unsigned int)&m_pNext[1] + 132 * m_pNext->m_nBlockSize )
  {
    m_pNext = m_pNext->m_pNext;
    if ( m_pNext == nullptr )
      return false;
  }
  return true;
}

//------------------------------------------------------------------------------
// Address: 0x100360C0
// Name: public: virtual void CShaderManager::Init(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderManager::Init(CShaderManager *this)
{
  int v2; // ecx
  int v3; // eax

  if ( g_pShaderUtil->InEditorMode(this: g_pShaderUtil)
    || (v3 = _CommandLine(a1: v2),
        (*(int (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v3 + 12))(a1: v3, a2: "-shadersondemand", a3: 0) != 0) )
  {
    this->m_bCreateShadersOnDemand = true;
    CShaderManager::CreateStaticShaders(this);
  }
  else
  {
    this->m_bCreateShadersOnDemand = false;
    CShaderManager::CreateStaticShaders(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10036110
// Name: public: virtual void CShaderManager::BindVertexShader(struct VertexShaderHandle_t__ __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderManager::BindVertexShader(CShaderManager *this, IDirect3DVertexShader9 **hVertexShader)
{
  CShaderManager::SetVertexShaderState(this, shader: *hVertexShader, hCachedShader: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x10036130
// Name: public: virtual void CShaderManager::SetVertexShader(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderManager::SetVertexShader(CShaderManager *this, int shader)
{
  int m_nVertexShaderIndex; // esi
  IDirect3DVertexShader9 *D3DVertexShader; // edi
  unsigned int **v5; // edi
  int v6; // ecx

  if ( shader == -1 )
  {
    CShaderManager::SetVertexShaderState(this, shader: nullptr, hCachedShader: nullptr);
  }
  else
  {
    m_nVertexShaderIndex = this->m_nVertexShaderIndex;
    if ( m_nVertexShaderIndex < 0 )
      m_nVertexShaderIndex = 0;
    if ( (*(_BYTE *)(shader + 24) & 2) == 0 )
    {
      D3DVertexShader = *(IDirect3DVertexShader9 **)(*(_DWORD *)(shader + 16) + 4 * m_nVertexShaderIndex);
      if ( D3DVertexShader == nullptr )
      {
        if ( this->m_bCreateShadersOnDemand )
        {
          v5 = (unsigned int **)(*(_DWORD *)(shader + 20) + 24 * m_nVertexShaderIndex);
          CUtlSymbolTable::String(this: &this->m_ShaderSymbolTable, id: *(CUtlSymbol *)shader);
          D3DVertexShader = (IDirect3DVertexShader9 *)CreateD3DVertexShader(pByteCode: *v5, a2: v6);
          *(_DWORD *)(*(_DWORD *)(shader + 16) + 4 * m_nVertexShaderIndex) = D3DVertexShader;
        }
        if ( D3DVertexShader == nullptr )
          _Error(
            a1: "!!!!!Using invalid shader combo!!!!!  Consult a programmer and tell them to build debug materialsystem.dll a"
            "nd stdshader*.dll.  Run with \"mat_bufferprimitives 0\" and look for CMaterial in the call stack and see wha"
            "t m_pDebugName is.  You are likely using a shader combo that has been skipped.\n");
      }
      CShaderManager::SetVertexShaderState(this, shader: D3DVertexShader, hCachedShader: nullptr);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100361C0
// Name: public: virtual void CShaderManager::BindPixelShader(struct PixelShaderHandle_t__ __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderManager::BindPixelShader(CShaderManager *this, IDirect3DPixelShader9 **hPixelShader)
{
  CShaderManager::SetPixelShaderState(this, shader: *hPixelShader, hCachedShader: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x100361E0
// Name: public: virtual void CShaderManager::SetPixelShader(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderManager::SetPixelShader(CShaderManager *this, int shader)
{
  int m_nPixelShaderIndex; // ebx
  IDirect3DPixelShader9 *D3DPixelShader; // eax
  int v5; // edi

  if ( shader == -1 )
  {
    CShaderManager::SetPixelShaderState(this, shader: nullptr, hCachedShader: nullptr);
  }
  else
  {
    m_nPixelShaderIndex = this->m_nPixelShaderIndex;
    if ( (*(_BYTE *)(shader + 24) & 2) == 0 )
    {
      D3DPixelShader = *(IDirect3DPixelShader9 **)(*(_DWORD *)(shader + 16) + 4 * m_nPixelShaderIndex);
      if ( D3DPixelShader == nullptr && this->m_bCreateShadersOnDemand )
      {
        v5 = *(_DWORD *)(shader + 20) + 24 * m_nPixelShaderIndex;
        CUtlSymbolTable::String(this: &this->m_ShaderSymbolTable, id: *(CUtlSymbol *)shader);
        D3DPixelShader = (IDirect3DPixelShader9 *)CreateD3DPixelShader(
                                                    pByteCode: *(unsigned int **)v5,
                                                    nCentroidMask: *(_DWORD *)(v5 + 20));
        *(_DWORD *)(*(_DWORD *)(shader + 16) + 4 * m_nPixelShaderIndex) = D3DPixelShader;
      }
      CShaderManager::SetPixelShaderState(this, shader: D3DPixelShader, hCachedShader: nullptr);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10036260
// Name: public: int CUtlVector<struct StaticComboAliasRecord_t,class CUtlMemory<struct StaticComboAliasRecord_t,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<StaticComboAliasRecord_t,CUtlMemory<StaticComboAliasRecord_t,int>>::InsertMultipleBefore(
        CUtlVector<StaticComboAliasRecord_t,CUtlMemory<StaticComboAliasRecord_t,int> > *this,
        int elem,
        int num)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  StaticComboAliasRecord_t *m_pMemory; // ecx
  int v8; // eax
  int v9; // eax

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<StaticComboRecord_t,int>::Grow(
      (CUtlMemory<CMeshMgr::VertexBufferLookup_t,int> *)this,
      num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v8 = this->m_Size;
  this->m_pElements = this->m_Memory.m_pMemory;
  v9 = v8 - elem - num;
  if ( v9 > 0 && num > 0 )
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 8 * v9);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x100362D0
// Name: protected: int CUtlLinkedList<struct IDirect3DVertexShader9 __near *,int,1,int,class CUtlFixedMemory<struct UtlLinkedListElem_t<struct IDirect3DVertexShader9 __near *,int>>>::AllocInternal(bool)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<IDirect3DVertexShader9 *,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<IDirect3DVertexShader9 *,int>>>::AllocInternal(
        CUtlLinkedList<IDirect3DVertexShader9 *,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<IDirect3DVertexShader9 *,int> > > *this,
        bool multilist)
{
  int result; // eax
  CUtlFixedMemory<UtlLinkedListElem_t<IDirect3DVertexShader9 *,int> >::BlockHeader_t *m_pBlockHeader; // eax
  CUtlFixedMemory<UtlLinkedListElem_t<IDirect3DVertexShader9 *,int> >::Iterator_t *p_m_LastAlloc; // esi
  int m_nIndex; // ecx
  CUtlFixedMemory<UtlLinkedListElem_t<IDirect3DVertexShader9 *,int> >::BlockHeader_t **v7; // eax
  CUtlFixedMemory<UtlLinkedListElem_t<IDirect3DVertexShader9 *,int> >::BlockHeader_t *v8; // ecx
  bool v9; // zf
  int v10; // eax
  int v11; // ecx
  CUtlFixedMemory<UtlLinkedListElem_t<IDirect3DVertexShader9 *,int> >::Iterator_t *v12; // eax
  int v13; // esi
  CUtlFixedMemory<UtlLinkedListElem_t<Texture_t,int> >::Iterator_t v14; // [esp+Ch] [ebp-18h] BYREF
  CUtlFixedMemory<UtlLinkedListElem_t<Texture_t,int> >::Iterator_t v15; // [esp+14h] [ebp-10h] BYREF
  CUtlFixedMemory<UtlLinkedListElem_t<Texture_t,int> >::Iterator_t v16; // [esp+1Ch] [ebp-8h] BYREF

  result = this->m_FirstFree;
  if ( result != 0 )
  {
    this->m_FirstFree = *(_DWORD *)(result + 8);
LABEL_33:
    if ( multilist )
    {
      *(_DWORD *)(result + 8) = 0;
      *(_DWORD *)(result + 4) = 0;
    }
    else
    {
      *(_DWORD *)(result + 8) = result;
      *(_DWORD *)(result + 4) = result;
    }
    return result;
  }
  m_pBlockHeader = this->m_LastAlloc.m_pBlockHeader;
  p_m_LastAlloc = &this->m_LastAlloc;
  if ( m_pBlockHeader != nullptr
    && (m_nIndex = this->m_LastAlloc.m_nIndex) >= 0
    && m_nIndex < m_pBlockHeader->m_nBlockSize )
  {
    v7 = (CUtlFixedMemory<UtlLinkedListElem_t<IDirect3DVertexShader9 *,int> >::BlockHeader_t **)CUtlFixedMemory<UtlLinkedListElem_t<CShaderDeviceDx10::GeometryShader_t,int>>::Next(
                                                                                                  (CUtlFixedMemory<UtlLinkedListElem_t<Texture_t,int> > *)this,
                                                                                                  result: (CUtlFixedMemory<UtlLinkedListElem_t<IDirect3DVertexShader9 *,int> >::Iterator_t *)&v15,
                                                                                                  it: (const CUtlFixedMemory<UtlLinkedListElem_t<Texture_t,int> >::Iterator_t *)&this->m_LastAlloc);
  }
  else
  {
    if ( this->m_Memory.m_pBlocks != nullptr )
    {
      v14.m_pBlockHeader = (CUtlFixedMemory<UtlLinkedListElem_t<Texture_t,int> >::BlockHeader_t *)this->m_Memory.m_pBlocks;
      v14.m_nIndex = 0;
    }
    else
    {
      v14.m_pBlockHeader = nullptr;
      v14.m_nIndex = -1;
    }
    v15 = v14;
    v7 = (CUtlFixedMemory<UtlLinkedListElem_t<IDirect3DVertexShader9 *,int> >::BlockHeader_t **)&v15;
  }
  v8 = *v7;
  v9 = *v7 == nullptr;
  v10 = (int)v7[1];
  if ( v9 || v10 < 0 || v10 >= v8->m_nBlockSize )
  {
    CUtlFixedMemory<UtlLinkedListElem_t<IDirect3DPixelShader9 *,int>>::Grow(
      (CUtlFixedMemory<UtlLinkedListElem_t<IDirect3DPixelShader9 *,int> > *)this,
      num: 1);
    this->m_pElements = nullptr;
    if ( p_m_LastAlloc->m_pBlockHeader != nullptr
      && (v11 = this->m_LastAlloc.m_nIndex) >= 0
      && v11 < p_m_LastAlloc->m_pBlockHeader->m_nBlockSize )
    {
      v12 = CUtlFixedMemory<UtlLinkedListElem_t<CShaderDeviceDx10::GeometryShader_t,int>>::Next(
              (CUtlFixedMemory<UtlLinkedListElem_t<Texture_t,int> > *)this,
              result: (CUtlFixedMemory<UtlLinkedListElem_t<IDirect3DVertexShader9 *,int> >::Iterator_t *)&v14,
              it: (const CUtlFixedMemory<UtlLinkedListElem_t<Texture_t,int> >::Iterator_t *)&this->m_LastAlloc);
    }
    else
    {
      v12 = CUtlFixedMemory<UtlLinkedListElem_t<CShaderManager::ShaderLookup_t,int>>::First(
              (CUtlFixedMemory<UtlLinkedListElem_t<Texture_t,int> > *)this,
              result: (CUtlFixedMemory<UtlLinkedListElem_t<IDirect3DVertexShader9 *,int> >::Iterator_t *)&v16);
    }
    v8 = v12->m_pBlockHeader;
    v9 = v12->m_pBlockHeader == nullptr;
    v10 = v12->m_nIndex;
    if ( v9 || v10 < 0 || v10 >= v8->m_nBlockSize )
    {
      if ( _executeCount_8 < 10 )
      {
        ++_executeCount_8;
        _Warning(a1: "CUtlLinkedList overflow! (exhausted memory allocator)\n");
      }
      return 0;
    }
  }
  if ( (CUtlFixedMemory<UtlLinkedListElem_t<IDirect3DVertexShader9 *,int> >::BlockHeader_t *)((char *)v8 + 12 * v10) != (CUtlFixedMemory<UtlLinkedListElem_t<IDirect3DVertexShader9 *,int> >::BlockHeader_t *)-8 )
  {
    this->m_LastAlloc.m_nIndex = v10;
    p_m_LastAlloc->m_pBlockHeader = v8;
    if ( v8 != nullptr && (v13 = this->m_LastAlloc.m_nIndex) >= 0 && v13 < v8->m_nBlockSize )
    {
      ++this->m_NumAlloced;
      result = (int)&v8[1] + 12 * v13;
    }
    else
    {
      result = 0;
      ++this->m_NumAlloced;
    }
    goto LABEL_33;
  }
  if ( _executeCount_7 >= 10 )
    return 0;
  ++_executeCount_7;
  _Warning(a1: "CUtlLinkedList overflow! (exhausted index range)\n");
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10036450
// Name: protected: int CUtlLinkedList<struct IDirect3DPixelShader9 __near *,int,1,int,class CUtlFixedMemory<struct UtlLinkedListElem_t<struct IDirect3DPixelShader9 __near *,int>>>::AllocInternal(bool)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<IDirect3DPixelShader9 *,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<IDirect3DPixelShader9 *,int>>>::AllocInternal(
        CUtlLinkedList<IDirect3DPixelShader9 *,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<IDirect3DPixelShader9 *,int> > > *this,
        bool multilist)
{
  int result; // eax
  CUtlFixedMemory<UtlLinkedListElem_t<IDirect3DPixelShader9 *,int> >::BlockHeader_t *m_pBlockHeader; // eax
  CUtlFixedMemory<UtlLinkedListElem_t<IDirect3DPixelShader9 *,int> >::Iterator_t *p_m_LastAlloc; // esi
  int m_nIndex; // ecx
  CUtlFixedMemory<UtlLinkedListElem_t<IDirect3DPixelShader9 *,int> >::BlockHeader_t **v7; // eax
  CUtlFixedMemory<UtlLinkedListElem_t<IDirect3DPixelShader9 *,int> >::BlockHeader_t *v8; // ecx
  bool v9; // zf
  int v10; // eax
  int v11; // ecx
  CUtlFixedMemory<UtlLinkedListElem_t<IDirect3DVertexShader9 *,int> >::Iterator_t *v12; // eax
  int v13; // esi
  CUtlFixedMemory<UtlLinkedListElem_t<Texture_t,int> >::Iterator_t v14; // [esp+Ch] [ebp-18h] BYREF
  CUtlFixedMemory<UtlLinkedListElem_t<Texture_t,int> >::Iterator_t v15; // [esp+14h] [ebp-10h] BYREF
  CUtlFixedMemory<UtlLinkedListElem_t<Texture_t,int> >::Iterator_t v16; // [esp+1Ch] [ebp-8h] BYREF

  result = this->m_FirstFree;
  if ( result != 0 )
  {
    this->m_FirstFree = *(_DWORD *)(result + 8);
LABEL_33:
    if ( multilist )
    {
      *(_DWORD *)(result + 8) = 0;
      *(_DWORD *)(result + 4) = 0;
    }
    else
    {
      *(_DWORD *)(result + 8) = result;
      *(_DWORD *)(result + 4) = result;
    }
    return result;
  }
  m_pBlockHeader = this->m_LastAlloc.m_pBlockHeader;
  p_m_LastAlloc = &this->m_LastAlloc;
  if ( m_pBlockHeader != nullptr
    && (m_nIndex = this->m_LastAlloc.m_nIndex) >= 0
    && m_nIndex < m_pBlockHeader->m_nBlockSize )
  {
    v7 = (CUtlFixedMemory<UtlLinkedListElem_t<IDirect3DPixelShader9 *,int> >::BlockHeader_t **)CUtlFixedMemory<UtlLinkedListElem_t<CShaderDeviceDx10::GeometryShader_t,int>>::Next(
                                                                                                 (CUtlFixedMemory<UtlLinkedListElem_t<Texture_t,int> > *)this,
                                                                                                 result: (CUtlFixedMemory<UtlLinkedListElem_t<IDirect3DVertexShader9 *,int> >::Iterator_t *)&v15,
                                                                                                 it: (const CUtlFixedMemory<UtlLinkedListElem_t<Texture_t,int> >::Iterator_t *)&this->m_LastAlloc);
  }
  else
  {
    if ( this->m_Memory.m_pBlocks != nullptr )
    {
      v14.m_pBlockHeader = (CUtlFixedMemory<UtlLinkedListElem_t<Texture_t,int> >::BlockHeader_t *)this->m_Memory.m_pBlocks;
      v14.m_nIndex = 0;
    }
    else
    {
      v14.m_pBlockHeader = nullptr;
      v14.m_nIndex = -1;
    }
    v15 = v14;
    v7 = (CUtlFixedMemory<UtlLinkedListElem_t<IDirect3DPixelShader9 *,int> >::BlockHeader_t **)&v15;
  }
  v8 = *v7;
  v9 = *v7 == nullptr;
  v10 = (int)v7[1];
  if ( v9 || v10 < 0 || v10 >= v8->m_nBlockSize )
  {
    CUtlFixedMemory<UtlLinkedListElem_t<IDirect3DPixelShader9 *,int>>::Grow(this: &this->m_Memory, num: 1);
    this->m_pElements = nullptr;
    if ( p_m_LastAlloc->m_pBlockHeader != nullptr
      && (v11 = this->m_LastAlloc.m_nIndex) >= 0
      && v11 < p_m_LastAlloc->m_pBlockHeader->m_nBlockSize )
    {
      v12 = CUtlFixedMemory<UtlLinkedListElem_t<CShaderDeviceDx10::GeometryShader_t,int>>::Next(
              (CUtlFixedMemory<UtlLinkedListElem_t<Texture_t,int> > *)this,
              result: (CUtlFixedMemory<UtlLinkedListElem_t<IDirect3DVertexShader9 *,int> >::Iterator_t *)&v14,
              it: (const CUtlFixedMemory<UtlLinkedListElem_t<Texture_t,int> >::Iterator_t *)&this->m_LastAlloc);
    }
    else
    {
      v12 = CUtlFixedMemory<UtlLinkedListElem_t<CShaderManager::ShaderLookup_t,int>>::First(
              (CUtlFixedMemory<UtlLinkedListElem_t<Texture_t,int> > *)this,
              result: (CUtlFixedMemory<UtlLinkedListElem_t<IDirect3DVertexShader9 *,int> >::Iterator_t *)&v16);
    }
    v8 = (CUtlFixedMemory<UtlLinkedListElem_t<IDirect3DPixelShader9 *,int> >::BlockHeader_t *)v12->m_pBlockHeader;
    v9 = v12->m_pBlockHeader == nullptr;
    v10 = v12->m_nIndex;
    if ( v9 || v10 < 0 || v10 >= v8->m_nBlockSize )
    {
      if ( _executeCount_10 < 10 )
      {
        ++_executeCount_10;
        _Warning(a1: "CUtlLinkedList overflow! (exhausted memory allocator)\n");
      }
      return 0;
    }
  }
  if ( (CUtlFixedMemory<UtlLinkedListElem_t<IDirect3DPixelShader9 *,int> >::BlockHeader_t *)((char *)v8 + 12 * v10) != (CUtlFixedMemory<UtlLinkedListElem_t<IDirect3DPixelShader9 *,int> >::BlockHeader_t *)-8 )
  {
    this->m_LastAlloc.m_nIndex = v10;
    p_m_LastAlloc->m_pBlockHeader = v8;
    if ( v8 != nullptr && (v13 = this->m_LastAlloc.m_nIndex) >= 0 && v13 < v8->m_nBlockSize )
    {
      ++this->m_NumAlloced;
      result = (int)&v8[1] + 12 * v13;
    }
    else
    {
      result = 0;
      ++this->m_NumAlloced;
    }
    goto LABEL_33;
  }
  if ( _executeCount_9 >= 10 )
    return 0;
  ++_executeCount_9;
  _Warning(a1: "CUtlLinkedList overflow! (exhausted index range)\n");
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x100365D0
// Name: protected: int CUtlLinkedList<struct CShaderManager::ShaderLookup_t,int,1,int,class CUtlFixedMemory<struct UtlLinkedListElem_t<struct CShaderManager::ShaderLookup_t,int>>>::AllocInternal(bool)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<CShaderManager::ShaderLookup_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CShaderManager::ShaderLookup_t,int>>>::AllocInternal(
        CUtlLinkedList<CShaderManager::ShaderLookup_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CShaderManager::ShaderLookup_t,int> > > *this,
        bool multilist)
{
  int result; // eax
  CUtlFixedMemory<UtlLinkedListElem_t<CShaderManager::ShaderLookup_t,int> >::BlockHeader_t *m_pBlockHeader; // eax
  CUtlFixedMemory<UtlLinkedListElem_t<CShaderManager::ShaderLookup_t,int> >::Iterator_t *p_m_LastAlloc; // esi
  int m_nIndex; // ecx
  CUtlFixedMemory<UtlLinkedListElem_t<CShaderManager::ShaderLookup_t,int> >::BlockHeader_t **v7; // eax
  CUtlFixedMemory<UtlLinkedListElem_t<CShaderManager::ShaderLookup_t,int> >::BlockHeader_t *v8; // ecx
  bool v9; // zf
  int v10; // eax
  int v11; // ecx
  CUtlFixedMemory<UtlLinkedListElem_t<IDirect3DVertexShader9 *,int> >::Iterator_t *v12; // eax
  int v13; // esi
  CUtlFixedMemory<UtlLinkedListElem_t<Texture_t,int> >::Iterator_t v14; // [esp+Ch] [ebp-18h] BYREF
  CUtlFixedMemory<UtlLinkedListElem_t<Texture_t,int> >::Iterator_t v15; // [esp+14h] [ebp-10h] BYREF
  CUtlFixedMemory<UtlLinkedListElem_t<Texture_t,int> >::Iterator_t v16; // [esp+1Ch] [ebp-8h] BYREF

  result = this->m_FirstFree;
  if ( result != 0 )
  {
    this->m_FirstFree = *(_DWORD *)(result + 48);
LABEL_33:
    if ( multilist )
    {
      *(_DWORD *)(result + 48) = 0;
      *(_DWORD *)(result + 44) = 0;
    }
    else
    {
      *(_DWORD *)(result + 48) = result;
      *(_DWORD *)(result + 44) = result;
    }
    return result;
  }
  m_pBlockHeader = this->m_LastAlloc.m_pBlockHeader;
  p_m_LastAlloc = &this->m_LastAlloc;
  if ( m_pBlockHeader != nullptr
    && (m_nIndex = this->m_LastAlloc.m_nIndex) >= 0
    && m_nIndex < m_pBlockHeader->m_nBlockSize )
  {
    v7 = (CUtlFixedMemory<UtlLinkedListElem_t<CShaderManager::ShaderLookup_t,int> >::BlockHeader_t **)CUtlFixedMemory<UtlLinkedListElem_t<CShaderDeviceDx10::GeometryShader_t,int>>::Next((CUtlFixedMemory<UtlLinkedListElem_t<Texture_t,int> > *)this, result: (CUtlFixedMemory<UtlLinkedListElem_t<IDirect3DVertexShader9 *,int> >::Iterator_t *)&v15, it: (const CUtlFixedMemory<UtlLinkedListElem_t<Texture_t,int> >::Iterator_t *)&this->m_LastAlloc);
  }
  else
  {
    if ( this->m_Memory.m_pBlocks != nullptr )
    {
      v14.m_pBlockHeader = (CUtlFixedMemory<UtlLinkedListElem_t<Texture_t,int> >::BlockHeader_t *)this->m_Memory.m_pBlocks;
      v14.m_nIndex = 0;
    }
    else
    {
      v14.m_pBlockHeader = nullptr;
      v14.m_nIndex = -1;
    }
    v15 = v14;
    v7 = (CUtlFixedMemory<UtlLinkedListElem_t<CShaderManager::ShaderLookup_t,int> >::BlockHeader_t **)&v15;
  }
  v8 = *v7;
  v9 = *v7 == nullptr;
  v10 = (int)v7[1];
  if ( v9 || v10 < 0 || v10 >= v8->m_nBlockSize )
  {
    CUtlFixedMemory<UtlLinkedListElem_t<CShaderDeviceDx10::VertexShader_t,int>>::Grow(
      (CUtlFixedMemory<UtlLinkedListElem_t<CShaderDeviceDx10::VertexShader_t,int> > *)this,
      num: 1);
    this->m_pElements = nullptr;
    if ( p_m_LastAlloc->m_pBlockHeader != nullptr
      && (v11 = this->m_LastAlloc.m_nIndex) >= 0
      && v11 < p_m_LastAlloc->m_pBlockHeader->m_nBlockSize )
    {
      v12 = CUtlFixedMemory<UtlLinkedListElem_t<CShaderDeviceDx10::GeometryShader_t,int>>::Next(
              (CUtlFixedMemory<UtlLinkedListElem_t<Texture_t,int> > *)this,
              result: (CUtlFixedMemory<UtlLinkedListElem_t<IDirect3DVertexShader9 *,int> >::Iterator_t *)&v14,
              it: (const CUtlFixedMemory<UtlLinkedListElem_t<Texture_t,int> >::Iterator_t *)&this->m_LastAlloc);
    }
    else
    {
      v12 = CUtlFixedMemory<UtlLinkedListElem_t<CShaderManager::ShaderLookup_t,int>>::First(
              (CUtlFixedMemory<UtlLinkedListElem_t<Texture_t,int> > *)this,
              result: (CUtlFixedMemory<UtlLinkedListElem_t<IDirect3DVertexShader9 *,int> >::Iterator_t *)&v16);
    }
    v8 = (CUtlFixedMemory<UtlLinkedListElem_t<CShaderManager::ShaderLookup_t,int> >::BlockHeader_t *)v12->m_pBlockHeader;
    v9 = v12->m_pBlockHeader == nullptr;
    v10 = v12->m_nIndex;
    if ( v9 || v10 < 0 || v10 >= v8->m_nBlockSize )
    {
      if ( _executeCount_12 < 10 )
      {
        ++_executeCount_12;
        _Warning(a1: "CUtlLinkedList overflow! (exhausted memory allocator)\n");
      }
      return 0;
    }
  }
  if ( (CUtlFixedMemory<UtlLinkedListElem_t<CShaderManager::ShaderLookup_t,int> >::BlockHeader_t *)((char *)v8 + 52 * v10) != (CUtlFixedMemory<UtlLinkedListElem_t<CShaderManager::ShaderLookup_t,int> >::BlockHeader_t *)-8 )
  {
    this->m_LastAlloc.m_nIndex = v10;
    p_m_LastAlloc->m_pBlockHeader = v8;
    if ( v8 != nullptr && (v13 = this->m_LastAlloc.m_nIndex) >= 0 && v13 < v8->m_nBlockSize )
    {
      ++this->m_NumAlloced;
      result = (int)&v8[1] + 52 * v13;
    }
    else
    {
      result = 0;
      ++this->m_NumAlloced;
    }
    goto LABEL_33;
  }
  if ( _executeCount_11 >= 10 )
    return 0;
  ++_executeCount_11;
  _Warning(a1: "CUtlLinkedList overflow! (exhausted index range)\n");
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10036750
// Name: protected: int CUtlLinkedList<struct ShaderFileCache_t,int,1,int,class CUtlFixedMemory<struct UtlLinkedListElem_t<struct ShaderFileCache_t,int>>>::AllocInternal(bool)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<ShaderFileCache_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<ShaderFileCache_t,int>>>::AllocInternal(
        CUtlLinkedList<ShaderFileCache_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<ShaderFileCache_t,int> > > *this,
        bool multilist)
{
  int result; // eax
  CUtlFixedMemory<UtlLinkedListElem_t<ShaderFileCache_t,int> >::BlockHeader_t *m_pBlockHeader; // eax
  CUtlFixedMemory<UtlLinkedListElem_t<ShaderFileCache_t,int> >::Iterator_t *p_m_LastAlloc; // esi
  int m_nIndex; // ecx
  CUtlFixedMemory<UtlLinkedListElem_t<ShaderFileCache_t,int> >::BlockHeader_t **v7; // eax
  CUtlFixedMemory<UtlLinkedListElem_t<ShaderFileCache_t,int> >::BlockHeader_t *v8; // ecx
  bool v9; // zf
  int v10; // eax
  int v11; // ecx
  CUtlFixedMemory<UtlLinkedListElem_t<IDirect3DVertexShader9 *,int> >::Iterator_t *v12; // eax
  int v13; // esi
  CUtlFixedMemory<UtlLinkedListElem_t<Texture_t,int> >::Iterator_t v14; // [esp+Ch] [ebp-18h] BYREF
  CUtlFixedMemory<UtlLinkedListElem_t<Texture_t,int> >::Iterator_t v15; // [esp+14h] [ebp-10h] BYREF
  CUtlFixedMemory<UtlLinkedListElem_t<Texture_t,int> >::Iterator_t v16; // [esp+1Ch] [ebp-8h] BYREF

  result = this->m_FirstFree;
  if ( result != 0 )
  {
    this->m_FirstFree = *(_DWORD *)(result + 128);
LABEL_33:
    if ( multilist )
    {
      *(_DWORD *)(result + 128) = 0;
      *(_DWORD *)(result + 124) = 0;
    }
    else
    {
      *(_DWORD *)(result + 128) = result;
      *(_DWORD *)(result + 124) = result;
    }
    return result;
  }
  m_pBlockHeader = this->m_LastAlloc.m_pBlockHeader;
  p_m_LastAlloc = &this->m_LastAlloc;
  if ( m_pBlockHeader != nullptr
    && (m_nIndex = this->m_LastAlloc.m_nIndex) >= 0
    && m_nIndex < m_pBlockHeader->m_nBlockSize )
  {
    v7 = (CUtlFixedMemory<UtlLinkedListElem_t<ShaderFileCache_t,int> >::BlockHeader_t **)CUtlFixedMemory<UtlLinkedListElem_t<CShaderDeviceDx10::GeometryShader_t,int>>::Next(
                                                                                           (CUtlFixedMemory<UtlLinkedListElem_t<Texture_t,int> > *)this,
                                                                                           result: (CUtlFixedMemory<UtlLinkedListElem_t<IDirect3DVertexShader9 *,int> >::Iterator_t *)&v15,
                                                                                           it: (const CUtlFixedMemory<UtlLinkedListElem_t<Texture_t,int> >::Iterator_t *)&this->m_LastAlloc);
  }
  else
  {
    if ( this->m_Memory.m_pBlocks != nullptr )
    {
      v14.m_pBlockHeader = (CUtlFixedMemory<UtlLinkedListElem_t<Texture_t,int> >::BlockHeader_t *)this->m_Memory.m_pBlocks;
      v14.m_nIndex = 0;
    }
    else
    {
      v14.m_pBlockHeader = nullptr;
      v14.m_nIndex = -1;
    }
    v15 = v14;
    v7 = (CUtlFixedMemory<UtlLinkedListElem_t<ShaderFileCache_t,int> >::BlockHeader_t **)&v15;
  }
  v8 = *v7;
  v9 = *v7 == nullptr;
  v10 = (int)v7[1];
  if ( v9 || v10 < 0 || v10 >= v8->m_nBlockSize )
  {
    CUtlFixedMemory<UtlLinkedListElem_t<ShaderFileCache_t,int>>::Grow(this: &this->m_Memory, num: 1);
    this->m_pElements = nullptr;
    if ( p_m_LastAlloc->m_pBlockHeader != nullptr
      && (v11 = this->m_LastAlloc.m_nIndex) >= 0
      && v11 < p_m_LastAlloc->m_pBlockHeader->m_nBlockSize )
    {
      v12 = CUtlFixedMemory<UtlLinkedListElem_t<CShaderDeviceDx10::GeometryShader_t,int>>::Next(
              (CUtlFixedMemory<UtlLinkedListElem_t<Texture_t,int> > *)this,
              result: (CUtlFixedMemory<UtlLinkedListElem_t<IDirect3DVertexShader9 *,int> >::Iterator_t *)&v14,
              it: (const CUtlFixedMemory<UtlLinkedListElem_t<Texture_t,int> >::Iterator_t *)&this->m_LastAlloc);
    }
    else
    {
      v12 = CUtlFixedMemory<UtlLinkedListElem_t<CShaderManager::ShaderLookup_t,int>>::First(
              (CUtlFixedMemory<UtlLinkedListElem_t<Texture_t,int> > *)this,
              result: (CUtlFixedMemory<UtlLinkedListElem_t<IDirect3DVertexShader9 *,int> >::Iterator_t *)&v16);
    }
    v8 = (CUtlFixedMemory<UtlLinkedListElem_t<ShaderFileCache_t,int> >::BlockHeader_t *)v12->m_pBlockHeader;
    v9 = v12->m_pBlockHeader == nullptr;
    v10 = v12->m_nIndex;
    if ( v9 || v10 < 0 || v10 >= v8->m_nBlockSize )
    {
      if ( _executeCount_14 < 10 )
      {
        ++_executeCount_14;
        _Warning(a1: "CUtlLinkedList overflow! (exhausted memory allocator)\n");
      }
      return 0;
    }
  }
  if ( (CUtlFixedMemory<UtlLinkedListElem_t<ShaderFileCache_t,int> >::BlockHeader_t *)((char *)v8 + 132 * v10) != (CUtlFixedMemory<UtlLinkedListElem_t<ShaderFileCache_t,int> >::BlockHeader_t *)-8 )
  {
    this->m_LastAlloc.m_nIndex = v10;
    p_m_LastAlloc->m_pBlockHeader = v8;
    if ( v8 != nullptr && (v13 = this->m_LastAlloc.m_nIndex) >= 0 && v13 < v8->m_nBlockSize )
    {
      ++this->m_NumAlloced;
      result = (int)&v8[1] + 132 * v13;
    }
    else
    {
      result = 0;
      ++this->m_NumAlloced;
    }
    goto LABEL_33;
  }
  if ( _executeCount_13 >= 10 )
    return 0;
  ++_executeCount_13;
  _Warning(a1: "CUtlLinkedList overflow! (exhausted index range)\n");
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x100368E0
// Name: public: virtual void CShaderManager::ClearVertexAndPixelShaderRefCounts(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderManager::ClearVertexAndPixelShaderRefCounts(CShaderManager *this)
{
  int i; // eax
  int j; // eax

  for ( i = this->m_VertexShaderDict.m_Head; i != 0; i = *(_DWORD *)(i + 48) )
    *(_DWORD *)(i + 28) = 0;
  for ( j = this->m_PixelShaderDict.m_Head; j != 0; j = *(_DWORD *)(j + 48) )
    *(_DWORD *)(j + 28) = 0;
}

//------------------------------------------------------------------------------
// Address: 0x10036910
// Name: public: void CShaderManager::SpewVertexAndPixelShaders(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderManager::SpewVertexAndPixelShaders(CShaderManager *this)
{
  CShaderManager *v1; // ebx
  int m_Head; // esi
  int v3; // ebp
  const char *v4; // eax
  int v5; // esi
  int v6; // ebp
  CUtlSymbolTable *p_m_ShaderSymbolTable; // ebx
  const char *v8; // eax
  int v9; // esi
  int v10; // ebx
  const char *v11; // eax
  int totalPixelShaderSets; // [esp+14h] [ebp-Ch]
  int i; // [esp+18h] [ebp-8h]

  v1 = this;
  _Msg(a1: "\nShader File Cache:\n");
  m_Head = v1->m_ShaderFileCache.m_Head;
  if ( m_Head != 0 )
  {
    do
    {
      if ( *(int *)(m_Head + 4) >= 5 )
        v3 = *(_DWORD *)(m_Head + 24);
      else
        v3 = 0;
      v4 = CUtlSymbolTable::String(this: &v1->m_ShaderSymbolTable, id: *(CUtlSymbol *)(m_Head + 2));
      _Msg(
        a1: "Total Combos:%9d Static:%9d Dynamic:%7d SeekTable:%7d Ver:%d '%s'\n",
        *(_DWORD *)(m_Head + 8),
        *(_DWORD *)(m_Head + 8) / *(_DWORD *)(m_Head + 12),
        *(_DWORD *)(m_Head + 12),
        v3,
        *(_DWORD *)(m_Head + 4),
        v4);
      m_Head = *(_DWORD *)(m_Head + 128);
    }
    while ( m_Head != 0 );
    v1 = this;
  }
  _Msg(a1: "\n");
  v5 = v1->m_VertexShaderDict.m_Head;
  v6 = 0;
  totalPixelShaderSets = 0;
  if ( v5 != 0 )
  {
    p_m_ShaderSymbolTable = &v1->m_ShaderSymbolTable;
    do
    {
      v8 = CUtlSymbolTable::String(this: p_m_ShaderSymbolTable, id: *(CUtlSymbol *)v5);
      _Msg(
        a1: "vsh 0x%8.8x: static combo:%9d dynamic combos:%6d refcount:%4d \"%s\"\n",
        v5,
        *(_DWORD *)(v5 + 4),
        *(_DWORD *)(v5 + 12),
        *(_DWORD *)(v5 + 28),
        v8);
      v6 += *(_DWORD *)(v5 + 12);
      v5 = *(_DWORD *)(v5 + 48);
      ++totalPixelShaderSets;
    }
    while ( v5 != 0 );
  }
  v9 = this->m_PixelShaderDict.m_Head;
  v10 = 0;
  for ( i = 0; v9 != 0; ++i )
  {
    v11 = CUtlSymbolTable::String(this: &this->m_ShaderSymbolTable, id: *(CUtlSymbol *)v9);
    _Msg(
      a1: "psh 0x%8.8x: static combo:%9d dynamic combos:%6d refcount:%4d \"%s\"\n",
      v9,
      *(_DWORD *)(v9 + 4),
      *(_DWORD *)(v9 + 12),
      *(_DWORD *)(v9 + 28),
      v11);
    v10 += *(_DWORD *)(v9 + 12);
    v9 = *(_DWORD *)(v9 + 48);
  }
  _Msg(a1: "Total unique vertex shaders: %d\n", v6);
  _Msg(a1: "Total vertex shader sets: %d\n", totalPixelShaderSets);
  _Msg(a1: "Total unique pixel shaders: %d\n", v10);
  _Msg(a1: "Total pixel shader sets: %d\n", i);
}

//------------------------------------------------------------------------------
// Address: 0x10036A70
// Name: mat_spewvertexandpixelshaders
// Source: json
//------------------------------------------------------------------------------
void __cdecl mat_spewvertexandpixelshaders()
{
  CShaderManager::SpewVertexAndPixelShaders(this: (CShaderManager *)g_pShaderManager);
}

//------------------------------------------------------------------------------
// Address: 0x10036A80
// Name: public: void CUtlLinkedList<struct IDirect3DPixelShader9 __near *,int,1,int,class CUtlFixedMemory<struct UtlLinkedListElem_t<struct IDirect3DPixelShader9 __near *,int>>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<IDirect3DPixelShader9 *,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<IDirect3DPixelShader9 *,int>>>::RemoveAll(
        CUtlLinkedList<IDirect3DPixelShader9 *,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<IDirect3DPixelShader9 *,int> > > *this)
{
  void *i; // eax
  CUtlFixedMemory<UtlLinkedListElem_t<IDirect3DPixelShader9 *,int> >::BlockHeader_t *v3; // ebx
  bool v4; // zf
  int v5; // edi
  CUtlFixedMemory<UtlLinkedListElem_t<IDirect3DPixelShader9 *,int> >::Iterator_t it; // [esp+10h] [ebp-10h] BYREF
  CUtlFixedMemory<UtlLinkedListElem_t<Texture_t,int> >::Iterator_t result; // [esp+18h] [ebp-8h] BYREF

  if ( this->m_LastAlloc.m_pBlockHeader != nullptr || this->m_LastAlloc.m_nIndex != -1 )
  {
    if ( this->m_Memory.m_pBlocks != nullptr )
    {
      result.m_pBlockHeader = (CUtlFixedMemory<UtlLinkedListElem_t<Texture_t,int> >::BlockHeader_t *)this->m_Memory.m_pBlocks;
      result.m_nIndex = 0;
    }
    else
    {
      result.m_pBlockHeader = nullptr;
      result.m_nIndex = -1;
    }
    for ( i = &result;
          ;
          i = CUtlFixedMemory<UtlLinkedListElem_t<CShaderDeviceDx10::GeometryShader_t,int>>::Next(
                (CUtlFixedMemory<UtlLinkedListElem_t<Texture_t,int> > *)this,
                (CUtlFixedMemory<UtlLinkedListElem_t<IDirect3DVertexShader9 *,int> >::Iterator_t *)&result,
                (const CUtlFixedMemory<UtlLinkedListElem_t<Texture_t,int> >::Iterator_t *)&it) )
    {
      v3 = *(CUtlFixedMemory<UtlLinkedListElem_t<IDirect3DPixelShader9 *,int> >::BlockHeader_t **)i;
      v4 = *(_DWORD *)i == 0;
      v5 = *((_DWORD *)i + 1);
      it.m_nIndex = v5;
      it.m_pBlockHeader = v3;
      if ( v4 )
      {
        if ( v5 == -1 )
          break;
      }
      else if ( v5 >= 0
             && v5 < v3->m_nBlockSize
             && (CUtlFixedMemory<UtlLinkedListElem_t<IDirect3DPixelShader9 *,int> >::BlockHeader_t *)((char *)v3 + 12 * v5) != (CUtlFixedMemory<UtlLinkedListElem_t<IDirect3DPixelShader9 *,int> >::BlockHeader_t *)-8
             && !CUtlFixedMemory<UtlLinkedListElem_t<IDirect3DPixelShader9 *,int>>::IsIdxAfter(
                   this: &this->m_Memory,
                   i: (unsigned int)&v3[1] + 12 * v5,
                   it: &this->m_LastAlloc)
             && (*((CUtlFixedMemory<UtlLinkedListElem_t<IDirect3DPixelShader9 *,int> >::BlockHeader_t **)&v3[1].m_nBlockSize
                 + 3 * v5) != (CUtlFixedMemory<UtlLinkedListElem_t<IDirect3DPixelShader9 *,int> >::BlockHeader_t *)((char *)&v3[1] + 12 * v5)
              || *(&v3[2].m_pNext + 3 * v5) == (CUtlFixedMemory<UtlLinkedListElem_t<IDirect3DPixelShader9 *,int> >::BlockHeader_t *)((char *)&v3[1] + 12 * v5)) )
      {
        *(&v3[1].m_nBlockSize + 3 * v5) = (int)v3 + 12 * v5 + 8;
        *((_DWORD *)&v3[2].m_pNext + 3 * v5) = this->m_FirstFree;
        this->m_FirstFree = (int)&v3[1] + 12 * v5;
      }
      if ( v3 == this->m_LastAlloc.m_pBlockHeader && v5 == this->m_LastAlloc.m_nIndex )
        break;
    }
    this->m_Head = 0;
    this->m_Tail = 0;
    this->m_ElementCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10036B50
// Name: public: void CUtlLinkedList<struct CShaderManager::ShaderLookup_t,int,1,int,class CUtlFixedMemory<struct UtlLinkedListElem_t<struct CShaderManager::ShaderLookup_t,int>>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CShaderManager::ShaderLookup_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CShaderManager::ShaderLookup_t,int>>>::RemoveAll(
        CUtlLinkedList<CShaderManager::ShaderLookup_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CShaderManager::ShaderLookup_t,int> > > *this)
{
  void *i; // eax
  CUtlFixedMemory<UtlLinkedListElem_t<CShaderManager::ShaderLookup_t,int> >::BlockHeader_t *v3; // edi
  bool v4; // zf
  int v5; // ebx
  CUtlFixedMemory<UtlLinkedListElem_t<CShaderManager::ShaderLookup_t,int> >::Iterator_t it; // [esp+10h] [ebp-10h] BYREF
  CUtlFixedMemory<UtlLinkedListElem_t<Texture_t,int> >::Iterator_t result; // [esp+18h] [ebp-8h] BYREF

  if ( this->m_LastAlloc.m_pBlockHeader != nullptr || this->m_LastAlloc.m_nIndex != -1 )
  {
    if ( this->m_Memory.m_pBlocks != nullptr )
    {
      result.m_pBlockHeader = (CUtlFixedMemory<UtlLinkedListElem_t<Texture_t,int> >::BlockHeader_t *)this->m_Memory.m_pBlocks;
      result.m_nIndex = 0;
    }
    else
    {
      result.m_pBlockHeader = nullptr;
      result.m_nIndex = -1;
    }
    for ( i = &result;
          ;
          i = CUtlFixedMemory<UtlLinkedListElem_t<CShaderDeviceDx10::GeometryShader_t,int>>::Next(
                (CUtlFixedMemory<UtlLinkedListElem_t<Texture_t,int> > *)this,
                (CUtlFixedMemory<UtlLinkedListElem_t<IDirect3DVertexShader9 *,int> >::Iterator_t *)&result,
                (const CUtlFixedMemory<UtlLinkedListElem_t<Texture_t,int> >::Iterator_t *)&it) )
    {
      v3 = *(CUtlFixedMemory<UtlLinkedListElem_t<CShaderManager::ShaderLookup_t,int> >::BlockHeader_t **)i;
      v4 = *(_DWORD *)i == 0;
      v5 = *((_DWORD *)i + 1);
      it.m_nIndex = v5;
      it.m_pBlockHeader = v3;
      if ( v4 )
      {
        if ( v5 == -1 )
          break;
      }
      else if ( v5 >= 0
             && v5 < v3->m_nBlockSize
             && (CUtlFixedMemory<UtlLinkedListElem_t<CShaderManager::ShaderLookup_t,int> >::BlockHeader_t *)((char *)v3 + 52 * v5) != (CUtlFixedMemory<UtlLinkedListElem_t<CShaderManager::ShaderLookup_t,int> >::BlockHeader_t *)-8
             && !CUtlFixedMemory<UtlLinkedListElem_t<CShaderDeviceDx10::VertexShader_t,int>>::IsIdxAfter(
                   (CUtlFixedMemory<UtlLinkedListElem_t<CShaderDeviceDx10::VertexShader_t,int> > *)this,
                   i: (unsigned int)&v3[1] + 52 * v5,
                   it: (const CUtlFixedMemory<UtlLinkedListElem_t<CShaderDeviceDx10::VertexShader_t,int> >::Iterator_t *)&this->m_LastAlloc)
             && (*((CUtlFixedMemory<UtlLinkedListElem_t<CShaderManager::ShaderLookup_t,int> >::BlockHeader_t **)&v3[6].m_nBlockSize
                 + 13 * v5) != (CUtlFixedMemory<UtlLinkedListElem_t<CShaderManager::ShaderLookup_t,int> >::BlockHeader_t *)((char *)&v3[1] + 52 * v5)
              || *(&v3[7].m_pNext + 13 * v5) == (CUtlFixedMemory<UtlLinkedListElem_t<CShaderManager::ShaderLookup_t,int> >::BlockHeader_t *)((char *)&v3[1] + 52 * v5)) )
      {
        *(&v3[6].m_nBlockSize + 13 * v5) = (int)v3 + 52 * v5 + 8;
        *((_DWORD *)&v3[7].m_pNext + 13 * v5) = this->m_FirstFree;
        this->m_FirstFree = (int)&v3[1] + 52 * v5;
      }
      if ( v3 == this->m_LastAlloc.m_pBlockHeader && v5 == this->m_LastAlloc.m_nIndex )
        break;
    }
    this->m_Head = 0;
    this->m_Tail = 0;
    this->m_ElementCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10036C20
// Name: public: void CUtlLinkedList<struct IDirect3DPixelShader9 __near *,int,1,int,class CUtlFixedMemory<struct UtlLinkedListElem_t<struct IDirect3DPixelShader9 __near *,int>>>::Unlink(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<IDirect3DPixelShader9 *,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<IDirect3DPixelShader9 *,int>>>::Unlink(
        CUtlLinkedList<IDirect3DPixelShader9 *,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<IDirect3DPixelShader9 *,int> > > *this,
        unsigned int elem)
{
  int v3; // ecx
  int v4; // eax

  if ( elem != 0
    && !CUtlFixedMemory<UtlLinkedListElem_t<IDirect3DPixelShader9 *,int>>::IsIdxAfter(
          this: &this->m_Memory,
          i: elem,
          it: &this->m_LastAlloc)
    && *(_DWORD *)(elem + 4) != elem )
  {
    v3 = *(_DWORD *)(elem + 4);
    v4 = *(_DWORD *)(elem + 8);
    if ( v3 != 0 )
      *(_DWORD *)(v3 + 8) = v4;
    else
      this->m_Head = v4;
    if ( v4 != 0 )
    {
      *(_DWORD *)(v4 + 4) = v3;
      --this->m_ElementCount;
    }
    else
    {
      --this->m_ElementCount;
      this->m_Tail = v3;
    }
    *(_DWORD *)(elem + 8) = elem;
    *(_DWORD *)(elem + 4) = elem;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10036C80
// Name: public: void CUtlLinkedList<struct ShaderFileCache_t,int,1,int,class CUtlFixedMemory<struct UtlLinkedListElem_t<struct ShaderFileCache_t,int>>>::Unlink(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<ShaderFileCache_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<ShaderFileCache_t,int>>>::Unlink(
        CUtlLinkedList<ShaderFileCache_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<ShaderFileCache_t,int> > > *this,
        unsigned int elem)
{
  int v3; // ecx
  int v4; // eax

  if ( elem != 0
    && !CUtlFixedMemory<UtlLinkedListElem_t<ShaderFileCache_t,int>>::IsIdxAfter(
          this: &this->m_Memory,
          i: elem,
          it: &this->m_LastAlloc)
    && *(_DWORD *)(elem + 124) != elem )
  {
    v3 = *(_DWORD *)(elem + 124);
    v4 = *(_DWORD *)(elem + 128);
    if ( v3 != 0 )
      *(_DWORD *)(v3 + 128) = v4;
    else
      this->m_Head = v4;
    if ( v4 != 0 )
    {
      *(_DWORD *)(v4 + 124) = v3;
      --this->m_ElementCount;
    }
    else
    {
      --this->m_ElementCount;
      this->m_Tail = v3;
    }
    *(_DWORD *)(elem + 128) = elem;
    *(_DWORD *)(elem + 124) = elem;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10036CF0
// Name: public: ShaderFileCache_t::~ShaderFileCache_t(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ShaderFileCache_t::~ShaderFileCache_t(ShaderFileCache_t *this)
{
  CUtlVector<CTransitionTable::ShadowStateDictEntry_t,CUtlMemory<CTransitionTable::ShadowStateDictEntry_t,int>>::~CUtlVector<CTransitionTable::ShadowStateDictEntry_t,CUtlMemory<CTransitionTable::ShadowStateDictEntry_t,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&this->m_StaticComboDupRecords);
  CUtlVector<CTransitionTable::ShadowStateDictEntry_t,CUtlMemory<CTransitionTable::ShadowStateDictEntry_t,int>>::~CUtlVector<CTransitionTable::ShadowStateDictEntry_t,CUtlMemory<CTransitionTable::ShadowStateDictEntry_t,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&this->m_StaticComboRecords);
  if ( this->m_ReferenceCombo.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_ReferenceCombo.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_ReferenceCombo.m_Memory.m_pMemory);
      this->m_ReferenceCombo.m_Memory.m_pMemory = nullptr;
    }
    this->m_ReferenceCombo.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10036D30
// Name: public: CShaderManager::ShaderStaticCombos_t::ShaderCreationData_t::ShaderCreationData_t(void)
// Source: json
//------------------------------------------------------------------------------
CShaderManager::ShaderStaticCombos_t::ShaderCreationData_t *__thiscall CShaderManager::ShaderStaticCombos_t::ShaderCreationData_t::ShaderCreationData_t(
        CShaderManager::ShaderStaticCombos_t::ShaderCreationData_t *this)
{
  this->ByteCode.m_Memory.m_pMemory = nullptr;
  this->ByteCode.m_Memory.m_nAllocationCount = 0;
  this->ByteCode.m_Memory.m_nGrowSize = 0;
  this->ByteCode.m_Size = 0;
  this->ByteCode.m_pElements = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10036D50
// Name: public: void CUtlVector<struct StaticComboAliasRecord_t,class CUtlMemory<struct StaticComboAliasRecord_t,int>>::EnsureCount(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<StaticComboAliasRecord_t,CUtlMemory<StaticComboAliasRecord_t,int>>::EnsureCount(
        CUtlVector<StaticComboAliasRecord_t,CUtlMemory<StaticComboAliasRecord_t,int> > *this,
        int num)
{
  if ( this->m_Size < num )
    CUtlVector<StaticComboAliasRecord_t,CUtlMemory<StaticComboAliasRecord_t,int>>::InsertMultipleBefore(
      this,
      elem: this->m_Size,
      num: num - this->m_Size);
}

//------------------------------------------------------------------------------
// Address: 0x10036D70
// Name: struct ShaderFileCache_t __near * Construct<struct ShaderFileCache_t>(struct ShaderFileCache_t __near *)
// Source: json
//------------------------------------------------------------------------------
ShaderFileCache_t *__cdecl Construct<ShaderFileCache_t>(ShaderFileCache_t *pMemory)
{
  if ( pMemory == nullptr )
    return nullptr;
  pMemory->m_Name.m_Id = -1;
  pMemory->m_Filename.m_Id = -1;
  CUtlBuffer::CUtlBuffer(this: &pMemory->m_ReferenceCombo, growSize: 0, initSize: 0, nFlags: 0);
  pMemory->m_StaticComboRecords.m_Memory.m_pMemory = nullptr;
  pMemory->m_StaticComboRecords.m_Memory.m_nAllocationCount = 0;
  pMemory->m_StaticComboRecords.m_Memory.m_nGrowSize = 0;
  pMemory->m_StaticComboRecords.m_Size = 0;
  pMemory->m_StaticComboRecords.m_pElements = nullptr;
  pMemory->m_StaticComboDupRecords.m_Memory.m_pMemory = nullptr;
  pMemory->m_StaticComboDupRecords.m_Memory.m_nAllocationCount = 0;
  pMemory->m_StaticComboDupRecords.m_Memory.m_nGrowSize = 0;
  pMemory->m_StaticComboDupRecords.m_Size = 0;
  pMemory->m_StaticComboDupRecords.m_pElements = nullptr;
  pMemory->m_Header.m_nVersion = 0;
  return pMemory;
}

//------------------------------------------------------------------------------
// Address: 0x10036E70
// Name: public: virtual void CShaderManager::DestroyVertexShader(struct VertexShaderHandle_t__ __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderManager::DestroyVertexShader(CShaderManager *this, VertexShaderHandle_t__ *hShader)
{
  CUtlFixedLinkedList<IDirect3DVertexShader9 *> *p_m_RawVertexShaderDict; // edi

  if ( hShader != nullptr )
  {
    (*(void (__stdcall **)(_DWORD))(**(_DWORD **)hShader + 8))(a1: *(_DWORD *)hShader);
    p_m_RawVertexShaderDict = &this->m_RawVertexShaderDict;
    CUtlLinkedList<IDirect3DPixelShader9 *,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<IDirect3DPixelShader9 *,int>>>::Unlink(
      this: (CUtlLinkedList<IDirect3DPixelShader9 *,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<IDirect3DPixelShader9 *,int> > > *)p_m_RawVertexShaderDict,
      elem: (unsigned int)hShader);
    hShader[2] = (VertexShaderHandle_t__)p_m_RawVertexShaderDict->m_FirstFree;
    p_m_RawVertexShaderDict->m_FirstFree = (int)hShader;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10036EB0
// Name: public: virtual void CShaderManager::DestroyPixelShader(struct PixelShaderHandle_t__ __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderManager::DestroyPixelShader(CShaderManager *this, PixelShaderHandle_t__ *hShader)
{
  CUtlFixedLinkedList<IDirect3DPixelShader9 *> *p_m_RawPixelShaderDict; // edi

  if ( hShader != nullptr )
  {
    (*(void (__stdcall **)(_DWORD))(**(_DWORD **)hShader + 8))(a1: *(_DWORD *)hShader);
    p_m_RawPixelShaderDict = &this->m_RawPixelShaderDict;
    CUtlLinkedList<IDirect3DPixelShader9 *,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<IDirect3DPixelShader9 *,int>>>::Unlink(
      this: p_m_RawPixelShaderDict,
      elem: (unsigned int)hShader);
    hShader[2] = (PixelShaderHandle_t__)p_m_RawPixelShaderDict->m_FirstFree;
    p_m_RawPixelShaderDict->m_FirstFree = (int)hShader;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10036EF0
// Name: public: bool CShaderManager::CreateDynamicCombos_Ver4(void __near *,unsigned char __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CShaderManager::CreateDynamicCombos_Ver4(
        CShaderManager *this,
        void *pContext,
        unsigned __int8 *pComboBuffer)
{
  ShaderFileCache_t *v4; // edi
  int m_nNumStaticCombos; // eax
  int v6; // esi
  unsigned __int8 *v7; // edx
  void *v8; // esp
  bool v9; // cc
  int v10; // eax
  int v11; // ecx
  int v12; // eax
  int v13; // esi
  unsigned __int8 *v14; // edi
  bool v15; // zf
  CUtlVector<unsigned char,CUtlMemory<unsigned char,int> > *v16; // ecx
  int v17; // esi
  void *D3DVertexShader; // eax
  int v19; // ecx
  int v21; // [esp-4h] [ebp-38h]
  int v22; // [esp+0h] [ebp-34h] BYREF
  CUtlSymbol id[2]; // [esp+Ch] [ebp-28h]
  int nOriginalSize; // [esp+10h] [ebp-24h] BYREF
  int nReferenceComboSizeForDiffs; // [esp+14h] [ebp-20h]
  int i; // [esp+18h] [ebp-1Ch]
  ShaderFileCache_t *pFileCache; // [esp+1Ch] [ebp-18h]
  unsigned __int8 *pReferenceShader; // [esp+20h] [ebp-14h]
  void *hardwareShader; // [esp+24h] [ebp-10h]
  unsigned __int8 *pDiffOutputBuffer; // [esp+28h] [ebp-Ch]
  int nStartingOffset; // [esp+2Ch] [ebp-8h]
  int v32; // [esp+30h] [ebp-4h]
  char bOK_3; // [esp+3Fh] [ebp+Bh]

  v4 = *((ShaderFileCache_t **)pContext + 8);
  m_nNumStaticCombos = v4->m_Header.m_nNumStaticCombos;
  v6 = 0;
  v7 = nullptr;
  *(_DWORD *)&id[0].m_Id = this;
  pFileCache = v4;
  nReferenceComboSizeForDiffs = m_nNumStaticCombos;
  pReferenceShader = nullptr;
  pDiffOutputBuffer = nullptr;
  if ( m_nNumStaticCombos != 0 )
  {
    pReferenceShader = v4->m_ReferenceCombo.m_Memory.m_pMemory;
    v8 = alloca(m_nNumStaticCombos);
    v7 = pReferenceShader;
    pDiffOutputBuffer = (unsigned __int8 *)&v22;
  }
  v9 = v4->m_Header.m_nDynamicCombos <= 0;
  bOK_3 = 1;
  nStartingOffset = 0;
  i = 0;
  if ( !v9 )
  {
    v32 = 0;
    do
    {
      v10 = *((_DWORD *)pContext + 10);
      v11 = *(_DWORD *)(v10 + 8 * v6);
      v12 = v10 + 8 * v6;
      if ( v11 != -1 )
      {
        if ( nStartingOffset == 0 )
          nStartingOffset = v11;
        if ( *(int *)(v12 + 4) > 0 )
        {
          v13 = *(_DWORD *)(v12 + 4);
          v14 = &pComboBuffer[v11 + *((_DWORD *)pContext + 9) - nStartingOffset];
          if ( v7 != nullptr )
          {
            ApplyDiffs(
              OldBlock: v7,
              DiffList: v14,
              OldSize: nReferenceComboSizeForDiffs,
              DiffListSize: v13,
              ResultListSize: &nOriginalSize,
              Output: pDiffOutputBuffer,
              OutSize: nReferenceComboSizeForDiffs);
            v14 = pDiffOutputBuffer;
            v13 = nOriginalSize;
          }
          v15 = *(_BYTE *)(*(_DWORD *)&id[0].m_Id + 296) == 0;
          hardwareShader = nullptr;
          if ( v15 )
          {
            CUtlSymbolTable::String(
              this: (CUtlSymbolTable *)(*(_DWORD *)&id[0].m_Id + 100),
              id: *(CUtlSymbol *)pContext);
            if ( pFileCache->m_bVertexShader )
            {
              D3DVertexShader = (void *)CreateD3DVertexShader(pByteCode: (unsigned int *)v14, a2: v19);
            }
            else
            {
              D3DVertexShader = (void *)CreateD3DPixelShader(
                                          pByteCode: (unsigned int *)v14,
                                          nCentroidMask: pFileCache->m_Header.m_nCentroidMask);
              hardwareShader = D3DVertexShader;
            }
            if ( D3DVertexShader == nullptr )
            {
              bOK_3 = 0;
              break;
            }
          }
          else
          {
            v16 = (CUtlVector<unsigned char,CUtlMemory<unsigned char,int> > *)(v32 + *((_DWORD *)pContext + 5));
            v16->m_Size = 0;
            CUtlVector<unsigned char,CUtlMemory<unsigned char,int>>::InsertMultipleBefore(this: v16, elem: 0, num: v13);
            v21 = v13;
            v17 = v32;
            _V_memcpy(dest: *(void **)(*((_DWORD *)pContext + 5) + v32), src: v14, count: v21);
            if ( pFileCache->m_bVertexShader )
              *(_DWORD *)(*((_DWORD *)pContext + 5) + v17 + 20) = 0;
            else
              *(_DWORD *)(*((_DWORD *)pContext + 5) + v17 + 20) = pFileCache->m_Header.m_nCentroidMask;
            D3DVertexShader = hardwareShader;
          }
          v4 = pFileCache;
          v6 = i;
          *(_DWORD *)(*((_DWORD *)pContext + 4) + 4 * i) = D3DVertexShader;
          v7 = pReferenceShader;
        }
      }
      v32 += 24;
      v9 = ++v6 < v4->m_Header.m_nDynamicCombos;
      i = v6;
    }
    while ( v9 );
  }
  free(pMem: *((void **)pContext + 10));
  *((_DWORD *)pContext + 10) = 0;
  return bOK_3;
}

//------------------------------------------------------------------------------
// Address: 0x10037080
// Name: public: bool CShaderManager::CreateDynamicCombos_Ver5(void __near *,unsigned char __near *,char __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CShaderManager::CreateDynamicCombos_Ver5(
        CShaderManager *this,
        _DWORD *pContext,
        unsigned __int8 *pComboBuffer,
        char *debugLabel)
{
  unsigned int *v4; // ebx
  char *v5; // edi
  unsigned int v6; // esi
  unsigned int v7; // eax
  unsigned int v8; // eax
  int v9; // eax
  ShaderFileCache_t *v10; // eax
  _DWORD *v11; // esi
  int v12; // ebp
  int v13; // ecx
  char *v14; // edi
  ShaderFileCache_t *v15; // edx
  int v16; // ebx
  CUtlMemory<unsigned char,int> *v17; // esi
  int m_nAllocationCount; // eax
  unsigned __int8 *m_pMemory; // ecx
  int v20; // eax
  bool v21; // zf
  int v22; // eax
  unsigned __int8 *D3DPixelShader; // eax
  D3DDeviceWrapper *v24; // esi
  bool v25; // cf
  unsigned __int8 *pCompressedShaders; // [esp+10h] [ebp-24h] BYREF
  void *hardwareShader; // [esp+14h] [ebp-20h]
  int iIndex; // [esp+18h] [ebp-1Ch]
  ShaderFileCache_t *pFileCache; // [esp+1Ch] [ebp-18h] BYREF
  int v31; // [esp+20h] [ebp-14h]
  unsigned __int8 *pUnpackBuffer; // [esp+24h] [ebp-10h] BYREF
  char *v33; // [esp+28h] [ebp-Ch]
  CUtlSymbol id[2]; // [esp+2Ch] [ebp-8h]
  char *v35; // [esp+30h] [ebp-4h]
  char bOK; // [esp+3Ch] [ebp+8h]

  v4 = (unsigned int *)&pComboBuffer[pContext[9]];
  *(_DWORD *)&id[0].m_Id = this;
  v31 = pContext[8];
  v5 = (char *)operator new(nSize: 0x20000u);
  v33 = v5;
  bOK = 1;
  do
  {
    v6 = *v4++;
    hardwareShader = v4;
    if ( v6 == -1 )
      break;
    v7 = v6 & 0xC0000000;
    if ( (v6 & 0xC0000000) != 0 )
    {
      if ( v7 == 0x40000000 )
      {
        v8 = CLZMA::Uncompress(
               this: (CLZMA *)&pCompressedShaders + 3,
               pInput: (unsigned __int8 *)v4,
               pOutput: (unsigned __int8 *)v5,
               pCallback: nullptr);
        v4 = (unsigned int *)((char *)v4 + (v6 & 0x3FFFFFFF));
        v6 = v8;
      }
      else
      {
        if ( v7 != 0x80000000 )
        {
          _Error(a1: " unrecognized shader compression type = file corrupt?");
          bOK = 0;
          goto LABEL_13;
        }
        v6 &= 0x3FFFFFFFu;
        memcpy(dst: (unsigned __int8 *)v5, src: (unsigned __int8 *)v4, count: v6);
        v4 = (unsigned int *)((char *)v4 + v6);
      }
    }
    else
    {
      pFileCache = (ShaderFileCache_t *)0x20000;
      v9 = BZ2_bzBuffToBuffDecompress(
             dest: v5,
             destLen: (unsigned int *)&pFileCache,
             source: (char *)v4,
             sourceLen: v6,
             small: 1,
             verbosity: 0);
      if ( v9 < 0 )
      {
        _Warning(a1: "BZIP Error (%d) decompressing shader", v9);
        bOK = 0;
      }
      v4 = (unsigned int *)((char *)v4 + v6);
      v6 = (unsigned int)pFileCache;
    }
    hardwareShader = v4;
LABEL_13:
    v35 = &v5[v6];
    if ( v5 < &v5[v6] )
    {
      while ( 1 )
      {
        v10 = *(ShaderFileCache_t **)v5;
        v11 = pContext;
        v12 = *((_DWORD *)v5 + 1);
        v13 = pContext[1];
        v14 = v5 + 8;
        v15 = v10;
        iIndex = 0;
        pFileCache = v10;
        if ( (int)v10 >= v13 )
        {
          pFileCache = (ShaderFileCache_t *)((char *)v10 - v13);
          v15 = (ShaderFileCache_t *)((char *)v10 - v13);
        }
        if ( *(_BYTE *)(*(_DWORD *)&id[0].m_Id + 296) != 0 )
        {
          v16 = 24 * (_DWORD)v15;
          v17 = (CUtlMemory<unsigned char,int> *)(24 * (_DWORD)v15 + pContext[5]);
          v17[1].m_pMemory = nullptr;
          if ( v12 != 0 )
          {
            m_nAllocationCount = v17->m_nAllocationCount;
            if ( v12 > m_nAllocationCount )
              CUtlMemory<CTransitionTable::TransitionOp_t,int>::Grow(this: v17, num: v12 - m_nAllocationCount);
            v17[1].m_pMemory += v12;
            m_pMemory = v17->m_pMemory;
            v20 = (int)&v17[1].m_pMemory[-v12];
            v21 = v17[1].m_pMemory == (unsigned __int8 *)v12;
            v17[1].m_nAllocationCount = (int)v17->m_pMemory;
            if ( v20 >= 0 && !v21 && v12 > 0 )
              _V_memmove(dest: &m_pMemory[v12], src: m_pMemory, count: v20);
          }
          _V_memcpy(dest: *(void **)(v16 + pContext[5]), src: v14, count: v12);
          if ( *(_BYTE *)(v31 + 32) != 0 )
            v22 = 0;
          else
            v22 = *(_DWORD *)(v31 + 20);
          *(_DWORD *)(v16 + pContext[5] + 20) = v22;
          v4 = (unsigned int *)hardwareShader;
          D3DPixelShader = (unsigned __int8 *)iIndex;
          v11 = pContext;
        }
        else
        {
          CUtlSymbolTable::String(this: (CUtlSymbolTable *)(*(_DWORD *)&id[0].m_Id + 100), id: *(CUtlSymbol *)pContext);
          if ( *(_BYTE *)(v31 + 32) != 0 )
          {
            if ( r_emulategl.m_pParent->m_Value.m_nValue != 0 )
              D3DXGetShaderVersion(a1: v14);
            v24 = Dx9Device();
            D3DDeviceWrapper::Synchronize(this: v24);
            if ( v24->m_pD3DDevice->CreateVertexShader(
                   this: v24->m_pD3DDevice,
                   a2: (const unsigned int *)v14,
                   a3: (IDirect3DVertexShader9 **)&pUnpackBuffer) >= 0 )
            {
              ++s_NumVertexShadersCreated;
              D3DPixelShader = pUnpackBuffer;
              v11 = pContext;
            }
            else
            {
              v11 = pContext;
              pUnpackBuffer = nullptr;
              D3DPixelShader = nullptr;
            }
          }
          else
          {
            D3DPixelShader = (unsigned __int8 *)CreateD3DPixelShader(
                                                  pByteCode: (unsigned int *)v14,
                                                  nCentroidMask: *(_DWORD *)(v31 + 20));
            iIndex = (int)D3DPixelShader;
          }
          if ( D3DPixelShader == nullptr )
          {
            _Warning(a1: "failed to create shader\n");
            v5 = v33;
            bOK = 0;
            goto LABEL_41;
          }
          ++v11[3];
        }
        v5 = &v14[v12];
        v25 = v5 < v35;
        *(_DWORD *)(v11[4] + 4 * (_DWORD)pFileCache) = D3DPixelShader;
        if ( !v25 )
        {
          v5 = v33;
          break;
        }
      }
    }
  }
  while ( bOK != 0 );
LABEL_41:
  free(pMem: v5);
  return bOK;
}

//------------------------------------------------------------------------------
// Address: 0x10037320
// Name: private: void CShaderManager::DestroyVertexShader(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderManager::DestroyVertexShader(CShaderManager *this, int shader)
{
  int i; // edi
  int v4; // eax
  bool v5; // zf
  _DWORD *v6; // eax
  CShaderManager::ShaderStaticCombos_t::ShaderCreationData_t *v7; // ecx
  int v8; // eax
  int v9; // eax

  for ( i = 0; i < *(_DWORD *)(shader + 8); ++i )
  {
    v4 = *(_DWORD *)(shader + 16);
    v5 = *(_DWORD *)(v4 + 4 * i) == 0;
    v6 = (_DWORD *)(v4 + 4 * i);
    if ( !v5 )
      (*(void (__stdcall **)(_DWORD))(*(_DWORD *)*v6 + 8))(a1: *v6);
  }
  free(pMem: *(void **)(shader + 16));
  v7 = *(CShaderManager::ShaderStaticCombos_t::ShaderCreationData_t **)(shader + 20);
  *(_DWORD *)(shader + 16) = 0;
  if ( v7 != nullptr )
  {
    CShaderManager::ShaderStaticCombos_t::ShaderCreationData_t::`vector deleting destructor'(this: v7, a2: 3u);
    *(_DWORD *)(shader + 20) = 0;
  }
  if ( shader != 0
    && !CUtlFixedMemory<UtlLinkedListElem_t<CShaderDeviceDx10::VertexShader_t,int>>::IsIdxAfter(
          this: (CUtlFixedMemory<UtlLinkedListElem_t<CShaderDeviceDx10::VertexShader_t,int> > *)&this->m_VertexShaderDict,
          i: shader,
          it: (const CUtlFixedMemory<UtlLinkedListElem_t<CShaderDeviceDx10::VertexShader_t,int> >::Iterator_t *)&this->m_VertexShaderDict.m_LastAlloc) )
  {
    v8 = *(_DWORD *)(shader + 44);
    if ( v8 != shader )
    {
      if ( v8 != 0 )
        *(_DWORD *)(v8 + 48) = *(_DWORD *)(shader + 48);
      else
        this->m_VertexShaderDict.m_Head = *(_DWORD *)(shader + 48);
      v9 = *(_DWORD *)(shader + 48);
      if ( v9 != 0 )
        *(_DWORD *)(v9 + 44) = *(_DWORD *)(shader + 44);
      else
        this->m_VertexShaderDict.m_Tail = *(_DWORD *)(shader + 44);
      *(_DWORD *)(shader + 48) = shader;
      *(_DWORD *)(shader + 44) = shader;
      --this->m_VertexShaderDict.m_ElementCount;
    }
  }
  *(_DWORD *)(shader + 48) = this->m_VertexShaderDict.m_FirstFree;
  this->m_VertexShaderDict.m_FirstFree = shader;
}

//------------------------------------------------------------------------------
// Address: 0x100373E0
// Name: private: void CShaderManager::DestroyPixelShader(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderManager::DestroyPixelShader(CShaderManager *this, int pixelShader)
{
  int i; // edi
  int v4; // eax
  bool v5; // zf
  _DWORD *v6; // eax
  CShaderManager::ShaderStaticCombos_t::ShaderCreationData_t *v7; // ecx
  int v8; // eax
  int v9; // eax

  for ( i = 0; i < *(_DWORD *)(pixelShader + 8); ++i )
  {
    v4 = *(_DWORD *)(pixelShader + 16);
    v5 = *(_DWORD *)(v4 + 4 * i) == 0;
    v6 = (_DWORD *)(v4 + 4 * i);
    if ( !v5 )
      (*(void (__stdcall **)(_DWORD))(*(_DWORD *)*v6 + 8))(a1: *v6);
  }
  free(pMem: *(void **)(pixelShader + 16));
  v7 = *(CShaderManager::ShaderStaticCombos_t::ShaderCreationData_t **)(pixelShader + 20);
  *(_DWORD *)(pixelShader + 16) = 0;
  if ( v7 != nullptr )
  {
    CShaderManager::ShaderStaticCombos_t::ShaderCreationData_t::`vector deleting destructor'(this: v7, a2: 3u);
    *(_DWORD *)(pixelShader + 20) = 0;
  }
  if ( pixelShader != 0
    && !CUtlFixedMemory<UtlLinkedListElem_t<CShaderDeviceDx10::VertexShader_t,int>>::IsIdxAfter(
          this: (CUtlFixedMemory<UtlLinkedListElem_t<CShaderDeviceDx10::VertexShader_t,int> > *)&this->m_PixelShaderDict,
          i: pixelShader,
          it: (const CUtlFixedMemory<UtlLinkedListElem_t<CShaderDeviceDx10::VertexShader_t,int> >::Iterator_t *)&this->m_PixelShaderDict.m_LastAlloc) )
  {
    v8 = *(_DWORD *)(pixelShader + 44);
    if ( v8 != pixelShader )
    {
      if ( v8 != 0 )
        *(_DWORD *)(v8 + 48) = *(_DWORD *)(pixelShader + 48);
      else
        this->m_PixelShaderDict.m_Head = *(_DWORD *)(pixelShader + 48);
      v9 = *(_DWORD *)(pixelShader + 48);
      if ( v9 != 0 )
        *(_DWORD *)(v9 + 44) = *(_DWORD *)(pixelShader + 44);
      else
        this->m_PixelShaderDict.m_Tail = *(_DWORD *)(pixelShader + 44);
      *(_DWORD *)(pixelShader + 48) = pixelShader;
      *(_DWORD *)(pixelShader + 44) = pixelShader;
      --this->m_PixelShaderDict.m_ElementCount;
    }
  }
  *(_DWORD *)(pixelShader + 48) = this->m_PixelShaderDict.m_FirstFree;
  this->m_PixelShaderDict.m_FirstFree = pixelShader;
}

//------------------------------------------------------------------------------
// Address: 0x100374A0
// Name: public: int CUtlLinkedList<struct IDirect3DVertexShader9 __near *,int,1,int,class CUtlFixedMemory<struct UtlLinkedListElem_t<struct IDirect3DVertexShader9 __near *,int>>>::AddToTail(struct IDirect3DVertexShader9 __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CUtlLinkedList<IDirect3DVertexShader9 *,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<IDirect3DVertexShader9 *,int>>>::AddToTail(
        CUtlLinkedList<IDirect3DVertexShader9 *,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<IDirect3DVertexShader9 *,int> > > *this,
        IDirect3DVertexShader9 *const *src)
{
  unsigned int result; // eax
  int v4; // esi
  int m_Tail; // eax

  result = CUtlLinkedList<IDirect3DVertexShader9 *,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<IDirect3DVertexShader9 *,int>>>::AllocInternal(
             this,
             multilist: false);
  v4 = result;
  if ( result != 0 )
  {
    CUtlLinkedList<IDirect3DPixelShader9 *,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<IDirect3DPixelShader9 *,int>>>::Unlink(
      (CUtlLinkedList<IDirect3DPixelShader9 *,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<IDirect3DPixelShader9 *,int> > > *)this,
      elem: result);
    *(_DWORD *)(v4 + 8) = 0;
    m_Tail = this->m_Tail;
    *(_DWORD *)(v4 + 4) = m_Tail;
    this->m_Tail = v4;
    if ( m_Tail != 0 )
    {
      *(_DWORD *)(m_Tail + 8) = v4;
      ++this->m_ElementCount;
    }
    else
    {
      ++this->m_ElementCount;
      this->m_Head = v4;
    }
    *(IDirect3DVertexShader9 **)v4 = *src;
    return v4;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10037500
// Name: public: int CUtlLinkedList<struct IDirect3DPixelShader9 __near *,int,1,int,class CUtlFixedMemory<struct UtlLinkedListElem_t<struct IDirect3DPixelShader9 __near *,int>>>::AddToTail(struct IDirect3DPixelShader9 __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CUtlLinkedList<IDirect3DPixelShader9 *,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<IDirect3DPixelShader9 *,int>>>::AddToTail(
        CUtlLinkedList<IDirect3DPixelShader9 *,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<IDirect3DPixelShader9 *,int> > > *this,
        IDirect3DPixelShader9 *const *src)
{
  unsigned int result; // eax
  int v4; // esi
  int m_Tail; // eax

  result = CUtlLinkedList<IDirect3DPixelShader9 *,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<IDirect3DPixelShader9 *,int>>>::AllocInternal(
             this,
             multilist: false);
  v4 = result;
  if ( result != 0 )
  {
    CUtlLinkedList<IDirect3DPixelShader9 *,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<IDirect3DPixelShader9 *,int>>>::Unlink(
      this,
      elem: result);
    *(_DWORD *)(v4 + 8) = 0;
    m_Tail = this->m_Tail;
    *(_DWORD *)(v4 + 4) = m_Tail;
    this->m_Tail = v4;
    if ( m_Tail != 0 )
    {
      *(_DWORD *)(m_Tail + 8) = v4;
      ++this->m_ElementCount;
    }
    else
    {
      ++this->m_ElementCount;
      this->m_Head = v4;
    }
    *(IDirect3DPixelShader9 **)v4 = *src;
    return v4;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10037560
// Name: public: int CUtlLinkedList<struct CShaderManager::ShaderLookup_t,int,1,int,class CUtlFixedMemory<struct UtlLinkedListElem_t<struct CShaderManager::ShaderLookup_t,int>>>::AddToTail(struct CShaderManager::ShaderLookup_t const __near &)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CUtlLinkedList<CShaderManager::ShaderLookup_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CShaderManager::ShaderLookup_t,int>>>::AddToTail(
        CUtlLinkedList<CShaderManager::ShaderLookup_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CShaderManager::ShaderLookup_t,int> > > *this,
        const CShaderManager::ShaderLookup_t *src)
{
  unsigned int result; // eax
  int v4; // esi
  int m_Tail; // eax

  result = CUtlLinkedList<CShaderManager::ShaderLookup_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CShaderManager::ShaderLookup_t,int>>>::AllocInternal(
             this,
             multilist: false);
  v4 = result;
  if ( result != 0 )
  {
    CUtlLinkedList<CShaderManager::ShaderLookup_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CShaderManager::ShaderLookup_t,int>>>::Unlink(
      (CUtlLinkedList<CShaderDeviceDx10::VertexShader_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CShaderDeviceDx10::VertexShader_t,int> > > *)this,
      elem: result);
    *(_DWORD *)(v4 + 48) = 0;
    m_Tail = this->m_Tail;
    *(_DWORD *)(v4 + 44) = m_Tail;
    this->m_Tail = v4;
    if ( m_Tail != 0 )
      *(_DWORD *)(m_Tail + 48) = v4;
    else
      this->m_Head = v4;
    ++this->m_ElementCount;
    CopyConstruct<CShaderManager::ShaderLookup_t>(pMemory: (CShaderManager::ShaderLookup_t *)v4, src);
    return v4;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100375C0
// Name: public: int CUtlLinkedList<struct ShaderFileCache_t,int,1,int,class CUtlFixedMemory<struct UtlLinkedListElem_t<struct ShaderFileCache_t,int>>>::AddToTail(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CUtlLinkedList<ShaderFileCache_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<ShaderFileCache_t,int>>>::AddToTail(
        CUtlLinkedList<ShaderFileCache_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<ShaderFileCache_t,int> > > *this)
{
  unsigned int result; // eax
  int v3; // esi
  int m_Tail; // eax

  result = CUtlLinkedList<ShaderFileCache_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<ShaderFileCache_t,int>>>::AllocInternal(
             this,
             multilist: false);
  v3 = result;
  if ( result != 0 )
  {
    CUtlLinkedList<ShaderFileCache_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<ShaderFileCache_t,int>>>::Unlink(
      this,
      elem: result);
    *(_DWORD *)(v3 + 128) = 0;
    m_Tail = this->m_Tail;
    *(_DWORD *)(v3 + 124) = m_Tail;
    this->m_Tail = v3;
    if ( m_Tail != 0 )
    {
      *(_DWORD *)(m_Tail + 128) = v3;
      ++this->m_ElementCount;
    }
    else
    {
      ++this->m_ElementCount;
      this->m_Head = v3;
    }
    Construct<ShaderFileCache_t>(pMemory: (ShaderFileCache_t *)v3);
    return v3;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10037620
// Name: public: void CUtlLinkedList<struct ShaderFileCache_t,int,1,int,class CUtlFixedMemory<struct UtlLinkedListElem_t<struct ShaderFileCache_t,int>>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<ShaderFileCache_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<ShaderFileCache_t,int>>>::RemoveAll(
        CUtlLinkedList<ShaderFileCache_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<ShaderFileCache_t,int> > > *this)
{
  void *i; // eax
  CUtlFixedMemory<UtlLinkedListElem_t<ShaderFileCache_t,int> >::BlockHeader_t *v3; // edi
  bool v4; // zf
  int v5; // ebx
  CUtlFixedMemory<UtlLinkedListElem_t<ShaderFileCache_t,int> >::Iterator_t it; // [esp+10h] [ebp-10h] BYREF
  CUtlFixedMemory<UtlLinkedListElem_t<Texture_t,int> >::Iterator_t result; // [esp+18h] [ebp-8h] BYREF

  if ( this->m_LastAlloc.m_pBlockHeader != nullptr || this->m_LastAlloc.m_nIndex != -1 )
  {
    if ( this->m_Memory.m_pBlocks != nullptr )
    {
      result.m_pBlockHeader = (CUtlFixedMemory<UtlLinkedListElem_t<Texture_t,int> >::BlockHeader_t *)this->m_Memory.m_pBlocks;
      result.m_nIndex = 0;
    }
    else
    {
      result.m_pBlockHeader = nullptr;
      result.m_nIndex = -1;
    }
    for ( i = &result;
          ;
          i = CUtlFixedMemory<UtlLinkedListElem_t<CShaderDeviceDx10::GeometryShader_t,int>>::Next(
                (CUtlFixedMemory<UtlLinkedListElem_t<Texture_t,int> > *)this,
                (CUtlFixedMemory<UtlLinkedListElem_t<IDirect3DVertexShader9 *,int> >::Iterator_t *)&result,
                (const CUtlFixedMemory<UtlLinkedListElem_t<Texture_t,int> >::Iterator_t *)&it) )
    {
      v3 = *(CUtlFixedMemory<UtlLinkedListElem_t<ShaderFileCache_t,int> >::BlockHeader_t **)i;
      v4 = *(_DWORD *)i == 0;
      v5 = *((_DWORD *)i + 1);
      it.m_nIndex = v5;
      it.m_pBlockHeader = v3;
      if ( v4 )
      {
        if ( v5 == -1 )
          break;
      }
      else if ( v5 >= 0
             && v5 < v3->m_nBlockSize
             && (CUtlFixedMemory<UtlLinkedListElem_t<ShaderFileCache_t,int> >::BlockHeader_t *)((char *)v3 + 132 * v5) != (CUtlFixedMemory<UtlLinkedListElem_t<ShaderFileCache_t,int> >::BlockHeader_t *)-8
             && !CUtlFixedMemory<UtlLinkedListElem_t<ShaderFileCache_t,int>>::IsIdxAfter(
                   this: &this->m_Memory,
                   i: (unsigned int)&v3[1] + 132 * v5,
                   it: &this->m_LastAlloc)
             && (*((CUtlFixedMemory<UtlLinkedListElem_t<ShaderFileCache_t,int> >::BlockHeader_t **)&v3[16].m_nBlockSize
                 + 33 * v5) != (CUtlFixedMemory<UtlLinkedListElem_t<ShaderFileCache_t,int> >::BlockHeader_t *)((char *)&v3[1] + 132 * v5)
              || *(&v3[17].m_pNext + 33 * v5) == (CUtlFixedMemory<UtlLinkedListElem_t<ShaderFileCache_t,int> >::BlockHeader_t *)((char *)&v3[1] + 132 * v5)) )
      {
        CUtlVector<CTransitionTable::ShadowStateDictEntry_t,CUtlMemory<CTransitionTable::ShadowStateDictEntry_t,int>>::~CUtlVector<CTransitionTable::ShadowStateDictEntry_t,CUtlMemory<CTransitionTable::ShadowStateDictEntry_t,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)((char *)&v3[14] + 132 * v5));
        CUtlVector<CTransitionTable::ShadowStateDictEntry_t,CUtlMemory<CTransitionTable::ShadowStateDictEntry_t,int>>::~CUtlVector<CTransitionTable::ShadowStateDictEntry_t,CUtlMemory<CTransitionTable::ShadowStateDictEntry_t,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)(&v3[11].m_nBlockSize + 33 * v5));
        if ( *(&v3[6].m_nBlockSize + 33 * v5) >= 0 )
        {
          if ( *(&v3[5].m_nBlockSize + 33 * v5) != 0 )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *((void **)&v3[5].m_nBlockSize + 33 * v5));
            *(&v3[5].m_nBlockSize + 33 * v5) = 0;
          }
          *((_DWORD *)&v3[6].m_pNext + 33 * v5) = 0;
        }
        *(&v3[16].m_nBlockSize + 33 * v5) = (int)v3 + 132 * v5 + 8;
        *((_DWORD *)&v3[17].m_pNext + 33 * v5) = this->m_FirstFree;
        this->m_FirstFree = (int)&v3[1] + 132 * v5;
      }
      if ( v3 == this->m_LastAlloc.m_pBlockHeader && v5 == this->m_LastAlloc.m_nIndex )
        break;
    }
    this->m_Head = 0;
    this->m_Tail = 0;
    this->m_ElementCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10037740
// Name: public: virtual struct VertexShaderHandle_t__ __near * CShaderManager::CreateVertexShader(class IShaderBuffer __near *)
// Source: json
//------------------------------------------------------------------------------
VertexShaderHandle_t__ *__thiscall CShaderManager::CreateVertexShader(
        CShaderManager *this,
        IShaderBuffer *pShaderBuffer)
{
  const void *(__thiscall *GetBits)(IShaderBuffer *); // edx
  int v4; // ebx
  D3DDeviceWrapper *v5; // edi
  unsigned int (__thiscall *GetSize)(IShaderBuffer *); // edx
  IDirect3DVertexShader9 *src; // [esp+10h] [ebp-4h] BYREF

  GetBits = pShaderBuffer->GetBits;
  src = nullptr;
  v4 = (int)GetBits(this: pShaderBuffer);
  v5 = Dx9Device();
  D3DDeviceWrapper::Synchronize(this: v5);
  if ( v5->m_pD3DDevice->CreateVertexShader(this: v5->m_pD3DDevice, a2: (const unsigned int *)v4, a3: &src) < 0
    || src == nullptr )
  {
    return nullptr;
  }
  GetSize = pShaderBuffer->GetSize;
  ++s_NumVertexShadersCreated;
  GetSize(this: pShaderBuffer);
  pShaderBuffer->GetBits(this: pShaderBuffer);
  return (VertexShaderHandle_t__ *)CUtlLinkedList<IDirect3DVertexShader9 *,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<IDirect3DVertexShader9 *,int>>>::AddToTail(
                                     this: &this->m_RawVertexShaderDict,
                                     &src);
}

//------------------------------------------------------------------------------
// Address: 0x100377D0
// Name: public: virtual struct PixelShaderHandle_t__ __near * CShaderManager::CreatePixelShader(class IShaderBuffer __near *)
// Source: json
//------------------------------------------------------------------------------
PixelShaderHandle_t__ *__thiscall CShaderManager::CreatePixelShader(CShaderManager *this, IShaderBuffer *pShaderBuffer)
{
  const void *(__thiscall *GetBits)(IShaderBuffer *); // edx
  int v4; // ebx
  D3DDeviceWrapper *v5; // edi
  unsigned int (__thiscall *GetSize)(IShaderBuffer *); // edx
  IDirect3DPixelShader9 *src; // [esp+10h] [ebp-4h] BYREF

  GetBits = pShaderBuffer->GetBits;
  src = nullptr;
  v4 = (int)GetBits(this: pShaderBuffer);
  v5 = Dx9Device();
  D3DDeviceWrapper::Synchronize(this: v5);
  if ( v5->m_pD3DDevice->CreatePixelShader(this: v5->m_pD3DDevice, a2: (const unsigned int *)v4, a3: &src) < 0
    || src == nullptr )
  {
    return nullptr;
  }
  GetSize = pShaderBuffer->GetSize;
  ++s_NumPixelShadersCreated;
  GetSize(this: pShaderBuffer);
  pShaderBuffer->GetBits(this: pShaderBuffer);
  return (PixelShaderHandle_t__ *)CUtlLinkedList<IDirect3DPixelShader9 *,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<IDirect3DPixelShader9 *,int>>>::AddToTail(
                                    this: &this->m_RawPixelShaderDict,
                                    &src);
}

//------------------------------------------------------------------------------
// Address: 0x10037860
// Name: private: bool CShaderManager::LoadAndCreateShaders(struct CShaderManager::ShaderLookup_t __near &,bool,char __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CShaderManager::LoadAndCreateShaders(
        CShaderManager *this,
        CShaderManager::ShaderLookup_t *lookup,
        bool bVertexShader,
        char *debugLabel)
{
  unsigned int m_Head; // esi
  unsigned __int16 v6; // ax
  int *v7; // edi
  const char *v8; // eax
  void *Header; // ebp
  const char *v11; // eax
  const char *v12; // eax
  unsigned __int16 v13; // ax
  CUtlSymbolTable *v14; // ecx
  bool v15; // cc
  int v16; // eax
  unsigned int v17; // eax
  int v18; // ecx
  int *v19; // eax
  CShaderManager::ShaderStaticCombos_t::ShaderCreationData_t *v20; // eax
  int i; // eax
  ShaderDictionaryEntry_t *v22; // eax
  int m_nStaticIndex; // ecx
  unsigned int v24; // edx
  int v25; // eax
  ShaderDictionaryEntry_t *m_pComboDictionary; // ecx
  const char *v27; // eax
  void *m_nAllocationCount; // eax
  StaticComboAliasRecord_t *v29; // eax
  int v30; // eax
  int v31; // eax
  const char *v32; // eax
  int v33; // ecx
  unsigned __int8 *v34; // edx
  int v35; // eax
  unsigned int v36; // esi
  unsigned int v37; // eax
  IFileSystem_vtbl *v38; // edx
  CUtlSymbolTable *v39; // eax
  IBaseFileSystem_vtbl *v40; // edx
  char DynamicCombos_Ver5; // al
  void *v42; // eax
  StaticComboAliasRecord_t *v43; // eax
  int v44; // [esp+58h] [ebp-1BCh]
  int v45; // [esp+58h] [ebp-1BCh]
  unsigned __int16 m_Id; // [esp+5Ch] [ebp-1B8h]
  const StaticComboAliasRecord_t *v47; // [esp+5Ch] [ebp-1B8h]
  int nStartingOffset; // [esp+70h] [ebp-1A4h] BYREF
  unsigned __int8 *pOptimalBuffer; // [esp+74h] [ebp-1A0h] BYREF
  CUtlSymbolTable *p_m_ShaderSymbolTable; // [esp+78h] [ebp-19Ch]
  unsigned int nAlignedBytesToRead; // [esp+7Ch] [ebp-198h]
  unsigned int nSizeAlign; // [esp+80h] [ebp-194h]
  ShaderFileCache_t fileCacheLookup; // [esp+84h] [ebp-190h] BYREF
  int nDictionaryOffset; // [esp+100h] [ebp-114h]
  unsigned int nOffsetAlign; // [esp+104h] [ebp-110h]
  unsigned int nBufferAlign; // [esp+108h] [ebp-10Ch] BYREF
  char filename[264]; // [esp+10Ch] [ebp-108h] BYREF

  m_Id = lookup->m_Name.m_Id;
  nAlignedBytesToRead = (unsigned int)this;
  p_m_ShaderSymbolTable = &this->m_ShaderSymbolTable;
  pOptimalBuffer = (unsigned __int8 *)CUtlSymbolTable::String(this: &this->m_ShaderSymbolTable, id: (CUtlSymbol)m_Id);
  fileCacheLookup.m_Header.m_nVersion = -1;
  CUtlBuffer::CUtlBuffer(
    this: (CUtlBuffer *)&fileCacheLookup.m_ReferenceCombo.m_Memory.m_nAllocationCount,
    growSize: 0,
    initSize: 0,
    nFlags: 0);
  m_Head = this->m_ShaderFileCache.m_Head;
  v6 = lookup->m_Name.m_Id;
  memset(&fileCacheLookup.m_StaticComboRecords.m_Memory.m_nAllocationCount, 0, 36);
  nDictionaryOffset = 0;
  fileCacheLookup.m_Header.m_nTotalCombos = 0;
  LOWORD(fileCacheLookup.m_Header.m_nVersion) = v6;
  LOBYTE(fileCacheLookup.m_ReferenceCombo.m_Memory.m_pMemory) = bVertexShader;
  if ( m_Head != 0 )
  {
    while ( *(_WORD *)m_Head != v6 || *(_BYTE *)(m_Head + 32) != bVertexShader )
    {
      m_Head = *(_DWORD *)(m_Head + 128);
      if ( m_Head == 0 )
        goto LABEL_5;
    }
  }
  else
  {
LABEL_5:
    m_Head = CUtlLinkedList<ShaderFileCache_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<ShaderFileCache_t,int>>>::AddToTail(this: &this->m_ShaderFileCache);
  }
  v7 = (int *)(m_Head + 4);
  lookup->m_hShaderFileCache = m_Head;
  if ( *(_DWORD *)(m_Head + 4) != 0 )
  {
    v8 = CUtlSymbolTable::String(this: p_m_ShaderSymbolTable, id: *(CUtlSymbol *)(m_Head + 2));
    Header = CShaderManager::OpenFileAndLoadHeader(
               this: (CShaderManager *)nAlignedBytesToRead,
               pFileName: v8,
               pHeader: nullptr);
    if ( Header == nullptr )
    {
      ShaderFileCache_t::~ShaderFileCache_t(this: (ShaderFileCache_t *)&fileCacheLookup.m_Header);
      return false;
    }
  }
  else
  {
    _V_memset(dest: (void *)(m_Head + 4), fill: 0, count: 28);
    v11 = "vsh";
    if ( !bVertexShader )
      v11 = "psh";
    V_snprintf(pDest: &filename[4], maxLen: 260, pFormat: "shaders\\%s\\%s.vcs", v11, (const char *)pOptimalBuffer);
    Header = CShaderManager::OpenFileAndLoadHeader(
               this: (CShaderManager *)nAlignedBytesToRead,
               pFileName: &filename[4],
               pHeader: (ShaderHeader_t *)(m_Head + 4));
    if ( Header != nullptr )
    {
      lookup->m_Flags |= 1u;
    }
    else
    {
      V_snprintf(pDest: &filename[4], maxLen: 260, pFormat: "shaders\\fxc\\%s.vcs", (const char *)pOptimalBuffer);
      Header = CShaderManager::OpenFileAndLoadHeader(
                 this: (CShaderManager *)nAlignedBytesToRead,
                 pFileName: &filename[4],
                 pHeader: (ShaderHeader_t *)(m_Head + 4));
      if ( Header == nullptr )
      {
        lookup->m_Flags |= 2u;
        v12 = "vertex";
        if ( !bVertexShader )
          v12 = "pixel";
        _Warning(a1: "Couldn't load %s shader %s\n", v12, (const char *)pOptimalBuffer);
        ShaderFileCache_t::~ShaderFileCache_t(this: (ShaderFileCache_t *)&fileCacheLookup.m_Header);
        return false;
      }
    }
    v13 = lookup->m_Name.m_Id;
    lookup->m_Flags = *(_DWORD *)(m_Head + 16);
    v14 = p_m_ShaderSymbolTable;
    *(_WORD *)m_Head = v13;
    *(CUtlSymbol *)(m_Head + 2) = (CUtlSymbol)CUtlSymbolTable::AddString(
                                                this: v14,
                                                result: (CUtlSymbol *)&pOptimalBuffer,
                                                pString: &filename[4])->m_Id;
    v15 = *v7 < 5;
    *(_BYTE *)(m_Head + 32) = bVertexShader;
    v16 = *(_DWORD *)(m_Head + 24);
    if ( v15 )
    {
      nStartingOffset = *(_DWORD *)(m_Head + 24);
      if ( v16 != 0 )
      {
        CUtlBuffer::EnsureCapacity(this: (CUtlBuffer *)(m_Head + 36), num: v16);
        g_pFullFileSystem->Read(
          this: &g_pFullFileSystem->IBaseFileSystem,
          a2: *(void **)(m_Head + 36),
          a3: nStartingOffset,
          a4: Header);
      }
    }
    else
    {
      if ( *(_DWORD *)(m_Head + 96) < v16 )
        CUtlVector<StaticComboAliasRecord_t,CUtlMemory<StaticComboAliasRecord_t,int>>::InsertMultipleBefore(
          this: (CUtlVector<StaticComboAliasRecord_t,CUtlMemory<StaticComboAliasRecord_t,int> > *)(m_Head + 84),
          elem: *(_DWORD *)(m_Head + 96),
          num: v16 - *(_DWORD *)(m_Head + 96));
      g_pFullFileSystem->Read(
        this: &g_pFullFileSystem->IBaseFileSystem,
        a2: *(void **)(m_Head + 84),
        a3: 8 * *(_DWORD *)(m_Head + 24),
        a4: Header);
      if ( *v7 == 6 )
      {
        g_pFullFileSystem->Read(this: &g_pFullFileSystem->IBaseFileSystem, a2: &nStartingOffset, a3: 4, a4: Header);
        if ( nStartingOffset != 0 )
        {
          CUtlVector<StaticComboAliasRecord_t,CUtlMemory<StaticComboAliasRecord_t,int>>::EnsureCount(
            this: (CUtlVector<StaticComboAliasRecord_t,CUtlMemory<StaticComboAliasRecord_t,int> > *)(m_Head + 104),
            num: nStartingOffset);
          g_pFullFileSystem->Read(
            this: &g_pFullFileSystem->IBaseFileSystem,
            a2: *(void **)(m_Head + 104),
            a3: 8 * nStartingOffset,
            a4: Header);
        }
      }
    }
  }
  lookup->m_ShaderStaticCombos.m_nCount = *(_DWORD *)(m_Head + 12);
  lookup->m_ShaderStaticCombos.m_pHardwareShaders = (void **)operator new(nSize: 4 * *(_DWORD *)(m_Head + 12));
  v17 = nAlignedBytesToRead;
  lookup->m_ShaderStaticCombos.m_nNumDynamicCombosAfterSkips = 0;
  if ( *(_BYTE *)(v17 + 296) != 0 )
  {
    nStartingOffset = *(_DWORD *)(m_Head + 12);
    v18 = (24 * (unsigned __int64)(unsigned int)nStartingOffset) >> 32 != 0 ? -1 : 24 * nStartingOffset;
    v19 = (int *)operator new(nSize: __CFADD__(v18, 4) ? -1 : v18 + 4);
    if ( v19 != nullptr )
    {
      v44 = nStartingOffset;
      *v19 = nStartingOffset;
      nStartingOffset = (int)(v19 + 1);
      `vector constructor iterator'(
        __t: v19 + 1,
        __s: 0x18u,
        __n: v44,
        __f: (void *(__thiscall *)(void *))CShaderManager::ShaderStaticCombos_t::ShaderCreationData_t::ShaderCreationData_t);
      v20 = (CShaderManager::ShaderStaticCombos_t::ShaderCreationData_t *)nStartingOffset;
    }
    else
    {
      v20 = nullptr;
    }
    lookup->m_ShaderStaticCombos.m_pCreationData = v20;
  }
  for ( i = 0; i < *(_DWORD *)(m_Head + 12); ++i )
    lookup->m_ShaderStaticCombos.m_pHardwareShaders[i] = nullptr;
  v15 = *v7 < 5;
  pOptimalBuffer = nullptr;
  nStartingOffset = 0;
  if ( v15 )
  {
    nOffsetAlign = *(_DWORD *)(m_Head + 24) + 28;
    v22 = (ShaderDictionaryEntry_t *)operator new(nSize: 8 * *(_DWORD *)(m_Head + 12));
    m_nStaticIndex = lookup->m_nStaticIndex;
    v24 = nOffsetAlign;
    lookup->m_pComboDictionary = v22;
    nSizeAlign = (unsigned int)&g_pFullFileSystem->IBaseFileSystem;
    g_pFullFileSystem->Seek(
      this: &g_pFullFileSystem->IBaseFileSystem,
      a2: Header,
      a3: v24 + 8 * m_nStaticIndex,
      a4: FILESYSTEM_SEEK_HEAD);
    g_pFullFileSystem->Read(
      this: &g_pFullFileSystem->IBaseFileSystem,
      a2: lookup->m_pComboDictionary,
      a3: 8 * *(_DWORD *)(m_Head + 12),
      a4: Header);
    v25 = *(_DWORD *)(m_Head + 12);
    if ( v25 > 0 )
    {
      m_pComboDictionary = lookup->m_pComboDictionary;
      do
      {
        if ( m_pComboDictionary->m_Offset != -1 )
        {
          if ( pOptimalBuffer == nullptr )
            pOptimalBuffer = (unsigned __int8 *)m_pComboDictionary->m_Offset;
          nStartingOffset = m_pComboDictionary->m_Offset + m_pComboDictionary->m_Size;
        }
        ++m_pComboDictionary;
        --v25;
      }
      while ( v25 != 0 );
      if ( pOptimalBuffer != nullptr )
        goto LABEL_70;
    }
    g_pFullFileSystem->Close(this: &g_pFullFileSystem->IBaseFileSystem, a2: Header);
    v27 = CUtlSymbolTable::String(this: p_m_ShaderSymbolTable, id: *(CUtlSymbol *)(m_Head + 2));
    _Warning(a1: "Shader '%s' - All dynamic combos skipped. This is bad!\n", v27);
    m_nAllocationCount = (void *)fileCacheLookup.m_StaticComboDupRecords.m_Memory.m_nAllocationCount;
    fileCacheLookup.m_StaticComboDupRecords.m_pElements = nullptr;
    if ( fileCacheLookup.m_StaticComboDupRecords.m_Size >= 0 )
    {
      if ( fileCacheLookup.m_StaticComboDupRecords.m_Memory.m_nAllocationCount != 0 )
      {
        _g_pMemAlloc->Free_2(
          this: _g_pMemAlloc,
          a2: (void *)fileCacheLookup.m_StaticComboDupRecords.m_Memory.m_nAllocationCount);
        m_nAllocationCount = nullptr;
        fileCacheLookup.m_StaticComboDupRecords.m_Memory.m_nAllocationCount = 0;
      }
      fileCacheLookup.m_StaticComboDupRecords.m_Memory.m_nGrowSize = 0;
    }
    nDictionaryOffset = (int)m_nAllocationCount;
    if ( fileCacheLookup.m_StaticComboDupRecords.m_Size >= 0 )
    {
      if ( m_nAllocationCount != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_nAllocationCount);
        fileCacheLookup.m_StaticComboDupRecords.m_Memory.m_nAllocationCount = 0;
      }
      fileCacheLookup.m_StaticComboDupRecords.m_Memory.m_nGrowSize = 0;
    }
    v29 = (StaticComboAliasRecord_t *)fileCacheLookup.m_StaticComboRecords.m_Memory.m_nAllocationCount;
    fileCacheLookup.m_StaticComboRecords.m_pElements = nullptr;
    if ( fileCacheLookup.m_StaticComboRecords.m_Size >= 0 )
    {
      if ( fileCacheLookup.m_StaticComboRecords.m_Memory.m_nAllocationCount != 0 )
      {
        _g_pMemAlloc->Free_2(
          this: _g_pMemAlloc,
          a2: (void *)fileCacheLookup.m_StaticComboRecords.m_Memory.m_nAllocationCount);
        v29 = nullptr;
        fileCacheLookup.m_StaticComboRecords.m_Memory.m_nAllocationCount = 0;
      }
      fileCacheLookup.m_StaticComboRecords.m_Memory.m_nGrowSize = 0;
    }
    fileCacheLookup.m_StaticComboDupRecords.m_Memory.m_pMemory = v29;
    if ( fileCacheLookup.m_StaticComboRecords.m_Size >= 0 )
    {
      if ( v29 != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v29);
        fileCacheLookup.m_StaticComboRecords.m_Memory.m_nAllocationCount = 0;
      }
      fileCacheLookup.m_StaticComboRecords.m_Memory.m_nGrowSize = 0;
    }
    if ( fileCacheLookup.m_ReferenceCombo.m_Get >= 0
      && fileCacheLookup.m_ReferenceCombo.m_Memory.m_nAllocationCount != 0 )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)fileCacheLookup.m_ReferenceCombo.m_Memory.m_nAllocationCount);
    }
    return false;
  }
  v47 = *(const StaticComboAliasRecord_t **)(m_Head + 104);
  v45 = *(_DWORD *)(m_Head + 116);
  nStartingOffset = lookup->m_nStaticIndex / *(_DWORD *)(m_Head + 12);
  v30 = BinarySearchCombos<StaticComboAliasRecord_t>(nStaticComboID: nStartingOffset, nCombos: v45, pRecords: v47);
  if ( v30 != -1 )
    nStartingOffset = *(_DWORD *)(*(_DWORD *)(m_Head + 104) + 8 * v30 + 4);
  if ( *v7 >= 5 )
  {
    v31 = BinarySearchCombos<StaticComboAliasRecord_t>(
            nStaticComboID: nStartingOffset,
            nCombos: *(_DWORD *)(m_Head + 24),
            pRecords: *(const StaticComboAliasRecord_t **)(m_Head + 84));
    if ( v31 != -1 )
    {
      v33 = *(_DWORD *)(m_Head + 84);
      v34 = *(unsigned __int8 **)(v33 + 8 * v31 + 4);
      v35 = *(_DWORD *)(v33 + 8 * v31 + 12);
      pOptimalBuffer = v34;
      nStartingOffset = v35;
LABEL_70:
      g_pFullFileSystem->GetOptimalIOConstraints(
        this: g_pFullFileSystem,
        a2: Header,
        a3: &nBufferAlign,
        a4: (unsigned int *)&fileCacheLookup,
        a5: (unsigned int *)filename);
      v36 = (unsigned int)pOptimalBuffer & ~(nBufferAlign - 1);
      v37 = ~(*(_DWORD *)&fileCacheLookup.m_Name.m_Id - 1)
          & (*(_DWORD *)&fileCacheLookup.m_Name.m_Id - v36 + nStartingOffset - 1);
      lookup->m_nDataOffset = (int)&pOptimalBuffer[-v36];
      v38 = g_pFullFileSystem->IAppSystem::__vftable;
      nSizeAlign = v37;
      v39 = (CUtlSymbolTable *)v38->AllocOptimalReadBuffer(this: g_pFullFileSystem, a2: Header, a3: v37, a4: v36);
      v40 = g_pFullFileSystem->IBaseFileSystem::__vftable;
      p_m_ShaderSymbolTable = v39;
      v40->Seek(this: &g_pFullFileSystem->IBaseFileSystem, a2: Header, a3: v36, a4: FILESYSTEM_SEEK_HEAD);
      g_pFullFileSystem->Read(
        this: &g_pFullFileSystem->IBaseFileSystem,
        a2: p_m_ShaderSymbolTable,
        a3: nSizeAlign,
        a4: Header);
      if ( *v7 >= 5 )
        DynamicCombos_Ver5 = CShaderManager::CreateDynamicCombos_Ver5(
                               this: (CShaderManager *)nAlignedBytesToRead,
                               pContext: lookup,
                               pComboBuffer: (unsigned __int8 *)p_m_ShaderSymbolTable,
                               debugLabel);
      else
        DynamicCombos_Ver5 = CShaderManager::CreateDynamicCombos_Ver4(
                               this: (CShaderManager *)nAlignedBytesToRead,
                               pContext: lookup,
                               pComboBuffer: (unsigned __int8 *)p_m_ShaderSymbolTable);
      LOBYTE(pOptimalBuffer) = DynamicCombos_Ver5;
      g_pFullFileSystem->FreeOptimalReadBuffer(this: g_pFullFileSystem, a2: p_m_ShaderSymbolTable);
      g_pFullFileSystem->Close(this: &g_pFullFileSystem->IBaseFileSystem, a2: Header);
      if ( (_BYTE)pOptimalBuffer == 0 )
        lookup->m_Flags |= 2u;
      v42 = (void *)fileCacheLookup.m_StaticComboDupRecords.m_Memory.m_nAllocationCount;
      fileCacheLookup.m_StaticComboDupRecords.m_pElements = nullptr;
      if ( fileCacheLookup.m_StaticComboDupRecords.m_Size >= 0 )
      {
        if ( fileCacheLookup.m_StaticComboDupRecords.m_Memory.m_nAllocationCount != 0 )
        {
          _g_pMemAlloc->Free_2(
            this: _g_pMemAlloc,
            a2: (void *)fileCacheLookup.m_StaticComboDupRecords.m_Memory.m_nAllocationCount);
          v42 = nullptr;
          fileCacheLookup.m_StaticComboDupRecords.m_Memory.m_nAllocationCount = 0;
        }
        fileCacheLookup.m_StaticComboDupRecords.m_Memory.m_nGrowSize = 0;
      }
      nDictionaryOffset = (int)v42;
      if ( fileCacheLookup.m_StaticComboDupRecords.m_Size >= 0 )
      {
        if ( v42 != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v42);
          fileCacheLookup.m_StaticComboDupRecords.m_Memory.m_nAllocationCount = 0;
        }
        fileCacheLookup.m_StaticComboDupRecords.m_Memory.m_nGrowSize = 0;
      }
      v43 = (StaticComboAliasRecord_t *)fileCacheLookup.m_StaticComboRecords.m_Memory.m_nAllocationCount;
      fileCacheLookup.m_StaticComboRecords.m_pElements = nullptr;
      if ( fileCacheLookup.m_StaticComboRecords.m_Size >= 0 )
      {
        if ( fileCacheLookup.m_StaticComboRecords.m_Memory.m_nAllocationCount != 0 )
        {
          _g_pMemAlloc->Free_2(
            this: _g_pMemAlloc,
            a2: (void *)fileCacheLookup.m_StaticComboRecords.m_Memory.m_nAllocationCount);
          v43 = nullptr;
          fileCacheLookup.m_StaticComboRecords.m_Memory.m_nAllocationCount = 0;
        }
        fileCacheLookup.m_StaticComboRecords.m_Memory.m_nGrowSize = 0;
      }
      fileCacheLookup.m_StaticComboDupRecords.m_Memory.m_pMemory = v43;
      if ( fileCacheLookup.m_StaticComboRecords.m_Size >= 0 )
      {
        if ( v43 != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v43);
          fileCacheLookup.m_StaticComboRecords.m_Memory.m_nAllocationCount = 0;
        }
        fileCacheLookup.m_StaticComboRecords.m_Memory.m_nGrowSize = 0;
      }
      if ( fileCacheLookup.m_ReferenceCombo.m_Get >= 0
        && fileCacheLookup.m_ReferenceCombo.m_Memory.m_nAllocationCount != 0 )
      {
        _g_pMemAlloc->Free_2(
          this: _g_pMemAlloc,
          a2: (void *)fileCacheLookup.m_ReferenceCombo.m_Memory.m_nAllocationCount);
      }
      return (char)pOptimalBuffer;
    }
  }
  g_pFullFileSystem->Close(this: &g_pFullFileSystem->IBaseFileSystem, a2: Header);
  lookup->m_Flags |= 2u;
  v32 = CUtlSymbolTable::String(this: p_m_ShaderSymbolTable, id: *(CUtlSymbol *)(m_Head + 2));
  _Warning(
    a1: "Shader '%s' - Couldn't load combo %d of shader (dyn=%d)\n",
    v32,
    lookup->m_nStaticIndex,
    *(_DWORD *)(m_Head + 12));
  CUtlVector<CTransitionTable::ShadowStateDictEntry_t,CUtlMemory<CTransitionTable::ShadowStateDictEntry_t,int>>::~CUtlVector<CTransitionTable::ShadowStateDictEntry_t,CUtlMemory<CTransitionTable::ShadowStateDictEntry_t,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&fileCacheLookup.m_StaticComboDupRecords.m_Memory.m_nAllocationCount);
  CUtlVector<CTransitionTable::ShadowStateDictEntry_t,CUtlMemory<CTransitionTable::ShadowStateDictEntry_t,int>>::~CUtlVector<CTransitionTable::ShadowStateDictEntry_t,CUtlMemory<CTransitionTable::ShadowStateDictEntry_t,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&fileCacheLookup.m_StaticComboRecords.m_Memory.m_nAllocationCount);
  if ( fileCacheLookup.m_ReferenceCombo.m_Get >= 0 && fileCacheLookup.m_ReferenceCombo.m_Memory.m_nAllocationCount != 0 )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)fileCacheLookup.m_ReferenceCombo.m_Memory.m_nAllocationCount);
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x100380D0
// Name: public: virtual int CShaderManager::CreateVertexShader(char const __near *,int,char __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CShaderManager::CreateVertexShader(
        CShaderManager *this,
        const char *pFileName,
        int nStaticVshIndex,
        char *debugLabel)
{
  int result; // eax
  unsigned __int16 m_Id; // cx
  CShaderManager::ShaderLookup_t *v7; // esi
  CShaderManager::ShaderLookup_t lookup; // [esp+4h] [ebp-30h] BYREF
  int v9; // [esp+30h] [ebp-4h]

  if ( pFileName == nullptr )
    return -1;
  memset(&lookup.m_ShaderStaticCombos.m_nNumDynamicCombosAfterSkips, 0, 24);
  v9 = 0;
  m_Id = CUtlSymbolTable::AddString(
           this: &this->m_ShaderSymbolTable,
           result: (CUtlSymbol *)&pFileName,
           pString: pFileName)->m_Id;
  result = this->m_VertexShaderDict.m_Head;
  LOWORD(lookup.m_nStaticIndex) = m_Id;
  lookup.m_ShaderStaticCombos.m_nCount = nStaticVshIndex;
  if ( result != 0 )
  {
    while ( *(_WORD *)result != m_Id || *(_DWORD *)(result + 4) != nStaticVshIndex )
    {
      result = *(_DWORD *)(result + 48);
      if ( result == 0 )
        goto LABEL_7;
    }
    ++*(_DWORD *)(result + 28);
  }
  else
  {
LABEL_7:
    v7 = (CShaderManager::ShaderLookup_t *)CUtlLinkedList<CShaderManager::ShaderLookup_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CShaderManager::ShaderLookup_t,int>>>::AddToTail(
                                             this: &this->m_VertexShaderDict,
                                             src: (const CShaderManager::ShaderLookup_t *)&lookup.m_nStaticIndex);
    if ( !CShaderManager::LoadAndCreateShaders(this, lookup: v7, bVertexShader: true, debugLabel) )
      return -1;
    ++v7->m_nRefCount;
    return (int)v7;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10038190
// Name: public: virtual int CShaderManager::CreatePixelShader(char const __near *,int,char __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CShaderManager::CreatePixelShader(
        CShaderManager *this,
        const char *pFileName,
        int nStaticPshIndex,
        char *debugLabel)
{
  unsigned __int16 m_Id; // cx
  int m_Head; // eax
  CShaderManager::ShaderLookup_t *v8; // ebx
  CShaderManager::ShaderLookup_t lookup; // [esp+4h] [ebp-30h] BYREF
  int v10; // [esp+30h] [ebp-4h]

  if ( pFileName == nullptr )
    return -1;
  memset(&lookup.m_ShaderStaticCombos.m_nNumDynamicCombosAfterSkips, 0, 24);
  v10 = 0;
  m_Id = CUtlSymbolTable::AddString(
           this: &this->m_ShaderSymbolTable,
           result: (CUtlSymbol *)&pFileName,
           pString: pFileName)->m_Id;
  m_Head = this->m_PixelShaderDict.m_Head;
  LOWORD(lookup.m_nStaticIndex) = m_Id;
  lookup.m_ShaderStaticCombos.m_nCount = nStaticPshIndex;
  if ( m_Head != 0 )
  {
    while ( *(_WORD *)m_Head != m_Id || *(_DWORD *)(m_Head + 4) != nStaticPshIndex )
    {
      m_Head = *(_DWORD *)(m_Head + 48);
      if ( m_Head == 0 )
        goto LABEL_7;
    }
    v8 = (CShaderManager::ShaderLookup_t *)m_Head;
  }
  else
  {
LABEL_7:
    v8 = (CShaderManager::ShaderLookup_t *)CUtlLinkedList<CShaderManager::ShaderLookup_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CShaderManager::ShaderLookup_t,int>>>::AddToTail(
                                             this: &this->m_PixelShaderDict,
                                             src: (const CShaderManager::ShaderLookup_t *)&lookup.m_nStaticIndex);
    if ( !CShaderManager::LoadAndCreateShaders(this, lookup: v8, bVertexShader: false, debugLabel) )
      return -1;
  }
  ++v8->m_nRefCount;
  return (int)v8;
}

//------------------------------------------------------------------------------
// Address: 0x10038240
// Name: public: virtual void CShaderManager::PurgeUnusedVertexAndPixelShaders(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderManager::PurgeUnusedVertexAndPixelShaders(CShaderManager *this)
{
  int m_Head; // eax
  int v3; // esi
  int v4; // eax
  int v5; // esi

  m_Head = this->m_VertexShaderDict.m_Head;
  if ( m_Head != 0 )
  {
    do
    {
      v3 = *(_DWORD *)(m_Head + 48);
      if ( *(int *)(m_Head + 28) <= 0 )
        CShaderManager::DestroyVertexShader(this, shader: m_Head);
      m_Head = v3;
    }
    while ( v3 != 0 );
  }
  v4 = this->m_PixelShaderDict.m_Head;
  if ( v4 != 0 )
  {
    do
    {
      v5 = *(_DWORD *)(v4 + 48);
      if ( *(int *)(v4 + 28) <= 0 )
        CShaderManager::DestroyPixelShader(this, pixelShader: v4);
      v4 = v5;
    }
    while ( v5 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10038290
// Name: public: void CUtlLinkedList<struct ShaderFileCache_t,int,1,int,class CUtlFixedMemory<struct UtlLinkedListElem_t<struct ShaderFileCache_t,int>>>::Purge(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<ShaderFileCache_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<ShaderFileCache_t,int>>>::Purge(
        CUtlLinkedList<ShaderFileCache_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<ShaderFileCache_t,int> > > *this)
{
  CUtlFixedMemory<UtlLinkedListElem_t<ShaderFileCache_t,int> >::BlockHeader_t *m_pBlocks; // esi
  CUtlFixedMemory<UtlLinkedListElem_t<ShaderFileCache_t,int> >::BlockHeader_t *v3; // eax

  CUtlLinkedList<ShaderFileCache_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<ShaderFileCache_t,int>>>::RemoveAll(this);
  m_pBlocks = this->m_Memory.m_pBlocks;
  if ( this->m_Memory.m_pBlocks != nullptr )
  {
    do
    {
      v3 = m_pBlocks;
      m_pBlocks = m_pBlocks->m_pNext;
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v3);
    }
    while ( m_pBlocks != nullptr );
    this->m_Memory.m_pBlocks = nullptr;
    this->m_Memory.m_nAllocationCount = 0;
  }
  this->m_FirstFree = 0;
  this->m_NumAlloced = 0;
  this->m_pElements = nullptr;
  this->m_LastAlloc.m_pBlockHeader = nullptr;
  this->m_LastAlloc.m_nIndex = -1;
}

//------------------------------------------------------------------------------
// Address: 0x100382E0
// Name: public: virtual CShaderManager::~CShaderManager(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderManager::~CShaderManager(CShaderManager *this)
{
  CUtlFixedLinkedList<ShaderFileCache_t> *p_m_ShaderFileCache; // edi
  CUtlFixedMemory<UtlLinkedListElem_t<ShaderFileCache_t,int> >::BlockHeader_t *m_pBlocks; // esi
  CUtlFixedMemory<UtlLinkedListElem_t<ShaderFileCache_t,int> >::BlockHeader_t *v4; // eax
  CUtlFixedMemory<UtlLinkedListElem_t<IDirect3DPixelShader9 *,int> >::BlockHeader_t *v5; // esi
  CUtlFixedMemory<UtlLinkedListElem_t<IDirect3DPixelShader9 *,int> >::BlockHeader_t *v6; // eax
  CUtlFixedMemory<UtlLinkedListElem_t<IDirect3DVertexShader9 *,int> >::BlockHeader_t *v7; // esi
  CUtlFixedMemory<UtlLinkedListElem_t<IDirect3DVertexShader9 *,int> >::BlockHeader_t *v8; // eax
  CUtlFixedMemory<UtlLinkedListElem_t<CShaderManager::ShaderLookup_t,int> >::BlockHeader_t *v9; // esi
  CUtlFixedMemory<UtlLinkedListElem_t<CShaderManager::ShaderLookup_t,int> >::BlockHeader_t *v10; // eax
  CUtlFixedMemory<UtlLinkedListElem_t<CShaderManager::ShaderLookup_t,int> >::BlockHeader_t *v11; // esi
  CUtlFixedMemory<UtlLinkedListElem_t<CShaderManager::ShaderLookup_t,int> >::BlockHeader_t *v12; // eax

  p_m_ShaderFileCache = &this->m_ShaderFileCache;
  this->__vftable = (CShaderManager_vtbl *)&CShaderManager::`vftable';
  CUtlLinkedList<ShaderFileCache_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<ShaderFileCache_t,int>>>::RemoveAll(this: &this->m_ShaderFileCache);
  m_pBlocks = p_m_ShaderFileCache->m_Memory.m_pBlocks;
  if ( p_m_ShaderFileCache->m_Memory.m_pBlocks != nullptr )
  {
    do
    {
      v4 = m_pBlocks;
      m_pBlocks = m_pBlocks->m_pNext;
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v4);
    }
    while ( m_pBlocks != nullptr );
    p_m_ShaderFileCache->m_Memory.m_pBlocks = nullptr;
    p_m_ShaderFileCache->m_Memory.m_nAllocationCount = 0;
  }
  CUtlLinkedList<IDirect3DPixelShader9 *,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<IDirect3DPixelShader9 *,int>>>::RemoveAll(this: &this->m_RawPixelShaderDict);
  v5 = this->m_RawPixelShaderDict.m_Memory.m_pBlocks;
  if ( v5 != nullptr )
  {
    do
    {
      v6 = v5;
      v5 = v5->m_pNext;
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v6);
    }
    while ( v5 != nullptr );
    this->m_RawPixelShaderDict.m_Memory.m_pBlocks = nullptr;
    this->m_RawPixelShaderDict.m_Memory.m_nAllocationCount = 0;
  }
  CUtlLinkedList<IDirect3DPixelShader9 *,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<IDirect3DPixelShader9 *,int>>>::RemoveAll(this: (CUtlLinkedList<IDirect3DPixelShader9 *,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<IDirect3DPixelShader9 *,int> > > *)&this->m_RawVertexShaderDict);
  v7 = this->m_RawVertexShaderDict.m_Memory.m_pBlocks;
  if ( v7 != nullptr )
  {
    do
    {
      v8 = v7;
      v7 = v7->m_pNext;
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v8);
    }
    while ( v7 != nullptr );
    this->m_RawVertexShaderDict.m_Memory.m_pBlocks = nullptr;
    this->m_RawVertexShaderDict.m_Memory.m_nAllocationCount = 0;
  }
  CUtlSymbolTable::~CUtlSymbolTable(this: &this->m_ShaderSymbolTable);
  CUtlLinkedList<CShaderManager::ShaderLookup_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CShaderManager::ShaderLookup_t,int>>>::RemoveAll(this: &this->m_PixelShaderDict);
  v9 = this->m_PixelShaderDict.m_Memory.m_pBlocks;
  if ( v9 != nullptr )
  {
    do
    {
      v10 = v9;
      v9 = v9->m_pNext;
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v10);
    }
    while ( v9 != nullptr );
    this->m_PixelShaderDict.m_Memory.m_pBlocks = nullptr;
    this->m_PixelShaderDict.m_Memory.m_nAllocationCount = 0;
  }
  CUtlLinkedList<CShaderManager::ShaderLookup_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CShaderManager::ShaderLookup_t,int>>>::RemoveAll(this: &this->m_VertexShaderDict);
  v11 = this->m_VertexShaderDict.m_Memory.m_pBlocks;
  if ( v11 != nullptr )
  {
    do
    {
      v12 = v11;
      v11 = v11->m_pNext;
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v12);
    }
    while ( v11 != nullptr );
    this->m_VertexShaderDict.m_Memory.m_pBlocks = nullptr;
    this->m_VertexShaderDict.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100383F0
// Name: public: void CShaderManager::DestroyAllShaders(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderManager::DestroyAllShaders(CShaderManager *this)
{
  int m_Head; // eax
  int v3; // edi
  int v4; // eax
  int v5; // edi

  m_Head = this->m_VertexShaderDict.m_Head;
  if ( m_Head != 0 )
  {
    do
    {
      v3 = *(_DWORD *)(m_Head + 48);
      CShaderManager::DestroyVertexShader(this, shader: m_Head);
      m_Head = v3;
    }
    while ( v3 != 0 );
  }
  v4 = this->m_PixelShaderDict.m_Head;
  if ( v4 != 0 )
  {
    do
    {
      v5 = *(_DWORD *)(v4 + 48);
      CShaderManager::DestroyPixelShader(this, pixelShader: v4);
      v4 = v5;
    }
    while ( v5 != 0 );
  }
  CUtlLinkedList<ShaderFileCache_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<ShaderFileCache_t,int>>>::Purge(this: &this->m_ShaderFileCache);
}

//------------------------------------------------------------------------------
// Address: 0x10038440
// Name: public: CShaderManager::CShaderManager(void)
// Source: json
//------------------------------------------------------------------------------
CShaderManager *__thiscall CShaderManager::CShaderManager(CShaderManager *this)
{
  CUtlFixedLinkedList<CShaderManager::ShaderLookup_t> *p_m_VertexShaderDict; // esi

  p_m_VertexShaderDict = &this->m_VertexShaderDict;
  this->__vftable = (CShaderManager_vtbl *)&CShaderManager::`vftable';
  this->m_VertexShaderDict.m_Memory.m_pBlocks = nullptr;
  this->m_VertexShaderDict.m_Memory.m_nAllocationCount = 0;
  this->m_VertexShaderDict.m_Memory.m_nGrowSize = 0;
  CUtlFixedMemory<UtlLinkedListElem_t<CShaderDeviceDx10::VertexShader_t,int>>::Init(
    this: (CUtlFixedMemory<UtlLinkedListElem_t<CShaderDeviceDx10::VertexShader_t,int> > *)&this->m_VertexShaderDict,
    nGrowSize: 32,
    nInitSize: 0);
  p_m_VertexShaderDict->m_LastAlloc.m_pBlockHeader = nullptr;
  p_m_VertexShaderDict->m_LastAlloc.m_nIndex = -1;
  p_m_VertexShaderDict->m_Head = 0;
  p_m_VertexShaderDict->m_Tail = 0;
  p_m_VertexShaderDict->m_FirstFree = 0;
  p_m_VertexShaderDict->m_ElementCount = 0;
  p_m_VertexShaderDict->m_NumAlloced = 0;
  p_m_VertexShaderDict->m_pElements = nullptr;
  this->m_PixelShaderDict.m_Memory.m_pBlocks = nullptr;
  this->m_PixelShaderDict.m_Memory.m_nAllocationCount = 0;
  this->m_PixelShaderDict.m_Memory.m_nGrowSize = 0;
  CUtlFixedMemory<UtlLinkedListElem_t<CShaderDeviceDx10::VertexShader_t,int>>::Init(
    this: (CUtlFixedMemory<UtlLinkedListElem_t<CShaderDeviceDx10::VertexShader_t,int> > *)&this->m_PixelShaderDict,
    nGrowSize: 32,
    nInitSize: 0);
  this->m_PixelShaderDict.m_LastAlloc.m_pBlockHeader = nullptr;
  this->m_PixelShaderDict.m_LastAlloc.m_nIndex = -1;
  this->m_PixelShaderDict.m_Head = 0;
  this->m_PixelShaderDict.m_Tail = 0;
  this->m_PixelShaderDict.m_FirstFree = 0;
  this->m_PixelShaderDict.m_ElementCount = 0;
  this->m_PixelShaderDict.m_NumAlloced = 0;
  this->m_PixelShaderDict.m_pElements = nullptr;
  CUtlSymbolTable::CUtlSymbolTable(this: &this->m_ShaderSymbolTable, growSize: 0, initSize: 32, caseInsensitive: true);
  this->m_RawVertexShaderDict.m_Memory.m_pBlocks = nullptr;
  this->m_RawVertexShaderDict.m_Memory.m_nAllocationCount = 0;
  this->m_RawVertexShaderDict.m_Memory.m_nGrowSize = 0;
  CUtlFixedMemory<UtlLinkedListElem_t<IDirect3DPixelShader9 *,int>>::Init(
    this: (CUtlFixedMemory<UtlLinkedListElem_t<IDirect3DPixelShader9 *,int> > *)&this->m_RawVertexShaderDict,
    nGrowSize: 0,
    nInitSize: 0);
  this->m_RawVertexShaderDict.m_LastAlloc.m_pBlockHeader = nullptr;
  this->m_RawVertexShaderDict.m_LastAlloc.m_nIndex = -1;
  this->m_RawVertexShaderDict.m_Head = 0;
  this->m_RawVertexShaderDict.m_Tail = 0;
  this->m_RawVertexShaderDict.m_FirstFree = 0;
  this->m_RawVertexShaderDict.m_ElementCount = 0;
  this->m_RawVertexShaderDict.m_NumAlloced = 0;
  this->m_RawVertexShaderDict.m_pElements = nullptr;
  this->m_RawPixelShaderDict.m_Memory.m_pBlocks = nullptr;
  this->m_RawPixelShaderDict.m_Memory.m_nAllocationCount = 0;
  this->m_RawPixelShaderDict.m_Memory.m_nGrowSize = 0;
  CUtlFixedMemory<UtlLinkedListElem_t<IDirect3DPixelShader9 *,int>>::Init(
    this: &this->m_RawPixelShaderDict.m_Memory,
    nGrowSize: 0,
    nInitSize: 0);
  this->m_RawPixelShaderDict.m_LastAlloc.m_pBlockHeader = nullptr;
  this->m_RawPixelShaderDict.m_LastAlloc.m_nIndex = -1;
  this->m_RawPixelShaderDict.m_Head = 0;
  this->m_RawPixelShaderDict.m_Tail = 0;
  this->m_RawPixelShaderDict.m_FirstFree = 0;
  this->m_RawPixelShaderDict.m_ElementCount = 0;
  this->m_RawPixelShaderDict.m_NumAlloced = 0;
  this->m_RawPixelShaderDict.m_pElements = nullptr;
  this->m_ShaderFileCache.m_Memory.m_pBlocks = nullptr;
  this->m_ShaderFileCache.m_Memory.m_nAllocationCount = 0;
  this->m_ShaderFileCache.m_Memory.m_nGrowSize = 0;
  CUtlFixedMemory<UtlLinkedListElem_t<ShaderFileCache_t,int>>::Init(
    this: &this->m_ShaderFileCache.m_Memory,
    nGrowSize: 32,
    nInitSize: 0);
  this->m_ShaderFileCache.m_LastAlloc.m_pBlockHeader = nullptr;
  this->m_ShaderFileCache.m_LastAlloc.m_nIndex = -1;
  this->m_ShaderFileCache.m_Head = 0;
  this->m_ShaderFileCache.m_Tail = 0;
  this->m_ShaderFileCache.m_FirstFree = 0;
  this->m_ShaderFileCache.m_ElementCount = 0;
  this->m_ShaderFileCache.m_NumAlloced = 0;
  this->m_ShaderFileCache.m_pElements = nullptr;
  this->m_bCreateShadersOnDemand = false;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10038580
// Name: public: virtual void CShaderManager::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderManager::Shutdown(CShaderManager *this)
{
  CShaderManager::DestroyAllShaders(this);
  if ( s_pIllegalMaterialPS != nullptr )
  {
    (*(void (__stdcall **)(void *))(*(_DWORD *)s_pIllegalMaterialPS + 8))(a1: s_pIllegalMaterialPS);
    s_pIllegalMaterialPS = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003A2C0
// Name: public: void CUtlMemory<class CUtlString,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<CUtlString,int>::Grow(CUtlMemory<CUtlString,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  CUtlString *m_pMemory; // edx
  unsigned int v7; // [esp-4h] [ebp-Ch]

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
    v7 = 16 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (CUtlString *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (CUtlString *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003A450
// Name: public: CUtlVector<struct CTransitionTable::ShadowStateDictEntry_t,class CUtlMemory<struct CTransitionTable::ShadowStateDictEntry_t,int>>::~CUtlVector<struct CTransitionTable::ShadowStateDictEntry_t,class CUtlMemory<struct CTransitionTable::ShadowStateDictEntry_t,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CTransitionTable::ShadowStateDictEntry_t,CUtlMemory<CTransitionTable::ShadowStateDictEntry_t,int>>::~CUtlVector<CTransitionTable::ShadowStateDictEntry_t,CUtlMemory<CTransitionTable::ShadowStateDictEntry_t,int>>(
        CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *this)
{
  bool v2; // sf
  CUtlSymbolTable::StringPool_t **m_pMemory; // eax

  v2 = this->m_Memory.m_nGrowSize < 0;
  this->m_Size = 0;
  if ( !v2 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
  v2 = this->m_Memory.m_nGrowSize < 0;
  m_pMemory = this->m_Memory.m_pMemory;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( !v2 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003A520
// Name: public: int CUtlVector<class CUtlString,class CUtlMemory<class CUtlString,int>>::InsertBefore(int,class CUtlString const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>::InsertBefore(
        CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *this,
        int elem,
        const CUtlString *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CUtlString *m_pMemory; // ecx
  int v7; // eax
  bool v8; // zf
  CUtlString *v9; // ecx

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CUtlString,int>::Grow(this: &this->m_Memory, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  v8 = this->m_Size - elem == 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 >= 0 && !v8 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 16 * v7);
  v9 = &this->m_Memory.m_pMemory[elem];
  if ( v9 != nullptr )
    CUtlString::CUtlString(this: v9, string: src);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x10079D30
// Name: _CShaderManager::SetVertexShaderState_::_7_::_dynamic_atexit_destructor_for___counter__
// Source: json
//------------------------------------------------------------------------------
void __cdecl CShaderManager::SetVertexShaderState_::_7_::_dynamic_atexit_destructor_for___counter__()
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x10079D40
// Name: _CShaderManager::SetPixelShaderState_::_7_::_dynamic_atexit_destructor_for___counter__
// Source: json
//------------------------------------------------------------------------------
void __cdecl CShaderManager::SetPixelShaderState_::_7_::_dynamic_atexit_destructor_for___counter__()
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x10079D50
// Name: _dynamic_atexit_destructor_for__mat_spewvertexandpixelshaders_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_spewvertexandpixelshaders_command__()
{
  ConCommand::~ConCommand(this: &mat_spewvertexandpixelshaders_command);
}

//------------------------------------------------------------------------------
// Address: 0x10079D60
// Name: _dynamic_atexit_destructor_for__mat_shadercount_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_shadercount_command__()
{
  ConCommand::~ConCommand(this: &mat_shadercount_command);
}

//------------------------------------------------------------------------------
// Address: 0x10079D70
// Name: _dynamic_atexit_destructor_for__s_ShaderManager__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_ShaderManager__()
{
  CShaderManager::~CShaderManager(this: &s_ShaderManager);
}

//------------------------------------------------------------------------------
// Address: 0x10079D80
// Name: _dynamic_atexit_destructor_for__s_EmptyConVar__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_EmptyConVar__()
{
  s_EmptyConVar.ConVar::ConCommandBase::__vftable = (CEmptyConVar_vtbl *)&ConVar::`vftable'{for `ConCommandBase'};
  s_EmptyConVar.ConVar::IConVar::__vftable = (IConVar_vtbl *)&ConVar::`vftable'{for `IConVar'};
  if ( s_EmptyConVar.m_Value.m_pszString != nullptr )
  {
    free(pMem: s_EmptyConVar.m_Value.m_pszString);
    s_EmptyConVar.m_Value.m_pszString = nullptr;
  }
  CUtlVector<CTransitionTable::ShadowStateDictEntry_t,CUtlMemory<CTransitionTable::ShadowStateDictEntry_t,int>>::~CUtlVector<CTransitionTable::ShadowStateDictEntry_t,CUtlMemory<CTransitionTable::ShadowStateDictEntry_t,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&s_EmptyConVar.m_fnChangeCallbacks);
  s_EmptyConVar.ConVar::ConCommandBase::__vftable = (CEmptyConVar_vtbl *)&ConCommandBase::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x10079DD0
// Name: _dynamic_atexit_destructor_for__g_ExpressionEvaluator__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_ExpressionEvaluator__()
{
  CExpressionEvaluator::~CExpressionEvaluator(this: &g_ExpressionEvaluator);
}

//------------------------------------------------------------------------------
// Address: 0x10079DE0
// Name: _dynamic_atexit_destructor_for__g_CleanupSymbolTable__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CleanupSymbolTable__()
{
  CUtlSymbolTableMT *v0; // esi

  v0 = CUtlSymbol::s_pSymbolTable;
  if ( CUtlSymbol::s_pSymbolTable != nullptr )
  {
    CUtlSymbolTable::RemoveAll(this: CUtlSymbol::s_pSymbolTable);
    CUtlVector<CTransitionTable::ShadowStateDictEntry_t,CUtlMemory<CTransitionTable::ShadowStateDictEntry_t,int>>::~CUtlVector<CTransitionTable::ShadowStateDictEntry_t,CUtlMemory<CTransitionTable::ShadowStateDictEntry_t,int>>(this: &v0->m_StringPools);
    CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::~CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>(this: &v0->m_Lookup);
    free(pMem: v0);
  }
  CUtlSymbol::s_pSymbolTable = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10079E20
// Name: _dynamic_atexit_destructor_for__vtMissing__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__vtMissing__()
{
  VariantClear(pvarg: &vtMissing);
}

} // namespace shaderapidx10
