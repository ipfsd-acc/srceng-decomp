// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: engine/hltvclientstate.cpp
// Functions: 34
// ============================================================

#include "engine\hltvclientstate.h"

//------------------------------------------------------------------------------
// Address: 0x1009D480
// Name: CL_ParseDeltaHeader
// Source: json
//------------------------------------------------------------------------------
void __cdecl CL_ParseDeltaHeader(CEntityReadInfo *u)
{
  bf_read *m_pBuf; // eax
  int m_nBitsAvail; // ecx
  unsigned int v3; // edx
  int v4; // esi
  int v5; // ecx
  const unsigned int *v6; // ecx
  const unsigned int *v7; // edx
  unsigned int v8; // edx
  const unsigned int *m_pBufferEnd; // esi
  unsigned int m_nInBufWord; // edi
  int v11; // edx
  const unsigned int *m_pDataIn; // ecx
  unsigned int v13; // esi
  unsigned int v14; // ebx
  int v15; // ecx
  int v16; // ecx
  unsigned int v17; // edx
  int v18; // esi
  int v19; // ecx
  int v20; // eax
  int v21; // edx
  unsigned int v22; // edx
  int v23; // ecx
  unsigned int v24; // edx
  int v25; // ecx
  const unsigned int *v26; // ecx
  const unsigned int *v27; // edx
  unsigned int v28; // edx
  const unsigned int *v29; // esi
  unsigned int v30; // edi
  int v31; // edx
  const unsigned int *v32; // ecx
  unsigned int v33; // esi
  unsigned int v34; // ebx
  int v35; // eax
  bf_read *v36; // eax
  unsigned int v37; // ecx
  int v38; // edx
  bool v39; // zf
  const unsigned int *v40; // ecx
  const unsigned int *v41; // esi
  bf_read *v42; // eax
  unsigned int v43; // ecx
  int v44; // edx
  const unsigned int *v45; // ecx
  const unsigned int *v46; // esi
  bf_read *v47; // eax
  unsigned int v48; // ecx
  int v49; // edx
  const unsigned int *v50; // ecx
  const unsigned int *v51; // esi
  int v52; // [esp+Ch] [ebp-4h]

  u->m_UpdateFlags = 0;
  m_pBuf = u->m_pBuf;
  m_nBitsAvail = m_pBuf->m_nBitsAvail;
  if ( m_nBitsAvail < 6 )
  {
    m_pBufferEnd = m_pBuf->m_pBufferEnd;
    m_nInBufWord = m_pBuf->m_nInBufWord;
    v11 = 6 - m_nBitsAvail;
    m_pDataIn = m_pBuf->m_pDataIn;
    if ( m_pDataIn == m_pBufferEnd )
    {
      m_pBuf->m_nBitsAvail = 1;
      m_pBuf->m_nInBufWord = 0;
      m_pBuf->m_bOverflow = true;
    }
    else
    {
      if ( m_pDataIn > m_pBufferEnd )
      {
        m_pBuf->m_bOverflow = true;
        m_pBuf->m_nInBufWord = 0;
        goto LABEL_16;
      }
      m_pBuf->m_nInBufWord = *m_pDataIn;
    }
    m_pBuf->m_pDataIn = m_pDataIn + 1;
LABEL_16:
    if ( m_pBuf->m_bOverflow )
    {
      v52 = 0;
    }
    else
    {
      v13 = m_pBuf->m_nInBufWord;
      v14 = (v13 & CBitBuffer::s_nMaskTable[v11]) << m_pBuf->m_nBitsAvail;
      m_pBuf->m_nBitsAvail = 32 - v11;
      v52 = v14 | m_nInBufWord;
      m_pBuf->m_nInBufWord = v13 >> v11;
    }
    goto LABEL_19;
  }
  v3 = m_pBuf->m_nInBufWord;
  v4 = v3 & 0x3F;
  v5 = m_nBitsAvail - 6;
  m_pBuf->m_nBitsAvail = v5;
  if ( v5 != 0 )
  {
    m_pBuf->m_nInBufWord = v3 >> 6;
    v52 = v3 & 0x3F;
  }
  else
  {
    v6 = m_pBuf->m_pDataIn;
    v7 = m_pBuf->m_pBufferEnd;
    m_pBuf->m_nBitsAvail = 32;
    if ( v6 == v7 )
    {
      m_pBuf->m_nBitsAvail = 1;
      m_pBuf->m_nInBufWord = 0;
      m_pBuf->m_pDataIn = v6 + 1;
      v52 = v4;
    }
    else
    {
      if ( v6 <= v7 )
      {
        v8 = *v6;
        m_pBuf->m_pDataIn = v6 + 1;
        m_pBuf->m_nInBufWord = v8;
      }
      else
      {
        m_pBuf->m_bOverflow = true;
        m_pBuf->m_nInBufWord = 0;
      }
      v52 = v4;
    }
  }
LABEL_19:
  v15 = v52 & 0x30;
  switch ( v15 )
  {
    case 16:
      v16 = m_pBuf->m_nBitsAvail;
      if ( v16 >= 4 )
      {
        v24 = m_pBuf->m_nInBufWord;
        v18 = v24 & 0xF;
        v25 = v16 - 4;
        m_pBuf->m_nBitsAvail = v25;
        if ( v25 != 0 )
        {
          m_pBuf->m_nInBufWord = v24 >> 4;
          v20 = v24 & 0xF;
          goto LABEL_49;
        }
        goto LABEL_33;
      }
      v21 = 4;
LABEL_40:
      v29 = m_pBuf->m_pBufferEnd;
      v30 = m_pBuf->m_nInBufWord;
      v31 = v21 - v16;
      v32 = m_pBuf->m_pDataIn;
      if ( v32 == v29 )
      {
        m_pBuf->m_nBitsAvail = 1;
        m_pBuf->m_nInBufWord = 0;
        m_pBuf->m_bOverflow = true;
      }
      else
      {
        if ( v32 > v29 )
        {
          m_pBuf->m_bOverflow = true;
          m_pBuf->m_nInBufWord = 0;
          goto LABEL_46;
        }
        m_pBuf->m_nInBufWord = *v32;
      }
      m_pBuf->m_pDataIn = v32 + 1;
LABEL_46:
      if ( m_pBuf->m_bOverflow )
      {
        v20 = 0;
      }
      else
      {
        v33 = m_pBuf->m_nInBufWord;
        v34 = (v33 & CBitBuffer::s_nMaskTable[v31]) << m_pBuf->m_nBitsAvail;
        m_pBuf->m_nBitsAvail = 32 - v31;
        m_pBuf->m_nInBufWord = v33 >> v31;
        v20 = v34 | v30;
      }
      goto LABEL_49;
    case 32:
      v16 = m_pBuf->m_nBitsAvail;
      if ( v16 >= 8 )
      {
        v22 = m_pBuf->m_nInBufWord;
        v18 = (unsigned __int8)v22;
        v23 = v16 - 8;
        m_pBuf->m_nBitsAvail = v23;
        if ( v23 != 0 )
        {
          m_pBuf->m_nInBufWord = v22 >> 8;
          v20 = (unsigned __int8)v22;
          goto LABEL_49;
        }
LABEL_33:
        v26 = m_pBuf->m_pDataIn;
        v27 = m_pBuf->m_pBufferEnd;
        m_pBuf->m_nBitsAvail = 32;
        if ( v26 == v27 )
        {
          m_pBuf->m_nBitsAvail = 1;
          m_pBuf->m_nInBufWord = 0;
          m_pBuf->m_pDataIn = v26 + 1;
          v20 = v18;
        }
        else
        {
          if ( v26 <= v27 )
          {
            v28 = *v26;
            m_pBuf->m_pDataIn = v26 + 1;
            m_pBuf->m_nInBufWord = v28;
          }
          else
          {
            m_pBuf->m_bOverflow = true;
            m_pBuf->m_nInBufWord = 0;
          }
          v20 = v18;
        }
        goto LABEL_49;
      }
      v21 = 8;
      goto LABEL_40;
    case 48:
      v16 = m_pBuf->m_nBitsAvail;
      if ( v16 < 28 )
      {
        v21 = 28;
        goto LABEL_40;
      }
      v17 = m_pBuf->m_nInBufWord;
      v18 = v17 & 0xFFFFFFF;
      v19 = v16 - 28;
      m_pBuf->m_nBitsAvail = v19;
      if ( v19 == 0 )
        goto LABEL_33;
      m_pBuf->m_nInBufWord = v17 >> 28;
      v20 = v17 & 0xFFFFFFF;
LABEL_49:
      v52 = v52 & 0xF | (16 * v20);
      break;
    default:
      break;
  }
  v35 = v52 + u->m_nHeaderBase + 1;
  u->m_nNewEntity = v35;
  u->m_nHeaderBase = v35;
  v36 = u->m_pBuf;
  v37 = v36->m_nInBufWord;
  v38 = v37 & 1;
  v39 = v36->m_nBitsAvail-- == 1;
  if ( v39 )
  {
    v40 = v36->m_pDataIn;
    v41 = v36->m_pBufferEnd;
    v36->m_nBitsAvail = 32;
    if ( v40 == v41 )
    {
      v36->m_nBitsAvail = 1;
      v36->m_nInBufWord = 0;
      v36->m_pDataIn = v40 + 1;
    }
    else if ( v40 <= v41 )
    {
      v36->m_nInBufWord = *v40;
      v36->m_pDataIn = v40 + 1;
    }
    else
    {
      v36->m_bOverflow = true;
      v36->m_nInBufWord = 0;
    }
  }
  else
  {
    v36->m_nInBufWord = v37 >> 1;
  }
  if ( v38 != 0 )
  {
    u->m_UpdateFlags |= 1u;
    v47 = u->m_pBuf;
    v48 = v47->m_nInBufWord;
    v49 = v48 & 1;
    v39 = v47->m_nBitsAvail-- == 1;
    if ( v39 )
    {
      v50 = v47->m_pDataIn;
      v51 = v47->m_pBufferEnd;
      v47->m_nBitsAvail = 32;
      if ( v50 == v51 )
      {
        v47->m_nBitsAvail = 1;
        v47->m_nInBufWord = 0;
        v47->m_pDataIn = v50 + 1;
      }
      else if ( v50 <= v51 )
      {
        v47->m_nInBufWord = *v50;
        v47->m_pDataIn = v50 + 1;
      }
      else
      {
        v47->m_bOverflow = true;
        v47->m_nInBufWord = 0;
      }
    }
    else
    {
      v47->m_nInBufWord = v48 >> 1;
    }
    if ( v49 != 0 )
      u->m_UpdateFlags |= 2u;
  }
  else
  {
    v42 = u->m_pBuf;
    v43 = v42->m_nInBufWord;
    v44 = v43 & 1;
    v39 = v42->m_nBitsAvail-- == 1;
    if ( v39 )
    {
      v45 = v42->m_pDataIn;
      v46 = v42->m_pBufferEnd;
      v42->m_nBitsAvail = 32;
      if ( v45 == v46 )
      {
        v42->m_nBitsAvail = 1;
        v42->m_nInBufWord = 0;
        v42->m_pDataIn = v45 + 1;
      }
      else if ( v45 <= v46 )
      {
        v42->m_nInBufWord = *v45;
        v42->m_pDataIn = v45 + 1;
      }
      else
      {
        v42->m_bOverflow = true;
        v42->m_nInBufWord = 0;
      }
    }
    else
    {
      v42->m_nInBufWord = v43 >> 1;
    }
    if ( v44 != 0 )
      u->m_UpdateFlags |= 4u;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1017DC40
// Name: HLTV_Callback_InstanceBaseline
// Source: json
//------------------------------------------------------------------------------
void __cdecl HLTV_Callback_InstanceBaseline(CHLTVServer *object)
{
  CHLTVServer::LinkInstanceBaselines(this: object);
}

//------------------------------------------------------------------------------
// Address: 0x1017DC50
// Name: public: CHLTVClientState::CHLTVClientState(void)
// Source: json
//------------------------------------------------------------------------------
CHLTVClientState *__thiscall CHLTVClientState::CHLTVClientState(CHLTVClientState *this)
{
  CBaseClientState::CBaseClientState(this);
  this->m_pNewClientFrame = nullptr;
  this->m_pCurrentClientFrame = nullptr;
  this->m_bSaveMemory = false;
  this->CBaseClientState::INetChannelHandler::__vftable = (CHLTVClientState_vtbl *)&CHLTVClientState::`vftable'{for `INetChannelHandler'};
  this->CBaseClientState::IConnectionlessPacketHandler::__vftable = (IConnectionlessPacketHandler_vtbl *)&CHLTVClientState::`vftable'{for `IConnectionlessPacketHandler'};
  this->CBaseClientState::IServerMessageHandler::INetMessageHandler::__vftable = (IServerMessageHandler_vtbl *)&CHLTVClientState::`vftable'{for `IServerMessageHandler'};
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1017DC90
// Name: public: virtual char const __near * CHLTVClientState::GetCDKeyHash(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CHLTVClientState::GetCDKeyHash(CHLTVClientState *this)
{
  return "HLTVHLTVHLTVHLTVHLTVHLTVHLTVHLTV";
}

//------------------------------------------------------------------------------
// Address: 0x1017DCD0
// Name: public: virtual CHLTVClientState::~CHLTVClientState(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHLTVClientState::~CHLTVClientState(CHLTVClientState *this)
{
  this->CBaseClientState::INetChannelHandler::__vftable = (CHLTVClientState_vtbl *)&CHLTVClientState::`vftable'{for `INetChannelHandler'};
  this->CBaseClientState::IConnectionlessPacketHandler::__vftable = (IConnectionlessPacketHandler_vtbl *)&CHLTVClientState::`vftable'{for `IConnectionlessPacketHandler'};
  this->CBaseClientState::IServerMessageHandler::INetMessageHandler::__vftable = (IServerMessageHandler_vtbl *)&CHLTVClientState::`vftable'{for `IServerMessageHandler'};
  CBaseClientState::~CBaseClientState(this);
}

//------------------------------------------------------------------------------
// Address: 0x1017DCF0
// Name: public: virtual bool CHLTVClientState::ProcessSetConVar(class NET_SetConVar __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CHLTVClientState::ProcessSetConVar(CHLTVClientState *this, NET_SetConVar *msg)
{
  char result; // al

  result = CBaseClientState::ProcessSetConVar(this, msg);
  if ( result != 0 )
    return CHLTVServer::SendNetMsg(
             this: *(CHLTVServer **)&this->m_bSaveMemory,
             msg,
             bForceReliable: false,
             bVoice: false);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1017DD20
// Name: public: virtual void CHLTVClientState::Clear(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHLTVClientState::Clear(CHLTVClientState *this)
{
  CBaseClientState::Clear(this);
  this->m_pNewClientFrame = nullptr;
  this->m_pCurrentClientFrame = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1017DD40
// Name: public: virtual bool CHLTVClientState::ProcessServerInfo(class SVC_ServerInfo __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CHLTVClientState::ProcessServerInfo(CHLTVClientState *this, SVC_ServerInfo *msg)
{
  const char *v3; // eax
  CNetworkStringTableContainer *v5; // ecx

  (*(void (__thiscall **)(char *))(*((_DWORD *)this - 2) + 44))(a1: (char *)this - 8);
  if ( (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)(*(_DWORD *)&this->m_bSaveMemory + 524) + 24))(a1: *(_DWORD *)&this->m_bSaveMemory + 524) == 0
    && !msg->m_bIsHLTV )
  {
    v3 = (const char *)(*((int (__thiscall **)(IServerMessageHandler_vtbl *))this->dtr_INetMessageHandler + 1))(a1: this->CBaseClientState::IServerMessageHandler::INetMessageHandler::__vftable);
    ConMsg(a1: "Server (%s) is not a SourceTV proxy.\n", v3);
LABEL_4:
    (*(void (__thiscall **)(char *, int))(*((_DWORD *)this - 2) + 64))(a1: (char *)this - 8, a2: 1);
    return 0;
  }
  CHLTVServer::StartRelay(this: *(CHLTVServer **)&this->m_bSaveMemory);
  if ( CBaseClientState::ProcessServerInfo(this, a2: (int)this, msg) == 0 )
    goto LABEL_4;
  v5 = *(CNetworkStringTableContainer **)(*(_DWORD *)&this->m_bSaveMemory + 196);
  *(_DWORD *)&this->m_szEncryptionKey[2044] = v5;
  CNetworkStringTableContainer::EnableRollback(this: v5, bState: false);
  *(_DWORD *)(*(_DWORD *)&this->m_bSaveMemory + 21352) = *(_DWORD *)&this->m_szLastLevelNameShort[32];
  *(_DWORD *)(*(_DWORD *)&this->m_bSaveMemory + 256) = this->m_pEntityBaselines[1][2047];
  *(_DWORD *)(*(_DWORD *)&this->m_bSaveMemory + 260) = this->m_pServerClasses;
  *(_DWORD *)(*(_DWORD *)&this->m_bSaveMemory + 20908) = *(_DWORD *)&this->m_bPaused;
  *(_DWORD *)(*(_DWORD *)&this->m_bSaveMemory + 184) = msg->m_nMapCRC;
  *(_DWORD *)(*(_DWORD *)&this->m_bSaveMemory + 188) = msg->m_nClientCRC;
  *(_DWORD *)(*(_DWORD *)&this->m_bSaveMemory + 192) = msg->m_nStringTableCRC;
  *(float *)(*(_DWORD *)&this->m_bSaveMemory + 276) = msg->m_fTickInterval;
  host_state.interval_per_tick = msg->m_fTickInterval;
  V_strncpy(pDest: (char *)(*(_DWORD *)&this->m_bSaveMemory + 24), pSrc: msg->m_szMapName, maxLen: 64);
  V_strncpy(pDest: (char *)(*(_DWORD *)&this->m_bSaveMemory + 88), pSrc: msg->m_szSkyName, maxLen: 64);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1017DEA0
// Name: public: virtual bool CHLTVClientState::ProcessClassInfo(class SVC_ClassInfo __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CHLTVClientState::ProcessClassInfo(CHLTVClientState *this, SVC_ClassInfo *msg)
{
  CBaseClientState *v4; // esi
  const CStandardSendProxies *v5; // eax

  if ( msg->m_bCreateOnClient )
  {
    DataTable_CreateClientTablesFromServerTables();
    v4 = (CHLTVClientState *)((char *)this - 8);
    DataTable_CreateClientClassInfosFromServerClasses(pState: v4);
    v4->LinkClasses(this: v4);
    v5 = serverGameDLL->GetStandardSendProxies(this: serverGameDLL);
    if ( RecvTable_CreateDecoders(pSendProxies: v5) )
    {
      return 1;
    }
    else
    {
      Host_EndGame(bShowMainMenu: true, message: "CL_ParseClassInfo_EndClasses: CreateDecoders failed.\n");
      return 0;
    }
  }
  else
  {
    ConMsg(a1: "HLTV SendTable CRC differs from server.\n");
    (*(void (__thiscall **)(char *, int))(*((_DWORD *)this - 2) + 64))(a1: (char *)this - 8, a2: 1);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1017DF30
// Name: public: virtual void CHLTVClientState::PacketEnd(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHLTVClientState::PacketEnd(CHLTVClientState *this)
{
  CClientFrame *m_pNewClientFrame; // eax
  CClientFrame *v3; // eax
  CClientFrame *v4; // ecx

  m_pNewClientFrame = this->m_pNewClientFrame;
  if ( m_pNewClientFrame != nullptr )
  {
    v3 = CHLTVServer::AddNewFrame(this: this->m_pHLTV, clientFrame: m_pNewClientFrame);
    v4 = this->m_pNewClientFrame;
    this->m_pCurrentClientFrame = v3;
    if ( v4 != nullptr )
      ((void (__thiscall *)(CClientFrame *, int))v4->dtr_CClientFrame)(a1: v4, a2: 1);
    this->m_pNewClientFrame = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1017DF70
// Name: public: virtual bool CHLTVClientState::HookClientStringTable(char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CHLTVClientState::HookClientStringTable(CHLTVClientState *this, const char *tableName)
{
  INetworkStringTable *StringTable; // esi

  StringTable = CBaseClientState::GetStringTable(this, name: tableName);
  if ( StringTable == nullptr || V_strcasecmp(s1: tableName, s2: "instancebaseline") != 0 )
    return 0;
  StringTable->SetStringChangedCallback(this: StringTable, a2: this->m_pHLTV, a3: HLTV_Callback_InstanceBaseline);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1017DFC0
// Name: public: virtual void CHLTVClientState::InstallStringTableCallback(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHLTVClientState::InstallStringTableCallback(CHLTVClientState *this, const char *tableName)
{
  INetworkStringTable *StringTable; // esi

  StringTable = CBaseClientState::GetStringTable(this, name: tableName);
  if ( StringTable != nullptr && V_strcasecmp(s1: tableName, s2: "instancebaseline") == 0 )
    StringTable->SetStringChangedCallback(this: StringTable, a2: this->m_pHLTV, a3: HLTV_Callback_InstanceBaseline);
}

//------------------------------------------------------------------------------
// Address: 0x1017E010
// Name: public: virtual bool CHLTVClientState::ProcessSetView(class SVC_SetView __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CHLTVClientState::ProcessSetView(CHLTVClientState *this, SVC_SetView *msg)
{
  char result; // al

  result = CBaseClientState::ProcessSetView(this, msg);
  if ( result != 0 )
    return CHLTVServer::SendNetMsg(
             this: *(CHLTVServer **)&this->m_bSaveMemory,
             msg,
             bForceReliable: false,
             bVoice: false);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1017E040
// Name: public: virtual bool CHLTVClientState::ProcessVoiceData(class SVC_VoiceData __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CHLTVClientState::ProcessVoiceData(CHLTVClientState *this, SVC_VoiceData *msg)
{
  int m_nLength; // edi
  void *v3; // esp
  CHLTVClientState *v4; // eax
  char v6[12]; // [esp+0h] [ebp-10h] BYREF
  CHLTVClientState *v7; // [esp+Ch] [ebp-4h]

  m_nLength = msg->m_nLength;
  v7 = this;
  v3 = alloca(4 * ((((m_nLength + 7) >> 3) + 3) / 4));
  CBitRead::ReadBits(this: &msg->m_DataIn, pOutData: v6, nBits: m_nLength);
  v4 = v7;
  msg->m_DataOut = v6;
  return CHLTVServer::SendNetMsg(this: *(CHLTVServer **)&v4->m_bSaveMemory, msg, bForceReliable: false, bVoice: false);
}

//------------------------------------------------------------------------------
// Address: 0x1017E0A0
// Name: public: virtual bool CHLTVClientState::ProcessGameEvent(class SVC_GameEvent __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CHLTVClientState::ProcessGameEvent(CHLTVClientState *this, SVC_GameEvent *msg)
{
  IGameEvent *v3; // eax
  IGameEvent *v4; // esi
  const char *v5; // edi
  int v6; // eax
  CHLTVClientState *v7; // edi
  const char *v8; // eax
  int m_nLength; // edi
  int v11; // esi
  void *v12; // esp
  char v13[12]; // [esp+0h] [ebp-34h] BYREF
  bf_read tmpBuf; // [esp+Ch] [ebp-28h] BYREF
  CHLTVClientState *v15; // [esp+30h] [ebp-4h]
  char bDontForward_3; // [esp+3Fh] [ebp+Bh]

  v15 = this;
  tmpBuf = msg->m_DataIn;
  v3 = g_GameEventManager->UnserializeEvent(this: g_GameEventManager, a2: &tmpBuf);
  v4 = v3;
  if ( v3 == nullptr )
    goto LABEL_8;
  v5 = v3->GetName(this: v3);
  bDontForward_3 = 0;
  if ( _V_strcmp(s1: v5, s2: "hltv_status") != 0 )
  {
    if ( _V_strcmp(s1: v5, s2: "hltv_title") != 0 )
      goto LABEL_6;
  }
  else
  {
    v6 = ((int (__thiscall *)(IGameEvent *, const char *))v4->GetInt)(a1: v4, a2: "slots");
    v7 = v15;
    *(_DWORD *)(*(_DWORD *)&v15->m_bSaveMemory + 25488) = v6;
    *(_DWORD *)(*(_DWORD *)&v7->m_bSaveMemory + 25496) = v4->GetInt(this: v4, a2: "proxies", a3: 0);
    *(_DWORD *)(*(_DWORD *)&v7->m_bSaveMemory + 25492) = v4->GetInt(this: v4, a2: "clients", a3: 0);
    v8 = (const char *)((int (__thiscall *)(IGameEvent *, const char *, const char *, _DWORD))v4->GetString)(
                         a1: v4,
                         a2: "master",
                         a3: defaultValue,
                         a4: 0);
    netadr_s::SetFromString(this: (netadr_s *)(*(_DWORD *)&v7->m_bSaveMemory + 25476), pch: v8, bUseDNS: false);
  }
  bDontForward_3 = 1;
LABEL_6:
  g_GameEventManager->FreeEvent(this: g_GameEventManager, a2: v4);
  if ( bDontForward_3 != 0 )
    return true;
LABEL_8:
  m_nLength = msg->m_nLength;
  v11 = 4 * ((((m_nLength + 7) >> 3) + 3) / 4);
  v12 = alloca(v11);
  CBitRead::ReadBits(this: &msg->m_DataIn, pOutData: v13, nBits: m_nLength);
  bf_write::StartWriting(this: &msg->m_DataOut, pData: v13, nBytes: v11, iStartBit: msg->m_nLength, nBits: -1);
  return CHLTVServer::SendNetMsg(this: *(CHLTVServer **)&v15->m_bSaveMemory, msg, bForceReliable: false, bVoice: false);
}

//------------------------------------------------------------------------------
// Address: 0x1017E220
// Name: public: virtual bool CHLTVClientState::ProcessTempEntities(class SVC_TempEntities __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CHLTVClientState::ProcessTempEntities(CHLTVClientState *this, SVC_TempEntities *msg)
{
  int m_nLength; // ebx
  int v3; // esi
  void *v4; // esp
  char v6[12]; // [esp+0h] [ebp-10h] BYREF
  CHLTVClientState *v7; // [esp+Ch] [ebp-4h]

  m_nLength = msg->m_nLength;
  v3 = 4 * ((((m_nLength + 7) >> 3) + 3) / 4);
  v7 = this;
  v4 = alloca(v3);
  CBitRead::ReadBits(this: &msg->m_DataIn, pOutData: v6, nBits: m_nLength);
  bf_write::StartWriting(this: &msg->m_DataOut, pData: v6, nBytes: v3, iStartBit: msg->m_nLength, nBits: -1);
  return CHLTVServer::SendNetMsg(this: *(CHLTVServer **)&v7->m_bSaveMemory, msg, bForceReliable: false, bVoice: false);
}

//------------------------------------------------------------------------------
// Address: 0x1017E2A0
// Name: public: virtual bool CHLTVClientState::ProcessSounds(class SVC_Sounds __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CHLTVClientState::ProcessSounds(CHLTVClientState *this, SVC_EntityMessage *msg)
{
  int m_nLength; // ebx
  int v3; // esi
  void *v4; // esp
  char v6[12]; // [esp+0h] [ebp-10h] BYREF
  CHLTVClientState *v7; // [esp+Ch] [ebp-4h]

  m_nLength = msg->m_nLength;
  v3 = 4 * ((((m_nLength + 7) >> 3) + 3) / 4);
  v7 = this;
  v4 = alloca(v3);
  CBitRead::ReadBits(this: &msg->m_DataIn, pOutData: v6, nBits: m_nLength);
  bf_write::StartWriting(this: &msg->m_DataOut, pData: v6, nBytes: v3, iStartBit: msg->m_nLength, nBits: -1);
  return CHLTVServer::SendNetMsg(this: *(CHLTVServer **)&v7->m_bSaveMemory, msg, bForceReliable: false, bVoice: false);
}

//------------------------------------------------------------------------------
// Address: 0x1017E320
// Name: public: virtual bool CHLTVClientState::ProcessPrefetch(class SVC_Prefetch __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CHLTVClientState::ProcessPrefetch(CHLTVClientState *this, SVC_PaintmapData *msg)
{
  return CHLTVServer::SendNetMsg(this: *(CHLTVServer **)&this->m_bSaveMemory, msg, bForceReliable: false, bVoice: false);
}

//------------------------------------------------------------------------------
// Address: 0x1017E340
// Name: public: void CHLTVClientState::ReadDeletions(class CEntityReadInfo __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHLTVClientState::ReadDeletions(CHLTVClientState *this, CEntityReadInfo *u)
{
  bf_read *m_pBuf; // eax
  unsigned int m_nInBufWord; // ecx
  int v4; // edx
  const unsigned int *m_pDataIn; // ecx
  const unsigned int *m_pBufferEnd; // esi
  bf_read *v8; // eax
  int m_nBitsAvail; // ecx
  unsigned int v10; // edx
  int v11; // esi
  int v12; // ecx
  int v13; // eax
  const unsigned int *v14; // ecx
  const unsigned int *v15; // edx
  unsigned int v16; // edx
  const unsigned int *v17; // esi
  unsigned int v18; // edi
  int v19; // edx
  const unsigned int *v20; // ecx
  unsigned int v21; // esi
  unsigned int v22; // ebx
  CFrameSnapshotEntry *v23; // eax

  while ( 1 )
  {
    m_pBuf = u->m_pBuf;
    m_nInBufWord = m_pBuf->m_nInBufWord;
    v4 = m_nInBufWord & 1;
    if ( m_pBuf->m_nBitsAvail-- == 1 )
    {
      m_pDataIn = m_pBuf->m_pDataIn;
      m_pBufferEnd = m_pBuf->m_pBufferEnd;
      m_pBuf->m_nBitsAvail = 32;
      if ( m_pDataIn == m_pBufferEnd )
      {
        m_pBuf->m_nBitsAvail = 1;
        m_pBuf->m_nInBufWord = 0;
        m_pBuf->m_pDataIn = m_pDataIn + 1;
      }
      else if ( m_pDataIn <= m_pBufferEnd )
      {
        m_pBuf->m_nInBufWord = *m_pDataIn;
        m_pBuf->m_pDataIn = m_pDataIn + 1;
      }
      else
      {
        m_pBuf->m_bOverflow = true;
        m_pBuf->m_nInBufWord = 0;
      }
    }
    else
    {
      m_pBuf->m_nInBufWord = m_nInBufWord >> 1;
    }
    if ( v4 == 0 )
      break;
    v8 = u->m_pBuf;
    m_nBitsAvail = v8->m_nBitsAvail;
    if ( m_nBitsAvail < 11 )
    {
      v17 = v8->m_pBufferEnd;
      v18 = v8->m_nInBufWord;
      v19 = 11 - m_nBitsAvail;
      v20 = v8->m_pDataIn;
      if ( v20 == v17 )
      {
        v8->m_nBitsAvail = 1;
        v8->m_nInBufWord = 0;
        v8->m_bOverflow = true;
        goto LABEL_23;
      }
      if ( v20 <= v17 )
      {
        v8->m_nInBufWord = *v20;
LABEL_23:
        v8->m_pDataIn = v20 + 1;
      }
      else
      {
        v8->m_bOverflow = true;
        v8->m_nInBufWord = 0;
      }
      if ( v8->m_bOverflow )
      {
        v13 = 0;
      }
      else
      {
        v21 = v8->m_nInBufWord;
        v22 = (v21 & CBitBuffer::s_nMaskTable[v19]) << v8->m_nBitsAvail;
        v8->m_nBitsAvail = 32 - v19;
        v8->m_nInBufWord = v21 >> v19;
        v13 = v22 | v18;
      }
      goto LABEL_27;
    }
    v10 = v8->m_nInBufWord;
    v11 = v10 & 0x7FF;
    v12 = m_nBitsAvail - 11;
    v8->m_nBitsAvail = v12;
    if ( v12 != 0 )
    {
      v8->m_nInBufWord = v10 >> 11;
      v13 = v10 & 0x7FF;
    }
    else
    {
      v14 = v8->m_pDataIn;
      v15 = v8->m_pBufferEnd;
      v8->m_nBitsAvail = 32;
      if ( v14 == v15 )
      {
        v8->m_nBitsAvail = 1;
        v8->m_nInBufWord = 0;
        v8->m_pDataIn = v14 + 1;
        v13 = v11;
      }
      else
      {
        if ( v14 <= v15 )
        {
          v16 = *v14;
          v8->m_pDataIn = v14 + 1;
          v8->m_nInBufWord = v16;
        }
        else
        {
          v8->m_bOverflow = true;
          v8->m_nInBufWord = 0;
        }
        v13 = v11;
      }
    }
LABEL_27:
    v23 = &u->m_pTo->m_pSnapshot->m_pEntities[v13];
    v23->m_nSerialNumber = -1;
    v23->m_pClass = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1017E510
// Name: public: void CHLTVClientState::SendPacket(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHLTVClientState::SendPacket(CHLTVClientState *this)
{
  int m_nDeltaTick; // eax
  INetChannel *m_NetChannel; // ecx
  int m_nValue; // eax
  long double v5; // st6
  long double v6; // st5
  NET_Tick tick; // [esp+4h] [ebp-24h] BYREF
  float commandInterval; // [esp+20h] [ebp-8h]
  float maxDelta; // [esp+24h] [ebp-4h]

  if ( this->m_nSignonState >= 2
    && this->m_flNextCmdTime <= net_time
    && this->m_NetChannel->CanPacket(this: this->m_NetChannel) )
  {
    if ( this->m_nSignonState == 6 )
    {
      m_nDeltaTick = this->m_nDeltaTick;
      m_NetChannel = this->m_NetChannel;
      tick.m_flHostFrameTime = host_frametime_unbounded;
      tick.m_nTick = m_nDeltaTick;
      tick.m_NetChannel = nullptr;
      tick.__vftable = (NET_Tick_vtbl *)&NET_Tick::`vftable';
      tick.m_bReliable = false;
      tick.m_flHostFrameTimeStdDeviation = host_frametime_stddeviation;
      m_NetChannel->SendNetMsg(this: m_NetChannel, a2: &tick, a3: false, a4: false);
    }
    this->m_NetChannel->SendDatagram(this: this->m_NetChannel, a2: nullptr);
    if ( this->m_nSignonState == 6 )
    {
      if ( tv_snapshotrate.m_pParent != nullptr )
        m_nValue = tv_snapshotrate.m_pParent->m_Value.m_nValue;
      else
        m_nValue = 0;
      commandInterval = 0.66666669 / (float)m_nValue;
      if ( commandInterval <= host_state.interval_per_tick )
        maxDelta = 0.66666669 / (float)m_nValue;
      else
        maxDelta = host_state.interval_per_tick;
      v5 = net_time - this->m_flNextCmdTime;
      v6 = 0.0;
      if ( v5 < 0.0 || (v6 = v5, v5 <= maxDelta) )
        this->m_flNextCmdTime = net_time + commandInterval - v6;
      else
        this->m_flNextCmdTime = net_time + commandInterval - maxDelta;
    }
    else
    {
      this->m_flNextCmdTime = net_time + 0.2;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1017E650
// Name: public: virtual bool CHLTVClientState::ProcessPacketEntities(class SVC_PacketEntities __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CHLTVClientState::ProcessPacketEntities(CHLTVClientState *this, SVC_PacketEntities *entmsg)
{
  bool v3; // zf
  int m_nDeltaFrom; // eax
  CFrameSnapshot *EmptySnapshot; // ebx
  CClientFrame *v8; // eax
  CNetworkStringTableContainer *v9; // eax
  float v10; // eax
  IServerMessageHandler_vtbl *v11; // ecx
  int v12; // eax
  int v13; // edx
  CFrameSnapshotEntry *m_pEntities; // eax
  ServerClass **v15; // ecx
  CNetworkStringTableContainer *m_StringTableContainer; // edx
  bool m_bIsDelta; // al
  int m_nUpdatedEntries; // ecx
  bool m_bUpdateBaseline; // al
  int v20; // edx
  void (__thiscall *v21)(char *, void ***); // edx
  void **v22; // [esp+8h] [ebp-4064h] BYREF
  bool v23; // [esp+Ch] [ebp-4060h]
  CClientFrame *v24; // [esp+10h] [ebp-405Ch]
  CNetworkStringTableContainer *v25; // [esp+14h] [ebp-4058h]
  int v26; // [esp+18h] [ebp-4054h]
  int v27; // [esp+1Ch] [ebp-4050h]
  int v28; // [esp+20h] [ebp-404Ch]
  int v29; // [esp+24h] [ebp-4048h]
  int v30; // [esp+28h] [ebp-4044h]
  bf_read *p_m_DataIn; // [esp+2Ch] [ebp-4040h]
  int v32; // [esp+38h] [ebp-4034h]
  bool v33; // [esp+3Ch] [ebp-4030h]
  int v34; // [esp+40h] [ebp-402Ch]
  int v35; // [esp+44h] [ebp-4028h]
  int v36; // [esp+4048h] [ebp-24h]
  void **v37; // [esp+404Ch] [ebp-20h] BYREF
  char v38; // [esp+4050h] [ebp-1Ch]
  int v39; // [esp+4054h] [ebp-18h]
  float v40; // [esp+405Ch] [ebp-10h]
  int m_nBaseline; // [esp+4060h] [ebp-Ch]
  CFrameSnapshot *v42; // [esp+4064h] [ebp-8h]
  CClientFrame *ClientFrame; // [esp+4068h] [ebp-4h]
  SVC_PacketEntities *msg; // [esp+4074h] [ebp+8h]

  v3 = !entmsg->m_bIsDelta;
  ClientFrame = nullptr;
  if ( !v3 )
  {
    m_nDeltaFrom = entmsg->m_nDeltaFrom;
    if ( LODWORD(this->m_ClockDriftMgr.m_ClockOffsets[15]) == m_nDeltaFrom )
    {
      Host_Error(error: "Update self-referencing, connection dropped.\n");
      return 0;
    }
    ClientFrame = CClientFrameManager::GetClientFrame(
                    this: (CClientFrameManager *)(*(_DWORD *)&this->m_bSaveMemory + 464),
                    nTick: m_nDeltaFrom,
                    bExact: true);
  }
  EmptySnapshot = CFrameSnapshotManager::CreateEmptySnapshot(
                    this: framesnapshotmanager,
                    tickcount: LODWORD(this->m_ClockDriftMgr.m_ClockOffsets[15]),
                    maxEntities: entmsg->m_nMaxEntries);
  v42 = EmptySnapshot;
  v8 = (CClientFrame *)MemAlloc_Alloc(nSize: 0x11Cu);
  if ( v8 != nullptr )
    v9 = (CNetworkStringTableContainer *)CClientFrame::CClientFrame(this: v8, pSnapshot: EmptySnapshot);
  else
    v9 = nullptr;
  this->m_StringTableContainer = v9;
  if ( entmsg->m_bUpdateBaseline )
  {
    CBaseClientState::CopyEntityBaseline(
      this: (CHLTVClientState *)((char *)this - 8),
      iFrom: entmsg->m_nBaseline,
      iTo: entmsg->m_nBaseline == 0);
    v10 = this->m_ClockDriftMgr.m_ClockOffsets[15];
    m_nBaseline = entmsg->m_nBaseline;
    v11 = this->CBaseClientState::IServerMessageHandler::INetMessageHandler::__vftable;
    v40 = v10;
    v38 = 1;
    v39 = 0;
    v37 = &CLC_BaselineAck::`vftable';
    (*((void (__thiscall **)(IServerMessageHandler_vtbl *, void ***, int, _DWORD))v11->dtr_INetMessageHandler + 41))(
      a1: v11,
      a2: &v37,
      a3: 1,
      a4: 0);
  }
  v12 = *(_DWORD *)&this->m_bRestrictServerCommands;
  if ( v12 != 0 )
  {
    v13 = *(_DWORD *)(v12 + 280);
    m_pEntities = EmptySnapshot->m_pEntities;
    v15 = *(ServerClass ***)(v13 + 8);
    for ( msg = nullptr; (int)msg < *(_DWORD *)(v13 + 12); msg = (SVC_PacketEntities *)((char *)msg + 1) )
    {
      m_pEntities->m_nSerialNumber = (int)v15[1];
      m_pEntities->m_pClass = *v15;
      ++m_pEntities;
      v15 += 3;
    }
    EmptySnapshot = v42;
  }
  m_StringTableContainer = this->m_StringTableContainer;
  v27 = -1;
  v28 = -1;
  v29 = -1;
  v36 = 0;
  v34 = 0;
  v35 = 0;
  p_m_DataIn = &entmsg->m_DataIn;
  m_bIsDelta = entmsg->m_bIsDelta;
  v24 = ClientFrame;
  m_nUpdatedEntries = entmsg->m_nUpdatedEntries;
  v23 = m_bIsDelta;
  m_bUpdateBaseline = entmsg->m_bUpdateBaseline;
  v25 = m_StringTableContainer;
  v20 = entmsg->m_nBaseline;
  v30 = m_nUpdatedEntries;
  v32 = v20;
  v21 = *(void (__thiscall **)(char *, void ***))(*((_DWORD *)this - 2) + 128);
  v33 = m_bUpdateBaseline;
  v22 = &CEntityReadInfo::`vftable';
  v26 = 3;
  v21(a1: (char *)this - 8, a2: &v22);
  CFrameSnapshot::ReleaseReference(this: EmptySnapshot);
  return CBaseClientState::ProcessPacketEntities(this, msg: entmsg);
}

//------------------------------------------------------------------------------
// Address: 0x1017E830
// Name: public: virtual int CHLTVClientState::GetConnectionRetryNumber(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CHLTVClientState::GetConnectionRetryNumber(CHLTVClientState *this)
{
  int result; // eax

  if ( tv_autoretry.m_pParent == nullptr )
    return this->m_nRetryMax;
  result = 16;
  if ( tv_autoretry.m_pParent->m_Value.m_nValue == 0 )
    return this->m_nRetryMax;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1017E850
// Name: public: virtual void CHLTVClientState::ConnectionCrashed(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHLTVClientState::ConnectionCrashed(CHLTVClientState *this, const char *reason)
{
  Remote_t *v3; // eax
  const char *v4; // eax
  vgui::CTreeViewListControl *v5; // ecx
  ECommandTarget_t TraceType; // eax
  const char *v7; // [esp-8h] [ebp-Ch]

  CBaseClientState::ConnectionCrashed(this, reason);
  if ( tv_autoretry.m_pParent != nullptr
    && tv_autoretry.m_pParent->m_Value.m_nValue != 0
    && vgui::Image::GetWide(this: (CVTFTexture *)&this->m_Remote) > 0 )
  {
    v3 = CAddressList::Get(this: &this->m_Remote, index: 0);
    v4 = CUtlString::operator char const *(this: &v3->m_szRetryAddress);
    v7 = va(format: "tv_relay %s\n", v4);
    TraceType = CTraceFilter::GetTraceType(this: v5);
    Cbuf_AddText(eTarget: TraceType, pText: v7, nTickDelay: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1017E8B0
// Name: public: virtual void CHLTVClientState::ConnectionClosing(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHLTVClientState::ConnectionClosing(CHLTVClientState *this, const char *reason)
{
  Remote_t *v3; // eax
  const char *v4; // eax
  vgui::CTreeViewListControl *v5; // ecx
  ECommandTarget_t TraceType; // eax
  const char *v7; // [esp-8h] [ebp-Ch]

  CBaseClientState::ConnectionClosing(this, reason);
  if ( tv_autoretry.m_pParent != nullptr
    && tv_autoretry.m_pParent->m_Value.m_nValue != 0
    && vgui::Image::GetWide(this: (CVTFTexture *)&this->m_Remote) > 0 )
  {
    v3 = CAddressList::Get(this: &this->m_Remote, index: 0);
    v4 = CUtlString::operator char const *(this: &v3->m_szRetryAddress);
    v7 = va(format: "tv_relay %s\n", v4);
    TraceType = CTraceFilter::GetTraceType(this: v5);
    Cbuf_AddText(eTarget: TraceType, pText: v7, nTickDelay: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1017E910
// Name: public: void CHLTVClientState::CopyNewEntity(class CEntityReadInfo __near &,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHLTVClientState::CopyNewEntity(CHLTVClientState *this, CFrameSnapshot *u, int iClass, int iSerialNum)
{
  ClientClass *ClientClass; // eax
  int m_pHLTVEntityData; // edi
  CFrameSnapshot *v8; // ecx
  int v9; // eax
  ServerClass *v10; // ebx
  PackedEntity *EntityBaseline; // eax
  int v12; // eax
  int NumFlatProps; // eax
  IChangeFrameList *v14; // ebx
  PackedEntity *PackedEntity; // eax
  int v16; // eax
  _DWORD *v17; // eax
  ServerClass *v18; // [esp-8h] [ebp-8064h]
  ClientClass *v19; // [esp-4h] [ebp-8060h]
  int pChangedProps[4096]; // [esp+Ch] [ebp-8050h] BYREF
  char packedData[16384]; // [esp+400Ch] [ebp-4050h] BYREF
  bf_write pOut; // [esp+800Ch] [ebp-50h] BYREF
  CBitRead v23; // [esp+8024h] [ebp-38h] BYREF
  ServerClass *pServerClass; // [esp+8048h] [ebp-14h]
  void *pData; // [esp+804Ch] [ebp-10h] BYREF
  CBaseClientState *v26; // [esp+8050h] [ebp-Ch]
  ClientClass *pClientClass; // [esp+8054h] [ebp-8h]
  int pDatalen; // [esp+8058h] [ebp-4h] BYREF
  CFrameSnapshot *pSnapshot; // [esp+8064h] [ebp+8h]
  PackedEntity *index; // [esp+8068h] [ebp+Ch]

  v26 = this;
  pServerClass = SV_FindServerClass(index: iClass);
  ClientClass = CBaseClientState::GetClientClass(this, index: iClass);
  m_pHLTVEntityData = (int)u->m_pHLTVEntityData;
  pClientClass = ClientClass;
  v8 = *(CFrameSnapshot **)(u->m_nNumEntities + 280);
  v9 = m_pHLTVEntityData;
  v8->m_pEntities[v9].m_nSerialNumber = iSerialNum;
  v10 = pServerClass;
  pSnapshot = v8;
  v8->m_pEntities[v9].m_pClass = pServerClass;
  pData = nullptr;
  pDatalen = 0;
  if ( LOBYTE(u->m_nTickCount) != 0
    && (EntityBaseline = CBaseClientState::GetEntityBaseline(
                           this: v26,
                           iBaseline: u->m_iExplicitDeleteSlots.m_Memory.m_nGrowSize,
                           nEntityIndex: m_pHLTVEntityData)) != nullptr
    && EntityBaseline->m_pClientClass == pClientClass )
  {
    pData = EntityBaseline->m_pData;
    v12 = EntityBaseline->m_nBits & 0x7FFFFFFF;
  }
  else
  {
    if ( !CBaseClientState::GetClassBaseline(this: v26, iClass, (const void **)&pData, &pDatalen) )
      _Error(a1: "HLTV_CopyNewEntity: GetDynamicBaseline(%d) failed.", iClass);
    v12 = 8 * pDatalen;
  }
  pDatalen = v12;
  NumFlatProps = SendTable_GetNumFlatProps(pSendTable: v10->m_pTable);
  v14 = nullptr;
  if ( LOBYTE(v26[1].IServerMessageHandler::INetMessageHandler::__vftable) == 0 )
    v14 = AllocChangeFrameList(nProperties: NumFlatProps, iCurTick: 0);
  PackedEntity = CFrameSnapshotManager::CreatePackedEntity(
                   this: framesnapshotmanager,
                   pSnapshot,
                   entity: m_pHLTVEntityData);
  v19 = pClientClass;
  v18 = pServerClass;
  index = PackedEntity;
  PackedEntity->m_pChangeFrameList = v14;
  PackedEntity::SetServerAndClientClass(this: PackedEntity, pServerClass: v18, pClientClass: v19);
  v23.m_bOverflow = false;
  v23.m_nDataBits = -1;
  v23.m_nDataBytes = 0;
  v23.m_pDebugName = "HLTV_ReadEnterPVS1";
  CBitRead::StartReading(
    this: &v23,
    (const unsigned int *)pData,
    nBytes: (pDatalen + 7) >> 3,
    iStartBit: 0,
    nBits: pDatalen);
  bf_write::bf_write(this: &pOut, pDebugName: "HLTV_ReadEnterPVS2", pData: packedData, nBytes: 0x4000, nBits: -1);
  v16 = RecvTable_MergeDeltas(
          pTable: pClientClass->m_pRecvTable,
          pOldState: (bf_read *)&v23,
          pNewState: (bf_read *)u->m_nTempEntities,
          &pOut,
          objectID: -1,
          bDebugWatchInfo: false,
          pChangedProps);
  if ( v14 != nullptr )
    v14->SetChangeTick(this: v14, a2: pChangedProps, a3: v16, a4: pSnapshot->m_nTickCount);
  if ( LOBYTE(u->m_iExplicitDeleteSlots.m_Size) != 0 )
    CBaseClientState::SetEntityBaseline(
      this: v26,
      iBaseline: u->m_iExplicitDeleteSlots.m_Memory.m_nGrowSize == 0,
      pClientClass,
      index: (int)u->m_pHLTVEntityData,
      packedData,
      length: (pOut.m_iCurBit + 7) >> 3);
  PackedEntity::AllocAndCopyPadded(this: index, pData: packedData, size: (pOut.m_iCurBit + 7) >> 3);
  *(_DWORD *)(u->m_nNumEntities + 4) = m_pHLTVEntityData;
  v17 = (_DWORD *)(u->m_nNumEntities + 4 * (m_pHLTVEntityData >> 5) + 16);
  *v17 |= 1 << (m_pHLTVEntityData & 0x1F);
}

//------------------------------------------------------------------------------
// Address: 0x1017EB30
// Name: HLTV_CopyExitingEnt
// Source: json
//------------------------------------------------------------------------------
void __usercall HLTV_CopyExitingEnt(CEntityReadInfo *u@<edi>)
{
  CFrameSnapshot *m_pSnapshot; // ebx
  int m_nOldEntity; // esi
  CFrameSnapshotEntry *v3; // ecx
  CFrameSnapshotEntry *v4; // eax
  unsigned int *v5; // eax

  if ( u->m_bAsDelta )
  {
    m_pSnapshot = u->m_pTo->m_pSnapshot;
    m_nOldEntity = u->m_nOldEntity;
    v3 = &m_pSnapshot->m_pEntities[m_nOldEntity];
    v4 = &u->m_pFrom->m_pSnapshot->m_pEntities[m_nOldEntity];
    v3->m_pClass = v4->m_pClass;
    v3->m_nSerialNumber = v4->m_nSerialNumber;
    v3->m_pPackedData = v4->m_pPackedData;
    _InterlockedExchangeAdd(
      &CFrameSnapshotManager::GetPackedEntity(this: framesnapshotmanager, pSnapshot: m_pSnapshot, entity: m_nOldEntity)->m_ReferenceCount.m_value,
      1u);
    u->m_pTo->last_entity = m_nOldEntity;
    v5 = &u->m_pTo->transmit_entity.m_Ints[m_nOldEntity >> 5];
    *v5 |= 1 << (m_nOldEntity & 0x1F);
  }
  else
  {
    ConMsg(a1: "WARNING: CopyExitingEnt on full update.\n");
    u->m_UpdateType = Failed;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1017EBC0
// Name: public: void CHLTVClientState::SendClientInfo(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHLTVClientState::SendClientInfo(CHLTVClientState *this)
{
  unsigned int CRC; // eax
  INetChannel *m_NetChannel; // ecx
  CLC_ClientInfo info; // [esp+8h] [ebp-50h] BYREF

  info.m_bReliable = true;
  info.m_NetChannel = nullptr;
  info.__vftable = (CLC_ClientInfo_vtbl *)&CLC_ClientInfo::`vftable';
  CRC = SendTable_GetCRC();
  m_NetChannel = this->m_NetChannel;
  info.m_nSendTableCRC = CRC;
  info.m_nServerCount = this->m_nServerCount;
  info.m_bIsHLTV = true;
  info.m_nFriendsID = 0;
  info.m_FriendsName[0] = 0;
  memset(info.m_nCustomFiles, 0, sizeof(info.m_nCustomFiles));
  m_NetChannel->SendNetMsg(this: m_NetChannel, a2: &info, a3: false, a4: false);
}

//------------------------------------------------------------------------------
// Address: 0x1017EC20
// Name: public: void CHLTVClientState::ReadEnterPVS(class CEntityReadInfo __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHLTVClientState::ReadEnterPVS(CHLTVClientState *this, CFrameSnapshot *u)
{
  int m_nServerClassBits; // edx
  bf_read *m_nTempEntities; // eax
  int m_nBitsAvail; // ecx
  unsigned int v5; // esi
  unsigned int v6; // edi
  int v7; // ecx
  const unsigned int *v8; // ecx
  const unsigned int *v9; // edx
  const unsigned int *m_pBufferEnd; // esi
  unsigned int m_nInBufWord; // edi
  const unsigned int *m_pDataIn; // ecx
  CFrameSnapshot *v13; // edi
  bf_read *v14; // eax
  int v15; // ecx
  unsigned int v16; // edx
  int v17; // esi
  int v18; // eax
  const unsigned int *v19; // ecx
  const unsigned int *v20; // edx
  unsigned int v21; // edx
  const unsigned int *v22; // esi
  unsigned int v23; // edi
  int v24; // edx
  const unsigned int *v25; // ecx
  unsigned int v26; // esi
  unsigned int v27; // ebx
  CHLTVEntityData *m_nValidEntities; // eax
  CFrameSnapshotEntry *m_pEntities; // ecx
  int NextSetBit; // eax
  int iClass; // [esp+10h] [ebp-4h]

  m_nServerClassBits = this->m_nServerClassBits;
  m_nTempEntities = (bf_read *)u->m_nTempEntities;
  m_nBitsAvail = m_nTempEntities->m_nBitsAvail;
  if ( m_nBitsAvail < m_nServerClassBits )
  {
    m_pBufferEnd = m_nTempEntities->m_pBufferEnd;
    m_nInBufWord = m_nTempEntities->m_nInBufWord;
    m_nServerClassBits -= m_nBitsAvail;
    m_pDataIn = m_nTempEntities->m_pDataIn;
    if ( m_pDataIn == m_pBufferEnd )
    {
      m_nTempEntities->m_nBitsAvail = 1;
      m_nTempEntities->m_nInBufWord = 0;
      m_nTempEntities->m_bOverflow = true;
    }
    else
    {
      if ( m_pDataIn > m_pBufferEnd )
      {
        m_nTempEntities->m_bOverflow = true;
        m_nTempEntities->m_nInBufWord = 0;
LABEL_14:
        if ( m_nTempEntities->m_bOverflow )
        {
          iClass = 0;
          goto LABEL_19;
        }
        v5 = m_nTempEntities->m_nInBufWord;
        v6 = ((v5 & CBitBuffer::s_nMaskTable[m_nServerClassBits]) << m_nTempEntities->m_nBitsAvail) | m_nInBufWord;
        m_nTempEntities->m_nBitsAvail = 32 - m_nServerClassBits;
        goto LABEL_17;
      }
      m_nTempEntities->m_nInBufWord = *m_pDataIn;
    }
    m_nTempEntities->m_pDataIn = m_pDataIn + 1;
    goto LABEL_14;
  }
  v5 = m_nTempEntities->m_nInBufWord;
  v6 = v5 & CBitBuffer::s_nMaskTable[m_nServerClassBits];
  v7 = m_nBitsAvail - m_nServerClassBits;
  m_nTempEntities->m_nBitsAvail = v7;
  if ( v7 == 0 )
  {
    v8 = m_nTempEntities->m_pDataIn;
    v9 = m_nTempEntities->m_pBufferEnd;
    m_nTempEntities->m_nBitsAvail = 32;
    if ( v8 == v9 )
    {
      m_nTempEntities->m_nBitsAvail = 1;
      m_nTempEntities->m_nInBufWord = 0;
      m_nTempEntities->m_pDataIn = v8 + 1;
    }
    else if ( v8 <= v9 )
    {
      m_nTempEntities->m_nInBufWord = *v8;
      m_nTempEntities->m_pDataIn = v8 + 1;
    }
    else
    {
      m_nTempEntities->m_bOverflow = true;
      m_nTempEntities->m_nInBufWord = 0;
    }
    goto LABEL_18;
  }
LABEL_17:
  m_nTempEntities->m_nInBufWord = v5 >> m_nServerClassBits;
LABEL_18:
  iClass = v6;
LABEL_19:
  v13 = u;
  v14 = (bf_read *)u->m_nTempEntities;
  v15 = v14->m_nBitsAvail;
  if ( v15 < 10 )
  {
    v22 = v14->m_pBufferEnd;
    v23 = v14->m_nInBufWord;
    v24 = 10 - v15;
    v25 = v14->m_pDataIn;
    if ( v25 == v22 )
    {
      v14->m_nBitsAvail = 1;
      v14->m_nInBufWord = 0;
      v14->m_bOverflow = true;
    }
    else
    {
      if ( v25 > v22 )
      {
        v14->m_bOverflow = true;
        v14->m_nInBufWord = 0;
LABEL_34:
        if ( v14->m_bOverflow )
        {
          v18 = 0;
        }
        else
        {
          v26 = v14->m_nInBufWord;
          v27 = (v26 & CBitBuffer::s_nMaskTable[v24]) << v14->m_nBitsAvail;
          v14->m_nBitsAvail = 32 - v24;
          v14->m_nInBufWord = v26 >> v24;
          v18 = v27 | v23;
        }
        v13 = u;
        goto LABEL_38;
      }
      v14->m_nInBufWord = *v25;
    }
    v14->m_pDataIn = v25 + 1;
    goto LABEL_34;
  }
  v16 = v14->m_nInBufWord;
  v17 = v16 & 0x3FF;
  v14->m_nBitsAvail = v15 - 10;
  if ( v15 == 10 )
  {
    v19 = v14->m_pDataIn;
    v20 = v14->m_pBufferEnd;
    v14->m_nBitsAvail = 32;
    if ( v19 == v20 )
    {
      v14->m_nBitsAvail = 1;
      v14->m_nInBufWord = 0;
      v14->m_pDataIn = v19 + 1;
      v18 = v17;
    }
    else
    {
      if ( v19 <= v20 )
      {
        v21 = *v19;
        v14->m_pDataIn = v19 + 1;
        v14->m_nInBufWord = v21;
      }
      else
      {
        v14->m_bOverflow = true;
        v14->m_nInBufWord = 0;
      }
      v18 = v17;
    }
  }
  else
  {
    v14->m_nInBufWord = v16 >> 10;
    v18 = v16 & 0x3FF;
  }
LABEL_38:
  CHLTVClientState::CopyNewEntity(this, u: v13, iClass, iSerialNum: v18);
  m_nValidEntities = (CHLTVEntityData *)v13->m_nValidEntities;
  if ( v13->m_pHLTVEntityData == m_nValidEntities )
  {
    m_pEntities = v13->m_pEntities;
    if ( m_pEntities == nullptr
      || (NextSetBit = CFixedBitVecBase<2048>::FindNextSetBit(
                         this: (CFixedBitVecBase<2048> *)&m_pEntities[1].m_nSerialNumber,
                         startBit: (int)m_nValidEntities->origin + 1),
          v13->m_nValidEntities = NextSetBit,
          NextSetBit < 0) )
    {
      v13->m_nValidEntities = 9999;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1017EE30
// Name: public: void CHLTVClientState::ReadDeltaEnt(class CEntityReadInfo __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHLTVClientState::ReadDeltaEnt(CHLTVClientState *this, CEntityReadInfo *u)
{
  CEntityReadInfo *v2; // esi
  CFrameSnapshot *m_pSnapshot; // eax
  int m_nNewEntity; // edi
  CFrameSnapshot *v5; // ebx
  CFrameSnapshotEntry *m_pEntities; // ecx
  CFrameSnapshotEntry *v7; // ecx
  CFrameSnapshotEntry *v8; // eax
  PackedEntity *PackedEntity; // ebx
  PackedEntity *v10; // edi
  bool v11; // zf
  int m_nBits; // ecx
  char *m_pData; // eax
  CEntityReadInfo *v14; // ecx
  int v15; // eax
  char *v16; // eax
  unsigned int *v17; // eax
  CClientFrame *m_pFrom; // eax
  int NextSetBit; // eax
  _BYTE pData[16384]; // [esp+Ch] [ebp-8048h] BYREF
  int pChangedProps[4096]; // [esp+400Ch] [ebp-4048h] BYREF
  CBitRead v22; // [esp+800Ch] [ebp-48h] BYREF
  bf_write pOut; // [esp+8030h] [ebp-24h] BYREF
  CFrameSnapshot *v24; // [esp+8048h] [ebp-Ch]
  CHLTVClientState *v25; // [esp+804Ch] [ebp-8h]
  CFrameSnapshot *pSnapshot; // [esp+8050h] [ebp-4h] BYREF

  v2 = u;
  m_pSnapshot = u->m_pFrom->m_pSnapshot;
  m_nNewEntity = u->m_nNewEntity;
  v25 = this;
  v5 = u->m_pTo->m_pSnapshot;
  m_pEntities = v5->m_pEntities;
  pSnapshot = m_pSnapshot;
  v7 = &m_pEntities[m_nNewEntity];
  v8 = &m_pSnapshot->m_pEntities[m_nNewEntity];
  v7->m_pClass = v8->m_pClass;
  v7->m_nSerialNumber = v8->m_nSerialNumber;
  v7->m_pPackedData = v8->m_pPackedData;
  v24 = v5;
  PackedEntity = CFrameSnapshotManager::CreatePackedEntity(
                   this: framesnapshotmanager,
                   pSnapshot: v5,
                   entity: m_nNewEntity);
  v10 = CFrameSnapshotManager::GetPackedEntity(this: framesnapshotmanager, pSnapshot, entity: m_nNewEntity);
  PackedEntity::SetServerAndClientClass(
    this: PackedEntity,
    pServerClass: v10->m_pServerClass,
    pClientClass: v10->m_pClientClass);
  v11 = !v25->m_bSaveMemory;
  pSnapshot = nullptr;
  if ( v11 )
  {
    pSnapshot = (CFrameSnapshot *)v10->m_pChangeFrameList->Copy(this: v10->m_pChangeFrameList);
    PackedEntity->m_pChangeFrameList = (IChangeFrameList *)pSnapshot;
  }
  m_nBits = v10->m_nBits;
  if ( m_nBits >= 0 )
  {
    m_pData = (char *)v10->m_pData;
    v14 = (CEntityReadInfo *)(m_nBits & 0x7FFFFFFF);
    u = v14;
  }
  else
  {
    m_pData = CBaseServer::UncompressPackedEntity(this: &v25->m_pHLTV->CBaseServer, pPackedEntity: v10, bits: (int *)&u);
    v14 = u;
  }
  v22.m_bOverflow = false;
  v22.m_nDataBits = -1;
  v22.m_nDataBytes = 0;
  v22.m_pDebugName = "HLTV_ReadEnterPVS1";
  CBitRead::StartReading(
    this: &v22,
    pData: (const unsigned int *)m_pData,
    nBytes: (int)(&v14->m_bAsDelta + 3) >> 3,
    iStartBit: 0,
    nBits: (int)v14);
  bf_write::bf_write(this: &pOut, pDebugName: "HLTV_ReadEnterPVS2", pData, nBytes: 0x4000, nBits: -1);
  v15 = RecvTable_MergeDeltas(
          pTable: PackedEntity->m_pClientClass->m_pRecvTable,
          pOldState: (bf_read *)&v22,
          pNewState: v2->m_pBuf,
          &pOut,
          objectID: -1,
          bDebugWatchInfo: false,
          pChangedProps);
  if ( pSnapshot != nullptr )
    (*(void (__thiscall **)(CFrameSnapshot *, int *, int, int))(pSnapshot->m_ListIndex.m_value + 8))(
      a1: pSnapshot,
      a2: pChangedProps,
      a3: v15,
      a4: v24->m_nTickCount);
  if ( v25->m_bSaveMemory )
  {
    pSnapshot = (CFrameSnapshot *)pOut.m_iCurBit;
    v16 = CBaseServer::CompressPackedEntity(
            this: &v25->m_pHLTV->CBaseServer,
            pServerClass: PackedEntity->m_pServerClass,
            data: (const char *)pOut.m_pData,
            bits: (int *)&pSnapshot);
    PackedEntity::AllocAndCopyPadded(this: PackedEntity, pData: v16, size: ((int)&pSnapshot->m_nTickCount + 3) >> 3);
    PackedEntity->m_nBits |= 0x80000000;
  }
  else
  {
    PackedEntity::AllocAndCopyPadded(this: PackedEntity, pData, size: (pOut.m_iCurBit + 7) >> 3);
  }
  v2->m_pTo->last_entity = v2->m_nNewEntity;
  v17 = &v2->m_pTo->transmit_entity.m_Ints[v2->m_nNewEntity >> 5];
  *v17 |= 1 << (v2->m_nNewEntity & 0x1F);
  m_pFrom = v2->m_pFrom;
  if ( m_pFrom == nullptr
    || (NextSetBit = CFixedBitVecBase<2048>::FindNextSetBit(
                       this: &m_pFrom->transmit_entity,
                       startBit: v2->m_nOldEntity + 1),
        v2->m_nOldEntity = NextSetBit,
        NextSetBit < 0) )
  {
    v2->m_nOldEntity = 9999;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1017F040
// Name: public: virtual void CHLTVClientState::ReadPacketEntities(class CEntityReadInfo __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHLTVClientState::ReadPacketEntities(CHLTVClientState *this, CEntityReadInfo *u)
{
  CClientFrame *m_pFrom; // eax
  int NextSetBit; // eax
  bool v4; // sf
  int m_nOldEntity; // ecx
  int m_UpdateFlags; // eax
  UpdateType m_UpdateType; // eax
  CClientFrame *v8; // eax
  CFrameSnapshotEntry *v9; // eax
  CClientFrame *v10; // edx
  int v11; // ecx
  int v12; // eax
  unsigned int v13; // ecx
  int v14; // edx
  int v15; // eax
  CClientFrame *v16; // edx
  int v17; // ecx
  int v18; // eax
  unsigned int v19; // ecx
  int v20; // edx
  unsigned int v21; // edx

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
  while ( u->m_UpdateType < Finished )
  {
    v4 = --u->m_nHeaderCount < 0;
    u->m_bIsEntity = !v4;
    if ( !v4 )
      CL_ParseDeltaHeader(u);
    u->m_UpdateType = PreserveEnt;
    do
    {
      if ( u->m_bIsEntity && (m_nOldEntity = u->m_nOldEntity, u->m_nNewEntity <= m_nOldEntity) )
      {
        m_UpdateFlags = u->m_UpdateFlags;
        if ( (m_UpdateFlags & 4) != 0 )
        {
          u->m_UpdateType = EnterPVS;
          m_UpdateType = EnterPVS;
        }
        else if ( (m_UpdateFlags & 1) != 0 )
        {
          u->m_UpdateType = LeavePVS;
          m_UpdateType = LeavePVS;
        }
        else
        {
          u->m_UpdateType = DeltaEnt;
          m_UpdateType = u->m_UpdateType;
        }
      }
      else
      {
        v8 = u->m_pFrom;
        if ( v8 == nullptr || (m_nOldEntity = u->m_nOldEntity) > v8->last_entity )
        {
          u->m_UpdateType = Finished;
          continue;
        }
        u->m_UpdateType = PreserveEnt;
        m_UpdateType = PreserveEnt;
      }
      switch ( m_UpdateType )
      {
        case EnterPVS:
          CHLTVClientState::ReadEnterPVS(this, u);
          continue;
        case LeavePVS:
          if ( (u->m_UpdateFlags & 2) != 0 )
          {
            v9 = &u->m_pTo->m_pSnapshot->m_pEntities[m_nOldEntity];
            v9->m_nSerialNumber = -1;
            v9->m_pClass = nullptr;
          }
          v10 = u->m_pFrom;
          if ( v10 == nullptr )
            goto LABEL_30;
          v11 = u->m_nOldEntity + 1;
          if ( v11 >= 2048 )
            goto LABEL_28;
          v12 = v11 >> 5;
          v13 = v10->transmit_entity.m_Ints[v11 >> 5] & `GetStartBitMask'::`2'::g_StartMask[v11 & 0x1F];
          v14 = (int)&v10->transmit_entity + 4 * v12;
          while ( v13 == 0 )
          {
            v13 = *(_DWORD *)(v14 + 4);
            v14 += 4;
            if ( ++v12 > 63 )
              goto LABEL_28;
          }
          _BitScanForward(&v13, v13);
          v15 = v13 + 32 * v12;
          goto LABEL_29;
        case DeltaEnt:
          CHLTVClientState::ReadDeltaEnt(this, u);
          continue;
        case PreserveEnt:
          if ( u->m_nNewEntity >= 2048 )
            Host_Error(error: "CL_ReadPreserveEnt: u.m_nNewEntity == MAX_EDICTS");
          HLTV_CopyExitingEnt(u);
          v16 = u->m_pFrom;
          if ( v16 == nullptr )
            goto LABEL_30;
          v17 = u->m_nOldEntity + 1;
          if ( v17 >= 2048 )
            goto LABEL_28;
          v18 = v17 >> 5;
          v19 = v16->transmit_entity.m_Ints[v17 >> 5] & `GetStartBitMask'::`2'::g_StartMask[v17 & 0x1F];
          v20 = (int)&v16->transmit_entity + 4 * v18;
          break;
      }
      while ( v19 == 0 )
      {
        v19 = *(_DWORD *)(v20 + 4);
        v20 += 4;
        if ( ++v18 > 63 )
        {
LABEL_28:
          v15 = -1;
          goto LABEL_29;
        }
      }
      _BitScanForward(&v21, v19);
      v15 = v21 + 32 * v18;
LABEL_29:
      u->m_nOldEntity = v15;
      if ( v15 < 0 )
LABEL_30:
        u->m_nOldEntity = 9999;
    }
    while ( u->m_UpdateType == PreserveEnt );
  }
  if ( u->m_bAsDelta && u->m_UpdateType == Finished )
    CHLTVClientState::ReadDeletions(this, u);
  if ( u->m_pBuf->m_bOverflow )
    Host_Error(error: "CL_ParsePacketEntities:  buffer read overflow\n");
  if ( !u->m_bAsDelta )
    this->m_flNextCmdTime = 0.0;
}

//------------------------------------------------------------------------------
// Address: 0x1017F280
// Name: public: virtual bool CHLTVClientState::ProcessGameEventList(class SVC_GameEventList __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CHLTVClientState::ProcessGameEventList(CHLTVClientState *this, SVC_GameEventList *msg)
{
  INetChannel *m_NetChannel; // edx
  int m_nLength; // ecx
  int m_nNumEvents; // edx
  unsigned __int8 *m_pData; // edx
  int m_nDataBytes; // ecx
  int m_nDataBits; // edx
  int m_iCurBit; // ecx
  int v11; // edx
  const char *m_pDebugName; // ecx
  int v13; // edi
  void *v14; // esp
  char v16[12]; // [esp+0h] [ebp-64h] BYREF
  SVC_GameEventList tmpMsg; // [esp+Ch] [ebp-58h] BYREF
  CHLTVClientState *v18; // [esp+60h] [ebp-4h]

  v18 = this;
  m_NetChannel = msg->m_NetChannel;
  tmpMsg.m_bReliable = msg->m_bReliable;
  tmpMsg.m_pMessageHandler = msg->m_pMessageHandler;
  m_nLength = msg->m_nLength;
  tmpMsg.m_NetChannel = m_NetChannel;
  m_nNumEvents = msg->m_nNumEvents;
  tmpMsg.m_nLength = m_nLength;
  tmpMsg.m_nNumEvents = m_nNumEvents;
  m_pData = msg->m_DataOut.m_pData;
  tmpMsg.__vftable = (SVC_GameEventList_vtbl *)&SVC_GameEventList::`vftable';
  tmpMsg.m_DataIn = msg->m_DataIn;
  m_nDataBytes = msg->m_DataOut.m_nDataBytes;
  tmpMsg.m_DataOut.m_pData = m_pData;
  m_nDataBits = msg->m_DataOut.m_nDataBits;
  tmpMsg.m_DataOut.m_nDataBytes = m_nDataBytes;
  m_iCurBit = msg->m_DataOut.m_iCurBit;
  tmpMsg.m_DataOut.m_nDataBits = m_nDataBits;
  v11 = *(_DWORD *)&msg->m_DataOut.m_bOverflow;
  tmpMsg.m_DataOut.m_iCurBit = m_iCurBit;
  m_pDebugName = msg->m_DataOut.m_pDebugName;
  *(_DWORD *)&tmpMsg.m_DataOut.m_bOverflow = v11;
  tmpMsg.m_DataOut.m_pDebugName = m_pDebugName;
  CBaseClientState::ProcessGameEventList(this, msg: &tmpMsg);
  v13 = 4 * ((((msg->m_nLength + 7) >> 3) + 3) / 4);
  v14 = alloca(v13);
  CBitRead::ReadBits(this: &msg->m_DataIn, pOutData: v16, nBits: msg->m_nLength);
  bf_write::StartWriting(this: &msg->m_DataOut, pData: v16, nBytes: v13, iStartBit: msg->m_nLength, nBits: -1);
  return CHLTVServer::SendNetMsg(this: *(CHLTVServer **)&v18->m_bSaveMemory, msg, bForceReliable: false, bVoice: false);
}

//------------------------------------------------------------------------------
// Address: 0x1017F360
// Name: public: virtual bool CHLTVClientState::SetSignonState(int,int,class NET_SignonState __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CHLTVClientState::SetSignonState(CHLTVClientState *this, int state, int count, NET_SignonState *msg)
{
  char result; // al
  INetChannel *m_NetChannel; // ecx
  char dest[12]; // [esp+10h] [ebp-24Ch] BYREF
  NetMessageCvar_t acvar; // [esp+1Ch] [ebp-240h] BYREF
  int m_nSignonState; // [esp+228h] [ebp-34h]
  int v10; // [esp+22Ch] [ebp-30h]
  int v11; // [esp+230h] [ebp-2Ch]
  CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > v12; // [esp+234h] [ebp-28h] BYREF
  CUtlVector<NetMessageCvar_t,CUtlMemory<NetMessageCvar_t,int> > v13; // [esp+248h] [ebp-14h] BYREF

  result = CBaseClientState::SetSignonState(this, state, count, msg);
  if ( result != 0 )
  {
    switch ( this->m_nSignonState )
    {
      case 2:
        ((void (__stdcall *)(_DWORD, _DWORD))this->m_NetChannel->SetTimeout)(a1: 300.0, a2: 0);
        this->m_NetChannel->Clear(this: this->m_NetChannel);
        LOBYTE(v12.m_Memory.m_nGrowSize) = 1;
        v12.m_Size = 0;
        v12.m_Memory.m_nAllocationCount = (int)&NET_SetConVar::`vftable';
        memset(&v13, 0, sizeof(v13));
        Host_BuildUserInfoUpdateMessage(nSplitScreenSlot: 0, rCvarList: &v13, nonDefault: false);
        _V_strcpy(dest, src: "tv_relay");
        _V_strcpy(dest: &acvar.name[248], src: "1");
        CUtlVector<NetMessageCvar_t,CUtlMemory<NetMessageCvar_t,int>>::InsertBefore(
          this: &v13,
          elem: v13.m_Size,
          src: (const NetMessageCvar_t *)dest);
        this->m_NetChannel->SendNetMsg(
          this: this->m_NetChannel,
          a2: (INetMessage *)&v12.m_Memory.m_nAllocationCount,
          a3: false,
          a4: false);
        CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&v13);
        break;
      case 3:
        CHLTVClientState::SendClientInfo(this);
        break;
      case 5:
        CHLTVServer::SignonComplete(this: this->m_pHLTV);
        break;
      case 6:
        ((void (__stdcall *)(_DWORD, _DWORD))this->m_NetChannel->SetTimeout)(
          a1: tv_timeout.m_pParent->m_Value.m_fValue,
          a2: 0);
        if ( tv_autorecord.m_pParent != nullptr && tv_autorecord.m_pParent->m_Value.m_nValue != 0 )
        {
          CHLTVDemoRecorder::StartAutoRecording(this: &hltv->m_DemoRecorder);
          this->m_NetChannel->SetDemoRecorder(this: this->m_NetChannel, a2: &hltv->m_DemoRecorder);
        }
        break;
      case 7:
        CHLTVServer::Changelevel(this: this->m_pHLTV);
        ((void (__stdcall *)(_DWORD, _DWORD))this->m_NetChannel->SetTimeout)(a1: 300.0, a2: 0);
        break;
      default:
        break;
    }
    if ( this->m_nSignonState >= 2 )
    {
      m_NetChannel = this->m_NetChannel;
      m_nSignonState = this->m_nSignonState;
      v10 = count;
      acvar.value[252] = 1;
      *(_DWORD *)&acvar.value[256] = 0;
      *(_DWORD *)&acvar.value[248] = &NET_SignonState::`vftable';
      memset(&v12, 0, sizeof(v12));
      memset(&v13, 0, sizeof(v13));
      v11 = 0;
      m_NetChannel->SendNetMsg(this: m_NetChannel, a2: (INetMessage *)&acvar.value[248], a3: false, a4: false);
      CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&v13);
      CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: &v12);
    }
    return 1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1017F560
// Name: public: void CHLTVClientState::UpdateStats(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHLTVClientState::UpdateStats(CHLTVClientState *this)
{
  CHLTVServer *m_pHLTV; // ecx
  int v3; // eax
  CHLTVServer *v4; // ecx
  int v5; // eax
  const char *v6; // eax
  int v7; // [esp-8h] [ebp-244h]
  NetMessageCvar_t acvar; // [esp+4h] [ebp-238h] BYREF
  NET_SetConVar conVars; // [esp+20Ch] [ebp-30h] BYREF
  int clients; // [esp+230h] [ebp-Ch] BYREF
  int proxies; // [esp+234h] [ebp-8h] BYREF
  int slots; // [esp+238h] [ebp-4h] BYREF

  if ( this->m_nSignonState >= 6 )
  {
    if ( this->m_fNextSendUpdateTime <= net_time )
    {
      this->m_fNextSendUpdateTime = net_time + 8.0;
      CHLTVServer::GetRelayStats(this: this->m_pHLTV, &proxies, &slots, &clients);
      m_pHLTV = this->m_pHLTV;
      ++proxies;
      v3 = m_pHLTV->GetMaxClients(this: &m_pHLTV->CBaseServer);
      v4 = this->m_pHLTV;
      slots += v3;
      v5 = v4->GetNumClients(this: &v4->CBaseServer);
      clients += v5;
      conVars.m_bReliable = true;
      conVars.m_NetChannel = nullptr;
      conVars.__vftable = (NET_SetConVar_vtbl *)&NET_SetConVar::`vftable';
      memset(&conVars.m_ConVars, 0, sizeof(conVars.m_ConVars));
      V_strncpy(pDest: acvar.name, pSrc: "hltv_proxies", maxLen: 260);
      V_snprintf(pDest: acvar.value, maxLen: 260, pFormat: "%d", proxies);
      CUtlVector<NetMessageCvar_t,CUtlMemory<NetMessageCvar_t,int>>::InsertBefore(
        this: &conVars.m_ConVars,
        elem: conVars.m_ConVars.m_Size,
        src: &acvar);
      V_strncpy(pDest: acvar.name, pSrc: "hltv_clients", maxLen: 260);
      V_snprintf(pDest: acvar.value, maxLen: 260, pFormat: "%d", clients);
      CUtlVector<NetMessageCvar_t,CUtlMemory<NetMessageCvar_t,int>>::InsertBefore(
        this: &conVars.m_ConVars,
        elem: conVars.m_ConVars.m_Size,
        src: &acvar);
      V_strncpy(pDest: acvar.name, pSrc: "hltv_slots", maxLen: 260);
      V_snprintf(pDest: acvar.value, maxLen: 260, pFormat: "%d", slots);
      CUtlVector<NetMessageCvar_t,CUtlMemory<NetMessageCvar_t,int>>::InsertBefore(
        this: &conVars.m_ConVars,
        elem: conVars.m_ConVars.m_Size,
        src: &acvar);
      V_strncpy(pDest: acvar.name, pSrc: "hltv_addr", maxLen: 260);
      v7 = this->m_pHLTV->GetUDPPort(this: &this->m_pHLTV->CBaseServer);
      v6 = netadr_s::ToString(this: &net_local_adr, baseOnly: true);
      V_snprintf(pDest: acvar.value, maxLen: 260, pFormat: "%s:%u", v6, v7);
      CUtlVector<NetMessageCvar_t,CUtlMemory<NetMessageCvar_t,int>>::InsertBefore(
        this: &conVars.m_ConVars,
        elem: conVars.m_ConVars.m_Size,
        src: &acvar);
      this->m_NetChannel->SendNetMsg(this: this->m_NetChannel, a2: &conVars, a3: false, a4: false);
      CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&conVars.m_ConVars);
    }
  }
  else
  {
    this->m_fNextSendUpdateTime = 0.0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1017F770
// Name: public: virtual void CHLTVClientState::RunFrame(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHLTVClientState::RunFrame(CHLTVClientState *this)
{
  CBaseClientState::RunFrame(this);
  if ( this->m_NetChannel != nullptr
    && this->m_NetChannel->IsTimedOut(this: this->m_NetChannel)
    && this->m_nSignonState >= 2 )
  {
    ConMsg(a1: "\nSourceTV connection timed out.\n");
    this->Disconnect(this, a2: true);
  }
  else
  {
    CHLTVClientState::UpdateStats(this);
  }
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x1009D170
// Name: CL_ParseDeltaHeader
// Source: json
//------------------------------------------------------------------------------
void __cdecl CL_ParseDeltaHeader(CEntityReadInfo *u)
{
  bf_read *m_pBuf; // eax
  int m_nBitsAvail; // ecx
  unsigned int v3; // edx
  int v4; // esi
  int v5; // ecx
  const unsigned int *v6; // ecx
  const unsigned int *v7; // edx
  unsigned int v8; // edx
  const unsigned int *m_pBufferEnd; // esi
  unsigned int m_nInBufWord; // edi
  int v11; // edx
  const unsigned int *m_pDataIn; // ecx
  unsigned int v13; // esi
  unsigned int v14; // ebx
  int v15; // ecx
  int v16; // ecx
  unsigned int v17; // edx
  int v18; // esi
  int v19; // ecx
  int v20; // eax
  int v21; // edx
  unsigned int v22; // edx
  int v23; // ecx
  unsigned int v24; // edx
  int v25; // ecx
  const unsigned int *v26; // ecx
  const unsigned int *v27; // edx
  unsigned int v28; // edx
  const unsigned int *v29; // esi
  unsigned int v30; // edi
  int v31; // edx
  const unsigned int *v32; // ecx
  unsigned int v33; // esi
  unsigned int v34; // ebx
  int v35; // eax
  bf_read *v36; // eax
  unsigned int v37; // ecx
  int v38; // edx
  bool v39; // zf
  const unsigned int *v40; // ecx
  const unsigned int *v41; // esi
  bf_read *v42; // eax
  unsigned int v43; // ecx
  int v44; // edx
  const unsigned int *v45; // ecx
  const unsigned int *v46; // esi
  bf_read *v47; // eax
  unsigned int v48; // ecx
  int v49; // edx
  const unsigned int *v50; // ecx
  const unsigned int *v51; // esi
  int v52; // [esp+Ch] [ebp-4h]

  u->m_UpdateFlags = 0;
  m_pBuf = u->m_pBuf;
  m_nBitsAvail = m_pBuf->m_nBitsAvail;
  if ( m_nBitsAvail < 6 )
  {
    m_pBufferEnd = m_pBuf->m_pBufferEnd;
    m_nInBufWord = m_pBuf->m_nInBufWord;
    v11 = 6 - m_nBitsAvail;
    m_pDataIn = m_pBuf->m_pDataIn;
    if ( m_pDataIn == m_pBufferEnd )
    {
      m_pBuf->m_nBitsAvail = 1;
      m_pBuf->m_nInBufWord = 0;
      m_pBuf->m_bOverflow = true;
    }
    else
    {
      if ( m_pDataIn > m_pBufferEnd )
      {
        m_pBuf->m_bOverflow = true;
        m_pBuf->m_nInBufWord = 0;
        goto LABEL_16;
      }
      m_pBuf->m_nInBufWord = *m_pDataIn;
    }
    m_pBuf->m_pDataIn = m_pDataIn + 1;
LABEL_16:
    if ( m_pBuf->m_bOverflow )
    {
      v52 = 0;
    }
    else
    {
      v13 = m_pBuf->m_nInBufWord;
      v14 = (v13 & CBitBuffer::s_nMaskTable[v11]) << m_pBuf->m_nBitsAvail;
      m_pBuf->m_nBitsAvail = 32 - v11;
      v52 = v14 | m_nInBufWord;
      m_pBuf->m_nInBufWord = v13 >> v11;
    }
    goto LABEL_19;
  }
  v3 = m_pBuf->m_nInBufWord;
  v4 = v3 & 0x3F;
  v5 = m_nBitsAvail - 6;
  m_pBuf->m_nBitsAvail = v5;
  if ( v5 != 0 )
  {
    m_pBuf->m_nInBufWord = v3 >> 6;
    v52 = v3 & 0x3F;
  }
  else
  {
    v6 = m_pBuf->m_pDataIn;
    v7 = m_pBuf->m_pBufferEnd;
    m_pBuf->m_nBitsAvail = 32;
    if ( v6 == v7 )
    {
      m_pBuf->m_nBitsAvail = 1;
      m_pBuf->m_nInBufWord = 0;
      m_pBuf->m_pDataIn = v6 + 1;
      v52 = v4;
    }
    else
    {
      if ( v6 <= v7 )
      {
        v8 = *v6;
        m_pBuf->m_pDataIn = v6 + 1;
        m_pBuf->m_nInBufWord = v8;
      }
      else
      {
        m_pBuf->m_bOverflow = true;
        m_pBuf->m_nInBufWord = 0;
      }
      v52 = v4;
    }
  }
LABEL_19:
  v15 = v52 & 0x30;
  switch ( v15 )
  {
    case 16:
      v16 = m_pBuf->m_nBitsAvail;
      if ( v16 >= 4 )
      {
        v24 = m_pBuf->m_nInBufWord;
        v18 = v24 & 0xF;
        v25 = v16 - 4;
        m_pBuf->m_nBitsAvail = v25;
        if ( v25 != 0 )
        {
          m_pBuf->m_nInBufWord = v24 >> 4;
          v20 = v24 & 0xF;
          goto LABEL_49;
        }
        goto LABEL_33;
      }
      v21 = 4;
LABEL_40:
      v29 = m_pBuf->m_pBufferEnd;
      v30 = m_pBuf->m_nInBufWord;
      v31 = v21 - v16;
      v32 = m_pBuf->m_pDataIn;
      if ( v32 == v29 )
      {
        m_pBuf->m_nBitsAvail = 1;
        m_pBuf->m_nInBufWord = 0;
        m_pBuf->m_bOverflow = true;
      }
      else
      {
        if ( v32 > v29 )
        {
          m_pBuf->m_bOverflow = true;
          m_pBuf->m_nInBufWord = 0;
          goto LABEL_46;
        }
        m_pBuf->m_nInBufWord = *v32;
      }
      m_pBuf->m_pDataIn = v32 + 1;
LABEL_46:
      if ( m_pBuf->m_bOverflow )
      {
        v20 = 0;
      }
      else
      {
        v33 = m_pBuf->m_nInBufWord;
        v34 = (v33 & CBitBuffer::s_nMaskTable[v31]) << m_pBuf->m_nBitsAvail;
        m_pBuf->m_nBitsAvail = 32 - v31;
        m_pBuf->m_nInBufWord = v33 >> v31;
        v20 = v34 | v30;
      }
      goto LABEL_49;
    case 32:
      v16 = m_pBuf->m_nBitsAvail;
      if ( v16 >= 8 )
      {
        v22 = m_pBuf->m_nInBufWord;
        v18 = (unsigned __int8)v22;
        v23 = v16 - 8;
        m_pBuf->m_nBitsAvail = v23;
        if ( v23 != 0 )
        {
          m_pBuf->m_nInBufWord = v22 >> 8;
          v20 = (unsigned __int8)v22;
          goto LABEL_49;
        }
LABEL_33:
        v26 = m_pBuf->m_pDataIn;
        v27 = m_pBuf->m_pBufferEnd;
        m_pBuf->m_nBitsAvail = 32;
        if ( v26 == v27 )
        {
          m_pBuf->m_nBitsAvail = 1;
          m_pBuf->m_nInBufWord = 0;
          m_pBuf->m_pDataIn = v26 + 1;
          v20 = v18;
        }
        else
        {
          if ( v26 <= v27 )
          {
            v28 = *v26;
            m_pBuf->m_pDataIn = v26 + 1;
            m_pBuf->m_nInBufWord = v28;
          }
          else
          {
            m_pBuf->m_bOverflow = true;
            m_pBuf->m_nInBufWord = 0;
          }
          v20 = v18;
        }
        goto LABEL_49;
      }
      v21 = 8;
      goto LABEL_40;
    case 48:
      v16 = m_pBuf->m_nBitsAvail;
      if ( v16 < 28 )
      {
        v21 = 28;
        goto LABEL_40;
      }
      v17 = m_pBuf->m_nInBufWord;
      v18 = v17 & 0xFFFFFFF;
      v19 = v16 - 28;
      m_pBuf->m_nBitsAvail = v19;
      if ( v19 == 0 )
        goto LABEL_33;
      m_pBuf->m_nInBufWord = v17 >> 28;
      v20 = v17 & 0xFFFFFFF;
LABEL_49:
      v52 = v52 & 0xF | (16 * v20);
      break;
    default:
      break;
  }
  v35 = v52 + u->m_nHeaderBase + 1;
  u->m_nNewEntity = v35;
  u->m_nHeaderBase = v35;
  v36 = u->m_pBuf;
  v37 = v36->m_nInBufWord;
  v38 = v37 & 1;
  v39 = v36->m_nBitsAvail-- == 1;
  if ( v39 )
  {
    v40 = v36->m_pDataIn;
    v41 = v36->m_pBufferEnd;
    v36->m_nBitsAvail = 32;
    if ( v40 == v41 )
    {
      v36->m_nBitsAvail = 1;
      v36->m_nInBufWord = 0;
      v36->m_pDataIn = v40 + 1;
    }
    else if ( v40 <= v41 )
    {
      v36->m_nInBufWord = *v40;
      v36->m_pDataIn = v40 + 1;
    }
    else
    {
      v36->m_bOverflow = true;
      v36->m_nInBufWord = 0;
    }
  }
  else
  {
    v36->m_nInBufWord = v37 >> 1;
  }
  if ( v38 != 0 )
  {
    u->m_UpdateFlags |= 1u;
    v47 = u->m_pBuf;
    v48 = v47->m_nInBufWord;
    v49 = v48 & 1;
    v39 = v47->m_nBitsAvail-- == 1;
    if ( v39 )
    {
      v50 = v47->m_pDataIn;
      v51 = v47->m_pBufferEnd;
      v47->m_nBitsAvail = 32;
      if ( v50 == v51 )
      {
        v47->m_nBitsAvail = 1;
        v47->m_nInBufWord = 0;
        v47->m_pDataIn = v50 + 1;
      }
      else if ( v50 <= v51 )
      {
        v47->m_nInBufWord = *v50;
        v47->m_pDataIn = v50 + 1;
      }
      else
      {
        v47->m_bOverflow = true;
        v47->m_nInBufWord = 0;
      }
    }
    else
    {
      v47->m_nInBufWord = v48 >> 1;
    }
    if ( v49 != 0 )
      u->m_UpdateFlags |= 2u;
  }
  else
  {
    v42 = u->m_pBuf;
    v43 = v42->m_nInBufWord;
    v44 = v43 & 1;
    v39 = v42->m_nBitsAvail-- == 1;
    if ( v39 )
    {
      v45 = v42->m_pDataIn;
      v46 = v42->m_pBufferEnd;
      v42->m_nBitsAvail = 32;
      if ( v45 == v46 )
      {
        v42->m_nBitsAvail = 1;
        v42->m_nInBufWord = 0;
        v42->m_pDataIn = v45 + 1;
      }
      else if ( v45 <= v46 )
      {
        v42->m_nInBufWord = *v45;
        v42->m_pDataIn = v45 + 1;
      }
      else
      {
        v42->m_bOverflow = true;
        v42->m_nInBufWord = 0;
      }
    }
    else
    {
      v42->m_nInBufWord = v43 >> 1;
    }
    if ( v44 != 0 )
      u->m_UpdateFlags |= 4u;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1017E000
// Name: HLTV_Callback_InstanceBaseline
// Source: json
//------------------------------------------------------------------------------
void __cdecl HLTV_Callback_InstanceBaseline(CHLTVServer *object)
{
  CHLTVServer::LinkInstanceBaselines(this: object);
}

//------------------------------------------------------------------------------
// Address: 0x1017E050
// Name: public: virtual char const __near * CHLTVClientState::GetCDKeyHash(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CHLTVClientState::GetCDKeyHash(CHLTVClientState *this)
{
  return "HLTVHLTVHLTVHLTVHLTVHLTVHLTVHLTV";
}

//------------------------------------------------------------------------------
// Address: 0x1017E060
// Name: public: virtual CHLTVClientState::~CHLTVClientState(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHLTVClientState::~CHLTVClientState(CHLTVClientState *this)
{
  this->CBaseClientState::INetChannelHandler::__vftable = (CHLTVClientState_vtbl *)&CHLTVClientState::`vftable'{for `INetChannelHandler'};
  this->CBaseClientState::IConnectionlessPacketHandler::__vftable = (IConnectionlessPacketHandler_vtbl *)&CHLTVClientState::`vftable'{for `IConnectionlessPacketHandler'};
  this->CBaseClientState::IServerMessageHandler::INetMessageHandler::__vftable = (IServerMessageHandler_vtbl *)&CHLTVClientState::`vftable'{for `IServerMessageHandler'};
  CBaseClientState::~CBaseClientState(this);
}

//------------------------------------------------------------------------------
// Address: 0x1017E080
// Name: public: virtual bool CHLTVClientState::ProcessSetConVar(class NET_SetConVar __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CHLTVClientState::ProcessSetConVar(CHLTVClientState *this, NET_SetConVar *msg)
{
  char result; // al

  result = CBaseClientState::ProcessSetConVar(this, msg);
  if ( result != 0 )
    return CHLTVServer::SendNetMsg(
             this: *(CHLTVServer **)&this->m_bSaveMemory,
             msg,
             bForceReliable: false,
             bVoice: false);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1017E0B0
// Name: public: virtual void CHLTVClientState::Clear(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHLTVClientState::Clear(CHLTVClientState *this)
{
  CBaseClientState::Clear(this);
  this->m_pNewClientFrame = nullptr;
  this->m_pCurrentClientFrame = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1017E0D0
// Name: public: virtual bool CHLTVClientState::ProcessServerInfo(class SVC_ServerInfo __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CHLTVClientState::ProcessServerInfo(CHLTVClientState *this, SVC_ServerInfo *msg)
{
  const char *v3; // eax
  CNetworkStringTableContainer *v5; // ecx

  (*(void (__thiscall **)(char *))(*((_DWORD *)this - 2) + 44))(a1: (char *)this - 8);
  if ( (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)(*(_DWORD *)&this->m_bSaveMemory + 524) + 24))(a1: *(_DWORD *)&this->m_bSaveMemory + 524) == 0
    && !msg->m_bIsHLTV )
  {
    v3 = (const char *)(*((int (__thiscall **)(IServerMessageHandler_vtbl *))this->dtr_INetMessageHandler + 1))(a1: this->CBaseClientState::IServerMessageHandler::INetMessageHandler::__vftable);
    ConMsg(a1: "Server (%s) is not a SourceTV proxy.\n", v3);
LABEL_4:
    (*(void (__thiscall **)(char *, int))(*((_DWORD *)this - 2) + 64))(a1: (char *)this - 8, a2: 1);
    return 0;
  }
  CHLTVServer::StartRelay(this: *(CHLTVServer **)&this->m_bSaveMemory);
  if ( CBaseClientState::ProcessServerInfo(this, a2: (int)this, msg) == 0 )
    goto LABEL_4;
  v5 = *(CNetworkStringTableContainer **)(*(_DWORD *)&this->m_bSaveMemory + 196);
  *(_DWORD *)&this->m_szEncryptionKey[2044] = v5;
  CNetworkStringTableContainer::EnableRollback(this: v5, bState: false);
  *(_DWORD *)(*(_DWORD *)&this->m_bSaveMemory + 21352) = *(_DWORD *)&this->m_szLastLevelNameShort[32];
  *(_DWORD *)(*(_DWORD *)&this->m_bSaveMemory + 256) = this->m_pEntityBaselines[1][2047];
  *(_DWORD *)(*(_DWORD *)&this->m_bSaveMemory + 260) = this->m_pServerClasses;
  *(_DWORD *)(*(_DWORD *)&this->m_bSaveMemory + 20908) = *(_DWORD *)&this->m_bPaused;
  *(_DWORD *)(*(_DWORD *)&this->m_bSaveMemory + 184) = msg->m_nMapCRC;
  *(_DWORD *)(*(_DWORD *)&this->m_bSaveMemory + 188) = msg->m_nClientCRC;
  *(_DWORD *)(*(_DWORD *)&this->m_bSaveMemory + 192) = msg->m_nStringTableCRC;
  *(float *)(*(_DWORD *)&this->m_bSaveMemory + 276) = msg->m_fTickInterval;
  host_state.interval_per_tick = msg->m_fTickInterval;
  V_strncpy(pDest: (char *)(*(_DWORD *)&this->m_bSaveMemory + 24), pSrc: msg->m_szMapName, maxLen: 64);
  V_strncpy(pDest: (char *)(*(_DWORD *)&this->m_bSaveMemory + 88), pSrc: msg->m_szSkyName, maxLen: 64);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1017E230
// Name: public: virtual bool CHLTVClientState::ProcessClassInfo(class SVC_ClassInfo __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CHLTVClientState::ProcessClassInfo(CHLTVClientState *this, SVC_ClassInfo *msg)
{
  CBaseClientState *v4; // esi
  const CStandardSendProxies *v5; // eax

  if ( msg->m_bCreateOnClient )
  {
    DataTable_CreateClientTablesFromServerTables();
    v4 = (CHLTVClientState *)((char *)this - 8);
    DataTable_CreateClientClassInfosFromServerClasses(pState: v4);
    v4->LinkClasses(this: v4);
    v5 = serverGameDLL->GetStandardSendProxies(this: serverGameDLL);
    if ( RecvTable_CreateDecoders(pSendProxies: v5) )
    {
      return 1;
    }
    else
    {
      Host_EndGame(bShowMainMenu: true, message: "CL_ParseClassInfo_EndClasses: CreateDecoders failed.\n");
      return 0;
    }
  }
  else
  {
    ConMsg(a1: "HLTV SendTable CRC differs from server.\n");
    (*(void (__thiscall **)(char *, int))(*((_DWORD *)this - 2) + 64))(a1: (char *)this - 8, a2: 1);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1017E2C0
// Name: public: virtual void CHLTVClientState::PacketEnd(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHLTVClientState::PacketEnd(CHLTVClientState *this)
{
  CClientFrame *m_pNewClientFrame; // eax
  CClientFrame *v3; // eax
  CClientFrame *v4; // ecx

  m_pNewClientFrame = this->m_pNewClientFrame;
  if ( m_pNewClientFrame != nullptr )
  {
    v3 = CHLTVServer::AddNewFrame(this: this->m_pHLTV, clientFrame: m_pNewClientFrame);
    v4 = this->m_pNewClientFrame;
    this->m_pCurrentClientFrame = v3;
    if ( v4 != nullptr )
      ((void (__thiscall *)(CClientFrame *, int))v4->dtr_CClientFrame)(a1: v4, a2: 1);
    this->m_pNewClientFrame = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1017E300
// Name: public: virtual bool CHLTVClientState::HookClientStringTable(char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CHLTVClientState::HookClientStringTable(CHLTVClientState *this, const char *tableName)
{
  INetworkStringTable *StringTable; // esi

  StringTable = CBaseClientState::GetStringTable(this, name: tableName);
  if ( StringTable == nullptr || V_strcasecmp(s1: tableName, s2: "instancebaseline") != 0 )
    return 0;
  StringTable->SetStringChangedCallback(
    this: StringTable,
    a2: this->m_pHLTV,
    a3: (void (__cdecl *)(void *, INetworkStringTable *, int, const char *, const void *))HLTV_Callback_InstanceBaseline);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1017E350
// Name: public: virtual void CHLTVClientState::InstallStringTableCallback(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHLTVClientState::InstallStringTableCallback(CHLTVClientState *this, const char *tableName)
{
  INetworkStringTable *StringTable; // esi

  StringTable = CBaseClientState::GetStringTable(this, name: tableName);
  if ( StringTable != nullptr && V_strcasecmp(s1: tableName, s2: "instancebaseline") == 0 )
    StringTable->SetStringChangedCallback(
      this: StringTable,
      a2: this->m_pHLTV,
      a3: (void (__cdecl *)(void *, INetworkStringTable *, int, const char *, const void *))HLTV_Callback_InstanceBaseline);
}

//------------------------------------------------------------------------------
// Address: 0x1017E3A0
// Name: public: virtual bool CHLTVClientState::ProcessSetView(class SVC_SetView __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CHLTVClientState::ProcessSetView(CHLTVClientState *this, SVC_SetView *msg)
{
  char result; // al

  result = CBaseClientState::ProcessSetView(this, msg);
  if ( result != 0 )
    return CHLTVServer::SendNetMsg(
             this: *(CHLTVServer **)&this->m_bSaveMemory,
             msg,
             bForceReliable: false,
             bVoice: false);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1017E3D0
// Name: public: virtual bool CHLTVClientState::ProcessVoiceData(class SVC_VoiceData __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CHLTVClientState::ProcessVoiceData(CHLTVClientState *this, SVC_VoiceData *msg)
{
  int m_nLength; // edi
  void *v3; // esp
  CHLTVClientState *v4; // eax
  _BYTE v6[12]; // [esp+0h] [ebp-10h] BYREF
  CHLTVClientState *v7; // [esp+Ch] [ebp-4h]

  m_nLength = msg->m_nLength;
  v7 = this;
  v3 = alloca(4 * ((((m_nLength + 7) >> 3) + 3) / 4));
  CBitRead::ReadBits(this: &msg->m_DataIn, pOutData: v6, nBits: m_nLength);
  v4 = v7;
  msg->m_DataOut = v6;
  return CHLTVServer::SendNetMsg(this: *(CHLTVServer **)&v4->m_bSaveMemory, msg, bForceReliable: false, bVoice: false);
}

//------------------------------------------------------------------------------
// Address: 0x1017E430
// Name: public: virtual bool CHLTVClientState::ProcessGameEvent(class SVC_GameEvent __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CHLTVClientState::ProcessGameEvent(CHLTVClientState *this, SVC_GameEvent *msg)
{
  IGameEvent *v3; // eax
  IGameEvent *v4; // esi
  const char *v5; // edi
  int v6; // eax
  CHLTVClientState *v7; // edi
  const char *v8; // eax
  int m_nLength; // edi
  int v11; // esi
  void *v12; // esp
  _BYTE v13[12]; // [esp+0h] [ebp-34h] BYREF
  bf_read tmpBuf; // [esp+Ch] [ebp-28h] BYREF
  CHLTVClientState *v15; // [esp+30h] [ebp-4h]
  char bDontForward_3; // [esp+3Fh] [ebp+Bh]

  v15 = this;
  tmpBuf = msg->m_DataIn;
  v3 = g_GameEventManager->UnserializeEvent(this: g_GameEventManager, a2: &tmpBuf);
  v4 = v3;
  if ( v3 == nullptr )
    goto LABEL_8;
  v5 = v3->GetName(this: v3);
  bDontForward_3 = 0;
  if ( _V_strcmp(s1: v5, s2: "hltv_status") != 0 )
  {
    if ( _V_strcmp(s1: v5, s2: "hltv_title") != 0 )
      goto LABEL_6;
  }
  else
  {
    v6 = ((int (__thiscall *)(IGameEvent *, const char *))v4->GetInt)(a1: v4, a2: "slots");
    v7 = v15;
    *(_DWORD *)(*(_DWORD *)&v15->m_bSaveMemory + 25488) = v6;
    *(_DWORD *)(*(_DWORD *)&v7->m_bSaveMemory + 25496) = v4->GetInt(this: v4, a2: "proxies", a3: 0);
    *(_DWORD *)(*(_DWORD *)&v7->m_bSaveMemory + 25492) = v4->GetInt(this: v4, a2: "clients", a3: 0);
    v8 = (const char *)((int (__thiscall *)(IGameEvent *, const char *, const char *, _DWORD))v4->GetString)(
                         a1: v4,
                         a2: "master",
                         a3: defaultValue,
                         a4: 0);
    netadr_s::SetFromString(this: (netadr_s *)(*(_DWORD *)&v7->m_bSaveMemory + 25476), pch: v8, bUseDNS: false);
  }
  bDontForward_3 = 1;
LABEL_6:
  g_GameEventManager->FreeEvent(this: g_GameEventManager, a2: v4);
  if ( bDontForward_3 != 0 )
    return true;
LABEL_8:
  m_nLength = msg->m_nLength;
  v11 = 4 * ((((m_nLength + 7) >> 3) + 3) / 4);
  v12 = alloca(v11);
  CBitRead::ReadBits(this: &msg->m_DataIn, pOutData: v13, nBits: m_nLength);
  bf_write::StartWriting(this: &msg->m_DataOut, pData: v13, nBytes: v11, iStartBit: msg->m_nLength, nBits: -1);
  return CHLTVServer::SendNetMsg(this: *(CHLTVServer **)&v15->m_bSaveMemory, msg, bForceReliable: false, bVoice: false);
}

//------------------------------------------------------------------------------
// Address: 0x1017E5B0
// Name: public: virtual bool CHLTVClientState::ProcessTempEntities(class SVC_TempEntities __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CHLTVClientState::ProcessTempEntities(CHLTVClientState *this, SVC_TempEntities *msg)
{
  int m_nLength; // ebx
  int v3; // esi
  void *v4; // esp
  _BYTE v6[12]; // [esp+0h] [ebp-10h] BYREF
  CHLTVClientState *v7; // [esp+Ch] [ebp-4h]

  m_nLength = msg->m_nLength;
  v3 = 4 * ((((m_nLength + 7) >> 3) + 3) / 4);
  v7 = this;
  v4 = alloca(v3);
  CBitRead::ReadBits(this: &msg->m_DataIn, pOutData: v6, nBits: m_nLength);
  bf_write::StartWriting(this: &msg->m_DataOut, pData: v6, nBytes: v3, iStartBit: msg->m_nLength, nBits: -1);
  return CHLTVServer::SendNetMsg(this: *(CHLTVServer **)&v7->m_bSaveMemory, msg, bForceReliable: false, bVoice: false);
}

//------------------------------------------------------------------------------
// Address: 0x1017E630
// Name: public: virtual bool CHLTVClientState::ProcessSounds(class SVC_Sounds __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CHLTVClientState::ProcessSounds(CHLTVClientState *this, SVC_EntityMessage *msg)
{
  int m_nLength; // ebx
  int v3; // esi
  void *v4; // esp
  _BYTE v6[12]; // [esp+0h] [ebp-10h] BYREF
  CHLTVClientState *v7; // [esp+Ch] [ebp-4h]

  m_nLength = msg->m_nLength;
  v3 = 4 * ((((m_nLength + 7) >> 3) + 3) / 4);
  v7 = this;
  v4 = alloca(v3);
  CBitRead::ReadBits(this: &msg->m_DataIn, pOutData: v6, nBits: m_nLength);
  bf_write::StartWriting(this: &msg->m_DataOut, pData: v6, nBytes: v3, iStartBit: msg->m_nLength, nBits: -1);
  return CHLTVServer::SendNetMsg(this: *(CHLTVServer **)&v7->m_bSaveMemory, msg, bForceReliable: false, bVoice: false);
}

//------------------------------------------------------------------------------
// Address: 0x1017E6B0
// Name: public: virtual bool CHLTVClientState::ProcessPrefetch(class SVC_Prefetch __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CHLTVClientState::ProcessPrefetch(CHLTVClientState *this, SVC_PaintmapData *msg)
{
  return CHLTVServer::SendNetMsg(this: *(CHLTVServer **)&this->m_bSaveMemory, msg, bForceReliable: false, bVoice: false);
}

//------------------------------------------------------------------------------
// Address: 0x1017E6D0
// Name: public: void CHLTVClientState::ReadDeletions(class CEntityReadInfo __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHLTVClientState::ReadDeletions(CHLTVClientState *this, CEntityReadInfo *u)
{
  bf_read *m_pBuf; // eax
  unsigned int m_nInBufWord; // ecx
  int v4; // edx
  const unsigned int *m_pDataIn; // ecx
  const unsigned int *m_pBufferEnd; // esi
  bf_read *v8; // eax
  int m_nBitsAvail; // ecx
  unsigned int v10; // edx
  int v11; // esi
  int v12; // ecx
  int v13; // eax
  const unsigned int *v14; // ecx
  const unsigned int *v15; // edx
  unsigned int v16; // edx
  const unsigned int *v17; // esi
  unsigned int v18; // edi
  int v19; // edx
  const unsigned int *v20; // ecx
  unsigned int v21; // esi
  unsigned int v22; // ebx
  CFrameSnapshotEntry *v23; // eax

  while ( 1 )
  {
    m_pBuf = u->m_pBuf;
    m_nInBufWord = m_pBuf->m_nInBufWord;
    v4 = m_nInBufWord & 1;
    if ( m_pBuf->m_nBitsAvail-- == 1 )
    {
      m_pDataIn = m_pBuf->m_pDataIn;
      m_pBufferEnd = m_pBuf->m_pBufferEnd;
      m_pBuf->m_nBitsAvail = 32;
      if ( m_pDataIn == m_pBufferEnd )
      {
        m_pBuf->m_nBitsAvail = 1;
        m_pBuf->m_nInBufWord = 0;
        m_pBuf->m_pDataIn = m_pDataIn + 1;
      }
      else if ( m_pDataIn <= m_pBufferEnd )
      {
        m_pBuf->m_nInBufWord = *m_pDataIn;
        m_pBuf->m_pDataIn = m_pDataIn + 1;
      }
      else
      {
        m_pBuf->m_bOverflow = true;
        m_pBuf->m_nInBufWord = 0;
      }
    }
    else
    {
      m_pBuf->m_nInBufWord = m_nInBufWord >> 1;
    }
    if ( v4 == 0 )
      break;
    v8 = u->m_pBuf;
    m_nBitsAvail = v8->m_nBitsAvail;
    if ( m_nBitsAvail < 11 )
    {
      v17 = v8->m_pBufferEnd;
      v18 = v8->m_nInBufWord;
      v19 = 11 - m_nBitsAvail;
      v20 = v8->m_pDataIn;
      if ( v20 == v17 )
      {
        v8->m_nBitsAvail = 1;
        v8->m_nInBufWord = 0;
        v8->m_bOverflow = true;
        goto LABEL_23;
      }
      if ( v20 <= v17 )
      {
        v8->m_nInBufWord = *v20;
LABEL_23:
        v8->m_pDataIn = v20 + 1;
      }
      else
      {
        v8->m_bOverflow = true;
        v8->m_nInBufWord = 0;
      }
      if ( v8->m_bOverflow )
      {
        v13 = 0;
      }
      else
      {
        v21 = v8->m_nInBufWord;
        v22 = (v21 & CBitBuffer::s_nMaskTable[v19]) << v8->m_nBitsAvail;
        v8->m_nBitsAvail = 32 - v19;
        v8->m_nInBufWord = v21 >> v19;
        v13 = v22 | v18;
      }
      goto LABEL_27;
    }
    v10 = v8->m_nInBufWord;
    v11 = v10 & 0x7FF;
    v12 = m_nBitsAvail - 11;
    v8->m_nBitsAvail = v12;
    if ( v12 != 0 )
    {
      v8->m_nInBufWord = v10 >> 11;
      v13 = v10 & 0x7FF;
    }
    else
    {
      v14 = v8->m_pDataIn;
      v15 = v8->m_pBufferEnd;
      v8->m_nBitsAvail = 32;
      if ( v14 == v15 )
      {
        v8->m_nBitsAvail = 1;
        v8->m_nInBufWord = 0;
        v8->m_pDataIn = v14 + 1;
        v13 = v11;
      }
      else
      {
        if ( v14 <= v15 )
        {
          v16 = *v14;
          v8->m_pDataIn = v14 + 1;
          v8->m_nInBufWord = v16;
        }
        else
        {
          v8->m_bOverflow = true;
          v8->m_nInBufWord = 0;
        }
        v13 = v11;
      }
    }
LABEL_27:
    v23 = &u->m_pTo->m_pSnapshot->m_pEntities[v13];
    v23->m_nSerialNumber = -1;
    v23->m_pClass = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1017E8A0
// Name: public: void CHLTVClientState::SendPacket(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHLTVClientState::SendPacket(CHLTVClientState *this)
{
  int m_nDeltaTick; // eax
  INetChannel *m_NetChannel; // ecx
  int m_nValue; // eax
  long double v5; // st6
  long double v6; // st5
  NET_Tick tick; // [esp+4h] [ebp-24h] BYREF
  float commandInterval; // [esp+20h] [ebp-8h]
  float maxDelta; // [esp+24h] [ebp-4h]

  if ( this->m_nSignonState >= 2
    && this->m_flNextCmdTime <= net_time
    && this->m_NetChannel->CanPacket(this: this->m_NetChannel) )
  {
    if ( this->m_nSignonState == 6 )
    {
      m_nDeltaTick = this->m_nDeltaTick;
      m_NetChannel = this->m_NetChannel;
      tick.m_flHostFrameTime = host_frametime_unbounded;
      tick.m_nTick = m_nDeltaTick;
      tick.m_NetChannel = nullptr;
      tick.__vftable = (NET_Tick_vtbl *)&NET_Tick::`vftable';
      tick.m_bReliable = false;
      tick.m_flHostFrameTimeStdDeviation = host_frametime_stddeviation;
      m_NetChannel->SendNetMsg(this: m_NetChannel, a2: &tick, a3: false, a4: false);
    }
    this->m_NetChannel->SendDatagram(this: this->m_NetChannel, a2: nullptr);
    if ( this->m_nSignonState == 6 )
    {
      if ( tv_snapshotrate.m_pParent != nullptr )
        m_nValue = tv_snapshotrate.m_pParent->m_Value.m_nValue;
      else
        m_nValue = 0;
      commandInterval = 0.66666669 / (float)m_nValue;
      if ( commandInterval <= host_state.interval_per_tick )
        maxDelta = 0.66666669 / (float)m_nValue;
      else
        maxDelta = host_state.interval_per_tick;
      v5 = net_time - this->m_flNextCmdTime;
      v6 = 0.0;
      if ( v5 < 0.0 || (v6 = v5, v5 <= maxDelta) )
        this->m_flNextCmdTime = net_time + commandInterval - v6;
      else
        this->m_flNextCmdTime = net_time + commandInterval - maxDelta;
    }
    else
    {
      this->m_flNextCmdTime = net_time + 0.2;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1017E9E0
// Name: public: virtual bool CHLTVClientState::ProcessPacketEntities(class SVC_PacketEntities __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CHLTVClientState::ProcessPacketEntities(CHLTVClientState *this, SVC_PacketEntities *entmsg)
{
  bool v3; // zf
  int m_nDeltaFrom; // eax
  CFrameSnapshot *EmptySnapshot; // ebx
  CClientFrame *v8; // eax
  CNetworkStringTableContainer *v9; // eax
  float v10; // eax
  IServerMessageHandler_vtbl *v11; // ecx
  int v12; // eax
  int v13; // edx
  CFrameSnapshotEntry *m_pEntities; // eax
  ServerClass **v15; // ecx
  CNetworkStringTableContainer *m_StringTableContainer; // edx
  bool m_bIsDelta; // al
  int m_nUpdatedEntries; // ecx
  bool m_bUpdateBaseline; // al
  int v20; // edx
  void (__thiscall *v21)(char *, void ***); // edx
  void **v22; // [esp+8h] [ebp-4064h] BYREF
  bool v23; // [esp+Ch] [ebp-4060h]
  CClientFrame *v24; // [esp+10h] [ebp-405Ch]
  CNetworkStringTableContainer *v25; // [esp+14h] [ebp-4058h]
  int v26; // [esp+18h] [ebp-4054h]
  int v27; // [esp+1Ch] [ebp-4050h]
  int v28; // [esp+20h] [ebp-404Ch]
  int v29; // [esp+24h] [ebp-4048h]
  int v30; // [esp+28h] [ebp-4044h]
  bf_read *p_m_DataIn; // [esp+2Ch] [ebp-4040h]
  int v32; // [esp+38h] [ebp-4034h]
  bool v33; // [esp+3Ch] [ebp-4030h]
  int v34; // [esp+40h] [ebp-402Ch]
  int v35; // [esp+44h] [ebp-4028h]
  int v36; // [esp+4048h] [ebp-24h]
  void **v37; // [esp+404Ch] [ebp-20h] BYREF
  char v38; // [esp+4050h] [ebp-1Ch]
  int v39; // [esp+4054h] [ebp-18h]
  float v40; // [esp+405Ch] [ebp-10h]
  int m_nBaseline; // [esp+4060h] [ebp-Ch]
  CFrameSnapshot *v42; // [esp+4064h] [ebp-8h]
  CClientFrame *ClientFrame; // [esp+4068h] [ebp-4h]
  SVC_PacketEntities *msg; // [esp+4074h] [ebp+8h]

  v3 = !entmsg->m_bIsDelta;
  ClientFrame = nullptr;
  if ( !v3 )
  {
    m_nDeltaFrom = entmsg->m_nDeltaFrom;
    if ( LODWORD(this->m_ClockDriftMgr.m_ClockOffsets[15]) == m_nDeltaFrom )
    {
      Host_Error(error: "Update self-referencing, connection dropped.\n");
      return 0;
    }
    ClientFrame = CClientFrameManager::GetClientFrame(
                    this: (CClientFrameManager *)(*(_DWORD *)&this->m_bSaveMemory + 464),
                    nTick: m_nDeltaFrom,
                    bExact: true);
  }
  EmptySnapshot = CFrameSnapshotManager::CreateEmptySnapshot(
                    this: framesnapshotmanager,
                    tickcount: LODWORD(this->m_ClockDriftMgr.m_ClockOffsets[15]),
                    maxEntities: entmsg->m_nMaxEntries);
  v42 = EmptySnapshot;
  v8 = (CClientFrame *)MemAlloc_Alloc(nSize: 0x11Cu);
  if ( v8 != nullptr )
    v9 = (CNetworkStringTableContainer *)CClientFrame::CClientFrame(this: v8, pSnapshot: EmptySnapshot);
  else
    v9 = nullptr;
  this->m_StringTableContainer = v9;
  if ( entmsg->m_bUpdateBaseline )
  {
    CBaseClientState::CopyEntityBaseline(
      this: (CHLTVClientState *)((char *)this - 8),
      iFrom: entmsg->m_nBaseline,
      iTo: entmsg->m_nBaseline == 0);
    v10 = this->m_ClockDriftMgr.m_ClockOffsets[15];
    m_nBaseline = entmsg->m_nBaseline;
    v11 = this->CBaseClientState::IServerMessageHandler::INetMessageHandler::__vftable;
    v40 = v10;
    v38 = 1;
    v39 = 0;
    v37 = &CLC_BaselineAck::`vftable';
    (*((void (__thiscall **)(IServerMessageHandler_vtbl *, void ***, int, _DWORD))v11->dtr_INetMessageHandler + 41))(
      a1: v11,
      a2: &v37,
      a3: 1,
      a4: 0);
  }
  v12 = *(_DWORD *)&this->m_bRestrictServerCommands;
  if ( v12 != 0 )
  {
    v13 = *(_DWORD *)(v12 + 280);
    m_pEntities = EmptySnapshot->m_pEntities;
    v15 = *(ServerClass ***)(v13 + 8);
    for ( msg = nullptr; (int)msg < *(_DWORD *)(v13 + 12); msg = (SVC_PacketEntities *)((char *)msg + 1) )
    {
      m_pEntities->m_nSerialNumber = (int)v15[1];
      m_pEntities->m_pClass = *v15;
      ++m_pEntities;
      v15 += 3;
    }
    EmptySnapshot = v42;
  }
  m_StringTableContainer = this->m_StringTableContainer;
  v27 = -1;
  v28 = -1;
  v29 = -1;
  v36 = 0;
  v34 = 0;
  v35 = 0;
  p_m_DataIn = &entmsg->m_DataIn;
  m_bIsDelta = entmsg->m_bIsDelta;
  v24 = ClientFrame;
  m_nUpdatedEntries = entmsg->m_nUpdatedEntries;
  v23 = m_bIsDelta;
  m_bUpdateBaseline = entmsg->m_bUpdateBaseline;
  v25 = m_StringTableContainer;
  v20 = entmsg->m_nBaseline;
  v30 = m_nUpdatedEntries;
  v32 = v20;
  v21 = *(void (__thiscall **)(char *, void ***))(*((_DWORD *)this - 2) + 128);
  v33 = m_bUpdateBaseline;
  v22 = &CEntityReadInfo::`vftable';
  v26 = 3;
  v21(a1: (char *)this - 8, a2: &v22);
  CFrameSnapshot::ReleaseReference(this: EmptySnapshot);
  return CBaseClientState::ProcessPacketEntities(this, msg: entmsg);
}

//------------------------------------------------------------------------------
// Address: 0x1017EBE0
// Name: public: virtual void CHLTVClientState::ConnectionCrashed(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHLTVClientState::ConnectionCrashed(CHLTVClientState *this, const char *reason)
{
  Remote_t *v3; // eax
  const char *v4; // eax
  vgui::CTreeViewListControl *v5; // ecx
  ECommandTarget_t TraceType; // eax
  const char *v7; // [esp-8h] [ebp-Ch]

  CBaseClientState::ConnectionCrashed(this, reason);
  if ( tv_autoretry.m_pParent != nullptr
    && tv_autoretry.m_pParent->m_Value.m_nValue != 0
    && vgui::Image::GetWide(this: (CVTFTexture *)&this->m_Remote) > 0 )
  {
    v3 = CAddressList::Get(this: &this->m_Remote, index: 0);
    v4 = CUtlString::operator char const *(this: &v3->m_szRetryAddress);
    v7 = va(format: "tv_relay %s\n", v4);
    TraceType = CTraceFilter::GetTraceType(this: v5);
    Cbuf_AddText(eTarget: TraceType, pText: v7, nTickDelay: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1017EC40
// Name: public: virtual void CHLTVClientState::ConnectionClosing(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHLTVClientState::ConnectionClosing(CHLTVClientState *this, const char *reason)
{
  Remote_t *v3; // eax
  const char *v4; // eax
  vgui::CTreeViewListControl *v5; // ecx
  ECommandTarget_t TraceType; // eax
  const char *v7; // [esp-8h] [ebp-Ch]

  CBaseClientState::ConnectionClosing(this, reason);
  if ( tv_autoretry.m_pParent != nullptr
    && tv_autoretry.m_pParent->m_Value.m_nValue != 0
    && vgui::Image::GetWide(this: (CVTFTexture *)&this->m_Remote) > 0 )
  {
    v3 = CAddressList::Get(this: &this->m_Remote, index: 0);
    v4 = CUtlString::operator char const *(this: &v3->m_szRetryAddress);
    v7 = va(format: "tv_relay %s\n", v4);
    TraceType = CTraceFilter::GetTraceType(this: v5);
    Cbuf_AddText(eTarget: TraceType, pText: v7, nTickDelay: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1017ECA0
// Name: public: void CHLTVClientState::CopyNewEntity(class CEntityReadInfo __near &,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHLTVClientState::CopyNewEntity(CHLTVClientState *this, CFrameSnapshot *u, int iClass, int iSerialNum)
{
  ClientClass *ClientClass; // eax
  int m_pHLTVEntityData; // edi
  CFrameSnapshot *v8; // ecx
  int v9; // eax
  ServerClass *v10; // ebx
  PackedEntity *EntityBaseline; // eax
  int v12; // eax
  int NumFlatProps; // eax
  IChangeFrameList *v14; // ebx
  PackedEntity *PackedEntity; // eax
  int v16; // eax
  _DWORD *v17; // eax
  ServerClass *v18; // [esp-8h] [ebp-8064h]
  ClientClass *v19; // [esp-4h] [ebp-8060h]
  int pChangedProps[4096]; // [esp+Ch] [ebp-8050h] BYREF
  char packedData[16384]; // [esp+400Ch] [ebp-4050h] BYREF
  bf_write pOut; // [esp+800Ch] [ebp-50h] BYREF
  CBitRead v23; // [esp+8024h] [ebp-38h] BYREF
  ServerClass *pServerClass; // [esp+8048h] [ebp-14h]
  void *pData; // [esp+804Ch] [ebp-10h] BYREF
  CBaseClientState *v26; // [esp+8050h] [ebp-Ch]
  ClientClass *pClientClass; // [esp+8054h] [ebp-8h]
  int pDatalen; // [esp+8058h] [ebp-4h] BYREF
  CFrameSnapshot *pSnapshot; // [esp+8064h] [ebp+8h]
  PackedEntity *index; // [esp+8068h] [ebp+Ch]

  v26 = this;
  pServerClass = SV_FindServerClass(index: iClass);
  ClientClass = CBaseClientState::GetClientClass(this, index: iClass);
  m_pHLTVEntityData = (int)u->m_pHLTVEntityData;
  pClientClass = ClientClass;
  v8 = *(CFrameSnapshot **)(u->m_nNumEntities + 280);
  v9 = m_pHLTVEntityData;
  v8->m_pEntities[v9].m_nSerialNumber = iSerialNum;
  v10 = pServerClass;
  pSnapshot = v8;
  v8->m_pEntities[v9].m_pClass = pServerClass;
  pData = nullptr;
  pDatalen = 0;
  if ( LOBYTE(u->m_nTickCount) != 0
    && (EntityBaseline = CBaseClientState::GetEntityBaseline(
                           this: v26,
                           iBaseline: u->m_iExplicitDeleteSlots.m_Memory.m_nGrowSize,
                           nEntityIndex: m_pHLTVEntityData)) != nullptr
    && EntityBaseline->m_pClientClass == pClientClass )
  {
    pData = EntityBaseline->m_pData;
    v12 = EntityBaseline->m_nBits & 0x7FFFFFFF;
  }
  else
  {
    if ( !CBaseClientState::GetClassBaseline(this: v26, iClass, (const void **)&pData, &pDatalen) )
      _Error(a1: "HLTV_CopyNewEntity: GetDynamicBaseline(%d) failed.", iClass);
    v12 = 8 * pDatalen;
  }
  pDatalen = v12;
  NumFlatProps = SendTable_GetNumFlatProps(pSendTable: v10->m_pTable);
  v14 = nullptr;
  if ( LOBYTE(v26[1].IServerMessageHandler::INetMessageHandler::__vftable) == 0 )
    v14 = AllocChangeFrameList(nProperties: NumFlatProps, iCurTick: 0);
  PackedEntity = CFrameSnapshotManager::CreatePackedEntity(
                   this: framesnapshotmanager,
                   pSnapshot,
                   entity: m_pHLTVEntityData);
  v19 = pClientClass;
  v18 = pServerClass;
  index = PackedEntity;
  PackedEntity->m_pChangeFrameList = v14;
  PackedEntity::SetServerAndClientClass(this: PackedEntity, pServerClass: v18, pClientClass: v19);
  v23.m_bOverflow = false;
  v23.m_nDataBits = -1;
  v23.m_nDataBytes = 0;
  v23.m_pDebugName = "HLTV_ReadEnterPVS1";
  CBitRead::StartReading(this: &v23, pData, nBytes: (pDatalen + 7) >> 3, iStartBit: 0, nBits: pDatalen);
  bf_write::bf_write(this: &pOut, pDebugName: "HLTV_ReadEnterPVS2", pData: packedData, nBytes: 0x4000, nBits: -1);
  v16 = RecvTable_MergeDeltas(
          pTable: pClientClass->m_pRecvTable,
          pOldState: (bf_read *)&v23,
          pNewState: (bf_read *)u->m_nTempEntities,
          &pOut,
          objectID: -1,
          bDebugWatchInfo: false,
          pChangedProps);
  if ( v14 != nullptr )
    v14->SetChangeTick(this: v14, a2: pChangedProps, a3: v16, a4: pSnapshot->m_nTickCount);
  if ( LOBYTE(u->m_iExplicitDeleteSlots.m_Size) != 0 )
    CBaseClientState::SetEntityBaseline(
      this: v26,
      iBaseline: u->m_iExplicitDeleteSlots.m_Memory.m_nGrowSize == 0,
      pClientClass,
      index: (int)u->m_pHLTVEntityData,
      packedData,
      length: (pOut.m_iCurBit + 7) >> 3);
  PackedEntity::AllocAndCopyPadded(this: index, pData: packedData, size: (pOut.m_iCurBit + 7) >> 3);
  *(_DWORD *)(u->m_nNumEntities + 4) = m_pHLTVEntityData;
  v17 = (_DWORD *)(u->m_nNumEntities + 4 * (m_pHLTVEntityData >> 5) + 16);
  *v17 |= 1 << (m_pHLTVEntityData & 0x1F);
}

//------------------------------------------------------------------------------
// Address: 0x1017EEC0
// Name: HLTV_CopyExitingEnt
// Source: json
//------------------------------------------------------------------------------
void __usercall HLTV_CopyExitingEnt(CEntityReadInfo *u@<edi>)
{
  CFrameSnapshot *m_pSnapshot; // ebx
  int m_nOldEntity; // esi
  CFrameSnapshotEntry *v3; // ecx
  CFrameSnapshotEntry *v4; // eax
  unsigned int *v5; // eax

  if ( u->m_bAsDelta )
  {
    m_pSnapshot = u->m_pTo->m_pSnapshot;
    m_nOldEntity = u->m_nOldEntity;
    v3 = &m_pSnapshot->m_pEntities[m_nOldEntity];
    v4 = &u->m_pFrom->m_pSnapshot->m_pEntities[m_nOldEntity];
    v3->m_pClass = v4->m_pClass;
    v3->m_nSerialNumber = v4->m_nSerialNumber;
    v3->m_pPackedData = v4->m_pPackedData;
    _InterlockedExchangeAdd(
      &CFrameSnapshotManager::GetPackedEntity(this: framesnapshotmanager, pSnapshot: m_pSnapshot, entity: m_nOldEntity)->m_ReferenceCount.m_value,
      1u);
    u->m_pTo->last_entity = m_nOldEntity;
    v5 = &u->m_pTo->transmit_entity.m_Ints[m_nOldEntity >> 5];
    *v5 |= 1 << (m_nOldEntity & 0x1F);
  }
  else
  {
    ConMsg(a1: "WARNING: CopyExitingEnt on full update.\n");
    u->m_UpdateType = Failed;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1017EF50
// Name: public: void CHLTVClientState::SendClientInfo(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHLTVClientState::SendClientInfo(CHLTVClientState *this)
{
  unsigned int CRC; // eax
  INetChannel *m_NetChannel; // ecx
  CLC_ClientInfo info; // [esp+8h] [ebp-50h] BYREF

  info.m_bReliable = true;
  info.m_NetChannel = nullptr;
  info.__vftable = (CLC_ClientInfo_vtbl *)&CLC_ClientInfo::`vftable';
  CRC = SendTable_GetCRC();
  m_NetChannel = this->m_NetChannel;
  info.m_nSendTableCRC = CRC;
  info.m_nServerCount = this->m_nServerCount;
  info.m_bIsHLTV = true;
  info.m_nFriendsID = 0;
  info.m_FriendsName[0] = 0;
  memset(info.m_nCustomFiles, 0, sizeof(info.m_nCustomFiles));
  m_NetChannel->SendNetMsg(this: m_NetChannel, a2: &info, a3: false, a4: false);
}

//------------------------------------------------------------------------------
// Address: 0x1017EFB0
// Name: public: void CHLTVClientState::ReadEnterPVS(class CEntityReadInfo __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHLTVClientState::ReadEnterPVS(CHLTVClientState *this, CFrameSnapshot *u)
{
  int m_nServerClassBits; // edx
  bf_read *m_nTempEntities; // eax
  int m_nBitsAvail; // ecx
  unsigned int v5; // esi
  unsigned int v6; // edi
  int v7; // ecx
  const unsigned int *v8; // ecx
  const unsigned int *v9; // edx
  const unsigned int *m_pBufferEnd; // esi
  unsigned int m_nInBufWord; // edi
  const unsigned int *m_pDataIn; // ecx
  CFrameSnapshot *v13; // edi
  bf_read *v14; // eax
  int v15; // ecx
  unsigned int v16; // edx
  int v17; // esi
  int v18; // eax
  const unsigned int *v19; // ecx
  const unsigned int *v20; // edx
  unsigned int v21; // edx
  const unsigned int *v22; // esi
  unsigned int v23; // edi
  int v24; // edx
  const unsigned int *v25; // ecx
  unsigned int v26; // esi
  unsigned int v27; // ebx
  CHLTVEntityData *m_nValidEntities; // eax
  CFrameSnapshotEntry *m_pEntities; // ecx
  signed int NextSetBit; // eax
  int iClass; // [esp+10h] [ebp-4h]

  m_nServerClassBits = this->m_nServerClassBits;
  m_nTempEntities = (bf_read *)u->m_nTempEntities;
  m_nBitsAvail = m_nTempEntities->m_nBitsAvail;
  if ( m_nBitsAvail < m_nServerClassBits )
  {
    m_pBufferEnd = m_nTempEntities->m_pBufferEnd;
    m_nInBufWord = m_nTempEntities->m_nInBufWord;
    m_nServerClassBits -= m_nBitsAvail;
    m_pDataIn = m_nTempEntities->m_pDataIn;
    if ( m_pDataIn == m_pBufferEnd )
    {
      m_nTempEntities->m_nBitsAvail = 1;
      m_nTempEntities->m_nInBufWord = 0;
      m_nTempEntities->m_bOverflow = true;
    }
    else
    {
      if ( m_pDataIn > m_pBufferEnd )
      {
        m_nTempEntities->m_bOverflow = true;
        m_nTempEntities->m_nInBufWord = 0;
LABEL_14:
        if ( m_nTempEntities->m_bOverflow )
        {
          iClass = 0;
          goto LABEL_19;
        }
        v5 = m_nTempEntities->m_nInBufWord;
        v6 = ((v5 & CBitBuffer::s_nMaskTable[m_nServerClassBits]) << m_nTempEntities->m_nBitsAvail) | m_nInBufWord;
        m_nTempEntities->m_nBitsAvail = 32 - m_nServerClassBits;
        goto LABEL_17;
      }
      m_nTempEntities->m_nInBufWord = *m_pDataIn;
    }
    m_nTempEntities->m_pDataIn = m_pDataIn + 1;
    goto LABEL_14;
  }
  v5 = m_nTempEntities->m_nInBufWord;
  v6 = v5 & CBitBuffer::s_nMaskTable[m_nServerClassBits];
  v7 = m_nBitsAvail - m_nServerClassBits;
  m_nTempEntities->m_nBitsAvail = v7;
  if ( v7 == 0 )
  {
    v8 = m_nTempEntities->m_pDataIn;
    v9 = m_nTempEntities->m_pBufferEnd;
    m_nTempEntities->m_nBitsAvail = 32;
    if ( v8 == v9 )
    {
      m_nTempEntities->m_nBitsAvail = 1;
      m_nTempEntities->m_nInBufWord = 0;
      m_nTempEntities->m_pDataIn = v8 + 1;
    }
    else if ( v8 <= v9 )
    {
      m_nTempEntities->m_nInBufWord = *v8;
      m_nTempEntities->m_pDataIn = v8 + 1;
    }
    else
    {
      m_nTempEntities->m_bOverflow = true;
      m_nTempEntities->m_nInBufWord = 0;
    }
    goto LABEL_18;
  }
LABEL_17:
  m_nTempEntities->m_nInBufWord = v5 >> m_nServerClassBits;
LABEL_18:
  iClass = v6;
LABEL_19:
  v13 = u;
  v14 = (bf_read *)u->m_nTempEntities;
  v15 = v14->m_nBitsAvail;
  if ( v15 < 10 )
  {
    v22 = v14->m_pBufferEnd;
    v23 = v14->m_nInBufWord;
    v24 = 10 - v15;
    v25 = v14->m_pDataIn;
    if ( v25 == v22 )
    {
      v14->m_nBitsAvail = 1;
      v14->m_nInBufWord = 0;
      v14->m_bOverflow = true;
    }
    else
    {
      if ( v25 > v22 )
      {
        v14->m_bOverflow = true;
        v14->m_nInBufWord = 0;
LABEL_34:
        if ( v14->m_bOverflow )
        {
          v18 = 0;
        }
        else
        {
          v26 = v14->m_nInBufWord;
          v27 = (v26 & CBitBuffer::s_nMaskTable[v24]) << v14->m_nBitsAvail;
          v14->m_nBitsAvail = 32 - v24;
          v14->m_nInBufWord = v26 >> v24;
          v18 = v27 | v23;
        }
        v13 = u;
        goto LABEL_38;
      }
      v14->m_nInBufWord = *v25;
    }
    v14->m_pDataIn = v25 + 1;
    goto LABEL_34;
  }
  v16 = v14->m_nInBufWord;
  v17 = v16 & 0x3FF;
  v14->m_nBitsAvail = v15 - 10;
  if ( v15 == 10 )
  {
    v19 = v14->m_pDataIn;
    v20 = v14->m_pBufferEnd;
    v14->m_nBitsAvail = 32;
    if ( v19 == v20 )
    {
      v14->m_nBitsAvail = 1;
      v14->m_nInBufWord = 0;
      v14->m_pDataIn = v19 + 1;
      v18 = v17;
    }
    else
    {
      if ( v19 <= v20 )
      {
        v21 = *v19;
        v14->m_pDataIn = v19 + 1;
        v14->m_nInBufWord = v21;
      }
      else
      {
        v14->m_bOverflow = true;
        v14->m_nInBufWord = 0;
      }
      v18 = v17;
    }
  }
  else
  {
    v14->m_nInBufWord = v16 >> 10;
    v18 = v16 & 0x3FF;
  }
LABEL_38:
  CHLTVClientState::CopyNewEntity(this, u: v13, iClass, iSerialNum: v18);
  m_nValidEntities = (CHLTVEntityData *)v13->m_nValidEntities;
  if ( v13->m_pHLTVEntityData == m_nValidEntities )
  {
    m_pEntities = v13->m_pEntities;
    if ( m_pEntities == nullptr
      || (NextSetBit = CFixedBitVecBase<2048>::FindNextSetBit(
                         this: (CFixedBitVecBase<2048> *)&m_pEntities[1].m_nSerialNumber,
                         startBit: (int)m_nValidEntities->origin + 1),
          v13->m_nValidEntities = NextSetBit,
          NextSetBit < 0) )
    {
      v13->m_nValidEntities = 9999;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1017F1C0
// Name: public: void CHLTVClientState::ReadDeltaEnt(class CEntityReadInfo __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHLTVClientState::ReadDeltaEnt(CHLTVClientState *this, CEntityReadInfo *u)
{
  CEntityReadInfo *v2; // esi
  CFrameSnapshot *m_pSnapshot; // eax
  int m_nNewEntity; // edi
  CFrameSnapshot *v5; // ebx
  CFrameSnapshotEntry *m_pEntities; // ecx
  CFrameSnapshotEntry *v7; // ecx
  CFrameSnapshotEntry *v8; // eax
  PackedEntity *PackedEntity; // ebx
  PackedEntity *v10; // edi
  bool v11; // zf
  int m_nBits; // ecx
  const char *m_pData; // eax
  CEntityReadInfo *v14; // ecx
  int v15; // eax
  char *v16; // eax
  unsigned int *v17; // eax
  CClientFrame *m_pFrom; // eax
  signed int NextSetBit; // eax
  _BYTE pData[16384]; // [esp+Ch] [ebp-8048h] BYREF
  int pChangedProps[4096]; // [esp+400Ch] [ebp-4048h] BYREF
  CBitRead v22; // [esp+800Ch] [ebp-48h] BYREF
  bf_write pOut; // [esp+8030h] [ebp-24h] BYREF
  CFrameSnapshot *v24; // [esp+8048h] [ebp-Ch]
  CHLTVClientState *v25; // [esp+804Ch] [ebp-8h]
  CFrameSnapshot *pSnapshot; // [esp+8050h] [ebp-4h] BYREF

  v2 = u;
  m_pSnapshot = u->m_pFrom->m_pSnapshot;
  m_nNewEntity = u->m_nNewEntity;
  v25 = this;
  v5 = u->m_pTo->m_pSnapshot;
  m_pEntities = v5->m_pEntities;
  pSnapshot = m_pSnapshot;
  v7 = &m_pEntities[m_nNewEntity];
  v8 = &m_pSnapshot->m_pEntities[m_nNewEntity];
  v7->m_pClass = v8->m_pClass;
  v7->m_nSerialNumber = v8->m_nSerialNumber;
  v7->m_pPackedData = v8->m_pPackedData;
  v24 = v5;
  PackedEntity = CFrameSnapshotManager::CreatePackedEntity(
                   this: framesnapshotmanager,
                   pSnapshot: v5,
                   entity: m_nNewEntity);
  v10 = CFrameSnapshotManager::GetPackedEntity(this: framesnapshotmanager, pSnapshot, entity: m_nNewEntity);
  PackedEntity::SetServerAndClientClass(
    this: PackedEntity,
    pServerClass: v10->m_pServerClass,
    pClientClass: v10->m_pClientClass);
  v11 = !v25->m_bSaveMemory;
  pSnapshot = nullptr;
  if ( v11 )
  {
    pSnapshot = (CFrameSnapshot *)v10->m_pChangeFrameList->Copy(this: v10->m_pChangeFrameList);
    PackedEntity->m_pChangeFrameList = (IChangeFrameList *)pSnapshot;
  }
  m_nBits = v10->m_nBits;
  if ( m_nBits >= 0 )
  {
    m_pData = (const char *)v10->m_pData;
    v14 = (CEntityReadInfo *)(m_nBits & 0x7FFFFFFF);
    u = v14;
  }
  else
  {
    m_pData = CBaseServer::UncompressPackedEntity(this: &v25->m_pHLTV->CBaseServer, pPackedEntity: v10, bits: (int *)&u);
    v14 = u;
  }
  v22.m_bOverflow = false;
  v22.m_nDataBits = -1;
  v22.m_nDataBytes = 0;
  v22.m_pDebugName = "HLTV_ReadEnterPVS1";
  CBitRead::StartReading(
    this: &v22,
    pData: m_pData,
    nBytes: (int)(&v14->m_bAsDelta + 3) >> 3,
    iStartBit: 0,
    nBits: (int)v14);
  bf_write::bf_write(this: &pOut, pDebugName: "HLTV_ReadEnterPVS2", pData, nBytes: 0x4000, nBits: -1);
  v15 = RecvTable_MergeDeltas(
          pTable: PackedEntity->m_pClientClass->m_pRecvTable,
          pOldState: (bf_read *)&v22,
          pNewState: v2->m_pBuf,
          &pOut,
          objectID: -1,
          bDebugWatchInfo: false,
          pChangedProps);
  if ( pSnapshot != nullptr )
    (*(void (__thiscall **)(CFrameSnapshot *, int *, int, int))(pSnapshot->m_ListIndex.m_value + 8))(
      a1: pSnapshot,
      a2: pChangedProps,
      a3: v15,
      a4: v24->m_nTickCount);
  if ( v25->m_bSaveMemory )
  {
    pSnapshot = (CFrameSnapshot *)pOut.m_iCurBit;
    v16 = CBaseServer::CompressPackedEntity(
            this: &v25->m_pHLTV->CBaseServer,
            pServerClass: PackedEntity->m_pServerClass,
            data: (const char *)pOut.m_pData,
            bits: (int *)&pSnapshot);
    PackedEntity::AllocAndCopyPadded(this: PackedEntity, pData: v16, size: ((int)&pSnapshot->m_nTickCount + 3) >> 3);
    PackedEntity->m_nBits |= 0x80000000;
  }
  else
  {
    PackedEntity::AllocAndCopyPadded(this: PackedEntity, pData, size: (pOut.m_iCurBit + 7) >> 3);
  }
  v2->m_pTo->last_entity = v2->m_nNewEntity;
  v17 = &v2->m_pTo->transmit_entity.m_Ints[v2->m_nNewEntity >> 5];
  *v17 |= 1 << (v2->m_nNewEntity & 0x1F);
  m_pFrom = v2->m_pFrom;
  if ( m_pFrom == nullptr
    || (NextSetBit = CFixedBitVecBase<2048>::FindNextSetBit(
                       this: &m_pFrom->transmit_entity,
                       startBit: v2->m_nOldEntity + 1),
        v2->m_nOldEntity = NextSetBit,
        NextSetBit < 0) )
  {
    v2->m_nOldEntity = 9999;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1017F3D0
// Name: public: virtual void CHLTVClientState::ReadPacketEntities(class CEntityReadInfo __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHLTVClientState::ReadPacketEntities(CHLTVClientState *this, CEntityReadInfo *u)
{
  CClientFrame *m_pFrom; // eax
  signed int NextSetBit; // eax
  bool v4; // sf
  int m_nOldEntity; // ecx
  int m_UpdateFlags; // eax
  UpdateType m_UpdateType; // eax
  CClientFrame *v8; // eax
  CFrameSnapshotEntry *v9; // eax
  CClientFrame *v10; // edx
  int v11; // ecx
  int v12; // eax
  unsigned int v13; // ecx
  int v14; // edx
  int v15; // eax
  CClientFrame *v16; // edx
  int v17; // ecx
  int v18; // eax
  unsigned int v19; // ecx
  int v20; // edx
  unsigned int v21; // edx

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
  while ( u->m_UpdateType < Finished )
  {
    v4 = --u->m_nHeaderCount < 0;
    u->m_bIsEntity = !v4;
    if ( !v4 )
      CL_ParseDeltaHeader(u);
    u->m_UpdateType = PreserveEnt;
    do
    {
      if ( u->m_bIsEntity && (m_nOldEntity = u->m_nOldEntity, u->m_nNewEntity <= m_nOldEntity) )
      {
        m_UpdateFlags = u->m_UpdateFlags;
        if ( (m_UpdateFlags & 4) != 0 )
        {
          u->m_UpdateType = EnterPVS;
          m_UpdateType = EnterPVS;
        }
        else if ( (m_UpdateFlags & 1) != 0 )
        {
          u->m_UpdateType = LeavePVS;
          m_UpdateType = LeavePVS;
        }
        else
        {
          u->m_UpdateType = DeltaEnt;
          m_UpdateType = u->m_UpdateType;
        }
      }
      else
      {
        v8 = u->m_pFrom;
        if ( v8 == nullptr || (m_nOldEntity = u->m_nOldEntity) > v8->last_entity )
        {
          u->m_UpdateType = Finished;
          continue;
        }
        u->m_UpdateType = PreserveEnt;
        m_UpdateType = PreserveEnt;
      }
      switch ( m_UpdateType )
      {
        case EnterPVS:
          CHLTVClientState::ReadEnterPVS(this, (CFrameSnapshot *)u);
          continue;
        case LeavePVS:
          if ( (u->m_UpdateFlags & 2) != 0 )
          {
            v9 = &u->m_pTo->m_pSnapshot->m_pEntities[m_nOldEntity];
            v9->m_nSerialNumber = -1;
            v9->m_pClass = nullptr;
          }
          v10 = u->m_pFrom;
          if ( v10 == nullptr )
            goto LABEL_30;
          v11 = u->m_nOldEntity + 1;
          if ( v11 >= 2048 )
            goto LABEL_28;
          v12 = v11 >> 5;
          v13 = v10->transmit_entity.m_Ints[v11 >> 5] & `GetStartBitMask'::`2'::g_StartMask[v11 & 0x1F];
          v14 = (int)&v10->transmit_entity + 4 * v12;
          while ( v13 == 0 )
          {
            v13 = *(_DWORD *)(v14 + 4);
            v14 += 4;
            if ( ++v12 > 63 )
              goto LABEL_28;
          }
          _BitScanForward(&v13, v13);
          v15 = v13 + 32 * v12;
          goto LABEL_29;
        case DeltaEnt:
          CHLTVClientState::ReadDeltaEnt(this, u);
          continue;
        case PreserveEnt:
          if ( u->m_nNewEntity >= 2048 )
            Host_Error(error: "CL_ReadPreserveEnt: u.m_nNewEntity == MAX_EDICTS");
          HLTV_CopyExitingEnt(u);
          v16 = u->m_pFrom;
          if ( v16 == nullptr )
            goto LABEL_30;
          v17 = u->m_nOldEntity + 1;
          if ( v17 >= 2048 )
            goto LABEL_28;
          v18 = v17 >> 5;
          v19 = v16->transmit_entity.m_Ints[v17 >> 5] & `GetStartBitMask'::`2'::g_StartMask[v17 & 0x1F];
          v20 = (int)&v16->transmit_entity + 4 * v18;
          break;
      }
      while ( v19 == 0 )
      {
        v19 = *(_DWORD *)(v20 + 4);
        v20 += 4;
        if ( ++v18 > 63 )
        {
LABEL_28:
          v15 = -1;
          goto LABEL_29;
        }
      }
      _BitScanForward(&v21, v19);
      v15 = v21 + 32 * v18;
LABEL_29:
      u->m_nOldEntity = v15;
      if ( v15 < 0 )
LABEL_30:
        u->m_nOldEntity = 9999;
    }
    while ( u->m_UpdateType == PreserveEnt );
  }
  if ( u->m_bAsDelta && u->m_UpdateType == Finished )
    CHLTVClientState::ReadDeletions(this, u);
  if ( u->m_pBuf->m_bOverflow )
    Host_Error(error: "CL_ParsePacketEntities:  buffer read overflow\n");
  if ( !u->m_bAsDelta )
    this->m_flNextCmdTime = 0.0;
}

//------------------------------------------------------------------------------
// Address: 0x1017F610
// Name: public: virtual bool CHLTVClientState::ProcessGameEventList(class SVC_GameEventList __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CHLTVClientState::ProcessGameEventList(CHLTVClientState *this, SVC_GameEventList *msg)
{
  INetChannel *m_NetChannel; // edx
  int m_nLength; // ecx
  int m_nNumEvents; // edx
  unsigned __int8 *m_pData; // edx
  int m_nDataBytes; // ecx
  int m_nDataBits; // edx
  int m_iCurBit; // ecx
  int v11; // edx
  const char *m_pDebugName; // ecx
  int v13; // edi
  void *v14; // esp
  _BYTE v16[12]; // [esp+0h] [ebp-64h] BYREF
  SVC_GameEventList tmpMsg; // [esp+Ch] [ebp-58h] BYREF
  CHLTVClientState *v18; // [esp+60h] [ebp-4h]

  v18 = this;
  m_NetChannel = msg->m_NetChannel;
  tmpMsg.m_bReliable = msg->m_bReliable;
  tmpMsg.m_pMessageHandler = msg->m_pMessageHandler;
  m_nLength = msg->m_nLength;
  tmpMsg.m_NetChannel = m_NetChannel;
  m_nNumEvents = msg->m_nNumEvents;
  tmpMsg.m_nLength = m_nLength;
  tmpMsg.m_nNumEvents = m_nNumEvents;
  m_pData = msg->m_DataOut.m_pData;
  tmpMsg.__vftable = (SVC_GameEventList_vtbl *)&SVC_GameEventList::`vftable';
  tmpMsg.m_DataIn = msg->m_DataIn;
  m_nDataBytes = msg->m_DataOut.m_nDataBytes;
  tmpMsg.m_DataOut.m_pData = m_pData;
  m_nDataBits = msg->m_DataOut.m_nDataBits;
  tmpMsg.m_DataOut.m_nDataBytes = m_nDataBytes;
  m_iCurBit = msg->m_DataOut.m_iCurBit;
  tmpMsg.m_DataOut.m_nDataBits = m_nDataBits;
  v11 = *(_DWORD *)&msg->m_DataOut.m_bOverflow;
  tmpMsg.m_DataOut.m_iCurBit = m_iCurBit;
  m_pDebugName = msg->m_DataOut.m_pDebugName;
  *(_DWORD *)&tmpMsg.m_DataOut.m_bOverflow = v11;
  tmpMsg.m_DataOut.m_pDebugName = m_pDebugName;
  CBaseClientState::ProcessGameEventList(this, msg: &tmpMsg);
  v13 = 4 * ((((msg->m_nLength + 7) >> 3) + 3) / 4);
  v14 = alloca(v13);
  CBitRead::ReadBits(this: &msg->m_DataIn, pOutData: v16, nBits: msg->m_nLength);
  bf_write::StartWriting(this: &msg->m_DataOut, pData: v16, nBytes: v13, iStartBit: msg->m_nLength, nBits: -1);
  return CHLTVServer::SendNetMsg(this: *(CHLTVServer **)&v18->m_bSaveMemory, msg, bForceReliable: false, bVoice: false);
}

//------------------------------------------------------------------------------
// Address: 0x1017F6F0
// Name: public: virtual bool CHLTVClientState::SetSignonState(int,int,class NET_SignonState __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CHLTVClientState::SetSignonState(CHLTVClientState *this, int state, int count, NET_SignonState *msg)
{
  char result; // al
  INetChannel *m_NetChannel; // ecx
  NetMessageCvar_t acvar; // [esp+10h] [ebp-24Ch] BYREF
  void **v8; // [esp+218h] [ebp-44h] BYREF
  char v9; // [esp+21Ch] [ebp-40h]
  int v10; // [esp+220h] [ebp-3Ch]
  int m_nSignonState; // [esp+228h] [ebp-34h]
  int v12; // [esp+22Ch] [ebp-30h]
  int v13; // [esp+230h] [ebp-2Ch]
  CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > v14; // [esp+234h] [ebp-28h] BYREF
  CUtlVector<NetMessageCvar_t,CUtlMemory<NetMessageCvar_t,int> > v15; // [esp+248h] [ebp-14h] BYREF

  result = CBaseClientState::SetSignonState(this, state, count, msg);
  if ( result != 0 )
  {
    switch ( this->m_nSignonState )
    {
      case 2:
        ((void (__stdcall *)(_DWORD, _DWORD))this->m_NetChannel->SetTimeout)(a1: 300.0, a2: 0);
        this->m_NetChannel->Clear(this: this->m_NetChannel);
        LOBYTE(v14.m_Memory.m_nGrowSize) = 1;
        v14.m_Size = 0;
        v14.m_Memory.m_nAllocationCount = (int)&NET_SetConVar::`vftable';
        memset(&v15, 0, sizeof(v15));
        Host_BuildUserInfoUpdateMessage(nSplitScreenSlot: 0, rCvarList: &v15, nonDefault: false);
        _V_strcpy(dest: acvar.name, src: "tv_relay");
        _V_strcpy(dest: acvar.value, src: "1");
        CUtlVector<NetMessageCvar_t,CUtlMemory<NetMessageCvar_t,int>>::InsertBefore(
          this: &v15,
          elem: v15.m_Size,
          src: &acvar);
        this->m_NetChannel->SendNetMsg(
          this: this->m_NetChannel,
          a2: (INetMessage *)&v14.m_Memory.m_nAllocationCount,
          a3: false,
          a4: false);
        CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&v15);
        break;
      case 3:
        CHLTVClientState::SendClientInfo(this);
        break;
      case 5:
        CHLTVServer::SignonComplete(this: this->m_pHLTV);
        break;
      case 6:
        ((void (__stdcall *)(_DWORD, _DWORD))this->m_NetChannel->SetTimeout)(
          a1: tv_timeout.m_pParent->m_Value.m_fValue,
          a2: 0);
        if ( tv_autorecord.m_pParent != nullptr && tv_autorecord.m_pParent->m_Value.m_nValue != 0 )
        {
          CHLTVDemoRecorder::StartAutoRecording(this: &hltv->m_DemoRecorder);
          this->m_NetChannel->SetDemoRecorder(this: this->m_NetChannel, a2: &hltv->m_DemoRecorder);
        }
        break;
      case 7:
        CHLTVServer::Changelevel(this: this->m_pHLTV);
        ((void (__stdcall *)(_DWORD, _DWORD))this->m_NetChannel->SetTimeout)(a1: 300.0, a2: 0);
        break;
      default:
        break;
    }
    if ( this->m_nSignonState >= 2 )
    {
      m_NetChannel = this->m_NetChannel;
      m_nSignonState = this->m_nSignonState;
      v12 = count;
      v9 = 1;
      v10 = 0;
      v8 = &NET_SignonState::`vftable';
      memset(&v14, 0, sizeof(v14));
      memset(&v15, 0, sizeof(v15));
      v13 = 0;
      m_NetChannel->SendNetMsg(this: m_NetChannel, a2: (INetMessage *)&v8, a3: false, a4: false);
      CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&v15);
      CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: &v14);
    }
    return 1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1017F8F0
// Name: public: void CHLTVClientState::UpdateStats(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHLTVClientState::UpdateStats(CHLTVClientState *this)
{
  CHLTVServer *m_pHLTV; // ecx
  int v3; // eax
  CHLTVServer *v4; // ecx
  int v5; // eax
  const char *v6; // eax
  int v7; // [esp-8h] [ebp-244h]
  NetMessageCvar_t acvar; // [esp+4h] [ebp-238h] BYREF
  NET_SetConVar conVars; // [esp+20Ch] [ebp-30h] BYREF
  int clients; // [esp+230h] [ebp-Ch] BYREF
  int proxies; // [esp+234h] [ebp-8h] BYREF
  int slots; // [esp+238h] [ebp-4h] BYREF

  if ( this->m_nSignonState >= 6 )
  {
    if ( this->m_fNextSendUpdateTime <= net_time )
    {
      this->m_fNextSendUpdateTime = net_time + 8.0;
      CHLTVServer::GetRelayStats(this: this->m_pHLTV, &proxies, &slots, &clients);
      m_pHLTV = this->m_pHLTV;
      ++proxies;
      v3 = m_pHLTV->GetMaxClients(this: &m_pHLTV->CBaseServer);
      v4 = this->m_pHLTV;
      slots += v3;
      v5 = v4->GetNumClients(this: &v4->CBaseServer);
      clients += v5;
      conVars.m_bReliable = true;
      conVars.m_NetChannel = nullptr;
      conVars.__vftable = (NET_SetConVar_vtbl *)&NET_SetConVar::`vftable';
      memset(&conVars.m_ConVars, 0, sizeof(conVars.m_ConVars));
      V_strncpy(pDest: acvar.name, pSrc: "hltv_proxies", maxLen: 260);
      V_snprintf(pDest: acvar.value, maxLen: 260, pFormat: "%d", proxies);
      CUtlVector<NetMessageCvar_t,CUtlMemory<NetMessageCvar_t,int>>::InsertBefore(
        this: &conVars.m_ConVars,
        elem: conVars.m_ConVars.m_Size,
        src: &acvar);
      V_strncpy(pDest: acvar.name, pSrc: "hltv_clients", maxLen: 260);
      V_snprintf(pDest: acvar.value, maxLen: 260, pFormat: "%d", clients);
      CUtlVector<NetMessageCvar_t,CUtlMemory<NetMessageCvar_t,int>>::InsertBefore(
        this: &conVars.m_ConVars,
        elem: conVars.m_ConVars.m_Size,
        src: &acvar);
      V_strncpy(pDest: acvar.name, pSrc: "hltv_slots", maxLen: 260);
      V_snprintf(pDest: acvar.value, maxLen: 260, pFormat: "%d", slots);
      CUtlVector<NetMessageCvar_t,CUtlMemory<NetMessageCvar_t,int>>::InsertBefore(
        this: &conVars.m_ConVars,
        elem: conVars.m_ConVars.m_Size,
        src: &acvar);
      V_strncpy(pDest: acvar.name, pSrc: "hltv_addr", maxLen: 260);
      v7 = this->m_pHLTV->GetUDPPort(this: &this->m_pHLTV->CBaseServer);
      v6 = netadr_s::ToString(this: &net_local_adr, baseOnly: true);
      V_snprintf(pDest: acvar.value, maxLen: 260, pFormat: "%s:%u", v6, v7);
      CUtlVector<NetMessageCvar_t,CUtlMemory<NetMessageCvar_t,int>>::InsertBefore(
        this: &conVars.m_ConVars,
        elem: conVars.m_ConVars.m_Size,
        src: &acvar);
      this->m_NetChannel->SendNetMsg(this: this->m_NetChannel, a2: &conVars, a3: false, a4: false);
      CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&conVars.m_ConVars);
    }
  }
  else
  {
    this->m_fNextSendUpdateTime = 0.0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1017FB00
// Name: public: virtual void CHLTVClientState::RunFrame(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHLTVClientState::RunFrame(CHLTVClientState *this)
{
  CBaseClientState::RunFrame(this);
  if ( this->m_NetChannel != nullptr
    && this->m_NetChannel->IsTimedOut(this: this->m_NetChannel)
    && this->m_nSignonState >= 2 )
  {
    ConMsg(a1: "\nSourceTV connection timed out.\n");
    this->Disconnect(this, a2: true);
  }
  else
  {
    CHLTVClientState::UpdateStats(this);
  }
}

} // namespace engine_xlsp
