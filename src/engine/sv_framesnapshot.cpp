// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: engine/sv_framesnapshot.cpp
// Functions: 21
// ============================================================

#include "engine\sv_framesnapshot.h"

//------------------------------------------------------------------------------
// Address: 0x1011F8C0
// Name: public: void CFrameSnapshotManager::AddEntityReference(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFrameSnapshotManager::AddEntityReference(CFrameSnapshotManager *this, int handle)
{
  _InterlockedExchangeAdd((volatile signed __int32 *)(*(_DWORD *)handle + 12), 1u);
}

//------------------------------------------------------------------------------
// Address: 0x1011F8E0
// Name: public: bool CFrameSnapshotManager::ShouldForceRepack(class CFrameSnapshot __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CFrameSnapshotManager::ShouldForceRepack(
        CFrameSnapshotManager *this,
        CFrameSnapshot *pSnapshot,
        int entity,
        int *handle)
{
  int v4; // eax
  bool result; // al

  result = false;
  if ( sv_creationtickcheck.m_pParent != nullptr && sv_creationtickcheck.m_pParent->m_Value.m_nValue != 0 )
  {
    v4 = *handle;
    if ( *handle != 0
      && (*(_DWORD *)(v4 + 48) & 0x80000000) == 0x80000000
      && g_ServerGlobalVariables.nTimestampNetworkingBase
       * ((pSnapshot->m_nTickCount - entity % g_ServerGlobalVariables.nTimestampRandomizeWindow)
        / g_ServerGlobalVariables.nTimestampNetworkingBase) != g_ServerGlobalVariables.nTimestampNetworkingBase
                                                             * (((*(_DWORD *)(v4 + 48) & 0x7FFFFFFF)
                                                               - entity
                                                               % g_ServerGlobalVariables.nTimestampRandomizeWindow)
                                                              / g_ServerGlobalVariables.nTimestampNetworkingBase) )
    {
      return true;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1011F960
// Name: public: bool CFrameSnapshotManager::UsePreviouslySentPacket(class CFrameSnapshot __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CFrameSnapshotManager::UsePreviouslySentPacket(
        CFrameSnapshotManager *this,
        CFrameSnapshot *pSnapshot,
        int entity,
        int entSerialNumber)
{
  int *v4; // edi

  v4 = (int *)this->m_pPackedData[entity];
  if ( v4 == nullptr || this->m_pSerialNumber[entity] != entSerialNumber )
    return 0;
  if ( CFrameSnapshotManager::ShouldForceRepack(this: framesnapshotmanager, pSnapshot, entity, handle: v4) )
    return 0;
  pSnapshot->m_pEntities[entity].m_pPackedData = (int)v4;
  _InterlockedExchangeAdd((volatile signed __int32 *)(*v4 + 12), 1u);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1011F9D0
// Name: public: class PackedEntity __near * CFrameSnapshotManager::GetPreviouslySentPacket(int,int)
// Source: json
//------------------------------------------------------------------------------
PackedEntity *__thiscall CFrameSnapshotManager::GetPreviouslySentPacket(
        CFrameSnapshotManager *this,
        int iEntity,
        int iSerialNumber)
{
  int v3; // eax

  v3 = this->m_pPackedData[iEntity];
  if ( v3 != 0 && this->m_pSerialNumber[iEntity] == iSerialNumber )
    return *(PackedEntity **)v3;
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1011FA00
// Name: public: class PackedEntity __near * CFrameSnapshotManager::GetPackedEntity(class CFrameSnapshot __near *,int)
// Source: json
//------------------------------------------------------------------------------
PackedEntity *__thiscall CFrameSnapshotManager::GetPackedEntity(
        CFrameSnapshotManager *this,
        CFrameSnapshot *pSnapshot,
        int entity)
{
  int m_pPackedData; // eax

  if ( pSnapshot != nullptr && (m_pPackedData = pSnapshot->m_pEntities[entity].m_pPackedData) != 0 )
    return *(PackedEntity **)m_pPackedData;
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1011FA30
// Name: public: void CFrameSnapshot::AddReference(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFrameSnapshot::AddReference(CFrameSnapshot *this)
{
  _InterlockedExchangeAdd(&this->m_nReferences.m_value, 1u);
}

//------------------------------------------------------------------------------
// Address: 0x1011FD50
// Name: public: virtual CFrameSnapshotManager::~CFrameSnapshotManager(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFrameSnapshotManager::~CFrameSnapshotManager(CFrameSnapshotManager *this)
{
  CUtlFixedMemory<UtlLinkedListElem_t<PackedEntity *,int> >::BlockHeader_t *m_pBlocks; // esi
  CUtlFixedMemory<UtlLinkedListElem_t<PackedEntity *,int> >::BlockHeader_t *v3; // [esp-4h] [ebp-10h]

  this->__vftable = (CFrameSnapshotManager_vtbl *)&CFrameSnapshotManager::`vftable';
  CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&this->m_iExplicitDeleteSlots);
  CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&this->m_PackedEntityCache);
  CUtlLinkedList<CSpatialEntry,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CSpatialEntry,int>>>::RemoveAll(this: (CUtlLinkedList<decal_t *,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<decal_t *,int> > > *)&this->m_PackedEntities);
  m_pBlocks = this->m_PackedEntities.m_Memory.m_pBlocks;
  if ( m_pBlocks != nullptr )
  {
    do
    {
      v3 = m_pBlocks;
      m_pBlocks = m_pBlocks->m_pNext;
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v3);
    }
    while ( m_pBlocks != nullptr );
    this->m_PackedEntities.m_Memory.m_pBlocks = nullptr;
    this->m_PackedEntities.m_Memory.m_nAllocationCount = 0;
  }
  CUtlMemoryPool::~CUtlMemoryPool(this: &this->m_PackedEntitiesPool);
  CUtlLinkedList<CFrameSnapshot *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CFrameSnapshot *,unsigned short>,unsigned short>>::RemoveAll(this: (CUtlLinkedList<unsigned int,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<unsigned int,unsigned short>,unsigned short> > *)&this->m_FrameSnapshots);
  if ( this->m_FrameSnapshots.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_FrameSnapshots.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_FrameSnapshots.m_Memory.m_pMemory);
      this->m_FrameSnapshots.m_Memory.m_pMemory = nullptr;
    }
    this->m_FrameSnapshots.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1011FDE0
// Name: public: void CFrameSnapshotManager::BuildSnapshotList(class CFrameSnapshot __near *,class CFrameSnapshot __near *,class CReferencedSnapshotList __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFrameSnapshotManager::BuildSnapshotList(
        CFrameSnapshotManager *this,
        CFrameSnapshot *pCurrentSnapshot,
        CFrameSnapshot *pLastSnapshot,
        CReferencedSnapshotList *list)
{
  CThreadFastMutex *p_m_FrameSnapshotsWriteMutex; // esi
  DWORD CurrentThreadId; // ecx
  UtlLinkedListElem_t<CFrameSnapshot *,unsigned short> *m_pMemory; // eax
  int m_Next; // ecx
  CFrameSnapshot *m_Element; // ebx
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CFrameSnapshot **v12; // ecx
  int v13; // eax
  CFrameSnapshot **v14; // edi
  UtlLinkedListElem_t<CFrameSnapshot *,unsigned short> *v15; // eax
  int v16; // ecx
  CFrameSnapshot *v17; // eax
  CThreadFastMutex *generated_id_19; // [esp+Ch] [ebp-Ch]
  int nInsanity; // [esp+14h] [ebp-4h]

  p_m_FrameSnapshotsWriteMutex = &this->m_FrameSnapshotsWriteMutex;
  generated_id_19 = &this->m_FrameSnapshotsWriteMutex;
  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != p_m_FrameSnapshotsWriteMutex->m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)p_m_FrameSnapshotsWriteMutex, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(a1: p_m_FrameSnapshotsWriteMutex, a2: CurrentThreadId, a3: 0);
  }
  else
  {
    ++p_m_FrameSnapshotsWriteMutex->m_depth;
  }
  nInsanity = 0;
  if ( pLastSnapshot != nullptr )
  {
    if ( (unsigned __int16)pLastSnapshot->m_ListIndex.m_value == 0xFFFF
      || (m_pMemory = this->m_FrameSnapshots.m_Memory.m_pMemory,
          (m_Next = m_pMemory[(unsigned __int16)pLastSnapshot->m_ListIndex.m_value].m_Next) == 0xFFFF) )
    {
      m_Element = nullptr;
    }
    else
    {
      m_Element = m_pMemory[m_Next].m_Element;
    }
  }
  else
  {
    m_Element = pCurrentSnapshot;
  }
  if ( m_Element != nullptr )
  {
    do
    {
      _InterlockedExchangeAdd(&m_Element->m_nReferences.m_value, 1u);
      m_Size = list->m_vecSnapshots.m_Size;
      m_nAllocationCount = list->m_vecSnapshots.m_Memory.m_nAllocationCount;
      if ( m_Size + 1 > m_nAllocationCount )
        CUtlMemory<INetMessage *,int>::Grow(this: (CUtlMemory<S3RGBA,int> *)list, num: m_Size - m_nAllocationCount + 1);
      ++list->m_vecSnapshots.m_Size;
      v12 = list->m_vecSnapshots.m_Memory.m_pMemory;
      v13 = list->m_vecSnapshots.m_Size - m_Size - 1;
      list->m_vecSnapshots.m_pElements = list->m_vecSnapshots.m_Memory.m_pMemory;
      if ( v13 > 0 )
        _V_memmove(dest: &v12[m_Size + 1], src: &v12[m_Size], count: 4 * v13);
      v14 = &list->m_vecSnapshots.m_Memory.m_pMemory[m_Size];
      if ( v14 != nullptr )
        *v14 = m_Element;
      if ( ++nInsanity > 100000 )
        _Error(a1: "CFrameSnapshotManager::BuildSnapshotList:  infinite loop building list!!!");
      if ( m_Element == pCurrentSnapshot )
        break;
      if ( m_Element == nullptr
        || (unsigned __int16)m_Element->m_ListIndex.m_value == 0xFFFF
        || (v15 = this->m_FrameSnapshots.m_Memory.m_pMemory,
            (v16 = v15[(unsigned __int16)m_Element->m_ListIndex.m_value].m_Next) == 0xFFFF) )
      {
        v17 = nullptr;
      }
      else
      {
        v17 = v15[v16].m_Element;
      }
      m_Element = v17;
    }
    while ( v17 != nullptr );
    p_m_FrameSnapshotsWriteMutex = generated_id_19;
  }
  if ( p_m_FrameSnapshotsWriteMutex->m_depth-- == 1 )
    _InterlockedExchange((volatile __int32 *)p_m_FrameSnapshotsWriteMutex, 0);
}

//------------------------------------------------------------------------------
// Address: 0x1011FF40
// Name: public: CFrameSnapshotManager::CFrameSnapshotManager(void)
// Source: json
//------------------------------------------------------------------------------
CFrameSnapshotManager *__thiscall CFrameSnapshotManager::CFrameSnapshotManager(CFrameSnapshotManager *this)
{
  UtlLinkedListElem_t<CFrameSnapshot *,unsigned short> *m_pMemory; // eax

  this->__vftable = (CFrameSnapshotManager_vtbl *)&CFrameSnapshotManager::`vftable';
  this->m_FrameSnapshotsWriteMutex.m_ownerID = 0;
  this->m_FrameSnapshotsWriteMutex.m_depth = 0;
  this->m_FrameSnapshots.m_Memory.m_pMemory = nullptr;
  this->m_FrameSnapshots.m_Memory.m_nAllocationCount = 0;
  this->m_FrameSnapshots.m_Memory.m_nGrowSize = 0;
  this->m_FrameSnapshots.m_LastAlloc.index = -1;
  *(_DWORD *)&this->m_FrameSnapshots.m_FirstFree = 0xFFFF;
  m_pMemory = this->m_FrameSnapshots.m_Memory.m_pMemory;
  *(_DWORD *)&this->m_FrameSnapshots.m_Head = -1;
  this->m_FrameSnapshots.m_NumAlloced = 0;
  this->m_FrameSnapshots.m_pElements = m_pMemory;
  CUtlMemoryPool::CUtlMemoryPool(
    this: &this->m_PackedEntitiesPool,
    blockSize: 52,
    numElements: 128,
    growMode: 2,
    pszAllocOwner: nullptr,
    nAlignment: 0);
  this->m_PackedEntities.m_Memory.m_pBlocks = nullptr;
  this->m_PackedEntities.m_Memory.m_nAllocationCount = 0;
  this->m_PackedEntities.m_Memory.m_nGrowSize = 0;
  this->m_PackedEntities.m_LastAlloc.m_pBlockHeader = nullptr;
  this->m_PackedEntities.m_LastAlloc.m_nIndex = -1;
  this->m_PackedEntities.m_Head = 0;
  this->m_PackedEntities.m_Tail = 0;
  this->m_PackedEntities.m_FirstFree = 0;
  this->m_PackedEntities.m_ElementCount = 0;
  this->m_PackedEntities.m_NumAlloced = 0;
  this->m_PackedEntities.m_pElements = nullptr;
  this->m_PackedEntityCache.m_Memory.m_pMemory = nullptr;
  this->m_PackedEntityCache.m_Memory.m_nAllocationCount = 0;
  this->m_PackedEntityCache.m_Memory.m_nGrowSize = 0;
  this->m_PackedEntityCache.m_Size = 0;
  this->m_PackedEntityCache.m_pElements = nullptr;
  this->m_WriteMutex.m_ownerID = 0;
  this->m_WriteMutex.m_depth = 0;
  this->m_iExplicitDeleteSlots.m_Memory.m_pMemory = nullptr;
  this->m_iExplicitDeleteSlots.m_Memory.m_nAllocationCount = 0;
  this->m_iExplicitDeleteSlots.m_Memory.m_nGrowSize = 0;
  this->m_iExplicitDeleteSlots.m_Size = 0;
  this->m_iExplicitDeleteSlots.m_pElements = nullptr;
  _V_memset(dest: this->m_pPackedData, fill: 0, count: 0x2000);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10120050
// Name: public: void CFrameSnapshotManager::RemoveEntityReference(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFrameSnapshotManager::RemoveEntityReference(CFrameSnapshotManager *this, PackedEntity **handle)
{
  PackedEntity *v2; // ebx
  CThreadFastMutex *p_m_WriteMutex; // edi
  DWORD CurrentThreadId; // ecx
  int m_Size; // ecx
  int v7; // eax
  UnpackedDataCache_t *m_pMemory; // esi
  PackedEntity *packedEntity; // [esp+8h] [ebp-4h]

  v2 = *handle;
  packedEntity = *handle;
  if ( _InterlockedDecrement(&(*handle)->m_ReferenceCount.m_value) > 0 )
    return;
  p_m_WriteMutex = &this->m_WriteMutex;
  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != this->m_WriteMutex.m_ownerID )
  {
    if ( _InterlockedCompareExchange((volatile signed __int32 *)p_m_WriteMutex, CurrentThreadId, 0) != 0 )
    {
      _mm_pause();
      CThreadFastMutex::Lock(a1: &this->m_WriteMutex, a2: CurrentThreadId, a3: 0);
      v2 = packedEntity;
      goto LABEL_7;
    }
    v2 = packedEntity;
  }
  ++this->m_WriteMutex.m_depth;
LABEL_7:
  CUtlLinkedList<PackedEntity *,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<PackedEntity *,int>>>::Free(
    this: (CUtlLinkedList<unsigned short,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<unsigned short,int> > > *)&this->m_PackedEntities,
    elem: (int)handle);
  if ( v2 != nullptr )
    PackedEntity::~PackedEntity(this: v2);
  CUtlMemoryPool::Free(this: &this->m_PackedEntitiesPool, memBlock: v2);
  m_Size = this->m_PackedEntityCache.m_Size;
  v7 = 0;
  if ( m_Size > 0 )
  {
    m_pMemory = this->m_PackedEntityCache.m_Memory.m_pMemory;
    while ( m_pMemory->pEntity != v2 )
    {
      ++v7;
      ++m_pMemory;
      if ( v7 >= m_Size )
        goto LABEL_15;
    }
    m_pMemory->pEntity = nullptr;
    m_pMemory->counter = 0;
  }
LABEL_15:
  if ( p_m_WriteMutex->m_depth-- == 1 )
    _InterlockedExchange((volatile __int32 *)p_m_WriteMutex, 0);
}

//------------------------------------------------------------------------------
// Address: 0x10120120
// Name: public: void CFrameSnapshotManager::AddExplicitDelete(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFrameSnapshotManager::AddExplicitDelete(CFrameSnapshotManager *this, int iSlot)
{
  CThreadFastMutex *p_m_WriteMutex; // ebx
  DWORD CurrentThreadId; // ecx
  int m_Size; // ecx
  int v6; // eax
  int *m_pMemory; // edx
  int m_nAllocationCount; // eax
  int v9; // edi
  int *v10; // ecx
  int v11; // eax
  int *v12; // eax

  p_m_WriteMutex = &this->m_WriteMutex;
  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != p_m_WriteMutex->m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)p_m_WriteMutex, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(a1: p_m_WriteMutex, a2: CurrentThreadId, a3: 0);
  }
  else
  {
    ++p_m_WriteMutex->m_depth;
  }
  m_Size = this->m_iExplicitDeleteSlots.m_Size;
  v6 = 0;
  if ( m_Size <= 0 )
    goto LABEL_11;
  m_pMemory = this->m_iExplicitDeleteSlots.m_Memory.m_pMemory;
  while ( *m_pMemory != iSlot )
  {
    ++v6;
    ++m_pMemory;
    if ( v6 >= m_Size )
      goto LABEL_11;
  }
  if ( v6 == -1 )
  {
LABEL_11:
    m_nAllocationCount = this->m_iExplicitDeleteSlots.m_Memory.m_nAllocationCount;
    v9 = this->m_iExplicitDeleteSlots.m_Size;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<INetMessage *,int>::Grow(
        this: (CUtlMemory<S3RGBA,int> *)&this->m_iExplicitDeleteSlots,
        num: v9 - m_nAllocationCount + 1);
    ++this->m_iExplicitDeleteSlots.m_Size;
    v10 = this->m_iExplicitDeleteSlots.m_Memory.m_pMemory;
    v11 = this->m_iExplicitDeleteSlots.m_Size - v9 - 1;
    this->m_iExplicitDeleteSlots.m_pElements = v10;
    if ( v11 > 0 )
      _V_memmove(dest: &v10[v9 + 1], src: &v10[v9], count: 4 * v11);
    v12 = &this->m_iExplicitDeleteSlots.m_Memory.m_pMemory[v9];
    if ( v12 != nullptr )
      *v12 = iSlot;
  }
  if ( p_m_WriteMutex->m_depth-- == 1 )
    _InterlockedExchange((volatile __int32 *)p_m_WriteMutex, 0);
}

//------------------------------------------------------------------------------
// Address: 0x10120200
// Name: public: struct UnpackedDataCache_t __near * CFrameSnapshotManager::GetCachedUncompressedEntity(class PackedEntity __near *)
// Source: json
//------------------------------------------------------------------------------
UnpackedDataCache_t *__thiscall CFrameSnapshotManager::GetCachedUncompressedEntity(
        CFrameSnapshotManager *this,
        PackedEntity *packedEntity)
{
  int m_nAllocationCount; // eax
  UnpackedDataCache_t *m_pMemory; // ecx
  int v5; // eax
  int v6; // ecx
  int v7; // eax
  UnpackedDataCache_t *v8; // esi
  int v9; // edx
  UnpackedDataCache_t *result; // eax
  int m_nPackedEntityCacheCounter; // edx
  int oldestValue; // [esp+10h] [ebp-4h]

  if ( this->m_PackedEntityCache.m_Size == 0 )
  {
    this->m_nPackedEntityCacheCounter = 0;
    m_nAllocationCount = this->m_PackedEntityCache.m_Memory.m_nAllocationCount;
    this->m_PackedEntityCache.m_Size = 0;
    if ( m_nAllocationCount < 128 )
      CUtlMemory<UnpackedDataCache_t,int>::Grow(
        this: &this->m_PackedEntityCache.m_Memory,
        num: 128 - m_nAllocationCount);
    this->m_PackedEntityCache.m_Size += 128;
    m_pMemory = this->m_PackedEntityCache.m_Memory.m_pMemory;
    v5 = this->m_PackedEntityCache.m_Size - 128;
    this->m_PackedEntityCache.m_pElements = m_pMemory;
    if ( v5 > 0 )
      _V_memmove(dest: &m_pMemory[128], src: m_pMemory, count: 16396 * v5);
    v6 = 0;
    if ( this->m_PackedEntityCache.m_Size > 0 )
    {
      v7 = 0;
      do
      {
        this->m_PackedEntityCache.m_Memory.m_pMemory[v7].pEntity = nullptr;
        this->m_PackedEntityCache.m_Memory.m_pMemory[v7].counter = 0;
        ++v6;
        ++v7;
      }
      while ( v6 < this->m_PackedEntityCache.m_Size );
    }
  }
  ++this->m_nPackedEntityCacheCounter;
  v8 = nullptr;
  v9 = 0;
  oldestValue = this->m_nPackedEntityCacheCounter;
  if ( this->m_PackedEntityCache.m_Size <= 0 )
  {
LABEL_15:
    m_nPackedEntityCacheCounter = this->m_nPackedEntityCacheCounter;
    v8->pEntity = packedEntity;
    v8->counter = m_nPackedEntityCacheCounter;
    v8->bits = -1;
    return v8;
  }
  else
  {
    result = this->m_PackedEntityCache.m_Memory.m_pMemory;
    while ( result->pEntity != packedEntity )
    {
      if ( result->counter < oldestValue )
      {
        oldestValue = result->counter;
        v8 = result;
      }
      ++v9;
      ++result;
      if ( v9 >= this->m_PackedEntityCache.m_Size )
        goto LABEL_15;
    }
    result->counter = this->m_nPackedEntityCacheCounter;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10120330
// Name: public: class CFrameSnapshot __near * CFrameSnapshotManager::CreateEmptySnapshot(int,int)
// Source: json
//------------------------------------------------------------------------------
CFrameSnapshot *__thiscall CFrameSnapshotManager::CreateEmptySnapshot(
        CFrameSnapshotManager *this,
        int tickcount,
        int maxEntities)
{
  CThreadFastMutex *p_m_FrameSnapshotsWriteMutex; // edi
  DWORD CurrentThreadId; // ecx
  CFrameSnapshot *v5; // eax
  CFrameSnapshot *v6; // esi
  bool v7; // zf
  CFrameSnapshotEntry *v8; // eax
  int v9; // ecx
  int *p_m_pPackedData; // eax
  DWORD v11; // ecx
  unsigned __int16 v12; // ax
  int v13; // ebx
  unsigned __int16 v14; // cx
  CFrameSnapshot *result; // eax
  UtlLinkedListElem_t<CFrameSnapshot *,unsigned short> *m_pMemory; // eax
  int v17; // ecx
  UtlLinkedListElem_t<CFrameSnapshot *,unsigned short> *v18; // esi
  UtlLinkedListElem_t<CFrameSnapshot *,unsigned short> *v19; // esi
  CFrameSnapshot *snap; // [esp+14h] [ebp-4h]
  unsigned __int16 maxEntitiesa; // [esp+24h] [ebp+Ch]

  p_m_FrameSnapshotsWriteMutex = &this->m_FrameSnapshotsWriteMutex;
  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != p_m_FrameSnapshotsWriteMutex->m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)p_m_FrameSnapshotsWriteMutex, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(a1: p_m_FrameSnapshotsWriteMutex, a2: CurrentThreadId, a3: 0);
  }
  else
  {
    ++p_m_FrameSnapshotsWriteMutex->m_depth;
  }
  v5 = (CFrameSnapshot *)CUtlMemoryPool::Alloc(this: &CFrameSnapshot::s_Allocator, amount: 0x40u);
  if ( v5 != nullptr )
  {
    v5->m_ListIndex.m_value = 0;
    v5->m_iExplicitDeleteSlots.m_Memory.m_pMemory = nullptr;
    v5->m_iExplicitDeleteSlots.m_Memory.m_nAllocationCount = 0;
    v5->m_iExplicitDeleteSlots.m_Memory.m_nGrowSize = 0;
    v5->m_iExplicitDeleteSlots.m_Size = 0;
    v5->m_iExplicitDeleteSlots.m_pElements = nullptr;
    v5->m_nReferences.m_value = 0;
    v5->m_nTempEntities = 0;
    v5->m_pTempEntities = nullptr;
    v5->m_pValidEntities = nullptr;
    _InterlockedExchange(&v5->m_nReferences.m_value, 0);
    v6 = v5;
    snap = v5;
  }
  else
  {
    snap = nullptr;
    v6 = nullptr;
  }
  _InterlockedExchangeAdd(&v6->m_nReferences.m_value, 1u);
  v7 = p_m_FrameSnapshotsWriteMutex->m_depth-- == 1;
  if ( v7 )
    _InterlockedExchange((volatile __int32 *)p_m_FrameSnapshotsWriteMutex, 0);
  v6->m_nTickCount = tickcount;
  v6->m_nNumEntities = maxEntities;
  v6->m_nValidEntities = 0;
  v6->m_pValidEntities = nullptr;
  v6->m_pHLTVEntityData = nullptr;
  v8 = (CFrameSnapshotEntry *)MemAlloc_Alloc(nSize: (12 * (unsigned __int64)(unsigned int)maxEntities) >> 32 != 0 ? -1 : 12 * maxEntities);
  v9 = maxEntities;
  v6->m_pEntities = v8;
  if ( maxEntities > 0 )
  {
    p_m_pPackedData = &v8->m_pPackedData;
    do
    {
      *(p_m_pPackedData - 2) = 0;
      *(p_m_pPackedData - 1) = -1;
      *p_m_pPackedData = 0;
      p_m_pPackedData += 3;
      --v9;
    }
    while ( v9 != 0 );
  }
  v11 = GetCurrentThreadId();
  if ( v11 != p_m_FrameSnapshotsWriteMutex->m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)p_m_FrameSnapshotsWriteMutex, v11, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(a1: p_m_FrameSnapshotsWriteMutex, a2: v11, a3: 0);
  }
  else
  {
    ++p_m_FrameSnapshotsWriteMutex->m_depth;
  }
  v12 = CUtlLinkedList<CFrameSnapshot *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CFrameSnapshot *,unsigned short>,unsigned short>>::AllocInternal(
          this: &this->m_FrameSnapshots,
          multilist: false);
  v13 = v12;
  if ( v12 == 0xFFFF )
  {
    v14 = -1;
    result = snap;
  }
  else
  {
    CUtlLinkedList<RecvTable *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<RecvTable *,unsigned short>,unsigned short>>::Unlink(
      this: (CUtlLinkedList<unsigned int,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<unsigned int,unsigned short>,unsigned short> > *)&this->m_FrameSnapshots,
      elem: v12);
    m_pMemory = this->m_FrameSnapshots.m_Memory.m_pMemory;
    v17 = v13;
    m_pMemory[v17].m_Next = -1;
    maxEntitiesa = this->m_FrameSnapshots.m_Tail;
    m_pMemory[v17].m_Previous = maxEntitiesa;
    this->m_FrameSnapshots.m_Tail = v13;
    if ( maxEntitiesa == 0xFFFF )
      this->m_FrameSnapshots.m_Head = v13;
    else
      this->m_FrameSnapshots.m_Memory.m_pMemory[maxEntitiesa].m_Next = v13;
    ++this->m_FrameSnapshots.m_ElementCount;
    v18 = this->m_FrameSnapshots.m_Memory.m_pMemory;
    v7 = &v18[v17] == nullptr;
    v19 = &v18[v17];
    result = snap;
    if ( !v7 )
      v19->m_Element = snap;
    v14 = v13;
  }
  _InterlockedExchange(&result->m_ListIndex.m_value, v14);
  v7 = p_m_FrameSnapshotsWriteMutex->m_depth-- == 1;
  if ( v7 )
    _InterlockedExchange((volatile __int32 *)p_m_FrameSnapshotsWriteMutex, 0);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101204F0
// Name: public: class PackedEntity __near * CFrameSnapshotManager::CreatePackedEntity(class CFrameSnapshot __near *,int)
// Source: json
//------------------------------------------------------------------------------
PackedEntity *__thiscall CFrameSnapshotManager::CreatePackedEntity(
        CFrameSnapshotManager *this,
        CFrameSnapshot *pSnapshot,
        int entity)
{
  CThreadFastMutex *p_m_WriteMutex; // esi
  DWORD CurrentThreadId; // ecx
  PackedEntity *v6; // eax
  PackedEntity *v7; // esi
  int v8; // eax
  PackedEntity **v9; // edi
  CFrameSnapshot *v11; // eax
  CFrameSnapshotManager *v12; // ecx
  CThreadFastMutex *v14; // [esp+Ch] [ebp-Ch]
  int v16; // [esp+14h] [ebp-4h]

  p_m_WriteMutex = &this->m_WriteMutex;
  v14 = &this->m_WriteMutex;
  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != p_m_WriteMutex->m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)p_m_WriteMutex, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(a1: p_m_WriteMutex, a2: CurrentThreadId, a3: 0);
  }
  else
  {
    ++p_m_WriteMutex->m_depth;
  }
  v6 = (PackedEntity *)CUtlMemoryPool::Alloc(this: &this->m_PackedEntitiesPool);
  v7 = v6;
  if ( v6 != nullptr )
    PackedEntity::PackedEntity(this: v6);
  v8 = CUtlLinkedList<PackedEntity *,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<PackedEntity *,int>>>::AllocInternal(
         this: &this->m_PackedEntities,
         multilist: false);
  v9 = (PackedEntity **)v8;
  if ( v8 != 0 )
  {
    CUtlLinkedList<CSpatialEntry,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CSpatialEntry,int>>>::LinkBefore(
      this: (CUtlLinkedList<decal_t *,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<decal_t *,int> > > *)&this->m_PackedEntities,
      before: 0,
      elem: v8);
    *v9 = v7;
    v16 = (int)v9;
  }
  else
  {
    v16 = 0;
  }
  if ( v14->m_depth-- == 1 )
    _InterlockedExchange((volatile __int32 *)v14, 0);
  _InterlockedExchange(&v7->m_ReferenceCount.m_value, 2);
  v11 = pSnapshot;
  v7->m_nEntityIndex = entity;
  pSnapshot->m_pEntities[entity].m_pPackedData = v16;
  v12 = this;
  if ( this->m_pPackedData[entity] != 0 )
  {
    CFrameSnapshotManager::RemoveEntityReference(this, handle: (PackedEntity **)this->m_pPackedData[entity]);
    v11 = pSnapshot;
    v12 = this;
  }
  v12->m_pPackedData[entity] = v16;
  v12->m_pSerialNumber[entity] = v11->m_pEntities[entity].m_nSerialNumber;
  *((_DWORD *)v7 + 12) ^= (*((_DWORD *)v7 + 12) ^ v11->m_nTickCount) & 0x7FFFFFFF;
  return v7;
}

//------------------------------------------------------------------------------
// Address: 0x101205F0
// Name: public: CFrameSnapshot::~CFrameSnapshot(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFrameSnapshot::~CFrameSnapshot(CFrameSnapshot *this)
{
  int v2; // ebx
  CEventInfo *v3; // edi
  int *m_pMemory; // eax

  free(pMem: this->m_pValidEntities);
  free(pMem: this->m_pEntities);
  v2 = 0;
  if ( this->m_pTempEntities != nullptr )
  {
    if ( this->m_nTempEntities > 0 )
    {
      do
      {
        v3 = this->m_pTempEntities[v2];
        if ( v3 != nullptr )
        {
          if ( v3->pData != nullptr )
            free(pMem: v3->pData);
          CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&v3->filter.m_Recipients);
          v3->filter.__vftable = (CEngineRecipientFilter_vtbl *)&IRecipientFilter::`vftable';
          free(pMem: v3);
        }
        ++v2;
      }
      while ( v2 < this->m_nTempEntities );
    }
    free(pMem: this->m_pTempEntities);
  }
  if ( this->m_pHLTVEntityData != nullptr )
    free(pMem: this->m_pHLTVEntityData);
  this->m_iExplicitDeleteSlots.m_Size = 0;
  if ( this->m_iExplicitDeleteSlots.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_iExplicitDeleteSlots.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_iExplicitDeleteSlots.m_Memory.m_pMemory);
      this->m_iExplicitDeleteSlots.m_Memory.m_pMemory = nullptr;
    }
    this->m_iExplicitDeleteSlots.m_Memory.m_nAllocationCount = 0;
  }
  m_pMemory = this->m_iExplicitDeleteSlots.m_Memory.m_pMemory;
  this->m_iExplicitDeleteSlots.m_pElements = m_pMemory;
  if ( this->m_iExplicitDeleteSlots.m_Memory.m_nGrowSize >= 0 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      this->m_iExplicitDeleteSlots.m_Memory.m_pMemory = nullptr;
    }
    this->m_iExplicitDeleteSlots.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10120850
// Name: public: virtual void CFrameSnapshotManager::LevelChanged(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFrameSnapshotManager::LevelChanged(CFrameSnapshotManager *this)
{
  CUtlLinkedList<CSpatialEntry,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CSpatialEntry,int>>>::RemoveAll(this: (CUtlLinkedList<decal_t *,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<decal_t *,int> > > *)&this->m_PackedEntities);
  CClassMemoryPool<PackedEntity>::Clear(this: &this->m_PackedEntitiesPool);
  this->m_PackedEntityCache.m_Size = 0;
  _V_memset(dest: this->m_pPackedData, fill: 0, count: 0x2000);
}

//------------------------------------------------------------------------------
// Address: 0x10120890
// Name: public: class CFrameSnapshot __near * CFrameSnapshotManager::TakeTickSnapshot(int)
// Source: json
//------------------------------------------------------------------------------
CFrameSnapshot *__thiscall CFrameSnapshotManager::TakeTickSnapshot(CFrameSnapshotManager *this, int tickcount)
{
  CFrameSnapshot *EmptySnapshot; // edi
  CFrameSnapshotEntry *m_pEntities; // esi
  int v4; // eax
  CFrameSnapshotEntry *v5; // esi
  edict_t *v6; // ebx
  CBaseClient *v7; // eax
  IClient *v8; // ecx
  unsigned __int16 *v9; // eax
  CHLTVEntityData *v10; // eax
  CFrameSnapshotManager *v11; // edx
  int v12; // ebx
  int m_nAllocationCount; // eax
  int *m_pMemory; // ecx
  int v15; // eax
  int v16; // eax
  bool v17; // sf
  int *v18; // eax
  CFrameSnapshotManager *v19; // ecx
  int v21; // [esp-8h] [ebp-101Ch]
  int v22; // [esp-8h] [ebp-101Ch]
  _WORD src[2048]; // [esp+Ch] [ebp-1008h] BYREF
  int m_Size; // [esp+100Ch] [ebp-8h]
  CFrameSnapshotManager *v25; // [esp+1010h] [ebp-4h]
  int tickcounta; // [esp+101Ch] [ebp+8h]
  int tickcountb; // [esp+101Ch] [ebp+8h]

  v25 = this;
  EmptySnapshot = CFrameSnapshotManager::CreateEmptySnapshot(this, tickcount, maxEntities: sv.num_edicts);
  m_pEntities = EmptySnapshot->m_pEntities;
  m_Size = sv.m_Clients.m_Size;
  v4 = 0;
  v5 = m_pEntities - 1;
  v6 = sv.edicts - 1;
  for ( tickcounta = 0; v4 < sv.num_edicts; tickcounta = v4 )
  {
    ++v6;
    ++v5;
    if ( v6->m_pUnk != nullptr && (v6->m_fStateFlags & 2) == 0 )
    {
      if ( v4 <= 0
        || v4 > m_Size
        || ((v7 = sv.m_Clients.m_Memory.m_pMemory[v4 - 1]) == nullptr ? (v8 = nullptr) : (v8 = &v7->IClient),
            v8->IsActive(this: v8)) )
      {
        v5->m_nSerialNumber = v6->m_NetworkSerialNumber;
        v5->m_pClass = v6->m_pNetworkable->GetServerClass(this: v6->m_pNetworkable);
        src[EmptySnapshot->m_nValidEntities++] = tickcounta;
      }
      v4 = tickcounta;
    }
    ++v4;
  }
  v9 = (unsigned __int16 *)MemAlloc_Alloc(
                             nSize: (unsigned __int64)(unsigned int)EmptySnapshot->m_nValidEntities >> 31 != 0
                           ? -1
                           : 2 * EmptySnapshot->m_nValidEntities);
  v21 = 2 * EmptySnapshot->m_nValidEntities;
  EmptySnapshot->m_pValidEntities = v9;
  _V_memcpy(dest: v9, src, count: v21);
  if ( hltv != nullptr && hltv->IsActive(this: &hltv->CBaseServer) )
  {
    v10 = (CHLTVEntityData *)MemAlloc_Alloc(
                               nSize: (unsigned __int64)(unsigned int)EmptySnapshot->m_nValidEntities >> 28 != 0
                             ? -1
                             : 16 * EmptySnapshot->m_nValidEntities);
    v22 = 16 * EmptySnapshot->m_nValidEntities;
    EmptySnapshot->m_pHLTVEntityData = v10;
    _V_memset(dest: v10, fill: 0, count: v22);
  }
  v11 = v25;
  v12 = v25->m_iExplicitDeleteSlots.m_Size;
  tickcountb = (int)v25->m_iExplicitDeleteSlots.m_Memory.m_pMemory;
  EmptySnapshot->m_iExplicitDeleteSlots.m_Size = 0;
  if ( v12 != 0 )
  {
    m_nAllocationCount = EmptySnapshot->m_iExplicitDeleteSlots.m_Memory.m_nAllocationCount;
    if ( v12 > m_nAllocationCount )
    {
      CUtlMemory<INetMessage *,int>::Grow(
        this: (CUtlMemory<S3RGBA,int> *)&EmptySnapshot->m_iExplicitDeleteSlots,
        num: v12 - m_nAllocationCount);
      v11 = v25;
    }
    EmptySnapshot->m_iExplicitDeleteSlots.m_Size += v12;
    m_pMemory = EmptySnapshot->m_iExplicitDeleteSlots.m_Memory.m_pMemory;
    v15 = EmptySnapshot->m_iExplicitDeleteSlots.m_Size - v12;
    EmptySnapshot->m_iExplicitDeleteSlots.m_pElements = m_pMemory;
    if ( v15 > 0 && v12 > 0 )
    {
      _V_memmove(dest: &m_pMemory[v12], src: m_pMemory, count: 4 * v15);
      v11 = v25;
    }
  }
  v16 = 0;
  if ( v12 > 0 )
  {
    do
    {
      EmptySnapshot->m_iExplicitDeleteSlots.m_Memory.m_pMemory[v16] = *(_DWORD *)(tickcountb + 4 * v16);
      ++v16;
    }
    while ( v16 < v12 );
    v11 = v25;
  }
  v17 = v11->m_iExplicitDeleteSlots.m_Memory.m_nGrowSize < 0;
  v11->m_iExplicitDeleteSlots.m_Size = 0;
  if ( !v17 )
  {
    v18 = v11->m_iExplicitDeleteSlots.m_Memory.m_pMemory;
    if ( v18 != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v18);
      v19 = v25;
      v25->m_iExplicitDeleteSlots.m_Memory.m_pMemory = nullptr;
      v11 = v19;
    }
    v11->m_iExplicitDeleteSlots.m_Memory.m_nAllocationCount = 0;
  }
  v11->m_iExplicitDeleteSlots.m_pElements = v11->m_iExplicitDeleteSlots.m_Memory.m_pMemory;
  return EmptySnapshot;
}

//------------------------------------------------------------------------------
// Address: 0x10120AB0
// Name: private: void CFrameSnapshotManager::DeleteFrameSnapshot(class CFrameSnapshot __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFrameSnapshotManager::DeleteFrameSnapshot(CFrameSnapshotManager *this, CFrameSnapshot *pSnapshot)
{
  int v2; // ebx
  int v3; // edi
  int m_value; // ebx
  CUtlLinkedList<CFrameSnapshot *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CFrameSnapshot *,unsigned short>,unsigned short> > *p_m_FrameSnapshots; // edi
  CFrameSnapshotManager *v6; // [esp+Ch] [ebp-4h]

  v2 = 0;
  v6 = this;
  if ( pSnapshot->m_nNumEntities > 0 )
  {
    v3 = 0;
    do
    {
      if ( pSnapshot->m_pEntities[v3].m_pPackedData != 0 )
      {
        CFrameSnapshotManager::RemoveEntityReference(
          this,
          handle: (PackedEntity **)pSnapshot->m_pEntities[v3].m_pPackedData);
        this = v6;
      }
      ++v2;
      ++v3;
    }
    while ( v2 < pSnapshot->m_nNumEntities );
  }
  m_value = (unsigned __int16)pSnapshot->m_ListIndex.m_value;
  p_m_FrameSnapshots = &this->m_FrameSnapshots;
  CUtlLinkedList<RecvTable *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<RecvTable *,unsigned short>,unsigned short>>::Unlink(
    this: (CUtlLinkedList<unsigned int,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<unsigned int,unsigned short>,unsigned short> > *)&this->m_FrameSnapshots,
    elem: pSnapshot->m_ListIndex.m_value);
  p_m_FrameSnapshots->m_Memory.m_pMemory[m_value].m_Next = p_m_FrameSnapshots->m_FirstFree;
  p_m_FrameSnapshots->m_FirstFree = m_value;
  CFrameSnapshot::~CFrameSnapshot(this: pSnapshot);
  CUtlMemoryPool::Free(this: &CFrameSnapshot::s_Allocator, memBlock: pSnapshot);
}

//------------------------------------------------------------------------------
// Address: 0x10120B20
// Name: public: void CFrameSnapshot::ReleaseReference(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFrameSnapshot::ReleaseReference(CFrameSnapshot *this)
{
  CThreadFastMutex *p_m_FrameSnapshotsWriteMutex; // esi
  DWORD CurrentThreadId; // ecx

  p_m_FrameSnapshotsWriteMutex = &framesnapshotmanager->m_FrameSnapshotsWriteMutex;
  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != p_m_FrameSnapshotsWriteMutex->m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)p_m_FrameSnapshotsWriteMutex, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(a1: p_m_FrameSnapshotsWriteMutex, a2: CurrentThreadId, a3: 0);
  }
  else
  {
    ++p_m_FrameSnapshotsWriteMutex->m_depth;
  }
  _InterlockedExchangeAdd(&this->m_nReferences.m_value, 0xFFFFFFFF);
  if ( this->m_nReferences.m_value == 0 )
    CFrameSnapshotManager::DeleteFrameSnapshot(this: &g_FrameSnapshotManager, pSnapshot: this);
  if ( p_m_FrameSnapshotsWriteMutex->m_depth-- == 1 )
    _InterlockedExchange((volatile __int32 *)p_m_FrameSnapshotsWriteMutex, 0);
}

//------------------------------------------------------------------------------
// Address: 0x10317630
// Name: _dynamic_initializer_for__CFrameSnapshot::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CFrameSnapshot::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CFrameSnapshot::s_Allocator,
    blockSize: 64,
    numElements: 64,
    growMode: 64,
    pszAllocOwner: "CFrameSnapshot pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CFrameSnapshot::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x10324280
// Name: _dynamic_atexit_destructor_for__CFrameSnapshot::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CFrameSnapshot::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CFrameSnapshot::s_Allocator);
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x1011F980
// Name: public: bool CFrameSnapshotManager::ShouldForceRepack(class CFrameSnapshot __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CFrameSnapshotManager::ShouldForceRepack(
        CFrameSnapshotManager *this,
        CFrameSnapshot *pSnapshot,
        int entity,
        int *handle)
{
  int v4; // eax
  bool result; // al

  result = false;
  if ( sv_creationtickcheck.m_pParent != nullptr && sv_creationtickcheck.m_pParent->m_Value.m_nValue != 0 )
  {
    v4 = *handle;
    if ( *handle != 0
      && (*(_DWORD *)(v4 + 48) & 0x80000000) == 0x80000000
      && g_ServerGlobalVariables.nTimestampNetworkingBase
       * ((pSnapshot->m_nTickCount - entity % g_ServerGlobalVariables.nTimestampRandomizeWindow)
        / g_ServerGlobalVariables.nTimestampNetworkingBase) != g_ServerGlobalVariables.nTimestampNetworkingBase
                                                             * (((*(_DWORD *)(v4 + 48) & 0x7FFFFFFF)
                                                               - entity
                                                               % g_ServerGlobalVariables.nTimestampRandomizeWindow)
                                                              / g_ServerGlobalVariables.nTimestampNetworkingBase) )
    {
      return true;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1011FA70
// Name: public: class PackedEntity __near * CFrameSnapshotManager::GetPreviouslySentPacket(int,int)
// Source: json
//------------------------------------------------------------------------------
PackedEntity *__thiscall CFrameSnapshotManager::GetPreviouslySentPacket(
        CFrameSnapshotManager *this,
        int iEntity,
        int iSerialNumber)
{
  int v3; // eax

  v3 = this->m_pPackedData[iEntity];
  if ( v3 != 0 && this->m_pSerialNumber[iEntity] == iSerialNumber )
    return *(PackedEntity **)v3;
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1011FAA0
// Name: public: class PackedEntity __near * CFrameSnapshotManager::GetPackedEntity(class CFrameSnapshot __near *,int)
// Source: json
//------------------------------------------------------------------------------
PackedEntity *__thiscall CFrameSnapshotManager::GetPackedEntity(
        CFrameSnapshotManager *this,
        CFrameSnapshot *pSnapshot,
        int entity)
{
  int m_pPackedData; // eax

  if ( pSnapshot != nullptr && (m_pPackedData = pSnapshot->m_pEntities[entity].m_pPackedData) != 0 )
    return *(PackedEntity **)m_pPackedData;
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1011FAD0
// Name: public: void CFrameSnapshot::AddReference(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFrameSnapshot::AddReference(CFrameSnapshot *this)
{
  _InterlockedExchangeAdd(&this->m_nReferences.m_value, 1u);
}

//------------------------------------------------------------------------------
// Address: 0x1011FEC0
// Name: public: virtual CFrameSnapshotManager::~CFrameSnapshotManager(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFrameSnapshotManager::~CFrameSnapshotManager(CFrameSnapshotManager *this)
{
  CUtlFixedMemory<UtlLinkedListElem_t<PackedEntity *,int> >::BlockHeader_t *m_pBlocks; // esi
  CUtlFixedMemory<UtlLinkedListElem_t<PackedEntity *,int> >::BlockHeader_t *v3; // [esp-4h] [ebp-10h]

  this->__vftable = (CFrameSnapshotManager_vtbl *)&CFrameSnapshotManager::`vftable';
  CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&this->m_iExplicitDeleteSlots);
  CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&this->m_PackedEntityCache);
  CUtlLinkedList<CSpatialEntry,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CSpatialEntry,int>>>::RemoveAll(this: (CUtlLinkedList<decal_t *,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<decal_t *,int> > > *)&this->m_PackedEntities);
  m_pBlocks = this->m_PackedEntities.m_Memory.m_pBlocks;
  if ( m_pBlocks != nullptr )
  {
    do
    {
      v3 = m_pBlocks;
      m_pBlocks = m_pBlocks->m_pNext;
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v3);
    }
    while ( m_pBlocks != nullptr );
    this->m_PackedEntities.m_Memory.m_pBlocks = nullptr;
    this->m_PackedEntities.m_Memory.m_nAllocationCount = 0;
  }
  CUtlMemoryPool::~CUtlMemoryPool(this: &this->m_PackedEntitiesPool);
  CUtlLinkedList<CFrameSnapshot *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CFrameSnapshot *,unsigned short>,unsigned short>>::RemoveAll(this: (CUtlLinkedList<unsigned int,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<unsigned int,unsigned short>,unsigned short> > *)&this->m_FrameSnapshots);
  if ( this->m_FrameSnapshots.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_FrameSnapshots.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_FrameSnapshots.m_Memory.m_pMemory);
      this->m_FrameSnapshots.m_Memory.m_pMemory = nullptr;
    }
    this->m_FrameSnapshots.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1011FF50
// Name: public: void CFrameSnapshotManager::BuildSnapshotList(class CFrameSnapshot __near *,class CFrameSnapshot __near *,class CReferencedSnapshotList __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFrameSnapshotManager::BuildSnapshotList(
        CFrameSnapshotManager *this,
        CFrameSnapshot *pCurrentSnapshot,
        CFrameSnapshot *pLastSnapshot,
        CReferencedSnapshotList *list)
{
  CThreadFastMutex *p_m_FrameSnapshotsWriteMutex; // esi
  DWORD CurrentThreadId; // ecx
  UtlLinkedListElem_t<CFrameSnapshot *,unsigned short> *m_pMemory; // eax
  int m_Next; // ecx
  CFrameSnapshot *m_Element; // ebx
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CFrameSnapshot **v12; // ecx
  int v13; // eax
  CFrameSnapshot **v14; // edi
  UtlLinkedListElem_t<CFrameSnapshot *,unsigned short> *v15; // eax
  int v16; // ecx
  CFrameSnapshot *v17; // eax
  CThreadFastMutex *generated_id_19; // [esp+Ch] [ebp-Ch]
  int nInsanity; // [esp+14h] [ebp-4h]

  p_m_FrameSnapshotsWriteMutex = &this->m_FrameSnapshotsWriteMutex;
  generated_id_19 = &this->m_FrameSnapshotsWriteMutex;
  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != p_m_FrameSnapshotsWriteMutex->m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)p_m_FrameSnapshotsWriteMutex, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(a1: p_m_FrameSnapshotsWriteMutex, a2: CurrentThreadId, a3: 0);
  }
  else
  {
    ++p_m_FrameSnapshotsWriteMutex->m_depth;
  }
  nInsanity = 0;
  if ( pLastSnapshot != nullptr )
  {
    if ( (unsigned __int16)pLastSnapshot->m_ListIndex.m_value == 0xFFFF
      || (m_pMemory = this->m_FrameSnapshots.m_Memory.m_pMemory,
          (m_Next = m_pMemory[(unsigned __int16)pLastSnapshot->m_ListIndex.m_value].m_Next) == 0xFFFF) )
    {
      m_Element = nullptr;
    }
    else
    {
      m_Element = m_pMemory[m_Next].m_Element;
    }
  }
  else
  {
    m_Element = pCurrentSnapshot;
  }
  if ( m_Element != nullptr )
  {
    do
    {
      _InterlockedExchangeAdd(&m_Element->m_nReferences.m_value, 1u);
      m_Size = list->m_vecSnapshots.m_Size;
      m_nAllocationCount = list->m_vecSnapshots.m_Memory.m_nAllocationCount;
      if ( m_Size + 1 > m_nAllocationCount )
        CUtlMemory<INetMessage *,int>::Grow(this: (CUtlMemory<S3RGBA,int> *)list, num: m_Size - m_nAllocationCount + 1);
      ++list->m_vecSnapshots.m_Size;
      v12 = list->m_vecSnapshots.m_Memory.m_pMemory;
      v13 = list->m_vecSnapshots.m_Size - m_Size - 1;
      list->m_vecSnapshots.m_pElements = list->m_vecSnapshots.m_Memory.m_pMemory;
      if ( v13 > 0 )
        _V_memmove(dest: &v12[m_Size + 1], src: &v12[m_Size], count: 4 * v13);
      v14 = &list->m_vecSnapshots.m_Memory.m_pMemory[m_Size];
      if ( v14 != nullptr )
        *v14 = m_Element;
      if ( ++nInsanity > 100000 )
        _Error(a1: "CFrameSnapshotManager::BuildSnapshotList:  infinite loop building list!!!");
      if ( m_Element == pCurrentSnapshot )
        break;
      if ( m_Element == nullptr
        || (unsigned __int16)m_Element->m_ListIndex.m_value == 0xFFFF
        || (v15 = this->m_FrameSnapshots.m_Memory.m_pMemory,
            (v16 = v15[(unsigned __int16)m_Element->m_ListIndex.m_value].m_Next) == 0xFFFF) )
      {
        v17 = nullptr;
      }
      else
      {
        v17 = v15[v16].m_Element;
      }
      m_Element = v17;
    }
    while ( v17 != nullptr );
    p_m_FrameSnapshotsWriteMutex = generated_id_19;
  }
  if ( p_m_FrameSnapshotsWriteMutex->m_depth-- == 1 )
    _InterlockedExchange((volatile __int32 *)p_m_FrameSnapshotsWriteMutex, 0);
}

