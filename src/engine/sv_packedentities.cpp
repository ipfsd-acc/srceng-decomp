// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: engine/sv_packedentities.cpp
// Functions: 25
// ============================================================

#include "engine\sv_packedentities.h"

//------------------------------------------------------------------------------
// Address: 0x10109BF0
// Name: private: void CParallelProcessor<struct CShadowMgr::DispDecalWorkItem_t,class CMemberFuncJobItemProcessor<struct CShadowMgr::DispDecalWorkItem_t,class CShadowMgr,class CShadowMgr>,1>::DoExecute(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CParallelProcessor<CShadowMgr::DispDecalWorkItem_t,CMemberFuncJobItemProcessor<CShadowMgr::DispDecalWorkItem_t,CShadowMgr,CShadowMgr>,1>::DoExecute(
        CParallelProcessor<CShadowMgr::DispDecalWorkItem_t,CMemberFuncJobItemProcessor<CShadowMgr::DispDecalWorkItem_t,CShadowMgr,CShadowMgr>,1> *this)
{
  void (__thiscall *m_pfnBegin)(char *); // eax
  CShadowMgr::DispDecalWorkItem_t *m_pLimit; // edx
  unsigned int v4; // eax
  unsigned __int32 v5; // esi
  CShadowMgr::DispDecalWorkItem_t *v6; // ebx
  void (__thiscall *m_pfnEnd)(char *); // eax
  unsigned int v8; // [esp+4h] [ebp-8h]
  CShadowMgr::DispDecalWorkItem_t *pLimit; // [esp+8h] [ebp-4h]

  if ( this->m_pItems.m_value < this->m_pLimit )
  {
    m_pfnBegin = (void (__thiscall *)(char *))this->m_ItemProcessor.m_pfnBegin;
    if ( m_pfnBegin != nullptr )
      m_pfnBegin(a1: (char *)this->m_ItemProcessor.m_pObject + HIDWORD(this->m_ItemProcessor.m_pfnBegin));
    m_pLimit = this->m_pLimit;
    v4 = 12 * this->m_nChunkSize;
    pLimit = m_pLimit;
    v8 = v4;
    do
    {
      v5 = _InterlockedExchangeAdd((volatile signed __int32 *)&this->m_pItems, v4);
      v6 = (CShadowMgr::DispDecalWorkItem_t *)(v4 + v5);
      if ( (unsigned int)m_pLimit < v4 + v5 )
        v6 = m_pLimit;
      if ( v5 < (unsigned int)v6 )
      {
        do
        {
          ((void (__thiscall *)(char *, unsigned __int32))LODWORD(this->m_ItemProcessor.m_pfnProcess))(
            a1: (char *)this->m_ItemProcessor.m_pObject + HIDWORD(this->m_ItemProcessor.m_pfnProcess),
            a2: v5);
          v5 += 12;
        }
        while ( v5 < (unsigned int)v6 );
        m_pLimit = pLimit;
        v4 = v8;
      }
    }
    while ( v5 < (unsigned int)m_pLimit );
    m_pfnEnd = (void (__thiscall *)(char *))this->m_ItemProcessor.m_pfnEnd;
    if ( m_pfnEnd != nullptr )
      m_pfnEnd(a1: (char *)this->m_ItemProcessor.m_pObject + HIDWORD(this->m_ItemProcessor.m_pfnEnd));
  }
}

