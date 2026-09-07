// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: gcsdk/steamextra/tier1/tsmempool.cpp
// Functions: 8
// ============================================================

#include "gcsdk\steamextra\tier1\tsmempool.h"

//------------------------------------------------------------------------------
// Address: 0x10025430
// Name: public: CRWLockAutoWrite<class CThreadSpinRWLock>::CRWLockAutoWrite<class CThreadSpinRWLock>(class CThreadSpinRWLock __near &)
// Source: json
//------------------------------------------------------------------------------
CRWLockAutoWrite<CThreadSpinRWLock> *__thiscall CRWLockAutoWrite<CThreadSpinRWLock>::CRWLockAutoWrite<CThreadSpinRWLock>(
        CRWLockAutoWrite<CThreadSpinRWLock> *this,
        CThreadSpinRWLock *RWLock)
{
  this->m_RWLock = RWLock;
  if ( (RWLock->m_lockInfo.m_i32 & 0x10000) != 0
    || _InterlockedCompareExchange((volatile signed __int32 *)RWLock, 0x10000, 0) != 0 )
  {
    CThreadSpinRWLock::SpinLockForWrite(this: RWLock);
    return this;
  }
  else
  {
    RWLock->m_writerId = GetCurrentThreadId();
    return this;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10025480
// Name: public: struct TSLNodeBase_t __near * CTSListBase::Push(struct TSLNodeBase_t __near *)
// Source: json
//------------------------------------------------------------------------------
TSLNodeBase_t *__thiscall CTSListBase::Push(CTSListBase *this, TSLNodeBase_t *pNode)
{
  TSLNodeBase_t *Next; // edi
  TSLNodeBase_t *v5; // [esp-8h] [ebp-14h]
  int DepthAndSequence; // [esp-4h] [ebp-10h]
  int v7; // [esp-4h] [ebp-10h]

  Next = this->m_Head.value.Next;
  DepthAndSequence = this->m_Head.value32.DepthAndSequence;
  pNode->Next = this->m_Head.value.Next;
  if ( (unsigned __int8)_ThreadInterlockedAssignIf64(
                          a1: this,
                          a2: pNode,
                          a3: DepthAndSequence + 65537,
                          a4: Next,
                          a5: DepthAndSequence) == 0 )
  {
    do
    {
      _mm_pause();
      Next = this->m_Head.value.Next;
      v7 = this->m_Head.value32.DepthAndSequence;
      v5 = this->m_Head.value.Next;
      pNode->Next = this->m_Head.value.Next;
    }
    while ( (unsigned __int8)_ThreadInterlockedAssignIf64(a1: this, a2: pNode, a3: v7 + 65537, a4: v5, a5: v7) == 0 );
  }
  return Next;
}

//------------------------------------------------------------------------------
// Address: 0x100254E0
// Name: public: struct TSLNodeBase_t __near * CTSListBase::Detach(void)
// Source: json
//------------------------------------------------------------------------------
TSLNodeBase_t *__thiscall CTSListBase::Detach(CTSListBase *this)
{
  TSLNodeBase_t *Next; // esi

  while ( 1 )
  {
    _mm_pause();
    Next = this->m_Head.value.Next;
    if ( this->m_Head.value.Next == nullptr )
      break;
    if ( (unsigned __int8)_ThreadInterlockedAssignIf64(
                            a1: this,
                            a2: 0,
                            a3: this->m_Head.value32.DepthAndSequence & 0xFFFF0000,
                            a4: Next,
                            a5: this->m_Head.value32.DepthAndSequence) != 0 )
      return Next;
  }
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10025520
// Name: private: void CThreadSafeMemoryPool::ClearNoLock(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CThreadSafeMemoryPool::ClearNoLock(CThreadSafeMemoryPool *this)
{
  int i; // edi
  unsigned __int8 *m_pubBlockSet; // eax

  for ( i = 0; i < this->m_vecBlockSets.m_Size; ++i )
  {
    m_pubBlockSet = this->m_vecBlockSets.m_Memory.m_pMemory[i].m_pubBlockSet;
    if ( m_pubBlockSet != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *(void **)(((unsigned int)m_pubBlockSet & 0xFFFFFFFC) - 4));
  }
  CTSListBase::Detach(this: this->m_ptslistFreeBlocks);
  this->m_cubAllocated = 0;
  _InterlockedExchange(&this->m_cBlocksInUse.m_value, 0);
  this->m_vecBlockSets.m_Size = 0;
}

//------------------------------------------------------------------------------
// Address: 0x10025580
// Name: public: void CThreadSafeMemoryPool::Free(void __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CThreadSafeMemoryPool::Free(CThreadSafeMemoryPool *this, TSLNodeBase_t *pMem, int cubAlloc)
{
  int m_i32; // ecx
  CThreadSpinRWLock *m_RWLock; // eax
  CRWLockAutoWrite<CThreadSpinRWLock> generated_id_18; // [esp+8h] [ebp-4h] BYREF

  if ( (this->m_threadRWLock.m_lockInfo.m_i32 & 0x10000) != 0
    || (m_i32 = (unsigned __int16)this->m_threadRWLock.m_lockInfo.m_i32,
        _InterlockedCompareExchange(
          (volatile signed __int32 *)this,
          m_i32 + 1,
          (unsigned __int16)this->m_threadRWLock.m_lockInfo.m_i32) != m_i32) )
  {
    CThreadSpinRWLock::SpinLockForRead(this: &this->m_threadRWLock);
  }
  CTSListBase::Push(this: this->m_ptslistFreeBlocks, pNode: pMem);
  _InterlockedExchangeAdd(&this->m_cBlocksInUse.m_value, 0xFFFFFFFF);
  _InterlockedExchangeAdd((volatile signed __int32 *)this, 0xFFFFFFFF);
  if ( this->m_cBlocksInUse.m_value == 0 && this->m_cubAllocated >= 0x500000 && this->m_vecBlockSets.m_Size >= 10 )
  {
    CRWLockAutoWrite<CThreadSpinRWLock>::CRWLockAutoWrite<CThreadSpinRWLock>(
      this: &generated_id_18,
      RWLock: &this->m_threadRWLock);
    if ( this->m_cBlocksInUse.m_value == 0 )
      CThreadSafeMemoryPool::ClearNoLock(this);
    m_RWLock = generated_id_18.m_RWLock;
    generated_id_18.m_RWLock->m_writerId = 0;
    m_RWLock->m_lockInfo.m_i32 = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10025620
// Name: public: CThreadSafeMemoryPool::CThreadSafeMemoryPool(int,int,int)
// Source: json
//------------------------------------------------------------------------------
CThreadSafeMemoryPool *__thiscall CThreadSafeMemoryPool::CThreadSafeMemoryPool(
        CThreadSafeMemoryPool *this,
        int blockSize,
        int numElements,
        int growMode)
{
  CTSListBase *v5; // eax
  CTSListBase *v6; // ebx
  int v7; // ecx

  CThreadSpinRWLock::CThreadSpinRWLock(this: &this->m_threadRWLock);
  this->m_cBlocksInUse.m_value = 0;
  this->m_vecBlockSets.m_Memory.m_pMemory = nullptr;
  this->m_vecBlockSets.m_Memory.m_nAllocationCount = 0;
  this->m_vecBlockSets.m_Memory.m_nGrowSize = 0;
  this->m_vecBlockSets.m_Size = 0;
  this->m_vecBlockSets.m_pElements = nullptr;
  v5 = (CTSListBase *)operator new(nSize: 8u);
  v6 = v5;
  if ( v5 != nullptr )
  {
    if ( ((unsigned __int8)v5 & 7) != 0 )
    {
      _Error(a1: "CTSListBase: Misaligned list\n");
      __debugbreak();
    }
    v6->m_Head.value.Next = nullptr;
    v6->m_Head.value32.DepthAndSequence = 0;
  }
  else
  {
    v6 = nullptr;
  }
  v7 = blockSize;
  this->m_ptslistFreeBlocks = v6;
  if ( blockSize % 8 != 0 )
    v7 = 8 - blockSize % 8 + blockSize;
  this->m_cubBlockSize = v7;
  this->m_cubAllocated = 0;
  this->m_nGrowMode = growMode;
  this->m_nGrowSize = numElements;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100256B0
// Name: public: CThreadSafeMemoryPool::~CThreadSafeMemoryPool(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CThreadSafeMemoryPool::~CThreadSafeMemoryPool(CThreadSafeMemoryPool *this)
{
  int i; // edi
  unsigned __int8 *m_pubBlockSet; // eax
  CTSListBase *m_ptslistFreeBlocks; // edi
  CThreadSafeMemoryPool::BlockSet_t *m_pMemory; // eax

  if ( (this->m_threadRWLock.m_lockInfo.m_i32 & 0x10000) != 0
    || _InterlockedCompareExchange((volatile signed __int32 *)this, 0x10000, 0) != 0 )
  {
    CThreadSpinRWLock::SpinLockForWrite(this: &this->m_threadRWLock);
  }
  else
  {
    this->m_threadRWLock.m_writerId = GetCurrentThreadId();
  }
  for ( i = 0; i < this->m_vecBlockSets.m_Size; ++i )
  {
    m_pubBlockSet = this->m_vecBlockSets.m_Memory.m_pMemory[i].m_pubBlockSet;
    if ( m_pubBlockSet != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *(void **)(((unsigned int)m_pubBlockSet & 0xFFFFFFFC) - 4));
  }
  m_ptslistFreeBlocks = this->m_ptslistFreeBlocks;
  if ( m_ptslistFreeBlocks != nullptr )
  {
    CTSListBase::Detach(this: this->m_ptslistFreeBlocks);
    free(pMem: m_ptslistFreeBlocks);
  }
  this->m_threadRWLock.m_writerId = 0;
  this->m_threadRWLock.m_lockInfo.m_i32 = 0;
  this->m_vecBlockSets.m_Size = 0;
  if ( this->m_vecBlockSets.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_vecBlockSets.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_vecBlockSets.m_Memory.m_pMemory);
      this->m_vecBlockSets.m_Memory.m_pMemory = nullptr;
    }
    this->m_vecBlockSets.m_Memory.m_nAllocationCount = 0;
  }
  m_pMemory = this->m_vecBlockSets.m_Memory.m_pMemory;
  this->m_vecBlockSets.m_pElements = m_pMemory;
  if ( this->m_vecBlockSets.m_Memory.m_nGrowSize >= 0 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      this->m_vecBlockSets.m_Memory.m_pMemory = nullptr;
    }
    this->m_vecBlockSets.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10025780
// Name: public: void __near * CThreadSafeMemoryPool::Alloc(unsigned int)
// Source: json
//------------------------------------------------------------------------------
TSLNodeBase_t *__thiscall CThreadSafeMemoryPool::Alloc(CThreadSafeMemoryPool *this, unsigned int amount)
{
  signed __int32 m_i32; // ecx
  CTSListBase *m_ptslistFreeBlocks; // ebx
  TSLNodeBase_t *Next; // edi
  int DepthAndSequence; // eax
  int v7; // edi
  int m_nGrowMode; // eax
  void *v9; // eax
  unsigned int v10; // ebx
  unsigned int v11; // eax
  TSLNodeBase_t *v12; // edi
  int v13; // ecx
  int m_nAllocationCount; // eax
  CThreadSafeMemoryPool::BlockSet_t *m_pMemory; // edx
  int v16; // eax
  CThreadSafeMemoryPool::BlockSet_t *v17; // ecx
  int cAttempts; // [esp+Ch] [ebp-Ch]
  int m_Size; // [esp+10h] [ebp-8h]
  unsigned int cubBlob; // [esp+14h] [ebp-4h]

  cAttempts = 999;
  while ( 1 )
  {
    if ( (this->m_threadRWLock.m_lockInfo.m_i32 & 0x10000) != 0
      || (m_i32 = (unsigned __int16)this->m_threadRWLock.m_lockInfo.m_i32,
          _InterlockedCompareExchange((volatile signed __int32 *)this, m_i32 + 1, m_i32) != m_i32) )
    {
      CThreadSpinRWLock::SpinLockForRead(this: &this->m_threadRWLock);
    }
    m_ptslistFreeBlocks = this->m_ptslistFreeBlocks;
    Next = m_ptslistFreeBlocks->m_Head.value.Next;
    DepthAndSequence = m_ptslistFreeBlocks->m_Head.value32.DepthAndSequence;
    if ( m_ptslistFreeBlocks->m_Head.value.Next != nullptr )
      break;
LABEL_8:
    _InterlockedExchangeAdd((volatile signed __int32 *)this, 0xFFFFFFFF);
    if ( (this->m_threadRWLock.m_lockInfo.m_i32 & 0x10000) != 0
      || _InterlockedCompareExchange((volatile signed __int32 *)this, 0x10000, 0) != 0 )
    {
      CThreadSpinRWLock::SpinLockForWrite(this: &this->m_threadRWLock);
    }
    else
    {
      this->m_threadRWLock.m_writerId = GetCurrentThreadId();
    }
    if ( this->m_ptslistFreeBlocks->m_Head.value.Depth <= 0 )
    {
      v7 = this->m_cubBlockSize * this->m_nGrowSize;
      m_nGrowMode = this->m_nGrowMode;
      cubBlob = v7;
      if ( m_nGrowMode == 1 )
      {
        cubBlob = v7 * (this->m_vecBlockSets.m_Size + 1);
        v7 = cubBlob;
      }
      if ( m_nGrowMode == 0 && this->m_vecBlockSets.m_Size == 1 )
      {
        this->m_threadRWLock.m_writerId = 0;
        this->m_threadRWLock.m_lockInfo.m_i32 = 0;
        return nullptr;
      }
      v9 = _g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7 + 11);
      if ( v9 == nullptr )
      {
        this->m_threadRWLock.m_writerId = 0;
        this->m_threadRWLock.m_lockInfo.m_i32 = 0;
        return nullptr;
      }
      v10 = ((unsigned int)v9 + 11) & 0xFFFFFFF8;
      *(_DWORD *)(v10 - 4) = v9;
      v11 = v10 + v7;
      v12 = (TSLNodeBase_t *)v10;
      if ( v10 < v11 )
      {
        do
        {
          CTSListBase::Push(this: this->m_ptslistFreeBlocks, pNode: v12);
          v12 = (TSLNodeBase_t *)((char *)v12 + this->m_cubBlockSize);
        }
        while ( (unsigned int)v12 < v10 + cubBlob );
      }
      this->m_cubAllocated += cubBlob;
      m_nAllocationCount = this->m_vecBlockSets.m_Memory.m_nAllocationCount;
      m_Size = this->m_vecBlockSets.m_Size;
      v13 = m_Size;
      if ( m_Size + 1 > m_nAllocationCount )
      {
        CUtlMemory<unsigned __int64,int>::Grow(
          this: &this->m_vecBlockSets.m_Memory,
          num: m_Size - m_nAllocationCount + 1);
        v13 = m_Size;
      }
      ++this->m_vecBlockSets.m_Size;
      m_pMemory = this->m_vecBlockSets.m_Memory.m_pMemory;
      v16 = this->m_vecBlockSets.m_Size - v13 - 1;
      this->m_vecBlockSets.m_pElements = m_pMemory;
      if ( v16 > 0 )
      {
        _V_memmove(dest: &m_pMemory[v13 + 1], src: &m_pMemory[v13], count: 8 * v16);
        v13 = m_Size;
      }
      v17 = &this->m_vecBlockSets.m_Memory.m_pMemory[v13];
      if ( v17 != nullptr )
      {
        v17->m_pubBlockSet = (unsigned __int8 *)v10;
        v17->m_cubAllocated = cubBlob;
      }
      this->m_threadRWLock.m_writerId = 0;
      this->m_threadRWLock.m_lockInfo.m_i32 = 0;
    }
    else
    {
      this->m_threadRWLock.m_writerId = 0;
      this->m_threadRWLock.m_lockInfo.m_i32 = 0;
    }
    if ( --cAttempts == 0 )
      return nullptr;
  }
  while ( (unsigned __int8)_ThreadInterlockedAssignIf64(
                             a1: m_ptslistFreeBlocks,
                             a2: Next->Next,
                             a3: DepthAndSequence - 1,
                             a4: Next,
                             a5: DepthAndSequence) == 0 )
  {
    _mm_pause();
    Next = m_ptslistFreeBlocks->m_Head.value.Next;
    DepthAndSequence = m_ptslistFreeBlocks->m_Head.value32.DepthAndSequence;
    if ( m_ptslistFreeBlocks->m_Head.value.Next == nullptr )
      goto LABEL_8;
  }
  _InterlockedExchangeAdd((volatile signed __int32 *)this, 0xFFFFFFFF);
  _InterlockedExchangeAdd(&this->m_cBlocksInUse.m_value, 1u);
  return Next;
}
