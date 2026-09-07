// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: datacache/datacache.cpp
// Functions: 88
// ============================================================

#include "datacache\datacache.h"

//------------------------------------------------------------------------------
// Address: 0x10001030
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
// Address: 0x10001090
// Name: public: struct TSLNodeBase_t __near * CTSListBase::Pop(void)
// Source: json
//------------------------------------------------------------------------------
TSLNodeBase_t *__thiscall CTSListBase::Pop(CTSListBase *this)
{
  TSLNodeBase_t *Next; // esi
  int DepthAndSequence; // eax

  Next = this->m_Head.value.Next;
  DepthAndSequence = this->m_Head.value32.DepthAndSequence;
  if ( this->m_Head.value.Next == nullptr )
    return nullptr;
  while ( (unsigned __int8)_ThreadInterlockedAssignIf64(
                             a1: this,
                             a2: Next->Next,
                             a3: DepthAndSequence - 1,
                             a4: Next,
                             a5: DepthAndSequence) == 0 )
  {
    _mm_pause();
    Next = this->m_Head.value.Next;
    DepthAndSequence = this->m_Head.value32.DepthAndSequence;
    if ( this->m_Head.value.Next == nullptr )
      return nullptr;
  }
  return Next;
}

//------------------------------------------------------------------------------
// Address: 0x100010D0
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
// Address: 0x10001120
// Name: public: virtual void CDataCacheSection::SetLimits(struct DataCacheLimits_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDataCacheSection::SetLimits(CDataCacheSection *this, const DataCacheLimits_t *limits)
{
  this->m_limits = *limits;
}

//------------------------------------------------------------------------------
// Address: 0x10001150
// Name: public: virtual void CDataCacheSection::SetOptions(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDataCacheSection::SetOptions(CDataCacheSection *this, unsigned int options)
{
  this->m_options = options;
}

//------------------------------------------------------------------------------
// Address: 0x10001160
// Name: public: virtual unsigned int CDataCacheSection::GetOptions(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CDataCacheSection::GetOptions(CDataCacheSection *this)
{
  return this->m_options;
}

//------------------------------------------------------------------------------
// Address: 0x10001170
// Name: public: virtual void CDataCacheSection::GetStatus(struct DataCacheStatus_t __near *,struct DataCacheLimits_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDataCacheSection::GetStatus(
        CDataCacheSection *this,
        DataCacheStatus_t *pStatus,
        DataCacheLimits_t *pLimits)
{
  if ( pStatus != nullptr )
    *pStatus = this->m_status;
  if ( pLimits != nullptr )
    *pLimits = this->m_limits;
}

//------------------------------------------------------------------------------
// Address: 0x100011D0
// Name: public: virtual bool CDataCacheSection::Add(unsigned int,void const __near *,unsigned int,struct memhandle_t__ __near * __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDataCacheSection::Add(
        CDataCacheSection *this,
        unsigned int clientId,
        const void *pItemData,
        unsigned int size,
        memhandle_t__ **pHandle)
{
  return this->AddEx(this, a2: clientId, a3: pItemData, a4: size, a5: 0, a6: pHandle);
}

//------------------------------------------------------------------------------
// Address: 0x100011F0
// Name: public: virtual struct memhandle_t__ __near * CDataCacheSection::Find(unsigned int)
// Source: json
//------------------------------------------------------------------------------
memhandle_t__ *__thiscall CDataCacheSection::Find(CDataCacheSection *this, unsigned int clientId)
{
  memhandle_t__ *(__thiscall *DoFind)(CDataCacheSection *, unsigned int); // edx
  memhandle_t__ *result; // eax

  DoFind = this->DoFind;
  ++this->m_status.nFindRequests;
  result = DoFind(this, a2: clientId);
  if ( result != nullptr )
    ++this->m_status.nFindHits;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10001220
// Name: public: virtual void CDataCacheSection::LockMutex(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDataCacheSection::LockMutex(CDataCacheSection *this)
{
  CThreadFastMutex *m_mutex; // esi
  DWORD CurrentThreadId; // ecx

  ++g_iDontForceFlush;
  m_mutex = this->m_mutex;
  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != m_mutex->m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)m_mutex, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(a1: m_mutex, a2: CurrentThreadId, a3: 0);
  }
  else
  {
    ++m_mutex->m_depth;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10001260
// Name: public: virtual void CDataCacheSection::UnlockMutex(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDataCacheSection::UnlockMutex(CDataCacheSection *this)
{
  CThreadFastMutex *m_mutex; // eax

  m_mutex = this->m_mutex;
  --g_iDontForceFlush;
  if ( m_mutex->m_depth-- == 1 )
    _InterlockedExchange((volatile __int32 *)m_mutex, 0);
}

//------------------------------------------------------------------------------
// Address: 0x10001280
// Name: public: virtual int __near * CDataCacheSection::GetFrameUnlockCounterPtr(void)
// Source: json
//------------------------------------------------------------------------------
int *__thiscall CDataCacheSection::GetFrameUnlockCounterPtr(CDataCacheSection *this)
{
  return &this->m_nFrameUnlockCounter;
}

//------------------------------------------------------------------------------
// Address: 0x10001290
// Name: public: virtual int CDataCacheSection::BreakLock(struct memhandle_t__ __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDataCacheSection::BreakLock(CDataCacheSection *this, memhandle_t__ *handle)
{
  return CDataManagerBase::BreakLock(this: this->m_LRU, handle);
}

//------------------------------------------------------------------------------
// Address: 0x100012A0
// Name: public: virtual bool CDataCacheSection::Touch(struct memhandle_t__ __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDataCacheSection::Touch(CDataCacheSection *this, memhandle_t__ *handle)
{
  CDataManagerBase::TouchResource(this: this->m_LRU, handle);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100012C0
// Name: public: virtual bool CDataCacheSection::Age(struct memhandle_t__ __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDataCacheSection::Age(CDataCacheSection *this, memhandle_t__ *handle)
{
  CDataManagerBase::MarkAsStale(this: this->m_LRU, handle);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100012E0
// Name: public: virtual void CDataCacheSection::OutputReport(enum DataCacheReportType_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDataCacheSection::OutputReport(CDataCacheSection *this, DataCacheReportType_t reportType)
{
  CDataCache_vtbl *v3; // edi
  const char *v4; // eax

  v3 = this->m_pSharedCache->__vftable;
  v4 = this->GetName(this);
  v3->OutputReport(this: this->m_pSharedCache, a2: reportType, a3: v4);
}

//------------------------------------------------------------------------------
// Address: 0x10001310
// Name: private: bool CDataCacheSection::DiscardItemData(struct DataCacheItem_t __near *,enum DataCacheNotificationType_t)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDataCacheSection::DiscardItemData(
        CDataCacheSection *this,
        DataCacheItem_t *pItem,
        DataCacheNotificationType_t type)
{
  DataCacheNotificationType_t v4; // eax
  CDataCacheSection_vtbl *v5; // edx
  const char *v6; // eax
  unsigned int clientId; // ecx
  const void *pItemData; // edx
  unsigned int size; // eax
  IDataCacheClient *m_pClient; // ecx
  char result; // al
  unsigned int v12; // edi
  CDataCache *m_pSharedCache; // ecx
  unsigned int v14; // edi
  CDataCache *v15; // eax
  DataCacheNotification_t notification; // [esp+8h] [ebp-14h] BYREF

  if ( pItem == nullptr )
    return 0;
  v4 = type;
  if ( type != DC_NONE )
  {
    if ( type == DC_AGE_DISCARD && this->m_pSharedCache->m_bInFlush )
      v4 = DC_FLUSH_DISCARD;
    v5 = this->__vftable;
    notification.type = v4;
    v6 = v5->GetName(this);
    clientId = pItem->clientId;
    pItemData = pItem->pItemData;
    notification.pszSectionName = v6;
    size = pItem->size;
    notification.clientId = clientId;
    m_pClient = this->m_pClient;
    notification.pItemData = pItemData;
    notification.nItemSize = size;
    result = m_pClient->HandleCacheNotification(this: m_pClient, a2: &notification);
    if ( result != 0 )
    {
      v12 = pItem->size;
      m_pSharedCache = this->m_pSharedCache;
      this->m_status.nBytes -= v12;
      --this->m_status.nItems;
      _InterlockedExchangeAdd((volatile signed __int32 *)&m_pSharedCache->m_status, -v12);
      _InterlockedExchangeAdd((volatile signed __int32 *)&this->m_pSharedCache->m_status.nItems, 0xFFFFFFFF);
    }
  }
  else
  {
    this->OnRemove(this, a2: pItem->clientId);
    pItem->pSection = nullptr;
    pItem->pItemData = nullptr;
    pItem->clientId = 0;
    v14 = pItem->size;
    v15 = this->m_pSharedCache;
    this->m_status.nBytes -= v14;
    --this->m_status.nItems;
    _InterlockedExchangeAdd((volatile signed __int32 *)&v15->m_status, -v14);
    _InterlockedExchangeAdd((volatile signed __int32 *)&this->m_pSharedCache->m_status.nItems, 0xFFFFFFFF);
    return 1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10001420
// Name: public: virtual void __near * CDataCache::QueryInterface(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall CDataCache::QueryInterface(CDataCache *this, const char *pInterfaceName)
{
  void *(__cdecl *FactoryThis)(const char *, int *); // eax

  FactoryThis = Sys_GetFactoryThis();
  return FactoryThis(a1: pInterfaceName, a2: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x10001440
// Name: public: virtual void CDataCache::SetSize(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDataCache::SetSize(CDataCache *this, unsigned int nMaxBytes)
{
  CDataManager<DataCacheItem_t,DataCacheItemData_t,DataCacheItem_t *,CThreadFastMutex> *p_m_LRU; // esi

  p_m_LRU = &this->m_LRU;
  CDataManagerBase::SetTargetSize(this: &this->m_LRU, targetSize: nMaxBytes);
  CDataManagerBase::FlushToTargetSize(this: p_m_LRU);
}

//------------------------------------------------------------------------------
// Address: 0x10001460
// Name: public: virtual void CDataCache::SetSectionLimits(char const __near *,struct DataCacheLimits_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDataCache::SetSectionLimits(
        CDataCache *this,
        const char *pszSectionName,
        const DataCacheLimits_t *limits)
{
  IDataCacheSection *v3; // eax

  v3 = this->FindSection(this, a2: pszSectionName);
  if ( v3 != nullptr )
    v3->SetLimits(this: v3, a2: limits);
  else
    DevMsg(a1: "Cannot find requested cache section \"%s\"", pszSectionName);
}

//------------------------------------------------------------------------------
// Address: 0x100014A0
// Name: public: virtual unsigned int CDataCache::Purge(unsigned int)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CDataCache::Purge(CDataCache *this, unsigned int nBytes)
{
  return CDataManagerBase::Purge(this: &this->m_LRU, nBytesToPurge: nBytes);
}

//------------------------------------------------------------------------------
// Address: 0x100014B0
// Name: public: virtual unsigned int CDataCache::Flush(bool,bool)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CDataCache::Flush(CDataCache *this, bool bUnlockedOnly, bool bNotify)
{
  unsigned int result; // eax
  CDataManager<DataCacheItem_t,DataCacheItemData_t,DataCacheItem_t *,CThreadFastMutex> *p_m_LRU; // ecx

  if ( this->m_bInFlush )
    return 0;
  this->m_bInFlush = true;
  p_m_LRU = &this->m_LRU;
  if ( bUnlockedOnly )
    result = CDataManagerBase::FlushAllUnlocked(this: p_m_LRU);
  else
    result = CDataManagerBase::FlushAll(this: p_m_LRU);
  this->m_bInFlush = false;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10001500
// Name: public: virtual void CDataManager<struct DataCacheItem_t,struct DataCacheItemData_t,struct DataCacheItem_t __near *,class CThreadFastMutex>::Lock(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDataManager<DataCacheItem_t,DataCacheItemData_t,DataCacheItem_t *,CThreadFastMutex>::Lock(
        CDataManager<DataCacheItem_t,DataCacheItemData_t,DataCacheItem_t *,CThreadFastMutex> *this)
{
  CThreadFastMutex *p_m_mutex; // esi
  DWORD CurrentThreadId; // ecx

  p_m_mutex = &this->m_mutex;
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
}

//------------------------------------------------------------------------------
// Address: 0x10001540
// Name: public: virtual bool CDataManager<struct DataCacheItem_t,struct DataCacheItemData_t,struct DataCacheItem_t __near *,class CThreadFastMutex>::TryLock(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDataManager<DataCacheItem_t,DataCacheItemData_t,DataCacheItem_t *,CThreadFastMutex>::TryLock(
        CDataManager<DataCacheItem_t,DataCacheItemData_t,DataCacheItem_t *,CThreadFastMutex> *this)
{
  DWORD CurrentThreadId; // eax

  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != this->m_mutex.m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)&this->m_mutex, CurrentThreadId, 0) != 0 )
  {
    return 0;
  }
  ++this->m_mutex.m_depth;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10001570
// Name: public: virtual void CDataManager<struct DataCacheItem_t,struct DataCacheItemData_t,struct DataCacheItem_t __near *,class CThreadFastMutex>::Unlock(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDataManager<DataCacheItem_t,DataCacheItemData_t,DataCacheItem_t *,CThreadFastMutex>::Unlock(
        CDataManager<DataCacheItem_t,DataCacheItemData_t,DataCacheItem_t *,CThreadFastMutex> *this)
{
  if ( this->m_mutex.m_depth-- == 1 )
    _InterlockedExchange((volatile __int32 *)&this->m_mutex, 0);
}

//------------------------------------------------------------------------------
// Address: 0x10001590
// Name: protected: virtual void CFmtStrN<256>::InitQuietTruncation(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFmtStrN<256>::InitQuietTruncation(CFmtStrN<256> *this)
{
  this->m_bQuietTruncation = true;
}

//------------------------------------------------------------------------------
// Address: 0x10001670
// Name: public: static void __near * DataCacheItem_t::operator new(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void *__cdecl DataCacheItem_t::operator new(unsigned int size)
{
  DWORD CurrentThreadId; // ecx
  void *result; // eax

  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != DataCacheItem_t::s_Allocator.m_mutex.m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)&DataCacheItem_t::s_Allocator.m_mutex, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(a1: &DataCacheItem_t::s_Allocator.m_mutex, a2: CurrentThreadId, a3: 0);
  }
  else
  {
    ++DataCacheItem_t::s_Allocator.m_mutex.m_depth;
  }
  result = CUtlMemoryPool::Alloc(this: &DataCacheItem_t::s_Allocator, amount: size);
  if ( --DataCacheItem_t::s_Allocator.m_mutex.m_depth == 0 )
    _InterlockedExchange((volatile __int32 *)&DataCacheItem_t::s_Allocator.m_mutex, 0);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100016E0
// Name: public: static void DataCacheItem_t::operator delete(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DataCacheItem_t::operator delete(void *p)
{
  DWORD CurrentThreadId; // ecx

  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != DataCacheItem_t::s_Allocator.m_mutex.m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)&DataCacheItem_t::s_Allocator.m_mutex, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(a1: &DataCacheItem_t::s_Allocator.m_mutex, a2: CurrentThreadId, a3: 0);
  }
  else
  {
    ++DataCacheItem_t::s_Allocator.m_mutex.m_depth;
  }
  CUtlMemoryPool::Free(this: &DataCacheItem_t::s_Allocator, memBlock: p);
  if ( --DataCacheItem_t::s_Allocator.m_mutex.m_depth == 0 )
    _InterlockedExchange((volatile __int32 *)&DataCacheItem_t::s_Allocator.m_mutex, 0);
}

