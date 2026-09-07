// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: engine/sv_client.cpp
// Functions: 53
// ============================================================

#include "engine\sv_client.h"

//------------------------------------------------------------------------------
// Address: 0x1011A270
// Name: public: virtual bool CGameClient::ProcessVoiceData(class CLC_VoiceData __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CGameClient::ProcessVoiceData(CGameClient *this, CLC_VoiceData *msg)
{
  IClient *v3; // eax
  char pOutData[4096]; // [esp+8h] [ebp-1000h] BYREF

  CBitRead::ReadBits(this: &msg->m_DataIn, pOutData, nBits: msg->m_nLength);
  serverGameClients->ClientVoice(this: serverGameClients, a2: (edict_t *)this->m_LastMovementTick);
  if ( this == (CGameClient *)8 )
    v3 = nullptr;
  else
    v3 = (IClient *)((char *)this - 4);
  SV_BroadcastVoiceData(cl: v3, nBytes: (msg->m_nLength + 7) >> 3, data: pOutData, xuid: msg->m_xuid);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1011A2F0
// Name: public: virtual bool CGameClient::ProcessRespondCvarValue(class CLC_RespondCvarValue __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CGameClient::ProcessRespondCvarValue(CGameClient *this, CLC_RespondCvarValue *msg)
{
  int m_iCookie; // edx

  m_iCookie = msg->m_iCookie;
  if ( m_iCookie > 0 && g_pServerPluginHandler != nullptr )
    g_pServerPluginHandler->OnQueryCvarValueFinished(
      this: g_pServerPluginHandler,
      a2: m_iCookie,
      a3: (edict_t *)this->m_LastMovementTick,
      a4: msg->m_eStatusCode,
      a5: msg->m_szCvarName,
      a6: msg->m_szCvarValue);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1011A330
// Name: public: void CGameClient::DownloadCustomizations(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameClient::DownloadCustomizations(CGameClient *this)
{
  CBaseClient::CustomFile_s *m_nCustomFiles; // esi
  int i; // ebx
  CCustomFilename hexname; // [esp+Ch] [ebp-118h] BYREF
  char out[16]; // [esp+110h] [ebp-14h] BYREF
  unsigned __int8 in[4]; // [esp+120h] [ebp-4h] BYREF

  m_nCustomFiles = this->m_nCustomFiles;
  for ( i = 4; i != 0; --i )
  {
    if ( m_nCustomFiles->crc != 0 )
    {
      *(_DWORD *)in = m_nCustomFiles->crc;
      V_binarytohex(in, inputbytes: 4, out, outsize: 16);
      V_snprintf(pDest: hexname.m_Filename, maxLen: 260, pFormat: "%s/%s.dat", "downloads", out);
      if ( !g_pFileSystem->FileExists(this: &g_pFileSystem->IBaseFileSystem, a2: (const char *)&hexname, a3: nullptr) )
        m_nCustomFiles->reqID = this->m_NetChannel->RequestFile(
                                  this: this->m_NetChannel,
                                  a2: (const char *)&hexname,
                                  a3: false);
    }
    ++m_nCustomFiles;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1011A3E0
// Name: public: virtual void CGameClient::Connect(char const __near *,int,class INetChannel __near *,bool,enum CrossPlayPlatform_t,class CUtlVector<struct NetMessageCvar_t,class CUtlMemory<struct NetMessageCvar_t,int>> __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameClient::Connect(
        CGameClient *this,
        const char *szName,
        int nUserID,
        INetChannel *pNetChannel,
        bool bFakePlayer,
        float clientPlatform,
        CUtlVector<NetMessageCvar_t,CUtlMemory<NetMessageCvar_t,int> > *pVecCvars)
{
  CClientFrame *v8; // eax
  IGameEvent *v9; // esi
  IGameEvent_vtbl *v10; // ebx
  int ClientXuid; // eax
  int v12; // edx
  IGameEvent_vtbl *v13; // ebx
  int v14; // eax
  int m_nFilesDownloaded; // ecx
  const char *v16; // eax

  CBaseClient::Connect(this, szName, nUserID, pNetChannel, bFakePlayer, clientPlatform, pVecCvars);
  v8 = (CClientFrame *)EDICT_NUM(n: this->m_nClientSlot);
  this->m_nSoundSequence = (int)v8;
  this->m_pCurrentFrame = v8;
  *(_DWORD *)&this->m_PackInfo.m_PVS[8188] = 0x2000;
  v9 = g_GameEventManager->CreateEventA(this: g_GameEventManager, a2: "player_connect", a3: 0, a4: 0);
  v9->SetInt(this: v9, a2: "userid", a3: this->m_nEntityIndex);
  v9->SetInt(this: v9, a2: "index", a3: *(_DWORD *)&this->m_bSplitPlayerDisconnecting);
  v9->SetString(this: v9, a2: "name", a3: (const char *)&this->m_UserID);
  v10 = v9->__vftable;
  ClientXuid = CBaseClient::GetClientXuid(this: (CGameClient *)((char *)this - 4));
  ((void (__thiscall *)(IGameEvent *, const char *, int, int))v10->SetUint64)(
    a1: v9,
    a2: "xuid",
    a3: ClientXuid,
    a4: v12);
  v13 = v9->__vftable;
  v14 = ((int (__thiscall *)(CGameClient *))this->PerformDisconnection)(a1: this);
  v13->SetString(this: v9, a2: "networkid", a3: (const char *)v14);
  m_nFilesDownloaded = this->m_nFilesDownloaded;
  if ( m_nFilesDownloaded != 0 )
    v16 = (const char *)(*(int (__thiscall **)(int))(*(_DWORD *)m_nFilesDownloaded + 4))(a1: m_nFilesDownloaded);
  else
    v16 = "none";
  v9->SetString(this: v9, a2: "address", a3: v16);
  v9->SetInt(this: v9, a2: "bot", a3: LOBYTE(this->m_nForceWaitForTick) != 0);
  g_GameEventManager->FireEvent(this: g_GameEventManager, a2: v9, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x1011A500
// Name: public: void CGameClient::SetupPrevPackInfo(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameClient::SetupPrevPackInfo(CGameClient *this)
{
  int m_AreasNetworked; // eax
  int m_nMapAreas; // eax
  int m_nPVSSize; // [esp-10h] [ebp-1Ch]

  m_AreasNetworked = this->m_PackInfo.m_AreasNetworked;
  qmemcpy(&this->m_PrevTransmitEdict, this->m_PackInfo.m_pTransmitEdict, sizeof(this->m_PrevTransmitEdict));
  this->m_PrevPackInfo.m_AreasNetworked = m_AreasNetworked;
  memcpy(
    dst: (unsigned __int8 *)this->m_PrevPackInfo.m_Areas,
    src: (unsigned __int8 *)this->m_PackInfo.m_Areas,
    count: 4 * m_AreasNetworked);
  m_nPVSSize = this->m_PackInfo.m_nPVSSize;
  this->m_PrevPackInfo.m_nPVSSize = m_nPVSSize;
  memcpy(dst: this->m_PrevPackInfo.m_PVS, src: this->m_PackInfo.m_PVS, count: m_nPVSSize);
  m_nMapAreas = this->m_PackInfo.m_nMapAreas;
  this->m_PrevPackInfo.m_nMapAreas = m_nMapAreas;
  memcpy(dst: this->m_PrevPackInfo.m_AreaFloodNums, src: this->m_PackInfo.m_AreaFloodNums, count: 4 * m_nMapAreas);
}

//------------------------------------------------------------------------------
// Address: 0x1011A590
// Name: public: virtual void CGameClient::UpdateUserSettings(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameClient::UpdateUserSettings(CGameClient *this)
{
  this->m_bVoiceLoopback = KeyValues::GetInt(this: this->m_ConVars, keyName: "voice_loopback", defaultValue: 0) != 0;
  CBaseClient::UpdateUserSettings(this);
  g_pServerPluginHandler->ClientSettingsChanged(this: g_pServerPluginHandler, a2: this->edict);
}

//------------------------------------------------------------------------------
// Address: 0x1011A5D0
// Name: public: virtual void CGameClient::Reconnect(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameClient::Reconnect(CGameClient *this)
{
  CGameServer::RemoveClientFromGame(this: &sv, client: (CGameClient *)((char *)this - 4));
  CBaseClient::Reconnect(this);
}

//------------------------------------------------------------------------------
// Address: 0x1011A5F0
// Name: public: virtual bool CGameClient::CheckConnect(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CGameClient::CheckConnect(CGameClient *this)
{
  CServerPlugin_vtbl *v2; // ebx
  int v3; // eax
  char szRejectReason[128]; // [esp+Ch] [ebp-80h] BYREF

  V_strncpy(pDest: szRejectReason, pSrc: "Connection rejected by game\n", maxLen: 128);
  v2 = g_pServerPluginHandler->__vftable;
  v3 = (*(int (__thiscall **)(int, char *, int))(*(_DWORD *)this->m_nFilesDownloaded + 4))(
         a1: this->m_nFilesDownloaded,
         a2: szRejectReason,
         a3: 128);
  if ( ((unsigned __int8 (__thiscall *)(CServerPlugin *, int, int *, int))v2->ClientConnect)(
         a1: g_pServerPluginHandler,
         a2: this->m_nSoundSequence,
         a3: &this->m_UserID,
         a4: v3) != 0 )
    return CBaseServer::ShouldUpdateMasterServer((vgui::Splitter *)this);
  ((void (__cdecl *)(CGameClient *, char *, int *))this->SendSignonData)(
    a1: this,
    a2: szRejectReason,
    a3: &this->m_UserID);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1011A680
// Name: public: virtual void CGameClient::ActivatePlayer(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameClient::ActivatePlayer(CGameClient *this)
{
  IGameEvent *v2; // edi
  int v3; // eax
  IGameEvent v4; // [esp+Ch] [ebp-4h]

  CBaseClient::ActivatePlayer(this);
  _COM_TimestampedLog(a1: "CGameClient::ActivatePlayer -start");
  if ( !sv.m_bLoadgame )
  {
    g_ServerGlobalVariables.curtime = CBaseServer::GetTime(this: &sv);
    _COM_TimestampedLog(a1: "g_pServerPluginHandler->ClientPutInServer");
    g_pServerPluginHandler->ClientPutInServer(this: g_pServerPluginHandler, a2: this->edict, a3: this->m_Name);
  }
  _COM_TimestampedLog(a1: "g_pServerPluginHandler->ClientActive");
  g_pServerPluginHandler->ClientActive(this: g_pServerPluginHandler, a2: this->edict, a3: sv.m_bLoadgame);
  _COM_TimestampedLog(a1: "g_pServerPluginHandler->ClientSettingsChanged");
  g_pServerPluginHandler->ClientSettingsChanged(this: g_pServerPluginHandler, a2: this->edict);
  _COM_TimestampedLog(a1: "GetTestScriptMgr()->CheckPoint");
  CTestScriptMgr::CheckPoint(this: &g_TestScriptMgr, pName: "client_connected");
  v2 = g_GameEventManager->CreateEventA(this: g_GameEventManager, a2: "player_activate", a3: 0, a4: 0);
  if ( v2 != nullptr )
  {
    v4.__vftable = v2->__vftable;
    v3 = this->GetUserID(this: &this->IClient);
    v4.SetInt(this: v2, a2: "userid", a3: v3);
    g_GameEventManager->FireEvent(this: g_GameEventManager, a2: v2, a3: false);
  }
  _COM_TimestampedLog(a1: "CGameClient::ActivatePlayer -end");
  this->m_flTimeClientBecameFullyConnected = realtime;
}

//------------------------------------------------------------------------------
// Address: 0x1011A7B0
// Name: public: virtual bool CGameClient::SendNetMsg(class INetMessage __near &,bool,bool)
// Source: json
//------------------------------------------------------------------------------
char __userpurge CGameClient::SendNetMsg@<al>(
        CGameClient *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>,
        INetMessage *msg,
        int bForceReliable,
        int bVoice)
{
  if ( LOBYTE(this->m_Server) != 0 )
    return CHLTVServer::SendNetMsg(this: hltv, msg, bForceReliable, bVoice);
  else
    return CBaseClient::SendNetMsg(this, a2, a3, msg, bForceReliable, bVoice);
}

//------------------------------------------------------------------------------
// Address: 0x1011A7D0
// Name: public: virtual void CGameClient::FileReceived(char const __near *,unsigned int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameClient::FileReceived(
        CGameClient *this,
        const char *fileName,
        unsigned int transferID,
        bool bIsReplayDemoFile)
{
  int v4; // eax
  CBaseClient::CustomFile_s *i; // edx

  v4 = 0;
  for ( i = this->m_nCustomFiles; i->crc != transferID; ++i )
  {
    if ( ++v4 >= 4 )
    {
      _Msg(a1: "CGameClient::FileReceived: %s not wanted.\n", fileName);
      return;
    }
  }
  ++this->m_nCustomFiles[3].reqID;
  (*(void (__thiscall **)(_DWORD, _DWORD))(**(_DWORD **)&this->m_bConVarsChanged + 192))(
    a1: *(_DWORD *)&this->m_bConVarsChanged,
    a2: *(_DWORD *)&this->m_bSplitPlayerDisconnecting);
}

//------------------------------------------------------------------------------
// Address: 0x1011A830
// Name: public: virtual void CGameClient::FileDenied(char const __near *,unsigned int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameClient::FileDenied(
        CGameClient *this,
        const char *fileName,
        unsigned int transferID,
        bool bIsReplayDemoFile)
{
  const char *v4; // eax

  v4 = (const char *)((int (__thiscall *)(CGameClient *))this->SetUserCVar)(a1: this);
  ConMsg(a1: "Downloading file '%s' from client %s failed.\n", fileName, v4);
}

//------------------------------------------------------------------------------
// Address: 0x1011A860
// Name: public: virtual void CGameClient::FileSent(char const __near *,unsigned int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameClient::FileSent(
        CGameClient *this,
        const char *fileName,
        unsigned int transferID,
        bool bIsReplayDemoFile)
{
  const char *v4; // eax

  v4 = (const char *)((int (__thiscall *)(CGameClient *))this->SetUserCVar)(a1: this);
  ConMsg(a1: "Sent file '%s' to client %s.\n", fileName, v4);
}

//------------------------------------------------------------------------------
// Address: 0x1011A890
// Name: public: virtual void CGameClient::PacketStart(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameClient::PacketStart(CGameClient *this, int incoming_sequence, int outgoing_acknowledged)
{
  int v3; // edi
  CBaseClient **m_SplitScreenUsers; // esi
  CGameClient *v5; // [esp+4h] [ebp-4h]

  v3 = 1;
  v5 = this;
  if ( host_state.max_splitscreen_players > 1 )
  {
    m_SplitScreenUsers = this->m_SplitScreenUsers;
    do
    {
      if ( *m_SplitScreenUsers != nullptr )
      {
        (*m_SplitScreenUsers)->PacketStart(
          this: &(*m_SplitScreenUsers)->IClient,
          a2: incoming_sequence,
          a3: outgoing_acknowledged);
        this = v5;
      }
      ++v3;
      ++m_SplitScreenUsers;
    }
    while ( v3 < host_state.max_splitscreen_players );
  }
  this->m_VoiceProximity.m_Ints[1] = sv.m_nTickCount - 1;
  host_client = (CGameClient *)((char *)this - 4);
  BYTE1(this->m_nForceWaitForTick) = 1;
}

//------------------------------------------------------------------------------
// Address: 0x1011A900
// Name: public: virtual void CGameClient::PacketEnd(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameClient::PacketEnd(CGameClient *this)
{
  g_ServerGlobalVariables.frametime = host_state.interval_per_tick;
}

//------------------------------------------------------------------------------
// Address: 0x1011A920
// Name: public: virtual void CGameClient::ConnectionClosing(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameClient::ConnectionClosing(CGameClient *this, const char *reason)
{
  const char *v3; // eax

  SV_RedirectEnd();
  v3 = reason;
  if ( reason == nullptr )
    v3 = "Connection closing";
  ((void (__cdecl *)(CGameClient *, const char *))this->SendSignonData)(a1: this, a2: v3);
}

//------------------------------------------------------------------------------
// Address: 0x1011A950
// Name: public: virtual void CGameClient::ConnectionCrashed(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameClient::ConnectionCrashed(CGameClient *this, const char *reason)
{
  const char *v3; // eax

  if ( LOBYTE(this->m_UserID) != 0
    && ((unsigned __int8 (__thiscall *)(CGameClient *))this->CBaseClient::IGameEventListener2::__vftable[1].WriteGameSounds)(a1: this) != 0 )
  {
    SV_RedirectEnd();
    v3 = reason;
    if ( reason == nullptr )
      v3 = "Connection lost";
    ((void (__cdecl *)(CGameClient *, const char *))this->SendSignonData)(a1: this, a2: v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1011A990
// Name: public: virtual bool CGameClient::IgnoreTempEntity(class CEventInfo __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CGameClient::IgnoreTempEntity(CGameClient *this, CEventInfo *event)
{
  return !this->m_bIsInReplayMode && CBaseClient::IgnoreTempEntity(this, event);
}

//------------------------------------------------------------------------------
// Address: 0x1011A9B0
// Name: public: class CCheckTransmitInfo const __near * CGameClient::GetPrevPackInfo(void)
// Source: json
//------------------------------------------------------------------------------
const CCheckTransmitInfo *__thiscall CGameClient::GetPrevPackInfo(CGameClient *this)
{
  return &this->m_PrevPackInfo;
}

//------------------------------------------------------------------------------
// Address: 0x1011A9C0
// Name: public: virtual bool CBaseServer::IsPaused(void)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CBaseServer::IsPaused(CBaseServer *this)
{
  return this->m_State == ss_paused;
}

//------------------------------------------------------------------------------
// Address: 0x1011A9D0
// Name: public: virtual bool CBaseServer::IsMultiplayer(void)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CBaseServer::IsMultiplayer(CBaseServer *this)
{
  return this->m_nMaxclients > 1;
}

//------------------------------------------------------------------------------
// Address: 0x1011A9E0
// Name: int ClampClientRate(int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ClampClientRate(int nRate)
{
  int m_nValue; // ecx
  int result; // eax
  int v3; // ecx

  if ( sv_maxrate.m_pParent != nullptr && (m_nValue = sv_maxrate.m_pParent->m_Value.m_nValue) > 0 )
  {
    result = nRate;
    if ( nRate >= m_nValue )
      result = sv_maxrate.m_pParent->m_Value.m_nValue;
  }
  else
  {
    result = nRate;
  }
  if ( sv_minrate.m_pParent != nullptr )
  {
    v3 = sv_minrate.m_pParent->m_Value.m_nValue;
    if ( v3 > 0 && result <= v3 )
      result = sv_minrate.m_pParent->m_Value.m_nValue;
  }
  if ( result < 1000 )
    return 1000;
  if ( result > 30000 )
    return 30000;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1011AA40
// Name: public: virtual bool CGameClient::ProcessMove(class CLC_Move __near *)
// Source: json
//------------------------------------------------------------------------------
char __userpurge CGameClient::ProcessMove@<al>(CGameClient *this@<ecx>, int a2@<ebx>, int a3@<edi>, CLC_Move *msg)
{
  CBaseClient *BaseUserForSplitClient; // eax
  int v8; // edi
  const unsigned int *m_pData; // eax
  int m_nDataBits; // ecx
  const unsigned int *v11; // eax
  int netdrop; // [esp+8h] [ebp-10h]
  char *v16; // [esp+10h] [ebp-8h]
  int startbit; // [esp+20h] [ebp+8h]

  v16 = (char *)this - 4;
  if ( (*(unsigned __int8 (**)(void))(*((_DWORD *)this - 1) + 132))() == 0
    || this->m_VoiceProximity.m_Ints[0] == sv.m_nTickCount )
  {
    return 1;
  }
  this->m_VoiceProximity.m_Ints[0] = sv.m_nTickCount;
  BaseUserForSplitClient = CBaseServer::GetBaseUserForSplitClient(
                             this: &sv,
                             pSplitUser: (CGameClient *)((char *)this - 8));
  v8 = msg->m_nNewCommands + msg->m_nBackupCommands;
  netdrop = ((int (__thiscall *)(INetChannel *, int, int))BaseUserForSplitClient->m_NetChannel->GetDropNumber)(
              a1: BaseUserForSplitClient->m_NetChannel,
              a2: a3,
              a3: a2);
  if ( sv.m_State != ss_paused && sv.m_nMaxclients <= 1 )
    Con_IsVisible();
  g_ServerGlobalVariables.curtime = CBaseServer::GetTime(this: &sv);
  g_ServerGlobalVariables.frametime = host_state.interval_per_tick;
  m_pData = msg->m_DataIn.m_pData;
  if ( m_pData != nullptr )
  {
    m_nDataBits = msg->m_DataIn.m_nDataBits;
    startbit = 32 * (msg->m_DataIn.m_pDataIn - m_pData)
             - msg->m_DataIn.m_nBitsAvail
             + 8 * (msg->m_DataIn.m_nDataBytes & 3);
    if ( startbit >= m_nDataBits )
      startbit = m_nDataBits;
  }
  else
  {
    startbit = 0;
  }
  ((void (__thiscall *)(IServerGameClients *, int, bf_read *, int, int, int))serverGameClients->ProcessUsercmds)(
    a1: serverGameClients,
    a2: this->m_LastMovementTick,
    a3: &msg->m_DataIn,
    a4: msg->m_nNewCommands,
    a5: v8,
    a6: netdrop);
  if ( msg->m_DataIn.m_bOverflow )
  {
    (*(void (__cdecl **)(char *, const char *))(*(_DWORD *)v16 + 52))(
      a1: v16,
      a2: "ProcessUsercmds:  Overflowed reading usercmd data (check sending and receiving code for mismatches)!\n");
    return 0;
  }
  else
  {
    v11 = msg->m_DataIn.m_pData;
    if ( v11 != nullptr )
    {
      v11 = (const unsigned int *)(32 * (msg->m_DataIn.m_pDataIn - v11)
                                 - msg->m_DataIn.m_nBitsAvail
                                 + 8 * (msg->m_DataIn.m_nDataBytes & 3));
      if ( (int)v11 >= msg->m_DataIn.m_nDataBits )
        v11 = (const unsigned int *)msg->m_DataIn.m_nDataBits;
    }
    if ( (const unsigned int *)msg->m_nLength == (const unsigned int *)((char *)v11 - startbit) )
    {
      return 1;
    }
    else
    {
      (*(void (__cdecl **)(char *, const char *))(*(_DWORD *)v16 + 52))(
        a1: v16,
        a2: "ProcessUsercmds:  Incorrect reading frame (check sending and receiving code for mismatches)!\n");
      return 0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1011ABE0
// Name: public: virtual bool CGameClient::ProcessFileCRCCheck(class CLC_FileCRCCheck __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CGameClient::ProcessFileCRCCheck(CGameClient *this, CLC_FileCRCCheck *msg)
{
  char *m_szFilename; // esi
  char *m_szPathID; // edi
  EFileCRCStatus v4; // eax
  char *v6; // esi
  const char *v7; // eax
  const char *v8; // eax
  const char *v9; // [esp-14h] [ebp-41Ch]
  const char *v10; // [esp-10h] [ebp-418h]
  const char *v11; // [esp-10h] [ebp-418h]
  char warningStr[1024]; // [esp+0h] [ebp-408h] BYREF
  unsigned int fileCRC; // [esp+400h] [ebp-8h] BYREF
  CGameClient *v14; // [esp+404h] [ebp-4h]

  v14 = this;
  if ( CGameServer::IsInPureServerMode(this: &sv) )
  {
    memset(warningStr, 0, sizeof(warningStr));
    m_szFilename = msg->m_szFilename;
    m_szPathID = msg->m_szPathID;
    v4 = g_pFileSystem->CheckCachedFileCRC(
           this: g_pFileSystem,
           a2: msg->m_szPathID,
           a3: msg->m_szFilename,
           a4: &fileCRC);
    if ( v4 != k_eFileCRCStatus_CantOpenFile )
    {
      if ( v4 == k_eFileCRCStatus_GotCRC && fileCRC != msg->m_CRC )
        V_snprintf(
          pDest: warningStr,
          maxLen: 1024,
          pFormat: "Pure server: file [%s]\\%s does not match the server's file.",
          m_szPathID,
          m_szFilename);
    }
    else
    {
      V_snprintf(
        pDest: warningStr,
        maxLen: 1024,
        pFormat: "Pure server: client has loaded extra file [%s]\\%s. File must be removed to play on this server.",
        m_szPathID,
        m_szFilename);
    }
    if ( warningStr[0] != 0 )
    {
      if ( sv_pure_kick_clients.m_pParent != nullptr && sv_pure_kick_clients.m_pParent->m_Value.m_nValue != 0 )
      {
        (*(void (**)(float *, const char *, ...))(*((_DWORD *)&v14[-1].m_flTimeClientBecameFullyConnected + 1) + 52))(
          a1: &v14[-1].m_flTimeClientBecameFullyConnected + 1,
          a2: "%s",
          warningStr);
        return 1;
      }
      v6 = (char *)(&v14[-1].m_flTimeClientBecameFullyConnected + 1);
      (*(void (**)(float *, const char *, ...))(*((_DWORD *)&v14[-1].m_flTimeClientBecameFullyConnected + 1) + 120))(
        a1: &v14[-1].m_flTimeClientBecameFullyConnected + 1,
        a2: "Warning: %s\n",
        warningStr);
      if ( sv_pure_trace.m_pParent != nullptr && sv_pure_trace.m_pParent->m_Value.m_nValue >= 1 )
      {
        v7 = (const char *)(*(int (__thiscall **)(char *, char *))(*(_DWORD *)v6 + 84))(a1: v6, a2: warningStr);
        _Msg(a1: "[%s] %s\n", v7, v10);
        return 1;
      }
    }
    else if ( sv_pure_trace.m_pParent != nullptr && sv_pure_trace.m_pParent->m_Value.m_nValue >= 2 )
    {
      v8 = (const char *)(*(int (__thiscall **)(float *, char *, char *))(*((_DWORD *)&v14[-1].m_flTimeClientBecameFullyConnected
                                                                          + 1)
                                                                        + 68))(
                           a1: &v14[-1].m_flTimeClientBecameFullyConnected + 1,
                           a2: m_szPathID,
                           a3: m_szFilename);
      _Msg(a1: "Pure server CRC check: client %s passed check for [%s]\\%s\n", v8, v9, v11);
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1011AD60
// Name: public: virtual void CGameClient::SetRate(int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameClient::SetRate(CGameClient *this, int nRate, bool bForce)
{
  int v3; // eax
  CGameClient *v4; // edx

  v3 = nRate;
  v4 = this;
  if ( !bForce )
    v3 = ClampClientRate(nRate);
  CBaseClient::SetRate(this: v4, nRate: v3, bForce);
}

//------------------------------------------------------------------------------
// Address: 0x1011AD90
// Name: public: virtual void CGameClient::SetUpdateRate(int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameClient::SetUpdateRate(CGameClient *this, int udpaterate, bool bForce)
{
  int m_nValue; // eax
  int v4; // edx

  if ( bForce )
  {
    m_nValue = udpaterate;
  }
  else
  {
    if ( sv_maxupdaterate.m_pParent != nullptr && (m_nValue = sv_maxupdaterate.m_pParent->m_Value.m_nValue) > 0 )
    {
      if ( udpaterate >= 1 )
      {
        if ( udpaterate <= m_nValue )
          m_nValue = udpaterate;
      }
      else
      {
        m_nValue = 1;
      }
    }
    else
    {
      m_nValue = udpaterate;
    }
    if ( sv_minupdaterate.m_pParent != nullptr )
    {
      v4 = sv_minupdaterate.m_pParent->m_Value.m_nValue;
      if ( v4 > 0 )
      {
        if ( m_nValue < v4 )
        {
          CBaseClient::SetUpdateRate(this, udpaterate: v4, bForce: false);
          return;
        }
        if ( m_nValue > 100 )
        {
          CBaseClient::SetUpdateRate(this, udpaterate: 100, bForce: false);
          return;
        }
      }
    }
  }
  CBaseClient::SetUpdateRate(this, udpaterate: m_nValue, bForce);
}

//------------------------------------------------------------------------------
// Address: 0x1011AE10
// Name: public: virtual bool CGameClient::UpdateAcknowledgedFramecount(int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CGameClient::UpdateAcknowledgedFramecount(CGameClient *this, int tick)
{
  int v4; // eax
  float m_fValue; // [esp+8h] [ebp-4h]
  float ticka; // [esp+14h] [ebp+8h]

  if ( tick != this->m_nDeltaTick )
  {
    v4 = tick;
    if ( sv_maxreplay.m_pParent->m_Value.m_fValue > 0.0 )
    {
      ticka = (float)tick;
      m_fValue = sv_maxreplay.m_pParent->m_Value.m_fValue;
      v4 = (int)(ticka
               - m_fValue / ((double (__thiscall *)(CBaseServer *))this->m_Server->GetTickInterval)(a1: this->m_Server));
    }
    if ( v4 > 0 )
      CClientFrameManager::DeleteClientFrames(this: &this->CClientFrameManager, nTick: v4);
  }
  return CBaseClient::UpdateAcknowledgedFramecount(this, tick);
}

//------------------------------------------------------------------------------
// Address: 0x1011AE90
// Name: public: virtual void CGameClient::Disconnect(char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
void CGameClient::Disconnect(CGameClient *this, const char *fmt, ...)
{
  char reason[1024]; // [esp+4h] [ebp-400h] BYREF
  va_list params; // [esp+414h] [ebp+10h] BYREF

  va_start(params, fmt);
  if ( this->m_NetChannel != nullptr )
  {
    V_vsnprintf(pDest: reason, maxLen: 1024, pFormat: fmt, params);
    CBaseClient::Disconnect(a1: (int)this, this, fmt: "%s", reason);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1011AEE0
// Name: public: virtual bool CGameClient::ProcessSignonStateMsg(int,int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CGameClient::ProcessSignonStateMsg(CGameClient *this, int state, int spawncount)
{
  bool result; // al
  int v5; // [esp+18h] [ebp+8h]

  if ( state == 2 )
  {
    result = this->CheckConnect(this: &this->IClient);
    if ( result )
    {
      v5 = 1133903872;
      if ( sv.m_bIsDedicatedForXbox )
        v5 = 1117126656;
      ((void (__stdcall *)(int, _DWORD))this->m_NetChannel->SetTimeout)(a1: v5, a2: 0);
      this->m_NetChannel->SetFileTransmissionMode(this: this->m_NetChannel, a2: false);
      this->m_NetChannel->SetMaxBufferSize(this: this->m_NetChannel, a2: true, a3: 96000, a4: false);
      return CBaseClient::ProcessSignonStateMsg(this, state: 2, spawncount);
    }
  }
  else
  {
    if ( state == 3 )
    {
      if ( sv.m_nMaxclients <= 1 )
      {
        SV_InstallClientStringTableMirrors();
        return CBaseClient::ProcessSignonStateMsg(this, state: 3, spawncount);
      }
    }
    else if ( state == 6 )
    {
      if ( sv.m_bLoadgame )
        CGameServer::FinishRestore(this: &sv);
      ((void (__stdcall *)(_DWORD, _DWORD))this->m_NetChannel->SetTimeout)(
        a1: sv_timeout.m_pParent->m_Value.m_fValue,
        a2: 0);
      this->m_NetChannel->SetFileTransmissionMode(this: this->m_NetChannel, a2: true);
      g_pServerPluginHandler->ClientFullyConnect(this: g_pServerPluginHandler, a2: this->edict);
    }
    return CBaseClient::ProcessSignonStateMsg(this, state, spawncount);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1011B020
// Name: private: bool CGameClient::IsEngineClientCommand(class CCommand const __near &)const
// Source: json
//------------------------------------------------------------------------------
char __thiscall CGameClient::IsEngineClientCommand(CGameClient *this, const CCommand *args)
{
  int v3; // esi
  const char **v4; // eax
  const char *v5; // eax
  const char *v6; // [esp-8h] [ebp-Ch]

  if ( args->m_nArgc == 0 )
    return 0;
  v3 = 0;
  if ( s_clcommands[0] == nullptr )
    return 0;
  v4 = s_clcommands;
  while ( 1 )
  {
    v6 = *v4;
    v5 = CCommand::operator[](this: args, nIndex: 0);
    if ( V_strcasecmp(s1: v5, s2: v6) == 0 )
      break;
    v4 = &s_clcommands[++v3];
    if ( *v4 == nullptr )
      return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1011B080
// Name: public: void SoundInfo_t::WriteDelta(struct SoundInfo_t __near *,class bf_write __near &,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SoundInfo_t::WriteDelta(
        SoundInfo_t *this,
        SoundInfo_t *delta,
        SoundInfo_t *buffer,
        float finalTickTime)
{
  SoundInfo_t *v4; // eax
  bool v5; // zf
  int x_low; // ecx
  int v8; // edx
  int v9; // ecx
  int v10; // edx
  int v11; // ecx
  int v12; // edx
  int v13; // ecx
  int v14; // edx
  int v15; // ecx
  int v16; // eax
  SoundInfo_t *v17; // eax
  int v18; // ecx
  BOOL bIsAmbient; // edx
  int v20; // edi
  char v21; // cl
  BOOL bIsSentence; // edi
  int v23; // ecx
  int v24; // eax
  char v25; // cl
  unsigned __int8 *v26; // edi
  int nSequenceNumber; // eax
  int v28; // ecx
  int v29; // ecx
  int v30; // ecx
  int v31; // ecx
  int v32; // ecx
  int v33; // edx
  int v34; // ecx
  int v35; // eax
  int v36; // ecx
  int v37; // edx
  int v38; // ecx
  int v39; // eax
  float fDelay; // xmm1_4
  float fTickTime; // xmm0_4
  int v42; // ecx
  int v43; // eax
  int v44; // ecx
  int v45; // edx
  int v46; // ecx
  int v47; // edx
  int v48; // ecx
  int v49; // edx
  int v50; // ecx
  int v51; // eax
  SoundInfo_t *v52; // [esp+18h] [ebp-4h]
  SoundInfo_t *deltaa; // [esp+28h] [ebp+Ch]

  v4 = this;
  v5 = this->nEntityIndex == delta->nEntityIndex;
  x_low = LODWORD(buffer->vDirection.x);
  v52 = v4;
  v8 = x_low + 1;
  if ( v5 )
  {
    if ( v8 > SLODWORD(buffer->vOrigin.z) )
      LOBYTE(buffer->vDirection.y) = 1;
    if ( LOBYTE(buffer->vDirection.y) == 0 )
    {
      *(_BYTE *)((x_low >> 3) + LODWORD(buffer->vOrigin.x)) &= ~(1 << (x_low & 7));
      ++LODWORD(buffer->vDirection.x);
    }
  }
  else
  {
    if ( v8 > SLODWORD(buffer->vOrigin.z) )
      LOBYTE(buffer->vDirection.y) = 1;
    if ( LOBYTE(buffer->vDirection.y) == 0 )
    {
      *(_BYTE *)((x_low >> 3) + LODWORD(buffer->vOrigin.x)) |= 1 << (x_low & 7);
      ++LODWORD(buffer->vDirection.x);
    }
    v9 = LODWORD(buffer->vDirection.x);
    v10 = v9 + 1;
    if ( v4->nEntityIndex > 31 )
    {
      if ( v10 > SLODWORD(buffer->vOrigin.z) )
        LOBYTE(buffer->vDirection.y) = 1;
      if ( LOBYTE(buffer->vDirection.y) == 0 )
      {
        *(_BYTE *)((v9 >> 3) + LODWORD(buffer->vOrigin.x)) &= ~(1 << (v9 & 7));
        ++LODWORD(buffer->vDirection.x);
      }
      bf_write::WriteUBitLong(this: (bf_write *)buffer, curData: v4->nEntityIndex, numbits: 11, bCheckRange: true);
    }
    else
    {
      if ( v10 > SLODWORD(buffer->vOrigin.z) )
        LOBYTE(buffer->vDirection.y) = 1;
      if ( LOBYTE(buffer->vDirection.y) == 0 )
      {
        *(_BYTE *)((v9 >> 3) + LODWORD(buffer->vOrigin.x)) |= 1 << (v9 & 7);
        ++LODWORD(buffer->vDirection.x);
      }
      bf_write::WriteUBitLong(this: (bf_write *)buffer, curData: v4->nEntityIndex, numbits: 5, bCheckRange: true);
    }
    v4 = v52;
  }
  v11 = LODWORD(buffer->vDirection.x);
  v12 = v11 + 1;
  if ( v4->nSoundNum == delta->nSoundNum )
  {
    if ( v12 > SLODWORD(buffer->vOrigin.z) )
      LOBYTE(buffer->vDirection.y) = 1;
    if ( LOBYTE(buffer->vDirection.y) == 0 )
    {
      *(_BYTE *)((v11 >> 3) + LODWORD(buffer->vOrigin.x)) &= ~(1 << (v11 & 7));
      ++LODWORD(buffer->vDirection.x);
    }
  }
  else
  {
    if ( v12 > SLODWORD(buffer->vOrigin.z) )
      LOBYTE(buffer->vDirection.y) = 1;
    if ( LOBYTE(buffer->vDirection.y) == 0 )
    {
      *(_BYTE *)((v11 >> 3) + LODWORD(buffer->vOrigin.x)) |= 1 << (v11 & 7);
      ++LODWORD(buffer->vDirection.x);
      v4 = v52;
    }
    bf_write::WriteUBitLong(this: (bf_write *)buffer, curData: v4->nSoundNum, numbits: 13, bCheckRange: true);
  }
  v13 = LODWORD(buffer->vDirection.x);
  v14 = v13 + 1;
  if ( v52->nFlags == delta->nFlags )
  {
    if ( v14 > SLODWORD(buffer->vOrigin.z) )
      LOBYTE(buffer->vDirection.y) = 1;
    if ( LOBYTE(buffer->vDirection.y) == 0 )
    {
      *(_BYTE *)((v13 >> 3) + LODWORD(buffer->vOrigin.x)) &= ~(1 << (v13 & 7));
      ++LODWORD(buffer->vDirection.x);
    }
  }
  else
  {
    if ( v14 > SLODWORD(buffer->vOrigin.z) )
      LOBYTE(buffer->vDirection.y) = 1;
    if ( LOBYTE(buffer->vDirection.y) == 0 )
    {
      *(_BYTE *)((v13 >> 3) + LODWORD(buffer->vOrigin.x)) |= 1 << (v13 & 7);
      ++LODWORD(buffer->vDirection.x);
    }
    bf_write::WriteUBitLong(this: (bf_write *)buffer, curData: v52->nFlags, numbits: 13, bCheckRange: true);
  }
  v15 = LODWORD(buffer->vDirection.x);
  v16 = v15 + 1;
  if ( v52->nChannel == delta->nChannel )
  {
    if ( v16 > SLODWORD(buffer->vOrigin.z) )
      LOBYTE(buffer->vDirection.y) = 1;
    if ( LOBYTE(buffer->vDirection.y) == 0 )
    {
      *(_BYTE *)((v15 >> 3) + LODWORD(buffer->vOrigin.x)) &= ~(1 << (v15 & 7));
      ++LODWORD(buffer->vDirection.x);
    }
  }
  else
  {
    if ( v16 > SLODWORD(buffer->vOrigin.z) )
      LOBYTE(buffer->vDirection.y) = 1;
    if ( LOBYTE(buffer->vDirection.y) == 0 )
    {
      *(_BYTE *)((v15 >> 3) + LODWORD(buffer->vOrigin.x)) |= 1 << (v15 & 7);
      ++LODWORD(buffer->vDirection.x);
    }
    bf_write::WriteUBitLong(this: (bf_write *)buffer, curData: v52->nChannel, numbits: 3, bCheckRange: true);
  }
  v17 = v52;
  v18 = LODWORD(buffer->vDirection.x);
  bIsAmbient = v52->bIsAmbient;
  if ( v18 + 1 > SLODWORD(buffer->vOrigin.z) )
    LOBYTE(buffer->vDirection.y) = 1;
  if ( LOBYTE(buffer->vDirection.y) == 0 )
  {
    v20 = v18 >> 3;
    v21 = v18 & 7;
    if ( bIsAmbient )
      *(_BYTE *)(v20 + LODWORD(buffer->vOrigin.x)) |= 1 << v21;
    else
      *(_BYTE *)(v20 + LODWORD(buffer->vOrigin.x)) &= ~(1 << v21);
    ++LODWORD(buffer->vDirection.x);
    v17 = v52;
  }
  bIsSentence = v17->bIsSentence;
  v23 = LODWORD(buffer->vDirection.x);
  if ( v23 + 1 > SLODWORD(buffer->vOrigin.z) )
    LOBYTE(buffer->vDirection.y) = 1;
  if ( LOBYTE(buffer->vDirection.y) == 0 )
  {
    v24 = v23 >> 3;
    v25 = v23 & 7;
    v5 = !bIsSentence;
    v26 = (unsigned __int8 *)LODWORD(buffer->vOrigin.x);
    if ( v5 )
      v26[v24] &= ~(1 << v25);
    else
      v26[v24] |= 1 << v25;
    ++LODWORD(buffer->vDirection.x);
    v17 = v52;
  }
  if ( v17->nFlags == 4 )
  {
    v17->fVolume = 0.0;
    v17->Soundlevel = SNDLVL_NONE;
    v17->nPitch = 100;
    v17->pszName = nullptr;
    v17->fDelay = 0.0;
    v17->nSequenceNumber = 0;
    v17->vOrigin.x = 0.0;
    v17->vOrigin.y = 0.0;
    v17->vOrigin.z = 0.0;
    v17->nSpeakerEntity = -1;
  }
  else
  {
    nSequenceNumber = v17->nSequenceNumber;
    v28 = delta->nSequenceNumber;
    if ( nSequenceNumber == v28 )
    {
      v29 = LODWORD(buffer->vDirection.x);
      if ( v29 + 1 > SLODWORD(buffer->vOrigin.z) )
        LOBYTE(buffer->vDirection.y) = 1;
      if ( LOBYTE(buffer->vDirection.y) == 0 )
      {
        *(_BYTE *)((v29 >> 3) + LODWORD(buffer->vOrigin.x)) |= 1 << (v29 & 7);
        ++LODWORD(buffer->vDirection.x);
      }
    }
    else if ( nSequenceNumber == v28 + 1 )
    {
      v30 = LODWORD(buffer->vDirection.x);
      if ( v30 + 1 > SLODWORD(buffer->vOrigin.z) )
        LOBYTE(buffer->vDirection.y) = 1;
      if ( LOBYTE(buffer->vDirection.y) == 0 )
      {
        *(_BYTE *)((v30 >> 3) + LODWORD(buffer->vOrigin.x)) &= ~(1 << (v30 & 7));
        ++LODWORD(buffer->vDirection.x);
      }
      v31 = LODWORD(buffer->vDirection.x);
      if ( v31 + 1 > SLODWORD(buffer->vOrigin.z) )
        LOBYTE(buffer->vDirection.y) = 1;
      if ( LOBYTE(buffer->vDirection.y) == 0 )
      {
        *(_BYTE *)((v31 >> 3) + LODWORD(buffer->vOrigin.x)) |= 1 << (v31 & 7);
        ++LODWORD(buffer->vDirection.x);
      }
    }
    else
    {
      bf_write::WriteUBitLong(this: (bf_write *)buffer, curData: 0, numbits: 2, bCheckRange: true);
      bf_write::WriteUBitLong(this: (bf_write *)buffer, curData: v52->nSequenceNumber, numbits: 10, bCheckRange: true);
    }
    v32 = LODWORD(buffer->vDirection.x);
    v33 = v32 + 1;
    if ( v52->fVolume == delta->fVolume )
    {
      if ( v33 > SLODWORD(buffer->vOrigin.z) )
        LOBYTE(buffer->vDirection.y) = 1;
      if ( LOBYTE(buffer->vDirection.y) == 0 )
      {
        *(_BYTE *)((v32 >> 3) + LODWORD(buffer->vOrigin.x)) &= ~(1 << (v32 & 7));
        ++LODWORD(buffer->vDirection.x);
      }
    }
    else
    {
      if ( v33 > SLODWORD(buffer->vOrigin.z) )
        LOBYTE(buffer->vDirection.y) = 1;
      if ( LOBYTE(buffer->vDirection.y) == 0 )
      {
        *(_BYTE *)((v32 >> 3) + LODWORD(buffer->vOrigin.x)) |= 1 << (v32 & 7);
        ++LODWORD(buffer->vDirection.x);
      }
      bf_write::WriteUBitLong(
        this: (bf_write *)buffer,
        curData: (__int64)(v52->fVolume * 127.0),
        numbits: 7,
        bCheckRange: true);
    }
    v34 = LODWORD(buffer->vDirection.x);
    v35 = v34 + 1;
    if ( v52->Soundlevel == delta->Soundlevel )
    {
      if ( v35 > SLODWORD(buffer->vOrigin.z) )
        LOBYTE(buffer->vDirection.y) = 1;
      if ( LOBYTE(buffer->vDirection.y) == 0 )
      {
        *(_BYTE *)((v34 >> 3) + LODWORD(buffer->vOrigin.x)) &= ~(1 << (v34 & 7));
        ++LODWORD(buffer->vDirection.x);
      }
    }
    else
    {
      if ( v35 > SLODWORD(buffer->vOrigin.z) )
        LOBYTE(buffer->vDirection.y) = 1;
      if ( LOBYTE(buffer->vDirection.y) == 0 )
      {
        *(_BYTE *)((v34 >> 3) + LODWORD(buffer->vOrigin.x)) |= 1 << (v34 & 7);
        ++LODWORD(buffer->vDirection.x);
      }
      bf_write::WriteUBitLong(this: (bf_write *)buffer, curData: v52->Soundlevel, numbits: 9, bCheckRange: true);
    }
    v36 = LODWORD(buffer->vDirection.x);
    v37 = v36 + 1;
    if ( v52->nPitch == delta->nPitch )
    {
      if ( v37 > SLODWORD(buffer->vOrigin.z) )
        LOBYTE(buffer->vDirection.y) = 1;
      if ( LOBYTE(buffer->vDirection.y) == 0 )
      {
        *(_BYTE *)((v36 >> 3) + LODWORD(buffer->vOrigin.x)) &= ~(1 << (v36 & 7));
        ++LODWORD(buffer->vDirection.x);
      }
    }
    else
    {
      if ( v37 > SLODWORD(buffer->vOrigin.z) )
        LOBYTE(buffer->vDirection.y) = 1;
      if ( LOBYTE(buffer->vDirection.y) == 0 )
      {
        *(_BYTE *)((v36 >> 3) + LODWORD(buffer->vOrigin.x)) |= 1 << (v36 & 7);
        ++LODWORD(buffer->vDirection.x);
      }
      bf_write::WriteUBitLong(this: (bf_write *)buffer, curData: v52->nPitch, numbits: 8, bCheckRange: true);
    }
    v38 = LODWORD(buffer->vDirection.x);
    v39 = v38 + 1;
    if ( v52->nRandomSeed == delta->nRandomSeed )
    {
      if ( v39 > SLODWORD(buffer->vOrigin.z) )
        LOBYTE(buffer->vDirection.y) = 1;
      if ( LOBYTE(buffer->vDirection.y) == 0 )
      {
        *(_BYTE *)((v38 >> 3) + LODWORD(buffer->vOrigin.x)) &= ~(1 << (v38 & 7));
        ++LODWORD(buffer->vDirection.x);
      }
    }
    else
    {
      if ( v39 > SLODWORD(buffer->vOrigin.z) )
        LOBYTE(buffer->vDirection.y) = 1;
      if ( LOBYTE(buffer->vDirection.y) == 0 )
      {
        *(_BYTE *)((v38 >> 3) + LODWORD(buffer->vOrigin.x)) |= 1 << (v38 & 7);
        ++LODWORD(buffer->vDirection.x);
      }
      bf_write::WriteUBitLong(this: (bf_write *)buffer, curData: v52->nRandomSeed, numbits: 6, bCheckRange: true);
    }
    fDelay = v52->fDelay;
    deltaa = (SoundInfo_t *)LODWORD(fDelay);
    if ( (v52->nFlags & 0x10) != 0 )
    {
      fTickTime = v52->fTickTime;
      if ( fTickTime != finalTickTime )
      {
        fDelay = fDelay + (float)(fTickTime - finalTickTime);
        deltaa = (SoundInfo_t *)LODWORD(fDelay);
      }
    }
    v42 = LODWORD(buffer->vDirection.x);
    v43 = v42 + 1;
    if ( fDelay == delta->fDelay )
    {
      if ( v43 > SLODWORD(buffer->vOrigin.z) )
        LOBYTE(buffer->vDirection.y) = 1;
      if ( LOBYTE(buffer->vDirection.y) == 0 )
      {
        *(_BYTE *)((v42 >> 3) + LODWORD(buffer->vOrigin.x)) &= ~(1 << (v42 & 7));
        ++LODWORD(buffer->vDirection.x);
      }
    }
    else
    {
      if ( v43 > SLODWORD(buffer->vOrigin.z) )
        LOBYTE(buffer->vDirection.y) = 1;
      if ( LOBYTE(buffer->vDirection.y) == 0 )
      {
        *(_BYTE *)((v42 >> 3) + LODWORD(buffer->vOrigin.x)) |= 1 << (v42 & 7);
        ++LODWORD(buffer->vDirection.x);
      }
      bf_write::WriteFloat(this: (bf_write *)buffer, val: *(float *)&deltaa);
    }
    v44 = LODWORD(buffer->vDirection.x);
    v45 = v44 + 1;
    if ( v52->vOrigin.x == delta->vOrigin.x )
    {
      if ( v45 > SLODWORD(buffer->vOrigin.z) )
        LOBYTE(buffer->vDirection.y) = 1;
      if ( LOBYTE(buffer->vDirection.y) == 0 )
      {
        *(_BYTE *)((v44 >> 3) + LODWORD(buffer->vOrigin.x)) &= ~(1 << (v44 & 7));
        ++LODWORD(buffer->vDirection.x);
      }
    }
    else
    {
      if ( v45 > SLODWORD(buffer->vOrigin.z) )
        LOBYTE(buffer->vDirection.y) = 1;
      if ( LOBYTE(buffer->vDirection.y) == 0 )
      {
        *(_BYTE *)((v44 >> 3) + LODWORD(buffer->vOrigin.x)) |= 1 << (v44 & 7);
        ++LODWORD(buffer->vDirection.x);
      }
      bf_write::WriteSBitLong(this: (bf_write *)buffer, data: (int)(float)(v52->vOrigin.x * 0.125), numbits: 12);
    }
    v46 = LODWORD(buffer->vDirection.x);
    v47 = v46 + 1;
    if ( v52->vOrigin.y == delta->vOrigin.y )
    {
      if ( v47 > SLODWORD(buffer->vOrigin.z) )
        LOBYTE(buffer->vDirection.y) = 1;
      if ( LOBYTE(buffer->vDirection.y) == 0 )
      {
        *(_BYTE *)((v46 >> 3) + LODWORD(buffer->vOrigin.x)) &= ~(1 << (v46 & 7));
        ++LODWORD(buffer->vDirection.x);
      }
    }
    else
    {
      if ( v47 > SLODWORD(buffer->vOrigin.z) )
        LOBYTE(buffer->vDirection.y) = 1;
      if ( LOBYTE(buffer->vDirection.y) == 0 )
      {
        *(_BYTE *)((v46 >> 3) + LODWORD(buffer->vOrigin.x)) |= 1 << (v46 & 7);
        ++LODWORD(buffer->vDirection.x);
      }
      bf_write::WriteSBitLong(this: (bf_write *)buffer, data: (int)(float)(v52->vOrigin.y * 0.125), numbits: 12);
    }
    v48 = LODWORD(buffer->vDirection.x);
    v49 = v48 + 1;
    if ( v52->vOrigin.z == delta->vOrigin.z )
    {
      if ( v49 > SLODWORD(buffer->vOrigin.z) )
        LOBYTE(buffer->vDirection.y) = 1;
      if ( LOBYTE(buffer->vDirection.y) == 0 )
      {
        *(_BYTE *)((v48 >> 3) + LODWORD(buffer->vOrigin.x)) &= ~(1 << (v48 & 7));
        ++LODWORD(buffer->vDirection.x);
      }
    }
    else
    {
      if ( v49 > SLODWORD(buffer->vOrigin.z) )
        LOBYTE(buffer->vDirection.y) = 1;
      if ( LOBYTE(buffer->vDirection.y) == 0 )
      {
        *(_BYTE *)((v48 >> 3) + LODWORD(buffer->vOrigin.x)) |= 1 << (v48 & 7);
        ++LODWORD(buffer->vDirection.x);
      }
      bf_write::WriteSBitLong(this: (bf_write *)buffer, data: (int)(float)(v52->vOrigin.z * 0.125), numbits: 12);
    }
    v50 = LODWORD(buffer->vDirection.x);
    v51 = v50 + 1;
    if ( v52->nSpeakerEntity == delta->nSpeakerEntity )
    {
      if ( v51 > SLODWORD(buffer->vOrigin.z) )
        LOBYTE(buffer->vDirection.y) = 1;
      if ( LOBYTE(buffer->vDirection.y) == 0 )
      {
        *(_BYTE *)((v50 >> 3) + LODWORD(buffer->vOrigin.x)) &= ~(1 << (v50 & 7));
        ++LODWORD(buffer->vDirection.x);
      }
    }
    else
    {
      if ( v51 > SLODWORD(buffer->vOrigin.z) )
        LOBYTE(buffer->vDirection.y) = 1;
      if ( LOBYTE(buffer->vDirection.y) == 0 )
      {
        *(_BYTE *)((v50 >> 3) + LODWORD(buffer->vOrigin.x)) |= 1 << (v50 & 7);
        ++LODWORD(buffer->vDirection.x);
      }
      bf_write::WriteSBitLong(this: (bf_write *)buffer, data: v52->nSpeakerEntity, numbits: 12);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1011B8B0
// Name: public: virtual bool CGameClient::ProcessClientInfo(class CLC_ClientInfo __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CGameClient::ProcessClientInfo(CGameClient *this, CLC_ClientInfo *msg)
{
  CBaseClient::ProcessClientInfo(this, msg);
  if ( this->m_bConVarsChanged )
  {
    (*(void (__cdecl **)(char *, const char *))(*((_DWORD *)this - 1) + 52))(
      a1: (char *)this - 4,
      a2: "ProcessClientInfo: SourceTV can not connect to game directly.\n");
    return 0;
  }
  else
  {
    if ( sv_allowupload.m_pParent != nullptr && sv_allowupload.m_pParent->m_Value.m_nValue != 0 )
      CGameClient::DownloadCustomizations(this: (CGameClient *)((char *)this - 8));
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1011B910
// Name: public: void CGameClient::WriteViewAngleUpdate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameClient::WriteViewAngleUpdate(CGameClient *this)
{
  CPlayerState *v2; // eax
  float *v3; // esi
  int v4; // eax
  float v5; // edx
  float v6; // eax
  INetChannel *m_NetChannel; // ecx
  float v8; // ecx
  float v9; // edx
  float v10; // xmm0_4
  INetChannel *v11; // ecx
  SVC_FixAngle fixAngle; // [esp+8h] [ebp-2Ch] BYREF
  float v13; // [esp+28h] [ebp-Ch]
  float v14; // [esp+2Ch] [ebp-8h]
  float v15; // [esp+30h] [ebp-4h]

  if ( !this->IsFakeClient(this: &this->IClient) || this->IsSplitScreenUser(this: &this->IClient) )
  {
    v2 = serverGameClients->GetPlayerState(this: serverGameClients, a2: this->edict);
    v3 = (float *)v2;
    if ( v2 != nullptr )
    {
      v4 = v2->fixangle;
      if ( v4 != 0 )
      {
        fixAngle.m_NetChannel = nullptr;
        fixAngle.__vftable = (SVC_FixAngle_vtbl *)&SVC_FixAngle::`vftable';
        fixAngle.m_bReliable = false;
        if ( v4 == 2 )
        {
          v5 = v3[8];
          v6 = v3[9];
          v13 = v3[7];
          m_NetChannel = this->m_NetChannel;
          v14 = v5;
          fixAngle.m_Angle.x = v13;
          v15 = v6;
          fixAngle.m_Angle.y = v5;
          fixAngle.m_bRelative = true;
          fixAngle.m_Angle.z = v6;
          m_NetChannel->SendNetMsg(this: m_NetChannel, a2: &fixAngle, a3: false, a4: false);
          v3[7] = 0.0;
          v3[8] = 0.0;
          v3[9] = 0.0;
        }
        else
        {
          v8 = v3[3];
          v9 = v3[4];
          v13 = v3[2];
          fixAngle.m_Angle.x = v13;
          v14 = v8;
          v10 = v8;
          v11 = this->m_NetChannel;
          v15 = v9;
          fixAngle.m_Angle.y = v10;
          fixAngle.m_bRelative = false;
          fixAngle.m_Angle.z = v9;
          v11->SendNetMsg(this: v11, a2: &fixAngle, a3: false, a4: false);
        }
        v3[6] = 0.0;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1011BA40
// Name: public: virtual bool CGameClient::ExecuteStringCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CGameClient::ExecuteStringCommand(CGameClient *this, char *pCommandString)
{
  const char *v4; // eax
  ConCommandBase *v5; // eax
  const ConCommandBase *v6; // esi
  CCommand args; // [esp+8h] [ebp-508h] BYREF

  if ( !CBaseClient::ExecuteStringCommand(this, pCommand: pCommandString) )
  {
    CCommand::CCommand(this: &args);
    if ( CCommand::Tokenize(this: &args, pCommand: pCommandString, pBreakSet: nullptr) == 0 || args.m_nArgc == 0 )
      return 0;
    if ( CGameClient::IsEngineClientCommand(this: (CGameClient *)((char *)this - 4), &args) )
    {
      Cmd_ExecuteCommand(
        eTarget: CBUF_SERVER,
        command: &args,
        src: src_client,
        nClientSlot: *(_DWORD *)&this->m_bSplitPlayerDisconnecting);
      return 1;
    }
    v4 = defaultValue;
    if ( args.m_nArgc > 0 )
      v4 = args.m_ppArgv[0];
    v5 = g_pCVar->FindCommandBase_2(this: g_pCVar, a2: v4);
    v6 = v5;
    if ( v5 != nullptr && v5->IsCommand(this: v5) && v6->IsFlagSet(this: (ConCommandBase *)v6, a2: 4) )
    {
      if ( (!v6->IsFlagSet(this: (ConCommandBase *)v6, a2: 0x4000)
         || sv.m_nMaxclients <= 1
         || sv_cheats.m_pParent != nullptr && sv_cheats.m_pParent->m_Value.m_nValue != 0
         || Cmd_IsRptActive())
        && (!v6->IsFlagSet(this: (ConCommandBase *)v6, a2: 64) || sv.m_nMaxclients <= 1) )
      {
        g_pServerPluginHandler->SetCommandClient(
          this: g_pServerPluginHandler,
          a2: *(_DWORD *)&this->m_bSplitPlayerDisconnecting);
        Cmd_Dispatch(pCommand: v6, command: &args);
        return 1;
      }
      return 0;
    }
    g_pServerPluginHandler->ClientCommand_2(
      this: g_pServerPluginHandler,
      a2: (edict_t *)this->m_nSoundSequence,
      a3: &args);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1011BBC0
// Name: public: virtual bool CGameClient::ShouldSendMessages(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CGameClient::ShouldSendMessages(CGameClient *this)
{
  float m_fValue; // [esp+4h] [ebp-4h]

  if ( !this->m_bIsHLTV )
    return (!this->IsFakeClient(this: &this->IClient)
         || sv_stressbots.m_pParent != nullptr && sv_stressbots.m_pParent->m_Value.m_nValue != 0)
        && CBaseClient::ShouldSendMessages(this);
  m_fValue = tv_snapshotrate.m_pParent->m_Value.m_fValue;
  return sv.m_nTickCount >= (int)(1.0
                                / (((double (__thiscall *)(CBaseServer *))this->m_Server->GetTickInterval)(a1: this->m_Server)
                                 * m_fValue))
                          + hltv->m_nLastTick;
}

//------------------------------------------------------------------------------
// Address: 0x1011BC50
// Name: public: virtual void CGameClient::FileRequested(char const __near *,unsigned int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameClient::FileRequested(
        CGameClient *this,
        const char *fileName,
        unsigned int transferID,
        int bIsReplayDemoFile)
{
  const char *v5; // eax

  v5 = (const char *)(*(int (__thiscall **)(int))(*(_DWORD *)this->m_nFilesDownloaded + 4))(a1: this->m_nFilesDownloaded);
  DevMsg(a1: "File '%s' requested from client %s.\n", fileName, v5);
  if ( sv_allowdownload.m_pParent != nullptr && sv_allowdownload.m_pParent->m_Value.m_nValue != 0 )
    (*(void (__thiscall **)(int, const char *, unsigned int, int))(*(_DWORD *)this->m_nFilesDownloaded + 172))(
      a1: this->m_nFilesDownloaded,
      a2: fileName,
      a3: transferID,
      a4: bIsReplayDemoFile);
  else
    (*(void (__thiscall **)(int, const char *, unsigned int, int))(*(_DWORD *)this->m_nFilesDownloaded + 176))(
      a1: this->m_nFilesDownloaded,
      a2: fileName,
      a3: transferID,
      a4: bIsReplayDemoFile);
}

//------------------------------------------------------------------------------
// Address: 0x1011BCD0
// Name: public: virtual bool CGameClient::ProcessCmdKeyValues(class CLC_CmdKeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CGameClient::ProcessCmdKeyValues(CGameClient *this, CLC_CmdKeyValues *msg)
{
  KeyValues *v3; // eax
  KeyValues *v4; // esi
  KeyValues *Copy; // eax
  IMatchEventsSubscription *v6; // eax

  serverGameClients->ClientCommandKeyValues(
    this: serverGameClients,
    a2: (edict_t *)this->m_LastMovementTick,
    a3: msg->m_pKeyValues);
  v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v3 != nullptr )
    v4 = KeyValues::KeyValues(this: v3, setName: "Server::CmdKeyValues");
  else
    v4 = nullptr;
  Copy = KeyValues::MakeCopy(this: msg->m_pKeyValues);
  KeyValues::AddSubKey(this: v4, pSubkey: Copy);
  KeyValues::SetPtr(this: v4, keyName: "edict", value: (void *)this->m_LastMovementTick);
  v6 = g_pMatchFramework->GetEventsSubscription(this: g_pMatchFramework);
  v6->BroadcastEvent(this: v6, a2: v4);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1011BD60
// Name: public: virtual bool CGameClient::IsHearingClient(int)const
// Source: json
//------------------------------------------------------------------------------
char __thiscall CGameClient::IsHearingClient(CGameClient *this, int index)
{
  CBaseClient *v4; // edi
  unsigned int v5; // eax

  if ( this->CBaseClient::IGameEventListener2::__vftable[1].SendSignonData(this) )
    return 1;
  if ( index == ((int (__thiscall *)(CGameClient *))this->SpawnPlayer)(a1: this) )
    return this->m_ClientFramePool.m_BlobHead.m_Data[0];
  v4 = sv.m_Clients.m_Memory.m_pMemory[index];
  if ( (ss_voice_hearpartner.m_pParent == nullptr || ss_voice_hearpartner.m_pParent->m_Value.m_nValue == 0)
    && CBaseClient::IsSplitScreenPartner(
         this: (CGameClient *)((char *)this - 4),
         pOther: sv.m_Clients.m_Memory.m_pMemory[index]) )
  {
    return 0;
  }
  v5 = ((int (__thiscall *)(CGameClient *))this->SpawnPlayer)(a1: this);
  return (*(_DWORD *)&v4[1].m_Name[4 * (v5 >> 5) + 8] & (1 << (v5 & 0x1F))) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x1011BDF0
// Name: public: virtual bool CGameClient::IsProximityHearingClient(int)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CGameClient::IsProximityHearingClient(CGameClient *this, int index)
{
  CBaseClient *v2; // esi
  unsigned int v3; // eax

  v2 = sv.m_Clients.m_Memory.m_pMemory[index];
  v3 = ((int (__thiscall *)(CGameClient *))this->SpawnPlayer)(a1: this);
  return (*(_DWORD *)&v2[1].m_Name[4 * (v3 >> 5) + 16] & (1 << (v3 & 0x1F))) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x1011BE30
// Name: protected: virtual void CGameClient::PerformDisconnection(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameClient::PerformDisconnection(CGameClient *this, const char *pReason)
{
  IGameEvent *v3; // eax
  IGameEvent *v4; // esi
  int v5; // eax
  const char *v6; // eax
  int ClientXuid; // eax
  int v8; // edx
  const char *v9; // eax
  IGameEvent_vtbl *v10; // [esp+8h] [ebp-4h]
  IGameEvent_vtbl *v11; // [esp+8h] [ebp-4h]
  IGameEvent_vtbl *v12; // [esp+8h] [ebp-4h]
  IGameEvent_vtbl *v13; // [esp+8h] [ebp-4h]

  v3 = g_GameEventManager->CreateEventA(this: g_GameEventManager, a2: "player_disconnect", a3: 0, a4: 0);
  v4 = v3;
  if ( v3 != nullptr )
  {
    v10 = v3->__vftable;
    v5 = this->GetUserID(this: &this->IClient);
    v10->SetInt(this: v4, a2: "userid", a3: v5);
    v4->SetString(this: v4, a2: "reason", a3: pReason);
    v11 = v4->__vftable;
    v6 = this->GetClientName(this: &this->IClient);
    v11->SetString(this: v4, a2: "name", a3: v6);
    v12 = v4->__vftable;
    ClientXuid = CBaseClient::GetClientXuid(this);
    ((void (__thiscall *)(IGameEvent *, const char *, int, int))v12->SetUint64)(
      a1: v4,
      a2: "xuid",
      a3: ClientXuid,
      a4: v8);
    v13 = v4->__vftable;
    v9 = this->GetNetworkIDString(this: &this->IClient);
    v13->SetString(this: v4, a2: "networkid", a3: v9);
    g_GameEventManager->FireEvent(this: g_GameEventManager, a2: v4, a3: false);
  }
  this->m_Server->RemoveClientFromGame(this: this->m_Server, a2: this);
  CBaseClient::PerformDisconnection(this, pReason);
}

//------------------------------------------------------------------------------
// Address: 0x1011BF20
// Name: private: int CGameClient::FillSoundsMessage(class SVC_Sounds __near &,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CGameClient::FillSoundsMessage(CGameClient *this, SoundInfo_t *msg, int nMaxSounds)
{
  int m_Size; // ebx
  int result; // eax
  SVC_Sounds *v6; // edi
  SVC_Sounds_vtbl *x_low; // edx
  void (__thiscall *SetReliable)(struct SVC_Sounds *, bool); // eax
  SoundInfo_t *m_pMemory; // eax
  int v10; // edi
  SoundInfo_t *v11; // edx
  bool v12; // zf
  int v13; // eax
  int v14; // edi
  _DWORD v15[3]; // [esp+10h] [ebp-68h] BYREF
  SoundInfo_t defaultSound; // [esp+1Ch] [ebp-5Ch] BYREF

  m_Size = this->m_Sounds.m_Size;
  if ( m_Size > nMaxSounds )
    m_Size = nMaxSounds;
  result = 0;
  if ( m_Size != 0 )
  {
    v6 = (SVC_Sounds *)msg;
    x_low = (SVC_Sounds_vtbl *)LODWORD(msg->vOrigin.x);
    defaultSound.fDelay = 0.0;
    defaultSound.nChannel = 0;
    defaultSound.nEntityIndex = 0;
    defaultSound.fVolume = 0.0;
    defaultSound.nFlags = 0;
    defaultSound.vListenerOrigin.x = 0.0;
    BYTE2(defaultSound.nSpeakerEntity) = 0;
    LOWORD(defaultSound.nSpeakerEntity) = 0;
    *(_DWORD *)&defaultSound.bIsSentence = v15;
    LOBYTE(msg->vDirection.y) = 0;
    SetReliable = x_low->SetReliable;
    defaultSound.vListenerOrigin.z = 0.0;
    defaultSound.pszName = nullptr;
    defaultSound.vListenerOrigin.y = 1.0;
    defaultSound.nSoundNum = 75;
    defaultSound.nSequenceNumber = 100;
    defaultSound.nPitch = -1;
    LODWORD(defaultSound.fTickTime) = 6;
    memset(v15, 0, sizeof(v15));
    memset(&defaultSound, 0, 24);
    LODWORD(msg->vDirection.z) = m_Size;
    SetReliable(this: (struct SVC_Sounds *)msg, a2: false);
    *(float *)&defaultSound.nRandomSeed = CBaseServer::GetFinalTickTime(this: this->m_Server);
    if ( m_Size > 0 )
    {
      m_pMemory = this->m_Sounds.m_Memory.m_pMemory;
      v10 = 0;
      defaultSound.Soundlevel = m_Size;
      do
      {
        SoundInfo_t::WriteDelta(
          this: &m_pMemory[v10],
          delta: *(SoundInfo_t **)&defaultSound.bIsSentence,
          buffer: (bf_write *)&msg->nPitch,
          finalTickTime: *(float *)&defaultSound.nRandomSeed);
        m_pMemory = this->m_Sounds.m_Memory.m_pMemory;
        v11 = &m_pMemory[v10++];
        v12 = defaultSound.Soundlevel-- == 1;
        *(_DWORD *)&defaultSound.bIsSentence = v11;
      }
      while ( !v12 );
      v6 = (SVC_Sounds *)msg;
    }
    if ( sv_sound_discardextraunreliable.m_pParent != nullptr
      && sv_sound_discardextraunreliable.m_pParent->m_Value.m_nValue != 0 )
    {
      v13 = this->m_Sounds.m_Size;
      if ( v13 != m_Size )
        _DevMsg(a1: 2, a2: "Warning! Dropped %i unreliable sounds for client %s.\n", v13 - m_Size, this->m_Name);
      this->m_Sounds.m_Size = 0;
      return v6->m_nNumSounds;
    }
    else
    {
      v14 = this->m_Sounds.m_Size - m_Size - nMaxSounds;
      if ( v14 > 0 )
      {
        _DevMsg(a1: 2, a2: "Warning! Dropped %i unreliable sounds for client %s.\n", v14, this->m_Name);
        m_Size += v14;
      }
      if ( m_Size > 0 )
      {
        if ( this->m_Sounds.m_Size - m_Size > 0 )
          _V_memmove(
            dest: this->m_Sounds.m_Memory.m_pMemory,
            src: &this->m_Sounds.m_Memory.m_pMemory[m_Size],
            count: 92 * (this->m_Sounds.m_Size - m_Size));
        this->m_Sounds.m_Size -= m_Size;
      }
      return LODWORD(msg->vDirection.z);
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1011C0E0
// Name: public: virtual void CGameClient::SpawnPlayer(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameClient::SpawnPlayer(CGameClient *this)
{
  bool (__thiscall *SendNetMsg)(IClient *, INetMessage *, bool, bool); // edx
  int v3; // eax
  SVC_SetView setView; // [esp+4h] [ebp-14h] BYREF

  if ( sv.m_bLoadgame )
  {
    CBaseServer::SetPaused(this: &sv, paused: false);
  }
  else
  {
    serverGameEnts->FreeContainingEntity(this: serverGameEnts, a2: this->edict);
    InitializeEntityDLLFields(pEdict: this->edict);
  }
  SendNetMsg = this->SendNetMsg;
  v3 = this->m_nClientSlot + 1;
  this->m_nEntityIndex = v3;
  setView.m_nEntityIndex = v3;
  this->m_bIsInReplayMode = false;
  setView.m_bReliable = true;
  setView.m_NetChannel = nullptr;
  setView.__vftable = (SVC_SetView_vtbl *)&SVC_SetView::`vftable';
  SendNetMsg(this: &this->IClient, a2: &setView, a3: false, a4: false);
  CBaseClient::SpawnPlayer(this);
}

//------------------------------------------------------------------------------
// Address: 0x1011C170
// Name: public: virtual class CClientFrame __near * CGameClient::GetDeltaFrame(int)
// Source: json
//------------------------------------------------------------------------------
CClientFrame *__thiscall CGameClient::GetDeltaFrame(CGameClient *this, int nTick)
{
  CBaseClient *v3; // eax
  int followEntity; // [esp+4h] [ebp-4h] BYREF

  if ( this->m_bIsInReplayMode
    && (serverGameClients->GetReplayDelay(this: serverGameClients, a2: this->edict, a3: &followEntity),
        (v3 = sv.m_Clients.m_Memory.m_pMemory[followEntity - 1]) != nullptr) )
  {
    return CClientFrameManager::GetClientFrame(this: (CClientFrameManager *)&v3[1], nTick, bExact: true);
  }
  else
  {
    return CClientFrameManager::GetClientFrame(this: &this->CClientFrameManager, nTick, bExact: true);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1011C1E0
// Name: public: virtual void CGameClient::SendSnapshot(class CClientFrame __near *)
// Source: json
//------------------------------------------------------------------------------
// bad sp value at call has been detected, the output may be wrong!
void __thiscall CGameClient::SendSnapshot(CGameClient *this, CClientFrame *pFrame)
{
  int v3; // eax
  void *v4; // esp
  int m_nValue; // eax
  int v6; // eax
  CBaseServer_vtbl *v7; // ebx
  CBaseServer *v8; // edi
  bf_write *Buffer; // eax
  CFrameSnapshot *v10; // edi
  CFrameSnapshot *v11; // ecx
  int v12; // [esp-17694h] [ebp-17700h]
  _DWORD v13[23975]; // [esp-17690h] [ebp-176FCh] BYREF
  SVC_Sounds sounds; // [esp+Ch] [ebp-60h] BYREF
  CFrameSnapshot *m_pSnapshot; // [esp+64h] [ebp-8h]
  CFrameSnapshot *m_pObj; // [esp+68h] [ebp-4h]
  int savedregs; // [esp+6Ch] [ebp+0h]

  if ( this->m_bIsHLTV )
  {
    v3 = ((int (__thiscall *)(IClient *, _DWORD, _DWORD, _DWORD, SVC_Sounds_vtbl *, _DWORD, INetChannel *, IServerMessageHandler *, _DWORD, int, int, const char *, _DWORD, int, unsigned int, unsigned int, int, const unsigned int *, const unsigned int *, const unsigned int *, unsigned __int8 *, int, int, int, _DWORD, const char *, CFrameSnapshot *, CFrameSnapshot *, int))this->GetMaxAckTickCount)(
           a1: &this->IClient,
           a2: v13[23972],
           a3: v13[23973],
           a4: v13[23974],
           a5: sounds.__vftable,
           a6: *(_DWORD *)&sounds.m_bReliable,
           a7: sounds.m_NetChannel,
           a8: sounds.m_pMessageHandler,
           a9: *(_DWORD *)&sounds.m_bReliableSound,
           a10: sounds.m_nNumSounds,
           a11: sounds.m_nLength,
           a12: sounds.m_DataIn.m_pDebugName,
           a13: *(_DWORD *)&sounds.m_DataIn.m_bOverflow,
           a14: sounds.m_DataIn.m_nDataBits,
           a15: sounds.m_DataIn.m_nDataBytes,
           a16: sounds.m_DataIn.m_nInBufWord,
           a17: sounds.m_DataIn.m_nBitsAvail,
           a18: sounds.m_DataIn.m_pDataIn,
           a19: sounds.m_DataIn.m_pBufferEnd,
           a20: sounds.m_DataIn.m_pData,
           a21: sounds.m_DataOut.m_pData,
           a22: sounds.m_DataOut.m_nDataBytes,
           a23: sounds.m_DataOut.m_nDataBits,
           a24: sounds.m_DataOut.m_iCurBit,
           a25: *(_DWORD *)&sounds.m_DataOut.m_bOverflow,
           a26: sounds.m_DataOut.m_pDebugName,
           a27: m_pSnapshot,
           a28: m_pObj,
           a29: savedregs);
    CNetworkStringTableContainer::DirectUpdate(this: networkStringTableContainerServer, tick_ack: v3);
    v4 = alloca(96000);
    if ( this->m_Sounds.m_Size > 0 )
    {
      sounds.m_bReliable = true;
      sounds.m_NetChannel = nullptr;
      sounds.__vftable = (SVC_Sounds_vtbl *)&SVC_Sounds::`vftable';
      sounds.m_DataIn.m_bOverflow = false;
      sounds.m_DataIn.m_pDebugName = nullptr;
      sounds.m_DataIn.m_nDataBits = -1;
      sounds.m_DataIn.m_nDataBytes = 0;
      bf_write::bf_write(this: &sounds.m_DataOut);
      bf_write::StartWriting(this: &sounds.m_DataOut, pData: v13, nBytes: 96000, iStartBit: 0, nBits: -1);
      if ( this->m_Server->IsMultiplayer(this: this->m_Server) )
      {
        if ( sv_multiplayer_maxsounds.m_pParent != nullptr )
          m_nValue = sv_multiplayer_maxsounds.m_pParent->m_Value.m_nValue;
        else
          m_nValue = 0;
      }
      else
      {
        m_nValue = 255;
      }
      CGameClient::FillSoundsMessage(this, msg: &sounds, nMaxSounds: m_nValue);
      CHLTVServer::SendNetMsg(this: hltv, msg: &sounds, bForceReliable: false, bVoice: false);
    }
    if ( tv_transmitall.m_pParent != nullptr )
      v6 = tv_transmitall.m_pParent->m_Value.m_nValue;
    else
      v6 = 0;
    m_pObj = this->m_pLastSnapshot.m_pObj;
    v7 = hltv->CBaseServer::IServer::IConnectionlessPacketHandler::__vftable;
    v12 = v6 != 0 ? 255 : 64;
    v8 = &hltv->CBaseServer;
    m_pSnapshot = pFrame->m_pSnapshot;
    Buffer = CHLTVServer::GetBuffer(this: hltv, nBuffer: 5);
    v7->WriteTempEntities(this: v8, a2: this, a3: m_pSnapshot, a4: m_pObj, a5: Buffer, a6: v12);
    CHLTVServer::AddNewFrame(this: hltv, clientFrame: pFrame);
    v10 = pFrame->m_pSnapshot;
    if ( v10 != this->m_pLastSnapshot.m_pObj )
    {
      if ( v10 != nullptr )
        CFrameSnapshot::AddReference(this: pFrame->m_pSnapshot);
      v11 = this->m_pLastSnapshot.m_pObj;
      if ( v11 != nullptr )
        CFrameSnapshot::ReleaseReference(this: v11);
      this->m_pLastSnapshot.m_pObj = v10;
    }
    this->UpdateAcknowledgedFramecount(this, a2: pFrame->tick_count);
  }
  else
  {
    CGameClient::WriteViewAngleUpdate(this);
    CBaseClient::SendSnapshot(this, a2: 0, pFrame);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1011C370
// Name: public: class CClientFrame __near * CGameClient::GetSendFrame(void)
// Source: json
//------------------------------------------------------------------------------
CClientFrame *__thiscall CGameClient::GetSendFrame(CGameClient *this)
{
  CClientFrame *m_pCurrentFrame; // edi
  int v3; // eax
  int v4; // edx
  CBaseClient *v5; // ecx
  int followEntity; // [esp+0h] [ebp-4h] BYREF

  followEntity = (int)this;
  m_pCurrentFrame = this->m_pCurrentFrame;
  if ( sv_maxreplay.m_pParent->m_Value.m_fValue > 0.0 )
  {
    v3 = serverGameClients->GetReplayDelay(this: serverGameClients, a2: this->edict, a3: &followEntity);
    v4 = followEntity;
    if ( v3 > 0 != this->m_bIsInReplayMode )
    {
      this->m_nDeltaTick = -1;
      this->m_bIsInReplayMode = v3 > 0;
      if ( v3 <= 0 )
      {
        this->m_nEntityIndex = this->m_nClientSlot + 1;
        return m_pCurrentFrame;
      }
      this->m_nEntityIndex = v4;
    }
    if ( v3 > 0 )
    {
      v5 = sv.m_Clients.m_Memory.m_pMemory[v4 - 1];
      if ( v5 == nullptr )
        return nullptr;
      m_pCurrentFrame = CClientFrameManager::GetClientFrame(
                          this: (CClientFrameManager *)&v5[1],
                          nTick: sv.m_nTickCount - v3,
                          bExact: false);
      if ( m_pCurrentFrame == nullptr || this->m_pLastSnapshot.m_pObj == m_pCurrentFrame->m_pSnapshot )
        return nullptr;
    }
  }
  return m_pCurrentFrame;
}

//------------------------------------------------------------------------------
// Address: 0x1011C4A0
// Name: public: void CGameClient::SetupPackInfo(class CFrameSnapshot __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameClient::SetupPackInfo(CGameClient *this, CFrameSnapshot *pSnapshot)
{
  CClientFrame *Frame; // eax
  IClient_vtbl *v4; // eax
  unsigned __int8 *v5; // eax
  CBitVec<2048> *v6; // edi
  int m_nValue; // edi
  float m_flTimeClientBecameFullyConnected; // xmm1_4
  int v9; // eax
  int i; // edx
  int m_AreasNetworked; // ecx
  int v12; // [esp-4h] [ebp-14h]
  float m_fValue; // [esp+Ch] [ebp-4h]
  float v14; // [esp+Ch] [ebp-4h]
  int nMaxFrames; // [esp+18h] [ebp+8h]
  float nMaxFramesb; // [esp+18h] [ebp+8h]
  float nMaxFramesa; // [esp+18h] [ebp+8h]
  float nMaxFramesc; // [esp+18h] [ebp+8h]

  v12 = (g_BSPData.numclusters + 7) / 8;
  this->m_PackInfo.m_nPVSSize = v12;
  serverGameClients->ClientSetupVisibility(
    this: serverGameClients,
    a2: (edict_t *)this->m_pViewEntity,
    a3: this->m_PackInfo.m_pClientEnt,
    a4: this->m_PackInfo.m_PVS,
    a5: v12);
  Frame = CClientFrameManager::AllocateFrame(this: &this->CClientFrameManager);
  this->m_pCurrentFrame = Frame;
  CClientFrame::Init(this: Frame, pSnapshot);
  v4 = this->CBaseClient::IClient::INetChannelHandler::__vftable;
  this->m_PackInfo.m_pTransmitEdict = &this->m_pCurrentFrame->transmit_entity;
  if ( v4->IsHLTV(this: &this->IClient) )
  {
    v5 = (unsigned __int8 *)MemAlloc_Alloc(nSize: 0x100u);
    v6 = (CBitVec<2048> *)v5;
    if ( v5 != nullptr )
      memset(dst: v5, value: 0, count: 0x100u);
    else
      v6 = nullptr;
    this->m_pCurrentFrame->transmit_always = v6;
    this->m_PackInfo.m_pTransmitAlways = this->m_pCurrentFrame->transmit_always;
  }
  else
  {
    this->m_PackInfo.m_pTransmitAlways = nullptr;
  }
  if ( sv_maxclientframes.m_pParent == nullptr || (m_nValue = sv_maxclientframes.m_pParent->m_Value.m_nValue) <= 128 )
    m_nValue = 128;
  m_flTimeClientBecameFullyConnected = this->m_flTimeClientBecameFullyConnected;
  nMaxFrames = m_nValue;
  if ( m_flTimeClientBecameFullyConnected != -1.0
    && sv_extra_client_connect_time.m_pParent->m_Value.m_fValue > (float)(realtime - m_flTimeClientBecameFullyConnected) )
  {
    m_fValue = sv_extra_client_connect_time.m_pParent->m_Value.m_fValue;
    if ( m_nValue <= (int)(m_fValue
                         / ((double (__thiscall *)(CBaseServer *))this->m_Server->GetTickInterval)(a1: this->m_Server)) )
    {
      nMaxFramesb = sv_extra_client_connect_time.m_pParent->m_Value.m_fValue;
      m_nValue = (int)(nMaxFramesb
                     / ((double (__thiscall *)(CBaseServer *))this->m_Server->GetTickInterval)(a1: this->m_Server));
      nMaxFrames = m_nValue;
    }
  }
  if ( sv_maxreplay.m_pParent->m_Value.m_fValue > 0.0 )
  {
    nMaxFramesa = (float)nMaxFrames;
    v14 = sv_maxreplay.m_pParent->m_Value.m_fValue;
    if ( nMaxFramesa <= v14
                      / ((double (__thiscall *)(CBaseServer *))this->m_Server->GetTickInterval)(a1: this->m_Server) )
    {
      nMaxFramesc = sv_maxreplay.m_pParent->m_Value.m_fValue;
      nMaxFramesa = nMaxFramesc
                  / ((double (__thiscall *)(CBaseServer *))this->m_Server->GetTickInterval)(a1: this->m_Server);
    }
    m_nValue = (int)nMaxFramesa;
  }
  if ( m_nValue < CClientFrameManager::AddClientFrame(this: &this->CClientFrameManager, frame: this->m_pCurrentFrame) )
    CClientFrameManager::RemoveOldestFrame(this: &this->CClientFrameManager);
  v9 = 0;
  this->m_PackInfo.m_AreasNetworked = 0;
  for ( i = g_AreasNetworked.m_Size; v9 < i; ++v9 )
  {
    m_AreasNetworked = this->m_PackInfo.m_AreasNetworked;
    if ( m_AreasNetworked >= 8 )
      break;
    this->m_PackInfo.m_Areas[m_AreasNetworked] = g_AreasNetworked.m_Memory.m_pMemory[v9];
    ++this->m_PackInfo.m_AreasNetworked;
  }
  CM_SetupAreaFloodNums(areaFloodNums: this->m_PackInfo.m_AreaFloodNums, pNumAreas: &this->m_PackInfo.m_nMapAreas);
}

//------------------------------------------------------------------------------
// Address: 0x1011C700
// Name: public: virtual void CGameClient::Inactivate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameClient::Inactivate(CGameClient *this)
{
  _DWORD *m_nSoundSequence; // eax
  bool v3; // sf
  int v4; // eax
  char *v5; // eax
  const char *v6; // eax
  const char *v7; // [esp-4h] [ebp-10h]
  ConVarRef voice_verbose; // [esp+4h] [ebp-8h] BYREF

  m_nSoundSequence = (_DWORD *)this->m_nSoundSequence;
  if ( m_nSoundSequence != nullptr && (*m_nSoundSequence & 2) == 0 )
    (*(void (__thiscall **)(_DWORD, char *))(**(_DWORD **)&this->m_bConVarsChanged + 180))(
      a1: *(_DWORD *)&this->m_bConVarsChanged,
      a2: (char *)this - 4);
  if ( this->CBaseClient::IGameEventListener2::__vftable[1].SendSignonData(this) )
    CHLTVServer::Changelevel(this: hltv);
  CBaseClient::Inactivate(this);
  v3 = this->m_Sounds.m_Memory.m_nAllocationCount < 0;
  this->m_Sounds.m_Memory.m_nGrowSize = 0;
  if ( !v3 )
  {
    if ( this->edict != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->edict);
      this->edict = nullptr;
    }
    this->m_Sounds.m_Memory.m_pMemory = nullptr;
  }
  this->m_Sounds.m_Size = (int)this->edict;
  ConVarRef::ConVarRef(this: &voice_verbose, pName: "voice_verbose");
  if ( voice_verbose.m_pConVarState->m_Value.m_nValue != 0 )
  {
    if ( ((int (__thiscall *)(CGameClient *))this->FreeBaselines)(a1: this) != 0 )
    {
      v4 = ((int (__thiscall *)(CGameClient *))this->FreeBaselines)(a1: this);
      v5 = (char *)(*(int (__thiscall **)(int))(*(_DWORD *)v4 + 4))(a1: v4);
    }
    else
    {
      v5 = &args.m_pArgvBuffer[228];
    }
    v6 = (const char *)((int (__thiscall *)(CGameClient *, char *))this->SetUserCVar)(a1: this, a2: v5);
    _Msg(a1: "* CGameClient::Inactivate:  Clearing m_VoiceStreams/m_VoiceProximity for %s (%s)\n", v6, v7);
  }
  if ( this != (CGameClient *)-120632 )
  {
    *(_DWORD *)&this->m_bVoiceLoopback = 0;
    this->m_VoiceStreams.m_Ints[0] = 0;
  }
  if ( this != (CGameClient *)-120640 )
  {
    this->m_VoiceStreams.m_Ints[1] = 0;
    this->m_VoiceProximity.m_Ints[0] = 0;
  }
  CClientFrameManager::DeleteClientFrames(this: (CClientFrameManager *)&this->m_Trace.m_Records.m_pElements, nTick: -1);
}

//------------------------------------------------------------------------------
// Address: 0x1011C830
// Name: public: virtual void CGameClient::Clear(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameClient::Clear(CGameClient *this)
{
  int v2; // eax
  char *v3; // eax
  const char *v4; // eax
  const char *v5; // [esp-4h] [ebp-14h]
  ConVarRef voice_verbose; // [esp+8h] [ebp-8h] BYREF

  if ( LOBYTE(this->m_Server) != 0 )
    hltv->Shutdown(this: &hltv->CBaseServer);
  CBaseClient::Clear(this);
  CClientFrameManager::DeleteClientFrames(this: (CClientFrameManager *)&this->m_Trace.m_Records.m_pElements, nTick: -1);
  this->m_Sounds.m_Memory.m_nGrowSize = 0;
  if ( this->m_Sounds.m_Memory.m_nAllocationCount >= 0 )
  {
    if ( this->edict != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->edict);
      this->edict = nullptr;
    }
    this->m_Sounds.m_Memory.m_pMemory = nullptr;
  }
  this->m_Sounds.m_Size = (int)this->edict;
  ConVarRef::ConVarRef(this: &voice_verbose, pName: "voice_verbose");
  if ( voice_verbose.m_pConVarState->m_Value.m_nValue != 0 )
  {
    if ( ((int (__thiscall *)(CGameClient *))this->FreeBaselines)(a1: this) != 0 )
    {
      v2 = ((int (__thiscall *)(CGameClient *))this->FreeBaselines)(a1: this);
      v3 = (char *)(*(int (__thiscall **)(int))(*(_DWORD *)v2 + 4))(a1: v2);
    }
    else
    {
      v3 = &args.m_pArgvBuffer[228];
    }
    v4 = (const char *)((int (__thiscall *)(CGameClient *, char *))this->SetUserCVar)(a1: this, a2: v3);
    _Msg(a1: "* CGameClient::Clear:  Clearing m_VoiceStreams/m_VoiceProximity for %s (%s)\n", v4, v5);
  }
  if ( this != (CGameClient *)-120632 )
  {
    *(_DWORD *)&this->m_bVoiceLoopback = 0;
    this->m_VoiceStreams.m_Ints[0] = 0;
  }
  if ( this != (CGameClient *)-120640 )
  {
    this->m_VoiceStreams.m_Ints[1] = 0;
    this->m_VoiceProximity.m_Ints[0] = 0;
  }
  this->m_nSoundSequence = 0;
  this->m_Sounds.m_pElements = nullptr;
  this->m_ClientFramePool.m_BlobHead.m_Data[0] = 0;
  this->m_VoiceProximity.m_Ints[1] = 0;
  this->m_LastMovementTick = 0;
  this->m_PrevTransmitEdict.m_Ints[63] = -1082130432;
}

//------------------------------------------------------------------------------
// Address: 0x1011C960
// Name: public: virtual void CGameClient::WriteGameSounds(class bf_write __near &,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameClient::WriteGameSounds(CGameClient *this, bf_write *buf, int nMaxSounds)
{
  int v4; // edi
  _BYTE pData[96000]; // [esp+8h] [ebp-17758h] BYREF
  SVC_Sounds msg; // [esp+17708h] [ebp-58h] BYREF

  if ( this->m_Sounds.m_Size > 0 )
  {
    msg.m_bReliable = true;
    msg.m_NetChannel = nullptr;
    msg.__vftable = (SVC_Sounds_vtbl *)&SVC_Sounds::`vftable';
    msg.m_DataIn.m_bOverflow = false;
    msg.m_DataIn.m_pDebugName = nullptr;
    msg.m_DataIn.m_nDataBits = -1;
    msg.m_DataIn.m_nDataBytes = 0;
    bf_write::bf_write(this: &msg.m_DataOut);
    bf_write::StartWriting(this: &msg.m_DataOut, pData, nBytes: 96000, iStartBit: 0, nBits: -1);
    v4 = CGameClient::FillSoundsMessage(this, &msg, nMaxSounds);
    SVC_Sounds::WriteToBuffer(this: &msg, buffer: buf);
    if ( CBaseClient::IsTracing(this) )
      CBaseClient::TraceNetworkData(this, msg: buf, fmt: "Sounds [count=%d]", v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1011CA00
// Name: public: CGameClient::CGameClient(int,class CBaseServer __near *)
// Source: json
//------------------------------------------------------------------------------
CGameClient *__thiscall CGameClient::CGameClient(CGameClient *this, int slot, CBaseServer *pServer)
{
  CBaseClient::CBaseClient(this);
  this->CClientFrameManager::__vftable = (CClientFrameManager_vtbl *)&CClientFrameManager::`vftable';
  CUtlMemoryPool::CUtlMemoryPool(
    this: &this->m_ClientFramePool,
    blockSize: 284,
    numElements: 128,
    growMode: 2,
    pszAllocOwner: nullptr,
    nAlignment: 0);
  this->m_Frames = nullptr;
  this->CBaseClient::IGameEventListener2::__vftable = (CGameClient_vtbl *)&CGameClient::`vftable'{for `IGameEventListener2'};
  this->CBaseClient::IClient::INetChannelHandler::__vftable = (IClient_vtbl *)&CGameClient::`vftable'{for `IClient'};
  this->CBaseClient::IClientMessageHandler::INetMessageHandler::__vftable = (IClientMessageHandler_vtbl *)&CGameClient::`vftable'{for `IClientMessageHandler'};
  this->CClientFrameManager::__vftable = (CClientFrameManager_vtbl *)&CGameClient::`vftable';
  if ( this != (CGameClient *)-120636 )
  {
    this->m_VoiceStreams.m_Ints[0] = 0;
    this->m_VoiceStreams.m_Ints[1] = 0;
  }
  if ( this != (CGameClient *)-120644 )
  {
    this->m_VoiceProximity.m_Ints[0] = 0;
    this->m_VoiceProximity.m_Ints[1] = 0;
  }
  this->m_Sounds.m_Memory.m_pMemory = nullptr;
  this->m_Sounds.m_Memory.m_nAllocationCount = 0;
  this->m_Sounds.m_Memory.m_nGrowSize = 0;
  this->m_Sounds.m_Size = 0;
  this->m_Sounds.m_pElements = nullptr;
  if ( this != (CGameClient *)-137704 )
    memset(dst: (unsigned __int8 *)&this->m_PrevTransmitEdict, value: 0, count: sizeof(this->m_PrevTransmitEdict));
  CGameClient::Clear(this: (CGameClient *)&this->IClient);
  this->m_nClientSlot = slot;
  this->m_nEntityIndex = slot + 1;
  this->m_Server = pServer;
  this->m_pCurrentFrame = nullptr;
  this->m_bIsInReplayMode = false;
  memset(dst: (unsigned __int8 *)&this->m_PrevPackInfo, value: 0, count: sizeof(this->m_PrevPackInfo));
  this->m_PrevPackInfo.m_pTransmitEdict = &this->m_PrevTransmitEdict;
  this->m_flTimeClientBecameFullyConnected = -1.0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1011CB40
// Name: public: virtual CGameClient::~CGameClient(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameClient::~CGameClient(CGameClient *this)
{
  this->CBaseClient::IGameEventListener2::__vftable = (CGameClient_vtbl *)&CGameClient::`vftable'{for `IGameEventListener2'};
  this->CBaseClient::IClient::INetChannelHandler::__vftable = (IClient_vtbl *)&CGameClient::`vftable'{for `IClient'};
  this->CBaseClient::IClientMessageHandler::INetMessageHandler::__vftable = (IClientMessageHandler_vtbl *)&CGameClient::`vftable'{for `IClientMessageHandler'};
  this->CClientFrameManager::__vftable = (CClientFrameManager_vtbl *)&CGameClient::`vftable';
  CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&this->m_Sounds);
  this->CClientFrameManager::__vftable = (CClientFrameManager_vtbl *)&CClientFrameManager::`vftable';
  CClientFrameManager::DeleteClientFrames(this: &this->CClientFrameManager, nTick: -1);
  CUtlMemoryPool::~CUtlMemoryPool(this: &this->m_ClientFramePool);
  CBaseClient::~CBaseClient(this);
}

//------------------------------------------------------------------------------
// Address: 0x1011CBA0
// Name: public: void CGameClient::SendSound(struct SoundInfo_t __near &,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameClient::SendSound(CGameClient *this, SoundInfo_t *sound, bool isReliable)
{
  bool (__thiscall *IsFakeClient)(IClient *); // edx
  IClient *v5; // edi
  const char *pszName; // eax
  const char *v7; // edx
  const char *v8; // ecx
  float FinalTickTime; // [esp+0h] [ebp-E8h]
  _BYTE pData[8]; // [esp+10h] [ebp-D8h] BYREF
  char buffer[32]; // [esp+18h] [ebp-D0h] BYREF
  SVC_Sounds sndmsg; // [esp+38h] [ebp-B0h] BYREF
  SoundInfo_t defaultSound; // [esp+90h] [ebp-58h] BYREF

  IsFakeClient = this->IsFakeClient;
  v5 = &this->IClient;
  defaultSound.Soundlevel = (soundlevel_t)&this->IClient;
  if ( (!IsFakeClient(this: &this->IClient) || v5->IsHLTV(this: v5) || v5->IsSplitScreenUser(this: v5))
    && !this->m_bIsInReplayMode )
  {
    if ( isReliable )
    {
      buffer[28] = 1;
      sndmsg.__vftable = nullptr;
      *(_DWORD *)&buffer[24] = &SVC_Sounds::`vftable';
      LOBYTE(sndmsg.m_nLength) = 0;
      sndmsg.m_nNumSounds = 0;
      sndmsg.m_DataIn.m_pDebugName = (const char *)-1;
      *(_DWORD *)&sndmsg.m_DataIn.m_bOverflow = 0;
      bf_write::bf_write(this: (bf_write *)&sndmsg.m_DataIn.m_pBufferEnd);
      this->m_nSoundSequence = ((unsigned __int16)this->m_nSoundSequence + 1) & 0x3FF;
      sound->nSequenceNumber = 0;
      bf_write::StartWriting(
        this: (bf_write *)&sndmsg.m_DataIn.m_pBufferEnd,
        pData,
        nBytes: 32,
        iStartBit: 0,
        nBits: -1);
      sndmsg.m_pMessageHandler = (IServerMessageHandler *)1;
      LOBYTE(sndmsg.m_NetChannel) = 1;
      memset(&defaultSound.pszName, 0, 16);
      defaultSound.vListenerOrigin.z = 1.0;
      defaultSound.nSpeakerEntity = 75;
      defaultSound.nEntityIndex = 100;
      defaultSound.nFlags = -1;
      defaultSound.nSequenceNumber = 6;
      defaultSound.nPitch = 0;
      defaultSound.nChannel = 0;
      defaultSound.nSoundNum = 0;
      BYTE2(defaultSound.nRandomSeed) = 0;
      LOWORD(defaultSound.nRandomSeed) = 0;
      *(_DWORD *)&sndmsg.m_DataOut.m_bOverflow = 0;
      sndmsg.m_DataOut.m_pDebugName = nullptr;
      memset(&defaultSound, 0, 32);
      SoundInfo_t::SetDefault(this: (SoundInfo_t *)&sndmsg.m_DataOut.m_bOverflow);
      FinalTickTime = CBaseServer::GetFinalTickTime(this: &sv);
      SoundInfo_t::WriteDelta(
        this: sound,
        delta: (SoundInfo_t *)&sndmsg.m_DataOut.m_bOverflow,
        buffer: (bf_write *)&sndmsg.m_DataIn.m_pBufferEnd,
        finalTickTime: FinalTickTime);
      if ( net_showreliablesounds.m_pParent != nullptr && net_showreliablesounds.m_pParent->m_Value.m_nValue != 0 )
      {
        if ( sound->bIsSentence )
        {
          pszName = VOX_SentenceNameFromIndex(sentencenum: sound->nSoundNum);
        }
        else if ( (sound->nFlags & 0x400) != 0 )
        {
          pszName = sound->pszName;
        }
        else
        {
          pszName = CGameServer::GetSound(this: &sv, index: sound->nSoundNum);
        }
        v7 = "sentence";
        if ( !sound->bIsSentence )
          v7 = "sound";
        v8 = " stop";
        if ( (sound->nFlags & 4) == 0 )
          v8 = defaultValue;
        _Warning(
          a1: "reliable%s %s %d/%d/%d/%s\n",
          v8,
          v7,
          sound->nEntityIndex,
          sound->nChannel,
          sound->nSoundNum,
          pszName);
      }
      (*(void (__thiscall **)(soundlevel_t, char *, int, _DWORD))(*(_DWORD *)defaultSound.Soundlevel + 116))(
        a1: defaultSound.Soundlevel,
        a2: &buffer[24],
        a3: 1,
        a4: 0);
    }
    else
    {
      sound->nSequenceNumber = this->m_nSoundSequence;
      CUtlVector<SoundInfo_t,CUtlMemory<SoundInfo_t,int>>::InsertBefore(
        this: &this->m_Sounds,
        elem: this->m_Sounds.m_Size,
        src: sound);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1011CE10
// Name: public: virtual bool CGameClient::SendSignonData(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CGameClient::SendSignonData(CGameClient *this)
{
  INetChannel *m_NetChannel; // ecx
  SVC_ClassInfo classmsg; // [esp+8h] [ebp-2Ch] BYREF

  if ( sv.m_FullSendTables.m_bOverflow )
  {
    Host_Error(error: "Send Table signon buffer overflowed %i bytes!!!\n", (sv.m_FullSendTables.m_iCurBit + 7) >> 3);
    return 0;
  }
  if ( SendTable_GetCRC() == 0 || this->m_nSendtableCRC == SendTable_GetCRC() )
  {
    m_NetChannel = this->m_NetChannel;
    classmsg.m_nNumServerClasses = this->m_Server->serverclasses;
    classmsg.m_bReliable = true;
    classmsg.m_NetChannel = nullptr;
    classmsg.__vftable = (SVC_ClassInfo_vtbl *)&SVC_ClassInfo::`vftable';
    memset(&classmsg.m_Classes, 0, sizeof(classmsg.m_Classes));
    classmsg.m_bCreateOnClient = true;
    m_NetChannel->SendNetMsg(this: m_NetChannel, a2: &classmsg, a3: false, a4: false);
    CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&classmsg.m_Classes);
  }
  else
  {
    if ( sv_sendtables.m_pParent == nullptr || sv_sendtables.m_pParent->m_Value.m_nValue == 0 )
    {
      this->Disconnect(this: &this->IClient, a2: "Server uses different class tables");
      return 0;
    }
    _ConDMsg(a1: "Client sent different SendTable CRC, sending full tables.\n");
    this->m_NetChannel->SendData(this: this->m_NetChannel, a2: &sv.m_FullSendTables, a3: true);
  }
  if ( !CBaseClient::SendSignonData(this) )
    return 0;
  this->m_nSoundSequence = 1;
  return 1;
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x1011A3B0
// Name: public: virtual bool CGameClient::ProcessRespondCvarValue(class CLC_RespondCvarValue __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CGameClient::ProcessRespondCvarValue(CGameClient *this, CLC_RespondCvarValue *msg)
{
  int m_iCookie; // edx

  m_iCookie = msg->m_iCookie;
  if ( m_iCookie > 0 && g_pServerPluginHandler != nullptr )
    g_pServerPluginHandler->OnQueryCvarValueFinished(
      this: g_pServerPluginHandler,
      a2: m_iCookie,
      a3: (edict_t *)this->m_LastMovementTick,
      a4: msg->m_eStatusCode,
      a5: msg->m_szCvarName,
      a6: msg->m_szCvarValue);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1011A3F0
// Name: public: void CGameClient::DownloadCustomizations(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameClient::DownloadCustomizations(CGameClient *this)
{
  CBaseClient::CustomFile_s *m_nCustomFiles; // esi
  int i; // ebx
  CCustomFilename hexname; // [esp+Ch] [ebp-118h] BYREF
  char out[16]; // [esp+110h] [ebp-14h] BYREF
  unsigned __int8 in[4]; // [esp+120h] [ebp-4h] BYREF

  m_nCustomFiles = this->m_nCustomFiles;
  for ( i = 4; i != 0; --i )
  {
    if ( m_nCustomFiles->crc != 0 )
    {
      *(_DWORD *)in = m_nCustomFiles->crc;
      V_binarytohex(in, inputbytes: 4, out, outsize: 16);
      V_snprintf(pDest: hexname.m_Filename, maxLen: 260, pFormat: "%s/%s.dat", "downloads", out);
      if ( !g_pFileSystem->FileExists(this: &g_pFileSystem->IBaseFileSystem, a2: (const char *)&hexname, a3: nullptr) )
        m_nCustomFiles->reqID = this->m_NetChannel->RequestFile(
                                  this: this->m_NetChannel,
                                  a2: (const char *)&hexname,
                                  a3: false);
    }
    ++m_nCustomFiles;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1011A4A0
// Name: public: virtual void CGameClient::Connect(char const __near *,int,class INetChannel __near *,bool,enum CrossPlayPlatform_t,class CUtlVector<struct NetMessageCvar_t,class CUtlMemory<struct NetMessageCvar_t,int>> __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameClient::Connect(
        CGameClient *this,
        const char *szName,
        int nUserID,
        INetChannel *pNetChannel,
        bool bFakePlayer,
        float clientPlatform,
        CUtlVector<NetMessageCvar_t,CUtlMemory<NetMessageCvar_t,int> > *pVecCvars)
{
  CClientFrame *v8; // eax
  IGameEvent *v9; // esi
  IGameEvent_vtbl *v10; // ebx
  int ClientXuid; // eax
  int v12; // edx
  IGameEvent_vtbl *v13; // ebx
  int v14; // eax
  int m_nFilesDownloaded; // ecx
  const char *v16; // eax

  CBaseClient::Connect(this, szName, nUserID, pNetChannel, bFakePlayer, clientPlatform, pVecCvars);
  v8 = (CClientFrame *)EDICT_NUM(n: this->m_nClientSlot);
  this->m_nSoundSequence = (int)v8;
  this->m_pCurrentFrame = v8;
  *(_DWORD *)&this->m_PackInfo.m_PVS[8188] = 0x2000;
  v9 = g_GameEventManager->CreateEventA(this: g_GameEventManager, a2: "player_connect", a3: 0, a4: 0);
  v9->SetInt(this: v9, a2: "userid", a3: this->m_nEntityIndex);
  v9->SetInt(this: v9, a2: "index", a3: *(_DWORD *)&this->m_bSplitPlayerDisconnecting);
  v9->SetString(this: v9, a2: "name", a3: (const char *)&this->m_UserID);
  v10 = v9->__vftable;
  ClientXuid = CBaseClient::GetClientXuid(this: (CGameClient *)((char *)this - 4));
  ((void (__thiscall *)(IGameEvent *, const char *, int, int))v10->SetUint64)(
    a1: v9,
    a2: "xuid",
    a3: ClientXuid,
    a4: v12);
  v13 = v9->__vftable;
  v14 = ((int (__thiscall *)(CGameClient *))this->PerformDisconnection)(a1: this);
  v13->SetString(this: v9, a2: "networkid", a3: (const char *)v14);
  m_nFilesDownloaded = this->m_nFilesDownloaded;
  if ( m_nFilesDownloaded != 0 )
    v16 = (const char *)(*(int (__thiscall **)(int))(*(_DWORD *)m_nFilesDownloaded + 4))(a1: m_nFilesDownloaded);
  else
    v16 = "none";
  v9->SetString(this: v9, a2: "address", a3: v16);
  v9->SetInt(this: v9, a2: "bot", a3: LOBYTE(this->m_nForceWaitForTick) != 0);
  g_GameEventManager->FireEvent(this: g_GameEventManager, a2: v9, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x1011A5C0
// Name: public: void CGameClient::SetupPrevPackInfo(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameClient::SetupPrevPackInfo(CGameClient *this)
{
  int m_AreasNetworked; // eax
  int m_nMapAreas; // eax
  int m_nPVSSize; // [esp-10h] [ebp-1Ch]

  m_AreasNetworked = this->m_PackInfo.m_AreasNetworked;
  qmemcpy(&this->m_PrevTransmitEdict, this->m_PackInfo.m_pTransmitEdict, sizeof(this->m_PrevTransmitEdict));
  this->m_PrevPackInfo.m_AreasNetworked = m_AreasNetworked;
  memcpy(
    dst: (unsigned __int8 *)this->m_PrevPackInfo.m_Areas,
    src: (unsigned __int8 *)this->m_PackInfo.m_Areas,
    count: 4 * m_AreasNetworked);
  m_nPVSSize = this->m_PackInfo.m_nPVSSize;
  this->m_PrevPackInfo.m_nPVSSize = m_nPVSSize;
  memcpy(dst: this->m_PrevPackInfo.m_PVS, src: this->m_PackInfo.m_PVS, count: m_nPVSSize);
  m_nMapAreas = this->m_PackInfo.m_nMapAreas;
  this->m_PrevPackInfo.m_nMapAreas = m_nMapAreas;
  memcpy(dst: this->m_PrevPackInfo.m_AreaFloodNums, src: this->m_PackInfo.m_AreaFloodNums, count: 4 * m_nMapAreas);
}

//------------------------------------------------------------------------------
// Address: 0x1011A650
// Name: public: virtual void CGameClient::UpdateUserSettings(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameClient::UpdateUserSettings(CGameClient *this)
{
  this->m_bVoiceLoopback = KeyValues::GetInt(this: this->m_ConVars, keyName: "voice_loopback", defaultValue: 0) != 0;
  CBaseClient::UpdateUserSettings(this);
  g_pServerPluginHandler->ClientSettingsChanged(this: g_pServerPluginHandler, a2: this->edict);
}

//------------------------------------------------------------------------------
// Address: 0x1011A690
// Name: public: virtual void CGameClient::Reconnect(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameClient::Reconnect(CGameClient *this)
{
  CGameServer::RemoveClientFromGame(this: &sv, client: (CGameClient *)((char *)this - 4));
  CBaseClient::Reconnect(this);
}

//------------------------------------------------------------------------------
// Address: 0x1011A6B0
// Name: public: virtual bool CGameClient::CheckConnect(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CGameClient::CheckConnect(CGameClient *this)
{
  CServerPlugin_vtbl *v2; // ebx
  int v3; // eax
  char szRejectReason[128]; // [esp+Ch] [ebp-80h] BYREF

  V_strncpy(pDest: szRejectReason, pSrc: "Connection rejected by game\n", maxLen: 128);
  v2 = g_pServerPluginHandler->__vftable;
  v3 = (*(int (__thiscall **)(int, char *, int))(*(_DWORD *)this->m_nFilesDownloaded + 4))(
         a1: this->m_nFilesDownloaded,
         a2: szRejectReason,
         a3: 128);
  if ( ((unsigned __int8 (__thiscall *)(CServerPlugin *, int, int *, int))v2->ClientConnect)(
         a1: g_pServerPluginHandler,
         a2: this->m_nSoundSequence,
         a3: &this->m_UserID,
         a4: v3) != 0 )
    return CBaseServer::ShouldUpdateMasterServer((vgui::Splitter *)this);
  ((void (__cdecl *)(CGameClient *, char *, int *))this->SendSignonData)(
    a1: this,
    a2: szRejectReason,
    a3: &this->m_UserID);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1011A740
// Name: public: virtual void CGameClient::ActivatePlayer(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameClient::ActivatePlayer(CGameClient *this)
{
  IGameEvent *v2; // edi
  int v3; // eax
  IGameEvent v4; // [esp+Ch] [ebp-4h]

  CBaseClient::ActivatePlayer(this);
  _COM_TimestampedLog(a1: "CGameClient::ActivatePlayer -start");
  if ( !sv.m_bLoadgame )
  {
    g_ServerGlobalVariables.curtime = CBaseServer::GetTime(this: &sv);
    _COM_TimestampedLog(a1: "g_pServerPluginHandler->ClientPutInServer");
    g_pServerPluginHandler->ClientPutInServer(this: g_pServerPluginHandler, a2: this->edict, a3: this->m_Name);
  }
  _COM_TimestampedLog(a1: "g_pServerPluginHandler->ClientActive");
  g_pServerPluginHandler->ClientActive(this: g_pServerPluginHandler, a2: this->edict, a3: sv.m_bLoadgame);
  _COM_TimestampedLog(a1: "g_pServerPluginHandler->ClientSettingsChanged");
  g_pServerPluginHandler->ClientSettingsChanged(this: g_pServerPluginHandler, a2: this->edict);
  _COM_TimestampedLog(a1: "GetTestScriptMgr()->CheckPoint");
  CTestScriptMgr::CheckPoint(this: &g_TestScriptMgr, pName: "client_connected");
  v2 = g_GameEventManager->CreateEventA(this: g_GameEventManager, a2: "player_activate", a3: 0, a4: 0);
  if ( v2 != nullptr )
  {
    v4.__vftable = v2->__vftable;
    v3 = this->GetUserID(this: &this->IClient);
    v4.SetInt(this: v2, a2: "userid", a3: v3);
    g_GameEventManager->FireEvent(this: g_GameEventManager, a2: v2, a3: false);
  }
  _COM_TimestampedLog(a1: "CGameClient::ActivatePlayer -end");
  this->m_flTimeClientBecameFullyConnected = realtime;
}

//------------------------------------------------------------------------------
// Address: 0x1011A870
// Name: public: virtual bool CGameClient::SendNetMsg(class INetMessage __near &,bool,bool)
// Source: json
//------------------------------------------------------------------------------
char __userpurge CGameClient::SendNetMsg@<al>(
        CGameClient *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>,
        INetMessage *msg,
        int bForceReliable,
        int bVoice)
{
  if ( LOBYTE(this->m_Server) != 0 )
    return CHLTVServer::SendNetMsg(this: hltv, msg, bForceReliable, bVoice);
  else
    return CBaseClient::SendNetMsg(this, a2, a3, msg, bForceReliable, bVoice);
}

//------------------------------------------------------------------------------
// Address: 0x1011A8F0
// Name: public: virtual void CGameClient::FileDenied(char const __near *,unsigned int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameClient::FileDenied(
        CGameClient *this,
        const char *fileName,
        unsigned int transferID,
        bool bIsReplayDemoFile)
{
  const char *v4; // eax

  v4 = (const char *)((int (__thiscall *)(CGameClient *))this->SetUserCVar)(a1: this);
  ConMsg(a1: "Downloading file '%s' from client %s failed.\n", fileName, v4);
}

//------------------------------------------------------------------------------
// Address: 0x1011AA10
// Name: public: virtual void CGameClient::ConnectionCrashed(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameClient::ConnectionCrashed(CGameClient *this, const char *reason)
{
  const char *v3; // eax

  if ( LOBYTE(this->m_UserID) != 0
    && ((unsigned __int8 (__thiscall *)(CGameClient *))this->CBaseClient::IGameEventListener2::__vftable[1].WriteGameSounds)(a1: this) != 0 )
  {
    SV_RedirectEnd();
    v3 = reason;
    if ( reason == nullptr )
      v3 = "Connection lost";
    ((void (__cdecl *)(CGameClient *, const char *))this->SendSignonData)(a1: this, a2: v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1011AA50
// Name: public: virtual bool CGameClient::IgnoreTempEntity(class CEventInfo __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CGameClient::IgnoreTempEntity(CGameClient *this, CEventInfo *event)
{
  return !this->m_bIsInReplayMode && CBaseClient::IgnoreTempEntity(this, event);
}

//------------------------------------------------------------------------------
// Address: 0x1011AA70
// Name: public: class CCheckTransmitInfo const __near * CGameClient::GetPrevPackInfo(void)
// Source: json
//------------------------------------------------------------------------------
const CCheckTransmitInfo *__thiscall CGameClient::GetPrevPackInfo(CGameClient *this)
{
  return &this->m_PrevPackInfo;
}

//------------------------------------------------------------------------------
// Address: 0x1011AA80
// Name: public: virtual bool CBaseServer::IsPaused(void)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CBaseServer::IsPaused(CBaseServer *this)
{
  return this->m_State == ss_paused;
}

//------------------------------------------------------------------------------
// Address: 0x1011AA90
// Name: public: virtual bool CBaseServer::IsMultiplayer(void)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CBaseServer::IsMultiplayer(CBaseServer *this)
{
  return this->m_nMaxclients > 1;
}

//------------------------------------------------------------------------------
// Address: 0x1011AAA0
// Name: int ClampClientRate(int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ClampClientRate(int nRate)
{
  int m_nValue; // ecx
  int result; // eax
  int v3; // ecx

  if ( sv_maxrate.m_pParent != nullptr && (m_nValue = sv_maxrate.m_pParent->m_Value.m_nValue) > 0 )
  {
    result = nRate;
    if ( nRate >= m_nValue )
      result = sv_maxrate.m_pParent->m_Value.m_nValue;
  }
  else
  {
    result = nRate;
  }
  if ( sv_minrate.m_pParent != nullptr )
  {
    v3 = sv_minrate.m_pParent->m_Value.m_nValue;
    if ( v3 > 0 && result <= v3 )
      result = sv_minrate.m_pParent->m_Value.m_nValue;
  }
  if ( result < 1000 )
    return 1000;
  if ( result > 30000 )
    return 30000;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1011AB00
// Name: public: virtual bool CGameClient::ProcessMove(class CLC_Move __near *)
// Source: json
//------------------------------------------------------------------------------
char __userpurge CGameClient::ProcessMove@<al>(CGameClient *this@<ecx>, int a2@<ebx>, int a3@<edi>, CLC_Move *msg)
{
  CBaseClient *BaseUserForSplitClient; // eax
  int v8; // edi
  const unsigned int *m_pData; // eax
  int m_nDataBits; // ecx
  const unsigned int *v11; // eax
  int netdrop; // [esp+8h] [ebp-10h]
  char *v16; // [esp+10h] [ebp-8h]
  int startbit; // [esp+20h] [ebp+8h]

  v16 = (char *)this - 4;
  if ( (*(unsigned __int8 (**)(void))(*((_DWORD *)this - 1) + 132))() == 0
    || this->m_VoiceProximity.m_Ints[0] == sv.m_nTickCount )
  {
    return 1;
  }
  this->m_VoiceProximity.m_Ints[0] = sv.m_nTickCount;
  BaseUserForSplitClient = CBaseServer::GetBaseUserForSplitClient(
                             this: &sv,
                             pSplitUser: (CGameClient *)((char *)this - 8));
  v8 = msg->m_nNewCommands + msg->m_nBackupCommands;
  netdrop = ((int (__thiscall *)(INetChannel *, int, int))BaseUserForSplitClient->m_NetChannel->GetDropNumber)(
              a1: BaseUserForSplitClient->m_NetChannel,
              a2: a3,
              a3: a2);
  if ( sv.m_State != ss_paused && sv.m_nMaxclients <= 1 )
    Con_IsVisible();
  g_ServerGlobalVariables.curtime = CBaseServer::GetTime(this: &sv);
  g_ServerGlobalVariables.frametime = host_state.interval_per_tick;
  m_pData = msg->m_DataIn.m_pData;
  if ( m_pData != nullptr )
  {
    m_nDataBits = msg->m_DataIn.m_nDataBits;
    startbit = 32 * (msg->m_DataIn.m_pDataIn - m_pData)
             - msg->m_DataIn.m_nBitsAvail
             + 8 * (msg->m_DataIn.m_nDataBytes & 3);
    if ( startbit >= m_nDataBits )
      startbit = m_nDataBits;
  }
  else
  {
    startbit = 0;
  }
  ((void (__thiscall *)(IServerGameClients *, int, bf_read *, int, int, int))serverGameClients->ProcessUsercmds)(
    a1: serverGameClients,
    a2: this->m_LastMovementTick,
    a3: &msg->m_DataIn,
    a4: msg->m_nNewCommands,
    a5: v8,
    a6: netdrop);
  if ( msg->m_DataIn.m_bOverflow )
  {
    (*(void (__cdecl **)(char *, const char *))(*(_DWORD *)v16 + 52))(
      a1: v16,
      a2: "ProcessUsercmds:  Overflowed reading usercmd data (check sending and receiving code for mismatches)!\n");
    return 0;
  }
  else
  {
    v11 = msg->m_DataIn.m_pData;
    if ( v11 != nullptr )
    {
      v11 = (const unsigned int *)(32 * (msg->m_DataIn.m_pDataIn - v11)
                                 - msg->m_DataIn.m_nBitsAvail
                                 + 8 * (msg->m_DataIn.m_nDataBytes & 3));
      if ( (int)v11 >= msg->m_DataIn.m_nDataBits )
        v11 = (const unsigned int *)msg->m_DataIn.m_nDataBits;
    }
    if ( (const unsigned int *)msg->m_nLength == (const unsigned int *)((char *)v11 - startbit) )
    {
      return 1;
    }
    else
    {
      (*(void (__cdecl **)(char *, const char *))(*(_DWORD *)v16 + 52))(
        a1: v16,
        a2: "ProcessUsercmds:  Incorrect reading frame (check sending and receiving code for mismatches)!\n");
      return 0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1011ACA0
// Name: public: virtual bool CGameClient::ProcessFileCRCCheck(class CLC_FileCRCCheck __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CGameClient::ProcessFileCRCCheck(CGameClient *this, CLC_FileCRCCheck *msg)
{
  char *m_szFilename; // esi
  char *m_szPathID; // edi
  EFileCRCStatus v4; // eax
  char *v6; // esi
  const char *v7; // eax
  const char *v8; // eax
  const char *v9; // [esp-14h] [ebp-41Ch]
  const char *v10; // [esp-10h] [ebp-418h]
  const char *v11; // [esp-10h] [ebp-418h]
  char warningStr[1024]; // [esp+0h] [ebp-408h] BYREF
  unsigned int fileCRC; // [esp+400h] [ebp-8h] BYREF
  CGameClient *v14; // [esp+404h] [ebp-4h]

  v14 = this;
  if ( CGameServer::IsInPureServerMode(this: &sv) )
  {
    memset(warningStr, 0, sizeof(warningStr));
    m_szFilename = msg->m_szFilename;
    m_szPathID = msg->m_szPathID;
    v4 = g_pFileSystem->CheckCachedFileCRC(
           this: g_pFileSystem,
           a2: msg->m_szPathID,
           a3: msg->m_szFilename,
           a4: &fileCRC);
    if ( v4 != k_eFileCRCStatus_CantOpenFile )
    {
      if ( v4 == k_eFileCRCStatus_GotCRC && fileCRC != msg->m_CRC )
        V_snprintf(
          pDest: warningStr,
          maxLen: 1024,
          pFormat: "Pure server: file [%s]\\%s does not match the server's file.",
          m_szPathID,
          m_szFilename);
    }
    else
    {
      V_snprintf(
        pDest: warningStr,
        maxLen: 1024,
        pFormat: "Pure server: client has loaded extra file [%s]\\%s. File must be removed to play on this server.",
        m_szPathID,
        m_szFilename);
    }
    if ( warningStr[0] != 0 )
    {
      if ( sv_pure_kick_clients.m_pParent != nullptr && sv_pure_kick_clients.m_pParent->m_Value.m_nValue != 0 )
      {
        (*(void (**)(float *, const char *, ...))(*((_DWORD *)&v14[-1].m_flTimeClientBecameFullyConnected + 1) + 52))(
          a1: &v14[-1].m_flTimeClientBecameFullyConnected + 1,
          a2: "%s",
          warningStr);
        return 1;
      }
      v6 = (char *)(&v14[-1].m_flTimeClientBecameFullyConnected + 1);
      (*(void (**)(float *, const char *, ...))(*((_DWORD *)&v14[-1].m_flTimeClientBecameFullyConnected + 1) + 120))(
        a1: &v14[-1].m_flTimeClientBecameFullyConnected + 1,
        a2: "Warning: %s\n",
        warningStr);
      if ( sv_pure_trace.m_pParent != nullptr && sv_pure_trace.m_pParent->m_Value.m_nValue >= 1 )
      {
        v7 = (const char *)(*(int (__thiscall **)(char *, char *))(*(_DWORD *)v6 + 84))(a1: v6, a2: warningStr);
        _Msg(a1: "[%s] %s\n", v7, v10);
        return 1;
      }
    }
    else if ( sv_pure_trace.m_pParent != nullptr && sv_pure_trace.m_pParent->m_Value.m_nValue >= 2 )
    {
      v8 = (const char *)(*(int (__thiscall **)(float *, char *, char *))(*((_DWORD *)&v14[-1].m_flTimeClientBecameFullyConnected
                                                                          + 1)
                                                                        + 68))(
                           a1: &v14[-1].m_flTimeClientBecameFullyConnected + 1,
                           a2: m_szPathID,
                           a3: m_szFilename);
      _Msg(a1: "Pure server CRC check: client %s passed check for [%s]\\%s\n", v8, v9, v11);
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1011AE20
// Name: public: virtual void CGameClient::SetRate(int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameClient::SetRate(CGameClient *this, int nRate, bool bForce)
{
  int v3; // eax
  CGameClient *v4; // edx

  v3 = nRate;
  v4 = this;
  if ( !bForce )
    v3 = ClampClientRate(nRate);
  CBaseClient::SetRate(this: v4, nRate: v3, bForce);
}

//------------------------------------------------------------------------------
// Address: 0x1011AE50
// Name: public: virtual void CGameClient::SetUpdateRate(int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameClient::SetUpdateRate(CGameClient *this, int udpaterate, bool bForce)
{
  int m_nValue; // eax
  int v4; // edx

  if ( bForce )
  {
    m_nValue = udpaterate;
  }
  else
  {
    if ( sv_maxupdaterate.m_pParent != nullptr && (m_nValue = sv_maxupdaterate.m_pParent->m_Value.m_nValue) > 0 )
    {
      if ( udpaterate >= 1 )
      {
        if ( udpaterate <= m_nValue )
          m_nValue = udpaterate;
      }
      else
      {
        m_nValue = 1;
      }
    }
    else
    {
      m_nValue = udpaterate;
    }
    if ( sv_minupdaterate.m_pParent != nullptr )
    {
      v4 = sv_minupdaterate.m_pParent->m_Value.m_nValue;
      if ( v4 > 0 )
      {
        if ( m_nValue < v4 )
        {
          CBaseClient::SetUpdateRate(this, udpaterate: v4, bForce: false);
          return;
        }
        if ( m_nValue > 100 )
        {
          CBaseClient::SetUpdateRate(this, udpaterate: 100, bForce: false);
          return;
        }
      }
    }
  }
  CBaseClient::SetUpdateRate(this, udpaterate: m_nValue, bForce);
}

//------------------------------------------------------------------------------
// Address: 0x1011AED0
// Name: public: virtual bool CGameClient::UpdateAcknowledgedFramecount(int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CGameClient::UpdateAcknowledgedFramecount(CGameClient *this, int tick)
{
  int v4; // eax
  float m_fValue; // [esp+8h] [ebp-4h]
  float ticka; // [esp+14h] [ebp+8h]

  if ( tick != this->m_nDeltaTick )
  {
    v4 = tick;
    if ( sv_maxreplay.m_pParent->m_Value.m_fValue > 0.0 )
    {
      ticka = (float)tick;
      m_fValue = sv_maxreplay.m_pParent->m_Value.m_fValue;
      v4 = (int)(ticka
               - m_fValue / ((double (__thiscall *)(CBaseServer *))this->m_Server->GetTickInterval)(a1: this->m_Server));
    }
    if ( v4 > 0 )
      CClientFrameManager::DeleteClientFrames(this: &this->CClientFrameManager, nTick: v4);
  }
  return CBaseClient::UpdateAcknowledgedFramecount(this, tick);
}

//------------------------------------------------------------------------------
// Address: 0x1011AF50
// Name: public: virtual void CGameClient::Disconnect(char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
void CGameClient::Disconnect(CGameClient *this, const char *fmt, ...)
{
  char reason[1024]; // [esp+4h] [ebp-400h] BYREF
  va_list params; // [esp+414h] [ebp+10h] BYREF

  va_start(params, fmt);
  if ( this->m_NetChannel != nullptr )
  {
    V_vsnprintf(pDest: reason, maxLen: 1024, pFormat: fmt, params);
    CBaseClient::Disconnect(a1: (int)this, this, fmt: "%s", reason);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1011AFA0
// Name: public: virtual bool CGameClient::ProcessSignonStateMsg(int,int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CGameClient::ProcessSignonStateMsg(CGameClient *this, int state, int spawncount)
{
  bool result; // al
  int flTimeout; // [esp+18h] [ebp+8h]

  if ( state == 2 )
  {
    result = this->CheckConnect(this: &this->IClient);
    if ( result )
    {
      flTimeout = 1133903872;
      if ( sv.m_bIsDedicatedForXbox )
        flTimeout = 1117126656;
      ((void (__stdcall *)(int, _DWORD))this->m_NetChannel->SetTimeout)(a1: flTimeout, a2: 0);
      this->m_NetChannel->SetFileTransmissionMode(this: this->m_NetChannel, a2: false);
      this->m_NetChannel->SetMaxBufferSize(this: this->m_NetChannel, a2: true, a3: 96000, a4: false);
      return CBaseClient::ProcessSignonStateMsg(this, state: 2, spawncount);
    }
  }
  else
  {
    if ( state == 3 )
    {
      if ( sv.m_nMaxclients <= 1 )
      {
        SV_InstallClientStringTableMirrors();
        return CBaseClient::ProcessSignonStateMsg(this, state: 3, spawncount);
      }
    }
    else if ( state == 6 )
    {
      if ( sv.m_bLoadgame )
        CGameServer::FinishRestore(this: &sv, a2: (int)this);
      ((void (__stdcall *)(_DWORD, _DWORD))this->m_NetChannel->SetTimeout)(
        a1: sv_timeout.m_pParent->m_Value.m_fValue,
        a2: 0);
      this->m_NetChannel->SetFileTransmissionMode(this: this->m_NetChannel, a2: true);
      g_pServerPluginHandler->ClientFullyConnect(this: g_pServerPluginHandler, a2: this->edict);
    }
    return CBaseClient::ProcessSignonStateMsg(this, state, spawncount);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1011B0E0
// Name: private: bool CGameClient::IsEngineClientCommand(class CCommand const __near &)const
// Source: json
//------------------------------------------------------------------------------
char __thiscall CGameClient::IsEngineClientCommand(CGameClient *this, const CCommand *args)
{
  int v3; // esi
  const char **v4; // eax
  const char *v5; // eax
  const char *v6; // [esp-8h] [ebp-Ch]

  if ( args->m_nArgc == 0 )
    return 0;
  v3 = 0;
  if ( s_clcommands[0] == nullptr )
    return 0;
  v4 = s_clcommands;
  while ( 1 )
  {
    v6 = *v4;
    v5 = CCommand::operator[](this: args, nIndex: 0);
    if ( V_strcasecmp(s1: v5, s2: v6) == 0 )
      break;
    v4 = &s_clcommands[++v3];
    if ( *v4 == nullptr )
      return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1011B140
// Name: public: void SoundInfo_t::WriteDelta(struct SoundInfo_t __near *,class bf_write __near &,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SoundInfo_t::WriteDelta(SoundInfo_t *this, SoundInfo_t *delta, bf_write *buffer, float finalTickTime)
{
  SoundInfo_t *v4; // eax
  bool v5; // zf
  int m_iCurBit; // ecx
  int v8; // edx
  int v9; // ecx
  int v10; // edx
  int v11; // ecx
  int v12; // edx
  int v13; // ecx
  int v14; // edx
  int v15; // ecx
  int v16; // eax
  SoundInfo_t *v17; // eax
  int v18; // ecx
  BOOL bIsAmbient; // edx
  int v20; // edi
  char v21; // cl
  BOOL bIsSentence; // edi
  int v23; // ecx
  int v24; // eax
  char v25; // cl
  unsigned __int8 *m_pData; // edi
  int nSequenceNumber; // eax
  int v28; // ecx
  int v29; // ecx
  int v30; // ecx
  int v31; // ecx
  int v32; // ecx
  int v33; // edx
  int v34; // ecx
  int v35; // eax
  int v36; // ecx
  int v37; // edx
  int v38; // ecx
  int v39; // eax
  float fDelay; // xmm1_4
  float fTickTime; // xmm0_4
  int v42; // ecx
  int v43; // eax
  int v44; // ecx
  int v45; // edx
  int v46; // ecx
  int v47; // edx
  int v48; // ecx
  int v49; // edx
  int v50; // ecx
  int v51; // eax
  SoundInfo_t *v52; // [esp+18h] [ebp-4h]
  float delayValue; // [esp+28h] [ebp+Ch]

  v4 = this;
  v5 = this->nEntityIndex == delta->nEntityIndex;
  m_iCurBit = buffer->m_iCurBit;
  v52 = v4;
  v8 = m_iCurBit + 1;
  if ( v5 )
  {
    if ( v8 > buffer->m_nDataBits )
      buffer->m_bOverflow = true;
    if ( !buffer->m_bOverflow )
    {
      buffer->m_pData[m_iCurBit >> 3] &= ~(1 << (m_iCurBit & 7));
      ++buffer->m_iCurBit;
    }
  }
  else
  {
    if ( v8 > buffer->m_nDataBits )
      buffer->m_bOverflow = true;
    if ( !buffer->m_bOverflow )
    {
      buffer->m_pData[m_iCurBit >> 3] |= 1 << (m_iCurBit & 7);
      ++buffer->m_iCurBit;
    }
    v9 = buffer->m_iCurBit;
    v10 = v9 + 1;
    if ( v4->nEntityIndex > 31 )
    {
      if ( v10 > buffer->m_nDataBits )
        buffer->m_bOverflow = true;
      if ( !buffer->m_bOverflow )
      {
        buffer->m_pData[v9 >> 3] &= ~(1 << (v9 & 7));
        ++buffer->m_iCurBit;
      }
      bf_write::WriteUBitLong(this: buffer, curData: v4->nEntityIndex, numbits: 11, bCheckRange: true);
    }
    else
    {
      if ( v10 > buffer->m_nDataBits )
        buffer->m_bOverflow = true;
      if ( !buffer->m_bOverflow )
      {
        buffer->m_pData[v9 >> 3] |= 1 << (v9 & 7);
        ++buffer->m_iCurBit;
      }
      bf_write::WriteUBitLong(this: buffer, curData: v4->nEntityIndex, numbits: 5, bCheckRange: true);
    }
    v4 = v52;
  }
  v11 = buffer->m_iCurBit;
  v12 = v11 + 1;
  if ( v4->nSoundNum == delta->nSoundNum )
  {
    if ( v12 > buffer->m_nDataBits )
      buffer->m_bOverflow = true;
    if ( !buffer->m_bOverflow )
    {
      buffer->m_pData[v11 >> 3] &= ~(1 << (v11 & 7));
      ++buffer->m_iCurBit;
    }
  }
  else
  {
    if ( v12 > buffer->m_nDataBits )
      buffer->m_bOverflow = true;
    if ( !buffer->m_bOverflow )
    {
      buffer->m_pData[v11 >> 3] |= 1 << (v11 & 7);
      ++buffer->m_iCurBit;
      v4 = v52;
    }
    bf_write::WriteUBitLong(this: buffer, curData: v4->nSoundNum, numbits: 13, bCheckRange: true);
  }
  v13 = buffer->m_iCurBit;
  v14 = v13 + 1;
  if ( v52->nFlags == delta->nFlags )
  {
    if ( v14 > buffer->m_nDataBits )
      buffer->m_bOverflow = true;
    if ( !buffer->m_bOverflow )
    {
      buffer->m_pData[v13 >> 3] &= ~(1 << (v13 & 7));
      ++buffer->m_iCurBit;
    }
  }
  else
  {
    if ( v14 > buffer->m_nDataBits )
      buffer->m_bOverflow = true;
    if ( !buffer->m_bOverflow )
    {
      buffer->m_pData[v13 >> 3] |= 1 << (v13 & 7);
      ++buffer->m_iCurBit;
    }
    bf_write::WriteUBitLong(this: buffer, curData: v52->nFlags, numbits: 13, bCheckRange: true);
  }
  v15 = buffer->m_iCurBit;
  v16 = v15 + 1;
  if ( v52->nChannel == delta->nChannel )
  {
    if ( v16 > buffer->m_nDataBits )
      buffer->m_bOverflow = true;
    if ( !buffer->m_bOverflow )
    {
      buffer->m_pData[v15 >> 3] &= ~(1 << (v15 & 7));
      ++buffer->m_iCurBit;
    }
  }
  else
  {
    if ( v16 > buffer->m_nDataBits )
      buffer->m_bOverflow = true;
    if ( !buffer->m_bOverflow )
    {
      buffer->m_pData[v15 >> 3] |= 1 << (v15 & 7);
      ++buffer->m_iCurBit;
    }
    bf_write::WriteUBitLong(this: buffer, curData: v52->nChannel, numbits: 3, bCheckRange: true);
  }
  v17 = v52;
  v18 = buffer->m_iCurBit;
  bIsAmbient = v52->bIsAmbient;
  if ( v18 + 1 > buffer->m_nDataBits )
    buffer->m_bOverflow = true;
  if ( !buffer->m_bOverflow )
  {
    v20 = v18 >> 3;
    v21 = v18 & 7;
    if ( bIsAmbient )
      buffer->m_pData[v20] |= 1 << v21;
    else
      buffer->m_pData[v20] &= ~(1 << v21);
    ++buffer->m_iCurBit;
    v17 = v52;
  }
  bIsSentence = v17->bIsSentence;
  v23 = buffer->m_iCurBit;
  if ( v23 + 1 > buffer->m_nDataBits )
    buffer->m_bOverflow = true;
  if ( !buffer->m_bOverflow )
  {
    v24 = v23 >> 3;
    v25 = v23 & 7;
    v5 = !bIsSentence;
    m_pData = buffer->m_pData;
    if ( v5 )
      m_pData[v24] &= ~(1 << v25);
    else
      m_pData[v24] |= 1 << v25;
    ++buffer->m_iCurBit;
    v17 = v52;
  }
  if ( v17->nFlags == 4 )
  {
    v17->fVolume = 0.0;
    v17->Soundlevel = SNDLVL_NONE;
    v17->nPitch = 100;
    v17->pszName = nullptr;
    v17->fDelay = 0.0;
    v17->nSequenceNumber = 0;
    v17->vOrigin.x = 0.0;
    v17->vOrigin.y = 0.0;
    v17->vOrigin.z = 0.0;
    v17->nSpeakerEntity = -1;
  }
  else
  {
    nSequenceNumber = v17->nSequenceNumber;
    v28 = delta->nSequenceNumber;
    if ( nSequenceNumber == v28 )
    {
      v29 = buffer->m_iCurBit;
      if ( v29 + 1 > buffer->m_nDataBits )
        buffer->m_bOverflow = true;
      if ( !buffer->m_bOverflow )
      {
        buffer->m_pData[v29 >> 3] |= 1 << (v29 & 7);
        ++buffer->m_iCurBit;
      }
    }
    else if ( nSequenceNumber == v28 + 1 )
    {
      v30 = buffer->m_iCurBit;
      if ( v30 + 1 > buffer->m_nDataBits )
        buffer->m_bOverflow = true;
      if ( !buffer->m_bOverflow )
      {
        buffer->m_pData[v30 >> 3] &= ~(1 << (v30 & 7));
        ++buffer->m_iCurBit;
      }
      v31 = buffer->m_iCurBit;
      if ( v31 + 1 > buffer->m_nDataBits )
        buffer->m_bOverflow = true;
      if ( !buffer->m_bOverflow )
      {
        buffer->m_pData[v31 >> 3] |= 1 << (v31 & 7);
        ++buffer->m_iCurBit;
      }
    }
    else
    {
      bf_write::WriteUBitLong(this: buffer, curData: 0, numbits: 2, bCheckRange: true);
      bf_write::WriteUBitLong(this: buffer, curData: v52->nSequenceNumber, numbits: 10, bCheckRange: true);
    }
    v32 = buffer->m_iCurBit;
    v33 = v32 + 1;
    if ( v52->fVolume == delta->fVolume )
    {
      if ( v33 > buffer->m_nDataBits )
        buffer->m_bOverflow = true;
      if ( !buffer->m_bOverflow )
      {
        buffer->m_pData[v32 >> 3] &= ~(1 << (v32 & 7));
        ++buffer->m_iCurBit;
      }
    }
    else
    {
      if ( v33 > buffer->m_nDataBits )
        buffer->m_bOverflow = true;
      if ( !buffer->m_bOverflow )
      {
        buffer->m_pData[v32 >> 3] |= 1 << (v32 & 7);
        ++buffer->m_iCurBit;
      }
      bf_write::WriteUBitLong(this: buffer, curData: (__int64)(v52->fVolume * 127.0), numbits: 7, bCheckRange: true);
    }
    v34 = buffer->m_iCurBit;
    v35 = v34 + 1;
    if ( v52->Soundlevel == delta->Soundlevel )
    {
      if ( v35 > buffer->m_nDataBits )
        buffer->m_bOverflow = true;
      if ( !buffer->m_bOverflow )
      {
        buffer->m_pData[v34 >> 3] &= ~(1 << (v34 & 7));
        ++buffer->m_iCurBit;
      }
    }
    else
    {
      if ( v35 > buffer->m_nDataBits )
        buffer->m_bOverflow = true;
      if ( !buffer->m_bOverflow )
      {
        buffer->m_pData[v34 >> 3] |= 1 << (v34 & 7);
        ++buffer->m_iCurBit;
      }
      bf_write::WriteUBitLong(this: buffer, curData: v52->Soundlevel, numbits: 9, bCheckRange: true);
    }
    v36 = buffer->m_iCurBit;
    v37 = v36 + 1;
    if ( v52->nPitch == delta->nPitch )
    {
      if ( v37 > buffer->m_nDataBits )
        buffer->m_bOverflow = true;
      if ( !buffer->m_bOverflow )
      {
        buffer->m_pData[v36 >> 3] &= ~(1 << (v36 & 7));
        ++buffer->m_iCurBit;
      }
    }
    else
    {
      if ( v37 > buffer->m_nDataBits )
        buffer->m_bOverflow = true;
      if ( !buffer->m_bOverflow )
      {
        buffer->m_pData[v36 >> 3] |= 1 << (v36 & 7);
        ++buffer->m_iCurBit;
      }
      bf_write::WriteUBitLong(this: buffer, curData: v52->nPitch, numbits: 8, bCheckRange: true);
    }
    v38 = buffer->m_iCurBit;
    v39 = v38 + 1;
    if ( v52->nRandomSeed == delta->nRandomSeed )
    {
      if ( v39 > buffer->m_nDataBits )
        buffer->m_bOverflow = true;
      if ( !buffer->m_bOverflow )
      {
        buffer->m_pData[v38 >> 3] &= ~(1 << (v38 & 7));
        ++buffer->m_iCurBit;
      }
    }
    else
    {
      if ( v39 > buffer->m_nDataBits )
        buffer->m_bOverflow = true;
      if ( !buffer->m_bOverflow )
      {
        buffer->m_pData[v38 >> 3] |= 1 << (v38 & 7);
        ++buffer->m_iCurBit;
      }
      bf_write::WriteUBitLong(this: buffer, curData: v52->nRandomSeed, numbits: 6, bCheckRange: true);
    }
    fDelay = v52->fDelay;
    delayValue = fDelay;
    if ( (v52->nFlags & 0x10) != 0 )
    {
      fTickTime = v52->fTickTime;
      if ( fTickTime != finalTickTime )
      {
        fDelay = fDelay + (float)(fTickTime - finalTickTime);
        delayValue = fDelay;
      }
    }
    v42 = buffer->m_iCurBit;
    v43 = v42 + 1;
    if ( fDelay == delta->fDelay )
    {
      if ( v43 > buffer->m_nDataBits )
        buffer->m_bOverflow = true;
      if ( !buffer->m_bOverflow )
      {
        buffer->m_pData[v42 >> 3] &= ~(1 << (v42 & 7));
        ++buffer->m_iCurBit;
      }
    }
    else
    {
      if ( v43 > buffer->m_nDataBits )
        buffer->m_bOverflow = true;
      if ( !buffer->m_bOverflow )
      {
        buffer->m_pData[v42 >> 3] |= 1 << (v42 & 7);
        ++buffer->m_iCurBit;
      }
      bf_write::WriteFloat(this: buffer, val: delayValue);
    }
    v44 = buffer->m_iCurBit;
    v45 = v44 + 1;
    if ( v52->vOrigin.x == delta->vOrigin.x )
    {
      if ( v45 > buffer->m_nDataBits )
        buffer->m_bOverflow = true;
      if ( !buffer->m_bOverflow )
      {
        buffer->m_pData[v44 >> 3] &= ~(1 << (v44 & 7));
        ++buffer->m_iCurBit;
      }
    }
    else
    {
      if ( v45 > buffer->m_nDataBits )
        buffer->m_bOverflow = true;
      if ( !buffer->m_bOverflow )
      {
        buffer->m_pData[v44 >> 3] |= 1 << (v44 & 7);
        ++buffer->m_iCurBit;
      }
      bf_write::WriteSBitLong(this: buffer, data: (int)(float)(v52->vOrigin.x * 0.125), numbits: 12);
    }
    v46 = buffer->m_iCurBit;
    v47 = v46 + 1;
    if ( v52->vOrigin.y == delta->vOrigin.y )
    {
      if ( v47 > buffer->m_nDataBits )
        buffer->m_bOverflow = true;
      if ( !buffer->m_bOverflow )
      {
        buffer->m_pData[v46 >> 3] &= ~(1 << (v46 & 7));
        ++buffer->m_iCurBit;
      }
    }
    else
    {
      if ( v47 > buffer->m_nDataBits )
        buffer->m_bOverflow = true;
      if ( !buffer->m_bOverflow )
      {
        buffer->m_pData[v46 >> 3] |= 1 << (v46 & 7);
        ++buffer->m_iCurBit;
      }
      bf_write::WriteSBitLong(this: buffer, data: (int)(float)(v52->vOrigin.y * 0.125), numbits: 12);
    }
    v48 = buffer->m_iCurBit;
    v49 = v48 + 1;
    if ( v52->vOrigin.z == delta->vOrigin.z )
    {
      if ( v49 > buffer->m_nDataBits )
        buffer->m_bOverflow = true;
      if ( !buffer->m_bOverflow )
      {
        buffer->m_pData[v48 >> 3] &= ~(1 << (v48 & 7));
        ++buffer->m_iCurBit;
      }
    }
    else
    {
      if ( v49 > buffer->m_nDataBits )
        buffer->m_bOverflow = true;
      if ( !buffer->m_bOverflow )
      {
        buffer->m_pData[v48 >> 3] |= 1 << (v48 & 7);
        ++buffer->m_iCurBit;
      }
      bf_write::WriteSBitLong(this: buffer, data: (int)(float)(v52->vOrigin.z * 0.125), numbits: 12);
    }
    v50 = buffer->m_iCurBit;
    v51 = v50 + 1;
    if ( v52->nSpeakerEntity == delta->nSpeakerEntity )
    {
      if ( v51 > buffer->m_nDataBits )
        buffer->m_bOverflow = true;
      if ( !buffer->m_bOverflow )
      {
        buffer->m_pData[v50 >> 3] &= ~(1 << (v50 & 7));
        ++buffer->m_iCurBit;
      }
    }
    else
    {
      if ( v51 > buffer->m_nDataBits )
        buffer->m_bOverflow = true;
      if ( !buffer->m_bOverflow )
      {
        buffer->m_pData[v50 >> 3] |= 1 << (v50 & 7);
        ++buffer->m_iCurBit;
      }
      bf_write::WriteSBitLong(this: buffer, data: v52->nSpeakerEntity, numbits: 12);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1011B970
// Name: public: virtual bool CGameClient::ProcessClientInfo(class CLC_ClientInfo __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CGameClient::ProcessClientInfo(CGameClient *this, CLC_ClientInfo *msg)
{
  CBaseClient::ProcessClientInfo(this, msg);
  if ( this->m_bConVarsChanged )
  {
    (*(void (__cdecl **)(char *, const char *))(*((_DWORD *)this - 1) + 52))(
      a1: (char *)this - 4,
      a2: "ProcessClientInfo: SourceTV can not connect to game directly.\n");
    return 0;
  }
  else
  {
    if ( sv_allowupload.m_pParent != nullptr && sv_allowupload.m_pParent->m_Value.m_nValue != 0 )
      CGameClient::DownloadCustomizations(this: (CGameClient *)((char *)this - 8));
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1011B9D0
// Name: public: void CGameClient::WriteViewAngleUpdate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameClient::WriteViewAngleUpdate(CGameClient *this)
{
  CPlayerState *v2; // eax
  float *v3; // esi
  int v4; // eax
  float v5; // edx
  float v6; // eax
  INetChannel *m_NetChannel; // ecx
  float v8; // ecx
  float v9; // edx
  float v10; // xmm0_4
  INetChannel *v11; // ecx
  SVC_FixAngle fixAngle; // [esp+8h] [ebp-2Ch] BYREF
  float v13; // [esp+28h] [ebp-Ch]
  float v14; // [esp+2Ch] [ebp-8h]
  float v15; // [esp+30h] [ebp-4h]

  if ( !this->IsFakeClient(this: &this->IClient) || this->IsSplitScreenUser(this: &this->IClient) )
  {
    v2 = serverGameClients->GetPlayerState(this: serverGameClients, a2: this->edict);
    v3 = (float *)v2;
    if ( v2 != nullptr )
    {
      v4 = v2->fixangle;
      if ( v4 != 0 )
      {
        fixAngle.m_NetChannel = nullptr;
        fixAngle.__vftable = (SVC_FixAngle_vtbl *)&SVC_FixAngle::`vftable';
        fixAngle.m_bReliable = false;
        if ( v4 == 2 )
        {
          v5 = v3[8];
          v6 = v3[9];
          v13 = v3[7];
          m_NetChannel = this->m_NetChannel;
          v14 = v5;
          fixAngle.m_Angle.x = v13;
          v15 = v6;
          fixAngle.m_Angle.y = v5;
          fixAngle.m_bRelative = true;
          fixAngle.m_Angle.z = v6;
          m_NetChannel->SendNetMsg(this: m_NetChannel, a2: &fixAngle, a3: false, a4: false);
          v3[7] = 0.0;
          v3[8] = 0.0;
          v3[9] = 0.0;
        }
        else
        {
          v8 = v3[3];
          v9 = v3[4];
          v13 = v3[2];
          fixAngle.m_Angle.x = v13;
          v14 = v8;
          v10 = v8;
          v11 = this->m_NetChannel;
          v15 = v9;
          fixAngle.m_Angle.y = v10;
          fixAngle.m_bRelative = false;
          fixAngle.m_Angle.z = v9;
          v11->SendNetMsg(this: v11, a2: &fixAngle, a3: false, a4: false);
        }
        v3[6] = 0.0;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1011BB00
// Name: public: virtual bool CGameClient::ExecuteStringCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CGameClient::ExecuteStringCommand(CGameClient *this, const char *pCommandString)
{
  const char *v4; // eax
  ConCommandBase *v5; // eax
  const ConCommandBase *v6; // esi
  CCommand args; // [esp+8h] [ebp-508h] BYREF

  if ( !CBaseClient::ExecuteStringCommand(this, pCommand: pCommandString) )
  {
    CCommand::CCommand(this: &args);
    if ( !CCommand::Tokenize(this: &args, pCommand: pCommandString, pBreakSet: nullptr) || args.m_nArgc == 0 )
      return 0;
    if ( CGameClient::IsEngineClientCommand(this: (CGameClient *)((char *)this - 4), &args) != 0 )
    {
      Cmd_ExecuteCommand(
        eTarget: CBUF_SERVER,
        command: &args,
        src: src_client,
        nClientSlot: *(_DWORD *)&this->m_bSplitPlayerDisconnecting);
      return 1;
    }
    v4 = defaultValue;
    if ( args.m_nArgc > 0 )
      v4 = args.m_ppArgv[0];
    v5 = g_pCVar->FindCommandBase_2(this: g_pCVar, a2: v4);
    v6 = v5;
    if ( v5 != nullptr && v5->IsCommand(this: v5) && v6->IsFlagSet(this: (ConCommandBase *)v6, a2: 4) )
    {
      if ( (!v6->IsFlagSet(this: (ConCommandBase *)v6, a2: 0x4000)
         || sv.m_nMaxclients <= 1
         || sv_cheats.m_pParent != nullptr && sv_cheats.m_pParent->m_Value.m_nValue != 0
         || Cmd_IsRptActive())
        && (!v6->IsFlagSet(this: (ConCommandBase *)v6, a2: 64) || sv.m_nMaxclients <= 1) )
      {
        g_pServerPluginHandler->SetCommandClient(
          this: g_pServerPluginHandler,
          a2: *(_DWORD *)&this->m_bSplitPlayerDisconnecting);
        Cmd_Dispatch(pCommand: v6, command: &args);
        return 1;
      }
      return 0;
    }
    g_pServerPluginHandler->ClientCommand_2(
      this: g_pServerPluginHandler,
      a2: (edict_t *)this->m_nSoundSequence,
      a3: &args);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1011BC80
// Name: public: virtual bool CGameClient::ShouldSendMessages(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CGameClient::ShouldSendMessages(CGameClient *this)
{
  float m_fValue; // [esp+4h] [ebp-4h]

  if ( !this->m_bIsHLTV )
    return (!this->IsFakeClient(this: &this->IClient)
         || sv_stressbots.m_pParent != nullptr && sv_stressbots.m_pParent->m_Value.m_nValue != 0)
        && CBaseClient::ShouldSendMessages(this);
  m_fValue = tv_snapshotrate.m_pParent->m_Value.m_fValue;
  return sv.m_nTickCount >= (int)(1.0
                                / (((double (__thiscall *)(CBaseServer *))this->m_Server->GetTickInterval)(a1: this->m_Server)
                                 * m_fValue))
                          + hltv->m_nLastTick;
}

//------------------------------------------------------------------------------
// Address: 0x1011BD10
// Name: public: virtual void CGameClient::FileRequested(char const __near *,unsigned int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameClient::FileRequested(
        CGameClient *this,
        const char *fileName,
        unsigned int transferID,
        int bIsReplayDemoFile)
{
  const char *v5; // eax

  v5 = (const char *)(*(int (__thiscall **)(int))(*(_DWORD *)this->m_nFilesDownloaded + 4))(a1: this->m_nFilesDownloaded);
  DevMsg(a1: "File '%s' requested from client %s.\n", fileName, v5);
  if ( sv_allowdownload.m_pParent != nullptr && sv_allowdownload.m_pParent->m_Value.m_nValue != 0 )
    (*(void (__thiscall **)(int, const char *, unsigned int, int))(*(_DWORD *)this->m_nFilesDownloaded + 172))(
      a1: this->m_nFilesDownloaded,
      a2: fileName,
      a3: transferID,
      a4: bIsReplayDemoFile);
  else
    (*(void (__thiscall **)(int, const char *, unsigned int, int))(*(_DWORD *)this->m_nFilesDownloaded + 176))(
      a1: this->m_nFilesDownloaded,
      a2: fileName,
      a3: transferID,
      a4: bIsReplayDemoFile);
}

//------------------------------------------------------------------------------
// Address: 0x1011BD90
// Name: public: virtual bool CGameClient::ProcessCmdKeyValues(class CLC_CmdKeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CGameClient::ProcessCmdKeyValues(CGameClient *this, CLC_CmdKeyValues *msg)
{
  CLC_CmdKeyValues *v2; // edi
  const char *Name; // eax
  int v4; // edi
  unsigned __int64 Uint64; // kr00_8
  CBaseClient *v6; // eax
  IClient *v7; // eax
  IClient *v8; // esi
  int v9; // edx
  KeyValues *v10; // eax
  KeyValues *v11; // esi
  KeyValues *Copy; // eax
  IMatchEventsSubscription *v14; // eax

  v2 = msg;
  serverGameClients->ClientCommandKeyValues(
    this: serverGameClients,
    a2: (edict_t *)this->m_LastMovementTick,
    a3: msg->m_pKeyValues);
  if ( !NET_IsDedicatedForXbox()
    || (Name = KeyValues::GetName(this: msg->m_pKeyValues), _V_stricmp(s1: Name, s2: "OnPlayerRemovedFromSession") != 0) )
  {
LABEL_12:
    v10 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v10 != nullptr )
      v11 = KeyValues::KeyValues(this: v10, setName: "Server::CmdKeyValues");
    else
      v11 = nullptr;
    Copy = KeyValues::MakeCopy(this: v2->m_pKeyValues);
    KeyValues::AddSubKey(this: v11, pSubkey: Copy);
    KeyValues::SetPtr(this: v11, keyName: "edict", value: (void *)this->m_LastMovementTick);
    v14 = g_pMatchFramework->GetEventsSubscription(this: g_pMatchFramework);
    v14->BroadcastEvent(this: v14, a2: v11);
    return 1;
  }
  v4 = 0;
  Uint64 = KeyValues::GetUint64(this: msg->m_pKeyValues, keyName: "xuid", defaultValue: 0);
  if ( sv.m_Clients.m_Size <= 0 )
  {
LABEL_11:
    v2 = msg;
    goto LABEL_12;
  }
  while ( 1 )
  {
    v6 = sv.m_Clients.m_Memory.m_pMemory[v4];
    if ( v6 != nullptr )
    {
      v7 = &v6->IClient;
      if ( v7 != nullptr )
      {
        v8 = v7 - 1;
        if ( v7 != (IClient *)4
          && Uint64 != 0
          && CBaseClient::GetClientXuid(this: (CBaseClient *)&v7[-1]) == (_DWORD)Uint64
          && v9 == HIDWORD(Uint64) )
        {
          break;
        }
      }
    }
    if ( ++v4 >= sv.m_Clients.m_Size )
      goto LABEL_11;
  }
  v8[1].Disconnect(this: v8 + 1, a2: "Player removed from host session\n");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1011BED0
// Name: public: virtual bool CGameClient::IsHearingClient(int)const
// Source: json
//------------------------------------------------------------------------------
char __thiscall CGameClient::IsHearingClient(CGameClient *this, int index)
{
  CBaseClient *v4; // edi
  unsigned int v5; // eax

  if ( this->CBaseClient::IGameEventListener2::__vftable[1].SendSignonData(this) )
    return 1;
  if ( index == ((int (__thiscall *)(CGameClient *))this->SpawnPlayer)(a1: this) )
    return this->m_ClientFramePool.m_BlobHead.m_Data[0];
  v4 = sv.m_Clients.m_Memory.m_pMemory[index];
  if ( (ss_voice_hearpartner.m_pParent == nullptr || ss_voice_hearpartner.m_pParent->m_Value.m_nValue == 0)
    && CBaseClient::IsSplitScreenPartner(
         this: (CGameClient *)((char *)this - 4),
         pOther: sv.m_Clients.m_Memory.m_pMemory[index]) )
  {
    return 0;
  }
  v5 = ((int (__thiscall *)(CGameClient *))this->SpawnPlayer)(a1: this);
  return (*(_DWORD *)&v4[1].m_Name[4 * (v5 >> 5) + 8] & (1 << (v5 & 0x1F))) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x1011BF60
// Name: public: virtual bool CGameClient::IsProximityHearingClient(int)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CGameClient::IsProximityHearingClient(CGameClient *this, int index)
{
  CBaseClient *v2; // esi
  unsigned int v3; // eax

  v2 = sv.m_Clients.m_Memory.m_pMemory[index];
  v3 = ((int (__thiscall *)(CGameClient *))this->SpawnPlayer)(a1: this);
  return (*(_DWORD *)&v2[1].m_Name[4 * (v3 >> 5) + 16] & (1 << (v3 & 0x1F))) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x1011BFA0
// Name: protected: virtual void CGameClient::PerformDisconnection(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameClient::PerformDisconnection(CGameClient *this, const char *pReason)
{
  IGameEvent *v3; // eax
  IGameEvent *v4; // esi
  int v5; // eax
  const char *v6; // eax
  int ClientXuid; // eax
  int v8; // edx
  const char *v9; // eax
  IGameEvent_vtbl *v10; // [esp+8h] [ebp-4h]
  IGameEvent_vtbl *v11; // [esp+8h] [ebp-4h]
  IGameEvent_vtbl *v12; // [esp+8h] [ebp-4h]
  IGameEvent_vtbl *v13; // [esp+8h] [ebp-4h]

  v3 = g_GameEventManager->CreateEventA(this: g_GameEventManager, a2: "player_disconnect", a3: 0, a4: 0);
  v4 = v3;
  if ( v3 != nullptr )
  {
    v10 = v3->__vftable;
    v5 = this->GetUserID(this: &this->IClient);
    v10->SetInt(this: v4, a2: "userid", a3: v5);
    v4->SetString(this: v4, a2: "reason", a3: pReason);
    v11 = v4->__vftable;
    v6 = this->GetClientName(this: &this->IClient);
    v11->SetString(this: v4, a2: "name", a3: v6);
    v12 = v4->__vftable;
    ClientXuid = CBaseClient::GetClientXuid(this);
    ((void (__thiscall *)(IGameEvent *, const char *, int, int))v12->SetUint64)(
      a1: v4,
      a2: "xuid",
      a3: ClientXuid,
      a4: v8);
    v13 = v4->__vftable;
    v9 = this->GetNetworkIDString(this: &this->IClient);
    v13->SetString(this: v4, a2: "networkid", a3: v9);
    g_GameEventManager->FireEvent(this: g_GameEventManager, a2: v4, a3: false);
  }
  this->m_Server->RemoveClientFromGame(this: this->m_Server, a2: this);
  CBaseClient::PerformDisconnection(this, pReason);
}

//------------------------------------------------------------------------------
// Address: 0x1011C090
// Name: private: int CGameClient::FillSoundsMessage(class SVC_Sounds __near &,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CGameClient::FillSoundsMessage(CGameClient *this, SVC_Sounds *msg, int nMaxSounds)
{
  int m_Size; // ebx
  int result; // eax
  SVC_Sounds *v6; // edi
  SVC_Sounds_vtbl *v7; // edx
  void (__thiscall *SetReliable)(struct SVC_Sounds *, bool); // eax
  SoundInfo_t *m_pMemory; // eax
  int v10; // edi
  SoundInfo_t *v11; // edx
  bool v12; // zf
  int v13; // eax
  int v14; // edi
  SoundInfo_t defaultSound; // [esp+14h] [ebp-68h] BYREF
  float finalTickTime; // [esp+70h] [ebp-Ch]
  int v17; // [esp+74h] [ebp-8h]
  SoundInfo_t *pDeltaSound; // [esp+78h] [ebp-4h]

  m_Size = this->m_Sounds.m_Size;
  if ( m_Size > nMaxSounds )
    m_Size = nMaxSounds;
  result = 0;
  if ( m_Size != 0 )
  {
    v6 = msg;
    v7 = msg->__vftable;
    defaultSound.nEntityIndex = 0;
    defaultSound.nSoundNum = 0;
    defaultSound.nFlags = 0;
    defaultSound.nSequenceNumber = 0;
    defaultSound.nRandomSeed = 0;
    defaultSound.pszName = nullptr;
    defaultSound.bLooping = false;
    *(_WORD *)&defaultSound.bIsSentence = 0;
    pDeltaSound = &defaultSound;
    msg->m_bReliableSound = false;
    SetReliable = v7->SetReliable;
    defaultSound.fDelay = 0.0;
    defaultSound.fTickTime = 0.0;
    defaultSound.fVolume = 1.0;
    defaultSound.Soundlevel = SNDLVL_NORM;
    defaultSound.nPitch = 100;
    defaultSound.nSpeakerEntity = -1;
    defaultSound.nChannel = 6;
    memset(&defaultSound, 0, 36);
    msg->m_nNumSounds = m_Size;
    SetReliable(this: msg, a2: false);
    finalTickTime = CBaseServer::GetFinalTickTime(this: this->m_Server);
    if ( m_Size > 0 )
    {
      m_pMemory = this->m_Sounds.m_Memory.m_pMemory;
      v10 = 0;
      v17 = m_Size;
      do
      {
        SoundInfo_t::WriteDelta(this: &m_pMemory[v10], delta: pDeltaSound, buffer: &msg->m_DataOut, finalTickTime);
        m_pMemory = this->m_Sounds.m_Memory.m_pMemory;
        v11 = &m_pMemory[v10++];
        v12 = v17-- == 1;
        pDeltaSound = v11;
      }
      while ( !v12 );
      v6 = msg;
    }
    if ( sv_sound_discardextraunreliable.m_pParent != nullptr
      && sv_sound_discardextraunreliable.m_pParent->m_Value.m_nValue != 0 )
    {
      v13 = this->m_Sounds.m_Size;
      if ( v13 != m_Size )
        _DevMsg(a1: 2, a2: "Warning! Dropped %i unreliable sounds for client %s.\n", v13 - m_Size, this->m_Name);
      this->m_Sounds.m_Size = 0;
      return v6->m_nNumSounds;
    }
    else
    {
      v14 = this->m_Sounds.m_Size - m_Size - nMaxSounds;
      if ( v14 > 0 )
      {
        _DevMsg(a1: 2, a2: "Warning! Dropped %i unreliable sounds for client %s.\n", v14, this->m_Name);
        m_Size += v14;
      }
      if ( m_Size > 0 )
      {
        if ( this->m_Sounds.m_Size - m_Size > 0 )
          _V_memmove(
            dest: this->m_Sounds.m_Memory.m_pMemory,
            src: &this->m_Sounds.m_Memory.m_pMemory[m_Size],
            count: 92 * (this->m_Sounds.m_Size - m_Size));
        this->m_Sounds.m_Size -= m_Size;
      }
      return msg->m_nNumSounds;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1011C250
// Name: public: virtual void CGameClient::SpawnPlayer(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameClient::SpawnPlayer(CGameClient *this)
{
  bool (__thiscall *SendNetMsg)(IClient *, INetMessage *, bool, bool); // edx
  int v3; // eax
  SVC_SetView setView; // [esp+4h] [ebp-14h] BYREF

  if ( sv.m_bLoadgame )
  {
    CBaseServer::SetPaused(this: &sv, paused: false);
  }
  else
  {
    serverGameEnts->FreeContainingEntity(this: serverGameEnts, a2: this->edict);
    InitializeEntityDLLFields(pEdict: this->edict);
  }
  SendNetMsg = this->SendNetMsg;
  v3 = this->m_nClientSlot + 1;
  this->m_nEntityIndex = v3;
  setView.m_nEntityIndex = v3;
  this->m_bIsInReplayMode = false;
  setView.m_bReliable = true;
  setView.m_NetChannel = nullptr;
  setView.__vftable = (SVC_SetView_vtbl *)&SVC_SetView::`vftable';
  SendNetMsg(this: &this->IClient, a2: &setView, a3: false, a4: false);
  CBaseClient::SpawnPlayer(this);
}

//------------------------------------------------------------------------------
// Address: 0x1011C2E0
// Name: public: virtual class CClientFrame __near * CGameClient::GetDeltaFrame(int)
// Source: json
//------------------------------------------------------------------------------
CClientFrame *__thiscall CGameClient::GetDeltaFrame(CGameClient *this, int nTick)
{
  CBaseClient *v3; // eax
  int followEntity; // [esp+4h] [ebp-4h] BYREF

  if ( this->m_bIsInReplayMode
    && (serverGameClients->GetReplayDelay(this: serverGameClients, a2: this->edict, a3: &followEntity),
        (v3 = sv.m_Clients.m_Memory.m_pMemory[followEntity - 1]) != nullptr) )
  {
    return CClientFrameManager::GetClientFrame(this: (CClientFrameManager *)&v3[1], nTick, bExact: true);
  }
  else
  {
    return CClientFrameManager::GetClientFrame(this: &this->CClientFrameManager, nTick, bExact: true);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1011C350
// Name: public: virtual void CGameClient::SendSnapshot(class CClientFrame __near *)
// Source: json
//------------------------------------------------------------------------------
// bad sp value at call has been detected, the output may be wrong!
void __thiscall CGameClient::SendSnapshot(CGameClient *this, CClientFrame *pFrame)
{
  int v3; // eax
  void *v4; // esp
  int m_nValue; // eax
  int v6; // eax
  CBaseServer_vtbl *v7; // ebx
  CBaseServer *v8; // edi
  bf_write *Buffer; // eax
  CFrameSnapshot *v10; // edi
  CFrameSnapshot *v11; // ecx
  int v12; // [esp-17694h] [ebp-17700h]
  _DWORD v13[23975]; // [esp-17690h] [ebp-176FCh] BYREF
  SVC_Sounds sounds; // [esp+Ch] [ebp-60h] BYREF
  CFrameSnapshot *m_pSnapshot; // [esp+64h] [ebp-8h]
  CFrameSnapshot *m_pObj; // [esp+68h] [ebp-4h]
  int savedregs; // [esp+6Ch] [ebp+0h]

  if ( this->m_bIsHLTV )
  {
    v3 = ((int (__thiscall *)(IClient *, _DWORD, _DWORD, _DWORD, SVC_Sounds_vtbl *, _DWORD, INetChannel *, IServerMessageHandler *, _DWORD, int, int, const char *, _DWORD, int, unsigned int, unsigned int, int, const unsigned int *, const unsigned int *, const unsigned int *, unsigned __int8 *, int, int, int, _DWORD, const char *, CFrameSnapshot *, CFrameSnapshot *, int))this->GetMaxAckTickCount)(
           a1: &this->IClient,
           a2: v13[23972],
           a3: v13[23973],
           a4: v13[23974],
           a5: sounds.__vftable,
           a6: *(_DWORD *)&sounds.m_bReliable,
           a7: sounds.m_NetChannel,
           a8: sounds.m_pMessageHandler,
           a9: *(_DWORD *)&sounds.m_bReliableSound,
           a10: sounds.m_nNumSounds,
           a11: sounds.m_nLength,
           a12: sounds.m_DataIn.m_pDebugName,
           a13: *(_DWORD *)&sounds.m_DataIn.m_bOverflow,
           a14: sounds.m_DataIn.m_nDataBits,
           a15: sounds.m_DataIn.m_nDataBytes,
           a16: sounds.m_DataIn.m_nInBufWord,
           a17: sounds.m_DataIn.m_nBitsAvail,
           a18: sounds.m_DataIn.m_pDataIn,
           a19: sounds.m_DataIn.m_pBufferEnd,
           a20: sounds.m_DataIn.m_pData,
           a21: sounds.m_DataOut.m_pData,
           a22: sounds.m_DataOut.m_nDataBytes,
           a23: sounds.m_DataOut.m_nDataBits,
           a24: sounds.m_DataOut.m_iCurBit,
           a25: *(_DWORD *)&sounds.m_DataOut.m_bOverflow,
           a26: sounds.m_DataOut.m_pDebugName,
           a27: m_pSnapshot,
           a28: m_pObj,
           a29: savedregs);
    CNetworkStringTableContainer::DirectUpdate(this: networkStringTableContainerServer, tick_ack: v3);
    v4 = alloca(96000);
    if ( this->m_Sounds.m_Size > 0 )
    {
      sounds.m_bReliable = true;
      sounds.m_NetChannel = nullptr;
      sounds.__vftable = (SVC_Sounds_vtbl *)&SVC_Sounds::`vftable';
      sounds.m_DataIn.m_bOverflow = false;
      sounds.m_DataIn.m_pDebugName = nullptr;
      sounds.m_DataIn.m_nDataBits = -1;
      sounds.m_DataIn.m_nDataBytes = 0;
      bf_write::bf_write(this: &sounds.m_DataOut);
      bf_write::StartWriting(this: &sounds.m_DataOut, pData: v13, nBytes: 96000, iStartBit: 0, nBits: -1);
      if ( this->m_Server->IsMultiplayer(this: this->m_Server) )
      {
        if ( sv_multiplayer_maxsounds.m_pParent != nullptr )
          m_nValue = sv_multiplayer_maxsounds.m_pParent->m_Value.m_nValue;
        else
          m_nValue = 0;
      }
      else
      {
        m_nValue = 255;
      }
      CGameClient::FillSoundsMessage(this, msg: &sounds, nMaxSounds: m_nValue);
      CHLTVServer::SendNetMsg(this: hltv, msg: &sounds, bForceReliable: false, bVoice: false);
    }
    if ( tv_transmitall.m_pParent != nullptr )
      v6 = tv_transmitall.m_pParent->m_Value.m_nValue;
    else
      v6 = 0;
    m_pObj = this->m_pLastSnapshot.m_pObj;
    v7 = hltv->CBaseServer::IServer::IConnectionlessPacketHandler::__vftable;
    v12 = v6 != 0 ? 255 : 64;
    v8 = &hltv->CBaseServer;
    m_pSnapshot = pFrame->m_pSnapshot;
    Buffer = CHLTVServer::GetBuffer(this: hltv, nBuffer: 5);
    v7->WriteTempEntities(this: v8, a2: this, a3: m_pSnapshot, a4: m_pObj, a5: Buffer, a6: v12);
    CHLTVServer::AddNewFrame(this: hltv, clientFrame: pFrame);
    v10 = pFrame->m_pSnapshot;
    if ( v10 != this->m_pLastSnapshot.m_pObj )
    {
      if ( v10 != nullptr )
        CFrameSnapshot::AddReference(this: pFrame->m_pSnapshot);
      v11 = this->m_pLastSnapshot.m_pObj;
      if ( v11 != nullptr )
        CFrameSnapshot::ReleaseReference(this: v11);
      this->m_pLastSnapshot.m_pObj = v10;
    }
    this->UpdateAcknowledgedFramecount(this, a2: pFrame->tick_count);
  }
  else
  {
    CGameClient::WriteViewAngleUpdate(this);
    CBaseClient::SendSnapshot(this, a2: 0, pFrame);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1011C4E0
// Name: public: class CClientFrame __near * CGameClient::GetSendFrame(void)
// Source: json
//------------------------------------------------------------------------------
CClientFrame *__thiscall CGameClient::GetSendFrame(CGameClient *this)
{
  CClientFrame *m_pCurrentFrame; // edi
  int v3; // eax
  int v4; // edx
  CBaseClient *v5; // ecx
  int followEntity; // [esp+0h] [ebp-4h] BYREF

  followEntity = (int)this;
  m_pCurrentFrame = this->m_pCurrentFrame;
  if ( sv_maxreplay.m_pParent->m_Value.m_fValue > 0.0 )
  {
    v3 = serverGameClients->GetReplayDelay(this: serverGameClients, a2: this->edict, a3: &followEntity);
    v4 = followEntity;
    if ( v3 > 0 != this->m_bIsInReplayMode )
    {
      this->m_nDeltaTick = -1;
      this->m_bIsInReplayMode = v3 > 0;
      if ( v3 <= 0 )
      {
        this->m_nEntityIndex = this->m_nClientSlot + 1;
        return m_pCurrentFrame;
      }
      this->m_nEntityIndex = v4;
    }
    if ( v3 > 0 )
    {
      v5 = sv.m_Clients.m_Memory.m_pMemory[v4 - 1];
      if ( v5 == nullptr )
        return nullptr;
      m_pCurrentFrame = CClientFrameManager::GetClientFrame(
                          this: (CClientFrameManager *)&v5[1],
                          nTick: sv.m_nTickCount - v3,
                          bExact: false);
      if ( m_pCurrentFrame == nullptr || this->m_pLastSnapshot.m_pObj == m_pCurrentFrame->m_pSnapshot )
        return nullptr;
    }
  }
  return m_pCurrentFrame;
}

//------------------------------------------------------------------------------
// Address: 0x1011C610
// Name: public: void CGameClient::SetupPackInfo(class CFrameSnapshot __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameClient::SetupPackInfo(CGameClient *this, CFrameSnapshot *pSnapshot)
{
  CClientFrame *Frame; // eax
  IClient_vtbl *v4; // eax
  unsigned __int8 *v5; // eax
  CBitVec<2048> *v6; // edi
  int m_nValue; // edi
  float m_flTimeClientBecameFullyConnected; // xmm1_4
  int v9; // eax
  int i; // edx
  int m_AreasNetworked; // ecx
  int v12; // [esp-4h] [ebp-14h]
  float m_fValue; // [esp+Ch] [ebp-4h]
  float v14; // [esp+Ch] [ebp-4h]
  int nMaxFrames; // [esp+18h] [ebp+8h]
  float nMaxFramesb; // [esp+18h] [ebp+8h]
  float nMaxFramesa; // [esp+18h] [ebp+8h]
  float nMaxFramesc; // [esp+18h] [ebp+8h]

  v12 = (g_BSPData.numclusters + 7) / 8;
  this->m_PackInfo.m_nPVSSize = v12;
  serverGameClients->ClientSetupVisibility(
    this: serverGameClients,
    a2: (edict_t *)this->m_pViewEntity,
    a3: this->m_PackInfo.m_pClientEnt,
    a4: this->m_PackInfo.m_PVS,
    a5: v12);
  Frame = CClientFrameManager::AllocateFrame(this: &this->CClientFrameManager);
  this->m_pCurrentFrame = Frame;
  CClientFrame::Init(this: Frame, pSnapshot);
  v4 = this->CBaseClient::IClient::INetChannelHandler::__vftable;
  this->m_PackInfo.m_pTransmitEdict = &this->m_pCurrentFrame->transmit_entity;
  if ( v4->IsHLTV(this: &this->IClient) )
  {
    v5 = (unsigned __int8 *)MemAlloc_Alloc(nSize: 0x100u);
    v6 = (CBitVec<2048> *)v5;
    if ( v5 != nullptr )
      memset(dst: v5, value: 0, count: 0x100u);
    else
      v6 = nullptr;
    this->m_pCurrentFrame->transmit_always = v6;
    this->m_PackInfo.m_pTransmitAlways = this->m_pCurrentFrame->transmit_always;
  }
  else
  {
    this->m_PackInfo.m_pTransmitAlways = nullptr;
  }
  if ( sv_maxclientframes.m_pParent == nullptr || (m_nValue = sv_maxclientframes.m_pParent->m_Value.m_nValue) <= 128 )
    m_nValue = 128;
  m_flTimeClientBecameFullyConnected = this->m_flTimeClientBecameFullyConnected;
  nMaxFrames = m_nValue;
  if ( m_flTimeClientBecameFullyConnected != -1.0
    && sv_extra_client_connect_time.m_pParent->m_Value.m_fValue > (float)(realtime - m_flTimeClientBecameFullyConnected) )
  {
    m_fValue = sv_extra_client_connect_time.m_pParent->m_Value.m_fValue;
    if ( m_nValue <= (int)(m_fValue
                         / ((double (__thiscall *)(CBaseServer *))this->m_Server->GetTickInterval)(a1: this->m_Server)) )
    {
      nMaxFramesb = sv_extra_client_connect_time.m_pParent->m_Value.m_fValue;
      m_nValue = (int)(nMaxFramesb
                     / ((double (__thiscall *)(CBaseServer *))this->m_Server->GetTickInterval)(a1: this->m_Server));
      nMaxFrames = m_nValue;
    }
  }
  if ( sv_maxreplay.m_pParent->m_Value.m_fValue > 0.0 )
  {
    nMaxFramesa = (float)nMaxFrames;
    v14 = sv_maxreplay.m_pParent->m_Value.m_fValue;
    if ( nMaxFramesa <= v14
                      / ((double (__thiscall *)(CBaseServer *))this->m_Server->GetTickInterval)(a1: this->m_Server) )
    {
      nMaxFramesc = sv_maxreplay.m_pParent->m_Value.m_fValue;
      nMaxFramesa = nMaxFramesc
                  / ((double (__thiscall *)(CBaseServer *))this->m_Server->GetTickInterval)(a1: this->m_Server);
    }
    m_nValue = (int)nMaxFramesa;
  }
  if ( m_nValue < CClientFrameManager::AddClientFrame(this: &this->CClientFrameManager, frame: this->m_pCurrentFrame) )
    CClientFrameManager::RemoveOldestFrame(this: &this->CClientFrameManager);
  v9 = 0;
  this->m_PackInfo.m_AreasNetworked = 0;
  for ( i = g_AreasNetworked.m_Size; v9 < i; ++v9 )
  {
    m_AreasNetworked = this->m_PackInfo.m_AreasNetworked;
    if ( m_AreasNetworked >= 8 )
      break;
    this->m_PackInfo.m_Areas[m_AreasNetworked] = g_AreasNetworked.m_Memory.m_pMemory[v9];
    ++this->m_PackInfo.m_AreasNetworked;
  }
  CM_SetupAreaFloodNums(areaFloodNums: this->m_PackInfo.m_AreaFloodNums, pNumAreas: &this->m_PackInfo.m_nMapAreas);
}

//------------------------------------------------------------------------------
// Address: 0x1011C870
// Name: public: virtual void CGameClient::Inactivate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameClient::Inactivate(CGameClient *this)
{
  _DWORD *m_nSoundSequence; // eax
  bool v3; // sf
  int v4; // eax
  char *v5; // eax
  const char *v6; // eax
  const char *v7; // [esp-4h] [ebp-10h]
  ConVarRef voice_verbose; // [esp+4h] [ebp-8h] BYREF

  m_nSoundSequence = (_DWORD *)this->m_nSoundSequence;
  if ( m_nSoundSequence != nullptr && (*m_nSoundSequence & 2) == 0 )
    (*(void (__thiscall **)(_DWORD, char *))(**(_DWORD **)&this->m_bConVarsChanged + 180))(
      a1: *(_DWORD *)&this->m_bConVarsChanged,
      a2: (char *)this - 4);
  if ( this->CBaseClient::IGameEventListener2::__vftable[1].SendSignonData(this) )
    CHLTVServer::Changelevel(this: hltv);
  CBaseClient::Inactivate(this);
  v3 = this->m_Sounds.m_Memory.m_nAllocationCount < 0;
  this->m_Sounds.m_Memory.m_nGrowSize = 0;
  if ( !v3 )
  {
    if ( this->edict != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->edict);
      this->edict = nullptr;
    }
    this->m_Sounds.m_Memory.m_pMemory = nullptr;
  }
  this->m_Sounds.m_Size = (int)this->edict;
  ConVarRef::ConVarRef(this: &voice_verbose, pName: "voice_verbose");
  if ( voice_verbose.m_pConVarState->m_Value.m_nValue != 0 )
  {
    if ( ((int (__thiscall *)(CGameClient *))this->FreeBaselines)(a1: this) != 0 )
    {
      v4 = ((int (__thiscall *)(CGameClient *))this->FreeBaselines)(a1: this);
      v5 = (char *)(*(int (__thiscall **)(int))(*(_DWORD *)v4 + 4))(a1: v4);
    }
    else
    {
      v5 = &args.m_pArgvBuffer[228];
    }
    v6 = (const char *)((int (__thiscall *)(CGameClient *, char *))this->SetUserCVar)(a1: this, a2: v5);
    _Msg(a1: "* CGameClient::Inactivate:  Clearing m_VoiceStreams/m_VoiceProximity for %s (%s)\n", v6, v7);
  }
  if ( this != (CGameClient *)-120632 )
  {
    *(_DWORD *)&this->m_bVoiceLoopback = 0;
    this->m_VoiceStreams.m_Ints[0] = 0;
  }
  if ( this != (CGameClient *)-120640 )
  {
    this->m_VoiceStreams.m_Ints[1] = 0;
    this->m_VoiceProximity.m_Ints[0] = 0;
  }
  CClientFrameManager::DeleteClientFrames(this: (CClientFrameManager *)&this->m_Trace.m_Records.m_pElements, nTick: -1);
}

//------------------------------------------------------------------------------
// Address: 0x1011C9A0
// Name: public: virtual void CGameClient::Clear(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameClient::Clear(CGameClient *this)
{
  int v2; // eax
  char *v3; // eax
  const char *v4; // eax
  const char *v5; // [esp-4h] [ebp-14h]
  ConVarRef voice_verbose; // [esp+8h] [ebp-8h] BYREF

  if ( LOBYTE(this->m_Server) != 0 )
    hltv->Shutdown(this: &hltv->CBaseServer);
  CBaseClient::Clear(this);
  CClientFrameManager::DeleteClientFrames(this: (CClientFrameManager *)&this->m_Trace.m_Records.m_pElements, nTick: -1);
  this->m_Sounds.m_Memory.m_nGrowSize = 0;
  if ( this->m_Sounds.m_Memory.m_nAllocationCount >= 0 )
  {
    if ( this->edict != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->edict);
      this->edict = nullptr;
    }
    this->m_Sounds.m_Memory.m_pMemory = nullptr;
  }
  this->m_Sounds.m_Size = (int)this->edict;
  ConVarRef::ConVarRef(this: &voice_verbose, pName: "voice_verbose");
  if ( voice_verbose.m_pConVarState->m_Value.m_nValue != 0 )
  {
    if ( ((int (__thiscall *)(CGameClient *))this->FreeBaselines)(a1: this) != 0 )
    {
      v2 = ((int (__thiscall *)(CGameClient *))this->FreeBaselines)(a1: this);
      v3 = (char *)(*(int (__thiscall **)(int))(*(_DWORD *)v2 + 4))(a1: v2);
    }
    else
    {
      v3 = &args.m_pArgvBuffer[228];
    }
    v4 = (const char *)((int (__thiscall *)(CGameClient *, char *))this->SetUserCVar)(a1: this, a2: v3);
    _Msg(a1: "* CGameClient::Clear:  Clearing m_VoiceStreams/m_VoiceProximity for %s (%s)\n", v4, v5);
  }
  if ( this != (CGameClient *)-120632 )
  {
    *(_DWORD *)&this->m_bVoiceLoopback = 0;
    this->m_VoiceStreams.m_Ints[0] = 0;
  }
  if ( this != (CGameClient *)-120640 )
  {
    this->m_VoiceStreams.m_Ints[1] = 0;
    this->m_VoiceProximity.m_Ints[0] = 0;
  }
  this->m_nSoundSequence = 0;
  this->m_Sounds.m_pElements = nullptr;
  this->m_ClientFramePool.m_BlobHead.m_Data[0] = 0;
  this->m_VoiceProximity.m_Ints[1] = 0;
  this->m_LastMovementTick = 0;
  this->m_PrevTransmitEdict.m_Ints[63] = -1082130432;
}

//------------------------------------------------------------------------------
// Address: 0x1011CAD0
// Name: public: virtual void CGameClient::WriteGameSounds(class bf_write __near &,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameClient::WriteGameSounds(CGameClient *this, bf_write *buf, int nMaxSounds)
{
  int v4; // edi
  _BYTE pData[96000]; // [esp+8h] [ebp-17758h] BYREF
  SVC_Sounds msg; // [esp+17708h] [ebp-58h] BYREF

  if ( this->m_Sounds.m_Size > 0 )
  {
    msg.m_bReliable = true;
    msg.m_NetChannel = nullptr;
    msg.__vftable = (SVC_Sounds_vtbl *)&SVC_Sounds::`vftable';
    msg.m_DataIn.m_bOverflow = false;
    msg.m_DataIn.m_pDebugName = nullptr;
    msg.m_DataIn.m_nDataBits = -1;
    msg.m_DataIn.m_nDataBytes = 0;
    bf_write::bf_write(this: &msg.m_DataOut);
    bf_write::StartWriting(this: &msg.m_DataOut, pData, nBytes: 96000, iStartBit: 0, nBits: -1);
    v4 = CGameClient::FillSoundsMessage(this, &msg, nMaxSounds);
    SVC_Sounds::WriteToBuffer(this: &msg, buffer: buf);
    if ( CBaseClient::IsTracing(this) )
      CBaseClient::TraceNetworkData(this, msg: buf, fmt: "Sounds [count=%d]", v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1011CB70
// Name: public: CGameClient::CGameClient(int,class CBaseServer __near *)
// Source: json
//------------------------------------------------------------------------------
CGameClient *__thiscall CGameClient::CGameClient(CGameClient *this, int slot, CBaseServer *pServer)
{
  CBaseClient::CBaseClient(this);
  this->CClientFrameManager::__vftable = (CClientFrameManager_vtbl *)&CClientFrameManager::`vftable';
  CUtlMemoryPool::CUtlMemoryPool(
    this: &this->m_ClientFramePool,
    blockSize: 284,
    numElements: 128,
    growMode: 2,
    pszAllocOwner: nullptr,
    nAlignment: 0);
  this->m_Frames = nullptr;
  this->CBaseClient::IGameEventListener2::__vftable = (CGameClient_vtbl *)&CGameClient::`vftable'{for `IGameEventListener2'};
  this->CBaseClient::IClient::INetChannelHandler::__vftable = (IClient_vtbl *)&CGameClient::`vftable'{for `IClient'};
  this->CBaseClient::IClientMessageHandler::INetMessageHandler::__vftable = (IClientMessageHandler_vtbl *)&CGameClient::`vftable'{for `IClientMessageHandler'};
  this->CClientFrameManager::__vftable = (CClientFrameManager_vtbl *)&CGameClient::`vftable';
  if ( this != (CGameClient *)-120636 )
  {
    this->m_VoiceStreams.m_Ints[0] = 0;
    this->m_VoiceStreams.m_Ints[1] = 0;
  }
  if ( this != (CGameClient *)-120644 )
  {
    this->m_VoiceProximity.m_Ints[0] = 0;
    this->m_VoiceProximity.m_Ints[1] = 0;
  }
  this->m_Sounds.m_Memory.m_pMemory = nullptr;
  this->m_Sounds.m_Memory.m_nAllocationCount = 0;
  this->m_Sounds.m_Memory.m_nGrowSize = 0;
  this->m_Sounds.m_Size = 0;
  this->m_Sounds.m_pElements = nullptr;
  if ( this != (CGameClient *)-137704 )
    memset(dst: (unsigned __int8 *)&this->m_PrevTransmitEdict, value: 0, count: sizeof(this->m_PrevTransmitEdict));
  CGameClient::Clear(this: (CGameClient *)&this->IClient);
  this->m_nClientSlot = slot;
  this->m_nEntityIndex = slot + 1;
  this->m_Server = pServer;
  this->m_pCurrentFrame = nullptr;
  this->m_bIsInReplayMode = false;
  memset(dst: (unsigned __int8 *)&this->m_PrevPackInfo, value: 0, count: sizeof(this->m_PrevPackInfo));
  this->m_PrevPackInfo.m_pTransmitEdict = &this->m_PrevTransmitEdict;
  this->m_flTimeClientBecameFullyConnected = -1.0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1011CCB0
// Name: public: virtual CGameClient::~CGameClient(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameClient::~CGameClient(CGameClient *this)
{
  this->CBaseClient::IGameEventListener2::__vftable = (CGameClient_vtbl *)&CGameClient::`vftable'{for `IGameEventListener2'};
  this->CBaseClient::IClient::INetChannelHandler::__vftable = (IClient_vtbl *)&CGameClient::`vftable'{for `IClient'};
  this->CBaseClient::IClientMessageHandler::INetMessageHandler::__vftable = (IClientMessageHandler_vtbl *)&CGameClient::`vftable'{for `IClientMessageHandler'};
  this->CClientFrameManager::__vftable = (CClientFrameManager_vtbl *)&CGameClient::`vftable';
  CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&this->m_Sounds);
  this->CClientFrameManager::__vftable = (CClientFrameManager_vtbl *)&CClientFrameManager::`vftable';
  CClientFrameManager::DeleteClientFrames(this: &this->CClientFrameManager, nTick: -1);
  CUtlMemoryPool::~CUtlMemoryPool(this: &this->m_ClientFramePool);
  CBaseClient::~CBaseClient(this);
}

//------------------------------------------------------------------------------
// Address: 0x1011CD10
// Name: public: void CGameClient::SendSound(struct SoundInfo_t __near &,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameClient::SendSound(CGameClient *this, SoundInfo_t *sound, bool isReliable)
{
  bool (__thiscall *IsFakeClient)(IClient *); // edx
  IClient *v5; // edi
  const char *pszName; // eax
  const char *v7; // edx
  const char *v8; // ecx
  float finalTickTime; // [esp+0h] [ebp-E8h]
  char buffer[32]; // [esp+10h] [ebp-D8h] BYREF
  SVC_Sounds sndmsg; // [esp+30h] [ebp-B8h] BYREF
  SoundInfo_t defaultSound; // [esp+88h] [ebp-60h] BYREF
  IClient *v13; // [esp+E4h] [ebp-4h]

  IsFakeClient = this->IsFakeClient;
  v5 = &this->IClient;
  v13 = &this->IClient;
  if ( (!IsFakeClient(this: &this->IClient) || v5->IsHLTV(this: v5) || v5->IsSplitScreenUser(this: v5))
    && !this->m_bIsInReplayMode )
  {
    if ( isReliable )
    {
      sndmsg.m_bReliable = true;
      sndmsg.m_NetChannel = nullptr;
      sndmsg.__vftable = (SVC_Sounds_vtbl *)&SVC_Sounds::`vftable';
      sndmsg.m_DataIn.m_bOverflow = false;
      sndmsg.m_DataIn.m_pDebugName = nullptr;
      sndmsg.m_DataIn.m_nDataBits = -1;
      sndmsg.m_DataIn.m_nDataBytes = 0;
      bf_write::bf_write(this: &sndmsg.m_DataOut);
      this->m_nSoundSequence = ((unsigned __int16)this->m_nSoundSequence + 1) & 0x3FF;
      sound->nSequenceNumber = 0;
      bf_write::StartWriting(this: &sndmsg.m_DataOut, pData: buffer, nBytes: 32, iStartBit: 0, nBits: -1);
      sndmsg.m_nNumSounds = 1;
      sndmsg.m_bReliableSound = true;
      memset(&defaultSound.fDelay, 0, 16);
      defaultSound.fVolume = 1.0;
      defaultSound.Soundlevel = SNDLVL_NORM;
      defaultSound.nPitch = 100;
      defaultSound.nSpeakerEntity = -1;
      defaultSound.nChannel = 6;
      defaultSound.nSoundNum = 0;
      defaultSound.nFlags = 0;
      defaultSound.nRandomSeed = 0;
      defaultSound.bLooping = false;
      *(_WORD *)&defaultSound.bIsSentence = 0;
      memset(&defaultSound, 0, 40);
      SoundInfo_t::SetDefault(this: &defaultSound);
      finalTickTime = CBaseServer::GetFinalTickTime(this: &sv);
      SoundInfo_t::WriteDelta(this: sound, delta: &defaultSound, buffer: &sndmsg.m_DataOut, finalTickTime);
      if ( net_showreliablesounds.m_pParent != nullptr && net_showreliablesounds.m_pParent->m_Value.m_nValue != 0 )
      {
        if ( sound->bIsSentence )
        {
          pszName = VOX_SentenceNameFromIndex(sentencenum: sound->nSoundNum);
        }
        else if ( (sound->nFlags & 0x400) != 0 )
        {
          pszName = sound->pszName;
        }
        else
        {
          pszName = CGameServer::GetSound(this: &sv, index: sound->nSoundNum);
        }
        v7 = "sentence";
        if ( !sound->bIsSentence )
          v7 = "sound";
        v8 = " stop";
        if ( (sound->nFlags & 4) == 0 )
          v8 = defaultValue;
        _Warning(
          a1: "reliable%s %s %d/%d/%d/%s\n",
          v8,
          v7,
          sound->nEntityIndex,
          sound->nChannel,
          sound->nSoundNum,
          pszName);
      }
      v13->SendNetMsg(this: v13, a2: &sndmsg, a3: true, a4: false);
    }
    else
    {
      sound->nSequenceNumber = this->m_nSoundSequence;
      CUtlVector<SoundInfo_t,CUtlMemory<SoundInfo_t,int>>::InsertBefore(
        this: &this->m_Sounds,
        elem: this->m_Sounds.m_Size,
        src: sound);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1011CF90
// Name: public: virtual bool CGameClient::SendSignonData(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CGameClient::SendSignonData(CGameClient *this)
{
  INetChannel *m_NetChannel; // ecx
  SVC_ClassInfo classmsg; // [esp+8h] [ebp-2Ch] BYREF

  if ( sv.m_FullSendTables.m_bOverflow )
  {
    Host_Error(error: "Send Table signon buffer overflowed %i bytes!!!\n", (sv.m_FullSendTables.m_iCurBit + 7) >> 3);
    return 0;
  }
  if ( SendTable_GetCRC() == 0 || this->m_nSendtableCRC == SendTable_GetCRC() )
  {
    m_NetChannel = this->m_NetChannel;
    classmsg.m_nNumServerClasses = this->m_Server->serverclasses;
    classmsg.m_bReliable = true;
    classmsg.m_NetChannel = nullptr;
    classmsg.__vftable = (SVC_ClassInfo_vtbl *)&SVC_ClassInfo::`vftable';
    memset(&classmsg.m_Classes, 0, sizeof(classmsg.m_Classes));
    classmsg.m_bCreateOnClient = true;
    m_NetChannel->SendNetMsg(this: m_NetChannel, a2: &classmsg, a3: false, a4: false);
    CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&classmsg.m_Classes);
  }
  else
  {
    if ( sv_sendtables.m_pParent == nullptr || sv_sendtables.m_pParent->m_Value.m_nValue == 0 )
    {
      this->Disconnect(this: &this->IClient, a2: "Server uses different class tables");
      return 0;
    }
    _ConDMsg(a1: "Client sent different SendTable CRC, sending full tables.\n");
    this->m_NetChannel->SendData(this: this->m_NetChannel, a2: &sv.m_FullSendTables, a3: true);
  }
  if ( !CBaseClient::SendSignonData(this) )
    return 0;
  this->m_nSoundSequence = 1;
  return 1;
}

} // namespace engine_xlsp
