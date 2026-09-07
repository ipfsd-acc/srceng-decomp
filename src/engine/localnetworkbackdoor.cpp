// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: engine/localnetworkbackdoor.cpp
// Functions: 11
// ============================================================

#include "engine\localnetworkbackdoor.h"

//------------------------------------------------------------------------------
// Address: 0x1019FC80
// Name: public: static void CLocalNetworkBackdoor::InitFastCopy(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CLocalNetworkBackdoor::InitFastCopy()
{
  CClientState *BaseLocalClient; // eax
  int v1; // esi
  CClientState *v2; // eax
  ClientClass *ClientClass; // edi
  CClientState *v4; // eax
  ServerClass *ServerClass; // ebx
  int v6; // eax
  CStandardSendProxies *pSendProxies; // [esp+0h] [ebp-14h]
  CStandardRecvProxies *pRecvProxies; // [esp+4h] [ebp-10h]
  int nSlowCopyProps; // [esp+8h] [ebp-Ch] BYREF
  int nFastCopyProps; // [esp+Ch] [ebp-8h] BYREF
  unsigned int v11; // [esp+10h] [ebp-4h]

  BaseLocalClient = GetBaseLocalClient();
  if ( BaseLocalClient->m_NetChannel->IsLoopback(this: BaseLocalClient->m_NetChannel) )
  {
    pSendProxies = serverGameDLL->GetStandardSendProxies(this: serverGameDLL);
    v1 = 0;
    pRecvProxies = g_ClientDLL->GetStandardRecvProxies(this: g_ClientDLL);
    nFastCopyProps = 0;
    nSlowCopyProps = 0;
    if ( GetBaseLocalClient()->m_nServerClasses > 0 )
    {
      v11 = 0;
      do
      {
        v2 = GetBaseLocalClient();
        ClientClass = CBaseClientState::GetClientClass(this: v2, index: v1);
        if ( ClientClass == nullptr )
        {
          v4 = GetBaseLocalClient();
          _Error(
            a1: "InitFastCopy - missing client class %d (Should be equivelent of server class: %s)",
            v1,
            v4->m_pServerClasses[v11 / 0x10].m_ClassName);
        }
        ServerClass = SV_FindServerClass(pName: ClientClass->m_pNetworkName);
        if ( ServerClass == nullptr )
          _Error(a1: "InitFastCopy - missing server class %s", ClientClass->m_pNetworkName);
        LocalTransfer_InitFastCopy(
          pSendTable: ServerClass->m_pTable,
          pSendProxies,
          pRecvTable: ClientClass->m_pRecvTable,
          pRecvProxies,
          &nSlowCopyProps,
          &nFastCopyProps);
        v11 += 16;
        ++v1;
      }
      while ( v1 < GetBaseLocalClient()->m_nServerClasses );
    }
    v6 = 100 * nFastCopyProps / (nSlowCopyProps + nFastCopyProps + 1);
    if ( v6 <= 45 )
      _Warning(a1: "InitFastCopy: only %d%% fast props. Bug?\n", v6);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1019FDA0
// Name: public: void CLocalNetworkBackdoor::ForceFlushEntity(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLocalNetworkBackdoor::ForceFlushEntity(CLocalNetworkBackdoor *this, int iEntity)
{
  CLocalNetworkBackdoor::CCachedEntState *v2; // esi
  IClientNetworkable *m_pNetworkable; // ecx

  v2 = &this->m_CachedEntState[iEntity];
  m_pNetworkable = this->m_CachedEntState[iEntity].m_pNetworkable;
  if ( m_pNetworkable != nullptr )
    m_pNetworkable->Release(this: m_pNetworkable);
  v2->m_pNetworkable = nullptr;
  v2->m_iSerialNumber = -1;
  v2->m_bDormant = false;
  v2->m_pDataPointer = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1019FDE0
// Name: public: void CLocalNetworkBackdoor::StartEntityStateUpdate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLocalNetworkBackdoor::StartEntityStateUpdate(CLocalNetworkBackdoor *this)
{
  if ( this != nullptr )
    memset(dst: (unsigned __int8 *)this, value: 0, count: 0x100u);
  this->m_nEntsCreated = 0;
  this->m_nEntsChanged = 0;
  ClientDLL_FrameStageNotify(frameStage: FRAME_NET_UPDATE_START);
}

//------------------------------------------------------------------------------
// Address: 0x1019FE20
// Name: public: void CLocalNetworkBackdoor::EntityDormant(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLocalNetworkBackdoor::EntityDormant(CLocalNetworkBackdoor *this, int iEnt, int iSerialNum)
{
  CLocalNetworkBackdoor::CCachedEntState *v4; // edi
  IClientNetworkable *m_pNetworkable; // eax

  v4 = &this->m_CachedEntState[iEnt];
  m_pNetworkable = this->m_CachedEntState[iEnt].m_pNetworkable;
  if ( m_pNetworkable != nullptr )
  {
    if ( this->m_CachedEntState[iEnt].m_iSerialNumber == iSerialNum )
    {
      this->m_EntsAlive.m_Ints[iEnt >> 5] |= 1 << (iEnt & 0x1F);
      if ( !v4->m_bDormant )
      {
        m_pNetworkable->NotifyShouldTransmit(this: m_pNetworkable, a2: SHOULDTRANSMIT_END);
        v4->m_bDormant = true;
      }
    }
    else
    {
      m_pNetworkable->Release(this: m_pNetworkable);
      v4->m_pNetworkable = nullptr;
      this->m_PrevEntsAlive.m_Ints[iEnt >> 5] &= ~(1 << (iEnt & 0x1F));
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1019FEB0
// Name: public: void CLocalNetworkBackdoor::EntState(int,int,int,class SendTable const __near *,void const __near *,bool,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLocalNetworkBackdoor::EntState(
        CLocalNetworkBackdoor *this,
        int iEnt,
        int iSerialNum,
        int iClass,
        const SendTable *pSendTable,
        const void *pSourceEnt,
        bool bChanged,
        bool bShouldTransmit)
{
  int v9; // ebx
  CClientState *BaseLocalClient; // eax
  IClientNetworkable *m_pNetworkable; // edi
  int v12; // eax
  ClientClass *pClientClass; // [esp+Ch] [ebp-10h]
  IClientNetworkable **p_m_pNetworkable; // [esp+10h] [ebp-Ch]
  DataUpdateType_t updateType; // [esp+14h] [ebp-8h]
  int v16; // [esp+18h] [ebp-4h]
  bool bCreated; // [esp+2Ch] [ebp+10h]
  bool bExistedAndWasDormant; // [esp+3Ch] [ebp+20h]

  this->m_EntsAlive.m_Ints[iEnt >> 5] |= 1 << (iEnt & 0x1F);
  v9 = iEnt;
  updateType = iEnt >> 5;
  v16 = 1 << (iEnt & 0x1F);
  BaseLocalClient = GetBaseLocalClient();
  pClientClass = CBaseClientState::GetClientClass(this: BaseLocalClient, index: iClass);
  if ( pClientClass == nullptr )
    _Error(a1: "CLocalNetworkBackdoor::EntState - missing client class %d", iClass);
  m_pNetworkable = this->m_CachedEntState[v9].m_pNetworkable;
  p_m_pNetworkable = &this->m_CachedEntState[v9].m_pNetworkable;
  if ( bShouldTransmit )
  {
    bExistedAndWasDormant = false;
    if ( m_pNetworkable != nullptr )
    {
      if ( iSerialNum == this->m_CachedEntState[v9].m_iSerialNumber )
      {
        bExistedAndWasDormant = this->m_CachedEntState[v9].m_bDormant;
      }
      else
      {
        m_pNetworkable->Release(this: m_pNetworkable);
        m_pNetworkable = nullptr;
        this->m_PrevEntsAlive.m_Ints[updateType] &= ~v16;
      }
    }
    bCreated = false;
    if ( m_pNetworkable != nullptr )
    {
      v12 = 1;
    }
    else
    {
      m_pNetworkable = pClientClass->m_pCreateFn(a1: iEnt, a2: iSerialNum);
      this->m_EntsCreatedIndices[this->m_nEntsCreated++] = iEnt;
      this->m_CachedEntState[v9].m_iSerialNumber = iSerialNum;
      bCreated = true;
      this->m_CachedEntState[v9].m_pDataPointer = m_pNetworkable->GetDataTableBasePtr(this: m_pNetworkable);
      *p_m_pNetworkable = m_pNetworkable;
      this->m_CachedEntState[v9].m_bDormant = m_pNetworkable->IsDormant(this: m_pNetworkable);
      v12 = 0;
    }
    if ( bChanged || bCreated || bExistedAndWasDormant )
    {
      m_pNetworkable->PreDataUpdate(this: m_pNetworkable, a2: (DataUpdateType_t)v12);
      LocalTransfer_TransferEntity(
        pEdict: &sv.edicts[v9],
        pSendTable,
        pSrcEnt: pSourceEnt,
        pRecvTable: pClientClass->m_pRecvTable,
        pDestEnt: this->m_CachedEntState[v9].m_pDataPointer,
        bNewlyCreated: bCreated,
        bJustEnteredPVS: bExistedAndWasDormant,
        objectID: iEnt);
      if ( bExistedAndWasDormant )
      {
        this->m_EntsCreatedIndices[this->m_nEntsCreated++] = iEnt;
      }
      else if ( !bCreated )
      {
        this->m_EntsChangedIndices[this->m_nEntsChanged++] = iEnt;
      }
    }
  }
  else if ( m_pNetworkable != nullptr )
  {
    if ( this->m_CachedEntState[v9].m_iSerialNumber == iSerialNum )
    {
      if ( !this->m_CachedEntState[v9].m_bDormant )
      {
        m_pNetworkable->NotifyShouldTransmit(this: m_pNetworkable, a2: SHOULDTRANSMIT_END);
        this->m_CachedEntState[v9].m_bDormant = true;
      }
    }
    else
    {
      m_pNetworkable->Release(this: m_pNetworkable);
      *p_m_pNetworkable = nullptr;
      this->m_EntsAlive.m_Ints[updateType] &= ~v16;
      this->m_PrevEntsAlive.m_Ints[updateType] &= ~v16;
    }
  }
  else
  {
    this->m_EntsAlive.m_Ints[updateType] &= ~v16;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101A00E0
// Name: public: void CLocalNetworkBackdoor::ClearState(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLocalNetworkBackdoor::ClearState(CLocalNetworkBackdoor *this)
{
  int *p_m_iSerialNumber; // eax
  int i; // esi

  p_m_iSerialNumber = &this->m_CachedEntState[0].m_iSerialNumber;
  for ( i = 2048; i != 0; --i )
  {
    p_m_iSerialNumber[2] = 0;
    *p_m_iSerialNumber = -1;
    *((_BYTE *)p_m_iSerialNumber - 4) = 0;
    p_m_iSerialNumber[1] = 0;
    p_m_iSerialNumber += 4;
  }
  if ( this != (CLocalNetworkBackdoor *)-256 )
    memset(dst: (unsigned __int8 *)&this->m_PrevEntsAlive, value: 0, count: sizeof(this->m_PrevEntsAlive));
}

//------------------------------------------------------------------------------
// Address: 0x101A0120
// Name: public: void CLocalNetworkBackdoor::StartBackdoorMode(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLocalNetworkBackdoor::StartBackdoorMode(CLocalNetworkBackdoor *this)
{
  int v2; // ebx
  int *p_m_iSerialNumber; // edi
  int (__thiscall ***v4)(_DWORD); // eax
  int (__thiscall ***v5)(_DWORD); // esi
  int v6; // eax
  int v8; // [esp+10h] [ebp-4h]

  CLocalNetworkBackdoor::ClearState(this);
  v2 = 0;
  v8 = 1;
  p_m_iSerialNumber = &this->m_CachedEntState[0].m_iSerialNumber;
  do
  {
    v4 = (int (__thiscall ***)(_DWORD))entitylist->GetClientNetworkable(this: entitylist, a2: v2);
    v5 = v4;
    if ( v4 != nullptr )
    {
      p_m_iSerialNumber[2] = (int)v4;
      v6 = (**v4)(a1: v4);
      *p_m_iSerialNumber = *(unsigned __int16 *)((*(int (__thiscall **)(int))(*(_DWORD *)v6 + 8))(a1: v6) + 2);
      *((_BYTE *)p_m_iSerialNumber - 4) = (*v5)[9](a1: v5);
      p_m_iSerialNumber[1] = (*v5)[12](a1: v5);
      this->m_PrevEntsAlive.m_Ints[v2 >> 5] |= v8;
    }
    ++v2;
    p_m_iSerialNumber += 4;
    v8 = __ROL4__(v8, 1);
  }
  while ( v2 < 2048 );
}

//------------------------------------------------------------------------------
// Address: 0x101A01C0
// Name: public: void CLocalNetworkBackdoor::StopBackdoorMode(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall CLocalNetworkBackdoor::StopBackdoorMode(CLocalNetworkBackdoor *this)
{
  CLocalNetworkBackdoor::ClearState(this);
}

//------------------------------------------------------------------------------
// Address: 0x101A01D0
// Name: public: void CLocalNetworkBackdoor::EndEntityStateUpdate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLocalNetworkBackdoor::EndEntityStateUpdate(CLocalNetworkBackdoor *this)
{
  IClientNetworkable *m_pNetworkable; // esi
  CLocalNetworkBackdoor::CCachedEntState *v3; // ebx
  int v4; // esi
  unsigned __int16 *m_EntsChangedIndices; // ebx
  IClientNetworkable *v6; // ecx
  CLocalNetworkBackdoor *v7; // ecx
  int v8; // edx
  int v9; // ebx
  int v10; // eax
  int v11; // esi
  IClientNetworkable *v12; // ecx
  IMDLCache *cacheCriticalSection; // [esp+Ch] [ebp-14h]
  unsigned int toDelete; // [esp+10h] [ebp-10h]
  CLocalNetworkBackdoor *v15; // [esp+14h] [ebp-Ch]
  int i; // [esp+18h] [ebp-8h]
  int ia; // [esp+18h] [ebp-8h]
  unsigned __int16 *m_EntsCreatedIndices; // [esp+1Ch] [ebp-4h]
  int v19; // [esp+1Ch] [ebp-4h]

  cacheCriticalSection = g_pMDLCache;
  ((void (*)(void))g_pMDLCache->BeginLock)();
  ClientDLL_FrameStageNotify(frameStage: FRAME_NET_UPDATE_POSTDATAUPDATE_START);
  i = 0;
  if ( this->m_nEntsCreated > 0 )
  {
    m_EntsCreatedIndices = this->m_EntsCreatedIndices;
    do
    {
      m_pNetworkable = this->m_CachedEntState[*m_EntsCreatedIndices].m_pNetworkable;
      v3 = &this->m_CachedEntState[*m_EntsCreatedIndices];
      m_pNetworkable->PostDataUpdate(this: m_pNetworkable, a2: DATA_UPDATE_CREATED);
      m_pNetworkable->NotifyShouldTransmit(this: m_pNetworkable, a2: SHOULDTRANSMIT_START);
      ++m_EntsCreatedIndices;
      v3->m_bDormant = false;
      ++i;
    }
    while ( i < this->m_nEntsCreated );
  }
  v4 = 0;
  if ( this->m_nEntsChanged > 0 )
  {
    m_EntsChangedIndices = this->m_EntsChangedIndices;
    do
    {
      v6 = this->m_CachedEntState[*m_EntsChangedIndices].m_pNetworkable;
      v6->PostDataUpdate(this: v6, a2: DATA_UPDATE_DATATABLE_CHANGED);
      ++v4;
      ++m_EntsChangedIndices;
    }
    while ( v4 < this->m_nEntsChanged );
  }
  ClientDLL_FrameStageNotify(frameStage: FRAME_NET_UPDATE_POSTDATAUPDATE_END);
  ia = 0;
  v7 = this;
  v15 = this;
  do
  {
    v8 = v7->m_PrevEntsAlive.m_Ints[0] & (v7->m_PrevEntsAlive.m_Ints[0] ^ v7->m_EntsAlive.m_Ints[0]);
    toDelete = v8;
    if ( v8 != 0 )
    {
      v9 = 0;
      v19 = 1;
      do
      {
        if ( (v8 & v19) != 0 )
        {
          v10 = v9 + ia;
          if ( v9 + ia < 2048 )
          {
            v11 = 2 * (v10 + 547);
            v12 = this->m_CachedEntState[v10].m_pNetworkable;
            if ( v12 != nullptr )
            {
              v12->Release(this: v12);
              v8 = toDelete;
              this->m_EntsAlive.m_Ints[2 * v11] = 0;
            }
          }
        }
        ++v9;
        v19 = __ROL4__(v19, 1);
      }
      while ( v9 < 32 );
      v7 = v15;
    }
    v7 = (CLocalNetworkBackdoor *)((char *)v7 + 4);
    v15 = v7;
    ia += 32;
  }
  while ( ia < 2048 );
  memcpy(
    dst: (unsigned __int8 *)&this->m_PrevEntsAlive,
    src: (unsigned __int8 *)this,
    count: sizeof(this->m_PrevEntsAlive));
  ClientDLL_FrameStageNotify(frameStage: FRAME_NET_UPDATE_END);
  cacheCriticalSection->EndLock(this: cacheCriticalSection);
}

//------------------------------------------------------------------------------
// Address: 0x101A0350
// Name: public: void CLocalNetworkBackdoor::ProcessDormantEntities(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLocalNetworkBackdoor::ProcessDormantEntities(CLocalNetworkBackdoor *this)
{
  int i; // eax
  int v3; // edi
  edict_t *v4; // esi
  int m_fStateFlags; // eax
  UtlLinkedListElem_t<unsigned short,unsigned short> *m_pMemory; // ecx

  for ( i = this->m_PendingDormantEntities.m_Head;
        i != 0xFFFF;
        i = this->m_PendingDormantEntities.m_Memory.m_pMemory[v3].m_Next )
  {
    v3 = (unsigned __int16)i;
    v4 = &sv.edicts[this->m_PendingDormantEntities.m_Memory.m_pMemory[v3].m_Element];
    m_fStateFlags = v4->m_fStateFlags;
    if ( (v4->m_fStateFlags & 2) != 0 || (m_fStateFlags & 0x10) == 0 )
    {
      v4->m_fStateFlags = m_fStateFlags & 0xFFFFFFBF;
    }
    else
    {
      CLocalNetworkBackdoor::EntityDormant(
        this,
        iEnt: this->m_PendingDormantEntities.m_Memory.m_pMemory[v3].m_Element,
        iSerialNum: v4->m_NetworkSerialNumber);
      v4->m_fStateFlags &= ~0x40u;
    }
  }
  CUtlLinkedList<unsigned short,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<unsigned short,unsigned short>,unsigned short>>::RemoveAll(this: &this->m_PendingDormantEntities);
  if ( this->m_PendingDormantEntities.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_PendingDormantEntities.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_PendingDormantEntities.m_Memory.m_pMemory);
      this->m_PendingDormantEntities.m_Memory.m_pMemory = nullptr;
    }
    this->m_PendingDormantEntities.m_Memory.m_nAllocationCount = 0;
  }
  this->m_PendingDormantEntities.m_FirstFree = -1;
  m_pMemory = this->m_PendingDormantEntities.m_Memory.m_pMemory;
  *(_DWORD *)&this->m_PendingDormantEntities.m_NumAlloced = -65536;
  this->m_PendingDormantEntities.m_pElements = m_pMemory;
}

//------------------------------------------------------------------------------
// Address: 0x101A0420
// Name: public: void CLocalNetworkBackdoor::AddToPendingDormantEntityList(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLocalNetworkBackdoor::AddToPendingDormantEntityList(
        CLocalNetworkBackdoor *this,
        unsigned __int16 iEdict)
{
  edict_t *v2; // edx
  CUtlLinkedList<unsigned short,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<unsigned short,unsigned short>,unsigned short> > *p_m_PendingDormantEntities; // esi
  int v4; // edi
  UtlLinkedListElem_t<unsigned short,unsigned short> *v5; // eax

  v2 = &sv.edicts[iEdict];
  if ( (v2->m_fStateFlags & 0x40) == 0 )
  {
    p_m_PendingDormantEntities = &this->m_PendingDormantEntities;
    v2->m_fStateFlags |= 0x40u;
    v4 = CUtlLinkedList<unsigned short,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<unsigned short,unsigned short>,unsigned short>>::AllocInternal(
           this: &this->m_PendingDormantEntities,
           multilist: false);
    if ( (_WORD)v4 != 0xFFFF )
    {
      CUtlLinkedList<unsigned short,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<unsigned short,unsigned short>,unsigned short>>::LinkBefore(
        this: p_m_PendingDormantEntities,
        before: 0xFFFFu,
        elem: v4);
      v5 = &p_m_PendingDormantEntities->m_Memory.m_pMemory[v4];
      if ( v5 != nullptr )
        v5->m_Element = iEdict;
    }
  }
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x101A00C0
// Name: public: static void CLocalNetworkBackdoor::InitFastCopy(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CLocalNetworkBackdoor::InitFastCopy()
{
  CClientState *BaseLocalClient; // eax
  int v1; // esi
  CClientState *v2; // eax
  ClientClass *ClientClass; // edi
  CClientState *v4; // eax
  ServerClass *ServerClass; // ebx
  int v6; // eax
  CStandardSendProxies *pSendProxies; // [esp+0h] [ebp-14h]
  CStandardRecvProxies *pRecvProxies; // [esp+4h] [ebp-10h]
  int nSlowCopyProps; // [esp+8h] [ebp-Ch] BYREF
  int nFastCopyProps; // [esp+Ch] [ebp-8h] BYREF
  unsigned int v11; // [esp+10h] [ebp-4h]

  BaseLocalClient = GetBaseLocalClient();
  if ( BaseLocalClient->m_NetChannel->IsLoopback(this: BaseLocalClient->m_NetChannel) )
  {
    pSendProxies = serverGameDLL->GetStandardSendProxies(this: serverGameDLL);
    v1 = 0;
    pRecvProxies = g_ClientDLL->GetStandardRecvProxies(this: g_ClientDLL);
    nFastCopyProps = 0;
    nSlowCopyProps = 0;
    if ( GetBaseLocalClient()->m_nServerClasses > 0 )
    {
      v11 = 0;
      do
      {
        v2 = GetBaseLocalClient();
        ClientClass = CBaseClientState::GetClientClass(this: v2, index: v1);
        if ( ClientClass == nullptr )
        {
          v4 = GetBaseLocalClient();
          _Error(
            a1: "InitFastCopy - missing client class %d (Should be equivelent of server class: %s)",
            v1,
            v4->m_pServerClasses[v11 / 0x10].m_ClassName);
        }
        ServerClass = SV_FindServerClass(pName: ClientClass->m_pNetworkName);
        if ( ServerClass == nullptr )
          _Error(a1: "InitFastCopy - missing server class %s", ClientClass->m_pNetworkName);
        LocalTransfer_InitFastCopy(
          pSendTable: (CSendTablePrecalc *)ServerClass->m_pTable,
          pSendProxies,
          pRecvTable: (const RecvProp *)ClientClass->m_pRecvTable,
          pRecvProxies,
          &nSlowCopyProps,
          &nFastCopyProps);
        v11 += 16;
        ++v1;
      }
      while ( v1 < GetBaseLocalClient()->m_nServerClasses );
    }
    v6 = 100 * nFastCopyProps / (nSlowCopyProps + nFastCopyProps + 1);
    if ( v6 <= 45 )
      _Warning(a1: "InitFastCopy: only %d%% fast props. Bug?\n", v6);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101A01E0
// Name: public: void CLocalNetworkBackdoor::ForceFlushEntity(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLocalNetworkBackdoor::ForceFlushEntity(CLocalNetworkBackdoor *this, int iEntity)
{
  CLocalNetworkBackdoor::CCachedEntState *v2; // esi
  IClientNetworkable *m_pNetworkable; // ecx

  v2 = &this->m_CachedEntState[iEntity];
  m_pNetworkable = this->m_CachedEntState[iEntity].m_pNetworkable;
  if ( m_pNetworkable != nullptr )
    m_pNetworkable->Release(this: m_pNetworkable);
  v2->m_pNetworkable = nullptr;
  v2->m_iSerialNumber = -1;
  v2->m_bDormant = false;
  v2->m_pDataPointer = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x101A0220
// Name: public: void CLocalNetworkBackdoor::StartEntityStateUpdate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLocalNetworkBackdoor::StartEntityStateUpdate(CLocalNetworkBackdoor *this)
{
  if ( this != nullptr )
    memset(dst: (unsigned __int8 *)this, value: 0, count: 0x100u);
  this->m_nEntsCreated = 0;
  this->m_nEntsChanged = 0;
  ClientDLL_FrameStageNotify(frameStage: FRAME_NET_UPDATE_START);
}

//------------------------------------------------------------------------------
// Address: 0x101A0260
// Name: public: void CLocalNetworkBackdoor::EntityDormant(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLocalNetworkBackdoor::EntityDormant(CLocalNetworkBackdoor *this, int iEnt, int iSerialNum)
{
  CLocalNetworkBackdoor::CCachedEntState *v4; // edi
  IClientNetworkable *m_pNetworkable; // eax

  v4 = &this->m_CachedEntState[iEnt];
  m_pNetworkable = this->m_CachedEntState[iEnt].m_pNetworkable;
  if ( m_pNetworkable != nullptr )
  {
    if ( this->m_CachedEntState[iEnt].m_iSerialNumber == iSerialNum )
    {
      this->m_EntsAlive.m_Ints[iEnt >> 5] |= 1 << (iEnt & 0x1F);
      if ( !v4->m_bDormant )
      {
        m_pNetworkable->NotifyShouldTransmit(this: m_pNetworkable, a2: SHOULDTRANSMIT_END);
        v4->m_bDormant = true;
      }
    }
    else
    {
      m_pNetworkable->Release(this: m_pNetworkable);
      v4->m_pNetworkable = nullptr;
      this->m_PrevEntsAlive.m_Ints[iEnt >> 5] &= ~(1 << (iEnt & 0x1F));
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101A02F0
// Name: public: void CLocalNetworkBackdoor::EntState(int,int,int,class SendTable const __near *,void const __near *,bool,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLocalNetworkBackdoor::EntState(
        CLocalNetworkBackdoor *this,
        int iEnt,
        int iSerialNum,
        int iClass,
        const SendTable *pSendTable,
        unsigned __int8 *pSourceEnt,
        bool bChanged,
        bool bShouldTransmit)
{
  int v9; // ebx
  CClientState *BaseLocalClient; // eax
  IClientNetworkable *m_pNetworkable; // edi
  int v12; // eax
  ClientClass *pClientClass; // [esp+Ch] [ebp-10h]
  IClientNetworkable **p_m_pNetworkable; // [esp+10h] [ebp-Ch]
  DataUpdateType_t updateType; // [esp+14h] [ebp-8h]
  int v16; // [esp+18h] [ebp-4h]
  bool bCreated; // [esp+2Ch] [ebp+10h]
  bool bExistedAndWasDormant; // [esp+3Ch] [ebp+20h]

  this->m_EntsAlive.m_Ints[iEnt >> 5] |= 1 << (iEnt & 0x1F);
  v9 = iEnt;
  updateType = iEnt >> 5;
  v16 = 1 << (iEnt & 0x1F);
  BaseLocalClient = GetBaseLocalClient();
  pClientClass = CBaseClientState::GetClientClass(this: BaseLocalClient, index: iClass);
  if ( pClientClass == nullptr )
    _Error(a1: "CLocalNetworkBackdoor::EntState - missing client class %d", iClass);
  m_pNetworkable = this->m_CachedEntState[v9].m_pNetworkable;
  p_m_pNetworkable = &this->m_CachedEntState[v9].m_pNetworkable;
  if ( bShouldTransmit )
  {
    bExistedAndWasDormant = false;
    if ( m_pNetworkable != nullptr )
    {
      if ( iSerialNum == this->m_CachedEntState[v9].m_iSerialNumber )
      {
        bExistedAndWasDormant = this->m_CachedEntState[v9].m_bDormant;
      }
      else
      {
        m_pNetworkable->Release(this: m_pNetworkable);
        m_pNetworkable = nullptr;
        this->m_PrevEntsAlive.m_Ints[updateType] &= ~v16;
      }
    }
    bCreated = false;
    if ( m_pNetworkable != nullptr )
    {
      v12 = 1;
    }
    else
    {
      m_pNetworkable = pClientClass->m_pCreateFn(a1: iEnt, a2: iSerialNum);
      this->m_EntsCreatedIndices[this->m_nEntsCreated++] = iEnt;
      this->m_CachedEntState[v9].m_iSerialNumber = iSerialNum;
      bCreated = true;
      this->m_CachedEntState[v9].m_pDataPointer = m_pNetworkable->GetDataTableBasePtr(this: m_pNetworkable);
      *p_m_pNetworkable = m_pNetworkable;
      this->m_CachedEntState[v9].m_bDormant = m_pNetworkable->IsDormant(this: m_pNetworkable);
      v12 = 0;
    }
    if ( bChanged || bCreated || bExistedAndWasDormant )
    {
      m_pNetworkable->PreDataUpdate(this: m_pNetworkable, a2: (DataUpdateType_t)v12);
      LocalTransfer_TransferEntity(
        pEdict: &sv.edicts[v9],
        pSendTable,
        pSrcEnt: pSourceEnt,
        pRecvTable: pClientClass->m_pRecvTable,
        pDestEnt: (unsigned __int8 *)this->m_CachedEntState[v9].m_pDataPointer,
        bNewlyCreated: bCreated,
        bJustEnteredPVS: bExistedAndWasDormant,
        objectID: iEnt);
      if ( bExistedAndWasDormant )
      {
        this->m_EntsCreatedIndices[this->m_nEntsCreated++] = iEnt;
      }
      else if ( !bCreated )
      {
        this->m_EntsChangedIndices[this->m_nEntsChanged++] = iEnt;
      }
    }
  }
  else if ( m_pNetworkable != nullptr )
  {
    if ( this->m_CachedEntState[v9].m_iSerialNumber == iSerialNum )
    {
      if ( !this->m_CachedEntState[v9].m_bDormant )
      {
        m_pNetworkable->NotifyShouldTransmit(this: m_pNetworkable, a2: SHOULDTRANSMIT_END);
        this->m_CachedEntState[v9].m_bDormant = true;
      }
    }
    else
    {
      m_pNetworkable->Release(this: m_pNetworkable);
      *p_m_pNetworkable = nullptr;
      this->m_EntsAlive.m_Ints[updateType] &= ~v16;
      this->m_PrevEntsAlive.m_Ints[updateType] &= ~v16;
    }
  }
  else
  {
    this->m_EntsAlive.m_Ints[updateType] &= ~v16;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101A0520
// Name: public: void CLocalNetworkBackdoor::ClearState(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLocalNetworkBackdoor::ClearState(CLocalNetworkBackdoor *this)
{
  int *p_m_iSerialNumber; // eax
  int i; // esi

  p_m_iSerialNumber = &this->m_CachedEntState[0].m_iSerialNumber;
  for ( i = 2048; i != 0; --i )
  {
    p_m_iSerialNumber[2] = 0;
    *p_m_iSerialNumber = -1;
    *((_BYTE *)p_m_iSerialNumber - 4) = 0;
    p_m_iSerialNumber[1] = 0;
    p_m_iSerialNumber += 4;
  }
  if ( this != (CLocalNetworkBackdoor *)-256 )
    memset(dst: (unsigned __int8 *)&this->m_PrevEntsAlive, value: 0, count: sizeof(this->m_PrevEntsAlive));
}

//------------------------------------------------------------------------------
// Address: 0x101A0560
// Name: public: void CLocalNetworkBackdoor::StartBackdoorMode(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLocalNetworkBackdoor::StartBackdoorMode(CLocalNetworkBackdoor *this)
{
  int v2; // ebx
  int *p_m_iSerialNumber; // edi
  int (__thiscall ***v4)(_DWORD); // eax
  int (__thiscall ***v5)(_DWORD); // esi
  int v6; // eax
  int v8; // [esp+10h] [ebp-4h]

  CLocalNetworkBackdoor::ClearState(this);
  v2 = 0;
  v8 = 1;
  p_m_iSerialNumber = &this->m_CachedEntState[0].m_iSerialNumber;
  do
  {
    v4 = (int (__thiscall ***)(_DWORD))entitylist->GetClientNetworkable(this: entitylist, a2: v2);
    v5 = v4;
    if ( v4 != nullptr )
    {
      p_m_iSerialNumber[2] = (int)v4;
      v6 = (**v4)(a1: v4);
      *p_m_iSerialNumber = *(unsigned __int16 *)((*(int (__thiscall **)(int))(*(_DWORD *)v6 + 8))(a1: v6) + 2);
      *((_BYTE *)p_m_iSerialNumber - 4) = (*v5)[9](a1: v5);
      p_m_iSerialNumber[1] = (*v5)[12](a1: v5);
      this->m_PrevEntsAlive.m_Ints[v2 >> 5] |= v8;
    }
    ++v2;
    p_m_iSerialNumber += 4;
    v8 = __ROL4__(v8, 1);
  }
  while ( v2 < 2048 );
}

//------------------------------------------------------------------------------
// Address: 0x101A0600
// Name: public: void CLocalNetworkBackdoor::StopBackdoorMode(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall CLocalNetworkBackdoor::StopBackdoorMode(CLocalNetworkBackdoor *this)
{
  CLocalNetworkBackdoor::ClearState(this);
}

//------------------------------------------------------------------------------
// Address: 0x101A0610
// Name: public: void CLocalNetworkBackdoor::EndEntityStateUpdate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLocalNetworkBackdoor::EndEntityStateUpdate(CLocalNetworkBackdoor *this)
{
  IClientNetworkable *m_pNetworkable; // esi
  CLocalNetworkBackdoor::CCachedEntState *v3; // ebx
  int v4; // esi
  unsigned __int16 *m_EntsChangedIndices; // ebx
  IClientNetworkable *v6; // ecx
  CLocalNetworkBackdoor *v7; // ecx
  int v8; // edx
  int v9; // ebx
  int v10; // eax
  int v11; // esi
  IClientNetworkable *v12; // ecx
  IMDLCache *cacheCriticalSection; // [esp+Ch] [ebp-14h]
  unsigned int toDelete; // [esp+10h] [ebp-10h]
  CLocalNetworkBackdoor *v15; // [esp+14h] [ebp-Ch]
  int i; // [esp+18h] [ebp-8h]
  int ia; // [esp+18h] [ebp-8h]
  unsigned __int16 *m_EntsCreatedIndices; // [esp+1Ch] [ebp-4h]
  int v19; // [esp+1Ch] [ebp-4h]

  cacheCriticalSection = g_pMDLCache;
  ((void (*)(void))g_pMDLCache->BeginLock)();
  ClientDLL_FrameStageNotify(frameStage: FRAME_NET_UPDATE_POSTDATAUPDATE_START);
  i = 0;
  if ( this->m_nEntsCreated > 0 )
  {
    m_EntsCreatedIndices = this->m_EntsCreatedIndices;
    do
    {
      m_pNetworkable = this->m_CachedEntState[*m_EntsCreatedIndices].m_pNetworkable;
      v3 = &this->m_CachedEntState[*m_EntsCreatedIndices];
      m_pNetworkable->PostDataUpdate(this: m_pNetworkable, a2: DATA_UPDATE_CREATED);
      m_pNetworkable->NotifyShouldTransmit(this: m_pNetworkable, a2: SHOULDTRANSMIT_START);
      ++m_EntsCreatedIndices;
      v3->m_bDormant = false;
      ++i;
    }
    while ( i < this->m_nEntsCreated );
  }
  v4 = 0;
  if ( this->m_nEntsChanged > 0 )
  {
    m_EntsChangedIndices = this->m_EntsChangedIndices;
    do
    {
      v6 = this->m_CachedEntState[*m_EntsChangedIndices].m_pNetworkable;
      v6->PostDataUpdate(this: v6, a2: DATA_UPDATE_DATATABLE_CHANGED);
      ++v4;
      ++m_EntsChangedIndices;
    }
    while ( v4 < this->m_nEntsChanged );
  }
  ClientDLL_FrameStageNotify(frameStage: FRAME_NET_UPDATE_POSTDATAUPDATE_END);
  ia = 0;
  v7 = this;
  v15 = this;
  do
  {
    v8 = v7->m_PrevEntsAlive.m_Ints[0] & (v7->m_PrevEntsAlive.m_Ints[0] ^ v7->m_EntsAlive.m_Ints[0]);
    toDelete = v8;
    if ( v8 != 0 )
    {
      v9 = 0;
      v19 = 1;
      do
      {
        if ( (v8 & v19) != 0 )
        {
          v10 = v9 + ia;
          if ( v9 + ia < 2048 )
          {
            v11 = 2 * (v10 + 547);
            v12 = this->m_CachedEntState[v10].m_pNetworkable;
            if ( v12 != nullptr )
            {
              v12->Release(this: v12);
              v8 = toDelete;
              this->m_EntsAlive.m_Ints[2 * v11] = 0;
            }
          }
        }
        ++v9;
        v19 = __ROL4__(v19, 1);
      }
      while ( v9 < 32 );
      v7 = v15;
    }
    v7 = (CLocalNetworkBackdoor *)((char *)v7 + 4);
    v15 = v7;
    ia += 32;
  }
  while ( ia < 2048 );
  memcpy(
    dst: (unsigned __int8 *)&this->m_PrevEntsAlive,
    src: (unsigned __int8 *)this,
    count: sizeof(this->m_PrevEntsAlive));
  ClientDLL_FrameStageNotify(frameStage: FRAME_NET_UPDATE_END);
  cacheCriticalSection->EndLock(this: cacheCriticalSection);
}

//------------------------------------------------------------------------------
// Address: 0x101A0790
// Name: public: void CLocalNetworkBackdoor::ProcessDormantEntities(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLocalNetworkBackdoor::ProcessDormantEntities(CLocalNetworkBackdoor *this)
{
  int i; // eax
  int v3; // edi
  edict_t *v4; // esi
  int m_fStateFlags; // eax
  UtlLinkedListElem_t<unsigned short,unsigned short> *m_pMemory; // ecx

  for ( i = this->m_PendingDormantEntities.m_Head;
        i != 0xFFFF;
        i = this->m_PendingDormantEntities.m_Memory.m_pMemory[v3].m_Next )
  {
    v3 = (unsigned __int16)i;
    v4 = &sv.edicts[this->m_PendingDormantEntities.m_Memory.m_pMemory[v3].m_Element];
    m_fStateFlags = v4->m_fStateFlags;
    if ( (v4->m_fStateFlags & 2) != 0 || (m_fStateFlags & 0x10) == 0 )
    {
      v4->m_fStateFlags = m_fStateFlags & 0xFFFFFFBF;
    }
    else
    {
      CLocalNetworkBackdoor::EntityDormant(
        this,
        iEnt: this->m_PendingDormantEntities.m_Memory.m_pMemory[v3].m_Element,
        iSerialNum: v4->m_NetworkSerialNumber);
      v4->m_fStateFlags &= ~0x40u;
    }
  }
  CUtlLinkedList<unsigned short,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<unsigned short,unsigned short>,unsigned short>>::RemoveAll(this: &this->m_PendingDormantEntities);
  if ( this->m_PendingDormantEntities.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_PendingDormantEntities.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_PendingDormantEntities.m_Memory.m_pMemory);
      this->m_PendingDormantEntities.m_Memory.m_pMemory = nullptr;
    }
    this->m_PendingDormantEntities.m_Memory.m_nAllocationCount = 0;
  }
  this->m_PendingDormantEntities.m_FirstFree = -1;
  m_pMemory = this->m_PendingDormantEntities.m_Memory.m_pMemory;
  *(_DWORD *)&this->m_PendingDormantEntities.m_NumAlloced = -65536;
  this->m_PendingDormantEntities.m_pElements = m_pMemory;
}

//------------------------------------------------------------------------------
// Address: 0x101A0860
// Name: public: void CLocalNetworkBackdoor::AddToPendingDormantEntityList(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLocalNetworkBackdoor::AddToPendingDormantEntityList(
        CLocalNetworkBackdoor *this,
        unsigned __int16 iEdict)
{
  edict_t *v2; // edx
  CUtlLinkedList<unsigned short,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<unsigned short,unsigned short>,unsigned short> > *p_m_PendingDormantEntities; // esi
  int v4; // edi
  UtlLinkedListElem_t<unsigned short,unsigned short> *v5; // eax

  v2 = &sv.edicts[iEdict];
  if ( (v2->m_fStateFlags & 0x40) == 0 )
  {
    p_m_PendingDormantEntities = &this->m_PendingDormantEntities;
    v2->m_fStateFlags |= 0x40u;
    v4 = (unsigned __int16)CUtlLinkedList<unsigned short,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<unsigned short,unsigned short>,unsigned short>>::AllocInternal(
                             this: &this->m_PendingDormantEntities,
                             multilist: false);
    if ( (_WORD)v4 != 0xFFFF )
    {
      CUtlLinkedList<unsigned short,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<unsigned short,unsigned short>,unsigned short>>::LinkBefore(
        this: p_m_PendingDormantEntities,
        before: 0xFFFFu,
        elem: v4);
      v5 = &p_m_PendingDormantEntities->m_Memory.m_pMemory[v4];
      if ( v5 != nullptr )
        v5->m_Element = iEdict;
    }
  }
}

} // namespace engine_xlsp
