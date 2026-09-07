// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/xbox/vxconsole/sys_utils.cpp
// Functions: 57
// ============================================================

#include "utils\xbox\vxconsole\sys_utils.h"

//------------------------------------------------------------------------------
// Address: 0x00413640
// Name: public: int CUtlVector<struct _DMN_MODLOAD,class CUtlMemory<struct _DMN_MODLOAD,int>>::InsertBefore(int,struct _DMN_MODLOAD const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<_DMN_MODLOAD,CUtlMemory<_DMN_MODLOAD,int>>::InsertBefore(
        CUtlVector<_DMN_MODLOAD,CUtlMemory<_DMN_MODLOAD,int> > *this,
        int elem,
        const _DMN_MODLOAD *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  _DMN_MODLOAD *m_pMemory; // ecx
  int v7; // eax
  int result; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<_DMN_MODLOAD,int>::Grow(this: &this->m_Memory, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 292 * v7);
  result = elem;
  if ( &this->m_Memory.m_pMemory[elem] != nullptr )
    qmemcpy(&this->m_Memory.m_pMemory[elem], src, sizeof(this->m_Memory.m_pMemory[elem]));
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00417BB0
// Name: public: int CUtlVector<struct xrDataCacheItem_t,class CUtlMemory<struct xrDataCacheItem_t,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<xrDataCacheItem_t,CUtlMemory<xrDataCacheItem_t,int>>::InsertMultipleBefore(
        CUtlVector<xrDataCacheItem_t,CUtlMemory<xrDataCacheItem_t,int> > *this,
        int elem,
        int num)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  xrDataCacheItem_t *m_pMemory; // ecx
  int v8; // eax
  int v9; // eax

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<xrDataCacheItem_t,int>::Grow(this: &this->m_Memory, num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v8 = this->m_Size;
  this->m_pElements = this->m_Memory.m_pMemory;
  v9 = v8 - elem - num;
  if ( v9 > 0 && num > 0 )
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 340 * v9);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x00417C30
// Name: public: int CUtlVector<struct CacheEntry_t,class CUtlMemory<struct CacheEntry_t,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CacheEntry_t,CUtlMemory<CacheEntry_t,int>>::InsertMultipleBefore(
        CUtlVector<CacheEntry_t,CUtlMemory<CacheEntry_t,int> > *this,
        int elem,
        int num)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  int v7; // edx
  CacheEntry_t *m_pMemory; // ecx
  int v9; // eax
  int v10; // ebx
  CacheEntry_t *v11; // esi

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<CacheEntry_t,int>::Grow(this: &this->m_Memory, num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  v7 = elem;
  m_pMemory = this->m_Memory.m_pMemory;
  v9 = this->m_Size - elem - num;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v9 <= 0 )
    goto LABEL_8;
  if ( num > 0 )
  {
    _V_memmove(dest: &m_pMemory[num + elem], src: &m_pMemory[elem], count: 156 * v9);
    v7 = elem;
LABEL_8:
    if ( num > 0 )
    {
      v10 = v7;
      do
      {
        v11 = &this->m_Memory.m_pMemory[v10];
        if ( v11 != nullptr )
        {
          CUtlString::CUtlString(this: &v11->name);
          CUtlString::CUtlString(this: &v11->section);
          v7 = elem;
          v11->listIndex = 0;
          v11->lruOrder = 0;
          v11->lruOrderBuff[0] = 0;
          v11->size = 0;
          v11->sizeBuff[0] = 0;
          v11->lockCount = 0;
          v11->lockCountBuff[0] = 0;
          v11->clientId = 0;
          v11->clientIdBuff[0] = 0;
          v11->itemData = 0;
          v11->itemDataBuff[0] = 0;
          v11->handle = 0;
          v11->handleBuff[0] = 0;
        }
        ++v10;
        --num;
      }
      while ( num != 0 );
    }
  }
  return v7;
}

//------------------------------------------------------------------------------
// Address: 0x00417D20
// Name: public: void CUtlVector<struct CacheEntry_t,class CUtlMemory<struct CacheEntry_t,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CacheEntry_t,CUtlMemory<CacheEntry_t,int>>::RemoveAll(
        CUtlVector<CacheEntry_t,CUtlMemory<CacheEntry_t,int> > *this)
{
  int v1; // ebx
  int v2; // eax
  char *v3; // esi
  int v4; // [esp+4h] [ebp-8h]
  CUtlVector<CacheEntry_t,CUtlMemory<CacheEntry_t,int> > *v5; // [esp+8h] [ebp-4h]

  v1 = this->m_Size - 1;
  v5 = this;
  if ( v1 < 0 )
  {
    this->m_Size = 0;
  }
  else
  {
    v2 = 156 * v1;
    v4 = 156 * v1;
    do
    {
      v3 = (char *)this->m_Memory.m_pMemory + v2;
      *((_DWORD *)v3 + 8) = 0;
      if ( *((int *)v3 + 7) >= 0 )
      {
        if ( *((_DWORD *)v3 + 5) != 0 )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *((void **)v3 + 5));
          this = v5;
          *((_DWORD *)v3 + 5) = 0;
        }
        *((_DWORD *)v3 + 6) = 0;
      }
      *((_DWORD *)v3 + 4) = 0;
      if ( *((int *)v3 + 3) >= 0 )
      {
        if ( *((_DWORD *)v3 + 1) != 0 )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *((void **)v3 + 1));
          this = v5;
          *((_DWORD *)v3 + 1) = 0;
        }
        *((_DWORD *)v3 + 2) = 0;
      }
      --v1;
      v2 = v4 - 156;
      v4 -= 156;
    }
    while ( v1 >= 0 );
    this->m_Size = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00418060
// Name: public: CUtlVector<struct CacheEntry_t,class CUtlMemory<struct CacheEntry_t,int>>::~CUtlVector<struct CacheEntry_t,class CUtlMemory<struct CacheEntry_t,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CacheEntry_t,CUtlMemory<CacheEntry_t,int>>::~CUtlVector<CacheEntry_t,CUtlMemory<CacheEntry_t,int>>(
        CUtlVector<CacheEntry_t,CUtlMemory<CacheEntry_t,int> > *this)
{
  bool v2; // sf
  CacheEntry_t *m_pMemory; // eax

  CUtlVector<CacheEntry_t,CUtlMemory<CacheEntry_t,int>>::RemoveAll(this);
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
// Address: 0x0041D3F0
// Name: public: CUtlVector<struct SymbolInfoStructs_t,class CUtlMemory<struct SymbolInfoStructs_t,int>>::~CUtlVector<struct SymbolInfoStructs_t,class CUtlMemory<struct SymbolInfoStructs_t,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<SymbolInfoStructs_t,CUtlMemory<SymbolInfoStructs_t,int>>::~CUtlVector<SymbolInfoStructs_t,CUtlMemory<SymbolInfoStructs_t,int>>(
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
// Address: 0x0041D460
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
// Address: 0x0041D4D0
// Name: public: int CUtlVector<unsigned int,class CUtlMemory<unsigned int,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<unsigned int,CUtlMemory<unsigned int,int>>::InsertMultipleBefore(
        CUtlVector<unsigned int,CUtlMemory<unsigned int,int> > *this,
        int elem,
        int num)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  unsigned int *m_pMemory; // ecx
  int v8; // eax
  int v9; // eax

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<unsigned int,int>::Grow(this: &this->m_Memory, num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v8 = this->m_Size;
  this->m_pElements = this->m_Memory.m_pMemory;
  v9 = v8 - elem - num;
  if ( v9 > 0 && num > 0 )
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 4 * v9);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x00421A60
// Name: public: int CUtlVector<struct xrVProfNodeItem_t,class CUtlMemory<struct xrVProfNodeItem_t,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<xrVProfNodeItem_t,CUtlMemory<xrVProfNodeItem_t,int>>::InsertMultipleBefore(
        CUtlVector<xrVProfNodeItem_t,CUtlMemory<xrVProfNodeItem_t,int> > *this,
        int elem,
        int num)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  xrVProfNodeItem_t *m_pMemory; // ecx
  int v8; // eax
  int v9; // eax

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<xrVProfNodeItem_t,int>::Grow(this: &this->m_Memory, num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v8 = this->m_Size;
  this->m_pElements = this->m_Memory.m_pMemory;
  v9 = v8 - elem - num;
  if ( v9 > 0 && num > 0 )
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 280 * v9);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x00421AE0
// Name: public: void CUtlVector<struct VProfNode_t,class CUtlMemory<struct VProfNode_t,int>>::EnsureCapacity(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<VProfNode_t,CUtlMemory<VProfNode_t,int>>::EnsureCapacity(
        CUtlVector<VProfNode_t,CUtlMemory<VProfNode_t,int> > *this,
        int num)
{
  VProfNode_t *m_pMemory; // edx
  unsigned int v4; // eax
  VProfNode_t *v5; // eax

  if ( this->m_Memory.m_nAllocationCount >= num )
  {
    this->m_pElements = this->m_Memory.m_pMemory;
  }
  else
  {
    if ( this->m_Memory.m_nGrowSize < 0 )
    {
LABEL_5:
      this->m_pElements = this->m_Memory.m_pMemory;
      return;
    }
    m_pMemory = this->m_Memory.m_pMemory;
    this->m_Memory.m_nAllocationCount = num;
    v4 = 112 * num;
    if ( m_pMemory != nullptr )
    {
      this->m_Memory.m_pMemory = (VProfNode_t *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v4);
      goto LABEL_5;
    }
    v5 = (VProfNode_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v4);
    this->m_Memory.m_pMemory = v5;
    this->m_pElements = v5;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00421B40
// Name: public: int CUtlVector<struct VProfNode_t,class CUtlMemory<struct VProfNode_t,int>>::InsertBefore(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<VProfNode_t,CUtlMemory<VProfNode_t,int>>::InsertBefore(
        CUtlVector<VProfNode_t,CUtlMemory<VProfNode_t,int> > *this,
        int elem)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  VProfNode_t *m_pMemory; // ecx
  int v6; // eax
  VProfNode_t *v7; // edi

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<VProfNode_t,int>::Grow(this: &this->m_Memory, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v6 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 112 * v6);
  v7 = &this->m_Memory.m_pMemory[elem];
  if ( v7 != nullptr )
  {
    CUtlString::CUtlString(this: &v7->name);
    CUtlString::CUtlString(this: &v7->budgetGroupName);
    v7->listIndex = 0;
  }
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x00421BC0
// Name: public: void CUtlVector<struct VProfNode_t,class CUtlMemory<struct VProfNode_t,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<VProfNode_t,CUtlMemory<VProfNode_t,int>>::RemoveAll(
        CUtlVector<VProfNode_t,CUtlMemory<VProfNode_t,int> > *this)
{
  int v1; // ebx
  int v2; // eax
  char *v3; // esi
  int v4; // [esp+4h] [ebp-8h]
  CUtlVector<VProfNode_t,CUtlMemory<VProfNode_t,int> > *v5; // [esp+8h] [ebp-4h]

  v1 = this->m_Size - 1;
  v5 = this;
  if ( v1 < 0 )
  {
    this->m_Size = 0;
  }
  else
  {
    v2 = 112 * v1;
    v4 = 112 * v1;
    do
    {
      v3 = (char *)this->m_Memory.m_pMemory + v2;
      *((_DWORD *)v3 + 8) = 0;
      if ( *((int *)v3 + 7) >= 0 )
      {
        if ( *((_DWORD *)v3 + 5) != 0 )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *((void **)v3 + 5));
          this = v5;
          *((_DWORD *)v3 + 5) = 0;
        }
        *((_DWORD *)v3 + 6) = 0;
      }
      *((_DWORD *)v3 + 4) = 0;
      if ( *((int *)v3 + 3) >= 0 )
      {
        if ( *((_DWORD *)v3 + 1) != 0 )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *((void **)v3 + 1));
          this = v5;
          *((_DWORD *)v3 + 1) = 0;
        }
        *((_DWORD *)v3 + 2) = 0;
      }
      --v1;
      v2 = v4 - 112;
      v4 -= 112;
    }
    while ( v1 >= 0 );
    this->m_Size = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00421CD0
