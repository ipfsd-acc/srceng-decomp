// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: engine/hltvclient.cpp
// Functions: 19
// ============================================================

#include "engine\hltvclient.h"

//------------------------------------------------------------------------------
// Address: 0x1017CF20
// Name: public: CHLTVClient::CHLTVClient(int,class CBaseServer __near *)
// Source: json
//------------------------------------------------------------------------------
CHLTVClient *__thiscall CHLTVClient::CHLTVClient(CHLTVClient *this, int slot, CBaseServer *pServer)
{
  CHLTVServer *v4; // eax
  int v5; // eax
  int m_nValue; // ecx

  CBaseClient::CBaseClient(this);
  this->CBaseClient::IGameEventListener2::__vftable = (CHLTVClient_vtbl *)&CHLTVClient::`vftable'{for `IGameEventListener2'};
  this->CBaseClient::IClient::INetChannelHandler::__vftable = (IClient_vtbl *)&CHLTVClient::`vftable'{for `IClient'};
  this->CBaseClient::IClientMessageHandler::INetMessageHandler::__vftable = (IClientMessageHandler_vtbl *)&CHLTVClient::`vftable'{for `IClientMessageHandler'};
  CBaseClient::Clear(this: (CBaseClient *)&this->IClient);
  this->m_nClientSlot = slot;
  this->m_Server = pServer;
  v4 = (CHLTVServer *)__RTDynamicCast(
                        inptr: pServer,
                        VfDelta: 0,
                        SrcType: &CBaseServer `RTTI Type Descriptor',
                        TargetType: &CHLTVServer `RTTI Type Descriptor',
                        isReference: 0);
  this->m_pHLTV = v4;
  v5 = v4->GetHLTVSlot(this: &v4->IHLTVServer);
  this->m_fLastSendTime = 0.0;
  this->m_flLastChatTime = 0.0;
  this->m_nEntityIndex = v5 + 1;
  this->m_nLastSendTick = 0;
  this->m_bNoChat = false;
  if ( tv_chatgroupsize.m_pParent != nullptr && (m_nValue = tv_chatgroupsize.m_pParent->m_Value.m_nValue) > 0 )
  {
    V_snprintf(pDest: this->m_szChatGroup, maxLen: 64, pFormat: "group%d", slot % m_nValue);
    return this;
  }
  else
  {
    V_strncpy(pDest: this->m_szChatGroup, pSrc: "all", maxLen: 64);
    return this;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1017D000
// Name: public: virtual bool CHLTVClient::ProcessClientInfo(class CLC_ClientInfo __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CHLTVClient::ProcessClientInfo(CHLTVClient *this, CLC_ClientInfo *msg)
{
  return CBaseClient::ProcessClientInfo(this, msg) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x1017D030
// Name: public: virtual void CHLTVClient::ConnectionClosing(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHLTVClient::ConnectionClosing(CHLTVClient *this, const char *reason)
{
  const char *v2; // eax

  v2 = reason;
  if ( reason == nullptr )
    v2 = "Connection closing";
  ((void (__cdecl *)(CHLTVClient *, const char *))this->SendSignonData)(a1: this, a2: v2);
}

//------------------------------------------------------------------------------
// Address: 0x1017D050
// Name: public: virtual void CHLTVClient::ConnectionCrashed(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHLTVClient::ConnectionCrashed(CHLTVClient *this, const char *reason)
{
  const char *v2; // eax

  v2 = reason;
  if ( reason == nullptr )
    v2 = "Connection lost";
  ((void (__cdecl *)(CHLTVClient *, const char *))this->SendSignonData)(a1: this, a2: v2);
}

//------------------------------------------------------------------------------
// Address: 0x1017D070
// Name: public: virtual void CHLTVClient::PacketStart(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHLTVClient::PacketStart(CHLTVClient *this, int incoming_sequence, int outgoing_acknowledged)
{
  BYTE1(this->m_nForceWaitForTick) = 1;
}

//------------------------------------------------------------------------------
// Address: 0x1017D080
// Name: public: virtual void CHLTVClient::FileRequested(char const __near *,unsigned int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHLTVClient::FileRequested(
        CHLTVClient *this,
        const char *fileName,
        unsigned int transferID,
        int bIsReplayDemoFile)
{
  DevMsg(a1: "CHLTVClient::FileRequested: %s.\n", fileName);
  (*(void (__thiscall **)(int, const char *, unsigned int, int))(*(_DWORD *)this->m_nFilesDownloaded + 176))(
    a1: this->m_nFilesDownloaded,
    a2: fileName,
    a3: transferID,
    a4: bIsReplayDemoFile);
}

//------------------------------------------------------------------------------
// Address: 0x1017D0C0
// Name: public: virtual void CHLTVClient::FileDenied(char const __near *,unsigned int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHLTVClient::FileDenied(
        CHLTVClient *this,
        const char *fileName,
        unsigned int transferID,
        bool bIsReplayDemoFile)
{
  DevMsg(a1: "CHLTVClient::FileDenied: %s.\n", fileName);
}

//------------------------------------------------------------------------------
// Address: 0x1017D0E0
// Name: public: virtual void CHLTVClient::FileReceived(char const __near *,unsigned int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHLTVClient::FileReceived(
        CHLTVClient *this,
        const char *fileName,
        unsigned int transferID,
        bool bIsReplayDemoFile)
{
  DevMsg(a1: "CHLTVClient::FileReceived: %s.\n", fileName);
}

//------------------------------------------------------------------------------
// Address: 0x1017D100
// Name: public: virtual void CHLTVClient::FileSent(char const __near *,unsigned int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHLTVClient::FileSent(
        CHLTVClient *this,
        const char *fileName,
        unsigned int transferID,
        bool bIsReplayDemoFile)
{
  DevMsg(a1: "CHLTVClient::FileSent: %s.\n", fileName);
}

//------------------------------------------------------------------------------
// Address: 0x1017D120
// Name: public: virtual class CClientFrame __near * CHLTVClient::GetDeltaFrame(int)
// Source: json
//------------------------------------------------------------------------------
CClientFrame *__thiscall CHLTVClient::GetDeltaFrame(CHLTVClient *this, int nTick)
{
  return CHLTVServer::GetDeltaFrame(this: this->m_pHLTV, nTick);
}