//------------------------------------------------------------------------------
// Address: 0x101200B0
// Name: public: CFrameSnapshotManager::CFrameSnapshotManager(void)
// Source: json
//------------------------------------------------------------------------------
CFrameSnapshotManager *__thiscall CFrameSnapshotManager::CFrameSnapshotManager(CFrameSnapshotManager *this)
{
  UtlLinkedListElem_t<CFrameSnapshot *,unsigned short> *m_pMemory; // eax

  this->__vftable = (CFrameSnapshotManager_vtbl *)&CFrameSnapshotManager::`vftable';
  this->m_FrameSnapshotsWriteMutex.m_ownerID = 0;
  this->m_FrameSnapshotsWriteMutex.m_depth = 0;
  this->m_FrameSnapshots.m_Memory.m_pMemory = nullptr;
  this->m_FrameSnapshots.m_Memory.m_nAllocationCount = 0;
  this->m_FrameSnapshots.m_Memory.m_nGrowSize = 0;
  this->m_FrameSnapshots.m_LastAlloc.index = -1;
  *(_DWORD *)&this->m_FrameSnapshots.m_FirstFree = 0xFFFF;
  m_pMemory = this->m_FrameSnapshots.m_Memory.m_pMemory;
  *(_DWORD *)&this->m_FrameSnapshots.m_Head = -1;
  this->m_FrameSnapshots.m_NumAlloced = 0;
  this->m_FrameSnapshots.m_pElements = m_pMemory;
  CUtlMemoryPool::CUtlMemoryPool(
    this: &this->m_PackedEntitiesPool,
    blockSize: 52,
    numElements: 128,
    growMode: 2,
    pszAllocOwner: nullptr,
    nAlignment: 0);
  this->m_PackedEntities.m_Memory.m_pBlocks = nullptr;
  this->m_PackedEntities.m_Memory.m_nAllocationCount = 0;
  this->m_PackedEntities.m_Memory.m_nGrowSize = 0;
  this->m_PackedEntities.m_LastAlloc.m_pBlockHeader = nullptr;
  this->m_PackedEntities.m_LastAlloc.m_nIndex = -1;
  this->m_PackedEntities.m_Head = 0;
  this->m_PackedEntities.m_Tail = 0;
  this->m_PackedEntities.m_FirstFree = 0;
  this->m_PackedEntities.m_ElementCount = 0;
  this->m_PackedEntities.m_NumAlloced = 0;
  this->m_PackedEntities.m_pElements = nullptr;
  this->m_PackedEntityCache.m_Memory.m_pMemory = nullptr;
  this->m_PackedEntityCache.m_Memory.m_nAllocationCount = 0;
  this->m_PackedEntityCache.m_Memory.m_nGrowSize = 0;
  this->m_PackedEntityCache.m_Size = 0;
  this->m_PackedEntityCache.m_pElements = nullptr;
  this->m_WriteMutex.m_ownerID = 0;
  this->m_WriteMutex.m_depth = 0;
  this->m_iExplicitDeleteSlots.m_Memory.m_pMemory = nullptr;
  this->m_iExplicitDeleteSlots.m_Memory.m_nAllocationCount = 0;
  this->m_iExplicitDeleteSlots.m_Memory.m_nGrowSize = 0;
  this->m_iExplicitDeleteSlots.m_Size = 0;
  this->m_iExplicitDeleteSlots.m_pElements = nullptr;
  _V_memset(dest: this->m_pPackedData, fill: 0, count: 0x2000);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101201C0
// Name: public: void CFrameSnapshotManager::RemoveEntityReference(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFrameSnapshotManager::RemoveEntityReference(CFrameSnapshotManager *this, PackedEntity **handle)
{
  PackedEntity *v2; // ebx
  CThreadFastMutex *p_m_WriteMutex; // edi
  DWORD CurrentThreadId; // ecx
  int m_Size; // ecx
  int v7; // eax
  UnpackedDataCache_t *m_pMemory; // esi
  PackedEntity *packedEntity; // [esp+8h] [ebp-4h]

  v2 = *handle;
  packedEntity = *handle;
  if ( _InterlockedDecrement(&(*handle)->m_ReferenceCount.m_value) > 0 )
    return;
  p_m_WriteMutex = &this->m_WriteMutex;
  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != this->m_WriteMutex.m_ownerID )
  {
    if ( _InterlockedCompareExchange((volatile signed __int32 *)p_m_WriteMutex, CurrentThreadId, 0) != 0 )
    {
      _mm_pause();
      CThreadFastMutex::Lock(a1: &this->m_WriteMutex, a2: CurrentThreadId, a3: 0);
      v2 = packedEntity;
      goto LABEL_7;
    }
    v2 = packedEntity;
  }
  ++this->m_WriteMutex.m_depth;
LABEL_7:
  CUtlLinkedList<PackedEntity *,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<PackedEntity *,int>>>::Free(
    this: (CUtlLinkedList<unsigned short,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<unsigned short,int> > > *)&this->m_PackedEntities,
    elem: (int)handle);
  if ( v2 != nullptr )
    PackedEntity::~PackedEntity(this: v2);
  CUtlMemoryPool::Free(this: &this->m_PackedEntitiesPool, memBlock: v2);
  m_Size = this->m_PackedEntityCache.m_Size;
  v7 = 0;
  if ( m_Size > 0 )
  {
    m_pMemory = this->m_PackedEntityCache.m_Memory.m_pMemory;
    while ( m_pMemory->pEntity != v2 )
    {
      ++v7;
      ++m_pMemory;
      if ( v7 >= m_Size )
        goto LABEL_15;
    }
    m_pMemory->pEntity = nullptr;
    m_pMemory->counter = 0;
  }
LABEL_15:
  if ( p_m_WriteMutex->m_depth-- == 1 )
    _InterlockedExchange((volatile __int32 *)p_m_WriteMutex, 0);
}

//------------------------------------------------------------------------------
// Address: 0x10120290
// Name: public: void CFrameSnapshotManager::AddExplicitDelete(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFrameSnapshotManager::AddExplicitDelete(CFrameSnapshotManager *this, int iSlot)
{
  CThreadFastMutex *p_m_WriteMutex; // ebx
  DWORD CurrentThreadId; // ecx
  int m_Size; // ecx
  int v6; // eax
  int *m_pMemory; // edx
  int m_nAllocationCount; // eax
  int v9; // edi
  int *v10; // ecx
  int v11; // eax
  int *v12; // eax

  p_m_WriteMutex = &this->m_WriteMutex;
  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != p_m_WriteMutex->m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)p_m_WriteMutex, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(a1: p_m_WriteMutex, a2: CurrentThreadId, a3: 0);
  }
  else
  {
    ++p_m_WriteMutex->m_depth;
  }
  m_Size = this->m_iExplicitDeleteSlots.m_Size;
  v6 = 0;
  if ( m_Size <= 0 )
    goto LABEL_11;
  m_pMemory = this->m_iExplicitDeleteSlots.m_Memory.m_pMemory;
  while ( *m_pMemory != iSlot )
  {
    ++v6;
    ++m_pMemory;
    if ( v6 >= m_Size )
      goto LABEL_11;
  }
  if ( v6 == -1 )
  {
LABEL_11:
    m_nAllocationCount = this->m_iExplicitDeleteSlots.m_Memory.m_nAllocationCount;
    v9 = this->m_iExplicitDeleteSlots.m_Size;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<INetMessage *,int>::Grow(
        this: (CUtlMemory<S3RGBA,int> *)&this->m_iExplicitDeleteSlots,
        num: v9 - m_nAllocationCount + 1);
    ++this->m_iExplicitDeleteSlots.m_Size;
    v10 = this->m_iExplicitDeleteSlots.m_Memory.m_pMemory;
    v11 = this->m_iExplicitDeleteSlots.m_Size - v9 - 1;
    this->m_iExplicitDeleteSlots.m_pElements = v10;
    if ( v11 > 0 )
      _V_memmove(dest: &v10[v9 + 1], src: &v10[v9], count: 4 * v11);
    v12 = &this->m_iExplicitDeleteSlots.m_Memory.m_pMemory[v9];
    if ( v12 != nullptr )
      *v12 = iSlot;
  }
  if ( p_m_WriteMutex->m_depth-- == 1 )
    _InterlockedExchange((volatile __int32 *)p_m_WriteMutex, 0);
}

//------------------------------------------------------------------------------
// Address: 0x10120370
// Name: public: struct UnpackedDataCache_t __near * CFrameSnapshotManager::GetCachedUncompressedEntity(class PackedEntity __near *)
// Source: json
//------------------------------------------------------------------------------
UnpackedDataCache_t *__thiscall CFrameSnapshotManager::GetCachedUncompressedEntity(
        CFrameSnapshotManager *this,
        PackedEntity *packedEntity)
{
  int m_nAllocationCount; // eax
  UnpackedDataCache_t *m_pMemory; // ecx
  int v5; // eax
  int v6; // ecx
  int v7; // eax
  UnpackedDataCache_t *v8; // esi
  int v9; // edx
  UnpackedDataCache_t *result; // eax
  int m_nPackedEntityCacheCounter; // edx
  int oldestValue; // [esp+10h] [ebp-4h]

  if ( this->m_PackedEntityCache.m_Size == 0 )
  {
    this->m_nPackedEntityCacheCounter = 0;
    m_nAllocationCount = this->m_PackedEntityCache.m_Memory.m_nAllocationCount;
    this->m_PackedEntityCache.m_Size = 0;
    if ( m_nAllocationCount < 128 )
      CUtlMemory<UnpackedDataCache_t,int>::Grow(
        this: &this->m_PackedEntityCache.m_Memory,
        num: 128 - m_nAllocationCount);
    this->m_PackedEntityCache.m_Size += 128;
    m_pMemory = this->m_PackedEntityCache.m_Memory.m_pMemory;
    v5 = this->m_PackedEntityCache.m_Size - 128;
    this->m_PackedEntityCache.m_pElements = m_pMemory;
    if ( v5 > 0 )
      _V_memmove(dest: &m_pMemory[128], src: m_pMemory, count: 16396 * v5);
    v6 = 0;
    if ( this->m_PackedEntityCache.m_Size > 0 )
    {
      v7 = 0;
      do
      {
        this->m_PackedEntityCache.m_Memory.m_pMemory[v7].pEntity = nullptr;
        this->m_PackedEntityCache.m_Memory.m_pMemory[v7].counter = 0;
        ++v6;
        ++v7;
      }
      while ( v6 < this->m_PackedEntityCache.m_Size );
    }
  }
  ++this->m_nPackedEntityCacheCounter;
  v8 = nullptr;
  v9 = 0;
  oldestValue = this->m_nPackedEntityCacheCounter;
  if ( this->m_PackedEntityCache.m_Size <= 0 )
  {
LABEL_15:
    m_nPackedEntityCacheCounter = this->m_nPackedEntityCacheCounter;
    v8->pEntity = packedEntity;
    v8->counter = m_nPackedEntityCacheCounter;
    v8->bits = -1;
    return v8;
  }
  else
  {
    result = this->m_PackedEntityCache.m_Memory.m_pMemory;
    while ( result->pEntity != packedEntity )
    {
      if ( result->counter < oldestValue )
      {
        oldestValue = result->counter;
        v8 = result;
      }
      ++v9;
      ++result;
      if ( v9 >= this->m_PackedEntityCache.m_Size )
        goto LABEL_15;
    }
    result->counter = this->m_nPackedEntityCacheCounter;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101204A0
// Name: public: class CFrameSnapshot __near * CFrameSnapshotManager::CreateEmptySnapshot(int,int)
// Source: json
//------------------------------------------------------------------------------
CFrameSnapshot *__thiscall CFrameSnapshotManager::CreateEmptySnapshot(
        CFrameSnapshotManager *this,
        int tickcount,
        int maxEntities)
{
  CThreadFastMutex *p_m_FrameSnapshotsWriteMutex; // edi
  DWORD CurrentThreadId; // ecx
  CFrameSnapshot *v5; // eax
  CFrameSnapshot *v6; // esi
  bool v7; // zf
  CFrameSnapshotEntry *v8; // eax
  int v9; // ecx
  int *p_m_pPackedData; // eax
  DWORD v11; // ecx
  unsigned __int16 v12; // ax
  int v13; // ebx
  unsigned __int16 v14; // cx
  CFrameSnapshot *result; // eax
  UtlLinkedListElem_t<CFrameSnapshot *,unsigned short> *m_pMemory; // eax
  int v17; // ecx
  UtlLinkedListElem_t<CFrameSnapshot *,unsigned short> *v18; // esi
  UtlLinkedListElem_t<CFrameSnapshot *,unsigned short> *v19; // esi
  CFrameSnapshot *snap; // [esp+14h] [ebp-4h]
  unsigned __int16 maxEntitiesa; // [esp+24h] [ebp+Ch]

  p_m_FrameSnapshotsWriteMutex = &this->m_FrameSnapshotsWriteMutex;
  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != p_m_FrameSnapshotsWriteMutex->m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)p_m_FrameSnapshotsWriteMutex, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(a1: p_m_FrameSnapshotsWriteMutex, a2: CurrentThreadId, a3: 0);
  }
  else
  {
    ++p_m_FrameSnapshotsWriteMutex->m_depth;
  }
  v5 = (CFrameSnapshot *)CUtlMemoryPool::Alloc(this: &CFrameSnapshot::s_Allocator, amount: 0x40u);
  if ( v5 != nullptr )
  {
    v5->m_ListIndex.m_value = 0;
    v5->m_iExplicitDeleteSlots.m_Memory.m_pMemory = nullptr;
    v5->m_iExplicitDeleteSlots.m_Memory.m_nAllocationCount = 0;
    v5->m_iExplicitDeleteSlots.m_Memory.m_nGrowSize = 0;
    v5->m_iExplicitDeleteSlots.m_Size = 0;
    v5->m_iExplicitDeleteSlots.m_pElements = nullptr;
    v5->m_nReferences.m_value = 0;
    v5->m_nTempEntities = 0;
    v5->m_pTempEntities = nullptr;
    v5->m_pValidEntities = nullptr;
    _InterlockedExchange(&v5->m_nReferences.m_value, 0);
    v6 = v5;
    snap = v5;
  }
  else
  {
    snap = nullptr;
    v6 = nullptr;
  }
  _InterlockedExchangeAdd(&v6->m_nReferences.m_value, 1u);
  v7 = p_m_FrameSnapshotsWriteMutex->m_depth-- == 1;
  if ( v7 )
    _InterlockedExchange((volatile __int32 *)p_m_FrameSnapshotsWriteMutex, 0);
  v6->m_nTickCount = tickcount;
  v6->m_nNumEntities = maxEntities;
  v6->m_nValidEntities = 0;
  v6->m_pValidEntities = nullptr;
  v6->m_pHLTVEntityData = nullptr;
  v8 = (CFrameSnapshotEntry *)MemAlloc_Alloc(nSize: (12 * (unsigned __int64)(unsigned int)maxEntities) >> 32 != 0 ? -1 : 12 * maxEntities);
  v9 = maxEntities;
  v6->m_pEntities = v8;
  if ( maxEntities > 0 )
  {
    p_m_pPackedData = &v8->m_pPackedData;
    do
    {
      *(p_m_pPackedData - 2) = 0;
      *(p_m_pPackedData - 1) = -1;
      *p_m_pPackedData = 0;
      p_m_pPackedData += 3;
      --v9;
    }
    while ( v9 != 0 );
  }
  v11 = GetCurrentThreadId();
  if ( v11 != p_m_FrameSnapshotsWriteMutex->m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)p_m_FrameSnapshotsWriteMutex, v11, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(a1: p_m_FrameSnapshotsWriteMutex, a2: v11, a3: 0);
  }
  else
  {
    ++p_m_FrameSnapshotsWriteMutex->m_depth;
  }
  v12 = CUtlLinkedList<CFrameSnapshot *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CFrameSnapshot *,unsigned short>,unsigned short>>::AllocInternal(
          this: &this->m_FrameSnapshots,
          multilist: false);
  v13 = v12;
  if ( v12 == 0xFFFF )
  {
    v14 = -1;
    result = snap;
  }
  else
  {
    CUtlLinkedList<RecvTable *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<RecvTable *,unsigned short>,unsigned short>>::Unlink(
      this: (CUtlLinkedList<unsigned int,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<unsigned int,unsigned short>,unsigned short> > *)&this->m_FrameSnapshots,
      elem: v12);
    m_pMemory = this->m_FrameSnapshots.m_Memory.m_pMemory;
    v17 = v13;
    m_pMemory[v17].m_Next = -1;
    maxEntitiesa = this->m_FrameSnapshots.m_Tail;
    m_pMemory[v17].m_Previous = maxEntitiesa;
    this->m_FrameSnapshots.m_Tail = v13;
    if ( maxEntitiesa == 0xFFFF )
      this->m_FrameSnapshots.m_Head = v13;
    else
      this->m_FrameSnapshots.m_Memory.m_pMemory[maxEntitiesa].m_Next = v13;
    ++this->m_FrameSnapshots.m_ElementCount;
    v18 = this->m_FrameSnapshots.m_Memory.m_pMemory;
    v7 = &v18[v17] == nullptr;
    v19 = &v18[v17];
    result = snap;
    if ( !v7 )
      v19->m_Element = snap;
    v14 = v13;
  }
  _InterlockedExchange(&result->m_ListIndex.m_value, v14);
  v7 = p_m_FrameSnapshotsWriteMutex->m_depth-- == 1;
  if ( v7 )
    _InterlockedExchange((volatile __int32 *)p_m_FrameSnapshotsWriteMutex, 0);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10120660
// Name: public: class PackedEntity __near * CFrameSnapshotManager::CreatePackedEntity(class CFrameSnapshot __near *,int)
// Source: json
//------------------------------------------------------------------------------
PackedEntity *__thiscall CFrameSnapshotManager::CreatePackedEntity(
        CFrameSnapshotManager *this,
        CFrameSnapshot *pSnapshot,
        int entity)
{
  CThreadFastMutex *p_m_WriteMutex; // esi
  DWORD CurrentThreadId; // ecx
  PackedEntity *v6; // eax
  PackedEntity *v7; // esi
  int v8; // eax
  PackedEntity **v9; // edi
  CFrameSnapshot *v11; // eax
  CFrameSnapshotManager *v12; // ecx
  CThreadFastMutex *v14; // [esp+Ch] [ebp-Ch]
  int v16; // [esp+14h] [ebp-4h]

  p_m_WriteMutex = &this->m_WriteMutex;
  v14 = &this->m_WriteMutex;
  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != p_m_WriteMutex->m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)p_m_WriteMutex, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(a1: p_m_WriteMutex, a2: CurrentThreadId, a3: 0);
  }
  else
  {
    ++p_m_WriteMutex->m_depth;
  }
  v6 = (PackedEntity *)CUtlMemoryPool::Alloc(this: &this->m_PackedEntitiesPool);
  v7 = v6;
  if ( v6 != nullptr )
    PackedEntity::PackedEntity(this: v6);
  v8 = CUtlLinkedList<PackedEntity *,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<PackedEntity *,int>>>::AllocInternal(
         this: &this->m_PackedEntities,
         multilist: false);
  v9 = (PackedEntity **)v8;
  if ( v8 != 0 )
  {
    CUtlLinkedList<CSpatialEntry,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CSpatialEntry,int>>>::LinkBefore(
      this: (CUtlLinkedList<decal_t *,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<decal_t *,int> > > *)&this->m_PackedEntities,
      before: 0,
      elem: v8);
    *v9 = v7;
    v16 = (int)v9;
  }
  else
  {
    v16 = 0;
  }
  if ( v14->m_depth-- == 1 )
    _InterlockedExchange((volatile __int32 *)v14, 0);
  _InterlockedExchange(&v7->m_ReferenceCount.m_value, 2);
  v11 = pSnapshot;
  v7->m_nEntityIndex = entity;
  pSnapshot->m_pEntities[entity].m_pPackedData = v16;
  v12 = this;
  if ( this->m_pPackedData[entity] != 0 )
  {
    CFrameSnapshotManager::RemoveEntityReference(this, handle: (PackedEntity **)this->m_pPackedData[entity]);
    v11 = pSnapshot;
    v12 = this;
  }
  v12->m_pPackedData[entity] = v16;
  v12->m_pSerialNumber[entity] = v11->m_pEntities[entity].m_nSerialNumber;
  *((_DWORD *)v7 + 12) ^= (*((_DWORD *)v7 + 12) ^ v11->m_nTickCount) & 0x7FFFFFFF;
  return v7;
}

//------------------------------------------------------------------------------
// Address: 0x10120760
// Name: public: CFrameSnapshot::~CFrameSnapshot(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFrameSnapshot::~CFrameSnapshot(CFrameSnapshot *this)
{
  int v2; // ebx
  CEventInfo *v3; // edi
  int *m_pMemory; // eax

  free(pMem: this->m_pValidEntities);
  free(pMem: this->m_pEntities);
  v2 = 0;
  if ( this->m_pTempEntities != nullptr )
  {
    if ( this->m_nTempEntities > 0 )
    {
      do
      {
        v3 = this->m_pTempEntities[v2];
        if ( v3 != nullptr )
        {
          if ( v3->pData != nullptr )
            free(pMem: v3->pData);
          CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&v3->filter.m_Recipients);
          v3->filter.__vftable = (CEngineRecipientFilter_vtbl *)&IRecipientFilter::`vftable';
          free(pMem: v3);
        }
        ++v2;
      }
      while ( v2 < this->m_nTempEntities );
    }
    free(pMem: this->m_pTempEntities);
  }
  if ( this->m_pHLTVEntityData != nullptr )
    free(pMem: this->m_pHLTVEntityData);
  this->m_iExplicitDeleteSlots.m_Size = 0;
  if ( this->m_iExplicitDeleteSlots.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_iExplicitDeleteSlots.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_iExplicitDeleteSlots.m_Memory.m_pMemory);
      this->m_iExplicitDeleteSlots.m_Memory.m_pMemory = nullptr;
    }
    this->m_iExplicitDeleteSlots.m_Memory.m_nAllocationCount = 0;
  }
  m_pMemory = this->m_iExplicitDeleteSlots.m_Memory.m_pMemory;
  this->m_iExplicitDeleteSlots.m_pElements = m_pMemory;
  if ( this->m_iExplicitDeleteSlots.m_Memory.m_nGrowSize >= 0 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      this->m_iExplicitDeleteSlots.m_Memory.m_pMemory = nullptr;
    }
    this->m_iExplicitDeleteSlots.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101209C0