// Name: public: CUtlVector<struct VProfNode_t,class CUtlMemory<struct VProfNode_t,int>>::~CUtlVector<struct VProfNode_t,class CUtlMemory<struct VProfNode_t,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<VProfNode_t,CUtlMemory<VProfNode_t,int>>::~CUtlVector<VProfNode_t,CUtlMemory<VProfNode_t,int>>(
        CUtlVector<VProfNode_t,CUtlMemory<VProfNode_t,int> > *this)
{
  bool v2; // sf
  VProfNode_t *m_pMemory; // eax

  CUtlVector<VProfNode_t,CUtlMemory<VProfNode_t,int>>::RemoveAll(this);
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
// Address: 0x00422730
// Name: public: int CUtlVector<struct SymbolInfoStructs_t,class CUtlMemory<struct SymbolInfoStructs_t,int>>::InsertBefore(int,struct SymbolInfoStructs_t const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<SymbolInfoStructs_t,CUtlMemory<SymbolInfoStructs_t,int>>::InsertBefore(
        CUtlVector<SymbolInfoStructs_t,CUtlMemory<SymbolInfoStructs_t,int> > *this,
        int elem,
        const SymbolInfoStructs_t *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  SymbolInfoStructs_t *m_pMemory; // ecx
  int v7; // eax
  int result; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<SymbolInfoStructs_t,int>::Grow(this: &this->m_Memory, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 576 * v7);
  result = elem;
  if ( &this->m_Memory.m_pMemory[elem] != nullptr )
    qmemcpy(&this->m_Memory.m_pMemory[elem], src, sizeof(this->m_Memory.m_pMemory[elem]));
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00423390
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
  CUtlString *v8; // ecx

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CUtlString,int>::Grow(this: &this->m_Memory, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 16 * v7);
  v8 = &this->m_Memory.m_pMemory[elem];
  if ( v8 != nullptr )
    CUtlString::CUtlString(this: v8, string: src);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x00423670
// Name: public: void CUtlVector<class CUtlString,class CUtlMemory<class CUtlString,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>::RemoveAll(
        CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *this)
{
  int v1; // edi
  int v2; // ebx
  CUtlString *v3; // esi
  CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *v4; // [esp+4h] [ebp-4h]

  v1 = this->m_Size - 1;
  v4 = this;
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
      v3->m_Storage.m_nActualLength = 0;
      if ( v3->m_Storage.m_Memory.m_nGrowSize >= 0 )
      {
        if ( v3->m_Storage.m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v3->m_Storage.m_Memory.m_pMemory);
          this = v4;
          v3->m_Storage.m_Memory.m_pMemory = nullptr;
        }
        v3->m_Storage.m_Memory.m_nAllocationCount = 0;
      }
      --v1;
      --v2;
    }
    while ( v1 >= 0 );
    this->m_Size = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00423780
// Name: public: void CUtlVector<struct fileList_t,class CUtlMemory<struct fileList_t,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<fileList_t,CUtlMemory<fileList_t,int>>::RemoveAll(
        CUtlVector<fileList_t,CUtlMemory<fileList_t,int> > *this)
{
  int v1; // edi
  int v2; // ebx
  fileList_t *v3; // esi
  CUtlVector<fileList_t,CUtlMemory<fileList_t,int> > *v4; // [esp+4h] [ebp-4h]

  v1 = this->m_Size - 1;
  v4 = this;
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
      v3->fileName.m_Storage.m_nActualLength = 0;
      if ( v3->fileName.m_Storage.m_Memory.m_nGrowSize >= 0 )
      {
        if ( v3->fileName.m_Storage.m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v3->fileName.m_Storage.m_Memory.m_pMemory);
          this = v4;
          v3->fileName.m_Storage.m_Memory.m_pMemory = nullptr;
        }
        v3->fileName.m_Storage.m_Memory.m_nAllocationCount = 0;
      }
      --v1;
      --v2;
    }
    while ( v1 >= 0 );
    this->m_Size = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004237F0
