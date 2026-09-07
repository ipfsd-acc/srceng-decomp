// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: dmxloader/dmxelement.cpp
// Functions: 26
// ============================================================

#include "dmxloader\dmxelement.h"

//------------------------------------------------------------------------------
// Address: 0x102465C0
// Name: public: class CUtlSymbolLarge CUtlSymbolTableLargeBase<class CNonThreadsafeTree<0>,0>::Find(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
CUtlSymbolLarge *__thiscall CUtlSymbolTableLargeBase<CNonThreadsafeTree<0>,0>::Find(
        CUtlSymbolTableLargeBase<CNonThreadsafeTree<0>,0> *this,
        CUtlSymbolLarge *result,
        const char *pString)
{
  const char *v3; // ebx
  int v5; // eax
  int v6; // esi
  void *v7; // esp
  CUtlRBTree<CUtlSymbolTableLargeBaseTreeEntry_t *,int,CTreeEntryLess<CNonThreadsafeTree<0>,0>,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int>,int> > *v8; // esi
  int v9; // eax
  CUtlSymbolTableLargeBaseTreeEntry_t *m_Data; // ecx
  unsigned int v11; // [esp+0h] [ebp-10h] BYREF
  int v12; // [esp+4h] [ebp-Ch] BYREF
  CUtlRBTree<CUtlSymbolTableLargeBaseTreeEntry_t *,int,CTreeEntryLess<CNonThreadsafeTree<0>,0>,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int>,int> > *p_m_Lookup; // [esp+Ch] [ebp-4h]

  v3 = pString;
  p_m_Lookup = &this->m_Lookup;
  if ( pString == nullptr )
    goto LABEL_2;
  v5 = _V_strlen(str: pString);
  v6 = v5 + 1;
  v7 = alloca(v5 + 5);
  v11 = HashString(pszKey: v3);
  _V_memcpy(dest: &v12, src: v3, count: v6);
  v8 = p_m_Lookup;
  pString = (const char *)&v11;
  v9 = CUtlRBTree<CUtlSymbolTableLargeBaseTreeEntry_t *,int,CTreeEntryLess<CNonThreadsafeTree<0>,0>,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int>,int>>::Find(
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
// Address: 0x10246650
// Name: public: void CUtlSymbolTableLargeBase<class CNonThreadsafeTree<0>,0>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlSymbolTableLargeBase<CNonThreadsafeTree<0>,0>::RemoveAll(
        CUtlSymbolTableLargeBase<CNonThreadsafeTree<0>,0> *this)
{
  int i; // edi

  CUtlRBTree<CUtlSymbolTableLargeBaseTreeEntry_t *,int,CTreeEntryLess<CNonThreadsafeTree<0>,0>,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int>,int>>::RemoveAll(this: &this->m_Lookup);
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
// Address: 0x102475F0
// Name: public: class CUtlSymbolLarge CUtlSymbolTableLargeBase<class CNonThreadsafeTree<0>,0>::AddString(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CUtlSymbolLarge *__thiscall CUtlSymbolTableLargeBase<CNonThreadsafeTree<0>,0>::AddString(
        CUtlSymbolTableLargeBase<CNonThreadsafeTree<0>,0> *this,
        CUtlSymbolLarge *result,
        const char *pString)
{
  void *m_String; // ecx
  int v6; // eax
  signed int v7; // edi
  CUtlSymbolTableLargeBase<CNonThreadsafeTree<0>,0>::StringPool_t *v8; // eax
  CUtlVector<CUtlSymbolTableLargeBase<CNonThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CNonThreadsafeTree<0>,0>::StringPool_t *,int> > *p_m_StringPools; // esi
  unsigned int v10; // esi
  CUtlSymbolTableLargeBase<CNonThreadsafeTree<0>,0>::StringPool_t *v11; // edx
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CUtlSymbolTableLargeBase<CNonThreadsafeTree<0>,0>::StringPool_t **m_pMemory; // ecx
  int v15; // eax
  CUtlSymbolTableLargeBase<CNonThreadsafeTree<0>,0>::StringPool_t **v16; // eax
  unsigned int v17; // eax
  CUtlSymbolTableLargeBase<CNonThreadsafeTree<0>,0>::StringPool_t *v18; // ecx
  int m_SpaceUsed; // edx
  CUtlSymbolTableLargeBaseTreeEntry_t *v20; // esi
  int lenString; // [esp+8h] [ebp-Ch]
  int lenDecorated; // [esp+Ch] [ebp-8h]
  CUtlSymbolTableLargeBase<CNonThreadsafeTree<0>,0>::StringPool_t *pPool; // [esp+10h] [ebp-4h] BYREF

  if ( pString != nullptr )
  {
    CUtlSymbolTableLargeBase<CNonThreadsafeTree<0>,0>::Find(this, result: (CUtlSymbolLarge *)&pPool, pString);
    m_String = pPool;
    if ( pPool == (CUtlSymbolTableLargeBase<CNonThreadsafeTree<0>,0>::StringPool_t *)-1 )
    {
      v6 = _V_strlen(str: pString);
      lenString = v6 + 1;
      v7 = (v6 + 8) & 0xFFFFFFFC;
      v8 = nullptr;
      lenDecorated = v7;
      if ( this->m_StringPools.m_Size <= 0 )
        goto LABEL_10;
      p_m_StringPools = &this->m_StringPools;
      pPool = (CUtlSymbolTableLargeBase<CNonThreadsafeTree<0>,0>::StringPool_t *)this->m_StringPools.m_Memory.m_pMemory;
      while ( *(_DWORD *)pPool->m_TotalLen - *(_DWORD *)(pPool->m_TotalLen + 4) < v7 )
      {
        pPool = (CUtlSymbolTableLargeBase<CNonThreadsafeTree<0>,0>::StringPool_t *)((char *)pPool + 4);
        v8 = (CUtlSymbolTableLargeBase<CNonThreadsafeTree<0>,0>::StringPool_t *)((char *)v8 + 1);
        if ( (int)v8 >= this->m_StringPools.m_Size )
          goto LABEL_10;
      }
      pPool = v8;
      if ( v8 == (CUtlSymbolTableLargeBase<CNonThreadsafeTree<0>,0>::StringPool_t *)-1 )
      {
LABEL_10:
        v10 = v7 + 12;
        if ( (unsigned int)(v7 + 12) <= 0x800 )
          v10 = 2048;
        v11 = (CUtlSymbolTableLargeBase<CNonThreadsafeTree<0>,0>::StringPool_t *)MemAlloc_Alloc(nSize: v10);
        v11->m_TotalLen = v10 - 12;
        p_m_StringPools = &this->m_StringPools;
        v11->m_SpaceUsed = 0;
        m_Size = this->m_StringPools.m_Size;
        m_nAllocationCount = this->m_StringPools.m_Memory.m_nAllocationCount;
        pPool = v11;
        if ( m_Size + 1 > m_nAllocationCount )
        {
          CUtlMemory<INetMessage *,int>::Grow(
            this: (CUtlMemory<S3RGBA,int> *)&this->m_StringPools,
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
        pPool = (CUtlSymbolTableLargeBase<CNonThreadsafeTree<0>,0>::StringPool_t *)m_Size;
        v7 = lenDecorated;
      }
      v17 = HashString(pszKey: pString);
      v18 = p_m_StringPools->m_Memory.m_pMemory[(_DWORD)pPool];
      m_SpaceUsed = v18->m_SpaceUsed;
      v20 = (CUtlSymbolTableLargeBaseTreeEntry_t *)&v18->m_Data[m_SpaceUsed];
      v18->m_SpaceUsed = v7 + m_SpaceUsed;
      v20->m_Hash = v17;
      _V_memcpy(dest: (char *)&v18[1] + m_SpaceUsed, src: pString, count: lenString);
      m_String = this->m_Lookup.m_Elements.m_pMemory[CNonThreadsafeTree<0>::Insert(this: &this->m_Lookup, entry: v20)].m_Data->m_String;
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
// Address: 0x10248320
// Name: public: char const __near * CDmxElement::GetTypeString(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CDmxElement::GetTypeString(CDmxElement *this)
{
  const char *result; // eax

  result = this->m_Type.u.m_pAsString;
  if ( result == (const char *)-1 )
    return defaultValue;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10248330
// Name: public: struct UniqueId_t const __near & CDmxElement::GetId(void)const
// Source: json
//------------------------------------------------------------------------------
const UniqueId_t *__thiscall CDmxElement::GetId(CDmxElement *this)
{
  return &this->m_Id;
}

//------------------------------------------------------------------------------
// Address: 0x10248340
// Name: private: void CDmxElement::SetId(struct UniqueId_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxElement::SetId(CDmxElement *this, const UniqueId_t *id)
{
  CopyUniqueId(src: id, pDest: &this->m_Id);
}

//------------------------------------------------------------------------------
// Address: 0x102483E0
// Name: private: int CUtlTSHash<struct CUtlSymbolTableLargeBaseTreeEntry_t __near *,2048,struct CUtlSymbolTableLargeBaseTreeEntry_t __near *,class CCThreadsafeTreeHashMethod<2048,struct CUtlSymbolTableLargeBaseTreeEntry_t __near *,0>,0>::Find(struct CUtlSymbolTableLargeBaseTreeEntry_t __near *,struct CUtlTSHash<struct CUtlSymbolTableLargeBaseTreeEntry_t __near *,2048,struct CUtlSymbolTableLargeBaseTreeEntry_t __near *,class CCThreadsafeTreeHashMethod<2048,struct CUtlSymbolTableLargeBaseTreeEntry_t __near *,0>,0>::HashFixedDataInternal_t<struct CUtlSymbolTableLargeBaseTreeEntry_t __near *> __near *,struct CUtlTSHash<struct CUtlSymbolTableLargeBaseTreeEntry_t __near *,2048,struct CUtlSymbolTableLargeBaseTreeEntry_t __near *,class CCThreadsafeTreeHashMethod<2048,struct CUtlSymbolTableLargeBaseTreeEntry_t __near *,0>,0>::HashFixedDataInternal_t<struct CUtlSymbolTableLargeBaseTreeEntry_t __near *> __near *)
// Source: json
//------------------------------------------------------------------------------
CUtlTSHash<CUtlSymbolTableLargeBaseTreeEntry_t *,2048,CUtlSymbolTableLargeBaseTreeEntry_t *,CCThreadsafeTreeHashMethod<2048,CUtlSymbolTableLargeBaseTreeEntry_t *,0>,0>::HashFixedDataInternal_t<CUtlSymbolTableLargeBaseTreeEntry_t *> *__thiscall CUtlTSHash<CUtlSymbolTableLargeBaseTreeEntry_t *,2048,CUtlSymbolTableLargeBaseTreeEntry_t *,CCThreadsafeTreeHashMethod<2048,CUtlSymbolTableLargeBaseTreeEntry_t *,0>,0>::Find(
        CUtlTSHash<CUtlSymbolTableLargeBaseTreeEntry_t *,2048,CUtlSymbolTableLargeBaseTreeEntry_t *,CCThreadsafeTreeHashMethod<2048,CUtlSymbolTableLargeBaseTreeEntry_t *,0>,0> *this,
        CUtlSymbolTableLargeBaseTreeEntry_t *uiKey,
        CUtlTSHash<CUtlSymbolTableLargeBaseTreeEntry_t *,2048,CUtlSymbolTableLargeBaseTreeEntry_t *,CCThreadsafeTreeHashMethod<2048,CUtlSymbolTableLargeBaseTreeEntry_t *,0>,0>::HashFixedDataInternal_t<CUtlSymbolTableLargeBaseTreeEntry_t *> *pFirstElement,
        CUtlTSHash<CUtlSymbolTableLargeBaseTreeEntry_t *,2048,CUtlSymbolTableLargeBaseTreeEntry_t *,CCThreadsafeTreeHashMethod<2048,CUtlSymbolTableLargeBaseTreeEntry_t *,0>,0>::HashFixedDataInternal_t<CUtlSymbolTableLargeBaseTreeEntry_t *> *pLastElement)
{
  CUtlTSHash<CUtlSymbolTableLargeBaseTreeEntry_t *,2048,CUtlSymbolTableLargeBaseTreeEntry_t *,CCThreadsafeTreeHashMethod<2048,CUtlSymbolTableLargeBaseTreeEntry_t *,0>,0>::HashFixedDataInternal_t<CUtlSymbolTableLargeBaseTreeEntry_t *> *v4; // esi

  v4 = pFirstElement;
  if ( pFirstElement == pLastElement )
    return nullptr;
  while ( v4->m_uiKey->m_Hash != uiKey->m_Hash || _V_strcmp(s1: v4->m_uiKey->m_String, s2: uiKey->m_String) != 0 )
  {
    v4 = v4->m_pNext;
    if ( v4 == pLastElement )
      return nullptr;
  }
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x10248430
// Name: private: int CUtlTSHash<struct CUtlSymbolTableLargeBaseTreeEntry_t __near *,2048,struct CUtlSymbolTableLargeBaseTreeEntry_t __near *,class CCThreadsafeTreeHashMethod<2048,struct CUtlSymbolTableLargeBaseTreeEntry_t __near *,0>,0>::InsertUncommitted(struct CUtlSymbolTableLargeBaseTreeEntry_t __near *,struct CUtlTSHash<struct CUtlSymbolTableLargeBaseTreeEntry_t __near *,2048,struct CUtlSymbolTableLargeBaseTreeEntry_t __near *,class CCThreadsafeTreeHashMethod<2048,struct CUtlSymbolTableLargeBaseTreeEntry_t __near *,0>,0>::HashBucket_t __near &)
// Source: json
//------------------------------------------------------------------------------
CUtlTSHash<CUtlSymbolTableLargeBaseTreeEntry_t *,2048,CUtlSymbolTableLargeBaseTreeEntry_t *,CCThreadsafeTreeHashMethod<2048,CUtlSymbolTableLargeBaseTreeEntry_t *,0>,0>::HashFixedDataInternal_t<CUtlSymbolTableLargeBaseTreeEntry_t *> *__thiscall CUtlTSHash<CUtlSymbolTableLargeBaseTreeEntry_t *,2048,CUtlSymbolTableLargeBaseTreeEntry_t *,CCThreadsafeTreeHashMethod<2048,CUtlSymbolTableLargeBaseTreeEntry_t *,0>,0>::InsertUncommitted(
        CUtlTSHash<CUtlSymbolTableLargeBaseTreeEntry_t *,2048,CUtlSymbolTableLargeBaseTreeEntry_t *,CCThreadsafeTreeHashMethod<2048,CUtlSymbolTableLargeBaseTreeEntry_t *,0>,0> *this,
        CUtlSymbolTableLargeBaseTreeEntry_t *uiKey,
        CUtlTSHash<CUtlSymbolTableLargeBaseTreeEntry_t *,2048,CUtlSymbolTableLargeBaseTreeEntry_t *,CCThreadsafeTreeHashMethod<2048,CUtlSymbolTableLargeBaseTreeEntry_t *,0>,0>::HashBucket_t *bucket)
{
  CThreadFastMutex *p_m_mutex; // esi
  DWORD CurrentThreadId; // ecx
  CUtlTSHash<CUtlSymbolTableLargeBaseTreeEntry_t *,2048,CUtlSymbolTableLargeBaseTreeEntry_t *,CCThreadsafeTreeHashMethod<2048,CUtlSymbolTableLargeBaseTreeEntry_t *,0>,0>::HashFixedDataInternal_t<CUtlSymbolTableLargeBaseTreeEntry_t *> *result; // eax

  this->m_bNeedsCommit = true;
  p_m_mutex = &this->m_EntryMemory.m_mutex;
  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != p_m_mutex->m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)p_m_mutex, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(a1: p_m_mutex, a2: CurrentThreadId, a3: 0);
  }
  else
  {
    ++p_m_mutex->m_depth;
  }
  result = (CUtlTSHash<CUtlSymbolTableLargeBaseTreeEntry_t *,2048,CUtlSymbolTableLargeBaseTreeEntry_t *,CCThreadsafeTreeHashMethod<2048,CUtlSymbolTableLargeBaseTreeEntry_t *,0>,0>::HashFixedDataInternal_t<CUtlSymbolTableLargeBaseTreeEntry_t *> *)CUtlMemoryPool::Alloc(this: &this->m_EntryMemory);
  if ( p_m_mutex->m_depth-- == 1 )
    _InterlockedExchange((volatile __int32 *)p_m_mutex, 0);
  result->m_pNext = bucket->m_pFirstUncommitted;
  bucket->m_pFirstUncommitted = result;
  result->m_uiKey = uiKey;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102484A0
// Name: public: void CUtlTSHash<struct CUtlSymbolTableLargeBaseTreeEntry_t __near *,2048,struct CUtlSymbolTableLargeBaseTreeEntry_t __near *,class CCThreadsafeTreeHashMethod<2048,struct CUtlSymbolTableLargeBaseTreeEntry_t __near *,0>,0>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlTSHash<CUtlSymbolTableLargeBaseTreeEntry_t *,2048,CUtlSymbolTableLargeBaseTreeEntry_t *,CCThreadsafeTreeHashMethod<2048,CUtlSymbolTableLargeBaseTreeEntry_t *,0>,0>::RemoveAll(
        CUtlTSHash<CUtlSymbolTableLargeBaseTreeEntry_t *,2048,CUtlSymbolTableLargeBaseTreeEntry_t *,CCThreadsafeTreeHashMethod<2048,CUtlSymbolTableLargeBaseTreeEntry_t *,0>,0> *this)
{
  CThreadSpinRWLock *p_m_AddLock; // esi
  int i; // edi
  unsigned int j; // eax
  CThreadFastMutex *p_m_mutex; // esi
  DWORD CurrentThreadId; // ecx

  this->m_bNeedsCommit = false;
  if ( this->m_EntryMemory.m_BlocksAllocated != 0 )
  {
    p_m_AddLock = &this->m_aBuckets[0].m_AddLock;
    for ( i = 2048; i != 0; --i )
    {
      if ( (p_m_AddLock->m_lockInfo.m_i32 & 0x10000) != 0
        || _InterlockedCompareExchange((volatile signed __int32 *)p_m_AddLock, 0x10000, 0) != 0 )
      {
        CThreadSpinRWLock::SpinLockForWrite(this: p_m_AddLock);
      }
      else
      {
        p_m_AddLock->m_writerId = GetCurrentThreadId();
      }
      for ( j = p_m_AddLock[-1].m_writerId; j != 0; j = *(_DWORD *)(j + 4) )
        ;
      p_m_AddLock[-1].m_lockInfo.m_i32 = 0;
      p_m_AddLock[-1].m_writerId = 0;
      p_m_AddLock->m_writerId = 0;
      p_m_AddLock->m_lockInfo.m_i32 = 0;
      p_m_AddLock += 2;
    }
    p_m_mutex = &this->m_EntryMemory.m_mutex;
    CurrentThreadId = GetCurrentThreadId();
    if ( CurrentThreadId != this->m_EntryMemory.m_mutex.m_ownerID
      && _InterlockedCompareExchange((volatile signed __int32 *)p_m_mutex, CurrentThreadId, 0) != 0 )
    {
      _mm_pause();
      CThreadFastMutex::Lock(a1: p_m_mutex, a2: CurrentThreadId, a3: 0);
    }
    else
    {
      ++this->m_EntryMemory.m_mutex.m_depth;
    }
    CUtlMemoryPool::Clear(this: &this->m_EntryMemory);
    if ( this->m_EntryMemory.m_mutex.m_depth-- == 1 )
      _InterlockedExchange((volatile __int32 *)p_m_mutex, 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10248690
// Name: private: int CUtlSymbolTableLargeBase<class CThreadsafeTree<0>,0>::FindPoolWithSpace(int)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::FindPoolWithSpace(
        CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0> *this,
        int len)
{
  int m_Size; // esi
  int result; // eax
  CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t **i; // edx

  m_Size = this->m_StringPools.m_Size;
  result = 0;
  if ( m_Size <= 0 )
    return -1;
  for ( i = this->m_StringPools.m_Memory.m_pMemory; (*i)->m_TotalLen - (*i)->m_SpaceUsed < len; ++i )
  {
    if ( ++result >= m_Size )
      return -1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102486D0
// Name: public: int CUtlTSHash<struct CUtlSymbolTableLargeBaseTreeEntry_t __near *,2048,struct CUtlSymbolTableLargeBaseTreeEntry_t __near *,class CCThreadsafeTreeHashMethod<2048,struct CUtlSymbolTableLargeBaseTreeEntry_t __near *,0>,0>::Insert(struct CUtlSymbolTableLargeBaseTreeEntry_t __near *,struct CUtlSymbolTableLargeBaseTreeEntry_t __near * const __near &,bool __near *)
// Source: json
//------------------------------------------------------------------------------
CUtlTSHash<CUtlSymbolTableLargeBaseTreeEntry_t *,2048,CUtlSymbolTableLargeBaseTreeEntry_t *,CCThreadsafeTreeHashMethod<2048,CUtlSymbolTableLargeBaseTreeEntry_t *,0>,0>::HashFixedDataInternal_t<CUtlSymbolTableLargeBaseTreeEntry_t *> *__thiscall CUtlTSHash<CUtlSymbolTableLargeBaseTreeEntry_t *,2048,CUtlSymbolTableLargeBaseTreeEntry_t *,CCThreadsafeTreeHashMethod<2048,CUtlSymbolTableLargeBaseTreeEntry_t *,0>,0>::Insert(
        CUtlTSHash<CUtlSymbolTableLargeBaseTreeEntry_t *,2048,CUtlSymbolTableLargeBaseTreeEntry_t *,CCThreadsafeTreeHashMethod<2048,CUtlSymbolTableLargeBaseTreeEntry_t *,0>,0> *this,
        CUtlSymbolTableLargeBaseTreeEntry_t *uiKey,
        CUtlSymbolTableLargeBaseTreeEntry_t **data,
        bool *pDidInsert)
{
  CUtlTSHash<CUtlSymbolTableLargeBaseTreeEntry_t *,2048,CUtlSymbolTableLargeBaseTreeEntry_t *,CCThreadsafeTreeHashMethod<2048,CUtlSymbolTableLargeBaseTreeEntry_t *,0>,0>::HashBucket_t *v5; // esi
  CUtlTSHash<CUtlSymbolTableLargeBaseTreeEntry_t *,2048,CUtlSymbolTableLargeBaseTreeEntry_t *,CCThreadsafeTreeHashMethod<2048,CUtlSymbolTableLargeBaseTreeEntry_t *,0>,0>::HashFixedDataInternal_t<CUtlSymbolTableLargeBaseTreeEntry_t *> *result; // eax
  CThreadSpinRWLock *p_m_AddLock; // ecx

  if ( pDidInsert != nullptr )
    *pDidInsert = false;
  v5 = &this->m_aBuckets[uiKey->m_Hash & 0x7FF];
  result = CUtlTSHash<CUtlSymbolTableLargeBaseTreeEntry_t *,2048,CUtlSymbolTableLargeBaseTreeEntry_t *,CCThreadsafeTreeHashMethod<2048,CUtlSymbolTableLargeBaseTreeEntry_t *,0>,0>::Find(
             this,
             uiKey,
             pFirstElement: v5->m_pFirst,
             pLastElement: nullptr);
  if ( result == nullptr )
  {
    CThreadSpinRWLock::LockForRead(this: &v5->m_AddLock);
    result = CUtlTSHash<CUtlSymbolTableLargeBaseTreeEntry_t *,2048,CUtlSymbolTableLargeBaseTreeEntry_t *,CCThreadsafeTreeHashMethod<2048,CUtlSymbolTableLargeBaseTreeEntry_t *,0>,0>::Find(
               this,
               uiKey,
               pFirstElement: v5->m_pFirstUncommitted,
               pLastElement: v5->m_pFirst);
    _InterlockedExchangeAdd((volatile signed __int32 *)&v5->m_AddLock, 0xFFFFFFFF);
    if ( result == nullptr )
    {
      p_m_AddLock = &v5->m_AddLock;
      if ( (v5->m_AddLock.m_lockInfo.m_i32 & 0x10000) != 0
        || _InterlockedCompareExchange((volatile signed __int32 *)p_m_AddLock, 0x10000, 0) != 0 )
      {
        CThreadSpinRWLock::SpinLockForWrite(this: p_m_AddLock);
      }
      else
      {
        v5->m_AddLock.m_writerId = GetCurrentThreadId();
      }
      result = CUtlTSHash<CUtlSymbolTableLargeBaseTreeEntry_t *,2048,CUtlSymbolTableLargeBaseTreeEntry_t *,CCThreadsafeTreeHashMethod<2048,CUtlSymbolTableLargeBaseTreeEntry_t *,0>,0>::Find(
                 this,
                 uiKey,
                 pFirstElement: v5->m_pFirstUncommitted,
                 pLastElement: v5->m_pFirst);
      if ( result == nullptr )
      {
        result = CUtlTSHash<CUtlSymbolTableLargeBaseTreeEntry_t *,2048,CUtlSymbolTableLargeBaseTreeEntry_t *,CCThreadsafeTreeHashMethod<2048,CUtlSymbolTableLargeBaseTreeEntry_t *,0>,0>::InsertUncommitted(
                   this,
                   uiKey,
                   bucket: v5);
        if ( result != (CUtlTSHash<CUtlSymbolTableLargeBaseTreeEntry_t *,2048,CUtlSymbolTableLargeBaseTreeEntry_t *,CCThreadsafeTreeHashMethod<2048,CUtlSymbolTableLargeBaseTreeEntry_t *,0>,0>::HashFixedDataInternal_t<CUtlSymbolTableLargeBaseTreeEntry_t *> *)-8 )
          result->m_Data = *data;
        if ( pDidInsert != nullptr )
          *pDidInsert = true;
      }
      v5->m_AddLock.m_writerId = 0;
      v5->m_AddLock.m_lockInfo.m_i32 = 0;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10248820
// Name: public: class CUtlSymbolLarge CUtlSymbolTableLargeBase<class CThreadsafeTree<0>,0>::Find(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
CUtlSymbolLarge *__thiscall CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::Find(
        CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0> *this,
        CUtlSymbolLarge *result,
        const char *pString)
{
  int v5; // eax
  int v6; // edi
  void *v7; // esp
  CUtlTSHash<CUtlSymbolTableLargeBaseTreeEntry_t *,2048,CUtlSymbolTableLargeBaseTreeEntry_t *,CCThreadsafeTreeHashMethod<2048,CUtlSymbolTableLargeBaseTreeEntry_t *,0>,0>::HashBucket_t *v8; // edi
  CUtlTSHash<CUtlSymbolTableLargeBaseTreeEntry_t *,2048,CUtlSymbolTableLargeBaseTreeEntry_t *,CCThreadsafeTreeHashMethod<2048,CUtlSymbolTableLargeBaseTreeEntry_t *,0>,0>::HashFixedDataInternal_t<CUtlSymbolTableLargeBaseTreeEntry_t *> *v9; // eax
  CUtlSymbolTableLargeBaseTreeEntry_t v10; // [esp+0h] [ebp-Ch] BYREF

  if ( pString == nullptr )
    goto LABEL_2;
  v5 = _V_strlen(str: pString);
  v6 = v5 + 1;
  v7 = alloca(v5 + 5);
  v10.m_Hash = HashString(pszKey: pString);
  _V_memcpy(dest: v10.m_String, src: pString, count: v6);
  v8 = &this->m_Lookup.m_aBuckets[v10.m_Hash & 0x7FF];
  v9 = CUtlTSHash<CUtlSymbolTableLargeBaseTreeEntry_t *,2048,CUtlSymbolTableLargeBaseTreeEntry_t *,CCThreadsafeTreeHashMethod<2048,CUtlSymbolTableLargeBaseTreeEntry_t *,0>,0>::Find(
         this: &this->m_Lookup,
         uiKey: &v10,
         pFirstElement: v8->m_pFirst,
         pLastElement: nullptr);
  if ( v9 != nullptr
    || (CThreadSpinRWLock::LockForRead(this: &v8->m_AddLock),
        v9 = CUtlTSHash<CUtlSymbolTableLargeBaseTreeEntry_t *,2048,CUtlSymbolTableLargeBaseTreeEntry_t *,CCThreadsafeTreeHashMethod<2048,CUtlSymbolTableLargeBaseTreeEntry_t *,0>,0>::Find(
               this: &this->m_Lookup,
               uiKey: &v10,
               pFirstElement: v8->m_pFirstUncommitted,
               pLastElement: v8->m_pFirst),
        _InterlockedExchangeAdd((volatile signed __int32 *)&v8->m_AddLock, 0xFFFFFFFF),
        v9 != nullptr) )
  {
    result->u.m_Id = (int)v9->m_Data->m_String;
    return result;
  }
  else
  {
LABEL_2:
    result->u.m_Id = -1;
    return result;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102488E0
// Name: public: void CUtlSymbolTableLargeBase<class CThreadsafeTree<0>,0>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::RemoveAll(
        CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0> *this)
{
  int v2; // edi

  CUtlTSHash<CUtlSymbolTableLargeBaseTreeEntry_t *,2048,CUtlSymbolTableLargeBaseTreeEntry_t *,CCThreadsafeTreeHashMethod<2048,CUtlSymbolTableLargeBaseTreeEntry_t *,0>,0>::RemoveAll(this: &this->m_Lookup);
  v2 = 0;
  if ( this->m_StringPools.m_Size <= 0 )
  {
    this->m_StringPools.m_Size = 0;
  }
  else
  {
    do
      free(pMem: this->m_StringPools.m_Memory.m_pMemory[v2++]);
    while ( v2 < this->m_StringPools.m_Size );
    this->m_StringPools.m_Size = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10248930
// Name: private: void CDmxElement::Resort(void)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxElement::Resort(CDmxElement *this)
{
  signed int m_Size; // eax
  int i; // edi
  CDmxAttribute **v4; // eax
  const char *Name; // eax
  _DWORD context[2]; // [esp+4h] [ebp-Ch] BYREF
  char v7; // [esp+Fh] [ebp-1h] BYREF

  if ( (*((_BYTE *)this + 49) & 1) != 0 )
  {
    if ( this->m_Attributes.m_bNeedsSort )
    {
      m_Size = this->m_Attributes.m_Size;
      this->m_Attributes.m_bNeedsSort = false;
      if ( m_Size > 1 )
      {
        context[0] = this->m_Attributes.m_pLessContext;
        context[1] = &v7;
        qsort_s(
          base: this->m_Attributes.m_Memory.m_pMemory,
          num: m_Size,
          width: 4u,
          comp: (int (__cdecl *)(void *, const void *, const void *))CUtlSortVector<CDmxAttribute *,CDmxAttributeLess>::CompareHelper,
          context);
      }
    }
    *((_BYTE *)this + 49) &= ~1u;
    for ( i = this->m_Attributes.m_Size - 1; i >= 1; --i )
    {
      v4 = &this->m_Attributes.m_Memory.m_pMemory[i];
      if ( *v4 != nullptr && *(v4 - 1) != nullptr && (*v4)->m_Name.u.m_Id == (*(v4 - 1))->m_Name.u.m_Id )
      {
        Name = CDmxAttribute::GetName(this: *v4);
        _Warning(a1: "Duplicate attribute name %s encountered!\n", Name);
        if ( this->m_Attributes.m_Size - i - 1 > 0 )
          _V_memmove(
            dest: &this->m_Attributes.m_Memory.m_pMemory[i],
            src: &this->m_Attributes.m_Memory.m_pMemory[i + 1],
            count: 4 * (this->m_Attributes.m_Size - i - 1));
        --this->m_Attributes.m_Size;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10248A00
// Name: public: void CDmxElement::LockForChanges(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxElement::LockForChanges(CDmxElement *this, bool bLock)
{
  if ( bLock )
  {
    ++this->m_nLockCount;
  }
  else if ( this->m_nLockCount-- == 1 )
  {
    CDmxElement::Resort(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10248A20
// Name: public: bool CDmxElement::HasAttribute(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CDmxElement::HasAttribute(CDmxElement *this, const char *pAttributeName)
{
  int v3; // esi
  CDmxAttribute v5; // [esp+4h] [ebp-Ch] BYREF

  CDmxElement::Resort(this);
  CDmxAttribute::CDmxAttribute(this: &v5, pAttributeName);
  pAttributeName = (const char *)&v5;
  v3 = CUtlSortVector<CDmxAttribute *,CDmxAttributeLess>::Find(
         this: &this->m_Attributes,
         src: (CDmxAttribute *const *)&pAttributeName);
  CDmxAttribute::~CDmxAttribute(this: &v5);
  return v3 >= 0;
}

//------------------------------------------------------------------------------
// Address: 0x10248A70
// Name: public: class CDmxAttribute const __near * CDmxElement::GetAttribute(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
const CDmxAttribute *__thiscall CDmxElement::GetAttribute(CDmxElement *this, const char *pAttributeName)
{
  int v3; // edi
  CDmxAttribute v5; // [esp+8h] [ebp-Ch] BYREF

  CDmxElement::Resort(this);
  CDmxAttribute::CDmxAttribute(this: &v5, pAttributeName);
  pAttributeName = (const char *)&v5;
  v3 = CUtlSortVector<CDmxAttribute *,CDmxAttributeLess>::Find(
         this: &this->m_Attributes,
         src: (CDmxAttribute *const *)&pAttributeName);
  CDmxAttribute::~CDmxAttribute(this: &v5);
  if ( v3 < 0 )
    return nullptr;
  else
    return this->m_Attributes.m_Memory.m_pMemory[v3];
}

//------------------------------------------------------------------------------
// Address: 0x10248AD0
// Name: private: void CDmxElement::AddElementsToDelete(class CUtlVector<class CDmxElement __near *,class CUtlMemory<class CDmxElement __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxElement::AddElementsToDelete(CDmxElement *this, CUtlMemory<S3RGBA,int> *elementsToDelete)
{
  CDmxElement *v2; // ebx
  char v3; // al
  int m_pMemory; // esi
  int m_nAllocationCount; // eax
  CDmxElement **v7; // ecx
  int v8; // eax
  CDmxElement **v9; // esi
  int v10; // eax
  CDmxAttribute *v11; // eax
  CDmxElement *v12; // ecx
  _DWORD *m_pData; // ebx
  int v14; // ecx
  int v15; // esi
  int nCount; // [esp+4h] [ebp-Ch]
  int nElementCount; // [esp+8h] [ebp-8h]
  int i; // [esp+18h] [ebp+8h]

  v2 = this;
  v3 = *((_BYTE *)this + 49);
  if ( (v3 & 2) == 0 )
  {
    *((_BYTE *)this + 49) = v3 | 2;
    m_pMemory = (int)elementsToDelete[1].m_pMemory;
    m_nAllocationCount = elementsToDelete->m_nAllocationCount;
    if ( m_pMemory + 1 > m_nAllocationCount )
      CUtlMemory<INetMessage *,int>::Grow(this: elementsToDelete, num: m_pMemory - m_nAllocationCount + 1);
    ++elementsToDelete[1].m_pMemory;
    v7 = (CDmxElement **)elementsToDelete->m_pMemory;
    v8 = (int)elementsToDelete[1].m_pMemory - m_pMemory - 1;
    elementsToDelete[1].m_nAllocationCount = (int)elementsToDelete->m_pMemory;
    if ( v8 > 0 )
      _V_memmove(dest: &v7[m_pMemory + 1], src: &v7[m_pMemory], count: 4 * v8);
    v9 = (CDmxElement **)&elementsToDelete->m_pMemory[m_pMemory];
    if ( v9 != nullptr )
      *v9 = v2;
    v10 = 0;
    nCount = v2->m_Attributes.m_Size;
    i = 0;
    if ( nCount > 0 )
    {
      do
      {
        v11 = v2->m_Attributes.m_Memory.m_pMemory[v10];
        if ( v11->m_Type == AT_FIRST_VALUE_TYPE )
        {
          v12 = *(CDmxElement **)v11->m_pData;
          if ( v12 != nullptr )
            CDmxElement::AddElementsToDelete(
              this: v12,
              (CUtlVector<CDmxElement *,CUtlMemory<CDmxElement *,int> > *)elementsToDelete);
        }
        else if ( v11->m_Type == AT_FIRST_ARRAY_TYPE )
        {
          m_pData = v11->m_pData;
          v14 = m_pData[3];
          v15 = 0;
          for ( nElementCount = v14; v15 < v14; ++v15 )
          {
            if ( *(_DWORD *)(*m_pData + 4 * v15) != 0 )
            {
              CDmxElement::AddElementsToDelete(
                this: *(CDmxElement **)(*m_pData + 4 * v15),
                (CUtlVector<CDmxElement *,CUtlMemory<CDmxElement *,int> > *)elementsToDelete);
              v14 = nElementCount;
            }
          }
          v2 = this;
        }
        v10 = i + 1;
        i = v10;
      }
      while ( v10 < nCount );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10248BC0
// Name: public: CUtlSymbolTableLargeBase<class CThreadsafeTree<0>,0>::CUtlSymbolTableLargeBase<class CThreadsafeTree<0>,0>(void)
// Source: json
//------------------------------------------------------------------------------
CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0> *__thiscall CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>(
        CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0> *this)
{
  CUtlTSHash<CUtlSymbolTableLargeBaseTreeEntry_t *,2048,CUtlSymbolTableLargeBaseTreeEntry_t *,CCThreadsafeTreeHashMethod<2048,CUtlSymbolTableLargeBaseTreeEntry_t *,0>,0>::HashBucket_t *m_aBuckets; // eax
  int v3; // edx
  CThreadSpinRWLock *p_m_AddLock; // ecx
  int i; // ecx

  CUtlMemoryPool::CUtlMemoryPool(
    this: &this->m_Lookup.m_EntryMemory,
    blockSize: 0xCu,
    numElements: 32,
    growMode: 2,
    pszAllocOwner: nullptr,
    nAlignment: 0);
  m_aBuckets = this->m_Lookup.m_aBuckets;
  this->m_Lookup.m_EntryMemory.m_mutex.m_ownerID = 0;
  this->m_Lookup.m_EntryMemory.m_mutex.m_depth = 0;
  v3 = 2047;
  p_m_AddLock = &this->m_Lookup.m_aBuckets[0].m_AddLock;
  do
  {
    p_m_AddLock->m_lockInfo.m_i32 = 0;
    p_m_AddLock->m_writerId = 0;
    p_m_AddLock += 2;
    --v3;
  }
  while ( v3 >= 0 );
  this->m_Lookup.m_bNeedsCommit = false;
  for ( i = 2048; i != 0; --i )
  {
    m_aBuckets->m_pFirst = nullptr;
    m_aBuckets->m_pFirstUncommitted = nullptr;
    ++m_aBuckets;
  }
  this->m_StringPools.m_Memory.m_pMemory = nullptr;
  this->m_StringPools.m_Memory.m_nAllocationCount = 0;
  this->m_StringPools.m_Size = 0;
  this->m_StringPools.m_pElements = nullptr;
  this->m_StringPools.m_Memory.m_nGrowSize = 8;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10248C40
// Name: public: class CUtlSymbolLarge CUtlSymbolTableLargeBase<class CThreadsafeTree<0>,0>::AddString(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CUtlSymbolLarge *__thiscall CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::AddString(
        CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0> *this,
        CUtlSymbolLarge *result,
        char *pString)
{
  const char *v3; // esi
  void *m_String; // ecx
  int v7; // eax
  unsigned int v8; // edi
  int PoolWithSpace; // esi
  unsigned int v10; // esi
  CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *v11; // edx
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t **m_pMemory; // ecx
  int v15; // eax
  CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t **v16; // eax
  unsigned int v17; // eax
  CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *v18; // ecx
  int m_SpaceUsed; // edx
  char *v20; // esi
  const char *v21; // ecx
  int lenString; // [esp+8h] [ebp-Ch]
  int lenDecorated; // [esp+Ch] [ebp-8h]
  CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *pPool; // [esp+10h] [ebp-4h] BYREF

  v3 = pString;
  if ( pString != nullptr )
  {
    CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::Find(this, result: (CUtlSymbolLarge *)&pPool, pString);
    m_String = pPool;
    if ( pPool == (CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *)-1 )
    {
      v7 = _V_strlen(str: v3) + 1;
      v8 = (v7 + 7) & 0xFFFFFFFC;
      lenString = v7;
      lenDecorated = v8;
      PoolWithSpace = CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::FindPoolWithSpace(this, len: v8);
      if ( PoolWithSpace == -1 )
      {
        v10 = v8 + 12;
        if ( v8 + 12 <= 0x800 )
          v10 = 2048;
        v11 = (CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *)MemAlloc_Alloc(nSize: v10);
        v11->m_TotalLen = v10 - 12;
        v11->m_SpaceUsed = 0;
        m_Size = this->m_StringPools.m_Size;
        m_nAllocationCount = this->m_StringPools.m_Memory.m_nAllocationCount;
        pPool = v11;
        if ( m_Size + 1 > m_nAllocationCount )
        {
          CUtlMemory<INetMessage *,int>::Grow(
            this: (CUtlMemory<S3RGBA,int> *)&this->m_StringPools,
            num: m_Size - m_nAllocationCount + 1);
          v11 = pPool;
        }
        ++this->m_StringPools.m_Size;
        m_pMemory = this->m_StringPools.m_Memory.m_pMemory;
        v15 = this->m_StringPools.m_Size - m_Size - 1;
        this->m_StringPools.m_pElements = m_pMemory;
        if ( v15 > 0 )
        {
          _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v15);
          v11 = pPool;
        }
        v16 = &this->m_StringPools.m_Memory.m_pMemory[m_Size];
        if ( v16 != nullptr )
          *v16 = v11;
        PoolWithSpace = m_Size;
        v8 = lenDecorated;
      }
      v17 = HashString(pszKey: pString);
      v18 = this->m_StringPools.m_Memory.m_pMemory[PoolWithSpace];
      m_SpaceUsed = v18->m_SpaceUsed;
      v20 = &v18->m_Data[m_SpaceUsed];
      v18->m_SpaceUsed = v8 + m_SpaceUsed;
      v21 = pString;
      *(_DWORD *)v20 = v17;
      _V_memcpy(dest: v20 + 4, src: v21, count: lenString);
      pString = v20;
      m_String = CUtlTSHash<CUtlSymbolTableLargeBaseTreeEntry_t *,2048,CUtlSymbolTableLargeBaseTreeEntry_t *,CCThreadsafeTreeHashMethod<2048,CUtlSymbolTableLargeBaseTreeEntry_t *,0>,0>::Insert(
                   this: &this->m_Lookup,
                   uiKey: (CUtlSymbolTableLargeBaseTreeEntry_t *)v20,
                   data: (CUtlSymbolTableLargeBaseTreeEntry_t **)&pString,
                   pDidInsert: nullptr)->m_Data->m_String;
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
// Address: 0x10248E80
// Name: private: CDmxElement::CDmxElement(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDmxElement *__thiscall CDmxElement::CDmxElement(CDmxElement *this, const char *pType)
{
  const char *v4; // [esp-4h] [ebp-Ch]

  v4 = pType;
  this->m_Attributes.m_Memory.m_pMemory = nullptr;
  this->m_Attributes.m_Memory.m_nAllocationCount = 0;
  this->m_Attributes.m_Memory.m_nGrowSize = 0;
  this->m_Attributes.m_Size = 0;
  this->m_Attributes.m_pElements = nullptr;
  this->m_Attributes.m_pLessContext = nullptr;
  this->m_Attributes.m_bNeedsSort = false;
  this->m_Type.u.m_Id = -1;
  this->m_Type = (CUtlSymbolLarge)CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::AddString(
                                    this: &CDmxElement::s_TypeSymbols,
                                    result: (CUtlSymbolLarge *)&pType,
                                    pString: v4)->u.m_Id;
  *((_BYTE *)this + 49) &= 0xFCu;
  this->m_nLockCount = 0;
  CreateUniqueId(pDest: &this->m_Id);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10248EE0
// Name: public: char const __near * CDmxElement::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CDmxElement::GetName(CDmxElement *this)
{
  CUtlString *v1; // eax

  v1 = (CUtlString *)CDmxElement::GetValue<CUtlString>(this, pAttributeName: "name");
  return CUtlString::operator char const *(this: v1);
}

//------------------------------------------------------------------------------
// Address: 0x10248F00
// Name: public: class CDmxAttribute __near * CDmxElement::AddAttribute(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDmxAttribute *__thiscall CDmxElement::AddAttribute(CDmxElement *this, CDmxAttribute *pAttributeName)
{
  const char *v3; // ebx
  int v4; // edi
  CDmxAttribute *v6; // eax
  const char *v7; // edi
  CDmxAttribute v9; // [esp+Ch] [ebp-Ch] BYREF

  CDmxElement::Resort(this);
  v3 = (const char *)pAttributeName;
  CDmxAttribute::CDmxAttribute(this: &v9, (const char *)pAttributeName);
  pAttributeName = &v9;
  v4 = CUtlSortVector<CDmxAttribute *,CDmxAttributeLess>::Find(this: &this->m_Attributes, src: &pAttributeName);
  CDmxAttribute::~CDmxAttribute(this: &v9);
  if ( v4 >= 0 )
    return this->m_Attributes.m_Memory.m_pMemory[v4];
  ++this->m_nLockCount;
  *((_BYTE *)this + 49) |= 1u;
  v6 = (CDmxAttribute *)DMXAlloc(size: 0xCu);
  if ( v6 != nullptr )
    v7 = (const char *)CDmxAttribute::CDmxAttribute(this: v6, pAttributeName: v3);
  else
    v7 = nullptr;
  pAttributeName = (CDmxAttribute *)v7;
  CUtlSortVector<CDmxAttribute *,CDmxAttributeLess>::InsertNoSort(this: &this->m_Attributes, src: &pAttributeName);
  if ( this->m_nLockCount-- == 1 )
    CDmxElement::Resort(this);
  return (CDmxAttribute *)v7;
}

//------------------------------------------------------------------------------
// Address: 0x10248FA0
// Name: class CDmxElement __near * CreateDmxElement(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDmxElement *__cdecl CreateDmxElement(char *pType)
{
  unsigned __int8 *v1; // esi
  CUtlSymbolLarge v3; // [esp+8h] [ebp-4h] BYREF

  v1 = DMXAlloc(size: 0x34u);
  if ( v1 == nullptr )
    return nullptr;
  *(_DWORD *)v1 = 0;
  *((_DWORD *)v1 + 1) = 0;
  *((_DWORD *)v1 + 2) = 0;
  *((_DWORD *)v1 + 3) = 0;
  *((_DWORD *)v1 + 4) = 0;
  *((_DWORD *)v1 + 5) = 0;
  v1[24] = 0;
  *((_DWORD *)v1 + 11) = -1;
  *((CUtlSymbolLarge *)v1 + 11) = (CUtlSymbolLarge)CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::AddString(
                                                     this: &CDmxElement::s_TypeSymbols,
                                                     result: &v3,
                                                     pString: pType)->u.m_Id;
  v1[49] &= 0xFCu;
  v1[48] = 0;
  CreateUniqueId(pDest: (UniqueId_t *)(v1 + 28));
  return (CDmxElement *)v1;
}

//------------------------------------------------------------------------------
// Address: 0x10249010
// Name: public: void CDmxElement::SetName(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxElement::SetName(CDmxElement *this, const char *pName)
{
  CDmxAttribute *v3; // edi
  CUtlString *m_pData; // ecx
  CUtlString string; // [esp+8h] [ebp-10h] BYREF

  CUtlString::CUtlString(this: &string, pString: pName);
  ++this->m_nLockCount;
  v3 = CDmxElement::AddAttribute(this, pAttributeName: (CDmxAttribute *)"name");
  CDmxAttribute::AllocateDataMemory(this: v3, type: AT_STRING);
  m_pData = (CUtlString *)v3->m_pData;
  if ( m_pData != nullptr )
    CUtlString::CUtlString(this: m_pData, &string);
  if ( this->m_nLockCount-- == 1 )
    CDmxElement::Resort(this);
  string.m_Storage.m_nActualLength = 0;
  if ( string.m_Storage.m_Memory.m_nGrowSize >= 0 && string.m_Storage.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: string.m_Storage.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x10249090
// Name: private: void CDmxElement::RemoveAllElementsRecursive(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxElement::RemoveAllElementsRecursive(CDmxElement *this)
{
  int v1; // edi
  int v2; // ecx
  CDmxElement **m_pMemory; // eax
  CDmxElement *v4; // esi
  int m_Size; // ebx
  CDmxAttribute *v6; // ecx
  bool v8; // sf
  CDmxAttribute **v9; // eax
  CUtlVector<CDmxElement *,CUtlMemory<CDmxElement *,int> > elementsToDelete; // [esp+4h] [ebp-1Ch] BYREF
  int nCount; // [esp+18h] [ebp-8h]
  int i; // [esp+1Ch] [ebp-4h]

  v1 = 0;
  memset(&elementsToDelete, 0, sizeof(elementsToDelete));
  CDmxElement::AddElementsToDelete(this, (CUtlMemory<S3RGBA,int> *)&elementsToDelete);
  v2 = 0;
  nCount = elementsToDelete.m_Size;
  m_pMemory = elementsToDelete.m_Memory.m_pMemory;
  for ( i = 0; v2 < nCount; i = v2 )
  {
    v4 = m_pMemory[v2];
    if ( v4 != nullptr )
    {
      ++v4->m_nLockCount;
      m_Size = v4->m_Attributes.m_Size;
      if ( m_Size > 0 )
      {
        do
        {
          v6 = v4->m_Attributes.m_Memory.m_pMemory[v1];
          if ( v6 != nullptr )
            CDmxAttribute::~CDmxAttribute(this: v6);
          ++v1;
        }
        while ( v1 < m_Size );
      }
      *((_BYTE *)v4 + 49) &= ~1u;
      v4->m_Attributes.m_Size = 0;
      if ( v4->m_nLockCount-- == 1 )
        CDmxElement::Resort(this: v4);
      v8 = v4->m_Attributes.m_Memory.m_nGrowSize < 0;
      v4->m_Attributes.m_Size = 0;
      if ( !v8 )
      {
        if ( v4->m_Attributes.m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v4->m_Attributes.m_Memory.m_pMemory);
          v4->m_Attributes.m_Memory.m_pMemory = nullptr;
        }
        v4->m_Attributes.m_Memory.m_nAllocationCount = 0;
      }
      v8 = v4->m_Attributes.m_Memory.m_nGrowSize < 0;
      v9 = v4->m_Attributes.m_Memory.m_pMemory;
      v4->m_Attributes.m_pElements = v4->m_Attributes.m_Memory.m_pMemory;
      if ( !v8 )
      {
        if ( v9 != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v9);
          v4->m_Attributes.m_Memory.m_pMemory = nullptr;
        }
        v4->m_Attributes.m_Memory.m_nAllocationCount = 0;
      }
      m_pMemory = elementsToDelete.m_Memory.m_pMemory;
      v1 = 0;
    }
    v2 = i + 1;
  }
  elementsToDelete.m_Size = 0;
  if ( elementsToDelete.m_Memory.m_nGrowSize >= 0 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      m_pMemory = nullptr;
      elementsToDelete.m_Memory.m_pMemory = nullptr;
    }
    elementsToDelete.m_Memory.m_nAllocationCount = 0;
  }
  elementsToDelete.m_pElements = m_pMemory;
  if ( elementsToDelete.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
}

// ============================================================
// Overlay from AdminServer (Missing functions)
// ============================================================
namespace AdminServer {

//------------------------------------------------------------------------------
// Address: 0x1008FB70
// Name: public: void CUtlSymbolTableLargeBase<class CNonThreadsafeTree<0>,0>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlSymbolTableLargeBase<CNonThreadsafeTree<0>,0>::RemoveAll(
        CUtlSymbolTableLargeBase<CNonThreadsafeTree<0>,0> *this)
{
  int i; // edi

  CUtlRBTree<CUtlSymbolTableLargeBaseTreeEntry_t *,int,CTreeEntryLess<CNonThreadsafeTree<0>,0>,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int>,int>>::RemoveAll(this: &this->m_Lookup);
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
// Address: 0x1008FBD0
// Name: public: void CUtlTSHash<struct CUtlSymbolTableLargeBaseTreeEntry_t __near *,2048,struct CUtlSymbolTableLargeBaseTreeEntry_t __near *,class CCThreadsafeTreeHashMethod<2048,struct CUtlSymbolTableLargeBaseTreeEntry_t __near *,0>,0>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlTSHash<CUtlSymbolTableLargeBaseTreeEntry_t *,2048,CUtlSymbolTableLargeBaseTreeEntry_t *,CCThreadsafeTreeHashMethod<2048,CUtlSymbolTableLargeBaseTreeEntry_t *,0>,0>::RemoveAll(
        CUtlTSHash<CUtlSymbolTableLargeBaseTreeEntry_t *,2048,CUtlSymbolTableLargeBaseTreeEntry_t *,CCThreadsafeTreeHashMethod<2048,CUtlSymbolTableLargeBaseTreeEntry_t *,0>,0> *this)
{
  CThreadSpinRWLock *p_m_AddLock; // esi
  int i; // edi
  unsigned int j; // eax
  CThreadFastMutex *p_m_mutex; // esi
  DWORD CurrentThreadId; // ecx

  this->m_bNeedsCommit = false;
  if ( this->m_EntryMemory.m_BlocksAllocated != 0 )
  {
    p_m_AddLock = &this->m_aBuckets[0].m_AddLock;
    for ( i = 2048; i != 0; --i )
    {
      if ( (p_m_AddLock->m_lockInfo.m_i32 & 0x10000) != 0
        || _InterlockedCompareExchange((volatile signed __int32 *)p_m_AddLock, 0x10000, 0) != 0 )
      {
        CThreadSpinRWLock::SpinLockForWrite(this: p_m_AddLock);
      }
      else
      {
        p_m_AddLock->m_writerId = GetCurrentThreadId();
      }
      for ( j = p_m_AddLock[-1].m_writerId; j != 0; j = *(_DWORD *)(j + 4) )
        ;
      p_m_AddLock[-1].m_lockInfo.m_i32 = 0;
      p_m_AddLock[-1].m_writerId = 0;
      p_m_AddLock->m_writerId = 0;
      p_m_AddLock->m_lockInfo.m_i32 = 0;
      p_m_AddLock += 2;
    }
    p_m_mutex = &this->m_EntryMemory.m_mutex;
    CurrentThreadId = GetCurrentThreadId();
    if ( CurrentThreadId != this->m_EntryMemory.m_mutex.m_ownerID
      && _InterlockedCompareExchange((volatile signed __int32 *)p_m_mutex, CurrentThreadId, 0) != 0 )
    {
      _mm_pause();
      CThreadFastMutex::Lock(a1: p_m_mutex, a2: CurrentThreadId, a3: 0);
    }
    else
    {
      ++this->m_EntryMemory.m_mutex.m_depth;
    }
    CUtlMemoryPool::Clear(this: &this->m_EntryMemory);
    if ( this->m_EntryMemory.m_mutex.m_depth-- == 1 )
      _InterlockedExchange((volatile __int32 *)p_m_mutex, 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1008FC90
// Name: public: void CUtlSymbolTableLargeBase<class CThreadsafeTree<0>,0>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::RemoveAll(
        CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0> *this)
{
  int v2; // edi

  CUtlTSHash<CUtlSymbolTableLargeBaseTreeEntry_t *,2048,CUtlSymbolTableLargeBaseTreeEntry_t *,CCThreadsafeTreeHashMethod<2048,CUtlSymbolTableLargeBaseTreeEntry_t *,0>,0>::RemoveAll(this: &this->m_Lookup);
  v2 = 0;
  if ( this->m_StringPools.m_Size <= 0 )
  {
    this->m_StringPools.m_Size = 0;
  }
  else
  {
    do
      free(pMem: this->m_StringPools.m_Memory.m_pMemory[v2++]);
    while ( v2 < this->m_StringPools.m_Size );
    this->m_StringPools.m_Size = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1008FCE0
// Name: public: CUtlSymbolTableLargeBase<class CThreadsafeTree<0>,0>::CUtlSymbolTableLargeBase<class CThreadsafeTree<0>,0>(void)
// Source: json
//------------------------------------------------------------------------------
CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0> *__thiscall CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>(
        CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0> *this)
{
  CUtlTSHash<CUtlSymbolTableLargeBaseTreeEntry_t *,2048,CUtlSymbolTableLargeBaseTreeEntry_t *,CCThreadsafeTreeHashMethod<2048,CUtlSymbolTableLargeBaseTreeEntry_t *,0>,0>::HashBucket_t *m_aBuckets; // eax
  int v3; // edx
  CThreadSpinRWLock *p_m_AddLock; // ecx
  int i; // ecx

  CUtlMemoryPool::CUtlMemoryPool(
    this: &this->m_Lookup.m_EntryMemory,
    blockSize: 12,
    numElements: 32,
    growMode: 2,
    pszAllocOwner: nullptr,
    nAlignment: 0);
  m_aBuckets = this->m_Lookup.m_aBuckets;
  this->m_Lookup.m_EntryMemory.m_mutex.m_ownerID = 0;
  this->m_Lookup.m_EntryMemory.m_mutex.m_depth = 0;
  v3 = 2047;
  p_m_AddLock = &this->m_Lookup.m_aBuckets[0].m_AddLock;
  do
  {
    p_m_AddLock->m_lockInfo.m_i32 = 0;
    p_m_AddLock->m_writerId = 0;
    p_m_AddLock += 2;
    --v3;
  }
  while ( v3 >= 0 );
  this->m_Lookup.m_bNeedsCommit = false;
  for ( i = 2048; i != 0; --i )
  {
    m_aBuckets->m_pFirst = nullptr;
    m_aBuckets->m_pFirstUncommitted = nullptr;
    ++m_aBuckets;
  }
  this->m_StringPools.m_Memory.m_pMemory = nullptr;
  this->m_StringPools.m_Memory.m_nAllocationCount = 0;
  this->m_StringPools.m_Size = 0;
  this->m_StringPools.m_pElements = nullptr;
  this->m_StringPools.m_Memory.m_nGrowSize = 8;
  return this;
}

} // namespace AdminServer

// ============================================================
// Overlay from avitest (Missing functions)
// ============================================================
namespace avitest {

//------------------------------------------------------------------------------
// Address: 0x0047DFB0
// Name: public: void CUtlSymbolTableLargeBase<class CNonThreadsafeTree<0>,0>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlSymbolTableLargeBase<CNonThreadsafeTree<0>,0>::RemoveAll(
        CUtlSymbolTableLargeBase<CNonThreadsafeTree<0>,0> *this)
{
  int i; // edi

  CUtlRBTree<CUtlSymbolTableLargeBaseTreeEntry_t *,int,CTreeEntryLess<CNonThreadsafeTree<0>,0>,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int>,int>>::RemoveAll(this: &this->m_Lookup);
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
// Address: 0x0047E010
// Name: public: void CUtlTSHash<struct CUtlSymbolTableLargeBaseTreeEntry_t __near *,2048,struct CUtlSymbolTableLargeBaseTreeEntry_t __near *,class CCThreadsafeTreeHashMethod<2048,struct CUtlSymbolTableLargeBaseTreeEntry_t __near *,0>,0>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlTSHash<CUtlSymbolTableLargeBaseTreeEntry_t *,2048,CUtlSymbolTableLargeBaseTreeEntry_t *,CCThreadsafeTreeHashMethod<2048,CUtlSymbolTableLargeBaseTreeEntry_t *,0>,0>::RemoveAll(
        CUtlTSHash<CUtlSymbolTableLargeBaseTreeEntry_t *,2048,CUtlSymbolTableLargeBaseTreeEntry_t *,CCThreadsafeTreeHashMethod<2048,CUtlSymbolTableLargeBaseTreeEntry_t *,0>,0> *this)
{
  CThreadSpinRWLock *p_m_AddLock; // esi
  int i; // edi
  unsigned int j; // eax
  CThreadFastMutex *p_m_mutex; // esi
  DWORD CurrentThreadId; // ecx

  this->m_bNeedsCommit = false;
  if ( this->m_EntryMemory.m_BlocksAllocated != 0 )
  {
    p_m_AddLock = &this->m_aBuckets[0].m_AddLock;
    for ( i = 2048; i != 0; --i )
    {
      if ( (p_m_AddLock->m_lockInfo.m_i32 & 0x10000) != 0
        || _InterlockedCompareExchange((volatile signed __int32 *)p_m_AddLock, 0x10000, 0) != 0 )
      {
        CThreadSpinRWLock::SpinLockForWrite(this: p_m_AddLock);
      }
      else
      {
        p_m_AddLock->m_writerId = GetCurrentThreadId();
      }
      for ( j = p_m_AddLock[-1].m_writerId; j != 0; j = *(_DWORD *)(j + 4) )
        ;
      p_m_AddLock[-1].m_lockInfo.m_i32 = 0;
      p_m_AddLock[-1].m_writerId = 0;
      p_m_AddLock->m_writerId = 0;
      p_m_AddLock->m_lockInfo.m_i32 = 0;
      p_m_AddLock += 2;
    }
    p_m_mutex = &this->m_EntryMemory.m_mutex;
    CurrentThreadId = GetCurrentThreadId();
    if ( CurrentThreadId != this->m_EntryMemory.m_mutex.m_ownerID
      && _InterlockedCompareExchange((volatile signed __int32 *)p_m_mutex, CurrentThreadId, 0) != 0 )
    {
      _mm_pause();
      CThreadFastMutex::Lock(a1: p_m_mutex, a2: CurrentThreadId, a3: 0);
    }
    else
    {
      ++this->m_EntryMemory.m_mutex.m_depth;
    }
    CUtlMemoryPool::Clear(this: &this->m_EntryMemory);
    if ( this->m_EntryMemory.m_mutex.m_depth-- == 1 )
      _InterlockedExchange((volatile __int32 *)p_m_mutex, 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0047E0D0
// Name: public: void CUtlSymbolTableLargeBase<class CThreadsafeTree<0>,0>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::RemoveAll(
        CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0> *this)
{
  int v2; // edi

  CUtlTSHash<CUtlSymbolTableLargeBaseTreeEntry_t *,2048,CUtlSymbolTableLargeBaseTreeEntry_t *,CCThreadsafeTreeHashMethod<2048,CUtlSymbolTableLargeBaseTreeEntry_t *,0>,0>::RemoveAll(this: &this->m_Lookup);
  v2 = 0;
  if ( this->m_StringPools.m_Size <= 0 )
  {
    this->m_StringPools.m_Size = 0;
  }
  else
  {
    do
      free(pMem: this->m_StringPools.m_Memory.m_pMemory[v2++]);
    while ( v2 < this->m_StringPools.m_Size );
    this->m_StringPools.m_Size = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0047E120
// Name: public: CUtlSymbolTableLargeBase<class CThreadsafeTree<0>,0>::CUtlSymbolTableLargeBase<class CThreadsafeTree<0>,0>(void)
// Source: json
//------------------------------------------------------------------------------
CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0> *__thiscall CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>(
        CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0> *this)
{
  CUtlTSHash<CUtlSymbolTableLargeBaseTreeEntry_t *,2048,CUtlSymbolTableLargeBaseTreeEntry_t *,CCThreadsafeTreeHashMethod<2048,CUtlSymbolTableLargeBaseTreeEntry_t *,0>,0>::HashBucket_t *m_aBuckets; // eax
  int v3; // edx
  CThreadSpinRWLock *p_m_AddLock; // ecx
  int i; // ecx

  CUtlMemoryPool::CUtlMemoryPool(
    this: &this->m_Lookup.m_EntryMemory,
    blockSize: 12,
    numElements: 32,
    growMode: 2,
    pszAllocOwner: nullptr,
    nAlignment: 0);
  m_aBuckets = this->m_Lookup.m_aBuckets;
  this->m_Lookup.m_EntryMemory.m_mutex.m_ownerID = 0;
  this->m_Lookup.m_EntryMemory.m_mutex.m_depth = 0;
  v3 = 2047;
  p_m_AddLock = &this->m_Lookup.m_aBuckets[0].m_AddLock;
  do
  {
    p_m_AddLock->m_lockInfo.m_i32 = 0;
    p_m_AddLock->m_writerId = 0;
    p_m_AddLock += 2;
    --v3;
  }
  while ( v3 >= 0 );
  this->m_Lookup.m_bNeedsCommit = false;
  for ( i = 2048; i != 0; --i )
  {
    m_aBuckets->m_pFirst = nullptr;
    m_aBuckets->m_pFirstUncommitted = nullptr;
    ++m_aBuckets;
  }
  this->m_StringPools.m_Memory.m_pMemory = nullptr;
  this->m_StringPools.m_Memory.m_nAllocationCount = 0;
  this->m_StringPools.m_Size = 0;
  this->m_StringPools.m_pElements = nullptr;
  this->m_StringPools.m_Memory.m_nGrowSize = 8;
  return this;
}

} // namespace avitest

// ============================================================
// Overlay from dedicated (Missing functions)
// ============================================================
namespace dedicated {

//------------------------------------------------------------------------------
// Address: 0x100B1B00
// Name: public: void CUtlSymbolTableLargeBase<class CNonThreadsafeTree<0>,0>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlSymbolTableLargeBase<CNonThreadsafeTree<0>,0>::RemoveAll(
        CUtlSymbolTableLargeBase<CNonThreadsafeTree<0>,0> *this)
{
  int i; // edi

  CUtlRBTree<CUtlSymbolTableLargeBaseTreeEntry_t *,int,CTreeEntryLess<CNonThreadsafeTree<0>,0>,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int>,int>>::RemoveAll(this: &this->m_Lookup);
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
// Address: 0x100B1B60
// Name: public: void CUtlTSHash<struct CUtlSymbolTableLargeBaseTreeEntry_t __near *,2048,struct CUtlSymbolTableLargeBaseTreeEntry_t __near *,class CCThreadsafeTreeHashMethod<2048,struct CUtlSymbolTableLargeBaseTreeEntry_t __near *,0>,0>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlTSHash<CUtlSymbolTableLargeBaseTreeEntry_t *,2048,CUtlSymbolTableLargeBaseTreeEntry_t *,CCThreadsafeTreeHashMethod<2048,CUtlSymbolTableLargeBaseTreeEntry_t *,0>,0>::RemoveAll(
        CUtlTSHash<CUtlSymbolTableLargeBaseTreeEntry_t *,2048,CUtlSymbolTableLargeBaseTreeEntry_t *,CCThreadsafeTreeHashMethod<2048,CUtlSymbolTableLargeBaseTreeEntry_t *,0>,0> *this)
{
  CThreadSpinRWLock *p_m_AddLock; // esi
  int i; // edi
  unsigned int j; // eax
  CThreadFastMutex *p_m_mutex; // esi
  DWORD CurrentThreadId; // ecx

  this->m_bNeedsCommit = false;
  if ( this->m_EntryMemory.m_BlocksAllocated != 0 )
  {
    p_m_AddLock = &this->m_aBuckets[0].m_AddLock;
    for ( i = 2048; i != 0; --i )
    {
      if ( (p_m_AddLock->m_lockInfo.m_i32 & 0x10000) != 0
        || _InterlockedCompareExchange((volatile signed __int32 *)p_m_AddLock, 0x10000, 0) != 0 )
      {
        CThreadSpinRWLock::SpinLockForWrite(this: p_m_AddLock);
      }
      else
      {
        p_m_AddLock->m_writerId = GetCurrentThreadId();
      }
      for ( j = p_m_AddLock[-1].m_writerId; j != 0; j = *(_DWORD *)(j + 4) )
        ;
      p_m_AddLock[-1].m_lockInfo.m_i32 = 0;
      p_m_AddLock[-1].m_writerId = 0;
      p_m_AddLock->m_writerId = 0;
      p_m_AddLock->m_lockInfo.m_i32 = 0;
      p_m_AddLock += 2;
    }
    p_m_mutex = &this->m_EntryMemory.m_mutex;
    CurrentThreadId = GetCurrentThreadId();
    if ( CurrentThreadId != this->m_EntryMemory.m_mutex.m_ownerID
      && _InterlockedCompareExchange((volatile signed __int32 *)p_m_mutex, CurrentThreadId, 0) != 0 )
    {
      _mm_pause();
      CThreadFastMutex::Lock(a1: p_m_mutex, a2: CurrentThreadId, a3: 0);
    }
    else
    {
      ++this->m_EntryMemory.m_mutex.m_depth;
    }
    CUtlMemoryPool::Clear(this: &this->m_EntryMemory);
    if ( this->m_EntryMemory.m_mutex.m_depth-- == 1 )
      _InterlockedExchange((volatile __int32 *)p_m_mutex, 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B1C20
// Name: public: void CUtlSymbolTableLargeBase<class CThreadsafeTree<0>,0>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::RemoveAll(
        CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0> *this)
{
  int v2; // edi

  CUtlTSHash<CUtlSymbolTableLargeBaseTreeEntry_t *,2048,CUtlSymbolTableLargeBaseTreeEntry_t *,CCThreadsafeTreeHashMethod<2048,CUtlSymbolTableLargeBaseTreeEntry_t *,0>,0>::RemoveAll(this: &this->m_Lookup);
  v2 = 0;
  if ( this->m_StringPools.m_Size <= 0 )
  {
    this->m_StringPools.m_Size = 0;
  }
  else
  {
    do
      free(pMem: this->m_StringPools.m_Memory.m_pMemory[v2++]);
    while ( v2 < this->m_StringPools.m_Size );
    this->m_StringPools.m_Size = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B1C70
// Name: public: CUtlSymbolTableLargeBase<class CThreadsafeTree<0>,0>::CUtlSymbolTableLargeBase<class CThreadsafeTree<0>,0>(void)
// Source: json
//------------------------------------------------------------------------------
CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0> *__thiscall CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>(
        CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0> *this)
{
  CUtlTSHash<CUtlSymbolTableLargeBaseTreeEntry_t *,2048,CUtlSymbolTableLargeBaseTreeEntry_t *,CCThreadsafeTreeHashMethod<2048,CUtlSymbolTableLargeBaseTreeEntry_t *,0>,0>::HashBucket_t *m_aBuckets; // eax
  int v3; // edx
  CThreadSpinRWLock *p_m_AddLock; // ecx
  int i; // ecx

  CUtlMemoryPool::CUtlMemoryPool(
    this: &this->m_Lookup.m_EntryMemory,
    blockSize: 12,
    numElements: 32,
    growMode: 2,
    pszAllocOwner: nullptr,
    nAlignment: 0);
  m_aBuckets = this->m_Lookup.m_aBuckets;
  this->m_Lookup.m_EntryMemory.m_mutex.m_ownerID = 0;
  this->m_Lookup.m_EntryMemory.m_mutex.m_depth = 0;
  v3 = 2047;
  p_m_AddLock = &this->m_Lookup.m_aBuckets[0].m_AddLock;
  do
  {
    p_m_AddLock->m_lockInfo.m_i32 = 0;
    p_m_AddLock->m_writerId = 0;
    p_m_AddLock += 2;
    --v3;
  }
  while ( v3 >= 0 );
  this->m_Lookup.m_bNeedsCommit = false;
  for ( i = 2048; i != 0; --i )
  {
    m_aBuckets->m_pFirst = nullptr;
    m_aBuckets->m_pFirstUncommitted = nullptr;
    ++m_aBuckets;
  }
  this->m_StringPools.m_Memory.m_pMemory = nullptr;
  this->m_StringPools.m_Memory.m_nAllocationCount = 0;
  this->m_StringPools.m_Size = 0;
  this->m_StringPools.m_pElements = nullptr;
  this->m_StringPools.m_Memory.m_nGrowSize = 8;
  return this;
}

} // namespace dedicated

// ============================================================
// Overlay from elementviewer (Missing functions)
// ============================================================
namespace elementviewer {

//------------------------------------------------------------------------------
// Address: 0x004C77D0
// Name: public: class Vector const __near & CDmxElement::GetValue<class Vector>(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
const Vector *__thiscall CDmxElement::GetValue<Vector>(CDmxElement *this, const char *pAttributeName)
{
  const CDmxAttribute *Attribute; // eax

  Attribute = CDmxElement::GetAttribute(this, pAttributeName);
  if ( Attribute != nullptr )
  {
    if ( Attribute->m_Type == AT_VECTOR3 )
    {
      return (const Vector *)Attribute->m_pData;
    }
    else
    {
      if ( (`CDmxAttribute::GetValue<Vector>'::`4'::`local static guard' & 1) == 0 )
        `CDmxAttribute::GetValue<Vector>'::`4'::`local static guard' |= 1u;
      `CDmxAttribute::GetValue<Vector>'::`4'::defaultValue = 0;
      dword_773F94 = 0;
      dword_773F98 = 0;
      return (const Vector *)&`CDmxAttribute::GetValue<Vector>'::`4'::defaultValue;
    }
  }
  else
  {
    if ( (`CDmxElement::GetValue<Vector>'::`4'::`local static guard' & 1) == 0 )
      `CDmxElement::GetValue<Vector>'::`4'::`local static guard' |= 1u;
    `CDmxElement::GetValue<Vector>'::`4'::defaultValue.x = 0.0;
    `CDmxElement::GetValue<Vector>'::`4'::defaultValue.y = 0.0;
    `CDmxElement::GetValue<Vector>'::`4'::defaultValue.z = 0.0;
    return &`CDmxElement::GetValue<Vector>'::`4'::defaultValue;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00672C60
// Name: public: char const __near * CDmxElement::GetTypeString(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CDmxElement::GetTypeString(CDmxElement *this)
{
  const char *result; // eax

  result = this->m_Type.u.m_pAsString;
  if ( result == (const char *)-1 )
    return defaultValue;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00672C70
// Name: public: struct UniqueId_t const __near & CDmxElement::GetId(void)const
// Source: json
//------------------------------------------------------------------------------
const UniqueId_t *__thiscall CDmxElement::GetId(CDmxElement *this)
{
  return &this->m_Id;
}

//------------------------------------------------------------------------------
// Address: 0x00672C80
// Name: private: void CDmxElement::SetId(struct UniqueId_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxElement::SetId(CDmxElement *this, const UniqueId_t *id)
{
  CopyUniqueId(src: id, pDest: &this->m_Id);
}

//------------------------------------------------------------------------------
// Address: 0x00672CA0
// Name: private: void CDmxElement::UnpackBitfield<unsigned char>(unsigned char __near *,struct DmxElementUnpackStructure_t const __near *,class CDmxAttribute const __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxElement::UnpackBitfield<unsigned char>(
        CDmxElement *this,
        unsigned __int8 *pDest,
        const DmxElementUnpackStructure_t *pUnpack,
        const CDmxAttribute *pAttribute)
{
  int m_nSize; // ecx
  char v6; // bl
  char v7; // al
  unsigned __int8 v8; // al
  char mask_3; // [esp+1Bh] [ebp+Fh]

  m_nSize = pUnpack->m_nSize;
  if ( m_nSize == 8 )
  {
    v6 = -1;
    v7 = -1;
  }
  else
  {
    v6 = (1 << m_nSize) - 1;
    v7 = v6 << pUnpack->m_nBitOffset;
  }
  mask_3 = ~v7;
  v8 = *(_BYTE *)pAttribute->m_pData;
  if ( ((unsigned __int8)~v6 & v8) != 0 )
  {
    _Warning(a1: "Value %s exeeds size of datatype. \n", pUnpack->m_pAttributeName);
    v8 = 0;
  }
  *pDest &= mask_3;
  *pDest |= ((unsigned __int8)v6 & v8) << pUnpack->m_nBitOffset;
}

//------------------------------------------------------------------------------
// Address: 0x00672D10
// Name: private: void CDmxElement::UnpackBitfield<char>(char __near *,struct DmxElementUnpackStructure_t const __near *,class CDmxAttribute const __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxElement::UnpackBitfield<char>(
        CDmxElement *this,
        char *pDest,
        const DmxElementUnpackStructure_t *pUnpack,
        const CDmxAttribute *pAttribute)
{
  int m_nSize; // edx
  char v6; // bl
  char v7; // al
  char v8; // al
  char v9; // dl
  char mask_3; // [esp+1Bh] [ebp+Fh]

  m_nSize = pUnpack->m_nSize;
  if ( m_nSize == 8 )
  {
    v6 = -1;
    v7 = -1;
  }
  else
  {
    v6 = (1 << m_nSize) - 1;
    v7 = v6 << pUnpack->m_nBitOffset;
  }
  mask_3 = ~v7;
  v8 = *(_BYTE *)pAttribute->m_pData;
  v9 = (1 << (m_nSize - 1)) - 1;
  if ( v8 < 0 )
  {
    if ( (~v9 & v8) != ~v9 )
    {
LABEL_8:
      _Warning(a1: "Value %s exeeds size of datatype. \n", pUnpack->m_pAttributeName);
      v8 = 0;
    }
  }
  else if ( (~v9 & v8) != 0 )
  {
    goto LABEL_8;
  }
  *pDest &= mask_3;
  *pDest |= ((unsigned __int8)v6 & (unsigned __int8)v8) << pUnpack->m_nBitOffset;
}

//------------------------------------------------------------------------------
// Address: 0x00672DA0
// Name: private: void CDmxElement::UnpackBitfield<short>(short __near *,struct DmxElementUnpackStructure_t const __near *,class CDmxAttribute const __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxElement::UnpackBitfield<short>(
        CDmxElement *this,
        __int16 *pDest,
        const DmxElementUnpackStructure_t *pUnpack,
        const CDmxAttribute *pAttribute)
{
  int m_nSize; // edx
  __int16 v5; // bx
  __int16 v6; // ax
  __int16 v7; // di
  __int16 v8; // ax
  int v9; // ecx
  bool v10; // zf

  m_nSize = pUnpack->m_nSize;
  if ( m_nSize == 16 )
  {
    v5 = -1;
    v6 = -1;
  }
  else
  {
    v5 = (1 << m_nSize) - 1;
    v6 = v5 << pUnpack->m_nBitOffset;
  }
  v7 = ~v6;
  v8 = *(_WORD *)pAttribute->m_pData;
  v9 = ~(__int16)((1 << (m_nSize - 1)) - 1);
  if ( v8 < 0 )
    v10 = (v9 & v8) == v9;
  else
    v10 = (v9 & v8) == 0;
  if ( !v10 )
  {
    _Warning(a1: "Value %s exeeds size of datatype. \n", pUnpack->m_pAttributeName);
    v8 = 0;
  }
  *pDest &= v7;
  *pDest |= ((unsigned __int16)v5 & (unsigned __int16)v8) << pUnpack->m_nBitOffset;
}

//------------------------------------------------------------------------------
// Address: 0x00672E40
// Name: private: void CDmxElement::UnpackBitfield<unsigned short>(unsigned short __near *,struct DmxElementUnpackStructure_t const __near *,class CDmxAttribute const __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxElement::UnpackBitfield<unsigned short>(
        CDmxElement *this,
        unsigned __int16 *pDest,
        const DmxElementUnpackStructure_t *pUnpack,
        const CDmxAttribute *pAttribute)
{
  int m_nSize; // ecx
  unsigned __int16 v5; // si
  __int16 v6; // ax
  __int16 v7; // bx
  int v8; // ecx

  m_nSize = pUnpack->m_nSize;
  if ( m_nSize == 16 )
  {
    v5 = -1;
    v6 = -1;
  }
  else
  {
    v5 = (1 << m_nSize) - 1;
    v6 = v5 << pUnpack->m_nBitOffset;
  }
  v7 = ~v6;
  v8 = *(unsigned __int16 *)pAttribute->m_pData;
  if ( (~v5 & v8) != 0 )
  {
    _Warning(a1: "Value %s exeeds size of datatype. \n", pUnpack->m_pAttributeName);
    LOWORD(v8) = 0;
  }
  *pDest &= v7;
  *pDest |= (v5 & (unsigned __int16)v8) << pUnpack->m_nBitOffset;
}

//------------------------------------------------------------------------------
// Address: 0x00672EC0
// Name: private: void CDmxElement::UnpackBitfield<int>(int __near *,struct DmxElementUnpackStructure_t const __near *,class CDmxAttribute const __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxElement::UnpackBitfield<int>(
        CDmxElement *this,
        int *pDest,
        const DmxElementUnpackStructure_t *pUnpack,
        const CDmxAttribute *pAttribute)
{
  int m_nSize; // edx
  int v5; // esi
  int v6; // eax
  int v7; // ebx
  int v8; // eax
  int v9; // edx
  bool v10; // zf

  m_nSize = pUnpack->m_nSize;
  if ( m_nSize == 32 )
  {
    v5 = -1;
    v6 = -1;
  }
  else
  {
    v5 = (1 << m_nSize) - 1;
    v6 = v5 << pUnpack->m_nBitOffset;
  }
  v7 = ~v6;
  v8 = *(_DWORD *)pAttribute->m_pData;
  v9 = ~((1 << (m_nSize - 1)) - 1);
  if ( v8 < 0 )
    v10 = (v8 & v9) == v9;
  else
    v10 = (v9 & v8) == 0;
  if ( !v10 )
  {
    _Warning(a1: "Value %s exeeds size of datatype. \n", pUnpack->m_pAttributeName);
    v8 = 0;
  }
  *pDest &= v7;
  *pDest |= (v5 & v8) << pUnpack->m_nBitOffset;
}

//------------------------------------------------------------------------------
// Address: 0x00672F40
// Name: private: void CDmxElement::UnpackBitfield<unsigned int>(unsigned int __near *,struct DmxElementUnpackStructure_t const __near *,class CDmxAttribute const __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxElement::UnpackBitfield<unsigned int>(
        CDmxElement *this,
        unsigned int *pDest,
        const DmxElementUnpackStructure_t *pUnpack,
        const CDmxAttribute *pAttribute)
{
  int m_nSize; // ecx
  int v5; // esi
  int v6; // eax
  int v7; // edi
  int v8; // eax

  m_nSize = pUnpack->m_nSize;
  if ( m_nSize == 32 )
  {
    v5 = -1;
    v6 = -1;
  }
  else
  {
    v5 = (1 << m_nSize) - 1;
    v6 = v5 << pUnpack->m_nBitOffset;
  }
  v7 = ~v6;
  v8 = *(_DWORD *)pAttribute->m_pData;
  if ( (~v5 & v8) != 0 )
  {
    _Warning(a1: "Value %s exeeds size of datatype. \n", pUnpack->m_pAttributeName);
    v8 = 0;
  }
  *pDest &= v7;
  *pDest |= (v5 & v8) << pUnpack->m_nBitOffset;
}

//------------------------------------------------------------------------------
// Address: 0x006731D0
// Name: private: void CDmxElement::Resort(void)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxElement::Resort(CDmxElement *this)
{
  signed int m_Size; // eax
  int i; // edi
  CDmxAttribute **v4; // eax
  const char *Name; // eax
  _DWORD context[2]; // [esp+4h] [ebp-Ch] BYREF
  char v7; // [esp+Fh] [ebp-1h] BYREF

  if ( (*((_BYTE *)this + 49) & 1) != 0 )
  {
    if ( this->m_Attributes.m_bNeedsSort )
    {
      m_Size = this->m_Attributes.m_Size;
      this->m_Attributes.m_bNeedsSort = false;
      if ( m_Size > 1 )
      {
        context[0] = this->m_Attributes.m_pLessContext;
        context[1] = &v7;
        qsort_s(
          base: this->m_Attributes.m_Memory.m_pMemory,
          num: m_Size,
          width: 4u,
          comp: (int (__cdecl *)(void *, const void *, const void *))CUtlSortVector<CDmxAttribute *,CDmxAttributeLess>::CompareHelper,
          context);
      }
    }
    *((_BYTE *)this + 49) &= ~1u;
    for ( i = this->m_Attributes.m_Size - 1; i >= 1; --i )
    {
      v4 = &this->m_Attributes.m_Memory.m_pMemory[i];
      if ( *v4 != nullptr && *(v4 - 1) != nullptr && (*v4)->m_Name.u.m_Id == (*(v4 - 1))->m_Name.u.m_Id )
      {
        Name = CDmxAttribute::GetName(this: *v4);
        _Warning(a1: "Duplicate attribute name %s encountered!\n", Name);
        if ( this->m_Attributes.m_Size - i - 1 > 0 )
          _V_memmove(
            dest: &this->m_Attributes.m_Memory.m_pMemory[i],
            src: &this->m_Attributes.m_Memory.m_pMemory[i + 1],
            count: 4 * (this->m_Attributes.m_Size - i - 1));
        --this->m_Attributes.m_Size;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x006732A0
// Name: public: void CDmxElement::LockForChanges(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxElement::LockForChanges(CDmxElement *this, bool bLock)
{
  if ( bLock )
  {
    ++this->m_nLockCount;
  }
  else if ( this->m_nLockCount-- == 1 )
  {
    CDmxElement::Resort(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x006732C0
// Name: public: bool CDmxElement::HasAttribute(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CDmxElement::HasAttribute(CDmxElement *this, const char *pAttributeName)
{
  int v3; // esi
  CDmxAttribute v5; // [esp+4h] [ebp-Ch] BYREF

  CDmxElement::Resort(this);
  CDmxAttribute::CDmxAttribute(this: &v5, pAttributeName);
  pAttributeName = (const char *)&v5;
  v3 = CUtlSortVector<CDmxAttribute *,CDmxAttributeLess>::Find(
         this: &this->m_Attributes,
         src: (CDmxAttribute *const **)&pAttributeName);
  CDmxAttribute::~CDmxAttribute(this: &v5);
  return v3 >= 0;
}

//------------------------------------------------------------------------------
// Address: 0x00673310
// Name: public: class CDmxAttribute const __near * CDmxElement::GetAttribute(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
const CDmxAttribute *__thiscall CDmxElement::GetAttribute(CDmxElement *this, const char *pAttributeName)
{
  int v3; // edi
  CDmxAttribute v5; // [esp+8h] [ebp-Ch] BYREF

  CDmxElement::Resort(this);
  CDmxAttribute::CDmxAttribute(this: &v5, pAttributeName);
  pAttributeName = (const char *)&v5;
  v3 = CUtlSortVector<CDmxAttribute *,CDmxAttributeLess>::Find(
         this: &this->m_Attributes,
         src: (CDmxAttribute *const **)&pAttributeName);
  CDmxAttribute::~CDmxAttribute(this: &v5);
  if ( v3 < 0 )
    return nullptr;
  else
    return this->m_Attributes.m_Memory.m_pMemory[v3];
}

//------------------------------------------------------------------------------
// Address: 0x00673370
// Name: private: void CDmxElement::AddElementsToDelete(class CUtlVector<class CDmxElement __near *,class CUtlMemory<class CDmxElement __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxElement::AddElementsToDelete(CDmxElement *this, CUtlMemory<vgui::TreeNode *,int> *elementsToDelete)
{
  CDmxElement *v2; // ebx
  char v3; // al
  int m_pMemory; // esi
  int m_nAllocationCount; // eax
  CDmxElement **v7; // ecx
  int v8; // eax
  CDmxElement **v9; // esi
  int v10; // eax
  CDmxAttribute *v11; // eax
  CDmxElement *v12; // ecx
  _DWORD *m_pData; // ebx
  int v14; // ecx
  int v15; // esi
  int nCount; // [esp+4h] [ebp-Ch]
  int nElementCount; // [esp+8h] [ebp-8h]
  int i; // [esp+18h] [ebp+8h]

  v2 = this;
  v3 = *((_BYTE *)this + 49);
  if ( (v3 & 2) == 0 )
  {
    *((_BYTE *)this + 49) = v3 | 2;
    m_pMemory = (int)elementsToDelete[1].m_pMemory;
    m_nAllocationCount = elementsToDelete->m_nAllocationCount;
    if ( m_pMemory + 1 > m_nAllocationCount )
      CUtlMemory<IDmFormatUpdater *,int>::Grow(this: elementsToDelete, num: m_pMemory - m_nAllocationCount + 1);
    ++elementsToDelete[1].m_pMemory;
    v7 = (CDmxElement **)elementsToDelete->m_pMemory;
    v8 = (int)elementsToDelete[1].m_pMemory - m_pMemory - 1;
    elementsToDelete[1].m_nAllocationCount = (int)elementsToDelete->m_pMemory;
    if ( v8 > 0 )
      _V_memmove(dest: &v7[m_pMemory + 1], src: &v7[m_pMemory], count: 4 * v8);
    v9 = (CDmxElement **)&elementsToDelete->m_pMemory[m_pMemory];
    if ( v9 != nullptr )
      *v9 = v2;
    v10 = 0;
    nCount = v2->m_Attributes.m_Size;
    i = 0;
    if ( nCount > 0 )
    {
      do
      {
        v11 = v2->m_Attributes.m_Memory.m_pMemory[v10];
        if ( v11->m_Type == AT_FIRST_VALUE_TYPE )
        {
          v12 = *(CDmxElement **)v11->m_pData;
          if ( v12 != nullptr )
            CDmxElement::AddElementsToDelete(
              this: v12,
              (CUtlVector<CDmxElement *,CUtlMemory<CDmxElement *,int> > *)elementsToDelete);
        }
        else if ( v11->m_Type == AT_FIRST_ARRAY_TYPE )
        {
          m_pData = v11->m_pData;
          v14 = m_pData[3];
          v15 = 0;
          for ( nElementCount = v14; v15 < v14; ++v15 )
          {
            if ( *(_DWORD *)(*m_pData + 4 * v15) != 0 )
            {
              CDmxElement::AddElementsToDelete(
                this: *(CDmxElement **)(*m_pData + 4 * v15),
                (CUtlVector<CDmxElement *,CUtlMemory<CDmxElement *,int> > *)elementsToDelete);
              v14 = nElementCount;
            }
          }
          v2 = this;
        }
        v10 = i + 1;
        i = v10;
      }
      while ( v10 < nCount );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00673460
// Name: public: class CUtlString const __near & CDmxElement::GetValue<class CUtlString>(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
const CUtlString *__thiscall CDmxElement::GetValue<CUtlString>(CDmxElement *this, const char *pAttributeName)
{
  int v3; // edi
  CDmxAttribute *v4; // eax
  CDmxAttribute v6; // [esp+8h] [ebp-Ch] BYREF

  CDmxElement::Resort(this);
  CDmxAttribute::CDmxAttribute(this: &v6, pAttributeName);
  pAttributeName = (const char *)&v6;
  v3 = CUtlSortVector<CDmxAttribute *,CDmxAttributeLess>::Find(
         this: &this->m_Attributes,
         src: (CDmxAttribute *const **)&pAttributeName);
  CDmxAttribute::~CDmxAttribute(this: &v6);
  if ( v3 >= 0 && (v4 = this->m_Attributes.m_Memory.m_pMemory[v3]) != nullptr )
  {
    if ( v4->m_Type == AT_STRING )
    {
      return (const CUtlString *)v4->m_pData;
    }
    else
    {
      if ( (`CDmxAttribute::GetValue<CUtlString>'::`4'::`local static guard' & 1) == 0 )
      {
        `CDmxAttribute::GetValue<CUtlString>'::`4'::`local static guard' |= 1u;
        CUtlString::CUtlString(this: &`CDmxAttribute::GetValue<CUtlString>'::`4'::defaultValue);
        atexit(func: `CDmxAttribute::GetValue<CUtlString>'::`4'::`dynamic atexit destructor for 'defaultValue'');
      }
      CUtlString::Set(this: &`CDmxAttribute::GetValue<CUtlString>'::`4'::defaultValue, pValue: nullptr);
      return &`CDmxAttribute::GetValue<CUtlString>'::`4'::defaultValue;
    }
  }
  else
  {
    if ( (`CDmxElement::GetValue<CUtlString>'::`4'::`local static guard' & 1) == 0 )
    {
      `CDmxElement::GetValue<CUtlString>'::`4'::`local static guard' |= 1u;
      CUtlString::CUtlString(this: &`CDmxElement::GetValue<CUtlString>'::`4'::defaultValue);
      atexit(func: `CDmxElement::GetValue<CUtlString>'::`4'::`dynamic atexit destructor for 'defaultValue'');
    }
    CUtlString::Set(this: &`CDmxElement::GetValue<CUtlString>'::`4'::defaultValue, pValue: nullptr);
    return &`CDmxElement::GetValue<CUtlString>'::`4'::defaultValue;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00673590
// Name: private: CDmxElement::CDmxElement(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDmxElement *__thiscall CDmxElement::CDmxElement(CDmxElement *this, char *pType)
{
  char *v4; // [esp-4h] [ebp-Ch]

  v4 = pType;
  this->m_Attributes.m_Memory.m_pMemory = nullptr;
  this->m_Attributes.m_Memory.m_nAllocationCount = 0;
  this->m_Attributes.m_Memory.m_nGrowSize = 0;
  this->m_Attributes.m_Size = 0;
  this->m_Attributes.m_pElements = nullptr;
  this->m_Attributes.m_pLessContext = nullptr;
  this->m_Attributes.m_bNeedsSort = false;
  this->m_Type.u.m_Id = -1;
  this->m_Type = (CUtlSymbolLarge)CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::AddString(
                                    this: &CDmxElement::s_TypeSymbols,
                                    result: (CUtlSymbolLarge *)&pType,
                                    pString: v4)->u.m_Id;
  *((_BYTE *)this + 49) &= 0xFCu;
  this->m_nLockCount = 0;
  CreateUniqueId(pDest: &this->m_Id);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x006735F0
// Name: public: char const __near * CDmxElement::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CDmxElement::GetName(CDmxElement *this)
{
  CUtlString *v1; // eax

  v1 = (CUtlString *)CDmxElement::GetValue<CUtlString>(this, pAttributeName: "name");
  return CUtlString::operator char const *(this: v1);
}

//------------------------------------------------------------------------------
// Address: 0x00673610
// Name: public: class CDmxAttribute __near * CDmxElement::AddAttribute(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDmxAttribute *__thiscall CDmxElement::AddAttribute(CDmxElement *this, CDmxAttribute *pAttributeName)
{
  const char *v3; // ebx
  int v4; // edi
  CDmxAttribute *v6; // eax
  const char *v7; // edi
  CDmxAttribute v9; // [esp+Ch] [ebp-Ch] BYREF

  CDmxElement::Resort(this);
  v3 = (const char *)pAttributeName;
  CDmxAttribute::CDmxAttribute(this: &v9, (const char *)pAttributeName);
  pAttributeName = &v9;
  v4 = CUtlSortVector<CDmxAttribute *,CDmxAttributeLess>::Find(
         this: &this->m_Attributes,
         src: (CDmxAttribute *const **)&pAttributeName);
  CDmxAttribute::~CDmxAttribute(this: &v9);
  if ( v4 >= 0 )
    return this->m_Attributes.m_Memory.m_pMemory[v4];
  ++this->m_nLockCount;
  *((_BYTE *)this + 49) |= 1u;
  v6 = (CDmxAttribute *)DMXAlloc(size: 0xCu);
  if ( v6 != nullptr )
    v7 = (const char *)CDmxAttribute::CDmxAttribute(this: v6, pAttributeName: v3);
  else
    v7 = nullptr;
  pAttributeName = (CDmxAttribute *)v7;
  CUtlSortVector<CDmxAttribute *,CDmxAttributeLess>::InsertNoSort(this: &this->m_Attributes, src: &pAttributeName);
  if ( this->m_nLockCount-- == 1 )
    CDmxElement::Resort(this);
  return (CDmxAttribute *)v7;
}

//------------------------------------------------------------------------------
// Address: 0x006736B0
// Name: public: void CDmxElement::UnpackIntoStructure(void __near *,struct DmxElementUnpackStructure_t const __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxElement::UnpackIntoStructure(CDmxElement *this, void *pData, CDmxAttribute *pUnpack)
{
  bool v3; // zf
  const char **p_m_Name; // edi
  CUtlString *v5; // ebx
  const char *v6; // eax
  const char *v7; // esi
  int v8; // esi
  CDmxAttribute *p_temp; // esi
  CUtlString *m_pData; // ecx
  const char *v11; // eax
  const char *v12; // eax
  const CUtlVector<float,CUtlMemory<float,int> > *v13; // eax
  int v14; // ecx
  int *p_m_nGrowSize; // edx
  DmAttributeType_t v16; // eax
  CDmxAttribute v17; // [esp+4h] [ebp-1Ch] BYREF
  CDmxAttribute temp; // [esp+10h] [ebp-10h] BYREF
  CDmxElement *v19; // [esp+1Ch] [ebp-4h]

  v3 = pUnpack->m_pData == nullptr;
  v19 = this;
  if ( !v3 )
  {
    p_m_Name = (const char **)&pUnpack->m_Name;
    while ( 1 )
    {
      v5 = (CUtlString *)&p_m_Name[2][(_DWORD)pData];
      if ( p_m_Name[8] == nullptr )
        break;
      CDmxElement::UnpackIntoStructure(this: v19, pData: v5, pUnpack: (const DmxElementUnpackStructure_t *)p_m_Name[8]);
LABEL_43:
      p_m_Name += 11;
      if ( p_m_Name[1] == nullptr )
        return;
    }
    v6 = p_m_Name[1];
    if ( (unsigned int)(v6 - 15) <= 0xD && (v6 == (const char *)19 || p_m_Name[4] != (const char *)-1)
      || v6 == (const char *)6
      || v6 == (const char *)20 )
    {
      goto LABEL_43;
    }
    CDmxAttribute::CDmxAttribute(this: &temp, pAttributeName: nullptr);
    v7 = *(p_m_Name - 1);
    CDmxElement::Resort(this: v19);
    CDmxAttribute::CDmxAttribute(this: &v17, pAttributeName: v7);
    pUnpack = &v17;
    v8 = CUtlSortVector<CDmxAttribute *,CDmxAttributeLess>::Find(
           this: &v19->m_Attributes,
           src: (CDmxAttribute *const **)&pUnpack);
    CDmxAttribute::~CDmxAttribute(this: &v17);
    if ( v8 < 0 || (p_temp = v19->m_Attributes.m_Memory.m_pMemory[v8]) == nullptr )
    {
      if ( *p_m_Name == nullptr )
      {
LABEL_42:
        CDmxAttribute::~CDmxAttribute(this: &temp);
        goto LABEL_43;
      }
      CDmxAttribute::AllocateDataMemory_AndConstruct(this: &temp, type: (DmAttributeType_t)p_m_Name[1]);
      if ( (unsigned int)(p_m_Name[1] - 15) > 0xD )
        CDmxAttribute::SetValueFromString(this: &temp, pValue: *p_m_Name);
      p_temp = &temp;
    }
    if ( p_m_Name[1] == (const char *)p_temp->m_Type )
    {
      if ( p_temp->m_Type == AT_STRING )
      {
        m_pData = (CUtlString *)p_temp->m_pData;
        if ( p_m_Name[3] == (const char *)-1 )
        {
          v11 = CUtlString::operator char const *(this: m_pData);
          CUtlString::operator=(this: v5, src: v11);
        }
        else
        {
          v12 = CUtlString::operator char const *(this: m_pData);
          V_strncpy(pDest: (char *)v5, pSrc: v12, maxLen: (int)p_m_Name[3]);
        }
      }
      else if ( CDmxAttribute::ArrayAttributeBasicType(type: p_temp->m_Type) == AT_FLOAT
             && p_m_Name[3] == (const char *)16 )
      {
        if ( (unsigned int)(p_m_Name[1] - 15) > 0xD )
        {
          v5->m_Storage.m_Memory.m_pMemory = *(unsigned __int8 **)p_temp->m_pData;
          v5->m_Storage.m_Memory.m_nAllocationCount = *(_DWORD *)p_temp->m_pData;
          v5->m_Storage.m_Memory.m_nGrowSize = *(_DWORD *)p_temp->m_pData;
          v5->m_Storage.m_nActualLength = *(_DWORD *)p_temp->m_pData;
        }
        else
        {
          v13 = CDmxAttribute::GetArray<float>(this: p_temp);
          v14 = 0;
          if ( (int)p_m_Name[9] > 0 )
          {
            p_m_nGrowSize = &v5->m_Storage.m_Memory.m_nGrowSize;
            do
            {
              *(p_m_nGrowSize - 2) = LODWORD(v13->m_Memory.m_pMemory[v14]);
              *(p_m_nGrowSize - 1) = LODWORD(v13->m_Memory.m_pMemory[v14]);
              *p_m_nGrowSize = LODWORD(v13->m_Memory.m_pMemory[v14]);
              p_m_nGrowSize[1] = LODWORD(v13->m_Memory.m_pMemory[v14++]);
              p_m_nGrowSize += 4;
            }
            while ( v14 < (int)p_m_Name[9] );
          }
        }
      }
      else
      {
        v16 = (DmAttributeType_t)p_m_Name[1];
        if ( (unsigned int)(v16 - 15) > 0xD )
        {
          if ( p_m_Name[4] == (const char *)-1 )
          {
            memcpy(
              dst: (unsigned __int8 *)v5,
              src: (unsigned __int8 *)p_temp->m_pData,
              count: (unsigned int)p_m_Name[3]);
          }
          else if ( p_temp->m_Type == AT_INT )
          {
            switch ( (unsigned int)p_m_Name[5] )
            {
              case 1u:
              case 3u:
                CDmxElement::UnpackBitfield<unsigned char>(
                  this: v19,
                  pDest: (unsigned __int8 *)v5,
                  pUnpack: (const DmxElementUnpackStructure_t *)(p_m_Name - 1),
                  pAttribute: p_temp);
                break;
              case 2u:
                goto $LN12_45;
              case 4u:
                CDmxElement::UnpackBitfield<short>(
                  this: v19,
                  pDest: (__int16 *)v5,
                  pUnpack: (const DmxElementUnpackStructure_t *)(p_m_Name - 1),
                  pAttribute: p_temp);
                break;
              case 5u:
                CDmxElement::UnpackBitfield<unsigned short>(
                  this: v19,
                  pDest: (unsigned __int16 *)v5,
                  pUnpack: (const DmxElementUnpackStructure_t *)(p_m_Name - 1),
                  pAttribute: p_temp);
                break;
              case 6u:
                CDmxElement::UnpackBitfield<int>(
                  this: v19,
                  pDest: (int *)v5,
                  pUnpack: (const DmxElementUnpackStructure_t *)(p_m_Name - 1),
                  pAttribute: p_temp);
                break;
              case 7u:
                CDmxElement::UnpackBitfield<unsigned int>(
                  this: v19,
                  pDest: (unsigned int *)v5,
                  pUnpack: (const DmxElementUnpackStructure_t *)(p_m_Name - 1),
                  pAttribute: p_temp);
                break;
              default:
                goto LABEL_42;
            }
          }
          else
          {
$LN12_45:
            CDmxElement::UnpackBitfield<char>(
              this: v19,
              pDest: (char *)v5,
              pUnpack: (const DmxElementUnpackStructure_t *)(p_m_Name - 1),
              pAttribute: p_temp);
          }
        }
        else
        {
          CDmxAttribute::GetArrayValue(
            this: p_temp,
            type: v16,
            pDest: v5,
            nDataTypeSize: (int)p_m_Name[3],
            nDestArrayLength: (int)p_m_Name[9],
            pDefaultString: *p_m_Name);
        }
      }
    }
    else
    {
      _Warning(
        a1: "CDmxElement::UnpackIntoStructure: Mismatched attribute type in attribute \"%s\"!\n",
        *(p_m_Name - 1));
    }
    goto LABEL_42;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00673960
// Name: private: void CDmxElement::RemoveAllElementsRecursive(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxElement::RemoveAllElementsRecursive(CDmxElement *this)
{
  int v1; // edi
  int v2; // ecx
  CDmxElement **m_pMemory; // eax
  CDmxElement *v4; // esi
  int m_Size; // ebx
  CDmxAttribute *v6; // ecx
  bool v8; // sf
  CDmxAttribute **v9; // eax
  CUtlVector<CDmxElement *,CUtlMemory<CDmxElement *,int> > elementsToDelete; // [esp+4h] [ebp-1Ch] BYREF
  int nCount; // [esp+18h] [ebp-8h]
  int i; // [esp+1Ch] [ebp-4h]

  v1 = 0;
  memset(&elementsToDelete, 0, sizeof(elementsToDelete));
  CDmxElement::AddElementsToDelete(this, (CUtlMemory<vgui::TreeNode *,int> *)&elementsToDelete);
  v2 = 0;
  nCount = elementsToDelete.m_Size;
  m_pMemory = elementsToDelete.m_Memory.m_pMemory;
  for ( i = 0; v2 < nCount; i = v2 )
  {
    v4 = m_pMemory[v2];
    if ( v4 != nullptr )
    {
      ++v4->m_nLockCount;
      m_Size = v4->m_Attributes.m_Size;
      if ( m_Size > 0 )
      {
        do
        {
          v6 = v4->m_Attributes.m_Memory.m_pMemory[v1];
          if ( v6 != nullptr )
            CDmxAttribute::~CDmxAttribute(this: v6);
          ++v1;
        }
        while ( v1 < m_Size );
      }
      *((_BYTE *)v4 + 49) &= ~1u;
      v4->m_Attributes.m_Size = 0;
      if ( v4->m_nLockCount-- == 1 )
        CDmxElement::Resort(this: v4);
      v8 = v4->m_Attributes.m_Memory.m_nGrowSize < 0;
      v4->m_Attributes.m_Size = 0;
      if ( !v8 )
      {
        if ( v4->m_Attributes.m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v4->m_Attributes.m_Memory.m_pMemory);
          v4->m_Attributes.m_Memory.m_pMemory = nullptr;
        }
        v4->m_Attributes.m_Memory.m_nAllocationCount = 0;
      }
      v8 = v4->m_Attributes.m_Memory.m_nGrowSize < 0;
      v9 = v4->m_Attributes.m_Memory.m_pMemory;
      v4->m_Attributes.m_pElements = v4->m_Attributes.m_Memory.m_pMemory;
      if ( !v8 )
      {
        if ( v9 != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v9);
          v4->m_Attributes.m_Memory.m_pMemory = nullptr;
        }
        v4->m_Attributes.m_Memory.m_nAllocationCount = 0;
      }
      m_pMemory = elementsToDelete.m_Memory.m_pMemory;
      v1 = 0;
    }
    v2 = i + 1;
  }
  elementsToDelete.m_Size = 0;
  if ( elementsToDelete.m_Memory.m_nGrowSize >= 0 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      m_pMemory = nullptr;
      elementsToDelete.m_Memory.m_pMemory = nullptr;
    }
    elementsToDelete.m_Memory.m_nAllocationCount = 0;
  }
  elementsToDelete.m_pElements = m_pMemory;
  if ( elementsToDelete.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x00681640
// Name: _dynamic_initializer_for__CDmxElement::s_TypeSymbols__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmxElement::s_TypeSymbols__()
{
  CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>(this: &CDmxElement::s_TypeSymbols);
  return atexit(func: dynamic_atexit_destructor_for__CDmxElement::s_TypeSymbols__);
}

//------------------------------------------------------------------------------
// Address: 0x00683660
// Name: _dynamic_atexit_destructor_for__CDmxElement::s_TypeSymbols__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmxElement::s_TypeSymbols__()
{
  CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::RemoveAll(this: &CDmxElement::s_TypeSymbols);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&CDmxElement::s_TypeSymbols.m_StringPools);
  CUtlTSHash<CUtlSymbolTableLargeBaseTreeEntry_t *,2048,CUtlSymbolTableLargeBaseTreeEntry_t *,CCThreadsafeTreeHashMethod<2048,CUtlSymbolTableLargeBaseTreeEntry_t *,0>,0>::RemoveAll(this: &CDmxElement::s_TypeSymbols.m_Lookup);
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmxElement::s_TypeSymbols.m_Lookup.m_EntryMemory);
}

} // namespace elementviewer

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x10246720
// Name: public: class CUtlSymbolLarge CUtlSymbolTableLargeBase<class CNonThreadsafeTree<0>,0>::Find(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
CUtlSymbolLarge *__thiscall CUtlSymbolTableLargeBase<CNonThreadsafeTree<0>,0>::Find(
        CUtlSymbolTableLargeBase<CNonThreadsafeTree<0>,0> *this,
        CUtlSymbolLarge *result,
        const char *pString)
{
  const char *v3; // ebx
  int v5; // eax
  int v6; // esi
  void *v7; // esp
  CUtlRBTree<CUtlSymbolTableLargeBaseTreeEntry_t *,int,CTreeEntryLess<CNonThreadsafeTree<0>,0>,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int>,int> > *v8; // esi
  int v9; // eax
  CUtlSymbolTableLargeBaseTreeEntry_t *m_Data; // ecx
  unsigned int v11; // [esp+0h] [ebp-10h] BYREF
  int v12; // [esp+4h] [ebp-Ch] BYREF
  CUtlRBTree<CUtlSymbolTableLargeBaseTreeEntry_t *,int,CTreeEntryLess<CNonThreadsafeTree<0>,0>,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int>,int> > *p_m_Lookup; // [esp+Ch] [ebp-4h]

  v3 = pString;
  p_m_Lookup = &this->m_Lookup;
  if ( pString == nullptr )
    goto LABEL_2;
  v5 = _V_strlen(str: pString);
  v6 = v5 + 1;
  v7 = alloca(v5 + 5);
  v11 = HashString(pszKey: v3);
  _V_memcpy(dest: &v12, src: v3, count: v6);
  v8 = p_m_Lookup;
  pString = (const char *)&v11;
  v9 = CUtlRBTree<CUtlSymbolTableLargeBaseTreeEntry_t *,int,CTreeEntryLess<CNonThreadsafeTree<0>,0>,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int>,int>>::Find(
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
// Address: 0x102467B0
// Name: public: void CUtlSymbolTableLargeBase<class CNonThreadsafeTree<0>,0>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlSymbolTableLargeBase<CNonThreadsafeTree<0>,0>::RemoveAll(
        CUtlSymbolTableLargeBase<CNonThreadsafeTree<0>,0> *this)
{
  int i; // edi

  CUtlRBTree<CUtlSymbolTableLargeBaseTreeEntry_t *,int,CTreeEntryLess<CNonThreadsafeTree<0>,0>,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int>,int>>::RemoveAll(this: &this->m_Lookup);
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
// Address: 0x10247750
// Name: public: class CUtlSymbolLarge CUtlSymbolTableLargeBase<class CNonThreadsafeTree<0>,0>::AddString(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CUtlSymbolLarge *__thiscall CUtlSymbolTableLargeBase<CNonThreadsafeTree<0>,0>::AddString(
        CUtlSymbolTableLargeBase<CNonThreadsafeTree<0>,0> *this,
        CUtlSymbolLarge *result,
        const char *pString)
{
  void *m_String; // ecx
  int v6; // eax
  signed int v7; // edi
  CUtlSymbolTableLargeBase<CNonThreadsafeTree<0>,0>::StringPool_t *v8; // eax
  CUtlVector<CUtlSymbolTableLargeBase<CNonThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CNonThreadsafeTree<0>,0>::StringPool_t *,int> > *p_m_StringPools; // esi
  unsigned int v10; // esi
  CUtlSymbolTableLargeBase<CNonThreadsafeTree<0>,0>::StringPool_t *v11; // edx
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CUtlSymbolTableLargeBase<CNonThreadsafeTree<0>,0>::StringPool_t **m_pMemory; // ecx
  int v15; // eax
  CUtlSymbolTableLargeBase<CNonThreadsafeTree<0>,0>::StringPool_t **v16; // eax
  unsigned int v17; // eax
  CUtlSymbolTableLargeBase<CNonThreadsafeTree<0>,0>::StringPool_t *v18; // ecx
  int m_SpaceUsed; // edx
  CUtlSymbolTableLargeBaseTreeEntry_t *v20; // esi
  int lenString; // [esp+8h] [ebp-Ch]
  int lenDecorated; // [esp+Ch] [ebp-8h]
  CUtlSymbolTableLargeBase<CNonThreadsafeTree<0>,0>::StringPool_t *pPool; // [esp+10h] [ebp-4h] BYREF

  if ( pString != nullptr )
  {
    CUtlSymbolTableLargeBase<CNonThreadsafeTree<0>,0>::Find(this, result: (CUtlSymbolLarge *)&pPool, pString);
    m_String = pPool;
    if ( pPool == (CUtlSymbolTableLargeBase<CNonThreadsafeTree<0>,0>::StringPool_t *)-1 )
    {
      v6 = _V_strlen(str: pString);
      lenString = v6 + 1;
      v7 = (v6 + 8) & 0xFFFFFFFC;
      v8 = nullptr;
      lenDecorated = v7;
      if ( this->m_StringPools.m_Size <= 0 )
        goto LABEL_10;
      p_m_StringPools = &this->m_StringPools;
      pPool = (CUtlSymbolTableLargeBase<CNonThreadsafeTree<0>,0>::StringPool_t *)this->m_StringPools.m_Memory.m_pMemory;
      while ( *(_DWORD *)pPool->m_TotalLen - *(_DWORD *)(pPool->m_TotalLen + 4) < v7 )
      {
        pPool = (CUtlSymbolTableLargeBase<CNonThreadsafeTree<0>,0>::StringPool_t *)((char *)pPool + 4);
        v8 = (CUtlSymbolTableLargeBase<CNonThreadsafeTree<0>,0>::StringPool_t *)((char *)v8 + 1);
        if ( (int)v8 >= this->m_StringPools.m_Size )
          goto LABEL_10;
      }
      pPool = v8;
      if ( v8 == (CUtlSymbolTableLargeBase<CNonThreadsafeTree<0>,0>::StringPool_t *)-1 )
      {
LABEL_10:
        v10 = v7 + 12;
        if ( (unsigned int)(v7 + 12) <= 0x800 )
          v10 = 2048;
        v11 = (CUtlSymbolTableLargeBase<CNonThreadsafeTree<0>,0>::StringPool_t *)MemAlloc_Alloc(nSize: v10);
        v11->m_TotalLen = v10 - 12;
        p_m_StringPools = &this->m_StringPools;
        v11->m_SpaceUsed = 0;
        m_Size = this->m_StringPools.m_Size;
        m_nAllocationCount = this->m_StringPools.m_Memory.m_nAllocationCount;
        pPool = v11;
        if ( m_Size + 1 > m_nAllocationCount )
        {
          CUtlMemory<INetMessage *,int>::Grow(
            this: (CUtlMemory<S3RGBA,int> *)&this->m_StringPools,
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
        pPool = (CUtlSymbolTableLargeBase<CNonThreadsafeTree<0>,0>::StringPool_t *)m_Size;
        v7 = lenDecorated;
      }
      v17 = HashString(pszKey: pString);
      v18 = p_m_StringPools->m_Memory.m_pMemory[(_DWORD)pPool];
      m_SpaceUsed = v18->m_SpaceUsed;
      v20 = (CUtlSymbolTableLargeBaseTreeEntry_t *)&v18->m_Data[m_SpaceUsed];
      v18->m_SpaceUsed = v7 + m_SpaceUsed;
      v20->m_Hash = v17;
      _V_memcpy(dest: (char *)&v18[1] + m_SpaceUsed, src: pString, count: lenString);
      m_String = this->m_Lookup.m_Elements.m_pMemory[CNonThreadsafeTree<0>::Insert(this: &this->m_Lookup, entry: v20)].m_Data->m_String;
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
// Address: 0x10248480
// Name: public: char const __near * CDmxElement::GetTypeString(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CDmxElement::GetTypeString(CDmxElement *this)
{
  const char *result; // eax

  result = this->m_Type.u.m_pAsString;
  if ( result == (const char *)-1 )
    return defaultValue;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10248490
// Name: public: struct UniqueId_t const __near & CDmxElement::GetId(void)const
// Source: json
//------------------------------------------------------------------------------
const UniqueId_t *__thiscall CDmxElement::GetId(CDmxElement *this)
{
  return &this->m_Id;
}

//------------------------------------------------------------------------------
// Address: 0x10248540
// Name: private: int CUtlTSHash<struct CUtlSymbolTableLargeBaseTreeEntry_t __near *,2048,struct CUtlSymbolTableLargeBaseTreeEntry_t __near *,class CCThreadsafeTreeHashMethod<2048,struct CUtlSymbolTableLargeBaseTreeEntry_t __near *,0>,0>::Find(struct CUtlSymbolTableLargeBaseTreeEntry_t __near *,struct CUtlTSHash<struct CUtlSymbolTableLargeBaseTreeEntry_t __near *,2048,struct CUtlSymbolTableLargeBaseTreeEntry_t __near *,class CCThreadsafeTreeHashMethod<2048,struct CUtlSymbolTableLargeBaseTreeEntry_t __near *,0>,0>::HashFixedDataInternal_t<struct CUtlSymbolTableLargeBaseTreeEntry_t __near *> __near *,struct CUtlTSHash<struct CUtlSymbolTableLargeBaseTreeEntry_t __near *,2048,struct CUtlSymbolTableLargeBaseTreeEntry_t __near *,class CCThreadsafeTreeHashMethod<2048,struct CUtlSymbolTableLargeBaseTreeEntry_t __near *,0>,0>::HashFixedDataInternal_t<struct CUtlSymbolTableLargeBaseTreeEntry_t __near *> __near *)
// Source: json
//------------------------------------------------------------------------------
CUtlTSHash<CUtlSymbolTableLargeBaseTreeEntry_t *,2048,CUtlSymbolTableLargeBaseTreeEntry_t *,CCThreadsafeTreeHashMethod<2048,CUtlSymbolTableLargeBaseTreeEntry_t *,0>,0>::HashFixedDataInternal_t<CUtlSymbolTableLargeBaseTreeEntry_t *> *__thiscall CUtlTSHash<CUtlSymbolTableLargeBaseTreeEntry_t *,2048,CUtlSymbolTableLargeBaseTreeEntry_t *,CCThreadsafeTreeHashMethod<2048,CUtlSymbolTableLargeBaseTreeEntry_t *,0>,0>::Find(
        CUtlTSHash<CUtlSymbolTableLargeBaseTreeEntry_t *,2048,CUtlSymbolTableLargeBaseTreeEntry_t *,CCThreadsafeTreeHashMethod<2048,CUtlSymbolTableLargeBaseTreeEntry_t *,0>,0> *this,
        CUtlSymbolTableLargeBaseTreeEntry_t *uiKey,
        CUtlTSHash<CUtlSymbolTableLargeBaseTreeEntry_t *,2048,CUtlSymbolTableLargeBaseTreeEntry_t *,CCThreadsafeTreeHashMethod<2048,CUtlSymbolTableLargeBaseTreeEntry_t *,0>,0>::HashFixedDataInternal_t<CUtlSymbolTableLargeBaseTreeEntry_t *> *pFirstElement,
        CUtlTSHash<CUtlSymbolTableLargeBaseTreeEntry_t *,2048,CUtlSymbolTableLargeBaseTreeEntry_t *,CCThreadsafeTreeHashMethod<2048,CUtlSymbolTableLargeBaseTreeEntry_t *,0>,0>::HashFixedDataInternal_t<CUtlSymbolTableLargeBaseTreeEntry_t *> *pLastElement)
{
  CUtlTSHash<CUtlSymbolTableLargeBaseTreeEntry_t *,2048,CUtlSymbolTableLargeBaseTreeEntry_t *,CCThreadsafeTreeHashMethod<2048,CUtlSymbolTableLargeBaseTreeEntry_t *,0>,0>::HashFixedDataInternal_t<CUtlSymbolTableLargeBaseTreeEntry_t *> *v4; // esi

  v4 = pFirstElement;
  if ( pFirstElement == pLastElement )
    return nullptr;
  while ( v4->m_uiKey->m_Hash != uiKey->m_Hash || _V_strcmp(s1: v4->m_uiKey->m_String, s2: uiKey->m_String) != 0 )
  {
    v4 = v4->m_pNext;
    if ( v4 == pLastElement )
      return nullptr;
  }
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x10248590
// Name: private: int CUtlTSHash<struct CUtlSymbolTableLargeBaseTreeEntry_t __near *,2048,struct CUtlSymbolTableLargeBaseTreeEntry_t __near *,class CCThreadsafeTreeHashMethod<2048,struct CUtlSymbolTableLargeBaseTreeEntry_t __near *,0>,0>::InsertUncommitted(struct CUtlSymbolTableLargeBaseTreeEntry_t __near *,struct CUtlTSHash<struct CUtlSymbolTableLargeBaseTreeEntry_t __near *,2048,struct CUtlSymbolTableLargeBaseTreeEntry_t __near *,class CCThreadsafeTreeHashMethod<2048,struct CUtlSymbolTableLargeBaseTreeEntry_t __near *,0>,0>::HashBucket_t __near &)
// Source: json
//------------------------------------------------------------------------------
CUtlTSHash<CUtlSymbolTableLargeBaseTreeEntry_t *,2048,CUtlSymbolTableLargeBaseTreeEntry_t *,CCThreadsafeTreeHashMethod<2048,CUtlSymbolTableLargeBaseTreeEntry_t *,0>,0>::HashFixedDataInternal_t<CUtlSymbolTableLargeBaseTreeEntry_t *> *__thiscall CUtlTSHash<CUtlSymbolTableLargeBaseTreeEntry_t *,2048,CUtlSymbolTableLargeBaseTreeEntry_t *,CCThreadsafeTreeHashMethod<2048,CUtlSymbolTableLargeBaseTreeEntry_t *,0>,0>::InsertUncommitted(
        CUtlTSHash<CUtlSymbolTableLargeBaseTreeEntry_t *,2048,CUtlSymbolTableLargeBaseTreeEntry_t *,CCThreadsafeTreeHashMethod<2048,CUtlSymbolTableLargeBaseTreeEntry_t *,0>,0> *this,
        CUtlSymbolTableLargeBaseTreeEntry_t *uiKey,
        CUtlTSHash<CUtlSymbolTableLargeBaseTreeEntry_t *,2048,CUtlSymbolTableLargeBaseTreeEntry_t *,CCThreadsafeTreeHashMethod<2048,CUtlSymbolTableLargeBaseTreeEntry_t *,0>,0>::HashBucket_t *bucket)
{
  CThreadFastMutex *p_m_mutex; // esi
  DWORD CurrentThreadId; // ecx
  CUtlTSHash<CUtlSymbolTableLargeBaseTreeEntry_t *,2048,CUtlSymbolTableLargeBaseTreeEntry_t *,CCThreadsafeTreeHashMethod<2048,CUtlSymbolTableLargeBaseTreeEntry_t *,0>,0>::HashFixedDataInternal_t<CUtlSymbolTableLargeBaseTreeEntry_t *> *result; // eax

  this->m_bNeedsCommit = true;
  p_m_mutex = &this->m_EntryMemory.m_mutex;
  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != p_m_mutex->m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)p_m_mutex, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(a1: p_m_mutex, a2: CurrentThreadId, a3: 0);
  }
  else
  {
    ++p_m_mutex->m_depth;
  }
  result = (CUtlTSHash<CUtlSymbolTableLargeBaseTreeEntry_t *,2048,CUtlSymbolTableLargeBaseTreeEntry_t *,CCThreadsafeTreeHashMethod<2048,CUtlSymbolTableLargeBaseTreeEntry_t *,0>,0>::HashFixedDataInternal_t<CUtlSymbolTableLargeBaseTreeEntry_t *> *)CUtlMemoryPool::Alloc(this: &this->m_EntryMemory);
  if ( p_m_mutex->m_depth-- == 1 )
    _InterlockedExchange((volatile __int32 *)p_m_mutex, 0);
  result->m_pNext = bucket->m_pFirstUncommitted;
  bucket->m_pFirstUncommitted = result;
  result->m_uiKey = uiKey;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10248600
// Name: public: void CUtlTSHash<struct CUtlSymbolTableLargeBaseTreeEntry_t __near *,2048,struct CUtlSymbolTableLargeBaseTreeEntry_t __near *,class CCThreadsafeTreeHashMethod<2048,struct CUtlSymbolTableLargeBaseTreeEntry_t __near *,0>,0>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlTSHash<CUtlSymbolTableLargeBaseTreeEntry_t *,2048,CUtlSymbolTableLargeBaseTreeEntry_t *,CCThreadsafeTreeHashMethod<2048,CUtlSymbolTableLargeBaseTreeEntry_t *,0>,0>::RemoveAll(
        CUtlTSHash<CUtlSymbolTableLargeBaseTreeEntry_t *,2048,CUtlSymbolTableLargeBaseTreeEntry_t *,CCThreadsafeTreeHashMethod<2048,CUtlSymbolTableLargeBaseTreeEntry_t *,0>,0> *this)
{
  CThreadSpinRWLock *p_m_AddLock; // esi
  int i; // edi
  unsigned int j; // eax
  CThreadFastMutex *p_m_mutex; // esi
  DWORD CurrentThreadId; // ecx

  this->m_bNeedsCommit = false;
  if ( this->m_EntryMemory.m_BlocksAllocated != 0 )
  {
    p_m_AddLock = &this->m_aBuckets[0].m_AddLock;
    for ( i = 2048; i != 0; --i )
    {
      if ( (p_m_AddLock->m_lockInfo.m_i32 & 0x10000) != 0
        || _InterlockedCompareExchange((volatile signed __int32 *)p_m_AddLock, 0x10000, 0) != 0 )
      {
        CThreadSpinRWLock::SpinLockForWrite(this: p_m_AddLock);
      }
      else
      {
        p_m_AddLock->m_writerId = GetCurrentThreadId();
      }
      for ( j = p_m_AddLock[-1].m_writerId; j != 0; j = *(_DWORD *)(j + 4) )
        ;
      p_m_AddLock[-1].m_lockInfo.m_i32 = 0;
      p_m_AddLock[-1].m_writerId = 0;
      p_m_AddLock->m_writerId = 0;
      p_m_AddLock->m_lockInfo.m_i32 = 0;
      p_m_AddLock += 2;
    }
    p_m_mutex = &this->m_EntryMemory.m_mutex;
    CurrentThreadId = GetCurrentThreadId();
    if ( CurrentThreadId != this->m_EntryMemory.m_mutex.m_ownerID
      && _InterlockedCompareExchange((volatile signed __int32 *)p_m_mutex, CurrentThreadId, 0) != 0 )
    {
      _mm_pause();
      CThreadFastMutex::Lock(a1: p_m_mutex, a2: CurrentThreadId, a3: 0);
    }
    else
    {
      ++this->m_EntryMemory.m_mutex.m_depth;
    }
    CUtlMemoryPool::Clear(this: &this->m_EntryMemory);
    if ( this->m_EntryMemory.m_mutex.m_depth-- == 1 )
      _InterlockedExchange((volatile __int32 *)p_m_mutex, 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102487F0
// Name: private: int CUtlSymbolTableLargeBase<class CThreadsafeTree<0>,0>::FindPoolWithSpace(int)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::FindPoolWithSpace(
        CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0> *this,
        int len)
{
  int m_Size; // esi
  int result; // eax
  CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t **i; // edx

  m_Size = this->m_StringPools.m_Size;
  result = 0;
  if ( m_Size <= 0 )
    return -1;
  for ( i = this->m_StringPools.m_Memory.m_pMemory; (*i)->m_TotalLen - (*i)->m_SpaceUsed < len; ++i )
  {
    if ( ++result >= m_Size )
      return -1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10248830
// Name: public: int CUtlTSHash<struct CUtlSymbolTableLargeBaseTreeEntry_t __near *,2048,struct CUtlSymbolTableLargeBaseTreeEntry_t __near *,class CCThreadsafeTreeHashMethod<2048,struct CUtlSymbolTableLargeBaseTreeEntry_t __near *,0>,0>::Insert(struct CUtlSymbolTableLargeBaseTreeEntry_t __near *,struct CUtlSymbolTableLargeBaseTreeEntry_t __near * const __near &,bool __near *)
// Source: json
//------------------------------------------------------------------------------
CUtlTSHash<CUtlSymbolTableLargeBaseTreeEntry_t *,2048,CUtlSymbolTableLargeBaseTreeEntry_t *,CCThreadsafeTreeHashMethod<2048,CUtlSymbolTableLargeBaseTreeEntry_t *,0>,0>::HashFixedDataInternal_t<CUtlSymbolTableLargeBaseTreeEntry_t *> *__thiscall CUtlTSHash<CUtlSymbolTableLargeBaseTreeEntry_t *,2048,CUtlSymbolTableLargeBaseTreeEntry_t *,CCThreadsafeTreeHashMethod<2048,CUtlSymbolTableLargeBaseTreeEntry_t *,0>,0>::Insert(
        CUtlTSHash<CUtlSymbolTableLargeBaseTreeEntry_t *,2048,CUtlSymbolTableLargeBaseTreeEntry_t *,CCThreadsafeTreeHashMethod<2048,CUtlSymbolTableLargeBaseTreeEntry_t *,0>,0> *this,
        CUtlSymbolTableLargeBaseTreeEntry_t *uiKey,
        CUtlSymbolTableLargeBaseTreeEntry_t **data,
        bool *pDidInsert)
{
  CUtlTSHash<CUtlSymbolTableLargeBaseTreeEntry_t *,2048,CUtlSymbolTableLargeBaseTreeEntry_t *,CCThreadsafeTreeHashMethod<2048,CUtlSymbolTableLargeBaseTreeEntry_t *,0>,0>::HashBucket_t *v5; // esi
  CUtlTSHash<CUtlSymbolTableLargeBaseTreeEntry_t *,2048,CUtlSymbolTableLargeBaseTreeEntry_t *,CCThreadsafeTreeHashMethod<2048,CUtlSymbolTableLargeBaseTreeEntry_t *,0>,0>::HashFixedDataInternal_t<CUtlSymbolTableLargeBaseTreeEntry_t *> *result; // eax
  CThreadSpinRWLock *p_m_AddLock; // ecx

  if ( pDidInsert != nullptr )
    *pDidInsert = false;
  v5 = &this->m_aBuckets[uiKey->m_Hash & 0x7FF];
  result = CUtlTSHash<CUtlSymbolTableLargeBaseTreeEntry_t *,2048,CUtlSymbolTableLargeBaseTreeEntry_t *,CCThreadsafeTreeHashMethod<2048,CUtlSymbolTableLargeBaseTreeEntry_t *,0>,0>::Find(
             this,
             uiKey,
             pFirstElement: v5->m_pFirst,
             pLastElement: nullptr);
  if ( result == nullptr )
  {
    CThreadSpinRWLock::LockForRead(this: &v5->m_AddLock);
    result = CUtlTSHash<CUtlSymbolTableLargeBaseTreeEntry_t *,2048,CUtlSymbolTableLargeBaseTreeEntry_t *,CCThreadsafeTreeHashMethod<2048,CUtlSymbolTableLargeBaseTreeEntry_t *,0>,0>::Find(
               this,
               uiKey,
               pFirstElement: v5->m_pFirstUncommitted,
               pLastElement: v5->m_pFirst);
    _InterlockedExchangeAdd((volatile signed __int32 *)&v5->m_AddLock, 0xFFFFFFFF);
    if ( result == nullptr )
    {
      p_m_AddLock = &v5->m_AddLock;
      if ( (v5->m_AddLock.m_lockInfo.m_i32 & 0x10000) != 0
        || _InterlockedCompareExchange((volatile signed __int32 *)p_m_AddLock, 0x10000, 0) != 0 )
      {
        CThreadSpinRWLock::SpinLockForWrite(this: p_m_AddLock);
      }
      else
      {
        v5->m_AddLock.m_writerId = GetCurrentThreadId();
      }
      result = CUtlTSHash<CUtlSymbolTableLargeBaseTreeEntry_t *,2048,CUtlSymbolTableLargeBaseTreeEntry_t *,CCThreadsafeTreeHashMethod<2048,CUtlSymbolTableLargeBaseTreeEntry_t *,0>,0>::Find(
                 this,
                 uiKey,
                 pFirstElement: v5->m_pFirstUncommitted,
                 pLastElement: v5->m_pFirst);
      if ( result == nullptr )
      {
        result = CUtlTSHash<CUtlSymbolTableLargeBaseTreeEntry_t *,2048,CUtlSymbolTableLargeBaseTreeEntry_t *,CCThreadsafeTreeHashMethod<2048,CUtlSymbolTableLargeBaseTreeEntry_t *,0>,0>::InsertUncommitted(
                   this,
                   uiKey,
                   bucket: v5);
        if ( result != (CUtlTSHash<CUtlSymbolTableLargeBaseTreeEntry_t *,2048,CUtlSymbolTableLargeBaseTreeEntry_t *,CCThreadsafeTreeHashMethod<2048,CUtlSymbolTableLargeBaseTreeEntry_t *,0>,0>::HashFixedDataInternal_t<CUtlSymbolTableLargeBaseTreeEntry_t *> *)-8 )
          result->m_Data = *data;
        if ( pDidInsert != nullptr )
          *pDidInsert = true;
      }
      v5->m_AddLock.m_writerId = 0;
      v5->m_AddLock.m_lockInfo.m_i32 = 0;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10248980
// Name: public: class CUtlSymbolLarge CUtlSymbolTableLargeBase<class CThreadsafeTree<0>,0>::Find(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
CUtlSymbolLarge *__thiscall CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::Find(
        CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0> *this,
        CUtlSymbolLarge *result,
        const char *pString)
{
  int v5; // eax
  int v6; // edi
  void *v7; // esp
  CUtlTSHash<CUtlSymbolTableLargeBaseTreeEntry_t *,2048,CUtlSymbolTableLargeBaseTreeEntry_t *,CCThreadsafeTreeHashMethod<2048,CUtlSymbolTableLargeBaseTreeEntry_t *,0>,0>::HashBucket_t *v8; // edi
  CUtlTSHash<CUtlSymbolTableLargeBaseTreeEntry_t *,2048,CUtlSymbolTableLargeBaseTreeEntry_t *,CCThreadsafeTreeHashMethod<2048,CUtlSymbolTableLargeBaseTreeEntry_t *,0>,0>::HashFixedDataInternal_t<CUtlSymbolTableLargeBaseTreeEntry_t *> *v9; // eax
  CUtlSymbolTableLargeBaseTreeEntry_t v10; // [esp+0h] [ebp-Ch] BYREF

  if ( pString == nullptr )
    goto LABEL_2;
  v5 = _V_strlen(str: pString);
  v6 = v5 + 1;
  v7 = alloca(v5 + 5);
  v10.m_Hash = HashString(pszKey: pString);
  _V_memcpy(dest: v10.m_String, src: pString, count: v6);
  v8 = &this->m_Lookup.m_aBuckets[v10.m_Hash & 0x7FF];
  v9 = CUtlTSHash<CUtlSymbolTableLargeBaseTreeEntry_t *,2048,CUtlSymbolTableLargeBaseTreeEntry_t *,CCThreadsafeTreeHashMethod<2048,CUtlSymbolTableLargeBaseTreeEntry_t *,0>,0>::Find(
         this: &this->m_Lookup,
         uiKey: &v10,
         pFirstElement: v8->m_pFirst,
         pLastElement: nullptr);
  if ( v9 != nullptr
    || (CThreadSpinRWLock::LockForRead(this: &v8->m_AddLock),
        v9 = CUtlTSHash<CUtlSymbolTableLargeBaseTreeEntry_t *,2048,CUtlSymbolTableLargeBaseTreeEntry_t *,CCThreadsafeTreeHashMethod<2048,CUtlSymbolTableLargeBaseTreeEntry_t *,0>,0>::Find(
               this: &this->m_Lookup,
               uiKey: &v10,
               pFirstElement: v8->m_pFirstUncommitted,
               pLastElement: v8->m_pFirst),
        _InterlockedExchangeAdd((volatile signed __int32 *)&v8->m_AddLock, 0xFFFFFFFF),
        v9 != nullptr) )
  {
    result->u.m_Id = (int)v9->m_Data->m_String;
    return result;
  }
  else
  {
LABEL_2:
    result->u.m_Id = -1;
    return result;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10248A40
// Name: public: void CUtlSymbolTableLargeBase<class CThreadsafeTree<0>,0>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::RemoveAll(
        CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0> *this)
{
  int v2; // edi

  CUtlTSHash<CUtlSymbolTableLargeBaseTreeEntry_t *,2048,CUtlSymbolTableLargeBaseTreeEntry_t *,CCThreadsafeTreeHashMethod<2048,CUtlSymbolTableLargeBaseTreeEntry_t *,0>,0>::RemoveAll(this: &this->m_Lookup);
  v2 = 0;
  if ( this->m_StringPools.m_Size <= 0 )
  {
    this->m_StringPools.m_Size = 0;
  }
  else
  {
    do
      free(pMem: this->m_StringPools.m_Memory.m_pMemory[v2++]);
    while ( v2 < this->m_StringPools.m_Size );
    this->m_StringPools.m_Size = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10248A90
// Name: private: void CDmxElement::Resort(void)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxElement::Resort(CDmxElement *this)
{
  signed int m_Size; // eax
  int i; // edi
  CDmxAttribute **v4; // eax
  const char *Name; // eax
  _DWORD context[2]; // [esp+4h] [ebp-Ch] BYREF
  char v7; // [esp+Fh] [ebp-1h] BYREF

  if ( (*((_BYTE *)this + 49) & 1) != 0 )
  {
    if ( this->m_Attributes.m_bNeedsSort )
    {
      m_Size = this->m_Attributes.m_Size;
      this->m_Attributes.m_bNeedsSort = false;
      if ( m_Size > 1 )
      {
        context[0] = this->m_Attributes.m_pLessContext;
        context[1] = &v7;
        qsort_s(
          base: this->m_Attributes.m_Memory.m_pMemory,
          num: m_Size,
          width: 4u,
          comp: (int (__cdecl *)(void *, const void *, const void *))CUtlSortVector<CDmxAttribute *,CDmxAttributeLess>::CompareHelper,
          context);
      }
    }
    *((_BYTE *)this + 49) &= ~1u;
    for ( i = this->m_Attributes.m_Size - 1; i >= 1; --i )
    {
      v4 = &this->m_Attributes.m_Memory.m_pMemory[i];
      if ( *v4 != nullptr && *(v4 - 1) != nullptr && (*v4)->m_Name.u.m_Id == (*(v4 - 1))->m_Name.u.m_Id )
      {
        Name = CDmxAttribute::GetName(this: *v4);
        _Warning(a1: "Duplicate attribute name %s encountered!\n", Name);
        if ( this->m_Attributes.m_Size - i - 1 > 0 )
          _V_memmove(
            dest: &this->m_Attributes.m_Memory.m_pMemory[i],
            src: &this->m_Attributes.m_Memory.m_pMemory[i + 1],
            count: 4 * (this->m_Attributes.m_Size - i - 1));
        --this->m_Attributes.m_Size;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10248B60
// Name: public: void CDmxElement::LockForChanges(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxElement::LockForChanges(CDmxElement *this, bool bLock)
{
  if ( bLock )
  {
    ++this->m_nLockCount;
  }
  else if ( this->m_nLockCount-- == 1 )
  {
    CDmxElement::Resort(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10248B80
// Name: public: bool CDmxElement::HasAttribute(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CDmxElement::HasAttribute(CDmxElement *this, const char *pAttributeName)
{
  int v3; // esi
  CDmxAttribute v5; // [esp+4h] [ebp-Ch] BYREF

  CDmxElement::Resort(this);
  CDmxAttribute::CDmxAttribute(this: &v5, pAttributeName);
  pAttributeName = (const char *)&v5;
  v3 = CUtlSortVector<CDmxAttribute *,CDmxAttributeLess>::Find(
         this: &this->m_Attributes,
         src: (CDmxAttribute *const **)&pAttributeName);
  CDmxAttribute::~CDmxAttribute(this: &v5);
  return v3 >= 0;
}

//------------------------------------------------------------------------------
// Address: 0x10248BD0
// Name: public: class CDmxAttribute const __near * CDmxElement::GetAttribute(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
const CDmxAttribute *__thiscall CDmxElement::GetAttribute(CDmxElement *this, const char *pAttributeName)
{
  int v3; // edi
  CDmxAttribute v5; // [esp+8h] [ebp-Ch] BYREF

  CDmxElement::Resort(this);
  CDmxAttribute::CDmxAttribute(this: &v5, pAttributeName);
  pAttributeName = (const char *)&v5;
  v3 = CUtlSortVector<CDmxAttribute *,CDmxAttributeLess>::Find(
         this: &this->m_Attributes,
         src: (CDmxAttribute *const **)&pAttributeName);
  CDmxAttribute::~CDmxAttribute(this: &v5);
  if ( v3 < 0 )
    return nullptr;
  else
    return this->m_Attributes.m_Memory.m_pMemory[v3];
}

//------------------------------------------------------------------------------
// Address: 0x10248C30
// Name: private: void CDmxElement::AddElementsToDelete(class CUtlVector<class CDmxElement __near *,class CUtlMemory<class CDmxElement __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxElement::AddElementsToDelete(CDmxElement *this, CUtlMemory<S3RGBA,int> *elementsToDelete)
{
  CDmxElement *v2; // ebx
  char v3; // al
  int m_pMemory; // esi
  int m_nAllocationCount; // eax
  CDmxElement **v7; // ecx
  int v8; // eax
  CDmxElement **v9; // esi
  int v10; // eax
  CDmxAttribute *v11; // eax
  CDmxElement *v12; // ecx
  _DWORD *m_pData; // ebx
  int v14; // ecx
  int v15; // esi
  int nCount; // [esp+4h] [ebp-Ch]
  int nElementCount; // [esp+8h] [ebp-8h]
  int i; // [esp+18h] [ebp+8h]

  v2 = this;
  v3 = *((_BYTE *)this + 49);
  if ( (v3 & 2) == 0 )
  {
    *((_BYTE *)this + 49) = v3 | 2;
    m_pMemory = (int)elementsToDelete[1].m_pMemory;
    m_nAllocationCount = elementsToDelete->m_nAllocationCount;
    if ( m_pMemory + 1 > m_nAllocationCount )
      CUtlMemory<INetMessage *,int>::Grow(this: elementsToDelete, num: m_pMemory - m_nAllocationCount + 1);
    ++elementsToDelete[1].m_pMemory;
    v7 = (CDmxElement **)elementsToDelete->m_pMemory;
    v8 = (int)elementsToDelete[1].m_pMemory - m_pMemory - 1;
    elementsToDelete[1].m_nAllocationCount = (int)elementsToDelete->m_pMemory;
    if ( v8 > 0 )
      _V_memmove(dest: &v7[m_pMemory + 1], src: &v7[m_pMemory], count: 4 * v8);
    v9 = (CDmxElement **)&elementsToDelete->m_pMemory[m_pMemory];
    if ( v9 != nullptr )
      *v9 = v2;
    v10 = 0;
    nCount = v2->m_Attributes.m_Size;
    i = 0;
    if ( nCount > 0 )
    {
      do
      {
        v11 = v2->m_Attributes.m_Memory.m_pMemory[v10];
        if ( v11->m_Type == AT_FIRST_VALUE_TYPE )
        {
          v12 = *(CDmxElement **)v11->m_pData;
          if ( v12 != nullptr )
            CDmxElement::AddElementsToDelete(
              this: v12,
              (CUtlVector<CDmxElement *,CUtlMemory<CDmxElement *,int> > *)elementsToDelete);
        }
        else if ( v11->m_Type == AT_FIRST_ARRAY_TYPE )
        {
          m_pData = v11->m_pData;
          v14 = m_pData[3];
          v15 = 0;
          for ( nElementCount = v14; v15 < v14; ++v15 )
          {
            if ( *(_DWORD *)(*m_pData + 4 * v15) != 0 )
            {
              CDmxElement::AddElementsToDelete(
                this: *(CDmxElement **)(*m_pData + 4 * v15),
                (CUtlVector<CDmxElement *,CUtlMemory<CDmxElement *,int> > *)elementsToDelete);
              v14 = nElementCount;
            }
          }
          v2 = this;
        }
        v10 = i + 1;
        i = v10;
      }
      while ( v10 < nCount );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10248D20
// Name: public: CUtlSymbolTableLargeBase<class CThreadsafeTree<0>,0>::CUtlSymbolTableLargeBase<class CThreadsafeTree<0>,0>(void)
// Source: json
//------------------------------------------------------------------------------
CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0> *__thiscall CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>(
        CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0> *this)
{
  CUtlTSHash<CUtlSymbolTableLargeBaseTreeEntry_t *,2048,CUtlSymbolTableLargeBaseTreeEntry_t *,CCThreadsafeTreeHashMethod<2048,CUtlSymbolTableLargeBaseTreeEntry_t *,0>,0>::HashBucket_t *m_aBuckets; // eax
  int v3; // edx
  CThreadSpinRWLock *p_m_AddLock; // ecx
  int i; // ecx

  CUtlMemoryPool::CUtlMemoryPool(
    this: &this->m_Lookup.m_EntryMemory,
    blockSize: 12,
    numElements: 32,
    growMode: 2,
    pszAllocOwner: nullptr,
    nAlignment: 0);
  m_aBuckets = this->m_Lookup.m_aBuckets;
  this->m_Lookup.m_EntryMemory.m_mutex.m_ownerID = 0;
  this->m_Lookup.m_EntryMemory.m_mutex.m_depth = 0;
  v3 = 2047;
  p_m_AddLock = &this->m_Lookup.m_aBuckets[0].m_AddLock;
  do
  {
    p_m_AddLock->m_lockInfo.m_i32 = 0;
    p_m_AddLock->m_writerId = 0;
    p_m_AddLock += 2;
    --v3;
  }
  while ( v3 >= 0 );
  this->m_Lookup.m_bNeedsCommit = false;
  for ( i = 2048; i != 0; --i )
  {
    m_aBuckets->m_pFirst = nullptr;
    m_aBuckets->m_pFirstUncommitted = nullptr;
    ++m_aBuckets;
  }
  this->m_StringPools.m_Memory.m_pMemory = nullptr;
  this->m_StringPools.m_Memory.m_nAllocationCount = 0;
  this->m_StringPools.m_Size = 0;
  this->m_StringPools.m_pElements = nullptr;
  this->m_StringPools.m_Memory.m_nGrowSize = 8;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10248DA0
// Name: public: class CUtlSymbolLarge CUtlSymbolTableLargeBase<class CThreadsafeTree<0>,0>::AddString(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CUtlSymbolLarge *__thiscall CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::AddString(
        CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0> *this,
        CUtlSymbolLarge *result,
        char *pString)
{
  const char *v3; // esi
  void *m_String; // ecx
  int v7; // eax
  unsigned int v8; // edi
  int PoolWithSpace; // esi
  unsigned int v10; // esi
  CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *v11; // edx
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t **m_pMemory; // ecx
  int v15; // eax
  CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t **v16; // eax
  unsigned int v17; // eax
  CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *v18; // ecx
  int m_SpaceUsed; // edx
  char *v20; // esi
  const char *v21; // ecx
  int lenString; // [esp+8h] [ebp-Ch]
  int lenDecorated; // [esp+Ch] [ebp-8h]
  CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *pPool; // [esp+10h] [ebp-4h] BYREF

  v3 = pString;
  if ( pString != nullptr )
  {
    CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::Find(this, result: (CUtlSymbolLarge *)&pPool, pString);
    m_String = pPool;
    if ( pPool == (CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *)-1 )
    {
      v7 = _V_strlen(str: v3) + 1;
      v8 = (v7 + 7) & 0xFFFFFFFC;
      lenString = v7;
      lenDecorated = v8;
      PoolWithSpace = CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::FindPoolWithSpace(this, len: v8);
      if ( PoolWithSpace == -1 )
      {
        v10 = v8 + 12;
        if ( v8 + 12 <= 0x800 )
          v10 = 2048;
        v11 = (CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *)MemAlloc_Alloc(nSize: v10);
        v11->m_TotalLen = v10 - 12;
        v11->m_SpaceUsed = 0;
        m_Size = this->m_StringPools.m_Size;
        m_nAllocationCount = this->m_StringPools.m_Memory.m_nAllocationCount;
        pPool = v11;
        if ( m_Size + 1 > m_nAllocationCount )
        {
          CUtlMemory<INetMessage *,int>::Grow(
            this: (CUtlMemory<S3RGBA,int> *)&this->m_StringPools,
            num: m_Size - m_nAllocationCount + 1);
          v11 = pPool;
        }
        ++this->m_StringPools.m_Size;
        m_pMemory = this->m_StringPools.m_Memory.m_pMemory;
        v15 = this->m_StringPools.m_Size - m_Size - 1;
        this->m_StringPools.m_pElements = m_pMemory;
        if ( v15 > 0 )
        {
          _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v15);
          v11 = pPool;
        }
        v16 = &this->m_StringPools.m_Memory.m_pMemory[m_Size];
        if ( v16 != nullptr )
          *v16 = v11;
        PoolWithSpace = m_Size;
        v8 = lenDecorated;
      }
      v17 = HashString(pszKey: pString);
      v18 = this->m_StringPools.m_Memory.m_pMemory[PoolWithSpace];
      m_SpaceUsed = v18->m_SpaceUsed;
      v20 = &v18->m_Data[m_SpaceUsed];
      v18->m_SpaceUsed = v8 + m_SpaceUsed;
      v21 = pString;
      *(_DWORD *)v20 = v17;
      _V_memcpy(dest: v20 + 4, src: v21, count: lenString);
      pString = v20;
      m_String = CUtlTSHash<CUtlSymbolTableLargeBaseTreeEntry_t *,2048,CUtlSymbolTableLargeBaseTreeEntry_t *,CCThreadsafeTreeHashMethod<2048,CUtlSymbolTableLargeBaseTreeEntry_t *,0>,0>::Insert(
                   this: &this->m_Lookup,
                   uiKey: (CUtlSymbolTableLargeBaseTreeEntry_t *)v20,
                   data: (CUtlSymbolTableLargeBaseTreeEntry_t **)&pString,
                   pDidInsert: nullptr)->m_Data->m_String;
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
// Address: 0x10248FE0
// Name: private: CDmxElement::CDmxElement(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDmxElement *__thiscall CDmxElement::CDmxElement(CDmxElement *this, char *pType)
{
  char *v4; // [esp-4h] [ebp-Ch]

  v4 = pType;
  this->m_Attributes.m_Memory.m_pMemory = nullptr;
  this->m_Attributes.m_Memory.m_nAllocationCount = 0;
  this->m_Attributes.m_Memory.m_nGrowSize = 0;
  this->m_Attributes.m_Size = 0;
  this->m_Attributes.m_pElements = nullptr;
  this->m_Attributes.m_pLessContext = nullptr;
  this->m_Attributes.m_bNeedsSort = false;
  this->m_Type.u.m_Id = -1;
  this->m_Type = (CUtlSymbolLarge)CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::AddString(
                                    this: &CDmxElement::s_TypeSymbols,
                                    result: (CUtlSymbolLarge *)&pType,
                                    pString: v4)->u.m_Id;
  *((_BYTE *)this + 49) &= 0xFCu;
  this->m_nLockCount = 0;
  CreateUniqueId(pDest: &this->m_Id);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10249040
// Name: public: char const __near * CDmxElement::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CDmxElement::GetName(CDmxElement *this)
{
  CUtlString *v1; // eax

  v1 = (CUtlString *)CDmxElement::GetValue<CUtlString>(this, pAttributeName: "name");
  return CUtlString::operator char const *(this: v1);
}

//------------------------------------------------------------------------------
// Address: 0x10249060
// Name: public: class CDmxAttribute __near * CDmxElement::AddAttribute(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDmxAttribute *__thiscall CDmxElement::AddAttribute(CDmxElement *this, CDmxAttribute *pAttributeName)
{
  const char *v3; // ebx
  int v4; // edi
  unsigned __int8 *v6; // eax
  const char *v7; // edi
  CDmxAttribute v9; // [esp+Ch] [ebp-Ch] BYREF

  CDmxElement::Resort(this);
  v3 = (const char *)pAttributeName;
  CDmxAttribute::CDmxAttribute(this: &v9, (const char *)pAttributeName);
  pAttributeName = &v9;
  v4 = CUtlSortVector<CDmxAttribute *,CDmxAttributeLess>::Find(
         this: &this->m_Attributes,
         src: (CDmxAttribute *const **)&pAttributeName);
  CDmxAttribute::~CDmxAttribute(this: &v9);
  if ( v4 >= 0 )
    return this->m_Attributes.m_Memory.m_pMemory[v4];
  ++this->m_nLockCount;
  *((_BYTE *)this + 49) |= 1u;
  v6 = DMXAlloc(size: 0xCu);
  if ( v6 != nullptr )
    v7 = (const char *)CDmxAttribute::CDmxAttribute(this: (CDmxAttribute *)v6, pAttributeName: v3);
  else
    v7 = nullptr;
  pAttributeName = (CDmxAttribute *)v7;
  CUtlSortVector<CDmxAttribute *,CDmxAttributeLess>::InsertNoSort(this: &this->m_Attributes, src: &pAttributeName);
  if ( this->m_nLockCount-- == 1 )
    CDmxElement::Resort(this);
  return (CDmxAttribute *)v7;
}

//------------------------------------------------------------------------------
// Address: 0x10249100
// Name: class CDmxElement __near * CreateDmxElement(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDmxElement *__cdecl CreateDmxElement(char *pType)
{
  unsigned __int8 *v1; // esi
  CUtlSymbolLarge v3; // [esp+8h] [ebp-4h] BYREF

  v1 = DMXAlloc(size: 0x34u);
  if ( v1 == nullptr )
    return nullptr;
  *(_DWORD *)v1 = 0;
  *((_DWORD *)v1 + 1) = 0;
  *((_DWORD *)v1 + 2) = 0;
  *((_DWORD *)v1 + 3) = 0;
  *((_DWORD *)v1 + 4) = 0;
  *((_DWORD *)v1 + 5) = 0;
  v1[24] = 0;
  *((_DWORD *)v1 + 11) = -1;
  *((CUtlSymbolLarge *)v1 + 11) = (CUtlSymbolLarge)CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::AddString(
                                                     this: &CDmxElement::s_TypeSymbols,
                                                     result: &v3,
                                                     pString: pType)->u.m_Id;
  v1[49] &= 0xFCu;
  v1[48] = 0;
  CreateUniqueId(pDest: (UniqueId_t *)(v1 + 28));
  return (CDmxElement *)v1;
}

//------------------------------------------------------------------------------
// Address: 0x10249170
// Name: public: void CDmxElement::SetName(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxElement::SetName(CDmxElement *this, const char *pName)
{
  CDmxAttribute *v3; // edi
  CUtlString *m_pData; // ecx
  CUtlString string; // [esp+8h] [ebp-10h] BYREF

  CUtlString::CUtlString(this: &string, pString: pName);
  ++this->m_nLockCount;
  v3 = CDmxElement::AddAttribute(this, pAttributeName: (CDmxAttribute *)"name");
  CDmxAttribute::AllocateDataMemory(this: v3, type: AT_STRING);
  m_pData = (CUtlString *)v3->m_pData;
  if ( m_pData != nullptr )
    CUtlString::CUtlString(this: m_pData, &string);
  if ( this->m_nLockCount-- == 1 )
    CDmxElement::Resort(this);
  string.m_Storage.m_nActualLength = 0;
  if ( string.m_Storage.m_Memory.m_nGrowSize >= 0 && string.m_Storage.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: string.m_Storage.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x102491F0
// Name: private: void CDmxElement::RemoveAllElementsRecursive(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxElement::RemoveAllElementsRecursive(CDmxElement *this)
{
  int v1; // edi
  int v2; // ecx
  CDmxElement **m_pMemory; // eax
  CDmxElement *v4; // esi
  int m_Size; // ebx
  CDmxAttribute *v6; // ecx
  bool v8; // sf
  CDmxAttribute **v9; // eax
  CUtlVector<CDmxElement *,CUtlMemory<CDmxElement *,int> > elementsToDelete; // [esp+4h] [ebp-1Ch] BYREF
  int nCount; // [esp+18h] [ebp-8h]
  int i; // [esp+1Ch] [ebp-4h]

  v1 = 0;
  memset(&elementsToDelete, 0, sizeof(elementsToDelete));
  CDmxElement::AddElementsToDelete(this, (CUtlMemory<S3RGBA,int> *)&elementsToDelete);
  v2 = 0;
  nCount = elementsToDelete.m_Size;
  m_pMemory = elementsToDelete.m_Memory.m_pMemory;
  for ( i = 0; v2 < nCount; i = v2 )
  {
    v4 = m_pMemory[v2];
    if ( v4 != nullptr )
    {
      ++v4->m_nLockCount;
      m_Size = v4->m_Attributes.m_Size;
      if ( m_Size > 0 )
      {
        do
        {
          v6 = v4->m_Attributes.m_Memory.m_pMemory[v1];
          if ( v6 != nullptr )
            CDmxAttribute::~CDmxAttribute(this: v6);
          ++v1;
        }
        while ( v1 < m_Size );
      }
      *((_BYTE *)v4 + 49) &= ~1u;
      v4->m_Attributes.m_Size = 0;
      if ( v4->m_nLockCount-- == 1 )
        CDmxElement::Resort(this: v4);
      v8 = v4->m_Attributes.m_Memory.m_nGrowSize < 0;
      v4->m_Attributes.m_Size = 0;
      if ( !v8 )
      {
        if ( v4->m_Attributes.m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v4->m_Attributes.m_Memory.m_pMemory);
          v4->m_Attributes.m_Memory.m_pMemory = nullptr;
        }
        v4->m_Attributes.m_Memory.m_nAllocationCount = 0;
      }
      v8 = v4->m_Attributes.m_Memory.m_nGrowSize < 0;
      v9 = v4->m_Attributes.m_Memory.m_pMemory;
      v4->m_Attributes.m_pElements = v4->m_Attributes.m_Memory.m_pMemory;
      if ( !v8 )
      {
        if ( v9 != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v9);
          v4->m_Attributes.m_Memory.m_pMemory = nullptr;
        }
        v4->m_Attributes.m_Memory.m_nAllocationCount = 0;
      }
      m_pMemory = elementsToDelete.m_Memory.m_pMemory;
      v1 = 0;
    }
    v2 = i + 1;
  }
  elementsToDelete.m_Size = 0;
  if ( elementsToDelete.m_Memory.m_nGrowSize >= 0 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      m_pMemory = nullptr;
      elementsToDelete.m_Memory.m_pMemory = nullptr;
    }
    elementsToDelete.m_Memory.m_nAllocationCount = 0;
  }
  elementsToDelete.m_pElements = m_pMemory;
  if ( elementsToDelete.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
}

} // namespace engine_xlsp

// ============================================================
// Overlay from hammer_dll (Missing functions)
// ============================================================
namespace hammer_dll {

//------------------------------------------------------------------------------
// Address: 0x10214B30
// Name: public: class Vector const __near & CDmxElement::GetValue<class Vector>(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
const Vector *__thiscall CDmxElement::GetValue<Vector>(CDmxElement *this, const char *pAttributeName)
{
  const CDmxAttribute *Attribute; // eax

  Attribute = CDmxElement::GetAttribute(this, pAttributeName);
  if ( Attribute != nullptr )
  {
    if ( Attribute->m_Type == AT_VECTOR3 )
    {
      return (const Vector *)Attribute->m_pData;
    }
    else
    {
      if ( (`CDmxAttribute::GetValue<Vector>'::`4'::`local static guard' & 1) == 0 )
        `CDmxAttribute::GetValue<Vector>'::`4'::`local static guard' |= 1u;
      `CDmxAttribute::GetValue<Vector>'::`4'::defaultValue = 0;
      dword_107D7570 = 0;
      dword_107D7574 = 0;
      return (const Vector *)&`CDmxAttribute::GetValue<Vector>'::`4'::defaultValue;
    }
  }
  else
  {
    if ( (`CDmxElement::GetValue<Vector>'::`4'::`local static guard' & 1) == 0 )
      `CDmxElement::GetValue<Vector>'::`4'::`local static guard' |= 1u;
    `CDmxElement::GetValue<Vector>'::`4'::defaultValue.x = 0.0;
    `CDmxElement::GetValue<Vector>'::`4'::defaultValue.y = 0.0;
    `CDmxElement::GetValue<Vector>'::`4'::defaultValue.z = 0.0;
    return &`CDmxElement::GetValue<Vector>'::`4'::defaultValue;
  }
}

//------------------------------------------------------------------------------
// Address: 0x104C06B0
// Name: public: char const __near * CDmxElement::GetTypeString(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CDmxElement::GetTypeString(CDmxElement *this)
{
  const char *result; // eax

  result = this->m_Type.u.m_pAsString;
  if ( result == (const char *)-1 )
    return &var;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104C06C0
// Name: public: struct UniqueId_t const __near & CDmxElement::GetId(void)const
// Source: json
//------------------------------------------------------------------------------
const UniqueId_t *__thiscall CDmxElement::GetId(CDmxElement *this)
{
  return &this->m_Id;
}

//------------------------------------------------------------------------------
// Address: 0x104C06D0
// Name: private: void CDmxElement::SetId(struct UniqueId_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxElement::SetId(CDmxElement *this, const UniqueId_t *id)
{
  CopyUniqueId(src: id, pDest: &this->m_Id);
}

//------------------------------------------------------------------------------
// Address: 0x104C06F0
// Name: private: void CDmxElement::UnpackBitfield<unsigned char>(unsigned char __near *,struct DmxElementUnpackStructure_t const __near *,class CDmxAttribute const __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxElement::UnpackBitfield<unsigned char>(
        CDmxElement *this,
        unsigned __int8 *pDest,
        const DmxElementUnpackStructure_t *pUnpack,
        const CDmxAttribute *pAttribute)
{
  int m_nSize; // ecx
  char v6; // bl
  char v7; // al
  unsigned __int8 v8; // al
  char mask_3; // [esp+1Bh] [ebp+Fh]

  m_nSize = pUnpack->m_nSize;
  if ( m_nSize == 8 )
  {
    v6 = -1;
    v7 = -1;
  }
  else
  {
    v6 = (1 << m_nSize) - 1;
    v7 = v6 << pUnpack->m_nBitOffset;
  }
  mask_3 = ~v7;
  v8 = *(_BYTE *)pAttribute->m_pData;
  if ( ((unsigned __int8)~v6 & v8) != 0 )
  {
    _Warning(a1: "Value %s exeeds size of datatype. \n", pUnpack->m_pAttributeName);
    v8 = 0;
  }
  *pDest &= mask_3;
  *pDest |= ((unsigned __int8)v6 & v8) << pUnpack->m_nBitOffset;
}

//------------------------------------------------------------------------------
// Address: 0x104C0760
// Name: private: void CDmxElement::UnpackBitfield<char>(char __near *,struct DmxElementUnpackStructure_t const __near *,class CDmxAttribute const __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxElement::UnpackBitfield<char>(
        CDmxElement *this,
        char *pDest,
        const DmxElementUnpackStructure_t *pUnpack,
        const CDmxAttribute *pAttribute)
{
  int m_nSize; // edx
  char v6; // bl
  char v7; // al
  char v8; // al
  char v9; // dl
  char mask_3; // [esp+1Bh] [ebp+Fh]

  m_nSize = pUnpack->m_nSize;
  if ( m_nSize == 8 )
  {
    v6 = -1;
    v7 = -1;
  }
  else
  {
    v6 = (1 << m_nSize) - 1;
    v7 = v6 << pUnpack->m_nBitOffset;
  }
  mask_3 = ~v7;
  v8 = *(_BYTE *)pAttribute->m_pData;
  v9 = (1 << (m_nSize - 1)) - 1;
  if ( v8 < 0 )
  {
    if ( (~v9 & v8) != ~v9 )
    {
LABEL_8:
      _Warning(a1: "Value %s exeeds size of datatype. \n", pUnpack->m_pAttributeName);
      v8 = 0;
    }
  }
  else if ( (~v9 & v8) != 0 )
  {
    goto LABEL_8;
  }
  *pDest &= mask_3;
  *pDest |= ((unsigned __int8)v6 & (unsigned __int8)v8) << pUnpack->m_nBitOffset;
}

//------------------------------------------------------------------------------
// Address: 0x104C07F0
// Name: private: void CDmxElement::UnpackBitfield<short>(short __near *,struct DmxElementUnpackStructure_t const __near *,class CDmxAttribute const __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxElement::UnpackBitfield<short>(
        CDmxElement *this,
        __int16 *pDest,
        const DmxElementUnpackStructure_t *pUnpack,
        const CDmxAttribute *pAttribute)
{
  int m_nSize; // edx
  __int16 v5; // bx
  __int16 v6; // ax
  __int16 v7; // di
  __int16 v8; // ax
  int v9; // ecx
  bool v10; // zf

  m_nSize = pUnpack->m_nSize;
  if ( m_nSize == 16 )
  {
    v5 = -1;
    v6 = -1;
  }
  else
  {
    v5 = (1 << m_nSize) - 1;
    v6 = v5 << pUnpack->m_nBitOffset;
  }
  v7 = ~v6;
  v8 = *(_WORD *)pAttribute->m_pData;
  v9 = ~(__int16)((1 << (m_nSize - 1)) - 1);
  if ( v8 < 0 )
    v10 = (v9 & v8) == v9;
  else
    v10 = (v9 & v8) == 0;
  if ( !v10 )
  {
    _Warning(a1: "Value %s exeeds size of datatype. \n", pUnpack->m_pAttributeName);
    v8 = 0;
  }
  *pDest &= v7;
  *pDest |= ((unsigned __int16)v5 & (unsigned __int16)v8) << pUnpack->m_nBitOffset;
}

//------------------------------------------------------------------------------
// Address: 0x104C0890
// Name: private: void CDmxElement::UnpackBitfield<unsigned short>(unsigned short __near *,struct DmxElementUnpackStructure_t const __near *,class CDmxAttribute const __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxElement::UnpackBitfield<unsigned short>(
        CDmxElement *this,
        unsigned __int16 *pDest,
        const DmxElementUnpackStructure_t *pUnpack,
        const CDmxAttribute *pAttribute)
{
  int m_nSize; // ecx
  unsigned __int16 v5; // si
  __int16 v6; // ax
  __int16 v7; // bx
  int v8; // ecx

  m_nSize = pUnpack->m_nSize;
  if ( m_nSize == 16 )
  {
    v5 = -1;
    v6 = -1;
  }
  else
  {
    v5 = (1 << m_nSize) - 1;
    v6 = v5 << pUnpack->m_nBitOffset;
  }
  v7 = ~v6;
  v8 = *(unsigned __int16 *)pAttribute->m_pData;
  if ( (~v5 & v8) != 0 )
  {
    _Warning(a1: "Value %s exeeds size of datatype. \n", pUnpack->m_pAttributeName);
    LOWORD(v8) = 0;
  }
  *pDest &= v7;
  *pDest |= (v5 & (unsigned __int16)v8) << pUnpack->m_nBitOffset;
}

//------------------------------------------------------------------------------
// Address: 0x104C0910
// Name: private: void CDmxElement::UnpackBitfield<int>(int __near *,struct DmxElementUnpackStructure_t const __near *,class CDmxAttribute const __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxElement::UnpackBitfield<int>(
        CDmxElement *this,
        int *pDest,
        const DmxElementUnpackStructure_t *pUnpack,
        const CDmxAttribute *pAttribute)
{
  int m_nSize; // edx
  int v5; // esi
  int v6; // eax
  int v7; // ebx
  int v8; // eax
  int v9; // edx
  bool v10; // zf

  m_nSize = pUnpack->m_nSize;
  if ( m_nSize == 32 )
  {
    v5 = -1;
    v6 = -1;
  }
  else
  {
    v5 = (1 << m_nSize) - 1;
    v6 = v5 << pUnpack->m_nBitOffset;
  }
  v7 = ~v6;
  v8 = *(_DWORD *)pAttribute->m_pData;
  v9 = ~((1 << (m_nSize - 1)) - 1);
  if ( v8 < 0 )
    v10 = (v8 & v9) == v9;
  else
    v10 = (v9 & v8) == 0;
  if ( !v10 )
  {
    _Warning(a1: "Value %s exeeds size of datatype. \n", pUnpack->m_pAttributeName);
    v8 = 0;
  }
  *pDest &= v7;
  *pDest |= (v5 & v8) << pUnpack->m_nBitOffset;
}

//------------------------------------------------------------------------------
// Address: 0x104C0990
// Name: private: void CDmxElement::UnpackBitfield<unsigned int>(unsigned int __near *,struct DmxElementUnpackStructure_t const __near *,class CDmxAttribute const __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxElement::UnpackBitfield<unsigned int>(
        CDmxElement *this,
        unsigned int *pDest,
        const DmxElementUnpackStructure_t *pUnpack,
        const CDmxAttribute *pAttribute)
{
  int m_nSize; // ecx
  int v5; // esi
  int v6; // eax
  int v7; // edi
  int v8; // eax

  m_nSize = pUnpack->m_nSize;
  if ( m_nSize == 32 )
  {
    v5 = -1;
    v6 = -1;
  }
  else
  {
    v5 = (1 << m_nSize) - 1;
    v6 = v5 << pUnpack->m_nBitOffset;
  }
  v7 = ~v6;
  v8 = *(_DWORD *)pAttribute->m_pData;
  if ( (~v5 & v8) != 0 )
  {
    _Warning(a1: "Value %s exeeds size of datatype. \n", pUnpack->m_pAttributeName);
    v8 = 0;
  }
  *pDest &= v7;
  *pDest |= (v5 & v8) << pUnpack->m_nBitOffset;
}

//------------------------------------------------------------------------------
// Address: 0x104C0C20
// Name: private: void CDmxElement::Resort(void)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxElement::Resort(CDmxElement *this)
{
  signed int m_Size; // eax
  int i; // edi
  CDmxAttribute **v4; // eax
  const char *Name; // eax
  _DWORD context[2]; // [esp+4h] [ebp-Ch] BYREF
  char v7; // [esp+Fh] [ebp-1h] BYREF

  if ( (*((_BYTE *)this + 49) & 1) != 0 )
  {
    if ( this->m_Attributes.m_bNeedsSort )
    {
      m_Size = this->m_Attributes.m_Size;
      this->m_Attributes.m_bNeedsSort = false;
      if ( m_Size > 1 )
      {
        context[0] = this->m_Attributes.m_pLessContext;
        context[1] = &v7;
        qsort_s(
          base: (char *)this->m_Attributes.m_Memory.m_pMemory,
          num: m_Size,
          width: 4u,
          comp: (int (__cdecl *)(void *, const void *, const void *))CUtlSortVector<CDmxAttribute *,CDmxAttributeLess>::CompareHelper,
          context);
      }
    }
    *((_BYTE *)this + 49) &= ~1u;
    for ( i = this->m_Attributes.m_Size - 1; i >= 1; --i )
    {
      v4 = &this->m_Attributes.m_Memory.m_pMemory[i];
      if ( *v4 != nullptr && *(v4 - 1) != nullptr && (*v4)->m_Name.u.m_Id == (*(v4 - 1))->m_Name.u.m_Id )
      {
        Name = CDmxAttribute::GetName(this: *v4);
        _Warning(a1: "Duplicate attribute name %s encountered!\n", Name);
        if ( this->m_Attributes.m_Size - i - 1 > 0 )
          _V_memmove(
            dest: &this->m_Attributes.m_Memory.m_pMemory[i],
            src: &this->m_Attributes.m_Memory.m_pMemory[i + 1],
            count: 4 * (this->m_Attributes.m_Size - i - 1));
        --this->m_Attributes.m_Size;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x104C0CF0
// Name: public: void CDmxElement::LockForChanges(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxElement::LockForChanges(CDmxElement *this, bool bLock)
{
  if ( bLock )
  {
    ++this->m_nLockCount;
  }
  else if ( this->m_nLockCount-- == 1 )
  {
    CDmxElement::Resort(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x104C0D10
// Name: public: bool CDmxElement::HasAttribute(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CDmxElement::HasAttribute(CDmxElement *this, const char *pAttributeName)
{
  int v3; // esi
  CDmxAttribute v5; // [esp+4h] [ebp-Ch] BYREF

  CDmxElement::Resort(this);
  CDmxAttribute::CDmxAttribute(this: &v5, pAttributeName);
  pAttributeName = (const char *)&v5;
  v3 = CUtlSortVector<CDmxAttribute *,CDmxAttributeLess>::Find(
         this: &this->m_Attributes,
         src: (CDmxAttribute *const **)&pAttributeName);
  CDmxAttribute::~CDmxAttribute(this: &v5);
  return v3 >= 0;
}

//------------------------------------------------------------------------------
// Address: 0x104C0D60
// Name: public: class CDmxAttribute const __near * CDmxElement::GetAttribute(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
const CDmxAttribute *__thiscall CDmxElement::GetAttribute(CDmxElement *this, const char *pAttributeName)
{
  int v3; // edi
  CDmxAttribute v5; // [esp+8h] [ebp-Ch] BYREF

  CDmxElement::Resort(this);
  CDmxAttribute::CDmxAttribute(this: &v5, pAttributeName);
  pAttributeName = (const char *)&v5;
  v3 = CUtlSortVector<CDmxAttribute *,CDmxAttributeLess>::Find(
         this: &this->m_Attributes,
         src: (CDmxAttribute *const **)&pAttributeName);
  CDmxAttribute::~CDmxAttribute(this: &v5);
  if ( v3 < 0 )
    return nullptr;
  else
    return this->m_Attributes.m_Memory.m_pMemory[v3];
}

//------------------------------------------------------------------------------
// Address: 0x104C0DC0
// Name: private: void CDmxElement::AddElementsToDelete(class CUtlVector<class CDmxElement __near *,class CUtlMemory<class CDmxElement __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxElement::AddElementsToDelete(CDmxElement *this, CUtlMemory<vgui::TreeNode *,int> *elementsToDelete)
{
  CDmxElement *v2; // ebx
  char v3; // al
  int m_pMemory; // esi
  int m_nAllocationCount; // eax
  CDmxElement **v7; // ecx
  int v8; // eax
  CDmxElement **v9; // esi
  int v10; // eax
  CDmxAttribute *v11; // eax
  CDmxElement *v12; // ecx
  _DWORD *m_pData; // ebx
  int v14; // ecx
  int v15; // esi
  int nCount; // [esp+4h] [ebp-Ch]
  int nElementCount; // [esp+8h] [ebp-8h]
  int i; // [esp+18h] [ebp+8h]

  v2 = this;
  v3 = *((_BYTE *)this + 49);
  if ( (v3 & 2) == 0 )
  {
    *((_BYTE *)this + 49) = v3 | 2;
    m_pMemory = (int)elementsToDelete[1].m_pMemory;
    m_nAllocationCount = elementsToDelete->m_nAllocationCount;
    if ( m_pMemory + 1 > m_nAllocationCount )
      CUtlMemory<IDmFormatUpdater *,int>::Grow(this: elementsToDelete, num: m_pMemory - m_nAllocationCount + 1);
    ++elementsToDelete[1].m_pMemory;
    v7 = (CDmxElement **)elementsToDelete->m_pMemory;
    v8 = (int)elementsToDelete[1].m_pMemory - m_pMemory - 1;
    elementsToDelete[1].m_nAllocationCount = (int)elementsToDelete->m_pMemory;
    if ( v8 > 0 )
      _V_memmove(dest: &v7[m_pMemory + 1], src: &v7[m_pMemory], count: 4 * v8);
    v9 = (CDmxElement **)&elementsToDelete->m_pMemory[m_pMemory];
    if ( v9 != nullptr )
      *v9 = v2;
    v10 = 0;
    nCount = v2->m_Attributes.m_Size;
    i = 0;
    if ( nCount > 0 )
    {
      do
      {
        v11 = v2->m_Attributes.m_Memory.m_pMemory[v10];
        if ( v11->m_Type == AT_FIRST_VALUE_TYPE )
        {
          v12 = *(CDmxElement **)v11->m_pData;
          if ( v12 != nullptr )
            CDmxElement::AddElementsToDelete(
              this: v12,
              (CUtlVector<CDmxElement *,CUtlMemory<CDmxElement *,int> > *)elementsToDelete);
        }
        else if ( v11->m_Type == AT_FIRST_ARRAY_TYPE )
        {
          m_pData = v11->m_pData;
          v14 = m_pData[3];
          v15 = 0;
          for ( nElementCount = v14; v15 < v14; ++v15 )
          {
            if ( *(_DWORD *)(*m_pData + 4 * v15) != 0 )
            {
              CDmxElement::AddElementsToDelete(
                this: *(CDmxElement **)(*m_pData + 4 * v15),
                (CUtlVector<CDmxElement *,CUtlMemory<CDmxElement *,int> > *)elementsToDelete);
              v14 = nElementCount;
            }
          }
          v2 = this;
        }
        v10 = i + 1;
        i = v10;
      }
      while ( v10 < nCount );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x104C0EB0
// Name: public: class CUtlString const __near & CDmxElement::GetValue<class CUtlString>(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
const CUtlString *__thiscall CDmxElement::GetValue<CUtlString>(CDmxElement *this, const char *pAttributeName)
{
  int v3; // edi
  CDmxAttribute *v4; // eax
  CDmxAttribute v6; // [esp+8h] [ebp-Ch] BYREF

  CDmxElement::Resort(this);
  CDmxAttribute::CDmxAttribute(this: &v6, pAttributeName);
  pAttributeName = (const char *)&v6;
  v3 = CUtlSortVector<CDmxAttribute *,CDmxAttributeLess>::Find(
         this: &this->m_Attributes,
         src: (CDmxAttribute *const **)&pAttributeName);
  CDmxAttribute::~CDmxAttribute(this: &v6);
  if ( v3 >= 0 && (v4 = this->m_Attributes.m_Memory.m_pMemory[v3]) != nullptr )
  {
    if ( v4->m_Type == AT_STRING )
    {
      return (const CUtlString *)v4->m_pData;
    }
    else
    {
      if ( (`CDmxAttribute::GetValue<CUtlString>'::`4'::`local static guard' & 1) == 0 )
      {
        `CDmxAttribute::GetValue<CUtlString>'::`4'::`local static guard' |= 1u;
        CUtlString::CUtlString(this: &`CDmxAttribute::GetValue<CUtlString>'::`4'::defaultValue);
        atexit(func: `CDmxAttribute::GetValue<CUtlString>'::`4'::`dynamic atexit destructor for 'defaultValue'');
      }
      CUtlString::Set(this: &`CDmxAttribute::GetValue<CUtlString>'::`4'::defaultValue, pValue: nullptr);
      return &`CDmxAttribute::GetValue<CUtlString>'::`4'::defaultValue;
    }
  }
  else
  {
    if ( (`CDmxElement::GetValue<CUtlString>'::`4'::`local static guard' & 1) == 0 )
    {
      `CDmxElement::GetValue<CUtlString>'::`4'::`local static guard' |= 1u;
      CUtlString::CUtlString(this: &`CDmxElement::GetValue<CUtlString>'::`4'::defaultValue);
      atexit(func: `CDmxElement::GetValue<CUtlString>'::`4'::`dynamic atexit destructor for 'defaultValue'');
    }
    CUtlString::Set(this: &`CDmxElement::GetValue<CUtlString>'::`4'::defaultValue, pValue: nullptr);
    return &`CDmxElement::GetValue<CUtlString>'::`4'::defaultValue;
  }
}

//------------------------------------------------------------------------------
// Address: 0x104C0FE0
// Name: private: CDmxElement::CDmxElement(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDmxElement *__thiscall CDmxElement::CDmxElement(CDmxElement *this, char *pType)
{
  char *v4; // [esp-4h] [ebp-Ch]

  v4 = pType;
  this->m_Attributes.m_Memory.m_pMemory = nullptr;
  this->m_Attributes.m_Memory.m_nAllocationCount = 0;
  this->m_Attributes.m_Memory.m_nGrowSize = 0;
  this->m_Attributes.m_Size = 0;
  this->m_Attributes.m_pElements = nullptr;
  this->m_Attributes.m_pLessContext = nullptr;
  this->m_Attributes.m_bNeedsSort = false;
  this->m_Type.u.m_Id = -1;
  this->m_Type = (CUtlSymbolLarge)CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::AddString(
                                    this: &CDmxElement::s_TypeSymbols,
                                    result: (CUtlSymbolLarge *)&pType,
                                    pString: v4)->u.m_Id;
  *((_BYTE *)this + 49) &= 0xFCu;
  this->m_nLockCount = 0;
  CreateUniqueId(pDest: &this->m_Id);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x104C1040
// Name: public: char const __near * CDmxElement::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CDmxElement::GetName(CDmxElement *this)
{
  CUtlString *v1; // eax

  v1 = (CUtlString *)CDmxElement::GetValue<CUtlString>(this, pAttributeName: "name");
  return CUtlString::operator char const *(this: v1);
}

//------------------------------------------------------------------------------
// Address: 0x104C1060
// Name: public: class CDmxAttribute __near * CDmxElement::AddAttribute(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDmxAttribute *__thiscall CDmxElement::AddAttribute(CDmxElement *this, CDmxAttribute *pAttributeName)
{
  const char *v3; // ebx
  int v4; // edi
  CDmxAttribute *v6; // eax
  const char *v7; // edi
  CDmxAttribute v9; // [esp+Ch] [ebp-Ch] BYREF

  CDmxElement::Resort(this);
  v3 = (const char *)pAttributeName;
  CDmxAttribute::CDmxAttribute(this: &v9, (const char *)pAttributeName);
  pAttributeName = &v9;
  v4 = CUtlSortVector<CDmxAttribute *,CDmxAttributeLess>::Find(
         this: &this->m_Attributes,
         src: (CDmxAttribute *const **)&pAttributeName);
  CDmxAttribute::~CDmxAttribute(this: &v9);
  if ( v4 >= 0 )
    return this->m_Attributes.m_Memory.m_pMemory[v4];
  ++this->m_nLockCount;
  *((_BYTE *)this + 49) |= 1u;
  v6 = (CDmxAttribute *)DMXAlloc(size: 0xCu);
  if ( v6 != nullptr )
    v7 = (const char *)CDmxAttribute::CDmxAttribute(this: v6, pAttributeName: v3);
  else
    v7 = nullptr;
  pAttributeName = (CDmxAttribute *)v7;
  CUtlSortVector<CDmxAttribute *,CDmxAttributeLess>::InsertNoSort(this: &this->m_Attributes, src: &pAttributeName);
  if ( this->m_nLockCount-- == 1 )
    CDmxElement::Resort(this);
  return (CDmxAttribute *)v7;
}

//------------------------------------------------------------------------------
// Address: 0x104C1100
// Name: public: void CDmxElement::UnpackIntoStructure(void __near *,struct DmxElementUnpackStructure_t const __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxElement::UnpackIntoStructure(CDmxElement *this, void *pData, CDmxAttribute *pUnpack)
{
  bool v3; // zf
  const char **p_m_Name; // edi
  CUtlString *v5; // ebx
  const char *v6; // eax
  const char *v7; // esi
  int v8; // esi
  CDmxAttribute *p_temp; // esi
  CUtlString *m_pData; // ecx
  const char *v11; // eax
  const char *v12; // eax
  const CUtlVector<float,CUtlMemory<float,int> > *v13; // eax
  int v14; // ecx
  int *p_m_nGrowSize; // edx
  DmAttributeType_t v16; // eax
  CDmxAttribute v17; // [esp+4h] [ebp-1Ch] BYREF
  CDmxAttribute temp; // [esp+10h] [ebp-10h] BYREF
  CDmxElement *v19; // [esp+1Ch] [ebp-4h]

  v3 = pUnpack->m_pData == nullptr;
  v19 = this;
  if ( !v3 )
  {
    p_m_Name = (const char **)&pUnpack->m_Name;
    while ( 1 )
    {
      v5 = (CUtlString *)&p_m_Name[2][(_DWORD)pData];
      if ( p_m_Name[8] == nullptr )
        break;
      CDmxElement::UnpackIntoStructure(this: v19, pData: v5, pUnpack: (const DmxElementUnpackStructure_t *)p_m_Name[8]);
LABEL_43:
      p_m_Name += 11;
      if ( p_m_Name[1] == nullptr )
        return;
    }
    v6 = p_m_Name[1];
    if ( (unsigned int)(v6 - 15) <= 0xD && (v6 == (const char *)19 || p_m_Name[4] != (const char *)-1)
      || v6 == (const char *)6
      || v6 == (const char *)20 )
    {
      goto LABEL_43;
    }
    CDmxAttribute::CDmxAttribute(this: &temp, pAttributeName: nullptr);
    v7 = *(p_m_Name - 1);
    CDmxElement::Resort(this: v19);
    CDmxAttribute::CDmxAttribute(this: &v17, pAttributeName: v7);
    pUnpack = &v17;
    v8 = CUtlSortVector<CDmxAttribute *,CDmxAttributeLess>::Find(
           this: &v19->m_Attributes,
           src: (CDmxAttribute *const **)&pUnpack);
    CDmxAttribute::~CDmxAttribute(this: &v17);
    if ( v8 < 0 || (p_temp = v19->m_Attributes.m_Memory.m_pMemory[v8]) == nullptr )
    {
      if ( *p_m_Name == nullptr )
      {
LABEL_42:
        CDmxAttribute::~CDmxAttribute(this: &temp);
        goto LABEL_43;
      }
      CDmxAttribute::AllocateDataMemory_AndConstruct(this: &temp, type: (DmAttributeType_t)p_m_Name[1]);
      if ( (unsigned int)(p_m_Name[1] - 15) > 0xD )
        CDmxAttribute::SetValueFromString(this: &temp, pValue: *p_m_Name);
      p_temp = &temp;
    }
    if ( p_m_Name[1] == (const char *)p_temp->m_Type )
    {
      if ( p_temp->m_Type == AT_STRING )
      {
        m_pData = (CUtlString *)p_temp->m_pData;
        if ( p_m_Name[3] == (const char *)-1 )
        {
          v11 = CUtlString::operator char const *(this: m_pData);
          CUtlString::operator=(this: v5, src: v11);
        }
        else
        {
          v12 = CUtlString::operator char const *(this: m_pData);
          V_strncpy(pDest: (char *)v5, pSrc: v12, maxLen: (int)p_m_Name[3]);
        }
      }
      else if ( CDmxAttribute::ArrayAttributeBasicType(type: p_temp->m_Type) == AT_FLOAT
             && p_m_Name[3] == (const char *)16 )
      {
        if ( (unsigned int)(p_m_Name[1] - 15) > 0xD )
        {
          v5->m_Storage.m_Memory.m_pMemory = *(unsigned __int8 **)p_temp->m_pData;
          v5->m_Storage.m_Memory.m_nAllocationCount = *(_DWORD *)p_temp->m_pData;
          v5->m_Storage.m_Memory.m_nGrowSize = *(_DWORD *)p_temp->m_pData;
          v5->m_Storage.m_nActualLength = *(_DWORD *)p_temp->m_pData;
        }
        else
        {
          v13 = CDmxAttribute::GetArray<float>(this: p_temp);
          v14 = 0;
          if ( (int)p_m_Name[9] > 0 )
          {
            p_m_nGrowSize = &v5->m_Storage.m_Memory.m_nGrowSize;
            do
            {
              *(p_m_nGrowSize - 2) = LODWORD(v13->m_Memory.m_pMemory[v14]);
              *(p_m_nGrowSize - 1) = LODWORD(v13->m_Memory.m_pMemory[v14]);
              *p_m_nGrowSize = LODWORD(v13->m_Memory.m_pMemory[v14]);
              p_m_nGrowSize[1] = LODWORD(v13->m_Memory.m_pMemory[v14++]);
              p_m_nGrowSize += 4;
            }
            while ( v14 < (int)p_m_Name[9] );
          }
        }
      }
      else
      {
        v16 = (DmAttributeType_t)p_m_Name[1];
        if ( (unsigned int)(v16 - 15) > 0xD )
        {
          if ( p_m_Name[4] == (const char *)-1 )
          {
            memcpy(
              dst: (unsigned __int8 *)v5,
              src: (unsigned __int8 *)p_temp->m_pData,
              count: (unsigned int)p_m_Name[3]);
          }
          else if ( p_temp->m_Type == AT_INT )
          {
            switch ( (unsigned int)p_m_Name[5] )
            {
              case 1u:
              case 3u:
                CDmxElement::UnpackBitfield<unsigned char>(
                  this: v19,
                  pDest: (unsigned __int8 *)v5,
                  pUnpack: (const DmxElementUnpackStructure_t *)(p_m_Name - 1),
                  pAttribute: p_temp);
                break;
              case 2u:
                goto $LN12_103;
              case 4u:
                CDmxElement::UnpackBitfield<short>(
                  this: v19,
                  pDest: (__int16 *)v5,
                  pUnpack: (const DmxElementUnpackStructure_t *)(p_m_Name - 1),
                  pAttribute: p_temp);
                break;
              case 5u:
                CDmxElement::UnpackBitfield<unsigned short>(
                  this: v19,
                  pDest: (unsigned __int16 *)v5,
                  pUnpack: (const DmxElementUnpackStructure_t *)(p_m_Name - 1),
                  pAttribute: p_temp);
                break;
              case 6u:
                CDmxElement::UnpackBitfield<int>(
                  this: v19,
                  pDest: (int *)v5,
                  pUnpack: (const DmxElementUnpackStructure_t *)(p_m_Name - 1),
                  pAttribute: p_temp);
                break;
              case 7u:
                CDmxElement::UnpackBitfield<unsigned int>(
                  this: v19,
                  pDest: (unsigned int *)v5,
                  pUnpack: (const DmxElementUnpackStructure_t *)(p_m_Name - 1),
                  pAttribute: p_temp);
                break;
              default:
                goto LABEL_42;
            }
          }
          else
          {
$LN12_103:
            CDmxElement::UnpackBitfield<char>(
              this: v19,
              pDest: (char *)v5,
              pUnpack: (const DmxElementUnpackStructure_t *)(p_m_Name - 1),
              pAttribute: p_temp);
          }
        }
        else
        {
          CDmxAttribute::GetArrayValue(
            this: p_temp,
            type: v16,
            pDest: v5,
            nDataTypeSize: (int)p_m_Name[3],
            nDestArrayLength: (int)p_m_Name[9],
            pDefaultString: *p_m_Name);
        }
      }
    }
    else
    {
      _Warning(
        a1: "CDmxElement::UnpackIntoStructure: Mismatched attribute type in attribute \"%s\"!\n",
        *(p_m_Name - 1));
    }
    goto LABEL_42;
  }
}

//------------------------------------------------------------------------------
// Address: 0x104C13B0
// Name: private: void CDmxElement::RemoveAllElementsRecursive(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxElement::RemoveAllElementsRecursive(CDmxElement *this)
{
  int v1; // edi
  int v2; // ecx
  CDmxElement **m_pMemory; // eax
  CDmxElement *v4; // esi
  int m_Size; // ebx
  CDmxAttribute *v6; // ecx
  bool v8; // sf
  CDmxAttribute **v9; // eax
  CUtlVector<CDmxElement *,CUtlMemory<CDmxElement *,int> > elementsToDelete; // [esp+4h] [ebp-1Ch] BYREF
  int nCount; // [esp+18h] [ebp-8h]
  int i; // [esp+1Ch] [ebp-4h]

  v1 = 0;
  memset(&elementsToDelete, 0, sizeof(elementsToDelete));
  CDmxElement::AddElementsToDelete(this, (CUtlMemory<vgui::TreeNode *,int> *)&elementsToDelete);
  v2 = 0;
  nCount = elementsToDelete.m_Size;
  m_pMemory = elementsToDelete.m_Memory.m_pMemory;
  for ( i = 0; v2 < nCount; i = v2 )
  {
    v4 = m_pMemory[v2];
    if ( v4 != nullptr )
    {
      ++v4->m_nLockCount;
      m_Size = v4->m_Attributes.m_Size;
      if ( m_Size > 0 )
      {
        do
        {
          v6 = v4->m_Attributes.m_Memory.m_pMemory[v1];
          if ( v6 != nullptr )
            CDmxAttribute::~CDmxAttribute(this: v6);
          ++v1;
        }
        while ( v1 < m_Size );
      }
      *((_BYTE *)v4 + 49) &= ~1u;
      v4->m_Attributes.m_Size = 0;
      if ( v4->m_nLockCount-- == 1 )
        CDmxElement::Resort(this: v4);
      v8 = v4->m_Attributes.m_Memory.m_nGrowSize < 0;
      v4->m_Attributes.m_Size = 0;
      if ( !v8 )
      {
        if ( v4->m_Attributes.m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v4->m_Attributes.m_Memory.m_pMemory);
          v4->m_Attributes.m_Memory.m_pMemory = nullptr;
        }
        v4->m_Attributes.m_Memory.m_nAllocationCount = 0;
      }
      v8 = v4->m_Attributes.m_Memory.m_nGrowSize < 0;
      v9 = v4->m_Attributes.m_Memory.m_pMemory;
      v4->m_Attributes.m_pElements = v4->m_Attributes.m_Memory.m_pMemory;
      if ( !v8 )
      {
        if ( v9 != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v9);
          v4->m_Attributes.m_Memory.m_pMemory = nullptr;
        }
        v4->m_Attributes.m_Memory.m_nAllocationCount = 0;
      }
      m_pMemory = elementsToDelete.m_Memory.m_pMemory;
      v1 = 0;
    }
    v2 = i + 1;
  }
  elementsToDelete.m_Size = 0;
  if ( elementsToDelete.m_Memory.m_nGrowSize >= 0 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      m_pMemory = nullptr;
      elementsToDelete.m_Memory.m_pMemory = nullptr;
    }
    elementsToDelete.m_Memory.m_nAllocationCount = 0;
  }
  elementsToDelete.m_pElements = m_pMemory;
  if ( elementsToDelete.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x105C6940
// Name: _dynamic_initializer_for__CDmxElement::s_TypeSymbols__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmxElement::s_TypeSymbols__()
{
  CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>(this: &CDmxElement::s_TypeSymbols);
  return atexit(func: dynamic_atexit_destructor_for__CDmxElement::s_TypeSymbols__);
}

//------------------------------------------------------------------------------
// Address: 0x105CCAF0
// Name: _dynamic_atexit_destructor_for__CDmxElement::s_TypeSymbols__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmxElement::s_TypeSymbols__()
{
  CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::RemoveAll(this: &CDmxElement::s_TypeSymbols);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&CDmxElement::s_TypeSymbols.m_StringPools);
  CUtlTSHash<CUtlSymbolTableLargeBaseTreeEntry_t *,2048,CUtlSymbolTableLargeBaseTreeEntry_t *,CCThreadsafeTreeHashMethod<2048,CUtlSymbolTableLargeBaseTreeEntry_t *,0>,0>::RemoveAll(this: &CDmxElement::s_TypeSymbols.m_Lookup);
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmxElement::s_TypeSymbols.m_Lookup.m_EntryMemory);
}

} // namespace hammer_dll

// ============================================================
// Overlay from missionchooser (Missing functions)
// ============================================================
namespace missionchooser {

//------------------------------------------------------------------------------
// Address: 0x100F5540
// Name: public: void CUtlSymbolTableLargeBase<class CNonThreadsafeTree<0>,0>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlSymbolTableLargeBase<CNonThreadsafeTree<0>,0>::RemoveAll(
        CUtlSymbolTableLargeBase<CNonThreadsafeTree<0>,0> *this)
{
  int i; // edi

  CUtlRBTree<CUtlSymbolTableLargeBaseTreeEntry_t *,int,CTreeEntryLess<CNonThreadsafeTree<0>,0>,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int>,int>>::RemoveAll(this: &this->m_Lookup);
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
// Address: 0x100F55A0
// Name: public: void CUtlTSHash<struct CUtlSymbolTableLargeBaseTreeEntry_t __near *,2048,struct CUtlSymbolTableLargeBaseTreeEntry_t __near *,class CCThreadsafeTreeHashMethod<2048,struct CUtlSymbolTableLargeBaseTreeEntry_t __near *,0>,0>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlTSHash<CUtlSymbolTableLargeBaseTreeEntry_t *,2048,CUtlSymbolTableLargeBaseTreeEntry_t *,CCThreadsafeTreeHashMethod<2048,CUtlSymbolTableLargeBaseTreeEntry_t *,0>,0>::RemoveAll(
        CUtlTSHash<CUtlSymbolTableLargeBaseTreeEntry_t *,2048,CUtlSymbolTableLargeBaseTreeEntry_t *,CCThreadsafeTreeHashMethod<2048,CUtlSymbolTableLargeBaseTreeEntry_t *,0>,0> *this)
{
  CThreadSpinRWLock *p_m_AddLock; // esi
  int i; // edi
  unsigned int j; // eax
  CThreadFastMutex *p_m_mutex; // esi
  DWORD CurrentThreadId; // ecx

  this->m_bNeedsCommit = false;
  if ( this->m_EntryMemory.m_BlocksAllocated != 0 )
  {
    p_m_AddLock = &this->m_aBuckets[0].m_AddLock;
    for ( i = 2048; i != 0; --i )
    {
      if ( (p_m_AddLock->m_lockInfo.m_i32 & 0x10000) != 0
        || _InterlockedCompareExchange((volatile signed __int32 *)p_m_AddLock, 0x10000, 0) != 0 )
      {
        CThreadSpinRWLock::SpinLockForWrite(this: p_m_AddLock);
      }
      else
      {
        p_m_AddLock->m_writerId = GetCurrentThreadId();
      }
      for ( j = p_m_AddLock[-1].m_writerId; j != 0; j = *(_DWORD *)(j + 4) )
        ;
      p_m_AddLock[-1].m_lockInfo.m_i32 = 0;
      p_m_AddLock[-1].m_writerId = 0;
      p_m_AddLock->m_writerId = 0;
      p_m_AddLock->m_lockInfo.m_i32 = 0;
      p_m_AddLock += 2;
    }
    p_m_mutex = &this->m_EntryMemory.m_mutex;
    CurrentThreadId = GetCurrentThreadId();
    if ( CurrentThreadId != this->m_EntryMemory.m_mutex.m_ownerID
      && _InterlockedCompareExchange((volatile signed __int32 *)p_m_mutex, CurrentThreadId, 0) != 0 )
    {
      _mm_pause();
      CThreadFastMutex::Lock(a1: p_m_mutex, a2: CurrentThreadId, a3: 0);
    }
    else
    {
      ++this->m_EntryMemory.m_mutex.m_depth;
    }
    CUtlMemoryPool::Clear(this: &this->m_EntryMemory);
    if ( this->m_EntryMemory.m_mutex.m_depth-- == 1 )
      _InterlockedExchange((volatile __int32 *)p_m_mutex, 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100F5660
// Name: public: void CUtlSymbolTableLargeBase<class CThreadsafeTree<0>,0>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::RemoveAll(
        CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0> *this)
{
  int v2; // edi

  CUtlTSHash<CUtlSymbolTableLargeBaseTreeEntry_t *,2048,CUtlSymbolTableLargeBaseTreeEntry_t *,CCThreadsafeTreeHashMethod<2048,CUtlSymbolTableLargeBaseTreeEntry_t *,0>,0>::RemoveAll(this: &this->m_Lookup);
  v2 = 0;
  if ( this->m_StringPools.m_Size <= 0 )
  {
    this->m_StringPools.m_Size = 0;
  }
  else
  {
    do
      free(pMem: this->m_StringPools.m_Memory.m_pMemory[v2++]);
    while ( v2 < this->m_StringPools.m_Size );
    this->m_StringPools.m_Size = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100F56B0
// Name: public: CUtlSymbolTableLargeBase<class CThreadsafeTree<0>,0>::CUtlSymbolTableLargeBase<class CThreadsafeTree<0>,0>(void)
// Source: json
//------------------------------------------------------------------------------
CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0> *__thiscall CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>(
        CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0> *this)
{
  CUtlTSHash<CUtlSymbolTableLargeBaseTreeEntry_t *,2048,CUtlSymbolTableLargeBaseTreeEntry_t *,CCThreadsafeTreeHashMethod<2048,CUtlSymbolTableLargeBaseTreeEntry_t *,0>,0>::HashBucket_t *m_aBuckets; // eax
  int v3; // edx
  CThreadSpinRWLock *p_m_AddLock; // ecx
  int i; // ecx

  CUtlMemoryPool::CUtlMemoryPool(
    this: &this->m_Lookup.m_EntryMemory,
    blockSize: 12,
    numElements: 32,
    growMode: 2,
    pszAllocOwner: nullptr,
    nAlignment: 0);
  m_aBuckets = this->m_Lookup.m_aBuckets;
  this->m_Lookup.m_EntryMemory.m_mutex.m_ownerID = 0;
  this->m_Lookup.m_EntryMemory.m_mutex.m_depth = 0;
  v3 = 2047;
  p_m_AddLock = &this->m_Lookup.m_aBuckets[0].m_AddLock;
  do
  {
    p_m_AddLock->m_lockInfo.m_i32 = 0;
    p_m_AddLock->m_writerId = 0;
    p_m_AddLock += 2;
    --v3;
  }
  while ( v3 >= 0 );
  this->m_Lookup.m_bNeedsCommit = false;
  for ( i = 2048; i != 0; --i )
  {
    m_aBuckets->m_pFirst = nullptr;
    m_aBuckets->m_pFirstUncommitted = nullptr;
    ++m_aBuckets;
  }
  this->m_StringPools.m_Memory.m_pMemory = nullptr;
  this->m_StringPools.m_Memory.m_nAllocationCount = 0;
  this->m_StringPools.m_Size = 0;
  this->m_StringPools.m_pElements = nullptr;
  this->m_StringPools.m_Memory.m_nGrowSize = 8;
  return this;
}

} // namespace missionchooser

// ============================================================
// Overlay from modelbrowser (Missing functions)
// ============================================================
namespace modelbrowser {

//------------------------------------------------------------------------------
// Address: 0x00415090
// Name: public: class Vector const __near & CDmxElement::GetValue<class Vector>(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
const Vector *__thiscall CDmxElement::GetValue<Vector>(CDmxElement *this, const char *pAttributeName)
{
  const CDmxAttribute *Attribute; // eax

  Attribute = CDmxElement::GetAttribute(this, pAttributeName);
  if ( Attribute != nullptr )
  {
    if ( Attribute->m_Type == AT_VECTOR3 )
    {
      return (const Vector *)Attribute->m_pData;
    }
    else
    {
      if ( (`CDmxAttribute::GetValue<Vector>'::`4'::`local static guard' & 1) == 0 )
        `CDmxAttribute::GetValue<Vector>'::`4'::`local static guard' |= 1u;
      `CDmxAttribute::GetValue<Vector>'::`4'::defaultValue = 0;
      dword_5077D4 = 0;
      dword_5077D8 = 0;
      return (const Vector *)&`CDmxAttribute::GetValue<Vector>'::`4'::defaultValue;
    }
  }
  else
  {
    if ( (`CDmxElement::GetValue<Vector>'::`4'::`local static guard' & 1) == 0 )
      `CDmxElement::GetValue<Vector>'::`4'::`local static guard' |= 1u;
    `CDmxElement::GetValue<Vector>'::`4'::defaultValue.x = 0.0;
    `CDmxElement::GetValue<Vector>'::`4'::defaultValue.y = 0.0;
    `CDmxElement::GetValue<Vector>'::`4'::defaultValue.z = 0.0;
    return &`CDmxElement::GetValue<Vector>'::`4'::defaultValue;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004AEC70
// Name: public: class CUtlSymbolLarge CUtlSymbolTableLargeBase<class CNonThreadsafeTree<0>,0>::Find(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
CUtlSymbolLarge *__thiscall CUtlSymbolTableLargeBase<CNonThreadsafeTree<0>,0>::Find(
        CUtlSymbolTableLargeBase<CNonThreadsafeTree<0>,0> *this,
        CUtlSymbolLarge *result,
        const char *pString)
{
  const char *v3; // ebx
  int v5; // eax
  int v6; // esi
  void *v7; // esp
  CUtlRBTree<CUtlSymbolTableLargeBaseTreeEntry_t *,int,CTreeEntryLess<CNonThreadsafeTree<0>,0>,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int>,int> > *v8; // esi
  int v9; // eax
  CUtlSymbolTableLargeBaseTreeEntry_t *m_Data; // ecx
  unsigned int v11; // [esp+0h] [ebp-10h] BYREF
  int v12; // [esp+4h] [ebp-Ch] BYREF
  CUtlRBTree<CUtlSymbolTableLargeBaseTreeEntry_t *,int,CTreeEntryLess<CNonThreadsafeTree<0>,0>,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int>,int> > *p_m_Lookup; // [esp+Ch] [ebp-4h]

  v3 = pString;
  p_m_Lookup = &this->m_Lookup;
  if ( pString == nullptr )
    goto LABEL_2;
  v5 = _V_strlen(str: pString);
  v6 = v5 + 1;
  v7 = alloca(v5 + 5);
  v11 = HashString(pszKey: v3);
  _V_memcpy(dest: &v12, src: v3, count: v6);
  v8 = p_m_Lookup;
  pString = (const char *)&v11;
  v9 = CUtlRBTree<CUtlSymbolTableLargeBaseTreeEntry_t *,int,CTreeEntryLess<CNonThreadsafeTree<0>,0>,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int>,int>>::Find(
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
// Address: 0x004AED00
// Name: public: void CUtlSymbolTableLargeBase<class CNonThreadsafeTree<0>,0>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlSymbolTableLargeBase<CNonThreadsafeTree<0>,0>::RemoveAll(
        CUtlSymbolTableLargeBase<CNonThreadsafeTree<0>,0> *this)
{
  int i; // edi

  CUtlRBTree<CUtlSymbolTableLargeBaseTreeEntry_t *,int,CTreeEntryLess<CNonThreadsafeTree<0>,0>,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int>,int>>::RemoveAll(this: &this->m_Lookup);
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
// Address: 0x004AF610
// Name: public: class CUtlSymbolLarge CUtlSymbolTableLargeBase<class CNonThreadsafeTree<0>,0>::AddString(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CUtlSymbolLarge *__thiscall CUtlSymbolTableLargeBase<CNonThreadsafeTree<0>,0>::AddString(
        CUtlSymbolTableLargeBase<CNonThreadsafeTree<0>,0> *this,
        CUtlSymbolLarge *result,
        const char *pString)
{
  void *m_String; // ecx
  int v6; // eax
  signed int v7; // edi
  CUtlSymbolTableLargeBase<CNonThreadsafeTree<0>,0>::StringPool_t *v8; // eax
  CUtlVector<CUtlSymbolTableLargeBase<CNonThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CNonThreadsafeTree<0>,0>::StringPool_t *,int> > *p_m_StringPools; // esi
  unsigned int v10; // esi
  CUtlSymbolTableLargeBase<CNonThreadsafeTree<0>,0>::StringPool_t *v11; // edx
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CUtlSymbolTableLargeBase<CNonThreadsafeTree<0>,0>::StringPool_t **m_pMemory; // ecx
  int v15; // eax
  CUtlSymbolTableLargeBase<CNonThreadsafeTree<0>,0>::StringPool_t **v16; // eax
  unsigned int v17; // eax
  CUtlSymbolTableLargeBase<CNonThreadsafeTree<0>,0>::StringPool_t *v18; // ecx
  int m_SpaceUsed; // edx
  CUtlSymbolTableLargeBaseTreeEntry_t *v20; // esi
  int lenString; // [esp+8h] [ebp-Ch]
  int lenDecorated; // [esp+Ch] [ebp-8h]
  CUtlSymbolTableLargeBase<CNonThreadsafeTree<0>,0>::StringPool_t *pPool; // [esp+10h] [ebp-4h] BYREF

  if ( pString != nullptr )
  {
    CUtlSymbolTableLargeBase<CNonThreadsafeTree<0>,0>::Find(this, result: (CUtlSymbolLarge *)&pPool, pString);
    m_String = pPool;
    if ( pPool == (CUtlSymbolTableLargeBase<CNonThreadsafeTree<0>,0>::StringPool_t *)-1 )
    {
      v6 = _V_strlen(str: pString);
      lenString = v6 + 1;
      v7 = (v6 + 8) & 0xFFFFFFFC;
      v8 = nullptr;
      lenDecorated = v7;
      if ( this->m_StringPools.m_Size <= 0 )
        goto LABEL_10;
      p_m_StringPools = &this->m_StringPools;
      pPool = (CUtlSymbolTableLargeBase<CNonThreadsafeTree<0>,0>::StringPool_t *)this->m_StringPools.m_Memory.m_pMemory;
      while ( *(_DWORD *)pPool->m_TotalLen - *(_DWORD *)(pPool->m_TotalLen + 4) < v7 )
      {
        pPool = (CUtlSymbolTableLargeBase<CNonThreadsafeTree<0>,0>::StringPool_t *)((char *)pPool + 4);
        v8 = (CUtlSymbolTableLargeBase<CNonThreadsafeTree<0>,0>::StringPool_t *)((char *)v8 + 1);
        if ( (int)v8 >= this->m_StringPools.m_Size )
          goto LABEL_10;
      }
      pPool = v8;
      if ( v8 == (CUtlSymbolTableLargeBase<CNonThreadsafeTree<0>,0>::StringPool_t *)-1 )
      {
LABEL_10:
        v10 = v7 + 12;
        if ( (unsigned int)(v7 + 12) <= 0x800 )
          v10 = 2048;
        v11 = (CUtlSymbolTableLargeBase<CNonThreadsafeTree<0>,0>::StringPool_t *)operator new(nSize: v10);
        v11->m_TotalLen = v10 - 12;
        p_m_StringPools = &this->m_StringPools;
        v11->m_SpaceUsed = 0;
        m_Size = this->m_StringPools.m_Size;
        m_nAllocationCount = this->m_StringPools.m_Memory.m_nAllocationCount;
        pPool = v11;
        if ( m_Size + 1 > m_nAllocationCount )
        {
          CUtlMemory<unsigned long,int>::Grow(
            this: (CUtlMemory<vgui::TreeNode *,int> *)&this->m_StringPools,
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
        pPool = (CUtlSymbolTableLargeBase<CNonThreadsafeTree<0>,0>::StringPool_t *)m_Size;
        v7 = lenDecorated;
      }
      v17 = HashString(pszKey: pString);
      v18 = p_m_StringPools->m_Memory.m_pMemory[(_DWORD)pPool];
      m_SpaceUsed = v18->m_SpaceUsed;
      v20 = (CUtlSymbolTableLargeBaseTreeEntry_t *)&v18->m_Data[m_SpaceUsed];
      v18->m_SpaceUsed = v7 + m_SpaceUsed;
      v20->m_Hash = v17;
      _V_memcpy(dest: (char *)&v18[1] + m_SpaceUsed, src: pString, count: lenString);
      m_String = this->m_Lookup.m_Elements.m_pMemory[CNonThreadsafeTree<0>::Insert(this: &this->m_Lookup, entry: v20)].m_Data->m_String;
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
// Address: 0x004AF770
// Name: private: void CDmxElement::SetId(struct UniqueId_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxElement::SetId(CDmxElement *this, const UniqueId_t *id)
{
  CopyUniqueId(src: id, pDest: &this->m_Id);
}

//------------------------------------------------------------------------------
// Address: 0x004AF790
// Name: protected: static int CUtlSortVector<class CDmxAttribute __near *,class CDmxAttributeLess>::CompareHelper(void __near *,class CDmxAttribute __near * const __near *,class CDmxAttribute __near * const __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl CUtlSortVector<CDmxAttribute *,CDmxAttributeLess>::CompareHelper(
        void *context,
        CDmxAttribute *const *lhs,
        CDmxAttribute *const *rhs)
{
  int v3; // ecx
  int v4; // esi
  int result; // eax
  int lhsa; // [esp+14h] [ebp+Ch]
  int rhsa; // [esp+18h] [ebp+10h]
  int rhsb; // [esp+18h] [ebp+10h]

  v3 = (int)*rhs;
  v4 = (int)*lhs;
  result = -1;
  if ( *lhs != nullptr )
    rhsa = *(_DWORD *)(v4 + 4);
  else
    rhsa = -1;
  if ( v3 != 0 )
    lhsa = *(_DWORD *)(v3 + 4);
  else
    lhsa = -1;
  if ( rhsa >= lhsa )
  {
    if ( v3 != 0 )
      rhsb = *(_DWORD *)(v3 + 4);
    else
      rhsb = -1;
    if ( v4 != 0 )
      return rhsb < *(_DWORD *)(v4 + 4);
    else
      return rhsb < -1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004AF810
// Name: private: int CUtlTSHash<struct CUtlSymbolTableLargeBaseTreeEntry_t __near *,2048,struct CUtlSymbolTableLargeBaseTreeEntry_t __near *,class CCThreadsafeTreeHashMethod<2048,struct CUtlSymbolTableLargeBaseTreeEntry_t __near *,0>,0>::Find(struct CUtlSymbolTableLargeBaseTreeEntry_t __near *,struct CUtlTSHash<struct CUtlSymbolTableLargeBaseTreeEntry_t __near *,2048,struct CUtlSymbolTableLargeBaseTreeEntry_t __near *,class CCThreadsafeTreeHashMethod<2048,struct CUtlSymbolTableLargeBaseTreeEntry_t __near *,0>,0>::HashFixedDataInternal_t<struct CUtlSymbolTableLargeBaseTreeEntry_t __near *> __near *,struct CUtlTSHash<struct CUtlSymbolTableLargeBaseTreeEntry_t __near *,2048,struct CUtlSymbolTableLargeBaseTreeEntry_t __near *,class CCThreadsafeTreeHashMethod<2048,struct CUtlSymbolTableLargeBaseTreeEntry_t __near *,0>,0>::HashFixedDataInternal_t<struct CUtlSymbolTableLargeBaseTreeEntry_t __near *> __near *)
// Source: json
//------------------------------------------------------------------------------
CUtlTSHash<CUtlSymbolTableLargeBaseTreeEntry_t *,2048,CUtlSymbolTableLargeBaseTreeEntry_t *,CCThreadsafeTreeHashMethod<2048,CUtlSymbolTableLargeBaseTreeEntry_t *,0>,0>::HashFixedDataInternal_t<CUtlSymbolTableLargeBaseTreeEntry_t *> *__thiscall CUtlTSHash<CUtlSymbolTableLargeBaseTreeEntry_t *,2048,CUtlSymbolTableLargeBaseTreeEntry_t *,CCThreadsafeTreeHashMethod<2048,CUtlSymbolTableLargeBaseTreeEntry_t *,0>,0>::Find(
        CUtlTSHash<CUtlSymbolTableLargeBaseTreeEntry_t *,2048,CUtlSymbolTableLargeBaseTreeEntry_t *,CCThreadsafeTreeHashMethod<2048,CUtlSymbolTableLargeBaseTreeEntry_t *,0>,0> *this,
        CUtlSymbolTableLargeBaseTreeEntry_t *uiKey,
        CUtlTSHash<CUtlSymbolTableLargeBaseTreeEntry_t *,2048,CUtlSymbolTableLargeBaseTreeEntry_t *,CCThreadsafeTreeHashMethod<2048,CUtlSymbolTableLargeBaseTreeEntry_t *,0>,0>::HashFixedDataInternal_t<CUtlSymbolTableLargeBaseTreeEntry_t *> *pFirstElement,
        CUtlTSHash<CUtlSymbolTableLargeBaseTreeEntry_t *,2048,CUtlSymbolTableLargeBaseTreeEntry_t *,CCThreadsafeTreeHashMethod<2048,CUtlSymbolTableLargeBaseTreeEntry_t *,0>,0>::HashFixedDataInternal_t<CUtlSymbolTableLargeBaseTreeEntry_t *> *pLastElement)
{
  CUtlTSHash<CUtlSymbolTableLargeBaseTreeEntry_t *,2048,CUtlSymbolTableLargeBaseTreeEntry_t *,CCThreadsafeTreeHashMethod<2048,CUtlSymbolTableLargeBaseTreeEntry_t *,0>,0>::HashFixedDataInternal_t<CUtlSymbolTableLargeBaseTreeEntry_t *> *v4; // esi

  v4 = pFirstElement;
  if ( pFirstElement == pLastElement )
    return nullptr;
  while ( v4->m_uiKey->m_Hash != uiKey->m_Hash || _V_strcmp(s1: v4->m_uiKey->m_String, s2: uiKey->m_String) != 0 )
  {
    v4 = v4->m_pNext;
    if ( v4 == pLastElement )
      return nullptr;
  }
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x004AF860
// Name: private: int CUtlTSHash<struct CUtlSymbolTableLargeBaseTreeEntry_t __near *,2048,struct CUtlSymbolTableLargeBaseTreeEntry_t __near *,class CCThreadsafeTreeHashMethod<2048,struct CUtlSymbolTableLargeBaseTreeEntry_t __near *,0>,0>::InsertUncommitted(struct CUtlSymbolTableLargeBaseTreeEntry_t __near *,struct CUtlTSHash<struct CUtlSymbolTableLargeBaseTreeEntry_t __near *,2048,struct CUtlSymbolTableLargeBaseTreeEntry_t __near *,class CCThreadsafeTreeHashMethod<2048,struct CUtlSymbolTableLargeBaseTreeEntry_t __near *,0>,0>::HashBucket_t __near &)
// Source: json
//------------------------------------------------------------------------------
CUtlTSHash<CUtlSymbolTableLargeBaseTreeEntry_t *,2048,CUtlSymbolTableLargeBaseTreeEntry_t *,CCThreadsafeTreeHashMethod<2048,CUtlSymbolTableLargeBaseTreeEntry_t *,0>,0>::HashFixedDataInternal_t<CUtlSymbolTableLargeBaseTreeEntry_t *> *__thiscall CUtlTSHash<CUtlSymbolTableLargeBaseTreeEntry_t *,2048,CUtlSymbolTableLargeBaseTreeEntry_t *,CCThreadsafeTreeHashMethod<2048,CUtlSymbolTableLargeBaseTreeEntry_t *,0>,0>::InsertUncommitted(
        CUtlTSHash<CUtlSymbolTableLargeBaseTreeEntry_t *,2048,CUtlSymbolTableLargeBaseTreeEntry_t *,CCThreadsafeTreeHashMethod<2048,CUtlSymbolTableLargeBaseTreeEntry_t *,0>,0> *this,
        CUtlSymbolTableLargeBaseTreeEntry_t *uiKey,
        CUtlTSHash<CUtlSymbolTableLargeBaseTreeEntry_t *,2048,CUtlSymbolTableLargeBaseTreeEntry_t *,CCThreadsafeTreeHashMethod<2048,CUtlSymbolTableLargeBaseTreeEntry_t *,0>,0>::HashBucket_t *bucket)
{
  CThreadFastMutex *p_m_mutex; // esi
  DWORD CurrentThreadId; // ecx
  CUtlTSHash<CUtlSymbolTableLargeBaseTreeEntry_t *,2048,CUtlSymbolTableLargeBaseTreeEntry_t *,CCThreadsafeTreeHashMethod<2048,CUtlSymbolTableLargeBaseTreeEntry_t *,0>,0>::HashFixedDataInternal_t<CUtlSymbolTableLargeBaseTreeEntry_t *> *result; // eax

  this->m_bNeedsCommit = true;
  p_m_mutex = &this->m_EntryMemory.m_mutex;
  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != p_m_mutex->m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)p_m_mutex, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(a1: p_m_mutex, a2: CurrentThreadId, a3: 0);
  }
  else
  {
    ++p_m_mutex->m_depth;
  }
  result = (CUtlTSHash<CUtlSymbolTableLargeBaseTreeEntry_t *,2048,CUtlSymbolTableLargeBaseTreeEntry_t *,CCThreadsafeTreeHashMethod<2048,CUtlSymbolTableLargeBaseTreeEntry_t *,0>,0>::HashFixedDataInternal_t<CUtlSymbolTableLargeBaseTreeEntry_t *> *)CUtlMemoryPool::Alloc(this: &this->m_EntryMemory);
  if ( p_m_mutex->m_depth-- == 1 )
    _InterlockedExchange((volatile __int32 *)p_m_mutex, 0);
  result->m_pNext = bucket->m_pFirstUncommitted;
  bucket->m_pFirstUncommitted = result;
  result->m_uiKey = uiKey;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004AF8D0
// Name: public: void CUtlTSHash<struct CUtlSymbolTableLargeBaseTreeEntry_t __near *,2048,struct CUtlSymbolTableLargeBaseTreeEntry_t __near *,class CCThreadsafeTreeHashMethod<2048,struct CUtlSymbolTableLargeBaseTreeEntry_t __near *,0>,0>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlTSHash<CUtlSymbolTableLargeBaseTreeEntry_t *,2048,CUtlSymbolTableLargeBaseTreeEntry_t *,CCThreadsafeTreeHashMethod<2048,CUtlSymbolTableLargeBaseTreeEntry_t *,0>,0>::RemoveAll(
        CUtlTSHash<CUtlSymbolTableLargeBaseTreeEntry_t *,2048,CUtlSymbolTableLargeBaseTreeEntry_t *,CCThreadsafeTreeHashMethod<2048,CUtlSymbolTableLargeBaseTreeEntry_t *,0>,0> *this)
{
  CThreadSpinRWLock *p_m_AddLock; // esi
  int i; // edi
  unsigned int j; // eax
  CThreadFastMutex *p_m_mutex; // esi
  DWORD CurrentThreadId; // ecx

  this->m_bNeedsCommit = false;
  if ( this->m_EntryMemory.m_BlocksAllocated != 0 )
  {
    p_m_AddLock = &this->m_aBuckets[0].m_AddLock;
    for ( i = 2048; i != 0; --i )
    {
      if ( (p_m_AddLock->m_lockInfo.m_i32 & 0x10000) != 0
        || _InterlockedCompareExchange((volatile signed __int32 *)p_m_AddLock, 0x10000, 0) != 0 )
      {
        CThreadSpinRWLock::SpinLockForWrite(this: p_m_AddLock);
      }
      else
      {
        p_m_AddLock->m_writerId = GetCurrentThreadId();
      }
      for ( j = p_m_AddLock[-1].m_writerId; j != 0; j = *(_DWORD *)(j + 4) )
        ;
      p_m_AddLock[-1].m_lockInfo.m_i32 = 0;
      p_m_AddLock[-1].m_writerId = 0;
      p_m_AddLock->m_writerId = 0;
      p_m_AddLock->m_lockInfo.m_i32 = 0;
      p_m_AddLock += 2;
    }
    p_m_mutex = &this->m_EntryMemory.m_mutex;
    CurrentThreadId = GetCurrentThreadId();
    if ( CurrentThreadId != this->m_EntryMemory.m_mutex.m_ownerID
      && _InterlockedCompareExchange((volatile signed __int32 *)p_m_mutex, CurrentThreadId, 0) != 0 )
    {
      _mm_pause();
      CThreadFastMutex::Lock(a1: p_m_mutex, a2: CurrentThreadId, a3: 0);
    }
    else
    {
      ++this->m_EntryMemory.m_mutex.m_depth;
    }
    CUtlMemoryPool::Clear(this: &this->m_EntryMemory);
    if ( this->m_EntryMemory.m_mutex.m_depth-- == 1 )
      _InterlockedExchange((volatile __int32 *)p_m_mutex, 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004AF990
// Name: public: int CUtlSortVector<class CDmxAttribute __near *,class CDmxAttributeLess>::Find(class CDmxAttribute __near * const __near &)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlSortVector<CDmxAttribute *,CDmxAttributeLess>::Find(
        CUtlSortVector<CDmxAttribute *,CDmxAttributeLess> *this,
        CDmxAttribute *const **src)
{
  int v3; // ebx
  int v4; // ecx
  CDmxAttribute **m_pMemory; // eax
  CDmxAttribute *const *v6; // esi
  int result; // eax
  CDmxAttribute *v8; // edx
  int *v9; // edi
  int *v10; // esi
  int *v11; // esi
  int *v12; // ecx
  int v13; // [esp+Ch] [ebp-24h] BYREF
  CUtlSymbolLarge::<unnamed_type_u> v14; // [esp+10h] [ebp-20h] BYREF
  int v15; // [esp+14h] [ebp-1Ch] BYREF
  int v16; // [esp+18h] [ebp-18h] BYREF
  int v17; // [esp+1Ch] [ebp-14h] BYREF
  int v18; // [esp+20h] [ebp-10h] BYREF
  int v19; // [esp+24h] [ebp-Ch] BYREF
  CUtlSymbolLarge::<unnamed_type_u> v20; // [esp+28h] [ebp-8h] BYREF
  CDmxAttribute **v21; // [esp+2Ch] [ebp-4h]
  CDmxAttribute *const *srca; // [esp+38h] [ebp+8h]

  if ( this->m_bNeedsSort
    && _LoggingSystem_LogAssert(
         a1: "%s (%d) : %s\n",
         "u:\\buildbot\\portal2_staging_win32\\build\\src\\public\\tier1/UtlSortVector.h",
         215,
         "Assertion Failed: !m_bNeedsSort") == 1 )
  {
    if ( (unsigned __int8)_ShouldUseNewAssertDialog() == 0
      || (unsigned __int8)_DoNewAssertDialog(
                            a1: "u:\\buildbot\\portal2_staging_win32\\build\\src\\public\\tier1/UtlSortVector.h",
                            a2: 215,
                            a3: "Assertion Failed: !m_bNeedsSort") != 0 )
    {
      __debugbreak();
    }
    __ExitOnFatalAssert(a1: "u:\\buildbot\\portal2_staging_win32\\build\\src\\public\\tier1/UtlSortVector.h", a2: 215);
  }
  v3 = 0;
  v4 = this->m_Size - 1;
  if ( v4 >= 0 )
  {
    m_pMemory = this->m_Memory.m_pMemory;
    v6 = *src;
    v21 = m_pMemory;
    for ( srca = v6; ; v6 = srca )
    {
      result = (v4 + v3) >> 1;
      v8 = v21[result];
      if ( v8 != nullptr )
      {
        v20.m_Id = (int)v8->m_Name.u;
        v9 = (int *)&v20;
      }
      else
      {
        v19 = -1;
        v9 = &v19;
      }
      if ( v6 != nullptr )
      {
        v18 = *((_DWORD *)v6 + 1);
        v10 = &v18;
      }
      else
      {
        v17 = -1;
        v10 = &v17;
      }
      if ( *v9 >= *v10 )
      {
        if ( srca != nullptr )
        {
          v16 = *((_DWORD *)srca + 1);
          v11 = &v16;
        }
        else
        {
          v15 = -1;
          v11 = &v15;
        }
        if ( v8 != nullptr )
        {
          v14.m_Id = (int)v8->m_Name.u;
          v12 = (int *)&v14;
        }
        else
        {
          v13 = -1;
          v12 = &v13;
        }
        if ( *v11 >= *v12 )
          return result;
        v4 = result - 1;
      }
      else
      {
        v3 = result + 1;
      }
      if ( v3 > v4 )
        return -1;
    }
  }
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004AFAC0
// Name: private: int CUtlSymbolTableLargeBase<class CThreadsafeTree<0>,0>::FindPoolWithSpace(int)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::FindPoolWithSpace(
        CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0> *this,
        int len)
{
  int m_Size; // esi
  int result; // eax
  CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t **i; // edx

  m_Size = this->m_StringPools.m_Size;
  result = 0;
  if ( m_Size <= 0 )
    return -1;
  for ( i = this->m_StringPools.m_Memory.m_pMemory; (*i)->m_TotalLen - (*i)->m_SpaceUsed < len; ++i )
  {
    if ( ++result >= m_Size )
      return -1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004AFB00
// Name: public: int CUtlTSHash<struct CUtlSymbolTableLargeBaseTreeEntry_t __near *,2048,struct CUtlSymbolTableLargeBaseTreeEntry_t __near *,class CCThreadsafeTreeHashMethod<2048,struct CUtlSymbolTableLargeBaseTreeEntry_t __near *,0>,0>::Insert(struct CUtlSymbolTableLargeBaseTreeEntry_t __near *,struct CUtlSymbolTableLargeBaseTreeEntry_t __near * const __near &,bool __near *)
// Source: json
//------------------------------------------------------------------------------
CUtlTSHash<CUtlSymbolTableLargeBaseTreeEntry_t *,2048,CUtlSymbolTableLargeBaseTreeEntry_t *,CCThreadsafeTreeHashMethod<2048,CUtlSymbolTableLargeBaseTreeEntry_t *,0>,0>::HashFixedDataInternal_t<CUtlSymbolTableLargeBaseTreeEntry_t *> *__thiscall CUtlTSHash<CUtlSymbolTableLargeBaseTreeEntry_t *,2048,CUtlSymbolTableLargeBaseTreeEntry_t *,CCThreadsafeTreeHashMethod<2048,CUtlSymbolTableLargeBaseTreeEntry_t *,0>,0>::Insert(
        CUtlTSHash<CUtlSymbolTableLargeBaseTreeEntry_t *,2048,CUtlSymbolTableLargeBaseTreeEntry_t *,CCThreadsafeTreeHashMethod<2048,CUtlSymbolTableLargeBaseTreeEntry_t *,0>,0> *this,
        CUtlSymbolTableLargeBaseTreeEntry_t *uiKey,
        CUtlSymbolTableLargeBaseTreeEntry_t **data,
        bool *pDidInsert)
{
  CUtlTSHash<CUtlSymbolTableLargeBaseTreeEntry_t *,2048,CUtlSymbolTableLargeBaseTreeEntry_t *,CCThreadsafeTreeHashMethod<2048,CUtlSymbolTableLargeBaseTreeEntry_t *,0>,0>::HashBucket_t *v5; // esi
  CUtlTSHash<CUtlSymbolTableLargeBaseTreeEntry_t *,2048,CUtlSymbolTableLargeBaseTreeEntry_t *,CCThreadsafeTreeHashMethod<2048,CUtlSymbolTableLargeBaseTreeEntry_t *,0>,0>::HashFixedDataInternal_t<CUtlSymbolTableLargeBaseTreeEntry_t *> *result; // eax
  CThreadSpinRWLock *p_m_AddLock; // ecx

  if ( pDidInsert != nullptr )
    *pDidInsert = false;
  v5 = &this->m_aBuckets[uiKey->m_Hash & 0x7FF];
  result = CUtlTSHash<CUtlSymbolTableLargeBaseTreeEntry_t *,2048,CUtlSymbolTableLargeBaseTreeEntry_t *,CCThreadsafeTreeHashMethod<2048,CUtlSymbolTableLargeBaseTreeEntry_t *,0>,0>::Find(
             this,
             uiKey,
             pFirstElement: v5->m_pFirst,
             pLastElement: nullptr);
  if ( result == nullptr )
  {
    CThreadSpinRWLock::LockForRead(this: &v5->m_AddLock);
    result = CUtlTSHash<CUtlSymbolTableLargeBaseTreeEntry_t *,2048,CUtlSymbolTableLargeBaseTreeEntry_t *,CCThreadsafeTreeHashMethod<2048,CUtlSymbolTableLargeBaseTreeEntry_t *,0>,0>::Find(
               this,
               uiKey,
               pFirstElement: v5->m_pFirstUncommitted,
               pLastElement: v5->m_pFirst);
    _InterlockedExchangeAdd((volatile signed __int32 *)&v5->m_AddLock, 0xFFFFFFFF);
    if ( result == nullptr )
    {
      p_m_AddLock = &v5->m_AddLock;
      if ( (v5->m_AddLock.m_lockInfo.m_i32 & 0x10000) != 0
        || _InterlockedCompareExchange((volatile signed __int32 *)p_m_AddLock, 0x10000, 0) != 0 )
      {
        CThreadSpinRWLock::SpinLockForWrite(this: p_m_AddLock);
      }
      else
      {
        v5->m_AddLock.m_writerId = GetCurrentThreadId();
      }
      result = CUtlTSHash<CUtlSymbolTableLargeBaseTreeEntry_t *,2048,CUtlSymbolTableLargeBaseTreeEntry_t *,CCThreadsafeTreeHashMethod<2048,CUtlSymbolTableLargeBaseTreeEntry_t *,0>,0>::Find(
                 this,
                 uiKey,
                 pFirstElement: v5->m_pFirstUncommitted,
                 pLastElement: v5->m_pFirst);
      if ( result == nullptr )
      {
        result = CUtlTSHash<CUtlSymbolTableLargeBaseTreeEntry_t *,2048,CUtlSymbolTableLargeBaseTreeEntry_t *,CCThreadsafeTreeHashMethod<2048,CUtlSymbolTableLargeBaseTreeEntry_t *,0>,0>::InsertUncommitted(
                   this,
                   uiKey,
                   bucket: v5);
        if ( result != (CUtlTSHash<CUtlSymbolTableLargeBaseTreeEntry_t *,2048,CUtlSymbolTableLargeBaseTreeEntry_t *,CCThreadsafeTreeHashMethod<2048,CUtlSymbolTableLargeBaseTreeEntry_t *,0>,0>::HashFixedDataInternal_t<CUtlSymbolTableLargeBaseTreeEntry_t *> *)-8 )
          result->m_Data = *data;
        if ( pDidInsert != nullptr )
          *pDidInsert = true;
      }
      v5->m_AddLock.m_writerId = 0;
      v5->m_AddLock.m_lockInfo.m_i32 = 0;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004AFBE0
// Name: public: int CUtlSortVector<class CDmxAttribute __near *,class CDmxAttributeLess>::InsertNoSort(class CDmxAttribute __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlSortVector<CDmxAttribute *,CDmxAttributeLess>::InsertNoSort(
        CUtlSortVector<CDmxAttribute *,CDmxAttributeLess> *this,
        CDmxAttribute **src)
{
  int m_nAllocationCount; // eax
  int m_Size; // edi
  CDmxAttribute **m_pMemory; // ecx
  int v6; // eax
  CDmxAttribute **v7; // eax

  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  m_Size = this->m_Size;
  this->m_bNeedsSort = true;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<unsigned long,int>::Grow((CUtlMemory<vgui::TreeNode *,int> *)this, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v6 = this->m_Size - m_Size - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v6);
  v7 = &this->m_Memory.m_pMemory[m_Size];
  if ( v7 != nullptr )
    *v7 = *src;
  return m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x004AFC50
// Name: public: class CUtlSymbolLarge CUtlSymbolTableLargeBase<class CThreadsafeTree<0>,0>::Find(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
CUtlSymbolLarge *__thiscall CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::Find(
        CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0> *this,
        CUtlSymbolLarge *result,
        const char *pString)
{
  int v5; // eax
  int v6; // edi
  void *v7; // esp
  CUtlTSHash<CUtlSymbolTableLargeBaseTreeEntry_t *,2048,CUtlSymbolTableLargeBaseTreeEntry_t *,CCThreadsafeTreeHashMethod<2048,CUtlSymbolTableLargeBaseTreeEntry_t *,0>,0>::HashBucket_t *v8; // edi
  CUtlTSHash<CUtlSymbolTableLargeBaseTreeEntry_t *,2048,CUtlSymbolTableLargeBaseTreeEntry_t *,CCThreadsafeTreeHashMethod<2048,CUtlSymbolTableLargeBaseTreeEntry_t *,0>,0>::HashFixedDataInternal_t<CUtlSymbolTableLargeBaseTreeEntry_t *> *v9; // eax
  CUtlSymbolTableLargeBaseTreeEntry_t v10; // [esp+0h] [ebp-Ch] BYREF

  if ( pString == nullptr )
    goto LABEL_2;
  v5 = _V_strlen(str: pString);
  v6 = v5 + 1;
  v7 = alloca(v5 + 5);
  v10.m_Hash = HashString(pszKey: pString);
  _V_memcpy(dest: v10.m_String, src: pString, count: v6);
  v8 = &this->m_Lookup.m_aBuckets[v10.m_Hash & 0x7FF];
  v9 = CUtlTSHash<CUtlSymbolTableLargeBaseTreeEntry_t *,2048,CUtlSymbolTableLargeBaseTreeEntry_t *,CCThreadsafeTreeHashMethod<2048,CUtlSymbolTableLargeBaseTreeEntry_t *,0>,0>::Find(
         this: &this->m_Lookup,
         uiKey: &v10,
         pFirstElement: v8->m_pFirst,
         pLastElement: nullptr);
  if ( v9 != nullptr
    || (CThreadSpinRWLock::LockForRead(this: &v8->m_AddLock),
        v9 = CUtlTSHash<CUtlSymbolTableLargeBaseTreeEntry_t *,2048,CUtlSymbolTableLargeBaseTreeEntry_t *,CCThreadsafeTreeHashMethod<2048,CUtlSymbolTableLargeBaseTreeEntry_t *,0>,0>::Find(
               this: &this->m_Lookup,
               uiKey: &v10,
               pFirstElement: v8->m_pFirstUncommitted,
               pLastElement: v8->m_pFirst),
        _InterlockedExchangeAdd((volatile signed __int32 *)&v8->m_AddLock, 0xFFFFFFFF),
        v9 != nullptr) )
  {
    result->u.m_Id = (int)v9->m_Data->m_String;
    return result;
  }
  else
  {
LABEL_2:
    result->u.m_Id = -1;
    return result;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004AFD10
// Name: public: void CUtlSymbolTableLargeBase<class CThreadsafeTree<0>,0>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::RemoveAll(
        CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0> *this)
{
  int v2; // edi

  CUtlTSHash<CUtlSymbolTableLargeBaseTreeEntry_t *,2048,CUtlSymbolTableLargeBaseTreeEntry_t *,CCThreadsafeTreeHashMethod<2048,CUtlSymbolTableLargeBaseTreeEntry_t *,0>,0>::RemoveAll(this: &this->m_Lookup);
  v2 = 0;
  if ( this->m_StringPools.m_Size <= 0 )
  {
    this->m_StringPools.m_Size = 0;
  }
  else
  {
    do
      free(pMem: this->m_StringPools.m_Memory.m_pMemory[v2++]);
    while ( v2 < this->m_StringPools.m_Size );
    this->m_StringPools.m_Size = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004AFD60
// Name: private: void CDmxElement::Resort(void)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxElement::Resort(CDmxElement *this)
{
  signed int m_Size; // eax
  int i; // edi
  CDmxAttribute **v4; // eax
  const char *Name; // eax
  _DWORD context[2]; // [esp+4h] [ebp-Ch] BYREF
  char v7; // [esp+Fh] [ebp-1h] BYREF

  if ( (*((_BYTE *)this + 49) & 1) != 0 )
  {
    if ( this->m_Attributes.m_bNeedsSort )
    {
      m_Size = this->m_Attributes.m_Size;
      this->m_Attributes.m_bNeedsSort = false;
      if ( m_Size > 1 )
      {
        context[0] = this->m_Attributes.m_pLessContext;
        context[1] = &v7;
        qsort_s(
          base: this->m_Attributes.m_Memory.m_pMemory,
          num: m_Size,
          width: 4u,
          comp: (int (__cdecl *)(void *, const void *, const void *))CUtlSortVector<CDmxAttribute *,CDmxAttributeLess>::CompareHelper,
          context);
      }
    }
    *((_BYTE *)this + 49) &= ~1u;
    for ( i = this->m_Attributes.m_Size - 1; i >= 1; --i )
    {
      v4 = &this->m_Attributes.m_Memory.m_pMemory[i];
      if ( *v4 != nullptr && *(v4 - 1) != nullptr && (*v4)->m_Name.u.m_Id == (*(v4 - 1))->m_Name.u.m_Id )
      {
        Name = CDmxAttribute::GetName(this: *v4);
        _Warning(a1: "Duplicate attribute name %s encountered!\n", Name);
        if ( this->m_Attributes.m_Size - i - 1 > 0 )
          _V_memmove(
            dest: &this->m_Attributes.m_Memory.m_pMemory[i],
            src: &this->m_Attributes.m_Memory.m_pMemory[i + 1],
            count: 4 * (this->m_Attributes.m_Size - i - 1));
        --this->m_Attributes.m_Size;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004AFE30
// Name: public: void CDmxElement::LockForChanges(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxElement::LockForChanges(CDmxElement *this, bool bLock)
{
  if ( bLock )
  {
    ++this->m_nLockCount;
  }
  else if ( this->m_nLockCount-- == 1 )
  {
    CDmxElement::Resort(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004AFE50
// Name: public: bool CDmxElement::HasAttribute(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CDmxElement::HasAttribute(CDmxElement *this, const char *pAttributeName)
{
  int v3; // esi
  CDmxAttribute v5; // [esp+4h] [ebp-Ch] BYREF

  CDmxElement::Resort(this);
  CDmxAttribute::CDmxAttribute(this: &v5, pAttributeName);
  pAttributeName = (const char *)&v5;
  v3 = CUtlSortVector<CDmxAttribute *,CDmxAttributeLess>::Find(
         this: &this->m_Attributes,
         src: (CDmxAttribute *const **)&pAttributeName);
  CDmxAttribute::~CDmxAttribute(this: &v5);
  return v3 >= 0;
}

//------------------------------------------------------------------------------
// Address: 0x004AFEA0
// Name: public: class CDmxAttribute const __near * CDmxElement::GetAttribute(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
const CDmxAttribute *__thiscall CDmxElement::GetAttribute(CDmxElement *this, const char *pAttributeName)
{
  int v3; // edi
  CDmxAttribute v5; // [esp+8h] [ebp-Ch] BYREF

  CDmxElement::Resort(this);
  CDmxAttribute::CDmxAttribute(this: &v5, pAttributeName);
  pAttributeName = (const char *)&v5;
  v3 = CUtlSortVector<CDmxAttribute *,CDmxAttributeLess>::Find(
         this: &this->m_Attributes,
         src: (CDmxAttribute *const **)&pAttributeName);
  CDmxAttribute::~CDmxAttribute(this: &v5);
  if ( v3 < 0 )
    return nullptr;
  else
    return this->m_Attributes.m_Memory.m_pMemory[v3];
}

//------------------------------------------------------------------------------
// Address: 0x004AFF00
// Name: private: void CDmxElement::AddElementsToDelete(class CUtlVector<class CDmxElement __near *,class CUtlMemory<class CDmxElement __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxElement::AddElementsToDelete(CDmxElement *this, CUtlMemory<vgui::TreeNode *,int> *elementsToDelete)
{
  CDmxElement *v2; // ebx
  char v3; // al
  int m_pMemory; // esi
  int m_nAllocationCount; // eax
  CDmxElement **v7; // ecx
  int v8; // eax
  CDmxElement **v9; // esi
  int v10; // eax
  CDmxAttribute *v11; // eax
  CDmxElement *v12; // ecx
  _DWORD *m_pData; // ebx
  int v14; // ecx
  int v15; // esi
  int nCount; // [esp+4h] [ebp-Ch]
  int nElementCount; // [esp+8h] [ebp-8h]
  int i; // [esp+18h] [ebp+8h]

  v2 = this;
  v3 = *((_BYTE *)this + 49);
  if ( (v3 & 2) == 0 )
  {
    *((_BYTE *)this + 49) = v3 | 2;
    m_pMemory = (int)elementsToDelete[1].m_pMemory;
    m_nAllocationCount = elementsToDelete->m_nAllocationCount;
    if ( m_pMemory + 1 > m_nAllocationCount )
      CUtlMemory<unsigned long,int>::Grow(this: elementsToDelete, num: m_pMemory - m_nAllocationCount + 1);
    ++elementsToDelete[1].m_pMemory;
    v7 = (CDmxElement **)elementsToDelete->m_pMemory;
    v8 = (int)elementsToDelete[1].m_pMemory - m_pMemory - 1;
    elementsToDelete[1].m_nAllocationCount = (int)elementsToDelete->m_pMemory;
    if ( v8 > 0 )
      _V_memmove(dest: &v7[m_pMemory + 1], src: &v7[m_pMemory], count: 4 * v8);
    v9 = (CDmxElement **)&elementsToDelete->m_pMemory[m_pMemory];
    if ( v9 != nullptr )
      *v9 = v2;
    v10 = 0;
    nCount = v2->m_Attributes.m_Size;
    i = 0;
    if ( nCount > 0 )
    {
      do
      {
        v11 = v2->m_Attributes.m_Memory.m_pMemory[v10];
        if ( v11->m_Type == AT_FIRST_VALUE_TYPE )
        {
          v12 = *(CDmxElement **)v11->m_pData;
          if ( v12 != nullptr )
            CDmxElement::AddElementsToDelete(
              this: v12,
              (CUtlVector<CDmxElement *,CUtlMemory<CDmxElement *,int> > *)elementsToDelete);
        }
        else if ( v11->m_Type == AT_FIRST_ARRAY_TYPE )
        {
          m_pData = v11->m_pData;
          v14 = m_pData[3];
          v15 = 0;
          for ( nElementCount = v14; v15 < v14; ++v15 )
          {
            if ( *(_DWORD *)(*m_pData + 4 * v15) != 0 )
            {
              CDmxElement::AddElementsToDelete(
                this: *(CDmxElement **)(*m_pData + 4 * v15),
                (CUtlVector<CDmxElement *,CUtlMemory<CDmxElement *,int> > *)elementsToDelete);
              v14 = nElementCount;
            }
          }
          v2 = this;
        }
        v10 = i + 1;
        i = v10;
      }
      while ( v10 < nCount );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004AFFF0
// Name: public: CUtlSymbolTableLargeBase<class CThreadsafeTree<0>,0>::CUtlSymbolTableLargeBase<class CThreadsafeTree<0>,0>(void)
// Source: json
//------------------------------------------------------------------------------
CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0> *__thiscall CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>(
        CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0> *this)
{
  CUtlTSHash<CUtlSymbolTableLargeBaseTreeEntry_t *,2048,CUtlSymbolTableLargeBaseTreeEntry_t *,CCThreadsafeTreeHashMethod<2048,CUtlSymbolTableLargeBaseTreeEntry_t *,0>,0>::HashBucket_t *m_aBuckets; // eax
  int v3; // edx
  CThreadSpinRWLock *p_m_AddLock; // ecx
  int i; // ecx

  CUtlMemoryPool::CUtlMemoryPool(
    this: &this->m_Lookup.m_EntryMemory,
    blockSize: 12,
    numElements: 32,
    growMode: 2,
    pszAllocOwner: nullptr,
    nAlignment: 0);
  m_aBuckets = this->m_Lookup.m_aBuckets;
  this->m_Lookup.m_EntryMemory.m_mutex.m_ownerID = 0;
  this->m_Lookup.m_EntryMemory.m_mutex.m_depth = 0;
  v3 = 2047;
  p_m_AddLock = &this->m_Lookup.m_aBuckets[0].m_AddLock;
  do
  {
    p_m_AddLock->m_lockInfo.m_i32 = 0;
    p_m_AddLock->m_writerId = 0;
    p_m_AddLock += 2;
    --v3;
  }
  while ( v3 >= 0 );
  this->m_Lookup.m_bNeedsCommit = false;
  for ( i = 2048; i != 0; --i )
  {
    m_aBuckets->m_pFirst = nullptr;
    m_aBuckets->m_pFirstUncommitted = nullptr;
    ++m_aBuckets;
  }
  this->m_StringPools.m_Memory.m_pMemory = nullptr;
  this->m_StringPools.m_Memory.m_nAllocationCount = 0;
  this->m_StringPools.m_Size = 0;
  this->m_StringPools.m_pElements = nullptr;
  this->m_StringPools.m_Memory.m_nGrowSize = 8;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004B0070
// Name: public: class CUtlSymbolLarge CUtlSymbolTableLargeBase<class CThreadsafeTree<0>,0>::AddString(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CUtlSymbolLarge *__thiscall CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::AddString(
        CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0> *this,
        CUtlSymbolLarge *result,
        char *pString)
{
  const char *v3; // esi
  void *m_String; // ecx
  int v7; // eax
  unsigned int v8; // edi
  int PoolWithSpace; // esi
  unsigned int v10; // esi
  CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *v11; // edx
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t **m_pMemory; // ecx
  int v15; // eax
  CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t **v16; // eax
  unsigned int v17; // eax
  CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *v18; // ecx
  int m_SpaceUsed; // edx
  char *v20; // esi
  const char *v21; // ecx
  int lenString; // [esp+8h] [ebp-Ch]
  int lenDecorated; // [esp+Ch] [ebp-8h]
  CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *pPool; // [esp+10h] [ebp-4h] BYREF

  v3 = pString;
  if ( pString != nullptr )
  {
    CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::Find(this, result: (CUtlSymbolLarge *)&pPool, pString);
    m_String = pPool;
    if ( pPool == (CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *)-1 )
    {
      v7 = _V_strlen(str: v3) + 1;
      v8 = (v7 + 7) & 0xFFFFFFFC;
      lenString = v7;
      lenDecorated = v8;
      PoolWithSpace = CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::FindPoolWithSpace(this, len: v8);
      if ( PoolWithSpace == -1 )
      {
        v10 = v8 + 12;
        if ( v8 + 12 <= 0x800 )
          v10 = 2048;
        v11 = (CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *)operator new(nSize: v10);
        v11->m_TotalLen = v10 - 12;
        v11->m_SpaceUsed = 0;
        m_Size = this->m_StringPools.m_Size;
        m_nAllocationCount = this->m_StringPools.m_Memory.m_nAllocationCount;
        pPool = v11;
        if ( m_Size + 1 > m_nAllocationCount )
        {
          CUtlMemory<unsigned long,int>::Grow(
            this: (CUtlMemory<vgui::TreeNode *,int> *)&this->m_StringPools,
            num: m_Size - m_nAllocationCount + 1);
          v11 = pPool;
        }
        ++this->m_StringPools.m_Size;
        m_pMemory = this->m_StringPools.m_Memory.m_pMemory;
        v15 = this->m_StringPools.m_Size - m_Size - 1;
        this->m_StringPools.m_pElements = m_pMemory;
        if ( v15 > 0 )
        {
          _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v15);
          v11 = pPool;
        }
        v16 = &this->m_StringPools.m_Memory.m_pMemory[m_Size];
        if ( v16 != nullptr )
          *v16 = v11;
        PoolWithSpace = m_Size;
        v8 = lenDecorated;
      }
      v17 = HashString(pszKey: pString);
      v18 = this->m_StringPools.m_Memory.m_pMemory[PoolWithSpace];
      m_SpaceUsed = v18->m_SpaceUsed;
      v20 = &v18->m_Data[m_SpaceUsed];
      v18->m_SpaceUsed = v8 + m_SpaceUsed;
      v21 = pString;
      *(_DWORD *)v20 = v17;
      _V_memcpy(dest: v20 + 4, src: v21, count: lenString);
      pString = v20;
      m_String = CUtlTSHash<CUtlSymbolTableLargeBaseTreeEntry_t *,2048,CUtlSymbolTableLargeBaseTreeEntry_t *,CCThreadsafeTreeHashMethod<2048,CUtlSymbolTableLargeBaseTreeEntry_t *,0>,0>::Insert(
                   this: &this->m_Lookup,
                   uiKey: (CUtlSymbolTableLargeBaseTreeEntry_t *)v20,
                   data: (CUtlSymbolTableLargeBaseTreeEntry_t **)&pString,
                   pDidInsert: nullptr)->m_Data->m_String;
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
// Address: 0x004B01D0
// Name: private: CDmxElement::CDmxElement(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDmxElement *__thiscall CDmxElement::CDmxElement(CDmxElement *this, char *pType)
{
  char *v4; // [esp-4h] [ebp-Ch]

  v4 = pType;
  this->m_Attributes.m_Memory.m_pMemory = nullptr;
  this->m_Attributes.m_Memory.m_nAllocationCount = 0;
  this->m_Attributes.m_Memory.m_nGrowSize = 0;
  this->m_Attributes.m_Size = 0;
  this->m_Attributes.m_pElements = nullptr;
  this->m_Attributes.m_pLessContext = nullptr;
  this->m_Attributes.m_bNeedsSort = false;
  this->m_Type.u.m_Id = -1;
  this->m_Type = (CUtlSymbolLarge)CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::AddString(
                                    this: &CDmxElement::s_TypeSymbols,
                                    result: (CUtlSymbolLarge *)&pType,
                                    pString: v4)->u.m_Id;
  *((_BYTE *)this + 49) &= 0xFCu;
  this->m_nLockCount = 0;
  CreateUniqueId(pDest: &this->m_Id);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004B0230
// Name: public: class CDmxAttribute __near * CDmxElement::AddAttribute(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDmxAttribute *__thiscall CDmxElement::AddAttribute(CDmxElement *this, CDmxAttribute *pAttributeName)
{
  const char *v3; // ebx
  int v4; // edi
  CDmxAttribute *v6; // eax
  const char *v7; // edi
  CDmxAttribute v9; // [esp+Ch] [ebp-Ch] BYREF

  CDmxElement::Resort(this);
  v3 = (const char *)pAttributeName;
  CDmxAttribute::CDmxAttribute(this: &v9, (const char *)pAttributeName);
  pAttributeName = &v9;
  v4 = CUtlSortVector<CDmxAttribute *,CDmxAttributeLess>::Find(
         this: &this->m_Attributes,
         src: (CDmxAttribute *const **)&pAttributeName);
  CDmxAttribute::~CDmxAttribute(this: &v9);
  if ( v4 >= 0 )
    return this->m_Attributes.m_Memory.m_pMemory[v4];
  ++this->m_nLockCount;
  *((_BYTE *)this + 49) |= 1u;
  v6 = (CDmxAttribute *)DMXAlloc(size: 0xCu);
  if ( v6 != nullptr )
    v7 = (const char *)CDmxAttribute::CDmxAttribute(this: v6, pAttributeName: v3);
  else
    v7 = nullptr;
  pAttributeName = (CDmxAttribute *)v7;
  CUtlSortVector<CDmxAttribute *,CDmxAttributeLess>::InsertNoSort(this: &this->m_Attributes, src: &pAttributeName);
  if ( this->m_nLockCount-- == 1 )
    CDmxElement::Resort(this);
  return (CDmxAttribute *)v7;
}

//------------------------------------------------------------------------------
// Address: 0x004B02D0
// Name: private: void CDmxElement::RemoveAllElementsRecursive(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxElement::RemoveAllElementsRecursive(CDmxElement *this)
{
  int v1; // edi
  int v2; // ecx
  CDmxElement **m_pMemory; // eax
  CDmxElement *v4; // esi
  int m_Size; // ebx
  CDmxAttribute *v6; // ecx
  bool v8; // sf
  CDmxAttribute **v9; // eax
  CUtlVector<CDmxElement *,CUtlMemory<CDmxElement *,int> > elementsToDelete; // [esp+4h] [ebp-1Ch] BYREF
  int nCount; // [esp+18h] [ebp-8h]
  int i; // [esp+1Ch] [ebp-4h]

  v1 = 0;
  memset(&elementsToDelete, 0, sizeof(elementsToDelete));
  CDmxElement::AddElementsToDelete(this, (CUtlMemory<vgui::TreeNode *,int> *)&elementsToDelete);
  v2 = 0;
  nCount = elementsToDelete.m_Size;
  m_pMemory = elementsToDelete.m_Memory.m_pMemory;
  for ( i = 0; v2 < nCount; i = v2 )
  {
    v4 = m_pMemory[v2];
    if ( v4 != nullptr )
    {
      ++v4->m_nLockCount;
      m_Size = v4->m_Attributes.m_Size;
      if ( m_Size > 0 )
      {
        do
        {
          v6 = v4->m_Attributes.m_Memory.m_pMemory[v1];
          if ( v6 != nullptr )
            CDmxAttribute::~CDmxAttribute(this: v6);
          ++v1;
        }
        while ( v1 < m_Size );
      }
      *((_BYTE *)v4 + 49) &= ~1u;
      v4->m_Attributes.m_Size = 0;
      if ( v4->m_nLockCount-- == 1 )
        CDmxElement::Resort(this: v4);
      v8 = v4->m_Attributes.m_Memory.m_nGrowSize < 0;
      v4->m_Attributes.m_Size = 0;
      if ( !v8 )
      {
        if ( v4->m_Attributes.m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v4->m_Attributes.m_Memory.m_pMemory);
          v4->m_Attributes.m_Memory.m_pMemory = nullptr;
        }
        v4->m_Attributes.m_Memory.m_nAllocationCount = 0;
      }
      v8 = v4->m_Attributes.m_Memory.m_nGrowSize < 0;
      v9 = v4->m_Attributes.m_Memory.m_pMemory;
      v4->m_Attributes.m_pElements = v4->m_Attributes.m_Memory.m_pMemory;
      if ( !v8 )
      {
        if ( v9 != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v9);
          v4->m_Attributes.m_Memory.m_pMemory = nullptr;
        }
        v4->m_Attributes.m_Memory.m_nAllocationCount = 0;
      }
      m_pMemory = elementsToDelete.m_Memory.m_pMemory;
      v1 = 0;
    }
    v2 = i + 1;
  }
  elementsToDelete.m_Size = 0;
  if ( elementsToDelete.m_Memory.m_nGrowSize >= 0 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      m_pMemory = nullptr;
      elementsToDelete.m_Memory.m_pMemory = nullptr;
    }
    elementsToDelete.m_Memory.m_nAllocationCount = 0;
  }
  elementsToDelete.m_pElements = m_pMemory;
  if ( elementsToDelete.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x004B8DB0
// Name: _dynamic_initializer_for__CDmxElement::s_TypeSymbols__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmxElement::s_TypeSymbols__()
{
  CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>(this: &CDmxElement::s_TypeSymbols);
  return atexit(func: dynamic_atexit_destructor_for__CDmxElement::s_TypeSymbols__);
}

//------------------------------------------------------------------------------
// Address: 0x004B9510
// Name: _dynamic_atexit_destructor_for__CDmxElement::s_TypeSymbols__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmxElement::s_TypeSymbols__()
{
  CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::RemoveAll(this: &CDmxElement::s_TypeSymbols);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&CDmxElement::s_TypeSymbols.m_StringPools);
  CUtlTSHash<CUtlSymbolTableLargeBaseTreeEntry_t *,2048,CUtlSymbolTableLargeBaseTreeEntry_t *,CCThreadsafeTreeHashMethod<2048,CUtlSymbolTableLargeBaseTreeEntry_t *,0>,0>::RemoveAll(this: &CDmxElement::s_TypeSymbols.m_Lookup);
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmxElement::s_TypeSymbols.m_Lookup.m_EntryMemory);
}

} // namespace modelbrowser

// ============================================================
// Overlay from particle_import (Missing functions)
// ============================================================
namespace particle_import {

//------------------------------------------------------------------------------
// Address: 0x0052F410
// Name: public: class CDmxAttribute __near * CDmxElement::SetValue<class CDmxElement __near *>(char const __near *,class CDmxElement __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
CDmxAttribute *__thiscall CDmxElement::SetValue<CDmxElement *>(
        CDmxElement *this,
        const char *pAttributeName,
        CDmxElement **value)
{
  CDmxAttribute *v4; // edi
  CDmxElement **m_pData; // eax

  CDmxElement::LockForChanges(this, bLock: true);
  v4 = CDmxElement::AddAttribute(this, pAttributeName);
  CDmxAttribute::AllocateDataMemory(this: v4, type: AT_FIRST_VALUE_TYPE);
  m_pData = (CDmxElement **)v4->m_pData;
  if ( m_pData != nullptr )
    *m_pData = *value;
  if ( this != nullptr )
    CDmxElement::LockForChanges(this, bLock: false);
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x00560A90
// Name: public: char const __near * CDmxElement::GetTypeString(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CDmxElement::GetTypeString(CDmxElement *this)
{
  const char *result; // eax

  result = this->m_Type.u.m_pAsString;
  if ( result == (const char *)-1 )
    return str;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00560AA0
// Name: public: struct UniqueId_t const __near & CDmxElement::GetId(void)const
// Source: json
//------------------------------------------------------------------------------
const UniqueId_t *__thiscall CDmxElement::GetId(CDmxElement *this)
{
  return &this->m_Id;
}

//------------------------------------------------------------------------------
// Address: 0x00560AB0
// Name: protected: static int CUtlSortVector<class CDmxAttribute __near *,class CDmxAttributeLess>::CompareHelper(void __near *,class CDmxAttribute __near * const __near *,class CDmxAttribute __near * const __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl CUtlSortVector<CDmxAttribute *,CDmxAttributeLess>::CompareHelper(
        void *context,
        CDmxAttribute *const *lhs,
        CDmxAttribute *const *rhs)
{
  int v3; // ecx
  int v4; // esi
  int result; // eax
  int lhsa; // [esp+14h] [ebp+Ch]
  int rhsa; // [esp+18h] [ebp+10h]
  int rhsb; // [esp+18h] [ebp+10h]

  v3 = (int)*rhs;
  v4 = (int)*lhs;
  result = -1;
  if ( *lhs != nullptr )
    rhsa = *(_DWORD *)(v4 + 4);
  else
    rhsa = -1;
  if ( v3 != 0 )
    lhsa = *(_DWORD *)(v3 + 4);
  else
    lhsa = -1;
  if ( rhsa >= lhsa )
  {
    if ( v3 != 0 )
      rhsb = *(_DWORD *)(v3 + 4);
    else
      rhsb = -1;
    if ( v4 != 0 )
      return rhsb < *(_DWORD *)(v4 + 4);
    else
      return rhsb < -1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00560B40
// Name: public: class CDmxAttribute __near * CDmxElement::GetAttribute(int)
// Source: json
//------------------------------------------------------------------------------
CDmxAttribute *__thiscall CDmxElement::GetAttribute(CDmxElement *this, int nIndex)
{
  return this->m_Attributes.m_Memory.m_pMemory[nIndex];
}

//------------------------------------------------------------------------------
// Address: 0x00560B50
// Name: public: int CUtlSortVector<class CDmxAttribute __near *,class CDmxAttributeLess>::Find(class CDmxAttribute __near * const __near &)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlSortVector<CDmxAttribute *,CDmxAttributeLess>::Find(
        CUtlSortVector<CDmxAttribute *,CDmxAttributeLess> *this,
        CDmxAttribute *const **src)
{
  int v3; // ebx
  int v4; // ecx
  CDmxAttribute **m_pMemory; // eax
  CDmxAttribute *const *v6; // esi
  int result; // eax
  CDmxAttribute *v8; // edx
  int *v9; // edi
  int *v10; // esi
  int *v11; // esi
  int *v12; // ecx
  int v13; // [esp+Ch] [ebp-24h] BYREF
  CUtlSymbolLarge::<unnamed_type_u> v14; // [esp+10h] [ebp-20h] BYREF
  int v15; // [esp+14h] [ebp-1Ch] BYREF
  int v16; // [esp+18h] [ebp-18h] BYREF
  int v17; // [esp+1Ch] [ebp-14h] BYREF
  int v18; // [esp+20h] [ebp-10h] BYREF
  int v19; // [esp+24h] [ebp-Ch] BYREF
  CUtlSymbolLarge::<unnamed_type_u> v20; // [esp+28h] [ebp-8h] BYREF
  CDmxAttribute **v21; // [esp+2Ch] [ebp-4h]
  CDmxAttribute *const *srca; // [esp+38h] [ebp+8h]

  if ( this->m_bNeedsSort
    && _LoggingSystem_LogAssert(
         a1: "%s (%d) : %s\n",
         "u:\\buildbot\\portal2_staging_win32\\build\\src\\public\\tier1/UtlSortVector.h",
         215,
         "Assertion Failed: !m_bNeedsSort") == 1 )
  {
    if ( (unsigned __int8)_ShouldUseNewAssertDialog() == 0
      || (unsigned __int8)_DoNewAssertDialog(
                            a1: "u:\\buildbot\\portal2_staging_win32\\build\\src\\public\\tier1/UtlSortVector.h",
                            a2: 215,
                            a3: "Assertion Failed: !m_bNeedsSort") != 0 )
    {
      __debugbreak();
    }
    __ExitOnFatalAssert(a1: "u:\\buildbot\\portal2_staging_win32\\build\\src\\public\\tier1/UtlSortVector.h", a2: 215);
  }
  v3 = 0;
  v4 = this->m_Size - 1;
  if ( v4 >= 0 )
  {
    m_pMemory = this->m_Memory.m_pMemory;
    v6 = *src;
    v21 = m_pMemory;
    for ( srca = v6; ; v6 = srca )
    {
      result = (v4 + v3) >> 1;
      v8 = v21[result];
      if ( v8 != nullptr )
      {
        v20.m_Id = (int)v8->m_Name.u;
        v9 = (int *)&v20;
      }
      else
      {
        v19 = -1;
        v9 = &v19;
      }
      if ( v6 != nullptr )
      {
        v18 = *((_DWORD *)v6 + 1);
        v10 = &v18;
      }
      else
      {
        v17 = -1;
        v10 = &v17;
      }
      if ( *v9 >= *v10 )
      {
        if ( srca != nullptr )
        {
          v16 = *((_DWORD *)srca + 1);
          v11 = &v16;
        }
        else
        {
          v15 = -1;
          v11 = &v15;
        }
        if ( v8 != nullptr )
        {
          v14.m_Id = (int)v8->m_Name.u;
          v12 = (int *)&v14;
        }
        else
        {
          v13 = -1;
          v12 = &v13;
        }
        if ( *v11 >= *v12 )
          return result;
        v4 = result - 1;
      }
      else
      {
        v3 = result + 1;
      }
      if ( v3 > v4 )
        return -1;
    }
  }
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00560C80
// Name: public: int CUtlSortVector<class CDmxAttribute __near *,class CDmxAttributeLess>::InsertNoSort(class CDmxAttribute __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlSortVector<CDmxAttribute *,CDmxAttributeLess>::InsertNoSort(
        CUtlSortVector<CDmxAttribute *,CDmxAttributeLess> *this,
        CDmxAttribute **src)
{
  int m_nAllocationCount; // eax
  int m_Size; // edi
  CDmxAttribute **m_pMemory; // ecx
  int v6; // eax
  CDmxAttribute **v7; // eax

  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  m_Size = this->m_Size;
  this->m_bNeedsSort = true;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<IDmFormatUpdater *,int>::Grow(
      (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v6 = this->m_Size - m_Size - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v6);
  v7 = &this->m_Memory.m_pMemory[m_Size];
  if ( v7 != nullptr )
    *v7 = *src;
  return m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x00560CF0
// Name: private: void CDmxElement::Resort(void)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxElement::Resort(CDmxElement *this)
{
  signed int m_Size; // eax
  int i; // edi
  CDmxAttribute **v4; // eax
  const char *Name; // eax
  _DWORD context[2]; // [esp+4h] [ebp-Ch] BYREF
  char v7; // [esp+Fh] [ebp-1h] BYREF

  if ( (*((_BYTE *)this + 49) & 1) != 0 )
  {
    if ( this->m_Attributes.m_bNeedsSort )
    {
      m_Size = this->m_Attributes.m_Size;
      this->m_Attributes.m_bNeedsSort = false;
      if ( m_Size > 1 )
      {
        context[0] = this->m_Attributes.m_pLessContext;
        context[1] = &v7;
        qsort_s(
          base: this->m_Attributes.m_Memory.m_pMemory,
          num: m_Size,
          width: 4u,
          comp: (int (__cdecl *)(void *, const void *, const void *))CUtlSortVector<CDmxAttribute *,CDmxAttributeLess>::CompareHelper,
          context);
      }
    }
    *((_BYTE *)this + 49) &= ~1u;
    for ( i = this->m_Attributes.m_Size - 1; i >= 1; --i )
    {
      v4 = &this->m_Attributes.m_Memory.m_pMemory[i];
      if ( *v4 != nullptr && *(v4 - 1) != nullptr && (*v4)->m_Name.u.m_Id == (*(v4 - 1))->m_Name.u.m_Id )
      {
        Name = CDmxAttribute::GetName(this: *v4);
        _Warning(a1: "Duplicate attribute name %s encountered!\n", Name);
        if ( this->m_Attributes.m_Size - i - 1 > 0 )
          _V_memmove(
            dest: &this->m_Attributes.m_Memory.m_pMemory[i],
            src: &this->m_Attributes.m_Memory.m_pMemory[i + 1],
            count: 4 * (this->m_Attributes.m_Size - i - 1));
        --this->m_Attributes.m_Size;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00560DC0
// Name: public: void CDmxElement::LockForChanges(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxElement::LockForChanges(CDmxElement *this, bool bLock)
{
  if ( bLock )
  {
    ++this->m_nLockCount;
  }
  else if ( this->m_nLockCount-- == 1 )
  {
    CDmxElement::Resort(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00560DE0
// Name: private: void CDmxElement::AddElementsToDelete(class CUtlVector<class CDmxElement __near *,class CUtlMemory<class CDmxElement __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxElement::AddElementsToDelete(
        CDmxElement *this,
        CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *elementsToDelete)
{
  CDmxElement *v2; // ebx
  char v3; // al
  int m_pMemory; // esi
  int m_nAllocationCount; // eax
  CDmxElement **v7; // ecx
  int v8; // eax
  CDmxElement **v9; // esi
  int v10; // eax
  CDmxAttribute *v11; // eax
  CDmxElement *v12; // ecx
  _DWORD *m_pData; // ebx
  int v14; // ecx
  int v15; // esi
  int nCount; // [esp+4h] [ebp-Ch]
  int nElementCount; // [esp+8h] [ebp-8h]
  int i; // [esp+18h] [ebp+8h]

  v2 = this;
  v3 = *((_BYTE *)this + 49);
  if ( (v3 & 2) == 0 )
  {
    *((_BYTE *)this + 49) = v3 | 2;
    m_pMemory = (int)elementsToDelete[1].m_pMemory;
    m_nAllocationCount = elementsToDelete->m_nAllocationCount;
    if ( m_pMemory + 1 > m_nAllocationCount )
      CUtlMemory<IDmFormatUpdater *,int>::Grow(this: elementsToDelete, num: m_pMemory - m_nAllocationCount + 1);
    ++elementsToDelete[1].m_pMemory;
    v7 = (CDmxElement **)elementsToDelete->m_pMemory;
    v8 = (int)elementsToDelete[1].m_pMemory - m_pMemory - 1;
    elementsToDelete[1].m_nAllocationCount = (int)elementsToDelete->m_pMemory;
    if ( v8 > 0 )
      _V_memmove(dest: &v7[m_pMemory + 1], src: &v7[m_pMemory], count: 4 * v8);
    v9 = (CDmxElement **)&elementsToDelete->m_pMemory[m_pMemory];
    if ( v9 != nullptr )
      *v9 = v2;
    v10 = 0;
    nCount = v2->m_Attributes.m_Size;
    i = 0;
    if ( nCount > 0 )
    {
      do
      {
        v11 = v2->m_Attributes.m_Memory.m_pMemory[v10];
        if ( v11->m_Type == AT_FIRST_VALUE_TYPE )
        {
          v12 = *(CDmxElement **)v11->m_pData;
          if ( v12 != nullptr )
            CDmxElement::AddElementsToDelete(
              this: v12,
              (CUtlVector<CDmxElement *,CUtlMemory<CDmxElement *,int> > *)elementsToDelete);
        }
        else if ( v11->m_Type == AT_FIRST_ARRAY_TYPE )
        {
          m_pData = v11->m_pData;
          v14 = m_pData[3];
          v15 = 0;
          for ( nElementCount = v14; v15 < v14; ++v15 )
          {
            if ( *(_DWORD *)(*m_pData + 4 * v15) != 0 )
            {
              CDmxElement::AddElementsToDelete(
                this: *(CDmxElement **)(*m_pData + 4 * v15),
                (CUtlVector<CDmxElement *,CUtlMemory<CDmxElement *,int> > *)elementsToDelete);
              v14 = nElementCount;
            }
          }
          v2 = this;
        }
        v10 = i + 1;
        i = v10;
      }
      while ( v10 < nCount );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00560ED0
// Name: public: class CUtlString const __near & CDmxElement::GetValue<class CUtlString>(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
const CUtlString *__thiscall CDmxElement::GetValue<CUtlString>(CDmxElement *this, const char *pAttributeName)
{
  int v3; // edi
  CDmxAttribute *v4; // eax
  CDmxAttribute v6; // [esp+8h] [ebp-Ch] BYREF

  CDmxElement::Resort(this);
  CDmxAttribute::CDmxAttribute(this: &v6, pAttributeName);
  pAttributeName = (const char *)&v6;
  v3 = CUtlSortVector<CDmxAttribute *,CDmxAttributeLess>::Find(
         this: &this->m_Attributes,
         src: (CDmxAttribute *const **)&pAttributeName);
  CDmxAttribute::~CDmxAttribute(this: &v6);
  if ( v3 >= 0 && (v4 = this->m_Attributes.m_Memory.m_pMemory[v3]) != nullptr )
  {
    if ( v4->m_Type == AT_STRING )
    {
      return (const CUtlString *)v4->m_pData;
    }
    else
    {
      if ( (`CDmxAttribute::GetValue<CUtlString>'::`4'::`local static guard' & 1) == 0 )
      {
        `CDmxAttribute::GetValue<CUtlString>'::`4'::`local static guard' |= 1u;
        CUtlString::CUtlString(this: &`CDmxAttribute::GetValue<CUtlString>'::`4'::defaultValue);
        atexit(func: `CDmxAttribute::GetValue<CUtlString>'::`4'::`dynamic atexit destructor for 'defaultValue'');
      }
      CUtlString::Set(this: &`CDmxAttribute::GetValue<CUtlString>'::`4'::defaultValue, pValue: nullptr);
      return &`CDmxAttribute::GetValue<CUtlString>'::`4'::defaultValue;
    }
  }
  else
  {
    if ( (`CDmxElement::GetValue<CUtlString>'::`4'::`local static guard' & 1) == 0 )
    {
      `CDmxElement::GetValue<CUtlString>'::`4'::`local static guard' |= 1u;
      CUtlString::CUtlString(this: &`CDmxElement::GetValue<CUtlString>'::`4'::defaultValue);
      atexit(func: `CDmxElement::GetValue<CUtlString>'::`4'::`dynamic atexit destructor for 'defaultValue'');
    }
    CUtlString::Set(this: &`CDmxElement::GetValue<CUtlString>'::`4'::defaultValue, pValue: nullptr);
    return &`CDmxElement::GetValue<CUtlString>'::`4'::defaultValue;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00560FB0
// Name: public: char const __near * CDmxElement::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CDmxElement::GetName(CDmxElement *this)
{
  CUtlString *v1; // eax

  v1 = (CUtlString *)CDmxElement::GetValue<CUtlString>(this, pAttributeName: "name");
  return CUtlString::operator char const *(this: v1);
}

//------------------------------------------------------------------------------
// Address: 0x00560FD0
// Name: public: class CDmxAttribute __near * CDmxElement::AddAttribute(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDmxAttribute *__thiscall CDmxElement::AddAttribute(CDmxElement *this, CDmxAttribute *pAttributeName)
{
  const char *v3; // ebx
  int v4; // edi
  CDmxAttribute *v6; // eax
  const char *v7; // edi
  CDmxAttribute v9; // [esp+Ch] [ebp-Ch] BYREF

  CDmxElement::Resort(this);
  v3 = (const char *)pAttributeName;
  CDmxAttribute::CDmxAttribute(this: &v9, (const char *)pAttributeName);
  pAttributeName = &v9;
  v4 = CUtlSortVector<CDmxAttribute *,CDmxAttributeLess>::Find(
         this: &this->m_Attributes,
         src: (CDmxAttribute *const **)&pAttributeName);
  CDmxAttribute::~CDmxAttribute(this: &v9);
  if ( v4 >= 0 )
    return this->m_Attributes.m_Memory.m_pMemory[v4];
  ++this->m_nLockCount;
  *((_BYTE *)this + 49) |= 1u;
  v6 = (CDmxAttribute *)DMXAlloc(size: 0xCu);
  if ( v6 != nullptr )
    v7 = (const char *)CDmxAttribute::CDmxAttribute(this: v6, pAttributeName: v3);
  else
    v7 = nullptr;
  pAttributeName = (CDmxAttribute *)v7;
  CUtlSortVector<CDmxAttribute *,CDmxAttributeLess>::InsertNoSort(this: &this->m_Attributes, src: &pAttributeName);
  if ( this->m_nLockCount-- == 1 )
    CDmxElement::Resort(this);
  return (CDmxAttribute *)v7;
}

//------------------------------------------------------------------------------
// Address: 0x00561070
// Name: class CDmxElement __near * CreateDmxElement(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDmxElement *__cdecl CreateDmxElement(char *pType)
{
  char *v1; // esi
  CUtlSymbolLarge v3; // [esp+8h] [ebp-4h] BYREF

  v1 = (char *)DMXAlloc(size: 0x34u);
  if ( v1 == nullptr )
    return nullptr;
  *(_DWORD *)v1 = 0;
  *((_DWORD *)v1 + 1) = 0;
  *((_DWORD *)v1 + 2) = 0;
  *((_DWORD *)v1 + 3) = 0;
  *((_DWORD *)v1 + 4) = 0;
  *((_DWORD *)v1 + 5) = 0;
  v1[24] = 0;
  *((_DWORD *)v1 + 11) = -1;
  *((CUtlSymbolLarge *)v1 + 11) = (CUtlSymbolLarge)CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::AddString(
                                                     this: &CDmxElement::s_TypeSymbols,
                                                     result: &v3,
                                                     pString: pType)->u.m_Id;
  v1[49] &= 0xFCu;
  v1[48] = 0;
  CreateUniqueId(pDest: (UniqueId_t *)(v1 + 28));
  return (CDmxElement *)v1;
}

//------------------------------------------------------------------------------
// Address: 0x005610E0
// Name: private: void CDmxElement::RemoveAllElementsRecursive(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxElement::RemoveAllElementsRecursive(CDmxElement *this)
{
  int v1; // edi
  int v2; // ecx
  CDmxElement **m_pMemory; // eax
  CDmxElement *v4; // esi
  int m_Size; // ebx
  CDmxAttribute *v6; // ecx
  bool v8; // sf
  CDmxAttribute **v9; // eax
  CUtlVector<CDmxElement *,CUtlMemory<CDmxElement *,int> > elementsToDelete; // [esp+4h] [ebp-1Ch] BYREF
  int nCount; // [esp+18h] [ebp-8h]
  int i; // [esp+1Ch] [ebp-4h]

  v1 = 0;
  memset(&elementsToDelete, 0, sizeof(elementsToDelete));
  CDmxElement::AddElementsToDelete(this, (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&elementsToDelete);
  v2 = 0;
  nCount = elementsToDelete.m_Size;
  m_pMemory = elementsToDelete.m_Memory.m_pMemory;
  for ( i = 0; v2 < nCount; i = v2 )
  {
    v4 = m_pMemory[v2];
    if ( v4 != nullptr )
    {
      ++v4->m_nLockCount;
      m_Size = v4->m_Attributes.m_Size;
      if ( m_Size > 0 )
      {
        do
        {
          v6 = v4->m_Attributes.m_Memory.m_pMemory[v1];
          if ( v6 != nullptr )
            CDmxAttribute::~CDmxAttribute(this: v6);
          ++v1;
        }
        while ( v1 < m_Size );
      }
      *((_BYTE *)v4 + 49) &= ~1u;
      v4->m_Attributes.m_Size = 0;
      if ( v4->m_nLockCount-- == 1 )
        CDmxElement::Resort(this: v4);
      v8 = v4->m_Attributes.m_Memory.m_nGrowSize < 0;
      v4->m_Attributes.m_Size = 0;
      if ( !v8 )
      {
        if ( v4->m_Attributes.m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v4->m_Attributes.m_Memory.m_pMemory);
          v4->m_Attributes.m_Memory.m_pMemory = nullptr;
        }
        v4->m_Attributes.m_Memory.m_nAllocationCount = 0;
      }
      v8 = v4->m_Attributes.m_Memory.m_nGrowSize < 0;
      v9 = v4->m_Attributes.m_Memory.m_pMemory;
      v4->m_Attributes.m_pElements = v4->m_Attributes.m_Memory.m_pMemory;
      if ( !v8 )
      {
        if ( v9 != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v9);
          v4->m_Attributes.m_Memory.m_pMemory = nullptr;
        }
        v4->m_Attributes.m_Memory.m_nAllocationCount = 0;
      }
      m_pMemory = elementsToDelete.m_Memory.m_pMemory;
      v1 = 0;
    }
    v2 = i + 1;
  }
  elementsToDelete.m_Size = 0;
  if ( elementsToDelete.m_Memory.m_nGrowSize >= 0 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      m_pMemory = nullptr;
      elementsToDelete.m_Memory.m_pMemory = nullptr;
    }
    elementsToDelete.m_Memory.m_nAllocationCount = 0;
  }
  elementsToDelete.m_pElements = m_pMemory;
  if ( elementsToDelete.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x00561220
// Name: public: void CDmxElement::AddAttributesFromStructure(void const __near *,struct DmxElementUnpackStructure_t const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxElement::AddAttributesFromStructure(CDmxElement *this, char *pData, CDmxAttribute *pUnpack)
{
  bool v3; // zf
  const DmxElementUnpackStructure_t **i; // edi
  const DmxElementUnpackStructure_t *v5; // ebx
  char *v6; // ebx
  CDmxElement *v7; // esi
  CDmxElement *v8; // ebx
  CDmxAttribute *v9; // eax
  CDmxElement *v10; // ecx
  CDmxAttribute *v11; // esi
  _DWORD *m_pData; // esi
  CDmxElement *v13; // eax
  CDmxElement *v14; // ecx
  int v15; // eax
  const char *v16; // esi
  int v17; // esi
  CDmxElement *v18; // esi
  CDmxAttribute *v19; // ecx
  DmAttributeType_t v20; // eax
  const char *v21; // eax
  DmAttributeType_t v22; // eax
  int v23; // ecx
  int v24; // edx
  DmAttributeType_t v25; // esi
  int v26; // eax
  int v27; // edx
  int v28; // ecx
  int v29; // eax
  int v30; // ecx
  CDmxAttribute v31; // [esp+4h] [ebp-18h] BYREF
  CUtlSymbolLarge result; // [esp+10h] [ebp-Ch] BYREF
  int value; // [esp+14h] [ebp-8h] BYREF
  CDmxElement *v34; // [esp+18h] [ebp-4h]

  v3 = pUnpack->m_pData == nullptr;
  v34 = this;
  if ( !v3 )
  {
    for ( i = (const DmxElementUnpackStructure_t **)&pUnpack[3]; *(i - 7) != nullptr; i += 11 )
    {
      v5 = (const DmxElementUnpackStructure_t *)((char *)*(i - 6) + (_DWORD)pData);
      v3 = *i == nullptr;
      pUnpack = (CDmxAttribute *)v5;
      if ( v3 )
      {
        v15 = (int)*(i - 7);
        if ( (unsigned int)(v15 - 15) <= 0xD && (v15 == 19 || *(i - 4) != (const DmxElementUnpackStructure_t *)-1) )
          continue;
        if ( v15 == 6 )
          continue;
        if ( v15 == 20 )
          continue;
        v16 = (const char *)*(i - 9);
        CDmxElement::Resort(this: v34);
        CDmxAttribute::CDmxAttribute(this: &v31, pAttributeName: v16);
        pUnpack = &v31;
        v17 = CUtlSortVector<CDmxAttribute *,CDmxAttributeLess>::Find(
                this: &v34->m_Attributes,
                src: (CDmxAttribute *const **)&pUnpack);
        CDmxAttribute::~CDmxAttribute(this: &v31);
        if ( v17 >= 0 )
          continue;
        v18 = v34;
        ++v34->m_nLockCount;
        v19 = CDmxElement::AddAttribute(this: v18, pAttributeName: (CDmxAttribute *)*(i - 9));
        v20 = (DmAttributeType_t)*(i - 7);
        pUnpack = v19;
        if ( v20 == AT_STRING )
        {
          if ( *(i - 5) == (const DmxElementUnpackStructure_t *)-1 )
          {
            v21 = CUtlString::Get(this: (CUtlString *)v5);
            CDmxAttribute::SetValue(this: pUnpack, pString: v21);
          }
          else
          {
            CDmxAttribute::SetValue(this: v19, pString: (const char *)v5);
          }
        }
        else
        {
          v22 = CDmxAttribute::ArrayAttributeBasicType(type: v20);
          v23 = (int)*(i - 5);
          v24 = v23;
          if ( v22 == AT_FLOAT && v23 == 16 )
            v24 = 4;
          v25 = (DmAttributeType_t)*(i - 7);
          if ( (unsigned int)(v25 - 15) > 0xD )
          {
            v26 = (int)*(i - 4);
            if ( v26 == -1 )
            {
              CDmxAttribute::SetValue(this: pUnpack, type: v25, pSrc: v5, nLen: v24);
            }
            else
            {
              if ( v23 == 32 )
                v27 = -1;
              else
                v27 = ((1 << v23) - 1) << v26;
              v28 = (int)*(i - 3);
              v29 = v27 & (int)v5->m_pAttributeName;
              if ( v28 == 2 || v28 == 4 || v28 == 6 )
              {
                v30 = 32 - (_DWORD)*(i - 5) - (_DWORD)*(i - 4);
                v29 = v29 << v30 >> v30;
              }
              value = v29 >> (char)*(i - 4);
              CDmxAttribute::SetValue(this: pUnpack, type: v25, pSrc: &value, nLen: 4);
            }
          }
          else
          {
            CDmxAttribute::SetArrayValue(
              this: pUnpack,
              type: v25,
              pSrc: v5,
              nDataTypeSize: v24,
              nArrayLength: (int)i[1],
              nSrcStride: (int)*(i - 5));
          }
          v18 = v34;
        }
        v3 = v18->m_nLockCount-- == 1;
        if ( !v3 )
          continue;
        v14 = v34;
      }
      else
      {
        v6 = (char *)*(i - 1);
        v7 = (CDmxElement *)DMXAlloc(size: 0x34u);
        if ( v7 != nullptr )
        {
          v7->m_Attributes.m_Memory.m_pMemory = nullptr;
          v7->m_Attributes.m_Memory.m_nAllocationCount = 0;
          v7->m_Attributes.m_Memory.m_nGrowSize = 0;
          v7->m_Attributes.m_Size = 0;
          v7->m_Attributes.m_pElements = nullptr;
          v7->m_Attributes.m_pLessContext = nullptr;
          v7->m_Attributes.m_bNeedsSort = false;
          v7->m_Type.u.m_Id = -1;
          v7->m_Type = (CUtlSymbolLarge)CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::AddString(
                                          this: &CDmxElement::s_TypeSymbols,
                                          &result,
                                          pString: v6)->u.m_Id;
          *((_BYTE *)v7 + 49) &= 0xFCu;
          v7->m_nLockCount = 0;
          CreateUniqueId(pDest: &v7->m_Id);
          v8 = v7;
        }
        else
        {
          v8 = nullptr;
        }
        CDmxElement::AddAttributesFromStructure(this: v8, pData: pUnpack, pUnpack: *i);
        v9 = (CDmxAttribute *)*(i - 9);
        v10 = v34;
        ++v34->m_nLockCount;
        v11 = CDmxElement::AddAttribute(this: v10, pAttributeName: v9);
        CDmxAttribute::AllocateDataMemory(this: v11, type: AT_FIRST_VALUE_TYPE);
        m_pData = v11->m_pData;
        if ( m_pData != nullptr )
          *m_pData = v8;
        v13 = v34;
        v3 = v34->m_nLockCount-- == 1;
        if ( !v3 )
          continue;
        v14 = v13;
      }
      CDmxElement::Resort(this: v14);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0056DAC0
// Name: _dynamic_initializer_for__CDmxElement::s_TypeSymbols__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmxElement::s_TypeSymbols__()
{
  CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>(this: &CDmxElement::s_TypeSymbols);
  return atexit(func: dynamic_atexit_destructor_for__CDmxElement::s_TypeSymbols__);
}

//------------------------------------------------------------------------------
// Address: 0x0056F670
// Name: _dynamic_atexit_destructor_for__CDmxElement::s_TypeSymbols__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmxElement::s_TypeSymbols__()
{
  CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::RemoveAll(this: &CDmxElement::s_TypeSymbols);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&CDmxElement::s_TypeSymbols.m_StringPools);
  CUtlTSHash<CUtlSymbolTableLargeBaseTreeEntry_t *,2048,CUtlSymbolTableLargeBaseTreeEntry_t *,CCThreadsafeTreeHashMethod<2048,CUtlSymbolTableLargeBaseTreeEntry_t *,0>,0>::RemoveAll(this: &CDmxElement::s_TypeSymbols.m_Lookup);
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmxElement::s_TypeSymbols.m_Lookup.m_EntryMemory);
}

} // namespace particle_import

// ============================================================
// Overlay from QCGenerator (Missing functions)
// ============================================================
namespace QCGenerator {

//------------------------------------------------------------------------------
// Address: 0x00484670
// Name: public: void CUtlSymbolTableLargeBase<class CNonThreadsafeTree<0>,0>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlSymbolTableLargeBase<CNonThreadsafeTree<0>,0>::RemoveAll(
        CUtlSymbolTableLargeBase<CNonThreadsafeTree<0>,0> *this)
{
  int i; // edi

  CUtlRBTree<CUtlSymbolTableLargeBaseTreeEntry_t *,int,CTreeEntryLess<CNonThreadsafeTree<0>,0>,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int>,int>>::RemoveAll(this: &this->m_Lookup);
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
// Address: 0x004846E0
// Name: public: CUtlTSHash<struct CUtlSymbolTableLargeBaseTreeEntry_t __near *,2048,struct CUtlSymbolTableLargeBaseTreeEntry_t __near *,class CCThreadsafeTreeHashMethod<2048,struct CUtlSymbolTableLargeBaseTreeEntry_t __near *,0>,0>::CUtlTSHash<struct CUtlSymbolTableLargeBaseTreeEntry_t __near *,2048,struct CUtlSymbolTableLargeBaseTreeEntry_t __near *,class CCThreadsafeTreeHashMethod<2048,struct CUtlSymbolTableLargeBaseTreeEntry_t __near *,0>,0>(int)
// Source: json
//------------------------------------------------------------------------------
CUtlTSHash<CUtlSymbolTableLargeBaseTreeEntry_t *,2048,CUtlSymbolTableLargeBaseTreeEntry_t *,CCThreadsafeTreeHashMethod<2048,CUtlSymbolTableLargeBaseTreeEntry_t *,0>,0> *__thiscall CUtlTSHash<CUtlSymbolTableLargeBaseTreeEntry_t *,2048,CUtlSymbolTableLargeBaseTreeEntry_t *,CCThreadsafeTreeHashMethod<2048,CUtlSymbolTableLargeBaseTreeEntry_t *,0>,0>::CUtlTSHash<CUtlSymbolTableLargeBaseTreeEntry_t *,2048,CUtlSymbolTableLargeBaseTreeEntry_t *,CCThreadsafeTreeHashMethod<2048,CUtlSymbolTableLargeBaseTreeEntry_t *,0>,0>(
        CUtlTSHash<CUtlSymbolTableLargeBaseTreeEntry_t *,2048,CUtlSymbolTableLargeBaseTreeEntry_t *,CCThreadsafeTreeHashMethod<2048,CUtlSymbolTableLargeBaseTreeEntry_t *,0>,0> *this,
        int nAllocationCount)
{
  int v3; // ebp
  CThreadSpinRWLock *p_m_AddLock; // edi
  CUtlTSHash<CUtlSymbolTableLargeBaseTreeEntry_t *,2048,CUtlSymbolTableLargeBaseTreeEntry_t *,CCThreadsafeTreeHashMethod<2048,CUtlSymbolTableLargeBaseTreeEntry_t *,0>,0>::HashBucket_t *m_aBuckets; // eax
  int i; // ecx

  CUtlMemoryPool::CUtlMemoryPool(
    this: &this->m_EntryMemory,
    blockSize: 12,
    numElements: nAllocationCount,
    growMode: 2,
    pszAllocOwner: nullptr,
    nAlignment: 0);
  this->m_EntryMemory.m_mutex.m_ownerID = 0;
  this->m_EntryMemory.m_mutex.m_depth = 0;
  v3 = 2047;
  p_m_AddLock = &this->m_aBuckets[0].m_AddLock;
  do
  {
    CThreadSpinRWLock::CThreadSpinRWLock(this: p_m_AddLock);
    p_m_AddLock = (CThreadSpinRWLock *)((char *)p_m_AddLock + 24);
    --v3;
  }
  while ( v3 >= 0 );
  this->m_bNeedsCommit = false;
  m_aBuckets = this->m_aBuckets;
  for ( i = 2048; i != 0; --i )
  {
    m_aBuckets->m_pFirst = nullptr;
    m_aBuckets->m_pFirstUncommitted = nullptr;
    ++m_aBuckets;
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00484750
// Name: public: void CUtlTSHash<struct CUtlSymbolTableLargeBaseTreeEntry_t __near *,2048,struct CUtlSymbolTableLargeBaseTreeEntry_t __near *,class CCThreadsafeTreeHashMethod<2048,struct CUtlSymbolTableLargeBaseTreeEntry_t __near *,0>,0>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlTSHash<CUtlSymbolTableLargeBaseTreeEntry_t *,2048,CUtlSymbolTableLargeBaseTreeEntry_t *,CCThreadsafeTreeHashMethod<2048,CUtlSymbolTableLargeBaseTreeEntry_t *,0>,0>::RemoveAll(
        CUtlTSHash<CUtlSymbolTableLargeBaseTreeEntry_t *,2048,CUtlSymbolTableLargeBaseTreeEntry_t *,CCThreadsafeTreeHashMethod<2048,CUtlSymbolTableLargeBaseTreeEntry_t *,0>,0> *this)
{
  bool v1; // zf
  CUtlTSHash<CUtlSymbolTableLargeBaseTreeEntry_t *,2048,CUtlSymbolTableLargeBaseTreeEntry_t *,CCThreadsafeTreeHashMethod<2048,CUtlSymbolTableLargeBaseTreeEntry_t *,0>,0>::HashFixedDataInternal_t<CUtlSymbolTableLargeBaseTreeEntry_t *> **p_m_pFirstUncommitted; // esi
  int i; // edi
  CUtlTSHash<CUtlSymbolTableLargeBaseTreeEntry_t *,2048,CUtlSymbolTableLargeBaseTreeEntry_t *,CCThreadsafeTreeHashMethod<2048,CUtlSymbolTableLargeBaseTreeEntry_t *,0>,0>::HashFixedDataInternal_t<CUtlSymbolTableLargeBaseTreeEntry_t *> *j; // eax
  CThreadFastMutex *p_m_mutex; // esi
  DWORD CurrentThreadId; // ecx

  v1 = this->m_EntryMemory.m_BlocksAllocated == 0;
  this->m_bNeedsCommit = false;
  if ( !v1 )
  {
    p_m_pFirstUncommitted = &this->m_aBuckets[0].m_pFirstUncommitted;
    for ( i = 2048; i != 0; --i )
    {
      CThreadSpinRWLock::LockForWrite(this: (CThreadSpinRWLock *)(p_m_pFirstUncommitted + 1));
      for ( j = *p_m_pFirstUncommitted; j != nullptr; j = j->m_pNext )
        ;
      *(p_m_pFirstUncommitted - 1) = nullptr;
      *p_m_pFirstUncommitted = nullptr;
      CThreadSpinRWLock::UnlockWrite(this: (CThreadSpinRWLock *)(p_m_pFirstUncommitted + 1));
      p_m_pFirstUncommitted += 6;
    }
    p_m_mutex = &this->m_EntryMemory.m_mutex;
    CurrentThreadId = GetCurrentThreadId();
    if ( CurrentThreadId != this->m_EntryMemory.m_mutex.m_ownerID
      && _InterlockedCompareExchange((volatile signed __int32 *)p_m_mutex, CurrentThreadId, 0) != 0 )
    {
      _mm_pause();
      CThreadFastMutex::Lock(a1: p_m_mutex, a2: CurrentThreadId, a3: 0);
    }
    else
    {
      ++this->m_EntryMemory.m_mutex.m_depth;
    }
    CUtlMemoryPool::Clear(this: &this->m_EntryMemory);
    v1 = this->m_EntryMemory.m_mutex.m_depth-- == 1;
    if ( v1 )
      _InterlockedExchange((volatile __int32 *)p_m_mutex, 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00484800
// Name: public: void CUtlSymbolTableLargeBase<class CThreadsafeTree<0>,0>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::RemoveAll(
        CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0> *this)
{
  int i; // edi

  CUtlTSHash<CUtlSymbolTableLargeBaseTreeEntry_t *,2048,CUtlSymbolTableLargeBaseTreeEntry_t *,CCThreadsafeTreeHashMethod<2048,CUtlSymbolTableLargeBaseTreeEntry_t *,0>,0>::RemoveAll(this: &this->m_Lookup);
  for ( i = 0; i < this->m_StringPools.m_Size; ++i )
    free(pMem: this->m_StringPools.m_Memory.m_pMemory[i]);
  this->m_StringPools.m_Size = 0;
}

} // namespace QCGenerator

// ============================================================
// Overlay from sceneviewer (Missing functions)
// ============================================================
namespace sceneviewer {

//------------------------------------------------------------------------------
// Address: 0x00444270
// Name: public: struct UniqueId_t const __near & CDmxElement::GetId(void)const
// Source: json
//------------------------------------------------------------------------------
const UniqueId_t *__thiscall CDmxElement::GetId(CDmxElement *this)
{
  return &this->m_Id;
}

//------------------------------------------------------------------------------
// Address: 0x004C71E0
// Name: public: class Vector const __near & CDmxElement::GetValue<class Vector>(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
const Vector *__thiscall CDmxElement::GetValue<Vector>(CDmxElement *this, const char *pAttributeName)
{
  const CDmxAttribute *Attribute; // eax

  Attribute = CDmxElement::GetAttribute(this, pAttributeName);
  if ( Attribute != nullptr )
  {
    if ( Attribute->m_Type == AT_VECTOR3 )
    {
      return (const Vector *)Attribute->m_pData;
    }
    else
    {
      if ( (`CDmxAttribute::GetValue<Vector>'::`4'::`local static guard' & 1) == 0 )
        `CDmxAttribute::GetValue<Vector>'::`4'::`local static guard' |= 1u;
      `CDmxAttribute::GetValue<Vector>'::`4'::defaultValue = 0;
      dword_7BABC8 = 0;
      dword_7BABCC = 0;
      return (const Vector *)&`CDmxAttribute::GetValue<Vector>'::`4'::defaultValue;
    }
  }
  else
  {
    if ( (`CDmxElement::GetValue<Vector>'::`4'::`local static guard' & 1) == 0 )
      `CDmxElement::GetValue<Vector>'::`4'::`local static guard' |= 1u;
    `CDmxElement::GetValue<Vector>'::`4'::defaultValue.x = 0.0;
    `CDmxElement::GetValue<Vector>'::`4'::defaultValue.y = 0.0;
    `CDmxElement::GetValue<Vector>'::`4'::defaultValue.z = 0.0;
    return &`CDmxElement::GetValue<Vector>'::`4'::defaultValue;
  }
}

//------------------------------------------------------------------------------
// Address: 0x006A0ED0
// Name: public: char const __near * CDmxElement::GetTypeString(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CDmxElement::GetTypeString(CDmxElement *this)
{
  const char *result; // eax

  result = this->m_Type.u.m_pAsString;
  if ( result == (const char *)-1 )
    return defaultValue;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x006A0EE0
// Name: private: void CDmxElement::SetId(struct UniqueId_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxElement::SetId(CDmxElement *this, const UniqueId_t *id)
{
  CopyUniqueId(src: id, pDest: &this->m_Id);
}

//------------------------------------------------------------------------------
// Address: 0x006A0F00
// Name: private: void CDmxElement::UnpackBitfield<unsigned char>(unsigned char __near *,struct DmxElementUnpackStructure_t const __near *,class CDmxAttribute const __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxElement::UnpackBitfield<unsigned char>(
        CDmxElement *this,
        unsigned __int8 *pDest,
        const DmxElementUnpackStructure_t *pUnpack,
        const CDmxAttribute *pAttribute)
{
  int m_nSize; // ecx
  char v6; // bl
  char v7; // al
  unsigned __int8 v8; // al
  char mask_3; // [esp+1Bh] [ebp+Fh]

  m_nSize = pUnpack->m_nSize;
  if ( m_nSize == 8 )
  {
    v6 = -1;
    v7 = -1;
  }
  else
  {
    v6 = (1 << m_nSize) - 1;
    v7 = v6 << pUnpack->m_nBitOffset;
  }
  mask_3 = ~v7;
  v8 = *(_BYTE *)pAttribute->m_pData;
  if ( ((unsigned __int8)~v6 & v8) != 0 )
  {
    _Warning(a1: "Value %s exeeds size of datatype. \n", pUnpack->m_pAttributeName);
    v8 = 0;
  }
  *pDest &= mask_3;
  *pDest |= ((unsigned __int8)v6 & v8) << pUnpack->m_nBitOffset;
}

//------------------------------------------------------------------------------
// Address: 0x006A0F70
// Name: private: void CDmxElement::UnpackBitfield<char>(char __near *,struct DmxElementUnpackStructure_t const __near *,class CDmxAttribute const __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxElement::UnpackBitfield<char>(
        CDmxElement *this,
        char *pDest,
        const DmxElementUnpackStructure_t *pUnpack,
        const CDmxAttribute *pAttribute)
{
  int m_nSize; // edx
  char v6; // bl
  char v7; // al
  char v8; // al
  char v9; // dl
  char mask_3; // [esp+1Bh] [ebp+Fh]

  m_nSize = pUnpack->m_nSize;
  if ( m_nSize == 8 )
  {
    v6 = -1;
    v7 = -1;
  }
  else
  {
    v6 = (1 << m_nSize) - 1;
    v7 = v6 << pUnpack->m_nBitOffset;
  }
  mask_3 = ~v7;
  v8 = *(_BYTE *)pAttribute->m_pData;
  v9 = (1 << (m_nSize - 1)) - 1;
  if ( v8 < 0 )
  {
    if ( (~v9 & v8) != ~v9 )
    {
LABEL_8:
      _Warning(a1: "Value %s exeeds size of datatype. \n", pUnpack->m_pAttributeName);
      v8 = 0;
    }
  }
  else if ( (~v9 & v8) != 0 )
  {
    goto LABEL_8;
  }
  *pDest &= mask_3;
  *pDest |= ((unsigned __int8)v6 & (unsigned __int8)v8) << pUnpack->m_nBitOffset;
}

//------------------------------------------------------------------------------
// Address: 0x006A1000
// Name: private: void CDmxElement::UnpackBitfield<short>(short __near *,struct DmxElementUnpackStructure_t const __near *,class CDmxAttribute const __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxElement::UnpackBitfield<short>(
        CDmxElement *this,
        __int16 *pDest,
        const DmxElementUnpackStructure_t *pUnpack,
        const CDmxAttribute *pAttribute)
{
  int m_nSize; // edx
  __int16 v5; // bx
  __int16 v6; // ax
  __int16 v7; // di
  __int16 v8; // ax
  int v9; // ecx
  bool v10; // zf

  m_nSize = pUnpack->m_nSize;
  if ( m_nSize == 16 )
  {
    v5 = -1;
    v6 = -1;
  }
  else
  {
    v5 = (1 << m_nSize) - 1;
    v6 = v5 << pUnpack->m_nBitOffset;
  }
  v7 = ~v6;
  v8 = *(_WORD *)pAttribute->m_pData;
  v9 = ~(__int16)((1 << (m_nSize - 1)) - 1);
  if ( v8 < 0 )
    v10 = (v9 & v8) == v9;
  else
    v10 = (v9 & v8) == 0;
  if ( !v10 )
  {
    _Warning(a1: "Value %s exeeds size of datatype. \n", pUnpack->m_pAttributeName);
    v8 = 0;
  }
  *pDest &= v7;
  *pDest |= ((unsigned __int16)v5 & (unsigned __int16)v8) << pUnpack->m_nBitOffset;
}

//------------------------------------------------------------------------------
// Address: 0x006A10A0
// Name: private: void CDmxElement::UnpackBitfield<unsigned short>(unsigned short __near *,struct DmxElementUnpackStructure_t const __near *,class CDmxAttribute const __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxElement::UnpackBitfield<unsigned short>(
        CDmxElement *this,
        unsigned __int16 *pDest,
        const DmxElementUnpackStructure_t *pUnpack,
        const CDmxAttribute *pAttribute)
{
  int m_nSize; // ecx
  unsigned __int16 v5; // si
  __int16 v6; // ax
  __int16 v7; // bx
  int v8; // ecx

  m_nSize = pUnpack->m_nSize;
  if ( m_nSize == 16 )
  {
    v5 = -1;
    v6 = -1;
  }
  else
  {
    v5 = (1 << m_nSize) - 1;
    v6 = v5 << pUnpack->m_nBitOffset;
  }
  v7 = ~v6;
  v8 = *(unsigned __int16 *)pAttribute->m_pData;
  if ( (~v5 & v8) != 0 )
  {
    _Warning(a1: "Value %s exeeds size of datatype. \n", pUnpack->m_pAttributeName);
    LOWORD(v8) = 0;
  }
  *pDest &= v7;
  *pDest |= (v5 & (unsigned __int16)v8) << pUnpack->m_nBitOffset;
}

//------------------------------------------------------------------------------
// Address: 0x006A1120
// Name: private: void CDmxElement::UnpackBitfield<int>(int __near *,struct DmxElementUnpackStructure_t const __near *,class CDmxAttribute const __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxElement::UnpackBitfield<int>(
        CDmxElement *this,
        int *pDest,
        const DmxElementUnpackStructure_t *pUnpack,
        const CDmxAttribute *pAttribute)
{
  int m_nSize; // edx
  int v5; // esi
  int v6; // eax
  int v7; // ebx
  int v8; // eax
  int v9; // edx
  bool v10; // zf

  m_nSize = pUnpack->m_nSize;
  if ( m_nSize == 32 )
  {
    v5 = -1;
    v6 = -1;
  }
  else
  {
    v5 = (1 << m_nSize) - 1;
    v6 = v5 << pUnpack->m_nBitOffset;
  }
  v7 = ~v6;
  v8 = *(_DWORD *)pAttribute->m_pData;
  v9 = ~((1 << (m_nSize - 1)) - 1);
  if ( v8 < 0 )
    v10 = (v8 & v9) == v9;
  else
    v10 = (v9 & v8) == 0;
  if ( !v10 )
  {
    _Warning(a1: "Value %s exeeds size of datatype. \n", pUnpack->m_pAttributeName);
    v8 = 0;
  }
  *pDest &= v7;
  *pDest |= (v5 & v8) << pUnpack->m_nBitOffset;
}

//------------------------------------------------------------------------------
// Address: 0x006A11A0
// Name: private: void CDmxElement::UnpackBitfield<unsigned int>(unsigned int __near *,struct DmxElementUnpackStructure_t const __near *,class CDmxAttribute const __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxElement::UnpackBitfield<unsigned int>(
        CDmxElement *this,
        unsigned int *pDest,
        const DmxElementUnpackStructure_t *pUnpack,
        const CDmxAttribute *pAttribute)
{
  int m_nSize; // ecx
  int v5; // esi
  int v6; // eax
  int v7; // edi
  int v8; // eax

  m_nSize = pUnpack->m_nSize;
  if ( m_nSize == 32 )
  {
    v5 = -1;
    v6 = -1;
  }
  else
  {
    v5 = (1 << m_nSize) - 1;
    v6 = v5 << pUnpack->m_nBitOffset;
  }
  v7 = ~v6;
  v8 = *(_DWORD *)pAttribute->m_pData;
  if ( (~v5 & v8) != 0 )
  {
    _Warning(a1: "Value %s exeeds size of datatype. \n", pUnpack->m_pAttributeName);
    v8 = 0;
  }
  *pDest &= v7;
  *pDest |= (v5 & v8) << pUnpack->m_nBitOffset;
}

//------------------------------------------------------------------------------
// Address: 0x006A1430
// Name: private: void CDmxElement::Resort(void)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxElement::Resort(CDmxElement *this)
{
  signed int m_Size; // eax
  int i; // edi
  CDmxAttribute **v4; // eax
  const char *Name; // eax
  _DWORD context[2]; // [esp+4h] [ebp-Ch] BYREF
  char v7; // [esp+Fh] [ebp-1h] BYREF

  if ( (*((_BYTE *)this + 49) & 1) != 0 )
  {
    if ( this->m_Attributes.m_bNeedsSort )
    {
      m_Size = this->m_Attributes.m_Size;
      this->m_Attributes.m_bNeedsSort = false;
      if ( m_Size > 1 )
      {
        context[0] = this->m_Attributes.m_pLessContext;
        context[1] = &v7;
        qsort_s(
          base: this->m_Attributes.m_Memory.m_pMemory,
          num: m_Size,
          width: 4u,
          comp: (int (__cdecl *)(void *, const void *, const void *))CUtlSortVector<CDmxAttribute *,CDmxAttributeLess>::CompareHelper,
          context);
      }
    }
    *((_BYTE *)this + 49) &= ~1u;
    for ( i = this->m_Attributes.m_Size - 1; i >= 1; --i )
    {
      v4 = &this->m_Attributes.m_Memory.m_pMemory[i];
      if ( *v4 != nullptr && *(v4 - 1) != nullptr && (*v4)->m_Name.u.m_Id == (*(v4 - 1))->m_Name.u.m_Id )
      {
        Name = CDmxAttribute::GetName(this: *v4);
        _Warning(a1: "Duplicate attribute name %s encountered!\n", Name);
        if ( this->m_Attributes.m_Size - i - 1 > 0 )
          _V_memmove(
            dest: &this->m_Attributes.m_Memory.m_pMemory[i],
            src: &this->m_Attributes.m_Memory.m_pMemory[i + 1],
            count: 4 * (this->m_Attributes.m_Size - i - 1));
        --this->m_Attributes.m_Size;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x006A1500
// Name: public: void CDmxElement::LockForChanges(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxElement::LockForChanges(CDmxElement *this, bool bLock)
{
  if ( bLock )
  {
    ++this->m_nLockCount;
  }
  else if ( this->m_nLockCount-- == 1 )
  {
    CDmxElement::Resort(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x006A1520
// Name: public: bool CDmxElement::HasAttribute(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CDmxElement::HasAttribute(CDmxElement *this, const char *pAttributeName)
{
  int v3; // esi
  CDmxAttribute v5; // [esp+4h] [ebp-Ch] BYREF

  CDmxElement::Resort(this);
  CDmxAttribute::CDmxAttribute(this: &v5, pAttributeName);
  pAttributeName = (const char *)&v5;
  v3 = CUtlSortVector<CDmxAttribute *,CDmxAttributeLess>::Find(
         this: &this->m_Attributes,
         src: (CDmxAttribute *const *)&pAttributeName);
  CDmxAttribute::~CDmxAttribute(this: &v5);
  return v3 >= 0;
}

//------------------------------------------------------------------------------
// Address: 0x006A1570
// Name: public: class CDmxAttribute const __near * CDmxElement::GetAttribute(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
const CDmxAttribute *__thiscall CDmxElement::GetAttribute(CDmxElement *this, const char *pAttributeName)
{
  int v3; // edi
  CDmxAttribute v5; // [esp+8h] [ebp-Ch] BYREF

  CDmxElement::Resort(this);
  CDmxAttribute::CDmxAttribute(this: &v5, pAttributeName);
  pAttributeName = (const char *)&v5;
  v3 = CUtlSortVector<CDmxAttribute *,CDmxAttributeLess>::Find(
         this: &this->m_Attributes,
         src: (CDmxAttribute *const *)&pAttributeName);
  CDmxAttribute::~CDmxAttribute(this: &v5);
  if ( v3 < 0 )
    return nullptr;
  else
    return this->m_Attributes.m_Memory.m_pMemory[v3];
}

//------------------------------------------------------------------------------
// Address: 0x006A15D0
// Name: private: void CDmxElement::AddElementsToDelete(class CUtlVector<class CDmxElement __near *,class CUtlMemory<class CDmxElement __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxElement::AddElementsToDelete(CDmxElement *this, CUtlMemory<vgui::TreeNode *,int> *elementsToDelete)
{
  CDmxElement *v2; // ebx
  char v3; // al
  int m_pMemory; // esi
  int m_nAllocationCount; // eax
  CDmxElement **v7; // ecx
  int v8; // eax
  CDmxElement **v9; // esi
  int v10; // eax
  CDmxAttribute *v11; // eax
  CDmxElement *v12; // ecx
  _DWORD *m_pData; // ebx
  int v14; // ecx
  int v15; // esi
  int nCount; // [esp+4h] [ebp-Ch]
  int nElementCount; // [esp+8h] [ebp-8h]
  int i; // [esp+18h] [ebp+8h]

  v2 = this;
  v3 = *((_BYTE *)this + 49);
  if ( (v3 & 2) == 0 )
  {
    *((_BYTE *)this + 49) = v3 | 2;
    m_pMemory = (int)elementsToDelete[1].m_pMemory;
    m_nAllocationCount = elementsToDelete->m_nAllocationCount;
    if ( m_pMemory + 1 > m_nAllocationCount )
      CUtlMemory<IDmFormatUpdater *,int>::Grow(this: elementsToDelete, num: m_pMemory - m_nAllocationCount + 1);
    ++elementsToDelete[1].m_pMemory;
    v7 = (CDmxElement **)elementsToDelete->m_pMemory;
    v8 = (int)elementsToDelete[1].m_pMemory - m_pMemory - 1;
    elementsToDelete[1].m_nAllocationCount = (int)elementsToDelete->m_pMemory;
    if ( v8 > 0 )
      _V_memmove(dest: &v7[m_pMemory + 1], src: &v7[m_pMemory], count: 4 * v8);
    v9 = (CDmxElement **)&elementsToDelete->m_pMemory[m_pMemory];
    if ( v9 != nullptr )
      *v9 = v2;
    v10 = 0;
    nCount = v2->m_Attributes.m_Size;
    i = 0;
    if ( nCount > 0 )
    {
      do
      {
        v11 = v2->m_Attributes.m_Memory.m_pMemory[v10];
        if ( v11->m_Type == AT_FIRST_VALUE_TYPE )
        {
          v12 = *(CDmxElement **)v11->m_pData;
          if ( v12 != nullptr )
            CDmxElement::AddElementsToDelete(
              this: v12,
              (CUtlVector<CDmxElement *,CUtlMemory<CDmxElement *,int> > *)elementsToDelete);
        }
        else if ( v11->m_Type == AT_FIRST_ARRAY_TYPE )
        {
          m_pData = v11->m_pData;
          v14 = m_pData[3];
          v15 = 0;
          for ( nElementCount = v14; v15 < v14; ++v15 )
          {
            if ( *(_DWORD *)(*m_pData + 4 * v15) != 0 )
            {
              CDmxElement::AddElementsToDelete(
                this: *(CDmxElement **)(*m_pData + 4 * v15),
                (CUtlVector<CDmxElement *,CUtlMemory<CDmxElement *,int> > *)elementsToDelete);
              v14 = nElementCount;
            }
          }
          v2 = this;
        }
        v10 = i + 1;
        i = v10;
      }
      while ( v10 < nCount );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x006A16C0
// Name: public: class CUtlString const __near & CDmxElement::GetValue<class CUtlString>(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
const CUtlString *__thiscall CDmxElement::GetValue<CUtlString>(CDmxElement *this, const char *pAttributeName)
{
  int v3; // edi
  CDmxAttribute *v4; // eax
  CDmxAttribute v6; // [esp+8h] [ebp-Ch] BYREF

  CDmxElement::Resort(this);
  CDmxAttribute::CDmxAttribute(this: &v6, pAttributeName);
  pAttributeName = (const char *)&v6;
  v3 = CUtlSortVector<CDmxAttribute *,CDmxAttributeLess>::Find(
         this: &this->m_Attributes,
         src: (CDmxAttribute *const *)&pAttributeName);
  CDmxAttribute::~CDmxAttribute(this: &v6);
  if ( v3 >= 0 && (v4 = this->m_Attributes.m_Memory.m_pMemory[v3]) != nullptr )
  {
    if ( v4->m_Type == AT_STRING )
    {
      return (const CUtlString *)v4->m_pData;
    }
    else
    {
      if ( (`CDmxAttribute::GetValue<CUtlString>'::`4'::`local static guard' & 1) == 0 )
      {
        `CDmxAttribute::GetValue<CUtlString>'::`4'::`local static guard' |= 1u;
        CUtlString::CUtlString(this: &`CDmxAttribute::GetValue<CUtlString>'::`4'::defaultValue);
        atexit(func: `CDmxAttribute::GetValue<CUtlString>'::`4'::`dynamic atexit destructor for 'defaultValue'');
      }
      CUtlString::Set(this: &`CDmxAttribute::GetValue<CUtlString>'::`4'::defaultValue, pValue: nullptr);
      return &`CDmxAttribute::GetValue<CUtlString>'::`4'::defaultValue;
    }
  }
  else
  {
    if ( (`CDmxElement::GetValue<CUtlString>'::`4'::`local static guard' & 1) == 0 )
    {
      `CDmxElement::GetValue<CUtlString>'::`4'::`local static guard' |= 1u;
      CUtlString::CUtlString(this: &`CDmxElement::GetValue<CUtlString>'::`4'::defaultValue);
      atexit(func: `CDmxElement::GetValue<CUtlString>'::`4'::`dynamic atexit destructor for 'defaultValue'');
    }
    CUtlString::Set(this: &`CDmxElement::GetValue<CUtlString>'::`4'::defaultValue, pValue: nullptr);
    return &`CDmxElement::GetValue<CUtlString>'::`4'::defaultValue;
  }
}

//------------------------------------------------------------------------------
// Address: 0x006A17F0
// Name: private: CDmxElement::CDmxElement(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDmxElement *__thiscall CDmxElement::CDmxElement(CDmxElement *this, char *pType)
{
  char *v4; // [esp-4h] [ebp-Ch]

  v4 = pType;
  this->m_Attributes.m_Memory.m_pMemory = nullptr;
  this->m_Attributes.m_Memory.m_nAllocationCount = 0;
  this->m_Attributes.m_Memory.m_nGrowSize = 0;
  this->m_Attributes.m_Size = 0;
  this->m_Attributes.m_pElements = nullptr;
  this->m_Attributes.m_pLessContext = nullptr;
  this->m_Attributes.m_bNeedsSort = false;
  this->m_Type.u.m_Id = -1;
  this->m_Type = (CUtlSymbolLarge)CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::AddString(
                                    this: &CDmxElement::s_TypeSymbols,
                                    result: (CUtlSymbolLarge *)&pType,
                                    pString: v4)->u.m_Id;
  *((_BYTE *)this + 49) &= 0xFCu;
  this->m_nLockCount = 0;
  CreateUniqueId(pDest: &this->m_Id);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x006A1850
// Name: public: char const __near * CDmxElement::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CDmxElement::GetName(CDmxElement *this)
{
  CUtlString *v1; // eax

  v1 = (CUtlString *)CDmxElement::GetValue<CUtlString>(this, pAttributeName: "name");
  return CUtlString::operator char const *(this: v1);
}

//------------------------------------------------------------------------------
// Address: 0x006A1870
// Name: public: class CDmxAttribute __near * CDmxElement::AddAttribute(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDmxAttribute *__thiscall CDmxElement::AddAttribute(CDmxElement *this, CDmxAttribute *pAttributeName)
{
  const char *v3; // ebx
  int v4; // edi
  CDmxAttribute *v6; // eax
  const char *v7; // edi
  CDmxAttribute v9; // [esp+Ch] [ebp-Ch] BYREF

  CDmxElement::Resort(this);
  v3 = (const char *)pAttributeName;
  CDmxAttribute::CDmxAttribute(this: &v9, (const char *)pAttributeName);
  pAttributeName = &v9;
  v4 = CUtlSortVector<CDmxAttribute *,CDmxAttributeLess>::Find(this: &this->m_Attributes, src: &pAttributeName);
  CDmxAttribute::~CDmxAttribute(this: &v9);
  if ( v4 >= 0 )
    return this->m_Attributes.m_Memory.m_pMemory[v4];
  ++this->m_nLockCount;
  *((_BYTE *)this + 49) |= 1u;
  v6 = (CDmxAttribute *)DMXAlloc(size: 0xCu);
  if ( v6 != nullptr )
    v7 = (const char *)CDmxAttribute::CDmxAttribute(this: v6, pAttributeName: v3);
  else
    v7 = nullptr;
  pAttributeName = (CDmxAttribute *)v7;
  CUtlSortVector<CDmxAttribute *,CDmxAttributeLess>::InsertNoSort(this: &this->m_Attributes, src: &pAttributeName);
  if ( this->m_nLockCount-- == 1 )
    CDmxElement::Resort(this);
  return (CDmxAttribute *)v7;
}

//------------------------------------------------------------------------------
// Address: 0x006A1910
// Name: public: void CDmxElement::UnpackIntoStructure(void __near *,struct DmxElementUnpackStructure_t const __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxElement::UnpackIntoStructure(CDmxElement *this, void *pData, CDmxAttribute *pUnpack)
{
  bool v3; // zf
  const char **p_m_Name; // edi
  CUtlString *v5; // ebx
  const char *v6; // eax
  const char *v7; // esi
  int v8; // esi
  CDmxAttribute *p_temp; // esi
  CUtlString *m_pData; // ecx
  const char *v11; // eax
  const char *v12; // eax
  const CUtlVector<float,CUtlMemory<float,int> > *v13; // eax
  int v14; // ecx
  int *p_m_nGrowSize; // edx
  DmAttributeType_t v16; // eax
  CDmxAttribute v17; // [esp+4h] [ebp-1Ch] BYREF
  CDmxAttribute temp; // [esp+10h] [ebp-10h] BYREF
  CDmxElement *v19; // [esp+1Ch] [ebp-4h]

  v3 = pUnpack->m_pData == nullptr;
  v19 = this;
  if ( !v3 )
  {
    p_m_Name = (const char **)&pUnpack->m_Name;
    while ( 1 )
    {
      v5 = (CUtlString *)&p_m_Name[2][(_DWORD)pData];
      if ( p_m_Name[8] == nullptr )
        break;
      CDmxElement::UnpackIntoStructure(this: v19, pData: v5, pUnpack: (const DmxElementUnpackStructure_t *)p_m_Name[8]);
LABEL_43:
      p_m_Name += 11;
      if ( p_m_Name[1] == nullptr )
        return;
    }
    v6 = p_m_Name[1];
    if ( (unsigned int)(v6 - 15) <= 0xD && (v6 == (const char *)19 || p_m_Name[4] != (const char *)-1)
      || v6 == (const char *)6
      || v6 == (const char *)20 )
    {
      goto LABEL_43;
    }
    CDmxAttribute::CDmxAttribute(this: &temp, pAttributeName: nullptr);
    v7 = *(p_m_Name - 1);
    CDmxElement::Resort(this: v19);
    CDmxAttribute::CDmxAttribute(this: &v17, pAttributeName: v7);
    pUnpack = &v17;
    v8 = CUtlSortVector<CDmxAttribute *,CDmxAttributeLess>::Find(this: &v19->m_Attributes, src: &pUnpack);
    CDmxAttribute::~CDmxAttribute(this: &v17);
    if ( v8 < 0 || (p_temp = v19->m_Attributes.m_Memory.m_pMemory[v8]) == nullptr )
    {
      if ( *p_m_Name == nullptr )
      {
LABEL_42:
        CDmxAttribute::~CDmxAttribute(this: &temp);
        goto LABEL_43;
      }
      CDmxAttribute::AllocateDataMemory_AndConstruct(this: &temp, type: (DmAttributeType_t)p_m_Name[1]);
      if ( (unsigned int)(p_m_Name[1] - 15) > 0xD )
        CDmxAttribute::SetValueFromString(this: &temp, pValue: *p_m_Name);
      p_temp = &temp;
    }
    if ( p_m_Name[1] == (const char *)p_temp->m_Type )
    {
      if ( p_temp->m_Type == AT_STRING )
      {
        m_pData = (CUtlString *)p_temp->m_pData;
        if ( p_m_Name[3] == (const char *)-1 )
        {
          v11 = CUtlString::operator char const *(this: m_pData);
          CUtlString::operator=(this: v5, src: v11);
        }
        else
        {
          v12 = CUtlString::operator char const *(this: m_pData);
          V_strncpy(pDest: (char *)v5, pSrc: v12, maxLen: (int)p_m_Name[3]);
        }
      }
      else if ( CDmxAttribute::ArrayAttributeBasicType(type: p_temp->m_Type) == AT_FLOAT
             && p_m_Name[3] == (const char *)16 )
      {
        if ( (unsigned int)(p_m_Name[1] - 15) > 0xD )
        {
          v5->m_Storage.m_Memory.m_pMemory = *(unsigned __int8 **)p_temp->m_pData;
          v5->m_Storage.m_Memory.m_nAllocationCount = *(_DWORD *)p_temp->m_pData;
          v5->m_Storage.m_Memory.m_nGrowSize = *(_DWORD *)p_temp->m_pData;
          v5->m_Storage.m_nActualLength = *(_DWORD *)p_temp->m_pData;
        }
        else
        {
          v13 = CDmxAttribute::GetArray<float>(this: p_temp);
          v14 = 0;
          if ( (int)p_m_Name[9] > 0 )
          {
            p_m_nGrowSize = &v5->m_Storage.m_Memory.m_nGrowSize;
            do
            {
              *(p_m_nGrowSize - 2) = LODWORD(v13->m_Memory.m_pMemory[v14]);
              *(p_m_nGrowSize - 1) = LODWORD(v13->m_Memory.m_pMemory[v14]);
              *p_m_nGrowSize = LODWORD(v13->m_Memory.m_pMemory[v14]);
              p_m_nGrowSize[1] = LODWORD(v13->m_Memory.m_pMemory[v14++]);
              p_m_nGrowSize += 4;
            }
            while ( v14 < (int)p_m_Name[9] );
          }
        }
      }
      else
      {
        v16 = (DmAttributeType_t)p_m_Name[1];
        if ( (unsigned int)(v16 - 15) > 0xD )
        {
          if ( p_m_Name[4] == (const char *)-1 )
          {
            memcpy(
              dst: (unsigned __int8 *)v5,
              src: (unsigned __int8 *)p_temp->m_pData,
              count: (unsigned int)p_m_Name[3]);
          }
          else if ( p_temp->m_Type == AT_INT )
          {
            switch ( (unsigned int)p_m_Name[5] )
            {
              case 1u:
              case 3u:
                CDmxElement::UnpackBitfield<unsigned char>(
                  this: v19,
                  pDest: (unsigned __int8 *)v5,
                  pUnpack: (const DmxElementUnpackStructure_t *)(p_m_Name - 1),
                  pAttribute: p_temp);
                break;
              case 2u:
                goto $LN12_50;
              case 4u:
                CDmxElement::UnpackBitfield<short>(
                  this: v19,
                  pDest: (__int16 *)v5,
                  pUnpack: (const DmxElementUnpackStructure_t *)(p_m_Name - 1),
                  pAttribute: p_temp);
                break;
              case 5u:
                CDmxElement::UnpackBitfield<unsigned short>(
                  this: v19,
                  pDest: (unsigned __int16 *)v5,
                  pUnpack: (const DmxElementUnpackStructure_t *)(p_m_Name - 1),
                  pAttribute: p_temp);
                break;
              case 6u:
                CDmxElement::UnpackBitfield<int>(
                  this: v19,
                  pDest: (int *)v5,
                  pUnpack: (const DmxElementUnpackStructure_t *)(p_m_Name - 1),
                  pAttribute: p_temp);
                break;
              case 7u:
                CDmxElement::UnpackBitfield<unsigned int>(
                  this: v19,
                  pDest: (unsigned int *)v5,
                  pUnpack: (const DmxElementUnpackStructure_t *)(p_m_Name - 1),
                  pAttribute: p_temp);
                break;
              default:
                goto LABEL_42;
            }
          }
          else
          {
$LN12_50:
            CDmxElement::UnpackBitfield<char>(
              this: v19,
              pDest: (char *)v5,
              pUnpack: (const DmxElementUnpackStructure_t *)(p_m_Name - 1),
              pAttribute: p_temp);
          }
        }
        else
        {
          CDmxAttribute::GetArrayValue(
            this: p_temp,
            type: v16,
            pDest: v5,
            nDataTypeSize: (int)p_m_Name[3],
            nDestArrayLength: (int)p_m_Name[9],
            pDefaultString: *p_m_Name);
        }
      }
    }
    else
    {
      _Warning(
        a1: "CDmxElement::UnpackIntoStructure: Mismatched attribute type in attribute \"%s\"!\n",
        *(p_m_Name - 1));
    }
    goto LABEL_42;
  }
}

//------------------------------------------------------------------------------
// Address: 0x006A1BC0
// Name: private: void CDmxElement::RemoveAllElementsRecursive(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxElement::RemoveAllElementsRecursive(CDmxElement *this)
{
  int v1; // edi
  int v2; // ecx
  CDmxElement **m_pMemory; // eax
  CDmxElement *v4; // esi
  int m_Size; // ebx
  CDmxAttribute *v6; // ecx
  bool v8; // sf
  CDmxAttribute **v9; // eax
  CUtlVector<CDmxElement *,CUtlMemory<CDmxElement *,int> > elementsToDelete; // [esp+4h] [ebp-1Ch] BYREF
  int nCount; // [esp+18h] [ebp-8h]
  int i; // [esp+1Ch] [ebp-4h]

  v1 = 0;
  memset(&elementsToDelete, 0, sizeof(elementsToDelete));
  CDmxElement::AddElementsToDelete(this, (CUtlMemory<vgui::TreeNode *,int> *)&elementsToDelete);
  v2 = 0;
  nCount = elementsToDelete.m_Size;
  m_pMemory = elementsToDelete.m_Memory.m_pMemory;
  for ( i = 0; v2 < nCount; i = v2 )
  {
    v4 = m_pMemory[v2];
    if ( v4 != nullptr )
    {
      ++v4->m_nLockCount;
      m_Size = v4->m_Attributes.m_Size;
      if ( m_Size > 0 )
      {
        do
        {
          v6 = v4->m_Attributes.m_Memory.m_pMemory[v1];
          if ( v6 != nullptr )
            CDmxAttribute::~CDmxAttribute(this: v6);
          ++v1;
        }
        while ( v1 < m_Size );
      }
      *((_BYTE *)v4 + 49) &= ~1u;
      v4->m_Attributes.m_Size = 0;
      if ( v4->m_nLockCount-- == 1 )
        CDmxElement::Resort(this: v4);
      v8 = v4->m_Attributes.m_Memory.m_nGrowSize < 0;
      v4->m_Attributes.m_Size = 0;
      if ( !v8 )
      {
        if ( v4->m_Attributes.m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v4->m_Attributes.m_Memory.m_pMemory);
          v4->m_Attributes.m_Memory.m_pMemory = nullptr;
        }
        v4->m_Attributes.m_Memory.m_nAllocationCount = 0;
      }
      v8 = v4->m_Attributes.m_Memory.m_nGrowSize < 0;
      v9 = v4->m_Attributes.m_Memory.m_pMemory;
      v4->m_Attributes.m_pElements = v4->m_Attributes.m_Memory.m_pMemory;
      if ( !v8 )
      {
        if ( v9 != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v9);
          v4->m_Attributes.m_Memory.m_pMemory = nullptr;
        }
        v4->m_Attributes.m_Memory.m_nAllocationCount = 0;
      }
      m_pMemory = elementsToDelete.m_Memory.m_pMemory;
      v1 = 0;
    }
    v2 = i + 1;
  }
  elementsToDelete.m_Size = 0;
  if ( elementsToDelete.m_Memory.m_nGrowSize >= 0 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      m_pMemory = nullptr;
      elementsToDelete.m_Memory.m_pMemory = nullptr;
    }
    elementsToDelete.m_Memory.m_nAllocationCount = 0;
  }
  elementsToDelete.m_pElements = m_pMemory;
  if ( elementsToDelete.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x006B3390
// Name: _dynamic_initializer_for__CDmxElement::s_TypeSymbols__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmxElement::s_TypeSymbols__()
{
  CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>(this: &CDmxElement::s_TypeSymbols);
  return atexit(func: dynamic_atexit_destructor_for__CDmxElement::s_TypeSymbols__);
}

//------------------------------------------------------------------------------
// Address: 0x006B60D0
// Name: _dynamic_atexit_destructor_for__CDmxElement::s_TypeSymbols__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmxElement::s_TypeSymbols__()
{
  CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::RemoveAll(this: &CDmxElement::s_TypeSymbols);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&CDmxElement::s_TypeSymbols.m_StringPools);
  CUtlTSHash<CUtlSymbolTableLargeBaseTreeEntry_t *,2048,CUtlSymbolTableLargeBaseTreeEntry_t *,CCThreadsafeTreeHashMethod<2048,CUtlSymbolTableLargeBaseTreeEntry_t *,0>,0>::RemoveAll(this: &CDmxElement::s_TypeSymbols.m_Lookup);
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmxElement::s_TypeSymbols.m_Lookup.m_EntryMemory);
}

//------------------------------------------------------------------------------
// Address: 0x006B33B0
// Name: _dynamic_initializer_for__s_DMXAllocator__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_DMXAllocator__()
{
  CMemoryStack::CMemoryStack(this: &s_DMXAllocator);
  return atexit(func: dynamic_atexit_destructor_for__s_DMXAllocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006B6100
// Name: _dynamic_atexit_destructor_for__s_DMXAllocator__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_DMXAllocator__()
{
  CMemoryStack::~CMemoryStack(this: &s_DMXAllocator);
}

} // namespace sceneviewer

// ============================================================
// Overlay from ServerBrowser (Missing functions)
// ============================================================
namespace ServerBrowser {

//------------------------------------------------------------------------------
// Address: 0x1009A540
// Name: public: void CUtlSymbolTableLargeBase<class CNonThreadsafeTree<0>,0>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlSymbolTableLargeBase<CNonThreadsafeTree<0>,0>::RemoveAll(
        CUtlSymbolTableLargeBase<CNonThreadsafeTree<0>,0> *this)
{
  int i; // edi

  CUtlRBTree<CUtlSymbolTableLargeBaseTreeEntry_t *,int,CTreeEntryLess<CNonThreadsafeTree<0>,0>,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int>,int>>::RemoveAll(this: &this->m_Lookup);
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
// Address: 0x1009A5A0
// Name: public: void CUtlTSHash<struct CUtlSymbolTableLargeBaseTreeEntry_t __near *,2048,struct CUtlSymbolTableLargeBaseTreeEntry_t __near *,class CCThreadsafeTreeHashMethod<2048,struct CUtlSymbolTableLargeBaseTreeEntry_t __near *,0>,0>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlTSHash<CUtlSymbolTableLargeBaseTreeEntry_t *,2048,CUtlSymbolTableLargeBaseTreeEntry_t *,CCThreadsafeTreeHashMethod<2048,CUtlSymbolTableLargeBaseTreeEntry_t *,0>,0>::RemoveAll(
        CUtlTSHash<CUtlSymbolTableLargeBaseTreeEntry_t *,2048,CUtlSymbolTableLargeBaseTreeEntry_t *,CCThreadsafeTreeHashMethod<2048,CUtlSymbolTableLargeBaseTreeEntry_t *,0>,0> *this)
{
  CThreadSpinRWLock *p_m_AddLock; // esi
  int i; // edi
  unsigned int j; // eax
  CThreadFastMutex *p_m_mutex; // esi
  DWORD CurrentThreadId; // ecx

  this->m_bNeedsCommit = false;
  if ( this->m_EntryMemory.m_BlocksAllocated != 0 )
  {
    p_m_AddLock = &this->m_aBuckets[0].m_AddLock;
    for ( i = 2048; i != 0; --i )
    {
      if ( (p_m_AddLock->m_lockInfo.m_i32 & 0x10000) != 0
        || _InterlockedCompareExchange((volatile signed __int32 *)p_m_AddLock, 0x10000, 0) != 0 )
      {
        CThreadSpinRWLock::SpinLockForWrite(this: p_m_AddLock);
      }
      else
      {
        p_m_AddLock->m_writerId = GetCurrentThreadId();
      }
      for ( j = p_m_AddLock[-1].m_writerId; j != 0; j = *(_DWORD *)(j + 4) )
        ;
      p_m_AddLock[-1].m_lockInfo.m_i32 = 0;
      p_m_AddLock[-1].m_writerId = 0;
      p_m_AddLock->m_writerId = 0;
      p_m_AddLock->m_lockInfo.m_i32 = 0;
      p_m_AddLock += 2;
    }
    p_m_mutex = &this->m_EntryMemory.m_mutex;
    CurrentThreadId = GetCurrentThreadId();
    if ( CurrentThreadId != this->m_EntryMemory.m_mutex.m_ownerID
      && _InterlockedCompareExchange((volatile signed __int32 *)p_m_mutex, CurrentThreadId, 0) != 0 )
    {
      _mm_pause();
      CThreadFastMutex::Lock(a1: p_m_mutex, a2: CurrentThreadId, a3: 0);
    }
    else
    {
      ++this->m_EntryMemory.m_mutex.m_depth;
    }
    CUtlMemoryPool::Clear(this: &this->m_EntryMemory);
    if ( this->m_EntryMemory.m_mutex.m_depth-- == 1 )
      _InterlockedExchange((volatile __int32 *)p_m_mutex, 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1009A660
// Name: public: void CUtlSymbolTableLargeBase<class CThreadsafeTree<0>,0>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::RemoveAll(
        CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0> *this)
{
  int v2; // edi

  CUtlTSHash<CUtlSymbolTableLargeBaseTreeEntry_t *,2048,CUtlSymbolTableLargeBaseTreeEntry_t *,CCThreadsafeTreeHashMethod<2048,CUtlSymbolTableLargeBaseTreeEntry_t *,0>,0>::RemoveAll(this: &this->m_Lookup);
  v2 = 0;
  if ( this->m_StringPools.m_Size <= 0 )
  {
    this->m_StringPools.m_Size = 0;
  }
  else
  {
    do
      free(pMem: this->m_StringPools.m_Memory.m_pMemory[v2++]);
    while ( v2 < this->m_StringPools.m_Size );
    this->m_StringPools.m_Size = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1009A6B0
// Name: public: CUtlSymbolTableLargeBase<class CThreadsafeTree<0>,0>::CUtlSymbolTableLargeBase<class CThreadsafeTree<0>,0>(void)
// Source: json
//------------------------------------------------------------------------------
CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0> *__thiscall CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>(
        CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0> *this)
{
  CUtlTSHash<CUtlSymbolTableLargeBaseTreeEntry_t *,2048,CUtlSymbolTableLargeBaseTreeEntry_t *,CCThreadsafeTreeHashMethod<2048,CUtlSymbolTableLargeBaseTreeEntry_t *,0>,0>::HashBucket_t *m_aBuckets; // eax
  int v3; // edx
  CThreadSpinRWLock *p_m_AddLock; // ecx
  int i; // ecx

  CUtlMemoryPool::CUtlMemoryPool(
    this: &this->m_Lookup.m_EntryMemory,
    blockSize: 12,
    numElements: 32,
    growMode: 2,
    pszAllocOwner: nullptr,
    nAlignment: 0);
  m_aBuckets = this->m_Lookup.m_aBuckets;
  this->m_Lookup.m_EntryMemory.m_mutex.m_ownerID = 0;
  this->m_Lookup.m_EntryMemory.m_mutex.m_depth = 0;
  v3 = 2047;
  p_m_AddLock = &this->m_Lookup.m_aBuckets[0].m_AddLock;
  do
  {
    p_m_AddLock->m_lockInfo.m_i32 = 0;
    p_m_AddLock->m_writerId = 0;
    p_m_AddLock += 2;
    --v3;
  }
  while ( v3 >= 0 );
  this->m_Lookup.m_bNeedsCommit = false;
  for ( i = 2048; i != 0; --i )
  {
    m_aBuckets->m_pFirst = nullptr;
    m_aBuckets->m_pFirstUncommitted = nullptr;
    ++m_aBuckets;
  }
  this->m_StringPools.m_Memory.m_pMemory = nullptr;
  this->m_StringPools.m_Memory.m_nAllocationCount = 0;
  this->m_StringPools.m_Size = 0;
  this->m_StringPools.m_pElements = nullptr;
  this->m_StringPools.m_Memory.m_nGrowSize = 8;
  return this;
}

} // namespace ServerBrowser

// ============================================================
// Overlay from vguimatsurface (Missing functions)
// ============================================================
namespace vguimatsurface {

//------------------------------------------------------------------------------
// Address: 0x100B9C20
// Name: public: void CUtlSymbolTableLargeBase<class CNonThreadsafeTree<0>,0>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlSymbolTableLargeBase<CNonThreadsafeTree<0>,0>::RemoveAll(
        CUtlSymbolTableLargeBase<CNonThreadsafeTree<0>,0> *this)
{
  int i; // edi

  CUtlRBTree<CUtlSymbolTableLargeBaseTreeEntry_t *,int,CTreeEntryLess<CNonThreadsafeTree<0>,0>,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int>,int>>::RemoveAll(this: &this->m_Lookup);
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
// Address: 0x100B9C80
// Name: public: void CUtlTSHash<struct CUtlSymbolTableLargeBaseTreeEntry_t __near *,2048,struct CUtlSymbolTableLargeBaseTreeEntry_t __near *,class CCThreadsafeTreeHashMethod<2048,struct CUtlSymbolTableLargeBaseTreeEntry_t __near *,0>,0>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlTSHash<CUtlSymbolTableLargeBaseTreeEntry_t *,2048,CUtlSymbolTableLargeBaseTreeEntry_t *,CCThreadsafeTreeHashMethod<2048,CUtlSymbolTableLargeBaseTreeEntry_t *,0>,0>::RemoveAll(
        CUtlTSHash<CUtlSymbolTableLargeBaseTreeEntry_t *,2048,CUtlSymbolTableLargeBaseTreeEntry_t *,CCThreadsafeTreeHashMethod<2048,CUtlSymbolTableLargeBaseTreeEntry_t *,0>,0> *this)
{
  CThreadSpinRWLock *p_m_AddLock; // esi
  int i; // edi
  unsigned int j; // eax
  CThreadFastMutex *p_m_mutex; // esi
  DWORD CurrentThreadId; // ecx

  this->m_bNeedsCommit = false;
  if ( this->m_EntryMemory.m_BlocksAllocated != 0 )
  {
    p_m_AddLock = &this->m_aBuckets[0].m_AddLock;
    for ( i = 2048; i != 0; --i )
    {
      if ( (p_m_AddLock->m_lockInfo.m_i32 & 0x10000) != 0
        || _InterlockedCompareExchange((volatile signed __int32 *)p_m_AddLock, 0x10000, 0) != 0 )
      {
        CThreadSpinRWLock::SpinLockForWrite(this: p_m_AddLock);
      }
      else
      {
        p_m_AddLock->m_writerId = GetCurrentThreadId();
      }
      for ( j = p_m_AddLock[-1].m_writerId; j != 0; j = *(_DWORD *)(j + 4) )
        ;
      p_m_AddLock[-1].m_lockInfo.m_i32 = 0;
      p_m_AddLock[-1].m_writerId = 0;
      p_m_AddLock->m_writerId = 0;
      p_m_AddLock->m_lockInfo.m_i32 = 0;
      p_m_AddLock += 2;
    }
    p_m_mutex = &this->m_EntryMemory.m_mutex;
    CurrentThreadId = GetCurrentThreadId();
    if ( CurrentThreadId != this->m_EntryMemory.m_mutex.m_ownerID
      && _InterlockedCompareExchange((volatile signed __int32 *)p_m_mutex, CurrentThreadId, 0) != 0 )
    {
      _mm_pause();
      CThreadFastMutex::Lock(a1: p_m_mutex, a2: CurrentThreadId, a3: 0);
    }
    else
    {
      ++this->m_EntryMemory.m_mutex.m_depth;
    }
    CUtlMemoryPool::Clear(this: &this->m_EntryMemory);
    if ( this->m_EntryMemory.m_mutex.m_depth-- == 1 )
      _InterlockedExchange((volatile __int32 *)p_m_mutex, 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B9D40
// Name: public: void CUtlSymbolTableLargeBase<class CThreadsafeTree<0>,0>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::RemoveAll(
        CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0> *this)
{
  int v2; // edi

  CUtlTSHash<CUtlSymbolTableLargeBaseTreeEntry_t *,2048,CUtlSymbolTableLargeBaseTreeEntry_t *,CCThreadsafeTreeHashMethod<2048,CUtlSymbolTableLargeBaseTreeEntry_t *,0>,0>::RemoveAll(this: &this->m_Lookup);
  v2 = 0;
  if ( this->m_StringPools.m_Size <= 0 )
  {
    this->m_StringPools.m_Size = 0;
  }
  else
  {
    do
      free(pMem: this->m_StringPools.m_Memory.m_pMemory[v2++]);
    while ( v2 < this->m_StringPools.m_Size );
    this->m_StringPools.m_Size = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B9D90
// Name: public: CUtlSymbolTableLargeBase<class CThreadsafeTree<0>,0>::CUtlSymbolTableLargeBase<class CThreadsafeTree<0>,0>(void)
// Source: json
//------------------------------------------------------------------------------
CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0> *__thiscall CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>(
        CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0> *this)
{
  CUtlTSHash<CUtlSymbolTableLargeBaseTreeEntry_t *,2048,CUtlSymbolTableLargeBaseTreeEntry_t *,CCThreadsafeTreeHashMethod<2048,CUtlSymbolTableLargeBaseTreeEntry_t *,0>,0>::HashBucket_t *m_aBuckets; // eax
  int v3; // edx
  CThreadSpinRWLock *p_m_AddLock; // ecx
  int i; // ecx

  CUtlMemoryPool::CUtlMemoryPool(
    this: &this->m_Lookup.m_EntryMemory,
    blockSize: 12,
    numElements: 32,
    growMode: 2,
    pszAllocOwner: nullptr,
    nAlignment: 0);
  m_aBuckets = this->m_Lookup.m_aBuckets;
  this->m_Lookup.m_EntryMemory.m_mutex.m_ownerID = 0;
  this->m_Lookup.m_EntryMemory.m_mutex.m_depth = 0;
  v3 = 2047;
  p_m_AddLock = &this->m_Lookup.m_aBuckets[0].m_AddLock;
  do
  {
    p_m_AddLock->m_lockInfo.m_i32 = 0;
    p_m_AddLock->m_writerId = 0;
    p_m_AddLock += 2;
    --v3;
  }
  while ( v3 >= 0 );
  this->m_Lookup.m_bNeedsCommit = false;
  for ( i = 2048; i != 0; --i )
  {
    m_aBuckets->m_pFirst = nullptr;
    m_aBuckets->m_pFirstUncommitted = nullptr;
    ++m_aBuckets;
  }
  this->m_StringPools.m_Memory.m_pMemory = nullptr;
  this->m_StringPools.m_Memory.m_nAllocationCount = 0;
  this->m_StringPools.m_Size = 0;
  this->m_StringPools.m_pElements = nullptr;
  this->m_StringPools.m_Memory.m_nGrowSize = 8;
  return this;
}

} // namespace vguimatsurface

// ============================================================
// Overlay from vgui_editor (Missing functions)
// ============================================================
namespace vgui_editor {

//------------------------------------------------------------------------------
// Address: 0x004917D0
// Name: public: void CUtlSymbolTableLargeBase<class CNonThreadsafeTree<0>,0>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlSymbolTableLargeBase<CNonThreadsafeTree<0>,0>::RemoveAll(
        CUtlSymbolTableLargeBase<CNonThreadsafeTree<0>,0> *this)
{
  int i; // edi

  CUtlRBTree<CUtlSymbolTableLargeBaseTreeEntry_t *,int,CTreeEntryLess<CNonThreadsafeTree<0>,0>,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int>,int>>::RemoveAll(this: &this->m_Lookup);
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
// Address: 0x00491830
// Name: public: void CUtlTSHash<struct CUtlSymbolTableLargeBaseTreeEntry_t __near *,2048,struct CUtlSymbolTableLargeBaseTreeEntry_t __near *,class CCThreadsafeTreeHashMethod<2048,struct CUtlSymbolTableLargeBaseTreeEntry_t __near *,0>,0>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlTSHash<CUtlSymbolTableLargeBaseTreeEntry_t *,2048,CUtlSymbolTableLargeBaseTreeEntry_t *,CCThreadsafeTreeHashMethod<2048,CUtlSymbolTableLargeBaseTreeEntry_t *,0>,0>::RemoveAll(
        CUtlTSHash<CUtlSymbolTableLargeBaseTreeEntry_t *,2048,CUtlSymbolTableLargeBaseTreeEntry_t *,CCThreadsafeTreeHashMethod<2048,CUtlSymbolTableLargeBaseTreeEntry_t *,0>,0> *this)
{
  CThreadSpinRWLock *p_m_AddLock; // esi
  int i; // edi
  unsigned int j; // eax
  CThreadFastMutex *p_m_mutex; // esi
  DWORD CurrentThreadId; // ecx

  this->m_bNeedsCommit = false;
  if ( this->m_EntryMemory.m_BlocksAllocated != 0 )
  {
    p_m_AddLock = &this->m_aBuckets[0].m_AddLock;
    for ( i = 2048; i != 0; --i )
    {
      if ( (p_m_AddLock->m_lockInfo.m_i32 & 0x10000) != 0
        || _InterlockedCompareExchange((volatile signed __int32 *)p_m_AddLock, 0x10000, 0) != 0 )
      {
        CThreadSpinRWLock::SpinLockForWrite(this: p_m_AddLock);
      }
      else
      {
        p_m_AddLock->m_writerId = GetCurrentThreadId();
      }
      for ( j = p_m_AddLock[-1].m_writerId; j != 0; j = *(_DWORD *)(j + 4) )
        ;
      p_m_AddLock[-1].m_lockInfo.m_i32 = 0;
      p_m_AddLock[-1].m_writerId = 0;
      p_m_AddLock->m_writerId = 0;
      p_m_AddLock->m_lockInfo.m_i32 = 0;
      p_m_AddLock += 2;
    }
    p_m_mutex = &this->m_EntryMemory.m_mutex;
    CurrentThreadId = GetCurrentThreadId();
    if ( CurrentThreadId != this->m_EntryMemory.m_mutex.m_ownerID
      && _InterlockedCompareExchange((volatile signed __int32 *)p_m_mutex, CurrentThreadId, 0) != 0 )
    {
      _mm_pause();
      CThreadFastMutex::Lock(a1: p_m_mutex, a2: CurrentThreadId, a3: 0);
    }
    else
    {
      ++this->m_EntryMemory.m_mutex.m_depth;
    }
    CUtlMemoryPool::Clear(this: &this->m_EntryMemory);
    if ( this->m_EntryMemory.m_mutex.m_depth-- == 1 )
      _InterlockedExchange((volatile __int32 *)p_m_mutex, 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004918F0
// Name: public: void CUtlSymbolTableLargeBase<class CThreadsafeTree<0>,0>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::RemoveAll(
        CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0> *this)
{
  int v2; // edi

  CUtlTSHash<CUtlSymbolTableLargeBaseTreeEntry_t *,2048,CUtlSymbolTableLargeBaseTreeEntry_t *,CCThreadsafeTreeHashMethod<2048,CUtlSymbolTableLargeBaseTreeEntry_t *,0>,0>::RemoveAll(this: &this->m_Lookup);
  v2 = 0;
  if ( this->m_StringPools.m_Size <= 0 )
  {
    this->m_StringPools.m_Size = 0;
  }
  else
  {
    do
      free(pMem: this->m_StringPools.m_Memory.m_pMemory[v2++]);
    while ( v2 < this->m_StringPools.m_Size );
    this->m_StringPools.m_Size = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00491940
// Name: public: CUtlSymbolTableLargeBase<class CThreadsafeTree<0>,0>::CUtlSymbolTableLargeBase<class CThreadsafeTree<0>,0>(void)
// Source: json
//------------------------------------------------------------------------------
CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0> *__thiscall CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>(
        CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0> *this)
{
  CUtlTSHash<CUtlSymbolTableLargeBaseTreeEntry_t *,2048,CUtlSymbolTableLargeBaseTreeEntry_t *,CCThreadsafeTreeHashMethod<2048,CUtlSymbolTableLargeBaseTreeEntry_t *,0>,0>::HashBucket_t *m_aBuckets; // eax
  int v3; // edx
  CThreadSpinRWLock *p_m_AddLock; // ecx
  int i; // ecx

  CUtlMemoryPool::CUtlMemoryPool(
    this: &this->m_Lookup.m_EntryMemory,
    blockSize: 12,
    numElements: 32,
    growMode: 2,
    pszAllocOwner: nullptr,
    nAlignment: 0);
  m_aBuckets = this->m_Lookup.m_aBuckets;
  this->m_Lookup.m_EntryMemory.m_mutex.m_ownerID = 0;
  this->m_Lookup.m_EntryMemory.m_mutex.m_depth = 0;
  v3 = 2047;
  p_m_AddLock = &this->m_Lookup.m_aBuckets[0].m_AddLock;
  do
  {
    p_m_AddLock->m_lockInfo.m_i32 = 0;
    p_m_AddLock->m_writerId = 0;
    p_m_AddLock += 2;
    --v3;
  }
  while ( v3 >= 0 );
  this->m_Lookup.m_bNeedsCommit = false;
  for ( i = 2048; i != 0; --i )
  {
    m_aBuckets->m_pFirst = nullptr;
    m_aBuckets->m_pFirstUncommitted = nullptr;
    ++m_aBuckets;
  }
  this->m_StringPools.m_Memory.m_pMemory = nullptr;
  this->m_StringPools.m_Memory.m_nAllocationCount = 0;
  this->m_StringPools.m_Size = 0;
  this->m_StringPools.m_pElements = nullptr;
  this->m_StringPools.m_Memory.m_nGrowSize = 8;
  return this;
}

} // namespace vgui_editor

// ============================================================
// Overlay from vgui_perftest (Missing functions)
// ============================================================
namespace vgui_perftest {

//------------------------------------------------------------------------------
// Address: 0x00426B00
// Name: public: class Color const __near & CDmxElement::GetValue<class Color>(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
const Color *__thiscall CDmxElement::GetValue<Color>(CDmxElement *this, const char *pAttributeName)
{
  const CDmxAttribute *Attribute; // eax

  Attribute = CDmxElement::GetAttribute(this, pAttributeName);
  if ( Attribute != nullptr )
  {
    if ( Attribute->m_Type == AT_COLOR )
    {
      return (const Color *)Attribute->m_pData;
    }
    else
    {
      if ( (`CDmxAttribute::GetValue<Color>'::`4'::`local static guard' & 1) == 0 )
      {
        `CDmxAttribute::GetValue<Color>'::`4'::`local static guard' |= 1u;
        `CDmxAttribute::GetValue<Color>'::`4'::defaultValue = 0;
      }
      `CDmxAttribute::GetValue<Color>'::`4'::defaultValue = -16777216;
      return (const Color *)&`CDmxAttribute::GetValue<Color>'::`4'::defaultValue;
    }
  }
  else
  {
    if ( (`CDmxElement::GetValue<Color>'::`4'::`local static guard' & 1) == 0 )
    {
      `CDmxElement::GetValue<Color>'::`4'::`local static guard' |= 1u;
      `CDmxElement::GetValue<Color>'::`4'::defaultValue = 0;
    }
    `CDmxElement::GetValue<Color>'::`4'::defaultValue._color[0] = 0;
    `CDmxElement::GetValue<Color>'::`4'::defaultValue._color[1] = 0;
    `CDmxElement::GetValue<Color>'::`4'::defaultValue._color[2] = 0;
    `CDmxElement::GetValue<Color>'::`4'::defaultValue._color[3] = -1;
    return &`CDmxElement::GetValue<Color>'::`4'::defaultValue;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00426B90
// Name: public: class Vector2D const __near & CDmxElement::GetValue<class Vector2D>(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
const Vector2D *__thiscall CDmxElement::GetValue<Vector2D>(CDmxElement *this, const char *pAttributeName)
{
  const CDmxAttribute *Attribute; // eax

  Attribute = CDmxElement::GetAttribute(this, pAttributeName);
  if ( Attribute != nullptr )
  {
    if ( Attribute->m_Type == AT_VECTOR2 )
    {
      return (const Vector2D *)Attribute->m_pData;
    }
    else
    {
      if ( (`CDmxAttribute::GetValue<Vector2D>'::`4'::`local static guard' & 1) == 0 )
        `CDmxAttribute::GetValue<Vector2D>'::`4'::`local static guard' |= 1u;
      `CDmxAttribute::GetValue<Vector2D>'::`4'::defaultValue = 0;
      dword_5C6280 = 0;
      return (const Vector2D *)&`CDmxAttribute::GetValue<Vector2D>'::`4'::defaultValue;
    }
  }
  else
  {
    if ( (`CDmxElement::GetValue<Vector2D>'::`4'::`local static guard' & 1) == 0 )
      `CDmxElement::GetValue<Vector2D>'::`4'::`local static guard' |= 1u;
    `CDmxElement::GetValue<Vector2D>'::`4'::defaultValue.x = 0.0;
    `CDmxElement::GetValue<Vector2D>'::`4'::defaultValue.y = 0.0;
    return &`CDmxElement::GetValue<Vector2D>'::`4'::defaultValue;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00427090
// Name: public: class CUtlString const __near & CDmxElement::GetValue<class CUtlString>(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
const CUtlString *__thiscall CDmxElement::GetValue<CUtlString>(CDmxElement *this, const char *pAttributeName)
{
  CDmxAttribute *Attribute; // eax

  Attribute = (CDmxAttribute *)CDmxElement::GetAttribute(this, pAttributeName);
  if ( Attribute != nullptr )
    return CDmxAttribute::GetValue<CUtlString>(this: Attribute);
  if ( (`CDmxElement::GetValue<CUtlString>'::`4'::`local static guard' & 1) == 0 )
  {
    `CDmxElement::GetValue<CUtlString>'::`4'::`local static guard' |= 1u;
    CUtlString::CUtlString(this: &`CDmxElement::GetValue<CUtlString>'::`4'::defaultValue);
    atexit(func: `CDmxElement::GetValue<CUtlString>'::`4'::`dynamic atexit destructor for 'defaultValue'');
  }
  CUtlString::Set(this: &`CDmxElement::GetValue<CUtlString>'::`4'::defaultValue, pValue: nullptr);
  return &`CDmxElement::GetValue<CUtlString>'::`4'::defaultValue;
}

//------------------------------------------------------------------------------
// Address: 0x004F7630
// Name: public: struct UniqueId_t const __near & CDmxElement::GetId(void)const
// Source: json
//------------------------------------------------------------------------------
const UniqueId_t *__thiscall CDmxElement::GetId(CDmxElement *this)
{
  return &this->m_Id;
}

//------------------------------------------------------------------------------
// Address: 0x0052BA80
// Name: public: char const __near * CDmxElement::GetTypeString(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CDmxElement::GetTypeString(CDmxElement *this)
{
  const char *result; // eax

  result = this->m_Type.u.m_pAsString;
  if ( result == (const char *)-1 )
    return defaultValue;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0052BA90
// Name: private: void CDmxElement::SetId(struct UniqueId_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxElement::SetId(CDmxElement *this, const UniqueId_t *id)
{
  CopyUniqueId(src: id, pDest: &this->m_Id);
}

//------------------------------------------------------------------------------
// Address: 0x0052BAB0
// Name: private: void CDmxElement::UnpackBitfield<unsigned char>(unsigned char __near *,struct DmxElementUnpackStructure_t const __near *,class CDmxAttribute const __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxElement::UnpackBitfield<unsigned char>(
        CDmxElement *this,
        unsigned __int8 *pDest,
        const DmxElementUnpackStructure_t *pUnpack,
        const CDmxAttribute *pAttribute)
{
  int m_nSize; // ecx
  char v6; // bl
  char v7; // al
  unsigned __int8 v8; // al
  char mask; // [esp+14h] [ebp+8h]

  m_nSize = pUnpack->m_nSize;
  if ( m_nSize == 8 )
  {
    v6 = -1;
    v7 = -1;
  }
  else
  {
    v6 = (1 << m_nSize) - 1;
    v7 = v6 << pUnpack->m_nBitOffset;
  }
  mask = ~v7;
  v8 = *(_BYTE *)pAttribute->m_pData;
  if ( ((unsigned __int8)~v6 & v8) != 0 )
  {
    _Warning(a1: "Value %s exeeds size of datatype. \n", pUnpack->m_pAttributeName);
    v8 = 0;
  }
  *pDest &= mask;
  *pDest |= ((unsigned __int8)v6 & v8) << pUnpack->m_nBitOffset;
}

//------------------------------------------------------------------------------
// Address: 0x0052BB20
// Name: private: void CDmxElement::UnpackBitfield<char>(char __near *,struct DmxElementUnpackStructure_t const __near *,class CDmxAttribute const __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxElement::UnpackBitfield<char>(
        CDmxElement *this,
        char *pDest,
        const DmxElementUnpackStructure_t *pUnpack,
        const CDmxAttribute *pAttribute)
{
  int m_nSize; // edx
  char v6; // bl
  char v7; // al
  char v8; // al
  char v9; // dl
  char mask; // [esp+14h] [ebp+8h]

  m_nSize = pUnpack->m_nSize;
  if ( m_nSize == 8 )
  {
    v6 = -1;
    v7 = -1;
  }
  else
  {
    v6 = (1 << m_nSize) - 1;
    v7 = v6 << pUnpack->m_nBitOffset;
  }
  mask = ~v7;
  v8 = *(_BYTE *)pAttribute->m_pData;
  v9 = (1 << (m_nSize - 1)) - 1;
  if ( v8 < 0 )
  {
    if ( (~v9 & v8) != ~v9 )
    {
LABEL_8:
      _Warning(a1: "Value %s exeeds size of datatype. \n", pUnpack->m_pAttributeName);
      v8 = 0;
    }
  }
  else if ( (~v9 & v8) != 0 )
  {
    goto LABEL_8;
  }
  *pDest &= mask;
  *pDest |= ((unsigned __int8)v6 & (unsigned __int8)v8) << pUnpack->m_nBitOffset;
}

//------------------------------------------------------------------------------
// Address: 0x0052BBC0
// Name: private: void CDmxElement::UnpackBitfield<short>(short __near *,struct DmxElementUnpackStructure_t const __near *,class CDmxAttribute const __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxElement::UnpackBitfield<short>(
        CDmxElement *this,
        __int16 *pDest,
        const DmxElementUnpackStructure_t *pUnpack,
        const CDmxAttribute *pAttribute)
{
  int m_nSize; // edx
  unsigned __int16 v5; // bx
  int v6; // eax
  __int16 v7; // di
  __int16 v8; // ax
  int v9; // ecx
  bool v10; // zf

  m_nSize = pUnpack->m_nSize;
  if ( m_nSize == 16 )
  {
    v5 = -1;
    LOWORD(v6) = -1;
  }
  else
  {
    v5 = (1 << m_nSize) - 1;
    v6 = v5 << pUnpack->m_nBitOffset;
  }
  v7 = ~(_WORD)v6;
  v8 = *(_WORD *)pAttribute->m_pData;
  v9 = ~(__int16)((1 << (m_nSize - 1)) - 1);
  if ( v8 < 0 )
    v10 = (v9 & v8) == v9;
  else
    v10 = (v9 & v8) == 0;
  if ( !v10 )
  {
    _Warning(a1: "Value %s exeeds size of datatype. \n", pUnpack->m_pAttributeName);
    v8 = 0;
  }
  *pDest &= v7;
  *pDest |= (v5 & (unsigned __int16)v8) << pUnpack->m_nBitOffset;
}

//------------------------------------------------------------------------------
// Address: 0x0052BC60
// Name: private: void CDmxElement::UnpackBitfield<unsigned short>(unsigned short __near *,struct DmxElementUnpackStructure_t const __near *,class CDmxAttribute const __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxElement::UnpackBitfield<unsigned short>(
        CDmxElement *this,
        unsigned __int16 *pDest,
        const DmxElementUnpackStructure_t *pUnpack,
        const CDmxAttribute *pAttribute)
{
  int m_nSize; // ecx
  unsigned __int16 v5; // si
  __int16 v6; // ax
  __int16 v7; // di
  unsigned __int16 v8; // ax

  m_nSize = pUnpack->m_nSize;
  if ( m_nSize == 16 )
  {
    v5 = -1;
    v6 = -1;
  }
  else
  {
    v5 = (1 << m_nSize) - 1;
    v6 = v5 << pUnpack->m_nBitOffset;
  }
  v7 = ~v6;
  v8 = *(_WORD *)pAttribute->m_pData;
  if ( ((unsigned __int16)~v5 & v8) != 0 )
  {
    _Warning(a1: "Value %s exeeds size of datatype. \n", pUnpack->m_pAttributeName);
    v8 = 0;
  }
  *pDest &= v7;
  *pDest |= (v5 & v8) << pUnpack->m_nBitOffset;
}

//------------------------------------------------------------------------------
// Address: 0x0052BCE0
// Name: private: void CDmxElement::UnpackBitfield<int>(int __near *,struct DmxElementUnpackStructure_t const __near *,class CDmxAttribute const __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxElement::UnpackBitfield<int>(
        CDmxElement *this,
        int *pDest,
        const DmxElementUnpackStructure_t *pUnpack,
        const CDmxAttribute *pAttribute)
{
  int m_nSize; // edx
  int v5; // esi
  int v6; // eax
  int v7; // ebx
  int v8; // eax
  int v9; // edx
  bool v10; // zf

  m_nSize = pUnpack->m_nSize;
  if ( m_nSize == 32 )
  {
    v5 = -1;
    v6 = -1;
  }
  else
  {
    v5 = (1 << m_nSize) - 1;
    v6 = v5 << pUnpack->m_nBitOffset;
  }
  v7 = ~v6;
  v8 = *(_DWORD *)pAttribute->m_pData;
  v9 = ~((1 << (m_nSize - 1)) - 1);
  if ( v8 < 0 )
    v10 = (v8 & v9) == v9;
  else
    v10 = (v9 & v8) == 0;
  if ( !v10 )
  {
    _Warning(a1: "Value %s exeeds size of datatype. \n", pUnpack->m_pAttributeName);
    v8 = 0;
  }
  *pDest &= v7;
  *pDest |= (v5 & v8) << pUnpack->m_nBitOffset;
}

//------------------------------------------------------------------------------
// Address: 0x0052BD70
// Name: private: void CDmxElement::UnpackBitfield<unsigned int>(unsigned int __near *,struct DmxElementUnpackStructure_t const __near *,class CDmxAttribute const __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxElement::UnpackBitfield<unsigned int>(
        CDmxElement *this,
        unsigned int *pDest,
        const DmxElementUnpackStructure_t *pUnpack,
        const CDmxAttribute *pAttribute)
{
  int m_nSize; // ecx
  int v5; // esi
  int v6; // eax
  int v7; // edi
  int v8; // eax

  m_nSize = pUnpack->m_nSize;
  if ( m_nSize == 32 )
  {
    v5 = -1;
    v6 = -1;
  }
  else
  {
    v5 = (1 << m_nSize) - 1;
    v6 = v5 << pUnpack->m_nBitOffset;
  }
  v7 = ~v6;
  v8 = *(_DWORD *)pAttribute->m_pData;
  if ( (~v5 & v8) != 0 )
  {
    _Warning(a1: "Value %s exeeds size of datatype. \n", pUnpack->m_pAttributeName);
    v8 = 0;
  }
  *pDest &= v7;
  *pDest |= (v5 & v8) << pUnpack->m_nBitOffset;
}

//------------------------------------------------------------------------------
// Address: 0x0052BDE0
// Name: protected: static int CUtlSortVector<class CDmxAttribute __near *,class CDmxAttributeLess>::CompareHelper(void __near *,class CDmxAttribute __near * const __near *,class CDmxAttribute __near * const __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl CUtlSortVector<CDmxAttribute *,CDmxAttributeLess>::CompareHelper(
        void *context,
        CDmxAttribute *const *lhs,
        CDmxAttribute *const *rhs)
{
  int v3; // ecx
  int v4; // esi
  int result; // eax
  int lhsa; // [esp+10h] [ebp+8h]
  int rhsa; // [esp+14h] [ebp+Ch]
  int rhsb; // [esp+14h] [ebp+Ch]

  v3 = (int)*rhs;
  v4 = (int)*lhs;
  result = -1;
  if ( *lhs != nullptr )
    rhsa = *(_DWORD *)(v4 + 4);
  else
    rhsa = -1;
  if ( v3 != 0 )
    lhsa = *(_DWORD *)(v3 + 4);
  else
    lhsa = -1;
  if ( rhsa >= lhsa )
  {
    if ( v3 != 0 )
      rhsb = *(_DWORD *)(v3 + 4);
    else
      rhsb = -1;
    if ( v4 != 0 )
      return rhsb < *(_DWORD *)(v4 + 4);
    else
      return rhsb < -1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0052BE70
// Name: public: int CUtlSortVector<class CDmxAttribute __near *,class CDmxAttributeLess>::Find(class CDmxAttribute __near * const __near &)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlSortVector<CDmxAttribute *,CDmxAttributeLess>::Find(
        CUtlSortVector<CDmxAttribute *,CDmxAttributeLess> *this,
        CDmxAttribute *const *src)
{
  int v3; // ebx
  int v4; // ecx
  int v5; // ebp
  int result; // eax
  CDmxAttribute *v7; // edx
  int *p_src; // edi
  int *v9; // esi
  int *v10; // esi
  int *v11; // ecx
  CDmxAttribute **m_pMemory; // [esp+10h] [ebp-20h]
  int v13; // [esp+14h] [ebp-1Ch] BYREF
  int v14; // [esp+18h] [ebp-18h] BYREF
  int v15; // [esp+1Ch] [ebp-14h] BYREF
  int v16; // [esp+20h] [ebp-10h] BYREF
  int v17; // [esp+24h] [ebp-Ch] BYREF
  CUtlSymbolLarge::<unnamed_tag> v18; // [esp+28h] [ebp-8h] BYREF
  int v19; // [esp+2Ch] [ebp-4h] BYREF

  if ( this->m_bNeedsSort
    && _LoggingSystem_LogAssert(
         a1: "%s (%d) : %s\n",
         "..\\public\\tier1/UtlSortVector.h",
         213,
         "Assertion Failed: !m_bNeedsSort") == 1 )
  {
    if ( (unsigned __int8)_ShouldUseNewAssertDialog() == 0
      || (unsigned __int8)_DoNewAssertDialog(
                            a1: "..\\public\\tier1/UtlSortVector.h",
                            a2: 213,
                            a3: "Assertion Failed: !m_bNeedsSort") != 0 )
    {
      __debugbreak();
    }
    __ExitOnFatalAssert(a1: "..\\public\\tier1/UtlSortVector.h", a2: 213);
  }
  v3 = 0;
  v4 = this->m_Size - 1;
  if ( v4 >= 0 )
  {
    v5 = (int)*src;
    m_pMemory = this->m_Memory.m_pMemory;
    do
    {
      result = (v4 + v3) >> 1;
      v7 = m_pMemory[result];
      if ( v7 != nullptr )
      {
        src = (CDmxAttribute *const *)v7->m_Name.u.m_Id;
        p_src = (int *)&src;
      }
      else
      {
        v13 = -1;
        p_src = &v13;
      }
      if ( v5 != 0 )
      {
        v14 = *(_DWORD *)(v5 + 4);
        v9 = &v14;
      }
      else
      {
        v15 = -1;
        v9 = &v15;
      }
      if ( *p_src >= *v9 )
      {
        if ( v5 != 0 )
        {
          v16 = *(_DWORD *)(v5 + 4);
          v10 = &v16;
        }
        else
        {
          v17 = -1;
          v10 = &v17;
        }
        if ( v7 != nullptr )
        {
          v18.m_Id = (int)v7->m_Name.u;
          v11 = (int *)&v18;
        }
        else
        {
          v19 = -1;
          v11 = &v19;
        }
        if ( *v10 >= *v11 )
          return result;
        v4 = result - 1;
      }
      else
      {
        v3 = result + 1;
      }
    }
    while ( v3 <= v4 );
  }
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0052BFA0
// Name: public: int CUtlSortVector<class CDmxAttribute __near *,class CDmxAttributeLess>::InsertNoSort(class CDmxAttribute __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlSortVector<CDmxAttribute *,CDmxAttributeLess>::InsertNoSort(
        CUtlSortVector<CDmxAttribute *,CDmxAttributeLess> *this,
        CDmxAttribute **src)
{
  int m_nAllocationCount; // eax
  int m_Size; // edi
  CDmxAttribute **m_pMemory; // ecx
  int v6; // eax
  bool v7; // zf
  CDmxAttribute **v8; // eax

  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  m_Size = this->m_Size;
  this->m_bNeedsSort = true;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<IDmFormatUpdater *,int>::Grow((CUtlMemory<S3RGBA,int> *)this, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v6 = this->m_Size - m_Size - 1;
  v7 = this->m_Size - m_Size == 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v6 >= 0 && !v7 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v6);
  v8 = &this->m_Memory.m_pMemory[m_Size];
  if ( v8 != nullptr )
    *v8 = *src;
  return m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x0052C010
// Name: private: void CDmxElement::Resort(void)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxElement::Resort(CDmxElement *this)
{
  signed int m_Size; // eax
  int i; // edi
  CDmxAttribute **v4; // eax
  const char *Name; // eax
  char v6; // [esp+7h] [ebp-9h] BYREF
  _DWORD context[2]; // [esp+8h] [ebp-8h] BYREF

  if ( (*((_BYTE *)this + 49) & 1) != 0 )
  {
    if ( this->m_Attributes.m_bNeedsSort )
    {
      m_Size = this->m_Attributes.m_Size;
      this->m_Attributes.m_bNeedsSort = false;
      if ( m_Size > 1 )
      {
        context[0] = this->m_Attributes.m_pLessContext;
        context[1] = &v6;
        qsort_s(
          base: this->m_Attributes.m_Memory.m_pMemory,
          num: m_Size,
          width: 4u,
          comp: (int (__cdecl *)(void *, const void *, const void *))CUtlSortVector<CDmxAttribute *,CDmxAttributeLess>::CompareHelper,
          context);
      }
    }
    *((_BYTE *)this + 49) &= ~1u;
    for ( i = this->m_Attributes.m_Size - 1; i >= 1; --i )
    {
      v4 = &this->m_Attributes.m_Memory.m_pMemory[i];
      if ( *v4 != nullptr && *(v4 - 1) != nullptr && (*v4)->m_Name.u.m_Id == (*(v4 - 1))->m_Name.u.m_Id )
      {
        Name = CDmxAttribute::GetName(this: *v4);
        _Warning(a1: "Duplicate attribute name %s encountered!\n", Name);
        if ( this->m_Attributes.m_Size - i - 1 > 0 )
          _V_memmove(
            dest: &this->m_Attributes.m_Memory.m_pMemory[i],
            src: &this->m_Attributes.m_Memory.m_pMemory[i + 1],
            count: 4 * (this->m_Attributes.m_Size - i - 1));
        --this->m_Attributes.m_Size;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0052C0E0
// Name: public: void CDmxElement::LockForChanges(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxElement::LockForChanges(CDmxElement *this, bool bLock)
{
  if ( bLock )
  {
    ++this->m_nLockCount;
  }
  else if ( this->m_nLockCount-- == 1 )
  {
    CDmxElement::Resort(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0052C100
// Name: public: bool CDmxElement::HasAttribute(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CDmxElement::HasAttribute(CDmxElement *this, const char *pAttributeName)
{
  int v3; // esi
  CDmxAttribute v5; // [esp+4h] [ebp-Ch] BYREF

  CDmxElement::Resort(this);
  CDmxAttribute::CDmxAttribute(this: &v5, pAttributeName);
  pAttributeName = (const char *)&v5;
  v3 = CUtlSortVector<CDmxAttribute *,CDmxAttributeLess>::Find(
         this: &this->m_Attributes,
         src: (CDmxAttribute *const *)&pAttributeName);
  CDmxAttribute::~CDmxAttribute(this: &v5);
  return v3 >= 0;
}

//------------------------------------------------------------------------------
// Address: 0x0052C150
// Name: public: class CDmxAttribute const __near * CDmxElement::GetAttribute(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
const CDmxAttribute *__thiscall CDmxElement::GetAttribute(CDmxElement *this, const char *pAttributeName)
{
  int v3; // edi
  CDmxAttribute v5; // [esp+8h] [ebp-Ch] BYREF

  CDmxElement::Resort(this);
  CDmxAttribute::CDmxAttribute(this: &v5, pAttributeName);
  pAttributeName = (const char *)&v5;
  v3 = CUtlSortVector<CDmxAttribute *,CDmxAttributeLess>::Find(
         this: &this->m_Attributes,
         src: (CDmxAttribute *const *)&pAttributeName);
  CDmxAttribute::~CDmxAttribute(this: &v5);
  if ( v3 < 0 )
    return nullptr;
  else
    return this->m_Attributes.m_Memory.m_pMemory[v3];
}

//------------------------------------------------------------------------------
// Address: 0x0052C1B0
// Name: private: void CDmxElement::AddElementsToDelete(class CUtlVector<class CDmxElement __near *,class CUtlMemory<class CDmxElement __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxElement::AddElementsToDelete(
        CDmxElement *this,
        CUtlVector<CDmxElement *,CUtlMemory<CDmxElement *,int> > *elementsToDelete)
{
  char v3; // al
  CUtlVector<CDmxElement *,CUtlMemory<CDmxElement *,int> > *v4; // esi
  int v5; // eax
  CDmxAttribute *v6; // ecx
  CDmxElement *v7; // ecx
  const CUtlVector<CDmxElement *,CUtlMemory<CDmxElement *,int> > *v8; // edi
  int v9; // ebx
  int i; // esi
  int m_Size; // [esp-Ch] [ebp-18h]
  int nCount; // [esp+4h] [ebp-8h] BYREF
  int v13; // [esp+8h] [ebp-4h]

  v3 = *((_BYTE *)this + 49);
  if ( (v3 & 2) == 0 )
  {
    v4 = elementsToDelete;
    *((_BYTE *)this + 49) = v3 | 2;
    m_Size = elementsToDelete->m_Size;
    nCount = (int)this;
    CUtlVector<vgui::ClickPanel *,CUtlMemory<vgui::ClickPanel *,int>>::InsertBefore(
      this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)elementsToDelete,
      elem: m_Size,
      src: (vgui::TreeNode **)&nCount);
    v5 = 0;
    v13 = this->m_Attributes.m_Size;
    nCount = 0;
    if ( v13 > 0 )
    {
      while ( 1 )
      {
        v6 = this->m_Attributes.m_Memory.m_pMemory[v5];
        if ( v6->m_Type == AT_FIRST_VALUE_TYPE )
        {
          v7 = *(CDmxElement **)v6->m_pData;
          if ( v7 != nullptr )
            CDmxElement::AddElementsToDelete(this: v7, elementsToDelete: v4);
        }
        else if ( v6->m_Type == AT_FIRST_ARRAY_TYPE )
        {
          v8 = CDmxAttribute::GetArray<CDmxElement *>(this: v6);
          v9 = v8->m_Size;
          for ( i = 0; i < v9; ++i )
          {
            if ( v8->m_Memory.m_pMemory[i] != nullptr )
              CDmxElement::AddElementsToDelete(this: v8->m_Memory.m_pMemory[i], elementsToDelete);
          }
        }
        v5 = ++nCount;
        if ( nCount >= v13 )
          break;
        v4 = elementsToDelete;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0052C270
// Name: private: CDmxElement::CDmxElement(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDmxElement *__thiscall CDmxElement::CDmxElement(CDmxElement *this, const char *pType)
{
  const char *v4; // [esp-4h] [ebp-Ch]

  v4 = pType;
  this->m_Attributes.m_Memory.m_pMemory = nullptr;
  this->m_Attributes.m_Memory.m_nAllocationCount = 0;
  this->m_Attributes.m_Memory.m_nGrowSize = 0;
  this->m_Attributes.m_Size = 0;
  this->m_Attributes.m_pElements = nullptr;
  this->m_Attributes.m_pLessContext = nullptr;
  this->m_Attributes.m_bNeedsSort = false;
  this->m_Type.u.m_Id = -1;
  this->m_Type = (CUtlSymbolLarge)CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::AddString(
                                    this: &CDmxElement::s_TypeSymbols,
                                    result: (CUtlSymbolLarge *)&pType,
                                    pString: v4)->u.m_Id;
  *((_BYTE *)this + 49) &= 0xFCu;
  this->m_nLockCount = 0;
  CreateUniqueId(pDest: &this->m_Id);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0052C2D0
// Name: public: class CDmxAttribute __near * CDmxElement::AddAttribute(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDmxAttribute *__thiscall CDmxElement::AddAttribute(CDmxElement *this, CDmxAttribute *pAttributeName)
{
  const char *v3; // ebx
  int v4; // edi
  CDmxAttribute *v6; // eax
  const char *v7; // edi
  CDmxAttribute v9; // [esp+Ch] [ebp-Ch] BYREF

  CDmxElement::Resort(this);
  v3 = (const char *)pAttributeName;
  CDmxAttribute::CDmxAttribute(this: &v9, (const char *)pAttributeName);
  pAttributeName = &v9;
  v4 = CUtlSortVector<CDmxAttribute *,CDmxAttributeLess>::Find(this: &this->m_Attributes, src: &pAttributeName);
  CDmxAttribute::~CDmxAttribute(this: &v9);
  if ( v4 >= 0 )
    return this->m_Attributes.m_Memory.m_pMemory[v4];
  ++this->m_nLockCount;
  *((_BYTE *)this + 49) |= 1u;
  v6 = (CDmxAttribute *)DMXAlloc(size: 0xCu);
  if ( v6 != nullptr )
    v7 = (const char *)CDmxAttribute::CDmxAttribute(this: v6, pAttributeName: v3);
  else
    v7 = nullptr;
  pAttributeName = (CDmxAttribute *)v7;
  CUtlSortVector<CDmxAttribute *,CDmxAttributeLess>::InsertNoSort(this: &this->m_Attributes, src: &pAttributeName);
  if ( this->m_nLockCount-- == 1 )
    CDmxElement::Resort(this);
  return (CDmxAttribute *)v7;
}

//------------------------------------------------------------------------------
// Address: 0x0052C370
// Name: public: void CDmxElement::UnpackIntoStructure(void __near *,struct DmxElementUnpackStructure_t const __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxElement::UnpackIntoStructure(
        CDmxElement *this,
        char *pData,
        const DmxElementUnpackStructure_t *pUnpack)
{
  const DmxElementUnpackStructure_t *v3; // esi
  CUtlString *v5; // ebx
  DmAttributeType_t m_AttributeType; // eax
  CUtlSymbolLarge *Attribute; // edi
  const char *ValueString; // eax
  const char *v9; // eax
  const CUtlVector<float,CUtlMemory<float,int> > *v10; // eax
  int v11; // ecx
  int *p_m_nGrowSize; // edx
  DmAttributeType_t v13; // eax
  int m_nSize; // [esp-Ch] [ebp-20h]
  CDmxAttribute temp; // [esp+4h] [ebp-10h] BYREF

  v3 = pUnpack;
  if ( pUnpack->m_AttributeType != AT_UNKNOWN )
  {
    while ( 1 )
    {
      v5 = (CUtlString *)&pData[v3->m_nOffset];
      if ( v3->m_pSub == nullptr )
        break;
      CDmxElement::UnpackIntoStructure(this, pData: v5, pUnpack: v3->m_pSub);
LABEL_41:
      ++v3;
      if ( v3->m_AttributeType == AT_UNKNOWN )
        return;
    }
    m_AttributeType = v3->m_AttributeType;
    if ( (unsigned int)(m_AttributeType - 15) <= 0xD && (m_AttributeType == AT_STRING_ARRAY || v3->m_nBitOffset != -1)
      || m_AttributeType == AT_VOID
      || m_AttributeType == AT_VOID_ARRAY )
    {
      goto LABEL_41;
    }
    CDmxAttribute::CDmxAttribute(this: (CDmxAttribute *)&temp.m_Name, pAttributeName: nullptr);
    Attribute = (CUtlSymbolLarge *)CDmxElement::GetAttribute(this, pAttributeName: v3->m_pAttributeName);
    if ( Attribute == nullptr )
    {
      if ( v3->m_pDefaultString == nullptr )
      {
LABEL_40:
        CDmxAttribute::~CDmxAttribute(this: (CDmxAttribute *)&temp.m_Name);
        goto LABEL_41;
      }
      CDmxAttribute::AllocateDataMemory_AndConstruct(this: (CDmxAttribute *)&temp.m_Name, type: v3->m_AttributeType);
      if ( (unsigned int)(v3->m_AttributeType - 15) > 0xD )
        CDmxAttribute::SetValueFromString(this: (CDmxAttribute *)&temp.m_Name, pValue: v3->m_pDefaultString);
      Attribute = &temp.m_Name;
    }
    if ( v3->m_AttributeType == Attribute->u.m_Id )
    {
      if ( Attribute->u.m_Id == 5 )
      {
        if ( v3->m_nSize == -1 )
        {
          ValueString = CDmxAttribute::GetValueString(this: (CDmxAttribute *)Attribute);
          CUtlString::operator=(this: v5, src: ValueString);
        }
        else
        {
          m_nSize = v3->m_nSize;
          v9 = CDmxAttribute::GetValueString(this: (CDmxAttribute *)Attribute);
          V_strncpy(pDest: (char *)v5, pSrc: v9, maxLen: m_nSize);
        }
      }
      else if ( CDmxAttribute::ArrayAttributeBasicType(type: (DmAttributeType_t)Attribute->u.m_Id) == AT_FLOAT
             && v3->m_nSize == 16 )
      {
        if ( (unsigned int)(v3->m_AttributeType - 15) > 0xD )
        {
          v5->m_Storage.m_Memory.m_pMemory = *(unsigned __int8 **)Attribute[2].u.m_Id;
          v5->m_Storage.m_Memory.m_nAllocationCount = *(_DWORD *)Attribute[2].u.m_Id;
          v5->m_Storage.m_Memory.m_nGrowSize = *(_DWORD *)Attribute[2].u.m_Id;
          v5->m_Storage.m_nActualLength = *(_DWORD *)Attribute[2].u.m_Id;
        }
        else
        {
          v10 = CDmxAttribute::GetArray<float>(this: (CDmxAttribute *)Attribute);
          v11 = 0;
          if ( v3->m_nArrayLength > 0 )
          {
            p_m_nGrowSize = &v5->m_Storage.m_Memory.m_nGrowSize;
            do
            {
              *(p_m_nGrowSize - 2) = LODWORD(v10->m_Memory.m_pMemory[v11]);
              *(p_m_nGrowSize - 1) = LODWORD(v10->m_Memory.m_pMemory[v11]);
              *p_m_nGrowSize = LODWORD(v10->m_Memory.m_pMemory[v11]);
              p_m_nGrowSize[1] = LODWORD(v10->m_Memory.m_pMemory[v11++]);
              p_m_nGrowSize += 4;
            }
            while ( v11 < v3->m_nArrayLength );
          }
        }
      }
      else
      {
        v13 = v3->m_AttributeType;
        if ( (unsigned int)(v13 - 15) > 0xD )
        {
          if ( v3->m_nBitOffset == -1 )
          {
            memcpy(dst: (unsigned __int8 *)v5, src: (unsigned __int8 *)Attribute[2].u.m_Id, count: v3->m_nSize);
          }
          else if ( Attribute->u.m_Id == 2 )
          {
            switch ( v3->m_BitfieldType )
            {
              case BITFIELD_TYPE_BOOL:
              case BITFIELD_TYPE_UNSIGNED_CHAR:
                CDmxElement::UnpackBitfield<unsigned char>(
                  this,
                  pDest: (unsigned __int8 *)v5,
                  pUnpack: v3,
                  pAttribute: (const CDmxAttribute *)Attribute);
                break;
              case BITFIELD_TYPE_CHAR:
                goto $LN12_24;
              case BITFIELD_TYPE_SHORT:
                CDmxElement::UnpackBitfield<short>(
                  this,
                  pDest: (__int16 *)v5,
                  pUnpack: v3,
                  pAttribute: (const CDmxAttribute *)Attribute);
                break;
              case BITFIELD_TYPE_UNSIGNED_SHORT:
                CDmxElement::UnpackBitfield<unsigned short>(
                  this,
                  pDest: (unsigned __int16 *)v5,
                  pUnpack: v3,
                  pAttribute: (const CDmxAttribute *)Attribute);
                break;
              case BITFIELD_TYPE_INT:
                CDmxElement::UnpackBitfield<int>(
                  this,
                  pDest: (int *)v5,
                  pUnpack: v3,
                  pAttribute: (const CDmxAttribute *)Attribute);
                break;
              case BITFIELD_TYPE_UNSIGNED_INT:
                CDmxElement::UnpackBitfield<unsigned int>(
                  this,
                  pDest: (unsigned int *)v5,
                  pUnpack: v3,
                  pAttribute: (const CDmxAttribute *)Attribute);
                break;
              default:
                goto LABEL_40;
            }
          }
          else
          {
$LN12_24:
            CDmxElement::UnpackBitfield<char>(
              this,
              pDest: (char *)v5,
              pUnpack: v3,
              pAttribute: (const CDmxAttribute *)Attribute);
          }
        }
        else
        {
          CDmxAttribute::GetArrayValue(
            this: (CDmxAttribute *)Attribute,
            type: v13,
            pDest: v5,
            nDataTypeSize: v3->m_nSize,
            nDestArrayLength: v3->m_nArrayLength,
            pDefaultString: v3->m_pDefaultString);
        }
      }
    }
    else
    {
      _Warning(
        a1: "CDmxElement::UnpackIntoStructure: Mismatched attribute type in attribute \"%s\"!\n",
        v3->m_pAttributeName);
    }
    goto LABEL_40;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0052C5E0
// Name: private: void CDmxElement::RemoveAllElementsRecursive(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxElement::RemoveAllElementsRecursive(CDmxElement *this)
{
  int v1; // ecx
  _DWORD *m_nAllocationCount; // eax
  int v3; // esi
  int v4; // ebp
  int i; // edi
  CDmxAttribute *v6; // ecx
  int nCount; // [esp+4h] [ebp-1Ch]
  CUtlVector<CDmxElement *,CUtlMemory<CDmxElement *,int> > elementsToDelete; // [esp+8h] [ebp-18h] BYREF
  _DWORD *v10; // [esp+1Ch] [ebp-4h]

  memset(&elementsToDelete.m_Memory.m_nAllocationCount, 0, 16);
  v10 = nullptr;
  CDmxElement::AddElementsToDelete(
    this,
    elementsToDelete: (CUtlVector<CDmxElement *,CUtlMemory<CDmxElement *,int> > *)&elementsToDelete.m_Memory.m_nAllocationCount);
  v1 = 0;
  elementsToDelete.m_Memory.m_pMemory = elementsToDelete.m_pElements;
  m_nAllocationCount = (_DWORD *)elementsToDelete.m_Memory.m_nAllocationCount;
  for ( nCount = 0; v1 < (int)elementsToDelete.m_Memory.m_pMemory; nCount = ++v1 )
  {
    v3 = m_nAllocationCount[v1];
    if ( v3 != 0 )
    {
      ++*(_BYTE *)(v3 + 48);
      v4 = *(_DWORD *)(v3 + 12);
      for ( i = 0; i < v4; ++i )
      {
        v6 = *(CDmxAttribute **)(*(_DWORD *)v3 + 4 * i);
        if ( v6 != nullptr )
          CDmxAttribute::~CDmxAttribute(this: v6);
      }
      *(_BYTE *)(v3 + 49) &= ~1u;
      *(_DWORD *)(v3 + 12) = 0;
      if ( (*(_BYTE *)(v3 + 48))-- == 1 )
        CDmxElement::Resort(this: (CDmxElement *)v3);
      CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)v3);
      m_nAllocationCount = (_DWORD *)elementsToDelete.m_Memory.m_nAllocationCount;
      v1 = nCount;
    }
  }
  elementsToDelete.m_pElements = nullptr;
  if ( elementsToDelete.m_Size >= 0 )
  {
    if ( m_nAllocationCount != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_nAllocationCount);
      m_nAllocationCount = nullptr;
      elementsToDelete.m_Memory.m_nAllocationCount = 0;
    }
    elementsToDelete.m_Memory.m_nGrowSize = 0;
  }
  v10 = m_nAllocationCount;
  if ( elementsToDelete.m_Size >= 0 && m_nAllocationCount != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_nAllocationCount);
}

//------------------------------------------------------------------------------
// Address: 0x00534D00
// Name: _dynamic_initializer_for__CDmxElement::s_TypeSymbols__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmxElement::s_TypeSymbols__()
{
  CUtlTSHash<CUtlSymbolTableLargeBaseTreeEntry_t *,2048,CUtlSymbolTableLargeBaseTreeEntry_t *,CCThreadsafeTreeHashMethod<2048,CUtlSymbolTableLargeBaseTreeEntry_t *,0>,0>::CUtlTSHash<CUtlSymbolTableLargeBaseTreeEntry_t *,2048,CUtlSymbolTableLargeBaseTreeEntry_t *,CCThreadsafeTreeHashMethod<2048,CUtlSymbolTableLargeBaseTreeEntry_t *,0>,0>(
    this: &CDmxElement::s_TypeSymbols.m_Lookup,
    nAllocationCount: 32);
  CDmxElement::s_TypeSymbols.m_StringPools.m_Memory.m_pMemory = nullptr;
  CDmxElement::s_TypeSymbols.m_StringPools.m_Memory.m_nAllocationCount = 0;
  CDmxElement::s_TypeSymbols.m_StringPools.m_Memory.m_nGrowSize = 8;
  CDmxElement::s_TypeSymbols.m_StringPools.m_Size = 0;
  CDmxElement::s_TypeSymbols.m_StringPools.m_pElements = nullptr;
  return atexit(func: dynamic_atexit_destructor_for__CDmxElement::s_TypeSymbols__);
}

//------------------------------------------------------------------------------
// Address: 0x00535870
// Name: _dynamic_atexit_destructor_for__CDmxElement::s_TypeSymbols__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmxElement::s_TypeSymbols__()
{
  CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::RemoveAll(this: &CDmxElement::s_TypeSymbols);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&CDmxElement::s_TypeSymbols.m_StringPools);
  CUtlTSHash<CUtlSymbolTableLargeBaseTreeEntry_t *,2048,CUtlSymbolTableLargeBaseTreeEntry_t *,CCThreadsafeTreeHashMethod<2048,CUtlSymbolTableLargeBaseTreeEntry_t *,0>,0>::RemoveAll(this: &CDmxElement::s_TypeSymbols.m_Lookup);
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmxElement::s_TypeSymbols.m_Lookup.m_EntryMemory);
}

//------------------------------------------------------------------------------
// Address: 0x00534D40
// Name: _dynamic_initializer_for__s_DMXAllocator__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_DMXAllocator__()
{
  CMemoryStack::CMemoryStack(this: &s_DMXAllocator);
  return atexit(func: dynamic_atexit_destructor_for__s_DMXAllocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005358A0
// Name: _dynamic_atexit_destructor_for__s_DMXAllocator__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_DMXAllocator__()
{
  CMemoryStack::~CMemoryStack(this: &s_DMXAllocator);
}

} // namespace vgui_perftest

// ============================================================
// Overlay from vp4 (Missing functions)
// ============================================================
namespace vp4 {

//------------------------------------------------------------------------------
// Address: 0x00482B60
// Name: public: void CUtlSymbolTableLargeBase<class CNonThreadsafeTree<0>,0>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlSymbolTableLargeBase<CNonThreadsafeTree<0>,0>::RemoveAll(
        CUtlSymbolTableLargeBase<CNonThreadsafeTree<0>,0> *this)
{
  int i; // edi

  CUtlRBTree<CUtlSymbolTableLargeBaseTreeEntry_t *,int,CTreeEntryLess<CNonThreadsafeTree<0>,0>,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int>,int>>::RemoveAll(this: &this->m_Lookup);
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
// Address: 0x00482BC0
// Name: public: void CUtlTSHash<struct CUtlSymbolTableLargeBaseTreeEntry_t __near *,2048,struct CUtlSymbolTableLargeBaseTreeEntry_t __near *,class CCThreadsafeTreeHashMethod<2048,struct CUtlSymbolTableLargeBaseTreeEntry_t __near *,0>,0>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlTSHash<CUtlSymbolTableLargeBaseTreeEntry_t *,2048,CUtlSymbolTableLargeBaseTreeEntry_t *,CCThreadsafeTreeHashMethod<2048,CUtlSymbolTableLargeBaseTreeEntry_t *,0>,0>::RemoveAll(
        CUtlTSHash<CUtlSymbolTableLargeBaseTreeEntry_t *,2048,CUtlSymbolTableLargeBaseTreeEntry_t *,CCThreadsafeTreeHashMethod<2048,CUtlSymbolTableLargeBaseTreeEntry_t *,0>,0> *this)
{
  CThreadSpinRWLock *p_m_AddLock; // esi
  int i; // edi
  unsigned int j; // eax
  CThreadFastMutex *p_m_mutex; // esi
  DWORD CurrentThreadId; // ecx

  this->m_bNeedsCommit = false;
  if ( this->m_EntryMemory.m_BlocksAllocated != 0 )
  {
    p_m_AddLock = &this->m_aBuckets[0].m_AddLock;
    for ( i = 2048; i != 0; --i )
    {
      if ( (p_m_AddLock->m_lockInfo.m_i32 & 0x10000) != 0
        || _InterlockedCompareExchange((volatile signed __int32 *)p_m_AddLock, 0x10000, 0) != 0 )
      {
        CThreadSpinRWLock::SpinLockForWrite(this: p_m_AddLock);
      }
      else
      {
        p_m_AddLock->m_writerId = GetCurrentThreadId();
      }
      for ( j = p_m_AddLock[-1].m_writerId; j != 0; j = *(_DWORD *)(j + 4) )
        ;
      p_m_AddLock[-1].m_lockInfo.m_i32 = 0;
      p_m_AddLock[-1].m_writerId = 0;
      p_m_AddLock->m_writerId = 0;
      p_m_AddLock->m_lockInfo.m_i32 = 0;
      p_m_AddLock += 2;
    }
    p_m_mutex = &this->m_EntryMemory.m_mutex;
    CurrentThreadId = GetCurrentThreadId();
    if ( CurrentThreadId != this->m_EntryMemory.m_mutex.m_ownerID
      && _InterlockedCompareExchange((volatile signed __int32 *)p_m_mutex, CurrentThreadId, 0) != 0 )
    {
      _mm_pause();
      CThreadFastMutex::Lock(a1: p_m_mutex, a2: CurrentThreadId, a3: 0);
    }
    else
    {
      ++this->m_EntryMemory.m_mutex.m_depth;
    }
    CUtlMemoryPool::Clear(this: &this->m_EntryMemory);
    if ( this->m_EntryMemory.m_mutex.m_depth-- == 1 )
      _InterlockedExchange((volatile __int32 *)p_m_mutex, 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00482C80
// Name: public: void CUtlSymbolTableLargeBase<class CThreadsafeTree<0>,0>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::RemoveAll(
        CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0> *this)
{
  int v2; // edi

  CUtlTSHash<CUtlSymbolTableLargeBaseTreeEntry_t *,2048,CUtlSymbolTableLargeBaseTreeEntry_t *,CCThreadsafeTreeHashMethod<2048,CUtlSymbolTableLargeBaseTreeEntry_t *,0>,0>::RemoveAll(this: &this->m_Lookup);
  v2 = 0;
  if ( this->m_StringPools.m_Size <= 0 )
  {
    this->m_StringPools.m_Size = 0;
  }
  else
  {
    do
      free(pMem: this->m_StringPools.m_Memory.m_pMemory[v2++]);
    while ( v2 < this->m_StringPools.m_Size );
    this->m_StringPools.m_Size = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00482CD0
// Name: public: CUtlSymbolTableLargeBase<class CThreadsafeTree<0>,0>::CUtlSymbolTableLargeBase<class CThreadsafeTree<0>,0>(void)
// Source: json
//------------------------------------------------------------------------------
CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0> *__thiscall CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>(
        CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0> *this)
{
  CUtlTSHash<CUtlSymbolTableLargeBaseTreeEntry_t *,2048,CUtlSymbolTableLargeBaseTreeEntry_t *,CCThreadsafeTreeHashMethod<2048,CUtlSymbolTableLargeBaseTreeEntry_t *,0>,0>::HashBucket_t *m_aBuckets; // eax
  int v3; // edx
  CThreadSpinRWLock *p_m_AddLock; // ecx
  int i; // ecx

  CUtlMemoryPool::CUtlMemoryPool(
    this: &this->m_Lookup.m_EntryMemory,
    blockSize: 12,
    numElements: 32,
    growMode: 2,
    pszAllocOwner: nullptr,
    nAlignment: 0);
  m_aBuckets = this->m_Lookup.m_aBuckets;
  this->m_Lookup.m_EntryMemory.m_mutex.m_ownerID = 0;
  this->m_Lookup.m_EntryMemory.m_mutex.m_depth = 0;
  v3 = 2047;
  p_m_AddLock = &this->m_Lookup.m_aBuckets[0].m_AddLock;
  do
  {
    p_m_AddLock->m_lockInfo.m_i32 = 0;
    p_m_AddLock->m_writerId = 0;
    p_m_AddLock += 2;
    --v3;
  }
  while ( v3 >= 0 );
  this->m_Lookup.m_bNeedsCommit = false;
  for ( i = 2048; i != 0; --i )
  {
    m_aBuckets->m_pFirst = nullptr;
    m_aBuckets->m_pFirstUncommitted = nullptr;
    ++m_aBuckets;
  }
  this->m_StringPools.m_Memory.m_pMemory = nullptr;
  this->m_StringPools.m_Memory.m_nAllocationCount = 0;
  this->m_StringPools.m_Size = 0;
  this->m_StringPools.m_pElements = nullptr;
  this->m_StringPools.m_Memory.m_nGrowSize = 8;
  return this;
}

} // namespace vp4

// ============================================================
// Overlay from vtex_gui (Missing functions)
// ============================================================
namespace vtex_gui {

//------------------------------------------------------------------------------
// Address: 0x004866A0
// Name: public: void CUtlSymbolTableLargeBase<class CNonThreadsafeTree<0>,0>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlSymbolTableLargeBase<CNonThreadsafeTree<0>,0>::RemoveAll(
        CUtlSymbolTableLargeBase<CNonThreadsafeTree<0>,0> *this)
{
  int i; // edi

  CUtlRBTree<CUtlSymbolTableLargeBaseTreeEntry_t *,int,CTreeEntryLess<CNonThreadsafeTree<0>,0>,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int>,int>>::RemoveAll(this: &this->m_Lookup);
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
// Address: 0x00486700
// Name: public: void CUtlTSHash<struct CUtlSymbolTableLargeBaseTreeEntry_t __near *,2048,struct CUtlSymbolTableLargeBaseTreeEntry_t __near *,class CCThreadsafeTreeHashMethod<2048,struct CUtlSymbolTableLargeBaseTreeEntry_t __near *,0>,0>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlTSHash<CUtlSymbolTableLargeBaseTreeEntry_t *,2048,CUtlSymbolTableLargeBaseTreeEntry_t *,CCThreadsafeTreeHashMethod<2048,CUtlSymbolTableLargeBaseTreeEntry_t *,0>,0>::RemoveAll(
        CUtlTSHash<CUtlSymbolTableLargeBaseTreeEntry_t *,2048,CUtlSymbolTableLargeBaseTreeEntry_t *,CCThreadsafeTreeHashMethod<2048,CUtlSymbolTableLargeBaseTreeEntry_t *,0>,0> *this)
{
  CThreadSpinRWLock *p_m_AddLock; // esi
  int i; // edi
  unsigned int j; // eax
  CThreadFastMutex *p_m_mutex; // esi
  DWORD CurrentThreadId; // ecx

  this->m_bNeedsCommit = false;
  if ( this->m_EntryMemory.m_BlocksAllocated != 0 )
  {
    p_m_AddLock = &this->m_aBuckets[0].m_AddLock;
    for ( i = 2048; i != 0; --i )
    {
      if ( (p_m_AddLock->m_lockInfo.m_i32 & 0x10000) != 0
        || _InterlockedCompareExchange((volatile signed __int32 *)p_m_AddLock, 0x10000, 0) != 0 )
      {
        CThreadSpinRWLock::SpinLockForWrite(this: p_m_AddLock);
      }
      else
      {
        p_m_AddLock->m_writerId = GetCurrentThreadId();
      }
      for ( j = p_m_AddLock[-1].m_writerId; j != 0; j = *(_DWORD *)(j + 4) )
        ;
      p_m_AddLock[-1].m_lockInfo.m_i32 = 0;
      p_m_AddLock[-1].m_writerId = 0;
      p_m_AddLock->m_writerId = 0;
      p_m_AddLock->m_lockInfo.m_i32 = 0;
      p_m_AddLock += 2;
    }
    p_m_mutex = &this->m_EntryMemory.m_mutex;
    CurrentThreadId = GetCurrentThreadId();
    if ( CurrentThreadId != this->m_EntryMemory.m_mutex.m_ownerID
      && _InterlockedCompareExchange((volatile signed __int32 *)p_m_mutex, CurrentThreadId, 0) != 0 )
    {
      _mm_pause();
      CThreadFastMutex::Lock(a1: p_m_mutex, a2: CurrentThreadId, a3: 0);
    }
    else
    {
      ++this->m_EntryMemory.m_mutex.m_depth;
    }
    CUtlMemoryPool::Clear(this: &this->m_EntryMemory);
    if ( this->m_EntryMemory.m_mutex.m_depth-- == 1 )
      _InterlockedExchange((volatile __int32 *)p_m_mutex, 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004867C0
// Name: public: void CUtlSymbolTableLargeBase<class CThreadsafeTree<0>,0>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::RemoveAll(
        CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0> *this)
{
  int v2; // edi

  CUtlTSHash<CUtlSymbolTableLargeBaseTreeEntry_t *,2048,CUtlSymbolTableLargeBaseTreeEntry_t *,CCThreadsafeTreeHashMethod<2048,CUtlSymbolTableLargeBaseTreeEntry_t *,0>,0>::RemoveAll(this: &this->m_Lookup);
  v2 = 0;
  if ( this->m_StringPools.m_Size <= 0 )
  {
    this->m_StringPools.m_Size = 0;
  }
  else
  {
    do
      free(pMem: this->m_StringPools.m_Memory.m_pMemory[v2++]);
    while ( v2 < this->m_StringPools.m_Size );
    this->m_StringPools.m_Size = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00486810
// Name: public: CUtlSymbolTableLargeBase<class CThreadsafeTree<0>,0>::CUtlSymbolTableLargeBase<class CThreadsafeTree<0>,0>(void)
// Source: json
//------------------------------------------------------------------------------
CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0> *__thiscall CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>(
        CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0> *this)
{
  CUtlTSHash<CUtlSymbolTableLargeBaseTreeEntry_t *,2048,CUtlSymbolTableLargeBaseTreeEntry_t *,CCThreadsafeTreeHashMethod<2048,CUtlSymbolTableLargeBaseTreeEntry_t *,0>,0>::HashBucket_t *m_aBuckets; // eax
  int v3; // edx
  CThreadSpinRWLock *p_m_AddLock; // ecx
  int i; // ecx

  CUtlMemoryPool::CUtlMemoryPool(
    this: &this->m_Lookup.m_EntryMemory,
    blockSize: 12,
    numElements: 32,
    growMode: 2,
    pszAllocOwner: nullptr,
    nAlignment: 0);
  m_aBuckets = this->m_Lookup.m_aBuckets;
  this->m_Lookup.m_EntryMemory.m_mutex.m_ownerID = 0;
  this->m_Lookup.m_EntryMemory.m_mutex.m_depth = 0;
  v3 = 2047;
  p_m_AddLock = &this->m_Lookup.m_aBuckets[0].m_AddLock;
  do
  {
    p_m_AddLock->m_lockInfo.m_i32 = 0;
    p_m_AddLock->m_writerId = 0;
    p_m_AddLock += 2;
    --v3;
  }
  while ( v3 >= 0 );
  this->m_Lookup.m_bNeedsCommit = false;
  for ( i = 2048; i != 0; --i )
  {
    m_aBuckets->m_pFirst = nullptr;
    m_aBuckets->m_pFirstUncommitted = nullptr;
    ++m_aBuckets;
  }
  this->m_StringPools.m_Memory.m_pMemory = nullptr;
  this->m_StringPools.m_Memory.m_nAllocationCount = 0;
  this->m_StringPools.m_Size = 0;
  this->m_StringPools.m_pElements = nullptr;
  this->m_StringPools.m_Memory.m_nGrowSize = 8;
  return this;
}

} // namespace vtex_gui

// ============================================================
// Overlay from client (Missing functions)
// ============================================================
namespace client {

//------------------------------------------------------------------------------
// Address: 0x10405600
// Name: public: char const __near * CDmxElement::GetTypeString(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CDmxElement::GetTypeString(CDmxElement *this)
{
  const char *result; // eax

  result = this->m_Type.u.m_pAsString;
  if ( result == (const char *)-1 )
    return prType;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10405620
// Name: private: void CDmxElement::SetId(struct UniqueId_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxElement::SetId(CDmxElement *this, const UniqueId_t *id)
{
  CopyUniqueId(src: id, pDest: &this->m_Id);
}

//------------------------------------------------------------------------------
// Address: 0x10405640
// Name: private: void CDmxElement::UnpackBitfield<unsigned char>(unsigned char __near *,struct DmxElementUnpackStructure_t const __near *,class CDmxAttribute const __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxElement::UnpackBitfield<unsigned char>(
        CDmxElement *this,
        unsigned __int8 *pDest,
        const DmxElementUnpackStructure_t *pUnpack,
        const CDmxAttribute *pAttribute)
{
  int m_nSize; // ecx
  char v6; // bl
  char v7; // al
  unsigned __int8 v8; // al
  char mask_3; // [esp+1Bh] [ebp+Fh]

  m_nSize = pUnpack->m_nSize;
  if ( m_nSize == 8 )
  {
    v6 = -1;
    v7 = -1;
  }
  else
  {
    v6 = (1 << m_nSize) - 1;
    v7 = v6 << pUnpack->m_nBitOffset;
  }
  mask_3 = ~v7;
  v8 = *(_BYTE *)pAttribute->m_pData;
  if ( ((unsigned __int8)~v6 & v8) != 0 )
  {
    _Warning(a1: "Value %s exeeds size of datatype. \n", pUnpack->m_pAttributeName);
    v8 = 0;
  }
  *pDest &= mask_3;
  *pDest |= ((unsigned __int8)v6 & v8) << pUnpack->m_nBitOffset;
}

//------------------------------------------------------------------------------
// Address: 0x104056B0
// Name: private: void CDmxElement::UnpackBitfield<char>(char __near *,struct DmxElementUnpackStructure_t const __near *,class CDmxAttribute const __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxElement::UnpackBitfield<char>(
        CDmxElement *this,
        char *pDest,
        const DmxElementUnpackStructure_t *pUnpack,
        const CDmxAttribute *pAttribute)
{
  int m_nSize; // edx
  char v6; // bl
  char v7; // al
  char v8; // al
  char v9; // dl
  char mask_3; // [esp+1Bh] [ebp+Fh]

  m_nSize = pUnpack->m_nSize;
  if ( m_nSize == 8 )
  {
    v6 = -1;
    v7 = -1;
  }
  else
  {
    v6 = (1 << m_nSize) - 1;
    v7 = v6 << pUnpack->m_nBitOffset;
  }
  mask_3 = ~v7;
  v8 = *(_BYTE *)pAttribute->m_pData;
  v9 = (1 << (m_nSize - 1)) - 1;
  if ( v8 < 0 )
  {
    if ( (~v9 & v8) != ~v9 )
    {
LABEL_8:
      _Warning(a1: "Value %s exeeds size of datatype. \n", pUnpack->m_pAttributeName);
      v8 = 0;
    }
  }
  else if ( (~v9 & v8) != 0 )
  {
    goto LABEL_8;
  }
  *pDest &= mask_3;
  *pDest |= ((unsigned __int8)v6 & (unsigned __int8)v8) << pUnpack->m_nBitOffset;
}

//------------------------------------------------------------------------------
// Address: 0x10405740
// Name: private: void CDmxElement::UnpackBitfield<short>(short __near *,struct DmxElementUnpackStructure_t const __near *,class CDmxAttribute const __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxElement::UnpackBitfield<short>(
        CDmxElement *this,
        __int16 *pDest,
        const DmxElementUnpackStructure_t *pUnpack,
        const CDmxAttribute *pAttribute)
{
  int m_nSize; // edx
  __int16 v5; // bx
  __int16 v6; // ax
  __int16 v7; // di
  __int16 v8; // ax
  int v9; // ecx
  bool v10; // zf

  m_nSize = pUnpack->m_nSize;
  if ( m_nSize == 16 )
  {
    v5 = -1;
    v6 = -1;
  }
  else
  {
    v5 = (1 << m_nSize) - 1;
    v6 = v5 << pUnpack->m_nBitOffset;
  }
  v7 = ~v6;
  v8 = *(_WORD *)pAttribute->m_pData;
  v9 = ~(__int16)((1 << (m_nSize - 1)) - 1);
  if ( v8 < 0 )
    v10 = (v9 & v8) == v9;
  else
    v10 = (v9 & v8) == 0;
  if ( !v10 )
  {
    _Warning(a1: "Value %s exeeds size of datatype. \n", pUnpack->m_pAttributeName);
    v8 = 0;
  }
  *pDest &= v7;
  *pDest |= ((unsigned __int16)v5 & (unsigned __int16)v8) << pUnpack->m_nBitOffset;
}

//------------------------------------------------------------------------------
// Address: 0x104057E0
// Name: private: void CDmxElement::UnpackBitfield<unsigned short>(unsigned short __near *,struct DmxElementUnpackStructure_t const __near *,class CDmxAttribute const __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxElement::UnpackBitfield<unsigned short>(
        CDmxElement *this,
        unsigned __int16 *pDest,
        const DmxElementUnpackStructure_t *pUnpack,
        const CDmxAttribute *pAttribute)
{
  int m_nSize; // ecx
  unsigned __int16 v5; // si
  __int16 v6; // ax
  __int16 v7; // bx
  int v8; // ecx

  m_nSize = pUnpack->m_nSize;
  if ( m_nSize == 16 )
  {
    v5 = -1;
    v6 = -1;
  }
  else
  {
    v5 = (1 << m_nSize) - 1;
    v6 = v5 << pUnpack->m_nBitOffset;
  }
  v7 = ~v6;
  v8 = *(unsigned __int16 *)pAttribute->m_pData;
  if ( (~v5 & v8) != 0 )
  {
    _Warning(a1: "Value %s exeeds size of datatype. \n", pUnpack->m_pAttributeName);
    LOWORD(v8) = 0;
  }
  *pDest &= v7;
  *pDest |= (v5 & (unsigned __int16)v8) << pUnpack->m_nBitOffset;
}

//------------------------------------------------------------------------------
// Address: 0x10405860
// Name: private: void CDmxElement::UnpackBitfield<int>(int __near *,struct DmxElementUnpackStructure_t const __near *,class CDmxAttribute const __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxElement::UnpackBitfield<int>(
        CDmxElement *this,
        int *pDest,
        const DmxElementUnpackStructure_t *pUnpack,
        const CDmxAttribute *pAttribute)
{
  int m_nSize; // edx
  int v5; // esi
  int v6; // eax
  int v7; // ebx
  int v8; // eax
  int v9; // edx
  bool v10; // zf

  m_nSize = pUnpack->m_nSize;
  if ( m_nSize == 32 )
  {
    v5 = -1;
    v6 = -1;
  }
  else
  {
    v5 = (1 << m_nSize) - 1;
    v6 = v5 << pUnpack->m_nBitOffset;
  }
  v7 = ~v6;
  v8 = *(_DWORD *)pAttribute->m_pData;
  v9 = ~((1 << (m_nSize - 1)) - 1);
  if ( v8 < 0 )
    v10 = (v8 & v9) == v9;
  else
    v10 = (v9 & v8) == 0;
  if ( !v10 )
  {
    _Warning(a1: "Value %s exeeds size of datatype. \n", pUnpack->m_pAttributeName);
    v8 = 0;
  }
  *pDest &= v7;
  *pDest |= (v5 & v8) << pUnpack->m_nBitOffset;
}

//------------------------------------------------------------------------------
// Address: 0x104058E0
// Name: private: void CDmxElement::UnpackBitfield<unsigned int>(unsigned int __near *,struct DmxElementUnpackStructure_t const __near *,class CDmxAttribute const __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxElement::UnpackBitfield<unsigned int>(
        CDmxElement *this,
        unsigned int *pDest,
        const DmxElementUnpackStructure_t *pUnpack,
        const CDmxAttribute *pAttribute)
{
  int m_nSize; // ecx
  int v5; // esi
  int v6; // eax
  int v7; // edi
  int v8; // eax

  m_nSize = pUnpack->m_nSize;
  if ( m_nSize == 32 )
  {
    v5 = -1;
    v6 = -1;
  }
  else
  {
    v5 = (1 << m_nSize) - 1;
    v6 = v5 << pUnpack->m_nBitOffset;
  }
  v7 = ~v6;
  v8 = *(_DWORD *)pAttribute->m_pData;
  if ( (~v5 & v8) != 0 )
  {
    _Warning(a1: "Value %s exeeds size of datatype. \n", pUnpack->m_pAttributeName);
    v8 = 0;
  }
  *pDest &= v7;
  *pDest |= (v5 & v8) << pUnpack->m_nBitOffset;
}

//------------------------------------------------------------------------------
// Address: 0x104059D0
// Name: private: int CUtlTSHash<struct CUtlSymbolTableLargeBaseTreeEntry_t __near *,2048,struct CUtlSymbolTableLargeBaseTreeEntry_t __near *,class CCThreadsafeTreeHashMethod<2048,struct CUtlSymbolTableLargeBaseTreeEntry_t __near *,0>,0>::Find(struct CUtlSymbolTableLargeBaseTreeEntry_t __near *,struct CUtlTSHash<struct CUtlSymbolTableLargeBaseTreeEntry_t __near *,2048,struct CUtlSymbolTableLargeBaseTreeEntry_t __near *,class CCThreadsafeTreeHashMethod<2048,struct CUtlSymbolTableLargeBaseTreeEntry_t __near *,0>,0>::HashFixedDataInternal_t<struct CUtlSymbolTableLargeBaseTreeEntry_t __near *> __near *,struct CUtlTSHash<struct CUtlSymbolTableLargeBaseTreeEntry_t __near *,2048,struct CUtlSymbolTableLargeBaseTreeEntry_t __near *,class CCThreadsafeTreeHashMethod<2048,struct CUtlSymbolTableLargeBaseTreeEntry_t __near *,0>,0>::HashFixedDataInternal_t<struct CUtlSymbolTableLargeBaseTreeEntry_t __near *> __near *)
// Source: json
//------------------------------------------------------------------------------
CUtlTSHash<CUtlSymbolTableLargeBaseTreeEntry_t *,2048,CUtlSymbolTableLargeBaseTreeEntry_t *,CCThreadsafeTreeHashMethod<2048,CUtlSymbolTableLargeBaseTreeEntry_t *,0>,0>::HashFixedDataInternal_t<CUtlSymbolTableLargeBaseTreeEntry_t *> *__thiscall CUtlTSHash<CUtlSymbolTableLargeBaseTreeEntry_t *,2048,CUtlSymbolTableLargeBaseTreeEntry_t *,CCThreadsafeTreeHashMethod<2048,CUtlSymbolTableLargeBaseTreeEntry_t *,0>,0>::Find(
        CUtlTSHash<CUtlSymbolTableLargeBaseTreeEntry_t *,2048,CUtlSymbolTableLargeBaseTreeEntry_t *,CCThreadsafeTreeHashMethod<2048,CUtlSymbolTableLargeBaseTreeEntry_t *,0>,0> *this,
        CUtlSymbolTableLargeBaseTreeEntry_t *uiKey,
        CUtlTSHash<CUtlSymbolTableLargeBaseTreeEntry_t *,2048,CUtlSymbolTableLargeBaseTreeEntry_t *,CCThreadsafeTreeHashMethod<2048,CUtlSymbolTableLargeBaseTreeEntry_t *,0>,0>::HashFixedDataInternal_t<CUtlSymbolTableLargeBaseTreeEntry_t *> *pFirstElement,
        CUtlTSHash<CUtlSymbolTableLargeBaseTreeEntry_t *,2048,CUtlSymbolTableLargeBaseTreeEntry_t *,CCThreadsafeTreeHashMethod<2048,CUtlSymbolTableLargeBaseTreeEntry_t *,0>,0>::HashFixedDataInternal_t<CUtlSymbolTableLargeBaseTreeEntry_t *> *pLastElement)
{
  CUtlTSHash<CUtlSymbolTableLargeBaseTreeEntry_t *,2048,CUtlSymbolTableLargeBaseTreeEntry_t *,CCThreadsafeTreeHashMethod<2048,CUtlSymbolTableLargeBaseTreeEntry_t *,0>,0>::HashFixedDataInternal_t<CUtlSymbolTableLargeBaseTreeEntry_t *> *v4; // esi

  v4 = pFirstElement;
  if ( pFirstElement == pLastElement )
    return nullptr;
  while ( v4->m_uiKey->m_Hash != uiKey->m_Hash || _V_strcmp(s1: v4->m_uiKey->m_String, s2: uiKey->m_String) != 0 )
  {
    v4 = v4->m_pNext;
    if ( v4 == pLastElement )
      return nullptr;
  }
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x10405A20
// Name: private: int CUtlTSHash<struct CUtlSymbolTableLargeBaseTreeEntry_t __near *,2048,struct CUtlSymbolTableLargeBaseTreeEntry_t __near *,class CCThreadsafeTreeHashMethod<2048,struct CUtlSymbolTableLargeBaseTreeEntry_t __near *,0>,0>::InsertUncommitted(struct CUtlSymbolTableLargeBaseTreeEntry_t __near *,struct CUtlTSHash<struct CUtlSymbolTableLargeBaseTreeEntry_t __near *,2048,struct CUtlSymbolTableLargeBaseTreeEntry_t __near *,class CCThreadsafeTreeHashMethod<2048,struct CUtlSymbolTableLargeBaseTreeEntry_t __near *,0>,0>::HashBucket_t __near &)
// Source: json
//------------------------------------------------------------------------------
CUtlTSHash<CUtlSymbolTableLargeBaseTreeEntry_t *,2048,CUtlSymbolTableLargeBaseTreeEntry_t *,CCThreadsafeTreeHashMethod<2048,CUtlSymbolTableLargeBaseTreeEntry_t *,0>,0>::HashFixedDataInternal_t<CUtlSymbolTableLargeBaseTreeEntry_t *> *__thiscall CUtlTSHash<CUtlSymbolTableLargeBaseTreeEntry_t *,2048,CUtlSymbolTableLargeBaseTreeEntry_t *,CCThreadsafeTreeHashMethod<2048,CUtlSymbolTableLargeBaseTreeEntry_t *,0>,0>::InsertUncommitted(
        CUtlTSHash<CUtlSymbolTableLargeBaseTreeEntry_t *,2048,CUtlSymbolTableLargeBaseTreeEntry_t *,CCThreadsafeTreeHashMethod<2048,CUtlSymbolTableLargeBaseTreeEntry_t *,0>,0> *this,
        CUtlSymbolTableLargeBaseTreeEntry_t *uiKey,
        CUtlTSHash<CUtlSymbolTableLargeBaseTreeEntry_t *,2048,CUtlSymbolTableLargeBaseTreeEntry_t *,CCThreadsafeTreeHashMethod<2048,CUtlSymbolTableLargeBaseTreeEntry_t *,0>,0>::HashBucket_t *bucket)
{
  CThreadFastMutex *p_m_mutex; // esi
  DWORD CurrentThreadId; // ecx
  CUtlTSHash<CUtlSymbolTableLargeBaseTreeEntry_t *,2048,CUtlSymbolTableLargeBaseTreeEntry_t *,CCThreadsafeTreeHashMethod<2048,CUtlSymbolTableLargeBaseTreeEntry_t *,0>,0>::HashFixedDataInternal_t<CUtlSymbolTableLargeBaseTreeEntry_t *> *result; // eax

  this->m_bNeedsCommit = true;
  p_m_mutex = &this->m_EntryMemory.m_mutex;
  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != p_m_mutex->m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)p_m_mutex, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(a1: p_m_mutex, a2: CurrentThreadId, a3: 0);
  }
  else
  {
    ++p_m_mutex->m_depth;
  }
  result = (CUtlTSHash<CUtlSymbolTableLargeBaseTreeEntry_t *,2048,CUtlSymbolTableLargeBaseTreeEntry_t *,CCThreadsafeTreeHashMethod<2048,CUtlSymbolTableLargeBaseTreeEntry_t *,0>,0>::HashFixedDataInternal_t<CUtlSymbolTableLargeBaseTreeEntry_t *> *)CUtlMemoryPool::Alloc(this: &this->m_EntryMemory);
  if ( p_m_mutex->m_depth-- == 1 )
    _InterlockedExchange((volatile __int32 *)p_m_mutex, 0);
  result->m_pNext = bucket->m_pFirstUncommitted;
  bucket->m_pFirstUncommitted = result;
  result->m_uiKey = uiKey;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10405A90
// Name: public: void CUtlTSHash<struct CUtlSymbolTableLargeBaseTreeEntry_t __near *,2048,struct CUtlSymbolTableLargeBaseTreeEntry_t __near *,class CCThreadsafeTreeHashMethod<2048,struct CUtlSymbolTableLargeBaseTreeEntry_t __near *,0>,0>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlTSHash<CUtlSymbolTableLargeBaseTreeEntry_t *,2048,CUtlSymbolTableLargeBaseTreeEntry_t *,CCThreadsafeTreeHashMethod<2048,CUtlSymbolTableLargeBaseTreeEntry_t *,0>,0>::RemoveAll(
        CUtlTSHash<CUtlSymbolTableLargeBaseTreeEntry_t *,2048,CUtlSymbolTableLargeBaseTreeEntry_t *,CCThreadsafeTreeHashMethod<2048,CUtlSymbolTableLargeBaseTreeEntry_t *,0>,0> *this)
{
  CThreadSpinRWLock *p_m_AddLock; // esi
  int i; // edi
  unsigned int j; // eax
  CThreadFastMutex *p_m_mutex; // esi
  DWORD CurrentThreadId; // ecx

  this->m_bNeedsCommit = false;
  if ( this->m_EntryMemory.m_BlocksAllocated != 0 )
  {
    p_m_AddLock = &this->m_aBuckets[0].m_AddLock;
    for ( i = 2048; i != 0; --i )
    {
      if ( (p_m_AddLock->m_lockInfo.m_i32 & 0x10000) != 0
        || _InterlockedCompareExchange((volatile signed __int32 *)p_m_AddLock, 0x10000, 0) != 0 )
      {
        CThreadSpinRWLock::SpinLockForWrite(this: p_m_AddLock);
      }
      else
      {
        p_m_AddLock->m_writerId = GetCurrentThreadId();
      }
      for ( j = p_m_AddLock[-1].m_writerId; j != 0; j = *(_DWORD *)(j + 4) )
        ;
      p_m_AddLock[-1].m_lockInfo.m_i32 = 0;
      p_m_AddLock[-1].m_writerId = 0;
      p_m_AddLock->m_writerId = 0;
      p_m_AddLock->m_lockInfo.m_i32 = 0;
      p_m_AddLock += 2;
    }
    p_m_mutex = &this->m_EntryMemory.m_mutex;
    CurrentThreadId = GetCurrentThreadId();
    if ( CurrentThreadId != this->m_EntryMemory.m_mutex.m_ownerID
      && _InterlockedCompareExchange((volatile signed __int32 *)p_m_mutex, CurrentThreadId, 0) != 0 )
    {
      _mm_pause();
      CThreadFastMutex::Lock(a1: p_m_mutex, a2: CurrentThreadId, a3: 0);
    }
    else
    {
      ++this->m_EntryMemory.m_mutex.m_depth;
    }
    CUtlMemoryPool::Clear(this: &this->m_EntryMemory);
    if ( this->m_EntryMemory.m_mutex.m_depth-- == 1 )
      _InterlockedExchange((volatile __int32 *)p_m_mutex, 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10405C80
// Name: private: int CUtlSymbolTableLargeBase<class CThreadsafeTree<0>,0>::FindPoolWithSpace(int)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::FindPoolWithSpace(
        CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0> *this,
        int len)
{
  int m_Size; // esi
  int result; // eax
  CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t **i; // edx

  m_Size = this->m_StringPools.m_Size;
  result = 0;
  if ( m_Size <= 0 )
    return -1;
  for ( i = this->m_StringPools.m_Memory.m_pMemory; (*i)->m_TotalLen - (*i)->m_SpaceUsed < len; ++i )
  {
    if ( ++result >= m_Size )
      return -1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10405CC0
// Name: public: int CUtlTSHash<struct CUtlSymbolTableLargeBaseTreeEntry_t __near *,2048,struct CUtlSymbolTableLargeBaseTreeEntry_t __near *,class CCThreadsafeTreeHashMethod<2048,struct CUtlSymbolTableLargeBaseTreeEntry_t __near *,0>,0>::Insert(struct CUtlSymbolTableLargeBaseTreeEntry_t __near *,struct CUtlSymbolTableLargeBaseTreeEntry_t __near * const __near &,bool __near *)
// Source: json
//------------------------------------------------------------------------------
CUtlTSHash<CUtlSymbolTableLargeBaseTreeEntry_t *,2048,CUtlSymbolTableLargeBaseTreeEntry_t *,CCThreadsafeTreeHashMethod<2048,CUtlSymbolTableLargeBaseTreeEntry_t *,0>,0>::HashFixedDataInternal_t<CUtlSymbolTableLargeBaseTreeEntry_t *> *__thiscall CUtlTSHash<CUtlSymbolTableLargeBaseTreeEntry_t *,2048,CUtlSymbolTableLargeBaseTreeEntry_t *,CCThreadsafeTreeHashMethod<2048,CUtlSymbolTableLargeBaseTreeEntry_t *,0>,0>::Insert(
        CUtlTSHash<CUtlSymbolTableLargeBaseTreeEntry_t *,2048,CUtlSymbolTableLargeBaseTreeEntry_t *,CCThreadsafeTreeHashMethod<2048,CUtlSymbolTableLargeBaseTreeEntry_t *,0>,0> *this,
        CUtlSymbolTableLargeBaseTreeEntry_t *uiKey,
        CUtlSymbolTableLargeBaseTreeEntry_t **data,
        bool *pDidInsert)
{
  CUtlTSHash<CUtlSymbolTableLargeBaseTreeEntry_t *,2048,CUtlSymbolTableLargeBaseTreeEntry_t *,CCThreadsafeTreeHashMethod<2048,CUtlSymbolTableLargeBaseTreeEntry_t *,0>,0>::HashBucket_t *v5; // esi
  CUtlTSHash<CUtlSymbolTableLargeBaseTreeEntry_t *,2048,CUtlSymbolTableLargeBaseTreeEntry_t *,CCThreadsafeTreeHashMethod<2048,CUtlSymbolTableLargeBaseTreeEntry_t *,0>,0>::HashFixedDataInternal_t<CUtlSymbolTableLargeBaseTreeEntry_t *> *result; // eax
  CThreadSpinRWLock *p_m_AddLock; // ecx

  if ( pDidInsert != nullptr )
    *pDidInsert = false;
  v5 = &this->m_aBuckets[uiKey->m_Hash & 0x7FF];
  result = CUtlTSHash<CUtlSymbolTableLargeBaseTreeEntry_t *,2048,CUtlSymbolTableLargeBaseTreeEntry_t *,CCThreadsafeTreeHashMethod<2048,CUtlSymbolTableLargeBaseTreeEntry_t *,0>,0>::Find(
             this,
             uiKey,
             pFirstElement: v5->m_pFirst,
             pLastElement: nullptr);
  if ( result == nullptr )
  {
    CThreadSpinRWLock::LockForRead(this: &v5->m_AddLock);
    result = CUtlTSHash<CUtlSymbolTableLargeBaseTreeEntry_t *,2048,CUtlSymbolTableLargeBaseTreeEntry_t *,CCThreadsafeTreeHashMethod<2048,CUtlSymbolTableLargeBaseTreeEntry_t *,0>,0>::Find(
               this,
               uiKey,
               pFirstElement: v5->m_pFirstUncommitted,
               pLastElement: v5->m_pFirst);
    _InterlockedExchangeAdd((volatile signed __int32 *)&v5->m_AddLock, 0xFFFFFFFF);
    if ( result == nullptr )
    {
      p_m_AddLock = &v5->m_AddLock;
      if ( (v5->m_AddLock.m_lockInfo.m_i32 & 0x10000) != 0
        || _InterlockedCompareExchange((volatile signed __int32 *)p_m_AddLock, 0x10000, 0) != 0 )
      {
        CThreadSpinRWLock::SpinLockForWrite(this: p_m_AddLock);
      }
      else
      {
        v5->m_AddLock.m_writerId = GetCurrentThreadId();
      }
      result = CUtlTSHash<CUtlSymbolTableLargeBaseTreeEntry_t *,2048,CUtlSymbolTableLargeBaseTreeEntry_t *,CCThreadsafeTreeHashMethod<2048,CUtlSymbolTableLargeBaseTreeEntry_t *,0>,0>::Find(
                 this,
                 uiKey,
                 pFirstElement: v5->m_pFirstUncommitted,
                 pLastElement: v5->m_pFirst);
      if ( result == nullptr )
      {
        result = CUtlTSHash<CUtlSymbolTableLargeBaseTreeEntry_t *,2048,CUtlSymbolTableLargeBaseTreeEntry_t *,CCThreadsafeTreeHashMethod<2048,CUtlSymbolTableLargeBaseTreeEntry_t *,0>,0>::InsertUncommitted(
                   this,
                   uiKey,
                   bucket: v5);
        if ( result != (CUtlTSHash<CUtlSymbolTableLargeBaseTreeEntry_t *,2048,CUtlSymbolTableLargeBaseTreeEntry_t *,CCThreadsafeTreeHashMethod<2048,CUtlSymbolTableLargeBaseTreeEntry_t *,0>,0>::HashFixedDataInternal_t<CUtlSymbolTableLargeBaseTreeEntry_t *> *)-8 )
          result->m_Data = *data;
        if ( pDidInsert != nullptr )
          *pDidInsert = true;
      }
      v5->m_AddLock.m_writerId = 0;
      v5->m_AddLock.m_lockInfo.m_i32 = 0;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10405E10
// Name: public: class CUtlSymbolLarge CUtlSymbolTableLargeBase<class CThreadsafeTree<0>,0>::Find(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
CUtlSymbolLarge *__thiscall CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::Find(
        CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0> *this,
        CUtlSymbolLarge *result,
        char *pString)
{
  unsigned int v5; // eax
  unsigned int v6; // edi
  void *v7; // esp
  CUtlTSHash<CUtlSymbolTableLargeBaseTreeEntry_t *,2048,CUtlSymbolTableLargeBaseTreeEntry_t *,CCThreadsafeTreeHashMethod<2048,CUtlSymbolTableLargeBaseTreeEntry_t *,0>,0>::HashBucket_t *v8; // edi
  CUtlTSHash<CUtlSymbolTableLargeBaseTreeEntry_t *,2048,CUtlSymbolTableLargeBaseTreeEntry_t *,CCThreadsafeTreeHashMethod<2048,CUtlSymbolTableLargeBaseTreeEntry_t *,0>,0>::HashFixedDataInternal_t<CUtlSymbolTableLargeBaseTreeEntry_t *> *v9; // eax
  CUtlSymbolTableLargeBaseTreeEntry_t v10; // [esp+0h] [ebp-Ch] BYREF

  if ( pString == nullptr )
    goto LABEL_2;
  v5 = _V_strlen(str: pString);
  v6 = v5 + 1;
  v7 = alloca(v5 + 5);
  v10.m_Hash = HashString(pszKey: pString);
  _V_memcpy(dest: (unsigned __int8 *)v10.m_String, src: (unsigned __int8 *)pString, count: v6);
  v8 = &this->m_Lookup.m_aBuckets[v10.m_Hash & 0x7FF];
  v9 = CUtlTSHash<CUtlSymbolTableLargeBaseTreeEntry_t *,2048,CUtlSymbolTableLargeBaseTreeEntry_t *,CCThreadsafeTreeHashMethod<2048,CUtlSymbolTableLargeBaseTreeEntry_t *,0>,0>::Find(
         this: &this->m_Lookup,
         uiKey: &v10,
         pFirstElement: v8->m_pFirst,
         pLastElement: nullptr);
  if ( v9 != nullptr
    || (CThreadSpinRWLock::LockForRead(this: &v8->m_AddLock),
        v9 = CUtlTSHash<CUtlSymbolTableLargeBaseTreeEntry_t *,2048,CUtlSymbolTableLargeBaseTreeEntry_t *,CCThreadsafeTreeHashMethod<2048,CUtlSymbolTableLargeBaseTreeEntry_t *,0>,0>::Find(
               this: &this->m_Lookup,
               uiKey: &v10,
               pFirstElement: v8->m_pFirstUncommitted,
               pLastElement: v8->m_pFirst),
        _InterlockedExchangeAdd((volatile signed __int32 *)&v8->m_AddLock, 0xFFFFFFFF),
        v9 != nullptr) )
  {
    result->u.m_Id = (int)v9->m_Data->m_String;
    return result;
  }
  else
  {
LABEL_2:
    result->u.m_Id = -1;
    return result;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10405ED0
// Name: public: void CUtlSymbolTableLargeBase<class CThreadsafeTree<0>,0>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::RemoveAll(
        CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0> *this)
{
  int v2; // edi

  CUtlTSHash<CUtlSymbolTableLargeBaseTreeEntry_t *,2048,CUtlSymbolTableLargeBaseTreeEntry_t *,CCThreadsafeTreeHashMethod<2048,CUtlSymbolTableLargeBaseTreeEntry_t *,0>,0>::RemoveAll(this: &this->m_Lookup);
  v2 = 0;
  if ( this->m_StringPools.m_Size <= 0 )
  {
    this->m_StringPools.m_Size = 0;
  }
  else
  {
    do
      C_BaseEntity::operator delete(pMem: this->m_StringPools.m_Memory.m_pMemory[v2++]);
    while ( v2 < this->m_StringPools.m_Size );
    this->m_StringPools.m_Size = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10405F20
// Name: private: void CDmxElement::Resort(void)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxElement::Resort(CDmxElement *this)
{
  signed int m_Size; // eax
  int i; // edi
  CDmxAttribute **v4; // eax
  const char *Name; // eax
  _DWORD context[2]; // [esp+4h] [ebp-Ch] BYREF
  char v7; // [esp+Fh] [ebp-1h] BYREF

  if ( (*((_BYTE *)this + 49) & 1) != 0 )
  {
    if ( this->m_Attributes.m_bNeedsSort )
    {
      m_Size = this->m_Attributes.m_Size;
      this->m_Attributes.m_bNeedsSort = false;
      if ( m_Size > 1 )
      {
        context[0] = this->m_Attributes.m_pLessContext;
        context[1] = &v7;
        qsort_s(
          base: (char *)this->m_Attributes.m_Memory.m_pMemory,
          num: m_Size,
          width: 4u,
          comp: (int (__cdecl *)(void *, const void *, const void *))CUtlSortVector<CDmxAttribute *,CDmxAttributeLess>::CompareHelper,
          context);
      }
    }
    *((_BYTE *)this + 49) &= ~1u;
    for ( i = this->m_Attributes.m_Size - 1; i >= 1; --i )
    {
      v4 = &this->m_Attributes.m_Memory.m_pMemory[i];
      if ( *v4 != nullptr && *(v4 - 1) != nullptr && (*v4)->m_Name.u.m_Id == (*(v4 - 1))->m_Name.u.m_Id )
      {
        Name = CDmxAttribute::GetName(this: *v4);
        _Warning(a1: "Duplicate attribute name %s encountered!\n", Name);
        if ( this->m_Attributes.m_Size - i - 1 > 0 )
          _V_memmove(
            dest: (unsigned __int8 *)&this->m_Attributes.m_Memory.m_pMemory[i],
            src: (unsigned __int8 *)&this->m_Attributes.m_Memory.m_pMemory[i + 1],
            count: 4 * (this->m_Attributes.m_Size - i - 1));
        --this->m_Attributes.m_Size;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10405FF0
// Name: public: void CDmxElement::LockForChanges(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxElement::LockForChanges(CDmxElement *this, bool bLock)
{
  if ( bLock )
  {
    ++this->m_nLockCount;
  }
  else if ( this->m_nLockCount-- == 1 )
  {
    CDmxElement::Resort(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10406010
// Name: public: bool CDmxElement::HasAttribute(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CDmxElement::HasAttribute(CDmxElement *this, const char *pAttributeName)
{
  int v3; // esi
  CDmxAttribute v5; // [esp+4h] [ebp-Ch] BYREF

  CDmxElement::Resort(this);
  CDmxAttribute::CDmxAttribute(this: &v5, pAttributeName);
  pAttributeName = (const char *)&v5;
  v3 = CUtlSortVector<CDmxAttribute *,CDmxAttributeLess>::Find(
         this: &this->m_Attributes,
         src: (CDmxAttribute *const **)&pAttributeName);
  CDmxAttribute::~CDmxAttribute(this: &v5);
  return v3 >= 0;
}

//------------------------------------------------------------------------------
// Address: 0x10406060
// Name: public: class CDmxAttribute const __near * CDmxElement::GetAttribute(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
const CDmxAttribute *__thiscall CDmxElement::GetAttribute(CDmxElement *this, const char *pAttributeName)
{
  int v3; // edi
  CDmxAttribute v5; // [esp+8h] [ebp-Ch] BYREF

  CDmxElement::Resort(this);
  CDmxAttribute::CDmxAttribute(this: &v5, pAttributeName);
  pAttributeName = (const char *)&v5;
  v3 = CUtlSortVector<CDmxAttribute *,CDmxAttributeLess>::Find(
         this: &this->m_Attributes,
         src: (CDmxAttribute *const **)&pAttributeName);
  CDmxAttribute::~CDmxAttribute(this: &v5);
  if ( v3 < 0 )
    return nullptr;
  else
    return this->m_Attributes.m_Memory.m_pMemory[v3];
}

//------------------------------------------------------------------------------
// Address: 0x104060C0
// Name: private: void CDmxElement::AddElementsToDelete(class CUtlVector<class CDmxElement __near *,class CUtlMemory<class CDmxElement __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxElement::AddElementsToDelete(CDmxElement *this, CUtlMemory<vgui::TreeNode *,int> *elementsToDelete)
{
  CDmxElement *v2; // ebx
  char v3; // al
  int m_pMemory; // esi
  int m_nAllocationCount; // eax
  CDmxElement **v7; // ecx
  int v8; // eax
  CDmxElement **v9; // esi
  int v10; // eax
  CDmxAttribute *v11; // eax
  CDmxElement *v12; // ecx
  _DWORD *m_pData; // ebx
  int v14; // ecx
  int v15; // esi
  int nCount; // [esp+4h] [ebp-Ch]
  int nElementCount; // [esp+8h] [ebp-8h]
  int i; // [esp+18h] [ebp+8h]

  v2 = this;
  v3 = *((_BYTE *)this + 49);
  if ( (v3 & 2) == 0 )
  {
    *((_BYTE *)this + 49) = v3 | 2;
    m_pMemory = (int)elementsToDelete[1].m_pMemory;
    m_nAllocationCount = elementsToDelete->m_nAllocationCount;
    if ( m_pMemory + 1 > m_nAllocationCount )
      CUtlMemory<CChoreoActor *,int>::Grow(this: elementsToDelete, num: m_pMemory - m_nAllocationCount + 1);
    ++elementsToDelete[1].m_pMemory;
    v7 = (CDmxElement **)elementsToDelete->m_pMemory;
    v8 = (int)elementsToDelete[1].m_pMemory - m_pMemory - 1;
    elementsToDelete[1].m_nAllocationCount = (int)elementsToDelete->m_pMemory;
    if ( v8 > 0 )
      _V_memmove(dest: (unsigned __int8 *)&v7[m_pMemory + 1], src: (unsigned __int8 *)&v7[m_pMemory], count: 4 * v8);
    v9 = (CDmxElement **)&elementsToDelete->m_pMemory[m_pMemory];
    if ( v9 != nullptr )
      *v9 = v2;
    v10 = 0;
    nCount = v2->m_Attributes.m_Size;
    i = 0;
    if ( nCount > 0 )
    {
      do
      {
        v11 = v2->m_Attributes.m_Memory.m_pMemory[v10];
        if ( v11->m_Type == AT_FIRST_VALUE_TYPE )
        {
          v12 = *(CDmxElement **)v11->m_pData;
          if ( v12 != nullptr )
            CDmxElement::AddElementsToDelete(
              this: v12,
              (CUtlVector<CDmxElement *,CUtlMemory<CDmxElement *,int> > *)elementsToDelete);
        }
        else if ( v11->m_Type == AT_FIRST_ARRAY_TYPE )
        {
          m_pData = v11->m_pData;
          v14 = m_pData[3];
          v15 = 0;
          for ( nElementCount = v14; v15 < v14; ++v15 )
          {
            if ( *(_DWORD *)(*m_pData + 4 * v15) != 0 )
            {
              CDmxElement::AddElementsToDelete(
                this: *(CDmxElement **)(*m_pData + 4 * v15),
                (CUtlVector<CDmxElement *,CUtlMemory<CDmxElement *,int> > *)elementsToDelete);
              v14 = nElementCount;
            }
          }
          v2 = this;
        }
        v10 = i + 1;
        i = v10;
      }
      while ( v10 < nCount );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x104061B0
// Name: public: CUtlSymbolTableLargeBase<class CThreadsafeTree<0>,0>::CUtlSymbolTableLargeBase<class CThreadsafeTree<0>,0>(void)
// Source: json
//------------------------------------------------------------------------------
CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0> *__thiscall CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>(
        CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0> *this)
{
  CUtlTSHash<CUtlSymbolTableLargeBaseTreeEntry_t *,2048,CUtlSymbolTableLargeBaseTreeEntry_t *,CCThreadsafeTreeHashMethod<2048,CUtlSymbolTableLargeBaseTreeEntry_t *,0>,0>::HashBucket_t *m_aBuckets; // eax
  int v3; // edx
  CThreadSpinRWLock *p_m_AddLock; // ecx
  int i; // ecx

  CUtlMemoryPool::CUtlMemoryPool(
    this: &this->m_Lookup.m_EntryMemory,
    blockSize: 0xCu,
    numElements: 32,
    growMode: 2,
    pszAllocOwner: nullptr,
    nAlignment: 0);
  m_aBuckets = this->m_Lookup.m_aBuckets;
  this->m_Lookup.m_EntryMemory.m_mutex.m_ownerID = 0;
  this->m_Lookup.m_EntryMemory.m_mutex.m_depth = 0;
  v3 = 2047;
  p_m_AddLock = &this->m_Lookup.m_aBuckets[0].m_AddLock;
  do
  {
    p_m_AddLock->m_lockInfo.m_i32 = 0;
    p_m_AddLock->m_writerId = 0;
    p_m_AddLock += 2;
    --v3;
  }
  while ( v3 >= 0 );
  this->m_Lookup.m_bNeedsCommit = false;
  for ( i = 2048; i != 0; --i )
  {
    m_aBuckets->m_pFirst = nullptr;
    m_aBuckets->m_pFirstUncommitted = nullptr;
    ++m_aBuckets;
  }
  this->m_StringPools.m_Memory.m_pMemory = nullptr;
  this->m_StringPools.m_Memory.m_nAllocationCount = 0;
  this->m_StringPools.m_Size = 0;
  this->m_StringPools.m_pElements = nullptr;
  this->m_StringPools.m_Memory.m_nGrowSize = 8;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10406230
// Name: public: class CUtlSymbolLarge CUtlSymbolTableLargeBase<class CThreadsafeTree<0>,0>::AddString(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CUtlSymbolLarge *__thiscall CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::AddString(
        CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0> *this,
        CUtlSymbolLarge *result,
        char *pString)
{
  const char *v3; // esi
  void *m_String; // ecx
  unsigned int v7; // eax
  unsigned int v8; // edi
  int PoolWithSpace; // esi
  unsigned int v10; // esi
  CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *v11; // edx
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t **m_pMemory; // ecx
  int v15; // eax
  CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t **v16; // eax
  int v17; // eax
  CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *v18; // ecx
  int m_SpaceUsed; // edx
  int v20; // esi
  unsigned __int8 *v21; // ecx
  unsigned int lenString; // [esp+8h] [ebp-Ch]
  int lenDecorated; // [esp+Ch] [ebp-8h]
  CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *pPool; // [esp+10h] [ebp-4h] BYREF

  v3 = pString;
  if ( pString != nullptr )
  {
    CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::Find(this, result: (CUtlSymbolLarge *)&pPool, pString);
    m_String = pPool;
    if ( pPool == (CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *)-1 )
    {
      v7 = _V_strlen(str: v3) + 1;
      v8 = (v7 + 7) & 0xFFFFFFFC;
      lenString = v7;
      lenDecorated = v8;
      PoolWithSpace = CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::FindPoolWithSpace(this, len: v8);
      if ( PoolWithSpace == -1 )
      {
        v10 = v8 + 12;
        if ( v8 + 12 <= 0x800 )
          v10 = 2048;
        v11 = (CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *)MemAlloc_Alloc(nSize: v10);
        v11->m_TotalLen = v10 - 12;
        v11->m_SpaceUsed = 0;
        m_Size = this->m_StringPools.m_Size;
        m_nAllocationCount = this->m_StringPools.m_Memory.m_nAllocationCount;
        pPool = v11;
        if ( m_Size + 1 > m_nAllocationCount )
        {
          CUtlMemory<CChoreoActor *,int>::Grow(
            this: (CUtlMemory<vgui::TreeNode *,int> *)&this->m_StringPools,
            num: m_Size - m_nAllocationCount + 1);
          v11 = pPool;
        }
        ++this->m_StringPools.m_Size;
        m_pMemory = this->m_StringPools.m_Memory.m_pMemory;
        v15 = this->m_StringPools.m_Size - m_Size - 1;
        this->m_StringPools.m_pElements = m_pMemory;
        if ( v15 > 0 )
        {
          _V_memmove(
            dest: (unsigned __int8 *)&m_pMemory[m_Size + 1],
            src: (unsigned __int8 *)&m_pMemory[m_Size],
            count: 4 * v15);
          v11 = pPool;
        }
        v16 = &this->m_StringPools.m_Memory.m_pMemory[m_Size];
        if ( v16 != nullptr )
          *v16 = v11;
        PoolWithSpace = m_Size;
        v8 = lenDecorated;
      }
      v17 = HashString(pszKey: pString);
      v18 = this->m_StringPools.m_Memory.m_pMemory[PoolWithSpace];
      m_SpaceUsed = v18->m_SpaceUsed;
      v20 = (int)&v18->m_Data[m_SpaceUsed];
      v18->m_SpaceUsed = v8 + m_SpaceUsed;
      v21 = (unsigned __int8 *)pString;
      *(_DWORD *)v20 = v17;
      _V_memcpy(dest: (unsigned __int8 *)(v20 + 4), src: v21, count: lenString);
      pString = (char *)v20;
      m_String = CUtlTSHash<CUtlSymbolTableLargeBaseTreeEntry_t *,2048,CUtlSymbolTableLargeBaseTreeEntry_t *,CCThreadsafeTreeHashMethod<2048,CUtlSymbolTableLargeBaseTreeEntry_t *,0>,0>::Insert(
                   this: &this->m_Lookup,
                   uiKey: (CUtlSymbolTableLargeBaseTreeEntry_t *)v20,
                   data: (CUtlSymbolTableLargeBaseTreeEntry_t **)&pString,
                   pDidInsert: nullptr)->m_Data->m_String;
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
// Address: 0x10406390
// Name: public: class CUtlString const __near & CDmxElement::GetValue<class CUtlString>(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
const CUtlString *__thiscall CDmxElement::GetValue<CUtlString>(CDmxElement *this, const char *pAttributeName)
{
  int v3; // edi
  CDmxAttribute *v4; // eax
  CDmxAttribute v6; // [esp+8h] [ebp-Ch] BYREF

  CDmxElement::Resort(this);
  CDmxAttribute::CDmxAttribute(this: &v6, pAttributeName);
  pAttributeName = (const char *)&v6;
  v3 = CUtlSortVector<CDmxAttribute *,CDmxAttributeLess>::Find(
         this: &this->m_Attributes,
         src: (CDmxAttribute *const **)&pAttributeName);
  CDmxAttribute::~CDmxAttribute(this: &v6);
  if ( v3 >= 0 && (v4 = this->m_Attributes.m_Memory.m_pMemory[v3]) != nullptr )
  {
    if ( v4->m_Type == AT_STRING )
    {
      return (const CUtlString *)v4->m_pData;
    }
    else
    {
      if ( (`CDmxAttribute::GetValue<CUtlString>'::`4'::`local static guard' & 1) == 0 )
      {
        `CDmxAttribute::GetValue<CUtlString>'::`4'::`local static guard' |= 1u;
        CUtlString::CUtlString(this: &`CDmxAttribute::GetValue<CUtlString>'::`4'::defaultValue);
        atexit(func: `CDmxAttribute::GetValue<CUtlString>'::`4'::`dynamic atexit destructor for 'defaultValue'');
      }
      CUtlString::Set(this: &`CDmxAttribute::GetValue<CUtlString>'::`4'::defaultValue, pValue: nullptr);
      return &`CDmxAttribute::GetValue<CUtlString>'::`4'::defaultValue;
    }
  }
  else
  {
    if ( (`CDmxElement::GetValue<CUtlString>'::`4'::`local static guard' & 1) == 0 )
    {
      `CDmxElement::GetValue<CUtlString>'::`4'::`local static guard' |= 1u;
      CUtlString::CUtlString(this: &`CDmxElement::GetValue<CUtlString>'::`4'::defaultValue);
      atexit(func: `CDmxElement::GetValue<CUtlString>'::`4'::`dynamic atexit destructor for 'defaultValue'');
    }
    CUtlString::Set(this: &`CDmxElement::GetValue<CUtlString>'::`4'::defaultValue, pValue: nullptr);
    return &`CDmxElement::GetValue<CUtlString>'::`4'::defaultValue;
  }
}

//------------------------------------------------------------------------------
// Address: 0x104064C0
// Name: private: CDmxElement::CDmxElement(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDmxElement *__thiscall CDmxElement::CDmxElement(CDmxElement *this, const char *pType)
{
  const char *v4; // [esp-4h] [ebp-Ch]

  v4 = pType;
  this->m_Attributes.m_Memory.m_pMemory = nullptr;
  this->m_Attributes.m_Memory.m_nAllocationCount = 0;
  this->m_Attributes.m_Memory.m_nGrowSize = 0;
  this->m_Attributes.m_Size = 0;
  this->m_Attributes.m_pElements = nullptr;
  this->m_Attributes.m_pLessContext = nullptr;
  this->m_Attributes.m_bNeedsSort = false;
  this->m_Type.u.m_Id = -1;
  this->m_Type = (CUtlSymbolLarge)CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::AddString(
                                    this: &CDmxElement::s_TypeSymbols,
                                    result: (CUtlSymbolLarge *)&pType,
                                    pString: v4)->u.m_Id;
  *((_BYTE *)this + 49) &= 0xFCu;
  this->m_nLockCount = 0;
  CreateUniqueId(pDest: &this->m_Id);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10406520
// Name: public: char const __near * CDmxElement::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CDmxElement::GetName(CDmxElement *this)
{
  CUtlString *v1; // eax

  v1 = (CUtlString *)CDmxElement::GetValue<CUtlString>(this, pAttributeName: "name");
  return CUtlString::operator char const *(this: v1);
}

//------------------------------------------------------------------------------
// Address: 0x10406540
// Name: public: class CDmxAttribute __near * CDmxElement::AddAttribute(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDmxAttribute *__thiscall CDmxElement::AddAttribute(CDmxElement *this, CDmxAttribute *pAttributeName)
{
  const char *v3; // ebx
  int v4; // edi
  unsigned __int8 *v6; // eax
  const char *v7; // edi
  CDmxAttribute v9; // [esp+Ch] [ebp-Ch] BYREF

  CDmxElement::Resort(this);
  v3 = (const char *)pAttributeName;
  CDmxAttribute::CDmxAttribute(this: &v9, (const char *)pAttributeName);
  pAttributeName = &v9;
  v4 = CUtlSortVector<CDmxAttribute *,CDmxAttributeLess>::Find(
         this: &this->m_Attributes,
         src: (CDmxAttribute *const **)&pAttributeName);
  CDmxAttribute::~CDmxAttribute(this: &v9);
  if ( v4 >= 0 )
    return this->m_Attributes.m_Memory.m_pMemory[v4];
  ++this->m_nLockCount;
  *((_BYTE *)this + 49) |= 1u;
  v6 = DMXAlloc(size: 0xCu);
  if ( v6 != nullptr )
    v7 = (const char *)CDmxAttribute::CDmxAttribute(this: (CDmxAttribute *)v6, pAttributeName: v3);
  else
    v7 = nullptr;
  pAttributeName = (CDmxAttribute *)v7;
  CUtlSortVector<CDmxAttribute *,CDmxAttributeLess>::InsertNoSort(this: &this->m_Attributes, src: &pAttributeName);
  if ( this->m_nLockCount-- == 1 )
    CDmxElement::Resort(this);
  return (CDmxAttribute *)v7;
}

//------------------------------------------------------------------------------
// Address: 0x104065E0
// Name: public: void CDmxElement::UnpackIntoStructure(void __near *,struct DmxElementUnpackStructure_t const __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxElement::UnpackIntoStructure(CDmxElement *this, void *pData, CDmxAttribute *pUnpack)
{
  bool v3; // zf
  const char **p_m_Name; // edi
  CUtlString *v5; // ebx
  const char *v6; // eax
  const char *v7; // esi
  int v8; // esi
  CDmxAttribute *p_temp; // esi
  CUtlString *m_pData; // ecx
  const char *v11; // eax
  char *v12; // eax
  const CUtlVector<float,CUtlMemory<float,int> > *v13; // eax
  int v14; // ecx
  int *p_m_nGrowSize; // edx
  DmAttributeType_t v16; // eax
  CDmxAttribute v17; // [esp+4h] [ebp-1Ch] BYREF
  CDmxAttribute temp; // [esp+10h] [ebp-10h] BYREF
  CDmxElement *v19; // [esp+1Ch] [ebp-4h]

  v3 = pUnpack->m_pData == nullptr;
  v19 = this;
  if ( !v3 )
  {
    p_m_Name = (const char **)&pUnpack->m_Name;
    while ( 1 )
    {
      v5 = (CUtlString *)&p_m_Name[2][(_DWORD)pData];
      if ( p_m_Name[8] == nullptr )
        break;
      CDmxElement::UnpackIntoStructure(this: v19, pData: v5, pUnpack: (const DmxElementUnpackStructure_t *)p_m_Name[8]);
LABEL_43:
      p_m_Name += 11;
      if ( p_m_Name[1] == nullptr )
        return;
    }
    v6 = p_m_Name[1];
    if ( (unsigned int)(v6 - 15) <= 0xD && (v6 == (const char *)19 || p_m_Name[4] != (const char *)-1)
      || v6 == (const char *)6
      || v6 == (const char *)20 )
    {
      goto LABEL_43;
    }
    CDmxAttribute::CDmxAttribute(this: &temp, pAttributeName: nullptr);
    v7 = *(p_m_Name - 1);
    CDmxElement::Resort(this: v19);
    CDmxAttribute::CDmxAttribute(this: &v17, pAttributeName: v7);
    pUnpack = &v17;
    v8 = CUtlSortVector<CDmxAttribute *,CDmxAttributeLess>::Find(
           this: &v19->m_Attributes,
           src: (CDmxAttribute *const **)&pUnpack);
    CDmxAttribute::~CDmxAttribute(this: &v17);
    if ( v8 < 0 || (p_temp = v19->m_Attributes.m_Memory.m_pMemory[v8]) == nullptr )
    {
      if ( *p_m_Name == nullptr )
      {
LABEL_42:
        CDmxAttribute::~CDmxAttribute(this: &temp);
        goto LABEL_43;
      }
      CDmxAttribute::AllocateDataMemory_AndConstruct(this: &temp, type: (DmAttributeType_t)p_m_Name[1]);
      if ( (unsigned int)(p_m_Name[1] - 15) > 0xD )
        CDmxAttribute::SetValueFromString(this: &temp, pValue: *p_m_Name);
      p_temp = &temp;
    }
    if ( p_m_Name[1] == (const char *)p_temp->m_Type )
    {
      if ( p_temp->m_Type == AT_STRING )
      {
        m_pData = (CUtlString *)p_temp->m_pData;
        if ( p_m_Name[3] == (const char *)-1 )
        {
          v11 = CUtlString::operator char const *(this: m_pData);
          CUtlString::operator=(this: v5, src: v11);
        }
        else
        {
          v12 = (char *)CUtlString::operator char const *(this: m_pData);
          V_strncpy(pDest: (char *)v5, pSrc: v12, maxLen: (int)p_m_Name[3]);
        }
      }
      else if ( CDmxAttribute::ArrayAttributeBasicType(type: p_temp->m_Type) == AT_FLOAT
             && p_m_Name[3] == (const char *)16 )
      {
        if ( (unsigned int)(p_m_Name[1] - 15) > 0xD )
        {
          v5->m_Storage.m_Memory.m_pMemory = *(unsigned __int8 **)p_temp->m_pData;
          v5->m_Storage.m_Memory.m_nAllocationCount = *(_DWORD *)p_temp->m_pData;
          v5->m_Storage.m_Memory.m_nGrowSize = *(_DWORD *)p_temp->m_pData;
          v5->m_Storage.m_nActualLength = *(_DWORD *)p_temp->m_pData;
        }
        else
        {
          v13 = CDmxAttribute::GetArray<float>(this: p_temp);
          v14 = 0;
          if ( (int)p_m_Name[9] > 0 )
          {
            p_m_nGrowSize = &v5->m_Storage.m_Memory.m_nGrowSize;
            do
            {
              *(p_m_nGrowSize - 2) = LODWORD(v13->m_Memory.m_pMemory[v14]);
              *(p_m_nGrowSize - 1) = LODWORD(v13->m_Memory.m_pMemory[v14]);
              *p_m_nGrowSize = LODWORD(v13->m_Memory.m_pMemory[v14]);
              p_m_nGrowSize[1] = LODWORD(v13->m_Memory.m_pMemory[v14++]);
              p_m_nGrowSize += 4;
            }
            while ( v14 < (int)p_m_Name[9] );
          }
        }
      }
      else
      {
        v16 = (DmAttributeType_t)p_m_Name[1];
        if ( (unsigned int)(v16 - 15) > 0xD )
        {
          if ( p_m_Name[4] == (const char *)-1 )
          {
            memcpy(
              dst: (unsigned __int8 *)v5,
              src: (unsigned __int8 *)p_temp->m_pData,
              count: (unsigned int)p_m_Name[3]);
          }
          else if ( p_temp->m_Type == AT_INT )
          {
            switch ( (unsigned int)p_m_Name[5] )
            {
              case 1u:
              case 3u:
                CDmxElement::UnpackBitfield<unsigned char>(
                  this: v19,
                  pDest: (unsigned __int8 *)v5,
                  pUnpack: (const DmxElementUnpackStructure_t *)(p_m_Name - 1),
                  pAttribute: p_temp);
                break;
              case 2u:
                goto $LN12_54;
              case 4u:
                CDmxElement::UnpackBitfield<short>(
                  this: v19,
                  pDest: (__int16 *)v5,
                  pUnpack: (const DmxElementUnpackStructure_t *)(p_m_Name - 1),
                  pAttribute: p_temp);
                break;
              case 5u:
                CDmxElement::UnpackBitfield<unsigned short>(
                  this: v19,
                  pDest: (unsigned __int16 *)v5,
                  pUnpack: (const DmxElementUnpackStructure_t *)(p_m_Name - 1),
                  pAttribute: p_temp);
                break;
              case 6u:
                CDmxElement::UnpackBitfield<int>(
                  this: v19,
                  pDest: (int *)v5,
                  pUnpack: (const DmxElementUnpackStructure_t *)(p_m_Name - 1),
                  pAttribute: p_temp);
                break;
              case 7u:
                CDmxElement::UnpackBitfield<unsigned int>(
                  this: v19,
                  pDest: (unsigned int *)v5,
                  pUnpack: (const DmxElementUnpackStructure_t *)(p_m_Name - 1),
                  pAttribute: p_temp);
                break;
              default:
                goto LABEL_42;
            }
          }
          else
          {
$LN12_54:
            CDmxElement::UnpackBitfield<char>(
              this: v19,
              pDest: (char *)v5,
              pUnpack: (const DmxElementUnpackStructure_t *)(p_m_Name - 1),
              pAttribute: p_temp);
          }
        }
        else
        {
          CDmxAttribute::GetArrayValue(
            this: p_temp,
            type: v16,
            pDest: v5,
            nDataTypeSize: (int)p_m_Name[3],
            nDestArrayLength: (int)p_m_Name[9],
            pDefaultString: *p_m_Name);
        }
      }
    }
    else
    {
      _Warning(
        a1: "CDmxElement::UnpackIntoStructure: Mismatched attribute type in attribute \"%s\"!\n",
        *(p_m_Name - 1));
    }
    goto LABEL_42;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10406890
// Name: private: void CDmxElement::RemoveAllElementsRecursive(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxElement::RemoveAllElementsRecursive(CDmxElement *this)
{
  int v1; // edi
  int v2; // ecx
  CDmxElement **m_pMemory; // eax
  CDmxElement *v4; // esi
  int m_Size; // ebx
  CDmxAttribute *v6; // ecx
  bool v8; // sf
  CDmxAttribute **v9; // eax
  CUtlVector<CDmxElement *,CUtlMemory<CDmxElement *,int> > elementsToDelete; // [esp+4h] [ebp-1Ch] BYREF
  int nCount; // [esp+18h] [ebp-8h]
  int i; // [esp+1Ch] [ebp-4h]

  v1 = 0;
  memset(&elementsToDelete, 0, sizeof(elementsToDelete));
  CDmxElement::AddElementsToDelete(this, (CUtlMemory<vgui::TreeNode *,int> *)&elementsToDelete);
  v2 = 0;
  nCount = elementsToDelete.m_Size;
  m_pMemory = elementsToDelete.m_Memory.m_pMemory;
  for ( i = 0; v2 < nCount; i = v2 )
  {
    v4 = m_pMemory[v2];
    if ( v4 != nullptr )
    {
      ++v4->m_nLockCount;
      m_Size = v4->m_Attributes.m_Size;
      if ( m_Size > 0 )
      {
        do
        {
          v6 = v4->m_Attributes.m_Memory.m_pMemory[v1];
          if ( v6 != nullptr )
            CDmxAttribute::~CDmxAttribute(this: v6);
          ++v1;
        }
        while ( v1 < m_Size );
      }
      *((_BYTE *)v4 + 49) &= ~1u;
      v4->m_Attributes.m_Size = 0;
      if ( v4->m_nLockCount-- == 1 )
        CDmxElement::Resort(this: v4);
      v8 = v4->m_Attributes.m_Memory.m_nGrowSize < 0;
      v4->m_Attributes.m_Size = 0;
      if ( !v8 )
      {
        if ( v4->m_Attributes.m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v4->m_Attributes.m_Memory.m_pMemory);
          v4->m_Attributes.m_Memory.m_pMemory = nullptr;
        }
        v4->m_Attributes.m_Memory.m_nAllocationCount = 0;
      }
      v8 = v4->m_Attributes.m_Memory.m_nGrowSize < 0;
      v9 = v4->m_Attributes.m_Memory.m_pMemory;
      v4->m_Attributes.m_pElements = v4->m_Attributes.m_Memory.m_pMemory;
      if ( !v8 )
      {
        if ( v9 != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v9);
          v4->m_Attributes.m_Memory.m_pMemory = nullptr;
        }
        v4->m_Attributes.m_Memory.m_nAllocationCount = 0;
      }
      m_pMemory = elementsToDelete.m_Memory.m_pMemory;
      v1 = 0;
    }
    v2 = i + 1;
  }
  elementsToDelete.m_Size = 0;
  if ( elementsToDelete.m_Memory.m_nGrowSize >= 0 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      m_pMemory = nullptr;
      elementsToDelete.m_Memory.m_pMemory = nullptr;
    }
    elementsToDelete.m_Memory.m_nAllocationCount = 0;
  }
  elementsToDelete.m_pElements = m_pMemory;
  if ( elementsToDelete.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x10407C20
// Name: public: class CUtlSymbolLarge CUtlSymbolTableLargeBase<class CNonThreadsafeTree<0>,0>::Find(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
CUtlSymbolLarge *__thiscall CUtlSymbolTableLargeBase<CNonThreadsafeTree<0>,0>::Find(
        CUtlSymbolTableLargeBase<CNonThreadsafeTree<0>,0> *this,
        CUtlSymbolLarge *result,
        char *pString)
{
  char *v3; // ebx
  unsigned int v5; // eax
  unsigned int v6; // esi
  void *v7; // esp
  CUtlRBTree<CUtlSymbolTableLargeBaseTreeEntry_t *,int,CTreeEntryLess<CNonThreadsafeTree<0>,0>,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int>,int> > *v8; // esi
  int v9; // eax
  CUtlSymbolTableLargeBaseTreeEntry_t *m_Data; // ecx
  int v11; // [esp+0h] [ebp-10h] BYREF
  unsigned __int8 v12[8]; // [esp+4h] [ebp-Ch] BYREF
  CUtlRBTree<CUtlSymbolTableLargeBaseTreeEntry_t *,int,CTreeEntryLess<CNonThreadsafeTree<0>,0>,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int>,int> > *p_m_Lookup; // [esp+Ch] [ebp-4h]

  v3 = pString;
  p_m_Lookup = &this->m_Lookup;
  if ( pString == nullptr )
    goto LABEL_2;
  v5 = _V_strlen(str: pString);
  v6 = v5 + 1;
  v7 = alloca(v5 + 5);
  v11 = HashString(pszKey: v3);
  _V_memcpy(dest: v12, src: (unsigned __int8 *)v3, count: v6);
  v8 = p_m_Lookup;
  pString = (char *)&v11;
  v9 = CUtlRBTree<CUtlSymbolTableLargeBaseTreeEntry_t *,int,CTreeEntryLess<CNonThreadsafeTree<0>,0>,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int>,int>>::Find(
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
// Address: 0x10407CB0
// Name: public: void CUtlSymbolTableLargeBase<class CNonThreadsafeTree<0>,0>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlSymbolTableLargeBase<CNonThreadsafeTree<0>,0>::RemoveAll(
        CUtlSymbolTableLargeBase<CNonThreadsafeTree<0>,0> *this)
{
  int i; // edi

  CUtlRBTree<CUtlSymbolTableLargeBaseTreeEntry_t *,int,CTreeEntryLess<CNonThreadsafeTree<0>,0>,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int>,int>>::RemoveAll(this: &this->m_Lookup);
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
    C_BaseEntity::operator delete(pMem: this->m_StringPools.m_Memory.m_pMemory[i]);
  this->m_StringPools.m_Size = 0;
}

//------------------------------------------------------------------------------
// Address: 0x104085C0
// Name: public: class CUtlSymbolLarge CUtlSymbolTableLargeBase<class CNonThreadsafeTree<0>,0>::AddString(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CUtlSymbolLarge *__thiscall CUtlSymbolTableLargeBase<CNonThreadsafeTree<0>,0>::AddString(
        CUtlSymbolTableLargeBase<CNonThreadsafeTree<0>,0> *this,
        CUtlSymbolLarge *result,
        char *pString)
{
  void *m_String; // ecx
  unsigned int v6; // eax
  signed int v7; // edi
  CUtlSymbolTableLargeBase<CNonThreadsafeTree<0>,0>::StringPool_t *v8; // eax
  CUtlVector<CUtlSymbolTableLargeBase<CNonThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CNonThreadsafeTree<0>,0>::StringPool_t *,int> > *p_m_StringPools; // esi
  unsigned int v10; // esi
  CUtlSymbolTableLargeBase<CNonThreadsafeTree<0>,0>::StringPool_t *v11; // edx
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CUtlSymbolTableLargeBase<CNonThreadsafeTree<0>,0>::StringPool_t **m_pMemory; // ecx
  int v15; // eax
  CUtlSymbolTableLargeBase<CNonThreadsafeTree<0>,0>::StringPool_t **v16; // eax
  int v17; // eax
  CUtlSymbolTableLargeBase<CNonThreadsafeTree<0>,0>::StringPool_t *v18; // ecx
  int m_SpaceUsed; // edx
  CUtlSymbolTableLargeBaseTreeEntry_t *v20; // esi
  unsigned int lenString; // [esp+8h] [ebp-Ch]
  int lenDecorated; // [esp+Ch] [ebp-8h]
  CUtlSymbolTableLargeBase<CNonThreadsafeTree<0>,0>::StringPool_t *pPool; // [esp+10h] [ebp-4h] BYREF

  if ( pString != nullptr )
  {
    CUtlSymbolTableLargeBase<CNonThreadsafeTree<0>,0>::Find(this, result: (CUtlSymbolLarge *)&pPool, pString);
    m_String = pPool;
    if ( pPool == (CUtlSymbolTableLargeBase<CNonThreadsafeTree<0>,0>::StringPool_t *)-1 )
    {
      v6 = _V_strlen(str: pString);
      lenString = v6 + 1;
      v7 = (v6 + 8) & 0xFFFFFFFC;
      v8 = nullptr;
      lenDecorated = v7;
      if ( this->m_StringPools.m_Size <= 0 )
        goto LABEL_10;
      p_m_StringPools = &this->m_StringPools;
      pPool = (CUtlSymbolTableLargeBase<CNonThreadsafeTree<0>,0>::StringPool_t *)this->m_StringPools.m_Memory.m_pMemory;
      while ( *(_DWORD *)pPool->m_TotalLen - *(_DWORD *)(pPool->m_TotalLen + 4) < v7 )
      {
        pPool = (CUtlSymbolTableLargeBase<CNonThreadsafeTree<0>,0>::StringPool_t *)((char *)pPool + 4);
        v8 = (CUtlSymbolTableLargeBase<CNonThreadsafeTree<0>,0>::StringPool_t *)((char *)v8 + 1);
        if ( (int)v8 >= this->m_StringPools.m_Size )
          goto LABEL_10;
      }
      pPool = v8;
      if ( v8 == (CUtlSymbolTableLargeBase<CNonThreadsafeTree<0>,0>::StringPool_t *)-1 )
      {
LABEL_10:
        v10 = v7 + 12;
        if ( (unsigned int)(v7 + 12) <= 0x800 )
          v10 = 2048;
        v11 = (CUtlSymbolTableLargeBase<CNonThreadsafeTree<0>,0>::StringPool_t *)MemAlloc_Alloc(nSize: v10);
        v11->m_TotalLen = v10 - 12;
        p_m_StringPools = &this->m_StringPools;
        v11->m_SpaceUsed = 0;
        m_Size = this->m_StringPools.m_Size;
        m_nAllocationCount = this->m_StringPools.m_Memory.m_nAllocationCount;
        pPool = v11;
        if ( m_Size + 1 > m_nAllocationCount )
        {
          CUtlMemory<CChoreoActor *,int>::Grow(
            this: (CUtlMemory<vgui::TreeNode *,int> *)&this->m_StringPools,
            num: m_Size - m_nAllocationCount + 1);
          v11 = pPool;
        }
        ++this->m_StringPools.m_Size;
        m_pMemory = p_m_StringPools->m_Memory.m_pMemory;
        v15 = this->m_StringPools.m_Size - m_Size - 1;
        this->m_StringPools.m_pElements = this->m_StringPools.m_Memory.m_pMemory;
        if ( v15 > 0 )
        {
          _V_memmove(
            dest: (unsigned __int8 *)&m_pMemory[m_Size + 1],
            src: (unsigned __int8 *)&m_pMemory[m_Size],
            count: 4 * v15);
          v11 = pPool;
        }
        v16 = &p_m_StringPools->m_Memory.m_pMemory[m_Size];
        if ( v16 != nullptr )
          *v16 = v11;
        pPool = (CUtlSymbolTableLargeBase<CNonThreadsafeTree<0>,0>::StringPool_t *)m_Size;
        v7 = lenDecorated;
      }
      v17 = HashString(pszKey: pString);
      v18 = p_m_StringPools->m_Memory.m_pMemory[(_DWORD)pPool];
      m_SpaceUsed = v18->m_SpaceUsed;
      v20 = (CUtlSymbolTableLargeBaseTreeEntry_t *)&v18->m_Data[m_SpaceUsed];
      v18->m_SpaceUsed = v7 + m_SpaceUsed;
      v20->m_Hash = v17;
      _V_memcpy(dest: (unsigned __int8 *)&v18[1] + m_SpaceUsed, src: (unsigned __int8 *)pString, count: lenString);
      m_String = this->m_Lookup.m_Elements.m_pMemory[CNonThreadsafeTree<0>::Insert(this: &this->m_Lookup, entry: v20)].m_Data->m_String;
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
// Address: 0x1042F540
// Name: _dynamic_initializer_for__CDmxElement::s_TypeSymbols__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmxElement::s_TypeSymbols__()
{
  CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>(this: &CDmxElement::s_TypeSymbols);
  return atexit(func: dynamic_atexit_destructor_for__CDmxElement::s_TypeSymbols__);
}

//------------------------------------------------------------------------------
// Address: 0x10437470
// Name: _dynamic_atexit_destructor_for__CDmxElement::s_TypeSymbols__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmxElement::s_TypeSymbols__()
{
  CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::RemoveAll(this: &CDmxElement::s_TypeSymbols);
  CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>::~CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&CDmxElement::s_TypeSymbols.m_StringPools);
  CUtlTSHash<CUtlSymbolTableLargeBaseTreeEntry_t *,2048,CUtlSymbolTableLargeBaseTreeEntry_t *,CCThreadsafeTreeHashMethod<2048,CUtlSymbolTableLargeBaseTreeEntry_t *,0>,0>::RemoveAll(this: &CDmxElement::s_TypeSymbols.m_Lookup);
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmxElement::s_TypeSymbols.m_Lookup.m_EntryMemory);
}

//------------------------------------------------------------------------------
// Address: 0x1042F560
// Name: _dynamic_initializer_for__s_DMXAllocator__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_DMXAllocator__()
{
  CMemoryStack::CMemoryStack(this: &s_DMXAllocator);
  return atexit(func: dynamic_atexit_destructor_for__s_DMXAllocator__);
}

//------------------------------------------------------------------------------
// Address: 0x104374A0
// Name: _dynamic_atexit_destructor_for__s_DMXAllocator__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_DMXAllocator__()
{
  CMemoryStack::~CMemoryStack(this: &s_DMXAllocator);
}

} // namespace client

// ============================================================
// Overlay from server (Missing functions)
// ============================================================
namespace server {

//------------------------------------------------------------------------------
// Address: 0x103F3BB0
// Name: public: class CUtlSymbolLarge CUtlSymbolTableLargeBase<class CNonThreadsafeTree<0>,0>::Find(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
CUtlSymbolLarge *__thiscall CUtlSymbolTableLargeBase<CNonThreadsafeTree<0>,0>::Find(
        CUtlSymbolTableLargeBase<CNonThreadsafeTree<0>,0> *this,
        CUtlSymbolLarge *result,
        char *pString)
{
  char *v3; // ebx
  unsigned int v5; // eax
  unsigned int v6; // esi
  void *v7; // esp
  CUtlRBTree<CUtlSymbolTableLargeBaseTreeEntry_t *,int,CTreeEntryLess<CNonThreadsafeTree<0>,0>,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int>,int> > *v8; // esi
  int v9; // eax
  CUtlSymbolTableLargeBaseTreeEntry_t *m_Data; // ecx
  int v11; // [esp+0h] [ebp-10h] BYREF
  unsigned __int8 v12[8]; // [esp+4h] [ebp-Ch] BYREF
  CUtlRBTree<CUtlSymbolTableLargeBaseTreeEntry_t *,int,CTreeEntryLess<CNonThreadsafeTree<0>,0>,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int>,int> > *p_m_Lookup; // [esp+Ch] [ebp-4h]

  v3 = pString;
  p_m_Lookup = &this->m_Lookup;
  if ( pString == nullptr )
    goto LABEL_2;
  v5 = _V_strlen(str: pString);
  v6 = v5 + 1;
  v7 = alloca(v5 + 5);
  v11 = HashString(pszKey: v3);
  _V_memcpy(dest: v12, src: (unsigned __int8 *)v3, count: v6);
  v8 = p_m_Lookup;
  pString = (char *)&v11;
  v9 = CUtlRBTree<CUtlSymbolTableLargeBaseTreeEntry_t *,int,CTreeEntryLess<CNonThreadsafeTree<0>,0>,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int>,int>>::Find(
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
// Address: 0x103F3C40
// Name: public: void CUtlSymbolTableLargeBase<class CNonThreadsafeTree<0>,0>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlSymbolTableLargeBase<CNonThreadsafeTree<0>,0>::RemoveAll(
        CUtlSymbolTableLargeBase<CNonThreadsafeTree<0>,0> *this)
{
  int i; // edi

  CUtlRBTree<CUtlSymbolTableLargeBaseTreeEntry_t *,int,CTreeEntryLess<CNonThreadsafeTree<0>,0>,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int>,int>>::RemoveAll(this: &this->m_Lookup);
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
// Address: 0x103F43E0
// Name: public: class CUtlSymbolLarge CUtlSymbolTableLargeBase<class CNonThreadsafeTree<0>,0>::AddString(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CUtlSymbolLarge *__thiscall CUtlSymbolTableLargeBase<CNonThreadsafeTree<0>,0>::AddString(
        CUtlSymbolTableLargeBase<CNonThreadsafeTree<0>,0> *this,
        CUtlSymbolLarge *result,
        char *pString)
{
  void *m_String; // ecx
  unsigned int v6; // eax
  const char *v7; // edi
  CUtlSymbolTableLargeBase<CNonThreadsafeTree<0>,0>::StringPool_t *v8; // eax
  CUtlVector<CUtlSymbolTableLargeBase<CNonThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CNonThreadsafeTree<0>,0>::StringPool_t *,int> > *p_m_StringPools; // esi
  unsigned int v10; // esi
  CUtlSymbolTableLargeBase<CNonThreadsafeTree<0>,0>::StringPool_t *v11; // edx
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CUtlSymbolTableLargeBase<CNonThreadsafeTree<0>,0>::StringPool_t **m_pMemory; // ecx
  int v15; // eax
  CUtlSymbolTableLargeBase<CNonThreadsafeTree<0>,0>::StringPool_t **v16; // eax
  int v17; // eax
  CUtlSymbolTableLargeBase<CNonThreadsafeTree<0>,0>::StringPool_t *v18; // ecx
  int m_SpaceUsed; // edx
  CUtlSymbolTableLargeBaseTreeEntry_t *v20; // esi
  unsigned int lenString; // [esp+8h] [ebp-Ch]
  int lenDecorated; // [esp+Ch] [ebp-8h]
  CUtlSymbolTableLargeBase<CNonThreadsafeTree<0>,0>::StringPool_t *pPool; // [esp+10h] [ebp-4h] BYREF

  if ( pString != nullptr )
  {
    CUtlSymbolTableLargeBase<CNonThreadsafeTree<0>,0>::Find(this, result: (CUtlSymbolLarge *)&pPool, pString);
    m_String = pPool;
    if ( pPool == (CUtlSymbolTableLargeBase<CNonThreadsafeTree<0>,0>::StringPool_t *)-1 )
    {
      v6 = _V_strlen(str: pString);
      lenString = v6 + 1;
      v7 = (const char *)((v6 + 8) & 0xFFFFFFFC);
      v8 = nullptr;
      lenDecorated = (int)v7;
      if ( this->m_StringPools.m_Size <= 0 )
        goto LABEL_10;
      p_m_StringPools = &this->m_StringPools;
      pPool = (CUtlSymbolTableLargeBase<CNonThreadsafeTree<0>,0>::StringPool_t *)this->m_StringPools.m_Memory.m_pMemory;
      while ( *(_DWORD *)pPool->m_TotalLen - *(_DWORD *)(pPool->m_TotalLen + 4) < (int)v7 )
      {
        pPool = (CUtlSymbolTableLargeBase<CNonThreadsafeTree<0>,0>::StringPool_t *)((char *)pPool + 4);
        v8 = (CUtlSymbolTableLargeBase<CNonThreadsafeTree<0>,0>::StringPool_t *)((char *)v8 + 1);
        if ( (int)v8 >= this->m_StringPools.m_Size )
          goto LABEL_10;
      }
      pPool = v8;
      if ( v8 == (CUtlSymbolTableLargeBase<CNonThreadsafeTree<0>,0>::StringPool_t *)-1 )
      {
LABEL_10:
        v10 = (unsigned int)(v7 + 12);
        if ( (unsigned int)(v7 + 12) <= 0x800 )
          v10 = 2048;
        v11 = (CUtlSymbolTableLargeBase<CNonThreadsafeTree<0>,0>::StringPool_t *)operator new(nSize: v10);
        v11->m_TotalLen = v10 - 12;
        p_m_StringPools = &this->m_StringPools;
        v11->m_SpaceUsed = 0;
        m_Size = this->m_StringPools.m_Size;
        m_nAllocationCount = this->m_StringPools.m_Memory.m_nAllocationCount;
        pPool = v11;
        if ( m_Size + 1 > m_nAllocationCount )
        {
          CUtlMemory<CNavLadder *,int>::Grow(
            this: (CUtlMemory<vgui::TreeNode *,int> *)&this->m_StringPools,
            num: m_Size - m_nAllocationCount + 1);
          v11 = pPool;
        }
        ++this->m_StringPools.m_Size;
        m_pMemory = p_m_StringPools->m_Memory.m_pMemory;
        v15 = this->m_StringPools.m_Size - m_Size - 1;
        this->m_StringPools.m_pElements = this->m_StringPools.m_Memory.m_pMemory;
        if ( v15 > 0 )
        {
          _V_memmove(
            dest: (unsigned __int8 *)&m_pMemory[m_Size + 1],
            src: (unsigned __int8 *)&m_pMemory[m_Size],
            count: 4 * v15);
          v11 = pPool;
        }
        v16 = &p_m_StringPools->m_Memory.m_pMemory[m_Size];
        if ( v16 != nullptr )
          *v16 = v11;
        pPool = (CUtlSymbolTableLargeBase<CNonThreadsafeTree<0>,0>::StringPool_t *)m_Size;
        v7 = (const char *)lenDecorated;
      }
      v17 = HashString(pszKey: pString);
      v18 = p_m_StringPools->m_Memory.m_pMemory[(_DWORD)pPool];
      m_SpaceUsed = v18->m_SpaceUsed;
      v20 = (CUtlSymbolTableLargeBaseTreeEntry_t *)&v18->m_Data[m_SpaceUsed];
      v18->m_SpaceUsed = (int)&v7[m_SpaceUsed];
      v20->m_Hash = v17;
      _V_memcpy(dest: (unsigned __int8 *)&v18[1] + m_SpaceUsed, src: (unsigned __int8 *)pString, count: lenString);
      m_String = this->m_Lookup.m_Elements.m_pMemory[CNonThreadsafeTree<0>::Insert(
                                                       this: &this->m_Lookup,
                                                       a2: v7,
                                                       entry: v20)].m_Data->m_String;
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
// Address: 0x103F4540
// Name: public: char const __near * CDmxElement::GetTypeString(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CDmxElement::GetTypeString(CDmxElement *this)
{
  const char *result; // eax

  result = this->m_Type.u.m_pAsString;
  if ( result == (const char *)-1 )
    return locale;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103F4550
// Name: public: struct UniqueId_t const __near & CDmxElement::GetId(void)const
// Source: json
//------------------------------------------------------------------------------
const UniqueId_t *__thiscall CDmxElement::GetId(CDmxElement *this)
{
  return &this->m_Id;
}

//------------------------------------------------------------------------------
// Address: 0x103F4560
// Name: private: void CDmxElement::SetId(struct UniqueId_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxElement::SetId(CDmxElement *this, const UniqueId_t *id)
{
  CopyUniqueId(src: id, pDest: &this->m_Id);
}

//------------------------------------------------------------------------------
// Address: 0x103F4580
// Name: private: void CDmxElement::UnpackBitfield<unsigned char>(unsigned char __near *,struct DmxElementUnpackStructure_t const __near *,class CDmxAttribute const __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxElement::UnpackBitfield<unsigned char>(
        CDmxElement *this,
        unsigned __int8 *pDest,
        const DmxElementUnpackStructure_t *pUnpack,
        const CDmxAttribute *pAttribute)
{
  int m_nSize; // ecx
  char v6; // bl
  char v7; // al
  unsigned __int8 v8; // al
  char mask_3; // [esp+1Bh] [ebp+Fh]

  m_nSize = pUnpack->m_nSize;
  if ( m_nSize == 8 )
  {
    v6 = -1;
    v7 = -1;
  }
  else
  {
    v6 = (1 << m_nSize) - 1;
    v7 = v6 << pUnpack->m_nBitOffset;
  }
  mask_3 = ~v7;
  v8 = *(_BYTE *)pAttribute->m_pData;
  if ( ((unsigned __int8)~v6 & v8) != 0 )
  {
    _Warning(a1: "Value %s exeeds size of datatype. \n", pUnpack->m_pAttributeName);
    v8 = 0;
  }
  *pDest &= mask_3;
  *pDest |= ((unsigned __int8)v6 & v8) << pUnpack->m_nBitOffset;
}

//------------------------------------------------------------------------------
// Address: 0x103F45F0
// Name: private: void CDmxElement::UnpackBitfield<char>(char __near *,struct DmxElementUnpackStructure_t const __near *,class CDmxAttribute const __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxElement::UnpackBitfield<char>(
        CDmxElement *this,
        char *pDest,
        const DmxElementUnpackStructure_t *pUnpack,
        const CDmxAttribute *pAttribute)
{
  int m_nSize; // edx
  char v6; // bl
  char v7; // al
  char v8; // al
  char v9; // dl
  char mask_3; // [esp+1Bh] [ebp+Fh]

  m_nSize = pUnpack->m_nSize;
  if ( m_nSize == 8 )
  {
    v6 = -1;
    v7 = -1;
  }
  else
  {
    v6 = (1 << m_nSize) - 1;
    v7 = v6 << pUnpack->m_nBitOffset;
  }
  mask_3 = ~v7;
  v8 = *(_BYTE *)pAttribute->m_pData;
  v9 = (1 << (m_nSize - 1)) - 1;
  if ( v8 < 0 )
  {
    if ( (~v9 & v8) != ~v9 )
    {
LABEL_8:
      _Warning(a1: "Value %s exeeds size of datatype. \n", pUnpack->m_pAttributeName);
      v8 = 0;
    }
  }
  else if ( (~v9 & v8) != 0 )
  {
    goto LABEL_8;
  }
  *pDest &= mask_3;
  *pDest |= ((unsigned __int8)v6 & (unsigned __int8)v8) << pUnpack->m_nBitOffset;
}

//------------------------------------------------------------------------------
// Address: 0x103F4680
// Name: private: void CDmxElement::UnpackBitfield<short>(short __near *,struct DmxElementUnpackStructure_t const __near *,class CDmxAttribute const __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxElement::UnpackBitfield<short>(
        CDmxElement *this,
        __int16 *pDest,
        const DmxElementUnpackStructure_t *pUnpack,
        const CDmxAttribute *pAttribute)
{
  int m_nSize; // edx
  __int16 v5; // bx
  __int16 v6; // ax
  __int16 v7; // di
  __int16 v8; // ax
  int v9; // ecx
  bool v10; // zf

  m_nSize = pUnpack->m_nSize;
  if ( m_nSize == 16 )
  {
    v5 = -1;
    v6 = -1;
  }
  else
  {
    v5 = (1 << m_nSize) - 1;
    v6 = v5 << pUnpack->m_nBitOffset;
  }
  v7 = ~v6;
  v8 = *(_WORD *)pAttribute->m_pData;
  v9 = ~(__int16)((1 << (m_nSize - 1)) - 1);
  if ( v8 < 0 )
    v10 = (v9 & v8) == v9;
  else
    v10 = (v9 & v8) == 0;
  if ( !v10 )
  {
    _Warning(a1: "Value %s exeeds size of datatype. \n", pUnpack->m_pAttributeName);
    v8 = 0;
  }
  *pDest &= v7;
  *pDest |= ((unsigned __int16)v5 & (unsigned __int16)v8) << pUnpack->m_nBitOffset;
}

//------------------------------------------------------------------------------
// Address: 0x103F4720
// Name: private: void CDmxElement::UnpackBitfield<unsigned short>(unsigned short __near *,struct DmxElementUnpackStructure_t const __near *,class CDmxAttribute const __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxElement::UnpackBitfield<unsigned short>(
        CDmxElement *this,
        unsigned __int16 *pDest,
        const DmxElementUnpackStructure_t *pUnpack,
        const CDmxAttribute *pAttribute)
{
  int m_nSize; // ecx
  unsigned __int16 v5; // si
  __int16 v6; // ax
  __int16 v7; // bx
  int v8; // ecx

  m_nSize = pUnpack->m_nSize;
  if ( m_nSize == 16 )
  {
    v5 = -1;
    v6 = -1;
  }
  else
  {
    v5 = (1 << m_nSize) - 1;
    v6 = v5 << pUnpack->m_nBitOffset;
  }
  v7 = ~v6;
  v8 = *(unsigned __int16 *)pAttribute->m_pData;
  if ( (~v5 & v8) != 0 )
  {
    _Warning(a1: "Value %s exeeds size of datatype. \n", pUnpack->m_pAttributeName);
    LOWORD(v8) = 0;
  }
  *pDest &= v7;
  *pDest |= (v5 & (unsigned __int16)v8) << pUnpack->m_nBitOffset;
}

//------------------------------------------------------------------------------
// Address: 0x103F47A0
// Name: private: void CDmxElement::UnpackBitfield<int>(int __near *,struct DmxElementUnpackStructure_t const __near *,class CDmxAttribute const __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxElement::UnpackBitfield<int>(
        CDmxElement *this,
        int *pDest,
        const DmxElementUnpackStructure_t *pUnpack,
        const CDmxAttribute *pAttribute)
{
  int m_nSize; // edx
  int v5; // esi
  int v6; // eax
  int v7; // ebx
  int v8; // eax
  int v9; // edx
  bool v10; // zf

  m_nSize = pUnpack->m_nSize;
  if ( m_nSize == 32 )
  {
    v5 = -1;
    v6 = -1;
  }
  else
  {
    v5 = (1 << m_nSize) - 1;
    v6 = v5 << pUnpack->m_nBitOffset;
  }
  v7 = ~v6;
  v8 = *(_DWORD *)pAttribute->m_pData;
  v9 = ~((1 << (m_nSize - 1)) - 1);
  if ( v8 < 0 )
    v10 = (v8 & v9) == v9;
  else
    v10 = (v9 & v8) == 0;
  if ( !v10 )
  {
    _Warning(a1: "Value %s exeeds size of datatype. \n", pUnpack->m_pAttributeName);
    v8 = 0;
  }
  *pDest &= v7;
  *pDest |= (v5 & v8) << pUnpack->m_nBitOffset;
}

//------------------------------------------------------------------------------
// Address: 0x103F4820
// Name: private: void CDmxElement::UnpackBitfield<unsigned int>(unsigned int __near *,struct DmxElementUnpackStructure_t const __near *,class CDmxAttribute const __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxElement::UnpackBitfield<unsigned int>(
        CDmxElement *this,
        unsigned int *pDest,
        const DmxElementUnpackStructure_t *pUnpack,
        const CDmxAttribute *pAttribute)
{
  int m_nSize; // ecx
  int v5; // esi
  int v6; // eax
  int v7; // edi
  int v8; // eax

  m_nSize = pUnpack->m_nSize;
  if ( m_nSize == 32 )
  {
    v5 = -1;
    v6 = -1;
  }
  else
  {
    v5 = (1 << m_nSize) - 1;
    v6 = v5 << pUnpack->m_nBitOffset;
  }
  v7 = ~v6;
  v8 = *(_DWORD *)pAttribute->m_pData;
  if ( (~v5 & v8) != 0 )
  {
    _Warning(a1: "Value %s exeeds size of datatype. \n", pUnpack->m_pAttributeName);
    v8 = 0;
  }
  *pDest &= v7;
  *pDest |= (v5 & v8) << pUnpack->m_nBitOffset;
}

//------------------------------------------------------------------------------
// Address: 0x103F4910
// Name: private: int CUtlTSHash<struct CUtlSymbolTableLargeBaseTreeEntry_t __near *,2048,struct CUtlSymbolTableLargeBaseTreeEntry_t __near *,class CCThreadsafeTreeHashMethod<2048,struct CUtlSymbolTableLargeBaseTreeEntry_t __near *,0>,0>::Find(struct CUtlSymbolTableLargeBaseTreeEntry_t __near *,struct CUtlTSHash<struct CUtlSymbolTableLargeBaseTreeEntry_t __near *,2048,struct CUtlSymbolTableLargeBaseTreeEntry_t __near *,class CCThreadsafeTreeHashMethod<2048,struct CUtlSymbolTableLargeBaseTreeEntry_t __near *,0>,0>::HashFixedDataInternal_t<struct CUtlSymbolTableLargeBaseTreeEntry_t __near *> __near *,struct CUtlTSHash<struct CUtlSymbolTableLargeBaseTreeEntry_t __near *,2048,struct CUtlSymbolTableLargeBaseTreeEntry_t __near *,class CCThreadsafeTreeHashMethod<2048,struct CUtlSymbolTableLargeBaseTreeEntry_t __near *,0>,0>::HashFixedDataInternal_t<struct CUtlSymbolTableLargeBaseTreeEntry_t __near *> __near *)
// Source: json
//------------------------------------------------------------------------------
CUtlTSHash<CUtlSymbolTableLargeBaseTreeEntry_t *,2048,CUtlSymbolTableLargeBaseTreeEntry_t *,CCThreadsafeTreeHashMethod<2048,CUtlSymbolTableLargeBaseTreeEntry_t *,0>,0>::HashFixedDataInternal_t<CUtlSymbolTableLargeBaseTreeEntry_t *> *__thiscall CUtlTSHash<CUtlSymbolTableLargeBaseTreeEntry_t *,2048,CUtlSymbolTableLargeBaseTreeEntry_t *,CCThreadsafeTreeHashMethod<2048,CUtlSymbolTableLargeBaseTreeEntry_t *,0>,0>::Find(
        CUtlTSHash<CUtlSymbolTableLargeBaseTreeEntry_t *,2048,CUtlSymbolTableLargeBaseTreeEntry_t *,CCThreadsafeTreeHashMethod<2048,CUtlSymbolTableLargeBaseTreeEntry_t *,0>,0> *this,
        CUtlSymbolTableLargeBaseTreeEntry_t *uiKey,
        CUtlTSHash<CUtlSymbolTableLargeBaseTreeEntry_t *,2048,CUtlSymbolTableLargeBaseTreeEntry_t *,CCThreadsafeTreeHashMethod<2048,CUtlSymbolTableLargeBaseTreeEntry_t *,0>,0>::HashFixedDataInternal_t<CUtlSymbolTableLargeBaseTreeEntry_t *> *pFirstElement,
        CUtlTSHash<CUtlSymbolTableLargeBaseTreeEntry_t *,2048,CUtlSymbolTableLargeBaseTreeEntry_t *,CCThreadsafeTreeHashMethod<2048,CUtlSymbolTableLargeBaseTreeEntry_t *,0>,0>::HashFixedDataInternal_t<CUtlSymbolTableLargeBaseTreeEntry_t *> *pLastElement)
{
  CUtlTSHash<CUtlSymbolTableLargeBaseTreeEntry_t *,2048,CUtlSymbolTableLargeBaseTreeEntry_t *,CCThreadsafeTreeHashMethod<2048,CUtlSymbolTableLargeBaseTreeEntry_t *,0>,0>::HashFixedDataInternal_t<CUtlSymbolTableLargeBaseTreeEntry_t *> *v4; // esi

  v4 = pFirstElement;
  if ( pFirstElement == pLastElement )
    return nullptr;
  while ( v4->m_uiKey->m_Hash != uiKey->m_Hash || _V_strcmp(s1: v4->m_uiKey->m_String, s2: uiKey->m_String) != 0 )
  {
    v4 = v4->m_pNext;
    if ( v4 == pLastElement )
      return nullptr;
  }
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x103F4960
// Name: private: int CUtlTSHash<struct CUtlSymbolTableLargeBaseTreeEntry_t __near *,2048,struct CUtlSymbolTableLargeBaseTreeEntry_t __near *,class CCThreadsafeTreeHashMethod<2048,struct CUtlSymbolTableLargeBaseTreeEntry_t __near *,0>,0>::InsertUncommitted(struct CUtlSymbolTableLargeBaseTreeEntry_t __near *,struct CUtlTSHash<struct CUtlSymbolTableLargeBaseTreeEntry_t __near *,2048,struct CUtlSymbolTableLargeBaseTreeEntry_t __near *,class CCThreadsafeTreeHashMethod<2048,struct CUtlSymbolTableLargeBaseTreeEntry_t __near *,0>,0>::HashBucket_t __near &)
// Source: json
//------------------------------------------------------------------------------
CUtlTSHash<CUtlSymbolTableLargeBaseTreeEntry_t *,2048,CUtlSymbolTableLargeBaseTreeEntry_t *,CCThreadsafeTreeHashMethod<2048,CUtlSymbolTableLargeBaseTreeEntry_t *,0>,0>::HashFixedDataInternal_t<CUtlSymbolTableLargeBaseTreeEntry_t *> *__thiscall CUtlTSHash<CUtlSymbolTableLargeBaseTreeEntry_t *,2048,CUtlSymbolTableLargeBaseTreeEntry_t *,CCThreadsafeTreeHashMethod<2048,CUtlSymbolTableLargeBaseTreeEntry_t *,0>,0>::InsertUncommitted(
        CUtlTSHash<CUtlSymbolTableLargeBaseTreeEntry_t *,2048,CUtlSymbolTableLargeBaseTreeEntry_t *,CCThreadsafeTreeHashMethod<2048,CUtlSymbolTableLargeBaseTreeEntry_t *,0>,0> *this,
        CUtlSymbolTableLargeBaseTreeEntry_t *uiKey,
        CUtlTSHash<CUtlSymbolTableLargeBaseTreeEntry_t *,2048,CUtlSymbolTableLargeBaseTreeEntry_t *,CCThreadsafeTreeHashMethod<2048,CUtlSymbolTableLargeBaseTreeEntry_t *,0>,0>::HashBucket_t *bucket)
{
  CThreadFastMutex *p_m_mutex; // esi
  DWORD CurrentThreadId; // ecx
  CUtlTSHash<CUtlSymbolTableLargeBaseTreeEntry_t *,2048,CUtlSymbolTableLargeBaseTreeEntry_t *,CCThreadsafeTreeHashMethod<2048,CUtlSymbolTableLargeBaseTreeEntry_t *,0>,0>::HashFixedDataInternal_t<CUtlSymbolTableLargeBaseTreeEntry_t *> *result; // eax

  this->m_bNeedsCommit = true;
  p_m_mutex = &this->m_EntryMemory.m_mutex;
  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != p_m_mutex->m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)p_m_mutex, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(a1: p_m_mutex, a2: CurrentThreadId, a3: 0);
  }
  else
  {
    ++p_m_mutex->m_depth;
  }
  result = (CUtlTSHash<CUtlSymbolTableLargeBaseTreeEntry_t *,2048,CUtlSymbolTableLargeBaseTreeEntry_t *,CCThreadsafeTreeHashMethod<2048,CUtlSymbolTableLargeBaseTreeEntry_t *,0>,0>::HashFixedDataInternal_t<CUtlSymbolTableLargeBaseTreeEntry_t *> *)CUtlMemoryPool::Alloc(this: &this->m_EntryMemory);
  if ( p_m_mutex->m_depth-- == 1 )
    _InterlockedExchange((volatile __int32 *)p_m_mutex, 0);
  result->m_pNext = bucket->m_pFirstUncommitted;
  bucket->m_pFirstUncommitted = result;
  result->m_uiKey = uiKey;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103F49D0
// Name: public: void CUtlTSHash<struct CUtlSymbolTableLargeBaseTreeEntry_t __near *,2048,struct CUtlSymbolTableLargeBaseTreeEntry_t __near *,class CCThreadsafeTreeHashMethod<2048,struct CUtlSymbolTableLargeBaseTreeEntry_t __near *,0>,0>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlTSHash<CUtlSymbolTableLargeBaseTreeEntry_t *,2048,CUtlSymbolTableLargeBaseTreeEntry_t *,CCThreadsafeTreeHashMethod<2048,CUtlSymbolTableLargeBaseTreeEntry_t *,0>,0>::RemoveAll(
        CUtlTSHash<CUtlSymbolTableLargeBaseTreeEntry_t *,2048,CUtlSymbolTableLargeBaseTreeEntry_t *,CCThreadsafeTreeHashMethod<2048,CUtlSymbolTableLargeBaseTreeEntry_t *,0>,0> *this)
{
  CThreadSpinRWLock *p_m_AddLock; // esi
  int i; // edi
  unsigned int j; // eax
  CThreadFastMutex *p_m_mutex; // esi
  DWORD CurrentThreadId; // ecx

  this->m_bNeedsCommit = false;
  if ( this->m_EntryMemory.m_BlocksAllocated != 0 )
  {
    p_m_AddLock = &this->m_aBuckets[0].m_AddLock;
    for ( i = 2048; i != 0; --i )
    {
      if ( (p_m_AddLock->m_lockInfo.m_i32 & 0x10000) != 0
        || _InterlockedCompareExchange((volatile signed __int32 *)p_m_AddLock, 0x10000, 0) != 0 )
      {
        CThreadSpinRWLock::SpinLockForWrite(this: p_m_AddLock);
      }
      else
      {
        p_m_AddLock->m_writerId = GetCurrentThreadId();
      }
      for ( j = p_m_AddLock[-1].m_writerId; j != 0; j = *(_DWORD *)(j + 4) )
        ;
      p_m_AddLock[-1].m_lockInfo.m_i32 = 0;
      p_m_AddLock[-1].m_writerId = 0;
      p_m_AddLock->m_writerId = 0;
      p_m_AddLock->m_lockInfo.m_i32 = 0;
      p_m_AddLock += 2;
    }
    p_m_mutex = &this->m_EntryMemory.m_mutex;
    CurrentThreadId = GetCurrentThreadId();
    if ( CurrentThreadId != this->m_EntryMemory.m_mutex.m_ownerID
      && _InterlockedCompareExchange((volatile signed __int32 *)p_m_mutex, CurrentThreadId, 0) != 0 )
    {
      _mm_pause();
      CThreadFastMutex::Lock(a1: p_m_mutex, a2: CurrentThreadId, a3: 0);
    }
    else
    {
      ++this->m_EntryMemory.m_mutex.m_depth;
    }
    CUtlMemoryPool::Clear(this: &this->m_EntryMemory);
    if ( this->m_EntryMemory.m_mutex.m_depth-- == 1 )
      _InterlockedExchange((volatile __int32 *)p_m_mutex, 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103F4BC0
// Name: private: int CUtlSymbolTableLargeBase<class CThreadsafeTree<0>,0>::FindPoolWithSpace(int)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::FindPoolWithSpace(
        CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0> *this,
        int len)
{
  int m_Size; // esi
  int result; // eax
  CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t **i; // edx

  m_Size = this->m_StringPools.m_Size;
  result = 0;
  if ( m_Size <= 0 )
    return -1;
  for ( i = this->m_StringPools.m_Memory.m_pMemory; (*i)->m_TotalLen - (*i)->m_SpaceUsed < len; ++i )
  {
    if ( ++result >= m_Size )
      return -1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103F4C00
// Name: public: int CUtlTSHash<struct CUtlSymbolTableLargeBaseTreeEntry_t __near *,2048,struct CUtlSymbolTableLargeBaseTreeEntry_t __near *,class CCThreadsafeTreeHashMethod<2048,struct CUtlSymbolTableLargeBaseTreeEntry_t __near *,0>,0>::Insert(struct CUtlSymbolTableLargeBaseTreeEntry_t __near *,struct CUtlSymbolTableLargeBaseTreeEntry_t __near * const __near &,bool __near *)
// Source: json
//------------------------------------------------------------------------------
CUtlTSHash<CUtlSymbolTableLargeBaseTreeEntry_t *,2048,CUtlSymbolTableLargeBaseTreeEntry_t *,CCThreadsafeTreeHashMethod<2048,CUtlSymbolTableLargeBaseTreeEntry_t *,0>,0>::HashFixedDataInternal_t<CUtlSymbolTableLargeBaseTreeEntry_t *> *__thiscall CUtlTSHash<CUtlSymbolTableLargeBaseTreeEntry_t *,2048,CUtlSymbolTableLargeBaseTreeEntry_t *,CCThreadsafeTreeHashMethod<2048,CUtlSymbolTableLargeBaseTreeEntry_t *,0>,0>::Insert(
        CUtlTSHash<CUtlSymbolTableLargeBaseTreeEntry_t *,2048,CUtlSymbolTableLargeBaseTreeEntry_t *,CCThreadsafeTreeHashMethod<2048,CUtlSymbolTableLargeBaseTreeEntry_t *,0>,0> *this,
        CUtlSymbolTableLargeBaseTreeEntry_t *uiKey,
        CUtlSymbolTableLargeBaseTreeEntry_t **data,
        bool *pDidInsert)
{
  CUtlTSHash<CUtlSymbolTableLargeBaseTreeEntry_t *,2048,CUtlSymbolTableLargeBaseTreeEntry_t *,CCThreadsafeTreeHashMethod<2048,CUtlSymbolTableLargeBaseTreeEntry_t *,0>,0>::HashBucket_t *v5; // esi
  CUtlTSHash<CUtlSymbolTableLargeBaseTreeEntry_t *,2048,CUtlSymbolTableLargeBaseTreeEntry_t *,CCThreadsafeTreeHashMethod<2048,CUtlSymbolTableLargeBaseTreeEntry_t *,0>,0>::HashFixedDataInternal_t<CUtlSymbolTableLargeBaseTreeEntry_t *> *result; // eax
  CThreadSpinRWLock *p_m_AddLock; // ecx

  if ( pDidInsert != nullptr )
    *pDidInsert = false;
  v5 = &this->m_aBuckets[uiKey->m_Hash & 0x7FF];
  result = CUtlTSHash<CUtlSymbolTableLargeBaseTreeEntry_t *,2048,CUtlSymbolTableLargeBaseTreeEntry_t *,CCThreadsafeTreeHashMethod<2048,CUtlSymbolTableLargeBaseTreeEntry_t *,0>,0>::Find(
             this,
             uiKey,
             pFirstElement: v5->m_pFirst,
             pLastElement: nullptr);
  if ( result == nullptr )
  {
    CThreadSpinRWLock::LockForRead(this: &v5->m_AddLock);
    result = CUtlTSHash<CUtlSymbolTableLargeBaseTreeEntry_t *,2048,CUtlSymbolTableLargeBaseTreeEntry_t *,CCThreadsafeTreeHashMethod<2048,CUtlSymbolTableLargeBaseTreeEntry_t *,0>,0>::Find(
               this,
               uiKey,
               pFirstElement: v5->m_pFirstUncommitted,
               pLastElement: v5->m_pFirst);
    _InterlockedExchangeAdd((volatile signed __int32 *)&v5->m_AddLock, 0xFFFFFFFF);
    if ( result == nullptr )
    {
      p_m_AddLock = &v5->m_AddLock;
      if ( (v5->m_AddLock.m_lockInfo.m_i32 & 0x10000) != 0
        || _InterlockedCompareExchange((volatile signed __int32 *)p_m_AddLock, 0x10000, 0) != 0 )
      {
        CThreadSpinRWLock::SpinLockForWrite(this: p_m_AddLock);
      }
      else
      {
        v5->m_AddLock.m_writerId = GetCurrentThreadId();
      }
      result = CUtlTSHash<CUtlSymbolTableLargeBaseTreeEntry_t *,2048,CUtlSymbolTableLargeBaseTreeEntry_t *,CCThreadsafeTreeHashMethod<2048,CUtlSymbolTableLargeBaseTreeEntry_t *,0>,0>::Find(
                 this,
                 uiKey,
                 pFirstElement: v5->m_pFirstUncommitted,
                 pLastElement: v5->m_pFirst);
      if ( result == nullptr )
      {
        result = CUtlTSHash<CUtlSymbolTableLargeBaseTreeEntry_t *,2048,CUtlSymbolTableLargeBaseTreeEntry_t *,CCThreadsafeTreeHashMethod<2048,CUtlSymbolTableLargeBaseTreeEntry_t *,0>,0>::InsertUncommitted(
                   this,
                   uiKey,
                   bucket: v5);
        if ( result != (CUtlTSHash<CUtlSymbolTableLargeBaseTreeEntry_t *,2048,CUtlSymbolTableLargeBaseTreeEntry_t *,CCThreadsafeTreeHashMethod<2048,CUtlSymbolTableLargeBaseTreeEntry_t *,0>,0>::HashFixedDataInternal_t<CUtlSymbolTableLargeBaseTreeEntry_t *> *)-8 )
          result->m_Data = *data;
        if ( pDidInsert != nullptr )
          *pDidInsert = true;
      }
      v5->m_AddLock.m_writerId = 0;
      v5->m_AddLock.m_lockInfo.m_i32 = 0;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103F4D50
// Name: public: class CUtlSymbolLarge CUtlSymbolTableLargeBase<class CThreadsafeTree<0>,0>::Find(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
CUtlSymbolLarge *__thiscall CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::Find(
        CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0> *this,
        CUtlSymbolLarge *result,
        char *pString)
{
  unsigned int v5; // eax
  unsigned int v6; // edi
  void *v7; // esp
  CUtlTSHash<CUtlSymbolTableLargeBaseTreeEntry_t *,2048,CUtlSymbolTableLargeBaseTreeEntry_t *,CCThreadsafeTreeHashMethod<2048,CUtlSymbolTableLargeBaseTreeEntry_t *,0>,0>::HashBucket_t *v8; // edi
  CUtlTSHash<CUtlSymbolTableLargeBaseTreeEntry_t *,2048,CUtlSymbolTableLargeBaseTreeEntry_t *,CCThreadsafeTreeHashMethod<2048,CUtlSymbolTableLargeBaseTreeEntry_t *,0>,0>::HashFixedDataInternal_t<CUtlSymbolTableLargeBaseTreeEntry_t *> *v9; // eax
  CUtlSymbolTableLargeBaseTreeEntry_t v10; // [esp+0h] [ebp-Ch] BYREF

  if ( pString == nullptr )
    goto LABEL_2;
  v5 = _V_strlen(str: pString);
  v6 = v5 + 1;
  v7 = alloca(v5 + 5);
  v10.m_Hash = HashString(pszKey: pString);
  _V_memcpy(dest: (unsigned __int8 *)v10.m_String, src: (unsigned __int8 *)pString, count: v6);
  v8 = &this->m_Lookup.m_aBuckets[v10.m_Hash & 0x7FF];
  v9 = CUtlTSHash<CUtlSymbolTableLargeBaseTreeEntry_t *,2048,CUtlSymbolTableLargeBaseTreeEntry_t *,CCThreadsafeTreeHashMethod<2048,CUtlSymbolTableLargeBaseTreeEntry_t *,0>,0>::Find(
         this: &this->m_Lookup,
         uiKey: &v10,
         pFirstElement: v8->m_pFirst,
         pLastElement: nullptr);
  if ( v9 != nullptr
    || (CThreadSpinRWLock::LockForRead(this: &v8->m_AddLock),
        v9 = CUtlTSHash<CUtlSymbolTableLargeBaseTreeEntry_t *,2048,CUtlSymbolTableLargeBaseTreeEntry_t *,CCThreadsafeTreeHashMethod<2048,CUtlSymbolTableLargeBaseTreeEntry_t *,0>,0>::Find(
               this: &this->m_Lookup,
               uiKey: &v10,
               pFirstElement: v8->m_pFirstUncommitted,
               pLastElement: v8->m_pFirst),
        _InterlockedExchangeAdd((volatile signed __int32 *)&v8->m_AddLock, 0xFFFFFFFF),
        v9 != nullptr) )
  {
    result->u.m_Id = (int)v9->m_Data->m_String;
    return result;
  }
  else
  {
LABEL_2:
    result->u.m_Id = -1;
    return result;
  }
}

//------------------------------------------------------------------------------
// Address: 0x103F4E10
// Name: public: void CUtlSymbolTableLargeBase<class CThreadsafeTree<0>,0>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::RemoveAll(
        CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0> *this)
{
  int v2; // edi

  CUtlTSHash<CUtlSymbolTableLargeBaseTreeEntry_t *,2048,CUtlSymbolTableLargeBaseTreeEntry_t *,CCThreadsafeTreeHashMethod<2048,CUtlSymbolTableLargeBaseTreeEntry_t *,0>,0>::RemoveAll(this: &this->m_Lookup);
  v2 = 0;
  if ( this->m_StringPools.m_Size <= 0 )
  {
    this->m_StringPools.m_Size = 0;
  }
  else
  {
    do
      free(pMem: this->m_StringPools.m_Memory.m_pMemory[v2++]);
    while ( v2 < this->m_StringPools.m_Size );
    this->m_StringPools.m_Size = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x103F4E60
// Name: private: void CDmxElement::Resort(void)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxElement::Resort(CDmxElement *this)
{
  signed int m_Size; // eax
  int i; // edi
  CDmxAttribute **v4; // eax
  const char *Name; // eax
  _DWORD context[2]; // [esp+4h] [ebp-Ch] BYREF
  char v7; // [esp+Fh] [ebp-1h] BYREF

  if ( (*((_BYTE *)this + 49) & 1) != 0 )
  {
    if ( this->m_Attributes.m_bNeedsSort )
    {
      m_Size = this->m_Attributes.m_Size;
      this->m_Attributes.m_bNeedsSort = false;
      if ( m_Size > 1 )
      {
        context[0] = this->m_Attributes.m_pLessContext;
        context[1] = &v7;
        qsort_s(
          base: (char *)this->m_Attributes.m_Memory.m_pMemory,
          num: m_Size,
          width: 4u,
          comp: (int (__cdecl *)(void *, const void *, const void *))CUtlSortVector<CDmxAttribute *,CDmxAttributeLess>::CompareHelper,
          context);
      }
    }
    *((_BYTE *)this + 49) &= ~1u;
    for ( i = this->m_Attributes.m_Size - 1; i >= 1; --i )
    {
      v4 = &this->m_Attributes.m_Memory.m_pMemory[i];
      if ( *v4 != nullptr && *(v4 - 1) != nullptr && (*v4)->m_Name.u.m_Id == (*(v4 - 1))->m_Name.u.m_Id )
      {
        Name = CDmxAttribute::GetName(this: *v4);
        _Warning(a1: "Duplicate attribute name %s encountered!\n", Name);
        if ( this->m_Attributes.m_Size - i - 1 > 0 )
          _V_memmove(
            dest: (unsigned __int8 *)&this->m_Attributes.m_Memory.m_pMemory[i],
            src: (unsigned __int8 *)&this->m_Attributes.m_Memory.m_pMemory[i + 1],
            count: 4 * (this->m_Attributes.m_Size - i - 1));
        --this->m_Attributes.m_Size;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x103F4F30
// Name: public: void CDmxElement::LockForChanges(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxElement::LockForChanges(CDmxElement *this, bool bLock)
{
  if ( bLock )
  {
    ++this->m_nLockCount;
  }
  else if ( this->m_nLockCount-- == 1 )
  {
    CDmxElement::Resort(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103F4F50
// Name: public: bool CDmxElement::HasAttribute(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CDmxElement::HasAttribute(CDmxElement *this, const char *pAttributeName)
{
  int v3; // esi
  CDmxAttribute v5; // [esp+4h] [ebp-Ch] BYREF

  CDmxElement::Resort(this);
  CDmxAttribute::CDmxAttribute(this: &v5, pAttributeName);
  pAttributeName = (const char *)&v5;
  v3 = CUtlSortVector<CDmxAttribute *,CDmxAttributeLess>::Find(
         this: &this->m_Attributes,
         src: (CDmxAttribute *const **)&pAttributeName);
  CDmxAttribute::~CDmxAttribute(this: &v5);
  return v3 >= 0;
}

//------------------------------------------------------------------------------
// Address: 0x103F4FA0
// Name: public: class CDmxAttribute const __near * CDmxElement::GetAttribute(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
const CDmxAttribute *__thiscall CDmxElement::GetAttribute(CDmxElement *this, const char *pAttributeName)
{
  int v3; // edi
  CDmxAttribute v5; // [esp+8h] [ebp-Ch] BYREF

  CDmxElement::Resort(this);
  CDmxAttribute::CDmxAttribute(this: &v5, pAttributeName);
  pAttributeName = (const char *)&v5;
  v3 = CUtlSortVector<CDmxAttribute *,CDmxAttributeLess>::Find(
         this: &this->m_Attributes,
         src: (CDmxAttribute *const **)&pAttributeName);
  CDmxAttribute::~CDmxAttribute(this: &v5);
  if ( v3 < 0 )
    return nullptr;
  else
    return this->m_Attributes.m_Memory.m_pMemory[v3];
}

//------------------------------------------------------------------------------
// Address: 0x103F5000
// Name: private: void CDmxElement::AddElementsToDelete(class CUtlVector<class CDmxElement __near *,class CUtlMemory<class CDmxElement __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxElement::AddElementsToDelete(CDmxElement *this, CUtlMemory<vgui::TreeNode *,int> *elementsToDelete)
{
  CDmxElement *v2; // ebx
  char v3; // al
  int m_pMemory; // esi
  int m_nAllocationCount; // eax
  CDmxElement **v7; // ecx
  int v8; // eax
  CDmxElement **v9; // esi
  int v10; // eax
  CDmxAttribute *v11; // eax
  CDmxElement *v12; // ecx
  _DWORD *m_pData; // ebx
  int v14; // ecx
  int v15; // esi
  int nCount; // [esp+4h] [ebp-Ch]
  int nElementCount; // [esp+8h] [ebp-8h]
  int i; // [esp+18h] [ebp+8h]

  v2 = this;
  v3 = *((_BYTE *)this + 49);
  if ( (v3 & 2) == 0 )
  {
    *((_BYTE *)this + 49) = v3 | 2;
    m_pMemory = (int)elementsToDelete[1].m_pMemory;
    m_nAllocationCount = elementsToDelete->m_nAllocationCount;
    if ( m_pMemory + 1 > m_nAllocationCount )
      CUtlMemory<CNavLadder *,int>::Grow(this: elementsToDelete, num: m_pMemory - m_nAllocationCount + 1);
    ++elementsToDelete[1].m_pMemory;
    v7 = (CDmxElement **)elementsToDelete->m_pMemory;
    v8 = (int)elementsToDelete[1].m_pMemory - m_pMemory - 1;
    elementsToDelete[1].m_nAllocationCount = (int)elementsToDelete->m_pMemory;
    if ( v8 > 0 )
      _V_memmove(dest: (unsigned __int8 *)&v7[m_pMemory + 1], src: (unsigned __int8 *)&v7[m_pMemory], count: 4 * v8);
    v9 = (CDmxElement **)&elementsToDelete->m_pMemory[m_pMemory];
    if ( v9 != nullptr )
      *v9 = v2;
    v10 = 0;
    nCount = v2->m_Attributes.m_Size;
    i = 0;
    if ( nCount > 0 )
    {
      do
      {
        v11 = v2->m_Attributes.m_Memory.m_pMemory[v10];
        if ( v11->m_Type == AT_FIRST_VALUE_TYPE )
        {
          v12 = *(CDmxElement **)v11->m_pData;
          if ( v12 != nullptr )
            CDmxElement::AddElementsToDelete(
              this: v12,
              (CUtlVector<CDmxElement *,CUtlMemory<CDmxElement *,int> > *)elementsToDelete);
        }
        else if ( v11->m_Type == AT_FIRST_ARRAY_TYPE )
        {
          m_pData = v11->m_pData;
          v14 = m_pData[3];
          v15 = 0;
          for ( nElementCount = v14; v15 < v14; ++v15 )
          {
            if ( *(_DWORD *)(*m_pData + 4 * v15) != 0 )
            {
              CDmxElement::AddElementsToDelete(
                this: *(CDmxElement **)(*m_pData + 4 * v15),
                (CUtlVector<CDmxElement *,CUtlMemory<CDmxElement *,int> > *)elementsToDelete);
              v14 = nElementCount;
            }
          }
          v2 = this;
        }
        v10 = i + 1;
        i = v10;
      }
      while ( v10 < nCount );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x103F50F0
// Name: public: CUtlSymbolTableLargeBase<class CThreadsafeTree<0>,0>::CUtlSymbolTableLargeBase<class CThreadsafeTree<0>,0>(void)
// Source: json
//------------------------------------------------------------------------------
CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0> *__thiscall CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>(
        CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0> *this)
{
  CUtlTSHash<CUtlSymbolTableLargeBaseTreeEntry_t *,2048,CUtlSymbolTableLargeBaseTreeEntry_t *,CCThreadsafeTreeHashMethod<2048,CUtlSymbolTableLargeBaseTreeEntry_t *,0>,0>::HashBucket_t *m_aBuckets; // eax
  int v3; // edx
  CThreadSpinRWLock *p_m_AddLock; // ecx
  int i; // ecx

  CUtlMemoryPool::CUtlMemoryPool(
    this: &this->m_Lookup.m_EntryMemory,
    blockSize: 0xCu,
    numElements: 32,
    growMode: 2,
    pszAllocOwner: nullptr,
    nAlignment: 0);
  m_aBuckets = this->m_Lookup.m_aBuckets;
  this->m_Lookup.m_EntryMemory.m_mutex.m_ownerID = 0;
  this->m_Lookup.m_EntryMemory.m_mutex.m_depth = 0;
  v3 = 2047;
  p_m_AddLock = &this->m_Lookup.m_aBuckets[0].m_AddLock;
  do
  {
    p_m_AddLock->m_lockInfo.m_i32 = 0;
    p_m_AddLock->m_writerId = 0;
    p_m_AddLock += 2;
    --v3;
  }
  while ( v3 >= 0 );
  this->m_Lookup.m_bNeedsCommit = false;
  for ( i = 2048; i != 0; --i )
  {
    m_aBuckets->m_pFirst = nullptr;
    m_aBuckets->m_pFirstUncommitted = nullptr;
    ++m_aBuckets;
  }
  this->m_StringPools.m_Memory.m_pMemory = nullptr;
  this->m_StringPools.m_Memory.m_nAllocationCount = 0;
  this->m_StringPools.m_Size = 0;
  this->m_StringPools.m_pElements = nullptr;
  this->m_StringPools.m_Memory.m_nGrowSize = 8;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x103F5170
// Name: public: class CUtlSymbolLarge CUtlSymbolTableLargeBase<class CThreadsafeTree<0>,0>::AddString(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CUtlSymbolLarge *__thiscall CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::AddString(
        CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0> *this,
        CUtlSymbolLarge *result,
        char *pString)
{
  const char *v3; // esi
  void *m_String; // ecx
  unsigned int v7; // eax
  unsigned int v8; // edi
  int PoolWithSpace; // esi
  unsigned int v10; // esi
  CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *v11; // edx
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t **m_pMemory; // ecx
  int v15; // eax
  CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t **v16; // eax
  int v17; // eax
  CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *v18; // ecx
  int m_SpaceUsed; // edx
  int v20; // esi
  unsigned __int8 *v21; // ecx
  unsigned int lenString; // [esp+8h] [ebp-Ch]
  int lenDecorated; // [esp+Ch] [ebp-8h]
  CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *pPool; // [esp+10h] [ebp-4h] BYREF

  v3 = pString;
  if ( pString != nullptr )
  {
    CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::Find(this, result: (CUtlSymbolLarge *)&pPool, pString);
    m_String = pPool;
    if ( pPool == (CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *)-1 )
    {
      v7 = _V_strlen(str: v3) + 1;
      v8 = (v7 + 7) & 0xFFFFFFFC;
      lenString = v7;
      lenDecorated = v8;
      PoolWithSpace = CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::FindPoolWithSpace(this, len: v8);
      if ( PoolWithSpace == -1 )
      {
        v10 = v8 + 12;
        if ( v8 + 12 <= 0x800 )
          v10 = 2048;
        v11 = (CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *)operator new(nSize: v10);
        v11->m_TotalLen = v10 - 12;
        v11->m_SpaceUsed = 0;
        m_Size = this->m_StringPools.m_Size;
        m_nAllocationCount = this->m_StringPools.m_Memory.m_nAllocationCount;
        pPool = v11;
        if ( m_Size + 1 > m_nAllocationCount )
        {
          CUtlMemory<CNavLadder *,int>::Grow(
            this: (CUtlMemory<vgui::TreeNode *,int> *)&this->m_StringPools,
            num: m_Size - m_nAllocationCount + 1);
          v11 = pPool;
        }
        ++this->m_StringPools.m_Size;
        m_pMemory = this->m_StringPools.m_Memory.m_pMemory;
        v15 = this->m_StringPools.m_Size - m_Size - 1;
        this->m_StringPools.m_pElements = m_pMemory;
        if ( v15 > 0 )
        {
          _V_memmove(
            dest: (unsigned __int8 *)&m_pMemory[m_Size + 1],
            src: (unsigned __int8 *)&m_pMemory[m_Size],
            count: 4 * v15);
          v11 = pPool;
        }
        v16 = &this->m_StringPools.m_Memory.m_pMemory[m_Size];
        if ( v16 != nullptr )
          *v16 = v11;
        PoolWithSpace = m_Size;
        v8 = lenDecorated;
      }
      v17 = HashString(pszKey: pString);
      v18 = this->m_StringPools.m_Memory.m_pMemory[PoolWithSpace];
      m_SpaceUsed = v18->m_SpaceUsed;
      v20 = (int)&v18->m_Data[m_SpaceUsed];
      v18->m_SpaceUsed = v8 + m_SpaceUsed;
      v21 = (unsigned __int8 *)pString;
      *(_DWORD *)v20 = v17;
      _V_memcpy(dest: (unsigned __int8 *)(v20 + 4), src: v21, count: lenString);
      pString = (char *)v20;
      m_String = CUtlTSHash<CUtlSymbolTableLargeBaseTreeEntry_t *,2048,CUtlSymbolTableLargeBaseTreeEntry_t *,CCThreadsafeTreeHashMethod<2048,CUtlSymbolTableLargeBaseTreeEntry_t *,0>,0>::Insert(
                   this: &this->m_Lookup,
                   uiKey: (CUtlSymbolTableLargeBaseTreeEntry_t *)v20,
                   data: (CUtlSymbolTableLargeBaseTreeEntry_t **)&pString,
                   pDidInsert: nullptr)->m_Data->m_String;
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
// Address: 0x103F52D0
// Name: public: class CUtlString const __near & CDmxElement::GetValue<class CUtlString>(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
const CUtlString *__thiscall CDmxElement::GetValue<CUtlString>(CDmxElement *this, const char *pAttributeName)
{
  int v3; // edi
  CDmxAttribute *v4; // eax
  CDmxAttribute v6; // [esp+8h] [ebp-Ch] BYREF

  CDmxElement::Resort(this);
  CDmxAttribute::CDmxAttribute(this: &v6, pAttributeName);
  pAttributeName = (const char *)&v6;
  v3 = CUtlSortVector<CDmxAttribute *,CDmxAttributeLess>::Find(
         this: &this->m_Attributes,
         src: (CDmxAttribute *const **)&pAttributeName);
  CDmxAttribute::~CDmxAttribute(this: &v6);
  if ( v3 >= 0 && (v4 = this->m_Attributes.m_Memory.m_pMemory[v3]) != nullptr )
  {
    if ( v4->m_Type == AT_STRING )
    {
      return (const CUtlString *)v4->m_pData;
    }
    else
    {
      if ( (`CDmxAttribute::GetValue<CUtlString>'::`4'::`local static guard' & 1) == 0 )
      {
        `CDmxAttribute::GetValue<CUtlString>'::`4'::`local static guard' |= 1u;
        CUtlString::CUtlString(this: &`CDmxAttribute::GetValue<CUtlString>'::`4'::defaultValue);
        atexit(func: `CDmxAttribute::GetValue<CUtlString>'::`4'::`dynamic atexit destructor for 'defaultValue'');
      }
      CUtlString::Set(this: &`CDmxAttribute::GetValue<CUtlString>'::`4'::defaultValue, pValue: nullptr);
      return &`CDmxAttribute::GetValue<CUtlString>'::`4'::defaultValue;
    }
  }
  else
  {
    if ( (`CDmxElement::GetValue<CUtlString>'::`4'::`local static guard' & 1) == 0 )
    {
      `CDmxElement::GetValue<CUtlString>'::`4'::`local static guard' |= 1u;
      CUtlString::CUtlString(this: &`CDmxElement::GetValue<CUtlString>'::`4'::defaultValue);
      atexit(func: `CDmxElement::GetValue<CUtlString>'::`4'::`dynamic atexit destructor for 'defaultValue'');
    }
    CUtlString::Set(this: &`CDmxElement::GetValue<CUtlString>'::`4'::defaultValue, pValue: nullptr);
    return &`CDmxElement::GetValue<CUtlString>'::`4'::defaultValue;
  }
}

//------------------------------------------------------------------------------
// Address: 0x103F5400
// Name: private: CDmxElement::CDmxElement(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDmxElement *__thiscall CDmxElement::CDmxElement(CDmxElement *this, char *pType)
{
  char *v4; // [esp-4h] [ebp-Ch]

  v4 = pType;
  this->m_Attributes.m_Memory.m_pMemory = nullptr;
  this->m_Attributes.m_Memory.m_nAllocationCount = 0;
  this->m_Attributes.m_Memory.m_nGrowSize = 0;
  this->m_Attributes.m_Size = 0;
  this->m_Attributes.m_pElements = nullptr;
  this->m_Attributes.m_pLessContext = nullptr;
  this->m_Attributes.m_bNeedsSort = false;
  this->m_Type.u.m_Id = -1;
  this->m_Type = (CUtlSymbolLarge)CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::AddString(
                                    this: &CDmxElement::s_TypeSymbols,
                                    result: (CUtlSymbolLarge *)&pType,
                                    pString: v4)->u.m_Id;
  *((_BYTE *)this + 49) &= 0xFCu;
  this->m_nLockCount = 0;
  CreateUniqueId(pDest: &this->m_Id);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x103F5460
// Name: public: char const __near * CDmxElement::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CDmxElement::GetName(CDmxElement *this)
{
  CUtlString *v1; // eax

  v1 = (CUtlString *)CDmxElement::GetValue<CUtlString>(this, pAttributeName: "name");
  return CUtlString::operator char const *(this: v1);
}

//------------------------------------------------------------------------------
// Address: 0x103F5480
// Name: public: class CDmxAttribute __near * CDmxElement::AddAttribute(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDmxAttribute *__thiscall CDmxElement::AddAttribute(CDmxElement *this, CDmxAttribute *pAttributeName)
{
  const char *v3; // ebx
  int v4; // edi
  unsigned __int8 *v6; // eax
  const char *v7; // edi
  CDmxAttribute v9; // [esp+Ch] [ebp-Ch] BYREF

  CDmxElement::Resort(this);
  v3 = (const char *)pAttributeName;
  CDmxAttribute::CDmxAttribute(this: &v9, (const char *)pAttributeName);
  pAttributeName = &v9;
  v4 = CUtlSortVector<CDmxAttribute *,CDmxAttributeLess>::Find(
         this: &this->m_Attributes,
         src: (CDmxAttribute *const **)&pAttributeName);
  CDmxAttribute::~CDmxAttribute(this: &v9);
  if ( v4 >= 0 )
    return this->m_Attributes.m_Memory.m_pMemory[v4];
  ++this->m_nLockCount;
  *((_BYTE *)this + 49) |= 1u;
  v6 = DMXAlloc(size: 0xCu);
  if ( v6 != nullptr )
    v7 = (const char *)CDmxAttribute::CDmxAttribute(this: (CDmxAttribute *)v6, pAttributeName: v3);
  else
    v7 = nullptr;
  pAttributeName = (CDmxAttribute *)v7;
  CUtlSortVector<CDmxAttribute *,CDmxAttributeLess>::InsertNoSort(this: &this->m_Attributes, src: &pAttributeName);
  if ( this->m_nLockCount-- == 1 )
    CDmxElement::Resort(this);
  return (CDmxAttribute *)v7;
}

//------------------------------------------------------------------------------
// Address: 0x103F5520
// Name: public: void CDmxElement::UnpackIntoStructure(void __near *,struct DmxElementUnpackStructure_t const __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxElement::UnpackIntoStructure(CDmxElement *this, void *pData, CDmxAttribute *pUnpack)
{
  bool v3; // zf
  const char **p_m_Name; // edi
  CUtlString *v5; // ebx
  const char *v6; // eax
  const char *v7; // esi
  int v8; // esi
  CDmxAttribute *p_temp; // esi
  CUtlString *m_pData; // ecx
  char *v11; // eax
  char *v12; // eax
  const CUtlVector<float,CUtlMemory<float,int> > *v13; // eax
  int v14; // ecx
  int *p_m_nGrowSize; // edx
  DmAttributeType_t v16; // eax
  CDmxAttribute v17; // [esp+4h] [ebp-1Ch] BYREF
  CDmxAttribute temp; // [esp+10h] [ebp-10h] BYREF
  CDmxElement *v19; // [esp+1Ch] [ebp-4h]

  v3 = pUnpack->m_pData == nullptr;
  v19 = this;
  if ( !v3 )
  {
    p_m_Name = (const char **)&pUnpack->m_Name;
    while ( 1 )
    {
      v5 = (CUtlString *)&p_m_Name[2][(_DWORD)pData];
      if ( p_m_Name[8] == nullptr )
        break;
      CDmxElement::UnpackIntoStructure(this: v19, pData: v5, pUnpack: (const DmxElementUnpackStructure_t *)p_m_Name[8]);
LABEL_43:
      p_m_Name += 11;
      if ( p_m_Name[1] == nullptr )
        return;
    }
    v6 = p_m_Name[1];
    if ( (unsigned int)(v6 - 15) <= 0xD && (v6 == (const char *)19 || p_m_Name[4] != (const char *)-1)
      || v6 == (const char *)6
      || v6 == (const char *)20 )
    {
      goto LABEL_43;
    }
    CDmxAttribute::CDmxAttribute(this: &temp, pAttributeName: nullptr);
    v7 = *(p_m_Name - 1);
    CDmxElement::Resort(this: v19);
    CDmxAttribute::CDmxAttribute(this: &v17, pAttributeName: v7);
    pUnpack = &v17;
    v8 = CUtlSortVector<CDmxAttribute *,CDmxAttributeLess>::Find(
           this: &v19->m_Attributes,
           src: (CDmxAttribute *const **)&pUnpack);
    CDmxAttribute::~CDmxAttribute(this: &v17);
    if ( v8 < 0 || (p_temp = v19->m_Attributes.m_Memory.m_pMemory[v8]) == nullptr )
    {
      if ( *p_m_Name == nullptr )
      {
LABEL_42:
        CDmxAttribute::~CDmxAttribute(this: &temp);
        goto LABEL_43;
      }
      CDmxAttribute::AllocateDataMemory_AndConstruct(this: &temp, type: (DmAttributeType_t)p_m_Name[1]);
      if ( (unsigned int)(p_m_Name[1] - 15) > 0xD )
        CDmxAttribute::SetValueFromString(this: &temp, pValue: (char *)*p_m_Name);
      p_temp = &temp;
    }
    if ( p_m_Name[1] == (const char *)p_temp->m_Type )
    {
      if ( p_temp->m_Type == AT_STRING )
      {
        m_pData = (CUtlString *)p_temp->m_pData;
        if ( p_m_Name[3] == (const char *)-1 )
        {
          v11 = (char *)CUtlString::operator char const *(this: m_pData);
          CUtlString::operator=(this: v5, src: v11);
        }
        else
        {
          v12 = (char *)CUtlString::operator char const *(this: m_pData);
          V_strncpy(pDest: (char *)v5, pSrc: v12, maxLen: (int)p_m_Name[3]);
        }
      }
      else if ( CDmxAttribute::ArrayAttributeBasicType(type: p_temp->m_Type) == AT_FLOAT
             && p_m_Name[3] == (const char *)16 )
      {
        if ( (unsigned int)(p_m_Name[1] - 15) > 0xD )
        {
          v5->m_Storage.m_Memory.m_pMemory = *(unsigned __int8 **)p_temp->m_pData;
          v5->m_Storage.m_Memory.m_nAllocationCount = *(_DWORD *)p_temp->m_pData;
          v5->m_Storage.m_Memory.m_nGrowSize = *(_DWORD *)p_temp->m_pData;
          v5->m_Storage.m_nActualLength = *(_DWORD *)p_temp->m_pData;
        }
        else
        {
          v13 = CDmxAttribute::GetArray<float>(this: p_temp);
          v14 = 0;
          if ( (int)p_m_Name[9] > 0 )
          {
            p_m_nGrowSize = &v5->m_Storage.m_Memory.m_nGrowSize;
            do
            {
              *(p_m_nGrowSize - 2) = LODWORD(v13->m_Memory.m_pMemory[v14]);
              *(p_m_nGrowSize - 1) = LODWORD(v13->m_Memory.m_pMemory[v14]);
              *p_m_nGrowSize = LODWORD(v13->m_Memory.m_pMemory[v14]);
              p_m_nGrowSize[1] = LODWORD(v13->m_Memory.m_pMemory[v14++]);
              p_m_nGrowSize += 4;
            }
            while ( v14 < (int)p_m_Name[9] );
          }
        }
      }
      else
      {
        v16 = (DmAttributeType_t)p_m_Name[1];
        if ( (unsigned int)(v16 - 15) > 0xD )
        {
          if ( p_m_Name[4] == (const char *)-1 )
          {
            memcpy(
              dst: (unsigned __int8 *)v5,
              src: (unsigned __int8 *)p_temp->m_pData,
              count: (unsigned int)p_m_Name[3]);
          }
          else if ( p_temp->m_Type == AT_INT )
          {
            switch ( (unsigned int)p_m_Name[5] )
            {
              case 1u:
              case 3u:
                CDmxElement::UnpackBitfield<unsigned char>(
                  this: v19,
                  pDest: (unsigned __int8 *)v5,
                  pUnpack: (const DmxElementUnpackStructure_t *)(p_m_Name - 1),
                  pAttribute: p_temp);
                break;
              case 2u:
                goto $LN12_46;
              case 4u:
                CDmxElement::UnpackBitfield<short>(
                  this: v19,
                  pDest: (__int16 *)v5,
                  pUnpack: (const DmxElementUnpackStructure_t *)(p_m_Name - 1),
                  pAttribute: p_temp);
                break;
              case 5u:
                CDmxElement::UnpackBitfield<unsigned short>(
                  this: v19,
                  pDest: (unsigned __int16 *)v5,
                  pUnpack: (const DmxElementUnpackStructure_t *)(p_m_Name - 1),
                  pAttribute: p_temp);
                break;
              case 6u:
                CDmxElement::UnpackBitfield<int>(
                  this: v19,
                  pDest: (int *)v5,
                  pUnpack: (const DmxElementUnpackStructure_t *)(p_m_Name - 1),
                  pAttribute: p_temp);
                break;
              case 7u:
                CDmxElement::UnpackBitfield<unsigned int>(
                  this: v19,
                  pDest: (unsigned int *)v5,
                  pUnpack: (const DmxElementUnpackStructure_t *)(p_m_Name - 1),
                  pAttribute: p_temp);
                break;
              default:
                goto LABEL_42;
            }
          }
          else
          {
$LN12_46:
            CDmxElement::UnpackBitfield<char>(
              this: v19,
              pDest: (char *)v5,
              pUnpack: (const DmxElementUnpackStructure_t *)(p_m_Name - 1),
              pAttribute: p_temp);
          }
        }
        else
        {
          CDmxAttribute::GetArrayValue(
            this: p_temp,
            type: v16,
            pDest: (unsigned __int8 *)v5,
            nDataTypeSize: (int)p_m_Name[3],
            nDestArrayLength: (int)p_m_Name[9],
            pDefaultString: (char *)*p_m_Name);
        }
      }
    }
    else
    {
      _Warning(
        a1: "CDmxElement::UnpackIntoStructure: Mismatched attribute type in attribute \"%s\"!\n",
        *(p_m_Name - 1));
    }
    goto LABEL_42;
  }
}

//------------------------------------------------------------------------------
// Address: 0x103F57D0
// Name: private: void CDmxElement::RemoveAllElementsRecursive(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxElement::RemoveAllElementsRecursive(CDmxElement *this)
{
  int v1; // edi
  int v2; // ecx
  CDmxElement **m_pMemory; // eax
  CDmxElement *v4; // esi
  int m_Size; // ebx
  CDmxAttribute *v6; // ecx
  bool v8; // sf
  CDmxAttribute **v9; // eax
  CUtlVector<CDmxElement *,CUtlMemory<CDmxElement *,int> > elementsToDelete; // [esp+4h] [ebp-1Ch] BYREF
  int nCount; // [esp+18h] [ebp-8h]
  int i; // [esp+1Ch] [ebp-4h]

  v1 = 0;
  memset(&elementsToDelete, 0, sizeof(elementsToDelete));
  CDmxElement::AddElementsToDelete(this, (CUtlMemory<vgui::TreeNode *,int> *)&elementsToDelete);
  v2 = 0;
  nCount = elementsToDelete.m_Size;
  m_pMemory = elementsToDelete.m_Memory.m_pMemory;
  for ( i = 0; v2 < nCount; i = v2 )
  {
    v4 = m_pMemory[v2];
    if ( v4 != nullptr )
    {
      ++v4->m_nLockCount;
      m_Size = v4->m_Attributes.m_Size;
      if ( m_Size > 0 )
      {
        do
        {
          v6 = v4->m_Attributes.m_Memory.m_pMemory[v1];
          if ( v6 != nullptr )
            CDmxAttribute::~CDmxAttribute(this: v6);
          ++v1;
        }
        while ( v1 < m_Size );
      }
      *((_BYTE *)v4 + 49) &= ~1u;
      v4->m_Attributes.m_Size = 0;
      if ( v4->m_nLockCount-- == 1 )
        CDmxElement::Resort(this: v4);
      v8 = v4->m_Attributes.m_Memory.m_nGrowSize < 0;
      v4->m_Attributes.m_Size = 0;
      if ( !v8 )
      {
        if ( v4->m_Attributes.m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v4->m_Attributes.m_Memory.m_pMemory);
          v4->m_Attributes.m_Memory.m_pMemory = nullptr;
        }
        v4->m_Attributes.m_Memory.m_nAllocationCount = 0;
      }
      v8 = v4->m_Attributes.m_Memory.m_nGrowSize < 0;
      v9 = v4->m_Attributes.m_Memory.m_pMemory;
      v4->m_Attributes.m_pElements = v4->m_Attributes.m_Memory.m_pMemory;
      if ( !v8 )
      {
        if ( v9 != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v9);
          v4->m_Attributes.m_Memory.m_pMemory = nullptr;
        }
        v4->m_Attributes.m_Memory.m_nAllocationCount = 0;
      }
      m_pMemory = elementsToDelete.m_Memory.m_pMemory;
      v1 = 0;
    }
    v2 = i + 1;
  }
  elementsToDelete.m_Size = 0;
  if ( elementsToDelete.m_Memory.m_nGrowSize >= 0 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      m_pMemory = nullptr;
      elementsToDelete.m_Memory.m_pMemory = nullptr;
    }
    elementsToDelete.m_Memory.m_nAllocationCount = 0;
  }
  elementsToDelete.m_pElements = m_pMemory;
  if ( elementsToDelete.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x10418690
// Name: _dynamic_initializer_for__CDmxElement::s_TypeSymbols__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmxElement::s_TypeSymbols__()
{
  CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>(this: &CDmxElement::s_TypeSymbols);
  return atexit(func: dynamic_atexit_destructor_for__CDmxElement::s_TypeSymbols__);
}

//------------------------------------------------------------------------------
// Address: 0x10422FB0
// Name: _dynamic_atexit_destructor_for__CDmxElement::s_TypeSymbols__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmxElement::s_TypeSymbols__()
{
  CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::RemoveAll(this: &CDmxElement::s_TypeSymbols);
  CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&CDmxElement::s_TypeSymbols.m_StringPools);
  CUtlTSHash<CUtlSymbolTableLargeBaseTreeEntry_t *,2048,CUtlSymbolTableLargeBaseTreeEntry_t *,CCThreadsafeTreeHashMethod<2048,CUtlSymbolTableLargeBaseTreeEntry_t *,0>,0>::RemoveAll(this: &CDmxElement::s_TypeSymbols.m_Lookup);
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmxElement::s_TypeSymbols.m_Lookup.m_EntryMemory);
}

} // namespace server