// Name: public: virtual void CFrameSnapshotManager::LevelChanged(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFrameSnapshotManager::LevelChanged(CFrameSnapshotManager *this)
{
  CUtlLinkedList<CSpatialEntry,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CSpatialEntry,int>>>::RemoveAll(this: (CUtlLinkedList<decal_t *,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<decal_t *,int> > > *)&this->m_PackedEntities);
  CClassMemoryPool<PackedEntity>::Clear(this: &this->m_PackedEntitiesPool);
  this->m_PackedEntityCache.m_Size = 0;
  _V_memset(dest: this->m_pPackedData, fill: 0, count: 0x2000);
}

//------------------------------------------------------------------------------
// Address: 0x10120A00
// Name: public: class CFrameSnapshot __near * CFrameSnapshotManager::TakeTickSnapshot(int)
// Source: json
//------------------------------------------------------------------------------
CFrameSnapshot *__thiscall CFrameSnapshotManager::TakeTickSnapshot(CFrameSnapshotManager *this, int tickcount)
{
  CFrameSnapshot *EmptySnapshot; // edi
  CFrameSnapshotEntry *m_pEntities; // esi
  int v4; // eax
  CFrameSnapshotEntry *v5; // esi
  edict_t *v6; // ebx
  CBaseClient *v7; // eax
  IClient *v8; // ecx
  unsigned __int16 *v9; // eax
  CHLTVEntityData *v10; // eax
  CFrameSnapshotManager *v11; // edx
  int v12; // ebx
  int m_nAllocationCount; // eax
  int *m_pMemory; // ecx
  int v15; // eax
  int v16; // eax
  bool v17; // sf
  int *v18; // eax
  CFrameSnapshotManager *v19; // ecx
  int v21; // [esp-8h] [ebp-101Ch]
  int v22; // [esp-8h] [ebp-101Ch]
  _WORD src[2048]; // [esp+Ch] [ebp-1008h] BYREF
  int m_Size; // [esp+100Ch] [ebp-8h]
  CFrameSnapshotManager *v25; // [esp+1010h] [ebp-4h]
  int tickcounta; // [esp+101Ch] [ebp+8h]
  int tickcountb; // [esp+101Ch] [ebp+8h]

  v25 = this;
  EmptySnapshot = CFrameSnapshotManager::CreateEmptySnapshot(this, tickcount, maxEntities: sv.num_edicts);
  m_pEntities = EmptySnapshot->m_pEntities;
  m_Size = sv.m_Clients.m_Size;
  v4 = 0;
  v5 = m_pEntities - 1;
  v6 = sv.edicts - 1;
  for ( tickcounta = 0; v4 < sv.num_edicts; tickcounta = v4 )
  {
    ++v6;
    ++v5;
    if ( v6->m_pUnk != nullptr && (v6->m_fStateFlags & 2) == 0 )
    {
      if ( v4 <= 0
        || v4 > m_Size
        || ((v7 = sv.m_Clients.m_Memory.m_pMemory[v4 - 1]) == nullptr ? (v8 = nullptr) : (v8 = &v7->IClient),
            v8->IsActive(this: v8)) )
      {
        v5->m_nSerialNumber = v6->m_NetworkSerialNumber;
        v5->m_pClass = v6->m_pNetworkable->GetServerClass(this: v6->m_pNetworkable);
        src[EmptySnapshot->m_nValidEntities++] = tickcounta;
      }
      v4 = tickcounta;
    }
    ++v4;
  }
  v9 = (unsigned __int16 *)MemAlloc_Alloc(
                             nSize: (unsigned __int64)(unsigned int)EmptySnapshot->m_nValidEntities >> 31 != 0
                           ? -1
                           : 2 * EmptySnapshot->m_nValidEntities);
  v21 = 2 * EmptySnapshot->m_nValidEntities;
  EmptySnapshot->m_pValidEntities = v9;
  _V_memcpy(dest: v9, src, count: v21);
  if ( hltv != nullptr && hltv->IsActive(this: &hltv->CBaseServer) )
  {
    v10 = (CHLTVEntityData *)MemAlloc_Alloc(
                               nSize: (unsigned __int64)(unsigned int)EmptySnapshot->m_nValidEntities >> 28 != 0
                             ? -1
                             : 16 * EmptySnapshot->m_nValidEntities);
    v22 = 16 * EmptySnapshot->m_nValidEntities;
    EmptySnapshot->m_pHLTVEntityData = v10;
    _V_memset(dest: v10, fill: 0, count: v22);
  }
  v11 = v25;
  v12 = v25->m_iExplicitDeleteSlots.m_Size;
  tickcountb = (int)v25->m_iExplicitDeleteSlots.m_Memory.m_pMemory;
  EmptySnapshot->m_iExplicitDeleteSlots.m_Size = 0;
  if ( v12 != 0 )
  {
    m_nAllocationCount = EmptySnapshot->m_iExplicitDeleteSlots.m_Memory.m_nAllocationCount;
    if ( v12 > m_nAllocationCount )
    {
      CUtlMemory<INetMessage *,int>::Grow(
        this: (CUtlMemory<S3RGBA,int> *)&EmptySnapshot->m_iExplicitDeleteSlots,
        num: v12 - m_nAllocationCount);
      v11 = v25;
    }
    EmptySnapshot->m_iExplicitDeleteSlots.m_Size += v12;
    m_pMemory = EmptySnapshot->m_iExplicitDeleteSlots.m_Memory.m_pMemory;
    v15 = EmptySnapshot->m_iExplicitDeleteSlots.m_Size - v12;
    EmptySnapshot->m_iExplicitDeleteSlots.m_pElements = m_pMemory;
    if ( v15 > 0 && v12 > 0 )
    {
      _V_memmove(dest: &m_pMemory[v12], src: m_pMemory, count: 4 * v15);
      v11 = v25;
    }
  }
  v16 = 0;
  if ( v12 > 0 )
  {
    do
    {
      EmptySnapshot->m_iExplicitDeleteSlots.m_Memory.m_pMemory[v16] = *(_DWORD *)(tickcountb + 4 * v16);
      ++v16;
    }
    while ( v16 < v12 );
    v11 = v25;
  }
  v17 = v11->m_iExplicitDeleteSlots.m_Memory.m_nGrowSize < 0;
  v11->m_iExplicitDeleteSlots.m_Size = 0;
  if ( !v17 )
  {
    v18 = v11->m_iExplicitDeleteSlots.m_Memory.m_pMemory;
    if ( v18 != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v18);
      v19 = v25;
      v25->m_iExplicitDeleteSlots.m_Memory.m_pMemory = nullptr;
      v11 = v19;
    }
    v11->m_iExplicitDeleteSlots.m_Memory.m_nAllocationCount = 0;
  }
  v11->m_iExplicitDeleteSlots.m_pElements = v11->m_iExplicitDeleteSlots.m_Memory.m_pMemory;
  return EmptySnapshot;
}

