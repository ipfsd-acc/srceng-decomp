// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: gcsdk/steamextra/tier1/tsmultimempool.cpp
// Functions: 11
// ============================================================

#include "gcsdk\steamextra\tier1\tsmultimempool.h"

//------------------------------------------------------------------------------
// Address: 0x1000E990
// Name: public: void CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<unsigned __int64,int,int>::Node_t,int>,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned __int64,int,int>::Node_t,int>,int>::Grow(
        CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned __int64,int,int>::Node_t,int>,int> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  UtlRBTreeNode_t<CUtlMap<unsigned __int64,int,int>::Node_t,int> *m_pMemory; // edx
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
    v7 = 32 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (UtlRBTreeNode_t<CUtlMap<unsigned __int64,int,int>::Node_t,int> *)_g_pMemAlloc->Realloc_2(
                                                                                            this: _g_pMemAlloc,
                                                                                            a2: m_pMemory,
                                                                                            a3: v7);
    else
      this->m_pMemory = (UtlRBTreeNode_t<CUtlMap<unsigned __int64,int,int>::Node_t,int> *)_g_pMemAlloc->Alloc_2(
                                                                                            this: _g_pMemAlloc,
                                                                                            a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000EA20
// Name: public: void CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<unsigned int,struct GCSDK::JobStatsBucket_t,int>::Node_t,int>,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,GCSDK::JobStatsBucket_t,int>::Node_t,int>,int>::Grow(
        CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,GCSDK::JobStatsBucket_t,int>::Node_t,int>,int> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  UtlRBTreeNode_t<CUtlMap<unsigned int,GCSDK::JobStatsBucket_t,int>::Node_t,int> *m_pMemory; // edx
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
    v7 = 240 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (UtlRBTreeNode_t<CUtlMap<unsigned int,GCSDK::JobStatsBucket_t,int>::Node_t,int> *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (UtlRBTreeNode_t<CUtlMap<unsigned int,GCSDK::JobStatsBucket_t,int>::Node_t,int> *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000EAC0
// Name: public: void CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<unsigned int,int,int>::Node_t,int>,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,int,int>::Node_t,int>,int>::Grow(
        CUtlMemory<GCSDK::CJobMgr::JobSleeping_t,int> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  GCSDK::CJobMgr::JobSleeping_t *m_pMemory; // edx
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
      this->m_pMemory = (GCSDK::CJobMgr::JobSleeping_t *)_g_pMemAlloc->Realloc_2(
                                                           this: _g_pMemAlloc,
                                                           a2: m_pMemory,
                                                           a3: v7);
    else
      this->m_pMemory = (GCSDK::CJobMgr::JobSleeping_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100173E0
// Name: public: static bool CDefOps<void __near *>::LessFunc(void __near * const __near &,void __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl CDefOps<void *>::LessFunc(const unsigned int *lhs, const unsigned int *rhs)
{
  return *lhs < *rhs;
}

//------------------------------------------------------------------------------
// Address: 0x10017460
// Name: public: void CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<class CSteamID,class GCSDK::CSharedObjectCache __near *,int>::Node_t,int>,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<UtlRBTreeNode_t<CUtlMap<CSteamID,GCSDK::CSharedObjectCache *,int>::Node_t,int>,int>::Grow(
        CUtlMemory<UtlRBTreeNode_t<CUtlMap<CSteamID,GCSDK::CSharedObjectCache *,int>::Node_t,int>,int> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  UtlRBTreeNode_t<CUtlMap<CSteamID,GCSDK::CSharedObjectCache *,int>::Node_t,int> *m_pMemory; // edx

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
      this->m_pMemory = (UtlRBTreeNode_t<CUtlMap<CSteamID,GCSDK::CSharedObjectCache *,int>::Node_t,int> *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: 28 * m_nAllocationCount);
    else
      this->m_pMemory = (UtlRBTreeNode_t<CUtlMap<CSteamID,GCSDK::CSharedObjectCache *,int>::Node_t,int> *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 28 * m_nAllocationCount);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10018F10
// Name: public: CThreadSafeMultiMemoryPool::~CThreadSafeMultiMemoryPool(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CThreadSafeMultiMemoryPool::~CThreadSafeMultiMemoryPool(CThreadSafeMultiMemoryPool *this)
{
  DWORD CurrentThreadId; // ecx
  int i; // ebx
  CThreadSafeMemoryPool *m_pMemPool; // edi
  int j; // edi
  CThreadSafeMultiMemoryPool::MemPoolRecord_t **m_pMemory; // eax
  CThreadSafeMultiMemoryPool::MemPoolRecord_t *v8; // eax

  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != this->m_mutexRawAllocations.m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)&this->m_mutexRawAllocations, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(a1: &this->m_mutexRawAllocations, a2: CurrentThreadId, a3: 0);
  }
  else
  {
    ++this->m_mutexRawAllocations.m_depth;
  }
  for ( i = 0; i < this->m_VecMemPool.m_Size; ++i )
  {
    m_pMemPool = this->m_VecMemPool.m_Memory.m_pMemory[i].m_pMemPool;
    if ( m_pMemPool != nullptr )
    {
      CThreadSafeMemoryPool::~CThreadSafeMemoryPool(this: this->m_VecMemPool.m_Memory.m_pMemory[i].m_pMemPool);
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *(void **)(((unsigned int)m_pMemPool & 0xFFFFFFFC) - 4));
    }
  }
  for ( j = 0; j < this->m_MapRawAllocation.m_Tree.m_Elements.m_nAllocationCount; ++j )
  {
    if ( j >= 0
      && j < this->m_MapRawAllocation.m_Tree.m_Elements.m_nAllocationCount
      && j <= this->m_MapRawAllocation.m_Tree.m_LastAlloc.index )
    {
      if ( (`CUtlRBTree<CUtlMap<void *,CThreadSafeMultiMemoryPool::RawAllocation_t,int>::Node_t,int,CUtlMap<void *,CThreadSafeMultiMemoryPool::RawAllocation_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,CThreadSafeMultiMemoryPool::RawAllocation_t,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<void *,CThreadSafeMultiMemoryPool::RawAllocation_t,int>::Node_t,int,CUtlMap<void *,CThreadSafeMultiMemoryPool::RawAllocation_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,CThreadSafeMultiMemoryPool::RawAllocation_t,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CUtlMap<void *,CThreadSafeMultiMemoryPool::RawAllocation_t,int>::Node_t,int,CUtlMap<void *,CThreadSafeMultiMemoryPool::RawAllocation_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,CThreadSafeMultiMemoryPool::RawAllocation_t,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_100828DC = -1;
        dword_100828E0 = -1;
        dword_100828E4 = 1;
      }
      if ( this->m_MapRawAllocation.m_Tree.m_Elements.m_pMemory[j].m_Left != j )
        _g_pMemAlloc->Free_2(
          this: _g_pMemAlloc,
          a2: this->m_MapRawAllocation.m_Tree.m_Elements.m_pMemory[j].m_Data.elem.m_pvMem);
    }
  }
  if ( this->m_mutexRawAllocations.m_depth-- == 1 )
    _InterlockedExchange((volatile __int32 *)&this->m_mutexRawAllocations, 0);
  CUtlRBTree<CUtlMap<void *,CThreadSafeMultiMemoryPool::RawAllocation_t,int>::Node_t,int,CUtlMap<void *,CThreadSafeMultiMemoryPool::RawAllocation_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,CThreadSafeMultiMemoryPool::RawAllocation_t,int>::Node_t,int>,int>>::RemoveAll(this: &this->m_MapRawAllocation.m_Tree);
  this->m_MapRawAllocation.m_Tree.m_FirstFree = -1;
  if ( this->m_MapRawAllocation.m_Tree.m_Elements.m_nGrowSize >= 0 )
  {
    if ( this->m_MapRawAllocation.m_Tree.m_Elements.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_MapRawAllocation.m_Tree.m_Elements.m_pMemory);
      this->m_MapRawAllocation.m_Tree.m_Elements.m_pMemory = nullptr;
    }
    this->m_MapRawAllocation.m_Tree.m_Elements.m_nAllocationCount = 0;
  }
  this->m_MapRawAllocation.m_Tree.m_LastAlloc.index = -1;
  if ( this->m_MapRawAllocation.m_Tree.m_Elements.m_nGrowSize >= 0 )
  {
    if ( this->m_MapRawAllocation.m_Tree.m_Elements.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_MapRawAllocation.m_Tree.m_Elements.m_pMemory);
      this->m_MapRawAllocation.m_Tree.m_Elements.m_pMemory = nullptr;
    }
    this->m_MapRawAllocation.m_Tree.m_Elements.m_nAllocationCount = 0;
  }
  this->m_VecMemPoolLookup.m_Size = 0;
  if ( this->m_VecMemPoolLookup.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_VecMemPoolLookup.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_VecMemPoolLookup.m_Memory.m_pMemory);
      this->m_VecMemPoolLookup.m_Memory.m_pMemory = nullptr;
    }
    this->m_VecMemPoolLookup.m_Memory.m_nAllocationCount = 0;
  }
  m_pMemory = this->m_VecMemPoolLookup.m_Memory.m_pMemory;
  this->m_VecMemPoolLookup.m_pElements = m_pMemory;
  if ( this->m_VecMemPoolLookup.m_Memory.m_nGrowSize >= 0 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      this->m_VecMemPoolLookup.m_Memory.m_pMemory = nullptr;
    }
    this->m_VecMemPoolLookup.m_Memory.m_nAllocationCount = 0;
  }
  this->m_VecMemPool.m_Size = 0;
  if ( this->m_VecMemPool.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_VecMemPool.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_VecMemPool.m_Memory.m_pMemory);
      this->m_VecMemPool.m_Memory.m_pMemory = nullptr;
    }
    this->m_VecMemPool.m_Memory.m_nAllocationCount = 0;
  }
  v8 = this->m_VecMemPool.m_Memory.m_pMemory;
  this->m_VecMemPool.m_pElements = this->m_VecMemPool.m_Memory.m_pMemory;
  if ( this->m_VecMemPool.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v8 != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v8);
      this->m_VecMemPool.m_Memory.m_pMemory = nullptr;
    }
    this->m_VecMemPool.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100193B0
// Name: public: CThreadSafeMultiMemoryPool::CThreadSafeMultiMemoryPool(struct CThreadSafeMultiMemoryPool::MemPoolConfig_t const __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
CThreadSafeMultiMemoryPool *__thiscall CThreadSafeMultiMemoryPool::CThreadSafeMultiMemoryPool(
        CThreadSafeMultiMemoryPool *this,
        const CThreadSafeMultiMemoryPool::MemPoolConfig_t *pMemPoolConfig,
        int cnMemPoolConfig,
        int nGrowMode)
{
  int i; // ebx
  int v6; // eax
  CThreadSafeMemoryPool *v7; // ecx
  unsigned int m_cubBlockSize; // edx
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CThreadSafeMultiMemoryPool::MemPoolRecord_t *m_pMemory; // ecx
  int v12; // eax
  CThreadSafeMultiMemoryPool::MemPoolRecord_t *v13; // eax
  unsigned int m_nBlockSizeMax; // eax
  int v15; // ebx
  signed int v16; // edi
  int v17; // edx
  CThreadSafeMultiMemoryPool::MemPoolRecord_t **v18; // ecx
  int v19; // eax
  signed int v20; // ebx
  int v21; // eax
  unsigned int *p_m_nBlockSize; // ecx
  CThreadSafeMemoryPool *memPoolRecord; // [esp+Ch] [ebp-8h]
  unsigned int memPoolRecord_4; // [esp+10h] [ebp-4h]
  unsigned int pMemPoolConfiga; // [esp+1Ch] [ebp+8h]

  this->m_VecMemPool.m_Memory.m_pMemory = nullptr;
  this->m_VecMemPool.m_Memory.m_nAllocationCount = 0;
  this->m_VecMemPool.m_Memory.m_nGrowSize = 0;
  this->m_VecMemPool.m_Size = 0;
  this->m_VecMemPool.m_pElements = nullptr;
  this->m_VecMemPoolLookup.m_Memory.m_pMemory = nullptr;
  this->m_VecMemPoolLookup.m_Memory.m_nAllocationCount = 0;
  this->m_VecMemPoolLookup.m_Memory.m_nGrowSize = 0;
  this->m_VecMemPoolLookup.m_Size = 0;
  this->m_VecMemPoolLookup.m_pElements = nullptr;
  this->m_MapRawAllocation.m_Tree.m_LessFunc.m_LessFunc = nullptr;
  this->m_MapRawAllocation.m_Tree.m_Elements.m_pMemory = nullptr;
  this->m_MapRawAllocation.m_Tree.m_Elements.m_nAllocationCount = 0;
  this->m_MapRawAllocation.m_Tree.m_Elements.m_nGrowSize = 0;
  this->m_MapRawAllocation.m_Tree.m_Root = -1;
  this->m_MapRawAllocation.m_Tree.m_FirstFree = -1;
  this->m_MapRawAllocation.m_Tree.m_NumElements = 0;
  this->m_MapRawAllocation.m_Tree.m_LastAlloc.index = -1;
  this->m_MapRawAllocation.m_Tree.m_pElements = this->m_MapRawAllocation.m_Tree.m_Elements.m_pMemory;
  this->m_mutexRawAllocations.m_ownerID = 0;
  this->m_mutexRawAllocations.m_depth = 0;
  this->m_cubReallocedTotal = 0;
  if ( this->m_MapRawAllocation.m_Tree.m_LessFunc.m_LessFunc == nullptr )
    this->m_MapRawAllocation.m_Tree.m_LessFunc.m_LessFunc = (bool (__cdecl *)(void *const *, void *const *))CDefOps<void *>::LessFunc;
  for ( i = 0; i < cnMemPoolConfig; this->m_nBlockSizeMax = m_nBlockSizeMax )
  {
    v6 = _g_pMemAlloc->Alloc(
           this: _g_pMemAlloc,
           a2: 67,
           a3: "C:\\buildbot\\slave\\cstrike15_win32_xbox_daily\\build\\source\\cstrike15\\src\\gcsdk\\steamextra\\tier1/tsmempool.h",
           a4: 61);
    if ( v6 != 0 )
    {
      v7 = (CThreadSafeMemoryPool *)((v6 + 11) & 0xFFFFFFF8);
      *((_DWORD *)&v7[-1].m_ptslistFreeBlocks + 1) = v6;
      memPoolRecord = CThreadSafeMemoryPool::CThreadSafeMemoryPool(
                        this: v7,
                        blockSize: pMemPoolConfig[i].m_cubBlockSize + 4,
                        numElements: pMemPoolConfig[i].m_cubDefaultPoolSize,
                        growMode: nGrowMode);
    }
    else
    {
      memPoolRecord = nullptr;
    }
    m_cubBlockSize = pMemPoolConfig[i].m_cubBlockSize;
    m_Size = this->m_VecMemPool.m_Size;
    m_nAllocationCount = this->m_VecMemPool.m_Memory.m_nAllocationCount;
    memPoolRecord_4 = m_cubBlockSize;
    if ( m_Size + 1 > m_nAllocationCount )
    {
      CUtlMemory<unsigned __int64,int>::Grow(
        (CUtlMemory<CThreadSafeMemoryPool::BlockSet_t,int> *)this,
        num: m_Size - m_nAllocationCount + 1);
      m_cubBlockSize = memPoolRecord_4;
    }
    ++this->m_VecMemPool.m_Size;
    m_pMemory = this->m_VecMemPool.m_Memory.m_pMemory;
    v12 = this->m_VecMemPool.m_Size - m_Size - 1;
    this->m_VecMemPool.m_pElements = this->m_VecMemPool.m_Memory.m_pMemory;
    if ( v12 > 0 )
    {
      _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 8 * v12);
      m_cubBlockSize = memPoolRecord_4;
    }
    v13 = &this->m_VecMemPool.m_Memory.m_pMemory[m_Size];
    if ( v13 != nullptr )
    {
      v13->m_pMemPool = memPoolRecord;
      v13->m_nBlockSize = m_cubBlockSize;
    }
    m_nBlockSizeMax = this->m_nBlockSizeMax;
    if ( m_nBlockSizeMax <= m_cubBlockSize )
      m_nBlockSizeMax = m_cubBlockSize;
    ++i;
  }
  v15 = this->m_VecMemPoolLookup.m_Size;
  v16 = this->m_nBlockSizeMax >> 5;
  if ( v16 != 0 )
  {
    v17 = this->m_VecMemPoolLookup.m_Memory.m_nAllocationCount;
    if ( v15 + v16 > v17 )
      CUtlMemory<GCSDK::CLock *,int>::Grow(
        this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&this->m_VecMemPoolLookup,
        num: v16 + v15 - v17);
    this->m_VecMemPoolLookup.m_Size += v16;
    v18 = this->m_VecMemPoolLookup.m_Memory.m_pMemory;
    v19 = this->m_VecMemPoolLookup.m_Size - v15 - v16;
    this->m_VecMemPoolLookup.m_pElements = v18;
    if ( v19 > 0 && v16 > 0 )
      _V_memmove(dest: &v18[v15] + v16, src: &v18[v15], count: 4 * v19);
  }
  v20 = 0;
  if ( v16 > 0 )
  {
    pMemPoolConfiga = 1;
    do
    {
      v21 = 0;
      if ( this->m_VecMemPool.m_Size > 0 )
      {
        p_m_nBlockSize = &this->m_VecMemPool.m_Memory.m_pMemory->m_nBlockSize;
        while ( *p_m_nBlockSize < pMemPoolConfiga )
        {
          ++v21;
          p_m_nBlockSize += 2;
          if ( v21 >= this->m_VecMemPool.m_Size )
            goto LABEL_30;
        }
        this->m_VecMemPoolLookup.m_Memory.m_pMemory[v20] = &this->m_VecMemPool.m_Memory.m_pMemory[v21];
      }
LABEL_30:
      pMemPoolConfiga += 32;
      ++v20;
    }
    while ( v20 < v16 );
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10019620
// Name: public: void CUtlMap<void __near *,struct CThreadSafeMultiMemoryPool::RawAllocation_t,int>::RemoveAt(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMap<void *,CThreadSafeMultiMemoryPool::RawAllocation_t,int>::RemoveAt(
        CUtlMap<void *,CThreadSafeMultiMemoryPool::RawAllocation_t,int> *this,
        int i)
{
  int v3; // eax

  if ( i != -1 )
  {
    CUtlRBTree<CUtlMap<void *,CThreadSafeMultiMemoryPool::RawAllocation_t,int>::Node_t,int,CUtlMap<void *,CThreadSafeMultiMemoryPool::RawAllocation_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,CThreadSafeMultiMemoryPool::RawAllocation_t,int>::Node_t,int>,int>>::Unlink(
      this: &this->m_Tree,
      elem: i);
    v3 = i;
    this->m_Tree.m_Elements.m_pMemory[v3].m_Left = i;
    this->m_Tree.m_Elements.m_pMemory[v3].m_Right = this->m_Tree.m_FirstFree;
    --this->m_Tree.m_NumElements;
    this->m_Tree.m_FirstFree = i;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10019660
// Name: public: void __near * CThreadSafeMultiMemoryPool::Alloc(unsigned int)
// Source: json
//------------------------------------------------------------------------------
_DWORD *__thiscall CThreadSafeMultiMemoryPool::Alloc(CThreadSafeMultiMemoryPool *this, unsigned int cubAllocSize)
{
  _DWORD *result; // eax
  _DWORD *v4; // eax
  _DWORD *v5; // ebx
  CThreadFastMutex *p_m_mutexRawAllocations; // esi
  DWORD CurrentThreadId; // eax
  bool v8; // zf
  CUtlMap<void *,CThreadSafeMultiMemoryPool::RawAllocation_t,int>::Node_t insert; // [esp+8h] [ebp-10h] BYREF
  CThreadSafeMultiMemoryPool *v10; // [esp+14h] [ebp-4h]

  v10 = this;
  if ( cubAllocSize == 0 )
    return nullptr;
  if ( cubAllocSize > this->m_nBlockSizeMax )
  {
    result = _g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: cubAllocSize + 4);
    v5 = result;
    if ( result != nullptr )
    {
      *result = cubAllocSize;
      p_m_mutexRawAllocations = &this->m_mutexRawAllocations;
      CurrentThreadId = GetCurrentThreadId();
      if ( CurrentThreadId != p_m_mutexRawAllocations->m_ownerID
        && _InterlockedCompareExchange((volatile signed __int32 *)p_m_mutexRawAllocations, CurrentThreadId, 0) != 0 )
      {
        _mm_pause();
        CThreadFastMutex::Lock(a1: p_m_mutexRawAllocations, a2: CurrentThreadId, a3: 0);
      }
      else
      {
        ++p_m_mutexRawAllocations->m_depth;
      }
      insert.key = v5;
      insert.elem.m_pvMem = v5;
      insert.elem.m_nBlockSize = cubAllocSize;
      CUtlRBTree<CUtlMap<void *,CThreadSafeMultiMemoryPool::RawAllocation_t,int>::Node_t,int,CUtlMap<void *,CThreadSafeMultiMemoryPool::RawAllocation_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,CThreadSafeMultiMemoryPool::RawAllocation_t,int>::Node_t,int>,int>>::Insert(
        this: &v10->m_MapRawAllocation.m_Tree,
        &insert);
      v8 = p_m_mutexRawAllocations->m_depth-- == 1;
      result = v5 + 1;
      if ( v8 )
        _InterlockedExchange((volatile __int32 *)p_m_mutexRawAllocations, 0);
    }
  }
  else
  {
    v4 = CThreadSafeMemoryPool::Alloc(
           this: this->m_VecMemPoolLookup.m_Memory.m_pMemory[(cubAllocSize - 1) >> 5]->m_pMemPool,
           amount: cubAllocSize + 4);
    *v4 = cubAllocSize;
    return v4 + 1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10019730
// Name: public: void CThreadSafeMultiMemoryPool::Free(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CThreadSafeMultiMemoryPool::Free(CThreadSafeMultiMemoryPool *this, _DWORD *pvMem)
{
  unsigned int v3; // eax
  CThreadFastMutex *p_m_mutexRawAllocations; // esi
  DWORD CurrentThreadId; // eax
  int v6; // edi
  bool v7; // zf
  CUtlMap<void *,CThreadSafeMultiMemoryPool::RawAllocation_t,int>::Node_t search; // [esp+4h] [ebp-Ch] BYREF

  if ( pvMem != nullptr )
  {
    v3 = *(pvMem - 1);
    if ( v3 <= this->m_nBlockSizeMax )
    {
      CThreadSafeMemoryPool::Free(
        this: this->m_VecMemPoolLookup.m_Memory.m_pMemory[(v3 - 1) >> 5]->m_pMemPool,
        pMem: pvMem - 1,
        cubAlloc: v3 + 4);
      return;
    }
    p_m_mutexRawAllocations = &this->m_mutexRawAllocations;
    CurrentThreadId = GetCurrentThreadId();
    if ( CurrentThreadId != p_m_mutexRawAllocations->m_ownerID
      && _InterlockedCompareExchange((volatile signed __int32 *)p_m_mutexRawAllocations, CurrentThreadId, 0) != 0 )
    {
      _mm_pause();
      CThreadFastMutex::Lock(a1: &this->m_mutexRawAllocations, a2: CurrentThreadId, a3: 0);
    }
    else
    {
      ++this->m_mutexRawAllocations.m_depth;
    }
    search.key = pvMem - 1;
    v6 = CUtlRBTree<CUtlMap<void *,CThreadSafeMultiMemoryPool::RawAllocation_t,int>::Node_t,int,CUtlMap<void *,CThreadSafeMultiMemoryPool::RawAllocation_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,CThreadSafeMultiMemoryPool::RawAllocation_t,int>::Node_t,int>,int>>::Find(
           this: &this->m_MapRawAllocation.m_Tree,
           &search);
    if ( v6 == -1 )
    {
      v7 = this->m_mutexRawAllocations.m_depth-- == 1;
      if ( !v7 )
        return;
    }
    else
    {
      _g_pMemAlloc->Free_2(
        this: _g_pMemAlloc,
        a2: this->m_MapRawAllocation.m_Tree.m_Elements.m_pMemory[v6].m_Data.elem.m_pvMem);
      CUtlMap<void *,CThreadSafeMultiMemoryPool::RawAllocation_t,int>::RemoveAt(this: &this->m_MapRawAllocation, i: v6);
      v7 = p_m_mutexRawAllocations->m_depth-- == 1;
      if ( !v7 )
        return;
    }
    _InterlockedExchange((volatile __int32 *)p_m_mutexRawAllocations, 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10019810
// Name: public: void __near * CThreadSafeMultiMemoryPool::ReAlloc(void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
_DWORD *__thiscall CThreadSafeMultiMemoryPool::ReAlloc(CThreadSafeMultiMemoryPool *this, _DWORD *pvMem, char *cubAlloc)
{
  unsigned int v4; // edi
  CThreadFastMutex *p_m_mutexRawAllocations; // edi
  DWORD CurrentThreadId; // eax
  char *v7; // ebx
  _DWORD *v8; // eax
  _DWORD *v9; // ebx
  bool v10; // zf
  _DWORD *result; // eax
  int v12; // eax
  CUtlMap<void *,CThreadSafeMultiMemoryPool::RawAllocation_t,int> *v13; // esi
  _DWORD *v14; // eax
  CUtlMap<void *,CThreadSafeMultiMemoryPool::RawAllocation_t,int>::Node_t search; // [esp+Ch] [ebp-20h] BYREF
  CUtlMap<void *,CThreadSafeMultiMemoryPool::RawAllocation_t,int>::Node_t insert; // [esp+18h] [ebp-14h] BYREF
  void *pvAllocedMem; // [esp+24h] [ebp-8h]
  CUtlMap<void *,CThreadSafeMultiMemoryPool::RawAllocation_t,int> *p_m_MapRawAllocation; // [esp+28h] [ebp-4h]
  int iRawAllocation; // [esp+34h] [ebp+8h]
  void *pvNewMem; // [esp+38h] [ebp+Ch]

  if ( pvMem != nullptr )
  {
    v4 = *(pvMem - 1);
    if ( (unsigned int)cubAlloc <= v4 )
      return pvMem;
  }
  else
  {
    v4 = -1;
  }
  if ( v4 <= this->m_nBlockSizeMax )
  {
    if ( (unsigned int)cubAlloc > this->m_VecMemPoolLookup.m_Memory.m_pMemory[(v4 - 1) >> 5]->m_nBlockSize )
    {
      v14 = CThreadSafeMultiMemoryPool::Alloc(this, cubAllocSize: (unsigned int)cubAlloc);
      pvNewMem = v14;
      if ( v14 == nullptr )
        return nullptr;
      this->m_cubReallocedTotal += v4;
      _V_memcpy(dest: v14, src: pvMem, count: v4);
      CThreadSafeMultiMemoryPool::Free(this, pvMem);
      return pvNewMem;
    }
    *(pvMem - 1) = cubAlloc;
    return pvMem;
  }
  p_m_mutexRawAllocations = &this->m_mutexRawAllocations;
  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != p_m_mutexRawAllocations->m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)p_m_mutexRawAllocations, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(a1: &this->m_mutexRawAllocations, a2: CurrentThreadId, a3: 0);
  }
  else
  {
    ++this->m_mutexRawAllocations.m_depth;
  }
  v7 = (char *)(pvMem - 1);
  pvAllocedMem = pvMem - 1;
  search.key = pvMem - 1;
  p_m_MapRawAllocation = &this->m_MapRawAllocation;
  iRawAllocation = CUtlRBTree<CUtlMap<void *,CThreadSafeMultiMemoryPool::RawAllocation_t,int>::Node_t,int,CUtlMap<void *,CThreadSafeMultiMemoryPool::RawAllocation_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,CThreadSafeMultiMemoryPool::RawAllocation_t,int>::Node_t,int>,int>>::Find(
                     this: &this->m_MapRawAllocation.m_Tree,
                     &search);
  if ( iRawAllocation == -1 )
    goto LABEL_12;
  v8 = _g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: v7, a3: cubAlloc + 4);
  v9 = v8;
  if ( v8 == nullptr )
  {
    CUtlMap<void *,CThreadSafeMultiMemoryPool::RawAllocation_t,int>::RemoveAt(
      this: p_m_MapRawAllocation,
      i: iRawAllocation);
LABEL_12:
    v10 = this->m_mutexRawAllocations.m_depth-- == 1;
    if ( v10 )
      _InterlockedExchange((volatile __int32 *)p_m_mutexRawAllocations, 0);
    return nullptr;
  }
  *v8 = cubAlloc;
  if ( pvAllocedMem == v8 )
  {
    v12 = iRawAllocation;
    this->m_MapRawAllocation.m_Tree.m_Elements.m_pMemory[v12].m_Data.elem.m_pvMem = v9;
    this->m_MapRawAllocation.m_Tree.m_Elements.m_pMemory[v12].m_Data.elem.m_nBlockSize = (unsigned int)cubAlloc;
  }
  else
  {
    v13 = p_m_MapRawAllocation;
    CUtlMap<void *,CThreadSafeMultiMemoryPool::RawAllocation_t,int>::RemoveAt(
      this: p_m_MapRawAllocation,
      i: iRawAllocation);
    insert.key = v9;
    insert.elem.m_pvMem = v9;
    insert.elem.m_nBlockSize = (unsigned int)cubAlloc;
    CUtlRBTree<CUtlMap<void *,CThreadSafeMultiMemoryPool::RawAllocation_t,int>::Node_t,int,CUtlMap<void *,CThreadSafeMultiMemoryPool::RawAllocation_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,CThreadSafeMultiMemoryPool::RawAllocation_t,int>::Node_t,int>,int>>::Insert(
      this: &v13->m_Tree,
      &insert);
  }
  v10 = p_m_mutexRawAllocations->m_depth-- == 1;
  result = v9 + 1;
  if ( v10 )
    _InterlockedExchange((volatile __int32 *)p_m_mutexRawAllocations, 0);
  return result;
}
