// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: engine/cl_ents_parse.cpp
// Functions: 11
// ============================================================

#include "engine\cl_ents_parse.h"

//------------------------------------------------------------------------------
// Address: 0x10085090
// Name: void CL_DeleteDLLEntity(int,char __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CL_DeleteDLLEntity(int iEnt, char *reason, bool bOnRecreatingAllEntities)
{
  int v3; // esi
  ClientClass *v4; // eax

  v3 = entitylist->GetClientNetworkable(this: entitylist, a2: iEnt);
  if ( v3 != 0 )
  {
    v4 = (ClientClass *)(*(int (__thiscall **)(int))(*(_DWORD *)v3 + 8))(a1: v3);
    CL_RecordDeleteEntity(entnum: iEnt, pclass: v4);
    if ( bOnRecreatingAllEntities )
      (*(void (__thiscall **)(int))(*(_DWORD *)v3 + 52))(a1: v3);
    (*(void (__thiscall **)(int))(*(_DWORD *)v3 + 4))(a1: v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100850E0
// Name: CL_AddPostDataUpdateCall
// Source: json
//------------------------------------------------------------------------------
void __usercall CL_AddPostDataUpdateCall(CEntityReadInfo *u@<esi>, int iEnt, DataUpdateType_t updateType)
{
  if ( u->m_nPostDataUpdateCalls >= 2048 )
    _Error(a1: "CL_AddPostDataUpdateCall: overflowed u.m_PostDataUpdateCalls");
  u->m_PostDataUpdateCalls[u->m_nPostDataUpdateCalls].m_iEnt = iEnt;
  u->m_PostDataUpdateCalls[u->m_nPostDataUpdateCalls++].m_UpdateType = updateType;
}

//------------------------------------------------------------------------------
// Address: 0x10085120
// Name: void CL_FlushEntityPacket(class CClientFrame __near *,char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
void CL_FlushEntityPacket(CClientFrame *packet, const char *errorString, ...)
{
  CClientState *BaseLocalClient; // eax
  char str[2048]; // [esp+0h] [ebp-818h] BYREF
  con_nprint_s np; // [esp+800h] [ebp-18h] BYREF
  va_list params; // [esp+828h] [ebp+10h] BYREF

  va_start(params, errorString);
  V_vsnprintf(pDest: str, maxLen: 2048, pFormat: errorString, params);
  ConMsg(a1: "%s", str);
  np.time_to_live = 1.0;
  np.color[0] = 1.0;
  np.color[1] = 0.2;
  np.fixed_width_font = false;
  np.index = 0;
  np.color[2] = 0.0;
  Con_NXPrintf(info: &np, fmt: "WARNING:  CL_FlushEntityPacket, %s", str);
  BaseLocalClient = GetBaseLocalClient();
  CClientFrameManager::DeleteUnusedClientFrame(this: &BaseLocalClient->CClientFrameManager, pFrameToDelete: packet);
}

//------------------------------------------------------------------------------
// Address: 0x100851C0
// Name: class IClientNetworkable __near * CL_CreateDLLEntity(int,int,int)
// Source: json
//------------------------------------------------------------------------------
IClientNetworkable *__cdecl CL_CreateDLLEntity(unsigned int iEnt, int iClass, int iSerialNum)
{
  ClientClass *m_pClientClass; // esi
  IEngineVGuiInternal *v4; // eax

  m_pClientClass = GetBaseLocalClient()->m_pServerClasses[iClass].m_pClientClass;
  if ( m_pClientClass == nullptr )
    return nullptr;
  CL_RecordAddEntity(entnum: iEnt);
  if ( GetBaseLocalClient()->m_nSignonState != 6 )
  {
    _COM_TimestampedLog(a1: "cl:  create '%s'", m_pClientClass->m_pNetworkName);
    v4 = EngineVGui();
    v4->UpdateProgressBar(this: v4, a2: PROGRESS_CREATEENTITIES, a3: true);
  }
  return m_pClientClass->m_pCreateFn(a1: iEnt, a2: iSerialNum);
}

//------------------------------------------------------------------------------
// Address: 0x10085230
// Name: CL_CallPostDataUpdates
// Source: json
//------------------------------------------------------------------------------
void __cdecl CL_CallPostDataUpdates(CEntityReadInfo *u)
{
  IMDLCache *v1; // edi
  int v2; // ebx
  int *p_m_iEnt; // esi
  int v4; // edi
  bool bSaveResolvable; // [esp+Ch] [ebp-Ch]
  int saveSlot; // [esp+10h] [ebp-8h]
  IMDLCache *cacheCriticalSection; // [esp+14h] [ebp-4h]

  v1 = g_pMDLCache;
  cacheCriticalSection = g_pMDLCache;
  g_pMDLCache->BeginLock(this: g_pMDLCache);
  saveSlot = splitscreen->SetActiveSplitScreenPlayerSlot(this: splitscreen, a2: 0);
  v2 = 0;
  bSaveResolvable = splitscreen->SetLocalPlayerIsResolvable(
                      this: splitscreen,
                      a2: "cl_ents_parse.cpp",
                      a3: 549,
                      a4: false);
  if ( u->m_nPostDataUpdateCalls > 0 )
  {
    p_m_iEnt = &u->m_PostDataUpdateCalls[0].m_iEnt;
    do
    {
      v4 = entitylist->GetClientNetworkable(this: entitylist, a2: *p_m_iEnt);
      if ( v4 == 0 )
        _Error(a1: "CL_CallPostDataUpdates: missing ent %d", *p_m_iEnt);
      (*(void (__thiscall **)(int, int))(*(_DWORD *)v4 + 28))(a1: v4, a2: p_m_iEnt[1]);
      ++v2;
      p_m_iEnt += 2;
    }
    while ( v2 < u->m_nPostDataUpdateCalls );
    v1 = cacheCriticalSection;
  }
  splitscreen->SetActiveSplitScreenPlayerSlot(this: splitscreen, a2: saveSlot);
  splitscreen->SetLocalPlayerIsResolvable(this: splitscreen, a2: "cl_ents_parse.cpp", a3: 562, a4: bSaveResolvable);
  v1->EndLock(this: v1);
}

//------------------------------------------------------------------------------
// Address: 0x10085320
// Name: void CL_PreprocessEntities(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CL_PreprocessEntities()
{
  bool IsMultiplayer; // bl
  int *p_command_ack; // esi
  bool v2; // al
  int *v3; // esi
  int v4; // esi
  int m_nServerTick; // edi
  CClientState *BaseLocalClient; // eax
  IPrediction_vtbl *v7; // ebx
  CClientState *v8; // eax
  int v9; // [esp-4h] [ebp-10h]

  IsMultiplayer = NET_IsMultiplayer();
  p_command_ack = &GetBaseLocalClient()->command_ack;
  v2 = GetBaseLocalClient()->lastoutgoingcommand == *p_command_ack;
  if ( IsMultiplayer || v2 )
    CL_RunPrediction(reason: PREDICTION_SIMULATION_RESULTS_ARRIVING_ON_SEND_FRAME);
  v3 = &GetBaseLocalClient()->command_ack;
  v4 = *v3 - GetBaseLocalClient()->last_command_ack;
  m_nServerTick = GetBaseLocalClient()->m_ClockDriftMgr.m_nServerTick;
  BaseLocalClient = GetBaseLocalClient();
  v7 = g_pClientSidePrediction->__vftable;
  v9 = m_nServerTick - BaseLocalClient->last_server_tick;
  v8 = GetBaseLocalClient();
  v7->PreEntityPacketReceived(this: g_pClientSidePrediction, a2: v4, a3: v8->m_nCurrentSequence, a4: v9);
  CDebugOverlay::PurgeServerOverlays();
}

//------------------------------------------------------------------------------
// Address: 0x100853B0
// Name: public: virtual char const __near * CLC_BaselineAck::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CLC_BaselineAck::GetName(CLC_BaselineAck *this)
{
  return "clc_BaselineAck";
}

//------------------------------------------------------------------------------
// Address: 0x100853D0
// Name: void CL_CopyNewEntity(class CEntityReadInfo __near &,int,int)
// Source: json
//------------------------------------------------------------------------------
void __usercall CL_CopyNewEntity(int a1@<edi>, CEntityReadInfo *u, int iClass, int iSerialNum)
{
  int m_nNewEntity; // eax
  IClientNetworkable *DLLEntity; // edi
  int v7; // eax
  int v8; // eax
  int v9; // edi
  ClientClass *v10; // eax
  CClientState *BaseLocalClient; // eax
  char v12; // bl
  bf_read *m_pBuf; // eax
  const unsigned int *m_pData; // ecx
  int v15; // edx
  int v16; // ecx
  int v17; // edx
  int m_nDataBits; // eax
  IClientNetworkable_vtbl *v19; // edx
  CClientState *v20; // eax
  PackedEntity *EntityBaseline; // eax
  int v22; // eax
  CClientState *v23; // eax
  int v24; // eax
  RecvTable *v25; // ebx
  CClientState *v26; // eax
  bf_read *v27; // edx
  void *v28; // eax
  void *v29; // eax
  unsigned int *v30; // eax
  bf_read *v31; // eax
  const unsigned int *v32; // ecx
  int v33; // eax
  int v34; // edx
  int v35; // ecx
  int v36; // edx
  int v37; // ecx
  int v38; // ebx
  int v39; // edi
  BOOL v40; // [esp-1Ch] [ebp-406Ch]
  ClientClass *v41; // [esp-18h] [ebp-4068h]
  int v42; // [esp-14h] [ebp-4064h]
  bf_read *v43; // [esp-10h] [ebp-4060h]
  int v44; // [esp-Ch] [ebp-405Ch]
  int m_nBaseline; // [esp-Ch] [ebp-405Ch]
  unsigned int v46; // [esp-Ch] [ebp-405Ch]
  int v47; // [esp-Ch] [ebp-405Ch]
  int v48; // [esp-Ch] [ebp-405Ch]
  int v50; // [esp-8h] [ebp-4058h]
  unsigned int packedData[4096]; // [esp+4h] [ebp-404Ch] BYREF
  bf_write pOut; // [esp+4004h] [ebp-4Ch] BYREF
  CBitRead v53; // [esp+401Ch] [ebp-34h] BYREF
  DataUpdateType_t updateType; // [esp+4040h] [ebp-10h]
  ClientClass *pClientClass; // [esp+4044h] [ebp-Ch]
  void *pData; // [esp+4048h] [ebp-8h] BYREF
  int pDatalen; // [esp+404Ch] [ebp-4h] BYREF
  unsigned int entnum; // [esp+4058h] [ebp+8h]
  int entnuma; // [esp+4058h] [ebp+8h]

  m_nNewEntity = u->m_nNewEntity;
  if ( m_nNewEntity >= 2048 )
  {
    Host_Error(error: "CL_CopyNewEntity: m_nNewEntity >= MAX_EDICTS");
    return;
  }
  DLLEntity = (IClientNetworkable *)entitylist->GetClientNetworkable(this: entitylist, a2: m_nNewEntity);
  if ( iClass >= GetBaseLocalClient()->m_nServerClasses )
  {
    Host_Error(error: "CL_CopyNewEntity: invalid class index (%d).\n", iClass);
    return;
  }
  pClientClass = GetBaseLocalClient()->m_pServerClasses[iClass].m_pClientClass;
  if ( DLLEntity != nullptr )
  {
    v7 = DLLEntity->GetIClientUnknown(this: DLLEntity);
    if ( *(unsigned __int16 *)((*(int (__thiscall **)(int))(*(_DWORD *)v7 + 8))(a1: v7) + 2) == iSerialNum )
    {
      v12 = 0;
      goto LABEL_13;
    }
    entnum = u->m_nNewEntity;
    v8 = entitylist->GetClientNetworkable(this: entitylist, a2: u->m_nNewEntity);
    v9 = v8;
    if ( v8 != 0 )
    {
      v10 = (ClientClass *)(*(int (__thiscall **)(int))(*(_DWORD *)v8 + 8))(a1: v8);
      CL_RecordDeleteEntity(entnum, pclass: v10);
      (*(void (__thiscall **)(int))(*(_DWORD *)v9 + 4))(a1: v9);
    }
  }
  DLLEntity = CL_CreateDLLEntity(iEnt: u->m_nNewEntity, iClass, iSerialNum);
  if ( DLLEntity == nullptr )
  {
    v44 = u->m_nNewEntity;
    BaseLocalClient = GetBaseLocalClient();
    Host_Error(
      error: "CL_ParsePacketEntities:  Error creating entity %s(%i)\n",
      BaseLocalClient->m_pServerClasses[iClass].m_pClientClass->m_pNetworkName,
      v44);
    return;
  }
  v12 = 1;
LABEL_13:
  m_pBuf = u->m_pBuf;
  m_pData = m_pBuf->m_pData;
  if ( m_pData != nullptr )
  {
    v15 = (char *)m_pBuf->m_pDataIn - (char *)m_pData;
    v16 = 2 * (m_pBuf->m_nDataBytes & 3);
    v17 = 32 * (v15 >> 2) - m_pBuf->m_nBitsAvail;
    m_nDataBits = m_pBuf->m_nDataBits;
    entnuma = v17 + 4 * v16;
    if ( entnuma >= m_nDataBits )
      entnuma = m_nDataBits;
  }
  else
  {
    entnuma = 0;
  }
  v19 = DLLEntity->__vftable;
  updateType = v12 == 0;
  ((void (__thiscall *)(IClientNetworkable *, DataUpdateType_t, int))v19->PreDataUpdate)(
    a1: DLLEntity,
    a2: updateType,
    a3: a1);
  if ( u->m_bAsDelta
    && (v50 = u->m_nNewEntity,
        m_nBaseline = u->m_nBaseline,
        v20 = GetBaseLocalClient(),
        (EntityBaseline = CBaseClientState::GetEntityBaseline(this: v20, iBaseline: m_nBaseline, nEntityIndex: v50)) != nullptr)
    && EntityBaseline->m_pClientClass == pClientClass )
  {
    pData = EntityBaseline->m_pData;
    v22 = EntityBaseline->m_nBits & 0x7FFFFFFF;
  }
  else
  {
    v23 = GetBaseLocalClient();
    if ( !CBaseClientState::GetClassBaseline(this: v23, iClass, (const void **)&pData, &pDatalen) )
      _Error(a1: "CL_CopyNewEntity: GetClassBaseline(%d) failed.", iClass);
    v22 = 8 * pDatalen;
  }
  pDatalen = v22;
  v53.m_bOverflow = false;
  v53.m_nDataBits = -1;
  v53.m_nDataBytes = 0;
  v53.m_pDebugName = "CL_CopyNewEntity->fromBuf";
  CBitRead::StartReading(this: &v53, (const unsigned int *)pData, nBytes: (v22 + 7) >> 3, iStartBit: 0, nBits: v22);
  v24 = entitylist->GetClientNetworkable(this: entitylist, a2: u->m_nNewEntity);
  if ( v24 != 0 && (v25 = *(RecvTable **)((*(int (__thiscall **)(int))(*(_DWORD *)v24 + 8))(a1: v24) + 12)) != nullptr )
  {
    if ( u->m_bUpdateBaselines )
    {
      bf_write::bf_write(
        this: &pOut,
        pDebugName: "CL_CopyNewEntity->newBuf",
        pData: (unsigned __int8 *)packedData,
        nBytes: 0x4000,
        nBits: -1);
      RecvTable_MergeDeltas(
        pTable: v25,
        pOldState: (bf_read *)&v53,
        pNewState: u->m_pBuf,
        &pOut,
        objectID: u->m_nNewEntity,
        bDebugWatchInfo: false,
        pChangedProps: nullptr);
      v46 = (pOut.m_iCurBit + 7) >> 3;
      v42 = u->m_nNewEntity;
      v41 = pClientClass;
      v40 = u->m_nBaseline == 0;
      v26 = GetBaseLocalClient();
      CBaseClientState::SetEntityBaseline(
        this: v26,
        iBaseline: v40,
        pClientClass: v41,
        index: v42,
        (char *)packedData,
        length: v46);
      CBitRead::StartReading(this: &v53, pData: packedData, nBytes: (pOut.m_iCurBit + 7) >> 3, iStartBit: 0, nBits: -1);
      v27 = (bf_read *)&v53;
    }
    else
    {
      v47 = u->m_nNewEntity;
      v28 = DLLEntity->GetDataTableBasePtr(this: DLLEntity);
      RecvTable_Decode(pTable: v25, pStruct: v28, pIn: (bf_read *)&v53, objectID: v47);
      v27 = u->m_pBuf;
    }
    v48 = u->m_nNewEntity;
    v43 = v27;
    v29 = DLLEntity->GetDataTableBasePtr(this: DLLEntity);
    RecvTable_Decode(pTable: v25, pStruct: v29, pIn: v43, objectID: v48);
  }
  else
  {
    Host_Error(error: "CL_ParseDelta: invalid recv table for ent %d.\n", u->m_nNewEntity);
  }
  CL_AddPostDataUpdateCall(u, iEnt: u->m_nNewEntity, updateType);
  u->m_pTo->last_entity = u->m_nNewEntity;
  v30 = &u->m_pTo->transmit_entity.m_Ints[u->m_nNewEntity >> 5];
  *v30 |= 1 << (u->m_nNewEntity & 0x1F);
  v31 = u->m_pBuf;
  v32 = v31->m_pData;
  if ( v32 != nullptr )
  {
    v34 = (char *)v31->m_pDataIn - (char *)v32;
    v35 = 2 * (v31->m_nDataBytes & 3);
    v36 = 32 * (v34 >> 2) - v31->m_nBitsAvail;
    v33 = v31->m_nDataBits;
    v37 = v36 + 4 * v35;
    if ( v37 < v33 )
      v33 = v37;
  }
  else
  {
    v33 = 0;
  }
  v38 = v33 - entnuma;
  if ( cl_entityreport.m_pParent != nullptr && cl_entityreport.m_pParent->m_Value.m_nValue != 0 )
    CL_RecordEntityBits(entnum: u->m_nNewEntity, bitcount: v38);
  v39 = u->m_nNewEntity;
  if ( v39 >= 1 && v39 <= GetBaseLocalClient()->m_nMaxClients )
  {
    if ( u->m_nNewEntity == GetBaseLocalClient()->m_nPlayerSlot + 1 )
      u->m_nLocalPlayerBits += v38;
    else
      u->m_nOtherPlayerBits += v38;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100857A0
// Name: void CL_CopyExistingEntity(class CEntityReadInfo __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CL_CopyExistingEntity(int u)
{
  bf_read *v2; // eax
  const unsigned int *m_pData; // ecx
  int v4; // edx
  int v5; // ecx
  int v6; // edx
  int m_nDataBits; // eax
  int v8; // eax
  int v9; // edi
  int v10; // eax
  RecvTable *v11; // ebx
  void *v12; // eax
  int v13; // edi
  bf_read *v14; // eax
  const unsigned int *v15; // ecx
  int v16; // eax
  int v17; // edx
  int v18; // ecx
  int v19; // edx
  int v20; // ecx
  int v21; // ebx
  int v22; // edi
  bf_read *v23; // [esp-Ch] [ebp-14h]
  int v24; // [esp-8h] [ebp-10h]
  int start_bit; // [esp+10h] [ebp+8h]

  v2 = *(bf_read **)(u + 36);
  m_pData = v2->m_pData;
  if ( m_pData != nullptr )
  {
    v4 = (char *)v2->m_pDataIn - (char *)m_pData;
    v5 = 2 * (v2->m_nDataBytes & 3);
    v6 = 32 * (v4 >> 2) - v2->m_nBitsAvail;
    m_nDataBits = v2->m_nDataBits;
    start_bit = v6 + 4 * v5;
    if ( start_bit >= m_nDataBits )
      start_bit = m_nDataBits;
  }
  else
  {
    start_bit = 0;
  }
  v8 = entitylist->GetClientNetworkable(this: entitylist, a2: *(_DWORD *)(u + 24));
  v9 = v8;
  if ( v8 != 0 )
  {
    (*(void (__thiscall **)(int, int))(*(_DWORD *)v8 + 24))(a1: v8, a2: 1);
    v10 = entitylist->GetClientNetworkable(this: entitylist, a2: *(_DWORD *)(u + 24));
    if ( v10 != 0 && (v11 = *(RecvTable **)((*(int (__thiscall **)(int))(*(_DWORD *)v10 + 8))(a1: v10) + 12)) != nullptr )
    {
      v24 = *(_DWORD *)(u + 24);
      v23 = *(bf_read **)(u + 36);
      v12 = (void *)(*(int (__thiscall **)(int))(*(_DWORD *)v9 + 48))(a1: v9);
      RecvTable_Decode(pTable: v11, pStruct: v12, pIn: v23, objectID: v24);
      v13 = *(_DWORD *)(u + 24);
      if ( *(int *)(u + 16448) >= 2048 )
        _Error(a1: "CL_AddPostDataUpdateCall: overflowed u.m_PostDataUpdateCalls");
      *(_DWORD *)(u + 8 * *(_DWORD *)(u + 16448) + 64) = v13;
      *(_DWORD *)(u + 8 * (*(_DWORD *)(u + 16448))++ + 68) = 1;
      *(_DWORD *)(*(_DWORD *)(u + 12) + 4) = *(_DWORD *)(u + 24);
      *(_DWORD *)(*(_DWORD *)(u + 12) + 4 * (*(int *)(u + 24) >> 5) + 16) |= 1 << (*(_DWORD *)(u + 24) & 0x1F);
      v14 = *(bf_read **)(u + 36);
      v15 = v14->m_pData;
      if ( v15 != nullptr )
      {
        v17 = (char *)v14->m_pDataIn - (char *)v15;
        v18 = 2 * (v14->m_nDataBytes & 3);
        v19 = 32 * (v17 >> 2) - v14->m_nBitsAvail;
        v16 = v14->m_nDataBits;
        v20 = v19 + 4 * v18;
        if ( v20 < v16 )
          v16 = v20;
      }
      else
      {
        v16 = 0;
      }
      v21 = v16 - start_bit;
      if ( cl_entityreport.m_pParent != nullptr && cl_entityreport.m_pParent->m_Value.m_nValue != 0 )
        CL_RecordEntityBits(entnum: *(_DWORD *)(u + 24), bitcount: v21);
      v22 = *(_DWORD *)(u + 24);
      if ( v22 >= 1 && v22 <= GetBaseLocalClient()->m_nMaxClients )
      {
        if ( *(_DWORD *)(u + 24) == GetBaseLocalClient()->m_nPlayerSlot + 1 )
          *(_DWORD *)(u + 56) += v21;
        else
          *(_DWORD *)(u + 60) += v21;
      }
    }
    else
    {
      Host_Error(error: "CL_ParseDelta: invalid recv table for ent %d.\n", *(_DWORD *)(u + 24));
    }
  }
  else
  {
    Host_Error(error: "CL_CopyExistingEntity: missing client entity %d.\n", *(_DWORD *)(u + 24));
  }
}

//------------------------------------------------------------------------------
// Address: 0x10085960
// Name: void CL_MarkEntitiesOutOfPVS(class CBitVec<2048> __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CL_MarkEntitiesOutOfPVS(CBitVec<2048> *pvs_flags)
{
  EntityCacheInfo_t *v1; // edi
  int v2; // ecx
  int m_nValue; // eax
  unsigned int v4; // esi
  int v5; // ebx
  int entityMax; // [esp+Ch] [ebp-8h]
  bool bReport; // [esp+13h] [ebp-1h]

  v1 = entitylist->GetClientNetworkableArray(this: entitylist);
  v2 = entitylist->GetHighestEntityIndex(this: entitylist) + 1;
  entityMax = v2;
  if ( cl_entityreport.m_pParent != nullptr )
    m_nValue = cl_entityreport.m_pParent->m_Value.m_nValue;
  else
    m_nValue = 0;
  bReport = m_nValue != 0;
  v4 = 0;
  v5 = 1;
  if ( v2 > 0 )
  {
    do
    {
      if ( v1[v4].m_pNetworkable != nullptr )
      {
        if ( v1[v4].m_bDormant != 0 )
        {
          if ( (v5 & pvs_flags->m_Ints[v4 >> 5]) != 0 )
            v1[v4].m_pNetworkable->NotifyShouldTransmit(this: v1[v4].m_pNetworkable, a2: SHOULDTRANSMIT_START);
        }
        else if ( (v5 & pvs_flags->m_Ints[v4 >> 5]) == 0 )
        {
          v1[v4].m_pNetworkable->NotifyShouldTransmit(this: v1[v4].m_pNetworkable, a2: SHOULDTRANSMIT_END);
          if ( bReport )
            CL_RecordLeavePVS(entnum: v4);
        }
      }
      ++v4;
      v5 = __ROL4__(v5, 1);
    }
    while ( (int)v4 < entityMax );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10085A20
// Name: bool CL_ProcessPacketEntities(class SVC_PacketEntities __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl CL_ProcessPacketEntities(SVC_PacketEntities *entmsg)
{
  CClientState *BaseLocalClient; // eax
  CClientFrame *Frame; // edi
  CClientState *v3; // eax
  int m_nValue; // ebx
  CClientState *v6; // eax
  int (__thiscall *GetHighestEntityIndex)(IClientEntityList *); // eax
  int v8; // ebx
  ClientClass *v9; // eax
  int (__thiscall *v10)(IClientEntityList *); // eax
  int v11; // ebx
  CClientState *v12; // eax
  CClientState *v13; // eax
  int v14; // edx
  bool m_bIsDelta; // al
  int m_nUpdatedEntries; // ecx
  bool m_bUpdateBaseline; // al
  int v18; // edx
  int v19; // ebx
  CClientState *v20; // eax
  CClientState *v21; // eax
  CClientState *v22; // eax
  CClientState *v23; // eax
  CClientState *v24; // eax
  CClientState *v25; // eax
  int v26; // [esp-50h] [ebp-40BCh]
  int m_nDeltaFrom; // [esp-Ch] [ebp-4078h]
  int m_nBaseline; // [esp-Ch] [ebp-4078h]
  BOOL v29; // [esp-8h] [ebp-4074h]
  unsigned int v30; // [esp+0h] [ebp-406Ch]
  int v31; // [esp+4h] [ebp-4068h]
  CEntityReadInfo u; // [esp+8h] [ebp-4064h] BYREF
  void **v33; // [esp+404Ch] [ebp-20h] BYREF
  char v34; // [esp+4050h] [ebp-1Ch]
  int v35; // [esp+4054h] [ebp-18h]
  int m_nServerTick; // [esp+405Ch] [ebp-10h]
  int v37; // [esp+4060h] [ebp-Ch]
  CClientFrame *ClientFrame; // [esp+4064h] [ebp-8h]
  int entnum; // [esp+4068h] [ebp-4h] BYREF

  BaseLocalClient = GetBaseLocalClient();
  Frame = CClientFrameManager::AllocateFrame(this: &BaseLocalClient->CClientFrameManager);
  v3 = GetBaseLocalClient();
  CClientFrame::Init(this: (CNetMessage *)Frame, netchan: (INetChannel *)v3->m_ClockDriftMgr.m_nServerTick);
  m_nValue = 0;
  ClientFrame = nullptr;
  if ( cl_flushentitypacket.m_pParent != nullptr && cl_flushentitypacket.m_pParent->m_Value.m_nValue != 0 )
  {
    CL_FlushEntityPacket(packet: Frame, errorString: "Forced by cvar\n");
    if ( cl_flushentitypacket.m_pParent != nullptr )
      m_nValue = cl_flushentitypacket.m_pParent->m_Value.m_nValue;
    CLoaderMemAlloc::CrtIsValidPointer(
      this: (ConVar *)&cl_flushentitypacket.IConVar,
      value: m_nValue - 1,
      a2: v30,
      a3: v31);
    return 0;
  }
  else
  {
    if ( entmsg->m_bIsDelta )
    {
      if ( GetBaseLocalClient()->m_ClockDriftMgr.m_nServerTick == entmsg->m_nDeltaFrom )
      {
        Host_Error(error: "Update self-referencing, connection dropped.\n");
        return 0;
      }
      m_nDeltaFrom = entmsg->m_nDeltaFrom;
      v6 = GetBaseLocalClient();
      ClientFrame = CClientFrameManager::GetClientFrame(
                      this: &v6->CClientFrameManager,
                      nTick: m_nDeltaFrom,
                      bExact: true);
      if ( ClientFrame == nullptr )
      {
        CL_FlushEntityPacket(packet: Frame, errorString: "Update delta not found.\n");
        return 0;
      }
    }
    else
    {
      entnum = 16737535;
      ConColorMsg(a1: (const struct Color *)&entnum, a2: "Receiving uncompressed update from server\n");
      GetHighestEntityIndex = entitylist->GetHighestEntityIndex;
      entnum = 0;
      if ( GetHighestEntityIndex(this: entitylist) > 0 )
      {
        do
        {
          v8 = entitylist->GetClientNetworkable(this: entitylist, a2: entnum);
          if ( v8 != 0 )
          {
            v9 = (ClientClass *)(*(int (__thiscall **)(int))(*(_DWORD *)v8 + 8))(a1: v8);
            CL_RecordDeleteEntity(entnum, pclass: v9);
            (*(void (__thiscall **)(int))(*(_DWORD *)v8 + 52))(a1: v8);
            (*(void (__thiscall **)(int))(*(_DWORD *)v8 + 4))(a1: v8);
          }
          v10 = entitylist->GetHighestEntityIndex;
          v11 = ++entnum;
        }
        while ( v11 < v10(this: entitylist) );
      }
    }
    ClientDLL_FrameStageNotify(frameStage: FRAME_NET_UPDATE_START);
    g_nPropsDecoded = 0;
    if ( entmsg->m_bUpdateBaseline )
    {
      v29 = entmsg->m_nBaseline == 0;
      m_nBaseline = entmsg->m_nBaseline;
      v12 = GetBaseLocalClient();
      CBaseClientState::CopyEntityBaseline(this: v12, iFrom: m_nBaseline, iTo: v29);
      entnum = (int)GetBaseLocalClient()->m_NetChannel;
      v13 = GetBaseLocalClient();
      v14 = entmsg->m_nBaseline;
      m_nServerTick = v13->m_ClockDriftMgr.m_nServerTick;
      v37 = v14;
      v34 = 1;
      v35 = 0;
      v33 = &CLC_BaselineAck::`vftable';
      (*(void (__thiscall **)(int, void ***, int, _DWORD))(*(_DWORD *)entnum + 164))(a1: entnum, a2: &v33, a3: 1, a4: 0);
    }
    memset(&u.m_nOldEntity, 255, 12);
    m_bIsDelta = entmsg->m_bIsDelta;
    u.m_pBuf = &entmsg->m_DataIn;
    m_nUpdatedEntries = entmsg->m_nUpdatedEntries;
    u.m_bAsDelta = m_bIsDelta;
    m_bUpdateBaseline = entmsg->m_bUpdateBaseline;
    u.m_pFrom = ClientFrame;
    v18 = entmsg->m_nBaseline;
    u.m_nHeaderCount = m_nUpdatedEntries;
    u.m_bUpdateBaselines = m_bUpdateBaseline;
    u.__vftable = (CEntityReadInfo_vtbl *)&CEntityReadInfo::`vftable';
    u.m_nPostDataUpdateCalls = 0;
    u.m_nLocalPlayerBits = 0;
    u.m_nOtherPlayerBits = 0;
    u.m_UpdateType = PreserveEnt;
    u.m_pTo = Frame;
    u.m_nBaseline = v18;
    v19 = splitscreen->SetActiveSplitScreenPlayerSlot(this: splitscreen, a2: 0);
    LOBYTE(ClientFrame) = splitscreen->SetLocalPlayerIsResolvable(
                            this: splitscreen,
                            a2: "cl_ents_parse.cpp",
                            a3: 651,
                            a4: false);
    v20 = GetBaseLocalClient();
    v20->ReadPacketEntities(this: v20, a2: &u);
    splitscreen->SetActiveSplitScreenPlayerSlot(this: splitscreen, a2: v19);
    splitscreen->SetLocalPlayerIsResolvable(this: splitscreen, a2: "cl_ents_parse.cpp", a3: 656, a4: (bool)ClientFrame);
    ClientDLL_FrameStageNotify(frameStage: FRAME_NET_UPDATE_POSTDATAUPDATE_START);
    CL_CallPostDataUpdates(&u);
    ClientDLL_FrameStageNotify(frameStage: FRAME_NET_UPDATE_POSTDATAUPDATE_END);
    CL_MarkEntitiesOutOfPVS(pvs_flags: &Frame->transmit_entity);
    v21 = GetBaseLocalClient();
    v21->m_NetChannel->UpdateMessageStats(this: v21->m_NetChannel, a2: 1, a3: u.m_nLocalPlayerBits);
    v22 = GetBaseLocalClient();
    v22->m_NetChannel->UpdateMessageStats(this: v22->m_NetChannel, a2: 2, a3: u.m_nOtherPlayerBits);
    v23 = GetBaseLocalClient();
    v23->m_NetChannel->UpdateMessageStats(
      this: v23->m_NetChannel,
      a2: 3,
      a3: -(u.m_nLocalPlayerBits + u.m_nOtherPlayerBits));
    v26 = entmsg->m_nDeltaFrom;
    v24 = GetBaseLocalClient();
    CClientFrameManager::DeleteClientFrames(this: &v24->CClientFrameManager, nTick: v26);
    v25 = GetBaseLocalClient();
    if ( CClientFrameManager::AddClientFrame(this: &v25->CClientFrameManager, frame: Frame) > 128 )
      _DevMsg(a1: 1, a2: "CL_ProcessPacketEntities: frame window too big (>%i)\n", 128);
    ClientDLL_FrameStageNotify(frameStage: FRAME_NET_UPDATE_END);
    return 1;
  }
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x10084DC0
// Name: void CL_DeleteDLLEntity(int,char __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CL_DeleteDLLEntity(int iEnt, char *reason, bool bOnRecreatingAllEntities)
{
  int v3; // esi
  ClientClass *v4; // eax

  v3 = entitylist->GetClientNetworkable(this: entitylist, a2: iEnt);
  if ( v3 != 0 )
  {
    v4 = (ClientClass *)(*(int (__thiscall **)(int))(*(_DWORD *)v3 + 8))(a1: v3);
    CL_RecordDeleteEntity(entnum: iEnt, pclass: v4);
    if ( bOnRecreatingAllEntities )
      (*(void (__thiscall **)(int))(*(_DWORD *)v3 + 52))(a1: v3);
    (*(void (__thiscall **)(int))(*(_DWORD *)v3 + 4))(a1: v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10084E10
// Name: CL_AddPostDataUpdateCall
// Source: json
//------------------------------------------------------------------------------
void __usercall CL_AddPostDataUpdateCall(CEntityReadInfo *u@<esi>, int iEnt, DataUpdateType_t updateType)
{
  if ( u->m_nPostDataUpdateCalls >= 2048 )
    _Error(a1: "CL_AddPostDataUpdateCall: overflowed u.m_PostDataUpdateCalls");
  u->m_PostDataUpdateCalls[u->m_nPostDataUpdateCalls].m_iEnt = iEnt;
  u->m_PostDataUpdateCalls[u->m_nPostDataUpdateCalls++].m_UpdateType = updateType;
}

//------------------------------------------------------------------------------
// Address: 0x10084E50
// Name: void CL_FlushEntityPacket(class CClientFrame __near *,char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
void CL_FlushEntityPacket(CClientFrame *packet, const char *errorString, ...)
{
  CClientState *BaseLocalClient; // eax
  char str[2048]; // [esp+0h] [ebp-818h] BYREF
  con_nprint_s np; // [esp+800h] [ebp-18h] BYREF
  va_list params; // [esp+828h] [ebp+10h] BYREF

  va_start(params, errorString);
  V_vsnprintf(pDest: str, maxLen: 2048, pFormat: errorString, params);
  ConMsg(a1: "%s", str);
  np.time_to_live = 1.0;
  np.color[0] = 1.0;
  np.color[1] = 0.2;
  np.fixed_width_font = false;
  np.index = 0;
  np.color[2] = 0.0;
  Con_NXPrintf(info: &np, fmt: "WARNING:  CL_FlushEntityPacket, %s", str);
  BaseLocalClient = GetBaseLocalClient();
  CClientFrameManager::DeleteUnusedClientFrame(this: &BaseLocalClient->CClientFrameManager, pFrameToDelete: packet);
}

//------------------------------------------------------------------------------
// Address: 0x10084EF0
// Name: class IClientNetworkable __near * CL_CreateDLLEntity(int,int,int)
// Source: json
//------------------------------------------------------------------------------
IClientNetworkable *__cdecl CL_CreateDLLEntity(unsigned int iEnt, int iClass, int iSerialNum)
{
  ClientClass *m_pClientClass; // esi
  IEngineVGuiInternal *v4; // eax

  m_pClientClass = GetBaseLocalClient()->m_pServerClasses[iClass].m_pClientClass;
  if ( m_pClientClass == nullptr )
    return nullptr;
  CL_RecordAddEntity(entnum: iEnt);
  if ( GetBaseLocalClient()->m_nSignonState != 6 )
  {
    _COM_TimestampedLog(a1: "cl:  create '%s'", m_pClientClass->m_pNetworkName);
    v4 = EngineVGui();
    v4->UpdateProgressBar(this: v4, a2: PROGRESS_CREATEENTITIES, a3: true);
  }
  return m_pClientClass->m_pCreateFn(a1: iEnt, a2: iSerialNum);
}

//------------------------------------------------------------------------------
// Address: 0x10084F60
// Name: CL_CallPostDataUpdates
// Source: json
//------------------------------------------------------------------------------
void __cdecl CL_CallPostDataUpdates(CEntityReadInfo *u)
{
  IMDLCache *v1; // edi
  int v2; // ebx
  int *p_m_iEnt; // esi
  int v4; // edi
  bool bSaveResolvable; // [esp+Ch] [ebp-Ch]
  int saveSlot; // [esp+10h] [ebp-8h]
  IMDLCache *cacheCriticalSection; // [esp+14h] [ebp-4h]

  v1 = g_pMDLCache;
  cacheCriticalSection = g_pMDLCache;
  g_pMDLCache->BeginLock(this: g_pMDLCache);
  saveSlot = splitscreen->SetActiveSplitScreenPlayerSlot(this: splitscreen, a2: 0);
  v2 = 0;
  bSaveResolvable = splitscreen->SetLocalPlayerIsResolvable(
                      this: splitscreen,
                      a2: "..\\engine\\cl_ents_parse.cpp",
                      a3: 549,
                      a4: false);
  if ( u->m_nPostDataUpdateCalls > 0 )
  {
    p_m_iEnt = &u->m_PostDataUpdateCalls[0].m_iEnt;
    do
    {
      v4 = entitylist->GetClientNetworkable(this: entitylist, a2: *p_m_iEnt);
      if ( v4 == 0 )
        _Error(a1: "CL_CallPostDataUpdates: missing ent %d", *p_m_iEnt);
      (*(void (__thiscall **)(int, int))(*(_DWORD *)v4 + 28))(a1: v4, a2: p_m_iEnt[1]);
      ++v2;
      p_m_iEnt += 2;
    }
    while ( v2 < u->m_nPostDataUpdateCalls );
    v1 = cacheCriticalSection;
  }
  splitscreen->SetActiveSplitScreenPlayerSlot(this: splitscreen, a2: saveSlot);
  splitscreen->SetLocalPlayerIsResolvable(
    this: splitscreen,
    a2: "..\\engine\\cl_ents_parse.cpp",
    a3: 562,
    a4: bSaveResolvable);
  v1->EndLock(this: v1);
}

//------------------------------------------------------------------------------
// Address: 0x10085050
// Name: void CL_PreprocessEntities(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CL_PreprocessEntities(CDebugOverlay *a1)
{
  bool IsMultiplayer; // bl
  int *p_command_ack; // esi
  bool v3; // al
  int *v4; // esi
  int v5; // esi
  int m_nServerTick; // edi
  CClientState *BaseLocalClient; // eax
  IPrediction_vtbl *v8; // ebx
  CClientState *v9; // eax
  int v10; // [esp-4h] [ebp-10h]

  IsMultiplayer = NET_IsMultiplayer();
  p_command_ack = &GetBaseLocalClient()->command_ack;
  v3 = GetBaseLocalClient()->lastoutgoingcommand == *p_command_ack;
  if ( IsMultiplayer || v3 )
    CL_RunPrediction(reason: PREDICTION_SIMULATION_RESULTS_ARRIVING_ON_SEND_FRAME);
  v4 = &GetBaseLocalClient()->command_ack;
  v5 = *v4 - GetBaseLocalClient()->last_command_ack;
  m_nServerTick = GetBaseLocalClient()->m_ClockDriftMgr.m_nServerTick;
  BaseLocalClient = GetBaseLocalClient();
  v8 = g_pClientSidePrediction->__vftable;
  v10 = m_nServerTick - BaseLocalClient->last_server_tick;
  v9 = GetBaseLocalClient();
  v8->PreEntityPacketReceived(this: g_pClientSidePrediction, a2: v5, a3: v9->m_nCurrentSequence, a4: v10);
  CDebugOverlay::PurgeServerOverlays(this: a1);
}

//------------------------------------------------------------------------------
// Address: 0x100850F0
// Name: void CL_CopyNewEntity(class CEntityReadInfo __near &,int,int)
// Source: json
//------------------------------------------------------------------------------
void __usercall CL_CopyNewEntity(int a1@<edi>, CEntityReadInfo *u, int iClass, int iSerialNum)
{
  int m_nNewEntity; // eax
  IClientNetworkable *DLLEntity; // edi
  int v7; // eax
  int v8; // eax
  int v9; // edi
  ClientClass *v10; // eax
  CClientState *BaseLocalClient; // eax
  char v12; // bl
  bf_read *m_pBuf; // eax
  const unsigned int *m_pData; // ecx
  int v15; // edx
  int v16; // ecx
  int v17; // edx
  int m_nDataBits; // eax
  IClientNetworkable_vtbl *v19; // edx
  CClientState *v20; // eax
  PackedEntity *EntityBaseline; // eax
  int v22; // eax
  CClientState *v23; // eax
  int v24; // eax
  RecvTable *v25; // ebx
  CClientState *v26; // eax
  bf_read *v27; // edx
  void *v28; // eax
  void *v29; // eax
  unsigned int *v30; // eax
  bf_read *v31; // eax
  const unsigned int *v32; // ecx
  int v33; // eax
  int v34; // edx
  int v35; // ecx
  int v36; // edx
  int v37; // ecx
  int v38; // ebx
  int v39; // edi
  BOOL v40; // [esp-1Ch] [ebp-406Ch]
  ClientClass *v41; // [esp-18h] [ebp-4068h]
  int v42; // [esp-14h] [ebp-4064h]
  bf_read *v43; // [esp-10h] [ebp-4060h]
  int v44; // [esp-Ch] [ebp-405Ch]
  int m_nBaseline; // [esp-Ch] [ebp-405Ch]
  unsigned int v46; // [esp-Ch] [ebp-405Ch]
  int v47; // [esp-Ch] [ebp-405Ch]
  int v48; // [esp-Ch] [ebp-405Ch]
  int v50; // [esp-8h] [ebp-4058h]
  char packedData[16384]; // [esp+4h] [ebp-404Ch] BYREF
  bf_write pOut; // [esp+4004h] [ebp-4Ch] BYREF
  CBitRead v53; // [esp+401Ch] [ebp-34h] BYREF
  DataUpdateType_t updateType; // [esp+4040h] [ebp-10h]
  ClientClass *pClientClass; // [esp+4044h] [ebp-Ch]
  void *pData; // [esp+4048h] [ebp-8h] BYREF
  int pDatalen; // [esp+404Ch] [ebp-4h] BYREF
  unsigned int entnum; // [esp+4058h] [ebp+8h]
  int entnuma; // [esp+4058h] [ebp+8h]

  m_nNewEntity = u->m_nNewEntity;
  if ( m_nNewEntity >= 2048 )
  {
    Host_Error(error: "CL_CopyNewEntity: m_nNewEntity >= MAX_EDICTS");
    return;
  }
  DLLEntity = (IClientNetworkable *)entitylist->GetClientNetworkable(this: entitylist, a2: m_nNewEntity);
  if ( iClass >= GetBaseLocalClient()->m_nServerClasses )
  {
    Host_Error(error: "CL_CopyNewEntity: invalid class index (%d).\n", iClass);
    return;
  }
  pClientClass = GetBaseLocalClient()->m_pServerClasses[iClass].m_pClientClass;
  if ( DLLEntity != nullptr )
  {
    v7 = DLLEntity->GetIClientUnknown(this: DLLEntity);
    if ( *(unsigned __int16 *)((*(int (__thiscall **)(int))(*(_DWORD *)v7 + 8))(a1: v7) + 2) == iSerialNum )
    {
      v12 = 0;
      goto LABEL_13;
    }
    entnum = u->m_nNewEntity;
    v8 = entitylist->GetClientNetworkable(this: entitylist, a2: u->m_nNewEntity);
    v9 = v8;
    if ( v8 != 0 )
    {
      v10 = (ClientClass *)(*(int (__thiscall **)(int))(*(_DWORD *)v8 + 8))(a1: v8);
      CL_RecordDeleteEntity(entnum, pclass: v10);
      (*(void (__thiscall **)(int))(*(_DWORD *)v9 + 4))(a1: v9);
    }
  }
  DLLEntity = CL_CreateDLLEntity(iEnt: u->m_nNewEntity, iClass, iSerialNum);
  if ( DLLEntity == nullptr )
  {
    v44 = u->m_nNewEntity;
    BaseLocalClient = GetBaseLocalClient();
    Host_Error(
      error: "CL_ParsePacketEntities:  Error creating entity %s(%i)\n",
      BaseLocalClient->m_pServerClasses[iClass].m_pClientClass->m_pNetworkName,
      v44);
    return;
  }
  v12 = 1;
LABEL_13:
  m_pBuf = u->m_pBuf;
  m_pData = m_pBuf->m_pData;
  if ( m_pData != nullptr )
  {
    v15 = (char *)m_pBuf->m_pDataIn - (char *)m_pData;
    v16 = 2 * (m_pBuf->m_nDataBytes & 3);
    v17 = 32 * (v15 >> 2) - m_pBuf->m_nBitsAvail;
    m_nDataBits = m_pBuf->m_nDataBits;
    entnuma = v17 + 4 * v16;
    if ( entnuma >= m_nDataBits )
      entnuma = m_nDataBits;
  }
  else
  {
    entnuma = 0;
  }
  v19 = DLLEntity->__vftable;
  updateType = v12 == 0;
  ((void (__thiscall *)(IClientNetworkable *, DataUpdateType_t, int))v19->PreDataUpdate)(
    a1: DLLEntity,
    a2: updateType,
    a3: a1);
  if ( u->m_bAsDelta
    && (v50 = u->m_nNewEntity,
        m_nBaseline = u->m_nBaseline,
        v20 = GetBaseLocalClient(),
        (EntityBaseline = CBaseClientState::GetEntityBaseline(this: v20, iBaseline: m_nBaseline, nEntityIndex: v50)) != nullptr)
    && EntityBaseline->m_pClientClass == pClientClass )
  {
    pData = EntityBaseline->m_pData;
    v22 = EntityBaseline->m_nBits & 0x7FFFFFFF;
  }
  else
  {
    v23 = GetBaseLocalClient();
    if ( !CBaseClientState::GetClassBaseline(this: v23, iClass, (const void **)&pData, &pDatalen) )
      _Error(a1: "CL_CopyNewEntity: GetClassBaseline(%d) failed.", iClass);
    v22 = 8 * pDatalen;
  }
  pDatalen = v22;
  v53.m_bOverflow = false;
  v53.m_nDataBits = -1;
  v53.m_nDataBytes = 0;
  v53.m_pDebugName = "CL_CopyNewEntity->fromBuf";
  CBitRead::StartReading(this: &v53, pData, nBytes: (v22 + 7) >> 3, iStartBit: 0, nBits: v22);
  v24 = entitylist->GetClientNetworkable(this: entitylist, a2: u->m_nNewEntity);
  if ( v24 != 0 && (v25 = *(RecvTable **)((*(int (__thiscall **)(int))(*(_DWORD *)v24 + 8))(a1: v24) + 12)) != nullptr )
  {
    if ( u->m_bUpdateBaselines )
    {
      bf_write::bf_write(
        this: &pOut,
        pDebugName: "CL_CopyNewEntity->newBuf",
        pData: packedData,
        nBytes: 0x4000,
        nBits: -1);
      RecvTable_MergeDeltas(
        pTable: v25,
        pOldState: (bf_read *)&v53,
        pNewState: u->m_pBuf,
        &pOut,
        objectID: u->m_nNewEntity,
        bDebugWatchInfo: false,
        pChangedProps: nullptr);
      v46 = (pOut.m_iCurBit + 7) >> 3;
      v42 = u->m_nNewEntity;
      v41 = pClientClass;
      v40 = u->m_nBaseline == 0;
      v26 = GetBaseLocalClient();
      CBaseClientState::SetEntityBaseline(
        this: v26,
        iBaseline: v40,
        pClientClass: v41,
        index: v42,
        packedData,
        length: v46);
      CBitRead::StartReading(this: &v53, pData: packedData, nBytes: (pOut.m_iCurBit + 7) >> 3, iStartBit: 0, nBits: -1);
      v27 = (bf_read *)&v53;
    }
    else
    {
      v47 = u->m_nNewEntity;
      v28 = DLLEntity->GetDataTableBasePtr(this: DLLEntity);
      RecvTable_Decode(pTable: v25, pStruct: v28, pIn: (bf_read *)&v53, objectID: v47);
      v27 = u->m_pBuf;
    }
    v48 = u->m_nNewEntity;
    v43 = v27;
    v29 = DLLEntity->GetDataTableBasePtr(this: DLLEntity);
    RecvTable_Decode(pTable: v25, pStruct: v29, pIn: v43, objectID: v48);
  }
  else
  {
    Host_Error(error: "CL_ParseDelta: invalid recv table for ent %d.\n", u->m_nNewEntity);
  }
  CL_AddPostDataUpdateCall(u, iEnt: u->m_nNewEntity, updateType);
  u->m_pTo->last_entity = u->m_nNewEntity;
  v30 = &u->m_pTo->transmit_entity.m_Ints[u->m_nNewEntity >> 5];
  *v30 |= 1 << (u->m_nNewEntity & 0x1F);
  v31 = u->m_pBuf;
  v32 = v31->m_pData;
  if ( v32 != nullptr )
  {
    v34 = (char *)v31->m_pDataIn - (char *)v32;
    v35 = 2 * (v31->m_nDataBytes & 3);
    v36 = 32 * (v34 >> 2) - v31->m_nBitsAvail;
    v33 = v31->m_nDataBits;
    v37 = v36 + 4 * v35;
    if ( v37 < v33 )
      v33 = v37;
  }
  else
  {
    v33 = 0;
  }
  v38 = v33 - entnuma;
  if ( cl_entityreport.m_pParent != nullptr && cl_entityreport.m_pParent->m_Value.m_nValue != 0 )
    CL_RecordEntityBits(entnum: u->m_nNewEntity, bitcount: v38);
  v39 = u->m_nNewEntity;
  if ( v39 >= 1 && v39 <= GetBaseLocalClient()->m_nMaxClients )
  {
    if ( u->m_nNewEntity == GetBaseLocalClient()->m_nPlayerSlot + 1 )
      u->m_nLocalPlayerBits += v38;
    else
      u->m_nOtherPlayerBits += v38;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100854C0
// Name: void CL_CopyExistingEntity(class CEntityReadInfo __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CL_CopyExistingEntity(int u)
{
  bf_read *v2; // eax
  const unsigned int *m_pData; // ecx
  int v4; // edx
  int v5; // ecx
  int v6; // edx
  int m_nDataBits; // eax
  int v8; // eax
  int v9; // edi
  int v10; // eax
  RecvTable *v11; // ebx
  void *v12; // eax
  int v13; // edi
  bf_read *v14; // eax
  const unsigned int *v15; // ecx
  int v16; // eax
  int v17; // edx
  int v18; // ecx
  int v19; // edx
  int v20; // ecx
  int v21; // ebx
  int v22; // edi
  bf_read *v23; // [esp-Ch] [ebp-14h]
  int v24; // [esp-8h] [ebp-10h]
  int start_bit; // [esp+10h] [ebp+8h]

  v2 = *(bf_read **)(u + 36);
  m_pData = v2->m_pData;
  if ( m_pData != nullptr )
  {
    v4 = (char *)v2->m_pDataIn - (char *)m_pData;
    v5 = 2 * (v2->m_nDataBytes & 3);
    v6 = 32 * (v4 >> 2) - v2->m_nBitsAvail;
    m_nDataBits = v2->m_nDataBits;
    start_bit = v6 + 4 * v5;
    if ( start_bit >= m_nDataBits )
      start_bit = m_nDataBits;
  }
  else
  {
    start_bit = 0;
  }
  v8 = entitylist->GetClientNetworkable(this: entitylist, a2: *(_DWORD *)(u + 24));
  v9 = v8;
  if ( v8 != 0 )
  {
    (*(void (__thiscall **)(int, int))(*(_DWORD *)v8 + 24))(a1: v8, a2: 1);
    v10 = entitylist->GetClientNetworkable(this: entitylist, a2: *(_DWORD *)(u + 24));
    if ( v10 != 0 && (v11 = *(RecvTable **)((*(int (__thiscall **)(int))(*(_DWORD *)v10 + 8))(a1: v10) + 12)) != nullptr )
    {
      v24 = *(_DWORD *)(u + 24);
      v23 = *(bf_read **)(u + 36);
      v12 = (void *)(*(int (__thiscall **)(int))(*(_DWORD *)v9 + 48))(a1: v9);
      RecvTable_Decode(pTable: v11, pStruct: v12, pIn: v23, objectID: v24);
      v13 = *(_DWORD *)(u + 24);
      if ( *(int *)(u + 16448) >= 2048 )
        _Error(a1: "CL_AddPostDataUpdateCall: overflowed u.m_PostDataUpdateCalls");
      *(_DWORD *)(u + 8 * *(_DWORD *)(u + 16448) + 64) = v13;
      *(_DWORD *)(u + 8 * (*(_DWORD *)(u + 16448))++ + 68) = 1;
      *(_DWORD *)(*(_DWORD *)(u + 12) + 4) = *(_DWORD *)(u + 24);
      *(_DWORD *)(*(_DWORD *)(u + 12) + 4 * (*(int *)(u + 24) >> 5) + 16) |= 1 << (*(_DWORD *)(u + 24) & 0x1F);
      v14 = *(bf_read **)(u + 36);
      v15 = v14->m_pData;
      if ( v15 != nullptr )
      {
        v17 = (char *)v14->m_pDataIn - (char *)v15;
        v18 = 2 * (v14->m_nDataBytes & 3);
        v19 = 32 * (v17 >> 2) - v14->m_nBitsAvail;
        v16 = v14->m_nDataBits;
        v20 = v19 + 4 * v18;
        if ( v20 < v16 )
          v16 = v20;
      }
      else
      {
        v16 = 0;
      }
      v21 = v16 - start_bit;
      if ( cl_entityreport.m_pParent != nullptr && cl_entityreport.m_pParent->m_Value.m_nValue != 0 )
        CL_RecordEntityBits(entnum: *(_DWORD *)(u + 24), bitcount: v21);
      v22 = *(_DWORD *)(u + 24);
      if ( v22 >= 1 && v22 <= GetBaseLocalClient()->m_nMaxClients )
      {
        if ( *(_DWORD *)(u + 24) == GetBaseLocalClient()->m_nPlayerSlot + 1 )
          *(_DWORD *)(u + 56) += v21;
        else
          *(_DWORD *)(u + 60) += v21;
      }
    }
    else
    {
      Host_Error(error: "CL_ParseDelta: invalid recv table for ent %d.\n", *(_DWORD *)(u + 24));
    }
  }
  else
  {
    Host_Error(error: "CL_CopyExistingEntity: missing client entity %d.\n", *(_DWORD *)(u + 24));
  }
}

//------------------------------------------------------------------------------
// Address: 0x10085680
// Name: void CL_MarkEntitiesOutOfPVS(class CBitVec<2048> __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CL_MarkEntitiesOutOfPVS(CBitVec<2048> *pvs_flags)
{
  EntityCacheInfo_t *v1; // edi
  int v2; // ecx
  int m_nValue; // eax
  unsigned int v4; // esi
  int v5; // ebx
  int entityMax; // [esp+Ch] [ebp-8h]
  bool bReport; // [esp+13h] [ebp-1h]

  v1 = entitylist->GetClientNetworkableArray(this: entitylist);
  v2 = entitylist->GetHighestEntityIndex(this: entitylist) + 1;
  entityMax = v2;
  if ( cl_entityreport.m_pParent != nullptr )
    m_nValue = cl_entityreport.m_pParent->m_Value.m_nValue;
  else
    m_nValue = 0;
  bReport = m_nValue != 0;
  v4 = 0;
  v5 = 1;
  if ( v2 > 0 )
  {
    do
    {
      if ( v1[v4].m_pNetworkable != nullptr )
      {
        if ( v1[v4].m_bDormant != 0 )
        {
          if ( (v5 & pvs_flags->m_Ints[v4 >> 5]) != 0 )
            v1[v4].m_pNetworkable->NotifyShouldTransmit(this: v1[v4].m_pNetworkable, a2: SHOULDTRANSMIT_START);
        }
        else if ( (v5 & pvs_flags->m_Ints[v4 >> 5]) == 0 )
        {
          v1[v4].m_pNetworkable->NotifyShouldTransmit(this: v1[v4].m_pNetworkable, a2: SHOULDTRANSMIT_END);
          if ( bReport )
            CL_RecordLeavePVS(entnum: v4);
        }
      }
      ++v4;
      v5 = __ROL4__(v5, 1);
    }
    while ( (int)v4 < entityMax );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10085740
// Name: bool CL_ProcessPacketEntities(class SVC_PacketEntities __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl CL_ProcessPacketEntities(SVC_PacketEntities *entmsg)
{
  CClientState *BaseLocalClient; // eax
  CClientFrame *Frame; // edi
  CClientState *v3; // eax
  int m_nValue; // ebx
  CClientState *v6; // eax
  int (__thiscall *GetHighestEntityIndex)(IClientEntityList *); // eax
  int v8; // ebx
  ClientClass *v9; // eax
  int (__thiscall *v10)(IClientEntityList *); // eax
  int v11; // ebx
  CClientState *v12; // eax
  CClientState *v13; // eax
  int v14; // edx
  bool m_bIsDelta; // al
  int m_nUpdatedEntries; // ecx
  bool m_bUpdateBaseline; // al
  int v18; // edx
  int v19; // ebx
  CClientState *v20; // eax
  CClientState *v21; // eax
  CClientState *v22; // eax
  CClientState *v23; // eax
  CClientState *v24; // eax
  CClientState *v25; // eax
  int v26; // [esp-50h] [ebp-40BCh]
  int m_nDeltaFrom; // [esp-Ch] [ebp-4078h]
  int m_nBaseline; // [esp-Ch] [ebp-4078h]
  BOOL v29; // [esp-8h] [ebp-4074h]
  CEntityReadInfo u; // [esp+8h] [ebp-4064h] BYREF
  void **v31; // [esp+404Ch] [ebp-20h] BYREF
  char v32; // [esp+4050h] [ebp-1Ch]
  int v33; // [esp+4054h] [ebp-18h]
  int m_nServerTick; // [esp+405Ch] [ebp-10h]
  int v35; // [esp+4060h] [ebp-Ch]
  CClientFrame *ClientFrame; // [esp+4064h] [ebp-8h]
  int entnum; // [esp+4068h] [ebp-4h] BYREF

  BaseLocalClient = GetBaseLocalClient();
  Frame = CClientFrameManager::AllocateFrame(this: &BaseLocalClient->CClientFrameManager);
  v3 = GetBaseLocalClient();
  CClientFrame::Init(this: (CNetMessage *)Frame, netchan: (INetChannel *)v3->m_ClockDriftMgr.m_nServerTick);
  m_nValue = 0;
  ClientFrame = nullptr;
  if ( cl_flushentitypacket.m_pParent != nullptr && cl_flushentitypacket.m_pParent->m_Value.m_nValue != 0 )
  {
    CL_FlushEntityPacket(packet: Frame, errorString: "Forced by cvar\n");
    if ( cl_flushentitypacket.m_pParent != nullptr )
      m_nValue = cl_flushentitypacket.m_pParent->m_Value.m_nValue;
    CLoaderMemAlloc::CrtIsValidPointer(this: (ConVar *)&cl_flushentitypacket.IConVar, value: m_nValue - 1);
    return 0;
  }
  else
  {
    if ( entmsg->m_bIsDelta )
    {
      if ( GetBaseLocalClient()->m_ClockDriftMgr.m_nServerTick == entmsg->m_nDeltaFrom )
      {
        Host_Error(error: "Update self-referencing, connection dropped.\n");
        return 0;
      }
      m_nDeltaFrom = entmsg->m_nDeltaFrom;
      v6 = GetBaseLocalClient();
      ClientFrame = CClientFrameManager::GetClientFrame(
                      this: &v6->CClientFrameManager,
                      nTick: m_nDeltaFrom,
                      bExact: true);
      if ( ClientFrame == nullptr )
      {
        CL_FlushEntityPacket(packet: Frame, errorString: "Update delta not found.\n");
        return 0;
      }
    }
    else
    {
      entnum = 16737535;
      ConColorMsg(a1: (const struct Color *)&entnum, a2: "Receiving uncompressed update from server\n");
      GetHighestEntityIndex = entitylist->GetHighestEntityIndex;
      entnum = 0;
      if ( GetHighestEntityIndex(this: entitylist) > 0 )
      {
        do
        {
          v8 = entitylist->GetClientNetworkable(this: entitylist, a2: entnum);
          if ( v8 != 0 )
          {
            v9 = (ClientClass *)(*(int (__thiscall **)(int))(*(_DWORD *)v8 + 8))(a1: v8);
            CL_RecordDeleteEntity(entnum, pclass: v9);
            (*(void (__thiscall **)(int))(*(_DWORD *)v8 + 52))(a1: v8);
            (*(void (__thiscall **)(int))(*(_DWORD *)v8 + 4))(a1: v8);
          }
          v10 = entitylist->GetHighestEntityIndex;
          v11 = ++entnum;
        }
        while ( v11 < v10(this: entitylist) );
      }
    }
    ClientDLL_FrameStageNotify(frameStage: FRAME_NET_UPDATE_START);
    g_nPropsDecoded = 0;
    if ( entmsg->m_bUpdateBaseline )
    {
      v29 = entmsg->m_nBaseline == 0;
      m_nBaseline = entmsg->m_nBaseline;
      v12 = GetBaseLocalClient();
      CBaseClientState::CopyEntityBaseline(this: v12, iFrom: m_nBaseline, iTo: v29);
      entnum = (int)GetBaseLocalClient()->m_NetChannel;
      v13 = GetBaseLocalClient();
      v14 = entmsg->m_nBaseline;
      m_nServerTick = v13->m_ClockDriftMgr.m_nServerTick;
      v35 = v14;
      v32 = 1;
      v33 = 0;
      v31 = &CLC_BaselineAck::`vftable';
      (*(void (__thiscall **)(int, void ***, int, _DWORD))(*(_DWORD *)entnum + 164))(a1: entnum, a2: &v31, a3: 1, a4: 0);
    }
    memset(&u.m_nOldEntity, 255, 12);
    m_bIsDelta = entmsg->m_bIsDelta;
    u.m_pBuf = &entmsg->m_DataIn;
    m_nUpdatedEntries = entmsg->m_nUpdatedEntries;
    u.m_bAsDelta = m_bIsDelta;
    m_bUpdateBaseline = entmsg->m_bUpdateBaseline;
    u.m_pFrom = ClientFrame;
    v18 = entmsg->m_nBaseline;
    u.m_nHeaderCount = m_nUpdatedEntries;
    u.m_bUpdateBaselines = m_bUpdateBaseline;
    u.__vftable = (CEntityReadInfo_vtbl *)&CEntityReadInfo::`vftable';
    u.m_nPostDataUpdateCalls = 0;
    u.m_nLocalPlayerBits = 0;
    u.m_nOtherPlayerBits = 0;
    u.m_UpdateType = PreserveEnt;
    u.m_pTo = Frame;
    u.m_nBaseline = v18;
    v19 = splitscreen->SetActiveSplitScreenPlayerSlot(this: splitscreen, a2: 0);
    LOBYTE(ClientFrame) = splitscreen->SetLocalPlayerIsResolvable(
                            this: splitscreen,
                            a2: "..\\engine\\cl_ents_parse.cpp",
                            a3: 651,
                            a4: false);
    v20 = GetBaseLocalClient();
    v20->ReadPacketEntities(this: v20, a2: &u);
    splitscreen->SetActiveSplitScreenPlayerSlot(this: splitscreen, a2: v19);
    splitscreen->SetLocalPlayerIsResolvable(
      this: splitscreen,
      a2: "..\\engine\\cl_ents_parse.cpp",
      a3: 656,
      a4: (bool)ClientFrame);
    ClientDLL_FrameStageNotify(frameStage: FRAME_NET_UPDATE_POSTDATAUPDATE_START);
    CL_CallPostDataUpdates(&u);
    ClientDLL_FrameStageNotify(frameStage: FRAME_NET_UPDATE_POSTDATAUPDATE_END);
    CL_MarkEntitiesOutOfPVS(pvs_flags: &Frame->transmit_entity);
    v21 = GetBaseLocalClient();
    v21->m_NetChannel->UpdateMessageStats(this: v21->m_NetChannel, a2: 1, a3: u.m_nLocalPlayerBits);
    v22 = GetBaseLocalClient();
    v22->m_NetChannel->UpdateMessageStats(this: v22->m_NetChannel, a2: 2, a3: u.m_nOtherPlayerBits);
    v23 = GetBaseLocalClient();
    v23->m_NetChannel->UpdateMessageStats(
      this: v23->m_NetChannel,
      a2: 3,
      a3: -(u.m_nLocalPlayerBits + u.m_nOtherPlayerBits));
    v26 = entmsg->m_nDeltaFrom;
    v24 = GetBaseLocalClient();
    CClientFrameManager::DeleteClientFrames(this: &v24->CClientFrameManager, nTick: v26);
    v25 = GetBaseLocalClient();
    if ( CClientFrameManager::AddClientFrame(this: &v25->CClientFrameManager, frame: Frame) > 128 )
      _DevMsg(a1: 1, a2: "CL_ProcessPacketEntities: frame window too big (>%i)\n", 128);
    ClientDLL_FrameStageNotify(frameStage: FRAME_NET_UPDATE_END);
    return 1;
  }
}

} // namespace engine_xlsp
