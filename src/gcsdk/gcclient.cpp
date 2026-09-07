// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: gcsdk/gcclient.cpp
// Functions: 22
// ============================================================

#include "gcsdk\gcclient.h"

//------------------------------------------------------------------------------
// Address: 0x10006F60
// Name: public: virtual bool GCSDK::CGCClientJob::BYieldingRunGCJob(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall GCSDK::CGCClientJob::BYieldingRunGCJob(ConVar *this)
{
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x10006F80
// Name: private: virtual bool GCSDK::CGCClientJob::BYieldingRunJobFromMsg(class GCSDK::CNetPacket __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall GCSDK::CGCClientJob::BYieldingRunJobFromMsg(GCSDK::CGCClientJob *this, GCSDK::CNetPacket *pNetPacket)
{
  if ( this->m_pGCClient != nullptr )
    return this->BYieldingRunGCJob_2(this, a2: pNetPacket);
  GCSDK::CJob::BYieldingWaitOneFrame(this);
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x10006FA0
// Name: private: virtual bool GCSDK::CGCClientJob::BYieldingRunJob(void __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall GCSDK::CGCClientJob::BYieldingRunJob(GCSDK::CGCClientJob *this, void *pvStartParam)
{
  if ( this->m_pGCClient != nullptr )
    return this->BYieldingRunGCJob(this);
  GCSDK::CJob::BYieldingWaitOneFrame(this);
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x10006FC0
// Name: public: bool GCSDK::CGCClient::BSendMessage(class GCSDK::CMsgBase_t<struct GCSDK::GCMsgHdrEx_t> const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall GCSDK::CGCClient::BSendMessage(
        GCSDK::CGCClient *this,
        const GCSDK::CMsgBase_t<GCSDK::GCMsgHdrEx_t> *msg)
{
  ISteamGameCoordinator *m_pSteamGameCoordinator; // ecx

  m_pSteamGameCoordinator = this->m_pSteamGameCoordinator;
  return m_pSteamGameCoordinator != nullptr
      && m_pSteamGameCoordinator->SendMessage(
           this: m_pSteamGameCoordinator,
           a2: *(_DWORD *)msg->m_pubPkt,
           a3: msg->m_pubPkt + 12,
           a4: msg->m_cubPkt - 12) == 0;
}

//------------------------------------------------------------------------------
// Address: 0x10007000
// Name: public: void GCSDK::CGCClient::Uninit(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GCSDK::CGCClient::Uninit(GCSDK::CGCClient *this)
{
  _SteamAPI_UnregisterCallback(a1: &this->m_callbackGCMessageAvailable);
  this->m_pSteamGameCoordinator = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10007200
// Name: public: bool GCSDK::CGCClient::BMainLoop(unsigned __int64)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall GCSDK::CGCClient::BMainLoop(GCSDK::CGCClient *this, unsigned __int64 ulLimitMicroseconds)
{
  bool v4; // al
  CLimitTimer limitTimer; // [esp+4h] [ebp-10h] BYREF
  unsigned __int64 v6; // [esp+Ch] [ebp-8h]

  if ( this->m_pSteamGameCoordinator == nullptr )
    return false;
  v6 = __rdtsc();
  limitTimer.m_lCycleLimit = _g_dwClockSpeed * ulLimitMicroseconds / 0xF4240 + v6;
  GCSDK::CJobTime::UpdateJobTime(cMicroSecPerShellFrame: 50000);
  v4 = GCSDK::CJobMgr::BFrameFuncRunSleepingJobs(this: &this->m_JobMgr, &limitTimer);
  return v4 | GCSDK::CJobMgr::BFrameFuncRunYieldingJobs(this: &this->m_JobMgr, &limitTimer);
}

//------------------------------------------------------------------------------
// Address: 0x100072A0
// Name: class GCSDK::CJob __near * GCSDK::CreateJob_CGCSOCreateJob(class GCSDK::CGCClient __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
GCSDK::CJob *__cdecl GCSDK::CreateJob_CGCSOCreateJob(GCSDK::CJob_vtbl *pParent, void *pvStartParam)
{
  GCSDK::CJob *v2; // esi
  GCSDK::CJob *result; // eax

  v2 = (GCSDK::CJob *)operator new(nSize: 0x90u);
  if ( v2 != nullptr )
  {
    GCSDK::CJob::CJob(this: v2, jobMgr: (GCSDK::CJobMgr *)&pParent[1]);
    v2[1].__vftable = pParent;
    *(_DWORD *)v2[1].gap4 = 2;
    v2->__vftable = (GCSDK::CJob_vtbl *)&GCSDK::CGCSOCreateJob::`vftable';
    result = v2;
  }
  else
  {
    result = nullptr;
  }
  result->m_pJobType = &g_JobType_CGCSOCreateJob;
  if ( pvStartParam != nullptr )
    result->m_pvStartParam = pvStartParam;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10007300
// Name: class GCSDK::CJob __near * GCSDK::CreateJob_CGCSODestroyJob(class GCSDK::CGCClient __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
GCSDK::CJob *__cdecl GCSDK::CreateJob_CGCSODestroyJob(GCSDK::CJob_vtbl *pParent, void *pvStartParam)
{
  GCSDK::CJob *v2; // esi
  GCSDK::CJob *result; // eax

  v2 = (GCSDK::CJob *)operator new(nSize: 0x90u);
  if ( v2 != nullptr )
  {
    GCSDK::CJob::CJob(this: v2, jobMgr: (GCSDK::CJobMgr *)&pParent[1]);
    v2[1].__vftable = pParent;
    *(_DWORD *)v2[1].gap4 = 2;
    v2->__vftable = (GCSDK::CJob_vtbl *)&GCSDK::CGCSODestroyJob::`vftable';
    result = v2;
  }
  else
  {
    result = nullptr;
  }
  result->m_pJobType = &g_JobType_CGCSODestroyJob;
  if ( pvStartParam != nullptr )
    result->m_pvStartParam = pvStartParam;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10007360
// Name: class GCSDK::CJob __near * GCSDK::CreateJob_CGCSOUpdateJob(class GCSDK::CGCClient __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
GCSDK::CJob *__cdecl GCSDK::CreateJob_CGCSOUpdateJob(GCSDK::CJob_vtbl *pParent, void *pvStartParam)
{
  GCSDK::CJob *v2; // esi
  GCSDK::CJob *result; // eax

  v2 = (GCSDK::CJob *)operator new(nSize: 0x90u);
  if ( v2 != nullptr )
  {
    GCSDK::CJob::CJob(this: v2, jobMgr: (GCSDK::CJobMgr *)&pParent[1]);
    v2[1].__vftable = pParent;
    *(_DWORD *)v2[1].gap4 = 2;
    v2->__vftable = (GCSDK::CJob_vtbl *)&GCSDK::CGCSOUpdateJob::`vftable';
    result = v2;
  }
  else
  {
    result = nullptr;
  }
  result->m_pJobType = &g_JobType_CGCSOUpdateJob;
  if ( pvStartParam != nullptr )
    result->m_pvStartParam = pvStartParam;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100073C0
// Name: class GCSDK::CJob __near * GCSDK::CreateJob_CGCSOCacheSubscribedJob(class GCSDK::CGCClient __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
GCSDK::CJob *__cdecl GCSDK::CreateJob_CGCSOCacheSubscribedJob(GCSDK::CJob_vtbl *pParent, void *pvStartParam)
{
  GCSDK::CJob *v2; // esi
  GCSDK::CJob *result; // eax

  v2 = (GCSDK::CJob *)operator new(nSize: 0x90u);
  if ( v2 != nullptr )
  {
    GCSDK::CJob::CJob(this: v2, jobMgr: (GCSDK::CJobMgr *)&pParent[1]);
    v2[1].__vftable = pParent;
    *(_DWORD *)v2[1].gap4 = 2;
    v2->__vftable = (GCSDK::CJob_vtbl *)&GCSDK::CGCSOCacheSubscribedJob::`vftable';
    result = v2;
  }
  else
  {
    result = nullptr;
  }
  result->m_pJobType = &g_JobType_CGCSOCacheSubscribedJob;
  if ( pvStartParam != nullptr )
    result->m_pvStartParam = pvStartParam;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10007420
// Name: class GCSDK::CJob __near * GCSDK::CreateJob_CGCSOCacheUnsubscribedJob(class GCSDK::CGCClient __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
GCSDK::CJob *__cdecl GCSDK::CreateJob_CGCSOCacheUnsubscribedJob(GCSDK::CJob_vtbl *pParent, void *pvStartParam)
{
  GCSDK::CJob *v2; // esi
  GCSDK::CJob *result; // eax

  v2 = (GCSDK::CJob *)operator new(nSize: 0x90u);
  if ( v2 != nullptr )
  {
    GCSDK::CJob::CJob(this: v2, jobMgr: (GCSDK::CJobMgr *)&pParent[1]);
    v2[1].__vftable = pParent;
    *(_DWORD *)v2[1].gap4 = 2;
    v2->__vftable = (GCSDK::CJob_vtbl *)&GCSDK::CGCSOCacheUnsubscribedJob::`vftable';
    result = v2;
  }
  else
  {
    result = nullptr;
  }
  result->m_pJobType = &g_JobType_CGCSOCacheUnsubscribedJob;
  if ( pvStartParam != nullptr )
    result->m_pvStartParam = pvStartParam;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100078E0
// Name: public: void GCSDK::CGCClient::OnGCMessageAvailable(struct GCMessageAvailable_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GCSDK::CGCClient::OnGCMessageAvailable(GCSDK::CGCClient *this, GCMessageAvailable_t *pCallback)
{
  ISteamGameCoordinator *m_pSteamGameCoordinator; // ecx
  unsigned int v4; // eax
  unsigned __int8 *m_pMemory; // edx
  unsigned __int8 *v6; // eax
  unsigned __int8 *v7; // esi
  GCSDK::CNetPacket *v8; // eax
  GCSDK::CNetPacket *v9; // ebx
  int v10; // eax
  unsigned int v11; // edx
  GCSDK::JobMsgInfo_t jobMsgInfo; // [esp+4h] [ebp-2Ch] BYREF
  unsigned int unFullSize; // [esp+24h] [ebp-Ch]
  unsigned int unMsgType; // [esp+28h] [ebp-8h] BYREF
  unsigned int cubData; // [esp+2Ch] [ebp-4h] BYREF

  m_pSteamGameCoordinator = this->m_pSteamGameCoordinator;
  if ( m_pSteamGameCoordinator != nullptr )
  {
    do
    {
      if ( !m_pSteamGameCoordinator->IsMessageAvailable(this: m_pSteamGameCoordinator, a2: &cubData) )
        break;
      v4 = cubData + 12;
      unFullSize = cubData + 12;
      if ( this->m_memMsg.m_nAllocationCount < (signed int)(cubData + 12) && this->m_memMsg.m_nGrowSize >= 0 )
      {
        m_pMemory = this->m_memMsg.m_pMemory;
        this->m_memMsg.m_nAllocationCount = v4;
        if ( m_pMemory != nullptr )
          v6 = (unsigned __int8 *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v4);
        else
          v6 = (unsigned __int8 *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v4);
        this->m_memMsg.m_pMemory = v6;
      }
      v7 = this->m_memMsg.m_pMemory;
      if ( this->m_pSteamGameCoordinator->RetrieveMessage(
             this: this->m_pSteamGameCoordinator,
             a2: &unMsgType,
             a3: v7 + 12,
             a4: this->m_memMsg.m_nAllocationCount - 12,
             a5: &cubData) == k_EGCResultOK )
      {
        *(_DWORD *)v7 = unMsgType;
        *((_DWORD *)v7 + 2) = 0;
        *((_DWORD *)v7 + 1) = 0;
        ++GCSDK::g_cNetPacket;
        v8 = (GCSDK::CNetPacket *)CUtlMemoryPool::Alloc(this: &GCSDK::CNetPacketPool::sm_MemPoolNetPacket);
        v9 = v8;
        if ( v8 != nullptr )
          GCSDK::CNetPacket::CNetPacket(this: v8);
        GCSDK::CNetPacket::Init(this: v9, pubData: v7, cubData: unFullSize, pubNetworkBuffer: nullptr);
        v10 = *(_DWORD *)(v7 + 22);
        HIDWORD(jobMsgInfo.m_JobIDSource) = *(_DWORD *)(v7 + 26);
        jobMsgInfo.m_eMsg = unMsgType;
        v11 = *(_DWORD *)(v7 + 14);
        LODWORD(jobMsgInfo.m_JobIDSource) = v10;
        jobMsgInfo.m_JobIDTarget = __PAIR64__(*(_DWORD *)(v7 + 18), v11);
        jobMsgInfo.m_eServerType = k_EServerTypeGCClient;
        GCSDK::CJobMgr::BRouteMsgToJob(this: &this->m_JobMgr, pParent: this, pNetPacket: v9, &jobMsgInfo);
        GCSDK::CMessageList::TallySendmessage(this: &GCSDK::g_theMessageList, eMsgType: unMsgType, unMsgSize: cubData);
        GCSDK::CNetPacket::Release(this: v9);
      }
      m_pSteamGameCoordinator = this->m_pSteamGameCoordinator;
    }
    while ( this->m_pSteamGameCoordinator != nullptr );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10007A10
// Name: public: bool GCSDK::CGCClient::BInit(class ISteamGameCoordinator __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall GCSDK::CGCClient::BInit(GCSDK::CGCClient *this, ISteamGameCoordinator *pSteamGameCoordinator)
{
  GCSDK *v4; // [esp+0h] [ebp-8h]

  GCSDK::InitGCSystemMessageTypes(this: v4);
  this->m_pSteamGameCoordinator = pSteamGameCoordinator;
  if ( GCSDK::CGCClient::OnGCMessageAvailable != nullptr )
  {
    if ( (this->m_callbackGCMessageAvailable.m_nCallbackFlags & 1) != 0 )
      _SteamAPI_UnregisterCallback(a1: &this->m_callbackGCMessageAvailable);
    this->m_callbackGCMessageAvailable.m_pObj = this;
    this->m_callbackGCMessageAvailable.m_Func = GCSDK::CGCClient::OnGCMessageAvailable;
    _SteamAPI_RegisterCallback(a1: &this->m_callbackGCMessageAvailable, a2: 1701);
  }
  if ( this->m_pSteamGameCoordinator != nullptr )
    GCSDK::CGCClient::OnGCMessageAvailable(this, pCallback: nullptr);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10008DE0
// Name: public: GCSDK::CGCClient::~CGCClient(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GCSDK::CGCClient::~CGCClient(GCSDK::CGCClient *this)
{
  int v2; // esi
  int *v3; // edx
  GCSDK::CSharedObjectCache *elem; // ecx
  bool v5; // zf

  _SteamAPI_UnregisterCallback(a1: &this->m_callbackGCMessageAvailable);
  v2 = 0;
  this->m_pSteamGameCoordinator = nullptr;
  if ( LOWORD(this->m_mapSOCache.m_Tree.m_Elements.m_nAllocationCount) != 0 )
  {
    do
    {
      if ( (unsigned __int16)v2 < this->m_mapSOCache.m_Tree.m_Elements.m_nAllocationCount
        && (unsigned __int16)v2 <= this->m_mapSOCache.m_Tree.m_LastAlloc.index )
      {
        if ( (`CUtlRBTree<CUtlMap<CSteamID,GCSDK::CSharedObjectCache *,unsigned short>::Node_t,unsigned short,CUtlMap<CSteamID,GCSDK::CSharedObjectCache *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CSteamID,GCSDK::CSharedObjectCache *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
            & 1) == 0 )
        {
          `CUtlRBTree<CUtlMap<CSteamID,GCSDK::CSharedObjectCache *,unsigned short>::Node_t,unsigned short,CUtlMap<CSteamID,GCSDK::CSharedObjectCache *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CSteamID,GCSDK::CSharedObjectCache *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
          `CUtlRBTree<CUtlMap<CSteamID,GCSDK::CSharedObjectCache *,unsigned short>::Node_t,unsigned short,CUtlMap<CSteamID,GCSDK::CSharedObjectCache *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CSteamID,GCSDK::CSharedObjectCache *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
          dword_10082280 = 0x1FFFF;
        }
        if ( (_WORD)v2 == 0xFFFF )
          v3 = &`CUtlRBTree<CUtlMap<CSteamID,GCSDK::CSharedObjectCache *,unsigned short>::Node_t,unsigned short,CUtlMap<CSteamID,GCSDK::CSharedObjectCache *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CSteamID,GCSDK::CSharedObjectCache *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        else
          v3 = (int *)&this->m_mapSOCache.m_Tree.m_Elements.m_pMemory[(unsigned __int16)v2];
        if ( *(_WORD *)v3 != (_WORD)v2 )
        {
          elem = this->m_mapSOCache.m_Tree.m_Elements.m_pMemory[(unsigned __int16)v2].m_Data.elem;
          if ( elem != nullptr )
            ((void (__thiscall *)(GCSDK::CSharedObjectCache *, int))elem->dtr_CSharedObjectCache)(a1: elem, a2: 1);
        }
      }
      ++v2;
    }
    while ( v2 < LOWORD(this->m_mapSOCache.m_Tree.m_Elements.m_nAllocationCount) );
  }
  CUtlRBTree<CUtlMap<CSteamID,GCSDK::CSharedObjectCache *,unsigned short>::Node_t,unsigned short,CUtlMap<CSteamID,GCSDK::CSharedObjectCache *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CSteamID,GCSDK::CSharedObjectCache *,unsigned short>::Node_t,unsigned short>,unsigned short>>::RemoveAll(this: &this->m_mapSOCache.m_Tree);
  v5 = (this->m_callbackGCMessageAvailable.m_nCallbackFlags & 1) == 0;
  this->m_callbackGCMessageAvailable.__vftable = (CCallback<GCSDK::CGCClient,GCMessageAvailable_t,0>_vtbl *)&CCallback<GCSDK::CGCClient,GCMessageAvailable_t,0>::`vftable';
  if ( !v5 )
    _SteamAPI_UnregisterCallback(a1: &this->m_callbackGCMessageAvailable);
  CUtlRBTree<CUtlMap<CSteamID,GCSDK::CSharedObjectCache *,unsigned short>::Node_t,unsigned short,CUtlMap<CSteamID,GCSDK::CSharedObjectCache *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CSteamID,GCSDK::CSharedObjectCache *,unsigned short>::Node_t,unsigned short>,unsigned short>>::RemoveAll(this: &this->m_mapSOCache.m_Tree);
  this->m_mapSOCache.m_Tree.m_FirstFree = -1;
  if ( this->m_mapSOCache.m_Tree.m_Elements.m_nGrowSize >= 0 )
  {
    if ( this->m_mapSOCache.m_Tree.m_Elements.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_mapSOCache.m_Tree.m_Elements.m_pMemory);
      this->m_mapSOCache.m_Tree.m_Elements.m_pMemory = nullptr;
    }
    this->m_mapSOCache.m_Tree.m_Elements.m_nAllocationCount = 0;
  }
  this->m_mapSOCache.m_Tree.m_LastAlloc.index = -1;
  if ( this->m_mapSOCache.m_Tree.m_Elements.m_nGrowSize >= 0 )
  {
    if ( this->m_mapSOCache.m_Tree.m_Elements.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_mapSOCache.m_Tree.m_Elements.m_pMemory);
      this->m_mapSOCache.m_Tree.m_Elements.m_pMemory = nullptr;
    }
    this->m_mapSOCache.m_Tree.m_Elements.m_nAllocationCount = 0;
  }
  GCSDK::CJobMgr::~CJobMgr(this: &this->m_JobMgr);
  if ( this->m_memMsg.m_nGrowSize >= 0 )
  {
    if ( this->m_memMsg.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_memMsg.m_pMemory);
      this->m_memMsg.m_pMemory = nullptr;
    }
    this->m_memMsg.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10009220
// Name: public: GCSDK::CGCClient::CGCClient(class ISteamGameCoordinator __near *,bool)
// Source: json
//------------------------------------------------------------------------------
GCSDK::CGCClient *__thiscall GCSDK::CGCClient::CGCClient(
        GCSDK::CGCClient *this,
        ISteamGameCoordinator *pSteamGameCoordinator,
        bool bGameserver)
{
  UtlRBTreeNode_t<CUtlMap<CSteamID,GCSDK::CSharedObjectCache *,unsigned short>::Node_t,unsigned short> *m_pMemory; // edx

  this->m_pSteamGameCoordinator = nullptr;
  this->m_memMsg.m_pMemory = nullptr;
  this->m_memMsg.m_nAllocationCount = 1024;
  this->m_memMsg.m_nGrowSize = 0;
  this->m_memMsg.m_pMemory = (unsigned __int8 *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 1024);
  GCSDK::CJobMgr::CJobMgr(this: &this->m_JobMgr);
  this->m_mapSOCache.m_Tree.m_LessFunc.m_LessFunc = CIgnoredSessionsMgr::XNKID_LessFunc;
  this->m_mapSOCache.m_Tree.m_Elements.m_pMemory = nullptr;
  this->m_mapSOCache.m_Tree.m_Elements.m_nAllocationCount = 0;
  this->m_mapSOCache.m_Tree.m_Elements.m_nGrowSize = 0;
  m_pMemory = this->m_mapSOCache.m_Tree.m_Elements.m_pMemory;
  *(_DWORD *)&this->m_mapSOCache.m_Tree.m_Root = 0xFFFF;
  *(_DWORD *)&this->m_mapSOCache.m_Tree.m_FirstFree = -1;
  this->m_mapSOCache.m_Tree.m_pElements = m_pMemory;
  this->m_callbackGCMessageAvailable.m_nCallbackFlags = 0;
  this->m_callbackGCMessageAvailable.m_iCallback = 0;
  this->m_callbackGCMessageAvailable.__vftable = (CCallback<GCSDK::CGCClient,GCMessageAvailable_t,0>_vtbl *)&CCallback<GCSDK::CGCClient,GCMessageAvailable_t,0>::`vftable';
  this->m_callbackGCMessageAvailable.m_pObj = nullptr;
  this->m_callbackGCMessageAvailable.m_Func = nullptr;
  if ( bGameserver )
    this->m_callbackGCMessageAvailable.m_nCallbackFlags |= 2u;
  if ( pSteamGameCoordinator != nullptr )
    GCSDK::CGCClient::BInit(this, pSteamGameCoordinator);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10009360
// Name: public: class GCSDK::CSharedObjectCache __near * GCSDK::CGCClient::FindSOCache(class CSteamID const __near &,bool)
// Source: json
//------------------------------------------------------------------------------
GCSDK::CSharedObjectCache *__thiscall GCSDK::CGCClient::FindSOCache(
        GCSDK::CGCClient *this,
        const CSteamID *steamID,
        bool bCreateIfMissing)
{
  unsigned int m_unAll64Bits; // edx
  unsigned int m_unAll64Bits_high; // eax
  CUtlMap<CSteamID,GCSDK::CSharedObjectCache *,unsigned short> *p_m_mapSOCache; // edi
  unsigned __int16 v6; // ax
  int v7; // ebx
  GCSDK::CSharedObjectCache *v9; // eax
  GCSDK::CSharedObjectCache *v10; // esi
  int v11; // eax
  CUtlMap<CSteamID,GCSDK::CSharedObjectCache *,unsigned short>::Node_t search; // [esp+Ch] [ebp-10h] BYREF
  GCSDK::CGCClient *v13; // [esp+18h] [ebp-4h]

  m_unAll64Bits = steamID->m_steamid.m_unAll64Bits;
  m_unAll64Bits_high = HIDWORD(steamID->m_steamid.m_unAll64Bits);
  v13 = this;
  p_m_mapSOCache = &this->m_mapSOCache;
  search.key.m_steamid.m_unAll64Bits = __PAIR64__(m_unAll64Bits_high, m_unAll64Bits);
  v6 = CUtlRBTree<CUtlMap<CSteamID,GCSDK::CSharedObjectCache *,unsigned short>::Node_t,unsigned short,CUtlMap<CSteamID,GCSDK::CSharedObjectCache *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CSteamID,GCSDK::CSharedObjectCache *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
         this: &this->m_mapSOCache.m_Tree,
         &search);
  v7 = v6;
  if ( v6 < p_m_mapSOCache->m_Tree.m_Elements.m_nAllocationCount
    && v6 <= p_m_mapSOCache->m_Tree.m_LastAlloc.index
    && CUtlRBTree<CUtlMap<CSteamID,GCSDK::CSharedObjectCache *,unsigned short>::Node_t,unsigned short,CUtlMap<CSteamID,GCSDK::CSharedObjectCache *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CSteamID,GCSDK::CSharedObjectCache *,unsigned short>::Node_t,unsigned short>,unsigned short>>::LeftChild(
         this: &p_m_mapSOCache->m_Tree,
         i: v6) != v6 )
  {
    return v13->m_mapSOCache.m_Tree.m_Elements.m_pMemory[v7].m_Data.elem;
  }
  if ( !bCreateIfMissing )
    return nullptr;
  v9 = (GCSDK::CSharedObjectCache *)operator new(nSize: 0x84u);
  if ( v9 != nullptr )
    v10 = GCSDK::CSharedObjectCache::CSharedObjectCache(this: v9, steamIDOwner: steamID);
  else
    v10 = nullptr;
  v11 = HIDWORD(steamID->m_steamid.m_unAll64Bits);
  *(_DWORD *)&search.key.m_steamid.m_comp = steamID->m_steamid.m_comp;
  *((_DWORD *)&search.key.m_steamid.m_comp + 1) = v11;
  search.elem = v10;
  CUtlRBTree<CUtlMap<CSteamID,GCSDK::CSharedObjectCache *,unsigned short>::Node_t,unsigned short,CUtlMap<CSteamID,GCSDK::CSharedObjectCache *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CSteamID,GCSDK::CSharedObjectCache *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Insert(
    this: &p_m_mapSOCache->m_Tree,
    insert: &search);
  return v10;
}

//------------------------------------------------------------------------------
// Address: 0x10009430
// Name: public: void GCSDK::CGCClient::RemoveSOCache(class CSteamID const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GCSDK::CGCClient::RemoveSOCache(GCSDK::CGCClient *this, GCSDK::CSharedObjectCache *ownerID)
{
  GCSDK::CSharedObjectCache_vtbl *v2; // edx
  CSteamID *m_pMemory; // eax
  CUtlMap<CSteamID,GCSDK::CSharedObjectCache *,unsigned short> *p_m_mapSOCache; // esi
  unsigned __int16 v5; // ax
  unsigned __int16 v6; // di
  int v7; // ebx
  int v8; // ebx
  GCSDK::CSharedObjectCache *elem; // ecx
  CUtlMap<CSteamID,GCSDK::CSharedObjectCache *,unsigned short>::Node_t search; // [esp+Ch] [ebp-10h] BYREF
  GCSDK::CGCClient *v11; // [esp+18h] [ebp-4h]
  GCSDK::CSharedObjectCache *pSOCache; // [esp+24h] [ebp+8h]

  v2 = ownerID->__vftable;
  m_pMemory = ownerID->m_context.m_vecSubscribers.m_Memory.m_pMemory;
  v11 = this;
  p_m_mapSOCache = &this->m_mapSOCache;
  search.key.m_steamid.m_unAll64Bits = __PAIR64__((unsigned int)m_pMemory, (unsigned int)v2);
  v5 = CUtlRBTree<CUtlMap<CSteamID,GCSDK::CSharedObjectCache *,unsigned short>::Node_t,unsigned short,CUtlMap<CSteamID,GCSDK::CSharedObjectCache *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CSteamID,GCSDK::CSharedObjectCache *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
         this: &this->m_mapSOCache.m_Tree,
         &search);
  v6 = v5;
  v7 = v5;
  if ( v5 < p_m_mapSOCache->m_Tree.m_Elements.m_nAllocationCount
    && v5 <= p_m_mapSOCache->m_Tree.m_LastAlloc.index
    && CUtlRBTree<CUtlMap<CSteamID,GCSDK::CSharedObjectCache *,unsigned short>::Node_t,unsigned short,CUtlMap<CSteamID,GCSDK::CSharedObjectCache *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CSteamID,GCSDK::CSharedObjectCache *,unsigned short>::Node_t,unsigned short>,unsigned short>>::LeftChild(
         this: &p_m_mapSOCache->m_Tree,
         i: v5) != v5 )
  {
    v8 = v7;
    elem = v11->m_mapSOCache.m_Tree.m_Elements.m_pMemory[v8].m_Data.elem;
    pSOCache = elem;
    if ( elem->m_bInitialized )
    {
      GCSDK::CSharedObjectCache::NotifyUnsubscribe(this: elem);
      ((void (__thiscall *)(GCSDK::CSharedObjectCache *, int))pSOCache->dtr_CSharedObjectCache)(a1: pSOCache, a2: 1);
      if ( v6 != 0xFFFF )
      {
        CUtlRBTree<CUtlMap<CSteamID,GCSDK::CSharedObjectCache *,unsigned short>::Node_t,unsigned short,CUtlMap<CSteamID,GCSDK::CSharedObjectCache *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CSteamID,GCSDK::CSharedObjectCache *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Unlink(
          this: &p_m_mapSOCache->m_Tree,
          elem: v6);
        p_m_mapSOCache->m_Tree.m_Elements.m_pMemory[v8].m_Left = v6;
        p_m_mapSOCache->m_Tree.m_Elements.m_pMemory[v8].m_Right = p_m_mapSOCache->m_Tree.m_FirstFree;
        --p_m_mapSOCache->m_Tree.m_NumElements;
        p_m_mapSOCache->m_Tree.m_FirstFree = v6;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100094F0
// Name: public: virtual bool GCSDK::CGCSOCreateJob::BYieldingRunGCJob(class GCSDK::CNetPacket __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall GCSDK::CGCSOCreateJob::BYieldingRunGCJob(GCSDK::CGCSOCreateJob *this, GCSDK::CNetPacket *pNetPacket)
{
  GCSDK::CGCClient *m_pGCClient; // ecx
  unsigned int m_cubData; // esi
  unsigned __int8 *v4; // eax
  GCSDK::CSharedObjectCache *SOCache; // eax
  int v7; // [esp-8h] [ebp-2Ch]
  GCSDK::CGCMsg<GCSDK::SOMsgType_t> msg; // [esp+4h] [ebp-20h] BYREF

  m_pGCClient = this->m_pGCClient;
  m_cubData = pNetPacket->m_cubData;
  v4 = pNetPacket->m_pubData + 30;
  msg.m_pubPkt = pNetPacket->m_pubData;
  msg.m_pubVarRead = msg.m_pubPkt + 42;
  msg.m_cubMsgHdr = 30;
  msg.m_cubStruct = 12;
  msg.m_pubBody = v4;
  msg.m_cubPkt = m_cubData;
  msg.m_bAlloced = false;
  msg.__vftable = (GCSDK::CGCMsg<GCSDK::SOMsgType_t>_vtbl *)&GCSDK::CGCMsg<GCSDK::SOMsgType_t>::`vftable';
  v7 = *((_DWORD *)v4 + 2);
  SOCache = GCSDK::CGCClient::FindSOCache(this: m_pGCClient, steamID: (const CSteamID *)v4, bCreateIfMissing: true);
  GCSDK::CSharedObjectCache::BCreateFromMsg(this: SOCache, nTypeID: v7, pMsg: &msg);
  msg.__vftable = (GCSDK::CGCMsg<GCSDK::SOMsgType_t>_vtbl *)&GCSDK::CMsgBase_t<GCSDK::GCMsgHdrEx_t>::`vftable';
  if ( msg.m_bAlloced && msg.m_pubPkt != nullptr )
    CThreadSafeMultiMemoryPool::Free(this: &GCSDK::g_MemPoolMsg, pvMem: msg.m_pubPkt);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10009570
// Name: public: virtual bool GCSDK::CGCSODestroyJob::BYieldingRunGCJob(class GCSDK::CNetPacket __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall GCSDK::CGCSODestroyJob::BYieldingRunGCJob(GCSDK::CGCSODestroyJob *this, GCSDK::CNetPacket *pNetPacket)
{
  GCSDK::CGCClient *m_pGCClient; // ecx
  unsigned int m_cubData; // esi
  unsigned __int8 *v4; // eax
  CUtlRBTree<CUtlMap<CSteamID,GCSDK::CSharedObjectCache *,unsigned short>::Node_t,unsigned short,CUtlMap<CSteamID,GCSDK::CSharedObjectCache *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CSteamID,GCSDK::CSharedObjectCache *,unsigned short>::Node_t,unsigned short>,unsigned short> > *p_m_Tree; // edi
  unsigned __int16 v6; // ax
  int v7; // ebx
  GCSDK::CSharedObjectCache *m_pNext; // ecx
  GCSDK::CGCMsg<GCSDK::SOMsgType_t> msg; // [esp+Ch] [ebp-2Ch] BYREF
  CUtlMap<CSteamID,GCSDK::CSharedObjectCache *,unsigned short>::Node_t search; // [esp+2Ch] [ebp-Ch] BYREF
  GCSDK::CNetPacket *pNetPacketa; // [esp+40h] [ebp+8h]

  m_pGCClient = this->m_pGCClient;
  m_cubData = pNetPacket->m_cubData;
  v4 = pNetPacket->m_pubData + 30;
  msg.m_pubPkt = pNetPacket->m_pubData;
  pNetPacketa = (GCSDK::CNetPacket *)m_pGCClient;
  p_m_Tree = &m_pGCClient->m_mapSOCache.m_Tree;
  msg.m_cubMsgHdr = 30;
  msg.m_cubStruct = 12;
  msg.m_pubBody = v4;
  msg.m_cubPkt = m_cubData;
  msg.m_bAlloced = false;
  msg.m_pubVarRead = msg.m_pubPkt + 42;
  msg.__vftable = (GCSDK::CGCMsg<GCSDK::SOMsgType_t>_vtbl *)&GCSDK::CGCMsg<GCSDK::SOMsgType_t>::`vftable';
  search.key.m_steamid.m_unAll64Bits = *(_QWORD *)v4;
  v6 = CUtlRBTree<CUtlMap<CSteamID,GCSDK::CSharedObjectCache *,unsigned short>::Node_t,unsigned short,CUtlMap<CSteamID,GCSDK::CSharedObjectCache *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CSteamID,GCSDK::CSharedObjectCache *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
         this: &m_pGCClient->m_mapSOCache.m_Tree,
         &search);
  v7 = v6;
  if ( v6 < p_m_Tree->m_Elements.m_nAllocationCount
    && v6 <= p_m_Tree->m_LastAlloc.index
    && CUtlRBTree<CUtlMap<CSteamID,GCSDK::CSharedObjectCache *,unsigned short>::Node_t,unsigned short,CUtlMap<CSteamID,GCSDK::CSharedObjectCache *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CSteamID,GCSDK::CSharedObjectCache *,unsigned short>::Node_t,unsigned short>,unsigned short>>::LeftChild(
         this: p_m_Tree,
         i: v6) != v6 )
  {
    m_pNext = (GCSDK::CSharedObjectCache *)pNetPacketa[17].m_pNext[v7].m_pNext;
    if ( m_pNext != nullptr )
      GCSDK::CSharedObjectCache::BDestroyFromMsg(
        this: m_pNext,
        nTypeID: *(_DWORD *)&msg.m_pubPkt[msg.m_cubMsgHdr + 8],
        pMsg: &msg);
  }
  msg.__vftable = (GCSDK::CGCMsg<GCSDK::SOMsgType_t>_vtbl *)&GCSDK::CMsgBase_t<GCSDK::GCMsgHdrEx_t>::`vftable';
  if ( msg.m_bAlloced && msg.m_pubPkt != nullptr )
    CThreadSafeMultiMemoryPool::Free(this: &GCSDK::g_MemPoolMsg, pvMem: msg.m_pubPkt);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10009650
// Name: public: virtual bool GCSDK::CGCSOUpdateJob::BYieldingRunGCJob(class GCSDK::CNetPacket __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall GCSDK::CGCSOUpdateJob::BYieldingRunGCJob(GCSDK::CGCSOUpdateJob *this, GCSDK::CNetPacket *pNetPacket)
{
  GCSDK::CGCClient *m_pGCClient; // ecx
  unsigned int m_cubData; // esi
  unsigned __int8 *v4; // eax
  GCSDK::CSharedObjectCache *SOCache; // eax
  int v7; // [esp-8h] [ebp-2Ch]
  GCSDK::CGCMsg<GCSDK::SOMsgType_t> msg; // [esp+4h] [ebp-20h] BYREF

  m_pGCClient = this->m_pGCClient;
  m_cubData = pNetPacket->m_cubData;
  v4 = pNetPacket->m_pubData + 30;
  msg.m_pubPkt = pNetPacket->m_pubData;
  msg.m_pubVarRead = msg.m_pubPkt + 42;
  msg.m_cubMsgHdr = 30;
  msg.m_cubStruct = 12;
  msg.m_pubBody = v4;
  msg.m_cubPkt = m_cubData;
  msg.m_bAlloced = false;
  msg.__vftable = (GCSDK::CGCMsg<GCSDK::SOMsgType_t>_vtbl *)&GCSDK::CGCMsg<GCSDK::SOMsgType_t>::`vftable';
  v7 = *((_DWORD *)v4 + 2);
  SOCache = GCSDK::CGCClient::FindSOCache(this: m_pGCClient, steamID: (const CSteamID *)v4, bCreateIfMissing: true);
  GCSDK::CSharedObjectCache::BUpdateFromMsg(this: SOCache, nTypeID: v7, pMsg: &msg);
  msg.__vftable = (GCSDK::CGCMsg<GCSDK::SOMsgType_t>_vtbl *)&GCSDK::CMsgBase_t<GCSDK::GCMsgHdrEx_t>::`vftable';
  if ( msg.m_bAlloced && msg.m_pubPkt != nullptr )
    CThreadSafeMultiMemoryPool::Free(this: &GCSDK::g_MemPoolMsg, pvMem: msg.m_pubPkt);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100096D0
// Name: public: virtual bool GCSDK::CGCSOCacheSubscribedJob::BYieldingRunGCJob(class GCSDK::CNetPacket __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall GCSDK::CGCSOCacheSubscribedJob::BYieldingRunGCJob(
        GCSDK::CGCSOCacheSubscribedJob *this,
        GCSDK::CNetPacket *pNetPacket)
{
  GCSDK::CGCClient *m_pGCClient; // ecx
  unsigned int m_cubData; // esi
  unsigned __int8 *v4; // edx
  GCSDK::CSharedObjectCache *SOCache; // eax
  GCSDK::CGCMsg<GCSDK::SOCacheSubscribed_t> msg; // [esp+4h] [ebp-20h] BYREF

  m_pGCClient = this->m_pGCClient;
  m_cubData = pNetPacket->m_cubData;
  v4 = pNetPacket->m_pubData + 30;
  msg.m_pubPkt = pNetPacket->m_pubData;
  msg.m_cubMsgHdr = 30;
  msg.m_cubStruct = 10;
  msg.m_pubBody = v4;
  msg.m_cubPkt = m_cubData;
  msg.m_bAlloced = false;
  msg.m_pubVarRead = msg.m_pubPkt + 40;
  msg.__vftable = (GCSDK::CGCMsg<GCSDK::SOCacheSubscribed_t>_vtbl *)&GCSDK::CGCMsg<GCSDK::SOCacheSubscribed_t>::`vftable';
  SOCache = GCSDK::CGCClient::FindSOCache(this: m_pGCClient, steamID: (const CSteamID *)v4, bCreateIfMissing: true);
  if ( SOCache != nullptr )
    GCSDK::CSharedObjectCache::BParseCacheSubscribedMsg(
      this: SOCache,
      cTypeCount: *(_WORD *)&msg.m_pubPkt[msg.m_cubMsgHdr + 8],
      pMsg: &msg);
  msg.__vftable = (GCSDK::CGCMsg<GCSDK::SOCacheSubscribed_t>_vtbl *)&GCSDK::CMsgBase_t<GCSDK::GCMsgHdrEx_t>::`vftable';
  if ( msg.m_bAlloced && msg.m_pubPkt != nullptr )
    CThreadSafeMultiMemoryPool::Free(this: &GCSDK::g_MemPoolMsg, pvMem: msg.m_pubPkt);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10009760
// Name: public: virtual bool GCSDK::CGCSOCacheUnsubscribedJob::BYieldingRunGCJob(class GCSDK::CNetPacket __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall GCSDK::CGCSOCacheUnsubscribedJob::BYieldingRunGCJob(
        GCSDK::CGCSOCacheUnsubscribedJob *this,
        GCSDK::CNetPacket *pNetPacket)
{
  GCSDK::CGCClient::RemoveSOCache(
    this: this->m_pGCClient,
    ownerID: (GCSDK::CSharedObjectCache *)(pNetPacket->m_pubData + 30));
  return 1;
}
