// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: engine/cl_steamauth.cpp
// Functions: 15
// ============================================================

#include "engine\cl_steamauth.h"

//------------------------------------------------------------------------------
// Address: 0x10090CE0
// Name: public: bool CSteamAPIContext::Init(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CSteamAPIContext::Init(CSteamAPIContext *this)
{
  int HSteamPipe; // esi
  int v4; // eax
  ISteamUser *v5; // eax
  int v6; // eax
  ISteamFriends *v7; // eax
  int v8; // eax
  ISteamUtils *v9; // eax
  int v10; // eax
  ISteamMatchmaking *v11; // eax
  int v12; // eax
  ISteamMatchmakingServers *v13; // eax
  int v14; // eax
  ISteamUserStats *v15; // eax
  int v16; // eax
  ISteamApps *v17; // eax
  int v18; // eax
  ISteamNetworking *v19; // eax
  int v20; // eax
  ISteamRemoteStorage *v21; // eax
  int hSteamUser; // [esp+8h] [ebp-4h]

  if ( _SteamClient() == 0 )
    return false;
  hSteamUser = _SteamAPI_GetHSteamUser();
  HSteamPipe = _SteamAPI_GetHSteamPipe();
  v4 = _SteamClient();
  v5 = (ISteamUser *)(*(int (__thiscall **)(int, int, int, const char *))(*(_DWORD *)v4 + 20))(
                       a1: v4,
                       a2: hSteamUser,
                       a3: HSteamPipe,
                       a4: "SteamUser014");
  this->m_pSteamUser = v5;
  if ( v5 == nullptr )
    return false;
  v6 = _SteamClient();
  v7 = (ISteamFriends *)(*(int (__thiscall **)(int, int, int, const char *))(*(_DWORD *)v6 + 32))(
                          a1: v6,
                          a2: hSteamUser,
                          a3: HSteamPipe,
                          a4: "SteamFriends008");
  this->m_pSteamFriends = v7;
  if ( v7 == nullptr )
    return false;
  v8 = _SteamClient();
  v9 = (ISteamUtils *)(*(int (__thiscall **)(int, int, const char *))(*(_DWORD *)v8 + 36))(
                        a1: v8,
                        a2: HSteamPipe,
                        a3: "SteamUtils005");
  this->m_pSteamUtils = v9;
  if ( v9 == nullptr )
    return false;
  v10 = _SteamClient();
  v11 = (ISteamMatchmaking *)(*(int (__thiscall **)(int, int, int, const char *))(*(_DWORD *)v10 + 40))(
                               a1: v10,
                               a2: hSteamUser,
                               a3: HSteamPipe,
                               a4: "SteamMatchMaking008");
  this->m_pSteamMatchmaking = v11;
  if ( v11 == nullptr )
    return false;
  v12 = _SteamClient();
  v13 = (ISteamMatchmakingServers *)(*(int (__thiscall **)(int, int, int, const char *))(*(_DWORD *)v12 + 48))(
                                      a1: v12,
                                      a2: hSteamUser,
                                      a3: HSteamPipe,
                                      a4: "SteamMatchMakingServers002");
  this->m_pSteamMatchmakingServers = v13;
  if ( v13 == nullptr )
    return false;
  v14 = _SteamClient();
  v15 = (ISteamUserStats *)(*(int (__thiscall **)(int, int, int, const char *))(*(_DWORD *)v14 + 56))(
                             a1: v14,
                             a2: hSteamUser,
                             a3: HSteamPipe,
                             a4: "STEAMUSERSTATS_INTERFACE_VERSION009");
  this->m_pSteamUserStats = v15;
  if ( v15 == nullptr )
    return false;
  v16 = _SteamClient();
  v17 = (ISteamApps *)(*(int (__thiscall **)(int, int, int, const char *))(*(_DWORD *)v16 + 64))(
                        a1: v16,
                        a2: hSteamUser,
                        a3: HSteamPipe,
                        a4: "STEAMAPPS_INTERFACE_VERSION004");
  this->m_pSteamApps = v17;
  if ( v17 == nullptr )
    return false;
  v18 = _SteamClient();
  v19 = (ISteamNetworking *)(*(int (__thiscall **)(int, int, int, const char *))(*(_DWORD *)v18 + 68))(
                              a1: v18,
                              a2: hSteamUser,
                              a3: HSteamPipe,
                              a4: "SteamNetworking005");
  this->m_pSteamNetworking = v19;
  if ( v19 == nullptr )
    return false;
  v20 = _SteamClient();
  v21 = (ISteamRemoteStorage *)(*(int (__thiscall **)(int, int, int, const char *))(*(_DWORD *)v20 + 72))(
                                 a1: v20,
                                 a2: hSteamUser,
                                 a3: HSteamPipe,
                                 a4: "STEAMREMOTESTORAGE_INTERFACE_VERSION004");
  this->m_pSteamRemoteStorage = v21;
  return v21 != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10090E30
// Name: class CSteam3Client __near & Steam3Client(void)
// Source: json
//------------------------------------------------------------------------------
CSteam3Client *__cdecl Steam3Client()
{
  return &s_Steam3Client;
}

//------------------------------------------------------------------------------
// Address: 0x10090E40
// Name: Callback_SteamAPIWarningMessageHook
// Source: json
//------------------------------------------------------------------------------
void __cdecl Callback_SteamAPIWarningMessageHook(int n, const char *sz)
{
  if ( n != 0 )
    _Warning(a1: "[STEAM] %s\n", sz);
  else
    _Msg(a1: "[STEAM] %s\n", sz);
}

//------------------------------------------------------------------------------
// Address: 0x10090E80
// Name: public: void CSteam3Client::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSteam3Client::Shutdown(CSteam3Client *this)
{
  if ( this->m_bActive )
  {
    this->m_bActive = false;
    if ( this->m_bInitialized )
    {
      _SteamAPI_Shutdown();
      this->m_bInitialized = false;
    }
    this->m_pSteamUser = nullptr;
    this->m_pSteamFriends = nullptr;
    this->m_pSteamUtils = nullptr;
    this->m_pSteamMatchmaking = nullptr;
    this->m_pSteamUserStats = nullptr;
    this->m_pSteamApps = nullptr;
    this->m_pSteamMatchmakingServers = nullptr;
    this->m_pSteamNetworking = nullptr;
    this->m_pSteamRemoteStorage = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10090ED0
// Name: public: void CSteam3Client::Activate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSteam3Client::Activate(CSteam3Client *this)
{
  bool v2; // al
  int v3; // eax

  if ( !this->m_bActive )
  {
    *(_WORD *)&this->m_bActive = 1;
    _SteamAPI_InitSafe();
    v2 = CSteamAPIContext::Init(this);
    this->m_bInitialized = v2;
    if ( v2 )
    {
      v3 = _SteamClient();
      (*(void (__thiscall **)(int, void (__cdecl *)(int, const char *)))(*(_DWORD *)v3 + 84))(
        a1: v3,
        a2: Callback_SteamAPIWarningMessageHook);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10090F20
// Name: public: void CSteam3Client::TerminateConnection(unsigned int,unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSteam3Client::TerminateConnection(CSteam3Client *this, u_long unIP, int usPort)
{
  ISteamUser *m_pSteamUser; // esi
  ISteamUser_vtbl *v4; // edi
  u_long v5; // eax

  m_pSteamUser = this->m_pSteamUser;
  this->m_bGSSecure = false;
  if ( m_pSteamUser != nullptr )
  {
    v4 = m_pSteamUser->__vftable;
    v5 = ntohl(netlong: unIP);
    v4->TerminateGameConnection(this: m_pSteamUser, a2: v5, a3: usPort);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10090F50
// Name: public: void CSteam3Client::RunFrame(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSteam3Client::RunFrame(CSteam3Client *this)
{
  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "CSteam3Client::RunFrame",
    a3: 0,
    a4: "Steam",
    a5: false,
    a6: 4);
  _SteamAPI_RunCallbacks();
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
}

//------------------------------------------------------------------------------
// Address: 0x10090F80
// Name: public: void CSteam3Client::OnClientGameServerDeny(struct ClientGameServerDeny_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSteam3Client::OnClientGameServerDeny(
        CSteam3Client *this,
        ClientGameServerDeny_t *pClientGameServerDeny)
{
  const char *v2; // eax

  if ( pClientGameServerDeny->m_uAppID == GetSteamAppID() )
  {
    v2 = "Unknown";
    switch ( pClientGameServerDeny->m_uReason )
    {
      case 1u:
        v2 = "Invalid version";
        goto LABEL_4;
      case 2u:
        v2 = "Kicked";
        goto LABEL_4;
      case 3u:
        v2 = "Not logged on";
        goto LABEL_4;
      case 4u:
        v2 = "No license";
        goto LABEL_4;
      case 5u:
        v2 = "VAC banned ";
        goto LABEL_4;
      case 6u:
        v2 = "Dropped from server";
        goto LABEL_4;
      case 7u:
        v2 = "Unknown";
        goto LABEL_4;
      case 8u:
        v2 = "Incompatible Anti Cheat";
        goto LABEL_4;
      case 9u:
        v2 = "Memory corruption";
        goto LABEL_4;
      case 0xAu:
        v2 = "Incompatible software";
        goto LABEL_4;
      case 0xBu:
        v2 = "Steam connection lost";
        goto LABEL_4;
      case 0xCu:
        v2 = "Steam connection error";
        goto LABEL_4;
      case 0xDu:
        v2 = "Response timed out";
        goto LABEL_4;
      case 0xEu:
        DevMsg(a1: "Validation stalled\n");
        return;
      default:
LABEL_4:
        _Warning(a1: "Disconnect: %s\n", v2);
        Host_Disconnect(bShowMainMenu: true);
        break;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10091070
// Name: public: void CSteam3Client::OnGameServerChangeRequested(struct GameServerChangeRequested_t __near *)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __thiscall CSteam3Client::OnGameServerChangeRequested(
        CSteam3Client *this,
        GameServerChangeRequested_t *pGameServerChangeRequested)
{
  vgui::CTreeViewListControl *v2; // ecx
  ECommandTarget_t TraceType; // eax
  const char *v4; // [esp-8h] [ebp-Ch]
  int v5; // [esp-4h] [ebp-8h]

  CLoaderMemAlloc::CrtSetReportMode(
    this: (ConVar *)&password.IConVar,
    value: pGameServerChangeRequested->m_rgchPassword,
    a2: v5);
  _Msg(a1: "Connecting to %s\n", pGameServerChangeRequested->m_rgchServer);
  v4 = va(format: "connect %s\n", pGameServerChangeRequested->m_rgchServer);
  TraceType = CTraceFilter::GetTraceType(this: v2);
  Cbuf_AddText(eTarget: TraceType, pText: v4, nTickDelay: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100910C0
// Name: public: void CSteam3Client::OnGameOverlayActivated(struct GameOverlayActivated_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSteam3Client::OnGameOverlayActivated(
        CSteam3Client *this,
        GameOverlayActivated_t *pGameOverlayActivated)
{
  bool v3; // al
  IEngineVGuiInternal *v4; // eax
  vgui::CTreeViewListControl *v5; // ecx
  ECommandTarget_t TraceType; // eax

  g_pInputSystem->ResetInputState(this: g_pInputSystem);
  v3 = pGameOverlayActivated->m_bActive != 0;
  this->m_bGameOverlayActive = v3;
  if ( v3 )
  {
    v4 = EngineVGui();
    if ( !v4->IsGameUIVisible(this: v4) && sv.m_State >= ss_active && CBaseServer::IsSinglePlayerGame(this: &sv) )
    {
      TraceType = CTraceFilter::GetTraceType(this: v5);
      Cbuf_AddText(eTarget: TraceType, pText: "gameui_activate", nTickDelay: 0);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10091130
// Name: public: void CSteam3Client::OnPersonaUpdated(struct PersonaStateChange_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSteam3Client::OnPersonaUpdated(CSteam3Client *this, PersonaStateChange_t *pPersonaStateChanged)
{
  ISteamUser *m_pSteamUser; // ecx
  ConVar *v3; // eax
  CSteamID steamID; // [esp+0h] [ebp-8h] BYREF

  if ( this->m_pSteamUtils != nullptr && this->m_pSteamFriends != nullptr )
  {
    m_pSteamUser = this->m_pSteamUser;
    if ( m_pSteamUser != nullptr && pPersonaStateChanged != nullptr )
    {
      m_pSteamUser->GetSteamID(this: m_pSteamUser, result: &steamID);
      if ( steamID.m_steamid.m_comp == pPersonaStateChanged->m_ulSteamID
        && (pPersonaStateChanged->m_nChangeFlags & 1) != 0 )
      {
        v3 = g_pCVar->FindVar_2(this: g_pCVar, a2: "name");
        if ( v3 != nullptr )
          UpdateNameFromSteamID(pConVar: &v3->IConVar, pSteamID: &steamID);
        else
          UpdateNameFromSteamID(pConVar: nullptr, pSteamID: &steamID);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100911C0
// Name: public: void CSteam3Client::OnLowBattery(struct LowBatteryPower_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSteam3Client::OnLowBattery(CSteam3Client *this, LowBatteryPower_t *pLowBat)
{
  ECommandTarget_t TraceType; // eax

  if ( pLowBat->m_nMinutesBatteryLeft == 1 || pLowBat->m_nMinutesBatteryLeft == 5 || pLowBat->m_nMinutesBatteryLeft == 9 )
  {
    TraceType = CTraceFilter::GetTraceType((vgui::CTreeViewListControl *)this);
    Cbuf_AddText(eTarget: TraceType, pText: "save LowBattery_AutoSave", nTickDelay: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100911F0
// Name: public: int CSteam3Client::InitiateConnection(void __near *,int,unsigned int,unsigned short,unsigned __int64,bool)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSteam3Client::InitiateConnection(
        CSteam3Client *this,
        void *pData,
        int cbMaxData,
        u_long unIP,
        int usPort,
        unsigned __int64 unGSSteamID,
        BOOL bSecure)
{
  ISteamUser *m_pSteamUser; // esi
  u_long v9; // eax

  m_pSteamUser = this->m_pSteamUser;
  this->m_bGSSecure = bSecure;
  if ( m_pSteamUser == nullptr )
    return 0;
  v9 = ntohl(netlong: unIP);
  return ((int (__thiscall *)(ISteamUser *, void *, int, _DWORD, _DWORD, u_long, int, BOOL))m_pSteamUser->InitiateGameConnection)(
           a1: m_pSteamUser,
           a2: pData,
           a3: cbMaxData,
           a4: unGSSteamID,
           a5: HIDWORD(unGSSteamID),
           a6: v9,
           a7: usPort,
           a8: bSecure);
}

//------------------------------------------------------------------------------
// Address: 0x10091240
// Name: public: CSteam3Client::~CSteam3Client(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSteam3Client::~CSteam3Client(CSteam3Client *this)
{
  if ( this->m_bActive )
  {
    this->m_bActive = false;
    if ( this->m_bInitialized )
    {
      _SteamAPI_Shutdown();
      this->m_bInitialized = false;
    }
    this->m_pSteamUser = nullptr;
    this->m_pSteamFriends = nullptr;
    this->m_pSteamUtils = nullptr;
    this->m_pSteamMatchmaking = nullptr;
    this->m_pSteamUserStats = nullptr;
    this->m_pSteamApps = nullptr;
    this->m_pSteamMatchmakingServers = nullptr;
    this->m_pSteamNetworking = nullptr;
    this->m_pSteamRemoteStorage = nullptr;
  }
  this->m_CallbackSteamSocketStatus.__vftable = (CCallback<CSteam3Client,SocketStatusCallback_t,0>_vtbl *)&CCallback<CSteam3Client,SocketStatusCallback_t,0>::`vftable';
  if ( (this->m_CallbackSteamSocketStatus.m_nCallbackFlags & 1) != 0 )
    _SteamAPI_UnregisterCallback(a1: &this->m_CallbackSteamSocketStatus);
  this->m_CallbackLowBattery.__vftable = (CCallback<CSteam3Client,LowBatteryPower_t,0>_vtbl *)&CCallback<CSteam3Client,LowBatteryPower_t,0>::`vftable';
  if ( (this->m_CallbackLowBattery.m_nCallbackFlags & 1) != 0 )
    _SteamAPI_UnregisterCallback(a1: &this->m_CallbackLowBattery);
  this->m_CallbackPersonaStateChanged.__vftable = (CCallback<CSteam3Client,PersonaStateChange_t,0>_vtbl *)&CCallback<CSteam3Client,PersonaStateChange_t,0>::`vftable';
  if ( (this->m_CallbackPersonaStateChanged.m_nCallbackFlags & 1) != 0 )
    _SteamAPI_UnregisterCallback(a1: &this->m_CallbackPersonaStateChanged);
  this->m_CallbackGameOverlayActivated.__vftable = (CCallback<CSteam3Client,GameOverlayActivated_t,0>_vtbl *)&CCallback<CSteam3Client,GameOverlayActivated_t,0>::`vftable';
  if ( (this->m_CallbackGameOverlayActivated.m_nCallbackFlags & 1) != 0 )
    _SteamAPI_UnregisterCallback(a1: &this->m_CallbackGameOverlayActivated);
  this->m_CallbackGameServerChangeRequested.__vftable = (CCallback<CSteam3Client,GameServerChangeRequested_t,0>_vtbl *)&CCallback<CSteam3Client,GameServerChangeRequested_t,0>::`vftable';
  if ( (this->m_CallbackGameServerChangeRequested.m_nCallbackFlags & 1) != 0 )
    _SteamAPI_UnregisterCallback(a1: &this->m_CallbackGameServerChangeRequested);
  this->m_CallbackClientGameServerDeny.__vftable = (CCallback<CSteam3Client,ClientGameServerDeny_t,0>_vtbl *)&CCallback<CSteam3Client,ClientGameServerDeny_t,0>::`vftable';
  if ( (this->m_CallbackClientGameServerDeny.m_nCallbackFlags & 1) != 0 )
    _SteamAPI_UnregisterCallback(a1: &this->m_CallbackClientGameServerDeny);
}

//------------------------------------------------------------------------------
// Address: 0x10091310
// Name: public: CSteam3Client::CSteam3Client(void)
// Source: json
//------------------------------------------------------------------------------
CSteam3Client *__thiscall CSteam3Client::CSteam3Client(CSteam3Client *this)
{
  this->m_pSteamUser = nullptr;
  this->m_pSteamFriends = nullptr;
  this->m_pSteamUtils = nullptr;
  this->m_pSteamMatchmaking = nullptr;
  this->m_pSteamUserStats = nullptr;
  this->m_pSteamApps = nullptr;
  this->m_pSteamMatchmakingServers = nullptr;
  this->m_pSteamNetworking = nullptr;
  this->m_pSteamRemoteStorage = nullptr;
  this->m_CallbackClientGameServerDeny.m_nCallbackFlags = 0;
  this->m_CallbackClientGameServerDeny.m_iCallback = 0;
  this->m_CallbackClientGameServerDeny.__vftable = (CCallback<CSteam3Client,ClientGameServerDeny_t,0>_vtbl *)&CCallback<CSteam3Client,ClientGameServerDeny_t,0>::`vftable';
  this->m_CallbackClientGameServerDeny.m_pObj = this;
  this->m_CallbackClientGameServerDeny.m_Func = CSteam3Client::OnClientGameServerDeny;
  if ( CSteam3Client::OnClientGameServerDeny != nullptr )
  {
    this->m_CallbackClientGameServerDeny.m_pObj = this;
    this->m_CallbackClientGameServerDeny.m_Func = CSteam3Client::OnClientGameServerDeny;
    _SteamAPI_RegisterCallback(a1: &this->m_CallbackClientGameServerDeny, a2: 113);
  }
  this->m_CallbackGameServerChangeRequested.m_nCallbackFlags = 0;
  this->m_CallbackGameServerChangeRequested.m_iCallback = 0;
  this->m_CallbackGameServerChangeRequested.__vftable = (CCallback<CSteam3Client,GameServerChangeRequested_t,0>_vtbl *)&CCallback<CSteam3Client,GameServerChangeRequested_t,0>::`vftable';
  this->m_CallbackGameServerChangeRequested.m_pObj = this;
  this->m_CallbackGameServerChangeRequested.m_Func = CSteam3Client::OnGameServerChangeRequested;
  if ( CSteam3Client::OnGameServerChangeRequested != nullptr )
  {
    this->m_CallbackGameServerChangeRequested.m_pObj = this;
    this->m_CallbackGameServerChangeRequested.m_Func = CSteam3Client::OnGameServerChangeRequested;
    _SteamAPI_RegisterCallback(a1: &this->m_CallbackGameServerChangeRequested, a2: 332);
  }
  this->m_CallbackGameOverlayActivated.m_nCallbackFlags = 0;
  this->m_CallbackGameOverlayActivated.m_iCallback = 0;
  this->m_CallbackGameOverlayActivated.__vftable = (CCallback<CSteam3Client,GameOverlayActivated_t,0>_vtbl *)&CCallback<CSteam3Client,GameOverlayActivated_t,0>::`vftable';
  this->m_CallbackGameOverlayActivated.m_pObj = this;
  this->m_CallbackGameOverlayActivated.m_Func = CSteam3Client::OnGameOverlayActivated;
  if ( CSteam3Client::OnGameOverlayActivated != nullptr )
  {
    this->m_CallbackGameOverlayActivated.m_pObj = this;
    this->m_CallbackGameOverlayActivated.m_Func = CSteam3Client::OnGameOverlayActivated;
    _SteamAPI_RegisterCallback(a1: &this->m_CallbackGameOverlayActivated, a2: 331);
  }
  this->m_CallbackPersonaStateChanged.m_nCallbackFlags = 0;
  this->m_CallbackPersonaStateChanged.m_iCallback = 0;
  this->m_CallbackPersonaStateChanged.__vftable = (CCallback<CSteam3Client,PersonaStateChange_t,0>_vtbl *)&CCallback<CSteam3Client,PersonaStateChange_t,0>::`vftable';
  this->m_CallbackPersonaStateChanged.m_pObj = this;
  this->m_CallbackPersonaStateChanged.m_Func = CSteam3Client::OnPersonaUpdated;
  if ( CSteam3Client::OnPersonaUpdated != nullptr )
  {
    this->m_CallbackPersonaStateChanged.m_pObj = this;
    this->m_CallbackPersonaStateChanged.m_Func = CSteam3Client::OnPersonaUpdated;
    _SteamAPI_RegisterCallback(a1: &this->m_CallbackPersonaStateChanged, a2: 304);
  }
  this->m_CallbackLowBattery.m_nCallbackFlags = 0;
  this->m_CallbackLowBattery.m_iCallback = 0;
  this->m_CallbackLowBattery.__vftable = (CCallback<CSteam3Client,LowBatteryPower_t,0>_vtbl *)&CCallback<CSteam3Client,LowBatteryPower_t,0>::`vftable';
  this->m_CallbackLowBattery.m_pObj = this;
  this->m_CallbackLowBattery.m_Func = CSteam3Client::OnLowBattery;
  if ( CSteam3Client::OnLowBattery != nullptr )
  {
    this->m_CallbackLowBattery.m_pObj = this;
    this->m_CallbackLowBattery.m_Func = CSteam3Client::OnLowBattery;
    _SteamAPI_RegisterCallback(a1: &this->m_CallbackLowBattery, a2: 702);
  }
  this->m_CallbackSteamSocketStatus.m_nCallbackFlags = 0;
  this->m_CallbackSteamSocketStatus.m_iCallback = 0;
  this->m_CallbackSteamSocketStatus.__vftable = (CCallback<CSteam3Client,SocketStatusCallback_t,0>_vtbl *)&CCallback<CSteam3Client,SocketStatusCallback_t,0>::`vftable';
  this->m_CallbackSteamSocketStatus.m_pObj = this;
  this->m_CallbackSteamSocketStatus.m_Func = (void (__thiscall *)(CSteam3Client *, SocketStatusCallback_t *))CBaseServer::RemoveClientFromGame;
  if ( CBaseServer::RemoveClientFromGame != nullptr )
  {
    this->m_CallbackSteamSocketStatus.m_pObj = this;
    this->m_CallbackSteamSocketStatus.m_Func = (void (__thiscall *)(CSteam3Client *, SocketStatusCallback_t *))CBaseServer::RemoveClientFromGame;
    _SteamAPI_RegisterCallback(a1: &this->m_CallbackSteamSocketStatus, a2: 1201);
  }
  *(_DWORD *)&this->m_bActive = 0;
  return this;
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x10090990
// Name: public: bool CSteamAPIContext::Init(void)
// Source: json
//------------------------------------------------------------------------------
bool __usercall CSteamAPIContext::Init@<al>(CSteamAPIContext *this@<ecx>, int a2@<esi>)
{
  int HSteamPipe; // esi
  int v5; // eax
  ISteamUser *v6; // eax
  int v7; // eax
  ISteamFriends *v8; // eax
  int v9; // eax
  ISteamUtils *v10; // eax
  int v11; // eax
  ISteamMatchmaking *v12; // eax
  int v13; // eax
  ISteamMatchmakingServers *v14; // eax
  int v15; // eax
  ISteamUserStats *v16; // eax
  int v17; // eax
  ISteamApps *v18; // eax
  int v19; // eax
  ISteamNetworking *v20; // eax
  int v21; // eax
  ISteamRemoteStorage *v22; // eax
  int v23; // [esp-4h] [ebp-10h]
  int hSteamUser; // [esp+8h] [ebp-4h]

  if ( _SteamClient() == 0 )
    return false;
  hSteamUser = _SteamAPI_GetHSteamUser(a1: a2);
  HSteamPipe = _SteamAPI_GetHSteamPipe(a1: v23);
  v5 = _SteamClient();
  v6 = (ISteamUser *)(*(int (__thiscall **)(int, int, int, const char *))(*(_DWORD *)v5 + 20))(
                       a1: v5,
                       a2: hSteamUser,
                       a3: HSteamPipe,
                       a4: "SteamUser014");
  this->m_pSteamUser = v6;
  if ( v6 == nullptr )
    return false;
  v7 = _SteamClient();
  v8 = (ISteamFriends *)(*(int (__thiscall **)(int, int, int, const char *))(*(_DWORD *)v7 + 32))(
                          a1: v7,
                          a2: hSteamUser,
                          a3: HSteamPipe,
                          a4: "SteamFriends008");
  this->m_pSteamFriends = v8;
  if ( v8 == nullptr )
    return false;
  v9 = _SteamClient();
  v10 = (ISteamUtils *)(*(int (__thiscall **)(int, int, const char *))(*(_DWORD *)v9 + 36))(
                         a1: v9,
                         a2: HSteamPipe,
                         a3: "SteamUtils005");
  this->m_pSteamUtils = v10;
  if ( v10 == nullptr )
    return false;
  v11 = _SteamClient();
  v12 = (ISteamMatchmaking *)(*(int (__thiscall **)(int, int, int, const char *))(*(_DWORD *)v11 + 40))(
                               a1: v11,
                               a2: hSteamUser,
                               a3: HSteamPipe,
                               a4: "SteamMatchMaking008");
  this->m_pSteamMatchmaking = v12;
  if ( v12 == nullptr )
    return false;
  v13 = _SteamClient();
  v14 = (ISteamMatchmakingServers *)(*(int (__thiscall **)(int, int, int, const char *))(*(_DWORD *)v13 + 48))(
                                      a1: v13,
                                      a2: hSteamUser,
                                      a3: HSteamPipe,
                                      a4: "SteamMatchMakingServers002");
  this->m_pSteamMatchmakingServers = v14;
  if ( v14 == nullptr )
    return false;
  v15 = _SteamClient();
  v16 = (ISteamUserStats *)(*(int (__thiscall **)(int, int, int, const char *))(*(_DWORD *)v15 + 56))(
                             a1: v15,
                             a2: hSteamUser,
                             a3: HSteamPipe,
                             a4: "STEAMUSERSTATS_INTERFACE_VERSION009");
  this->m_pSteamUserStats = v16;
  if ( v16 == nullptr )
    return false;
  v17 = _SteamClient();
  v18 = (ISteamApps *)(*(int (__thiscall **)(int, int, int, const char *))(*(_DWORD *)v17 + 64))(
                        a1: v17,
                        a2: hSteamUser,
                        a3: HSteamPipe,
                        a4: "STEAMAPPS_INTERFACE_VERSION004");
  this->m_pSteamApps = v18;
  if ( v18 == nullptr )
    return false;
  v19 = _SteamClient();
  v20 = (ISteamNetworking *)(*(int (__thiscall **)(int, int, int, const char *))(*(_DWORD *)v19 + 68))(
                              a1: v19,
                              a2: hSteamUser,
                              a3: HSteamPipe,
                              a4: "SteamNetworking005");
  this->m_pSteamNetworking = v20;
  if ( v20 == nullptr )
    return false;
  v21 = _SteamClient();
  v22 = (ISteamRemoteStorage *)(*(int (__thiscall **)(int, int, int, const char *))(*(_DWORD *)v21 + 72))(
                                 a1: v21,
                                 a2: hSteamUser,
                                 a3: HSteamPipe,
                                 a4: "STEAMREMOTESTORAGE_INTERFACE_VERSION004");
  this->m_pSteamRemoteStorage = v22;
  return v22 != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10090AE0
// Name: class CSteam3Client __near & Steam3Client(void)
// Source: json
//------------------------------------------------------------------------------
CSteam3Client *__cdecl Steam3Client()
{
  return &s_Steam3Client;
}

//------------------------------------------------------------------------------
// Address: 0x10090AF0
// Name: Callback_SteamAPIWarningMessageHook
// Source: json
//------------------------------------------------------------------------------
void __cdecl Callback_SteamAPIWarningMessageHook(int n, const char *sz)
{
  if ( n != 0 )
    _Warning(a1: "[STEAM] %s\n", sz);
  else
    _Msg(a1: "[STEAM] %s\n", sz);
}

//------------------------------------------------------------------------------
// Address: 0x10090B30
// Name: public: void CSteam3Client::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSteam3Client::Shutdown(CSteam3Client *this)
{
  if ( this->m_bActive )
  {
    this->m_bActive = false;
    if ( this->m_bInitialized )
    {
      _SteamAPI_Shutdown();
      this->m_bInitialized = false;
    }
    this->m_pSteamUser = nullptr;
    this->m_pSteamFriends = nullptr;
    this->m_pSteamUtils = nullptr;
    this->m_pSteamMatchmaking = nullptr;
    this->m_pSteamUserStats = nullptr;
    this->m_pSteamApps = nullptr;
    this->m_pSteamMatchmakingServers = nullptr;
    this->m_pSteamNetworking = nullptr;
    this->m_pSteamRemoteStorage = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10090B80
// Name: public: void CSteam3Client::Activate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSteam3Client::Activate(CSteam3Client *this)
{
  bool v2; // al
  int v3; // eax

  if ( !this->m_bActive )
  {
    *(_WORD *)&this->m_bActive = 1;
    _SteamAPI_InitSafe();
    v2 = CSteamAPIContext::Init(this, a2: (int)this);
    this->m_bInitialized = v2;
    if ( v2 )
    {
      v3 = _SteamClient();
      (*(void (__thiscall **)(int, void (__cdecl *)(int, const char *)))(*(_DWORD *)v3 + 84))(
        a1: v3,
        a2: Callback_SteamAPIWarningMessageHook);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10090BD0
// Name: public: void CSteam3Client::TerminateConnection(unsigned int,unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSteam3Client::TerminateConnection(CSteam3Client *this, u_long unIP, int usPort)
{
  ISteamUser *m_pSteamUser; // esi
  ISteamUser_vtbl *v4; // edi
  u_long v5; // eax

  m_pSteamUser = this->m_pSteamUser;
  this->m_bGSSecure = false;
  if ( m_pSteamUser != nullptr )
  {
    v4 = m_pSteamUser->__vftable;
    v5 = ntohl(netlong: unIP);
    v4->TerminateGameConnection(this: m_pSteamUser, a2: v5, a3: usPort);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10090C00
// Name: public: void CSteam3Client::RunFrame(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSteam3Client::RunFrame(CSteam3Client *this)
{
  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "CSteam3Client::RunFrame",
    a3: 0,
    a4: "Steam",
    a5: false,
    a6: 4);
  _SteamAPI_RunCallbacks();
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
}

//------------------------------------------------------------------------------
// Address: 0x10090C30
// Name: public: void CSteam3Client::OnClientGameServerDeny(struct ClientGameServerDeny_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSteam3Client::OnClientGameServerDeny(
        CSteam3Client *this,
        ClientGameServerDeny_t *pClientGameServerDeny)
{
  const char *v2; // eax

  if ( pClientGameServerDeny->m_uAppID == GetSteamAppID() )
  {
    v2 = "Unknown";
    switch ( pClientGameServerDeny->m_uReason )
    {
      case 1u:
        v2 = "Invalid version";
        goto LABEL_4;
      case 2u:
        v2 = "Kicked";
        goto LABEL_4;
      case 3u:
        v2 = "Not logged on";
        goto LABEL_4;
      case 4u:
        v2 = "No license";
        goto LABEL_4;
      case 5u:
        v2 = "VAC banned ";
        goto LABEL_4;
      case 6u:
        v2 = "Dropped from server";
        goto LABEL_4;
      case 7u:
        v2 = "Unknown";
        goto LABEL_4;
      case 8u:
        v2 = "Incompatible Anti Cheat";
        goto LABEL_4;
      case 9u:
        v2 = "Memory corruption";
        goto LABEL_4;
      case 0xAu:
        v2 = "Incompatible software";
        goto LABEL_4;
      case 0xBu:
        v2 = "Steam connection lost";
        goto LABEL_4;
      case 0xCu:
        v2 = "Steam connection error";
        goto LABEL_4;
      case 0xDu:
        v2 = "Response timed out";
        goto LABEL_4;
      case 0xEu:
        DevMsg(a1: "Validation stalled\n");
        return;
      default:
LABEL_4:
        _Warning(a1: "Disconnect: %s\n", v2);
        Host_Disconnect(bShowMainMenu: true);
        break;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10090D20
// Name: public: void CSteam3Client::OnGameServerChangeRequested(struct GameServerChangeRequested_t __near *)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __thiscall CSteam3Client::OnGameServerChangeRequested(
        CSteam3Client *this,
        GameServerChangeRequested_t *pGameServerChangeRequested)
{
  vgui::CTreeViewListControl *v2; // ecx
  ECommandTarget_t TraceType; // eax
  const char *v4; // [esp-8h] [ebp-Ch]

  CLoaderMemAlloc::CrtSetReportMode(
    this: (ConVar *)&password.IConVar,
    value: pGameServerChangeRequested->m_rgchPassword);
  _Msg(a1: "Connecting to %s\n", pGameServerChangeRequested->m_rgchServer);
  v4 = va(format: "connect %s\n", pGameServerChangeRequested->m_rgchServer);
  TraceType = CTraceFilter::GetTraceType(this: v2);
  Cbuf_AddText(eTarget: TraceType, pText: v4, nTickDelay: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10090D70
// Name: public: void CSteam3Client::OnGameOverlayActivated(struct GameOverlayActivated_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSteam3Client::OnGameOverlayActivated(
        CSteam3Client *this,
        GameOverlayActivated_t *pGameOverlayActivated)
{
  bool v3; // al
  IEngineVGuiInternal *v4; // eax
  vgui::CTreeViewListControl *v5; // ecx
  ECommandTarget_t TraceType; // eax

  g_pInputSystem->ResetInputState(this: g_pInputSystem);
  v3 = pGameOverlayActivated->m_bActive != 0;
  this->m_bGameOverlayActive = v3;
  if ( v3 )
  {
    v4 = EngineVGui();
    if ( !v4->IsGameUIVisible(this: v4) && sv.m_State >= ss_active && CBaseServer::IsSinglePlayerGame(this: &sv) )
    {
      TraceType = CTraceFilter::GetTraceType(this: v5);
      Cbuf_AddText(eTarget: TraceType, pText: "gameui_activate", nTickDelay: 0);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10090DE0
// Name: public: void CSteam3Client::OnPersonaUpdated(struct PersonaStateChange_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSteam3Client::OnPersonaUpdated(CSteam3Client *this, PersonaStateChange_t *pPersonaStateChanged)
{
  ISteamUser *m_pSteamUser; // ecx
  ConVar *v3; // eax
  CSteamID steamID; // [esp+0h] [ebp-8h] BYREF

  if ( this->m_pSteamUtils != nullptr && this->m_pSteamFriends != nullptr )
  {
    m_pSteamUser = this->m_pSteamUser;
    if ( m_pSteamUser != nullptr && pPersonaStateChanged != nullptr )
    {
      m_pSteamUser->GetSteamID(this: m_pSteamUser, result: &steamID);
      if ( steamID.m_steamid.m_comp == pPersonaStateChanged->m_ulSteamID
        && (pPersonaStateChanged->m_nChangeFlags & 1) != 0 )
      {
        v3 = g_pCVar->FindVar_2(this: g_pCVar, a2: "name");
        if ( v3 != nullptr )
          UpdateNameFromSteamID(pConVar: &v3->IConVar, pSteamID: &steamID);
        else
          UpdateNameFromSteamID(pConVar: nullptr, pSteamID: &steamID);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10090E70
// Name: public: void CSteam3Client::OnLowBattery(struct LowBatteryPower_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSteam3Client::OnLowBattery(CSteam3Client *this, LowBatteryPower_t *pLowBat)
{
  ECommandTarget_t TraceType; // eax

  if ( pLowBat->m_nMinutesBatteryLeft == 1 || pLowBat->m_nMinutesBatteryLeft == 5 || pLowBat->m_nMinutesBatteryLeft == 9 )
  {
    TraceType = CTraceFilter::GetTraceType((vgui::CTreeViewListControl *)this);
    Cbuf_AddText(eTarget: TraceType, pText: "save LowBattery_AutoSave", nTickDelay: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10090EA0
// Name: public: int CSteam3Client::InitiateConnection(void __near *,int,unsigned int,unsigned short,unsigned __int64,bool)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSteam3Client::InitiateConnection(
        CSteam3Client *this,
        void *pData,
        int cbMaxData,
        u_long unIP,
        int usPort,
        unsigned __int64 unGSSteamID,
        BOOL bSecure)
{
  ISteamUser *m_pSteamUser; // esi
  u_long v9; // eax

  m_pSteamUser = this->m_pSteamUser;
  this->m_bGSSecure = bSecure;
  if ( m_pSteamUser == nullptr )
    return 0;
  v9 = ntohl(netlong: unIP);
  return ((int (__thiscall *)(ISteamUser *, void *, int, _DWORD, _DWORD, u_long, int, BOOL))m_pSteamUser->InitiateGameConnection)(
           a1: m_pSteamUser,
           a2: pData,
           a3: cbMaxData,
           a4: unGSSteamID,
           a5: HIDWORD(unGSSteamID),
           a6: v9,
           a7: usPort,
           a8: bSecure);
}

//------------------------------------------------------------------------------
// Address: 0x10090F30
// Name: public: CSteam3Client::~CSteam3Client(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSteam3Client::~CSteam3Client(CSteam3Client *this)
{
  if ( this->m_bActive )
  {
    this->m_bActive = false;
    if ( this->m_bInitialized )
    {
      _SteamAPI_Shutdown();
      this->m_bInitialized = false;
    }
    this->m_pSteamUser = nullptr;
    this->m_pSteamFriends = nullptr;
    this->m_pSteamUtils = nullptr;
    this->m_pSteamMatchmaking = nullptr;
    this->m_pSteamUserStats = nullptr;
    this->m_pSteamApps = nullptr;
    this->m_pSteamMatchmakingServers = nullptr;
    this->m_pSteamNetworking = nullptr;
    this->m_pSteamRemoteStorage = nullptr;
  }
  this->m_CallbackSteamSocketStatus.__vftable = (CCallback<CSteam3Client,SocketStatusCallback_t,0>_vtbl *)&CCallback<CSteam3Client,SocketStatusCallback_t,0>::`vftable';
  if ( (this->m_CallbackSteamSocketStatus.m_nCallbackFlags & 1) != 0 )
    _SteamAPI_UnregisterCallback(a1: &this->m_CallbackSteamSocketStatus);
  this->m_CallbackLowBattery.__vftable = (CCallback<CSteam3Client,LowBatteryPower_t,0>_vtbl *)&CCallback<CSteam3Client,LowBatteryPower_t,0>::`vftable';
  if ( (this->m_CallbackLowBattery.m_nCallbackFlags & 1) != 0 )
    _SteamAPI_UnregisterCallback(a1: &this->m_CallbackLowBattery);
  this->m_CallbackPersonaStateChanged.__vftable = (CCallback<CSteam3Client,PersonaStateChange_t,0>_vtbl *)&CCallback<CSteam3Client,PersonaStateChange_t,0>::`vftable';
  if ( (this->m_CallbackPersonaStateChanged.m_nCallbackFlags & 1) != 0 )
    _SteamAPI_UnregisterCallback(a1: &this->m_CallbackPersonaStateChanged);
  this->m_CallbackGameOverlayActivated.__vftable = (CCallback<CSteam3Client,GameOverlayActivated_t,0>_vtbl *)&CCallback<CSteam3Client,GameOverlayActivated_t,0>::`vftable';
  if ( (this->m_CallbackGameOverlayActivated.m_nCallbackFlags & 1) != 0 )
    _SteamAPI_UnregisterCallback(a1: &this->m_CallbackGameOverlayActivated);
  this->m_CallbackGameServerChangeRequested.__vftable = (CCallback<CSteam3Client,GameServerChangeRequested_t,0>_vtbl *)&CCallback<CSteam3Client,GameServerChangeRequested_t,0>::`vftable';
  if ( (this->m_CallbackGameServerChangeRequested.m_nCallbackFlags & 1) != 0 )
    _SteamAPI_UnregisterCallback(a1: &this->m_CallbackGameServerChangeRequested);
  this->m_CallbackClientGameServerDeny.__vftable = (CCallback<CSteam3Client,ClientGameServerDeny_t,0>_vtbl *)&CCallback<CSteam3Client,ClientGameServerDeny_t,0>::`vftable';
  if ( (this->m_CallbackClientGameServerDeny.m_nCallbackFlags & 1) != 0 )
    _SteamAPI_UnregisterCallback(a1: &this->m_CallbackClientGameServerDeny);
}

//------------------------------------------------------------------------------
// Address: 0x10091000
// Name: public: CSteam3Client::CSteam3Client(void)
// Source: json
//------------------------------------------------------------------------------
CSteam3Client *__thiscall CSteam3Client::CSteam3Client(CSteam3Client *this)
{
  this->m_pSteamUser = nullptr;
  this->m_pSteamFriends = nullptr;
  this->m_pSteamUtils = nullptr;
  this->m_pSteamMatchmaking = nullptr;
  this->m_pSteamUserStats = nullptr;
  this->m_pSteamApps = nullptr;
  this->m_pSteamMatchmakingServers = nullptr;
  this->m_pSteamNetworking = nullptr;
  this->m_pSteamRemoteStorage = nullptr;
  this->m_CallbackClientGameServerDeny.m_nCallbackFlags = 0;
  this->m_CallbackClientGameServerDeny.m_iCallback = 0;
  this->m_CallbackClientGameServerDeny.__vftable = (CCallback<CSteam3Client,ClientGameServerDeny_t,0>_vtbl *)&CCallback<CSteam3Client,ClientGameServerDeny_t,0>::`vftable';
  this->m_CallbackClientGameServerDeny.m_pObj = this;
  this->m_CallbackClientGameServerDeny.m_Func = CSteam3Client::OnClientGameServerDeny;
  if ( CSteam3Client::OnClientGameServerDeny != nullptr )
  {
    this->m_CallbackClientGameServerDeny.m_pObj = this;
    this->m_CallbackClientGameServerDeny.m_Func = CSteam3Client::OnClientGameServerDeny;
    _SteamAPI_RegisterCallback(a1: &this->m_CallbackClientGameServerDeny, a2: 113);
  }
  this->m_CallbackGameServerChangeRequested.m_nCallbackFlags = 0;
  this->m_CallbackGameServerChangeRequested.m_iCallback = 0;
  this->m_CallbackGameServerChangeRequested.__vftable = (CCallback<CSteam3Client,GameServerChangeRequested_t,0>_vtbl *)&CCallback<CSteam3Client,GameServerChangeRequested_t,0>::`vftable';
  this->m_CallbackGameServerChangeRequested.m_pObj = this;
  this->m_CallbackGameServerChangeRequested.m_Func = CSteam3Client::OnGameServerChangeRequested;
  if ( CSteam3Client::OnGameServerChangeRequested != nullptr )
  {
    this->m_CallbackGameServerChangeRequested.m_pObj = this;
    this->m_CallbackGameServerChangeRequested.m_Func = CSteam3Client::OnGameServerChangeRequested;
    _SteamAPI_RegisterCallback(a1: &this->m_CallbackGameServerChangeRequested, a2: 332);
  }
  this->m_CallbackGameOverlayActivated.m_nCallbackFlags = 0;
  this->m_CallbackGameOverlayActivated.m_iCallback = 0;
  this->m_CallbackGameOverlayActivated.__vftable = (CCallback<CSteam3Client,GameOverlayActivated_t,0>_vtbl *)&CCallback<CSteam3Client,GameOverlayActivated_t,0>::`vftable';
  this->m_CallbackGameOverlayActivated.m_pObj = this;
  this->m_CallbackGameOverlayActivated.m_Func = CSteam3Client::OnGameOverlayActivated;
  if ( CSteam3Client::OnGameOverlayActivated != nullptr )
  {
    this->m_CallbackGameOverlayActivated.m_pObj = this;
    this->m_CallbackGameOverlayActivated.m_Func = CSteam3Client::OnGameOverlayActivated;
    _SteamAPI_RegisterCallback(a1: &this->m_CallbackGameOverlayActivated, a2: 331);
  }
  this->m_CallbackPersonaStateChanged.m_nCallbackFlags = 0;
  this->m_CallbackPersonaStateChanged.m_iCallback = 0;
  this->m_CallbackPersonaStateChanged.__vftable = (CCallback<CSteam3Client,PersonaStateChange_t,0>_vtbl *)&CCallback<CSteam3Client,PersonaStateChange_t,0>::`vftable';
  this->m_CallbackPersonaStateChanged.m_pObj = this;
  this->m_CallbackPersonaStateChanged.m_Func = CSteam3Client::OnPersonaUpdated;
  if ( CSteam3Client::OnPersonaUpdated != nullptr )
  {
    this->m_CallbackPersonaStateChanged.m_pObj = this;
    this->m_CallbackPersonaStateChanged.m_Func = CSteam3Client::OnPersonaUpdated;
    _SteamAPI_RegisterCallback(a1: &this->m_CallbackPersonaStateChanged, a2: 304);
  }
  this->m_CallbackLowBattery.m_nCallbackFlags = 0;
  this->m_CallbackLowBattery.m_iCallback = 0;
  this->m_CallbackLowBattery.__vftable = (CCallback<CSteam3Client,LowBatteryPower_t,0>_vtbl *)&CCallback<CSteam3Client,LowBatteryPower_t,0>::`vftable';
  this->m_CallbackLowBattery.m_pObj = this;
  this->m_CallbackLowBattery.m_Func = CSteam3Client::OnLowBattery;
  if ( CSteam3Client::OnLowBattery != nullptr )
  {
    this->m_CallbackLowBattery.m_pObj = this;
    this->m_CallbackLowBattery.m_Func = CSteam3Client::OnLowBattery;
    _SteamAPI_RegisterCallback(a1: &this->m_CallbackLowBattery, a2: 702);
  }
  this->m_CallbackSteamSocketStatus.m_nCallbackFlags = 0;
  this->m_CallbackSteamSocketStatus.m_iCallback = 0;
  this->m_CallbackSteamSocketStatus.__vftable = (CCallback<CSteam3Client,SocketStatusCallback_t,0>_vtbl *)&CCallback<CSteam3Client,SocketStatusCallback_t,0>::`vftable';
  this->m_CallbackSteamSocketStatus.m_pObj = this;
  this->m_CallbackSteamSocketStatus.m_Func = (void (__thiscall *)(CSteam3Client *, SocketStatusCallback_t *))CBaseServer::RemoveClientFromGame;
  if ( CBaseServer::RemoveClientFromGame != nullptr )
  {
    this->m_CallbackSteamSocketStatus.m_pObj = this;
    this->m_CallbackSteamSocketStatus.m_Func = (void (__thiscall *)(CSteam3Client *, SocketStatusCallback_t *))CBaseServer::RemoveClientFromGame;
    _SteamAPI_RegisterCallback(a1: &this->m_CallbackSteamSocketStatus, a2: 1201);
  }
  *(_DWORD *)&this->m_bActive = 0;
  return this;
}

} // namespace engine_xlsp
