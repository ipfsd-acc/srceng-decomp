// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/shared/querycache.cpp
// Functions: 8
// ============================================================

#include "game\shared\querycache.h"

//------------------------------------------------------------------------------
// Address: 0x101F1270
// Name: PreUpdateQueryCache
// Source: json
//------------------------------------------------------------------------------
int PreUpdateQueryCache()
{
  mdlcache->BeginCoarseLock(this: mdlcache);
  return ((int (__thiscall *)(IMDLCache *))mdlcache->BeginLock)(a1: mdlcache);
}

//------------------------------------------------------------------------------
// Address: 0x101F1290
// Name: PostUpdateQueryCache
// Source: json
//------------------------------------------------------------------------------
int PostUpdateQueryCache()
{
  mdlcache->EndLock(this: mdlcache);
  return ((int (__thiscall *)(IMDLCache *))mdlcache->EndCoarseLock)(a1: mdlcache);
}

//------------------------------------------------------------------------------
// Address: 0x101F1320
// Name: public: int CJob::Abort(bool)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CJob::Abort(CJob *this, BOOL bDiscard)
{
  int result; // eax
  CThreadFastMutex *p_m_mutex; // edi
  DWORD CurrentThreadId; // ecx
  bool v6; // bl
  int v7; // eax
  int m_status; // [esp+10h] [ebp+8h]

  result = this->m_status;
  if ( result == 1 || result == 2 || result == 4 )
  {
    p_m_mutex = &this->m_mutex;
    CurrentThreadId = GetCurrentThreadId();
    if ( CurrentThreadId != p_m_mutex->m_ownerID
      && _InterlockedCompareExchange((volatile signed __int32 *)p_m_mutex, CurrentThreadId, 0) != 0 )
    {
      _mm_pause();
      CThreadFastMutex::Lock(a1: &this->m_mutex, a2: CurrentThreadId, a3: 0);
    }
    else
    {
      ++this->m_mutex.m_depth;
    }
    this->AddRef(this);
    switch ( this->m_status )
    {
      case 1:
      case 4:
        v6 = bDiscard;
        v7 = this->DoAbort(this, a2: bDiscard);
        this->m_status = v7;
        m_status = v7;
        if ( v6 )
          this->DoCleanup(this);
        CThreadEvent::Set(this: &this->m_CompleteEvent);
        break;
      default:
        m_status = this->m_status;
        break;
    }
    this->Release(this);
    if ( this->m_mutex.m_depth-- == 1 )
      _InterlockedExchange((volatile __int32 *)p_m_mutex, 0);
    return m_status;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101F13F0
// Name: sv_querycache_stats
// Source: json
//------------------------------------------------------------------------------
void __cdecl sv_querycache_stats()
{
  QueryCacheEntry_t *m_pHead; // eax
  int i; // ecx

  m_pHead = s_VictimList.m_pHead;
  for ( i = 0; m_pHead != nullptr; ++i )
    m_pHead = m_pHead->m_pNext;
  _Warning(
    a1: "%d queries, %d misses (%d free) suc spec = %d wasted spec=%d\n",
    s_nNumCacheQueries,
    s_nNumCacheMisses,
    i,
    s_SuccessfulSpeculatives,
    s_WastedSpeculativeUpdates);
}

//------------------------------------------------------------------------------
// Address: 0x101F1440
// Name: void InvalidateQueryCache(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InvalidateQueryCache()
{
  QueryCacheEntry_t *v0; // edx
  QueryCacheEntry_t *v1; // eax
  int i; // ecx

  v0 = nullptr;
  memset(s_HashChains, 0, sizeof(s_HashChains));
  v1 = s_QCache;
  for ( i = 1024; i != 0; --i )
  {
    v1->m_QueryParams.m_Type = EQUERY_INVALID;
    v1->m_pNext = v0;
    if ( v0 != nullptr )
      v0->m_pPrev = v1;
    v1->m_pPrev = nullptr;
    v0 = v1++;
  }
  s_VictimList.m_pHead = v0;
}

//------------------------------------------------------------------------------
// Address: 0x101F1480
// Name: public: void QueryCacheEntry_t::IssueQuery(void)
// Source: json
//------------------------------------------------------------------------------
// bad sp value at call has been detected, the output may be wrong!
void __usercall QueryCacheEntry_t::IssueQuery(QueryCacheEntry_t *this@<ecx>, int a2@<ebp>)
{
  bool v3; // cc
  float *p_z; // edi
  unsigned int v5; // eax
  IHandleEntity *v6; // ecx
  unsigned int v7; // eax
  unsigned int v8; // eax
  float *v9; // eax
  unsigned int m_Index; // eax
  IHandleEntity *m_pEntity; // ecx
  QueryCacheEntry_t *m_pPrev; // eax
  unsigned int m_nHashIdx; // ecx
  CUtlIntrusiveDList<QueryCacheEntry_t> *v14; // ecx
  QueryCacheEntry_t *m_pNext; // eax
  float x; // xmm3_4
  int y_low; // xmm4_4
  float z; // xmm5_4
  float v19; // xmm2_4
  unsigned int m_nTraceMask; // edx
  float v21; // xmm0_4
  bool v22; // al
  Vector v23; // [esp+1Ch] [ebp-E4h] BYREF
  CGameTrace result; // [esp+28h] [ebp-D8h] BYREF
  _BYTE v25[12]; // [esp+84h] [ebp-7Ch] BYREF
  CTraceFilterSimple filter; // [esp+90h] [ebp-70h] BYREF
  float v27; // [esp+A4h] [ebp-5Ch]
  float v28; // [esp+A8h] [ebp-58h]
  float v29; // [esp+ACh] [ebp-54h]
  int v30; // [esp+B4h] [ebp-4Ch]
  int v31; // [esp+B8h] [ebp-48h]
  int v32; // [esp+BCh] [ebp-44h]
  int v33; // [esp+C4h] [ebp-3Ch]
  int v34; // [esp+C8h] [ebp-38h]
  int v35; // [esp+CCh] [ebp-34h]
  int v36; // [esp+D4h] [ebp-2Ch]
  char v37; // [esp+D8h] [ebp-28h]
  bool v38; // [esp+D9h] [ebp-27h]
  int duration; // [esp+ECh] [ebp-14h]
  CHandle<CBaseEntity> *m_pEntities; // [esp+F0h] [ebp-10h]
  int v41; // [esp+F4h] [ebp-Ch]
  int i; // [esp+F8h] [ebp-8h]
  int retaddr; // [esp+100h] [ebp+0h]

  v41 = a2;
  i = retaddr;
  v3 = this->m_QueryParams.m_nNumValidPoints <= 0;
  duration = 0;
  if ( v3 )
  {
LABEL_14:
    m_Index = this->m_QueryParams.m_pEntities[2].m_Index;
    if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
      m_pEntity = nullptr;
    else
      m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
    CTraceFilterSimple::CTraceFilterSimple(
      this: (CTraceFilterSimple *)v25,
      passedict: m_pEntity,
      collisionGroup: this->m_QueryParams.m_nCollisionGroup,
      pExtraShouldHitFunc: this->m_QueryParams.m_pTraceFilterFunction);
    x = this->m_QueryParams.m_Points[0].x;
    y_low = SLODWORD(this->m_QueryParams.m_Points[0].y);
    z = this->m_QueryParams.m_Points[0].z;
    v19 = this->m_QueryParams.m_Points[1].z;
    m_nTraceMask = this->m_QueryParams.m_nTraceMask;
    v21 = this->m_QueryParams.m_Points[1].x - x;
    v28 = this->m_QueryParams.m_Points[1].y - *(float *)&y_low;
    v27 = v21;
    ++s_nNumCacheMisses;
    v29 = v19 - z;
    v38 = (float)((float)((float)(v28 * v28) + (float)(v21 * v21)) + (float)(v29 * v29)) != 0.0;
    v37 = 1;
    v35 = 0;
    v34 = 0;
    v33 = 0;
    v36 = 0;
    v32 = 0;
    v31 = 0;
    v30 = 0;
    *(float *)&filter.m_pPassEnt = x;
    filter.m_collisionGroup = y_low;
    *(float *)&filter.m_pExtraShouldHitCheckFunction = z;
    enginetrace->TraceRay(
      this: enginetrace,
      a2: (const Ray_t *)&filter.m_pPassEnt,
      a3: m_nTraceMask,
      a4: (ITraceFilter *)v25,
      a5: (CGameTrace *)&v23);
    if ( r_visualizetraces.m_pParent != nullptr && r_visualizetraces.m_pParent->m_Value.m_nValue != 0 )
      DebugDrawLine(vecAbsStart: &v23, vecAbsEnd: &result.startpos, r: 255, g: 0, b: 0, test: 1, duration: -1.0);
    v22 = result.plane.normal.z < 1.0 || result.plane.pad[0] != 0 || result.plane.pad[1] != 0;
    this->m_bResult = !v22;
    this->m_flLastUpdateTime = gpGlobals->curtime;
    return;
  }
  m_pEntities = this->m_QueryParams.m_pEntities;
  p_z = &this->m_QueryParams.m_Points[0].z;
  while ( 1 )
  {
    v5 = m_pEntities->m_Index;
    if ( m_pEntities->m_Index == -1 )
      break;
    if ( g_pEntityList->m_EntPtrArray[(unsigned __int16)v5].m_SerialNumber != HIWORD(v5) )
      break;
    v6 = g_pEntityList->m_EntPtrArray[(unsigned __int16)v5].m_pEntity;
    if ( v6 == nullptr )
      break;
    v7 = m_pEntities[3].m_Index;
    if ( v7 != 0 )
    {
      v8 = v7 - 1;
      if ( v8 != 0 )
      {
        if ( v8 == 1 )
        {
          *(p_z - 2) = 0.0;
          *(p_z - 1) = 0.0;
          *p_z = 0.0;
        }
        goto LABEL_13;
      }
      v9 = (float *)((int (__thiscall *)(IHandleEntity *, int *))v6->__vftable[42].dtr_IHandleEntity)(
                      a1: v6,
                      a2: &result.hitbox);
    }
    else
    {
      v9 = (float *)((int (__thiscall *)(IHandleEntity *))v6->__vftable[49].dtr_IHandleEntity)(a1: v6);
    }
    *(p_z - 2) = *v9;
    *(p_z - 1) = v9[1];
    *p_z = v9[2];
LABEL_13:
    ++m_pEntities;
    p_z += 3;
    if ( ++duration >= this->m_QueryParams.m_nNumValidPoints )
      goto LABEL_14;
  }
  m_pPrev = this->m_pPrev;
  m_nHashIdx = this->m_QueryParams.m_nHashIdx;
  this->m_QueryParams.m_Type = EQUERY_INVALID;
  v14 = &s_HashChains[m_nHashIdx];
  if ( m_pPrev != nullptr )
  {
    m_pPrev->m_pNext = this->m_pNext;
    if ( this->m_pNext != nullptr )
      this->m_pNext->m_pPrev = this->m_pPrev;
  }
  else if ( v14->m_pHead == this )
  {
    m_pNext = this->m_pNext;
    v14->m_pHead = this->m_pNext;
    if ( m_pNext != nullptr )
      m_pNext->m_pPrev = nullptr;
  }
  this->m_pNext = nullptr;
  this->m_pPrev = nullptr;
  this->m_pNext = s_VictimList.m_pHead;
  if ( s_VictimList.m_pHead != nullptr )
    s_VictimList.m_pHead->m_pPrev = this;
  this->m_pPrev = nullptr;
  s_VictimList.m_pHead = this;
}

//------------------------------------------------------------------------------
// Address: 0x101F1760
// Name: void ProcessQueryCacheUpdate(struct QueryCacheUpdateRecord_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ProcessQueryCacheUpdate(QueryCacheEntry_t *workItem)
{
  float curtime; // xmm0_4
  int v3; // eax
  QueryCacheEntry_t *m_pHead; // esi
  QueryCacheEntry_t *m_pNext; // eax
  float v6; // xmm1_4
  QueryCacheEntry_t *m_pPrev; // ecx
  unsigned int m_nHashIdx; // edx
  CUtlIntrusiveDList<QueryCacheEntry_t> *v9; // edx
  QueryCacheEntry_t *m_Type; // eax
  float flCurTime; // [esp+0h] [ebp-8h]
  int i; // [esp+4h] [ebp-4h]
  int savedregs; // [esp+8h] [ebp+0h] BYREF
  QueryCacheEntry_t *pNext; // [esp+10h] [ebp+8h]

  curtime = gpGlobals->curtime;
  v3 = 0;
  flCurTime = curtime;
  for ( i = 0; v3 < (int)workItem->m_pPrev; i = v3 )
  {
    m_pHead = s_HashChains[(int)workItem->m_pNext + v3].m_pHead;
    if ( m_pHead != nullptr )
    {
      do
      {
        m_pNext = m_pHead->m_pNext;
        v6 = curtime - m_pHead->m_flLastUpdateTime;
        pNext = m_pHead->m_pNext;
        if ( m_pHead->m_bUsedSinceUpdated )
        {
          if ( v6 >= m_pHead->m_QueryParams.m_flMinimumUpdateInterval )
          {
            QueryCacheEntry_t::IssueQuery(this: m_pHead, a2: (int)&savedregs);
            curtime = flCurTime;
            *(_WORD *)&m_pHead->m_bUsedSinceUpdated = 256;
          }
        }
        else if ( v6 > m_pHead->m_QueryParams.m_flMinimumUpdateInterval )
        {
          if ( m_pHead->m_bSpeculativelyDone )
            ++s_WastedSpeculativeUpdates;
          m_pPrev = m_pHead->m_pPrev;
          m_nHashIdx = m_pHead->m_QueryParams.m_nHashIdx;
          m_pHead->m_QueryParams.m_Type = EQUERY_INVALID;
          v9 = &s_HashChains[m_nHashIdx];
          if ( m_pPrev != nullptr )
          {
            m_pPrev->m_pNext = m_pNext;
            if ( m_pHead->m_pNext != nullptr )
              m_pHead->m_pNext->m_pPrev = m_pHead->m_pPrev;
          }
          else if ( v9->m_pHead == m_pHead )
          {
            v9->m_pHead = m_pNext;
            if ( m_pNext != nullptr )
              m_pNext->m_pPrev = nullptr;
          }
          m_pHead->m_pNext = nullptr;
          m_pHead->m_pPrev = nullptr;
          m_pHead->m_pNext = (QueryCacheEntry_t *)workItem->m_QueryParams.m_Type;
          m_Type = (QueryCacheEntry_t *)workItem->m_QueryParams.m_Type;
          if ( m_Type != nullptr )
            m_Type->m_pPrev = m_pHead;
          else
            workItem->m_QueryParams.m_nNumValidPoints = (int)m_pHead;
          m_pHead->m_pPrev = nullptr;
          workItem->m_QueryParams.m_Type = (EQueryType_t)m_pHead;
        }
        m_pHead = pNext;
      }
      while ( pNext != nullptr );
      v3 = i;
    }
    ++v3;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101F1980
// Name: void UpdateQueryCache(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl UpdateQueryCache()
{
  int m_nValue; // eax
  QueryCacheEntry_t *m_pHead; // ecx
  QueryCacheEntry_t **p_m_pTailPtr; // eax
  int i; // edx
  QueryCacheUpdateRecord_t workList[8]; // [esp+8h] [ebp-98h] BYREF
  CParallelProcessor<QueryCacheUpdateRecord_t,CFuncJobItemProcessor<QueryCacheUpdateRecord_t>,1> v5; // [esp+88h] [ebp-18h] BYREF

  workList[0].m_nNumHashChainsToUpdate = 256;
  workList[1].m_nStartHashChain = 256;
  workList[1].m_nNumHashChainsToUpdate = 256;
  workList[2].m_nNumHashChainsToUpdate = 256;
  workList[3].m_nNumHashChainsToUpdate = 256;
  workList[4].m_nNumHashChainsToUpdate = 256;
  workList[5].m_nNumHashChainsToUpdate = 256;
  workList[6].m_nNumHashChainsToUpdate = 256;
  workList[7].m_nNumHashChainsToUpdate = 256;
  workList[0].m_KilledList.m_pHead = nullptr;
  workList[0].m_KilledList.m_pTailPtr = nullptr;
  workList[1].m_KilledList.m_pHead = nullptr;
  workList[1].m_KilledList.m_pTailPtr = nullptr;
  workList[2].m_KilledList.m_pHead = nullptr;
  workList[2].m_KilledList.m_pTailPtr = nullptr;
  workList[3].m_KilledList.m_pHead = nullptr;
  workList[3].m_KilledList.m_pTailPtr = nullptr;
  workList[4].m_KilledList.m_pHead = nullptr;
  workList[4].m_KilledList.m_pTailPtr = nullptr;
  workList[5].m_KilledList.m_pHead = nullptr;
  workList[5].m_KilledList.m_pTailPtr = nullptr;
  workList[6].m_KilledList.m_pHead = nullptr;
  workList[6].m_KilledList.m_pTailPtr = nullptr;
  workList[7].m_KilledList.m_pHead = nullptr;
  workList[7].m_KilledList.m_pTailPtr = nullptr;
  workList[0].m_nStartHashChain = 0;
  workList[2].m_nStartHashChain = 512;
  workList[3].m_nStartHashChain = 768;
  workList[4].m_nStartHashChain = 1024;
  workList[5].m_nStartHashChain = 1280;
  workList[6].m_nStartHashChain = 1536;
  workList[7].m_nStartHashChain = 1792;
  if ( sv_disable_querycache.m_pParent != nullptr )
    m_nValue = sv_disable_querycache.m_pParent->m_Value.m_nValue;
  else
    m_nValue = 0;
  v5.m_pItems.m_value = nullptr;
  v5.m_pLimit = nullptr;
  _InterlockedExchange((volatile __int32 *)&v5.m_pItems, 0);
  v5.m_ItemProcessor.m_pfnProcess = (void (__cdecl *)(QueryCacheUpdateRecord_t *))ProcessQueryCacheUpdate;
  v5.m_ItemProcessor.m_pfnBegin = (void (__cdecl *)())PreUpdateQueryCache;
  v5.m_ItemProcessor.m_pfnEnd = (void (__cdecl *)())PostUpdateQueryCache;
  CParallelProcessor<QueryCacheUpdateRecord_t,CFuncJobItemProcessor<QueryCacheUpdateRecord_t>,1>::Run(
    this: &v5,
    pItems: workList,
    nItems: 8u,
    nChunkSize: 1,
    nMaxParallel: m_nValue != 0 ? 0 : 0x7FFFFFFF,
    pThreadPool: nullptr);
  m_pHead = s_VictimList.m_pHead;
  p_m_pTailPtr = &workList[1].m_KilledList.m_pTailPtr;
  for ( i = 2; i != 0; --i )
  {
    if ( *(p_m_pTailPtr - 5) != nullptr )
    {
      (*(p_m_pTailPtr - 4))->m_pNext = m_pHead;
      if ( s_VictimList.m_pHead != nullptr )
        s_VictimList.m_pHead->m_pPrev = *(p_m_pTailPtr - 4);
      m_pHead = *(p_m_pTailPtr - 5);
      s_VictimList.m_pHead = m_pHead;
    }
    if ( *(p_m_pTailPtr - 1) != nullptr )
    {
      (*p_m_pTailPtr)->m_pNext = m_pHead;
      if ( s_VictimList.m_pHead != nullptr )
        s_VictimList.m_pHead->m_pPrev = *p_m_pTailPtr;
      m_pHead = *(p_m_pTailPtr - 1);
      s_VictimList.m_pHead = m_pHead;
    }
    if ( p_m_pTailPtr[3] != nullptr )
    {
      p_m_pTailPtr[4]->m_pNext = m_pHead;
      if ( s_VictimList.m_pHead != nullptr )
        s_VictimList.m_pHead->m_pPrev = p_m_pTailPtr[4];
      m_pHead = p_m_pTailPtr[3];
      s_VictimList.m_pHead = m_pHead;
    }
    if ( p_m_pTailPtr[7] != nullptr )
    {
      p_m_pTailPtr[8]->m_pNext = m_pHead;
      if ( s_VictimList.m_pHead != nullptr )
        s_VictimList.m_pHead->m_pPrev = p_m_pTailPtr[8];
      m_pHead = p_m_pTailPtr[7];
      s_VictimList.m_pHead = m_pHead;
    }
    p_m_pTailPtr += 16;
  }
}
