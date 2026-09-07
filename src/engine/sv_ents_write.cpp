// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: engine/sv_ents_write.cpp
// Functions: 8
// ============================================================

#include "engine\sv_ents_write.h"

//------------------------------------------------------------------------------
// Address: 0x1011CF20
// Name: SV_NeedsExplicitCreate
// Source: json
//------------------------------------------------------------------------------
bool __fastcall SV_NeedsExplicitCreate(int a1, CEntityWriteInfo *u)
{
  bool result; // al
  int m_nNewEntity; // eax
  CFrameSnapshot *m_pFromSnapshot; // ecx
  CFrameSnapshotEntry *m_pEntities; // ecx
  unsigned int v6; // eax

  result = false;
  if ( u->m_bAsDelta )
  {
    m_nNewEntity = u->m_nNewEntity;
    m_pFromSnapshot = u->m_pFromSnapshot;
    if ( m_nNewEntity >= m_pFromSnapshot->m_nNumEntities )
      return true;
    m_pEntities = m_pFromSnapshot->m_pEntities;
    v6 = m_nNewEntity;
    if ( m_pEntities[v6].m_pClass == nullptr
      || m_pEntities[v6].m_nSerialNumber != u->m_pToSnapshot->m_pEntities[v6].m_nSerialNumber )
    {
      return true;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1011CF60
// Name: SV_WriteDeltaHeader
// Source: json
//------------------------------------------------------------------------------
void __usercall SV_WriteDeltaHeader(CEntityWriteInfo *u@<edi>, int entnum, char flags)
{
  bf_write *m_pBuf; // esi
  int m_iCurBit; // ecx
  int v5; // ecx

  m_pBuf = u->m_pBuf;
  bf_write::WriteUBitVar(this: m_pBuf, n: entnum - u->m_nHeaderBase - 1);
  m_iCurBit = m_pBuf->m_iCurBit;
  if ( (flags & 1) != 0 )
  {
    if ( m_iCurBit + 1 > m_pBuf->m_nDataBits )
      m_pBuf->m_bOverflow = true;
    if ( !m_pBuf->m_bOverflow )
    {
      m_pBuf->m_pData[m_iCurBit >> 3] |= 1 << (m_iCurBit & 7);
      ++m_pBuf->m_iCurBit;
    }
    v5 = m_pBuf->m_iCurBit;
    if ( v5 + 1 > m_pBuf->m_nDataBits )
      m_pBuf->m_bOverflow = true;
    if ( m_pBuf->m_bOverflow )
      goto LABEL_20;
    if ( (flags & 2) != 0 )
    {
LABEL_10:
      m_pBuf->m_pData[v5 >> 3] |= 1 << (v5 & 7);
      ++m_pBuf->m_iCurBit;
      ++u->m_nHeaderCount;
      u->m_nHeaderBase = entnum;
      return;
    }
  }
  else
  {
    if ( m_iCurBit + 1 > m_pBuf->m_nDataBits )
      m_pBuf->m_bOverflow = true;
    if ( !m_pBuf->m_bOverflow )
    {
      m_pBuf->m_pData[m_iCurBit >> 3] &= ~(1 << (m_iCurBit & 7));
      ++m_pBuf->m_iCurBit;
    }
    v5 = m_pBuf->m_iCurBit;
    if ( v5 + 1 > m_pBuf->m_nDataBits )
      m_pBuf->m_bOverflow = true;
    if ( m_pBuf->m_bOverflow )
      goto LABEL_20;
    if ( (flags & 4) != 0 )
      goto LABEL_10;
  }
  m_pBuf->m_pData[v5 >> 3] &= ~(1 << (v5 & 7));
  ++m_pBuf->m_iCurBit;
LABEL_20:
  ++u->m_nHeaderCount;
  u->m_nHeaderBase = entnum;
}

//------------------------------------------------------------------------------
// Address: 0x1011D080
// Name: SV_WriteEnterPVS
// Source: json
//------------------------------------------------------------------------------
void __usercall SV_WriteEnterPVS(CEntityWriteInfo *u@<esi>)
{
  int m_nNewEntity; // ebx
  bf_write *m_pBuf; // edi
  int m_iCurBit; // ecx
  int v4; // ecx
  int v5; // eax
  CFrameSnapshot *m_pToSnapshot; // ecx
  CFrameSnapshotEntry *m_pEntities; // ecx
  ServerClass *m_pClass; // edi
  CFrameSnapshotEntry *v9; // ebx
  CBaseServer *m_pServer; // edx
  int m_ClassID; // eax
  PackedEntity *PackedEntity; // eax
  int v13; // ebx
  CBitVec<2048> *from_baseline; // eax
  unsigned int *v15; // eax
  PackedEntity *m_pNewPack; // eax
  int m_nBits; // ecx
  char *m_pData; // eax
  int m_nOldEntity; // eax
  CClientFrame *m_pFrom; // ecx
  signed int NextSetBit; // eax
  signed int v22; // eax
  int nFromBytes; // [esp+8h] [ebp-Ch] BYREF
  int nToBits; // [esp+Ch] [ebp-8h] BYREF
  const void *pFromData; // [esp+10h] [ebp-4h] BYREF

  m_nNewEntity = u->m_nNewEntity;
  m_pBuf = u->m_pBuf;
  bf_write::WriteUBitVar(this: m_pBuf, n: m_nNewEntity - u->m_nHeaderBase - 1);
  m_iCurBit = m_pBuf->m_iCurBit;
  if ( m_iCurBit + 1 > m_pBuf->m_nDataBits )
    m_pBuf->m_bOverflow = true;
  if ( !m_pBuf->m_bOverflow )
  {
    m_pBuf->m_pData[m_iCurBit >> 3] &= ~(1 << (m_iCurBit & 7));
    ++m_pBuf->m_iCurBit;
  }
  v4 = m_pBuf->m_iCurBit;
  if ( v4 + 1 > m_pBuf->m_nDataBits )
    m_pBuf->m_bOverflow = true;
  if ( !m_pBuf->m_bOverflow )
  {
    m_pBuf->m_pData[v4 >> 3] |= 1 << (v4 & 7);
    ++m_pBuf->m_iCurBit;
  }
  ++u->m_nHeaderCount;
  v5 = u->m_nNewEntity;
  m_pToSnapshot = u->m_pToSnapshot;
  u->m_nHeaderBase = m_nNewEntity;
  m_pEntities = m_pToSnapshot->m_pEntities;
  m_pClass = m_pEntities[v5].m_pClass;
  v9 = &m_pEntities[v5];
  if ( m_pClass == nullptr )
    Host_Error(error: "SV_CreatePacketEntities: GetEntServerClass failed for ent %d.\n", v5);
  m_pServer = u->m_pServer;
  m_ClassID = m_pClass->m_ClassID;
  if ( m_ClassID >= m_pServer->serverclasses )
    ConMsg(a1: "pClass->m_ClassID(%i) >= %i\n", m_ClassID, m_pServer->serverclasses);
  bf_write::WriteUBitLong(
    this: u->m_pBuf,
    curData: m_pClass->m_ClassID,
    numbits: u->m_pServer->serverclassbits,
    bCheckRange: true);
  bf_write::WriteUBitLong(this: u->m_pBuf, curData: v9->m_nSerialNumber, numbits: 10, bCheckRange: true);
  if ( u->m_bAsDelta
    && (PackedEntity = CFrameSnapshotManager::GetPackedEntity(
                         this: framesnapshotmanager,
                         pSnapshot: u->m_pBaseline,
                         entity: u->m_nNewEntity)) != nullptr
    && PackedEntity->m_pServerClass == u->m_pNewPack->m_pServerClass )
  {
    pFromData = PackedEntity->m_pData;
    v13 = PackedEntity->m_nBits & 0x7FFFFFFF;
  }
  else
  {
    if ( !CBaseServer::GetClassBaseline(this: u->m_pServer, pClass: m_pClass, pData: &pFromData, pDatalen: &nFromBytes) )
      _Error(a1: "SV_WriteEnterPVS: missing instance baseline for '%s'.", m_pClass->m_pNetworkName);
    if ( pFromData == nullptr )
      _Error(a1: "SV_WriteEnterPVS: missing pFromData for '%s'.", m_pClass->m_pNetworkName);
    v13 = 8 * nFromBytes;
  }
  from_baseline = u->m_pTo->from_baseline;
  if ( from_baseline != nullptr )
  {
    v15 = &from_baseline->m_Ints[u->m_nNewEntity >> 5];
    *v15 |= 1 << (u->m_nNewEntity & 0x1F);
  }
  m_pNewPack = u->m_pNewPack;
  m_nBits = m_pNewPack->m_nBits;
  if ( m_nBits >= 0 )
  {
    m_pData = (char *)m_pNewPack->m_pData;
    nToBits = m_nBits & 0x7FFFFFFF;
  }
  else
  {
    m_pData = CBaseServer::UncompressPackedEntity(this: u->m_pServer, pPackedEntity: m_pNewPack, bits: &nToBits);
  }
  u->m_nFullProps += SendTable_WriteAllDeltaProps(
                       pTable: m_pClass->m_pTable,
                       pFromData,
                       nFromDataBits: v13,
                       pToData: m_pData,
                       nToDataBits: nToBits,
                       nObjectID: u->m_pNewPack->m_nEntityIndex,
                       pBufOut: u->m_pBuf);
  m_nOldEntity = u->m_nOldEntity;
  if ( u->m_nNewEntity == m_nOldEntity )
  {
    m_pFrom = u->m_pFrom;
    if ( m_pFrom == nullptr
      || (NextSetBit = CFixedBitVecBase<2048>::FindNextSetBit(
                         this: &m_pFrom->transmit_entity,
                         startBit: m_nOldEntity + 1),
          u->m_nOldEntity = NextSetBit,
          NextSetBit < 0) )
    {
      u->m_nOldEntity = 9999;
    }
  }
  v22 = CFixedBitVecBase<2048>::FindNextSetBit(this: &u->m_pTo->transmit_entity, startBit: u->m_nNewEntity + 1);
  u->m_nNewEntity = v22;
  if ( v22 < 0 )
    u->m_nNewEntity = 9999;
}

//------------------------------------------------------------------------------
// Address: 0x1011D2B0
// Name: SV_WriteLeavePVS
// Source: json
//------------------------------------------------------------------------------
void __usercall SV_WriteLeavePVS(CEntityWriteInfo *u@<eax>)
{
  char v2; // si
  int m_nOldEntity; // ecx
  CFrameSnapshot *m_pFromSnapshot; // edx
  CClientFrame *m_pFrom; // eax
  signed int NextSetBit; // eax

  v2 = 1;
  if ( u->m_bAsDelta )
  {
    m_nOldEntity = u->m_nOldEntity;
    m_pFromSnapshot = u->m_pFromSnapshot;
    if ( u->m_pToSnapshot->m_pEntities[m_nOldEntity].m_pClass == nullptr
      && m_nOldEntity < m_pFromSnapshot->m_nNumEntities
      && m_pFromSnapshot->m_pEntities[m_nOldEntity].m_pClass != nullptr )
    {
      v2 = 3;
      u->m_DeletionFlags.m_Ints[m_nOldEntity >> 5] |= 1 << (m_nOldEntity & 0x1F);
    }
  }
  SV_WriteDeltaHeader(u, entnum: u->m_nOldEntity, flags: v2);
  m_pFrom = u->m_pFrom;
  if ( m_pFrom == nullptr
    || (NextSetBit = CFixedBitVecBase<2048>::FindNextSetBit(
                       this: &m_pFrom->transmit_entity,
                       startBit: u->m_nOldEntity + 1),
        u->m_nOldEntity = NextSetBit,
        NextSetBit < 0) )
  {
    u->m_nOldEntity = 9999;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1011D370
// Name: SV_WritePropsFromPackedEntity
// Source: json
//------------------------------------------------------------------------------
void __usercall SV_WritePropsFromPackedEntity(CEntityWriteInfo *u@<esi>, float a2@<ebp>, const int *a3, int a4)
{
  void *v4; // esp
  PackedEntity *m_pNewPack; // edi
  const SendTable *m_pTable; // ecx
  edict_t *v7; // eax
  IServerUnknown *m_pUnk; // eax
  edict_t *v9; // eax
  IServerUnknown *v10; // eax
  int v11; // eax
  int v12; // eax
  int v13; // edx
  float *v14; // eax
  __int128 v15; // xmm0
  int m_nBits; // eax
  const CSendProxyRecipients *v17; // eax
  int v18; // eax
  bf_write *m_pBuf; // eax
  const char *m_pDebugName; // edx
  int v21; // [esp-10h] [ebp-4080h]
  const CSendProxyRecipients *SamplePosition; // [esp-Ch] [ebp-407Ch]
  int CenterVertIndex; // [esp-8h] [ebp-4078h]
  int v24[4097]; // [esp+Ch] [ebp-4064h] BYREF
  bf_write v25; // [esp+4010h] [ebp-60h] BYREF
  PackedEntity *m_pOldPack; // [esp+4028h] [ebp-48h]
  char *v27; // [esp+402Ch] [ebp-44h]
  SendTable *v28; // [esp+4030h] [ebp-40h]
  __int128 v29; // [esp+4034h] [ebp-3Ch] BYREF
  const SendTable *v30; // [esp+404Ch] [ebp-24h]
  ServerDTITimerType v31; // [esp+4050h] [ebp-20h]
  CCycleCount v32; // [esp+4054h] [ebp-1Ch] BYREF
  int v33; // [esp+405Ch] [ebp-14h] BYREF
  int *v34; // [esp+4060h] [ebp-10h]
  float distToPlayer; // [esp+4064h] [ebp-Ch]
  int v36; // [esp+4068h] [ebp-8h]
  int vars0; // [esp+4070h] [ebp+0h]

  distToPlayer = a2;
  v36 = vars0;
  v4 = alloca(16476);
  m_pNewPack = u->m_pNewPack;
  m_pTable = m_pNewPack->m_pServerClass->m_pTable;
  m_pOldPack = u->m_pOldPack;
  v28 = (SendTable *)m_pTable;
  v32.m_Int64 = 0;
  if ( g_bServerDTIEnabled )
  {
    v30 = m_pTable;
    v31 = SERVERDTI_WRITE_DELTA_PROPS;
    HIDWORD(v29) = &v32;
    v32.m_Int64 = __rdtsc();
    if ( !u->m_pServer->IsHLTV(this: u->m_pServer) )
    {
      v7 = &sv.edicts[m_pNewPack->m_nEntityIndex];
      if ( (v7->m_fStateFlags & 4) != 0 && (m_pUnk = v7->m_pUnk) != nullptr )
        v34 = (int *)m_pUnk->GetCollideable(this: m_pUnk);
      else
        v34 = nullptr;
      v9 = &sv.edicts[u->m_nClientEntity];
      if ( (v9->m_fStateFlags & 4) != 0 && (v10 = v9->m_pUnk) != nullptr )
        v11 = (int)v10->GetCollideable(this: v10);
      else
        v11 = 0;
      if ( v34 != nullptr && v11 != 0 )
      {
        v12 = (*(int (__thiscall **)(int))(*(_DWORD *)v11 + 32))(a1: v11);
        v13 = *v34;
        HIDWORD(v29) = v12;
        v14 = (float *)(*(int (__thiscall **)(int *))(v13 + 32))(a1: v34);
        v15 = 0;
        *(float *)&v15 = fsqrt(
                           (float)((float)((float)(v14[1] - *(float *)(HIDWORD(v29) + 4))
                                         * (float)(v14[1] - *(float *)(HIDWORD(v29) + 4)))
                                 + (float)((float)(v14[2] - *(float *)(HIDWORD(v29) + 8))
                                         * (float)(v14[2] - *(float *)(HIDWORD(v29) + 8))))
                         + (float)((float)(*v14 - *(float *)HIDWORD(v29)) * (float)(*v14 - *(float *)HIDWORD(v29))));
        v29 = v15;
        ServerDTI_AddEntityEncodeEvent(pSendTable: v28, distToPlayer: *(float *)&v15);
      }
    }
  }
  m_nBits = m_pNewPack->m_nBits;
  if ( m_nBits >= 0 )
  {
    HIDWORD(v29) = m_pNewPack->m_pData;
    v33 = m_nBits & 0x7FFFFFFF;
  }
  else
  {
    HIDWORD(v29) = CBaseServer::UncompressPackedEntity(this: u->m_pServer, pPackedEntity: m_pNewPack, bits: &v33);
  }
  v34 = (int *)a3;
  v27 = (char *)a4;
  bf_write::bf_write(this: &v25);
  if ( u->m_bCullProps )
  {
    v34 = v24;
    CenterVertIndex = CCoreDispNode::GetCenterVertIndex(this: (CVTFTexture *)m_pNewPack);
    SamplePosition = (const CSendProxyRecipients *)CAudioMixerWave::GetSamplePosition(this: (CVTFTexture *)m_pNewPack);
    v21 = CCoreDispNode::GetCenterVertIndex(this: (CVTFTexture *)m_pOldPack);
    v17 = (const CSendProxyRecipients *)CAudioMixerWave::GetSamplePosition(this: (CVTFTexture *)m_pOldPack);
    v18 = SendTable_CullPropsFromProxies(
            pTable: v28,
            pStartProps: a3,
            nStartProps: a4,
            iClient: u->m_nClientEntity - 1,
            pOldStateProxies: v17,
            nOldStateProxies: v21,
            pNewStateProxies: SamplePosition,
            nNewStateProxies: CenterVertIndex,
            pOutProps: v24,
            nMaxOutProps: 4096);
  }
  else
  {
    m_pBuf = u->m_pBuf;
    v25.m_pData = m_pBuf->m_pData;
    v25.m_nDataBytes = m_pBuf->m_nDataBytes;
    v25.m_nDataBits = m_pBuf->m_nDataBits;
    v25.m_iCurBit = m_pBuf->m_iCurBit;
    *(_DWORD *)&v25.m_bOverflow = *(_DWORD *)&m_pBuf->m_bOverflow;
    m_pDebugName = m_pBuf->m_pDebugName;
    v18 = (int)v27;
    v25.m_pDebugName = m_pDebugName;
  }
  SendTable_WritePropList(
    pTable: v28,
    pState: (const void *)HIDWORD(v29),
    nBits: v33,
    pOut: u->m_pBuf,
    objectID: m_pNewPack->m_nEntityIndex,
    pCheckProps: v34,
    nCheckProps: v18);
  if ( !u->m_bCullProps && hltv != nullptr )
    CDeltaEntityCache::AddDeltaBits(
      this: &hltv->m_DeltaCache,
      nEntityIndex: m_pNewPack->m_nEntityIndex,
      nDeltaTick: u->m_pFromSnapshot->m_nTickCount,
      nBits: u->m_pBuf->m_iCurBit - v25.m_iCurBit,
      pBuffer: &v25);
  if ( g_bServerDTIEnabled && v30 != nullptr )
  {
    v27 = (char *)&v29 + 8;
    *((_QWORD *)&v29 + 1) = __rdtsc();
    v32.m_Int64 = *((_QWORD *)&v29 + 1) - v32.m_Int64;
    _ServerDTI_HookTimer(pSendTable: v30, timerType: v31, count: &v32);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1011D630
// Name: SV_DetermineUpdateType
// Source: json
//------------------------------------------------------------------------------
void __thiscall SV_DetermineUpdateType(CEntityWriteInfo *u)
{
  int m_nNewEntity; // esi
  int m_nOldEntity; // eax
  CFrameSnapshot *m_pFromSnapshot; // edx
  CDeltaEntityCache::DeltaEntityEntry_s *DeltaBits; // esi
  int PropsChangedAfterTick; // esi
  PackedEntity *m_pOldPack; // ecx
  int m_nBits; // eax
  char *m_pData; // esi
  PackedEntity *m_pNewPack; // eax
  int v11; // ecx
  char *v12; // eax
  int iOutProps[4096]; // [esp+8h] [ebp-4008h] BYREF
  int bits; // [esp+4008h] [ebp-8h] BYREF
  int nBits; // [esp+400Ch] [ebp-4h] BYREF
  int savedregs; // [esp+4010h] [ebp+0h] BYREF

  m_nNewEntity = u->m_nNewEntity;
  m_nOldEntity = u->m_nOldEntity;
  if ( m_nNewEntity < m_nOldEntity )
    goto LABEL_2;
  if ( m_nNewEntity > m_nOldEntity )
  {
    u->m_UpdateType = LeavePVS;
    return;
  }
  if ( SV_NeedsExplicitCreate(a1: (int)u, u) )
  {
LABEL_2:
    u->m_UpdateType = EnterPVS;
    return;
  }
  if ( u->m_pOldPack != u->m_pNewPack )
  {
    if ( !u->m_bCullProps
      && hltv != nullptr
      && (m_pFromSnapshot = u->m_pFromSnapshot,
          nBits = 0,
          (DeltaBits = CDeltaEntityCache::FindDeltaBits(
                         this: &hltv->m_DeltaCache,
                         nEntityIndex: m_nNewEntity,
                         nDeltaTick: m_pFromSnapshot->m_nTickCount,
                         &nBits)) != nullptr) )
    {
      if ( nBits > 0 )
      {
        SV_WriteDeltaHeader(u, entnum: u->m_nNewEntity, flags: 0);
        bf_write::WriteBits(this: u->m_pBuf, pInData: (unsigned int)DeltaBits, nBits);
        u->m_UpdateType = DeltaEnt;
        return;
      }
    }
    else
    {
      PropsChangedAfterTick = PackedEntity::GetPropsChangedAfterTick(
                                this: u->m_pNewPack,
                                iTick: u->m_pFromSnapshot->m_nTickCount,
                                iOutProps,
                                nMaxOutProps: 4096);
      if ( PropsChangedAfterTick == -1 )
      {
        m_pOldPack = u->m_pOldPack;
        m_nBits = m_pOldPack->m_nBits;
        if ( m_nBits >= 0 )
        {
          m_pData = (char *)m_pOldPack->m_pData;
          bits = m_nBits & 0x7FFFFFFF;
        }
        else
        {
          m_pData = CBaseServer::UncompressPackedEntity(this: u->m_pServer, pPackedEntity: m_pOldPack, &bits);
        }
        m_pNewPack = u->m_pNewPack;
        v11 = m_pNewPack->m_nBits;
        if ( v11 >= 0 )
        {
          v12 = (char *)m_pNewPack->m_pData;
          nBits = v11 & 0x7FFFFFFF;
        }
        else
        {
          v12 = CBaseServer::UncompressPackedEntity(this: u->m_pServer, pPackedEntity: m_pNewPack, bits: &nBits);
        }
        PropsChangedAfterTick = SendTable_CalcDelta(
                                  pTable: u->m_pOldPack->m_pServerClass->m_pTable,
                                  pFromState: m_pData,
                                  nFromBits: bits,
                                  pToState: v12,
                                  nToBits: nBits,
                                  pDeltaProps: iOutProps,
                                  nMaxDeltaProps: 4096,
                                  objectID: u->m_nNewEntity);
      }
      if ( PropsChangedAfterTick > 0 )
      {
        SV_WriteDeltaHeader(u, entnum: u->m_nNewEntity, flags: 0);
        SV_WritePropsFromPackedEntity(u, a2: COERCE_FLOAT(&savedregs), a3: iOutProps, a4: PropsChangedAfterTick);
        u->m_UpdateType = DeltaEnt;
        return;
      }
      if ( !u->m_bCullProps && hltv != nullptr )
        CDeltaEntityCache::AddDeltaBits(
          this: &hltv->m_DeltaCache,
          nEntityIndex: u->m_nNewEntity,
          nDeltaTick: u->m_pFromSnapshot->m_nTickCount,
          nBits: 0,
          pBuffer: nullptr);
    }
  }
  u->m_UpdateType = PreserveEnt;
}

//------------------------------------------------------------------------------
// Address: 0x1011D800
// Name: SV_WriteDeletions
// Source: json
//------------------------------------------------------------------------------
int __usercall SV_WriteDeletions@<eax>(CEntityWriteInfo *u@<edi>)
{
  CFrameSnapshot *m_pToSnapshot; // edx
  unsigned int v3; // ebx
  CFrameSnapshot *m_pFromSnapshot; // esi
  int m_Size; // edx
  int v6; // eax
  int *m_pMemory; // ecx
  CFrameSnapshotEntry *v8; // ecx
  CFrameSnapshotEntry *v9; // eax
  bf_write *m_pBuf; // eax
  int m_iCurBit; // ecx
  bf_write *v12; // eax
  int v13; // ecx
  int v14; // [esp+4h] [ebp-10h]
  int nNumDeletions; // [esp+8h] [ebp-Ch]
  CFrameSnapshot *pSnapShot; // [esp+Ch] [ebp-8h]
  int v17; // [esp+10h] [ebp-4h]

  if ( !u->m_bAsDelta )
    return 0;
  m_pToSnapshot = u->m_pToSnapshot;
  v3 = 0;
  nNumDeletions = 0;
  pSnapShot = m_pToSnapshot;
  if ( m_pToSnapshot->m_nNumEntities > 0 )
  {
    v17 = 0;
    while ( 1 )
    {
      v14 = 1 << (v3 & 0x1F);
      if ( (v14 & u->m_DeletionFlags.m_Ints[v3 >> 5]) == 0 )
      {
        m_pFromSnapshot = u->m_pFromSnapshot;
        if ( m_pToSnapshot->m_pEntities[v17].m_pClass == nullptr
          && (signed int)v3 < m_pFromSnapshot->m_nNumEntities
          && m_pFromSnapshot->m_pEntities[v17].m_pClass != nullptr )
        {
          goto LABEL_21;
        }
        if ( u->m_pTo != nullptr )
          break;
      }
LABEL_27:
      ++v17;
      if ( (signed int)++v3 >= m_pToSnapshot->m_nNumEntities )
        goto LABEL_28;
    }
    m_Size = m_pToSnapshot->m_iExplicitDeleteSlots.m_Size;
    v6 = 0;
    if ( m_Size <= 0 )
    {
LABEL_14:
      v6 = -1;
    }
    else
    {
      m_pMemory = pSnapShot->m_iExplicitDeleteSlots.m_Memory.m_pMemory;
      while ( *m_pMemory != v3 )
      {
        ++v6;
        ++m_pMemory;
        if ( v6 >= m_Size )
          goto LABEL_14;
      }
    }
    if ( v6 != -1 )
    {
      if ( (v8 = &u->m_pToSnapshot->m_pEntities[v17], (v9 = &m_pFromSnapshot->m_pEntities[v17]) == nullptr)
        || v8 == nullptr
        || v9->m_pClass != nullptr && v9->m_nSerialNumber == v8->m_nSerialNumber
        || (v14 & u->m_pTo->transmit_entity.m_Ints[v3 >> 5]) == 0 )
      {
LABEL_21:
        m_pBuf = u->m_pBuf;
        m_iCurBit = m_pBuf->m_iCurBit;
        if ( m_iCurBit + 1 > m_pBuf->m_nDataBits )
          m_pBuf->m_bOverflow = true;
        if ( !m_pBuf->m_bOverflow )
        {
          m_pBuf->m_pData[m_iCurBit >> 3] |= 1 << (m_iCurBit & 7);
          ++m_pBuf->m_iCurBit;
        }
        bf_write::WriteUBitLong(this: u->m_pBuf, curData: v3, numbits: 11, bCheckRange: true);
        ++nNumDeletions;
      }
    }
    m_pToSnapshot = pSnapShot;
    goto LABEL_27;
  }
LABEL_28:
  v12 = u->m_pBuf;
  v13 = v12->m_iCurBit;
  if ( v13 + 1 > v12->m_nDataBits )
    v12->m_bOverflow = true;
  if ( !v12->m_bOverflow )
  {
    v12->m_pData[v13 >> 3] &= ~(1 << (v13 & 7));
    ++v12->m_iCurBit;
  }
  return nNumDeletions;
}

//------------------------------------------------------------------------------
// Address: 0x1011D9A0
// Name: public: virtual void CBaseServer::WriteDeltaEntities(class CBaseClient __near *,class CClientFrame __near *,class CClientFrame __near *,class bf_write __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseServer::WriteDeltaEntities(
        CBaseServer *this,
        CBaseClient *client,
        CClientFrame *to,
        CClientFrame *from,
        bf_write *pBuf)
{
  CFrameSnapshot *m_pSnapshot; // ecx
  CBaseClient *v7; // esi
  CFrameSnapshot *m_pBaseline; // edx
  int m_nEntityIndex; // eax
  CBaseServer_vtbl *v11; // edx
  bool (__thiscall *IsHLTV)(struct CBaseServer *); // eax
  CFrameSnapshot *v13; // edx
  bool v14; // zf
  int m_iCurBit; // ecx
  unsigned __int8 *m_pData; // edx
  int m_nDataBytes; // eax
  const char *m_pDebugName; // ecx
  int v19; // edx
  int v20; // eax
  int NextSetBit; // esi
  int m_nNewEntity; // edi
  int v23; // eax
  int v24; // edi
  IServerNetworkable *m_pNetworkable; // ecx
  const char *v26; // eax
  IServerNetworkable *v27; // ecx
  const char *v28; // eax
  CEntityWriteInfo u; // [esp+Ch] [ebp-164h] BYREF
  bf_write savepos; // [esp+158h] [ebp-18h] BYREF
  int startbit; // [esp+180h] [ebp+10h]
  bool bIsTracing_3; // [esp+187h] [ebp+17h]

  memset(&u.m_nOldEntity, 255, 12);
  u.__vftable = (CEntityWriteInfo_vtbl *)&CEntityWriteInfo::`vftable';
  memset(dst: (unsigned __int8 *)&u.m_DeletionFlags, value: 0, count: sizeof(u.m_DeletionFlags));
  m_pSnapshot = to->m_pSnapshot;
  v7 = client;
  m_pBaseline = client->m_pBaseline;
  u.m_pTo = to;
  m_nEntityIndex = client->m_nEntityIndex;
  u.m_pBaseline = m_pBaseline;
  v11 = this->__vftable;
  u.m_pToSnapshot = m_pSnapshot;
  u.m_nClientEntity = m_nEntityIndex;
  IsHLTV = v11->IsHLTV;
  u.m_pBuf = pBuf;
  u.m_nFullProps = 0;
  u.m_pServer = this;
  u.m_bCullProps = !IsHLTV(this) || sv.m_State >= ss_active;
  if ( from != nullptr )
  {
    v13 = from->m_pSnapshot;
    u.m_bAsDelta = true;
    u.m_pFrom = from;
    u.m_pFromSnapshot = v13;
  }
  else
  {
    u.m_bAsDelta = false;
    u.m_pFrom = nullptr;
    u.m_pFromSnapshot = nullptr;
  }
  v14 = client->m_nBaselineUpdateTick == -1;
  u.m_nHeaderCount = 0;
  if ( v14 )
  {
    if ( client != (CBaseClient *)-256 )
      memset(dst: (unsigned __int8 *)&client->m_BaselinesSent, value: 0, count: sizeof(client->m_BaselinesSent));
    to->from_baseline = &client->m_BaselinesSent;
  }
  bf_write::WriteUBitLong(this: pBuf, curData: 0x1Au, numbits: 6, bCheckRange: true);
  bf_write::WriteUBitLong(this: pBuf, curData: u.m_pToSnapshot->m_nNumEntities, numbits: 11, bCheckRange: true);
  m_iCurBit = pBuf->m_iCurBit;
  if ( u.m_bAsDelta )
  {
    if ( m_iCurBit + 1 > pBuf->m_nDataBits )
      pBuf->m_bOverflow = true;
    if ( !pBuf->m_bOverflow )
    {
      pBuf->m_pData[m_iCurBit >> 3] |= 1 << (m_iCurBit & 7);
      ++pBuf->m_iCurBit;
    }
    bf_write::WriteLong(this: pBuf, val: u.m_pFrom->tick_count);
  }
  else
  {
    if ( m_iCurBit + 1 > pBuf->m_nDataBits )
      pBuf->m_bOverflow = true;
    if ( !pBuf->m_bOverflow )
    {
      pBuf->m_pData[m_iCurBit >> 3] &= ~(1 << (m_iCurBit & 7));
      ++pBuf->m_iCurBit;
    }
  }
  bf_write::WriteUBitLong(this: pBuf, curData: client->m_nBaselineUsed, numbits: 1, bCheckRange: true);
  m_pData = pBuf->m_pData;
  m_nDataBytes = pBuf->m_nDataBytes;
  savepos.m_nDataBits = pBuf->m_nDataBits;
  m_pDebugName = pBuf->m_pDebugName;
  savepos.m_pData = m_pData;
  v19 = pBuf->m_iCurBit;
  savepos.m_nDataBytes = m_nDataBytes;
  v20 = *(_DWORD *)&pBuf->m_bOverflow;
  savepos.m_pDebugName = m_pDebugName;
  savepos.m_iCurBit = v19;
  *(_DWORD *)&savepos.m_bOverflow = v20;
  bf_write::WriteUBitLong(this: pBuf, curData: 0, numbits: 32, bCheckRange: true);
  startbit = pBuf->m_iCurBit;
  bIsTracing_3 = CBaseClient::IsTracing(this: client);
  if ( bIsTracing_3 )
    CBaseClient::TraceNetworkData(this: client, msg: pBuf, fmt: "Delta Entities Overhead");
  if ( g_pLocalNetworkBackdoor == nullptr )
  {
    if ( u.m_pFrom == nullptr
      || (NextSetBit = CFixedBitVecBase<2048>::FindNextSetBit(
                         this: &u.m_pFrom->transmit_entity,
                         startBit: u.m_nOldEntity + 1),
          u.m_nOldEntity = NextSetBit,
          NextSetBit < 0) )
    {
      NextSetBit = 9999;
      u.m_nOldEntity = 9999;
    }
    m_nNewEntity = CFixedBitVecBase<2048>::FindNextSetBit(this: &to->transmit_entity, startBit: u.m_nNewEntity + 1);
    u.m_nNewEntity = m_nNewEntity;
    if ( m_nNewEntity < 0 )
    {
      m_nNewEntity = 9999;
      u.m_nNewEntity = 9999;
    }
    while ( NextSetBit != 9999 )
    {
      if ( m_nNewEntity != 9999 )
        goto LABEL_43;
      u.m_pNewPack = nullptr;
LABEL_45:
      if ( NextSetBit == 9999 )
        u.m_pOldPack = nullptr;
      else
        u.m_pOldPack = CFrameSnapshotManager::GetPackedEntity(
                         this: framesnapshotmanager,
                         pSnapshot: u.m_pFromSnapshot,
                         entity: NextSetBit);
      SV_DetermineUpdateType(&u);
      switch ( u.m_UpdateType )
      {
        case EnterPVS:
          SV_WriteEnterPVS(&u);
          goto LABEL_50;
        case LeavePVS:
          SV_WriteLeavePVS(&u);
          goto LABEL_50;
        case DeltaEnt:
          if ( u.m_pFrom == nullptr
            || (NextSetBit = CFixedBitVecBase<2048>::FindNextSetBit(
                               this: &u.m_pFrom->transmit_entity,
                               startBit: u.m_nOldEntity + 1),
                u.m_nOldEntity = NextSetBit,
                NextSetBit < 0) )
          {
            NextSetBit = 9999;
            u.m_nOldEntity = 9999;
          }
          goto LABEL_60;
        case PreserveEnt:
          if ( u.m_pFrom == nullptr
            || (NextSetBit = CFixedBitVecBase<2048>::FindNextSetBit(
                               this: &u.m_pFrom->transmit_entity,
                               startBit: u.m_nOldEntity + 1),
                u.m_nOldEntity = NextSetBit,
                NextSetBit < 0) )
          {
            NextSetBit = 9999;
            u.m_nOldEntity = 9999;
          }
LABEL_60:
          m_nNewEntity = CFixedBitVecBase<2048>::FindNextSetBit(
                           this: &u.m_pTo->transmit_entity,
                           startBit: u.m_nNewEntity + 1);
          u.m_nNewEntity = m_nNewEntity;
          if ( m_nNewEntity < 0 )
          {
            m_nNewEntity = 9999;
            u.m_nNewEntity = 9999;
          }
          break;
        default:
LABEL_50:
          m_nNewEntity = u.m_nNewEntity;
          NextSetBit = u.m_nOldEntity;
          break;
      }
      if ( bIsTracing_3 )
      {
        if ( u.m_UpdateType != EnterPVS )
        {
          if ( u.m_UpdateType == LeavePVS )
          {
            CBaseClient::TraceNetworkData(
              this: client,
              msg: pBuf,
              fmt: "leave [%s]",
              u.m_pOldPack->m_pServerClass->m_pNetworkName);
          }
          else if ( u.m_UpdateType == DeltaEnt )
          {
            m_pNetworkable = sv.edicts[u.m_pOldPack->m_nEntityIndex].m_pNetworkable;
            v26 = m_pNetworkable->GetClassNameA(this: m_pNetworkable);
            CBaseClient::TraceNetworkData(this: client, msg: pBuf, fmt: "delta [%s]", v26);
          }
        }
        else
        {
          v27 = sv.edicts[u.m_pNewPack->m_nEntityIndex].m_pNetworkable;
          v28 = v27->GetClassNameA(this: v27);
          CBaseClient::TraceNetworkData(this: client, msg: pBuf, fmt: "enter [%s]", v28);
        }
      }
    }
    if ( m_nNewEntity == 9999 )
    {
      v23 = SV_WriteDeletions(&u);
      if ( bIsTracing_3 )
        CBaseClient::TraceNetworkData(this: client, msg: pBuf, fmt: "Delta: [%d] deletions", v23);
      v7 = client;
      goto LABEL_34;
    }
LABEL_43:
    u.m_pNewPack = CFrameSnapshotManager::GetPackedEntity(
                     this: framesnapshotmanager,
                     pSnapshot: u.m_pToSnapshot,
                     entity: m_nNewEntity);
    goto LABEL_45;
  }
LABEL_34:
  v24 = u.m_pBuf->m_iCurBit;
  bf_write::WriteUBitLong(this: &savepos, curData: u.m_nHeaderCount, numbits: 11, bCheckRange: true);
  bf_write::WriteUBitLong(this: &savepos, curData: v24 - startbit, numbits: 20, bCheckRange: true);
  if ( v7->m_nBaselineUpdateTick == -1 && (u.m_nFullProps > 0 || !u.m_bAsDelta) && u.m_pBaseline != nullptr )
  {
    if ( savepos.m_iCurBit + 1 <= savepos.m_nDataBits && !savepos.m_bOverflow )
      savepos.m_pData[savepos.m_iCurBit >> 3] |= 1 << (savepos.m_iCurBit & 7);
    v7->m_nBaselineUpdateTick = to->tick_count;
  }
  else if ( savepos.m_iCurBit + 1 <= savepos.m_nDataBits && !savepos.m_bOverflow )
  {
    savepos.m_pData[savepos.m_iCurBit >> 3] &= ~(1 << (savepos.m_iCurBit & 7));
  }
  if ( bIsTracing_3 )
    CBaseClient::TraceNetworkData(this: v7, msg: pBuf, fmt: "Delta Finish");
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x1011D0A0
// Name: SV_NeedsExplicitCreate
// Source: json
//------------------------------------------------------------------------------
bool __fastcall SV_NeedsExplicitCreate(int a1, CEntityWriteInfo *u)
{
  bool result; // al
  int m_nNewEntity; // eax
  CFrameSnapshot *m_pFromSnapshot; // ecx
  CFrameSnapshotEntry *m_pEntities; // ecx
  unsigned int v6; // eax

  result = false;
  if ( u->m_bAsDelta )
  {
    m_nNewEntity = u->m_nNewEntity;
    m_pFromSnapshot = u->m_pFromSnapshot;
    if ( m_nNewEntity >= m_pFromSnapshot->m_nNumEntities )
      return true;
    m_pEntities = m_pFromSnapshot->m_pEntities;
    v6 = m_nNewEntity;
    if ( m_pEntities[v6].m_pClass == nullptr
      || m_pEntities[v6].m_nSerialNumber != u->m_pToSnapshot->m_pEntities[v6].m_nSerialNumber )
    {
      return true;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1011D0E0
// Name: SV_WriteDeltaHeader
// Source: json
//------------------------------------------------------------------------------
void __usercall SV_WriteDeltaHeader(CEntityWriteInfo *u@<edi>, int entnum, char flags)
{
  bf_write *m_pBuf; // esi
  int m_iCurBit; // ecx
  int v5; // ecx

  m_pBuf = u->m_pBuf;
  bf_write::WriteUBitVar(this: m_pBuf, n: entnum - u->m_nHeaderBase - 1);
  m_iCurBit = m_pBuf->m_iCurBit;
  if ( (flags & 1) != 0 )
  {
    if ( m_iCurBit + 1 > m_pBuf->m_nDataBits )
      m_pBuf->m_bOverflow = true;
    if ( !m_pBuf->m_bOverflow )
    {
      m_pBuf->m_pData[m_iCurBit >> 3] |= 1 << (m_iCurBit & 7);
      ++m_pBuf->m_iCurBit;
    }
    v5 = m_pBuf->m_iCurBit;
    if ( v5 + 1 > m_pBuf->m_nDataBits )
      m_pBuf->m_bOverflow = true;
    if ( m_pBuf->m_bOverflow )
      goto LABEL_20;
    if ( (flags & 2) != 0 )
    {
LABEL_10:
      m_pBuf->m_pData[v5 >> 3] |= 1 << (v5 & 7);
      ++m_pBuf->m_iCurBit;
      ++u->m_nHeaderCount;
      u->m_nHeaderBase = entnum;
      return;
    }
  }
  else
  {
    if ( m_iCurBit + 1 > m_pBuf->m_nDataBits )
      m_pBuf->m_bOverflow = true;
    if ( !m_pBuf->m_bOverflow )
    {
      m_pBuf->m_pData[m_iCurBit >> 3] &= ~(1 << (m_iCurBit & 7));
      ++m_pBuf->m_iCurBit;
    }
    v5 = m_pBuf->m_iCurBit;
    if ( v5 + 1 > m_pBuf->m_nDataBits )
      m_pBuf->m_bOverflow = true;
    if ( m_pBuf->m_bOverflow )
      goto LABEL_20;
    if ( (flags & 4) != 0 )
      goto LABEL_10;
  }
  m_pBuf->m_pData[v5 >> 3] &= ~(1 << (v5 & 7));
  ++m_pBuf->m_iCurBit;
LABEL_20:
  ++u->m_nHeaderCount;
  u->m_nHeaderBase = entnum;
}

//------------------------------------------------------------------------------
// Address: 0x1011D200
// Name: SV_WriteEnterPVS
// Source: json
//------------------------------------------------------------------------------
void __usercall SV_WriteEnterPVS(CEntityWriteInfo *u@<esi>)
{
  int m_nNewEntity; // ebx
  bf_write *m_pBuf; // edi
  int m_iCurBit; // ecx
  int v4; // ecx
  int v5; // eax
  CFrameSnapshot *m_pToSnapshot; // ecx
  CFrameSnapshotEntry *m_pEntities; // ecx
  ServerClass *m_pClass; // edi
  CFrameSnapshotEntry *v9; // ebx
  CBaseServer *m_pServer; // edx
  int m_ClassID; // eax
  PackedEntity *PackedEntity; // eax
  int v13; // ebx
  CBitVec<2048> *from_baseline; // eax
  unsigned int *v15; // eax
  PackedEntity *m_pNewPack; // eax
  int m_nBits; // ecx
  const char *m_pData; // eax
  int m_nOldEntity; // eax
  CClientFrame *m_pFrom; // ecx
  signed int NextSetBit; // eax
  signed int v22; // eax
  int nFromBytes; // [esp+8h] [ebp-Ch] BYREF
  int nToBits; // [esp+Ch] [ebp-8h] BYREF
  const void *pFromData; // [esp+10h] [ebp-4h] BYREF

  m_nNewEntity = u->m_nNewEntity;
  m_pBuf = u->m_pBuf;
  bf_write::WriteUBitVar(this: m_pBuf, n: m_nNewEntity - u->m_nHeaderBase - 1);
  m_iCurBit = m_pBuf->m_iCurBit;
  if ( m_iCurBit + 1 > m_pBuf->m_nDataBits )
    m_pBuf->m_bOverflow = true;
  if ( !m_pBuf->m_bOverflow )
  {
    m_pBuf->m_pData[m_iCurBit >> 3] &= ~(1 << (m_iCurBit & 7));
    ++m_pBuf->m_iCurBit;
  }
  v4 = m_pBuf->m_iCurBit;
  if ( v4 + 1 > m_pBuf->m_nDataBits )
    m_pBuf->m_bOverflow = true;
  if ( !m_pBuf->m_bOverflow )
  {
    m_pBuf->m_pData[v4 >> 3] |= 1 << (v4 & 7);
    ++m_pBuf->m_iCurBit;
  }
  ++u->m_nHeaderCount;
  v5 = u->m_nNewEntity;
  m_pToSnapshot = u->m_pToSnapshot;
  u->m_nHeaderBase = m_nNewEntity;
  m_pEntities = m_pToSnapshot->m_pEntities;
  m_pClass = m_pEntities[v5].m_pClass;
  v9 = &m_pEntities[v5];
  if ( m_pClass == nullptr )
    Host_Error(error: "SV_CreatePacketEntities: GetEntServerClass failed for ent %d.\n", v5);
  m_pServer = u->m_pServer;
  m_ClassID = m_pClass->m_ClassID;
  if ( m_ClassID >= m_pServer->serverclasses )
    ConMsg(a1: "pClass->m_ClassID(%i) >= %i\n", m_ClassID, m_pServer->serverclasses);
  bf_write::WriteUBitLong(
    this: u->m_pBuf,
    curData: m_pClass->m_ClassID,
    numbits: u->m_pServer->serverclassbits,
    bCheckRange: true);
  bf_write::WriteUBitLong(this: u->m_pBuf, curData: v9->m_nSerialNumber, numbits: 10, bCheckRange: true);
  if ( u->m_bAsDelta
    && (PackedEntity = CFrameSnapshotManager::GetPackedEntity(
                         this: framesnapshotmanager,
                         pSnapshot: u->m_pBaseline,
                         entity: u->m_nNewEntity)) != nullptr
    && PackedEntity->m_pServerClass == u->m_pNewPack->m_pServerClass )
  {
    pFromData = PackedEntity->m_pData;
    v13 = PackedEntity->m_nBits & 0x7FFFFFFF;
  }
  else
  {
    if ( !CBaseServer::GetClassBaseline(this: u->m_pServer, pClass: m_pClass, pData: &pFromData, pDatalen: &nFromBytes) )
      _Error(a1: "SV_WriteEnterPVS: missing instance baseline for '%s'.", m_pClass->m_pNetworkName);
    if ( pFromData == nullptr )
      _Error(a1: "SV_WriteEnterPVS: missing pFromData for '%s'.", m_pClass->m_pNetworkName);
    v13 = 8 * nFromBytes;
  }
  from_baseline = u->m_pTo->from_baseline;
  if ( from_baseline != nullptr )
  {
    v15 = &from_baseline->m_Ints[u->m_nNewEntity >> 5];
    *v15 |= 1 << (u->m_nNewEntity & 0x1F);
  }
  m_pNewPack = u->m_pNewPack;
  m_nBits = m_pNewPack->m_nBits;
  if ( m_nBits >= 0 )
  {
    m_pData = (const char *)m_pNewPack->m_pData;
    nToBits = m_nBits & 0x7FFFFFFF;
  }
  else
  {
    m_pData = CBaseServer::UncompressPackedEntity(this: u->m_pServer, pPackedEntity: m_pNewPack, bits: &nToBits);
  }
  u->m_nFullProps += SendTable_WriteAllDeltaProps(
                       pTable: m_pClass->m_pTable,
                       pFromData,
                       nFromDataBits: v13,
                       pToData: m_pData,
                       nToDataBits: nToBits,
                       nObjectID: u->m_pNewPack->m_nEntityIndex,
                       pBufOut: u->m_pBuf);
  m_nOldEntity = u->m_nOldEntity;
  if ( u->m_nNewEntity == m_nOldEntity )
  {
    m_pFrom = u->m_pFrom;
    if ( m_pFrom == nullptr
      || (NextSetBit = CFixedBitVecBase<2048>::FindNextSetBit(
                         this: &m_pFrom->transmit_entity,
                         startBit: m_nOldEntity + 1),
          u->m_nOldEntity = NextSetBit,
          NextSetBit < 0) )
    {
      u->m_nOldEntity = 9999;
    }
  }
  v22 = CFixedBitVecBase<2048>::FindNextSetBit(this: &u->m_pTo->transmit_entity, startBit: u->m_nNewEntity + 1);
  u->m_nNewEntity = v22;
  if ( v22 < 0 )
    u->m_nNewEntity = 9999;
}

//------------------------------------------------------------------------------
// Address: 0x1011D430
// Name: SV_WriteLeavePVS
// Source: json
//------------------------------------------------------------------------------
void __usercall SV_WriteLeavePVS(CEntityWriteInfo *u@<eax>)
{
  char v2; // si
  int m_nOldEntity; // ecx
  CFrameSnapshot *m_pFromSnapshot; // edx
  CClientFrame *m_pFrom; // eax
  signed int NextSetBit; // eax

  v2 = 1;
  if ( u->m_bAsDelta )
  {
    m_nOldEntity = u->m_nOldEntity;
    m_pFromSnapshot = u->m_pFromSnapshot;
    if ( u->m_pToSnapshot->m_pEntities[m_nOldEntity].m_pClass == nullptr
      && m_nOldEntity < m_pFromSnapshot->m_nNumEntities
      && m_pFromSnapshot->m_pEntities[m_nOldEntity].m_pClass != nullptr )
    {
      v2 = 3;
      u->m_DeletionFlags.m_Ints[m_nOldEntity >> 5] |= 1 << (m_nOldEntity & 0x1F);
    }
  }
  SV_WriteDeltaHeader(u, entnum: u->m_nOldEntity, flags: v2);
  m_pFrom = u->m_pFrom;
  if ( m_pFrom == nullptr
    || (NextSetBit = CFixedBitVecBase<2048>::FindNextSetBit(
                       this: &m_pFrom->transmit_entity,
                       startBit: u->m_nOldEntity + 1),
        u->m_nOldEntity = NextSetBit,
        NextSetBit < 0) )
  {
    u->m_nOldEntity = 9999;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1011D520
// Name: SV_WritePropsFromPackedEntity
// Source: json
//------------------------------------------------------------------------------
void __usercall SV_WritePropsFromPackedEntity(CEntityWriteInfo *u@<esi>, int a2@<ebp>, const int *a3, int a4)
{
  void *v4; // esp
  PackedEntity *m_pNewPack; // edi
  const SendTable *m_pTable; // ecx
  edict_t *v7; // eax
  IServerUnknown *m_pUnk; // eax
  edict_t *v9; // eax
  IServerUnknown *v10; // eax
  int v11; // eax
  int v12; // eax
  int v13; // edx
  float *v14; // eax
  __int128 distToPlayer; // xmm0
  int m_nBits; // eax
  const CSendProxyRecipients *v17; // eax
  int v18; // eax
  bf_write *m_pBuf; // eax
  const char *m_pDebugName; // edx
  int v21; // [esp-10h] [ebp-4080h]
  const CSendProxyRecipients *SamplePosition; // [esp-Ch] [ebp-407Ch]
  int CenterVertIndex; // [esp-8h] [ebp-4078h]
  int v24[4097]; // [esp+Ch] [ebp-4064h] BYREF
  bf_write v25; // [esp+4010h] [ebp-60h] BYREF
  PackedEntity *m_pOldPack; // [esp+4028h] [ebp-48h]
  char *v27; // [esp+402Ch] [ebp-44h]
  SendTable *v28; // [esp+4030h] [ebp-40h]
  __int128 v29; // [esp+4034h] [ebp-3Ch] BYREF
  const SendTable *v30; // [esp+404Ch] [ebp-24h]
  ServerDTITimerType v31; // [esp+4050h] [ebp-20h]
  CCycleCount v32; // [esp+4054h] [ebp-1Ch] BYREF
  int v33; // [esp+405Ch] [ebp-14h] BYREF
  int *v34; // [esp+4060h] [ebp-10h]
  int v35; // [esp+4064h] [ebp-Ch]
  void *v36; // [esp+4068h] [ebp-8h]
  void *retaddr; // [esp+4070h] [ebp+0h]

  v35 = a2;
  v36 = retaddr;
  v4 = alloca(16476);
  m_pNewPack = u->m_pNewPack;
  m_pTable = m_pNewPack->m_pServerClass->m_pTable;
  m_pOldPack = u->m_pOldPack;
  v28 = (SendTable *)m_pTable;
  v32.m_Int64 = 0;
  if ( g_bServerDTIEnabled )
  {
    v30 = m_pTable;
    v31 = SERVERDTI_WRITE_DELTA_PROPS;
    HIDWORD(v29) = &v32;
    v32.m_Int64 = __rdtsc();
    if ( !u->m_pServer->IsHLTV(this: u->m_pServer) )
    {
      v7 = &sv.edicts[m_pNewPack->m_nEntityIndex];
      if ( (v7->m_fStateFlags & 4) != 0 && (m_pUnk = v7->m_pUnk) != nullptr )
        v34 = (int *)m_pUnk->GetCollideable(this: m_pUnk);
      else
        v34 = nullptr;
      v9 = &sv.edicts[u->m_nClientEntity];
      if ( (v9->m_fStateFlags & 4) != 0 && (v10 = v9->m_pUnk) != nullptr )
        v11 = (int)v10->GetCollideable(this: v10);
      else
        v11 = 0;
      if ( v34 != nullptr && v11 != 0 )
      {
        v12 = (*(int (__thiscall **)(int))(*(_DWORD *)v11 + 32))(a1: v11);
        v13 = *v34;
        HIDWORD(v29) = v12;
        v14 = (float *)(*(int (__thiscall **)(int *))(v13 + 32))(a1: v34);
        distToPlayer = 0;
        *(float *)&distToPlayer = fsqrt(
                                    (float)((float)((float)(v14[1] - *(float *)(HIDWORD(v29) + 4))
                                                  * (float)(v14[1] - *(float *)(HIDWORD(v29) + 4)))
                                          + (float)((float)(v14[2] - *(float *)(HIDWORD(v29) + 8))
                                                  * (float)(v14[2] - *(float *)(HIDWORD(v29) + 8))))
                                  + (float)((float)(*v14 - *(float *)HIDWORD(v29))
                                          * (float)(*v14 - *(float *)HIDWORD(v29))));
        v29 = distToPlayer;
        ServerDTI_AddEntityEncodeEvent(pSendTable: v28, distToPlayer: *(float *)&distToPlayer);
      }
    }
  }
  m_nBits = m_pNewPack->m_nBits;
  if ( m_nBits >= 0 )
  {
    HIDWORD(v29) = m_pNewPack->m_pData;
    v33 = m_nBits & 0x7FFFFFFF;
  }
  else
  {
    HIDWORD(v29) = CBaseServer::UncompressPackedEntity(this: u->m_pServer, pPackedEntity: m_pNewPack, bits: &v33);
  }
  v34 = (int *)a3;
  v27 = (char *)a4;
  bf_write::bf_write(this: &v25);
  if ( u->m_bCullProps )
  {
    v34 = v24;
    CenterVertIndex = CCoreDispNode::GetCenterVertIndex(this: (CVTFTexture *)m_pNewPack);
    SamplePosition = (const CSendProxyRecipients *)CAudioMixerWave::GetSamplePosition(this: (CVTFTexture *)m_pNewPack);
    v21 = CCoreDispNode::GetCenterVertIndex(this: (CVTFTexture *)m_pOldPack);
    v17 = (const CSendProxyRecipients *)CAudioMixerWave::GetSamplePosition(this: (CVTFTexture *)m_pOldPack);
    v18 = SendTable_CullPropsFromProxies(
            pTable: v28,
            pStartProps: a3,
            nStartProps: a4,
            iClient: u->m_nClientEntity - 1,
            pOldStateProxies: v17,
            nOldStateProxies: v21,
            pNewStateProxies: SamplePosition,
            nNewStateProxies: CenterVertIndex,
            pOutProps: v24,
            nMaxOutProps: 4096);
  }
  else
  {
    m_pBuf = u->m_pBuf;
    v25.m_pData = m_pBuf->m_pData;
    v25.m_nDataBytes = m_pBuf->m_nDataBytes;
    v25.m_nDataBits = m_pBuf->m_nDataBits;
    v25.m_iCurBit = m_pBuf->m_iCurBit;
    *(_DWORD *)&v25.m_bOverflow = *(_DWORD *)&m_pBuf->m_bOverflow;
    m_pDebugName = m_pBuf->m_pDebugName;
    v18 = (int)v27;
    v25.m_pDebugName = m_pDebugName;
  }
  SendTable_WritePropList(
    pTable: v28,
    pState: (const void *)HIDWORD(v29),
    nBits: v33,
    pOut: u->m_pBuf,
    objectID: m_pNewPack->m_nEntityIndex,
    pCheckProps: v34,
    nCheckProps: v18);
  if ( !u->m_bCullProps && hltv != nullptr )
    CDeltaEntityCache::AddDeltaBits(
      this: &hltv->m_DeltaCache,
      nEntityIndex: m_pNewPack->m_nEntityIndex,
      nDeltaTick: u->m_pFromSnapshot->m_nTickCount,
      nBits: u->m_pBuf->m_iCurBit - v25.m_iCurBit,
      pBuffer: &v25);
  if ( g_bServerDTIEnabled && v30 != nullptr )
  {
    v27 = (char *)&v29 + 8;
    *((_QWORD *)&v29 + 1) = __rdtsc();
    v32.m_Int64 = *((_QWORD *)&v29 + 1) - v32.m_Int64;
    _ServerDTI_HookTimer(pSendTable: v30, timerType: v31, count: &v32);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1011D7E0
// Name: SV_DetermineUpdateType
// Source: json
//------------------------------------------------------------------------------
void __thiscall SV_DetermineUpdateType(CEntityWriteInfo *u)
{
  int m_nNewEntity; // esi
  int m_nOldEntity; // eax
  CFrameSnapshot *m_pFromSnapshot; // edx
  unsigned __int8 *DeltaBits; // esi
  int PropsChangedAfterTick; // esi
  PackedEntity *m_pOldPack; // ecx
  int m_nBits; // eax
  const char *m_pData; // esi
  PackedEntity *m_pNewPack; // eax
  int v11; // ecx
  const char *v12; // eax
  int iOutProps[4096]; // [esp+8h] [ebp-4008h] BYREF
  int bits; // [esp+4008h] [ebp-8h] BYREF
  int nBits; // [esp+400Ch] [ebp-4h] BYREF
  int savedregs; // [esp+4010h] [ebp+0h] BYREF

  m_nNewEntity = u->m_nNewEntity;
  m_nOldEntity = u->m_nOldEntity;
  if ( m_nNewEntity < m_nOldEntity )
    goto LABEL_2;
  if ( m_nNewEntity > m_nOldEntity )
  {
    u->m_UpdateType = LeavePVS;
    return;
  }
  if ( SV_NeedsExplicitCreate(a1: (int)u, u) )
  {
LABEL_2:
    u->m_UpdateType = EnterPVS;
    return;
  }
  if ( u->m_pOldPack != u->m_pNewPack )
  {
    if ( !u->m_bCullProps
      && hltv != nullptr
      && (m_pFromSnapshot = u->m_pFromSnapshot,
          nBits = 0,
          (DeltaBits = CDeltaEntityCache::FindDeltaBits(
                         this: &hltv->m_DeltaCache,
                         nEntityIndex: m_nNewEntity,
                         nDeltaTick: m_pFromSnapshot->m_nTickCount,
                         &nBits)) != nullptr) )
    {
      if ( nBits > 0 )
      {
        SV_WriteDeltaHeader(u, entnum: u->m_nNewEntity, flags: 0);
        bf_write::WriteBits(this: u->m_pBuf, pInData: DeltaBits, nBits);
        u->m_UpdateType = DeltaEnt;
        return;
      }
    }
    else
    {
      PropsChangedAfterTick = PackedEntity::GetPropsChangedAfterTick(
                                this: u->m_pNewPack,
                                iTick: u->m_pFromSnapshot->m_nTickCount,
                                iOutProps,
                                nMaxOutProps: 4096);
      if ( PropsChangedAfterTick == -1 )
      {
        m_pOldPack = u->m_pOldPack;
        m_nBits = m_pOldPack->m_nBits;
        if ( m_nBits >= 0 )
        {
          m_pData = (const char *)m_pOldPack->m_pData;
          bits = m_nBits & 0x7FFFFFFF;
        }
        else
        {
          m_pData = CBaseServer::UncompressPackedEntity(this: u->m_pServer, pPackedEntity: m_pOldPack, &bits);
        }
        m_pNewPack = u->m_pNewPack;
        v11 = m_pNewPack->m_nBits;
        if ( v11 >= 0 )
        {
          v12 = (const char *)m_pNewPack->m_pData;
          nBits = v11 & 0x7FFFFFFF;
        }
        else
        {
          v12 = CBaseServer::UncompressPackedEntity(this: u->m_pServer, pPackedEntity: m_pNewPack, bits: &nBits);
        }
        PropsChangedAfterTick = SendTable_CalcDelta(
                                  pTable: u->m_pOldPack->m_pServerClass->m_pTable,
                                  pFromState: m_pData,
                                  nFromBits: bits,
                                  pToState: v12,
                                  nToBits: nBits,
                                  pDeltaProps: iOutProps,
                                  nMaxDeltaProps: 4096,
                                  objectID: u->m_nNewEntity);
      }
      if ( PropsChangedAfterTick > 0 )
      {
        SV_WriteDeltaHeader(u, entnum: u->m_nNewEntity, flags: 0);
        SV_WritePropsFromPackedEntity(u, a2: (int)&savedregs, a3: iOutProps, a4: PropsChangedAfterTick);
        u->m_UpdateType = DeltaEnt;
        return;
      }
      if ( !u->m_bCullProps && hltv != nullptr )
        CDeltaEntityCache::AddDeltaBits(
          this: &hltv->m_DeltaCache,
          nEntityIndex: u->m_nNewEntity,
          nDeltaTick: u->m_pFromSnapshot->m_nTickCount,
          nBits: 0,
          pBuffer: nullptr);
    }
  }
  u->m_UpdateType = PreserveEnt;
}

//------------------------------------------------------------------------------
// Address: 0x1011D9B0
// Name: SV_WriteDeletions
// Source: json
//------------------------------------------------------------------------------
int __usercall SV_WriteDeletions@<eax>(CEntityWriteInfo *u@<edi>)
{
  CFrameSnapshot *m_pToSnapshot; // edx
  unsigned int v3; // ebx
  CFrameSnapshot *m_pFromSnapshot; // esi
  int m_Size; // edx
  int v6; // eax
  int *m_pMemory; // ecx
  CFrameSnapshotEntry *v8; // ecx
  CFrameSnapshotEntry *v9; // eax
  bf_write *m_pBuf; // eax
  int m_iCurBit; // ecx
  bf_write *v12; // eax
  int v13; // ecx
  int v14; // [esp+4h] [ebp-10h]
  int nNumDeletions; // [esp+8h] [ebp-Ch]
  CFrameSnapshot *pSnapShot; // [esp+Ch] [ebp-8h]
  int v17; // [esp+10h] [ebp-4h]

  if ( !u->m_bAsDelta )
    return 0;
  m_pToSnapshot = u->m_pToSnapshot;
  v3 = 0;
  nNumDeletions = 0;
  pSnapShot = m_pToSnapshot;
  if ( m_pToSnapshot->m_nNumEntities > 0 )
  {
    v17 = 0;
    while ( 1 )
    {
      v14 = 1 << (v3 & 0x1F);
      if ( (v14 & u->m_DeletionFlags.m_Ints[v3 >> 5]) == 0 )
      {
        m_pFromSnapshot = u->m_pFromSnapshot;
        if ( m_pToSnapshot->m_pEntities[v17].m_pClass == nullptr
          && (signed int)v3 < m_pFromSnapshot->m_nNumEntities
          && m_pFromSnapshot->m_pEntities[v17].m_pClass != nullptr )
        {
          goto LABEL_21;
        }
        if ( u->m_pTo != nullptr )
          break;
      }
LABEL_27:
      ++v17;
      if ( (signed int)++v3 >= m_pToSnapshot->m_nNumEntities )
        goto LABEL_28;
    }
    m_Size = m_pToSnapshot->m_iExplicitDeleteSlots.m_Size;
    v6 = 0;
    if ( m_Size <= 0 )
    {
LABEL_14:
      v6 = -1;
    }
    else
    {
      m_pMemory = pSnapShot->m_iExplicitDeleteSlots.m_Memory.m_pMemory;
      while ( *m_pMemory != v3 )
      {
        ++v6;
        ++m_pMemory;
        if ( v6 >= m_Size )
          goto LABEL_14;
      }
    }
    if ( v6 != -1 )
    {
      if ( (v8 = &u->m_pToSnapshot->m_pEntities[v17], (v9 = &m_pFromSnapshot->m_pEntities[v17]) == nullptr)
        || v8 == nullptr
        || v9->m_pClass != nullptr && v9->m_nSerialNumber == v8->m_nSerialNumber
        || (v14 & u->m_pTo->transmit_entity.m_Ints[v3 >> 5]) == 0 )
      {
LABEL_21:
        m_pBuf = u->m_pBuf;
        m_iCurBit = m_pBuf->m_iCurBit;
        if ( m_iCurBit + 1 > m_pBuf->m_nDataBits )
          m_pBuf->m_bOverflow = true;
        if ( !m_pBuf->m_bOverflow )
        {
          m_pBuf->m_pData[m_iCurBit >> 3] |= 1 << (m_iCurBit & 7);
          ++m_pBuf->m_iCurBit;
        }
        bf_write::WriteUBitLong(this: u->m_pBuf, curData: v3, numbits: 11, bCheckRange: true);
        ++nNumDeletions;
      }
    }
    m_pToSnapshot = pSnapShot;
    goto LABEL_27;
  }
LABEL_28:
  v12 = u->m_pBuf;
  v13 = v12->m_iCurBit;
  if ( v13 + 1 > v12->m_nDataBits )
    v12->m_bOverflow = true;
  if ( !v12->m_bOverflow )
  {
    v12->m_pData[v13 >> 3] &= ~(1 << (v13 & 7));
    ++v12->m_iCurBit;
  }
  return nNumDeletions;
}

//------------------------------------------------------------------------------
// Address: 0x1011DB50
// Name: public: virtual void CBaseServer::WriteDeltaEntities(class CBaseClient __near *,class CClientFrame __near *,class CClientFrame __near *,class bf_write __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseServer::WriteDeltaEntities(
        CBaseServer *this,
        CBaseClient *client,
        CClientFrame *to,
        CClientFrame *from,
        bf_write *pBuf)
{
  CFrameSnapshot *m_pSnapshot; // ecx
  CBaseClient *v7; // esi
  CFrameSnapshot *m_pBaseline; // edx
  int m_nEntityIndex; // eax
  CBaseServer_vtbl *v11; // edx
  bool (__thiscall *IsHLTV)(struct CBaseServer *); // eax
  CFrameSnapshot *v13; // edx
  bool v14; // zf
  int m_iCurBit; // ecx
  unsigned __int8 *m_pData; // edx
  int m_nDataBytes; // eax
  const char *m_pDebugName; // ecx
  int v19; // edx
  int v20; // eax
  int NextSetBit; // esi
  int m_nNewEntity; // edi
  int v23; // eax
  int v24; // edi
  IServerNetworkable *m_pNetworkable; // ecx
  const char *v26; // eax
  IServerNetworkable *v27; // ecx
  const char *v28; // eax
  CEntityWriteInfo u; // [esp+Ch] [ebp-164h] BYREF
  bf_write savepos; // [esp+158h] [ebp-18h] BYREF
  int startbit; // [esp+180h] [ebp+10h]
  bool bIsTracing_3; // [esp+187h] [ebp+17h]

  memset(&u.m_nOldEntity, 255, 12);
  u.__vftable = (CEntityWriteInfo_vtbl *)&CEntityWriteInfo::`vftable';
  memset(dst: (unsigned __int8 *)&u.m_DeletionFlags, value: 0, count: sizeof(u.m_DeletionFlags));
  m_pSnapshot = to->m_pSnapshot;
  v7 = client;
  m_pBaseline = client->m_pBaseline;
  u.m_pTo = to;
  m_nEntityIndex = client->m_nEntityIndex;
  u.m_pBaseline = m_pBaseline;
  v11 = this->__vftable;
  u.m_pToSnapshot = m_pSnapshot;
  u.m_nClientEntity = m_nEntityIndex;
  IsHLTV = v11->IsHLTV;
  u.m_pBuf = pBuf;
  u.m_nFullProps = 0;
  u.m_pServer = this;
  u.m_bCullProps = !IsHLTV(this) || sv.m_State >= ss_active;
  if ( from != nullptr )
  {
    v13 = from->m_pSnapshot;
    u.m_bAsDelta = true;
    u.m_pFrom = from;
    u.m_pFromSnapshot = v13;
  }
  else
  {
    u.m_bAsDelta = false;
    u.m_pFrom = nullptr;
    u.m_pFromSnapshot = nullptr;
  }
  v14 = client->m_nBaselineUpdateTick == -1;
  u.m_nHeaderCount = 0;
  if ( v14 )
  {
    if ( client != (CBaseClient *)-256 )
      memset(dst: (unsigned __int8 *)&client->m_BaselinesSent, value: 0, count: sizeof(client->m_BaselinesSent));
    to->from_baseline = &client->m_BaselinesSent;
  }
  bf_write::WriteUBitLong(this: pBuf, curData: 0x1Au, numbits: 6, bCheckRange: true);
  bf_write::WriteUBitLong(this: pBuf, curData: u.m_pToSnapshot->m_nNumEntities, numbits: 11, bCheckRange: true);
  m_iCurBit = pBuf->m_iCurBit;
  if ( u.m_bAsDelta )
  {
    if ( m_iCurBit + 1 > pBuf->m_nDataBits )
      pBuf->m_bOverflow = true;
    if ( !pBuf->m_bOverflow )
    {
      pBuf->m_pData[m_iCurBit >> 3] |= 1 << (m_iCurBit & 7);
      ++pBuf->m_iCurBit;
    }
    bf_write::WriteLong(this: pBuf, val: u.m_pFrom->tick_count);
  }
  else
  {
    if ( m_iCurBit + 1 > pBuf->m_nDataBits )
      pBuf->m_bOverflow = true;
    if ( !pBuf->m_bOverflow )
    {
      pBuf->m_pData[m_iCurBit >> 3] &= ~(1 << (m_iCurBit & 7));
      ++pBuf->m_iCurBit;
    }
  }
  bf_write::WriteUBitLong(this: pBuf, curData: client->m_nBaselineUsed, numbits: 1, bCheckRange: true);
  m_pData = pBuf->m_pData;
  m_nDataBytes = pBuf->m_nDataBytes;
  savepos.m_nDataBits = pBuf->m_nDataBits;
  m_pDebugName = pBuf->m_pDebugName;
  savepos.m_pData = m_pData;
  v19 = pBuf->m_iCurBit;
  savepos.m_nDataBytes = m_nDataBytes;
  v20 = *(_DWORD *)&pBuf->m_bOverflow;
  savepos.m_pDebugName = m_pDebugName;
  savepos.m_iCurBit = v19;
  *(_DWORD *)&savepos.m_bOverflow = v20;
  bf_write::WriteUBitLong(this: pBuf, curData: 0, numbits: 32, bCheckRange: true);
  startbit = pBuf->m_iCurBit;
  bIsTracing_3 = CBaseClient::IsTracing(this: client);
  if ( bIsTracing_3 )
    CBaseClient::TraceNetworkData(this: client, msg: pBuf, fmt: "Delta Entities Overhead");
  if ( g_pLocalNetworkBackdoor == nullptr )
  {
    if ( u.m_pFrom == nullptr
      || (NextSetBit = CFixedBitVecBase<2048>::FindNextSetBit(
                         this: &u.m_pFrom->transmit_entity,
                         startBit: u.m_nOldEntity + 1),
          u.m_nOldEntity = NextSetBit,
          NextSetBit < 0) )
    {
      NextSetBit = 9999;
      u.m_nOldEntity = 9999;
    }
    m_nNewEntity = CFixedBitVecBase<2048>::FindNextSetBit(this: &to->transmit_entity, startBit: u.m_nNewEntity + 1);
    u.m_nNewEntity = m_nNewEntity;
    if ( m_nNewEntity < 0 )
    {
      m_nNewEntity = 9999;
      u.m_nNewEntity = 9999;
    }
    while ( NextSetBit != 9999 )
    {
      if ( m_nNewEntity != 9999 )
        goto LABEL_43;
      u.m_pNewPack = nullptr;
LABEL_45:
      if ( NextSetBit == 9999 )
        u.m_pOldPack = nullptr;
      else
        u.m_pOldPack = CFrameSnapshotManager::GetPackedEntity(
                         this: framesnapshotmanager,
                         pSnapshot: u.m_pFromSnapshot,
                         entity: NextSetBit);
      SV_DetermineUpdateType(&u);
      switch ( u.m_UpdateType )
      {
        case EnterPVS:
          SV_WriteEnterPVS(&u);
          goto LABEL_50;
        case LeavePVS:
          SV_WriteLeavePVS(&u);
          goto LABEL_50;
        case DeltaEnt:
          if ( u.m_pFrom == nullptr
            || (NextSetBit = CFixedBitVecBase<2048>::FindNextSetBit(
                               this: &u.m_pFrom->transmit_entity,
                               startBit: u.m_nOldEntity + 1),
                u.m_nOldEntity = NextSetBit,
                NextSetBit < 0) )
          {
            NextSetBit = 9999;
            u.m_nOldEntity = 9999;
          }
          goto LABEL_60;
        case PreserveEnt:
          if ( u.m_pFrom == nullptr
            || (NextSetBit = CFixedBitVecBase<2048>::FindNextSetBit(
                               this: &u.m_pFrom->transmit_entity,
                               startBit: u.m_nOldEntity + 1),
                u.m_nOldEntity = NextSetBit,
                NextSetBit < 0) )
          {
            NextSetBit = 9999;
            u.m_nOldEntity = 9999;
          }
LABEL_60:
          m_nNewEntity = CFixedBitVecBase<2048>::FindNextSetBit(
                           this: &u.m_pTo->transmit_entity,
                           startBit: u.m_nNewEntity + 1);
          u.m_nNewEntity = m_nNewEntity;
          if ( m_nNewEntity < 0 )
          {
            m_nNewEntity = 9999;
            u.m_nNewEntity = 9999;
          }
          break;
        default:
LABEL_50:
          m_nNewEntity = u.m_nNewEntity;
          NextSetBit = u.m_nOldEntity;
          break;
      }
      if ( bIsTracing_3 )
      {
        if ( u.m_UpdateType != EnterPVS )
        {
          if ( u.m_UpdateType == LeavePVS )
          {
            CBaseClient::TraceNetworkData(
              this: client,
              msg: pBuf,
              fmt: "leave [%s]",
              u.m_pOldPack->m_pServerClass->m_pNetworkName);
          }
          else if ( u.m_UpdateType == DeltaEnt )
          {
            m_pNetworkable = sv.edicts[u.m_pOldPack->m_nEntityIndex].m_pNetworkable;
            v26 = m_pNetworkable->GetClassNameA(this: m_pNetworkable);
            CBaseClient::TraceNetworkData(this: client, msg: pBuf, fmt: "delta [%s]", v26);
          }
        }
        else
        {
          v27 = sv.edicts[u.m_pNewPack->m_nEntityIndex].m_pNetworkable;
          v28 = v27->GetClassNameA(this: v27);
          CBaseClient::TraceNetworkData(this: client, msg: pBuf, fmt: "enter [%s]", v28);
        }
      }
    }
    if ( m_nNewEntity == 9999 )
    {
      v23 = SV_WriteDeletions(&u);
      if ( bIsTracing_3 )
        CBaseClient::TraceNetworkData(this: client, msg: pBuf, fmt: "Delta: [%d] deletions", v23);
      v7 = client;
      goto LABEL_34;
    }
LABEL_43:
    u.m_pNewPack = CFrameSnapshotManager::GetPackedEntity(
                     this: framesnapshotmanager,
                     pSnapshot: u.m_pToSnapshot,
                     entity: m_nNewEntity);
    goto LABEL_45;
  }
LABEL_34:
  v24 = u.m_pBuf->m_iCurBit;
  bf_write::WriteUBitLong(this: &savepos, curData: u.m_nHeaderCount, numbits: 11, bCheckRange: true);
  bf_write::WriteUBitLong(this: &savepos, curData: v24 - startbit, numbits: 20, bCheckRange: true);
  if ( v7->m_nBaselineUpdateTick == -1 && (u.m_nFullProps > 0 || !u.m_bAsDelta) && u.m_pBaseline != nullptr )
  {
    if ( savepos.m_iCurBit + 1 <= savepos.m_nDataBits && !savepos.m_bOverflow )
      savepos.m_pData[savepos.m_iCurBit >> 3] |= 1 << (savepos.m_iCurBit & 7);
    v7->m_nBaselineUpdateTick = to->tick_count;
  }
  else if ( savepos.m_iCurBit + 1 <= savepos.m_nDataBits && !savepos.m_bOverflow )
  {
    savepos.m_pData[savepos.m_iCurBit >> 3] &= ~(1 << (savepos.m_iCurBit & 7));
  }
  if ( bIsTracing_3 )
    CBaseClient::TraceNetworkData(this: v7, msg: pBuf, fmt: "Delta Finish");
}

} // namespace engine_xlsp
