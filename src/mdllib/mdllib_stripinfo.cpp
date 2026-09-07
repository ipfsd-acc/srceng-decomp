// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: mdllib/mdllib_stripinfo.cpp
// Functions: 26
// ============================================================

#include "mdllib\mdllib_stripinfo.h"

//------------------------------------------------------------------------------
// Address: 0x10001630
// Name: public: void CUtlVector<unsigned short,class CUtlMemory<unsigned short,int>>::EnsureCapacity(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<unsigned short,CUtlMemory<unsigned short,int>>::EnsureCapacity(
        CUtlVector<unsigned short,CUtlMemory<unsigned short,int> > *this,
        int num)
{
  unsigned __int16 *m_pMemory; // edx
  unsigned int v4; // eax
  unsigned __int16 *v5; // eax

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
    v4 = 2 * num;
    if ( m_pMemory != nullptr )
    {
      this->m_Memory.m_pMemory = (unsigned __int16 *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v4);
      goto LABEL_5;
    }
    v5 = (unsigned __int16 *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v4);
    this->m_Memory.m_pMemory = v5;
    this->m_pElements = v5;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10001B70
// Name: public: CUtlVector<unsigned short,class CUtlMemory<unsigned short,int>>::~CUtlVector<unsigned short,class CUtlMemory<unsigned short,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<unsigned short,CUtlMemory<unsigned short,int>>::~CUtlVector<unsigned short,CUtlMemory<unsigned short,int>>(
        CUtlVector<CMdlStripInfo::MdlRangeItem,CUtlMemory<CMdlStripInfo::MdlRangeItem,int> > *this)
{
  bool v2; // sf
  CMdlStripInfo::MdlRangeItem *m_pMemory; // eax

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
// Address: 0x10001CE0
// Name: public: int CUtlVector<struct OptimizedModel::OptimizedIndexBufferMarkupPs3_t __near *,class CUtlMemory<struct OptimizedModel::OptimizedIndexBufferMarkupPs3_t __near *,int>>::InsertBefore(int,struct OptimizedModel::OptimizedIndexBufferMarkupPs3_t __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<OptimizedModel::OptimizedIndexBufferMarkupPs3_t *,CUtlMemory<OptimizedModel::OptimizedIndexBufferMarkupPs3_t *,int>>::InsertBefore(
        CUtlVector<OptimizedModel::OptimizedIndexBufferMarkupPs3_t *,CUtlMemory<OptimizedModel::OptimizedIndexBufferMarkupPs3_t *,int> > *this,
        int elem,
        OptimizedModel::OptimizedIndexBufferMarkupPs3_t **src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  OptimizedModel::OptimizedIndexBufferMarkupPs3_t **m_pMemory; // ecx
  int v7; // eax
  OptimizedModel::OptimizedIndexBufferMarkupPs3_t **v8; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<int,int>::Grow(this: &this->m_Memory, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 4 * v7);
  v8 = &this->m_Memory.m_pMemory[elem];
  if ( v8 != nullptr )
    *v8 = *src;
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x10002510
// Name: public: void CUtlVector<struct CMdlStripInfo::Ps3studioPartition_t __near *,class CUtlMemory<struct CMdlStripInfo::Ps3studioPartition_t __near *,int>>::PurgeAndDeleteElements(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CMdlStripInfo::Ps3studioPartition_t *,CUtlMemory<CMdlStripInfo::Ps3studioPartition_t *,int>>::PurgeAndDeleteElements(
        CUtlVector<CMdlStripInfo::Ps3studioPartition_t *,CUtlMemory<CMdlStripInfo::Ps3studioPartition_t *,int> > *this)
{
  int v2; // eax
  CMdlStripInfo::Ps3studioPartition_t *v3; // esi
  unsigned int *m_pMemory; // eax
  unsigned int *v5; // eax
  unsigned __int16 *v6; // eax
  CMdlStripInfo::Ps3studioPartition_t **v7; // ecx
  int i; // [esp+8h] [ebp-4h]

  v2 = 0;
  for ( i = 0; v2 < this->m_Size; i = v2 )
  {
    v3 = this->m_Memory.m_pMemory[v2];
    if ( v3 != nullptr )
    {
      v3->m_arrStripLocalOriginalIndices.m_Size = 0;
      if ( v3->m_arrStripLocalOriginalIndices.m_Memory.m_nGrowSize >= 0 )
      {
        if ( v3->m_arrStripLocalOriginalIndices.m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v3->m_arrStripLocalOriginalIndices.m_Memory.m_pMemory);
          v3->m_arrStripLocalOriginalIndices.m_Memory.m_pMemory = nullptr;
        }
        v3->m_arrStripLocalOriginalIndices.m_Memory.m_nAllocationCount = 0;
      }
      m_pMemory = v3->m_arrStripLocalOriginalIndices.m_Memory.m_pMemory;
      v3->m_arrStripLocalOriginalIndices.m_pElements = m_pMemory;
      if ( v3->m_arrStripLocalOriginalIndices.m_Memory.m_nGrowSize >= 0 )
      {
        if ( m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
          v3->m_arrStripLocalOriginalIndices.m_Memory.m_pMemory = nullptr;
        }
        v3->m_arrStripLocalOriginalIndices.m_Memory.m_nAllocationCount = 0;
      }
      v3->m_arrVertOriginalIndices.m_Size = 0;
      if ( v3->m_arrVertOriginalIndices.m_Memory.m_nGrowSize >= 0 )
      {
        if ( v3->m_arrVertOriginalIndices.m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v3->m_arrVertOriginalIndices.m_Memory.m_pMemory);
          v3->m_arrVertOriginalIndices.m_Memory.m_pMemory = nullptr;
        }
        v3->m_arrVertOriginalIndices.m_Memory.m_nAllocationCount = 0;
      }
      v5 = v3->m_arrVertOriginalIndices.m_Memory.m_pMemory;
      v3->m_arrVertOriginalIndices.m_pElements = v5;
      if ( v3->m_arrVertOriginalIndices.m_Memory.m_nGrowSize >= 0 )
      {
        if ( v5 != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v5);
          v3->m_arrVertOriginalIndices.m_Memory.m_pMemory = nullptr;
        }
        v3->m_arrVertOriginalIndices.m_Memory.m_nAllocationCount = 0;
      }
      v3->m_arrLocalIndices.m_Size = 0;
      if ( v3->m_arrLocalIndices.m_Memory.m_nGrowSize >= 0 )
      {
        if ( v3->m_arrLocalIndices.m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v3->m_arrLocalIndices.m_Memory.m_pMemory);
          v3->m_arrLocalIndices.m_Memory.m_pMemory = nullptr;
        }
        v3->m_arrLocalIndices.m_Memory.m_nAllocationCount = 0;
      }
      v6 = v3->m_arrLocalIndices.m_Memory.m_pMemory;
      v3->m_arrLocalIndices.m_pElements = v3->m_arrLocalIndices.m_Memory.m_pMemory;
      if ( v3->m_arrLocalIndices.m_Memory.m_nGrowSize >= 0 )
      {
        if ( v6 != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v6);
          v3->m_arrLocalIndices.m_Memory.m_pMemory = nullptr;
        }
        v3->m_arrLocalIndices.m_Memory.m_nAllocationCount = 0;
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
    v7 = this->m_Memory.m_pMemory;
    this->m_Memory.m_nAllocationCount = 0;
    this->m_pElements = v7;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10002740
