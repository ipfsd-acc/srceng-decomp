// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: engine/dt_common_eng.cpp
// Functions: 13
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x10167D50
// Name: void DataTable_ClearWriteFlags_R(class SendTable __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DataTable_ClearWriteFlags_R(SendTable *pTable)
{
  int v1; // ebx
  int v2; // edi

  *((_BYTE *)pTable + 16) &= ~2u;
  v1 = 0;
  if ( pTable->m_nProps > 0 )
  {
    v2 = 0;
    do
    {
      if ( pTable->m_pProps[v2].m_Type == DPT_DataTable )
        DataTable_ClearWriteFlags_R(pTable: pTable->m_pProps[v2].m_pDataTable);
      ++v1;
      ++v2;
    }
    while ( v1 < pTable->m_nProps );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10167D90
// Name: void DataTable_ClearWriteFlags(class ServerClass __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DataTable_ClearWriteFlags(ServerClass *pClasses)
{
  ServerClass *i; // edi
  SendTable *m_pTable; // ecx
  int v3; // edx
  int v4; // esi

  for ( i = pClasses; i != nullptr; i = i->m_pNext )
  {
    m_pTable = i->m_pTable;
    *((_BYTE *)m_pTable + 16) &= ~2u;
    v3 = 0;
    if ( m_pTable->m_nProps > 0 )
    {
      v4 = 0;
      do
      {
        if ( m_pTable->m_pProps[v4].m_Type == DPT_DataTable )
          DataTable_ClearWriteFlags_R(pTable: m_pTable->m_pProps[v4].m_pDataTable);
        ++v3;
        ++v4;
      }
      while ( v3 < m_pTable->m_nProps );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10167DE0
// Name: void DataTable_WriteClassInfosBuffer(class ServerClass __near *,class bf_write __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DataTable_WriteClassInfosBuffer(ServerClass *pClasses, bf_write *pBuf)
{
  ServerClass *v2; // esi
  int v3; // ecx
  ServerClass *i; // eax

  v2 = pClasses;
  v3 = 0;
  for ( i = pClasses; i != nullptr; ++v3 )
    i = i->m_pNext;
  bf_write::WriteShort(this: pBuf, val: v3);
  if ( pClasses != nullptr )
  {
    do
    {
      bf_write::WriteShort(this: pBuf, val: v2->m_ClassID);
      bf_write::WriteString(this: pBuf, pStr: v2->m_pNetworkName);
      bf_write::WriteString(this: pBuf, pStr: v2->m_pTable->m_pNetTableName);
      v2 = v2->m_pNext;
    }
    while ( v2 != nullptr );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10167E40
// Name: bool DataTable_ParseClassInfosFromBuffer(class CClientState __near *,class bf_read __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl DataTable_ParseClassInfosFromBuffer(CClientState *pState, bf_read *pBuf)
{
  C_ServerClassInfo *m_pServerClasses; // eax
  int *p_m_InstanceBaselineIndex; // ebx
  C_ServerClassInfo *v4; // esi
  int j; // edi
  int m_nBitsAvail; // ecx
  unsigned int v8; // eax
  __int16 v9; // dx
  int v10; // ecx
  const unsigned int *v11; // ecx
  unsigned int v12; // ecx
  const unsigned int *m_pBufferEnd; // edx
  unsigned int m_nInBufWord; // edi
  const unsigned int *m_pDataIn; // ecx
  unsigned int v16; // edx
  unsigned int v17; // ebx
  unsigned int v18; // edx
  int v19; // edi
  int v20; // ecx
  _DWORD *v21; // eax
  C_ServerClassInfo *v22; // eax
  int v23; // edi
  C_ServerClassInfo *v24; // ebx
  int v26; // ecx
  unsigned int v27; // eax
  __int16 v28; // dx
  int v29; // ecx
  const unsigned int *v30; // ecx
  unsigned int v31; // ecx
  const unsigned int *v32; // edx
  unsigned int v33; // edi
  const unsigned int *v34; // ecx
  unsigned int v35; // edx
  unsigned int v36; // ebx
  unsigned int v37; // edx
  int v38; // edi
  C_ServerClassInfo *v39; // ebx
  C_ServerClassInfo *v40; // ebx
  int i; // [esp+18h] [ebp+Ch]
  int ia; // [esp+18h] [ebp+Ch]

  m_pServerClasses = pState->m_pServerClasses;
  if ( m_pServerClasses != nullptr )
  {
    p_m_InstanceBaselineIndex = &m_pServerClasses[-1].m_InstanceBaselineIndex;
    v4 = &m_pServerClasses[m_pServerClasses[-1].m_InstanceBaselineIndex];
    for ( j = m_pServerClasses[-1].m_InstanceBaselineIndex - 1; j >= 0; --j )
      C_ServerClassInfo::~C_ServerClassInfo(this: --v4);
    free(pMem: p_m_InstanceBaselineIndex);
  }
  m_nBitsAvail = pBuf->m_nBitsAvail;
  if ( m_nBitsAvail < 16 )
  {
    m_pBufferEnd = pBuf->m_pBufferEnd;
    m_nInBufWord = pBuf->m_nInBufWord;
    v8 = 16 - m_nBitsAvail;
    m_pDataIn = pBuf->m_pDataIn;
    if ( m_pDataIn == m_pBufferEnd )
    {
      pBuf->m_nBitsAvail = 1;
      pBuf->m_nInBufWord = 0;
      pBuf->m_bOverflow = true;
    }
    else
    {
      if ( m_pDataIn > m_pBufferEnd )
      {
        pBuf->m_bOverflow = true;
        pBuf->m_nInBufWord = 0;
        goto LABEL_20;
      }
      pBuf->m_nInBufWord = *m_pDataIn;
    }
    pBuf->m_pDataIn = m_pDataIn + 1;
LABEL_20:
    if ( pBuf->m_bOverflow )
    {
      LOWORD(v8) = 0;
    }
    else
    {
      v16 = pBuf->m_nInBufWord;
      v17 = (v16 & CBitBuffer::s_nMaskTable[v8]) << pBuf->m_nBitsAvail;
      pBuf->m_nBitsAvail = 32 - v8;
      v18 = v16 >> v8;
      LOWORD(v8) = v17 | m_nInBufWord;
      pBuf->m_nInBufWord = v18;
    }
    goto LABEL_23;
  }
  v8 = pBuf->m_nInBufWord;
  v9 = v8;
  v10 = m_nBitsAvail - 16;
  pBuf->m_nBitsAvail = v10;
  if ( v10 != 0 )
  {
    pBuf->m_nInBufWord = HIWORD(v8);
  }
  else
  {
    v8 = (unsigned int)pBuf->m_pDataIn;
    v11 = pBuf->m_pBufferEnd;
    pBuf->m_nBitsAvail = 32;
    if ( (const unsigned int *)v8 == v11 )
    {
      pBuf->m_pDataIn = (const unsigned int *)(v8 + 4);
      pBuf->m_nBitsAvail = 1;
      pBuf->m_nInBufWord = 0;
      LOWORD(v8) = v9;
    }
    else
    {
      if ( v8 <= (unsigned int)v11 )
      {
        v12 = *(_DWORD *)v8;
        pBuf->m_pDataIn = (const unsigned int *)(v8 + 4);
        pBuf->m_nInBufWord = v12;
      }
      else
      {
        pBuf->m_bOverflow = true;
        pBuf->m_nInBufWord = 0;
      }
      LOWORD(v8) = v9;
    }
  }
LABEL_23:
  v19 = (__int16)v8;
  pState->m_nServerClasses = (__int16)v8;
  v20 = (unsigned __int64)(unsigned int)(__int16)v8 >> 28 != 0 ? -1 : 16 * (__int16)v8;
  v21 = MemAlloc_Alloc(nSize: __CFADD__(v20, 4) ? -1 : v20 + 4);
  if ( v21 != nullptr )
  {
    *v21 = v19;
    v22 = (C_ServerClassInfo *)(v21 + 1);
    v23 = v19 - 1;
    i = (int)v22;
    v24 = v22;
    if ( v23 >= 0 )
    {
      do
      {
        C_ServerClassInfo::C_ServerClassInfo(this: v24++);
        --v23;
      }
      while ( v23 >= 0 );
      v22 = (C_ServerClassInfo *)i;
    }
  }
  else
  {
    v22 = nullptr;
  }
  pState->m_pServerClasses = v22;
  if ( v22 == nullptr )
  {
    Host_EndGame(
      bShowMainMenu: true,
      message: "CL_ParseClassInfo: can't allocate %d C_ServerClassInfos.\n",
      pState->m_nServerClasses);
    return 0;
  }
  ia = 0;
  if ( pState->m_nServerClasses <= 0 )
    return 1;
  while ( 1 )
  {
    v26 = pBuf->m_nBitsAvail;
    if ( v26 < 16 )
    {
      v32 = pBuf->m_pBufferEnd;
      v33 = pBuf->m_nInBufWord;
      v27 = 16 - v26;
      v34 = pBuf->m_pDataIn;
      if ( v34 == v32 )
      {
        pBuf->m_nBitsAvail = 1;
        pBuf->m_nInBufWord = 0;
        pBuf->m_bOverflow = true;
      }
      else
      {
        if ( v34 > v32 )
        {
          pBuf->m_bOverflow = true;
          pBuf->m_nInBufWord = 0;
          goto LABEL_48;
        }
        pBuf->m_nInBufWord = *v34;
      }
      pBuf->m_pDataIn = v34 + 1;
LABEL_48:
      if ( pBuf->m_bOverflow )
      {
        LOWORD(v27) = 0;
      }
      else
      {
        v35 = pBuf->m_nInBufWord;
        v36 = (v35 & CBitBuffer::s_nMaskTable[v27]) << pBuf->m_nBitsAvail;
        pBuf->m_nBitsAvail = 32 - v27;
        v37 = v35 >> v27;
        LOWORD(v27) = v36 | v33;
        pBuf->m_nInBufWord = v37;
      }
      goto LABEL_51;
    }
    v27 = pBuf->m_nInBufWord;
    v28 = v27;
    v29 = v26 - 16;
    pBuf->m_nBitsAvail = v29;
    if ( v29 != 0 )
    {
      pBuf->m_nInBufWord = HIWORD(v27);
    }
    else
    {
      v27 = (unsigned int)pBuf->m_pDataIn;
      v30 = pBuf->m_pBufferEnd;
      pBuf->m_nBitsAvail = 32;
      if ( (const unsigned int *)v27 == v30 )
      {
        pBuf->m_pDataIn = (const unsigned int *)(v27 + 4);
        pBuf->m_nBitsAvail = 1;
        pBuf->m_nInBufWord = 0;
        LOWORD(v27) = v28;
      }
      else
      {
        if ( v27 <= (unsigned int)v30 )
        {
          v31 = *(_DWORD *)v27;
          pBuf->m_pDataIn = (const unsigned int *)(v27 + 4);
          pBuf->m_nInBufWord = v31;
        }
        else
        {
          pBuf->m_bOverflow = true;
          pBuf->m_nInBufWord = 0;
        }
        LOWORD(v27) = v28;
      }
    }
LABEL_51:
    if ( (__int16)v27 >= pState->m_nServerClasses )
      break;
    v38 = (__int16)v27;
    v39 = pState->m_pServerClasses;
    v39[v38].m_ClassName = CBitRead::ReadAndAllocateString(this: pBuf, pOverflow: nullptr);
    v40 = pState->m_pServerClasses;
    v40[v38].m_DatatableName = CBitRead::ReadAndAllocateString(this: pBuf, pOverflow: nullptr);
    if ( ++ia >= pState->m_nServerClasses )
      return 1;
  }
  Host_EndGame(
    bShowMainMenu: true,
    message: "DataTable_ParseClassInfosFromBuffer: invalid class index (%d).\n",
    (__int16)v27);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10168150
// Name: bool DataTable_LoadDataTablesFromBuffer(class bf_read __near *,int)
// Source: json
//------------------------------------------------------------------------------
char __cdecl DataTable_LoadDataTablesFromBuffer(bf_read *pBuf, int nDemoProtocol)
{
  unsigned int m_nInBufWord; // eax
  int v3; // edx
  bool v4; // zf
  const unsigned int *m_pDataIn; // eax
  const unsigned int *m_pBufferEnd; // ecx
  unsigned int v7; // eax
  int v8; // ecx
  const unsigned int *v9; // eax
  const unsigned int *v10; // edx
  CClientState *BaseLocalClient; // eax

  while ( 1 )
  {
    m_nInBufWord = pBuf->m_nInBufWord;
    v3 = m_nInBufWord & 1;
    v4 = pBuf->m_nBitsAvail-- == 1;
    if ( v4 )
    {
      m_pDataIn = pBuf->m_pDataIn;
      m_pBufferEnd = pBuf->m_pBufferEnd;
      pBuf->m_nBitsAvail = 32;
      if ( m_pDataIn == m_pBufferEnd )
      {
        pBuf->m_nBitsAvail = 1;
        pBuf->m_nInBufWord = 0;
        pBuf->m_pDataIn = m_pDataIn + 1;
      }
      else if ( m_pDataIn <= m_pBufferEnd )
      {
        pBuf->m_nInBufWord = *m_pDataIn;
        pBuf->m_pDataIn = m_pDataIn + 1;
      }
      else
      {
        pBuf->m_bOverflow = true;
        pBuf->m_nInBufWord = 0;
      }
    }
    else
    {
      pBuf->m_nInBufWord = m_nInBufWord >> 1;
    }
    if ( v3 == 0 )
      break;
    v7 = pBuf->m_nInBufWord;
    v8 = v7 & 1;
    v4 = pBuf->m_nBitsAvail-- == 1;
    if ( v4 )
    {
      v9 = pBuf->m_pDataIn;
      v10 = pBuf->m_pBufferEnd;
      pBuf->m_nBitsAvail = 32;
      if ( v9 == v10 )
      {
        pBuf->m_nBitsAvail = 1;
        pBuf->m_nInBufWord = 0;
        pBuf->m_pDataIn = v9 + 1;
      }
      else if ( v9 <= v10 )
      {
        pBuf->m_nInBufWord = *v9;
        pBuf->m_pDataIn = v9 + 1;
      }
      else
      {
        pBuf->m_bOverflow = true;
        pBuf->m_nInBufWord = 0;
      }
    }
    else
    {
      pBuf->m_nInBufWord = v7 >> 1;
    }
    if ( !RecvTable_RecvClassInfos(pBuf, bNeedsDecoder: v8 != 0, nDemoProtocol) )
    {
      Host_Error(error: "DataTable_ParseClientTablesFromBuffer failed.\n");
      return 0;
    }
  }
  BaseLocalClient = GetBaseLocalClient();
  return DataTable_ParseClassInfosFromBuffer(pState: BaseLocalClient, pBuf);
}

//------------------------------------------------------------------------------
// Address: 0x10168330
// Name: void DataTable_CreateClientClassInfosFromServerClasses(class CBaseClientState __near *)
// Source: json
//------------------------------------------------------------------------------
void __usercall DataTable_CreateClientClassInfosFromServerClasses(int a1@<edi>, int a2@<esi>, CBaseClientState *pState)
{
  IServerGameDLL *v3; // ecx
  int v4; // eax
  int v5; // esi
  C_ServerClassInfo *m_pServerClasses; // eax
  int *p_m_InstanceBaselineIndex; // ecx
  C_ServerClassInfo *v8; // edi
  int v9; // ebx
  int v10; // ecx
  int *v11; // eax
  int v12; // esi
  C_ServerClassInfo *v13; // ebx
  C_ServerClassInfo *i; // edi
  C_ServerClassInfo *v15; // ecx
  CBaseClientState *v16; // eax
  ServerClass *v17; // esi
  int v18; // edi
  const char *m_pNetworkName; // edx
  C_ServerClassInfo *v20; // ebx
  C_ServerClassInfo *v21; // ebx
  ServerClass *pClasses; // [esp+0h] [ebp-8h]
  int *v23; // [esp+4h] [ebp-4h]

  v3 = serverGameDLL;
  if ( serverGameDLL == nullptr )
  {
    Sys_Error(error: "DataTable_CreateClientClassInfosFromServerClasses:  No serverGameDLL loaded!");
    v3 = serverGameDLL;
  }
  v4 = ((int (__thiscall *)(IServerGameDLL *, int, int))v3->GetAllServerClasses)(a1: v3, a2: a1, a3: a2);
  v5 = 0;
  for ( pClasses = (ServerClass *)v4; v4 != 0; ++v5 )
    v4 = *(_DWORD *)(v4 + 8);
  m_pServerClasses = pState->m_pServerClasses;
  if ( m_pServerClasses != nullptr )
  {
    p_m_InstanceBaselineIndex = &m_pServerClasses[-1].m_InstanceBaselineIndex;
    v8 = &m_pServerClasses[m_pServerClasses[-1].m_InstanceBaselineIndex];
    v9 = m_pServerClasses[-1].m_InstanceBaselineIndex - 1;
    v23 = &m_pServerClasses[-1].m_InstanceBaselineIndex;
    if ( v9 >= 0 )
    {
      do
      {
        C_ServerClassInfo::~C_ServerClassInfo(this: --v8);
        --v9;
      }
      while ( v9 >= 0 );
      p_m_InstanceBaselineIndex = v23;
    }
    free(pMem: p_m_InstanceBaselineIndex);
  }
  pState->m_nServerClasses = v5;
  v10 = (unsigned __int64)(unsigned int)v5 >> 28 != 0 ? -1 : 16 * v5;
  v11 = (int *)MemAlloc_Alloc(nSize: __CFADD__(v10, 4) ? -1 : v10 + 4);
  if ( v11 != nullptr )
  {
    *v11 = v5;
    v12 = v5 - 1;
    v13 = (C_ServerClassInfo *)(v11 + 1);
    for ( i = (C_ServerClassInfo *)(v11 + 1); v12 >= 0; --v12 )
      C_ServerClassInfo::C_ServerClassInfo(this: i++);
    v15 = v13;
  }
  else
  {
    v15 = nullptr;
  }
  v16 = pState;
  pState->m_pServerClasses = v15;
  if ( v15 != nullptr )
  {
    v17 = pClasses;
    v18 = 0;
    if ( pClasses != nullptr )
    {
      while ( 1 )
      {
        m_pNetworkName = v17->m_pNetworkName;
        v17->m_ClassID = v18;
        v20 = v16->m_pServerClasses;
        ++v18;
        v20[v17->m_ClassID].m_ClassName = COM_StringCopy(in: m_pNetworkName);
        v21 = pState->m_pServerClasses;
        v21[v17->m_ClassID].m_DatatableName = COM_StringCopy(in: v17->m_pTable->m_pNetTableName);
        v17 = v17->m_pNext;
        if ( v17 == nullptr )
          break;
        v16 = pState;
      }
    }
  }
  else
  {
    Host_EndGame(
      bShowMainMenu: true,
      message: "CL_ParseClassInfo: can't allocate %d C_ServerClassInfos.\n",
      pState->m_nServerClasses);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10168480
// Name: void DataTable_MaybeWriteSendTableBuffer(class SendTable __near *,class bf_write __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DataTable_MaybeWriteSendTableBuffer(SendTable *pTable, bf_write *pBuf, bool bNeedDecoder)
{
  char v3; // al
  int m_iCurBit; // ecx
  int v5; // ecx
  unsigned __int8 *v6; // esi
  char v7; // bl

  v3 = *((_BYTE *)pTable + 16);
  if ( (v3 & 2) == 0 )
  {
    *((_BYTE *)pTable + 16) = v3 | 2;
    m_iCurBit = pBuf->m_iCurBit;
    if ( m_iCurBit + 1 > pBuf->m_nDataBits )
      pBuf->m_bOverflow = true;
    if ( !pBuf->m_bOverflow )
    {
      pBuf->m_pData[m_iCurBit >> 3] |= 1 << (m_iCurBit & 7);
      ++pBuf->m_iCurBit;
    }
    v5 = pBuf->m_iCurBit;
    if ( v5 + 1 > pBuf->m_nDataBits )
      pBuf->m_bOverflow = true;
    if ( !pBuf->m_bOverflow )
    {
      v6 = &pBuf->m_pData[v5 >> 3];
      v7 = 1 << (v5 & 7);
      if ( bNeedDecoder )
      {
        *v6 |= v7;
        ++pBuf->m_iCurBit;
        SendTable_WriteInfos(pTable, pBuf);
        return;
      }
      *v6 &= ~v7;
      ++pBuf->m_iCurBit;
    }
    SendTable_WriteInfos(pTable, pBuf);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10168520
// Name: void DataTable_MaybeWriteSendTableBuffer_R(class SendTable __near *,class bf_write __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DataTable_MaybeWriteSendTableBuffer_R(SendTable *pTable, bf_write *pBuf)
{
  int v2; // ebx
  int v3; // edi

  DataTable_MaybeWriteSendTableBuffer(pTable, pBuf, bNeedDecoder: false);
  v2 = 0;
  if ( pTable->m_nProps > 0 )
  {
    v3 = 0;
    do
    {
      if ( pTable->m_pProps[v3].m_Type == DPT_DataTable )
        DataTable_MaybeWriteSendTableBuffer_R(pTable: pTable->m_pProps[v3].m_pDataTable, pBuf);
      ++v2;
      ++v3;
    }
    while ( v2 < pTable->m_nProps );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10168570
// Name: void DataTable_WriteSendTablesBuffer(class ServerClass __near *,class bf_write __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DataTable_WriteSendTablesBuffer(ServerClass *pClasses, bf_write *pBuf)
{
  ServerClass *v2; // ebx
  SendTable *m_pTable; // edi
  char v5; // al
  int m_iCurBit; // ecx
  int v7; // ecx
  SendTable *v8; // edi
  char v9; // al
  int v10; // ecx
  int v11; // ecx
  int v12; // ebx
  int v13; // ecx
  ServerClass *pCur; // [esp+14h] [ebp+8h]
  bf_write *pBufa; // [esp+18h] [ebp+Ch]

  v2 = pClasses;
  DataTable_ClearWriteFlags(pClasses);
  if ( pClasses != nullptr )
  {
    do
    {
      m_pTable = v2->m_pTable;
      v5 = *((_BYTE *)m_pTable + 16);
      if ( (v5 & 2) == 0 )
      {
        *((_BYTE *)m_pTable + 16) = v5 | 2;
        m_iCurBit = pBuf->m_iCurBit;
        if ( m_iCurBit + 1 > pBuf->m_nDataBits )
          pBuf->m_bOverflow = true;
        if ( !pBuf->m_bOverflow )
        {
          pBuf->m_pData[m_iCurBit >> 3] |= 1 << (m_iCurBit & 7);
          ++pBuf->m_iCurBit;
        }
        v7 = pBuf->m_iCurBit;
        if ( v7 + 1 > pBuf->m_nDataBits )
          pBuf->m_bOverflow = true;
        if ( !pBuf->m_bOverflow )
        {
          pBuf->m_pData[v7 >> 3] |= 1 << (v7 & 7);
          ++pBuf->m_iCurBit;
        }
        SendTable_WriteInfos(pTable: m_pTable, pBuf);
      }
      v2 = v2->m_pNext;
    }
    while ( v2 != nullptr );
    v2 = pClasses;
  }
  for ( pCur = v2; pCur != nullptr; pCur = pCur->m_pNext )
  {
    v8 = pCur->m_pTable;
    v9 = *((_BYTE *)v8 + 16);
    if ( (v9 & 2) == 0 )
    {
      *((_BYTE *)v8 + 16) = v9 | 2;
      v10 = pBuf->m_iCurBit;
      if ( v10 + 1 > pBuf->m_nDataBits )
        pBuf->m_bOverflow = true;
      if ( !pBuf->m_bOverflow )
      {
        pBuf->m_pData[v10 >> 3] |= 1 << (v10 & 7);
        ++pBuf->m_iCurBit;
      }
      v11 = pBuf->m_iCurBit;
      if ( v11 + 1 > pBuf->m_nDataBits )
        pBuf->m_bOverflow = true;
      if ( !pBuf->m_bOverflow )
      {
        pBuf->m_pData[v11 >> 3] &= ~(1 << (v11 & 7));
        ++pBuf->m_iCurBit;
      }
      SendTable_WriteInfos(pTable: v8, pBuf);
    }
    v12 = 0;
    for ( pBufa = nullptr; (int)pBufa < v8->m_nProps; pBufa = (bf_write *)((char *)pBufa + 1) )
    {
      if ( v8->m_pProps[v12].m_Type == DPT_DataTable )
        DataTable_MaybeWriteSendTableBuffer_R(pTable: v8->m_pProps[v12].m_pDataTable, pBuf);
      ++v12;
    }
  }
  v13 = pBuf->m_iCurBit;
  if ( v13 + 1 > pBuf->m_nDataBits )
    pBuf->m_bOverflow = true;
  if ( !pBuf->m_bOverflow )
  {
    pBuf->m_pData[v13 >> 3] &= ~(1 << (v13 & 7));
    ++pBuf->m_iCurBit;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10168B20
// Name: bool DataTable_SetupReceiveTableFromSendTable(class SendTable __near *,bool)
// Source: json
//------------------------------------------------------------------------------
char __cdecl DataTable_SetupReceiveTableFromSendTable(SendTable *sendTable, bool bNeedsDecoder)
{
  CClientSendTable *v2; // eax
  CRecvDecoder *v3; // ebx
  CClientSendTable *v4; // edi
  unsigned __int16 v5; // ax
  int v6; // esi
  UtlLinkedListElem_t<CClientSendTable *,unsigned short> *v7; // eax
  CRecvDecoder *v8; // eax
  unsigned __int16 v9; // ax
  int v10; // esi
  UtlLinkedListElem_t<CRecvDecoder *,unsigned short> *v11; // eax
  RecvTable *RecvTable; // eax
  int m_nProps; // esi
  int v15; // ecx
  int *v16; // eax
  SendProp *v17; // eax
  int v18; // esi
  SendProp *v19; // ebx
  int v20; // ecx
  int v21; // esi
  int v22; // ebx
  int v23; // eax
  SendProp *v24; // esi
  int v25; // edi
  int v26; // eax
  int v27; // eax
  SendTable *m_pDataTable; // ecx
  const char *m_pExcludeDTName; // eax
  CClientSendProp *pClientProp; // [esp+Ch] [ebp-8h]
  CClientSendTable *pClientSendTable; // [esp+10h] [ebp-4h]
  int iProp; // [esp+20h] [ebp+Ch]
  int iPropa; // [esp+20h] [ebp+Ch]
  int iPropb; // [esp+20h] [ebp+Ch]

  v2 = (CClientSendTable *)MemAlloc_Alloc(nSize: 0x28u);
  v3 = nullptr;
  if ( v2 != nullptr )
  {
    v4 = CClientSendTable::CClientSendTable(this: v2);
    pClientSendTable = v4;
  }
  else
  {
    pClientSendTable = nullptr;
    v4 = nullptr;
  }
  v5 = CUtlLinkedList<CClientSendTable *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CClientSendTable *,unsigned short>,unsigned short>>::AllocInternal(
         this: &g_ClientSendTables,
         multilist: false);
  v6 = v5;
  if ( v5 != 0xFFFF )
  {
    CUtlLinkedList<CClientSendTable *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CClientSendTable *,unsigned short>,unsigned short>>::LinkBefore(
      this: (CUtlLinkedList<unsigned int,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<unsigned int,unsigned short>,unsigned short> > *)&g_ClientSendTables,
      before: 0xFFFFu,
      elem: v5);
    v7 = &g_ClientSendTables.m_Memory.m_pMemory[v6];
    if ( v7 != nullptr )
      v7->m_Element = v4;
  }
  v4->m_SendTable.m_pNetTableName = COM_StringCopy(in: sendTable->m_pNetTableName);
  if ( bNeedsDecoder )
  {
    v8 = (CRecvDecoder *)MemAlloc_Alloc(nSize: 0x14Cu);
    if ( v8 != nullptr )
      v3 = CRecvDecoder::CRecvDecoder(this: v8);
    v9 = CUtlLinkedList<CRecvDecoder *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CRecvDecoder *,unsigned short>,unsigned short>>::AllocInternal(
           this: &g_RecvDecoders,
           multilist: false);
    v10 = v9;
    if ( v9 != 0xFFFF )
    {
      CUtlLinkedList<CClientSendTable *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CClientSendTable *,unsigned short>,unsigned short>>::LinkBefore(
        this: (CUtlLinkedList<unsigned int,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<unsigned int,unsigned short>,unsigned short> > *)&g_RecvDecoders,
        before: 0xFFFFu,
        elem: v9);
      v11 = &g_RecvDecoders.m_Memory.m_pMemory[v10];
      if ( v11 != nullptr )
        v11->m_Element = v3;
    }
    RecvTable = FindRecvTable(pName: v4->m_SendTable.m_pNetTableName);
    if ( RecvTable == nullptr )
    {
      DataTable_Warning(pInMessage: "No matching RecvTable for SendTable '%s'.\n", v4->m_SendTable.m_pNetTableName);
      return 0;
    }
    RecvTable->m_pDecoder = v3;
    v3->m_pTable = RecvTable;
    v3->m_pClientSendTable = v4;
    v3->m_Precalc.m_pSendTable = &v4->m_SendTable;
    v4->m_SendTable.m_pPrecalc = &v3->m_Precalc;
    SetupArrayProps_R<RecvTable,RecvProp>(pTable: RecvTable);
  }
  m_nProps = sendTable->m_nProps;
  v4->m_SendTable.m_nProps = m_nProps;
  if ( m_nProps != 0
    && (v15 = (84 * (unsigned __int64)(unsigned int)m_nProps) >> 32 != 0 ? -1 : 84 * m_nProps,
        (v16 = (int *)MemAlloc_Alloc(nSize: __CFADD__(v15, 4) ? -1 : v15 + 4)) != nullptr) )
  {
    *v16 = m_nProps;
    v17 = (SendProp *)(v16 + 1);
    v18 = m_nProps - 1;
    iProp = (int)v17;
    v19 = v17;
    if ( v18 >= 0 )
    {
      do
      {
        SendProp::SendProp(this: v19++);
        --v18;
      }
      while ( v18 >= 0 );
      v17 = (SendProp *)iProp;
    }
  }
  else
  {
    v17 = nullptr;
  }
  v20 = v4->m_SendTable.m_nProps;
  v4->m_SendTable.m_pProps = v17;
  v21 = v4->m_Props.m_Size - 1;
  for ( iPropa = v20; v21 >= 0; --v21 )
    ICvar::Iterator::~Iterator(this: (ICvar::Iterator *)&v4->m_Props.m_Memory.m_pMemory[v21]);
  v4->m_Props.m_Size = 0;
  CUtlVector<CClientSendProp,CUtlMemory<CClientSendProp,int>>::InsertMultipleBefore(
    this: &v4->m_Props,
    elem: 0,
    num: iPropa);
  iPropb = 0;
  if ( v4->m_SendTable.m_nProps > 0 )
  {
    v22 = 0;
    while ( 1 )
    {
      v23 = (int)&v4->m_Props.m_Memory.m_pMemory[iPropb];
      v24 = &sendTable->m_pProps[v22];
      v25 = (int)&v4->m_SendTable.m_pProps[v22];
      pClientProp = (CClientSendProp *)v23;
      *(_DWORD *)(v25 + 8) = v24->m_Type;
      *(_DWORD *)(v25 + 48) = COM_StringCopy(in: v24->m_pVarName);
      *(_DWORD *)(v25 + 60) = v24->m_Flags;
      *(_BYTE *)(v25 + 56) = v24->m_priority;
      v26 = _CommandLine();
      if ( (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v26 + 40))(a1: v26, a2: "-dti") != 0
        && v24->m_pParentArrayPropName != nullptr )
      {
        *(_DWORD *)(v25 + 44) = COM_StringCopy(in: v24->m_pParentArrayPropName);
      }
      v27 = *(_DWORD *)(v25 + 8);
      if ( v27 == 6 )
      {
        m_pDataTable = v24->m_pDataTable;
        m_pExcludeDTName = v24->m_pExcludeDTName;
        if ( m_pDataTable != nullptr )
          m_pExcludeDTName = m_pDataTable->m_pNetTableName;
        pClientProp->m_pTableName = COM_StringCopy(in: m_pExcludeDTName);
        *(_DWORD *)(v25 + 68) = v24->m_DataTableProxyFn;
        *(_DWORD *)(v25 + 76) = v24->m_Offset & 0xFFFFF;
      }
      else if ( (*(_DWORD *)(v25 + 60) & 0x40) != 0 )
      {
        *(_DWORD *)(v25 + 40) = COM_StringCopy(in: v24->m_pExcludeDTName);
      }
      else if ( v27 == 5 )
      {
        *(_DWORD *)(v25 + 32) = v24->m_nElements;
      }
      else
      {
        *(float *)(v25 + 16) = v24->m_fLowValue;
        *(float *)(v25 + 20) = v24->m_fHighValue;
        *(_DWORD *)(v25 + 12) = v24->m_nBits;
      }
      ++v22;
      if ( ++iPropb >= pClientSendTable->m_SendTable.m_nProps )
        break;
      v4 = pClientSendTable;
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10168DD0
// Name: void DataTable_MaybeCreateReceiveTable(class CUtlVector<class SendTable __near *,class CUtlMemory<class SendTable __near *,int>> __near &,class SendTable __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DataTable_MaybeCreateReceiveTable(
        CUtlVector<SendTable *,CUtlMemory<SendTable *,int> > *visited,
        SendTable *pTable,
        bool bNeedDecoder)
{
  int m_Size; // edi
  int v4; // eax
  SendTable **m_pMemory; // ecx
  int m_nAllocationCount; // eax
  SendTable **v7; // ecx
  int v8; // eax
  SendTable **v9; // eax

  m_Size = visited->m_Size;
  v4 = 0;
  if ( m_Size <= 0 )
    goto LABEL_7;
  m_pMemory = visited->m_Memory.m_pMemory;
  while ( *m_pMemory != pTable )
  {
    ++v4;
    ++m_pMemory;
    if ( v4 >= m_Size )
      goto LABEL_7;
  }
  if ( v4 == -1 )
  {
LABEL_7:
    m_nAllocationCount = visited->m_Memory.m_nAllocationCount;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<INetMessage *,int>::Grow(this: (CUtlMemory<S3RGBA,int> *)visited, num: m_Size - m_nAllocationCount + 1);
    ++visited->m_Size;
    v7 = visited->m_Memory.m_pMemory;
    v8 = visited->m_Size - m_Size - 1;
    visited->m_pElements = visited->m_Memory.m_pMemory;
    if ( v8 > 0 )
      _V_memmove(dest: &v7[m_Size + 1], src: &v7[m_Size], count: 4 * v8);
    v9 = &visited->m_Memory.m_pMemory[m_Size];
    if ( v9 != nullptr )
      *v9 = pTable;
    DataTable_SetupReceiveTableFromSendTable(sendTable: pTable, bNeedsDecoder: bNeedDecoder);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10168E60
// Name: void DataTable_MaybeCreateReceiveTable_R(class CUtlVector<class SendTable __near *,class CUtlMemory<class SendTable __near *,int>> __near &,class SendTable __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DataTable_MaybeCreateReceiveTable_R(
        CUtlVector<SendTable *,CUtlMemory<SendTable *,int> > *visited,
        SendTable *pTable)
{
  int v2; // ebx
  int v3; // edi

  DataTable_MaybeCreateReceiveTable(visited, pTable, bNeedDecoder: false);
  v2 = 0;
  if ( pTable->m_nProps > 0 )
  {
    v3 = 0;
    do
    {
      if ( pTable->m_pProps[v3].m_Type == DPT_DataTable )
        DataTable_MaybeCreateReceiveTable_R(visited, pTable: pTable->m_pProps[v3].m_pDataTable);
      ++v2;
      ++v3;
    }
    while ( v2 < pTable->m_nProps );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10168EB0
// Name: void DataTable_CreateClientTablesFromServerTables(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DataTable_CreateClientTablesFromServerTables()
{
  IServerGameDLL *v0; // ecx
  int v1; // ebx
  ServerClass *v2; // edi
  SendTable **m_pMemory; // eax
  ServerClass *v4; // esi
  SendTable *m_pTable; // esi
  int v6; // edi
  CUtlVector<SendTable *,CUtlMemory<SendTable *,int> > visited; // [esp+4h] [ebp-18h] BYREF
  ServerClass *pCur; // [esp+18h] [ebp-4h]

  v0 = serverGameDLL;
  v1 = 0;
  if ( serverGameDLL == nullptr )
  {
    Sys_Error(error: "DataTable_CreateClientTablesFromServerTables:  No serverGameDLL loaded!");
    v0 = serverGameDLL;
  }
  v2 = v0->GetAllServerClasses(this: v0);
  m_pMemory = nullptr;
  memset(&visited, 0, sizeof(visited));
  v4 = v2;
  if ( v2 != nullptr )
  {
    do
    {
      DataTable_MaybeCreateReceiveTable(&visited, pTable: v4->m_pTable, bNeedDecoder: true);
      v4 = v4->m_pNext;
    }
    while ( v4 != nullptr );
    m_pMemory = visited.m_Memory.m_pMemory;
  }
  pCur = v2;
  if ( v2 != nullptr )
  {
    do
    {
      m_pTable = pCur->m_pTable;
      DataTable_MaybeCreateReceiveTable(&visited, pTable: m_pTable, bNeedDecoder: false);
      if ( m_pTable->m_nProps > 0 )
      {
        v6 = 0;
        do
        {
          if ( m_pTable->m_pProps[v6].m_Type == DPT_DataTable )
            DataTable_MaybeCreateReceiveTable_R(&visited, pTable: m_pTable->m_pProps[v6].m_pDataTable);
          ++v1;
          ++v6;
        }
        while ( v1 < m_pTable->m_nProps );
        v1 = 0;
      }
      pCur = pCur->m_pNext;
    }
    while ( pCur != nullptr );
    m_pMemory = visited.m_Memory.m_pMemory;
  }
  visited.m_Size = 0;
  if ( visited.m_Memory.m_nGrowSize >= 0 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      m_pMemory = nullptr;
      visited.m_Memory.m_pMemory = nullptr;
    }
    visited.m_Memory.m_nAllocationCount = 0;
  }
  visited.m_pElements = m_pMemory;
  if ( visited.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x10167ED0
// Name: void DataTable_ClearWriteFlags_R(class SendTable __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DataTable_ClearWriteFlags_R(SendTable *pTable)
{
  int v1; // ebx
  int v2; // edi

  *((_BYTE *)pTable + 16) &= ~2u;
  v1 = 0;
  if ( pTable->m_nProps > 0 )
  {
    v2 = 0;
    do
    {
      if ( pTable->m_pProps[v2].m_Type == DPT_DataTable )
        DataTable_ClearWriteFlags_R(pTable: pTable->m_pProps[v2].m_pDataTable);
      ++v1;
      ++v2;
    }
    while ( v1 < pTable->m_nProps );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10167F10
// Name: void DataTable_ClearWriteFlags(class ServerClass __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DataTable_ClearWriteFlags(ServerClass *pClasses)
{
  ServerClass *i; // edi
  SendTable *m_pTable; // ecx
  int v3; // edx
  int v4; // esi

  for ( i = pClasses; i != nullptr; i = i->m_pNext )
  {
    m_pTable = i->m_pTable;
    *((_BYTE *)m_pTable + 16) &= ~2u;
    v3 = 0;
    if ( m_pTable->m_nProps > 0 )
    {
      v4 = 0;
      do
      {
        if ( m_pTable->m_pProps[v4].m_Type == DPT_DataTable )
          DataTable_ClearWriteFlags_R(pTable: m_pTable->m_pProps[v4].m_pDataTable);
        ++v3;
        ++v4;
      }
      while ( v3 < m_pTable->m_nProps );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10167F60
// Name: void DataTable_WriteClassInfosBuffer(class ServerClass __near *,class bf_write __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DataTable_WriteClassInfosBuffer(ServerClass *pClasses, bf_write *pBuf)
{
  ServerClass *v2; // esi
  int v3; // ecx
  ServerClass *i; // eax

  v2 = pClasses;
  v3 = 0;
  for ( i = pClasses; i != nullptr; ++v3 )
    i = i->m_pNext;
  bf_write::WriteShort(this: pBuf, val: v3);
  if ( pClasses != nullptr )
  {
    do
    {
      bf_write::WriteShort(this: pBuf, val: v2->m_ClassID);
      bf_write::WriteString(this: pBuf, pStr: v2->m_pNetworkName);
      bf_write::WriteString(this: pBuf, pStr: v2->m_pTable->m_pNetTableName);
      v2 = v2->m_pNext;
    }
    while ( v2 != nullptr );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10167FC0
// Name: bool DataTable_ParseClassInfosFromBuffer(class CClientState __near *,class bf_read __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl DataTable_ParseClassInfosFromBuffer(CClientState *pState, bf_read *pBuf)
{
  C_ServerClassInfo *m_pServerClasses; // eax
  int *p_m_InstanceBaselineIndex; // ebx
  C_ServerClassInfo *v4; // esi
  int j; // edi
  int m_nBitsAvail; // ecx
  unsigned int v8; // eax
  __int16 v9; // dx
  int v10; // ecx
  const unsigned int *v11; // ecx
  unsigned int v12; // ecx
  const unsigned int *m_pBufferEnd; // edx
  unsigned int m_nInBufWord; // edi
  const unsigned int *m_pDataIn; // ecx
  unsigned int v16; // edx
  unsigned int v17; // ebx
  unsigned int v18; // edx
  int v19; // edi
  int v20; // ecx
  _DWORD *v21; // eax
  C_ServerClassInfo *v22; // eax
  int v23; // edi
  C_ServerClassInfo *v24; // ebx
  int v26; // ecx
  unsigned int v27; // eax
  __int16 v28; // dx
  int v29; // ecx
  const unsigned int *v30; // ecx
  unsigned int v31; // ecx
  const unsigned int *v32; // edx
  unsigned int v33; // edi
  const unsigned int *v34; // ecx
  unsigned int v35; // edx
  unsigned int v36; // ebx
  unsigned int v37; // edx
  int v38; // edi
  C_ServerClassInfo *v39; // ebx
  C_ServerClassInfo *v40; // ebx
  int i; // [esp+18h] [ebp+Ch]
  int ia; // [esp+18h] [ebp+Ch]

  m_pServerClasses = pState->m_pServerClasses;
  if ( m_pServerClasses != nullptr )
  {
    p_m_InstanceBaselineIndex = &m_pServerClasses[-1].m_InstanceBaselineIndex;
    v4 = &m_pServerClasses[m_pServerClasses[-1].m_InstanceBaselineIndex];
    for ( j = m_pServerClasses[-1].m_InstanceBaselineIndex - 1; j >= 0; --j )
      C_ServerClassInfo::~C_ServerClassInfo(this: --v4);
    free(pMem: p_m_InstanceBaselineIndex);
  }
  m_nBitsAvail = pBuf->m_nBitsAvail;
  if ( m_nBitsAvail < 16 )
  {
    m_pBufferEnd = pBuf->m_pBufferEnd;
    m_nInBufWord = pBuf->m_nInBufWord;
    v8 = 16 - m_nBitsAvail;
    m_pDataIn = pBuf->m_pDataIn;
    if ( m_pDataIn == m_pBufferEnd )
    {
      pBuf->m_nBitsAvail = 1;
      pBuf->m_nInBufWord = 0;
      pBuf->m_bOverflow = true;
    }
    else
    {
      if ( m_pDataIn > m_pBufferEnd )
      {
        pBuf->m_bOverflow = true;
        pBuf->m_nInBufWord = 0;
        goto LABEL_20;
      }
      pBuf->m_nInBufWord = *m_pDataIn;
    }
    pBuf->m_pDataIn = m_pDataIn + 1;
LABEL_20:
    if ( pBuf->m_bOverflow )
    {
      LOWORD(v8) = 0;
    }
    else
    {
      v16 = pBuf->m_nInBufWord;
      v17 = (v16 & CBitBuffer::s_nMaskTable[v8]) << pBuf->m_nBitsAvail;
      pBuf->m_nBitsAvail = 32 - v8;
      v18 = v16 >> v8;
      LOWORD(v8) = v17 | m_nInBufWord;
      pBuf->m_nInBufWord = v18;
    }
    goto LABEL_23;
  }
  v8 = pBuf->m_nInBufWord;
  v9 = v8;
  v10 = m_nBitsAvail - 16;
  pBuf->m_nBitsAvail = v10;
  if ( v10 != 0 )
  {
    pBuf->m_nInBufWord = HIWORD(v8);
  }
  else
  {
    v8 = (unsigned int)pBuf->m_pDataIn;
    v11 = pBuf->m_pBufferEnd;
    pBuf->m_nBitsAvail = 32;
    if ( (const unsigned int *)v8 == v11 )
    {
      pBuf->m_pDataIn = (const unsigned int *)(v8 + 4);
      pBuf->m_nBitsAvail = 1;
      pBuf->m_nInBufWord = 0;
      LOWORD(v8) = v9;
    }
    else
    {
      if ( v8 <= (unsigned int)v11 )
      {
        v12 = *(_DWORD *)v8;
        pBuf->m_pDataIn = (const unsigned int *)(v8 + 4);
        pBuf->m_nInBufWord = v12;
      }
      else
      {
        pBuf->m_bOverflow = true;
        pBuf->m_nInBufWord = 0;
      }
      LOWORD(v8) = v9;
    }
  }
LABEL_23:
  v19 = (__int16)v8;
  pState->m_nServerClasses = (__int16)v8;
  v20 = (unsigned __int64)(unsigned int)(__int16)v8 >> 28 != 0 ? -1 : 16 * (__int16)v8;
  v21 = MemAlloc_Alloc(nSize: __CFADD__(v20, 4) ? -1 : v20 + 4);
  if ( v21 != nullptr )
  {
    *v21 = v19;
    v22 = (C_ServerClassInfo *)(v21 + 1);
    v23 = v19 - 1;
    i = (int)v22;
    v24 = v22;
    if ( v23 >= 0 )
    {
      do
      {
        C_ServerClassInfo::C_ServerClassInfo(this: v24++);
        --v23;
      }
      while ( v23 >= 0 );
      v22 = (C_ServerClassInfo *)i;
    }
  }
  else
  {
    v22 = nullptr;
  }
  pState->m_pServerClasses = v22;
  if ( v22 == nullptr )
  {
    Host_EndGame(
      bShowMainMenu: true,
      message: "CL_ParseClassInfo: can't allocate %d C_ServerClassInfos.\n",
      pState->m_nServerClasses);
    return 0;
  }
  ia = 0;
  if ( pState->m_nServerClasses <= 0 )
    return 1;
  while ( 1 )
  {
    v26 = pBuf->m_nBitsAvail;
    if ( v26 < 16 )
    {
      v32 = pBuf->m_pBufferEnd;
      v33 = pBuf->m_nInBufWord;
      v27 = 16 - v26;
      v34 = pBuf->m_pDataIn;
      if ( v34 == v32 )
      {
        pBuf->m_nBitsAvail = 1;
        pBuf->m_nInBufWord = 0;
        pBuf->m_bOverflow = true;
      }
      else
      {
        if ( v34 > v32 )
        {
          pBuf->m_bOverflow = true;
          pBuf->m_nInBufWord = 0;
          goto LABEL_48;
        }
        pBuf->m_nInBufWord = *v34;
      }
      pBuf->m_pDataIn = v34 + 1;
LABEL_48:
      if ( pBuf->m_bOverflow )
      {
        LOWORD(v27) = 0;
      }
      else
      {
        v35 = pBuf->m_nInBufWord;
        v36 = (v35 & CBitBuffer::s_nMaskTable[v27]) << pBuf->m_nBitsAvail;
        pBuf->m_nBitsAvail = 32 - v27;
        v37 = v35 >> v27;
        LOWORD(v27) = v36 | v33;
        pBuf->m_nInBufWord = v37;
      }
      goto LABEL_51;
    }
    v27 = pBuf->m_nInBufWord;
    v28 = v27;
    v29 = v26 - 16;
    pBuf->m_nBitsAvail = v29;
    if ( v29 != 0 )
    {
      pBuf->m_nInBufWord = HIWORD(v27);
    }
    else
    {
      v27 = (unsigned int)pBuf->m_pDataIn;
      v30 = pBuf->m_pBufferEnd;
      pBuf->m_nBitsAvail = 32;
      if ( (const unsigned int *)v27 == v30 )
      {
        pBuf->m_pDataIn = (const unsigned int *)(v27 + 4);
        pBuf->m_nBitsAvail = 1;
        pBuf->m_nInBufWord = 0;
        LOWORD(v27) = v28;
      }
      else
      {
        if ( v27 <= (unsigned int)v30 )
        {
          v31 = *(_DWORD *)v27;
          pBuf->m_pDataIn = (const unsigned int *)(v27 + 4);
          pBuf->m_nInBufWord = v31;
        }
        else
        {
          pBuf->m_bOverflow = true;
          pBuf->m_nInBufWord = 0;
        }
        LOWORD(v27) = v28;
      }
    }
LABEL_51:
    if ( (__int16)v27 >= pState->m_nServerClasses )
      break;
    v38 = (__int16)v27;
    v39 = pState->m_pServerClasses;
    v39[v38].m_ClassName = CBitRead::ReadAndAllocateString(this: pBuf, pOverflow: nullptr);
    v40 = pState->m_pServerClasses;
    v40[v38].m_DatatableName = CBitRead::ReadAndAllocateString(this: pBuf, pOverflow: nullptr);
    if ( ++ia >= pState->m_nServerClasses )
      return 1;
  }
  Host_EndGame(
    bShowMainMenu: true,
    message: "DataTable_ParseClassInfosFromBuffer: invalid class index (%d).\n",
    (__int16)v27);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x101682D0
// Name: bool DataTable_LoadDataTablesFromBuffer(class bf_read __near *,int)
// Source: json
//------------------------------------------------------------------------------
char __cdecl DataTable_LoadDataTablesFromBuffer(bf_read *pBuf, int nDemoProtocol)
{
  unsigned int m_nInBufWord; // eax
  int v3; // edx
  bool v4; // zf
  const unsigned int *m_pDataIn; // eax
  const unsigned int *m_pBufferEnd; // ecx
  unsigned int v7; // eax
  int v8; // ecx
  const unsigned int *v9; // eax
  const unsigned int *v10; // edx
  CClientState *BaseLocalClient; // eax

  while ( 1 )
  {
    m_nInBufWord = pBuf->m_nInBufWord;
    v3 = m_nInBufWord & 1;
    v4 = pBuf->m_nBitsAvail-- == 1;
    if ( v4 )
    {
      m_pDataIn = pBuf->m_pDataIn;
      m_pBufferEnd = pBuf->m_pBufferEnd;
      pBuf->m_nBitsAvail = 32;
      if ( m_pDataIn == m_pBufferEnd )
      {
        pBuf->m_nBitsAvail = 1;
        pBuf->m_nInBufWord = 0;
        pBuf->m_pDataIn = m_pDataIn + 1;
      }
      else if ( m_pDataIn <= m_pBufferEnd )
      {
        pBuf->m_nInBufWord = *m_pDataIn;
        pBuf->m_pDataIn = m_pDataIn + 1;
      }
      else
      {
        pBuf->m_bOverflow = true;
        pBuf->m_nInBufWord = 0;
      }
    }
    else
    {
      pBuf->m_nInBufWord = m_nInBufWord >> 1;
    }
    if ( v3 == 0 )
      break;
    v7 = pBuf->m_nInBufWord;
    v8 = v7 & 1;
    v4 = pBuf->m_nBitsAvail-- == 1;
    if ( v4 )
    {
      v9 = pBuf->m_pDataIn;
      v10 = pBuf->m_pBufferEnd;
      pBuf->m_nBitsAvail = 32;
      if ( v9 == v10 )
      {
        pBuf->m_nBitsAvail = 1;
        pBuf->m_nInBufWord = 0;
        pBuf->m_pDataIn = v9 + 1;
      }
      else if ( v9 <= v10 )
      {
        pBuf->m_nInBufWord = *v9;
        pBuf->m_pDataIn = v9 + 1;
      }
      else
      {
        pBuf->m_bOverflow = true;
        pBuf->m_nInBufWord = 0;
      }
    }
    else
    {
      pBuf->m_nInBufWord = v7 >> 1;
    }
    if ( !RecvTable_RecvClassInfos(pBuf, bNeedsDecoder: v8 != 0, nDemoProtocol) )
    {
      Host_Error(error: "DataTable_ParseClientTablesFromBuffer failed.\n");
      return 0;
    }
  }
  BaseLocalClient = GetBaseLocalClient();
  return DataTable_ParseClassInfosFromBuffer(pState: BaseLocalClient, pBuf);
}

//------------------------------------------------------------------------------
// Address: 0x101684B0
// Name: void DataTable_CreateClientClassInfosFromServerClasses(class CBaseClientState __near *)
// Source: json
//------------------------------------------------------------------------------
void __usercall DataTable_CreateClientClassInfosFromServerClasses(int a1@<edi>, int a2@<esi>, CBaseClientState *pState)
{
  IServerGameDLL *v3; // ecx
  int v4; // eax
  int v5; // esi
  C_ServerClassInfo *m_pServerClasses; // eax
  int *p_m_InstanceBaselineIndex; // ecx
  C_ServerClassInfo *v8; // edi
  int v9; // ebx
  int v10; // ecx
  int *v11; // eax
  int v12; // esi
  C_ServerClassInfo *v13; // ebx
  C_ServerClassInfo *i; // edi
  C_ServerClassInfo *v15; // ecx
  CBaseClientState *v16; // eax
  ServerClass *v17; // esi
  int v18; // edi
  const char *m_pNetworkName; // edx
  C_ServerClassInfo *v20; // ebx
  C_ServerClassInfo *v21; // ebx
  ServerClass *pClasses; // [esp+0h] [ebp-8h]
  int *v23; // [esp+4h] [ebp-4h]

  v3 = serverGameDLL;
  if ( serverGameDLL == nullptr )
  {
    Sys_Error(error: "DataTable_CreateClientClassInfosFromServerClasses:  No serverGameDLL loaded!");
    v3 = serverGameDLL;
  }
  v4 = ((int (__thiscall *)(IServerGameDLL *, int, int))v3->GetAllServerClasses)(a1: v3, a2: a1, a3: a2);
  v5 = 0;
  for ( pClasses = (ServerClass *)v4; v4 != 0; ++v5 )
    v4 = *(_DWORD *)(v4 + 8);
  m_pServerClasses = pState->m_pServerClasses;
  if ( m_pServerClasses != nullptr )
  {
    p_m_InstanceBaselineIndex = &m_pServerClasses[-1].m_InstanceBaselineIndex;
    v8 = &m_pServerClasses[m_pServerClasses[-1].m_InstanceBaselineIndex];
    v9 = m_pServerClasses[-1].m_InstanceBaselineIndex - 1;
    v23 = &m_pServerClasses[-1].m_InstanceBaselineIndex;
    if ( v9 >= 0 )
    {
      do
      {
        C_ServerClassInfo::~C_ServerClassInfo(this: --v8);
        --v9;
      }
      while ( v9 >= 0 );
      p_m_InstanceBaselineIndex = v23;
    }
    free(pMem: p_m_InstanceBaselineIndex);
  }
  pState->m_nServerClasses = v5;
  v10 = (unsigned __int64)(unsigned int)v5 >> 28 != 0 ? -1 : 16 * v5;
  v11 = (int *)MemAlloc_Alloc(nSize: __CFADD__(v10, 4) ? -1 : v10 + 4);
  if ( v11 != nullptr )
  {
    *v11 = v5;
    v12 = v5 - 1;
    v13 = (C_ServerClassInfo *)(v11 + 1);
    for ( i = (C_ServerClassInfo *)(v11 + 1); v12 >= 0; --v12 )
      C_ServerClassInfo::C_ServerClassInfo(this: i++);
    v15 = v13;
  }
  else
  {
    v15 = nullptr;
  }
  v16 = pState;
  pState->m_pServerClasses = v15;
  if ( v15 != nullptr )
  {
    v17 = pClasses;
    v18 = 0;
    if ( pClasses != nullptr )
    {
      while ( 1 )
      {
        m_pNetworkName = v17->m_pNetworkName;
        v17->m_ClassID = v18;
        v20 = v16->m_pServerClasses;
        ++v18;
        v20[v17->m_ClassID].m_ClassName = COM_StringCopy(in: m_pNetworkName);
        v21 = pState->m_pServerClasses;
        v21[v17->m_ClassID].m_DatatableName = COM_StringCopy(in: v17->m_pTable->m_pNetTableName);
        v17 = v17->m_pNext;
        if ( v17 == nullptr )
          break;
        v16 = pState;
      }
    }
  }
  else
  {
    Host_EndGame(
      bShowMainMenu: true,
      message: "CL_ParseClassInfo: can't allocate %d C_ServerClassInfos.\n",
      pState->m_nServerClasses);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10168600
// Name: void DataTable_MaybeWriteSendTableBuffer(class SendTable __near *,class bf_write __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DataTable_MaybeWriteSendTableBuffer(SendTable *pTable, bf_write *pBuf, bool bNeedDecoder)
{
  char v3; // al
  int m_iCurBit; // ecx
  int v5; // ecx
  unsigned __int8 *v6; // esi
  char v7; // bl

  v3 = *((_BYTE *)pTable + 16);
  if ( (v3 & 2) == 0 )
  {
    *((_BYTE *)pTable + 16) = v3 | 2;
    m_iCurBit = pBuf->m_iCurBit;
    if ( m_iCurBit + 1 > pBuf->m_nDataBits )
      pBuf->m_bOverflow = true;
    if ( !pBuf->m_bOverflow )
    {
      pBuf->m_pData[m_iCurBit >> 3] |= 1 << (m_iCurBit & 7);
      ++pBuf->m_iCurBit;
    }
    v5 = pBuf->m_iCurBit;
    if ( v5 + 1 > pBuf->m_nDataBits )
      pBuf->m_bOverflow = true;
    if ( !pBuf->m_bOverflow )
    {
      v6 = &pBuf->m_pData[v5 >> 3];
      v7 = 1 << (v5 & 7);
      if ( bNeedDecoder )
      {
        *v6 |= v7;
        ++pBuf->m_iCurBit;
        SendTable_WriteInfos(pTable, pBuf);
        return;
      }
      *v6 &= ~v7;
      ++pBuf->m_iCurBit;
    }
    SendTable_WriteInfos(pTable, pBuf);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101686A0
// Name: void DataTable_MaybeWriteSendTableBuffer_R(class SendTable __near *,class bf_write __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DataTable_MaybeWriteSendTableBuffer_R(SendTable *pTable, bf_write *pBuf)
{
  int v2; // ebx
  int v3; // edi

  DataTable_MaybeWriteSendTableBuffer(pTable, pBuf, bNeedDecoder: false);
  v2 = 0;
  if ( pTable->m_nProps > 0 )
  {
    v3 = 0;
    do
    {
      if ( pTable->m_pProps[v3].m_Type == DPT_DataTable )
        DataTable_MaybeWriteSendTableBuffer_R(pTable: pTable->m_pProps[v3].m_pDataTable, pBuf);
      ++v2;
      ++v3;
    }
    while ( v2 < pTable->m_nProps );
  }
}

//------------------------------------------------------------------------------
// Address: 0x101686F0
// Name: void DataTable_WriteSendTablesBuffer(class ServerClass __near *,class bf_write __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DataTable_WriteSendTablesBuffer(ServerClass *pClasses, bf_write *pBuf)
{
  ServerClass *v2; // ebx
  SendTable *m_pTable; // edi
  char v5; // al
  int m_iCurBit; // ecx
  int v7; // ecx
  SendTable *v8; // edi
  char v9; // al
  int v10; // ecx
  int v11; // ecx
  int v12; // ebx
  int v13; // ecx
  ServerClass *pCur; // [esp+14h] [ebp+8h]
  bf_write *pBufa; // [esp+18h] [ebp+Ch]

  v2 = pClasses;
  DataTable_ClearWriteFlags(pClasses);
  if ( pClasses != nullptr )
  {
    do
    {
      m_pTable = v2->m_pTable;
      v5 = *((_BYTE *)m_pTable + 16);
      if ( (v5 & 2) == 0 )
      {
        *((_BYTE *)m_pTable + 16) = v5 | 2;
        m_iCurBit = pBuf->m_iCurBit;
        if ( m_iCurBit + 1 > pBuf->m_nDataBits )
          pBuf->m_bOverflow = true;
        if ( !pBuf->m_bOverflow )
        {
          pBuf->m_pData[m_iCurBit >> 3] |= 1 << (m_iCurBit & 7);
          ++pBuf->m_iCurBit;
        }
        v7 = pBuf->m_iCurBit;
        if ( v7 + 1 > pBuf->m_nDataBits )
          pBuf->m_bOverflow = true;
        if ( !pBuf->m_bOverflow )
        {
          pBuf->m_pData[v7 >> 3] |= 1 << (v7 & 7);
          ++pBuf->m_iCurBit;
        }
        SendTable_WriteInfos(pTable: m_pTable, pBuf);
      }
      v2 = v2->m_pNext;
    }
    while ( v2 != nullptr );
    v2 = pClasses;
  }
  for ( pCur = v2; pCur != nullptr; pCur = pCur->m_pNext )
  {
    v8 = pCur->m_pTable;
    v9 = *((_BYTE *)v8 + 16);
    if ( (v9 & 2) == 0 )
    {
      *((_BYTE *)v8 + 16) = v9 | 2;
      v10 = pBuf->m_iCurBit;
      if ( v10 + 1 > pBuf->m_nDataBits )
        pBuf->m_bOverflow = true;
      if ( !pBuf->m_bOverflow )
      {
        pBuf->m_pData[v10 >> 3] |= 1 << (v10 & 7);
        ++pBuf->m_iCurBit;
      }
      v11 = pBuf->m_iCurBit;
      if ( v11 + 1 > pBuf->m_nDataBits )
        pBuf->m_bOverflow = true;
      if ( !pBuf->m_bOverflow )
      {
        pBuf->m_pData[v11 >> 3] &= ~(1 << (v11 & 7));
        ++pBuf->m_iCurBit;
      }
      SendTable_WriteInfos(pTable: v8, pBuf);
    }
    v12 = 0;
    for ( pBufa = nullptr; (int)pBufa < v8->m_nProps; pBufa = (bf_write *)((char *)pBufa + 1) )
    {
      if ( v8->m_pProps[v12].m_Type == DPT_DataTable )
        DataTable_MaybeWriteSendTableBuffer_R(pTable: v8->m_pProps[v12].m_pDataTable, pBuf);
      ++v12;
    }
  }
  v13 = pBuf->m_iCurBit;
  if ( v13 + 1 > pBuf->m_nDataBits )
    pBuf->m_bOverflow = true;
  if ( !pBuf->m_bOverflow )
  {
    pBuf->m_pData[v13 >> 3] &= ~(1 << (v13 & 7));
    ++pBuf->m_iCurBit;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10168C10
// Name: bool DataTable_SetupReceiveTableFromSendTable(class SendTable __near *,bool)
// Source: json
//------------------------------------------------------------------------------
char __cdecl DataTable_SetupReceiveTableFromSendTable(SendTable *sendTable, bool bNeedsDecoder)
{
  CClientSendTable *v2; // eax
  CRecvDecoder *v3; // ebx
  CClientSendTable *v4; // edi
  unsigned __int16 v5; // ax
  int v6; // esi
  UtlLinkedListElem_t<CClientSendTable *,unsigned short> *v7; // eax
  CRecvDecoder *v8; // eax
  unsigned __int16 v9; // ax
  int v10; // esi
  UtlLinkedListElem_t<CRecvDecoder *,unsigned short> *v11; // eax
  RecvTable *RecvTable; // eax
  int m_nProps; // esi
  int v15; // ecx
  int *v16; // eax
  SendProp *v17; // eax
  int v18; // esi
  SendProp *v19; // ebx
  int v20; // ecx
  int v21; // esi
  int v22; // ebx
  int v23; // eax
  SendProp *v24; // esi
  int v25; // edi
  int v26; // eax
  int v27; // eax
  SendTable *m_pDataTable; // ecx
  const char *m_pExcludeDTName; // eax
  CClientSendProp *pClientProp; // [esp+Ch] [ebp-8h]
  CClientSendTable *pClientSendTable; // [esp+10h] [ebp-4h]
  int iProp; // [esp+20h] [ebp+Ch]
  int iPropa; // [esp+20h] [ebp+Ch]
  int iPropb; // [esp+20h] [ebp+Ch]

  v2 = (CClientSendTable *)MemAlloc_Alloc(nSize: 0x28u);
  v3 = nullptr;
  if ( v2 != nullptr )
  {
    v4 = CClientSendTable::CClientSendTable(this: v2);
    pClientSendTable = v4;
  }
  else
  {
    pClientSendTable = nullptr;
    v4 = nullptr;
  }
  v5 = CUtlLinkedList<CClientSendTable *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CClientSendTable *,unsigned short>,unsigned short>>::AllocInternal(
         this: &g_ClientSendTables,
         multilist: false);
  v6 = v5;
  if ( v5 != 0xFFFF )
  {
    CUtlLinkedList<CClientSendTable *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CClientSendTable *,unsigned short>,unsigned short>>::LinkBefore(
      this: (CUtlLinkedList<unsigned int,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<unsigned int,unsigned short>,unsigned short> > *)&g_ClientSendTables,
      before: 0xFFFFu,
      elem: v5);
    v7 = &g_ClientSendTables.m_Memory.m_pMemory[v6];
    if ( v7 != nullptr )
      v7->m_Element = v4;
  }
  v4->m_SendTable.m_pNetTableName = COM_StringCopy(in: sendTable->m_pNetTableName);
  if ( bNeedsDecoder )
  {
    v8 = (CRecvDecoder *)MemAlloc_Alloc(nSize: 0x14Cu);
    if ( v8 != nullptr )
      v3 = CRecvDecoder::CRecvDecoder(this: v8);
    v9 = CUtlLinkedList<CRecvDecoder *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CRecvDecoder *,unsigned short>,unsigned short>>::AllocInternal(
           this: &g_RecvDecoders,
           multilist: false);
    v10 = v9;
    if ( v9 != 0xFFFF )
    {
      CUtlLinkedList<CClientSendTable *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CClientSendTable *,unsigned short>,unsigned short>>::LinkBefore(
        this: (CUtlLinkedList<unsigned int,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<unsigned int,unsigned short>,unsigned short> > *)&g_RecvDecoders,
        before: 0xFFFFu,
        elem: v9);
      v11 = &g_RecvDecoders.m_Memory.m_pMemory[v10];
      if ( v11 != nullptr )
        v11->m_Element = v3;
    }
    RecvTable = FindRecvTable(pName: v4->m_SendTable.m_pNetTableName);
    if ( RecvTable == nullptr )
    {
      DataTable_Warning(pInMessage: "No matching RecvTable for SendTable '%s'.\n", v4->m_SendTable.m_pNetTableName);
      return 0;
    }
    RecvTable->m_pDecoder = v3;
    v3->m_pTable = RecvTable;
    v3->m_pClientSendTable = v4;
    v3->m_Precalc.m_pSendTable = &v4->m_SendTable;
    v4->m_SendTable.m_pPrecalc = &v3->m_Precalc;
    SetupArrayProps_R<RecvTable,RecvProp>(pTable: RecvTable);
  }
  m_nProps = sendTable->m_nProps;
  v4->m_SendTable.m_nProps = m_nProps;
  if ( m_nProps != 0
    && (v15 = (84 * (unsigned __int64)(unsigned int)m_nProps) >> 32 != 0 ? -1 : 84 * m_nProps,
        (v16 = (int *)MemAlloc_Alloc(nSize: __CFADD__(v15, 4) ? -1 : v15 + 4)) != nullptr) )
  {
    *v16 = m_nProps;
    v17 = (SendProp *)(v16 + 1);
    v18 = m_nProps - 1;
    iProp = (int)v17;
    v19 = v17;
    if ( v18 >= 0 )
    {
      do
      {
        SendProp::SendProp(this: v19++);
        --v18;
      }
      while ( v18 >= 0 );
      v17 = (SendProp *)iProp;
    }
  }
  else
  {
    v17 = nullptr;
  }
  v20 = v4->m_SendTable.m_nProps;
  v4->m_SendTable.m_pProps = v17;
  v21 = v4->m_Props.m_Size - 1;
  for ( iPropa = v20; v21 >= 0; --v21 )
    ICvar::Iterator::~Iterator(this: (ICvar::Iterator *)&v4->m_Props.m_Memory.m_pMemory[v21]);
  v4->m_Props.m_Size = 0;
  CUtlVector<CClientSendProp,CUtlMemory<CClientSendProp,int>>::InsertMultipleBefore(
    this: &v4->m_Props,
    elem: 0,
    num: iPropa);
  iPropb = 0;
  if ( v4->m_SendTable.m_nProps > 0 )
  {
    v22 = 0;
    while ( 1 )
    {
      v23 = (int)&v4->m_Props.m_Memory.m_pMemory[iPropb];
      v24 = &sendTable->m_pProps[v22];
      v25 = (int)&v4->m_SendTable.m_pProps[v22];
      pClientProp = (CClientSendProp *)v23;
      *(_DWORD *)(v25 + 8) = v24->m_Type;
      *(_DWORD *)(v25 + 48) = COM_StringCopy(in: v24->m_pVarName);
      *(_DWORD *)(v25 + 60) = v24->m_Flags;
      *(_BYTE *)(v25 + 56) = v24->m_priority;
      v26 = _CommandLine();
      if ( (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v26 + 40))(a1: v26, a2: "-dti") != 0
        && v24->m_pParentArrayPropName != nullptr )
      {
        *(_DWORD *)(v25 + 44) = COM_StringCopy(in: v24->m_pParentArrayPropName);
      }
      v27 = *(_DWORD *)(v25 + 8);
      if ( v27 == 6 )
      {
        m_pDataTable = v24->m_pDataTable;
        m_pExcludeDTName = v24->m_pExcludeDTName;
        if ( m_pDataTable != nullptr )
          m_pExcludeDTName = m_pDataTable->m_pNetTableName;
        pClientProp->m_pTableName = COM_StringCopy(in: m_pExcludeDTName);
        *(_DWORD *)(v25 + 68) = v24->m_DataTableProxyFn;
        *(_DWORD *)(v25 + 76) = v24->m_Offset & 0xFFFFF;
      }
      else if ( (*(_DWORD *)(v25 + 60) & 0x40) != 0 )
      {
        *(_DWORD *)(v25 + 40) = COM_StringCopy(in: v24->m_pExcludeDTName);
      }
      else if ( v27 == 5 )
      {
        *(_DWORD *)(v25 + 32) = v24->m_nElements;
      }
      else
      {
        *(float *)(v25 + 16) = v24->m_fLowValue;
        *(float *)(v25 + 20) = v24->m_fHighValue;
        *(_DWORD *)(v25 + 12) = v24->m_nBits;
      }
      ++v22;
      if ( ++iPropb >= pClientSendTable->m_SendTable.m_nProps )
        break;
      v4 = pClientSendTable;
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10168EC0
// Name: void DataTable_MaybeCreateReceiveTable(class CUtlVector<class SendTable __near *,class CUtlMemory<class SendTable __near *,int>> __near &,class SendTable __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DataTable_MaybeCreateReceiveTable(
        CUtlVector<SendTable *,CUtlMemory<SendTable *,int> > *visited,
        SendTable *pTable,
        bool bNeedDecoder)
{
  int m_Size; // edi
  int v4; // eax
  SendTable **m_pMemory; // ecx
  int m_nAllocationCount; // eax
  SendTable **v7; // ecx
  int v8; // eax
  SendTable **v9; // eax

  m_Size = visited->m_Size;
  v4 = 0;
  if ( m_Size <= 0 )
    goto LABEL_7;
  m_pMemory = visited->m_Memory.m_pMemory;
  while ( *m_pMemory != pTable )
  {
    ++v4;
    ++m_pMemory;
    if ( v4 >= m_Size )
      goto LABEL_7;
  }
  if ( v4 == -1 )
  {
LABEL_7:
    m_nAllocationCount = visited->m_Memory.m_nAllocationCount;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<INetMessage *,int>::Grow(this: (CUtlMemory<S3RGBA,int> *)visited, num: m_Size - m_nAllocationCount + 1);
    ++visited->m_Size;
    v7 = visited->m_Memory.m_pMemory;
    v8 = visited->m_Size - m_Size - 1;
    visited->m_pElements = visited->m_Memory.m_pMemory;
    if ( v8 > 0 )
      _V_memmove(dest: &v7[m_Size + 1], src: &v7[m_Size], count: 4 * v8);
    v9 = &visited->m_Memory.m_pMemory[m_Size];
    if ( v9 != nullptr )
      *v9 = pTable;
    DataTable_SetupReceiveTableFromSendTable(sendTable: pTable, bNeedsDecoder: bNeedDecoder);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10168F50
// Name: void DataTable_MaybeCreateReceiveTable_R(class CUtlVector<class SendTable __near *,class CUtlMemory<class SendTable __near *,int>> __near &,class SendTable __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DataTable_MaybeCreateReceiveTable_R(
        CUtlVector<SendTable *,CUtlMemory<SendTable *,int> > *visited,
        SendTable *pTable)
{
  int v2; // ebx
  int v3; // edi

  DataTable_MaybeCreateReceiveTable(visited, pTable, bNeedDecoder: false);
  v2 = 0;
  if ( pTable->m_nProps > 0 )
  {
    v3 = 0;
    do
    {
      if ( pTable->m_pProps[v3].m_Type == DPT_DataTable )
        DataTable_MaybeCreateReceiveTable_R(visited, pTable: pTable->m_pProps[v3].m_pDataTable);
      ++v2;
      ++v3;
    }
    while ( v2 < pTable->m_nProps );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10168FA0
// Name: void DataTable_CreateClientTablesFromServerTables(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DataTable_CreateClientTablesFromServerTables()
{
  IServerGameDLL *v0; // ecx
  int v1; // ebx
  ServerClass *v2; // edi
  SendTable **m_pMemory; // eax
  ServerClass *v4; // esi
  SendTable *m_pTable; // esi
  int v6; // edi
  CUtlVector<SendTable *,CUtlMemory<SendTable *,int> > visited; // [esp+4h] [ebp-18h] BYREF
  ServerClass *pCur; // [esp+18h] [ebp-4h]

  v0 = serverGameDLL;
  v1 = 0;
  if ( serverGameDLL == nullptr )
  {
    Sys_Error(error: "DataTable_CreateClientTablesFromServerTables:  No serverGameDLL loaded!");
    v0 = serverGameDLL;
  }
  v2 = v0->GetAllServerClasses(this: v0);
  m_pMemory = nullptr;
  memset(&visited, 0, sizeof(visited));
  v4 = v2;
  if ( v2 != nullptr )
  {
    do
    {
      DataTable_MaybeCreateReceiveTable(&visited, pTable: v4->m_pTable, bNeedDecoder: true);
      v4 = v4->m_pNext;
    }
    while ( v4 != nullptr );
    m_pMemory = visited.m_Memory.m_pMemory;
  }
  pCur = v2;
  if ( v2 != nullptr )
  {
    do
    {
      m_pTable = pCur->m_pTable;
      DataTable_MaybeCreateReceiveTable(&visited, pTable: m_pTable, bNeedDecoder: false);
      if ( m_pTable->m_nProps > 0 )
      {
        v6 = 0;
        do
        {
          if ( m_pTable->m_pProps[v6].m_Type == DPT_DataTable )
            DataTable_MaybeCreateReceiveTable_R(&visited, pTable: m_pTable->m_pProps[v6].m_pDataTable);
          ++v1;
          ++v6;
        }
        while ( v1 < m_pTable->m_nProps );
        v1 = 0;
      }
      pCur = pCur->m_pNext;
    }
    while ( pCur != nullptr );
    m_pMemory = visited.m_Memory.m_pMemory;
  }
  visited.m_Size = 0;
  if ( visited.m_Memory.m_nGrowSize >= 0 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      m_pMemory = nullptr;
      visited.m_Memory.m_pMemory = nullptr;
    }
    visited.m_Memory.m_nAllocationCount = 0;
  }
  visited.m_pElements = m_pMemory;
  if ( visited.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
}

} // namespace engine_xlsp