// Name: public: CUtlVector<class CUtlString,class CUtlMemory<class CUtlString,int>>::~CUtlVector<class CUtlString,class CUtlMemory<class CUtlString,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>::~CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>(
        CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *this)
{
  bool v2; // sf
  CUtlString *m_pMemory; // eax

  CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>::RemoveAll(this);
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
// Address: 0x00423850
// Name: public: CUtlVector<struct fileList_t,class CUtlMemory<struct fileList_t,int>>::~CUtlVector<struct fileList_t,class CUtlMemory<struct fileList_t,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<fileList_t,CUtlMemory<fileList_t,int>>::~CUtlVector<fileList_t,CUtlMemory<fileList_t,int>>(
        CUtlVector<fileList_t,CUtlMemory<fileList_t,int> > *this)
{
  bool v2; // sf
  fileList_t *m_pMemory; // eax

  CUtlVector<fileList_t,CUtlMemory<fileList_t,int>>::RemoveAll(this);
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
// Address: 0x00423B40
// Name: public: void CUtlVector<class CUtlVector<class CUtlString,class CUtlMemory<class CUtlString,int>>,class CUtlMemory<class CUtlVector<class CUtlString,class CUtlMemory<class CUtlString,int>>,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>,CUtlMemory<CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>,int>>::RemoveAll(
        CUtlVector<CUtlVector<CUtlString,CUtlMemory<CUtlString,int> >,CUtlMemory<CUtlVector<CUtlString,CUtlMemory<CUtlString,int> >,int> > *this)
{
  int v1; // edi
  int v2; // eax
  CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *v3; // esi
  CUtlString *m_pMemory; // eax
  CUtlVector<CUtlVector<CUtlString,CUtlMemory<CUtlString,int> >,CUtlMemory<CUtlVector<CUtlString,CUtlMemory<CUtlString,int> >,int> > *v5; // [esp+4h] [ebp-8h]
  int i; // [esp+8h] [ebp-4h]

  v1 = this->m_Size - 1;
  v5 = this;
  if ( v1 < 0 )
  {
    this->m_Size = 0;
  }
  else
  {
    v2 = 20 * v1;
    for ( i = 20 * v1; ; v2 = i )
    {
      v3 = (CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *)((char *)this->m_Memory.m_pMemory + v2);
      CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>::RemoveAll(this: v3);
      if ( v3->m_Memory.m_nGrowSize >= 0 )
      {
        if ( v3->m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v3->m_Memory.m_pMemory);
          v3->m_Memory.m_pMemory = nullptr;
        }
        v3->m_Memory.m_nAllocationCount = 0;
      }
      m_pMemory = v3->m_Memory.m_pMemory;
      v3->m_pElements = v3->m_Memory.m_pMemory;
      if ( v3->m_Memory.m_nGrowSize >= 0 )
      {
        if ( m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
          v3->m_Memory.m_pMemory = nullptr;
        }
        v3->m_Memory.m_nAllocationCount = 0;
      }
      i -= 20;
      this = v5;
      if ( --v1 < 0 )
        break;
    }
    v5->m_Size = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00425BE0
// Name: public: int CUtlVector<struct dvdimage_t,class CUtlMemory<struct dvdimage_t,int>>::InsertBefore(int,struct dvdimage_t const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<dvdimage_t,CUtlMemory<dvdimage_t,int>>::InsertBefore(
        CUtlVector<dvdimage_t,CUtlMemory<dvdimage_t,int> > *this,
        int elem,
        const dvdimage_t *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  dvdimage_t *m_pMemory; // ecx
  int v7; // eax
  dvdimage_t *v8; // ecx

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<dvdimage_t,int>::Grow(this: &this->m_Memory, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 348 * v7);
  v8 = &this->m_Memory.m_pMemory[elem];
  if ( v8 != nullptr )
    dvdimage_t::dvdimage_t(this: v8, __that: src);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x00425C60
// Name: public: void CUtlVector<struct dvdimage_t,class CUtlMemory<struct dvdimage_t,int>>::Sort(int (*)(struct dvdimage_t const __near *,struct dvdimage_t const __near *))
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<dvdimage_t,CUtlMemory<dvdimage_t,int>>::Sort(
        CUtlVector<dvdimage_t,CUtlMemory<dvdimage_t,int> > *this,
        int (__cdecl *pfnCompare)(const void *, const void *))
{
  CUtlVector<dvdimage_t,CUtlMemory<dvdimage_t,int> > *v2; // esi
  signed int m_Size; // eax
  dvdimage_t *m_pMemory; // ecx
  int v5; // ebx
  int v6; // edi
  dvdimage_t *v7; // esi
  dvdimage_t __that; // [esp+4h] [ebp-168h] BYREF
  CUtlVector<dvdimage_t,CUtlMemory<dvdimage_t,int> > *v9; // [esp+160h] [ebp-Ch]
  int j; // [esp+164h] [ebp-8h]
  int i; // [esp+168h] [ebp-4h]

  v2 = this;
  m_Size = this->m_Size;
  v9 = this;
  if ( m_Size > 1 )
  {
    m_pMemory = this->m_Memory.m_pMemory;
    if ( v2->m_Memory.m_pMemory != nullptr )
    {
      qsort(base: m_pMemory, num: m_Size, width: 0x15Cu, comp: pfnCompare);
    }
    else
    {
      v5 = m_Size - 1;
      i = m_Size - 1;
      do
      {
        if ( v5 >= 1 )
        {
          v6 = 1;
          for ( j = v5; j != 0; --j )
          {
            if ( pfnCompare(a1: &v2->m_Memory.m_pMemory[v6 - 1], a2: &v2->m_Memory.m_pMemory[v6]) < 0 )
            {
              v7 = &v2->m_Memory.m_pMemory[v6];
              dvdimage_t::dvdimage_t(this: &__that, __that: v7 - 1);
              dvdimage_t::operator=(this: v7 - 1, __that: v7);
              dvdimage_t::operator=(this: v7, &__that);
              dvdimage_t::~dvdimage_t(this: &__that);
              v2 = v9;
              v5 = i;
            }
            ++v6;
          }
        }
        i = --v5;
      }
      while ( v5 >= 0 );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004263C0
// Name: public: void CUtlVector<struct dvdimage_t,class CUtlMemory<struct dvdimage_t,int>>::Purge(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<dvdimage_t,CUtlMemory<dvdimage_t,int>>::Purge(
        CUtlVector<dvdimage_t,CUtlMemory<dvdimage_t,int> > *this)
{
  int v2; // esi
  int v3; // ebx
  dvdimage_t *m_pMemory; // ecx

  v2 = this->m_Size - 1;
  if ( v2 >= 0 )
  {
    v3 = v2;
    do
    {
      dvdimage_t::~dvdimage_t(this: &this->m_Memory.m_pMemory[v3--]);
      --v2;
    }
    while ( v2 >= 0 );
  }
  this->m_Size = 0;
  if ( this->m_Memory.m_nGrowSize < 0 )
  {
    this->m_pElements = this->m_Memory.m_pMemory;
  }
  else
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    m_pMemory = this->m_Memory.m_pMemory;
    this->m_Memory.m_nAllocationCount = 0;
    this->m_pElements = m_pMemory;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00426E90
// Name: char __near * Sys_GetToken(bool)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl Sys_GetToken(bool crossline)
{
  char *v2; // eax
  char *v3; // esi
  char v4; // cl
  char v5; // cl
  char v6; // cl
  char *v7; // edx

  if ( g_sys_tokenready )
  {
    g_sys_tokenready = false;
    return g_sys_token;
  }
  else
  {
    v2 = g_sys_scriptptr;
    v3 = g_sys_scriptendptr;
    g_sys_token[0] = 0;
    if ( g_sys_scriptptr >= g_sys_scriptendptr )
    {
LABEL_35:
      g_sys_endofscript = true;
      return nullptr;
    }
    else
    {
      while ( 1 )
      {
        v4 = *v2;
        if ( *v2 <= 32 )
        {
          while ( v2 < g_sys_scriptendptr )
          {
            g_sys_scriptptr = ++v2;
            if ( v4 == 10 )
            {
              if ( !crossline )
                return nullptr;
              ++g_sys_scriptline;
            }
            v4 = *v2;
            if ( *v2 > 32 )
              goto LABEL_10;
          }
          goto LABEL_35;
        }
LABEL_10:
        if ( v2 >= g_sys_scriptendptr )
          goto LABEL_35;
        v5 = *v2;
        if ( *v2 != 59 && (v5 != 47 || v2[1] != 47) )
          break;
        if ( !crossline )
          return nullptr;
        if ( v5 != 10 )
        {
          do
          {
            g_sys_scriptptr = ++v2;
            if ( v2 >= g_sys_scriptendptr )
              goto LABEL_35;
          }
          while ( *v2 != 10 );
        }
        ++v2;
        ++g_sys_scriptline;
        g_sys_scriptptr = v2;
      }
      v6 = *v2;
      v7 = g_sys_token;
      if ( *v2 == 34 && v2[1] != 0 )
      {
        while ( 1 )
        {
          ++v2;
          *v7++ = v6;
          g_sys_scriptptr = v2;
          if ( v2 == v3 )
            break;
          if ( v7 == (char *)&g_sys_oldscriptline )
            return nullptr;
          v6 = *v2;
          if ( *v2 < 32 )
            break;
          if ( v6 == 34 )
          {
            *v7 = 34;
            g_sys_scriptptr = v2 + 1;
            v7[1] = 0;
            return g_sys_token;
          }
        }
        if ( *v2 == 34 )
        {
          *v7 = *v2;
          g_sys_scriptptr = v2 + 1;
          v7[1] = 0;
          return g_sys_token;
        }
      }
      else if ( v6 > 32 )
      {
        do
        {
          if ( v6 == 59 )
            break;
          if ( v6 == 34 )
            break;
          ++v2;
          *v7++ = v6;
          g_sys_scriptptr = v2;
          if ( v2 == v3 )
            break;
          if ( v7 == (char *)&g_sys_oldscriptline )
            return nullptr;
          v6 = *v2;
        }
        while ( *v2 > 32 );
      }
      *v7 = 0;
      return g_sys_token;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00427140
// Name: void Sys_SetRegistryPrefix(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Sys_SetRegistryPrefix(const char *pPrefix)
{
  _snprintf_s(string: g_szRegistryPrefix, sizeInBytes: 0x100u, count: 0xFFFFFFFF, format: pPrefix);
}

//------------------------------------------------------------------------------
// Address: 0x00427160
// Name: Sys_SplitRegistryKey
// Source: json
//------------------------------------------------------------------------------
int __cdecl Sys_SplitRegistryKey(const char *key, char *key0, char *key0Len)
{
  unsigned int v4; // edi
  int v5; // eax
  unsigned int v6; // esi

  if ( key == nullptr )
    return 0;
  v4 = strlen(key);
  if ( v4 == 0 )
    return 0;
  v5 = v4 - 1;
  v6 = -1;
  if ( (int)(v4 - 1) < 0 )
    return 0;
  do
  {
    if ( key[v5] == 92 )
      break;
    v6 = v5--;
  }
  while ( v5 >= 0 );
  if ( v6 == -1 )
    return 0;
  _snprintf_s(string: key0, sizeInBytes: v6, count: 0xFFFFFFFF, format: key);
  _snprintf_s(string: key0Len, sizeInBytes: v4 - v6 + 1, count: 0xFFFFFFFF, format: &key[v6]);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004271E0
// Name: int Sys_SetRegistryString(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl Sys_SetRegistryString(const char *keyName, const char *value)
{
  char *v2; // edi
  int v3; // esi
  char key1[256]; // [esp+8h] [ebp-304h] BYREF
  char key0[256]; // [esp+108h] [ebp-204h] BYREF
  char keyBuff[256]; // [esp+208h] [ebp-104h] BYREF
  HKEY__ *hKey; // [esp+308h] [ebp-4h] BYREF

  strcpy_s(_Dst: keyBuff, _SizeInBytes: 0x100u, _Src: g_szRegistryPrefix);
  strcat_s(_Dst: keyBuff, _SizeInBytes: 0x100u, _Src: keyName);
  v2 = keyBuff;
  v3 = -2147483647;
  if ( strncmp(first: keyBuff, last: "HKEY_LOCAL_MACHINE", count: 0x12u) == 0 )
  {
    v3 = -2147483646;
    v2 = &keyBuff[19];
  }
  else if ( strncmp(first: keyBuff, last: "HKEY_CURRENT_USER", count: 0x11u) == 0 )
  {
    v2 = &keyBuff[18];
  }
  if ( Sys_SplitRegistryKey(key: v2, key0, key0Len: key1) == 0
    || RegCreateKeyExA(
         hKey: (HKEY)v3,
         lpSubKey: key0,
         Reserved: 0,
         lpClass: nullptr,
         dwOptions: 0,
         samDesired: value != nullptr ? 131078 : 983103,
         lpSecurityAttributes: nullptr,
         phkResult: &hKey,
         lpdwDisposition: nullptr) != 0 )
  {
    return 0;
  }
  if ( RegSetValueExA(
         hKey,
         lpValueName: key1,
         Reserved: 0,
         dwType: 1u,
         lpData: (const BYTE *)value,
         cbData: strlen(value) + 1) != 0 )
  {
    RegCloseKey(hKey);
    return 0;
  }
  RegCloseKey(hKey);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00427310
// Name: int Sys_GetRegistryString(char const __near *,char __near *,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl Sys_GetRegistryString(const char *keyName, char *value, const char *defValue, unsigned int valueLen)
{
  char *v4; // esi
  int v5; // edi
  char key1[256]; // [esp+Ch] [ebp-308h] BYREF
  char key0[256]; // [esp+10Ch] [ebp-208h] BYREF
  char keyBuff[256]; // [esp+20Ch] [ebp-108h] BYREF
  unsigned int len; // [esp+30Ch] [ebp-8h] BYREF
  HKEY__ *hKey; // [esp+310h] [ebp-4h] BYREF

  strcpy_s(_Dst: keyBuff, _SizeInBytes: 0x100u, _Src: g_szRegistryPrefix);
  strcat_s(_Dst: keyBuff, _SizeInBytes: 0x100u, _Src: keyName);
  v4 = keyBuff;
  if ( defValue != nullptr )
    _snprintf_s(string: value, sizeInBytes: valueLen, count: 0xFFFFFFFF, format: defValue);
  v5 = -2147483647;
  if ( strncmp(first: keyBuff, last: "HKEY_LOCAL_MACHINE", count: 0x12u) == 0 )
  {
    v5 = -2147483646;
    v4 = &keyBuff[19];
  }
  else if ( strncmp(first: keyBuff, last: "HKEY_CURRENT_USER", count: 0x11u) == 0 )
  {
    v4 = &keyBuff[18];
  }
  if ( Sys_SplitRegistryKey(key: v4, key0, key0Len: key1) == 0
    || RegOpenKeyExA(hKey: (HKEY)v5, lpSubKey: key0, ulOptions: 0, samDesired: 0x20019u, phkResult: &hKey) != 0 )
  {
    return 0;
  }
  len = valueLen;
  if ( RegQueryValueExA(
         hKey,
         lpValueName: key1,
         lpReserved: nullptr,
         lpType: nullptr,
         lpData: (LPBYTE)value,
         lpcbData: &len) != 0 )
  {
    RegCloseKey(hKey);
    return 0;
  }
  RegCloseKey(hKey);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00427440
// Name: int Sys_SetRegistryInteger(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl Sys_SetRegistryInteger(const char *keyName, int value)
{
  char *v2; // edi
  int v3; // esi
  char key1[256]; // [esp+8h] [ebp-304h] BYREF
  char key0[256]; // [esp+108h] [ebp-204h] BYREF
  char keyBuff[256]; // [esp+208h] [ebp-104h] BYREF
  HKEY__ *hKey; // [esp+308h] [ebp-4h] BYREF

  strcpy_s(_Dst: keyBuff, _SizeInBytes: 0x100u, _Src: g_szRegistryPrefix);
  strcat_s(_Dst: keyBuff, _SizeInBytes: 0x100u, _Src: keyName);
  v2 = keyBuff;
  v3 = -2147483647;
  if ( strncmp(first: keyBuff, last: "HKEY_LOCAL_MACHINE", count: 0x12u) == 0 )
  {
    v3 = -2147483646;
    v2 = &keyBuff[19];
  }
  else if ( strncmp(first: keyBuff, last: "HKEY_CURRENT_USER", count: 0x11u) == 0 )
  {
    v2 = &keyBuff[18];
  }
  if ( Sys_SplitRegistryKey(key: v2, key0, key0Len: key1) == 0
    || RegCreateKeyExA(
         hKey: (HKEY)v3,
         lpSubKey: key0,
         Reserved: 0,
         lpClass: nullptr,
         dwOptions: 0,
         samDesired: 0x20006u,
         lpSecurityAttributes: nullptr,
         phkResult: &hKey,
         lpdwDisposition: nullptr) != 0 )
  {
    return 0;
  }
  if ( RegSetValueExA(hKey, lpValueName: key1, Reserved: 0, dwType: 4u, lpData: (const BYTE *)&value, cbData: 4u) != 0 )
  {
    RegCloseKey(hKey);
    return 0;
  }
  RegCloseKey(hKey);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00427550
// Name: int Sys_GetRegistryInteger(char const __near *,int,int __near &)
// Source: json
//------------------------------------------------------------------------------
int __cdecl Sys_GetRegistryInteger(const char *keyName, int defValue, int *value)
{
  char *v3; // edi
  int v4; // esi
  char key1[256]; // [esp+Ch] [ebp-308h] BYREF
  char key0[256]; // [esp+10Ch] [ebp-208h] BYREF
  char keyBuff[256]; // [esp+20Ch] [ebp-108h] BYREF
  unsigned int len; // [esp+30Ch] [ebp-8h] BYREF
  HKEY__ *hKey; // [esp+310h] [ebp-4h] BYREF

  strcpy_s(_Dst: keyBuff, _SizeInBytes: 0x100u, _Src: g_szRegistryPrefix);
  strcat_s(_Dst: keyBuff, _SizeInBytes: 0x100u, _Src: keyName);
  v3 = keyBuff;
  *value = defValue;
  v4 = -2147483647;
  if ( strncmp(first: keyBuff, last: "HKEY_LOCAL_MACHINE", count: 0x12u) == 0 )
  {
    v4 = -2147483646;
    v3 = &keyBuff[19];
  }
  else if ( strncmp(first: keyBuff, last: "HKEY_CURRENT_USER", count: 0x11u) == 0 )
  {
    v3 = &keyBuff[18];
  }
  if ( Sys_SplitRegistryKey(key: v3, key0, key0Len: key1) == 0
    || RegOpenKeyExA(hKey: (HKEY)v4, lpSubKey: key0, ulOptions: 0, samDesired: 0x20019u, phkResult: &hKey) != 0 )
  {
    return 0;
  }
  len = 4;
  if ( RegQueryValueExA(
         hKey,
         lpValueName: key1,
         lpReserved: nullptr,
         lpType: nullptr,
         lpData: (LPBYTE)value,
         lpcbData: &len) != 0 )
  {
    RegCloseKey(hKey);
    return 0;
  }
  RegCloseKey(hKey);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00427670
// Name: void Sys_MessageBox(char const __near *,char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
void Sys_MessageBox(const char *title, const char *format, ...)
{
  char msg[2048]; // [esp+0h] [ebp-800h] BYREF
  va_list ap; // [esp+810h] [ebp+10h] BYREF

  va_start(ap, format);
  vsprintf_s(string: msg, sizeInBytes: 0x800u, format, ap);
  MessageBoxA(hWnd: nullptr, lpText: msg, lpCaption: title, uType: 0x42000u);
}

//------------------------------------------------------------------------------
// Address: 0x004276C0
// Name: void Sys_Free(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Sys_Free(void *ptr)
{
  if ( ptr != nullptr )
    free(pMem: ptr);
}

//------------------------------------------------------------------------------
// Address: 0x004276E0
// Name: void Sys_Error(char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
void Sys_Error(const char *format, ...)
{
  char msg[1024]; // [esp+0h] [ebp-400h] BYREF
  va_list ap; // [esp+40Ch] [ebp+Ch] BYREF

  va_start(ap, format);
  vsprintf_s(string: msg, sizeInBytes: 0x400u, format, ap);
  MessageBoxA(hWnd: nullptr, lpText: msg, lpCaption: "FATAL ERROR", uType: 0x10u);
}

//------------------------------------------------------------------------------
// Address: 0x00427720
// Name: bool Sys_SaveFile(char const __near *,void __near *,long,bool)
// Source: json
//------------------------------------------------------------------------------
char __cdecl Sys_SaveFile(const char *filename, void *buffer, unsigned int count, int bText)
{
  int *v4; // eax
  int v6; // esi
  int *v7; // eax
  char szError[260]; // [esp+4h] [ebp-104h] BYREF

  _sopen_s(
    pfh: &bText,
    path: filename,
    oflag: ((unsigned __int8)bText != 0 ? 0x4000 : 0x8000) | 0x302,
    shflag: 64,
    pmode: 384);
  if ( bText == -1 )
  {
    v4 = _errno();
    strerror_s(buffer: szError, sizeInTChars: 0x104u, errnum: *v4);
    Sys_Error(format: "Sys_SaveFile(): Error opening %s: %s", filename, szError);
    return 0;
  }
  else
  {
    v6 = _write(fh: bText, buf: buffer, cnt: count);
    if ( v6 == count )
    {
      _close(fh: bText);
      return 1;
    }
    else
    {
      v7 = _errno();
      Sys_Error(format: "Sys_SaveFile(): write failure %d, errno=%d", v6, *v7);
      return 0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004277E0
// Name: void Sys_NormalizePath(char __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Sys_NormalizePath(char *path, bool forceToLower)
{
  signed int v2; // edi
  signed int i; // ecx
  char v4; // al

  v2 = strlen(path);
  for ( i = 0; i < v2; ++i )
  {
    v4 = path[i];
    if ( v4 == 47 )
    {
      path[i] = 92;
    }
    else if ( forceToLower && v4 >= 65 && v4 <= 90 )
    {
      path[i] = v4 + 32;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00427830
// Name: void Sys_AddFileSeperator(char __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Sys_AddFileSeperator(char *path, unsigned int pathLen)
{
  if ( *path != 0 )
  {
    if ( path[strlen(path) - 1] != 92 )
      strcat_s(_Dst: path, _SizeInBytes: pathLen, _Src: "\\");
  }
  else
  {
    strcpy_s(_Dst: path, _SizeInBytes: pathLen, _Src: ".\\");
  }
}

//------------------------------------------------------------------------------
// Address: 0x00427880
// Name: void Sys_StripFilename(char const __near *,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Sys_StripFilename(const char *inpath, char *outpath, unsigned int outPathLen)
{
  unsigned int v3; // kr00_4
  int v4; // eax
  bool v5; // zf
  char v6; // cl

  strcpy_s(_Dst: outpath, _SizeInBytes: outPathLen, _Src: inpath);
  v3 = strlen(outpath);
  v4 = v3 - 1;
  v5 = v3 == 1;
  if ( (int)(v3 - 1) > 0 )
  {
    do
    {
      v6 = outpath[v4];
      if ( v6 == 92 )
        break;
      if ( v6 == 47 )
        break;
      if ( v6 == 58 )
        break;
      --v4;
    }
    while ( v4 > 0 );
    v5 = v4 == 0;
  }
  if ( v5 )
    *outpath = 0;
  else
    outpath[v4 + 1] = 0;
}

//------------------------------------------------------------------------------
// Address: 0x004278E0
// Name: void Sys_StripExtension(char const __near *,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Sys_StripExtension(const char *inpath, char *outpath, unsigned int outPathLen)
{
  unsigned int v3; // kr00_4
  int v4; // eax
  bool v5; // zf

  strcpy_s(_Dst: outpath, _SizeInBytes: outPathLen, _Src: inpath);
  v3 = strlen(outpath);
  v4 = v3 - 1;
  v5 = v3 == 1;
  if ( (int)(v3 - 1) > 0 )
  {
    do
    {
      if ( outpath[v4] == 46 )
        break;
      --v4;
    }
    while ( v4 > 0 );
    v5 = v4 == 0;
  }
  if ( !v5 && outpath[v4] == 46 )
    outpath[v4] = 0;
}

//------------------------------------------------------------------------------
// Address: 0x00427930
// Name: void Sys_StripPath(char const __near *,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Sys_StripPath(const char *inpath, char *outpath, unsigned int outPathLen)
{
  const char *i; // eax
  char v4; // cl

  for ( i = &inpath[strlen(inpath)]; i != inpath; --i )
  {
    v4 = *(i - 1);
    if ( v4 == 92 )
      break;
    if ( v4 == 47 )
      break;
    if ( v4 == 58 )
      break;
  }
  strcpy_s(_Dst: outpath, _SizeInBytes: outPathLen, _Src: i);
}

//------------------------------------------------------------------------------
// Address: 0x00427980
// Name: void Sys_AddExtension(char const __near *,char __near *,int,bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Sys_AddExtension(const char *extension, char *outpath, unsigned int outPathLen, bool bForce)
{
  char *i; // eax
  char v5; // cl

  if ( !bForce && *outpath != 0 )
  {
    for ( i = &outpath[strlen(outpath) - 1]; i != outpath; --i )
    {
      v5 = *i;
      if ( *i == 92 || v5 == 47 )
        break;
      if ( v5 == 46 )
        return;
    }
  }
  strcat_s(_Dst: outpath, _SizeInBytes: outPathLen, _Src: extension);
}

//------------------------------------------------------------------------------
// Address: 0x004279E0
// Name: int Sys_Exists(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl Sys_Exists(const char *filename)
{
  int result; // eax
  _iobuf *test; // [esp+0h] [ebp-4h] BYREF

  fopen_s(pfile: &test, file: filename, mode: "rb");
  result = (int)test;
  if ( test != nullptr )
  {
    fclose(stream: test);
    return 1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00427A20
// Name: char __near * Sys_GetToken(char __near * __near *,int,int __near *)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl Sys_GetToken(char **dataptr, int allowLineBreaks, int *numlines)
{
  char *v3; // eax
  int v4; // edi
  int v5; // esi
  char *v7; // ecx
  int i; // eax
  char v9; // al
  char v10; // dl
  char j; // cl
  char v12; // cl
  char v13; // al
  char *k; // ecx

  if ( numlines != nullptr )
    *numlines = 0;
  v3 = *dataptr;
  v4 = 0;
  v5 = 0;
  token_0[0] = 0;
  if ( v3 == nullptr )
  {
    *dataptr = nullptr;
    return token_0;
  }
  while ( 1 )
  {
LABEL_5:
    v7 = v3;
    for ( i = *v3; i <= 32; i = *++v7 )
    {
      if ( i == 10 )
      {
        if ( numlines != nullptr )
          ++*numlines;
        v5 = 1;
      }
      else if ( i == 0 )
      {
        *dataptr = nullptr;
        return token_0;
      }
    }
    if ( v5 != 0 && allowLineBreaks == 0 )
      goto LABEL_46;
    v9 = *v7;
    if ( *v7 != 47 )
      break;
    v10 = v7[1];
    if ( v10 == 47 )
    {
      v3 = v7 + 2;
      for ( j = v7[2]; j != 0; j = *++v3 )
      {
        if ( j == 10 )
          break;
      }
    }
    else
    {
      if ( v10 != 42 )
      {
LABEL_37:
        token_0[v4++] = v9;
        while ( 1 )
        {
          v9 = *++v7;
          if ( v9 == 10 )
            break;
          if ( v9 <= 32 )
            goto LABEL_43;
LABEL_36:
          if ( v4 < 1024 )
            goto LABEL_37;
        }
        if ( numlines != nullptr )
          ++*numlines;
LABEL_43:
        if ( v4 >= 1024 )
          v4 = 0;
        token_0[v4] = 0;
LABEL_46:
        *dataptr = v7;
        return token_0;
      }
      v3 = v7 + 2;
      v12 = v7[2];
      if ( v12 != 0 )
      {
        while ( v12 != 42 || v3[1] != 47 )
        {
          v12 = *++v3;
          if ( v12 == 0 )
            goto LABEL_5;
        }
        if ( *v3 != 0 )
          v3 += 2;
      }
    }
  }
  if ( v9 != 34 )
    goto LABEL_36;
  v13 = v7[1];
  for ( k = v7 + 2; v13 != 34; v13 = *k++ )
  {
    if ( v13 == 0 )
      break;
    if ( v4 < 1024 )
      token_0[v4++] = v13;
  }
  token_0[v4] = 0;
  *dataptr = k;
  return token_0;
}

//------------------------------------------------------------------------------
// Address: 0x00427B90
// Name: unsigned long Sys_GetSystemTime(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __cdecl Sys_GetSystemTime()
{
  _LARGE_INTEGER qwTime; // [esp+0h] [ebp-14h] BYREF
  _LARGE_INTEGER qwTicksPerSec; // [esp+8h] [ebp-Ch] BYREF
  float msecsPerTick; // [esp+10h] [ebp-4h]

  QueryPerformanceFrequency(lpFrequency: &qwTicksPerSec);
  msecsPerTick = 1000.0 / (double)qwTicksPerSec.QuadPart;
  QueryPerformanceCounter(lpPerformanceCount: &qwTime);
  return (__int64)((double)qwTime.QuadPart * msecsPerTick);
}

//------------------------------------------------------------------------------
// Address: 0x00427BE0
// Name: unsigned long Sys_ColorScale(unsigned long,float)
// Source: json
//------------------------------------------------------------------------------
int __cdecl Sys_ColorScale(unsigned int color, float scale)
{
  int v2; // ecx
  int v3; // edx
  int v4; // eax

  v2 = (int)(float)((float)(unsigned __int8)color * scale);
  v3 = (int)(float)((float)BYTE1(color) * scale);
  v4 = (int)(float)((float)BYTE2(color) * scale);
  if ( v2 > 255 )
    LOBYTE(v2) = -1;
  if ( v3 > 255 )
    LOBYTE(v3) = -1;
  if ( v4 > 255 )
    LOBYTE(v4) = -1;
  return (unsigned __int8)v2 | (((unsigned __int8)v3 | ((unsigned __int8)v4 << 8)) << 8);
}

//------------------------------------------------------------------------------
// Address: 0x00427C70
// Name: bool Sys_IsWildcardMatch(char const __near *,char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl Sys_IsWildcardMatch(const char *wildcardString, const char *stringToCheck, bool caseSensitive)
{
  const char *v3; // edi
  const char *v4; // esi
  char v5; // bl
  char i; // al
  char strChar; // [esp+7h] [ebp-1h]

  v3 = wildcardString;
  if ( _stricmp(dst: wildcardString, src: "*.*") == 0 || _stricmp(dst: wildcardString, src: "*") == 0 )
    return true;
  v4 = stringToCheck;
  for ( strChar = *stringToCheck; *v4 != 0; strChar = *v4 )
  {
    v5 = *v3;
    if ( *v3 == 0 )
      break;
    ++v4;
    ++v3;
    if ( !caseSensitive )
    {
      v5 = toupper(c: v5);
      strChar = toupper(c: strChar);
    }
    if ( v5 == 42 )
    {
      if ( *--v4 != 0 )
      {
        while ( !Sys_IsWildcardMatch(wildcardString: v3, stringToCheck: v4++, caseSensitive) )
        {
          if ( *v4 == 0 )
            goto LABEL_14;
        }
        return true;
      }
    }
    else if ( v5 != 63 && v5 != strChar )
    {
      return false;
    }
LABEL_14:
    ;
  }
  for ( i = *v3; i != 0; i = *++v3 )
  {
    if ( i != 42 )
      break;
  }
  return *v4 == 0 && *v3 == 0;
}

//------------------------------------------------------------------------------
// Address: 0x00427D50
// Name: char __near * Sys_NumberToCommaString(__int64,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl Sys_NumberToCommaString(__int64 number, char *buffer, unsigned int bufferSize)
{
  int v3; // ecx
  char *v4; // edi
  char *v5; // eax
  int v6; // esi
  signed int v7; // eax
  char *i; // ecx
  char temp2[256]; // [esp+0h] [ebp-200h] BYREF
  char temp[256]; // [esp+100h] [ebp-100h] BYREF

  sprintf_s(string: temp, sizeInBytes: 0x100u, format: "%I64d", number);
  v3 = strlen(temp);
  v4 = &temp2[v3 + 255];
  v5 = temp2;
  if ( v3 > 0 )
  {
LABEL_2:
    v6 = 0;
    while ( v3 > 0 )
    {
      *v5 = *v4;
      ++v6;
      ++v5;
      --v4;
      --v3;
      if ( v6 >= 3 )
      {
        if ( v3 <= 0 )
          break;
        *v5++ = 44;
        goto LABEL_2;
      }
    }
  }
  *v5 = 0;
  v7 = strlen(temp2) - 1;
  for ( i = temp; v7 >= 0; --v7 )
    *i++ = temp2[v7];
  *i = 0;
  _snprintf_s(string: buffer, sizeInBytes: bufferSize, count: 0xFFFFFFFF, format: temp);
  return buffer;
}

//------------------------------------------------------------------------------
// Address: 0x00427E20
// Name: void Sys_CreatePath(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Sys_CreatePath(const char *pInPath)
{
  _BYTE *v1; // eax
  _BYTE *v2; // esi
  _BYTE *v3; // eax
  char dirPath[260]; // [esp+4h] [ebp-104h] BYREF

  strcpy_s(_Dst: dirPath, _SizeInBytes: 0x104u, _Src: pInPath);
  if ( dirPath[0] == 92 && dirPath[1] == 92 )
    strchr(string: (unsigned __int8 *)&dirPath[1], chr: 0x5Cu);
  else
    strchr(string: (unsigned __int8 *)dirPath, chr: 0x5Cu);
  v2 = v1;
  if ( v1 != nullptr )
  {
    while ( 1 )
    {
      strchr(string: v2 + 1, chr: 0x5Cu);
      v2 = v3;
      if ( v3 == nullptr )
        break;
      *v3 = 0;
      CreateDirectoryA(lpPathName: dirPath, lpSecurityAttributes: nullptr);
      *v2 = 92;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00427F50
// Name: void __near * Sys_Alloc(int)
// Source: json
//------------------------------------------------------------------------------
void *__cdecl Sys_Alloc(int size)
{
  unsigned int v1; // esi
  void *v2; // edi

  if ( size == 0 )
    Sys_Error(format: "Sys_Alloc(): zero size");
  v1 = (size + 3) & 0xFFFFFFFC;
  v2 = operator new(nSize: v1);
  if ( v2 == nullptr )
    Sys_Error(format: "Sys_Alloc(): %d bytes not available", v1);
  _V_memset(dest: v2, fill: 0, count: v1);
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x00427FA0
// Name: int Sys_LoadFile(char const __near *,void __near * __near *,bool)
// Source: json
//------------------------------------------------------------------------------
unsigned int __cdecl Sys_LoadFile(const char *filename, void **bufferptr, bool bText)
{
  int v3; // eax
  int *v4; // eax
  int v5; // edi
  int v6; // ebx
  unsigned int v7; // esi
  unsigned int v9; // ebx
  void *v10; // edi
  int v11; // ebx
  char szError[260]; // [esp+4h] [ebp-10Ch] BYREF
  _iobuf *pfile; // [esp+108h] [ebp-8h] BYREF
  int handle; // [esp+10Ch] [ebp-4h] BYREF

  *bufferptr = nullptr;
  fopen_s(&pfile, file: filename, mode: "rb");
  if ( pfile == nullptr )
    return -1;
  fclose(stream: pfile);
  _sopen_s(pfh: &handle, path: filename, oflag: bText ? 0x4000 : 0x8000, shflag: 32, pmode: 256);
  v3 = handle;
  if ( handle == -1 )
  {
    v4 = _errno();
    strerror_s(buffer: szError, sizeInTChars: 0x104u, errnum: *v4);
    Sys_Error(format: "Sys_LoadFile(): Error opening %s: %s", filename, szError);
    v3 = handle;
  }
  v5 = v3;
  if ( v3 == -1 )
  {
    v7 = -1;
  }
  else
  {
    v6 = _lseek(fh: v3, pos: 0, mthd: 1);
    v7 = _lseek(fh: v5, pos: 0, mthd: 2);
    _lseek(fh: v5, pos: v6, mthd: 0);
  }
  if ( v7 == -1 )
    Sys_Error(format: "Sys_Alloc(): zero size");
  v9 = (v7 + 4) & 0xFFFFFFFC;
  v10 = operator new(nSize: v9);
  if ( v10 == nullptr )
    Sys_Error(format: "Sys_Alloc(): %d bytes not available", v9);
  _V_memset(dest: v10, fill: 0, count: v9);
  v11 = _read(fh: handle, buf: v10, cnt: v7);
  _close(fh: handle);
  if ( bText )
  {
    *((_BYTE *)v10 + v11) = 0;
    *bufferptr = v10;
    return v11;
  }
  else
  {
    if ( v7 != v11 )
      Sys_Error(format: "Sys_LoadFile(): read failure");
    *((_BYTE *)v10 + v7) = 0;
    *bufferptr = v10;
    return v7;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00428110
// Name: char __near * Sys_CopyString(char const __near *)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl Sys_CopyString(char *str)
{
  unsigned int v1; // eax
  unsigned int v2; // ebx
  void *v3; // esi

  v1 = strlen(str);
  v2 = v1 + 1;
  if ( v1 == -1 )
    Sys_Error(format: "Sys_Alloc(): zero size");
  v3 = operator new(nSize: (v2 + 3) & 0xFFFFFFFC);
  if ( v3 == nullptr )
    Sys_Error(format: "Sys_Alloc(): %d bytes not available", (v2 + 3) & 0xFFFFFFFC);
  _V_memset(dest: v3, fill: 0, count: (v2 + 3) & 0xFFFFFFFC);
  memcpy(dst: (unsigned __int8 *)v3, src: (unsigned __int8 *)str, count: v2);
  return (char *)v3;
}

//------------------------------------------------------------------------------
// Address: 0x00428190
// Name: public: int CUtlVector<class CUtlString,class CUtlMemory<class CUtlString,int>>::InsertBefore(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>::InsertBefore(
        CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *this,
        int elem)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CUtlString *m_pMemory; // ecx
  int v6; // eax
  CUtlString *v7; // ecx

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CUtlString,int>::Grow(this: &this->m_Memory, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v6 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 16 * v6);
  v7 = &this->m_Memory.m_pMemory[elem];
  if ( v7 != nullptr )
    CUtlString::CUtlString(this: v7);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x00428200
// Name: public: int CUtlVector<struct fileList_t,class CUtlMemory<struct fileList_t,int>>::InsertBefore(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<fileList_t,CUtlMemory<fileList_t,int>>::InsertBefore(
        CUtlVector<fileList_t,CUtlMemory<fileList_t,int> > *this,
        int elem)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  fileList_t *m_pMemory; // ecx
  int v6; // eax
  fileList_t *v7; // ecx

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<fileList_t,int>::Grow(
      (CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v6 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 24 * v6);
  v7 = &this->m_Memory.m_pMemory[elem];
  if ( v7 != nullptr )
    CUtlString::CUtlString(this: &v7->fileName);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x00428270
// Name: public: int CUtlVector<struct fileList_t,class CUtlMemory<struct fileList_t,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<fileList_t,CUtlMemory<fileList_t,int>>::InsertMultipleBefore(
        CUtlVector<fileList_t,CUtlMemory<fileList_t,int> > *this,
        int elem,
        int num)
{
  int v3; // edi
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  int v8; // edx
  fileList_t *m_pMemory; // ecx
  int v10; // eax
  int v11; // ebx
  fileList_t *v12; // ecx

  v3 = num;
  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<fileList_t,int>::Grow(
      (CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int> *)this,
      num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  v8 = elem;
  m_pMemory = this->m_Memory.m_pMemory;
  v10 = this->m_Size - elem - num;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v10 <= 0 )
    goto LABEL_8;
  if ( num > 0 )
  {
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 24 * v10);
    v8 = elem;
LABEL_8:
    if ( num > 0 )
    {
      v11 = v8;
      do
      {
        v12 = &this->m_Memory.m_pMemory[v11];
        if ( v12 != nullptr )
        {
          CUtlString::CUtlString(this: &v12->fileName);
          v8 = elem;
        }
        ++v11;
        --v3;
      }
      while ( v3 != 0 );
    }
  }
  return v8;
}

//------------------------------------------------------------------------------
// Address: 0x00428310
// Name: GetFileList
// Source: json
//------------------------------------------------------------------------------
int __usercall GetFileList@<eax>(
        const char *pDirPath@<ecx>,
        const char *pPattern@<eax>,
        CUtlVector<fileList_t,CUtlMemory<fileList_t,int> > *fileList)
{
  unsigned int v6; // kr04_4
  int v7; // eax
  char v8; // cl
  char *v9; // edi
  char v10; // al
  unsigned int v11; // eax
  const char *v12; // esi
  char *v13; // edi
  char v14; // cl
  int v15; // esi
  int v17; // eax
  char v18; // cl
  unsigned int v19; // eax
  char *v20; // edi
  char v21; // cl
  char *v22; // edi
  char *v23; // esi
  char v24; // cl
  int m_Size; // eax
  int v26; // esi
  char v27; // [esp+Bh] [ebp-439h] BYREF
  char fileName[260]; // [esp+Ch] [ebp-438h] BYREF
  char fullPath[260]; // [esp+110h] [ebp-334h] BYREF
  _finddata64i32_t findData; // [esp+214h] [ebp-230h] BYREF
  char sourcePath[260]; // [esp+33Ch] [ebp-108h] BYREF
  int h; // [esp+440h] [ebp-4h]
  char bFindDirs_3; // [esp+44Fh] [ebp+Bh]

  CUtlVector<fileList_t,CUtlMemory<fileList_t,int>>::RemoveAll(this: fileList);
  if ( fileList->m_Memory.m_nGrowSize >= 0 )
  {
    if ( fileList->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: fileList->m_Memory.m_pMemory);
      fileList->m_Memory.m_pMemory = nullptr;
    }
    fileList->m_Memory.m_nAllocationCount = 0;
  }
  fileList->m_pElements = fileList->m_Memory.m_pMemory;
  strcpy(sourcePath, pDirPath);
  v6 = strlen(sourcePath);
  if ( v6 != 0 )
  {
    if ( findData.name[v6 + 259] != 92 )
    {
      sourcePath[v6] = 92;
      sourcePath[v6 + 1] = 0;
    }
  }
  else
  {
    strcpy(sourcePath, ".\\");
  }
  v7 = 0;
  do
  {
    v8 = sourcePath[v7];
    fullPath[v7++] = v8;
  }
  while ( v8 != 0 );
  if ( *pPattern != 92 || pPattern[1] != 0 )
  {
    bFindDirs_3 = 0;
    v11 = strlen(pPattern) + 1;
    v12 = pPattern;
    v13 = &fileName[259];
    do
      v14 = *++v13;
    while ( v14 != 0 );
    qmemcpy(v13, v12, v11);
  }
  else
  {
    bFindDirs_3 = 1;
    v9 = &fileName[259];
    do
      v10 = *++v9;
    while ( v10 != 0 );
    strcpy(v9, "*");
  }
  v15 = _findfirst64i32(szWild: fullPath, pfd: &findData);
  h = v15;
  if ( v15 == -1 )
    return 0;
  do
  {
    if ( bFindDirs_3 != 0 )
    {
      if ( (findData.attrib & 0x10) == 0 )
        continue;
    }
    else if ( (findData.attrib & 0x10) != 0 )
    {
      continue;
    }
    if ( _V_stricmp(s1: findData.name, s2: ".") != 0 && _V_stricmp(s1: findData.name, s2: "..") != 0 )
    {
      v17 = 0;
      do
      {
        v18 = sourcePath[v17];
        fileName[v17++] = v18;
      }
      while ( v18 != 0 );
      v19 = strlen(findData.name) + 1;
      v20 = &v27;
      do
        v21 = *++v20;
      while ( v21 != 0 );
      qmemcpy(v20, findData.name, 4 * (v19 >> 2));
      v23 = &findData.name[4 * (v19 >> 2)];
      v22 = &v20[4 * (v19 >> 2)];
      v24 = v19;
      m_Size = fileList->m_Size;
      qmemcpy(v22, v23, v24 & 3);
      v26 = CUtlVector<fileList_t,CUtlMemory<fileList_t,int>>::InsertBefore(this: fileList, elem: m_Size);
      CUtlString::Set(this: &fileList->m_Memory.m_pMemory[v26].fileName, pValue: fileName);
      fileList->m_Memory.m_pMemory[v26].timeWrite = findData.time_write;
      v15 = h;
    }
  }
  while ( _findnext64i32(hFile: v15, pfd: &findData) == 0 );
  _findclose(hFile: v15);
  return fileList->m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x00428560
// Name: RecurseFileTree_r
// Source: json
//------------------------------------------------------------------------------
void __cdecl RecurseFileTree_r(
        const char *pDirPath,
        int depth,
        CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *dirList)
{
  fileList_t *i; // ebx
  int v4; // eax
  int v5; // eax
  fileList_t *m_pMemory; // edi
  const char *v7; // eax
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CUtlString *v10; // ecx
  int v11; // eax
  int v12; // edi
  CUtlString *v13; // ecx
  int v14; // [esp-8h] [ebp-2Ch]
  CUtlVector<fileList_t,CUtlMemory<fileList_t,int> > fileList; // [esp+Ch] [ebp-18h] BYREF
  int v16; // [esp+20h] [ebp-4h]

  i = nullptr;
  memset(&fileList, 0, sizeof(fileList));
  v4 = GetFileList(pDirPath, pPattern: "\\", &fileList);
  if ( v4 != 0 )
  {
    if ( v4 > 0 )
    {
      m_pMemory = fileList.m_Memory.m_pMemory;
      v16 = depth + 1;
      for ( i = (fileList_t *)v4; i != nullptr; i = (fileList_t *)((char *)i - 1) )
      {
        v14 = v16;
        v7 = CUtlString::operator char const *(this: &m_pMemory->fileName);
        RecurseFileTree_r(pDirPath: v7, depth: v14, dirList);
        ++m_pMemory;
      }
    }
    m_Size = dirList->m_Size;
    m_nAllocationCount = dirList->m_Memory.m_nAllocationCount;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<CUtlString,int>::Grow(this: &dirList->m_Memory, num: m_Size - m_nAllocationCount + 1);
    ++dirList->m_Size;
    v10 = dirList->m_Memory.m_pMemory;
    v11 = dirList->m_Size - m_Size - 1;
    dirList->m_pElements = dirList->m_Memory.m_pMemory;
    if ( v11 > (int)i )
      _V_memmove(dest: &v10[m_Size + 1], src: &v10[m_Size], count: 16 * v11);
    v12 = m_Size;
    v13 = &dirList->m_Memory.m_pMemory[v12];
    if ( v13 != nullptr )
      CUtlString::CUtlString(this: v13);
    CUtlString::Set(this: &dirList->m_Memory.m_pMemory[v12], pValue: pDirPath);
    CUtlVector<fileList_t,CUtlMemory<fileList_t,int>>::RemoveAll(this: &fileList);
    if ( fileList.m_Memory.m_nGrowSize >= (int)i && fileList.m_Memory.m_pMemory != i )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: fileList.m_Memory.m_pMemory);
  }
  else
  {
    v5 = CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>::InsertBefore(this: dirList, elem: dirList->m_Size);
    CUtlString::Set(this: &dirList->m_Memory.m_pMemory[v5], pValue: pDirPath);
    CUtlVector<fileList_t,CUtlMemory<fileList_t,int>>::~CUtlVector<fileList_t,CUtlMemory<fileList_t,int>>(this: &fileList);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00428680
// Name: int FindFiles(char __near *,bool,class CUtlVector<struct fileList_t,class CUtlMemory<struct fileList_t,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
int __cdecl FindFiles(char *pFileMask, bool bRecurse, CUtlVector<fileList_t,CUtlMemory<fileList_t,int> > *fileList)
{
  char *v3; // edi
  char v4; // al
  unsigned int v5; // eax
  char *v6; // edi
  char v7; // cl
  int v8; // esi
  int v9; // eax
  fileList_t *v10; // edi
  int v11; // ebx
  fileList_t *v12; // esi
  int v13; // edx
  bool v14; // zf
  int m_nGrowSize; // esi
  fileList_t *m_pMemory; // eax
  const char *v17; // eax
  CUtlVector<fileList_t,CUtlMemory<fileList_t,int> > *v18; // esi
  int m_Size; // edi
  int inserted; // eax
  fileList_t *v21; // edi
  int v22; // ebx
  CUtlString *p_fileName; // esi
  int timeWrite_high; // ecx
  CUtlString *v25; // eax
  int v26; // esi
  unsigned int v28; // [esp-8h] [ebp-348h]
  char extension[260]; // [esp+8h] [ebp-338h] BYREF
  char dirPath[260]; // [esp+10Ch] [ebp-234h] BYREF
  char pattern[260]; // [esp+210h] [ebp-130h] BYREF
  int i; // [esp+314h] [ebp-2Ch]
  CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > dirList; // [esp+318h] [ebp-28h] BYREF
  CUtlVector<fileList_t,CUtlMemory<fileList_t,int> > tempList; // [esp+32Ch] [ebp-14h] BYREF
  char *pFileMaska; // [esp+348h] [ebp+8h]
  int bRecursea; // [esp+34Ch] [ebp+Ch]
  int bRecurseb; // [esp+34Ch] [ebp+Ch]

  strcpy(dirPath, pFileMask);
  V_StripFilename(path: dirPath);
  V_FileBase(in: pFileMask, out: pattern, maxlen: 260);
  V_ExtractFileExtension(path: pFileMask, dest: extension, destSize: 260);
  if ( extension[0] != 0 )
  {
    v3 = &dirPath[259];
    do
      v4 = *++v3;
    while ( v4 != 0 );
    strcpy(v3, ".");
    v5 = strlen(extension) + 1;
    v6 = &dirPath[259];
    do
      v7 = *++v6;
    while ( v7 != 0 );
    qmemcpy(v6, extension, v5);
  }
  memset(&tempList, 0, sizeof(tempList));
  if ( bRecurse )
  {
    memset(&dirList, 0, sizeof(dirList));
    RecurseFileTree_r(pDirPath: dirPath, depth: 0, &dirList);
    i = 0;
    if ( dirList.m_Size > 0 )
    {
      bRecurseb = 0;
      do
      {
        CUtlVector<fileList_t,CUtlMemory<fileList_t,int>>::RemoveAll(this: &tempList);
        m_nGrowSize = tempList.m_Memory.m_nGrowSize;
        m_pMemory = tempList.m_Memory.m_pMemory;
        if ( tempList.m_Memory.m_nGrowSize >= 0 )
        {
          if ( tempList.m_Memory.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: tempList.m_Memory.m_pMemory);
            m_pMemory = nullptr;
            tempList.m_Memory.m_pMemory = nullptr;
          }
          tempList.m_Memory.m_nAllocationCount = 0;
        }
        if ( tempList.m_Memory.m_nAllocationCount < dirList.m_Size && m_nGrowSize >= 0 )
        {
          tempList.m_Memory.m_nAllocationCount = dirList.m_Size;
          v28 = 24 * dirList.m_Size;
          if ( m_pMemory != nullptr )
            m_pMemory = (fileList_t *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v28);
          else
            m_pMemory = (fileList_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v28);
          tempList.m_Memory.m_pMemory = m_pMemory;
        }
        tempList.m_pElements = m_pMemory;
        v17 = CUtlString::operator char const *(this: &dirList.m_Memory.m_pMemory[bRecurseb]);
        GetFileList(pDirPath: v17, pPattern: pattern, fileList: &tempList);
        v18 = fileList;
        m_Size = tempList.m_Size;
        inserted = CUtlVector<fileList_t,CUtlMemory<fileList_t,int>>::InsertMultipleBefore(
                     this: fileList,
                     elem: fileList->m_Size,
                     num: tempList.m_Size);
        if ( m_Size > 0 )
        {
          v21 = tempList.m_Memory.m_pMemory;
          v22 = inserted;
          pFileMaska = (char *)tempList.m_Size;
          while ( 1 )
          {
            p_fileName = &v18->m_Memory.m_pMemory[v22].fileName;
            CUtlString::operator=(this: p_fileName, src: &v21->fileName);
            p_fileName[1].m_Storage.m_Memory.m_pMemory = (unsigned __int8 *)v21->timeWrite;
            timeWrite_high = HIDWORD(v21->timeWrite);
            ++v21;
            ++v22;
            v14 = pFileMaska-- == (char *)1;
            p_fileName[1].m_Storage.m_Memory.m_nAllocationCount = timeWrite_high;
            if ( v14 )
              break;
            v18 = fileList;
          }
        }
        ++bRecurseb;
        ++i;
      }
      while ( i < dirList.m_Size );
    }
    CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>::RemoveAll(this: &dirList);
    v25 = dirList.m_Memory.m_pMemory;
    if ( dirList.m_Memory.m_nGrowSize >= 0 )
    {
      if ( dirList.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: dirList.m_Memory.m_pMemory);
        v25 = nullptr;
        dirList.m_Memory.m_pMemory = nullptr;
      }
      dirList.m_Memory.m_nAllocationCount = 0;
    }
    dirList.m_pElements = v25;
    if ( dirList.m_Memory.m_nGrowSize >= 0 && v25 != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v25);
  }
  else
  {
    GetFileList(pDirPath: dirPath, pPattern: pattern, fileList: &tempList);
    v8 = tempList.m_Size;
    v9 = CUtlVector<fileList_t,CUtlMemory<fileList_t,int>>::InsertMultipleBefore(
           this: fileList,
           elem: fileList->m_Size,
           num: tempList.m_Size);
    if ( v8 > 0 )
    {
      v10 = tempList.m_Memory.m_pMemory;
      v11 = v9;
      bRecursea = v8;
      do
      {
        v12 = &fileList->m_Memory.m_pMemory[v11];
        CUtlString::operator=(this: &v12->fileName, src: &v10->fileName);
        LODWORD(v12->timeWrite) = v10->timeWrite;
        v13 = HIDWORD(v10->timeWrite);
        ++v10;
        ++v11;
        v14 = bRecursea-- == 1;
        HIDWORD(v12->timeWrite) = v13;
      }
      while ( !v14 );
    }
  }
  v26 = fileList->m_Size;
  CUtlVector<fileList_t,CUtlMemory<fileList_t,int>>::RemoveAll(this: &tempList);
  if ( tempList.m_Memory.m_nGrowSize >= 0 && tempList.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: tempList.m_Memory.m_pMemory);
  return v26;
}

//------------------------------------------------------------------------------
// Address: 0x00428950
// Name: bool DeleteFiles(char __near *,bool,bool)
// Source: json
//------------------------------------------------------------------------------
char __cdecl DeleteFiles(char *pFileMask, bool bRecurse, bool bVerbose)
{
  int v3; // edi
  int m_Size; // ebx
  fileList_t *m_pMemory; // esi
  const char *v6; // eax
  const char *v7; // eax
  CUtlVector<fileList_t,CUtlMemory<fileList_t,int> > files; // [esp+Ch] [ebp-14h] BYREF

  v3 = 0;
  memset(&files, 0, sizeof(files));
  FindFiles(pFileMask, bRecurse, fileList: &files);
  m_Size = files.m_Size;
  if ( files.m_Size <= 0 )
  {
LABEL_7:
    CUtlVector<fileList_t,CUtlMemory<fileList_t,int>>::RemoveAll(this: &files);
    if ( files.m_Memory.m_nGrowSize >= 0 && files.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: files.m_Memory.m_pMemory);
    return 1;
  }
  else
  {
    m_pMemory = files.m_Memory.m_pMemory;
    while ( 1 )
    {
      if ( bVerbose )
      {
        v6 = CUtlString::operator char const *(this: &m_pMemory->fileName);
        ConsoleWindowPrintf(rgb: 0, strFormat: "Deleting: %s\n", v6);
      }
      v7 = CUtlString::operator char const *(this: &m_pMemory->fileName);
      if ( !DeleteFileA(lpFileName: v7) )
        break;
      ++v3;
      ++m_pMemory;
      if ( v3 >= m_Size )
        goto LABEL_7;
    }
    CUtlVector<fileList_t,CUtlMemory<fileList_t,int>>::RemoveAll(this: &files);
    if ( files.m_Memory.m_nGrowSize >= 0 && files.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: files.m_Memory.m_pMemory);
    return 0;
  }
}