//------------------------------------------------------------------------------
// Address: 0x10120C20
// Name: private: void CFrameSnapshotManager::DeleteFrameSnapshot(class CFrameSnapshot __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFrameSnapshotManager::DeleteFrameSnapshot(CFrameSnapshotManager *this, CFrameSnapshot *pSnapshot)
{
  int v2; // ebx
  int v3; // edi
  int m_value; // ebx
  CUtlLinkedList<CFrameSnapshot *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CFrameSnapshot *,unsigned short>,unsigned short> > *p_m_FrameSnapshots; // edi
  CFrameSnapshotManager *v6; // [esp+Ch] [ebp-4h]

  v2 = 0;
  v6 = this;
  if ( pSnapshot->m_nNumEntities > 0 )
  {
    v3 = 0;
    do
    {
      if ( pSnapshot->m_pEntities[v3].m_pPackedData != 0 )
      {
        CFrameSnapshotManager::RemoveEntityReference(
          this,
          handle: (PackedEntity **)pSnapshot->m_pEntities[v3].m_pPackedData);
        this = v6;
      }
      ++v2;
      ++v3;
    }
    while ( v2 < pSnapshot->m_nNumEntities );
  }
  m_value = (unsigned __int16)pSnapshot->m_ListIndex.m_value;
  p_m_FrameSnapshots = &this->m_FrameSnapshots;
  CUtlLinkedList<RecvTable *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<RecvTable *,unsigned short>,unsigned short>>::Unlink(
    this: (CUtlLinkedList<unsigned int,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<unsigned int,unsigned short>,unsigned short> > *)&this->m_FrameSnapshots,
    elem: pSnapshot->m_ListIndex.m_value);
  p_m_FrameSnapshots->m_Memory.m_pMemory[m_value].m_Next = p_m_FrameSnapshots->m_FirstFree;
  p_m_FrameSnapshots->m_FirstFree = m_value;
  CFrameSnapshot::~CFrameSnapshot(this: pSnapshot);
  CUtlMemoryPool::Free(this: &CFrameSnapshot::s_Allocator, memBlock: pSnapshot);
}

