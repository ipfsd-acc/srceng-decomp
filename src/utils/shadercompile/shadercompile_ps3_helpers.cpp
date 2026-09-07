// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/shadercompile/shadercompile_ps3_helpers.cpp
// Functions: 90
// ============================================================

#include "utils\shadercompile\shadercompile_ps3_helpers.h"

//------------------------------------------------------------------------------
// Address: 0x10007F20
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
// Address: 0x10008660
// Name: public: int CUtlVector<struct _D3DXMACRO,class CUtlMemory<struct _D3DXMACRO,int>>::InsertBefore(int,struct _D3DXMACRO const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<_D3DXMACRO,CUtlMemory<_D3DXMACRO,int>>::InsertBefore(
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
// Address: 0x10009410
// Name: public: void CUtlMemory<struct ShaderInfo_t,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<ShaderInfo_t,int>::Grow(CUtlMemory<ShaderInfo_t,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  ShaderInfo_t *m_pMemory; // edx
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
      this->m_pMemory = (ShaderInfo_t *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (ShaderInfo_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100094A0
// Name: public: void CUtlMemory<class CompilerMsgInfo,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<CompilerMsgInfo,int>::Grow(CUtlMemory<CompilerMsgInfo,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  CompilerMsgInfo *m_pMemory; // edx
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
    v7 = 36 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (CompilerMsgInfo *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (CompilerMsgInfo *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10009660
// Name: public: void CUtlVector<struct StaticComboAuxInfo_t,class CUtlMemory<struct StaticComboAuxInfo_t,int>>::Sort(int (*)(struct StaticComboAuxInfo_t const __near *,struct StaticComboAuxInfo_t const __near *))
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<StaticComboAuxInfo_t,CUtlMemory<StaticComboAuxInfo_t,int>>::Sort(
        CUtlVector<StaticComboAuxInfo_t,CUtlMemory<StaticComboAuxInfo_t,int> > *this,
        int (__cdecl *pfnCompare)(const void *, const void *))
{
  signed int m_Size; // eax
  char *m_pMemory; // ecx
  int v5; // eax
  int v6; // esi
  int j; // ebx
  StaticComboRecord_t v8; // xmm0_8
  __int64 v9; // xmm1_8
  StaticComboAuxInfo_t *v10; // eax
  int i; // [esp+4h] [ebp-4h]

  m_Size = this->m_Size;
  if ( m_Size > 1 )
  {
    m_pMemory = (char *)this->m_Memory.m_pMemory;
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      qsort(base: m_pMemory, num: m_Size, width: 0x10u, comp: pfnCompare);
    }
    else
    {
      v5 = m_Size - 1;
      for ( i = v5; v5 >= 0; i = v5 )
      {
        if ( v5 >= 1 )
        {
          v6 = 1;
          for ( j = v5; j != 0; --j )
          {
            if ( pfnCompare(a1: &this->m_Memory.m_pMemory[v6 - 1], a2: &this->m_Memory.m_pMemory[v6]) < 0 )
            {
              v8 = this->m_Memory.m_pMemory[v6 - 1].StaticComboRecord_t;
              v9 = *(_QWORD *)&this->m_Memory.m_pMemory[v6 - 1].m_nCRC32;
              v10 = &this->m_Memory.m_pMemory[v6];
              v10[-1].StaticComboRecord_t = v10->StaticComboRecord_t;
              *(_QWORD *)&v10[-1].m_nCRC32 = *(_QWORD *)&v10->m_nCRC32;
              v10->StaticComboRecord_t = v8;
              *(_QWORD *)&v10->m_nCRC32 = v9;
            }
            ++v6;
          }
          v5 = i;
        }
        --v5;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10009920
// Name: public: void CUtlVector<struct CByteCodeBlock __near *,class CUtlMemory<struct CByteCodeBlock __near *,int>>::Sort(int (*)(struct CByteCodeBlock __near * const __near *,struct CByteCodeBlock __near * const __near *))
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CByteCodeBlock *,CUtlMemory<CByteCodeBlock *,int>>::Sort(
        CUtlVector<CByteCodeBlock *,CUtlMemory<CByteCodeBlock *,int> > *this,
        int (__cdecl *pfnCompare)(const void *, const void *))
{
  signed int m_Size; // ebx
  int i; // ebx
  int j; // esi
  CByteCodeBlock *v6; // ecx
  CByteCodeBlock **v7; // eax

  m_Size = this->m_Size;
  if ( m_Size > 1 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      qsort(base: (char *)this->m_Memory.m_pMemory, num: m_Size, width: 4u, comp: pfnCompare);
    }
    else
    {
      for ( i = m_Size - 1; i >= 0; --i )
      {
        for ( j = 1; j <= i; ++j )
        {
          if ( pfnCompare(a1: &this->m_Memory.m_pMemory[j - 1], a2: &this->m_Memory.m_pMemory[j]) < 0 )
          {
            v6 = this->m_Memory.m_pMemory[j - 1];
            v7 = &this->m_Memory.m_pMemory[j];
            *(v7 - 1) = *v7;
            *v7 = v6;
          }
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100099A0
// Name: public: void CUtlVector<struct StaticComboAuxInfo_t,class CUtlMemory<struct StaticComboAuxInfo_t,int>>::EnsureCapacity(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<StaticComboAuxInfo_t,CUtlMemory<StaticComboAuxInfo_t,int>>::EnsureCapacity(
        CUtlVector<StaticComboAuxInfo_t,CUtlMemory<StaticComboAuxInfo_t,int> > *this,
        int num)
{
  StaticComboAuxInfo_t *m_pMemory; // edx
  unsigned int v4; // eax
  StaticComboAuxInfo_t *v5; // eax

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
    v4 = 16 * num;
    if ( m_pMemory != nullptr )
    {
      this->m_Memory.m_pMemory = (StaticComboAuxInfo_t *)_g_pMemAlloc->Realloc_2(
                                                           this: _g_pMemAlloc,
                                                           a2: m_pMemory,
                                                           a3: v4);
      goto LABEL_5;
    }
    v5 = (StaticComboAuxInfo_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v4);
    this->m_Memory.m_pMemory = v5;
    this->m_pElements = v5;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10009A00
// Name: public: void CUtlVector<struct StaticComboAliasRecord_t,class CUtlMemory<struct StaticComboAliasRecord_t,int>>::Sort(int (*)(struct StaticComboAliasRecord_t const __near *,struct StaticComboAliasRecord_t const __near *))
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<StaticComboAliasRecord_t,CUtlMemory<StaticComboAliasRecord_t,int>>::Sort(
        CUtlVector<StaticComboAliasRecord_t,CUtlMemory<StaticComboAliasRecord_t,int> > *this,
        int (__cdecl *pfnCompare)(const void *, const void *))
{
  signed int m_Size; // ebx
  int v4; // ebx
  int j; // esi
  unsigned int m_nStaticComboID; // ecx
  unsigned int m_nSourceStaticCombo; // edx
  StaticComboAliasRecord_t *v8; // eax
  int i; // [esp+8h] [ebp-4h]

  m_Size = this->m_Size;
  if ( m_Size > 1 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      qsort(base: (char *)this->m_Memory.m_pMemory, num: m_Size, width: 8u, comp: pfnCompare);
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
            m_nStaticComboID = this->m_Memory.m_pMemory[j - 1].m_nStaticComboID;
            m_nSourceStaticCombo = this->m_Memory.m_pMemory[j - 1].m_nSourceStaticCombo;
            v8 = &this->m_Memory.m_pMemory[j];
            v8[-1].m_nStaticComboID = v8->m_nStaticComboID;
            v8[-1].m_nSourceStaticCombo = v8->m_nSourceStaticCombo;
            v4 = i;
            v8->m_nStaticComboID = m_nStaticComboID;
            v8->m_nSourceStaticCombo = m_nSourceStaticCombo;
          }
        }
        --v4;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10009C80
// Name: public: int CUtlVector<struct StaticComboAuxInfo_t,class CUtlMemory<struct StaticComboAuxInfo_t,int>>::InsertBefore(int,struct StaticComboAuxInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<StaticComboAuxInfo_t,CUtlMemory<StaticComboAuxInfo_t,int>>::InsertBefore(
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
// Address: 0x1000A0D0
// Name: public: CUtlVector<struct CWorkerAccumState<class CThreadNullMutex>::SubProcess __near *,class CUtlMemory<struct CWorkerAccumState<class CThreadNullMutex>::SubProcess __near *,int>>::~CUtlVector<struct CWorkerAccumState<class CThreadNullMutex>::SubProcess __near *,class CUtlMemory<struct CWorkerAccumState<class CThreadNullMutex>::SubProcess __near *,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CWorkerAccumState<CThreadNullMutex>::SubProcess *,CUtlMemory<CWorkerAccumState<CThreadNullMutex>::SubProcess *,int>>::~CUtlVector<CWorkerAccumState<CThreadNullMutex>::SubProcess *,CUtlMemory<CWorkerAccumState<CThreadNullMutex>::SubProcess *,int>>(
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
// Address: 0x1000A140
// Name: public: void CUtlVector<struct CByteCodeBlock __near *,class CUtlMemory<struct CByteCodeBlock __near *,int>>::PurgeAndDeleteElements(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CByteCodeBlock *,CUtlMemory<CByteCodeBlock *,int>>::PurgeAndDeleteElements(
        CUtlVector<CByteCodeBlock *,CUtlMemory<CByteCodeBlock *,int> > *this)
{
  int i; // ebx
  CByteCodeBlock *v3; // edi
  bool v4; // sf
  CByteCodeBlock **m_pMemory; // ecx

  for ( i = 0; i < this->m_Size; ++i )
  {
    v3 = this->m_Memory.m_pMemory[i];
    if ( v3 != nullptr )
    {
      if ( v3->m_ByteCode != nullptr )
        free(pMem: v3->m_ByteCode);
      free(pMem: v3);
    }
  }
  v4 = this->m_Memory.m_nGrowSize < 0;
  this->m_Size = 0;
  if ( v4 )
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
// Address: 0x1000A1C0
// Name: public: int CUtlVector<class CUtlNodeHash<struct CStaticCombo,7097,unsigned __int64> __near *,class CUtlMemory<class CUtlNodeHash<struct CStaticCombo,7097,unsigned __int64> __near *,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CUtlNodeHash<CStaticCombo,7097,unsigned __int64> *,CUtlMemory<CUtlNodeHash<CStaticCombo,7097,unsigned __int64> *,int>>::InsertMultipleBefore(
        CUtlVector<CUtlNodeHash<CStaticCombo,7097,unsigned __int64> *,CUtlMemory<CUtlNodeHash<CStaticCombo,7097,unsigned __int64> *,int> > *this,
        int elem,
        int num)
{
  int v3; // edi
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CUtlNodeHash<CStaticCombo,7097,unsigned __int64> **m_pMemory; // ecx
  int v9; // eax
  int v10; // ecx
  CUtlNodeHash<CStaticCombo,7097,unsigned __int64> **v11; // eax

  v3 = num;
  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<int,int>::Grow((CUtlMemory<CTCPPacket *,int> *)this, num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v9 = this->m_Size - elem - num;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v9 <= 0 )
    goto LABEL_8;
  if ( num > 0 )
  {
    _V_memmove(dest: &m_pMemory[elem] + num, src: &m_pMemory[elem], count: 4 * v9);
LABEL_8:
    if ( num > 0 )
    {
      v10 = elem;
      do
      {
        v11 = &this->m_Memory.m_pMemory[v10];
        if ( v11 != nullptr )
          *v11 = nullptr;
        ++v10;
        --v3;
      }
      while ( v3 != 0 );
    }
  }
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x1000A250
// Name: public: int CUtlVector<struct ShaderInfo_t,class CUtlMemory<struct ShaderInfo_t,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<ShaderInfo_t,CUtlMemory<ShaderInfo_t,int>>::InsertMultipleBefore(
        CUtlVector<ShaderInfo_t,CUtlMemory<ShaderInfo_t,int> > *this,
        int elem,
        int num)
{
  int v3; // edi
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  int v8; // edx
  ShaderInfo_t *m_pMemory; // ecx
  int v10; // eax
  int v11; // ebx
  char *v12; // eax

  v3 = num;
  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<ShaderInfo_t,int>::Grow(this: &this->m_Memory, num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  v8 = elem;
  m_pMemory = this->m_Memory.m_pMemory;
  v10 = this->m_Size - elem - num;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v10 <= 0 )
    goto LABEL_8;
  if ( num > 0 )
  {
    _V_memmove(dest: &m_pMemory[num + elem], src: &m_pMemory[elem], count: v10 << 6);
    v8 = elem;
LABEL_8:
    if ( num > 0 )
    {
      v11 = v8 << 6;
      do
      {
        v12 = (char *)this->m_Memory.m_pMemory + v11;
        if ( v12 != nullptr )
        {
          memset(dst: (int)v12, value: nullptr, count: 0x40u);
          v8 = elem;
        }
        v11 += 64;
        --v3;
      }
      while ( v3 != 0 );
    }
  }
  return v8;
}

//------------------------------------------------------------------------------
// Address: 0x1000A890
// Name: public: int CUtlVector<class CompilerMsgInfo,class CUtlMemory<class CompilerMsgInfo,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CompilerMsgInfo,CUtlMemory<CompilerMsgInfo,int>>::InsertMultipleBefore(
        CUtlVector<CompilerMsgInfo,CUtlMemory<CompilerMsgInfo,int> > *this,
        int elem,
        int num)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  int v7; // ecx
  CompilerMsgInfo *m_pMemory; // edx
  int v9; // eax
  int v10; // ebx
  CompilerMsgInfo *v11; // edi

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<CompilerMsgInfo,int>::Grow(this: &this->m_Memory, num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  v7 = elem;
  m_pMemory = this->m_Memory.m_pMemory;
  v9 = this->m_Size - elem - num;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v9 <= 0 )
    goto LABEL_8;
  if ( num > 0 )
  {
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 36 * v9);
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
          CUtlString::CUtlString(this: &this->m_Memory.m_pMemory[v10].m_sFirstCommand);
          CUtlString::CUtlString(this: &v11->m_sFirstMachineName);
          v7 = elem;
          v11->m_numTimesReported = 0;
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
// Address: 0x1000AFB0
// Name: public: void CUtlVector<bool,class CUtlMemory<bool,int>>::EnsureCount(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<bool,CUtlMemory<bool,int>>::EnsureCount(
        CUtlVector<bool,CUtlMemory<bool,int> > *this,
        int num)
{
  int m_Size; // eax
  int v4; // edi
  int v5; // ebx
  int m_nAllocationCount; // eax
  bool *m_pMemory; // ecx
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
        CUtlMemory<bool,int>::Grow((CUtlMemory<char,int> *)this, num: v4 + v5 - m_nAllocationCount);
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
// Address: 0x1000B320
// Name: public: void CUtlVector<class CompilerMsgInfo,class CUtlMemory<class CompilerMsgInfo,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CompilerMsgInfo,CUtlMemory<CompilerMsgInfo,int>>::RemoveAll(
        CUtlVector<CompilerMsgInfo,CUtlMemory<CompilerMsgInfo,int> > *this)
{
  int v1; // ebx
  int v2; // eax
  char *v3; // esi
  int v4; // [esp+4h] [ebp-8h]
  CUtlVector<CompilerMsgInfo,CUtlMemory<CompilerMsgInfo,int> > *v5; // [esp+8h] [ebp-4h]

  v1 = this->m_Size - 1;
  v5 = this;
  if ( v1 < 0 )
  {
    this->m_Size = 0;
  }
  else
  {
    v2 = 36 * v1;
    v4 = 36 * v1;
    do
    {
      v3 = (char *)this->m_Memory.m_pMemory + v2;
      *((_DWORD *)v3 + 7) = 0;
      if ( *((int *)v3 + 6) >= 0 )
      {
        if ( *((_DWORD *)v3 + 4) != 0 )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *((void **)v3 + 4));
          this = v5;
          *((_DWORD *)v3 + 4) = 0;
        }
        *((_DWORD *)v3 + 5) = 0;
      }
      *((_DWORD *)v3 + 3) = 0;
      if ( *((int *)v3 + 2) >= 0 )
      {
        if ( *(_DWORD *)v3 != 0 )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *(void **)v3);
          this = v5;
          *(_DWORD *)v3 = 0;
        }
        *((_DWORD *)v3 + 1) = 0;
      }
      --v1;
      v2 = v4 - 36;
      v4 -= 36;
    }
    while ( v1 >= 0 );
    this->m_Size = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000C3E0
// Name: public: CUtlVector<class CompilerMsgInfo,class CUtlMemory<class CompilerMsgInfo,int>>::~CUtlVector<class CompilerMsgInfo,class CUtlMemory<class CompilerMsgInfo,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CompilerMsgInfo,CUtlMemory<CompilerMsgInfo,int>>::~CUtlVector<CompilerMsgInfo,CUtlMemory<CompilerMsgInfo,int>>(
        CUtlVector<CompilerMsgInfo,CUtlMemory<CompilerMsgInfo,int> > *this)
{
  bool v2; // sf
  CompilerMsgInfo *m_pMemory; // eax

  CUtlVector<CompilerMsgInfo,CUtlMemory<CompilerMsgInfo,int>>::RemoveAll(this);
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
// Address: 0x1000EA10
// Name: WritePS3DebugInfo
// Source: json
//------------------------------------------------------------------------------
void __usercall WritePS3DebugInfo(DWORD nFileSize@<esi>, const char *pFullPath, unsigned __int8 *pFileData)
{
  HANDLE FileA; // eax
  int v4; // eax
  HANDLE v5; // edx
  int v6; // eax
  char filename[260]; // [esp+4h] [ebp-118h] BYREF
  PS3DebugFileTOCEntry_t tocEntry; // [esp+108h] [ebp-14h] BYREF
  unsigned int nBytesWritten; // [esp+118h] [ebp-4h] BYREF

  if ( nFileSize + g_nPS3DebugInfoPackFileSizes[g_nCurrentPS3DebugInfoFile] <= 0x40000000 )
  {
    FileA = g_hPS3DebugInfoCurrentPackFile;
    if ( g_hPS3DebugInfoCurrentPackFile != (HANDLE)-1 )
      goto LABEL_6;
  }
  else
  {
    CloseHandle(hObject: g_hPS3DebugInfoCurrentPackFile);
    ++g_nCurrentPS3DebugInfoFile;
    g_hPS3DebugInfoCurrentPackFile = (HANDLE)-1;
  }
  V_snprintf(pDest: filename, maxLen: 260, pFormat: "ps3shaderdebug_pack%02d.bin", g_nCurrentPS3DebugInfoFile);
  V_ComposeFileName(
    path: g_pShaderPath,
    filename,
    dest: g_PS3DebugInfoPackFilenames[g_nCurrentPS3DebugInfoFile],
    destSize: 260);
  FileA = CreateFileA(
            lpFileName: g_PS3DebugInfoPackFilenames[g_nCurrentPS3DebugInfoFile],
            dwDesiredAccess: 0x40000000u,
            dwShareMode: 0,
            lpSecurityAttributes: nullptr,
            dwCreationDisposition: 2u,
            dwFlagsAndAttributes: 0x80u,
            hTemplateFile: nullptr);
  g_hPS3DebugInfoCurrentPackFile = FileA;
  if ( FileA == (HANDLE)-1 )
  {
    _Error(a1: "Could not write to PS3 debug info file.  Make sure you have enough disk space, these things can be huuuge.");
    return;
  }
LABEL_6:
  nBytesWritten = 0;
  WriteFile(
    hFile: FileA,
    lpBuffer: pFileData,
    nNumberOfBytesToWrite: nFileSize,
    lpNumberOfBytesWritten: &nBytesWritten,
    lpOverlapped: nullptr);
  if ( nBytesWritten == nFileSize )
  {
    v4 = _V_strlen(str: pFullPath);
    v5 = g_hPS3DebugTOCFile;
    tocEntry.m_nFilenameLength = v4 + 1;
    v6 = g_nCurrentPS3DebugInfoFile;
    tocEntry.m_nFileOffset = g_nPS3DebugInfoPackFileSizes[g_nCurrentPS3DebugInfoFile];
    g_nPS3DebugInfoPackFileSizes[g_nCurrentPS3DebugInfoFile] = nBytesWritten + tocEntry.m_nFileOffset;
    tocEntry.m_nFileIndex = v6;
    tocEntry.m_nFileSize = nFileSize;
    WriteFile(
      hFile: v5,
      lpBuffer: &tocEntry,
      nNumberOfBytesToWrite: 0x10u,
      lpNumberOfBytesWritten: &nBytesWritten,
      lpOverlapped: nullptr);
    if ( nBytesWritten != 16
      || (WriteFile(
            hFile: g_hPS3DebugTOCFile,
            lpBuffer: pFullPath,
            nNumberOfBytesToWrite: tocEntry.m_nFilenameLength,
            lpNumberOfBytesWritten: &nBytesWritten,
            lpOverlapped: nullptr),
          nBytesWritten != tocEntry.m_nFilenameLength) )
    {
      _Error(a1: "Error writing to PS3 debug TOC file.  Make sure you have enough disk space, these things can be huuuge.");
    }
  }
  else
  {
    _Error(a1: "Error writing to PS3 debug info file.  Make sure you have enough disk space, these things can be huuuge.");
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000EBA0
// Name: void InitializePS3ShaderDebugPackFiles(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InitializePS3ShaderDebugPackFiles()
{
  V_ComposeFileName(path: g_pShaderPath, filename: "ps3shaderdebug_toc.bin", dest: g_PS3DebugTOCFilename, destSize: 260);
  g_hPS3DebugTOCFile = CreateFileA(
                         lpFileName: g_PS3DebugTOCFilename,
                         dwDesiredAccess: 0x40000000u,
                         dwShareMode: 0,
                         lpSecurityAttributes: nullptr,
                         dwCreationDisposition: 2u,
                         dwFlagsAndAttributes: 0x80u,
                         hTemplateFile: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x1000EBE0
// Name: DisplayFileUnpackProgress
// Source: json
//------------------------------------------------------------------------------
void __usercall DisplayFileUnpackProgress(
        unsigned int nTotalSize@<eax>,
        unsigned int nCurrent@<ecx>,
        unsigned int nLast)
{
  double v3; // st7
  int v4; // edi
  int i; // esi

  v3 = (double)nTotalSize;
  v4 = (int)((double)nCurrent * 100.0 / v3);
  for ( i = 1 - (int)((double)nLast * -100.0 / v3); i <= v4; ++i )
  {
    if ( i % 10 != 0 )
    {
      if ( i % 2 == 0 )
        _Msg(a1: ".");
    }
    else
    {
      _Msg(a1: "%d", i / 10);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000ECA0
// Name: SendShaderCompileLogContentsToMaster
// Source: json
//------------------------------------------------------------------------------
char __cdecl SendShaderCompileLogContentsToMaster(char *pFilename)
{
  _iobuf *v1; // eax
  _iobuf *v2; // ebx
  unsigned int v4; // esi
  int v5; // edi
  _BYTE dest[4]; // [esp+4h] [ebp-2200h] BYREF
  unsigned int v7; // [esp+8h] [ebp-21FCh]
  _iobuf string[16]; // [esp+2004h] [ebp-200h] BYREF

  v1 = fopen(file: (_iobuf *)pFilename, mode: "r");
  v2 = v1;
  if ( v1 == nullptr )
    return 0;
  dest[0] = 11;
  v7 = 0;
  v4 = 8;
  if ( feof(stream: v1) == 0 )
  {
    do
    {
      if ( fgets(string, count: 512, str: v2) == nullptr )
        break;
      v5 = _V_strlen(str: (const char *)string);
      _V_memcpy(dest: &dest[v4], src: string, count: v5);
      v4 += v5;
      if ( 0x2000 - v4 < 0x200 )
      {
        v7 = v4;
        VMPI_SendData(pData: dest, nBytes: v4, iDest: 0, fVMPISendFlags: 0);
        v4 = 8;
      }
    }
    while ( feof(stream: v2) == 0 );
    if ( v4 > 8 )
    {
      v7 = v4;
      VMPI_SendData(pData: dest, nBytes: v4, iDest: 0, fVMPISendFlags: 0);
    }
  }
  fclose(stream: v2);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1000EDB0
// Name: void PS3SendShaderCompileLogContentsToMaster(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl PS3SendShaderCompileLogContentsToMaster()
{
  HANDLE MutexA; // eax
  void *v1; // esi
  char szLogFilename[260]; // [esp+0h] [ebp-104h] BYREF

  if ( GetEnvironmentVariableA(lpName: "PS3COMPILELOG", lpBuffer: szLogFilename, nSize: 0x104u) != 0 )
  {
    MutexA = CreateMutexA(lpMutexAttributes: nullptr, bInitialOwner: false, lpName: "PS3COMPILELOGMUTEX");
    v1 = MutexA;
    if ( MutexA != nullptr && WaitForSingleObject(hHandle: MutexA, dwMilliseconds: 0x2710u) == 0 )
    {
      SendShaderCompileLogContentsToMaster(pFilename: szLogFilename);
      unlink(path: szLogFilename);
      ReleaseMutex(hMutex: v1);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000EE30
// Name: bool PS3ShaderCompileLogDispatch(class MessageBuffer __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
char __cdecl PS3ShaderCompileLogDispatch(MessageBuffer *pBuf)
{
  char *data; // esi
  unsigned int v3; // eax
  unsigned __int8 *v4; // ebx
  _iobuf *v5; // eax
  _iobuf *v6; // esi
  unsigned int nDataSize; // [esp+4h] [ebp-4h]

  if ( ConCommandBase::GetName(this: (CVMPIFile_Memory *)pBuf) < 8 )
    return 0;
  v3 = *((_DWORD *)pBuf->data + 1);
  v4 = (unsigned __int8 *)(pBuf->data + 8);
  nDataSize = v3 - 8;
  if ( v3 >= 8 )
  {
    data = pBuf->data;
    if ( (signed int)ConCommandBase::GetName(this: (CVMPIFile_Memory *)pBuf) >= *((_DWORD *)data + 1) )
    {
      v5 = fopen(file: (_iobuf *)"ps3compilelog.txt", mode: "ab");
      v6 = v5;
      if ( v5 != nullptr )
      {
        fwrite(buffer: v4, size: nDataSize, count: 1u, stream: v5);
        fclose(stream: v6);
      }
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1000F050
// Name: public: void CUtlMemory<struct UtlRBTreeNode_t<struct CUtlSymbolTableLargeBaseTreeEntry_t __near *,int>,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int>,int>::Grow(
        CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int>,int> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int> *m_pMemory; // edx
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
      this->m_pMemory = (UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int> *)_g_pMemAlloc->Realloc_2(
                                                                                        this: _g_pMemAlloc,
                                                                                        a2: m_pMemory,
                                                                                        a3: v7);
    else
      this->m_pMemory = (UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int> *)_g_pMemAlloc->Alloc_2(
                                                                                        this: _g_pMemAlloc,
                                                                                        a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000F0F0
// Name: public: int CUtlRBTree<struct CUtlSymbolTableLargeBaseTreeEntry_t __near *,int,class CTreeEntryLess<class CNonThreadsafeTree<1>,1>,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlSymbolTableLargeBaseTreeEntry_t __near *,int>,int>>::Parent(int)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<CUtlSymbolTableLargeBaseTreeEntry_t *,int,CTreeEntryLess<CNonThreadsafeTree<1>,1>,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int>,int>>::Parent(
        CUtlRBTree<CUtlSymbolTableLargeBaseTreeEntry_t *,int,CTreeEntryLess<CNonThreadsafeTree<1>,1>,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int>,int> > *this,
        int i)
{
  if ( (`CUtlRBTree<CUtlSymbolTableLargeBaseTreeEntry_t *,int,CTreeEntryLess<CNonThreadsafeTree<1>,1>,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CUtlSymbolTableLargeBaseTreeEntry_t *,int,CTreeEntryLess<CNonThreadsafeTree<1>,1>,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlSymbolTableLargeBaseTreeEntry_t *,int,CTreeEntryLess<CNonThreadsafeTree<1>,1>,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_1016CBA0 = -1;
    dword_1016CBA4 = -1;
    dword_1016CBA8 = 1;
  }
  if ( i == -1 )
    return dword_1016CBA4;
  else
    return this->m_Elements.m_pMemory[i].m_Parent;
}

//------------------------------------------------------------------------------
// Address: 0x1000F150
// Name: public: int CUtlRBTree<struct CUtlSymbolTableLargeBaseTreeEntry_t __near *,int,class CTreeEntryLess<class CNonThreadsafeTree<1>,1>,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlSymbolTableLargeBaseTreeEntry_t __near *,int>,int>>::RightChild(int)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<CUtlSymbolTableLargeBaseTreeEntry_t *,int,CTreeEntryLess<CNonThreadsafeTree<1>,1>,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int>,int>>::RightChild(
        CUtlRBTree<CUtlSymbolTableLargeBaseTreeEntry_t *,int,CTreeEntryLess<CNonThreadsafeTree<1>,1>,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int>,int> > *this,
        int i)
{
  if ( (`CUtlRBTree<CUtlSymbolTableLargeBaseTreeEntry_t *,int,CTreeEntryLess<CNonThreadsafeTree<1>,1>,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CUtlSymbolTableLargeBaseTreeEntry_t *,int,CTreeEntryLess<CNonThreadsafeTree<1>,1>,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlSymbolTableLargeBaseTreeEntry_t *,int,CTreeEntryLess<CNonThreadsafeTree<1>,1>,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_1016CBA0 = -1;
    dword_1016CBA4 = -1;
    dword_1016CBA8 = 1;
  }
  if ( i == -1 )
    return dword_1016CBA0;
  else
    return this->m_Elements.m_pMemory[i].m_Right;
}

//------------------------------------------------------------------------------
// Address: 0x1000F1B0
// Name: protected: void CUtlRBTree<struct CUtlSymbolTableLargeBaseTreeEntry_t __near *,int,class CTreeEntryLess<class CNonThreadsafeTree<1>,1>,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlSymbolTableLargeBaseTreeEntry_t __near *,int>,int>>::FindInsertionPosition(struct CUtlSymbolTableLargeBaseTreeEntry_t __near * const __near &,int __near &,bool __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlSymbolTableLargeBaseTreeEntry_t *,int,CTreeEntryLess<CNonThreadsafeTree<1>,1>,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int>,int>>::FindInsertionPosition(
        CUtlRBTree<CUtlSymbolTableLargeBaseTreeEntry_t *,int,CTreeEntryLess<CNonThreadsafeTree<1>,1>,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int>,int> > *this,
        CUtlSymbolTableLargeBaseTreeEntry_t *const *insert,
        int *parent,
        bool *leftchild)
{
  int m_Root; // esi
  CUtlSymbolTableLargeBaseTreeEntry_t *m_Data; // eax
  unsigned int v6; // edx
  CUtlRBTree<CUtlSymbolTableLargeBaseTreeEntry_t *,int,CTreeEntryLess<CNonThreadsafeTree<1>,1>,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int>,int> > *v8; // [esp+4h] [ebp-4h]

  m_Root = this->m_Root;
  *parent = -1;
  v8 = this;
  *leftchild = false;
  if ( m_Root != -1 )
  {
    while ( 1 )
    {
      *parent = m_Root;
      m_Data = this->m_Elements.m_pMemory[m_Root].m_Data;
      v6 = **(_DWORD **)insert;
      if ( v6 == m_Data->m_Hash ? _V_stricmp(s1: (*insert)->m_String, s2: m_Data->m_String) < 0 : v6 < m_Data->m_Hash )
      {
        *leftchild = true;
        if ( (`CUtlRBTree<CUtlSymbolTableLargeBaseTreeEntry_t *,int,CTreeEntryLess<CNonThreadsafeTree<1>,1>,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int>,int>>::Links'::`2'::`local static guard'
            & 1) == 0 )
        {
          `CUtlRBTree<CUtlSymbolTableLargeBaseTreeEntry_t *,int,CTreeEntryLess<CNonThreadsafeTree<1>,1>,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int>,int>>::Links'::`2'::`local static guard' |= 1u;
          `CUtlRBTree<CUtlSymbolTableLargeBaseTreeEntry_t *,int,CTreeEntryLess<CNonThreadsafeTree<1>,1>,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_1016CBA0 = -1;
          dword_1016CBA4 = -1;
          dword_1016CBA8 = 1;
        }
        m_Root = v8->m_Elements.m_pMemory[m_Root].m_Left;
      }
      else
      {
        *leftchild = false;
        if ( (`CUtlRBTree<CUtlSymbolTableLargeBaseTreeEntry_t *,int,CTreeEntryLess<CNonThreadsafeTree<1>,1>,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int>,int>>::Links'::`2'::`local static guard'
            & 1) == 0 )
        {
          `CUtlRBTree<CUtlSymbolTableLargeBaseTreeEntry_t *,int,CTreeEntryLess<CNonThreadsafeTree<1>,1>,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int>,int>>::Links'::`2'::`local static guard' |= 1u;
          `CUtlRBTree<CUtlSymbolTableLargeBaseTreeEntry_t *,int,CTreeEntryLess<CNonThreadsafeTree<1>,1>,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_1016CBA0 = -1;
          dword_1016CBA4 = -1;
          dword_1016CBA8 = 1;
        }
        m_Root = v8->m_Elements.m_pMemory[m_Root].m_Right;
      }
      if ( m_Root == -1 )
        break;
      this = v8;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000F2D0
// Name: public: int CUtlRBTree<struct CUtlSymbolTableLargeBaseTreeEntry_t __near *,int,class CTreeEntryLess<class CNonThreadsafeTree<1>,1>,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlSymbolTableLargeBaseTreeEntry_t __near *,int>,int>>::NewNode(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<CUtlSymbolTableLargeBaseTreeEntry_t *,int,CTreeEntryLess<CNonThreadsafeTree<1>,1>,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int>,int>>::NewNode(
        CUtlRBTree<CUtlSymbolTableLargeBaseTreeEntry_t *,int,CTreeEntryLess<CNonThreadsafeTree<1>,1>,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int>,int> > *this)
{
  int result; // eax
  int index; // ecx
  int m_nAllocationCount; // eax
  int v5; // ecx
  int v6; // edi
  int v7; // ecx
  int v8; // eax
  int v9; // ecx
  UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int> *m_pMemory; // edx
  UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int> *v11; // edx

  result = this->m_FirstFree;
  if ( result == -1 )
  {
    index = this->m_LastAlloc.index;
    if ( index < 0 || (m_nAllocationCount = this->m_Elements.m_nAllocationCount, index >= m_nAllocationCount) )
    {
      m_nAllocationCount = this->m_Elements.m_nAllocationCount;
      v5 = (m_nAllocationCount > 0) - 1;
    }
    else
    {
      v5 = index + 1;
      if ( v5 < 0 || v5 >= m_nAllocationCount )
        v5 = -1;
    }
    v6 = v5;
    if ( v5 < 0 || v5 >= m_nAllocationCount )
    {
      CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int>,int>::Grow(this: &this->m_Elements, num: 1);
      v7 = this->m_LastAlloc.index;
      if ( v7 < 0 || (v8 = this->m_Elements.m_nAllocationCount, v7 >= v8) )
      {
        v8 = this->m_Elements.m_nAllocationCount;
        v9 = (v8 > 0) - 1;
      }
      else
      {
        v9 = v7 + 1;
        if ( v9 < 0 || v9 >= v8 )
          v9 = -1;
      }
      v6 = v9;
      if ( v9 < 0 || v9 >= v8 )
        _Error(a1: "CUtlRBTree overflow!\n");
    }
    m_pMemory = this->m_Elements.m_pMemory;
    this->m_LastAlloc.index = v6;
    this->m_pElements = m_pMemory;
    return v6;
  }
  else
  {
    v11 = this->m_Elements.m_pMemory;
    this->m_FirstFree = v11[result].m_Right;
    this->m_pElements = v11;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1000F390
// Name: public: bool CUtlRBTree<struct CUtlSymbolTableLargeBaseTreeEntry_t __near *,int,class CTreeEntryLess<class CNonThreadsafeTree<1>,1>,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlSymbolTableLargeBaseTreeEntry_t __near *,int>,int>>::IsLeftChild(int)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CUtlRBTree<CUtlSymbolTableLargeBaseTreeEntry_t *,int,CTreeEntryLess<CNonThreadsafeTree<1>,1>,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int>,int>>::IsLeftChild(
        CUtlRBTree<CUtlSymbolTableLargeBaseTreeEntry_t *,int,CTreeEntryLess<CNonThreadsafeTree<1>,1>,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int>,int> > *this,
        int i)
{
  int v2; // edx
  UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int> *v3; // eax
  int m_Parent; // eax

  v2 = `CUtlRBTree<CUtlSymbolTableLargeBaseTreeEntry_t *,int,CTreeEntryLess<CNonThreadsafeTree<1>,1>,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int>,int>>::Links'::`2'::`local static guard';
  if ( (`CUtlRBTree<CUtlSymbolTableLargeBaseTreeEntry_t *,int,CTreeEntryLess<CNonThreadsafeTree<1>,1>,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    v2 = `CUtlRBTree<CUtlSymbolTableLargeBaseTreeEntry_t *,int,CTreeEntryLess<CNonThreadsafeTree<1>,1>,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int>,int>>::Links'::`2'::`local static guard'
       | 1;
    `CUtlRBTree<CUtlSymbolTableLargeBaseTreeEntry_t *,int,CTreeEntryLess<CNonThreadsafeTree<1>,1>,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlSymbolTableLargeBaseTreeEntry_t *,int,CTreeEntryLess<CNonThreadsafeTree<1>,1>,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_1016CBA0 = -1;
    dword_1016CBA4 = -1;
    dword_1016CBA8 = 1;
  }
  if ( i == -1 )
    v3 = (UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int> *)&`CUtlRBTree<CUtlSymbolTableLargeBaseTreeEntry_t *,int,CTreeEntryLess<CNonThreadsafeTree<1>,1>,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v3 = &this->m_Elements.m_pMemory[i];
  m_Parent = v3->m_Parent;
  if ( (v2 & 1) == 0 )
  {
    `CUtlRBTree<CUtlSymbolTableLargeBaseTreeEntry_t *,int,CTreeEntryLess<CNonThreadsafeTree<1>,1>,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int>,int>>::Links'::`2'::`local static guard' = v2 | 1;
    `CUtlRBTree<CUtlSymbolTableLargeBaseTreeEntry_t *,int,CTreeEntryLess<CNonThreadsafeTree<1>,1>,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_1016CBA0 = -1;
    dword_1016CBA4 = -1;
    dword_1016CBA8 = 1;
  }
  if ( m_Parent == -1 )
    return `CUtlRBTree<CUtlSymbolTableLargeBaseTreeEntry_t *,int,CTreeEntryLess<CNonThreadsafeTree<1>,1>,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int>,int>>::Links'::`2'::s_Sentinel == i;
  else
    return this->m_Elements.m_pMemory[m_Parent].m_Left == i;
}

//------------------------------------------------------------------------------
// Address: 0x1000F440
// Name: public: bool CUtlRBTree<struct CUtlSymbolTableLargeBaseTreeEntry_t __near *,int,class CTreeEntryLess<class CNonThreadsafeTree<1>,1>,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlSymbolTableLargeBaseTreeEntry_t __near *,int>,int>>::IsRightChild(int)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CUtlRBTree<CUtlSymbolTableLargeBaseTreeEntry_t *,int,CTreeEntryLess<CNonThreadsafeTree<1>,1>,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int>,int>>::IsRightChild(
        CUtlRBTree<CUtlSymbolTableLargeBaseTreeEntry_t *,int,CTreeEntryLess<CNonThreadsafeTree<1>,1>,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int>,int> > *this,
        int i)
{
  int v2; // edx
  UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int> *v3; // eax
  int m_Parent; // eax

  v2 = `CUtlRBTree<CUtlSymbolTableLargeBaseTreeEntry_t *,int,CTreeEntryLess<CNonThreadsafeTree<1>,1>,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int>,int>>::Links'::`2'::`local static guard';
  if ( (`CUtlRBTree<CUtlSymbolTableLargeBaseTreeEntry_t *,int,CTreeEntryLess<CNonThreadsafeTree<1>,1>,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    v2 = `CUtlRBTree<CUtlSymbolTableLargeBaseTreeEntry_t *,int,CTreeEntryLess<CNonThreadsafeTree<1>,1>,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int>,int>>::Links'::`2'::`local static guard'
       | 1;
    `CUtlRBTree<CUtlSymbolTableLargeBaseTreeEntry_t *,int,CTreeEntryLess<CNonThreadsafeTree<1>,1>,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlSymbolTableLargeBaseTreeEntry_t *,int,CTreeEntryLess<CNonThreadsafeTree<1>,1>,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_1016CBA0 = -1;
    dword_1016CBA4 = -1;
    dword_1016CBA8 = 1;
  }
  if ( i == -1 )
    v3 = (UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int> *)&`CUtlRBTree<CUtlSymbolTableLargeBaseTreeEntry_t *,int,CTreeEntryLess<CNonThreadsafeTree<1>,1>,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v3 = &this->m_Elements.m_pMemory[i];
  m_Parent = v3->m_Parent;
  if ( (v2 & 1) == 0 )
  {
    `CUtlRBTree<CUtlSymbolTableLargeBaseTreeEntry_t *,int,CTreeEntryLess<CNonThreadsafeTree<1>,1>,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int>,int>>::Links'::`2'::`local static guard' = v2 | 1;
    `CUtlRBTree<CUtlSymbolTableLargeBaseTreeEntry_t *,int,CTreeEntryLess<CNonThreadsafeTree<1>,1>,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_1016CBA0 = -1;
    dword_1016CBA4 = -1;
    dword_1016CBA8 = 1;
  }
  if ( m_Parent == -1 )
    return dword_1016CBA0 == i;
  else
    return this->m_Elements.m_pMemory[m_Parent].m_Right == i;
}

//------------------------------------------------------------------------------
// Address: 0x1000F4F0
// Name: protected: void CUtlRBTree<struct CUtlSymbolTableLargeBaseTreeEntry_t __near *,int,class CTreeEntryLess<class CNonThreadsafeTree<1>,1>,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlSymbolTableLargeBaseTreeEntry_t __near *,int>,int>>::RotateLeft(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlSymbolTableLargeBaseTreeEntry_t *,int,CTreeEntryLess<CNonThreadsafeTree<1>,1>,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int>,int>>::RotateLeft(
        CUtlRBTree<CUtlSymbolTableLargeBaseTreeEntry_t *,int,CTreeEntryLess<CNonThreadsafeTree<1>,1>,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int>,int> > *this,
        int elem)
{
  int v2; // eax
  UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int> *v4; // ecx
  int m_Right; // edi
  UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int> *v6; // eax
  int v7; // eax
  UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int> *v8; // ecx
  UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int> *v9; // eax

  v2 = `CUtlRBTree<CUtlSymbolTableLargeBaseTreeEntry_t *,int,CTreeEntryLess<CNonThreadsafeTree<1>,1>,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int>,int>>::Links'::`2'::`local static guard';
  if ( (`CUtlRBTree<CUtlSymbolTableLargeBaseTreeEntry_t *,int,CTreeEntryLess<CNonThreadsafeTree<1>,1>,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    v2 = `CUtlRBTree<CUtlSymbolTableLargeBaseTreeEntry_t *,int,CTreeEntryLess<CNonThreadsafeTree<1>,1>,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int>,int>>::Links'::`2'::`local static guard'
       | 1;
    `CUtlRBTree<CUtlSymbolTableLargeBaseTreeEntry_t *,int,CTreeEntryLess<CNonThreadsafeTree<1>,1>,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlSymbolTableLargeBaseTreeEntry_t *,int,CTreeEntryLess<CNonThreadsafeTree<1>,1>,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_1016CBA0 = -1;
    dword_1016CBA4 = -1;
    dword_1016CBA8 = 1;
  }
  if ( elem == -1 )
    v4 = (UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int> *)&`CUtlRBTree<CUtlSymbolTableLargeBaseTreeEntry_t *,int,CTreeEntryLess<CNonThreadsafeTree<1>,1>,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v4 = &this->m_Elements.m_pMemory[elem];
  m_Right = v4->m_Right;
  if ( (v2 & 1) == 0 )
  {
    `CUtlRBTree<CUtlSymbolTableLargeBaseTreeEntry_t *,int,CTreeEntryLess<CNonThreadsafeTree<1>,1>,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int>,int>>::Links'::`2'::`local static guard' = v2 | 1;
    `CUtlRBTree<CUtlSymbolTableLargeBaseTreeEntry_t *,int,CTreeEntryLess<CNonThreadsafeTree<1>,1>,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_1016CBA0 = -1;
    dword_1016CBA4 = -1;
    dword_1016CBA8 = 1;
  }
  if ( m_Right == -1 )
    v6 = (UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int> *)&`CUtlRBTree<CUtlSymbolTableLargeBaseTreeEntry_t *,int,CTreeEntryLess<CNonThreadsafeTree<1>,1>,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v6 = &this->m_Elements.m_pMemory[m_Right];
  this->m_Elements.m_pMemory[elem].m_Right = v6->m_Left;
  v7 = `CUtlRBTree<CUtlSymbolTableLargeBaseTreeEntry_t *,int,CTreeEntryLess<CNonThreadsafeTree<1>,1>,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int>,int>>::Links'::`2'::`local static guard';
  if ( (`CUtlRBTree<CUtlSymbolTableLargeBaseTreeEntry_t *,int,CTreeEntryLess<CNonThreadsafeTree<1>,1>,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    v7 = `CUtlRBTree<CUtlSymbolTableLargeBaseTreeEntry_t *,int,CTreeEntryLess<CNonThreadsafeTree<1>,1>,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int>,int>>::Links'::`2'::`local static guard'
       | 1;
    `CUtlRBTree<CUtlSymbolTableLargeBaseTreeEntry_t *,int,CTreeEntryLess<CNonThreadsafeTree<1>,1>,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlSymbolTableLargeBaseTreeEntry_t *,int,CTreeEntryLess<CNonThreadsafeTree<1>,1>,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_1016CBA0 = -1;
    dword_1016CBA4 = -1;
    dword_1016CBA8 = 1;
  }
  if ( m_Right == -1 )
    v8 = (UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int> *)&`CUtlRBTree<CUtlSymbolTableLargeBaseTreeEntry_t *,int,CTreeEntryLess<CNonThreadsafeTree<1>,1>,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v8 = &this->m_Elements.m_pMemory[m_Right];
  if ( v8->m_Left != -1 )
  {
    if ( (v7 & 1) == 0 )
    {
      `CUtlRBTree<CUtlSymbolTableLargeBaseTreeEntry_t *,int,CTreeEntryLess<CNonThreadsafeTree<1>,1>,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int>,int>>::Links'::`2'::`local static guard' = v7 | 1;
      `CUtlRBTree<CUtlSymbolTableLargeBaseTreeEntry_t *,int,CTreeEntryLess<CNonThreadsafeTree<1>,1>,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int>,int>>::Links'::`2'::s_Sentinel = -1;
      dword_1016CBA0 = -1;
      dword_1016CBA4 = -1;
      dword_1016CBA8 = 1;
    }
    if ( m_Right == -1 )
      v9 = (UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int> *)&`CUtlRBTree<CUtlSymbolTableLargeBaseTreeEntry_t *,int,CTreeEntryLess<CNonThreadsafeTree<1>,1>,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int>,int>>::Links'::`2'::s_Sentinel;
    else
      v9 = &this->m_Elements.m_pMemory[m_Right];
    this->m_Elements.m_pMemory[v9->m_Left].m_Parent = elem;
  }
  if ( m_Right != -1 )
    this->m_Elements.m_pMemory[m_Right].m_Parent = CUtlRBTree<CUtlSymbolTableLargeBaseTreeEntry_t *,int,CTreeEntryLess<CNonThreadsafeTree<1>,1>,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int>,int>>::Parent(
                                                     this,
                                                     i: elem);
  if ( elem == this->m_Root )
  {
    this->m_Root = m_Right;
  }
  else if ( CUtlRBTree<CUtlSymbolTableLargeBaseTreeEntry_t *,int,CTreeEntryLess<CNonThreadsafeTree<1>,1>,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int>,int>>::IsLeftChild(
              this,
              i: elem) )
  {
    this->m_Elements.m_pMemory[CUtlRBTree<CUtlSymbolTableLargeBaseTreeEntry_t *,int,CTreeEntryLess<CNonThreadsafeTree<1>,1>,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int>,int>>::Parent(
                                 this,
                                 i: elem)].m_Left = m_Right;
  }
  else
  {
    this->m_Elements.m_pMemory[CUtlRBTree<CUtlSymbolTableLargeBaseTreeEntry_t *,int,CTreeEntryLess<CNonThreadsafeTree<1>,1>,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int>,int>>::Parent(
                                 this,
                                 i: elem)].m_Right = m_Right;
  }
  this->m_Elements.m_pMemory[m_Right].m_Left = elem;
  if ( elem != -1 )
    this->m_Elements.m_pMemory[elem].m_Parent = m_Right;
}

//------------------------------------------------------------------------------
// Address: 0x1000F6A0
// Name: protected: void CUtlRBTree<struct CUtlSymbolTableLargeBaseTreeEntry_t __near *,int,class CTreeEntryLess<class CNonThreadsafeTree<1>,1>,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlSymbolTableLargeBaseTreeEntry_t __near *,int>,int>>::RotateRight(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlSymbolTableLargeBaseTreeEntry_t *,int,CTreeEntryLess<CNonThreadsafeTree<1>,1>,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int>,int>>::RotateRight(
        CUtlRBTree<CUtlSymbolTableLargeBaseTreeEntry_t *,int,CTreeEntryLess<CNonThreadsafeTree<1>,1>,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int>,int> > *this,
        int elem)
{
  int v2; // eax
  UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int> *v4; // ecx
  int m_Left; // edi
  UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int> *v6; // eax
  UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int> *v7; // eax

  v2 = `CUtlRBTree<CUtlSymbolTableLargeBaseTreeEntry_t *,int,CTreeEntryLess<CNonThreadsafeTree<1>,1>,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int>,int>>::Links'::`2'::`local static guard';
  if ( (`CUtlRBTree<CUtlSymbolTableLargeBaseTreeEntry_t *,int,CTreeEntryLess<CNonThreadsafeTree<1>,1>,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    v2 = `CUtlRBTree<CUtlSymbolTableLargeBaseTreeEntry_t *,int,CTreeEntryLess<CNonThreadsafeTree<1>,1>,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int>,int>>::Links'::`2'::`local static guard'
       | 1;
    `CUtlRBTree<CUtlSymbolTableLargeBaseTreeEntry_t *,int,CTreeEntryLess<CNonThreadsafeTree<1>,1>,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlSymbolTableLargeBaseTreeEntry_t *,int,CTreeEntryLess<CNonThreadsafeTree<1>,1>,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_1016CBA0 = -1;
    dword_1016CBA4 = -1;
    dword_1016CBA8 = 1;
  }
  if ( elem == -1 )
    v4 = (UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int> *)&`CUtlRBTree<CUtlSymbolTableLargeBaseTreeEntry_t *,int,CTreeEntryLess<CNonThreadsafeTree<1>,1>,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v4 = &this->m_Elements.m_pMemory[elem];
  m_Left = v4->m_Left;
  if ( (v2 & 1) == 0 )
  {
    `CUtlRBTree<CUtlSymbolTableLargeBaseTreeEntry_t *,int,CTreeEntryLess<CNonThreadsafeTree<1>,1>,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int>,int>>::Links'::`2'::`local static guard' = v2 | 1;
    `CUtlRBTree<CUtlSymbolTableLargeBaseTreeEntry_t *,int,CTreeEntryLess<CNonThreadsafeTree<1>,1>,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_1016CBA0 = -1;
    dword_1016CBA4 = -1;
    dword_1016CBA8 = 1;
  }
  if ( m_Left == -1 )
    v6 = (UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int> *)&`CUtlRBTree<CUtlSymbolTableLargeBaseTreeEntry_t *,int,CTreeEntryLess<CNonThreadsafeTree<1>,1>,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v6 = &this->m_Elements.m_pMemory[m_Left];
  this->m_Elements.m_pMemory[elem].m_Left = v6->m_Right;
  if ( (`CUtlRBTree<CUtlSymbolTableLargeBaseTreeEntry_t *,int,CTreeEntryLess<CNonThreadsafeTree<1>,1>,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CUtlSymbolTableLargeBaseTreeEntry_t *,int,CTreeEntryLess<CNonThreadsafeTree<1>,1>,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlSymbolTableLargeBaseTreeEntry_t *,int,CTreeEntryLess<CNonThreadsafeTree<1>,1>,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_1016CBA0 = -1;
    dword_1016CBA4 = -1;
    dword_1016CBA8 = 1;
  }
  if ( m_Left == -1 )
    v7 = (UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int> *)&`CUtlRBTree<CUtlSymbolTableLargeBaseTreeEntry_t *,int,CTreeEntryLess<CNonThreadsafeTree<1>,1>,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v7 = &this->m_Elements.m_pMemory[m_Left];
  if ( v7->m_Right != -1 )
    this->m_Elements.m_pMemory[CUtlRBTree<CUtlSymbolTableLargeBaseTreeEntry_t *,int,CTreeEntryLess<CNonThreadsafeTree<1>,1>,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int>,int>>::RightChild(
                                 this,
                                 i: m_Left)].m_Parent = elem;
  if ( m_Left != -1 )
    this->m_Elements.m_pMemory[m_Left].m_Parent = CUtlRBTree<CUtlSymbolTableLargeBaseTreeEntry_t *,int,CTreeEntryLess<CNonThreadsafeTree<1>,1>,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int>,int>>::Parent(
                                                    this,
                                                    i: elem);
  if ( elem == this->m_Root )
  {
    this->m_Root = m_Left;
  }
  else if ( CUtlRBTree<CUtlSymbolTableLargeBaseTreeEntry_t *,int,CTreeEntryLess<CNonThreadsafeTree<1>,1>,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int>,int>>::IsRightChild(
              this,
              i: elem) )
  {
    this->m_Elements.m_pMemory[CUtlRBTree<CUtlSymbolTableLargeBaseTreeEntry_t *,int,CTreeEntryLess<CNonThreadsafeTree<1>,1>,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int>,int>>::Parent(
                                 this,
                                 i: elem)].m_Right = m_Left;
  }
  else
  {
    this->m_Elements.m_pMemory[CUtlRBTree<CUtlSymbolTableLargeBaseTreeEntry_t *,int,CTreeEntryLess<CNonThreadsafeTree<1>,1>,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int>,int>>::Parent(
                                 this,
                                 i: elem)].m_Left = m_Left;
  }
  this->m_Elements.m_pMemory[m_Left].m_Right = elem;
  if ( elem != -1 )
    this->m_Elements.m_pMemory[elem].m_Parent = m_Left;
}

//------------------------------------------------------------------------------
// Address: 0x1000F810
// Name: public: int CUtlRBTree<struct CUtlSymbolTableLargeBaseTreeEntry_t __near *,int,class CTreeEntryLess<class CNonThreadsafeTree<1>,1>,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlSymbolTableLargeBaseTreeEntry_t __near *,int>,int>>::Find(struct CUtlSymbolTableLargeBaseTreeEntry_t __near * const __near &)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<CUtlSymbolTableLargeBaseTreeEntry_t *,int,CTreeEntryLess<CNonThreadsafeTree<1>,1>,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int>,int>>::Find(
        CUtlRBTree<CUtlSymbolTableLargeBaseTreeEntry_t *,int,CTreeEntryLess<CNonThreadsafeTree<1>,1>,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int>,int> > *this,
        CUtlSymbolTableLargeBaseTreeEntry_t *const *search)
{
  int m_Root; // ebx
  unsigned int v3; // edx
  int v4; // esi
  CUtlSymbolTableLargeBaseTreeEntry_t *m_Data; // eax
  bool v6; // al
  CUtlSymbolTableLargeBaseTreeEntry_t *v7; // eax
  unsigned int v8; // edi
  bool v9; // al
  CUtlRBTree<CUtlSymbolTableLargeBaseTreeEntry_t *,int,CTreeEntryLess<CNonThreadsafeTree<1>,1>,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int>,int> > *v11; // [esp+4h] [ebp-4h]

  m_Root = this->m_Root;
  v11 = this;
  if ( m_Root != -1 )
  {
    while ( 1 )
    {
      v3 = **(_DWORD **)search;
      v4 = m_Root;
      m_Data = this->m_Elements.m_pMemory[m_Root].m_Data;
      if ( v3 == m_Data->m_Hash )
        v6 = _V_stricmp(s1: (*search)->m_String, s2: m_Data->m_String) < 0;
      else
        v6 = v3 < m_Data->m_Hash;
      if ( v6 )
      {
        if ( (`CUtlRBTree<CUtlSymbolTableLargeBaseTreeEntry_t *,int,CTreeEntryLess<CNonThreadsafeTree<1>,1>,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int>,int>>::Links'::`2'::`local static guard'
            & 1) == 0 )
        {
          `CUtlRBTree<CUtlSymbolTableLargeBaseTreeEntry_t *,int,CTreeEntryLess<CNonThreadsafeTree<1>,1>,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int>,int>>::Links'::`2'::`local static guard' |= 1u;
          `CUtlRBTree<CUtlSymbolTableLargeBaseTreeEntry_t *,int,CTreeEntryLess<CNonThreadsafeTree<1>,1>,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_1016CBA0 = -1;
          dword_1016CBA4 = -1;
          dword_1016CBA8 = 1;
        }
        m_Root = v11->m_Elements.m_pMemory[m_Root].m_Left;
      }
      else
      {
        v7 = v11->m_Elements.m_pMemory[v4].m_Data;
        v8 = **(_DWORD **)search;
        if ( v7->m_Hash == v8 )
          v9 = _V_stricmp(s1: v7->m_String, s2: (*search)->m_String) < 0;
        else
          v9 = v7->m_Hash < v8;
        if ( !v9 )
          return m_Root;
        if ( (`CUtlRBTree<CUtlSymbolTableLargeBaseTreeEntry_t *,int,CTreeEntryLess<CNonThreadsafeTree<1>,1>,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int>,int>>::Links'::`2'::`local static guard'
            & 1) == 0 )
        {
          `CUtlRBTree<CUtlSymbolTableLargeBaseTreeEntry_t *,int,CTreeEntryLess<CNonThreadsafeTree<1>,1>,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int>,int>>::Links'::`2'::`local static guard' |= 1u;
          `CUtlRBTree<CUtlSymbolTableLargeBaseTreeEntry_t *,int,CTreeEntryLess<CNonThreadsafeTree<1>,1>,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_1016CBA0 = -1;
          dword_1016CBA4 = -1;
          dword_1016CBA8 = 1;
        }
        m_Root = v11->m_Elements.m_pMemory[v4].m_Right;
      }
      if ( m_Root == -1 )
        return m_Root;
      this = v11;
    }
  }
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x1000F960
// Name: public: void CUtlRBTree<struct CUtlSymbolTableLargeBaseTreeEntry_t __near *,int,class CTreeEntryLess<class CNonThreadsafeTree<1>,1>,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlSymbolTableLargeBaseTreeEntry_t __near *,int>,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlSymbolTableLargeBaseTreeEntry_t *,int,CTreeEntryLess<CNonThreadsafeTree<1>,1>,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int>,int>>::RemoveAll(
        CUtlRBTree<CUtlSymbolTableLargeBaseTreeEntry_t *,int,CTreeEntryLess<CNonThreadsafeTree<1>,1>,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int>,int> > *this)
{
  int index; // edx
  int v2; // eax
  int v3; // edx

  index = this->m_LastAlloc.index;
  if ( index != -1 )
  {
    v2 = (this->m_Elements.m_nAllocationCount > 0) - 1;
    if ( this->m_Elements.m_nAllocationCount > 0 )
    {
      do
      {
        if ( v2 >= 0 && v2 < this->m_Elements.m_nAllocationCount && v2 <= index )
        {
          if ( (`CUtlRBTree<CUtlSymbolTableLargeBaseTreeEntry_t *,int,CTreeEntryLess<CNonThreadsafeTree<1>,1>,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int>,int>>::Links'::`2'::`local static guard'
              & 1) == 0 )
          {
            `CUtlRBTree<CUtlSymbolTableLargeBaseTreeEntry_t *,int,CTreeEntryLess<CNonThreadsafeTree<1>,1>,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int>,int>>::Links'::`2'::`local static guard' |= 1u;
            `CUtlRBTree<CUtlSymbolTableLargeBaseTreeEntry_t *,int,CTreeEntryLess<CNonThreadsafeTree<1>,1>,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_1016CBA0 = -1;
            dword_1016CBA4 = -1;
            dword_1016CBA8 = 1;
          }
          if ( this->m_Elements.m_pMemory[v2].m_Left != v2 )
          {
            v3 = v2;
            this->m_Elements.m_pMemory[v3].m_Right = this->m_FirstFree;
            this->m_Elements.m_pMemory[v3].m_Left = v2;
            this->m_FirstFree = v2;
          }
        }
        index = this->m_LastAlloc.index;
        if ( v2 == index )
          break;
        if ( ++v2 < 0 || v2 >= this->m_Elements.m_nAllocationCount )
          v2 = -1;
      }
      while ( v2 != -1 );
    }
    this->m_Root = -1;
    this->m_NumElements = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000FA20
// Name: protected: void CUtlRBTree<struct CUtlSymbolTableLargeBaseTreeEntry_t __near *,int,class CTreeEntryLess<class CNonThreadsafeTree<1>,1>,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlSymbolTableLargeBaseTreeEntry_t __near *,int>,int>>::InsertRebalance(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlSymbolTableLargeBaseTreeEntry_t *,int,CTreeEntryLess<CNonThreadsafeTree<1>,1>,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int>,int>>::InsertRebalance(
        CUtlRBTree<CUtlSymbolTableLargeBaseTreeEntry_t *,int,CTreeEntryLess<CNonThreadsafeTree<1>,1>,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int>,int> > *this,
        int elem)
{
  int v2; // edx
  int v4; // eax
  UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int> *v5; // ecx
  int m_Parent; // ecx
  UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int> *v7; // ecx
  UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int> *v8; // ecx
  int v9; // esi
  UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int> *v10; // eax
  int v11; // edi
  bool IsLeftChild; // al
  int v13; // ecx
  UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int> *v14; // eax
  int m_Right; // eax
  UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int> *v16; // ecx
  int v17; // eax
  UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int> *v18; // ecx
  UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int> *v19; // eax
  UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int> *v20; // eax
  UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int> *v21; // ecx
  int v22; // eax
  UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int> *v23; // ecx
  UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int> *v24; // eax

  v2 = elem;
  if ( elem != this->m_Root )
  {
    while ( 1 )
    {
      v4 = `CUtlRBTree<CUtlSymbolTableLargeBaseTreeEntry_t *,int,CTreeEntryLess<CNonThreadsafeTree<1>,1>,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int>,int>>::Links'::`2'::`local static guard';
      if ( (`CUtlRBTree<CUtlSymbolTableLargeBaseTreeEntry_t *,int,CTreeEntryLess<CNonThreadsafeTree<1>,1>,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int>,int>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        v4 = `CUtlRBTree<CUtlSymbolTableLargeBaseTreeEntry_t *,int,CTreeEntryLess<CNonThreadsafeTree<1>,1>,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int>,int>>::Links'::`2'::`local static guard'
           | 1;
        `CUtlRBTree<CUtlSymbolTableLargeBaseTreeEntry_t *,int,CTreeEntryLess<CNonThreadsafeTree<1>,1>,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int>,int>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CUtlSymbolTableLargeBaseTreeEntry_t *,int,CTreeEntryLess<CNonThreadsafeTree<1>,1>,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_1016CBA0 = -1;
        dword_1016CBA4 = -1;
        dword_1016CBA8 = 1;
      }
      if ( v2 == -1 )
        v5 = (UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int> *)&`CUtlRBTree<CUtlSymbolTableLargeBaseTreeEntry_t *,int,CTreeEntryLess<CNonThreadsafeTree<1>,1>,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int>,int>>::Links'::`2'::s_Sentinel;
      else
        v5 = &this->m_Elements.m_pMemory[v2];
      m_Parent = v5->m_Parent;
      if ( (v4 & 1) == 0 )
      {
        v4 |= 1u;
        `CUtlRBTree<CUtlSymbolTableLargeBaseTreeEntry_t *,int,CTreeEntryLess<CNonThreadsafeTree<1>,1>,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int>,int>>::Links'::`2'::`local static guard' = v4;
        `CUtlRBTree<CUtlSymbolTableLargeBaseTreeEntry_t *,int,CTreeEntryLess<CNonThreadsafeTree<1>,1>,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_1016CBA0 = -1;
        dword_1016CBA4 = -1;
        dword_1016CBA8 = 1;
      }
      if ( m_Parent == -1 )
        v7 = (UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int> *)&`CUtlRBTree<CUtlSymbolTableLargeBaseTreeEntry_t *,int,CTreeEntryLess<CNonThreadsafeTree<1>,1>,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int>,int>>::Links'::`2'::s_Sentinel;
      else
        v7 = &this->m_Elements.m_pMemory[m_Parent];
      if ( v7->m_Tag != 0 )
        break;
      if ( (v4 & 1) == 0 )
      {
        v4 |= 1u;
        `CUtlRBTree<CUtlSymbolTableLargeBaseTreeEntry_t *,int,CTreeEntryLess<CNonThreadsafeTree<1>,1>,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int>,int>>::Links'::`2'::`local static guard' = v4;
        `CUtlRBTree<CUtlSymbolTableLargeBaseTreeEntry_t *,int,CTreeEntryLess<CNonThreadsafeTree<1>,1>,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_1016CBA0 = -1;
        dword_1016CBA4 = -1;
        dword_1016CBA8 = 1;
      }
      if ( v2 == -1 )
        v8 = (UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int> *)&`CUtlRBTree<CUtlSymbolTableLargeBaseTreeEntry_t *,int,CTreeEntryLess<CNonThreadsafeTree<1>,1>,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int>,int>>::Links'::`2'::s_Sentinel;
      else
        v8 = &this->m_Elements.m_pMemory[v2];
      v9 = v8->m_Parent;
      if ( (v4 & 1) == 0 )
      {
        `CUtlRBTree<CUtlSymbolTableLargeBaseTreeEntry_t *,int,CTreeEntryLess<CNonThreadsafeTree<1>,1>,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int>,int>>::Links'::`2'::`local static guard' = v4 | 1;
        `CUtlRBTree<CUtlSymbolTableLargeBaseTreeEntry_t *,int,CTreeEntryLess<CNonThreadsafeTree<1>,1>,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_1016CBA0 = -1;
        dword_1016CBA4 = -1;
        dword_1016CBA8 = 1;
      }
      if ( v9 == -1 )
        v10 = (UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int> *)&`CUtlRBTree<CUtlSymbolTableLargeBaseTreeEntry_t *,int,CTreeEntryLess<CNonThreadsafeTree<1>,1>,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int>,int>>::Links'::`2'::s_Sentinel;
      else
        v10 = &this->m_Elements.m_pMemory[v9];
      v11 = v10->m_Parent;
      IsLeftChild = CUtlRBTree<CUtlSymbolTableLargeBaseTreeEntry_t *,int,CTreeEntryLess<CNonThreadsafeTree<1>,1>,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int>,int>>::IsLeftChild(
                      this,
                      i: v9);
      v13 = `CUtlRBTree<CUtlSymbolTableLargeBaseTreeEntry_t *,int,CTreeEntryLess<CNonThreadsafeTree<1>,1>,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int>,int>>::Links'::`2'::`local static guard';
      if ( IsLeftChild )
      {
        if ( (`CUtlRBTree<CUtlSymbolTableLargeBaseTreeEntry_t *,int,CTreeEntryLess<CNonThreadsafeTree<1>,1>,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int>,int>>::Links'::`2'::`local static guard'
            & 1) == 0 )
        {
          v13 = `CUtlRBTree<CUtlSymbolTableLargeBaseTreeEntry_t *,int,CTreeEntryLess<CNonThreadsafeTree<1>,1>,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int>,int>>::Links'::`2'::`local static guard'
              | 1;
          `CUtlRBTree<CUtlSymbolTableLargeBaseTreeEntry_t *,int,CTreeEntryLess<CNonThreadsafeTree<1>,1>,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int>,int>>::Links'::`2'::`local static guard' |= 1u;
          `CUtlRBTree<CUtlSymbolTableLargeBaseTreeEntry_t *,int,CTreeEntryLess<CNonThreadsafeTree<1>,1>,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_1016CBA0 = -1;
          dword_1016CBA4 = -1;
          dword_1016CBA8 = 1;
        }
        if ( v11 == -1 )
          v14 = (UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int> *)&`CUtlRBTree<CUtlSymbolTableLargeBaseTreeEntry_t *,int,CTreeEntryLess<CNonThreadsafeTree<1>,1>,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int>,int>>::Links'::`2'::s_Sentinel;
        else
          v14 = &this->m_Elements.m_pMemory[v11];
        m_Right = v14->m_Right;
        if ( (v13 & 1) == 0 )
        {
          `CUtlRBTree<CUtlSymbolTableLargeBaseTreeEntry_t *,int,CTreeEntryLess<CNonThreadsafeTree<1>,1>,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int>,int>>::Links'::`2'::`local static guard' = v13 | 1;
          `CUtlRBTree<CUtlSymbolTableLargeBaseTreeEntry_t *,int,CTreeEntryLess<CNonThreadsafeTree<1>,1>,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_1016CBA0 = -1;
          dword_1016CBA4 = -1;
          dword_1016CBA8 = 1;
        }
        if ( m_Right == -1 )
          v16 = (UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int> *)&`CUtlRBTree<CUtlSymbolTableLargeBaseTreeEntry_t *,int,CTreeEntryLess<CNonThreadsafeTree<1>,1>,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int>,int>>::Links'::`2'::s_Sentinel;
        else
          v16 = &this->m_Elements.m_pMemory[m_Right];
        if ( v16->m_Tag == 0 )
          goto LABEL_61;
        if ( CUtlRBTree<CUtlSymbolTableLargeBaseTreeEntry_t *,int,CTreeEntryLess<CNonThreadsafeTree<1>,1>,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int>,int>>::IsRightChild(
               this,
               i: elem) )
        {
          elem = v9;
          CUtlRBTree<CUtlSymbolTableLargeBaseTreeEntry_t *,int,CTreeEntryLess<CNonThreadsafeTree<1>,1>,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int>,int>>::RotateLeft(
            this,
            elem: v9);
          v17 = `CUtlRBTree<CUtlSymbolTableLargeBaseTreeEntry_t *,int,CTreeEntryLess<CNonThreadsafeTree<1>,1>,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int>,int>>::Links'::`2'::`local static guard';
          if ( (`CUtlRBTree<CUtlSymbolTableLargeBaseTreeEntry_t *,int,CTreeEntryLess<CNonThreadsafeTree<1>,1>,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int>,int>>::Links'::`2'::`local static guard'
              & 1) == 0 )
          {
            v17 = `CUtlRBTree<CUtlSymbolTableLargeBaseTreeEntry_t *,int,CTreeEntryLess<CNonThreadsafeTree<1>,1>,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int>,int>>::Links'::`2'::`local static guard'
                | 1;
            `CUtlRBTree<CUtlSymbolTableLargeBaseTreeEntry_t *,int,CTreeEntryLess<CNonThreadsafeTree<1>,1>,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int>,int>>::Links'::`2'::`local static guard' |= 1u;
            `CUtlRBTree<CUtlSymbolTableLargeBaseTreeEntry_t *,int,CTreeEntryLess<CNonThreadsafeTree<1>,1>,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_1016CBA0 = -1;
            dword_1016CBA4 = -1;
            dword_1016CBA8 = 1;
          }
          if ( v9 == -1 )
            v18 = (UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int> *)&`CUtlRBTree<CUtlSymbolTableLargeBaseTreeEntry_t *,int,CTreeEntryLess<CNonThreadsafeTree<1>,1>,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int>,int>>::Links'::`2'::s_Sentinel;
          else
            v18 = &this->m_Elements.m_pMemory[v9];
          v9 = v18->m_Parent;
          if ( (v17 & 1) == 0 )
          {
            `CUtlRBTree<CUtlSymbolTableLargeBaseTreeEntry_t *,int,CTreeEntryLess<CNonThreadsafeTree<1>,1>,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int>,int>>::Links'::`2'::`local static guard' = v17 | 1;
            `CUtlRBTree<CUtlSymbolTableLargeBaseTreeEntry_t *,int,CTreeEntryLess<CNonThreadsafeTree<1>,1>,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_1016CBA0 = -1;
            dword_1016CBA4 = -1;
            dword_1016CBA8 = 1;
          }
          if ( v9 == -1 )
            v19 = (UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int> *)&`CUtlRBTree<CUtlSymbolTableLargeBaseTreeEntry_t *,int,CTreeEntryLess<CNonThreadsafeTree<1>,1>,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int>,int>>::Links'::`2'::s_Sentinel;
          else
            v19 = &this->m_Elements.m_pMemory[v9];
          v11 = v19->m_Parent;
        }
        this->m_Elements.m_pMemory[v9].m_Tag = 1;
        this->m_Elements.m_pMemory[v11].m_Tag = 0;
        CUtlRBTree<CUtlSymbolTableLargeBaseTreeEntry_t *,int,CTreeEntryLess<CNonThreadsafeTree<1>,1>,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int>,int>>::RotateRight(
          this,
          elem: v11);
      }
      else
      {
        if ( (`CUtlRBTree<CUtlSymbolTableLargeBaseTreeEntry_t *,int,CTreeEntryLess<CNonThreadsafeTree<1>,1>,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int>,int>>::Links'::`2'::`local static guard'
            & 1) == 0 )
        {
          v13 = `CUtlRBTree<CUtlSymbolTableLargeBaseTreeEntry_t *,int,CTreeEntryLess<CNonThreadsafeTree<1>,1>,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int>,int>>::Links'::`2'::`local static guard'
              | 1;
          `CUtlRBTree<CUtlSymbolTableLargeBaseTreeEntry_t *,int,CTreeEntryLess<CNonThreadsafeTree<1>,1>,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int>,int>>::Links'::`2'::`local static guard' |= 1u;
          `CUtlRBTree<CUtlSymbolTableLargeBaseTreeEntry_t *,int,CTreeEntryLess<CNonThreadsafeTree<1>,1>,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_1016CBA0 = -1;
          dword_1016CBA4 = -1;
          dword_1016CBA8 = 1;
        }
        if ( v11 == -1 )
          v20 = (UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int> *)&`CUtlRBTree<CUtlSymbolTableLargeBaseTreeEntry_t *,int,CTreeEntryLess<CNonThreadsafeTree<1>,1>,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int>,int>>::Links'::`2'::s_Sentinel;
        else
          v20 = &this->m_Elements.m_pMemory[v11];
        m_Right = v20->m_Left;
        if ( (v13 & 1) == 0 )
        {
          `CUtlRBTree<CUtlSymbolTableLargeBaseTreeEntry_t *,int,CTreeEntryLess<CNonThreadsafeTree<1>,1>,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int>,int>>::Links'::`2'::`local static guard' = v13 | 1;
          `CUtlRBTree<CUtlSymbolTableLargeBaseTreeEntry_t *,int,CTreeEntryLess<CNonThreadsafeTree<1>,1>,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_1016CBA0 = -1;
          dword_1016CBA4 = -1;
          dword_1016CBA8 = 1;
        }
        if ( m_Right == -1 )
          v21 = (UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int> *)&`CUtlRBTree<CUtlSymbolTableLargeBaseTreeEntry_t *,int,CTreeEntryLess<CNonThreadsafeTree<1>,1>,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int>,int>>::Links'::`2'::s_Sentinel;
        else
          v21 = &this->m_Elements.m_pMemory[m_Right];
        if ( v21->m_Tag == 0 )
        {
LABEL_61:
          this->m_Elements.m_pMemory[v9].m_Tag = 1;
          this->m_Elements.m_pMemory[m_Right].m_Tag = 1;
          this->m_Elements.m_pMemory[v11].m_Tag = 0;
          elem = v11;
          goto LABEL_75;
        }
        if ( CUtlRBTree<CUtlSymbolTableLargeBaseTreeEntry_t *,int,CTreeEntryLess<CNonThreadsafeTree<1>,1>,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int>,int>>::IsLeftChild(
               this,
               i: elem) )
        {
          elem = v9;
          CUtlRBTree<CUtlSymbolTableLargeBaseTreeEntry_t *,int,CTreeEntryLess<CNonThreadsafeTree<1>,1>,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int>,int>>::RotateRight(
            this,
            elem: v9);
          v22 = `CUtlRBTree<CUtlSymbolTableLargeBaseTreeEntry_t *,int,CTreeEntryLess<CNonThreadsafeTree<1>,1>,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int>,int>>::Links'::`2'::`local static guard';
          if ( (`CUtlRBTree<CUtlSymbolTableLargeBaseTreeEntry_t *,int,CTreeEntryLess<CNonThreadsafeTree<1>,1>,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int>,int>>::Links'::`2'::`local static guard'
              & 1) == 0 )
          {
            v22 = `CUtlRBTree<CUtlSymbolTableLargeBaseTreeEntry_t *,int,CTreeEntryLess<CNonThreadsafeTree<1>,1>,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int>,int>>::Links'::`2'::`local static guard'
                | 1;
            `CUtlRBTree<CUtlSymbolTableLargeBaseTreeEntry_t *,int,CTreeEntryLess<CNonThreadsafeTree<1>,1>,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int>,int>>::Links'::`2'::`local static guard' |= 1u;
            `CUtlRBTree<CUtlSymbolTableLargeBaseTreeEntry_t *,int,CTreeEntryLess<CNonThreadsafeTree<1>,1>,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_1016CBA0 = -1;
            dword_1016CBA4 = -1;
            dword_1016CBA8 = 1;
          }
          if ( v9 == -1 )
            v23 = (UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int> *)&`CUtlRBTree<CUtlSymbolTableLargeBaseTreeEntry_t *,int,CTreeEntryLess<CNonThreadsafeTree<1>,1>,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int>,int>>::Links'::`2'::s_Sentinel;
          else
            v23 = &this->m_Elements.m_pMemory[v9];
          v9 = v23->m_Parent;
          if ( (v22 & 1) == 0 )
          {
            `CUtlRBTree<CUtlSymbolTableLargeBaseTreeEntry_t *,int,CTreeEntryLess<CNonThreadsafeTree<1>,1>,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int>,int>>::Links'::`2'::`local static guard' = v22 | 1;
            `CUtlRBTree<CUtlSymbolTableLargeBaseTreeEntry_t *,int,CTreeEntryLess<CNonThreadsafeTree<1>,1>,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_1016CBA0 = -1;
            dword_1016CBA4 = -1;
            dword_1016CBA8 = 1;
          }
          if ( v9 == -1 )
            v24 = (UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int> *)&`CUtlRBTree<CUtlSymbolTableLargeBaseTreeEntry_t *,int,CTreeEntryLess<CNonThreadsafeTree<1>,1>,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int>,int>>::Links'::`2'::s_Sentinel;
          else
            v24 = &this->m_Elements.m_pMemory[v9];
          v11 = v24->m_Parent;
        }
        this->m_Elements.m_pMemory[v9].m_Tag = 1;
        this->m_Elements.m_pMemory[v11].m_Tag = 0;
        CUtlRBTree<CUtlSymbolTableLargeBaseTreeEntry_t *,int,CTreeEntryLess<CNonThreadsafeTree<1>,1>,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int>,int>>::RotateLeft(
          this,
          elem: v11);
      }
LABEL_75:
      if ( elem == this->m_Root )
        break;
      v2 = elem;
    }
  }
  this->m_Elements.m_pMemory[this->m_Root].m_Tag = 1;
}

//------------------------------------------------------------------------------
// Address: 0x1000FE80
// Name: SendFileContentsToMaster
// Source: json
//------------------------------------------------------------------------------
void __cdecl SendFileContentsToMaster(char *pFilename)
{
  HANDLE FileA; // eax
  DWORD FileSize; // esi
  void *v3; // edi
  CUtlBuffer myBuffer; // [esp+4h] [ebp-44h] BYREF
  PS3ShaderDebugInfoPacket_t filePacket; // [esp+34h] [ebp-14h] BYREF
  void *fileHandle; // [esp+40h] [ebp-8h]
  unsigned int bytesRead; // [esp+44h] [ebp-4h] BYREF

  FileA = CreateFileA(
            lpFileName: pFilename,
            dwDesiredAccess: 0x80000000,
            dwShareMode: 0,
            lpSecurityAttributes: nullptr,
            dwCreationDisposition: 3u,
            dwFlagsAndAttributes: 0x80u,
            hTemplateFile: nullptr);
  fileHandle = FileA;
  if ( FileA != (HANDLE)-1 )
  {
    FileSize = GetFileSize(hFile: FileA, lpFileSizeHigh: nullptr);
    v3 = operator new(nSize: FileSize);
    ReadFile(
      hFile: fileHandle,
      lpBuffer: v3,
      nNumberOfBytesToRead: FileSize,
      lpNumberOfBytesRead: &bytesRead,
      lpOverlapped: nullptr);
    if ( bytesRead == FileSize )
    {
      filePacket.m_PacketID = 6;
      filePacket.m_nFileNameLength = _V_strlen(str: pFilename) + 1;
      filePacket.m_nFileDataLength = bytesRead;
      CUtlBuffer::CUtlBuffer(this: &myBuffer, growSize: 0, initSize: 0, nFlags: 0);
      CUtlBuffer::Put(this: &myBuffer, pMem: &filePacket, size: 12);
      CUtlBuffer::Put(this: &myBuffer, pMem: pFilename, size: filePacket.m_nFileNameLength);
      CUtlBuffer::Put(this: &myBuffer, pMem: v3, size: filePacket.m_nFileDataLength);
      VMPI_SendData(
        pData: myBuffer.m_Memory.m_pMemory,
        nBytes: filePacket.m_nFileDataLength + filePacket.m_nFileNameLength + 12,
        iDest: 0,
        fVMPISendFlags: 0);
      if ( myBuffer.m_Memory.m_nGrowSize >= 0 && myBuffer.m_Memory.m_pMemory != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: myBuffer.m_Memory.m_pMemory);
    }
    free(pMem: v3);
    CloseHandle(hObject: fileHandle);
    unlink(path: pFilename);
  }
  fopen(file: (_iobuf *)pFilename, mode: "r");
}

//------------------------------------------------------------------------------
// Address: 0x1000FFA0
// Name: void SendSubDirectoryToMaster(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SendSubDirectoryToMaster(const char *pStartingPath)
{
  ForEachFileRecursive_void____cdecl___char_const____(
    pStartingPath,
    callbackFunction: (void (__cdecl *)(const char *))SendFileContentsToMaster);
}

//------------------------------------------------------------------------------
// Address: 0x1000FFC0
// Name: protected: void CUtlRBTree<struct CUtlSymbolTableLargeBaseTreeEntry_t __near *,int,class CTreeEntryLess<class CNonThreadsafeTree<1>,1>,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlSymbolTableLargeBaseTreeEntry_t __near *,int>,int>>::LinkToParent(int,int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlSymbolTableLargeBaseTreeEntry_t *,int,CTreeEntryLess<CNonThreadsafeTree<1>,1>,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int>,int>>::LinkToParent(
        CUtlRBTree<CUtlSymbolTableLargeBaseTreeEntry_t *,int,CTreeEntryLess<CNonThreadsafeTree<1>,1>,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int>,int> > *this,
        int i,
        int parent,
        bool isLeft)
{
  UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int> *v4; // eax
  UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int> *m_pMemory; // edx

  v4 = &this->m_Elements.m_pMemory[i];
  v4->m_Parent = parent;
  v4->m_Right = -1;
  v4->m_Left = -1;
  v4->m_Tag = 0;
  if ( parent == -1 )
  {
    this->m_Root = i;
    CUtlRBTree<CUtlSymbolTableLargeBaseTreeEntry_t *,int,CTreeEntryLess<CNonThreadsafeTree<1>,1>,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int>,int>>::InsertRebalance(
      this,
      elem: i);
  }
  else
  {
    m_pMemory = this->m_Elements.m_pMemory;
    if ( isLeft )
      m_pMemory[parent].m_Left = i;
    else
      m_pMemory[parent].m_Right = i;
    CUtlRBTree<CUtlSymbolTableLargeBaseTreeEntry_t *,int,CTreeEntryLess<CNonThreadsafeTree<1>,1>,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int>,int>>::InsertRebalance(
      this,
      elem: i);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10010030
// Name: public: class CUtlSymbolLarge CUtlSymbolTableLargeBase<class CNonThreadsafeTree<1>,1>::Find(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
CUtlSymbolLarge *__thiscall CUtlSymbolTableLargeBase<CNonThreadsafeTree<1>,1>::Find(
        CUtlSymbolTableLargeBase<CNonThreadsafeTree<1>,1> *this,
        CUtlSymbolLarge *result,
        const char *pString)
{
  const char *v3; // ebx
  int v5; // eax
  int v6; // esi
  void *v7; // esp
  CUtlRBTree<CUtlSymbolTableLargeBaseTreeEntry_t *,int,CTreeEntryLess<CNonThreadsafeTree<1>,1>,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int>,int> > *v8; // esi
  int v9; // eax
  CUtlSymbolTableLargeBaseTreeEntry_t *m_Data; // ecx
  unsigned int v11; // [esp+0h] [ebp-10h] BYREF
  int v12; // [esp+4h] [ebp-Ch] BYREF
  CUtlRBTree<CUtlSymbolTableLargeBaseTreeEntry_t *,int,CTreeEntryLess<CNonThreadsafeTree<1>,1>,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int>,int> > *p_m_Lookup; // [esp+Ch] [ebp-4h]

  v3 = pString;
  p_m_Lookup = &this->m_Lookup;
  if ( pString == nullptr )
    goto LABEL_2;
  v5 = _V_strlen(str: pString);
  v6 = v5 + 1;
  v7 = alloca(v5 + 5);
  v11 = HashStringCaseless(pszKey: v3);
  _V_memcpy(dest: &v12, src: v3, count: v6);
  v8 = p_m_Lookup;
  pString = (const char *)&v11;
  v9 = CUtlRBTree<CUtlSymbolTableLargeBaseTreeEntry_t *,int,CTreeEntryLess<CNonThreadsafeTree<1>,1>,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int>,int>>::Find(
         this: p_m_Lookup,
         search: (CUtlSymbolTableLargeBaseTreeEntry_t *const *)&pString);
  if ( v9 == -1 )
  {
LABEL_2:
    result->u.m_Id = -1;
    return result;
  }
  else
  {
    m_Data = v8->m_Elements.m_pMemory[v9].m_Data;
    result->u.m_Id = (int)m_Data->m_String;
    return result;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100100C0
// Name: public: void CUtlSymbolTableLargeBase<class CNonThreadsafeTree<1>,1>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlSymbolTableLargeBase<CNonThreadsafeTree<1>,1>::RemoveAll(
        CUtlSymbolTableLargeBase<CNonThreadsafeTree<1>,1> *this)
{
  int i; // edi

  CUtlRBTree<CUtlSymbolTableLargeBaseTreeEntry_t *,int,CTreeEntryLess<CNonThreadsafeTree<1>,1>,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int>,int>>::RemoveAll(this: &this->m_Lookup);
  this->m_Lookup.m_FirstFree = -1;
  if ( this->m_Lookup.m_Elements.m_nGrowSize >= 0 )
  {
    if ( this->m_Lookup.m_Elements.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Lookup.m_Elements.m_pMemory);
      this->m_Lookup.m_Elements.m_pMemory = nullptr;
    }
    this->m_Lookup.m_Elements.m_nAllocationCount = 0;
  }
  this->m_Lookup.m_LastAlloc.index = -1;
  for ( i = 0; i < this->m_StringPools.m_Size; ++i )
    free(pMem: this->m_StringPools.m_Memory.m_pMemory[i]);
  this->m_StringPools.m_Size = 0;
}

//------------------------------------------------------------------------------
// Address: 0x10010120
// Name: public: CUtlRBTree<struct CUtlSymbolTableLargeBaseTreeEntry_t __near *,int,class CTreeEntryLess<class CNonThreadsafeTree<1>,1>,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlSymbolTableLargeBaseTreeEntry_t __near *,int>,int>>::~CUtlRBTree<struct CUtlSymbolTableLargeBaseTreeEntry_t __near *,int,class CTreeEntryLess<class CNonThreadsafeTree<1>,1>,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlSymbolTableLargeBaseTreeEntry_t __near *,int>,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlSymbolTableLargeBaseTreeEntry_t *,int,CTreeEntryLess<CNonThreadsafeTree<1>,1>,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int>,int>>::~CUtlRBTree<CUtlSymbolTableLargeBaseTreeEntry_t *,int,CTreeEntryLess<CNonThreadsafeTree<1>,1>,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int>,int>>(
        CUtlRBTree<CUtlSymbolTableLargeBaseTreeEntry_t *,int,CTreeEntryLess<CNonThreadsafeTree<1>,1>,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int>,int> > *this)
{
  CUtlRBTree<CUtlSymbolTableLargeBaseTreeEntry_t *,int,CTreeEntryLess<CNonThreadsafeTree<1>,1>,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int>,int>>::RemoveAll(this);
  this->m_FirstFree = -1;
  if ( this->m_Elements.m_nGrowSize >= 0 )
  {
    if ( this->m_Elements.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Elements.m_pMemory);
      this->m_Elements.m_pMemory = nullptr;
    }
    this->m_Elements.m_nAllocationCount = 0;
  }
  this->m_LastAlloc.index = -1;
  if ( this->m_Elements.m_nGrowSize >= 0 )
  {
    if ( this->m_Elements.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Elements.m_pMemory);
      this->m_Elements.m_pMemory = nullptr;
    }
    this->m_Elements.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10010180
// Name: public: CUtlSymbolTableLargeBase<class CNonThreadsafeTree<1>,1>::CUtlSymbolTableLargeBase<class CNonThreadsafeTree<1>,1>(void)
// Source: json
//------------------------------------------------------------------------------
CUtlSymbolTableLargeBase<CNonThreadsafeTree<1>,1> *__thiscall CUtlSymbolTableLargeBase<CNonThreadsafeTree<1>,1>::CUtlSymbolTableLargeBase<CNonThreadsafeTree<1>,1>(
        CUtlSymbolTableLargeBase<CNonThreadsafeTree<1>,1> *this)
{
  this->m_Lookup.m_Elements.m_pMemory = nullptr;
  this->m_Lookup.m_Elements.m_nAllocationCount = 16;
  this->m_Lookup.m_Elements.m_nGrowSize = 0;
  this->m_Lookup.m_Elements.m_pMemory = (UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int> *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 320);
  this->m_Lookup.m_NumElements = 0;
  this->m_Lookup.m_Root = -1;
  this->m_Lookup.m_FirstFree = -1;
  this->m_Lookup.m_LastAlloc.index = -1;
  this->m_Lookup.m_pElements = this->m_Lookup.m_Elements.m_pMemory;
  this->m_StringPools.m_Memory.m_pMemory = nullptr;
  this->m_StringPools.m_Memory.m_nAllocationCount = 0;
  this->m_StringPools.m_Size = 0;
  this->m_StringPools.m_pElements = nullptr;
  this->m_StringPools.m_Memory.m_nGrowSize = 8;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100101E0
// Name: public: int CNonThreadsafeTree<1>::Insert(struct CUtlSymbolTableLargeBaseTreeEntry_t __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CNonThreadsafeTree<1>::Insert(CNonThreadsafeTree<1> *this, CUtlSymbolTableLargeBaseTreeEntry_t *entry)
{
  int v3; // edi
  UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int> *m_pMemory; // eax
  CUtlSymbolTableLargeBaseTreeEntry_t **p_m_Data; // eax
  int parent; // [esp+8h] [ebp-8h] BYREF
  bool leftchild[4]; // [esp+Ch] [ebp-4h] BYREF

  parent = -1;
  leftchild[0] = false;
  CUtlRBTree<CUtlSymbolTableLargeBaseTreeEntry_t *,int,CTreeEntryLess<CNonThreadsafeTree<1>,1>,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int>,int>>::FindInsertionPosition(
    this,
    insert: &entry,
    &parent,
    leftchild);
  v3 = CUtlRBTree<CUtlSymbolTableLargeBaseTreeEntry_t *,int,CTreeEntryLess<CNonThreadsafeTree<1>,1>,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int>,int>>::NewNode(this);
  CUtlRBTree<CUtlSymbolTableLargeBaseTreeEntry_t *,int,CTreeEntryLess<CNonThreadsafeTree<1>,1>,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int>,int>>::LinkToParent(
    this,
    i: v3,
    parent,
    isLeft: leftchild[0]);
  m_pMemory = this->m_Elements.m_pMemory;
  ++this->m_NumElements;
  p_m_Data = &m_pMemory[v3].m_Data;
  if ( p_m_Data != nullptr )
    *p_m_Data = entry;
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x10010250
// Name: public: class CUtlSymbolLarge CUtlSymbolTableLargeBase<class CNonThreadsafeTree<1>,1>::AddString(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CUtlSymbolLarge *__thiscall CUtlSymbolTableLargeBase<CNonThreadsafeTree<1>,1>::AddString(
        CUtlSymbolTableLargeBase<CNonThreadsafeTree<1>,1> *this,
        CUtlSymbolLarge *result,
        const char *pString)
{
  void *m_String; // ecx
  int v6; // eax
  signed int v7; // edi
  CUtlSymbolTableLargeBase<CNonThreadsafeTree<1>,1>::StringPool_t *v8; // eax
  CUtlVector<CUtlSymbolTableLargeBase<CNonThreadsafeTree<1>,1>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CNonThreadsafeTree<1>,1>::StringPool_t *,int> > *p_m_StringPools; // esi
  unsigned int v10; // esi
  CUtlSymbolTableLargeBase<CNonThreadsafeTree<1>,1>::StringPool_t *v11; // edx
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CUtlSymbolTableLargeBase<CNonThreadsafeTree<1>,1>::StringPool_t **m_pMemory; // ecx
  int v15; // eax
  CUtlSymbolTableLargeBase<CNonThreadsafeTree<1>,1>::StringPool_t **v16; // eax
  unsigned int v17; // eax
  CUtlSymbolTableLargeBase<CNonThreadsafeTree<1>,1>::StringPool_t *v18; // ecx
  int m_SpaceUsed; // edx
  CUtlSymbolTableLargeBaseTreeEntry_t *v20; // esi
  int lenString; // [esp+8h] [ebp-Ch]
  int lenDecorated; // [esp+Ch] [ebp-8h]
  CUtlSymbolTableLargeBase<CNonThreadsafeTree<1>,1>::StringPool_t *pPool; // [esp+10h] [ebp-4h] BYREF

  if ( pString != nullptr )
  {
    CUtlSymbolTableLargeBase<CNonThreadsafeTree<1>,1>::Find(this, result: (CUtlSymbolLarge *)&pPool, pString);
    m_String = pPool;
    if ( pPool == (CUtlSymbolTableLargeBase<CNonThreadsafeTree<1>,1>::StringPool_t *)-1 )
    {
      v6 = _V_strlen(str: pString);
      lenString = v6 + 1;
      v7 = (v6 + 8) & 0xFFFFFFFC;
      v8 = nullptr;
      lenDecorated = v7;
      if ( this->m_StringPools.m_Size <= 0 )
        goto LABEL_10;
      p_m_StringPools = &this->m_StringPools;
      pPool = (CUtlSymbolTableLargeBase<CNonThreadsafeTree<1>,1>::StringPool_t *)this->m_StringPools.m_Memory.m_pMemory;
      while ( *(_DWORD *)pPool->m_TotalLen - *(_DWORD *)(pPool->m_TotalLen + 4) < v7 )
      {
        pPool = (CUtlSymbolTableLargeBase<CNonThreadsafeTree<1>,1>::StringPool_t *)((char *)pPool + 4);
        v8 = (CUtlSymbolTableLargeBase<CNonThreadsafeTree<1>,1>::StringPool_t *)((char *)v8 + 1);
        if ( (int)v8 >= this->m_StringPools.m_Size )
          goto LABEL_10;
      }
      pPool = v8;
      if ( v8 == (CUtlSymbolTableLargeBase<CNonThreadsafeTree<1>,1>::StringPool_t *)-1 )
      {
LABEL_10:
        v10 = v7 + 12;
        if ( (unsigned int)(v7 + 12) <= 0x800 )
          v10 = 2048;
        v11 = (CUtlSymbolTableLargeBase<CNonThreadsafeTree<1>,1>::StringPool_t *)operator new(nSize: v10);
        v11->m_TotalLen = v10 - 12;
        p_m_StringPools = &this->m_StringPools;
        v11->m_SpaceUsed = 0;
        m_Size = this->m_StringPools.m_Size;
        m_nAllocationCount = this->m_StringPools.m_Memory.m_nAllocationCount;
        pPool = v11;
        if ( m_Size + 1 > m_nAllocationCount )
        {
          CUtlMemory<int,int>::Grow(
            this: (CUtlMemory<CTCPPacket *,int> *)&this->m_StringPools,
            num: m_Size - m_nAllocationCount + 1);
          v11 = pPool;
        }
        ++this->m_StringPools.m_Size;
        m_pMemory = p_m_StringPools->m_Memory.m_pMemory;
        v15 = this->m_StringPools.m_Size - m_Size - 1;
        this->m_StringPools.m_pElements = this->m_StringPools.m_Memory.m_pMemory;
        if ( v15 > 0 )
        {
          _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v15);
          v11 = pPool;
        }
        v16 = &p_m_StringPools->m_Memory.m_pMemory[m_Size];
        if ( v16 != nullptr )
          *v16 = v11;
        pPool = (CUtlSymbolTableLargeBase<CNonThreadsafeTree<1>,1>::StringPool_t *)m_Size;
        v7 = lenDecorated;
      }
      v17 = HashStringCaseless(pszKey: pString);
      v18 = p_m_StringPools->m_Memory.m_pMemory[(_DWORD)pPool];
      m_SpaceUsed = v18->m_SpaceUsed;
      v20 = (CUtlSymbolTableLargeBaseTreeEntry_t *)&v18->m_Data[m_SpaceUsed];
      v18->m_SpaceUsed = v7 + m_SpaceUsed;
      v20->m_Hash = v17;
      _V_memcpy(dest: (char *)&v18[1] + m_SpaceUsed, src: pString, count: lenString);
      m_String = this->m_Lookup.m_Elements.m_pMemory[CNonThreadsafeTree<1>::Insert(this: &this->m_Lookup, entry: v20)].m_Data->m_String;
    }
    result->u.m_Id = (int)m_String;
    return result;
  }
  else
  {
    result->u.m_Id = -1;
    return result;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100103B0
// Name: bool PS3ShaderDebugInfoDispatch(class MessageBuffer __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
char __cdecl PS3ShaderDebugInfoDispatch(MessageBuffer *pBuf)
{
  MessageBuffer *v1; // ebx
  char *data; // edi
  char fullPath[260]; // [esp+Ch] [ebp-104h] BYREF

  v1 = pBuf;
  data = pBuf->data;
  ++g_nTotalPS3DebugFileCount;
  if ( CUtlSymbolTableLargeBase<CNonThreadsafeTree<1>,1>::Find(
         this: &g_PS3DebugInfoFileSet,
         result: (CUtlSymbolLarge *)&pBuf,
         pString: data + 12)->u.m_Id == -1 )
  {
    CUtlSymbolTableLargeBase<CNonThreadsafeTree<1>,1>::AddString(
      this: &g_PS3DebugInfoFileSet,
      result: (CUtlSymbolLarge *)&pBuf,
      pString: data + 12);
    if ( V_strnicmp(s1: data + 12, s2: "cgc-capture", n: 11) == 0 )
    {
      V_ComposeFileName(path: g_pShaderPath, filename: data + 12, dest: fullPath, destSize: 260);
      WritePS3DebugInfo(
        nFileSize: *((_DWORD *)data + 2),
        pFullPath: fullPath,
        pFileData: (unsigned __int8 *)&v1->data[*((_DWORD *)data + 1) + 12]);
      return 1;
    }
  }
  else
  {
    ++g_nDuplicatePS3DebugFileCount;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10010450
// Name: void ExpandPS3DebugInfo(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ExpandPS3DebugInfo()
{
  int v0; // ebx
  DWORD FileSize; // esi
  DWORD m_nFilenameLength; // eax
  int v3; // eax
  int v4; // edi
  int v5; // eax
  int m_nFileIndex; // eax
  HANDLE FileA; // eax
  int m_Size; // edi
  int v9; // esi
  int m_nFileSize; // ebx
  HANDLE v11; // esi
  unsigned int v12; // edi
  unsigned int v13; // esi
  char fileNameBuffer[260]; // [esp+Ch] [ebp-288h] BYREF
  char dirToCreate[260]; // [esp+110h] [ebp-184h] BYREF
  CUtlSymbolTableLargeBase<CNonThreadsafeTree<1>,1> createdPS3DebugInfoDirectories; // [esp+214h] [ebp-80h] BYREF
  CUtlSymbolLarge v17; // [esp+24Ch] [ebp-48h] BYREF
  CUtlSymbolLarge v18; // [esp+250h] [ebp-44h] BYREF
  CUtlSymbolLarge result; // [esp+254h] [ebp-40h] BYREF
  PS3DebugFileTOCEntry_t tocEntry; // [esp+258h] [ebp-3Ch] BYREF
  unsigned int nTocFileSize; // [esp+268h] [ebp-2Ch]
  unsigned int nBytesWritten; // [esp+26Ch] [ebp-28h] BYREF
  unsigned int nTocFileSizeHigh; // [esp+270h] [ebp-24h] BYREF
  unsigned int nCurrentTocEntryOffset; // [esp+274h] [ebp-20h]
  CUtlVector<unsigned char,CUtlMemory<unsigned char,int> > scratchSpace; // [esp+278h] [ebp-1Ch] BYREF
  unsigned int nBytesRead; // [esp+28Ch] [ebp-8h] BYREF
  int nCurrentDebugInfoFile; // [esp+290h] [ebp-4h]

  v0 = -1;
  if ( g_hPS3DebugTOCFile != (HANDLE)-1 )
  {
    _Msg(a1: "Unpacking giant shader debug info files into sub-directory tree.\n");
    _Msg(a1: "0");
    CloseHandle(hObject: g_hPS3DebugTOCFile);
    if ( g_hPS3DebugInfoCurrentPackFile != (HANDLE)-1 )
      CloseHandle(hObject: g_hPS3DebugInfoCurrentPackFile);
    g_hPS3DebugTOCFile = CreateFileA(
                           lpFileName: g_PS3DebugTOCFilename,
                           dwDesiredAccess: 0x80000000,
                           dwShareMode: 0,
                           lpSecurityAttributes: nullptr,
                           dwCreationDisposition: 3u,
                           dwFlagsAndAttributes: 0x80u,
                           hTemplateFile: nullptr);
    FileSize = GetFileSize(hFile: g_hPS3DebugTOCFile, lpFileSizeHigh: &nTocFileSizeHigh);
    nTocFileSize = FileSize;
    if ( nTocFileSizeHigh != 0 )
    {
      _Error(a1: "PS3 debug info TOC File is greater than 4 GB.  This is probably not a good thing.");
      return;
    }
    CUtlSymbolTableLargeBase<CNonThreadsafeTree<1>,1>::CUtlSymbolTableLargeBase<CNonThreadsafeTree<1>,1>(this: &createdPS3DebugInfoDirectories);
    memset(&scratchSpace, 0, sizeof(scratchSpace));
    g_hPS3DebugInfoCurrentPackFile = (HANDLE)-1;
    nCurrentTocEntryOffset = 0;
    nCurrentDebugInfoFile = -1;
    if ( FileSize != 0 )
    {
      do
      {
        nBytesRead = 0;
        ReadFile(
          hFile: g_hPS3DebugTOCFile,
          lpBuffer: &tocEntry,
          nNumberOfBytesToRead: 0x10u,
          lpNumberOfBytesRead: &nBytesRead,
          lpOverlapped: nullptr);
        m_nFilenameLength = tocEntry.m_nFilenameLength;
        if ( tocEntry.m_nFilenameLength >= 260 )
          m_nFilenameLength = 260;
        ReadFile(
          hFile: g_hPS3DebugTOCFile,
          lpBuffer: fileNameBuffer,
          nNumberOfBytesToRead: m_nFilenameLength,
          lpNumberOfBytesRead: &nBytesRead,
          lpOverlapped: nullptr);
        V_ExtractFilePath(path: fileNameBuffer, dest: dirToCreate, destSize: 260);
        V_StripTrailingSlash(ppath: dirToCreate);
        if ( CUtlSymbolTableLargeBase<CNonThreadsafeTree<1>,1>::Find(
               this: &createdPS3DebugInfoDirectories,
               &result,
               pString: dirToCreate)->u.m_Id == -1 )
        {
          strchr(string: fileNameBuffer, chr: 0x5Cu);
          v4 = v3;
          if ( v3 != 0 )
          {
            do
            {
              memcpy(
                dst: (unsigned __int8 *)dirToCreate,
                src: (unsigned __int8 *)fileNameBuffer,
                count: v4 - (_DWORD)fileNameBuffer);
              dirToCreate[v4 - (_DWORD)fileNameBuffer] = 0;
              if ( CUtlSymbolTableLargeBase<CNonThreadsafeTree<1>,1>::Find(
                     this: &createdPS3DebugInfoDirectories,
                     result: &v18,
                     pString: dirToCreate)->u.m_Id == -1 )
              {
                CreateDirectoryA(lpPathName: dirToCreate, lpSecurityAttributes: nullptr);
                CUtlSymbolTableLargeBase<CNonThreadsafeTree<1>,1>::AddString(
                  this: &createdPS3DebugInfoDirectories,
                  result: &v17,
                  pString: dirToCreate);
              }
              strchr(string: (char *)(v4 + 1), chr: 0x5Cu);
              v4 = v5;
            }
            while ( v5 != 0 );
          }
        }
        m_nFileIndex = tocEntry.m_nFileIndex;
        if ( v0 != tocEntry.m_nFileIndex )
        {
          if ( g_hPS3DebugInfoCurrentPackFile != (HANDLE)-1 )
          {
            CloseHandle(hObject: g_hPS3DebugInfoCurrentPackFile);
            DeleteFileA(lpFileName: g_PS3DebugInfoPackFilenames[v0]);
            m_nFileIndex = tocEntry.m_nFileIndex;
          }
          nCurrentDebugInfoFile = m_nFileIndex;
          FileA = CreateFileA(
                    lpFileName: g_PS3DebugInfoPackFilenames[m_nFileIndex],
                    dwDesiredAccess: 0x80000000,
                    dwShareMode: 0,
                    lpSecurityAttributes: nullptr,
                    dwCreationDisposition: 3u,
                    dwFlagsAndAttributes: 0x80u,
                    hTemplateFile: nullptr);
          v0 = nCurrentDebugInfoFile;
          g_hPS3DebugInfoCurrentPackFile = FileA;
        }
        if ( scratchSpace.m_Size < tocEntry.m_nFileSize )
        {
          m_Size = scratchSpace.m_Size;
          v9 = tocEntry.m_nFileSize - scratchSpace.m_Size;
          if ( tocEntry.m_nFileSize != scratchSpace.m_Size )
          {
            m_nFileSize = tocEntry.m_nFileSize;
            if ( tocEntry.m_nFileSize > scratchSpace.m_Memory.m_nAllocationCount )
              CUtlMemory<bool,int>::Grow(
                this: (CUtlMemory<char,int> *)&scratchSpace,
                num: tocEntry.m_nFileSize - scratchSpace.m_Memory.m_nAllocationCount);
            scratchSpace.m_Size += v9;
            scratchSpace.m_pElements = scratchSpace.m_Memory.m_pMemory;
            if ( scratchSpace.m_Size - m_Size - v9 > 0 && v9 > 0 )
              _V_memmove(
                dest: &scratchSpace.m_Memory.m_pMemory[m_nFileSize],
                src: &scratchSpace.m_Memory.m_pMemory[m_Size],
                count: scratchSpace.m_Size - m_Size - v9);
            v0 = nCurrentDebugInfoFile;
          }
        }
        ReadFile(
          hFile: g_hPS3DebugInfoCurrentPackFile,
          lpBuffer: scratchSpace.m_Memory.m_pMemory,
          nNumberOfBytesToRead: tocEntry.m_nFileSize,
          lpNumberOfBytesRead: &nBytesRead,
          lpOverlapped: nullptr);
        nBytesWritten = 0;
        v11 = CreateFileA(
                lpFileName: fileNameBuffer,
                dwDesiredAccess: 0x40000000u,
                dwShareMode: 0,
                lpSecurityAttributes: nullptr,
                dwCreationDisposition: 2u,
                dwFlagsAndAttributes: 0x80u,
                hTemplateFile: nullptr);
        if ( v11 == (HANDLE)-1 )
          _Error(
            a1: "Unable to create PS3 shader debug info file: %s.  Ensure you have enoug disk space.\n",
            fileNameBuffer);
        WriteFile(
          hFile: v11,
          lpBuffer: scratchSpace.m_Memory.m_pMemory,
          nNumberOfBytesToWrite: tocEntry.m_nFileSize,
          lpNumberOfBytesWritten: &nBytesWritten,
          lpOverlapped: nullptr);
        CloseHandle(hObject: v11);
        v12 = nTocFileSize;
        v13 = tocEntry.m_nFilenameLength + nCurrentTocEntryOffset + 16;
        DisplayFileUnpackProgress(nTotalSize: nTocFileSize, nCurrent: v13, nLast: nCurrentTocEntryOffset);
        nCurrentTocEntryOffset = v13;
      }
      while ( v13 < v12 );
      if ( g_hPS3DebugInfoCurrentPackFile != (HANDLE)-1 )
      {
        CloseHandle(hObject: g_hPS3DebugInfoCurrentPackFile);
        DeleteFileA(lpFileName: g_PS3DebugInfoPackFilenames[v0]);
      }
    }
    CloseHandle(hObject: g_hPS3DebugTOCFile);
    DeleteFileA(lpFileName: g_PS3DebugTOCFilename);
    CUtlVector<CWorkerAccumState<CThreadNullMutex>::SubProcess *,CUtlMemory<CWorkerAccumState<CThreadNullMutex>::SubProcess *,int>>::~CUtlVector<CWorkerAccumState<CThreadNullMutex>::SubProcess *,CUtlMemory<CWorkerAccumState<CThreadNullMutex>::SubProcess *,int>>(this: (CUtlVector<CFileResponse,CUtlMemory<CFileResponse,int> > *)&scratchSpace);
    CUtlSymbolTableLargeBase<CNonThreadsafeTree<1>,1>::RemoveAll(this: &createdPS3DebugInfoDirectories);
    CUtlVector<CWorkerAccumState<CThreadNullMutex>::SubProcess *,CUtlMemory<CWorkerAccumState<CThreadNullMutex>::SubProcess *,int>>::~CUtlVector<CWorkerAccumState<CThreadNullMutex>::SubProcess *,CUtlMemory<CWorkerAccumState<CThreadNullMutex>::SubProcess *,int>>(this: (CUtlVector<CFileResponse,CUtlMemory<CFileResponse,int> > *)&createdPS3DebugInfoDirectories.m_StringPools);
    CUtlRBTree<CUtlSymbolTableLargeBaseTreeEntry_t *,int,CTreeEntryLess<CNonThreadsafeTree<1>,1>,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int>,int>>::~CUtlRBTree<CUtlSymbolTableLargeBaseTreeEntry_t *,int,CTreeEntryLess<CNonThreadsafeTree<1>,1>,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int>,int>>(this: &createdPS3DebugInfoDirectories.m_Lookup);
  }
  _Msg(
    a1: "\nTotal shader debug files returned: %d, duplicates: %d\n",
    g_nTotalPS3DebugFileCount,
    g_nDuplicatePS3DebugFileCount);
}

//------------------------------------------------------------------------------
// Address: 0x1001A370
// Name: public: unsigned short CUtlRBTree<class CUtlSymbolTable::CStringPoolIndex,unsigned short,class CUtlSymbolTable::CLess,class CUtlMemory<struct UtlRBTreeNode_t<class CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::NewNode(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::NewNode(
        CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> > *this)
{
  int m_FirstFree; // ecx
  int m_nAllocationCount; // eax
  unsigned __int16 index; // cx
  unsigned __int16 v5; // cx
  unsigned __int16 v6; // di
  int v7; // eax
  unsigned __int16 v8; // cx
  unsigned __int16 v9; // cx
  UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short> *m_pMemory; // edx
  UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short> *v12; // edx

  m_FirstFree = this->m_FirstFree;
  if ( (_WORD)m_FirstFree == 0xFFFF )
  {
    m_nAllocationCount = this->m_Elements.m_nAllocationCount;
    if ( this->m_LastAlloc.index >= m_nAllocationCount )
    {
      m_nAllocationCount = this->m_Elements.m_nAllocationCount;
      v5 = (m_nAllocationCount > 0) - 1;
    }
    else
    {
      index = this->m_LastAlloc.index;
      if ( (unsigned __int16)(index + 1) >= m_nAllocationCount )
        v5 = -1;
      else
        v5 = index + 1;
    }
    v6 = v5;
    if ( v5 >= m_nAllocationCount )
    {
      CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>::Grow(
        this: &this->m_Elements,
        num: 1);
      v7 = this->m_Elements.m_nAllocationCount;
      if ( this->m_LastAlloc.index >= v7 )
      {
        v7 = this->m_Elements.m_nAllocationCount;
        v9 = (v7 > 0) - 1;
      }
      else
      {
        v8 = this->m_LastAlloc.index;
        if ( (unsigned __int16)(v8 + 1) >= v7 )
          v9 = -1;
        else
          v9 = v8 + 1;
      }
      v6 = v9;
      if ( v9 >= v7 )
        _Error(a1: "CUtlRBTree overflow!\n");
    }
    m_pMemory = this->m_Elements.m_pMemory;
    this->m_LastAlloc.index = v6;
    this->m_pElements = m_pMemory;
    return v6;
  }
  else
  {
    v12 = this->m_Elements.m_pMemory;
    this->m_FirstFree = v12[m_FirstFree].m_Right;
    this->m_pElements = v12;
    return m_FirstFree;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001A500
// Name: public: unsigned short CUtlRBTree<class CUtlSymbolTable::CStringPoolIndex,unsigned short,class CUtlSymbolTable::CLess,class CUtlMemory<struct UtlRBTreeNode_t<class CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Parent(unsigned short)const
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Parent(
        CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> > *this,
        unsigned __int16 i)
{
  if ( (`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
    dword_1016F680 = 0x1FFFF;
  }
  if ( i == 0xFFFF )
    return dword_1016F680;
  else
    return this->m_Elements.m_pMemory[i].m_Parent;
}

//------------------------------------------------------------------------------
// Address: 0x1001A680
// Name: public: unsigned short CUtlRBTree<class CUtlSymbolTable::CStringPoolIndex,unsigned short,class CUtlSymbolTable::CLess,class CUtlMemory<struct UtlRBTreeNode_t<class CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::LeftChild(unsigned short)const
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::LeftChild(
        CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> > *this,
        unsigned __int16 i)
{
  if ( (`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
    dword_1016F680 = 0x1FFFF;
  }
  if ( i == 0xFFFF )
    return `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
  else
    return this->m_Elements.m_pMemory[i].m_Left;
}

//------------------------------------------------------------------------------
// Address: 0x1001A6E0
// Name: public: unsigned short CUtlRBTree<class CUtlSymbolTable::CStringPoolIndex,unsigned short,class CUtlSymbolTable::CLess,class CUtlMemory<struct UtlRBTreeNode_t<class CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::RightChild(unsigned short)const
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::RightChild(
        CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> > *this,
        unsigned __int16 i)
{
  if ( (`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
    dword_1016F680 = 0x1FFFF;
  }
  if ( i == 0xFFFF )
    return HIWORD(`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel);
  else
    return this->m_Elements.m_pMemory[i].m_Right;
}

//------------------------------------------------------------------------------
// Address: 0x1001A750
// Name: protected: void CUtlRBTree<class CUtlSymbolTable::CStringPoolIndex,unsigned short,class CUtlSymbolTable::CLess,class CUtlMemory<struct UtlRBTreeNode_t<class CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::FindInsertionPosition(class CUtlSymbolTable::CStringPoolIndex const __near &,unsigned short __near &,bool __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::FindInsertionPosition(
        CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> > *this,
        const CUtlSymbolTable::CStringPoolIndex *insert,
        unsigned __int16 *parent,
        bool *leftchild)
{
  unsigned __int16 m_Root; // di
  int v6; // esi

  m_Root = this->m_Root;
  *parent = -1;
  *leftchild = false;
  while ( m_Root != 0xFFFF )
  {
    *parent = m_Root;
    v6 = m_Root;
    if ( CUtlSymbolTable::CLess::operator()(
           this: &this->m_LessFunc,
           i1: insert,
           i2: &this->m_Elements.m_pMemory[v6].m_Data) )
    {
      *leftchild = true;
      if ( (`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_1016F680 = 0x1FFFF;
      }
      m_Root = this->m_Elements.m_pMemory[m_Root].m_Left;
    }
    else
    {
      *leftchild = false;
      if ( (`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_1016F680 = 0x1FFFF;
      }
      m_Root = this->m_Elements.m_pMemory[v6].m_Right;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001A840
// Name: protected: void CUtlRBTree<class CUtlSymbolTable::CStringPoolIndex,unsigned short,class CUtlSymbolTable::CLess,class CUtlMemory<struct UtlRBTreeNode_t<class CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::RotateLeft(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::RotateLeft(
        CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> > *this,
        unsigned __int16 elem)
{
  unsigned __int16 v4; // ax
  int v5; // edi
  unsigned __int16 v6; // ax
  int elema; // [esp+14h] [ebp+8h]

  v4 = CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::RightChild(
         this,
         i: elem);
  v5 = v4;
  this->m_Elements.m_pMemory[elem].m_Right = CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::LeftChild(
                                               this,
                                               i: v4);
  elema = elem;
  if ( CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::LeftChild(
         this,
         i: v5) != 0xFFFF )
    this->m_Elements.m_pMemory[CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::LeftChild(
                                 this,
                                 i: v5)].m_Parent = elem;
  if ( (_WORD)v5 != 0xFFFF )
    this->m_Elements.m_pMemory[v5].m_Parent = CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Parent(
                                                this,
                                                i: elem);
  if ( elem == this->m_Root )
  {
    this->m_Root = v5;
  }
  else
  {
    v6 = CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Parent(
           this,
           i: elem);
    if ( CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::LeftChild(
           this,
           i: v6) == elem )
      this->m_Elements.m_pMemory[CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Parent(
                                   this,
                                   i: elem)].m_Left = v5;
    else
      this->m_Elements.m_pMemory[CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Parent(
                                   this,
                                   i: elem)].m_Right = v5;
  }
  this->m_Elements.m_pMemory[v5].m_Left = elem;
  if ( elem != 0xFFFF )
    this->m_Elements.m_pMemory[elema].m_Parent = v5;
}

//------------------------------------------------------------------------------
// Address: 0x1001A940
// Name: protected: void CUtlRBTree<class CUtlSymbolTable::CStringPoolIndex,unsigned short,class CUtlSymbolTable::CLess,class CUtlMemory<struct UtlRBTreeNode_t<class CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::RotateRight(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::RotateRight(
        CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> > *this,
        unsigned __int16 elem)
{
  unsigned __int16 v4; // ax
  int v5; // edi
  unsigned __int16 v6; // ax
  int elema; // [esp+14h] [ebp+8h]

  v4 = CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::LeftChild(
         this,
         i: elem);
  v5 = v4;
  this->m_Elements.m_pMemory[elem].m_Left = CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::RightChild(
                                              this,
                                              i: v4);
  elema = elem;
  if ( CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::RightChild(
         this,
         i: v5) != 0xFFFF )
    this->m_Elements.m_pMemory[CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::RightChild(
                                 this,
                                 i: v5)].m_Parent = elem;
  if ( (_WORD)v5 != 0xFFFF )
    this->m_Elements.m_pMemory[v5].m_Parent = CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Parent(
                                                this,
                                                i: elem);
  if ( elem == this->m_Root )
  {
    this->m_Root = v5;
  }
  else
  {
    v6 = CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Parent(
           this,
           i: elem);
    if ( CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::RightChild(
           this,
           i: v6) == elem )
      this->m_Elements.m_pMemory[CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Parent(
                                   this,
                                   i: elem)].m_Right = v5;
    else
      this->m_Elements.m_pMemory[CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Parent(
                                   this,
                                   i: elem)].m_Left = v5;
  }
  this->m_Elements.m_pMemory[v5].m_Right = elem;
  if ( elem != 0xFFFF )
    this->m_Elements.m_pMemory[elema].m_Parent = v5;
}

//------------------------------------------------------------------------------
// Address: 0x1001AA80
// Name: public: unsigned short CUtlRBTree<class CUtlSymbolTable::CStringPoolIndex,unsigned short,class CUtlSymbolTable::CLess,class CUtlMemory<struct UtlRBTreeNode_t<class CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Find(class CUtlSymbolTable::CStringPoolIndex const __near &)const
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Find(
        CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> > *this,
        const CUtlSymbolTable::CStringPoolIndex *search)
{
  unsigned __int16 m_Root; // bx
  int v4; // esi

  m_Root = this->m_Root;
  if ( m_Root == 0xFFFF )
    return -1;
  do
  {
    v4 = m_Root;
    if ( CUtlSymbolTable::CLess::operator()(
           this: &this->m_LessFunc,
           i1: search,
           i2: &this->m_Elements.m_pMemory[v4].m_Data) )
    {
      if ( (`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_1016F680 = 0x1FFFF;
      }
      m_Root = this->m_Elements.m_pMemory[m_Root].m_Left;
    }
    else
    {
      if ( !CUtlSymbolTable::CLess::operator()(
              this: &this->m_LessFunc,
              i1: &this->m_Elements.m_pMemory[v4].m_Data,
              i2: search) )
        return m_Root;
      if ( (`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_1016F680 = 0x1FFFF;
      }
      m_Root = this->m_Elements.m_pMemory[v4].m_Right;
    }
  }
  while ( m_Root != 0xFFFF );
  return m_Root;
}

//------------------------------------------------------------------------------
// Address: 0x1001AB80
// Name: public: void CUtlRBTree<class CUtlSymbolTable::CStringPoolIndex,unsigned short,class CUtlSymbolTable::CLess,class CUtlMemory<struct UtlRBTreeNode_t<class CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::RemoveAll(
        CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> > *this)
{
  unsigned __int16 index; // cx
  unsigned __int16 v3; // di
  int v4; // eax
  unsigned __int16 it; // [esp+4h] [ebp-4h]

  index = this->m_LastAlloc.index;
  if ( index != 0xFFFF )
  {
    v3 = (this->m_Elements.m_nAllocationCount > 0) - 1;
    it = v3;
    if ( this->m_Elements.m_nAllocationCount > 0 )
    {
      do
      {
        if ( v3 < this->m_Elements.m_nAllocationCount
          && v3 <= index
          && CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::LeftChild(
               this,
               i: it) != v3 )
        {
          v4 = v3;
          this->m_Elements.m_pMemory[v4].m_Right = this->m_FirstFree;
          this->m_Elements.m_pMemory[v4].m_Left = v3;
          this->m_FirstFree = v3;
        }
        index = this->m_LastAlloc.index;
        if ( v3 == index )
          break;
        ++v3;
        if ( (unsigned __int16)(it + 1) >= this->m_Elements.m_nAllocationCount )
          v3 = -1;
        it = v3;
      }
      while ( v3 != 0xFFFF );
    }
    *(_DWORD *)&this->m_Root = 0xFFFF;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001AC40
// Name: protected: void CUtlRBTree<class CUtlSymbolTable::CStringPoolIndex,unsigned short,class CUtlSymbolTable::CLess,class CUtlMemory<struct UtlRBTreeNode_t<class CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::InsertRebalance(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::InsertRebalance(
        CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> > *this,
        unsigned __int16 elem)
{
  unsigned __int16 v2; // bx
  int v4; // eax
  int *v5; // ecx
  int v6; // ecx
  int *v7; // ecx
  int *v8; // ecx
  unsigned __int16 v9; // di
  int *v10; // ecx
  int v11; // ecx
  int *v12; // edx
  int v13; // edx
  int *v14; // edx
  int *v15; // edx
  unsigned __int16 v16; // dx
  int *v17; // ebx
  int v18; // eax
  int *v19; // edx
  int v20; // edx
  int *v21; // eax
  int *v22; // edx
  int v23; // edx
  int *v24; // ebx
  int *v25; // edx
  int v26; // edx
  int *v27; // eax

  v2 = elem;
  while ( v2 != this->m_Root )
  {
    v4 = `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard';
    if ( (`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
        & 1) == 0 )
    {
      v4 = `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
         | 1;
      `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
      `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
      dword_1016F680 = 0x1FFFF;
    }
    if ( v2 == 0xFFFF )
      v5 = &`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
    else
      v5 = (int *)&this->m_Elements.m_pMemory[v2];
    v6 = *((unsigned __int16 *)v5 + 2);
    if ( (v4 & 1) == 0 )
    {
      `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
      dword_1016F680 = 0x1FFFF;
      v4 |= 1u;
      `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
    }
    if ( (_WORD)v6 == 0xFFFF )
      v7 = &`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
    else
      v7 = (int *)&this->m_Elements.m_pMemory[v6];
    if ( *((_WORD *)v7 + 3) != 0 )
      break;
    if ( (v4 & 1) == 0 )
    {
      v4 |= 1u;
      `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
      `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
      dword_1016F680 = 0x1FFFF;
    }
    if ( v2 == 0xFFFF )
      v8 = &`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
    else
      v8 = (int *)&this->m_Elements.m_pMemory[v2];
    v9 = *((_WORD *)v8 + 2);
    if ( (v4 & 1) == 0 )
    {
      v4 |= 1u;
      `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
      `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
      dword_1016F680 = 0x1FFFF;
    }
    if ( v9 == 0xFFFF )
      v10 = &`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
    else
      v10 = (int *)&this->m_Elements.m_pMemory[v9];
    v11 = *((unsigned __int16 *)v10 + 2);
    if ( (v4 & 1) == 0 )
    {
      `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
      dword_1016F680 = 0x1FFFF;
      v4 |= 1u;
      `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
    }
    if ( v9 == 0xFFFF )
      v12 = &`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
    else
      v12 = (int *)&this->m_Elements.m_pMemory[v9];
    v13 = *((unsigned __int16 *)v12 + 2);
    if ( (v4 & 1) == 0 )
    {
      `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
      dword_1016F680 = 0x1FFFF;
      v4 |= 1u;
      `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
    }
    if ( (_WORD)v13 == 0xFFFF )
      v14 = &`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
    else
      v14 = (int *)&this->m_Elements.m_pMemory[v13];
    if ( *(_WORD *)v14 == v9 )
    {
      if ( (v4 & 1) == 0 )
      {
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_1016F680 = 0x1FFFF;
        v4 |= 1u;
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
      }
      if ( (_WORD)v11 == 0xFFFF )
        v15 = &`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        v15 = (int *)&this->m_Elements.m_pMemory[v11];
      v16 = *((_WORD *)v15 + 1);
      if ( (v4 & 1) == 0 )
      {
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_1016F680 = 0x1FFFF;
        v4 |= 1u;
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
      }
      if ( v16 == 0xFFFF )
        v17 = &`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        v17 = (int *)&this->m_Elements.m_pMemory[v16];
      if ( *((_WORD *)v17 + 3) != 0 )
      {
        if ( (v4 & 1) == 0 )
        {
          `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
          dword_1016F680 = 0x1FFFF;
          v4 |= 1u;
          `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
        }
        v2 = elem;
        if ( elem == 0xFFFF )
        {
          v19 = &`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        }
        else
        {
          v19 = (int *)&this->m_Elements.m_pMemory[elem];
          v2 = elem;
        }
        v20 = *((unsigned __int16 *)v19 + 2);
        if ( (v4 & 1) == 0 )
        {
          `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4 | 1;
          `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
          dword_1016F680 = 0x1FFFF;
        }
        if ( (_WORD)v20 == 0xFFFF )
          v21 = &`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        else
          v21 = (int *)&this->m_Elements.m_pMemory[v20];
        if ( *((_WORD *)v21 + 1) == v2 )
        {
          v2 = v9;
          elem = v9;
          CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::RotateLeft(
            this,
            elem: v9);
          v9 = CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Parent(
                 this,
                 i: v9);
          LOWORD(v11) = CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Parent(
                          this,
                          i: v9);
        }
        this->m_Elements.m_pMemory[v9].m_Tag = 1;
        this->m_Elements.m_pMemory[(unsigned __int16)v11].m_Tag = 0;
        CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::RotateRight(
          this,
          elem: v11);
        continue;
      }
      this->m_Elements.m_pMemory[v9].m_Tag = 1;
      v18 = v16;
    }
    else
    {
      if ( (v4 & 1) == 0 )
      {
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_1016F680 = 0x1FFFF;
        v4 |= 1u;
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
      }
      if ( (_WORD)v11 == 0xFFFF )
        v22 = &`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        v22 = (int *)&this->m_Elements.m_pMemory[v11];
      v23 = *(unsigned __int16 *)v22;
      if ( (v4 & 1) == 0 )
      {
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_1016F680 = 0x1FFFF;
        v4 |= 1u;
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
      }
      if ( (_WORD)v23 == 0xFFFF )
        v24 = &`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        v24 = (int *)&this->m_Elements.m_pMemory[v23];
      if ( *((_WORD *)v24 + 3) != 0 )
      {
        if ( (v4 & 1) == 0 )
        {
          `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
          dword_1016F680 = 0x1FFFF;
          v4 |= 1u;
          `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
        }
        v2 = elem;
        if ( elem == 0xFFFF )
        {
          v25 = &`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        }
        else
        {
          v25 = (int *)&this->m_Elements.m_pMemory[elem];
          v2 = elem;
        }
        v26 = *((unsigned __int16 *)v25 + 2);
        if ( (v4 & 1) == 0 )
        {
          `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4 | 1;
          `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
          dword_1016F680 = 0x1FFFF;
        }
        if ( (_WORD)v26 == 0xFFFF )
          v27 = &`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        else
          v27 = (int *)&this->m_Elements.m_pMemory[v26];
        if ( *(_WORD *)v27 == v2 )
        {
          v2 = v9;
          elem = v9;
          CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::RotateRight(
            this,
            elem: v9);
          v9 = CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Parent(
                 this,
                 i: v9);
          LOWORD(v11) = CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Parent(
                          this,
                          i: v9);
        }
        this->m_Elements.m_pMemory[v9].m_Tag = 1;
        this->m_Elements.m_pMemory[(unsigned __int16)v11].m_Tag = 0;
        CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::RotateLeft(
          this,
          elem: v11);
        continue;
      }
      this->m_Elements.m_pMemory[v9].m_Tag = 1;
      v18 = v23;
    }
    this->m_Elements.m_pMemory[v18].m_Tag = 1;
    v2 = v11;
    this->m_Elements.m_pMemory[v11].m_Tag = 0;
    elem = v11;
  }
  this->m_Elements.m_pMemory[this->m_Root].m_Tag = 1;
}

//------------------------------------------------------------------------------
// Address: 0x1001B250
// Name: protected: void CUtlRBTree<class CUtlSymbolTable::CStringPoolIndex,unsigned short,class CUtlSymbolTable::CLess,class CUtlMemory<struct UtlRBTreeNode_t<class CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::LinkToParent(unsigned short,unsigned short,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::LinkToParent(
        CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> > *this,
        unsigned __int16 i,
        unsigned __int16 parent,
        bool isLeft)
{
  UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short> *v4; // eax
  UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short> *m_pMemory; // eax

  v4 = &this->m_Elements.m_pMemory[i];
  v4->m_Right = -1;
  v4->m_Left = -1;
  v4->m_Parent = parent;
  v4->m_Tag = 0;
  if ( parent == 0xFFFF )
  {
    this->m_Root = i;
    CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::InsertRebalance(
      this,
      elem: i);
  }
  else
  {
    m_pMemory = this->m_Elements.m_pMemory;
    if ( isLeft )
      m_pMemory[parent].m_Left = i;
    else
      m_pMemory[parent].m_Right = i;
    CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::InsertRebalance(
      this,
      elem: i);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001B350
// Name: public: CUtlRBTree<class CUtlSymbolTable::CStringPoolIndex,unsigned short,class CUtlSymbolTable::CLess,class CUtlMemory<struct UtlRBTreeNode_t<class CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::~CUtlRBTree<class CUtlSymbolTable::CStringPoolIndex,unsigned short,class CUtlSymbolTable::CLess,class CUtlMemory<struct UtlRBTreeNode_t<class CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::~CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>(
        CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> > *this)
{
  CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::RemoveAll(this);
  this->m_FirstFree = -1;
  if ( this->m_Elements.m_nGrowSize >= 0 )
  {
    if ( this->m_Elements.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Elements.m_pMemory);
      this->m_Elements.m_pMemory = nullptr;
    }
    this->m_Elements.m_nAllocationCount = 0;
  }
  this->m_LastAlloc.index = -1;
  if ( this->m_Elements.m_nGrowSize >= 0 )
  {
    if ( this->m_Elements.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Elements.m_pMemory);
      this->m_Elements.m_pMemory = nullptr;
    }
    this->m_Elements.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001B3E0
// Name: public: unsigned short CUtlRBTree<class CUtlSymbolTable::CStringPoolIndex,unsigned short,class CUtlSymbolTable::CLess,class CUtlMemory<struct UtlRBTreeNode_t<class CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Insert(class CUtlSymbolTable::CStringPoolIndex const __near &)
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Insert(
        CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> > *this,
        const CUtlSymbolTable::CStringPoolIndex *insert)
{
  unsigned __int16 v3; // ax
  int v4; // edi
  UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short> *m_pMemory; // edx
  int parent; // [esp+Ch] [ebp-8h] BYREF
  BOOL leftchild; // [esp+10h] [ebp-4h] BYREF

  parent = 0xFFFF;
  LOBYTE(leftchild) = 0;
  CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::FindInsertionPosition(
    this,
    insert,
    (unsigned __int16 *)&parent,
    (bool *)&leftchild);
  v3 = CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::NewNode(this);
  v4 = v3;
  CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::LinkToParent(
    this,
    i: v3,
    parent,
    isLeft: leftchild);
  m_pMemory = this->m_Elements.m_pMemory;
  ++this->m_NumElements;
  if ( &m_pMemory[v4] != (UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short> *)-8 )
    m_pMemory[v4].m_Data = *insert;
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x1001CAE0
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
// Address: 0x1001CFD0
// Name: public: void CUtlMemory<struct UtlLinkedListElem_t<class CUtlVector<char,class CUtlMemory<char,int>> __near *,unsigned short>,unsigned short>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<UtlLinkedListElem_t<CUtlVector<char,CUtlMemory<char,int>> *,unsigned short>,unsigned short>::Grow(
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
// Address: 0x1001DC90
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
    CUtlMemory<bool,int>::Grow(this: &this->m_Memory, num: num + m_Size - m_nAllocationCount);
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
// Address: 0x1001DDB0
// Name: public: int CUtlVector<char __near *,class CUtlMemory<char __near *,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<char *,CUtlMemory<char *,int>>::InsertMultipleBefore(
        CUtlVector<int,CUtlMemory<int,int> > *this,
        int elem,
        int num)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  int *m_pMemory; // ecx
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
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 4 * v9);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x1001EBC0
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
      CUtlMemory<bool,int>::Grow(this: &this->m_Memory, num: size - m_nAllocationCount);
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
// Address: 0x100231A0
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
// Address: 0x10024390
// Name: public: unsigned short CUtlRBTree<struct CUtlMap<class CUtlLinkedList<unsigned __int64,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<unsigned __int64,int>,int>> __near *,int,unsigned short>::Node_t,unsigned short,class CUtlMap<class CUtlLinkedList<unsigned __int64,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<unsigned __int64,int>,int>> __near *,int,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<class CUtlLinkedList<unsigned __int64,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<unsigned __int64,int>,int>> __near *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Parent(unsigned short)const
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CUtlRBTree<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Parent(
        CUtlRBTree<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int> > *,int,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int> > *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int> > *,int,unsigned short>::Node_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 i)
{
  if ( (`CUtlRBTree<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
    dword_10171FDC = 0x1FFFF;
  }
  if ( i == 0xFFFF )
    return dword_10171FDC;
  else
    return this->m_Elements.m_pMemory[i].m_Parent;
}

//------------------------------------------------------------------------------
// Address: 0x100243F0
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
// Address: 0x100244A0
// Name: public: unsigned short CUtlRBTree<struct CUtlMap<class CUtlLinkedList<unsigned __int64,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<unsigned __int64,int>,int>> __near *,int,unsigned short>::Node_t,unsigned short,class CUtlMap<class CUtlLinkedList<unsigned __int64,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<unsigned __int64,int>,int>> __near *,int,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<class CUtlLinkedList<unsigned __int64,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<unsigned __int64,int>,int>> __near *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::LeftChild(unsigned short)const
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CUtlRBTree<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::LeftChild(
        CUtlRBTree<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int> > *,int,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int> > *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int> > *,int,unsigned short>::Node_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 i)
{
  if ( (`CUtlRBTree<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
    dword_10171FDC = 0x1FFFF;
  }
  if ( i == 0xFFFF )
    return `CUtlRBTree<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
  else
    return this->m_Elements.m_pMemory[i].m_Left;
}

//------------------------------------------------------------------------------
// Address: 0x10024760
// Name: public: unsigned short CUtlRBTree<struct CUtlMap<class CUtlLinkedList<unsigned __int64,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<unsigned __int64,int>,int>> __near *,int,unsigned short>::Node_t,unsigned short,class CUtlMap<class CUtlLinkedList<unsigned __int64,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<unsigned __int64,int>,int>> __near *,int,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<class CUtlLinkedList<unsigned __int64,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<unsigned __int64,int>,int>> __near *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::RightChild(unsigned short)const
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CUtlRBTree<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::RightChild(
        CUtlRBTree<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int> > *,int,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int> > *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int> > *,int,unsigned short>::Node_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 i)
{
  if ( (`CUtlRBTree<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
    dword_10171FDC = 0x1FFFF;
  }
  if ( i == 0xFFFF )
    return HIWORD(`CUtlRBTree<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel);
  else
    return this->m_Elements.m_pMemory[i].m_Right;
}

//------------------------------------------------------------------------------
// Address: 0x100247C0
// Name: public: unsigned short CUtlRBTree<struct CUtlMap<class CUtlLinkedList<unsigned __int64,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<unsigned __int64,int>,int>> __near *,int,unsigned short>::Node_t,unsigned short,class CUtlMap<class CUtlLinkedList<unsigned __int64,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<unsigned __int64,int>,int>> __near *,int,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<class CUtlLinkedList<unsigned __int64,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<unsigned __int64,int>,int>> __near *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::NewNode(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::NewNode(
        CUtlRBTree<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int> > *,int,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int> > *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int> > *,int,unsigned short>::Node_t,unsigned short>,unsigned short> > *this)
{
  int m_FirstFree; // ecx
  int m_nAllocationCount; // eax
  unsigned __int16 index; // cx
  unsigned __int16 v5; // cx
  unsigned __int16 v6; // di
  int v7; // eax
  unsigned __int16 v8; // cx
  unsigned __int16 v9; // cx
  UtlRBTreeNode_t<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int> > *,int,unsigned short>::Node_t,unsigned short> *m_pMemory; // edx
  UtlRBTreeNode_t<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int> > *,int,unsigned short>::Node_t,unsigned short> *v12; // edx

  m_FirstFree = this->m_FirstFree;
  if ( (_WORD)m_FirstFree == 0xFFFF )
  {
    m_nAllocationCount = this->m_Elements.m_nAllocationCount;
    if ( this->m_LastAlloc.index >= m_nAllocationCount )
    {
      m_nAllocationCount = this->m_Elements.m_nAllocationCount;
      v5 = (m_nAllocationCount > 0) - 1;
    }
    else
    {
      index = this->m_LastAlloc.index;
      if ( (unsigned __int16)(index + 1) >= m_nAllocationCount )
        v5 = -1;
      else
        v5 = index + 1;
    }
    v6 = v5;
    if ( v5 >= m_nAllocationCount )
    {
      CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short>,unsigned short>::Grow(
        this: &this->m_Elements,
        num: 1);
      v7 = this->m_Elements.m_nAllocationCount;
      if ( this->m_LastAlloc.index >= v7 )
      {
        v7 = this->m_Elements.m_nAllocationCount;
        v9 = (v7 > 0) - 1;
      }
      else
      {
        v8 = this->m_LastAlloc.index;
        if ( (unsigned __int16)(v8 + 1) >= v7 )
          v9 = -1;
        else
          v9 = v8 + 1;
      }
      v6 = v9;
      if ( v9 >= v7 )
        _Error(a1: "CUtlRBTree overflow!\n");
    }
    m_pMemory = this->m_Elements.m_pMemory;
    this->m_LastAlloc.index = v6;
    this->m_pElements = m_pMemory;
    return v6;
  }
  else
  {
    v12 = this->m_Elements.m_pMemory;
    this->m_FirstFree = v12[m_FirstFree].m_Right;
    this->m_pElements = v12;
    return m_FirstFree;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100248C0
// Name: protected: void CUtlRBTree<struct CUtlMap<class CUtlLinkedList<unsigned __int64,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<unsigned __int64,int>,int>> __near *,int,unsigned short>::Node_t,unsigned short,class CUtlMap<class CUtlLinkedList<unsigned __int64,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<unsigned __int64,int>,int>> __near *,int,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<class CUtlLinkedList<unsigned __int64,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<unsigned __int64,int>,int>> __near *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::RotateLeft(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::RotateLeft(
        CUtlRBTree<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int> > *,int,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int> > *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int> > *,int,unsigned short>::Node_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 elem)
{
  unsigned __int16 v4; // ax
  int v5; // edi
  unsigned __int16 v6; // ax
  int elema; // [esp+14h] [ebp+8h]

  v4 = CUtlRBTree<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::RightChild(
         this,
         i: elem);
  v5 = v4;
  this->m_Elements.m_pMemory[elem].m_Right = CUtlRBTree<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::LeftChild(
                                               this,
                                               i: v4);
  elema = elem;
  if ( CUtlRBTree<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::LeftChild(
         this,
         i: v5) != 0xFFFF )
    this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::LeftChild(
                                 this,
                                 i: v5)].m_Parent = elem;
  if ( (_WORD)v5 != 0xFFFF )
    this->m_Elements.m_pMemory[v5].m_Parent = CUtlRBTree<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Parent(
                                                this,
                                                i: elem);
  if ( elem == this->m_Root )
  {
    this->m_Root = v5;
  }
  else
  {
    v6 = CUtlRBTree<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Parent(
           this,
           i: elem);
    if ( CUtlRBTree<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::LeftChild(
           this,
           i: v6) == elem )
      this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Parent(
                                   this,
                                   i: elem)].m_Left = v5;
    else
      this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Parent(
                                   this,
                                   i: elem)].m_Right = v5;
  }
  this->m_Elements.m_pMemory[v5].m_Left = elem;
  if ( elem != 0xFFFF )
    this->m_Elements.m_pMemory[elema].m_Parent = v5;
}

//------------------------------------------------------------------------------
// Address: 0x100249B0
// Name: protected: void CUtlRBTree<struct CUtlMap<class CUtlLinkedList<unsigned __int64,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<unsigned __int64,int>,int>> __near *,int,unsigned short>::Node_t,unsigned short,class CUtlMap<class CUtlLinkedList<unsigned __int64,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<unsigned __int64,int>,int>> __near *,int,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<class CUtlLinkedList<unsigned __int64,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<unsigned __int64,int>,int>> __near *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::RotateRight(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::RotateRight(
        CUtlRBTree<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int> > *,int,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int> > *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int> > *,int,unsigned short>::Node_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 elem)
{
  unsigned __int16 v4; // ax
  int v5; // edi
  unsigned __int16 v6; // ax
  int elema; // [esp+14h] [ebp+8h]

  v4 = CUtlRBTree<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::LeftChild(
         this,
         i: elem);
  v5 = v4;
  this->m_Elements.m_pMemory[elem].m_Left = CUtlRBTree<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::RightChild(
                                              this,
                                              i: v4);
  elema = elem;
  if ( CUtlRBTree<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::RightChild(
         this,
         i: v5) != 0xFFFF )
    this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::RightChild(
                                 this,
                                 i: v5)].m_Parent = elem;
  if ( (_WORD)v5 != 0xFFFF )
    this->m_Elements.m_pMemory[v5].m_Parent = CUtlRBTree<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Parent(
                                                this,
                                                i: elem);
  if ( elem == this->m_Root )
  {
    this->m_Root = v5;
  }
  else
  {
    v6 = CUtlRBTree<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Parent(
           this,
           i: elem);
    if ( CUtlRBTree<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::RightChild(
           this,
           i: v6) == elem )
      this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Parent(
                                   this,
                                   i: elem)].m_Right = v5;
    else
      this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Parent(
                                   this,
                                   i: elem)].m_Left = v5;
  }
  this->m_Elements.m_pMemory[v5].m_Right = elem;
  if ( elem != 0xFFFF )
    this->m_Elements.m_pMemory[elema].m_Parent = v5;
}

//------------------------------------------------------------------------------
// Address: 0x10024D40
// Name: public: unsigned short CUtlRBTree<struct CUtlMap<class CUtlLinkedList<unsigned __int64,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<unsigned __int64,int>,int>> __near *,int,unsigned short>::Node_t,unsigned short,class CUtlMap<class CUtlLinkedList<unsigned __int64,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<unsigned __int64,int>,int>> __near *,int,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<class CUtlLinkedList<unsigned __int64,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<unsigned __int64,int>,int>> __near *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::FirstInorder(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::FirstInorder(
        CUtlRBTree<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int> > *,int,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int> > *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int> > *,int,unsigned short>::Node_t,unsigned short>,unsigned short> > *this)
{
  int result; // eax
  int v2; // ebx
  int *v3; // edx

  result = this->m_Root;
  v2 = `CUtlRBTree<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard';
  while ( 1 )
  {
    if ( (v2 & 1) == 0 )
    {
      `CUtlRBTree<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
      dword_10171FDC = 0x1FFFF;
      v2 |= 1u;
      `CUtlRBTree<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v2;
    }
    v3 = (_WORD)result == 0xFFFF
       ? &`CUtlRBTree<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel
       : (int *)&this->m_Elements.m_pMemory[(unsigned __int16)result];
    if ( *(_WORD *)v3 == 0xFFFF )
      break;
    if ( (v2 & 1) == 0 )
    {
      `CUtlRBTree<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
      dword_10171FDC = 0x1FFFF;
      v2 |= 1u;
      `CUtlRBTree<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v2;
    }
    if ( (_WORD)result == 0xFFFF )
      result = (unsigned __int16)`CUtlRBTree<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
    else
      result = this->m_Elements.m_pMemory[(unsigned __int16)result].m_Left;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10024E10
// Name: protected: void CUtlRBTree<struct CUtlMap<class CUtlLinkedList<unsigned __int64,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<unsigned __int64,int>,int>> __near *,int,unsigned short>::Node_t,unsigned short,class CUtlMap<class CUtlLinkedList<unsigned __int64,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<unsigned __int64,int>,int>> __near *,int,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<class CUtlLinkedList<unsigned __int64,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<unsigned __int64,int>,int>> __near *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::FindInsertionPosition(struct CUtlMap<class CUtlLinkedList<unsigned __int64,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<unsigned __int64,int>,int>> __near *,int,unsigned short>::Node_t const __near &,unsigned short __near &,bool __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::FindInsertionPosition(
        CUtlRBTree<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int> > *,int,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int> > *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int> > *,int,unsigned short>::Node_t,unsigned short>,unsigned short> > *this,
        const CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int> > *,int,unsigned short>::Node_t *insert,
        unsigned __int16 *parent,
        bool *leftchild)
{
  unsigned __int16 m_Root; // di
  int v6; // esi

  m_Root = this->m_Root;
  *parent = -1;
  *leftchild = false;
  while ( m_Root != 0xFFFF )
  {
    *parent = m_Root;
    v6 = m_Root;
    if ( this->m_LessFunc.m_LessFunc(a1: insert, a2: &this->m_Elements.m_pMemory[v6].m_Data) != 0 )
    {
      *leftchild = true;
      if ( (`CUtlRBTree<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_10171FDC = 0x1FFFF;
      }
      m_Root = this->m_Elements.m_pMemory[m_Root].m_Left;
    }
    else
    {
      *leftchild = false;
      if ( (`CUtlRBTree<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_10171FDC = 0x1FFFF;
      }
      m_Root = this->m_Elements.m_pMemory[v6].m_Right;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10024F80
// Name: public: void CUtlRBTree<struct CUtlMap<class CUtlLinkedList<unsigned __int64,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<unsigned __int64,int>,int>> __near *,int,unsigned short>::Node_t,unsigned short,class CUtlMap<class CUtlLinkedList<unsigned __int64,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<unsigned __int64,int>,int>> __near *,int,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<class CUtlLinkedList<unsigned __int64,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<unsigned __int64,int>,int>> __near *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::RemoveAll(
        CUtlRBTree<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int> > *,int,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int> > *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int> > *,int,unsigned short>::Node_t,unsigned short>,unsigned short> > *this)
{
  unsigned __int16 index; // cx
  unsigned __int16 v3; // di
  int v4; // eax
  unsigned __int16 it; // [esp+4h] [ebp-4h]

  index = this->m_LastAlloc.index;
  if ( index != 0xFFFF )
  {
    v3 = (this->m_Elements.m_nAllocationCount > 0) - 1;
    it = v3;
    if ( this->m_Elements.m_nAllocationCount > 0 )
    {
      do
      {
        if ( v3 < this->m_Elements.m_nAllocationCount
          && v3 <= index
          && CUtlRBTree<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::LeftChild(
               this,
               i: it) != v3 )
        {
          v4 = v3;
          this->m_Elements.m_pMemory[v4].m_Right = this->m_FirstFree;
          this->m_Elements.m_pMemory[v4].m_Left = v3;
          this->m_FirstFree = v3;
        }
        index = this->m_LastAlloc.index;
        if ( v3 == index )
          break;
        ++v3;
        if ( (unsigned __int16)(it + 1) >= this->m_Elements.m_nAllocationCount )
          v3 = -1;
        it = v3;
      }
      while ( v3 != 0xFFFF );
    }
    *(_DWORD *)&this->m_Root = 0xFFFF;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10025030
// Name: protected: void CUtlRBTree<struct CUtlMap<class CUtlLinkedList<unsigned __int64,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<unsigned __int64,int>,int>> __near *,int,unsigned short>::Node_t,unsigned short,class CUtlMap<class CUtlLinkedList<unsigned __int64,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<unsigned __int64,int>,int>> __near *,int,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<class CUtlLinkedList<unsigned __int64,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<unsigned __int64,int>,int>> __near *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::InsertRebalance(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::InsertRebalance(
        CUtlRBTree<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int> > *,int,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int> > *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int> > *,int,unsigned short>::Node_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 elem)
{
  unsigned __int16 v2; // dx
  int v4; // eax
  int *v5; // ecx
  int v6; // ecx
  int *v7; // ecx
  int *v8; // ecx
  int v9; // edi
  int *v10; // ecx
  int v11; // ebx
  int *v12; // ecx
  int v13; // ecx
  int *v14; // ecx
  int *v15; // ecx
  int v16; // edx
  int *v17; // ecx
  int *v18; // ecx
  int v19; // ecx
  int *v20; // eax
  int v21; // ecx
  int *v22; // eax
  int *v23; // eax
  int *v24; // ecx
  int *v25; // ecx
  int *v26; // ecx
  int v27; // ecx
  int *v28; // eax
  int v29; // ecx
  int *v30; // eax
  int *v31; // eax

  v2 = elem;
  if ( elem != this->m_Root )
  {
    while ( 1 )
    {
      v4 = `CUtlRBTree<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard';
      if ( (`CUtlRBTree<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_10171FDC = 0x1FFFF;
        v4 = `CUtlRBTree<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
           | 1;
        `CUtlRBTree<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
      }
      if ( v2 == 0xFFFF )
        v5 = &`CUtlRBTree<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        v5 = (int *)&this->m_Elements.m_pMemory[v2];
      v6 = *((unsigned __int16 *)v5 + 2);
      if ( (v4 & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_10171FDC = 0x1FFFF;
        v4 |= 1u;
        `CUtlRBTree<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
      }
      if ( (_WORD)v6 == 0xFFFF )
        v7 = &`CUtlRBTree<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        v7 = (int *)&this->m_Elements.m_pMemory[v6];
      if ( *((_WORD *)v7 + 3) != 0 )
        break;
      if ( (v4 & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_10171FDC = 0x1FFFF;
        v4 |= 1u;
        `CUtlRBTree<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
      }
      if ( v2 == 0xFFFF )
        v8 = &`CUtlRBTree<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        v8 = (int *)&this->m_Elements.m_pMemory[v2];
      v9 = *((unsigned __int16 *)v8 + 2);
      if ( (v4 & 1) == 0 )
      {
        v4 |= 1u;
        `CUtlRBTree<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
        `CUtlRBTree<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_10171FDC = 0x1FFFF;
      }
      if ( (_WORD)v9 == 0xFFFF )
        v10 = &`CUtlRBTree<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        v10 = (int *)&this->m_Elements.m_pMemory[v9];
      v11 = *((unsigned __int16 *)v10 + 2);
      if ( (v4 & 1) == 0 )
      {
        v4 |= 1u;
        `CUtlRBTree<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
        `CUtlRBTree<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_10171FDC = 0x1FFFF;
      }
      if ( (_WORD)v9 == 0xFFFF )
        v12 = &`CUtlRBTree<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        v12 = (int *)&this->m_Elements.m_pMemory[v9];
      v13 = *((unsigned __int16 *)v12 + 2);
      if ( (v4 & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_10171FDC = 0x1FFFF;
        v4 |= 1u;
        `CUtlRBTree<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
      }
      if ( (_WORD)v13 == 0xFFFF )
        v14 = &`CUtlRBTree<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        v14 = (int *)&this->m_Elements.m_pMemory[v13];
      if ( *(_WORD *)v14 == (_WORD)v9 )
      {
        if ( (v4 & 1) == 0 )
        {
          v4 |= 1u;
          `CUtlRBTree<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
          `CUtlRBTree<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
          dword_10171FDC = 0x1FFFF;
        }
        if ( (_WORD)v11 == 0xFFFF )
          v15 = &`CUtlRBTree<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        else
          v15 = (int *)&this->m_Elements.m_pMemory[v11];
        v16 = *((unsigned __int16 *)v15 + 1);
        if ( (v4 & 1) == 0 )
        {
          `CUtlRBTree<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
          dword_10171FDC = 0x1FFFF;
          v4 |= 1u;
          `CUtlRBTree<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
        }
        if ( (_WORD)v16 == 0xFFFF )
          v17 = &`CUtlRBTree<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        else
          v17 = (int *)&this->m_Elements.m_pMemory[v16];
        if ( *((_WORD *)v17 + 3) == 0 )
          goto LABEL_81;
        if ( (v4 & 1) == 0 )
        {
          v4 |= 1u;
          `CUtlRBTree<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
          `CUtlRBTree<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
          dword_10171FDC = 0x1FFFF;
        }
        if ( elem == 0xFFFF )
          v18 = &`CUtlRBTree<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        else
          v18 = (int *)&this->m_Elements.m_pMemory[elem];
        v19 = *((unsigned __int16 *)v18 + 2);
        if ( (v4 & 1) == 0 )
        {
          `CUtlRBTree<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4 | 1;
          `CUtlRBTree<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
          dword_10171FDC = 0x1FFFF;
        }
        if ( (_WORD)v19 == 0xFFFF )
          v20 = &`CUtlRBTree<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        else
          v20 = (int *)&this->m_Elements.m_pMemory[v19];
        if ( *((_WORD *)v20 + 1) == elem )
        {
          elem = v9;
          CUtlRBTree<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::RotateLeft(
            this,
            elem: v9);
          v21 = `CUtlRBTree<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard';
          if ( (`CUtlRBTree<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
              & 1) == 0 )
          {
            v21 = `CUtlRBTree<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
                | 1;
            `CUtlRBTree<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
            `CUtlRBTree<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
            dword_10171FDC = 0x1FFFF;
          }
          if ( (_WORD)v9 == 0xFFFF )
            v22 = &`CUtlRBTree<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
          else
            v22 = (int *)&this->m_Elements.m_pMemory[v9];
          v9 = *((unsigned __int16 *)v22 + 2);
          if ( (v21 & 1) == 0 )
          {
            `CUtlRBTree<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v21 | 1;
            `CUtlRBTree<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
            dword_10171FDC = 0x1FFFF;
          }
          if ( (_WORD)v9 == 0xFFFF )
            v23 = &`CUtlRBTree<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
          else
            v23 = (int *)&this->m_Elements.m_pMemory[v9];
          LOWORD(v11) = *((_WORD *)v23 + 2);
        }
        this->m_Elements.m_pMemory[(unsigned __int16)v9].m_Tag = 1;
        this->m_Elements.m_pMemory[(unsigned __int16)v11].m_Tag = 0;
        CUtlRBTree<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::RotateRight(
          this,
          elem: v11);
      }
      else
      {
        if ( (v4 & 1) == 0 )
        {
          v4 |= 1u;
          `CUtlRBTree<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
          `CUtlRBTree<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
          dword_10171FDC = 0x1FFFF;
        }
        if ( (_WORD)v11 == 0xFFFF )
          v24 = &`CUtlRBTree<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        else
          v24 = (int *)&this->m_Elements.m_pMemory[v11];
        v16 = *(unsigned __int16 *)v24;
        if ( (v4 & 1) == 0 )
        {
          `CUtlRBTree<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
          dword_10171FDC = 0x1FFFF;
          v4 |= 1u;
          `CUtlRBTree<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
        }
        if ( (_WORD)v16 == 0xFFFF )
          v25 = &`CUtlRBTree<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        else
          v25 = (int *)&this->m_Elements.m_pMemory[v16];
        if ( *((_WORD *)v25 + 3) == 0 )
        {
LABEL_81:
          this->m_Elements.m_pMemory[v9].m_Tag = 1;
          this->m_Elements.m_pMemory[v16].m_Tag = 1;
          this->m_Elements.m_pMemory[v11].m_Tag = 0;
          elem = v11;
          goto LABEL_105;
        }
        if ( (v4 & 1) == 0 )
        {
          v4 |= 1u;
          `CUtlRBTree<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
          `CUtlRBTree<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
          dword_10171FDC = 0x1FFFF;
        }
        if ( elem == 0xFFFF )
          v26 = &`CUtlRBTree<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        else
          v26 = (int *)&this->m_Elements.m_pMemory[elem];
        v27 = *((unsigned __int16 *)v26 + 2);
        if ( (v4 & 1) == 0 )
        {
          `CUtlRBTree<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4 | 1;
          `CUtlRBTree<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
          dword_10171FDC = 0x1FFFF;
        }
        if ( (_WORD)v27 == 0xFFFF )
          v28 = &`CUtlRBTree<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        else
          v28 = (int *)&this->m_Elements.m_pMemory[v27];
        if ( *(_WORD *)v28 == elem )
        {
          elem = v9;
          CUtlRBTree<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::RotateRight(
            this,
            elem: v9);
          v29 = `CUtlRBTree<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard';
          if ( (`CUtlRBTree<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
              & 1) == 0 )
          {
            v29 = `CUtlRBTree<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
                | 1;
            `CUtlRBTree<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
            `CUtlRBTree<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
            dword_10171FDC = 0x1FFFF;
          }
          if ( (_WORD)v9 == 0xFFFF )
            v30 = &`CUtlRBTree<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
          else
            v30 = (int *)&this->m_Elements.m_pMemory[v9];
          v9 = *((unsigned __int16 *)v30 + 2);
          if ( (v29 & 1) == 0 )
          {
            `CUtlRBTree<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v29 | 1;
            `CUtlRBTree<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
            dword_10171FDC = 0x1FFFF;
          }
          if ( (_WORD)v9 == 0xFFFF )
            v31 = &`CUtlRBTree<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
          else
            v31 = (int *)&this->m_Elements.m_pMemory[v9];
          LOWORD(v11) = *((_WORD *)v31 + 2);
        }
        this->m_Elements.m_pMemory[(unsigned __int16)v9].m_Tag = 1;
        this->m_Elements.m_pMemory[(unsigned __int16)v11].m_Tag = 0;
        CUtlRBTree<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::RotateLeft(
          this,
          elem: v11);
      }
LABEL_105:
      if ( elem == this->m_Root )
        break;
      v2 = elem;
    }
  }
  this->m_Elements.m_pMemory[this->m_Root].m_Tag = 1;
}

//------------------------------------------------------------------------------
// Address: 0x100293A0
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
// Address: 0x10029670
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
// Address: 0x10029840
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
      CUtlMemory<bool,int>::Grow((CUtlMemory<char,int> *)this, num: size - m_nAllocationCount);
    this->m_Size += size;
    m_pMemory = this->m_Memory.m_pMemory;
    v5 = this->m_Size - size;
    this->m_pElements = this->m_Memory.m_pMemory;
    if ( v5 > 0 && size > 0 )
      _V_memmove(dest: &m_pMemory[size], src: m_pMemory, count: v5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002D9D0
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

//------------------------------------------------------------------------------
// Address: 0x1002EFB0
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
    CUtlMemory<CWUStatus,int>::Grow(
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
// Address: 0x1002F1B0
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
    CUtlMemory<CWUStatus,int>::Grow(
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
// Address: 0x1002F6C0
// Name: public: void CUtlVector<class CWorkUnit,class CUtlMemory<class CWorkUnit,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CWorkUnit,CUtlMemory<CWorkUnit,int>>::RemoveAll(
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
// Address: 0x1002F7D0
// Name: public: CUtlVector<class CWorkUnit,class CUtlMemory<class CWorkUnit,int>>::~CUtlVector<class CWorkUnit,class CUtlMemory<class CWorkUnit,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CWorkUnit,CUtlMemory<CWorkUnit,int>>::~CUtlVector<CWorkUnit,CUtlMemory<CWorkUnit,int>>(
        CUtlVector<CWorkUnit,CUtlMemory<CWorkUnit,int> > *this)
{
  bool v2; // sf
  CWorkUnit *m_pMemory; // eax

  CUtlVector<CWorkUnit,CUtlMemory<CWorkUnit,int>>::RemoveAll(this);
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
// Address: 0x1002F8E0
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
// Address: 0x1002FBA0
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
// Address: 0x1002FC80
// Name: public: void CUtlMemory<class CWUStatus,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<CWUStatus,int>::Grow(
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
// Address: 0x100301C0
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
// Address: 0x10030A20
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
// Address: 0x1000EEB0
// Name: ForEachFileRecursive_void_(__cdecl_)(char_const__)_
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ForEachFileRecursive_void____cdecl___char_const____(
        const char *pStartingPath,
        void (__cdecl *callbackFunction)(const char *))
{
  HANDLE FirstFileA; // edi
  char searchPath[260]; // [esp+8h] [ebp-348h] BYREF
  char fullFilePath[260]; // [esp+10Ch] [ebp-244h] BYREF
  _WIN32_FIND_DATAA findFileData; // [esp+210h] [ebp-140h] BYREF

  V_strncpy(pDest: searchPath, pSrc: pStartingPath, maxLen: 260);
  V_ComposeFileName(path: pStartingPath, filename: "*.*", dest: searchPath, destSize: 260);
  FirstFileA = FindFirstFileA(lpFileName: searchPath, lpFindFileData: &findFileData);
  if ( FirstFileA != (HANDLE)-1 )
  {
    do
    {
      if ( _V_stricmp(s1: findFileData.cFileName, s2: ".") != 0 && _V_stricmp(s1: findFileData.cFileName, s2: "..") != 0 )
      {
        V_ComposeFileName(path: pStartingPath, filename: findFileData.cFileName, dest: fullFilePath, destSize: 260);
        printf(format: "Found file: %s\n\n", fullFilePath);
        if ( (findFileData.dwFileAttributes & 0x10) != 0 )
          ForEachFileRecursive_void____cdecl___char_const____(pStartingPath: fullFilePath, callbackFunction);
        else
          callbackFunction(a1: fullFilePath);
      }
    }
    while ( FindNextFileA(hFindFile: FirstFileA, lpFindFileData: &findFileData) );
  }
  FindClose(hFindFile: FirstFileA);
}