//------------------------------------------------------------------------------
// Address: 0x10110C00
// Name: public: void CParallelProcessor<struct CShadowMgr::DispDecalWorkItem_t,class CMemberFuncJobItemProcessor<struct CShadowMgr::DispDecalWorkItem_t,class CShadowMgr,class CShadowMgr>,1>::Run(struct CShadowMgr::DispDecalWorkItem_t __near *,unsigned int,int,int,class IThreadPool __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CParallelProcessor<CShadowMgr::DispDecalWorkItem_t,CMemberFuncJobItemProcessor<CShadowMgr::DispDecalWorkItem_t,CShadowMgr,CShadowMgr>,1>::Run(
        CParallelProcessor<CShadowMgr::DispDecalWorkItem_t,CMemberFuncJobItemProcessor<CShadowMgr::DispDecalWorkItem_t,CShadowMgr,CShadowMgr>,1> *this,
        CShadowMgr::DispDecalWorkItem_t *pItems,
        unsigned int nItems,
        int nChunkSize,
        int nMaxParallel,
        IThreadPool *pThreadPool)
{
  unsigned int v6; // eax
  IThreadPool *v8; // ecx
  int v9; // ebx
  int v10; // eax
  void *v11; // esp
  int i; // esi
  CFunctor *v13; // eax
  CParallelProcessor<CShadowMgr::DispDecalWorkItem_t,CMemberFuncJobItemProcessor<CShadowMgr::DispDecalWorkItem_t,CShadowMgr,CShadowMgr>,1> *v14; // ecx
  _DWORD v15[3]; // [esp+0h] [ebp-10h]
  CParallelProcessor<CShadowMgr::DispDecalWorkItem_t,CMemberFuncJobItemProcessor<CShadowMgr::DispDecalWorkItem_t,CShadowMgr,CShadowMgr>,1> *v16; // [esp+Ch] [ebp-4h]

  v6 = nItems;
  v16 = this;
  if ( nItems != 0 )
  {
    this->m_nChunkSize = nChunkSize;
    v8 = pThreadPool;
    if ( pThreadPool == nullptr )
    {
      v8 = _g_pThreadPool;
      pThreadPool = _g_pThreadPool;
    }
    _InterlockedExchange((volatile __int32 *)&this->m_pItems, (__int32)pItems);
    v9 = v6 - 1;
    if ( (int)(v6 - 1) > nMaxParallel )
      v9 = nMaxParallel;
    this->m_pLimit = &pItems[v6];
    if ( v8 == nullptr )
      goto LABEL_18;
    v10 = v8->NumThreads(this: v8);
    if ( v9 > v10 )
      v9 = v10;
    if ( v9 > 0 )
    {
      v11 = alloca(4 * v9);
      for ( i = v9; i != 0; v15[i] = nItems )
      {
        --i;
        v13 = (CFunctor *)MemAlloc_Alloc(nSize: 0x18u);
        if ( v13 != nullptr )
        {
          v14 = v16;
          v13[1].m_nUserID = 1;
          v13->__vftable = (CFunctor_vtbl *)&CMemberFunctor0<CParallelProcessor<CShadowMgr::DispDecalWorkItem_t,CMemberFuncJobItemProcessor<CShadowMgr::DispDecalWorkItem_t,CShadowMgr,CShadowMgr>,1> *,void (__thiscall CParallelProcessor<CShadowMgr::DispDecalWorkItem_t,CMemberFuncJobItemProcessor<CShadowMgr::DispDecalWorkItem_t,CShadowMgr,CShadowMgr>,1>::*)(void),CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>::`vftable'{for `CFunctor'};
          v13[1].__vftable = (CFunctor_vtbl *)&CMemberFunctor0<CParallelProcessor<CShadowMgr::DispDecalWorkItem_t,CMemberFuncJobItemProcessor<CShadowMgr::DispDecalWorkItem_t,CShadowMgr,CShadowMgr>,1> *,void (__thiscall CParallelProcessor<CShadowMgr::DispDecalWorkItem_t,CMemberFuncJobItemProcessor<CShadowMgr::DispDecalWorkItem_t,CShadowMgr,CShadowMgr>,1>::*)(void),CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>::`vftable'{for `CRefCountServiceBase<1,CRefMT>'};
          v13[2].__vftable = (CFunctor_vtbl *)CParallelProcessor<CShadowMgr::DispDecalWorkItem_t,CMemberFuncJobItemProcessor<CShadowMgr::DispDecalWorkItem_t,CShadowMgr,CShadowMgr>,1>::DoExecute;
          v13[2].m_nUserID = (unsigned int)v14;
        }
        else
        {
          v13 = nullptr;
        }
        pThreadPool->AddFunctorInternal(this: pThreadPool, a2: v13, a3: (CJob **)&nItems, a4: nullptr, a5: 8u);
      }
      CParallelProcessor<CShadowMgr::DispDecalWorkItem_t,CMemberFuncJobItemProcessor<CShadowMgr::DispDecalWorkItem_t,CShadowMgr,CShadowMgr>,1>::DoExecute(this: v16);
      do
      {
        CJob::Abort(this: (CJob *)v15[i], bDiscard: true);
        (*(void (__thiscall **)(_DWORD))(*(_DWORD *)v15[i] + 4))(a1: v15[i]);
        ++i;
      }
      while ( i < v9 );
    }
    else
    {
LABEL_18:
      CParallelProcessor<CShadowMgr::DispDecalWorkItem_t,CMemberFuncJobItemProcessor<CShadowMgr::DispDecalWorkItem_t,CShadowMgr,CShadowMgr>,1>::DoExecute(this);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10124BB0
// Name: private: void CParallelProcessor<class CGameClient __near *,class CFuncJobItemProcessor<class CGameClient __near *>,1>::DoExecute(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CParallelProcessor<CGameClient *,CFuncJobItemProcessor<CGameClient *>,1>::DoExecute(
        CParallelProcessor<CGameClient *,CFuncJobItemProcessor<CGameClient *>,1> *this)
{
  void (*m_pfnBegin)(void); // eax
  CGameClient **m_pLimit; // ecx
  unsigned int v4; // edx
  CGameClient **v5; // esi
  CGameClient **v6; // edi
  void (*m_pfnEnd)(void); // ebx
  unsigned int v8; // [esp+4h] [ebp-8h]
  CGameClient **pLimit; // [esp+8h] [ebp-4h]

  if ( this->m_pItems.m_value < this->m_pLimit )
  {
    m_pfnBegin = this->m_ItemProcessor.m_pfnBegin;
    if ( m_pfnBegin != nullptr )
      m_pfnBegin();
    m_pLimit = this->m_pLimit;
    v4 = 4 * this->m_nChunkSize;
    pLimit = m_pLimit;
    v8 = v4;
    do
    {
      v5 = (CGameClient **)_InterlockedExchangeAdd((volatile signed __int32 *)&this->m_pItems, v4);
      v6 = (CGameClient **)((char *)v5 + v4);
      if ( m_pLimit < (CGameClient **)((char *)v5 + v4) )
        v6 = m_pLimit;
      if ( v5 < v6 )
      {
        do
          this->m_ItemProcessor.m_pfnProcess(a1: v5++);
        while ( v5 < v6 );
        m_pLimit = pLimit;
        v4 = v8;
      }
    }
    while ( v5 < m_pLimit );
    m_pfnEnd = this->m_ItemProcessor.m_pfnEnd;
    if ( m_pfnEnd != nullptr )
      m_pfnEnd();
  }
}

//------------------------------------------------------------------------------
// Address: 0x101278D0
// Name: public: void CParallelProcessor<class CGameClient __near *,class CFuncJobItemProcessor<class CGameClient __near *>,1>::Run(class CGameClient __near * __near *,unsigned int,int,int,class IThreadPool __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CParallelProcessor<CGameClient *,CFuncJobItemProcessor<CGameClient *>,1>::Run(
        CParallelProcessor<CGameClient *,CFuncJobItemProcessor<CGameClient *>,1> *this,
        CGameClient **pItems,
        unsigned int nItems,
        int nChunkSize,
        int nMaxParallel,
        IThreadPool *pThreadPool)
{
  unsigned int v6; // ebx
  IThreadPool *v8; // ecx
  CGameClient **v9; // eax
  int v10; // ebx
  int v11; // eax
  void *v12; // esp
  int i; // esi
  CFunctor *v14; // eax
  CParallelProcessor<CGameClient *,CFuncJobItemProcessor<CGameClient *>,1> *v15; // ecx
  _DWORD v16[3]; // [esp+0h] [ebp-10h]
  CParallelProcessor<CGameClient *,CFuncJobItemProcessor<CGameClient *>,1> *v17; // [esp+Ch] [ebp-4h]

  v6 = nItems;
  v17 = this;
  if ( nItems != 0 )
  {
    v8 = pThreadPool;
    this->m_nChunkSize = nChunkSize;
    if ( v8 == nullptr )
    {
      pThreadPool = _g_pThreadPool;
      v8 = _g_pThreadPool;
    }
    _InterlockedExchange((volatile __int32 *)&this->m_pItems, (__int32)pItems);
    v9 = &pItems[v6];
    v10 = v6 - 1;
    this->m_pLimit = v9;
    if ( v10 > nMaxParallel )
      v10 = nMaxParallel;
    if ( v8 == nullptr )
      goto LABEL_18;
    v11 = v8->NumThreads(this: v8);
    if ( v10 > v11 )
      v10 = v11;
    if ( v10 > 0 )
    {
      v12 = alloca(4 * v10);
      for ( i = v10; i != 0; v16[i] = nItems )
      {
        --i;
        v14 = (CFunctor *)MemAlloc_Alloc(nSize: 0x18u);
        if ( v14 != nullptr )
        {
          v15 = v17;
          v14[1].m_nUserID = 1;
          v14->__vftable = (CFunctor_vtbl *)&CMemberFunctor0<CParallelProcessor<CGameClient *,CFuncJobItemProcessor<CGameClient *>,1> *,void (__thiscall CParallelProcessor<CGameClient *,CFuncJobItemProcessor<CGameClient *>,1>::*)(void),CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>::`vftable'{for `CFunctor'};
          v14[1].__vftable = (CFunctor_vtbl *)&CMemberFunctor0<CParallelProcessor<CGameClient *,CFuncJobItemProcessor<CGameClient *>,1> *,void (__thiscall CParallelProcessor<CGameClient *,CFuncJobItemProcessor<CGameClient *>,1>::*)(void),CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>::`vftable'{for `CRefCountServiceBase<1,CRefMT>'};
          v14[2].__vftable = (CFunctor_vtbl *)CParallelProcessor<CGameClient *,CFuncJobItemProcessor<CGameClient *>,1>::DoExecute;
          v14[2].m_nUserID = (unsigned int)v15;
        }
        else
        {
          v14 = nullptr;
        }
        pThreadPool->AddFunctorInternal(this: pThreadPool, a2: v14, a3: (CJob **)&nItems, a4: nullptr, a5: 8u);
      }
      CParallelProcessor<CGameClient *,CFuncJobItemProcessor<CGameClient *>,1>::DoExecute(this: v17);
      do
      {
        CJob::Abort(this: (CJob *)v16[i], bDiscard: true);
        (*(void (__thiscall **)(_DWORD))(*(_DWORD *)v16[i] + 4))(a1: v16[i]);
        ++i;
      }
      while ( i < v10 );
    }
    else
    {
LABEL_18:
      CParallelProcessor<CGameClient *,CFuncJobItemProcessor<CGameClient *>,1>::DoExecute(this);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10128580
// Name: void SV_EnsureInstanceBaseline(class ServerClass __near *,int,void const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SV_EnsureInstanceBaseline(ServerClass *pServerClass, int iEdict, const void *pData, int nBytes)
{
  edict_t *v4; // esi
  int v5; // esi
  DWORD CurrentThreadId; // eax
  INetworkStringTable *InstanceBaselineTable; // eax
  char idString[32]; // [esp+4h] [ebp-20h] BYREF

  v4 = &sv.edicts[iEdict];
  if ( v4->m_pNetworkable == nullptr )
    _Error(a1: "SV_EnsureInstanceBaseline: edict %d missing ent", iEdict);
  v5 = (int)v4->m_pNetworkable->GetServerClass(this: v4->m_pNetworkable);
  if ( *(_DWORD *)(v5 + 16) == 0xFFFF )
  {
    V_snprintf(pDest: idString, maxLen: 32, pFormat: "%d", *(_DWORD *)(v5 + 12));
    CurrentThreadId = GetCurrentThreadId();
    if ( CurrentThreadId != g_svInstanceBaselineMutex.m_ownerID
      && _InterlockedCompareExchange((volatile signed __int32 *)&g_svInstanceBaselineMutex, CurrentThreadId, 0) != 0 )
    {
      _mm_pause();
      CThreadFastMutex::Lock(a1: &g_svInstanceBaselineMutex, a2: CurrentThreadId, a3: 0);
    }
    else
    {
      ++g_svInstanceBaselineMutex.m_depth;
    }
    InstanceBaselineTable = CBaseServer::GetInstanceBaselineTable(this: &sv);
    *(_DWORD *)(v5 + 16) = InstanceBaselineTable->AddString(
                             this: InstanceBaselineTable,
                             a2: true,
                             a3: idString,
                             a4: nBytes,
                             a5: pData);
    if ( --g_svInstanceBaselineMutex.m_depth == 0 )
      _InterlockedExchange((volatile __int32 *)&g_svInstanceBaselineMutex, 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10128660
// Name: protected: void CGameServer::AssignClassIds(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameServer::AssignClassIds(CGameServer *this)
{
  ServerClass *v2; // eax
  ServerClass *v3; // esi
  int v4; // edi
  int v5; // eax
  bool v6; // bl
  int i; // edi

  v2 = serverGameDLL->GetAllServerClasses(this: serverGameDLL);
  v3 = v2;
  v4 = 0;
  if ( v2 != nullptr )
  {
    do
    {
      v2 = v2->m_pNext;
      ++v4;
    }
    while ( v2 != nullptr );
    if ( v4 > 512 )
      _Error(a1: "CGameServer::AssignClassIds: too many server classes (%i, MAX = %i).\n", v4, 512);
  }
  this->serverclasses = v4;
  this->serverclassbits = Q_log2(val: v4) + 1;
  v5 = _CommandLine();
  v6 = (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v5 + 40))(a1: v5, a2: "-netspike") != 0;
  for ( i = 0; v3 != nullptr; v3 = v3->m_pNext )
  {
    v3->m_ClassID = i++;
    if ( v6 )
      _Msg(a1: "%d == '%s'\n", v3->m_ClassID, v3->m_pNetworkName);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10128710
// Name: char const __near * GetObjectClassName(int)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl GetObjectClassName(int objectID)
{
  edict_t *v1; // eax

  if ( objectID < 0 || objectID >= sv.num_edicts )
    return "[unknown]";
  v1 = &sv.edicts[objectID];
  if ( v1->m_pUnk != nullptr )
    return v1->m_pNetworkable->GetClassNameA(this: v1->m_pNetworkable);
  else
    return defaultValue;
}

//------------------------------------------------------------------------------
// Address: 0x10128750
// Name: private: void CParallelProcessor<struct PackWork_t,class CFuncJobItemProcessor<struct PackWork_t>,1>::DoExecute(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CParallelProcessor<PackWork_t,CFuncJobItemProcessor<PackWork_t>,1>::DoExecute(
        CParallelProcessor<PackWork_t,CFuncJobItemProcessor<PackWork_t>,1> *this)
{
  void (*m_pfnBegin)(void); // eax
  PackWork_t *m_pLimit; // edx
  unsigned int v4; // eax
  PackWork_t *v5; // esi
  PackWork_t *v6; // edi
  void (*m_pfnEnd)(void); // ebx
  unsigned int v8; // [esp+4h] [ebp-8h]
  PackWork_t *pLimit; // [esp+8h] [ebp-4h]

  if ( this->m_pItems.m_value < this->m_pLimit )
  {
    m_pfnBegin = this->m_ItemProcessor.m_pfnBegin;
    if ( m_pfnBegin != nullptr )
      m_pfnBegin();
    m_pLimit = this->m_pLimit;
    v4 = 12 * this->m_nChunkSize;
    pLimit = m_pLimit;
    v8 = v4;
    do
    {
      v5 = (PackWork_t *)_InterlockedExchangeAdd((volatile signed __int32 *)&this->m_pItems, v4);
      v6 = (PackWork_t *)((char *)v5 + v4);
      if ( m_pLimit < (PackWork_t *)((char *)v5 + v4) )
        v6 = m_pLimit;
      if ( v5 < v6 )
      {
        do
          this->m_ItemProcessor.m_pfnProcess(a1: v5++);
        while ( v5 < v6 );
        m_pLimit = pLimit;
        v4 = v8;
      }
    }
    while ( v5 < m_pLimit );
    m_pfnEnd = this->m_ItemProcessor.m_pfnEnd;
    if ( m_pfnEnd != nullptr )
      m_pfnEnd();
  }
}

//------------------------------------------------------------------------------
// Address: 0x10128820
// Name: public: void CUtlMemory<struct SVC_ClassInfo::class_s,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<SVC_ClassInfo::class_s,int>::Grow(CUtlMemory<SVC_ClassInfo::class_s,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  SVC_ClassInfo::class_s *m_pMemory; // edx
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
    v7 = 516 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (SVC_ClassInfo::class_s *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (SVC_ClassInfo::class_s *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101288C0
// Name: void PackEntities_NetworkBackDoor(int,class CGameClient __near * __near *,class CFrameSnapshot __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl PackEntities_NetworkBackDoor(int clientCount, CGameClient **clients, CFrameSnapshot *snapshot)
{
  CFrameSnapshot *v3; // ecx
  CCheckTransmitInfo *p_m_PackInfo; // edx
  int v5; // edi
  unsigned int v6; // eax
  edict_t *v7; // esi
  ServerClass *pSVClass; // [esp+4h] [ebp-4h]
  CCheckTransmitInfo *pInfo; // [esp+14h] [ebp+Ch]

  v3 = snapshot;
  p_m_PackInfo = &(*clients)->m_PackInfo;
  v5 = 0;
  pInfo = p_m_PackInfo;
  if ( snapshot->m_nValidEntities > 0 )
  {
    while ( 1 )
    {
      v6 = v3->m_pValidEntities[v5];
      pSVClass = v3->m_pEntities[v6].m_pClass;
      v7 = &sv.edicts[v6];
      CLocalNetworkBackdoor::EntState(
        this: g_pLocalNetworkBackdoor,
        iEnt: v6,
        iSerialNum: v7->m_NetworkSerialNumber,
        iClass: pSVClass->m_ClassID,
        pSendTable: pSVClass->m_pTable,
        pSourceEnt: v7->m_pUnk,
        bChanged: v7->m_fStateFlags & 1,
        bShouldTransmit: ((1 << (v6 & 0x1F)) & p_m_PackInfo->m_pTransmitEdict->m_Ints[v6 >> 5]) != 0);
      v7->m_fStateFlags &= 0xFFFFFEFE;
      CBaseEdict::GetChangeAccessor(this: v7)->m_iChangeInfoSerialNumber = 0;
      v3 = snapshot;
      if ( ++v5 >= snapshot->m_nValidEntities )
        break;
      p_m_PackInfo = pInfo;
    }
  }
  CLocalNetworkBackdoor::ProcessDormantEntities(this: g_pLocalNetworkBackdoor);
  InvalidateSharedEdictChangeInfos();
}

//------------------------------------------------------------------------------
// Address: 0x10128990
// Name: void SV_MaybeWriteSendTable(class SendTable __near *,class bf_write __near &,bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SV_MaybeWriteSendTable(SendTable *pTable, bf_write *pBuf, bool bNeedDecoder)
{
  char v3; // al
  unsigned __int8 pData[4096]; // [esp+4h] [ebp-1054h] BYREF
  SVC_SendTable v5; // [esp+1004h] [ebp-54h] BYREF

  v3 = *((_BYTE *)pTable + 16);
  if ( (v3 & 2) == 0 )
  {
    *((_BYTE *)pTable + 16) = v3 | 2;
    v5.m_bReliable = true;
    v5.m_NetChannel = nullptr;
    v5.__vftable = (SVC_SendTable_vtbl *)&SVC_SendTable::`vftable';
    v5.m_DataIn.m_bOverflow = false;
    v5.m_DataIn.m_pDebugName = nullptr;
    v5.m_DataIn.m_nDataBits = -1;
    v5.m_DataIn.m_nDataBytes = 0;
    bf_write::bf_write(this: &v5.m_DataOut);
    bf_write::StartWriting(this: &v5.m_DataOut, pData, nBytes: 4096, iStartBit: 0, nBits: -1);
    SendTable_WriteInfos(pTable, pBuf: &v5.m_DataOut);
    v5.m_bNeedsDecoder = bNeedDecoder;
    SVC_SendTable::WriteToBuffer(this: &v5, buffer: pBuf);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10128A20
// Name: void SV_MaybeWriteSendTable_R(class SendTable __near *,class bf_write __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SV_MaybeWriteSendTable_R(SendTable *pTable, bf_write *pBuf)
{
  int v2; // ebx
  int v3; // edi

  SV_MaybeWriteSendTable(pTable, pBuf, bNeedDecoder: false);
  v2 = 0;
  if ( pTable->m_nProps > 0 )
  {
    v3 = 0;
    do
    {
      if ( pTable->m_pProps[v3].m_Type == DPT_DataTable )
        SV_MaybeWriteSendTable_R(pTable: pTable->m_pProps[v3].m_pDataTable, pBuf);
      ++v2;
      ++v3;
    }
    while ( v2 < pTable->m_nProps );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10128A70
// Name: void SV_WriteSendTables(class ServerClass __near *,class bf_write __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SV_WriteSendTables(ServerClass *pClasses, bf_write *pBuf)
{
  ServerClass *v2; // edi
  int v3; // ebx
  SendTable *m_pTable; // esi
  char v5; // al
  SendTable *v6; // esi
  int v7; // edi
  unsigned __int8 pData[4096]; // [esp+Ch] [ebp-1054h] BYREF
  SVC_SendTable v9; // [esp+100Ch] [ebp-54h] BYREF
  ServerClass *pClassesa; // [esp+1068h] [ebp+8h]

  v2 = pClasses;
  DataTable_ClearWriteFlags(pClasses);
  v3 = 0;
  if ( pClasses != nullptr )
  {
    do
    {
      m_pTable = v2->m_pTable;
      v5 = *((_BYTE *)m_pTable + 16);
      if ( (v5 & 2) == 0 )
      {
        *((_BYTE *)m_pTable + 16) = v5 | 2;
        v9.m_bReliable = true;
        v9.m_NetChannel = nullptr;
        v9.__vftable = (SVC_SendTable_vtbl *)&SVC_SendTable::`vftable';
        v9.m_DataIn.m_bOverflow = false;
        v9.m_DataIn.m_pDebugName = nullptr;
        v9.m_DataIn.m_nDataBits = -1;
        v9.m_DataIn.m_nDataBytes = 0;
        bf_write::bf_write(this: &v9.m_DataOut);
        bf_write::StartWriting(this: &v9.m_DataOut, pData, nBytes: 4096, iStartBit: 0, nBits: -1);
        SendTable_WriteInfos(pTable: m_pTable, pBuf: &v9.m_DataOut);
        v9.m_bNeedsDecoder = true;
        SVC_SendTable::WriteToBuffer(this: &v9, buffer: pBuf);
      }
      v2 = v2->m_pNext;
    }
    while ( v2 != nullptr );
    v2 = pClasses;
  }
  for ( pClassesa = v2; pClassesa != nullptr; pClassesa = pClassesa->m_pNext )
  {
    v6 = pClassesa->m_pTable;
    SV_MaybeWriteSendTable(pTable: v6, pBuf, bNeedDecoder: false);
    v7 = 0;
    if ( v6->m_nProps > 0 )
    {
      do
      {
        if ( v6->m_pProps[v3].m_Type == DPT_DataTable )
          SV_MaybeWriteSendTable_R(pTable: v6->m_pProps[v3].m_pDataTable, pBuf);
        ++v7;
        ++v3;
      }
      while ( v7 < v6->m_nProps );
      v3 = 0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10128CF0
// Name: DoesEdictChangeInfoContainPropIndex
// Source: json
//------------------------------------------------------------------------------
bool __usercall DoesEdictChangeInfoContainPropIndex@<al>(
        SendTable *pSendTable@<eax>,
        const CEdictChangeInfo *pCI@<ebx>,
        int nProp)
{
  CSendTablePrecalc *m_pPrecalc; // esi
  bool result; // al
  int v5; // edi
  unsigned __int16 v6; // ax
  int p_elem; // ecx
  int v8; // eax
  int m_nChangeOffsets; // eax
  bool v10; // sf
  bool v11; // of
  CUtlMap<unsigned short,PropIndicesCollection_t,unsigned short>::Node_t search; // [esp+8h] [ebp-Ch] BYREF
  bool bFound; // [esp+13h] [ebp-1h]

  m_pPrecalc = pSendTable->m_pPrecalc;
  result = false;
  v5 = 0;
  bFound = false;
  if ( pCI->m_nChangeOffsets != 0 )
  {
    do
    {
      if ( result )
        break;
      search.key = pCI->m_ChangeOffsets[v5];
      v6 = CUtlRBTree<CUtlMap<unsigned short,PropIndicesCollection_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,PropIndicesCollection_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,PropIndicesCollection_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
             this: &m_pPrecalc->m_PropOffsetToIndexMap.m_Tree,
             &search);
      if ( v6 != 0xFFFF )
      {
        p_elem = (int)&m_pPrecalc->m_PropOffsetToIndexMap.m_Tree.m_Elements.m_pMemory[v6].m_Data.elem;
        v8 = 0;
        while ( *(unsigned __int16 *)(p_elem + 2 * v8) != nProp )
        {
          if ( (unsigned int)++v8 >= 2 )
            goto LABEL_9;
        }
        bFound = true;
      }
LABEL_9:
      m_nChangeOffsets = pCI->m_nChangeOffsets;
      v11 = __OFSUB__(++v5, m_nChangeOffsets);
      v10 = v5 - m_nChangeOffsets < 0;
      result = bFound;
    }
    while ( v10 != v11 );
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10128D80
// Name: ValidateEdictChangeInfos
// Source: json
//------------------------------------------------------------------------------
void __usercall ValidateEdictChangeInfos(
        SendTable *pTable@<esi>,
        const edict_t *pEdict,
        const int *pDeltaProps,
        int nDeltaProps)
{
  const CEdictChangeInfo *v4; // ebx
  int v5; // eax
  const SendProp *v6; // edi
  int nCurProp; // [esp+8h] [ebp-4h]

  v4 = &g_pSharedChangeInfo->m_ChangeInfos[CBaseEdict::GetChangeAccessor(this: &pEdict->CBaseEdict)->m_iChangeInfo];
  if ( CBaseEdict::GetChangeAccessor(this: &pEdict->CBaseEdict)->m_iChangeInfoSerialNumber != g_pSharedChangeInfo->m_iSerialNumber )
    v4 = nullptr;
  if ( (pEdict->m_fStateFlags & 0x100) == 0 )
  {
    for ( nCurProp = 0; nCurProp < nDeltaProps; ++nCurProp )
    {
      v5 = pDeltaProps[nCurProp];
      v6 = pTable->m_pPrecalc->m_Props.m_Memory.m_pMemory[v5];
      if ( v4 == nullptr || !DoesEdictChangeInfoContainPropIndex(pSendTable: pTable, pCI: v4, nProp: v5) )
        _Warning(
          a1: "edict %d (%s) missing prop '%s' in changeinfos\n",
          pEdict - sv.edicts,
          pTable->m_pNetTableName,
          v6->m_pVarName);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10128E30
// Name: SV_PackEntity
// Source: json
//------------------------------------------------------------------------------
void __usercall SV_PackEntity(int edictIdx@<ebx>, edict_t *edict, ServerClass *pServerClass, CFrameSnapshot *pSnapshot)
{
  bool v4; // zf
  int m_nSerialNumber; // ecx
  SendTable *m_pTable; // esi
  int m_nDataTableProxies; // eax
  PackedEntity *PreviouslySentPacket; // eax
  PackedEntity *v9; // edi
  int v10; // eax
  int v11; // ecx
  const SendProp *v12; // eax
  const char *m_pVarName; // edi
  const char *v14; // eax
  int m_pChangeFrameList; // eax
  IChangeFrameList *v16; // edi
  int v17; // eax
  int v18; // esi
  int v19; // eax
  PackedEntity *PackedEntity; // esi
  IServerUnknown *m_pUnk; // [esp-14h] [ebp-8150h]
  unsigned __int8 pData[16384]; // [esp+8h] [ebp-8134h] BYREF
  int pDeltaProps[4096]; // [esp+4008h] [ebp-4134h] BYREF
  char v24; // [esp+8008h] [ebp-134h] BYREF
  bf_write pOut; // [esp+8108h] [ebp-34h] BYREF
  PackedEntity *v26; // [esp+8120h] [ebp-1Ch]
  int nProperties; // [esp+8124h] [ebp-18h]
  CUtlMemory<CSendProxyRecipients,int> pRecipients; // [esp+8128h] [ebp-14h] BYREF
  int v29; // [esp+8134h] [ebp-8h]
  int entSerialNumber; // [esp+8138h] [ebp-4h]

  v4 = (edict->m_fStateFlags & 1) == 0;
  m_nSerialNumber = pSnapshot->m_pEntities[edictIdx].m_nSerialNumber;
  entSerialNumber = m_nSerialNumber;
  if ( v4
    && CFrameSnapshotManager::UsePreviouslySentPacket(
         this: framesnapshotmanager,
         pSnapshot,
         entity: edictIdx,
         entSerialNumber: m_nSerialNumber) != 0
    && (sv_debugmanualmode.m_pParent == nullptr || sv_debugmanualmode.m_pParent->m_Value.m_nValue == 0) )
  {
    edict->m_fStateFlags &= 0xFFFFFEFE;
    CBaseEdict::GetChangeAccessor(this: edict)->m_iChangeInfoSerialNumber = 0;
    return;
  }
  bf_write::bf_write(this: &pOut, pDebugName: "SV_PackEntity->writeBuf", pData, nBytes: 0x4000, nBits: -1);
  m_pTable = pServerClass->m_pTable;
  m_nDataTableProxies = m_pTable->m_pPrecalc->m_nDataTableProxies;
  pRecipients.m_pMemory = (CSendProxyRecipients *)&v24;
  pRecipients.m_nAllocationCount = m_nDataTableProxies;
  m_pUnk = edict->m_pUnk;
  pRecipients.m_nGrowSize = -1;
  if ( !SendTable_Encode(
          pTable: m_pTable,
          pStruct: m_pUnk,
          &pOut,
          objectID: edictIdx,
          &pRecipients,
          bNonZeroOnly: false) )
    Host_Error(error: "SV_PackEntity: SendTable_Encode returned false (ent %d).\n", edictIdx);
  SV_EnsureInstanceBaseline(pServerClass, iEdict: edictIdx, pData, nBytes: (pOut.m_iCurBit + 7) >> 3);
  nProperties = SendTable_GetNumFlatProps(pSendTable: m_pTable);
  PreviouslySentPacket = CFrameSnapshotManager::GetPreviouslySentPacket(
                           this: framesnapshotmanager,
                           iEntity: edictIdx,
                           iSerialNumber: pSnapshot->m_pEntities[edictIdx].m_nSerialNumber);
  v9 = PreviouslySentPacket;
  v26 = PreviouslySentPacket;
  if ( PreviouslySentPacket != nullptr )
  {
    v10 = SendTable_CalcDelta(
            pTable: m_pTable,
            pFromState: PreviouslySentPacket->m_pData,
            nFromBits: PreviouslySentPacket->m_nBits & 0x7FFFFFFF,
            pToState: pData,
            nToBits: pOut.m_iCurBit,
            pDeltaProps,
            nMaxDeltaProps: 4096,
            objectID: edictIdx);
    v29 = v10;
    if ( sv_validate_edict_change_infos.m_pParent != nullptr
      && sv_validate_edict_change_infos.m_pParent->m_Value.m_nValue != 0 )
    {
      ValidateEdictChangeInfos(pTable: m_pTable, pEdict: edict, pDeltaProps, nDeltaProps: v10);
      v10 = v29;
    }
    if ( v10 != 0 )
    {
      if ( (edict->m_fStateFlags & 1) == 0 )
      {
        v11 = 0;
        entSerialNumber = 0;
        if ( v10 > 0 )
        {
          do
          {
            v12 = m_pTable->m_pPrecalc->m_Props.m_Memory.m_pMemory[pDeltaProps[v11]];
            if ( (v12->m_Flags & 0x80000) == 0 )
            {
              m_pVarName = v12->m_pVarName;
              if ( edict->m_pUnk != nullptr )
                v14 = edict->m_pNetworkable->GetClassNameA(this: edict->m_pNetworkable);
              else
                v14 = defaultValue;
              _Msg(
                a1: "Entity %d (class '%s') reported ENTITY_CHANGE_NONE but '%s' changed.\n",
                edictIdx,
                v14,
                m_pVarName);
              v11 = entSerialNumber;
              v9 = v26;
            }
            entSerialNumber = ++v11;
          }
          while ( v11 < v29 );
        }
      }
    }
    else if ( PackedEntity::CompareRecipients(this: v9, recipients: &pRecipients)
           && CFrameSnapshotManager::UsePreviouslySentPacket(
                this: framesnapshotmanager,
                pSnapshot,
                entity: edictIdx,
                entSerialNumber) != 0 )
    {
      edict->m_fStateFlags &= 0xFFFFFEFE;
      CBaseEdict::GetChangeAccessor(this: edict)->m_iChangeInfoSerialNumber = 0;
      CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>::~CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>(this: (CUtlBuffer *)&pRecipients);
      return;
    }
    if ( hltv != nullptr && hltv->IsActive(this: &hltv->CBaseServer) )
    {
      m_pChangeFrameList = (int)v9->m_pChangeFrameList->Copy(this: v9->m_pChangeFrameList);
    }
    else
    {
      m_pChangeFrameList = (int)v9->m_pChangeFrameList;
      v9->m_pChangeFrameList = nullptr;
    }
    v16 = (IChangeFrameList *)m_pChangeFrameList;
    if ( m_pChangeFrameList == 0 )
      _Error(a1: "SV_PackEntity: SnagChangeFrameList returned null");
    v17 = v16->GetNumProps(this: v16);
    v18 = nProperties;
    if ( v17 != nProperties )
    {
      v19 = v16->GetNumProps(this: v16);
      _Error(a1: "SV_PackEntity: SnagChangeFrameList mismatched number of props[%d vs %d]", v18, v19);
    }
    v16->SetChangeTick(this: v16, a2: pDeltaProps, a3: v29, a4: pSnapshot->m_nTickCount);
  }
  else
  {
    v16 = AllocChangeFrameList(nProperties, iCurTick: pSnapshot->m_nTickCount);
  }
  PackedEntity = CFrameSnapshotManager::CreatePackedEntity(this: framesnapshotmanager, pSnapshot, entity: edictIdx);
  PackedEntity->m_pChangeFrameList = v16;
  PackedEntity::SetServerAndClientClass(this: PackedEntity, pServerClass, pClientClass: nullptr);
  PackedEntity::AllocAndCopyPadded(this: PackedEntity, pData, size: (pOut.m_iCurBit + 7) >> 3);
  PackedEntity::SetRecipients(this: PackedEntity, recipients: &pRecipients);
  edict->m_fStateFlags &= 0xFFFFFEFE;
  CBaseEdict::GetChangeAccessor(this: edict)->m_iChangeInfoSerialNumber = 0;
  if ( pRecipients.m_nGrowSize >= 0 && pRecipients.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: pRecipients.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x10129180
// Name: public: static void PackWork_t::Process(struct PackWork_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl PackWork_t::Process(PackWork_t *item)
{
  SV_PackEntity(
    edictIdx: item->nIdx,
    edict: item->pEdict,
    pServerClass: item->pSnapshot->m_pEntities[item->nIdx].m_pClass,
    pSnapshot: item->pSnapshot);
}

//------------------------------------------------------------------------------
// Address: 0x101291B0
// Name: void SV_WriteClassInfos(class ServerClass __near *,class bf_write __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SV_WriteClassInfos(ServerClass *pClasses, bf_write *pBuf)
{
  ServerClass *v2; // ebx
  int m_Size; // eax
  int v4; // esi
  SVC_ClassInfo::class_s *m_pMemory; // ecx
  int v6; // eax
  SVC_ClassInfo::class_s *v7; // eax
  SVC_ClassInfo::class_s *v8; // eax
  SVC_ClassInfo::class_s svclass; // [esp+8h] [ebp-230h] BYREF
  SVC_ClassInfo classinfomsg; // [esp+20Ch] [ebp-2Ch] BYREF

  v2 = pClasses;
  classinfomsg.m_bReliable = true;
  classinfomsg.m_NetChannel = nullptr;
  classinfomsg.__vftable = (SVC_ClassInfo_vtbl *)&SVC_ClassInfo::`vftable';
  memset(&classinfomsg.m_Classes, 0, sizeof(classinfomsg.m_Classes));
  classinfomsg.m_bCreateOnClient = false;
  if ( pClasses != nullptr )
  {
    do
    {
      svclass.classID = v2->m_ClassID;
      V_strncpy(pDest: svclass.datatablename, pSrc: v2->m_pTable->m_pNetTableName, maxLen: 256);
      V_strncpy(pDest: svclass.classname, pSrc: v2->m_pNetworkName, maxLen: 256);
      m_Size = classinfomsg.m_Classes.m_Size;
      v4 = classinfomsg.m_Classes.m_Size;
      if ( classinfomsg.m_Classes.m_Size + 1 > classinfomsg.m_Classes.m_Memory.m_nAllocationCount )
      {
        CUtlMemory<SVC_ClassInfo::class_s,int>::Grow(
          this: &classinfomsg.m_Classes.m_Memory,
          num: classinfomsg.m_Classes.m_Size - classinfomsg.m_Classes.m_Memory.m_nAllocationCount + 1);
        m_Size = classinfomsg.m_Classes.m_Size;
      }
      m_pMemory = classinfomsg.m_Classes.m_Memory.m_pMemory;
      classinfomsg.m_Classes.m_Size = m_Size + 1;
      v6 = m_Size - v4;
      classinfomsg.m_Classes.m_pElements = classinfomsg.m_Classes.m_Memory.m_pMemory;
      if ( v6 > 0 )
      {
        _V_memmove(
          dest: &classinfomsg.m_Classes.m_Memory.m_pMemory[v4 + 1],
          src: &classinfomsg.m_Classes.m_Memory.m_pMemory[v4],
          count: 516 * v6);
        m_pMemory = classinfomsg.m_Classes.m_Memory.m_pMemory;
      }
      v7 = &m_pMemory[v4];
      if ( v7 != nullptr )
        *v7 = svclass;
      v2 = v2->m_pNext;
    }
    while ( v2 != nullptr );
  }
  SVC_ClassInfo::WriteToBuffer(this: &classinfomsg, buffer: pBuf);
  v8 = classinfomsg.m_Classes.m_Memory.m_pMemory;
  classinfomsg.m_Classes.m_Size = 0;
  if ( classinfomsg.m_Classes.m_Memory.m_nGrowSize >= 0 )
  {
    if ( classinfomsg.m_Classes.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: classinfomsg.m_Classes.m_Memory.m_pMemory);
      v8 = nullptr;
      classinfomsg.m_Classes.m_Memory.m_pMemory = nullptr;
    }
    classinfomsg.m_Classes.m_Memory.m_nAllocationCount = 0;
  }
  classinfomsg.m_Classes.m_pElements = v8;
  if ( classinfomsg.m_Classes.m_Memory.m_nGrowSize >= 0 && v8 != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v8);
}

//------------------------------------------------------------------------------
// Address: 0x10129300
// Name: public: void CParallelProcessor<struct PackWork_t,class CFuncJobItemProcessor<struct PackWork_t>,1>::Run(struct PackWork_t __near *,unsigned int,int,int,class IThreadPool __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CParallelProcessor<PackWork_t,CFuncJobItemProcessor<PackWork_t>,1>::Run(
        CParallelProcessor<PackWork_t,CFuncJobItemProcessor<PackWork_t>,1> *this,
        PackWork_t *pItems,
        unsigned int nItems,
        int nChunkSize,
        int nMaxParallel,
        IThreadPool *pThreadPool)
{
  unsigned int v6; // eax
  IThreadPool *v8; // ecx
  int v9; // ebx
  int v10; // eax
  void *v11; // esp
  int i; // esi
  CFunctor *v13; // eax
  CParallelProcessor<PackWork_t,CFuncJobItemProcessor<PackWork_t>,1> *v14; // ecx
  _DWORD v15[3]; // [esp+0h] [ebp-10h]
  CParallelProcessor<PackWork_t,CFuncJobItemProcessor<PackWork_t>,1> *v16; // [esp+Ch] [ebp-4h]

  v6 = nItems;
  v16 = this;
  if ( nItems != 0 )
  {
    this->m_nChunkSize = nChunkSize;
    v8 = pThreadPool;
    if ( pThreadPool == nullptr )
    {
      v8 = _g_pThreadPool;
      pThreadPool = _g_pThreadPool;
    }
    _InterlockedExchange((volatile __int32 *)&this->m_pItems, (__int32)pItems);
    v9 = v6 - 1;
    if ( (int)(v6 - 1) > nMaxParallel )
      v9 = nMaxParallel;
    this->m_pLimit = &pItems[v6];
    if ( v8 == nullptr )
      goto LABEL_18;
    v10 = v8->NumThreads(this: v8);
    if ( v9 > v10 )
      v9 = v10;
    if ( v9 > 0 )
    {
      v11 = alloca(4 * v9);
      for ( i = v9; i != 0; v15[i] = nItems )
      {
        --i;
        v13 = (CFunctor *)MemAlloc_Alloc(nSize: 0x18u);
        if ( v13 != nullptr )
        {
          v14 = v16;
          v13[1].m_nUserID = 1;
          v13->__vftable = (CFunctor_vtbl *)&CMemberFunctor0<CParallelProcessor<PackWork_t,CFuncJobItemProcessor<PackWork_t>,1> *,void (__thiscall CParallelProcessor<PackWork_t,CFuncJobItemProcessor<PackWork_t>,1>::*)(void),CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>::`vftable'{for `CFunctor'};
          v13[1].__vftable = (CFunctor_vtbl *)&CMemberFunctor0<CParallelProcessor<PackWork_t,CFuncJobItemProcessor<PackWork_t>,1> *,void (__thiscall CParallelProcessor<PackWork_t,CFuncJobItemProcessor<PackWork_t>,1>::*)(void),CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>::`vftable'{for `CRefCountServiceBase<1,CRefMT>'};
          v13[2].__vftable = (CFunctor_vtbl *)CParallelProcessor<PackWork_t,CFuncJobItemProcessor<PackWork_t>,1>::DoExecute;
          v13[2].m_nUserID = (unsigned int)v14;
        }
        else
        {
          v13 = nullptr;
        }
        pThreadPool->AddFunctorInternal(this: pThreadPool, a2: v13, a3: (CJob **)&nItems, a4: nullptr, a5: 8u);
      }
      CParallelProcessor<PackWork_t,CFuncJobItemProcessor<PackWork_t>,1>::DoExecute(this: v16);
      do
      {
        CJob::Abort(this: (CJob *)v15[i], bDiscard: true);
        (*(void (__thiscall **)(_DWORD))(*(_DWORD *)v15[i] + 4))(a1: v15[i]);
        ++i;
      }
      while ( i < v9 );
    }
    else
    {
LABEL_18:
      CParallelProcessor<PackWork_t,CFuncJobItemProcessor<PackWork_t>,1>::DoExecute(this);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10129420
// Name: void PackEntities_Normal(int,class CGameClient __near * __near *,class CFrameSnapshot __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl PackEntities_Normal(int clientCount, CGameClient **clients, CFrameSnapshot *snapshot)
{
  CFrameSnapshot *v3; // eax
  signed int v4; // edi
  int v5; // ecx
  edict_t *v6; // edi
  CHLTVEntityData *m_pHLTVEntityData; // esi
  edict_t *v8; // ebx
  float *v9; // eax
  int v10; // ecx
  int v11; // edx
  int v12; // eax
  edict_t **v13; // eax
  CFrameSnapshot **p_pSnapshot; // esi
  PackWork_t pItems; // [esp+Ch] [ebp-6028h] BYREF
  CParallelProcessor<PackWork_t,CFuncJobItemProcessor<PackWork_t>,1> v16; // [esp+600Ch] [ebp-28h] BYREF
  int v17; // [esp+6024h] [ebp-10h]
  edict_t **p_pEdict; // [esp+6028h] [ebp-Ch]
  signed int v19; // [esp+602Ch] [ebp-8h]
  unsigned int v20; // [esp+6030h] [ebp-4h]

  v3 = snapshot;
  v4 = 0;
  v5 = 0;
  v19 = 0;
  v17 = 0;
  if ( snapshot->m_nValidEntities > 0 )
  {
    v20 = 0;
    p_pEdict = &pItems.pEdict;
    do
    {
      v6 = (edict_t *)v3->m_pValidEntities[v5];
      m_pHLTVEntityData = v3->m_pHLTVEntityData;
      v8 = &sv.edicts[(_DWORD)v6];
      if ( m_pHLTVEntityData != nullptr && v8 != nullptr )
      {
        v9 = (float *)v8->m_pNetworkable->GetPVSInfo(this: v8->m_pNetworkable);
        if ( *((_WORD *)v9 + 1) == 1 )
        {
          v10 = v20;
          m_pHLTVEntityData[v20 / 0x10].m_nNodeCluster = **((unsigned __int16 **)v9 + 1);
        }
        else
        {
          v11 = v20;
          m_pHLTVEntityData[v20 / 0x10].m_nNodeCluster = *(__int16 *)v9 | 0x80000000;
          v10 = v11;
        }
        *(float *)((char *)m_pHLTVEntityData->origin + v10) = v9[3];
        *(float *)((char *)&m_pHLTVEntityData->origin[1] + v10) = v9[4];
        *(float *)((char *)&m_pHLTVEntityData->origin[2] + v10) = v9[5];
      }
      v12 = 0;
      if ( clientCount > 0 )
      {
        while ( ((1 << ((unsigned __int8)v6 & 0x1F))
               & clients[v12]->m_pCurrentFrame->transmit_entity.m_Ints[(unsigned int)v6 >> 5]) == 0 )
        {
          if ( ++v12 >= clientCount )
            goto LABEL_14;
        }
        v13 = p_pEdict;
        ++v19;
        *(p_pEdict - 1) = v6;
        *v13 = v8;
        v13[1] = (edict_t *)snapshot;
        p_pEdict = v13 + 3;
      }
LABEL_14:
      v3 = snapshot;
      v20 += 16;
      v5 = v17 + 1;
      v17 = v5;
    }
    while ( v5 < snapshot->m_nValidEntities );
    v4 = v19;
  }
  if ( sv_parallel_packentities.m_pParent != nullptr && sv_parallel_packentities.m_pParent->m_Value.m_nValue != 0 )
  {
    v16.m_pItems.m_value = nullptr;
    v16.m_pLimit = nullptr;
    _InterlockedExchange((volatile __int32 *)&v16.m_pItems, 0);
    v16.m_ItemProcessor.m_pfnBegin = nullptr;
    v16.m_ItemProcessor.m_pfnEnd = nullptr;
    v16.m_ItemProcessor.m_pfnProcess = PackWork_t::Process;
    CParallelProcessor<PackWork_t,CFuncJobItemProcessor<PackWork_t>,1>::Run(
      this: &v16,
      &pItems,
      nItems: v4,
      nChunkSize: 1,
      nMaxParallel: 0x7FFFFFFF,
      pThreadPool: nullptr);
    InvalidateSharedEdictChangeInfos();
  }
  else
  {
    if ( v4 > 0 )
    {
      p_pSnapshot = &pItems.pSnapshot;
      do
      {
        SV_PackEntity(
          edictIdx: (int)*(p_pSnapshot - 2),
          edict: (edict_t *)*(p_pSnapshot - 1),
          pServerClass: (*p_pSnapshot)->m_pEntities[(_DWORD)*(p_pSnapshot - 2)].m_pClass,
          pSnapshot: *p_pSnapshot);
        p_pSnapshot += 3;
        --v4;
      }
      while ( v4 != 0 );
    }
    InvalidateSharedEdictChangeInfos();
  }
}

//------------------------------------------------------------------------------
// Address: 0x101295B0
// Name: void SV_ComputeClientPacks(int,class CGameClient __near * __near *,class CFrameSnapshot __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SV_ComputeClientPacks(int clientCount, CGameClient **clients, CFrameSnapshot *snapshot)
{
  int i; // esi
  CGameClient *v4; // ecx
  CGameClient *v5; // eax
  int v6; // eax
  int m_nClientTick; // esi
  CClientState *BaseLocalClient; // eax
  CClientState *v9; // eax
  float flSaveLastServerTickTime; // [esp+Ch] [ebp-14h]
  int saveServerTicks; // [esp+10h] [ebp-10h]
  CCheckTransmitInfo *pInfo; // [esp+14h] [ebp-Ch]
  CCheckTransmitInfo *pInfoa; // [esp+14h] [ebp-Ch]
  CCheckTransmitInfo *pInfob; // [esp+14h] [ebp-Ch]
  float pInfoc; // [esp+14h] [ebp-Ch]
  IMDLCache *cacheCriticalSection; // [esp+18h] [ebp-8h]
  bool bSaveSimulation; // [esp+1Fh] [ebp-1h]

  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "SV_ComputeClientPacks",
    a3: 0,
    a4: "CheckTransmit",
    a5: false,
    a6: 2);
  cacheCriticalSection = g_pMDLCache;
  ((void (*)(void))g_pMDLCache->BeginLock)();
  for ( i = 0; i < clientCount; ++i )
  {
    v4 = clients[i];
    pInfo = &v4->m_PackInfo;
    CGameClient::SetupPackInfo(this: v4, pSnapshot: snapshot);
    v5 = clients[i];
    if ( v5->m_nDeltaTick < 0 )
      serverGameEnts->PrepareForFullUpdate(this: serverGameEnts, a2: v5->edict);
    serverGameEnts->CheckTransmit(
      this: serverGameEnts,
      a2: pInfo,
      a3: snapshot->m_pValidEntities,
      a4: snapshot->m_nValidEntities);
    CGameClient::SetupPrevPackInfo(this: clients[i]);
  }
  if ( g_pLocalNetworkBackdoor != nullptr )
  {
    if ( GetBaseLocalClient()->m_pServerClasses != nullptr )
    {
      v6 = (*clients)->GetMaxAckTickCount(this: &(*clients)->IClient);
      CNetworkStringTableContainer::DirectUpdate(this: sv.m_StringTables, tick_ack: v6);
      CLocalNetworkBackdoor::StartEntityStateUpdate(this: g_pLocalNetworkBackdoor);
      m_nClientTick = GetBaseLocalClient()->m_ClockDriftMgr.m_nClientTick;
      saveServerTicks = GetBaseLocalClient()->m_ClockDriftMgr.m_nServerTick;
      bSaveSimulation = GetBaseLocalClient()->insimulation;
      flSaveLastServerTickTime = GetBaseLocalClient()->m_flLastServerTickTime;
      GetBaseLocalClient()->insimulation = true;
      pInfoa = (CCheckTransmitInfo *)sv.m_nTickCount;
      GetBaseLocalClient()->m_ClockDriftMgr.m_nClientTick = (int)pInfoa;
      pInfob = (CCheckTransmitInfo *)sv.m_nTickCount;
      GetBaseLocalClient()->m_ClockDriftMgr.m_nServerTick = (int)pInfob;
      pInfoc = (float)sv.m_nTickCount * host_state.interval_per_tick;
      GetBaseLocalClient()->m_flLastServerTickTime = pInfoc;
      g_ClientGlobalVariables.tickcount = GetBaseLocalClient()->m_ClockDriftMgr.m_nClientTick;
      BaseLocalClient = GetBaseLocalClient();
      g_ClientGlobalVariables.curtime = CClientState::GetTime(this: BaseLocalClient);
      PackEntities_NetworkBackDoor(clientCount, clients, snapshot);
      CLocalNetworkBackdoor::EndEntityStateUpdate(this: g_pLocalNetworkBackdoor);
      GetBaseLocalClient()->m_ClockDriftMgr.m_nClientTick = m_nClientTick;
      GetBaseLocalClient()->m_ClockDriftMgr.m_nServerTick = saveServerTicks;
      GetBaseLocalClient()->insimulation = bSaveSimulation;
      GetBaseLocalClient()->m_flLastServerTickTime = flSaveLastServerTickTime;
      g_ClientGlobalVariables.tickcount = GetBaseLocalClient()->m_ClockDriftMgr.m_nClientTick;
      v9 = GetBaseLocalClient();
      g_ClientGlobalVariables.curtime = CClientState::GetTime(this: v9);
      PrintPartialChangeEntsList();
    }
    else
    {
      _Warning(
        a1: "Attempting to pack entities on server with invalid local client state. Probably a result of VXConsole or con com"
        "mands. Aborting SV_ComputeClientPacks.\n");
    }
  }
  else
  {
    PackEntities_Normal(clientCount, clients, snapshot);
  }
  cacheCriticalSection->EndLock(this: cacheCriticalSection);
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
}

//------------------------------------------------------------------------------
// Address: 0x10275730
// Name: private: void CParallelProcessor<int,class CMemberFuncJobItemProcessor<int,class CCallQueueT<class CTSQueue<class CFunctor __near *,0,1>>,class CCallQueueT<class CTSQueue<class CFunctor __near *,0,1>>>,1>::DoExecute(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CParallelProcessor<int,CMemberFuncJobItemProcessor<int,CCallQueueT<CTSQueue<CFunctor *,0,1>>,CCallQueueT<CTSQueue<CFunctor *,0,1>>>,1>::DoExecute(
        CParallelProcessor<int,CMemberFuncJobItemProcessor<int,CCallQueueT<CTSQueue<CFunctor *,0,1> >,CCallQueueT<CTSQueue<CFunctor *,0,1> > >,1> *this)
{
  void (__thiscall *m_pfnBegin)(CCallQueueT<CTSQueue<CFunctor *,0,1> > *); // eax
  int *m_pLimit; // ecx
  unsigned int v4; // edx
  int *v5; // esi
  int *v6; // ebx
  void (__thiscall *m_pfnEnd)(CCallQueueT<CTSQueue<CFunctor *,0,1> > *); // eax
  unsigned int v8; // [esp+4h] [ebp-8h]
  int *pLimit; // [esp+8h] [ebp-4h]

  if ( this->m_pItems.m_value < this->m_pLimit )
  {
    m_pfnBegin = this->m_ItemProcessor.m_pfnBegin;
    if ( m_pfnBegin != nullptr )
      m_pfnBegin(this: this->m_ItemProcessor.m_pObject);
    m_pLimit = this->m_pLimit;
    v4 = 4 * this->m_nChunkSize;
    pLimit = m_pLimit;
    v8 = v4;
    do
    {
      v5 = (int *)_InterlockedExchangeAdd((volatile signed __int32 *)&this->m_pItems, v4);
      v6 = (int *)((char *)v5 + v4);
      if ( m_pLimit < (int *)((char *)v5 + v4) )
        v6 = m_pLimit;
      if ( v5 < v6 )
      {
        do
          this->m_ItemProcessor.m_pfnProcess(this: this->m_ItemProcessor.m_pObject, a2: v5++);
        while ( v5 < v6 );
        m_pLimit = pLimit;
        v4 = v8;
      }
    }
    while ( v5 < m_pLimit );
    m_pfnEnd = this->m_ItemProcessor.m_pfnEnd;
    if ( m_pfnEnd != nullptr )
      m_pfnEnd(this: this->m_ItemProcessor.m_pObject);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10275830
// Name: public: void CParallelProcessor<int,class CMemberFuncJobItemProcessor<int,class CCallQueueT<class CTSQueue<class CFunctor __near *,0,1>>,class CCallQueueT<class CTSQueue<class CFunctor __near *,0,1>>>,1>::Run(int __near *,unsigned int,int,int,class IThreadPool __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CParallelProcessor<int,CMemberFuncJobItemProcessor<int,CCallQueueT<CTSQueue<CFunctor *,0,1>>,CCallQueueT<CTSQueue<CFunctor *,0,1>>>,1>::Run(
        CParallelProcessor<int,CMemberFuncJobItemProcessor<int,CCallQueueT<CTSQueue<CFunctor *,0,1> >,CCallQueueT<CTSQueue<CFunctor *,0,1> > >,1> *this,
        int *pItems,
        unsigned int nItems,
        int nChunkSize,
        int nMaxParallel,
        IThreadPool *pThreadPool)
{
  unsigned int v6; // ebx
  IThreadPool *v8; // ecx
  int *v9; // eax
  int v10; // ebx
  int v11; // eax
  void *v12; // esp
  int i; // esi
  CFunctor *v14; // eax
  CParallelProcessor<int,CMemberFuncJobItemProcessor<int,CCallQueueT<CTSQueue<CFunctor *,0,1> >,CCallQueueT<CTSQueue<CFunctor *,0,1> > >,1> *v15; // ecx
  _DWORD v16[3]; // [esp+0h] [ebp-10h]
  CParallelProcessor<int,CMemberFuncJobItemProcessor<int,CCallQueueT<CTSQueue<CFunctor *,0,1> >,CCallQueueT<CTSQueue<CFunctor *,0,1> > >,1> *v17; // [esp+Ch] [ebp-4h]

  v6 = nItems;
  v17 = this;
  if ( nItems != 0 )
  {
    v8 = pThreadPool;
    this->m_nChunkSize = nChunkSize;
    if ( v8 == nullptr )
    {
      pThreadPool = _g_pThreadPool;
      v8 = _g_pThreadPool;
    }
    _InterlockedExchange((volatile __int32 *)&this->m_pItems, (__int32)pItems);
    v9 = &pItems[v6];
    v10 = v6 - 1;
    this->m_pLimit = v9;
    if ( v10 > nMaxParallel )
      v10 = nMaxParallel;
    if ( v8 == nullptr )
      goto LABEL_18;
    v11 = v8->NumThreads(this: v8);
    if ( v10 > v11 )
      v10 = v11;
    if ( v10 > 0 )
    {
      v12 = alloca(4 * v10);
      for ( i = v10; i != 0; v16[i] = nItems )
      {
        --i;
        v14 = (CFunctor *)MemAlloc_Alloc(nSize: 0x18u);
        if ( v14 != nullptr )
        {
          v15 = v17;
          v14[1].m_nUserID = 1;
          v14->__vftable = (CFunctor_vtbl *)&CMemberFunctor0<CParallelProcessor<int,CMemberFuncJobItemProcessor<int,CCallQueueT<CTSQueue<CFunctor *,0,1>>,CCallQueueT<CTSQueue<CFunctor *,0,1>>>,1> *,void (__thiscall CParallelProcessor<int,CMemberFuncJobItemProcessor<int,CCallQueueT<CTSQueue<CFunctor *,0,1>>,CCallQueueT<CTSQueue<CFunctor *,0,1>>>,1>::*)(void),CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>::`vftable'{for `CFunctor'};
          v14[1].__vftable = (CFunctor_vtbl *)&CMemberFunctor0<CParallelProcessor<int,CMemberFuncJobItemProcessor<int,CCallQueueT<CTSQueue<CFunctor *,0,1>>,CCallQueueT<CTSQueue<CFunctor *,0,1>>>,1> *,void (__thiscall CParallelProcessor<int,CMemberFuncJobItemProcessor<int,CCallQueueT<CTSQueue<CFunctor *,0,1>>,CCallQueueT<CTSQueue<CFunctor *,0,1>>>,1>::*)(void),CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>::`vftable'{for `CRefCountServiceBase<1,CRefMT>'};
          v14[2].__vftable = (CFunctor_vtbl *)CParallelProcessor<int,CMemberFuncJobItemProcessor<int,CCallQueueT<CTSQueue<CFunctor *,0,1>>,CCallQueueT<CTSQueue<CFunctor *,0,1>>>,1>::DoExecute;
          v14[2].m_nUserID = (unsigned int)v15;
        }
        else
        {
          v14 = nullptr;
        }
        pThreadPool->AddFunctorInternal(this: pThreadPool, a2: v14, a3: (CJob **)&nItems, a4: nullptr, a5: 8u);
      }
      CParallelProcessor<int,CMemberFuncJobItemProcessor<int,CCallQueueT<CTSQueue<CFunctor *,0,1>>,CCallQueueT<CTSQueue<CFunctor *,0,1>>>,1>::DoExecute(this: v17);
      do
      {
        CJob::Abort(this: (CJob *)v16[i], bDiscard: true);
        (*(void (__thiscall **)(_DWORD))(*(_DWORD *)v16[i] + 4))(a1: v16[i]);
        ++i;
      }
      while ( i < v10 );
    }
    else
    {
LABEL_18:
      CParallelProcessor<int,CMemberFuncJobItemProcessor<int,CCallQueueT<CTSQueue<CFunctor *,0,1>>,CCallQueueT<CTSQueue<CFunctor *,0,1>>>,1>::DoExecute(this);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101287C0
// Name: protected: struct UtlRBTreeLinks_t<unsigned short> const __near & CUtlRBTree<struct CUtlMap<unsigned short,struct PropIndicesCollection_t,unsigned short>::Node_t,unsigned short,class CUtlMap<unsigned short,struct PropIndicesCollection_t,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<unsigned short,struct PropIndicesCollection_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links(unsigned short)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
UtlRBTreeNode_t<CUtlMap<unsigned short,PropIndicesCollection_t,unsigned short>::Node_t,unsigned short> *__thiscall CUtlRBTree<CUtlMap<unsigned short,PropIndicesCollection_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,PropIndicesCollection_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,PropIndicesCollection_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links(
        CUtlRBTree<CUtlMap<unsigned short,PropIndicesCollection_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,PropIndicesCollection_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,PropIndicesCollection_t,unsigned short>::Node_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 i)
{
  if ( (`CUtlRBTree<CUtlMap<unsigned short,PropIndicesCollection_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,PropIndicesCollection_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,PropIndicesCollection_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<unsigned short,PropIndicesCollection_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,PropIndicesCollection_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,PropIndicesCollection_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlMap<unsigned short,PropIndicesCollection_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,PropIndicesCollection_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,PropIndicesCollection_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
    `CUtlRBTree<CUtlMap<unsigned short,PropIndicesCollection_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,PropIndicesCollection_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,PropIndicesCollection_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
    *(_DWORD *)&`CUtlRBTree<CUtlMap<unsigned short,PropIndicesCollection_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,PropIndicesCollection_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,PropIndicesCollection_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = 0x1FFFF;
  }
  if ( i == 0xFFFF )
    return (UtlRBTreeNode_t<CUtlMap<unsigned short,PropIndicesCollection_t,unsigned short>::Node_t,unsigned short> *)&`CUtlRBTree<CUtlMap<unsigned short,PropIndicesCollection_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,PropIndicesCollection_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,PropIndicesCollection_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
  else
    return &this->m_Elements.m_pMemory[i];
}

//------------------------------------------------------------------------------
// Address: 0x10129810
// Name: __CreateCServerPluginIServerPluginHelpers_interface
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CServerPlugin *__cdecl _CreateCServerPluginIServerPluginHelpers_interface()
{
  return &s_ServerPlugin;
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x10109BE0
// Name: private: void CParallelProcessor<struct CShadowMgr::DispDecalWorkItem_t,class CMemberFuncJobItemProcessor<struct CShadowMgr::DispDecalWorkItem_t,class CShadowMgr,class CShadowMgr>,1>::DoExecute(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CParallelProcessor<CShadowMgr::DispDecalWorkItem_t,CMemberFuncJobItemProcessor<CShadowMgr::DispDecalWorkItem_t,CShadowMgr,CShadowMgr>,1>::DoExecute(
        CParallelProcessor<CShadowMgr::DispDecalWorkItem_t,CMemberFuncJobItemProcessor<CShadowMgr::DispDecalWorkItem_t,CShadowMgr,CShadowMgr>,1> *this)
{
  void (__thiscall *m_pfnBegin)(char *); // eax
  CShadowMgr::DispDecalWorkItem_t *m_pLimit; // edx
  unsigned int v4; // eax
  unsigned __int32 v5; // esi
  CShadowMgr::DispDecalWorkItem_t *v6; // ebx
  void (__thiscall *m_pfnEnd)(char *); // eax
  unsigned int v8; // [esp+4h] [ebp-8h]
  CShadowMgr::DispDecalWorkItem_t *pLimit; // [esp+8h] [ebp-4h]

  if ( this->m_pItems.m_value < this->m_pLimit )
  {
    m_pfnBegin = (void (__thiscall *)(char *))this->m_ItemProcessor.m_pfnBegin;
    if ( m_pfnBegin != nullptr )
      m_pfnBegin(a1: (char *)this->m_ItemProcessor.m_pObject + HIDWORD(this->m_ItemProcessor.m_pfnBegin));
    m_pLimit = this->m_pLimit;
    v4 = 12 * this->m_nChunkSize;
    pLimit = m_pLimit;
    v8 = v4;
    do
    {
      v5 = _InterlockedExchangeAdd((volatile signed __int32 *)&this->m_pItems, v4);
      v6 = (CShadowMgr::DispDecalWorkItem_t *)(v4 + v5);
      if ( (unsigned int)m_pLimit < v4 + v5 )
        v6 = m_pLimit;
      if ( v5 < (unsigned int)v6 )
      {
        do
        {
          ((void (__thiscall *)(char *, unsigned __int32))LODWORD(this->m_ItemProcessor.m_pfnProcess))(
            a1: (char *)this->m_ItemProcessor.m_pObject + HIDWORD(this->m_ItemProcessor.m_pfnProcess),
            a2: v5);
          v5 += 12;
        }
        while ( v5 < (unsigned int)v6 );
        m_pLimit = pLimit;
        v4 = v8;
      }
    }
    while ( v5 < (unsigned int)m_pLimit );
    m_pfnEnd = (void (__thiscall *)(char *))this->m_ItemProcessor.m_pfnEnd;
    if ( m_pfnEnd != nullptr )
      m_pfnEnd(a1: (char *)this->m_ItemProcessor.m_pObject + HIDWORD(this->m_ItemProcessor.m_pfnEnd));
  }
}

//------------------------------------------------------------------------------
// Address: 0x10110DB0
// Name: public: void CParallelProcessor<struct CShadowMgr::DispDecalWorkItem_t,class CMemberFuncJobItemProcessor<struct CShadowMgr::DispDecalWorkItem_t,class CShadowMgr,class CShadowMgr>,1>::Run(struct CShadowMgr::DispDecalWorkItem_t __near *,unsigned int,int,int,class IThreadPool __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CParallelProcessor<CShadowMgr::DispDecalWorkItem_t,CMemberFuncJobItemProcessor<CShadowMgr::DispDecalWorkItem_t,CShadowMgr,CShadowMgr>,1>::Run(
        CParallelProcessor<CShadowMgr::DispDecalWorkItem_t,CMemberFuncJobItemProcessor<CShadowMgr::DispDecalWorkItem_t,CShadowMgr,CShadowMgr>,1> *this,
        CShadowMgr::DispDecalWorkItem_t *pItems,
        unsigned int nItems,
        int nChunkSize,
        int nMaxParallel,
        IThreadPool *pThreadPool)
{
  unsigned int v6; // eax
  IThreadPool *v8; // ecx
  int v9; // ebx
  int v10; // eax
  void *v11; // esp
  int i; // esi
  CFunctor *v13; // eax
  CParallelProcessor<CShadowMgr::DispDecalWorkItem_t,CMemberFuncJobItemProcessor<CShadowMgr::DispDecalWorkItem_t,CShadowMgr,CShadowMgr>,1> *v14; // ecx
  _DWORD v15[3]; // [esp+0h] [ebp-10h]
  CParallelProcessor<CShadowMgr::DispDecalWorkItem_t,CMemberFuncJobItemProcessor<CShadowMgr::DispDecalWorkItem_t,CShadowMgr,CShadowMgr>,1> *v16; // [esp+Ch] [ebp-4h]

  v6 = nItems;
  v16 = this;
  if ( nItems != 0 )
  {
    this->m_nChunkSize = nChunkSize;
    v8 = pThreadPool;
    if ( pThreadPool == nullptr )
    {
      v8 = _g_pThreadPool;
      pThreadPool = _g_pThreadPool;
    }
    _InterlockedExchange((volatile __int32 *)&this->m_pItems, (__int32)pItems);
    v9 = v6 - 1;
    if ( (int)(v6 - 1) > nMaxParallel )
      v9 = nMaxParallel;
    this->m_pLimit = &pItems[v6];
    if ( v8 == nullptr )
      goto LABEL_18;
    v10 = v8->NumThreads(this: v8);
    if ( v9 > v10 )
      v9 = v10;
    if ( v9 > 0 )
    {
      v11 = alloca(4 * v9);
      for ( i = v9; i != 0; v15[i] = nItems )
      {
        --i;
        v13 = (CFunctor *)MemAlloc_Alloc(nSize: 0x18u);
        if ( v13 != nullptr )
        {
          v14 = v16;
          v13[1].m_nUserID = 1;
          v13->__vftable = (CFunctor_vtbl *)&CMemberFunctor0<CParallelProcessor<CShadowMgr::DispDecalWorkItem_t,CMemberFuncJobItemProcessor<CShadowMgr::DispDecalWorkItem_t,CShadowMgr,CShadowMgr>,1> *,void (__thiscall CParallelProcessor<CShadowMgr::DispDecalWorkItem_t,CMemberFuncJobItemProcessor<CShadowMgr::DispDecalWorkItem_t,CShadowMgr,CShadowMgr>,1>::*)(void),CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>::`vftable'{for `CFunctor'};
          v13[1].__vftable = (CFunctor_vtbl *)&CMemberFunctor0<CParallelProcessor<CShadowMgr::DispDecalWorkItem_t,CMemberFuncJobItemProcessor<CShadowMgr::DispDecalWorkItem_t,CShadowMgr,CShadowMgr>,1> *,void (__thiscall CParallelProcessor<CShadowMgr::DispDecalWorkItem_t,CMemberFuncJobItemProcessor<CShadowMgr::DispDecalWorkItem_t,CShadowMgr,CShadowMgr>,1>::*)(void),CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>::`vftable'{for `CRefCountServiceBase<1,CRefMT>'};
          v13[2].__vftable = (CFunctor_vtbl *)CParallelProcessor<CShadowMgr::DispDecalWorkItem_t,CMemberFuncJobItemProcessor<CShadowMgr::DispDecalWorkItem_t,CShadowMgr,CShadowMgr>,1>::DoExecute;
          v13[2].m_nUserID = (unsigned int)v14;
        }
        else
        {
          v13 = nullptr;
        }
        pThreadPool->AddFunctorInternal(this: pThreadPool, a2: v13, a3: (CJob **)&nItems, a4: nullptr, a5: 8u);
      }
      CParallelProcessor<CShadowMgr::DispDecalWorkItem_t,CMemberFuncJobItemProcessor<CShadowMgr::DispDecalWorkItem_t,CShadowMgr,CShadowMgr>,1>::DoExecute(this: v16);
      do
      {
        CJob::Abort(this: (CJob *)v15[i], bDiscard: true);
        (*(void (__thiscall **)(_DWORD))(*(_DWORD *)v15[i] + 4))(a1: v15[i]);
        ++i;
      }
      while ( i < v9 );
    }
    else
    {
LABEL_18:
      CParallelProcessor<CShadowMgr::DispDecalWorkItem_t,CMemberFuncJobItemProcessor<CShadowMgr::DispDecalWorkItem_t,CShadowMgr,CShadowMgr>,1>::DoExecute(this);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10124C50
// Name: private: void CParallelProcessor<class CGameClient __near *,class CFuncJobItemProcessor<class CGameClient __near *>,1>::DoExecute(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CParallelProcessor<CGameClient *,CFuncJobItemProcessor<CGameClient *>,1>::DoExecute(
        CParallelProcessor<CGameClient *,CFuncJobItemProcessor<CGameClient *>,1> *this)
{
  void (*m_pfnBegin)(void); // eax
  CGameClient **m_pLimit; // ecx
  unsigned int v4; // edx
  CGameClient **v5; // esi
  CGameClient **v6; // edi
  void (*m_pfnEnd)(void); // ebx
  unsigned int v8; // [esp+4h] [ebp-8h]
  CGameClient **pLimit; // [esp+8h] [ebp-4h]

  if ( this->m_pItems.m_value < this->m_pLimit )
  {
    m_pfnBegin = this->m_ItemProcessor.m_pfnBegin;
    if ( m_pfnBegin != nullptr )
      m_pfnBegin();
    m_pLimit = this->m_pLimit;
    v4 = 4 * this->m_nChunkSize;
    pLimit = m_pLimit;
    v8 = v4;
    do
    {
      v5 = (CGameClient **)_InterlockedExchangeAdd((volatile signed __int32 *)&this->m_pItems, v4);
      v6 = (CGameClient **)((char *)v5 + v4);
      if ( m_pLimit < (CGameClient **)((char *)v5 + v4) )
        v6 = m_pLimit;
      if ( v5 < v6 )
      {
        do
          this->m_ItemProcessor.m_pfnProcess(a1: v5++);
        while ( v5 < v6 );
        m_pLimit = pLimit;
        v4 = v8;
      }
    }
    while ( v5 < m_pLimit );
    m_pfnEnd = this->m_ItemProcessor.m_pfnEnd;
    if ( m_pfnEnd != nullptr )
      m_pfnEnd();
  }
}

//------------------------------------------------------------------------------
// Address: 0x10127930
// Name: public: void CParallelProcessor<class CGameClient __near *,class CFuncJobItemProcessor<class CGameClient __near *>,1>::Run(class CGameClient __near * __near *,unsigned int,int,int,class IThreadPool __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CParallelProcessor<CGameClient *,CFuncJobItemProcessor<CGameClient *>,1>::Run(
        CParallelProcessor<CGameClient *,CFuncJobItemProcessor<CGameClient *>,1> *this,
        CGameClient **pItems,
        unsigned int nItems,
        int nChunkSize,
        int nMaxParallel,
        IThreadPool *pThreadPool)
{
  unsigned int v6; // ebx
  IThreadPool *v8; // ecx
  CGameClient **v9; // eax
  int v10; // ebx
  int v11; // eax
  void *v12; // esp
  int i; // esi
  CFunctor *v14; // eax
  CParallelProcessor<CGameClient *,CFuncJobItemProcessor<CGameClient *>,1> *v15; // ecx
  _DWORD v16[3]; // [esp+0h] [ebp-10h]
  CParallelProcessor<CGameClient *,CFuncJobItemProcessor<CGameClient *>,1> *v17; // [esp+Ch] [ebp-4h]

  v6 = nItems;
  v17 = this;
  if ( nItems != 0 )
  {
    v8 = pThreadPool;
    this->m_nChunkSize = nChunkSize;
    if ( v8 == nullptr )
    {
      pThreadPool = _g_pThreadPool;
      v8 = _g_pThreadPool;
    }
    _InterlockedExchange((volatile __int32 *)&this->m_pItems, (__int32)pItems);
    v9 = &pItems[v6];
    v10 = v6 - 1;
    this->m_pLimit = v9;
    if ( v10 > nMaxParallel )
      v10 = nMaxParallel;
    if ( v8 == nullptr )
      goto LABEL_18;
    v11 = v8->NumThreads(this: v8);
    if ( v10 > v11 )
      v10 = v11;
    if ( v10 > 0 )
    {
      v12 = alloca(4 * v10);
      for ( i = v10; i != 0; v16[i] = nItems )
      {
        --i;
        v14 = (CFunctor *)MemAlloc_Alloc(nSize: 0x18u);
        if ( v14 != nullptr )
        {
          v15 = v17;
          v14[1].m_nUserID = 1;
          v14->__vftable = (CFunctor_vtbl *)&CMemberFunctor0<CParallelProcessor<CGameClient *,CFuncJobItemProcessor<CGameClient *>,1> *,void (__thiscall CParallelProcessor<CGameClient *,CFuncJobItemProcessor<CGameClient *>,1>::*)(void),CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>::`vftable'{for `CFunctor'};
          v14[1].__vftable = (CFunctor_vtbl *)&CMemberFunctor0<CParallelProcessor<CGameClient *,CFuncJobItemProcessor<CGameClient *>,1> *,void (__thiscall CParallelProcessor<CGameClient *,CFuncJobItemProcessor<CGameClient *>,1>::*)(void),CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>::`vftable'{for `CRefCountServiceBase<1,CRefMT>'};
          v14[2].__vftable = (CFunctor_vtbl *)CParallelProcessor<CGameClient *,CFuncJobItemProcessor<CGameClient *>,1>::DoExecute;
          v14[2].m_nUserID = (unsigned int)v15;
        }
        else
        {
          v14 = nullptr;
        }
        pThreadPool->AddFunctorInternal(this: pThreadPool, a2: v14, a3: (CJob **)&nItems, a4: nullptr, a5: 8u);
      }
      CParallelProcessor<CGameClient *,CFuncJobItemProcessor<CGameClient *>,1>::DoExecute(this: v17);
      do
      {
        CJob::Abort(this: (CJob *)v16[i], bDiscard: true);
        (*(void (__thiscall **)(_DWORD))(*(_DWORD *)v16[i] + 4))(a1: v16[i]);
        ++i;
      }
      while ( i < v10 );
    }
    else
    {
LABEL_18:
      CParallelProcessor<CGameClient *,CFuncJobItemProcessor<CGameClient *>,1>::DoExecute(this);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101286E0
// Name: void SV_EnsureInstanceBaseline(class ServerClass __near *,int,void const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SV_EnsureInstanceBaseline(ServerClass *pServerClass, int iEdict, const void *pData, int nBytes)
{
  edict_t *v4; // esi
  int v5; // esi
  DWORD CurrentThreadId; // eax
  INetworkStringTable *InstanceBaselineTable; // eax
  char idString[32]; // [esp+4h] [ebp-20h] BYREF

  v4 = &sv.edicts[iEdict];
  if ( v4->m_pNetworkable == nullptr )
    _Error(a1: "SV_EnsureInstanceBaseline: edict %d missing ent", iEdict);
  v5 = (int)v4->m_pNetworkable->GetServerClass(this: v4->m_pNetworkable);
  if ( *(_DWORD *)(v5 + 16) == 0xFFFF )
  {
    V_snprintf(pDest: idString, maxLen: 32, pFormat: "%d", *(_DWORD *)(v5 + 12));
    CurrentThreadId = GetCurrentThreadId();
    if ( CurrentThreadId != g_svInstanceBaselineMutex.m_ownerID
      && _InterlockedCompareExchange((volatile signed __int32 *)&g_svInstanceBaselineMutex, CurrentThreadId, 0) != 0 )
    {
      _mm_pause();
      CThreadFastMutex::Lock(a1: &g_svInstanceBaselineMutex, a2: CurrentThreadId, a3: 0);
    }
    else
    {
      ++g_svInstanceBaselineMutex.m_depth;
    }
    InstanceBaselineTable = CBaseServer::GetInstanceBaselineTable(this: &sv);
    *(_DWORD *)(v5 + 16) = InstanceBaselineTable->AddString(
                             this: InstanceBaselineTable,
                             a2: true,
                             a3: idString,
                             a4: nBytes,
                             a5: pData);
    if ( --g_svInstanceBaselineMutex.m_depth == 0 )
      _InterlockedExchange((volatile __int32 *)&g_svInstanceBaselineMutex, 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10128870
// Name: char const __near * GetObjectClassName(int)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl GetObjectClassName(int objectID)
{
  edict_t *v1; // eax

  if ( objectID < 0 || objectID >= sv.num_edicts )
    return "[unknown]";
  v1 = &sv.edicts[objectID];
  if ( v1->m_pUnk != nullptr )
    return v1->m_pNetworkable->GetClassNameA(this: v1->m_pNetworkable);
  else
    return defaultValue;
}

//------------------------------------------------------------------------------
// Address: 0x101288B0
// Name: private: void CParallelProcessor<struct PackWork_t,class CFuncJobItemProcessor<struct PackWork_t>,1>::DoExecute(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CParallelProcessor<PackWork_t,CFuncJobItemProcessor<PackWork_t>,1>::DoExecute(
        CParallelProcessor<PackWork_t,CFuncJobItemProcessor<PackWork_t>,1> *this)
{
  void (*m_pfnBegin)(void); // eax
  PackWork_t *m_pLimit; // edx
  unsigned int v4; // eax
  PackWork_t *v5; // esi
  PackWork_t *v6; // edi
  void (*m_pfnEnd)(void); // ebx
  unsigned int v8; // [esp+4h] [ebp-8h]
  PackWork_t *pLimit; // [esp+8h] [ebp-4h]

  if ( this->m_pItems.m_value < this->m_pLimit )
  {
    m_pfnBegin = this->m_ItemProcessor.m_pfnBegin;
    if ( m_pfnBegin != nullptr )
      m_pfnBegin();
    m_pLimit = this->m_pLimit;
    v4 = 12 * this->m_nChunkSize;
    pLimit = m_pLimit;
    v8 = v4;
    do
    {
      v5 = (PackWork_t *)_InterlockedExchangeAdd((volatile signed __int32 *)&this->m_pItems, v4);
      v6 = (PackWork_t *)((char *)v5 + v4);
      if ( m_pLimit < (PackWork_t *)((char *)v5 + v4) )
        v6 = m_pLimit;
      if ( v5 < v6 )
      {
        do
          this->m_ItemProcessor.m_pfnProcess(a1: v5++);
        while ( v5 < v6 );
        m_pLimit = pLimit;
        v4 = v8;
      }
    }
    while ( v5 < m_pLimit );
    m_pfnEnd = this->m_ItemProcessor.m_pfnEnd;
    if ( m_pfnEnd != nullptr )
      m_pfnEnd();
  }
}

//------------------------------------------------------------------------------
// Address: 0x10128980
// Name: public: void CUtlMemory<struct SVC_ClassInfo::class_s,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<SVC_ClassInfo::class_s,int>::Grow(CUtlMemory<SVC_ClassInfo::class_s,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  SVC_ClassInfo::class_s *m_pMemory; // edx
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
    v7 = 516 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (SVC_ClassInfo::class_s *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (SVC_ClassInfo::class_s *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10128AF0
// Name: void SV_MaybeWriteSendTable(class SendTable __near *,class bf_write __near &,bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SV_MaybeWriteSendTable(SendTable *pTable, bf_write *pBuf, bool bNeedDecoder)
{
  char v3; // al
  _BYTE pData[4096]; // [esp+4h] [ebp-1054h] BYREF
  SVC_SendTable v5; // [esp+1004h] [ebp-54h] BYREF

  v3 = *((_BYTE *)pTable + 16);
  if ( (v3 & 2) == 0 )
  {
    *((_BYTE *)pTable + 16) = v3 | 2;
    v5.m_bReliable = true;
    v5.m_NetChannel = nullptr;
    v5.__vftable = (SVC_SendTable_vtbl *)&SVC_SendTable::`vftable';
    v5.m_DataIn.m_bOverflow = false;
    v5.m_DataIn.m_pDebugName = nullptr;
    v5.m_DataIn.m_nDataBits = -1;
    v5.m_DataIn.m_nDataBytes = 0;
    bf_write::bf_write(this: &v5.m_DataOut);
    bf_write::StartWriting(this: &v5.m_DataOut, pData, nBytes: 4096, iStartBit: 0, nBits: -1);
    SendTable_WriteInfos(pTable, pBuf: &v5.m_DataOut);
    v5.m_bNeedsDecoder = bNeedDecoder;
    SVC_SendTable::WriteToBuffer(this: &v5, buffer: pBuf);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10128B80
// Name: void SV_MaybeWriteSendTable_R(class SendTable __near *,class bf_write __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SV_MaybeWriteSendTable_R(SendTable *pTable, bf_write *pBuf)
{
  int v2; // ebx
  int v3; // edi

  SV_MaybeWriteSendTable(pTable, pBuf, bNeedDecoder: false);
  v2 = 0;
  if ( pTable->m_nProps > 0 )
  {
    v3 = 0;
    do
    {
      if ( pTable->m_pProps[v3].m_Type == DPT_DataTable )
        SV_MaybeWriteSendTable_R(pTable: pTable->m_pProps[v3].m_pDataTable, pBuf);
      ++v2;
      ++v3;
    }
    while ( v2 < pTable->m_nProps );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10128BD0
// Name: void SV_WriteSendTables(class ServerClass __near *,class bf_write __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SV_WriteSendTables(ServerClass *pClasses, bf_write *pBuf)
{
  ServerClass *v2; // edi
  int v3; // ebx
  SendTable *m_pTable; // esi
  char v5; // al
  SendTable *v6; // esi
  int v7; // edi
  _BYTE pData[4096]; // [esp+Ch] [ebp-1054h] BYREF
  SVC_SendTable v9; // [esp+100Ch] [ebp-54h] BYREF
  ServerClass *pClassesa; // [esp+1068h] [ebp+8h]

  v2 = pClasses;
  DataTable_ClearWriteFlags(pClasses);
  v3 = 0;
  if ( pClasses != nullptr )
  {
    do
    {
      m_pTable = v2->m_pTable;
      v5 = *((_BYTE *)m_pTable + 16);
      if ( (v5 & 2) == 0 )
      {
        *((_BYTE *)m_pTable + 16) = v5 | 2;
        v9.m_bReliable = true;
        v9.m_NetChannel = nullptr;
        v9.__vftable = (SVC_SendTable_vtbl *)&SVC_SendTable::`vftable';
        v9.m_DataIn.m_bOverflow = false;
        v9.m_DataIn.m_pDebugName = nullptr;
        v9.m_DataIn.m_nDataBits = -1;
        v9.m_DataIn.m_nDataBytes = 0;
        bf_write::bf_write(this: &v9.m_DataOut);
        bf_write::StartWriting(this: &v9.m_DataOut, pData, nBytes: 4096, iStartBit: 0, nBits: -1);
        SendTable_WriteInfos(pTable: m_pTable, pBuf: &v9.m_DataOut);
        v9.m_bNeedsDecoder = true;
        SVC_SendTable::WriteToBuffer(this: &v9, buffer: pBuf);
      }
      v2 = v2->m_pNext;
    }
    while ( v2 != nullptr );
    v2 = pClasses;
  }
  for ( pClassesa = v2; pClassesa != nullptr; pClassesa = pClassesa->m_pNext )
  {
    v6 = pClassesa->m_pTable;
    SV_MaybeWriteSendTable(pTable: v6, pBuf, bNeedDecoder: false);
    v7 = 0;
    if ( v6->m_nProps > 0 )
    {
      do
      {
        if ( v6->m_pProps[v3].m_Type == DPT_DataTable )
          SV_MaybeWriteSendTable_R(pTable: v6->m_pProps[v3].m_pDataTable, pBuf);
        ++v7;
        ++v3;
      }
      while ( v7 < v6->m_nProps );
      v3 = 0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10128E50
// Name: DoesEdictChangeInfoContainPropIndex
// Source: json
//------------------------------------------------------------------------------
bool __usercall DoesEdictChangeInfoContainPropIndex@<al>(
        SendTable *pSendTable@<eax>,
        const CEdictChangeInfo *pCI@<ebx>,
        int nProp)
{
  CSendTablePrecalc *m_pPrecalc; // esi
  bool result; // al
  int v5; // edi
  unsigned __int16 v6; // ax
  int p_elem; // ecx
  int v8; // eax
  int m_nChangeOffsets; // eax
  bool v10; // sf
  bool v11; // of
  CUtlMap<unsigned short,PropIndicesCollection_t,unsigned short>::Node_t search; // [esp+8h] [ebp-Ch] BYREF
  bool bFound; // [esp+13h] [ebp-1h]

  m_pPrecalc = pSendTable->m_pPrecalc;
  result = false;
  v5 = 0;
  bFound = false;
  if ( pCI->m_nChangeOffsets != 0 )
  {
    do
    {
      if ( result )
        break;
      search.key = pCI->m_ChangeOffsets[v5];
      v6 = CUtlRBTree<CUtlMap<unsigned short,PropIndicesCollection_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,PropIndicesCollection_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,PropIndicesCollection_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
             this: &m_pPrecalc->m_PropOffsetToIndexMap.m_Tree,
             &search);
      if ( v6 != 0xFFFF )
      {
        p_elem = (int)&m_pPrecalc->m_PropOffsetToIndexMap.m_Tree.m_Elements.m_pMemory[v6].m_Data.elem;
        v8 = 0;
        while ( *(unsigned __int16 *)(p_elem + 2 * v8) != nProp )
        {
          if ( (unsigned int)++v8 >= 2 )
            goto LABEL_9;
        }
        bFound = true;
      }
LABEL_9:
      m_nChangeOffsets = pCI->m_nChangeOffsets;
      v11 = __OFSUB__(++v5, m_nChangeOffsets);
      v10 = v5 - m_nChangeOffsets < 0;
      result = bFound;
    }
    while ( v10 != v11 );
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10128EE0
// Name: ValidateEdictChangeInfos
// Source: json
//------------------------------------------------------------------------------
void __usercall ValidateEdictChangeInfos(
        SendTable *pTable@<esi>,
        const edict_t *pEdict,
        const int *pDeltaProps,
        int nDeltaProps)
{
  const CEdictChangeInfo *v4; // ebx
  int v5; // eax
  const SendProp *v6; // edi
  int nCurProp; // [esp+8h] [ebp-4h]

  v4 = &g_pSharedChangeInfo->m_ChangeInfos[CBaseEdict::GetChangeAccessor(this: &pEdict->CBaseEdict)->m_iChangeInfo];
  if ( CBaseEdict::GetChangeAccessor(this: &pEdict->CBaseEdict)->m_iChangeInfoSerialNumber != g_pSharedChangeInfo->m_iSerialNumber )
    v4 = nullptr;
  if ( (pEdict->m_fStateFlags & 0x100) == 0 )
  {
    for ( nCurProp = 0; nCurProp < nDeltaProps; ++nCurProp )
    {
      v5 = pDeltaProps[nCurProp];
      v6 = pTable->m_pPrecalc->m_Props.m_Memory.m_pMemory[v5];
      if ( v4 == nullptr || !DoesEdictChangeInfoContainPropIndex(pSendTable: pTable, pCI: v4, nProp: v5) )
        _Warning(
          a1: "edict %d (%s) missing prop '%s' in changeinfos\n",
          pEdict - sv.edicts,
          pTable->m_pNetTableName,
          v6->m_pVarName);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10128F90
// Name: SV_PackEntity
// Source: json
//------------------------------------------------------------------------------
void __usercall SV_PackEntity(int edictIdx@<ebx>, edict_t *edict, ServerClass *pServerClass, CFrameSnapshot *pSnapshot)
{
  bool v4; // zf
  int m_nSerialNumber; // ecx
  SendTable *m_pTable; // esi
  int m_nDataTableProxies; // eax
  PackedEntity *PreviouslySentPacket; // eax
  PackedEntity *v9; // edi
  int v10; // eax
  int v11; // ecx
  const SendProp *v12; // eax
  const char *m_pVarName; // edi
  const char *v14; // eax
  int m_pChangeFrameList; // eax
  IChangeFrameList *v16; // edi
  int v17; // eax
  int v18; // esi
  int v19; // eax
  PackedEntity *PackedEntity; // esi
  IServerUnknown *m_pUnk; // [esp-14h] [ebp-8150h]
  _BYTE pData[16384]; // [esp+8h] [ebp-8134h] BYREF
  int pDeltaProps[4096]; // [esp+4008h] [ebp-4134h] BYREF
  char v24; // [esp+8008h] [ebp-134h] BYREF
  bf_write pOut; // [esp+8108h] [ebp-34h] BYREF
  PackedEntity *v26; // [esp+8120h] [ebp-1Ch]
  int nProperties; // [esp+8124h] [ebp-18h]
  CUtlMemory<CSendProxyRecipients,int> pRecipients; // [esp+8128h] [ebp-14h] BYREF
  int v29; // [esp+8134h] [ebp-8h]
  int entSerialNumber; // [esp+8138h] [ebp-4h]

  v4 = (edict->m_fStateFlags & 1) == 0;
  m_nSerialNumber = pSnapshot->m_pEntities[edictIdx].m_nSerialNumber;
  entSerialNumber = m_nSerialNumber;
  if ( v4
    && CFrameSnapshotManager::UsePreviouslySentPacket(
         this: framesnapshotmanager,
         pSnapshot,
         entity: edictIdx,
         entSerialNumber: m_nSerialNumber)
    && (sv_debugmanualmode.m_pParent == nullptr || sv_debugmanualmode.m_pParent->m_Value.m_nValue == 0) )
  {
    edict->m_fStateFlags &= 0xFFFFFEFE;
    CBaseEdict::GetChangeAccessor(this: edict)->m_iChangeInfoSerialNumber = 0;
    return;
  }
  bf_write::bf_write(this: &pOut, pDebugName: "SV_PackEntity->writeBuf", pData, nBytes: 0x4000, nBits: -1);
  m_pTable = pServerClass->m_pTable;
  m_nDataTableProxies = m_pTable->m_pPrecalc->m_nDataTableProxies;
  pRecipients.m_pMemory = (CSendProxyRecipients *)&v24;
  pRecipients.m_nAllocationCount = m_nDataTableProxies;
  m_pUnk = edict->m_pUnk;
  pRecipients.m_nGrowSize = -1;
  if ( !SendTable_Encode(
          pTable: m_pTable,
          pStruct: m_pUnk,
          &pOut,
          objectID: edictIdx,
          &pRecipients,
          bNonZeroOnly: false) )
    Host_Error(error: "SV_PackEntity: SendTable_Encode returned false (ent %d).\n", edictIdx);
  SV_EnsureInstanceBaseline(pServerClass, iEdict: edictIdx, pData, nBytes: (pOut.m_iCurBit + 7) >> 3);
  nProperties = SendTable_GetNumFlatProps(pSendTable: m_pTable);
  PreviouslySentPacket = CFrameSnapshotManager::GetPreviouslySentPacket(
                           this: framesnapshotmanager,
                           iEntity: edictIdx,
                           iSerialNumber: pSnapshot->m_pEntities[edictIdx].m_nSerialNumber);
  v9 = PreviouslySentPacket;
  v26 = PreviouslySentPacket;
  if ( PreviouslySentPacket != nullptr )
  {
    v10 = SendTable_CalcDelta(
            pTable: m_pTable,
            pFromState: PreviouslySentPacket->m_pData,
            nFromBits: PreviouslySentPacket->m_nBits & 0x7FFFFFFF,
            pToState: pData,
            nToBits: pOut.m_iCurBit,
            pDeltaProps,
            nMaxDeltaProps: 4096,
            objectID: edictIdx);
    v29 = v10;
    if ( sv_validate_edict_change_infos.m_pParent != nullptr
      && sv_validate_edict_change_infos.m_pParent->m_Value.m_nValue != 0 )
    {
      ValidateEdictChangeInfos(pTable: m_pTable, pEdict: edict, pDeltaProps, nDeltaProps: v10);
      v10 = v29;
    }
    if ( v10 != 0 )
    {
      if ( (edict->m_fStateFlags & 1) == 0 )
      {
        v11 = 0;
        entSerialNumber = 0;
        if ( v10 > 0 )
        {
          do
          {
            v12 = m_pTable->m_pPrecalc->m_Props.m_Memory.m_pMemory[pDeltaProps[v11]];
            if ( (v12->m_Flags & 0x80000) == 0 )
            {
              m_pVarName = v12->m_pVarName;
              if ( edict->m_pUnk != nullptr )
                v14 = edict->m_pNetworkable->GetClassNameA(this: edict->m_pNetworkable);
              else
                v14 = defaultValue;
              _Msg(
                a1: "Entity %d (class '%s') reported ENTITY_CHANGE_NONE but '%s' changed.\n",
                edictIdx,
                v14,
                m_pVarName);
              v11 = entSerialNumber;
              v9 = v26;
            }
            entSerialNumber = ++v11;
          }
          while ( v11 < v29 );
        }
      }
    }
    else if ( PackedEntity::CompareRecipients(this: v9, recipients: &pRecipients)
           && CFrameSnapshotManager::UsePreviouslySentPacket(
                this: framesnapshotmanager,
                pSnapshot,
                entity: edictIdx,
                entSerialNumber) )
    {
      edict->m_fStateFlags &= 0xFFFFFEFE;
      CBaseEdict::GetChangeAccessor(this: edict)->m_iChangeInfoSerialNumber = 0;
      CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>::~CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>(this: (CUtlBuffer *)&pRecipients);
      return;
    }
    if ( hltv != nullptr && hltv->IsActive(this: &hltv->CBaseServer) )
    {
      m_pChangeFrameList = (int)v9->m_pChangeFrameList->Copy(this: v9->m_pChangeFrameList);
    }
    else
    {
      m_pChangeFrameList = (int)v9->m_pChangeFrameList;
      v9->m_pChangeFrameList = nullptr;
    }
    v16 = (IChangeFrameList *)m_pChangeFrameList;
    if ( m_pChangeFrameList == 0 )
      _Error(a1: "SV_PackEntity: SnagChangeFrameList returned null");
    v17 = v16->GetNumProps(this: v16);
    v18 = nProperties;
    if ( v17 != nProperties )
    {
      v19 = v16->GetNumProps(this: v16);
      _Error(a1: "SV_PackEntity: SnagChangeFrameList mismatched number of props[%d vs %d]", v18, v19);
    }
    v16->SetChangeTick(this: v16, a2: pDeltaProps, a3: v29, a4: pSnapshot->m_nTickCount);
  }
  else
  {
    v16 = AllocChangeFrameList(nProperties, iCurTick: pSnapshot->m_nTickCount);
  }
  PackedEntity = CFrameSnapshotManager::CreatePackedEntity(this: framesnapshotmanager, pSnapshot, entity: edictIdx);
  PackedEntity->m_pChangeFrameList = v16;
  PackedEntity::SetServerAndClientClass(this: PackedEntity, pServerClass, pClientClass: nullptr);
  PackedEntity::AllocAndCopyPadded(this: PackedEntity, pData, size: (pOut.m_iCurBit + 7) >> 3);
  PackedEntity::SetRecipients(this: PackedEntity, recipients: &pRecipients);
  edict->m_fStateFlags &= 0xFFFFFEFE;
  CBaseEdict::GetChangeAccessor(this: edict)->m_iChangeInfoSerialNumber = 0;
  if ( pRecipients.m_nGrowSize >= 0 && pRecipients.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: pRecipients.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x101292E0
// Name: public: static void PackWork_t::Process(struct PackWork_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl PackWork_t::Process(PackWork_t *item)
{
  SV_PackEntity(
    edictIdx: item->nIdx,
    edict: item->pEdict,
    pServerClass: item->pSnapshot->m_pEntities[item->nIdx].m_pClass,
    pSnapshot: item->pSnapshot);
}

//------------------------------------------------------------------------------
// Address: 0x10129310
// Name: void SV_WriteClassInfos(class ServerClass __near *,class bf_write __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SV_WriteClassInfos(ServerClass *pClasses, bf_write *pBuf)
{
  ServerClass *v2; // ebx
  int m_Size; // eax
  int v4; // esi
  SVC_ClassInfo::class_s *m_pMemory; // ecx
  int v6; // eax
  SVC_ClassInfo::class_s *v7; // eax
  SVC_ClassInfo::class_s *v8; // eax
  SVC_ClassInfo::class_s svclass; // [esp+8h] [ebp-230h] BYREF
  SVC_ClassInfo classinfomsg; // [esp+20Ch] [ebp-2Ch] BYREF

  v2 = pClasses;
  classinfomsg.m_bReliable = true;
  classinfomsg.m_NetChannel = nullptr;
  classinfomsg.__vftable = (SVC_ClassInfo_vtbl *)&SVC_ClassInfo::`vftable';
  memset(&classinfomsg.m_Classes, 0, sizeof(classinfomsg.m_Classes));
  classinfomsg.m_bCreateOnClient = false;
  if ( pClasses != nullptr )
  {
    do
    {
      svclass.classID = v2->m_ClassID;
      V_strncpy(pDest: svclass.datatablename, pSrc: v2->m_pTable->m_pNetTableName, maxLen: 256);
      V_strncpy(pDest: svclass.classname, pSrc: v2->m_pNetworkName, maxLen: 256);
      m_Size = classinfomsg.m_Classes.m_Size;
      v4 = classinfomsg.m_Classes.m_Size;
      if ( classinfomsg.m_Classes.m_Size + 1 > classinfomsg.m_Classes.m_Memory.m_nAllocationCount )
      {
        CUtlMemory<SVC_ClassInfo::class_s,int>::Grow(
          this: &classinfomsg.m_Classes.m_Memory,
          num: classinfomsg.m_Classes.m_Size - classinfomsg.m_Classes.m_Memory.m_nAllocationCount + 1);
        m_Size = classinfomsg.m_Classes.m_Size;
      }
      m_pMemory = classinfomsg.m_Classes.m_Memory.m_pMemory;
      classinfomsg.m_Classes.m_Size = m_Size + 1;
      v6 = m_Size - v4;
      classinfomsg.m_Classes.m_pElements = classinfomsg.m_Classes.m_Memory.m_pMemory;
      if ( v6 > 0 )
      {
        _V_memmove(
          dest: &classinfomsg.m_Classes.m_Memory.m_pMemory[v4 + 1],
          src: &classinfomsg.m_Classes.m_Memory.m_pMemory[v4],
          count: 516 * v6);
        m_pMemory = classinfomsg.m_Classes.m_Memory.m_pMemory;
      }
      v7 = &m_pMemory[v4];
      if ( v7 != nullptr )
        *v7 = svclass;
      v2 = v2->m_pNext;
    }
    while ( v2 != nullptr );
  }
  SVC_ClassInfo::WriteToBuffer(this: &classinfomsg, buffer: pBuf);
  v8 = classinfomsg.m_Classes.m_Memory.m_pMemory;
  classinfomsg.m_Classes.m_Size = 0;
  if ( classinfomsg.m_Classes.m_Memory.m_nGrowSize >= 0 )
  {
    if ( classinfomsg.m_Classes.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: classinfomsg.m_Classes.m_Memory.m_pMemory);
      v8 = nullptr;
      classinfomsg.m_Classes.m_Memory.m_pMemory = nullptr;
    }
    classinfomsg.m_Classes.m_Memory.m_nAllocationCount = 0;
  }
  classinfomsg.m_Classes.m_pElements = v8;
  if ( classinfomsg.m_Classes.m_Memory.m_nGrowSize >= 0 && v8 != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v8);
}

//------------------------------------------------------------------------------
// Address: 0x10129460
// Name: public: void CParallelProcessor<struct PackWork_t,class CFuncJobItemProcessor<struct PackWork_t>,1>::Run(struct PackWork_t __near *,unsigned int,int,int,class IThreadPool __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CParallelProcessor<PackWork_t,CFuncJobItemProcessor<PackWork_t>,1>::Run(
        CParallelProcessor<PackWork_t,CFuncJobItemProcessor<PackWork_t>,1> *this,
        PackWork_t *pItems,
        unsigned int nItems,
        int nChunkSize,
        int nMaxParallel,
        IThreadPool *pThreadPool)
{
  unsigned int v6; // eax
  IThreadPool *v8; // ecx
  int v9; // ebx
  int v10; // eax
  void *v11; // esp
  int i; // esi
  CFunctor *v13; // eax
  CParallelProcessor<PackWork_t,CFuncJobItemProcessor<PackWork_t>,1> *v14; // ecx
  _DWORD v15[3]; // [esp+0h] [ebp-10h]
  CParallelProcessor<PackWork_t,CFuncJobItemProcessor<PackWork_t>,1> *v16; // [esp+Ch] [ebp-4h]

  v6 = nItems;
  v16 = this;
  if ( nItems != 0 )
  {
    this->m_nChunkSize = nChunkSize;
    v8 = pThreadPool;
    if ( pThreadPool == nullptr )
    {
      v8 = _g_pThreadPool;
      pThreadPool = _g_pThreadPool;
    }
    _InterlockedExchange((volatile __int32 *)&this->m_pItems, (__int32)pItems);
    v9 = v6 - 1;
    if ( (int)(v6 - 1) > nMaxParallel )
      v9 = nMaxParallel;
    this->m_pLimit = &pItems[v6];
    if ( v8 == nullptr )
      goto LABEL_18;
    v10 = v8->NumThreads(this: v8);
    if ( v9 > v10 )
      v9 = v10;
    if ( v9 > 0 )
    {
      v11 = alloca(4 * v9);
      for ( i = v9; i != 0; v15[i] = nItems )
      {
        --i;
        v13 = (CFunctor *)MemAlloc_Alloc(nSize: 0x18u);
        if ( v13 != nullptr )
        {
          v14 = v16;
          v13[1].m_nUserID = 1;
          v13->__vftable = (CFunctor_vtbl *)&CMemberFunctor0<CParallelProcessor<PackWork_t,CFuncJobItemProcessor<PackWork_t>,1> *,void (__thiscall CParallelProcessor<PackWork_t,CFuncJobItemProcessor<PackWork_t>,1>::*)(void),CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>::`vftable'{for `CFunctor'};
          v13[1].__vftable = (CFunctor_vtbl *)&CMemberFunctor0<CParallelProcessor<PackWork_t,CFuncJobItemProcessor<PackWork_t>,1> *,void (__thiscall CParallelProcessor<PackWork_t,CFuncJobItemProcessor<PackWork_t>,1>::*)(void),CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>::`vftable'{for `CRefCountServiceBase<1,CRefMT>'};
          v13[2].__vftable = (CFunctor_vtbl *)CParallelProcessor<PackWork_t,CFuncJobItemProcessor<PackWork_t>,1>::DoExecute;
          v13[2].m_nUserID = (unsigned int)v14;
        }
        else
        {
          v13 = nullptr;
        }
        pThreadPool->AddFunctorInternal(this: pThreadPool, a2: v13, a3: (CJob **)&nItems, a4: nullptr, a5: 8u);
      }
      CParallelProcessor<PackWork_t,CFuncJobItemProcessor<PackWork_t>,1>::DoExecute(this: v16);
      do
      {
        CJob::Abort(this: (CJob *)v15[i], bDiscard: true);
        (*(void (__thiscall **)(_DWORD))(*(_DWORD *)v15[i] + 4))(a1: v15[i]);
        ++i;
      }
      while ( i < v9 );
    }
    else
    {
LABEL_18:
      CParallelProcessor<PackWork_t,CFuncJobItemProcessor<PackWork_t>,1>::DoExecute(this);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10129580
// Name: void PackEntities_Normal(int,class CGameClient __near * __near *,class CFrameSnapshot __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl PackEntities_Normal(int clientCount, CGameClient **clients, CFrameSnapshot *snapshot)
{
  CFrameSnapshot *v3; // eax
  signed int v4; // edi
  int v5; // ecx
  edict_t *v6; // edi
  CHLTVEntityData *m_pHLTVEntityData; // esi
  edict_t *v8; // ebx
  float *v9; // eax
  int v10; // ecx
  int v11; // edx
  int v12; // eax
  edict_t **v13; // eax
  CFrameSnapshot **p_pSnapshot; // esi
  PackWork_t pItems; // [esp+Ch] [ebp-6028h] BYREF
  CParallelProcessor<PackWork_t,CFuncJobItemProcessor<PackWork_t>,1> v16; // [esp+600Ch] [ebp-28h] BYREF
  int v17; // [esp+6024h] [ebp-10h]
  edict_t **p_pEdict; // [esp+6028h] [ebp-Ch]
  signed int v19; // [esp+602Ch] [ebp-8h]
  unsigned int v20; // [esp+6030h] [ebp-4h]

  v3 = snapshot;
  v4 = 0;
  v5 = 0;
  v19 = 0;
  v17 = 0;
  if ( snapshot->m_nValidEntities > 0 )
  {
    v20 = 0;
    p_pEdict = &pItems.pEdict;
    do
    {
      v6 = (edict_t *)v3->m_pValidEntities[v5];
      m_pHLTVEntityData = v3->m_pHLTVEntityData;
      v8 = &sv.edicts[(_DWORD)v6];
      if ( m_pHLTVEntityData != nullptr && v8 != nullptr )
      {
        v9 = (float *)v8->m_pNetworkable->GetPVSInfo(this: v8->m_pNetworkable);
        if ( *((_WORD *)v9 + 1) == 1 )
        {
          v10 = v20;
          m_pHLTVEntityData[v20 / 0x10].m_nNodeCluster = **((unsigned __int16 **)v9 + 1);
        }
        else
        {
          v11 = v20;
          m_pHLTVEntityData[v20 / 0x10].m_nNodeCluster = *(__int16 *)v9 | 0x80000000;
          v10 = v11;
        }
        *(float *)((char *)m_pHLTVEntityData->origin + v10) = v9[3];
        *(float *)((char *)&m_pHLTVEntityData->origin[1] + v10) = v9[4];
        *(float *)((char *)&m_pHLTVEntityData->origin[2] + v10) = v9[5];
      }
      v12 = 0;
      if ( clientCount > 0 )
      {
        while ( ((1 << ((unsigned __int8)v6 & 0x1F))
               & clients[v12]->m_pCurrentFrame->transmit_entity.m_Ints[(unsigned int)v6 >> 5]) == 0 )
        {
          if ( ++v12 >= clientCount )
            goto LABEL_14;
        }
        v13 = p_pEdict;
        ++v19;
        *(p_pEdict - 1) = v6;
        *v13 = v8;
        v13[1] = (edict_t *)snapshot;
        p_pEdict = v13 + 3;
      }
LABEL_14:
      v3 = snapshot;
      v20 += 16;
      v5 = v17 + 1;
      v17 = v5;
    }
    while ( v5 < snapshot->m_nValidEntities );
    v4 = v19;
  }
  if ( sv_parallel_packentities.m_pParent != nullptr && sv_parallel_packentities.m_pParent->m_Value.m_nValue != 0 )
  {
    v16.m_pItems.m_value = nullptr;
    v16.m_pLimit = nullptr;
    _InterlockedExchange((volatile __int32 *)&v16.m_pItems, 0);
    v16.m_ItemProcessor.m_pfnBegin = nullptr;
    v16.m_ItemProcessor.m_pfnEnd = nullptr;
    v16.m_ItemProcessor.m_pfnProcess = PackWork_t::Process;
    CParallelProcessor<PackWork_t,CFuncJobItemProcessor<PackWork_t>,1>::Run(
      this: &v16,
      &pItems,
      nItems: v4,
      nChunkSize: 1,
      nMaxParallel: 0x7FFFFFFF,
      pThreadPool: nullptr);
    InvalidateSharedEdictChangeInfos();
  }
  else
  {
    if ( v4 > 0 )
    {
      p_pSnapshot = &pItems.pSnapshot;
      do
      {
        SV_PackEntity(
          edictIdx: (int)*(p_pSnapshot - 2),
          edict: (edict_t *)*(p_pSnapshot - 1),
          pServerClass: (*p_pSnapshot)->m_pEntities[(_DWORD)*(p_pSnapshot - 2)].m_pClass,
          pSnapshot: *p_pSnapshot);
        p_pSnapshot += 3;
        --v4;
      }
      while ( v4 != 0 );
    }
    InvalidateSharedEdictChangeInfos();
  }
}

//------------------------------------------------------------------------------
// Address: 0x10129710
// Name: void SV_ComputeClientPacks(int,class CGameClient __near * __near *,class CFrameSnapshot __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SV_ComputeClientPacks(int clientCount, CGameClient **clients, CFrameSnapshot *snapshot)
{
  int i; // esi
  CGameClient *v4; // ecx
  CGameClient *v5; // eax
  int v6; // eax
  int m_nClientTick; // esi
  CClientState *BaseLocalClient; // eax
  CClientState *v9; // eax
  float flSaveLastServerTickTime; // [esp+Ch] [ebp-14h]
  int saveServerTicks; // [esp+10h] [ebp-10h]
  CCheckTransmitInfo *pInfo; // [esp+14h] [ebp-Ch]
  CCheckTransmitInfo *pInfoa; // [esp+14h] [ebp-Ch]
  CCheckTransmitInfo *pInfob; // [esp+14h] [ebp-Ch]
  float pInfoc; // [esp+14h] [ebp-Ch]
  IMDLCache *cacheCriticalSection; // [esp+18h] [ebp-8h]
  bool bSaveSimulation; // [esp+1Fh] [ebp-1h]

  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "SV_ComputeClientPacks",
    a3: 0,
    a4: "CheckTransmit",
    a5: false,
    a6: 2);
  cacheCriticalSection = g_pMDLCache;
  ((void (*)(void))g_pMDLCache->BeginLock)();
  for ( i = 0; i < clientCount; ++i )
  {
    v4 = clients[i];
    pInfo = &v4->m_PackInfo;
    CGameClient::SetupPackInfo(this: v4, pSnapshot: snapshot);
    v5 = clients[i];
    if ( v5->m_nDeltaTick < 0 )
      serverGameEnts->PrepareForFullUpdate(this: serverGameEnts, a2: v5->edict);
    serverGameEnts->CheckTransmit(
      this: serverGameEnts,
      a2: pInfo,
      a3: snapshot->m_pValidEntities,
      a4: snapshot->m_nValidEntities);
    CGameClient::SetupPrevPackInfo(this: clients[i]);
  }
  if ( g_pLocalNetworkBackdoor != nullptr )
  {
    if ( GetBaseLocalClient()->m_pServerClasses != nullptr )
    {
      v6 = (*clients)->GetMaxAckTickCount(this: &(*clients)->IClient);
      CNetworkStringTableContainer::DirectUpdate(this: sv.m_StringTables, tick_ack: v6);
      CLocalNetworkBackdoor::StartEntityStateUpdate(this: g_pLocalNetworkBackdoor);
      m_nClientTick = GetBaseLocalClient()->m_ClockDriftMgr.m_nClientTick;
      saveServerTicks = GetBaseLocalClient()->m_ClockDriftMgr.m_nServerTick;
      bSaveSimulation = GetBaseLocalClient()->insimulation;
      flSaveLastServerTickTime = GetBaseLocalClient()->m_flLastServerTickTime;
      GetBaseLocalClient()->insimulation = true;
      pInfoa = (CCheckTransmitInfo *)sv.m_nTickCount;
      GetBaseLocalClient()->m_ClockDriftMgr.m_nClientTick = (int)pInfoa;
      pInfob = (CCheckTransmitInfo *)sv.m_nTickCount;
      GetBaseLocalClient()->m_ClockDriftMgr.m_nServerTick = (int)pInfob;
      pInfoc = (float)sv.m_nTickCount * host_state.interval_per_tick;
      GetBaseLocalClient()->m_flLastServerTickTime = pInfoc;
      g_ClientGlobalVariables.tickcount = GetBaseLocalClient()->m_ClockDriftMgr.m_nClientTick;
      BaseLocalClient = GetBaseLocalClient();
      g_ClientGlobalVariables.curtime = CClientState::GetTime(this: BaseLocalClient);
      PackEntities_NetworkBackDoor(clientCount, clients, snapshot);
      CLocalNetworkBackdoor::EndEntityStateUpdate(this: g_pLocalNetworkBackdoor);
      GetBaseLocalClient()->m_ClockDriftMgr.m_nClientTick = m_nClientTick;
      GetBaseLocalClient()->m_ClockDriftMgr.m_nServerTick = saveServerTicks;
      GetBaseLocalClient()->insimulation = bSaveSimulation;
      GetBaseLocalClient()->m_flLastServerTickTime = flSaveLastServerTickTime;
      g_ClientGlobalVariables.tickcount = GetBaseLocalClient()->m_ClockDriftMgr.m_nClientTick;
      v9 = GetBaseLocalClient();
      g_ClientGlobalVariables.curtime = CClientState::GetTime(this: v9);
      PrintPartialChangeEntsList();
    }
    else
    {
      _Warning(
        a1: "Attempting to pack entities on server with invalid local client state. Probably a result of VXConsole or con com"
        "mands. Aborting SV_ComputeClientPacks.\n");
    }
  }
  else
  {
    PackEntities_Normal(clientCount, clients, snapshot);
  }
  cacheCriticalSection->EndLock(this: cacheCriticalSection);
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
}

//------------------------------------------------------------------------------
// Address: 0x102757D0
// Name: private: void CParallelProcessor<int,class CMemberFuncJobItemProcessor<int,class CCallQueueT<class CTSQueue<class CFunctor __near *,0,1>>,class CCallQueueT<class CTSQueue<class CFunctor __near *,0,1>>>,1>::DoExecute(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CParallelProcessor<int,CMemberFuncJobItemProcessor<int,CCallQueueT<CTSQueue<CFunctor *,0,1>>,CCallQueueT<CTSQueue<CFunctor *,0,1>>>,1>::DoExecute(
        CParallelProcessor<int,CMemberFuncJobItemProcessor<int,CCallQueueT<CTSQueue<CFunctor *,0,1> >,CCallQueueT<CTSQueue<CFunctor *,0,1> > >,1> *this)
{
  void (__thiscall *m_pfnBegin)(CCallQueueT<CTSQueue<CFunctor *,0,1> > *); // eax
  int *m_pLimit; // ecx
  unsigned int v4; // edx
  int *v5; // esi
  int *v6; // ebx
  void (__thiscall *m_pfnEnd)(CCallQueueT<CTSQueue<CFunctor *,0,1> > *); // eax
  unsigned int v8; // [esp+4h] [ebp-8h]
  int *pLimit; // [esp+8h] [ebp-4h]

  if ( this->m_pItems.m_value < this->m_pLimit )
  {
    m_pfnBegin = this->m_ItemProcessor.m_pfnBegin;
    if ( m_pfnBegin != nullptr )
      m_pfnBegin(this: this->m_ItemProcessor.m_pObject);
    m_pLimit = this->m_pLimit;
    v4 = 4 * this->m_nChunkSize;
    pLimit = m_pLimit;
    v8 = v4;
    do
    {
      v5 = (int *)_InterlockedExchangeAdd((volatile signed __int32 *)&this->m_pItems, v4);
      v6 = (int *)((char *)v5 + v4);
      if ( m_pLimit < (int *)((char *)v5 + v4) )
        v6 = m_pLimit;
      if ( v5 < v6 )
      {
        do
          this->m_ItemProcessor.m_pfnProcess(this: this->m_ItemProcessor.m_pObject, a2: v5++);
        while ( v5 < v6 );
        m_pLimit = pLimit;
        v4 = v8;
      }
    }
    while ( v5 < m_pLimit );
    m_pfnEnd = this->m_ItemProcessor.m_pfnEnd;
    if ( m_pfnEnd != nullptr )
      m_pfnEnd(this: this->m_ItemProcessor.m_pObject);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10275910
// Name: public: void CParallelProcessor<int,class CMemberFuncJobItemProcessor<int,class CCallQueueT<class CTSQueue<class CFunctor __near *,0,1>>,class CCallQueueT<class CTSQueue<class CFunctor __near *,0,1>>>,1>::Run(int __near *,unsigned int,int,int,class IThreadPool __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CParallelProcessor<int,CMemberFuncJobItemProcessor<int,CCallQueueT<CTSQueue<CFunctor *,0,1>>,CCallQueueT<CTSQueue<CFunctor *,0,1>>>,1>::Run(
        CParallelProcessor<int,CMemberFuncJobItemProcessor<int,CCallQueueT<CTSQueue<CFunctor *,0,1> >,CCallQueueT<CTSQueue<CFunctor *,0,1> > >,1> *this,
        int *pItems,
        unsigned int nItems,
        int nChunkSize,
        int nMaxParallel,
        IThreadPool *pThreadPool)
{
  unsigned int v6; // ebx
  IThreadPool *v8; // ecx
  int *v9; // eax
  int v10; // ebx
  int v11; // eax
  void *v12; // esp
  int i; // esi
  CFunctor *v14; // eax
  CParallelProcessor<int,CMemberFuncJobItemProcessor<int,CCallQueueT<CTSQueue<CFunctor *,0,1> >,CCallQueueT<CTSQueue<CFunctor *,0,1> > >,1> *v15; // ecx
  _DWORD v16[3]; // [esp+0h] [ebp-10h]
  CParallelProcessor<int,CMemberFuncJobItemProcessor<int,CCallQueueT<CTSQueue<CFunctor *,0,1> >,CCallQueueT<CTSQueue<CFunctor *,0,1> > >,1> *v17; // [esp+Ch] [ebp-4h]

  v6 = nItems;
  v17 = this;
  if ( nItems != 0 )
  {
    v8 = pThreadPool;
    this->m_nChunkSize = nChunkSize;
    if ( v8 == nullptr )
    {
      pThreadPool = _g_pThreadPool;
      v8 = _g_pThreadPool;
    }
    _InterlockedExchange((volatile __int32 *)&this->m_pItems, (__int32)pItems);
    v9 = &pItems[v6];
    v10 = v6 - 1;
    this->m_pLimit = v9;
    if ( v10 > nMaxParallel )
      v10 = nMaxParallel;
    if ( v8 == nullptr )
      goto LABEL_18;
    v11 = v8->NumThreads(this: v8);
    if ( v10 > v11 )
      v10 = v11;
    if ( v10 > 0 )
    {
      v12 = alloca(4 * v10);
      for ( i = v10; i != 0; v16[i] = nItems )
      {
        --i;
        v14 = (CFunctor *)MemAlloc_Alloc(nSize: 0x18u);
        if ( v14 != nullptr )
        {
          v15 = v17;
          v14[1].m_nUserID = 1;
          v14->__vftable = (CFunctor_vtbl *)&CMemberFunctor0<CParallelProcessor<int,CMemberFuncJobItemProcessor<int,CCallQueueT<CTSQueue<CFunctor *,0,1>>,CCallQueueT<CTSQueue<CFunctor *,0,1>>>,1> *,void (__thiscall CParallelProcessor<int,CMemberFuncJobItemProcessor<int,CCallQueueT<CTSQueue<CFunctor *,0,1>>,CCallQueueT<CTSQueue<CFunctor *,0,1>>>,1>::*)(void),CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>::`vftable'{for `CFunctor'};
          v14[1].__vftable = (CFunctor_vtbl *)&CMemberFunctor0<CParallelProcessor<int,CMemberFuncJobItemProcessor<int,CCallQueueT<CTSQueue<CFunctor *,0,1>>,CCallQueueT<CTSQueue<CFunctor *,0,1>>>,1> *,void (__thiscall CParallelProcessor<int,CMemberFuncJobItemProcessor<int,CCallQueueT<CTSQueue<CFunctor *,0,1>>,CCallQueueT<CTSQueue<CFunctor *,0,1>>>,1>::*)(void),CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>::`vftable'{for `CRefCountServiceBase<1,CRefMT>'};
          v14[2].__vftable = (CFunctor_vtbl *)CParallelProcessor<int,CMemberFuncJobItemProcessor<int,CCallQueueT<CTSQueue<CFunctor *,0,1>>,CCallQueueT<CTSQueue<CFunctor *,0,1>>>,1>::DoExecute;
          v14[2].m_nUserID = (unsigned int)v15;
        }
        else
        {
          v14 = nullptr;
        }
        pThreadPool->AddFunctorInternal(this: pThreadPool, a2: v14, a3: (CJob **)&nItems, a4: nullptr, a5: 8u);
      }
      CParallelProcessor<int,CMemberFuncJobItemProcessor<int,CCallQueueT<CTSQueue<CFunctor *,0,1>>,CCallQueueT<CTSQueue<CFunctor *,0,1>>>,1>::DoExecute(this: v17);
      do
      {
        CJob::Abort(this: (CJob *)v16[i], bDiscard: true);
        (*(void (__thiscall **)(_DWORD))(*(_DWORD *)v16[i] + 4))(a1: v16[i]);
        ++i;
      }
      while ( i < v10 );
    }
    else
    {
LABEL_18:
      CParallelProcessor<int,CMemberFuncJobItemProcessor<int,CCallQueueT<CTSQueue<CFunctor *,0,1>>,CCallQueueT<CTSQueue<CFunctor *,0,1>>>,1>::DoExecute(this);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10128920
// Name: protected: struct UtlRBTreeLinks_t<unsigned short> const __near & CUtlRBTree<struct CUtlMap<unsigned short,struct PropIndicesCollection_t,unsigned short>::Node_t,unsigned short,class CUtlMap<unsigned short,struct PropIndicesCollection_t,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<unsigned short,struct PropIndicesCollection_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links(unsigned short)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
UtlRBTreeNode_t<CUtlMap<unsigned short,PropIndicesCollection_t,unsigned short>::Node_t,unsigned short> *__thiscall CUtlRBTree<CUtlMap<unsigned short,PropIndicesCollection_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,PropIndicesCollection_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,PropIndicesCollection_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links(
        CUtlRBTree<CUtlMap<unsigned short,PropIndicesCollection_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,PropIndicesCollection_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,PropIndicesCollection_t,unsigned short>::Node_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 i)
{
  if ( (`CUtlRBTree<CUtlMap<unsigned short,PropIndicesCollection_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,PropIndicesCollection_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,PropIndicesCollection_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<unsigned short,PropIndicesCollection_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,PropIndicesCollection_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,PropIndicesCollection_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlMap<unsigned short,PropIndicesCollection_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,PropIndicesCollection_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,PropIndicesCollection_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
    `CUtlRBTree<CUtlMap<unsigned short,PropIndicesCollection_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,PropIndicesCollection_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,PropIndicesCollection_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
    *(_DWORD *)&`CUtlRBTree<CUtlMap<unsigned short,PropIndicesCollection_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,PropIndicesCollection_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,PropIndicesCollection_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = 0x1FFFF;
  }
  if ( i == 0xFFFF )
    return (UtlRBTreeNode_t<CUtlMap<unsigned short,PropIndicesCollection_t,unsigned short>::Node_t,unsigned short> *)&`CUtlRBTree<CUtlMap<unsigned short,PropIndicesCollection_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,PropIndicesCollection_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,PropIndicesCollection_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
  else
    return &this->m_Elements.m_pMemory[i];
}

//------------------------------------------------------------------------------
// Address: 0x10129970
// Name: __CreateCServerPluginIServerPluginHelpers_interface
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CServerPlugin *__cdecl _CreateCServerPluginIServerPluginHelpers_interface()
{
  return &s_ServerPlugin;
}

} // namespace engine_xlsp