//------------------------------------------------------------------------------
// Address: 0x10120C90
// Name: public: void CFrameSnapshot::ReleaseReference(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFrameSnapshot::ReleaseReference(CFrameSnapshot *this)
{
  CThreadFastMutex *p_m_FrameSnapshotsWriteMutex; // esi
  DWORD CurrentThreadId; // ecx

  p_m_FrameSnapshotsWriteMutex = &framesnapshotmanager->m_FrameSnapshotsWriteMutex;
  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != p_m_FrameSnapshotsWriteMutex->m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)p_m_FrameSnapshotsWriteMutex, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(a1: p_m_FrameSnapshotsWriteMutex, a2: CurrentThreadId, a3: 0);
  }
  else
  {
    ++p_m_FrameSnapshotsWriteMutex->m_depth;
  }
  _InterlockedExchangeAdd(&this->m_nReferences.m_value, 0xFFFFFFFF);
  if ( this->m_nReferences.m_value == 0 )
    CFrameSnapshotManager::DeleteFrameSnapshot(this: &g_FrameSnapshotManager, pSnapshot: this);
  if ( p_m_FrameSnapshotsWriteMutex->m_depth-- == 1 )
    _InterlockedExchange((volatile __int32 *)p_m_FrameSnapshotsWriteMutex, 0);
}

//------------------------------------------------------------------------------
// Address: 0x10317800
// Name: _dynamic_initializer_for__CFrameSnapshot::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CFrameSnapshot::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CFrameSnapshot::s_Allocator,
    blockSize: 64,
    numElements: 64,
    growMode: 64,
    pszAllocOwner: "CFrameSnapshot pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CFrameSnapshot::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x10324460
// Name: _dynamic_atexit_destructor_for__CFrameSnapshot::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CFrameSnapshot::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CFrameSnapshot::s_Allocator);
}

} // namespace engine_xlsp
