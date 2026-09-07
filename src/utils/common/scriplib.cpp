// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/common/scriplib.cpp
// Functions: 30
// ============================================================

#include "utils\common\scriplib.h"

//------------------------------------------------------------------------------
// Address: 0x10005A20
// Name: public: void CUtlVector<struct SortedLump_t,class CUtlMemory<struct SortedLump_t,int>>::Sort(int (*)(struct SortedLump_t const __near *,struct SortedLump_t const __near *))
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<SortedLump_t,CUtlMemory<SortedLump_t,int>>::Sort(
        CUtlVector<SortedLump_t,CUtlMemory<SortedLump_t,int> > *this,
        int (__cdecl *pfnCompare)(const void *, const void *))
{
  signed int m_Size; // ebx
  int v4; // ebx
  int j; // esi
  int lumpNum; // ecx
  lump_t *pLump; // edx
  SortedLump_t *v8; // eax
  int i; // [esp+8h] [ebp-4h]

  m_Size = this->m_Size;
  if ( m_Size > 1 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      qsort(base: this->m_Memory.m_pMemory, num: m_Size, width: 8u, comp: pfnCompare);
    }
    else
    {
      v4 = m_Size - 1;
      for ( i = v4; v4 >= 0; i = v4 )
      {
        for ( j = 1; j <= v4; ++j )
        {
          if ( pfnCompare(a1: &this->m_Memory.m_pMemory[j - 1], a2: &this->m_Memory.m_pMemory[j]) < 0 )
          {
            lumpNum = this->m_Memory.m_pMemory[j - 1].lumpNum;
            pLump = this->m_Memory.m_pMemory[j - 1].pLump;
            v8 = &this->m_Memory.m_pMemory[j];
            v8[-1].lumpNum = v8->lumpNum;
            v8[-1].pLump = v8->pLump;
            v4 = i;
            v8->lumpNum = lumpNum;
            v8->pLump = pLump;
          }
        }
        --v4;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10007E80
// Name: public: int CUtlVector<struct texinfo_s,class CUtlMemory<struct texinfo_s,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<texinfo_s,CUtlMemory<texinfo_s,int>>::InsertMultipleBefore(
        CUtlVector<texinfo_s,CUtlMemory<texinfo_s,int> > *this,
        int elem,
        int num)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  texinfo_s *m_pMemory; // ecx
  int v8; // eax
  int v9; // eax

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<texinfo_s,int>::Grow(this: &this->m_Memory, num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v8 = this->m_Size;
  this->m_pElements = this->m_Memory.m_pMemory;
  v9 = v8 - elem - num;
  if ( v9 > 0 && num > 0 )
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 72 * v9);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x100085A0
// Name: public: int CUtlVector<unsigned short,class CUtlMemory<unsigned short,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<unsigned short,CUtlMemory<unsigned short,int>>::InsertMultipleBefore(
        CUtlVector<CFaceMacroTextureInfo,CUtlMemory<CFaceMacroTextureInfo,int> > *this,
        int elem,
        int num)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CFaceMacroTextureInfo *m_pMemory; // ecx
  int v8; // eax
  int v9; // eax

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<CFaceMacroTextureInfo,int>::Grow(this: &this->m_Memory, num: num + m_Size - m_nAllocationCount);
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
// Address: 0x10008610
// Name: public: int CUtlVector<struct doccluderdata_t,class CUtlMemory<struct doccluderdata_t,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<doccluderdata_t,CUtlMemory<doccluderdata_t,int>>::InsertMultipleBefore(
        CUtlVector<doccluderdata_t,CUtlMemory<doccluderdata_t,int> > *this,
        int elem,
        int num)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  doccluderdata_t *m_pMemory; // ecx
  int v8; // eax
  int v9; // eax

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<doccluderdata_t,int>::Grow(this: &this->m_Memory, num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v8 = this->m_Size;
  this->m_pElements = this->m_Memory.m_pMemory;
  v9 = v8 - elem - num;
  if ( v9 > 0 && num > 0 )
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 40 * v9);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x10008690
// Name: public: int CUtlVector<struct doccluderpolydata_t,class CUtlMemory<struct doccluderpolydata_t,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<doccluderpolydata_t,CUtlMemory<doccluderpolydata_t,int>>::InsertMultipleBefore(
        CUtlVector<doccluderpolydata_t,CUtlMemory<doccluderpolydata_t,int> > *this,
        int elem,
        int num)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  doccluderpolydata_t *m_pMemory; // ecx
  int v8; // eax
  int v9; // eax

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<doccluderpolydata_t,int>::Grow(this: &this->m_Memory, num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v8 = this->m_Size;
  this->m_pElements = this->m_Memory.m_pMemory;
  v9 = v8 - elem - num;
  if ( v9 > 0 && num > 0 )
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 12 * v9);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x10008890
// Name: public: int CUtlVector<struct dfacebrushlist_t,class CUtlMemory<struct dfacebrushlist_t,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<dfacebrushlist_t,CUtlMemory<dfacebrushlist_t,int>>::InsertMultipleBefore(
        CUtlVector<dfacebrushlist_t,CUtlMemory<dfacebrushlist_t,int> > *this,
        int elem,
        int num)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  dfacebrushlist_t *m_pMemory; // ecx
  int v8; // eax
  int v9; // eax

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<int,int>::Grow(
      (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)this,
      num: num + m_Size - m_nAllocationCount);
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
// Address: 0x10008900
// Name: public: int CUtlVector<struct dleafambientlighting_t,class CUtlMemory<struct dleafambientlighting_t,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<dleafambientlighting_t,CUtlMemory<dleafambientlighting_t,int>>::InsertMultipleBefore(
        CUtlVector<dleafambientlighting_t,CUtlMemory<dleafambientlighting_t,int> > *this,
        int elem,
        int num)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  dleafambientlighting_t *m_pMemory; // ecx
  int v8; // eax
  int v9; // eax

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<dleafambientlighting_t,int>::Grow(this: &this->m_Memory, num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v8 = this->m_Size;
  this->m_pElements = this->m_Memory.m_pMemory;
  v9 = v8 - elem - num;
  if ( v9 > 0 && num > 0 )
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 28 * v9);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x10008990
// Name: public: int CUtlVector<class ddispinfo_t,class CUtlMemory<class ddispinfo_t,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<ddispinfo_t,CUtlMemory<ddispinfo_t,int>>::InsertMultipleBefore(
        CUtlVector<ddispinfo_t,CUtlMemory<ddispinfo_t,int> > *this,
        int elem,
        int num)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  ddispinfo_t *m_pMemory; // ecx
  int v8; // eax
  int v9; // eax

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<ddispinfo_t,int>::Grow(this: &this->m_Memory, num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v8 = this->m_Size;
  this->m_pElements = this->m_Memory.m_pMemory;
  v9 = v8 - elem - num;
  if ( v9 > 0 && num > 0 )
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 176 * v9);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x10008A10
// Name: public: int CUtlVector<class CDispVert,class CUtlMemory<class CDispVert,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CDispVert,CUtlMemory<CDispVert,int>>::InsertMultipleBefore(
        CUtlVector<CDispVert,CUtlMemory<CDispVert,int> > *this,
        int elem,
        int num)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CDispVert *m_pMemory; // ecx
  int v8; // eax
  int v9; // eax

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<CDispVert,int>::Grow(this: &this->m_Memory, num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v8 = this->m_Size;
  this->m_pElements = this->m_Memory.m_pMemory;
  v9 = v8 - elem - num;
  if ( v9 > 0 && num > 0 )
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 20 * v9);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x10008A90
// Name: public: int CUtlVector<class CDispMultiBlend,class CUtlMemory<class CDispMultiBlend,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CDispMultiBlend,CUtlMemory<CDispMultiBlend,int>>::InsertMultipleBefore(
        CUtlVector<CDispMultiBlend,CUtlMemory<CDispMultiBlend,int> > *this,
        int elem,
        int num)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CDispMultiBlend *m_pMemory; // ecx
  int v8; // eax
  int v9; // eax

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<CDispMultiBlend,int>::Grow(this: &this->m_Memory, num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v8 = this->m_Size;
  this->m_pElements = this->m_Memory.m_pMemory;
  v9 = v8 - elem - num;
  if ( v9 > 0 && num > 0 )
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 80 * v9);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x10009580
// Name: public: CUtlVector<struct dleafambientlighting_t,class CUtlMemory<struct dleafambientlighting_t,int>>::~CUtlVector<struct dleafambientlighting_t,class CUtlMemory<struct dleafambientlighting_t,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<dleafambientlighting_t,CUtlMemory<dleafambientlighting_t,int>>::~CUtlVector<dleafambientlighting_t,CUtlMemory<dleafambientlighting_t,int>>(
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
// Address: 0x10009780
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
// Address: 0x1000CEC0
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
// Address: 0x1000DFB0
// Name: public: void CUtlVector<struct clusterlist_t,class CUtlMemory<struct clusterlist_t,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<clusterlist_t,CUtlMemory<clusterlist_t,int>>::RemoveAll(
        CUtlVector<clusterlist_t,CUtlMemory<clusterlist_t,int> > *this)
{
  int v1; // ebx
  int v2; // eax
  char *v3; // esi
  void *v4; // eax
  int v5; // [esp+4h] [ebp-8h]
  CUtlVector<clusterlist_t,CUtlMemory<clusterlist_t,int> > *v6; // [esp+8h] [ebp-4h]

  v1 = this->m_Size - 1;
  v6 = this;
  if ( v1 < 0 )
  {
    this->m_Size = 0;
  }
  else
  {
    v2 = 24 * v1;
    v5 = 24 * v1;
    do
    {
      v3 = (char *)this->m_Memory.m_pMemory + v2;
      *((_DWORD *)v3 + 4) = 0;
      if ( *((int *)v3 + 3) >= 0 )
      {
        if ( *((_DWORD *)v3 + 1) != 0 )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *((void **)v3 + 1));
          this = v6;
          *((_DWORD *)v3 + 1) = 0;
        }
        *((_DWORD *)v3 + 2) = 0;
      }
      v4 = *((void **)v3 + 1);
      *((_DWORD *)v3 + 5) = v4;
      if ( *((int *)v3 + 3) >= 0 )
      {
        if ( v4 != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v4);
          this = v6;
          *((_DWORD *)v3 + 1) = 0;
        }
        *((_DWORD *)v3 + 2) = 0;
      }
      --v1;
      v2 = v5 - 24;
      v5 -= 24;
    }
    while ( v1 >= 0 );
    this->m_Size = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000FEE0
// Name: public: CUtlVector<struct clusterlist_t,class CUtlMemory<struct clusterlist_t,int>>::~CUtlVector<struct clusterlist_t,class CUtlMemory<struct clusterlist_t,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<clusterlist_t,CUtlMemory<clusterlist_t,int>>::~CUtlVector<clusterlist_t,CUtlMemory<clusterlist_t,int>>(
        CUtlVector<clusterlist_t,CUtlMemory<clusterlist_t,int> > *this)
{
  bool v2; // sf
  clusterlist_t *m_pMemory; // eax

  CUtlVector<clusterlist_t,CUtlMemory<clusterlist_t,int>>::RemoveAll(this);
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
// Address: 0x1000FF40
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
// Address: 0x100125B0
// Name: public: virtual bool CScriptLib::DoesFileExist(char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CScriptLib::DoesFileExist(CScriptLib *this, const char *pFilename)
{
  return g_pFullFileSystem->FileExists(this: &g_pFullFileSystem->IBaseFileSystem, a2: pFilename, a3: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x100125D0
// Name: public: virtual bool CScriptLib::ReadFileToBuffer(char const __near *,class CUtlBuffer __near &,bool,bool)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CScriptLib::ReadFileToBuffer(
        CScriptLib *this,
        const char *pSourceName,
        CUtlBuffer *buffer,
        bool bText,
        bool bNoOpenFailureWarning)
{
  int *v5; // eax
  const char *v6; // eax

  if ( g_pFullFileSystem->ReadFile(
         this: &g_pFullFileSystem->IBaseFileSystem,
         a2: pSourceName,
         a3: nullptr,
         a4: buffer,
         a5: 0,
         a6: 0,
         a7: nullptr) )
  {
    if ( bText )
      CUtlBuffer::SetBufferType(this: buffer, bIsText: true, bContainsCRLF: true);
    else
      CUtlBuffer::SetBufferType(this: buffer, bIsText: false, bContainsCRLF: false);
    return 1;
  }
  else
  {
    if ( !bNoOpenFailureWarning )
    {
      v5 = _errno();
      v6 = strerror(errnum: *v5);
      _Msg(a1: "ReadFileToBuffer(): Error opening %s: %s\n", pSourceName, v6);
    }
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10012650
// Name: public: virtual bool CScriptLib::WriteBufferToFile(char const __near *,class CUtlBuffer __near &,enum DiskWriteMode_t)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CScriptLib::WriteBufferToFile(
        CScriptLib *this,
        const char *pTargetName,
        CUtlBuffer *buffer,
        DiskWriteMode_t writeMode)
{
  _BYTE *v5; // eax
  _BYTE *v6; // esi
  _BYTE *v7; // eax
  char dirPath[260]; // [esp+8h] [ebp-104h] BYREF

  strcpy(dirPath, pTargetName);
  strchr(string: (unsigned __int8 *)dirPath, chr: 0x5Cu);
  v6 = v5;
  if ( v5 != nullptr )
  {
    while ( 1 )
    {
      strchr(string: v6 + 1, chr: 0x5Cu);
      v6 = v7;
      if ( v7 == nullptr )
        break;
      *v7 = 0;
      _mkdir(path: dirPath);
      *v6 = 92;
    }
  }
  return writeMode != WRITE_TO_DISK_ALWAYS
      && (writeMode != WRITE_TO_DISK_UPDATE || !this->DoesFileExist(this, a2: pTargetName))
      || g_pFullFileSystem->WriteFile(
           this: &g_pFullFileSystem->IBaseFileSystem,
           a2: pTargetName,
           a3: nullptr,
           a4: buffer);
}

//------------------------------------------------------------------------------
// Address: 0x10012710
// Name: public: virtual int CScriptLib::CompareFileTime(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CScriptLib::CompareFileTime(CScriptLib *this, const char *pFilenameA, const char *pFilenameB)
{
  unsigned int v3; // esi
  unsigned int v4; // eax
  bool v5; // cf

  v3 = g_pFullFileSystem->GetFileTime(this: &g_pFullFileSystem->IBaseFileSystem, a2: pFilenameA, a3: nullptr);
  v4 = g_pFullFileSystem->GetFileTime(this: &g_pFullFileSystem->IBaseFileSystem, a2: pFilenameB, a3: nullptr);
  if ( v3 == -1 )
    v3 = 0;
  if ( v4 == -1 )
    return v3 != 0;
  v5 = v4 < v3;
  if ( v4 <= v3 )
    return v5;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x10012770
// Name: public: virtual char __near * CScriptLib::MakeTemporaryFilename(char const __near *,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CScriptLib::MakeTemporaryFilename(CScriptLib *this, const char *pchModPath, char *pPath, int pathSize)
{
  char *v4; // eax
  char *v5; // esi

  v4 = _tempnam(dir: pchModPath, pfx: "mgd_");
  v5 = v4;
  if ( *v4 == 92 )
    v5 = v4 + 1;
  if ( v5[strlen(v5) - 1] == 46 )
    v5[strlen(v5) - 1] = 0;
  V_snprintf(pDest: pPath, maxLen: pathSize, pFormat: "%s.tmp", v5);
  free(pMem: v5);
  return pPath;
}

//------------------------------------------------------------------------------
// Address: 0x10012880
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
// Address: 0x100128F0
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
    CUtlMemory<fileList_t,int>::Grow(this: &this->m_Memory, num: m_Size - m_nAllocationCount + 1);
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
// Address: 0x10012960
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
    CUtlMemory<fileList_t,int>::Grow(this: &this->m_Memory, num: num + m_Size - m_nAllocationCount);
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
// Address: 0x10012A00
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
// Address: 0x10012A70
// Name: private: int CScriptLib::GetFileList(char const __near *,char const __near *,class CUtlVector<struct fileList_t,class CUtlMemory<struct fileList_t,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CScriptLib::GetFileList(
        CScriptLib *this,
        const char *pDirPath,
        const char *pPattern,
        CUtlVector<fileList_t,CUtlMemory<fileList_t,int> > *fileList)
{
  unsigned int v5; // kr00_4
  int v6; // eax
  char v7; // cl
  char *v8; // edi
  char v9; // al
  unsigned int v10; // eax
  char *v11; // edi
  char v12; // cl
  int v13; // esi
  int v15; // eax
  char v16; // cl
  unsigned int v17; // eax
  char *v18; // edi
  char v19; // cl
  char *v20; // edi
  char *v21; // esi
  char v22; // cl
  int m_Size; // eax
  int v24; // esi
  char v25; // [esp+Bh] [ebp-435h] BYREF
  char fileName[260]; // [esp+Ch] [ebp-434h] BYREF
  char fullPath[260]; // [esp+110h] [ebp-330h] BYREF
  _finddata64i32_t findData; // [esp+214h] [ebp-22Ch] BYREF
  char sourcePath[260]; // [esp+33Ch] [ebp-104h] BYREF
  int h; // [esp+448h] [ebp+8h]
  char bFindDirs_3; // [esp+453h] [ebp+13h]

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
  v5 = strlen(sourcePath);
  if ( v5 != 0 )
  {
    if ( findData.name[v5 + 259] != 92 )
    {
      sourcePath[v5] = 92;
      sourcePath[v5 + 1] = 0;
    }
  }
  else
  {
    strcpy(sourcePath, ".\\");
  }
  v6 = 0;
  do
  {
    v7 = sourcePath[v6];
    fullPath[v6++] = v7;
  }
  while ( v7 != 0 );
  if ( *pPattern != 92 || pPattern[1] != 0 )
  {
    bFindDirs_3 = 0;
    v10 = strlen(pPattern) + 1;
    v11 = &fileName[259];
    do
      v12 = *++v11;
    while ( v12 != 0 );
    qmemcpy(v11, pPattern, v10);
  }
  else
  {
    bFindDirs_3 = 1;
    v8 = &fileName[259];
    do
      v9 = *++v8;
    while ( v9 != 0 );
    strcpy(v8, "*");
  }
  v13 = _findfirst64i32(szWild: fullPath, pfd: &findData);
  h = v13;
  if ( v13 == -1 )
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
      v15 = 0;
      do
      {
        v16 = sourcePath[v15];
        fileName[v15++] = v16;
      }
      while ( v16 != 0 );
      v17 = strlen(findData.name) + 1;
      v18 = &v25;
      do
        v19 = *++v18;
      while ( v19 != 0 );
      qmemcpy(v18, findData.name, 4 * (v17 >> 2));
      v21 = &findData.name[4 * (v17 >> 2)];
      v20 = &v18[4 * (v17 >> 2)];
      v22 = v17;
      m_Size = fileList->m_Size;
      qmemcpy(v20, v21, v22 & 3);
      v24 = CUtlVector<fileList_t,CUtlMemory<fileList_t,int>>::InsertBefore(this: fileList, elem: m_Size);
      CUtlString::Set(this: &fileList->m_Memory.m_pMemory[v24].fileName, pValue: fileName);
      fileList->m_Memory.m_pMemory[v24].timeWrite = findData.time_write;
      v13 = h;
    }
  }
  while ( _findnext64i32(hFile: v13, pfd: &findData) == 0 );
  _findclose(hFile: v13);
  return fileList->m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x10012CD0
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
// Address: 0x10012D30
// Name: public: virtual void CScriptLib::DeleteTemporaryFiles(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CScriptLib::DeleteTemporaryFiles(CScriptLib *this, const char *pFileMask)
{
  char *v2; // eax
  char *v3; // edx
  char v4; // cl
  unsigned int v5; // eax
  char *v6; // edi
  char v7; // cl
  int (__thiscall *FindFiles)(struct CScriptLib *, char *, bool, CUtlVector<fileList_t,CUtlMemory<fileList_t,int> > *); // edx
  int v9; // esi
  int v10; // edi
  const char *v11; // eax
  fileList_t *m_pMemory; // eax
  char v13; // [esp+3h] [ebp-11Dh] BYREF
  char tempPath[260]; // [esp+4h] [ebp-11Ch] BYREF
  CScriptLib *v15; // [esp+108h] [ebp-18h]
  CUtlVector<fileList_t,CUtlMemory<fileList_t,int> > fileList; // [esp+10Ch] [ebp-14h] BYREF

  v15 = this;
  v2 = getenv(option: "temp");
  if ( v2 != nullptr || (v2 = getenv(option: "tmp")) != nullptr )
  {
    v3 = (char *)(tempPath - v2);
    do
    {
      v4 = *v2;
      v2[(_DWORD)v3] = *v2;
      ++v2;
    }
    while ( v4 != 0 );
    V_AppendSlash(pStr: tempPath, strSize: 260);
    v5 = strlen(pFileMask) + 1;
    v6 = &v13;
    do
      v7 = *++v6;
    while ( v7 != 0 );
    qmemcpy(v6, pFileMask, v5);
    FindFiles = v15->FindFiles;
    memset(&fileList, 0, sizeof(fileList));
    FindFiles(this: v15, a2: tempPath, a3: false, a4: &fileList);
    v9 = 0;
    if ( fileList.m_Size > 0 )
    {
      v10 = 0;
      do
      {
        v11 = CUtlString::Get(this: &fileList.m_Memory.m_pMemory[v10].fileName);
        _unlink(path: v11);
        ++v9;
        ++v10;
      }
      while ( v9 < fileList.m_Size );
    }
    CUtlVector<fileList_t,CUtlMemory<fileList_t,int>>::RemoveAll(this: &fileList);
    m_pMemory = fileList.m_Memory.m_pMemory;
    if ( fileList.m_Memory.m_nGrowSize >= 0 )
    {
      if ( fileList.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: fileList.m_Memory.m_pMemory);
        m_pMemory = nullptr;
        fileList.m_Memory.m_pMemory = nullptr;
      }
      fileList.m_Memory.m_nAllocationCount = 0;
    }
    fileList.m_pElements = m_pMemory;
    if ( fileList.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10012E60
// Name: private: void CScriptLib::RecurseFileTree_r(char const __near *,int,class CUtlVector<class CUtlString,class CUtlMemory<class CUtlString,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CScriptLib::RecurseFileTree_r(
        CScriptLib *this,
        const char *pDirPath,
        int depth,
        CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *dirList)
{
  fileList_t *i; // ebx
  int v5; // eax
  int v6; // eax
  fileList_t *m_pMemory; // edi
  const char *v8; // eax
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CUtlString *v11; // ecx
  int v12; // eax
  int v13; // edi
  CUtlString *v14; // ecx
  CUtlVector<fileList_t,CUtlMemory<fileList_t,int> > fileList; // [esp+Ch] [ebp-18h] BYREF
  CScriptLib *v16; // [esp+20h] [ebp-4h]

  i = nullptr;
  v16 = this;
  memset(&fileList, 0, sizeof(fileList));
  v5 = CScriptLib::GetFileList(this, pDirPath, pPattern: "\\", &fileList);
  if ( v5 != 0 )
  {
    if ( v5 > 0 )
    {
      m_pMemory = fileList.m_Memory.m_pMemory;
      for ( i = (fileList_t *)v5; i != nullptr; i = (fileList_t *)((char *)i - 1) )
      {
        v8 = CUtlString::Get(this: &m_pMemory->fileName);
        CScriptLib::RecurseFileTree_r(this: v16, pDirPath: v8, depth: depth + 1, dirList);
        ++m_pMemory;
      }
    }
    m_Size = dirList->m_Size;
    m_nAllocationCount = dirList->m_Memory.m_nAllocationCount;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<CUtlString,int>::Grow(this: &dirList->m_Memory, num: m_Size - m_nAllocationCount + 1);
    ++dirList->m_Size;
    v11 = dirList->m_Memory.m_pMemory;
    v12 = dirList->m_Size - m_Size - 1;
    dirList->m_pElements = dirList->m_Memory.m_pMemory;
    if ( v12 > (int)i )
      _V_memmove(dest: &v11[m_Size + 1], src: &v11[m_Size], count: 16 * v12);
    v13 = m_Size;
    v14 = &dirList->m_Memory.m_pMemory[v13];
    if ( v14 != nullptr )
      CUtlString::CUtlString(this: v14);
    CUtlString::Set(this: &dirList->m_Memory.m_pMemory[v13], pValue: pDirPath);
    CUtlVector<fileList_t,CUtlMemory<fileList_t,int>>::RemoveAll(this: &fileList);
    if ( fileList.m_Memory.m_nGrowSize >= (int)i && fileList.m_Memory.m_pMemory != i )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: fileList.m_Memory.m_pMemory);
  }
  else
  {
    v6 = CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>::InsertBefore(this: dirList, elem: dirList->m_Size);
    CUtlString::Set(this: &dirList->m_Memory.m_pMemory[v6], pValue: pDirPath);
    CUtlVector<fileList_t,CUtlMemory<fileList_t,int>>::~CUtlVector<fileList_t,CUtlMemory<fileList_t,int>>(this: &fileList);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10012F80
// Name: public: virtual int CScriptLib::FindFiles(char __near *,bool,class CUtlVector<struct fileList_t,class CUtlMemory<struct fileList_t,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CScriptLib::FindFiles(
        CScriptLib *this,
        char *pFileMask,
        bool bRecurse,
        CUtlVector<fileList_t,CUtlMemory<fileList_t,int> > *fileList)
{
  CScriptLib *v4; // edi
  char *v5; // edi
  char v6; // al
  unsigned int v7; // eax
  char *v8; // edi
  char v9; // cl
  int m_nGrowSize; // esi
  fileList_t *m_pMemory; // eax
  const char *v13; // eax
  CUtlVector<fileList_t,CUtlMemory<fileList_t,int> > *v14; // esi
  int m_Size; // edi
  int inserted; // eax
  fileList_t *v17; // edi
  int v18; // ebx
  CUtlString *p_fileName; // esi
  int timeWrite_high; // eax
  bool v21; // zf
  CUtlString *v22; // eax
  unsigned int v23; // [esp-8h] [ebp-34Ch]
  char extension[260]; // [esp+8h] [ebp-33Ch] BYREF
  char dirPath[260]; // [esp+10Ch] [ebp-238h] BYREF
  char pattern[260]; // [esp+210h] [ebp-134h] BYREF
  CScriptLib *v27; // [esp+314h] [ebp-30h]
  int i; // [esp+318h] [ebp-2Ch]
  CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > dirList; // [esp+31Ch] [ebp-28h] BYREF
  CUtlVector<fileList_t,CUtlMemory<fileList_t,int> > tempList; // [esp+330h] [ebp-14h] BYREF
  char *pFileMaska; // [esp+34Ch] [ebp+8h]
  int bRecursea; // [esp+350h] [ebp+Ch]

  v4 = this;
  v27 = this;
  strcpy(dirPath, pFileMask);
  V_StripFilename(path: dirPath);
  V_FileBase(in: pFileMask, out: pattern, maxlen: 260);
  V_ExtractFileExtension(path: pFileMask, dest: extension, destSize: 260);
  if ( extension[0] != 0 )
  {
    v5 = &dirPath[259];
    do
      v6 = *++v5;
    while ( v6 != 0 );
    strcpy(v5, ".");
    v7 = strlen(extension) + 1;
    v8 = &dirPath[259];
    do
      v9 = *++v8;
    while ( v9 != 0 );
    qmemcpy(v8, extension, v7);
    v4 = v27;
  }
  if ( bRecurse )
  {
    memset(&tempList, 0, sizeof(tempList));
    memset(&dirList, 0, sizeof(dirList));
    CScriptLib::RecurseFileTree_r(this: v4, pDirPath: dirPath, depth: 0, &dirList);
    i = 0;
    if ( dirList.m_Size > 0 )
    {
      bRecursea = 0;
      while ( 1 )
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
          v23 = 24 * dirList.m_Size;
          if ( m_pMemory != nullptr )
            m_pMemory = (fileList_t *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v23);
          else
            m_pMemory = (fileList_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v23);
          tempList.m_Memory.m_pMemory = m_pMemory;
        }
        tempList.m_pElements = m_pMemory;
        v13 = CUtlString::Get(this: &dirList.m_Memory.m_pMemory[bRecursea]);
        CScriptLib::GetFileList(this: v4, pDirPath: v13, pPattern: pattern, fileList: &tempList);
        v14 = fileList;
        m_Size = tempList.m_Size;
        inserted = CUtlVector<fileList_t,CUtlMemory<fileList_t,int>>::InsertMultipleBefore(
                     this: fileList,
                     elem: fileList->m_Size,
                     num: tempList.m_Size);
        if ( m_Size > 0 )
        {
          v17 = tempList.m_Memory.m_pMemory;
          v18 = inserted;
          pFileMaska = (char *)tempList.m_Size;
          while ( 1 )
          {
            p_fileName = &v14->m_Memory.m_pMemory[v18].fileName;
            CUtlString::operator=(this: p_fileName, src: &v17->fileName);
            p_fileName[1].m_Storage.m_Memory.m_pMemory = (unsigned __int8 *)v17->timeWrite;
            timeWrite_high = HIDWORD(v17->timeWrite);
            ++v17;
            ++v18;
            v21 = pFileMaska-- == (char *)1;
            p_fileName[1].m_Storage.m_Memory.m_nAllocationCount = timeWrite_high;
            if ( v21 )
              break;
            v14 = fileList;
          }
        }
        ++bRecursea;
        if ( ++i >= dirList.m_Size )
          break;
        v4 = v27;
      }
    }
    CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>::RemoveAll(this: &dirList);
    v22 = dirList.m_Memory.m_pMemory;
    if ( dirList.m_Memory.m_nGrowSize >= 0 )
    {
      if ( dirList.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: dirList.m_Memory.m_pMemory);
        v22 = nullptr;
        dirList.m_Memory.m_pMemory = nullptr;
      }
      dirList.m_Memory.m_nAllocationCount = 0;
    }
    dirList.m_pElements = v22;
    if ( dirList.m_Memory.m_nGrowSize >= 0 )
    {
      if ( v22 != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v22);
        dirList.m_Memory.m_pMemory = nullptr;
      }
      dirList.m_Memory.m_nAllocationCount = 0;
    }
    CUtlVector<fileList_t,CUtlMemory<fileList_t,int>>::RemoveAll(this: &tempList);
    if ( tempList.m_Memory.m_nGrowSize < 0 )
    {
      return fileList->m_Size;
    }
    else
    {
      if ( tempList.m_Memory.m_pMemory != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: tempList.m_Memory.m_pMemory);
      return fileList->m_Size;
    }
  }
  else
  {
    CScriptLib::GetFileList(this: v4, pDirPath: dirPath, pPattern: pattern, fileList);
    return fileList->m_Size;
  }
}

// ============================================================
// Overlay from bspzip (Missing functions)
// ============================================================
namespace bspzip {

//------------------------------------------------------------------------------
// Address: 0x00404420
// Name: public: int CUtlVector<struct texinfo_s,class CUtlMemory<struct texinfo_s,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<texinfo_s,CUtlMemory<texinfo_s,int>>::InsertMultipleBefore(
        CUtlVector<texinfo_s,CUtlMemory<texinfo_s,int> > *this,
        int elem,
        int num)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  texinfo_s *m_pMemory; // ecx
  int v8; // eax
  int v9; // eax

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<texinfo_s,int>::Grow(this: &this->m_Memory, num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v8 = this->m_Size;
  this->m_pElements = this->m_Memory.m_pMemory;
  v9 = v8 - elem - num;
  if ( v9 > 0 && num > 0 )
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 72 * v9);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x00404990
// Name: public: int CUtlVector<struct doccluderdata_t,class CUtlMemory<struct doccluderdata_t,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<doccluderdata_t,CUtlMemory<doccluderdata_t,int>>::InsertMultipleBefore(
        CUtlVector<doccluderdata_t,CUtlMemory<doccluderdata_t,int> > *this,
        int elem,
        int num)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  doccluderdata_t *m_pMemory; // ecx
  int v8; // eax
  int v9; // eax

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<doccluderdata_t,int>::Grow(this: &this->m_Memory, num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v8 = this->m_Size;
  this->m_pElements = this->m_Memory.m_pMemory;
  v9 = v8 - elem - num;
  if ( v9 > 0 && num > 0 )
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 40 * v9);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x00404A10
// Name: public: int CUtlVector<struct doccluderpolydata_t,class CUtlMemory<struct doccluderpolydata_t,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<doccluderpolydata_t,CUtlMemory<doccluderpolydata_t,int>>::InsertMultipleBefore(
        CUtlVector<doccluderpolydata_t,CUtlMemory<doccluderpolydata_t,int> > *this,
        int elem,
        int num)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  doccluderpolydata_t *m_pMemory; // ecx
  int v8; // eax
  int v9; // eax

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<doccluderpolydata_t,int>::Grow(this: &this->m_Memory, num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v8 = this->m_Size;
  this->m_pElements = this->m_Memory.m_pMemory;
  v9 = v8 - elem - num;
  if ( v9 > 0 && num > 0 )
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 12 * v9);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x00404C10
// Name: public: int CUtlVector<struct dleafambientlighting_t,class CUtlMemory<struct dleafambientlighting_t,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<dleafambientlighting_t,CUtlMemory<dleafambientlighting_t,int>>::InsertMultipleBefore(
        CUtlVector<dleafambientlighting_t,CUtlMemory<dleafambientlighting_t,int> > *this,
        int elem,
        int num)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  dleafambientlighting_t *m_pMemory; // ecx
  int v8; // eax
  int v9; // eax

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<dleafambientlighting_t,int>::Grow(this: &this->m_Memory, num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v8 = this->m_Size;
  this->m_pElements = this->m_Memory.m_pMemory;
  v9 = v8 - elem - num;
  if ( v9 > 0 && num > 0 )
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 28 * v9);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x00404CA0
// Name: public: int CUtlVector<class ddispinfo_t,class CUtlMemory<class ddispinfo_t,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<ddispinfo_t,CUtlMemory<ddispinfo_t,int>>::InsertMultipleBefore(
        CUtlVector<ddispinfo_t,CUtlMemory<ddispinfo_t,int> > *this,
        int elem,
        int num)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  ddispinfo_t *m_pMemory; // ecx
  int v8; // eax
  int v9; // eax

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<ddispinfo_t,int>::Grow(this: &this->m_Memory, num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v8 = this->m_Size;
  this->m_pElements = this->m_Memory.m_pMemory;
  v9 = v8 - elem - num;
  if ( v9 > 0 && num > 0 )
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 176 * v9);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x00404D20
// Name: public: int CUtlVector<class CDispVert,class CUtlMemory<class CDispVert,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CDispVert,CUtlMemory<CDispVert,int>>::InsertMultipleBefore(
        CUtlVector<CDispVert,CUtlMemory<CDispVert,int> > *this,
        int elem,
        int num)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CDispVert *m_pMemory; // ecx
  int v8; // eax
  int v9; // eax

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<CDispVert,int>::Grow(this: &this->m_Memory, num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v8 = this->m_Size;
  this->m_pElements = this->m_Memory.m_pMemory;
  v9 = v8 - elem - num;
  if ( v9 > 0 && num > 0 )
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 20 * v9);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x00404DA0
// Name: public: int CUtlVector<class CDispMultiBlend,class CUtlMemory<class CDispMultiBlend,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CDispMultiBlend,CUtlMemory<CDispMultiBlend,int>>::InsertMultipleBefore(
        CUtlVector<CDispMultiBlend,CUtlMemory<CDispMultiBlend,int> > *this,
        int elem,
        int num)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CDispMultiBlend *m_pMemory; // ecx
  int v8; // eax
  int v9; // eax

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<CDispMultiBlend,int>::Grow(this: &this->m_Memory, num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v8 = this->m_Size;
  this->m_pElements = this->m_Memory.m_pMemory;
  v9 = v8 - elem - num;
  if ( v9 > 0 && num > 0 )
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 80 * v9);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x00404E20
// Name: public: int CUtlVector<struct dfacebrushlist_t,class CUtlMemory<struct dfacebrushlist_t,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<dfacebrushlist_t,CUtlMemory<dfacebrushlist_t,int>>::InsertMultipleBefore(
        CUtlVector<dfacebrushlist_t,CUtlMemory<dfacebrushlist_t,int> > *this,
        int elem,
        int num)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  dfacebrushlist_t *m_pMemory; // ecx
  int v8; // eax
  int v9; // eax

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<int,int>::Grow(
      (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)this,
      num: num + m_Size - m_nAllocationCount);
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
// Address: 0x00404E90
// Name: public: int CUtlVector<unsigned short,class CUtlMemory<unsigned short,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<unsigned short,CUtlMemory<unsigned short,int>>::InsertMultipleBefore(
        CUtlVector<CFaceMacroTextureInfo,CUtlMemory<CFaceMacroTextureInfo,int> > *this,
        int elem,
        int num)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CFaceMacroTextureInfo *m_pMemory; // ecx
  int v8; // eax
  int v9; // eax

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<CFaceMacroTextureInfo,int>::Grow(this: &this->m_Memory, num: num + m_Size - m_nAllocationCount);
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
// Address: 0x00406210
// Name: public: CUtlVector<struct dleafambientlighting_t,class CUtlMemory<struct dleafambientlighting_t,int>>::~CUtlVector<struct dleafambientlighting_t,class CUtlMemory<struct dleafambientlighting_t,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<dleafambientlighting_t,CUtlMemory<dleafambientlighting_t,int>>::~CUtlVector<dleafambientlighting_t,CUtlMemory<dleafambientlighting_t,int>>(
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
// Address: 0x00408A50
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
// Address: 0x00408E70
// Name: public: void CUtlVector<struct clusterlist_t,class CUtlMemory<struct clusterlist_t,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<clusterlist_t,CUtlMemory<clusterlist_t,int>>::RemoveAll(
        CUtlVector<clusterlist_t,CUtlMemory<clusterlist_t,int> > *this)
{
  int v1; // ebx
  int v2; // eax
  char *v3; // esi
  void *v4; // eax
  int v5; // [esp+4h] [ebp-8h]
  CUtlVector<clusterlist_t,CUtlMemory<clusterlist_t,int> > *v6; // [esp+8h] [ebp-4h]

  v1 = this->m_Size - 1;
  v6 = this;
  if ( v1 < 0 )
  {
    this->m_Size = 0;
  }
  else
  {
    v2 = 24 * v1;
    v5 = 24 * v1;
    do
    {
      v3 = (char *)this->m_Memory.m_pMemory + v2;
      *((_DWORD *)v3 + 4) = 0;
      if ( *((int *)v3 + 3) >= 0 )
      {
        if ( *((_DWORD *)v3 + 1) != 0 )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *((void **)v3 + 1));
          this = v6;
          *((_DWORD *)v3 + 1) = 0;
        }
        *((_DWORD *)v3 + 2) = 0;
      }
      v4 = *((void **)v3 + 1);
      *((_DWORD *)v3 + 5) = v4;
      if ( *((int *)v3 + 3) >= 0 )
      {
        if ( v4 != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v4);
          this = v6;
          *((_DWORD *)v3 + 1) = 0;
        }
        *((_DWORD *)v3 + 2) = 0;
      }
      --v1;
      v2 = v5 - 24;
      v5 -= 24;
    }
    while ( v1 >= 0 );
    this->m_Size = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040A320
// Name: public: CUtlVector<struct clusterlist_t,class CUtlMemory<struct clusterlist_t,int>>::~CUtlVector<struct clusterlist_t,class CUtlMemory<struct clusterlist_t,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<clusterlist_t,CUtlMemory<clusterlist_t,int>>::~CUtlVector<clusterlist_t,CUtlMemory<clusterlist_t,int>>(
        CUtlVector<clusterlist_t,CUtlMemory<clusterlist_t,int> > *this)
{
  bool v2; // sf
  clusterlist_t *m_pMemory; // eax

  CUtlVector<clusterlist_t,CUtlMemory<clusterlist_t,int>>::RemoveAll(this);
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
// Address: 0x0040A380
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
// Address: 0x0040DD20
// Name: void DefaultScriptLoadedCallback(char const __near *,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DefaultScriptLoadedCallback()
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x0040DD30
// Name: public: virtual bool CScriptLib::DoesFileExist(char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CScriptLib::DoesFileExist(CScriptLib *this, const char *pFilename)
{
  return g_pFullFileSystem->FileExists(this: &g_pFullFileSystem->IBaseFileSystem, a2: pFilename, a3: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x0040DD50
// Name: public: virtual bool CScriptLib::ReadFileToBuffer(char const __near *,class CUtlBuffer __near &,bool,bool)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CScriptLib::ReadFileToBuffer(
        CScriptLib *this,
        const char *pSourceName,
        CUtlBuffer *buffer,
        bool bText,
        bool bNoOpenFailureWarning)
{
  int *v5; // eax
  const char *v6; // eax

  if ( g_pFullFileSystem->ReadFile(
         this: &g_pFullFileSystem->IBaseFileSystem,
         a2: pSourceName,
         a3: nullptr,
         a4: buffer,
         a5: 0,
         a6: 0,
         a7: nullptr) )
  {
    if ( bText )
      CUtlBuffer::SetBufferType(this: buffer, bIsText: true, bContainsCRLF: true);
    else
      CUtlBuffer::SetBufferType(this: buffer, bIsText: false, bContainsCRLF: false);
    return 1;
  }
  else
  {
    if ( !bNoOpenFailureWarning )
    {
      v5 = _errno();
      v6 = strerror(errnum: *v5);
      _Msg(a1: "ReadFileToBuffer(): Error opening %s: %s\n", pSourceName, v6);
    }
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040DDD0
// Name: public: virtual bool CScriptLib::WriteBufferToFile(char const __near *,class CUtlBuffer __near &,enum DiskWriteMode_t)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CScriptLib::WriteBufferToFile(
        CScriptLib *this,
        const char *pTargetName,
        CUtlBuffer *buffer,
        DiskWriteMode_t writeMode)
{
  _BYTE *v5; // eax
  _BYTE *v6; // esi
  _BYTE *v7; // eax
  char dirPath[260]; // [esp+8h] [ebp-104h] BYREF

  strcpy(dirPath, pTargetName);
  strchr(string: (unsigned __int8 *)dirPath, chr: 0x5Cu);
  v6 = v5;
  if ( v5 != nullptr )
  {
    while ( 1 )
    {
      strchr(string: v6 + 1, chr: 0x5Cu);
      v6 = v7;
      if ( v7 == nullptr )
        break;
      *v7 = 0;
      _mkdir(path: dirPath);
      *v6 = 92;
    }
  }
  return writeMode != WRITE_TO_DISK_ALWAYS
      && (writeMode != WRITE_TO_DISK_UPDATE || !this->DoesFileExist(this, a2: pTargetName))
      || g_pFullFileSystem->WriteFile(
           this: &g_pFullFileSystem->IBaseFileSystem,
           a2: pTargetName,
           a3: nullptr,
           a4: buffer);
}

//------------------------------------------------------------------------------
// Address: 0x0040DE90
// Name: public: virtual int CScriptLib::CompareFileTime(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CScriptLib::CompareFileTime(CScriptLib *this, const char *pFilenameA, const char *pFilenameB)
{
  unsigned int v3; // esi
  unsigned int v4; // eax
  bool v5; // cf

  v3 = g_pFullFileSystem->GetFileTime(this: &g_pFullFileSystem->IBaseFileSystem, a2: pFilenameA, a3: nullptr);
  v4 = g_pFullFileSystem->GetFileTime(this: &g_pFullFileSystem->IBaseFileSystem, a2: pFilenameB, a3: nullptr);
  if ( v3 == -1 )
    v3 = 0;
  if ( v4 == -1 )
    return v3 != 0;
  v5 = v4 < v3;
  if ( v4 <= v3 )
    return v5;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0040DEF0
// Name: public: virtual char __near * CScriptLib::MakeTemporaryFilename(char const __near *,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CScriptLib::MakeTemporaryFilename(CScriptLib *this, const char *pchModPath, char *pPath, int pathSize)
{
  char *v4; // eax
  char *v5; // esi

  v4 = _tempnam(dir: pchModPath, pfx: "mgd_");
  v5 = v4;
  if ( *v4 == 92 )
    v5 = v4 + 1;
  if ( v5[strlen(v5) - 1] == 46 )
    v5[strlen(v5) - 1] = 0;
  V_snprintf(pDest: pPath, maxLen: pathSize, pFormat: "%s.tmp", v5);
  free(pMem: v5);
  return pPath;
}

//------------------------------------------------------------------------------
// Address: 0x0040E000
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
// Address: 0x0040E070
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
    CUtlMemory<fileList_t,int>::Grow(this: &this->m_Memory, num: m_Size - m_nAllocationCount + 1);
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
// Address: 0x0040E0E0
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
    CUtlMemory<fileList_t,int>::Grow(this: &this->m_Memory, num: num + m_Size - m_nAllocationCount);
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
// Address: 0x0040E180
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
// Address: 0x0040E1F0
// Name: private: int CScriptLib::GetFileList(char const __near *,char const __near *,class CUtlVector<struct fileList_t,class CUtlMemory<struct fileList_t,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CScriptLib::GetFileList(
        CScriptLib *this,
        const char *pDirPath,
        const char *pPattern,
        CUtlVector<fileList_t,CUtlMemory<fileList_t,int> > *fileList)
{
  unsigned int v5; // kr00_4
  int v6; // eax
  char v7; // cl
  char *v8; // edi
  char v9; // al
  unsigned int v10; // eax
  char *v11; // edi
  char v12; // cl
  int v13; // esi
  int v15; // eax
  char v16; // cl
  unsigned int v17; // eax
  char *v18; // edi
  char v19; // cl
  char *v20; // edi
  char *v21; // esi
  char v22; // cl
  int m_Size; // eax
  int v24; // esi
  char v25; // [esp+Bh] [ebp-435h] BYREF
  char fileName[260]; // [esp+Ch] [ebp-434h] BYREF
  char fullPath[260]; // [esp+110h] [ebp-330h] BYREF
  _finddata64i32_t findData; // [esp+214h] [ebp-22Ch] BYREF
  char sourcePath[260]; // [esp+33Ch] [ebp-104h] BYREF
  int h; // [esp+448h] [ebp+8h]
  char bFindDirs_3; // [esp+453h] [ebp+13h]

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
  v5 = strlen(sourcePath);
  if ( v5 != 0 )
  {
    if ( findData.name[v5 + 259] != 92 )
    {
      sourcePath[v5] = 92;
      sourcePath[v5 + 1] = 0;
    }
  }
  else
  {
    strcpy(sourcePath, ".\\");
  }
  v6 = 0;
  do
  {
    v7 = sourcePath[v6];
    fullPath[v6++] = v7;
  }
  while ( v7 != 0 );
  if ( *pPattern != 92 || pPattern[1] != 0 )
  {
    bFindDirs_3 = 0;
    v10 = strlen(pPattern) + 1;
    v11 = &fileName[259];
    do
      v12 = *++v11;
    while ( v12 != 0 );
    qmemcpy(v11, pPattern, v10);
  }
  else
  {
    bFindDirs_3 = 1;
    v8 = &fileName[259];
    do
      v9 = *++v8;
    while ( v9 != 0 );
    strcpy(v8, "*");
  }
  v13 = _findfirst64i32(szWild: fullPath, pfd: &findData);
  h = v13;
  if ( v13 == -1 )
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
      v15 = 0;
      do
      {
        v16 = sourcePath[v15];
        fileName[v15++] = v16;
      }
      while ( v16 != 0 );
      v17 = strlen(findData.name) + 1;
      v18 = &v25;
      do
        v19 = *++v18;
      while ( v19 != 0 );
      qmemcpy(v18, findData.name, 4 * (v17 >> 2));
      v21 = &findData.name[4 * (v17 >> 2)];
      v20 = &v18[4 * (v17 >> 2)];
      v22 = v17;
      m_Size = fileList->m_Size;
      qmemcpy(v20, v21, v22 & 3);
      v24 = CUtlVector<fileList_t,CUtlMemory<fileList_t,int>>::InsertBefore(this: fileList, elem: m_Size);
      CUtlString::Set(this: &fileList->m_Memory.m_pMemory[v24].fileName, pValue: fileName);
      fileList->m_Memory.m_pMemory[v24].timeWrite = findData.time_write;
      v13 = h;
    }
  }
  while ( _findnext64i32(hFile: v13, pfd: &findData) == 0 );
  _findclose(hFile: v13);
  return fileList->m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x0040E450
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
// Address: 0x0040E4B0
// Name: public: virtual void CScriptLib::DeleteTemporaryFiles(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CScriptLib::DeleteTemporaryFiles(CScriptLib *this, const char *pFileMask)
{
  char *v2; // eax
  char *v3; // edx
  char v4; // cl
  unsigned int v5; // eax
  char *v6; // edi
  char v7; // cl
  int (__thiscall *FindFiles)(struct CScriptLib *, char *, bool, CUtlVector<fileList_t,CUtlMemory<fileList_t,int> > *); // edx
  int v9; // esi
  int v10; // edi
  const char *v11; // eax
  fileList_t *m_pMemory; // eax
  char v13; // [esp+3h] [ebp-11Dh] BYREF
  char tempPath[260]; // [esp+4h] [ebp-11Ch] BYREF
  CScriptLib *v15; // [esp+108h] [ebp-18h]
  CUtlVector<fileList_t,CUtlMemory<fileList_t,int> > fileList; // [esp+10Ch] [ebp-14h] BYREF

  v15 = this;
  v2 = getenv(option: "temp");
  if ( v2 != nullptr || (v2 = getenv(option: "tmp")) != nullptr )
  {
    v3 = (char *)(tempPath - v2);
    do
    {
      v4 = *v2;
      v2[(_DWORD)v3] = *v2;
      ++v2;
    }
    while ( v4 != 0 );
    V_AppendSlash(pStr: tempPath, strSize: 260);
    v5 = strlen(pFileMask) + 1;
    v6 = &v13;
    do
      v7 = *++v6;
    while ( v7 != 0 );
    qmemcpy(v6, pFileMask, v5);
    FindFiles = v15->FindFiles;
    memset(&fileList, 0, sizeof(fileList));
    FindFiles(this: v15, a2: tempPath, a3: false, a4: &fileList);
    v9 = 0;
    if ( fileList.m_Size > 0 )
    {
      v10 = 0;
      do
      {
        v11 = CUtlString::Get(this: &fileList.m_Memory.m_pMemory[v10].fileName);
        _unlink(path: v11);
        ++v9;
        ++v10;
      }
      while ( v9 < fileList.m_Size );
    }
    CUtlVector<fileList_t,CUtlMemory<fileList_t,int>>::RemoveAll(this: &fileList);
    m_pMemory = fileList.m_Memory.m_pMemory;
    if ( fileList.m_Memory.m_nGrowSize >= 0 )
    {
      if ( fileList.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: fileList.m_Memory.m_pMemory);
        m_pMemory = nullptr;
        fileList.m_Memory.m_pMemory = nullptr;
      }
      fileList.m_Memory.m_nAllocationCount = 0;
    }
    fileList.m_pElements = m_pMemory;
    if ( fileList.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040E5E0
// Name: private: void CScriptLib::RecurseFileTree_r(char const __near *,int,class CUtlVector<class CUtlString,class CUtlMemory<class CUtlString,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CScriptLib::RecurseFileTree_r(
        CScriptLib *this,
        const char *pDirPath,
        int depth,
        CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *dirList)
{
  fileList_t *i; // ebx
  int v5; // eax
  int v6; // eax
  fileList_t *m_pMemory; // edi
  const char *v8; // eax
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CUtlString *v11; // ecx
  int v12; // eax
  int v13; // edi
  CUtlString *v14; // ecx
  CUtlVector<fileList_t,CUtlMemory<fileList_t,int> > fileList; // [esp+Ch] [ebp-18h] BYREF
  CScriptLib *v16; // [esp+20h] [ebp-4h]

  i = nullptr;
  v16 = this;
  memset(&fileList, 0, sizeof(fileList));
  v5 = CScriptLib::GetFileList(this, pDirPath, pPattern: "\\", &fileList);
  if ( v5 != 0 )
  {
    if ( v5 > 0 )
    {
      m_pMemory = fileList.m_Memory.m_pMemory;
      for ( i = (fileList_t *)v5; i != nullptr; i = (fileList_t *)((char *)i - 1) )
      {
        v8 = CUtlString::Get(this: &m_pMemory->fileName);
        CScriptLib::RecurseFileTree_r(this: v16, pDirPath: v8, depth: depth + 1, dirList);
        ++m_pMemory;
      }
    }
    m_Size = dirList->m_Size;
    m_nAllocationCount = dirList->m_Memory.m_nAllocationCount;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<CUtlString,int>::Grow(this: &dirList->m_Memory, num: m_Size - m_nAllocationCount + 1);
    ++dirList->m_Size;
    v11 = dirList->m_Memory.m_pMemory;
    v12 = dirList->m_Size - m_Size - 1;
    dirList->m_pElements = dirList->m_Memory.m_pMemory;
    if ( v12 > (int)i )
      _V_memmove(dest: &v11[m_Size + 1], src: &v11[m_Size], count: 16 * v12);
    v13 = m_Size;
    v14 = &dirList->m_Memory.m_pMemory[v13];
    if ( v14 != nullptr )
      CUtlString::CUtlString(this: v14);
    CUtlString::Set(this: &dirList->m_Memory.m_pMemory[v13], pValue: pDirPath);
    CUtlVector<fileList_t,CUtlMemory<fileList_t,int>>::RemoveAll(this: &fileList);
    if ( fileList.m_Memory.m_nGrowSize >= (int)i && fileList.m_Memory.m_pMemory != i )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: fileList.m_Memory.m_pMemory);
  }
  else
  {
    v6 = CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>::InsertBefore(this: dirList, elem: dirList->m_Size);
    CUtlString::Set(this: &dirList->m_Memory.m_pMemory[v6], pValue: pDirPath);
    CUtlVector<fileList_t,CUtlMemory<fileList_t,int>>::~CUtlVector<fileList_t,CUtlMemory<fileList_t,int>>(this: &fileList);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040E700
// Name: public: virtual int CScriptLib::FindFiles(char __near *,bool,class CUtlVector<struct fileList_t,class CUtlMemory<struct fileList_t,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CScriptLib::FindFiles(
        CScriptLib *this,
        char *pFileMask,
        bool bRecurse,
        CUtlVector<fileList_t,CUtlMemory<fileList_t,int> > *fileList)
{
  CScriptLib *v4; // edi
  char *v5; // edi
  char v6; // al
  unsigned int v7; // eax
  char *v8; // edi
  char v9; // cl
  int m_nGrowSize; // esi
  fileList_t *m_pMemory; // eax
  const char *v13; // eax
  CUtlVector<fileList_t,CUtlMemory<fileList_t,int> > *v14; // esi
  int m_Size; // edi
  int inserted; // eax
  fileList_t *v17; // edi
  int v18; // ebx
  CUtlString *p_fileName; // esi
  int timeWrite_high; // eax
  bool v21; // zf
  CUtlString *v22; // eax
  unsigned int v23; // [esp-8h] [ebp-34Ch]
  char extension[260]; // [esp+8h] [ebp-33Ch] BYREF
  char dirPath[260]; // [esp+10Ch] [ebp-238h] BYREF
  char pattern[260]; // [esp+210h] [ebp-134h] BYREF
  CScriptLib *v27; // [esp+314h] [ebp-30h]
  int i; // [esp+318h] [ebp-2Ch]
  CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > dirList; // [esp+31Ch] [ebp-28h] BYREF
  CUtlVector<fileList_t,CUtlMemory<fileList_t,int> > tempList; // [esp+330h] [ebp-14h] BYREF
  char *pFileMaska; // [esp+34Ch] [ebp+8h]
  int bRecursea; // [esp+350h] [ebp+Ch]

  v4 = this;
  v27 = this;
  strcpy(dirPath, pFileMask);
  V_StripFilename(path: dirPath);
  V_FileBase(in: pFileMask, out: pattern, maxlen: 260);
  V_ExtractFileExtension(path: pFileMask, dest: extension, destSize: 260);
  if ( extension[0] != 0 )
  {
    v5 = &dirPath[259];
    do
      v6 = *++v5;
    while ( v6 != 0 );
    strcpy(v5, ".");
    v7 = strlen(extension) + 1;
    v8 = &dirPath[259];
    do
      v9 = *++v8;
    while ( v9 != 0 );
    qmemcpy(v8, extension, v7);
    v4 = v27;
  }
  if ( bRecurse )
  {
    memset(&tempList, 0, sizeof(tempList));
    memset(&dirList, 0, sizeof(dirList));
    CScriptLib::RecurseFileTree_r(this: v4, pDirPath: dirPath, depth: 0, &dirList);
    i = 0;
    if ( dirList.m_Size > 0 )
    {
      bRecursea = 0;
      while ( 1 )
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
          v23 = 24 * dirList.m_Size;
          if ( m_pMemory != nullptr )
            m_pMemory = (fileList_t *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v23);
          else
            m_pMemory = (fileList_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v23);
          tempList.m_Memory.m_pMemory = m_pMemory;
        }
        tempList.m_pElements = m_pMemory;
        v13 = CUtlString::Get(this: &dirList.m_Memory.m_pMemory[bRecursea]);
        CScriptLib::GetFileList(this: v4, pDirPath: v13, pPattern: pattern, fileList: &tempList);
        v14 = fileList;
        m_Size = tempList.m_Size;
        inserted = CUtlVector<fileList_t,CUtlMemory<fileList_t,int>>::InsertMultipleBefore(
                     this: fileList,
                     elem: fileList->m_Size,
                     num: tempList.m_Size);
        if ( m_Size > 0 )
        {
          v17 = tempList.m_Memory.m_pMemory;
          v18 = inserted;
          pFileMaska = (char *)tempList.m_Size;
          while ( 1 )
          {
            p_fileName = &v14->m_Memory.m_pMemory[v18].fileName;
            CUtlString::operator=(this: p_fileName, src: &v17->fileName);
            p_fileName[1].m_Storage.m_Memory.m_pMemory = (unsigned __int8 *)v17->timeWrite;
            timeWrite_high = HIDWORD(v17->timeWrite);
            ++v17;
            ++v18;
            v21 = pFileMaska-- == (char *)1;
            p_fileName[1].m_Storage.m_Memory.m_nAllocationCount = timeWrite_high;
            if ( v21 )
              break;
            v14 = fileList;
          }
        }
        ++bRecursea;
        if ( ++i >= dirList.m_Size )
          break;
        v4 = v27;
      }
    }
    CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>::RemoveAll(this: &dirList);
    v22 = dirList.m_Memory.m_pMemory;
    if ( dirList.m_Memory.m_nGrowSize >= 0 )
    {
      if ( dirList.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: dirList.m_Memory.m_pMemory);
        v22 = nullptr;
        dirList.m_Memory.m_pMemory = nullptr;
      }
      dirList.m_Memory.m_nAllocationCount = 0;
    }
    dirList.m_pElements = v22;
    if ( dirList.m_Memory.m_nGrowSize >= 0 )
    {
      if ( v22 != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v22);
        dirList.m_Memory.m_pMemory = nullptr;
      }
      dirList.m_Memory.m_nAllocationCount = 0;
    }
    CUtlVector<fileList_t,CUtlMemory<fileList_t,int>>::RemoveAll(this: &tempList);
    if ( tempList.m_Memory.m_nGrowSize < 0 )
    {
      return fileList->m_Size;
    }
    else
    {
      if ( tempList.m_Memory.m_pMemory != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: tempList.m_Memory.m_pMemory);
      return fileList->m_Size;
    }
  }
  else
  {
    CScriptLib::GetFileList(this: v4, pDirPath: dirPath, pPattern: pattern, fileList);
    return fileList->m_Size;
  }
}

} // namespace bspzip

// ============================================================
// Overlay from hlfaceposer (Missing functions)
// ============================================================
namespace hlfaceposer {

//------------------------------------------------------------------------------
// Address: 0x0040D9D0
// Name: char __near * MemAlloc_StrDup(char const __near *)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl MemAlloc_StrDup(const char *pString)
{
  char *result; // eax

  if ( pString == nullptr )
    return nullptr;
  result = (char *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: strlen(pString) + 1);
  if ( result == nullptr )
    return nullptr;
  strcpy(result, pString);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0040DA20
// Name: void AddScriptToStack(char __near *,enum ScriptPathMode_t)
// Source: json
//------------------------------------------------------------------------------
void __cdecl AddScriptToStack(char *filename, ScriptPathMode_t pathMode)
{
  int File; // esi
  const char *v3; // [esp-8h] [ebp-8h]
  const char *savedregs; // [esp+0h] [ebp+0h]

  if ( ++script == (script_t *)token )
    _Error(this: (ISceneTokenProcessor *)&stru_4EF354, a2: savedregs);
  if ( pathMode == SCRIPT_USE_RELATIVE_PATH )
  {
    V_strncpy(pDest: script->filename, pSrc: filename, maxLen: 1024);
  }
  else
  {
    v3 = ExpandPath(path: filename);
    V_strncpy(pDest: script->filename, pSrc: v3, maxLen: 1024);
  }
  File = LoadFile(filename: script->filename, bufferptr: (void **)&script->buffer);
  if ( g_pfnCallback != nullptr )
  {
    if ( script == &scriptstack[1] )
      g_pfnCallback(a1: script->filename, a2: nullptr, a3: 0);
    else
      g_pfnCallback(a1: script->filename, a2: script[-1].filename, a3: script[-1].line);
  }
  script->line = 1;
  script->script_p = script->buffer;
  script->end_p = &script->buffer[File];
}

//------------------------------------------------------------------------------
// Address: 0x0040DB00
// Name: void LoadScriptFile(char __near *,enum ScriptPathMode_t)
// Source: json
//------------------------------------------------------------------------------
void __cdecl LoadScriptFile(char *filename, ScriptPathMode_t pathMode)
{
  script = scriptstack;
  AddScriptToStack(filename, pathMode);
  endofscript = 0;
  tokenready = 0;
}

//------------------------------------------------------------------------------
// Address: 0x0040DB30
// Name: bool AddMacroToStack(char __near *)
// Source: json
//------------------------------------------------------------------------------
char __usercall AddMacroToStack@<al>(const char *a1@<ebx>, char *macroname)
{
  int v3; // esi
  bool v4; // zf
  script_t *v5; // edi
  script_t *v6; // ebx
  int nummacroparams; // eax
  char *macrobuffer; // esi
  char **macroparam; // edi
  unsigned int v10; // esi
  const char *v11; // [esp-Ch] [ebp-14h]
  script_t *pmacro; // [esp+4h] [ebp-4h]
  int i; // [esp+10h] [ebp+8h]

  if ( *macroname != 36 )
    return 0;
  v3 = 0;
  v4 = nummacros == 0;
  if ( nummacros > 0 )
  {
    do
    {
      if ( _V_stricmp(s1: macrolist[v3]->filename, s2: macroname + 1) == 0 )
        break;
      ++v3;
    }
    while ( v3 < nummacros );
    v4 = v3 == nummacros;
  }
  if ( v4 )
    return 0;
  v5 = macrolist[v3];
  v11 = a1;
  v6 = script + 2;
  pmacro = v5;
  if ( &script[2] == (script_t *)token )
    _Error(this: (ISceneTokenProcessor *)&stru_4EF354, a2: v11);
  nummacroparams = v5->nummacroparams;
  macrobuffer = v6->macrobuffer;
  v6->nummacroparams = nummacroparams;
  i = 0;
  if ( nummacroparams > 0 )
  {
    macroparam = v6->macroparam;
    do
    {
      GetToken(crossline: 0);
      strcpy(macrobuffer, token);
      *macroparam = *(char **)((char *)macroparam + (char *)pmacro - (char *)v6);
      macroparam[64] = macrobuffer;
      macrobuffer += strlen(token) + 1;
      if ( macrobuffer >= (char *)v6->macroparam )
        _Error(this: (ISceneTokenProcessor *)&stru_4EF378, a2: v11);
      ++macroparam;
      ++i;
    }
    while ( i < v6->nummacroparams );
    v5 = pmacro;
  }
  script = (script_t *)strcpy(v6->filename, v5->filename);
  v10 = v5->end_p - v5->buffer;
  script->buffer = (char *)operator new(nSize: v10 + 1);
  memcpy(dst: (unsigned __int8 *)script->buffer, src: (unsigned __int8 *)v5->buffer, count: v10);
  v5->buffer[v10] = 0;
  script->script_p = script->buffer;
  script->end_p = &script->buffer[v10];
  script->line = v5->line;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0040DCF0
// Name: bool ExpandMacroToken(char __near * __near &)
// Source: json
//------------------------------------------------------------------------------
char __usercall ExpandMacroToken@<al>(const char *a1@<edi>, char **token_p)
{
  char *script_p; // eax
  _BYTE *v3; // ebx
  char v4; // al
  script_t *v6; // eax
  int v7; // esi
  int v8; // edi
  bool v9; // zf
  const char *v10; // edx
  unsigned int v11; // eax
  _BYTE *v12; // esi
  char v13; // cl
  char *s2; // [esp+0h] [ebp-4h]

  if ( script->nummacroparams == 0 )
    return 0;
  script_p = script->script_p;
  if ( *script_p != 36 )
    return 0;
  v3 = script_p + 1;
  s2 = script_p + 1;
  v4 = script_p[1];
  if ( v4 <= 32 )
  {
LABEL_6:
    if ( *v3 != 36 )
      return 0;
  }
  else
  {
    while ( v4 != 36 )
    {
      v4 = *++v3;
      if ( v4 <= 32 )
        goto LABEL_6;
    }
  }
  *v3 = 0;
  v6 = script;
  v7 = 0;
  if ( script->nummacroparams <= 0 )
    goto LABEL_13;
  v8 = 5136;
  do
  {
    v9 = _V_stricmp(s1: *(const char **)&v6->filename[v8], s2) == 0;
    v6 = script;
    if ( v9 )
      break;
    ++v7;
    v8 += 4;
  }
  while ( v7 < script->nummacroparams );
  if ( v7 >= script->nummacroparams )
  {
LABEL_13:
    _Error(this: (ISceneTokenProcessor *)&stru_4EF3C4, a2: s2, v6);
    v6 = script;
  }
  v10 = v6->macrovalue[v7];
  v11 = strlen(v10);
  v12 = *token_p;
  do
  {
    v13 = *v10;
    *v12++ = *v10++;
  }
  while ( v13 != 0 );
  *token_p += v11;
  script->script_p = v3 + 1;
  if ( script->script_p >= script->end_p )
    _Error(this: (ISceneTokenProcessor *)&stru_4EF3AC, a2: a1);
  if ( *token_p >= (char *)&nummacros )
    _Error(this: (ISceneTokenProcessor *)&stru_4EF390, a2: scriptline);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0040DE20
// Name: void ParseFromMemory(char __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ParseFromMemory(char *buffer, int size)
{
  scriptstack[1].buffer = buffer;
  scriptstack[1].script_p = buffer;
  script = &scriptstack[1];
  scriptstack[1].end_p = &buffer[size];
  strcpy(scriptstack[1].filename, "memory buffer");
  scriptstack[1].line = 1;
  endofscript = 0;
  tokenready = 0;
}

//------------------------------------------------------------------------------
// Address: 0x0040DF50
// Name: int TokenAvailable(void)
// Source: json
//------------------------------------------------------------------------------
int __cdecl TokenAvailable()
{
  char *script_p; // eax
  char *end_p; // edx
  char v3; // cl
  char v4; // cl

  if ( tokenready != 0 )
    return 1;
  script_p = script->script_p;
  end_p = script->end_p;
  if ( script_p < end_p )
  {
    v3 = *script_p;
    if ( *script_p > 32 )
    {
LABEL_8:
      v4 = *script_p;
      if ( *script_p != 59 && v4 != 35 && (v4 != 47 || script_p[1] != 47) )
        return 1;
    }
    else
    {
      while ( v3 != 10 )
      {
        if ( ++script_p == end_p )
          break;
        v3 = *script_p;
        if ( *script_p > 32 )
          goto LABEL_8;
      }
    }
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x0040DFB0
// Name: public: virtual bool CScriptLib::DoesFileExist(char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CScriptLib::DoesFileExist(CScriptLib *this, const char *pFilename)
{
  return g_pFullFileSystem->FileExists(this: &g_pFullFileSystem->IBaseFileSystem, a2: pFilename, a3: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x0040DFD0
// Name: public: virtual bool CScriptLib::ReadFileToBuffer(char const __near *,class CUtlBuffer __near &,bool,bool)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CScriptLib::ReadFileToBuffer(
        CScriptLib *this,
        const char *pSourceName,
        CUtlBuffer *buffer,
        bool bText,
        bool bNoOpenFailureWarning)
{
  int *v5; // eax
  const char *v6; // eax

  if ( g_pFullFileSystem->ReadFile(
         this: &g_pFullFileSystem->IBaseFileSystem,
         a2: pSourceName,
         a3: nullptr,
         a4: buffer,
         a5: 0,
         a6: 0,
         a7: nullptr) )
  {
    if ( bText )
      CUtlBuffer::SetBufferType(this: buffer, bIsText: true, bContainsCRLF: true);
    else
      CUtlBuffer::SetBufferType(this: buffer, bIsText: false, bContainsCRLF: false);
    return 1;
  }
  else
  {
    if ( !bNoOpenFailureWarning )
    {
      v5 = _errno();
      v6 = strerror(errnum: *v5);
      _Msg(a1: "ReadFileToBuffer(): Error opening %s: %s\n", pSourceName, v6);
    }
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040E050
// Name: public: virtual bool CScriptLib::WriteBufferToFile(char const __near *,class CUtlBuffer __near &,enum DiskWriteMode_t)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CScriptLib::WriteBufferToFile(
        CScriptLib *this,
        const char *pTargetName,
        CUtlBuffer *buffer,
        DiskWriteMode_t writeMode)
{
  _BYTE *v5; // eax
  _BYTE *v6; // esi
  _BYTE *v7; // eax
  char dirPath[260]; // [esp+8h] [ebp-104h] BYREF

  strcpy(dirPath, pTargetName);
  strchr(string: (unsigned __int8 *)dirPath, chr: 0x5Cu);
  v6 = v5;
  if ( v5 != nullptr )
  {
    while ( 1 )
    {
      strchr(string: v6 + 1, chr: 0x5Cu);
      v6 = v7;
      if ( v7 == nullptr )
        break;
      *v7 = 0;
      _mkdir(path: dirPath);
      *v6 = 92;
    }
  }
  return writeMode != WRITE_TO_DISK_ALWAYS
      && (writeMode != WRITE_TO_DISK_UPDATE || !this->DoesFileExist(this, a2: pTargetName))
      || g_pFullFileSystem->WriteFile(
           this: &g_pFullFileSystem->IBaseFileSystem,
           a2: pTargetName,
           a3: nullptr,
           a4: buffer);
}

//------------------------------------------------------------------------------
// Address: 0x0040E110
// Name: public: virtual int CScriptLib::CompareFileTime(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CScriptLib::CompareFileTime(CScriptLib *this, const char *pFilenameA, const char *pFilenameB)
{
  unsigned int v3; // esi
  unsigned int v4; // eax
  bool v5; // cf

  v3 = g_pFullFileSystem->GetFileTime(this: &g_pFullFileSystem->IBaseFileSystem, a2: pFilenameA, a3: nullptr);
  v4 = g_pFullFileSystem->GetFileTime(this: &g_pFullFileSystem->IBaseFileSystem, a2: pFilenameB, a3: nullptr);
  if ( v3 == -1 )
    v3 = 0;
  if ( v4 == -1 )
    return v3 != 0;
  v5 = v4 < v3;
  if ( v4 <= v3 )
    return v5;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0040E170
// Name: public: virtual char __near * CScriptLib::MakeTemporaryFilename(char const __near *,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CScriptLib::MakeTemporaryFilename(CScriptLib *this, const char *pchModPath, char *pPath, int pathSize)
{
  char *v4; // eax
  char *v5; // esi

  v4 = _tempnam(dir: pchModPath, pfx: "mgd_");
  v5 = v4;
  if ( *v4 == 92 )
    v5 = v4 + 1;
  if ( v5[strlen(v5) - 1] == 46 )
    v5[strlen(v5) - 1] = 0;
  V_snprintf(pDest: pPath, maxLen: pathSize, pFormat: "%s.tmp", v5);
  free(pMem: v5);
  return pPath;
}

//------------------------------------------------------------------------------
// Address: 0x0040E1E0
// Name: void DefineMacro(char __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DefineMacro(char *macroname)
{
  script_t *v1; // edi
  char *script_p; // esi
  char *macrobuffer; // ebx
  unsigned int v4; // ebx
  unsigned __int8 *v5; // eax
  int v6; // eax
  script_t *v7; // edx
  const char *v8; // [esp+0h] [ebp-Ch]

  v1 = (script_t *)operator new(nSize: 0x1614u);
  strcpy(v1->filename, macroname);
  v1->line = script->line;
  v1->nummacroparams = 0;
  script_p = script->script_p;
  macrobuffer = v1->macrobuffer;
  while ( TokenAvailable() != 0 )
  {
    GetToken(crossline: 0);
    if ( token[0] == 92 && byte_5432A9 == 92 )
      break;
    script_p = script->script_p;
    v1->macroparam[v1->nummacroparams++] = macrobuffer;
    strcpy(macrobuffer, token);
    macrobuffer += strlen(token) + 1;
    if ( macrobuffer >= (char *)v1->macroparam )
      _Error(this: (ISceneTokenProcessor *)&stru_4EF378, a2: v8);
  }
  for ( script->script_p = script_p; *script_p != 0; ++script_p )
  {
    if ( *script_p == 10 )
      break;
    if ( *script_p == 92 && script_p[1] == 92 )
    {
      do
      {
        if ( *script_p == 10 )
          break;
        *script_p++ = 32;
      }
      while ( *script_p != 0 );
      if ( *script_p == 0 )
        break;
    }
  }
  v4 = script_p - script->script_p;
  v5 = (unsigned __int8 *)operator new(nSize: v4 + 1);
  v1->buffer = (char *)v5;
  memcpy(dst: v5, src: (unsigned __int8 *)script->script_p, count: v4);
  v1->buffer[v4] = 0;
  v1->end_p = &v1->buffer[v4];
  v6 = nummacros;
  v7 = script;
  macrolist[nummacros] = v1;
  nummacros = v6 + 1;
  v7->script_p = script_p;
}

//------------------------------------------------------------------------------
// Address: 0x0040E410
// Name: bool ExpandVariableToken(char __near * __near &)
// Source: json
//------------------------------------------------------------------------------
char __usercall ExpandVariableToken@<al>(const char *a1@<edi>, char **token_p)
{
  char *script_p; // eax
  const char *v3; // edi
  _BYTE *v4; // ebx
  char v5; // al
  int v7; // esi
  char *value; // esi
  unsigned int v9; // eax
  char *v10; // edx
  _BYTE *v11; // esi
  char v12; // cl

  script_p = script->script_p;
  if ( *script_p != 36 )
    return 0;
  v3 = script_p + 1;
  v4 = script_p + 1;
  v5 = script_p[1];
  if ( v5 <= 32 )
  {
LABEL_5:
    if ( *v4 != 36 )
      return 0;
  }
  else
  {
    while ( v5 != 36 )
    {
      v5 = *++v4;
      if ( v5 <= 32 )
        goto LABEL_5;
    }
  }
  v7 = 0;
  *v4 = 0;
  if ( g_definevariable.m_Size <= 0 )
    goto LABEL_12;
  while ( V_strnicmp(s1: g_definevariable.m_Memory.m_pMemory[v7].param, s2: v3, n: v4 - v3 - 2) != 0 )
  {
    if ( ++v7 >= g_definevariable.m_Size )
      goto LABEL_12;
  }
  if ( v7 >= g_definevariable.m_Size )
LABEL_12:
    _Error(this: (ISceneTokenProcessor *)&stru_4EF468, a2: v3, script);
  value = g_definevariable.m_Memory.m_pMemory[v7].value;
  v9 = strlen(value);
  v10 = value;
  v11 = *token_p;
  do
  {
    v12 = *v10;
    *v11++ = *v10++;
  }
  while ( v12 != 0 );
  *token_p += v9;
  script->script_p = v4 + 1;
  if ( script->script_p >= script->end_p )
    _Error(this: (ISceneTokenProcessor *)&stru_4EF3AC, a2: a1);
  if ( *token_p >= (char *)&nummacros )
    _Error(this: (ISceneTokenProcessor *)&stru_4EF390, a2: scriptline);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0040E620
// Name: void DefineVariable(char __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DefineVariable(char *variablename)
{
  char *v1; // eax
  char *v2; // eax
  char *v3; // ecx
  char v4; // dl
  variable_t v; // [esp+8h] [ebp-8h] BYREF

  if ( variablename != nullptr
    && (v1 = (char *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: strlen(variablename) + 1)) != nullptr )
  {
    strcpy(v1, variablename);
  }
  else
  {
    v1 = nullptr;
  }
  v.param = v1;
  GetToken(crossline: 0);
  v2 = (char *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: strlen(token) + 1);
  if ( v2 != nullptr )
  {
    v3 = v2;
    do
    {
      v4 = v3[token - v2];
      *v3++ = v4;
    }
    while ( v4 != 0 );
  }
  else
  {
    v2 = nullptr;
  }
  v.value = v2;
  CUtlVector<tagPOINT,CUtlMemory<tagPOINT,int>>::InsertBefore(
    this: &g_definevariable,
    elem: g_definevariable.m_Size,
    src: &v);
}

//------------------------------------------------------------------------------
// Address: 0x0040E6E0
// Name: int GetToken(int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl GetToken(int crossline)
{
  script_t *v1; // eax
  char *script_p; // ecx
  char v3; // dl
  script_t *v4; // eax
  char *v5; // ecx
  char *v6; // edx
  char v7; // cl
  char *v8; // ecx
  char v9; // dl
  script_t *v10; // eax
  char *v11; // edx
  script_t *v12; // eax
  char *line; // edx
  char v14; // cl
  char *v15; // esi
  script_t *v16; // eax
  char i; // cl
  char *v18; // esi
  char *v19; // ecx
  char *token_p; // [esp+Ch] [ebp-4h] BYREF

  if ( tokenready != 0 )
  {
LABEL_54:
    tokenready = 0;
    return 1;
  }
  else
  {
    while ( 1 )
    {
      v1 = script;
      if ( script->script_p >= script->end_p )
        return EndOfScript(crossline);
      tokenready = 0;
      while ( 1 )
      {
        while ( 1 )
        {
          if ( *v1->script_p <= 32 )
          {
            do
            {
              script_p = v1->script_p;
              if ( script_p >= v1->end_p )
                return EndOfScript(crossline);
              v3 = *script_p;
              v1->script_p = script_p + 1;
              if ( v3 == 10 )
              {
                if ( crossline == 0 )
                  _Error(this: (ISceneTokenProcessor *)&stru_4EF3F4, a2: scriptline);
                v4 = script;
                ++script->line;
                scriptline = (char *)v4->line;
              }
              v1 = script;
            }
            while ( *script->script_p <= 32 );
          }
          v5 = v1->script_p;
          if ( v5 >= v1->end_p )
            return EndOfScript(crossline);
          v6 = v1->script_p;
          v7 = *v5;
          if ( v7 != 59 && v7 != 35 )
          {
            if ( v7 != 47 )
              goto LABEL_30;
            if ( v6[1] != 47 )
              break;
          }
          if ( crossline == 0 )
          {
            _Error(this: (ISceneTokenProcessor *)&stru_4EF3F4, a2: scriptline);
            v1 = script;
          }
          if ( *v1->script_p != 10 )
          {
            do
            {
              ++v1->script_p;
              v1 = script;
              v11 = script->script_p;
              if ( v11 >= script->end_p )
                return EndOfScript(crossline);
            }
            while ( *v11 != 10 );
          }
          ++v1->script_p;
          v12 = script;
          ++script->line;
          line = (char *)v12->line;
          v1 = script;
          scriptline = line;
        }
        if ( v6[1] != 42 )
          break;
        v1->script_p += 2;
        while ( 1 )
        {
          v8 = script->script_p;
          if ( *v8 == 42 && v8[1] == 47 )
            break;
          v9 = *v8;
          script->script_p = v8 + 1;
          if ( v9 != 10 )
          {
            v10 = script;
            if ( script->script_p >= script->end_p )
              return EndOfScript(crossline);
            ++script->line;
            scriptline = (char *)v10->line;
          }
        }
        script->script_p += 2;
        v1 = script;
      }
LABEL_30:
      v14 = *v6;
      v15 = token;
      token_p = token;
      if ( v14 == 34 )
      {
        ++v1->script_p;
        v16 = script;
        for ( i = *script->script_p; i != 34; i = *v16->script_p )
        {
          *v15 = i;
          ++script->script_p;
          v16 = script;
          ++v15;
          if ( script->script_p == script->end_p )
            break;
          if ( v15 == (char *)&nummacros )
          {
            _Error(this: (ISceneTokenProcessor *)&stru_4EF390, a2: scriptline);
            v16 = script;
          }
        }
        ++v16->script_p;
      }
      else
      {
        for ( ; v14 > 32; v14 = *script->script_p )
        {
          if ( v14 == 59 )
            break;
          if ( ExpandMacroToken(a1: (const char *)1, &token_p) != 0
            || ExpandVariableToken(a1: (const char *)1, &token_p) != 0 )
          {
            v15 = token_p;
          }
          else
          {
            v18 = token_p;
            *token_p = *script->script_p++;
            v19 = script->script_p;
            v15 = v18 + 1;
            token_p = v15;
            if ( v19 == script->end_p )
              break;
            if ( v15 == (char *)&nummacros )
              _Error(this: (ISceneTokenProcessor *)&stru_4EF390, a2: scriptline);
          }
        }
      }
      *v15 = 0;
      if ( _V_stricmp(s1: token, s2: "$include") != 0 )
      {
        if ( _V_stricmp(s1: token, s2: "$definemacro") != 0 )
        {
          if ( _V_stricmp(s1: token, s2: "$definevariable") != 0 )
          {
            if ( AddMacroToStack(a1: (const char *)_Error, macroname: token) == 0 )
              return 1;
          }
          else
          {
            GetToken(crossline: 0);
            DefineVariable(variablename: token);
          }
        }
        else
        {
          GetToken(crossline: 0);
          DefineMacro(macroname: token);
        }
      }
      else
      {
        GetToken(crossline: 0);
        AddScriptToStack(filename: token, pathMode: SCRIPT_USE_ABSOLUTE_PATH);
      }
      if ( tokenready != 0 )
        goto LABEL_54;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040ED30
// Name: private: int CScriptLib::GetFileList(char const __near *,char const __near *,class CUtlVector<struct fileList_t,class CUtlMemory<struct fileList_t,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CScriptLib::GetFileList(
        CScriptLib *this,
        const char *pDirPath,
        const char *pPattern,
        CUtlVector<CEventRelativeTag,CUtlMemory<CEventRelativeTag,int> > *fileList)
{
  unsigned int v5; // kr00_4
  int v6; // eax
  char v7; // cl
  char *v8; // edi
  char v9; // al
  unsigned int v10; // eax
  char *v11; // edi
  char v12; // cl
  int v13; // esi
  int v15; // eax
  char v16; // cl
  unsigned int v17; // eax
  char *v18; // edi
  char v19; // cl
  char *v20; // edi
  char *v21; // esi
  char v22; // cl
  int m_Size; // eax
  int v24; // esi
  char v25; // [esp+Bh] [ebp-435h] BYREF
  char fileName[260]; // [esp+Ch] [ebp-434h] BYREF
  char fullPath[260]; // [esp+110h] [ebp-330h] BYREF
  _finddata64i32_t findData; // [esp+214h] [ebp-22Ch] BYREF
  char sourcePath[260]; // [esp+33Ch] [ebp-104h] BYREF
  int h; // [esp+448h] [ebp+8h]
  char bFindDirs_3; // [esp+453h] [ebp+13h]

  CUtlVector<CEventRelativeTag,CUtlMemory<CEventRelativeTag,int>>::RemoveAll(this: fileList);
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
  v5 = strlen(sourcePath);
  if ( v5 != 0 )
  {
    if ( findData.name[v5 + 259] != 92 )
    {
      sourcePath[v5] = 92;
      sourcePath[v5 + 1] = 0;
    }
  }
  else
  {
    strcpy(sourcePath, ".\\");
  }
  v6 = 0;
  do
  {
    v7 = sourcePath[v6];
    fullPath[v6++] = v7;
  }
  while ( v7 != 0 );
  if ( *pPattern != 92 || pPattern[1] != 0 )
  {
    bFindDirs_3 = 0;
    v10 = strlen(pPattern) + 1;
    v11 = &fileName[259];
    do
      v12 = *++v11;
    while ( v12 != 0 );
    qmemcpy(v11, pPattern, v10);
  }
  else
  {
    bFindDirs_3 = 1;
    v8 = &fileName[259];
    do
      v9 = *++v8;
    while ( v9 != 0 );
    strcpy(v8, "*");
  }
  v13 = _findfirst64i32(szWild: fullPath, pfd: &findData);
  h = v13;
  if ( v13 == -1 )
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
      v15 = 0;
      do
      {
        v16 = sourcePath[v15];
        fileName[v15++] = v16;
      }
      while ( v16 != 0 );
      v17 = strlen(findData.name) + 1;
      v18 = &v25;
      do
        v19 = *++v18;
      while ( v19 != 0 );
      qmemcpy(v18, findData.name, 4 * (v17 >> 2));
      v21 = &findData.name[4 * (v17 >> 2)];
      v20 = &v18[4 * (v17 >> 2)];
      v22 = v17;
      m_Size = fileList->m_Size;
      qmemcpy(v20, v21, v22 & 3);
      v24 = CUtlVector<fileList_t,CUtlMemory<fileList_t,int>>::InsertBefore(
              this: (CUtlVector<fileList_t,CUtlMemory<fileList_t,int> > *)fileList,
              elem: m_Size);
      CUtlString::Set(this: &fileList->m_Memory.m_pMemory[v24].m_Name, pValue: fileName);
      *(_QWORD *)&fileList->m_Memory.m_pMemory[v24].m_flPercentage = findData.time_write;
      v13 = h;
    }
  }
  while ( _findnext64i32(hFile: v13, pfd: &findData) == 0 );
  _findclose(hFile: v13);
  return fileList->m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x0040EFF0
// Name: public: virtual void CScriptLib::DeleteTemporaryFiles(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CScriptLib::DeleteTemporaryFiles(CScriptLib *this, const char *pFileMask)
{
  char *v2; // eax
  char *v3; // edx
  char v4; // cl
  unsigned int v5; // eax
  char *v6; // edi
  char v7; // cl
  int (__thiscall *FindFiles)(struct CScriptLib *, char *, bool, CUtlVector<fileList_t,CUtlMemory<fileList_t,int> > *); // edx
  int v9; // esi
  int v10; // edi
  const char *v11; // eax
  fileList_t *m_pMemory; // eax
  char v13; // [esp+3h] [ebp-11Dh] BYREF
  char tempPath[260]; // [esp+4h] [ebp-11Ch] BYREF
  CScriptLib *v15; // [esp+108h] [ebp-18h]
  CUtlVector<fileList_t,CUtlMemory<fileList_t,int> > fileList; // [esp+10Ch] [ebp-14h] BYREF

  v15 = this;
  v2 = getenv(option: "temp");
  if ( v2 != nullptr || (v2 = getenv(option: "tmp")) != nullptr )
  {
    v3 = (char *)(tempPath - v2);
    do
    {
      v4 = *v2;
      v2[(_DWORD)v3] = *v2;
      ++v2;
    }
    while ( v4 != 0 );
    V_AppendSlash(pStr: tempPath, strSize: 260);
    v5 = strlen(pFileMask) + 1;
    v6 = &v13;
    do
      v7 = *++v6;
    while ( v7 != 0 );
    qmemcpy(v6, pFileMask, v5);
    FindFiles = v15->FindFiles;
    memset(&fileList, 0, sizeof(fileList));
    FindFiles(this: v15, a2: tempPath, a3: false, a4: &fileList);
    v9 = 0;
    if ( fileList.m_Size > 0 )
    {
      v10 = 0;
      do
      {
        v11 = CUtlString::operator char const *(this: &fileList.m_Memory.m_pMemory[v10].fileName);
        _unlink(path: v11);
        ++v9;
        ++v10;
      }
      while ( v9 < fileList.m_Size );
    }
    CUtlVector<CEventRelativeTag,CUtlMemory<CEventRelativeTag,int>>::RemoveAll(this: (CUtlVector<CEventRelativeTag,CUtlMemory<CEventRelativeTag,int> > *)&fileList);
    m_pMemory = fileList.m_Memory.m_pMemory;
    if ( fileList.m_Memory.m_nGrowSize >= 0 )
    {
      if ( fileList.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: fileList.m_Memory.m_pMemory);
        m_pMemory = nullptr;
        fileList.m_Memory.m_pMemory = nullptr;
      }
      fileList.m_Memory.m_nAllocationCount = 0;
    }
    fileList.m_pElements = m_pMemory;
    if ( fileList.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040F120
// Name: private: void CScriptLib::RecurseFileTree_r(char const __near *,int,class CUtlVector<class CUtlString,class CUtlMemory<class CUtlString,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CScriptLib::RecurseFileTree_r(
        CScriptLib *this,
        const char *pDirPath,
        int depth,
        CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *dirList)
{
  fileList_t *i; // ebx
  int v5; // eax
  int v6; // eax
  fileList_t *m_pMemory; // edi
  const char *v8; // eax
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CUtlString *v11; // ecx
  int v12; // eax
  int v13; // edi
  CUtlString *v14; // ecx
  CUtlVector<fileList_t,CUtlMemory<fileList_t,int> > fileList; // [esp+Ch] [ebp-18h] BYREF
  CScriptLib *v16; // [esp+20h] [ebp-4h]

  i = nullptr;
  v16 = this;
  memset(&fileList, 0, sizeof(fileList));
  v5 = CScriptLib::GetFileList(
         this,
         pDirPath,
         pPattern: "\\",
         (CUtlVector<CEventRelativeTag,CUtlMemory<CEventRelativeTag,int> > *)&fileList);
  if ( v5 != 0 )
  {
    if ( v5 > 0 )
    {
      m_pMemory = fileList.m_Memory.m_pMemory;
      for ( i = (fileList_t *)v5; i != nullptr; i = (fileList_t *)((char *)i - 1) )
      {
        v8 = CUtlString::operator char const *(this: &m_pMemory->fileName);
        CScriptLib::RecurseFileTree_r(this: v16, pDirPath: v8, depth: depth + 1, dirList);
        ++m_pMemory;
      }
    }
    m_Size = dirList->m_Size;
    m_nAllocationCount = dirList->m_Memory.m_nAllocationCount;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<SceneImageEntry_t,int>::Grow(
        this: (CUtlMemory<SceneImageEntry_t,int> *)dirList,
        num: m_Size - m_nAllocationCount + 1);
    ++dirList->m_Size;
    v11 = dirList->m_Memory.m_pMemory;
    v12 = dirList->m_Size - m_Size - 1;
    dirList->m_pElements = dirList->m_Memory.m_pMemory;
    if ( v12 > (int)i )
      _V_memmove(dest: &v11[m_Size + 1], src: &v11[m_Size], count: 16 * v12);
    v13 = m_Size;
    v14 = &dirList->m_Memory.m_pMemory[v13];
    if ( v14 != nullptr )
      CUtlString::CUtlString(this: v14);
    CUtlString::Set(this: &dirList->m_Memory.m_pMemory[v13], pValue: pDirPath);
    CUtlVector<CEventRelativeTag,CUtlMemory<CEventRelativeTag,int>>::RemoveAll(this: (CUtlVector<CEventRelativeTag,CUtlMemory<CEventRelativeTag,int> > *)&fileList);
    if ( fileList.m_Memory.m_nGrowSize >= (int)i && fileList.m_Memory.m_pMemory != i )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: fileList.m_Memory.m_pMemory);
  }
  else
  {
    v6 = CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>::InsertBefore(this: dirList, elem: dirList->m_Size);
    CUtlString::Set(this: &dirList->m_Memory.m_pMemory[v6], pValue: pDirPath);
    CUtlVector<CEventRelativeTag,CUtlMemory<CEventRelativeTag,int>>::~CUtlVector<CEventRelativeTag,CUtlMemory<CEventRelativeTag,int>>(this: (CUtlVector<CEventRelativeTag,CUtlMemory<CEventRelativeTag,int> > *)&fileList);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040F240
// Name: public: virtual int CScriptLib::FindFiles(char __near *,bool,class CUtlVector<struct fileList_t,class CUtlMemory<struct fileList_t,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CScriptLib::FindFiles(
        CScriptLib *this,
        char *pFileMask,
        bool bRecurse,
        CUtlVector<fileList_t,CUtlMemory<fileList_t,int> > *fileList)
{
  CScriptLib *v4; // edi
  char *v5; // edi
  char v6; // al
  unsigned int v7; // eax
  char *v8; // edi
  char v9; // cl
  int m_nGrowSize; // esi
  fileList_t *m_pMemory; // eax
  const char *v13; // eax
  CUtlVector<fileList_t,CUtlMemory<fileList_t,int> > *v14; // esi
  int m_Size; // edi
  int inserted; // eax
  fileList_t *v17; // edi
  int v18; // ebx
  CUtlString *p_fileName; // esi
  int timeWrite_high; // eax
  bool v21; // zf
  CUtlString *v22; // eax
  unsigned int v23; // [esp-8h] [ebp-34Ch]
  char extension[260]; // [esp+8h] [ebp-33Ch] BYREF
  char dirPath[260]; // [esp+10Ch] [ebp-238h] BYREF
  char pattern[260]; // [esp+210h] [ebp-134h] BYREF
  CScriptLib *v27; // [esp+314h] [ebp-30h]
  int i; // [esp+318h] [ebp-2Ch]
  CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > dirList; // [esp+31Ch] [ebp-28h] BYREF
  CUtlVector<fileList_t,CUtlMemory<fileList_t,int> > tempList; // [esp+330h] [ebp-14h] BYREF
  char *pFileMaska; // [esp+34Ch] [ebp+8h]
  int bRecursea; // [esp+350h] [ebp+Ch]

  v4 = this;
  v27 = this;
  strcpy(dirPath, pFileMask);
  V_StripFilename(path: dirPath);
  V_FileBase(in: pFileMask, out: pattern, maxlen: 260);
  V_ExtractFileExtension(path: pFileMask, dest: extension, destSize: 260);
  if ( extension[0] != 0 )
  {
    v5 = &dirPath[259];
    do
      v6 = *++v5;
    while ( v6 != 0 );
    strcpy(v5, ".");
    v7 = strlen(extension) + 1;
    v8 = &dirPath[259];
    do
      v9 = *++v8;
    while ( v9 != 0 );
    qmemcpy(v8, extension, v7);
    v4 = v27;
  }
  if ( bRecurse )
  {
    memset(&tempList, 0, sizeof(tempList));
    memset(&dirList, 0, sizeof(dirList));
    CScriptLib::RecurseFileTree_r(this: v4, pDirPath: dirPath, depth: 0, &dirList);
    i = 0;
    if ( dirList.m_Size > 0 )
    {
      bRecursea = 0;
      while ( 1 )
      {
        CUtlVector<CEventRelativeTag,CUtlMemory<CEventRelativeTag,int>>::RemoveAll(this: (CUtlVector<CEventRelativeTag,CUtlMemory<CEventRelativeTag,int> > *)&tempList);
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
          v23 = 24 * dirList.m_Size;
          if ( m_pMemory != nullptr )
            m_pMemory = (fileList_t *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v23);
          else
            m_pMemory = (fileList_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v23);
          tempList.m_Memory.m_pMemory = m_pMemory;
        }
        tempList.m_pElements = m_pMemory;
        v13 = CUtlString::operator char const *(this: &dirList.m_Memory.m_pMemory[bRecursea]);
        CScriptLib::GetFileList(
          this: v4,
          pDirPath: v13,
          pPattern: pattern,
          fileList: (CUtlVector<CEventRelativeTag,CUtlMemory<CEventRelativeTag,int> > *)&tempList);
        v14 = fileList;
        m_Size = tempList.m_Size;
        inserted = CUtlVector<fileList_t,CUtlMemory<fileList_t,int>>::InsertMultipleBefore(
                     this: fileList,
                     elem: fileList->m_Size,
                     num: tempList.m_Size);
        if ( m_Size > 0 )
        {
          v17 = tempList.m_Memory.m_pMemory;
          v18 = inserted;
          pFileMaska = (char *)tempList.m_Size;
          while ( 1 )
          {
            p_fileName = &v14->m_Memory.m_pMemory[v18].fileName;
            CUtlString::operator=(this: p_fileName, src: &v17->fileName);
            p_fileName[1].m_Storage.m_Memory.m_pMemory = (unsigned __int8 *)v17->timeWrite;
            timeWrite_high = HIDWORD(v17->timeWrite);
            ++v17;
            ++v18;
            v21 = pFileMaska-- == (char *)1;
            p_fileName[1].m_Storage.m_Memory.m_nAllocationCount = timeWrite_high;
            if ( v21 )
              break;
            v14 = fileList;
          }
        }
        ++bRecursea;
        if ( ++i >= dirList.m_Size )
          break;
        v4 = v27;
      }
    }
    CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>::RemoveAll(this: &dirList);
    v22 = dirList.m_Memory.m_pMemory;
    if ( dirList.m_Memory.m_nGrowSize >= 0 )
    {
      if ( dirList.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: dirList.m_Memory.m_pMemory);
        v22 = nullptr;
        dirList.m_Memory.m_pMemory = nullptr;
      }
      dirList.m_Memory.m_nAllocationCount = 0;
    }
    dirList.m_pElements = v22;
    if ( dirList.m_Memory.m_nGrowSize >= 0 )
    {
      if ( v22 != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v22);
        dirList.m_Memory.m_pMemory = nullptr;
      }
      dirList.m_Memory.m_nAllocationCount = 0;
    }
    CUtlVector<CEventRelativeTag,CUtlMemory<CEventRelativeTag,int>>::RemoveAll(this: (CUtlVector<CEventRelativeTag,CUtlMemory<CEventRelativeTag,int> > *)&tempList);
    if ( tempList.m_Memory.m_nGrowSize < 0 )
    {
      return fileList->m_Size;
    }
    else
    {
      if ( tempList.m_Memory.m_pMemory != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: tempList.m_Memory.m_pMemory);
      return fileList->m_Size;
    }
  }
  else
  {
    CScriptLib::GetFileList(
      this: v4,
      pDirPath: dirPath,
      pPattern: pattern,
      (CUtlVector<CEventRelativeTag,CUtlMemory<CEventRelativeTag,int> > *)fileList);
    return fileList->m_Size;
  }
}

} // namespace hlfaceposer

// ============================================================
// Overlay from hammer_dll (Missing functions)
// ============================================================
namespace hammer_dll {

//------------------------------------------------------------------------------
// Address: 0x100A0B60
// Name: char __near * MemAlloc_StrDup(char const __near *)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl MemAlloc_StrDup(const char *pString)
{
  char *result; // eax

  if ( pString == nullptr )
    return nullptr;
  result = (char *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: strlen(pString) + 1);
  if ( result == nullptr )
    return nullptr;
  strcpy(result, pString);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100A0BB0
// Name: void AddScriptToStack(char __near *,enum ScriptPathMode_t)
// Source: json
//------------------------------------------------------------------------------
void __cdecl AddScriptToStack(char *filename, ScriptPathMode_t pathMode)
{
  int File; // esi
  const char *v3; // [esp-8h] [ebp-8h]
  const char *savedregs; // [esp+0h] [ebp+0h]

  if ( ++script == (script_t *)token )
    _Error(this: (ISceneTokenProcessor *)&stru_105E5ECC, a2: savedregs);
  if ( pathMode == SCRIPT_USE_RELATIVE_PATH )
  {
    V_strncpy(pDest: script->filename, pSrc: filename, maxLen: 1024);
  }
  else
  {
    v3 = ExpandPath(path: filename);
    V_strncpy(pDest: script->filename, pSrc: v3, maxLen: 1024);
  }
  File = LoadFile(filename: script->filename, bufferptr: (void **)&script->buffer);
  if ( g_pfnCallback != nullptr )
    ((void (__thiscall *)(vgui::ToolWindow *))g_pfnCallback)(this: g_pfnCallback);
  script->line = 1;
  script->script_p = script->buffer;
  script->end_p = &script->buffer[File];
}

//------------------------------------------------------------------------------
// Address: 0x100A0C90
// Name: void LoadScriptFile(char __near *,enum ScriptPathMode_t)
// Source: json
//------------------------------------------------------------------------------
void __cdecl LoadScriptFile(char *filename, ScriptPathMode_t pathMode)
{
  script = scriptstack;
  AddScriptToStack(filename, pathMode);
  endofscript = 0;
  tokenready = 0;
}

//------------------------------------------------------------------------------
// Address: 0x100A0CC0
// Name: bool AddMacroToStack(char __near *)
// Source: json
//------------------------------------------------------------------------------
char __usercall AddMacroToStack@<al>(const char *a1@<ebx>, char *macroname)
{
  int v3; // esi
  bool v4; // zf
  script_t *v5; // edi
  script_t *v6; // ebx
  int nummacroparams; // eax
  char *macrobuffer; // esi
  char **macroparam; // edi
  unsigned int v10; // esi
  const char *v11; // [esp-Ch] [ebp-14h]
  script_t *pmacro; // [esp+4h] [ebp-4h]
  int i; // [esp+10h] [ebp+8h]

  if ( *macroname != 36 )
    return 0;
  v3 = 0;
  v4 = nummacros == 0;
  if ( nummacros > 0 )
  {
    do
    {
      if ( _V_stricmp(s1: macrolist[v3]->filename, s2: macroname + 1) == 0 )
        break;
      ++v3;
    }
    while ( v3 < nummacros );
    v4 = v3 == nummacros;
  }
  if ( v4 )
    return 0;
  v5 = macrolist[v3];
  v11 = a1;
  v6 = script + 2;
  pmacro = v5;
  if ( &script[2] == (script_t *)token )
    _Error(this: (ISceneTokenProcessor *)&stru_105E5ECC, a2: v11);
  nummacroparams = v5->nummacroparams;
  macrobuffer = v6->macrobuffer;
  v6->nummacroparams = nummacroparams;
  i = 0;
  if ( nummacroparams > 0 )
  {
    macroparam = v6->macroparam;
    do
    {
      GetToken(crossline: 0);
      strcpy(macrobuffer, token);
      *macroparam = *(char **)((char *)macroparam + (char *)pmacro - (char *)v6);
      macroparam[64] = macrobuffer;
      macrobuffer += strlen(token) + 1;
      if ( macrobuffer >= (char *)v6->macroparam )
        _Error(this: (ISceneTokenProcessor *)&stru_105E5EF0, a2: v11);
      ++macroparam;
      ++i;
    }
    while ( i < v6->nummacroparams );
    v5 = pmacro;
  }
  script = (script_t *)strcpy(v6->filename, v5->filename);
  v10 = v5->end_p - v5->buffer;
  script->buffer = (char *)MemAlloc_Alloc(nSize: v10 + 1);
  memcpy(dst: (unsigned __int8 *)script->buffer, src: (unsigned __int8 *)v5->buffer, count: v10);
  v5->buffer[v10] = 0;
  script->script_p = script->buffer;
  script->end_p = &script->buffer[v10];
  script->line = v5->line;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100A0E80
// Name: bool ExpandMacroToken(char __near * __near &)
// Source: json
//------------------------------------------------------------------------------
char __usercall ExpandMacroToken@<al>(const char *a1@<edi>, char **token_p)
{
  char *script_p; // eax
  _BYTE *v3; // ebx
  char v4; // al
  script_t *v6; // eax
  int v7; // esi
  int v8; // edi
  bool v9; // zf
  const char *v10; // edx
  unsigned int v11; // eax
  _BYTE *v12; // esi
  char v13; // cl
  const char *v15; // [esp+0h] [ebp-4h]

  if ( script->nummacroparams == 0 )
    return 0;
  script_p = script->script_p;
  if ( *script_p != 36 )
    return 0;
  v3 = script_p + 1;
  v15 = script_p + 1;
  v4 = script_p[1];
  if ( v4 <= 32 )
  {
LABEL_6:
    if ( *v3 != 36 )
      return 0;
  }
  else
  {
    while ( v4 != 36 )
    {
      v4 = *++v3;
      if ( v4 <= 32 )
        goto LABEL_6;
    }
  }
  *v3 = 0;
  v6 = script;
  v7 = 0;
  if ( script->nummacroparams <= 0 )
    goto LABEL_13;
  v8 = 5136;
  do
  {
    v9 = _V_stricmp(s1: *(const char **)&v6->filename[v8], s2: v15) == 0;
    v6 = script;
    if ( v9 )
      break;
    ++v7;
    v8 += 4;
  }
  while ( v7 < script->nummacroparams );
  if ( v7 >= script->nummacroparams )
  {
LABEL_13:
    _Error(this: (ISceneTokenProcessor *)&stru_105E5F3C, a2: v15, v6);
    v6 = script;
  }
  v10 = v6->macrovalue[v7];
  v11 = strlen(v10);
  v12 = *token_p;
  do
  {
    v13 = *v10;
    *v12++ = *v10++;
  }
  while ( v13 != 0 );
  *token_p += v11;
  script->script_p = v3 + 1;
  if ( script->script_p >= script->end_p )
    _Error(this: (ISceneTokenProcessor *)&stru_105E5F24, a2: a1);
  if ( *token_p >= (char *)&nummacros )
    _Error(this: (ISceneTokenProcessor *)&stru_105E5F08, a2: scriptline);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100A0FC0
// Name: void ParseFromMemory(char __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ParseFromMemory(char *buffer, int size)
{
  scriptstack[1].buffer = buffer;
  scriptstack[1].script_p = buffer;
  script = &scriptstack[1];
  scriptstack[1].end_p = &buffer[size];
  strcpy(scriptstack[1].filename, "memory buffer");
  scriptstack[1].line = 1;
  endofscript = 0;
  tokenready = 0;
}

//------------------------------------------------------------------------------
// Address: 0x100A1030
// Name: int EndOfScript(int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl EndOfScript(int crossline)
{
  if ( crossline == 0 )
    _Error(this: (ISceneTokenProcessor *)&stru_105E5F6C, a2: scriptline);
  if ( strcmp(script->filename, aMemoryB) == 0
    || (free(pMem: script->buffer), script->buffer = nullptr, script == &scriptstack[1]) )
  {
    endofscript = 1;
    return 0;
  }
  else
  {
    --script;
    scriptline = (char *)script->line;
    return GetToken(crossline);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A10F0
// Name: int TokenAvailable(void)
// Source: json
//------------------------------------------------------------------------------
int __cdecl TokenAvailable()
{
  char *script_p; // eax
  char *end_p; // edx
  char v3; // cl
  char v4; // cl

  if ( tokenready != 0 )
    return 1;
  script_p = script->script_p;
  end_p = script->end_p;
  if ( script_p < end_p )
  {
    v3 = *script_p;
    if ( *script_p > 32 )
    {
LABEL_8:
      v4 = *script_p;
      if ( *script_p != 59 && v4 != 35 && (v4 != 47 || script_p[1] != 47) )
        return 1;
    }
    else
    {
      while ( v3 != 10 )
      {
        if ( ++script_p == end_p )
          break;
        v3 = *script_p;
        if ( *script_p > 32 )
          goto LABEL_8;
      }
    }
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x100A1150
// Name: public: virtual bool CScriptLib::DoesFileExist(char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CScriptLib::DoesFileExist(CScriptLib *this, const char *pFilename)
{
  return g_pFullFileSystem->FileExists(this: &g_pFullFileSystem->IBaseFileSystem, a2: pFilename, a3: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x100A1170
// Name: public: virtual bool CScriptLib::ReadFileToBuffer(char const __near *,class CUtlBuffer __near &,bool,bool)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CScriptLib::ReadFileToBuffer(
        CScriptLib *this,
        const char *pSourceName,
        CUtlBuffer *buffer,
        bool bText,
        bool bNoOpenFailureWarning)
{
  int *v5; // eax
  const char *v6; // eax

  if ( g_pFullFileSystem->ReadFile(
         this: &g_pFullFileSystem->IBaseFileSystem,
         a2: pSourceName,
         a3: nullptr,
         a4: buffer,
         a5: 0,
         a6: 0,
         a7: nullptr) )
  {
    if ( bText )
      CUtlBuffer::SetBufferType(this: buffer, bIsText: true, bContainsCRLF: true);
    else
      CUtlBuffer::SetBufferType(this: buffer, bIsText: false, bContainsCRLF: false);
    return 1;
  }
  else
  {
    if ( !bNoOpenFailureWarning )
    {
      v5 = _errno();
      v6 = strerror(errnum: *v5);
      _Msg(a1: "ReadFileToBuffer(): Error opening %s: %s\n", pSourceName, v6);
    }
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A11F0
// Name: public: virtual bool CScriptLib::WriteBufferToFile(char const __near *,class CUtlBuffer __near &,enum DiskWriteMode_t)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CScriptLib::WriteBufferToFile(
        CScriptLib *this,
        const char *pTargetName,
        CUtlBuffer *buffer,
        DiskWriteMode_t writeMode)
{
  _BYTE *v5; // eax
  _BYTE *v6; // esi
  _BYTE *v7; // eax
  char dirPath[260]; // [esp+8h] [ebp-104h] BYREF

  strcpy(dirPath, pTargetName);
  strchr(string: dirPath, chr: 0x5Cu);
  v6 = v5;
  if ( v5 != nullptr )
  {
    while ( 1 )
    {
      strchr(string: v6 + 1, chr: 0x5Cu);
      v6 = v7;
      if ( v7 == nullptr )
        break;
      *v7 = 0;
      mkdir(path: dirPath);
      *v6 = 92;
    }
  }
  return writeMode != WRITE_TO_DISK_ALWAYS
      && (writeMode != WRITE_TO_DISK_UPDATE || !this->DoesFileExist(this, a2: pTargetName))
      || g_pFullFileSystem->WriteFile(
           this: &g_pFullFileSystem->IBaseFileSystem,
           a2: pTargetName,
           a3: nullptr,
           a4: buffer);
}

//------------------------------------------------------------------------------
// Address: 0x100A12B0
// Name: public: virtual int CScriptLib::CompareFileTime(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CScriptLib::CompareFileTime(CScriptLib *this, const char *pFilenameA, const char *pFilenameB)
{
  unsigned int v3; // esi
  unsigned int v4; // eax
  bool v5; // cf

  v3 = g_pFullFileSystem->GetFileTime(this: &g_pFullFileSystem->IBaseFileSystem, a2: pFilenameA, a3: nullptr);
  v4 = g_pFullFileSystem->GetFileTime(this: &g_pFullFileSystem->IBaseFileSystem, a2: pFilenameB, a3: nullptr);
  if ( v3 == -1 )
    v3 = 0;
  if ( v4 == -1 )
    return v3 != 0;
  v5 = v4 < v3;
  if ( v4 <= v3 )
    return v5;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x100A1310
// Name: public: virtual char __near * CScriptLib::MakeTemporaryFilename(char const __near *,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CScriptLib::MakeTemporaryFilename(CScriptLib *this, const char *pchModPath, char *pPath, int pathSize)
{
  char *v4; // eax
  char *v5; // esi

  v4 = _tempnam(dir: pchModPath, pfx: "mgd_");
  v5 = v4;
  if ( *v4 == 92 )
    v5 = v4 + 1;
  if ( v5[strlen(v5) - 1] == 46 )
    v5[strlen(v5) - 1] = 0;
  V_snprintf(pDest: pPath, maxLen: pathSize, pFormat: "%s.tmp", v5);
  free(pMem: v5);
  return pPath;
}

//------------------------------------------------------------------------------
// Address: 0x100A1380
// Name: void DefineMacro(char __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DefineMacro(char *macroname)
{
  script_t *v1; // edi
  char *script_p; // esi
  char *macrobuffer; // ebx
  unsigned int v4; // ebx
  unsigned __int8 *v5; // eax
  int v6; // eax
  script_t *v7; // edx
  const char *v8; // [esp+0h] [ebp-Ch]

  v1 = (script_t *)MemAlloc_Alloc(nSize: 0x1614u);
  strcpy(v1->filename, macroname);
  v1->line = script->line;
  v1->nummacroparams = 0;
  script_p = script->script_p;
  macrobuffer = v1->macrobuffer;
  while ( TokenAvailable() != 0 )
  {
    GetToken(crossline: 0);
    if ( token[0] == 92 && byte_107A84F1 == 92 )
      break;
    script_p = script->script_p;
    v1->macroparam[v1->nummacroparams++] = macrobuffer;
    strcpy(macrobuffer, token);
    macrobuffer += strlen(token) + 1;
    if ( macrobuffer >= (char *)v1->macroparam )
      _Error(this: (ISceneTokenProcessor *)&stru_105E5EF0, a2: v8);
  }
  for ( script->script_p = script_p; *script_p != 0; ++script_p )
  {
    if ( *script_p == 10 )
      break;
    if ( *script_p == 92 && script_p[1] == 92 )
    {
      do
      {
        if ( *script_p == 10 )
          break;
        *script_p++ = 32;
      }
      while ( *script_p != 0 );
      if ( *script_p == 0 )
        break;
    }
  }
  v4 = script_p - script->script_p;
  v5 = (unsigned __int8 *)MemAlloc_Alloc(nSize: v4 + 1);
  v1->buffer = (char *)v5;
  memcpy(dst: v5, src: (unsigned __int8 *)script->script_p, count: v4);
  v1->buffer[v4] = 0;
  v1->end_p = &v1->buffer[v4];
  v6 = nummacros;
  v7 = script;
  macrolist[nummacros] = v1;
  nummacros = v6 + 1;
  v7->script_p = script_p;
}

//------------------------------------------------------------------------------
// Address: 0x100A1520
// Name: bool ExpandVariableToken(char __near * __near &)
// Source: json
//------------------------------------------------------------------------------
char __usercall ExpandVariableToken@<al>(const char *a1@<edi>, char **token_p)
{
  char *script_p; // ebx
  const char *v3; // ebx
  char *v4; // esi
  char v5; // al
  int v7; // esi
  int v8; // edi
  void (*v9)(ISceneTokenProcessor *, const char *, ...); // ebx
  char *value; // edi
  unsigned int v11; // eax
  char *v12; // edx
  _BYTE *v13; // esi
  char v14; // cl
  const char *v15; // [esp-10h] [ebp-18h]
  char *cp; // [esp+4h] [ebp-4h]

  script_p = script->script_p;
  if ( *script_p != 36 )
    return 0;
  v3 = script_p + 1;
  v4 = (char *)v3;
  v5 = *v3;
  cp = (char *)v3;
  if ( *v3 <= 32 )
  {
LABEL_6:
    if ( *v4 != 36 )
      return 0;
  }
  else
  {
    while ( v5 != 36 )
    {
      v5 = *++v4;
      if ( v5 <= 32 )
      {
        cp = v4;
        goto LABEL_6;
      }
    }
    cp = v4;
  }
  v7 = v4 - v3;
  v8 = 0;
  v3[v7] = 0;
  if ( g_definevariable.m_Size <= 0 )
    goto LABEL_14;
  while ( V_strnicmp(s1: g_definevariable.m_Memory.m_pMemory[v8].param, s2: v3, n: v7) != 0 )
  {
    if ( ++v8 >= g_definevariable.m_Size )
      goto LABEL_14;
  }
  if ( v8 < g_definevariable.m_Size )
  {
    v9 = _Error;
  }
  else
  {
LABEL_14:
    v15 = v3;
    v9 = _Error;
    _Error(this: (ISceneTokenProcessor *)&stru_105E5FE0, a2: v15, script);
  }
  value = g_definevariable.m_Memory.m_pMemory[v8].value;
  v11 = strlen(value);
  v12 = value;
  v13 = *token_p;
  do
  {
    v14 = *v12;
    *v13++ = *v12++;
  }
  while ( v14 != 0 );
  *token_p += v11;
  script->script_p = cp + 1;
  if ( script->script_p >= script->end_p )
    v9(this: (ISceneTokenProcessor *)&stru_105E5F24, a2: a1);
  if ( *token_p >= (char *)&nummacros )
    v9(this: (ISceneTokenProcessor *)&stru_105E5F08, a2: scriptline);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100A1720
// Name: void DefineVariable(char __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DefineVariable(char *variablename)
{
  char *v1; // eax
  char *v2; // eax
  char *v3; // ecx
  char v4; // dl
  variable_t v; // [esp+8h] [ebp-8h] BYREF

  if ( variablename != nullptr
    && (v1 = (char *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: strlen(variablename) + 1)) != nullptr )
  {
    strcpy(v1, variablename);
  }
  else
  {
    v1 = nullptr;
  }
  v.param = v1;
  GetToken(crossline: 0);
  v2 = (char *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: strlen(token) + 1);
  if ( v2 != nullptr )
  {
    v3 = v2;
    do
    {
      v4 = v3[token - v2];
      *v3++ = v4;
    }
    while ( v4 != 0 );
  }
  else
  {
    v2 = nullptr;
  }
  v.value = v2;
  CUtlVector<vgui::AnimationController::RanEvent_t,CUtlMemory<vgui::AnimationController::RanEvent_t,int>>::InsertBefore(
    this: (CUtlVector<vgui::PropertySheet::Page_t,CUtlMemory<vgui::PropertySheet::Page_t,int> > *)&g_definevariable,
    elem: g_definevariable.m_Size,
    src: (const vgui::PropertySheet::Page_t *)&v);
}

//------------------------------------------------------------------------------
// Address: 0x100A17E0
// Name: int GetToken(int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl GetToken(int crossline)
{
  script_t *v1; // eax
  char *script_p; // ecx
  char v3; // dl
  script_t *v4; // eax
  char *v5; // ecx
  char *v6; // edx
  char v7; // cl
  char *v8; // ecx
  char v9; // dl
  script_t *v10; // eax
  char *v11; // edx
  script_t *v12; // eax
  char *line; // edx
  char v14; // cl
  char *v15; // esi
  script_t *v16; // eax
  char i; // cl
  char *v18; // esi
  char *v19; // ecx
  char *token_p; // [esp+Ch] [ebp-4h] BYREF

  if ( tokenready != 0 )
  {
LABEL_54:
    tokenready = 0;
    return 1;
  }
  else
  {
    while ( 1 )
    {
      v1 = script;
      if ( script->script_p >= script->end_p )
        return EndOfScript(crossline);
      tokenready = 0;
      while ( 1 )
      {
        while ( 1 )
        {
          if ( *v1->script_p <= 32 )
          {
            do
            {
              script_p = v1->script_p;
              if ( script_p >= v1->end_p )
                return EndOfScript(crossline);
              v3 = *script_p;
              v1->script_p = script_p + 1;
              if ( v3 == 10 )
              {
                if ( crossline == 0 )
                  _Error(this: (ISceneTokenProcessor *)&stru_105E5F6C, a2: scriptline);
                v4 = script;
                ++script->line;
                scriptline = (char *)v4->line;
              }
              v1 = script;
            }
            while ( *script->script_p <= 32 );
          }
          v5 = v1->script_p;
          if ( v5 >= v1->end_p )
            return EndOfScript(crossline);
          v6 = v1->script_p;
          v7 = *v5;
          if ( v7 != 59 && v7 != 35 )
          {
            if ( v7 != 47 )
              goto LABEL_30;
            if ( v6[1] != 47 )
              break;
          }
          if ( crossline == 0 )
          {
            _Error(this: (ISceneTokenProcessor *)&stru_105E5F6C, a2: scriptline);
            v1 = script;
          }
          if ( *v1->script_p != 10 )
          {
            do
            {
              ++v1->script_p;
              v1 = script;
              v11 = script->script_p;
              if ( v11 >= script->end_p )
                return EndOfScript(crossline);
            }
            while ( *v11 != 10 );
          }
          ++v1->script_p;
          v12 = script;
          ++script->line;
          line = (char *)v12->line;
          v1 = script;
          scriptline = line;
        }
        if ( v6[1] != 42 )
          break;
        v1->script_p += 2;
        while ( 1 )
        {
          v8 = script->script_p;
          if ( *v8 == 42 && v8[1] == 47 )
            break;
          v9 = *v8;
          script->script_p = v8 + 1;
          if ( v9 != 10 )
          {
            v10 = script;
            if ( script->script_p >= script->end_p )
              return EndOfScript(crossline);
            ++script->line;
            scriptline = (char *)v10->line;
          }
        }
        script->script_p += 2;
        v1 = script;
      }
LABEL_30:
      v14 = *v6;
      v15 = token;
      token_p = token;
      if ( v14 == 34 )
      {
        ++v1->script_p;
        v16 = script;
        for ( i = *script->script_p; i != 34; i = *v16->script_p )
        {
          *v15 = i;
          ++script->script_p;
          v16 = script;
          ++v15;
          if ( script->script_p == script->end_p )
            break;
          if ( v15 == (char *)&nummacros )
          {
            _Error(this: (ISceneTokenProcessor *)&stru_105E5F08, a2: scriptline);
            v16 = script;
          }
        }
        ++v16->script_p;
      }
      else
      {
        for ( ; v14 > 32; v14 = *script->script_p )
        {
          if ( v14 == 59 )
            break;
          if ( ExpandMacroToken(a1: (const char *)1, &token_p) != 0
            || ExpandVariableToken(a1: (const char *)1, &token_p) != 0 )
          {
            v15 = token_p;
          }
          else
          {
            v18 = token_p;
            *token_p = *script->script_p++;
            v19 = script->script_p;
            v15 = v18 + 1;
            token_p = v15;
            if ( v19 == script->end_p )
              break;
            if ( v15 == (char *)&nummacros )
              _Error(this: (ISceneTokenProcessor *)&stru_105E5F08, a2: scriptline);
          }
        }
      }
      *v15 = 0;
      if ( _V_stricmp(s1: token, s2: "$include") != 0 )
      {
        if ( _V_stricmp(s1: token, s2: "$definemacro") != 0 )
        {
          if ( _V_stricmp(s1: token, s2: "$definevariable") != 0 )
          {
            if ( AddMacroToStack(a1: (const char *)_Error, macroname: token) == 0 )
              return 1;
          }
          else
          {
            GetToken(crossline: 0);
            DefineVariable(variablename: token);
          }
        }
        else
        {
          GetToken(crossline: 0);
          DefineMacro(macroname: token);
        }
      }
      else
      {
        GetToken(crossline: 0);
        AddScriptToStack(filename: token, pathMode: SCRIPT_USE_ABSOLUTE_PATH);
      }
      if ( tokenready != 0 )
        goto LABEL_54;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A1F80
// Name: private: int CScriptLib::GetFileList(char const __near *,char const __near *,class CUtlVector<struct fileList_t,class CUtlMemory<struct fileList_t,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CScriptLib::GetFileList(
        CScriptLib *this,
        const char *pDirPath,
        const char *pPattern,
        CUtlVector<fileList_t,CUtlMemory<fileList_t,int> > *fileList)
{
  unsigned int v5; // kr00_4
  int v6; // eax
  char v7; // cl
  char *v8; // edi
  char v9; // al
  unsigned int v10; // eax
  char *v11; // edi
  char v12; // cl
  int v13; // esi
  int v15; // eax
  char v16; // cl
  unsigned int v17; // eax
  char *v18; // edi
  char v19; // cl
  char *v20; // edi
  char *v21; // esi
  char v22; // cl
  int m_Size; // eax
  int v24; // esi
  char v25; // [esp+Bh] [ebp-435h] BYREF
  char fileName[260]; // [esp+Ch] [ebp-434h] BYREF
  char fullPath[260]; // [esp+110h] [ebp-330h] BYREF
  _finddata64i32_t findData; // [esp+214h] [ebp-22Ch] BYREF
  char sourcePath[260]; // [esp+33Ch] [ebp-104h] BYREF
  int h; // [esp+448h] [ebp+8h]
  char bFindDirs_3; // [esp+453h] [ebp+13h]

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
  v5 = strlen(sourcePath);
  if ( v5 != 0 )
  {
    if ( findData.name[v5 + 259] != 92 )
    {
      sourcePath[v5] = 92;
      sourcePath[v5 + 1] = 0;
    }
  }
  else
  {
    strcpy(sourcePath, ".\\");
  }
  v6 = 0;
  do
  {
    v7 = sourcePath[v6];
    fullPath[v6++] = v7;
  }
  while ( v7 != 0 );
  if ( *pPattern != 92 || pPattern[1] != 0 )
  {
    bFindDirs_3 = 0;
    v10 = strlen(pPattern) + 1;
    v11 = &fileName[259];
    do
      v12 = *++v11;
    while ( v12 != 0 );
    qmemcpy(v11, pPattern, v10);
  }
  else
  {
    bFindDirs_3 = 1;
    v8 = &fileName[259];
    do
      v9 = *++v8;
    while ( v9 != 0 );
    strcpy(v8, "*");
  }
  v13 = _findfirst64i32(szWild: fullPath, pfd: &findData);
  h = v13;
  if ( v13 == -1 )
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
      v15 = 0;
      do
      {
        v16 = sourcePath[v15];
        fileName[v15++] = v16;
      }
      while ( v16 != 0 );
      v17 = strlen(findData.name) + 1;
      v18 = &v25;
      do
        v19 = *++v18;
      while ( v19 != 0 );
      qmemcpy(v18, findData.name, 4 * (v17 >> 2));
      v21 = &findData.name[4 * (v17 >> 2)];
      v20 = &v18[4 * (v17 >> 2)];
      v22 = v17;
      m_Size = fileList->m_Size;
      qmemcpy(v20, v21, v22 & 3);
      v24 = CUtlVector<fileList_t,CUtlMemory<fileList_t,int>>::InsertBefore(this: fileList, elem: m_Size);
      CUtlString::Set(this: &fileList->m_Memory.m_pMemory[v24].fileName, pValue: fileName);
      fileList->m_Memory.m_pMemory[v24].timeWrite = findData.time_write;
      v13 = h;
    }
  }
  while ( _findnext64i32(hFile: v13, pfd: &findData) == 0 );
  _findclose(hFile: v13);
  return fileList->m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x100A2280
// Name: public: virtual void CScriptLib::DeleteTemporaryFiles(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CScriptLib::DeleteTemporaryFiles(CScriptLib *this, const char *pFileMask)
{
  char *v2; // eax
  char *v3; // edx
  char v4; // cl
  unsigned int v5; // eax
  char *v6; // edi
  char v7; // cl
  int v8; // esi
  int v9; // edi
  const char *v10; // eax
  char v11; // [esp+3h] [ebp-129h] BYREF
  char tempPath[260]; // [esp+4h] [ebp-128h] BYREF
  CScriptLib *v13; // [esp+108h] [ebp-24h]
  CUtlVector<fileList_t,CUtlMemory<fileList_t,int> > fileList; // [esp+10Ch] [ebp-20h] BYREF
  int v15; // [esp+128h] [ebp-4h]

  v13 = this;
  v2 = getenv(option: "temp");
  if ( v2 != nullptr || (v2 = getenv(option: "tmp")) != nullptr )
  {
    v3 = (char *)(tempPath - v2);
    do
    {
      v4 = *v2;
      v2[(_DWORD)v3] = *v2;
      ++v2;
    }
    while ( v4 != 0 );
    V_AppendSlash(pStr: tempPath, strSize: 260);
    v5 = strlen(pFileMask) + 1;
    v6 = &v11;
    do
      v7 = *++v6;
    while ( v7 != 0 );
    qmemcpy(v6, pFileMask, v5);
    memset(&fileList, 0, sizeof(fileList));
    v15 = 1;
    v13->FindFiles(this: v13, a2: tempPath, a3: false, a4: &fileList);
    v8 = 0;
    if ( fileList.m_Size > 0 )
    {
      v9 = 0;
      do
      {
        v10 = CUtlString::operator char const *(this: &fileList.m_Memory.m_pMemory[v9].fileName);
        unlink(path: v10);
        ++v8;
        ++v9;
      }
      while ( v8 < fileList.m_Size );
    }
    v15 = -1;
    CUtlVector<fileList_t,CUtlMemory<fileList_t,int>>::~CUtlVector<fileList_t,CUtlMemory<fileList_t,int>>(this: &fileList);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A23A0
// Name: private: void CScriptLib::RecurseFileTree_r(char const __near *,int,class CUtlVector<class CUtlString,class CUtlMemory<class CUtlString,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CScriptLib::RecurseFileTree_r(
        CScriptLib *this,
        const char *pDirPath,
        int depth,
        CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *dirList)
{
  int i; // ebx
  int v5; // eax
  CUtlString *v6; // ecx
  int v7; // edi
  const char *v8; // eax
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CUtlString *m_pMemory; // ecx
  int v12; // eax
  int v13; // edi
  bool v14; // zf
  CUtlString *v15; // ecx
  CUtlVector<fileList_t,CUtlMemory<fileList_t,int> > fileList; // [esp+Ch] [ebp-24h] BYREF
  CScriptLib *v17; // [esp+20h] [ebp-10h]
  int v18; // [esp+2Ch] [ebp-4h]

  i = 0;
  v17 = this;
  memset(&fileList, 0, sizeof(fileList));
  v18 = 1;
  v5 = CScriptLib::GetFileList(this, pDirPath, pPattern: "\\", &fileList);
  if ( v5 != 0 )
  {
    if ( v5 > 0 )
    {
      v7 = 0;
      for ( i = v5; i != 0; --i )
      {
        v8 = CUtlString::operator char const *(this: &fileList.m_Memory.m_pMemory[v7].fileName);
        CScriptLib::RecurseFileTree_r(this: v17, pDirPath: v8, depth: depth + 1, dirList);
        ++v7;
      }
    }
    m_Size = dirList->m_Size;
    m_nAllocationCount = dirList->m_Memory.m_nAllocationCount;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<ActiveLayer_t<QAngle>,int>::Grow(
        this: (CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int> *)dirList,
        num: m_Size - m_nAllocationCount + 1);
    ++dirList->m_Size;
    m_pMemory = dirList->m_Memory.m_pMemory;
    v12 = dirList->m_Size - m_Size - 1;
    dirList->m_pElements = dirList->m_Memory.m_pMemory;
    if ( v12 > i )
      _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 16 * v12);
    v13 = m_Size;
    v14 = &dirList->m_Memory.m_pMemory[v13] == nullptr;
    v15 = &dirList->m_Memory.m_pMemory[v13];
    LOBYTE(v18) = 2;
    if ( !v14 )
      CUtlString::CUtlString(this: v15);
    LOBYTE(v18) = 1;
    CUtlString::Set(this: &dirList->m_Memory.m_pMemory[v13], pValue: pDirPath);
  }
  else
  {
    v6 = &dirList->m_Memory.m_pMemory[CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>::InsertBefore(
                                        this: dirList,
                                        elem: dirList->m_Size)];
    CUtlString::Set(this: v6, pValue: pDirPath);
  }
  v18 = -1;
  CUtlVector<fileList_t,CUtlMemory<fileList_t,int>>::~CUtlVector<fileList_t,CUtlMemory<fileList_t,int>>(this: &fileList);
}

//------------------------------------------------------------------------------
// Address: 0x100A24D0
// Name: public: virtual int CScriptLib::FindFiles(char __near *,bool,class CUtlVector<struct fileList_t,class CUtlMemory<struct fileList_t,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CScriptLib::FindFiles(
        CScriptLib *this,
        char *pFileMask,
        bool bRecurse,
        CUtlVector<fileList_t,CUtlMemory<fileList_t,int> > *fileList)
{
  CScriptLib *v4; // ebx
  char *v5; // edi
  char v6; // al
  unsigned int v7; // eax
  char *v8; // edi
  char v9; // cl
  fileList_t *m_pMemory; // eax
  const char *v12; // eax
  CUtlVector<fileList_t,CUtlMemory<fileList_t,int> > *v13; // esi
  int inserted; // eax
  int v15; // ebx
  fileList_t *v16; // edi
  CUtlString *p_fileName; // esi
  int v18; // eax
  char extension[260]; // [esp+Ch] [ebp-34Ch] BYREF
  char dirPath[260]; // [esp+110h] [ebp-248h] BYREF
  char pattern[260]; // [esp+214h] [ebp-144h] BYREF
  CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > dirList; // [esp+318h] [ebp-40h] BYREF
  int j; // [esp+32Ch] [ebp-2Ch]
  CScriptLib *v24; // [esp+330h] [ebp-28h]
  int i; // [esp+334h] [ebp-24h]
  CUtlVector<fileList_t,CUtlMemory<fileList_t,int> > tempList; // [esp+338h] [ebp-20h] BYREF
  int v27; // [esp+354h] [ebp-4h]
  char *pFileMaska; // [esp+360h] [ebp+8h]
  int bRecursea; // [esp+364h] [ebp+Ch]

  v4 = this;
  v24 = this;
  strcpy(dirPath, pFileMask);
  V_StripFilename(path: dirPath);
  V_FileBase(in: pFileMask, out: pattern, maxlen: 260);
  V_ExtractFileExtension(path: pFileMask, dest: extension, destSize: 260);
  if ( extension[0] != 0 )
  {
    v5 = &dirPath[259];
    do
      v6 = *++v5;
    while ( v6 != 0 );
    strcpy(v5, ".");
    v7 = strlen(extension) + 1;
    v8 = &dirPath[259];
    do
      v9 = *++v8;
    while ( v9 != 0 );
    qmemcpy(v8, extension, v7);
  }
  if ( bRecurse )
  {
    memset(&tempList, 0, sizeof(tempList));
    v27 = 3;
    memset(&dirList, 0, sizeof(dirList));
    CScriptLib::RecurseFileTree_r(this: v4, pDirPath: dirPath, depth: 0, &dirList);
    i = 0;
    if ( dirList.m_Size > 0 )
    {
      pFileMaska = nullptr;
      do
      {
        CUtlVector<fileList_t,CUtlMemory<fileList_t,int>>::RemoveAll(this: &tempList);
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
        tempList.m_pElements = m_pMemory;
        if ( tempList.m_Memory.m_nAllocationCount < dirList.m_Size && tempList.m_Memory.m_nGrowSize >= 0 )
        {
          tempList.m_Memory.m_nAllocationCount = dirList.m_Size;
          if ( m_pMemory != nullptr )
            m_pMemory = (fileList_t *)_g_pMemAlloc->Realloc_2(
                                        this: _g_pMemAlloc,
                                        a2: m_pMemory,
                                        a3: 24 * dirList.m_Size);
          else
            m_pMemory = (fileList_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 24 * dirList.m_Size);
          tempList.m_Memory.m_pMemory = m_pMemory;
        }
        tempList.m_pElements = m_pMemory;
        v12 = CUtlString::operator char const *(this: (CUtlString *)&pFileMaska[(unsigned int)dirList.m_Memory.m_pMemory]);
        CScriptLib::GetFileList(this: v4, pDirPath: v12, pPattern: pattern, fileList: &tempList);
        v13 = fileList;
        inserted = CUtlVector<fileList_t,CUtlMemory<fileList_t,int>>::InsertMultipleBefore(
                     this: fileList,
                     elem: fileList->m_Size,
                     num: tempList.m_Size);
        j = 0;
        if ( tempList.m_Size > 0 )
        {
          bRecursea = 0;
          v15 = inserted;
          while ( 1 )
          {
            v16 = &tempList.m_Memory.m_pMemory[bRecursea];
            p_fileName = &v13->m_Memory.m_pMemory[v15].fileName;
            CUtlString::operator=(this: p_fileName, src: &tempList.m_Memory.m_pMemory[bRecursea].fileName);
            v18 = j;
            ++bRecursea;
            p_fileName[1].m_Storage.m_Memory.m_pMemory = (unsigned __int8 *)v16->timeWrite;
            p_fileName[1].m_Storage.m_Memory.m_nAllocationCount = HIDWORD(v16->timeWrite);
            ++v15;
            j = v18 + 1;
            if ( v18 + 1 >= tempList.m_Size )
              break;
            v13 = fileList;
          }
          v4 = v24;
        }
        pFileMaska += 16;
        ++i;
      }
      while ( i < dirList.m_Size );
    }
    LOBYTE(v27) = 1;
    CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>::~CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>(this: &dirList);
    v27 = -1;
    CUtlVector<fileList_t,CUtlMemory<fileList_t,int>>::~CUtlVector<fileList_t,CUtlMemory<fileList_t,int>>(this: &tempList);
    return fileList->m_Size;
  }
  else
  {
    CScriptLib::GetFileList(this: v4, pDirPath: dirPath, pPattern: pattern, fileList);
    return fileList->m_Size;
  }
}

} // namespace hammer_dll

// ============================================================
// Overlay from localization_check (Missing functions)
// ============================================================
namespace localization_check {

//------------------------------------------------------------------------------
// Address: 0x004162D0
// Name: void AddScriptToStack(char __near *,enum ScriptPathMode_t)
// Source: json
//------------------------------------------------------------------------------
void __usercall AddScriptToStack(int a1@<edi>, char *filename, ScriptPathMode_t pathMode)
{
  int File; // esi
  const char *v4; // [esp-8h] [ebp-8h]
  const char *savedregs; // [esp+0h] [ebp+0h]

  if ( ++script == (script_t *)token )
    _Error(this: (ISceneTokenProcessor *)&stru_447538, a2: savedregs);
  if ( pathMode == SCRIPT_USE_RELATIVE_PATH )
  {
    V_strncpy(pDest: script->filename, pSrc: filename, maxLen: 1024);
  }
  else
  {
    v4 = ExpandPath(path: filename);
    V_strncpy(pDest: script->filename, pSrc: v4, maxLen: 1024);
  }
  File = LoadFile(a1, filename: script->filename, bufferptr: (void **)&script->buffer);
  if ( g_pfnCallback != nullptr )
  {
    if ( script == &scriptstack[1] )
      g_pfnCallback(a1: script->filename, a2: nullptr, a3: 0);
    else
      g_pfnCallback(a1: script->filename, a2: script[-1].filename, a3: script[-1].line);
  }
  script->line = 1;
  script->script_p = script->buffer;
  script->end_p = &script->buffer[File];
}

//------------------------------------------------------------------------------
// Address: 0x004163B0
// Name: void LoadScriptFile(char __near *,enum ScriptPathMode_t)
// Source: json
//------------------------------------------------------------------------------
void __usercall LoadScriptFile(int a1@<edi>, char *filename, ScriptPathMode_t pathMode)
{
  script = scriptstack;
  AddScriptToStack(a1, filename, pathMode);
  endofscript = 0;
  tokenready = 0;
}

//------------------------------------------------------------------------------
// Address: 0x004163E0
// Name: bool AddMacroToStack(char __near *)
// Source: json
//------------------------------------------------------------------------------
char __usercall AddMacroToStack@<al>(const char *a1@<ebx>, char *macroname)
{
  int v3; // esi
  bool v4; // zf
  script_t *v5; // edi
  script_t *v6; // ebx
  int nummacroparams; // eax
  char *macrobuffer; // esi
  char **macroparam; // edi
  unsigned int v10; // esi
  const char *v11; // [esp-Ch] [ebp-14h]
  script_t *pmacro; // [esp+4h] [ebp-4h]
  int i; // [esp+10h] [ebp+8h]

  if ( *macroname != 36 )
    return 0;
  v3 = 0;
  v4 = nummacros == 0;
  if ( nummacros > 0 )
  {
    do
    {
      if ( _V_stricmp(s1: macrolist[v3]->filename, s2: macroname + 1) == 0 )
        break;
      ++v3;
    }
    while ( v3 < nummacros );
    v4 = v3 == nummacros;
  }
  if ( v4 )
    return 0;
  v5 = macrolist[v3];
  v11 = a1;
  v6 = script + 2;
  pmacro = v5;
  if ( &script[2] == (script_t *)token )
    _Error(this: (ISceneTokenProcessor *)&stru_447538, a2: v11);
  nummacroparams = v5->nummacroparams;
  macrobuffer = v6->macrobuffer;
  v6->nummacroparams = nummacroparams;
  i = 0;
  if ( nummacroparams > 0 )
  {
    macroparam = v6->macroparam;
    do
    {
      GetToken(crossline: 0);
      strcpy(macrobuffer, token);
      *macroparam = *(char **)((char *)macroparam + (char *)pmacro - (char *)v6);
      macroparam[64] = macrobuffer;
      macrobuffer += strlen(token) + 1;
      if ( macrobuffer >= (char *)v6->macroparam )
        _Error(this: (ISceneTokenProcessor *)&stru_44755C, a2: v11);
      ++macroparam;
      ++i;
    }
    while ( i < v6->nummacroparams );
    v5 = pmacro;
  }
  script = (script_t *)strcpy(v6->filename, v5->filename);
  v10 = v5->end_p - v5->buffer;
  script->buffer = (char *)operator new(nSize: v10 + 1);
  memcpy(dst: (unsigned __int8 *)script->buffer, src: (unsigned __int8 *)v5->buffer, count: v10);
  v5->buffer[v10] = 0;
  script->script_p = script->buffer;
  script->end_p = &script->buffer[v10];
  script->line = v5->line;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004165A0
// Name: bool ExpandMacroToken(char __near * __near &)
// Source: json
//------------------------------------------------------------------------------
char __usercall ExpandMacroToken@<al>(const char *a1@<edi>, char **token_p)
{
  char *script_p; // eax
  _BYTE *v3; // ebx
  char v4; // al
  script_t *v6; // eax
  int v7; // esi
  int v8; // edi
  bool v9; // zf
  const char *v10; // edx
  unsigned int v11; // eax
  _BYTE *v12; // esi
  char v13; // cl
  char *s2; // [esp+0h] [ebp-4h]

  if ( script->nummacroparams == 0 )
    return 0;
  script_p = script->script_p;
  if ( *script_p != 36 )
    return 0;
  v3 = script_p + 1;
  s2 = script_p + 1;
  v4 = script_p[1];
  if ( v4 <= 32 )
  {
LABEL_6:
    if ( *v3 != 36 )
      return 0;
  }
  else
  {
    while ( v4 != 36 )
    {
      v4 = *++v3;
      if ( v4 <= 32 )
        goto LABEL_6;
    }
  }
  *v3 = 0;
  v6 = script;
  v7 = 0;
  if ( script->nummacroparams <= 0 )
    goto LABEL_13;
  v8 = 5136;
  do
  {
    v9 = _V_stricmp(s1: *(const char **)&v6->filename[v8], s2) == 0;
    v6 = script;
    if ( v9 )
      break;
    ++v7;
    v8 += 4;
  }
  while ( v7 < script->nummacroparams );
  if ( v7 >= script->nummacroparams )
  {
LABEL_13:
    _Error(this: (ISceneTokenProcessor *)&stru_4475A8, a2: s2, v6);
    v6 = script;
  }
  v10 = v6->macrovalue[v7];
  v11 = strlen(v10);
  v12 = *token_p;
  do
  {
    v13 = *v10;
    *v12++ = *v10++;
  }
  while ( v13 != 0 );
  *token_p += v11;
  script->script_p = v3 + 1;
  if ( script->script_p >= script->end_p )
    _Error(this: (ISceneTokenProcessor *)&stru_447590, a2: a1);
  if ( *token_p >= (char *)&nummacros )
    _Error(this: (ISceneTokenProcessor *)&stru_447574, a2: scriptline);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004166D0
// Name: int EndOfScript(int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl EndOfScript(int crossline)
{
  if ( crossline == 0 )
    _Error(this: (ISceneTokenProcessor *)&stru_4475D8, a2: scriptline);
  if ( strcmp(script->filename, "memory buffer") == 0
    || (free(pMem: script->buffer), script->buffer = nullptr, script == &scriptstack[1]) )
  {
    endofscript = 1;
    return 0;
  }
  else
  {
    --script;
    scriptline = (char *)script->line;
    return GetToken(crossline);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00416790
// Name: int TokenAvailable(void)
// Source: json
//------------------------------------------------------------------------------
int __cdecl TokenAvailable()
{
  char *script_p; // eax
  char *end_p; // edx
  char v3; // cl
  char v4; // cl

  if ( tokenready != 0 )
    return 1;
  script_p = script->script_p;
  end_p = script->end_p;
  if ( script_p < end_p )
  {
    v3 = *script_p;
    if ( *script_p > 32 )
    {
LABEL_8:
      v4 = *script_p;
      if ( *script_p != 59 && v4 != 35 && (v4 != 47 || script_p[1] != 47) )
        return 1;
    }
    else
    {
      while ( v3 != 10 )
      {
        if ( ++script_p == end_p )
          break;
        v3 = *script_p;
        if ( *script_p > 32 )
          goto LABEL_8;
      }
    }
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x004167F0
// Name: public: virtual bool CScriptLib::DoesFileExist(char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CScriptLib::DoesFileExist(CScriptLib *this, const char *pFilename)
{
  return g_pFullFileSystem->FileExists(this: &g_pFullFileSystem->IBaseFileSystem, a2: pFilename, a3: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x00416810
// Name: public: virtual bool CScriptLib::ReadFileToBuffer(char const __near *,class CUtlBuffer __near &,bool,bool)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CScriptLib::ReadFileToBuffer(
        CScriptLib *this,
        const char *pSourceName,
        CUtlBuffer *buffer,
        bool bText,
        bool bNoOpenFailureWarning)
{
  int *v5; // eax
  const char *v6; // eax

  if ( g_pFullFileSystem->ReadFile(
         this: &g_pFullFileSystem->IBaseFileSystem,
         a2: pSourceName,
         a3: nullptr,
         a4: buffer,
         a5: 0,
         a6: 0,
         a7: nullptr) )
  {
    if ( bText )
      CUtlBuffer::SetBufferType(this: buffer, bIsText: true, bContainsCRLF: true);
    else
      CUtlBuffer::SetBufferType(this: buffer, bIsText: false, bContainsCRLF: false);
    return 1;
  }
  else
  {
    if ( !bNoOpenFailureWarning )
    {
      v5 = _errno();
      v6 = strerror(errnum: *v5);
      _Msg(a1: "ReadFileToBuffer(): Error opening %s: %s\n", pSourceName, v6);
    }
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00416890
// Name: public: virtual bool CScriptLib::WriteBufferToFile(char const __near *,class CUtlBuffer __near &,enum DiskWriteMode_t)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CScriptLib::WriteBufferToFile(
        CScriptLib *this,
        const char *pTargetName,
        CUtlBuffer *buffer,
        DiskWriteMode_t writeMode)
{
  _BYTE *v5; // eax
  _BYTE *v6; // esi
  _BYTE *v7; // eax
  char dirPath[260]; // [esp+8h] [ebp-104h] BYREF

  strcpy(dirPath, pTargetName);
  strchr(string: (unsigned __int8 *)dirPath, chr: 0x5Cu);
  v6 = v5;
  if ( v5 != nullptr )
  {
    while ( 1 )
    {
      strchr(string: v6 + 1, chr: 0x5Cu);
      v6 = v7;
      if ( v7 == nullptr )
        break;
      *v7 = 0;
      mkdir(path: dirPath);
      *v6 = 92;
    }
  }
  return writeMode != WRITE_TO_DISK_ALWAYS
      && (writeMode != WRITE_TO_DISK_UPDATE || !this->DoesFileExist(this, a2: pTargetName))
      || g_pFullFileSystem->WriteFile(
           this: &g_pFullFileSystem->IBaseFileSystem,
           a2: pTargetName,
           a3: nullptr,
           a4: buffer);
}

//------------------------------------------------------------------------------
// Address: 0x00416950
// Name: public: virtual int CScriptLib::CompareFileTime(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CScriptLib::CompareFileTime(CScriptLib *this, const char *pFilenameA, const char *pFilenameB)
{
  unsigned int v3; // esi
  unsigned int v4; // eax
  bool v5; // cf

  v3 = g_pFullFileSystem->GetFileTime(this: &g_pFullFileSystem->IBaseFileSystem, a2: pFilenameA, a3: nullptr);
  v4 = g_pFullFileSystem->GetFileTime(this: &g_pFullFileSystem->IBaseFileSystem, a2: pFilenameB, a3: nullptr);
  if ( v3 == -1 )
    v3 = 0;
  if ( v4 == -1 )
    return v3 != 0;
  v5 = v4 < v3;
  if ( v4 <= v3 )
    return v5;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004169B0
// Name: public: virtual char __near * CScriptLib::MakeTemporaryFilename(char const __near *,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CScriptLib::MakeTemporaryFilename(CScriptLib *this, const char *pchModPath, char *pPath, int pathSize)
{
  char *v4; // eax
  char *v5; // esi

  v4 = _tempnam(dir: pchModPath, pfx: "mgd_");
  v5 = v4;
  if ( *v4 == 92 )
    v5 = v4 + 1;
  if ( v5[strlen(v5) - 1] == 46 )
    v5[strlen(v5) - 1] = 0;
  V_snprintf(pDest: pPath, maxLen: pathSize, pFormat: "%s.tmp", v5);
  free(pMem: v5);
  return pPath;
}

//------------------------------------------------------------------------------
// Address: 0x00416A20
// Name: void DefineMacro(char __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DefineMacro(char *macroname)
{
  script_t *v1; // edi
  char *script_p; // esi
  char *macrobuffer; // ebx
  unsigned int v4; // ebx
  unsigned __int8 *v5; // eax
  int v6; // eax
  script_t *v7; // edx
  const char *v8; // [esp+0h] [ebp-Ch]

  v1 = (script_t *)operator new(nSize: 0x1614u);
  strcpy(v1->filename, macroname);
  v1->line = script->line;
  v1->nummacroparams = 0;
  script_p = script->script_p;
  macrobuffer = v1->macrobuffer;
  while ( TokenAvailable() != 0 )
  {
    GetToken(crossline: 0);
    if ( token[0] == 92 && byte_481B39 == 92 )
      break;
    script_p = script->script_p;
    v1->macroparam[v1->nummacroparams++] = macrobuffer;
    strcpy(macrobuffer, token);
    macrobuffer += strlen(token) + 1;
    if ( macrobuffer >= (char *)v1->macroparam )
      _Error(this: (ISceneTokenProcessor *)&stru_44755C, a2: v8);
  }
  for ( script->script_p = script_p; *script_p != 0; ++script_p )
  {
    if ( *script_p == 10 )
      break;
    if ( *script_p == 92 && script_p[1] == 92 )
    {
      do
      {
        if ( *script_p == 10 )
          break;
        *script_p++ = 32;
      }
      while ( *script_p != 0 );
      if ( *script_p == 0 )
        break;
    }
  }
  v4 = script_p - script->script_p;
  v5 = (unsigned __int8 *)operator new(nSize: v4 + 1);
  v1->buffer = (char *)v5;
  memcpy(dst: v5, src: (unsigned __int8 *)script->script_p, count: v4);
  v1->buffer[v4] = 0;
  v1->end_p = &v1->buffer[v4];
  v6 = nummacros;
  v7 = script;
  macrolist[nummacros] = v1;
  nummacros = v6 + 1;
  v7->script_p = script_p;
}

//------------------------------------------------------------------------------
// Address: 0x00416C60
// Name: bool ExpandVariableToken(char __near * __near &)
// Source: json
//------------------------------------------------------------------------------
char __usercall ExpandVariableToken@<al>(const char *a1@<edi>, char **token_p)
{
  char *script_p; // eax
  const char *v3; // edi
  _BYTE *v4; // ebx
  char v5; // al
  int v7; // esi
  char *value; // esi
  unsigned int v9; // eax
  char *v10; // edx
  _BYTE *v11; // esi
  char v12; // cl

  script_p = script->script_p;
  if ( *script_p != 36 )
    return 0;
  v3 = script_p + 1;
  v4 = script_p + 1;
  v5 = script_p[1];
  if ( v5 <= 32 )
  {
LABEL_5:
    if ( *v4 != 36 )
      return 0;
  }
  else
  {
    while ( v5 != 36 )
    {
      v5 = *++v4;
      if ( v5 <= 32 )
        goto LABEL_5;
    }
  }
  v7 = 0;
  *v4 = 0;
  if ( g_definevariable.m_Size <= 0 )
    goto LABEL_12;
  while ( V_strnicmp(s1: g_definevariable.m_Memory.m_pMemory[v7].param, s2: v3, n: v4 - v3 - 2) != 0 )
  {
    if ( ++v7 >= g_definevariable.m_Size )
      goto LABEL_12;
  }
  if ( v7 >= g_definevariable.m_Size )
LABEL_12:
    _Error(this: (ISceneTokenProcessor *)&stru_44764C, a2: v3, script);
  value = g_definevariable.m_Memory.m_pMemory[v7].value;
  v9 = strlen(value);
  v10 = value;
  v11 = *token_p;
  do
  {
    v12 = *v10;
    *v11++ = *v10++;
  }
  while ( v12 != 0 );
  *token_p += v9;
  script->script_p = v4 + 1;
  if ( script->script_p >= script->end_p )
    _Error(this: (ISceneTokenProcessor *)&stru_447590, a2: a1);
  if ( *token_p >= (char *)&nummacros )
    _Error(this: (ISceneTokenProcessor *)&stru_447574, a2: scriptline);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00416E70
// Name: void DefineVariable(char __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DefineVariable(char *variablename)
{
  char *v1; // eax
  char *v2; // eax
  char *v3; // ecx
  char v4; // dl
  variable_t v; // [esp+8h] [ebp-8h] BYREF

  if ( variablename != nullptr
    && (v1 = (char *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: strlen(variablename) + 1)) != nullptr )
  {
    strcpy(v1, variablename);
  }
  else
  {
    v1 = nullptr;
  }
  v.param = v1;
  GetToken(crossline: 0);
  v2 = (char *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: strlen(token) + 1);
  if ( v2 != nullptr )
  {
    v3 = v2;
    do
    {
      v4 = v3[token - v2];
      *v3++ = v4;
    }
    while ( v4 != 0 );
  }
  else
  {
    v2 = nullptr;
  }
  v.value = v2;
  CUtlVector<variable_t,CUtlMemory<variable_t,int>>::InsertBefore(
    this: &g_definevariable,
    elem: g_definevariable.m_Size,
    src: &v);
}

//------------------------------------------------------------------------------
// Address: 0x00416F30
// Name: int GetToken(int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl GetToken(int crossline)
{
  script_t *v1; // eax
  char *script_p; // ecx
  char v3; // dl
  script_t *v4; // eax
  char *v5; // ecx
  char *v6; // edx
  char v7; // cl
  char *v8; // ecx
  char v9; // dl
  script_t *v10; // eax
  char *v11; // edx
  script_t *v12; // eax
  char *line; // edx
  char v14; // cl
  char *v15; // esi
  script_t *v16; // eax
  char i; // cl
  char *v18; // esi
  char *v19; // ecx
  char *token_p; // [esp+Ch] [ebp-4h] BYREF

  if ( tokenready != 0 )
  {
LABEL_54:
    tokenready = 0;
    return 1;
  }
  else
  {
    while ( 1 )
    {
      v1 = script;
      if ( script->script_p >= script->end_p )
        return EndOfScript(crossline);
      tokenready = 0;
      while ( 1 )
      {
        while ( 1 )
        {
          if ( *v1->script_p <= 32 )
          {
            do
            {
              script_p = v1->script_p;
              if ( script_p >= v1->end_p )
                return EndOfScript(crossline);
              v3 = *script_p;
              v1->script_p = script_p + 1;
              if ( v3 == 10 )
              {
                if ( crossline == 0 )
                  _Error(this: (ISceneTokenProcessor *)&stru_4475D8, a2: scriptline);
                v4 = script;
                ++script->line;
                scriptline = (char *)v4->line;
              }
              v1 = script;
            }
            while ( *script->script_p <= 32 );
          }
          v5 = v1->script_p;
          if ( v5 >= v1->end_p )
            return EndOfScript(crossline);
          v6 = v1->script_p;
          v7 = *v5;
          if ( v7 != 59 && v7 != 35 )
          {
            if ( v7 != 47 )
              goto LABEL_30;
            if ( v6[1] != 47 )
              break;
          }
          if ( crossline == 0 )
          {
            _Error(this: (ISceneTokenProcessor *)&stru_4475D8, a2: scriptline);
            v1 = script;
          }
          if ( *v1->script_p != 10 )
          {
            do
            {
              ++v1->script_p;
              v1 = script;
              v11 = script->script_p;
              if ( v11 >= script->end_p )
                return EndOfScript(crossline);
            }
            while ( *v11 != 10 );
          }
          ++v1->script_p;
          v12 = script;
          ++script->line;
          line = (char *)v12->line;
          v1 = script;
          scriptline = line;
        }
        if ( v6[1] != 42 )
          break;
        v1->script_p += 2;
        while ( 1 )
        {
          v8 = script->script_p;
          if ( *v8 == 42 && v8[1] == 47 )
            break;
          v9 = *v8;
          script->script_p = v8 + 1;
          if ( v9 != 10 )
          {
            v10 = script;
            if ( script->script_p >= script->end_p )
              return EndOfScript(crossline);
            ++script->line;
            scriptline = (char *)v10->line;
          }
        }
        script->script_p += 2;
        v1 = script;
      }
LABEL_30:
      v14 = *v6;
      v15 = token;
      token_p = token;
      if ( v14 == 34 )
      {
        ++v1->script_p;
        v16 = script;
        for ( i = *script->script_p; i != 34; i = *v16->script_p )
        {
          *v15 = i;
          ++script->script_p;
          v16 = script;
          ++v15;
          if ( script->script_p == script->end_p )
            break;
          if ( v15 == (char *)&nummacros )
          {
            _Error(this: (ISceneTokenProcessor *)&stru_447574, a2: scriptline);
            v16 = script;
          }
        }
        ++v16->script_p;
      }
      else
      {
        for ( ; v14 > 32; v14 = *script->script_p )
        {
          if ( v14 == 59 )
            break;
          if ( ExpandMacroToken(a1: (const char *)1, &token_p) != 0
            || ExpandVariableToken(a1: (const char *)1, &token_p) != 0 )
          {
            v15 = token_p;
          }
          else
          {
            v18 = token_p;
            *token_p = *script->script_p++;
            v19 = script->script_p;
            v15 = v18 + 1;
            token_p = v15;
            if ( v19 == script->end_p )
              break;
            if ( v15 == (char *)&nummacros )
              _Error(this: (ISceneTokenProcessor *)&stru_447574, a2: scriptline);
          }
        }
      }
      *v15 = 0;
      if ( _V_stricmp(s1: token, s2: "$include") != 0 )
      {
        if ( _V_stricmp(s1: token, s2: "$definemacro") != 0 )
        {
          if ( _V_stricmp(s1: token, s2: "$definevariable") != 0 )
          {
            if ( AddMacroToStack(a1: (const char *)_Error, macroname: token) == 0 )
              return 1;
          }
          else
          {
            GetToken(crossline: 0);
            DefineVariable(variablename: token);
          }
        }
        else
        {
          GetToken(crossline: 0);
          DefineMacro(macroname: token);
        }
      }
      else
      {
        GetToken(crossline: 0);
        AddScriptToStack(a1: 1, filename: token, pathMode: SCRIPT_USE_ABSOLUTE_PATH);
      }
      if ( tokenready != 0 )
        goto LABEL_54;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00417520
// Name: private: int CScriptLib::GetFileList(char const __near *,char const __near *,class CUtlVector<struct fileList_t,class CUtlMemory<struct fileList_t,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CScriptLib::GetFileList(
        CScriptLib *this,
        const char *pDirPath,
        const char *pPattern,
        CUtlVector<CEventRelativeTag,CUtlMemory<CEventRelativeTag,int> > *fileList)
{
  unsigned int v5; // kr00_4
  int v6; // eax
  char v7; // cl
  char *v8; // edi
  char v9; // al
  unsigned int v10; // eax
  char *v11; // edi
  char v12; // cl
  int v13; // esi
  int v15; // eax
  char v16; // cl
  unsigned int v17; // eax
  char *v18; // edi
  char v19; // cl
  char *v20; // edi
  char *v21; // esi
  char v22; // cl
  int m_Size; // eax
  int v24; // esi
  char v25; // [esp+Bh] [ebp-435h] BYREF
  char fileName[260]; // [esp+Ch] [ebp-434h] BYREF
  char fullPath[260]; // [esp+110h] [ebp-330h] BYREF
  _finddata64i32_t findData; // [esp+214h] [ebp-22Ch] BYREF
  char sourcePath[260]; // [esp+33Ch] [ebp-104h] BYREF
  int h; // [esp+448h] [ebp+8h]
  char bFindDirs_3; // [esp+453h] [ebp+13h]

  CUtlVector<CEventRelativeTag,CUtlMemory<CEventRelativeTag,int>>::RemoveAll(this: fileList);
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
  v5 = strlen(sourcePath);
  if ( v5 != 0 )
  {
    if ( findData.name[v5 + 259] != 92 )
    {
      sourcePath[v5] = 92;
      sourcePath[v5 + 1] = 0;
    }
  }
  else
  {
    strcpy(sourcePath, ".\\");
  }
  v6 = 0;
  do
  {
    v7 = sourcePath[v6];
    fullPath[v6++] = v7;
  }
  while ( v7 != 0 );
  if ( *pPattern != 92 || pPattern[1] != 0 )
  {
    bFindDirs_3 = 0;
    v10 = strlen(pPattern) + 1;
    v11 = &fileName[259];
    do
      v12 = *++v11;
    while ( v12 != 0 );
    qmemcpy(v11, pPattern, v10);
  }
  else
  {
    bFindDirs_3 = 1;
    v8 = &fileName[259];
    do
      v9 = *++v8;
    while ( v9 != 0 );
    strcpy(v8, "*");
  }
  v13 = _findfirst64i32(szWild: fullPath, pfd: &findData);
  h = v13;
  if ( v13 == -1 )
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
      v15 = 0;
      do
      {
        v16 = sourcePath[v15];
        fileName[v15++] = v16;
      }
      while ( v16 != 0 );
      v17 = strlen(findData.name) + 1;
      v18 = &v25;
      do
        v19 = *++v18;
      while ( v19 != 0 );
      qmemcpy(v18, findData.name, 4 * (v17 >> 2));
      v21 = &findData.name[4 * (v17 >> 2)];
      v20 = &v18[4 * (v17 >> 2)];
      v22 = v17;
      m_Size = fileList->m_Size;
      qmemcpy(v20, v21, v22 & 3);
      v24 = CUtlVector<fileList_t,CUtlMemory<fileList_t,int>>::InsertBefore(
              this: (CUtlVector<fileList_t,CUtlMemory<fileList_t,int> > *)fileList,
              elem: m_Size);
      CUtlString::Set(this: &fileList->m_Memory.m_pMemory[v24].m_Name, pValue: fileName);
      *(_QWORD *)&fileList->m_Memory.m_pMemory[v24].m_flPercentage = findData.time_write;
      v13 = h;
    }
  }
  while ( _findnext64i32(hFile: v13, pfd: &findData) == 0 );
  _findclose(hFile: v13);
  return fileList->m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x004177E0
// Name: public: virtual void CScriptLib::DeleteTemporaryFiles(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CScriptLib::DeleteTemporaryFiles(CScriptLib *this, const char *pFileMask)
{
  char *v2; // eax
  char *v3; // edx
  char v4; // cl
  unsigned int v5; // eax
  char *v6; // edi
  char v7; // cl
  int (__thiscall *FindFiles)(struct CScriptLib *, char *, bool, CUtlVector<fileList_t,CUtlMemory<fileList_t,int> > *); // edx
  int v9; // esi
  int v10; // edi
  const char *v11; // eax
  fileList_t *m_pMemory; // eax
  char v13; // [esp+3h] [ebp-11Dh] BYREF
  char tempPath[260]; // [esp+4h] [ebp-11Ch] BYREF
  CScriptLib *v15; // [esp+108h] [ebp-18h]
  CUtlVector<fileList_t,CUtlMemory<fileList_t,int> > fileList; // [esp+10Ch] [ebp-14h] BYREF

  v15 = this;
  v2 = getenv(option: "temp");
  if ( v2 != nullptr || (v2 = getenv(option: "tmp")) != nullptr )
  {
    v3 = (char *)(tempPath - v2);
    do
    {
      v4 = *v2;
      v2[(_DWORD)v3] = *v2;
      ++v2;
    }
    while ( v4 != 0 );
    V_AppendSlash(pStr: tempPath, strSize: 260);
    v5 = strlen(pFileMask) + 1;
    v6 = &v13;
    do
      v7 = *++v6;
    while ( v7 != 0 );
    qmemcpy(v6, pFileMask, v5);
    FindFiles = v15->FindFiles;
    memset(&fileList, 0, sizeof(fileList));
    FindFiles(this: v15, a2: tempPath, a3: false, a4: &fileList);
    v9 = 0;
    if ( fileList.m_Size > 0 )
    {
      v10 = 0;
      do
      {
        v11 = CUtlString::operator char const *(this: &fileList.m_Memory.m_pMemory[v10].fileName);
        _unlink(path: v11);
        ++v9;
        ++v10;
      }
      while ( v9 < fileList.m_Size );
    }
    CUtlVector<CEventRelativeTag,CUtlMemory<CEventRelativeTag,int>>::RemoveAll(this: (CUtlVector<CEventRelativeTag,CUtlMemory<CEventRelativeTag,int> > *)&fileList);
    m_pMemory = fileList.m_Memory.m_pMemory;
    if ( fileList.m_Memory.m_nGrowSize >= 0 )
    {
      if ( fileList.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: fileList.m_Memory.m_pMemory);
        m_pMemory = nullptr;
        fileList.m_Memory.m_pMemory = nullptr;
      }
      fileList.m_Memory.m_nAllocationCount = 0;
    }
    fileList.m_pElements = m_pMemory;
    if ( fileList.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00417910
// Name: private: void CScriptLib::RecurseFileTree_r(char const __near *,int,class CUtlVector<class CUtlString,class CUtlMemory<class CUtlString,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CScriptLib::RecurseFileTree_r(
        CScriptLib *this,
        const char *pDirPath,
        int depth,
        CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *dirList)
{
  fileList_t *i; // ebx
  int v5; // eax
  int v6; // eax
  fileList_t *m_pMemory; // edi
  const char *v8; // eax
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CUtlString *v11; // ecx
  int v12; // eax
  int v13; // edi
  CUtlString *v14; // ecx
  CUtlVector<fileList_t,CUtlMemory<fileList_t,int> > fileList; // [esp+Ch] [ebp-18h] BYREF
  CScriptLib *v16; // [esp+20h] [ebp-4h]

  i = nullptr;
  v16 = this;
  memset(&fileList, 0, sizeof(fileList));
  v5 = CScriptLib::GetFileList(
         this,
         pDirPath,
         pPattern: "\\",
         (CUtlVector<CEventRelativeTag,CUtlMemory<CEventRelativeTag,int> > *)&fileList);
  if ( v5 != 0 )
  {
    if ( v5 > 0 )
    {
      m_pMemory = fileList.m_Memory.m_pMemory;
      for ( i = (fileList_t *)v5; i != nullptr; i = (fileList_t *)((char *)i - 1) )
      {
        v8 = CUtlString::operator char const *(this: &m_pMemory->fileName);
        CScriptLib::RecurseFileTree_r(this: v16, pDirPath: v8, depth: depth + 1, dirList);
        ++m_pMemory;
      }
    }
    m_Size = dirList->m_Size;
    m_nAllocationCount = dirList->m_Memory.m_nAllocationCount;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<OrderedCaption_t,int>::Grow(
        this: (CUtlMemory<OrderedCaption_t,int> *)dirList,
        num: m_Size - m_nAllocationCount + 1);
    ++dirList->m_Size;
    v11 = dirList->m_Memory.m_pMemory;
    v12 = dirList->m_Size - m_Size - 1;
    dirList->m_pElements = dirList->m_Memory.m_pMemory;
    if ( v12 > (int)i )
      _V_memmove(dest: &v11[m_Size + 1], src: &v11[m_Size], count: 16 * v12);
    v13 = m_Size;
    v14 = &dirList->m_Memory.m_pMemory[v13];
    if ( v14 != nullptr )
      CUtlString::CUtlString(this: v14);
    CUtlString::Set(this: &dirList->m_Memory.m_pMemory[v13], pValue: pDirPath);
    CUtlVector<CEventRelativeTag,CUtlMemory<CEventRelativeTag,int>>::RemoveAll(this: (CUtlVector<CEventRelativeTag,CUtlMemory<CEventRelativeTag,int> > *)&fileList);
    if ( fileList.m_Memory.m_nGrowSize >= (int)i && fileList.m_Memory.m_pMemory != i )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: fileList.m_Memory.m_pMemory);
  }
  else
  {
    v6 = CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>::InsertBefore(this: dirList, elem: dirList->m_Size);
    CUtlString::Set(this: &dirList->m_Memory.m_pMemory[v6], pValue: pDirPath);
    CUtlVector<CEventRelativeTag,CUtlMemory<CEventRelativeTag,int>>::~CUtlVector<CEventRelativeTag,CUtlMemory<CEventRelativeTag,int>>(this: (CUtlVector<CEventRelativeTag,CUtlMemory<CEventRelativeTag,int> > *)&fileList);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00417A30
// Name: public: virtual int CScriptLib::FindFiles(char __near *,bool,class CUtlVector<struct fileList_t,class CUtlMemory<struct fileList_t,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CScriptLib::FindFiles(
        CScriptLib *this,
        char *pFileMask,
        bool bRecurse,
        CUtlVector<fileList_t,CUtlMemory<fileList_t,int> > *fileList)
{
  CScriptLib *v4; // edi
  char *v5; // edi
  char v6; // al
  unsigned int v7; // eax
  char *v8; // edi
  char v9; // cl
  int m_nGrowSize; // esi
  fileList_t *m_pMemory; // eax
  const char *v13; // eax
  CUtlVector<fileList_t,CUtlMemory<fileList_t,int> > *v14; // esi
  int m_Size; // edi
  int inserted; // eax
  fileList_t *v17; // edi
  int v18; // ebx
  CUtlString *p_fileName; // esi
  int timeWrite_high; // eax
  bool v21; // zf
  CUtlString *v22; // eax
  unsigned int v23; // [esp-8h] [ebp-34Ch]
  char extension[260]; // [esp+8h] [ebp-33Ch] BYREF
  char dirPath[260]; // [esp+10Ch] [ebp-238h] BYREF
  char pattern[260]; // [esp+210h] [ebp-134h] BYREF
  CScriptLib *v27; // [esp+314h] [ebp-30h]
  int i; // [esp+318h] [ebp-2Ch]
  CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > dirList; // [esp+31Ch] [ebp-28h] BYREF
  CUtlVector<fileList_t,CUtlMemory<fileList_t,int> > tempList; // [esp+330h] [ebp-14h] BYREF
  char *pFileMaska; // [esp+34Ch] [ebp+8h]
  int bRecursea; // [esp+350h] [ebp+Ch]

  v4 = this;
  v27 = this;
  strcpy(dirPath, pFileMask);
  V_StripFilename(path: dirPath);
  V_FileBase(in: pFileMask, out: pattern, maxlen: 260);
  V_ExtractFileExtension(path: pFileMask, dest: extension, destSize: 260);
  if ( extension[0] != 0 )
  {
    v5 = &dirPath[259];
    do
      v6 = *++v5;
    while ( v6 != 0 );
    strcpy(v5, ".");
    v7 = strlen(extension) + 1;
    v8 = &dirPath[259];
    do
      v9 = *++v8;
    while ( v9 != 0 );
    qmemcpy(v8, extension, v7);
    v4 = v27;
  }
  if ( bRecurse )
  {
    memset(&tempList, 0, sizeof(tempList));
    memset(&dirList, 0, sizeof(dirList));
    CScriptLib::RecurseFileTree_r(this: v4, pDirPath: dirPath, depth: 0, &dirList);
    i = 0;
    if ( dirList.m_Size > 0 )
    {
      bRecursea = 0;
      while ( 1 )
      {
        CUtlVector<CEventRelativeTag,CUtlMemory<CEventRelativeTag,int>>::RemoveAll(this: (CUtlVector<CEventRelativeTag,CUtlMemory<CEventRelativeTag,int> > *)&tempList);
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
          v23 = 24 * dirList.m_Size;
          if ( m_pMemory != nullptr )
            m_pMemory = (fileList_t *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v23);
          else
            m_pMemory = (fileList_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v23);
          tempList.m_Memory.m_pMemory = m_pMemory;
        }
        tempList.m_pElements = m_pMemory;
        v13 = CUtlString::operator char const *(this: &dirList.m_Memory.m_pMemory[bRecursea]);
        CScriptLib::GetFileList(
          this: v4,
          pDirPath: v13,
          pPattern: pattern,
          fileList: (CUtlVector<CEventRelativeTag,CUtlMemory<CEventRelativeTag,int> > *)&tempList);
        v14 = fileList;
        m_Size = tempList.m_Size;
        inserted = CUtlVector<fileList_t,CUtlMemory<fileList_t,int>>::InsertMultipleBefore(
                     this: fileList,
                     elem: fileList->m_Size,
                     num: tempList.m_Size);
        if ( m_Size > 0 )
        {
          v17 = tempList.m_Memory.m_pMemory;
          v18 = inserted;
          pFileMaska = (char *)tempList.m_Size;
          while ( 1 )
          {
            p_fileName = &v14->m_Memory.m_pMemory[v18].fileName;
            CUtlString::operator=(this: p_fileName, src: &v17->fileName);
            p_fileName[1].m_Storage.m_Memory.m_pMemory = (unsigned __int8 *)v17->timeWrite;
            timeWrite_high = HIDWORD(v17->timeWrite);
            ++v17;
            ++v18;
            v21 = pFileMaska-- == (char *)1;
            p_fileName[1].m_Storage.m_Memory.m_nAllocationCount = timeWrite_high;
            if ( v21 )
              break;
            v14 = fileList;
          }
        }
        ++bRecursea;
        if ( ++i >= dirList.m_Size )
          break;
        v4 = v27;
      }
    }
    CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>::RemoveAll(this: &dirList);
    v22 = dirList.m_Memory.m_pMemory;
    if ( dirList.m_Memory.m_nGrowSize >= 0 )
    {
      if ( dirList.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: dirList.m_Memory.m_pMemory);
        v22 = nullptr;
        dirList.m_Memory.m_pMemory = nullptr;
      }
      dirList.m_Memory.m_nAllocationCount = 0;
    }
    dirList.m_pElements = v22;
    if ( dirList.m_Memory.m_nGrowSize >= 0 )
    {
      if ( v22 != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v22);
        dirList.m_Memory.m_pMemory = nullptr;
      }
      dirList.m_Memory.m_nAllocationCount = 0;
    }
    CUtlVector<CEventRelativeTag,CUtlMemory<CEventRelativeTag,int>>::RemoveAll(this: (CUtlVector<CEventRelativeTag,CUtlMemory<CEventRelativeTag,int> > *)&tempList);
    if ( tempList.m_Memory.m_nGrowSize < 0 )
    {
      return fileList->m_Size;
    }
    else
    {
      if ( tempList.m_Memory.m_pMemory != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: tempList.m_Memory.m_pMemory);
      return fileList->m_Size;
    }
  }
  else
  {
    CScriptLib::GetFileList(
      this: v4,
      pDirPath: dirPath,
      pPattern: pattern,
      (CUtlVector<CEventRelativeTag,CUtlMemory<CEventRelativeTag,int> > *)fileList);
    return fileList->m_Size;
  }
}

} // namespace localization_check

// ============================================================
// Overlay from makegamedata (Missing functions)
// ============================================================
namespace makegamedata {

//------------------------------------------------------------------------------
// Address: 0x0041E820
// Name: void AddScriptToStack(char __near *,enum ScriptPathMode_t)
// Source: json
//------------------------------------------------------------------------------
void __usercall AddScriptToStack(int a1@<edi>, char *filename, ScriptPathMode_t pathMode)
{
  int File; // esi
  const char *v4; // [esp-8h] [ebp-8h]
  const char *savedregs; // [esp+0h] [ebp+0h]

  if ( ++script == (script_t *)token )
    _Error(this: (ISceneTokenProcessor *)&stru_590C78, a2: savedregs);
  if ( pathMode == SCRIPT_USE_RELATIVE_PATH )
  {
    V_strncpy(pDest: script->filename, pSrc: filename, maxLen: 1024);
  }
  else
  {
    v4 = ExpandPath(path: filename);
    V_strncpy(pDest: script->filename, pSrc: v4, maxLen: 1024);
  }
  File = LoadFile(a1, filename: script->filename, bufferptr: (void **)&script->buffer);
  if ( g_pfnCallback != nullptr )
    ((void (__thiscall *)(CBaseAppSystem<IDmSerializers> *))g_pfnCallback)(this: g_pfnCallback);
  script->line = 1;
  script->script_p = script->buffer;
  script->end_p = &script->buffer[File];
}

//------------------------------------------------------------------------------
// Address: 0x0041E900
// Name: bool AddMacroToStack(char __near *)
// Source: json
//------------------------------------------------------------------------------
char __usercall AddMacroToStack@<al>(const char *a1@<ebx>, char *macroname)
{
  int v3; // esi
  bool v4; // zf
  script_t *v5; // edi
  script_t *v6; // ebx
  int nummacroparams; // eax
  char *macrobuffer; // esi
  char **macroparam; // edi
  unsigned int v10; // esi
  const char *v11; // [esp-Ch] [ebp-14h]
  script_t *pmacro; // [esp+4h] [ebp-4h]
  int i; // [esp+10h] [ebp+8h]

  if ( *macroname != 36 )
    return 0;
  v3 = 0;
  v4 = nummacros == 0;
  if ( nummacros > 0 )
  {
    do
    {
      if ( _V_stricmp(s1: macrolist[v3]->filename, s2: macroname + 1) == 0 )
        break;
      ++v3;
    }
    while ( v3 < nummacros );
    v4 = v3 == nummacros;
  }
  if ( v4 )
    return 0;
  v5 = macrolist[v3];
  v11 = a1;
  v6 = script + 2;
  pmacro = v5;
  if ( &script[2] == (script_t *)token )
    _Error(this: (ISceneTokenProcessor *)&stru_590C78, a2: v11);
  nummacroparams = v5->nummacroparams;
  macrobuffer = v6->macrobuffer;
  v6->nummacroparams = nummacroparams;
  i = 0;
  if ( nummacroparams > 0 )
  {
    macroparam = v6->macroparam;
    do
    {
      GetToken(crossline: 0);
      strcpy(macrobuffer, token);
      *macroparam = *(char **)((char *)macroparam + (char *)pmacro - (char *)v6);
      macroparam[64] = macrobuffer;
      macrobuffer += strlen(token) + 1;
      if ( macrobuffer >= (char *)v6->macroparam )
        _Error(this: (ISceneTokenProcessor *)&stru_590C9C, a2: v11);
      ++macroparam;
      ++i;
    }
    while ( i < v6->nummacroparams );
    v5 = pmacro;
  }
  script = (script_t *)strcpy(v6->filename, v5->filename);
  v10 = v5->end_p - v5->buffer;
  script->buffer = (char *)MemAlloc_Alloc(nSize: v10 + 1);
  memcpy(dst: (unsigned __int8 *)script->buffer, src: (unsigned __int8 *)v5->buffer, count: v10);
  v5->buffer[v10] = 0;
  script->script_p = script->buffer;
  script->end_p = &script->buffer[v10];
  script->line = v5->line;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0041EAC0
// Name: bool ExpandMacroToken(char __near * __near &)
// Source: json
//------------------------------------------------------------------------------
char __usercall ExpandMacroToken@<al>(const char *a1@<edi>, char **token_p)
{
  char *script_p; // eax
  _BYTE *v3; // ebx
  char v4; // al
  script_t *v6; // eax
  int v7; // esi
  int v8; // edi
  bool v9; // zf
  const char *v10; // edx
  unsigned int v11; // eax
  _BYTE *v12; // esi
  char v13; // cl
  char *s2; // [esp+0h] [ebp-4h]

  if ( script->nummacroparams == 0 )
    return 0;
  script_p = script->script_p;
  if ( *script_p != 36 )
    return 0;
  v3 = script_p + 1;
  s2 = script_p + 1;
  v4 = script_p[1];
  if ( v4 <= 32 )
  {
LABEL_6:
    if ( *v3 != 36 )
      return 0;
  }
  else
  {
    while ( v4 != 36 )
    {
      v4 = *++v3;
      if ( v4 <= 32 )
        goto LABEL_6;
    }
  }
  *v3 = 0;
  v6 = script;
  v7 = 0;
  if ( script->nummacroparams <= 0 )
    goto LABEL_13;
  v8 = 5136;
  do
  {
    v9 = _V_stricmp(s1: *(const char **)&v6->filename[v8], s2) == 0;
    v6 = script;
    if ( v9 )
      break;
    ++v7;
    v8 += 4;
  }
  while ( v7 < script->nummacroparams );
  if ( v7 >= script->nummacroparams )
  {
LABEL_13:
    _Error(this: (ISceneTokenProcessor *)&stru_590CE8, a2: s2, v6);
    v6 = script;
  }
  v10 = v6->macrovalue[v7];
  v11 = strlen(v10);
  v12 = *token_p;
  do
  {
    v13 = *v10;
    *v12++ = *v10++;
  }
  while ( v13 != 0 );
  *token_p += v11;
  script->script_p = v3 + 1;
  if ( script->script_p >= script->end_p )
    _Error(this: (ISceneTokenProcessor *)&stru_590CD0, a2: a1);
  if ( *token_p >= (char *)&nummacros )
    _Error(this: (ISceneTokenProcessor *)&stru_590CB4, a2: scriptline);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0041EBF0
// Name: void ParseFromMemory(char __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ParseFromMemory(char *buffer, int size)
{
  scriptstack[1].buffer = buffer;
  scriptstack[1].script_p = buffer;
  script = &scriptstack[1];
  scriptstack[1].end_p = &buffer[size];
  strcpy(scriptstack[1].filename, "memory buffer");
  scriptstack[1].line = 1;
  endofscript = 0;
  tokenready = 0;
}

//------------------------------------------------------------------------------
// Address: 0x0041EC60
// Name: int EndOfScript(int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl EndOfScript(int crossline)
{
  if ( crossline == 0 )
    _Error(this: (ISceneTokenProcessor *)&stru_590D18, a2: scriptline);
  if ( strcmp(script->filename, aMemoryB) == 0
    || (free(pMem: script->buffer), script->buffer = nullptr, script == &scriptstack[1]) )
  {
    endofscript = 1;
    return 0;
  }
  else
  {
    --script;
    scriptline = (char *)script->line;
    return GetToken(crossline);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041ED20
// Name: int TokenAvailable(void)
// Source: json
//------------------------------------------------------------------------------
int __cdecl TokenAvailable()
{
  char *script_p; // eax
  char *end_p; // edx
  char v3; // cl
  char v4; // cl

  if ( tokenready != 0 )
    return 1;
  script_p = script->script_p;
  end_p = script->end_p;
  if ( script_p < end_p )
  {
    v3 = *script_p;
    if ( *script_p > 32 )
    {
LABEL_8:
      v4 = *script_p;
      if ( *script_p != 59 && v4 != 35 && (v4 != 47 || script_p[1] != 47) )
        return 1;
    }
    else
    {
      while ( v3 != 10 )
      {
        if ( ++script_p == end_p )
          break;
        v3 = *script_p;
        if ( *script_p > 32 )
          goto LABEL_8;
      }
    }
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x0041ED80
// Name: public: virtual bool CScriptLib::DoesFileExist(char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CScriptLib::DoesFileExist(CScriptLib *this, const char *pFilename)
{
  return g_pFullFileSystem->FileExists(this: &g_pFullFileSystem->IBaseFileSystem, a2: pFilename, a3: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x0041EDA0
// Name: public: virtual bool CScriptLib::ReadFileToBuffer(char const __near *,class CUtlBuffer __near &,bool,bool)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CScriptLib::ReadFileToBuffer(
        CScriptLib *this,
        const char *pSourceName,
        CUtlBuffer *buffer,
        bool bText,
        bool bNoOpenFailureWarning)
{
  int *v5; // eax
  const char *v6; // eax

  if ( g_pFullFileSystem->ReadFile(
         this: &g_pFullFileSystem->IBaseFileSystem,
         a2: pSourceName,
         a3: nullptr,
         a4: buffer,
         a5: 0,
         a6: 0,
         a7: nullptr) )
  {
    if ( bText )
      CUtlBuffer::SetBufferType(this: buffer, bIsText: true, bContainsCRLF: true);
    else
      CUtlBuffer::SetBufferType(this: buffer, bIsText: false, bContainsCRLF: false);
    return 1;
  }
  else
  {
    if ( !bNoOpenFailureWarning )
    {
      v5 = _errno();
      v6 = strerror(errnum: *v5);
      _Msg(a1: "ReadFileToBuffer(): Error opening %s: %s\n", pSourceName, v6);
    }
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041EE20
// Name: public: virtual bool CScriptLib::WriteBufferToFile(char const __near *,class CUtlBuffer __near &,enum DiskWriteMode_t)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CScriptLib::WriteBufferToFile(
        CScriptLib *this,
        const char *pTargetName,
        CUtlBuffer *buffer,
        DiskWriteMode_t writeMode)
{
  _BYTE *v5; // eax
  _BYTE *v6; // esi
  _BYTE *v7; // eax
  char dirPath[260]; // [esp+8h] [ebp-104h] BYREF

  strcpy(dirPath, pTargetName);
  strchr(string: (unsigned __int8 *)dirPath, chr: 0x5Cu);
  v6 = v5;
  if ( v5 != nullptr )
  {
    while ( 1 )
    {
      strchr(string: v6 + 1, chr: 0x5Cu);
      v6 = v7;
      if ( v7 == nullptr )
        break;
      *v7 = 0;
      mkdir(path: dirPath);
      *v6 = 92;
    }
  }
  return writeMode != WRITE_TO_DISK_ALWAYS
      && (writeMode != WRITE_TO_DISK_UPDATE || !this->DoesFileExist(this, a2: pTargetName))
      || g_pFullFileSystem->WriteFile(
           this: &g_pFullFileSystem->IBaseFileSystem,
           a2: pTargetName,
           a3: nullptr,
           a4: buffer);
}

//------------------------------------------------------------------------------
// Address: 0x0041EEE0
// Name: public: virtual int CScriptLib::CompareFileTime(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CScriptLib::CompareFileTime(CScriptLib *this, const char *pFilenameA, const char *pFilenameB)
{
  unsigned int v3; // esi
  unsigned int v4; // eax
  bool v5; // cf

  v3 = g_pFullFileSystem->GetFileTime(this: &g_pFullFileSystem->IBaseFileSystem, a2: pFilenameA, a3: nullptr);
  v4 = g_pFullFileSystem->GetFileTime(this: &g_pFullFileSystem->IBaseFileSystem, a2: pFilenameB, a3: nullptr);
  if ( v3 == -1 )
    v3 = 0;
  if ( v4 == -1 )
    return v3 != 0;
  v5 = v4 < v3;
  if ( v4 <= v3 )
    return v5;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0041EF40
// Name: public: virtual char __near * CScriptLib::MakeTemporaryFilename(char const __near *,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CScriptLib::MakeTemporaryFilename(CScriptLib *this, const char *pchModPath, char *pPath, int pathSize)
{
  char *v4; // eax
  char *v5; // esi

  v4 = _tempnam(dir: pchModPath, pfx: "mgd_");
  v5 = v4;
  if ( *v4 == 92 )
    v5 = v4 + 1;
  if ( v5[strlen(v5) - 1] == 46 )
    v5[strlen(v5) - 1] = 0;
  V_snprintf(pDest: pPath, maxLen: pathSize, pFormat: "%s.tmp", v5);
  free(pMem: v5);
  return pPath;
}

//------------------------------------------------------------------------------
// Address: 0x0041EFB0
// Name: void DefineMacro(char __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DefineMacro(char *macroname)
{
  script_t *v1; // edi
  char *script_p; // esi
  char *macrobuffer; // ebx
  unsigned int v4; // ebx
  unsigned __int8 *v5; // eax
  int v6; // eax
  script_t *v7; // edx
  const char *v8; // [esp+0h] [ebp-Ch]

  v1 = (script_t *)MemAlloc_Alloc(nSize: 0x1614u);
  strcpy(v1->filename, macroname);
  v1->line = script->line;
  v1->nummacroparams = 0;
  script_p = script->script_p;
  macrobuffer = v1->macrobuffer;
  while ( TokenAvailable() != 0 )
  {
    GetToken(crossline: 0);
    if ( token[0] == 92 && byte_685F01 == 92 )
      break;
    script_p = script->script_p;
    v1->macroparam[v1->nummacroparams++] = macrobuffer;
    strcpy(macrobuffer, token);
    macrobuffer += strlen(token) + 1;
    if ( macrobuffer >= (char *)v1->macroparam )
      _Error(this: (ISceneTokenProcessor *)&stru_590C9C, a2: v8);
  }
  for ( script->script_p = script_p; *script_p != 0; ++script_p )
  {
    if ( *script_p == 10 )
      break;
    if ( *script_p == 92 && script_p[1] == 92 )
    {
      do
      {
        if ( *script_p == 10 )
          break;
        *script_p++ = 32;
      }
      while ( *script_p != 0 );
      if ( *script_p == 0 )
        break;
    }
  }
  v4 = script_p - script->script_p;
  v5 = (unsigned __int8 *)MemAlloc_Alloc(nSize: v4 + 1);
  v1->buffer = (char *)v5;
  memcpy(dst: v5, src: (unsigned __int8 *)script->script_p, count: v4);
  v1->buffer[v4] = 0;
  v1->end_p = &v1->buffer[v4];
  v6 = nummacros;
  v7 = script;
  macrolist[nummacros] = v1;
  nummacros = v6 + 1;
  v7->script_p = script_p;
}

//------------------------------------------------------------------------------
// Address: 0x0041F150
// Name: bool ExpandVariableToken(char __near * __near &)
// Source: json
//------------------------------------------------------------------------------
char __usercall ExpandVariableToken@<al>(const char *a1@<edi>, char **token_p)
{
  char *script_p; // ebx
  const char *v3; // ebx
  char *v4; // esi
  char v5; // al
  int v7; // esi
  int v8; // edi
  void (*v9)(ISceneTokenProcessor *, const char *, ...); // ebx
  char *value; // edi
  unsigned int v11; // eax
  char *v12; // edx
  _BYTE *v13; // esi
  char v14; // cl
  const char *v15; // [esp-10h] [ebp-18h]
  char *cp; // [esp+4h] [ebp-4h]

  script_p = script->script_p;
  if ( *script_p != 36 )
    return 0;
  v3 = script_p + 1;
  v4 = (char *)v3;
  v5 = *v3;
  cp = (char *)v3;
  if ( *v3 <= 32 )
  {
LABEL_6:
    if ( *v4 != 36 )
      return 0;
  }
  else
  {
    while ( v5 != 36 )
    {
      v5 = *++v4;
      if ( v5 <= 32 )
      {
        cp = v4;
        goto LABEL_6;
      }
    }
    cp = v4;
  }
  v7 = v4 - v3;
  v8 = 0;
  v3[v7] = 0;
  if ( g_definevariable.m_Size <= 0 )
    goto LABEL_14;
  while ( V_strnicmp(s1: g_definevariable.m_Memory.m_pMemory[v8].param, s2: v3, n: v7) != 0 )
  {
    if ( ++v8 >= g_definevariable.m_Size )
      goto LABEL_14;
  }
  if ( v8 < g_definevariable.m_Size )
  {
    v9 = _Error;
  }
  else
  {
LABEL_14:
    v15 = v3;
    v9 = _Error;
    _Error(this: (ISceneTokenProcessor *)&stru_590D50, a2: v15, script);
  }
  value = g_definevariable.m_Memory.m_pMemory[v8].value;
  v11 = strlen(value);
  v12 = value;
  v13 = *token_p;
  do
  {
    v14 = *v12;
    *v13++ = *v12++;
  }
  while ( v14 != 0 );
  *token_p += v11;
  script->script_p = cp + 1;
  if ( script->script_p >= script->end_p )
    v9(this: (ISceneTokenProcessor *)&stru_590CD0, a2: a1);
  if ( *token_p >= (char *)&nummacros )
    v9(this: (ISceneTokenProcessor *)&stru_590CB4, a2: scriptline);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0041F280
// Name: void DefineVariable(char __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DefineVariable(char *variablename)
{
  char *v1; // eax
  char *v2; // eax
  char *v3; // ecx
  char v4; // dl
  variable_t v; // [esp+8h] [ebp-8h] BYREF

  if ( variablename != nullptr
    && (v1 = (char *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: strlen(variablename) + 1)) != nullptr )
  {
    strcpy(v1, variablename);
  }
  else
  {
    v1 = nullptr;
  }
  v.param = v1;
  GetToken(crossline: 0);
  v2 = (char *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: strlen(token) + 1);
  if ( v2 != nullptr )
  {
    v3 = v2;
    do
    {
      v4 = v3[token - v2];
      *v3++ = v4;
    }
    while ( v4 != 0 );
  }
  else
  {
    v2 = nullptr;
  }
  v.value = v2;
  CUtlVector<variable_t,CUtlMemory<variable_t,int>>::InsertBefore(
    this: (CUtlVector<ZIP_PreloadDirectoryEntry,CUtlMemory<ZIP_PreloadDirectoryEntry,int> > *)&g_definevariable,
    elem: g_definevariable.m_Size,
    src: (const ZIP_PreloadDirectoryEntry *)&v);
}

//------------------------------------------------------------------------------
// Address: 0x0041F340
// Name: int GetToken(int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl GetToken(int crossline)
{
  script_t *v1; // eax
  char *script_p; // ecx
  char v3; // dl
  script_t *v4; // eax
  char *v5; // ecx
  char *v6; // edx
  char v7; // cl
  char *v8; // ecx
  char v9; // dl
  script_t *v10; // eax
  char *v11; // edx
  script_t *v12; // eax
  char *line; // edx
  char v14; // cl
  char *v15; // esi
  script_t *v16; // eax
  char i; // cl
  char *v18; // esi
  char *v19; // ecx
  char *token_p; // [esp+Ch] [ebp-4h] BYREF

  if ( tokenready != 0 )
  {
LABEL_54:
    tokenready = 0;
    return 1;
  }
  else
  {
    while ( 1 )
    {
      v1 = script;
      if ( script->script_p >= script->end_p )
        return EndOfScript(crossline);
      tokenready = 0;
      while ( 1 )
      {
        while ( 1 )
        {
          if ( *v1->script_p <= 32 )
          {
            do
            {
              script_p = v1->script_p;
              if ( script_p >= v1->end_p )
                return EndOfScript(crossline);
              v3 = *script_p;
              v1->script_p = script_p + 1;
              if ( v3 == 10 )
              {
                if ( crossline == 0 )
                  _Error(this: (ISceneTokenProcessor *)&stru_590D18, a2: scriptline);
                v4 = script;
                ++script->line;
                scriptline = (char *)v4->line;
              }
              v1 = script;
            }
            while ( *script->script_p <= 32 );
          }
          v5 = v1->script_p;
          if ( v5 >= v1->end_p )
            return EndOfScript(crossline);
          v6 = v1->script_p;
          v7 = *v5;
          if ( v7 != 59 && v7 != 35 )
          {
            if ( v7 != 47 )
              goto LABEL_30;
            if ( v6[1] != 47 )
              break;
          }
          if ( crossline == 0 )
          {
            _Error(this: (ISceneTokenProcessor *)&stru_590D18, a2: scriptline);
            v1 = script;
          }
          if ( *v1->script_p != 10 )
          {
            do
            {
              ++v1->script_p;
              v1 = script;
              v11 = script->script_p;
              if ( v11 >= script->end_p )
                return EndOfScript(crossline);
            }
            while ( *v11 != 10 );
          }
          ++v1->script_p;
          v12 = script;
          ++script->line;
          line = (char *)v12->line;
          v1 = script;
          scriptline = line;
        }
        if ( v6[1] != 42 )
          break;
        v1->script_p += 2;
        while ( 1 )
        {
          v8 = script->script_p;
          if ( *v8 == 42 && v8[1] == 47 )
            break;
          v9 = *v8;
          script->script_p = v8 + 1;
          if ( v9 != 10 )
          {
            v10 = script;
            if ( script->script_p >= script->end_p )
              return EndOfScript(crossline);
            ++script->line;
            scriptline = (char *)v10->line;
          }
        }
        script->script_p += 2;
        v1 = script;
      }
LABEL_30:
      v14 = *v6;
      v15 = token;
      token_p = token;
      if ( v14 == 34 )
      {
        ++v1->script_p;
        v16 = script;
        for ( i = *script->script_p; i != 34; i = *v16->script_p )
        {
          *v15 = i;
          ++script->script_p;
          v16 = script;
          ++v15;
          if ( script->script_p == script->end_p )
            break;
          if ( v15 == (char *)&nummacros )
          {
            _Error(this: (ISceneTokenProcessor *)&stru_590CB4, a2: scriptline);
            v16 = script;
          }
        }
        ++v16->script_p;
      }
      else
      {
        for ( ; v14 > 32; v14 = *script->script_p )
        {
          if ( v14 == 59 )
            break;
          if ( ExpandMacroToken(a1: (const char *)1, &token_p) != 0
            || ExpandVariableToken(a1: (const char *)1, &token_p) != 0 )
          {
            v15 = token_p;
          }
          else
          {
            v18 = token_p;
            *token_p = *script->script_p++;
            v19 = script->script_p;
            v15 = v18 + 1;
            token_p = v15;
            if ( v19 == script->end_p )
              break;
            if ( v15 == (char *)&nummacros )
              _Error(this: (ISceneTokenProcessor *)&stru_590CB4, a2: scriptline);
          }
        }
      }
      *v15 = 0;
      if ( _V_stricmp(s1: token, s2: "$include") != 0 )
      {
        if ( _V_stricmp(s1: token, s2: "$definemacro") != 0 )
        {
          if ( _V_stricmp(s1: token, s2: "$definevariable") != 0 )
          {
            if ( AddMacroToStack(a1: (const char *)_Error, macroname: token) == 0 )
              return 1;
          }
          else
          {
            GetToken(crossline: 0);
            DefineVariable(variablename: token);
          }
        }
        else
        {
          GetToken(crossline: 0);
          DefineMacro(macroname: token);
        }
      }
      else
      {
        GetToken(crossline: 0);
        AddScriptToStack(a1: 1, filename: token, pathMode: SCRIPT_USE_ABSOLUTE_PATH);
      }
      if ( tokenready != 0 )
        goto LABEL_54;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041F740
// Name: private: int CScriptLib::GetFileList(char const __near *,char const __near *,class CUtlVector<struct fileList_t,class CUtlMemory<struct fileList_t,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CScriptLib::GetFileList(
        CScriptLib *this,
        const char *pDirPath,
        const char *pPattern,
        CUtlVector<CEventRelativeTag,CUtlMemory<CEventRelativeTag,int> > *fileList)
{
  unsigned int v5; // kr00_4
  int v6; // eax
  char v7; // cl
  char *v8; // edi
  char v9; // al
  unsigned int v10; // eax
  char *v11; // edi
  char v12; // cl
  int v13; // esi
  int v15; // eax
  char v16; // cl
  unsigned int v17; // eax
  char *v18; // edi
  char v19; // cl
  char *v20; // edi
  char *v21; // esi
  char v22; // cl
  int m_Size; // eax
  int v24; // esi
  char v25; // [esp+Bh] [ebp-435h] BYREF
  char fileName[260]; // [esp+Ch] [ebp-434h] BYREF
  char fullPath[260]; // [esp+110h] [ebp-330h] BYREF
  _finddata64i32_t findData; // [esp+214h] [ebp-22Ch] BYREF
  char sourcePath[260]; // [esp+33Ch] [ebp-104h] BYREF
  int h; // [esp+448h] [ebp+8h]
  char bFindDirs_3; // [esp+453h] [ebp+13h]

  CUtlVector<CEventRelativeTag,CUtlMemory<CEventRelativeTag,int>>::RemoveAll(this: fileList);
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
  v5 = strlen(sourcePath);
  if ( v5 != 0 )
  {
    if ( findData.name[v5 + 259] != 92 )
    {
      sourcePath[v5] = 92;
      sourcePath[v5 + 1] = 0;
    }
  }
  else
  {
    strcpy(sourcePath, ".\\");
  }
  v6 = 0;
  do
  {
    v7 = sourcePath[v6];
    fullPath[v6++] = v7;
  }
  while ( v7 != 0 );
  if ( *pPattern != 92 || pPattern[1] != 0 )
  {
    bFindDirs_3 = 0;
    v10 = strlen(pPattern) + 1;
    v11 = &fileName[259];
    do
      v12 = *++v11;
    while ( v12 != 0 );
    qmemcpy(v11, pPattern, v10);
  }
  else
  {
    bFindDirs_3 = 1;
    v8 = &fileName[259];
    do
      v9 = *++v8;
    while ( v9 != 0 );
    strcpy(v8, "*");
  }
  v13 = _findfirst64i32(szWild: fullPath, pfd: &findData);
  h = v13;
  if ( v13 == -1 )
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
      v15 = 0;
      do
      {
        v16 = sourcePath[v15];
        fileName[v15++] = v16;
      }
      while ( v16 != 0 );
      v17 = strlen(findData.name) + 1;
      v18 = &v25;
      do
        v19 = *++v18;
      while ( v19 != 0 );
      qmemcpy(v18, findData.name, 4 * (v17 >> 2));
      v21 = &findData.name[4 * (v17 >> 2)];
      v20 = &v18[4 * (v17 >> 2)];
      v22 = v17;
      m_Size = fileList->m_Size;
      qmemcpy(v20, v21, v22 & 3);
      v24 = CUtlVector<fileList_t,CUtlMemory<fileList_t,int>>::InsertBefore(
              this: (CUtlVector<fileList_t,CUtlMemory<fileList_t,int> > *)fileList,
              elem: m_Size);
      CUtlString::Set(this: &fileList->m_Memory.m_pMemory[v24].m_Name, pValue: fileName);
      *(_QWORD *)&fileList->m_Memory.m_pMemory[v24].m_flPercentage = findData.time_write;
      v13 = h;
    }
  }
  while ( _findnext64i32(hFile: v13, pfd: &findData) == 0 );
  _findclose(hFile: v13);
  return fileList->m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x0041F9A0
// Name: public: virtual void CScriptLib::DeleteTemporaryFiles(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CScriptLib::DeleteTemporaryFiles(CScriptLib *this, const char *pFileMask)
{
  char *v2; // eax
  char *v3; // edx
  char v4; // cl
  unsigned int v5; // eax
  char *v6; // edi
  char v7; // cl
  int (__thiscall *FindFiles)(struct CScriptLib *, char *, bool, CUtlVector<fileList_t,CUtlMemory<fileList_t,int> > *); // edx
  int v9; // esi
  int v10; // edi
  const char *v11; // eax
  fileList_t *m_pMemory; // eax
  char v13; // [esp+3h] [ebp-11Dh] BYREF
  char tempPath[260]; // [esp+4h] [ebp-11Ch] BYREF
  CScriptLib *v15; // [esp+108h] [ebp-18h]
  CUtlVector<fileList_t,CUtlMemory<fileList_t,int> > fileList; // [esp+10Ch] [ebp-14h] BYREF

  v15 = this;
  v2 = getenv(option: "temp");
  if ( v2 != nullptr || (v2 = getenv(option: "tmp")) != nullptr )
  {
    v3 = (char *)(tempPath - v2);
    do
    {
      v4 = *v2;
      v2[(_DWORD)v3] = *v2;
      ++v2;
    }
    while ( v4 != 0 );
    V_AppendSlash(pStr: tempPath, strSize: 260);
    v5 = strlen(pFileMask) + 1;
    v6 = &v13;
    do
      v7 = *++v6;
    while ( v7 != 0 );
    qmemcpy(v6, pFileMask, v5);
    FindFiles = v15->FindFiles;
    memset(&fileList, 0, sizeof(fileList));
    FindFiles(this: v15, a2: tempPath, a3: false, a4: &fileList);
    v9 = 0;
    if ( fileList.m_Size > 0 )
    {
      v10 = 0;
      do
      {
        v11 = CUtlString::operator char const *(this: &fileList.m_Memory.m_pMemory[v10].fileName);
        _unlink(path: v11);
        ++v9;
        ++v10;
      }
      while ( v9 < fileList.m_Size );
    }
    CUtlVector<CEventRelativeTag,CUtlMemory<CEventRelativeTag,int>>::RemoveAll(this: (CUtlVector<CEventRelativeTag,CUtlMemory<CEventRelativeTag,int> > *)&fileList);
    m_pMemory = fileList.m_Memory.m_pMemory;
    if ( fileList.m_Memory.m_nGrowSize >= 0 )
    {
      if ( fileList.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: fileList.m_Memory.m_pMemory);
        m_pMemory = nullptr;
        fileList.m_Memory.m_pMemory = nullptr;
      }
      fileList.m_Memory.m_nAllocationCount = 0;
    }
    fileList.m_pElements = m_pMemory;
    if ( fileList.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041FAD0
// Name: private: void CScriptLib::RecurseFileTree_r(char const __near *,int,class CUtlVector<class CUtlString,class CUtlMemory<class CUtlString,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CScriptLib::RecurseFileTree_r(
        CScriptLib *this,
        const char *pDirPath,
        int depth,
        CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *dirList)
{
  fileList_t *i; // ebx
  int v5; // eax
  int v6; // eax
  fileList_t *m_pMemory; // edi
  const char *v8; // eax
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CUtlString *v11; // ecx
  int v12; // eax
  int v13; // edi
  CUtlString *v14; // ecx
  CUtlVector<fileList_t,CUtlMemory<fileList_t,int> > fileList; // [esp+Ch] [ebp-18h] BYREF
  CScriptLib *v16; // [esp+20h] [ebp-4h]

  i = nullptr;
  v16 = this;
  memset(&fileList, 0, sizeof(fileList));
  v5 = CScriptLib::GetFileList(
         this,
         pDirPath,
         pPattern: "\\",
         (CUtlVector<CEventRelativeTag,CUtlMemory<CEventRelativeTag,int> > *)&fileList);
  if ( v5 != 0 )
  {
    if ( v5 > 0 )
    {
      m_pMemory = fileList.m_Memory.m_pMemory;
      for ( i = (fileList_t *)v5; i != nullptr; i = (fileList_t *)((char *)i - 1) )
      {
        v8 = CUtlString::operator char const *(this: &m_pMemory->fileName);
        CScriptLib::RecurseFileTree_r(this: v16, pDirPath: v8, depth: depth + 1, dirList);
        ++m_pMemory;
      }
    }
    m_Size = dirList->m_Size;
    m_nAllocationCount = dirList->m_Memory.m_nAllocationCount;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<ResourceCopy_t,int>::Grow(
        this: (CUtlMemory<ResourceCopy_t,int> *)dirList,
        num: m_Size - m_nAllocationCount + 1);
    ++dirList->m_Size;
    v11 = dirList->m_Memory.m_pMemory;
    v12 = dirList->m_Size - m_Size - 1;
    dirList->m_pElements = dirList->m_Memory.m_pMemory;
    if ( v12 > (int)i )
      _V_memmove(dest: &v11[m_Size + 1], src: &v11[m_Size], count: 16 * v12);
    v13 = m_Size;
    v14 = &dirList->m_Memory.m_pMemory[v13];
    if ( v14 != nullptr )
      CUtlString::CUtlString(this: v14);
    CUtlString::Set(this: &dirList->m_Memory.m_pMemory[v13], pValue: pDirPath);
    CUtlVector<CEventRelativeTag,CUtlMemory<CEventRelativeTag,int>>::RemoveAll(this: (CUtlVector<CEventRelativeTag,CUtlMemory<CEventRelativeTag,int> > *)&fileList);
    if ( fileList.m_Memory.m_nGrowSize >= (int)i && fileList.m_Memory.m_pMemory != i )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: fileList.m_Memory.m_pMemory);
  }
  else
  {
    v6 = CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>::InsertBefore(this: dirList, elem: dirList->m_Size);
    CUtlString::Set(this: &dirList->m_Memory.m_pMemory[v6], pValue: pDirPath);
    CUtlVector<CEventRelativeTag,CUtlMemory<CEventRelativeTag,int>>::~CUtlVector<CEventRelativeTag,CUtlMemory<CEventRelativeTag,int>>(this: (CUtlVector<CEventRelativeTag,CUtlMemory<CEventRelativeTag,int> > *)&fileList);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041FBF0
// Name: public: virtual int CScriptLib::FindFiles(char __near *,bool,class CUtlVector<struct fileList_t,class CUtlMemory<struct fileList_t,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CScriptLib::FindFiles(
        CScriptLib *this,
        char *pFileMask,
        bool bRecurse,
        CUtlVector<fileList_t,CUtlMemory<fileList_t,int> > *fileList)
{
  CScriptLib *v4; // edi
  char *v5; // edi
  char v6; // al
  unsigned int v7; // eax
  char *v8; // edi
  char v9; // cl
  int m_nGrowSize; // esi
  fileList_t *m_pMemory; // eax
  const char *v13; // eax
  CUtlVector<fileList_t,CUtlMemory<fileList_t,int> > *v14; // esi
  int m_Size; // edi
  int inserted; // eax
  fileList_t *v17; // edi
  int v18; // ebx
  CUtlString *p_fileName; // esi
  int timeWrite_high; // eax
  bool v21; // zf
  CUtlString *v22; // eax
  unsigned int v23; // [esp-8h] [ebp-34Ch]
  char extension[260]; // [esp+8h] [ebp-33Ch] BYREF
  char dirPath[260]; // [esp+10Ch] [ebp-238h] BYREF
  char pattern[260]; // [esp+210h] [ebp-134h] BYREF
  CScriptLib *v27; // [esp+314h] [ebp-30h]
  int i; // [esp+318h] [ebp-2Ch]
  CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > dirList; // [esp+31Ch] [ebp-28h] BYREF
  CUtlVector<fileList_t,CUtlMemory<fileList_t,int> > tempList; // [esp+330h] [ebp-14h] BYREF
  char *pFileMaska; // [esp+34Ch] [ebp+8h]
  int bRecursea; // [esp+350h] [ebp+Ch]

  v4 = this;
  v27 = this;
  strcpy(dirPath, pFileMask);
  V_StripFilename(path: dirPath);
  V_FileBase(in: pFileMask, out: pattern, maxlen: 260);
  V_ExtractFileExtension(path: pFileMask, dest: extension, destSize: 260);
  if ( extension[0] != 0 )
  {
    v5 = &dirPath[259];
    do
      v6 = *++v5;
    while ( v6 != 0 );
    strcpy(v5, ".");
    v7 = strlen(extension) + 1;
    v8 = &dirPath[259];
    do
      v9 = *++v8;
    while ( v9 != 0 );
    qmemcpy(v8, extension, v7);
    v4 = v27;
  }
  if ( bRecurse )
  {
    memset(&tempList, 0, sizeof(tempList));
    memset(&dirList, 0, sizeof(dirList));
    CScriptLib::RecurseFileTree_r(this: v4, pDirPath: dirPath, depth: 0, &dirList);
    i = 0;
    if ( dirList.m_Size > 0 )
    {
      bRecursea = 0;
      while ( 1 )
      {
        CUtlVector<CEventRelativeTag,CUtlMemory<CEventRelativeTag,int>>::RemoveAll(this: (CUtlVector<CEventRelativeTag,CUtlMemory<CEventRelativeTag,int> > *)&tempList);
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
          v23 = 24 * dirList.m_Size;
          if ( m_pMemory != nullptr )
            m_pMemory = (fileList_t *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v23);
          else
            m_pMemory = (fileList_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v23);
          tempList.m_Memory.m_pMemory = m_pMemory;
        }
        tempList.m_pElements = m_pMemory;
        v13 = CUtlString::operator char const *(this: &dirList.m_Memory.m_pMemory[bRecursea]);
        CScriptLib::GetFileList(
          this: v4,
          pDirPath: v13,
          pPattern: pattern,
          fileList: (CUtlVector<CEventRelativeTag,CUtlMemory<CEventRelativeTag,int> > *)&tempList);
        v14 = fileList;
        m_Size = tempList.m_Size;
        inserted = CUtlVector<fileList_t,CUtlMemory<fileList_t,int>>::InsertMultipleBefore(
                     this: fileList,
                     elem: fileList->m_Size,
                     num: tempList.m_Size);
        if ( m_Size > 0 )
        {
          v17 = tempList.m_Memory.m_pMemory;
          v18 = inserted;
          pFileMaska = (char *)tempList.m_Size;
          while ( 1 )
          {
            p_fileName = &v14->m_Memory.m_pMemory[v18].fileName;
            CUtlString::operator=(this: p_fileName, src: &v17->fileName);
            p_fileName[1].m_Storage.m_Memory.m_pMemory = (unsigned __int8 *)v17->timeWrite;
            timeWrite_high = HIDWORD(v17->timeWrite);
            ++v17;
            ++v18;
            v21 = pFileMaska-- == (char *)1;
            p_fileName[1].m_Storage.m_Memory.m_nAllocationCount = timeWrite_high;
            if ( v21 )
              break;
            v14 = fileList;
          }
        }
        ++bRecursea;
        if ( ++i >= dirList.m_Size )
          break;
        v4 = v27;
      }
    }
    CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::RemoveAll(this: (CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int> > *)&dirList);
    v22 = dirList.m_Memory.m_pMemory;
    if ( dirList.m_Memory.m_nGrowSize >= 0 )
    {
      if ( dirList.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: dirList.m_Memory.m_pMemory);
        v22 = nullptr;
        dirList.m_Memory.m_pMemory = nullptr;
      }
      dirList.m_Memory.m_nAllocationCount = 0;
    }
    dirList.m_pElements = v22;
    if ( dirList.m_Memory.m_nGrowSize >= 0 )
    {
      if ( v22 != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v22);
        dirList.m_Memory.m_pMemory = nullptr;
      }
      dirList.m_Memory.m_nAllocationCount = 0;
    }
    CUtlVector<CEventRelativeTag,CUtlMemory<CEventRelativeTag,int>>::RemoveAll(this: (CUtlVector<CEventRelativeTag,CUtlMemory<CEventRelativeTag,int> > *)&tempList);
    if ( tempList.m_Memory.m_nGrowSize < 0 )
    {
      return fileList->m_Size;
    }
    else
    {
      if ( tempList.m_Memory.m_pMemory != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: tempList.m_Memory.m_pMemory);
      return fileList->m_Size;
    }
  }
  else
  {
    CScriptLib::GetFileList(
      this: v4,
      pDirPath: dirPath,
      pPattern: pattern,
      (CUtlVector<CEventRelativeTag,CUtlMemory<CEventRelativeTag,int> > *)fileList);
    return fileList->m_Size;
  }
}

} // namespace makegamedata

// ============================================================
// Overlay from mdlcheck (Missing functions)
// ============================================================
namespace mdlcheck {

//------------------------------------------------------------------------------
// Address: 0x00403600
// Name: public: void CUtlMemory<class CUtlSymbol,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<CUtlSymbol,int>::Grow(CUtlMemory<CUtlSymbol,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  CUtlSymbol *m_pMemory; // edx
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
        m_nAllocationCount = 16;
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
    v7 = 2 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (CUtlSymbol *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (CUtlSymbol *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004069E0
// Name: public: void CUtlMemory<struct fileList_t,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<fileList_t,int>::Grow(
        CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int> > *,int>::Node_t,int>,int> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int> > *,int>::Node_t,int> *m_pMemory; // edx
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
      this->m_pMemory = (UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int> > *,int>::Node_t,int> *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int> > *,int>::Node_t,int> *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00407EB0
// Name: void DefaultScriptLoadedCallback(char const __near *,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DefaultScriptLoadedCallback()
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x00407EC0
// Name: void AddScriptToStack(char __near *,enum ScriptPathMode_t)
// Source: json
//------------------------------------------------------------------------------
void __cdecl AddScriptToStack(char *filename, ScriptPathMode_t pathMode)
{
  int File; // esi
  const char *v3; // [esp-8h] [ebp-8h]

  if ( ++script == (script_t *)token )
    _Error(a1: "script file exceeded MAX_INCLUDES");
  if ( pathMode == SCRIPT_USE_RELATIVE_PATH )
  {
    V_strncpy(pDest: script->filename, pSrc: filename, maxLen: 1024);
  }
  else
  {
    v3 = ExpandPath(path: filename);
    V_strncpy(pDest: script->filename, pSrc: v3, maxLen: 1024);
  }
  File = LoadFile(filename: script->filename, bufferptr: (void **)&script->buffer);
  if ( g_pfnCallback != nullptr )
  {
    if ( script == &scriptstack[1] )
      g_pfnCallback(a1: script->filename, a2: nullptr, a3: 0);
    else
      g_pfnCallback(a1: script->filename, a2: script[-1].filename, a3: script[-1].line);
  }
  script->line = 1;
  script->script_p = script->buffer;
  script->end_p = &script->buffer[File];
}

//------------------------------------------------------------------------------
// Address: 0x00407FA0
// Name: bool AddMacroToStack(char __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl AddMacroToStack(char *macroname)
{
  int v2; // esi
  bool v3; // zf
  script_t *v4; // edi
  script_t *v5; // ebx
  int nummacroparams; // eax
  char *macrobuffer; // esi
  char **macroparam; // edi
  unsigned int v9; // esi
  script_t *pmacro; // [esp+4h] [ebp-4h]
  int i; // [esp+10h] [ebp+8h]

  if ( *macroname != 36 )
    return 0;
  v2 = 0;
  v3 = nummacros == 0;
  if ( nummacros > 0 )
  {
    do
    {
      if ( _V_stricmp(s1: macrolist[v2]->filename, s2: macroname + 1) == 0 )
        break;
      ++v2;
    }
    while ( v2 < nummacros );
    v3 = v2 == nummacros;
  }
  if ( v3 )
    return 0;
  v4 = macrolist[v2];
  v5 = script + 2;
  pmacro = v4;
  if ( &script[2] == (script_t *)token )
    _Error(a1: "script file exceeded MAX_INCLUDES");
  nummacroparams = v4->nummacroparams;
  macrobuffer = v5->macrobuffer;
  v5->nummacroparams = nummacroparams;
  i = 0;
  if ( nummacroparams > 0 )
  {
    macroparam = v5->macroparam;
    do
    {
      GetToken(crossline: 0);
      strcpy(macrobuffer, token);
      *macroparam = *(char **)((char *)macroparam + (char *)pmacro - (char *)v5);
      macroparam[64] = macrobuffer;
      macrobuffer += strlen(token) + 1;
      if ( macrobuffer >= (char *)v5->macroparam )
        _Error(a1: "Macro buffer overflow\n");
      ++macroparam;
      ++i;
    }
    while ( i < v5->nummacroparams );
    v4 = pmacro;
  }
  script = (script_t *)strcpy(v5->filename, v4->filename);
  v9 = v4->end_p - v4->buffer;
  script->buffer = (char *)malloc(size: v9 + 1);
  memcpy(dst: (unsigned __int8 *)script->buffer, src: (unsigned __int8 *)v4->buffer, count: v9);
  v4->buffer[v9] = 0;
  script->script_p = script->buffer;
  script->end_p = &script->buffer[v9];
  script->line = v4->line;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00408160
// Name: bool ExpandMacroToken(char __near * __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl ExpandMacroToken(char **token_p)
{
  char *script_p; // eax
  _BYTE *v2; // ebx
  char v3; // al
  script_t *v5; // eax
  int v6; // esi
  int v7; // edi
  bool v8; // zf
  const char *v9; // edx
  unsigned int v10; // eax
  _BYTE *v11; // esi
  char v12; // cl
  char *s2; // [esp+0h] [ebp-4h]

  if ( script->nummacroparams == 0 )
    return 0;
  script_p = script->script_p;
  if ( *script_p != 36 )
    return 0;
  v2 = script_p + 1;
  s2 = script_p + 1;
  v3 = script_p[1];
  if ( v3 <= 32 )
  {
LABEL_6:
    if ( *v2 != 36 )
      return 0;
  }
  else
  {
    while ( v3 != 36 )
    {
      v3 = *++v2;
      if ( v3 <= 32 )
        goto LABEL_6;
    }
  }
  *v2 = 0;
  v5 = script;
  v6 = 0;
  if ( script->nummacroparams <= 0 )
    goto LABEL_13;
  v7 = 5136;
  do
  {
    v8 = _V_stricmp(s1: *(const char **)&v5->filename[v7], s2) == 0;
    v5 = script;
    if ( v8 )
      break;
    ++v6;
    v7 += 4;
  }
  while ( v6 < script->nummacroparams );
  if ( v6 >= script->nummacroparams )
  {
LABEL_13:
    _Error(a1: "unknown macro token \"%s\" in %s\n", s2, v5->filename);
    v5 = script;
  }
  v9 = v5->macrovalue[v6];
  v10 = strlen(v9);
  v11 = *token_p;
  do
  {
    v12 = *v9;
    *v11++ = *v9++;
  }
  while ( v12 != 0 );
  *token_p += v10;
  script->script_p = v2 + 1;
  if ( script->script_p >= script->end_p )
    _Error(a1: "Macro expand overflow\n");
  if ( *token_p >= (char *)&nummacros )
    _Error(a1: "Token too large on line %i\n", scriptline);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00408290
// Name: void ParseFromMemory(char __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ParseFromMemory(char *buffer, int size)
{
  scriptstack[1].buffer = buffer;
  scriptstack[1].script_p = buffer;
  script = &scriptstack[1];
  scriptstack[1].end_p = &buffer[size];
  strcpy(scriptstack[1].filename, "memory buffer");
  scriptstack[1].line = 1;
  endofscript = 0;
  tokenready = 0;
}

//------------------------------------------------------------------------------
// Address: 0x00408300
// Name: int EndOfScript(int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl EndOfScript(int crossline)
{
  if ( crossline == 0 )
    _Error(a1: "Line %i is incomplete\n", scriptline);
  if ( strcmp(script->filename, aMemoryB) == 0
    || (free(pBlock: script->buffer), script->buffer = nullptr, script == &scriptstack[1]) )
  {
    endofscript = 1;
    return 0;
  }
  else
  {
    --script;
    scriptline = script->line;
    return GetToken(crossline);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004083C0
// Name: int TokenAvailable(void)
// Source: json
//------------------------------------------------------------------------------
int __cdecl TokenAvailable()
{
  char *script_p; // eax
  char *end_p; // edx
  char v3; // cl
  char v4; // cl

  if ( tokenready != 0 )
    return 1;
  script_p = script->script_p;
  end_p = script->end_p;
  if ( script_p < end_p )
  {
    v3 = *script_p;
    if ( *script_p > 32 )
    {
LABEL_8:
      v4 = *script_p;
      if ( *script_p != 59 && v4 != 35 && (v4 != 47 || script_p[1] != 47) )
        return 1;
    }
    else
    {
      while ( v3 != 10 )
      {
        if ( ++script_p == end_p )
          break;
        v3 = *script_p;
        if ( *script_p > 32 )
          goto LABEL_8;
      }
    }
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00408420
// Name: public: virtual bool CScriptLib::DoesFileExist(char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CScriptLib::DoesFileExist(CScriptLib *this, const char *pFilename)
{
  return g_pFullFileSystem->FileExists(this: &g_pFullFileSystem->IBaseFileSystem, a2: pFilename, a3: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x00408440
// Name: public: virtual bool CScriptLib::ReadFileToBuffer(char const __near *,class CUtlBuffer __near &,bool,bool)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CScriptLib::ReadFileToBuffer(
        CScriptLib *this,
        const char *pSourceName,
        CUtlBuffer *buffer,
        bool bText,
        bool bNoOpenFailureWarning)
{
  int *v5; // eax
  const char *v6; // eax

  if ( g_pFullFileSystem->ReadFile(
         this: &g_pFullFileSystem->IBaseFileSystem,
         a2: pSourceName,
         a3: nullptr,
         a4: buffer,
         a5: 0,
         a6: 0,
         a7: nullptr) )
  {
    if ( bText )
      CUtlBuffer::SetBufferType(this: buffer, bIsText: true, bContainsCRLF: true);
    else
      CUtlBuffer::SetBufferType(this: buffer, bIsText: false, bContainsCRLF: false);
    return 1;
  }
  else
  {
    if ( !bNoOpenFailureWarning )
    {
      v5 = _errno();
      v6 = strerror(errnum: *v5);
      _Msg(a1: "ReadFileToBuffer(): Error opening %s: %s\n", pSourceName, v6);
    }
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004084C0
// Name: public: virtual bool CScriptLib::WriteBufferToFile(char const __near *,class CUtlBuffer __near &,enum DiskWriteMode_t)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CScriptLib::WriteBufferToFile(
        CScriptLib *this,
        const char *pTargetName,
        CUtlBuffer *buffer,
        DiskWriteMode_t writeMode)
{
  _BYTE *v5; // eax
  _BYTE *v6; // esi
  _BYTE *v7; // eax
  char dirPath[260]; // [esp+8h] [ebp-104h] BYREF

  strcpy(dirPath, pTargetName);
  strchr(string: (unsigned __int8 *)dirPath, chr: 0x5Cu);
  v6 = v5;
  if ( v5 != nullptr )
  {
    while ( 1 )
    {
      strchr(string: v6 + 1, chr: 0x5Cu);
      v6 = v7;
      if ( v7 == nullptr )
        break;
      *v7 = 0;
      _mkdir(path: dirPath);
      *v6 = 92;
    }
  }
  return writeMode != WRITE_TO_DISK_ALWAYS
      && (writeMode != WRITE_TO_DISK_UPDATE || !this->DoesFileExist(this, a2: pTargetName))
      || g_pFullFileSystem->WriteFile(
           this: &g_pFullFileSystem->IBaseFileSystem,
           a2: pTargetName,
           a3: nullptr,
           a4: buffer);
}

//------------------------------------------------------------------------------
// Address: 0x00408580
// Name: public: virtual int CScriptLib::CompareFileTime(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CScriptLib::CompareFileTime(CScriptLib *this, const char *pFilenameA, const char *pFilenameB)
{
  unsigned int v3; // esi
  unsigned int v4; // eax
  bool v5; // cf

  v3 = g_pFullFileSystem->GetFileTime(this: &g_pFullFileSystem->IBaseFileSystem, a2: pFilenameA, a3: nullptr);
  v4 = g_pFullFileSystem->GetFileTime(this: &g_pFullFileSystem->IBaseFileSystem, a2: pFilenameB, a3: nullptr);
  if ( v3 == -1 )
    v3 = 0;
  if ( v4 == -1 )
    return v3 != 0;
  v5 = v4 < v3;
  if ( v4 <= v3 )
    return v5;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004085E0
// Name: public: virtual char __near * CScriptLib::MakeTemporaryFilename(char const __near *,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CScriptLib::MakeTemporaryFilename(CScriptLib *this, const char *pchModPath, char *pPath, int pathSize)
{
  char *v4; // eax
  char *v5; // esi

  v4 = _tempnam(dir: pchModPath, pfx: "mgd_");
  v5 = v4;
  if ( *v4 == 92 )
    v5 = v4 + 1;
  if ( v5[strlen(v5) - 1] == 46 )
    v5[strlen(v5) - 1] = 0;
  V_snprintf(pDest: pPath, maxLen: pathSize, pFormat: "%s.tmp", v5);
  free(pBlock: v5);
  return pPath;
}

//------------------------------------------------------------------------------
// Address: 0x00408650
// Name: void DefineMacro(char __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DefineMacro(char *macroname)
{
  script_t *v1; // edi
  char *script_p; // esi
  char *macrobuffer; // ebx
  unsigned int v4; // ebx
  unsigned __int8 *v5; // eax
  int v6; // eax
  script_t *v7; // edx

  v1 = (script_t *)malloc(size: 0x1614u);
  strcpy(v1->filename, macroname);
  v1->line = script->line;
  v1->nummacroparams = 0;
  script_p = script->script_p;
  macrobuffer = v1->macrobuffer;
  while ( TokenAvailable() != 0 )
  {
    GetToken(crossline: 0);
    if ( token[0] == 92 && byte_842709 == 92 )
      break;
    script_p = script->script_p;
    v1->macroparam[v1->nummacroparams++] = macrobuffer;
    strcpy(macrobuffer, token);
    macrobuffer += strlen(token) + 1;
    if ( macrobuffer >= (char *)v1->macroparam )
      _Error(a1: "Macro buffer overflow\n");
  }
  for ( script->script_p = script_p; *script_p != 0; ++script_p )
  {
    if ( *script_p == 10 )
      break;
    if ( *script_p == 92 && script_p[1] == 92 )
    {
      do
      {
        if ( *script_p == 10 )
          break;
        *script_p++ = 32;
      }
      while ( *script_p != 0 );
      if ( *script_p == 0 )
        break;
    }
  }
  v4 = script_p - script->script_p;
  v5 = (unsigned __int8 *)malloc(size: v4 + 1);
  v1->buffer = (char *)v5;
  memcpy(dst: v5, src: (unsigned __int8 *)script->script_p, count: v4);
  v1->buffer[v4] = 0;
  v1->end_p = &v1->buffer[v4];
  v6 = nummacros;
  v7 = script;
  macrolist[nummacros] = v1;
  nummacros = v6 + 1;
  v7->script_p = script_p;
}

//------------------------------------------------------------------------------
// Address: 0x004087F0
// Name: public: void CUtlMemory<struct variable_t,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<variable_t,int>::Grow(CUtlMemory<variable_t,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  variable_t *m_pMemory; // edx
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
      this->m_pMemory = (variable_t *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (variable_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00408890
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
// Address: 0x00408920
// Name: bool ExpandVariableToken(char __near * __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl ExpandVariableToken(char **token_p)
{
  char *script_p; // ebx
  const char *v2; // ebx
  char *v3; // esi
  char v4; // al
  int v6; // esi
  int v7; // edi
  void (*v8)(const char *, ...); // ebx
  char *value; // edi
  unsigned int v10; // eax
  char *v11; // edx
  _BYTE *v12; // esi
  char v13; // cl
  const char *v14; // [esp-10h] [ebp-18h]
  char *cp; // [esp+4h] [ebp-4h]

  script_p = script->script_p;
  if ( *script_p != 36 )
    return 0;
  v2 = script_p + 1;
  v3 = (char *)v2;
  v4 = *v2;
  cp = (char *)v2;
  if ( *v2 <= 32 )
  {
LABEL_6:
    if ( *v3 != 36 )
      return 0;
  }
  else
  {
    while ( v4 != 36 )
    {
      v4 = *++v3;
      if ( v4 <= 32 )
      {
        cp = v3;
        goto LABEL_6;
      }
    }
    cp = v3;
  }
  v6 = v3 - v2;
  v7 = 0;
  v2[v6] = 0;
  if ( g_definevariable.m_Size <= 0 )
    goto LABEL_14;
  while ( V_strnicmp(s1: g_definevariable.m_Memory.m_pMemory[v7].param, s2: v2, n: v6) != 0 )
  {
    if ( ++v7 >= g_definevariable.m_Size )
      goto LABEL_14;
  }
  if ( v7 < g_definevariable.m_Size )
  {
    v8 = (void (*)(const char *, ...))_Error;
  }
  else
  {
LABEL_14:
    v14 = v2;
    v8 = (void (*)(const char *, ...))_Error;
    _Error(a1: "unknown variable token \"%s\" in %s\n", v14, script->filename);
  }
  value = g_definevariable.m_Memory.m_pMemory[v7].value;
  v10 = strlen(value);
  v11 = value;
  v12 = *token_p;
  do
  {
    v13 = *v11;
    *v12++ = *v11++;
  }
  while ( v13 != 0 );
  *token_p += v10;
  script->script_p = cp + 1;
  if ( script->script_p >= script->end_p )
    v8(a1: "Macro expand overflow\n");
  if ( *token_p >= (char *)&nummacros )
    v8(a1: "Token too large on line %i\n", scriptline);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00408AC0
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
// Address: 0x00408B30
// Name: void DefineVariable(char __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DefineVariable(char *variablename)
{
  char *v1; // eax
  char *v2; // eax
  char *v3; // ecx
  char v4; // dl
  variable_t v; // [esp+8h] [ebp-8h] BYREF

  if ( variablename != nullptr
    && (v1 = (char *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: strlen(variablename) + 1)) != nullptr )
  {
    strcpy(v1, variablename);
  }
  else
  {
    v1 = nullptr;
  }
  v.param = v1;
  GetToken(crossline: 0);
  v2 = (char *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: strlen(token) + 1);
  if ( v2 != nullptr )
  {
    v3 = v2;
    do
    {
      v4 = v3[token - v2];
      *v3++ = v4;
    }
    while ( v4 != 0 );
  }
  else
  {
    v2 = nullptr;
  }
  v.value = v2;
  CUtlVector<variable_t,CUtlMemory<variable_t,int>>::InsertBefore(
    this: &g_definevariable,
    elem: g_definevariable.m_Size,
    src: &v);
}

//------------------------------------------------------------------------------
// Address: 0x00408BF0
// Name: int GetToken(int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl GetToken(int crossline)
{
  script_t *v1; // eax
  char *script_p; // ecx
  char v3; // dl
  script_t *v4; // eax
  char *v5; // ecx
  char *v6; // edx
  char v7; // cl
  char *v8; // ecx
  char v9; // dl
  script_t *v10; // eax
  char *v11; // edx
  script_t *v12; // eax
  int line; // edx
  char v14; // cl
  char *v15; // esi
  script_t *v16; // eax
  char i; // cl
  char *v18; // esi
  char *v19; // ecx
  char *token_p; // [esp+Ch] [ebp-4h] BYREF

  if ( tokenready != 0 )
  {
LABEL_54:
    tokenready = 0;
    return 1;
  }
  else
  {
    while ( 1 )
    {
      v1 = script;
      if ( script->script_p >= script->end_p )
        return EndOfScript(crossline);
      tokenready = 0;
      while ( 1 )
      {
        while ( 1 )
        {
          if ( *v1->script_p <= 32 )
          {
            do
            {
              script_p = v1->script_p;
              if ( script_p >= v1->end_p )
                return EndOfScript(crossline);
              v3 = *script_p;
              v1->script_p = script_p + 1;
              if ( v3 == 10 )
              {
                if ( crossline == 0 )
                  _Error(a1: "Line %i is incomplete\n", scriptline);
                v4 = script;
                ++script->line;
                scriptline = v4->line;
              }
              v1 = script;
            }
            while ( *script->script_p <= 32 );
          }
          v5 = v1->script_p;
          if ( v5 >= v1->end_p )
            return EndOfScript(crossline);
          v6 = v1->script_p;
          v7 = *v5;
          if ( v7 != 59 && v7 != 35 )
          {
            if ( v7 != 47 )
              goto LABEL_30;
            if ( v6[1] != 47 )
              break;
          }
          if ( crossline == 0 )
          {
            _Error(a1: "Line %i is incomplete\n", scriptline);
            v1 = script;
          }
          if ( *v1->script_p != 10 )
          {
            do
            {
              ++v1->script_p;
              v1 = script;
              v11 = script->script_p;
              if ( v11 >= script->end_p )
                return EndOfScript(crossline);
            }
            while ( *v11 != 10 );
          }
          ++v1->script_p;
          v12 = script;
          ++script->line;
          line = v12->line;
          v1 = script;
          scriptline = line;
        }
        if ( v6[1] != 42 )
          break;
        v1->script_p += 2;
        while ( 1 )
        {
          v8 = script->script_p;
          if ( *v8 == 42 && v8[1] == 47 )
            break;
          v9 = *v8;
          script->script_p = v8 + 1;
          if ( v9 != 10 )
          {
            v10 = script;
            if ( script->script_p >= script->end_p )
              return EndOfScript(crossline);
            ++script->line;
            scriptline = v10->line;
          }
        }
        script->script_p += 2;
        v1 = script;
      }
LABEL_30:
      v14 = *v6;
      v15 = token;
      token_p = token;
      if ( v14 == 34 )
      {
        ++v1->script_p;
        v16 = script;
        for ( i = *script->script_p; i != 34; i = *v16->script_p )
        {
          *v15 = i;
          ++script->script_p;
          v16 = script;
          ++v15;
          if ( script->script_p == script->end_p )
            break;
          if ( v15 == (char *)&nummacros )
          {
            _Error(a1: "Token too large on line %i\n", scriptline);
            v16 = script;
          }
        }
        ++v16->script_p;
      }
      else
      {
        for ( ; v14 > 32; v14 = *script->script_p )
        {
          if ( v14 == 59 )
            break;
          if ( ExpandMacroToken(&token_p) != 0 || ExpandVariableToken(&token_p) != 0 )
          {
            v15 = token_p;
          }
          else
          {
            v18 = token_p;
            *token_p = *script->script_p++;
            v19 = script->script_p;
            v15 = v18 + 1;
            token_p = v15;
            if ( v19 == script->end_p )
              break;
            if ( v15 == (char *)&nummacros )
              _Error(a1: "Token too large on line %i\n", scriptline);
          }
        }
      }
      *v15 = 0;
      if ( _V_stricmp(s1: token, s2: "$include") != 0 )
      {
        if ( _V_stricmp(s1: token, s2: "$definemacro") != 0 )
        {
          if ( _V_stricmp(s1: token, s2: "$definevariable") != 0 )
          {
            if ( AddMacroToStack(macroname: token) == 0 )
              return 1;
          }
          else
          {
            GetToken(crossline: 0);
            DefineVariable(variablename: token);
          }
        }
        else
        {
          GetToken(crossline: 0);
          DefineMacro(macroname: token);
        }
      }
      else
      {
        GetToken(crossline: 0);
        AddScriptToStack(filename: token, pathMode: SCRIPT_USE_ABSOLUTE_PATH);
      }
      if ( tokenready != 0 )
        goto LABEL_54;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00408FF0
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
      (CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int> > *,int>::Node_t,int>,int> *)this,
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
// Address: 0x00409060
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
      (CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<char *,CUtlMemory<char *,int> > *,int>::Node_t,int>,int> *)this,
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
// Address: 0x00409100
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
// Address: 0x00409170
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
// Address: 0x004091E0
// Name: private: int CScriptLib::GetFileList(char const __near *,char const __near *,class CUtlVector<struct fileList_t,class CUtlMemory<struct fileList_t,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CScriptLib::GetFileList(
        CScriptLib *this,
        const char *pDirPath,
        const char *pPattern,
        CUtlVector<fileList_t,CUtlMemory<fileList_t,int> > *fileList)
{
  unsigned int v5; // kr00_4
  int v6; // eax
  char v7; // cl
  char *v8; // edi
  char v9; // al
  unsigned int v10; // eax
  char *v11; // edi
  char v12; // cl
  int v13; // esi
  int v15; // eax
  char v16; // cl
  unsigned int v17; // eax
  char *v18; // edi
  char v19; // cl
  char *v20; // edi
  char *v21; // esi
  char v22; // cl
  int m_Size; // eax
  int v24; // esi
  char v25; // [esp+Bh] [ebp-435h] BYREF
  char fileName[260]; // [esp+Ch] [ebp-434h] BYREF
  char fullPath[260]; // [esp+110h] [ebp-330h] BYREF
  _finddata64i32_t findData; // [esp+214h] [ebp-22Ch] BYREF
  char sourcePath[260]; // [esp+33Ch] [ebp-104h] BYREF
  int h; // [esp+448h] [ebp+8h]
  char bFindDirs_3; // [esp+453h] [ebp+13h]

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
  v5 = strlen(sourcePath);
  if ( v5 != 0 )
  {
    if ( findData.name[v5 + 259] != 92 )
    {
      sourcePath[v5] = 92;
      sourcePath[v5 + 1] = 0;
    }
  }
  else
  {
    strcpy(sourcePath, ".\\");
  }
  v6 = 0;
  do
  {
    v7 = sourcePath[v6];
    fullPath[v6++] = v7;
  }
  while ( v7 != 0 );
  if ( *pPattern != 92 || pPattern[1] != 0 )
  {
    bFindDirs_3 = 0;
    v10 = strlen(pPattern) + 1;
    v11 = &fileName[259];
    do
      v12 = *++v11;
    while ( v12 != 0 );
    qmemcpy(v11, pPattern, v10);
  }
  else
  {
    bFindDirs_3 = 1;
    v8 = &fileName[259];
    do
      v9 = *++v8;
    while ( v9 != 0 );
    strcpy(v8, "*");
  }
  v13 = _findfirst64i32(szWild: fullPath, pfd: &findData);
  h = v13;
  if ( v13 == -1 )
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
      v15 = 0;
      do
      {
        v16 = sourcePath[v15];
        fileName[v15++] = v16;
      }
      while ( v16 != 0 );
      v17 = strlen(findData.name) + 1;
      v18 = &v25;
      do
        v19 = *++v18;
      while ( v19 != 0 );
      qmemcpy(v18, findData.name, 4 * (v17 >> 2));
      v21 = &findData.name[4 * (v17 >> 2)];
      v20 = &v18[4 * (v17 >> 2)];
      v22 = v17;
      m_Size = fileList->m_Size;
      qmemcpy(v20, v21, v22 & 3);
      v24 = CUtlVector<fileList_t,CUtlMemory<fileList_t,int>>::InsertBefore(this: fileList, elem: m_Size);
      CUtlString::Set(this: &fileList->m_Memory.m_pMemory[v24].fileName, pValue: fileName);
      fileList->m_Memory.m_pMemory[v24].timeWrite = findData.time_write;
      v13 = h;
    }
  }
  while ( _findnext64i32(hFile: v13, pfd: &findData) == 0 );
  _findclose(hFile: v13);
  return fileList->m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x00409440
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
// Address: 0x004094A0
// Name: public: virtual void CScriptLib::DeleteTemporaryFiles(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CScriptLib::DeleteTemporaryFiles(CScriptLib *this, const char *pFileMask)
{
  char *v2; // eax
  char *v3; // edx
  char v4; // cl
  unsigned int v5; // eax
  char *v6; // edi
  char v7; // cl
  int (__thiscall *FindFiles)(struct CScriptLib *, char *, bool, CUtlVector<fileList_t,CUtlMemory<fileList_t,int> > *); // edx
  int v9; // esi
  int v10; // edi
  const char *v11; // eax
  fileList_t *m_pMemory; // eax
  char v13; // [esp+3h] [ebp-11Dh] BYREF
  char tempPath[260]; // [esp+4h] [ebp-11Ch] BYREF
  CScriptLib *v15; // [esp+108h] [ebp-18h]
  CUtlVector<fileList_t,CUtlMemory<fileList_t,int> > fileList; // [esp+10Ch] [ebp-14h] BYREF

  v15 = this;
  v2 = getenv(option: "temp");
  if ( v2 != nullptr || (v2 = getenv(option: "tmp")) != nullptr )
  {
    v3 = (char *)(tempPath - v2);
    do
    {
      v4 = *v2;
      v2[(_DWORD)v3] = *v2;
      ++v2;
    }
    while ( v4 != 0 );
    V_AppendSlash(pStr: tempPath, strSize: 260);
    v5 = strlen(pFileMask) + 1;
    v6 = &v13;
    do
      v7 = *++v6;
    while ( v7 != 0 );
    qmemcpy(v6, pFileMask, v5);
    FindFiles = v15->FindFiles;
    memset(&fileList, 0, sizeof(fileList));
    FindFiles(this: v15, a2: tempPath, a3: false, a4: &fileList);
    v9 = 0;
    if ( fileList.m_Size > 0 )
    {
      v10 = 0;
      do
      {
        v11 = CUtlString::Get(this: &fileList.m_Memory.m_pMemory[v10].fileName);
        _unlink(path: v11);
        ++v9;
        ++v10;
      }
      while ( v9 < fileList.m_Size );
    }
    CUtlVector<fileList_t,CUtlMemory<fileList_t,int>>::RemoveAll(this: &fileList);
    m_pMemory = fileList.m_Memory.m_pMemory;
    if ( fileList.m_Memory.m_nGrowSize >= 0 )
    {
      if ( fileList.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: fileList.m_Memory.m_pMemory);
        m_pMemory = nullptr;
        fileList.m_Memory.m_pMemory = nullptr;
      }
      fileList.m_Memory.m_nAllocationCount = 0;
    }
    fileList.m_pElements = m_pMemory;
    if ( fileList.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004095D0
// Name: private: void CScriptLib::RecurseFileTree_r(char const __near *,int,class CUtlVector<class CUtlString,class CUtlMemory<class CUtlString,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CScriptLib::RecurseFileTree_r(
        CScriptLib *this,
        const char *pDirPath,
        int depth,
        CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *dirList)
{
  fileList_t *i; // ebx
  int v5; // eax
  int v6; // eax
  fileList_t *m_pMemory; // edi
  const char *v8; // eax
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CUtlString *v11; // ecx
  int v12; // eax
  int v13; // edi
  CUtlString *v14; // ecx
  CUtlVector<fileList_t,CUtlMemory<fileList_t,int> > fileList; // [esp+Ch] [ebp-18h] BYREF
  CScriptLib *v16; // [esp+20h] [ebp-4h]

  i = nullptr;
  v16 = this;
  memset(&fileList, 0, sizeof(fileList));
  v5 = CScriptLib::GetFileList(this, pDirPath, pPattern: "\\", &fileList);
  if ( v5 != 0 )
  {
    if ( v5 > 0 )
    {
      m_pMemory = fileList.m_Memory.m_pMemory;
      for ( i = (fileList_t *)v5; i != nullptr; i = (fileList_t *)((char *)i - 1) )
      {
        v8 = CUtlString::Get(this: &m_pMemory->fileName);
        CScriptLib::RecurseFileTree_r(this: v16, pDirPath: v8, depth: depth + 1, dirList);
        ++m_pMemory;
      }
    }
    m_Size = dirList->m_Size;
    m_nAllocationCount = dirList->m_Memory.m_nAllocationCount;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<CUtlString,int>::Grow(this: &dirList->m_Memory, num: m_Size - m_nAllocationCount + 1);
    ++dirList->m_Size;
    v11 = dirList->m_Memory.m_pMemory;
    v12 = dirList->m_Size - m_Size - 1;
    dirList->m_pElements = dirList->m_Memory.m_pMemory;
    if ( v12 > (int)i )
      _V_memmove(dest: &v11[m_Size + 1], src: &v11[m_Size], count: 16 * v12);
    v13 = m_Size;
    v14 = &dirList->m_Memory.m_pMemory[v13];
    if ( v14 != nullptr )
      CUtlString::CUtlString(this: v14);
    CUtlString::Set(this: &dirList->m_Memory.m_pMemory[v13], pValue: pDirPath);
    CUtlVector<fileList_t,CUtlMemory<fileList_t,int>>::RemoveAll(this: &fileList);
    if ( fileList.m_Memory.m_nGrowSize >= (int)i && fileList.m_Memory.m_pMemory != i )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: fileList.m_Memory.m_pMemory);
  }
  else
  {
    v6 = CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>::InsertBefore(this: dirList, elem: dirList->m_Size);
    CUtlString::Set(this: &dirList->m_Memory.m_pMemory[v6], pValue: pDirPath);
    CUtlVector<fileList_t,CUtlMemory<fileList_t,int>>::~CUtlVector<fileList_t,CUtlMemory<fileList_t,int>>(this: &fileList);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004096F0
// Name: public: virtual int CScriptLib::FindFiles(char __near *,bool,class CUtlVector<struct fileList_t,class CUtlMemory<struct fileList_t,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CScriptLib::FindFiles(
        CScriptLib *this,
        char *pFileMask,
        bool bRecurse,
        CUtlVector<fileList_t,CUtlMemory<fileList_t,int> > *fileList)
{
  CScriptLib *v4; // edi
  char *v5; // edi
  char v6; // al
  unsigned int v7; // eax
  char *v8; // edi
  char v9; // cl
  int m_nGrowSize; // esi
  fileList_t *m_pMemory; // eax
  const char *v13; // eax
  CUtlVector<fileList_t,CUtlMemory<fileList_t,int> > *v14; // esi
  int m_Size; // edi
  int inserted; // eax
  fileList_t *v17; // edi
  int v18; // ebx
  CUtlString *p_fileName; // esi
  int timeWrite_high; // eax
  bool v21; // zf
  CUtlString *v22; // eax
  unsigned int v23; // [esp-8h] [ebp-34Ch]
  char extension[260]; // [esp+8h] [ebp-33Ch] BYREF
  char dirPath[260]; // [esp+10Ch] [ebp-238h] BYREF
  char pattern[260]; // [esp+210h] [ebp-134h] BYREF
  CScriptLib *v27; // [esp+314h] [ebp-30h]
  int i; // [esp+318h] [ebp-2Ch]
  CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > dirList; // [esp+31Ch] [ebp-28h] BYREF
  CUtlVector<fileList_t,CUtlMemory<fileList_t,int> > tempList; // [esp+330h] [ebp-14h] BYREF
  char *pFileMaska; // [esp+34Ch] [ebp+8h]
  int bRecursea; // [esp+350h] [ebp+Ch]

  v4 = this;
  v27 = this;
  strcpy(dirPath, pFileMask);
  V_StripFilename(path: dirPath);
  V_FileBase(in: pFileMask, out: pattern, maxlen: 260);
  V_ExtractFileExtension(path: pFileMask, dest: extension, destSize: 260);
  if ( extension[0] != 0 )
  {
    v5 = &dirPath[259];
    do
      v6 = *++v5;
    while ( v6 != 0 );
    strcpy(v5, ".");
    v7 = strlen(extension) + 1;
    v8 = &dirPath[259];
    do
      v9 = *++v8;
    while ( v9 != 0 );
    qmemcpy(v8, extension, v7);
    v4 = v27;
  }
  if ( bRecurse )
  {
    memset(&tempList, 0, sizeof(tempList));
    memset(&dirList, 0, sizeof(dirList));
    CScriptLib::RecurseFileTree_r(this: v4, pDirPath: dirPath, depth: 0, &dirList);
    i = 0;
    if ( dirList.m_Size > 0 )
    {
      bRecursea = 0;
      while ( 1 )
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
          v23 = 24 * dirList.m_Size;
          if ( m_pMemory != nullptr )
            m_pMemory = (fileList_t *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v23);
          else
            m_pMemory = (fileList_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v23);
          tempList.m_Memory.m_pMemory = m_pMemory;
        }
        tempList.m_pElements = m_pMemory;
        v13 = CUtlString::Get(this: &dirList.m_Memory.m_pMemory[bRecursea]);
        CScriptLib::GetFileList(this: v4, pDirPath: v13, pPattern: pattern, fileList: &tempList);
        v14 = fileList;
        m_Size = tempList.m_Size;
        inserted = CUtlVector<fileList_t,CUtlMemory<fileList_t,int>>::InsertMultipleBefore(
                     this: fileList,
                     elem: fileList->m_Size,
                     num: tempList.m_Size);
        if ( m_Size > 0 )
        {
          v17 = tempList.m_Memory.m_pMemory;
          v18 = inserted;
          pFileMaska = (char *)tempList.m_Size;
          while ( 1 )
          {
            p_fileName = &v14->m_Memory.m_pMemory[v18].fileName;
            CUtlString::operator=(this: p_fileName, src: &v17->fileName);
            p_fileName[1].m_Storage.m_Memory.m_pMemory = (unsigned __int8 *)v17->timeWrite;
            timeWrite_high = HIDWORD(v17->timeWrite);
            ++v17;
            ++v18;
            v21 = pFileMaska-- == (char *)1;
            p_fileName[1].m_Storage.m_Memory.m_nAllocationCount = timeWrite_high;
            if ( v21 )
              break;
            v14 = fileList;
          }
        }
        ++bRecursea;
        if ( ++i >= dirList.m_Size )
          break;
        v4 = v27;
      }
    }
    CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>::RemoveAll(this: &dirList);
    v22 = dirList.m_Memory.m_pMemory;
    if ( dirList.m_Memory.m_nGrowSize >= 0 )
    {
      if ( dirList.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: dirList.m_Memory.m_pMemory);
        v22 = nullptr;
        dirList.m_Memory.m_pMemory = nullptr;
      }
      dirList.m_Memory.m_nAllocationCount = 0;
    }
    dirList.m_pElements = v22;
    if ( dirList.m_Memory.m_nGrowSize >= 0 )
    {
      if ( v22 != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v22);
        dirList.m_Memory.m_pMemory = nullptr;
      }
      dirList.m_Memory.m_nAllocationCount = 0;
    }
    CUtlVector<fileList_t,CUtlMemory<fileList_t,int>>::RemoveAll(this: &tempList);
    if ( tempList.m_Memory.m_nGrowSize < 0 )
    {
      return fileList->m_Size;
    }
    else
    {
      if ( tempList.m_Memory.m_pMemory != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: tempList.m_Memory.m_pMemory);
      return fileList->m_Size;
    }
  }
  else
  {
    CScriptLib::GetFileList(this: v4, pDirPath: dirPath, pPattern: pattern, fileList);
    return fileList->m_Size;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040CE50
// Name: public: CUtlVector<void (*)(class IConVar __near *,char const __near *,float),class CUtlMemory<void (*)(class IConVar __near *,char const __near *,float),int>>::~CUtlVector<void (*)(class IConVar __near *,char const __near *,float),class CUtlMemory<void (*)(class IConVar __near *,char const __near *,float),int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<void (__cdecl *)(IConVar *,char const *,float),CUtlMemory<void (__cdecl *)(IConVar *,char const *,float),int>>::~CUtlVector<void (__cdecl *)(IConVar *,char const *,float),CUtlMemory<void (__cdecl *)(IConVar *,char const *,float),int>>(
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

} // namespace mdlcheck

// ============================================================
// Overlay from mdlcompile (Missing functions)
// ============================================================
namespace mdlcompile {

//------------------------------------------------------------------------------
// Address: 0x004266F0
// Name: void (*SetScriptLoadedCallback(void (*)(char const __near *,char const __near *,int)))(char const __near *,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void (__cdecl *__cdecl SetScriptLoadedCallback(
        void (__cdecl *pfnNewScriptLoadedCallback)(const char *, const char *, int)))(const char *, const char *, int)
{
  void (__cdecl *result)(const char *, const char *, int); // eax

  result = g_pfnCallback;
  g_pfnCallback = pfnNewScriptLoadedCallback;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00426710
// Name: void AddScriptToStack(char __near *,enum ScriptPathMode_t)
// Source: json
//------------------------------------------------------------------------------
void __usercall AddScriptToStack(int a1@<edi>, char *filename, ScriptPathMode_t pathMode)
{
  int File; // esi
  const char *v4; // [esp-8h] [ebp-8h]

  if ( ++script == (script_t *)token )
    _Error(a1: "script file exceeded MAX_INCLUDES");
  if ( pathMode == SCRIPT_USE_RELATIVE_PATH )
  {
    V_strncpy(pDest: script->filename, pSrc: filename, maxLen: 1024);
  }
  else
  {
    v4 = ExpandPath(path: filename);
    V_strncpy(pDest: script->filename, pSrc: v4, maxLen: 1024);
  }
  File = LoadFile(a1, filename: script->filename, bufferptr: (void **)&script->buffer);
  if ( g_pfnCallback != nullptr )
  {
    if ( script == &scriptstack[1] )
      g_pfnCallback(a1: script->filename, a2: nullptr, a3: 0);
    else
      g_pfnCallback(a1: script->filename, a2: script[-1].filename, a3: script[-1].line);
  }
  script->line = 1;
  script->script_p = script->buffer;
  script->end_p = &script->buffer[File];
}

//------------------------------------------------------------------------------
// Address: 0x004267F0
// Name: void LoadScriptFile(char __near *,enum ScriptPathMode_t)
// Source: json
//------------------------------------------------------------------------------
void __usercall LoadScriptFile(int a1@<edi>, char *filename, ScriptPathMode_t pathMode)
{
  script = scriptstack;
  AddScriptToStack(a1, filename, pathMode);
  endofscript = 0;
  tokenready = 0;
}

//------------------------------------------------------------------------------
// Address: 0x00426820
// Name: bool AddMacroToStack(char __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl AddMacroToStack(char *macroname)
{
  int v2; // esi
  bool v3; // zf
  script_t *v4; // edi
  script_t *v5; // ebx
  int nummacroparams; // eax
  char *macrobuffer; // esi
  char **macroparam; // edi
  unsigned int v9; // esi
  script_t *pmacro; // [esp+4h] [ebp-4h]
  int i; // [esp+10h] [ebp+8h]

  if ( *macroname != 36 )
    return 0;
  v2 = 0;
  v3 = nummacros == 0;
  if ( nummacros > 0 )
  {
    do
    {
      if ( _V_stricmp(s1: macrolist[v2]->filename, s2: macroname + 1) == 0 )
        break;
      ++v2;
    }
    while ( v2 < nummacros );
    v3 = v2 == nummacros;
  }
  if ( v3 )
    return 0;
  v4 = macrolist[v2];
  v5 = script + 2;
  pmacro = v4;
  if ( &script[2] == (script_t *)token )
    _Error(a1: "script file exceeded MAX_INCLUDES");
  nummacroparams = v4->nummacroparams;
  macrobuffer = v5->macrobuffer;
  v5->nummacroparams = nummacroparams;
  i = 0;
  if ( nummacroparams > 0 )
  {
    macroparam = v5->macroparam;
    do
    {
      GetToken(crossline: 0);
      strcpy(macrobuffer, token);
      *macroparam = *(char **)((char *)macroparam + (char *)pmacro - (char *)v5);
      macroparam[64] = macrobuffer;
      macrobuffer += strlen(token) + 1;
      if ( macrobuffer >= (char *)v5->macroparam )
        _Error(a1: "Macro buffer overflow\n");
      ++macroparam;
      ++i;
    }
    while ( i < v5->nummacroparams );
    v4 = pmacro;
  }
  script = (script_t *)strcpy(v5->filename, v4->filename);
  v9 = v4->end_p - v4->buffer;
  script->buffer = (char *)MemAlloc_Alloc(nSize: v9 + 1);
  memcpy(dst: (unsigned __int8 *)script->buffer, src: (unsigned __int8 *)v4->buffer, count: v9);
  v4->buffer[v9] = 0;
  script->script_p = script->buffer;
  script->end_p = &script->buffer[v9];
  script->line = v4->line;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004269E0
// Name: bool ExpandMacroToken(char __near * __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl ExpandMacroToken(char **token_p)
{
  char *script_p; // eax
  _BYTE *v2; // ebx
  char v3; // al
  script_t *v5; // eax
  int v6; // esi
  int v7; // edi
  bool v8; // zf
  const char *v9; // edx
  unsigned int v10; // eax
  _BYTE *v11; // esi
  char v12; // cl
  char *s2; // [esp+0h] [ebp-4h]

  if ( script->nummacroparams == 0 )
    return 0;
  script_p = script->script_p;
  if ( *script_p != 36 )
    return 0;
  v2 = script_p + 1;
  s2 = script_p + 1;
  v3 = script_p[1];
  if ( v3 <= 32 )
  {
LABEL_6:
    if ( *v2 != 36 )
      return 0;
  }
  else
  {
    while ( v3 != 36 )
    {
      v3 = *++v2;
      if ( v3 <= 32 )
        goto LABEL_6;
    }
  }
  *v2 = 0;
  v5 = script;
  v6 = 0;
  if ( script->nummacroparams <= 0 )
    goto LABEL_13;
  v7 = 5136;
  do
  {
    v8 = _V_stricmp(s1: *(const char **)&v5->filename[v7], s2) == 0;
    v5 = script;
    if ( v8 )
      break;
    ++v6;
    v7 += 4;
  }
  while ( v6 < script->nummacroparams );
  if ( v6 >= script->nummacroparams )
  {
LABEL_13:
    _Error(a1: "unknown macro token \"%s\" in %s\n", s2, v5->filename);
    v5 = script;
  }
  v9 = v5->macrovalue[v6];
  v10 = strlen(v9);
  v11 = *token_p;
  do
  {
    v12 = *v9;
    *v11++ = *v9++;
  }
  while ( v12 != 0 );
  *token_p += v10;
  script->script_p = v2 + 1;
  if ( script->script_p >= script->end_p )
    _Error(a1: "Macro expand overflow\n");
  if ( *token_p >= (char *)&nummacros )
    _Error(a1: "Token too large on line %i\n", scriptline);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00426B10
// Name: void PushMemoryScript(char __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl PushMemoryScript(char *pszBuffer, int nSize)
{
  script_t *v2; // eax
  script_t *v3; // eax

  v2 = script;
  if ( script == nullptr )
    v2 = scriptstack;
  v3 = v2 + 1;
  script = v3;
  if ( v3 == (script_t *)token )
  {
    _Error(a1: "script file exceeded MAX_INCLUDES");
    v3 = script;
  }
  *(_QWORD *)v3->filename = *(_QWORD *)aMemoryB;
  strcpy(&script->filename[8], "uffer");
  script->buffer = pszBuffer;
  script->line = 1;
  script->script_p = script->buffer;
  script->end_p = &script->buffer[nSize];
  endofscript = 0;
  tokenready = 0;
}

//------------------------------------------------------------------------------
// Address: 0x00426BD0
// Name: bool PopMemoryScript(void)
// Source: json
//------------------------------------------------------------------------------
char __cdecl PopMemoryScript()
{
  if ( _V_stricmp(s1: script->filename, s2: aMemoryB) != 0 )
    return 0;
  if ( script == scriptstack )
  {
    endofscript = 1;
    return 0;
  }
  --script;
  scriptline = script->line;
  endofscript = 0;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00426C30
// Name: void UnGetToken(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl UnGetToken()
{
  tokenready = 1;
}

//------------------------------------------------------------------------------
// Address: 0x00426C40
// Name: int EndOfScript(int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl EndOfScript(int crossline)
{
  if ( crossline == 0 )
    _Error(a1: "Line %i is incomplete\n", scriptline);
  if ( strcmp(script->filename, aMemoryB) == 0
    || (free(pMem: script->buffer), script->buffer = nullptr, script == &scriptstack[1]) )
  {
    endofscript = 1;
    return 0;
  }
  else
  {
    --script;
    scriptline = script->line;
    return GetToken(crossline);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00426D00
// Name: int TokenAvailable(void)
// Source: json
//------------------------------------------------------------------------------
int __cdecl TokenAvailable()
{
  char *script_p; // eax
  char *end_p; // edx
  char v3; // cl
  char v4; // cl

  if ( tokenready != 0 )
    return 1;
  script_p = script->script_p;
  end_p = script->end_p;
  if ( script_p < end_p )
  {
    v3 = *script_p;
    if ( *script_p > 32 )
    {
LABEL_8:
      v4 = *script_p;
      if ( *script_p != 59 && v4 != 35 && (v4 != 47 || script_p[1] != 47) )
        return 1;
    }
    else
    {
      while ( v3 != 10 )
      {
        if ( ++script_p == end_p )
          break;
        v3 = *script_p;
        if ( *script_p > 32 )
          goto LABEL_8;
      }
    }
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00426D60
// Name: int GetTokenizerStatus(char __near * __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl GetTokenizerStatus(char **pFilename, int *pLine)
{
  script_t *v2; // eax

  v2 = script;
  if ( script == nullptr || script->script_p >= script->end_p )
    return 0;
  if ( pFilename != nullptr )
  {
    *pFilename = (char *)script;
    v2 = script;
  }
  if ( pLine != nullptr )
    *pLine = v2->line;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00426DB0
// Name: public: virtual bool CScriptLib::DoesFileExist(char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CScriptLib::DoesFileExist(CScriptLib *this, const char *pFilename)
{
  return g_pFullFileSystem->FileExists(this: &g_pFullFileSystem->IBaseFileSystem, a2: pFilename, a3: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x00426DD0
// Name: public: virtual bool CScriptLib::ReadFileToBuffer(char const __near *,class CUtlBuffer __near &,bool,bool)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CScriptLib::ReadFileToBuffer(
        CScriptLib *this,
        const char *pSourceName,
        CUtlBuffer *buffer,
        bool bText,
        bool bNoOpenFailureWarning)
{
  int *v5; // eax
  const char *v6; // eax

  if ( g_pFullFileSystem->ReadFile(
         this: &g_pFullFileSystem->IBaseFileSystem,
         a2: pSourceName,
         a3: nullptr,
         a4: buffer,
         a5: 0,
         a6: 0,
         a7: nullptr) )
  {
    if ( bText )
      CUtlBuffer::SetBufferType(this: buffer, bIsText: true, bContainsCRLF: true);
    else
      CUtlBuffer::SetBufferType(this: buffer, bIsText: false, bContainsCRLF: false);
    return 1;
  }
  else
  {
    if ( !bNoOpenFailureWarning )
    {
      v5 = _errno();
      v6 = strerror(errnum: *v5);
      _Msg(a1: "ReadFileToBuffer(): Error opening %s: %s\n", pSourceName, v6);
    }
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00426E50
// Name: public: virtual bool CScriptLib::WriteBufferToFile(char const __near *,class CUtlBuffer __near &,enum DiskWriteMode_t)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CScriptLib::WriteBufferToFile(
        CScriptLib *this,
        const char *pTargetName,
        CUtlBuffer *buffer,
        DiskWriteMode_t writeMode)
{
  _BYTE *v5; // eax
  _BYTE *v6; // esi
  _BYTE *v7; // eax
  char dirPath[260]; // [esp+8h] [ebp-104h] BYREF

  strcpy(dirPath, pTargetName);
  strchr(string: (unsigned __int8 *)dirPath, chr: 0x5Cu);
  v6 = v5;
  if ( v5 != nullptr )
  {
    while ( 1 )
    {
      strchr(string: v6 + 1, chr: 0x5Cu);
      v6 = v7;
      if ( v7 == nullptr )
        break;
      *v7 = 0;
      _mkdir(path: dirPath);
      *v6 = 92;
    }
  }
  return writeMode != WRITE_TO_DISK_ALWAYS
      && (writeMode != WRITE_TO_DISK_UPDATE || !this->DoesFileExist(this, a2: pTargetName))
      || g_pFullFileSystem->WriteFile(
           this: &g_pFullFileSystem->IBaseFileSystem,
           a2: pTargetName,
           a3: nullptr,
           a4: buffer);
}

//------------------------------------------------------------------------------
// Address: 0x00426F10
// Name: public: virtual int CScriptLib::CompareFileTime(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CScriptLib::CompareFileTime(CScriptLib *this, const char *pFilenameA, const char *pFilenameB)
{
  unsigned int v3; // esi
  unsigned int v4; // eax
  bool v5; // cf

  v3 = g_pFullFileSystem->GetFileTime(this: &g_pFullFileSystem->IBaseFileSystem, a2: pFilenameA, a3: nullptr);
  v4 = g_pFullFileSystem->GetFileTime(this: &g_pFullFileSystem->IBaseFileSystem, a2: pFilenameB, a3: nullptr);
  if ( v3 == -1 )
    v3 = 0;
  if ( v4 == -1 )
    return v3 != 0;
  v5 = v4 < v3;
  if ( v4 <= v3 )
    return v5;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00426F70
// Name: public: virtual char __near * CScriptLib::MakeTemporaryFilename(char const __near *,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CScriptLib::MakeTemporaryFilename(CScriptLib *this, const char *pchModPath, char *pPath, int pathSize)
{
  char *v4; // eax
  char *v5; // esi

  v4 = _tempnam(dir: pchModPath, pfx: "mgd_");
  v5 = v4;
  if ( *v4 == 92 )
    v5 = v4 + 1;
  if ( v5[strlen(v5) - 1] == 46 )
    v5[strlen(v5) - 1] = 0;
  V_snprintf(pDest: pPath, maxLen: pathSize, pFormat: "%s.tmp", v5);
  free(pMem: v5);
  return pPath;
}

//------------------------------------------------------------------------------
// Address: 0x00426FE0
// Name: void DefineMacro(char __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DefineMacro(char *macroname)
{
  script_t *v1; // edi
  char *script_p; // esi
  char *macrobuffer; // ebx
  unsigned int v4; // ebx
  unsigned __int8 *v5; // eax
  int v6; // eax
  script_t *v7; // edx

  v1 = (script_t *)MemAlloc_Alloc(nSize: 0x1614u);
  strcpy(v1->filename, macroname);
  v1->line = script->line;
  v1->nummacroparams = 0;
  script_p = script->script_p;
  macrobuffer = v1->macrobuffer;
  while ( TokenAvailable() != 0 )
  {
    GetToken(crossline: 0);
    if ( token[0] == 92 && pModelName == 92 )
      break;
    script_p = script->script_p;
    v1->macroparam[v1->nummacroparams++] = macrobuffer;
    strcpy(macrobuffer, token);
    macrobuffer += strlen(token) + 1;
    if ( macrobuffer >= (char *)v1->macroparam )
      _Error(a1: "Macro buffer overflow\n");
  }
  for ( script->script_p = script_p; *script_p != 0; ++script_p )
  {
    if ( *script_p == 10 )
      break;
    if ( *script_p == 92 && script_p[1] == 92 )
    {
      do
      {
        if ( *script_p == 10 )
          break;
        *script_p++ = 32;
      }
      while ( *script_p != 0 );
      if ( *script_p == 0 )
        break;
    }
  }
  v4 = script_p - script->script_p;
  v5 = (unsigned __int8 *)MemAlloc_Alloc(nSize: v4 + 1);
  v1->buffer = (char *)v5;
  memcpy(dst: v5, src: (unsigned __int8 *)script->script_p, count: v4);
  v1->buffer[v4] = 0;
  v1->end_p = &v1->buffer[v4];
  v6 = nummacros;
  v7 = script;
  macrolist[nummacros] = v1;
  nummacros = v6 + 1;
  v7->script_p = script_p;
}

//------------------------------------------------------------------------------
// Address: 0x00427180
// Name: bool ExpandVariableToken(char __near * __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl ExpandVariableToken(char **token_p)
{
  char *script_p; // ebx
  const char *v2; // ebx
  char *v3; // esi
  char v4; // al
  int v6; // esi
  int v7; // edi
  void (*v8)(const char *, ...); // ebx
  char *value; // edi
  unsigned int v10; // eax
  char *v11; // edx
  _BYTE *v12; // esi
  char v13; // cl
  const char *v14; // [esp-10h] [ebp-18h]
  char *cp; // [esp+4h] [ebp-4h]

  script_p = script->script_p;
  if ( *script_p != 36 )
    return 0;
  v2 = script_p + 1;
  v3 = (char *)v2;
  v4 = *v2;
  cp = (char *)v2;
  if ( *v2 <= 32 )
  {
LABEL_6:
    if ( *v3 != 36 )
      return 0;
  }
  else
  {
    while ( v4 != 36 )
    {
      v4 = *++v3;
      if ( v4 <= 32 )
      {
        cp = v3;
        goto LABEL_6;
      }
    }
    cp = v3;
  }
  v6 = v3 - v2;
  v7 = 0;
  v2[v6] = 0;
  if ( g_definevariable.m_Size <= 0 )
    goto LABEL_14;
  while ( V_strnicmp(s1: g_definevariable.m_Memory.m_pMemory[v7].param, s2: v2, n: v6) != 0 )
  {
    if ( ++v7 >= g_definevariable.m_Size )
      goto LABEL_14;
  }
  if ( v7 < g_definevariable.m_Size )
  {
    v8 = (void (*)(const char *, ...))_Error;
  }
  else
  {
LABEL_14:
    v14 = v2;
    v8 = (void (*)(const char *, ...))_Error;
    _Error(a1: "unknown variable token \"%s\" in %s\n", v14, script->filename);
  }
  value = g_definevariable.m_Memory.m_pMemory[v7].value;
  v10 = strlen(value);
  v11 = value;
  v12 = *token_p;
  do
  {
    v13 = *v11;
    *v12++ = *v11++;
  }
  while ( v13 != 0 );
  *token_p += v10;
  script->script_p = cp + 1;
  if ( script->script_p >= script->end_p )
    v8(a1: "Macro expand overflow\n");
  if ( *token_p >= (char *)&nummacros )
    v8(a1: "Token too large on line %i\n", scriptline);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00427390
// Name: void DefineVariable(char __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DefineVariable(char *variablename)
{
  char *v1; // eax
  char *v2; // eax
  char *v3; // ecx
  char v4; // dl
  variable_t v; // [esp+8h] [ebp-8h] BYREF

  if ( variablename != nullptr
    && (v1 = (char *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: strlen(variablename) + 1)) != nullptr )
  {
    strcpy(v1, variablename);
  }
  else
  {
    v1 = nullptr;
  }
  v.param = v1;
  GetToken(crossline: 0);
  v2 = (char *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: strlen(token) + 1);
  if ( v2 != nullptr )
  {
    v3 = v2;
    do
    {
      v4 = v3[token - v2];
      *v3++ = v4;
    }
    while ( v4 != 0 );
  }
  else
  {
    v2 = nullptr;
  }
  v.value = v2;
  CUtlVector<variable_t,CUtlMemory<variable_t,int>>::InsertBefore(
    this: &g_definevariable,
    elem: g_definevariable.m_Size,
    src: &v);
}

//------------------------------------------------------------------------------
// Address: 0x00427450
// Name: int GetToken(int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl GetToken(int crossline)
{
  script_t *v1; // eax
  char *script_p; // ecx
  char v3; // dl
  script_t *v4; // eax
  char *v5; // ecx
  char *v6; // edx
  char v7; // cl
  char *v8; // ecx
  char v9; // dl
  script_t *v10; // eax
  char *v11; // edx
  script_t *v12; // eax
  int line; // edx
  char v14; // cl
  char *v15; // esi
  script_t *v16; // eax
  char i; // cl
  char *v18; // esi
  char *v19; // ecx
  char *token_p; // [esp+Ch] [ebp-4h] BYREF

  if ( tokenready != 0 )
  {
LABEL_54:
    tokenready = 0;
    return 1;
  }
  else
  {
    while ( 1 )
    {
      v1 = script;
      if ( script->script_p >= script->end_p )
        return EndOfScript(crossline);
      tokenready = 0;
      while ( 1 )
      {
        while ( 1 )
        {
          if ( *v1->script_p <= 32 )
          {
            do
            {
              script_p = v1->script_p;
              if ( script_p >= v1->end_p )
                return EndOfScript(crossline);
              v3 = *script_p;
              v1->script_p = script_p + 1;
              if ( v3 == 10 )
              {
                if ( crossline == 0 )
                  _Error(a1: "Line %i is incomplete\n", scriptline);
                v4 = script;
                ++script->line;
                scriptline = v4->line;
              }
              v1 = script;
            }
            while ( *script->script_p <= 32 );
          }
          v5 = v1->script_p;
          if ( v5 >= v1->end_p )
            return EndOfScript(crossline);
          v6 = v1->script_p;
          v7 = *v5;
          if ( v7 != 59 && v7 != 35 )
          {
            if ( v7 != 47 )
              goto LABEL_30;
            if ( v6[1] != 47 )
              break;
          }
          if ( crossline == 0 )
          {
            _Error(a1: "Line %i is incomplete\n", scriptline);
            v1 = script;
          }
          if ( *v1->script_p != 10 )
          {
            do
            {
              ++v1->script_p;
              v1 = script;
              v11 = script->script_p;
              if ( v11 >= script->end_p )
                return EndOfScript(crossline);
            }
            while ( *v11 != 10 );
          }
          ++v1->script_p;
          v12 = script;
          ++script->line;
          line = v12->line;
          v1 = script;
          scriptline = line;
        }
        if ( v6[1] != 42 )
          break;
        v1->script_p += 2;
        while ( 1 )
        {
          v8 = script->script_p;
          if ( *v8 == 42 && v8[1] == 47 )
            break;
          v9 = *v8;
          script->script_p = v8 + 1;
          if ( v9 != 10 )
          {
            v10 = script;
            if ( script->script_p >= script->end_p )
              return EndOfScript(crossline);
            ++script->line;
            scriptline = v10->line;
          }
        }
        script->script_p += 2;
        v1 = script;
      }
LABEL_30:
      v14 = *v6;
      v15 = token;
      token_p = token;
      if ( v14 == 34 )
      {
        ++v1->script_p;
        v16 = script;
        for ( i = *script->script_p; i != 34; i = *v16->script_p )
        {
          *v15 = i;
          ++script->script_p;
          v16 = script;
          ++v15;
          if ( script->script_p == script->end_p )
            break;
          if ( v15 == (char *)&nummacros )
          {
            _Error(a1: "Token too large on line %i\n", scriptline);
            v16 = script;
          }
        }
        ++v16->script_p;
      }
      else
      {
        for ( ; v14 > 32; v14 = *script->script_p )
        {
          if ( v14 == 59 )
            break;
          if ( ExpandMacroToken(&token_p) != 0 || ExpandVariableToken(&token_p) != 0 )
          {
            v15 = token_p;
          }
          else
          {
            v18 = token_p;
            *token_p = *script->script_p++;
            v19 = script->script_p;
            v15 = v18 + 1;
            token_p = v15;
            if ( v19 == script->end_p )
              break;
            if ( v15 == (char *)&nummacros )
              _Error(a1: "Token too large on line %i\n", scriptline);
          }
        }
      }
      *v15 = 0;
      if ( _V_stricmp(s1: token, s2: "$include") != 0 )
      {
        if ( _V_stricmp(s1: token, s2: "$definemacro") != 0 )
        {
          if ( _V_stricmp(s1: token, s2: "$definevariable") != 0 )
          {
            if ( AddMacroToStack(macroname: token) == 0 )
              return 1;
          }
          else
          {
            GetToken(crossline: 0);
            DefineVariable(variablename: token);
          }
        }
        else
        {
          GetToken(crossline: 0);
          DefineMacro(macroname: token);
        }
      }
      else
      {
        GetToken(crossline: 0);
        AddScriptToStack(a1: 1, filename: token, pathMode: SCRIPT_USE_ABSOLUTE_PATH);
      }
      if ( tokenready != 0 )
        goto LABEL_54;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00427850
// Name: int GetExprToken(int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl GetExprToken(int crossline)
{
  script_t *v2; // eax
  char *v3; // edx
  char v4; // dl
  script_t *v5; // eax
  char *script_p; // ecx
  char *v7; // edx
  char v8; // cl
  char *v9; // edx
  char *v10; // esi
  script_t *v11; // eax
  bool v12; // zf
  script_t *v13; // eax
  char v14; // cl
  char *v15; // ecx
  script_t *v16; // eax
  script_t *v17; // eax

  if ( tokenready != 0 )
  {
    tokenready = 0;
    return 1;
  }
  else
  {
    v2 = script;
    if ( script->script_p < script->end_p )
    {
      tokenready = 0;
      while ( *v2->script_p > 32 )
      {
LABEL_13:
        script_p = v2->script_p;
        if ( script_p >= v2->end_p )
          return EndOfScript(crossline);
        v7 = v2->script_p;
        v8 = *script_p;
        if ( v8 != 59 && v8 != 35 && (v8 != 47 || v7[1] != 47) )
        {
          v10 = token;
          if ( *v7 == 34 )
          {
            ++v2->script_p;
            v11 = script;
            while ( *v11->script_p != 34 )
            {
              *v10 = *v11->script_p++;
              v11 = script;
              ++v10;
              if ( script->script_p == script->end_p )
                break;
              if ( v10 == (char *)&nummacros )
              {
                _Error(a1: "Token too large on line %i\n", scriptline);
                v11 = script;
              }
            }
LABEL_31:
            ++v11->script_p;
          }
          else
          {
            v12 = isalpha(c: *v7) == 0;
            v13 = script;
            if ( !v12 || (v14 = *script->script_p) == 95 )
            {
              while ( 1 )
              {
                v12 = isalnum(c: *v13->script_p) == 0;
                v17 = script;
                if ( v12 && *script->script_p != 95 )
                  break;
                *v10 = *script->script_p;
                ++v17->script_p;
                v13 = script;
                ++v10;
                if ( script->script_p == script->end_p )
                  break;
                if ( v10 == (char *)&nummacros )
                {
                  _Error(a1: "Token too large on line %i\n", scriptline);
                  v13 = script;
                }
              }
            }
            else
            {
              v12 = isdigit(c: v14) == 0;
              v11 = script;
              if ( v12 )
              {
                v15 = script->script_p;
                if ( *v15 != 46 )
                {
                  token[0] = *v15;
                  v10 = &pModelName;
                  goto LABEL_31;
                }
              }
              while ( 1 )
              {
                v12 = isdigit(c: *v11->script_p) == 0;
                v16 = script;
                if ( v12 && *script->script_p != 46 )
                  break;
                *v10 = *script->script_p;
                ++v16->script_p;
                v11 = script;
                ++v10;
                if ( script->script_p == script->end_p )
                  break;
                if ( v10 == (char *)&nummacros )
                {
                  _Error(a1: "Token too large on line %i\n", scriptline);
                  v11 = script;
                }
              }
            }
          }
          *v10 = 0;
          if ( _V_stricmp(s1: token, s2: "$include") != 0 )
            return 1;
          GetToken(crossline: 0);
          AddScriptToStack(a1: (int)_Error, filename: token, pathMode: SCRIPT_USE_ABSOLUTE_PATH);
          return GetToken(crossline);
        }
        if ( crossline == 0 )
        {
          _Error(a1: "Line %i is incomplete\n", scriptline);
          v2 = script;
        }
        if ( *v2->script_p != 10 )
        {
          do
          {
            ++v2->script_p;
            v2 = script;
            v9 = script->script_p;
            if ( v9 >= script->end_p )
              return EndOfScript(crossline);
          }
          while ( *v9 != 10 );
        }
        ++v2->script_p;
        v2 = script;
      }
      while ( 1 )
      {
        v3 = v2->script_p;
        if ( v3 >= v2->end_p )
          break;
        v4 = *v3;
        ++v2->script_p;
        if ( v4 == 10 )
        {
          if ( crossline == 0 )
            _Error(a1: "Line %i is incomplete\n", scriptline);
          v5 = script;
          ++script->line;
          scriptline = v5->line;
        }
        v2 = script;
        if ( *script->script_p > 32 )
          goto LABEL_13;
      }
    }
    return EndOfScript(crossline);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00427D20
// Name: private: int CScriptLib::GetFileList(char const __near *,char const __near *,class CUtlVector<struct fileList_t,class CUtlMemory<struct fileList_t,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CScriptLib::GetFileList(
        CScriptLib *this,
        const char *pDirPath,
        const char *pPattern,
        CUtlVector<fileList_t,CUtlMemory<fileList_t,int> > *fileList)
{
  unsigned int v5; // kr00_4
  int v6; // eax
  char v7; // cl
  char *v8; // edi
  char v9; // al
  unsigned int v10; // eax
  char *v11; // edi
  char v12; // cl
  int v13; // esi
  int v15; // eax
  char v16; // cl
  unsigned int v17; // eax
  char *v18; // edi
  char v19; // cl
  char *v20; // edi
  char *v21; // esi
  char v22; // cl
  int m_Size; // eax
  int v24; // esi
  char v25; // [esp+Bh] [ebp-435h] BYREF
  char fileName[260]; // [esp+Ch] [ebp-434h] BYREF
  char fullPath[260]; // [esp+110h] [ebp-330h] BYREF
  _finddata64i32_t findData; // [esp+214h] [ebp-22Ch] BYREF
  char sourcePath[260]; // [esp+33Ch] [ebp-104h] BYREF
  int h; // [esp+448h] [ebp+8h]
  char bFindDirs_3; // [esp+453h] [ebp+13h]

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
  v5 = strlen(sourcePath);
  if ( v5 != 0 )
  {
    if ( findData.name[v5 + 259] != 92 )
    {
      sourcePath[v5] = 92;
      sourcePath[v5 + 1] = 0;
    }
  }
  else
  {
    strcpy(sourcePath, ".\\");
  }
  v6 = 0;
  do
  {
    v7 = sourcePath[v6];
    fullPath[v6++] = v7;
  }
  while ( v7 != 0 );
  if ( *pPattern != 92 || pPattern[1] != 0 )
  {
    bFindDirs_3 = 0;
    v10 = strlen(pPattern) + 1;
    v11 = &fileName[259];
    do
      v12 = *++v11;
    while ( v12 != 0 );
    qmemcpy(v11, pPattern, v10);
  }
  else
  {
    bFindDirs_3 = 1;
    v8 = &fileName[259];
    do
      v9 = *++v8;
    while ( v9 != 0 );
    strcpy(v8, "*");
  }
  v13 = _findfirst64i32(szWild: fullPath, pfd: &findData);
  h = v13;
  if ( v13 == -1 )
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
      v15 = 0;
      do
      {
        v16 = sourcePath[v15];
        fileName[v15++] = v16;
      }
      while ( v16 != 0 );
      v17 = strlen(findData.name) + 1;
      v18 = &v25;
      do
        v19 = *++v18;
      while ( v19 != 0 );
      qmemcpy(v18, findData.name, 4 * (v17 >> 2));
      v21 = &findData.name[4 * (v17 >> 2)];
      v20 = &v18[4 * (v17 >> 2)];
      v22 = v17;
      m_Size = fileList->m_Size;
      qmemcpy(v20, v21, v22 & 3);
      v24 = CUtlVector<fileList_t,CUtlMemory<fileList_t,int>>::InsertBefore(this: fileList, elem: m_Size);
      CUtlString::Set(this: &fileList->m_Memory.m_pMemory[v24].fileName, pValue: fileName);
      fileList->m_Memory.m_pMemory[v24].timeWrite = findData.time_write;
      v13 = h;
    }
  }
  while ( _findnext64i32(hFile: v13, pfd: &findData) == 0 );
  _findclose(hFile: v13);
  return fileList->m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x00427FE0
// Name: public: virtual void CScriptLib::DeleteTemporaryFiles(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CScriptLib::DeleteTemporaryFiles(CScriptLib *this, const char *pFileMask)
{
  char *v2; // eax
  char *v3; // edx
  char v4; // cl
  unsigned int v5; // eax
  char *v6; // edi
  char v7; // cl
  int (__thiscall *FindFiles)(struct CScriptLib *, char *, bool, CUtlVector<fileList_t,CUtlMemory<fileList_t,int> > *); // edx
  int v9; // esi
  int v10; // edi
  const char *v11; // eax
  fileList_t *m_pMemory; // eax
  char v13; // [esp+3h] [ebp-11Dh] BYREF
  char tempPath[260]; // [esp+4h] [ebp-11Ch] BYREF
  CScriptLib *v15; // [esp+108h] [ebp-18h]
  CUtlVector<fileList_t,CUtlMemory<fileList_t,int> > fileList; // [esp+10Ch] [ebp-14h] BYREF

  v15 = this;
  v2 = getenv(option: "temp");
  if ( v2 != nullptr || (v2 = getenv(option: "tmp")) != nullptr )
  {
    v3 = (char *)(tempPath - v2);
    do
    {
      v4 = *v2;
      v2[(_DWORD)v3] = *v2;
      ++v2;
    }
    while ( v4 != 0 );
    V_AppendSlash(pStr: tempPath, strSize: 260);
    v5 = strlen(pFileMask) + 1;
    v6 = &v13;
    do
      v7 = *++v6;
    while ( v7 != 0 );
    qmemcpy(v6, pFileMask, v5);
    FindFiles = v15->FindFiles;
    memset(&fileList, 0, sizeof(fileList));
    FindFiles(this: v15, a2: tempPath, a3: false, a4: &fileList);
    v9 = 0;
    if ( fileList.m_Size > 0 )
    {
      v10 = 0;
      do
      {
        v11 = CUtlString::operator char const *(this: &fileList.m_Memory.m_pMemory[v10].fileName);
        unlink(path: v11);
        ++v9;
        ++v10;
      }
      while ( v9 < fileList.m_Size );
    }
    CUtlVector<fileList_t,CUtlMemory<fileList_t,int>>::RemoveAll(this: &fileList);
    m_pMemory = fileList.m_Memory.m_pMemory;
    if ( fileList.m_Memory.m_nGrowSize >= 0 )
    {
      if ( fileList.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: fileList.m_Memory.m_pMemory);
        m_pMemory = nullptr;
        fileList.m_Memory.m_pMemory = nullptr;
      }
      fileList.m_Memory.m_nAllocationCount = 0;
    }
    fileList.m_pElements = m_pMemory;
    if ( fileList.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00428110
// Name: private: void CScriptLib::RecurseFileTree_r(char const __near *,int,class CUtlVector<class CUtlString,class CUtlMemory<class CUtlString,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CScriptLib::RecurseFileTree_r(
        CScriptLib *this,
        const char *pDirPath,
        int depth,
        CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *dirList)
{
  fileList_t *i; // ebx
  int v5; // eax
  int v6; // eax
  fileList_t *m_pMemory; // edi
  const char *v8; // eax
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CUtlString *v11; // ecx
  int v12; // eax
  int v13; // edi
  CUtlString *v14; // ecx
  CUtlVector<fileList_t,CUtlMemory<fileList_t,int> > fileList; // [esp+Ch] [ebp-18h] BYREF
  CScriptLib *v16; // [esp+20h] [ebp-4h]

  i = nullptr;
  v16 = this;
  memset(&fileList, 0, sizeof(fileList));
  v5 = CScriptLib::GetFileList(this, pDirPath, pPattern: "\\", &fileList);
  if ( v5 != 0 )
  {
    if ( v5 > 0 )
    {
      m_pMemory = fileList.m_Memory.m_pMemory;
      for ( i = (fileList_t *)v5; i != nullptr; i = (fileList_t *)((char *)i - 1) )
      {
        v8 = CUtlString::operator char const *(this: &m_pMemory->fileName);
        CScriptLib::RecurseFileTree_r(this: v16, pDirPath: v8, depth: depth + 1, dirList);
        ++m_pMemory;
      }
    }
    m_Size = dirList->m_Size;
    m_nAllocationCount = dirList->m_Memory.m_nAllocationCount;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<ActiveLayer_t<QAngle>,int>::Grow(
        this: (CUtlMemory<ActiveLayer_t<CUtlSymbolLarge>,int> *)dirList,
        num: m_Size - m_nAllocationCount + 1);
    ++dirList->m_Size;
    v11 = dirList->m_Memory.m_pMemory;
    v12 = dirList->m_Size - m_Size - 1;
    dirList->m_pElements = dirList->m_Memory.m_pMemory;
    if ( v12 > (int)i )
      _V_memmove(dest: &v11[m_Size + 1], src: &v11[m_Size], count: 16 * v12);
    v13 = m_Size;
    v14 = &dirList->m_Memory.m_pMemory[v13];
    if ( v14 != nullptr )
      CUtlString::CUtlString(this: v14);
    CUtlString::Set(this: &dirList->m_Memory.m_pMemory[v13], pValue: pDirPath);
    CUtlVector<fileList_t,CUtlMemory<fileList_t,int>>::RemoveAll(this: &fileList);
    if ( fileList.m_Memory.m_nGrowSize >= (int)i && fileList.m_Memory.m_pMemory != i )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: fileList.m_Memory.m_pMemory);
  }
  else
  {
    v6 = CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>::InsertBefore(this: dirList, elem: dirList->m_Size);
    CUtlString::Set(this: &dirList->m_Memory.m_pMemory[v6], pValue: pDirPath);
    CUtlVector<fileList_t,CUtlMemory<fileList_t,int>>::~CUtlVector<fileList_t,CUtlMemory<fileList_t,int>>(this: &fileList);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00428230
// Name: public: virtual int CScriptLib::FindFiles(char __near *,bool,class CUtlVector<struct fileList_t,class CUtlMemory<struct fileList_t,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CScriptLib::FindFiles(
        CScriptLib *this,
        char *pFileMask,
        bool bRecurse,
        CUtlVector<fileList_t,CUtlMemory<fileList_t,int> > *fileList)
{
  CScriptLib *v4; // edi
  char *v5; // edi
  char v6; // al
  unsigned int v7; // eax
  char *v8; // edi
  char v9; // cl
  int m_nGrowSize; // esi
  fileList_t *m_pMemory; // eax
  const char *v13; // eax
  CUtlVector<fileList_t,CUtlMemory<fileList_t,int> > *v14; // esi
  int m_Size; // edi
  int inserted; // eax
  fileList_t *v17; // edi
  int v18; // ebx
  CUtlString *p_fileName; // esi
  int timeWrite_high; // eax
  bool v21; // zf
  CUtlString *v22; // eax
  unsigned int v23; // [esp-8h] [ebp-34Ch]
  char extension[260]; // [esp+8h] [ebp-33Ch] BYREF
  char dirPath[260]; // [esp+10Ch] [ebp-238h] BYREF
  char pattern[260]; // [esp+210h] [ebp-134h] BYREF
  CScriptLib *v27; // [esp+314h] [ebp-30h]
  int i; // [esp+318h] [ebp-2Ch]
  CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > dirList; // [esp+31Ch] [ebp-28h] BYREF
  CUtlVector<fileList_t,CUtlMemory<fileList_t,int> > tempList; // [esp+330h] [ebp-14h] BYREF
  char *pFileMaska; // [esp+34Ch] [ebp+8h]
  int bRecursea; // [esp+350h] [ebp+Ch]

  v4 = this;
  v27 = this;
  strcpy(dirPath, pFileMask);
  V_StripFilename(path: dirPath);
  V_FileBase(in: pFileMask, out: pattern, maxlen: 260);
  V_ExtractFileExtension(path: pFileMask, dest: extension, destSize: 260);
  if ( extension[0] != 0 )
  {
    v5 = &dirPath[259];
    do
      v6 = *++v5;
    while ( v6 != 0 );
    strcpy(v5, ".");
    v7 = strlen(extension) + 1;
    v8 = &dirPath[259];
    do
      v9 = *++v8;
    while ( v9 != 0 );
    qmemcpy(v8, extension, v7);
    v4 = v27;
  }
  if ( bRecurse )
  {
    memset(&tempList, 0, sizeof(tempList));
    memset(&dirList, 0, sizeof(dirList));
    CScriptLib::RecurseFileTree_r(this: v4, pDirPath: dirPath, depth: 0, &dirList);
    i = 0;
    if ( dirList.m_Size > 0 )
    {
      bRecursea = 0;
      while ( 1 )
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
          v23 = 24 * dirList.m_Size;
          if ( m_pMemory != nullptr )
            m_pMemory = (fileList_t *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v23);
          else
            m_pMemory = (fileList_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v23);
          tempList.m_Memory.m_pMemory = m_pMemory;
        }
        tempList.m_pElements = m_pMemory;
        v13 = CUtlString::operator char const *(this: &dirList.m_Memory.m_pMemory[bRecursea]);
        CScriptLib::GetFileList(this: v4, pDirPath: v13, pPattern: pattern, fileList: &tempList);
        v14 = fileList;
        m_Size = tempList.m_Size;
        inserted = CUtlVector<fileList_t,CUtlMemory<fileList_t,int>>::InsertMultipleBefore(
                     this: fileList,
                     elem: fileList->m_Size,
                     num: tempList.m_Size);
        if ( m_Size > 0 )
        {
          v17 = tempList.m_Memory.m_pMemory;
          v18 = inserted;
          pFileMaska = (char *)tempList.m_Size;
          while ( 1 )
          {
            p_fileName = &v14->m_Memory.m_pMemory[v18].fileName;
            CUtlString::operator=(this: p_fileName, src: &v17->fileName);
            p_fileName[1].m_Storage.m_Memory.m_pMemory = (unsigned __int8 *)v17->timeWrite;
            timeWrite_high = HIDWORD(v17->timeWrite);
            ++v17;
            ++v18;
            v21 = pFileMaska-- == (char *)1;
            p_fileName[1].m_Storage.m_Memory.m_nAllocationCount = timeWrite_high;
            if ( v21 )
              break;
            v14 = fileList;
          }
        }
        ++bRecursea;
        if ( ++i >= dirList.m_Size )
          break;
        v4 = v27;
      }
    }
    CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::RemoveAll(this: (CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int> > *)&dirList);
    v22 = dirList.m_Memory.m_pMemory;
    if ( dirList.m_Memory.m_nGrowSize >= 0 )
    {
      if ( dirList.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: dirList.m_Memory.m_pMemory);
        v22 = nullptr;
        dirList.m_Memory.m_pMemory = nullptr;
      }
      dirList.m_Memory.m_nAllocationCount = 0;
    }
    dirList.m_pElements = v22;
    if ( dirList.m_Memory.m_nGrowSize >= 0 )
    {
      if ( v22 != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v22);
        dirList.m_Memory.m_pMemory = nullptr;
      }
      dirList.m_Memory.m_nAllocationCount = 0;
    }
    CUtlVector<fileList_t,CUtlMemory<fileList_t,int>>::RemoveAll(this: &tempList);
    if ( tempList.m_Memory.m_nGrowSize < 0 )
    {
      return fileList->m_Size;
    }
    else
    {
      if ( tempList.m_Memory.m_pMemory != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: tempList.m_Memory.m_pMemory);
      return fileList->m_Size;
    }
  }
  else
  {
    CScriptLib::GetFileList(this: v4, pDirPath: dirPath, pPattern: pattern, fileList);
    return fileList->m_Size;
  }
}

} // namespace mdlcompile

// ============================================================
// Overlay from motionmapper (Missing functions)
// ============================================================
namespace motionmapper {

//------------------------------------------------------------------------------
// Address: 0x00409AE0
// Name: public: void CUtlMemory<class CUtlVector<int,class CUtlMemory<int,int>>,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<CUtlVector<int,CUtlMemory<int,int>>,int>::Grow(
        CUtlMemory<CUtlVector<int,CUtlMemory<int,int> >,int> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  CUtlVector<int,CUtlMemory<int,int> > *m_pMemory; // edx
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
      this->m_pMemory = (CUtlVector<int,CUtlMemory<int,int> > *)_g_pMemAlloc->Realloc_2(
                                                                  this: _g_pMemAlloc,
                                                                  a2: m_pMemory,
                                                                  a3: v7);
    else
      this->m_pMemory = (CUtlVector<int,CUtlMemory<int,int> > *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00409B80
// Name: public: void CUtlMemory<class Vector,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<Vector,int>::Grow(CUtlMemory<Vector,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  Vector *m_pMemory; // edx
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
    v7 = 12 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (Vector *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (Vector *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00409C20
// Name: public: void CUtlMemory<class CUtlSymbol,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<CUtlSymbol,int>::Grow(CUtlMemory<CUtlSymbol,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  CUtlSymbol *m_pMemory; // edx
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
        m_nAllocationCount = 16;
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
    v7 = 2 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (CUtlSymbol *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (CUtlSymbol *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00409D60
// Name: public: int CUtlVector<class CUtlVector<int,class CUtlMemory<int,int>>,class CUtlMemory<class CUtlVector<int,class CUtlMemory<int,int>>,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CUtlVector<int,CUtlMemory<int,int>>,CUtlMemory<CUtlVector<int,CUtlMemory<int,int>>,int>>::InsertMultipleBefore(
        CUtlVector<CUtlVector<int,CUtlMemory<int,int> >,CUtlMemory<CUtlVector<int,CUtlMemory<int,int> >,int> > *this,
        int elem,
        int num)
{
  int v3; // edi
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CUtlVector<int,CUtlMemory<int,int> > *m_pMemory; // ecx
  int v9; // eax
  int v10; // ecx
  CUtlVector<int,CUtlMemory<int,int> > *v11; // eax

  v3 = num;
  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<CUtlVector<int,CUtlMemory<int,int>>,int>::Grow(
      this: &this->m_Memory,
      num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v9 = this->m_Size - elem - num;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v9 <= 0 )
    goto LABEL_8;
  if ( num > 0 )
  {
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 20 * v9);
LABEL_8:
    if ( num > 0 )
    {
      v10 = elem;
      do
      {
        v11 = &this->m_Memory.m_pMemory[v10];
        if ( v11 != nullptr )
        {
          v11->m_Memory.m_pMemory = nullptr;
          v11->m_Memory.m_nAllocationCount = 0;
          v11->m_Memory.m_nGrowSize = 0;
          v11->m_Size = 0;
          v11->m_pElements = nullptr;
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
// Address: 0x00409E10
// Name: public: void CUtlVector<class CUtlVector<int,class CUtlMemory<int,int>>,class CUtlMemory<class CUtlVector<int,class CUtlMemory<int,int>>,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CUtlVector<int,CUtlMemory<int,int>>,CUtlMemory<CUtlVector<int,CUtlMemory<int,int>>,int>>::RemoveAll(
        CUtlVector<CUtlVector<int,CUtlMemory<int,int> >,CUtlMemory<CUtlVector<int,CUtlMemory<int,int> >,int> > *this)
{
  int v1; // ebx
  int v2; // eax
  char *v3; // esi
  void *v4; // eax
  int v5; // [esp+4h] [ebp-8h]
  CUtlVector<CUtlVector<int,CUtlMemory<int,int> >,CUtlMemory<CUtlVector<int,CUtlMemory<int,int> >,int> > *v6; // [esp+8h] [ebp-4h]

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
// Address: 0x0040B720
// Name: void DefaultScriptLoadedCallback(char const __near *,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DefaultScriptLoadedCallback()
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x0040B730
// Name: public: virtual bool CScriptLib::DoesFileExist(char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CScriptLib::DoesFileExist(CScriptLib *this, const char *pFilename)
{
  return g_pFullFileSystem->FileExists(this: &g_pFullFileSystem->IBaseFileSystem, a2: pFilename, a3: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x0040B750
// Name: public: virtual bool CScriptLib::ReadFileToBuffer(char const __near *,class CUtlBuffer __near &,bool,bool)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CScriptLib::ReadFileToBuffer(
        CScriptLib *this,
        const char *pSourceName,
        CUtlBuffer *buffer,
        bool bText,
        bool bNoOpenFailureWarning)
{
  int *v5; // eax
  const char *v6; // eax

  if ( g_pFullFileSystem->ReadFile(
         this: &g_pFullFileSystem->IBaseFileSystem,
         a2: pSourceName,
         a3: nullptr,
         a4: buffer,
         a5: 0,
         a6: 0,
         a7: nullptr) )
  {
    if ( bText )
      CUtlBuffer::SetBufferType(this: buffer, bIsText: true, bContainsCRLF: true);
    else
      CUtlBuffer::SetBufferType(this: buffer, bIsText: false, bContainsCRLF: false);
    return 1;
  }
  else
  {
    if ( !bNoOpenFailureWarning )
    {
      v5 = _errno();
      v6 = strerror(errnum: *v5);
      _Msg(a1: "ReadFileToBuffer(): Error opening %s: %s\n", pSourceName, v6);
    }
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040B7D0
// Name: public: virtual bool CScriptLib::WriteBufferToFile(char const __near *,class CUtlBuffer __near &,enum DiskWriteMode_t)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CScriptLib::WriteBufferToFile(
        CScriptLib *this,
        const char *pTargetName,
        CUtlBuffer *buffer,
        DiskWriteMode_t writeMode)
{
  _BYTE *v5; // eax
  _BYTE *v6; // esi
  _BYTE *v7; // eax
  char dirPath[260]; // [esp+8h] [ebp-104h] BYREF

  strcpy(dirPath, pTargetName);
  strchr(string: (unsigned __int8 *)dirPath, chr: 0x5Cu);
  v6 = v5;
  if ( v5 != nullptr )
  {
    while ( 1 )
    {
      strchr(string: v6 + 1, chr: 0x5Cu);
      v6 = v7;
      if ( v7 == nullptr )
        break;
      *v7 = 0;
      _mkdir(path: dirPath);
      *v6 = 92;
    }
  }
  return writeMode != WRITE_TO_DISK_ALWAYS
      && (writeMode != WRITE_TO_DISK_UPDATE || !this->DoesFileExist(this, a2: pTargetName))
      || g_pFullFileSystem->WriteFile(
           this: &g_pFullFileSystem->IBaseFileSystem,
           a2: pTargetName,
           a3: nullptr,
           a4: buffer);
}

//------------------------------------------------------------------------------
// Address: 0x0040B890
// Name: public: virtual int CScriptLib::CompareFileTime(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CScriptLib::CompareFileTime(CScriptLib *this, const char *pFilenameA, const char *pFilenameB)
{
  unsigned int v3; // esi
  unsigned int v4; // eax
  bool v5; // cf

  v3 = g_pFullFileSystem->GetFileTime(this: &g_pFullFileSystem->IBaseFileSystem, a2: pFilenameA, a3: nullptr);
  v4 = g_pFullFileSystem->GetFileTime(this: &g_pFullFileSystem->IBaseFileSystem, a2: pFilenameB, a3: nullptr);
  if ( v3 == -1 )
    v3 = 0;
  if ( v4 == -1 )
    return v3 != 0;
  v5 = v4 < v3;
  if ( v4 <= v3 )
    return v5;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0040B8F0
// Name: public: virtual char __near * CScriptLib::MakeTemporaryFilename(char const __near *,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CScriptLib::MakeTemporaryFilename(CScriptLib *this, const char *pchModPath, char *pPath, int pathSize)
{
  char *v4; // eax
  char *v5; // esi

  v4 = _tempnam(dir: pchModPath, pfx: "mgd_");
  v5 = v4;
  if ( *v4 == 92 )
    v5 = v4 + 1;
  if ( v5[strlen(v5) - 1] == 46 )
    v5[strlen(v5) - 1] = 0;
  V_snprintf(pDest: pPath, maxLen: pathSize, pFormat: "%s.tmp", v5);
  free(pMem: v5);
  return pPath;
}

//------------------------------------------------------------------------------
// Address: 0x0040B960
// Name: public: void CUtlMemory<struct fileList_t,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<fileList_t,int>::Grow(CUtlMemory<fileList_t,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  fileList_t *m_pMemory; // edx
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
      this->m_pMemory = (fileList_t *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (fileList_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040BA00
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
// Address: 0x0040BA90
// Name: public: CUtlVector<void (*)(class IConVar __near *,char const __near *,float),class CUtlMemory<void (*)(class IConVar __near *,char const __near *,float),int>>::~CUtlVector<void (*)(class IConVar __near *,char const __near *,float),class CUtlMemory<void (*)(class IConVar __near *,char const __near *,float),int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<void (__cdecl *)(IConVar *,char const *,float),CUtlMemory<void (__cdecl *)(IConVar *,char const *,float),int>>::~CUtlVector<void (__cdecl *)(IConVar *,char const *,float),CUtlMemory<void (__cdecl *)(IConVar *,char const *,float),int>>(
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
// Address: 0x0040BB00
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
// Address: 0x0040BB70
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
    CUtlMemory<fileList_t,int>::Grow(this: &this->m_Memory, num: m_Size - m_nAllocationCount + 1);
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
// Address: 0x0040BBE0
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
    CUtlMemory<fileList_t,int>::Grow(this: &this->m_Memory, num: num + m_Size - m_nAllocationCount);
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
// Address: 0x0040BC80
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
// Address: 0x0040BCF0
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
// Address: 0x0040BD60
// Name: private: int CScriptLib::GetFileList(char const __near *,char const __near *,class CUtlVector<struct fileList_t,class CUtlMemory<struct fileList_t,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CScriptLib::GetFileList(
        CScriptLib *this,
        const char *pDirPath,
        const char *pPattern,
        CUtlVector<fileList_t,CUtlMemory<fileList_t,int> > *fileList)
{
  unsigned int v5; // kr00_4
  int v6; // eax
  char v7; // cl
  char *v8; // edi
  char v9; // al
  unsigned int v10; // eax
  char *v11; // edi
  char v12; // cl
  int v13; // esi
  int v15; // eax
  char v16; // cl
  unsigned int v17; // eax
  char *v18; // edi
  char v19; // cl
  char *v20; // edi
  char *v21; // esi
  char v22; // cl
  int m_Size; // eax
  int v24; // esi
  char v25; // [esp+Bh] [ebp-435h] BYREF
  char fileName[260]; // [esp+Ch] [ebp-434h] BYREF
  char fullPath[260]; // [esp+110h] [ebp-330h] BYREF
  _finddata64i32_t findData; // [esp+214h] [ebp-22Ch] BYREF
  char sourcePath[260]; // [esp+33Ch] [ebp-104h] BYREF
  int h; // [esp+448h] [ebp+8h]
  char bFindDirs_3; // [esp+453h] [ebp+13h]

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
  v5 = strlen(sourcePath);
  if ( v5 != 0 )
  {
    if ( findData.name[v5 + 259] != 92 )
    {
      sourcePath[v5] = 92;
      sourcePath[v5 + 1] = 0;
    }
  }
  else
  {
    strcpy(sourcePath, ".\\");
  }
  v6 = 0;
  do
  {
    v7 = sourcePath[v6];
    fullPath[v6++] = v7;
  }
  while ( v7 != 0 );
  if ( *pPattern != 92 || pPattern[1] != 0 )
  {
    bFindDirs_3 = 0;
    v10 = strlen(pPattern) + 1;
    v11 = &fileName[259];
    do
      v12 = *++v11;
    while ( v12 != 0 );
    qmemcpy(v11, pPattern, v10);
  }
  else
  {
    bFindDirs_3 = 1;
    v8 = &fileName[259];
    do
      v9 = *++v8;
    while ( v9 != 0 );
    strcpy(v8, "*");
  }
  v13 = _findfirst64i32(szWild: fullPath, pfd: &findData);
  h = v13;
  if ( v13 == -1 )
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
      v15 = 0;
      do
      {
        v16 = sourcePath[v15];
        fileName[v15++] = v16;
      }
      while ( v16 != 0 );
      v17 = strlen(findData.name) + 1;
      v18 = &v25;
      do
        v19 = *++v18;
      while ( v19 != 0 );
      qmemcpy(v18, findData.name, 4 * (v17 >> 2));
      v21 = &findData.name[4 * (v17 >> 2)];
      v20 = &v18[4 * (v17 >> 2)];
      v22 = v17;
      m_Size = fileList->m_Size;
      qmemcpy(v20, v21, v22 & 3);
      v24 = CUtlVector<fileList_t,CUtlMemory<fileList_t,int>>::InsertBefore(this: fileList, elem: m_Size);
      CUtlString::Set(this: &fileList->m_Memory.m_pMemory[v24].fileName, pValue: fileName);
      fileList->m_Memory.m_pMemory[v24].timeWrite = findData.time_write;
      v13 = h;
    }
  }
  while ( _findnext64i32(hFile: v13, pfd: &findData) == 0 );
  _findclose(hFile: v13);
  return fileList->m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x0040BFC0
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
// Address: 0x0040C020
// Name: public: virtual void CScriptLib::DeleteTemporaryFiles(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CScriptLib::DeleteTemporaryFiles(CScriptLib *this, const char *pFileMask)
{
  char *v2; // eax
  char *v3; // edx
  char v4; // cl
  unsigned int v5; // eax
  char *v6; // edi
  char v7; // cl
  int (__thiscall *FindFiles)(struct CScriptLib *, char *, bool, CUtlVector<fileList_t,CUtlMemory<fileList_t,int> > *); // edx
  int v9; // esi
  int v10; // edi
  const char *v11; // eax
  fileList_t *m_pMemory; // eax
  char v13; // [esp+3h] [ebp-11Dh] BYREF
  char tempPath[260]; // [esp+4h] [ebp-11Ch] BYREF
  CScriptLib *v15; // [esp+108h] [ebp-18h]
  CUtlVector<fileList_t,CUtlMemory<fileList_t,int> > fileList; // [esp+10Ch] [ebp-14h] BYREF

  v15 = this;
  v2 = getenv(option: "temp");
  if ( v2 != nullptr || (v2 = getenv(option: "tmp")) != nullptr )
  {
    v3 = (char *)(tempPath - v2);
    do
    {
      v4 = *v2;
      v2[(_DWORD)v3] = *v2;
      ++v2;
    }
    while ( v4 != 0 );
    V_AppendSlash(pStr: tempPath, strSize: 260);
    v5 = strlen(pFileMask) + 1;
    v6 = &v13;
    do
      v7 = *++v6;
    while ( v7 != 0 );
    qmemcpy(v6, pFileMask, v5);
    FindFiles = v15->FindFiles;
    memset(&fileList, 0, sizeof(fileList));
    FindFiles(this: v15, a2: tempPath, a3: false, a4: &fileList);
    v9 = 0;
    if ( fileList.m_Size > 0 )
    {
      v10 = 0;
      do
      {
        v11 = CUtlString::Get(this: &fileList.m_Memory.m_pMemory[v10].fileName);
        _unlink(path: v11);
        ++v9;
        ++v10;
      }
      while ( v9 < fileList.m_Size );
    }
    CUtlVector<fileList_t,CUtlMemory<fileList_t,int>>::RemoveAll(this: &fileList);
    m_pMemory = fileList.m_Memory.m_pMemory;
    if ( fileList.m_Memory.m_nGrowSize >= 0 )
    {
      if ( fileList.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: fileList.m_Memory.m_pMemory);
        m_pMemory = nullptr;
        fileList.m_Memory.m_pMemory = nullptr;
      }
      fileList.m_Memory.m_nAllocationCount = 0;
    }
    fileList.m_pElements = m_pMemory;
    if ( fileList.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040C150
// Name: private: void CScriptLib::RecurseFileTree_r(char const __near *,int,class CUtlVector<class CUtlString,class CUtlMemory<class CUtlString,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CScriptLib::RecurseFileTree_r(
        CScriptLib *this,
        const char *pDirPath,
        int depth,
        CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *dirList)
{
  fileList_t *i; // ebx
  int v5; // eax
  int v6; // eax
  fileList_t *m_pMemory; // edi
  const char *v8; // eax
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CUtlString *v11; // ecx
  int v12; // eax
  int v13; // edi
  CUtlString *v14; // ecx
  CUtlVector<fileList_t,CUtlMemory<fileList_t,int> > fileList; // [esp+Ch] [ebp-18h] BYREF
  CScriptLib *v16; // [esp+20h] [ebp-4h]

  i = nullptr;
  v16 = this;
  memset(&fileList, 0, sizeof(fileList));
  v5 = CScriptLib::GetFileList(this, pDirPath, pPattern: "\\", &fileList);
  if ( v5 != 0 )
  {
    if ( v5 > 0 )
    {
      m_pMemory = fileList.m_Memory.m_pMemory;
      for ( i = (fileList_t *)v5; i != nullptr; i = (fileList_t *)((char *)i - 1) )
      {
        v8 = CUtlString::Get(this: &m_pMemory->fileName);
        CScriptLib::RecurseFileTree_r(this: v16, pDirPath: v8, depth: depth + 1, dirList);
        ++m_pMemory;
      }
    }
    m_Size = dirList->m_Size;
    m_nAllocationCount = dirList->m_Memory.m_nAllocationCount;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<CUtlString,int>::Grow(this: &dirList->m_Memory, num: m_Size - m_nAllocationCount + 1);
    ++dirList->m_Size;
    v11 = dirList->m_Memory.m_pMemory;
    v12 = dirList->m_Size - m_Size - 1;
    dirList->m_pElements = dirList->m_Memory.m_pMemory;
    if ( v12 > (int)i )
      _V_memmove(dest: &v11[m_Size + 1], src: &v11[m_Size], count: 16 * v12);
    v13 = m_Size;
    v14 = &dirList->m_Memory.m_pMemory[v13];
    if ( v14 != nullptr )
      CUtlString::CUtlString(this: v14);
    CUtlString::Set(this: &dirList->m_Memory.m_pMemory[v13], pValue: pDirPath);
    CUtlVector<fileList_t,CUtlMemory<fileList_t,int>>::RemoveAll(this: &fileList);
    if ( fileList.m_Memory.m_nGrowSize >= (int)i && fileList.m_Memory.m_pMemory != i )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: fileList.m_Memory.m_pMemory);
  }
  else
  {
    v6 = CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>::InsertBefore(this: dirList, elem: dirList->m_Size);
    CUtlString::Set(this: &dirList->m_Memory.m_pMemory[v6], pValue: pDirPath);
    CUtlVector<fileList_t,CUtlMemory<fileList_t,int>>::~CUtlVector<fileList_t,CUtlMemory<fileList_t,int>>(this: &fileList);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040C270
// Name: public: virtual int CScriptLib::FindFiles(char __near *,bool,class CUtlVector<struct fileList_t,class CUtlMemory<struct fileList_t,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CScriptLib::FindFiles(
        CScriptLib *this,
        char *pFileMask,
        bool bRecurse,
        CUtlVector<fileList_t,CUtlMemory<fileList_t,int> > *fileList)
{
  CScriptLib *v4; // edi
  char *v5; // edi
  char v6; // al
  unsigned int v7; // eax
  char *v8; // edi
  char v9; // cl
  int m_nGrowSize; // esi
  fileList_t *m_pMemory; // eax
  const char *v13; // eax
  CUtlVector<fileList_t,CUtlMemory<fileList_t,int> > *v14; // esi
  int m_Size; // edi
  int inserted; // eax
  fileList_t *v17; // edi
  int v18; // ebx
  CUtlString *p_fileName; // esi
  int timeWrite_high; // eax
  bool v21; // zf
  CUtlString *v22; // eax
  unsigned int v23; // [esp-8h] [ebp-34Ch]
  char extension[260]; // [esp+8h] [ebp-33Ch] BYREF
  char dirPath[260]; // [esp+10Ch] [ebp-238h] BYREF
  char pattern[260]; // [esp+210h] [ebp-134h] BYREF
  CScriptLib *v27; // [esp+314h] [ebp-30h]
  int i; // [esp+318h] [ebp-2Ch]
  CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > dirList; // [esp+31Ch] [ebp-28h] BYREF
  CUtlVector<fileList_t,CUtlMemory<fileList_t,int> > tempList; // [esp+330h] [ebp-14h] BYREF
  char *pFileMaska; // [esp+34Ch] [ebp+8h]
  int bRecursea; // [esp+350h] [ebp+Ch]

  v4 = this;
  v27 = this;
  strcpy(dirPath, pFileMask);
  V_StripFilename(path: dirPath);
  V_FileBase(in: pFileMask, out: pattern, maxlen: 260);
  V_ExtractFileExtension(path: pFileMask, dest: extension, destSize: 260);
  if ( extension[0] != 0 )
  {
    v5 = &dirPath[259];
    do
      v6 = *++v5;
    while ( v6 != 0 );
    strcpy(v5, ".");
    v7 = strlen(extension) + 1;
    v8 = &dirPath[259];
    do
      v9 = *++v8;
    while ( v9 != 0 );
    qmemcpy(v8, extension, v7);
    v4 = v27;
  }
  if ( bRecurse )
  {
    memset(&tempList, 0, sizeof(tempList));
    memset(&dirList, 0, sizeof(dirList));
    CScriptLib::RecurseFileTree_r(this: v4, pDirPath: dirPath, depth: 0, &dirList);
    i = 0;
    if ( dirList.m_Size > 0 )
    {
      bRecursea = 0;
      while ( 1 )
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
          v23 = 24 * dirList.m_Size;
          if ( m_pMemory != nullptr )
            m_pMemory = (fileList_t *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v23);
          else
            m_pMemory = (fileList_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v23);
          tempList.m_Memory.m_pMemory = m_pMemory;
        }
        tempList.m_pElements = m_pMemory;
        v13 = CUtlString::Get(this: &dirList.m_Memory.m_pMemory[bRecursea]);
        CScriptLib::GetFileList(this: v4, pDirPath: v13, pPattern: pattern, fileList: &tempList);
        v14 = fileList;
        m_Size = tempList.m_Size;
        inserted = CUtlVector<fileList_t,CUtlMemory<fileList_t,int>>::InsertMultipleBefore(
                     this: fileList,
                     elem: fileList->m_Size,
                     num: tempList.m_Size);
        if ( m_Size > 0 )
        {
          v17 = tempList.m_Memory.m_pMemory;
          v18 = inserted;
          pFileMaska = (char *)tempList.m_Size;
          while ( 1 )
          {
            p_fileName = &v14->m_Memory.m_pMemory[v18].fileName;
            CUtlString::operator=(this: p_fileName, src: &v17->fileName);
            p_fileName[1].m_Storage.m_Memory.m_pMemory = (unsigned __int8 *)v17->timeWrite;
            timeWrite_high = HIDWORD(v17->timeWrite);
            ++v17;
            ++v18;
            v21 = pFileMaska-- == (char *)1;
            p_fileName[1].m_Storage.m_Memory.m_nAllocationCount = timeWrite_high;
            if ( v21 )
              break;
            v14 = fileList;
          }
        }
        ++bRecursea;
        if ( ++i >= dirList.m_Size )
          break;
        v4 = v27;
      }
    }
    CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>::RemoveAll(this: &dirList);
    v22 = dirList.m_Memory.m_pMemory;
    if ( dirList.m_Memory.m_nGrowSize >= 0 )
    {
      if ( dirList.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: dirList.m_Memory.m_pMemory);
        v22 = nullptr;
        dirList.m_Memory.m_pMemory = nullptr;
      }
      dirList.m_Memory.m_nAllocationCount = 0;
    }
    dirList.m_pElements = v22;
    if ( dirList.m_Memory.m_nGrowSize >= 0 )
    {
      if ( v22 != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v22);
        dirList.m_Memory.m_pMemory = nullptr;
      }
      dirList.m_Memory.m_nAllocationCount = 0;
    }
    CUtlVector<fileList_t,CUtlMemory<fileList_t,int>>::RemoveAll(this: &tempList);
    if ( tempList.m_Memory.m_nGrowSize < 0 )
    {
      return fileList->m_Size;
    }
    else
    {
      if ( tempList.m_Memory.m_pMemory != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: tempList.m_Memory.m_pMemory);
      return fileList->m_Size;
    }
  }
  else
  {
    CScriptLib::GetFileList(this: v4, pDirPath: dirPath, pPattern: pattern, fileList);
    return fileList->m_Size;
  }
}

} // namespace motionmapper

// ============================================================
// Overlay from scenemanager (Missing functions)
// ============================================================
namespace scenemanager {

//------------------------------------------------------------------------------
// Address: 0x0040B450
// Name: void AddScriptToStack(char __near *,enum ScriptPathMode_t)
// Source: json
//------------------------------------------------------------------------------
void __usercall AddScriptToStack(int a1@<edi>, char *filename, ScriptPathMode_t pathMode)
{
  int File; // esi
  const char *v4; // [esp-8h] [ebp-8h]
  const char *savedregs; // [esp+0h] [ebp+0h]

  if ( ++script == (script_t *)token )
    _Error(this: (ISceneTokenProcessor *)&stru_44E068, a2: savedregs);
  if ( pathMode == SCRIPT_USE_RELATIVE_PATH )
  {
    V_strncpy(pDest: script->filename, pSrc: filename, maxLen: 1024);
  }
  else
  {
    v4 = ExpandPath(path: filename);
    V_strncpy(pDest: script->filename, pSrc: v4, maxLen: 1024);
  }
  File = LoadFile(a1, filename: script->filename, bufferptr: (void **)&script->buffer);
  if ( g_pfnCallback != nullptr )
  {
    if ( script == &scriptstack[1] )
      g_pfnCallback(a1: script->filename, a2: nullptr, a3: 0);
    else
      g_pfnCallback(a1: script->filename, a2: script[-1].filename, a3: script[-1].line);
  }
  script->line = 1;
  script->script_p = script->buffer;
  script->end_p = &script->buffer[File];
}

//------------------------------------------------------------------------------
// Address: 0x0040B530
// Name: void LoadScriptFile(char __near *,enum ScriptPathMode_t)
// Source: json
//------------------------------------------------------------------------------
void __usercall LoadScriptFile(int a1@<edi>, char *filename, ScriptPathMode_t pathMode)
{
  script = scriptstack;
  AddScriptToStack(a1, filename, pathMode);
  endofscript = 0;
  tokenready = 0;
}

//------------------------------------------------------------------------------
// Address: 0x0040B560
// Name: bool AddMacroToStack(char __near *)
// Source: json
//------------------------------------------------------------------------------
char __usercall AddMacroToStack@<al>(const char *a1@<ebx>, char *macroname)
{
  int v3; // esi
  bool v4; // zf
  script_t *v5; // edi
  script_t *v6; // ebx
  int nummacroparams; // eax
  char *macrobuffer; // esi
  char **macroparam; // edi
  unsigned int v10; // esi
  const char *v11; // [esp-Ch] [ebp-14h]
  script_t *pmacro; // [esp+4h] [ebp-4h]
  int i; // [esp+10h] [ebp+8h]

  if ( *macroname != 36 )
    return 0;
  v3 = 0;
  v4 = nummacros == 0;
  if ( nummacros > 0 )
  {
    do
    {
      if ( _V_stricmp(s1: macrolist[v3]->filename, s2: macroname + 1) == 0 )
        break;
      ++v3;
    }
    while ( v3 < nummacros );
    v4 = v3 == nummacros;
  }
  if ( v4 )
    return 0;
  v5 = macrolist[v3];
  v11 = a1;
  v6 = script + 2;
  pmacro = v5;
  if ( &script[2] == (script_t *)token )
    _Error(this: (ISceneTokenProcessor *)&stru_44E068, a2: v11);
  nummacroparams = v5->nummacroparams;
  macrobuffer = v6->macrobuffer;
  v6->nummacroparams = nummacroparams;
  i = 0;
  if ( nummacroparams > 0 )
  {
    macroparam = v6->macroparam;
    do
    {
      GetToken(crossline: 0);
      strcpy(macrobuffer, token);
      *macroparam = *(char **)((char *)macroparam + (char *)pmacro - (char *)v6);
      macroparam[64] = macrobuffer;
      macrobuffer += strlen(token) + 1;
      if ( macrobuffer >= (char *)v6->macroparam )
        _Error(this: (ISceneTokenProcessor *)&stru_44E08C, a2: v11);
      ++macroparam;
      ++i;
    }
    while ( i < v6->nummacroparams );
    v5 = pmacro;
  }
  script = (script_t *)strcpy(v6->filename, v5->filename);
  v10 = v5->end_p - v5->buffer;
  script->buffer = (char *)operator new(nSize: v10 + 1);
  memcpy(dst: (unsigned __int8 *)script->buffer, src: (unsigned __int8 *)v5->buffer, count: v10);
  v5->buffer[v10] = 0;
  script->script_p = script->buffer;
  script->end_p = &script->buffer[v10];
  script->line = v5->line;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0040B850
// Name: int EndOfScript(int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl EndOfScript(int crossline)
{
  if ( crossline == 0 )
    _Error(this: (ISceneTokenProcessor *)&stru_44E108, a2: scriptline);
  if ( strcmp(script->filename, "memory buffer") == 0
    || (free(pMem: script->buffer), script->buffer = nullptr, script == &scriptstack[1]) )
  {
    endofscript = 1;
    return 0;
  }
  else
  {
    --script;
    scriptline = (char *)script->line;
    return GetToken(crossline);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040B910
// Name: int TokenAvailable(void)
// Source: json
//------------------------------------------------------------------------------
int __cdecl TokenAvailable()
{
  char *script_p; // eax
  char *end_p; // edx
  char v3; // cl
  char v4; // cl

  if ( tokenready != 0 )
    return 1;
  script_p = script->script_p;
  end_p = script->end_p;
  if ( script_p < end_p )
  {
    v3 = *script_p;
    if ( *script_p > 32 )
    {
LABEL_8:
      v4 = *script_p;
      if ( *script_p != 59 && v4 != 35 && (v4 != 47 || script_p[1] != 47) )
        return 1;
    }
    else
    {
      while ( v3 != 10 )
      {
        if ( ++script_p == end_p )
          break;
        v3 = *script_p;
        if ( *script_p > 32 )
          goto LABEL_8;
      }
    }
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x0040B970
// Name: public: virtual bool CScriptLib::DoesFileExist(char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CScriptLib::DoesFileExist(CScriptLib *this, const char *pFilename)
{
  return g_pFullFileSystem->FileExists(this: &g_pFullFileSystem->IBaseFileSystem, a2: pFilename, a3: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x0040B990
// Name: public: virtual bool CScriptLib::ReadFileToBuffer(char const __near *,class CUtlBuffer __near &,bool,bool)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CScriptLib::ReadFileToBuffer(
        CScriptLib *this,
        const char *pSourceName,
        CUtlBuffer *buffer,
        bool bText,
        bool bNoOpenFailureWarning)
{
  int *v5; // eax
  const char *v6; // eax

  if ( g_pFullFileSystem->ReadFile(
         this: &g_pFullFileSystem->IBaseFileSystem,
         a2: pSourceName,
         a3: nullptr,
         a4: buffer,
         a5: 0,
         a6: 0,
         a7: nullptr) )
  {
    if ( bText )
      CUtlBuffer::SetBufferType(this: buffer, bIsText: true, bContainsCRLF: true);
    else
      CUtlBuffer::SetBufferType(this: buffer, bIsText: false, bContainsCRLF: false);
    return 1;
  }
  else
  {
    if ( !bNoOpenFailureWarning )
    {
      v5 = _errno();
      v6 = strerror(errnum: *v5);
      _Msg(a1: "ReadFileToBuffer(): Error opening %s: %s\n", pSourceName, v6);
    }
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040BA10
// Name: public: virtual bool CScriptLib::WriteBufferToFile(char const __near *,class CUtlBuffer __near &,enum DiskWriteMode_t)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CScriptLib::WriteBufferToFile(
        CScriptLib *this,
        const char *pTargetName,
        CUtlBuffer *buffer,
        DiskWriteMode_t writeMode)
{
  _BYTE *v5; // eax
  _BYTE *v6; // esi
  _BYTE *v7; // eax
  char dirPath[260]; // [esp+8h] [ebp-104h] BYREF

  strcpy(dirPath, pTargetName);
  strchr(string: (unsigned __int8 *)dirPath, chr: 0x5Cu);
  v6 = v5;
  if ( v5 != nullptr )
  {
    while ( 1 )
    {
      strchr(string: v6 + 1, chr: 0x5Cu);
      v6 = v7;
      if ( v7 == nullptr )
        break;
      *v7 = 0;
      _mkdir(path: dirPath);
      *v6 = 92;
    }
  }
  return writeMode != WRITE_TO_DISK_ALWAYS
      && (writeMode != WRITE_TO_DISK_UPDATE || !this->DoesFileExist(this, a2: pTargetName))
      || g_pFullFileSystem->WriteFile(
           this: &g_pFullFileSystem->IBaseFileSystem,
           a2: pTargetName,
           a3: nullptr,
           a4: buffer);
}

//------------------------------------------------------------------------------
// Address: 0x0040BAD0
// Name: public: virtual int CScriptLib::CompareFileTime(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CScriptLib::CompareFileTime(CScriptLib *this, const char *pFilenameA, const char *pFilenameB)
{
  unsigned int v3; // esi
  unsigned int v4; // eax
  bool v5; // cf

  v3 = g_pFullFileSystem->GetFileTime(this: &g_pFullFileSystem->IBaseFileSystem, a2: pFilenameA, a3: nullptr);
  v4 = g_pFullFileSystem->GetFileTime(this: &g_pFullFileSystem->IBaseFileSystem, a2: pFilenameB, a3: nullptr);
  if ( v3 == -1 )
    v3 = 0;
  if ( v4 == -1 )
    return v3 != 0;
  v5 = v4 < v3;
  if ( v4 <= v3 )
    return v5;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0040BB30
// Name: public: virtual char __near * CScriptLib::MakeTemporaryFilename(char const __near *,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CScriptLib::MakeTemporaryFilename(CScriptLib *this, const char *pchModPath, char *pPath, int pathSize)
{
  char *v4; // eax
  char *v5; // esi

  v4 = _tempnam(dir: pchModPath, pfx: "mgd_");
  v5 = v4;
  if ( *v4 == 92 )
    v5 = v4 + 1;
  if ( v5[strlen(v5) - 1] == 46 )
    v5[strlen(v5) - 1] = 0;
  V_snprintf(pDest: pPath, maxLen: pathSize, pFormat: "%s.tmp", v5);
  free(pMem: v5);
  return pPath;
}

//------------------------------------------------------------------------------
// Address: 0x0040BBA0
// Name: void DefineMacro(char __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DefineMacro(char *macroname)
{
  script_t *v1; // edi
  char *script_p; // esi
  char *macrobuffer; // ebx
  unsigned int v4; // ebx
  unsigned __int8 *v5; // eax
  int v6; // eax
  script_t *v7; // edx
  const char *v8; // [esp+0h] [ebp-Ch]

  v1 = (script_t *)operator new(nSize: 0x1614u);
  strcpy(v1->filename, macroname);
  v1->line = script->line;
  v1->nummacroparams = 0;
  script_p = script->script_p;
  macrobuffer = v1->macrobuffer;
  while ( TokenAvailable() != 0 )
  {
    GetToken(crossline: 0);
    if ( token[0] == 92 && byte_48C761 == 92 )
      break;
    script_p = script->script_p;
    v1->macroparam[v1->nummacroparams++] = macrobuffer;
    strcpy(macrobuffer, token);
    macrobuffer += strlen(token) + 1;
    if ( macrobuffer >= (char *)v1->macroparam )
      _Error(this: (ISceneTokenProcessor *)&stru_44E08C, a2: v8);
  }
  for ( script->script_p = script_p; *script_p != 0; ++script_p )
  {
    if ( *script_p == 10 )
      break;
    if ( *script_p == 92 && script_p[1] == 92 )
    {
      do
      {
        if ( *script_p == 10 )
          break;
        *script_p++ = 32;
      }
      while ( *script_p != 0 );
      if ( *script_p == 0 )
        break;
    }
  }
  v4 = script_p - script->script_p;
  v5 = (unsigned __int8 *)operator new(nSize: v4 + 1);
  v1->buffer = (char *)v5;
  memcpy(dst: v5, src: (unsigned __int8 *)script->script_p, count: v4);
  v1->buffer[v4] = 0;
  v1->end_p = &v1->buffer[v4];
  v6 = nummacros;
  v7 = script;
  macrolist[nummacros] = v1;
  nummacros = v6 + 1;
  v7->script_p = script_p;
}

//------------------------------------------------------------------------------
// Address: 0x0040BE70
// Name: bool ExpandVariableToken(char __near * __near &)
// Source: json
//------------------------------------------------------------------------------
char __usercall ExpandVariableToken@<al>(const char *a1@<edi>, char **token_p)
{
  char *script_p; // eax
  const char *v3; // edi
  _BYTE *v4; // ebx
  char v5; // al
  int v7; // esi
  char *value; // esi
  unsigned int v9; // eax
  char *v10; // edx
  _BYTE *v11; // esi
  char v12; // cl

  script_p = script->script_p;
  if ( *script_p != 36 )
    return 0;
  v3 = script_p + 1;
  v4 = script_p + 1;
  v5 = script_p[1];
  if ( v5 <= 32 )
  {
LABEL_5:
    if ( *v4 != 36 )
      return 0;
  }
  else
  {
    while ( v5 != 36 )
    {
      v5 = *++v4;
      if ( v5 <= 32 )
        goto LABEL_5;
    }
  }
  v7 = 0;
  *v4 = 0;
  if ( g_definevariable.m_Size <= 0 )
    goto LABEL_12;
  while ( V_strnicmp(s1: g_definevariable.m_Memory.m_pMemory[v7].param, s2: v3, n: v4 - v3 - 2) != 0 )
  {
    if ( ++v7 >= g_definevariable.m_Size )
      goto LABEL_12;
  }
  if ( v7 >= g_definevariable.m_Size )
LABEL_12:
    _Error(this: (ISceneTokenProcessor *)&stru_44E17C, a2: v3, script);
  value = g_definevariable.m_Memory.m_pMemory[v7].value;
  v9 = strlen(value);
  v10 = value;
  v11 = *token_p;
  do
  {
    v12 = *v10;
    *v11++ = *v10++;
  }
  while ( v12 != 0 );
  *token_p += v9;
  script->script_p = v4 + 1;
  if ( script->script_p >= script->end_p )
    _Error(this: (ISceneTokenProcessor *)&stru_44E0C0, a2: a1);
  if ( *token_p >= (char *)&nummacros )
    _Error(this: (ISceneTokenProcessor *)&stru_44E0A4, a2: scriptline);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0040C080
// Name: void DefineVariable(char __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DefineVariable(char *variablename)
{
  char *v1; // eax
  char *v2; // eax
  char *v3; // ecx
  char v4; // dl
  variable_t v; // [esp+8h] [ebp-8h] BYREF

  if ( variablename != nullptr
    && (v1 = (char *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: strlen(variablename) + 1)) != nullptr )
  {
    strcpy(v1, variablename);
  }
  else
  {
    v1 = nullptr;
  }
  v.param = v1;
  GetToken(crossline: 0);
  v2 = (char *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: strlen(token) + 1);
  if ( v2 != nullptr )
  {
    v3 = v2;
    do
    {
      v4 = v3[token - v2];
      *v3++ = v4;
    }
    while ( v4 != 0 );
  }
  else
  {
    v2 = nullptr;
  }
  v.value = v2;
  CUtlVector<variable_t,CUtlMemory<variable_t,int>>::InsertBefore(
    this: &g_definevariable,
    elem: g_definevariable.m_Size,
    src: &v);
}

//------------------------------------------------------------------------------
// Address: 0x0040C140
// Name: int GetToken(int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl GetToken(int crossline)
{
  script_t *v1; // eax
  char *script_p; // ecx
  char v3; // dl
  script_t *v4; // eax
  char *v5; // ecx
  char *v6; // edx
  char v7; // cl
  char *v8; // ecx
  char v9; // dl
  script_t *v10; // eax
  char *v11; // edx
  script_t *v12; // eax
  char *line; // edx
  char v14; // cl
  char *v15; // esi
  script_t *v16; // eax
  char i; // cl
  char *v18; // esi
  char *v19; // ecx
  char *token_p; // [esp+Ch] [ebp-4h] BYREF

  if ( tokenready != 0 )
  {
LABEL_54:
    tokenready = 0;
    return 1;
  }
  else
  {
    while ( 1 )
    {
      v1 = script;
      if ( script->script_p >= script->end_p )
        return EndOfScript(crossline);
      tokenready = 0;
      while ( 1 )
      {
        while ( 1 )
        {
          if ( *v1->script_p <= 32 )
          {
            do
            {
              script_p = v1->script_p;
              if ( script_p >= v1->end_p )
                return EndOfScript(crossline);
              v3 = *script_p;
              v1->script_p = script_p + 1;
              if ( v3 == 10 )
              {
                if ( crossline == 0 )
                  _Error(this: (ISceneTokenProcessor *)&stru_44E108, a2: scriptline);
                v4 = script;
                ++script->line;
                scriptline = (char *)v4->line;
              }
              v1 = script;
            }
            while ( *script->script_p <= 32 );
          }
          v5 = v1->script_p;
          if ( v5 >= v1->end_p )
            return EndOfScript(crossline);
          v6 = v1->script_p;
          v7 = *v5;
          if ( v7 != 59 && v7 != 35 )
          {
            if ( v7 != 47 )
              goto LABEL_30;
            if ( v6[1] != 47 )
              break;
          }
          if ( crossline == 0 )
          {
            _Error(this: (ISceneTokenProcessor *)&stru_44E108, a2: scriptline);
            v1 = script;
          }
          if ( *v1->script_p != 10 )
          {
            do
            {
              ++v1->script_p;
              v1 = script;
              v11 = script->script_p;
              if ( v11 >= script->end_p )
                return EndOfScript(crossline);
            }
            while ( *v11 != 10 );
          }
          ++v1->script_p;
          v12 = script;
          ++script->line;
          line = (char *)v12->line;
          v1 = script;
          scriptline = line;
        }
        if ( v6[1] != 42 )
          break;
        v1->script_p += 2;
        while ( 1 )
        {
          v8 = script->script_p;
          if ( *v8 == 42 && v8[1] == 47 )
            break;
          v9 = *v8;
          script->script_p = v8 + 1;
          if ( v9 != 10 )
          {
            v10 = script;
            if ( script->script_p >= script->end_p )
              return EndOfScript(crossline);
            ++script->line;
            scriptline = (char *)v10->line;
          }
        }
        script->script_p += 2;
        v1 = script;
      }
LABEL_30:
      v14 = *v6;
      v15 = token;
      token_p = token;
      if ( v14 == 34 )
      {
        ++v1->script_p;
        v16 = script;
        for ( i = *script->script_p; i != 34; i = *v16->script_p )
        {
          *v15 = i;
          ++script->script_p;
          v16 = script;
          ++v15;
          if ( script->script_p == script->end_p )
            break;
          if ( v15 == (char *)&nummacros )
          {
            _Error(this: (ISceneTokenProcessor *)&stru_44E0A4, a2: scriptline);
            v16 = script;
          }
        }
        ++v16->script_p;
      }
      else
      {
        for ( ; v14 > 32; v14 = *script->script_p )
        {
          if ( v14 == 59 )
            break;
          if ( ExpandMacroToken(&token_p) || ExpandVariableToken(a1: (const char *)1, &token_p) != 0 )
          {
            v15 = token_p;
          }
          else
          {
            v18 = token_p;
            *token_p = *script->script_p++;
            v19 = script->script_p;
            v15 = v18 + 1;
            token_p = v15;
            if ( v19 == script->end_p )
              break;
            if ( v15 == (char *)&nummacros )
              _Error(this: (ISceneTokenProcessor *)&stru_44E0A4, a2: scriptline);
          }
        }
      }
      *v15 = 0;
      if ( _V_stricmp(s1: token, s2: "$include") != 0 )
      {
        if ( _V_stricmp(s1: token, s2: "$definemacro") != 0 )
        {
          if ( _V_stricmp(s1: token, s2: "$definevariable") != 0 )
          {
            if ( AddMacroToStack(a1: (const char *)_Error, macroname: token) == 0 )
              return 1;
          }
          else
          {
            GetToken(crossline: 0);
            DefineVariable(variablename: token);
          }
        }
        else
        {
          GetToken(crossline: 0);
          DefineMacro(macroname: token);
        }
      }
      else
      {
        GetToken(crossline: 0);
        AddScriptToStack(a1: 1, filename: token, pathMode: SCRIPT_USE_ABSOLUTE_PATH);
      }
      if ( tokenready != 0 )
        goto LABEL_54;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040C730
// Name: private: int CScriptLib::GetFileList(char const __near *,char const __near *,class CUtlVector<struct fileList_t,class CUtlMemory<struct fileList_t,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CScriptLib::GetFileList(
        CScriptLib *this,
        const char *pDirPath,
        const char *pPattern,
        CUtlVector<fileList_t,CUtlMemory<fileList_t,int> > *fileList)
{
  unsigned int v5; // kr00_4
  int v6; // eax
  char v7; // cl
  char *v8; // edi
  char v9; // al
  unsigned int v10; // eax
  char *v11; // edi
  char v12; // cl
  int v13; // esi
  int v15; // eax
  char v16; // cl
  unsigned int v17; // eax
  char *v18; // edi
  char v19; // cl
  char *v20; // edi
  char *v21; // esi
  char v22; // cl
  int m_Size; // eax
  int v24; // esi
  char v25; // [esp+Bh] [ebp-435h] BYREF
  char fileName[260]; // [esp+Ch] [ebp-434h] BYREF
  char fullPath[260]; // [esp+110h] [ebp-330h] BYREF
  _finddata64i32_t findData; // [esp+214h] [ebp-22Ch] BYREF
  char sourcePath[260]; // [esp+33Ch] [ebp-104h] BYREF
  int h; // [esp+448h] [ebp+8h]
  char bFindDirs_3; // [esp+453h] [ebp+13h]

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
  v5 = strlen(sourcePath);
  if ( v5 != 0 )
  {
    if ( findData.name[v5 + 259] != 92 )
    {
      sourcePath[v5] = 92;
      sourcePath[v5 + 1] = 0;
    }
  }
  else
  {
    strcpy(sourcePath, ".\\");
  }
  v6 = 0;
  do
  {
    v7 = sourcePath[v6];
    fullPath[v6++] = v7;
  }
  while ( v7 != 0 );
  if ( *pPattern != 92 || pPattern[1] != 0 )
  {
    bFindDirs_3 = 0;
    v10 = strlen(pPattern) + 1;
    v11 = &fileName[259];
    do
      v12 = *++v11;
    while ( v12 != 0 );
    qmemcpy(v11, pPattern, v10);
  }
  else
  {
    bFindDirs_3 = 1;
    v8 = &fileName[259];
    do
      v9 = *++v8;
    while ( v9 != 0 );
    strcpy(v8, "*");
  }
  v13 = _findfirst64i32(szWild: fullPath, pfd: &findData);
  h = v13;
  if ( v13 == -1 )
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
      v15 = 0;
      do
      {
        v16 = sourcePath[v15];
        fileName[v15++] = v16;
      }
      while ( v16 != 0 );
      v17 = strlen(findData.name) + 1;
      v18 = &v25;
      do
        v19 = *++v18;
      while ( v19 != 0 );
      qmemcpy(v18, findData.name, 4 * (v17 >> 2));
      v21 = &findData.name[4 * (v17 >> 2)];
      v20 = &v18[4 * (v17 >> 2)];
      v22 = v17;
      m_Size = fileList->m_Size;
      qmemcpy(v20, v21, v22 & 3);
      v24 = CUtlVector<fileList_t,CUtlMemory<fileList_t,int>>::InsertBefore(this: fileList, elem: m_Size);
      CUtlString::Set(this: &fileList->m_Memory.m_pMemory[v24].fileName, pValue: fileName);
      fileList->m_Memory.m_pMemory[v24].timeWrite = findData.time_write;
      v13 = h;
    }
  }
  while ( _findnext64i32(hFile: v13, pfd: &findData) == 0 );
  _findclose(hFile: v13);
  return fileList->m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x0040C9F0
// Name: public: virtual void CScriptLib::DeleteTemporaryFiles(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CScriptLib::DeleteTemporaryFiles(CScriptLib *this, const char *pFileMask)
{
  char *v2; // eax
  char *v3; // edx
  char v4; // cl
  unsigned int v5; // eax
  char *v6; // edi
  char v7; // cl
  int (__thiscall *FindFiles)(struct CScriptLib *, char *, bool, CUtlVector<fileList_t,CUtlMemory<fileList_t,int> > *); // edx
  int v9; // esi
  int v10; // edi
  const char *v11; // eax
  fileList_t *m_pMemory; // eax
  char v13; // [esp+3h] [ebp-11Dh] BYREF
  char tempPath[260]; // [esp+4h] [ebp-11Ch] BYREF
  CScriptLib *v15; // [esp+108h] [ebp-18h]
  CUtlVector<fileList_t,CUtlMemory<fileList_t,int> > fileList; // [esp+10Ch] [ebp-14h] BYREF

  v15 = this;
  v2 = getenv(option: "temp");
  if ( v2 != nullptr || (v2 = getenv(option: "tmp")) != nullptr )
  {
    v3 = (char *)(tempPath - v2);
    do
    {
      v4 = *v2;
      v2[(_DWORD)v3] = *v2;
      ++v2;
    }
    while ( v4 != 0 );
    V_AppendSlash(pStr: tempPath, strSize: 260);
    v5 = strlen(pFileMask) + 1;
    v6 = &v13;
    do
      v7 = *++v6;
    while ( v7 != 0 );
    qmemcpy(v6, pFileMask, v5);
    FindFiles = v15->FindFiles;
    memset(&fileList, 0, sizeof(fileList));
    FindFiles(this: v15, a2: tempPath, a3: false, a4: &fileList);
    v9 = 0;
    if ( fileList.m_Size > 0 )
    {
      v10 = 0;
      do
      {
        v11 = CUtlString::Get(this: &fileList.m_Memory.m_pMemory[v10].fileName);
        _unlink(path: v11);
        ++v9;
        ++v10;
      }
      while ( v9 < fileList.m_Size );
    }
    CUtlVector<fileList_t,CUtlMemory<fileList_t,int>>::RemoveAll(this: &fileList);
    m_pMemory = fileList.m_Memory.m_pMemory;
    if ( fileList.m_Memory.m_nGrowSize >= 0 )
    {
      if ( fileList.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: fileList.m_Memory.m_pMemory);
        m_pMemory = nullptr;
        fileList.m_Memory.m_pMemory = nullptr;
      }
      fileList.m_Memory.m_nAllocationCount = 0;
    }
    fileList.m_pElements = m_pMemory;
    if ( fileList.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040CB20
// Name: private: void CScriptLib::RecurseFileTree_r(char const __near *,int,class CUtlVector<class CUtlString,class CUtlMemory<class CUtlString,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CScriptLib::RecurseFileTree_r(
        CScriptLib *this,
        const char *pDirPath,
        int depth,
        CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *dirList)
{
  fileList_t *i; // ebx
  int v5; // eax
  int v6; // eax
  fileList_t *m_pMemory; // edi
  const char *v8; // eax
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CUtlString *v11; // ecx
  int v12; // eax
  int v13; // edi
  CUtlString *v14; // ecx
  CUtlVector<fileList_t,CUtlMemory<fileList_t,int> > fileList; // [esp+Ch] [ebp-18h] BYREF
  CScriptLib *v16; // [esp+20h] [ebp-4h]

  i = nullptr;
  v16 = this;
  memset(&fileList, 0, sizeof(fileList));
  v5 = CScriptLib::GetFileList(this, pDirPath, pPattern: "\\", &fileList);
  if ( v5 != 0 )
  {
    if ( v5 > 0 )
    {
      m_pMemory = fileList.m_Memory.m_pMemory;
      for ( i = (fileList_t *)v5; i != nullptr; i = (fileList_t *)((char *)i - 1) )
      {
        v8 = CUtlString::Get(this: &m_pMemory->fileName);
        CScriptLib::RecurseFileTree_r(this: v16, pDirPath: v8, depth: depth + 1, dirList);
        ++m_pMemory;
      }
    }
    m_Size = dirList->m_Size;
    m_nAllocationCount = dirList->m_Memory.m_nAllocationCount;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<CUtlString,int>::Grow(this: &dirList->m_Memory, num: m_Size - m_nAllocationCount + 1);
    ++dirList->m_Size;
    v11 = dirList->m_Memory.m_pMemory;
    v12 = dirList->m_Size - m_Size - 1;
    dirList->m_pElements = dirList->m_Memory.m_pMemory;
    if ( v12 > (int)i )
      _V_memmove(dest: &v11[m_Size + 1], src: &v11[m_Size], count: 16 * v12);
    v13 = m_Size;
    v14 = &dirList->m_Memory.m_pMemory[v13];
    if ( v14 != nullptr )
      CUtlString::CUtlString(this: v14);
    CUtlString::Set(this: &dirList->m_Memory.m_pMemory[v13], pValue: pDirPath);
    CUtlVector<fileList_t,CUtlMemory<fileList_t,int>>::RemoveAll(this: &fileList);
    if ( fileList.m_Memory.m_nGrowSize >= (int)i && fileList.m_Memory.m_pMemory != i )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: fileList.m_Memory.m_pMemory);
  }
  else
  {
    v6 = CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>::InsertBefore(this: dirList, elem: dirList->m_Size);
    CUtlString::Set(this: &dirList->m_Memory.m_pMemory[v6], pValue: pDirPath);
    CUtlVector<fileList_t,CUtlMemory<fileList_t,int>>::~CUtlVector<fileList_t,CUtlMemory<fileList_t,int>>(this: &fileList);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040CC40
// Name: public: virtual int CScriptLib::FindFiles(char __near *,bool,class CUtlVector<struct fileList_t,class CUtlMemory<struct fileList_t,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CScriptLib::FindFiles(
        CScriptLib *this,
        char *pFileMask,
        bool bRecurse,
        CUtlVector<fileList_t,CUtlMemory<fileList_t,int> > *fileList)
{
  CScriptLib *v4; // edi
  char *v5; // edi
  char v6; // al
  unsigned int v7; // eax
  char *v8; // edi
  char v9; // cl
  int m_nGrowSize; // esi
  fileList_t *m_pMemory; // eax
  const char *v13; // eax
  CUtlVector<fileList_t,CUtlMemory<fileList_t,int> > *v14; // esi
  int m_Size; // edi
  int inserted; // eax
  fileList_t *v17; // edi
  int v18; // ebx
  CUtlString *p_fileName; // esi
  int timeWrite_high; // eax
  bool v21; // zf
  CUtlString *v22; // eax
  unsigned int v23; // [esp-8h] [ebp-34Ch]
  char extension[260]; // [esp+8h] [ebp-33Ch] BYREF
  char dirPath[260]; // [esp+10Ch] [ebp-238h] BYREF
  char pattern[260]; // [esp+210h] [ebp-134h] BYREF
  CScriptLib *v27; // [esp+314h] [ebp-30h]
  int i; // [esp+318h] [ebp-2Ch]
  CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > dirList; // [esp+31Ch] [ebp-28h] BYREF
  CUtlVector<fileList_t,CUtlMemory<fileList_t,int> > tempList; // [esp+330h] [ebp-14h] BYREF
  char *pFileMaska; // [esp+34Ch] [ebp+8h]
  int bRecursea; // [esp+350h] [ebp+Ch]

  v4 = this;
  v27 = this;
  strcpy(dirPath, pFileMask);
  V_StripFilename(path: dirPath);
  V_FileBase(in: pFileMask, out: pattern, maxlen: 260);
  V_ExtractFileExtension(path: pFileMask, dest: extension, destSize: 260);
  if ( extension[0] != 0 )
  {
    v5 = &dirPath[259];
    do
      v6 = *++v5;
    while ( v6 != 0 );
    strcpy(v5, ".");
    v7 = strlen(extension) + 1;
    v8 = &dirPath[259];
    do
      v9 = *++v8;
    while ( v9 != 0 );
    qmemcpy(v8, extension, v7);
    v4 = v27;
  }
  if ( bRecurse )
  {
    memset(&tempList, 0, sizeof(tempList));
    memset(&dirList, 0, sizeof(dirList));
    CScriptLib::RecurseFileTree_r(this: v4, pDirPath: dirPath, depth: 0, &dirList);
    i = 0;
    if ( dirList.m_Size > 0 )
    {
      bRecursea = 0;
      while ( 1 )
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
          v23 = 24 * dirList.m_Size;
          if ( m_pMemory != nullptr )
            m_pMemory = (fileList_t *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v23);
          else
            m_pMemory = (fileList_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v23);
          tempList.m_Memory.m_pMemory = m_pMemory;
        }
        tempList.m_pElements = m_pMemory;
        v13 = CUtlString::Get(this: &dirList.m_Memory.m_pMemory[bRecursea]);
        CScriptLib::GetFileList(this: v4, pDirPath: v13, pPattern: pattern, fileList: &tempList);
        v14 = fileList;
        m_Size = tempList.m_Size;
        inserted = CUtlVector<fileList_t,CUtlMemory<fileList_t,int>>::InsertMultipleBefore(
                     this: fileList,
                     elem: fileList->m_Size,
                     num: tempList.m_Size);
        if ( m_Size > 0 )
        {
          v17 = tempList.m_Memory.m_pMemory;
          v18 = inserted;
          pFileMaska = (char *)tempList.m_Size;
          while ( 1 )
          {
            p_fileName = &v14->m_Memory.m_pMemory[v18].fileName;
            CUtlString::operator=(this: p_fileName, src: &v17->fileName);
            p_fileName[1].m_Storage.m_Memory.m_pMemory = (unsigned __int8 *)v17->timeWrite;
            timeWrite_high = HIDWORD(v17->timeWrite);
            ++v17;
            ++v18;
            v21 = pFileMaska-- == (char *)1;
            p_fileName[1].m_Storage.m_Memory.m_nAllocationCount = timeWrite_high;
            if ( v21 )
              break;
            v14 = fileList;
          }
        }
        ++bRecursea;
        if ( ++i >= dirList.m_Size )
          break;
        v4 = v27;
      }
    }
    CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>::RemoveAll(this: &dirList);
    v22 = dirList.m_Memory.m_pMemory;
    if ( dirList.m_Memory.m_nGrowSize >= 0 )
    {
      if ( dirList.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: dirList.m_Memory.m_pMemory);
        v22 = nullptr;
        dirList.m_Memory.m_pMemory = nullptr;
      }
      dirList.m_Memory.m_nAllocationCount = 0;
    }
    dirList.m_pElements = v22;
    if ( dirList.m_Memory.m_nGrowSize >= 0 )
    {
      if ( v22 != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v22);
        dirList.m_Memory.m_pMemory = nullptr;
      }
      dirList.m_Memory.m_nAllocationCount = 0;
    }
    CUtlVector<fileList_t,CUtlMemory<fileList_t,int>>::RemoveAll(this: &tempList);
    if ( tempList.m_Memory.m_nGrowSize < 0 )
    {
      return fileList->m_Size;
    }
    else
    {
      if ( tempList.m_Memory.m_pMemory != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: tempList.m_Memory.m_pMemory);
      return fileList->m_Size;
    }
  }
  else
  {
    CScriptLib::GetFileList(this: v4, pDirPath: dirPath, pPattern: pattern, fileList);
    return fileList->m_Size;
  }
}

} // namespace scenemanager

// ============================================================
// Overlay from studiomdl (Missing functions)
// ============================================================
namespace studiomdl {

//------------------------------------------------------------------------------
// Address: 0x0041F2B0
// Name: void (*SetScriptLoadedCallback(void (*)(char const __near *,char const __near *,int)))(char const __near *,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void (__cdecl *__cdecl SetScriptLoadedCallback(
        void (__cdecl *pfnNewScriptLoadedCallback)(const char *, const char *, int)))(const char *, const char *, int)
{
  void (__cdecl *result)(const char *, const char *, int); // eax

  result = g_pfnCallback;
  g_pfnCallback = pfnNewScriptLoadedCallback;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0041F2D0
// Name: void AddScriptToStack(char __near *,enum ScriptPathMode_t)
// Source: json
//------------------------------------------------------------------------------
void __cdecl AddScriptToStack(char *filename, ScriptPathMode_t pathMode)
{
  int File; // esi
  const char *v3; // [esp-8h] [ebp-8h]

  if ( ++script == (script_t *)token )
    _Error(a1: "script file exceeded MAX_INCLUDES");
  if ( pathMode == SCRIPT_USE_RELATIVE_PATH )
  {
    V_strncpy(pDest: script->filename, pSrc: filename, maxLen: 1024);
  }
  else
  {
    v3 = ExpandPath(path: filename);
    V_strncpy(pDest: script->filename, pSrc: v3, maxLen: 1024);
  }
  File = LoadFile(filename: script->filename, bufferptr: (void **)&script->buffer);
  if ( g_pfnCallback != nullptr )
  {
    if ( script == &scriptstack[1] )
      g_pfnCallback(a1: script->filename, a2: nullptr, a3: 0);
    else
      g_pfnCallback(a1: script->filename, a2: script[-1].filename, a3: script[-1].line);
  }
  script->line = 1;
  script->script_p = script->buffer;
  script->end_p = &script->buffer[File];
}

//------------------------------------------------------------------------------
// Address: 0x0041F3B0
// Name: void LoadScriptFile(char __near *,enum ScriptPathMode_t)
// Source: json
//------------------------------------------------------------------------------
void __cdecl LoadScriptFile(char *filename, ScriptPathMode_t pathMode)
{
  script = scriptstack;
  AddScriptToStack(filename, pathMode);
  endofscript = 0;
  tokenready = 0;
}

//------------------------------------------------------------------------------
// Address: 0x0041F3E0
// Name: bool AddMacroToStack(char __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl AddMacroToStack(char *macroname)
{
  int v2; // esi
  bool v3; // zf
  script_t *v4; // edi
  script_t *v5; // ebx
  int nummacroparams; // eax
  char *macrobuffer; // esi
  char **macroparam; // edi
  unsigned int v9; // esi
  script_t *pmacro; // [esp+4h] [ebp-4h]
  int i; // [esp+10h] [ebp+8h]

  if ( *macroname != 36 )
    return 0;
  v2 = 0;
  v3 = nummacros == 0;
  if ( nummacros > 0 )
  {
    do
    {
      if ( _V_stricmp(s1: macrolist[v2]->filename, s2: macroname + 1) == 0 )
        break;
      ++v2;
    }
    while ( v2 < nummacros );
    v3 = v2 == nummacros;
  }
  if ( v3 )
    return 0;
  v4 = macrolist[v2];
  v5 = script + 2;
  pmacro = v4;
  if ( &script[2] == (script_t *)token )
    _Error(a1: "script file exceeded MAX_INCLUDES");
  nummacroparams = v4->nummacroparams;
  macrobuffer = v5->macrobuffer;
  v5->nummacroparams = nummacroparams;
  i = 0;
  if ( nummacroparams > 0 )
  {
    macroparam = v5->macroparam;
    do
    {
      GetToken(crossline: 0);
      strcpy(macrobuffer, token);
      *macroparam = *(char **)((char *)macroparam + (char *)pmacro - (char *)v5);
      macroparam[64] = macrobuffer;
      macrobuffer += strlen(token) + 1;
      if ( macrobuffer >= (char *)v5->macroparam )
        _Error(a1: "Macro buffer overflow\n");
      ++macroparam;
      ++i;
    }
    while ( i < v5->nummacroparams );
    v4 = pmacro;
  }
  script = (script_t *)strcpy(v5->filename, v4->filename);
  v9 = v4->end_p - v4->buffer;
  script->buffer = (char *)MemAlloc_Alloc(nSize: v9 + 1);
  memcpy(dst: (unsigned __int8 *)script->buffer, src: (unsigned __int8 *)v4->buffer, count: v9);
  v4->buffer[v9] = 0;
  script->script_p = script->buffer;
  script->end_p = &script->buffer[v9];
  script->line = v4->line;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0041F5A0
// Name: bool ExpandMacroToken(char __near * __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl ExpandMacroToken(char **token_p)
{
  char *script_p; // eax
  _BYTE *v2; // ebx
  char v3; // al
  script_t *v5; // eax
  int v6; // esi
  int v7; // edi
  bool v8; // zf
  const char *v9; // edx
  unsigned int v10; // eax
  _BYTE *v11; // esi
  char v12; // cl
  char *s2; // [esp+0h] [ebp-4h]

  if ( script->nummacroparams == 0 )
    return 0;
  script_p = script->script_p;
  if ( *script_p != 36 )
    return 0;
  v2 = script_p + 1;
  s2 = script_p + 1;
  v3 = script_p[1];
  if ( v3 <= 32 )
  {
LABEL_6:
    if ( *v2 != 36 )
      return 0;
  }
  else
  {
    while ( v3 != 36 )
    {
      v3 = *++v2;
      if ( v3 <= 32 )
        goto LABEL_6;
    }
  }
  *v2 = 0;
  v5 = script;
  v6 = 0;
  if ( script->nummacroparams <= 0 )
    goto LABEL_13;
  v7 = 5136;
  do
  {
    v8 = _V_stricmp(s1: *(const char **)&v5->filename[v7], s2) == 0;
    v5 = script;
    if ( v8 )
      break;
    ++v6;
    v7 += 4;
  }
  while ( v6 < script->nummacroparams );
  if ( v6 >= script->nummacroparams )
  {
LABEL_13:
    _Error(a1: "unknown macro token \"%s\" in %s\n", s2, v5->filename);
    v5 = script;
  }
  v9 = v5->macrovalue[v6];
  v10 = strlen(v9);
  v11 = *token_p;
  do
  {
    v12 = *v9;
    *v11++ = *v9++;
  }
  while ( v12 != 0 );
  *token_p += v10;
  script->script_p = v2 + 1;
  if ( script->script_p >= script->end_p )
    _Error(a1: "Macro expand overflow\n");
  if ( *token_p >= (char *)&nummacros )
    _Error(a1: "Token too large on line %i\n", scriptline);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0041F6D0
// Name: void PushMemoryScript(char __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl PushMemoryScript(char *pszBuffer, int nSize)
{
  script_t *v2; // eax
  script_t *v3; // eax

  v2 = script;
  if ( script == nullptr )
    v2 = scriptstack;
  v3 = v2 + 1;
  script = v3;
  if ( v3 == (script_t *)token )
  {
    _Error(a1: "script file exceeded MAX_INCLUDES");
    v3 = script;
  }
  *(_QWORD *)v3->filename = *(_QWORD *)aMemoryB;
  strcpy(&script->filename[8], "uffer");
  script->buffer = pszBuffer;
  script->line = 1;
  script->script_p = script->buffer;
  script->end_p = &script->buffer[nSize];
  endofscript = 0;
  tokenready = 0;
}

//------------------------------------------------------------------------------
// Address: 0x0041F790
// Name: bool PopMemoryScript(void)
// Source: json
//------------------------------------------------------------------------------
char __cdecl PopMemoryScript()
{
  if ( _V_stricmp(s1: script->filename, s2: aMemoryB) != 0 )
    return 0;
  if ( script == scriptstack )
  {
    endofscript = 1;
    return 0;
  }
  --script;
  scriptline = script->line;
  endofscript = 0;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0041F7F0
// Name: void UnGetToken(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl UnGetToken()
{
  tokenready = 1;
}

//------------------------------------------------------------------------------
// Address: 0x0041F800
// Name: int EndOfScript(int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl EndOfScript(int crossline)
{
  if ( crossline == 0 )
    _Error(a1: "Line %i is incomplete\n", scriptline);
  if ( strcmp(script->filename, aMemoryB) == 0
    || (free(pMem: script->buffer), script->buffer = nullptr, script == &scriptstack[1]) )
  {
    endofscript = 1;
    return 0;
  }
  else
  {
    --script;
    scriptline = script->line;
    return GetToken(crossline);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041F8C0
// Name: int TokenAvailable(void)
// Source: json
//------------------------------------------------------------------------------
int __cdecl TokenAvailable()
{
  char *script_p; // eax
  char *end_p; // edx
  char v3; // cl
  char v4; // cl

  if ( tokenready != 0 )
    return 1;
  script_p = script->script_p;
  end_p = script->end_p;
  if ( script_p < end_p )
  {
    v3 = *script_p;
    if ( *script_p > 32 )
    {
LABEL_8:
      v4 = *script_p;
      if ( *script_p != 59 && v4 != 35 && (v4 != 47 || script_p[1] != 47) )
        return 1;
    }
    else
    {
      while ( v3 != 10 )
      {
        if ( ++script_p == end_p )
          break;
        v3 = *script_p;
        if ( *script_p > 32 )
          goto LABEL_8;
      }
    }
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x0041F920
// Name: int GetTokenizerStatus(char __near * __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl GetTokenizerStatus(char **pFilename, int *pLine)
{
  script_t *v2; // eax

  v2 = script;
  if ( script == nullptr || script->script_p >= script->end_p )
    return 0;
  if ( pFilename != nullptr )
  {
    *pFilename = (char *)script;
    v2 = script;
  }
  if ( pLine != nullptr )
    *pLine = v2->line;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0041F970
// Name: public: virtual bool CScriptLib::DoesFileExist(char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CScriptLib::DoesFileExist(CScriptLib *this, const char *pFilename)
{
  return g_pFullFileSystem->FileExists(this: &g_pFullFileSystem->IBaseFileSystem, a2: pFilename, a3: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x0041F990
// Name: public: virtual bool CScriptLib::ReadFileToBuffer(char const __near *,class CUtlBuffer __near &,bool,bool)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CScriptLib::ReadFileToBuffer(
        CScriptLib *this,
        const char *pSourceName,
        CUtlBuffer *buffer,
        bool bText,
        bool bNoOpenFailureWarning)
{
  int *v5; // eax
  const char *v6; // eax

  if ( g_pFullFileSystem->ReadFile(
         this: &g_pFullFileSystem->IBaseFileSystem,
         a2: pSourceName,
         a3: nullptr,
         a4: buffer,
         a5: 0,
         a6: 0,
         a7: nullptr) )
  {
    if ( bText )
      CUtlBuffer::SetBufferType(this: buffer, bIsText: true, bContainsCRLF: true);
    else
      CUtlBuffer::SetBufferType(this: buffer, bIsText: false, bContainsCRLF: false);
    return 1;
  }
  else
  {
    if ( !bNoOpenFailureWarning )
    {
      v5 = _errno();
      v6 = strerror(errnum: *v5);
      _Msg(a1: "ReadFileToBuffer(): Error opening %s: %s\n", pSourceName, v6);
    }
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041FA10
// Name: public: virtual bool CScriptLib::WriteBufferToFile(char const __near *,class CUtlBuffer __near &,enum DiskWriteMode_t)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CScriptLib::WriteBufferToFile(
        CScriptLib *this,
        const char *pTargetName,
        CUtlBuffer *buffer,
        DiskWriteMode_t writeMode)
{
  _BYTE *v5; // eax
  _BYTE *v6; // esi
  _BYTE *v7; // eax
  char dirPath[260]; // [esp+8h] [ebp-104h] BYREF

  strcpy(dirPath, pTargetName);
  strchr(string: (unsigned __int8 *)dirPath, chr: 0x5Cu);
  v6 = v5;
  if ( v5 != nullptr )
  {
    while ( 1 )
    {
      strchr(string: v6 + 1, chr: 0x5Cu);
      v6 = v7;
      if ( v7 == nullptr )
        break;
      *v7 = 0;
      _mkdir(path: dirPath);
      *v6 = 92;
    }
  }
  return writeMode != WRITE_TO_DISK_ALWAYS
      && (writeMode != WRITE_TO_DISK_UPDATE || !this->DoesFileExist(this, a2: pTargetName))
      || g_pFullFileSystem->WriteFile(
           this: &g_pFullFileSystem->IBaseFileSystem,
           a2: pTargetName,
           a3: nullptr,
           a4: buffer);
}

//------------------------------------------------------------------------------
// Address: 0x0041FB30
// Name: public: virtual char __near * CScriptLib::MakeTemporaryFilename(char const __near *,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CScriptLib::MakeTemporaryFilename(CScriptLib *this, const char *pchModPath, char *pPath, int pathSize)
{
  char *v4; // eax
  char *v5; // esi

  v4 = _tempnam(dir: pchModPath, pfx: "mgd_");
  v5 = v4;
  if ( *v4 == 92 )
    v5 = v4 + 1;
  if ( v5[strlen(v5) - 1] == 46 )
    v5[strlen(v5) - 1] = 0;
  V_snprintf(pDest: pPath, maxLen: pathSize, pFormat: "%s.tmp", v5);
  free(pMem: v5);
  return pPath;
}

//------------------------------------------------------------------------------
// Address: 0x0041FBA0
// Name: void DefineMacro(char __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DefineMacro(char *macroname)
{
  script_t *v1; // edi
  char *script_p; // esi
  char *macrobuffer; // ebx
  unsigned int v4; // ebx
  unsigned __int8 *v5; // eax
  int v6; // eax
  script_t *v7; // edx

  v1 = (script_t *)MemAlloc_Alloc(nSize: 0x1614u);
  strcpy(v1->filename, macroname);
  v1->line = script->line;
  v1->nummacroparams = 0;
  script_p = script->script_p;
  macrobuffer = v1->macrobuffer;
  while ( TokenAvailable() != 0 )
  {
    GetToken(crossline: 0);
    if ( token[0] == 92 && pModelName == 92 )
      break;
    script_p = script->script_p;
    v1->macroparam[v1->nummacroparams++] = macrobuffer;
    strcpy(macrobuffer, token);
    macrobuffer += strlen(token) + 1;
    if ( macrobuffer >= (char *)v1->macroparam )
      _Error(a1: "Macro buffer overflow\n");
  }
  for ( script->script_p = script_p; *script_p != 0; ++script_p )
  {
    if ( *script_p == 10 )
      break;
    if ( *script_p == 92 && script_p[1] == 92 )
    {
      do
      {
        if ( *script_p == 10 )
          break;
        *script_p++ = 32;
      }
      while ( *script_p != 0 );
      if ( *script_p == 0 )
        break;
    }
  }
  v4 = script_p - script->script_p;
  v5 = (unsigned __int8 *)MemAlloc_Alloc(nSize: v4 + 1);
  v1->buffer = (char *)v5;
  memcpy(dst: v5, src: (unsigned __int8 *)script->script_p, count: v4);
  v1->buffer[v4] = 0;
  v1->end_p = &v1->buffer[v4];
  v6 = nummacros;
  v7 = script;
  macrolist[nummacros] = v1;
  nummacros = v6 + 1;
  v7->script_p = script_p;
}

//------------------------------------------------------------------------------
// Address: 0x0041FDE0
// Name: bool ExpandVariableToken(char __near * __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl ExpandVariableToken(char **token_p)
{
  char *script_p; // ebx
  const char *v2; // ebx
  char *v3; // esi
  char v4; // al
  int v6; // esi
  int v7; // edi
  void (*v8)(const char *, ...); // ebx
  char *value; // edi
  unsigned int v10; // eax
  char *v11; // edx
  _BYTE *v12; // esi
  char v13; // cl
  const char *v14; // [esp-10h] [ebp-18h]
  char *cp; // [esp+4h] [ebp-4h]

  script_p = script->script_p;
  if ( *script_p != 36 )
    return 0;
  v2 = script_p + 1;
  v3 = (char *)v2;
  v4 = *v2;
  cp = (char *)v2;
  if ( *v2 <= 32 )
  {
LABEL_6:
    if ( *v3 != 36 )
      return 0;
  }
  else
  {
    while ( v4 != 36 )
    {
      v4 = *++v3;
      if ( v4 <= 32 )
      {
        cp = v3;
        goto LABEL_6;
      }
    }
    cp = v3;
  }
  v6 = v3 - v2;
  v7 = 0;
  v2[v6] = 0;
  if ( g_definevariable.m_Size <= 0 )
    goto LABEL_14;
  while ( V_strnicmp(s1: g_definevariable.m_Memory.m_pMemory[v7].param, s2: v2, n: v6) != 0 )
  {
    if ( ++v7 >= g_definevariable.m_Size )
      goto LABEL_14;
  }
  if ( v7 < g_definevariable.m_Size )
  {
    v8 = (void (*)(const char *, ...))_Error;
  }
  else
  {
LABEL_14:
    v14 = v2;
    v8 = (void (*)(const char *, ...))_Error;
    _Error(a1: "unknown variable token \"%s\" in %s\n", v14, script->filename);
  }
  value = g_definevariable.m_Memory.m_pMemory[v7].value;
  v10 = strlen(value);
  v11 = value;
  v12 = *token_p;
  do
  {
    v13 = *v11;
    *v12++ = *v11++;
  }
  while ( v13 != 0 );
  *token_p += v10;
  script->script_p = cp + 1;
  if ( script->script_p >= script->end_p )
    v8(a1: "Macro expand overflow\n");
  if ( *token_p >= (char *)&nummacros )
    v8(a1: "Token too large on line %i\n", scriptline);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0041FFF0
// Name: void DefineVariable(char __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DefineVariable(char *variablename)
{
  char *v1; // eax
  char *v2; // eax
  char *v3; // ecx
  char v4; // dl
  variable_t v; // [esp+8h] [ebp-8h] BYREF

  if ( variablename != nullptr
    && (v1 = (char *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: strlen(variablename) + 1)) != nullptr )
  {
    strcpy(v1, variablename);
  }
  else
  {
    v1 = nullptr;
  }
  v.param = v1;
  GetToken(crossline: 0);
  v2 = (char *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: strlen(token) + 1);
  if ( v2 != nullptr )
  {
    v3 = v2;
    do
    {
      v4 = v3[token - v2];
      *v3++ = v4;
    }
    while ( v4 != 0 );
  }
  else
  {
    v2 = nullptr;
  }
  v.value = v2;
  CUtlVector<variable_t,CUtlMemory<variable_t,int>>::InsertBefore(
    this: &g_definevariable,
    elem: g_definevariable.m_Size,
    src: &v);
}

//------------------------------------------------------------------------------
// Address: 0x004200B0
// Name: int GetToken(int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl GetToken(int crossline)
{
  script_t *v1; // eax
  char *script_p; // ecx
  char v3; // dl
  script_t *v4; // eax
  char *v5; // ecx
  char *v6; // edx
  char v7; // cl
  char *v8; // ecx
  char v9; // dl
  script_t *v10; // eax
  char *v11; // edx
  script_t *v12; // eax
  int line; // edx
  char v14; // cl
  char *v15; // esi
  script_t *v16; // eax
  char i; // cl
  char *v18; // esi
  char *v19; // ecx
  char *token_p; // [esp+Ch] [ebp-4h] BYREF

  if ( tokenready != 0 )
  {
LABEL_54:
    tokenready = 0;
    return 1;
  }
  else
  {
    while ( 1 )
    {
      v1 = script;
      if ( script->script_p >= script->end_p )
        return EndOfScript(crossline);
      tokenready = 0;
      while ( 1 )
      {
        while ( 1 )
        {
          if ( *v1->script_p <= 32 )
          {
            do
            {
              script_p = v1->script_p;
              if ( script_p >= v1->end_p )
                return EndOfScript(crossline);
              v3 = *script_p;
              v1->script_p = script_p + 1;
              if ( v3 == 10 )
              {
                if ( crossline == 0 )
                  _Error(a1: "Line %i is incomplete\n", scriptline);
                v4 = script;
                ++script->line;
                scriptline = v4->line;
              }
              v1 = script;
            }
            while ( *script->script_p <= 32 );
          }
          v5 = v1->script_p;
          if ( v5 >= v1->end_p )
            return EndOfScript(crossline);
          v6 = v1->script_p;
          v7 = *v5;
          if ( v7 != 59 && v7 != 35 )
          {
            if ( v7 != 47 )
              goto LABEL_30;
            if ( v6[1] != 47 )
              break;
          }
          if ( crossline == 0 )
          {
            _Error(a1: "Line %i is incomplete\n", scriptline);
            v1 = script;
          }
          if ( *v1->script_p != 10 )
          {
            do
            {
              ++v1->script_p;
              v1 = script;
              v11 = script->script_p;
              if ( v11 >= script->end_p )
                return EndOfScript(crossline);
            }
            while ( *v11 != 10 );
          }
          ++v1->script_p;
          v12 = script;
          ++script->line;
          line = v12->line;
          v1 = script;
          scriptline = line;
        }
        if ( v6[1] != 42 )
          break;
        v1->script_p += 2;
        while ( 1 )
        {
          v8 = script->script_p;
          if ( *v8 == 42 && v8[1] == 47 )
            break;
          v9 = *v8;
          script->script_p = v8 + 1;
          if ( v9 != 10 )
          {
            v10 = script;
            if ( script->script_p >= script->end_p )
              return EndOfScript(crossline);
            ++script->line;
            scriptline = v10->line;
          }
        }
        script->script_p += 2;
        v1 = script;
      }
LABEL_30:
      v14 = *v6;
      v15 = token;
      token_p = token;
      if ( v14 == 34 )
      {
        ++v1->script_p;
        v16 = script;
        for ( i = *script->script_p; i != 34; i = *v16->script_p )
        {
          *v15 = i;
          ++script->script_p;
          v16 = script;
          ++v15;
          if ( script->script_p == script->end_p )
            break;
          if ( v15 == (char *)&nummacros )
          {
            _Error(a1: "Token too large on line %i\n", scriptline);
            v16 = script;
          }
        }
        ++v16->script_p;
      }
      else
      {
        for ( ; v14 > 32; v14 = *script->script_p )
        {
          if ( v14 == 59 )
            break;
          if ( ExpandMacroToken(&token_p) != 0 || ExpandVariableToken(&token_p) != 0 )
          {
            v15 = token_p;
          }
          else
          {
            v18 = token_p;
            *token_p = *script->script_p++;
            v19 = script->script_p;
            v15 = v18 + 1;
            token_p = v15;
            if ( v19 == script->end_p )
              break;
            if ( v15 == (char *)&nummacros )
              _Error(a1: "Token too large on line %i\n", scriptline);
          }
        }
      }
      *v15 = 0;
      if ( _V_stricmp(s1: token, s2: "$include") != 0 )
      {
        if ( _V_stricmp(s1: token, s2: "$definemacro") != 0 )
        {
          if ( _V_stricmp(s1: token, s2: "$definevariable") != 0 )
          {
            if ( AddMacroToStack(macroname: token) == 0 )
              return 1;
          }
          else
          {
            GetToken(crossline: 0);
            DefineVariable(variablename: token);
          }
        }
        else
        {
          GetToken(crossline: 0);
          DefineMacro(macroname: token);
        }
      }
      else
      {
        GetToken(crossline: 0);
        AddScriptToStack(filename: token, pathMode: SCRIPT_USE_ABSOLUTE_PATH);
      }
      if ( tokenready != 0 )
        goto LABEL_54;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004204B0
// Name: int GetExprToken(int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl GetExprToken(int crossline)
{
  script_t *v2; // eax
  char *v3; // edx
  char v4; // dl
  script_t *v5; // eax
  char *script_p; // ecx
  char *v7; // edx
  char v8; // cl
  char *v9; // edx
  char *v10; // esi
  script_t *v11; // eax
  bool v12; // zf
  script_t *v13; // eax
  char v14; // cl
  char *v15; // ecx
  script_t *v16; // eax
  script_t *v17; // eax

  if ( tokenready != 0 )
  {
    tokenready = 0;
    return 1;
  }
  else
  {
    v2 = script;
    if ( script->script_p < script->end_p )
    {
      tokenready = 0;
      while ( *v2->script_p > 32 )
      {
LABEL_13:
        script_p = v2->script_p;
        if ( script_p >= v2->end_p )
          return EndOfScript(crossline);
        v7 = v2->script_p;
        v8 = *script_p;
        if ( v8 != 59 && v8 != 35 && (v8 != 47 || v7[1] != 47) )
        {
          v10 = token;
          if ( *v7 == 34 )
          {
            ++v2->script_p;
            v11 = script;
            while ( *v11->script_p != 34 )
            {
              *v10 = *v11->script_p++;
              v11 = script;
              ++v10;
              if ( script->script_p == script->end_p )
                break;
              if ( v10 == (char *)&nummacros )
              {
                _Error(a1: "Token too large on line %i\n", scriptline);
                v11 = script;
              }
            }
LABEL_31:
            ++v11->script_p;
          }
          else
          {
            v12 = isalpha(c: *v7) == 0;
            v13 = script;
            if ( !v12 || (v14 = *script->script_p) == 95 )
            {
              while ( 1 )
              {
                v12 = isalnum(c: *v13->script_p) == 0;
                v17 = script;
                if ( v12 && *script->script_p != 95 )
                  break;
                *v10 = *script->script_p;
                ++v17->script_p;
                v13 = script;
                ++v10;
                if ( script->script_p == script->end_p )
                  break;
                if ( v10 == (char *)&nummacros )
                {
                  _Error(a1: "Token too large on line %i\n", scriptline);
                  v13 = script;
                }
              }
            }
            else
            {
              v12 = isdigit(c: v14) == 0;
              v11 = script;
              if ( v12 )
              {
                v15 = script->script_p;
                if ( *v15 != 46 )
                {
                  token[0] = *v15;
                  v10 = &pModelName;
                  goto LABEL_31;
                }
              }
              while ( 1 )
              {
                v12 = isdigit(c: *v11->script_p) == 0;
                v16 = script;
                if ( v12 && *script->script_p != 46 )
                  break;
                *v10 = *script->script_p;
                ++v16->script_p;
                v11 = script;
                ++v10;
                if ( script->script_p == script->end_p )
                  break;
                if ( v10 == (char *)&nummacros )
                {
                  _Error(a1: "Token too large on line %i\n", scriptline);
                  v11 = script;
                }
              }
            }
          }
          *v10 = 0;
          if ( _V_stricmp(s1: token, s2: "$include") != 0 )
            return 1;
          GetToken(crossline: 0);
          AddScriptToStack(filename: token, pathMode: SCRIPT_USE_ABSOLUTE_PATH);
          return GetToken(crossline);
        }
        if ( crossline == 0 )
        {
          _Error(a1: "Line %i is incomplete\n", scriptline);
          v2 = script;
        }
        if ( *v2->script_p != 10 )
        {
          do
          {
            ++v2->script_p;
            v2 = script;
            v9 = script->script_p;
            if ( v9 >= script->end_p )
              return EndOfScript(crossline);
          }
          while ( *v9 != 10 );
        }
        ++v2->script_p;
        v2 = script;
      }
      while ( 1 )
      {
        v3 = v2->script_p;
        if ( v3 >= v2->end_p )
          break;
        v4 = *v3;
        ++v2->script_p;
        if ( v4 == 10 )
        {
          if ( crossline == 0 )
            _Error(a1: "Line %i is incomplete\n", scriptline);
          v5 = script;
          ++script->line;
          scriptline = v5->line;
        }
        v2 = script;
        if ( *script->script_p > 32 )
          goto LABEL_13;
      }
    }
    return EndOfScript(crossline);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00420A50
// Name: private: int CScriptLib::GetFileList(char const __near *,char const __near *,class CUtlVector<struct fileList_t,class CUtlMemory<struct fileList_t,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CScriptLib::GetFileList(
        CScriptLib *this,
        const char *pDirPath,
        const char *pPattern,
        CUtlVector<fileList_t,CUtlMemory<fileList_t,int> > *fileList)
{
  unsigned int v5; // kr00_4
  int v6; // eax
  char v7; // cl
  char *v8; // edi
  char v9; // al
  unsigned int v10; // eax
  char *v11; // edi
  char v12; // cl
  int v13; // esi
  int v15; // eax
  char v16; // cl
  unsigned int v17; // eax
  char *v18; // edi
  char v19; // cl
  char *v20; // edi
  char *v21; // esi
  char v22; // cl
  int m_Size; // eax
  int v24; // esi
  char v25; // [esp+Bh] [ebp-435h] BYREF
  char fileName[260]; // [esp+Ch] [ebp-434h] BYREF
  char fullPath[260]; // [esp+110h] [ebp-330h] BYREF
  _finddata64i32_t findData; // [esp+214h] [ebp-22Ch] BYREF
  char sourcePath[260]; // [esp+33Ch] [ebp-104h] BYREF
  int h; // [esp+448h] [ebp+8h]
  char bFindDirs_3; // [esp+453h] [ebp+13h]

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
  v5 = strlen(sourcePath);
  if ( v5 != 0 )
  {
    if ( findData.name[v5 + 259] != 92 )
    {
      sourcePath[v5] = 92;
      sourcePath[v5 + 1] = 0;
    }
  }
  else
  {
    strcpy(sourcePath, ".\\");
  }
  v6 = 0;
  do
  {
    v7 = sourcePath[v6];
    fullPath[v6++] = v7;
  }
  while ( v7 != 0 );
  if ( *pPattern != 92 || pPattern[1] != 0 )
  {
    bFindDirs_3 = 0;
    v10 = strlen(pPattern) + 1;
    v11 = &fileName[259];
    do
      v12 = *++v11;
    while ( v12 != 0 );
    qmemcpy(v11, pPattern, v10);
  }
  else
  {
    bFindDirs_3 = 1;
    v8 = &fileName[259];
    do
      v9 = *++v8;
    while ( v9 != 0 );
    strcpy(v8, "*");
  }
  v13 = _findfirst64i32(szWild: fullPath, pfd: &findData);
  h = v13;
  if ( v13 == -1 )
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
      v15 = 0;
      do
      {
        v16 = sourcePath[v15];
        fileName[v15++] = v16;
      }
      while ( v16 != 0 );
      v17 = strlen(findData.name) + 1;
      v18 = &v25;
      do
        v19 = *++v18;
      while ( v19 != 0 );
      qmemcpy(v18, findData.name, 4 * (v17 >> 2));
      v21 = &findData.name[4 * (v17 >> 2)];
      v20 = &v18[4 * (v17 >> 2)];
      v22 = v17;
      m_Size = fileList->m_Size;
      qmemcpy(v20, v21, v22 & 3);
      v24 = CUtlVector<fileList_t,CUtlMemory<fileList_t,int>>::InsertBefore(this: fileList, elem: m_Size);
      CUtlString::Set(this: &fileList->m_Memory.m_pMemory[v24].fileName, pValue: fileName);
      fileList->m_Memory.m_pMemory[v24].timeWrite = findData.time_write;
      v13 = h;
    }
  }
  while ( _findnext64i32(hFile: v13, pfd: &findData) == 0 );
  _findclose(hFile: v13);
  return fileList->m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x00420D10
// Name: public: virtual void CScriptLib::DeleteTemporaryFiles(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CScriptLib::DeleteTemporaryFiles(CScriptLib *this, const char *pFileMask)
{
  char *v2; // eax
  char *v3; // edx
  char v4; // cl
  unsigned int v5; // eax
  char *v6; // edi
  char v7; // cl
  int (__thiscall *FindFiles)(struct CScriptLib *, char *, bool, CUtlVector<fileList_t,CUtlMemory<fileList_t,int> > *); // edx
  int v9; // esi
  int v10; // edi
  const char *v11; // eax
  fileList_t *m_pMemory; // eax
  char v13; // [esp+3h] [ebp-11Dh] BYREF
  char tempPath[260]; // [esp+4h] [ebp-11Ch] BYREF
  CScriptLib *v15; // [esp+108h] [ebp-18h]
  CUtlVector<fileList_t,CUtlMemory<fileList_t,int> > fileList; // [esp+10Ch] [ebp-14h] BYREF

  v15 = this;
  v2 = getenv(option: "temp");
  if ( v2 != nullptr || (v2 = getenv(option: "tmp")) != nullptr )
  {
    v3 = (char *)(tempPath - v2);
    do
    {
      v4 = *v2;
      v2[(_DWORD)v3] = *v2;
      ++v2;
    }
    while ( v4 != 0 );
    V_AppendSlash(pStr: tempPath, strSize: 260);
    v5 = strlen(pFileMask) + 1;
    v6 = &v13;
    do
      v7 = *++v6;
    while ( v7 != 0 );
    qmemcpy(v6, pFileMask, v5);
    FindFiles = v15->FindFiles;
    memset(&fileList, 0, sizeof(fileList));
    FindFiles(this: v15, a2: tempPath, a3: false, a4: &fileList);
    v9 = 0;
    if ( fileList.m_Size > 0 )
    {
      v10 = 0;
      do
      {
        v11 = CUtlString::operator char const *(this: &fileList.m_Memory.m_pMemory[v10].fileName);
        unlink(path: v11);
        ++v9;
        ++v10;
      }
      while ( v9 < fileList.m_Size );
    }
    CUtlVector<fileList_t,CUtlMemory<fileList_t,int>>::RemoveAll(this: &fileList);
    m_pMemory = fileList.m_Memory.m_pMemory;
    if ( fileList.m_Memory.m_nGrowSize >= 0 )
    {
      if ( fileList.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: fileList.m_Memory.m_pMemory);
        m_pMemory = nullptr;
        fileList.m_Memory.m_pMemory = nullptr;
      }
      fileList.m_Memory.m_nAllocationCount = 0;
    }
    fileList.m_pElements = m_pMemory;
    if ( fileList.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00420E40
// Name: private: void CScriptLib::RecurseFileTree_r(char const __near *,int,class CUtlVector<class CUtlString,class CUtlMemory<class CUtlString,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CScriptLib::RecurseFileTree_r(
        CScriptLib *this,
        const char *pDirPath,
        int depth,
        CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *dirList)
{
  fileList_t *i; // ebx
  int v5; // eax
  int v6; // eax
  fileList_t *m_pMemory; // edi
  const char *v8; // eax
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CUtlString *v11; // ecx
  int v12; // eax
  int v13; // edi
  CUtlString *v14; // ecx
  CUtlVector<fileList_t,CUtlMemory<fileList_t,int> > fileList; // [esp+Ch] [ebp-18h] BYREF
  CScriptLib *v16; // [esp+20h] [ebp-4h]

  i = nullptr;
  v16 = this;
  memset(&fileList, 0, sizeof(fileList));
  v5 = CScriptLib::GetFileList(this, pDirPath, pPattern: "\\", &fileList);
  if ( v5 != 0 )
  {
    if ( v5 > 0 )
    {
      m_pMemory = fileList.m_Memory.m_pMemory;
      for ( i = (fileList_t *)v5; i != nullptr; i = (fileList_t *)((char *)i - 1) )
      {
        v8 = CUtlString::operator char const *(this: &m_pMemory->fileName);
        CScriptLib::RecurseFileTree_r(this: v16, pDirPath: v8, depth: depth + 1, dirList);
        ++m_pMemory;
      }
    }
    m_Size = dirList->m_Size;
    m_nAllocationCount = dirList->m_Memory.m_nAllocationCount;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<ActiveLayer_t<QAngle>,int>::Grow(
        this: (CUtlMemory<ActiveLayer_t<CUtlSymbolLarge>,int> *)dirList,
        num: m_Size - m_nAllocationCount + 1);
    ++dirList->m_Size;
    v11 = dirList->m_Memory.m_pMemory;
    v12 = dirList->m_Size - m_Size - 1;
    dirList->m_pElements = dirList->m_Memory.m_pMemory;
    if ( v12 > (int)i )
      _V_memmove(dest: &v11[m_Size + 1], src: &v11[m_Size], count: 16 * v12);
    v13 = m_Size;
    v14 = &dirList->m_Memory.m_pMemory[v13];
    if ( v14 != nullptr )
      CUtlString::CUtlString(this: v14);
    CUtlString::Set(this: &dirList->m_Memory.m_pMemory[v13], pValue: pDirPath);
    CUtlVector<fileList_t,CUtlMemory<fileList_t,int>>::RemoveAll(this: &fileList);
    if ( fileList.m_Memory.m_nGrowSize >= (int)i && fileList.m_Memory.m_pMemory != i )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: fileList.m_Memory.m_pMemory);
  }
  else
  {
    v6 = CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>::InsertBefore(this: dirList, elem: dirList->m_Size);
    CUtlString::Set(this: &dirList->m_Memory.m_pMemory[v6], pValue: pDirPath);
    CUtlVector<fileList_t,CUtlMemory<fileList_t,int>>::~CUtlVector<fileList_t,CUtlMemory<fileList_t,int>>(this: &fileList);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00420F60
// Name: public: virtual int CScriptLib::FindFiles(char __near *,bool,class CUtlVector<struct fileList_t,class CUtlMemory<struct fileList_t,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CScriptLib::FindFiles(
        CScriptLib *this,
        char *pFileMask,
        bool bRecurse,
        CUtlVector<fileList_t,CUtlMemory<fileList_t,int> > *fileList)
{
  CScriptLib *v4; // edi
  char *v5; // edi
  char v6; // al
  unsigned int v7; // eax
  char *v8; // edi
  char v9; // cl
  int m_nGrowSize; // esi
  fileList_t *m_pMemory; // eax
  const char *v13; // eax
  CUtlVector<fileList_t,CUtlMemory<fileList_t,int> > *v14; // esi
  int m_Size; // edi
  int inserted; // eax
  fileList_t *v17; // edi
  int v18; // ebx
  CUtlString *p_fileName; // esi
  int timeWrite_high; // eax
  bool v21; // zf
  CUtlString *v22; // eax
  unsigned int v23; // [esp-8h] [ebp-34Ch]
  char extension[260]; // [esp+8h] [ebp-33Ch] BYREF
  char dirPath[260]; // [esp+10Ch] [ebp-238h] BYREF
  char pattern[260]; // [esp+210h] [ebp-134h] BYREF
  CScriptLib *v27; // [esp+314h] [ebp-30h]
  int i; // [esp+318h] [ebp-2Ch]
  CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > dirList; // [esp+31Ch] [ebp-28h] BYREF
  CUtlVector<fileList_t,CUtlMemory<fileList_t,int> > tempList; // [esp+330h] [ebp-14h] BYREF
  char *pFileMaska; // [esp+34Ch] [ebp+8h]
  int bRecursea; // [esp+350h] [ebp+Ch]

  v4 = this;
  v27 = this;
  strcpy(dirPath, pFileMask);
  V_StripFilename(path: dirPath);
  V_FileBase(in: pFileMask, out: pattern, maxlen: 260);
  V_ExtractFileExtension(path: pFileMask, dest: extension, destSize: 260);
  if ( extension[0] != 0 )
  {
    v5 = &dirPath[259];
    do
      v6 = *++v5;
    while ( v6 != 0 );
    strcpy(v5, ".");
    v7 = strlen(extension) + 1;
    v8 = &dirPath[259];
    do
      v9 = *++v8;
    while ( v9 != 0 );
    qmemcpy(v8, extension, v7);
    v4 = v27;
  }
  if ( bRecurse )
  {
    memset(&tempList, 0, sizeof(tempList));
    memset(&dirList, 0, sizeof(dirList));
    CScriptLib::RecurseFileTree_r(this: v4, pDirPath: dirPath, depth: 0, &dirList);
    i = 0;
    if ( dirList.m_Size > 0 )
    {
      bRecursea = 0;
      while ( 1 )
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
          v23 = 24 * dirList.m_Size;
          if ( m_pMemory != nullptr )
            m_pMemory = (fileList_t *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v23);
          else
            m_pMemory = (fileList_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v23);
          tempList.m_Memory.m_pMemory = m_pMemory;
        }
        tempList.m_pElements = m_pMemory;
        v13 = CUtlString::operator char const *(this: &dirList.m_Memory.m_pMemory[bRecursea]);
        CScriptLib::GetFileList(this: v4, pDirPath: v13, pPattern: pattern, fileList: &tempList);
        v14 = fileList;
        m_Size = tempList.m_Size;
        inserted = CUtlVector<fileList_t,CUtlMemory<fileList_t,int>>::InsertMultipleBefore(
                     this: fileList,
                     elem: fileList->m_Size,
                     num: tempList.m_Size);
        if ( m_Size > 0 )
        {
          v17 = tempList.m_Memory.m_pMemory;
          v18 = inserted;
          pFileMaska = (char *)tempList.m_Size;
          while ( 1 )
          {
            p_fileName = &v14->m_Memory.m_pMemory[v18].fileName;
            CUtlString::operator=(this: p_fileName, src: &v17->fileName);
            p_fileName[1].m_Storage.m_Memory.m_pMemory = (unsigned __int8 *)v17->timeWrite;
            timeWrite_high = HIDWORD(v17->timeWrite);
            ++v17;
            ++v18;
            v21 = pFileMaska-- == (char *)1;
            p_fileName[1].m_Storage.m_Memory.m_nAllocationCount = timeWrite_high;
            if ( v21 )
              break;
            v14 = fileList;
          }
        }
        ++bRecursea;
        if ( ++i >= dirList.m_Size )
          break;
        v4 = v27;
      }
    }
    CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::RemoveAll(this: (CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int> > *)&dirList);
    v22 = dirList.m_Memory.m_pMemory;
    if ( dirList.m_Memory.m_nGrowSize >= 0 )
    {
      if ( dirList.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: dirList.m_Memory.m_pMemory);
        v22 = nullptr;
        dirList.m_Memory.m_pMemory = nullptr;
      }
      dirList.m_Memory.m_nAllocationCount = 0;
    }
    dirList.m_pElements = v22;
    if ( dirList.m_Memory.m_nGrowSize >= 0 )
    {
      if ( v22 != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v22);
        dirList.m_Memory.m_pMemory = nullptr;
      }
      dirList.m_Memory.m_nAllocationCount = 0;
    }
    CUtlVector<fileList_t,CUtlMemory<fileList_t,int>>::RemoveAll(this: &tempList);
    if ( tempList.m_Memory.m_nGrowSize < 0 )
    {
      return fileList->m_Size;
    }
    else
    {
      if ( tempList.m_Memory.m_pMemory != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: tempList.m_Memory.m_pMemory);
      return fileList->m_Size;
    }
  }
  else
  {
    CScriptLib::GetFileList(this: v4, pDirPath: dirPath, pPattern: pattern, fileList);
    return fileList->m_Size;
  }
}

} // namespace studiomdl

// ============================================================
// Overlay from unusedcontent (Missing functions)
// ============================================================
namespace unusedcontent {

//------------------------------------------------------------------------------
// Address: 0x004038C0
// Name: void DefaultScriptLoadedCallback(char const __near *,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DefaultScriptLoadedCallback()
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x004038D0
// Name: public: virtual bool CScriptLib::DoesFileExist(char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CScriptLib::DoesFileExist(CScriptLib *this, const char *pFilename)
{
  return g_pFullFileSystem->FileExists(this: &g_pFullFileSystem->IBaseFileSystem, a2: pFilename, a3: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x004038F0
// Name: public: virtual bool CScriptLib::ReadFileToBuffer(char const __near *,class CUtlBuffer __near &,bool,bool)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CScriptLib::ReadFileToBuffer(
        CScriptLib *this,
        const char *pSourceName,
        CUtlBuffer *buffer,
        bool bText,
        bool bNoOpenFailureWarning)
{
  int *v5; // eax
  const char *v6; // eax

  if ( g_pFullFileSystem->ReadFile(
         this: &g_pFullFileSystem->IBaseFileSystem,
         a2: pSourceName,
         a3: nullptr,
         a4: buffer,
         a5: 0,
         a6: 0,
         a7: nullptr) )
  {
    if ( bText )
      CUtlBuffer::SetBufferType(this: buffer, bIsText: true, bContainsCRLF: true);
    else
      CUtlBuffer::SetBufferType(this: buffer, bIsText: false, bContainsCRLF: false);
    return 1;
  }
  else
  {
    if ( !bNoOpenFailureWarning )
    {
      v5 = _errno();
      v6 = strerror(errnum: *v5);
      _Msg(a1: "ReadFileToBuffer(): Error opening %s: %s\n", pSourceName, v6);
    }
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00403970
// Name: public: virtual bool CScriptLib::WriteBufferToFile(char const __near *,class CUtlBuffer __near &,enum DiskWriteMode_t)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CScriptLib::WriteBufferToFile(
        CScriptLib *this,
        const char *pTargetName,
        CUtlBuffer *buffer,
        DiskWriteMode_t writeMode)
{
  _BYTE *v5; // eax
  _BYTE *v6; // esi
  _BYTE *v7; // eax
  char dirPath[260]; // [esp+8h] [ebp-104h] BYREF

  strcpy(dirPath, pTargetName);
  strchr(string: (unsigned __int8 *)dirPath, chr: 0x5Cu);
  v6 = v5;
  if ( v5 != nullptr )
  {
    while ( 1 )
    {
      strchr(string: v6 + 1, chr: 0x5Cu);
      v6 = v7;
      if ( v7 == nullptr )
        break;
      *v7 = 0;
      _mkdir(path: dirPath);
      *v6 = 92;
    }
  }
  return writeMode != WRITE_TO_DISK_ALWAYS
      && (writeMode != WRITE_TO_DISK_UPDATE || !this->DoesFileExist(this, a2: pTargetName))
      || g_pFullFileSystem->WriteFile(
           this: &g_pFullFileSystem->IBaseFileSystem,
           a2: pTargetName,
           a3: nullptr,
           a4: buffer);
}

//------------------------------------------------------------------------------
// Address: 0x00403A30
// Name: public: virtual int CScriptLib::CompareFileTime(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CScriptLib::CompareFileTime(CScriptLib *this, const char *pFilenameA, const char *pFilenameB)
{
  unsigned int v3; // esi
  unsigned int v4; // eax
  bool v5; // cf

  v3 = g_pFullFileSystem->GetFileTime(this: &g_pFullFileSystem->IBaseFileSystem, a2: pFilenameA, a3: nullptr);
  v4 = g_pFullFileSystem->GetFileTime(this: &g_pFullFileSystem->IBaseFileSystem, a2: pFilenameB, a3: nullptr);
  if ( v3 == -1 )
    v3 = 0;
  if ( v4 == -1 )
    return v3 != 0;
  v5 = v4 < v3;
  if ( v4 <= v3 )
    return v5;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00403A90
// Name: public: virtual char __near * CScriptLib::MakeTemporaryFilename(char const __near *,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CScriptLib::MakeTemporaryFilename(CScriptLib *this, const char *pchModPath, char *pPath, int pathSize)
{
  char *v4; // eax
  char *v5; // esi

  v4 = _tempnam(dir: pchModPath, pfx: "mgd_");
  v5 = v4;
  if ( *v4 == 92 )
    v5 = v4 + 1;
  if ( v5[strlen(v5) - 1] == 46 )
    v5[strlen(v5) - 1] = 0;
  V_snprintf(pDest: pPath, maxLen: pathSize, pFormat: "%s.tmp", v5);
  free(pMem: v5);
  return pPath;
}

//------------------------------------------------------------------------------
// Address: 0x00403E90
// Name: private: int CScriptLib::GetFileList(char const __near *,char const __near *,class CUtlVector<struct fileList_t,class CUtlMemory<struct fileList_t,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CScriptLib::GetFileList(
        CScriptLib *this,
        const char *pDirPath,
        const char *pPattern,
        CUtlVector<fileList_t,CUtlMemory<fileList_t,int> > *fileList)
{
  unsigned int v5; // kr00_4
  int v6; // eax
  char v7; // cl
  char *v8; // edi
  char v9; // al
  unsigned int v10; // eax
  char *v11; // edi
  char v12; // cl
  int v13; // esi
  int v15; // eax
  char v16; // cl
  unsigned int v17; // eax
  char *v18; // edi
  char v19; // cl
  char *v20; // edi
  char *v21; // esi
  char v22; // cl
  int m_Size; // eax
  int v24; // esi
  char v25; // [esp+Bh] [ebp-435h] BYREF
  char fileName[260]; // [esp+Ch] [ebp-434h] BYREF
  char fullPath[260]; // [esp+110h] [ebp-330h] BYREF
  _finddata64i32_t findData; // [esp+214h] [ebp-22Ch] BYREF
  char sourcePath[260]; // [esp+33Ch] [ebp-104h] BYREF
  int h; // [esp+448h] [ebp+8h]
  char bFindDirs_3; // [esp+453h] [ebp+13h]

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
  v5 = strlen(sourcePath);
  if ( v5 != 0 )
  {
    if ( findData.name[v5 + 259] != 92 )
    {
      sourcePath[v5] = 92;
      sourcePath[v5 + 1] = 0;
    }
  }
  else
  {
    strcpy(sourcePath, ".\\");
  }
  v6 = 0;
  do
  {
    v7 = sourcePath[v6];
    fullPath[v6++] = v7;
  }
  while ( v7 != 0 );
  if ( *pPattern != 92 || pPattern[1] != 0 )
  {
    bFindDirs_3 = 0;
    v10 = strlen(pPattern) + 1;
    v11 = &fileName[259];
    do
      v12 = *++v11;
    while ( v12 != 0 );
    qmemcpy(v11, pPattern, v10);
  }
  else
  {
    bFindDirs_3 = 1;
    v8 = &fileName[259];
    do
      v9 = *++v8;
    while ( v9 != 0 );
    strcpy(v8, "*");
  }
  v13 = _findfirst64i32(szWild: fullPath, pfd: &findData);
  h = v13;
  if ( v13 == -1 )
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
      v15 = 0;
      do
      {
        v16 = sourcePath[v15];
        fileName[v15++] = v16;
      }
      while ( v16 != 0 );
      v17 = strlen(findData.name) + 1;
      v18 = &v25;
      do
        v19 = *++v18;
      while ( v19 != 0 );
      qmemcpy(v18, findData.name, 4 * (v17 >> 2));
      v21 = &findData.name[4 * (v17 >> 2)];
      v20 = &v18[4 * (v17 >> 2)];
      v22 = v17;
      m_Size = fileList->m_Size;
      qmemcpy(v20, v21, v22 & 3);
      v24 = CUtlVector<fileList_t,CUtlMemory<fileList_t,int>>::InsertBefore(this: fileList, elem: m_Size);
      CUtlString::Set(this: &fileList->m_Memory.m_pMemory[v24].fileName, pValue: fileName);
      fileList->m_Memory.m_pMemory[v24].timeWrite = findData.time_write;
      v13 = h;
    }
  }
  while ( _findnext64i32(hFile: v13, pfd: &findData) == 0 );
  _findclose(hFile: v13);
  return fileList->m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x00404150
// Name: public: virtual void CScriptLib::DeleteTemporaryFiles(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CScriptLib::DeleteTemporaryFiles(CScriptLib *this, const char *pFileMask)
{
  char *v2; // eax
  char *v3; // edx
  char v4; // cl
  unsigned int v5; // eax
  char *v6; // edi
  char v7; // cl
  int (__thiscall *FindFiles)(struct CScriptLib *, char *, bool, CUtlVector<fileList_t,CUtlMemory<fileList_t,int> > *); // edx
  int v9; // esi
  int v10; // edi
  const char *v11; // eax
  fileList_t *m_pMemory; // eax
  char v13; // [esp+3h] [ebp-11Dh] BYREF
  char tempPath[260]; // [esp+4h] [ebp-11Ch] BYREF
  CScriptLib *v15; // [esp+108h] [ebp-18h]
  CUtlVector<fileList_t,CUtlMemory<fileList_t,int> > fileList; // [esp+10Ch] [ebp-14h] BYREF

  v15 = this;
  v2 = getenv(option: "temp");
  if ( v2 != nullptr || (v2 = getenv(option: "tmp")) != nullptr )
  {
    v3 = (char *)(tempPath - v2);
    do
    {
      v4 = *v2;
      v2[(_DWORD)v3] = *v2;
      ++v2;
    }
    while ( v4 != 0 );
    V_AppendSlash(pStr: tempPath, strSize: 260);
    v5 = strlen(pFileMask) + 1;
    v6 = &v13;
    do
      v7 = *++v6;
    while ( v7 != 0 );
    qmemcpy(v6, pFileMask, v5);
    FindFiles = v15->FindFiles;
    memset(&fileList, 0, sizeof(fileList));
    FindFiles(this: v15, a2: tempPath, a3: false, a4: &fileList);
    v9 = 0;
    if ( fileList.m_Size > 0 )
    {
      v10 = 0;
      do
      {
        v11 = CUtlString::Get(this: &fileList.m_Memory.m_pMemory[v10].fileName);
        _unlink(path: v11);
        ++v9;
        ++v10;
      }
      while ( v9 < fileList.m_Size );
    }
    CUtlVector<fileList_t,CUtlMemory<fileList_t,int>>::RemoveAll(this: &fileList);
    m_pMemory = fileList.m_Memory.m_pMemory;
    if ( fileList.m_Memory.m_nGrowSize >= 0 )
    {
      if ( fileList.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: fileList.m_Memory.m_pMemory);
        m_pMemory = nullptr;
        fileList.m_Memory.m_pMemory = nullptr;
      }
      fileList.m_Memory.m_nAllocationCount = 0;
    }
    fileList.m_pElements = m_pMemory;
    if ( fileList.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00404280
// Name: private: void CScriptLib::RecurseFileTree_r(char const __near *,int,class CUtlVector<class CUtlString,class CUtlMemory<class CUtlString,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CScriptLib::RecurseFileTree_r(
        CScriptLib *this,
        const char *pDirPath,
        int depth,
        CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *dirList)
{
  fileList_t *i; // ebx
  int v5; // eax
  int v6; // eax
  fileList_t *m_pMemory; // edi
  const char *v8; // eax
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CUtlString *v11; // ecx
  int v12; // eax
  int v13; // edi
  CUtlString *v14; // ecx
  CUtlVector<fileList_t,CUtlMemory<fileList_t,int> > fileList; // [esp+Ch] [ebp-18h] BYREF
  CScriptLib *v16; // [esp+20h] [ebp-4h]

  i = nullptr;
  v16 = this;
  memset(&fileList, 0, sizeof(fileList));
  v5 = CScriptLib::GetFileList(this, pDirPath, pPattern: "\\", &fileList);
  if ( v5 != 0 )
  {
    if ( v5 > 0 )
    {
      m_pMemory = fileList.m_Memory.m_pMemory;
      for ( i = (fileList_t *)v5; i != nullptr; i = (fileList_t *)((char *)i - 1) )
      {
        v8 = CUtlString::Get(this: &m_pMemory->fileName);
        CScriptLib::RecurseFileTree_r(this: v16, pDirPath: v8, depth: depth + 1, dirList);
        ++m_pMemory;
      }
    }
    m_Size = dirList->m_Size;
    m_nAllocationCount = dirList->m_Memory.m_nAllocationCount;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<CUtlString,int>::Grow(this: &dirList->m_Memory, num: m_Size - m_nAllocationCount + 1);
    ++dirList->m_Size;
    v11 = dirList->m_Memory.m_pMemory;
    v12 = dirList->m_Size - m_Size - 1;
    dirList->m_pElements = dirList->m_Memory.m_pMemory;
    if ( v12 > (int)i )
      _V_memmove(dest: &v11[m_Size + 1], src: &v11[m_Size], count: 16 * v12);
    v13 = m_Size;
    v14 = &dirList->m_Memory.m_pMemory[v13];
    if ( v14 != nullptr )
      CUtlString::CUtlString(this: v14);
    CUtlString::Set(this: &dirList->m_Memory.m_pMemory[v13], pValue: pDirPath);
    CUtlVector<fileList_t,CUtlMemory<fileList_t,int>>::RemoveAll(this: &fileList);
    if ( fileList.m_Memory.m_nGrowSize >= (int)i && fileList.m_Memory.m_pMemory != i )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: fileList.m_Memory.m_pMemory);
  }
  else
  {
    v6 = CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>::InsertBefore(this: dirList, elem: dirList->m_Size);
    CUtlString::Set(this: &dirList->m_Memory.m_pMemory[v6], pValue: pDirPath);
    CUtlVector<fileList_t,CUtlMemory<fileList_t,int>>::~CUtlVector<fileList_t,CUtlMemory<fileList_t,int>>(this: &fileList);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004043A0
// Name: public: virtual int CScriptLib::FindFiles(char __near *,bool,class CUtlVector<struct fileList_t,class CUtlMemory<struct fileList_t,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CScriptLib::FindFiles(
        CScriptLib *this,
        char *pFileMask,
        bool bRecurse,
        CUtlVector<fileList_t,CUtlMemory<fileList_t,int> > *fileList)
{
  CScriptLib *v4; // edi
  char *v5; // edi
  char v6; // al
  unsigned int v7; // eax
  char *v8; // edi
  char v9; // cl
  int m_nGrowSize; // esi
  fileList_t *m_pMemory; // eax
  const char *v13; // eax
  CUtlVector<fileList_t,CUtlMemory<fileList_t,int> > *v14; // esi
  int m_Size; // edi
  int inserted; // eax
  fileList_t *v17; // edi
  int v18; // ebx
  CUtlString *p_fileName; // esi
  int timeWrite_high; // eax
  bool v21; // zf
  CUtlString *v22; // eax
  unsigned int v23; // [esp-8h] [ebp-34Ch]
  char extension[260]; // [esp+8h] [ebp-33Ch] BYREF
  char dirPath[260]; // [esp+10Ch] [ebp-238h] BYREF
  char pattern[260]; // [esp+210h] [ebp-134h] BYREF
  CScriptLib *v27; // [esp+314h] [ebp-30h]
  int i; // [esp+318h] [ebp-2Ch]
  CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > dirList; // [esp+31Ch] [ebp-28h] BYREF
  CUtlVector<fileList_t,CUtlMemory<fileList_t,int> > tempList; // [esp+330h] [ebp-14h] BYREF
  char *pFileMaska; // [esp+34Ch] [ebp+8h]
  int bRecursea; // [esp+350h] [ebp+Ch]

  v4 = this;
  v27 = this;
  strcpy(dirPath, pFileMask);
  V_StripFilename(path: dirPath);
  V_FileBase(in: pFileMask, out: pattern, maxlen: 260);
  V_ExtractFileExtension(path: pFileMask, dest: extension, destSize: 260);
  if ( extension[0] != 0 )
  {
    v5 = &dirPath[259];
    do
      v6 = *++v5;
    while ( v6 != 0 );
    strcpy(v5, ".");
    v7 = strlen(extension) + 1;
    v8 = &dirPath[259];
    do
      v9 = *++v8;
    while ( v9 != 0 );
    qmemcpy(v8, extension, v7);
    v4 = v27;
  }
  if ( bRecurse )
  {
    memset(&tempList, 0, sizeof(tempList));
    memset(&dirList, 0, sizeof(dirList));
    CScriptLib::RecurseFileTree_r(this: v4, pDirPath: dirPath, depth: 0, &dirList);
    i = 0;
    if ( dirList.m_Size > 0 )
    {
      bRecursea = 0;
      while ( 1 )
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
          v23 = 24 * dirList.m_Size;
          if ( m_pMemory != nullptr )
            m_pMemory = (fileList_t *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v23);
          else
            m_pMemory = (fileList_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v23);
          tempList.m_Memory.m_pMemory = m_pMemory;
        }
        tempList.m_pElements = m_pMemory;
        v13 = CUtlString::Get(this: &dirList.m_Memory.m_pMemory[bRecursea]);
        CScriptLib::GetFileList(this: v4, pDirPath: v13, pPattern: pattern, fileList: &tempList);
        v14 = fileList;
        m_Size = tempList.m_Size;
        inserted = CUtlVector<fileList_t,CUtlMemory<fileList_t,int>>::InsertMultipleBefore(
                     this: fileList,
                     elem: fileList->m_Size,
                     num: tempList.m_Size);
        if ( m_Size > 0 )
        {
          v17 = tempList.m_Memory.m_pMemory;
          v18 = inserted;
          pFileMaska = (char *)tempList.m_Size;
          while ( 1 )
          {
            p_fileName = &v14->m_Memory.m_pMemory[v18].fileName;
            CUtlString::operator=(this: p_fileName, src: &v17->fileName);
            p_fileName[1].m_Storage.m_Memory.m_pMemory = (unsigned __int8 *)v17->timeWrite;
            timeWrite_high = HIDWORD(v17->timeWrite);
            ++v17;
            ++v18;
            v21 = pFileMaska-- == (char *)1;
            p_fileName[1].m_Storage.m_Memory.m_nAllocationCount = timeWrite_high;
            if ( v21 )
              break;
            v14 = fileList;
          }
        }
        ++bRecursea;
        if ( ++i >= dirList.m_Size )
          break;
        v4 = v27;
      }
    }
    CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>::RemoveAll(this: &dirList);
    v22 = dirList.m_Memory.m_pMemory;
    if ( dirList.m_Memory.m_nGrowSize >= 0 )
    {
      if ( dirList.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: dirList.m_Memory.m_pMemory);
        v22 = nullptr;
        dirList.m_Memory.m_pMemory = nullptr;
      }
      dirList.m_Memory.m_nAllocationCount = 0;
    }
    dirList.m_pElements = v22;
    if ( dirList.m_Memory.m_nGrowSize >= 0 )
    {
      if ( v22 != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v22);
        dirList.m_Memory.m_pMemory = nullptr;
      }
      dirList.m_Memory.m_nAllocationCount = 0;
    }
    CUtlVector<fileList_t,CUtlMemory<fileList_t,int>>::RemoveAll(this: &tempList);
    if ( tempList.m_Memory.m_nGrowSize < 0 )
    {
      return fileList->m_Size;
    }
    else
    {
      if ( tempList.m_Memory.m_pMemory != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: tempList.m_Memory.m_pMemory);
      return fileList->m_Size;
    }
  }
  else
  {
    CScriptLib::GetFileList(this: v4, pDirPath: dirPath, pPattern: pattern, fileList);
    return fileList->m_Size;
  }
}

} // namespace unusedcontent

// ============================================================
// Overlay from vbsp (Missing functions)
// ============================================================
namespace vbsp {

//------------------------------------------------------------------------------
// Address: 0x0044C390
// Name: void DefaultScriptLoadedCallback(char const __near *,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DefaultScriptLoadedCallback()
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x0044C3A0
// Name: public: virtual bool CScriptLib::DoesFileExist(char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CScriptLib::DoesFileExist(CScriptLib *this, const char *pFilename)
{
  return g_pFullFileSystem->FileExists(this: &g_pFullFileSystem->IBaseFileSystem, a2: pFilename, a3: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x0044C3C0
// Name: public: virtual bool CScriptLib::ReadFileToBuffer(char const __near *,class CUtlBuffer __near &,bool,bool)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CScriptLib::ReadFileToBuffer(
        CScriptLib *this,
        const char *pSourceName,
        CUtlBuffer *buffer,
        bool bText,
        bool bNoOpenFailureWarning)
{
  int *v5; // eax
  const char *v6; // eax

  if ( g_pFullFileSystem->ReadFile(
         this: &g_pFullFileSystem->IBaseFileSystem,
         a2: pSourceName,
         a3: nullptr,
         a4: buffer,
         a5: 0,
         a6: 0,
         a7: nullptr) )
  {
    if ( bText )
      CUtlBuffer::SetBufferType(this: buffer, bIsText: true, bContainsCRLF: true);
    else
      CUtlBuffer::SetBufferType(this: buffer, bIsText: false, bContainsCRLF: false);
    return 1;
  }
  else
  {
    if ( !bNoOpenFailureWarning )
    {
      v5 = _errno();
      v6 = strerror(errnum: *v5);
      _Msg(a1: "ReadFileToBuffer(): Error opening %s: %s\n", pSourceName, v6);
    }
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0044C440
// Name: public: virtual bool CScriptLib::WriteBufferToFile(char const __near *,class CUtlBuffer __near &,enum DiskWriteMode_t)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CScriptLib::WriteBufferToFile(
        CScriptLib *this,
        const char *pTargetName,
        CUtlBuffer *buffer,
        DiskWriteMode_t writeMode)
{
  _BYTE *v5; // eax
  _BYTE *v6; // esi
  _BYTE *v7; // eax
  char dirPath[260]; // [esp+8h] [ebp-104h] BYREF

  strcpy(dirPath, pTargetName);
  strchr(string: (unsigned __int8 *)dirPath, chr: 0x5Cu);
  v6 = v5;
  if ( v5 != nullptr )
  {
    while ( 1 )
    {
      strchr(string: v6 + 1, chr: 0x5Cu);
      v6 = v7;
      if ( v7 == nullptr )
        break;
      *v7 = 0;
      _mkdir(path: dirPath);
      *v6 = 92;
    }
  }
  return writeMode != WRITE_TO_DISK_ALWAYS
      && (writeMode != WRITE_TO_DISK_UPDATE || !this->DoesFileExist(this, a2: pTargetName))
      || g_pFullFileSystem->WriteFile(
           this: &g_pFullFileSystem->IBaseFileSystem,
           a2: pTargetName,
           a3: nullptr,
           a4: buffer);
}

//------------------------------------------------------------------------------
// Address: 0x0044C500
// Name: public: virtual int CScriptLib::CompareFileTime(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CScriptLib::CompareFileTime(CScriptLib *this, const char *pFilenameA, const char *pFilenameB)
{
  unsigned int v3; // esi
  unsigned int v4; // eax
  bool v5; // cf

  v3 = g_pFullFileSystem->GetFileTime(this: &g_pFullFileSystem->IBaseFileSystem, a2: pFilenameA, a3: nullptr);
  v4 = g_pFullFileSystem->GetFileTime(this: &g_pFullFileSystem->IBaseFileSystem, a2: pFilenameB, a3: nullptr);
  if ( v3 == -1 )
    v3 = 0;
  if ( v4 == -1 )
    return v3 != 0;
  v5 = v4 < v3;
  if ( v4 <= v3 )
    return v5;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0044C560
// Name: public: virtual char __near * CScriptLib::MakeTemporaryFilename(char const __near *,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CScriptLib::MakeTemporaryFilename(CScriptLib *this, const char *pchModPath, char *pPath, int pathSize)
{
  char *v4; // eax
  char *v5; // esi

  v4 = _tempnam(dir: pchModPath, pfx: "mgd_");
  v5 = v4;
  if ( *v4 == 92 )
    v5 = v4 + 1;
  if ( v5[strlen(v5) - 1] == 46 )
    v5[strlen(v5) - 1] = 0;
  V_snprintf(pDest: pPath, maxLen: pathSize, pFormat: "%s.tmp", v5);
  free(pMem: v5);
  return pPath;
}

//------------------------------------------------------------------------------
// Address: 0x0044C7C0
// Name: private: int CScriptLib::GetFileList(char const __near *,char const __near *,class CUtlVector<struct fileList_t,class CUtlMemory<struct fileList_t,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CScriptLib::GetFileList(
        CScriptLib *this,
        const char *pDirPath,
        const char *pPattern,
        CUtlVector<fileList_t,CUtlMemory<fileList_t,int> > *fileList)
{
  unsigned int v5; // kr00_4
  int v6; // eax
  char v7; // cl
  char *v8; // edi
  char v9; // al
  unsigned int v10; // eax
  char *v11; // edi
  char v12; // cl
  int v13; // esi
  int v15; // eax
  char v16; // cl
  unsigned int v17; // eax
  char *v18; // edi
  char v19; // cl
  char *v20; // edi
  char *v21; // esi
  char v22; // cl
  int m_Size; // eax
  int v24; // esi
  char v25; // [esp+Bh] [ebp-435h] BYREF
  char fileName[260]; // [esp+Ch] [ebp-434h] BYREF
  char fullPath[260]; // [esp+110h] [ebp-330h] BYREF
  _finddata64i32_t findData; // [esp+214h] [ebp-22Ch] BYREF
  char sourcePath[260]; // [esp+33Ch] [ebp-104h] BYREF
  int h; // [esp+448h] [ebp+8h]
  char bFindDirs_3; // [esp+453h] [ebp+13h]

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
  v5 = strlen(sourcePath);
  if ( v5 != 0 )
  {
    if ( findData.name[v5 + 259] != 92 )
    {
      sourcePath[v5] = 92;
      sourcePath[v5 + 1] = 0;
    }
  }
  else
  {
    strcpy(sourcePath, ".\\");
  }
  v6 = 0;
  do
  {
    v7 = sourcePath[v6];
    fullPath[v6++] = v7;
  }
  while ( v7 != 0 );
  if ( *pPattern != 92 || pPattern[1] != 0 )
  {
    bFindDirs_3 = 0;
    v10 = strlen(pPattern) + 1;
    v11 = &fileName[259];
    do
      v12 = *++v11;
    while ( v12 != 0 );
    qmemcpy(v11, pPattern, v10);
  }
  else
  {
    bFindDirs_3 = 1;
    v8 = &fileName[259];
    do
      v9 = *++v8;
    while ( v9 != 0 );
    strcpy(v8, "*");
  }
  v13 = _findfirst64i32(szWild: fullPath, pfd: &findData);
  h = v13;
  if ( v13 == -1 )
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
      v15 = 0;
      do
      {
        v16 = sourcePath[v15];
        fileName[v15++] = v16;
      }
      while ( v16 != 0 );
      v17 = strlen(findData.name) + 1;
      v18 = &v25;
      do
        v19 = *++v18;
      while ( v19 != 0 );
      qmemcpy(v18, findData.name, 4 * (v17 >> 2));
      v21 = &findData.name[4 * (v17 >> 2)];
      v20 = &v18[4 * (v17 >> 2)];
      v22 = v17;
      m_Size = fileList->m_Size;
      qmemcpy(v20, v21, v22 & 3);
      v24 = CUtlVector<fileList_t,CUtlMemory<fileList_t,int>>::InsertBefore(this: fileList, elem: m_Size);
      CUtlString::Set(this: &fileList->m_Memory.m_pMemory[v24].fileName, pValue: fileName);
      fileList->m_Memory.m_pMemory[v24].timeWrite = findData.time_write;
      v13 = h;
    }
  }
  while ( _findnext64i32(hFile: v13, pfd: &findData) == 0 );
  _findclose(hFile: v13);
  return fileList->m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x0044CA80
// Name: public: virtual void CScriptLib::DeleteTemporaryFiles(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CScriptLib::DeleteTemporaryFiles(CScriptLib *this, const char *pFileMask)
{
  char *v2; // eax
  char *v3; // edx
  char v4; // cl
  unsigned int v5; // eax
  char *v6; // edi
  char v7; // cl
  int (__thiscall *FindFiles)(struct CScriptLib *, char *, bool, CUtlVector<fileList_t,CUtlMemory<fileList_t,int> > *); // edx
  int v9; // esi
  int v10; // edi
  const char *v11; // eax
  fileList_t *m_pMemory; // eax
  char v13; // [esp+3h] [ebp-11Dh] BYREF
  char tempPath[260]; // [esp+4h] [ebp-11Ch] BYREF
  CScriptLib *v15; // [esp+108h] [ebp-18h]
  CUtlVector<fileList_t,CUtlMemory<fileList_t,int> > fileList; // [esp+10Ch] [ebp-14h] BYREF

  v15 = this;
  v2 = getenv(option: "temp");
  if ( v2 != nullptr || (v2 = getenv(option: "tmp")) != nullptr )
  {
    v3 = (char *)(tempPath - v2);
    do
    {
      v4 = *v2;
      v2[(_DWORD)v3] = *v2;
      ++v2;
    }
    while ( v4 != 0 );
    V_AppendSlash(pStr: tempPath, strSize: 260);
    v5 = strlen(pFileMask) + 1;
    v6 = &v13;
    do
      v7 = *++v6;
    while ( v7 != 0 );
    qmemcpy(v6, pFileMask, v5);
    FindFiles = v15->FindFiles;
    memset(&fileList, 0, sizeof(fileList));
    FindFiles(this: v15, a2: tempPath, a3: false, a4: &fileList);
    v9 = 0;
    if ( fileList.m_Size > 0 )
    {
      v10 = 0;
      do
      {
        v11 = CUtlString::Get(this: &fileList.m_Memory.m_pMemory[v10].fileName);
        _unlink(path: v11);
        ++v9;
        ++v10;
      }
      while ( v9 < fileList.m_Size );
    }
    CUtlVector<fileList_t,CUtlMemory<fileList_t,int>>::RemoveAll(this: &fileList);
    m_pMemory = fileList.m_Memory.m_pMemory;
    if ( fileList.m_Memory.m_nGrowSize >= 0 )
    {
      if ( fileList.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: fileList.m_Memory.m_pMemory);
        m_pMemory = nullptr;
        fileList.m_Memory.m_pMemory = nullptr;
      }
      fileList.m_Memory.m_nAllocationCount = 0;
    }
    fileList.m_pElements = m_pMemory;
    if ( fileList.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0044CBB0
// Name: private: void CScriptLib::RecurseFileTree_r(char const __near *,int,class CUtlVector<class CUtlString,class CUtlMemory<class CUtlString,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CScriptLib::RecurseFileTree_r(
        CScriptLib *this,
        const char *pDirPath,
        int depth,
        CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *dirList)
{
  fileList_t *i; // ebx
  int v5; // eax
  int v6; // eax
  fileList_t *m_pMemory; // edi
  const char *v8; // eax
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CUtlString *v11; // ecx
  int v12; // eax
  int v13; // edi
  CUtlString *v14; // ecx
  CUtlVector<fileList_t,CUtlMemory<fileList_t,int> > fileList; // [esp+Ch] [ebp-18h] BYREF
  CScriptLib *v16; // [esp+20h] [ebp-4h]

  i = nullptr;
  v16 = this;
  memset(&fileList, 0, sizeof(fileList));
  v5 = CScriptLib::GetFileList(this, pDirPath, pPattern: "\\", &fileList);
  if ( v5 != 0 )
  {
    if ( v5 > 0 )
    {
      m_pMemory = fileList.m_Memory.m_pMemory;
      for ( i = (fileList_t *)v5; i != nullptr; i = (fileList_t *)((char *)i - 1) )
      {
        v8 = CUtlString::Get(this: &m_pMemory->fileName);
        CScriptLib::RecurseFileTree_r(this: v16, pDirPath: v8, depth: depth + 1, dirList);
        ++m_pMemory;
      }
    }
    m_Size = dirList->m_Size;
    m_nAllocationCount = dirList->m_Memory.m_nAllocationCount;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<listplane_t,int>::Grow(
        this: (CUtlMemory<listplane_t,int> *)dirList,
        num: m_Size - m_nAllocationCount + 1);
    ++dirList->m_Size;
    v11 = dirList->m_Memory.m_pMemory;
    v12 = dirList->m_Size - m_Size - 1;
    dirList->m_pElements = dirList->m_Memory.m_pMemory;
    if ( v12 > (int)i )
      _V_memmove(dest: &v11[m_Size + 1], src: &v11[m_Size], count: 16 * v12);
    v13 = m_Size;
    v14 = &dirList->m_Memory.m_pMemory[v13];
    if ( v14 != nullptr )
      CUtlString::CUtlString(this: v14);
    CUtlString::Set(this: &dirList->m_Memory.m_pMemory[v13], pValue: pDirPath);
    CUtlVector<fileList_t,CUtlMemory<fileList_t,int>>::RemoveAll(this: &fileList);
    if ( fileList.m_Memory.m_nGrowSize >= (int)i && fileList.m_Memory.m_pMemory != i )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: fileList.m_Memory.m_pMemory);
  }
  else
  {
    v6 = CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>::InsertBefore(this: dirList, elem: dirList->m_Size);
    CUtlString::Set(this: &dirList->m_Memory.m_pMemory[v6], pValue: pDirPath);
    CUtlVector<fileList_t,CUtlMemory<fileList_t,int>>::~CUtlVector<fileList_t,CUtlMemory<fileList_t,int>>(this: &fileList);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0044CCD0
// Name: public: virtual int CScriptLib::FindFiles(char __near *,bool,class CUtlVector<struct fileList_t,class CUtlMemory<struct fileList_t,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CScriptLib::FindFiles(
        CScriptLib *this,
        char *pFileMask,
        bool bRecurse,
        CUtlVector<fileList_t,CUtlMemory<fileList_t,int> > *fileList)
{
  CScriptLib *v4; // edi
  char *v5; // edi
  char v6; // al
  unsigned int v7; // eax
  char *v8; // edi
  char v9; // cl
  int m_nGrowSize; // esi
  fileList_t *m_pMemory; // eax
  const char *v13; // eax
  CUtlVector<fileList_t,CUtlMemory<fileList_t,int> > *v14; // esi
  int m_Size; // edi
  int inserted; // eax
  fileList_t *v17; // edi
  int v18; // ebx
  CUtlString *p_fileName; // esi
  int timeWrite_high; // eax
  bool v21; // zf
  CUtlString *v22; // eax
  unsigned int v23; // [esp-8h] [ebp-34Ch]
  char extension[260]; // [esp+8h] [ebp-33Ch] BYREF
  char dirPath[260]; // [esp+10Ch] [ebp-238h] BYREF
  char pattern[260]; // [esp+210h] [ebp-134h] BYREF
  CScriptLib *v27; // [esp+314h] [ebp-30h]
  int i; // [esp+318h] [ebp-2Ch]
  CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > dirList; // [esp+31Ch] [ebp-28h] BYREF
  CUtlVector<fileList_t,CUtlMemory<fileList_t,int> > tempList; // [esp+330h] [ebp-14h] BYREF
  char *pFileMaska; // [esp+34Ch] [ebp+8h]
  int bRecursea; // [esp+350h] [ebp+Ch]

  v4 = this;
  v27 = this;
  strcpy(dirPath, pFileMask);
  V_StripFilename(path: dirPath);
  V_FileBase(in: pFileMask, out: pattern, maxlen: 260);
  V_ExtractFileExtension(path: pFileMask, dest: extension, destSize: 260);
  if ( extension[0] != 0 )
  {
    v5 = &dirPath[259];
    do
      v6 = *++v5;
    while ( v6 != 0 );
    strcpy(v5, ".");
    v7 = strlen(extension) + 1;
    v8 = &dirPath[259];
    do
      v9 = *++v8;
    while ( v9 != 0 );
    qmemcpy(v8, extension, v7);
    v4 = v27;
  }
  if ( bRecurse )
  {
    memset(&tempList, 0, sizeof(tempList));
    memset(&dirList, 0, sizeof(dirList));
    CScriptLib::RecurseFileTree_r(this: v4, pDirPath: dirPath, depth: 0, &dirList);
    i = 0;
    if ( dirList.m_Size > 0 )
    {
      bRecursea = 0;
      while ( 1 )
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
          v23 = 24 * dirList.m_Size;
          if ( m_pMemory != nullptr )
            m_pMemory = (fileList_t *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v23);
          else
            m_pMemory = (fileList_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v23);
          tempList.m_Memory.m_pMemory = m_pMemory;
        }
        tempList.m_pElements = m_pMemory;
        v13 = CUtlString::Get(this: &dirList.m_Memory.m_pMemory[bRecursea]);
        CScriptLib::GetFileList(this: v4, pDirPath: v13, pPattern: pattern, fileList: &tempList);
        v14 = fileList;
        m_Size = tempList.m_Size;
        inserted = CUtlVector<fileList_t,CUtlMemory<fileList_t,int>>::InsertMultipleBefore(
                     this: fileList,
                     elem: fileList->m_Size,
                     num: tempList.m_Size);
        if ( m_Size > 0 )
        {
          v17 = tempList.m_Memory.m_pMemory;
          v18 = inserted;
          pFileMaska = (char *)tempList.m_Size;
          while ( 1 )
          {
            p_fileName = &v14->m_Memory.m_pMemory[v18].fileName;
            CUtlString::operator=(this: p_fileName, src: &v17->fileName);
            p_fileName[1].m_Storage.m_Memory.m_pMemory = (unsigned __int8 *)v17->timeWrite;
            timeWrite_high = HIDWORD(v17->timeWrite);
            ++v17;
            ++v18;
            v21 = pFileMaska-- == (char *)1;
            p_fileName[1].m_Storage.m_Memory.m_nAllocationCount = timeWrite_high;
            if ( v21 )
              break;
            v14 = fileList;
          }
        }
        ++bRecursea;
        if ( ++i >= dirList.m_Size )
          break;
        v4 = v27;
      }
    }
    CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>::RemoveAll(this: &dirList);
    v22 = dirList.m_Memory.m_pMemory;
    if ( dirList.m_Memory.m_nGrowSize >= 0 )
    {
      if ( dirList.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: dirList.m_Memory.m_pMemory);
        v22 = nullptr;
        dirList.m_Memory.m_pMemory = nullptr;
      }
      dirList.m_Memory.m_nAllocationCount = 0;
    }
    dirList.m_pElements = v22;
    if ( dirList.m_Memory.m_nGrowSize >= 0 )
    {
      if ( v22 != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v22);
        dirList.m_Memory.m_pMemory = nullptr;
      }
      dirList.m_Memory.m_nAllocationCount = 0;
    }
    CUtlVector<fileList_t,CUtlMemory<fileList_t,int>>::RemoveAll(this: &tempList);
    if ( tempList.m_Memory.m_nGrowSize < 0 )
    {
      return fileList->m_Size;
    }
    else
    {
      if ( tempList.m_Memory.m_pMemory != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: tempList.m_Memory.m_pMemory);
      return fileList->m_Size;
    }
  }
  else
  {
    CScriptLib::GetFileList(this: v4, pDirPath: dirPath, pPattern: pattern, fileList);
    return fileList->m_Size;
  }
}

} // namespace vbsp

// ============================================================
// Overlay from vbspinfo (Missing functions)
// ============================================================
namespace vbspinfo {

//------------------------------------------------------------------------------
// Address: 0x00404580
// Name: public: int CUtlVector<struct texinfo_s,class CUtlMemory<struct texinfo_s,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<texinfo_s,CUtlMemory<texinfo_s,int>>::InsertMultipleBefore(
        CUtlVector<texinfo_s,CUtlMemory<texinfo_s,int> > *this,
        int elem,
        int num)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  texinfo_s *m_pMemory; // ecx
  int v8; // eax
  int v9; // eax

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<texinfo_s,int>::Grow(this: &this->m_Memory, num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v8 = this->m_Size;
  this->m_pElements = this->m_Memory.m_pMemory;
  v9 = v8 - elem - num;
  if ( v9 > 0 && num > 0 )
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 72 * v9);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x00404AF0
// Name: public: int CUtlVector<struct doccluderdata_t,class CUtlMemory<struct doccluderdata_t,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<doccluderdata_t,CUtlMemory<doccluderdata_t,int>>::InsertMultipleBefore(
        CUtlVector<doccluderdata_t,CUtlMemory<doccluderdata_t,int> > *this,
        int elem,
        int num)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  doccluderdata_t *m_pMemory; // ecx
  int v8; // eax
  int v9; // eax

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<doccluderdata_t,int>::Grow(this: &this->m_Memory, num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v8 = this->m_Size;
  this->m_pElements = this->m_Memory.m_pMemory;
  v9 = v8 - elem - num;
  if ( v9 > 0 && num > 0 )
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 40 * v9);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x00404B70
// Name: public: int CUtlVector<struct doccluderpolydata_t,class CUtlMemory<struct doccluderpolydata_t,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<doccluderpolydata_t,CUtlMemory<doccluderpolydata_t,int>>::InsertMultipleBefore(
        CUtlVector<doccluderpolydata_t,CUtlMemory<doccluderpolydata_t,int> > *this,
        int elem,
        int num)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  doccluderpolydata_t *m_pMemory; // ecx
  int v8; // eax
  int v9; // eax

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<doccluderpolydata_t,int>::Grow(this: &this->m_Memory, num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v8 = this->m_Size;
  this->m_pElements = this->m_Memory.m_pMemory;
  v9 = v8 - elem - num;
  if ( v9 > 0 && num > 0 )
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 12 * v9);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x00404D70
// Name: public: int CUtlVector<struct dleafambientlighting_t,class CUtlMemory<struct dleafambientlighting_t,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<dleafambientlighting_t,CUtlMemory<dleafambientlighting_t,int>>::InsertMultipleBefore(
        CUtlVector<dleafambientlighting_t,CUtlMemory<dleafambientlighting_t,int> > *this,
        int elem,
        int num)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  dleafambientlighting_t *m_pMemory; // ecx
  int v8; // eax
  int v9; // eax

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<dleafambientlighting_t,int>::Grow(this: &this->m_Memory, num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v8 = this->m_Size;
  this->m_pElements = this->m_Memory.m_pMemory;
  v9 = v8 - elem - num;
  if ( v9 > 0 && num > 0 )
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 28 * v9);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x00404E00
// Name: public: int CUtlVector<class ddispinfo_t,class CUtlMemory<class ddispinfo_t,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<ddispinfo_t,CUtlMemory<ddispinfo_t,int>>::InsertMultipleBefore(
        CUtlVector<ddispinfo_t,CUtlMemory<ddispinfo_t,int> > *this,
        int elem,
        int num)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  ddispinfo_t *m_pMemory; // ecx
  int v8; // eax
  int v9; // eax

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<ddispinfo_t,int>::Grow(this: &this->m_Memory, num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v8 = this->m_Size;
  this->m_pElements = this->m_Memory.m_pMemory;
  v9 = v8 - elem - num;
  if ( v9 > 0 && num > 0 )
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 176 * v9);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x00404E80
// Name: public: int CUtlVector<class CDispVert,class CUtlMemory<class CDispVert,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CDispVert,CUtlMemory<CDispVert,int>>::InsertMultipleBefore(
        CUtlVector<CDispVert,CUtlMemory<CDispVert,int> > *this,
        int elem,
        int num)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CDispVert *m_pMemory; // ecx
  int v8; // eax
  int v9; // eax

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<CDispVert,int>::Grow(this: &this->m_Memory, num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v8 = this->m_Size;
  this->m_pElements = this->m_Memory.m_pMemory;
  v9 = v8 - elem - num;
  if ( v9 > 0 && num > 0 )
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 20 * v9);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x00404F00
// Name: public: int CUtlVector<unsigned short,class CUtlMemory<unsigned short,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<unsigned short,CUtlMemory<unsigned short,int>>::InsertMultipleBefore(
        CUtlVector<CFaceMacroTextureInfo,CUtlMemory<CFaceMacroTextureInfo,int> > *this,
        int elem,
        int num)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CFaceMacroTextureInfo *m_pMemory; // ecx
  int v8; // eax
  int v9; // eax

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<CFaceMacroTextureInfo,int>::Grow(this: &this->m_Memory, num: num + m_Size - m_nAllocationCount);
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
// Address: 0x00404F70
// Name: public: int CUtlVector<class CDispMultiBlend,class CUtlMemory<class CDispMultiBlend,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CDispMultiBlend,CUtlMemory<CDispMultiBlend,int>>::InsertMultipleBefore(
        CUtlVector<CDispMultiBlend,CUtlMemory<CDispMultiBlend,int> > *this,
        int elem,
        int num)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CDispMultiBlend *m_pMemory; // ecx
  int v8; // eax
  int v9; // eax

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<CDispMultiBlend,int>::Grow(this: &this->m_Memory, num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v8 = this->m_Size;
  this->m_pElements = this->m_Memory.m_pMemory;
  v9 = v8 - elem - num;
  if ( v9 > 0 && num > 0 )
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 80 * v9);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x00404FF0
// Name: public: int CUtlVector<struct dfacebrushlist_t,class CUtlMemory<struct dfacebrushlist_t,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<dfacebrushlist_t,CUtlMemory<dfacebrushlist_t,int>>::InsertMultipleBefore(
        CUtlVector<dfacebrushlist_t,CUtlMemory<dfacebrushlist_t,int> > *this,
        int elem,
        int num)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  dfacebrushlist_t *m_pMemory; // ecx
  int v8; // eax
  int v9; // eax

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<int,int>::Grow(
      (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)this,
      num: num + m_Size - m_nAllocationCount);
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
// Address: 0x00405DC0
// Name: public: CUtlVector<struct dleafambientlighting_t,class CUtlMemory<struct dleafambientlighting_t,int>>::~CUtlVector<struct dleafambientlighting_t,class CUtlMemory<struct dleafambientlighting_t,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<dleafambientlighting_t,CUtlMemory<dleafambientlighting_t,int>>::~CUtlVector<dleafambientlighting_t,CUtlMemory<dleafambientlighting_t,int>>(
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
// Address: 0x00408610
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
// Address: 0x00408A30
// Name: public: void CUtlVector<struct clusterlist_t,class CUtlMemory<struct clusterlist_t,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<clusterlist_t,CUtlMemory<clusterlist_t,int>>::RemoveAll(
        CUtlVector<clusterlist_t,CUtlMemory<clusterlist_t,int> > *this)
{
  int v1; // ebx
  int v2; // eax
  char *v3; // esi
  void *v4; // eax
  int v5; // [esp+4h] [ebp-8h]
  CUtlVector<clusterlist_t,CUtlMemory<clusterlist_t,int> > *v6; // [esp+8h] [ebp-4h]

  v1 = this->m_Size - 1;
  v6 = this;
  if ( v1 < 0 )
  {
    this->m_Size = 0;
  }
  else
  {
    v2 = 24 * v1;
    v5 = 24 * v1;
    do
    {
      v3 = (char *)this->m_Memory.m_pMemory + v2;
      *((_DWORD *)v3 + 4) = 0;
      if ( *((int *)v3 + 3) >= 0 )
      {
        if ( *((_DWORD *)v3 + 1) != 0 )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *((void **)v3 + 1));
          this = v6;
          *((_DWORD *)v3 + 1) = 0;
        }
        *((_DWORD *)v3 + 2) = 0;
      }
      v4 = *((void **)v3 + 1);
      *((_DWORD *)v3 + 5) = v4;
      if ( *((int *)v3 + 3) >= 0 )
      {
        if ( v4 != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v4);
          this = v6;
          *((_DWORD *)v3 + 1) = 0;
        }
        *((_DWORD *)v3 + 2) = 0;
      }
      --v1;
      v2 = v5 - 24;
      v5 -= 24;
    }
    while ( v1 >= 0 );
    this->m_Size = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00409EE0
// Name: public: CUtlVector<struct clusterlist_t,class CUtlMemory<struct clusterlist_t,int>>::~CUtlVector<struct clusterlist_t,class CUtlMemory<struct clusterlist_t,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<clusterlist_t,CUtlMemory<clusterlist_t,int>>::~CUtlVector<clusterlist_t,CUtlMemory<clusterlist_t,int>>(
        CUtlVector<clusterlist_t,CUtlMemory<clusterlist_t,int> > *this)
{
  bool v2; // sf
  clusterlist_t *m_pMemory; // eax

  CUtlVector<clusterlist_t,CUtlMemory<clusterlist_t,int>>::RemoveAll(this);
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
// Address: 0x00409F40
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
// Address: 0x0040B410
// Name: public: int CUtlVector<class CSPVert,class CUtlMemory<class CSPVert,int>>::AddVectorToTail(class CUtlVector<class CSPVert,class CUtlMemory<class CSPVert,int>> const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CSPVert,CUtlMemory<CSPVert,int>>::AddVectorToTail(
        CUtlVector<CSPVert,CUtlMemory<CSPVert,int> > *this,
        const CUtlVector<CSPVert,CUtlMemory<CSPVert,int> > *src)
{
  int m_Size; // ebx
  int v4; // edi
  CSPVert *m_pMemory; // edx
  int v6; // ebx
  int v7; // edx
  CSPVert *v8; // eax
  CSPVert *v9; // ecx
  int base; // [esp+Ch] [ebp-4h]

  m_Size = this->m_Size;
  v4 = src->m_Size;
  base = m_Size;
  CUtlMemory<CSPVert,int>::EnsureCapacity(this: &this->m_Memory, num: v4 + m_Size);
  m_pMemory = this->m_Memory.m_pMemory;
  this->m_Size += v4;
  this->m_pElements = m_pMemory;
  if ( v4 <= 0 )
    return m_Size;
  v6 = 0;
  v7 = base;
  do
  {
    v8 = &src->m_Memory.m_pMemory[v6];
    v9 = &this->m_Memory.m_pMemory[v7];
    if ( v9 != nullptr )
    {
      *(_QWORD *)&v9->m_vPos.x = *(_QWORD *)&v8->m_vPos.x;
      *(_QWORD *)&v9->m_vPos.z = *(_QWORD *)&v8->m_vPos.z;
      *(_QWORD *)&v9->m_vColor.m_vColor.y = *(_QWORD *)&v8->m_vColor.m_vColor.y;
      v9->m_vColor.m_flAlpha = v8->m_vColor.m_flAlpha;
    }
    ++v6;
    ++v7;
    --v4;
  }
  while ( v4 != 0 );
  return base;
}

//------------------------------------------------------------------------------
// Address: 0x0040B4A0
// Name: public: int CUtlVector<class CSPVert,class CUtlMemory<class CSPVert,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CSPVert,CUtlMemory<CSPVert,int>>::InsertMultipleBefore(
        CUtlVector<CSPVert,CUtlMemory<CSPVert,int> > *this,
        int elem,
        int num)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CSPVert *m_pMemory; // ecx
  int v9; // eax
  int v10; // edx
  int v11; // eax
  unsigned int v12; // edx
  CSPVert *v13; // ecx
  int v14; // eax
  int v15; // edi
  CSPVert *v16; // ecx
  int i; // [esp+10h] [ebp+8h]

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<dleafambientlighting_t,int>::Grow(
      (CUtlMemory<dleafambientlighting_t,int> *)this,
      num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v9 = this->m_Size - elem - num;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v9 > 0 && num > 0 )
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 28 * v9);
  v10 = 0;
  if ( num >= 4 )
  {
    v11 = elem;
    v12 = ((unsigned int)(num - 4) >> 2) + 1;
    i = 4 * v12;
    do
    {
      v13 = &this->m_Memory.m_pMemory[v11];
      if ( v13 != nullptr )
        v13->m_vColor.m_flAlpha = 1.0;
      if ( &this->m_Memory.m_pMemory[v11] != (CSPVert *)-28 )
        this->m_Memory.m_pMemory[v11 + 1].m_vColor.m_flAlpha = 1.0;
      if ( &this->m_Memory.m_pMemory[v11] != (CSPVert *)-56 )
        this->m_Memory.m_pMemory[v11 + 2].m_vColor.m_flAlpha = 1.0;
      if ( &this->m_Memory.m_pMemory[v11] != (CSPVert *)-84 )
        this->m_Memory.m_pMemory[v11 + 3].m_vColor.m_flAlpha = 1.0;
      v11 += 4;
      --v12;
    }
    while ( v12 != 0 );
    v10 = i;
  }
  if ( v10 < num )
  {
    v14 = v10 + elem;
    v15 = num - v10;
    do
    {
      v16 = &this->m_Memory.m_pMemory[v14];
      if ( v16 != nullptr )
        v16->m_vColor.m_flAlpha = 1.0;
      ++v14;
      --v15;
    }
    while ( v15 != 0 );
  }
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x0040C6F0
// Name: public: void CUtlVector<char,class CUtlMemory<char,int>>::CopyArray(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<char,CUtlMemory<char,int>>::CopyArray(
        CUtlVector<char,CUtlMemory<char,int> > *this,
        const char *pArray,
        int size)
{
  int m_nAllocationCount; // eax
  char *m_pMemory; // ecx
  int v6; // eax
  int i; // eax

  this->m_Size = 0;
  if ( size != 0 )
  {
    m_nAllocationCount = this->m_Memory.m_nAllocationCount;
    if ( size > m_nAllocationCount )
      CUtlMemory<char,int>::Grow((CUtlMemory<unsigned char,int> *)this, num: size - m_nAllocationCount);
    this->m_Size += size;
    m_pMemory = this->m_Memory.m_pMemory;
    v6 = this->m_Size - size;
    this->m_pElements = this->m_Memory.m_pMemory;
    if ( v6 > 0 && size > 0 )
      _V_memmove(dest: &m_pMemory[size], src: m_pMemory, count: v6);
  }
  for ( i = 0; i < size; ++i )
    this->m_Memory.m_pMemory[i] = pArray[i];
}

//------------------------------------------------------------------------------
// Address: 0x0040C950
// Name: void DefaultScriptLoadedCallback(char const __near *,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DefaultScriptLoadedCallback()
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x0040C960
// Name: void AddScriptToStack(char __near *,enum ScriptPathMode_t)
// Source: json
//------------------------------------------------------------------------------
void __cdecl AddScriptToStack(char *filename, ScriptPathMode_t pathMode)
{
  int File; // esi
  const char *v3; // [esp-8h] [ebp-8h]

  if ( ++script == (script_t *)token )
    _Error(a1: "script file exceeded MAX_INCLUDES");
  if ( pathMode == SCRIPT_USE_RELATIVE_PATH )
  {
    V_strncpy(pDest: script->filename, pSrc: filename, maxLen: 1024);
  }
  else
  {
    v3 = ExpandPath(path: filename);
    V_strncpy(pDest: script->filename, pSrc: v3, maxLen: 1024);
  }
  File = LoadFile(filename: script->filename, bufferptr: (void **)&script->buffer);
  if ( g_pfnCallback != nullptr )
  {
    if ( script == &scriptstack[1] )
      g_pfnCallback(a1: script->filename, a2: nullptr, a3: 0);
    else
      g_pfnCallback(a1: script->filename, a2: script[-1].filename, a3: script[-1].line);
  }
  script->line = 1;
  script->script_p = script->buffer;
  script->end_p = &script->buffer[File];
}

//------------------------------------------------------------------------------
// Address: 0x0040CA40
// Name: bool AddMacroToStack(char __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl AddMacroToStack(char *macroname)
{
  int v2; // esi
  bool v3; // zf
  script_t *v4; // edi
  script_t *v5; // ebx
  int nummacroparams; // eax
  char *macrobuffer; // esi
  char **macroparam; // edi
  unsigned int v9; // esi
  script_t *pmacro; // [esp+4h] [ebp-4h]
  int i; // [esp+10h] [ebp+8h]

  if ( *macroname != 36 )
    return 0;
  v2 = 0;
  v3 = nummacros == 0;
  if ( nummacros > 0 )
  {
    do
    {
      if ( _V_stricmp(s1: macrolist[v2]->filename, s2: macroname + 1) == 0 )
        break;
      ++v2;
    }
    while ( v2 < nummacros );
    v3 = v2 == nummacros;
  }
  if ( v3 )
    return 0;
  v4 = macrolist[v2];
  v5 = script + 2;
  pmacro = v4;
  if ( &script[2] == (script_t *)token )
    _Error(a1: "script file exceeded MAX_INCLUDES");
  nummacroparams = v4->nummacroparams;
  macrobuffer = v5->macrobuffer;
  v5->nummacroparams = nummacroparams;
  i = 0;
  if ( nummacroparams > 0 )
  {
    macroparam = v5->macroparam;
    do
    {
      GetToken(crossline: 0);
      strcpy(macrobuffer, token);
      *macroparam = *(char **)((char *)macroparam + (char *)pmacro - (char *)v5);
      macroparam[64] = macrobuffer;
      macrobuffer += strlen(token) + 1;
      if ( macrobuffer >= (char *)v5->macroparam )
        _Error(a1: "Macro buffer overflow\n");
      ++macroparam;
      ++i;
    }
    while ( i < v5->nummacroparams );
    v4 = pmacro;
  }
  script = (script_t *)strcpy(v5->filename, v4->filename);
  v9 = v4->end_p - v4->buffer;
  script->buffer = (char *)malloc(size: v9 + 1);
  memcpy(dst: (unsigned __int8 *)script->buffer, src: (unsigned __int8 *)v4->buffer, count: v9);
  v4->buffer[v9] = 0;
  script->script_p = script->buffer;
  script->end_p = &script->buffer[v9];
  script->line = v4->line;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0040CC00
// Name: bool ExpandMacroToken(char __near * __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl ExpandMacroToken(char **token_p)
{
  char *script_p; // eax
  _BYTE *v2; // ebx
  char v3; // al
  script_t *v5; // eax
  int v6; // esi
  int v7; // edi
  bool v8; // zf
  const char *v9; // edx
  unsigned int v10; // eax
  _BYTE *v11; // esi
  char v12; // cl
  char *s2; // [esp+0h] [ebp-4h]

  if ( script->nummacroparams == 0 )
    return 0;
  script_p = script->script_p;
  if ( *script_p != 36 )
    return 0;
  v2 = script_p + 1;
  s2 = script_p + 1;
  v3 = script_p[1];
  if ( v3 <= 32 )
  {
LABEL_6:
    if ( *v2 != 36 )
      return 0;
  }
  else
  {
    while ( v3 != 36 )
    {
      v3 = *++v2;
      if ( v3 <= 32 )
        goto LABEL_6;
    }
  }
  *v2 = 0;
  v5 = script;
  v6 = 0;
  if ( script->nummacroparams <= 0 )
    goto LABEL_13;
  v7 = 5136;
  do
  {
    v8 = _V_stricmp(s1: *(const char **)&v5->filename[v7], s2) == 0;
    v5 = script;
    if ( v8 )
      break;
    ++v6;
    v7 += 4;
  }
  while ( v6 < script->nummacroparams );
  if ( v6 >= script->nummacroparams )
  {
LABEL_13:
    _Error(a1: "unknown macro token \"%s\" in %s\n", s2, v5->filename);
    v5 = script;
  }
  v9 = v5->macrovalue[v6];
  v10 = strlen(v9);
  v11 = *token_p;
  do
  {
    v12 = *v9;
    *v11++ = *v9++;
  }
  while ( v12 != 0 );
  *token_p += v10;
  script->script_p = v2 + 1;
  if ( script->script_p >= script->end_p )
    _Error(a1: "Macro expand overflow\n");
  if ( *token_p >= (char *)&nummacros )
    _Error(a1: "Token too large on line %i\n", scriptline);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0040CD30
// Name: void ParseFromMemory(char __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ParseFromMemory(char *buffer, int size)
{
  scriptstack[1].buffer = buffer;
  scriptstack[1].script_p = buffer;
  script = &scriptstack[1];
  scriptstack[1].end_p = &buffer[size];
  strcpy(scriptstack[1].filename, "memory buffer");
  scriptstack[1].line = 1;
  endofscript = 0;
  tokenready = 0;
}

//------------------------------------------------------------------------------
// Address: 0x0040CDA0
// Name: int EndOfScript(int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl EndOfScript(int crossline)
{
  if ( crossline == 0 )
    _Error(a1: "Line %i is incomplete\n", scriptline);
  if ( strcmp(script->filename, aMemoryB) == 0
    || (free(pBlock: script->buffer), script->buffer = nullptr, script == &scriptstack[1]) )
  {
    endofscript = 1;
    return 0;
  }
  else
  {
    --script;
    scriptline = script->line;
    return GetToken(crossline);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040CE60
// Name: int TokenAvailable(void)
// Source: json
//------------------------------------------------------------------------------
int __cdecl TokenAvailable()
{
  char *script_p; // eax
  char *end_p; // edx
  char v3; // cl
  char v4; // cl

  if ( tokenready != 0 )
    return 1;
  script_p = script->script_p;
  end_p = script->end_p;
  if ( script_p < end_p )
  {
    v3 = *script_p;
    if ( *script_p > 32 )
    {
LABEL_8:
      v4 = *script_p;
      if ( *script_p != 59 && v4 != 35 && (v4 != 47 || script_p[1] != 47) )
        return 1;
    }
    else
    {
      while ( v3 != 10 )
      {
        if ( ++script_p == end_p )
          break;
        v3 = *script_p;
        if ( *script_p > 32 )
          goto LABEL_8;
      }
    }
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x0040CEC0
// Name: public: virtual bool CScriptLib::DoesFileExist(char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CScriptLib::DoesFileExist(CScriptLib *this, const char *pFilename)
{
  return g_pFullFileSystem->FileExists(this: &g_pFullFileSystem->IBaseFileSystem, a2: pFilename, a3: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x0040CEE0
// Name: public: virtual bool CScriptLib::ReadFileToBuffer(char const __near *,class CUtlBuffer __near &,bool,bool)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CScriptLib::ReadFileToBuffer(
        CScriptLib *this,
        const char *pSourceName,
        CUtlBuffer *buffer,
        bool bText,
        bool bNoOpenFailureWarning)
{
  int *v5; // eax
  const char *v6; // eax

  if ( g_pFullFileSystem->ReadFile(
         this: &g_pFullFileSystem->IBaseFileSystem,
         a2: pSourceName,
         a3: nullptr,
         a4: buffer,
         a5: 0,
         a6: 0,
         a7: nullptr) )
  {
    if ( bText )
      CUtlBuffer::SetBufferType(this: buffer, bIsText: true, bContainsCRLF: true);
    else
      CUtlBuffer::SetBufferType(this: buffer, bIsText: false, bContainsCRLF: false);
    return 1;
  }
  else
  {
    if ( !bNoOpenFailureWarning )
    {
      v5 = _errno();
      v6 = strerror(errnum: *v5);
      _Msg(a1: "ReadFileToBuffer(): Error opening %s: %s\n", pSourceName, v6);
    }
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040CF60
// Name: public: virtual bool CScriptLib::WriteBufferToFile(char const __near *,class CUtlBuffer __near &,enum DiskWriteMode_t)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CScriptLib::WriteBufferToFile(
        CScriptLib *this,
        const char *pTargetName,
        CUtlBuffer *buffer,
        DiskWriteMode_t writeMode)
{
  _BYTE *v5; // eax
  _BYTE *v6; // esi
  _BYTE *v7; // eax
  char dirPath[260]; // [esp+8h] [ebp-104h] BYREF

  strcpy(dirPath, pTargetName);
  strchr(string: (unsigned __int8 *)dirPath, chr: 0x5Cu);
  v6 = v5;
  if ( v5 != nullptr )
  {
    while ( 1 )
    {
      strchr(string: v6 + 1, chr: 0x5Cu);
      v6 = v7;
      if ( v7 == nullptr )
        break;
      *v7 = 0;
      _mkdir(path: dirPath);
      *v6 = 92;
    }
  }
  return writeMode != WRITE_TO_DISK_ALWAYS
      && (writeMode != WRITE_TO_DISK_UPDATE || !this->DoesFileExist(this, a2: pTargetName))
      || g_pFullFileSystem->WriteFile(
           this: &g_pFullFileSystem->IBaseFileSystem,
           a2: pTargetName,
           a3: nullptr,
           a4: buffer);
}

//------------------------------------------------------------------------------
// Address: 0x0040D020
// Name: public: virtual int CScriptLib::CompareFileTime(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CScriptLib::CompareFileTime(CScriptLib *this, const char *pFilenameA, const char *pFilenameB)
{
  unsigned int v3; // esi
  unsigned int v4; // eax
  bool v5; // cf

  v3 = g_pFullFileSystem->GetFileTime(this: &g_pFullFileSystem->IBaseFileSystem, a2: pFilenameA, a3: nullptr);
  v4 = g_pFullFileSystem->GetFileTime(this: &g_pFullFileSystem->IBaseFileSystem, a2: pFilenameB, a3: nullptr);
  if ( v3 == -1 )
    v3 = 0;
  if ( v4 == -1 )
    return v3 != 0;
  v5 = v4 < v3;
  if ( v4 <= v3 )
    return v5;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0040D080
// Name: public: virtual char __near * CScriptLib::MakeTemporaryFilename(char const __near *,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CScriptLib::MakeTemporaryFilename(CScriptLib *this, const char *pchModPath, char *pPath, int pathSize)
{
  char *v4; // eax
  char *v5; // esi

  v4 = _tempnam(dir: pchModPath, pfx: "mgd_");
  v5 = v4;
  if ( *v4 == 92 )
    v5 = v4 + 1;
  if ( v5[strlen(v5) - 1] == 46 )
    v5[strlen(v5) - 1] = 0;
  V_snprintf(pDest: pPath, maxLen: pathSize, pFormat: "%s.tmp", v5);
  free(pBlock: v5);
  return pPath;
}

//------------------------------------------------------------------------------
// Address: 0x0040D190
// Name: void DefineMacro(char __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DefineMacro(char *macroname)
{
  script_t *v1; // edi
  char *script_p; // esi
  char *macrobuffer; // ebx
  unsigned int v4; // ebx
  unsigned __int8 *v5; // eax
  int v6; // eax
  script_t *v7; // edx

  v1 = (script_t *)malloc(size: 0x1614u);
  strcpy(v1->filename, macroname);
  v1->line = script->line;
  v1->nummacroparams = 0;
  script_p = script->script_p;
  macrobuffer = v1->macrobuffer;
  while ( TokenAvailable() != 0 )
  {
    GetToken(crossline: 0);
    if ( token[0] == 92 && byte_435AFF9 == 92 )
      break;
    script_p = script->script_p;
    v1->macroparam[v1->nummacroparams++] = macrobuffer;
    strcpy(macrobuffer, token);
    macrobuffer += strlen(token) + 1;
    if ( macrobuffer >= (char *)v1->macroparam )
      _Error(a1: "Macro buffer overflow\n");
  }
  for ( script->script_p = script_p; *script_p != 0; ++script_p )
  {
    if ( *script_p == 10 )
      break;
    if ( *script_p == 92 && script_p[1] == 92 )
    {
      do
      {
        if ( *script_p == 10 )
          break;
        *script_p++ = 32;
      }
      while ( *script_p != 0 );
      if ( *script_p == 0 )
        break;
    }
  }
  v4 = script_p - script->script_p;
  v5 = (unsigned __int8 *)malloc(size: v4 + 1);
  v1->buffer = (char *)v5;
  memcpy(dst: v5, src: (unsigned __int8 *)script->script_p, count: v4);
  v1->buffer[v4] = 0;
  v1->end_p = &v1->buffer[v4];
  v6 = nummacros;
  v7 = script;
  macrolist[nummacros] = v1;
  nummacros = v6 + 1;
  v7->script_p = script_p;
}

//------------------------------------------------------------------------------
// Address: 0x0040D3D0
// Name: bool ExpandVariableToken(char __near * __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl ExpandVariableToken(char **token_p)
{
  char *script_p; // eax
  const char *v2; // edi
  _BYTE *v3; // ebx
  char v4; // al
  int v6; // esi
  char *value; // esi
  unsigned int v8; // eax
  char *v9; // edx
  _BYTE *v10; // esi
  char v11; // cl

  script_p = script->script_p;
  if ( *script_p != 36 )
    return 0;
  v2 = script_p + 1;
  v3 = script_p + 1;
  v4 = script_p[1];
  if ( v4 <= 32 )
  {
LABEL_5:
    if ( *v3 != 36 )
      return 0;
  }
  else
  {
    while ( v4 != 36 )
    {
      v4 = *++v3;
      if ( v4 <= 32 )
        goto LABEL_5;
    }
  }
  v6 = 0;
  *v3 = 0;
  if ( g_definevariable.m_Size <= 0 )
    goto LABEL_12;
  while ( V_strnicmp(s1: g_definevariable.m_Memory.m_pMemory[v6].param, s2: v2, n: v3 - v2 - 2) != 0 )
  {
    if ( ++v6 >= g_definevariable.m_Size )
      goto LABEL_12;
  }
  if ( v6 >= g_definevariable.m_Size )
LABEL_12:
    _Error(a1: "unknown variable token \"%s\" in %s\n", v2, script->filename);
  value = g_definevariable.m_Memory.m_pMemory[v6].value;
  v8 = strlen(value);
  v9 = value;
  v10 = *token_p;
  do
  {
    v11 = *v9;
    *v10++ = *v9++;
  }
  while ( v11 != 0 );
  *token_p += v8;
  script->script_p = v3 + 1;
  if ( script->script_p >= script->end_p )
    _Error(a1: "Macro expand overflow\n");
  if ( *token_p >= (char *)&nummacros )
    _Error(a1: "Token too large on line %i\n", scriptline);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0040D500
// Name: public: int CUtlVector<struct variable_t,class CUtlMemory<struct variable_t,int>>::InsertBefore(int,struct variable_t const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<variable_t,CUtlMemory<variable_t,int>>::InsertBefore(
        CUtlVector<variable_t,CUtlMemory<variable_t,int> > *this,
        int elem,
        const variable_t *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  variable_t *m_pMemory; // ecx
  int v7; // eax
  variable_t *v8; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<variable_t,int>::Grow(this: &this->m_Memory, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 8 * v7);
  v8 = &this->m_Memory.m_pMemory[elem];
  if ( v8 != nullptr )
    *v8 = *src;
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x0040D570
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
// Address: 0x0040D5E0
// Name: void DefineVariable(char __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DefineVariable(char *variablename)
{
  char *v1; // eax
  char *v2; // eax
  char *v3; // ecx
  char v4; // dl
  variable_t v; // [esp+8h] [ebp-8h] BYREF

  if ( variablename != nullptr
    && (v1 = (char *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: strlen(variablename) + 1)) != nullptr )
  {
    strcpy(v1, variablename);
  }
  else
  {
    v1 = nullptr;
  }
  v.param = v1;
  GetToken(crossline: 0);
  v2 = (char *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: strlen(token) + 1);
  if ( v2 != nullptr )
  {
    v3 = v2;
    do
    {
      v4 = v3[token - v2];
      *v3++ = v4;
    }
    while ( v4 != 0 );
  }
  else
  {
    v2 = nullptr;
  }
  v.value = v2;
  CUtlVector<variable_t,CUtlMemory<variable_t,int>>::InsertBefore(
    this: &g_definevariable,
    elem: g_definevariable.m_Size,
    src: &v);
}

//------------------------------------------------------------------------------
// Address: 0x0040D6A0
// Name: int GetToken(int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl GetToken(int crossline)
{
  script_t *v1; // eax
  char *script_p; // ecx
  char v3; // dl
  script_t *v4; // eax
  char *v5; // ecx
  char *v6; // edx
  char v7; // cl
  char *v8; // ecx
  char v9; // dl
  script_t *v10; // eax
  char *v11; // edx
  script_t *v12; // eax
  int line; // edx
  char v14; // cl
  char *v15; // esi
  script_t *v16; // eax
  char i; // cl
  char *v18; // esi
  char *v19; // ecx
  char *token_p; // [esp+Ch] [ebp-4h] BYREF

  if ( tokenready != 0 )
  {
LABEL_54:
    tokenready = 0;
    return 1;
  }
  else
  {
    while ( 1 )
    {
      v1 = script;
      if ( script->script_p >= script->end_p )
        return EndOfScript(crossline);
      tokenready = 0;
      while ( 1 )
      {
        while ( 1 )
        {
          if ( *v1->script_p <= 32 )
          {
            do
            {
              script_p = v1->script_p;
              if ( script_p >= v1->end_p )
                return EndOfScript(crossline);
              v3 = *script_p;
              v1->script_p = script_p + 1;
              if ( v3 == 10 )
              {
                if ( crossline == 0 )
                  _Error(a1: "Line %i is incomplete\n", scriptline);
                v4 = script;
                ++script->line;
                scriptline = v4->line;
              }
              v1 = script;
            }
            while ( *script->script_p <= 32 );
          }
          v5 = v1->script_p;
          if ( v5 >= v1->end_p )
            return EndOfScript(crossline);
          v6 = v1->script_p;
          v7 = *v5;
          if ( v7 != 59 && v7 != 35 )
          {
            if ( v7 != 47 )
              goto LABEL_30;
            if ( v6[1] != 47 )
              break;
          }
          if ( crossline == 0 )
          {
            _Error(a1: "Line %i is incomplete\n", scriptline);
            v1 = script;
          }
          if ( *v1->script_p != 10 )
          {
            do
            {
              ++v1->script_p;
              v1 = script;
              v11 = script->script_p;
              if ( v11 >= script->end_p )
                return EndOfScript(crossline);
            }
            while ( *v11 != 10 );
          }
          ++v1->script_p;
          v12 = script;
          ++script->line;
          line = v12->line;
          v1 = script;
          scriptline = line;
        }
        if ( v6[1] != 42 )
          break;
        v1->script_p += 2;
        while ( 1 )
        {
          v8 = script->script_p;
          if ( *v8 == 42 && v8[1] == 47 )
            break;
          v9 = *v8;
          script->script_p = v8 + 1;
          if ( v9 != 10 )
          {
            v10 = script;
            if ( script->script_p >= script->end_p )
              return EndOfScript(crossline);
            ++script->line;
            scriptline = v10->line;
          }
        }
        script->script_p += 2;
        v1 = script;
      }
LABEL_30:
      v14 = *v6;
      v15 = token;
      token_p = token;
      if ( v14 == 34 )
      {
        ++v1->script_p;
        v16 = script;
        for ( i = *script->script_p; i != 34; i = *v16->script_p )
        {
          *v15 = i;
          ++script->script_p;
          v16 = script;
          ++v15;
          if ( script->script_p == script->end_p )
            break;
          if ( v15 == (char *)&nummacros )
          {
            _Error(a1: "Token too large on line %i\n", scriptline);
            v16 = script;
          }
        }
        ++v16->script_p;
      }
      else
      {
        for ( ; v14 > 32; v14 = *script->script_p )
        {
          if ( v14 == 59 )
            break;
          if ( ExpandMacroToken(&token_p) != 0 || ExpandVariableToken(&token_p) != 0 )
          {
            v15 = token_p;
          }
          else
          {
            v18 = token_p;
            *token_p = *script->script_p++;
            v19 = script->script_p;
            v15 = v18 + 1;
            token_p = v15;
            if ( v19 == script->end_p )
              break;
            if ( v15 == (char *)&nummacros )
              _Error(a1: "Token too large on line %i\n", scriptline);
          }
        }
      }
      *v15 = 0;
      if ( _V_stricmp(s1: token, s2: "$include") != 0 )
      {
        if ( _V_stricmp(s1: token, s2: "$definemacro") != 0 )
        {
          if ( _V_stricmp(s1: token, s2: "$definevariable") != 0 )
          {
            if ( AddMacroToStack(macroname: token) == 0 )
              return 1;
          }
          else
          {
            GetToken(crossline: 0);
            DefineVariable(variablename: token);
          }
        }
        else
        {
          GetToken(crossline: 0);
          DefineMacro(macroname: token);
        }
      }
      else
      {
        GetToken(crossline: 0);
        AddScriptToStack(filename: token, pathMode: SCRIPT_USE_ABSOLUTE_PATH);
      }
      if ( tokenready != 0 )
        goto LABEL_54;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040DAA0
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
    CUtlMemory<fileList_t,int>::Grow(this: &this->m_Memory, num: m_Size - m_nAllocationCount + 1);
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
// Address: 0x0040DB10
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
    CUtlMemory<fileList_t,int>::Grow(this: &this->m_Memory, num: num + m_Size - m_nAllocationCount);
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
// Address: 0x0040DBB0
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
// Address: 0x0040DC20
// Name: private: int CScriptLib::GetFileList(char const __near *,char const __near *,class CUtlVector<struct fileList_t,class CUtlMemory<struct fileList_t,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CScriptLib::GetFileList(
        CScriptLib *this,
        const char *pDirPath,
        const char *pPattern,
        CUtlVector<fileList_t,CUtlMemory<fileList_t,int> > *fileList)
{
  unsigned int v5; // kr00_4
  int v6; // eax
  char v7; // cl
  char *v8; // edi
  char v9; // al
  unsigned int v10; // eax
  char *v11; // edi
  char v12; // cl
  int v13; // esi
  int v15; // eax
  char v16; // cl
  unsigned int v17; // eax
  char *v18; // edi
  char v19; // cl
  char *v20; // edi
  char *v21; // esi
  char v22; // cl
  int m_Size; // eax
  int v24; // esi
  char v25; // [esp+Bh] [ebp-435h] BYREF
  char fileName[260]; // [esp+Ch] [ebp-434h] BYREF
  char fullPath[260]; // [esp+110h] [ebp-330h] BYREF
  _finddata64i32_t findData; // [esp+214h] [ebp-22Ch] BYREF
  char sourcePath[260]; // [esp+33Ch] [ebp-104h] BYREF
  int h; // [esp+448h] [ebp+8h]
  char bFindDirs_3; // [esp+453h] [ebp+13h]

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
  v5 = strlen(sourcePath);
  if ( v5 != 0 )
  {
    if ( findData.name[v5 + 259] != 92 )
    {
      sourcePath[v5] = 92;
      sourcePath[v5 + 1] = 0;
    }
  }
  else
  {
    strcpy(sourcePath, ".\\");
  }
  v6 = 0;
  do
  {
    v7 = sourcePath[v6];
    fullPath[v6++] = v7;
  }
  while ( v7 != 0 );
  if ( *pPattern != 92 || pPattern[1] != 0 )
  {
    bFindDirs_3 = 0;
    v10 = strlen(pPattern) + 1;
    v11 = &fileName[259];
    do
      v12 = *++v11;
    while ( v12 != 0 );
    qmemcpy(v11, pPattern, v10);
  }
  else
  {
    bFindDirs_3 = 1;
    v8 = &fileName[259];
    do
      v9 = *++v8;
    while ( v9 != 0 );
    strcpy(v8, "*");
  }
  v13 = _findfirst64i32(szWild: fullPath, pfd: &findData);
  h = v13;
  if ( v13 == -1 )
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
      v15 = 0;
      do
      {
        v16 = sourcePath[v15];
        fileName[v15++] = v16;
      }
      while ( v16 != 0 );
      v17 = strlen(findData.name) + 1;
      v18 = &v25;
      do
        v19 = *++v18;
      while ( v19 != 0 );
      qmemcpy(v18, findData.name, 4 * (v17 >> 2));
      v21 = &findData.name[4 * (v17 >> 2)];
      v20 = &v18[4 * (v17 >> 2)];
      v22 = v17;
      m_Size = fileList->m_Size;
      qmemcpy(v20, v21, v22 & 3);
      v24 = CUtlVector<fileList_t,CUtlMemory<fileList_t,int>>::InsertBefore(this: fileList, elem: m_Size);
      CUtlString::Set(this: &fileList->m_Memory.m_pMemory[v24].fileName, pValue: fileName);
      fileList->m_Memory.m_pMemory[v24].timeWrite = findData.time_write;
      v13 = h;
    }
  }
  while ( _findnext64i32(hFile: v13, pfd: &findData) == 0 );
  _findclose(hFile: v13);
  return fileList->m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x0040DE80
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
// Address: 0x0040DEE0
// Name: public: virtual void CScriptLib::DeleteTemporaryFiles(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CScriptLib::DeleteTemporaryFiles(CScriptLib *this, const char *pFileMask)
{
  char *v2; // eax
  char *v3; // edx
  char v4; // cl
  unsigned int v5; // eax
  char *v6; // edi
  char v7; // cl
  int (__thiscall *FindFiles)(struct CScriptLib *, char *, bool, CUtlVector<fileList_t,CUtlMemory<fileList_t,int> > *); // edx
  int v9; // esi
  int v10; // edi
  const char *v11; // eax
  fileList_t *m_pMemory; // eax
  char v13; // [esp+3h] [ebp-11Dh] BYREF
  char tempPath[260]; // [esp+4h] [ebp-11Ch] BYREF
  CScriptLib *v15; // [esp+108h] [ebp-18h]
  CUtlVector<fileList_t,CUtlMemory<fileList_t,int> > fileList; // [esp+10Ch] [ebp-14h] BYREF

  v15 = this;
  v2 = getenv(option: "temp");
  if ( v2 != nullptr || (v2 = getenv(option: "tmp")) != nullptr )
  {
    v3 = (char *)(tempPath - v2);
    do
    {
      v4 = *v2;
      v2[(_DWORD)v3] = *v2;
      ++v2;
    }
    while ( v4 != 0 );
    V_AppendSlash(pStr: tempPath, strSize: 260);
    v5 = strlen(pFileMask) + 1;
    v6 = &v13;
    do
      v7 = *++v6;
    while ( v7 != 0 );
    qmemcpy(v6, pFileMask, v5);
    FindFiles = v15->FindFiles;
    memset(&fileList, 0, sizeof(fileList));
    FindFiles(this: v15, a2: tempPath, a3: false, a4: &fileList);
    v9 = 0;
    if ( fileList.m_Size > 0 )
    {
      v10 = 0;
      do
      {
        v11 = CUtlString::Get(this: &fileList.m_Memory.m_pMemory[v10].fileName);
        _unlink(path: v11);
        ++v9;
        ++v10;
      }
      while ( v9 < fileList.m_Size );
    }
    CUtlVector<fileList_t,CUtlMemory<fileList_t,int>>::RemoveAll(this: &fileList);
    m_pMemory = fileList.m_Memory.m_pMemory;
    if ( fileList.m_Memory.m_nGrowSize >= 0 )
    {
      if ( fileList.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: fileList.m_Memory.m_pMemory);
        m_pMemory = nullptr;
        fileList.m_Memory.m_pMemory = nullptr;
      }
      fileList.m_Memory.m_nAllocationCount = 0;
    }
    fileList.m_pElements = m_pMemory;
    if ( fileList.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040E010
// Name: private: void CScriptLib::RecurseFileTree_r(char const __near *,int,class CUtlVector<class CUtlString,class CUtlMemory<class CUtlString,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CScriptLib::RecurseFileTree_r(
        CScriptLib *this,
        const char *pDirPath,
        int depth,
        CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *dirList)
{
  fileList_t *i; // ebx
  int v5; // eax
  int v6; // eax
  fileList_t *m_pMemory; // edi
  const char *v8; // eax
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CUtlString *v11; // ecx
  int v12; // eax
  int v13; // edi
  CUtlString *v14; // ecx
  CUtlVector<fileList_t,CUtlMemory<fileList_t,int> > fileList; // [esp+Ch] [ebp-18h] BYREF
  CScriptLib *v16; // [esp+20h] [ebp-4h]

  i = nullptr;
  v16 = this;
  memset(&fileList, 0, sizeof(fileList));
  v5 = CScriptLib::GetFileList(this, pDirPath, pPattern: "\\", &fileList);
  if ( v5 != 0 )
  {
    if ( v5 > 0 )
    {
      m_pMemory = fileList.m_Memory.m_pMemory;
      for ( i = (fileList_t *)v5; i != nullptr; i = (fileList_t *)((char *)i - 1) )
      {
        v8 = CUtlString::Get(this: &m_pMemory->fileName);
        CScriptLib::RecurseFileTree_r(this: v16, pDirPath: v8, depth: depth + 1, dirList);
        ++m_pMemory;
      }
    }
    m_Size = dirList->m_Size;
    m_nAllocationCount = dirList->m_Memory.m_nAllocationCount;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<CUtlString,int>::Grow(this: &dirList->m_Memory, num: m_Size - m_nAllocationCount + 1);
    ++dirList->m_Size;
    v11 = dirList->m_Memory.m_pMemory;
    v12 = dirList->m_Size - m_Size - 1;
    dirList->m_pElements = dirList->m_Memory.m_pMemory;
    if ( v12 > (int)i )
      _V_memmove(dest: &v11[m_Size + 1], src: &v11[m_Size], count: 16 * v12);
    v13 = m_Size;
    v14 = &dirList->m_Memory.m_pMemory[v13];
    if ( v14 != nullptr )
      CUtlString::CUtlString(this: v14);
    CUtlString::Set(this: &dirList->m_Memory.m_pMemory[v13], pValue: pDirPath);
    CUtlVector<fileList_t,CUtlMemory<fileList_t,int>>::RemoveAll(this: &fileList);
    if ( fileList.m_Memory.m_nGrowSize >= (int)i && fileList.m_Memory.m_pMemory != i )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: fileList.m_Memory.m_pMemory);
  }
  else
  {
    v6 = CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>::InsertBefore(this: dirList, elem: dirList->m_Size);
    CUtlString::Set(this: &dirList->m_Memory.m_pMemory[v6], pValue: pDirPath);
    CUtlVector<fileList_t,CUtlMemory<fileList_t,int>>::~CUtlVector<fileList_t,CUtlMemory<fileList_t,int>>(this: &fileList);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040E130
// Name: public: virtual int CScriptLib::FindFiles(char __near *,bool,class CUtlVector<struct fileList_t,class CUtlMemory<struct fileList_t,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CScriptLib::FindFiles(
        CScriptLib *this,
        char *pFileMask,
        bool bRecurse,
        CUtlVector<fileList_t,CUtlMemory<fileList_t,int> > *fileList)
{
  CScriptLib *v4; // edi
  char *v5; // edi
  char v6; // al
  unsigned int v7; // eax
  char *v8; // edi
  char v9; // cl
  int m_nGrowSize; // esi
  fileList_t *m_pMemory; // eax
  const char *v13; // eax
  CUtlVector<fileList_t,CUtlMemory<fileList_t,int> > *v14; // esi
  int m_Size; // edi
  int inserted; // eax
  fileList_t *v17; // edi
  int v18; // ebx
  CUtlString *p_fileName; // esi
  int timeWrite_high; // eax
  bool v21; // zf
  CUtlString *v22; // eax
  unsigned int v23; // [esp-8h] [ebp-34Ch]
  char extension[260]; // [esp+8h] [ebp-33Ch] BYREF
  char dirPath[260]; // [esp+10Ch] [ebp-238h] BYREF
  char pattern[260]; // [esp+210h] [ebp-134h] BYREF
  CScriptLib *v27; // [esp+314h] [ebp-30h]
  int i; // [esp+318h] [ebp-2Ch]
  CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > dirList; // [esp+31Ch] [ebp-28h] BYREF
  CUtlVector<fileList_t,CUtlMemory<fileList_t,int> > tempList; // [esp+330h] [ebp-14h] BYREF
  char *pFileMaska; // [esp+34Ch] [ebp+8h]
  int bRecursea; // [esp+350h] [ebp+Ch]

  v4 = this;
  v27 = this;
  strcpy(dirPath, pFileMask);
  V_StripFilename(path: dirPath);
  V_FileBase(in: pFileMask, out: pattern, maxlen: 260);
  V_ExtractFileExtension(path: pFileMask, dest: extension, destSize: 260);
  if ( extension[0] != 0 )
  {
    v5 = &dirPath[259];
    do
      v6 = *++v5;
    while ( v6 != 0 );
    strcpy(v5, ".");
    v7 = strlen(extension) + 1;
    v8 = &dirPath[259];
    do
      v9 = *++v8;
    while ( v9 != 0 );
    qmemcpy(v8, extension, v7);
    v4 = v27;
  }
  if ( bRecurse )
  {
    memset(&tempList, 0, sizeof(tempList));
    memset(&dirList, 0, sizeof(dirList));
    CScriptLib::RecurseFileTree_r(this: v4, pDirPath: dirPath, depth: 0, &dirList);
    i = 0;
    if ( dirList.m_Size > 0 )
    {
      bRecursea = 0;
      while ( 1 )
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
          v23 = 24 * dirList.m_Size;
          if ( m_pMemory != nullptr )
            m_pMemory = (fileList_t *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v23);
          else
            m_pMemory = (fileList_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v23);
          tempList.m_Memory.m_pMemory = m_pMemory;
        }
        tempList.m_pElements = m_pMemory;
        v13 = CUtlString::Get(this: &dirList.m_Memory.m_pMemory[bRecursea]);
        CScriptLib::GetFileList(this: v4, pDirPath: v13, pPattern: pattern, fileList: &tempList);
        v14 = fileList;
        m_Size = tempList.m_Size;
        inserted = CUtlVector<fileList_t,CUtlMemory<fileList_t,int>>::InsertMultipleBefore(
                     this: fileList,
                     elem: fileList->m_Size,
                     num: tempList.m_Size);
        if ( m_Size > 0 )
        {
          v17 = tempList.m_Memory.m_pMemory;
          v18 = inserted;
          pFileMaska = (char *)tempList.m_Size;
          while ( 1 )
          {
            p_fileName = &v14->m_Memory.m_pMemory[v18].fileName;
            CUtlString::operator=(this: p_fileName, src: &v17->fileName);
            p_fileName[1].m_Storage.m_Memory.m_pMemory = (unsigned __int8 *)v17->timeWrite;
            timeWrite_high = HIDWORD(v17->timeWrite);
            ++v17;
            ++v18;
            v21 = pFileMaska-- == (char *)1;
            p_fileName[1].m_Storage.m_Memory.m_nAllocationCount = timeWrite_high;
            if ( v21 )
              break;
            v14 = fileList;
          }
        }
        ++bRecursea;
        if ( ++i >= dirList.m_Size )
          break;
        v4 = v27;
      }
    }
    CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>::RemoveAll(this: &dirList);
    v22 = dirList.m_Memory.m_pMemory;
    if ( dirList.m_Memory.m_nGrowSize >= 0 )
    {
      if ( dirList.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: dirList.m_Memory.m_pMemory);
        v22 = nullptr;
        dirList.m_Memory.m_pMemory = nullptr;
      }
      dirList.m_Memory.m_nAllocationCount = 0;
    }
    dirList.m_pElements = v22;
    if ( dirList.m_Memory.m_nGrowSize >= 0 )
    {
      if ( v22 != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v22);
        dirList.m_Memory.m_pMemory = nullptr;
      }
      dirList.m_Memory.m_nAllocationCount = 0;
    }
    CUtlVector<fileList_t,CUtlMemory<fileList_t,int>>::RemoveAll(this: &tempList);
    if ( tempList.m_Memory.m_nGrowSize < 0 )
    {
      return fileList->m_Size;
    }
    else
    {
      if ( tempList.m_Memory.m_pMemory != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: tempList.m_Memory.m_pMemory);
      return fileList->m_Size;
    }
  }
  else
  {
    CScriptLib::GetFileList(this: v4, pDirPath: dirPath, pPattern: pattern, fileList);
    return fileList->m_Size;
  }
}

} // namespace vbspinfo

// ============================================================
// Overlay from vcd_sound_check (Missing functions)
// ============================================================
namespace vcd_sound_check {

//------------------------------------------------------------------------------
// Address: 0x00403AE0
// Name: void DefaultScriptLoadedCallback(char const __near *,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DefaultScriptLoadedCallback()
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x00403AF0
// Name: void AddScriptToStack(char __near *,enum ScriptPathMode_t)
// Source: json
//------------------------------------------------------------------------------
void __usercall AddScriptToStack(int a1@<edi>, char *filename, ScriptPathMode_t pathMode)
{
  int File; // esi
  const char *v4; // [esp-8h] [ebp-8h]
  const char *savedregs; // [esp+0h] [ebp+0h]

  if ( ++script == (script_t *)token )
    _Error(this: (ISceneTokenProcessor *)&stru_42EDA8, a2: savedregs);
  if ( pathMode == SCRIPT_USE_RELATIVE_PATH )
  {
    V_strncpy(pDest: script->filename, pSrc: filename, maxLen: 1024);
  }
  else
  {
    v4 = ExpandPath(path: filename);
    V_strncpy(pDest: script->filename, pSrc: v4, maxLen: 1024);
  }
  File = LoadFile(a1, filename: script->filename, bufferptr: (void **)&script->buffer);
  if ( g_pfnCallback != nullptr )
  {
    if ( script == &scriptstack[1] )
      g_pfnCallback(a1: script->filename, a2: nullptr, a3: 0);
    else
      g_pfnCallback(a1: script->filename, a2: script[-1].filename, a3: script[-1].line);
  }
  script->line = 1;
  script->script_p = script->buffer;
  script->end_p = &script->buffer[File];
}

//------------------------------------------------------------------------------
// Address: 0x00403BD0
// Name: void LoadScriptFile(char __near *,enum ScriptPathMode_t)
// Source: json
//------------------------------------------------------------------------------
void __usercall LoadScriptFile(int a1@<edi>, char *filename, ScriptPathMode_t pathMode)
{
  script = scriptstack;
  AddScriptToStack(a1, filename, pathMode);
  endofscript = 0;
  tokenready = 0;
}

//------------------------------------------------------------------------------
// Address: 0x00403C00
// Name: bool AddMacroToStack(char __near *)
// Source: json
//------------------------------------------------------------------------------
char __usercall AddMacroToStack@<al>(const char *a1@<ebx>, char *macroname)
{
  int v3; // esi
  bool v4; // zf
  script_t *v5; // edi
  script_t *v6; // ebx
  int nummacroparams; // eax
  char *macrobuffer; // esi
  char **macroparam; // edi
  unsigned int v10; // esi
  const char *v11; // [esp-Ch] [ebp-14h]
  script_t *pmacro; // [esp+4h] [ebp-4h]
  int i; // [esp+10h] [ebp+8h]

  if ( *macroname != 36 )
    return 0;
  v3 = 0;
  v4 = nummacros == 0;
  if ( nummacros > 0 )
  {
    do
    {
      if ( _V_stricmp(s1: macrolist[v3]->filename, s2: macroname + 1) == 0 )
        break;
      ++v3;
    }
    while ( v3 < nummacros );
    v4 = v3 == nummacros;
  }
  if ( v4 )
    return 0;
  v5 = macrolist[v3];
  v11 = a1;
  v6 = script + 2;
  pmacro = v5;
  if ( &script[2] == (script_t *)token )
    _Error(this: (ISceneTokenProcessor *)&stru_42EDA8, a2: v11);
  nummacroparams = v5->nummacroparams;
  macrobuffer = v6->macrobuffer;
  v6->nummacroparams = nummacroparams;
  i = 0;
  if ( nummacroparams > 0 )
  {
    macroparam = v6->macroparam;
    do
    {
      GetToken(crossline: 0);
      strcpy(macrobuffer, token);
      *macroparam = *(char **)((char *)macroparam + (char *)pmacro - (char *)v6);
      macroparam[64] = macrobuffer;
      macrobuffer += strlen(token) + 1;
      if ( macrobuffer >= (char *)v6->macroparam )
        _Error(this: (ISceneTokenProcessor *)&stru_42EDCC, a2: v11);
      ++macroparam;
      ++i;
    }
    while ( i < v6->nummacroparams );
    v5 = pmacro;
  }
  script = (script_t *)strcpy(v6->filename, v5->filename);
  v10 = v5->end_p - v5->buffer;
  script->buffer = (char *)operator new(nSize: v10 + 1);
  memcpy(dst: (unsigned __int8 *)script->buffer, src: (unsigned __int8 *)v5->buffer, count: v10);
  v5->buffer[v10] = 0;
  script->script_p = script->buffer;
  script->end_p = &script->buffer[v10];
  script->line = v5->line;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00403DC0
// Name: bool ExpandMacroToken(char __near * __near &)
// Source: json
//------------------------------------------------------------------------------
char __usercall ExpandMacroToken@<al>(const char *a1@<edi>, char **token_p)
{
  char *script_p; // eax
  _BYTE *v3; // ebx
  char v4; // al
  script_t *v6; // eax
  int v7; // esi
  int v8; // edi
  bool v9; // zf
  const char *v10; // edx
  unsigned int v11; // eax
  _BYTE *v12; // esi
  char v13; // cl
  char *s2; // [esp+0h] [ebp-4h]

  if ( script->nummacroparams == 0 )
    return 0;
  script_p = script->script_p;
  if ( *script_p != 36 )
    return 0;
  v3 = script_p + 1;
  s2 = script_p + 1;
  v4 = script_p[1];
  if ( v4 <= 32 )
  {
LABEL_6:
    if ( *v3 != 36 )
      return 0;
  }
  else
  {
    while ( v4 != 36 )
    {
      v4 = *++v3;
      if ( v4 <= 32 )
        goto LABEL_6;
    }
  }
  *v3 = 0;
  v6 = script;
  v7 = 0;
  if ( script->nummacroparams <= 0 )
    goto LABEL_13;
  v8 = 5136;
  do
  {
    v9 = _V_stricmp(s1: *(const char **)&v6->filename[v8], s2) == 0;
    v6 = script;
    if ( v9 )
      break;
    ++v7;
    v8 += 4;
  }
  while ( v7 < script->nummacroparams );
  if ( v7 >= script->nummacroparams )
  {
LABEL_13:
    _Error(this: (ISceneTokenProcessor *)&stru_42EE18, a2: s2, v6);
    v6 = script;
  }
  v10 = v6->macrovalue[v7];
  v11 = strlen(v10);
  v12 = *token_p;
  do
  {
    v13 = *v10;
    *v12++ = *v10++;
  }
  while ( v13 != 0 );
  *token_p += v11;
  script->script_p = v3 + 1;
  if ( script->script_p >= script->end_p )
    _Error(this: (ISceneTokenProcessor *)&stru_42EE00, a2: a1);
  if ( *token_p >= (char *)&nummacros )
    _Error(this: (ISceneTokenProcessor *)&stru_42EDE4, a2: scriptline);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00403EF0
// Name: int EndOfScript(int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl EndOfScript(int crossline)
{
  if ( crossline == 0 )
    _Error(this: (ISceneTokenProcessor *)&stru_42EE48, a2: scriptline);
  if ( strcmp(script->filename, "memory buffer") == 0
    || (free(pMem: script->buffer), script->buffer = nullptr, script == &scriptstack[1]) )
  {
    endofscript = 1;
    return 0;
  }
  else
  {
    --script;
    scriptline = (char *)script->line;
    return GetToken(crossline);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00403FB0
// Name: int TokenAvailable(void)
// Source: json
//------------------------------------------------------------------------------
int __cdecl TokenAvailable()
{
  char *script_p; // eax
  char *end_p; // edx
  char v3; // cl
  char v4; // cl

  if ( tokenready != 0 )
    return 1;
  script_p = script->script_p;
  end_p = script->end_p;
  if ( script_p < end_p )
  {
    v3 = *script_p;
    if ( *script_p > 32 )
    {
LABEL_8:
      v4 = *script_p;
      if ( *script_p != 59 && v4 != 35 && (v4 != 47 || script_p[1] != 47) )
        return 1;
    }
    else
    {
      while ( v3 != 10 )
      {
        if ( ++script_p == end_p )
          break;
        v3 = *script_p;
        if ( *script_p > 32 )
          goto LABEL_8;
      }
    }
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00404010
// Name: public: virtual bool CScriptLib::DoesFileExist(char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CScriptLib::DoesFileExist(CScriptLib *this, const char *pFilename)
{
  return g_pFullFileSystem->FileExists(this: &g_pFullFileSystem->IBaseFileSystem, a2: pFilename, a3: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x00404030
// Name: public: virtual bool CScriptLib::ReadFileToBuffer(char const __near *,class CUtlBuffer __near &,bool,bool)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CScriptLib::ReadFileToBuffer(
        CScriptLib *this,
        const char *pSourceName,
        CUtlBuffer *buffer,
        bool bText,
        bool bNoOpenFailureWarning)
{
  int *v5; // eax
  const char *v6; // eax

  if ( g_pFullFileSystem->ReadFile(
         this: &g_pFullFileSystem->IBaseFileSystem,
         a2: pSourceName,
         a3: nullptr,
         a4: buffer,
         a5: 0,
         a6: 0,
         a7: nullptr) )
  {
    if ( bText )
      CUtlBuffer::SetBufferType(this: buffer, bIsText: true, bContainsCRLF: true);
    else
      CUtlBuffer::SetBufferType(this: buffer, bIsText: false, bContainsCRLF: false);
    return 1;
  }
  else
  {
    if ( !bNoOpenFailureWarning )
    {
      v5 = _errno();
      v6 = strerror(errnum: *v5);
      _Msg(a1: "ReadFileToBuffer(): Error opening %s: %s\n", pSourceName, v6);
    }
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004040B0
// Name: public: virtual bool CScriptLib::WriteBufferToFile(char const __near *,class CUtlBuffer __near &,enum DiskWriteMode_t)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CScriptLib::WriteBufferToFile(
        CScriptLib *this,
        const char *pTargetName,
        CUtlBuffer *buffer,
        DiskWriteMode_t writeMode)
{
  _BYTE *v5; // eax
  _BYTE *v6; // esi
  _BYTE *v7; // eax
  char dirPath[260]; // [esp+8h] [ebp-104h] BYREF

  strcpy(dirPath, pTargetName);
  strchr(string: (unsigned __int8 *)dirPath, chr: 0x5Cu);
  v6 = v5;
  if ( v5 != nullptr )
  {
    while ( 1 )
    {
      strchr(string: v6 + 1, chr: 0x5Cu);
      v6 = v7;
      if ( v7 == nullptr )
        break;
      *v7 = 0;
      _mkdir(path: dirPath);
      *v6 = 92;
    }
  }
  return writeMode != WRITE_TO_DISK_ALWAYS
      && (writeMode != WRITE_TO_DISK_UPDATE || !this->DoesFileExist(this, a2: pTargetName))
      || g_pFullFileSystem->WriteFile(
           this: &g_pFullFileSystem->IBaseFileSystem,
           a2: pTargetName,
           a3: nullptr,
           a4: buffer);
}

//------------------------------------------------------------------------------
// Address: 0x00404170
// Name: public: virtual int CScriptLib::CompareFileTime(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CScriptLib::CompareFileTime(CScriptLib *this, const char *pFilenameA, const char *pFilenameB)
{
  unsigned int v3; // esi
  unsigned int v4; // eax
  bool v5; // cf

  v3 = g_pFullFileSystem->GetFileTime(this: &g_pFullFileSystem->IBaseFileSystem, a2: pFilenameA, a3: nullptr);
  v4 = g_pFullFileSystem->GetFileTime(this: &g_pFullFileSystem->IBaseFileSystem, a2: pFilenameB, a3: nullptr);
  if ( v3 == -1 )
    v3 = 0;
  if ( v4 == -1 )
    return v3 != 0;
  v5 = v4 < v3;
  if ( v4 <= v3 )
    return v5;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004041D0
// Name: public: virtual char __near * CScriptLib::MakeTemporaryFilename(char const __near *,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CScriptLib::MakeTemporaryFilename(CScriptLib *this, const char *pchModPath, char *pPath, int pathSize)
{
  char *v4; // eax
  char *v5; // esi

  v4 = _tempnam(dir: pchModPath, pfx: "mgd_");
  v5 = v4;
  if ( *v4 == 92 )
    v5 = v4 + 1;
  if ( v5[strlen(v5) - 1] == 46 )
    v5[strlen(v5) - 1] = 0;
  V_snprintf(pDest: pPath, maxLen: pathSize, pFormat: "%s.tmp", v5);
  free(pMem: v5);
  return pPath;
}

//------------------------------------------------------------------------------
// Address: 0x00404240
// Name: void DefineMacro(char __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DefineMacro(char *macroname)
{
  script_t *v1; // edi
  char *script_p; // esi
  char *macrobuffer; // ebx
  unsigned int v4; // ebx
  unsigned __int8 *v5; // eax
  int v6; // eax
  script_t *v7; // edx
  const char *v8; // [esp+0h] [ebp-Ch]

  v1 = (script_t *)operator new(nSize: 0x1614u);
  strcpy(v1->filename, macroname);
  v1->line = script->line;
  v1->nummacroparams = 0;
  script_p = script->script_p;
  macrobuffer = v1->macrobuffer;
  while ( TokenAvailable() != 0 )
  {
    GetToken(crossline: 0);
    if ( token[0] == 92 && byte_465571 == 92 )
      break;
    script_p = script->script_p;
    v1->macroparam[v1->nummacroparams++] = macrobuffer;
    strcpy(macrobuffer, token);
    macrobuffer += strlen(token) + 1;
    if ( macrobuffer >= (char *)v1->macroparam )
      _Error(this: (ISceneTokenProcessor *)&stru_42EDCC, a2: v8);
  }
  for ( script->script_p = script_p; *script_p != 0; ++script_p )
  {
    if ( *script_p == 10 )
      break;
    if ( *script_p == 92 && script_p[1] == 92 )
    {
      do
      {
        if ( *script_p == 10 )
          break;
        *script_p++ = 32;
      }
      while ( *script_p != 0 );
      if ( *script_p == 0 )
        break;
    }
  }
  v4 = script_p - script->script_p;
  v5 = (unsigned __int8 *)operator new(nSize: v4 + 1);
  v1->buffer = (char *)v5;
  memcpy(dst: v5, src: (unsigned __int8 *)script->script_p, count: v4);
  v1->buffer[v4] = 0;
  v1->end_p = &v1->buffer[v4];
  v6 = nummacros;
  v7 = script;
  macrolist[nummacros] = v1;
  nummacros = v6 + 1;
  v7->script_p = script_p;
}

//------------------------------------------------------------------------------
// Address: 0x00404510
// Name: bool ExpandVariableToken(char __near * __near &)
// Source: json
//------------------------------------------------------------------------------
char __usercall ExpandVariableToken@<al>(const char *a1@<edi>, char **token_p)
{
  char *script_p; // eax
  const char *v3; // edi
  _BYTE *v4; // ebx
  char v5; // al
  int v7; // esi
  char *value; // esi
  unsigned int v9; // eax
  char *v10; // edx
  _BYTE *v11; // esi
  char v12; // cl

  script_p = script->script_p;
  if ( *script_p != 36 )
    return 0;
  v3 = script_p + 1;
  v4 = script_p + 1;
  v5 = script_p[1];
  if ( v5 <= 32 )
  {
LABEL_5:
    if ( *v4 != 36 )
      return 0;
  }
  else
  {
    while ( v5 != 36 )
    {
      v5 = *++v4;
      if ( v5 <= 32 )
        goto LABEL_5;
    }
  }
  v7 = 0;
  *v4 = 0;
  if ( g_definevariable.m_Size <= 0 )
    goto LABEL_12;
  while ( V_strnicmp(s1: g_definevariable.m_Memory.m_pMemory[v7].param, s2: v3, n: v4 - v3 - 2) != 0 )
  {
    if ( ++v7 >= g_definevariable.m_Size )
      goto LABEL_12;
  }
  if ( v7 >= g_definevariable.m_Size )
LABEL_12:
    _Error(this: (ISceneTokenProcessor *)&stru_42EEBC, a2: v3, script);
  value = g_definevariable.m_Memory.m_pMemory[v7].value;
  v9 = strlen(value);
  v10 = value;
  v11 = *token_p;
  do
  {
    v12 = *v10;
    *v11++ = *v10++;
  }
  while ( v12 != 0 );
  *token_p += v9;
  script->script_p = v4 + 1;
  if ( script->script_p >= script->end_p )
    _Error(this: (ISceneTokenProcessor *)&stru_42EE00, a2: a1);
  if ( *token_p >= (char *)&nummacros )
    _Error(this: (ISceneTokenProcessor *)&stru_42EDE4, a2: scriptline);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00404720
// Name: void DefineVariable(char __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DefineVariable(char *variablename)
{
  char *v1; // eax
  char *v2; // eax
  char *v3; // ecx
  char v4; // dl
  variable_t v; // [esp+8h] [ebp-8h] BYREF

  if ( variablename != nullptr
    && (v1 = (char *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: strlen(variablename) + 1)) != nullptr )
  {
    strcpy(v1, variablename);
  }
  else
  {
    v1 = nullptr;
  }
  v.param = v1;
  GetToken(crossline: 0);
  v2 = (char *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: strlen(token) + 1);
  if ( v2 != nullptr )
  {
    v3 = v2;
    do
    {
      v4 = v3[token - v2];
      *v3++ = v4;
    }
    while ( v4 != 0 );
  }
  else
  {
    v2 = nullptr;
  }
  v.value = v2;
  CUtlVector<variable_t,CUtlMemory<variable_t,int>>::InsertBefore(
    this: &g_definevariable,
    elem: g_definevariable.m_Size,
    src: &v);
}

//------------------------------------------------------------------------------
// Address: 0x004047E0
// Name: int GetToken(int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl GetToken(int crossline)
{
  script_t *v1; // eax
  char *script_p; // ecx
  char v3; // dl
  script_t *v4; // eax
  char *v5; // ecx
  char *v6; // edx
  char v7; // cl
  char *v8; // ecx
  char v9; // dl
  script_t *v10; // eax
  char *v11; // edx
  script_t *v12; // eax
  char *line; // edx
  char v14; // cl
  char *v15; // esi
  script_t *v16; // eax
  char i; // cl
  char *v18; // esi
  char *v19; // ecx
  char *token_p; // [esp+Ch] [ebp-4h] BYREF

  if ( tokenready != 0 )
  {
LABEL_54:
    tokenready = 0;
    return 1;
  }
  else
  {
    while ( 1 )
    {
      v1 = script;
      if ( script->script_p >= script->end_p )
        return EndOfScript(crossline);
      tokenready = 0;
      while ( 1 )
      {
        while ( 1 )
        {
          if ( *v1->script_p <= 32 )
          {
            do
            {
              script_p = v1->script_p;
              if ( script_p >= v1->end_p )
                return EndOfScript(crossline);
              v3 = *script_p;
              v1->script_p = script_p + 1;
              if ( v3 == 10 )
              {
                if ( crossline == 0 )
                  _Error(this: (ISceneTokenProcessor *)&stru_42EE48, a2: scriptline);
                v4 = script;
                ++script->line;
                scriptline = (char *)v4->line;
              }
              v1 = script;
            }
            while ( *script->script_p <= 32 );
          }
          v5 = v1->script_p;
          if ( v5 >= v1->end_p )
            return EndOfScript(crossline);
          v6 = v1->script_p;
          v7 = *v5;
          if ( v7 != 59 && v7 != 35 )
          {
            if ( v7 != 47 )
              goto LABEL_30;
            if ( v6[1] != 47 )
              break;
          }
          if ( crossline == 0 )
          {
            _Error(this: (ISceneTokenProcessor *)&stru_42EE48, a2: scriptline);
            v1 = script;
          }
          if ( *v1->script_p != 10 )
          {
            do
            {
              ++v1->script_p;
              v1 = script;
              v11 = script->script_p;
              if ( v11 >= script->end_p )
                return EndOfScript(crossline);
            }
            while ( *v11 != 10 );
          }
          ++v1->script_p;
          v12 = script;
          ++script->line;
          line = (char *)v12->line;
          v1 = script;
          scriptline = line;
        }
        if ( v6[1] != 42 )
          break;
        v1->script_p += 2;
        while ( 1 )
        {
          v8 = script->script_p;
          if ( *v8 == 42 && v8[1] == 47 )
            break;
          v9 = *v8;
          script->script_p = v8 + 1;
          if ( v9 != 10 )
          {
            v10 = script;
            if ( script->script_p >= script->end_p )
              return EndOfScript(crossline);
            ++script->line;
            scriptline = (char *)v10->line;
          }
        }
        script->script_p += 2;
        v1 = script;
      }
LABEL_30:
      v14 = *v6;
      v15 = token;
      token_p = token;
      if ( v14 == 34 )
      {
        ++v1->script_p;
        v16 = script;
        for ( i = *script->script_p; i != 34; i = *v16->script_p )
        {
          *v15 = i;
          ++script->script_p;
          v16 = script;
          ++v15;
          if ( script->script_p == script->end_p )
            break;
          if ( v15 == (char *)&nummacros )
          {
            _Error(this: (ISceneTokenProcessor *)&stru_42EDE4, a2: scriptline);
            v16 = script;
          }
        }
        ++v16->script_p;
      }
      else
      {
        for ( ; v14 > 32; v14 = *script->script_p )
        {
          if ( v14 == 59 )
            break;
          if ( ExpandMacroToken(a1: (const char *)1, &token_p) != 0
            || ExpandVariableToken(a1: (const char *)1, &token_p) != 0 )
          {
            v15 = token_p;
          }
          else
          {
            v18 = token_p;
            *token_p = *script->script_p++;
            v19 = script->script_p;
            v15 = v18 + 1;
            token_p = v15;
            if ( v19 == script->end_p )
              break;
            if ( v15 == (char *)&nummacros )
              _Error(this: (ISceneTokenProcessor *)&stru_42EDE4, a2: scriptline);
          }
        }
      }
      *v15 = 0;
      if ( _V_stricmp(s1: token, s2: "$include") != 0 )
      {
        if ( _V_stricmp(s1: token, s2: "$definemacro") != 0 )
        {
          if ( _V_stricmp(s1: token, s2: "$definevariable") != 0 )
          {
            if ( AddMacroToStack(a1: (const char *)_Error, macroname: token) == 0 )
              return 1;
          }
          else
          {
            GetToken(crossline: 0);
            DefineVariable(variablename: token);
          }
        }
        else
        {
          GetToken(crossline: 0);
          DefineMacro(macroname: token);
        }
      }
      else
      {
        GetToken(crossline: 0);
        AddScriptToStack(a1: 1, filename: token, pathMode: SCRIPT_USE_ABSOLUTE_PATH);
      }
      if ( tokenready != 0 )
        goto LABEL_54;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00404DD0
// Name: private: int CScriptLib::GetFileList(char const __near *,char const __near *,class CUtlVector<struct fileList_t,class CUtlMemory<struct fileList_t,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CScriptLib::GetFileList(
        CScriptLib *this,
        const char *pDirPath,
        const char *pPattern,
        CUtlVector<CEventRelativeTag,CUtlMemory<CEventRelativeTag,int> > *fileList)
{
  unsigned int v5; // kr00_4
  int v6; // eax
  char v7; // cl
  char *v8; // edi
  char v9; // al
  unsigned int v10; // eax
  char *v11; // edi
  char v12; // cl
  int v13; // esi
  int v15; // eax
  char v16; // cl
  unsigned int v17; // eax
  char *v18; // edi
  char v19; // cl
  char *v20; // edi
  char *v21; // esi
  char v22; // cl
  int m_Size; // eax
  int v24; // esi
  char v25; // [esp+Bh] [ebp-435h] BYREF
  char fileName[260]; // [esp+Ch] [ebp-434h] BYREF
  char fullPath[260]; // [esp+110h] [ebp-330h] BYREF
  _finddata64i32_t findData; // [esp+214h] [ebp-22Ch] BYREF
  char sourcePath[260]; // [esp+33Ch] [ebp-104h] BYREF
  int h; // [esp+448h] [ebp+8h]
  char bFindDirs_3; // [esp+453h] [ebp+13h]

  CUtlVector<CEventRelativeTag,CUtlMemory<CEventRelativeTag,int>>::RemoveAll(this: fileList);
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
  v5 = strlen(sourcePath);
  if ( v5 != 0 )
  {
    if ( findData.name[v5 + 259] != 92 )
    {
      sourcePath[v5] = 92;
      sourcePath[v5 + 1] = 0;
    }
  }
  else
  {
    strcpy(sourcePath, ".\\");
  }
  v6 = 0;
  do
  {
    v7 = sourcePath[v6];
    fullPath[v6++] = v7;
  }
  while ( v7 != 0 );
  if ( *pPattern != 92 || pPattern[1] != 0 )
  {
    bFindDirs_3 = 0;
    v10 = strlen(pPattern) + 1;
    v11 = &fileName[259];
    do
      v12 = *++v11;
    while ( v12 != 0 );
    qmemcpy(v11, pPattern, v10);
  }
  else
  {
    bFindDirs_3 = 1;
    v8 = &fileName[259];
    do
      v9 = *++v8;
    while ( v9 != 0 );
    strcpy(v8, "*");
  }
  v13 = _findfirst64i32(szWild: fullPath, pfd: &findData);
  h = v13;
  if ( v13 == -1 )
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
      v15 = 0;
      do
      {
        v16 = sourcePath[v15];
        fileName[v15++] = v16;
      }
      while ( v16 != 0 );
      v17 = strlen(findData.name) + 1;
      v18 = &v25;
      do
        v19 = *++v18;
      while ( v19 != 0 );
      qmemcpy(v18, findData.name, 4 * (v17 >> 2));
      v21 = &findData.name[4 * (v17 >> 2)];
      v20 = &v18[4 * (v17 >> 2)];
      v22 = v17;
      m_Size = fileList->m_Size;
      qmemcpy(v20, v21, v22 & 3);
      v24 = CUtlVector<fileList_t,CUtlMemory<fileList_t,int>>::InsertBefore(
              this: (CUtlVector<fileList_t,CUtlMemory<fileList_t,int> > *)fileList,
              elem: m_Size);
      CUtlString::Set(this: &fileList->m_Memory.m_pMemory[v24].m_Name, pValue: fileName);
      *(_QWORD *)&fileList->m_Memory.m_pMemory[v24].m_flPercentage = findData.time_write;
      v13 = h;
    }
  }
  while ( _findnext64i32(hFile: v13, pfd: &findData) == 0 );
  _findclose(hFile: v13);
  return fileList->m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x00405090
// Name: public: virtual void CScriptLib::DeleteTemporaryFiles(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CScriptLib::DeleteTemporaryFiles(CScriptLib *this, const char *pFileMask)
{
  char *v2; // eax
  char *v3; // edx
  char v4; // cl
  unsigned int v5; // eax
  char *v6; // edi
  char v7; // cl
  int (__thiscall *FindFiles)(struct CScriptLib *, char *, bool, CUtlVector<fileList_t,CUtlMemory<fileList_t,int> > *); // edx
  int v9; // esi
  int v10; // edi
  const char *v11; // eax
  fileList_t *m_pMemory; // eax
  char v13; // [esp+3h] [ebp-11Dh] BYREF
  char tempPath[260]; // [esp+4h] [ebp-11Ch] BYREF
  CScriptLib *v15; // [esp+108h] [ebp-18h]
  CUtlVector<fileList_t,CUtlMemory<fileList_t,int> > fileList; // [esp+10Ch] [ebp-14h] BYREF

  v15 = this;
  v2 = getenv(option: "temp");
  if ( v2 != nullptr || (v2 = getenv(option: "tmp")) != nullptr )
  {
    v3 = (char *)(tempPath - v2);
    do
    {
      v4 = *v2;
      v2[(_DWORD)v3] = *v2;
      ++v2;
    }
    while ( v4 != 0 );
    V_AppendSlash(pStr: tempPath, strSize: 260);
    v5 = strlen(pFileMask) + 1;
    v6 = &v13;
    do
      v7 = *++v6;
    while ( v7 != 0 );
    qmemcpy(v6, pFileMask, v5);
    FindFiles = v15->FindFiles;
    memset(&fileList, 0, sizeof(fileList));
    FindFiles(this: v15, a2: tempPath, a3: false, a4: &fileList);
    v9 = 0;
    if ( fileList.m_Size > 0 )
    {
      v10 = 0;
      do
      {
        v11 = CUtlString::Get(this: &fileList.m_Memory.m_pMemory[v10].fileName);
        _unlink(path: v11);
        ++v9;
        ++v10;
      }
      while ( v9 < fileList.m_Size );
    }
    CUtlVector<CEventRelativeTag,CUtlMemory<CEventRelativeTag,int>>::RemoveAll(this: (CUtlVector<CEventRelativeTag,CUtlMemory<CEventRelativeTag,int> > *)&fileList);
    m_pMemory = fileList.m_Memory.m_pMemory;
    if ( fileList.m_Memory.m_nGrowSize >= 0 )
    {
      if ( fileList.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: fileList.m_Memory.m_pMemory);
        m_pMemory = nullptr;
        fileList.m_Memory.m_pMemory = nullptr;
      }
      fileList.m_Memory.m_nAllocationCount = 0;
    }
    fileList.m_pElements = m_pMemory;
    if ( fileList.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004051C0
// Name: private: void CScriptLib::RecurseFileTree_r(char const __near *,int,class CUtlVector<class CUtlString,class CUtlMemory<class CUtlString,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CScriptLib::RecurseFileTree_r(
        CScriptLib *this,
        const char *pDirPath,
        int depth,
        CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *dirList)
{
  fileList_t *i; // ebx
  int v5; // eax
  int v6; // eax
  fileList_t *m_pMemory; // edi
  const char *v8; // eax
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CUtlString *v11; // ecx
  int v12; // eax
  int v13; // edi
  CUtlString *v14; // ecx
  CUtlVector<fileList_t,CUtlMemory<fileList_t,int> > fileList; // [esp+Ch] [ebp-18h] BYREF
  CScriptLib *v16; // [esp+20h] [ebp-4h]

  i = nullptr;
  v16 = this;
  memset(&fileList, 0, sizeof(fileList));
  v5 = CScriptLib::GetFileList(
         this,
         pDirPath,
         pPattern: "\\",
         (CUtlVector<CEventRelativeTag,CUtlMemory<CEventRelativeTag,int> > *)&fileList);
  if ( v5 != 0 )
  {
    if ( v5 > 0 )
    {
      m_pMemory = fileList.m_Memory.m_pMemory;
      for ( i = (fileList_t *)v5; i != nullptr; i = (fileList_t *)((char *)i - 1) )
      {
        v8 = CUtlString::Get(this: &m_pMemory->fileName);
        CScriptLib::RecurseFileTree_r(this: v16, pDirPath: v8, depth: depth + 1, dirList);
        ++m_pMemory;
      }
    }
    m_Size = dirList->m_Size;
    m_nAllocationCount = dirList->m_Memory.m_nAllocationCount;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<CUtlString,int>::Grow(this: &dirList->m_Memory, num: m_Size - m_nAllocationCount + 1);
    ++dirList->m_Size;
    v11 = dirList->m_Memory.m_pMemory;
    v12 = dirList->m_Size - m_Size - 1;
    dirList->m_pElements = dirList->m_Memory.m_pMemory;
    if ( v12 > (int)i )
      _V_memmove(dest: &v11[m_Size + 1], src: &v11[m_Size], count: 16 * v12);
    v13 = m_Size;
    v14 = &dirList->m_Memory.m_pMemory[v13];
    if ( v14 != nullptr )
      CUtlString::CUtlString(this: v14);
    CUtlString::Set(this: &dirList->m_Memory.m_pMemory[v13], pValue: pDirPath);
    CUtlVector<CEventRelativeTag,CUtlMemory<CEventRelativeTag,int>>::RemoveAll(this: (CUtlVector<CEventRelativeTag,CUtlMemory<CEventRelativeTag,int> > *)&fileList);
    if ( fileList.m_Memory.m_nGrowSize >= (int)i && fileList.m_Memory.m_pMemory != i )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: fileList.m_Memory.m_pMemory);
  }
  else
  {
    v6 = CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>::InsertBefore(this: dirList, elem: dirList->m_Size);
    CUtlString::Set(this: &dirList->m_Memory.m_pMemory[v6], pValue: pDirPath);
    CUtlVector<CEventRelativeTag,CUtlMemory<CEventRelativeTag,int>>::~CUtlVector<CEventRelativeTag,CUtlMemory<CEventRelativeTag,int>>(this: (CUtlVector<CEventRelativeTag,CUtlMemory<CEventRelativeTag,int> > *)&fileList);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004052E0
// Name: public: virtual int CScriptLib::FindFiles(char __near *,bool,class CUtlVector<struct fileList_t,class CUtlMemory<struct fileList_t,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CScriptLib::FindFiles(
        CScriptLib *this,
        char *pFileMask,
        bool bRecurse,
        CUtlVector<fileList_t,CUtlMemory<fileList_t,int> > *fileList)
{
  CScriptLib *v4; // edi
  char *v5; // edi
  char v6; // al
  unsigned int v7; // eax
  char *v8; // edi
  char v9; // cl
  int m_nGrowSize; // esi
  fileList_t *m_pMemory; // eax
  const char *v13; // eax
  CUtlVector<fileList_t,CUtlMemory<fileList_t,int> > *v14; // esi
  int m_Size; // edi
  int inserted; // eax
  fileList_t *v17; // edi
  int v18; // ebx
  CUtlString *p_fileName; // esi
  int timeWrite_high; // eax
  bool v21; // zf
  CUtlString *v22; // eax
  unsigned int v23; // [esp-8h] [ebp-34Ch]
  char extension[260]; // [esp+8h] [ebp-33Ch] BYREF
  char dirPath[260]; // [esp+10Ch] [ebp-238h] BYREF
  char pattern[260]; // [esp+210h] [ebp-134h] BYREF
  CScriptLib *v27; // [esp+314h] [ebp-30h]
  int i; // [esp+318h] [ebp-2Ch]
  CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > dirList; // [esp+31Ch] [ebp-28h] BYREF
  CUtlVector<fileList_t,CUtlMemory<fileList_t,int> > tempList; // [esp+330h] [ebp-14h] BYREF
  char *pFileMaska; // [esp+34Ch] [ebp+8h]
  int bRecursea; // [esp+350h] [ebp+Ch]

  v4 = this;
  v27 = this;
  strcpy(dirPath, pFileMask);
  V_StripFilename(path: dirPath);
  V_FileBase(in: pFileMask, out: pattern, maxlen: 260);
  V_ExtractFileExtension(path: pFileMask, dest: extension, destSize: 260);
  if ( extension[0] != 0 )
  {
    v5 = &dirPath[259];
    do
      v6 = *++v5;
    while ( v6 != 0 );
    strcpy(v5, ".");
    v7 = strlen(extension) + 1;
    v8 = &dirPath[259];
    do
      v9 = *++v8;
    while ( v9 != 0 );
    qmemcpy(v8, extension, v7);
    v4 = v27;
  }
  if ( bRecurse )
  {
    memset(&tempList, 0, sizeof(tempList));
    memset(&dirList, 0, sizeof(dirList));
    CScriptLib::RecurseFileTree_r(this: v4, pDirPath: dirPath, depth: 0, &dirList);
    i = 0;
    if ( dirList.m_Size > 0 )
    {
      bRecursea = 0;
      while ( 1 )
      {
        CUtlVector<CEventRelativeTag,CUtlMemory<CEventRelativeTag,int>>::RemoveAll(this: (CUtlVector<CEventRelativeTag,CUtlMemory<CEventRelativeTag,int> > *)&tempList);
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
          v23 = 24 * dirList.m_Size;
          if ( m_pMemory != nullptr )
            m_pMemory = (fileList_t *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v23);
          else
            m_pMemory = (fileList_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v23);
          tempList.m_Memory.m_pMemory = m_pMemory;
        }
        tempList.m_pElements = m_pMemory;
        v13 = CUtlString::Get(this: &dirList.m_Memory.m_pMemory[bRecursea]);
        CScriptLib::GetFileList(
          this: v4,
          pDirPath: v13,
          pPattern: pattern,
          fileList: (CUtlVector<CEventRelativeTag,CUtlMemory<CEventRelativeTag,int> > *)&tempList);
        v14 = fileList;
        m_Size = tempList.m_Size;
        inserted = CUtlVector<fileList_t,CUtlMemory<fileList_t,int>>::InsertMultipleBefore(
                     this: fileList,
                     elem: fileList->m_Size,
                     num: tempList.m_Size);
        if ( m_Size > 0 )
        {
          v17 = tempList.m_Memory.m_pMemory;
          v18 = inserted;
          pFileMaska = (char *)tempList.m_Size;
          while ( 1 )
          {
            p_fileName = &v14->m_Memory.m_pMemory[v18].fileName;
            CUtlString::operator=(this: p_fileName, src: &v17->fileName);
            p_fileName[1].m_Storage.m_Memory.m_pMemory = (unsigned __int8 *)v17->timeWrite;
            timeWrite_high = HIDWORD(v17->timeWrite);
            ++v17;
            ++v18;
            v21 = pFileMaska-- == (char *)1;
            p_fileName[1].m_Storage.m_Memory.m_nAllocationCount = timeWrite_high;
            if ( v21 )
              break;
            v14 = fileList;
          }
        }
        ++bRecursea;
        if ( ++i >= dirList.m_Size )
          break;
        v4 = v27;
      }
    }
    CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>::RemoveAll(this: &dirList);
    v22 = dirList.m_Memory.m_pMemory;
    if ( dirList.m_Memory.m_nGrowSize >= 0 )
    {
      if ( dirList.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: dirList.m_Memory.m_pMemory);
        v22 = nullptr;
        dirList.m_Memory.m_pMemory = nullptr;
      }
      dirList.m_Memory.m_nAllocationCount = 0;
    }
    dirList.m_pElements = v22;
    if ( dirList.m_Memory.m_nGrowSize >= 0 )
    {
      if ( v22 != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v22);
        dirList.m_Memory.m_pMemory = nullptr;
      }
      dirList.m_Memory.m_nAllocationCount = 0;
    }
    CUtlVector<CEventRelativeTag,CUtlMemory<CEventRelativeTag,int>>::RemoveAll(this: (CUtlVector<CEventRelativeTag,CUtlMemory<CEventRelativeTag,int> > *)&tempList);
    if ( tempList.m_Memory.m_nGrowSize < 0 )
    {
      return fileList->m_Size;
    }
    else
    {
      if ( tempList.m_Memory.m_pMemory != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: tempList.m_Memory.m_pMemory);
      return fileList->m_Size;
    }
  }
  else
  {
    CScriptLib::GetFileList(
      this: v4,
      pDirPath: dirPath,
      pPattern: pattern,
      (CUtlVector<CEventRelativeTag,CUtlMemory<CEventRelativeTag,int> > *)fileList);
    return fileList->m_Size;
  }
}

} // namespace vcd_sound_check

// ============================================================
// Overlay from vmap (Missing functions)
// ============================================================
namespace vmap {

//------------------------------------------------------------------------------
// Address: 0x00457650
// Name: public: virtual bool CScriptLib::DoesFileExist(char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CScriptLib::DoesFileExist(CScriptLib *this, const char *pFilename)
{
  return g_pFullFileSystem->FileExists(this: &g_pFullFileSystem->IBaseFileSystem, a2: pFilename, a3: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x00457670
// Name: public: virtual bool CScriptLib::ReadFileToBuffer(char const __near *,class CUtlBuffer __near &,bool,bool)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CScriptLib::ReadFileToBuffer(
        CScriptLib *this,
        const char *pSourceName,
        CUtlBuffer *buffer,
        bool bText,
        bool bNoOpenFailureWarning)
{
  int *v5; // eax
  const char *v6; // eax

  if ( g_pFullFileSystem->ReadFile(
         this: &g_pFullFileSystem->IBaseFileSystem,
         a2: pSourceName,
         a3: nullptr,
         a4: buffer,
         a5: 0,
         a6: 0,
         a7: nullptr) )
  {
    if ( bText )
      CUtlBuffer::SetBufferType(this: buffer, bIsText: true, bContainsCRLF: true);
    else
      CUtlBuffer::SetBufferType(this: buffer, bIsText: false, bContainsCRLF: false);
    return 1;
  }
  else
  {
    if ( !bNoOpenFailureWarning )
    {
      v5 = _errno();
      v6 = strerror(errnum: *v5);
      _Msg(a1: "ReadFileToBuffer(): Error opening %s: %s\n", pSourceName, v6);
    }
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004576F0
// Name: public: virtual bool CScriptLib::WriteBufferToFile(char const __near *,class CUtlBuffer __near &,enum DiskWriteMode_t)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CScriptLib::WriteBufferToFile(
        CScriptLib *this,
        const char *pTargetName,
        CUtlBuffer *buffer,
        DiskWriteMode_t writeMode)
{
  _BYTE *v5; // eax
  _BYTE *v6; // esi
  _BYTE *v7; // eax
  char dirPath[260]; // [esp+8h] [ebp-104h] BYREF

  strcpy(dirPath, pTargetName);
  strchr(string: (unsigned __int8 *)dirPath, chr: 0x5Cu);
  v6 = v5;
  if ( v5 != nullptr )
  {
    while ( 1 )
    {
      strchr(string: v6 + 1, chr: 0x5Cu);
      v6 = v7;
      if ( v7 == nullptr )
        break;
      *v7 = 0;
      _mkdir(path: dirPath);
      *v6 = 92;
    }
  }
  return writeMode != WRITE_TO_DISK_ALWAYS
      && (writeMode != WRITE_TO_DISK_UPDATE || !this->DoesFileExist(this, a2: pTargetName))
      || g_pFullFileSystem->WriteFile(
           this: &g_pFullFileSystem->IBaseFileSystem,
           a2: pTargetName,
           a3: nullptr,
           a4: buffer);
}

//------------------------------------------------------------------------------
// Address: 0x004577B0
// Name: public: virtual int CScriptLib::CompareFileTime(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CScriptLib::CompareFileTime(CScriptLib *this, const char *pFilenameA, const char *pFilenameB)
{
  unsigned int v3; // esi
  unsigned int v4; // eax
  bool v5; // cf

  v3 = g_pFullFileSystem->GetFileTime(this: &g_pFullFileSystem->IBaseFileSystem, a2: pFilenameA, a3: nullptr);
  v4 = g_pFullFileSystem->GetFileTime(this: &g_pFullFileSystem->IBaseFileSystem, a2: pFilenameB, a3: nullptr);
  if ( v3 == -1 )
    v3 = 0;
  if ( v4 == -1 )
    return v3 != 0;
  v5 = v4 < v3;
  if ( v4 <= v3 )
    return v5;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00457810
// Name: public: virtual char __near * CScriptLib::MakeTemporaryFilename(char const __near *,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CScriptLib::MakeTemporaryFilename(CScriptLib *this, const char *pchModPath, char *pPath, int pathSize)
{
  char *v4; // eax
  char *v5; // esi

  v4 = _tempnam(dir: pchModPath, pfx: "mgd_");
  v5 = v4;
  if ( *v4 == 92 )
    v5 = v4 + 1;
  if ( v5[strlen(v5) - 1] == 46 )
    v5[strlen(v5) - 1] = 0;
  V_snprintf(pDest: pPath, maxLen: pathSize, pFormat: "%s.tmp", v5);
  free(pMem: v5);
  return pPath;
}

//------------------------------------------------------------------------------
// Address: 0x00457B10
// Name: private: int CScriptLib::GetFileList(char const __near *,char const __near *,class CUtlVector<struct fileList_t,class CUtlMemory<struct fileList_t,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CScriptLib::GetFileList(
        CScriptLib *this,
        const char *pDirPath,
        const char *pPattern,
        CUtlVector<fileList_t,CUtlMemory<fileList_t,int> > *fileList)
{
  unsigned int v5; // kr00_4
  int v6; // eax
  char v7; // cl
  char *v8; // edi
  char v9; // al
  unsigned int v10; // eax
  char *v11; // edi
  char v12; // cl
  int v13; // esi
  int v15; // eax
  char v16; // cl
  unsigned int v17; // eax
  char *v18; // edi
  char v19; // cl
  char *v20; // edi
  char *v21; // esi
  char v22; // cl
  int m_Size; // eax
  int v24; // esi
  char v25; // [esp+Bh] [ebp-435h] BYREF
  char fileName[260]; // [esp+Ch] [ebp-434h] BYREF
  char fullPath[260]; // [esp+110h] [ebp-330h] BYREF
  _finddata64i32_t findData; // [esp+214h] [ebp-22Ch] BYREF
  char sourcePath[260]; // [esp+33Ch] [ebp-104h] BYREF
  int h; // [esp+448h] [ebp+8h]
  char bFindDirs_3; // [esp+453h] [ebp+13h]

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
  v5 = strlen(sourcePath);
  if ( v5 != 0 )
  {
    if ( findData.name[v5 + 259] != 92 )
    {
      sourcePath[v5] = 92;
      sourcePath[v5 + 1] = 0;
    }
  }
  else
  {
    strcpy(sourcePath, ".\\");
  }
  v6 = 0;
  do
  {
    v7 = sourcePath[v6];
    fullPath[v6++] = v7;
  }
  while ( v7 != 0 );
  if ( *pPattern != 92 || pPattern[1] != 0 )
  {
    bFindDirs_3 = 0;
    v10 = strlen(pPattern) + 1;
    v11 = &fileName[259];
    do
      v12 = *++v11;
    while ( v12 != 0 );
    qmemcpy(v11, pPattern, v10);
  }
  else
  {
    bFindDirs_3 = 1;
    v8 = &fileName[259];
    do
      v9 = *++v8;
    while ( v9 != 0 );
    strcpy(v8, "*");
  }
  v13 = _findfirst64i32(szWild: fullPath, pfd: &findData);
  h = v13;
  if ( v13 == -1 )
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
    if ( _V_stricmp(s1: findData.name, s2: ".") != 0 && _V_stricmp(s1: findData.name, s2: asc_6C5720) != 0 )
    {
      v15 = 0;
      do
      {
        v16 = sourcePath[v15];
        fileName[v15++] = v16;
      }
      while ( v16 != 0 );
      v17 = strlen(findData.name) + 1;
      v18 = &v25;
      do
        v19 = *++v18;
      while ( v19 != 0 );
      qmemcpy(v18, findData.name, 4 * (v17 >> 2));
      v21 = &findData.name[4 * (v17 >> 2)];
      v20 = &v18[4 * (v17 >> 2)];
      v22 = v17;
      m_Size = fileList->m_Size;
      qmemcpy(v20, v21, v22 & 3);
      v24 = CUtlVector<fileList_t,CUtlMemory<fileList_t,int>>::InsertBefore(this: fileList, elem: m_Size);
      CUtlString::Set(this: &fileList->m_Memory.m_pMemory[v24].fileName, pValue: fileName);
      fileList->m_Memory.m_pMemory[v24].timeWrite = findData.time_write;
      v13 = h;
    }
  }
  while ( _findnext64i32(hFile: v13, pfd: &findData) == 0 );
  _findclose(hFile: v13);
  return fileList->m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x00457DD0
// Name: public: virtual void CScriptLib::DeleteTemporaryFiles(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CScriptLib::DeleteTemporaryFiles(CScriptLib *this, const char *pFileMask)
{
  char *v2; // eax
  char *v3; // edx
  char v4; // cl
  unsigned int v5; // eax
  char *v6; // edi
  char v7; // cl
  int (__thiscall *FindFiles)(struct CScriptLib *, char *, bool, CUtlVector<fileList_t,CUtlMemory<fileList_t,int> > *); // edx
  int v9; // esi
  int v10; // edi
  const char *v11; // eax
  fileList_t *m_pMemory; // eax
  char v13; // [esp+3h] [ebp-11Dh] BYREF
  char tempPath[260]; // [esp+4h] [ebp-11Ch] BYREF
  CScriptLib *v15; // [esp+108h] [ebp-18h]
  CUtlVector<fileList_t,CUtlMemory<fileList_t,int> > fileList; // [esp+10Ch] [ebp-14h] BYREF

  v15 = this;
  v2 = getenv(option: "temp");
  if ( v2 != nullptr || (v2 = getenv(option: "tmp")) != nullptr )
  {
    v3 = (char *)(tempPath - v2);
    do
    {
      v4 = *v2;
      v2[(_DWORD)v3] = *v2;
      ++v2;
    }
    while ( v4 != 0 );
    V_AppendSlash(pStr: tempPath, strSize: 260);
    v5 = strlen(pFileMask) + 1;
    v6 = &v13;
    do
      v7 = *++v6;
    while ( v7 != 0 );
    qmemcpy(v6, pFileMask, v5);
    FindFiles = v15->FindFiles;
    memset(&fileList, 0, sizeof(fileList));
    FindFiles(this: v15, a2: tempPath, a3: false, a4: &fileList);
    v9 = 0;
    if ( fileList.m_Size > 0 )
    {
      v10 = 0;
      do
      {
        v11 = CUtlString::operator char const *(this: &fileList.m_Memory.m_pMemory[v10].fileName);
        _unlink(path: v11);
        ++v9;
        ++v10;
      }
      while ( v9 < fileList.m_Size );
    }
    CUtlVector<fileList_t,CUtlMemory<fileList_t,int>>::RemoveAll(this: &fileList);
    m_pMemory = fileList.m_Memory.m_pMemory;
    if ( fileList.m_Memory.m_nGrowSize >= 0 )
    {
      if ( fileList.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: fileList.m_Memory.m_pMemory);
        m_pMemory = nullptr;
        fileList.m_Memory.m_pMemory = nullptr;
      }
      fileList.m_Memory.m_nAllocationCount = 0;
    }
    fileList.m_pElements = m_pMemory;
    if ( fileList.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00457F00
// Name: private: void CScriptLib::RecurseFileTree_r(char const __near *,int,class CUtlVector<class CUtlString,class CUtlMemory<class CUtlString,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CScriptLib::RecurseFileTree_r(
        CScriptLib *this,
        const char *pDirPath,
        int depth,
        CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *dirList)
{
  fileList_t *i; // ebx
  int v5; // eax
  int v6; // eax
  fileList_t *m_pMemory; // edi
  const char *v8; // eax
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CUtlString *v11; // ecx
  int v12; // eax
  int v13; // edi
  CUtlString *v14; // ecx
  CUtlVector<fileList_t,CUtlMemory<fileList_t,int> > fileList; // [esp+Ch] [ebp-18h] BYREF
  CScriptLib *v16; // [esp+20h] [ebp-4h]

  i = nullptr;
  v16 = this;
  memset(&fileList, 0, sizeof(fileList));
  v5 = CScriptLib::GetFileList(this, pDirPath, pPattern: "\\", &fileList);
  if ( v5 != 0 )
  {
    if ( v5 > 0 )
    {
      m_pMemory = fileList.m_Memory.m_pMemory;
      for ( i = (fileList_t *)v5; i != nullptr; i = (fileList_t *)((char *)i - 1) )
      {
        v8 = CUtlString::operator char const *(this: &m_pMemory->fileName);
        CScriptLib::RecurseFileTree_r(this: v16, pDirPath: v8, depth: depth + 1, dirList);
        ++m_pMemory;
      }
    }
    m_Size = dirList->m_Size;
    m_nAllocationCount = dirList->m_Memory.m_nAllocationCount;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<ActiveLayer_t<QAngle>,int>::Grow(
        this: (CUtlMemory<ActiveLayer_t<CUtlSymbolLarge>,int> *)dirList,
        num: m_Size - m_nAllocationCount + 1);
    ++dirList->m_Size;
    v11 = dirList->m_Memory.m_pMemory;
    v12 = dirList->m_Size - m_Size - 1;
    dirList->m_pElements = dirList->m_Memory.m_pMemory;
    if ( v12 > (int)i )
      _V_memmove(dest: &v11[m_Size + 1], src: &v11[m_Size], count: 16 * v12);
    v13 = m_Size;
    v14 = &dirList->m_Memory.m_pMemory[v13];
    if ( v14 != nullptr )
      CUtlString::CUtlString(this: v14);
    CUtlString::Set(this: &dirList->m_Memory.m_pMemory[v13], pValue: pDirPath);
    CUtlVector<fileList_t,CUtlMemory<fileList_t,int>>::RemoveAll(this: &fileList);
    if ( fileList.m_Memory.m_nGrowSize >= (int)i && fileList.m_Memory.m_pMemory != i )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: fileList.m_Memory.m_pMemory);
  }
  else
  {
    v6 = CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>::InsertBefore(this: dirList, elem: dirList->m_Size);
    CUtlString::Set(this: &dirList->m_Memory.m_pMemory[v6], pValue: pDirPath);
    CUtlVector<fileList_t,CUtlMemory<fileList_t,int>>::~CUtlVector<fileList_t,CUtlMemory<fileList_t,int>>(this: &fileList);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00458020
// Name: public: virtual int CScriptLib::FindFiles(char __near *,bool,class CUtlVector<struct fileList_t,class CUtlMemory<struct fileList_t,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CScriptLib::FindFiles(
        CScriptLib *this,
        char *pFileMask,
        bool bRecurse,
        CUtlVector<fileList_t,CUtlMemory<fileList_t,int> > *fileList)
{
  CScriptLib *v4; // edi
  char *v5; // edi
  char v6; // al
  unsigned int v7; // eax
  char *v8; // edi
  char v9; // cl
  int m_nGrowSize; // esi
  fileList_t *m_pMemory; // eax
  const char *v13; // eax
  CUtlVector<fileList_t,CUtlMemory<fileList_t,int> > *v14; // esi
  int m_Size; // edi
  int inserted; // eax
  fileList_t *v17; // edi
  int v18; // ebx
  CUtlString *p_fileName; // esi
  int timeWrite_high; // eax
  bool v21; // zf
  CUtlString *v22; // eax
  unsigned int v23; // [esp-8h] [ebp-34Ch]
  char extension[260]; // [esp+8h] [ebp-33Ch] BYREF
  char dirPath[260]; // [esp+10Ch] [ebp-238h] BYREF
  char pattern[260]; // [esp+210h] [ebp-134h] BYREF
  CScriptLib *v27; // [esp+314h] [ebp-30h]
  int i; // [esp+318h] [ebp-2Ch]
  CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > dirList; // [esp+31Ch] [ebp-28h] BYREF
  CUtlVector<fileList_t,CUtlMemory<fileList_t,int> > tempList; // [esp+330h] [ebp-14h] BYREF
  char *pFileMaska; // [esp+34Ch] [ebp+8h]
  int bRecursea; // [esp+350h] [ebp+Ch]

  v4 = this;
  v27 = this;
  strcpy(dirPath, pFileMask);
  V_StripFilename(path: dirPath);
  V_FileBase(in: pFileMask, out: pattern, maxlen: 260);
  V_ExtractFileExtension(path: pFileMask, dest: extension, destSize: 260);
  if ( extension[0] != 0 )
  {
    v5 = &dirPath[259];
    do
      v6 = *++v5;
    while ( v6 != 0 );
    strcpy(v5, ".");
    v7 = strlen(extension) + 1;
    v8 = &dirPath[259];
    do
      v9 = *++v8;
    while ( v9 != 0 );
    qmemcpy(v8, extension, v7);
    v4 = v27;
  }
  if ( bRecurse )
  {
    memset(&tempList, 0, sizeof(tempList));
    memset(&dirList, 0, sizeof(dirList));
    CScriptLib::RecurseFileTree_r(this: v4, pDirPath: dirPath, depth: 0, &dirList);
    i = 0;
    if ( dirList.m_Size > 0 )
    {
      bRecursea = 0;
      while ( 1 )
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
          v23 = 24 * dirList.m_Size;
          if ( m_pMemory != nullptr )
            m_pMemory = (fileList_t *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v23);
          else
            m_pMemory = (fileList_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v23);
          tempList.m_Memory.m_pMemory = m_pMemory;
        }
        tempList.m_pElements = m_pMemory;
        v13 = CUtlString::operator char const *(this: &dirList.m_Memory.m_pMemory[bRecursea]);
        CScriptLib::GetFileList(this: v4, pDirPath: v13, pPattern: pattern, fileList: &tempList);
        v14 = fileList;
        m_Size = tempList.m_Size;
        inserted = CUtlVector<fileList_t,CUtlMemory<fileList_t,int>>::InsertMultipleBefore(
                     this: fileList,
                     elem: fileList->m_Size,
                     num: tempList.m_Size);
        if ( m_Size > 0 )
        {
          v17 = tempList.m_Memory.m_pMemory;
          v18 = inserted;
          pFileMaska = (char *)tempList.m_Size;
          while ( 1 )
          {
            p_fileName = &v14->m_Memory.m_pMemory[v18].fileName;
            CUtlString::operator=(this: p_fileName, src: &v17->fileName);
            p_fileName[1].m_Storage.m_Memory.m_pMemory = (unsigned __int8 *)v17->timeWrite;
            timeWrite_high = HIDWORD(v17->timeWrite);
            ++v17;
            ++v18;
            v21 = pFileMaska-- == (char *)1;
            p_fileName[1].m_Storage.m_Memory.m_nAllocationCount = timeWrite_high;
            if ( v21 )
              break;
            v14 = fileList;
          }
        }
        ++bRecursea;
        if ( ++i >= dirList.m_Size )
          break;
        v4 = v27;
      }
    }
    CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::RemoveAll(this: (CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int> > *)&dirList);
    v22 = dirList.m_Memory.m_pMemory;
    if ( dirList.m_Memory.m_nGrowSize >= 0 )
    {
      if ( dirList.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: dirList.m_Memory.m_pMemory);
        v22 = nullptr;
        dirList.m_Memory.m_pMemory = nullptr;
      }
      dirList.m_Memory.m_nAllocationCount = 0;
    }
    dirList.m_pElements = v22;
    if ( dirList.m_Memory.m_nGrowSize >= 0 )
    {
      if ( v22 != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v22);
        dirList.m_Memory.m_pMemory = nullptr;
      }
      dirList.m_Memory.m_nAllocationCount = 0;
    }
    CUtlVector<fileList_t,CUtlMemory<fileList_t,int>>::RemoveAll(this: &tempList);
    if ( tempList.m_Memory.m_nGrowSize < 0 )
    {
      return fileList->m_Size;
    }
    else
    {
      if ( tempList.m_Memory.m_pMemory != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: tempList.m_Memory.m_pMemory);
      return fileList->m_Size;
    }
  }
  else
  {
    CScriptLib::GetFileList(this: v4, pDirPath: dirPath, pPattern: pattern, fileList);
    return fileList->m_Size;
  }
}

} // namespace vmap

// ============================================================
// Overlay from vrad_dll (Missing functions)
// ============================================================
namespace vrad_dll {

//------------------------------------------------------------------------------
// Address: 0x10001180
// Name: public: void CUtlMemory<struct UtlLinkedListElem_t<unsigned short,unsigned short>,unsigned short>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<UtlLinkedListElem_t<unsigned short,unsigned short>,unsigned short>::Grow(
        CUtlMemory<UtlLinkedListElem_t<unsigned short,unsigned short>,unsigned short> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  UtlLinkedListElem_t<unsigned short,unsigned short> *m_pMemory; // edx
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
        m_nAllocationCount = 6;
      for ( ; m_nAllocationCount < v5; m_nAllocationCount *= 2 )
        ;
    }
    if ( (unsigned __int16)m_nAllocationCount < v5 )
    {
      if ( (_WORD)m_nAllocationCount != 0 || v5 > 0xFFFF )
      {
        if ( (unsigned __int16)v5 != v5 )
          return;
        do
          m_nAllocationCount = (v5 + m_nAllocationCount) / 2;
        while ( (unsigned __int16)m_nAllocationCount < v5 );
      }
      else
      {
        --m_nAllocationCount;
      }
    }
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    v7 = 6 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (UtlLinkedListElem_t<unsigned short,unsigned short> *)_g_pMemAlloc->Realloc_2(
                                                                                this: _g_pMemAlloc,
                                                                                a2: m_pMemory,
                                                                                a3: v7);
    else
      this->m_pMemory = (UtlLinkedListElem_t<unsigned short,unsigned short> *)_g_pMemAlloc->Alloc_2(
                                                                                this: _g_pMemAlloc,
                                                                                a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10004E20
// Name: public: void CUtlMemory<struct UtlLinkedListElem_t<class CIncLight __near *,unsigned short>,unsigned short>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<UtlLinkedListElem_t<CIncLight *,unsigned short>,unsigned short>::Grow(
        CUtlMemory<UtlLinkedListElem_t<CUtlVector<char,CUtlMemory<char,int> > *,unsigned short>,unsigned short> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  UtlLinkedListElem_t<CUtlVector<char,CUtlMemory<char,int> > *,unsigned short> *m_pMemory; // edx
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
      for ( ; m_nAllocationCount < v5; m_nAllocationCount *= 2 )
        ;
    }
    if ( (unsigned __int16)m_nAllocationCount < v5 )
    {
      if ( (_WORD)m_nAllocationCount != 0 || v5 > 0xFFFF )
      {
        if ( (unsigned __int16)v5 != v5 )
          return;
        do
          m_nAllocationCount = (v5 + m_nAllocationCount) / 2;
        while ( (unsigned __int16)m_nAllocationCount < v5 );
      }
      else
      {
        --m_nAllocationCount;
      }
    }
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    v7 = 8 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (UtlLinkedListElem_t<CUtlVector<char,CUtlMemory<char,int> > *,unsigned short> *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (UtlLinkedListElem_t<CUtlVector<char,CUtlMemory<char,int> > *,unsigned short> *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10005300
// Name: public: int CUtlVector<unsigned short,class CUtlMemory<unsigned short,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<unsigned short,CUtlMemory<unsigned short,int>>::InsertMultipleBefore(
        CUtlVector<CIncrementalHeader::CLMSize,CUtlMemory<CIncrementalHeader::CLMSize,int> > *this,
        int elem,
        int num)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CIncrementalHeader::CLMSize *m_pMemory; // ecx
  int v8; // eax
  int v9; // eax

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<CIncrementalHeader::CLMSize,int>::Grow(
      (CUtlMemory<CBSPTreeData::Leaf_t,int> *)this,
      num: num + m_Size - m_nAllocationCount);
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
// Address: 0x10005480
// Name: public: int CUtlVector<struct ClusterDispList_t,class CUtlMemory<struct ClusterDispList_t,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<ClusterDispList_t,CUtlMemory<ClusterDispList_t,int>>::InsertMultipleBefore(
        CUtlVector<CUtlVector<CLightFace *,CUtlMemory<CLightFace *,int> >,CUtlMemory<CUtlVector<CLightFace *,CUtlMemory<CLightFace *,int> >,int> > *this,
        int elem,
        int num)
{
  int v3; // edi
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CUtlVector<CLightFace *,CUtlMemory<CLightFace *,int> > *m_pMemory; // ecx
  int v9; // eax
  int v10; // ecx
  CUtlVector<CLightFace *,CUtlMemory<CLightFace *,int> > *v11; // eax

  v3 = num;
  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<UtlRBTreeNode_t<float,int>,int>::Grow(this: &this->m_Memory, num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v9 = this->m_Size - elem - num;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v9 <= 0 )
    goto LABEL_8;
  if ( num > 0 )
  {
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 20 * v9);
LABEL_8:
    if ( num > 0 )
    {
      v10 = elem;
      do
      {
        v11 = &this->m_Memory.m_pMemory[v10];
        if ( v11 != nullptr )
        {
          v11->m_Memory.m_pMemory = nullptr;
          v11->m_Memory.m_nAllocationCount = 0;
          v11->m_Memory.m_nGrowSize = 0;
          v11->m_Size = 0;
          v11->m_pElements = nullptr;
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
// Address: 0x10005950
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
      CUtlMemory<char,int>::Grow(this: &this->m_Memory, num: size - m_nAllocationCount);
    this->m_Size += size;
    m_pMemory = this->m_Memory.m_pMemory;
    v5 = this->m_Size - size;
    this->m_pElements = this->m_Memory.m_pMemory;
    if ( v5 > 0 && size > 0 )
      _V_memmove(dest: &m_pMemory[size], src: m_pMemory, count: v5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10007E30
// Name: public: void CUtlMemory<struct ambientsample_t,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<ambientsample_t,int>::Grow(CUtlMemory<ambientsample_t,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  ambientsample_t *m_pMemory; // edx
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
    v7 = 84 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (ambientsample_t *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (ambientsample_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100085C0
// Name: public: int CUtlVector<struct dplane_t,class CUtlMemory<struct dplane_t,int>>::InsertBefore(int,struct dplane_t const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<dplane_t,CUtlMemory<dplane_t,int>>::InsertBefore(
        CUtlVector<dplane_t,CUtlMemory<dplane_t,int> > *this,
        int elem,
        const dplane_t *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  dplane_t *m_pMemory; // ecx
  int v7; // eax
  dplane_t *v8; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<UtlRBTreeNode_t<float,int>,int>::Grow(
      (CUtlMemory<CUtlVector<CLightFace *,CUtlMemory<CLightFace *,int> >,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 20 * v7);
  v8 = &this->m_Memory.m_pMemory[elem];
  if ( v8 != nullptr )
    *v8 = *src;
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x10008640
// Name: public: int CUtlVector<struct ambientsample_t,class CUtlMemory<struct ambientsample_t,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<ambientsample_t,CUtlMemory<ambientsample_t,int>>::InsertMultipleBefore(
        CUtlVector<ambientsample_t,CUtlMemory<ambientsample_t,int> > *this,
        int elem,
        int num)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  ambientsample_t *m_pMemory; // ecx
  int v8; // eax
  int v9; // eax

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<ambientsample_t,int>::Grow(this: &this->m_Memory, num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v8 = this->m_Size;
  this->m_pElements = this->m_Memory.m_pMemory;
  v9 = v8 - elem - num;
  if ( v9 > 0 && num > 0 )
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 84 * v9);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x10008FC0
// Name: public: void CUtlVector<struct ClusterDispList_t,class CUtlMemory<struct ClusterDispList_t,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<ClusterDispList_t,CUtlMemory<ClusterDispList_t,int>>::RemoveAll(
        CUtlVector<CUtlVector<CLightFace *,CUtlMemory<CLightFace *,int> >,CUtlMemory<CUtlVector<CLightFace *,CUtlMemory<CLightFace *,int> >,int> > *this)
{
  int v1; // ebx
  int v2; // eax
  char *v3; // esi
  void *v4; // eax
  int v5; // [esp+4h] [ebp-8h]
  CUtlVector<CUtlVector<CLightFace *,CUtlMemory<CLightFace *,int> >,CUtlMemory<CUtlVector<CLightFace *,CUtlMemory<CLightFace *,int> >,int> > *v6; // [esp+8h] [ebp-4h]

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
// Address: 0x10009250
// Name: public: CUtlVector<struct ClusterDispList_t,class CUtlMemory<struct ClusterDispList_t,int>>::~CUtlVector<struct ClusterDispList_t,class CUtlMemory<struct ClusterDispList_t,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<ClusterDispList_t,CUtlMemory<ClusterDispList_t,int>>::~CUtlVector<ClusterDispList_t,CUtlMemory<ClusterDispList_t,int>>(
        CUtlVector<CUtlVector<ambientsample_t,CUtlMemory<ambientsample_t,int> >,CUtlMemory<CUtlVector<ambientsample_t,CUtlMemory<ambientsample_t,int> >,int> > *this)
{
  bool v2; // sf
  CUtlVector<ambientsample_t,CUtlMemory<ambientsample_t,int> > *m_pMemory; // eax

  CUtlVector<ClusterDispList_t,CUtlMemory<ClusterDispList_t,int>>::RemoveAll((CUtlVector<CUtlVector<CLightFace *,CUtlMemory<CLightFace *,int> >,CUtlMemory<CUtlVector<CLightFace *,CUtlMemory<CLightFace *,int> >,int> > *)this);
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
// Address: 0x10011140
// Name: public: void CUtlVector<class CLightValue,class CUtlMemory<class CLightValue,int>>::Purge(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CLightValue,CUtlMemory<CLightValue,int>>::Purge(
        CUtlVector<unsigned char,CUtlMemory<unsigned char,int> > *this)
{
  bool v2; // sf
  unsigned __int8 *m_pMemory; // ecx

  v2 = this->m_Memory.m_nGrowSize < 0;
  this->m_Size = 0;
  if ( v2 )
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
// Address: 0x10012ED0
// Name: public: int CUtlVector<char,class CUtlMemory<char,int>>::InsertMultipleBefore(int,int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<char,CUtlMemory<char,int>>::InsertMultipleBefore(
        CUtlVector<char,CUtlMemory<char,int> > *this,
        int elem,
        int num,
        const char *pToInsert)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  char *m_pMemory; // ecx
  int v9; // eax
  int i; // ecx
  char *v11; // eax

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<char,int>::Grow((CUtlMemory<unsigned char,int> *)this, num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v9 = this->m_Size - elem - num;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v9 > 0 && num > 0 )
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: v9);
  if ( pToInsert != nullptr )
  {
    for ( i = 0; i < num; ++i )
    {
      v11 = &this->m_Memory.m_pMemory[i + elem];
      if ( v11 != nullptr )
        *v11 = pToInsert[i];
    }
  }
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x100146B0
// Name: public: void CUtlVector<unsigned char,class CUtlMemory<unsigned char,int>>::EnsureCount(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<unsigned char,CUtlMemory<unsigned char,int>>::EnsureCount(
        CUtlVector<unsigned char,CUtlMemory<unsigned char,int> > *this,
        int num)
{
  int m_Size; // eax
  int v4; // edi
  int v5; // ebx
  int m_nAllocationCount; // eax
  unsigned __int8 *m_pMemory; // ecx
  int v8; // eax

  m_Size = this->m_Size;
  if ( m_Size < num )
  {
    v4 = num - m_Size;
    v5 = this->m_Size;
    if ( num != m_Size )
    {
      m_nAllocationCount = this->m_Memory.m_nAllocationCount;
      if ( v5 + v4 > m_nAllocationCount )
        CUtlMemory<char,int>::Grow(this: &this->m_Memory, num: v4 + v5 - m_nAllocationCount);
      this->m_Size += v4;
      m_pMemory = this->m_Memory.m_pMemory;
      v8 = this->m_Size - v5 - v4;
      this->m_pElements = this->m_Memory.m_pMemory;
      if ( v8 > 0 && v4 > 0 )
        _V_memmove(dest: &m_pMemory[v5 + v4], src: &m_pMemory[v5], count: v8);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10014A40
// Name: public: void CUtlVector<char,class CUtlMemory<char,int>>::CopyArray(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<char,CUtlMemory<char,int>>::CopyArray(
        CUtlVector<unsigned char,CUtlMemory<unsigned char,int> > *this,
        const unsigned __int8 *pArray,
        int size)
{
  int m_nAllocationCount; // eax
  unsigned __int8 *m_pMemory; // ecx
  int v6; // eax
  int i; // eax

  this->m_Size = 0;
  if ( size != 0 )
  {
    m_nAllocationCount = this->m_Memory.m_nAllocationCount;
    if ( size > m_nAllocationCount )
      CUtlMemory<char,int>::Grow(this: &this->m_Memory, num: size - m_nAllocationCount);
    this->m_Size += size;
    m_pMemory = this->m_Memory.m_pMemory;
    v6 = this->m_Size - size;
    this->m_pElements = this->m_Memory.m_pMemory;
    if ( v6 > 0 && size > 0 )
      _V_memmove(dest: &m_pMemory[size], src: m_pMemory, count: v6);
  }
  for ( i = 0; i < size; ++i )
    this->m_Memory.m_pMemory[i] = pArray[i];
}

//------------------------------------------------------------------------------
// Address: 0x10018A20
// Name: public: void CUtlMemory<struct UtlRBTreeNode_t<float,int>,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<UtlRBTreeNode_t<float,int>,int>::Grow(
        CUtlMemory<CUtlVector<CLightFace *,CUtlMemory<CLightFace *,int> >,int> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  CUtlVector<CLightFace *,CUtlMemory<CLightFace *,int> > *m_pMemory; // edx
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
      this->m_pMemory = (CUtlVector<CLightFace *,CUtlMemory<CLightFace *,int> > *)_g_pMemAlloc->Realloc_2(
                                                                                    this: _g_pMemAlloc,
                                                                                    a2: m_pMemory,
                                                                                    a3: v7);
    else
      this->m_pMemory = (CUtlVector<CLightFace *,CUtlMemory<CLightFace *,int> > *)_g_pMemAlloc->Alloc_2(
                                                                                    this: _g_pMemAlloc,
                                                                                    a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10018D40
// Name: public: int CUtlVector<struct PatchSampleData_t,class CUtlMemory<struct PatchSampleData_t,int>>::InsertBefore(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<PatchSampleData_t,CUtlMemory<PatchSampleData_t,int>>::InsertBefore(
        CUtlVector<PatchSampleData_t,CUtlMemory<PatchSampleData_t,int> > *this,
        int elem)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  PatchSampleData_t *m_pMemory; // ecx
  int v6; // eax
  PatchSampleData_t *v7; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CVradStaticPropMgr::MeshData_t,int>::Grow(
      (CUtlMemory<dleafambientlighting_t,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v6 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 28 * v6);
  v7 = &this->m_Memory.m_pMemory[elem];
  if ( v7 != nullptr )
  {
    v7->m_ndxPatches.m_Memory.m_pMemory = nullptr;
    v7->m_ndxPatches.m_Memory.m_nAllocationCount = 0;
    v7->m_ndxPatches.m_Memory.m_nGrowSize = 0;
    v7->m_ndxPatches.m_Size = 0;
    v7->m_ndxPatches.m_pElements = nullptr;
  }
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x10018DD0
// Name: public: void CUtlVector<struct PatchSampleData_t,class CUtlMemory<struct PatchSampleData_t,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<PatchSampleData_t,CUtlMemory<PatchSampleData_t,int>>::RemoveAll(
        CUtlVector<PatchSampleData_t,CUtlMemory<PatchSampleData_t,int> > *this)
{
  int v1; // ebx
  int v2; // edx
  char *v3; // esi
  void *v4; // eax
  CUtlVector<PatchSampleData_t,CUtlMemory<PatchSampleData_t,int> > *v5; // [esp+4h] [ebp-8h]
  int v6; // [esp+8h] [ebp-4h]

  v1 = this->m_Size - 1;
  v5 = this;
  if ( v1 < 0 )
  {
    this->m_Size = 0;
  }
  else
  {
    v2 = 28 * v1;
    v6 = 28 * v1;
    do
    {
      v3 = (char *)this->m_Memory.m_pMemory + v2;
      *((_DWORD *)v3 + 5) = 0;
      if ( *((int *)v3 + 4) >= 0 )
      {
        if ( *((_DWORD *)v3 + 2) != 0 )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *((void **)v3 + 2));
          v2 = v6;
          this = v5;
          *((_DWORD *)v3 + 2) = 0;
        }
        *((_DWORD *)v3 + 3) = 0;
      }
      v4 = *((void **)v3 + 2);
      *((_DWORD *)v3 + 6) = v4;
      if ( *((int *)v3 + 4) >= 0 )
      {
        if ( v4 != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v4);
          v2 = v6;
          this = v5;
          *((_DWORD *)v3 + 2) = 0;
        }
        *((_DWORD *)v3 + 3) = 0;
      }
      --v1;
      v2 -= 28;
      v6 = v2;
    }
    while ( v1 >= 0 );
    this->m_Size = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10019390
// Name: public: void CUtlVector<class CUtlVector<struct PatchSampleData_t,class CUtlMemory<struct PatchSampleData_t,int>>,class CUtlMemory<class CUtlVector<struct PatchSampleData_t,class CUtlMemory<struct PatchSampleData_t,int>>,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CUtlVector<PatchSampleData_t,CUtlMemory<PatchSampleData_t,int>>,CUtlMemory<CUtlVector<PatchSampleData_t,CUtlMemory<PatchSampleData_t,int>>,int>>::RemoveAll(
        CUtlVector<CUtlVector<PatchSampleData_t,CUtlMemory<PatchSampleData_t,int> >,CUtlMemory<CUtlVector<PatchSampleData_t,CUtlMemory<PatchSampleData_t,int> >,int> > *this)
{
  int v1; // edi
  int v2; // eax
  CUtlVector<PatchSampleData_t,CUtlMemory<PatchSampleData_t,int> > *v3; // esi
  PatchSampleData_t *m_pMemory; // eax
  CUtlVector<CUtlVector<PatchSampleData_t,CUtlMemory<PatchSampleData_t,int> >,CUtlMemory<CUtlVector<PatchSampleData_t,CUtlMemory<PatchSampleData_t,int> >,int> > *v5; // [esp+4h] [ebp-8h]
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
      v3 = (CUtlVector<PatchSampleData_t,CUtlMemory<PatchSampleData_t,int> > *)((char *)this->m_Memory.m_pMemory + v2);
      CUtlVector<PatchSampleData_t,CUtlMemory<PatchSampleData_t,int>>::RemoveAll(this: v3);
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
// Address: 0x10019430
// Name: public: CUtlVector<class CUtlVector<struct PatchSampleData_t,class CUtlMemory<struct PatchSampleData_t,int>>,class CUtlMemory<class CUtlVector<struct PatchSampleData_t,class CUtlMemory<struct PatchSampleData_t,int>>,int>>::~CUtlVector<class CUtlVector<struct PatchSampleData_t,class CUtlMemory<struct PatchSampleData_t,int>>,class CUtlMemory<class CUtlVector<struct PatchSampleData_t,class CUtlMemory<struct PatchSampleData_t,int>>,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CUtlVector<PatchSampleData_t,CUtlMemory<PatchSampleData_t,int>>,CUtlMemory<CUtlVector<PatchSampleData_t,CUtlMemory<PatchSampleData_t,int>>,int>>::~CUtlVector<CUtlVector<PatchSampleData_t,CUtlMemory<PatchSampleData_t,int>>,CUtlMemory<CUtlVector<PatchSampleData_t,CUtlMemory<PatchSampleData_t,int>>,int>>(
        CUtlVector<CUtlVector<PatchSampleData_t,CUtlMemory<PatchSampleData_t,int> >,CUtlMemory<CUtlVector<PatchSampleData_t,CUtlMemory<PatchSampleData_t,int> >,int> > *this)
{
  bool v2; // sf
  CUtlVector<PatchSampleData_t,CUtlMemory<PatchSampleData_t,int> > *m_pMemory; // eax

  CUtlVector<CUtlVector<PatchSampleData_t,CUtlMemory<PatchSampleData_t,int>>,CUtlMemory<CUtlVector<PatchSampleData_t,CUtlMemory<PatchSampleData_t,int>>,int>>::RemoveAll(this);
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
// Address: 0x1001DD70
// Name: public: void CUtlMemory<struct bumplights_t,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<bumplights_t,int>::Grow(CUtlMemory<bumplights_t,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  bumplights_t *m_pMemory; // edx
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
    v7 = 48 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (bumplights_t *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (bumplights_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001E0C0
// Name: public: void CUtlMemory<struct CPatch,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<CPatch,int>::Grow(CUtlMemory<CPatch,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  CPatch *m_pMemory; // edx
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
    v7 = 264 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (CPatch *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (CPatch *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001F7F0
// Name: public: int CUtlVector<struct bumplights_t,class CUtlMemory<struct bumplights_t,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<bumplights_t,CUtlMemory<bumplights_t,int>>::InsertMultipleBefore(
        CUtlVector<bumplights_t,CUtlMemory<bumplights_t,int> > *this,
        int elem,
        int num)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  bumplights_t *m_pMemory; // ecx
  int v8; // eax
  int v9; // eax

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<bumplights_t,int>::Grow(this: &this->m_Memory, num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v8 = this->m_Size;
  this->m_pElements = this->m_Memory.m_pMemory;
  v9 = v8 - elem - num;
  if ( v9 > 0 && num > 0 )
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 48 * v9);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x1001FA40
// Name: public: int CUtlVector<struct CPatch,class CUtlMemory<struct CPatch,int>>::AddToTail(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CPatch,CUtlMemory<CPatch,int>>::AddToTail(CUtlVector<CPatch,CUtlMemory<CPatch,int> > *this)
{
  int m_nAllocationCount; // eax
  int m_Size; // edi
  CPatch *m_pMemory; // ecx
  int v5; // eax

  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  m_Size = this->m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CPatch,int>::Grow(this: &this->m_Memory, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v5 = this->m_Size - m_Size - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v5 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 264 * v5);
  return m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x10021E20
// Name: public: void CUtlMemory<struct CacheOptimizedKDNode,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<CacheOptimizedKDNode,int>::Grow(CUtlMemory<ResourceEntryInfo,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  ResourceEntryInfo *m_pMemory; // edx
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
      this->m_pMemory = (ResourceEntryInfo *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (ResourceEntryInfo *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10023150
// Name: public: int CUtlVector<class Vector2D,class CUtlMemory<class Vector2D,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>::InsertMultipleBefore(
        CUtlVector<ResourceEntryInfo,CUtlMemory<ResourceEntryInfo,int> > *this,
        int elem,
        int num)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  ResourceEntryInfo *m_pMemory; // ecx
  int v8; // eax
  int v9; // eax

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<CacheOptimizedKDNode,int>::Grow(this: &this->m_Memory, num: num + m_Size - m_nAllocationCount);
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
// Address: 0x10024AD0
// Name: public: void CUtlMemory<struct DetailPropLightstylesLump_t,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<DetailPropLightstylesLump_t,int>::Grow(
        CUtlMemory<DetailPropLightstylesLump_t,int> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  DetailPropLightstylesLump_t *m_pMemory; // edx
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
        m_nAllocationCount = 7;
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
    v7 = 5 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (DetailPropLightstylesLump_t *)_g_pMemAlloc->Realloc_2(
                                                         this: _g_pMemAlloc,
                                                         a2: m_pMemory,
                                                         a3: v7);
    else
      this->m_pMemory = (DetailPropLightstylesLump_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10025EF0
// Name: public: int CUtlVector<struct DetailPropLightstylesLump_t,class CUtlMemory<struct DetailPropLightstylesLump_t,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<DetailPropLightstylesLump_t,CUtlMemory<DetailPropLightstylesLump_t,int>>::InsertMultipleBefore(
        CUtlVector<DetailPropLightstylesLump_t,CUtlMemory<DetailPropLightstylesLump_t,int> > *this,
        int elem,
        int num)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  DetailPropLightstylesLump_t *m_pMemory; // ecx
  int v8; // eax
  int v9; // eax

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<DetailPropLightstylesLump_t,int>::Grow(this: &this->m_Memory, num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v8 = this->m_Size;
  this->m_pElements = this->m_Memory.m_pMemory;
  v9 = v8 - elem - num;
  if ( v9 > 0 && num > 0 )
    _V_memmove(
      dest: (char *)&m_pMemory->m_Lighting + 4 * elem + 4 * num + elem + num,
      src: (char *)&m_pMemory->m_Lighting + 4 * elem + elem,
      count: 5 * v9);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x1002B1A0
// Name: public: void CUtlMemory<struct colorVertex_t,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<colorVertex_t,int>::Grow(CUtlMemory<colorVertex_t,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  colorVertex_t *m_pMemory; // edx
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
    v7 = m_nAllocationCount << 6;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (colorVertex_t *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (colorVertex_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002C0E0
// Name: public: int CUtlVector<struct CShadowTextureList::materialentry_t,class CUtlMemory<struct CShadowTextureList::materialentry_t,int>>::InsertBefore(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CShadowTextureList::materialentry_t,CUtlMemory<CShadowTextureList::materialentry_t,int>>::InsertBefore(
        CUtlVector<CShadowTextureList::materialentry_t,CUtlMemory<CShadowTextureList::materialentry_t,int> > *this,
        int elem)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CShadowTextureList::materialentry_t *m_pMemory; // ecx
  int v6; // eax
  int v7; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CVradStaticPropMgr::MeshData_t,int>::Grow(
      (CUtlMemory<dleafambientlighting_t,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v6 = this->m_Size;
  this->m_pElements = this->m_Memory.m_pMemory;
  v7 = v6 - elem - 1;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 28 * v7);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x1002ED80
// Name: public: void CUtlVector<class CUtlVector<struct colorVertex_t,class CUtlMemory<struct colorVertex_t,int>> __near *,class CUtlMemory<class CUtlVector<struct colorVertex_t,class CUtlMemory<struct colorVertex_t,int>> __near *,int>>::PurgeAndDeleteElements(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CUtlVector<colorVertex_t,CUtlMemory<colorVertex_t,int>> *,CUtlMemory<CUtlVector<colorVertex_t,CUtlMemory<colorVertex_t,int>> *,int>>::PurgeAndDeleteElements(
        CUtlVector<CUtlVector<colorVertex_t,CUtlMemory<colorVertex_t,int> > *,CUtlMemory<CUtlVector<colorVertex_t,CUtlMemory<colorVertex_t,int> > *,int> > *this)
{
  int v2; // eax
  CUtlVector<colorVertex_t,CUtlMemory<colorVertex_t,int> > *v3; // esi
  colorVertex_t *m_pMemory; // eax
  CUtlVector<colorVertex_t,CUtlMemory<colorVertex_t,int> > **v5; // ecx
  int i; // [esp+8h] [ebp-4h]

  v2 = 0;
  for ( i = 0; v2 < this->m_Size; i = v2 )
  {
    v3 = this->m_Memory.m_pMemory[v2];
    if ( v3 != nullptr )
    {
      v3->m_Size = 0;
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
      free(pMem: v3);
      v2 = i;
    }
    ++v2;
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
    v5 = this->m_Memory.m_pMemory;
    this->m_Memory.m_nAllocationCount = 0;
    this->m_pElements = v5;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002EE40
// Name: public: int CUtlVector<struct CVradStaticPropMgr::StaticPropDict_t,class CUtlMemory<struct CVradStaticPropMgr::StaticPropDict_t,int>>::InsertBefore(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CVradStaticPropMgr::StaticPropDict_t,CUtlMemory<CVradStaticPropMgr::StaticPropDict_t,int>>::InsertBefore(
        CUtlVector<CVradStaticPropMgr::StaticPropDict_t,CUtlMemory<CVradStaticPropMgr::StaticPropDict_t,int> > *this,
        int elem)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CVradStaticPropMgr::StaticPropDict_t *m_pMemory; // ecx
  int v6; // eax
  CVradStaticPropMgr::StaticPropDict_t *v7; // edi

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CVradStaticPropMgr::StaticPropDict_t,int>::Grow(
      this: &this->m_Memory,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v6 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 136 * v6);
  v7 = &this->m_Memory.m_pMemory[elem];
  if ( v7 != nullptr )
  {
    CUtlBuffer::CUtlBuffer(this: &v7->m_VtxBuf, growSize: 0, initSize: 0, nFlags: 0);
    v7->m_textureShadowIndex.m_Memory.m_pMemory = nullptr;
    v7->m_textureShadowIndex.m_Memory.m_nAllocationCount = 0;
    v7->m_textureShadowIndex.m_Memory.m_nGrowSize = 0;
    v7->m_textureShadowIndex.m_Size = 0;
    v7->m_textureShadowIndex.m_pElements = nullptr;
    v7->m_triangleMaterialIndex.m_Memory.m_pMemory = nullptr;
    v7->m_triangleMaterialIndex.m_Memory.m_nAllocationCount = 0;
    v7->m_triangleMaterialIndex.m_Memory.m_nGrowSize = 0;
    v7->m_triangleMaterialIndex.m_Size = 0;
    v7->m_triangleMaterialIndex.m_pElements = nullptr;
  }
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x1002F070
// Name: public: void CUtlVector<struct CVradStaticPropMgr::StaticPropDict_t,class CUtlMemory<struct CVradStaticPropMgr::StaticPropDict_t,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CVradStaticPropMgr::StaticPropDict_t,CUtlMemory<CVradStaticPropMgr::StaticPropDict_t,int>>::RemoveAll(
        CUtlVector<CVradStaticPropMgr::StaticPropDict_t,CUtlMemory<CVradStaticPropMgr::StaticPropDict_t,int> > *this)
{
  int v1; // ebx
  int v2; // eax
  char *v3; // esi
  void *v4; // eax
  void *v5; // eax
  CUtlVector<CVradStaticPropMgr::StaticPropDict_t,CUtlMemory<CVradStaticPropMgr::StaticPropDict_t,int> > *v6; // [esp+4h] [ebp-8h]
  int v7; // [esp+8h] [ebp-4h]

  v1 = this->m_Size - 1;
  v6 = this;
  if ( v1 < 0 )
  {
    this->m_Size = 0;
  }
  else
  {
    v2 = 136 * v1;
    v7 = 136 * v1;
    do
    {
      v3 = (char *)this->m_Memory.m_pMemory + v2;
      *((_DWORD *)v3 + 32) = 0;
      if ( *((int *)v3 + 31) >= 0 )
      {
        if ( *((_DWORD *)v3 + 29) != 0 )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *((void **)v3 + 29));
          *((_DWORD *)v3 + 29) = 0;
        }
        *((_DWORD *)v3 + 30) = 0;
      }
      v4 = *((void **)v3 + 29);
      *((_DWORD *)v3 + 33) = v4;
      if ( *((int *)v3 + 31) >= 0 )
      {
        if ( v4 != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v4);
          *((_DWORD *)v3 + 29) = 0;
        }
        *((_DWORD *)v3 + 30) = 0;
      }
      *((_DWORD *)v3 + 27) = 0;
      if ( *((int *)v3 + 26) >= 0 )
      {
        if ( *((_DWORD *)v3 + 24) != 0 )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *((void **)v3 + 24));
          *((_DWORD *)v3 + 24) = 0;
        }
        *((_DWORD *)v3 + 25) = 0;
      }
      v5 = *((void **)v3 + 24);
      *((_DWORD *)v3 + 28) = v5;
      if ( *((int *)v3 + 26) >= 0 )
      {
        if ( v5 != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v5);
          *((_DWORD *)v3 + 24) = 0;
        }
        *((_DWORD *)v3 + 25) = 0;
      }
      if ( *((int *)v3 + 14) >= 0 )
      {
        if ( *((_DWORD *)v3 + 12) != 0 )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *((void **)v3 + 12));
          *((_DWORD *)v3 + 12) = 0;
        }
        *((_DWORD *)v3 + 13) = 0;
      }
      this = v6;
      --v1;
      v2 = v7 - 136;
      v7 -= 136;
    }
    while ( v1 >= 0 );
    v6->m_Size = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002F220
// Name: public: void CUtlVector<struct CVradStaticPropMgr::MeshData_t,class CUtlMemory<struct CVradStaticPropMgr::MeshData_t,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CVradStaticPropMgr::MeshData_t,CUtlMemory<CVradStaticPropMgr::MeshData_t,int>>::RemoveAll(
        CUtlVector<CVradStaticPropMgr::MeshData_t,CUtlMemory<CVradStaticPropMgr::MeshData_t,int> > *this)
{
  int v1; // ebx
  int v2; // edx
  char *v3; // esi
  void *v4; // eax
  CUtlVector<CVradStaticPropMgr::MeshData_t,CUtlMemory<CVradStaticPropMgr::MeshData_t,int> > *v5; // [esp+4h] [ebp-8h]
  int v6; // [esp+8h] [ebp-4h]

  v1 = this->m_Size - 1;
  v5 = this;
  if ( v1 < 0 )
  {
    this->m_Size = 0;
  }
  else
  {
    v2 = 28 * v1;
    v6 = 28 * v1;
    do
    {
      v3 = (char *)this->m_Memory.m_pMemory + v2;
      *((_DWORD *)v3 + 3) = 0;
      if ( *((int *)v3 + 2) >= 0 )
      {
        if ( *(_DWORD *)v3 != 0 )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *(void **)v3);
          v2 = v6;
          this = v5;
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
          v2 = v6;
          this = v5;
          *(_DWORD *)v3 = 0;
        }
        *((_DWORD *)v3 + 1) = 0;
      }
      --v1;
      v2 -= 28;
      v6 = v2;
    }
    while ( v1 >= 0 );
    this->m_Size = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002F960
// Name: public: CUtlVector<struct CVradStaticPropMgr::StaticPropDict_t,class CUtlMemory<struct CVradStaticPropMgr::StaticPropDict_t,int>>::~CUtlVector<struct CVradStaticPropMgr::StaticPropDict_t,class CUtlMemory<struct CVradStaticPropMgr::StaticPropDict_t,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CVradStaticPropMgr::StaticPropDict_t,CUtlMemory<CVradStaticPropMgr::StaticPropDict_t,int>>::~CUtlVector<CVradStaticPropMgr::StaticPropDict_t,CUtlMemory<CVradStaticPropMgr::StaticPropDict_t,int>>(
        CUtlVector<CVradStaticPropMgr::StaticPropDict_t,CUtlMemory<CVradStaticPropMgr::StaticPropDict_t,int> > *this)
{
  bool v2; // sf
  CVradStaticPropMgr::StaticPropDict_t *m_pMemory; // eax

  CUtlVector<CVradStaticPropMgr::StaticPropDict_t,CUtlMemory<CVradStaticPropMgr::StaticPropDict_t,int>>::RemoveAll(this);
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
// Address: 0x10030200
// Name: public: int CUtlVector<struct CVradStaticPropMgr::CStaticProp,class CUtlMemory<struct CVradStaticPropMgr::CStaticProp,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CVradStaticPropMgr::CStaticProp,CUtlMemory<CVradStaticPropMgr::CStaticProp,int>>::InsertMultipleBefore(
        CUtlVector<CVradStaticPropMgr::CStaticProp,CUtlMemory<CVradStaticPropMgr::CStaticProp,int> > *this,
        int elem,
        int num)
{
  int v3; // edi
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CVradStaticPropMgr::CStaticProp *m_pMemory; // ecx
  int v9; // eax
  int v10; // ecx
  CVradStaticPropMgr::CStaticProp *v11; // eax

  v3 = num;
  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<CVradStaticPropMgr::CStaticProp,int>::Grow(this: &this->m_Memory, num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v9 = this->m_Size - elem - num;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v9 <= 0 )
    goto LABEL_8;
  if ( num > 0 )
  {
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 96 * v9);
LABEL_8:
    if ( num > 0 )
    {
      v10 = elem;
      do
      {
        v11 = &this->m_Memory.m_pMemory[v10];
        if ( v11 != nullptr )
        {
          v11->m_MeshData.m_Memory.m_pMemory = nullptr;
          v11->m_MeshData.m_Memory.m_nAllocationCount = 0;
          v11->m_MeshData.m_Memory.m_nGrowSize = 0;
          v11->m_MeshData.m_Size = 0;
          v11->m_MeshData.m_pElements = nullptr;
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
// Address: 0x100302B0
// Name: public: void CUtlVector<struct CVradStaticPropMgr::CStaticProp,class CUtlMemory<struct CVradStaticPropMgr::CStaticProp,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CVradStaticPropMgr::CStaticProp,CUtlMemory<CVradStaticPropMgr::CStaticProp,int>>::RemoveAll(
        CUtlVector<CVradStaticPropMgr::CStaticProp,CUtlMemory<CVradStaticPropMgr::CStaticProp,int> > *this)
{
  int v1; // edi
  int v2; // ebx
  CVradStaticPropMgr::CStaticProp *v3; // esi
  bool v4; // sf
  CVradStaticPropMgr::MeshData_t *m_pMemory; // eax
  CUtlVector<CVradStaticPropMgr::CStaticProp,CUtlMemory<CVradStaticPropMgr::CStaticProp,int> > *v6; // [esp+4h] [ebp-4h]

  v1 = this->m_Size - 1;
  v6 = this;
  if ( v1 >= 0 )
  {
    v2 = v1;
    do
    {
      v3 = &this->m_Memory.m_pMemory[v2];
      CUtlVector<CVradStaticPropMgr::MeshData_t,CUtlMemory<CVradStaticPropMgr::MeshData_t,int>>::RemoveAll(this: &v3->m_MeshData);
      if ( v3->m_MeshData.m_Memory.m_nGrowSize >= 0 )
      {
        if ( v3->m_MeshData.m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v3->m_MeshData.m_Memory.m_pMemory);
          v3->m_MeshData.m_Memory.m_pMemory = nullptr;
        }
        v3->m_MeshData.m_Memory.m_nAllocationCount = 0;
      }
      v4 = v3->m_MeshData.m_Memory.m_nGrowSize < 0;
      m_pMemory = v3->m_MeshData.m_Memory.m_pMemory;
      v3->m_MeshData.m_pElements = m_pMemory;
      if ( !v4 )
      {
        if ( m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
          v3->m_MeshData.m_Memory.m_pMemory = nullptr;
        }
        v3->m_MeshData.m_Memory.m_nAllocationCount = 0;
      }
      this = v6;
      --v2;
      --v1;
    }
    while ( v1 >= 0 );
  }
  this->m_Size = 0;
}

//------------------------------------------------------------------------------
// Address: 0x10030640
// Name: public: CUtlVector<struct CVradStaticPropMgr::CStaticProp,class CUtlMemory<struct CVradStaticPropMgr::CStaticProp,int>>::~CUtlVector<struct CVradStaticPropMgr::CStaticProp,class CUtlMemory<struct CVradStaticPropMgr::CStaticProp,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CVradStaticPropMgr::CStaticProp,CUtlMemory<CVradStaticPropMgr::CStaticProp,int>>::~CUtlVector<CVradStaticPropMgr::CStaticProp,CUtlMemory<CVradStaticPropMgr::CStaticProp,int>>(
        CUtlVector<CVradStaticPropMgr::CStaticProp,CUtlMemory<CVradStaticPropMgr::CStaticProp,int> > *this)
{
  bool v2; // sf
  CVradStaticPropMgr::CStaticProp *m_pMemory; // eax

  CUtlVector<CVradStaticPropMgr::CStaticProp,CUtlMemory<CVradStaticPropMgr::CStaticProp,int>>::RemoveAll(this);
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
// Address: 0x10036A80
// Name: public: void CUtlMemory<struct texinfo_s,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<texinfo_s,int>::Grow(CUtlMemory<texinfo_s,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  texinfo_s *m_pMemory; // edx
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
      this->m_pMemory = (texinfo_s *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (texinfo_s *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10036B20
// Name: public: void CUtlMemory<struct doccluderdata_t,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<doccluderdata_t,int>::Grow(CUtlMemory<doccluderdata_t,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  doccluderdata_t *m_pMemory; // edx
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
    v7 = 40 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (doccluderdata_t *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (doccluderdata_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10036BC0
// Name: public: void CUtlMemory<struct clusterlist_t,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<clusterlist_t,int>::Grow(
        CUtlMemory<UtlLinkedListElem_t<unsigned __int64,unsigned __int64>,unsigned __int64> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  UtlLinkedListElem_t<unsigned __int64,unsigned __int64> *m_pMemory; // edx
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
      this->m_pMemory = (UtlLinkedListElem_t<unsigned __int64,unsigned __int64> *)_g_pMemAlloc->Realloc_2(
                                                                                    this: _g_pMemAlloc,
                                                                                    a2: m_pMemory,
                                                                                    a3: v7);
    else
      this->m_pMemory = (UtlLinkedListElem_t<unsigned __int64,unsigned __int64> *)_g_pMemAlloc->Alloc_2(
                                                                                    this: _g_pMemAlloc,
                                                                                    a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10036C60
// Name: public: void CUtlMemory<class ddispinfo_t,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<ddispinfo_t,int>::Grow(CUtlMemory<ddispinfo_t,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  ddispinfo_t *m_pMemory; // edx
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
    v7 = 176 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (ddispinfo_t *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (ddispinfo_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10036D00
// Name: public: void CUtlMemory<class CDispMultiBlend,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<CDispMultiBlend,int>::Grow(CUtlMemory<CDispMultiBlend,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  CDispMultiBlend *m_pMemory; // edx
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
    v7 = 80 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (CDispMultiBlend *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (CDispMultiBlend *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100382A0
// Name: public: void CUtlMemory<struct UtlLinkedListElem_t<struct GameLump_t,unsigned short>,unsigned short>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<UtlLinkedListElem_t<GameLump_t,unsigned short>,unsigned short>::Grow(
        CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CShadowTextureList::alphatexture_t,unsigned short>::Node_t,unsigned short>,unsigned short> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  UtlRBTreeNode_t<CUtlMap<char const *,CShadowTextureList::alphatexture_t,unsigned short>::Node_t,unsigned short> *m_pMemory; // edx
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
      for ( ; m_nAllocationCount < v5; m_nAllocationCount *= 2 )
        ;
    }
    if ( (unsigned __int16)m_nAllocationCount < v5 )
    {
      if ( (_WORD)m_nAllocationCount != 0 || v5 > 0xFFFF )
      {
        if ( (unsigned __int16)v5 != v5 )
          return;
        do
          m_nAllocationCount = (v5 + m_nAllocationCount) / 2;
        while ( (unsigned __int16)m_nAllocationCount < v5 );
      }
      else
      {
        --m_nAllocationCount;
      }
    }
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    v7 = 24 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (UtlRBTreeNode_t<CUtlMap<char const *,CShadowTextureList::alphatexture_t,unsigned short>::Node_t,unsigned short> *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (UtlRBTreeNode_t<CUtlMap<char const *,CShadowTextureList::alphatexture_t,unsigned short>::Node_t,unsigned short> *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10039530
// Name: public: int CUtlVector<struct texinfo_s,class CUtlMemory<struct texinfo_s,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<texinfo_s,CUtlMemory<texinfo_s,int>>::InsertMultipleBefore(
        CUtlVector<texinfo_s,CUtlMemory<texinfo_s,int> > *this,
        int elem,
        int num)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  texinfo_s *m_pMemory; // ecx
  int v8; // eax
  int v9; // eax

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<texinfo_s,int>::Grow(this: &this->m_Memory, num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v8 = this->m_Size;
  this->m_pElements = this->m_Memory.m_pMemory;
  v9 = v8 - elem - num;
  if ( v9 > 0 && num > 0 )
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 72 * v9);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x10039AA0
// Name: public: int CUtlVector<struct doccluderdata_t,class CUtlMemory<struct doccluderdata_t,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<doccluderdata_t,CUtlMemory<doccluderdata_t,int>>::InsertMultipleBefore(
        CUtlVector<doccluderdata_t,CUtlMemory<doccluderdata_t,int> > *this,
        int elem,
        int num)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  doccluderdata_t *m_pMemory; // ecx
  int v8; // eax
  int v9; // eax

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<doccluderdata_t,int>::Grow(this: &this->m_Memory, num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v8 = this->m_Size;
  this->m_pElements = this->m_Memory.m_pMemory;
  v9 = v8 - elem - num;
  if ( v9 > 0 && num > 0 )
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 40 * v9);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x10039B20
// Name: public: int CUtlVector<struct doccluderpolydata_t,class CUtlMemory<struct doccluderpolydata_t,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<doccluderpolydata_t,CUtlMemory<doccluderpolydata_t,int>>::InsertMultipleBefore(
        CUtlVector<Vector,CUtlMemory<Vector,int> > *this,
        int elem,
        int num)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  Vector *m_pMemory; // ecx
  int v8; // eax
  int v9; // eax

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<UtlLinkedListElem_t<CMasterMulticastThread::CMulticastFile *,int>,int>::Grow(
      (CUtlMemory<CVTFTexture::ResourceMemorySection,int> *)this,
      num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v8 = this->m_Size;
  this->m_pElements = this->m_Memory.m_pMemory;
  v9 = v8 - elem - num;
  if ( v9 > 0 && num > 0 )
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 12 * v9);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x10039D20
// Name: public: int CUtlVector<struct dleafambientlighting_t,class CUtlMemory<struct dleafambientlighting_t,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<dleafambientlighting_t,CUtlMemory<dleafambientlighting_t,int>>::InsertMultipleBefore(
        CUtlVector<dleafambientlighting_t,CUtlMemory<dleafambientlighting_t,int> > *this,
        int elem,
        int num)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  dleafambientlighting_t *m_pMemory; // ecx
  int v8; // eax
  int v9; // eax

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<CVradStaticPropMgr::MeshData_t,int>::Grow(this: &this->m_Memory, num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v8 = this->m_Size;
  this->m_pElements = this->m_Memory.m_pMemory;
  v9 = v8 - elem - num;
  if ( v9 > 0 && num > 0 )
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 28 * v9);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x10039DB0
// Name: public: int CUtlVector<class ddispinfo_t,class CUtlMemory<class ddispinfo_t,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<ddispinfo_t,CUtlMemory<ddispinfo_t,int>>::InsertMultipleBefore(
        CUtlVector<ddispinfo_t,CUtlMemory<ddispinfo_t,int> > *this,
        int elem,
        int num)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  ddispinfo_t *m_pMemory; // ecx
  int v8; // eax
  int v9; // eax

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<ddispinfo_t,int>::Grow(this: &this->m_Memory, num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v8 = this->m_Size;
  this->m_pElements = this->m_Memory.m_pMemory;
  v9 = v8 - elem - num;
  if ( v9 > 0 && num > 0 )
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 176 * v9);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x10039E30
// Name: public: int CUtlVector<class CDispVert,class CUtlMemory<class CDispVert,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CDispVert,CUtlMemory<CDispVert,int>>::InsertMultipleBefore(
        CUtlVector<CDispVert,CUtlMemory<CDispVert,int> > *this,
        int elem,
        int num)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CDispVert *m_pMemory; // ecx
  int v8; // eax
  int v9; // eax

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<UtlRBTreeNode_t<float,int>,int>::Grow(
      (CUtlMemory<CUtlVector<CLightFace *,CUtlMemory<CLightFace *,int> >,int> *)this,
      num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v8 = this->m_Size;
  this->m_pElements = this->m_Memory.m_pMemory;
  v9 = v8 - elem - num;
  if ( v9 > 0 && num > 0 )
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 20 * v9);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x10039EB0
// Name: public: int CUtlVector<class CDispMultiBlend,class CUtlMemory<class CDispMultiBlend,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CDispMultiBlend,CUtlMemory<CDispMultiBlend,int>>::InsertMultipleBefore(
        CUtlVector<CDispMultiBlend,CUtlMemory<CDispMultiBlend,int> > *this,
        int elem,
        int num)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CDispMultiBlend *m_pMemory; // ecx
  int v8; // eax
  int v9; // eax

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<CDispMultiBlend,int>::Grow(this: &this->m_Memory, num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v8 = this->m_Size;
  this->m_pElements = this->m_Memory.m_pMemory;
  v9 = v8 - elem - num;
  if ( v9 > 0 && num > 0 )
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 80 * v9);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x10039F30
// Name: public: int CUtlVector<struct dfacebrushlist_t,class CUtlMemory<struct dfacebrushlist_t,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<dfacebrushlist_t,CUtlMemory<dfacebrushlist_t,int>>::InsertMultipleBefore(
        CUtlVector<S3RGBA,CUtlMemory<S3RGBA,int> > *this,
        int elem,
        int num)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  S3RGBA *m_pMemory; // ecx
  int v8; // eax
  int v9; // eax

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<int,int>::Grow(this: &this->m_Memory, num: num + m_Size - m_nAllocationCount);
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
// Address: 0x1003E110
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
// Address: 0x1003E180
// Name: public: int CUtlVector<struct clusterlist_t,class CUtlMemory<struct clusterlist_t,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<clusterlist_t,CUtlMemory<clusterlist_t,int>>::InsertMultipleBefore(
        CUtlVector<clusterlist_t,CUtlMemory<clusterlist_t,int> > *this,
        int elem,
        int num)
{
  int v3; // edi
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  clusterlist_t *m_pMemory; // ecx
  int v9; // eax
  int v10; // ecx
  clusterlist_t *v11; // eax

  v3 = num;
  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<clusterlist_t,int>::Grow(
      (CUtlMemory<UtlLinkedListElem_t<unsigned __int64,unsigned __int64>,unsigned __int64> *)this,
      num: num + m_Size - m_nAllocationCount);
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
          v11->leafs.m_Memory.m_pMemory = nullptr;
          v11->leafs.m_Memory.m_nAllocationCount = 0;
          v11->leafs.m_Memory.m_nGrowSize = 0;
          v11->leafs.m_Size = 0;
          v11->leafs.m_pElements = nullptr;
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
// Address: 0x1003FA50
// Name: public: CUtlVector<struct clusterlist_t,class CUtlMemory<struct clusterlist_t,int>>::~CUtlVector<struct clusterlist_t,class CUtlMemory<struct clusterlist_t,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<clusterlist_t,CUtlMemory<clusterlist_t,int>>::~CUtlVector<clusterlist_t,CUtlMemory<clusterlist_t,int>>(
        CUtlVector<CWorkUnit,CUtlMemory<CWorkUnit,int> > *this)
{
  bool v2; // sf
  CWorkUnit *m_pMemory; // eax

  CUtlVector<clusterlist_t,CUtlMemory<clusterlist_t,int>>::RemoveAll(this);
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
// Address: 0x1003FAB0
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
// Address: 0x10048740
// Name: public: int CUtlVector<class CDispCollNode,class CUtlMemoryAligned<class CDispCollNode,16>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CDispCollNode,CUtlMemoryAligned<CDispCollNode,16>>::InsertMultipleBefore(
        CUtlVector<CDispCollNode,CUtlMemoryAligned<CDispCollNode,16> > *this,
        int elem,
        int num)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CDispCollNode *m_pMemory; // ecx
  int v8; // eax
  int v9; // eax

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemoryAligned<CDispCollNode,16>::Grow(this: &this->m_Memory, num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v8 = this->m_Size;
  this->m_pElements = this->m_Memory.m_pMemory;
  v9 = v8 - elem - num;
  if ( v9 > 0 && num > 0 )
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 96 * v9);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x100487C0
// Name: public: int CUtlVector<class CDispCollLeaf,class CUtlMemoryAligned<class CDispCollLeaf,16>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CDispCollLeaf,CUtlMemoryAligned<CDispCollLeaf,16>>::InsertMultipleBefore(
        CUtlVector<CDispCollLeaf,CUtlMemoryAligned<CDispCollLeaf,16> > *this,
        int elem,
        int num)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CDispCollLeaf *m_pMemory; // ecx
  int v8; // eax
  int v9; // eax

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemoryAligned<CDispCollLeaf,16>::Grow(this: &this->m_Memory, num: num + m_Size - m_nAllocationCount);
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
// Address: 0x10048830
// Name: public: int CUtlVector<class CDispCollTri,class CUtlMemoryAligned<class CDispCollTri,16>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CDispCollTri,CUtlMemoryAligned<CDispCollTri,16>>::InsertMultipleBefore(
        CUtlVector<CDispCollTri,CUtlMemoryAligned<CDispCollTri,16> > *this,
        int elem,
        int num)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CDispCollTri *m_pMemory; // ecx
  int v9; // ebx
  int v10; // eax
  int v11; // eax
  int v12; // eax
  unsigned int v13; // edx
  CDispCollTri *v14; // ecx
  CDispCollTri *v15; // ecx
  CDispCollTri *v16; // ecx
  CDispCollTri *v17; // ecx
  int v18; // ecx
  int v19; // edi
  CDispCollTri *v20; // eax
  int i; // [esp+14h] [ebp+Ch]

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemoryAligned<CDispCollTri,16>::Grow(this: &this->m_Memory, num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v9 = elem;
  v10 = this->m_Size - elem - num;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v10 > 0 && num > 0 )
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 24 * v10);
  v11 = 0;
  if ( num >= 4 )
  {
    v12 = elem;
    v13 = ((unsigned int)(num - 4) >> 2) + 1;
    i = 4 * v13;
    do
    {
      v14 = &this->m_Memory.m_pMemory[v12];
      if ( v14 != nullptr )
      {
        v14->m_vecNormal.x = 0.0;
        v14->m_vecNormal.y = 0.0;
        v14->m_vecNormal.z = 0.0;
        v14->m_flDist = 0.0;
        v14->m_TriData[2].m_IndexDummy = 0;
        v14->m_TriData[1].m_IndexDummy = 0;
        v14->m_TriData[0].m_IndexDummy = 0;
      }
      v15 = &this->m_Memory.m_pMemory[v12 + 1];
      if ( &this->m_Memory.m_pMemory[v12] != (CDispCollTri *)-24 )
      {
        this->m_Memory.m_pMemory[v12 + 1].m_vecNormal.x = 0.0;
        v15->m_vecNormal.y = 0.0;
        v15->m_vecNormal.z = 0.0;
        v15->m_flDist = 0.0;
        v15->m_TriData[2].m_IndexDummy = 0;
        v15->m_TriData[1].m_IndexDummy = 0;
        v15->m_TriData[0].m_IndexDummy = 0;
      }
      v16 = &this->m_Memory.m_pMemory[v12 + 2];
      if ( &this->m_Memory.m_pMemory[v12] != (CDispCollTri *)-48 )
      {
        this->m_Memory.m_pMemory[v12 + 2].m_vecNormal.x = 0.0;
        v16->m_vecNormal.y = 0.0;
        v16->m_vecNormal.z = 0.0;
        v16->m_flDist = 0.0;
        v16->m_TriData[2].m_IndexDummy = 0;
        v16->m_TriData[1].m_IndexDummy = 0;
        v16->m_TriData[0].m_IndexDummy = 0;
      }
      v17 = &this->m_Memory.m_pMemory[v12 + 3];
      if ( &this->m_Memory.m_pMemory[v12] != (CDispCollTri *)-72 )
      {
        this->m_Memory.m_pMemory[v12 + 3].m_vecNormal.x = 0.0;
        v17->m_vecNormal.y = 0.0;
        v17->m_vecNormal.z = 0.0;
        v17->m_flDist = 0.0;
        v17->m_TriData[2].m_IndexDummy = 0;
        v17->m_TriData[1].m_IndexDummy = 0;
        v17->m_TriData[0].m_IndexDummy = 0;
      }
      v12 += 4;
      --v13;
    }
    while ( v13 != 0 );
    v9 = elem;
    v11 = i;
  }
  if ( v11 < num )
  {
    v18 = v11 + v9;
    v19 = num - v11;
    do
    {
      v20 = &this->m_Memory.m_pMemory[v18];
      if ( v20 != nullptr )
      {
        v20->m_vecNormal.x = 0.0;
        v20->m_vecNormal.y = 0.0;
        v20->m_vecNormal.z = 0.0;
        v20->m_flDist = 0.0;
        v20->m_TriData[2].m_IndexDummy = 0;
        v20->m_TriData[1].m_IndexDummy = 0;
        v20->m_TriData[0].m_IndexDummy = 0;
      }
      ++v18;
      --v19;
    }
    while ( v19 != 0 );
  }
  return v9;
}

//------------------------------------------------------------------------------
// Address: 0x1004AB20
// Name: void AddScriptToStack(char __near *,enum ScriptPathMode_t)
// Source: json
//------------------------------------------------------------------------------
void __cdecl AddScriptToStack(char *filename, ScriptPathMode_t pathMode)
{
  int File; // esi
  const char *v3; // [esp-8h] [ebp-8h]

  if ( ++script == (script_t *)token )
    _Error(a1: "script file exceeded MAX_INCLUDES");
  if ( pathMode == SCRIPT_USE_RELATIVE_PATH )
  {
    V_strncpy(pDest: script->filename, pSrc: filename, maxLen: 1024);
  }
  else
  {
    v3 = ExpandPath(path: filename);
    V_strncpy(pDest: script->filename, pSrc: v3, maxLen: 1024);
  }
  File = LoadFile(filename: script->filename, bufferptr: (void **)&script->buffer);
  if ( g_pfnCallback != nullptr )
    ((void (__thiscall *)(CFileSystemPassThru *))g_pfnCallback)(this: g_pfnCallback);
  script->line = 1;
  script->script_p = script->buffer;
  script->end_p = &script->buffer[File];
}

//------------------------------------------------------------------------------
// Address: 0x1004AC00
// Name: bool AddMacroToStack(char __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl AddMacroToStack(char *macroname)
{
  int v2; // esi
  bool v3; // zf
  script_t *v4; // edi
  script_t *v5; // ebx
  int nummacroparams; // eax
  char *macrobuffer; // esi
  char **macroparam; // edi
  unsigned int v9; // esi
  script_t *pmacro; // [esp+4h] [ebp-4h]
  int i; // [esp+10h] [ebp+8h]

  if ( *macroname != 36 )
    return 0;
  v2 = 0;
  v3 = nummacros == 0;
  if ( nummacros > 0 )
  {
    do
    {
      if ( _V_stricmp(s1: macrolist[v2]->filename, s2: macroname + 1) == 0 )
        break;
      ++v2;
    }
    while ( v2 < nummacros );
    v3 = v2 == nummacros;
  }
  if ( v3 )
    return 0;
  v4 = macrolist[v2];
  v5 = script + 2;
  pmacro = v4;
  if ( &script[2] == (script_t *)token )
    _Error(a1: "script file exceeded MAX_INCLUDES");
  nummacroparams = v4->nummacroparams;
  macrobuffer = v5->macrobuffer;
  v5->nummacroparams = nummacroparams;
  i = 0;
  if ( nummacroparams > 0 )
  {
    macroparam = v5->macroparam;
    do
    {
      GetToken(crossline: 0);
      strcpy(macrobuffer, token);
      *macroparam = *(char **)((char *)macroparam + (char *)pmacro - (char *)v5);
      macroparam[64] = macrobuffer;
      macrobuffer += strlen(token) + 1;
      if ( macrobuffer >= (char *)v5->macroparam )
        _Error(a1: "Macro buffer overflow\n");
      ++macroparam;
      ++i;
    }
    while ( i < v5->nummacroparams );
    v4 = pmacro;
  }
  script = (script_t *)strcpy(v5->filename, v4->filename);
  v9 = v4->end_p - v4->buffer;
  script->buffer = (char *)MemAlloc_Alloc(nSize: v9 + 1);
  memcpy(dst: (unsigned __int8 *)script->buffer, src: (unsigned __int8 *)v4->buffer, count: v9);
  v4->buffer[v9] = 0;
  script->script_p = script->buffer;
  script->end_p = &script->buffer[v9];
  script->line = v4->line;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1004ADC0
// Name: bool ExpandMacroToken(char __near * __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl ExpandMacroToken(char **token_p)
{
  char *script_p; // eax
  _BYTE *v2; // ebx
  char v3; // al
  script_t *v5; // eax
  int v6; // esi
  int v7; // edi
  bool v8; // zf
  const char *v9; // edx
  unsigned int v10; // eax
  _BYTE *v11; // esi
  char v12; // cl
  char *s2; // [esp+0h] [ebp-4h]

  if ( script->nummacroparams == 0 )
    return 0;
  script_p = script->script_p;
  if ( *script_p != 36 )
    return 0;
  v2 = script_p + 1;
  s2 = script_p + 1;
  v3 = script_p[1];
  if ( v3 <= 32 )
  {
LABEL_6:
    if ( *v2 != 36 )
      return 0;
  }
  else
  {
    while ( v3 != 36 )
    {
      v3 = *++v2;
      if ( v3 <= 32 )
        goto LABEL_6;
    }
  }
  *v2 = 0;
  v5 = script;
  v6 = 0;
  if ( script->nummacroparams <= 0 )
    goto LABEL_13;
  v7 = 5136;
  do
  {
    v8 = _V_stricmp(s1: *(const char **)&v5->filename[v7], s2) == 0;
    v5 = script;
    if ( v8 )
      break;
    ++v6;
    v7 += 4;
  }
  while ( v6 < script->nummacroparams );
  if ( v6 >= script->nummacroparams )
  {
LABEL_13:
    _Error(a1: "unknown macro token \"%s\" in %s\n", s2, v5->filename);
    v5 = script;
  }
  v9 = v5->macrovalue[v6];
  v10 = strlen(v9);
  v11 = *token_p;
  do
  {
    v12 = *v9;
    *v11++ = *v9++;
  }
  while ( v12 != 0 );
  *token_p += v10;
  script->script_p = v2 + 1;
  if ( script->script_p >= script->end_p )
    _Error(a1: "Macro expand overflow\n");
  if ( *token_p >= (char *)&nummacros )
    _Error(a1: "Token too large on line %i\n", scriptline);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1004AEF0
// Name: void ParseFromMemory(char __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ParseFromMemory(char *buffer, int size)
{
  scriptstack[1].buffer = buffer;
  scriptstack[1].script_p = buffer;
  script = &scriptstack[1];
  scriptstack[1].end_p = &buffer[size];
  strcpy(scriptstack[1].filename, "memory buffer");
  scriptstack[1].line = 1;
  endofscript = 0;
  tokenready = 0;
}

//------------------------------------------------------------------------------
// Address: 0x1004AF60
// Name: int EndOfScript(int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl EndOfScript(int crossline)
{
  if ( crossline == 0 )
    _Error(a1: "Line %i is incomplete\n", scriptline);
  if ( strcmp(script->filename, aMemoryB) == 0
    || (free(pMem: script->buffer), script->buffer = nullptr, script == &scriptstack[1]) )
  {
    endofscript = 1;
    return 0;
  }
  else
  {
    --script;
    scriptline = script->line;
    return GetToken(crossline);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004B020
// Name: int TokenAvailable(void)
// Source: json
//------------------------------------------------------------------------------
int __cdecl TokenAvailable()
{
  char *script_p; // eax
  char *end_p; // edx
  char v3; // cl
  char v4; // cl

  if ( tokenready != 0 )
    return 1;
  script_p = script->script_p;
  end_p = script->end_p;
  if ( script_p < end_p )
  {
    v3 = *script_p;
    if ( *script_p > 32 )
    {
LABEL_8:
      v4 = *script_p;
      if ( *script_p != 59 && v4 != 35 && (v4 != 47 || script_p[1] != 47) )
        return 1;
    }
    else
    {
      while ( v3 != 10 )
      {
        if ( ++script_p == end_p )
          break;
        v3 = *script_p;
        if ( *script_p > 32 )
          goto LABEL_8;
      }
    }
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1004B080
// Name: public: virtual bool CScriptLib::DoesFileExist(char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CScriptLib::DoesFileExist(CScriptLib *this, const char *pFilename)
{
  return g_pFullFileSystem->FileExists(this: &g_pFullFileSystem->IBaseFileSystem, a2: pFilename, a3: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x1004B0A0
// Name: public: virtual bool CScriptLib::ReadFileToBuffer(char const __near *,class CUtlBuffer __near &,bool,bool)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CScriptLib::ReadFileToBuffer(
        CScriptLib *this,
        const char *pSourceName,
        CUtlBuffer *buffer,
        bool bText,
        bool bNoOpenFailureWarning)
{
  int *v5; // eax
  const char *v6; // eax

  if ( g_pFullFileSystem->ReadFile(
         this: &g_pFullFileSystem->IBaseFileSystem,
         a2: pSourceName,
         a3: nullptr,
         a4: buffer,
         a5: 0,
         a6: 0,
         a7: nullptr) )
  {
    if ( bText )
      CUtlBuffer::SetBufferType(this: buffer, bIsText: true, bContainsCRLF: true);
    else
      CUtlBuffer::SetBufferType(this: buffer, bIsText: false, bContainsCRLF: false);
    return 1;
  }
  else
  {
    if ( !bNoOpenFailureWarning )
    {
      v5 = _errno();
      v6 = strerror(errnum: *v5);
      _Msg(a1: "ReadFileToBuffer(): Error opening %s: %s\n", pSourceName, v6);
    }
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004B120
// Name: public: virtual bool CScriptLib::WriteBufferToFile(char const __near *,class CUtlBuffer __near &,enum DiskWriteMode_t)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CScriptLib::WriteBufferToFile(
        CScriptLib *this,
        const char *pTargetName,
        CUtlBuffer *buffer,
        DiskWriteMode_t writeMode)
{
  _BYTE *v5; // eax
  _BYTE *v6; // esi
  _BYTE *v7; // eax
  char dirPath[260]; // [esp+8h] [ebp-104h] BYREF

  strcpy(dirPath, pTargetName);
  strchr(string: (unsigned __int8 *)dirPath, chr: 0x5Cu);
  v6 = v5;
  if ( v5 != nullptr )
  {
    while ( 1 )
    {
      strchr(string: v6 + 1, chr: 0x5Cu);
      v6 = v7;
      if ( v7 == nullptr )
        break;
      *v7 = 0;
      _mkdir(path: dirPath);
      *v6 = 92;
    }
  }
  return writeMode != WRITE_TO_DISK_ALWAYS
      && (writeMode != WRITE_TO_DISK_UPDATE || !this->DoesFileExist(this, a2: pTargetName))
      || g_pFullFileSystem->WriteFile(
           this: &g_pFullFileSystem->IBaseFileSystem,
           a2: pTargetName,
           a3: nullptr,
           a4: buffer);
}

//------------------------------------------------------------------------------
// Address: 0x1004B1E0
// Name: public: virtual int CScriptLib::CompareFileTime(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CScriptLib::CompareFileTime(CScriptLib *this, const char *pFilenameA, const char *pFilenameB)
{
  unsigned int v3; // esi
  unsigned int v4; // eax
  bool v5; // cf

  v3 = g_pFullFileSystem->GetFileTime(this: &g_pFullFileSystem->IBaseFileSystem, a2: pFilenameA, a3: nullptr);
  v4 = g_pFullFileSystem->GetFileTime(this: &g_pFullFileSystem->IBaseFileSystem, a2: pFilenameB, a3: nullptr);
  if ( v3 == -1 )
    v3 = 0;
  if ( v4 == -1 )
    return v3 != 0;
  v5 = v4 < v3;
  if ( v4 <= v3 )
    return v5;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x1004B240
// Name: public: virtual char __near * CScriptLib::MakeTemporaryFilename(char const __near *,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CScriptLib::MakeTemporaryFilename(CScriptLib *this, const char *pchModPath, char *pPath, int pathSize)
{
  char *v4; // eax
  char *v5; // esi

  v4 = _tempnam(dir: pchModPath, pfx: "mgd_");
  v5 = v4;
  if ( *v4 == 92 )
    v5 = v4 + 1;
  if ( v5[strlen(v5) - 1] == 46 )
    v5[strlen(v5) - 1] = 0;
  V_snprintf(pDest: pPath, maxLen: pathSize, pFormat: "%s.tmp", v5);
  free(pMem: v5);
  return pPath;
}

//------------------------------------------------------------------------------
// Address: 0x1004B2B0
// Name: void DefineMacro(char __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DefineMacro(char *macroname)
{
  script_t *v1; // edi
  char *script_p; // esi
  char *macrobuffer; // ebx
  unsigned int v4; // ebx
  unsigned __int8 *v5; // eax
  int v6; // eax
  script_t *v7; // edx

  v1 = (script_t *)MemAlloc_Alloc(nSize: 0x1614u);
  strcpy(v1->filename, macroname);
  v1->line = script->line;
  v1->nummacroparams = 0;
  script_p = script->script_p;
  macrobuffer = v1->macrobuffer;
  while ( TokenAvailable() != 0 )
  {
    GetToken(crossline: 0);
    if ( token[0] == 92 && byte_1525E239 == 92 )
      break;
    script_p = script->script_p;
    v1->macroparam[v1->nummacroparams++] = macrobuffer;
    strcpy(macrobuffer, token);
    macrobuffer += strlen(token) + 1;
    if ( macrobuffer >= (char *)v1->macroparam )
      _Error(a1: "Macro buffer overflow\n");
  }
  for ( script->script_p = script_p; *script_p != 0; ++script_p )
  {
    if ( *script_p == 10 )
      break;
    if ( *script_p == 92 && script_p[1] == 92 )
    {
      do
      {
        if ( *script_p == 10 )
          break;
        *script_p++ = 32;
      }
      while ( *script_p != 0 );
      if ( *script_p == 0 )
        break;
    }
  }
  v4 = script_p - script->script_p;
  v5 = (unsigned __int8 *)MemAlloc_Alloc(nSize: v4 + 1);
  v1->buffer = (char *)v5;
  memcpy(dst: v5, src: (unsigned __int8 *)script->script_p, count: v4);
  v1->buffer[v4] = 0;
  v1->end_p = &v1->buffer[v4];
  v6 = nummacros;
  v7 = script;
  macrolist[nummacros] = v1;
  nummacros = v6 + 1;
  v7->script_p = script_p;
}

//------------------------------------------------------------------------------
// Address: 0x1004B450
// Name: bool ExpandVariableToken(char __near * __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl ExpandVariableToken(char **token_p)
{
  char *script_p; // ebx
  const char *v2; // ebx
  char *v3; // esi
  char v4; // al
  int v6; // esi
  int v7; // edi
  void (*v8)(const char *, ...); // ebx
  char *value; // edi
  unsigned int v10; // eax
  char *v11; // edx
  _BYTE *v12; // esi
  char v13; // cl
  const char *v14; // [esp-10h] [ebp-18h]
  char *cp; // [esp+4h] [ebp-4h]

  script_p = script->script_p;
  if ( *script_p != 36 )
    return 0;
  v2 = script_p + 1;
  v3 = (char *)v2;
  v4 = *v2;
  cp = (char *)v2;
  if ( *v2 <= 32 )
  {
LABEL_6:
    if ( *v3 != 36 )
      return 0;
  }
  else
  {
    while ( v4 != 36 )
    {
      v4 = *++v3;
      if ( v4 <= 32 )
      {
        cp = v3;
        goto LABEL_6;
      }
    }
    cp = v3;
  }
  v6 = v3 - v2;
  v7 = 0;
  v2[v6] = 0;
  if ( g_definevariable.m_Size <= 0 )
    goto LABEL_14;
  while ( V_strnicmp(s1: g_definevariable.m_Memory.m_pMemory[v7].param, s2: v2, n: v6) != 0 )
  {
    if ( ++v7 >= g_definevariable.m_Size )
      goto LABEL_14;
  }
  if ( v7 < g_definevariable.m_Size )
  {
    v8 = (void (*)(const char *, ...))_Error;
  }
  else
  {
LABEL_14:
    v14 = v2;
    v8 = (void (*)(const char *, ...))_Error;
    _Error(a1: "unknown variable token \"%s\" in %s\n", v14, script->filename);
  }
  value = g_definevariable.m_Memory.m_pMemory[v7].value;
  v10 = strlen(value);
  v11 = value;
  v12 = *token_p;
  do
  {
    v13 = *v11;
    *v12++ = *v11++;
  }
  while ( v13 != 0 );
  *token_p += v10;
  script->script_p = cp + 1;
  if ( script->script_p >= script->end_p )
    v8(a1: "Macro expand overflow\n");
  if ( *token_p >= (char *)&nummacros )
    v8(a1: "Token too large on line %i\n", scriptline);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1004B580
// Name: public: int CUtlVector<struct variable_t,class CUtlMemory<struct variable_t,int>>::InsertBefore(int,struct variable_t const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<variable_t,CUtlMemory<variable_t,int>>::InsertBefore(
        CUtlVector<unsigned __int64,CUtlMemory<unsigned __int64,int> > *this,
        int elem,
        unsigned __int64 *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  unsigned __int64 *m_pMemory; // ecx
  int v7; // eax
  unsigned __int64 *v8; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CacheOptimizedKDNode,int>::Grow(
      (CUtlMemory<ResourceEntryInfo,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 8 * v7);
  v8 = &this->m_Memory.m_pMemory[elem];
  if ( v8 != nullptr )
    *v8 = *src;
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x1004B5F0
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
    CUtlMemory<UtlLinkedListElem_t<CWorkUnitInfo,int>,int>::Grow(
      (CUtlMemory<CWorkUnitWalker::CWorkerInfo,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
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
// Address: 0x1004B660
// Name: void DefineVariable(char __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DefineVariable(char *variablename)
{
  char *v1; // eax
  char *v2; // eax
  char *v3; // ecx
  char v4; // dl
  variable_t v; // [esp+8h] [ebp-8h] BYREF

  if ( variablename != nullptr
    && (v1 = (char *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: strlen(variablename) + 1)) != nullptr )
  {
    strcpy(v1, variablename);
  }
  else
  {
    v1 = nullptr;
  }
  v.param = v1;
  GetToken(crossline: 0);
  v2 = (char *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: strlen(token) + 1);
  if ( v2 != nullptr )
  {
    v3 = v2;
    do
    {
      v4 = v3[token - v2];
      *v3++ = v4;
    }
    while ( v4 != 0 );
  }
  else
  {
    v2 = nullptr;
  }
  v.value = v2;
  CUtlVector<variable_t,CUtlMemory<variable_t,int>>::InsertBefore(
    this: (CUtlVector<unsigned __int64,CUtlMemory<unsigned __int64,int> > *)&g_definevariable,
    elem: g_definevariable.m_Size,
    src: (unsigned __int64 *)&v);
}

//------------------------------------------------------------------------------
// Address: 0x1004B720
// Name: int GetToken(int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl GetToken(int crossline)
{
  script_t *v1; // eax
  char *script_p; // ecx
  char v3; // dl
  script_t *v4; // eax
  char *v5; // ecx
  char *v6; // edx
  char v7; // cl
  char *v8; // ecx
  char v9; // dl
  script_t *v10; // eax
  char *v11; // edx
  script_t *v12; // eax
  int line; // edx
  char v14; // cl
  char *v15; // esi
  script_t *v16; // eax
  char i; // cl
  char *v18; // esi
  char *v19; // ecx
  char *token_p; // [esp+Ch] [ebp-4h] BYREF

  if ( tokenready != 0 )
  {
LABEL_54:
    tokenready = 0;
    return 1;
  }
  else
  {
    while ( 1 )
    {
      v1 = script;
      if ( script->script_p >= script->end_p )
        return EndOfScript(crossline);
      tokenready = 0;
      while ( 1 )
      {
        while ( 1 )
        {
          if ( *v1->script_p <= 32 )
          {
            do
            {
              script_p = v1->script_p;
              if ( script_p >= v1->end_p )
                return EndOfScript(crossline);
              v3 = *script_p;
              v1->script_p = script_p + 1;
              if ( v3 == 10 )
              {
                if ( crossline == 0 )
                  _Error(a1: "Line %i is incomplete\n", scriptline);
                v4 = script;
                ++script->line;
                scriptline = v4->line;
              }
              v1 = script;
            }
            while ( *script->script_p <= 32 );
          }
          v5 = v1->script_p;
          if ( v5 >= v1->end_p )
            return EndOfScript(crossline);
          v6 = v1->script_p;
          v7 = *v5;
          if ( v7 != 59 && v7 != 35 )
          {
            if ( v7 != 47 )
              goto LABEL_30;
            if ( v6[1] != 47 )
              break;
          }
          if ( crossline == 0 )
          {
            _Error(a1: "Line %i is incomplete\n", scriptline);
            v1 = script;
          }
          if ( *v1->script_p != 10 )
          {
            do
            {
              ++v1->script_p;
              v1 = script;
              v11 = script->script_p;
              if ( v11 >= script->end_p )
                return EndOfScript(crossline);
            }
            while ( *v11 != 10 );
          }
          ++v1->script_p;
          v12 = script;
          ++script->line;
          line = v12->line;
          v1 = script;
          scriptline = line;
        }
        if ( v6[1] != 42 )
          break;
        v1->script_p += 2;
        while ( 1 )
        {
          v8 = script->script_p;
          if ( *v8 == 42 && v8[1] == 47 )
            break;
          v9 = *v8;
          script->script_p = v8 + 1;
          if ( v9 != 10 )
          {
            v10 = script;
            if ( script->script_p >= script->end_p )
              return EndOfScript(crossline);
            ++script->line;
            scriptline = v10->line;
          }
        }
        script->script_p += 2;
        v1 = script;
      }
LABEL_30:
      v14 = *v6;
      v15 = token;
      token_p = token;
      if ( v14 == 34 )
      {
        ++v1->script_p;
        v16 = script;
        for ( i = *script->script_p; i != 34; i = *v16->script_p )
        {
          *v15 = i;
          ++script->script_p;
          v16 = script;
          ++v15;
          if ( script->script_p == script->end_p )
            break;
          if ( v15 == (char *)&nummacros )
          {
            _Error(a1: "Token too large on line %i\n", scriptline);
            v16 = script;
          }
        }
        ++v16->script_p;
      }
      else
      {
        for ( ; v14 > 32; v14 = *script->script_p )
        {
          if ( v14 == 59 )
            break;
          if ( ExpandMacroToken(&token_p) != 0 || ExpandVariableToken(&token_p) != 0 )
          {
            v15 = token_p;
          }
          else
          {
            v18 = token_p;
            *token_p = *script->script_p++;
            v19 = script->script_p;
            v15 = v18 + 1;
            token_p = v15;
            if ( v19 == script->end_p )
              break;
            if ( v15 == (char *)&nummacros )
              _Error(a1: "Token too large on line %i\n", scriptline);
          }
        }
      }
      *v15 = 0;
      if ( _V_stricmp(s1: token, s2: "$include") != 0 )
      {
        if ( _V_stricmp(s1: token, s2: "$definemacro") != 0 )
        {
          if ( _V_stricmp(s1: token, s2: "$definevariable") != 0 )
          {
            if ( AddMacroToStack(macroname: token) == 0 )
              return 1;
          }
          else
          {
            GetToken(crossline: 0);
            DefineVariable(variablename: token);
          }
        }
        else
        {
          GetToken(crossline: 0);
          DefineMacro(macroname: token);
        }
      }
      else
      {
        GetToken(crossline: 0);
        AddScriptToStack(filename: token, pathMode: SCRIPT_USE_ABSOLUTE_PATH);
      }
      if ( tokenready != 0 )
        goto LABEL_54;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004BB20
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
    CUtlMemory<clusterlist_t,int>::Grow(
      (CUtlMemory<UtlLinkedListElem_t<unsigned __int64,unsigned __int64>,unsigned __int64> *)this,
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
// Address: 0x1004BB90
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
    CUtlMemory<clusterlist_t,int>::Grow(
      (CUtlMemory<UtlLinkedListElem_t<unsigned __int64,unsigned __int64>,unsigned __int64> *)this,
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
// Address: 0x1004BC30
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
// Address: 0x1004BCA0
// Name: private: int CScriptLib::GetFileList(char const __near *,char const __near *,class CUtlVector<struct fileList_t,class CUtlMemory<struct fileList_t,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CScriptLib::GetFileList(
        CScriptLib *this,
        const char *pDirPath,
        const char *pPattern,
        CUtlVector<fileList_t,CUtlMemory<fileList_t,int> > *fileList)
{
  unsigned int v5; // kr00_4
  int v6; // eax
  char v7; // cl
  char *v8; // edi
  char v9; // al
  unsigned int v10; // eax
  char *v11; // edi
  char v12; // cl
  int v13; // esi
  int v15; // eax
  char v16; // cl
  unsigned int v17; // eax
  char *v18; // edi
  char v19; // cl
  char *v20; // edi
  char *v21; // esi
  char v22; // cl
  int m_Size; // eax
  int v24; // esi
  char v25; // [esp+Bh] [ebp-435h] BYREF
  char fileName[260]; // [esp+Ch] [ebp-434h] BYREF
  char fullPath[260]; // [esp+110h] [ebp-330h] BYREF
  _finddata64i32_t findData; // [esp+214h] [ebp-22Ch] BYREF
  char sourcePath[260]; // [esp+33Ch] [ebp-104h] BYREF
  int h; // [esp+448h] [ebp+8h]
  char bFindDirs_3; // [esp+453h] [ebp+13h]

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
  v5 = strlen(sourcePath);
  if ( v5 != 0 )
  {
    if ( findData.name[v5 + 259] != 92 )
    {
      sourcePath[v5] = 92;
      sourcePath[v5 + 1] = 0;
    }
  }
  else
  {
    strcpy(sourcePath, ".\\");
  }
  v6 = 0;
  do
  {
    v7 = sourcePath[v6];
    fullPath[v6++] = v7;
  }
  while ( v7 != 0 );
  if ( *pPattern != 92 || pPattern[1] != 0 )
  {
    bFindDirs_3 = 0;
    v10 = strlen(pPattern) + 1;
    v11 = &fileName[259];
    do
      v12 = *++v11;
    while ( v12 != 0 );
    qmemcpy(v11, pPattern, v10);
  }
  else
  {
    bFindDirs_3 = 1;
    v8 = &fileName[259];
    do
      v9 = *++v8;
    while ( v9 != 0 );
    strcpy(v8, "*");
  }
  v13 = _findfirst64i32(szWild: fullPath, pfd: &findData);
  h = v13;
  if ( v13 == -1 )
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
      v15 = 0;
      do
      {
        v16 = sourcePath[v15];
        fileName[v15++] = v16;
      }
      while ( v16 != 0 );
      v17 = strlen(findData.name) + 1;
      v18 = &v25;
      do
        v19 = *++v18;
      while ( v19 != 0 );
      qmemcpy(v18, findData.name, 4 * (v17 >> 2));
      v21 = &findData.name[4 * (v17 >> 2)];
      v20 = &v18[4 * (v17 >> 2)];
      v22 = v17;
      m_Size = fileList->m_Size;
      qmemcpy(v20, v21, v22 & 3);
      v24 = CUtlVector<fileList_t,CUtlMemory<fileList_t,int>>::InsertBefore(this: fileList, elem: m_Size);
      CUtlString::Set(this: &fileList->m_Memory.m_pMemory[v24].fileName, pValue: fileName);
      fileList->m_Memory.m_pMemory[v24].timeWrite = findData.time_write;
      v13 = h;
    }
  }
  while ( _findnext64i32(hFile: v13, pfd: &findData) == 0 );
  _findclose(hFile: v13);
  return fileList->m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x1004BF00
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
// Address: 0x1004BF60
// Name: public: virtual void CScriptLib::DeleteTemporaryFiles(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CScriptLib::DeleteTemporaryFiles(CScriptLib *this, const char *pFileMask)
{
  char *v2; // eax
  char *v3; // edx
  char v4; // cl
  unsigned int v5; // eax
  char *v6; // edi
  char v7; // cl
  int (__thiscall *FindFiles)(struct CScriptLib *, char *, bool, CUtlVector<fileList_t,CUtlMemory<fileList_t,int> > *); // edx
  int v9; // esi
  int v10; // edi
  const char *v11; // eax
  fileList_t *m_pMemory; // eax
  char v13; // [esp+3h] [ebp-11Dh] BYREF
  char tempPath[260]; // [esp+4h] [ebp-11Ch] BYREF
  CScriptLib *v15; // [esp+108h] [ebp-18h]
  CUtlVector<fileList_t,CUtlMemory<fileList_t,int> > fileList; // [esp+10Ch] [ebp-14h] BYREF

  v15 = this;
  v2 = getenv(option: "temp");
  if ( v2 != nullptr || (v2 = getenv(option: "tmp")) != nullptr )
  {
    v3 = (char *)(tempPath - v2);
    do
    {
      v4 = *v2;
      v2[(_DWORD)v3] = *v2;
      ++v2;
    }
    while ( v4 != 0 );
    V_AppendSlash(pStr: tempPath, strSize: 260);
    v5 = strlen(pFileMask) + 1;
    v6 = &v13;
    do
      v7 = *++v6;
    while ( v7 != 0 );
    qmemcpy(v6, pFileMask, v5);
    FindFiles = v15->FindFiles;
    memset(&fileList, 0, sizeof(fileList));
    FindFiles(this: v15, a2: tempPath, a3: false, a4: &fileList);
    v9 = 0;
    if ( fileList.m_Size > 0 )
    {
      v10 = 0;
      do
      {
        v11 = CUtlString::Get(this: &fileList.m_Memory.m_pMemory[v10].fileName);
        _unlink(path: v11);
        ++v9;
        ++v10;
      }
      while ( v9 < fileList.m_Size );
    }
    CUtlVector<fileList_t,CUtlMemory<fileList_t,int>>::RemoveAll(this: &fileList);
    m_pMemory = fileList.m_Memory.m_pMemory;
    if ( fileList.m_Memory.m_nGrowSize >= 0 )
    {
      if ( fileList.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: fileList.m_Memory.m_pMemory);
        m_pMemory = nullptr;
        fileList.m_Memory.m_pMemory = nullptr;
      }
      fileList.m_Memory.m_nAllocationCount = 0;
    }
    fileList.m_pElements = m_pMemory;
    if ( fileList.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004C090
// Name: private: void CScriptLib::RecurseFileTree_r(char const __near *,int,class CUtlVector<class CUtlString,class CUtlMemory<class CUtlString,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CScriptLib::RecurseFileTree_r(
        CScriptLib *this,
        const char *pDirPath,
        int depth,
        CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *dirList)
{
  fileList_t *i; // ebx
  int v5; // eax
  int v6; // eax
  fileList_t *m_pMemory; // edi
  const char *v8; // eax
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CUtlString *v11; // ecx
  int v12; // eax
  int v13; // edi
  CUtlString *v14; // ecx
  CUtlVector<fileList_t,CUtlMemory<fileList_t,int> > fileList; // [esp+Ch] [ebp-18h] BYREF
  CScriptLib *v16; // [esp+20h] [ebp-4h]

  i = nullptr;
  v16 = this;
  memset(&fileList, 0, sizeof(fileList));
  v5 = CScriptLib::GetFileList(this, pDirPath, pPattern: "\\", &fileList);
  if ( v5 != 0 )
  {
    if ( v5 > 0 )
    {
      m_pMemory = fileList.m_Memory.m_pMemory;
      for ( i = (fileList_t *)v5; i != nullptr; i = (fileList_t *)((char *)i - 1) )
      {
        v8 = CUtlString::Get(this: &m_pMemory->fileName);
        CScriptLib::RecurseFileTree_r(this: v16, pDirPath: v8, depth: depth + 1, dirList);
        ++m_pMemory;
      }
    }
    m_Size = dirList->m_Size;
    m_nAllocationCount = dirList->m_Memory.m_nAllocationCount;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<UtlLinkedListElem_t<CWorkUnitInfo,int>,int>::Grow(
        this: (CUtlMemory<CWorkUnitWalker::CWorkerInfo,int> *)dirList,
        num: m_Size - m_nAllocationCount + 1);
    ++dirList->m_Size;
    v11 = dirList->m_Memory.m_pMemory;
    v12 = dirList->m_Size - m_Size - 1;
    dirList->m_pElements = dirList->m_Memory.m_pMemory;
    if ( v12 > (int)i )
      _V_memmove(dest: &v11[m_Size + 1], src: &v11[m_Size], count: 16 * v12);
    v13 = m_Size;
    v14 = &dirList->m_Memory.m_pMemory[v13];
    if ( v14 != nullptr )
      CUtlString::CUtlString(this: v14);
    CUtlString::Set(this: &dirList->m_Memory.m_pMemory[v13], pValue: pDirPath);
    CUtlVector<fileList_t,CUtlMemory<fileList_t,int>>::RemoveAll(this: &fileList);
    if ( fileList.m_Memory.m_nGrowSize >= (int)i && fileList.m_Memory.m_pMemory != i )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: fileList.m_Memory.m_pMemory);
  }
  else
  {
    v6 = CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>::InsertBefore(this: dirList, elem: dirList->m_Size);
    CUtlString::Set(this: &dirList->m_Memory.m_pMemory[v6], pValue: pDirPath);
    CUtlVector<fileList_t,CUtlMemory<fileList_t,int>>::~CUtlVector<fileList_t,CUtlMemory<fileList_t,int>>(this: &fileList);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004C1B0
// Name: public: virtual int CScriptLib::FindFiles(char __near *,bool,class CUtlVector<struct fileList_t,class CUtlMemory<struct fileList_t,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CScriptLib::FindFiles(
        CScriptLib *this,
        char *pFileMask,
        bool bRecurse,
        CUtlVector<fileList_t,CUtlMemory<fileList_t,int> > *fileList)
{
  CScriptLib *v4; // edi
  char *v5; // edi
  char v6; // al
  unsigned int v7; // eax
  char *v8; // edi
  char v9; // cl
  int m_nGrowSize; // esi
  fileList_t *m_pMemory; // eax
  const char *v13; // eax
  CUtlVector<fileList_t,CUtlMemory<fileList_t,int> > *v14; // esi
  int m_Size; // edi
  int inserted; // eax
  fileList_t *v17; // edi
  int v18; // ebx
  CUtlString *p_fileName; // esi
  int timeWrite_high; // eax
  bool v21; // zf
  CUtlString *v22; // eax
  unsigned int v23; // [esp-8h] [ebp-34Ch]
  char extension[260]; // [esp+8h] [ebp-33Ch] BYREF
  char dirPath[260]; // [esp+10Ch] [ebp-238h] BYREF
  char pattern[260]; // [esp+210h] [ebp-134h] BYREF
  CScriptLib *v27; // [esp+314h] [ebp-30h]
  int i; // [esp+318h] [ebp-2Ch]
  CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > dirList; // [esp+31Ch] [ebp-28h] BYREF
  CUtlVector<fileList_t,CUtlMemory<fileList_t,int> > tempList; // [esp+330h] [ebp-14h] BYREF
  char *pFileMaska; // [esp+34Ch] [ebp+8h]
  int bRecursea; // [esp+350h] [ebp+Ch]

  v4 = this;
  v27 = this;
  strcpy(dirPath, pFileMask);
  V_StripFilename(path: dirPath);
  V_FileBase(in: pFileMask, out: pattern, maxlen: 260);
  V_ExtractFileExtension(path: pFileMask, dest: extension, destSize: 260);
  if ( extension[0] != 0 )
  {
    v5 = &dirPath[259];
    do
      v6 = *++v5;
    while ( v6 != 0 );
    strcpy(v5, ".");
    v7 = strlen(extension) + 1;
    v8 = &dirPath[259];
    do
      v9 = *++v8;
    while ( v9 != 0 );
    qmemcpy(v8, extension, v7);
    v4 = v27;
  }
  if ( bRecurse )
  {
    memset(&tempList, 0, sizeof(tempList));
    memset(&dirList, 0, sizeof(dirList));
    CScriptLib::RecurseFileTree_r(this: v4, pDirPath: dirPath, depth: 0, &dirList);
    i = 0;
    if ( dirList.m_Size > 0 )
    {
      bRecursea = 0;
      while ( 1 )
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
          v23 = 24 * dirList.m_Size;
          if ( m_pMemory != nullptr )
            m_pMemory = (fileList_t *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v23);
          else
            m_pMemory = (fileList_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v23);
          tempList.m_Memory.m_pMemory = m_pMemory;
        }
        tempList.m_pElements = m_pMemory;
        v13 = CUtlString::Get(this: &dirList.m_Memory.m_pMemory[bRecursea]);
        CScriptLib::GetFileList(this: v4, pDirPath: v13, pPattern: pattern, fileList: &tempList);
        v14 = fileList;
        m_Size = tempList.m_Size;
        inserted = CUtlVector<fileList_t,CUtlMemory<fileList_t,int>>::InsertMultipleBefore(
                     this: fileList,
                     elem: fileList->m_Size,
                     num: tempList.m_Size);
        if ( m_Size > 0 )
        {
          v17 = tempList.m_Memory.m_pMemory;
          v18 = inserted;
          pFileMaska = (char *)tempList.m_Size;
          while ( 1 )
          {
            p_fileName = &v14->m_Memory.m_pMemory[v18].fileName;
            CUtlString::operator=(this: p_fileName, src: &v17->fileName);
            p_fileName[1].m_Storage.m_Memory.m_pMemory = (unsigned __int8 *)v17->timeWrite;
            timeWrite_high = HIDWORD(v17->timeWrite);
            ++v17;
            ++v18;
            v21 = pFileMaska-- == (char *)1;
            p_fileName[1].m_Storage.m_Memory.m_nAllocationCount = timeWrite_high;
            if ( v21 )
              break;
            v14 = fileList;
          }
        }
        ++bRecursea;
        if ( ++i >= dirList.m_Size )
          break;
        v4 = v27;
      }
    }
    CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>::RemoveAll(this: &dirList);
    v22 = dirList.m_Memory.m_pMemory;
    if ( dirList.m_Memory.m_nGrowSize >= 0 )
    {
      if ( dirList.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: dirList.m_Memory.m_pMemory);
        v22 = nullptr;
        dirList.m_Memory.m_pMemory = nullptr;
      }
      dirList.m_Memory.m_nAllocationCount = 0;
    }
    dirList.m_pElements = v22;
    if ( dirList.m_Memory.m_nGrowSize >= 0 )
    {
      if ( v22 != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v22);
        dirList.m_Memory.m_pMemory = nullptr;
      }
      dirList.m_Memory.m_nAllocationCount = 0;
    }
    CUtlVector<fileList_t,CUtlMemory<fileList_t,int>>::RemoveAll(this: &tempList);
    if ( tempList.m_Memory.m_nGrowSize < 0 )
    {
      return fileList->m_Size;
    }
    else
    {
      if ( tempList.m_Memory.m_pMemory != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: tempList.m_Memory.m_pMemory);
      return fileList->m_Size;
    }
  }
  else
  {
    CScriptLib::GetFileList(this: v4, pDirPath: dirPath, pPattern: pattern, fileList);
    return fileList->m_Size;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10079E80
// Name: public: int CUtlVector<struct CacheOptimizedTriangle,class CUtlBlockMemory<struct CacheOptimizedTriangle,int>>::InsertBefore(int,struct CacheOptimizedTriangle const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CacheOptimizedTriangle,CUtlBlockMemory<CacheOptimizedTriangle,int>>::InsertBefore(
        CUtlVector<CacheOptimizedTriangle,CUtlBlockMemory<CacheOptimizedTriangle,int> > *this,
        int elem,
        const CacheOptimizedTriangle *src)
{
  int m_nBlocks; // ebx
  int m_Size; // eax
  int v6; // edi
  int v7; // eax
  int v8; // edx
  int v9; // eax
  CacheOptimizedTriangle *v10; // eax

  m_nBlocks = this->m_Memory.m_nBlocks;
  m_Size = this->m_Size;
  v6 = ((32 * *((_DWORD *)&this->m_Memory + 2)) >> 5) + 1;
  if ( m_Size + 1 > v6 * m_nBlocks )
  {
    v7 = m_Size - v6 * m_nBlocks + 1;
    if ( v7 > 0 )
      CUtlBlockMemory<CacheOptimizedTriangle,int>::ChangeSize(
        this: &this->m_Memory,
        nBlocks: m_nBlocks + (v6 + v7 - 1) / v6);
  }
  v8 = ++this->m_Size - elem - 1;
  this->m_pElements = nullptr;
  if ( v8 > 0 )
  {
    v9 = *((_DWORD *)&this->m_Memory + 2);
    _V_memmove(
      dest: &this->m_Memory.m_pMemory[(elem + 1) >> (v9 >> 27)][(elem + 1) & ((32 * v9) >> 5)],
      src: &this->m_Memory.m_pMemory[elem >> (v9 >> 27)][elem & ((32 * v9) >> 5)],
      count: 48 * v8);
  }
  v10 = &this->m_Memory.m_pMemory[elem >> (*((int *)&this->m_Memory + 2) >> 27)][elem
                                                                               & ((32 * *((_DWORD *)&this->m_Memory + 2)) >> 5)];
  if ( v10 != nullptr )
    *v10 = *src;
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x1008D100
// Name: public: void CUtlMemory<class CIPAddr,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<CIPAddr,int>::Grow(CUtlMemory<CMasterMulticastThread::CChunkInfo,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  CMasterMulticastThread::CChunkInfo *m_pMemory; // edx
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
        m_nAllocationCount = 6;
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
    v7 = 6 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (CMasterMulticastThread::CChunkInfo *)_g_pMemAlloc->Realloc_2(
                                                                this: _g_pMemAlloc,
                                                                a2: m_pMemory,
                                                                a3: v7);
    else
      this->m_pMemory = (CMasterMulticastThread::CChunkInfo *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1008DB90
// Name: public: int CUtlVector<class CMasterMulticastThread::CChunkInfo,class CUtlMemory<class CMasterMulticastThread::CChunkInfo,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CMasterMulticastThread::CChunkInfo,CUtlMemory<CMasterMulticastThread::CChunkInfo,int>>::InsertMultipleBefore(
        CUtlVector<CMasterMulticastThread::CChunkInfo,CUtlMemory<CMasterMulticastThread::CChunkInfo,int> > *this,
        int elem,
        int num)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CMasterMulticastThread::CChunkInfo *m_pMemory; // ecx
  int v8; // eax
  int v9; // eax

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<CIPAddr,int>::Grow(this: &this->m_Memory, num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v8 = this->m_Size;
  this->m_pElements = this->m_Memory.m_pMemory;
  v9 = v8 - elem - num;
  if ( v9 > 0 && num > 0 )
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 6 * v9);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x1008DE60
// Name: public: int CUtlVector<class CTransmitRateMgr::CMachineRecord,class CUtlMemory<class CTransmitRateMgr::CMachineRecord,int>>::AddToTail(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CTransmitRateMgr::CMachineRecord,CUtlMemory<CTransmitRateMgr::CMachineRecord,int>>::AddToTail(
        CUtlVector<CTransmitRateMgr::CMachineRecord,CUtlMemory<CTransmitRateMgr::CMachineRecord,int> > *this)
{
  int m_nAllocationCount; // eax
  int m_Size; // edi
  CTransmitRateMgr::CMachineRecord *m_pMemory; // ecx
  int v5; // eax

  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  m_Size = this->m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CacheOptimizedKDNode,int>::Grow(
      (CUtlMemory<ResourceEntryInfo,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v5 = this->m_Size - m_Size - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v5 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 8 * v5);
  return m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x10091B40
// Name: public: void CUtlMemory<struct UtlLinkedListElem_t<class CWorkUnitInfo,int>,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<UtlLinkedListElem_t<CWorkUnitInfo,int>,int>::Grow(
        CUtlMemory<CWorkUnitWalker::CWorkerInfo,int> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  CWorkUnitWalker::CWorkerInfo *m_pMemory; // edx
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
      this->m_pMemory = (CWorkUnitWalker::CWorkerInfo *)_g_pMemAlloc->Realloc_2(
                                                          this: _g_pMemAlloc,
                                                          a2: m_pMemory,
                                                          a3: v7);
    else
      this->m_pMemory = (CWorkUnitWalker::CWorkerInfo *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100920E0
// Name: public: int CUtlVector<class CWUStatus,class CUtlMemory<class CWUStatus,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CWUStatus,CUtlMemory<CWUStatus,int>>::InsertMultipleBefore(
        CUtlVector<CWUStatus,CUtlMemory<CWUStatus,int> > *this,
        int elem,
        int num)
{
  int v3; // edi
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CWUStatus *m_pMemory; // ecx
  int v9; // eax
  int v10; // ecx
  CWUStatus *v11; // eax

  v3 = num;
  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<clusterlist_t,int>::Grow(
      (CUtlMemory<UtlLinkedListElem_t<unsigned __int64,unsigned __int64>,unsigned __int64> *)this,
      num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v9 = this->m_Size - elem - num;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v9 > 0 && num > 0 )
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 24 * v9);
  if ( num > 0 )
  {
    v10 = elem;
    do
    {
      v11 = &this->m_Memory.m_pMemory[v10];
      if ( v11 != nullptr )
      {
        v11->m_iState = 0;
        *(_QWORD *)&v11->m_Rect.left = 0;
        *(_QWORD *)&v11->m_Rect.right = 0;
      }
      ++v10;
      --v3;
    }
    while ( v3 != 0 );
  }
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x10092190
// Name: public: CUtlVector<struct dleafambientlighting_t,class CUtlMemory<struct dleafambientlighting_t,int>>::~CUtlVector<struct dleafambientlighting_t,class CUtlMemory<struct dleafambientlighting_t,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<dleafambientlighting_t,CUtlMemory<dleafambientlighting_t,int>>::~CUtlVector<dleafambientlighting_t,CUtlMemory<dleafambientlighting_t,int>>(
        CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *this)
{
  bool v2; // sf
  CVTFTexture::ResourceMemorySection *m_pMemory; // eax

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
// Address: 0x10092200
// Name: public: int CUtlVector<class CWorkUnitEvent,class CUtlMemory<class CWorkUnitEvent,int>>::InsertBefore(int,class CWorkUnitEvent const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CWorkUnitEvent,CUtlMemory<CWorkUnitEvent,int>>::InsertBefore(
        CUtlVector<CWorkUnitEvent,CUtlMemory<CWorkUnitEvent,int> > *this,
        int elem,
        const CWorkUnitEvent *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CWorkUnitEvent *m_pMemory; // ecx
  int v7; // eax
  CWorkUnitEvent *v8; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<UtlLinkedListElem_t<CWorkUnitInfo,int>,int>::Grow(
      (CUtlMemory<CWorkUnitWalker::CWorkerInfo,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 16 * v7);
  v8 = &this->m_Memory.m_pMemory[elem];
  if ( v8 != nullptr )
    *v8 = *src;
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x100923D0
// Name: public: int CUtlVector<class CWorkUnit,class CUtlMemory<class CWorkUnit,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CWorkUnit,CUtlMemory<CWorkUnit,int>>::InsertMultipleBefore(
        CUtlVector<CWorkUnit,CUtlMemory<CWorkUnit,int> > *this,
        int elem,
        int num)
{
  int v3; // edi
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CWorkUnit *m_pMemory; // ecx
  int v9; // eax
  int v10; // ecx
  CWorkUnit *v11; // eax

  v3 = num;
  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<clusterlist_t,int>::Grow(
      (CUtlMemory<UtlLinkedListElem_t<unsigned __int64,unsigned __int64>,unsigned __int64> *)this,
      num: num + m_Size - m_nAllocationCount);
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
          v11->m_Events.m_Memory.m_pMemory = nullptr;
          v11->m_Events.m_Memory.m_nAllocationCount = 0;
          v11->m_Events.m_Memory.m_nGrowSize = 0;
          v11->m_Events.m_Size = 0;
          v11->m_Events.m_pElements = nullptr;
          v11->m_iWorkerCompleted = -1;
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
// Address: 0x100928E0
// Name: public: void CUtlVector<struct clusterlist_t,class CUtlMemory<struct clusterlist_t,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<clusterlist_t,CUtlMemory<clusterlist_t,int>>::RemoveAll(
        CUtlVector<CWorkUnit,CUtlMemory<CWorkUnit,int> > *this)
{
  int v1; // ebx
  int v2; // eax
  char *v3; // esi
  void *v4; // eax
  int v5; // [esp+4h] [ebp-8h]
  CUtlVector<CWorkUnit,CUtlMemory<CWorkUnit,int> > *v6; // [esp+8h] [ebp-4h]

  v1 = this->m_Size - 1;
  v6 = this;
  if ( v1 < 0 )
  {
    this->m_Size = 0;
  }
  else
  {
    v2 = 24 * v1;
    v5 = 24 * v1;
    do
    {
      v3 = (char *)this->m_Memory.m_pMemory + v2;
      *((_DWORD *)v3 + 4) = 0;
      if ( *((int *)v3 + 3) >= 0 )
      {
        if ( *((_DWORD *)v3 + 1) != 0 )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *((void **)v3 + 1));
          this = v6;
          *((_DWORD *)v3 + 1) = 0;
        }
        *((_DWORD *)v3 + 2) = 0;
      }
      v4 = *((void **)v3 + 1);
      *((_DWORD *)v3 + 5) = v4;
      if ( *((int *)v3 + 3) >= 0 )
      {
        if ( v4 != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v4);
          this = v6;
          *((_DWORD *)v3 + 1) = 0;
        }
        *((_DWORD *)v3 + 2) = 0;
      }
      --v1;
      v2 = v5 - 24;
      v5 -= 24;
    }
    while ( v1 >= 0 );
    this->m_Size = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100932D0
// Name: public: int CUtlVector<class CWULookupInfo,class CUtlMemory<class CWULookupInfo,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CWULookupInfo,CUtlMemory<CWULookupInfo,int>>::InsertMultipleBefore(
        CUtlVector<CWULookupInfo,CUtlMemory<CWULookupInfo,int> > *this,
        int elem,
        int num)
{
  int v3; // edi
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CWULookupInfo *m_pMemory; // ecx
  int v9; // eax
  int v10; // ecx
  CWULookupInfo *v11; // eax

  v3 = num;
  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<UtlLinkedListElem_t<CMasterMulticastThread::CMulticastFile *,int>,int>::Grow(
      (CUtlMemory<CVTFTexture::ResourceMemorySection,int> *)this,
      num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v9 = this->m_Size - elem - num;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v9 <= 0 )
    goto LABEL_8;
  if ( num > 0 )
  {
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 12 * v9);
LABEL_8:
    if ( num > 0 )
    {
      v10 = elem;
      do
      {
        v11 = &this->m_Memory.m_pMemory[v10];
        if ( v11 != nullptr )
        {
          v11->m_iWUInfo = -1;
          v11->m_iPartition = -222222;
          v11->m_iPartitionListIndex = -1;
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
// Address: 0x10095620
// Name: public: class CUtlMemory<struct UtlLinkedListElem_t<unsigned __int64,unsigned __int64>,unsigned __int64>::Iterator_t CUtlMemory<struct UtlLinkedListElem_t<unsigned __int64,unsigned __int64>,unsigned __int64>::Next(class CUtlMemory<struct UtlLinkedListElem_t<unsigned __int64,unsigned __int64>,unsigned __int64>::Iterator_t const __near &)const
// Source: json
//------------------------------------------------------------------------------
CUtlMemory<UtlLinkedListElem_t<unsigned __int64,unsigned __int64>,unsigned __int64>::Iterator_t *__thiscall CUtlMemory<UtlLinkedListElem_t<unsigned __int64,unsigned __int64>,unsigned __int64>::Next(
        CUtlMemory<UtlLinkedListElem_t<unsigned __int64,unsigned __int64>,unsigned __int64> *this,
        CUtlMemory<UtlLinkedListElem_t<unsigned __int64,unsigned __int64>,unsigned __int64>::Iterator_t *result,
        const CUtlMemory<UtlLinkedListElem_t<unsigned __int64,unsigned __int64>,unsigned __int64>::Iterator_t *it)
{
  if ( LODWORD(it->index) + 1 < 0 || LODWORD(it->index) + 1 >= this->m_nAllocationCount )
  {
    result->index = -1;
    return result;
  }
  else
  {
    result->index = it->index + 1;
    return result;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10095DD0
// Name: public: int CUtlVector<class CWorkUnitWalker::CWorkerInfo,class CUtlMemory<class CWorkUnitWalker::CWorkerInfo,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CWorkUnitWalker::CWorkerInfo,CUtlMemory<CWorkUnitWalker::CWorkerInfo,int>>::InsertMultipleBefore(
        CUtlVector<CWorkUnitWalker::CWorkerInfo,CUtlMemory<CWorkUnitWalker::CWorkerInfo,int> > *this,
        int elem,
        int num)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CWorkUnitWalker::CWorkerInfo *m_pMemory; // ecx
  int v8; // eax
  int v9; // eax

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<UtlLinkedListElem_t<CWorkUnitInfo,int>,int>::Grow(
      this: &this->m_Memory,
      num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v8 = this->m_Size;
  this->m_pElements = this->m_Memory.m_pMemory;
  v9 = v8 - elem - num;
  if ( v9 > 0 && num > 0 )
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 16 * v9);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x10096630
// Name: public: int CUtlVector<unsigned __int64,class CUtlMemory<unsigned __int64,int>>::InsertMultipleBefore(int,int,unsigned __int64 const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<unsigned __int64,CUtlMemory<unsigned __int64,int>>::InsertMultipleBefore(
        CUtlVector<unsigned __int64,CUtlMemory<unsigned __int64,int> > *this,
        int elem,
        int num,
        const unsigned __int64 *pToInsert)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  unsigned __int64 *m_pMemory; // ecx
  int v9; // ebx
  int v10; // eax
  int v11; // eax
  int v12; // edx
  unsigned __int64 *v13; // ecx

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<CacheOptimizedKDNode,int>::Grow(
      (CUtlMemory<ResourceEntryInfo,int> *)this,
      num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v9 = elem;
  v10 = this->m_Size - elem - num;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v10 > 0 && num > 0 )
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 8 * v10);
  if ( pToInsert != nullptr )
  {
    v11 = 0;
    if ( num > 0 )
    {
      v12 = elem;
      do
      {
        v13 = &this->m_Memory.m_pMemory[v12];
        if ( v13 != nullptr )
        {
          *(_DWORD *)v13 = pToInsert[v11];
          *((_DWORD *)v13 + 1) = HIDWORD(pToInsert[v11]);
          v9 = elem;
        }
        ++v11;
        ++v12;
      }
      while ( v11 < num );
    }
  }
  return v9;
}

//------------------------------------------------------------------------------
// Address: 0x100976B0
// Name: public: int CUtlVector<class CFileResponse,class CUtlMemory<class CFileResponse,int>>::InsertBefore(int,class CFileResponse const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CFileResponse,CUtlMemory<CFileResponse,int>>::InsertBefore(
        CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *this,
        int elem,
        const CVTFTexture::ResourceMemorySection *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CVTFTexture::ResourceMemorySection *m_pMemory; // ecx
  int v7; // eax
  CVTFTexture::ResourceMemorySection *v8; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<UtlLinkedListElem_t<CMasterMulticastThread::CMulticastFile *,int>,int>::Grow(
      this: &this->m_Memory,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 12 * v7);
  v8 = &this->m_Memory.m_pMemory[elem];
  if ( v8 != nullptr )
    *v8 = *src;
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x100A0D50
// Name: public: void CUtlVector<struct CVTFTexture::ResourceMemorySection,class CUtlMemory<struct CVTFTexture::ResourceMemorySection,int>>::EnsureCapacity(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int>>::EnsureCapacity(
        CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *this,
        int num)
{
  CVTFTexture::ResourceMemorySection *m_pMemory; // edx
  unsigned int v4; // eax
  CVTFTexture::ResourceMemorySection *v5; // eax

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
    v4 = 12 * num;
    if ( m_pMemory != nullptr )
    {
      this->m_Memory.m_pMemory = (CVTFTexture::ResourceMemorySection *)_g_pMemAlloc->Realloc_2(
                                                                         this: _g_pMemAlloc,
                                                                         a2: m_pMemory,
                                                                         a3: v4);
      goto LABEL_5;
    }
    v5 = (CVTFTexture::ResourceMemorySection *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v4);
    this->m_Memory.m_pMemory = v5;
    this->m_pElements = v5;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A0DC0
// Name: public: int CUtlVector<struct CVTFTexture::ResourceMemorySection,class CUtlMemory<struct CVTFTexture::ResourceMemorySection,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int>>::InsertMultipleBefore(
        CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *this,
        int elem,
        int num)
{
  int v3; // edi
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CVTFTexture::ResourceMemorySection *m_pMemory; // ecx
  int v9; // eax
  int v10; // ecx
  CVTFTexture::ResourceMemorySection *v11; // eax

  v3 = num;
  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<UtlLinkedListElem_t<CMasterMulticastThread::CMulticastFile *,int>,int>::Grow(
      this: &this->m_Memory,
      num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v9 = this->m_Size - elem - num;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v9 > 0 && num > 0 )
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 12 * v9);
  if ( num > 0 )
  {
    v10 = elem;
    do
    {
      v11 = &this->m_Memory.m_pMemory[v10];
      if ( v11 != nullptr )
      {
        *(_QWORD *)&v11->m_nDataAllocSize = 0;
        v11->m_pData = nullptr;
      }
      ++v10;
      --v3;
    }
    while ( v3 != 0 );
  }
  return elem;
}

} // namespace vrad_dll

// ============================================================
// Overlay from vvis_dll (Missing functions)
// ============================================================
namespace vvis_dll {

//------------------------------------------------------------------------------
// Address: 0x100043E0
// Name: public: void CUtlVector<char,class CUtlMemory<char,int>>::Purge(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<char,CUtlMemory<char,int>>::Purge(CUtlVector<char,CUtlMemory<char,int> > *this)
{
  bool v2; // sf
  char *m_pMemory; // ecx

  v2 = this->m_Memory.m_nGrowSize < 0;
  this->m_Size = 0;
  if ( v2 )
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
// Address: 0x10004580
// Name: public: int CUtlVector<char,class CUtlMemory<char,int>>::InsertMultipleBefore(int,int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<char,CUtlMemory<char,int>>::InsertMultipleBefore(
        CUtlVector<char,CUtlMemory<char,int> > *this,
        int elem,
        int num,
        const char *pToInsert)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  char *m_pMemory; // ecx
  int v9; // eax
  int i; // ecx
  char *v11; // eax

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<char,int>::Grow((CUtlMemory<unsigned char,int> *)this, num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v9 = this->m_Size - elem - num;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v9 > 0 && num > 0 )
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: v9);
  if ( pToInsert != nullptr )
  {
    for ( i = 0; i < num; ++i )
    {
      v11 = &this->m_Memory.m_pMemory[i + elem];
      if ( v11 != nullptr )
        *v11 = pToInsert[i];
    }
  }
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x10004610
// Name: public: int CUtlVector<struct texinfo_s,class CUtlMemory<struct texinfo_s,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<texinfo_s,CUtlMemory<texinfo_s,int>>::InsertMultipleBefore(
        CUtlVector<texinfo_s,CUtlMemory<texinfo_s,int> > *this,
        int elem,
        int num)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  texinfo_s *m_pMemory; // ecx
  int v8; // eax
  int v9; // eax

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<texinfo_s,int>::Grow(this: &this->m_Memory, num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v8 = this->m_Size;
  this->m_pElements = this->m_Memory.m_pMemory;
  v9 = v8 - elem - num;
  if ( v9 > 0 && num > 0 )
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 72 * v9);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x10004B80
// Name: public: int CUtlVector<struct doccluderdata_t,class CUtlMemory<struct doccluderdata_t,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<doccluderdata_t,CUtlMemory<doccluderdata_t,int>>::InsertMultipleBefore(
        CUtlVector<doccluderdata_t,CUtlMemory<doccluderdata_t,int> > *this,
        int elem,
        int num)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  doccluderdata_t *m_pMemory; // ecx
  int v8; // eax
  int v9; // eax

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<doccluderdata_t,int>::Grow(this: &this->m_Memory, num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v8 = this->m_Size;
  this->m_pElements = this->m_Memory.m_pMemory;
  v9 = v8 - elem - num;
  if ( v9 > 0 && num > 0 )
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 40 * v9);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x10004C00
// Name: public: int CUtlVector<struct doccluderpolydata_t,class CUtlMemory<struct doccluderpolydata_t,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<doccluderpolydata_t,CUtlMemory<doccluderpolydata_t,int>>::InsertMultipleBefore(
        CUtlVector<doccluderpolydata_t,CUtlMemory<doccluderpolydata_t,int> > *this,
        int elem,
        int num)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  doccluderpolydata_t *m_pMemory; // ecx
  int v8; // eax
  int v9; // eax

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<UtlLinkedListElem_t<CMasterMulticastThread::CMulticastFile *,int>,int>::Grow(
      (CUtlMemory<UtlLinkedListElem_t<CWorkerFile *,int>,int> *)this,
      num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v8 = this->m_Size;
  this->m_pElements = this->m_Memory.m_pMemory;
  v9 = v8 - elem - num;
  if ( v9 > 0 && num > 0 )
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 12 * v9);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x10004E00
// Name: public: int CUtlVector<struct dleafambientlighting_t,class CUtlMemory<struct dleafambientlighting_t,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<dleafambientlighting_t,CUtlMemory<dleafambientlighting_t,int>>::InsertMultipleBefore(
        CUtlVector<dleafambientlighting_t,CUtlMemory<dleafambientlighting_t,int> > *this,
        int elem,
        int num)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  dleafambientlighting_t *m_pMemory; // ecx
  int v8; // eax
  int v9; // eax

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<dleafambientlighting_t,int>::Grow(this: &this->m_Memory, num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v8 = this->m_Size;
  this->m_pElements = this->m_Memory.m_pMemory;
  v9 = v8 - elem - num;
  if ( v9 > 0 && num > 0 )
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 28 * v9);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x10004E90
// Name: public: int CUtlVector<class ddispinfo_t,class CUtlMemory<class ddispinfo_t,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<ddispinfo_t,CUtlMemory<ddispinfo_t,int>>::InsertMultipleBefore(
        CUtlVector<ddispinfo_t,CUtlMemory<ddispinfo_t,int> > *this,
        int elem,
        int num)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  ddispinfo_t *m_pMemory; // ecx
  int v8; // eax
  int v9; // eax

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<ddispinfo_t,int>::Grow(this: &this->m_Memory, num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v8 = this->m_Size;
  this->m_pElements = this->m_Memory.m_pMemory;
  v9 = v8 - elem - num;
  if ( v9 > 0 && num > 0 )
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 176 * v9);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x10004F10
// Name: public: int CUtlVector<class CDispVert,class CUtlMemory<class CDispVert,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CDispVert,CUtlMemory<CDispVert,int>>::InsertMultipleBefore(
        CUtlVector<CDispVert,CUtlMemory<CDispVert,int> > *this,
        int elem,
        int num)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CDispVert *m_pMemory; // ecx
  int v8; // eax
  int v9; // eax

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<CDispVert,int>::Grow(this: &this->m_Memory, num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v8 = this->m_Size;
  this->m_pElements = this->m_Memory.m_pMemory;
  v9 = v8 - elem - num;
  if ( v9 > 0 && num > 0 )
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 20 * v9);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x10004F90
// Name: public: int CUtlVector<unsigned short,class CUtlMemory<unsigned short,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<unsigned short,CUtlMemory<unsigned short,int>>::InsertMultipleBefore(
        CUtlVector<CFaceMacroTextureInfo,CUtlMemory<CFaceMacroTextureInfo,int> > *this,
        int elem,
        int num)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CFaceMacroTextureInfo *m_pMemory; // ecx
  int v8; // eax
  int v9; // eax

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<CFaceMacroTextureInfo,int>::Grow(this: &this->m_Memory, num: num + m_Size - m_nAllocationCount);
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
// Address: 0x10005000
// Name: public: int CUtlVector<class CDispMultiBlend,class CUtlMemory<class CDispMultiBlend,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CDispMultiBlend,CUtlMemory<CDispMultiBlend,int>>::InsertMultipleBefore(
        CUtlVector<CDispMultiBlend,CUtlMemory<CDispMultiBlend,int> > *this,
        int elem,
        int num)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CDispMultiBlend *m_pMemory; // ecx
  int v8; // eax
  int v9; // eax

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<CDispMultiBlend,int>::Grow(this: &this->m_Memory, num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v8 = this->m_Size;
  this->m_pElements = this->m_Memory.m_pMemory;
  v9 = v8 - elem - num;
  if ( v9 > 0 && num > 0 )
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 80 * v9);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x10005080
// Name: public: int CUtlVector<struct dfacebrushlist_t,class CUtlMemory<struct dfacebrushlist_t,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<dfacebrushlist_t,CUtlMemory<dfacebrushlist_t,int>>::InsertMultipleBefore(
        CUtlVector<CVMPIConnection *,CUtlMemory<CVMPIConnection *,int> > *this,
        int elem,
        int num)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CVMPIConnection **m_pMemory; // ecx
  int v8; // eax
  int v9; // eax

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<int,int>::Grow((CUtlMemory<CTCPPacket *,int> *)this, num: num + m_Size - m_nAllocationCount);
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
// Address: 0x10006280
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
      CUtlMemory<char,int>::Grow(this: &this->m_Memory, num: size - m_nAllocationCount);
    this->m_Size += size;
    m_pMemory = this->m_Memory.m_pMemory;
    v5 = this->m_Size - size;
    this->m_pElements = this->m_Memory.m_pMemory;
    if ( v5 > 0 && size > 0 )
      _V_memmove(dest: &m_pMemory[size], src: m_pMemory, count: v5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100062D0
// Name: public: CUtlVector<struct dleafambientlighting_t,class CUtlMemory<struct dleafambientlighting_t,int>>::~CUtlVector<struct dleafambientlighting_t,class CUtlMemory<struct dleafambientlighting_t,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<dleafambientlighting_t,CUtlMemory<dleafambientlighting_t,int>>::~CUtlVector<dleafambientlighting_t,CUtlMemory<dleafambientlighting_t,int>>(
        CUtlVector<CFileResponse,CUtlMemory<CFileResponse,int> > *this)
{
  bool v2; // sf
  CFileResponse *m_pMemory; // eax

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
// Address: 0x10008B10
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
// Address: 0x10008B80
// Name: public: int CUtlVector<struct clusterlist_t,class CUtlMemory<struct clusterlist_t,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<clusterlist_t,CUtlMemory<clusterlist_t,int>>::InsertMultipleBefore(
        CUtlVector<clusterlist_t,CUtlMemory<clusterlist_t,int> > *this,
        int elem,
        int num)
{
  int v3; // edi
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  clusterlist_t *m_pMemory; // ecx
  int v9; // eax
  int v10; // ecx
  clusterlist_t *v11; // eax

  v3 = num;
  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<clusterlist_t,int>::Grow(
      (CUtlMemory<UtlLinkedListElem_t<unsigned __int64,unsigned __int64>,unsigned __int64> *)this,
      num: num + m_Size - m_nAllocationCount);
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
          v11->leafs.m_Memory.m_pMemory = nullptr;
          v11->leafs.m_Memory.m_nAllocationCount = 0;
          v11->leafs.m_Memory.m_nGrowSize = 0;
          v11->leafs.m_Size = 0;
          v11->leafs.m_pElements = nullptr;
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
// Address: 0x1000A3F0
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
// Address: 0x1000EB60
// Name: public: void CUtlVector<char,class CUtlMemory<char,int>>::CopyArray(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<char,CUtlMemory<char,int>>::CopyArray(
        CUtlVector<char,CUtlMemory<char,int> > *this,
        const char *pArray,
        int size)
{
  int m_nAllocationCount; // eax
  char *m_pMemory; // ecx
  int v6; // eax
  int i; // eax

  this->m_Size = 0;
  if ( size != 0 )
  {
    m_nAllocationCount = this->m_Memory.m_nAllocationCount;
    if ( size > m_nAllocationCount )
      CUtlMemory<char,int>::Grow((CUtlMemory<unsigned char,int> *)this, num: size - m_nAllocationCount);
    this->m_Size += size;
    m_pMemory = this->m_Memory.m_pMemory;
    v6 = this->m_Size - size;
    this->m_pElements = this->m_Memory.m_pMemory;
    if ( v6 > 0 && size > 0 )
      _V_memmove(dest: &m_pMemory[size], src: m_pMemory, count: v6);
  }
  for ( i = 0; i < size; ++i )
    this->m_Memory.m_pMemory[i] = pArray[i];
}

//------------------------------------------------------------------------------
// Address: 0x10010A50
// Name: public: int CUtlVector<class CSPVert,class CUtlMemory<class CSPVert,int>>::AddVectorToTail(class CUtlVector<class CSPVert,class CUtlMemory<class CSPVert,int>> const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CSPVert,CUtlMemory<CSPVert,int>>::AddVectorToTail(
        CUtlVector<CSPVert,CUtlMemory<CSPVert,int> > *this,
        const CUtlVector<CSPVert,CUtlMemory<CSPVert,int> > *src)
{
  int m_Size; // ebx
  int v4; // edi
  CSPVert *m_pMemory; // edx
  int v6; // ebx
  int v7; // edx
  CSPVert *v8; // eax
  CSPVert *v9; // ecx
  int base; // [esp+Ch] [ebp-4h]

  m_Size = this->m_Size;
  v4 = src->m_Size;
  base = m_Size;
  CUtlMemory<CSPVert,int>::EnsureCapacity(this: &this->m_Memory, num: v4 + m_Size);
  m_pMemory = this->m_Memory.m_pMemory;
  this->m_Size += v4;
  this->m_pElements = m_pMemory;
  if ( v4 <= 0 )
    return m_Size;
  v6 = 0;
  v7 = base;
  do
  {
    v8 = &src->m_Memory.m_pMemory[v6];
    v9 = &this->m_Memory.m_pMemory[v7];
    if ( v9 != nullptr )
    {
      *(_QWORD *)&v9->m_vPos.x = *(_QWORD *)&v8->m_vPos.x;
      *(_QWORD *)&v9->m_vPos.z = *(_QWORD *)&v8->m_vPos.z;
      *(_QWORD *)&v9->m_vColor.m_vColor.y = *(_QWORD *)&v8->m_vColor.m_vColor.y;
      v9->m_vColor.m_flAlpha = v8->m_vColor.m_flAlpha;
    }
    ++v6;
    ++v7;
    --v4;
  }
  while ( v4 != 0 );
  return base;
}

//------------------------------------------------------------------------------
// Address: 0x10010AE0
// Name: public: int CUtlVector<class CSPVert,class CUtlMemory<class CSPVert,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CSPVert,CUtlMemory<CSPVert,int>>::InsertMultipleBefore(
        CUtlVector<CSPVert,CUtlMemory<CSPVert,int> > *this,
        int elem,
        int num)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CSPVert *m_pMemory; // ecx
  int v9; // eax
  int v10; // edx
  int v11; // eax
  unsigned int v12; // edx
  CSPVert *v13; // ecx
  int v14; // eax
  int v15; // edi
  CSPVert *v16; // ecx
  int i; // [esp+10h] [ebp+8h]

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<dleafambientlighting_t,int>::Grow(
      (CUtlMemory<dleafambientlighting_t,int> *)this,
      num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v9 = this->m_Size - elem - num;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v9 > 0 && num > 0 )
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 28 * v9);
  v10 = 0;
  if ( num >= 4 )
  {
    v11 = elem;
    v12 = ((unsigned int)(num - 4) >> 2) + 1;
    i = 4 * v12;
    do
    {
      v13 = &this->m_Memory.m_pMemory[v11];
      if ( v13 != nullptr )
        v13->m_vColor.m_flAlpha = 1.0;
      if ( &this->m_Memory.m_pMemory[v11] != (CSPVert *)-28 )
        this->m_Memory.m_pMemory[v11 + 1].m_vColor.m_flAlpha = 1.0;
      if ( &this->m_Memory.m_pMemory[v11] != (CSPVert *)-56 )
        this->m_Memory.m_pMemory[v11 + 2].m_vColor.m_flAlpha = 1.0;
      if ( &this->m_Memory.m_pMemory[v11] != (CSPVert *)-84 )
        this->m_Memory.m_pMemory[v11 + 3].m_vColor.m_flAlpha = 1.0;
      v11 += 4;
      --v12;
    }
    while ( v12 != 0 );
    v10 = i;
  }
  if ( v10 < num )
  {
    v14 = v10 + elem;
    v15 = num - v10;
    do
    {
      v16 = &this->m_Memory.m_pMemory[v14];
      if ( v16 != nullptr )
        v16->m_vColor.m_flAlpha = 1.0;
      ++v14;
      --v15;
    }
    while ( v15 != 0 );
  }
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x10012470
// Name: void AddScriptToStack(char __near *,enum ScriptPathMode_t)
// Source: json
//------------------------------------------------------------------------------
void __cdecl AddScriptToStack(char *filename, ScriptPathMode_t pathMode)
{
  int File; // esi
  const char *v3; // [esp-8h] [ebp-8h]

  if ( ++script == (script_t *)token )
    _Error(a1: "script file exceeded MAX_INCLUDES");
  if ( pathMode == SCRIPT_USE_RELATIVE_PATH )
  {
    V_strncpy(pDest: script->filename, pSrc: filename, maxLen: 1024);
  }
  else
  {
    v3 = ExpandPath(path: filename);
    V_strncpy(pDest: script->filename, pSrc: v3, maxLen: 1024);
  }
  File = LoadFile(filename: script->filename, bufferptr: (void **)&script->buffer);
  if ( g_pfnCallback != nullptr )
    ((void (__thiscall *)(CFileSystemPassThru *))g_pfnCallback)(this: g_pfnCallback);
  script->line = 1;
  script->script_p = script->buffer;
  script->end_p = &script->buffer[File];
}

//------------------------------------------------------------------------------
// Address: 0x10012550
// Name: bool AddMacroToStack(char __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl AddMacroToStack(char *macroname)
{
  int v2; // esi
  bool v3; // zf
  script_t *v4; // edi
  script_t *v5; // ebx
  int nummacroparams; // eax
  char *macrobuffer; // esi
  char **macroparam; // edi
  unsigned int v9; // esi
  script_t *pmacro; // [esp+4h] [ebp-4h]
  int i; // [esp+10h] [ebp+8h]

  if ( *macroname != 36 )
    return 0;
  v2 = 0;
  v3 = nummacros == 0;
  if ( nummacros > 0 )
  {
    do
    {
      if ( _V_stricmp(s1: macrolist[v2]->filename, s2: macroname + 1) == 0 )
        break;
      ++v2;
    }
    while ( v2 < nummacros );
    v3 = v2 == nummacros;
  }
  if ( v3 )
    return 0;
  v4 = macrolist[v2];
  v5 = script + 2;
  pmacro = v4;
  if ( &script[2] == (script_t *)token )
    _Error(a1: "script file exceeded MAX_INCLUDES");
  nummacroparams = v4->nummacroparams;
  macrobuffer = v5->macrobuffer;
  v5->nummacroparams = nummacroparams;
  i = 0;
  if ( nummacroparams > 0 )
  {
    macroparam = v5->macroparam;
    do
    {
      GetToken(crossline: 0);
      strcpy(macrobuffer, token);
      *macroparam = *(char **)((char *)macroparam + (char *)pmacro - (char *)v5);
      macroparam[64] = macrobuffer;
      macrobuffer += strlen(token) + 1;
      if ( macrobuffer >= (char *)v5->macroparam )
        _Error(a1: "Macro buffer overflow\n");
      ++macroparam;
      ++i;
    }
    while ( i < v5->nummacroparams );
    v4 = pmacro;
  }
  script = (script_t *)strcpy(v5->filename, v4->filename);
  v9 = v4->end_p - v4->buffer;
  script->buffer = (char *)malloc(size: v9 + 1);
  memcpy(dst: (unsigned __int8 *)script->buffer, src: (unsigned __int8 *)v4->buffer, count: v9);
  v4->buffer[v9] = 0;
  script->script_p = script->buffer;
  script->end_p = &script->buffer[v9];
  script->line = v4->line;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10012840
// Name: void ParseFromMemory(char __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ParseFromMemory(char *buffer, int size)
{
  scriptstack[1].buffer = buffer;
  scriptstack[1].script_p = buffer;
  script = &scriptstack[1];
  scriptstack[1].end_p = &buffer[size];
  strcpy(scriptstack[1].filename, "memory buffer");
  scriptstack[1].line = 1;
  endofscript = 0;
  tokenready = 0;
}

//------------------------------------------------------------------------------
// Address: 0x100128B0
// Name: int EndOfScript(int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl EndOfScript(int crossline)
{
  if ( crossline == 0 )
    _Error(a1: "Line %i is incomplete\n", scriptline);
  if ( strcmp(script->filename, aMemoryB) == 0
    || (free(pBlock: script->buffer), script->buffer = nullptr, script == &scriptstack[1]) )
  {
    endofscript = 1;
    return 0;
  }
  else
  {
    --script;
    scriptline = script->line;
    return GetToken(crossline);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10012970
// Name: int TokenAvailable(void)
// Source: json
//------------------------------------------------------------------------------
int __cdecl TokenAvailable()
{
  char *script_p; // eax
  char *end_p; // edx
  char v3; // cl
  char v4; // cl

  if ( tokenready != 0 )
    return 1;
  script_p = script->script_p;
  end_p = script->end_p;
  if ( script_p < end_p )
  {
    v3 = *script_p;
    if ( *script_p > 32 )
    {
LABEL_8:
      v4 = *script_p;
      if ( *script_p != 59 && v4 != 35 && (v4 != 47 || script_p[1] != 47) )
        return 1;
    }
    else
    {
      while ( v3 != 10 )
      {
        if ( ++script_p == end_p )
          break;
        v3 = *script_p;
        if ( *script_p > 32 )
          goto LABEL_8;
      }
    }
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x100129D0
// Name: public: virtual bool CScriptLib::DoesFileExist(char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CScriptLib::DoesFileExist(CScriptLib *this, const char *pFilename)
{
  return g_pFullFileSystem->FileExists(this: &g_pFullFileSystem->IBaseFileSystem, a2: pFilename, a3: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x100129F0
// Name: public: virtual bool CScriptLib::ReadFileToBuffer(char const __near *,class CUtlBuffer __near &,bool,bool)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CScriptLib::ReadFileToBuffer(
        CScriptLib *this,
        const char *pSourceName,
        CUtlBuffer *buffer,
        bool bText,
        bool bNoOpenFailureWarning)
{
  int *v5; // eax
  const char *v6; // eax

  if ( g_pFullFileSystem->ReadFile(
         this: &g_pFullFileSystem->IBaseFileSystem,
         a2: pSourceName,
         a3: nullptr,
         a4: buffer,
         a5: 0,
         a6: 0,
         a7: nullptr) )
  {
    if ( bText )
      CUtlBuffer::SetBufferType(this: buffer, bIsText: true, bContainsCRLF: true);
    else
      CUtlBuffer::SetBufferType(this: buffer, bIsText: false, bContainsCRLF: false);
    return 1;
  }
  else
  {
    if ( !bNoOpenFailureWarning )
    {
      v5 = _errno();
      v6 = strerror(errnum: *v5);
      _Msg(a1: "ReadFileToBuffer(): Error opening %s: %s\n", pSourceName, v6);
    }
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10012B30
// Name: public: virtual int CScriptLib::CompareFileTime(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CScriptLib::CompareFileTime(CScriptLib *this, const char *pFilenameA, const char *pFilenameB)
{
  unsigned int v3; // esi
  unsigned int v4; // eax
  bool v5; // cf

  v3 = g_pFullFileSystem->GetFileTime(this: &g_pFullFileSystem->IBaseFileSystem, a2: pFilenameA, a3: nullptr);
  v4 = g_pFullFileSystem->GetFileTime(this: &g_pFullFileSystem->IBaseFileSystem, a2: pFilenameB, a3: nullptr);
  if ( v3 == -1 )
    v3 = 0;
  if ( v4 == -1 )
    return v3 != 0;
  v5 = v4 < v3;
  if ( v4 <= v3 )
    return v5;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x10012B90
// Name: public: virtual char __near * CScriptLib::MakeTemporaryFilename(char const __near *,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CScriptLib::MakeTemporaryFilename(CScriptLib *this, const char *pchModPath, char *pPath, int pathSize)
{
  char *v4; // eax
  char *v5; // esi

  v4 = _tempnam(dir: pchModPath, pfx: "mgd_");
  v5 = v4;
  if ( *v4 == 92 )
    v5 = v4 + 1;
  if ( v5[strlen(v5) - 1] == 46 )
    v5[strlen(v5) - 1] = 0;
  V_snprintf(pDest: pPath, maxLen: pathSize, pFormat: "%s.tmp", v5);
  free(pBlock: v5);
  return pPath;
}

//------------------------------------------------------------------------------
// Address: 0x10012C00
// Name: void DefineMacro(char __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DefineMacro(char *macroname)
{
  script_t *v1; // edi
  char *script_p; // esi
  char *macrobuffer; // ebx
  unsigned int v4; // ebx
  unsigned __int8 *v5; // eax
  int v6; // eax
  script_t *v7; // edx

  v1 = (script_t *)malloc(size: 0x1614u);
  strcpy(v1->filename, macroname);
  v1->line = script->line;
  v1->nummacroparams = 0;
  script_p = script->script_p;
  macrobuffer = v1->macrobuffer;
  while ( TokenAvailable() != 0 )
  {
    GetToken(crossline: 0);
    if ( token[0] == 92 && byte_13F8E8C9 == 92 )
      break;
    script_p = script->script_p;
    v1->macroparam[v1->nummacroparams++] = macrobuffer;
    strcpy(macrobuffer, token);
    macrobuffer += strlen(token) + 1;
    if ( macrobuffer >= (char *)v1->macroparam )
      _Error(a1: "Macro buffer overflow\n");
  }
  for ( script->script_p = script_p; *script_p != 0; ++script_p )
  {
    if ( *script_p == 10 )
      break;
    if ( *script_p == 92 && script_p[1] == 92 )
    {
      do
      {
        if ( *script_p == 10 )
          break;
        *script_p++ = 32;
      }
      while ( *script_p != 0 );
      if ( *script_p == 0 )
        break;
    }
  }
  v4 = script_p - script->script_p;
  v5 = (unsigned __int8 *)malloc(size: v4 + 1);
  v1->buffer = (char *)v5;
  memcpy(dst: v5, src: (unsigned __int8 *)script->script_p, count: v4);
  v1->buffer[v4] = 0;
  v1->end_p = &v1->buffer[v4];
  v6 = nummacros;
  v7 = script;
  macrolist[nummacros] = v1;
  nummacros = v6 + 1;
  v7->script_p = script_p;
}

//------------------------------------------------------------------------------
// Address: 0x10012E40
// Name: bool ExpandVariableToken(char __near * __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl ExpandVariableToken(char **token_p)
{
  char *script_p; // ebx
  const char *v2; // ebx
  char *v3; // esi
  char v4; // al
  int v6; // esi
  int v7; // edi
  void (*v8)(const char *, ...); // ebx
  char *value; // edi
  unsigned int v10; // eax
  char *v11; // edx
  _BYTE *v12; // esi
  char v13; // cl
  const char *v14; // [esp-10h] [ebp-18h]
  char *cp; // [esp+4h] [ebp-4h]

  script_p = script->script_p;
  if ( *script_p != 36 )
    return 0;
  v2 = script_p + 1;
  v3 = (char *)v2;
  v4 = *v2;
  cp = (char *)v2;
  if ( *v2 <= 32 )
  {
LABEL_6:
    if ( *v3 != 36 )
      return 0;
  }
  else
  {
    while ( v4 != 36 )
    {
      v4 = *++v3;
      if ( v4 <= 32 )
      {
        cp = v3;
        goto LABEL_6;
      }
    }
    cp = v3;
  }
  v6 = v3 - v2;
  v7 = 0;
  v2[v6] = 0;
  if ( g_definevariable.m_Size <= 0 )
    goto LABEL_14;
  while ( V_strnicmp(s1: g_definevariable.m_Memory.m_pMemory[v7].param, s2: v2, n: v6) != 0 )
  {
    if ( ++v7 >= g_definevariable.m_Size )
      goto LABEL_14;
  }
  if ( v7 < g_definevariable.m_Size )
  {
    v8 = (void (*)(const char *, ...))_Error;
  }
  else
  {
LABEL_14:
    v14 = v2;
    v8 = (void (*)(const char *, ...))_Error;
    _Error(a1: "unknown variable token \"%s\" in %s\n", v14, script->filename);
  }
  value = g_definevariable.m_Memory.m_pMemory[v7].value;
  v10 = strlen(value);
  v11 = value;
  v12 = *token_p;
  do
  {
    v13 = *v11;
    *v12++ = *v11++;
  }
  while ( v13 != 0 );
  *token_p += v10;
  script->script_p = cp + 1;
  if ( script->script_p >= script->end_p )
    v8(a1: "Macro expand overflow\n");
  if ( *token_p >= (char *)&nummacros )
    v8(a1: "Token too large on line %i\n", scriptline);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10012F70
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
    CUtlMemory<UtlLinkedListElem_t<CWorkUnitInfo,int>,int>::Grow(
      (CUtlMemory<CWorkUnitWalker::CWorkerInfo,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
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
// Address: 0x10012FF0
// Name: void DefineVariable(char __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DefineVariable(char *variablename)
{
  char *v1; // eax
  char *v2; // eax
  char *v3; // ecx
  char v4; // dl
  variable_t v; // [esp+8h] [ebp-8h] BYREF

  if ( variablename != nullptr
    && (v1 = (char *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: strlen(variablename) + 1)) != nullptr )
  {
    strcpy(v1, variablename);
  }
  else
  {
    v1 = nullptr;
  }
  v.param = v1;
  GetToken(crossline: 0);
  v2 = (char *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: strlen(token) + 1);
  if ( v2 != nullptr )
  {
    v3 = v2;
    do
    {
      v4 = v3[token - v2];
      *v3++ = v4;
    }
    while ( v4 != 0 );
  }
  else
  {
    v2 = nullptr;
  }
  v.value = v2;
  CUtlVector<variable_t,CUtlMemory<variable_t,int>>::InsertBefore(
    this: (CUtlVector<unsigned __int64,CUtlMemory<unsigned __int64,int> > *)&g_definevariable,
    elem: g_definevariable.m_Size,
    src: (const unsigned __int64 *)&v);
}

//------------------------------------------------------------------------------
// Address: 0x100130B0
// Name: int GetToken(int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl GetToken(int crossline)
{
  script_t *v1; // eax
  char *script_p; // ecx
  char v3; // dl
  script_t *v4; // eax
  char *v5; // ecx
  char *v6; // edx
  char v7; // cl
  char *v8; // ecx
  char v9; // dl
  script_t *v10; // eax
  char *v11; // edx
  script_t *v12; // eax
  int line; // edx
  char v14; // cl
  char *v15; // esi
  script_t *v16; // eax
  char i; // cl
  char *v18; // esi
  char *v19; // ecx
  char *token_p; // [esp+Ch] [ebp-4h] BYREF

  if ( tokenready != 0 )
  {
LABEL_54:
    tokenready = 0;
    return 1;
  }
  else
  {
    while ( 1 )
    {
      v1 = script;
      if ( script->script_p >= script->end_p )
        return EndOfScript(crossline);
      tokenready = 0;
      while ( 1 )
      {
        while ( 1 )
        {
          if ( *v1->script_p <= 32 )
          {
            do
            {
              script_p = v1->script_p;
              if ( script_p >= v1->end_p )
                return EndOfScript(crossline);
              v3 = *script_p;
              v1->script_p = script_p + 1;
              if ( v3 == 10 )
              {
                if ( crossline == 0 )
                  _Error(a1: "Line %i is incomplete\n", scriptline);
                v4 = script;
                ++script->line;
                scriptline = v4->line;
              }
              v1 = script;
            }
            while ( *script->script_p <= 32 );
          }
          v5 = v1->script_p;
          if ( v5 >= v1->end_p )
            return EndOfScript(crossline);
          v6 = v1->script_p;
          v7 = *v5;
          if ( v7 != 59 && v7 != 35 )
          {
            if ( v7 != 47 )
              goto LABEL_30;
            if ( v6[1] != 47 )
              break;
          }
          if ( crossline == 0 )
          {
            _Error(a1: "Line %i is incomplete\n", scriptline);
            v1 = script;
          }
          if ( *v1->script_p != 10 )
          {
            do
            {
              ++v1->script_p;
              v1 = script;
              v11 = script->script_p;
              if ( v11 >= script->end_p )
                return EndOfScript(crossline);
            }
            while ( *v11 != 10 );
          }
          ++v1->script_p;
          v12 = script;
          ++script->line;
          line = v12->line;
          v1 = script;
          scriptline = line;
        }
        if ( v6[1] != 42 )
          break;
        v1->script_p += 2;
        while ( 1 )
        {
          v8 = script->script_p;
          if ( *v8 == 42 && v8[1] == 47 )
            break;
          v9 = *v8;
          script->script_p = v8 + 1;
          if ( v9 != 10 )
          {
            v10 = script;
            if ( script->script_p >= script->end_p )
              return EndOfScript(crossline);
            ++script->line;
            scriptline = v10->line;
          }
        }
        script->script_p += 2;
        v1 = script;
      }
LABEL_30:
      v14 = *v6;
      v15 = token;
      token_p = token;
      if ( v14 == 34 )
      {
        ++v1->script_p;
        v16 = script;
        for ( i = *script->script_p; i != 34; i = *v16->script_p )
        {
          *v15 = i;
          ++script->script_p;
          v16 = script;
          ++v15;
          if ( script->script_p == script->end_p )
            break;
          if ( v15 == (char *)&nummacros )
          {
            _Error(a1: "Token too large on line %i\n", scriptline);
            v16 = script;
          }
        }
        ++v16->script_p;
      }
      else
      {
        for ( ; v14 > 32; v14 = *script->script_p )
        {
          if ( v14 == 59 )
            break;
          if ( ExpandMacroToken(&token_p) || ExpandVariableToken(&token_p) != 0 )
          {
            v15 = token_p;
          }
          else
          {
            v18 = token_p;
            *token_p = *script->script_p++;
            v19 = script->script_p;
            v15 = v18 + 1;
            token_p = v15;
            if ( v19 == script->end_p )
              break;
            if ( v15 == (char *)&nummacros )
              _Error(a1: "Token too large on line %i\n", scriptline);
          }
        }
      }
      *v15 = 0;
      if ( _V_stricmp(s1: token, s2: "$include") != 0 )
      {
        if ( _V_stricmp(s1: token, s2: "$definemacro") != 0 )
        {
          if ( _V_stricmp(s1: token, s2: "$definevariable") != 0 )
          {
            if ( AddMacroToStack(macroname: token) == 0 )
              return 1;
          }
          else
          {
            GetToken(crossline: 0);
            DefineVariable(variablename: token);
          }
        }
        else
        {
          GetToken(crossline: 0);
          DefineMacro(macroname: token);
        }
      }
      else
      {
        GetToken(crossline: 0);
        AddScriptToStack(filename: token, pathMode: SCRIPT_USE_ABSOLUTE_PATH);
      }
      if ( tokenready != 0 )
        goto LABEL_54;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100134B0
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
    CUtlMemory<clusterlist_t,int>::Grow(
      (CUtlMemory<UtlLinkedListElem_t<unsigned __int64,unsigned __int64>,unsigned __int64> *)this,
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
// Address: 0x10013520
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
    CUtlMemory<clusterlist_t,int>::Grow(
      (CUtlMemory<UtlLinkedListElem_t<unsigned __int64,unsigned __int64>,unsigned __int64> *)this,
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
// Address: 0x100135C0
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
// Address: 0x10013630
// Name: private: int CScriptLib::GetFileList(char const __near *,char const __near *,class CUtlVector<struct fileList_t,class CUtlMemory<struct fileList_t,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CScriptLib::GetFileList(
        CScriptLib *this,
        const char *pDirPath,
        const char *pPattern,
        CUtlVector<fileList_t,CUtlMemory<fileList_t,int> > *fileList)
{
  unsigned int v5; // kr00_4
  int v6; // eax
  char v7; // cl
  char *v8; // edi
  char v9; // al
  unsigned int v10; // eax
  char *v11; // edi
  char v12; // cl
  int v13; // esi
  int v15; // eax
  char v16; // cl
  unsigned int v17; // eax
  char *v18; // edi
  char v19; // cl
  char *v20; // edi
  char *v21; // esi
  char v22; // cl
  int m_Size; // eax
  int v24; // esi
  char v25; // [esp+Bh] [ebp-435h] BYREF
  char fileName[260]; // [esp+Ch] [ebp-434h] BYREF
  char fullPath[260]; // [esp+110h] [ebp-330h] BYREF
  _finddata64i32_t findData; // [esp+214h] [ebp-22Ch] BYREF
  char sourcePath[260]; // [esp+33Ch] [ebp-104h] BYREF
  int h; // [esp+448h] [ebp+8h]
  char bFindDirs_3; // [esp+453h] [ebp+13h]

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
  v5 = strlen(sourcePath);
  if ( v5 != 0 )
  {
    if ( findData.name[v5 + 259] != 92 )
    {
      sourcePath[v5] = 92;
      sourcePath[v5 + 1] = 0;
    }
  }
  else
  {
    strcpy(sourcePath, ".\\");
  }
  v6 = 0;
  do
  {
    v7 = sourcePath[v6];
    fullPath[v6++] = v7;
  }
  while ( v7 != 0 );
  if ( *pPattern != 92 || pPattern[1] != 0 )
  {
    bFindDirs_3 = 0;
    v10 = strlen(pPattern) + 1;
    v11 = &fileName[259];
    do
      v12 = *++v11;
    while ( v12 != 0 );
    qmemcpy(v11, pPattern, v10);
  }
  else
  {
    bFindDirs_3 = 1;
    v8 = &fileName[259];
    do
      v9 = *++v8;
    while ( v9 != 0 );
    strcpy(v8, "*");
  }
  v13 = _findfirst64i32(szWild: fullPath, pfd: &findData);
  h = v13;
  if ( v13 == -1 )
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
      v15 = 0;
      do
      {
        v16 = sourcePath[v15];
        fileName[v15++] = v16;
      }
      while ( v16 != 0 );
      v17 = strlen(findData.name) + 1;
      v18 = &v25;
      do
        v19 = *++v18;
      while ( v19 != 0 );
      qmemcpy(v18, findData.name, 4 * (v17 >> 2));
      v21 = &findData.name[4 * (v17 >> 2)];
      v20 = &v18[4 * (v17 >> 2)];
      v22 = v17;
      m_Size = fileList->m_Size;
      qmemcpy(v20, v21, v22 & 3);
      v24 = CUtlVector<fileList_t,CUtlMemory<fileList_t,int>>::InsertBefore(this: fileList, elem: m_Size);
      CUtlString::Set(this: &fileList->m_Memory.m_pMemory[v24].fileName, pValue: fileName);
      fileList->m_Memory.m_pMemory[v24].timeWrite = findData.time_write;
      v13 = h;
    }
  }
  while ( _findnext64i32(hFile: v13, pfd: &findData) == 0 );
  _findclose(hFile: v13);
  return fileList->m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x10013890
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
// Address: 0x100138F0
// Name: public: virtual void CScriptLib::DeleteTemporaryFiles(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CScriptLib::DeleteTemporaryFiles(CScriptLib *this, const char *pFileMask)
{
  char *v2; // eax
  char *v3; // edx
  char v4; // cl
  unsigned int v5; // eax
  char *v6; // edi
  char v7; // cl
  int (__thiscall *FindFiles)(struct CScriptLib *, char *, bool, CUtlVector<fileList_t,CUtlMemory<fileList_t,int> > *); // edx
  int v9; // esi
  int v10; // edi
  const char *v11; // eax
  fileList_t *m_pMemory; // eax
  char v13; // [esp+3h] [ebp-11Dh] BYREF
  char tempPath[260]; // [esp+4h] [ebp-11Ch] BYREF
  CScriptLib *v15; // [esp+108h] [ebp-18h]
  CUtlVector<fileList_t,CUtlMemory<fileList_t,int> > fileList; // [esp+10Ch] [ebp-14h] BYREF

  v15 = this;
  v2 = getenv(option: "temp");
  if ( v2 != nullptr || (v2 = getenv(option: "tmp")) != nullptr )
  {
    v3 = (char *)(tempPath - v2);
    do
    {
      v4 = *v2;
      v2[(_DWORD)v3] = *v2;
      ++v2;
    }
    while ( v4 != 0 );
    V_AppendSlash(pStr: tempPath, strSize: 260);
    v5 = strlen(pFileMask) + 1;
    v6 = &v13;
    do
      v7 = *++v6;
    while ( v7 != 0 );
    qmemcpy(v6, pFileMask, v5);
    FindFiles = v15->FindFiles;
    memset(&fileList, 0, sizeof(fileList));
    FindFiles(this: v15, a2: tempPath, a3: false, a4: &fileList);
    v9 = 0;
    if ( fileList.m_Size > 0 )
    {
      v10 = 0;
      do
      {
        v11 = CUtlString::Get(this: &fileList.m_Memory.m_pMemory[v10].fileName);
        _unlink(path: v11);
        ++v9;
        ++v10;
      }
      while ( v9 < fileList.m_Size );
    }
    CUtlVector<fileList_t,CUtlMemory<fileList_t,int>>::RemoveAll(this: &fileList);
    m_pMemory = fileList.m_Memory.m_pMemory;
    if ( fileList.m_Memory.m_nGrowSize >= 0 )
    {
      if ( fileList.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: fileList.m_Memory.m_pMemory);
        m_pMemory = nullptr;
        fileList.m_Memory.m_pMemory = nullptr;
      }
      fileList.m_Memory.m_nAllocationCount = 0;
    }
    fileList.m_pElements = m_pMemory;
    if ( fileList.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10013A20
// Name: private: void CScriptLib::RecurseFileTree_r(char const __near *,int,class CUtlVector<class CUtlString,class CUtlMemory<class CUtlString,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CScriptLib::RecurseFileTree_r(
        CScriptLib *this,
        const char *pDirPath,
        int depth,
        CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *dirList)
{
  fileList_t *i; // ebx
  int v5; // eax
  int v6; // eax
  fileList_t *m_pMemory; // edi
  const char *v8; // eax
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CUtlString *v11; // ecx
  int v12; // eax
  int v13; // edi
  CUtlString *v14; // ecx
  CUtlVector<fileList_t,CUtlMemory<fileList_t,int> > fileList; // [esp+Ch] [ebp-18h] BYREF
  CScriptLib *v16; // [esp+20h] [ebp-4h]

  i = nullptr;
  v16 = this;
  memset(&fileList, 0, sizeof(fileList));
  v5 = CScriptLib::GetFileList(this, pDirPath, pPattern: "\\", &fileList);
  if ( v5 != 0 )
  {
    if ( v5 > 0 )
    {
      m_pMemory = fileList.m_Memory.m_pMemory;
      for ( i = (fileList_t *)v5; i != nullptr; i = (fileList_t *)((char *)i - 1) )
      {
        v8 = CUtlString::Get(this: &m_pMemory->fileName);
        CScriptLib::RecurseFileTree_r(this: v16, pDirPath: v8, depth: depth + 1, dirList);
        ++m_pMemory;
      }
    }
    m_Size = dirList->m_Size;
    m_nAllocationCount = dirList->m_Memory.m_nAllocationCount;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<UtlLinkedListElem_t<CWorkUnitInfo,int>,int>::Grow(
        this: (CUtlMemory<CWorkUnitWalker::CWorkerInfo,int> *)dirList,
        num: m_Size - m_nAllocationCount + 1);
    ++dirList->m_Size;
    v11 = dirList->m_Memory.m_pMemory;
    v12 = dirList->m_Size - m_Size - 1;
    dirList->m_pElements = dirList->m_Memory.m_pMemory;
    if ( v12 > (int)i )
      _V_memmove(dest: &v11[m_Size + 1], src: &v11[m_Size], count: 16 * v12);
    v13 = m_Size;
    v14 = &dirList->m_Memory.m_pMemory[v13];
    if ( v14 != nullptr )
      CUtlString::CUtlString(this: v14);
    CUtlString::Set(this: &dirList->m_Memory.m_pMemory[v13], pValue: pDirPath);
    CUtlVector<fileList_t,CUtlMemory<fileList_t,int>>::RemoveAll(this: &fileList);
    if ( fileList.m_Memory.m_nGrowSize >= (int)i && fileList.m_Memory.m_pMemory != i )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: fileList.m_Memory.m_pMemory);
  }
  else
  {
    v6 = CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>::InsertBefore(this: dirList, elem: dirList->m_Size);
    CUtlString::Set(this: &dirList->m_Memory.m_pMemory[v6], pValue: pDirPath);
    CUtlVector<fileList_t,CUtlMemory<fileList_t,int>>::~CUtlVector<fileList_t,CUtlMemory<fileList_t,int>>(this: &fileList);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10013B40
// Name: public: virtual int CScriptLib::FindFiles(char __near *,bool,class CUtlVector<struct fileList_t,class CUtlMemory<struct fileList_t,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CScriptLib::FindFiles(
        CScriptLib *this,
        char *pFileMask,
        bool bRecurse,
        CUtlVector<fileList_t,CUtlMemory<fileList_t,int> > *fileList)
{
  CScriptLib *v4; // edi
  char *v5; // edi
  char v6; // al
  unsigned int v7; // eax
  char *v8; // edi
  char v9; // cl
  int m_nGrowSize; // esi
  fileList_t *m_pMemory; // eax
  const char *v13; // eax
  CUtlVector<fileList_t,CUtlMemory<fileList_t,int> > *v14; // esi
  int m_Size; // edi
  int inserted; // eax
  fileList_t *v17; // edi
  int v18; // ebx
  CUtlString *p_fileName; // esi
  int timeWrite_high; // eax
  bool v21; // zf
  CUtlString *v22; // eax
  unsigned int v23; // [esp-8h] [ebp-34Ch]
  char extension[260]; // [esp+8h] [ebp-33Ch] BYREF
  char dirPath[260]; // [esp+10Ch] [ebp-238h] BYREF
  char pattern[260]; // [esp+210h] [ebp-134h] BYREF
  CScriptLib *v27; // [esp+314h] [ebp-30h]
  int i; // [esp+318h] [ebp-2Ch]
  CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > dirList; // [esp+31Ch] [ebp-28h] BYREF
  CUtlVector<fileList_t,CUtlMemory<fileList_t,int> > tempList; // [esp+330h] [ebp-14h] BYREF
  char *pFileMaska; // [esp+34Ch] [ebp+8h]
  int bRecursea; // [esp+350h] [ebp+Ch]

  v4 = this;
  v27 = this;
  strcpy(dirPath, pFileMask);
  V_StripFilename(path: dirPath);
  V_FileBase(in: pFileMask, out: pattern, maxlen: 260);
  V_ExtractFileExtension(path: pFileMask, dest: extension, destSize: 260);
  if ( extension[0] != 0 )
  {
    v5 = &dirPath[259];
    do
      v6 = *++v5;
    while ( v6 != 0 );
    strcpy(v5, ".");
    v7 = strlen(extension) + 1;
    v8 = &dirPath[259];
    do
      v9 = *++v8;
    while ( v9 != 0 );
    qmemcpy(v8, extension, v7);
    v4 = v27;
  }
  if ( bRecurse )
  {
    memset(&tempList, 0, sizeof(tempList));
    memset(&dirList, 0, sizeof(dirList));
    CScriptLib::RecurseFileTree_r(this: v4, pDirPath: dirPath, depth: 0, &dirList);
    i = 0;
    if ( dirList.m_Size > 0 )
    {
      bRecursea = 0;
      while ( 1 )
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
          v23 = 24 * dirList.m_Size;
          if ( m_pMemory != nullptr )
            m_pMemory = (fileList_t *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v23);
          else
            m_pMemory = (fileList_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v23);
          tempList.m_Memory.m_pMemory = m_pMemory;
        }
        tempList.m_pElements = m_pMemory;
        v13 = CUtlString::Get(this: &dirList.m_Memory.m_pMemory[bRecursea]);
        CScriptLib::GetFileList(this: v4, pDirPath: v13, pPattern: pattern, fileList: &tempList);
        v14 = fileList;
        m_Size = tempList.m_Size;
        inserted = CUtlVector<fileList_t,CUtlMemory<fileList_t,int>>::InsertMultipleBefore(
                     this: fileList,
                     elem: fileList->m_Size,
                     num: tempList.m_Size);
        if ( m_Size > 0 )
        {
          v17 = tempList.m_Memory.m_pMemory;
          v18 = inserted;
          pFileMaska = (char *)tempList.m_Size;
          while ( 1 )
          {
            p_fileName = &v14->m_Memory.m_pMemory[v18].fileName;
            CUtlString::operator=(this: p_fileName, src: &v17->fileName);
            p_fileName[1].m_Storage.m_Memory.m_pMemory = (unsigned __int8 *)v17->timeWrite;
            timeWrite_high = HIDWORD(v17->timeWrite);
            ++v17;
            ++v18;
            v21 = pFileMaska-- == (char *)1;
            p_fileName[1].m_Storage.m_Memory.m_nAllocationCount = timeWrite_high;
            if ( v21 )
              break;
            v14 = fileList;
          }
        }
        ++bRecursea;
        if ( ++i >= dirList.m_Size )
          break;
        v4 = v27;
      }
    }
    CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>::RemoveAll(this: &dirList);
    v22 = dirList.m_Memory.m_pMemory;
    if ( dirList.m_Memory.m_nGrowSize >= 0 )
    {
      if ( dirList.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: dirList.m_Memory.m_pMemory);
        v22 = nullptr;
        dirList.m_Memory.m_pMemory = nullptr;
      }
      dirList.m_Memory.m_nAllocationCount = 0;
    }
    dirList.m_pElements = v22;
    if ( dirList.m_Memory.m_nGrowSize >= 0 )
    {
      if ( v22 != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v22);
        dirList.m_Memory.m_pMemory = nullptr;
      }
      dirList.m_Memory.m_nAllocationCount = 0;
    }
    CUtlVector<fileList_t,CUtlMemory<fileList_t,int>>::RemoveAll(this: &tempList);
    if ( tempList.m_Memory.m_nGrowSize < 0 )
    {
      return fileList->m_Size;
    }
    else
    {
      if ( tempList.m_Memory.m_pMemory != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: tempList.m_Memory.m_pMemory);
      return fileList->m_Size;
    }
  }
  else
  {
    CScriptLib::GetFileList(this: v4, pDirPath: dirPath, pPattern: pattern, fileList);
    return fileList->m_Size;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10027930
// Name: public: int CUtlVector<struct variable_t,class CUtlMemory<struct variable_t,int>>::InsertBefore(int,struct variable_t const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<variable_t,CUtlMemory<variable_t,int>>::InsertBefore(
        CUtlVector<unsigned __int64,CUtlMemory<unsigned __int64,int> > *this,
        int elem,
        unsigned __int64 *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  unsigned __int64 *m_pMemory; // ecx
  int v7; // eax
  unsigned __int64 *v8; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CTransmitRateMgr::CMachineRecord,int>::Grow(
      (CUtlMemory<CTransmitRateMgr::CMachineRecord,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 8 * v7);
  v8 = &this->m_Memory.m_pMemory[elem];
  if ( v8 != nullptr )
    *v8 = *src;
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x100279A0
// Name: public: int CUtlVector<unsigned __int64,class CUtlMemory<unsigned __int64,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<unsigned __int64,CUtlMemory<unsigned __int64,int>>::InsertMultipleBefore(
        CUtlVector<unsigned __int64,CUtlMemory<unsigned __int64,int> > *this,
        int elem,
        int num)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  unsigned __int64 *m_pMemory; // ecx
  int v8; // eax
  int v9; // eax

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<CTransmitRateMgr::CMachineRecord,int>::Grow(
      (CUtlMemory<CTransmitRateMgr::CMachineRecord,int> *)this,
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
// Address: 0x1002CFE0
// Name: public: int CUtlVector<class CMasterMulticastThread::CChunkInfo,class CUtlMemory<class CMasterMulticastThread::CChunkInfo,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CMasterMulticastThread::CChunkInfo,CUtlMemory<CMasterMulticastThread::CChunkInfo,int>>::InsertMultipleBefore(
        CUtlVector<CMasterMulticastThread::CChunkInfo,CUtlMemory<CMasterMulticastThread::CChunkInfo,int> > *this,
        int elem,
        int num)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CMasterMulticastThread::CChunkInfo *m_pMemory; // ecx
  int v8; // eax
  int v9; // eax

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<CIPAddr,int>::Grow(this: &this->m_Memory, num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v8 = this->m_Size;
  this->m_pElements = this->m_Memory.m_pMemory;
  v9 = v8 - elem - num;
  if ( v9 > 0 && num > 0 )
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 6 * v9);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x1002D2B0
// Name: public: int CUtlVector<class CTransmitRateMgr::CMachineRecord,class CUtlMemory<class CTransmitRateMgr::CMachineRecord,int>>::AddToTail(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CTransmitRateMgr::CMachineRecord,CUtlMemory<CTransmitRateMgr::CMachineRecord,int>>::AddToTail(
        CUtlVector<CTransmitRateMgr::CMachineRecord,CUtlMemory<CTransmitRateMgr::CMachineRecord,int> > *this)
{
  int m_nAllocationCount; // eax
  int m_Size; // edi
  CTransmitRateMgr::CMachineRecord *m_pMemory; // ecx
  int v5; // eax

  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  m_Size = this->m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CTransmitRateMgr::CMachineRecord,int>::Grow(this: &this->m_Memory, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v5 = this->m_Size - m_Size - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v5 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 8 * v5);
  return m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x10030AA0
// Name: public: int CUtlVector<class CWUStatus,class CUtlMemory<class CWUStatus,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CWUStatus,CUtlMemory<CWUStatus,int>>::InsertMultipleBefore(
        CUtlVector<CWUStatus,CUtlMemory<CWUStatus,int> > *this,
        int elem,
        int num)
{
  int v3; // edi
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CWUStatus *m_pMemory; // ecx
  int v9; // eax
  int v10; // ecx
  CWUStatus *v11; // eax

  v3 = num;
  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<clusterlist_t,int>::Grow(
      (CUtlMemory<UtlLinkedListElem_t<unsigned __int64,unsigned __int64>,unsigned __int64> *)this,
      num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v9 = this->m_Size - elem - num;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v9 > 0 && num > 0 )
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 24 * v9);
  if ( num > 0 )
  {
    v10 = elem;
    do
    {
      v11 = &this->m_Memory.m_pMemory[v10];
      if ( v11 != nullptr )
      {
        v11->m_iState = 0;
        *(_QWORD *)&v11->m_Rect.left = 0;
        *(_QWORD *)&v11->m_Rect.right = 0;
      }
      ++v10;
      --v3;
    }
    while ( v3 != 0 );
  }
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x10030B50
// Name: public: int CUtlVector<class CWorkUnitEvent,class CUtlMemory<class CWorkUnitEvent,int>>::InsertBefore(int,class CWorkUnitEvent const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CWorkUnitEvent,CUtlMemory<CWorkUnitEvent,int>>::InsertBefore(
        CUtlVector<CWorkUnitEvent,CUtlMemory<CWorkUnitEvent,int> > *this,
        int elem,
        const CWorkUnitEvent *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CWorkUnitEvent *m_pMemory; // ecx
  int v7; // eax
  CWorkUnitEvent *v8; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<UtlLinkedListElem_t<CWorkUnitInfo,int>,int>::Grow(
      (CUtlMemory<CWorkUnitWalker::CWorkerInfo,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 16 * v7);
  v8 = &this->m_Memory.m_pMemory[elem];
  if ( v8 != nullptr )
    *v8 = *src;
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x10030D20
// Name: public: int CUtlVector<class CWorkUnit,class CUtlMemory<class CWorkUnit,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CWorkUnit,CUtlMemory<CWorkUnit,int>>::InsertMultipleBefore(
        CUtlVector<CWorkUnit,CUtlMemory<CWorkUnit,int> > *this,
        int elem,
        int num)
{
  int v3; // edi
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CWorkUnit *m_pMemory; // ecx
  int v9; // eax
  int v10; // ecx
  CWorkUnit *v11; // eax

  v3 = num;
  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<clusterlist_t,int>::Grow(
      (CUtlMemory<UtlLinkedListElem_t<unsigned __int64,unsigned __int64>,unsigned __int64> *)this,
      num: num + m_Size - m_nAllocationCount);
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
          v11->m_Events.m_Memory.m_pMemory = nullptr;
          v11->m_Events.m_Memory.m_nAllocationCount = 0;
          v11->m_Events.m_Memory.m_nGrowSize = 0;
          v11->m_Events.m_Size = 0;
          v11->m_Events.m_pElements = nullptr;
          v11->m_iWorkerCompleted = -1;
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
// Address: 0x10031230
// Name: public: void CUtlVector<struct clusterlist_t,class CUtlMemory<struct clusterlist_t,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<clusterlist_t,CUtlMemory<clusterlist_t,int>>::RemoveAll(
        CUtlVector<CWorkUnit,CUtlMemory<CWorkUnit,int> > *this)
{
  int v1; // ebx
  int v2; // eax
  char *v3; // esi
  void *v4; // eax
  int v5; // [esp+4h] [ebp-8h]
  CUtlVector<CWorkUnit,CUtlMemory<CWorkUnit,int> > *v6; // [esp+8h] [ebp-4h]

  v1 = this->m_Size - 1;
  v6 = this;
  if ( v1 < 0 )
  {
    this->m_Size = 0;
  }
  else
  {
    v2 = 24 * v1;
    v5 = 24 * v1;
    do
    {
      v3 = (char *)this->m_Memory.m_pMemory + v2;
      *((_DWORD *)v3 + 4) = 0;
      if ( *((int *)v3 + 3) >= 0 )
      {
        if ( *((_DWORD *)v3 + 1) != 0 )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *((void **)v3 + 1));
          this = v6;
          *((_DWORD *)v3 + 1) = 0;
        }
        *((_DWORD *)v3 + 2) = 0;
      }
      v4 = *((void **)v3 + 1);
      *((_DWORD *)v3 + 5) = v4;
      if ( *((int *)v3 + 3) >= 0 )
      {
        if ( v4 != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v4);
          this = v6;
          *((_DWORD *)v3 + 1) = 0;
        }
        *((_DWORD *)v3 + 2) = 0;
      }
      --v1;
      v2 = v5 - 24;
      v5 -= 24;
    }
    while ( v1 >= 0 );
    this->m_Size = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10031340
// Name: public: CUtlVector<struct clusterlist_t,class CUtlMemory<struct clusterlist_t,int>>::~CUtlVector<struct clusterlist_t,class CUtlMemory<struct clusterlist_t,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<clusterlist_t,CUtlMemory<clusterlist_t,int>>::~CUtlVector<clusterlist_t,CUtlMemory<clusterlist_t,int>>(
        CUtlVector<CWorkUnit,CUtlMemory<CWorkUnit,int> > *this)
{
  bool v2; // sf
  CWorkUnit *m_pMemory; // eax

  CUtlVector<clusterlist_t,CUtlMemory<clusterlist_t,int>>::RemoveAll(this);
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
// Address: 0x10031D10
// Name: public: int CUtlVector<class CWULookupInfo,class CUtlMemory<class CWULookupInfo,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CWULookupInfo,CUtlMemory<CWULookupInfo,int>>::InsertMultipleBefore(
        CUtlVector<CWULookupInfo,CUtlMemory<CWULookupInfo,int> > *this,
        int elem,
        int num)
{
  int v3; // edi
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CWULookupInfo *m_pMemory; // ecx
  int v9; // eax
  int v10; // ecx
  CWULookupInfo *v11; // eax

  v3 = num;
  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<UtlLinkedListElem_t<CMasterMulticastThread::CMulticastFile *,int>,int>::Grow(
      (CUtlMemory<UtlLinkedListElem_t<CWorkerFile *,int>,int> *)this,
      num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v9 = this->m_Size - elem - num;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v9 <= 0 )
    goto LABEL_8;
  if ( num > 0 )
  {
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 12 * v9);
LABEL_8:
    if ( num > 0 )
    {
      v10 = elem;
      do
      {
        v11 = &this->m_Memory.m_pMemory[v10];
        if ( v11 != nullptr )
        {
          v11->m_iWUInfo = -1;
          v11->m_iPartition = -222222;
          v11->m_iPartitionListIndex = -1;
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
// Address: 0x100348C0
// Name: public: int CUtlVector<class CWorkUnitWalker::CWorkerInfo,class CUtlMemory<class CWorkUnitWalker::CWorkerInfo,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CWorkUnitWalker::CWorkerInfo,CUtlMemory<CWorkUnitWalker::CWorkerInfo,int>>::InsertMultipleBefore(
        CUtlVector<CWorkUnitWalker::CWorkerInfo,CUtlMemory<CWorkUnitWalker::CWorkerInfo,int> > *this,
        int elem,
        int num)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CWorkUnitWalker::CWorkerInfo *m_pMemory; // ecx
  int v8; // eax
  int v9; // eax

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<UtlLinkedListElem_t<CWorkUnitInfo,int>,int>::Grow(
      this: &this->m_Memory,
      num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v8 = this->m_Size;
  this->m_pElements = this->m_Memory.m_pMemory;
  v9 = v8 - elem - num;
  if ( v9 > 0 && num > 0 )
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 16 * v9);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x10035120
// Name: public: int CUtlVector<unsigned __int64,class CUtlMemory<unsigned __int64,int>>::InsertMultipleBefore(int,int,unsigned __int64 const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<unsigned __int64,CUtlMemory<unsigned __int64,int>>::InsertMultipleBefore(
        CUtlVector<unsigned __int64,CUtlMemory<unsigned __int64,int> > *this,
        int elem,
        int num,
        const unsigned __int64 *pToInsert)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  unsigned __int64 *m_pMemory; // ecx
  int v9; // ebx
  int v10; // eax
  int v11; // eax
  int v12; // edx
  unsigned __int64 *v13; // ecx

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<CTransmitRateMgr::CMachineRecord,int>::Grow(
      (CUtlMemory<CTransmitRateMgr::CMachineRecord,int> *)this,
      num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v9 = elem;
  v10 = this->m_Size - elem - num;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v10 > 0 && num > 0 )
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 8 * v10);
  if ( pToInsert != nullptr )
  {
    v11 = 0;
    if ( num > 0 )
    {
      v12 = elem;
      do
      {
        v13 = &this->m_Memory.m_pMemory[v12];
        if ( v13 != nullptr )
        {
          *(_DWORD *)v13 = pToInsert[v11];
          *((_DWORD *)v13 + 1) = HIDWORD(pToInsert[v11]);
          v9 = elem;
        }
        ++v11;
        ++v12;
      }
      while ( v11 < num );
    }
  }
  return v9;
}

//------------------------------------------------------------------------------
// Address: 0x10036100
// Name: public: int CUtlVector<class CFileResponse,class CUtlMemory<class CFileResponse,int>>::InsertBefore(int,class CFileResponse const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CFileResponse,CUtlMemory<CFileResponse,int>>::InsertBefore(
        CUtlVector<CFileResponse,CUtlMemory<CFileResponse,int> > *this,
        int elem,
        const CFileResponse *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CFileResponse *m_pMemory; // ecx
  int v7; // eax
  CFileResponse *v8; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<UtlLinkedListElem_t<CMasterMulticastThread::CMulticastFile *,int>,int>::Grow(
      (CUtlMemory<UtlLinkedListElem_t<CWorkerFile *,int>,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 12 * v7);
  v8 = &this->m_Memory.m_pMemory[elem];
  if ( v8 != nullptr )
    *v8 = *src;
  return elem;
}

} // namespace vvis_dll