// Name: public: void CUtlVector<struct CMdlStripInfo::Ps3studioBatch_t __near *,class CUtlMemory<struct CMdlStripInfo::Ps3studioBatch_t __near *,int>>::PurgeAndDeleteElements(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CMdlStripInfo::Ps3studioBatch_t *,CUtlMemory<CMdlStripInfo::Ps3studioBatch_t *,int>>::PurgeAndDeleteElements(
        CUtlVector<CMdlStripInfo::Ps3studioBatch_t *,CUtlMemory<CMdlStripInfo::Ps3studioBatch_t *,int> > *this)
{
  int v2; // eax
  CMdlStripInfo::Ps3studioBatch_t *v3; // esi
  CMdlStripInfo::Ps3studioPartition_t **m_pMemory; // eax
  CMdlStripInfo::Ps3studioBatch_t **v5; // ecx
  int i; // [esp+8h] [ebp-4h]

  v2 = 0;
  for ( i = 0; v2 < this->m_Size; i = v2 )
  {
    v3 = this->m_Memory.m_pMemory[v2];
    if ( v3 != nullptr )
    {
      CUtlVector<CMdlStripInfo::Ps3studioPartition_t *,CUtlMemory<CMdlStripInfo::Ps3studioPartition_t *,int>>::PurgeAndDeleteElements(this: &this->m_Memory.m_pMemory[v2]->m_arrPartitions);
      v3->m_arrPartitions.m_Size = 0;
      if ( v3->m_arrPartitions.m_Memory.m_nGrowSize >= 0 )
      {
        if ( v3->m_arrPartitions.m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v3->m_arrPartitions.m_Memory.m_pMemory);
          v3->m_arrPartitions.m_Memory.m_pMemory = nullptr;
        }
        v3->m_arrPartitions.m_Memory.m_nAllocationCount = 0;
      }
      m_pMemory = v3->m_arrPartitions.m_Memory.m_pMemory;
      v3->m_arrPartitions.m_pElements = v3->m_arrPartitions.m_Memory.m_pMemory;
      if ( v3->m_arrPartitions.m_Memory.m_nGrowSize >= 0 )
      {
        if ( m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
          v3->m_arrPartitions.m_Memory.m_pMemory = nullptr;
        }
        v3->m_arrPartitions.m_Memory.m_nAllocationCount = 0;
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
// Address: 0x10005160
// Name: public: virtual bool CMdlStripInfo::GetCheckSum(long __near *,long __near *)const
// Source: json
//------------------------------------------------------------------------------
char __thiscall CMdlStripInfo::GetCheckSum(CMdlStripInfo *this, int *plChecksumOriginal, int *plChecksumStripped)
{
  if ( this->m_eMode == 0 )
    return 0;
  if ( plChecksumOriginal != nullptr )
    *plChecksumOriginal = this->m_lChecksumOld;
  if ( plChecksumStripped != nullptr )
    *plChecksumStripped = this->m_lChecksumNew;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10005190
// Name: public: void CUtlMemory<int,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<int,int>::Grow(
        CUtlMemory<OptimizedModel::OptimizedIndexBufferMarkupPs3_t *,int> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  OptimizedModel::OptimizedIndexBufferMarkupPs3_t **m_pMemory; // edx
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
      this->m_pMemory = (OptimizedModel::OptimizedIndexBufferMarkupPs3_t **)_g_pMemAlloc->Realloc_2(
                                                                              this: _g_pMemAlloc,
                                                                              a2: m_pMemory,
                                                                              a3: v7);
    else
      this->m_pMemory = (OptimizedModel::OptimizedIndexBufferMarkupPs3_t **)_g_pMemAlloc->Alloc_2(
                                                                              this: _g_pMemAlloc,
                                                                              a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10005220
// Name: public: void CUtlMemory<struct CMdlStripInfo::MdlRangeItem,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<CMdlStripInfo::MdlRangeItem,int>::Grow(
        CUtlMemory<CMdlStripInfo::MdlRangeItem,int> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  CMdlStripInfo::MdlRangeItem *m_pMemory; // edx
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
      this->m_pMemory = (CMdlStripInfo::MdlRangeItem *)_g_pMemAlloc->Realloc_2(
                                                         this: _g_pMemAlloc,
                                                         a2: m_pMemory,
                                                         a3: v7);
    else
      this->m_pMemory = (CMdlStripInfo::MdlRangeItem *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100052B0
// Name: public: void CByteswap::SwapBufferToTargetEndian<unsigned int>(unsigned int __near *,unsigned int __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapBufferToTargetEndian<unsigned int>(
        CByteswap *this,
        int *outputBuffer,
        int *inputBuffer,
        int count)
{
  int v4; // ebx
  int *v5; // edi
  int *v6; // eax
  char *v7; // esi
  char v8; // cl
  char v9; // dl
  char v10; // al
  char v11; // cl

  v4 = count;
  if ( count > 0 )
  {
    v5 = outputBuffer;
    if ( outputBuffer != nullptr )
    {
      v6 = inputBuffer;
      if ( inputBuffer == nullptr )
        v6 = outputBuffer;
      if ( (*(_BYTE *)this & 1) != 0 )
      {
        v7 = (char *)v6 + 2;
        do
        {
          v8 = v7[1];
          v9 = *v7;
          count = *v5;
          v10 = *(v7 - 1);
          BYTE1(count) = v9;
          LOBYTE(count) = v8;
          v11 = *(v7 - 2);
          BYTE2(count) = v10;
          HIBYTE(count) = v11;
          _V_memcpy(dest: v5++, src: &count, count: 4);
          v7 += 4;
          --v4;
        }
        while ( v4 != 0 );
      }
      else if ( v6 != nullptr && outputBuffer != v6 )
      {
        memcpy(dst: (unsigned __int8 *)outputBuffer, src: (unsigned __int8 *)v6, count: 4 * count);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10005540
// Name: protected: void CUtlBuffer::PutTypeBin<int>(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlBuffer::PutTypeBin<int>(CUtlBuffer *this, int src)
{
  if ( CUtlBuffer::CheckPut(this, nSize: 4) )
  {
    if ( (*(_BYTE *)&this->m_Byteswap & 1) != 0 )
      CByteswap::SwapBufferToTargetEndian<unsigned int>(
        this: &this->m_Byteswap,
        outputBuffer: (int *)&this->m_Memory.m_pMemory[this->m_Put - this->m_nOffset],
        inputBuffer: &src,
        count: 1);
    else
      *(_DWORD *)&this->m_Memory.m_pMemory[this->m_Put - this->m_nOffset] = src;
    this->m_Put += 4;
    CUtlBuffer::AddNullTermination(this, nPut: this->m_Put);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100055B0
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
// Address: 0x10005620
// Name: public: int CUtlVector<struct CMdlStripInfo::MdlRangeItem,class CUtlMemory<struct CMdlStripInfo::MdlRangeItem,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CMdlStripInfo::MdlRangeItem,CUtlMemory<CMdlStripInfo::MdlRangeItem,int>>::InsertMultipleBefore(
        CUtlVector<CMdlStripInfo::MdlRangeItem,CUtlMemory<CMdlStripInfo::MdlRangeItem,int> > *this,
        int elem,
        int num)
{
  int v3; // edi
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CMdlStripInfo::MdlRangeItem *m_pMemory; // ecx
  int v9; // eax
  int v10; // ecx
  CMdlStripInfo::MdlRangeItem *v11; // eax

  v3 = num;
  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<CMdlStripInfo::MdlRangeItem,int>::Grow(this: &this->m_Memory, num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v9 = this->m_Size - elem - num;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v9 <= 0 )
    goto LABEL_8;
  if ( num > 0 )
  {
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 16 * v9);
LABEL_8:
    if ( num > 0 )
    {
      v10 = elem;
      do
      {
        v11 = &this->m_Memory.m_pMemory[v10];
        if ( v11 != nullptr )
        {
          v11->m_offOld = 0;
          v11->m_offNew = 0;
          v11->m_numOld = 0;
          v11->m_numNew = 0;
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
// Address: 0x100056C0
// Name: public: unsigned int CUtlBuffer::GetUnsignedInt(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CUtlBuffer::GetUnsignedInt(CUtlBuffer *this)
{
  unsigned __int8 *v2; // eax
  unsigned int result; // eax
  char *v4; // edi
  int nIncrement; // [esp+4h] [ebp-Ch] BYREF
  unsigned int i; // [esp+8h] [ebp-8h] BYREF
  char *endptr; // [esp+Ch] [ebp-4h] BYREF

  if ( (this->m_Flags & 1) == 0 )
  {
    if ( CUtlBuffer::CheckGet(this, nSize: 4) )
    {
      v2 = &this->m_Memory.m_pMemory[-this->m_nOffset];
      if ( (*(_BYTE *)&this->m_Byteswap & 1) != 0 )
      {
        CByteswap::SwapBufferToTargetEndian<unsigned int>(
          this: &this->m_Byteswap,
          outputBuffer: (int *)&i,
          inputBuffer: (int *)&v2[this->m_Get],
          count: 1);
        this->m_Get += 4;
        return i;
      }
      else
      {
        result = *(_DWORD *)&v2[this->m_Get];
        this->m_Get += 4;
      }
      return result;
    }
    return 0;
  }
  nIncrement = 128;
  if ( !CUtlBuffer::CheckArbitraryPeekGet(this, nOffset: 0, &nIncrement) )
    return 0;
  endptr = (char *)&this->m_Memory.m_pMemory[this->m_Get - this->m_nOffset];
  v4 = endptr;
  result = strtoul(nptr: endptr, &endptr, ibase: 10);
  if ( endptr != v4 )
    this->m_Get += endptr - v4;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10005760
// Name: public: CUtlBuffer::~CUtlBuffer(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlBuffer::~CUtlBuffer(CUtlBuffer *this)
{
  if ( this->m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10005790
// Name: public: virtual bool CMdlStripInfo::StripModelBuffer(class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CMdlStripInfo::StripModelBuffer(
        CMdlStripInfo *this,
        CUtlSortVector<unsigned short,CLessSimple<unsigned short> > *mdlBuffer)
{
  int v2; // esi
  unsigned __int8 *v4; // edi
  int m_eMode; // eax
  CUtlSortVector<unsigned short,CLessSimple<unsigned short> > *p_m_vtxIndices; // ebx
  int v7; // esi
  _DWORD *v8; // edi
  int m_Size; // eax
  int v10; // ebx
  int v11; // esi
  unsigned __int16 v12; // cx
  char *v13; // esi
  int Less; // eax
  int v15; // eax
  int v16; // ecx
  int v17; // edx
  studiohdr_t *mdlHdr; // [esp+4h] [ebp-20h]
  mstudiobodyparts_t *mdlBodyPart; // [esp+8h] [ebp-1Ch]
  unsigned __int16 src[2]; // [esp+Ch] [ebp-18h] BYREF
  int v21; // [esp+10h] [ebp-14h]
  int mdlBodyPart_idx; // [esp+14h] [ebp-10h]
  int mdlModel_idx; // [esp+18h] [ebp-Ch]
  int v24; // [esp+1Ch] [ebp-8h]
  int v25; // [esp+20h] [ebp-4h]
  CUtlSortVector<unsigned short,CLessSimple<unsigned short> > *srcIndices; // [esp+2Ch] [ebp+8h]

  v2 = 0;
  if ( this->m_eMode == 0 )
    return 0;
  v4 = (unsigned __int8 *)mdlBuffer->m_Memory.m_pMemory + mdlBuffer->m_Size;
  mdlHdr = (studiohdr_t *)v4;
  if ( *((_DWORD *)v4 + 2) != this->m_lChecksumOld )
  {
    if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_ModelLib, a2: 0) != 0 )
      _LoggingSystem_Log(a1: LOG_ModelLib, a2: 0, a3: "ERROR: [StripModelBuffer] checksum mismatch!\n");
    return 0;
  }
  *((_DWORD *)v4 + 2) = this->m_lChecksumNew;
  m_eMode = this->m_eMode;
  if ( m_eMode != 1 )
  {
    if ( m_eMode != 2 )
      return 0;
    p_m_vtxIndices = &this->m_vtxIndices;
    srcIndices = &this->m_vtxIndices;
    mdlBodyPart_idx = 0;
    if ( *((int *)v4 + 58) > 0 )
    {
      v21 = 0;
      do
      {
        v7 = (int)&v4[v2 + *((_DWORD *)v4 + 59)];
        mdlBodyPart = (mstudiobodyparts_t *)v7;
        mdlModel_idx = 0;
        if ( *(int *)(v7 + 4) > 0 )
        {
          v24 = 0;
          do
          {
            v8 = (_DWORD *)(v7 + v24 + *(_DWORD *)(v7 + 12));
            if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_ModelLib, a2: 0) != 0 )
              _LoggingSystem_Log(
                a1: LOG_ModelLib,
                a2: 0,
                a3: " Stripped %d vertexes (was: %d, now: %d).\n",
                v8[20] - p_m_vtxIndices->m_Size,
                v8[20],
                p_m_vtxIndices->m_Size);
            m_Size = p_m_vtxIndices->m_Size;
            v10 = 0;
            v8[20] = m_Size;
            if ( (int)v8[18] > 0 )
            {
              v25 = 0;
              do
              {
                v11 = v25 + v8[19];
                v12 = *(_WORD *)((char *)v8 + v11 + 12) + *(_WORD *)((char *)v8 + v11 + 8);
                v13 = (char *)v8 + v11;
                *(_DWORD *)src = v12;
                Less = CUtlSortVector<unsigned short,CLessSimple<unsigned short>>::FindLess(this: srcIndices, src);
                *(_DWORD *)src = *((unsigned __int16 *)v13 + 6);
                *((_DWORD *)v13 + 2) = Less;
                v15 = CUtlSortVector<unsigned short,CLessSimple<unsigned short>>::FindLess(this: srcIndices, src) + 1;
                *((_DWORD *)v13 + 3) = v15;
                v25 += 116;
                *((_DWORD *)v13 + 2) += 1 - v15;
                *((_DWORD *)v13 + 13) = *((_DWORD *)v13 + 2);
                *((_DWORD *)v13 + 14) = *((_DWORD *)v13 + 2);
                *((_DWORD *)v13 + 15) = *((_DWORD *)v13 + 2);
                *((_DWORD *)v13 + 16) = *((_DWORD *)v13 + 2);
                *((_DWORD *)v13 + 17) = *((_DWORD *)v13 + 2);
                *((_DWORD *)v13 + 18) = *((_DWORD *)v13 + 2);
                *((_DWORD *)v13 + 19) = *((_DWORD *)v13 + 2);
                ++v10;
                *((_DWORD *)v13 + 20) = *((_DWORD *)v13 + 2);
              }
              while ( v10 < v8[18] );
              v7 = (int)mdlBodyPart;
            }
            v24 += 148;
            p_m_vtxIndices = srcIndices;
            ++mdlModel_idx;
          }
          while ( mdlModel_idx < *(_DWORD *)(v7 + 4) );
          v4 = (unsigned __int8 *)mdlHdr;
        }
        v2 = v21 + 16;
        ++mdlBodyPart_idx;
        v21 += 16;
      }
      while ( mdlBodyPart_idx < *((_DWORD *)v4 + 58) );
    }
    v16 = 0;
    if ( *((int *)v4 + 39) > 0 )
    {
      v17 = 0;
      do
      {
        *(_DWORD *)&v4[v17 + 160 + *((_DWORD *)v4 + 40)] &= 0xFFFC07FF;
        ++v16;
        v17 += 216;
      }
      while ( v16 < *((_DWORD *)v4 + 39) );
    }
    if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_ModelLib, a2: 0) != 0 )
      _LoggingSystem_Log(a1: LOG_ModelLib, a2: 0, a3: " Updated %d bone(s).\n", *((_DWORD *)v4 + 39));
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100059D0
// Name: public: int CUtlVector<struct CMdlStripInfo::Ps3studioBatch_t __near *,class CUtlMemory<struct CMdlStripInfo::Ps3studioBatch_t __near *,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CMdlStripInfo::Ps3studioBatch_t *,CUtlMemory<CMdlStripInfo::Ps3studioBatch_t *,int>>::InsertMultipleBefore(
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
    CUtlMemory<int,int>::Grow(
      (CUtlMemory<OptimizedModel::OptimizedIndexBufferMarkupPs3_t *,int> *)this,
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
// Address: 0x10005A40
// Name: public: unsigned short CUtlBuffer::GetUnsignedShort(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlBuffer::GetUnsignedShort(CUtlBuffer *this)
{
  unsigned __int8 *v2; // eax
  int result; // eax
  char *v4; // edi
  int nIncrement; // [esp+4h] [ebp-Ch] BYREF
  int s; // [esp+8h] [ebp-8h] BYREF
  char *endptr; // [esp+Ch] [ebp-4h] BYREF

  if ( (this->m_Flags & 1) == 0 )
  {
    if ( CUtlBuffer::CheckGet(this, nSize: 2) )
    {
      v2 = &this->m_Memory.m_pMemory[-this->m_nOffset];
      if ( (*(_BYTE *)&this->m_Byteswap & 1) != 0 )
      {
        CByteswap::SwapBufferToTargetEndian<unsigned short>(
          this: &this->m_Byteswap,
          outputBuffer: (unsigned __int8 *)&s,
          inputBuffer: &v2[this->m_Get],
          count: 1);
        this->m_Get += 2;
        return s;
      }
      else
      {
        result = *(unsigned __int16 *)&v2[this->m_Get];
        this->m_Get += 2;
      }
      return result;
    }
    return 0;
  }
  nIncrement = 128;
  if ( !CUtlBuffer::CheckArbitraryPeekGet(this, nOffset: 0, &nIncrement) )
    return 0;
  endptr = (char *)&this->m_Memory.m_pMemory[this->m_Get - this->m_nOffset];
  v4 = endptr;
  result = (unsigned __int16)strtoul(nptr: endptr, &endptr, ibase: 10);
  if ( endptr != v4 )
    this->m_Get += endptr - v4;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10005AE0
// Name: public: int CUtlBuffer::GetInt(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlBuffer::GetInt(CUtlBuffer *this)
{
  unsigned __int8 *v2; // eax
  int result; // eax
  char *v4; // edi
  int nIncrement; // [esp+4h] [ebp-Ch] BYREF
  int i; // [esp+8h] [ebp-8h] BYREF
  char *endptr; // [esp+Ch] [ebp-4h] BYREF

  if ( (this->m_Flags & 1) == 0 )
  {
    if ( CUtlBuffer::CheckGet(this, nSize: 4) )
    {
      v2 = &this->m_Memory.m_pMemory[-this->m_nOffset];
      if ( (*(_BYTE *)&this->m_Byteswap & 1) != 0 )
      {
        CByteswap::SwapBufferToTargetEndian<unsigned int>(
          this: &this->m_Byteswap,
          outputBuffer: &i,
          inputBuffer: (int *)&v2[this->m_Get],
          count: 1);
        this->m_Get += 4;
        return i;
      }
      else
      {
        result = *(_DWORD *)&v2[this->m_Get];
        this->m_Get += 4;
      }
      return result;
    }
    return 0;
  }
  nIncrement = 128;
  if ( !CUtlBuffer::CheckArbitraryPeekGet(this, nOffset: 0, &nIncrement) )
    return 0;
  endptr = (char *)&this->m_Memory.m_pMemory[this->m_Get - this->m_nOffset];
  v4 = endptr;
  result = strtol(nptr: endptr, &endptr, ibase: 10);
  if ( endptr != v4 )
    this->m_Get += endptr - v4;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10005B80
// Name: public: CMdlStripInfo::CMdlStripInfo(void)
// Source: json
//------------------------------------------------------------------------------
CMdlStripInfo *__thiscall CMdlStripInfo::CMdlStripInfo(CMdlStripInfo *this)
{
  unsigned __int8 *m_pInt; // eax

  this->__vftable = (CMdlStripInfo_vtbl *)&CMdlStripInfo::`vftable';
  this->m_eMode = 0;
  this->m_lChecksumOld = 0;
  this->m_lChecksumNew = 0;
  *(_QWORD *)&this->m_vtxVerts.m_numBits = 0;
  *(_QWORD *)&this->m_vtxVerts.m_iBitStringStorage = 0;
  m_pInt = (unsigned __int8 *)this->m_vtxVerts.m_pInt;
  if ( m_pInt != nullptr )
    memset(dst: m_pInt, value: 0, count: 4 * this->m_vtxVerts.m_numInts);
  this->m_vtxIndices.m_Memory.m_pMemory = nullptr;
  this->m_vtxIndices.m_Memory.m_nAllocationCount = 0;
  this->m_vtxIndices.m_Memory.m_nGrowSize = 0;
  this->m_vtxIndices.m_Size = 0;
  this->m_vtxIndices.m_pElements = nullptr;
  this->m_vtxIndices.m_pLessContext = nullptr;
  this->m_vtxIndices.m_bNeedsSort = false;
  this->m_ps3studioBatches.m_Memory.m_pMemory = nullptr;
  this->m_ps3studioBatches.m_Memory.m_nAllocationCount = 0;
  this->m_ps3studioBatches.m_Memory.m_nGrowSize = 0;
  this->m_ps3studioBatches.m_Size = 0;
  this->m_ps3studioBatches.m_pElements = nullptr;
  this->m_ps3studioStripGroupHeaderBatchOffset.m_Memory.m_pMemory = nullptr;
  this->m_ps3studioStripGroupHeaderBatchOffset.m_Memory.m_nAllocationCount = 0;
  this->m_ps3studioStripGroupHeaderBatchOffset.m_Memory.m_nGrowSize = 0;
  this->m_ps3studioStripGroupHeaderBatchOffset.m_Size = 0;
  this->m_ps3studioStripGroupHeaderBatchOffset.m_pElements = nullptr;
  this->m_vtxMdlOffsets.m_Memory.m_pMemory = nullptr;
  this->m_vtxMdlOffsets.m_Memory.m_nAllocationCount = 0;
  this->m_vtxMdlOffsets.m_Memory.m_nGrowSize = 0;
  this->m_vtxMdlOffsets.m_Size = 0;
  this->m_vtxMdlOffsets.m_pElements = nullptr;
  this->m_vtxMdlOffsets.m_pLessContext = nullptr;
  this->m_vtxMdlOffsets.m_bNeedsSort = false;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10005C10
// Name: public: virtual bool CMdlStripInfo::Serialize(class CUtlBuffer __near &)const
// Source: json
//------------------------------------------------------------------------------
char __thiscall CMdlStripInfo::Serialize(CMdlStripInfo *this, unsigned int bufStorage)
{
  CUtlBuffer *v2; // esi
  char m_eMode; // al
  unsigned int *m_pInt; // ebx
  unsigned __int16 *m_pMemory; // edi
  unsigned __int16 v8; // bx
  CMdlStripInfo *v9; // ebx
  int v10; // edi
  const CMdlStripInfo::MdlRangeItem *v11; // edi
  int m_offOld; // ebx
  int m_offNew; // ebx
  int m_numOld; // ebx
  int m_numNew; // ebx
  bool v16; // cc
  bool v17; // zf
  CMdlStripInfo::Ps3studioBatch_t *v18; // edi
  int v19; // eax
  const CMdlStripInfo::MdlRangeItem *v20; // ebx
  int i; // edi
  __int16 v22; // bx
  int v23; // eax
  int *v24; // eax
  int v25; // ebx
  int m; // edi
  const CMdlStripInfo::MdlRangeItem *v27; // ebx
  const CMdlStripInfo::MdlRangeItem **v28; // eax
  const CMdlStripInfo::MdlRangeItem *v29; // ebx
  const CMdlStripInfo::MdlRangeItem **v30; // eax
  int n; // edi
  const CMdlStripInfo::MdlRangeItem *v32; // ebx
  const CMdlStripInfo::MdlRangeItem **v33; // eax
  const CMdlStripInfo::MdlRangeItem *v34; // ebx
  unsigned int *v35; // eax
  CMdlStripInfo::Ps3studioBatch_t *v36; // edi
  unsigned int m_uiModelIndexOffset; // ebx
  unsigned int m_uiVhvIndexOffset; // ebx
  CMdlStripInfo *v39; // ebx
  int v40; // edi
  unsigned int *v41; // ecx
  unsigned int v42; // ebx
  int m_lChecksumOld; // [esp-4h] [ebp-2Ch]
  int m_lChecksumNew; // [esp-4h] [ebp-2Ch]
  int v45; // [esp-4h] [ebp-2Ch]
  int v46; // [esp-4h] [ebp-2Ch]
  int m_numBits; // [esp-4h] [ebp-2Ch]
  int v48; // [esp-4h] [ebp-2Ch]
  int m_Size; // [esp-4h] [ebp-2Ch]
  int v50; // [esp-4h] [ebp-2Ch]
  int v51; // [esp-4h] [ebp-2Ch]
  int v52; // [esp-4h] [ebp-2Ch]
  int v53; // [esp-4h] [ebp-2Ch]
  const CMdlStripInfo::MdlRangeItem *pmriEnd; // [esp+Ch] [ebp-1Ch] BYREF
  int k; // [esp+10h] [ebp-18h]
  CMdlStripInfo::Ps3studioBatch_t *batch; // [esp+14h] [ebp-14h]
  int j; // [esp+18h] [ebp-10h]
  char chHeader[4]; // [esp+1Ch] [ebp-Ch] BYREF
  int src; // [esp+20h] [ebp-8h] BYREF
  CMdlStripInfo *v60; // [esp+24h] [ebp-4h]

  v2 = (CUtlBuffer *)bufStorage;
  m_eMode = this->m_eMode;
  v60 = this;
  qmemcpy(chHeader, "MAP", 3);
  chHeader[3] = m_eMode;
  CUtlBuffer::Put(this: (CUtlBuffer *)bufStorage, pMem: chHeader, size: 4);
  switch ( this->m_eMode )
  {
    case 1:
    case 4:
      m_lChecksumOld = this->m_lChecksumOld;
      if ( (v2->m_Flags & 1) != 0 )
        CUtlBuffer::Printf(this: v2, pFmt: "%d", m_lChecksumOld);
      else
        CUtlBuffer::PutTypeBin<int>(this: v2, src: m_lChecksumOld);
      m_lChecksumNew = this->m_lChecksumNew;
      if ( (v2->m_Flags & 1) != 0 )
        CUtlBuffer::Printf(this: v2, pFmt: "%d", m_lChecksumNew);
      else
        CUtlBuffer::PutTypeBin<int>(this: v2, src: m_lChecksumNew);
      return 1;
    case 2:
      v45 = this->m_lChecksumOld;
      if ( (v2->m_Flags & 1) != 0 )
        CUtlBuffer::Printf(this: v2, pFmt: "%d", v45);
      else
        CUtlBuffer::PutTypeBin<int>(this: v2, src: v45);
      v46 = this->m_lChecksumNew;
      if ( (v2->m_Flags & 1) != 0 )
        CUtlBuffer::Printf(this: v2, pFmt: "%d", v46);
      else
        CUtlBuffer::PutTypeBin<int>(this: v2, src: v46);
      m_numBits = this->m_vtxVerts.m_numBits;
      if ( (v2->m_Flags & 1) != 0 )
        CUtlBuffer::Printf(this: v2, pFmt: "%d", m_numBits);
      else
        CUtlBuffer::PutTypeBin<int>(this: v2, src: m_numBits);
      m_pInt = this->m_vtxVerts.m_pInt;
      for ( bufStorage = (unsigned int)&m_pInt[this->m_vtxVerts.m_numInts]; (unsigned int)m_pInt < bufStorage; ++m_pInt )
      {
        v48 = *m_pInt;
        if ( (v2->m_Flags & 1) != 0 )
          CUtlBuffer::Printf(this: v2, pFmt: "%u", v48);
        else
          CUtlBuffer::PutTypeBin<int>(this: v2, src: v48);
      }
      m_Size = this->m_vtxIndices.m_Size;
      if ( (v2->m_Flags & 1) != 0 )
        CUtlBuffer::Printf(this: v2, pFmt: "%d", m_Size);
      else
        CUtlBuffer::PutTypeBin<int>(this: v2, src: m_Size);
      m_pMemory = v60->m_vtxIndices.m_Memory.m_pMemory;
      for ( pmriEnd = (const CMdlStripInfo::MdlRangeItem *)&m_pMemory[v60->m_vtxIndices.m_Size];
            m_pMemory < (unsigned __int16 *)pmriEnd;
            ++m_pMemory )
      {
        v8 = *m_pMemory;
        if ( (v2->m_Flags & 1) != 0 )
        {
          CUtlBuffer::Printf(this: v2, pFmt: "%hu", *m_pMemory);
        }
        else
        {
          bufStorage = *m_pMemory;
          if ( CUtlBuffer::CheckPut(this: v2, nSize: 2) )
          {
            if ( (*(_BYTE *)&v2->m_Byteswap & 1) != 0 )
              CByteswap::SwapBufferToTargetEndian<unsigned short>(
                this: &v2->m_Byteswap,
                outputBuffer: &v2->m_Memory.m_pMemory[v2->m_Put - v2->m_nOffset],
                inputBuffer: (unsigned __int8 *)&bufStorage,
                count: 1);
            else
              *(_WORD *)&v2->m_Memory.m_pMemory[v2->m_Put - v2->m_nOffset] = v8;
            v2->m_Put += 2;
            CUtlBuffer::AddNullTermination(this: v2, nPut: v2->m_Put);
          }
        }
      }
      v9 = v60;
      v10 = v60->m_vtxMdlOffsets.m_Size;
      if ( (v2->m_Flags & 1) != 0 )
      {
        CUtlBuffer::Printf(this: v2, pFmt: "%d", v60->m_vtxMdlOffsets.m_Size);
      }
      else
      {
        bufStorage = v60->m_vtxMdlOffsets.m_Size;
        if ( CUtlBuffer::CheckPut(this: v2, nSize: 4) )
        {
          if ( (*(_BYTE *)&v2->m_Byteswap & 1) != 0 )
            CByteswap::SwapBufferToTargetEndian<unsigned int>(
              this: &v2->m_Byteswap,
              outputBuffer: (int *)&v2->m_Memory.m_pMemory[v2->m_Put - v2->m_nOffset],
              inputBuffer: (int *)&bufStorage,
              count: 1);
          else
            *(_DWORD *)&v2->m_Memory.m_pMemory[v2->m_Put - v2->m_nOffset] = v10;
          v2->m_Put += 4;
          CUtlBuffer::AddNullTermination(this: v2, nPut: v2->m_Put);
        }
      }
      v11 = v9->m_vtxMdlOffsets.m_Memory.m_pMemory;
      pmriEnd = &v11[v9->m_vtxMdlOffsets.m_Size];
      if ( v11 >= pmriEnd )
        return 1;
      do
      {
        m_offOld = v11->m_offOld;
        if ( (v2->m_Flags & 1) != 0 )
        {
          CUtlBuffer::Printf(this: v2, pFmt: "%d", v11->m_offOld);
        }
        else
        {
          bufStorage = v11->m_offOld;
          if ( CUtlBuffer::CheckPut(this: v2, nSize: 4) )
          {
            if ( (*(_BYTE *)&v2->m_Byteswap & 1) != 0 )
              CByteswap::SwapBufferToTargetEndian<unsigned int>(
                this: &v2->m_Byteswap,
                outputBuffer: (int *)&v2->m_Memory.m_pMemory[v2->m_Put - v2->m_nOffset],
                inputBuffer: (int *)&bufStorage,
                count: 1);
            else
              *(_DWORD *)&v2->m_Memory.m_pMemory[v2->m_Put - v2->m_nOffset] = m_offOld;
            v2->m_Put += 4;
            CUtlBuffer::AddNullTermination(this: v2, nPut: v2->m_Put);
          }
        }
        m_offNew = v11->m_offNew;
        if ( (v2->m_Flags & 1) != 0 )
        {
          CUtlBuffer::Printf(this: v2, pFmt: "%d", v11->m_offNew);
        }
        else
        {
          bufStorage = v11->m_offNew;
          if ( CUtlBuffer::CheckPut(this: v2, nSize: 4) )
          {
            if ( (*(_BYTE *)&v2->m_Byteswap & 1) != 0 )
              CByteswap::SwapBufferToTargetEndian<unsigned int>(
                this: &v2->m_Byteswap,
                outputBuffer: (int *)&v2->m_Memory.m_pMemory[v2->m_Put - v2->m_nOffset],
                inputBuffer: (int *)&bufStorage,
                count: 1);
            else
              *(_DWORD *)&v2->m_Memory.m_pMemory[v2->m_Put - v2->m_nOffset] = m_offNew;
            v2->m_Put += 4;
            CUtlBuffer::AddNullTermination(this: v2, nPut: v2->m_Put);
          }
        }
        m_numOld = v11->m_numOld;
        if ( (v2->m_Flags & 1) != 0 )
        {
          CUtlBuffer::Printf(this: v2, pFmt: "%d", v11->m_numOld);
        }
        else
        {
          bufStorage = v11->m_numOld;
          if ( CUtlBuffer::CheckPut(this: v2, nSize: 4) )
          {
            if ( (*(_BYTE *)&v2->m_Byteswap & 1) != 0 )
              CByteswap::SwapBufferToTargetEndian<unsigned int>(
                this: &v2->m_Byteswap,
                outputBuffer: (int *)&v2->m_Memory.m_pMemory[v2->m_Put - v2->m_nOffset],
                inputBuffer: (int *)&bufStorage,
                count: 1);
            else
              *(_DWORD *)&v2->m_Memory.m_pMemory[v2->m_Put - v2->m_nOffset] = m_numOld;
            v2->m_Put += 4;
            CUtlBuffer::AddNullTermination(this: v2, nPut: v2->m_Put);
          }
        }
        m_numNew = v11->m_numNew;
        if ( (v2->m_Flags & 1) != 0 )
        {
          CUtlBuffer::Printf(this: v2, pFmt: "%d", v11->m_numNew);
        }
        else
        {
          bufStorage = v11->m_numNew;
          if ( CUtlBuffer::CheckPut(this: v2, nSize: 4) )
          {
            if ( (*(_BYTE *)&v2->m_Byteswap & 1) != 0 )
              CByteswap::SwapBufferToTargetEndian<unsigned int>(
                this: &v2->m_Byteswap,
                outputBuffer: (int *)&v2->m_Memory.m_pMemory[v2->m_Put - v2->m_nOffset],
                inputBuffer: (int *)&bufStorage,
                count: 1);
            else
              *(_DWORD *)&v2->m_Memory.m_pMemory[v2->m_Put - v2->m_nOffset] = m_numNew;
            v2->m_Put += 4;
            CUtlBuffer::AddNullTermination(this: v2, nPut: v2->m_Put);
          }
        }
        ++v11;
      }
      while ( v11 < pmriEnd );
      return 1;
    case 3:
      v50 = this->m_lChecksumOld;
      if ( (v2->m_Flags & 1) != 0 )
        CUtlBuffer::Printf(this: v2, pFmt: "%d", v50);
      else
        CUtlBuffer::PutTypeBin<int>(this: v2, src: v50);
      v51 = this->m_lChecksumNew;
      if ( (v2->m_Flags & 1) != 0 )
        CUtlBuffer::Printf(this: v2, pFmt: "%d", v51);
      else
        CUtlBuffer::PutTypeBin<int>(this: v2, src: v51);
      v52 = this->m_ps3studioBatches.m_Size;
      if ( (v2->m_Flags & 1) != 0 )
        CUtlBuffer::Printf(this: v2, pFmt: "%u", v52);
      else
        CUtlBuffer::PutTypeBin<int>(this: v2, src: v52);
      v16 = this->m_ps3studioBatches.m_Size <= 0;
      k = 0;
      if ( v16 )
        goto LABEL_178;
      break;
    default:
      return 1;
  }
  while ( 1 )
  {
    v17 = (v2->m_Flags & 1) == 0;
    v18 = v60->m_ps3studioBatches.m_Memory.m_pMemory[k];
    v19 = v18->m_arrPartitions.m_Size;
    batch = v18;
    if ( v17 )
      CUtlBuffer::PutTypeBin<int>(this: v2, src: v19);
    else
      CUtlBuffer::Printf(this: v2, pFmt: "%u", v19);
    v16 = v18->m_arrPartitions.m_Size <= 0;
    j = 0;
    if ( !v16 )
      break;
LABEL_163:
    v36 = batch;
    m_uiModelIndexOffset = batch->m_uiModelIndexOffset;
    if ( (v2->m_Flags & 1) != 0 )
    {
      CUtlBuffer::Printf(this: v2, pFmt: "%u", batch->m_uiModelIndexOffset);
    }
    else
    {
      bufStorage = batch->m_uiModelIndexOffset;
      if ( CUtlBuffer::CheckPut(this: v2, nSize: 4) )
      {
        if ( (*(_BYTE *)&v2->m_Byteswap & 1) != 0 )
          CByteswap::SwapBufferToTargetEndian<unsigned int>(
            this: &v2->m_Byteswap,
            outputBuffer: (int *)&v2->m_Memory.m_pMemory[v2->m_Put - v2->m_nOffset],
            inputBuffer: (int *)&bufStorage,
            count: 1);
        else
          *(_DWORD *)&v2->m_Memory.m_pMemory[v2->m_Put - v2->m_nOffset] = m_uiModelIndexOffset;
        v2->m_Put += 4;
        CUtlBuffer::AddNullTermination(this: v2, nPut: v2->m_Put);
      }
    }
    m_uiVhvIndexOffset = v36->m_uiVhvIndexOffset;
    if ( (v2->m_Flags & 1) != 0 )
    {
      CUtlBuffer::Printf(this: v2, pFmt: "%u", v36->m_uiVhvIndexOffset);
    }
    else
    {
      bufStorage = v36->m_uiVhvIndexOffset;
      if ( CUtlBuffer::CheckPut(this: v2, nSize: 4) )
      {
        if ( (*(_BYTE *)&v2->m_Byteswap & 1) != 0 )
          CByteswap::SwapBufferToTargetEndian<unsigned int>(
            this: &v2->m_Byteswap,
            outputBuffer: (int *)&v2->m_Memory.m_pMemory[v2->m_Put - v2->m_nOffset],
            inputBuffer: (int *)&bufStorage,
            count: 1);
        else
          *(_DWORD *)&v2->m_Memory.m_pMemory[v2->m_Put - v2->m_nOffset] = m_uiVhvIndexOffset;
        v2->m_Put += 4;
        CUtlBuffer::AddNullTermination(this: v2, nPut: v2->m_Put);
      }
    }
    if ( ++k >= v60->m_ps3studioBatches.m_Size )
    {
LABEL_178:
      v39 = v60;
      v53 = v60->m_ps3studioStripGroupHeaderBatchOffset.m_Size;
      if ( (v2->m_Flags & 1) != 0 )
        CUtlBuffer::Printf(this: v2, pFmt: "%u", v53);
      else
        CUtlBuffer::PutTypeBin<int>(this: v2, src: v53);
      v40 = 0;
      if ( v39->m_ps3studioStripGroupHeaderBatchOffset.m_Size > 0 )
      {
        do
        {
          v41 = v60->m_ps3studioStripGroupHeaderBatchOffset.m_Memory.m_pMemory;
          v42 = v41[v40];
          if ( (v2->m_Flags & 1) != 0 )
          {
            CUtlBuffer::Printf(this: v2, pFmt: "%u", v41[v40]);
          }
          else
          {
            bufStorage = v41[v40];
            if ( CUtlBuffer::CheckPut(this: v2, nSize: 4) )
            {
              if ( (*(_BYTE *)&v2->m_Byteswap & 1) != 0 )
                CByteswap::SwapBufferToTargetEndian<unsigned int>(
                  this: &v2->m_Byteswap,
                  outputBuffer: (int *)&v2->m_Memory.m_pMemory[v2->m_Put - v2->m_nOffset],
                  inputBuffer: (int *)&bufStorage,
                  count: 1);
              else
                *(_DWORD *)&v2->m_Memory.m_pMemory[v2->m_Put - v2->m_nOffset] = v42;
              v2->m_Put += 4;
              CUtlBuffer::AddNullTermination(this: v2, nPut: v2->m_Put);
            }
          }
          ++v40;
        }
        while ( v40 < v60->m_ps3studioStripGroupHeaderBatchOffset.m_Size );
      }
      return 1;
    }
  }
  while ( 1 )
  {
    v17 = (v2->m_Flags & 1) == 0;
    v20 = (const CMdlStripInfo::MdlRangeItem *)batch->m_arrPartitions.m_Memory.m_pMemory[j]->m_arrLocalIndices.m_Size;
    bufStorage = (unsigned int)batch->m_arrPartitions.m_Memory.m_pMemory[j];
    if ( v17 )
    {
      pmriEnd = v20;
      if ( CUtlBuffer::CheckPut(this: v2, nSize: 4) )
      {
        if ( (*(_BYTE *)&v2->m_Byteswap & 1) != 0 )
          CByteswap::SwapBufferToTargetEndian<unsigned int>(
            this: &v2->m_Byteswap,
            outputBuffer: (int *)&v2->m_Memory.m_pMemory[v2->m_Put - v2->m_nOffset],
            inputBuffer: (int *)&pmriEnd,
            count: 1);
        else
          *(_DWORD *)&v2->m_Memory.m_pMemory[v2->m_Put - v2->m_nOffset] = v20;
        v2->m_Put += 4;
        CUtlBuffer::AddNullTermination(this: v2, nPut: v2->m_Put);
      }
    }
    else
    {
      CUtlBuffer::Printf(this: v2, pFmt: "%u", v20);
    }
    for ( i = 0; i < *(_DWORD *)(bufStorage + 12); ++i )
    {
      v22 = *(_WORD *)(*(_DWORD *)bufStorage + 2 * i);
      if ( (v2->m_Flags & 1) != 0 )
      {
        CUtlBuffer::Printf(this: v2, pFmt: "%hu", *(unsigned __int16 *)(*(_DWORD *)bufStorage + 2 * i));
        continue;
      }
      src = *(unsigned __int16 *)(*(_DWORD *)bufStorage + 2 * i);
      if ( CUtlBuffer::CheckPut(this: v2, nSize: 2) )
      {
        v23 = (int)&v2->m_Memory.m_pMemory[-v2->m_nOffset];
        if ( (*(_BYTE *)&v2->m_Byteswap & 1) == 0 )
        {
          *(_WORD *)(v23 + v2->m_Put) = v22;
LABEL_104:
          v2->m_Put += 2;
          CUtlBuffer::AddNullTermination(this: v2, nPut: v2->m_Put);
          continue;
        }
        v24 = (int *)(v2->m_Put + v23);
        if ( v24 == nullptr )
          goto LABEL_104;
        if ( (*(_BYTE *)&v2->m_Byteswap & 1) != 0 )
        {
          HIWORD(src) = 0;
          LOBYTE(src) = HIBYTE(v22);
          BYTE1(src) = v22;
          _V_memcpy(dest: v24, &src, count: 2);
          v2->m_Put += 2;
          CUtlBuffer::AddNullTermination(this: v2, nPut: v2->m_Put);
        }
        else
        {
          if ( v24 == &src )
            goto LABEL_104;
          *(_WORD *)v24 = src;
          v2->m_Put += 2;
          CUtlBuffer::AddNullTermination(this: v2, nPut: v2->m_Put);
        }
      }
    }
    v25 = *(_DWORD *)(bufStorage + 32);
    if ( (v2->m_Flags & 1) != 0 )
    {
      CUtlBuffer::Printf(this: v2, pFmt: "%u", *(_DWORD *)(bufStorage + 32));
    }
    else
    {
      pmriEnd = *(const CMdlStripInfo::MdlRangeItem **)(bufStorage + 32);
      if ( CUtlBuffer::CheckPut(this: v2, nSize: 4) )
      {
        if ( (*(_BYTE *)&v2->m_Byteswap & 1) != 0 )
          CByteswap::SwapBufferToTargetEndian<unsigned int>(
            this: &v2->m_Byteswap,
            outputBuffer: (int *)&v2->m_Memory.m_pMemory[v2->m_Put - v2->m_nOffset],
            inputBuffer: (int *)&pmriEnd,
            count: 1);
        else
          *(_DWORD *)&v2->m_Memory.m_pMemory[v2->m_Put - v2->m_nOffset] = v25;
        v2->m_Put += 4;
        CUtlBuffer::AddNullTermination(this: v2, nPut: v2->m_Put);
      }
    }
    for ( m = 0; m < *(_DWORD *)(bufStorage + 32); ++m )
    {
      v17 = (v2->m_Flags & 1) == 0;
      v27 = *(const CMdlStripInfo::MdlRangeItem **)(*(_DWORD *)(bufStorage + 20) + 4 * m);
      pmriEnd = v27;
      if ( !v17 )
      {
        CUtlBuffer::Printf(this: v2, pFmt: "%u", v27);
        continue;
      }
      if ( CUtlBuffer::CheckPut(this: v2, nSize: 4) )
      {
        if ( (*(_BYTE *)&v2->m_Byteswap & 1) == 0 )
        {
          *(_DWORD *)&v2->m_Memory.m_pMemory[v2->m_Put - v2->m_nOffset] = v27;
LABEL_124:
          v2->m_Put += 4;
          CUtlBuffer::AddNullTermination(this: v2, nPut: v2->m_Put);
          continue;
        }
        v28 = (const CMdlStripInfo::MdlRangeItem **)&v2->m_Memory.m_pMemory[v2->m_Put - v2->m_nOffset];
        if ( v28 == nullptr )
          goto LABEL_124;
        if ( (*(_BYTE *)&v2->m_Byteswap & 1) != 0 )
        {
          LOBYTE(src) = HIBYTE(pmriEnd);
          BYTE1(src) = BYTE2(pmriEnd);
          BYTE2(src) = BYTE1(v27);
          HIBYTE(src) = (_BYTE)v27;
          _V_memcpy(dest: v28, &src, count: 4);
          v2->m_Put += 4;
          CUtlBuffer::AddNullTermination(this: v2, nPut: v2->m_Put);
        }
        else
        {
          if ( v28 == &pmriEnd )
            goto LABEL_124;
          *v28 = v27;
          v2->m_Put += 4;
          CUtlBuffer::AddNullTermination(this: v2, nPut: v2->m_Put);
        }
      }
    }
    v17 = (v2->m_Flags & 1) == 0;
    v29 = *(const CMdlStripInfo::MdlRangeItem **)(bufStorage + 52);
    pmriEnd = v29;
    if ( v17 )
    {
      if ( !CUtlBuffer::CheckPut(this: v2, nSize: 4) )
        goto LABEL_138;
      if ( (*(_BYTE *)&v2->m_Byteswap & 1) != 0 )
      {
        v30 = (const CMdlStripInfo::MdlRangeItem **)&v2->m_Memory.m_pMemory[v2->m_Put - v2->m_nOffset];
        if ( v30 != nullptr )
        {
          if ( (*(_BYTE *)&v2->m_Byteswap & 1) != 0 )
          {
            LOBYTE(src) = HIBYTE(pmriEnd);
            BYTE1(src) = BYTE2(pmriEnd);
            BYTE2(src) = BYTE1(v29);
            HIBYTE(src) = (_BYTE)v29;
            _V_memcpy(dest: v30, &src, count: 4);
            v2->m_Put += 4;
            CUtlBuffer::AddNullTermination(this: v2, nPut: v2->m_Put);
            goto LABEL_138;
          }
          if ( v30 != &pmriEnd )
          {
            *v30 = v29;
            v2->m_Put += 4;
            CUtlBuffer::AddNullTermination(this: v2, nPut: v2->m_Put);
            goto LABEL_138;
          }
        }
      }
      else
      {
        *(_DWORD *)&v2->m_Memory.m_pMemory[v2->m_Put - v2->m_nOffset] = v29;
      }
      v2->m_Put += 4;
      CUtlBuffer::AddNullTermination(this: v2, nPut: v2->m_Put);
    }
    else
    {
      CUtlBuffer::Printf(this: v2, pFmt: "%u", v29);
    }
LABEL_138:
    for ( n = 0; n < *(_DWORD *)(bufStorage + 52); ++n )
    {
      v17 = (v2->m_Flags & 1) == 0;
      v32 = *(const CMdlStripInfo::MdlRangeItem **)(*(_DWORD *)(bufStorage + 40) + 4 * n);
      pmriEnd = v32;
      if ( !v17 )
      {
        CUtlBuffer::Printf(this: v2, pFmt: "%u", v32);
        continue;
      }
      if ( CUtlBuffer::CheckPut(this: v2, nSize: 4) )
      {
        if ( (*(_BYTE *)&v2->m_Byteswap & 1) == 0 )
        {
          *(_DWORD *)&v2->m_Memory.m_pMemory[v2->m_Put - v2->m_nOffset] = v32;
LABEL_148:
          v2->m_Put += 4;
          CUtlBuffer::AddNullTermination(this: v2, nPut: v2->m_Put);
          continue;
        }
        v33 = (const CMdlStripInfo::MdlRangeItem **)&v2->m_Memory.m_pMemory[v2->m_Put - v2->m_nOffset];
        if ( v33 == nullptr )
          goto LABEL_148;
        if ( (*(_BYTE *)&v2->m_Byteswap & 1) != 0 )
        {
          LOBYTE(src) = HIBYTE(pmriEnd);
          BYTE1(src) = BYTE2(pmriEnd);
          BYTE2(src) = BYTE1(v32);
          HIBYTE(src) = (_BYTE)v32;
          _V_memcpy(dest: v33, &src, count: 4);
          v2->m_Put += 4;
          CUtlBuffer::AddNullTermination(this: v2, nPut: v2->m_Put);
        }
        else
        {
          if ( v33 == &pmriEnd )
            goto LABEL_148;
          *v33 = v32;
          v2->m_Put += 4;
          CUtlBuffer::AddNullTermination(this: v2, nPut: v2->m_Put);
        }
      }
    }
    v17 = (v2->m_Flags & 1) == 0;
    v34 = *(const CMdlStripInfo::MdlRangeItem **)(bufStorage + 60);
    pmriEnd = v34;
    if ( !v17 )
    {
      CUtlBuffer::Printf(this: v2, pFmt: "%u", v34);
      goto LABEL_162;
    }
    if ( CUtlBuffer::CheckPut(this: v2, nSize: 4) )
    {
      if ( (*(_BYTE *)&v2->m_Byteswap & 1) == 0 )
      {
        *(_DWORD *)&v2->m_Memory.m_pMemory[v2->m_Put - v2->m_nOffset] = v34;
LABEL_160:
        v2->m_Put += 4;
        CUtlBuffer::AddNullTermination(this: v2, nPut: v2->m_Put);
        goto LABEL_162;
      }
      v35 = (unsigned int *)&v2->m_Memory.m_pMemory[v2->m_Put - v2->m_nOffset];
      if ( v35 == nullptr )
        goto LABEL_160;
      if ( (*(_BYTE *)&v2->m_Byteswap & 1) != 0 )
      {
        LOBYTE(bufStorage) = HIBYTE(pmriEnd);
        BYTE1(bufStorage) = BYTE2(pmriEnd);
        BYTE2(bufStorage) = BYTE1(v34);
        HIBYTE(bufStorage) = (_BYTE)v34;
        _V_memcpy(dest: v35, src: &bufStorage, count: 4);
        v2->m_Put += 4;
        CUtlBuffer::AddNullTermination(this: v2, nPut: v2->m_Put);
      }
      else
      {
        if ( v35 == &bufStorage )
          goto LABEL_160;
        *v35 = (unsigned int)v34;
        v2->m_Put += 4;
        CUtlBuffer::AddNullTermination(this: v2, nPut: v2->m_Put);
      }
    }
LABEL_162:
    if ( ++j >= batch->m_arrPartitions.m_Size )
      goto LABEL_163;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100067E0
// Name: public: virtual bool CMdlStripInfo::StripVertexDataBuffer(class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CMdlStripInfo::StripVertexDataBuffer(CMdlStripInfo *this, CUtlBuffer *vvdBuffer)
{
  int m_Get; // ecx
  unsigned __int8 *v5; // esi
  unsigned int v6; // eax
  int m_eMode; // ecx
  int v8; // edx
  int v9; // ecx
  unsigned __int8 *v10; // ebx
  unsigned __int8 *m_p; // eax
  unsigned __int8 *v12; // ecx
  unsigned __int8 *v13; // ebx
  int v14; // ecx
  int v15; // edx
  unsigned __int8 *v16; // ecx
  unsigned __int8 *v17; // ecx
  mstudiovertex_t *v18; // eax
  int v19; // ebx
  int v20; // ecx
  int v21; // esi
  float *v22; // eax
  int vvdLengthOld; // [esp+4h] [ebp-20h]
  int vvdLengthOlda; // [esp+4h] [ebp-20h]
  int mdlNumVerticesOld; // [esp+8h] [ebp-1Ch]
  int k; // [esp+Ch] [ebp-18h]
  mstudiovertex_t *vvdVertexSrc; // [esp+10h] [ebp-14h]
  CArrayAutoPtr<unsigned char> memTempVVD; // [esp+14h] [ebp-10h]
  unsigned __int8 *vvdTangentNew; // [esp+18h] [ebp-Ch]
  mstudiovertex_t *vvdVertexNew; // [esp+1Ch] [ebp-8h]
  unsigned __int8 *vvdTangentSrc; // [esp+20h] [ebp-4h]

  if ( this->m_eMode == 0 )
    return 0;
  m_Get = vvdBuffer->m_Get;
  v5 = &vvdBuffer->m_Memory.m_pMemory[m_Get];
  v6 = vvdBuffer->m_Put - m_Get;
  vvdLengthOld = v6;
  if ( *((_DWORD *)v5 + 2) != this->m_lChecksumOld )
  {
    if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_ModelLib, a2: 0) != 0 )
      _LoggingSystem_Log(a1: LOG_ModelLib, a2: 0, a3: "ERROR: [StripVertexDataBuffer] checksum mismatch!\n");
    return 0;
  }
  *((_DWORD *)v5 + 2) = this->m_lChecksumNew;
  m_eMode = this->m_eMode;
  if ( m_eMode != 1 )
  {
    if ( m_eMode != 2 )
      return 0;
    v8 = *((_DWORD *)v5 + 4);
    *((_DWORD *)v5 + 3) = 1;
    *((_DWORD *)v5 + 4) = this->m_vtxIndices.m_Size;
    mdlNumVerticesOld = v8;
    *((_DWORD *)v5 + 5) = this->m_vtxIndices.m_Size;
    *((_DWORD *)v5 + 6) = this->m_vtxIndices.m_Size;
    *((_DWORD *)v5 + 7) = this->m_vtxIndices.m_Size;
    *((_DWORD *)v5 + 8) = this->m_vtxIndices.m_Size;
    *((_DWORD *)v5 + 9) = this->m_vtxIndices.m_Size;
    *((_DWORD *)v5 + 10) = this->m_vtxIndices.m_Size;
    *((_DWORD *)v5 + 11) = this->m_vtxIndices.m_Size;
    v9 = *((_DWORD *)v5 + 15);
    v10 = &v5[*((_DWORD *)v5 + 14)];
    vvdVertexSrc = (mstudiovertex_t *)v10;
    if ( v9 != 0 )
      vvdTangentSrc = &v5[v9];
    else
      vvdTangentSrc = nullptr;
    if ( *((_DWORD *)v5 + 12) != 0 )
    {
      m_p = (unsigned __int8 *)operator new(nSize: v6);
      v12 = &m_p[*((_DWORD *)v5 + 14)];
      vvdTangentNew = &m_p[*((_DWORD *)v5 + 15)];
      memTempVVD.m_p = m_p;
      vvdVertexNew = (mstudiovertex_t *)v12;
      k = 0;
      if ( *((int *)v5 + 12) > 0 )
      {
        v13 = &v5[*((_DWORD *)v5 + 13) + 8];
        while ( 1 )
        {
          memcpy(dst: v12, src: (unsigned __int8 *)&vvdVertexSrc[*((_DWORD *)v13 - 1)], count: 48 * *(_DWORD *)v13);
          vvdVertexNew += *(_DWORD *)v13;
          if ( vvdTangentSrc != nullptr )
          {
            memcpy(dst: vvdTangentNew, src: &vvdTangentSrc[16 * *((_DWORD *)v13 - 1)], count: 16 * *(_DWORD *)v13);
            vvdTangentNew += 16 * *(_DWORD *)v13;
          }
          v13 += 12;
          if ( ++k >= *((_DWORD *)v5 + 12) )
            break;
          v12 = (unsigned __int8 *)vvdVertexNew;
        }
        m_p = memTempVVD.m_p;
        v10 = (unsigned __int8 *)vvdVertexSrc;
      }
      if ( v10 != nullptr )
      {
        memcpy(dst: v10, src: &m_p[*((_DWORD *)v5 + 14)], count: 48 * mdlNumVerticesOld);
        m_p = memTempVVD.m_p;
      }
      if ( vvdTangentSrc != nullptr )
      {
        memcpy(dst: vvdTangentSrc, src: &m_p[*((_DWORD *)v5 + 15)], count: 16 * mdlNumVerticesOld);
        m_p = memTempVVD.m_p;
      }
      free(pMem: m_p);
      free(pMem: nullptr);
      v6 = vvdLengthOld;
    }
    *((_DWORD *)v5 + 14) -= (12 * *((_DWORD *)v5 + 12) + 15) & 0xFFFFFFF0;
    v14 = *((_DWORD *)v5 + 14);
    v15 = 0;
    *((_DWORD *)v5 + 12) = 0;
    v16 = &v5[v14];
    if ( this->m_vtxIndices.m_Size > 0 )
    {
      v17 = v16 + 24;
      do
      {
        v18 = &vvdVertexSrc[this->m_vtxIndices.m_Memory.m_pMemory[v15++]];
        *((_QWORD *)v17 - 3) = *(_QWORD *)v18->m_BoneWeights.weight;
        *((_QWORD *)v17 - 2) = *(_QWORD *)&v18->m_BoneWeights.weight[2];
        *((float *)v17 - 2) = v18->m_vecPosition.x;
        v17 += 48;
        *((float *)v17 - 13) = v18->m_vecPosition.y;
        *((float *)v17 - 12) = v18->m_vecPosition.z;
        *((float *)v17 - 11) = v18->m_vecNormal.x;
        *((float *)v17 - 10) = v18->m_vecNormal.y;
        *((float *)v17 - 9) = v18->m_vecNormal.z;
        *((float *)v17 - 8) = v18->m_vecTexCoord.x;
        *((float *)v17 - 7) = v18->m_vecTexCoord.y;
      }
      while ( v15 < this->m_vtxIndices.m_Size );
      v6 = vvdLengthOld;
    }
    v19 = *((_DWORD *)v5 + 14) + 48 * this->m_vtxIndices.m_Size;
    vvdLengthOlda = v6;
    if ( vvdTangentSrc != nullptr )
    {
      v20 = 0;
      *((_DWORD *)v5 + 15) = v19;
      if ( this->m_vtxIndices.m_Size > 0 )
      {
        v21 = (int)&v5[v19 + 8];
        do
        {
          v22 = (float *)&vvdTangentSrc[16 * this->m_vtxIndices.m_Memory.m_pMemory[v20++]];
          v21 += 16;
          *(float *)(v21 - 24) = *v22;
          *(float *)(v21 - 20) = v22[1];
          *(float *)(v21 - 16) = v22[2];
          *(float *)(v21 - 12) = v22[3];
        }
        while ( v20 < this->m_vtxIndices.m_Size );
      }
      v19 += 16 * this->m_vtxIndices.m_Size;
    }
    CUtlBuffer::SeekPut(this: vvdBuffer, type: SEEK_CURRENT, offset: vvdBuffer->m_Get + v19 - vvdBuffer->m_Put);
    if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_ModelLib, a2: 0) != 0 )
      _LoggingSystem_Log(a1: LOG_ModelLib, a2: 0, a3: " Stripped %d vvd bytes.\n", vvdLengthOlda - v19);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10006AF0
// Name: public: virtual bool CMdlStripInfo::UnSerialize(class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CMdlStripInfo::UnSerialize(CMdlStripInfo *this, CUtlBuffer *bufData)
{
  CUtlBuffer *v2; // edi
  CMdlStripInfo *v3; // esi
  int v4; // eax
  bool result; // al
  int Int; // eax
  unsigned __int16 *m_pInt; // ebx
  int v8; // eax
  unsigned __int16 *m_pMemory; // ebx
  int v10; // eax
  CMdlStripInfo::MdlRangeItem *v11; // ebx
  CMdlStripInfo::MdlRangeItem *v12; // esi
  int UnsignedInt; // eax
  int v14; // ebx
  CMdlStripInfo::Ps3studioBatch_t *v15; // eax
  CUtlVector<unsigned int,CUtlMemory<unsigned int,int> > *v16; // esi
  int v17; // eax
  _DWORD *v18; // eax
  unsigned int v19; // esi
  int v20; // eax
  int v21; // eax
  int v22; // ecx
  char *v23; // edx
  int v24; // ecx
  int v25; // eax
  int v26; // ecx
  char *v27; // edx
  int v28; // ecx
  int v29; // eax
  _DWORD *v30; // [esp+8h] [ebp-18h]
  int v31; // [esp+8h] [ebp-18h]
  _DWORD *v32; // [esp+8h] [ebp-18h]
  unsigned int *v33; // [esp+8h] [ebp-18h]
  unsigned __int16 *pusEnda; // [esp+Ch] [ebp-14h]
  unsigned __int16 *pusEndb; // [esp+Ch] [ebp-14h]
  int k; // [esp+10h] [ebp-10h]
  CMdlStripInfo::Ps3studioBatch_t *batch; // [esp+14h] [ebp-Ch]
  int j; // [esp+18h] [ebp-8h]
  _WORD *nnc; // [esp+1Ch] [ebp-4h]
  int nn; // [esp+1Ch] [ebp-4h]
  int nna; // [esp+1Ch] [ebp-4h]
  int nnb; // [esp+1Ch] [ebp-4h]

  v2 = bufData;
  v3 = this;
  CUtlBuffer::Get(this: bufData, pMem: &bufData, size: 4);
  if ( (_BYTE)bufData != 77 || BYTE1(bufData) != 65 || BYTE2(bufData) != 80 )
    return false;
  v4 = SHIBYTE(bufData);
  v3->m_eMode = SHIBYTE(bufData);
  switch ( v4 )
  {
    case 0:
      v3->m_lChecksumOld = 0;
      v3->m_lChecksumNew = 0;
      goto LABEL_6;
    case 1:
    case 4:
      v3->m_lChecksumOld = CUtlBuffer::GetInt(this: v2);
      v3->m_lChecksumNew = CUtlBuffer::GetInt(this: v2);
      return true;
    case 2:
      v3->m_lChecksumOld = CUtlBuffer::GetInt(this: v2);
      v3->m_lChecksumNew = CUtlBuffer::GetInt(this: v2);
      Int = CUtlBuffer::GetInt(this: v2);
      CVarBitVecBase<int>::Resize(this: &v3->m_vtxVerts, resizeNumBits: Int, bClearAll: true);
      m_pInt = (unsigned __int16 *)v3->m_vtxVerts.m_pInt;
      for ( pusEnda = &m_pInt[2 * v3->m_vtxVerts.m_numInts]; m_pInt < pusEnda; m_pInt += 2 )
        *(_DWORD *)m_pInt = CUtlBuffer::GetUnsignedInt(this: v2);
      v8 = CUtlBuffer::GetInt(this: v2);
      v3->m_vtxIndices.m_Size = 0;
      CUtlVector<unsigned short,CUtlMemory<unsigned short,int>>::InsertMultipleBefore(
        this: &v3->m_vtxIndices,
        elem: 0,
        num: v8);
      m_pMemory = v3->m_vtxIndices.m_Memory.m_pMemory;
      for ( pusEndb = &m_pMemory[v3->m_vtxIndices.m_Size]; m_pMemory < pusEndb; ++m_pMemory )
        *m_pMemory = CUtlBuffer::GetUnsignedShort(this: v2);
      v10 = CUtlBuffer::GetInt(this: v2);
      v3->m_vtxMdlOffsets.m_Size = 0;
      CUtlVector<CMdlStripInfo::MdlRangeItem,CUtlMemory<CMdlStripInfo::MdlRangeItem,int>>::InsertMultipleBefore(
        this: &v3->m_vtxMdlOffsets,
        elem: 0,
        num: v10);
      v11 = v3->m_vtxMdlOffsets.m_Memory.m_pMemory;
      v12 = &v11[v3->m_vtxMdlOffsets.m_Size];
      if ( v11 >= v12 )
        goto LABEL_6;
      do
      {
        v11->m_offOld = CUtlBuffer::GetInt(this: v2);
        v11->m_offNew = CUtlBuffer::GetInt(this: v2);
        v11->m_numOld = CUtlBuffer::GetInt(this: v2);
        v11->m_numNew = CUtlBuffer::GetInt(this: v2);
        ++v11;
      }
      while ( v11 < v12 );
      result = true;
      break;
    case 3:
      v3->m_lChecksumOld = CUtlBuffer::GetInt(this: v2);
      v3->m_lChecksumNew = CUtlBuffer::GetInt(this: v2);
      UnsignedInt = CUtlBuffer::GetUnsignedInt(this: v2);
      v14 = 0;
      v3->m_ps3studioBatches.m_Size = 0;
      CUtlVector<CMdlStripInfo::Ps3studioBatch_t *,CUtlMemory<CMdlStripInfo::Ps3studioBatch_t *,int>>::InsertMultipleBefore(
        this: (CUtlVector<unsigned int,CUtlMemory<unsigned int,int> > *)&v3->m_ps3studioBatches,
        elem: 0,
        num: UnsignedInt);
      k = 0;
      if ( v3->m_ps3studioBatches.m_Size > 0 )
      {
        do
        {
          v15 = (CMdlStripInfo::Ps3studioBatch_t *)operator new(nSize: 0x1Cu);
          if ( v15 != nullptr )
          {
            v15->m_arrPartitions.m_Memory.m_pMemory = nullptr;
            v15->m_arrPartitions.m_Memory.m_nAllocationCount = 0;
            v15->m_arrPartitions.m_Memory.m_nGrowSize = 0;
            v15->m_arrPartitions.m_Size = 0;
            v15->m_arrPartitions.m_pElements = nullptr;
          }
          else
          {
            v15 = nullptr;
          }
          v3->m_ps3studioBatches.m_Memory.m_pMemory[k] = v15;
          v16 = (CUtlVector<unsigned int,CUtlMemory<unsigned int,int> > *)v3->m_ps3studioBatches.m_Memory.m_pMemory[k];
          batch = (CMdlStripInfo::Ps3studioBatch_t *)v16;
          v17 = CUtlBuffer::GetUnsignedInt(this: v2);
          v16->m_Size = 0;
          CUtlVector<CMdlStripInfo::Ps3studioBatch_t *,CUtlMemory<CMdlStripInfo::Ps3studioBatch_t *,int>>::InsertMultipleBefore(
            this: v16,
            elem: 0,
            num: v17);
          j = 0;
          if ( v16->m_Size > 0 )
          {
            do
            {
              v18 = operator new(nSize: 0x68u);
              if ( v18 != nullptr )
              {
                *v18 = 0;
                v18[1] = 0;
                v18[2] = 0;
                v18[3] = 0;
                v18[4] = 0;
                v18[5] = 0;
                v18[6] = 0;
                v18[7] = 0;
                v18[8] = 0;
                v18[9] = 0;
                v18[10] = 0;
                v18[11] = 0;
                v18[12] = 0;
                v18[13] = 0;
                v18[14] = 0;
              }
              else
              {
                v18 = nullptr;
              }
              v16->m_Memory.m_pMemory[j] = (unsigned int)v18;
              v19 = v16->m_Memory.m_pMemory[j];
              v20 = CUtlBuffer::GetUnsignedInt(this: v2);
              *(_DWORD *)(v19 + 12) = 0;
              CUtlVector<unsigned short,CUtlMemory<unsigned short,int>>::InsertMultipleBefore(
                this: (CUtlVector<unsigned short,CUtlMemory<unsigned short,int> > *)v19,
                elem: 0,
                num: v20);
              if ( *(int *)(v19 + 12) > 0 )
              {
                do
                {
                  nnc = (_WORD *)(*(_DWORD *)v19 + 2 * v14++);
                  *nnc = CUtlBuffer::GetUnsignedShort(this: v2);
                }
                while ( v14 < *(_DWORD *)(v19 + 12) );
              }
              v21 = CUtlBuffer::GetUnsignedInt(this: v2);
              nn = v21;
              *(_DWORD *)(v19 + 32) = 0;
              if ( v21 != 0 )
              {
                v22 = *(_DWORD *)(v19 + 24);
                if ( v21 > v22 )
                {
                  CUtlMemory<int,int>::Grow(
                    this: (CUtlMemory<OptimizedModel::OptimizedIndexBufferMarkupPs3_t *,int> *)(v19 + 20),
                    num: v21 - v22);
                  v21 = nn;
                }
                *(_DWORD *)(v19 + 32) += v21;
                v23 = *(char **)(v19 + 20);
                v24 = *(_DWORD *)(v19 + 32) - v21;
                *(_DWORD *)(v19 + 36) = v23;
                if ( v24 > 0 && v21 > 0 )
                  _V_memmove(dest: &v23[4 * v21], src: v23, count: 4 * v24);
              }
              for ( nna = 0; nna < *(_DWORD *)(v19 + 32); ++nna )
              {
                v30 = (_DWORD *)(*(_DWORD *)(v19 + 20) + 4 * nna);
                *v30 = CUtlBuffer::GetUnsignedInt(this: v2);
              }
              v25 = CUtlBuffer::GetUnsignedInt(this: v2);
              v31 = v25;
              *(_DWORD *)(v19 + 52) = 0;
              if ( v25 != 0 )
              {
                v26 = *(_DWORD *)(v19 + 44);
                if ( v25 > v26 )
                {
                  CUtlMemory<int,int>::Grow(
                    this: (CUtlMemory<OptimizedModel::OptimizedIndexBufferMarkupPs3_t *,int> *)(v19 + 40),
                    num: v25 - v26);
                  v25 = v31;
                }
                *(_DWORD *)(v19 + 52) += v25;
                v27 = *(char **)(v19 + 40);
                v28 = *(_DWORD *)(v19 + 52) - v25;
                *(_DWORD *)(v19 + 56) = v27;
                if ( v28 > 0 && v25 > 0 )
                  _V_memmove(dest: &v27[4 * v25], src: v27, count: 4 * v28);
              }
              for ( nnb = 0; nnb < *(_DWORD *)(v19 + 52); ++nnb )
              {
                v32 = (_DWORD *)(*(_DWORD *)(v19 + 40) + 4 * nnb);
                *v32 = CUtlBuffer::GetUnsignedInt(this: v2);
              }
              *(_DWORD *)(v19 + 60) = CUtlBuffer::GetUnsignedInt(this: v2);
              v14 = 0;
              ++j;
              v16 = (CUtlVector<unsigned int,CUtlMemory<unsigned int,int> > *)batch;
            }
            while ( j < batch->m_arrPartitions.m_Size );
          }
          v16[1].m_Memory.m_pMemory = (unsigned int *)CUtlBuffer::GetUnsignedInt(this: v2);
          v16[1].m_Memory.m_nAllocationCount = CUtlBuffer::GetUnsignedInt(this: v2);
          ++k;
          v3 = this;
        }
        while ( k < this->m_ps3studioBatches.m_Size );
      }
      v29 = CUtlBuffer::GetUnsignedInt(this: v2);
      v3->m_ps3studioStripGroupHeaderBatchOffset.m_Size = 0;
      CUtlVector<CMdlStripInfo::Ps3studioBatch_t *,CUtlMemory<CMdlStripInfo::Ps3studioBatch_t *,int>>::InsertMultipleBefore(
        this: &v3->m_ps3studioStripGroupHeaderBatchOffset,
        elem: 0,
        num: v29);
      if ( v3->m_ps3studioStripGroupHeaderBatchOffset.m_Size <= 0 )
      {
LABEL_6:
        result = true;
      }
      else
      {
        do
        {
          v33 = &v3->m_ps3studioStripGroupHeaderBatchOffset.m_Memory.m_pMemory[v14++];
          *v33 = CUtlBuffer::GetUnsignedInt(this: v2);
        }
        while ( v14 < v3->m_ps3studioStripGroupHeaderBatchOffset.m_Size );
        result = true;
      }
      break;
    default:
      result = false;
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10006F30
// Name: public: virtual bool CMdlStripInfo::StripHardwareVertsBuffer(class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CMdlStripInfo::StripHardwareVertsBuffer(CMdlStripInfo *this, unsigned int vhvBuffer)
{
  CMdlStripInfo *v2; // ebx
  int v4; // ecx
  unsigned __int8 *v5; // esi
  int m_eMode; // eax
  unsigned int *v7; // ecx
  unsigned __int8 *v8; // esi
  unsigned __int8 *v9; // edx
  unsigned int v10; // ebx
  unsigned int v11; // edx
  unsigned int v12; // ecx
  unsigned int *v13; // edi
  unsigned int v14; // eax
  unsigned int v15; // ecx
  int v16; // eax
  int NumBytesRegistered; // eax
  char *v18; // eax
  unsigned int v19; // ebx
  bool v20; // cc
  int *v21; // edi
  char *v22; // eax
  unsigned int v23; // eax
  int v24; // eax
  unsigned int v25; // ebx
  int NumBytesInserted; // eax
  int v27; // esi
  int v28; // eax
  int v29; // eax
  signed int m_Size; // ecx
  unsigned int v31; // eax
  _DWORD **v32; // eax
  int v33; // ecx
  int v34; // edx
  int v35; // edi
  _DWORD *v36; // eax
  unsigned int v37; // ecx
  unsigned int v38; // eax
  bool v39; // zf
  unsigned int v40; // edi
  int v41; // eax
  HardwareVerts::FileHeader_t *v42; // eax
  unsigned int v43; // ecx
  int v44; // edi
  unsigned int v45; // edx
  unsigned int v46; // edx
  unsigned int i; // edx
  CMdlStripInfo::Ps3studioBatch_t *v48; // esi
  unsigned int v49; // ebx
  CMdlStripInfo::Ps3studioPartition_t *v50; // edx
  int v51; // eax
  unsigned int v52; // ecx
  unsigned int v53; // eax
  int v54; // edi
  unsigned int v55; // edx
  CMemoryMovingTracker vhvRemove; // [esp+8h] [ebp-8Ch] BYREF
  CUtlBuffer v57; // [esp+3Ch] [ebp-58h] BYREF
  unsigned int *pVertDataSrc; // [esp+6Ch] [ebp-28h]
  HardwareVerts::FileHeader_t *vhvHdr; // [esp+70h] [ebp-24h]
  unsigned int iPartition; // [esp+74h] [ebp-20h]
  unsigned int iMesh; // [esp+78h] [ebp-1Ch]
  int numMeshesRemoved; // [esp+7Ch] [ebp-18h]
  int vhvLength; // [esp+80h] [ebp-14h] BYREF
  unsigned int iBatch; // [esp+84h] [ebp-10h]
  unsigned int vhvEndMeshOffset; // [esp+88h] [ebp-Ch]
  unsigned int numVerts; // [esp+8Ch] [ebp-8h]
  int j; // [esp+90h] [ebp-4h]
  unsigned int iBatchEnd; // [esp+9Ch] [ebp+8h]

  v2 = this;
  numMeshesRemoved = (int)this;
  if ( this->m_eMode == 0 )
    return 0;
  v4 = *(_DWORD *)(vhvBuffer + 12);
  v5 = (unsigned __int8 *)(v4 + *(_DWORD *)vhvBuffer);
  vhvLength = *(_DWORD *)(vhvBuffer + 16) - v4;
  if ( *((_DWORD *)v5 + 1) != v2->m_lChecksumOld )
  {
    if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_ModelLib, a2: 0) != 0 )
    {
      _LoggingSystem_Log(a1: LOG_ModelLib, a2: 0, a3: "ERROR: [StripHardwareVertsBuffer] checksum mismatch!\n");
      return 0;
    }
    return 0;
  }
  *((_DWORD *)v5 + 1) = v2->m_lChecksumNew;
  m_eMode = v2->m_eMode;
  switch ( m_eMode )
  {
    case 1:
      return 1;
    case 4:
      v7 = (unsigned int *)&v5[(28 * *((_DWORD *)v5 + 5) + 551) & 0xFFFFFE00];
      v8 = &v5[vhvLength];
      v9 = (unsigned __int8 *)(v7 + 1);
      if ( v7 + 1 <= (unsigned int *)v8 )
      {
        do
        {
          *v7 = *v7 & 0xFF00FF00 | ((unsigned __int8)*v7 << 16) | (unsigned __int8)BYTE2(*v7);
          v9 += 4;
          ++v7;
        }
        while ( v9 <= v8 );
      }
      return 1;
    case 2:
      CMemoryMovingTracker::CMemoryMovingTracker(this: &vhvRemove, ePolicy: MEMORY_REMOVE);
      v10 = -1;
      v11 = 40;
      numVerts = -1;
      vhvEndMeshOffset = 40;
      numMeshesRemoved = 0;
      iBatch = 0;
      j = 0;
      if ( *((int *)v5 + 5) > 0 )
      {
        v12 = 20 - (_DWORD)v5;
        v13 = (unsigned int *)(v5 + 48);
        for ( iMesh = 20 - (_DWORD)v5; ; v12 = iMesh )
        {
          v14 = *v13;
          if ( *v13 < v10 )
            numVerts = *v13;
          v15 = (unsigned int)v13 + v12;
          if ( v15 > v11 )
            vhvEndMeshOffset = v15;
          if ( *(v13 - 2) != 0 )
          {
            CMemoryMovingTracker::RegisterBytes(
              this: &vhvRemove,
              pos: &v5[v14],
              length: *(v13 - 1) * *((_DWORD *)v5 + 3));
            CMemoryMovingTracker::RegisterBytes(this: &vhvRemove, pos: (unsigned __int8 *)v13 - 8, length: 28);
            iBatch += *(v13 - 1);
            ++numMeshesRemoved;
          }
          v11 = vhvEndMeshOffset;
          v10 = numVerts;
          v13 += 7;
          if ( ++j >= *((_DWORD *)v5 + 5) )
            break;
        }
      }
      CMemoryMovingTracker::RegisterBytes(this: &vhvRemove, pos: &v5[v11], length: v10 - v11);
      v16 = *((_DWORD *)v5 + 4) * *((_DWORD *)v5 + 3);
      CMemoryMovingTracker::RegisterBytes(this: &vhvRemove, pos: &v5[v10 + v16], length: vhvLength - v16 - v10);
      CInsertionTracker::Finalize(this: (CMdlLib *)&vhvRemove);
      if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_ModelLib, a2: 0) != 0 )
      {
        NumBytesRegistered = CMemoryMovingTracker::GetNumBytesRegistered(this: &vhvRemove);
        _LoggingSystem_Log(a1: LOG_ModelLib, a2: 0, a3: " Stripped %d vhv bytes.\n", NumBytesRegistered);
      }
      v18 = CMemoryMovingTracker::ComputeOffset(this: &vhvRemove, ptrBase: v5, off: v10);
      v19 = (unsigned int)(v18 + 3) & 0xFFFFFFFC;
      v20 = *((_DWORD *)v5 + 5) <= 0;
      numVerts = (unsigned int)v18;
      j = 0;
      if ( !v20 )
      {
        iMesh = v19 - (_DWORD)v18;
        v21 = (int *)(v5 + 48);
        do
        {
          v22 = CMemoryMovingTracker::ComputeOffset(this: &vhvRemove, ptrBase: v5, off: *v21);
          v21 += 7;
          *(v21 - 7) = (int)&v22[iMesh];
          ++j;
        }
        while ( j < *((_DWORD *)v5 + 5) );
      }
      v23 = iBatch;
      *((_DWORD *)v5 + 5) -= numMeshesRemoved;
      *((_DWORD *)v5 + 4) -= v23;
      CMemoryMovingTracker::MemMove(this: &vhvRemove, ptrBase: v5, length: &vhvLength);
      v24 = v19 - numVerts;
      v25 = v19 - numVerts + vhvLength;
      memset(&v57.m_Put, 0, 12);
      v57.m_nOffset = 0;
      v57.m_Byteswap = 0;
      v57.m_Get = (int)CDefOps<unsigned char *>::LessFunc;
      v57.m_nMaxPut = -1;
      v57.m_GetOverflowFunc = (bool (__thiscall *)(CUtlBuffer *, int))-1;
      v57.m_PutOverflowFunc = (bool (__thiscall *)(CUtlBuffer *, int))-1;
      CInsertionTracker::InsertBytes(this: (CInsertionTracker *)&v57.m_Get, pos: &v5[numVerts], length: v24);
      CInsertionTracker::InsertBytes(
        this: (CInsertionTracker *)&v57.m_Get,
        pos: &v5[vhvLength],
        length: ((v25 + 3) & 0xFFFFFFFC) - v25);
      CInsertionTracker::Finalize(this: (CMdlLib *)&v57.m_Get);
      if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_ModelLib, a2: 0) != 0 )
      {
        NumBytesInserted = CInsertionTracker::GetNumBytesInserted(this: (CInsertionTracker *)&v57.m_Get);
        _LoggingSystem_Log(a1: LOG_ModelLib, a2: 0, a3: " Inserted %d alignment bytes.\n", NumBytesInserted);
      }
      CInsertionTracker::MemMove(
        this: (CInsertionTracker *)&v57.m_Get,
        ptrBase: (char *)v5,
        length: (unsigned __int8 *)&vhvLength);
      CUtlBuffer::SeekPut(
        this: (CUtlBuffer *)vhvBuffer,
        type: SEEK_CURRENT,
        offset: *(_DWORD *)(vhvBuffer + 12) + vhvLength - *(_DWORD *)(vhvBuffer + 16));
      if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_ModelLib, a2: 0) != 0 )
      {
        v27 = CInsertionTracker::GetNumBytesInserted(this: (CInsertionTracker *)&v57.m_Get);
        v28 = CMemoryMovingTracker::GetNumBytesRegistered(this: &vhvRemove);
        _LoggingSystem_Log(a1: LOG_ModelLib, a2: 0, a3: " Reduced vhv buffer by %d bytes.\n", v28 - v27);
      }
      CUtlRBTree<CUtlMap<unsigned char *,int,unsigned int>::Node_t,unsigned int,CUtlMap<unsigned char *,int,unsigned int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned char *,int,unsigned int>::Node_t,unsigned int>,unsigned int>>::~CUtlRBTree<CUtlMap<unsigned char *,int,unsigned int>::Node_t,unsigned int,CUtlMap<unsigned char *,int,unsigned int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned char *,int,unsigned int>::Node_t,unsigned int>,unsigned int>>(this: (CUtlRBTree<CUtlMap<unsigned char *,int,unsigned int>::Node_t,unsigned int,CUtlMap<unsigned char *,int,unsigned int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned char *,int,unsigned int>::Node_t,unsigned int>,unsigned int> > *)&v57.m_Get);
      CUtlRBTree<CUtlMap<unsigned char *,int,unsigned int>::Node_t,unsigned int,CUtlMap<unsigned char *,int,unsigned int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned char *,int,unsigned int>::Node_t,unsigned int>,unsigned int>>::~CUtlRBTree<CUtlMap<unsigned char *,int,unsigned int>::Node_t,unsigned int,CUtlMap<unsigned char *,int,unsigned int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned char *,int,unsigned int>::Node_t,unsigned int>,unsigned int>>(this: &vhvRemove.m_map.m_Tree);
      return 1;
    default:
      break;
  }
  if ( m_eMode != 3 )
    return 0;
  v29 = *((_DWORD *)v5 + 5);
  if ( v29 == 0 || v29 != v2->m_ps3studioStripGroupHeaderBatchOffset.m_Size )
  {
    if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_ModelLib, a2: 0) != 0 )
      _LoggingSystem_Log(
        a1: LOG_ModelLib,
        a2: 0,
        a3: " Mismatching vhv buffer mesh count( vhv=%d, vsi=%d ).\n",
        *((_DWORD *)v5 + 5),
        v2->m_ps3studioStripGroupHeaderBatchOffset.m_Size);
    return 0;
  }
  m_Size = v2->m_ps3studioBatches.m_Size;
  v31 = 0;
  iBatch = 0;
  if ( m_Size > 0 )
  {
    vhvEndMeshOffset = (unsigned int)v2->m_ps3studioBatches.m_Memory.m_pMemory;
    numVerts = m_Size;
    do
    {
      v32 = *(_DWORD ***)vhvEndMeshOffset;
      v33 = *(_DWORD *)(*(_DWORD *)vhvEndMeshOffset + 12);
      v34 = 0;
      v35 = 0;
      j = 0;
      if ( v33 >= 2 )
      {
        v36 = *v32;
        v37 = ((unsigned int)(v33 - 2) >> 1) + 1;
        j = 2 * v37;
        do
        {
          v34 += *(_DWORD *)(*v36 + 32);
          v35 += *(_DWORD *)(v36[1] + 32);
          v36 += 2;
          --v37;
        }
        while ( v37 != 0 );
        v2 = (CMdlStripInfo *)numMeshesRemoved;
      }
      if ( j >= *(_DWORD *)(*(_DWORD *)vhvEndMeshOffset + 12) )
        v38 = iBatch;
      else
        v38 = *(_DWORD *)(*(_DWORD *)(**(_DWORD **)vhvEndMeshOffset + 4 * j) + 32) + iBatch;
      vhvEndMeshOffset += 4;
      v31 = v35 + v34 + v38;
      v39 = numVerts-- == 1;
      iBatch = v31;
    }
    while ( !v39 );
  }
  j = (28 * *((_DWORD *)v5 + 5) + 551) & 0xFFFFFE00;
  v40 = (j + 4 * v31 + 511) & 0xFFFFFE00;
  CUtlBuffer::CUtlBuffer(this: &v57, growSize: 0, initSize: 0, nFlags: 0);
  v41 = vhvLength;
  if ( v40 > vhvLength )
    v41 = v40;
  CUtlBuffer::EnsureCapacity(this: &v57, num: v41);
  _V_memcpy(dest: v57.m_Memory.m_pMemory, src: v5, count: vhvLength);
  if ( *((_DWORD *)v5 + 12) == j && v40 >= vhvLength )
  {
    CUtlBuffer::EnsureCapacity(this: (CUtlBuffer *)vhvBuffer, num: v40 + *(_DWORD *)(vhvBuffer + 12));
    CUtlBuffer::SeekPut(this: (CUtlBuffer *)vhvBuffer, type: SEEK_CURRENT, offset: v40 - vhvLength);
    v42 = (HardwareVerts::FileHeader_t *)(*(_DWORD *)(vhvBuffer + 12) + *(_DWORD *)vhvBuffer);
    pVertDataSrc = (unsigned int *)&v57.m_Memory.m_pMemory[j];
    v43 = 0;
    v44 = (int)v42 + j;
    vhvHdr = v42;
    j += (int)v42;
    iMesh = 0;
    iBatch = 0;
    if ( v2->m_ps3studioStripGroupHeaderBatchOffset.m_Size != 0 )
    {
      vhvEndMeshOffset = (unsigned int)&v42[1].m_nChecksum;
      do
      {
        *(_DWORD *)(vhvEndMeshOffset + 4) = v44 - (_DWORD)v42;
        v45 = v2->m_ps3studioStripGroupHeaderBatchOffset.m_Size - 1;
        numVerts = 0;
        if ( v43 >= v45 )
          v46 = v2->m_ps3studioBatches.m_Size;
        else
          v46 = v2->m_ps3studioStripGroupHeaderBatchOffset.m_Memory.m_pMemory[v43 + 1];
        iBatchEnd = v46;
        if ( v46 >= v2->m_ps3studioBatches.m_Size )
          iBatchEnd = v2->m_ps3studioBatches.m_Size;
        for ( i = iBatch; i < iBatchEnd; iBatch = i )
        {
          v48 = v2->m_ps3studioBatches.m_Memory.m_pMemory[i];
          v49 = 0;
          iPartition = 0;
          if ( v48->m_arrPartitions.m_Size != 0 )
          {
            do
            {
              v50 = v48->m_arrPartitions.m_Memory.m_pMemory[v49];
              v51 = v50->m_arrVertOriginalIndices.m_Size;
              numVerts += v51;
              v52 = 0;
              if ( v51 != 0 )
              {
                do
                {
                  v53 = pVertDataSrc[v48->m_uiVhvIndexOffset
                                   + v50->m_arrStripLocalOriginalIndices.m_Memory.m_pMemory[v52]];
                  v54 = j;
                  *(_DWORD *)j = v53 & 0xFF00FF00 | ((unsigned __int8)v53 << 16) | BYTE2(v53);
                  v44 = v54 + 4;
                  ++v52;
                  j = v44;
                }
                while ( v52 < v50->m_arrVertOriginalIndices.m_Size );
                v49 = iPartition;
              }
              iPartition = ++v49;
            }
            while ( v49 < v48->m_arrPartitions.m_Size );
            v42 = vhvHdr;
            v43 = iMesh;
            i = iBatch;
          }
          v2 = (CMdlStripInfo *)numMeshesRemoved;
          ++i;
        }
        v55 = vhvEndMeshOffset;
        *(_DWORD *)vhvEndMeshOffset = numVerts;
        iMesh = ++v43;
        vhvEndMeshOffset = v55 + 28;
      }
      while ( v43 < v2->m_ps3studioStripGroupHeaderBatchOffset.m_Size );
    }
    CUtlBuffer::~CUtlBuffer(this: &v57);
    return 1;
  }
  if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_ModelLib, a2: 0) != 0 )
    _LoggingSystem_Log(a1: LOG_ModelLib, a2: 0, a3: " Unexpected vhv buffer mesh offset.\n");
  CUtlBuffer::~CUtlBuffer(this: &v57);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10007570
// Name: public: virtual bool CMdlStripInfo::StripOptimizedModelBuffer(class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CMdlStripInfo::StripOptimizedModelBuffer(CMdlStripInfo *this, CUtlBuffer *vtxBuffer)
{
  int m_Get; // edx
  OptimizedModel::FileHeader_t *v4; // edi
  int checkSum; // edx
  int m_eMode; // eax
  int v7; // edx
  int *v8; // esi
  char *v9; // ecx
  int v10; // eax
  bool v11; // cc
  int v12; // esi
  int v13; // edx
  OptimizedModel::ModelHeader_t *v14; // esi
  OptimizedModel::ModelLODHeader_t *v15; // eax
  OptimizedModel::ModelLODHeader_t *v16; // esi
  int *v17; // edi
  int v18; // esi
  int v19; // edx
  int v20; // ecx
  char *v21; // esi
  int v22; // ebx
  OptimizedModel::ModelHeader_t *v23; // esi
  OptimizedModel::ModelLODHeader_t *v24; // edx
  OptimizedModel::FileHeader_t *v25; // ebx
  OptimizedModel::Vertex_t *v26; // eax
  int v27; // ecx
  OptimizedModel::MeshHeader_t *v28; // ecx
  int v29; // eax
  _DWORD *v30; // eax
  int v31; // edi
  int v32; // esi
  int v33; // ecx
  unsigned int v34; // esi
  unsigned int v35; // edx
  unsigned int v36; // edi
  int m_Size; // ebx
  int v38; // ebx
  unsigned int *v39; // eax
  int v40; // esi
  int v41; // ebx
  unsigned int *v42; // eax
  int v43; // esi
  int v44; // ebx
  unsigned int *m_pMemory; // edi
  int v46; // esi
  unsigned int *v47; // eax
  int v48; // ebx
  int v49; // esi
  unsigned int *v50; // eax
  OptimizedModel::FileHeader_t *v51; // ecx
  char *v52; // edi
  unsigned int v53; // ebx
  int v54; // esi
  int v55; // eax
  void *(__thiscall *Alloc_2)(IMemAlloc *, unsigned int); // edx
  int *v57; // eax
  char *v58; // edx
  int v59; // eax
  int v60; // edi
  int *v61; // ebx
  int *v62; // edi
  CUtlSortVector<CMdlStripInfo::MdlRangeItem,CLessSimple<CMdlStripInfo::MdlRangeItem> > *v63; // edi
  int LessOrEqual; // eax
  OptimizedModel::ModelHeader_t *v65; // ebx
  CMdlStripInfo::MdlRangeItem *v66; // edi
  int v67; // edi
  int *v68; // ebx
  unsigned int *v69; // edi
  unsigned __int8 *v70; // edi
  unsigned int *v71; // ebx
  unsigned int v72; // esi
  int v73; // eax
  int NumBytesRegistered; // eax
  char *v75; // edi
  int v76; // ebx
  unsigned int v77; // esi
  int v78; // eax
  char *v79; // esi
  char *v80; // eax
  char *v81; // eax
  OptimizedModel::FileHeader_t *v82; // edx
  CUtlSortVector<CMdlStripInfo::MdlRangeItem,CLessSimple<CMdlStripInfo::MdlRangeItem> > *v83; // ebx
  int v84; // edi
  unsigned __int16 *v85; // edi
  unsigned int v86; // esi
  char *v87; // esi
  unsigned int v88; // edi
  int v89; // edi
  char *v90; // ebx
  char *v91; // ebx
  char *v92; // eax
  char *v93; // eax
  char *v94; // eax
  char *v95; // eax
  char *v96; // eax
  _DWORD *v97; // ecx
  _DWORD *v98; // esi
  char *v99; // eax
  int *v100; // ecx
  int v101; // eax
  int v102; // esi
  char *v103; // eax
  OptimizedModel::FileHeader_t *v104; // ecx
  OptimizedModel::FileHeader_t *v105; // esi
  UtlRBTreeNode_t<CUtlMap<unsigned char *,int,unsigned int>::Node_t,unsigned int> *v106; // eax
  unsigned __int8 *v107; // [esp-10h] [ebp-ECh]
  int v108; // [esp-Ch] [ebp-E8h]
  int v109; // [esp-Ch] [ebp-E8h]
  int v110; // [esp-Ch] [ebp-E8h]
  CMdlStripInfo::MdlRangeItem src; // [esp+4h] [ebp-D8h] BYREF
  int vtxLength; // [esp+14h] [ebp-C8h] BYREF
  CMemoryMovingTracker vtxRemove; // [esp+18h] [ebp-C4h] BYREF
  CUtlSortVector<CMdlStripInfo::MdlRangeItem,CLessSimple<CMdlStripInfo::MdlRangeItem> > *arrMdlOffsets; // [esp+4Ch] [ebp-90h]
  OptimizedModel::MeshHeader_t *vtxMesh; // [esp+50h] [ebp-8Ch]
  CUtlVector<unsigned int,CUtlMemory<unsigned int,int> > vtxOffVertex; // [esp+54h] [ebp-88h] BYREF
  CUtlVector<int,CUtlMemory<int,int> > vtxIndexDeltas; // [esp+68h] [ebp-74h] BYREF
  CUtlVector<unsigned int,CUtlMemory<unsigned int,int> > vtxOffIndex; // [esp+7Ch] [ebp-60h] BYREF
  unsigned __int16 *vtxIndexBufferEnd; // [esp+90h] [ebp-4Ch]
  OptimizedModel::Vertex_t *vtxVertexBufferEnd; // [esp+94h] [ebp-48h]
  int v121; // [esp+98h] [ebp-44h]
  int v122; // [esp+9Ch] [ebp-40h]
  unsigned int vtxOffVertexBuffer; // [esp+A0h] [ebp-3Ch]
  int vtxModel_idx; // [esp+A4h] [ebp-38h]
  int vtxStripGroup_idx; // [esp+A8h] [ebp-34h]
  unsigned int offVertexEnd; // [esp+ACh] [ebp-30h]
  int vtxMesh_idx; // [esp+B0h] [ebp-2Ch]
  unsigned int offVertex; // [esp+B4h] [ebp-28h] BYREF
  int vtxStrip_idx; // [esp+B8h] [ebp-24h]
  OptimizedModel::ModelLODHeader_t *vtxLod; // [esp+BCh] [ebp-20h]
  int vtxBodyPart_idx; // [esp+C0h] [ebp-1Ch]
  unsigned int vtxOffVertexBufferEnd; // [esp+C4h] [ebp-18h]
  int vtxMatList_idx; // [esp+C8h] [ebp-14h]
  int v134; // [esp+CCh] [ebp-10h]
  unsigned int vtxOffIndexBuffer; // [esp+D0h] [ebp-Ch]
  OptimizedModel::ModelHeader_t *vtxModel; // [esp+D4h] [ebp-8h]
  OptimizedModel::FileHeader_t *vtxHdr; // [esp+D8h] [ebp-4h]

  if ( this->m_eMode == 0 )
    return 0;
  m_Get = vtxBuffer->m_Get;
  v4 = (OptimizedModel::FileHeader_t *)&vtxBuffer->m_Memory.m_pMemory[m_Get];
  vtxLength = vtxBuffer->m_Put - m_Get;
  checkSum = v4->checkSum;
  vtxHdr = v4;
  if ( checkSum != this->m_lChecksumOld )
  {
    if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_ModelLib, a2: 0) != 0 )
      _LoggingSystem_Log(a1: LOG_ModelLib, a2: 0, a3: "ERROR: [StripOptimizedModelBuffer] checksum mismatch!\n");
    return 0;
  }
  v4->checkSum = this->m_lChecksumNew;
  m_eMode = this->m_eMode;
  if ( m_eMode != 1 )
  {
    if ( m_eMode != 2 )
      return 0;
    vtxIndexBufferEnd = (unsigned __int16 *)&this->m_vtxIndices;
    arrMdlOffsets = &this->m_vtxMdlOffsets;
    vtxRemove.m_map.m_Tree.m_LessFunc.m_LessFunc = (bool (__cdecl *)(unsigned __int8 *const *, unsigned __int8 *const *))CDefOps<unsigned char *>::LessFunc;
    memset(&vtxRemove.m_map.m_Tree.m_Elements, 0, sizeof(vtxRemove.m_map.m_Tree.m_Elements));
    vtxRemove.m_map.m_Tree.m_Root = -1;
    vtxRemove.m_map.m_Tree.m_NumElements = 0;
    vtxRemove.m_map.m_Tree.m_FirstFree = -1;
    vtxRemove.m_map.m_Tree.m_LastAlloc.index = -1;
    vtxRemove.m_map.m_Tree.m_pElements = nullptr;
    vtxRemove.m_ePolicy = MEMORY_REMOVE;
    v7 = 8 * v4->numLODs - 8;
    vtxOffIndexBuffer = -1;
    vtxOffVertexBuffer = -1;
    v107 = (unsigned __int8 *)&v4->maxBonesPerStrip + v4->materialReplacementListOffset;
    vtxMatList_idx = 0;
    vtxOffVertexBufferEnd = 0;
    memset(&vtxOffIndex, 0, sizeof(vtxOffIndex));
    memset(&vtxOffVertex, 0, sizeof(vtxOffVertex));
    CMemoryMovingTracker::RegisterBytes(this: &vtxRemove, pos: v107, length: v7);
    for ( offVertexEnd = 0; (signed int)offVertexEnd < v4->numLODs; ++offVertexEnd )
    {
      v8 = (int *)((char *)&v4->version + 8 * offVertexEnd + v4->materialReplacementListOffset);
      if ( offVertexEnd != 0 )
      {
        CMemoryMovingTracker::RegisterBytes(this: &vtxRemove, pos: (unsigned __int8 *)v8 + v8[1], length: 6 * *v8);
        vtxBodyPart_idx = 0;
        if ( *v8 > 0 )
        {
          vtxModel = nullptr;
          do
          {
            v9 = (char *)vtxModel + (_DWORD)v8 + v8[1] + *(int *)((char *)&vtxModel->numLODs + (_DWORD)v8 + v8[1] + 2);
            if ( v9 != nullptr )
            {
              vtxStrip_idx = (int)(v9 + 1);
              v10 = strlen(v9) + 1;
            }
            else
            {
              v10 = 0;
            }
            CMemoryMovingTracker::RegisterBytes(this: &vtxRemove, pos: (unsigned __int8 *)v9, length: v10);
            vtxModel = (OptimizedModel::ModelHeader_t *)((char *)vtxModel + 6);
            ++vtxBodyPart_idx;
          }
          while ( vtxBodyPart_idx < *v8 );
        }
      }
    }
    vtxBodyPart_idx = 0;
    if ( v4->numBodyParts > 0 )
    {
      do
      {
        v11 = *(int *)((char *)&vtxHdr->version + 8 * vtxBodyPart_idx + vtxHdr->bodyPartOffset) <= 0;
        vtxStrip_idx = (int)vtxHdr + 8 * vtxBodyPart_idx + vtxHdr->bodyPartOffset;
        vtxModel_idx = 0;
        if ( !v11 )
        {
          do
          {
            v12 = *(_DWORD *)(vtxStrip_idx + 4) + 8 * vtxModel_idx;
            v13 = *(_DWORD *)(v12 + vtxStrip_idx + 4);
            v14 = (OptimizedModel::ModelHeader_t *)(vtxStrip_idx + v12);
            v108 = 12 * v14->numLODs - 12;
            vtxModel = v14;
            CMemoryMovingTracker::RegisterBytes(
              this: &vtxRemove,
              pos: (unsigned __int8 *)&v14[1].lodOffset + v13,
              length: v108);
            v11 = v14->numLODs <= 0;
            vtxMesh_idx = 0;
            if ( !v11 )
            {
              v134 = 0;
              do
              {
                v15 = (OptimizedModel::ModelLODHeader_t *)((char *)vtxModel + v134 + vtxModel->lodOffset);
                vtxLod = v15;
                if ( vtxMesh_idx != 0 )
                {
                  v16 = v15;
                  CMemoryMovingTracker::RegisterBytes(
                    this: &vtxRemove,
                    pos: (unsigned __int8 *)v16 + v16->meshOffset,
                    length: 9 * v15->numMeshes);
                  v11 = v16->numMeshes <= 0;
                  offVertex = 0;
                  if ( !v11 )
                  {
                    v121 = 0;
                    do
                    {
                      v17 = (int *)((char *)&vtxLod->numMeshes + v121 + vtxLod->meshOffset);
                      CMemoryMovingTracker::RegisterBytes(
                        this: &vtxRemove,
                        pos: (unsigned __int8 *)v17 + v17[1],
                        length: 33 * *v17);
                      v11 = *v17 <= 0;
                      vtxStripGroup_idx = 0;
                      if ( !v11 )
                      {
                        v122 = 0;
                        do
                        {
                          v18 = v122 + v17[1];
                          v19 = *(int *)((char *)v17 + v18 + 20);
                          v20 = 35 * *(int *)((char *)v17 + v18 + 16);
                          v21 = (char *)v17 + v18;
                          CMemoryMovingTracker::RegisterBytes(
                            this: &vtxRemove,
                            pos: (unsigned __int8 *)&v21[v19],
                            length: v20);
                          v22 = 0;
                          if ( *((int *)v21 + 4) > 0 )
                          {
                            offVertexEnd = 0;
                            do
                            {
                              CMemoryMovingTracker::RegisterBytes(
                                this: &vtxRemove,
                                pos: (unsigned __int8 *)&v21[offVertexEnd
                                                      + *((_DWORD *)v21 + 5)
                                                      + *(_DWORD *)&v21[offVertexEnd + 23 + *((_DWORD *)v21 + 5)]],
                                length: 8 * *(_DWORD *)&v21[offVertexEnd + 19 + *((_DWORD *)v21 + 5)]);
                              offVertexEnd += 35;
                              ++v22;
                            }
                            while ( v22 < *((_DWORD *)v21 + 4) );
                          }
                          v122 += 33;
                          ++vtxStripGroup_idx;
                        }
                        while ( vtxStripGroup_idx < *v17 );
                      }
                      v121 += 9;
                      ++offVertex;
                    }
                    while ( (signed int)offVertex < vtxLod->numMeshes );
                  }
                }
                v134 += 12;
                ++vtxMesh_idx;
              }
              while ( vtxMesh_idx < vtxModel->numLODs );
            }
            v23 = vtxModel;
            v24 = nullptr;
            vtxLod = nullptr;
            if ( vtxModel->numLODs > 0 )
            {
              v25 = vtxHdr;
              do
              {
                v26 = (OptimizedModel::Vertex_t *)((char *)v23 + 12 * (_DWORD)v24 + v23->lodOffset);
                vtxVertexBufferEnd = v26;
                v122 = 0;
                if ( *(int *)v26->boneWeightIndex > 0 )
                {
                  vtxMesh_idx = 0;
                  do
                  {
                    v27 = vtxMesh_idx + *(_DWORD *)&v26->origMeshVertID;
                    vtxStripGroup_idx = 0;
                    v28 = (OptimizedModel::MeshHeader_t *)&v26->boneWeightIndex[v27];
                    v11 = v28->numStripGroups <= 0;
                    vtxMesh = v28;
                    if ( !v11 )
                    {
                      v29 = 0;
                      v121 = 0;
                      do
                      {
                        v30 = (int *)((char *)&v28->numStripGroups + v29 + v28->stripGroupHeaderOffset);
                        v31 = v30[3] + 2 * v30[2] - (_DWORD)v25;
                        v32 = v30[3];
                        v33 = v30[1];
                        offVertex = (unsigned int)v30 + v33 - (_DWORD)v25;
                        v34 = (unsigned int)v30 + v32 - (_DWORD)v25;
                        v35 = (unsigned int)v30 + v33 + 9 * *v30 - (_DWORD)v25;
                        v36 = (unsigned int)v30 + v31;
                        offVertexEnd = v35;
                        if ( v34 < vtxOffIndexBuffer )
                          vtxOffIndexBuffer = v34;
                        if ( v36 > vtxMatList_idx )
                          vtxMatList_idx = v36;
                        if ( offVertex < vtxOffVertexBuffer )
                          vtxOffVertexBuffer = offVertex;
                        if ( v35 > vtxOffVertexBufferEnd )
                          vtxOffVertexBufferEnd = v35;
                        if ( vtxLod == nullptr )
                        {
                          m_Size = vtxOffIndex.m_Size;
                          v134 = vtxOffIndex.m_Size;
                          if ( vtxOffIndex.m_Size + 1 > vtxOffIndex.m_Memory.m_nAllocationCount )
                          {
                            CUtlMemory<int,int>::Grow(
                              this: (CUtlMemory<OptimizedModel::OptimizedIndexBufferMarkupPs3_t *,int> *)&vtxOffIndex,
                              num: vtxOffIndex.m_Size - vtxOffIndex.m_Memory.m_nAllocationCount + 1);
                            m_Size = vtxOffIndex.m_Size;
                          }
                          v38 = m_Size + 1;
                          vtxOffIndex.m_Size = v38;
                          vtxOffIndex.m_pElements = vtxOffIndex.m_Memory.m_pMemory;
                          if ( v38 - v134 - 1 > 0 )
                            _V_memmove(
                              dest: &vtxOffIndex.m_Memory.m_pMemory[v134 + 1],
                              src: &vtxOffIndex.m_Memory.m_pMemory[v134],
                              count: 4 * (v38 - v134 - 1));
                          v39 = &vtxOffIndex.m_Memory.m_pMemory[v134];
                          if ( v39 != nullptr )
                            *v39 = v34;
                          v40 = v38;
                          if ( v38 + 1 > vtxOffIndex.m_Memory.m_nAllocationCount )
                          {
                            CUtlMemory<int,int>::Grow(
                              this: (CUtlMemory<OptimizedModel::OptimizedIndexBufferMarkupPs3_t *,int> *)&vtxOffIndex,
                              num: v38 - vtxOffIndex.m_Memory.m_nAllocationCount + 1);
                            v38 = vtxOffIndex.m_Size;
                          }
                          v41 = v38 + 1;
                          vtxOffIndex.m_Size = v41;
                          vtxOffIndex.m_pElements = vtxOffIndex.m_Memory.m_pMemory;
                          if ( v41 - v40 - 1 > 0 )
                            _V_memmove(
                              dest: &vtxOffIndex.m_Memory.m_pMemory[v40 + 1],
                              src: &vtxOffIndex.m_Memory.m_pMemory[v40],
                              count: 4 * (v41 - v40 - 1));
                          v42 = &vtxOffIndex.m_Memory.m_pMemory[v40];
                          if ( v42 != nullptr )
                            *v42 = v36;
                          v43 = vtxOffVertex.m_Size;
                          v44 = vtxOffVertex.m_Size;
                          if ( vtxOffVertex.m_Size + 1 > vtxOffVertex.m_Memory.m_nAllocationCount )
                          {
                            CUtlMemory<int,int>::Grow(
                              this: (CUtlMemory<OptimizedModel::OptimizedIndexBufferMarkupPs3_t *,int> *)&vtxOffVertex,
                              num: vtxOffVertex.m_Size - vtxOffVertex.m_Memory.m_nAllocationCount + 1);
                            v43 = vtxOffVertex.m_Size;
                          }
                          m_pMemory = vtxOffVertex.m_Memory.m_pMemory;
                          v46 = v43 + 1;
                          vtxOffVertex.m_Size = v46;
                          vtxOffVertex.m_pElements = vtxOffVertex.m_Memory.m_pMemory;
                          if ( v46 - v44 - 1 > 0 )
                            _V_memmove(
                              dest: &vtxOffVertex.m_Memory.m_pMemory[v44 + 1],
                              src: &vtxOffVertex.m_Memory.m_pMemory[v44],
                              count: 4 * (v46 - v44 - 1));
                          v47 = &m_pMemory[v44];
                          if ( v47 != nullptr )
                            *v47 = offVertex;
                          v48 = v46;
                          if ( v46 + 1 > vtxOffVertex.m_Memory.m_nAllocationCount )
                          {
                            CUtlMemory<int,int>::Grow(
                              this: (CUtlMemory<OptimizedModel::OptimizedIndexBufferMarkupPs3_t *,int> *)&vtxOffVertex,
                              num: v46 - vtxOffVertex.m_Memory.m_nAllocationCount + 1);
                            v46 = vtxOffVertex.m_Size;
                            m_pMemory = vtxOffVertex.m_Memory.m_pMemory;
                          }
                          v49 = v46 + 1;
                          vtxOffVertex.m_Size = v49;
                          vtxOffVertex.m_pElements = m_pMemory;
                          if ( v49 - v48 - 1 > 0 )
                            _V_memmove(dest: &m_pMemory[v48 + 1], src: &m_pMemory[v48], count: 4 * (v49 - v48 - 1));
                          v50 = &m_pMemory[v48];
                          if ( v50 != nullptr )
                            *v50 = offVertexEnd;
                        }
                        v28 = vtxMesh;
                        v25 = vtxHdr;
                        v29 = v121 + 33;
                        ++vtxStripGroup_idx;
                        v121 += 33;
                      }
                      while ( vtxStripGroup_idx < vtxMesh->numStripGroups );
                      v26 = vtxVertexBufferEnd;
                      v23 = vtxModel;
                      v24 = vtxLod;
                    }
                    vtxMesh_idx += 9;
                    ++v122;
                  }
                  while ( v122 < *(_DWORD *)v26->boneWeightIndex );
                }
                v24 = (OptimizedModel::ModelLODHeader_t *)((char *)v24 + 1);
                vtxLod = v24;
              }
              while ( (int)v24 < v23->numLODs );
            }
            ++vtxModel_idx;
          }
          while ( vtxModel_idx < *(_DWORD *)vtxStrip_idx );
        }
        ++vtxBodyPart_idx;
      }
      while ( vtxBodyPart_idx < vtxHdr->numBodyParts );
    }
    v51 = vtxHdr;
    v52 = (char *)vtxHdr + vtxOffVertexBuffer;
    vtxVertexBufferEnd = (OptimizedModel::Vertex_t *)((char *)vtxHdr + vtxOffVertexBufferEnd);
    v53 = vtxOffVertexBufferEnd - vtxOffVertexBuffer;
    v54 = 0;
    v55 = (int)(vtxOffVertexBufferEnd - vtxOffVertexBuffer) / 9;
    memset(&vtxIndexDeltas, 0, 16);
    if ( v55 > 0 )
    {
      Alloc_2 = _g_pMemAlloc->Alloc_2;
      vtxIndexDeltas.m_Memory.m_nAllocationCount = (int)(vtxOffVertexBufferEnd - vtxOffVertexBuffer) / 9;
      v57 = (int *)Alloc_2(this: _g_pMemAlloc, a2: 4 * v55);
      v51 = vtxHdr;
      vtxIndexDeltas.m_Memory.m_pMemory = v57;
    }
    vtxIndexDeltas.m_pElements = vtxIndexDeltas.m_Memory.m_pMemory;
    vtxOffVertexBufferEnd = 0;
    if ( v52 < (char *)vtxVertexBufferEnd )
    {
      vtxMesh = (OptimizedModel::MeshHeader_t *)(v52 - (char *)v51);
      vtxVertexBufferEnd = (OptimizedModel::Vertex_t *)(-4 - (_DWORD)v52);
      vtxModel = (OptimizedModel::ModelHeader_t *)(v52 + 4);
      vtxStrip_idx = (v53 - 1) / 9 + 1;
      do
      {
        v58 = (char *)vtxModel + (_DWORD)vtxVertexBufferEnd + (unsigned int)vtxMesh;
        v59 = 0;
        if ( vtxOffVertex.m_Size <= 0 )
        {
LABEL_86:
          CMemoryMovingTracker::RegisterBytes(
            this: &vtxRemove,
            pos: (unsigned __int8 *)&vtxModel[-1].lodOffset,
            length: 9);
          v60 = v54;
          if ( v54 + 1 > vtxIndexDeltas.m_Memory.m_nAllocationCount )
          {
            CUtlMemory<int,int>::Grow(
              this: (CUtlMemory<OptimizedModel::OptimizedIndexBufferMarkupPs3_t *,int> *)&vtxIndexDeltas,
              num: v54 - vtxIndexDeltas.m_Memory.m_nAllocationCount + 1);
            v54 = vtxIndexDeltas.m_Size;
          }
          v61 = vtxIndexDeltas.m_Memory.m_pMemory;
          vtxIndexDeltas.m_Size = ++v54;
          vtxIndexDeltas.m_pElements = vtxIndexDeltas.m_Memory.m_pMemory;
          if ( v54 - v60 - 1 > 0 )
            _V_memmove(
              dest: &vtxIndexDeltas.m_Memory.m_pMemory[v60 + 1],
              src: &vtxIndexDeltas.m_Memory.m_pMemory[v60],
              count: 4 * (v54 - v60 - 1));
          v62 = &v61[v60];
          if ( v62 != nullptr )
            *v62 = 0;
          ++vtxOffVertexBufferEnd;
        }
        else
        {
          while ( (unsigned int)v58 < vtxOffVertex.m_Memory.m_pMemory[v59]
               || (unsigned int)v58 >= vtxOffVertex.m_Memory.m_pMemory[v59 + 1] )
          {
            v59 += 2;
            if ( v59 >= vtxOffVertex.m_Size )
              goto LABEL_86;
          }
          src.m_offOld = 0;
          src.m_numOld = 0;
          src.m_numNew = 0;
          v63 = arrMdlOffsets;
          src.m_offNew = ((int)vtxModel + (int)vtxVertexBufferEnd) / 9;
          LessOrEqual = CUtlSortVector<CMdlStripInfo::MdlRangeItem,CLessSimple<CMdlStripInfo::MdlRangeItem>>::FindLessOrEqual(
                          this: arrMdlOffsets,
                          &src);
          v65 = vtxModel;
          v66 = &v63->m_Memory.m_pMemory[LessOrEqual];
          offVertex = (unsigned __int16)(LOWORD(vtxModel->numLODs) + LOWORD(v66->m_offOld));
          LOWORD(v65->numLODs) = CUtlSortVector<unsigned short,CLessSimple<unsigned short>>::Find(
                                   this: (CUtlSortVector<unsigned short,CLessSimple<unsigned short> > *)vtxIndexBufferEnd,
                                   src: (const unsigned __int16 *)&offVertex)
                               - LOWORD(v66->m_offNew);
          v67 = v54;
          if ( v54 + 1 > vtxIndexDeltas.m_Memory.m_nAllocationCount )
          {
            CUtlMemory<int,int>::Grow(
              this: (CUtlMemory<OptimizedModel::OptimizedIndexBufferMarkupPs3_t *,int> *)&vtxIndexDeltas,
              num: v54 - vtxIndexDeltas.m_Memory.m_nAllocationCount + 1);
            v54 = vtxIndexDeltas.m_Size;
          }
          v68 = vtxIndexDeltas.m_Memory.m_pMemory;
          vtxIndexDeltas.m_Size = ++v54;
          vtxIndexDeltas.m_pElements = vtxIndexDeltas.m_Memory.m_pMemory;
          if ( v54 - v67 - 1 > 0 )
            _V_memmove(
              dest: &vtxIndexDeltas.m_Memory.m_pMemory[v67 + 1],
              src: &vtxIndexDeltas.m_Memory.m_pMemory[v67],
              count: 4 * (v54 - v67 - 1));
          v69 = (unsigned int *)&v68[v67];
          if ( v69 != nullptr )
            *v69 = vtxOffVertexBufferEnd;
        }
        vtxModel = (OptimizedModel::ModelHeader_t *)((char *)vtxModel + 9);
        --vtxStrip_idx;
      }
      while ( vtxStrip_idx != 0 );
      v51 = vtxHdr;
    }
    v70 = (unsigned __int8 *)v51 + vtxOffIndexBuffer;
    vtxIndexBufferEnd = (unsigned __int16 *)((char *)v51 + vtxMatList_idx);
    if ( (char *)v51 + vtxOffIndexBuffer < (char *)v51 + vtxMatList_idx )
    {
      v71 = vtxOffIndex.m_Memory.m_pMemory;
      v72 = v70 - (unsigned __int8 *)vtxHdr;
      do
      {
        v73 = 0;
        if ( vtxOffIndex.m_Size <= 0 )
        {
LABEL_107:
          CMemoryMovingTracker::RegisterBytes(this: &vtxRemove, pos: v70, length: 2);
        }
        else
        {
          while ( v72 < v71[v73] || v72 >= v71[v73 + 1] )
          {
            v73 += 2;
            if ( v73 >= vtxOffIndex.m_Size )
              goto LABEL_107;
          }
          *(_WORD *)v70 -= LOWORD(vtxIndexDeltas.m_Memory.m_pMemory[*(unsigned __int16 *)v70]);
        }
        v70 += 2;
        v72 += 2;
      }
      while ( v70 < (unsigned __int8 *)vtxIndexBufferEnd );
    }
    CInsertionTracker::Finalize(this: (CMdlLib *)&vtxRemove);
    if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_ModelLib, a2: 0) != 0 )
    {
      NumBytesRegistered = CMemoryMovingTracker::GetNumBytesRegistered(this: &vtxRemove);
      _LoggingSystem_Log(a1: LOG_ModelLib, a2: 0, a3: " Stripped %d vtx bytes.\n", NumBytesRegistered);
    }
    v11 = vtxHdr->numLODs <= 0;
    vtxMatList_idx = 0;
    if ( !v11 )
    {
      do
      {
        v75 = (char *)vtxHdr + 8 * vtxMatList_idx + vtxHdr->materialReplacementListOffset;
        v76 = 0;
        if ( *(int *)v75 > 0 )
        {
          vtxOffIndexBuffer = 0;
          do
          {
            v77 = vtxOffIndexBuffer + *((_DWORD *)v75 + 1);
            v78 = *(_DWORD *)&v75[v77 + 2];
            v79 = &v75[v77];
            v80 = CMemoryMovingTracker::ComputeOffset(this: &vtxRemove, ptrBase: (unsigned __int8 *)v79, off: v78);
            vtxOffIndexBuffer += 6;
            ++v76;
            *(_DWORD *)(v79 + 2) = v80;
          }
          while ( v76 < *(_DWORD *)v75 );
        }
        v81 = CMemoryMovingTracker::ComputeOffset(
                this: &vtxRemove,
                ptrBase: (unsigned __int8 *)v75,
                off: *((_DWORD *)v75 + 1));
        v82 = vtxHdr;
        *((_DWORD *)v75 + 1) = v81;
        ++vtxMatList_idx;
      }
      while ( vtxMatList_idx < v82->numLODs );
    }
    v11 = vtxHdr->numBodyParts <= 0;
    v134 = 0;
    if ( !v11 )
    {
      do
      {
        v11 = *(int *)((char *)&vtxHdr->version + 8 * v134 + vtxHdr->bodyPartOffset) <= 0;
        vtxModel_idx = (int)vtxHdr + 8 * v134 + vtxHdr->bodyPartOffset;
        vtxBodyPart_idx = 0;
        if ( !v11 )
        {
          do
          {
            v11 = *(_DWORD *)(vtxModel_idx + *(_DWORD *)(vtxModel_idx + 4) + 8 * vtxBodyPart_idx) <= 0;
            vtxOffVertexBuffer = vtxModel_idx + *(_DWORD *)(vtxModel_idx + 4) + 8 * vtxBodyPart_idx;
            vtxLod = nullptr;
            if ( !v11 )
            {
              vtxOffVertexBufferEnd = 0;
              do
              {
                v83 = (CUtlSortVector<CMdlStripInfo::MdlRangeItem,CLessSimple<CMdlStripInfo::MdlRangeItem> > *)(*(_DWORD *)(vtxOffVertexBuffer + 4) + vtxOffVertexBuffer + vtxOffVertexBufferEnd);
                vtxMesh_idx = 0;
                v11 = (int)v83->m_Memory.m_pMemory <= 0;
                arrMdlOffsets = v83;
                if ( !v11 )
                {
                  vtxMatList_idx = 0;
                  do
                  {
                    v84 = vtxMatList_idx + v83->m_Memory.m_nAllocationCount;
                    vtxStripGroup_idx = 0;
                    v85 = (unsigned __int16 *)((char *)v83 + v84);
                    v11 = *(_DWORD *)v85 <= 0;
                    vtxIndexBufferEnd = v85;
                    if ( !v11 )
                    {
                      vtxOffIndexBuffer = 0;
                      do
                      {
                        v86 = vtxOffIndexBuffer + *((_DWORD *)v85 + 1);
                        vtxStrip_idx = 0;
                        v87 = (char *)v85 + v86;
                        if ( *((int *)v87 + 4) > 0 )
                        {
                          v88 = 0;
                          offVertex = 0;
                          do
                          {
                            v89 = (int)&v87[v88 + *((_DWORD *)v87 + 5)];
                            v90 = CMemoryMovingTracker::ComputeOffset(
                                    this: &vtxRemove,
                                    ptrBase: (unsigned __int8 *)v87,
                                    off: *(_DWORD *)(v89 + 4) + *((_DWORD *)v87 + 3));
                            *(_DWORD *)(v89 + 4) = v90
                                                 - CMemoryMovingTracker::ComputeOffset(
                                                     this: &vtxRemove,
                                                     ptrBase: (unsigned __int8 *)v87,
                                                     off: *((_DWORD *)v87 + 3));
                            v91 = CMemoryMovingTracker::ComputeOffset(
                                    this: &vtxRemove,
                                    ptrBase: (unsigned __int8 *)v87,
                                    off: *(_DWORD *)(v89 + 12) + *((_DWORD *)v87 + 1));
                            v92 = CMemoryMovingTracker::ComputeOffset(
                                    this: &vtxRemove,
                                    ptrBase: (unsigned __int8 *)v87,
                                    off: *((_DWORD *)v87 + 1));
                            v109 = *(_DWORD *)(v89 + 23);
                            *(_DWORD *)(v89 + 12) = v91 - v92;
                            *(_DWORD *)(v89 + 23) = CMemoryMovingTracker::ComputeOffset(
                                                      this: &vtxRemove,
                                                      ptrBase: (unsigned __int8 *)v89,
                                                      off: v109);
                            v88 = offVertex + 35;
                            ++vtxStrip_idx;
                            offVertex += 35;
                          }
                          while ( vtxStrip_idx < *((_DWORD *)v87 + 4) );
                          v85 = vtxIndexBufferEnd;
                          v83 = arrMdlOffsets;
                        }
                        v93 = CMemoryMovingTracker::ComputeOffset(
                                this: &vtxRemove,
                                ptrBase: (unsigned __int8 *)v87,
                                off: *((_DWORD *)v87 + 1));
                        v110 = *((_DWORD *)v87 + 3);
                        *((_DWORD *)v87 + 1) = v93;
                        *((_DWORD *)v87 + 3) = CMemoryMovingTracker::ComputeOffset(
                                                 this: &vtxRemove,
                                                 ptrBase: (unsigned __int8 *)v87,
                                                 off: v110);
                        v94 = CMemoryMovingTracker::ComputeOffset(
                                this: &vtxRemove,
                                ptrBase: (unsigned __int8 *)v87,
                                off: *((_DWORD *)v87 + 5));
                        vtxOffIndexBuffer += 33;
                        *((_DWORD *)v87 + 5) = v94;
                        ++vtxStripGroup_idx;
                      }
                      while ( vtxStripGroup_idx < *(_DWORD *)v85 );
                    }
                    v95 = CMemoryMovingTracker::ComputeOffset(
                            this: &vtxRemove,
                            ptrBase: (unsigned __int8 *)v85,
                            off: *((_DWORD *)v85 + 1));
                    vtxMatList_idx += 9;
                    *((_DWORD *)v85 + 1) = v95;
                    ++vtxMesh_idx;
                  }
                  while ( vtxMesh_idx < (int)v83->m_Memory.m_pMemory );
                }
                v96 = CMemoryMovingTracker::ComputeOffset(
                        this: &vtxRemove,
                        ptrBase: (unsigned __int8 *)v83,
                        off: v83->m_Memory.m_nAllocationCount);
                v97 = (_DWORD *)vtxOffVertexBuffer;
                vtxOffVertexBufferEnd += 12;
                v83->m_Memory.m_nAllocationCount = (int)v96;
                vtxLod = (OptimizedModel::ModelLODHeader_t *)((char *)vtxLod + 1);
              }
              while ( (int)vtxLod < *v97 );
            }
            v98 = (_DWORD *)vtxOffVertexBuffer;
            v99 = CMemoryMovingTracker::ComputeOffset(
                    this: &vtxRemove,
                    ptrBase: (unsigned __int8 *)vtxOffVertexBuffer,
                    off: *(_DWORD *)(vtxOffVertexBuffer + 4));
            v100 = (int *)vtxModel_idx;
            v98[1] = v99;
            v101 = vtxBodyPart_idx + 1;
            *v98 = 1;
            vtxBodyPart_idx = v101;
          }
          while ( v101 < *v100 );
        }
        v102 = vtxModel_idx;
        v103 = CMemoryMovingTracker::ComputeOffset(
                 this: &vtxRemove,
                 ptrBase: (unsigned __int8 *)vtxModel_idx,
                 off: *(_DWORD *)(vtxModel_idx + 4));
        v104 = vtxHdr;
        *(_DWORD *)(v102 + 4) = v103;
        ++v134;
      }
      while ( v134 < v104->numBodyParts );
    }
    v105 = vtxHdr;
    v105->materialReplacementListOffset = (int)CMemoryMovingTracker::ComputeOffset(
                                                 this: &vtxRemove,
                                                 ptrBase: (unsigned __int8 *)vtxHdr,
                                                 off: vtxHdr->materialReplacementListOffset);
    v105->bodyPartOffset = (int)CMemoryMovingTracker::ComputeOffset(
                                  this: &vtxRemove,
                                  ptrBase: (unsigned __int8 *)v105,
                                  off: v105->bodyPartOffset);
    v105->numLODs = 1;
    CMemoryMovingTracker::MemMove(this: &vtxRemove, ptrBase: v105, length: &vtxLength);
    CUtlBuffer::SeekPut(this: vtxBuffer, type: SEEK_CURRENT, offset: vtxBuffer->m_Get + vtxLength - vtxBuffer->m_Put);
    if ( vtxIndexDeltas.m_Memory.m_nGrowSize >= 0 && vtxIndexDeltas.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: vtxIndexDeltas.m_Memory.m_pMemory);
    if ( vtxOffVertex.m_Memory.m_nGrowSize >= 0 && vtxOffVertex.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: vtxOffVertex.m_Memory.m_pMemory);
    if ( vtxOffIndex.m_Memory.m_nGrowSize >= 0 && vtxOffIndex.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: vtxOffIndex.m_Memory.m_pMemory);
    CUtlRBTree<CUtlMap<unsigned char *,int,unsigned int>::Node_t,unsigned int,CUtlMap<unsigned char *,int,unsigned int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned char *,int,unsigned int>::Node_t,unsigned int>,unsigned int>>::RemoveAll(this: &vtxRemove.m_map.m_Tree);
    v106 = vtxRemove.m_map.m_Tree.m_Elements.m_pMemory;
    vtxRemove.m_map.m_Tree.m_FirstFree = -1;
    if ( vtxRemove.m_map.m_Tree.m_Elements.m_nGrowSize >= 0 )
    {
      if ( vtxRemove.m_map.m_Tree.m_Elements.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: vtxRemove.m_map.m_Tree.m_Elements.m_pMemory);
        v106 = nullptr;
        vtxRemove.m_map.m_Tree.m_Elements.m_pMemory = nullptr;
      }
      vtxRemove.m_map.m_Tree.m_Elements.m_nAllocationCount = 0;
    }
    vtxRemove.m_map.m_Tree.m_LastAlloc.index = -1;
    if ( vtxRemove.m_map.m_Tree.m_Elements.m_nGrowSize >= 0 && v106 != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v106);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100081F0
// Name: public: void CMdlStripInfo::Reset(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMdlStripInfo::Reset(CMdlStripInfo *this)
{
  this->m_eMode = 0;
  this->m_lChecksumOld = 0;
  this->m_lChecksumNew = 0;
  CVarBitVecBase<int>::Resize(this: &this->m_vtxVerts, resizeNumBits: 0, bClearAll: false);
  this->m_vtxIndices.m_Size = 0;
  CUtlVector<CMdlStripInfo::Ps3studioBatch_t *,CUtlMemory<CMdlStripInfo::Ps3studioBatch_t *,int>>::PurgeAndDeleteElements(this: &this->m_ps3studioBatches);
}

//------------------------------------------------------------------------------
// Address: 0x10008220
// Name: public: virtual void CMdlStripInfo::DeleteThis(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMdlStripInfo::DeleteThis(CMdlStripInfo *this)
{
  if ( this != nullptr )
  {
    this->__vftable = (CMdlStripInfo_vtbl *)&CMdlStripInfo::`vftable';
    CUtlVector<CMdlStripInfo::Ps3studioBatch_t *,CUtlMemory<CMdlStripInfo::Ps3studioBatch_t *,int>>::PurgeAndDeleteElements(this: &this->m_ps3studioBatches);
    CUtlVector<unsigned short,CUtlMemory<unsigned short,int>>::~CUtlVector<unsigned short,CUtlMemory<unsigned short,int>>(this: &this->m_vtxMdlOffsets);
    CUtlVector<unsigned short,CUtlMemory<unsigned short,int>>::~CUtlVector<unsigned short,CUtlMemory<unsigned short,int>>(this: (CUtlVector<CMdlStripInfo::MdlRangeItem,CUtlMemory<CMdlStripInfo::MdlRangeItem,int> > *)&this->m_ps3studioStripGroupHeaderBatchOffset);
    CUtlVector<unsigned short,CUtlMemory<unsigned short,int>>::~CUtlVector<unsigned short,CUtlMemory<unsigned short,int>>(this: (CUtlVector<CMdlStripInfo::MdlRangeItem,CUtlMemory<CMdlStripInfo::MdlRangeItem,int> > *)&this->m_ps3studioBatches);
    CUtlVector<unsigned short,CUtlMemory<unsigned short,int>>::~CUtlVector<unsigned short,CUtlMemory<unsigned short,int>>(this: (CUtlVector<CMdlStripInfo::MdlRangeItem,CUtlMemory<CMdlStripInfo::MdlRangeItem,int> > *)&this->m_vtxIndices);
    if ( this->m_vtxVerts.m_numInts > 1 )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_vtxVerts.m_pInt);
    this->m_vtxVerts.m_pInt = nullptr;
    free(pMem: this);
  }
}