//------------------------------------------------------------------------------
// Address: 0x1017D130
// Name: public: virtual bool CHLTVClient::ExecuteStringCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __userpurge CHLTVClient::ExecuteStringCommand@<al>(CHLTVClient *this@<ecx>, int a2@<edi>, char *pCommandString)
{
  char *v3; // ebx
  const char *v5; // edi
  int m_nArgc; // ecx
  const char *v8; // eax
  const char *v9; // eax
  char v10; // al
  int v11; // ecx
  int v12; // eax
  CHLTVClient_vtbl *v13; // ebx
  int v14; // edi
  unsigned __int64 v15; // st7
  int v16; // eax
  int v17; // eax
  int v18; // ecx
  int v19; // edx
  CHLTVClient_vtbl *v20; // edi
  int v21; // ecx
  bool v22; // zf
  int (__thiscall *v23)(int); // eax
  int v24; // eax
  int v25; // edi
  int v26; // ebx
  int v27; // eax
  double v28; // st7
  const char *v29; // eax
  const char *v30; // eax
  _DWORD *v31; // edi
  int (__thiscall *v32)(_DWORD *); // eax
  CHLTVClient_vtbl *v33; // ebx
  int v34; // eax
  int v35; // eax
  double v36; // st7
  const char *v37; // eax
  const char *v38; // [esp+0h] [ebp-6A8h]
  int v39; // [esp+0h] [ebp-6A8h]
  int v41; // [esp+4h] [ebp-6A4h]
  int v42; // [esp+4h] [ebp-6A4h]
  CCommand v43; // [esp+10h] [ebp-698h] BYREF
  char out[12]; // [esp+518h] [ebp-190h] BYREF
  char gd[260]; // [esp+524h] [ebp-184h] BYREF
  char chattext[128]; // [esp+628h] [ebp-80h] BYREF

  v3 = pCommandString;
  if ( CBaseClient::ExecuteStringCommand(this, pCommand: pCommandString) )
    return 1;
  if ( v3 == nullptr )
    return 1;
  if ( *v3 == 0 )
    return 1;
  CCommand::CCommand(this: &v43);
  if ( CCommand::Tokenize(this: &v43, pCommand: v3, pBreakSet: nullptr) == 0 )
    return 1;
  v5 = defaultValue;
  if ( v43.m_nArgc > 0 )
    v5 = v43.m_ppArgv[0];
  if ( _V_stricmp(s1: v5, s2: "spec_next") == 0
    || _V_stricmp(s1: v5, s2: "spec_prev") == 0
    || _V_stricmp(s1: v5, s2: "spec_mode") == 0 )
  {
    ((void (__cdecl *)(CHLTVClient *, const char *))this->CBaseClient::IGameEventListener2::__vftable[1].UpdateUserSettings)(
      a1: this,
      a2: "Camera settings can't be changed during a live broadcast.\n");
    return 1;
  }
  if ( _V_stricmp(s1: v5, s2: "say") == 0 )
  {
    m_nArgc = v43.m_nArgc;
    if ( v43.m_nArgc > 1 )
    {
      pCommandString = (char *)LODWORD(tv_chattimelimit.m_pParent->m_Value.m_fValue);
      if ( *(float *)&pCommandString > 0.0 )
      {
        if ( *(float *)&pCommandString + *(double *)&this->m_szPassword[60] > net_time )
          return 1;
        *(long double *)&this->m_szPassword[60] = net_time;
        v8 = defaultValue;
        if ( m_nArgc > 1 )
          v8 = v43.m_ppArgv[1];
        v9 = (const char *)((int (__thiscall *)(CHLTVClient *, const char *))this->SetUserCVar)(a1: this, a2: v8);
        V_snprintf(pDest: &gd[248], maxLen: 128, pFormat: "%s : %s", v9, v38);
        CHLTVServer::BroadcastLocalChat(
          this: *(CHLTVServer **)&this->m_szChatGroup[63],
          pszChat: &gd[248],
          pszGroup: (const char *)&this->m_flLastChatTime + 5);
        return 1;
      }
      return 1;
    }
  }
  if ( _V_strcmp(s1: v5, s2: "tv_chatgroup") != 0 )
  {
    if ( _V_strcmp(s1: v5, s2: "status") != 0 )
    {
      DevMsg(a1: "CHLTVClient::ExecuteStringCommand: Unknown command %s.\n", v3);
      return 1;
    }
    else
    {
      V_FileBase(in: com_gamedir, out, maxlen: 260);
      v10 = (*(int (__thiscall **)(int, int))(*(_DWORD *)(*(_DWORD *)&this->m_szChatGroup[63] + 520) + 32))(
              a1: *(_DWORD *)&this->m_szChatGroup[63] + 520,
              a2);
      v11 = *(_DWORD *)&this->m_szChatGroup[63] + 520;
      if ( v10 != 0 )
      {
        v12 = (*(int (__thiscall **)(int))(*(_DWORD *)v11 + 8))(a1: v11);
        v13 = this->CBaseClient::IGameEventListener2::__vftable;
        v14 = *(_DWORD *)&this->m_szChatGroup[63];
        *(double *)&v15 = ((double (__thiscall *)(int))*(_DWORD *)(*(_DWORD *)v12 + 28))(a1: v12);
        v16 = (*(int (__thiscall **)(int, _DWORD, _DWORD))(*(_DWORD *)(v14 + 8) + 52))(
                a1: v14 + 8,
                a2: v15,
                a3: HIDWORD(v15));
        ((void (__cdecl *)(CHLTVClient *, const char *, int))v13[1].UpdateUserSettings)(
          a1: this,
          a2: "SourceTV Master \"%s\", delay %.0f\n",
          a3: v16);
      }
      else
      {
        v17 = (*(int (__thiscall **)(int))(*(_DWORD *)v11 + 28))(a1: v11);
        v18 = *(_DWORD *)&this->m_szChatGroup[63];
        v19 = *(_DWORD *)(v18 + 8);
        v20 = this->CBaseClient::IGameEventListener2::__vftable;
        v21 = v18 + 8;
        v22 = v17 == 0;
        v23 = *(int (__thiscall **)(int))(v19 + 52);
        if ( v22 )
        {
          v42 = v23(a1: v21);
          ((void (__cdecl *)(CHLTVClient *, const char *, int))v20[1].UpdateUserSettings)(
            a1: this,
            a2: "SourceTV Relay \"%s\", not connect.\n",
            a3: v42);
        }
        else
        {
          v41 = v23(a1: v21);
          ((void (__cdecl *)(CHLTVClient *, const char *, int))v20[1].UpdateUserSettings)(
            a1: this,
            a2: "SourceTV Relay \"%s\", connected.\n",
            a3: v41);
        }
      }
      v24 = *(_DWORD *)&this->m_szChatGroup[63];
      *(_DWORD *)&chattext[124] = this->CBaseClient::IGameEventListener2::__vftable;
      v25 = v24 + 520;
      v26 = v24;
      v27 = build_number();
      v28 = ((double (__thiscall *)(int, int))*(_DWORD *)(*(_DWORD *)v25 + 16))(a1: v25, a2: v27);
      v29 = COM_FormatSeconds(seconds: (int)v28);
      v39 = (*(int (__thiscall **)(int, const char *))(*(_DWORD *)(v26 + 8) + 32))(a1: v26 + 8, a2: v29);
      v30 = netadr_s::ToString(this: &net_local_adr, baseOnly: true);
      (*(void (**)(CHLTVClient *, const char *, ...))(*(_DWORD *)&chattext[124] + 120))(
        a1: this,
        a2: "IP %s:%i, Online %s, Version %i (%s)\n",
        v30,
        v39,
        "Win32");
      v31 = *(_DWORD **)&this->m_szChatGroup[63];
      v32 = *(int (__thiscall **)(_DWORD *))(v31[2] + 76);
      v33 = this->CBaseClient::IGameEventListener2::__vftable;
      v31 += 2;
      v34 = v32(a1: v31);
      v35 = (*(int (__thiscall **)(_DWORD *, int))(*v31 + 56))(a1: v31, a2: v34);
      v36 = ((double (__thiscall *)(_DWORD *, char *, int))*(_DWORD *)(*v31 + 36))(a1: v31, a2: out, a3: v35);
      v37 = COM_FormatSeconds(seconds: (int)v36);
      ((void (__cdecl *)(CHLTVClient *, const char *, const char *))v33[1].UpdateUserSettings)(
        a1: this,
        a2: "Game Time %s, Mod \"%s\", Map \"%s\", Players %i\n",
        a3: v37);
      (*(void (__thiscall **)(int, char **, char *, char *))(*(_DWORD *)(*(_DWORD *)&this->m_szChatGroup[63] + 520) + 20))(
        a1: *(_DWORD *)&this->m_szChatGroup[63] + 520,
        a2: &pCommandString,
        a3: &chattext[120],
        a4: &chattext[116]);
      ((void (*)(CHLTVClient *, const char *, ...))this->CBaseClient::IGameEventListener2::__vftable[1].UpdateUserSettings)(
        a1: this,
        a2: "Local Slots %i, Spectators %i, Proxies %i\n",
        *(_DWORD *)&chattext[120],
        *(_DWORD *)&chattext[116] - (_DWORD)pCommandString,
        pCommandString);
      (*(void (__thiscall **)(int, char **, char *, char *))(*(_DWORD *)(*(_DWORD *)&this->m_szChatGroup[63] + 520) + 24))(
        a1: *(_DWORD *)&this->m_szChatGroup[63] + 520,
        a2: &pCommandString,
        a3: &chattext[120],
        a4: &chattext[116]);
      ((void (*)(CHLTVClient *, const char *, ...))this->CBaseClient::IGameEventListener2::__vftable[1].UpdateUserSettings)(
        a1: this,
        a2: "Total Slots %i, Spectators %i, Proxies %i\n",
        *(_DWORD *)&chattext[120],
        *(_DWORD *)&chattext[116] - (_DWORD)pCommandString,
        pCommandString);
      return 1;
    }
  }
  else
  {
    if ( v43.m_nArgc <= 1 )
      ((void (*)(CHLTVClient *, const char *, ...))this->CBaseClient::IGameEventListener2::__vftable[1].UpdateUserSettings)(
        a1: this,
        a2: "Your current chat group is \"%s\"\n",
        (char *)&this->m_flLastChatTime + 5);
    else
      V_strncpy(pDest: (char *)&this->m_flLastChatTime + 5, pSrc: v43.m_ppArgv[1], maxLen: 64);
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1017D530
// Name: public: virtual bool CHLTVClient::ShouldSendMessages(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CHLTVClient::ShouldSendMessages(CHLTVClient *this)
{
  IClient *v2; // edi
  CBaseServer *m_Server; // edx
  int m_nLastSendTick; // eax
  bool v6; // bl

  v2 = &this->IClient;
  if ( !this->IsActive(this: &this->IClient) )
    return CBaseClient::ShouldSendMessages(this);
  if ( this->m_NetChannel->IsOverflowed(this: this->m_NetChannel) )
  {
    this->m_NetChannel->Reset(this: this->m_NetChannel);
    v2->Disconnect(this: v2, a2: "%s overflowed reliable buffer\n", this->m_Name);
    return false;
  }
  m_Server = this->m_Server;
  m_nLastSendTick = this->m_nLastSendTick;
  v6 = m_nLastSendTick != m_Server->m_nTickCount;
  if ( m_nLastSendTick != m_Server->m_nTickCount )
    goto LABEL_8;
  if ( net_time > this->m_fLastSendTime + 2.0 )
  {
    v6 = true;
LABEL_8:
    if ( !this->m_NetChannel->CanPacket(this: this->m_NetChannel) )
      return false;
  }
  return v6;
}

//------------------------------------------------------------------------------
// Address: 0x1017D5E0
// Name: public: virtual void CHLTVClient::SetUpdateRate(int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHLTVClient::SetUpdateRate(CHLTVClient *this, int udpaterate, bool bForce)
{
  HIDWORD(this->m_fNextMessageTime) = 1008981770;
}

//------------------------------------------------------------------------------
// Address: 0x1017D600
// Name: public: virtual bool CHLTVClient::ProcessSetConVar(class NET_SetConVar __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CHLTVClient::ProcessSetConVar(CHLTVClient *this, NET_SetConVar *msg)
{
  char result; // al
  bool v4; // al
  char *v5; // edi
  char *m_pszString; // eax
  const char *v7; // eax
  int v8; // edi
  int v9; // eax

  result = CBaseClient::ProcessSetConVar(this, msg);
  if ( result != 0 )
  {
    if ( this->m_nFilesDownloaded == 2 )
    {
      v4 = KeyValues::GetInt(this: *(KeyValues **)&this->m_FriendsName[24], keyName: "tv_relay", defaultValue: 0) != 0;
      this->m_bConVarsChanged = v4;
      if ( !v4 )
      {
        if ( !CHLTVServer::DispatchToRelay(
                this: *(CHLTVServer **)&this->m_szChatGroup[59],
                pClient: (CHLTVClient *)((char *)this - 8)) )
        {
          v7 = (const char *)(*(int (__thiscall **)(int))(*(_DWORD *)(*(_DWORD *)&this->m_szChatGroup[59] + 8) + 116))(a1: *(_DWORD *)&this->m_szChatGroup[59] + 8);
          if ( v7 != nullptr && _V_stricmp(s1: (const char *)&this->m_fLastSendTime, s2: v7) != 0 )
          {
            (*(void (__cdecl **)(char *, const char *))(*((_DWORD *)this - 1) + 52))(
              a1: (char *)this - 4,
              a2: "Bad spectator password");
            return 0;
          }
          v8 = *(_DWORD *)(*(_DWORD *)&this->m_szChatGroup[59] + 8);
          v9 = (*(int (__thiscall **)(unsigned int, int))(*(_DWORD *)this->m_nCustomFiles[3].reqID + 196))(
                 a1: this->m_nCustomFiles[3].reqID,
                 a2: 2);
          if ( (*(unsigned __int8 (__thiscall **)(int, int))(v8 + 200))(
                 a1: *(_DWORD *)&this->m_szChatGroup[59] + 8,
                 a2: v9) != 0 )
            return 1;
          (*(void (__cdecl **)(char *, const char *))(*((_DWORD *)this - 1) + 52))(
            a1: (char *)this - 4,
            a2: "SourceTV server is restricted to local spectators (class C).\n");
        }
        return 0;
      }
      if ( (tv_relaypassword.m_nFlags & 0x1000) != 0 )
      {
        v5 = "FCVAR_NEVER_AS_STRING";
        goto LABEL_8;
      }
      m_pszString = tv_relaypassword.m_pParent->m_Value.m_pszString;
      if ( m_pszString != nullptr )
      {
        v5 = tv_relaypassword.m_pParent->m_Value.m_pszString;
        if ( *m_pszString != 0 )
        {
LABEL_8:
          if ( _V_stricmp(s1: v5, s2: "none") != 0 && _V_stricmp(s1: (const char *)&this->m_fLastSendTime, s2: v5) != 0 )
          {
            (*(void (__cdecl **)(char *, const char *))(*((_DWORD *)this - 1) + 52))(
              a1: (char *)this - 4,
              a2: "Bad relay password");
            return 0;
          }
        }
      }
    }
    return 1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1017D780
// Name: public: virtual void CHLTVClient::UpdateUserSettings(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHLTVClient::UpdateUserSettings(CHLTVClient *this)
{
  this->m_bNoChat = KeyValues::GetInt(this: this->m_ConVars, keyName: "tv_nochat", defaultValue: 0) != 0;
  CBaseClient::UpdateUserSettings(this);
}

//------------------------------------------------------------------------------
// Address: 0x1017D810
// Name: public: virtual void CHLTVClient::SpawnPlayer(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHLTVClient::SpawnPlayer(CHLTVClient *this)
{
  bool (__thiscall *SendNetMsg)(IClient *, INetMessage *, bool, bool); // edx
  SVC_SetView setView; // [esp+4h] [ebp-14h] BYREF

  SendNetMsg = this->SendNetMsg;
  setView.m_nEntityIndex = this->m_pHLTV->m_nViewEntity;
  setView.m_bReliable = true;
  setView.m_NetChannel = nullptr;
  setView.__vftable = (SVC_SetView_vtbl *)&SVC_SetView::`vftable';
  SendNetMsg(this: &this->IClient, a2: &setView, a3: false, a4: false);
  CHLTVServer::BroadcastLocalTitle(this: this->m_pHLTV, client: this);
  this->m_flLastChatTime = net_time;
  CBaseClient::SpawnPlayer(this);
}

//------------------------------------------------------------------------------
// Address: 0x1017D880
// Name: public: virtual void CHLTVClient::SetRate(int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHLTVClient::SetRate(CHLTVClient *this, int nRate, bool bForce)
{
  int m_nValue; // eax

  if ( bForce )
    goto LABEL_12;
  if ( LOBYTE(this->m_Server) != 0 )
  {
    m_nValue = nRate;
    if ( nRate < 1000 )
    {
LABEL_4:
      CBaseClient::SetRate(this, nRate: 1000, bForce: false);
      return;
    }
    if ( nRate > 30000 )
    {
      CBaseClient::SetRate(this, nRate: 30000, bForce: false);
      return;
    }
    goto LABEL_13;
  }
  if ( tv_maxrate.m_pParent == nullptr || (m_nValue = tv_maxrate.m_pParent->m_Value.m_nValue) <= 0 )
  {
LABEL_12:
    m_nValue = nRate;
  }
  else
  {
    if ( nRate < 1000 )
      goto LABEL_4;
    if ( nRate <= m_nValue )
    {
      CBaseClient::SetRate(this, nRate, bForce: false);
      return;
    }
  }
LABEL_13:
  CBaseClient::SetRate(this, nRate: m_nValue, bForce);
}

//------------------------------------------------------------------------------
// Address: 0x1017D910
// Name: public: virtual void CHLTVClient::SendSnapshot(class CClientFrame __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CHLTVClient::SendSnapshot(CHLTVClient *this@<ecx>, int a2@<ebx>, CClientFrame *pFrame)
{
  CClientFrame *v4; // edi
  int v5; // ebx
  CClientFrame *v6; // eax
  CClientFrame *i; // edi
  int (*GetMaxAckTickCount)(void); // eax
  int v9; // eax
  CFrameSnapshot *m_pSnapshot; // eax
  CFrameSnapshot *m_pObj; // ecx
  bool v12; // zf
  INetChannel *m_NetChannel; // ecx
  bool v14; // al
  _BYTE pData[96000]; // [esp+8h] [ebp-17738h] BYREF
  bf_write buffer; // [esp+17708h] [ebp-38h] BYREF
  NET_Tick v17; // [esp+17720h] [ebp-20h] BYREF
  IClient *v18; // [esp+1773Ch] [ebp-4h]
  CFrameSnapshot *v19; // [esp+17748h] [ebp+8h]

  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "CHLTVClient::SendSnapshot",
    a3: 0,
    a4: "HLTV",
    a5: false,
    a6: 4);
  bf_write::bf_write(this: &buffer, pDebugName: "CHLTVClient::SendSnapshot", pData, nBytes: 96000, nBits: -1);
  v4 = pFrame;
  if ( this->m_pLastSnapshot.m_pObj == pFrame->m_pSnapshot || this->m_nForceWaitForTick > 0 )
  {
    this->m_NetChannel->Transmit(this: this->m_NetChannel, a2: false);
    CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
    return;
  }
  v5 = ((int (__thiscall *)(CHLTVClient *, int, int))this->GetDeltaFrame)(a1: this, a2: this->m_nDeltaTick, a3: a2);
  v6 = this->GetDeltaFrame(this, a2: this->m_nLastSendTick);
  if ( v6 != nullptr )
  {
    for ( i = v6->m_pNext; i != nullptr; i = i->m_pNext )
    {
      if ( i->tick_count > pFrame->tick_count )
        break;
      this->m_NetChannel->SendData(this: this->m_NetChannel, a2: (bf_write *)&i[1].transmit_entity.m_Ints[2], a3: true);
      if ( v5 != 0 )
        this->m_NetChannel->SendData(
          this: this->m_NetChannel,
          a2: (bf_write *)&i[1].transmit_entity.m_Ints[8],
          a3: false);
    }
    v4 = pFrame;
  }
  v17.m_nTick = v4->tick_count;
  v17.m_flHostFrameTime = host_frametime_unbounded;
  v17.m_NetChannel = nullptr;
  v17.__vftable = (NET_Tick_vtbl *)&NET_Tick::`vftable';
  v17.m_bReliable = false;
  v17.m_flHostFrameTimeStdDeviation = host_frametime_stddeviation;
  NET_Tick::WriteToBuffer(this: &v17, &buffer);
  GetMaxAckTickCount = (int (*)(void))this->GetMaxAckTickCount;
  v18 = &this->IClient;
  v9 = GetMaxAckTickCount();
  CNetworkStringTableContainer::WriteUpdateMessage(
    this: this->m_Server->m_StringTables,
    client: nullptr,
    tick_ack: v9,
    buf: &buffer);
  ((void (__thiscall *)(CBaseServer *, CHLTVClient *, CClientFrame *, int))this->m_Server->WriteDeltaEntities)(
    a1: this->m_Server,
    a2: this,
    a3: v4,
    a4: v5);
  if ( !buffer.m_bOverflow )
    goto LABEL_15;
  if ( v5 != 0 )
  {
    ConMsg(a1: "WARNING: msg overflowed for %s\n", this->m_Name);
    bf_write::Reset(this: &buffer);
LABEL_15:
    m_pSnapshot = v4->m_pSnapshot;
    v19 = m_pSnapshot;
    if ( m_pSnapshot != this->m_pLastSnapshot.m_pObj )
    {
      if ( m_pSnapshot != nullptr )
      {
        CFrameSnapshot::AddReference(this: m_pSnapshot);
        m_pSnapshot = v19;
      }
      m_pObj = this->m_pLastSnapshot.m_pObj;
      if ( m_pObj != nullptr )
      {
        CFrameSnapshot::ReleaseReference(this: m_pObj);
        m_pSnapshot = v19;
      }
      this->m_pLastSnapshot.m_pObj = m_pSnapshot;
    }
    v12 = !this->m_bFakePlayer;
    this->m_nLastSendTick = v4->tick_count;
    if ( v12 )
    {
      m_NetChannel = this->m_NetChannel;
      if ( v5 != 0 )
      {
        v14 = m_NetChannel->SendDatagram(this: m_NetChannel, a2: &buffer) > 0;
      }
      else if ( m_NetChannel->SendData(this: m_NetChannel, a2: &buffer, a3: true)
             && this->m_NetChannel->Transmit(this: this->m_NetChannel, a2: false) )
      {
        v14 = true;
        this->m_nForceWaitForTick = v4->tick_count;
      }
      else
      {
        v14 = false;
        this->m_nForceWaitForTick = v4->tick_count;
      }
      if ( !v14 )
        v18->Disconnect(this: v18, a2: "ERROR! Couldn't send snapshot.");
    }
    else
    {
      this->m_nDeltaTick = v4->tick_count;
    }
    goto LABEL_31;
  }
  v18->Disconnect(this: v18, a2: "ERROR! Reliable snapshot overflow.");
LABEL_31:
  v17.__vftable = (NET_Tick_vtbl *)&INetMessage::`vftable';
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
}

//------------------------------------------------------------------------------
// Address: 0x1017DBB0
// Name: public: virtual bool CHLTVClient::SendSignonData(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CHLTVClient::SendSignonData(CHLTVClient *this)
{
  INetChannel *m_NetChannel; // ecx
  SVC_ClassInfo classmsg; // [esp+4h] [ebp-2Ch] BYREF

  if ( this->m_nSendtableCRC == SendTable_GetCRC() )
  {
    classmsg.m_nNumServerClasses = this->m_Server->serverclasses;
    m_NetChannel = this->m_NetChannel;
    classmsg.m_bReliable = true;
    classmsg.m_NetChannel = nullptr;
    memset(&classmsg.m_Classes, 0, sizeof(classmsg.m_Classes));
    classmsg.m_bCreateOnClient = true;
    classmsg.__vftable = (SVC_ClassInfo_vtbl *)&SVC_ClassInfo::`vftable';
    m_NetChannel->SendNetMsg(this: m_NetChannel, a2: &classmsg, a3: false, a4: false);
    CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&classmsg.m_Classes);
    return CBaseClient::SendSignonData(this);
  }
  else
  {
    this->Disconnect(this: &this->IClient, a2: "Server uses different class tables");
    return false;
  }
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x1017D2E0
// Name: public: CHLTVClient::CHLTVClient(int,class CBaseServer __near *)
// Source: json
//------------------------------------------------------------------------------
CHLTVClient *__thiscall CHLTVClient::CHLTVClient(CHLTVClient *this, int slot, CBaseServer *pServer)
{
  CHLTVServer *v4; // eax
  int v5; // eax
  int m_nValue; // ecx

  CBaseClient::CBaseClient(this);
  this->CBaseClient::IGameEventListener2::__vftable = (CHLTVClient_vtbl *)&CHLTVClient::`vftable'{for `IGameEventListener2'};
  this->CBaseClient::IClient::INetChannelHandler::__vftable = (IClient_vtbl *)&CHLTVClient::`vftable'{for `IClient'};
  this->CBaseClient::IClientMessageHandler::INetMessageHandler::__vftable = (IClientMessageHandler_vtbl *)&CHLTVClient::`vftable'{for `IClientMessageHandler'};
  CBaseClient::Clear(this: (CBaseClient *)&this->IClient);
  this->m_nClientSlot = slot;
  this->m_Server = pServer;
  v4 = (CHLTVServer *)__RTDynamicCast(
                        inptr: pServer,
                        VfDelta: 0,
                        SrcType: &CBaseServer `RTTI Type Descriptor',
                        TargetType: &CHLTVServer `RTTI Type Descriptor',
                        isReference: 0);
  this->m_pHLTV = v4;
  v5 = v4->GetHLTVSlot(this: &v4->IHLTVServer);
  this->m_fLastSendTime = 0.0;
  this->m_flLastChatTime = 0.0;
  this->m_nEntityIndex = v5 + 1;
  this->m_nLastSendTick = 0;
  this->m_bNoChat = false;
  if ( tv_chatgroupsize.m_pParent != nullptr && (m_nValue = tv_chatgroupsize.m_pParent->m_Value.m_nValue) > 0 )
  {
    V_snprintf(pDest: this->m_szChatGroup, maxLen: 64, pFormat: "group%d", slot % m_nValue);
    return this;
  }
  else
  {
    V_strncpy(pDest: this->m_szChatGroup, pSrc: "all", maxLen: 64);
    return this;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1017D3C0
// Name: public: virtual bool CHLTVClient::ProcessClientInfo(class CLC_ClientInfo __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CHLTVClient::ProcessClientInfo(CHLTVClient *this, CLC_ClientInfo *msg)
{
  return CBaseClient::ProcessClientInfo(this, msg) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x1017D3F0
// Name: public: virtual void CHLTVClient::ConnectionClosing(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHLTVClient::ConnectionClosing(CHLTVClient *this, const char *reason)
{
  const char *v2; // eax

  v2 = reason;
  if ( reason == nullptr )
    v2 = "Connection closing";
  ((void (__cdecl *)(CHLTVClient *, const char *))this->SendSignonData)(a1: this, a2: v2);
}

//------------------------------------------------------------------------------
// Address: 0x1017D410
// Name: public: virtual void CHLTVClient::ConnectionCrashed(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHLTVClient::ConnectionCrashed(CHLTVClient *this, const char *reason)
{
  const char *v2; // eax

  v2 = reason;
  if ( reason == nullptr )
    v2 = "Connection lost";
  ((void (__cdecl *)(CHLTVClient *, const char *))this->SendSignonData)(a1: this, a2: v2);
}

//------------------------------------------------------------------------------
// Address: 0x1017D430
// Name: public: virtual void CHLTVClient::PacketStart(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHLTVClient::PacketStart(CHLTVClient *this, int incoming_sequence, int outgoing_acknowledged)
{
  BYTE1(this->m_nForceWaitForTick) = 1;
}

//------------------------------------------------------------------------------
// Address: 0x1017D440
// Name: public: virtual void CHLTVClient::FileRequested(char const __near *,unsigned int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHLTVClient::FileRequested(
        CHLTVClient *this,
        const char *fileName,
        unsigned int transferID,
        int bIsReplayDemoFile)
{
  DevMsg(a1: "CHLTVClient::FileRequested: %s.\n", fileName);
  (*(void (__thiscall **)(int, const char *, unsigned int, int))(*(_DWORD *)this->m_nFilesDownloaded + 176))(
    a1: this->m_nFilesDownloaded,
    a2: fileName,
    a3: transferID,
    a4: bIsReplayDemoFile);
}

//------------------------------------------------------------------------------
// Address: 0x1017D480
// Name: public: virtual void CHLTVClient::FileDenied(char const __near *,unsigned int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHLTVClient::FileDenied(
        CHLTVClient *this,
        const char *fileName,
        unsigned int transferID,
        bool bIsReplayDemoFile)
{
  DevMsg(a1: "CHLTVClient::FileDenied: %s.\n", fileName);
}

//------------------------------------------------------------------------------
// Address: 0x1017D4A0
// Name: public: virtual void CHLTVClient::FileReceived(char const __near *,unsigned int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHLTVClient::FileReceived(
        CHLTVClient *this,
        const char *fileName,
        unsigned int transferID,
        bool bIsReplayDemoFile)
{
  DevMsg(a1: "CHLTVClient::FileReceived: %s.\n", fileName);
}

//------------------------------------------------------------------------------
// Address: 0x1017D4C0
// Name: public: virtual void CHLTVClient::FileSent(char const __near *,unsigned int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHLTVClient::FileSent(
        CHLTVClient *this,
        const char *fileName,
        unsigned int transferID,
        bool bIsReplayDemoFile)
{
  DevMsg(a1: "CHLTVClient::FileSent: %s.\n", fileName);
}

//------------------------------------------------------------------------------
// Address: 0x1017D4E0
// Name: public: virtual class CClientFrame __near * CHLTVClient::GetDeltaFrame(int)
// Source: json
//------------------------------------------------------------------------------
CClientFrame *__thiscall CHLTVClient::GetDeltaFrame(CHLTVClient *this, int nTick)
{
  return CHLTVServer::GetDeltaFrame(this: this->m_pHLTV, nTick);
}

//------------------------------------------------------------------------------
// Address: 0x1017D4F0
// Name: public: virtual bool CHLTVClient::ExecuteStringCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __userpurge CHLTVClient::ExecuteStringCommand@<al>(CHLTVClient *this@<ecx>, int a2@<edi>, char *pCommandString)
{
  const char *v3; // ebx
  const char *v5; // edi
  int m_nArgc; // ecx
  const char *v8; // eax
  const char *v9; // eax
  char v10; // al
  int v11; // ecx
  int v12; // eax
  CHLTVClient_vtbl *v13; // ebx
  int v14; // edi
  unsigned __int64 v15; // st7
  int v16; // eax
  int v17; // eax
  int v18; // ecx
  int v19; // edx
  CHLTVClient_vtbl *v20; // edi
  int v21; // ecx
  bool v22; // zf
  int (__thiscall *v23)(int); // eax
  int v24; // eax
  int v25; // edi
  int v26; // ebx
  int v27; // eax
  double v28; // st7
  char *v29; // eax
  const char *v30; // eax
  _DWORD *v31; // edi
  int (__thiscall *v32)(_DWORD *); // eax
  CHLTVClient_vtbl *v33; // ebx
  int v34; // eax
  int v35; // eax
  double v36; // st7
  char *v37; // eax
  const char *v38; // [esp+0h] [ebp-6A8h]
  int v39; // [esp+0h] [ebp-6A8h]
  int v41; // [esp+4h] [ebp-6A4h]
  int v42; // [esp+4h] [ebp-6A4h]
  CCommand v43; // [esp+10h] [ebp-698h] BYREF
  char out[12]; // [esp+518h] [ebp-190h] BYREF
  char gd[260]; // [esp+524h] [ebp-184h] BYREF
  char chattext[128]; // [esp+628h] [ebp-80h] BYREF

  v3 = pCommandString;
  if ( CBaseClient::ExecuteStringCommand(this, pCommand: pCommandString) )
    return 1;
  if ( v3 == nullptr )
    return 1;
  if ( *v3 == 0 )
    return 1;
  CCommand::CCommand(this: &v43);
  if ( !CCommand::Tokenize(this: &v43, pCommand: v3, pBreakSet: nullptr) )
    return 1;
  v5 = defaultValue;
  if ( v43.m_nArgc > 0 )
    v5 = v43.m_ppArgv[0];
  if ( _V_stricmp(s1: v5, s2: "spec_next") == 0
    || _V_stricmp(s1: v5, s2: "spec_prev") == 0
    || _V_stricmp(s1: v5, s2: "spec_mode") == 0 )
  {
    ((void (__cdecl *)(CHLTVClient *, const char *))this->CBaseClient::IGameEventListener2::__vftable[1].UpdateUserSettings)(
      a1: this,
      a2: "Camera settings can't be changed during a live broadcast.\n");
    return 1;
  }
  if ( _V_stricmp(s1: v5, s2: "say") == 0 )
  {
    m_nArgc = v43.m_nArgc;
    if ( v43.m_nArgc > 1 )
    {
      pCommandString = (char *)LODWORD(tv_chattimelimit.m_pParent->m_Value.m_fValue);
      if ( *(float *)&pCommandString > 0.0 )
      {
        if ( *(float *)&pCommandString + *(double *)&this->m_szPassword[60] > net_time )
          return 1;
        *(long double *)&this->m_szPassword[60] = net_time;
        v8 = defaultValue;
        if ( m_nArgc > 1 )
          v8 = v43.m_ppArgv[1];
        v9 = (const char *)((int (__thiscall *)(CHLTVClient *, const char *))this->SetUserCVar)(a1: this, a2: v8);
        V_snprintf(pDest: &gd[248], maxLen: 128, pFormat: "%s : %s", v9, v38);
        CHLTVServer::BroadcastLocalChat(
          this: *(CHLTVServer **)&this->m_szChatGroup[63],
          pszChat: &gd[248],
          pszGroup: (const char *)&this->m_flLastChatTime + 5);
        return 1;
      }
      return 1;
    }
  }
  if ( _V_strcmp(s1: v5, s2: "tv_chatgroup") != 0 )
  {
    if ( _V_strcmp(s1: v5, s2: "status") != 0 )
    {
      DevMsg(a1: "CHLTVClient::ExecuteStringCommand: Unknown command %s.\n", v3);
      return 1;
    }
    else
    {
      V_FileBase(in: com_gamedir, out, maxlen: 260);
      v10 = (*(int (__thiscall **)(int, int))(*(_DWORD *)(*(_DWORD *)&this->m_szChatGroup[63] + 520) + 32))(
              a1: *(_DWORD *)&this->m_szChatGroup[63] + 520,
              a2);
      v11 = *(_DWORD *)&this->m_szChatGroup[63] + 520;
      if ( v10 != 0 )
      {
        v12 = (*(int (__thiscall **)(int))(*(_DWORD *)v11 + 8))(a1: v11);
        v13 = this->CBaseClient::IGameEventListener2::__vftable;
        v14 = *(_DWORD *)&this->m_szChatGroup[63];
        *(double *)&v15 = ((double (__thiscall *)(int))*(_DWORD *)(*(_DWORD *)v12 + 28))(a1: v12);
        v16 = (*(int (__thiscall **)(int, _DWORD, _DWORD))(*(_DWORD *)(v14 + 8) + 52))(
                a1: v14 + 8,
                a2: v15,
                a3: HIDWORD(v15));
        ((void (__cdecl *)(CHLTVClient *, const char *, int))v13[1].UpdateUserSettings)(
          a1: this,
          a2: "SourceTV Master \"%s\", delay %.0f\n",
          a3: v16);
      }
      else
      {
        v17 = (*(int (__thiscall **)(int))(*(_DWORD *)v11 + 28))(a1: v11);
        v18 = *(_DWORD *)&this->m_szChatGroup[63];
        v19 = *(_DWORD *)(v18 + 8);
        v20 = this->CBaseClient::IGameEventListener2::__vftable;
        v21 = v18 + 8;
        v22 = v17 == 0;
        v23 = *(int (__thiscall **)(int))(v19 + 52);
        if ( v22 )
        {
          v42 = v23(a1: v21);
          ((void (__cdecl *)(CHLTVClient *, const char *, int))v20[1].UpdateUserSettings)(
            a1: this,
            a2: "SourceTV Relay \"%s\", not connect.\n",
            a3: v42);
        }
        else
        {
          v41 = v23(a1: v21);
          ((void (__cdecl *)(CHLTVClient *, const char *, int))v20[1].UpdateUserSettings)(
            a1: this,
            a2: "SourceTV Relay \"%s\", connected.\n",
            a3: v41);
        }
      }
      v24 = *(_DWORD *)&this->m_szChatGroup[63];
      *(_DWORD *)&chattext[124] = this->CBaseClient::IGameEventListener2::__vftable;
      v25 = v24 + 520;
      v26 = v24;
      v27 = build_number();
      v28 = ((double (__thiscall *)(int, int))*(_DWORD *)(*(_DWORD *)v25 + 16))(a1: v25, a2: v27);
      v29 = COM_FormatSeconds(seconds: (int)v28);
      v39 = (*(int (__thiscall **)(int, char *))(*(_DWORD *)(v26 + 8) + 32))(a1: v26 + 8, a2: v29);
      v30 = netadr_s::ToString(this: &net_local_adr, baseOnly: true);
      (*(void (**)(CHLTVClient *, const char *, ...))(*(_DWORD *)&chattext[124] + 120))(
        a1: this,
        a2: "IP %s:%i, Online %s, Version %i (%s)\n",
        v30,
        v39,
        "Win32");
      v31 = *(_DWORD **)&this->m_szChatGroup[63];
      v32 = *(int (__thiscall **)(_DWORD *))(v31[2] + 76);
      v33 = this->CBaseClient::IGameEventListener2::__vftable;
      v31 += 2;
      v34 = v32(a1: v31);
      v35 = (*(int (__thiscall **)(_DWORD *, int))(*v31 + 56))(a1: v31, a2: v34);
      v36 = ((double (__thiscall *)(_DWORD *, char *, int))*(_DWORD *)(*v31 + 36))(a1: v31, a2: out, a3: v35);
      v37 = COM_FormatSeconds(seconds: (int)v36);
      ((void (__cdecl *)(CHLTVClient *, const char *, char *))v33[1].UpdateUserSettings)(
        a1: this,
        a2: "Game Time %s, Mod \"%s\", Map \"%s\", Players %i\n",
        a3: v37);
      (*(void (__thiscall **)(int, char **, char *, char *))(*(_DWORD *)(*(_DWORD *)&this->m_szChatGroup[63] + 520) + 20))(
        a1: *(_DWORD *)&this->m_szChatGroup[63] + 520,
        a2: &pCommandString,
        a3: &chattext[120],
        a4: &chattext[116]);
      ((void (*)(CHLTVClient *, const char *, ...))this->CBaseClient::IGameEventListener2::__vftable[1].UpdateUserSettings)(
        a1: this,
        a2: "Local Slots %i, Spectators %i, Proxies %i\n",
        *(_DWORD *)&chattext[120],
        *(_DWORD *)&chattext[116] - (_DWORD)pCommandString,
        pCommandString);
      (*(void (__thiscall **)(int, char **, char *, char *))(*(_DWORD *)(*(_DWORD *)&this->m_szChatGroup[63] + 520) + 24))(
        a1: *(_DWORD *)&this->m_szChatGroup[63] + 520,
        a2: &pCommandString,
        a3: &chattext[120],
        a4: &chattext[116]);
      ((void (*)(CHLTVClient *, const char *, ...))this->CBaseClient::IGameEventListener2::__vftable[1].UpdateUserSettings)(
        a1: this,
        a2: "Total Slots %i, Spectators %i, Proxies %i\n",
        *(_DWORD *)&chattext[120],
        *(_DWORD *)&chattext[116] - (_DWORD)pCommandString,
        pCommandString);
      return 1;
    }
  }
  else
  {
    if ( v43.m_nArgc <= 1 )
      ((void (*)(CHLTVClient *, const char *, ...))this->CBaseClient::IGameEventListener2::__vftable[1].UpdateUserSettings)(
        a1: this,
        a2: "Your current chat group is \"%s\"\n",
        (char *)&this->m_flLastChatTime + 5);
    else
      V_strncpy(pDest: (char *)&this->m_flLastChatTime + 5, pSrc: v43.m_ppArgv[1], maxLen: 64);
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1017D8F0
// Name: public: virtual bool CHLTVClient::ShouldSendMessages(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CHLTVClient::ShouldSendMessages(CHLTVClient *this)
{
  IClient *v2; // edi
  CBaseServer *m_Server; // edx
  int m_nLastSendTick; // eax
  bool v6; // bl

  v2 = &this->IClient;
  if ( !this->IsActive(this: &this->IClient) )
    return CBaseClient::ShouldSendMessages(this);
  if ( this->m_NetChannel->IsOverflowed(this: this->m_NetChannel) )
  {
    this->m_NetChannel->Reset(this: this->m_NetChannel);
    v2->Disconnect(this: v2, a2: "%s overflowed reliable buffer\n", this->m_Name);
    return false;
  }
  m_Server = this->m_Server;
  m_nLastSendTick = this->m_nLastSendTick;
  v6 = m_nLastSendTick != m_Server->m_nTickCount;
  if ( m_nLastSendTick != m_Server->m_nTickCount )
    goto LABEL_8;
  if ( net_time > this->m_fLastSendTime + 2.0 )
  {
    v6 = true;
LABEL_8:
    if ( !this->m_NetChannel->CanPacket(this: this->m_NetChannel) )
      return false;
  }
  return v6;
}

//------------------------------------------------------------------------------
// Address: 0x1017D9A0
// Name: public: virtual void CHLTVClient::SetUpdateRate(int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHLTVClient::SetUpdateRate(CHLTVClient *this, int udpaterate, bool bForce)
{
  HIDWORD(this->m_fNextMessageTime) = 1008981770;
}

//------------------------------------------------------------------------------
// Address: 0x1017D9C0
// Name: public: virtual bool CHLTVClient::ProcessSetConVar(class NET_SetConVar __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CHLTVClient::ProcessSetConVar(CHLTVClient *this, NET_SetConVar *msg)
{
  char result; // al
  bool v4; // al
  char *v5; // edi
  char *m_pszString; // eax
  const char *v7; // eax
  int v8; // edi
  int v9; // eax

  result = CBaseClient::ProcessSetConVar(this, msg);
  if ( result != 0 )
  {
    if ( this->m_nFilesDownloaded == 2 )
    {
      v4 = KeyValues::GetInt(this: *(KeyValues **)&this->m_FriendsName[24], keyName: "tv_relay", defaultValue: 0) != 0;
      this->m_bConVarsChanged = v4;
      if ( !v4 )
      {
        if ( !CHLTVServer::DispatchToRelay(
                this: *(CHLTVServer **)&this->m_szChatGroup[59],
                pClient: (CHLTVClient *)((char *)this - 8)) )
        {
          v7 = (const char *)(*(int (__thiscall **)(int))(*(_DWORD *)(*(_DWORD *)&this->m_szChatGroup[59] + 8) + 116))(a1: *(_DWORD *)&this->m_szChatGroup[59] + 8);
          if ( v7 != nullptr && _V_stricmp(s1: (const char *)&this->m_fLastSendTime, s2: v7) != 0 )
          {
            (*(void (__cdecl **)(char *, const char *))(*((_DWORD *)this - 1) + 52))(
              a1: (char *)this - 4,
              a2: "Bad spectator password");
            return 0;
          }
          v8 = *(_DWORD *)(*(_DWORD *)&this->m_szChatGroup[59] + 8);
          v9 = (*(int (__thiscall **)(unsigned int, int))(*(_DWORD *)this->m_nCustomFiles[3].reqID + 196))(
                 a1: this->m_nCustomFiles[3].reqID,
                 a2: 2);
          if ( (*(unsigned __int8 (__thiscall **)(int, int))(v8 + 200))(
                 a1: *(_DWORD *)&this->m_szChatGroup[59] + 8,
                 a2: v9) != 0 )
            return 1;
          (*(void (__cdecl **)(char *, const char *))(*((_DWORD *)this - 1) + 52))(
            a1: (char *)this - 4,
            a2: "SourceTV server is restricted to local spectators (class C).\n");
        }
        return 0;
      }
      if ( (tv_relaypassword.m_nFlags & 0x1000) != 0 )
      {
        v5 = "FCVAR_NEVER_AS_STRING";
        goto LABEL_8;
      }
      m_pszString = tv_relaypassword.m_pParent->m_Value.m_pszString;
      if ( m_pszString != nullptr )
      {
        v5 = tv_relaypassword.m_pParent->m_Value.m_pszString;
        if ( *m_pszString != 0 )
        {
LABEL_8:
          if ( _V_stricmp(s1: v5, s2: "none") != 0 && _V_stricmp(s1: (const char *)&this->m_fLastSendTime, s2: v5) != 0 )
          {
            (*(void (__cdecl **)(char *, const char *))(*((_DWORD *)this - 1) + 52))(
              a1: (char *)this - 4,
              a2: "Bad relay password");
            return 0;
          }
        }
      }
    }
    return 1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1017DB40
// Name: public: virtual void CHLTVClient::UpdateUserSettings(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHLTVClient::UpdateUserSettings(CHLTVClient *this)
{
  this->m_bNoChat = KeyValues::GetInt(this: this->m_ConVars, keyName: "tv_nochat", defaultValue: 0) != 0;
  CBaseClient::UpdateUserSettings(this);
}

//------------------------------------------------------------------------------
// Address: 0x1017DBD0
// Name: public: virtual void CHLTVClient::SpawnPlayer(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHLTVClient::SpawnPlayer(CHLTVClient *this)
{
  bool (__thiscall *SendNetMsg)(IClient *, INetMessage *, bool, bool); // edx
  SVC_SetView setView; // [esp+4h] [ebp-14h] BYREF

  SendNetMsg = this->SendNetMsg;
  setView.m_nEntityIndex = this->m_pHLTV->m_nViewEntity;
  setView.m_bReliable = true;
  setView.m_NetChannel = nullptr;
  setView.__vftable = (SVC_SetView_vtbl *)&SVC_SetView::`vftable';
  SendNetMsg(this: &this->IClient, a2: &setView, a3: false, a4: false);
  CHLTVServer::BroadcastLocalTitle(this: this->m_pHLTV, client: this);
  this->m_flLastChatTime = net_time;
  CBaseClient::SpawnPlayer(this);
}

//------------------------------------------------------------------------------
// Address: 0x1017DC40
// Name: public: virtual void CHLTVClient::SetRate(int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHLTVClient::SetRate(CHLTVClient *this, int nRate, bool bForce)
{
  int m_nValue; // eax

  if ( bForce )
    goto LABEL_12;
  if ( LOBYTE(this->m_Server) != 0 )
  {
    m_nValue = nRate;
    if ( nRate < 1000 )
    {
LABEL_4:
      CBaseClient::SetRate(this, nRate: 1000, bForce: false);
      return;
    }
    if ( nRate > 30000 )
    {
      CBaseClient::SetRate(this, nRate: 30000, bForce: false);
      return;
    }
    goto LABEL_13;
  }
  if ( tv_maxrate.m_pParent == nullptr || (m_nValue = tv_maxrate.m_pParent->m_Value.m_nValue) <= 0 )
  {
LABEL_12:
    m_nValue = nRate;
  }
  else
  {
    if ( nRate < 1000 )
      goto LABEL_4;
    if ( nRate <= m_nValue )
    {
      CBaseClient::SetRate(this, nRate, bForce: false);
      return;
    }
  }
LABEL_13:
  CBaseClient::SetRate(this, nRate: m_nValue, bForce);
}

//------------------------------------------------------------------------------
// Address: 0x1017DCD0
// Name: public: virtual void CHLTVClient::SendSnapshot(class CClientFrame __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CHLTVClient::SendSnapshot(CHLTVClient *this@<ecx>, int a2@<ebx>, CClientFrame *pFrame)
{
  CClientFrame *v4; // edi
  int v5; // ebx
  CClientFrame *v6; // eax
  CClientFrame *i; // edi
  int (*GetMaxAckTickCount)(void); // eax
  int v9; // eax
  CFrameSnapshot *m_pSnapshot; // eax
  CFrameSnapshot *m_pObj; // ecx
  bool v12; // zf
  INetChannel *m_NetChannel; // ecx
  bool v14; // al
  _BYTE pData[96000]; // [esp+8h] [ebp-17738h] BYREF
  bf_write buffer; // [esp+17708h] [ebp-38h] BYREF
  NET_Tick v17; // [esp+17720h] [ebp-20h] BYREF
  IClient *v18; // [esp+1773Ch] [ebp-4h]
  CFrameSnapshot *v19; // [esp+17748h] [ebp+8h]

  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "CHLTVClient::SendSnapshot",
    a3: 0,
    a4: "HLTV",
    a5: false,
    a6: 4);
  bf_write::bf_write(this: &buffer, pDebugName: "CHLTVClient::SendSnapshot", pData, nBytes: 96000, nBits: -1);
  v4 = pFrame;
  if ( this->m_pLastSnapshot.m_pObj == pFrame->m_pSnapshot || this->m_nForceWaitForTick > 0 )
  {
    this->m_NetChannel->Transmit(this: this->m_NetChannel, a2: false);
    CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
    return;
  }
  v5 = ((int (__thiscall *)(CHLTVClient *, int, int))this->GetDeltaFrame)(a1: this, a2: this->m_nDeltaTick, a3: a2);
  v6 = this->GetDeltaFrame(this, a2: this->m_nLastSendTick);
  if ( v6 != nullptr )
  {
    for ( i = v6->m_pNext; i != nullptr; i = i->m_pNext )
    {
      if ( i->tick_count > pFrame->tick_count )
        break;
      this->m_NetChannel->SendData(this: this->m_NetChannel, a2: (bf_write *)&i[1].transmit_entity.m_Ints[2], a3: true);
      if ( v5 != 0 )
        this->m_NetChannel->SendData(
          this: this->m_NetChannel,
          a2: (bf_write *)&i[1].transmit_entity.m_Ints[8],
          a3: false);
    }
    v4 = pFrame;
  }
  v17.m_nTick = v4->tick_count;
  v17.m_flHostFrameTime = host_frametime_unbounded;
  v17.m_NetChannel = nullptr;
  v17.__vftable = (NET_Tick_vtbl *)&NET_Tick::`vftable';
  v17.m_bReliable = false;
  v17.m_flHostFrameTimeStdDeviation = host_frametime_stddeviation;
  NET_Tick::WriteToBuffer(this: &v17, &buffer);
  GetMaxAckTickCount = (int (*)(void))this->GetMaxAckTickCount;
  v18 = &this->IClient;
  v9 = GetMaxAckTickCount();
  CNetworkStringTableContainer::WriteUpdateMessage(
    this: this->m_Server->m_StringTables,
    client: nullptr,
    tick_ack: v9,
    buf: &buffer);
  ((void (__thiscall *)(CBaseServer *, CHLTVClient *, CClientFrame *, int))this->m_Server->WriteDeltaEntities)(
    a1: this->m_Server,
    a2: this,
    a3: v4,
    a4: v5);
  if ( !buffer.m_bOverflow )
    goto LABEL_15;
  if ( v5 != 0 )
  {
    ConMsg(a1: "WARNING: msg overflowed for %s\n", this->m_Name);
    bf_write::Reset(this: &buffer);
LABEL_15:
    m_pSnapshot = v4->m_pSnapshot;
    v19 = m_pSnapshot;
    if ( m_pSnapshot != this->m_pLastSnapshot.m_pObj )
    {
      if ( m_pSnapshot != nullptr )
      {
        CFrameSnapshot::AddReference(this: m_pSnapshot);
        m_pSnapshot = v19;
      }
      m_pObj = this->m_pLastSnapshot.m_pObj;
      if ( m_pObj != nullptr )
      {
        CFrameSnapshot::ReleaseReference(this: m_pObj);
        m_pSnapshot = v19;
      }
      this->m_pLastSnapshot.m_pObj = m_pSnapshot;
    }
    v12 = !this->m_bFakePlayer;
    this->m_nLastSendTick = v4->tick_count;
    if ( v12 )
    {
      m_NetChannel = this->m_NetChannel;
      if ( v5 != 0 )
      {
        v14 = m_NetChannel->SendDatagram(this: m_NetChannel, a2: &buffer) > 0;
      }
      else if ( m_NetChannel->SendData(this: m_NetChannel, a2: &buffer, a3: true)
             && this->m_NetChannel->Transmit(this: this->m_NetChannel, a2: false) )
      {
        v14 = true;
        this->m_nForceWaitForTick = v4->tick_count;
      }
      else
      {
        v14 = false;
        this->m_nForceWaitForTick = v4->tick_count;
      }
      if ( !v14 )
        v18->Disconnect(this: v18, a2: "ERROR! Couldn't send snapshot.");
    }
    else
    {
      this->m_nDeltaTick = v4->tick_count;
    }
    goto LABEL_31;
  }
  v18->Disconnect(this: v18, a2: "ERROR! Reliable snapshot overflow.");
LABEL_31:
  v17.__vftable = (NET_Tick_vtbl *)&INetMessage::`vftable';
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
}

//------------------------------------------------------------------------------
// Address: 0x1017DF70
// Name: public: virtual bool CHLTVClient::SendSignonData(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CHLTVClient::SendSignonData(CHLTVClient *this)
{
  INetChannel *m_NetChannel; // ecx
  SVC_ClassInfo classmsg; // [esp+4h] [ebp-2Ch] BYREF

  if ( this->m_nSendtableCRC == SendTable_GetCRC() )
  {
    classmsg.m_nNumServerClasses = this->m_Server->serverclasses;
    m_NetChannel = this->m_NetChannel;
    classmsg.m_bReliable = true;
    classmsg.m_NetChannel = nullptr;
    memset(&classmsg.m_Classes, 0, sizeof(classmsg.m_Classes));
    classmsg.m_bCreateOnClient = true;
    classmsg.__vftable = (SVC_ClassInfo_vtbl *)&SVC_ClassInfo::`vftable';
    m_NetChannel->SendNetMsg(this: m_NetChannel, a2: &classmsg, a3: false, a4: false);
    CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&classmsg.m_Classes);
    return CBaseClient::SendSignonData(this);
  }
  else
  {
    this->Disconnect(this: &this->IClient, a2: "Server uses different class tables");
    return false;
  }
}

} // namespace engine_xlsp