//------------------------------------------------------------------------------
// Address: 0x10001750
// Name: public: virtual CDataCacheSection::~CDataCacheSection(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDataCacheSection::~CDataCacheSection(CDataCacheSection *this)
{
  CTSSimpleList<CDataCacheSection::FrameLock_t> *p_m_FreeFrameLocks; // edi
  TSLNodeBase_t *Next; // esi
  int DepthAndSequence; // eax

  this->__vftable = (CDataCacheSection_vtbl *)&CDataCacheSection::`vftable';
  p_m_FreeFrameLocks = &this->m_FreeFrameLocks;
  while ( 1 )
  {
    Next = p_m_FreeFrameLocks->m_Head.value.Next;
    DepthAndSequence = p_m_FreeFrameLocks->m_Head.value32.DepthAndSequence;
    if ( p_m_FreeFrameLocks->m_Head.value.Next == nullptr )
      break;
    while ( (unsigned __int8)_ThreadInterlockedAssignIf64(
                               a1: p_m_FreeFrameLocks,
                               a2: Next->Next,
                               a3: DepthAndSequence - 1,
                               a4: Next,
                               a5: DepthAndSequence) == 0 )
    {
      _mm_pause();
      Next = p_m_FreeFrameLocks->m_Head.value.Next;
      DepthAndSequence = p_m_FreeFrameLocks->m_Head.value32.DepthAndSequence;
      if ( p_m_FreeFrameLocks->m_Head.value.Next == nullptr )
        goto LABEL_5;
    }
    if ( Next == nullptr )
      break;
    free(pMem: Next);
  }
LABEL_5:
  CTSListBase::Detach(this: p_m_FreeFrameLocks);
  this->__vftable = (CDataCacheSection_vtbl *)&IDataCacheSection::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x100017D0
// Name: public: virtual char const __near * CDataCacheSection::GetName(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CDataCacheSection::GetName(CDataCacheSection *this)
{
  return this->szName;
}

//------------------------------------------------------------------------------
// Address: 0x100017E0
// Name: private: virtual void CDataCacheSection::OnAdd(unsigned int,struct memhandle_t__ __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDataCacheSection::OnAdd(CDataCacheSection *this, unsigned int clientId, memhandle_t__ *hCacheItem)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x10001800
// Name: public: virtual class IDataCache __near * CDataCacheSection::GetSharedCache(void)
// Source: json
//------------------------------------------------------------------------------
CDataCache *__thiscall CDataCacheSection::GetSharedCache(CDataCacheSection *this)
{
  return this->m_pSharedCache;
}

//------------------------------------------------------------------------------
// Address: 0x10001810
// Name: private: void CDataCacheSection::ForceFlushDebug(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDataCacheSection::ForceFlushDebug(CDataCacheSection *this, bool bFlush)
{
  char *v3; // eax
  char *m_pszString; // eax

  if ( bFlush && mem_force_flush.m_pParent != nullptr && mem_force_flush.m_pParent->m_Value.m_nValue != 0 )
  {
    if ( (mem_force_flush_section.m_nFlags & 0x1000) != 0
      || (v3 = mem_force_flush_section.m_pParent->m_Value.m_pszString) != nullptr && *v3 != 0 )
    {
      if ( (mem_force_flush_section.m_nFlags & 0x1000) != 0 )
      {
        m_pszString = "FCVAR_NEVER_AS_STRING";
      }
      else
      {
        m_pszString = mem_force_flush_section.m_pParent->m_Value.m_pszString;
        if ( m_pszString == nullptr )
          m_pszString = (char *)defaultValue;
      }
      if ( _V_stricmp(s1: this->szName, s2: m_pszString) == 0 )
        this->Flush(this, a2: true, a3: true);
    }
    else
    {
      this->m_pSharedCache->Flush(this: this->m_pSharedCache, a2: true, a3: true);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100018A0
// Name: void DataCacheSize_f(class IConVar __near *,char const __near *,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DataCacheSize_f(IConVar *pConVar, const char *pOldString, float flOldValue)
{
  int m_nValue; // eax
  ConVarRef var; // [esp+0h] [ebp-8h] BYREF

  ConVarRef::ConVarRef(this: &var, pConVar);
  m_nValue = var.m_pConVarState->m_Value.m_nValue;
  if ( m_nValue != (int)flOldValue )
  {
    CDataManagerBase::SetTargetSize(this: &g_DataCache.m_LRU, targetSize: m_nValue << 20);
    CDataManagerBase::FlushToTargetSize(this: &g_DataCache.m_LRU);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100018E0
// Name: public: virtual void CDataCache::GetStatus(struct DataCacheStatus_t __near *,struct DataCacheLimits_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDataCache::GetStatus(CDataCache *this, DataCacheStatus_t *pStatus, DataCacheLimits_t *pLimits)
{
  if ( pStatus != nullptr )
    *pStatus = this->m_status;
  if ( pLimits != nullptr )
  {
    pLimits->nMaxBytes = -1;
    pLimits->nMaxItems = -1;
    pLimits->nMinBytes = 0;
    pLimits->nMinItems = 0;
    pLimits->nMaxBytes = CDataManagerBase::TargetSize(this: &this->m_LRU);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10001940
// Name: public: virtual int CDataCache::GetSectionCount(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDataCache::GetSectionCount(CDataCache *this)
{
  return this->m_Sections.m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x10001950
// Name: private: virtual void CDataManager<struct DataCacheItem_t,struct DataCacheItemData_t,struct DataCacheItem_t __near *,class CThreadFastMutex>::DestroyResourceStorage(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDataManager<DataCacheItem_t,DataCacheItemData_t,DataCacheItem_t *,CThreadFastMutex>::DestroyResourceStorage(
        CDataManager<DataCacheItem_t,DataCacheItemData_t,DataCacheItem_t *,CThreadFastMutex> *this,
        DataCacheItem_t *pStore)
{
  CDataCacheSection *pSection; // ecx

  pSection = pStore->pSection;
  if ( pSection != nullptr )
    CDataCacheSection::DiscardItemData(this: pSection, pItem: pStore, type: DC_AGE_DISCARD);
  DataCacheItem_t::operator delete(p: pStore);
}

//------------------------------------------------------------------------------
// Address: 0x10001980
// Name: private: virtual unsigned int CDataManager<struct DataCacheItem_t,struct DataCacheItemData_t,struct DataCacheItem_t __near *,class CThreadFastMutex>::GetRealSize(void __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CDataManager<DataCacheItem_t,DataCacheItemData_t,DataCacheItem_t *,CThreadFastMutex>::GetRealSize(
        CDataManager<DataCacheItem_t,DataCacheItemData_t,DataCacheItem_t *,CThreadFastMutex> *this,
        _DWORD *pStore)
{
  return pStore[1];
}

//------------------------------------------------------------------------------
// Address: 0x10001990
// Name: public: CFmtStrN<256>::CFmtStrN<256>(char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
CFmtStrN<256> *CFmtStrN<256>::CFmtStrN<256>(CFmtStrN<256> *this, const char *pszFormat, ...)
{
  CFmtStrN<256> *v2; // esi
  char *m_szBuf; // edi
  bool v4; // zf
  char *v6; // [esp-14h] [ebp-1Ch]
  const char *v7; // [esp-Ch] [ebp-14h]
  va_list params; // [esp+18h] [ebp+10h] BYREF

  va_start(params, pszFormat);
  v2 = this;
  v7 = pszFormat;
  m_szBuf = this->m_szBuf;
  v6 = this->m_szBuf;
  this->__vftable = (CFmtStrN<256>_vtbl *)&CFmtStrN<256>::`vftable';
  v2->m_bQuietTruncation = true;
  HIBYTE(this) = 0;
  V_vsnprintfRet(pDest: v6, maxLen: 255, pFormat: v7, params, pbTruncated: (bool *)&this + 3);
  v4 = HIBYTE(this) == 0;
  v2->m_szBuf[255] = 0;
  if ( !v4 && !v2->m_bQuietTruncation && `CFmtStrN<256>::CFmtStrN<256>'::`4'::scAsserted < 5 )
    ++`CFmtStrN<256>::CFmtStrN<256>'::`4'::scAsserted;
  v2->m_nLength = _V_strlen(str: m_szBuf);
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x10001A00
// Name: public: int CDataManagerBase::LockCount(struct memhandle_t__ __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDataManagerBase::LockCount(CDataManagerBase *this, memhandle_t__ *handle)
{
  __int16 v3; // dx
  int v4; // eax
  int lockCount; // ebx
  CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::ListElem_t *m_pMemory; // edi
  int v7; // eax

  this->Lock(this);
  v3 = (_WORD)handle - 1;
  v4 = (unsigned __int16)((_WORD)handle - 1);
  lockCount = 0;
  if ( v4 < this->m_memoryLists.m_MaxElementIndex )
  {
    m_pMemory = this->m_memoryLists.m_Memory.m_pMemory;
    v7 = v4;
    if ( (m_pMemory[v7].m_Previous != v3 || m_pMemory[v7].m_Next == v3)
      && m_pMemory[v7].m_Element.serial == HIWORD(handle)
      && (_WORD)handle != 0 )
    {
      lockCount = m_pMemory[v7].m_Element.lockCount;
    }
  }
  this->Unlock(this);
  return lockCount;
}

//------------------------------------------------------------------------------
// Address: 0x10001A70
// Name: public: CDataCacheSection::CDataCacheSection(class CDataCache __near *,class IDataCacheClient __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDataCacheSection *__thiscall CDataCacheSection::CDataCacheSection(
        CDataCacheSection *this,
        CDataCache *pSharedCache,
        IDataCacheClient *pClient,
        const char *pszName)
{
  CTSSimpleList<CDataCacheSection::FrameLock_t> *p_m_FreeFrameLocks; // ebx
  TSLNodeBase_t **v6; // esi
  TSLNodeBase_t *Next; // [esp-Ch] [ebp-18h]
  int DepthAndSequence; // [esp-8h] [ebp-14h]
  TSLNodeBase_t *v10; // [esp-8h] [ebp-14h]
  int v11; // [esp-4h] [ebp-10h]
  int i; // [esp+14h] [ebp+8h]

  this->m_LRU = &pSharedCache->m_LRU;
  this->__vftable = (CDataCacheSection_vtbl *)&CDataCacheSection::`vftable';
  this->m_nFrameUnlockCounter = 0;
  this->m_limits.nMaxBytes = -1;
  this->m_limits.nMaxItems = -1;
  this->m_limits.nMinBytes = 0;
  this->m_limits.nMinItems = 0;
  p_m_FreeFrameLocks = &this->m_FreeFrameLocks;
  this->m_pClient = pClient;
  this->m_options = 0;
  this->m_pSharedCache = pSharedCache;
  if ( (((_BYTE)this - 48) & 7) != 0 )
  {
    _Error(a1: "CTSListBase: Misaligned list\n");
    __debugbreak();
  }
  p_m_FreeFrameLocks->m_Head.value.Next = nullptr;
  this->m_FreeFrameLocks.m_Head.value32.DepthAndSequence = 0;
  this->m_mutex = pSharedCache->m_mutex;
  memset(dst: (unsigned __int8 *)this->m_FrameLocks, value: 0, count: sizeof(this->m_FrameLocks));
  *(_QWORD *)&this->m_status.nBytes = 0;
  *(_QWORD *)&this->m_status.nBytesLocked = 0;
  *(_QWORD *)&this->m_status.nFindRequests = 0;
  V_strncpy(pDest: this->szName, pSrc: pszName, maxLen: 16);
  for ( i = 0; i < 6; ++i )
  {
    v6 = (TSLNodeBase_t **)operator new(nSize: 0xCu);
    v6[2] = (TSLNodeBase_t *)i;
    DepthAndSequence = this->m_FreeFrameLocks.m_Head.value32.DepthAndSequence;
    Next = p_m_FreeFrameLocks->m_Head.value.Next;
    *v6 = p_m_FreeFrameLocks->m_Head.value.Next;
    if ( (unsigned __int8)_ThreadInterlockedAssignIf64(
                            a1: &this->m_FreeFrameLocks,
                            a2: v6,
                            a3: DepthAndSequence + 65537,
                            a4: Next,
                            a5: DepthAndSequence) == 0 )
    {
      do
      {
        _mm_pause();
        v11 = this->m_FreeFrameLocks.m_Head.value32.DepthAndSequence;
        v10 = p_m_FreeFrameLocks->m_Head.value.Next;
        *v6 = p_m_FreeFrameLocks->m_Head.value.Next;
      }
      while ( (unsigned __int8)_ThreadInterlockedAssignIf64(
                                 a1: &this->m_FreeFrameLocks,
                                 a2: v6,
                                 a3: v11 + 65537,
                                 a4: v10,
                                 a5: v11) == 0 );
    }
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10001BD0
// Name: public: virtual bool CDataCacheSection::IsPresent(struct memhandle_t__ __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDataCacheSection::IsPresent(CDataCacheSection *this, memhandle_t__ *handle)
{
  return CDataManagerBase::GetResource_NoLockNoLRUTouch(this: this->m_LRU, handle) != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10001BF0
// Name: public: virtual void CDataCacheSection::GetAndLockMultiple(void __near * __near *,int,struct memhandle_t__ __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDataCacheSection::GetAndLockMultiple(
        CDataCacheSection *this,
        void **ppData,
        int nCount,
        memhandle_t__ **pHandles)
{
  CThreadFastMutex *m_mutex; // edi
  DWORD CurrentThreadId; // eax
  void **v7; // edi
  int v8; // ebx
  void **v9; // eax
  unsigned int v10; // ecx
  CDataCache *m_pSharedCache; // edx
  CAutoLockT<CThreadFastMutex> generated_id_18; // [esp+Ch] [ebp-8h]
  int nLockCount; // [esp+10h] [ebp-4h] BYREF

  CDataCacheSection::ForceFlushDebug(this, bFlush: g_iDontForceFlush == 0);
  m_mutex = this->m_mutex;
  generated_id_18.m_lock = m_mutex;
  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != m_mutex->m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)m_mutex, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(a1: m_mutex, a2: CurrentThreadId, a3: 0);
  }
  else
  {
    ++m_mutex->m_depth;
  }
  if ( nCount > 0 )
  {
    v7 = ppData;
    v8 = (char *)pHandles - (char *)ppData;
    do
    {
      if ( *(void **)((char *)v7 + v8) != nullptr )
      {
        v9 = (void **)CDataManagerBase::LockResourceReturnCount(
                        this: this->m_LRU,
                        pCount: &nLockCount,
                        handle: *(memhandle_t__ **)((char *)v7 + v8));
        if ( v9 != nullptr )
        {
          if ( nLockCount == 1 )
          {
            v10 = (unsigned int)v9[1];
            ++this->m_status.nItemsLocked;
            m_pSharedCache = this->m_pSharedCache;
            this->m_status.nBytesLocked += v10;
            _InterlockedExchangeAdd((volatile signed __int32 *)&m_pSharedCache->m_status.nBytesLocked, v10);
            _InterlockedExchangeAdd((volatile signed __int32 *)&this->m_pSharedCache->m_status.nItemsLocked, 1u);
          }
          *v7 = *v9;
        }
        else
        {
          *v7 = nullptr;
        }
      }
      else
      {
        *v7 = nullptr;
      }
      ++v7;
      --nCount;
    }
    while ( nCount != 0 );
    m_mutex = generated_id_18.m_lock;
  }
  if ( m_mutex->m_depth-- == 1 )
    _InterlockedExchange((volatile __int32 *)m_mutex, 0);
}

//------------------------------------------------------------------------------
// Address: 0x10001CE0
// Name: public: virtual void __near * CDataCacheSection::Lock(struct memhandle_t__ __near *)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall CDataCacheSection::Lock(CDataCacheSection *this, memhandle_t__ *handle)
{
  _DWORD *v3; // eax
  unsigned int v4; // ecx

  CDataCacheSection::ForceFlushDebug(this, bFlush: g_iDontForceFlush == 0);
  if ( handle == nullptr )
    return nullptr;
  v3 = CDataManagerBase::LockResourceReturnCount(this: this->m_LRU, pCount: (int *)&handle, handle);
  if ( v3 == nullptr )
    return nullptr;
  if ( handle == (memhandle_t__ *)1 )
  {
    v4 = v3[1];
    this->m_status.nBytesLocked += v4;
    ++this->m_status.nItemsLocked;
    _InterlockedExchangeAdd((volatile signed __int32 *)&this->m_pSharedCache->m_status.nBytesLocked, v4);
    _InterlockedExchangeAdd((volatile signed __int32 *)&this->m_pSharedCache->m_status.nItemsLocked, 1u);
  }
  return (void *)*v3;
}

//------------------------------------------------------------------------------
// Address: 0x10001D60
// Name: public: virtual int CDataCacheSection::Unlock(struct memhandle_t__ __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDataCacheSection::Unlock(CDataCacheSection *this, memhandle_t__ *handle)
{
  int result; // eax
  CThreadFastMutex *m_mutex; // ebx
  int v5; // edi
  DWORD CurrentThreadId; // eax
  int v7; // ebx
  CThreadFastMutex *v8; // eax
  CDataCache *m_pSharedCache; // eax
  void (__thiscall *EnsureCapacity)(struct CDataCacheSection *, unsigned int, unsigned int); // edx

  result = 0;
  if ( handle != nullptr )
  {
    m_mutex = this->m_mutex;
    v5 = 0;
    CurrentThreadId = GetCurrentThreadId();
    if ( CurrentThreadId != m_mutex->m_ownerID
      && _InterlockedCompareExchange((volatile signed __int32 *)m_mutex, CurrentThreadId, 0) != 0 )
    {
      _mm_pause();
      CThreadFastMutex::Lock(a1: m_mutex, a2: CurrentThreadId, a3: 0);
    }
    else
    {
      ++m_mutex->m_depth;
    }
    v7 = CDataManagerBase::UnlockResource(this: this->m_LRU, handle);
    if ( v7 == 0 )
      v5 = *((_DWORD *)CDataManagerBase::GetResource_NoLockNoLRUTouch(this: &this->m_pSharedCache->m_LRU, handle) + 1);
    v8 = this->m_mutex;
    if ( v8->m_depth-- == 1 )
      _InterlockedExchange((volatile __int32 *)v8, 0);
    if ( v5 != 0 )
    {
      m_pSharedCache = this->m_pSharedCache;
      this->m_status.nBytesLocked -= v5;
      --this->m_status.nItemsLocked;
      _InterlockedExchangeAdd((volatile signed __int32 *)&m_pSharedCache->m_status.nBytesLocked, -v5);
      _InterlockedExchangeAdd((volatile signed __int32 *)&this->m_pSharedCache->m_status.nItemsLocked, 0xFFFFFFFF);
      EnsureCapacity = this->EnsureCapacity;
      ++this->m_nFrameUnlockCounter;
      EnsureCapacity(this, a2: 0, a3: 1u);
    }
    return v7;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10001E30
// Name: public: virtual void __near * CDataCacheSection::Get(struct memhandle_t__ __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall CDataCacheSection::Get(CDataCacheSection *this, memhandle_t__ *handle, bool bFrameLock)
{
  void *result; // eax
  CThreadFastMutex *m_mutex; // esi
  DWORD CurrentThreadId; // eax
  void **Resource_NoLock; // eax
  bool v8; // zf

  CDataCacheSection::ForceFlushDebug(this, bFlush: g_iDontForceFlush == 0);
  if ( handle == nullptr )
    return nullptr;
  if ( bFrameLock && this->IsFrameLocking(this) )
    return this->FrameLock(this, a2: handle);
  m_mutex = this->m_mutex;
  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != m_mutex->m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)m_mutex, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(a1: m_mutex, a2: CurrentThreadId, a3: 0);
  }
  else
  {
    ++m_mutex->m_depth;
  }
  Resource_NoLock = (void **)CDataManagerBase::GetResource_NoLock(this: this->m_LRU, handle);
  if ( Resource_NoLock == nullptr )
  {
    v8 = m_mutex->m_depth-- == 1;
    if ( v8 )
      _InterlockedExchange((volatile __int32 *)m_mutex, 0);
    return nullptr;
  }
  result = *Resource_NoLock;
  v8 = m_mutex->m_depth-- == 1;
  if ( v8 )
    _InterlockedExchange((volatile __int32 *)m_mutex, 0);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10001EF0
// Name: public: virtual void __near * CDataCacheSection::GetNoTouch(struct memhandle_t__ __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall CDataCacheSection::GetNoTouch(CDataCacheSection *this, memhandle_t__ *handle, bool bFrameLock)
{
  void *result; // eax
  CThreadFastMutex *m_mutex; // esi
  DWORD CurrentThreadId; // ecx
  void **Resource_NoLockNoLRUTouch; // eax
  bool v8; // zf

  if ( handle == nullptr )
    return nullptr;
  if ( bFrameLock && this->IsFrameLocking(this) )
    return this->FrameLock(this, a2: handle);
  m_mutex = this->m_mutex;
  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != m_mutex->m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)m_mutex, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(a1: m_mutex, a2: CurrentThreadId, a3: 0);
  }
  else
  {
    ++m_mutex->m_depth;
  }
  Resource_NoLockNoLRUTouch = (void **)CDataManagerBase::GetResource_NoLockNoLRUTouch(this: this->m_LRU, handle);
  if ( Resource_NoLockNoLRUTouch == nullptr )
  {
    v8 = m_mutex->m_depth-- == 1;
    if ( v8 )
      _InterlockedExchange((volatile __int32 *)m_mutex, 0);
    return nullptr;
  }
  result = *Resource_NoLockNoLRUTouch;
  v8 = m_mutex->m_depth-- == 1;
  if ( v8 )
    _InterlockedExchange((volatile __int32 *)m_mutex, 0);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10001FA0
// Name: public: virtual int CDataCacheSection::BeginFrameLocking(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDataCacheSection::BeginFrameLocking(CDataCacheSection *this)
{
  CDataCacheSection::FrameLock_t *v2; // eax
  CTSSimpleList<CDataCacheSection::FrameLock_t> *p_m_FreeFrameLocks; // edi
  CDataCacheSection::FrameLock_t *Next; // esi
  int DepthAndSequence; // eax
  int nThreadID; // [esp+4h] [ebp-8h]

  nThreadID = (int)GenericThreadLocals::CThreadLocalBase::Get(this: (GenericThreadLocals::CThreadLocalBase *)g_nThreadID.m_index);
  v2 = this->m_FrameLocks[nThreadID];
  if ( v2 != nullptr )
  {
    return ++v2->m_iLock;
  }
  else
  {
    p_m_FreeFrameLocks = &this->m_FreeFrameLocks;
    while ( 1 )
    {
      Next = (CDataCacheSection::FrameLock_t *)p_m_FreeFrameLocks->m_Head.value.Next;
      DepthAndSequence = p_m_FreeFrameLocks->m_Head.value32.DepthAndSequence;
      if ( p_m_FreeFrameLocks->m_Head.value.Next != nullptr )
      {
        while ( (unsigned __int8)_ThreadInterlockedAssignIf64(
                                   a1: p_m_FreeFrameLocks,
                                   a2: Next->m_iLock,
                                   a3: DepthAndSequence - 1,
                                   a4: Next,
                                   a5: DepthAndSequence) == 0 )
        {
          _mm_pause();
          Next = (CDataCacheSection::FrameLock_t *)p_m_FreeFrameLocks->m_Head.value.Next;
          DepthAndSequence = p_m_FreeFrameLocks->m_Head.value32.DepthAndSequence;
          if ( p_m_FreeFrameLocks->m_Head.value.Next == nullptr )
            goto LABEL_7;
        }
      }
      else
      {
LABEL_7:
        Next = nullptr;
      }
      if ( Next != nullptr )
        break;
      _mm_pause();
      _ThreadSleep(a1: 1);
    }
    Next->m_iLock = 1;
    Next->m_pFirst = nullptr;
    this->m_FrameLocks[nThreadID] = Next;
    return Next->m_iLock;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10002050
// Name: public: virtual bool CDataCacheSection::IsFrameLocking(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDataCacheSection::IsFrameLocking(CDataCacheSection *this)
{
  return this->m_FrameLocks[(_DWORD)GenericThreadLocals::CThreadLocalBase::Get(this: (GenericThreadLocals::CThreadLocalBase *)g_nThreadID.m_index)] != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10002070
// Name: public: virtual void __near * CDataCacheSection::FrameLock(struct memhandle_t__ __near *)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall CDataCacheSection::FrameLock(CDataCacheSection *this, memhandle_t__ *handle)
{
  const void *pItemData; // edi
  CDataCacheSection::FrameLock_t *v4; // ebx
  DataCacheItem_t *v5; // edi
  int m_iThread; // eax

  CDataCacheSection::ForceFlushDebug(this, bFlush: g_iDontForceFlush == 0);
  pItemData = nullptr;
  v4 = this->m_FrameLocks[(_DWORD)GenericThreadLocals::CThreadLocalBase::Get(this: (GenericThreadLocals::CThreadLocalBase *)g_nThreadID.m_index)];
  if ( v4 == nullptr )
    return (void *)pItemData;
  v5 = (DataCacheItem_t *)CDataManagerBase::LockResource(this: this->m_LRU, handle);
  if ( v5 != nullptr )
  {
    m_iThread = v4->m_iThread;
    if ( v5->pNextFrameLocked[m_iThread] == (DataCacheItem_t *)-1 )
    {
      v5->pNextFrameLocked[m_iThread] = v4->m_pFirst;
      v4->m_pFirst = v5;
      this->Lock(this, a2: handle);
    }
    pItemData = v5->pItemData;
    CDataManagerBase::UnlockResource(this: this->m_LRU, handle);
    return (void *)pItemData;
  }
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10002100
// Name: public: virtual int CDataCacheSection::EndFrameLocking(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDataCacheSection::EndFrameLocking(CDataCacheSection *this)
{
  int v2; // eax
  CDataCacheSection::FrameLock_t *v3; // edi
  CThreadFastMutex *m_mutex; // ebx
  DWORD CurrentThreadId; // eax
  DataCacheItem_t *m_pFirst; // eax
  int m_iThread; // ebx
  DataCacheItem_t *v8; // edi
  int result; // eax
  int nThread; // [esp+8h] [ebp-10h]
  CAutoLockT<CThreadFastMutex> generated_id_21; // [esp+Ch] [ebp-Ch]
  CDataCacheSection::FrameLock_t *pFrameLock; // [esp+10h] [ebp-8h]

  v2 = (int)GenericThreadLocals::CThreadLocalBase::Get(this: (GenericThreadLocals::CThreadLocalBase *)g_nThreadID.m_index);
  v3 = this->m_FrameLocks[v2];
  nThread = v2;
  pFrameLock = v3;
  if ( v3->m_iLock == 1 )
  {
    if ( v3->m_pFirst != nullptr )
    {
      m_mutex = this->m_mutex;
      generated_id_21.m_lock = m_mutex;
      CurrentThreadId = GetCurrentThreadId();
      if ( CurrentThreadId != m_mutex->m_ownerID
        && _InterlockedCompareExchange((volatile signed __int32 *)m_mutex, CurrentThreadId, 0) != 0 )
      {
        _mm_pause();
        CThreadFastMutex::Lock(a1: m_mutex, a2: CurrentThreadId, a3: 0);
      }
      else
      {
        ++m_mutex->m_depth;
      }
      m_pFirst = v3->m_pFirst;
      m_iThread = v3->m_iThread;
      if ( m_pFirst != nullptr )
      {
        do
        {
          v8 = m_pFirst->pNextFrameLocked[m_iThread];
          m_pFirst->pNextFrameLocked[m_iThread] = (DataCacheItem_t *)-1;
          this->Unlock(this, a2: m_pFirst->hLRU);
          m_pFirst = v8;
        }
        while ( v8 != nullptr );
        v3 = pFrameLock;
      }
      if ( generated_id_21.m_lock->m_depth-- == 1 )
        _InterlockedExchange((volatile __int32 *)generated_id_21.m_lock, 0);
    }
    CTSListBase::Push(this: &this->m_FreeFrameLocks, pNode: (TSLNodeBase_t *)v3);
    this->m_FrameLocks[nThread] = nullptr;
    return 0;
  }
  else
  {
    result = v3->m_iLock - 1;
    v3->m_iLock = result;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100021E0
// Name: public: virtual int CDataCacheSection::GetLockCount(struct memhandle_t__ __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDataCacheSection::GetLockCount(CDataCacheSection *this, memhandle_t__ *handle)
{
  return CDataManagerBase::LockCount(this: this->m_LRU, handle);
}

//------------------------------------------------------------------------------
// Address: 0x100021F0
// Name: public: virtual void CDataCacheSection::UpdateSize(struct memhandle_t__ __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDataCacheSection::UpdateSize(CDataCacheSection *this, memhandle_t__ *handle, unsigned int nNewSize)
{
  _DWORD *v4; // eax
  unsigned int v5; // ecx
  unsigned int v6; // edi
  CDataCache *m_pSharedCache; // eax
  unsigned int oldSize; // [esp+4h] [ebp-4h]

  v4 = CDataManagerBase::LockResource(this: this->m_LRU, handle);
  if ( v4 != nullptr )
  {
    v5 = v4[1];
    oldSize = v5;
    if ( v5 != nNewSize )
    {
      v6 = nNewSize - v5;
      v4[1] = nNewSize;
      if ( (int)(nNewSize - v5) > 0 )
      {
        CDataManagerBase::EnsureCapacity(this: &this->m_pSharedCache->m_LRU, size: v6);
        v5 = oldSize;
      }
      CDataManagerBase::NotifySizeChanged(this: this->m_LRU, handle, oldSize: v5, newSize: nNewSize);
      m_pSharedCache = this->m_pSharedCache;
      this->m_status.nBytes += v6;
      this->m_status.nBytesLocked += v6;
      _InterlockedExchangeAdd((volatile signed __int32 *)&m_pSharedCache->m_status, v6);
      _InterlockedExchangeAdd((volatile signed __int32 *)&this->m_pSharedCache->m_status.nBytesLocked, v6);
    }
    CDataManagerBase::UnlockResource(this: this->m_LRU, handle);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10002280
// Name: private: bool CDataCacheSection::DiscardItem(struct memhandle_t__ __near *,enum DataCacheNotificationType_t)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDataCacheSection::DiscardItem(
        CDataCacheSection *this,
        memhandle_t__ *hItem,
        DataCacheNotificationType_t type)
{
  memhandle_t__ *v3; // ebx
  DataCacheItem_t *Resource_NoLockNoLRUTouch; // edi
  unsigned int size; // eax
  CDataCache *m_pSharedCache; // ecx
  CDataCacheSection::FrameLock_t *v8; // eax
  int m_iThread; // edx
  DataCacheItem_t *v10; // ebx
  DataCacheItem_t *m_pFirst; // ecx
  DataCacheItem_t *v12; // eax
  DataCacheItem_t *v13; // ecx

  v3 = hItem;
  Resource_NoLockNoLRUTouch = (DataCacheItem_t *)CDataManagerBase::GetResource_NoLockNoLRUTouch(
                                                   this: &this->m_pSharedCache->m_LRU,
                                                   handle: hItem);
  if ( CDataCacheSection::DiscardItemData(this, pItem: Resource_NoLockNoLRUTouch, type) == 0 )
    return 0;
  if ( CDataManagerBase::LockCount(this: this->m_LRU, handle: hItem) != 0 )
  {
    CDataManagerBase::BreakLock(this: this->m_LRU, handle: hItem);
    size = Resource_NoLockNoLRUTouch->size;
    m_pSharedCache = this->m_pSharedCache;
    this->m_status.nBytesLocked -= size;
    --this->m_status.nItemsLocked;
    _InterlockedExchangeAdd((volatile signed __int32 *)&m_pSharedCache->m_status.nBytesLocked, -size);
    _InterlockedExchangeAdd((volatile signed __int32 *)&this->m_pSharedCache->m_status.nItemsLocked, 0xFFFFFFFF);
    ++this->m_nFrameUnlockCounter;
  }
  v8 = this->m_FrameLocks[(_DWORD)GenericThreadLocals::CThreadLocalBase::Get(this: (GenericThreadLocals::CThreadLocalBase *)g_nThreadID.m_index)];
  if ( v8 != nullptr )
  {
    m_iThread = v8->m_iThread;
    v10 = Resource_NoLockNoLRUTouch->pNextFrameLocked[m_iThread];
    if ( v10 != (DataCacheItem_t *)-1 )
    {
      m_pFirst = v8->m_pFirst;
      if ( m_pFirst == Resource_NoLockNoLRUTouch )
      {
        v8->m_pFirst = v10;
      }
      else
      {
        v12 = v8->m_pFirst;
        if ( m_pFirst != nullptr )
        {
          while ( 1 )
          {
            v13 = v12->pNextFrameLocked[m_iThread];
            if ( v13 == Resource_NoLockNoLRUTouch )
              break;
            v12 = v12->pNextFrameLocked[m_iThread];
            if ( v13 == nullptr )
              goto LABEL_13;
          }
          v12->pNextFrameLocked[m_iThread] = v10;
        }
      }
LABEL_13:
      Resource_NoLockNoLRUTouch->pNextFrameLocked[m_iThread] = (DataCacheItem_t *)-1;
    }
    v3 = hItem;
  }
  Resource_NoLockNoLRUTouch->pSection = nullptr;
  CDataManagerBase::DestroyResource(this: this->m_LRU, handle: v3);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10002380
// Name: public: virtual void CDataCache::SetOptions(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDataCache::SetOptions(CDataCache *this, unsigned int options)
{
  int v3; // edi

  if ( this->m_Sections.m_Size != 0 )
  {
    v3 = 0;
    do
    {
      this->m_Sections.m_Memory.m_pMemory[v3]->SetOptions(this: this->m_Sections.m_Memory.m_pMemory[v3], a2: options);
      ++v3;
    }
    while ( this->m_Sections.m_Size != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x100023C0
// Name: private: void CDataCache::OutputItemReport(struct memhandle_t__ __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDataCache::OutputItemReport(CDataCache *this, memhandle_t__ *hItem, void *pXboxData)
{
  CThreadFastMutex *m_mutex; // edi
  DWORD CurrentThreadId; // ecx
  _DWORD *Resource_NoLockNoLRUTouch; // eax
  _DWORD *v7; // esi
  bool v8; // zf
  _DWORD **v9; // ebx
  int v10; // eax
  char *m_szBuf; // eax
  char *v12; // ecx
  const char *v13; // eax
  float value; // [esp+18h] [ebp-340h]
  const char *v15; // [esp+24h] [ebp-334h]
  int v16; // [esp+28h] [ebp-330h]
  int v17; // [esp+2Ch] [ebp-32Ch]
  int v18; // [esp+30h] [ebp-328h]
  const char *v19; // [esp+34h] [ebp-324h]
  const char *v20; // [esp+38h] [ebp-320h]
  CFmtStrN<256> v21; // [esp+48h] [ebp-310h] BYREF
  char name[512]; // [esp+154h] [ebp-204h] BYREF
  CDataManagerBase *p_m_LRU; // [esp+354h] [ebp-4h]

  m_mutex = this->m_mutex;
  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != m_mutex->m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)m_mutex, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(a1: m_mutex, a2: CurrentThreadId, a3: 0);
  }
  else
  {
    ++m_mutex->m_depth;
  }
  p_m_LRU = &this->m_LRU;
  Resource_NoLockNoLRUTouch = CDataManagerBase::GetResource_NoLockNoLRUTouch(this: &this->m_LRU, handle: hItem);
  v7 = Resource_NoLockNoLRUTouch;
  if ( Resource_NoLockNoLRUTouch != nullptr )
  {
    v9 = (_DWORD **)Resource_NoLockNoLRUTouch[3];
    name[0] = 0;
    (*(void (__thiscall **)(_DWORD *, _DWORD, _DWORD, char *, int))(*v9[45] + 8))(
      a1: v9[45],
      a2: Resource_NoLockNoLRUTouch[2],
      a3: *Resource_NoLockNoLRUTouch,
      a4: name,
      a5: 511);
    if ( CDataManagerBase::LockCount(this: p_m_LRU, handle: hItem) != 0 )
    {
      v10 = CDataManagerBase::LockCount(this: p_m_LRU, handle: hItem);
      m_szBuf = CFmtStrN<256>::CFmtStrN<256>(this: &v21, pszFormat: "Locked %d", v10)->m_szBuf;
    }
    else
    {
      m_szBuf = (char *)defaultValue;
    }
    v12 = name;
    if ( name[0] == 0 )
      v12 = "unknown";
    v15 = (const char *)((int (__thiscall *)(_DWORD **, _DWORD, _DWORD, memhandle_t__ *, char *, char *))(*v9)[2])(
                          a1: v9,
                          a2: v7[2],
                          a3: *v7,
                          a4: hItem,
                          a5: v12,
                          a6: m_szBuf);
    value = (float)(unsigned int)v7[1];
    v13 = V_pretifymem(value, digitsafterdecimal: 2, usebinaryonek: true);
    _Msg(a1: "\t%16.16s : %12s : 0x%08x, 0x%08x, 0x%08x : %s : %s\n", v13, v15, v16, v17, v18, v19, v20);
    v8 = m_mutex->m_depth-- == 1;
    if ( v8 )
      _InterlockedExchange((volatile __int32 *)m_mutex, 0);
  }
  else
  {
    v8 = m_mutex->m_depth-- == 1;
    if ( v8 )
      _InterlockedExchange((volatile __int32 *)m_mutex, 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10002510
// Name: private: int CDataCache::FindSectionIndex(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDataCache::FindSectionIndex(CDataCache *this, const char *pszSection)
{
  int v3; // esi
  CDataCacheSection *v4; // ecx
  const char *v5; // eax

  v3 = 0;
  if ( this->m_Sections.m_Size <= 0 )
    return -1;
  while ( 1 )
  {
    v4 = this->m_Sections.m_Memory.m_pMemory[v3];
    v5 = v4->GetName(this: v4);
    if ( _V_stricmp(s1: v5, s2: pszSection) == 0 )
      break;
    if ( ++v3 >= this->m_Sections.m_Size )
      return -1;
  }
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x10002560
// Name: private: static bool CDataCache::SortMemhandlesBySizeLessFunc(struct memhandle_t__ __near * const __near &,struct memhandle_t__ __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl CDataCache::SortMemhandlesBySizeLessFunc(memhandle_t__ **lhs, memhandle_t__ **rhs)
{
  _DWORD *Resource_NoLockNoLRUTouch; // esi

  Resource_NoLockNoLRUTouch = CDataManagerBase::GetResource_NoLockNoLRUTouch(this: &g_DataCache.m_LRU, handle: *lhs);
  return Resource_NoLockNoLRUTouch[1] < *((_DWORD *)CDataManagerBase::GetResource_NoLockNoLRUTouch(
                                                      this: &g_DataCache.m_LRU,
                                                      handle: *rhs)
                                        + 1);
}

//------------------------------------------------------------------------------
// Address: 0x100025A0
// Name: public: virtual char const __near * CDataCache::GetSectionName(int)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CDataCache::GetSectionName(CDataCache *this, int iIndex)
{
  CDataCacheSection *v2; // ecx

  if ( iIndex < 0 || iIndex >= this->m_Sections.m_Size )
    return defaultValue;
  v2 = this->m_Sections.m_Memory.m_pMemory[iIndex];
  return v2->GetName(this: v2);
}

//------------------------------------------------------------------------------
// Address: 0x100025D0
// Name: public: struct memhandle_t__ __near * CDataManager<struct DataCacheItem_t,struct DataCacheItemData_t,struct DataCacheItem_t __near *,class CThreadFastMutex>::CreateResource(struct DataCacheItemData_t const __near &,bool)
// Source: json
//------------------------------------------------------------------------------
memhandle_t__ *__thiscall CDataManager<DataCacheItem_t,DataCacheItemData_t,DataCacheItem_t *,CThreadFastMutex>::CreateResource(
        CDataManager<DataCacheItem_t,DataCacheItemData_t,DataCacheItem_t *,CThreadFastMutex> *this,
        const DataCacheItemData_t *createParams,
        bool bCreateLocked)
{
  DataCacheItemData_t *v4; // eax
  unsigned int *v5; // edi
  unsigned __int16 Handle; // ax
  memhandle_t__ *v7; // edi

  CDataManagerBase::EnsureCapacity(this, size: createParams->size);
  v4 = (DataCacheItemData_t *)DataCacheItem_t::operator new(size: 0x2Cu);
  if ( v4 != nullptr )
  {
    *v4 = *createParams;
    v4[1].pItemData = (const void *)-1;
    v4[1].size = -1;
    v4[1].clientId = -1;
    v4[1].pSection = (CDataCacheSection *)-1;
    v4[2].pItemData = (const void *)-1;
    v4[2].size = -1;
    v4[2].clientId = -1;
    v5 = (unsigned int *)v4;
  }
  else
  {
    v5 = nullptr;
  }
  this->Lock(this);
  Handle = CDataManagerBase::CreateHandle(this, bCreateLocked);
  v7 = CDataManagerBase::StoreResourceInHandle(this, memoryIndex: Handle, pStore: v5, realSize: v5[1]);
  this->Unlock(this);
  return v7;
}

//------------------------------------------------------------------------------
// Address: 0x10002F60
// Name: public: virtual bool CDataCacheSection::AddEx(unsigned int,void const __near *,unsigned int,unsigned int,struct memhandle_t__ __near * __near *)
// Source: json
//------------------------------------------------------------------------------
char __userpurge CDataCacheSection::AddEx@<al>(
        CDataCacheSection *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>,
        unsigned int clientId,
        const void *pItemData,
        unsigned int size,
        char flags,
        memhandle_t__ **pHandle)
{
  CDataManager<DataCacheItem_t,DataCacheItemData_t,DataCacheItem_t *,CThreadFastMutex> *m_LRU; // ecx
  memhandle_t__ *v11; // edi
  CDataCache *m_pSharedCache; // eax
  CDataManager<DataCacheItem_t,DataCacheItemData_t,DataCacheItem_t *,CThreadFastMutex> *v13; // ecx
  DataCacheItemData_t itemData; // [esp+4h] [ebp-10h] BYREF

  CDataCacheSection::ForceFlushDebug(this, bFlush: true);
  if ( (this->m_options & 8) != 0 && this->Find(this, a2: clientId) != nullptr )
  {
    _Error(a1: "Duplicate add to data cache\n");
    return 0;
  }
  else
  {
    ((void (__thiscall *)(CDataCacheSection *, unsigned int, int, int, int))this->EnsureCapacity)(
      a1: this,
      a2: size,
      a3: 1,
      a4: a3,
      a5: a2);
    itemData.clientId = clientId;
    m_LRU = this->m_LRU;
    itemData.pItemData = pItemData;
    itemData.size = size;
    itemData.pSection = this;
    v11 = CDataManager<DataCacheItem_t,DataCacheItemData_t,DataCacheItem_t *,CThreadFastMutex>::CreateResource(
            this: m_LRU,
            createParams: &itemData,
            bCreateLocked: true);
    *((_DWORD *)CDataManagerBase::GetResource_NoLockNoLRUTouch(this: &this->m_pSharedCache->m_LRU, handle: v11) + 4) = v11;
    if ( pHandle != nullptr )
      *pHandle = v11;
    m_pSharedCache = this->m_pSharedCache;
    this->m_status.nBytes += size;
    ++this->m_status.nItems;
    _InterlockedExchangeAdd((volatile signed __int32 *)&m_pSharedCache->m_status, size);
    _InterlockedExchangeAdd((volatile signed __int32 *)&this->m_pSharedCache->m_status.nItems, 1u);
    ((void (__thiscall *)(CDataCacheSection *, unsigned int))this->OnAdd)(a1: this, a2: clientId);
    ++g_iDontForceFlush;
    if ( (flags & 1) != 0 )
      this->Lock(this, a2: v11);
    ((void (__thiscall *)(CDataCacheSection *))this->FrameLock)(a1: this);
    v13 = this->m_LRU;
    --g_iDontForceFlush;
    CDataManagerBase::UnlockResource(this: v13, handle: v11);
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10003070
// Name: public: virtual enum DataCacheRemoveResult_t CDataCacheSection::Remove(struct memhandle_t__ __near *,void const __near * __near *,unsigned int __near *,bool)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDataCacheSection::Remove(
        CDataCacheSection *this,
        memhandle_t__ *handle,
        const void **ppItemData,
        unsigned int *pItemSize,
        bool bNotify)
{
  memhandle_t__ *v5; // ebx
  CThreadFastMutex *m_mutex; // esi
  DWORD CurrentThreadId; // ecx
  const void **Resource_NoLockNoLRUTouch; // eax
  bool v11; // zf

  v5 = handle;
  if ( handle == nullptr )
    return 1;
  if ( CDataManagerBase::LockCount(this: this->m_LRU, handle) > 0 )
    return 2;
  m_mutex = this->m_mutex;
  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId == m_mutex->m_ownerID )
    goto LABEL_7;
  if ( _InterlockedCompareExchange((volatile signed __int32 *)m_mutex, CurrentThreadId, 0) == 0 )
  {
    v5 = handle;
LABEL_7:
    ++m_mutex->m_depth;
    goto LABEL_9;
  }
  _mm_pause();
  CThreadFastMutex::Lock(a1: m_mutex, a2: CurrentThreadId, a3: 0);
  v5 = handle;
LABEL_9:
  Resource_NoLockNoLRUTouch = (const void **)CDataManagerBase::GetResource_NoLockNoLRUTouch(
                                               this: &this->m_pSharedCache->m_LRU,
                                               handle: v5);
  if ( Resource_NoLockNoLRUTouch == nullptr )
  {
    v11 = m_mutex->m_depth-- == 1;
    if ( v11 )
      _InterlockedExchange((volatile __int32 *)m_mutex, 0);
    return 1;
  }
  if ( ppItemData != nullptr )
    *ppItemData = *Resource_NoLockNoLRUTouch;
  if ( pItemSize != nullptr )
    *pItemSize = (unsigned int)Resource_NoLockNoLRUTouch[1];
  CDataCacheSection::DiscardItem(this, hItem: v5, type: bNotify ? DC_REMOVED : DC_NONE);
  v11 = m_mutex->m_depth-- == 1;
  if ( v11 )
    _InterlockedExchange((volatile __int32 *)m_mutex, 0);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10003170
// Name: public: virtual void CDataCache::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDataCache::Shutdown(CDataCache *this)
{
  this->Flush(this, a2: false, a3: false);
  if ( g_pCVar != nullptr )
    ConVar_Unregister();
}

//------------------------------------------------------------------------------
// Address: 0x10003190
// Name: public: virtual void CDataCache::RemoveSection(char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDataCache::RemoveSection(CDataCache *this, const char *pszClientName, bool bCallFlush)
{
  int SectionIndex; // eax
  int v5; // edi
  CDataCacheSection *v6; // ecx
  CDataCacheSection *v7; // ecx
  int m_Size; // ecx

  SectionIndex = CDataCache::FindSectionIndex(this, pszSection: pszClientName);
  v5 = SectionIndex;
  if ( SectionIndex != -1 )
  {
    if ( bCallFlush )
    {
      v6 = this->m_Sections.m_Memory.m_pMemory[SectionIndex];
      v6->Flush(this: v6, a2: false, a3: true);
    }
    v7 = this->m_Sections.m_Memory.m_pMemory[v5];
    if ( v7 != nullptr )
      ((void (__thiscall *)(CDataCacheSection *, int))v7->dtr_IDataCacheSection)(a1: v7, a2: 1);
    m_Size = this->m_Sections.m_Size;
    if ( m_Size > 0 )
    {
      if ( v5 != m_Size - 1 )
        this->m_Sections.m_Memory.m_pMemory[v5] = this->m_Sections.m_Memory.m_pMemory[m_Size - 1];
      --this->m_Sections.m_Size;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10003200
// Name: public: virtual class IDataCacheSection __near * CDataCache::FindSection(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDataCacheSection *__thiscall CDataCache::FindSection(CDataCache *this, const char *pszClientName)
{
  int SectionIndex; // eax

  SectionIndex = CDataCache::FindSectionIndex(this, pszSection: pszClientName);
  if ( SectionIndex == -1 )
    return nullptr;
  else
    return this->m_Sections.m_Memory.m_pMemory[SectionIndex];
}

//------------------------------------------------------------------------------
// Address: 0x10003230
// Name: public: struct memhandle_t__ __near * CDataManager<struct DataCacheItem_t,struct DataCacheItemData_t,struct DataCacheItem_t __near *,class CThreadFastMutex>::GetNext(struct memhandle_t__ __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDataManager<DataCacheItem_t,DataCacheItemData_t,DataCacheItem_t *,CThreadFastMutex>::GetNext(
        CDataManager<DataCacheItem_t,DataCacheItemData_t,DataCacheItem_t *,CThreadFastMutex> *this,
        memhandle_t__ *hPrev)
{
  __int16 v3; // dx
  int v4; // eax
  CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::ListElem_t *m_pMemory; // edi
  int v6; // eax
  bool v7; // zf
  unsigned __int16 v8; // ax
  unsigned __int16 m_Next; // ax

  if ( hPrev == (memhandle_t__ *)-1 )
    return -1;
  v3 = (_WORD)hPrev - 1;
  v4 = (unsigned __int16)((_WORD)hPrev - 1);
  if ( v4 >= this->m_memoryLists.m_MaxElementIndex
    || (m_pMemory = this->m_memoryLists.m_Memory.m_pMemory, v6 = v4, m_pMemory[v6].m_Previous == v3)
    && m_pMemory[v6].m_Next != v3
    || (v7 = m_pMemory[v6].m_Element.serial == HIWORD(hPrev), v8 = (_WORD)hPrev - 1, !v7) )
  {
    v8 = -1;
  }
  m_Next = this->m_memoryLists.m_Memory.m_pMemory[v8].m_Next;
  if ( m_Next == 0xFFFF )
    return -1;
  else
    return (int)CDataManagerBase::ToHandle(this, index: m_Next);
}

//------------------------------------------------------------------------------
// Address: 0x10003AA0
// Name: private: struct memhandle_t__ __near * CDataCacheSection::GetFirstUnlockedItem(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDataCacheSection::GetFirstUnlockedItem(CDataCacheSection *this)
{
  CDataManager<DataCacheItem_t,DataCacheItemData_t,DataCacheItem_t *,CThreadFastMutex> *m_LRU; // ecx
  UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short> *m_pMemory; // edx
  memhandle_t__ *v4; // esi
  CDataManager<DataCacheItem_t,DataCacheItemData_t,DataCacheItem_t *,CThreadFastMutex> *v5; // ecx
  int v6; // edx
  unsigned int v7; // edi
  CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::ListElem_t *v8; // esi
  int v9; // eax
  bool v10; // zf
  unsigned __int16 v11; // ax
  unsigned __int16 m_Next; // ax

  m_LRU = this->m_LRU;
  m_pMemory = m_LRU->m_memoryLists.m_List.m_Memory.m_pMemory;
  if ( m_pMemory[m_LRU->m_lruList].m_Element.m_Head == 0xFFFF )
    return -1;
  v4 = CDataManagerBase::ToHandle(this: m_LRU, index: m_pMemory[m_LRU->m_lruList].m_Element.m_Head);
  if ( v4 == (memhandle_t__ *)-1 )
    return -1;
  while ( *((CDataCacheSection **)CDataManagerBase::GetResource_NoLockNoLRUTouch(
                                    this: &this->m_pSharedCache->m_LRU,
                                    handle: v4)
          + 3) != this )
  {
    v5 = this->m_LRU;
    v6 = (unsigned __int16)((_WORD)v4 - 1);
    v7 = (unsigned int)v4 >> 16;
    if ( v6 >= v5->m_memoryLists.m_MaxElementIndex
      || (v8 = v5->m_memoryLists.m_Memory.m_pMemory, v9 = v6, v8[v6].m_Previous == (_WORD)v6)
      && v8[v9].m_Next != (_WORD)v6
      || (v10 = v8[v9].m_Element.serial == (unsigned __int16)v7, v11 = v6, !v10) )
    {
      v11 = -1;
    }
    m_Next = v5->m_memoryLists.m_Memory.m_pMemory[v11].m_Next;
    if ( m_Next != 0xFFFF )
    {
      v4 = CDataManagerBase::ToHandle(this: v5, index: m_Next);
      if ( v4 != (memhandle_t__ *)-1 )
        continue;
    }
    return -1;
  }
  return (int)v4;
}

//------------------------------------------------------------------------------
// Address: 0x10003B50
// Name: private: struct memhandle_t__ __near * CDataCacheSection::GetFirstLockedItem(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDataCacheSection::GetFirstLockedItem(CDataCacheSection *this)
{
  CDataManager<DataCacheItem_t,DataCacheItemData_t,DataCacheItem_t *,CThreadFastMutex> *m_LRU; // ecx
  UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short> *m_pMemory; // edx
  memhandle_t__ *v4; // esi
  CDataManager<DataCacheItem_t,DataCacheItemData_t,DataCacheItem_t *,CThreadFastMutex> *v5; // ecx
  int v6; // edx
  unsigned int v7; // edi
  CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::ListElem_t *v8; // esi
  int v9; // eax
  bool v10; // zf
  unsigned __int16 v11; // ax
  unsigned __int16 m_Next; // ax

  m_LRU = this->m_LRU;
  m_pMemory = m_LRU->m_memoryLists.m_List.m_Memory.m_pMemory;
  if ( m_pMemory[m_LRU->m_lockList].m_Element.m_Head == 0xFFFF )
    return -1;
  v4 = CDataManagerBase::ToHandle(this: m_LRU, index: m_pMemory[m_LRU->m_lockList].m_Element.m_Head);
  if ( v4 == (memhandle_t__ *)-1 )
    return -1;
  while ( *((CDataCacheSection **)CDataManagerBase::GetResource_NoLockNoLRUTouch(
                                    this: &this->m_pSharedCache->m_LRU,
                                    handle: v4)
          + 3) != this )
  {
    v5 = this->m_LRU;
    v6 = (unsigned __int16)((_WORD)v4 - 1);
    v7 = (unsigned int)v4 >> 16;
    if ( v6 >= v5->m_memoryLists.m_MaxElementIndex
      || (v8 = v5->m_memoryLists.m_Memory.m_pMemory, v9 = v6, v8[v6].m_Previous == (_WORD)v6)
      && v8[v9].m_Next != (_WORD)v6
      || (v10 = v8[v9].m_Element.serial == (unsigned __int16)v7, v11 = v6, !v10) )
    {
      v11 = -1;
    }
    m_Next = v5->m_memoryLists.m_Memory.m_pMemory[v11].m_Next;
    if ( m_Next != 0xFFFF )
    {
      v4 = CDataManagerBase::ToHandle(this: v5, index: m_Next);
      if ( v4 != (memhandle_t__ *)-1 )
        continue;
    }
    return -1;
  }
  return (int)v4;
}

//------------------------------------------------------------------------------
// Address: 0x10003C00
// Name: private: struct memhandle_t__ __near * CDataCacheSection::GetNextItem(struct memhandle_t__ __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDataCacheSection::GetNextItem(CDataCacheSection *this, memhandle_t__ *hCurrent)
{
  memhandle_t__ *Next; // esi
  CDataManager<DataCacheItem_t,DataCacheItemData_t,DataCacheItem_t *,CThreadFastMutex> *m_LRU; // ecx
  int v5; // edx
  unsigned int v6; // edi
  CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::ListElem_t *m_pMemory; // esi
  int v8; // eax
  bool v9; // zf
  unsigned __int16 v10; // ax
  unsigned __int16 m_Next; // ax

  Next = (memhandle_t__ *)CDataManager<DataCacheItem_t,DataCacheItemData_t,DataCacheItem_t *,CThreadFastMutex>::GetNext(
                            this: this->m_LRU,
                            hPrev: hCurrent);
  if ( Next == (memhandle_t__ *)-1 )
    return -1;
  while ( *((CDataCacheSection **)CDataManagerBase::GetResource_NoLockNoLRUTouch(
                                    this: &this->m_pSharedCache->m_LRU,
                                    handle: Next)
          + 3) != this )
  {
    m_LRU = this->m_LRU;
    v5 = (unsigned __int16)((_WORD)Next - 1);
    v6 = (unsigned int)Next >> 16;
    if ( v5 >= m_LRU->m_memoryLists.m_MaxElementIndex
      || (m_pMemory = m_LRU->m_memoryLists.m_Memory.m_pMemory, v8 = v5, m_pMemory[v5].m_Previous == (_WORD)v5)
      && m_pMemory[v8].m_Next != (_WORD)v5
      || (v9 = m_pMemory[v8].m_Element.serial == (unsigned __int16)v6, v10 = v5, !v9) )
    {
      v10 = -1;
    }
    m_Next = m_LRU->m_memoryLists.m_Memory.m_pMemory[v10].m_Next;
    if ( m_Next != 0xFFFF )
    {
      Next = CDataManagerBase::ToHandle(this: m_LRU, index: m_Next);
      if ( Next != (memhandle_t__ *)-1 )
        continue;
    }
    return -1;
  }
  return (int)Next;
}

//------------------------------------------------------------------------------
// Address: 0x10003CB0
// Name: private: virtual struct memhandle_t__ __near * CDataCacheSectionFastFind::DoFind(unsigned int)
// Source: json
//------------------------------------------------------------------------------
memhandle_t__ *__thiscall CDataCacheSectionFastFind::DoFind(CDataCacheSectionFastFind *this, unsigned int clientId)
{
  CThreadFastMutex *m_mutex; // esi
  DWORD CurrentThreadId; // ecx
  unsigned int v5; // eax
  _DWORD *v6; // ecx
  bool v7; // zf
  memhandle_t__ *result; // eax

  m_mutex = this->m_mutex;
  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != m_mutex->m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)m_mutex, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(a1: m_mutex, a2: CurrentThreadId, a3: 0);
  }
  else
  {
    ++m_mutex->m_depth;
  }
  v5 = Hash4(pKey: &clientId);
  v6 = (_DWORD *)this->m_Handles.m_aBuckets.m_Memory.m_pMemory[v5 & this->m_Handles.m_uiBucketMask];
  if ( v6 == nullptr )
    goto LABEL_8;
  while ( *v6 != v5 )
  {
    v6 = (_DWORD *)v6[3];
    if ( v6 == nullptr )
      goto LABEL_8;
  }
  if ( v6 == (_DWORD *)-1 )
  {
LABEL_8:
    v7 = m_mutex->m_depth-- == 1;
    if ( v7 )
      _InterlockedExchange((volatile __int32 *)m_mutex, 0);
    return nullptr;
  }
  else
  {
    result = (memhandle_t__ *)v6[1];
    v7 = m_mutex->m_depth-- == 1;
    if ( v7 )
      _InterlockedExchange((volatile __int32 *)m_mutex, 0);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10003D50
// Name: public: virtual bool CDataCache::Connect(void __near * (*)(char const __near *,int __near *))
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDataCache::Connect(CDataCache *this, void *(__cdecl *factory)(const char *, int *))
{
  int m_nValue; // eax
  void *(__cdecl *v5)(const char *, int *); // [esp+4h] [ebp-8h] BYREF
  void *(__cdecl *pFactoryList)(const char *, int *); // [esp+8h] [ebp-4h] BYREF

  v5 = factory;
  pFactoryList = factory;
  ConnectTier1Libraries(pFactoryList: &factory, nFactoryCount: 1);
  ConnectTier2Libraries(&pFactoryList, nFactoryCount: 1);
  CDataManagerBase::Unlock(pFactoryList: &v5, nFactoryCount: 1);
  if ( datacachesize.m_pParent != nullptr )
    m_nValue = datacachesize.m_pParent->m_Value.m_nValue;
  else
    m_nValue = 0;
  CDataManagerBase::SetTargetSize(this: &g_DataCache.m_LRU, targetSize: m_nValue << 20);
  CDataManagerBase::FlushToTargetSize(this: &g_DataCache.m_LRU);
  g_pDataCache = this;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10003DC0
// Name: public: virtual void CDataCache::Disconnect(void)
// Source: json
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x10003F00
// Name: private: virtual struct memhandle_t__ __near * CDataCacheSection::DoFind(unsigned int)
// Source: json
//------------------------------------------------------------------------------
memhandle_t__ *__thiscall CDataCacheSection::DoFind(CDataCacheSection *this, unsigned int clientId)
{
  CThreadFastMutex *m_mutex; // ebx
  DWORD CurrentThreadId; // ecx
  memhandle_t__ *FirstUnlockedItem; // edi
  bool v6; // zf

  m_mutex = this->m_mutex;
  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != m_mutex->m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)m_mutex, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(a1: m_mutex, a2: CurrentThreadId, a3: 0);
  }
  else
  {
    ++m_mutex->m_depth;
  }
  FirstUnlockedItem = (memhandle_t__ *)CDataCacheSection::GetFirstUnlockedItem(this);
  if ( FirstUnlockedItem == (memhandle_t__ *)-1 )
  {
LABEL_8:
    FirstUnlockedItem = (memhandle_t__ *)CDataCacheSection::GetFirstLockedItem(this);
    if ( FirstUnlockedItem == (memhandle_t__ *)-1 )
    {
LABEL_11:
      v6 = m_mutex->m_depth-- == 1;
      if ( v6 )
        _InterlockedExchange((volatile __int32 *)m_mutex, 0);
      return nullptr;
    }
    while ( *((_DWORD *)CDataManagerBase::GetResource_NoLockNoLRUTouch(
                          this: &this->m_pSharedCache->m_LRU,
                          handle: FirstUnlockedItem)
            + 2) != clientId )
    {
      FirstUnlockedItem = (memhandle_t__ *)CDataCacheSection::GetNextItem(this, hCurrent: FirstUnlockedItem);
      if ( FirstUnlockedItem == (memhandle_t__ *)-1 )
        goto LABEL_11;
    }
  }
  else
  {
    while ( *((_DWORD *)CDataManagerBase::GetResource_NoLockNoLRUTouch(
                          this: &this->m_pSharedCache->m_LRU,
                          handle: FirstUnlockedItem)
            + 2) != clientId )
    {
      FirstUnlockedItem = (memhandle_t__ *)CDataCacheSection::GetNextItem(this, hCurrent: FirstUnlockedItem);
      if ( FirstUnlockedItem == (memhandle_t__ *)-1 )
        goto LABEL_8;
    }
  }
  ++this->m_status.nFindHits;
  v6 = m_mutex->m_depth-- == 1;
  if ( v6 )
    _InterlockedExchange((volatile __int32 *)m_mutex, 0);
  return FirstUnlockedItem;
}

//------------------------------------------------------------------------------
// Address: 0x10003FE0
// Name: public: virtual unsigned int CDataCacheSection::Flush(bool,bool)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CDataCacheSection::Flush(CDataCacheSection *this, bool bUnlockedOnly, bool bNotify)
{
  CThreadFastMutex *m_mutex; // edi
  DWORD CurrentThreadId; // ecx
  DataCacheNotificationType_t v6; // ebx
  memhandle_t__ *FirstUnlockedItem; // edi
  memhandle_t__ *FirstLockedItem; // edi
  CAutoLockT<CThreadFastMutex> generated_id_22; // [esp+Ch] [ebp-Ch]
  memhandle_t__ *hNext; // [esp+10h] [ebp-8h]
  memhandle_t__ *hNexta; // [esp+10h] [ebp-8h]
  unsigned int nBytesCurrent; // [esp+14h] [ebp-4h]
  unsigned int nBytesCurrenta; // [esp+14h] [ebp-4h]
  unsigned int nBytesFlushed; // [esp+24h] [ebp+Ch]

  m_mutex = this->m_mutex;
  generated_id_22.m_lock = m_mutex;
  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != m_mutex->m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)m_mutex, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(a1: m_mutex, a2: CurrentThreadId, a3: 0);
  }
  else
  {
    ++m_mutex->m_depth;
  }
  v6 = bNotify ? DC_FLUSH_DISCARD : DC_NONE;
  nBytesFlushed = 0;
  FirstUnlockedItem = (memhandle_t__ *)CDataCacheSection::GetFirstUnlockedItem(this);
  if ( FirstUnlockedItem != (memhandle_t__ *)-1 )
  {
    do
    {
      hNext = (memhandle_t__ *)CDataCacheSection::GetNextItem(this, hCurrent: FirstUnlockedItem);
      nBytesCurrent = *((_DWORD *)CDataManagerBase::GetResource_NoLockNoLRUTouch(
                                    this: &this->m_pSharedCache->m_LRU,
                                    handle: FirstUnlockedItem)
                      + 1);
      if ( CDataCacheSection::DiscardItem(this, hItem: FirstUnlockedItem, type: v6) != 0 )
        nBytesFlushed += nBytesCurrent;
      FirstUnlockedItem = hNext;
    }
    while ( hNext != (memhandle_t__ *)-1 );
  }
  if ( !bUnlockedOnly )
  {
    FirstLockedItem = (memhandle_t__ *)CDataCacheSection::GetFirstLockedItem(this);
    if ( FirstLockedItem != (memhandle_t__ *)-1 )
    {
      do
      {
        hNexta = (memhandle_t__ *)CDataCacheSection::GetNextItem(this, hCurrent: FirstLockedItem);
        nBytesCurrenta = *((_DWORD *)CDataManagerBase::GetResource_NoLockNoLRUTouch(
                                       this: &this->m_pSharedCache->m_LRU,
                                       handle: FirstLockedItem)
                         + 1);
        if ( CDataCacheSection::DiscardItem(this, hItem: FirstLockedItem, type: v6) != 0 )
          nBytesFlushed += nBytesCurrenta;
        FirstLockedItem = hNexta;
      }
      while ( hNexta != (memhandle_t__ *)-1 );
    }
  }
  if ( generated_id_22.m_lock->m_depth-- == 1 )
    _InterlockedExchange((volatile __int32 *)generated_id_22.m_lock, 0);
  return nBytesFlushed;
}

//------------------------------------------------------------------------------
// Address: 0x100040F0
// Name: public: virtual unsigned int CDataCacheSection::Purge(unsigned int)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CDataCacheSection::Purge(CDataCacheSection *this, unsigned int nBytes)
{
  CThreadFastMutex *m_mutex; // ebx
  DWORD CurrentThreadId; // ecx
  memhandle_t__ *FirstUnlockedItem; // esi
  unsigned int v6; // ebx
  memhandle_t__ *hNext; // [esp+Ch] [ebp-Ch]
  CAutoLockT<CThreadFastMutex> generated_id_23; // [esp+10h] [ebp-8h]
  unsigned int nBytesPurged; // [esp+14h] [ebp-4h]

  m_mutex = this->m_mutex;
  generated_id_23.m_lock = m_mutex;
  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != m_mutex->m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)m_mutex, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(a1: m_mutex, a2: CurrentThreadId, a3: 0);
  }
  else
  {
    ++m_mutex->m_depth;
  }
  nBytesPurged = 0;
  FirstUnlockedItem = (memhandle_t__ *)CDataCacheSection::GetFirstUnlockedItem(this);
  if ( FirstUnlockedItem != (memhandle_t__ *)-1 )
  {
    do
    {
      if ( nBytes == 0 )
        break;
      hNext = (memhandle_t__ *)CDataCacheSection::GetNextItem(this, hCurrent: FirstUnlockedItem);
      v6 = *((_DWORD *)CDataManagerBase::GetResource_NoLockNoLRUTouch(
                         this: &this->m_pSharedCache->m_LRU,
                         handle: FirstUnlockedItem)
           + 1);
      if ( CDataCacheSection::DiscardItem(this, hItem: FirstUnlockedItem, type: DC_FLUSH_DISCARD) != 0 )
      {
        nBytesPurged += v6;
        if ( v6 >= nBytes )
          v6 = nBytes;
        nBytes -= v6;
      }
      FirstUnlockedItem = hNext;
      m_mutex = generated_id_23.m_lock;
    }
    while ( hNext != (memhandle_t__ *)-1 );
  }
  if ( m_mutex->m_depth-- == 1 )
    _InterlockedExchange((volatile __int32 *)m_mutex, 0);
  return nBytesPurged;
}

//------------------------------------------------------------------------------
// Address: 0x100041B0
// Name: public: unsigned int CDataCacheSection::PurgeItems(unsigned int)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CDataCacheSection::PurgeItems(CDataCacheSection *this, unsigned int nItems)
{
  CThreadFastMutex *m_mutex; // ebx
  DWORD CurrentThreadId; // ecx
  memhandle_t__ *FirstUnlockedItem; // esi
  int NextItem; // ebx
  bool v7; // zf
  CAutoLockT<CThreadFastMutex> generated_id_24; // [esp+Ch] [ebp-8h]
  unsigned int nPurged; // [esp+10h] [ebp-4h]

  m_mutex = this->m_mutex;
  generated_id_24.m_lock = m_mutex;
  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != m_mutex->m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)m_mutex, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(a1: m_mutex, a2: CurrentThreadId, a3: 0);
  }
  else
  {
    ++m_mutex->m_depth;
  }
  nPurged = 0;
  FirstUnlockedItem = (memhandle_t__ *)CDataCacheSection::GetFirstUnlockedItem(this);
  if ( FirstUnlockedItem != (memhandle_t__ *)-1 )
  {
    do
    {
      if ( nItems == 0 )
        break;
      NextItem = CDataCacheSection::GetNextItem(this, hCurrent: FirstUnlockedItem);
      if ( CDataCacheSection::DiscardItem(this, hItem: FirstUnlockedItem, type: DC_FLUSH_DISCARD) != 0 )
      {
        --nItems;
        ++nPurged;
      }
      FirstUnlockedItem = (memhandle_t__ *)NextItem;
      v7 = NextItem == -1;
      m_mutex = generated_id_24.m_lock;
    }
    while ( !v7 );
  }
  v7 = m_mutex->m_depth-- == 1;
  if ( v7 )
    _InterlockedExchange((volatile __int32 *)m_mutex, 0);
  return nPurged;
}

//------------------------------------------------------------------------------
// Address: 0x100042F0
// Name: public: virtual void CDataCacheSection::EnsureCapacity(unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDataCacheSection::EnsureCapacity(CDataCacheSection *this, unsigned int nBytes, unsigned int nItems)
{
  unsigned int nMaxBytes; // ecx
  unsigned int v5; // eax
  unsigned int nMaxItems; // ecx
  unsigned int v7; // eax

  if ( this->m_limits.nMaxItems != -1 || this->m_limits.nMaxBytes != -1 )
  {
    nMaxBytes = this->m_limits.nMaxBytes;
    v5 = nBytes + this->m_status.nBytes;
    if ( v5 > nMaxBytes )
      this->Purge(this, a2: v5 - nMaxBytes);
    nMaxItems = this->m_limits.nMaxItems;
    v7 = this->m_status.nItems;
    if ( v7 >= nMaxItems )
      CDataCacheSection::PurgeItems(this, nItems: v7 - nMaxItems + 1);
  }
  CDataManagerBase::EnsureCapacity(this: &this->m_pSharedCache->m_LRU, size: nBytes);
}

//------------------------------------------------------------------------------
// Address: 0x10004360
// Name: public: virtual enum AppSystemTier_t CTier3AppSystem<class IDataCache,0>::GetTier(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CTier3AppSystem<IDataCache,0>::GetTier(CTier3AppSystem<IDataCache,0> *this)
{
  return 3;
}

//------------------------------------------------------------------------------
// Address: 0x10004370
// Name: public: CUtlHashFast<struct memhandle_t__ __near *,class CUtlHashFastNoHash>::CUtlHashFast<struct memhandle_t__ __near *,class CUtlHashFastNoHash>(void)
// Source: json
//------------------------------------------------------------------------------
CUtlHashFast<memhandle_t__ *,CUtlHashFastNoHash> *__thiscall CUtlHashFast<memhandle_t__ *,CUtlHashFastNoHash>::CUtlHashFast<memhandle_t__ *,CUtlHashFastNoHash>(
        CUtlHashFast<memhandle_t__ *,CUtlHashFastNoHash> *this)
{
  this->m_aBuckets.m_Memory.m_pMemory = nullptr;
  this->m_aBuckets.m_Memory.m_nAllocationCount = 0;
  this->m_aBuckets.m_Memory.m_nGrowSize = 0;
  this->m_aBuckets.m_pElements = nullptr;
  this->m_aDataPool.m_Memory.m_pBlocks = nullptr;
  this->m_aDataPool.m_Memory.m_nAllocationCount = 0;
  this->m_aDataPool.m_Memory.m_nGrowSize = 0;
  this->m_aDataPool.m_LastAlloc.m_pBlockHeader = nullptr;
  this->m_aDataPool.m_LastAlloc.m_nIndex = -1;
  this->m_aDataPool.m_Head = 0;
  this->m_aDataPool.m_Tail = 0;
  this->m_aDataPool.m_FirstFree = 0;
  this->m_aDataPool.m_ElementCount = 0;
  this->m_aDataPool.m_NumAlloced = 0;
  this->m_aDataPool.m_pElements = nullptr;
  this->m_aBuckets.m_Size = 0;
  if ( this->m_aBuckets.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_aBuckets.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_aBuckets.m_Memory.m_pMemory);
      this->m_aBuckets.m_Memory.m_pMemory = nullptr;
    }
    this->m_aBuckets.m_Memory.m_nAllocationCount = 0;
  }
  this->m_aBuckets.m_pElements = this->m_aBuckets.m_Memory.m_pMemory;
  CUtlLinkedList<CUtlHashFast<memhandle_t__ *,CUtlHashFastNoHash>::HashFastData_t_<memhandle_t__ *>,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<memhandle_t__ *,CUtlHashFastNoHash>::HashFastData_t_<memhandle_t__ *>,int>>>::Purge(this: &this->m_aDataPool);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100043F0
// Name: public: CUtlHashFast<struct memhandle_t__ __near *,class CUtlHashFastNoHash>::~CUtlHashFast<struct memhandle_t__ __near *,class CUtlHashFastNoHash>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlHashFast<memhandle_t__ *,CUtlHashFastNoHash>::~CUtlHashFast<memhandle_t__ *,CUtlHashFastNoHash>(
        CUtlHashFast<memhandle_t__ *,CUtlHashFastNoHash> *this)
{
  CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<memhandle_t__ *,CUtlHashFastNoHash>::HashFastData_t_<memhandle_t__ *>,int> >::BlockHeader_t *m_pBlocks; // esi
  CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<memhandle_t__ *,CUtlHashFastNoHash>::HashFastData_t_<memhandle_t__ *>,int> >::BlockHeader_t *v3; // [esp-4h] [ebp-10h]

  this->m_aBuckets.m_Size = 0;
  if ( this->m_aBuckets.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_aBuckets.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_aBuckets.m_Memory.m_pMemory);
      this->m_aBuckets.m_Memory.m_pMemory = nullptr;
    }
    this->m_aBuckets.m_Memory.m_nAllocationCount = 0;
  }
  this->m_aBuckets.m_pElements = this->m_aBuckets.m_Memory.m_pMemory;
  CUtlLinkedList<CUtlHashFast<memhandle_t__ *,CUtlHashFastNoHash>::HashFastData_t_<memhandle_t__ *>,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<memhandle_t__ *,CUtlHashFastNoHash>::HashFastData_t_<memhandle_t__ *>,int>>>::Purge(this: &this->m_aDataPool);
  CUtlLinkedList<CUtlHashFast<memhandle_t__ *,CUtlHashFastNoHash>::HashFastData_t_<memhandle_t__ *>,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<memhandle_t__ *,CUtlHashFastNoHash>::HashFastData_t_<memhandle_t__ *>,int>>>::RemoveAll(this: &this->m_aDataPool);
  if ( this->m_aDataPool.m_Memory.m_pBlocks != nullptr )
  {
    m_pBlocks = this->m_aDataPool.m_Memory.m_pBlocks;
    do
    {
      v3 = m_pBlocks;
      m_pBlocks = m_pBlocks->m_pNext;
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v3);
    }
    while ( m_pBlocks != nullptr );
    this->m_aDataPool.m_Memory.m_pBlocks = nullptr;
    this->m_aDataPool.m_Memory.m_nAllocationCount = 0;
  }
  CUtlVector<CDataCacheSection *,CUtlMemory<CDataCacheSection *,int>>::~CUtlVector<CDataCacheSection *,CUtlMemory<CDataCacheSection *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&this->m_aBuckets);
}

//------------------------------------------------------------------------------
// Address: 0x10004470
// Name: private: virtual void CDataCacheSectionFastFind::OnAdd(unsigned int,struct memhandle_t__ __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDataCacheSectionFastFind::OnAdd(
        CDataCacheSectionFastFind *this,
        unsigned int clientId,
        memhandle_t__ *hCacheItem)
{
  CThreadFastMutex *m_mutex; // ebx
  DWORD CurrentThreadId; // ecx
  unsigned int *v6; // esi
  unsigned int v7; // ebx
  CAutoLockT<CThreadFastMutex> generated_id_26; // [esp+Ch] [ebp-8h]
  unsigned int v10; // [esp+10h] [ebp-4h]

  m_mutex = this->m_mutex;
  generated_id_26.m_lock = m_mutex;
  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != m_mutex->m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)m_mutex, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(a1: m_mutex, a2: CurrentThreadId, a3: 0);
  }
  else
  {
    ++m_mutex->m_depth;
  }
  v10 = Hash4(pKey: &clientId);
  v6 = (unsigned int *)CUtlLinkedList<CUtlHashFast<memhandle_t__ *,CUtlHashFastNoHash>::HashFastData_t_<memhandle_t__ *>,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<memhandle_t__ *,CUtlHashFastNoHash>::HashFastData_t_<memhandle_t__ *>,int>>>::AllocInternal(
                         this: &this->m_Handles.m_aDataPool,
                         multilist: true);
  if ( v6 != nullptr )
  {
    v6[1] = (unsigned int)hCacheItem;
    *v6 = v10;
    v7 = v10 & this->m_Handles.m_uiBucketMask;
    CUtlLinkedList<CUtlHashFast<memhandle_t__ *,CUtlHashFastNoHash>::HashFastData_t_<memhandle_t__ *>,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<memhandle_t__ *,CUtlHashFastNoHash>::HashFastData_t_<memhandle_t__ *>,int>>>::LinkBefore(
      this: &this->m_Handles.m_aDataPool,
      before: this->m_Handles.m_aBuckets.m_Memory.m_pMemory[v7],
      elem: (int)v6);
    this->m_Handles.m_aBuckets.m_Memory.m_pMemory[v7] = (int)v6;
    m_mutex = generated_id_26.m_lock;
  }
  if ( m_mutex->m_depth-- == 1 )
    _InterlockedExchange((volatile __int32 *)m_mutex, 0);
}

//------------------------------------------------------------------------------
// Address: 0x10004520
// Name: private: virtual void CDataCacheSectionFastFind::OnRemove(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDataCacheSectionFastFind::OnRemove(CDataCacheSectionFastFind *this, unsigned int clientId)
{
  CThreadFastMutex *m_mutex; // edi
  DWORD CurrentThreadId; // ecx
  unsigned int v5; // eax
  int *m_pMemory; // ecx
  _DWORD *v7; // esi
  bool v8; // zf
  unsigned int v9; // eax

  m_mutex = this->m_mutex;
  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != m_mutex->m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)m_mutex, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(a1: m_mutex, a2: CurrentThreadId, a3: 0);
  }
  else
  {
    ++m_mutex->m_depth;
  }
  v5 = Hash4(pKey: &clientId);
  m_pMemory = this->m_Handles.m_aBuckets.m_Memory.m_pMemory;
  v7 = (_DWORD *)m_pMemory[v5 & this->m_Handles.m_uiBucketMask];
  if ( v7 == nullptr )
    goto LABEL_8;
  while ( *v7 != v5 )
  {
    v7 = (_DWORD *)v7[3];
    if ( v7 == nullptr )
      goto LABEL_8;
  }
  if ( v7 == (_DWORD *)-1 )
  {
LABEL_8:
    v8 = m_mutex->m_depth-- == 1;
    if ( v8 )
      _InterlockedExchange((volatile __int32 *)m_mutex, 0);
  }
  else
  {
    v9 = this->m_Handles.m_uiBucketMask & *v7;
    if ( (_DWORD *)m_pMemory[v9] == v7 )
      m_pMemory[v9] = v7[3];
    else
      CUtlLinkedList<CUtlHashFast<memhandle_t__ *,CUtlHashFastNoHash>::HashFastData_t_<memhandle_t__ *>,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<memhandle_t__ *,CUtlHashFastNoHash>::HashFastData_t_<memhandle_t__ *>,int>>>::Unlink(
        this: &this->m_Handles.m_aDataPool,
        elem: (int)v7);
    CUtlLinkedList<CUtlHashFast<memhandle_t__ *,CUtlHashFastNoHash>::HashFastData_t_<memhandle_t__ *>,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<memhandle_t__ *,CUtlHashFastNoHash>::HashFastData_t_<memhandle_t__ *>,int>>>::Free(
      this: &this->m_Handles.m_aDataPool,
      elem: (int)v7);
    v8 = m_mutex->m_depth-- == 1;
    if ( v8 )
      _InterlockedExchange((volatile __int32 *)m_mutex, 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100045F0
// Name: public: CDataCache::CDataCache(void)
// Source: json
//------------------------------------------------------------------------------
CDataCache *__thiscall CDataCache::CDataCache(CDataCache *this)
{
  this->__vftable = (CDataCache_vtbl *)&CDataCache::`vftable';
  CDataManagerBase::CDataManagerBase(this: &this->m_LRU, maxSize: 0xFFFFFFFF);
  this->m_LRU.__vftable = (CDataManager<DataCacheItem_t,DataCacheItemData_t,DataCacheItem_t *,CThreadFastMutex>_vtbl *)&CDataManager<DataCacheItem_t,DataCacheItemData_t,DataCacheItem_t *,CThreadFastMutex>::`vftable';
  this->m_LRU.m_mutex.m_ownerID = 0;
  this->m_LRU.m_mutex.m_depth = 0;
  this->m_Sections.m_Memory.m_pMemory = nullptr;
  this->m_Sections.m_Memory.m_nAllocationCount = 0;
  this->m_Sections.m_Memory.m_nGrowSize = 0;
  this->m_Sections.m_Size = 0;
  this->m_Sections.m_pElements = nullptr;
  this->m_mutex = &this->m_LRU.m_mutex;
  *(_QWORD *)&this->m_status.nBytes = 0;
  *(_QWORD *)&this->m_status.nBytesLocked = 0;
  *(_QWORD *)&this->m_status.nFindRequests = 0;
  this->m_bInFlush = false;
  *((_WORD *)&this->m_LRU.CDataManagerBase + 37) &= ~2u;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10004660
// Name: public: virtual void CDataCache::OutputReport(enum DataCacheReportType_t,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDataCache::OutputReport(CDataCache *this, DataCacheReportType_t reportType, const char *pszSection)
{
  CThreadFastMutex *m_mutex; // edi
  CDataManagerBase *CurrentThreadId; // eax
  CDataManagerBase *m_ownerID; // ecx
  IDataCacheSection *v7; // edi
  int v8; // ebx
  memhandle_t__ *const *v9; // edi
  int v10; // eax
  UtlRBTreeNode_t<memhandle_t__ *,int> *m_pMemory; // ecx
  int v12; // edx
  int v13; // esi
  int v14; // edx
  int v15; // ebx
  memhandle_t__ *const *v16; // edi
  int v17; // eax
  UtlRBTreeNode_t<memhandle_t__ *,int> *v18; // ecx
  int v19; // edx
  int v20; // esi
  int v21; // edx
  int v22; // eax
  CDataCache *v23; // edi
  int v24; // esi
  UtlRBTreeNode_t<memhandle_t__ *,int> *v25; // ebx
  int m_nGrowSize; // esi
  UtlRBTreeNode_t<memhandle_t__ *,int> *v27; // eax
  CDataManagerBase *v28; // ebx
  int i; // esi
  int j; // esi
  int v31; // edi
  CDataCacheSection *v32; // ecx
  CDataCacheSection *v33; // ecx
  CDataCache_vtbl *v34; // esi
  int v35; // eax
  int m_Size; // esi
  int v37; // edi
  const char *v38; // eax
  int v39; // ebx
  int v40; // esi
  _DWORD *Resource_NoLockNoLRUTouch; // eax
  int k; // edi
  _DWORD *v43; // eax
  int v44; // ecx
  int v45; // eax
  const char *v46; // eax
  memhandle_t__ **v47; // eax
  memhandle_t__ **v48; // eax
  CThreadFastMutex *m_lock; // eax
  double v51; // [esp+18h] [ebp-8Ch]
  double v52; // [esp+1Ch] [ebp-88h]
  const char *v53; // [esp+20h] [ebp-84h]
  CUtlRBTree<memhandle_t__ *,int,bool (__cdecl*)(memhandle_t__ * const &,memhandle_t__ * const &),CUtlMemory<UtlRBTreeNode_t<memhandle_t__ *,int>,int> > sortedbysize; // [esp+30h] [ebp-74h] BYREF
  CUtlVector<memhandle_t__ *,CUtlMemory<memhandle_t__ *,int> > lruList; // [esp+54h] [ebp-50h] BYREF
  CUtlVector<memhandle_t__ *,CUtlMemory<memhandle_t__ *,int> > lockedlist; // [esp+68h] [ebp-3Ch] BYREF
  int bytesTotal; // [esp+7Ch] [ebp-28h]
  float value; // [esp+80h] [ebp-24h]
  float percent; // [esp+84h] [ebp-20h]
  CAutoLockT<CThreadFastMutex> generated_id_28; // [esp+88h] [ebp-1Ch]
  int v61; // [esp+8Ch] [ebp-18h] BYREF
  int parent; // [esp+90h] [ebp-14h] BYREF
  CDataManagerBase *p_m_LRU; // [esp+94h] [ebp-10h]
  CDataCache *v64; // [esp+98h] [ebp-Ch]
  int bytesUsed; // [esp+9Ch] [ebp-8h]
  bool v66; // [esp+A2h] [ebp-2h] BYREF
  bool leftchild; // [esp+A3h] [ebp-1h] BYREF

  m_mutex = this->m_mutex;
  v64 = this;
  generated_id_28.m_lock = m_mutex;
  CurrentThreadId = (CDataManagerBase *)GetCurrentThreadId();
  m_ownerID = (CDataManagerBase *)m_mutex->m_ownerID;
  p_m_LRU = CurrentThreadId;
  if ( CurrentThreadId != m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)m_mutex, (signed __int32)CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(a1: m_mutex, a2: p_m_LRU, a3: 0);
  }
  else
  {
    ++m_mutex->m_depth;
  }
  p_m_LRU = &this->m_LRU;
  bytesUsed = CDataManagerBase::UsedSize(this: &this->m_LRU);
  *(float *)&bytesTotal = COERCE_FLOAT(CDataManagerBase::TargetSize(this: &this->m_LRU));
  value = (float)bytesUsed;
  percent = (float)((float)bytesUsed * 100.0) / (float)bytesTotal;
  memset(&lruList, 0, sizeof(lruList));
  memset(&lockedlist, 0, sizeof(lockedlist));
  CDataManagerBase::GetLockHandleList(this: &this->m_LRU, list: &lockedlist);
  CDataManagerBase::GetLRUHandleList(this: &this->m_LRU, list: &lruList);
  v7 = nullptr;
  bytesUsed = 0;
  if ( pszSection == nullptr || (v7 = this->FindSection(this, a2: pszSection), bytesUsed = (int)v7, v7 != nullptr) )
  {
    switch ( reportType )
    {
      case DC_DETAIL_REPORT:
        v8 = 0;
        sortedbysize.m_LessFunc = (bool (__cdecl *)(memhandle_t__ *const *, memhandle_t__ *const *))CDataCache::SortMemhandlesBySizeLessFunc;
        memset(&sortedbysize.m_Elements, 0, sizeof(sortedbysize.m_Elements));
        sortedbysize.m_Root = -1;
        sortedbysize.m_NumElements = 0;
        sortedbysize.m_FirstFree = -1;
        sortedbysize.m_LastAlloc.index = -1;
        sortedbysize.m_pElements = nullptr;
        if ( lockedlist.m_Size > 0 )
        {
          do
          {
            if ( v7 == nullptr
              || *((IDataCacheSection **)CDataManagerBase::GetResource_NoLockNoLRUTouch(
                                           this: p_m_LRU,
                                           handle: lockedlist.m_Memory.m_pMemory[v8])
                 + 3) == v7 )
            {
              v9 = &lockedlist.m_Memory.m_pMemory[v8];
              parent = -1;
              leftchild = false;
              CUtlRBTree<memhandle_t__ *,int,bool (__cdecl *)(memhandle_t__ * const &,memhandle_t__ * const &),CUtlMemory<UtlRBTreeNode_t<memhandle_t__ *,int>,int>>::FindInsertionPosition(
                this: &sortedbysize,
                insert: v9,
                &parent,
                &leftchild);
              v10 = CUtlRBTree<memhandle_t__ *,int,bool (__cdecl *)(memhandle_t__ * const &,memhandle_t__ * const &),CUtlMemory<UtlRBTreeNode_t<memhandle_t__ *,int>,int>>::NewNode(this: &sortedbysize);
              m_pMemory = sortedbysize.m_Elements.m_pMemory;
              v12 = parent;
              v13 = v10;
              sortedbysize.m_Elements.m_pMemory[v13].m_Parent = parent;
              m_pMemory[v13].m_Right = -1;
              m_pMemory[v13].m_Left = -1;
              m_pMemory[v13].m_Tag = 0;
              if ( v12 == -1 )
              {
                sortedbysize.m_Root = v10;
              }
              else
              {
                v14 = v12;
                if ( leftchild )
                  m_pMemory[v14].m_Left = v10;
                else
                  m_pMemory[v14].m_Right = v10;
              }
              CUtlRBTree<memhandle_t__ *,int,bool (__cdecl *)(memhandle_t__ * const &,memhandle_t__ * const &),CUtlMemory<UtlRBTreeNode_t<memhandle_t__ *,int>,int>>::InsertRebalance(
                this: &sortedbysize,
                elem: v10);
              ++sortedbysize.m_NumElements;
              if ( &sortedbysize.m_Elements.m_pMemory[v13] != (UtlRBTreeNode_t<memhandle_t__ *,int> *)-16 )
                sortedbysize.m_Elements.m_pMemory[v13].m_Data = *v9;
              v7 = (IDataCacheSection *)bytesUsed;
            }
            ++v8;
          }
          while ( v8 < lockedlist.m_Size );
        }
        v15 = 0;
        if ( lruList.m_Size > 0 )
        {
          while ( 1 )
          {
            if ( v7 == nullptr
              || *((IDataCacheSection **)CDataManagerBase::GetResource_NoLockNoLRUTouch(
                                           this: p_m_LRU,
                                           handle: lruList.m_Memory.m_pMemory[v15])
                 + 3) == v7 )
            {
              v16 = &lruList.m_Memory.m_pMemory[v15];
              v61 = -1;
              v66 = false;
              CUtlRBTree<memhandle_t__ *,int,bool (__cdecl *)(memhandle_t__ * const &,memhandle_t__ * const &),CUtlMemory<UtlRBTreeNode_t<memhandle_t__ *,int>,int>>::FindInsertionPosition(
                this: &sortedbysize,
                insert: v16,
                parent: &v61,
                leftchild: &v66);
              v17 = CUtlRBTree<memhandle_t__ *,int,bool (__cdecl *)(memhandle_t__ * const &,memhandle_t__ * const &),CUtlMemory<UtlRBTreeNode_t<memhandle_t__ *,int>,int>>::NewNode(this: &sortedbysize);
              v18 = sortedbysize.m_Elements.m_pMemory;
              v19 = v61;
              v20 = v17;
              sortedbysize.m_Elements.m_pMemory[v20].m_Parent = v61;
              v18[v20].m_Right = -1;
              v18[v20].m_Left = -1;
              v18[v20].m_Tag = 0;
              if ( v19 == -1 )
              {
                sortedbysize.m_Root = v17;
              }
              else
              {
                v21 = v19;
                if ( v66 )
                  v18[v21].m_Left = v17;
                else
                  v18[v21].m_Right = v17;
              }
              CUtlRBTree<memhandle_t__ *,int,bool (__cdecl *)(memhandle_t__ * const &,memhandle_t__ * const &),CUtlMemory<UtlRBTreeNode_t<memhandle_t__ *,int>,int>>::InsertRebalance(
                this: &sortedbysize,
                elem: v17);
              ++sortedbysize.m_NumElements;
              if ( &sortedbysize.m_Elements.m_pMemory[v20] != (UtlRBTreeNode_t<memhandle_t__ *,int> *)-16 )
                sortedbysize.m_Elements.m_pMemory[v20].m_Data = *v16;
            }
            if ( ++v15 >= lruList.m_Size )
              break;
            v7 = (IDataCacheSection *)bytesUsed;
          }
        }
        v22 = CUtlRBTree<memhandle_t__ *,int,bool (__cdecl *)(memhandle_t__ * const &,memhandle_t__ * const &),CUtlMemory<UtlRBTreeNode_t<memhandle_t__ *,int>,int>>::FirstInorder(this: &sortedbysize);
        v23 = v64;
        v24 = v22;
        if ( v22 != -1 )
        {
          v25 = sortedbysize.m_Elements.m_pMemory;
          do
          {
            CDataCache::OutputItemReport(this: v23, hItem: v25[v24].m_Data, pXboxData: nullptr);
            v24 = CUtlRBTree<memhandle_t__ *,int,bool (__cdecl *)(memhandle_t__ * const &,memhandle_t__ * const &),CUtlMemory<UtlRBTreeNode_t<memhandle_t__ *,int>,int>>::NextInorder(
                    this: &sortedbysize,
                    i: v24);
          }
          while ( v24 != -1 );
        }
        v23->OutputReport(this: v23, a2: DC_SUMMARY_REPORT, a3: pszSection);
        CUtlRBTree<memhandle_t__ *,int,bool (__cdecl *)(memhandle_t__ * const &,memhandle_t__ * const &),CUtlMemory<UtlRBTreeNode_t<memhandle_t__ *,int>,int>>::RemoveAll(this: &sortedbysize);
        m_nGrowSize = sortedbysize.m_Elements.m_nGrowSize;
        v27 = sortedbysize.m_Elements.m_pMemory;
        sortedbysize.m_FirstFree = -1;
        if ( sortedbysize.m_Elements.m_nGrowSize >= 0 )
        {
          if ( sortedbysize.m_Elements.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: sortedbysize.m_Elements.m_pMemory);
            v27 = nullptr;
            sortedbysize.m_Elements.m_pMemory = nullptr;
          }
          sortedbysize.m_Elements.m_nAllocationCount = 0;
        }
        sortedbysize.m_LastAlloc.index = -1;
        if ( m_nGrowSize >= 0 )
        {
          if ( v27 != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v27);
            sortedbysize.m_Elements.m_pMemory = nullptr;
          }
          sortedbysize.m_Elements.m_nAllocationCount = 0;
        }
        break;
      case DC_DETAIL_REPORT_LRU:
        v28 = p_m_LRU;
        for ( i = 0; i < lockedlist.m_Size; ++i )
        {
          if ( v7 == nullptr
            || *((IDataCacheSection **)CDataManagerBase::GetResource_NoLockNoLRUTouch(
                                         this: v28,
                                         handle: lockedlist.m_Memory.m_pMemory[i])
               + 3) == v7 )
          {
            CDataCache::OutputItemReport(this: v64, hItem: lockedlist.m_Memory.m_pMemory[i], pXboxData: nullptr);
          }
        }
        for ( j = 0; j < lruList.m_Size; ++j )
        {
          if ( v7 == nullptr
            || *((IDataCacheSection **)CDataManagerBase::GetResource_NoLockNoLRUTouch(
                                         this: v28,
                                         handle: lruList.m_Memory.m_pMemory[j])
               + 3) == v7 )
          {
            CDataCache::OutputItemReport(this: v64, hItem: lruList.m_Memory.m_pMemory[j], pXboxData: nullptr);
          }
        }
        v64->OutputReport(this: v64, a2: DC_SUMMARY_REPORT, a3: pszSection);
        break;
      case DC_SUMMARY_REPORT:
        v31 = 0;
        if ( pszSection != nullptr )
        {
          v39 = 0;
          v40 = 0;
          if ( lockedlist.m_Size > 0 )
          {
            do
            {
              Resource_NoLockNoLRUTouch = CDataManagerBase::GetResource_NoLockNoLRUTouch(
                                            this: p_m_LRU,
                                            handle: lockedlist.m_Memory.m_pMemory[v31]);
              if ( Resource_NoLockNoLRUTouch[3] == bytesUsed )
              {
                v40 += *((_DWORD *)CDataManagerBase::GetResource_NoLockNoLRUTouch(
                                     this: &g_DataCache.m_LRU,
                                     handle: lockedlist.m_Memory.m_pMemory[v31])
                       + 1);
                ++v39;
              }
              ++v31;
            }
            while ( v31 < lockedlist.m_Size );
          }
          for ( k = 0; k < lruList.m_Size; ++k )
          {
            v43 = CDataManagerBase::GetResource_NoLockNoLRUTouch(this: p_m_LRU, handle: lruList.m_Memory.m_pMemory[k]);
            if ( v43[3] == bytesUsed )
            {
              v40 += *((_DWORD *)CDataManagerBase::GetResource_NoLockNoLRUTouch(
                                   this: &g_DataCache.m_LRU,
                                   handle: lruList.m_Memory.m_pMemory[k])
                     + 1);
              ++v39;
            }
          }
          v44 = *(_DWORD *)(bytesUsed + 164);
          v45 = 1;
          if ( v44 == -1 )
          {
            v45 = bytesTotal;
          }
          else if ( v44 != 0 )
          {
            v45 = *(_DWORD *)(bytesUsed + 164);
          }
          *(float *)&bytesTotal = (float)v45;
          v53 = V_pretifymem(value: (float)v45, digitsafterdecimal: 2, usebinaryonek: true);
          v51 = (float)((float)((float)v40 * 100.0) / *(float *)&bytesTotal);
          v46 = V_pretifymem(value: (float)v40, digitsafterdecimal: 2, usebinaryonek: true);
          _Msg(a1: "Section [%s]: %i resources total %s, %.2f %% of limit (%s)\n", pszSection, v39, v46, v51, v53);
        }
        else
        {
          if ( this->m_Sections.m_Size > 0 )
          {
            do
            {
              v32 = this->m_Sections.m_Memory.m_pMemory[v31];
              if ( v32->GetName(this: v32) != nullptr )
              {
                v33 = this->m_Sections.m_Memory.m_pMemory[v31];
                v34 = this->__vftable;
                v35 = (int)v33->GetName(this: v33);
                v34->OutputReport(this, a2: DC_SUMMARY_REPORT, a3: (const char *)v35);
              }
              ++v31;
            }
            while ( v31 < this->m_Sections.m_Size );
          }
          m_Size = lockedlist.m_Size;
          v37 = lruList.m_Size;
          v52 = percent;
          v38 = V_pretifymem(value, digitsafterdecimal: 2, usebinaryonek: true);
          _Msg(a1: "Summary: %i resources total %s, %.2f %% of capacity\n", m_Size + v37, v38, v52);
        }
        break;
      default:
        break;
    }
    v47 = lockedlist.m_Memory.m_pMemory;
    lockedlist.m_Size = 0;
    if ( lockedlist.m_Memory.m_nGrowSize >= 0 )
    {
      if ( lockedlist.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: lockedlist.m_Memory.m_pMemory);
        v47 = nullptr;
        lockedlist.m_Memory.m_pMemory = nullptr;
      }
      lockedlist.m_Memory.m_nAllocationCount = 0;
    }
    lockedlist.m_pElements = v47;
    if ( lockedlist.m_Memory.m_nGrowSize >= 0 )
    {
      if ( v47 != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v47);
        lockedlist.m_Memory.m_pMemory = nullptr;
      }
      lockedlist.m_Memory.m_nAllocationCount = 0;
    }
    v48 = lruList.m_Memory.m_pMemory;
    lruList.m_Size = 0;
    if ( lruList.m_Memory.m_nGrowSize >= 0 )
    {
      if ( lruList.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: lruList.m_Memory.m_pMemory);
        v48 = nullptr;
        lruList.m_Memory.m_pMemory = nullptr;
      }
      lruList.m_Memory.m_nAllocationCount = 0;
    }
    lruList.m_pElements = v48;
    if ( lruList.m_Memory.m_nGrowSize >= 0 )
    {
      if ( v48 != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v48);
        lruList.m_Memory.m_pMemory = nullptr;
      }
      lruList.m_Memory.m_nAllocationCount = 0;
    }
  }
  else
  {
    _Msg(a1: "Unknown cache section %s\n", pszSection);
    CUtlVector<CDataCacheSection *,CUtlMemory<CDataCacheSection *,int>>::~CUtlVector<CDataCacheSection *,CUtlMemory<CDataCacheSection *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&lockedlist);
    CUtlVector<CDataCacheSection *,CUtlMemory<CDataCacheSection *,int>>::~CUtlVector<CDataCacheSection *,CUtlMemory<CDataCacheSection *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&lruList);
  }
  m_lock = generated_id_28.m_lock;
  if ( generated_id_28.m_lock->m_depth-- == 1 )
    _InterlockedExchange((volatile __int32 *)m_lock, 0);
}

//------------------------------------------------------------------------------
// Address: 0x10004C90
// Name: public: bool CUtlHashFast<struct memhandle_t__ __near *,class CUtlHashFastNoHash>::Init(int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CUtlHashFast<memhandle_t__ *,CUtlHashFastNoHash>::Init(
        CUtlHashFast<memhandle_t__ *,CUtlHashFastNoHash> *this,
        int nBucketCount)
{
  int i; // eax
  CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<memhandle_t__ *,CUtlHashFastNoHash>::HashFastData_t_<memhandle_t__ *>,int> >::BlockHeader_t *m_pBlocks; // esi
  CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<memhandle_t__ *,CUtlHashFastNoHash>::HashFastData_t_<memhandle_t__ *>,int> >::BlockHeader_t *v6; // [esp-8h] [ebp-10h]
  int nGrowSize; // [esp+10h] [ebp+8h]

  if ( ((nBucketCount - 1) & nBucketCount) != 0 )
    return 0;
  this->m_aBuckets.m_Size = 0;
  CUtlVector<ResourceList_t__ *,CUtlMemory<ResourceList_t__ *,int>>::InsertMultipleBefore(
    this: &this->m_aBuckets,
    elem: 0,
    num: nBucketCount);
  for ( i = 0; i < nBucketCount; ++i )
    this->m_aBuckets.m_Memory.m_pMemory[i] = 0;
  this->m_uiBucketMask = nBucketCount - 1;
  nGrowSize = 2 * nBucketCount;
  CUtlLinkedList<CUtlHashFast<memhandle_t__ *,CUtlHashFastNoHash>::HashFastData_t_<memhandle_t__ *>,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<memhandle_t__ *,CUtlHashFastNoHash>::HashFastData_t_<memhandle_t__ *>,int>>>::RemoveAll(this: &this->m_aDataPool);
  m_pBlocks = this->m_aDataPool.m_Memory.m_pBlocks;
  if ( m_pBlocks != nullptr )
  {
    do
    {
      v6 = m_pBlocks;
      m_pBlocks = m_pBlocks->m_pNext;
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v6);
    }
    while ( m_pBlocks != nullptr );
    this->m_aDataPool.m_Memory.m_pBlocks = nullptr;
    this->m_aDataPool.m_Memory.m_nAllocationCount = 0;
  }
  this->m_aDataPool.m_pElements = nullptr;
  this->m_aDataPool.m_Memory.m_nGrowSize = nGrowSize;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10004D20
// Name: public: CDataCacheSectionFastFind::CDataCacheSectionFastFind(class CDataCache __near *,class IDataCacheClient __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDataCacheSectionFastFind *__thiscall CDataCacheSectionFastFind::CDataCacheSectionFastFind(
        CDataCacheSectionFastFind *this,
        CDataCache *pSharedCache,
        IDataCacheClient *pClient,
        const char *pszName)
{
  CDataCacheSection::CDataCacheSection(this, pSharedCache, pClient, pszName);
  this->__vftable = (CDataCacheSectionFastFind_vtbl *)&CDataCacheSectionFastFind::`vftable';
  CUtlHashFast<memhandle_t__ *,CUtlHashFastNoHash>::CUtlHashFast<memhandle_t__ *,CUtlHashFastNoHash>(this: &this->m_Handles);
  CUtlHashFast<memhandle_t__ *,CUtlHashFastNoHash>::Init(this: &this->m_Handles, nBucketCount: 1024);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10004DA0
// Name: public: virtual class IDataCacheSection __near * CDataCache::AddSection(class IDataCacheClient __near *,char const __near *,struct DataCacheLimits_t const __near &,bool)
// Source: json
//------------------------------------------------------------------------------
CDataCacheSectionFastFind *__thiscall CDataCache::AddSection(
        CDataCache *this,
        IDataCacheClient *pClient,
        const char *pszSectionName,
        const DataCacheLimits_t *limits,
        bool bSupportFastFind)
{
  CDataCacheSectionFastFind *result; // eax
  CDataCacheSection *v7; // eax
  CDataCacheSectionFastFind *v8; // ebx
  CDataCacheSectionFastFind *v9; // eax
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CDataCacheSection **m_pMemory; // ecx
  int v13; // eax
  CDataCacheSection **v14; // edi

  result = (CDataCacheSectionFastFind *)this->FindSection(this, a2: pszSectionName);
  if ( result != nullptr )
    return result;
  if ( bSupportFastFind )
  {
    v9 = (CDataCacheSectionFastFind *)operator new(nSize: 0x128u);
    if ( v9 != nullptr )
    {
      v8 = CDataCacheSectionFastFind::CDataCacheSectionFastFind(
             this: v9,
             pSharedCache: this,
             pClient,
             pszName: pszSectionName);
      goto LABEL_8;
    }
LABEL_7:
    v8 = nullptr;
    goto LABEL_8;
  }
  v7 = (CDataCacheSection *)operator new(nSize: 0xE0u);
  if ( v7 == nullptr )
    goto LABEL_7;
  v8 = (CDataCacheSectionFastFind *)CDataCacheSection::CDataCacheSection(
                                      this: v7,
                                      pSharedCache: this,
                                      pClient,
                                      pszName: pszSectionName);
LABEL_8:
  v8->SetLimits(this: v8, a2: limits);
  m_Size = this->m_Sections.m_Size;
  m_nAllocationCount = this->m_Sections.m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<unsigned long,int>::Grow(
      this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&this->m_Sections,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Sections.m_Size;
  m_pMemory = this->m_Sections.m_Memory.m_pMemory;
  v13 = this->m_Sections.m_Size - m_Size - 1;
  this->m_Sections.m_pElements = m_pMemory;
  if ( v13 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v13);
  v14 = &this->m_Sections.m_Memory.m_pMemory[m_Size];
  if ( v14 != nullptr )
    *v14 = v8;
  return v8;
}

//------------------------------------------------------------------------------
// Address: 0x10001110
// Name: __CreateCDataCacheIDataCache_interface
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDataCache *__cdecl _CreateCDataCacheIDataCache_interface()
{
  return &g_DataCache;
}
