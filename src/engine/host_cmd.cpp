// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: engine/host_cmd.cpp
// Functions: 137
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x1018A820
// Name: HostnameChanged
// Source: json
//------------------------------------------------------------------------------
void __usercall HostnameChanged(int a1@<ebx>, int a2@<edi>, IConVar *pConVar)
{
  CSteam3Server *v3; // eax
  IGameEvent *v4; // esi
  ConVarRef var; // [esp+0h] [ebp-8h] BYREF

  v3 = Steam3Server();
  CSteam3Server::NotifyOfServerNameChange(this: v3, a2: a1, a3: a2);
  if ( sv.m_State >= ss_active
    && CGameEventManager::GetEventDescriptor(this: g_GameEventManager, name: "hostname_changed", pCookie: nullptr) != nullptr )
  {
    v4 = g_GameEventManager->CreateEventA(this: g_GameEventManager, a2: "hostname_changed", a3: 0, a4: 0);
    if ( v4 != nullptr )
    {
      ConVarRef::ConVarRef(this: &var, pConVar);
      v4->SetString(this: v4, a2: "hostname", a3: var.m_pConVarState->m_Value.m_pszString);
      g_GameEventManager->FireEvent(this: g_GameEventManager, a2: v4, a3: false);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1018A8B0
// Name: unsigned int GetSteamAppID(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __cdecl GetSteamAppID()
{
  CSteam3Client *v0; // eax
  CSteam3Server *v2; // eax

  if ( Steam3Client()->m_pSteamUtils != nullptr )
  {
    v0 = Steam3Client();
    return v0->m_pSteamUtils->GetAppID(this: v0->m_pSteamUtils);
  }
  else if ( Steam3Server()->m_pSteamGameServerUtils != nullptr )
  {
    v2 = Steam3Server();
    return v2->m_pSteamGameServerUtils->GetAppID(this: v2->m_pSteamGameServerUtils);
  }
  else
  {
    return 215;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1018A8F0
// Name: enum EUniverse GetSteamUniverse(void)
// Source: json
//------------------------------------------------------------------------------
EUniverse __cdecl GetSteamUniverse()
{
  CSteam3Client *v0; // eax
  CSteam3Server *v2; // eax

  if ( Steam3Client()->m_pSteamUtils != nullptr )
  {
    v0 = Steam3Client();
    return v0->m_pSteamUtils->GetConnectedUniverse(this: v0->m_pSteamUtils);
  }
  else if ( Steam3Server()->m_pSteamGameServerUtils != nullptr )
  {
    v2 = Steam3Server();
    return v2->m_pSteamGameServerUtils->GetConnectedUniverse(this: v2->m_pSteamGameServerUtils);
  }
  else
  {
    return k_EUniverseInvalid;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1018A930
// Name: void SetLaunchOptions(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SetLaunchOptions(const CCommand *args)
{
  int v1; // esi
  KeyValues *v2; // eax
  int m_nArgc; // eax
  const char **m_ppArgv; // edi
  const char *v5; // eax
  char *v6; // eax
  const char *v7; // [esp-8h] [ebp-10h]

  v1 = 0;
  if ( g_pLaunchOptions != nullptr )
    KeyValues::deleteThis(this: g_pLaunchOptions);
  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v2 != nullptr )
    g_pLaunchOptions = KeyValues::KeyValues(this: v2, setName: "LaunchOptions");
  else
    g_pLaunchOptions = nullptr;
  m_nArgc = args->m_nArgc;
  if ( args->m_nArgc > 0 )
  {
    m_ppArgv = args->m_ppArgv;
    do
    {
      if ( v1 < 0 || v1 >= m_nArgc )
        v5 = defaultValue;
      else
        v5 = *m_ppArgv;
      v7 = v5;
      v6 = va(format: "Arg%d", v1);
      KeyValues::SetString(this: g_pLaunchOptions, keyName: v6, value: v7);
      m_nArgc = args->m_nArgc;
      ++v1;
      ++m_ppArgv;
    }
    while ( v1 < args->m_nArgc );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1018A9C0
// Name: void Host_Quit_f(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Host_Quit_f()
{
  if ( EngineTool_CheckQuitHandlers() )
    HostState_Shutdown();
}

//------------------------------------------------------------------------------
// Address: 0x1018A9D0
// Name: _restart
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __cdecl restart()
{
  HostState_Restart();
}

//------------------------------------------------------------------------------
// Address: 0x1018A9E0
// Name: void Host_LightCrosshair(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Host_LightCrosshair()
{
  int v0; // esi
  int v1; // edi
  int v2; // eax
  Vector f; // [esp+0h] [ebp-18h] BYREF
  Vector lightmapColor; // [esp+Ch] [ebp-Ch] BYREF
  Vector endPoint; // [esp+18h] [ebp+0h] BYREF

  lightmapColor.x = (float)(g_MainViewForward[0].x * 57016.32) + g_MainViewOrigin[0].x;
  lightmapColor.y = (float)(*(float *)&dword_104F1BF8 * 57016.32) + g_MainViewOrigin[0].y;
  lightmapColor.z = (float)(*(float *)&dword_104F1BFC * 57016.32) + g_MainViewOrigin[0].z;
  R_LightVec(
    a1: (int)&endPoint,
    start: g_MainViewOrigin,
    end: &lightmapColor,
    bUseLightStyles: true,
    c: &f,
    textureS: nullptr,
    textureT: nullptr,
    lightmapS: nullptr,
    lightmapT: nullptr);
  v0 = LinearToTexture(f: f.x);
  v1 = LinearToTexture(f: f.y);
  v2 = LinearToTexture(f: f.z);
  ConMsg(a1: "Luxel Value: %d %d %d\n", v0, v1, v2);
}

//------------------------------------------------------------------------------
// Address: 0x1018AAA0
// Name: void Host_Status_PrintClient(class IClient __near *,bool,void (*)(char const __near *,...))
// Source: json
//------------------------------------------------------------------------------
void __cdecl Host_Status_PrintClient(IClient *client, bool bShowAddress, void (*print)(const char *, ...))
{
  INetChannel *v3; // edi
  const char *v4; // ebx
  int v5; // eax
  double v6; // st7
  double v7; // st7
  double v8; // st7
  char *v9; // eax
  int v10; // eax
  int v11; // eax
  int v12; // eax
  int v13; // eax
  void (*v14)(const char *, ...); // esi
  int v15; // eax
  int v16; // eax
  int v17; // eax
  int v18; // eax

  v3 = client->GetNetChannel(this: client);
  v4 = "challenging";
  if ( client->IsActive(this: client) )
  {
    v4 = "active";
  }
  else if ( client->IsSpawned(this: client) )
  {
    v4 = "spawning";
  }
  else if ( client->IsConnected(this: client) )
  {
    v4 = "connecting";
  }
  if ( v3 != nullptr )
  {
    v5 = v3->GetDataRate(this: v3);
    v6 = ((double (__thiscall *)(INetChannel *, int, const char *, int))v3->GetAvgLoss)(a1: v3, a2: 1, a3: v4, a4: v5)
       * 100.0;
    v7 = ((double (__thiscall *)(INetChannel *, _DWORD, int))v3->GetAvgLatency)(a1: v3, a2: 0, a3: (int)v6) * 1000.0;
    v8 = ((double (__thiscall *)(INetChannel *, int))v3->GetTimeConnected)(a1: v3, a2: (int)v7);
    v9 = COM_FormatSeconds(seconds: (int)v8);
    v10 = ((int (__thiscall *)(IClient *, char *))client->GetNetworkIDString)(a1: client, a2: v9);
    v11 = ((int (__thiscall *)(IClient *, int))client->GetClientName)(a1: client, a2: v10);
    v12 = ((int (__thiscall *)(IClient *, int))client->GetPlayerSlot)(a1: client, a2: v11);
    v13 = ((int (__thiscall *)(IClient *, int))client->GetUserID)(a1: client, a2: v12 + 1);
    v14 = print;
    print(a1: "# %2i %i \"%s\" %s %s %i %i %s %d", v13);
    if ( bShowAddress )
    {
      v15 = (int)v3->GetAddress(this: v3);
      print(a1: " %s", v15);
      print(a1: "\n");
      return;
    }
  }
  else
  {
    v16 = ((int (__thiscall *)(IClient *, const char *))client->GetNetworkIDString)(a1: client, a2: v4);
    v17 = ((int (__thiscall *)(IClient *, int))client->GetClientName)(a1: client, a2: v16);
    v18 = ((int (__thiscall *)(IClient *, int))client->GetUserID)(a1: client, a2: v17);
    v14 = print;
    print(a1: "#%2i \"%s\" %s %s", v18);
  }
  v14(a1: "\n");
}

//------------------------------------------------------------------------------
// Address: 0x1018ABF0
// Name: void Host_Client_Printf(char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
void Host_Client_Printf(const char *fmt, ...)
{
  char string[1024]; // [esp+0h] [ebp-400h] BYREF
  va_list params; // [esp+40Ch] [ebp+Ch] BYREF

  va_start(params, fmt);
  V_vsnprintf(pDest: string, maxLen: 1024, pFormat: fmt, params);
  host_client->ClientPrintf(this: &host_client->IClient, a2: "%s", string);
}

//------------------------------------------------------------------------------
// Address: 0x1018AC40
// Name: bool CL_HL2Demo_MapCheck(char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl CL_HL2Demo_MapCheck(const char *name)
{
  if ( !CL_IsHL2Demo() || sv.m_bIsDedicated )
    return true;
  return _V_stricmp(s1: name, s2: "d1_trainstation_01") == 0
      || _V_stricmp(s1: name, s2: "d1_trainstation_02") == 0
      || _V_stricmp(s1: name, s2: "d1_town_01") == 0
      || _V_stricmp(s1: name, s2: "d1_town_01a") == 0
      || _V_stricmp(s1: name, s2: "d1_town_02") == 0
      || _V_stricmp(s1: name, s2: "d1_town_03") == 0
      || _V_stricmp(s1: name, s2: "background01") == 0
      || _V_stricmp(s1: name, s2: "background03") == 0;
}

//------------------------------------------------------------------------------
// Address: 0x1018AD10
// Name: bool CL_PortalDemo_MapCheck(char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl CL_PortalDemo_MapCheck(const char *name)
{
  if ( !CL_IsPortalDemo() || sv.m_bIsDedicated )
    return true;
  return _V_stricmp(s1: name, s2: "testchmb_a_00") == 0
      || _V_stricmp(s1: name, s2: "testchmb_a_01") == 0
      || _V_stricmp(s1: name, s2: "testchmb_a_02") == 0
      || _V_stricmp(s1: name, s2: "testchmb_a_03") == 0
      || _V_stricmp(s1: name, s2: "testchmb_a_04") == 0
      || _V_stricmp(s1: name, s2: "testchmb_a_05") == 0
      || _V_stricmp(s1: name, s2: "testchmb_a_06") == 0
      || _V_stricmp(s1: name, s2: "background1") == 0;
}

//------------------------------------------------------------------------------
// Address: 0x1018ADE0
// Name: void Host_Changelevel_f(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Host_Changelevel_f(const CCommand *args)
{
  const char *v1; // eax
  const char *v2; // eax
  const char *v3; // eax
  const char *v4; // ecx

  if ( args->m_nArgc >= 2 )
  {
    if ( sv.m_State >= ss_active )
    {
      v1 = defaultValue;
      if ( args->m_nArgc > 1 )
        v1 = args->m_ppArgv[1];
      if ( g_pVEngineServer->IsMapValid(this: g_pVEngineServer, a2: v1) == 0 )
        goto LABEL_8;
      v2 = defaultValue;
      if ( args->m_nArgc > 1 )
        v2 = args->m_ppArgv[1];
      if ( !CL_HL2Demo_MapCheck(name: v2) )
        goto LABEL_8;
      v3 = defaultValue;
      if ( args->m_nArgc > 1 )
        v3 = args->m_ppArgv[1];
      if ( CL_PortalDemo_MapCheck(name: v3) )
      {
        SetLaunchOptions(args);
        v4 = defaultValue;
        if ( args->m_nArgc > 2 )
          v4 = args->m_ppArgv[2];
        if ( args->m_nArgc > 1 )
          HostState_ChangeLevelMP(pNewLevel: args->m_ppArgv[1], pLandmarkName: v4);
        else
          HostState_ChangeLevelMP(pNewLevel: defaultValue, pLandmarkName: v4);
      }
      else
      {
LABEL_8:
        if ( args->m_nArgc > 1 )
          _Warning(a1: "changelevel failed: %s not found\n", args->m_ppArgv[1]);
        else
          _Warning(a1: "changelevel failed: %s not found\n", defaultValue);
      }
    }
    else
    {
      ConMsg(a1: "Can't changelevel, not running server\n");
    }
  }
  else
  {
    ConMsg(a1: "changelevel <levelname> : continue game on a new level\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x1018AEF0
// Name: void Host_Changelevel2_f(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Host_Changelevel2_f(const CCommand *args)
{
  const char *v1; // eax
  const char *v2; // eax
  const char *v3; // eax
  const char *v4; // eax
  const char *v5; // eax
  const char *v6; // eax
  vgui::CTreeViewListControl *v7; // ecx
  const char *v8; // eax
  vgui::CTreeViewListControl *v9; // ecx
  const char *v10; // eax
  const char *v11; // ecx

  if ( args->m_nArgc >= 2 )
  {
    if ( sv.m_State >= ss_active )
    {
      v1 = defaultValue;
      if ( args->m_nArgc > 1 )
        v1 = args->m_ppArgv[1];
      if ( g_pVEngineServer->IsMapValid(this: g_pVEngineServer, a2: v1) != 0 )
        goto LABEL_23;
      if ( !CL_IsHL2Demo() )
        goto LABEL_16;
      if ( !CL_IsHL2Demo() )
        goto LABEL_23;
      v2 = defaultValue;
      if ( args->m_nArgc > 1 )
        v2 = args->m_ppArgv[1];
      if ( _V_stricmp(s1: v2, s2: "d1_trainstation_03") == 0 )
        goto LABEL_23;
      v3 = defaultValue;
      if ( args->m_nArgc > 1 )
        v3 = args->m_ppArgv[1];
      if ( _V_stricmp(s1: v3, s2: "d1_town_02a") != 0 )
      {
LABEL_16:
        if ( args->m_nArgc > 1 )
          _Warning(a1: "changelevel2 failed: %s not found\n", args->m_ppArgv[1]);
        else
          _Warning(a1: "changelevel2 failed: %s not found\n", defaultValue);
      }
      else
      {
LABEL_23:
        if ( !CL_IsHL2Demo() || sv.m_bIsDedicated )
          goto LABEL_32;
        v4 = defaultValue;
        if ( args->m_nArgc > 1 )
          v4 = args->m_ppArgv[1];
        if ( _V_stricmp(s1: v4, s2: "d1_trainstation_03") != 0 )
        {
LABEL_32:
          if ( !CL_IsHL2Demo() || sv.m_bIsDedicated )
            goto LABEL_38;
          v5 = defaultValue;
          if ( args->m_nArgc > 1 )
            v5 = args->m_ppArgv[1];
          if ( _V_stricmp(s1: v5, s2: "d1_town_02a") != 0 )
            goto LABEL_38;
          v6 = defaultValue;
          if ( args->m_nArgc > 2 )
            v6 = args->m_ppArgv[2];
          if ( _V_stricmp(s1: v6, s2: "d1_town_02_02a") != 0 )
          {
LABEL_38:
            if ( !CL_IsPortalDemo() || sv.m_bIsDedicated )
              goto LABEL_40;
            v8 = defaultValue;
            if ( args->m_nArgc > 1 )
              v8 = args->m_ppArgv[1];
            if ( _V_stricmp(s1: v8, s2: "testchmb_a_07") != 0 )
            {
LABEL_40:
              v10 = defaultValue;
              if ( args->m_nArgc > 1 )
                v10 = args->m_ppArgv[1];
              if ( CL_HL2Demo_MapCheck(name: v10) )
              {
                SetLaunchOptions(args);
                v11 = defaultValue;
                if ( args->m_nArgc > 2 )
                  v11 = args->m_ppArgv[2];
                if ( args->m_nArgc > 1 )
                  HostState_ChangeLevelSP(pNewLevel: args->m_ppArgv[1], pLandmarkName: v11);
                else
                  HostState_ChangeLevelSP(pNewLevel: defaultValue, pLandmarkName: v11);
              }
              else if ( args->m_nArgc > 1 )
              {
                _Warning(a1: "changelevel failed: %s not found\n", args->m_ppArgv[1]);
              }
              else
              {
                _Warning(a1: "changelevel failed: %s not found\n", defaultValue);
              }
            }
            else
            {
              CL_DemoTransitionFromTestChmb(this: v9);
            }
          }
          else
          {
            CL_DemoTransitionFromRavenholm(this: v7);
          }
        }
        else
        {
          CL_DemoTransitionFromTrainstation();
        }
      }
    }
    else
    {
      ConMsg(a1: "Can't changelevel2, not in a map\n");
    }
  }
  else
  {
    ConMsg(a1: "changelevel2 <levelname> : continue game on a new level in the unit\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x1018B150
// Name: void Host_Disconnect(bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Host_Disconnect(BOOL bShowMainMenu)
{
  IGameEvent *v1; // eax
  CClientState *LocalClient; // eax
  IEngineVGuiInternal *v3; // eax

  v1 = g_GameEventManager->CreateEventA(this: g_GameEventManager, a2: "cs_game_disconnected", a3: 0, a4: 0);
  if ( v1 != nullptr )
    g_GameEventManager->FireEventClientSide(this: g_GameEventManager, a2: v1);
  ++g_nHostDisconnectReentrancyCounter;
  if ( bShowMainMenu )
    g_bInCommentaryMode = false;
  if ( !sv.m_bIsDedicated )
  {
    LocalClient = GetLocalClient(nSlot: -1);
    LocalClient->Disconnect(this: LocalClient, a2: bShowMainMenu);
  }
  if ( g_ClientDLL != nullptr && bShowMainMenu )
    ((void (*)(void))g_ClientDLL->ShutdownMovies)();
  Host_AllowQueuedMaterialSystem(bAllow: false);
  HostState_GameShutdown();
  if ( !sv.m_bIsDedicated
    && bShowMainMenu
    && !engineClient->IsDrawingLoadingImage(this: engineClient)
    && GetBaseLocalClient()->demonum == -1 )
  {
    v3 = EngineVGui();
    v3->ActivateGameUI(this: v3);
  }
  --g_nHostDisconnectReentrancyCounter;
}

//------------------------------------------------------------------------------
// Address: 0x1018B220
// Name: disconnect
// Source: json
//------------------------------------------------------------------------------
void __cdecl disconnect(const CCommand *args)
{
  GetBaseLocalClient()->demonum = -1;
  if ( args->m_nArgc > 1 )
    COM_ExplainDisconnection(bPrint: false, fmt: args->m_ppArgv[1]);
  Host_Disconnect(bShowMainMenu: true);
}

//------------------------------------------------------------------------------
// Address: 0x1018B260
// Name: version
// Source: json
//------------------------------------------------------------------------------
void __cdecl version()
{
  int HostVersion; // eax
  CSteam3Client *v1; // eax
  int v2; // eax
  CSteam3Server *v3; // eax
  int v4; // eax
  int v5; // eax
  const char *VersionString; // [esp-8h] [ebp-Ch]
  const char *ProductString; // [esp-4h] [ebp-8h]
  int v8; // [esp-4h] [ebp-8h]
  int v9; // [esp-4h] [ebp-8h]

  ProductString = Sys_GetProductString();
  VersionString = Sys_GetVersionString();
  HostVersion = GetHostVersion();
  ConMsg(a1: "Protocol version %i\nExe version %s (%s)\n", HostVersion, VersionString, ProductString);
  if ( Steam3Client()->m_pSteamUtils != nullptr )
  {
    v1 = Steam3Client();
    v8 = v1->m_pSteamUtils->GetAppID(this: v1->m_pSteamUtils);
    v2 = build_number();
    ConMsg(a1: "Exe build: 03:30:13 Jul 15 2011 (%i) (%i)\n", v2, v8);
  }
  else if ( Steam3Server()->m_pSteamGameServerUtils != nullptr )
  {
    v3 = Steam3Server();
    v9 = v3->m_pSteamGameServerUtils->GetAppID(this: v3->m_pSteamGameServerUtils);
    v4 = build_number();
    ConMsg(a1: "Exe build: 03:30:13 Jul 15 2011 (%i) (%i)\n", v4, v9);
  }
  else
  {
    v5 = build_number();
    ConMsg(a1: "Exe build: 03:30:13 Jul 15 2011 (%i) (%i)\n", v5, 215);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1018B300
// Name: pause
// Source: json
//------------------------------------------------------------------------------
void __cdecl pause(const CCommand *args)
{
  const char *v1; // eax
  const char *v2; // eax
  const char *v3; // [esp-4h] [ebp-4h]

  if ( sv.m_bIsDedicated || GetBaseLocalClient()->m_szLevelName[0] != 0 )
  {
    if ( cmd_source == src_command )
    {
      Cmd_ForwardToServer(args);
    }
    else if ( CGameServer::IsPausable(this: &sv) )
    {
      CBaseServer::SetPaused(this: &sv, paused: sv.m_State != ss_paused);
      v1 = "paused";
      if ( sv.m_State != ss_paused )
        v1 = "unpaused";
      v2 = (const char *)((int (__thiscall *)(IClient *, const char *))host_client->GetClientName)(
                           a1: &host_client->IClient,
                           a2: v1);
      CBaseServer::BroadcastPrintf(this: &sv, fmt: "%s %s the game\n", v2, v3);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1018B3A0
// Name: setpause
// Source: json
//------------------------------------------------------------------------------
void __cdecl setpause(const CCommand *args)
{
  const char *v1; // eax

  if ( sv.m_bIsDedicated || GetBaseLocalClient()->m_szLevelName[0] != 0 )
  {
    if ( cmd_source == src_command )
    {
      Cmd_ForwardToServer(args);
    }
    else
    {
      CBaseServer::SetPaused(this: &sv, paused: true);
      if ( CCommand::FindArg(this: args, pName: "nomsg") == nullptr )
      {
        v1 = host_client->GetClientName(this: &host_client->IClient);
        CBaseServer::BroadcastPrintf(this: &sv, fmt: "%s paused the game\n", v1);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1018B420
// Name: unpause
// Source: json
//------------------------------------------------------------------------------
void __cdecl unpause(const CCommand *args)
{
  const char *v1; // eax

  if ( sv.m_bIsDedicated || GetBaseLocalClient()->m_szLevelName[0] != 0 )
  {
    if ( cmd_source == src_command )
    {
      Cmd_ForwardToServer(args);
    }
    else
    {
      CBaseServer::SetPaused(this: &sv, paused: false);
      if ( CCommand::FindArg(this: args, pName: "nomsg") == nullptr )
      {
        v1 = host_client->GetClientName(this: &host_client->IClient);
        CBaseServer::BroadcastPrintf(this: &sv, fmt: "%s unpaused the game\n", v1);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1018B4A0
// Name: memory
// Source: json
//------------------------------------------------------------------------------
void __cdecl memory()
{
  void (*v0)(const char *, ...); // ebx
  int v1; // eax
  int i; // esi
  const char *CounterName; // ebx
  float v4; // [esp+18h] [ebp-8h]
  float v5; // [esp+1Ch] [ebp-4h]

  v0 = ConMsg;
  ConMsg(a1: "Heap Used:\n");
  v1 = _g_pMemAlloc->GetSize(this: _g_pMemAlloc, a2: nullptr);
  if ( v1 == -1 )
    ConMsg(a1: "Corrupted!\n");
  else
    ConMsg(a1: "%5.2f MB (%d bytes)\n", (double)v1 * 0.00000095367432, v1);
  ConMsg(a1: "\nVideo Memory Used:\n");
  v5 = 0.0;
  for ( i = 0; i < CVProfile::GetNumCounters(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled); ++i )
  {
    if ( CVProfile::GetCounterGroup(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled, a2: i) == COUNTER_GROUP_TEXTURE_GLOBAL )
    {
      v4 = (float)(int)CVProfile::GetCounterValue(
                         this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
                         a2: i)
         * 0.00000095367432;
      v5 = v4 + v5;
      CounterName = CVProfile::GetCounterName(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled, a2: i);
      if ( V_strnicmp(s1: CounterName, s2: "TexGroup_Global_", n: 16) == 0 )
        CounterName += 16;
      ConMsg(a1: "%5.2f MB: %s\n", v4, CounterName);
      v0 = ConMsg;
    }
  }
  v0(a1: "------------------\n");
  v0(a1: "%5.2f MB: total\n", v5);
  v0(a1: "\nHunk Memory Used:\n");
  Hunk_Print();
}

//------------------------------------------------------------------------------
// Address: 0x1018B5E0
// Name: int Host_GetNumDemos(void)
// Source: json
//------------------------------------------------------------------------------
int __cdecl Host_GetNumDemos()
{
  int v0; // edi
  int i; // esi

  v0 = 0;
  for ( i = 0; i < 32; ++i )
  {
    if ( GetBaseLocalClient()->demos[i][0] == 0 )
      break;
    ++v0;
  }
  return v0;
}

//------------------------------------------------------------------------------
// Address: 0x1018B610
// Name: void Host_PrintDemoList(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Host_PrintDemoList()
{
  int v0; // edi
  int i; // esi
  int demonum; // ebx
  int v3; // edi
  int v4; // esi
  bool v5; // zf
  const char *v6; // ebx
  CClientState *BaseLocalClient; // eax
  int v8; // [esp+Ch] [ebp-8h]
  int next; // [esp+10h] [ebp-4h]

  v0 = 0;
  for ( i = 0; i < 32; ++i )
  {
    if ( GetBaseLocalClient()->demos[i][0] == 0 )
      break;
    ++v0;
  }
  v8 = v0;
  demonum = GetBaseLocalClient()->demonum;
  next = demonum;
  if ( demonum >= v0 || demonum < 0 )
  {
    next = 0;
    demonum = 0;
  }
  v3 = 0;
  v4 = 0;
  while ( GetBaseLocalClient()->demos[v4][0] != 0 )
  {
    v5 = demonum == v3;
    v6 = "-->";
    if ( !v5 )
      v6 = "   ";
    BaseLocalClient = GetBaseLocalClient();
    DevMsg(a1: "%3s % 2i : %20s\n", v6, v3++, BaseLocalClient->demos[v4++]);
    if ( v4 >= 32 )
      break;
    demonum = next;
  }
  if ( v8 == 0 )
    DevMsg(a1: "No demos in list, use startdemos <demoname> <demoname2> to specify\n");
}

//------------------------------------------------------------------------------
// Address: 0x1018B6E0
// Name: startdemos
// Source: json
//------------------------------------------------------------------------------
void __cdecl startdemos(const CCommand *args)
{
  int v1; // edi
  int v2; // esi
  int v3; // edi
  const char **v4; // ebx
  const char *v5; // eax
  CClientState *BaseLocalClient; // eax
  const char *v7; // [esp-8h] [ebp-18h]
  int v8; // [esp+Ch] [ebp-4h]

  v1 = args->m_nArgc - 1;
  if ( v1 > 32 )
  {
    _Msg(a1: "Max %i demos in demoloop\n", 32);
    v1 = 32;
  }
  _Msg(a1: "%i demo(s) in loop\n", v1);
  v2 = 1;
  v8 = v1 + 1;
  if ( v1 + 1 > 1 )
  {
    v3 = 32;
    v4 = &args->m_ppArgv[1];
    do
    {
      if ( v2 < 0 || v2 >= args->m_nArgc )
        v5 = defaultValue;
      else
        v5 = *v4;
      v7 = v5;
      BaseLocalClient = GetBaseLocalClient();
      V_strncpy(pDest: (char *)&BaseLocalClient->events.m_Tail + v3, pSrc: v7, maxLen: 32);
      ++v2;
      ++v4;
      v3 += 32;
    }
    while ( v2 < v8 );
  }
  GetBaseLocalClient()->demonum = 0;
  Host_PrintDemoList();
  if ( sv.m_State >= ss_active || demoplayer->IsPlayingBack(this: demoplayer) )
    GetBaseLocalClient()->demonum = -1;
  else
    CL_NextDemo();
}

//------------------------------------------------------------------------------
// Address: 0x1018B7C0
// Name: stopdemo
// Source: json
//------------------------------------------------------------------------------
void __cdecl stopdemo()
{
  if ( demoplayer->IsPlayingBack(this: demoplayer) )
    Host_Disconnect(bShowMainMenu: true);
}

//------------------------------------------------------------------------------
// Address: 0x1018B7E0
// Name: demolist
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __cdecl demolist()
{
  Host_PrintDemoList();
}

//------------------------------------------------------------------------------
// Address: 0x1018B7F0
// Name: killserver
// Source: json
//------------------------------------------------------------------------------
void __cdecl killserver()
{
  IMatchTitle *v0; // eax

  Host_Disconnect(bShowMainMenu: true);
  if ( !sv.m_bIsDedicated )
  {
    NET_SetMultiplayer(multiplayer: false);
    v0 = g_pMatchFramework->GetMatchTitle(this: g_pMatchFramework);
    if ( (v0->GetTitleSettingsFlags(this: v0) & 1) != 0 )
      NET_SetMultiplayer(multiplayer: true);
    else
      NET_SetMultiplayer(multiplayer: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1018B840
// Name: void Host_VoiceToggle_f(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
void __usercall Host_VoiceToggle_f(int a1@<edi>, int a2@<esi>, const CCommand *args)
{
  bool v3; // bl
  const char *v4; // ecx
  const char *v5; // edx
  const char *v6; // esi

  if ( GetBaseLocalClient()->m_nSignonState == 6 )
  {
    v3 = false;
    if ( args->m_nArgc == 2 )
      v3 = V_strcasecmp(s1: args->m_ppArgv[1], s2: "on") == 0;
    if ( !Voice_IsRecording() || v3 )
    {
      if ( v3 && !Voice_IsRecording() )
      {
        v4 = nullptr;
        v5 = nullptr;
        v6 = nullptr;
        if ( voice_recordtofile.m_pParent != nullptr && voice_recordtofile.m_pParent->m_Value.m_nValue != 0 )
        {
          v4 = "voice_micdata.wav";
          v5 = "voice_decompressed.wav";
        }
        if ( voice_inputfromfile.m_pParent != nullptr && voice_inputfromfile.m_pParent->m_Value.m_nValue != 0 )
          v6 = "voice_input.wav";
        Voice_RecordStart(pUncompressedFile: v4, pDecompressedFile: v5, pMicInputFile: v6);
      }
    }
    else
    {
      CL_SendVoicePacket(a1, a2, bFinal: true);
      Voice_RecordStop();
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1018B8F0
// Name: listmodels
// Source: json
//------------------------------------------------------------------------------
void __cdecl listmodels()
{
  modelloader->Print(this: modelloader);
}

//------------------------------------------------------------------------------
// Address: 0x1018B900
// Name: incrementvar
// Source: json
//------------------------------------------------------------------------------
void __cdecl incrementvar(const CCommand *args)
{
  const char *v2; // ebx
  ConVar *v3; // eax
  ConVar *v4; // edi
  const char *v5; // eax
  const char *v6; // eax
  const char *v7; // esi
  long double v8; // st7
  float v9; // xmm0_4
  vgui::CTreeViewListControl *v10; // ecx
  ECommandTarget_t TraceType; // eax
  const char *v12; // eax
  char *v13; // [esp+4h] [ebp-1Ch]
  double v14; // [esp+4h] [ebp-1Ch]
  float v15; // [esp+18h] [ebp-8h]
  float v16; // [esp+1Ch] [ebp-4h]
  float m_fValue; // [esp+28h] [ebp+8h]
  float v18; // [esp+28h] [ebp+8h]

  if ( args->m_nArgc != 5 )
  {
    _Warning(a1: "Usage: incrementvar varName minValue maxValue delta\n");
    return;
  }
  v2 = args->m_ppArgv[1];
  if ( v2 == nullptr )
  {
    _ConDMsg(a1: "Host_IncrementCVar_f without a varname\n");
    return;
  }
  v3 = g_pCVar->FindVar_2(this: g_pCVar, a2: v2);
  v4 = v3;
  if ( v3 == nullptr )
  {
    _ConDMsg(a1: "cvar \"%s\" not found\n", v2);
    return;
  }
  m_fValue = v3->m_pParent->m_Value.m_fValue;
  v5 = defaultValue;
  if ( args->m_nArgc > 2 )
    v5 = args->m_ppArgv[2];
  v16 = atof(nptr: v5);
  v6 = defaultValue;
  if ( args->m_nArgc > 3 )
    v6 = args->m_ppArgv[3];
  v15 = atof(nptr: v6);
  if ( args->m_nArgc > 4 )
    v7 = args->m_ppArgv[4];
  else
    v7 = defaultValue;
  v8 = atof(nptr: v7) + m_fValue;
  v9 = v16;
  v18 = v8;
  if ( v8 > v15 )
    goto LABEL_17;
  if ( v16 > v18 )
  {
    v9 = v15;
LABEL_17:
    v18 = v9;
  }
  v13 = va(format: "%s %f", v2, v18);
  TraceType = CTraceFilter::GetTraceType(this: v10);
  Cbuf_AddText(eTarget: TraceType, pText: v13, nTickDelay: 0);
  v12 = (const char *)((int (__thiscall *)(ConVar *, _DWORD, _DWORD))v4->GetName)(
                        a1: v4,
                        a2: COERCE_UNSIGNED_INT64(v18),
                        a3: HIDWORD(COERCE_UNSIGNED_INT64(v18)));
  _ConDMsg(a1: "%s = %f\n", v12, v14);
}

//------------------------------------------------------------------------------
// Address: 0x1018BA40
// Name: multvar
// Source: json
//------------------------------------------------------------------------------
void __cdecl multvar(const CCommand *args)
{
  const char *v2; // ebx
  ConVar *v3; // eax
  ConVar *v4; // edi
  const char *v5; // eax
  const char *v6; // eax
  const char *v7; // esi
  long double v8; // st7
  float v9; // xmm0_4
  vgui::CTreeViewListControl *v10; // ecx
  ECommandTarget_t TraceType; // eax
  const char *v12; // eax
  char *v13; // [esp+4h] [ebp-1Ch]
  double v14; // [esp+4h] [ebp-1Ch]
  float v15; // [esp+18h] [ebp-8h]
  float v16; // [esp+1Ch] [ebp-4h]
  float m_fValue; // [esp+28h] [ebp+8h]
  float v18; // [esp+28h] [ebp+8h]

  if ( args->m_nArgc != 5 )
  {
    _Warning(a1: "Usage: multvar varName minValue maxValue factor\n");
    return;
  }
  v2 = args->m_ppArgv[1];
  if ( v2 == nullptr )
  {
    _ConDMsg(a1: "multvar without a varname\n");
    return;
  }
  v3 = g_pCVar->FindVar_2(this: g_pCVar, a2: v2);
  v4 = v3;
  if ( v3 == nullptr )
  {
    _ConDMsg(a1: "cvar \"%s\" not found\n", v2);
    return;
  }
  m_fValue = v3->m_pParent->m_Value.m_fValue;
  v5 = defaultValue;
  if ( args->m_nArgc > 2 )
    v5 = args->m_ppArgv[2];
  v15 = atof(nptr: v5);
  v6 = defaultValue;
  if ( args->m_nArgc > 3 )
    v6 = args->m_ppArgv[3];
  v16 = atof(nptr: v6);
  if ( args->m_nArgc > 4 )
    v7 = args->m_ppArgv[4];
  else
    v7 = defaultValue;
  v8 = atof(nptr: v7) * m_fValue;
  v18 = v8;
  if ( v8 > v16 )
  {
    v9 = v16;
LABEL_17:
    v18 = v9;
    goto LABEL_18;
  }
  v9 = v15;
  if ( v15 > v18 )
    goto LABEL_17;
LABEL_18:
  v13 = va(format: "%s %f", v2, v18);
  TraceType = CTraceFilter::GetTraceType(this: v10);
  Cbuf_AddText(eTarget: TraceType, pText: v13, nTickDelay: 0);
  v12 = (const char *)((int (__thiscall *)(ConVar *, _DWORD, _DWORD))v4->GetName)(
                        a1: v4,
                        a2: COERCE_UNSIGNED_INT64(v18),
                        a3: HIDWORD(COERCE_UNSIGNED_INT64(v18)));
  _ConDMsg(a1: "%s = %f\n", v12, v14);
}

//------------------------------------------------------------------------------
// Address: 0x1018BB90
// Name: dumpstringtables
// Source: json
//------------------------------------------------------------------------------
void __cdecl dumpstringtables()
{
  SV_PrintStringTables();
  CL_PrintStringTables();
}

//------------------------------------------------------------------------------
// Address: 0x1018BBA0
// Name: stringtabledictionary
// Source: json
//------------------------------------------------------------------------------
void __cdecl stringtabledictionary()
{
  if ( sv.m_State >= ss_active )
    SV_CreateDictionary(pchMapName: sv.m_szMapname);
  else
    _Warning(a1: "stringtabledictionary: only valid when running a map\n");
}

//------------------------------------------------------------------------------
// Address: 0x1018BBD0
// Name: crash
// Source: json
//------------------------------------------------------------------------------
void __cdecl crash()
{
  _Msg(a1: "forcing crash\n");
  MEMORY[0] = 0;
}

//------------------------------------------------------------------------------
// Address: 0x1018BBF0
// Name: flush
// Source: json
//------------------------------------------------------------------------------
void __cdecl flush()
{
  g_ClientDLL->InvalidateMdlCache(this: g_ClientDLL);
  serverGameDLL->InvalidateMdlCache(this: serverGameDLL);
  g_pDataCache->Flush(this: g_pDataCache, a2: true, a3: true);
  wavedatacache->Flush(this: wavedatacache, a2: false);
}

//------------------------------------------------------------------------------
// Address: 0x1018BC40
// Name: flush_locked
// Source: json
//------------------------------------------------------------------------------
void __cdecl flush_locked()
{
  g_ClientDLL->InvalidateMdlCache(this: g_ClientDLL);
  serverGameDLL->InvalidateMdlCache(this: serverGameDLL);
  g_pDataCache->Flush(this: g_pDataCache, a2: false, a3: true);
  wavedatacache->Flush(this: wavedatacache, a2: false);
}

//------------------------------------------------------------------------------
// Address: 0x1018BC90
// Name: cache_print
// Source: json
//------------------------------------------------------------------------------
void __cdecl cache_print(const CCommand *args)
{
  const char *v1; // eax

  v1 = nullptr;
  if ( args->m_nArgc == 2 )
    v1 = args->m_ppArgv[1];
  g_pDataCache->OutputReport(this: g_pDataCache, a2: DC_DETAIL_REPORT, a3: v1);
}

//------------------------------------------------------------------------------
// Address: 0x1018BCC0
// Name: cache_print_lru
// Source: json
//------------------------------------------------------------------------------
void __cdecl cache_print_lru(const CCommand *args)
{
  const char *v1; // eax

  v1 = nullptr;
  if ( args->m_nArgc == 2 )
    v1 = args->m_ppArgv[1];
  g_pDataCache->OutputReport(this: g_pDataCache, a2: DC_DETAIL_REPORT_LRU, a3: v1);
}

//------------------------------------------------------------------------------
// Address: 0x1018BCF0
// Name: cache_print_summary
// Source: json
//------------------------------------------------------------------------------
void __cdecl cache_print_summary(const CCommand *args)
{
  const char *v1; // eax

  v1 = nullptr;
  if ( args->m_nArgc == 2 )
    v1 = args->m_ppArgv[1];
  g_pDataCache->OutputReport(this: g_pDataCache, a2: DC_SUMMARY_REPORT, a3: v1);
}

//------------------------------------------------------------------------------
// Address: 0x1018BD20
// Name: ss_disconnect
// Source: json
//------------------------------------------------------------------------------
void __cdecl ss_disconnect(const CCommand *args)
{
  int v1; // edx
  int v2; // eax
  int v3; // eax
  CCommand argsClient; // [esp+0h] [ebp-608h] BYREF
  char buf[256]; // [esp+508h] [ebp-100h] BYREF

  if ( cmd_source == src_command )
  {
    v1 = -1;
    v2 = 1;
    if ( host_state.max_splitscreen_players > 1 )
    {
      while ( v2 != 0 )
      {
        if ( ++v2 >= host_state.max_splitscreen_players )
          goto LABEL_7;
      }
      v1 = 0;
    }
LABEL_7:
    if ( args->m_nArgc <= 1 )
    {
      if ( v1 != 0 )
      {
        _Msg(a1: "Can't ss_disconnect, no split screen users active\n");
        return;
      }
    }
    else
    {
      v3 = V_atoi(str: args->m_ppArgv[1]);
      if ( v3 != 0 )
      {
        _Msg(a1: "Can't ss_disconnect, slot %d not active\n", v3);
        return;
      }
    }
    V_snprintf(pDest: buf, maxLen: 256, pFormat: "ss_disconnect %d\n", 0);
    CCommand::CCommand(this: &argsClient);
    CCommand::Tokenize(this: &argsClient, pCommand: buf, pBreakSet: nullptr);
    Cmd_ForwardToServer(args: &argsClient);
    splitscreen->SetDisconnecting(this: splitscreen, a2: 0, a3: true);
  }
  else
  {
    CBaseClient::SplitScreenDisconnect(this: host_client, args);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1018BE10
// Name: restart
// Source: json
//------------------------------------------------------------------------------
void __cdecl restart(const CCommand *args)
{
  IGameEvent *v1; // eax
  CClientState *LocalClient; // eax
  bool bRememberLocation; // [esp+0h] [ebp-4h]

  if ( !demoplayer->IsPlayingBack(this: demoplayer)
    && sv.m_State >= ss_active
    && sv.m_nMaxclients <= 1
    && cmd_source == src_command )
  {
    if ( args->m_nArgc != 2 || (bRememberLocation = true, _V_stricmp(s1: args->m_ppArgv[1], s2: "setpos") != 0) )
      bRememberLocation = false;
    v1 = g_GameEventManager->CreateEventA(this: g_GameEventManager, a2: "cs_game_disconnected", a3: 0, a4: 0);
    if ( v1 != nullptr )
      g_GameEventManager->FireEventClientSide(this: g_GameEventManager, a2: v1);
    ++g_nHostDisconnectReentrancyCounter;
    if ( !sv.m_bIsDedicated )
    {
      LocalClient = GetLocalClient(nSlot: -1);
      LocalClient->Disconnect(this: LocalClient, a2: false);
    }
    Host_AllowQueuedMaterialSystem(bAllow: false);
    HostState_GameShutdown();
    --g_nHostDisconnectReentrancyCounter;
    if ( CL_HL2Demo_MapCheck(name: sv.m_szMapname) && CL_PortalDemo_MapCheck(name: sv.m_szMapname) )
      HostState_NewGame(
        pMapName: sv.m_szMapname,
        remember_location: bRememberLocation,
        background: false,
        bSplitScreenConnect: false);
    else
      _Warning(a1: "map load failed: %s not found or invalid\n", sv.m_szMapname);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1018BF30
// Name: reload
// Source: json
//------------------------------------------------------------------------------
void __usercall reload(int a1@<edi>, const CCommand *args)
{
  bool v2; // zf
  const char *v3; // edi
  CStatTime *v4; // ecx
  KeyValues *v5; // eax
  KeyValues *v6; // esi
  IMatchEventsSubscription *v7; // eax
  char *m_pszString; // eax
  char *v9; // eax
  char *v10; // eax
  char *v11; // eax
  char *v12; // eax
  char name[260]; // [esp+0h] [ebp-108h] BYREF
  BOOL remember_location; // [esp+104h] [ebp-4h]

  if ( !demoplayer->IsPlayingBack(this: demoplayer)
    && sv.m_State >= ss_active
    && sv.m_nMaxclients <= 1
    && serverGameDLL->SupportsSaveRestore(this: serverGameDLL)
    && cmd_source == src_command )
  {
    v2 = args->m_nArgc == 2;
    LOBYTE(remember_location) = 0;
    if ( v2 )
      LOBYTE(remember_location) = _V_stricmp(s1: args->m_ppArgv[1], s2: "setpos") == 0;
    v3 = (const char *)((int (__thiscall *)(ISaveRestore *, char *, int, int))saverestore->FindRecentSave)(
                         a1: saverestore,
                         a2: name,
                         a3: 260,
                         a4: a1);
    SCR_BeginLoadingPlaque(a1: v4, a2: (int)v3, levelName: nullptr);
    v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v5 != nullptr )
      v6 = KeyValues::KeyValues(this: v5, setName: "OnEngineClientSignonStatePrepareChange");
    else
      v6 = nullptr;
    KeyValues::SetString(this: v6, keyName: "reason", value: "reload");
    v7 = g_pMatchFramework->GetEventsSubscription(this: g_pMatchFramework);
    v7->BroadcastEvent(this: v7, a2: v6);
    Host_Disconnect(bShowMainMenu: false);
    if ( v3 != nullptr && saverestore->SaveFileExists(this: saverestore, a2: v3) )
    {
      HostState_LoadGame(pSaveFileName: v3, remember_location, bLetToolsOverrideLoadGameEnts: false);
      return;
    }
    if ( (host_map.m_nFlags & 0x1000) != 0 )
    {
      m_pszString = "FCVAR_NEVER_AS_STRING";
    }
    else
    {
      m_pszString = host_map.m_pParent->m_Value.m_pszString;
      if ( m_pszString == nullptr )
        m_pszString = (char *)defaultValue;
    }
    if ( !CL_HL2Demo_MapCheck(name: m_pszString) )
    {
      if ( (host_map.m_nFlags & 0x1000) != 0 )
      {
LABEL_20:
        _Warning(a1: "map load failed: %s not found or invalid\n", "FCVAR_NEVER_AS_STRING");
        return;
      }
      v9 = host_map.m_pParent->m_Value.m_pszString;
      if ( v9 == nullptr )
        v9 = (char *)defaultValue;
      goto LABEL_23;
    }
    if ( (host_map.m_nFlags & 0x1000) != 0 )
    {
      v10 = "FCVAR_NEVER_AS_STRING";
    }
    else
    {
      v10 = host_map.m_pParent->m_Value.m_pszString;
      if ( v10 == nullptr )
        v10 = (char *)defaultValue;
    }
    if ( !CL_PortalDemo_MapCheck(name: v10) )
    {
      if ( (host_map.m_nFlags & 0x1000) != 0 )
        goto LABEL_20;
      v9 = host_map.m_pParent->m_Value.m_pszString;
      if ( v9 == nullptr )
        v9 = (char *)defaultValue;
LABEL_23:
      _Warning(a1: "map load failed: %s not found or invalid\n", v9);
      return;
    }
    if ( v3 != nullptr && *v3 != 0 )
    {
      if ( (host_map.m_nFlags & 0x1000) != 0 )
      {
        v11 = "FCVAR_NEVER_AS_STRING";
      }
      else
      {
        v11 = host_map.m_pParent->m_Value.m_pszString;
        if ( v11 == nullptr )
          v11 = (char *)defaultValue;
      }
      _Warning(a1: "SAVERESTORE PROBLEM: %s not found!  Starting new game in %s\n", v3, v11);
    }
    if ( (host_map.m_nFlags & 0x1000) != 0 )
    {
      v12 = "FCVAR_NEVER_AS_STRING";
    }
    else
    {
      v12 = host_map.m_pParent->m_Value.m_pszString;
      if ( v12 == nullptr )
        v12 = (char *)defaultValue;
    }
    HostState_NewGame(pMapName: v12, remember_location, background: false, bSplitScreenConnect: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1018C1C0
// Name: demos
// Source: json
//------------------------------------------------------------------------------
void __cdecl demos(const CCommand *args)
{
  CClientState *BaseLocalClient; // esi
  int demonum; // edi
  IGameEvent *v3; // eax
  CClientState *LocalClient; // eax
  int NumDemos; // eax
  int v6; // ebx
  const char *v7; // eax
  int v8; // eax

  BaseLocalClient = GetBaseLocalClient();
  demonum = BaseLocalClient->demonum;
  BaseLocalClient->demonum = -1;
  v3 = g_GameEventManager->CreateEventA(this: g_GameEventManager, a2: "cs_game_disconnected", a3: 0, a4: 0);
  if ( v3 != nullptr )
    g_GameEventManager->FireEventClientSide(this: g_GameEventManager, a2: v3);
  ++g_nHostDisconnectReentrancyCounter;
  if ( !sv.m_bIsDedicated )
  {
    LocalClient = GetLocalClient(nSlot: -1);
    LocalClient->Disconnect(this: LocalClient, a2: false);
  }
  Host_AllowQueuedMaterialSystem(bAllow: false);
  HostState_GameShutdown();
  --g_nHostDisconnectReentrancyCounter;
  BaseLocalClient->demonum = demonum;
  if ( demonum == -1 )
    BaseLocalClient->demonum = 0;
  if ( args->m_nArgc == 2 )
  {
    NumDemos = Host_GetNumDemos();
    if ( NumDemos >= 1 )
    {
      v6 = NumDemos - 1;
      v7 = defaultValue;
      if ( args->m_nArgc > 1 )
        v7 = args->m_ppArgv[1];
      v8 = V_atoi(str: v7);
      if ( v8 >= 0 )
      {
        if ( v8 > v6 )
          v8 = v6;
      }
      else
      {
        v8 = 0;
      }
      BaseLocalClient->demonum = v8;
      DevMsg(a1: "Jumping to %s\n", BaseLocalClient->demos[v8]);
    }
  }
  Host_PrintDemoList();
  CL_NextDemo();
}

//------------------------------------------------------------------------------
// Address: 0x1018C2C0
// Name: nextdemo
// Source: json
//------------------------------------------------------------------------------
void __cdecl nextdemo(const CCommand *args)
{
  int NumDemos; // eax
  int v2; // esi
  const char *v3; // edi
  int v4; // eax
  int demonum; // esi
  CClientState *BaseLocalClient; // eax

  if ( args->m_nArgc == 2 )
  {
    NumDemos = Host_GetNumDemos();
    if ( NumDemos >= 1 )
    {
      v2 = NumDemos - 1;
      if ( args->m_nArgc > 1 )
        v3 = args->m_ppArgv[1];
      else
        v3 = defaultValue;
      v4 = V_atoi(str: v3);
      if ( v4 >= 0 )
      {
        if ( v4 <= v2 )
          v2 = v4;
      }
      else
      {
        v2 = 0;
      }
      GetBaseLocalClient()->demonum = v2;
      demonum = GetBaseLocalClient()->demonum;
      BaseLocalClient = GetBaseLocalClient();
      DevMsg(a1: "Jumping to %s\n", BaseLocalClient->demos[demonum]);
    }
  }
  Host_EndGame(bShowMainMenu: false, message: "Moving to next demo...");
}

//------------------------------------------------------------------------------
// Address: 0x1018C350
// Name: soundfade
// Source: json
//------------------------------------------------------------------------------
void __cdecl soundfade(const CCommand *args)
{
  int m_nArgc; // eax
  bool v3; // cc
  const char *v4; // eax
  long double v5; // st7
  long double v6; // st6
  long double v7; // st7
  const char *v8; // eax
  long double v9; // st7
  const char *v10; // eax
  long double v11; // st7
  const char *v12; // eax
  const char *v13; // eax
  long double v14; // st7
  float v15; // [esp+Ch] [ebp-14h]
  float holdtime; // [esp+14h] [ebp-Ch]
  float intime; // [esp+18h] [ebp-8h]
  float holdTime; // [esp+28h] [ebp+8h]

  m_nArgc = args->m_nArgc;
  if ( args->m_nArgc == 3 || m_nArgc == 5 )
  {
    v3 = m_nArgc <= 1;
    v4 = defaultValue;
    if ( !v3 )
      v4 = args->m_ppArgv[1];
    v5 = atof(nptr: v4);
    v6 = 0.0;
    if ( v5 < 0.0 || (v6 = v5, v7 = 100.0, v6 <= 100.0) )
      v7 = v6;
    holdtime = v7;
    v8 = defaultValue;
    if ( args->m_nArgc > 2 )
      v8 = args->m_ppArgv[2];
    v3 = atof(nptr: v8) >= 0.0;
    v9 = 0.0;
    if ( v3 )
    {
      v10 = defaultValue;
      if ( args->m_nArgc > 2 )
        v10 = args->m_ppArgv[2];
      v9 = atof(nptr: v10);
    }
    intime = v9;
    holdTime = 0.0;
    if ( args->m_nArgc == 5 )
    {
      v3 = atof(nptr: args->m_ppArgv[3]) >= 0.0;
      v11 = 0.0;
      if ( v3 )
      {
        v12 = defaultValue;
        if ( args->m_nArgc > 3 )
          v12 = args->m_ppArgv[3];
        v11 = atof(nptr: v12);
      }
      holdTime = v11;
      v13 = defaultValue;
      if ( args->m_nArgc > 4 )
        v13 = args->m_ppArgv[4];
      v3 = atof(nptr: v13) >= 0.0;
      v14 = 0.0;
      if ( v3 )
      {
        if ( args->m_nArgc > 4 )
          v14 = atof(nptr: args->m_ppArgv[4]);
        else
          v14 = atof(nptr: defaultValue);
      }
    }
    else
    {
      v14 = 0.0;
    }
    v15 = v14;
    S_SoundFade(percent: holdtime, holdtime: intime, intime: holdTime, outtime: v15);
  }
  else
  {
    _Msg(a1: "soundfade <percent> <hold> [<out> <int>]\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x1018C4B0
// Name: void Host_VoiceRecordStart_f(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Host_VoiceRecordStart_f()
{
  const char *v0; // ecx
  const char *v1; // edx
  const char *v2; // esi
  ConVarRef voice_vox; // [esp+0h] [ebp-8h] BYREF

  ConVarRef::ConVarRef(this: &voice_vox, pName: "voice_vox");
  if ( voice_vox.m_pConVarState->m_Value.m_nValue == 0 && GetLocalClient(nSlot: 0)->m_nSignonState == 6 )
  {
    v0 = nullptr;
    v1 = nullptr;
    v2 = nullptr;
    if ( voice_recordtofile.m_pParent != nullptr && voice_recordtofile.m_pParent->m_Value.m_nValue != 0 )
    {
      v0 = "voice_micdata.wav";
      v1 = "voice_decompressed.wav";
    }
    if ( voice_inputfromfile.m_pParent != nullptr && voice_inputfromfile.m_pParent->m_Value.m_nValue != 0 )
      v2 = "voice_input.wav";
    Voice_RecordStart(pUncompressedFile: v0, pDecompressedFile: v1, pMicInputFile: v2);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1018C520
// Name: void Host_VoiceRecordStop_f(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
void __usercall Host_VoiceRecordStop_f(int a1@<edi>, int a2@<esi>, const CCommand *args)
{
  ConVarRef voice_vox; // [esp+0h] [ebp-8h] BYREF

  ConVarRef::ConVarRef(this: &voice_vox, pName: "voice_vox");
  if ( voice_vox.m_pConVarState->m_Value.m_nValue == 0 && GetLocalClient(nSlot: 0)->m_nSignonState == 6 )
  {
    if ( Voice_IsRecording() )
    {
      CL_SendVoicePacket(a1, a2, bFinal: true);
      Voice_RecordStop();
    }
    if ( args->m_nArgc != 2 || V_strcasecmp(s1: args->m_ppArgv[1], s2: "force") != 0 )
      voice_vox.m_pConVar->SetValue_2(this: voice_vox.m_pConVar, a2: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1018C5A0
// Name: status
// Source: json
//------------------------------------------------------------------------------
void __cdecl status(const CCommand *args)
{
  void (*v1)(const char *, ...); // ebx
  char *m_pszString; // eax
  const char *v3; // esi
  ISteamGameServer *m_pSteamGameServer; // ecx
  ISteamGameServer *v5; // ecx
  CSteam3Client *v6; // eax
  int v7; // eax
  CSteam3Server *v8; // eax
  const char *v9; // eax
  const char *v10; // ecx
  const char *VersionString; // eax
  const char *v12; // esi
  char *v13; // eax
  IHLTVDirector *v14; // eax
  CHLTVServer *v15; // esi
  unsigned __int64 v16; // st7
  int v17; // eax
  bool v18; // zf
  const char *v19; // eax
  int j; // edi
  CBaseClient *v21; // eax
  IClient *v22; // esi
  const char *v23; // eax
  int i; // edi
  CBaseClient *v25; // eax
  IClient *v26; // esi
  int HostVersion; // [esp-Ch] [ebp-30h]
  int v28; // [esp-8h] [ebp-2Ch]
  const char *v29; // [esp-4h] [ebp-28h]
  int UDPPort; // [esp-4h] [ebp-28h]
  double v31; // [esp+0h] [ebp-24h]
  const char *v32; // [esp+4h] [ebp-20h]
  int v33; // [esp+14h] [ebp-10h] BYREF
  int v34; // [esp+18h] [ebp-Ch] BYREF
  int nMaxHumanSlots; // [esp+1Ch] [ebp-8h] BYREF
  int nHumans; // [esp+20h] [ebp-4h]

  if ( cmd_source == src_command )
  {
    if ( sv.m_State < ss_active )
    {
      Cmd_ForwardToServer(args);
      return;
    }
    v1 = ConMsg;
  }
  else
  {
    v1 = Host_Client_Printf;
  }
  if ( (host_name.m_nFlags & 0x1000) != 0 )
  {
    m_pszString = "FCVAR_NEVER_AS_STRING";
  }
  else
  {
    m_pszString = host_name.m_pParent->m_Value.m_pszString;
    if ( m_pszString == nullptr )
      m_pszString = (char *)defaultValue;
  }
  v1(a1: "hostname: %s\n", m_pszString);
  v3 = defaultValue;
  m_pSteamGameServer = Steam3Server()->m_pSteamGameServer;
  if ( m_pSteamGameServer != nullptr && m_pSteamGameServer->BSecure(this: m_pSteamGameServer) )
  {
    HIBYTE(nHumans) = 1;
  }
  else
  {
    HIBYTE(nHumans) = 0;
    if ( Steam3Server()->m_eServerMode == eServerModeAuthenticationAndSecure )
    {
      v5 = Steam3Server()->m_pSteamGameServer;
      if ( v5 == nullptr || (v3 = "(secure mode enabled, connected to Steam3)", !v5->BLoggedOn(this: v5)) )
        v3 = "(secure mode enabled, disconnected from Steam3)";
    }
  }
  if ( Steam3Client()->m_pSteamUtils != nullptr )
  {
    v6 = Steam3Client();
    v7 = v6->m_pSteamUtils->GetConnectedUniverse(this: v6->m_pSteamUtils);
  }
  else if ( Steam3Server()->m_pSteamGameServerUtils != nullptr )
  {
    v8 = Steam3Server();
    v7 = v8->m_pSteamGameServerUtils->GetConnectedUniverse(this: v8->m_pSteamGameServerUtils);
  }
  else
  {
    v7 = 0;
  }
  switch ( v7 )
  {
    case 1:
      v9 = defaultValue;
      break;
    case 2:
      v9 = "(beta)";
      break;
    case 3:
      v9 = "(internal)";
      break;
    case 4:
      v9 = "(dev)";
      break;
    case 5:
      v9 = "(rc)";
      break;
    default:
      v9 = "(unknown)";
      break;
  }
  v10 = "secure";
  if ( HIBYTE(nHumans) == 0 )
    v10 = "insecure";
  v32 = v9;
  v29 = v10;
  v28 = build_number();
  HostVersion = GetHostVersion();
  VersionString = Sys_GetVersionString();
  v1(a1: "version : %s/%d %d %s %s %s\n", VersionString, HostVersion, v28, v29, v3, v32);
  if ( NET_IsMultiplayer() )
  {
    v12 = "dedicated";
    if ( !sv.m_bIsDedicated )
      v12 = "listen";
    UDPPort = NET_GetUDPPort(socket: sv.m_Socket);
    v13 = netadr_s::ToString(this: &net_local_adr, baseOnly: true);
    v1(a1: "udp/ip  :  %s:%i os(%s) type(%s)\n", v13, UDPPort, "Windows", v12);
  }
  if ( !sv.m_bIsDedicated && GetBaseLocalClient()->m_nSignonState >= 2 )
    v1(
      a1: "map     : %s at: %d x, %d y, %d z\n",
      sv.m_szMapname,
      (int)g_MainViewOrigin[0].x,
      (int)g_MainViewOrigin[0].y,
      (int)g_MainViewOrigin[0].z);
  if ( hltv != nullptr && hltv->IsActive(this: &hltv->CBaseServer) )
  {
    v14 = hltv->GetDirector(this: &hltv->IHLTVServer);
    v15 = hltv;
    *(double *)&v16 = ((double (__thiscall *)(IHLTVDirector *))v14->GetDelay)(a1: v14);
    v17 = ((int (__thiscall *)(CBaseServer *, _DWORD, _DWORD))v15->GetUDPPort)(
            a1: &v15->CBaseServer,
            a2: v16,
            a3: HIDWORD(v16));
    v1(a1: "sourcetv:  port %i, delay %.1fs\n", v17, v31);
  }
  CBaseServer::GetMasterServerPlayerCounts(this: &sv, nHumans: &v33, &nMaxHumanSlots, nBots: &v34);
  v18 = !CGameServer::IsHibernating(this: &sv);
  v19 = "hibernating";
  if ( v18 )
    v19 = "not hibernating";
  v1(a1: "players : %i humans, %i bots (%i max) (%s)\n\n", v33, v34, nMaxHumanSlots, v19);
  if ( args->m_nArgc != 2 || _V_stricmp(s1: args->m_ppArgv[1], s2: "short") != 0 )
  {
    v1(a1: "# userid name uniqueid connected ping loss state rate");
    if ( cmd_source == src_command )
      v1(a1: " adr");
    v1(a1: "\n");
    for ( i = 0; i < sv.m_Clients.m_Size; ++i )
    {
      v25 = sv.m_Clients.m_Memory.m_pMemory[i];
      if ( v25 != nullptr )
        v26 = &v25->IClient;
      else
        v26 = nullptr;
      if ( v26->IsConnected(this: v26) )
        Host_Status_PrintClient(client: v26, bShowAddress: cmd_source == src_command, print: v1);
    }
    v1(a1: "#end\n");
  }
  else
  {
    for ( j = 0; j < sv.m_Clients.m_Size; ++j )
    {
      v21 = sv.m_Clients.m_Memory.m_pMemory[j];
      if ( v21 != nullptr )
        v22 = &v21->IClient;
      else
        v22 = nullptr;
      if ( v22->IsActive(this: v22) )
      {
        v23 = v22->GetClientName(this: v22);
        v1(a1: "#%i - %s\n", j + 1, v23);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1018C950
// Name: ping
// Source: json
//------------------------------------------------------------------------------
void __usercall ping(int a1@<esi>, const CCommand *args)
{
  int v2; // edi
  CBaseClient *v3; // esi
  IClient *v4; // esi
  int v5; // eax
  IClient_vtbl *v6; // edi
  int v7; // ebx
  double v8; // st7
  int i; // [esp+14h] [ebp-4h]

  if ( cmd_source == src_command )
  {
    Cmd_ForwardToServer(args);
  }
  else
  {
    ((void (__stdcall *)(IClient *))host_client->ClientPrintf)(a1: &host_client->IClient);
    v2 = 0;
    for ( i = 0; v2 < sv.m_Clients.m_Size; i = v2 )
    {
      v3 = sv.m_Clients.m_Memory.m_pMemory[v2];
      if ( v3 != nullptr )
        v4 = &v3->IClient;
      else
        v4 = nullptr;
      if ( v4->IsConnected(this: v4) && !v4->IsFakeClient(this: v4) )
      {
        v5 = ((int (__thiscall *)(IClient *, int))v4->GetNetChannel)(a1: v4, a2: a1);
        v6 = host_client->CBaseClient::IClient::INetChannelHandler::__vftable;
        v7 = v5;
        a1 = (int)v4->GetClientName(this: v4);
        v8 = ((double (__thiscall *)(int, _DWORD))*(_DWORD *)(*(_DWORD *)v7 + 40))(a1: v7, a2: 0);
        v6->ClientPrintf(this: &host_client->IClient, a2: "%4.0f ms : %s\n", v8 * 1000.0);
        v2 = i;
      }
      ++v2;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1018CA40
// Name: kickid
// Source: json
//------------------------------------------------------------------------------
void __cdecl kickid(const CCommand *args)
{
  int m_nArgc; // eax
  int v2; // edi
  const char *v3; // eax
  const char *v4; // ecx
  const char *v5; // eax
  const char *v6; // esi
  int m_nArgv0Size; // eax
  int v8; // esi
  const char **v9; // ebx
  const char *v10; // eax
  int v11; // ebx
  CBaseClient *v12; // eax
  int v13; // esi
  int v14; // edi
  int v15; // edx
  bool v16; // zf
  const char *v17; // eax
  IClient *v18; // eax
  int v19; // ecx
  char szSearchString[128]; // [esp+8h] [ebp-94h] BYREF
  char *who; // [esp+88h] [ebp-14h]
  int iSearchIndex; // [esp+8Ch] [ebp-10h]
  int argsStartNum; // [esp+90h] [ebp-Ch]
  const char *pszMessage; // [esp+94h] [ebp-8h]
  bool bSteamID; // [esp+9Bh] [ebp-1h]

  m_nArgc = args->m_nArgc;
  v2 = 0;
  who = "Console";
  pszMessage = nullptr;
  iSearchIndex = -1;
  argsStartNum = 1;
  bSteamID = false;
  if ( m_nArgc > 1 )
  {
    v6 = args->m_ppArgv[1];
    if ( *v6 < 48 || *v6 > 57 )
    {
      if ( V_strnicmp(s1: v6, s2: "STEAM_", n: 6) != 0 )
        goto LABEL_16;
      v3 = defaultValue;
      if ( args->m_nArgc > 2 )
        v3 = args->m_ppArgv[2];
      if ( _V_strstr(s1: v3, search: ":") == nullptr )
      {
LABEL_16:
        V_snprintf(pDest: szSearchString, maxLen: 128, pFormat: "%s", v6);
      }
      else
      {
        v4 = defaultValue;
        if ( args->m_nArgc > 5 )
          v4 = args->m_ppArgv[5];
        v5 = defaultValue;
        if ( args->m_nArgc > 3 )
          v5 = args->m_ppArgv[3];
        V_snprintf(pDest: szSearchString, maxLen: 128, pFormat: "%s:%s:%s", v6, v5, v4);
        argsStartNum = 5;
        bSteamID = true;
      }
    }
    else
    {
      iSearchIndex = V_atoi(str: args->m_ppArgv[1]);
    }
    if ( args->m_nArgc > argsStartNum )
    {
      m_nArgv0Size = args->m_nArgv0Size;
      if ( m_nArgv0Size != 0 )
        pszMessage = &args->m_pArgSBuffer[m_nArgv0Size];
      else
        pszMessage = defaultValue;
      v8 = 1;
      if ( argsStartNum >= 1 )
      {
        v9 = &args->m_ppArgv[1];
        do
        {
          if ( v8 < 0 || v8 >= args->m_nArgc )
            v10 = defaultValue;
          else
            v10 = *v9;
          ++v8;
          ++v9;
          v2 += _V_strlen(str: v10) + 1;
        }
        while ( v8 <= argsStartNum );
      }
      if ( bSteamID )
        v2 -= 5;
      if ( v2 <= _V_strlen(str: pszMessage) )
        pszMessage += v2;
      else
        pszMessage = nullptr;
    }
    v11 = 0;
    if ( sv.m_Clients.m_Size <= 0 )
      goto LABEL_43;
    while ( 1 )
    {
      v12 = sv.m_Clients.m_Memory.m_pMemory[v11];
      v13 = v12 != nullptr ? (int)&v12->IClient : 0;
      if ( (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v13 + 124))(a1: v13) != 0 )
      {
        v14 = iSearchIndex;
        v15 = *(_DWORD *)v13;
        if ( iSearchIndex == -1 )
        {
          v17 = (const char *)(*(int (__thiscall **)(int))(v15 + 84))(a1: v13);
          v16 = _V_stricmp(s1: v17, s2: szSearchString) == 0;
        }
        else
        {
          v16 = (*(int (__thiscall **)(int))(v15 + 60))(a1: v13) == v14;
        }
        if ( v16 )
          break;
      }
      if ( ++v11 >= sv.m_Clients.m_Size )
        goto LABEL_43;
    }
    if ( v11 >= sv.m_Clients.m_Size )
    {
LABEL_43:
      if ( iSearchIndex == -1 )
        ConMsg(a1: "uniqueid \"%s\" not found\n", szSearchString);
      else
        ConMsg(a1: "userid \"%d\" not found\n", iSearchIndex);
    }
    else
    {
      if ( (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v13 + 156))(a1: v13) != 0
        && (*(int (__thiscall **)(int))(*(_DWORD *)v13 + 168))(a1: v13) != 0 )
      {
        v13 = (*(int (__thiscall **)(int))(*(_DWORD *)v13 + 168))(a1: v13);
      }
      if ( cmd_source != src_command )
        who = host_client->m_Name;
      if ( host_client != nullptr )
        v18 = &host_client->IClient;
      else
        v18 = nullptr;
      if ( (v18 != (IClient *)v13 || sv.m_bIsDedicated)
        && (iSearchIndex != -1 || (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v13 + 136))(a1: v13) == 0) )
      {
        v19 = *(_DWORD *)v13;
        if ( pszMessage != nullptr )
          (*(void (**)(int, const char *, ...))(v19 + 52))(a1: v13, a2: "Kicked by %s : %s", who, pszMessage);
        else
          (*(void (**)(int, const char *, ...))(v19 + 52))(a1: v13, a2: "Kicked by %s", who);
      }
    }
  }
  else
  {
    ConMsg(a1: "Usage:  kickid < userid | uniqueid > { message }\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x1018CD40
// Name: kick
// Source: json
//------------------------------------------------------------------------------
void __cdecl kick(const CCommand *args)
{
  bool v1; // cc
  int m_nArgv0Size; // eax
  bool v3; // zf
  const char *v4; // eax
  char *v5; // ebx
  int v6; // eax
  char *v7; // eax
  int v8; // edi
  CBaseClient *v9; // eax
  int v10; // esi
  const char *v11; // eax
  char *m_Name; // ecx
  IClient *v13; // eax
  char name[64]; // [esp+4h] [ebp-44h] BYREF
  char *who; // [esp+44h] [ebp-4h]

  v1 = args->m_nArgc <= 1;
  who = "Console";
  if ( v1 )
  {
    ConMsg(a1: "Usage:  kick < name >\n");
  }
  else
  {
    memset(dst: (unsigned __int8 *)name, value: 0, count: sizeof(name));
    m_nArgv0Size = args->m_nArgv0Size;
    v3 = m_nArgv0Size == 0;
    v4 = &args->m_pArgSBuffer[m_nArgv0Size];
    if ( v3 )
      v4 = defaultValue;
    V_strncpy(pDest: name, pSrc: v4, maxLen: 64);
    v5 = name;
    if ( name[0] != 0 )
    {
      v6 = _V_strlen(str: name);
      if ( name[0] == 34 )
      {
        v3 = name[v6 - 1] == 34;
        v7 = &name[v6 - 1];
        if ( v3 )
        {
          *v7 = 0;
          v5 = &name[1];
        }
      }
      v8 = 0;
      if ( sv.m_Clients.m_Size <= 0 )
        goto LABEL_16;
      while ( 1 )
      {
        v9 = sv.m_Clients.m_Memory.m_pMemory[v8];
        v10 = v9 != nullptr ? (int)&v9->IClient : 0;
        if ( (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v10 + 124))(a1: v10) != 0 )
        {
          v11 = (const char *)(*(int (__thiscall **)(int))(*(_DWORD *)v10 + 68))(a1: v10);
          if ( V_strcasecmp(s1: v11, s2: v5) == 0 )
            break;
        }
        if ( ++v8 >= sv.m_Clients.m_Size )
          goto LABEL_16;
      }
      if ( v8 >= sv.m_Clients.m_Size )
      {
LABEL_16:
        ConMsg(a1: "Can't kick \"%s\", name not found\n", v5);
      }
      else
      {
        if ( (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v10 + 156))(a1: v10) != 0
          && (*(int (__thiscall **)(int))(*(_DWORD *)v10 + 168))(a1: v10) != 0 )
        {
          v10 = (*(int (__thiscall **)(int))(*(_DWORD *)v10 + 168))(a1: v10);
        }
        m_Name = host_client->m_Name;
        if ( cmd_source == src_command )
          m_Name = who;
        if ( host_client != nullptr )
          v13 = &host_client->IClient;
        else
          v13 = nullptr;
        if ( v13 != (IClient *)v10 || sv.m_bIsDedicated )
          (*(void (**)(int, const char *, ...))(*(_DWORD *)v10 + 52))(a1: v10, a2: "Kicked by %s", m_Name);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1018CEA0
// Name: void Host_PrintMemoryStatus(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Host_PrintMemoryStatus(const char *mapname)
{
  unsigned int v1; // eax
  _MEMORYSTATUS Buffer; // [esp+20h] [ebp-24h] BYREF
  signed int dwTotalPhys; // [esp+40h] [ebp-4h]

  GlobalMemoryStatus(lpBuffer: &Buffer);
  dwTotalPhys = Buffer.dwTotalPhys;
  _Msg(
    a1: "[MEMORYSTATUS] [%s] Operating system reports Available: %.2f MB, Used: %.2f MB, Free: %.2f MB\n",
    mapname,
    0.00000095367432 * (double)Buffer.dwTotalPhys - 32.0,
    (double)(Buffer.dwTotalPhys - Buffer.dwAvailPhys) * 0.00000095367432 - 32.0,
    (double)Buffer.dwAvailPhys * 0.00000095367432);
  _g_pMemAlloc->SetStatsExtraInfo(this: _g_pMemAlloc, a2: mapname, a3: defaultValue);
  v1 = _g_pMemAlloc->GetSize(this: _g_pMemAlloc, a2: nullptr);
  dwTotalPhys = v1;
  if ( v1 == -1 )
    _Msg(a1: "Internal heap corrupted!\n");
  else
    _Msg(a1: "Internal heap reports: %5.2f MB (%d bytes)\n", (double)dwTotalPhys * 0.00000095367432, v1);
  _Msg(a1: "\nHunk Memory Used:\n");
  Hunk_Print();
  _Msg(a1: "\nDatacache reports:\n");
  ((void (__thiscall *)(IDataCache *, _DWORD))g_pDataCache->OutputReport)(a1: g_pDataCache, a2: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1018CFB0
// Name: Host_Map_Helper_FuzzyName
// Source: json
//------------------------------------------------------------------------------
char __usercall Host_Map_Helper_FuzzyName@<al>(const CCommand *args@<esi>, char *name, int bufsize)
{
  char *v3; // eax
  int m_nArgv0Size; // eax
  bool v5; // zf
  char *v6; // eax
  const char *v7; // eax
  int v8; // eax
  const char *v10; // [esp-8h] [ebp-1018h]
  char commands[64]; // [esp+0h] [ebp-1010h] BYREF
  CUtlString v12; // [esp+1000h] [ebp-10h] BYREF

  CUtlString::CUtlString(this: &v12);
  v3 = (char *)defaultValue;
  if ( args->m_nArgc > 0 )
    v3 = (char *)args->m_ppArgv[0];
  CUtlString::operator=(this: &v12, src: v3);
  CUtlString::operator+=(this: &v12, rhs: " ");
  m_nArgv0Size = args->m_nArgv0Size;
  v5 = m_nArgv0Size == 0;
  v6 = &args->m_pArgSBuffer[m_nArgv0Size];
  if ( v5 )
    v6 = (char *)defaultValue;
  v10 = v6;
  v7 = CUtlString::operator char const *(this: &v12);
  if ( _Host_Map_f_CompletionFunc(cmdname: v7, partial: v10, (char (*)[64])commands) <= 0 )
  {
    v12.m_Storage.m_nActualLength = 0;
    if ( v12.m_Storage.m_Memory.m_nGrowSize >= 0 && v12.m_Storage.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v12.m_Storage.m_Memory.m_pMemory);
    return 0;
  }
  else
  {
    v8 = CUtlString::Length(this: &v12);
    V_strncpy(pDest: name, pSrc: &commands[v8], maxLen: bufsize);
    v12.m_Storage.m_nActualLength = 0;
    if ( v12.m_Storage.m_Memory.m_nGrowSize >= 0 && v12.m_Storage.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v12.m_Storage.m_Memory.m_pMemory);
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1018D090
// Name: void Host_Map_Helper(class CCommand const __near &,enum EMapFlags)
// Source: json
//------------------------------------------------------------------------------
void __usercall Host_Map_Helper(int a1@<edi>, const CCommand *args, EMapFlags flags)
{
  bool v3; // cc
  const char *v4; // eax
  const char *v5; // eax
  const char *v6; // eax
  const char *v7; // eax
  const char *v8; // eax
  const char *v9; // eax
  const char *v10; // eax
  const char *v11; // esi
  char name[96]; // [esp+0h] [ebp-E4h] BYREF
  char ppath[96]; // [esp+60h] [ebp-84h] BYREF
  Vector newpos; // [esp+C0h] [ebp-24h] BYREF
  QAngle newangle; // [esp+CCh] [ebp-18h] BYREF
  BOOL bBackground; // [esp+DBh] [ebp-9h]
  BOOL bSplitScreenConnect; // [esp+DFh] [ebp-5h]
  bool bCommentary; // [esp+E3h] [ebp-1h]

  if ( cmd_source == src_command )
  {
    if ( args->m_nArgc >= 2 )
    {
      if ( sv.m_State < ss_active || CBaseServer::IsSinglePlayerGame(this: &sv) || sv.m_bIsLevelMainMenuBackground )
      {
        v3 = args->m_nArgc <= 1;
        LOBYTE(bBackground) = (flags & 2) != 0;
        LOBYTE(bSplitScreenConnect) = (flags & 8) != 0;
        v4 = defaultValue;
        if ( !v3 )
          v4 = args->m_ppArgv[1];
        V_StripExtension(in: v4, out: ppath, outSize: 96);
        if ( modelloader->Map_IsValid(this: modelloader, a2: ppath, a3: true)
          || (Host_Map_Helper_FuzzyName(args, name: ppath, bufsize: 96),
              modelloader->Map_IsValid(this: modelloader, a2: ppath, a3: false)) )
        {
          GetPlatformMapPath(pMapPath: ppath, pPlatformMapPath: name, maxLength: 96);
          bCommentary = (flags & 4) != 0;
          if ( (flags & 1) != 0 )
          {
            g_bInEditMode = true;
          }
          else if ( g_bInEditMode )
          {
            Host_ReadConfiguration(a1: flags, a2: a1, a3: (int)args, iController: -1);
            g_bInEditMode = false;
          }
          g_bInCommentaryMode = bCommentary;
          SetLaunchOptions(args);
          if ( CL_HL2Demo_MapCheck(name) && CL_PortalDemo_MapCheck(name) )
          {
            GetBaseLocalClient()->demonum = -1;
            Host_Disconnect(bShowMainMenu: false);
            HostState_NewGame(pMapName: name, remember_location: false, background: bBackground, bSplitScreenConnect);
            if ( args->m_nArgc == 10 && _V_stricmp(s1: args->m_ppArgv[2], s2: "setpos") == 0 )
            {
              v5 = defaultValue;
              if ( args->m_nArgc > 6 )
                v5 = args->m_ppArgv[6];
              if ( _V_stricmp(s1: v5, s2: "setang") == 0 )
              {
                v6 = defaultValue;
                if ( args->m_nArgc > 3 )
                  v6 = args->m_ppArgv[3];
                newpos.x = atof(nptr: v6);
                v7 = defaultValue;
                if ( args->m_nArgc > 4 )
                  v7 = args->m_ppArgv[4];
                newpos.y = atof(nptr: v7);
                v8 = defaultValue;
                if ( args->m_nArgc > 5 )
                  v8 = args->m_ppArgv[5];
                newpos.z = atof(nptr: v8);
                v9 = defaultValue;
                if ( args->m_nArgc > 7 )
                  v9 = args->m_ppArgv[7];
                newangle.x = atof(nptr: v9);
                v10 = defaultValue;
                if ( args->m_nArgc > 8 )
                  v10 = args->m_ppArgv[8];
                newangle.y = atof(nptr: v10);
                if ( args->m_nArgc > 9 )
                  v11 = args->m_ppArgv[9];
                else
                  v11 = defaultValue;
                newangle.z = atof(nptr: v11);
                HostState_SetSpawnPoint(position: &newpos, angle: &newangle);
              }
            }
          }
          else
          {
            _Warning(a1: "map load failed: %s not found or invalid\n", name);
          }
        }
        else
        {
          _Warning(a1: "map load failed: %s not found or invalid\n", ppath);
        }
      }
      else
      {
        Host_Changelevel_f(args);
      }
    }
    else
    {
      _Warning(a1: "No map specified\n");
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1018D380
// Name: void Host_Map_f(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
void __usercall Host_Map_f(int a1@<edi>, const CCommand *args)
{
  Host_Map_Helper(a1, args, flags: EMAP_NONE);
}

//------------------------------------------------------------------------------
// Address: 0x1018D3A0
// Name: void Host_SplitScreen_Map_f(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
void __usercall Host_SplitScreen_Map_f(int a1@<edi>, const CCommand *args)
{
  Host_Map_Helper(a1, args, flags: EMAP_SPLITSCREEN);
}

//------------------------------------------------------------------------------
// Address: 0x1018D3C0
// Name: map_edit
// Source: json
//------------------------------------------------------------------------------
void __usercall map_edit(int a1@<edi>, const CCommand *args)
{
  Host_Map_Helper(a1, args, flags: EMAP_EDIT_MODE);
}

//------------------------------------------------------------------------------
// Address: 0x1018D3E0
// Name: void Host_Map_Background_f(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
void __usercall Host_Map_Background_f(int a1@<edi>, const CCommand *args)
{
  Host_Map_Helper(a1, args, flags: EMAP_BACKGROUND);
}

//------------------------------------------------------------------------------
// Address: 0x1018D400
// Name: void Host_Map_Commentary_f(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
void __usercall Host_Map_Commentary_f(int a1@<edi>, const CCommand *args)
{
  Host_Map_Helper(a1, args, flags: EMAP_COMMENTARY);
}

//------------------------------------------------------------------------------
// Address: 0x1018D420
// Name: ss_connect
// Source: json
//------------------------------------------------------------------------------
void __usercall ss_connect(int a1@<esi>)
{
  int v1; // esi
  CClientState *BaseLocalClient; // eax
  CLC_SplitPlayerConnect msg; // [esp+0h] [ebp-24h] BYREF

  if ( cmd_source == src_command )
  {
    if ( host_state.max_splitscreen_players == 1 )
    {
      if ( toolframework->InToolMode(this: toolframework) )
        _Msg(a1: "Can't ss_connect, split screen not supported when running -tools mode.\n");
      else
        _Msg(a1: "Can't ss_connect, game does not support split screen.\n");
    }
    else if ( GetBaseLocalClient()->m_nSignonState >= 2 )
    {
      v1 = 1;
      if ( ((unsigned __int8 (__thiscall *)(ISplitScreen *, int, int))splitscreen->IsValidSplitScreenSlot)(
             a1: splitscreen,
             a2: 1,
             a3: a1) != 0 )
      {
        do
          ++v1;
        while ( splitscreen->IsValidSplitScreenSlot(this: splitscreen, a2: v1) );
      }
      if ( v1 < host_state.max_splitscreen_players )
      {
        msg.m_bReliable = true;
        msg.m_NetChannel = nullptr;
        msg.__vftable = (CLC_SplitPlayerConnect_vtbl *)&CLC_SplitPlayerConnect::`vftable';
        memset(&msg.m_UserInfo, 0, sizeof(msg.m_UserInfo));
        Host_BuildUserInfoUpdateMessage(nSplitScreenSlot: v1, rCvarList: &msg.m_UserInfo, nonDefault: false);
        BaseLocalClient = GetBaseLocalClient();
        ((void (__thiscall *)(INetChannel *, CLC_SplitPlayerConnect *, _DWORD))BaseLocalClient->m_NetChannel->SendNetMsg)(
          a1: BaseLocalClient->m_NetChannel,
          a2: &msg,
          a3: 0);
        CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&msg.m_UserInfo);
      }
      else
      {
        _Msg(a1: "Can't ss_connect, no more split screen player slots!\n");
      }
    }
    else
    {
      _Msg(a1: "Can't ss_connect, not connected to game.\n");
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102F2568
// Name: __flush
// Source: json
//------------------------------------------------------------------------------
int __cdecl _flush(_iobuf *str)
{
  int flag; // eax
  int v2; // ebx
  char *base; // eax
  char *v4; // edi
  int v5; // eax
  int v6; // eax
  char *v7; // eax
  char *v9; // [esp-Ch] [ebp-14h]
  char *v10; // [esp-8h] [ebp-10h]

  flag = str->_flag;
  v2 = 0;
  if ( (flag & 3) == 2 && (flag & 0x108) != 0 )
  {
    base = str->_base;
    v4 = (char *)(str->_ptr - base);
    if ( (int)v4 > 0 )
    {
      v10 = (char *)(str->_ptr - base);
      v9 = str->_base;
      v5 = fileno(stream: str);
      if ( (char *)_write(fh: v5, buf: v9, cnt: (unsigned int)v10) == v4 )
      {
        v6 = str->_flag;
        if ( (v6 & 0x80u) != 0 )
          str->_flag = v6 & 0xFFFFFFFD;
      }
      else
      {
        str->_flag |= 0x20u;
        v2 = -1;
      }
    }
  }
  v7 = str->_base;
  str->_cnt = 0;
  str->_ptr = v7;
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x102F25D0
// Name: __fflush_nolock
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _fflush_nolock(_iobuf *str)
{
  int v2; // eax

  if ( str == nullptr )
    return flsall(flushflag: 0);
  if ( _flush(str) != 0 )
    return -1;
  if ( (str->_flag & 0x4000) == 0 )
    return 0;
  v2 = fileno(stream: str);
  return -(_commit(filedes: v2) != 0);
}

//------------------------------------------------------------------------------
// Address: 0x102F2618
// Name: flsall
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl flsall(int flushflag)
{
  int i; // esi
  char **v2; // eax
  char *v3; // eax
  int v4; // ecx
  int result; // eax
  int err; // [esp+10h] [ebp-24h]
  int count; // [esp+18h] [ebp-1Ch]

  count = 0;
  err = 0;
  _lock(locknum: 1);
  for ( i = 0; i < (int)_nstream; ++i )
  {
    v2 = (char **)&__piob[i];
    if ( *v2 != nullptr )
    {
      v3 = *v2;
      if ( (v3[12] & 0x83) != 0 )
      {
        _lock_file2(i, s: v3);
        v4 = *((_DWORD *)__piob[i] + 3);
        if ( (v4 & 0x83) != 0 )
        {
          if ( flushflag == 1 )
          {
            if ( _fflush_nolock(str: (_iobuf *)__piob[i]) != -1 )
              ++count;
          }
          else if ( flushflag == 0 && (v4 & 2) != 0 && _fflush_nolock(str: (_iobuf *)__piob[i]) == -1 )
          {
            err = -1;
          }
        }
        _unlock_file2(i, s: (char *)__piob[i]);
      }
    }
  }
  _unlock(locknum: 1);
  result = count;
  if ( flushflag != 1 )
    return err;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102F26F2
// Name: _fflush
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl fflush(_iobuf *stream)
{
  int rc; // [esp+10h] [ebp-1Ch]

  if ( stream == nullptr )
    return flsall(flushflag: 0);
  _lock_file(pf: stream);
  rc = _fflush_nolock(str: stream);
  _unlock_file(pf: stream);
  return rc;
}

//------------------------------------------------------------------------------
// Address: 0x102F2745
// Name: __flushall
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _flushall()
{
  return flsall(flushflag: 1);
}

//------------------------------------------------------------------------------
// Address: 0x102F274E
// Name: ___crtCorExitProcess
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl __crtCorExitProcess(int status)
{
  HMODULE ModuleHandleW; // eax
  FARPROC CorExitProcess; // eax

  ModuleHandleW = GetModuleHandleW(lpModuleName: L"mscoree.dll");
  if ( ModuleHandleW != nullptr )
  {
    CorExitProcess = GetProcAddress(hModule: ModuleHandleW, lpProcName: "CorExitProcess");
    if ( CorExitProcess != nullptr )
      ((void (__stdcall *)(int))CorExitProcess)(a1: status);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102F2779
// Name: ___crtExitProcess
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl __noreturn __crtExitProcess(int status)
{
  __crtCorExitProcess(status);
  ExitProcess(uExitCode: status);
}

//------------------------------------------------------------------------------
// Address: 0x102F2791
// Name: __lockexit
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void _lockexit()
{
  _lock(locknum: 8);
}

//------------------------------------------------------------------------------
// Address: 0x102F279A
// Name: __unlockexit
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void _unlockexit()
{
  _unlock(locknum: 8);
}

//------------------------------------------------------------------------------
// Address: 0x102F27A3
// Name: __init_pointers
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void _init_pointers()
{
  void *v0; // esi

  v0 = (void *)_encoded_null();
  _initp_heap_handler(enull: v0);
  _initp_misc_invarg(enull: v0);
  _initp_misc_purevirt(enull: v0);
  _initp_misc_rand_s(enull: v0);
  _initp_misc_winsig(enull: v0);
  _initp_eh_hooks(enull: v0);
}

//------------------------------------------------------------------------------
// Address: 0x102F27D6
// Name: __initterm_e
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _initterm_e(int (__cdecl **pfbegin)(), int (__cdecl **pfend)())
{
  int result; // eax

  result = 0;
  while ( pfbegin < pfend && result == 0 )
  {
    if ( *pfbegin != nullptr )
      result = (*pfbegin)();
    ++pfbegin;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102F27FA
// Name: __cinit
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _cinit(int initFloatingPrecision)
{
  int result; // eax
  void (**i)(void); // edi

  if ( _fpmath != nullptr && _IsNonwritableInCurrentImage(pTarget: (unsigned __int8 *)&_FPinit) != 0 )
    _fpmath(initPrecision: initFloatingPrecision);
  _initp_misc_cfltcvt_tab();
  result = _initterm_e(pfbegin: __xi_a, pfend: __xi_z);
  if ( result == 0 )
  {
    atexit(func: _RTC_Terminate);
    for ( i = __xc_a; i < __xc_z; ++i )
    {
      if ( *i != nullptr )
        (*i)();
    }
    if ( __dyn_tls_init_callback != nullptr
      && _IsNonwritableInCurrentImage(pTarget: (unsigned __int8 *)&__dyn_tls_init_callback) != 0 )
    {
      __dyn_tls_init_callback(a1: nullptr, a2: 2u, a3: nullptr);
    }
    return 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102F2891
// Name: doexit
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl doexit(int code, int quick, int retcaller)
{
  PVOID *v3; // ebx
  PVOID *v4; // edi
  void (*v5)(void); // ebx
  void (__cdecl **v6)(); // ebx
  void (__cdecl **v7)(); // eax
  void (__cdecl **onexitbegin)(); // [esp+10h] [ebp-30h]
  void (__cdecl **onexitend_saved)(); // [esp+18h] [ebp-28h]
  void (__cdecl **onexitbegin_saved)(); // [esp+1Ch] [ebp-24h]
  void (**j)(void); // [esp+20h] [ebp-20h]
  void (**i)(void); // [esp+24h] [ebp-1Ch]

  _lock(locknum: 8);
  if ( _C_Exit_Done != 1 )
  {
    _C_Termination_Done = 1;
    _exitflag = retcaller;
    if ( quick == 0 )
    {
      v3 = (PVOID *)DecodePointer(Ptr: __onexitbegin);
      onexitbegin = (void (__cdecl **)())v3;
      if ( v3 != nullptr )
      {
        v4 = (PVOID *)DecodePointer(Ptr: __onexitend);
        onexitbegin_saved = (void (__cdecl **)())v3;
        onexitend_saved = (void (__cdecl **)())v4;
        while ( --v4 >= v3 )
        {
          if ( *v4 != (PVOID)_encoded_null() )
          {
            if ( v4 < v3 )
              break;
            v5 = (void (*)(void))DecodePointer(Ptr: *v4);
            *v4 = (PVOID)_encoded_null();
            v5();
            v6 = (void (__cdecl **)())DecodePointer(Ptr: __onexitbegin);
            v7 = (void (__cdecl **)())DecodePointer(Ptr: __onexitend);
            if ( onexitbegin_saved != v6 || onexitend_saved != v7 )
            {
              onexitbegin_saved = v6;
              onexitbegin = v6;
              onexitend_saved = v7;
              v4 = (PVOID *)v7;
            }
            v3 = (PVOID *)onexitbegin;
          }
        }
      }
      for ( i = __xp_a; i < __xp_z; ++i )
      {
        if ( *i != nullptr )
          (*i)();
      }
    }
    for ( j = __xt_a; j < __xt_z; ++j )
    {
      if ( *j != nullptr )
        (*j)();
    }
  }
  if ( retcaller != 0 )
    _unlock(locknum: 8);
  if ( retcaller == 0 )
  {
    _C_Exit_Done = 1;
    _unlock(locknum: 8);
    __crtExitProcess(status: code);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102F29D1
// Name: _exit
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl __noreturn exit(int code)
{
  doexit(code, quick: 0, retcaller: 0);
}

//------------------------------------------------------------------------------
// Address: 0x102F29E7
// Name: __exit
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl __noreturn _exit(int code)
{
  doexit(code, quick: 1, retcaller: 0);
}

//------------------------------------------------------------------------------
// Address: 0x102F29FD
// Name: __cexit
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _cexit()
{
  doexit(code: 0, quick: 0, retcaller: 1);
}

//------------------------------------------------------------------------------
// Address: 0x102F2A0C
// Name: __amsg_exit
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl __noreturn _amsg_exit(int rterrnum)
{
  _FF_MSGBANNER();
  _NMSG_WRITE(rterrnum);
  _exit(code: 255);
}

//------------------------------------------------------------------------------
// Address: 0x102F2A2A
// Name: ___libm_sse2_atan2
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl __libm_sse2_atan2()
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x102F2F40
// Name: ___libm_sse2_cos
// Source: linker_block_proximity
//------------------------------------------------------------------------------
double __usercall __libm_sse2_cos@<st0>(__m128i a1@<xmm0>)
{
  double result; // st7

  if ( (__int16)((_mm_extract_epi16(a1, 3) & 0x7FFF) - 12336) > 4293 && (_mm_extract_epi16(a1, 3) & 0x7FF0) != 0x7FF0 )
    return cos(X: *(double *)a1.m128i_i64);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102F30EB
// Name: ___libm_sse2_asin
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl __libm_sse2_asin()
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x102F3534
// Name: ___libm_sse2_tan
// Source: linker_block_proximity
//------------------------------------------------------------------------------
double __usercall __libm_sse2_tan@<st0>(__m128i a1@<xmm0>)
{
  double result; // st7

  if ( (__int16)((_mm_extract_epi16(a1, 3) & 0x7FFF) - 14368) > 2216
    && COERCE_DOUBLE(*(_QWORD *)sign_mask & a1.m128i_i64[0] ^ a1.m128i_i64[0]) != *(double *)INF_1 )
  {
    return tan(X: *(double *)a1.m128i_i64);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102F3789
// Name: __freea
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _freea(_DWORD *_Memory)
{
  if ( _Memory != nullptr && *(_Memory - 2) == 56797 )
    free(pMem: _Memory - 2);
}

//------------------------------------------------------------------------------
// Address: 0x102F37B0
// Name: _strncat
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char *__cdecl strncat(char *Destination, const char *Source, size_t Count)
{
  size_t v3; // ecx
  char *v4; // edi
  char v5; // al
  int v6; // eax
  int v7; // eax
  char *v8; // edi
  const char *v9; // esi
  char v10; // bl
  size_t v11; // ecx
  int v12; // edx
  char v13; // dl
  int v15; // eax

  v3 = Count;
  if ( Count == 0 )
    return Destination;
  v4 = Destination;
  if ( ((unsigned __int8)Destination & 3) == 0 )
    goto find_end_of_front_string_loop;
  do
  {
    v5 = *v4++;
    if ( v5 == 0 )
    {
start_byte_3:
      v8 = v4 - 1;
      goto copy_start;
    }
  }
  while ( ((unsigned __int8)v4 & 3) != 0 );
  while ( 1 )
  {
    do
    {
find_end_of_front_string_loop:
      v6 = (*(_DWORD *)v4 + 2130640639) ^ ~*(_DWORD *)v4;
      v4 += 4;
    }
    while ( (v6 & 0x81010100) == 0 );
    v7 = *((_DWORD *)v4 - 1);
    if ( (_BYTE)v7 == 0 )
      break;
    if ( BYTE1(v7) == 0 )
    {
      v8 = v4 - 3;
      goto copy_start;
    }
    if ( (v7 & 0xFF0000) == 0 )
    {
      v8 = v4 - 2;
      goto copy_start;
    }
    if ( (v7 & 0xFF000000) == 0 )
      goto start_byte_3;
  }
  v8 = v4 - 4;
copy_start:
  v9 = Source;
  if ( ((unsigned __int8)Source & 3) == 0 )
  {
    v10 = Count;
    v11 = Count >> 2;
    if ( Count >> 2 != 0 )
      goto main_loop_entrance_0;
tail_loop_start_0:
    v3 = v10 & 3;
    if ( (v10 & 3) != 0 )
    {
      while ( 1 )
      {
        v13 = *v9++;
        *v8++ = v13;
        if ( v13 == 0 )
          break;
        if ( --v3 == 0 )
          goto empty_counter;
      }
    }
    else
    {
empty_counter:
      *v8 = v3;
    }
    return Destination;
  }
  do
  {
    LOBYTE(v12) = *v9++;
    if ( (_BYTE)v12 == 0 )
    {
LABEL_26:
      *v8 = v12;
      return Destination;
    }
    *v8++ = v12;
    if ( --v3 == 0 )
      goto empty_counter;
  }
  while ( ((unsigned __int8)v9 & 3) != 0 );
  v10 = v3;
  v11 = v3 >> 2;
  if ( v11 == 0 )
    goto tail_loop_start_0;
  while ( 1 )
  {
main_loop_entrance_0:
    v15 = (*(_DWORD *)v9 + 2130640639) ^ ~*(_DWORD *)v9;
    v12 = *(_DWORD *)v9;
    v9 += 4;
    if ( (v15 & 0x81010100) != 0 )
    {
      if ( (_BYTE)v12 == 0 )
        goto LABEL_26;
      if ( BYTE1(v12) == 0 )
        break;
      if ( (v12 & 0xFF0000) == 0 )
      {
        *(_WORD *)v8 = v12;
        v8[2] = 0;
        return Destination;
      }
      if ( (v12 & 0xFF000000) == 0 )
      {
        *(_DWORD *)v8 = v12;
        return Destination;
      }
    }
    *(_DWORD *)v8 = v12;
    v8 += 4;
    if ( --v11 == 0 )
      goto tail_loop_start_0;
  }
  *(_WORD *)v8 = (unsigned __int8)v12;
  return Destination;
}

//------------------------------------------------------------------------------
// Address: 0x102F38E5
// Name: __vsnwprintf_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _vsnwprintf_l(
        unsigned __int16 *string,
        unsigned int count,
        const wchar_t *format,
        localeinfo_struct *plocinfo,
        char *ap)
{
  int result; // eax
  int v6; // edi
  _iobuf str; // [esp+8h] [ebp-20h] BYREF

  memset(&str, 0, sizeof(str));
  if ( format != nullptr && (count == 0 || string != nullptr) )
  {
    str._flag = 66;
    str._base = (char *)string;
    str._ptr = (char *)string;
    if ( count <= 0x3FFFFFFF )
      str._cnt = 2 * count;
    else
      str._cnt = 0x7FFFFFFF;
    result = _woutput_l(stream: &str, format, plocinfo, argptr: ap);
    v6 = result;
    if ( string != nullptr )
    {
      if ( --str._cnt < 0 )
        _flsbuf(ch: 0, &str);
      else
        *str._ptr++ = 0;
      if ( --str._cnt < 0 )
        _flsbuf(ch: 0, &str);
      else
        *str._ptr = 0;
      return v6;
    }
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return -1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102F39B6
// Name: __vsnwprintf
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _vsnwprintf(unsigned __int16 *string, unsigned int count, const wchar_t *format, char *ap)
{
  return _vsnwprintf_l(string, count, format, plocinfo: nullptr, ap);
}

//------------------------------------------------------------------------------
// Address: 0x102F39D3
// Name: __vswprintf_helper
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _vswprintf_helper(
        int (__cdecl *woutfn)(_iobuf *, const wchar_t *, localeinfo_struct *, char *),
        unsigned __int16 *string,
        unsigned int count,
        const wchar_t *format,
        localeinfo_struct *plocinfo,
        char *ap)
{
  int result; // eax
  bool v7; // sf
  _iobuf str; // [esp+8h] [ebp-20h] BYREF
  int retval; // [esp+3Ch] [ebp+14h]

  memset(&str, 0, sizeof(str));
  if ( format == nullptr || count != 0 && string == nullptr )
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return -1;
  }
  str._flag = 66;
  str._base = (char *)string;
  str._ptr = (char *)string;
  if ( count <= 0x3FFFFFFF )
    str._cnt = 2 * count;
  else
    str._cnt = 0x7FFFFFFF;
  result = woutfn(a1: &str, a2: format, a3: plocinfo, a4: ap);
  retval = result;
  if ( string != nullptr )
  {
    if ( result >= 0 )
    {
      if ( --str._cnt >= 0 )
      {
        *str._ptr++ = 0;
LABEL_13:
        if ( --str._cnt >= 0 )
        {
          *str._ptr = 0;
          return retval;
        }
        if ( _flsbuf(ch: 0, &str) != -1 )
          return retval;
        goto LABEL_17;
      }
      if ( _flsbuf(ch: 0, &str) != -1 )
        goto LABEL_13;
    }
LABEL_17:
    v7 = str._cnt < 0;
    string[count - 1] = 0;
    return !v7 - 2;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102F3AC9
// Name: __vswprintf_c_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _vswprintf_c_l(
        unsigned __int16 *string,
        unsigned int count,
        const wchar_t *format,
        localeinfo_struct *plocinfo,
        char *ap)
{
  int result; // eax

  result = _vswprintf_helper(woutfn: _woutput_l, string, count, format, plocinfo, ap);
  if ( result < 0 )
    return -1;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102F3AF3
// Name: strtoxq
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned __int64 __cdecl strtoxq(
        localeinfo_struct *plocinfo,
        const char *nptr,
        const char **endptr,
        int ibase,
        int flags)
{
  char v6; // cl
  threadlocaleinfostruct *locinfo; // esi
  const char *i; // edi
  int v9; // eax
  char v10; // al
  const unsigned __int16 *pctype; // ebx
  unsigned int v12; // esi
  int v13; // eax
  char v14; // al
  _LocaleUpdate _loc_update; // [esp+4h] [ebp-3Ch] BYREF
  int v16; // [esp+18h] [ebp-28h]
  unsigned __int64 v17; // [esp+1Ch] [ebp-24h]
  unsigned __int64 maxval; // [esp+24h] [ebp-1Ch]
  unsigned __int64 number; // [esp+2Ch] [ebp-14h]
  const char *p; // [esp+38h] [ebp-8h]
  char c; // [esp+3Fh] [ebp-1h]

  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  if ( endptr != nullptr )
    *endptr = nptr;
  if ( nptr == nullptr || ibase != 0 && (ibase < 2 || ibase > 36) )
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return 0;
  }
  v6 = *nptr;
  locinfo = _loc_update.localeinfo.locinfo;
  number = 0;
  c = v6;
  for ( i = nptr + 1; ; ++i )
  {
    if ( locinfo->mb_cur_max <= 1 )
    {
      v9 = locinfo->pctype[(unsigned __int8)c] & 8;
    }
    else
    {
      v9 = _isctype_l((unsigned __int8)c, mask: 8, plocinfo: &_loc_update.localeinfo);
      locinfo = _loc_update.localeinfo.locinfo;
    }
    if ( v9 == 0 )
      break;
    c = *i;
  }
  p = i;
  if ( c == 45 )
  {
    flags |= 2u;
  }
  else if ( c != 43 )
  {
    goto LABEL_20;
  }
  v10 = *i++;
  p = i;
  c = v10;
LABEL_20:
  if ( ibase == 0 )
  {
    if ( c != 48 )
    {
      ibase = 10;
      goto LABEL_32;
    }
    if ( *i != 120 && *i != 88 )
    {
      ibase = 8;
      goto LABEL_32;
    }
    ibase = 16;
  }
  if ( ibase == 16 && c == 48 && (*i == 120 || *i == 88) )
  {
    c = i[1];
    p = i + 2;
  }
LABEL_32:
  v16 = ibase >> 31;
  pctype = locinfo->pctype;
  v17 = 0xFFFFFFFFFFFFFFFFuLL % ibase;
  maxval = 0xFFFFFFFFFFFFFFFFuLL / ibase;
  while ( 1 )
  {
    if ( (pctype[(unsigned __int8)c] & 4) != 0 )
    {
      v12 = c - 48;
    }
    else
    {
      if ( (pctype[(unsigned __int8)c] & 0x103) == 0 )
        break;
      v13 = c;
      if ( (unsigned __int8)(c - 97) <= 0x19u )
        v13 = c - 32;
      v12 = v13 - 55;
    }
    if ( v12 >= ibase )
      break;
    flags |= 8u;
    if ( number < maxval || number == maxval && v12 <= v17 )
    {
      number = v12 + __PAIR64__(v16, ibase) * number;
    }
    else
    {
      flags |= 4u;
      if ( endptr == nullptr )
        break;
    }
    v14 = *p++;
    c = v14;
  }
  --p;
  if ( (flags & 8) != 0 )
  {
    if ( (flags & 4) != 0
      || (flags & 1) == 0
      && ((flags & 2) != 0 && number > 0x8000000000000000uLL
       || (flags & 2) == 0 && (number & 0x8000000000000000uLL) != 0LL) )
    {
      *_errno() = 34;
      if ( (flags & 1) != 0 )
      {
        number = -1;
      }
      else if ( (flags & 2) != 0 )
      {
        number = 0x8000000000000000uLL;
      }
      else
      {
        number = 0x7FFFFFFFFFFFFFFFLL;
      }
    }
  }
  else
  {
    if ( endptr != nullptr )
      p = nptr;
    number = 0;
  }
  if ( endptr != nullptr )
    *endptr = p;
  if ( (flags & 2) != 0 )
    number = -(__int64)number;
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return number;
}

//------------------------------------------------------------------------------
// Address: 0x102F3D90
// Name: __strtoi64
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned __int64 __cdecl _strtoi64(const char *nptr, char **endptr, int ibase)
{
  if ( __locale_changed != 0 )
    return strtoxq(plocinfo: nullptr, nptr, (const char **)endptr, ibase, flags: 0);
  else
    return strtoxq(plocinfo: &__initiallocalestructinfo, nptr, (const char **)endptr, ibase, flags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x102F3DBB
// Name: __wtol
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _wtol(const wchar_t *nptr)
{
  return wcstol(nptr, endptr: nullptr, ibase: 10);
}

//------------------------------------------------------------------------------
// Address: 0x102F3DD1
// Name: __wtoi
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _wtoi(const wchar_t *nptr)
{
  return _wtol(nptr);
}

//------------------------------------------------------------------------------
// Address: 0x102F3DDC
// Name: vscan_fn
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall vscan_fn@<eax>(
        wchar_t *string@<esi>,
        int (__cdecl *inputfn)(_iobuf *, const wchar_t *, localeinfo_struct *, char *),
        const wchar_t *format,
        localeinfo_struct *plocinfo,
        char *arglist)
{
  unsigned int v6; // eax
  _iobuf str; // [esp+4h] [ebp-20h] BYREF

  memset(&str, 0, sizeof(str));
  if ( string != nullptr && format != nullptr )
  {
    v6 = wcslen(wcs: string);
    str._flag = 73;
    str._base = (char *)string;
    str._ptr = (char *)string;
    if ( v6 <= 0x3FFFFFFF )
      str._cnt = 2 * v6;
    else
      str._cnt = 0x7FFFFFFF;
    return inputfn(a1: &str, a2: format, a3: plocinfo, a4: arglist);
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102F3E50
// Name: _swscanf
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int swscanf(wchar_t *string, const wchar_t *format, ...)
{
  va_list arglist; // [esp+14h] [ebp+10h] BYREF

  va_start(arglist, format);
  return vscan_fn(string, inputfn: _winput_l, format, plocinfo: nullptr, arglist);
}

//------------------------------------------------------------------------------
// Address: 0x102F3E72
// Name: __wtof_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
long double __cdecl _wtof_l(wchar_t *nptr, localeinfo_struct *plocinfo)
{
  unsigned __int16 *v2; // esi
  long double result; // st7
  _LocaleUpdate _loc_update; // [esp+4h] [ebp-2Ch] BYREF
  _flt fltstruct; // [esp+14h] [ebp-1Ch] BYREF

  v2 = nptr;
  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  if ( nptr != nullptr )
  {
    while ( iswctype(c: *v2, mask: 8u) != 0 )
      ++v2;
    result = _wfltin2(flt: &fltstruct, str: v2, _Locale: &_loc_update.localeinfo)->dval;
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return 0.0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102F3EFA
// Name: __wtof
// Source: linker_block_proximity
//------------------------------------------------------------------------------
long double __cdecl _wtof(wchar_t *nptr)
{
  return _wtof_l(nptr, plocinfo: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x102F3F0D
// Name: _wcsncat
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned __int16 *__cdecl wcsncat(unsigned __int16 *front, const wchar_t *back, unsigned int count)
{
  unsigned __int16 *v3; // edx
  unsigned __int16 *result; // eax
  __int16 v5; // cx
  unsigned __int16 *v6; // edx
  __int16 v8; // cx

  v3 = front;
  result = front;
  do
    v5 = *v3++;
  while ( v5 != 0 );
  v6 = v3 - 1;
  if ( count != 0 )
  {
    while ( 1 )
    {
      v8 = *back;
      --count;
      *v6++ = *back++;
      if ( v8 == 0 )
        break;
      if ( count == 0 )
        goto LABEL_6;
    }
  }
  else
  {
LABEL_6:
    *v6 = 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102F3F60
// Name: _strpbrk
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl strpbrk(unsigned __int8 *string, unsigned __int8 *control)
{
  unsigned int v2; // eax
  signed __int32 v5[8]; // [esp-20h] [ebp-24h] BYREF

  v2 = 0;
  memset(v5, 0, sizeof(v5));
  while ( 1 )
  {
    LOBYTE(v2) = *control;
    if ( *control == 0 )
      break;
    ++control;
    _bittestandset(v5, v2);
  }
  do
  {
    LOBYTE(v2) = *string;
    if ( *string == 0 )
      break;
    ++string;
  }
  while ( !_bittest(v5, v2) );
}

//------------------------------------------------------------------------------
// Address: 0x102F3FA0
// Name: __strnicmp_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _strnicmp_l(char *dst, char *src, unsigned int count, localeinfo_struct *plocinfo)
{
  char *v4; // esi
  unsigned int v5; // edi
  unsigned int v6; // eax
  _LocaleUpdate _loc_update; // [esp+Ch] [ebp-10h] BYREF

  if ( count != 0 )
  {
    _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
    if ( dst != nullptr && (v4 = src, src != nullptr) )
    {
      if ( count <= 0x7FFFFFFF )
      {
        if ( _loc_update.localeinfo.locinfo->lc_handle[2] != 0 )
        {
          do
          {
            v5 = _tolower_l(c: (unsigned __int8)v4[dst - src], plocinfo: &_loc_update.localeinfo);
            v6 = _tolower_l(c: (unsigned __int8)*v4++, plocinfo: &_loc_update.localeinfo);
            --count;
          }
          while ( count != 0 && v5 != 0 && v5 == v6 );
        }
        else
        {
          __ascii_strnicmp(first: (unsigned __int8 *)dst, last: (unsigned __int8 *)src, count);
        }
        if ( _loc_update.updated )
          _loc_update.ptd->_ownlocale &= ~2u;
      }
      else
      {
        *_errno() = 22;
        _invalid_parameter_noinfo();
        if ( _loc_update.updated )
          _loc_update.ptd->_ownlocale &= ~2u;
      }
    }
    else
    {
      *_errno() = 22;
      _invalid_parameter_noinfo();
      if ( _loc_update.updated )
        _loc_update.ptd->_ownlocale &= ~2u;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102F4082
// Name: __strnicmp
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _strnicmp(char *dst, char *src, unsigned int count)
{
  if ( __locale_changed != 0 )
  {
    _strnicmp_l(dst, src, count, plocinfo: nullptr);
  }
  else if ( dst != nullptr && src != nullptr && count <= 0x7FFFFFFF )
  {
    __ascii_strnicmp(first: (unsigned __int8 *)dst, last: (unsigned __int8 *)src, count);
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
  }
}

//------------------------------------------------------------------------------
// Address: 0x102F40D5
// Name: __towlower_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _towlower_l(unsigned __int16 c, localeinfo_struct *plocinfo)
{
  int result; // eax
  threadlocaleinfostruct *locinfo; // esi
  unsigned int v4; // ecx
  bool v5; // zf
  _LocaleUpdate _loc_update; // [esp+0h] [ebp-14h] BYREF
  unsigned __int16 widechar; // [esp+10h] [ebp-4h] BYREF

  result = 0xFFFF;
  if ( c != 0xFFFF )
  {
    _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
    locinfo = _loc_update.localeinfo.locinfo;
    v4 = _loc_update.localeinfo.locinfo->lc_handle[2];
    if ( v4 != 0 )
    {
      if ( c >= 0x100u )
      {
        v5 = __crtLCMapStringW(
               Locale: v4,
               dwMapFlags: 0x100u,
               lpSrcStr: &c,
               cchSrc: 1,
               lpDestStr: &widechar,
               cchDest: 1) == 0;
        result = c;
        if ( !v5 )
          result = widechar;
      }
      else
      {
        v5 = iswctype(c, mask: 1u) == 0;
        result = c;
        if ( !v5 )
          result = locinfo->pclmap[c];
      }
    }
    else
    {
      LOWORD(result) = c;
      if ( (unsigned __int16)(c - 65) <= 0x19u )
        LOWORD(result) = c + 32;
      result = (unsigned __int16)result;
    }
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102F4175
// Name: _towlower
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl towlower(unsigned __int16 c)
{
  return _towlower_l(c, plocinfo: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x102F4188
// Name: _copytlocinfo_nolock
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall copytlocinfo_nolock(threadlocaleinfostruct *ptlocid@<eax>, threadlocaleinfostruct *ptlocis@<ecx>)
{
  if ( ptlocis != nullptr && ptlocid != nullptr && ptlocid != ptlocis )
  {
    *ptlocid = *ptlocis;
    ptlocid->refcount = 0;
    __addlocaleref(ptloci: ptlocid);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102F41AE
// Name: ___init_collate
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl __init_collate()
{
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x102F41B1
// Name: __strcats
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void _strcats(char *outstr, unsigned int sizeInBytes, int n, ...)
{
  int v3; // edi
  const char **p_n; // esi

  v3 = 0;
  if ( n > 0 )
  {
    p_n = (const char **)&n;
    do
    {
      if ( strcat_s(_Dst: outstr, _SizeInBytes: sizeInBytes, _Src: *++p_n) != 0 )
        _invoke_watson(pszExpression: nullptr, pszFunction: nullptr, pszFile: nullptr, nLine: 0, pReserved: 0);
      ++v3;
    }
    while ( v3 < n );
  }
}

//------------------------------------------------------------------------------
// Address: 0x102F41F2
// Name: ___lc_strtolc
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl __lc_strtolc(tagLC_STRINGS *names, char *locale)
{
  const char *v2; // esi
  unsigned int v4; // eax
  bool j; // zf
  const char *v6; // edi
  char v7; // bl
  int v8; // eax
  char *szCountry; // eax
  unsigned int v10; // [esp-Ch] [ebp-18h]
  const char *v12; // [esp-8h] [ebp-14h]
  unsigned int v13; // [esp-4h] [ebp-10h]
  int i; // [esp+18h] [ebp+Ch]

  memset(dst: (int)names, value: nullptr, count: sizeof(tagLC_STRINGS));
  v2 = locale;
  if ( *locale == 0 )
    return 0;
  if ( *locale == 46 && locale[1] != 0 )
  {
    if ( strncpy_s(_Dst: names->szCodePage, _SizeInBytes: 0x10u, _Src: locale + 1, _Count: 0xFu) != 0 )
      _invoke_watson(pszExpression: nullptr, pszFunction: nullptr, pszFile: nullptr, nLine: 0, pReserved: 0);
    names->szCodePage[15] = 0;
    return 0;
  }
  i = 0;
  strcspn(string: (unsigned __int8 *)locale, control: "_.,");
  for ( j = v4 == 0; !j; j = v4 == 0 )
  {
    v6 = &v2[v4];
    v7 = v2[v4];
    if ( i != 0 )
    {
      if ( i == 1 )
      {
        if ( v4 >= 0x40 || v7 == 95 )
          return -1;
        v13 = v4;
        v12 = v2;
        v10 = 64;
        szCountry = names->szCountry;
      }
      else
      {
        if ( i != 2 || v4 >= 0x10 || v7 != 0 && v7 != 44 )
          return -1;
        v13 = v4;
        v12 = v2;
        v10 = 16;
        szCountry = names->szCodePage;
      }
      v8 = strncpy_s(_Dst: szCountry, _SizeInBytes: v10, _Src: v12, _Count: v13);
    }
    else
    {
      if ( v4 >= 0x40 || v7 == 46 )
        return -1;
      v8 = strncpy_s(_Dst: names->szLanguage, _SizeInBytes: 0x40u, _Src: v2, _Count: v4);
    }
    if ( v8 != 0 )
      _invoke_watson(pszExpression: nullptr, pszFunction: nullptr, pszFile: nullptr, nLine: 0, pReserved: 0);
    if ( v7 == 44 || v7 == 0 )
      return 0;
    ++i;
    v2 = v6 + 1;
    strcspn(string: (unsigned __int8 *)v6 + 1, control: "_.,");
  }
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x102F4311
// Name: ___lc_lctostr
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl __lc_lctostr(char *locale, unsigned int sizeInBytes, const tagLC_STRINGS *names)
{
  if ( strcpy_s(_Dst: locale, _SizeInBytes: sizeInBytes, _Src: names->szLanguage) != 0 )
    _invoke_watson(pszExpression: nullptr, pszFunction: nullptr, pszFile: nullptr, nLine: 0, pReserved: 0);
  if ( names->szCountry[0] != 0 )
    _strcats(outstr: locale, sizeInBytes, n: 2, "_", names->szCountry);
  if ( names->szCodePage[0] != 0 )
    _strcats(outstr: locale, sizeInBytes, n: 2, ".", names->szCodePage);
}

//------------------------------------------------------------------------------
// Address: 0x102F437C
// Name: _setlocale_get_all
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char *__usercall setlocale_get_all@<eax>(threadlocaleinfostruct *ploci@<esi>)
{
  char *result; // eax
  char *v2; // edi
  unsigned __int8 **v3; // eax
  int v4; // eax
  unsigned __int8 *locale; // [esp-8h] [ebp-1Ch]
  int *refcount; // [esp+4h] [ebp-10h]
  int same; // [esp+8h] [ebp-Ch]
  threadlocaleinfostruct::<unnamed_type_lc_category> *v8; // [esp+Ch] [ebp-8h]
  const $FAA2ED44176E8AD2BA02CFC02FF7315D *v9; // [esp+10h] [ebp-4h]

  same = 1;
  result = (char *)MemAlloc_Alloc(nSize: 0x355u);
  refcount = (int *)result;
  if ( result != nullptr )
  {
    v2 = result + 4;
    result[4] = 0;
    *(_DWORD *)result = 1;
    _strcats(outstr: result + 4, sizeInBytes: 0x351u, n: 3, "LC_COLLATE", "=", ploci->lc_category[1].locale);
    v9 = &__lc_category[1];
    v8 = &ploci->lc_category[1];
    do
    {
      if ( strcat_s(_Dst: v2, _SizeInBytes: 0x351u, _Src: ";") != 0 )
        _invoke_watson(pszExpression: nullptr, pszFunction: nullptr, pszFile: nullptr, nLine: 0, pReserved: 0);
      v3 = (unsigned __int8 **)v8;
      locale = (unsigned __int8 *)v8[1].locale;
      ++v8;
      strcmp(str1: *v3, str2: locale);
      if ( v4 != 0 )
        same = 0;
      ++v9;
      _strcats(outstr: v2, sizeInBytes: 0x351u, n: 3, v9->catname, "=", v8->locale);
    }
    while ( (int)v9 < (int)&__lc_category[5] );
    if ( same != 0 )
    {
      free(pMem: refcount);
      if ( ploci->lc_category[0].refcount != nullptr
        && InterlockedDecrement(lpAddend: ploci->lc_category[0].refcount) == 0 )
      {
        free(pMem: ploci->lc_category[0].refcount);
      }
      if ( ploci->lc_category[0].wrefcount != nullptr
        && InterlockedDecrement(lpAddend: ploci->lc_category[0].wrefcount) == 0 )
      {
        free(pMem: ploci->lc_category[0].wrefcount);
      }
      result = ploci->lc_category[2].locale;
      ploci->lc_category[0].wrefcount = nullptr;
      ploci->lc_category[0].wlocale = nullptr;
      ploci->lc_category[0].refcount = nullptr;
      ploci->lc_category[0].locale = nullptr;
    }
    else
    {
      if ( ploci->lc_category[0].refcount != nullptr
        && InterlockedDecrement(lpAddend: ploci->lc_category[0].refcount) == 0 )
      {
        free(pMem: ploci->lc_category[0].refcount);
      }
      if ( ploci->lc_category[0].wrefcount != nullptr
        && InterlockedDecrement(lpAddend: ploci->lc_category[0].wrefcount) == 0 )
      {
        free(pMem: ploci->lc_category[0].wrefcount);
      }
      ploci->lc_category[0].wrefcount = nullptr;
      ploci->lc_category[0].wlocale = nullptr;
      ploci->lc_category[0].refcount = refcount;
      ploci->lc_category[0].locale = v2;
      return v2;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102F44E1
// Name: __expandlocale
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char *__cdecl _expandlocale(char *expr, char *output, unsigned int sizeInChars, tagLC_ID *id, unsigned int *cp)
{
  const char *v5; // esi
  _tiddata *v6; // eax
  tagLC_ID *p_cacheid; // ebx
  unsigned int v9; // eax
  int v10; // eax
  int v11; // eax
  unsigned int v12; // eax
  unsigned int charactersInExpression; // [esp+10h] [ebp-B0h]
  unsigned int *pcachecp; // [esp+14h] [ebp-ACh]
  char *cachein; // [esp+18h] [ebp-A8h]
  char *cacheout; // [esp+28h] [ebp-98h]
  tagLC_STRINGS names; // [esp+2Ch] [ebp-94h] BYREF

  v5 = expr;
  v6 = _getptd();
  pcachecp = &v6->_setloc_data._cachecp;
  p_cacheid = &v6->_setloc_data._cacheid;
  cachein = v6->_setloc_data._cachein;
  cacheout = v6->_setloc_data._cacheout;
  if ( expr == nullptr || output == nullptr || sizeInChars == 0 )
    return nullptr;
  if ( *expr == 67 && expr[1] == 0 )
  {
    if ( strcpy_s(_Dst: output, _SizeInBytes: sizeInChars, _Src: "C") == 0 )
    {
      if ( id != nullptr )
      {
        id->wLanguage = 0;
        id->wCountry = 0;
        id->wCodePage = 0;
      }
      if ( cp != nullptr )
        *cp = 0;
      return output;
    }
LABEL_12:
    _invoke_watson(pszExpression: nullptr, pszFunction: nullptr, pszFile: nullptr, nLine: 0, pReserved: 0);
  }
  strlen(buf: (unsigned __int8 *)expr);
  charactersInExpression = v9;
  if ( v9 >= 0x83
    || (strcmp(str1: (unsigned __int8 *)cacheout, str2: (unsigned __int8 *)expr), v10 != 0)
    && (strcmp(str1: (unsigned __int8 *)cachein, str2: (unsigned __int8 *)expr), v11 != 0) )
  {
    if ( __lc_strtolc(&names, locale: expr) == 0
      && __get_qualified_locale(lpInStr: &names, lpOutId: p_cacheid, lpOutStr: &names) != 0 )
    {
      *pcachecp = p_cacheid->wCodePage;
      __lc_lctostr(locale: cacheout, sizeInBytes: 0x83u, &names);
      if ( *expr == 0 || (v12 = charactersInExpression, charactersInExpression >= 0x83) )
      {
        v12 = 0;
        v5 = defaultValue;
      }
      if ( strncpy_s(_Dst: cachein, _SizeInBytes: 0x83u, _Src: v5, _Count: v12 + 1) != 0 )
        goto LABEL_12;
      goto LABEL_22;
    }
    return nullptr;
  }
LABEL_22:
  if ( id != nullptr )
    *id = *p_cacheid;
  if ( cp != nullptr )
    *cp = *pcachecp;
  if ( strcpy_s(_Dst: output, _SizeInBytes: sizeInChars, _Src: cacheout) != 0 )
    _invoke_watson(pszExpression: nullptr, pszFunction: nullptr, pszFile: nullptr, nLine: 0, pReserved: 0);
  return cacheout;
}

//------------------------------------------------------------------------------
// Address: 0x102F4702
// Name: _setlocale_set_cat
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char *__usercall setlocale_set_cat@<eax>(threadlocaleinfostruct *ploci@<esi>, int category@<ecx>, char *locale)
{
  _tiddata *v4; // edi
  char *v6; // ebx
  int v7; // eax
  int v8; // eax
  unsigned int *v9; // ecx
  unsigned int id; // ecx
  _is_ctype_compatible *Lcid_c; // eax
  unsigned int v12; // edx
  int is_clike; // edx
  _is_ctype_compatible *v14; // eax
  unsigned int j; // eax
  int v16; // edi
  char *v17; // eax
  int v18; // ecx
  char *v19; // [esp-4h] [ebp-1D4h]
  unsigned int buf2; // [esp+10h] [ebp-1C0h]
  unsigned int oldhandle; // [esp+18h] [ebp-1B8h]
  unsigned int oldcodepage; // [esp+1Ch] [ebp-1B4h]
  tagLC_ID idtemp; // [esp+20h] [ebp-1B0h] BYREF
  unsigned int *v24; // [esp+28h] [ebp-1A8h]
  unsigned int cptemp; // [esp+2Ch] [ebp-1A4h] BYREF
  _is_ctype_compatible buf1; // [esp+30h] [ebp-1A0h]
  char *oldlocale; // [esp+38h] [ebp-198h]
  char *pch; // [esp+3Ch] [ebp-194h]
  int v29; // [esp+40h] [ebp-190h]
  int i; // [esp+44h] [ebp-18Ch]
  unsigned __int16 out[128]; // [esp+48h] [ebp-188h] BYREF
  char lctemp[132]; // [esp+148h] [ebp-88h] BYREF

  v29 = category;
  oldlocale = locale;
  v4 = _getptd();
  if ( _expandlocale(expr: locale, output: lctemp, sizeInChars: 0x83u, id: &idtemp, cp: &cptemp) == nullptr )
    return nullptr;
  v6 = (char *)ploci + 16 * category;
  strcmp(str1: (unsigned __int8 *)lctemp, str2: *((unsigned __int8 **)v6 + 18));
  if ( v7 != 0 )
  {
    strlen(buf: (unsigned __int8 *)lctemp);
    i = v8 + 5;
    pch = (char *)MemAlloc_Alloc(nSize: v8 + 5);
    if ( pch != nullptr )
    {
      oldlocale = *((char **)v6 + 18);
      v24 = &ploci->lc_handle[v29];
      oldhandle = *v24;
      buf1.is_clike = (int)&ploci->lc_id[v29];
      oldcodepage = ploci->lc_codepage;
      if ( strcpy_s(_Dst: pch + 4, _SizeInBytes: i - 4, _Src: lctemp) != 0 )
        _invoke_watson(pszExpression: nullptr, pszFunction: nullptr, pszFile: nullptr, nLine: 0, pReserved: 0);
      v9 = v24;
      *((_DWORD *)v6 + 18) = pch + 4;
      *v9 = idtemp.wLanguage;
      *(tagLC_ID *)buf1.is_clike = idtemp;
      if ( v29 == 2 )
      {
        i = 0;
        ploci->lc_codepage = cptemp;
        id = v4->_setloc_data._Lcid_c[4].id;
        buf1.is_clike = v4->_setloc_data._Lcid_c[4].is_clike;
        Lcid_c = v4->_setloc_data._Lcid_c;
        while ( ploci->lc_codepage != Lcid_c->id )
        {
          v12 = Lcid_c->id;
          ++i;
          Lcid_c->id = id;
          buf2 = v12;
          is_clike = Lcid_c->is_clike;
          Lcid_c->is_clike = buf1.is_clike;
          id = buf2;
          ++Lcid_c;
          buf1.is_clike = is_clike;
          if ( i >= 5 )
            goto LABEL_14;
        }
        if ( i != 0 )
        {
          v14 = &v4->_setloc_data._Lcid_c[i];
          v4->_setloc_data._Lcid_c[0].id = v14->id;
          v4->_setloc_data._Lcid_c[0].is_clike = v14->is_clike;
          v14->id = id;
          v14->is_clike = buf1.is_clike;
        }
LABEL_14:
        if ( i == 5 )
        {
          if ( __crtGetStringTypeA(
                 plocinfo: nullptr,
                 dwInfoType: 1u,
                 lpSrcStr: first_127char,
                 cchSrc: 127,
                 lpCharType: out,
                 code_page: ploci->lc_codepage,
                 lcid: ploci->lc_handle[2],
                 bError: 1) != 0 )
          {
            for ( j = 0; j < 0x7F; ++j )
              out[j] &= 0x1FFu;
            v4->_setloc_data._Lcid_c[0].is_clike = memcmp(lhs: out, rhs: ctype_loc_style, siz: 0xFEu) == 0;
          }
          else
          {
            v4->_setloc_data._Lcid_c[0].is_clike = 0;
          }
          v4->_setloc_data._Lcid_c[0].id = ploci->lc_codepage;
        }
        ploci->lc_clike = v4->_setloc_data._Lcid_c[0].is_clike;
      }
      if ( v29 == 1 )
        ploci->lc_collate_cp = cptemp;
      if ( ((int (__cdecl *)())__lc_category[v29].init)() == 0 )
      {
        if ( oldlocale != __clocalestr )
        {
          v16 = 2 * (v29 + 5);
          if ( InterlockedDecrement(lpAddend: ploci->lc_category[v29].refcount) == 0 )
          {
            free(pMem: *((void **)&ploci->refcount + 2 * v16));
            free(pMem: *((void **)v6 + 21));
            *((_DWORD *)v6 + 19) = 0;
          }
        }
        v17 = pch;
        v18 = 2 * (v29 + 5);
        *(_DWORD *)pch = 1;
        *(&ploci->refcount + 2 * v18) = (int)v17;
        return *((char **)v6 + 18);
      }
      v19 = pch;
      *((_DWORD *)v6 + 18) = oldlocale;
      free(pMem: v19);
      *v24 = oldhandle;
      ploci->lc_codepage = oldcodepage;
    }
    return nullptr;
  }
  return *((char **)v6 + 18);
}

//------------------------------------------------------------------------------
// Address: 0x102F4A3C
// Name: _setlocale_nolock
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char *__fastcall setlocale_nolock(int _category, threadlocaleinfostruct *ploci, char *_locale)
{
  int v3; // ebx
  threadlocaleinfostruct *v4; // esi
  char *result; // eax
  unsigned __int8 *v6; // edi
  _BYTE *v7; // eax
  _BYTE *v8; // ebx
  unsigned int v9; // eax
  const $FAA2ED44176E8AD2BA02CFC02FF7315D *v10; // esi
  int v11; // eax
  unsigned __int8 *v12; // ebx
  unsigned int v13; // eax
  unsigned int v14; // edi
  unsigned __int8 *v15; // edi
  unsigned __int8 **lc_category; // edi
  int v17; // eax
  int i; // [esp+10h] [ebp-94h]
  unsigned int len; // [esp+14h] [ebp-90h]
  unsigned int lena; // [esp+14h] [ebp-90h]
  int fLocaleSet; // [esp+18h] [ebp-8Ch]
  char lctemp[132]; // [esp+1Ch] [ebp-88h] BYREF

  v3 = 0;
  v4 = ploci;
  if ( _category != 0 )
  {
    if ( _locale != nullptr )
      return setlocale_set_cat(ploci, category: _category, locale: _locale);
    else
      return ploci->lc_category[_category].locale;
  }
  len = 1;
  fLocaleSet = 0;
  if ( _locale == nullptr )
    return setlocale_get_all(ploci: v4);
  if ( *_locale == 76 && _locale[1] == 67 && _locale[2] == 95 )
  {
    v6 = (unsigned __int8 *)_locale;
    do
    {
      strpbrk(string: v6, control: "=;");
      v8 = v7;
      if ( v7 == nullptr )
        return nullptr;
      v9 = v7 - v6;
      lena = v9;
      if ( v9 == 0 || *v8 == 59 )
        return nullptr;
      i = 1;
      v10 = &__lc_category[1];
      while ( 1 )
      {
        if ( strncmp(first: v10->catname, last: (const char *)v6, count: v9) == 0 )
        {
          strlen(buf: (unsigned __int8 *)v10->catname);
          if ( lena == v11 )
            break;
        }
        ++i;
        if ( (int)++v10 > (int)&__lc_category[5] )
          break;
        v9 = lena;
      }
      v12 = v8 + 1;
      strcspn(string: v12, control: ";");
      v14 = v13;
      if ( v13 == 0 && *v12 != 59 )
        return nullptr;
      if ( i <= 5 )
      {
        if ( strncpy_s(_Dst: lctemp, _SizeInBytes: 0x83u, _Src: (const char *)v12, _Count: v13) != 0 )
          _invoke_watson(pszExpression: nullptr, pszFunction: nullptr, pszFile: nullptr, nLine: 0, pReserved: 0);
        lctemp[v14] = 0;
        if ( setlocale_set_cat(ploci, category: i, locale: lctemp) != nullptr )
          ++fLocaleSet;
      }
      v15 = &v12[v14];
      if ( *v15 == 0 )
        break;
      v6 = v15 + 1;
    }
    while ( *v6 != 0 );
    result = nullptr;
    if ( fLocaleSet == 0 )
      return result;
    v4 = ploci;
    return setlocale_get_all(ploci: v4);
  }
  result = _expandlocale(expr: _locale, output: lctemp, sizeInChars: 0x83u, id: nullptr, cp: nullptr);
  if ( result != nullptr )
  {
    lc_category = (unsigned __int8 **)v4->lc_category;
    do
    {
      if ( v3 != 0 )
      {
        strcmp(str1: (unsigned __int8 *)lctemp, str2: *lc_category);
        if ( v17 == 0 || setlocale_set_cat(ploci: v4, category: v3, locale: lctemp) != nullptr )
          ++fLocaleSet;
        else
          len = 0;
      }
      ++v3;
      lc_category += 4;
    }
    while ( v3 <= 5 );
    result = nullptr;
    if ( len != 0 || fLocaleSet != 0 )
      return setlocale_get_all(ploci: v4);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102F4C58
// Name: _setlocale
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char *__cdecl setlocale(unsigned int _category, char *_locale)
{
  _tiddata *v3; // esi
  unsigned __int8 *v4; // ebx
  int v5; // eax
  char *retval; // [esp+14h] [ebp-20h]

  retval = nullptr;
  if ( _category <= 5 )
  {
    v3 = _getptd();
    __updatetlocinfo();
    v3->_ownlocale |= 0x10u;
    v4 = calloc(count: 0xD8u, size: 1u);
    if ( v4 != nullptr )
    {
      _lock(locknum: 12);
      copytlocinfo_nolock(ptlocid: (threadlocaleinfostruct *)v4, ptlocis: v3->ptlocinfo);
      _unlock(locknum: 12);
      retval = setlocale_nolock(_category, ploci: (threadlocaleinfostruct *)v4, _locale);
      if ( retval != nullptr )
      {
        if ( _locale != nullptr )
        {
          strcmp(str1: (unsigned __int8 *)_locale, str2: (unsigned __int8 *)__clocalestr);
          if ( v5 != 0 )
            __locale_changed = 1;
        }
        _lock(locknum: 12);
        _updatetlocinfoEx_nolock(pptlocid: &v3->ptlocinfo, ptlocis: (threadlocaleinfostruct *)v4);
        __removelocaleref(ptloci: (threadlocaleinfostruct *)v4);
        if ( (v3->_ownlocale & 2) == 0 && (__globallocalestatus & 1) == 0 )
        {
          _updatetlocinfoEx_nolock(pptlocid: &__ptlocinfo, ptlocis: v3->ptlocinfo);
          __lconv = __ptlocinfo->lconv;
          _pctype = __ptlocinfo->pctype;
          __mb_cur_max = __ptlocinfo->mb_cur_max;
        }
        _unlock(locknum: 12);
      }
      else
      {
        __removelocaleref(ptloci: (threadlocaleinfostruct *)v4);
        __freetlocinfo(ptloci: (threadlocaleinfostruct *)v4);
      }
    }
    v3->_ownlocale &= ~0x10u;
    return retval;
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102F4DCC
// Name: _wcschr
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned __int16 *__cdecl wcschr(const wchar_t *string, wchar_t ch)
{
  unsigned __int16 *result; // eax

  for ( result = (unsigned __int16 *)string; *result != 0; ++result )
  {
    if ( *result == ch )
      return result;
  }
  if ( *result != ch )
    return nullptr;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102F4DF3
// Name: __towupper_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _towupper_l(unsigned __int16 c, localeinfo_struct *plocinfo)
{
  int result; // eax
  threadlocaleinfostruct *locinfo; // esi
  unsigned int v4; // eax
  bool v5; // zf
  _LocaleUpdate _loc_update; // [esp+0h] [ebp-14h] BYREF
  unsigned __int16 widechar; // [esp+10h] [ebp-4h] BYREF

  result = 0xFFFF;
  if ( c != 0xFFFF )
  {
    _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
    locinfo = _loc_update.localeinfo.locinfo;
    v4 = _loc_update.localeinfo.locinfo->lc_handle[2];
    if ( v4 != 0 )
    {
      if ( c >= 0x100u )
      {
        v5 = __crtLCMapStringW(
               Locale: v4,
               dwMapFlags: 0x200u,
               lpSrcStr: &c,
               cchSrc: 1,
               lpDestStr: &widechar,
               cchDest: 1) == 0;
        result = c;
        if ( !v5 )
          result = widechar;
      }
      else
      {
        v5 = iswctype(c, mask: 2u) == 0;
        result = c;
        if ( !v5 )
          result = locinfo->pcumap[c];
      }
    }
    else
    {
      LOWORD(result) = c;
      if ( (unsigned __int16)(c - 97) <= 0x19u )
        LOWORD(result) = c - 32;
      result = (unsigned __int16)result;
    }
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102F4E99
// Name: _towupper
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl towupper(unsigned __int16 c)
{
  return _towupper_l(c, plocinfo: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x102F4EAC
// Name: __forcdecpt_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _forcdecpt_l(char *buffer, localeinfo_struct *_Locale)
{
  char *v2; // esi
  bool i; // zf
  char v4; // al
  char *v5; // esi
  char v6; // cl
  char v7; // cl
  _LocaleUpdate _loc_update; // [esp+4h] [ebp-10h] BYREF

  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo: _Locale);
  v2 = buffer;
  for ( i = tolower(c: *buffer) == 101; !i; i = isdigit(c: (unsigned __int8)*v2) == 0 )
    ++v2;
  if ( tolower(c: *v2) == 120 )
    v2 += 2;
  v4 = *v2;
  *v2 = *_loc_update.localeinfo.locinfo->lconv->decimal_point;
  v5 = v2 + 1;
  do
  {
    v6 = *v5;
    *v5 = v4;
    v4 = v6;
    v7 = *v5++;
  }
  while ( v7 != 0 );
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
}

//------------------------------------------------------------------------------
// Address: 0x102F4F20
// Name: __cropzeros_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _cropzeros_l(char *buf, localeinfo_struct *_Locale)
{
  char *v2; // eax
  char i; // cl
  char v4; // cl
  char *v5; // eax
  char v6; // cl
  char *v7; // edx
  char v8; // cl
  _LocaleUpdate _loc_update; // [esp+4h] [ebp-10h] BYREF

  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo: _Locale);
  v2 = buf;
  for ( i = *buf; *v2 != 0; i = *++v2 )
  {
    if ( i == *_loc_update.localeinfo.locinfo->lconv->decimal_point )
      break;
  }
  v4 = *v2;
  v5 = v2 + 1;
  if ( v4 != 0 )
  {
    while ( 1 )
    {
      v6 = *v5;
      if ( *v5 == 0 || v6 == 101 || v6 == 69 )
        break;
      ++v5;
    }
    v7 = v5;
    do
      --v5;
    while ( *v5 == 48 );
    if ( *v5 == *_loc_update.localeinfo.locinfo->lconv->decimal_point )
      --v5;
    do
    {
      v8 = *v7;
      ++v5;
      ++v7;
      *v5 = v8;
    }
    while ( v8 != 0 );
  }
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
}

//------------------------------------------------------------------------------
// Address: 0x102F4FA2
// Name: __positive
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __cdecl _positive(long double *arg)
{
  return *arg >= 0.0;
}

//------------------------------------------------------------------------------
// Address: 0x102F4FBE
// Name: __fassign_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _fassign_l(_CRT_FLOAT flag, char *argument, char *number, localeinfo_struct *plocinfo)
{
  _CRT_DOUBLE doubletemp; // [esp+0h] [ebp-8h] BYREF

  if ( LODWORD(flag.f) != 0 )
  {
    _atodbl_l(d: &doubletemp, str: number, plocinfo);
    *(_CRT_DOUBLE *)argument = doubletemp;
  }
  else
  {
    _atoflt_l(d: &flag, str: number, plocinfo);
    *(_CRT_FLOAT *)argument = flag;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102F5000
// Name: __fassign
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _fassign(int flag, char *argument, char *number)
{
  _fassign_l((_CRT_FLOAT)flag, argument, number, plocinfo: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x102F501A
// Name: _shift
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall shift(char *s@<eax>, int dist@<edi>)
{
  int v3; // eax

  if ( dist != 0 )
  {
    strlen(buf: (unsigned __int8 *)s);
    memmove(dst: (unsigned __int8 *)&s[dist], src: (unsigned __int8 *)s, count: v3 + 1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102F5039
// Name: __forcdecpt
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _forcdecpt(char *buffer)
{
  _forcdecpt_l(buffer, _Locale: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x102F504C
// Name: __cropzeros
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _cropzeros(char *buf)
{
  _cropzeros_l(buf, _Locale: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x102F505F
// Name: _cftoe2_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall cftoe2_l@<eax>(
        char *buf@<eax>,
        unsigned int sizeInBytes,
        int ndec,
        int caps,
        _strflt *pflt,
        char g_fmt,
        localeinfo_struct *plocinfo)
{
  int *v8; // eax
  int v10; // eax
  char *v11; // esi
  threadlocaleinfostruct *locinfo; // eax
  char *v13; // esi
  unsigned int v14; // ebx
  int v15; // eax
  int v16; // [esp-4h] [ebp-1Ch]
  _LocaleUpdate _loc_update; // [esp+8h] [ebp-10h] BYREF

  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  if ( buf == nullptr || sizeInBytes == 0 )
  {
    v8 = _errno();
    v16 = 22;
LABEL_3:
    *v8 = v16;
    _invalid_parameter_noinfo();
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return v16;
  }
  if ( ndec <= 0 )
    v10 = 0;
  else
    v10 = ndec;
  if ( sizeInBytes <= v10 + 9 )
  {
    v8 = _errno();
    v16 = 34;
    goto LABEL_3;
  }
  if ( g_fmt != 0 )
    shift(s: &buf[pflt->sign == 45], dist: ndec > 0);
  v11 = buf;
  if ( pflt->sign == 45 )
  {
    *buf = 45;
    v11 = buf + 1;
  }
  if ( ndec > 0 )
  {
    locinfo = _loc_update.localeinfo.locinfo;
    *v11 = v11[1];
    *++v11 = *locinfo->lconv->decimal_point;
  }
  v13 = &v11[ndec + (g_fmt == 0)];
  if ( sizeInBytes == -1 )
    v14 = -1;
  else
    v14 = sizeInBytes + buf - v13;
  if ( strcpy_s(_Dst: v13, _SizeInBytes: v14, _Src: "e+000") != 0 )
    _invoke_watson(pszExpression: nullptr, pszFunction: nullptr, pszFile: nullptr, nLine: 0, pReserved: 0);
  if ( caps != 0 )
    *v13 = 69;
  if ( *pflt->mantissa != 48 )
  {
    v15 = pflt->decpt - 1;
    if ( v15 < 0 )
    {
      v15 = 1 - pflt->decpt;
      v13[1] = 45;
    }
    if ( v15 >= 100 )
    {
      v13[2] += v15 / 100;
      v15 %= 100;
    }
    if ( v15 >= 10 )
    {
      v13[3] += v15 / 10;
      LOBYTE(v15) = v15 % 10;
    }
    v13[4] += v15;
  }
  if ( (_outputformat & 1) != 0 && v13[2] == 48 )
    memmove(dst: (unsigned __int8 *)v13 + 2, src: (unsigned __int8 *)v13 + 3, count: 3u);
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x102F51C0
// Name: __cftoe_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _cftoe_l(
        _CRT_DOUBLE *pvalue,
        char *buf,
        unsigned int sizeInBytes,
        int ndec,
        int caps,
        localeinfo_struct *plocinfo)
{
  int result; // eax
  unsigned int v7; // eax
  _strflt retstrflt; // [esp+Ch] [ebp-2Ch] BYREF
  char resstr[24]; // [esp+1Ch] [ebp-1Ch] BYREF

  _fltout2(x: *(_CRT_DOUBLE *)&pvalue->x, flt: &retstrflt, resultstr: resstr, resultsize: 0x16u);
  if ( buf != nullptr && (v7 = sizeInBytes, sizeInBytes != 0) )
  {
    if ( sizeInBytes != -1 )
      v7 = sizeInBytes - (retstrflt.sign == 45) - (ndec > 0);
    result = _fptostr(
               buf: &buf[(retstrflt.sign == 45) + (ndec > 0)],
               sizeInBytes: v7,
               digits: ndec + 1,
               pflt: &retstrflt);
    if ( result != 0 )
      *buf = 0;
    else
      return cftoe2_l(buf, sizeInBytes, ndec, caps, pflt: &retstrflt, g_fmt: 0, plocinfo);
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return 22;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102F5287
// Name: __cftoe
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _cftoe(_CRT_DOUBLE *pvalue, char *buf, unsigned int sizeInBytes, int ndec, int caps)
{
  return _cftoe_l(pvalue, buf, sizeInBytes, ndec, caps, plocinfo: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x102F52A7
// Name: __cftoa_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _cftoa_l(
        _CRT_DOUBLE *pvalue,
        char *buf,
        unsigned int sizeInBytes,
        int ndec,
        int caps,
        localeinfo_struct *plocinfo)
{
  char *v6; // esi
  int *v7; // eax
  int result; // eax
  unsigned int v9; // eax
  bool v10; // zf
  _BYTE *v11; // eax
  char *v12; // esi
  char *v13; // eax
  char *v14; // esi
  int x_low; // eax
  unsigned int v16; // eax
  unsigned int v17; // ecx
  char *i; // eax
  __int64 v19; // rax
  __int64 v20; // rcx
  _BYTE *v21; // esi
  _BYTE *v22; // edi
  __int64 v23; // rax
  __int64 v24; // rcx
  __int64 v25; // rax
  __int64 v26; // rcx
  __int64 v27; // rcx
  __int64 v28; // [esp-Ch] [ebp-38h]
  int v29; // [esp-4h] [ebp-30h]
  _LocaleUpdate _loc_update; // [esp+8h] [ebp-24h] BYREF
  __int64 exponent; // [esp+18h] [ebp-14h]
  unsigned __int64 mask; // [esp+20h] [ebp-Ch]
  int maskpos; // [esp+28h] [ebp-4h]
  char *pos; // [esp+38h] [ebp+Ch]

  LODWORD(exponent) = 1023;
  maskpos = 48;
  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  if ( ndec < 0 )
    ndec = 0;
  v6 = buf;
  if ( buf == nullptr || sizeInBytes == 0 )
  {
    v7 = _errno();
    v29 = 22;
LABEL_5:
    *v7 = v29;
    _invalid_parameter_noinfo();
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return v29;
  }
  *buf = 0;
  if ( sizeInBytes <= ndec + 11 )
  {
    v7 = _errno();
    v29 = 34;
    goto LABEL_5;
  }
  LODWORD(mask) = LODWORD(pvalue->x);
  if ( ((HIDWORD(pvalue->x) >> 20) & 0x7FF) == 0x7FF )
  {
    v9 = sizeInBytes;
    if ( sizeInBytes != -1 )
      v9 = sizeInBytes - 2;
    result = _cftoe(pvalue, buf: buf + 2, sizeInBytes: v9, ndec, caps: 0);
    if ( result != 0 )
    {
      v10 = !_loc_update.updated;
      *buf = 0;
      if ( !v10 )
        _loc_update.ptd->_ownlocale &= ~2u;
      return result;
    }
    if ( buf[2] == 45 )
    {
      *buf = 45;
      v6 = buf + 1;
    }
    *v6 = 48;
    v6[1] = caps == 0 ? 120 : 88;
    strrchr(string: (unsigned __int8 *)v6 + 2, chr: 0x65u);
    if ( v11 != nullptr )
    {
      *v11 = caps == 0 ? 112 : 80;
      v11[3] = 0;
    }
  }
  else
  {
    if ( (HIDWORD(pvalue->x) & 0x80000000) != 0 )
    {
      *buf = 45;
      v6 = buf + 1;
    }
    *v6 = 48;
    v6[1] = caps == 0 ? 120 : 88;
    if ( (HIDWORD(pvalue->x) & 0x7FF00000) != 0 )
    {
      v6[2] = 49;
      v12 = v6 + 3;
    }
    else
    {
      v6[2] = 48;
      v12 = v6 + 3;
      if ( (HIDWORD(pvalue->x) & 0xFFFFF | LODWORD(pvalue->x)) != 0 )
        LODWORD(exponent) = 1022;
      else
        LODWORD(exponent) = 0;
    }
    v13 = v12;
    v14 = v12 + 1;
    pos = v13;
    if ( ndec != 0 )
      *v13 = *_loc_update.localeinfo.locinfo->lconv->decimal_point;
    else
      *v13 = 0;
    x_low = LODWORD(pvalue->x);
    HIDWORD(mask) = HIDWORD(pvalue->x) & 0xFFFFF;
    if ( HIDWORD(mask) != 0 || x_low != 0 )
    {
      mask = 0xF000000000000LL;
      do
      {
        if ( ndec <= 0 )
          break;
        v16 = (unsigned __int16)(((mask & *(_QWORD *)&pvalue->x & 0xFFFFFFFFFFFFFLL) >> maskpos) + 48);
        if ( v16 > 0x39 )
          LOBYTE(v16) = (caps != 0 ? 7 : 39) + ((mask & *(_QWORD *)&pvalue->x & 0xFFFFFFFFFFFFFLL) >> maskpos) + 48;
        v17 = HIDWORD(mask);
        maskpos -= 4;
        *v14++ = v16;
        --ndec;
        mask = __PAIR64__(v17, mask) >> 4;
      }
      while ( (maskpos & 0x8000u) == 0 );
      if ( (maskpos & 0x8000u) == 0
        && (unsigned __int16)((mask & *(_QWORD *)&pvalue->x & 0xFFFFFFFFFFFFFLL) >> maskpos) > 8u )
      {
        for ( i = v14 - 1; *i == 102 || *i == 70; --i )
          *i = 48;
        if ( i == pos )
        {
          ++*(i - 1);
        }
        else if ( *i == 57 )
        {
          *i = caps != 0 ? 65 : 97;
        }
        else
        {
          ++*i;
        }
      }
    }
    if ( ndec > 0 )
    {
      memset(dst: (int)v14, value: (unsigned __int8 *)0x30, count: ndec);
      v14 += ndec;
    }
    if ( *pos == 0 )
      v14 = pos;
    *v14 = caps == 0 ? 112 : 80;
    HIDWORD(v20) = 0;
    v19 = ((*(_QWORD *)&pvalue->x >> 52) & 0x7FFLL) - (unsigned int)exponent;
    if ( v19 < 0 )
    {
      v14[1] = 45;
      v21 = v14 + 2;
      v19 = -v19;
    }
    else
    {
      v14[1] = 43;
      v21 = v14 + 2;
    }
    v22 = v21;
    *v21 = 48;
    if ( v19 >= 0 )
    {
      LODWORD(v20) = 1000;
      if ( v19 >= 1000 )
      {
        v28 = v20;
        v24 = v19 % v20;
        v23 = v19 / v28;
        *v21++ = v23 + 48;
        HIDWORD(exponent) = HIDWORD(v23);
        v19 = v24;
        if ( v21 != v22 )
          goto LABEL_60;
      }
    }
    if ( v19 >= 100 )
    {
LABEL_60:
      v26 = v19 % 100;
      v25 = v19 / 100;
      *v21 = v25 + 48;
      HIDWORD(exponent) = HIDWORD(v25);
      ++v21;
      v19 = v26;
    }
    if ( v21 != v22 || v19 >= 10 )
    {
      v27 = v19 % 10;
      *v21++ = v19 / 10 + 48;
      LOBYTE(v19) = v19 % 10;
      HIDWORD(exponent) = HIDWORD(v27);
    }
    *v21 = v19 + 48;
    v21[1] = 0;
  }
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x102F561D
// Name: _cftof2_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall cftof2_l@<eax>(
        char *buf@<ecx>,
        _strflt *pflt@<eax>,
        unsigned int sizeInBytes,
        int ndec,
        char g_fmt,
        localeinfo_struct *plocinfo)
{
  int v8; // esi
  char *v10; // esi
  int decpt; // eax
  int v12; // eax
  unsigned __int8 *v13; // esi
  int v14; // eax
  int v15; // edi
  int v16; // edi
  _LocaleUpdate _loc_update; // [esp+Ch] [ebp-10h] BYREF

  v8 = pflt->decpt - 1;
  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  if ( buf != nullptr && sizeInBytes != 0 )
  {
    if ( g_fmt != 0 && v8 == ndec )
      *(_WORD *)&buf[v8 + (pflt->sign == 45)] = 48;
    v10 = buf;
    if ( pflt->sign == 45 )
    {
      *buf = 45;
      v10 = buf + 1;
    }
    decpt = pflt->decpt;
    if ( decpt > 0 )
    {
      v13 = (unsigned __int8 *)&v10[decpt];
    }
    else
    {
      strlen(buf: (unsigned __int8 *)v10);
      memmove(dst: (unsigned __int8 *)v10 + 1, src: (unsigned __int8 *)v10, count: v12 + 1);
      *v10 = 48;
      v13 = (unsigned __int8 *)(v10 + 1);
    }
    if ( ndec > 0 )
    {
      strlen(buf: v13);
      memmove(dst: v13 + 1, src: v13, count: v14 + 1);
      *v13 = *_loc_update.localeinfo.locinfo->lconv->decimal_point;
      v15 = pflt->decpt;
      if ( v15 < 0 )
      {
        v16 = -v15;
        if ( g_fmt != 0 || ndec >= v16 )
          ndec = v16;
        shift(s: (char *)v13 + 1, dist: ndec);
        memset(dst: (int)(v13 + 1), value: (unsigned __int8 *)0x30, count: ndec);
      }
    }
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return 0;
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return 22;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102F5720
// Name: __cftof_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _cftof_l(_CRT_DOUBLE *pvalue, char *buf, unsigned int sizeInBytes, int ndec, localeinfo_struct *plocinfo)
{
  int result; // eax
  unsigned int v6; // eax
  _strflt retstrflt; // [esp+8h] [ebp-2Ch] BYREF
  char resstr[24]; // [esp+18h] [ebp-1Ch] BYREF

  _fltout2(x: *(_CRT_DOUBLE *)&pvalue->x, flt: &retstrflt, resultstr: resstr, resultsize: 0x16u);
  if ( buf != nullptr && sizeInBytes != 0 )
  {
    v6 = -1;
    if ( sizeInBytes != -1 )
      v6 = sizeInBytes - (retstrflt.sign == 45);
    result = _fptostr(
               buf: &buf[retstrflt.sign == 45],
               sizeInBytes: v6,
               digits: ndec + retstrflt.decpt,
               pflt: &retstrflt);
    if ( result != 0 )
      *buf = 0;
    else
      return cftof2_l(buf, pflt: &retstrflt, sizeInBytes, ndec, g_fmt: 0, plocinfo);
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return 22;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102F57E1
// Name: __cftog_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _cftog_l(
        _CRT_DOUBLE *pvalue,
        char *buf,
        unsigned int sizeInBytes,
        int ndec,
        int caps,
        localeinfo_struct *plocinfo)
{
  int result; // eax
  unsigned int v7; // ecx
  int v8; // ebx
  BOOL v9; // eax
  char *v10; // edi
  _strflt retstrflt; // [esp+8h] [ebp-2Ch] BYREF
  char resstr[24]; // [esp+18h] [ebp-1Ch] BYREF

  _fltout2(x: *(_CRT_DOUBLE *)&pvalue->x, flt: &retstrflt, resultstr: resstr, resultsize: 0x16u);
  if ( buf != nullptr && (v7 = sizeInBytes, sizeInBytes != 0) )
  {
    v8 = retstrflt.decpt - 1;
    v9 = retstrflt.sign == 45;
    v10 = &buf[v9];
    if ( sizeInBytes != -1 )
      v7 = sizeInBytes - v9;
    result = _fptostr(buf: v10, sizeInBytes: v7, digits: ndec, pflt: &retstrflt);
    if ( result != 0 )
    {
      *buf = 0;
    }
    else if ( retstrflt.decpt - 1 < -4 || retstrflt.decpt - 1 >= ndec )
    {
      return cftoe2_l(buf, sizeInBytes, ndec, caps, pflt: &retstrflt, g_fmt: 1, plocinfo);
    }
    else
    {
      if ( v8 < retstrflt.decpt - 1 )
        v10[strlen(v10) - 1] = 0;
      return cftof2_l(buf, pflt: &retstrflt, sizeInBytes, ndec, g_fmt: 1, plocinfo);
    }
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return 22;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102F599C
// Name: __setdefaultprecision
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int _setdefaultprecision()
{
  int result; // eax

  result = _controlfp_s(_CurrentState: nullptr, newctrl: 0x10000u, mask: 0x30000u);
  if ( result != 0 )
    _invoke_watson(pszExpression: nullptr, pszFunction: nullptr, pszFile: nullptr, nLine: 0, pReserved: 0);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102F5A40
// Name: _strcmp
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl strcmp(unsigned __int8 *str1, unsigned __int8 *str2)
{
  unsigned __int8 *v2; // edx
  unsigned __int8 *v3; // ecx
  unsigned int v4; // eax
  unsigned int v5; // eax
  __int16 v6; // ax

  v2 = str1;
  v3 = str2;
  if ( ((unsigned __int8)str1 & 3) != 0 )
  {
    if ( ((unsigned __int8)str1 & 1) == 0 )
      goto doword;
    v2 = str1 + 1;
    if ( *str1 != *str2 )
      return;
    v3 = str2 + 1;
    if ( *str1 == 0 )
      return;
    if ( ((unsigned __int8)v2 & 2) != 0 )
    {
doword:
      v6 = *(_WORD *)v2;
      v2 += 2;
      if ( (_BYTE)v6 != *v3 || (_BYTE)v6 == 0 || HIBYTE(v6) != v3[1] || HIBYTE(v6) == 0 )
        return;
      v3 += 2;
    }
  }
  do
  {
    v4 = *(_DWORD *)v2;
    if ( (unsigned __int8)*(_DWORD *)v2 != *v3 )
      break;
    if ( (_BYTE)v4 == 0 )
      break;
    if ( BYTE1(v4) != v3[1] )
      break;
    if ( BYTE1(v4) == 0 )
      break;
    v5 = HIWORD(v4);
    if ( (_BYTE)v5 != v3[2] )
      break;
    if ( (_BYTE)v5 == 0 )
      break;
    if ( BYTE1(v5) != v3[3] )
      break;
    v3 += 4;
    v2 += 4;
  }
  while ( BYTE1(v5) != 0 );
}

//------------------------------------------------------------------------------
// Address: 0x102F5AC8
// Name: _abort
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl __noreturn abort()
{
  if ( __get_sigabrt() != nullptr )
    raise(signum: 22);
  if ( (__abort_behavior & 2) != 0 )
    _call_reportfault(nDbgHookCode: 3, dwExceptionCode: 0x40000015u, dwExceptionFlags: 1u);
  _exit(code: 3);
}

//------------------------------------------------------------------------------
// Address: 0x102F5AFB
// Name: __set_abort_behavior
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl _set_abort_behavior(unsigned int flags, unsigned int mask)
{
  unsigned int result; // eax

  result = __abort_behavior;
  __abort_behavior = mask & flags | __abort_behavior & ~mask;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102F5B1C
// Name: __GET_RTERRMSG
// Source: linker_block_proximity
//------------------------------------------------------------------------------
const wchar_t *__cdecl _GET_RTERRMSG(int rterrnum)
{
  int v1; // eax

  v1 = 0;
  while ( rterrnum != rterrs[v1].rterrno )
  {
    if ( (unsigned int)++v1 >= 0x16 )
      return nullptr;
  }
  return rterrs[v1].rterrtxt;
}

//------------------------------------------------------------------------------
// Address: 0x102F5B42
// Name: __NMSG_WRITE
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _NMSG_WRITE(int rterrnum)
{
  const wchar_t *v1; // edi
  unsigned int v2; // eax
  HANDLE StdHandle; // eax
  void *v4; // esi
  unsigned int i; // eax
  DWORD v6; // eax
  unsigned int bytes_written; // [esp+Ch] [ebp-1FCh] BYREF
  char buffer[500]; // [esp+10h] [ebp-1F8h] BYREF

  v1 = _GET_RTERRMSG(rterrnum);
  bytes_written = (unsigned int)v1;
  if ( v1 != nullptr )
  {
    if ( _set_error_mode(em: 3) == 1 || _set_error_mode(em: 3) == 0 && __app_type == 1 )
    {
      StdHandle = GetStdHandle(nStdHandle: 0xFFFFFFF4);
      v4 = StdHandle;
      if ( StdHandle != nullptr && StdHandle != (HANDLE)-1 )
      {
        for ( i = 0; i < 0x1F4; ++i )
        {
          buffer[i] = v1[i];
          if ( v1[i] == 0 )
            break;
        }
        buffer[499] = 0;
        strlen(buf: (unsigned __int8 *)buffer);
        WriteFile(
          hFile: v4,
          lpBuffer: buffer,
          nNumberOfBytesToWrite: v6,
          lpNumberOfBytesWritten: &bytes_written,
          lpOverlapped: nullptr);
      }
    }
    else if ( rterrnum != 252 )
    {
      if ( wcscpy_s(_Dst: outmsg, _SizeInWords: 0x314u, _Src: aRuntimeErrorPr) != 0 )
        _invoke_watson(pszExpression: nullptr, pszFunction: nullptr, pszFile: nullptr, nLine: 0, pReserved: 0);
      outmsg[285] = 0;
      if ( GetModuleFileNameW(hModule: nullptr, lpFilename: &outmsg[25], nSize: 0x104u) == 0
        && wcscpy_s(_Dst: &outmsg[25], _SizeInWords: 0x2FBu, _Src: L"<program name unknown>") != 0
        || wcslen(wcs: &outmsg[25]) + 1 > 0x3C
        && (v2 = wcslen(wcs: &outmsg[25]),
            wcsncpy_s(
              _Dst: &_umaskval + v2,
              _SizeInWords: 763 - (&_umaskval + v2 - &outmsg[25]),
              _Src: L"...",
              _Count: 3u) != 0)
        || wcscat_s(_Dst: outmsg, _SizeInWords: 0x314u, _Src: L"\n\n") != 0
        || wcscat_s(_Dst: outmsg, _SizeInWords: 0x314u, _Src: (const wchar_t *)bytes_written) != 0 )
      {
        _invoke_watson(pszExpression: nullptr, pszFunction: nullptr, pszFile: nullptr, nLine: 0, pReserved: 0);
      }
      __crtMessageBoxW(lpText: outmsg, lpCaption: L"Microsoft Visual C++ Runtime Library", uType: 0x12010u);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102F5CF1
// Name: __FF_MSGBANNER
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void _FF_MSGBANNER()
{
  if ( _set_error_mode(em: 3) == 1 || _set_error_mode(em: 3) == 0 && __app_type == 1 )
  {
    _NMSG_WRITE(rterrnum: 252);
    _NMSG_WRITE(rterrnum: 255);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102F5D2A
// Name: ___getlocaleinfo
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl __getlocaleinfo(
        localeinfo_struct *plocinfo,
        int lc_type,
        unsigned int localehandle,
        unsigned int fieldtype,
        void **address)
{
  unsigned __int8 *v5; // ebx
  unsigned int LocaleInfoA; // esi
  unsigned int v7; // eax
  unsigned __int8 *v8; // eax
  unsigned __int8 *v9; // eax
  unsigned int LocaleInfoW; // eax
  int v12; // ebx
  unsigned __int8 *v13; // eax
  int buffersize; // [esp+Ch] [ebp-90h]
  int bufferused; // [esp+10h] [ebp-8Ch]
  unsigned int dw; // [esp+14h] [ebp-88h] BYREF
  unsigned __int8 cbuffer[128]; // [esp+18h] [ebp-84h] BYREF

  dw = (unsigned int)plocinfo;
  switch ( lc_type )
  {
    case 1:
      bufferused = 0;
      v5 = cbuffer;
      LocaleInfoA = __crtGetLocaleInfoA(
                      plocinfo,
                      Locale: localehandle,
                      LCType: fieldtype,
                      lpLCData: (char *)cbuffer,
                      cchData: 128);
      if ( LocaleInfoA == 0 )
      {
        if ( GetLastError() != 122 )
          return -1;
        v7 = __crtGetLocaleInfoA(
               plocinfo: (localeinfo_struct *)dw,
               Locale: localehandle,
               LCType: fieldtype,
               lpLCData: nullptr,
               cchData: 0);
        buffersize = v7;
        if ( v7 == 0 )
          return -1;
        v8 = calloc(count: v7, size: 1u);
        v5 = v8;
        if ( v8 == nullptr )
          return -1;
        bufferused = 1;
        LocaleInfoA = __crtGetLocaleInfoA(
                        plocinfo: (localeinfo_struct *)dw,
                        Locale: localehandle,
                        LCType: fieldtype,
                        lpLCData: (char *)v8,
                        cchData: buffersize);
        if ( LocaleInfoA == 0 )
          goto LABEL_9;
      }
      v9 = calloc(count: LocaleInfoA, size: 1u);
      *address = v9;
      if ( v9 == nullptr )
      {
        if ( bufferused == 0 )
          return -1;
LABEL_9:
        free(pMem: v5);
        return -1;
      }
      if ( strncpy_s(_Dst: (char *)v9, _SizeInBytes: LocaleInfoA, _Src: (const char *)v5, _Count: LocaleInfoA - 1) != 0 )
        _invoke_watson(pszExpression: nullptr, pszFunction: nullptr, pszFile: nullptr, nLine: 0, pReserved: 0);
      if ( bufferused != 0 )
        free(pMem: v5);
      break;
    case 2:
      *address = nullptr;
      LocaleInfoW = GetLocaleInfoW(Locale: localehandle, LCType: fieldtype, lpLCData: nullptr, cchData: 0);
      v12 = LocaleInfoW;
      if ( LocaleInfoW == 0
        || (v13 = calloc(count: LocaleInfoW, size: 2u), *address = v13, v13 == nullptr)
        || GetLocaleInfoW(Locale: localehandle, LCType: fieldtype, lpLCData: (LPWSTR)v13, cchData: v12) == 0 )
      {
        free(pMem: *address);
        *address = nullptr;
        return -1;
      }
      break;
    case 0:
      dw = 0;
      if ( GetLocaleInfoW(Locale: localehandle, LCType: fieldtype | 0x20000000, lpLCData: (LPWSTR)&dw, cchData: 2) == 0 )
        return -1;
      *(_BYTE *)address = dw;
      break;
    default:
      return -1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x102F5ED6
// Name: __initp_misc_purevirt
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _initp_misc_purevirt(void *enull)
{
  __pPurecall = enull;
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x1018AC20
// Name: HostnameChanged
// Source: json
//------------------------------------------------------------------------------
void __cdecl HostnameChanged(IConVar *pConVar)
{
  CSteam3Server *v1; // eax
  IGameEvent *v2; // esi
  ConVarRef var; // [esp+0h] [ebp-8h] BYREF

  v1 = Steam3Server();
  CSteam3Server::NotifyOfServerNameChange(this: v1);
  if ( sv.m_State >= ss_active
    && CGameEventManager::GetEventDescriptor(this: g_GameEventManager, name: "hostname_changed", pCookie: nullptr) != nullptr )
  {
    v2 = g_GameEventManager->CreateEventA(this: g_GameEventManager, a2: "hostname_changed", a3: 0, a4: 0);
    if ( v2 != nullptr )
    {
      ConVarRef::ConVarRef(this: &var, pConVar);
      v2->SetString(this: v2, a2: "hostname", a3: var.m_pConVarState->m_Value.m_pszString);
      g_GameEventManager->FireEvent(this: g_GameEventManager, a2: v2, a3: false);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1018ACB0
// Name: unsigned int GetSteamAppID(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __cdecl GetSteamAppID()
{
  CSteam3Client *v0; // eax
  CSteam3Server *v2; // eax

  if ( Steam3Client()->m_pSteamUtils != nullptr )
  {
    v0 = Steam3Client();
    return v0->m_pSteamUtils->GetAppID(this: v0->m_pSteamUtils);
  }
  else if ( Steam3Server()->m_pSteamGameServerUtils != nullptr )
  {
    v2 = Steam3Server();
    return v2->m_pSteamGameServerUtils->GetAppID(this: v2->m_pSteamGameServerUtils);
  }
  else
  {
    return 215;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1018ACF0
// Name: enum EUniverse GetSteamUniverse(void)
// Source: json
//------------------------------------------------------------------------------
EUniverse __cdecl GetSteamUniverse()
{
  CSteam3Client *v0; // eax
  CSteam3Server *v2; // eax

  if ( Steam3Client()->m_pSteamUtils != nullptr )
  {
    v0 = Steam3Client();
    return v0->m_pSteamUtils->GetConnectedUniverse(this: v0->m_pSteamUtils);
  }
  else if ( Steam3Server()->m_pSteamGameServerUtils != nullptr )
  {
    v2 = Steam3Server();
    return v2->m_pSteamGameServerUtils->GetConnectedUniverse(this: v2->m_pSteamGameServerUtils);
  }
  else
  {
    return k_EUniverseInvalid;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1018AD30
// Name: void SetLaunchOptions(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SetLaunchOptions(const CCommand *args)
{
  int v1; // esi
  KeyValues *v2; // eax
  int m_nArgc; // eax
  const char **m_ppArgv; // edi
  const char *v5; // eax
  const char *v6; // eax
  const char *v7; // [esp-8h] [ebp-10h]

  v1 = 0;
  if ( g_pLaunchOptions != nullptr )
    KeyValues::deleteThis(this: g_pLaunchOptions);
  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v2 != nullptr )
    g_pLaunchOptions = KeyValues::KeyValues(this: v2, setName: "LaunchOptions");
  else
    g_pLaunchOptions = nullptr;
  m_nArgc = args->m_nArgc;
  if ( args->m_nArgc > 0 )
  {
    m_ppArgv = args->m_ppArgv;
    do
    {
      if ( v1 < 0 || v1 >= m_nArgc )
        v5 = defaultValue;
      else
        v5 = *m_ppArgv;
      v7 = v5;
      v6 = va(format: "Arg%d", v1);
      KeyValues::SetString(this: g_pLaunchOptions, keyName: v6, value: v7);
      m_nArgc = args->m_nArgc;
      ++v1;
      ++m_ppArgv;
    }
    while ( v1 < args->m_nArgc );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1018ADC0
// Name: void Host_Quit_f(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Host_Quit_f()
{
  if ( EngineTool_CheckQuitHandlers() != 0 )
    HostState_Shutdown();
}

//------------------------------------------------------------------------------
// Address: 0x1018ADD0
// Name: _restart
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __cdecl restart()
{
  HostState_Restart();
}

//------------------------------------------------------------------------------
// Address: 0x1018AEA0
// Name: void Host_Status_PrintClient(class IClient __near *,bool,void (*)(char const __near *,...))
// Source: json
//------------------------------------------------------------------------------
void __cdecl Host_Status_PrintClient(IClient *client, bool bShowAddress, void (*print)(const char *, ...))
{
  INetChannel *v3; // edi
  const char *v4; // ebx
  int v5; // eax
  double v6; // st7
  double v7; // st7
  double v8; // st7
  char *v9; // eax
  int v10; // eax
  int v11; // eax
  int v12; // eax
  int v13; // eax
  void (*v14)(const char *, ...); // esi
  int v15; // eax
  int v16; // eax
  int v17; // eax
  int v18; // eax

  v3 = client->GetNetChannel(this: client);
  v4 = "challenging";
  if ( client->IsActive(this: client) )
  {
    v4 = "active";
  }
  else if ( client->IsSpawned(this: client) )
  {
    v4 = "spawning";
  }
  else if ( client->IsConnected(this: client) )
  {
    v4 = "connecting";
  }
  if ( v3 != nullptr )
  {
    v5 = v3->GetDataRate(this: v3);
    v6 = ((double (__thiscall *)(INetChannel *, int, const char *, int))v3->GetAvgLoss)(a1: v3, a2: 1, a3: v4, a4: v5)
       * 100.0;
    v7 = ((double (__thiscall *)(INetChannel *, _DWORD, int))v3->GetAvgLatency)(a1: v3, a2: 0, a3: (int)v6) * 1000.0;
    v8 = ((double (__thiscall *)(INetChannel *, int))v3->GetTimeConnected)(a1: v3, a2: (int)v7);
    v9 = COM_FormatSeconds(seconds: (int)v8);
    v10 = ((int (__thiscall *)(IClient *, char *))client->GetNetworkIDString)(a1: client, a2: v9);
    v11 = ((int (__thiscall *)(IClient *, int))client->GetClientName)(a1: client, a2: v10);
    v12 = ((int (__thiscall *)(IClient *, int))client->GetPlayerSlot)(a1: client, a2: v11);
    v13 = ((int (__thiscall *)(IClient *, int))client->GetUserID)(a1: client, a2: v12 + 1);
    v14 = print;
    print(a1: "# %2i %i \"%s\" %s %s %i %i %s %d", v13);
    if ( bShowAddress )
    {
      v15 = (int)v3->GetAddress(this: v3);
      print(a1: " %s", v15);
      print(a1: "\n");
      return;
    }
  }
  else
  {
    v16 = ((int (__thiscall *)(IClient *, const char *))client->GetNetworkIDString)(a1: client, a2: v4);
    v17 = ((int (__thiscall *)(IClient *, int))client->GetClientName)(a1: client, a2: v16);
    v18 = ((int (__thiscall *)(IClient *, int))client->GetUserID)(a1: client, a2: v17);
    v14 = print;
    print(a1: "#%2i \"%s\" %s %s", v18);
  }
  v14(a1: "\n");
}

//------------------------------------------------------------------------------
// Address: 0x1018AFF0
// Name: void Host_Client_Printf(char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
void Host_Client_Printf(const char *fmt, ...)
{
  char string[1024]; // [esp+0h] [ebp-400h] BYREF
  va_list params; // [esp+40Ch] [ebp+Ch] BYREF

  va_start(params, fmt);
  V_vsnprintf(pDest: string, maxLen: 1024, pFormat: fmt, params);
  host_client->ClientPrintf(this: &host_client->IClient, a2: "%s", string);
}

//------------------------------------------------------------------------------
// Address: 0x1018B040
// Name: bool CL_HL2Demo_MapCheck(char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl CL_HL2Demo_MapCheck(const char *name)
{
  if ( !CL_IsHL2Demo() || sv.m_bIsDedicated )
    return true;
  return _V_stricmp(s1: name, s2: "d1_trainstation_01") == 0
      || _V_stricmp(s1: name, s2: "d1_trainstation_02") == 0
      || _V_stricmp(s1: name, s2: "d1_town_01") == 0
      || _V_stricmp(s1: name, s2: "d1_town_01a") == 0
      || _V_stricmp(s1: name, s2: "d1_town_02") == 0
      || _V_stricmp(s1: name, s2: "d1_town_03") == 0
      || _V_stricmp(s1: name, s2: "background01") == 0
      || _V_stricmp(s1: name, s2: "background03") == 0;
}

//------------------------------------------------------------------------------
// Address: 0x1018B110
// Name: bool CL_PortalDemo_MapCheck(char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl CL_PortalDemo_MapCheck(const char *name)
{
  if ( !CL_IsPortalDemo() || sv.m_bIsDedicated )
    return true;
  return _V_stricmp(s1: name, s2: "testchmb_a_00") == 0
      || _V_stricmp(s1: name, s2: "testchmb_a_01") == 0
      || _V_stricmp(s1: name, s2: "testchmb_a_02") == 0
      || _V_stricmp(s1: name, s2: "testchmb_a_03") == 0
      || _V_stricmp(s1: name, s2: "testchmb_a_04") == 0
      || _V_stricmp(s1: name, s2: "testchmb_a_05") == 0
      || _V_stricmp(s1: name, s2: "testchmb_a_06") == 0
      || _V_stricmp(s1: name, s2: "background1") == 0;
}

//------------------------------------------------------------------------------
// Address: 0x1018B1E0
// Name: void Host_Changelevel_f(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Host_Changelevel_f(const CCommand *args)
{
  const char *v1; // eax
  const char *v2; // eax
  const char *v3; // eax
  const char *v4; // ecx

  if ( args->m_nArgc >= 2 )
  {
    if ( sv.m_State >= ss_active )
    {
      v1 = defaultValue;
      if ( args->m_nArgc > 1 )
        v1 = args->m_ppArgv[1];
      if ( g_pVEngineServer->IsMapValid(this: g_pVEngineServer, a2: v1) == 0 )
        goto LABEL_8;
      v2 = defaultValue;
      if ( args->m_nArgc > 1 )
        v2 = args->m_ppArgv[1];
      if ( !CL_HL2Demo_MapCheck(name: v2) )
        goto LABEL_8;
      v3 = defaultValue;
      if ( args->m_nArgc > 1 )
        v3 = args->m_ppArgv[1];
      if ( CL_PortalDemo_MapCheck(name: v3) )
      {
        SetLaunchOptions(args);
        v4 = defaultValue;
        if ( args->m_nArgc > 2 )
          v4 = args->m_ppArgv[2];
        if ( args->m_nArgc > 1 )
          HostState_ChangeLevelMP(pNewLevel: args->m_ppArgv[1], pLandmarkName: v4);
        else
          HostState_ChangeLevelMP(pNewLevel: defaultValue, pLandmarkName: v4);
      }
      else
      {
LABEL_8:
        if ( args->m_nArgc > 1 )
          _Warning(a1: "changelevel failed: %s not found\n", args->m_ppArgv[1]);
        else
          _Warning(a1: "changelevel failed: %s not found\n", defaultValue);
      }
    }
    else
    {
      ConMsg(a1: "Can't changelevel, not running server\n");
    }
  }
  else
  {
    ConMsg(a1: "changelevel <levelname> : continue game on a new level\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x1018B2F0
// Name: void Host_Changelevel2_f(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Host_Changelevel2_f(const CCommand *args)
{
  const char *v1; // eax
  const char *v2; // eax
  const char *v3; // eax
  const char *v4; // eax
  const char *v5; // eax
  const char *v6; // eax
  vgui::CTreeViewListControl *v7; // ecx
  const char *v8; // eax
  vgui::CTreeViewListControl *v9; // ecx
  const char *v10; // eax
  const char *v11; // ecx

  if ( args->m_nArgc >= 2 )
  {
    if ( sv.m_State >= ss_active )
    {
      v1 = defaultValue;
      if ( args->m_nArgc > 1 )
        v1 = args->m_ppArgv[1];
      if ( g_pVEngineServer->IsMapValid(this: g_pVEngineServer, a2: v1) != 0 )
        goto LABEL_23;
      if ( !CL_IsHL2Demo() )
        goto LABEL_16;
      if ( !CL_IsHL2Demo() )
        goto LABEL_23;
      v2 = defaultValue;
      if ( args->m_nArgc > 1 )
        v2 = args->m_ppArgv[1];
      if ( _V_stricmp(s1: v2, s2: "d1_trainstation_03") == 0 )
        goto LABEL_23;
      v3 = defaultValue;
      if ( args->m_nArgc > 1 )
        v3 = args->m_ppArgv[1];
      if ( _V_stricmp(s1: v3, s2: "d1_town_02a") != 0 )
      {
LABEL_16:
        if ( args->m_nArgc > 1 )
          _Warning(a1: "changelevel2 failed: %s not found\n", args->m_ppArgv[1]);
        else
          _Warning(a1: "changelevel2 failed: %s not found\n", defaultValue);
      }
      else
      {
LABEL_23:
        if ( !CL_IsHL2Demo() || sv.m_bIsDedicated )
          goto LABEL_32;
        v4 = defaultValue;
        if ( args->m_nArgc > 1 )
          v4 = args->m_ppArgv[1];
        if ( _V_stricmp(s1: v4, s2: "d1_trainstation_03") != 0 )
        {
LABEL_32:
          if ( !CL_IsHL2Demo() || sv.m_bIsDedicated )
            goto LABEL_38;
          v5 = defaultValue;
          if ( args->m_nArgc > 1 )
            v5 = args->m_ppArgv[1];
          if ( _V_stricmp(s1: v5, s2: "d1_town_02a") != 0 )
            goto LABEL_38;
          v6 = defaultValue;
          if ( args->m_nArgc > 2 )
            v6 = args->m_ppArgv[2];
          if ( _V_stricmp(s1: v6, s2: "d1_town_02_02a") != 0 )
          {
LABEL_38:
            if ( !CL_IsPortalDemo() || sv.m_bIsDedicated )
              goto LABEL_40;
            v8 = defaultValue;
            if ( args->m_nArgc > 1 )
              v8 = args->m_ppArgv[1];
            if ( _V_stricmp(s1: v8, s2: "testchmb_a_07") != 0 )
            {
LABEL_40:
              v10 = defaultValue;
              if ( args->m_nArgc > 1 )
                v10 = args->m_ppArgv[1];
              if ( CL_HL2Demo_MapCheck(name: v10) )
              {
                SetLaunchOptions(args);
                v11 = defaultValue;
                if ( args->m_nArgc > 2 )
                  v11 = args->m_ppArgv[2];
                if ( args->m_nArgc > 1 )
                  HostState_ChangeLevelSP(pNewLevel: args->m_ppArgv[1], pLandmarkName: v11);
                else
                  HostState_ChangeLevelSP(pNewLevel: defaultValue, pLandmarkName: v11);
              }
              else if ( args->m_nArgc > 1 )
              {
                _Warning(a1: "changelevel failed: %s not found\n", args->m_ppArgv[1]);
              }
              else
              {
                _Warning(a1: "changelevel failed: %s not found\n", defaultValue);
              }
            }
            else
            {
              CL_DemoTransitionFromTestChmb(this: v9);
            }
          }
          else
          {
            CL_DemoTransitionFromRavenholm(this: v7);
          }
        }
        else
        {
          CL_DemoTransitionFromTrainstation();
        }
      }
    }
    else
    {
      ConMsg(a1: "Can't changelevel2, not in a map\n");
    }
  }
  else
  {
    ConMsg(a1: "changelevel2 <levelname> : continue game on a new level in the unit\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x1018B550
// Name: void Host_Disconnect(bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Host_Disconnect(BOOL bShowMainMenu)
{
  IGameEvent *v1; // eax
  CClientState *LocalClient; // eax
  IEngineVGuiInternal *v3; // eax

  v1 = g_GameEventManager->CreateEventA(this: g_GameEventManager, a2: "cs_game_disconnected", a3: 0, a4: 0);
  if ( v1 != nullptr )
    g_GameEventManager->FireEventClientSide(this: g_GameEventManager, a2: v1);
  ++g_nHostDisconnectReentrancyCounter;
  if ( bShowMainMenu )
    g_bInCommentaryMode = false;
  if ( !sv.m_bIsDedicated )
  {
    LocalClient = GetLocalClient(nSlot: -1);
    LocalClient->Disconnect(this: LocalClient, a2: bShowMainMenu);
  }
  if ( g_ClientDLL != nullptr && bShowMainMenu )
    ((void (*)(void))g_ClientDLL->ShutdownMovies)();
  Host_AllowQueuedMaterialSystem(bAllow: false);
  HostState_GameShutdown();
  if ( !sv.m_bIsDedicated
    && bShowMainMenu
    && !engineClient->IsDrawingLoadingImage(this: engineClient)
    && GetBaseLocalClient()->demonum == -1 )
  {
    v3 = EngineVGui();
    v3->ActivateGameUI(this: v3);
  }
  --g_nHostDisconnectReentrancyCounter;
}

//------------------------------------------------------------------------------
// Address: 0x1018B620
// Name: disconnect
// Source: json
//------------------------------------------------------------------------------
void __cdecl disconnect(const CCommand *args)
{
  GetBaseLocalClient()->demonum = -1;
  if ( args->m_nArgc > 1 )
    COM_ExplainDisconnection(bPrint: false, fmt: args->m_ppArgv[1]);
  Host_Disconnect(bShowMainMenu: true);
}

//------------------------------------------------------------------------------
// Address: 0x1018B660
// Name: version
// Source: json
//------------------------------------------------------------------------------
void __cdecl version()
{
  int HostVersion; // eax
  CSteam3Client *v1; // eax
  int v2; // eax
  CSteam3Server *v3; // eax
  int v4; // eax
  int v5; // eax
  const char *VersionString; // [esp-8h] [ebp-Ch]
  const char *ProductString; // [esp-4h] [ebp-8h]
  int v8; // [esp-4h] [ebp-8h]
  int v9; // [esp-4h] [ebp-8h]

  ProductString = Sys_GetProductString();
  VersionString = Sys_GetVersionString();
  HostVersion = GetHostVersion();
  ConMsg(a1: "Protocol version %i\nExe version %s (%s)\n", HostVersion, VersionString, ProductString);
  if ( Steam3Client()->m_pSteamUtils != nullptr )
  {
    v1 = Steam3Client();
    v8 = v1->m_pSteamUtils->GetAppID(this: v1->m_pSteamUtils);
    v2 = build_number();
    ConMsg(a1: "Exe build: 03:30:09 Jul 15 2011 (%i) (%i)\n", v2, v8);
  }
  else if ( Steam3Server()->m_pSteamGameServerUtils != nullptr )
  {
    v3 = Steam3Server();
    v9 = v3->m_pSteamGameServerUtils->GetAppID(this: v3->m_pSteamGameServerUtils);
    v4 = build_number();
    ConMsg(a1: "Exe build: 03:30:09 Jul 15 2011 (%i) (%i)\n", v4, v9);
  }
  else
  {
    v5 = build_number();
    ConMsg(a1: "Exe build: 03:30:09 Jul 15 2011 (%i) (%i)\n", v5, 215);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1018B700
// Name: pause
// Source: json
//------------------------------------------------------------------------------
void __cdecl pause(const CCommand *args)
{
  const char *v1; // eax
  const char *v2; // eax
  const char *v3; // [esp-4h] [ebp-4h]

  if ( sv.m_bIsDedicated || GetBaseLocalClient()->m_szLevelName[0] != 0 )
  {
    if ( cmd_source == src_command )
    {
      Cmd_ForwardToServer(args);
    }
    else if ( CGameServer::IsPausable(this: &sv) )
    {
      CBaseServer::SetPaused(this: &sv, paused: sv.m_State != ss_paused);
      v1 = "paused";
      if ( sv.m_State != ss_paused )
        v1 = "unpaused";
      v2 = (const char *)((int (__thiscall *)(IClient *, const char *))host_client->GetClientName)(
                           a1: &host_client->IClient,
                           a2: v1);
      CBaseServer::BroadcastPrintf(this: &sv, fmt: "%s %s the game\n", v2, v3);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1018B7A0
// Name: setpause
// Source: json
//------------------------------------------------------------------------------
void __cdecl setpause(const CCommand *args)
{
  const char *v1; // eax

  if ( sv.m_bIsDedicated || GetBaseLocalClient()->m_szLevelName[0] != 0 )
  {
    if ( cmd_source == src_command )
    {
      Cmd_ForwardToServer(args);
    }
    else
    {
      CBaseServer::SetPaused(this: &sv, paused: true);
      if ( CCommand::FindArg(this: args, pName: "nomsg") == nullptr )
      {
        v1 = host_client->GetClientName(this: &host_client->IClient);
        CBaseServer::BroadcastPrintf(this: &sv, fmt: "%s paused the game\n", v1);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1018B820
// Name: unpause
// Source: json
//------------------------------------------------------------------------------
void __cdecl unpause(const CCommand *args)
{
  const char *v1; // eax

  if ( sv.m_bIsDedicated || GetBaseLocalClient()->m_szLevelName[0] != 0 )
  {
    if ( cmd_source == src_command )
    {
      Cmd_ForwardToServer(args);
    }
    else
    {
      CBaseServer::SetPaused(this: &sv, paused: false);
      if ( CCommand::FindArg(this: args, pName: "nomsg") == nullptr )
      {
        v1 = host_client->GetClientName(this: &host_client->IClient);
        CBaseServer::BroadcastPrintf(this: &sv, fmt: "%s unpaused the game\n", v1);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1018B8A0
// Name: memory
// Source: json
//------------------------------------------------------------------------------
void __cdecl memory()
{
  void (*v0)(const char *, ...); // ebx
  int v1; // eax
  int i; // esi
  const char *CounterName; // ebx
  float v4; // [esp+18h] [ebp-8h]
  float v5; // [esp+1Ch] [ebp-4h]

  v0 = ConMsg;
  ConMsg(a1: "Heap Used:\n");
  v1 = _g_pMemAlloc->GetSize(this: _g_pMemAlloc, a2: nullptr);
  if ( v1 == -1 )
    ConMsg(a1: "Corrupted!\n");
  else
    ConMsg(a1: "%5.2f MB (%d bytes)\n", (double)v1 * 0.00000095367432, v1);
  ConMsg(a1: "\nVideo Memory Used:\n");
  v5 = 0.0;
  for ( i = 0; i < CVProfile::GetNumCounters(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled); ++i )
  {
    if ( CVProfile::GetCounterGroup(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled, a2: i) == COUNTER_GROUP_TEXTURE_GLOBAL )
    {
      v4 = (float)(int)CVProfile::GetCounterValue(
                         this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
                         a2: i)
         * 0.00000095367432;
      v5 = v4 + v5;
      CounterName = CVProfile::GetCounterName(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled, a2: i);
      if ( V_strnicmp(s1: CounterName, s2: "TexGroup_Global_", n: 16) == 0 )
        CounterName += 16;
      ConMsg(a1: "%5.2f MB: %s\n", v4, CounterName);
      v0 = ConMsg;
    }
  }
  v0(a1: "------------------\n");
  v0(a1: "%5.2f MB: total\n", v5);
  v0(a1: "\nHunk Memory Used:\n");
  Hunk_Print();
}

//------------------------------------------------------------------------------
// Address: 0x1018B9E0
// Name: int Host_GetNumDemos(void)
// Source: json
//------------------------------------------------------------------------------
int __cdecl Host_GetNumDemos()
{
  int v0; // edi
  int i; // esi

  v0 = 0;
  for ( i = 0; i < 32; ++i )
  {
    if ( GetBaseLocalClient()->demos[i][0] == 0 )
      break;
    ++v0;
  }
  return v0;
}

//------------------------------------------------------------------------------
// Address: 0x1018BA10
// Name: void Host_PrintDemoList(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Host_PrintDemoList()
{
  int v0; // edi
  int i; // esi
  int demonum; // ebx
  int v3; // edi
  int v4; // esi
  bool v5; // zf
  const char *v6; // ebx
  CClientState *BaseLocalClient; // eax
  int v8; // [esp+Ch] [ebp-8h]
  int next; // [esp+10h] [ebp-4h]

  v0 = 0;
  for ( i = 0; i < 32; ++i )
  {
    if ( GetBaseLocalClient()->demos[i][0] == 0 )
      break;
    ++v0;
  }
  v8 = v0;
  demonum = GetBaseLocalClient()->demonum;
  next = demonum;
  if ( demonum >= v0 || demonum < 0 )
  {
    next = 0;
    demonum = 0;
  }
  v3 = 0;
  v4 = 0;
  while ( GetBaseLocalClient()->demos[v4][0] != 0 )
  {
    v5 = demonum == v3;
    v6 = "-->";
    if ( !v5 )
      v6 = "   ";
    BaseLocalClient = GetBaseLocalClient();
    DevMsg(a1: "%3s % 2i : %20s\n", v6, v3++, BaseLocalClient->demos[v4++]);
    if ( v4 >= 32 )
      break;
    demonum = next;
  }
  if ( v8 == 0 )
    DevMsg(a1: "No demos in list, use startdemos <demoname> <demoname2> to specify\n");
}

//------------------------------------------------------------------------------
// Address: 0x1018BAE0
// Name: startdemos
// Source: json
//------------------------------------------------------------------------------
void __cdecl startdemos(const CCommand *args)
{
  int v1; // edi
  int v2; // esi
  int v3; // edi
  const char **v4; // ebx
  const char *v5; // eax
  CClientState *BaseLocalClient; // eax
  const char *v7; // [esp-8h] [ebp-18h]
  int v8; // [esp+Ch] [ebp-4h]

  v1 = args->m_nArgc - 1;
  if ( v1 > 32 )
  {
    _Msg(a1: "Max %i demos in demoloop\n", 32);
    v1 = 32;
  }
  _Msg(a1: "%i demo(s) in loop\n", v1);
  v2 = 1;
  v8 = v1 + 1;
  if ( v1 + 1 > 1 )
  {
    v3 = 32;
    v4 = &args->m_ppArgv[1];
    do
    {
      if ( v2 < 0 || v2 >= args->m_nArgc )
        v5 = defaultValue;
      else
        v5 = *v4;
      v7 = v5;
      BaseLocalClient = GetBaseLocalClient();
      V_strncpy(pDest: (char *)&BaseLocalClient->events.m_Tail + v3, pSrc: v7, maxLen: 32);
      ++v2;
      ++v4;
      v3 += 32;
    }
    while ( v2 < v8 );
  }
  GetBaseLocalClient()->demonum = 0;
  Host_PrintDemoList();
  if ( sv.m_State >= ss_active || demoplayer->IsPlayingBack(this: demoplayer) )
    GetBaseLocalClient()->demonum = -1;
  else
    CL_NextDemo();
}

//------------------------------------------------------------------------------
// Address: 0x1018BBC0
// Name: stopdemo
// Source: json
//------------------------------------------------------------------------------
void __cdecl stopdemo()
{
  if ( demoplayer->IsPlayingBack(this: demoplayer) )
    Host_Disconnect(bShowMainMenu: true);
}

//------------------------------------------------------------------------------
// Address: 0x1018BBE0
// Name: demolist
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __cdecl demolist()
{
  Host_PrintDemoList();
}

//------------------------------------------------------------------------------
// Address: 0x1018BD00
// Name: incrementvar
// Source: json
//------------------------------------------------------------------------------
void __cdecl incrementvar(const CCommand *args)
{
  const char *v2; // ebx
  ConVar *v3; // eax
  ConVar *v4; // edi
  const char *v5; // eax
  const char *v6; // eax
  const char *v7; // esi
  long double v8; // st7
  float v9; // xmm0_4
  vgui::CTreeViewListControl *v10; // ecx
  ECommandTarget_t TraceType; // eax
  const char *v12; // eax
  const char *v13; // [esp+4h] [ebp-1Ch]
  double v14; // [esp+4h] [ebp-1Ch]
  float v15; // [esp+18h] [ebp-8h]
  float v16; // [esp+1Ch] [ebp-4h]
  float m_fValue; // [esp+28h] [ebp+8h]
  float v18; // [esp+28h] [ebp+8h]

  if ( args->m_nArgc != 5 )
  {
    _Warning(a1: "Usage: incrementvar varName minValue maxValue delta\n");
    return;
  }
  v2 = args->m_ppArgv[1];
  if ( v2 == nullptr )
  {
    _ConDMsg(a1: "Host_IncrementCVar_f without a varname\n");
    return;
  }
  v3 = g_pCVar->FindVar_2(this: g_pCVar, a2: v2);
  v4 = v3;
  if ( v3 == nullptr )
  {
    _ConDMsg(a1: "cvar \"%s\" not found\n", v2);
    return;
  }
  m_fValue = v3->m_pParent->m_Value.m_fValue;
  v5 = defaultValue;
  if ( args->m_nArgc > 2 )
    v5 = args->m_ppArgv[2];
  v16 = atof(nptr: v5);
  v6 = defaultValue;
  if ( args->m_nArgc > 3 )
    v6 = args->m_ppArgv[3];
  v15 = atof(nptr: v6);
  if ( args->m_nArgc > 4 )
    v7 = args->m_ppArgv[4];
  else
    v7 = defaultValue;
  v8 = atof(nptr: v7) + m_fValue;
  v9 = v16;
  v18 = v8;
  if ( v8 > v15 )
    goto LABEL_17;
  if ( v16 > v18 )
  {
    v9 = v15;
LABEL_17:
    v18 = v9;
  }
  v13 = va(format: "%s %f", v2, v18);
  TraceType = CTraceFilter::GetTraceType(this: v10);
  Cbuf_AddText(eTarget: TraceType, pText: v13, nTickDelay: 0);
  v12 = (const char *)((int (__thiscall *)(ConVar *, _DWORD, _DWORD))v4->GetName)(
                        a1: v4,
                        a2: COERCE_UNSIGNED_INT64(v18),
                        a3: HIDWORD(COERCE_UNSIGNED_INT64(v18)));
  _ConDMsg(a1: "%s = %f\n", v12, v14);
}

//------------------------------------------------------------------------------
// Address: 0x1018BE40
// Name: multvar
// Source: json
//------------------------------------------------------------------------------
void __cdecl multvar(const CCommand *args)
{
  const char *v2; // ebx
  ConVar *v3; // eax
  ConVar *v4; // edi
  const char *v5; // eax
  const char *v6; // eax
  const char *v7; // esi
  long double v8; // st7
  float v9; // xmm0_4
  vgui::CTreeViewListControl *v10; // ecx
  ECommandTarget_t TraceType; // eax
  const char *v12; // eax
  const char *v13; // [esp+4h] [ebp-1Ch]
  double v14; // [esp+4h] [ebp-1Ch]
  float v15; // [esp+18h] [ebp-8h]
  float v16; // [esp+1Ch] [ebp-4h]
  float m_fValue; // [esp+28h] [ebp+8h]
  float v18; // [esp+28h] [ebp+8h]

  if ( args->m_nArgc != 5 )
  {
    _Warning(a1: "Usage: multvar varName minValue maxValue factor\n");
    return;
  }
  v2 = args->m_ppArgv[1];
  if ( v2 == nullptr )
  {
    _ConDMsg(a1: "multvar without a varname\n");
    return;
  }
  v3 = g_pCVar->FindVar_2(this: g_pCVar, a2: v2);
  v4 = v3;
  if ( v3 == nullptr )
  {
    _ConDMsg(a1: "cvar \"%s\" not found\n", v2);
    return;
  }
  m_fValue = v3->m_pParent->m_Value.m_fValue;
  v5 = defaultValue;
  if ( args->m_nArgc > 2 )
    v5 = args->m_ppArgv[2];
  v15 = atof(nptr: v5);
  v6 = defaultValue;
  if ( args->m_nArgc > 3 )
    v6 = args->m_ppArgv[3];
  v16 = atof(nptr: v6);
  if ( args->m_nArgc > 4 )
    v7 = args->m_ppArgv[4];
  else
    v7 = defaultValue;
  v8 = atof(nptr: v7) * m_fValue;
  v18 = v8;
  if ( v8 > v16 )
  {
    v9 = v16;
LABEL_17:
    v18 = v9;
    goto LABEL_18;
  }
  v9 = v15;
  if ( v15 > v18 )
    goto LABEL_17;
LABEL_18:
  v13 = va(format: "%s %f", v2, v18);
  TraceType = CTraceFilter::GetTraceType(this: v10);
  Cbuf_AddText(eTarget: TraceType, pText: v13, nTickDelay: 0);
  v12 = (const char *)((int (__thiscall *)(ConVar *, _DWORD, _DWORD))v4->GetName)(
                        a1: v4,
                        a2: COERCE_UNSIGNED_INT64(v18),
                        a3: HIDWORD(COERCE_UNSIGNED_INT64(v18)));
  _ConDMsg(a1: "%s = %f\n", v12, v14);
}

//------------------------------------------------------------------------------
// Address: 0x1018BF90
// Name: dumpstringtables
// Source: json
//------------------------------------------------------------------------------
void __cdecl dumpstringtables()
{
  SV_PrintStringTables();
  CL_PrintStringTables();
}

//------------------------------------------------------------------------------
// Address: 0x1018BFA0
// Name: stringtabledictionary
// Source: json
//------------------------------------------------------------------------------
void __cdecl stringtabledictionary()
{
  if ( sv.m_State >= ss_active )
    SV_CreateDictionary(pchMapName: sv.m_szMapname);
  else
    _Warning(a1: "stringtabledictionary: only valid when running a map\n");
}

//------------------------------------------------------------------------------
// Address: 0x1018BFD0
// Name: crash
// Source: json
//------------------------------------------------------------------------------
void __cdecl crash()
{
  _Msg(a1: "forcing crash\n");
  MEMORY[0] = 0;
}

//------------------------------------------------------------------------------
// Address: 0x1018BFF0
// Name: flush
// Source: json
//------------------------------------------------------------------------------
void __cdecl flush()
{
  g_ClientDLL->InvalidateMdlCache(this: g_ClientDLL);
  serverGameDLL->InvalidateMdlCache(this: serverGameDLL);
  g_pDataCache->Flush(this: g_pDataCache, a2: true, a3: true);
  wavedatacache->Flush(this: wavedatacache, a2: false);
}

//------------------------------------------------------------------------------
// Address: 0x1018C040
// Name: flush_locked
// Source: json
//------------------------------------------------------------------------------
void __cdecl flush_locked()
{
  g_ClientDLL->InvalidateMdlCache(this: g_ClientDLL);
  serverGameDLL->InvalidateMdlCache(this: serverGameDLL);
  g_pDataCache->Flush(this: g_pDataCache, a2: false, a3: true);
  wavedatacache->Flush(this: wavedatacache, a2: false);
}

//------------------------------------------------------------------------------
// Address: 0x1018C090
// Name: cache_print
// Source: json
//------------------------------------------------------------------------------
void __cdecl cache_print(const CCommand *args)
{
  const char *v1; // eax

  v1 = nullptr;
  if ( args->m_nArgc == 2 )
    v1 = args->m_ppArgv[1];
  g_pDataCache->OutputReport(this: g_pDataCache, a2: DC_DETAIL_REPORT, a3: v1);
}

//------------------------------------------------------------------------------
// Address: 0x1018C0C0
// Name: cache_print_lru
// Source: json
//------------------------------------------------------------------------------
void __cdecl cache_print_lru(const CCommand *args)
{
  const char *v1; // eax

  v1 = nullptr;
  if ( args->m_nArgc == 2 )
    v1 = args->m_ppArgv[1];
  g_pDataCache->OutputReport(this: g_pDataCache, a2: DC_DETAIL_REPORT_LRU, a3: v1);
}

//------------------------------------------------------------------------------
// Address: 0x1018C0F0
// Name: cache_print_summary
// Source: json
//------------------------------------------------------------------------------
void __cdecl cache_print_summary(const CCommand *args)
{
  const char *v1; // eax

  v1 = nullptr;
  if ( args->m_nArgc == 2 )
    v1 = args->m_ppArgv[1];
  g_pDataCache->OutputReport(this: g_pDataCache, a2: DC_SUMMARY_REPORT, a3: v1);
}

//------------------------------------------------------------------------------
// Address: 0x1018C120
// Name: ss_disconnect
// Source: json
//------------------------------------------------------------------------------
void __cdecl ss_disconnect(const CCommand *args)
{
  int v1; // edx
  int v2; // eax
  int v3; // eax
  CCommand argsClient; // [esp+0h] [ebp-608h] BYREF
  char buf[256]; // [esp+508h] [ebp-100h] BYREF

  if ( cmd_source == src_command )
  {
    v1 = -1;
    v2 = 1;
    if ( host_state.max_splitscreen_players > 1 )
    {
      while ( v2 != 0 )
      {
        if ( ++v2 >= host_state.max_splitscreen_players )
          goto LABEL_7;
      }
      v1 = 0;
    }
LABEL_7:
    if ( args->m_nArgc <= 1 )
    {
      if ( v1 != 0 )
      {
        _Msg(a1: "Can't ss_disconnect, no split screen users active\n");
        return;
      }
    }
    else
    {
      v3 = V_atoi(str: args->m_ppArgv[1]);
      if ( v3 != 0 )
      {
        _Msg(a1: "Can't ss_disconnect, slot %d not active\n", v3);
        return;
      }
    }
    V_snprintf(pDest: buf, maxLen: 256, pFormat: "ss_disconnect %d\n", 0);
    CCommand::CCommand(this: &argsClient);
    CCommand::Tokenize(this: &argsClient, pCommand: buf, pBreakSet: nullptr);
    Cmd_ForwardToServer(args: &argsClient);
    splitscreen->SetDisconnecting(this: splitscreen, a2: 0, a3: true);
  }
  else
  {
    CBaseClient::SplitScreenDisconnect(this: host_client, args);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1018C210
// Name: restart
// Source: json
//------------------------------------------------------------------------------
void __cdecl restart(const CCommand *args)
{
  IGameEvent *v1; // eax
  CClientState *LocalClient; // eax
  bool bRememberLocation; // [esp+0h] [ebp-4h]

  if ( !demoplayer->IsPlayingBack(this: demoplayer)
    && sv.m_State >= ss_active
    && sv.m_nMaxclients <= 1
    && cmd_source == src_command )
  {
    if ( args->m_nArgc != 2 || (bRememberLocation = true, _V_stricmp(s1: args->m_ppArgv[1], s2: "setpos") != 0) )
      bRememberLocation = false;
    v1 = g_GameEventManager->CreateEventA(this: g_GameEventManager, a2: "cs_game_disconnected", a3: 0, a4: 0);
    if ( v1 != nullptr )
      g_GameEventManager->FireEventClientSide(this: g_GameEventManager, a2: v1);
    ++g_nHostDisconnectReentrancyCounter;
    if ( !sv.m_bIsDedicated )
    {
      LocalClient = GetLocalClient(nSlot: -1);
      LocalClient->Disconnect(this: LocalClient, a2: false);
    }
    Host_AllowQueuedMaterialSystem(bAllow: false);
    HostState_GameShutdown();
    --g_nHostDisconnectReentrancyCounter;
    if ( CL_HL2Demo_MapCheck(name: sv.m_szMapname) && CL_PortalDemo_MapCheck(name: sv.m_szMapname) )
      HostState_NewGame(
        pMapName: sv.m_szMapname,
        remember_location: bRememberLocation,
        background: false,
        bSplitScreenConnect: false);
    else
      _Warning(a1: "map load failed: %s not found or invalid\n", sv.m_szMapname);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1018C330
// Name: reload
// Source: json
//------------------------------------------------------------------------------
void __usercall reload(int a1@<edi>, const CCommand *args)
{
  bool v2; // zf
  const char *v3; // edi
  KeyValues *v4; // eax
  KeyValues *v5; // esi
  IMatchEventsSubscription *v6; // eax
  char *m_pszString; // eax
  char *v8; // eax
  char *v9; // eax
  char *v10; // eax
  char *v11; // eax
  char name[260]; // [esp+0h] [ebp-108h] BYREF
  BOOL remember_location; // [esp+104h] [ebp-4h]

  if ( !demoplayer->IsPlayingBack(this: demoplayer)
    && sv.m_State >= ss_active
    && sv.m_nMaxclients <= 1
    && serverGameDLL->SupportsSaveRestore(this: serverGameDLL)
    && cmd_source == src_command )
  {
    v2 = args->m_nArgc == 2;
    LOBYTE(remember_location) = 0;
    if ( v2 )
      LOBYTE(remember_location) = _V_stricmp(s1: args->m_ppArgv[1], s2: "setpos") == 0;
    v3 = (const char *)((int (__thiscall *)(ISaveRestore *, char *, int, int))saverestore->FindRecentSave)(
                         a1: saverestore,
                         a2: name,
                         a3: 260,
                         a4: a1);
    SCR_BeginLoadingPlaque(levelName: nullptr);
    v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v4 != nullptr )
      v5 = KeyValues::KeyValues(this: v4, setName: "OnEngineClientSignonStatePrepareChange");
    else
      v5 = nullptr;
    KeyValues::SetString(this: v5, keyName: "reason", value: "reload");
    v6 = g_pMatchFramework->GetEventsSubscription(this: g_pMatchFramework);
    v6->BroadcastEvent(this: v6, a2: v5);
    Host_Disconnect(bShowMainMenu: false);
    if ( v3 != nullptr && saverestore->SaveFileExists(this: saverestore, a2: v3) )
    {
      HostState_LoadGame(pSaveFileName: v3, remember_location, bLetToolsOverrideLoadGameEnts: false);
      return;
    }
    if ( (host_map.m_nFlags & 0x1000) != 0 )
    {
      m_pszString = "FCVAR_NEVER_AS_STRING";
    }
    else
    {
      m_pszString = host_map.m_pParent->m_Value.m_pszString;
      if ( m_pszString == nullptr )
        m_pszString = (char *)defaultValue;
    }
    if ( !CL_HL2Demo_MapCheck(name: m_pszString) )
    {
      if ( (host_map.m_nFlags & 0x1000) != 0 )
      {
LABEL_20:
        _Warning(a1: "map load failed: %s not found or invalid\n", "FCVAR_NEVER_AS_STRING");
        return;
      }
      v8 = host_map.m_pParent->m_Value.m_pszString;
      if ( v8 == nullptr )
        v8 = (char *)defaultValue;
      goto LABEL_23;
    }
    if ( (host_map.m_nFlags & 0x1000) != 0 )
    {
      v9 = "FCVAR_NEVER_AS_STRING";
    }
    else
    {
      v9 = host_map.m_pParent->m_Value.m_pszString;
      if ( v9 == nullptr )
        v9 = (char *)defaultValue;
    }
    if ( !CL_PortalDemo_MapCheck(name: v9) )
    {
      if ( (host_map.m_nFlags & 0x1000) != 0 )
        goto LABEL_20;
      v8 = host_map.m_pParent->m_Value.m_pszString;
      if ( v8 == nullptr )
        v8 = (char *)defaultValue;
LABEL_23:
      _Warning(a1: "map load failed: %s not found or invalid\n", v8);
      return;
    }
    if ( v3 != nullptr && *v3 != 0 )
    {
      if ( (host_map.m_nFlags & 0x1000) != 0 )
      {
        v10 = "FCVAR_NEVER_AS_STRING";
      }
      else
      {
        v10 = host_map.m_pParent->m_Value.m_pszString;
        if ( v10 == nullptr )
          v10 = (char *)defaultValue;
      }
      _Warning(a1: "SAVERESTORE PROBLEM: %s not found!  Starting new game in %s\n", v3, v10);
    }
    if ( (host_map.m_nFlags & 0x1000) != 0 )
    {
      v11 = "FCVAR_NEVER_AS_STRING";
    }
    else
    {
      v11 = host_map.m_pParent->m_Value.m_pszString;
      if ( v11 == nullptr )
        v11 = (char *)defaultValue;
    }
    HostState_NewGame(pMapName: v11, remember_location, background: false, bSplitScreenConnect: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1018C5C0
// Name: demos
// Source: json
//------------------------------------------------------------------------------
void __cdecl demos(const CCommand *args)
{
  CClientState *BaseLocalClient; // esi
  int demonum; // edi
  IGameEvent *v3; // eax
  CClientState *LocalClient; // eax
  int NumDemos; // eax
  int v6; // ebx
  const char *v7; // eax
  int v8; // eax

  BaseLocalClient = GetBaseLocalClient();
  demonum = BaseLocalClient->demonum;
  BaseLocalClient->demonum = -1;
  v3 = g_GameEventManager->CreateEventA(this: g_GameEventManager, a2: "cs_game_disconnected", a3: 0, a4: 0);
  if ( v3 != nullptr )
    g_GameEventManager->FireEventClientSide(this: g_GameEventManager, a2: v3);
  ++g_nHostDisconnectReentrancyCounter;
  if ( !sv.m_bIsDedicated )
  {
    LocalClient = GetLocalClient(nSlot: -1);
    LocalClient->Disconnect(this: LocalClient, a2: false);
  }
  Host_AllowQueuedMaterialSystem(bAllow: false);
  HostState_GameShutdown();
  --g_nHostDisconnectReentrancyCounter;
  BaseLocalClient->demonum = demonum;
  if ( demonum == -1 )
    BaseLocalClient->demonum = 0;
  if ( args->m_nArgc == 2 )
  {
    NumDemos = Host_GetNumDemos();
    if ( NumDemos >= 1 )
    {
      v6 = NumDemos - 1;
      v7 = defaultValue;
      if ( args->m_nArgc > 1 )
        v7 = args->m_ppArgv[1];
      v8 = V_atoi(str: v7);
      if ( v8 >= 0 )
      {
        if ( v8 > v6 )
          v8 = v6;
      }
      else
      {
        v8 = 0;
      }
      BaseLocalClient->demonum = v8;
      DevMsg(a1: "Jumping to %s\n", BaseLocalClient->demos[v8]);
    }
  }
  Host_PrintDemoList();
  CL_NextDemo();
}

//------------------------------------------------------------------------------
// Address: 0x1018C6C0
// Name: nextdemo
// Source: json
//------------------------------------------------------------------------------
void __cdecl nextdemo(const CCommand *args)
{
  int NumDemos; // eax
  int v2; // esi
  const char *v3; // edi
  int v4; // eax
  int demonum; // esi
  CClientState *BaseLocalClient; // eax

  if ( args->m_nArgc == 2 )
  {
    NumDemos = Host_GetNumDemos();
    if ( NumDemos >= 1 )
    {
      v2 = NumDemos - 1;
      if ( args->m_nArgc > 1 )
        v3 = args->m_ppArgv[1];
      else
        v3 = defaultValue;
      v4 = V_atoi(str: v3);
      if ( v4 >= 0 )
      {
        if ( v4 <= v2 )
          v2 = v4;
      }
      else
      {
        v2 = 0;
      }
      GetBaseLocalClient()->demonum = v2;
      demonum = GetBaseLocalClient()->demonum;
      BaseLocalClient = GetBaseLocalClient();
      DevMsg(a1: "Jumping to %s\n", BaseLocalClient->demos[demonum]);
    }
  }
  Host_EndGame(bShowMainMenu: false, message: "Moving to next demo...");
}

//------------------------------------------------------------------------------
// Address: 0x1018C750
// Name: soundfade
// Source: json
//------------------------------------------------------------------------------
void __cdecl soundfade(const CCommand *args)
{
  int m_nArgc; // eax
  bool v3; // cc
  const char *v4; // eax
  long double v5; // st7
  long double v6; // st6
  long double v7; // st7
  const char *v8; // eax
  long double v9; // st7
  const char *v10; // eax
  long double v11; // st7
  const char *v12; // eax
  const char *v13; // eax
  long double v14; // st7
  float v15; // [esp+Ch] [ebp-14h]
  float holdtime; // [esp+14h] [ebp-Ch]
  float intime; // [esp+18h] [ebp-8h]
  float holdTime; // [esp+28h] [ebp+8h]

  m_nArgc = args->m_nArgc;
  if ( args->m_nArgc == 3 || m_nArgc == 5 )
  {
    v3 = m_nArgc <= 1;
    v4 = defaultValue;
    if ( !v3 )
      v4 = args->m_ppArgv[1];
    v5 = atof(nptr: v4);
    v6 = 0.0;
    if ( v5 < 0.0 || (v6 = v5, v7 = 100.0, v6 <= 100.0) )
      v7 = v6;
    holdtime = v7;
    v8 = defaultValue;
    if ( args->m_nArgc > 2 )
      v8 = args->m_ppArgv[2];
    v3 = atof(nptr: v8) >= 0.0;
    v9 = 0.0;
    if ( v3 )
    {
      v10 = defaultValue;
      if ( args->m_nArgc > 2 )
        v10 = args->m_ppArgv[2];
      v9 = atof(nptr: v10);
    }
    intime = v9;
    holdTime = 0.0;
    if ( args->m_nArgc == 5 )
    {
      v3 = atof(nptr: args->m_ppArgv[3]) >= 0.0;
      v11 = 0.0;
      if ( v3 )
      {
        v12 = defaultValue;
        if ( args->m_nArgc > 3 )
          v12 = args->m_ppArgv[3];
        v11 = atof(nptr: v12);
      }
      holdTime = v11;
      v13 = defaultValue;
      if ( args->m_nArgc > 4 )
        v13 = args->m_ppArgv[4];
      v3 = atof(nptr: v13) >= 0.0;
      v14 = 0.0;
      if ( v3 )
      {
        if ( args->m_nArgc > 4 )
          v14 = atof(nptr: args->m_ppArgv[4]);
        else
          v14 = atof(nptr: defaultValue);
      }
    }
    else
    {
      v14 = 0.0;
    }
    v15 = v14;
    S_SoundFade(percent: holdtime, holdtime: intime, intime: holdTime, outtime: v15);
  }
  else
  {
    _Msg(a1: "soundfade <percent> <hold> [<out> <int>]\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x1018C8B0
// Name: void Host_VoiceRecordStart_f(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Host_VoiceRecordStart_f()
{
  const char *v0; // ecx
  const char *v1; // edx
  const char *v2; // esi
  ConVarRef voice_vox; // [esp+0h] [ebp-8h] BYREF

  ConVarRef::ConVarRef(this: &voice_vox, pName: "voice_vox");
  if ( voice_vox.m_pConVarState->m_Value.m_nValue == 0 && GetLocalClient(nSlot: 0)->m_nSignonState == 6 )
  {
    v0 = nullptr;
    v1 = nullptr;
    v2 = nullptr;
    if ( voice_recordtofile.m_pParent != nullptr && voice_recordtofile.m_pParent->m_Value.m_nValue != 0 )
    {
      v0 = "voice_micdata.wav";
      v1 = "voice_decompressed.wav";
    }
    if ( voice_inputfromfile.m_pParent != nullptr && voice_inputfromfile.m_pParent->m_Value.m_nValue != 0 )
      v2 = "voice_input.wav";
    Voice_RecordStart(pUncompressedFile: v0, pDecompressedFile: v1, pMicInputFile: v2);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1018C920
// Name: void Host_VoiceRecordStop_f(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Host_VoiceRecordStop_f(const CCommand *args)
{
  ConVarRef voice_vox; // [esp+0h] [ebp-8h] BYREF

  ConVarRef::ConVarRef(this: &voice_vox, pName: "voice_vox");
  if ( voice_vox.m_pConVarState->m_Value.m_nValue == 0 && GetLocalClient(nSlot: 0)->m_nSignonState == 6 )
  {
    if ( Voice_IsRecording() )
    {
      CL_SendVoicePacket(bFinal: true);
      Voice_RecordStop();
    }
    if ( args->m_nArgc != 2 || V_strcasecmp(s1: args->m_ppArgv[1], s2: "force") != 0 )
      voice_vox.m_pConVar->SetValue_2(this: voice_vox.m_pConVar, a2: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1018C9A0
// Name: status
// Source: json
//------------------------------------------------------------------------------
void __cdecl status(const CCommand *args)
{
  void (*v1)(const char *, ...); // ebx
  char *m_pszString; // eax
  const char *v3; // esi
  ISteamGameServer *m_pSteamGameServer; // ecx
  ISteamGameServer *v5; // ecx
  CSteam3Client *v6; // eax
  int v7; // eax
  CSteam3Server *v8; // eax
  const char *v9; // eax
  const char *v10; // ecx
  const char *VersionString; // eax
  const char *v12; // esi
  const char *v13; // eax
  IHLTVDirector *v14; // eax
  CHLTVServer *v15; // esi
  unsigned __int64 v16; // st7
  int v17; // eax
  bool v18; // zf
  const char *v19; // eax
  int j; // edi
  CBaseClient *v21; // eax
  IClient *v22; // esi
  const char *v23; // eax
  int i; // edi
  CBaseClient *v25; // eax
  IClient *v26; // esi
  int HostVersion; // [esp-Ch] [ebp-30h]
  int v28; // [esp-8h] [ebp-2Ch]
  const char *v29; // [esp-4h] [ebp-28h]
  int UDPPort; // [esp-4h] [ebp-28h]
  double v31; // [esp+0h] [ebp-24h]
  const char *v32; // [esp+4h] [ebp-20h]
  int v33; // [esp+14h] [ebp-10h] BYREF
  int v34; // [esp+18h] [ebp-Ch] BYREF
  int nMaxHumanSlots; // [esp+1Ch] [ebp-8h] BYREF
  int nHumans; // [esp+20h] [ebp-4h]

  if ( cmd_source == src_command )
  {
    if ( sv.m_State < ss_active )
    {
      Cmd_ForwardToServer(args);
      return;
    }
    v1 = ConMsg;
  }
  else
  {
    v1 = Host_Client_Printf;
  }
  if ( (host_name.m_nFlags & 0x1000) != 0 )
  {
    m_pszString = "FCVAR_NEVER_AS_STRING";
  }
  else
  {
    m_pszString = host_name.m_pParent->m_Value.m_pszString;
    if ( m_pszString == nullptr )
      m_pszString = (char *)defaultValue;
  }
  v1(a1: "hostname: %s\n", m_pszString);
  v3 = defaultValue;
  m_pSteamGameServer = Steam3Server()->m_pSteamGameServer;
  if ( m_pSteamGameServer != nullptr && m_pSteamGameServer->BSecure(this: m_pSteamGameServer) )
  {
    HIBYTE(nHumans) = 1;
  }
  else
  {
    HIBYTE(nHumans) = 0;
    if ( Steam3Server()->m_eServerMode == eServerModeAuthenticationAndSecure )
    {
      v5 = Steam3Server()->m_pSteamGameServer;
      if ( v5 == nullptr || (v3 = "(secure mode enabled, connected to Steam3)", !v5->BLoggedOn(this: v5)) )
        v3 = "(secure mode enabled, disconnected from Steam3)";
    }
  }
  if ( Steam3Client()->m_pSteamUtils != nullptr )
  {
    v6 = Steam3Client();
    v7 = v6->m_pSteamUtils->GetConnectedUniverse(this: v6->m_pSteamUtils);
  }
  else if ( Steam3Server()->m_pSteamGameServerUtils != nullptr )
  {
    v8 = Steam3Server();
    v7 = v8->m_pSteamGameServerUtils->GetConnectedUniverse(this: v8->m_pSteamGameServerUtils);
  }
  else
  {
    v7 = 0;
  }
  switch ( v7 )
  {
    case 1:
      v9 = defaultValue;
      break;
    case 2:
      v9 = "(beta)";
      break;
    case 3:
      v9 = "(internal)";
      break;
    case 4:
      v9 = "(dev)";
      break;
    case 5:
      v9 = "(rc)";
      break;
    default:
      v9 = "(unknown)";
      break;
  }
  v10 = "secure";
  if ( HIBYTE(nHumans) == 0 )
    v10 = "insecure";
  v32 = v9;
  v29 = v10;
  v28 = build_number();
  HostVersion = GetHostVersion();
  VersionString = Sys_GetVersionString();
  v1(a1: "version : %s/%d %d %s %s %s\n", VersionString, HostVersion, v28, v29, v3, v32);
  if ( NET_IsMultiplayer() )
  {
    v12 = "dedicated";
    if ( !sv.m_bIsDedicated )
      v12 = "listen";
    UDPPort = NET_GetUDPPort(socket: sv.m_Socket);
    v13 = netadr_s::ToString(this: &net_local_adr, baseOnly: true);
    v1(a1: "udp/ip  :  %s:%i os(%s) type(%s)\n", v13, UDPPort, "Windows", v12);
  }
  if ( !sv.m_bIsDedicated && GetBaseLocalClient()->m_nSignonState >= 2 )
    v1(
      a1: "map     : %s at: %d x, %d y, %d z\n",
      sv.m_szMapname,
      (int)g_MainViewOrigin[0].x,
      (int)*(float *)&dword_104F1BE0,
      (int)*(float *)&dword_104F1BE4);
  if ( hltv != nullptr && hltv->IsActive(this: &hltv->CBaseServer) )
  {
    v14 = hltv->GetDirector(this: &hltv->IHLTVServer);
    v15 = hltv;
    *(double *)&v16 = ((double (__thiscall *)(IHLTVDirector *))v14->GetDelay)(a1: v14);
    v17 = ((int (__thiscall *)(CBaseServer *, _DWORD, _DWORD))v15->GetUDPPort)(
            a1: &v15->CBaseServer,
            a2: v16,
            a3: HIDWORD(v16));
    v1(a1: "sourcetv:  port %i, delay %.1fs\n", v17, v31);
  }
  CBaseServer::GetMasterServerPlayerCounts(this: &sv, nHumans: &v33, &nMaxHumanSlots, nBots: &v34);
  v18 = !CGameServer::IsHibernating(this: &sv);
  v19 = "hibernating";
  if ( v18 )
    v19 = "not hibernating";
  v1(a1: "players : %i humans, %i bots (%i max) (%s)\n\n", v33, v34, nMaxHumanSlots, v19);
  if ( args->m_nArgc != 2 || _V_stricmp(s1: args->m_ppArgv[1], s2: "short") != 0 )
  {
    v1(a1: "# userid name uniqueid connected ping loss state rate");
    if ( cmd_source == src_command )
      v1(a1: " adr");
    v1(a1: "\n");
    for ( i = 0; i < sv.m_Clients.m_Size; ++i )
    {
      v25 = sv.m_Clients.m_Memory.m_pMemory[i];
      if ( v25 != nullptr )
        v26 = &v25->IClient;
      else
        v26 = nullptr;
      if ( v26->IsConnected(this: v26) )
        Host_Status_PrintClient(client: v26, bShowAddress: cmd_source == src_command, print: v1);
    }
    v1(a1: "#end\n");
  }
  else
  {
    for ( j = 0; j < sv.m_Clients.m_Size; ++j )
    {
      v21 = sv.m_Clients.m_Memory.m_pMemory[j];
      if ( v21 != nullptr )
        v22 = &v21->IClient;
      else
        v22 = nullptr;
      if ( v22->IsActive(this: v22) )
      {
        v23 = v22->GetClientName(this: v22);
        v1(a1: "#%i - %s\n", j + 1, v23);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1018CD50
// Name: ping
// Source: json
//------------------------------------------------------------------------------
void __usercall ping(int a1@<esi>, const CCommand *args)
{
  int v2; // edi
  CBaseClient *v3; // esi
  IClient *v4; // esi
  int v5; // eax
  IClient_vtbl *v6; // edi
  int v7; // ebx
  double v8; // st7
  int i; // [esp+14h] [ebp-4h]

  if ( cmd_source == src_command )
  {
    Cmd_ForwardToServer(args);
  }
  else
  {
    ((void (__stdcall *)(IClient *))host_client->ClientPrintf)(a1: &host_client->IClient);
    v2 = 0;
    for ( i = 0; v2 < sv.m_Clients.m_Size; i = v2 )
    {
      v3 = sv.m_Clients.m_Memory.m_pMemory[v2];
      if ( v3 != nullptr )
        v4 = &v3->IClient;
      else
        v4 = nullptr;
      if ( v4->IsConnected(this: v4) && !v4->IsFakeClient(this: v4) )
      {
        v5 = ((int (__thiscall *)(IClient *, int))v4->GetNetChannel)(a1: v4, a2: a1);
        v6 = host_client->CBaseClient::IClient::INetChannelHandler::__vftable;
        v7 = v5;
        a1 = (int)v4->GetClientName(this: v4);
        v8 = ((double (__thiscall *)(int, _DWORD))*(_DWORD *)(*(_DWORD *)v7 + 40))(a1: v7, a2: 0);
        v6->ClientPrintf(this: &host_client->IClient, a2: "%4.0f ms : %s\n", v8 * 1000.0);
        v2 = i;
      }
      ++v2;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1018CE40
// Name: kickid
// Source: json
//------------------------------------------------------------------------------
void __cdecl kickid(const CCommand *args)
{
  int m_nArgc; // eax
  int v2; // edi
  const char *v3; // eax
  const char *v4; // ecx
  const char *v5; // eax
  const char *v6; // esi
  int m_nArgv0Size; // eax
  int v8; // esi
  const char **v9; // ebx
  const char *v10; // eax
  int v11; // ebx
  CBaseClient *v12; // eax
  int v13; // esi
  int v14; // edi
  int v15; // edx
  bool v16; // zf
  const char *v17; // eax
  IClient *v18; // eax
  int v19; // ecx
  char szSearchString[128]; // [esp+8h] [ebp-94h] BYREF
  char *who; // [esp+88h] [ebp-14h]
  int iSearchIndex; // [esp+8Ch] [ebp-10h]
  int argsStartNum; // [esp+90h] [ebp-Ch]
  const char *pszMessage; // [esp+94h] [ebp-8h]
  bool bSteamID; // [esp+9Bh] [ebp-1h]

  m_nArgc = args->m_nArgc;
  v2 = 0;
  who = "Console";
  pszMessage = nullptr;
  iSearchIndex = -1;
  argsStartNum = 1;
  bSteamID = false;
  if ( m_nArgc > 1 )
  {
    v6 = args->m_ppArgv[1];
    if ( *v6 < 48 || *v6 > 57 )
    {
      if ( V_strnicmp(s1: v6, s2: "STEAM_", n: 6) != 0 )
        goto LABEL_16;
      v3 = defaultValue;
      if ( args->m_nArgc > 2 )
        v3 = args->m_ppArgv[2];
      if ( _V_strstr(s1: v3, search: ":") == nullptr )
      {
LABEL_16:
        V_snprintf(pDest: szSearchString, maxLen: 128, pFormat: "%s", v6);
      }
      else
      {
        v4 = defaultValue;
        if ( args->m_nArgc > 5 )
          v4 = args->m_ppArgv[5];
        v5 = defaultValue;
        if ( args->m_nArgc > 3 )
          v5 = args->m_ppArgv[3];
        V_snprintf(pDest: szSearchString, maxLen: 128, pFormat: "%s:%s:%s", v6, v5, v4);
        argsStartNum = 5;
        bSteamID = true;
      }
    }
    else
    {
      iSearchIndex = V_atoi(str: args->m_ppArgv[1]);
    }
    if ( args->m_nArgc > argsStartNum )
    {
      m_nArgv0Size = args->m_nArgv0Size;
      if ( m_nArgv0Size != 0 )
        pszMessage = &args->m_pArgSBuffer[m_nArgv0Size];
      else
        pszMessage = defaultValue;
      v8 = 1;
      if ( argsStartNum >= 1 )
      {
        v9 = &args->m_ppArgv[1];
        do
        {
          if ( v8 < 0 || v8 >= args->m_nArgc )
            v10 = defaultValue;
          else
            v10 = *v9;
          ++v8;
          ++v9;
          v2 += _V_strlen(str: v10) + 1;
        }
        while ( v8 <= argsStartNum );
      }
      if ( bSteamID )
        v2 -= 5;
      if ( v2 <= _V_strlen(str: pszMessage) )
        pszMessage += v2;
      else
        pszMessage = nullptr;
    }
    v11 = 0;
    if ( sv.m_Clients.m_Size <= 0 )
      goto LABEL_43;
    while ( 1 )
    {
      v12 = sv.m_Clients.m_Memory.m_pMemory[v11];
      v13 = v12 != nullptr ? (int)&v12->IClient : 0;
      if ( (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v13 + 124))(a1: v13) != 0 )
      {
        v14 = iSearchIndex;
        v15 = *(_DWORD *)v13;
        if ( iSearchIndex == -1 )
        {
          v17 = (const char *)(*(int (__thiscall **)(int))(v15 + 84))(a1: v13);
          v16 = _V_stricmp(s1: v17, s2: szSearchString) == 0;
        }
        else
        {
          v16 = (*(int (__thiscall **)(int))(v15 + 60))(a1: v13) == v14;
        }
        if ( v16 )
          break;
      }
      if ( ++v11 >= sv.m_Clients.m_Size )
        goto LABEL_43;
    }
    if ( v11 >= sv.m_Clients.m_Size )
    {
LABEL_43:
      if ( iSearchIndex == -1 )
        ConMsg(a1: "uniqueid \"%s\" not found\n", szSearchString);
      else
        ConMsg(a1: "userid \"%d\" not found\n", iSearchIndex);
    }
    else
    {
      if ( (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v13 + 156))(a1: v13) != 0
        && (*(int (__thiscall **)(int))(*(_DWORD *)v13 + 168))(a1: v13) != 0 )
      {
        v13 = (*(int (__thiscall **)(int))(*(_DWORD *)v13 + 168))(a1: v13);
      }
      if ( cmd_source != src_command )
        who = host_client->m_Name;
      if ( host_client != nullptr )
        v18 = &host_client->IClient;
      else
        v18 = nullptr;
      if ( (v18 != (IClient *)v13 || sv.m_bIsDedicated)
        && (iSearchIndex != -1 || (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v13 + 136))(a1: v13) == 0) )
      {
        v19 = *(_DWORD *)v13;
        if ( pszMessage != nullptr )
          (*(void (**)(int, const char *, ...))(v19 + 52))(a1: v13, a2: "Kicked by %s : %s", who, pszMessage);
        else
          (*(void (**)(int, const char *, ...))(v19 + 52))(a1: v13, a2: "Kicked by %s", who);
      }
    }
  }
  else
  {
    ConMsg(a1: "Usage:  kickid < userid | uniqueid > { message }\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x1018D140
// Name: kick
// Source: json
//------------------------------------------------------------------------------
void __cdecl kick(const CCommand *args)
{
  bool v1; // cc
  int m_nArgv0Size; // eax
  bool v3; // zf
  const char *v4; // eax
  char *v5; // ebx
  int v6; // eax
  char *v7; // eax
  int v8; // edi
  CBaseClient *v9; // eax
  int v10; // esi
  const char *v11; // eax
  char *m_Name; // ecx
  IClient *v13; // eax
  char name[64]; // [esp+4h] [ebp-44h] BYREF
  char *who; // [esp+44h] [ebp-4h]

  v1 = args->m_nArgc <= 1;
  who = "Console";
  if ( v1 )
  {
    ConMsg(a1: "Usage:  kick < name >\n");
  }
  else
  {
    memset(dst: (unsigned __int8 *)name, value: 0, count: sizeof(name));
    m_nArgv0Size = args->m_nArgv0Size;
    v3 = m_nArgv0Size == 0;
    v4 = &args->m_pArgSBuffer[m_nArgv0Size];
    if ( v3 )
      v4 = defaultValue;
    V_strncpy(pDest: name, pSrc: v4, maxLen: 64);
    v5 = name;
    if ( name[0] != 0 )
    {
      v6 = _V_strlen(str: name);
      if ( name[0] == 34 )
      {
        v3 = name[v6 - 1] == 34;
        v7 = &name[v6 - 1];
        if ( v3 )
        {
          *v7 = 0;
          v5 = &name[1];
        }
      }
      v8 = 0;
      if ( sv.m_Clients.m_Size <= 0 )
        goto LABEL_16;
      while ( 1 )
      {
        v9 = sv.m_Clients.m_Memory.m_pMemory[v8];
        v10 = v9 != nullptr ? (int)&v9->IClient : 0;
        if ( (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v10 + 124))(a1: v10) != 0 )
        {
          v11 = (const char *)(*(int (__thiscall **)(int))(*(_DWORD *)v10 + 68))(a1: v10);
          if ( V_strcasecmp(s1: v11, s2: v5) == 0 )
            break;
        }
        if ( ++v8 >= sv.m_Clients.m_Size )
          goto LABEL_16;
      }
      if ( v8 >= sv.m_Clients.m_Size )
      {
LABEL_16:
        ConMsg(a1: "Can't kick \"%s\", name not found\n", v5);
      }
      else
      {
        if ( (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v10 + 156))(a1: v10) != 0
          && (*(int (__thiscall **)(int))(*(_DWORD *)v10 + 168))(a1: v10) != 0 )
        {
          v10 = (*(int (__thiscall **)(int))(*(_DWORD *)v10 + 168))(a1: v10);
        }
        m_Name = host_client->m_Name;
        if ( cmd_source == src_command )
          m_Name = who;
        if ( host_client != nullptr )
          v13 = &host_client->IClient;
        else
          v13 = nullptr;
        if ( v13 != (IClient *)v10 || sv.m_bIsDedicated )
          (*(void (**)(int, const char *, ...))(*(_DWORD *)v10 + 52))(a1: v10, a2: "Kicked by %s", m_Name);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1018D2A0
// Name: void Host_PrintMemoryStatus(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Host_PrintMemoryStatus(const char *mapname)
{
  unsigned int v1; // eax
  _MEMORYSTATUS Buffer; // [esp+20h] [ebp-24h] BYREF
  signed int dwTotalPhys; // [esp+40h] [ebp-4h]

  GlobalMemoryStatus(lpBuffer: &Buffer);
  dwTotalPhys = Buffer.dwTotalPhys;
  _Msg(
    a1: "[MEMORYSTATUS] [%s] Operating system reports Available: %.2f MB, Used: %.2f MB, Free: %.2f MB\n",
    mapname,
    0.00000095367432 * (double)Buffer.dwTotalPhys - 32.0,
    (double)(Buffer.dwTotalPhys - Buffer.dwAvailPhys) * 0.00000095367432 - 32.0,
    (double)Buffer.dwAvailPhys * 0.00000095367432);
  _g_pMemAlloc->SetStatsExtraInfo(this: _g_pMemAlloc, a2: mapname, a3: defaultValue);
  v1 = _g_pMemAlloc->GetSize(this: _g_pMemAlloc, a2: nullptr);
  dwTotalPhys = v1;
  if ( v1 == -1 )
    _Msg(a1: "Internal heap corrupted!\n");
  else
    _Msg(a1: "Internal heap reports: %5.2f MB (%d bytes)\n", (double)dwTotalPhys * 0.00000095367432, v1);
  _Msg(a1: "\nHunk Memory Used:\n");
  Hunk_Print();
  _Msg(a1: "\nDatacache reports:\n");
  ((void (__thiscall *)(IDataCache *, _DWORD))g_pDataCache->OutputReport)(a1: g_pDataCache, a2: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1018D3B0
// Name: Host_Map_Helper_FuzzyName
// Source: json
//------------------------------------------------------------------------------
char __usercall Host_Map_Helper_FuzzyName@<al>(const CCommand *args@<esi>, char *name, int bufsize)
{
  const char *v3; // eax
  int m_nArgv0Size; // eax
  bool v5; // zf
  char *v6; // eax
  const char *v7; // eax
  int v8; // eax
  const char *v10; // [esp-8h] [ebp-1018h]
  char commands[64]; // [esp+0h] [ebp-1010h] BYREF
  CUtlString v12; // [esp+1000h] [ebp-10h] BYREF

  CUtlString::CUtlString(this: &v12);
  v3 = defaultValue;
  if ( args->m_nArgc > 0 )
    v3 = args->m_ppArgv[0];
  CUtlString::operator=(this: &v12, src: v3);
  CUtlString::operator+=(this: &v12, rhs: " ");
  m_nArgv0Size = args->m_nArgv0Size;
  v5 = m_nArgv0Size == 0;
  v6 = &args->m_pArgSBuffer[m_nArgv0Size];
  if ( v5 )
    v6 = (char *)defaultValue;
  v10 = v6;
  v7 = CUtlString::operator char const *(this: &v12);
  if ( _Host_Map_f_CompletionFunc(cmdname: v7, partial: v10, (char (*)[64])commands) <= 0 )
  {
    v12.m_Storage.m_nActualLength = 0;
    if ( v12.m_Storage.m_Memory.m_nGrowSize >= 0 && v12.m_Storage.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v12.m_Storage.m_Memory.m_pMemory);
    return 0;
  }
  else
  {
    v8 = CUtlString::Length(this: &v12);
    V_strncpy(pDest: name, pSrc: &commands[v8], maxLen: bufsize);
    v12.m_Storage.m_nActualLength = 0;
    if ( v12.m_Storage.m_Memory.m_nGrowSize >= 0 && v12.m_Storage.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v12.m_Storage.m_Memory.m_pMemory);
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1018D490
// Name: void Host_Map_Helper(class CCommand const __near &,enum EMapFlags)
// Source: json
//------------------------------------------------------------------------------
void __usercall Host_Map_Helper(int a1@<edi>, const CCommand *args, EMapFlags flags)
{
  bool v3; // cc
  const char *v4; // eax
  const char *v5; // eax
  const char *v6; // eax
  const char *v7; // eax
  const char *v8; // eax
  const char *v9; // eax
  const char *v10; // eax
  const char *v11; // esi
  char name[96]; // [esp+0h] [ebp-E4h] BYREF
  char ppath[96]; // [esp+60h] [ebp-84h] BYREF
  Vector newpos; // [esp+C0h] [ebp-24h] BYREF
  QAngle newangle; // [esp+CCh] [ebp-18h] BYREF
  BOOL bBackground; // [esp+DBh] [ebp-9h]
  BOOL bSplitScreenConnect; // [esp+DFh] [ebp-5h]
  bool bCommentary; // [esp+E3h] [ebp-1h]

  if ( cmd_source == src_command )
  {
    if ( args->m_nArgc >= 2 )
    {
      if ( sv.m_State < ss_active || CBaseServer::IsSinglePlayerGame(this: &sv) || sv.m_bIsLevelMainMenuBackground )
      {
        v3 = args->m_nArgc <= 1;
        LOBYTE(bBackground) = (flags & 2) != 0;
        LOBYTE(bSplitScreenConnect) = (flags & 8) != 0;
        v4 = defaultValue;
        if ( !v3 )
          v4 = args->m_ppArgv[1];
        V_StripExtension(in: v4, out: ppath, outSize: 96);
        if ( modelloader->Map_IsValid(this: modelloader, a2: ppath, a3: true)
          || (Host_Map_Helper_FuzzyName(args, name: ppath, bufsize: 96),
              modelloader->Map_IsValid(this: modelloader, a2: ppath, a3: false)) )
        {
          GetPlatformMapPath(pMapPath: ppath, pPlatformMapPath: name, maxLength: 96);
          bCommentary = (flags & 4) != 0;
          if ( (flags & 1) != 0 )
          {
            g_bInEditMode = true;
          }
          else if ( g_bInEditMode )
          {
            Host_ReadConfiguration(a1: flags, a2: a1, a3: (int)args, iController: -1);
            g_bInEditMode = false;
          }
          g_bInCommentaryMode = bCommentary;
          SetLaunchOptions(args);
          if ( CL_HL2Demo_MapCheck(name) && CL_PortalDemo_MapCheck(name) )
          {
            GetBaseLocalClient()->demonum = -1;
            Host_Disconnect(bShowMainMenu: false);
            HostState_NewGame(pMapName: name, remember_location: false, background: bBackground, bSplitScreenConnect);
            if ( args->m_nArgc == 10 && _V_stricmp(s1: args->m_ppArgv[2], s2: "setpos") == 0 )
            {
              v5 = defaultValue;
              if ( args->m_nArgc > 6 )
                v5 = args->m_ppArgv[6];
              if ( _V_stricmp(s1: v5, s2: "setang") == 0 )
              {
                v6 = defaultValue;
                if ( args->m_nArgc > 3 )
                  v6 = args->m_ppArgv[3];
                newpos.x = atof(nptr: v6);
                v7 = defaultValue;
                if ( args->m_nArgc > 4 )
                  v7 = args->m_ppArgv[4];
                newpos.y = atof(nptr: v7);
                v8 = defaultValue;
                if ( args->m_nArgc > 5 )
                  v8 = args->m_ppArgv[5];
                newpos.z = atof(nptr: v8);
                v9 = defaultValue;
                if ( args->m_nArgc > 7 )
                  v9 = args->m_ppArgv[7];
                newangle.x = atof(nptr: v9);
                v10 = defaultValue;
                if ( args->m_nArgc > 8 )
                  v10 = args->m_ppArgv[8];
                newangle.y = atof(nptr: v10);
                if ( args->m_nArgc > 9 )
                  v11 = args->m_ppArgv[9];
                else
                  v11 = defaultValue;
                newangle.z = atof(nptr: v11);
                HostState_SetSpawnPoint(position: &newpos, angle: &newangle);
              }
            }
          }
          else
          {
            _Warning(a1: "map load failed: %s not found or invalid\n", name);
          }
        }
        else
        {
          _Warning(a1: "map load failed: %s not found or invalid\n", ppath);
        }
      }
      else
      {
        Host_Changelevel_f(args);
      }
    }
    else
    {
      _Warning(a1: "No map specified\n");
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1018D780
// Name: void Host_Map_f(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
void __usercall Host_Map_f(int a1@<edi>, const CCommand *args)
{
  Host_Map_Helper(a1, args, flags: EMAP_NONE);
}

//------------------------------------------------------------------------------
// Address: 0x1018D7A0
// Name: void Host_SplitScreen_Map_f(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
void __usercall Host_SplitScreen_Map_f(int a1@<edi>, const CCommand *args)
{
  Host_Map_Helper(a1, args, flags: EMAP_SPLITSCREEN);
}

//------------------------------------------------------------------------------
// Address: 0x1018D7C0
// Name: map_edit
// Source: json
//------------------------------------------------------------------------------
void __usercall map_edit(int a1@<edi>, const CCommand *args)
{
  Host_Map_Helper(a1, args, flags: EMAP_EDIT_MODE);
}

//------------------------------------------------------------------------------
// Address: 0x1018D7E0
// Name: void Host_Map_Background_f(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
void __usercall Host_Map_Background_f(int a1@<edi>, const CCommand *args)
{
  Host_Map_Helper(a1, args, flags: EMAP_BACKGROUND);
}

//------------------------------------------------------------------------------
// Address: 0x1018D800
// Name: void Host_Map_Commentary_f(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
void __usercall Host_Map_Commentary_f(int a1@<edi>, const CCommand *args)
{
  Host_Map_Helper(a1, args, flags: EMAP_COMMENTARY);
}

//------------------------------------------------------------------------------
// Address: 0x1018D820
// Name: ss_connect
// Source: json
//------------------------------------------------------------------------------
void __usercall ss_connect(int a1@<esi>)
{
  int v1; // esi
  CClientState *BaseLocalClient; // eax
  CLC_SplitPlayerConnect msg; // [esp+0h] [ebp-24h] BYREF

  if ( cmd_source == src_command )
  {
    if ( host_state.max_splitscreen_players == 1 )
    {
      if ( toolframework->InToolMode(this: toolframework) )
        _Msg(a1: "Can't ss_connect, split screen not supported when running -tools mode.\n");
      else
        _Msg(a1: "Can't ss_connect, game does not support split screen.\n");
    }
    else if ( GetBaseLocalClient()->m_nSignonState >= 2 )
    {
      v1 = 1;
      if ( ((unsigned __int8 (__thiscall *)(ISplitScreen *, int, int))splitscreen->IsValidSplitScreenSlot)(
             a1: splitscreen,
             a2: 1,
             a3: a1) != 0 )
      {
        do
          ++v1;
        while ( splitscreen->IsValidSplitScreenSlot(this: splitscreen, a2: v1) );
      }
      if ( v1 < host_state.max_splitscreen_players )
      {
        msg.m_bReliable = true;
        msg.m_NetChannel = nullptr;
        msg.__vftable = (CLC_SplitPlayerConnect_vtbl *)&CLC_SplitPlayerConnect::`vftable';
        memset(&msg.m_UserInfo, 0, sizeof(msg.m_UserInfo));
        Host_BuildUserInfoUpdateMessage(nSplitScreenSlot: v1, rCvarList: &msg.m_UserInfo, nonDefault: false);
        BaseLocalClient = GetBaseLocalClient();
        ((void (__thiscall *)(INetChannel *, CLC_SplitPlayerConnect *, _DWORD))BaseLocalClient->m_NetChannel->SendNetMsg)(
          a1: BaseLocalClient->m_NetChannel,
          a2: &msg,
          a3: 0);
        CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&msg.m_UserInfo);
      }
      else
      {
        _Msg(a1: "Can't ss_connect, no more split screen player slots!\n");
      }
    }
    else
    {
      _Msg(a1: "Can't ss_connect, not connected to game.\n");
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102F2748
// Name: __flush
// Source: json
//------------------------------------------------------------------------------
int __cdecl _flush(_iobuf *str)
{
  int flag; // eax
  int v2; // ebx
  char *base; // eax
  char *v4; // edi
  int v5; // eax
  int v6; // eax
  char *v7; // eax
  char *v9; // [esp-Ch] [ebp-14h]
  char *v10; // [esp-8h] [ebp-10h]

  flag = str->_flag;
  v2 = 0;
  if ( (flag & 3) == 2 && (flag & 0x108) != 0 )
  {
    base = str->_base;
    v4 = (char *)(str->_ptr - base);
    if ( (int)v4 > 0 )
    {
      v10 = (char *)(str->_ptr - base);
      v9 = str->_base;
      v5 = fileno(stream: str);
      if ( (char *)_write(fh: v5, buf: v9, cnt: (unsigned int)v10) == v4 )
      {
        v6 = str->_flag;
        if ( (v6 & 0x80u) != 0 )
          str->_flag = v6 & 0xFFFFFFFD;
      }
      else
      {
        str->_flag |= 0x20u;
        v2 = -1;
      }
    }
  }
  v7 = str->_base;
  str->_cnt = 0;
  str->_ptr = v7;
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x102F27B0
// Name: __fflush_nolock
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _fflush_nolock(_iobuf *str)
{
  int v2; // eax

  if ( str == nullptr )
    return flsall(flushflag: 0);
  if ( _flush(str) != 0 )
    return -1;
  if ( (str->_flag & 0x4000) == 0 )
    return 0;
  v2 = fileno(stream: str);
  return -(_commit(filedes: v2) != 0);
}

//------------------------------------------------------------------------------
// Address: 0x102F27F8
// Name: flsall
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl flsall(int flushflag)
{
  int i; // esi
  char **v2; // eax
  char *v3; // eax
  int v4; // ecx
  int result; // eax
  int err; // [esp+10h] [ebp-24h]
  int count; // [esp+18h] [ebp-1Ch]

  count = 0;
  err = 0;
  _lock(locknum: 1);
  for ( i = 0; i < (int)_nstream; ++i )
  {
    v2 = (char **)&__piob[i];
    if ( *v2 != nullptr )
    {
      v3 = *v2;
      if ( (v3[12] & 0x83) != 0 )
      {
        _lock_file2(i, s: v3);
        v4 = *((_DWORD *)__piob[i] + 3);
        if ( (v4 & 0x83) != 0 )
        {
          if ( flushflag == 1 )
          {
            if ( _fflush_nolock(str: (_iobuf *)__piob[i]) != -1 )
              ++count;
          }
          else if ( flushflag == 0 && (v4 & 2) != 0 && _fflush_nolock(str: (_iobuf *)__piob[i]) == -1 )
          {
            err = -1;
          }
        }
        _unlock_file2(i, s: (char *)__piob[i]);
      }
    }
  }
  _unlock(locknum: 1);
  result = count;
  if ( flushflag != 1 )
    return err;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102F28D2
// Name: _fflush
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl fflush(_iobuf *stream)
{
  int rc; // [esp+10h] [ebp-1Ch]

  if ( stream == nullptr )
    return flsall(flushflag: 0);
  _lock_file(pf: stream);
  rc = _fflush_nolock(str: stream);
  _unlock_file(pf: stream);
  return rc;
}

//------------------------------------------------------------------------------
// Address: 0x102F2925
// Name: __flushall
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _flushall()
{
  return flsall(flushflag: 1);
}

//------------------------------------------------------------------------------
// Address: 0x102F292E
// Name: ___crtCorExitProcess
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl __crtCorExitProcess(int status)
{
  HMODULE ModuleHandleW; // eax
  FARPROC CorExitProcess; // eax

  ModuleHandleW = GetModuleHandleW(lpModuleName: L"mscoree.dll");
  if ( ModuleHandleW != nullptr )
  {
    CorExitProcess = GetProcAddress(hModule: ModuleHandleW, lpProcName: "CorExitProcess");
    if ( CorExitProcess != nullptr )
      ((void (__stdcall *)(int))CorExitProcess)(a1: status);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102F2959
// Name: ___crtExitProcess
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl __noreturn __crtExitProcess(int status)
{
  __crtCorExitProcess(status);
  ExitProcess(uExitCode: status);
}

//------------------------------------------------------------------------------
// Address: 0x102F2971
// Name: __lockexit
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void _lockexit()
{
  _lock(locknum: 8);
}

//------------------------------------------------------------------------------
// Address: 0x102F297A
// Name: __unlockexit
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void _unlockexit()
{
  _unlock(locknum: 8);
}

//------------------------------------------------------------------------------
// Address: 0x102F2983
// Name: __init_pointers
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void _init_pointers()
{
  PVOID v0; // esi

  v0 = _encoded_null();
  _initp_heap_handler(enull: v0);
  _initp_misc_invarg(enull: v0);
  _initp_misc_purevirt(enull: v0);
  _initp_misc_rand_s(enull: v0);
  _initp_misc_winsig(enull: v0);
  _initp_eh_hooks();
}

//------------------------------------------------------------------------------
// Address: 0x102F29B6
// Name: __initterm_e
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _initterm_e(int (__cdecl **pfbegin)(), int (__cdecl **pfend)())
{
  int result; // eax

  result = 0;
  while ( pfbegin < pfend && result == 0 )
  {
    if ( *pfbegin != nullptr )
      result = (*pfbegin)();
    ++pfbegin;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102F29DA
// Name: __cinit
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _cinit(int initFloatingPrecision)
{
  int result; // eax
  void (**i)(void); // edi

  if ( _fpmath != nullptr && _IsNonwritableInCurrentImage(pTarget: (unsigned __int8 *)&_FPinit) != 0 )
    _fpmath(initPrecision: initFloatingPrecision);
  _initp_misc_cfltcvt_tab();
  result = _initterm_e(pfbegin: __xi_a, pfend: __xi_z);
  if ( result == 0 )
  {
    atexit(func: _RTC_Terminate);
    for ( i = __xc_a; i < __xc_z; ++i )
    {
      if ( *i != nullptr )
        (*i)();
    }
    if ( __dyn_tls_init_callback != nullptr
      && _IsNonwritableInCurrentImage(pTarget: (unsigned __int8 *)&__dyn_tls_init_callback) != 0 )
    {
      __dyn_tls_init_callback(a1: nullptr, a2: 2u, a3: nullptr);
    }
    return 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102F2A71
// Name: doexit
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl doexit(int code, int quick, int retcaller)
{
  PVOID *v3; // ebx
  PVOID *v4; // edi
  void (*v5)(void); // ebx
  void (__cdecl **v6)(); // ebx
  void (__cdecl **v7)(); // eax
  void (__cdecl **onexitbegin)(); // [esp+10h] [ebp-30h]
  void (__cdecl **onexitend_saved)(); // [esp+18h] [ebp-28h]
  void (__cdecl **onexitbegin_saved)(); // [esp+1Ch] [ebp-24h]
  void (**j)(void); // [esp+20h] [ebp-20h]
  void (**i)(void); // [esp+24h] [ebp-1Ch]

  _lock(locknum: 8);
  if ( _C_Exit_Done != 1 )
  {
    _C_Termination_Done = 1;
    _exitflag = retcaller;
    if ( quick == 0 )
    {
      v3 = (PVOID *)DecodePointer(Ptr: __onexitbegin);
      onexitbegin = (void (__cdecl **)())v3;
      if ( v3 != nullptr )
      {
        v4 = (PVOID *)DecodePointer(Ptr: __onexitend);
        onexitbegin_saved = (void (__cdecl **)())v3;
        onexitend_saved = (void (__cdecl **)())v4;
        while ( --v4 >= v3 )
        {
          if ( *v4 != _encoded_null() )
          {
            if ( v4 < v3 )
              break;
            v5 = (void (*)(void))DecodePointer(Ptr: *v4);
            *v4 = _encoded_null();
            v5();
            v6 = (void (__cdecl **)())DecodePointer(Ptr: __onexitbegin);
            v7 = (void (__cdecl **)())DecodePointer(Ptr: __onexitend);
            if ( onexitbegin_saved != v6 || onexitend_saved != v7 )
            {
              onexitbegin_saved = v6;
              onexitbegin = v6;
              onexitend_saved = v7;
              v4 = (PVOID *)v7;
            }
            v3 = (PVOID *)onexitbegin;
          }
        }
      }
      for ( i = __xp_a; i < __xp_z; ++i )
      {
        if ( *i != nullptr )
          (*i)();
      }
    }
    for ( j = __xt_a; j < __xt_z; ++j )
    {
      if ( *j != nullptr )
        (*j)();
    }
  }
  if ( retcaller != 0 )
    _unlock(locknum: 8);
  if ( retcaller == 0 )
  {
    _C_Exit_Done = 1;
    _unlock(locknum: 8);
    __crtExitProcess(status: code);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102F2BB1
// Name: _exit
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl __noreturn exit(int code)
{
  doexit(code, quick: 0, retcaller: 0);
}

//------------------------------------------------------------------------------
// Address: 0x102F2BC7
// Name: __exit
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl __noreturn _exit(int code)
{
  doexit(code, quick: 1, retcaller: 0);
}

//------------------------------------------------------------------------------
// Address: 0x102F2BDD
// Name: __cexit
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _cexit()
{
  doexit(code: 0, quick: 0, retcaller: 1);
}

//------------------------------------------------------------------------------
// Address: 0x102F2BEC
// Name: __amsg_exit
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x102F2C0C
// Name: ___libm_sse2_atan2
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl __libm_sse2_atan2()
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x102F3122
// Name: ___libm_sse2_cos
// Source: linker_block_proximity
//------------------------------------------------------------------------------
double __usercall __libm_sse2_cos@<st0>(__m128i a1@<xmm0>)
{
  double result; // st7

  if ( (__int16)((_mm_extract_epi16(a1, 3) & 0x7FFF) - 12336) > 4293 && (_mm_extract_epi16(a1, 3) & 0x7FF0) != 0x7FF0 )
    return cos(X: *(double *)a1.m128i_i64);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102F32CD
// Name: ___libm_sse2_asin
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl __libm_sse2_asin()
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x102F3716
// Name: ___libm_sse2_tan
// Source: linker_block_proximity
//------------------------------------------------------------------------------
double __usercall __libm_sse2_tan@<st0>(__m128i a1@<xmm0>)
{
  double result; // st7

  if ( (__int16)((_mm_extract_epi16(a1, 3) & 0x7FFF) - 14368) > 2216
    && COERCE_DOUBLE(*(_QWORD *)sign_mask & a1.m128i_i64[0] ^ a1.m128i_i64[0]) != *(double *)INF_1 )
  {
    return tan(X: *(double *)a1.m128i_i64);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102F396B
// Name: __freea
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _freea(_DWORD *_Memory)
{
  if ( _Memory != nullptr && *(_Memory - 2) == 56797 )
    free(pMem: _Memory - 2);
}

//------------------------------------------------------------------------------
// Address: 0x102F3990
// Name: _strncat
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char *__cdecl strncat(char *Destination, const char *Source, size_t Count)
{
  size_t v3; // ecx
  char *v4; // edi
  char v5; // al
  int v6; // eax
  int v7; // eax
  char *v8; // edi
  const char *v9; // esi
  char v10; // bl
  size_t v11; // ecx
  int v12; // edx
  char v13; // dl
  int v15; // eax

  v3 = Count;
  if ( Count == 0 )
    return Destination;
  v4 = Destination;
  if ( ((unsigned __int8)Destination & 3) == 0 )
    goto find_end_of_front_string_loop;
  do
  {
    v5 = *v4++;
    if ( v5 == 0 )
    {
start_byte_3:
      v8 = v4 - 1;
      goto copy_start;
    }
  }
  while ( ((unsigned __int8)v4 & 3) != 0 );
  while ( 1 )
  {
    do
    {
find_end_of_front_string_loop:
      v6 = (*(_DWORD *)v4 + 2130640639) ^ ~*(_DWORD *)v4;
      v4 += 4;
    }
    while ( (v6 & 0x81010100) == 0 );
    v7 = *((_DWORD *)v4 - 1);
    if ( (_BYTE)v7 == 0 )
      break;
    if ( BYTE1(v7) == 0 )
    {
      v8 = v4 - 3;
      goto copy_start;
    }
    if ( (v7 & 0xFF0000) == 0 )
    {
      v8 = v4 - 2;
      goto copy_start;
    }
    if ( (v7 & 0xFF000000) == 0 )
      goto start_byte_3;
  }
  v8 = v4 - 4;
copy_start:
  v9 = Source;
  if ( ((unsigned __int8)Source & 3) == 0 )
  {
    v10 = Count;
    v11 = Count >> 2;
    if ( Count >> 2 != 0 )
      goto main_loop_entrance_0;
tail_loop_start_0:
    v3 = v10 & 3;
    if ( (v10 & 3) != 0 )
    {
      while ( 1 )
      {
        v13 = *v9++;
        *v8++ = v13;
        if ( v13 == 0 )
          break;
        if ( --v3 == 0 )
          goto empty_counter;
      }
    }
    else
    {
empty_counter:
      *v8 = v3;
    }
    return Destination;
  }
  do
  {
    LOBYTE(v12) = *v9++;
    if ( (_BYTE)v12 == 0 )
    {
LABEL_26:
      *v8 = v12;
      return Destination;
    }
    *v8++ = v12;
    if ( --v3 == 0 )
      goto empty_counter;
  }
  while ( ((unsigned __int8)v9 & 3) != 0 );
  v10 = v3;
  v11 = v3 >> 2;
  if ( v11 == 0 )
    goto tail_loop_start_0;
  while ( 1 )
  {
main_loop_entrance_0:
    v15 = (*(_DWORD *)v9 + 2130640639) ^ ~*(_DWORD *)v9;
    v12 = *(_DWORD *)v9;
    v9 += 4;
    if ( (v15 & 0x81010100) != 0 )
    {
      if ( (_BYTE)v12 == 0 )
        goto LABEL_26;
      if ( BYTE1(v12) == 0 )
        break;
      if ( (v12 & 0xFF0000) == 0 )
      {
        *(_WORD *)v8 = v12;
        v8[2] = 0;
        return Destination;
      }
      if ( (v12 & 0xFF000000) == 0 )
      {
        *(_DWORD *)v8 = v12;
        return Destination;
      }
    }
    *(_DWORD *)v8 = v12;
    v8 += 4;
    if ( --v11 == 0 )
      goto tail_loop_start_0;
  }
  *(_WORD *)v8 = (unsigned __int8)v12;
  return Destination;
}

//------------------------------------------------------------------------------
// Address: 0x102F3AC5
// Name: __vsnwprintf_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _vsnwprintf_l(
        unsigned __int16 *string,
        unsigned int count,
        const wchar_t *format,
        localeinfo_struct *plocinfo,
        char *ap)
{
  int result; // eax
  int v6; // edi
  _iobuf str; // [esp+8h] [ebp-20h] BYREF

  memset(&str, 0, sizeof(str));
  if ( format != nullptr && (count == 0 || string != nullptr) )
  {
    str._flag = 66;
    str._base = (char *)string;
    str._ptr = (char *)string;
    if ( count <= 0x3FFFFFFF )
      str._cnt = 2 * count;
    else
      str._cnt = 0x7FFFFFFF;
    result = _woutput_l(stream: &str, format, plocinfo, argptr: ap);
    v6 = result;
    if ( string != nullptr )
    {
      if ( --str._cnt < 0 )
        _flsbuf(ch: 0, (int)&str);
      else
        *str._ptr++ = 0;
      if ( --str._cnt < 0 )
        _flsbuf(ch: 0, (int)&str);
      else
        *str._ptr = 0;
      return v6;
    }
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return -1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102F3B96
// Name: __vsnwprintf
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _vsnwprintf(unsigned __int16 *string, unsigned int count, const wchar_t *format, char *ap)
{
  return _vsnwprintf_l(string, count, format, plocinfo: nullptr, ap);
}

//------------------------------------------------------------------------------
// Address: 0x102F3BB3
// Name: __vswprintf_helper
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _vswprintf_helper(
        int (__cdecl *woutfn)(_iobuf *, const wchar_t *, localeinfo_struct *, char *),
        unsigned __int16 *string,
        unsigned int count,
        const wchar_t *format,
        localeinfo_struct *plocinfo,
        char *ap)
{
  int result; // eax
  bool v7; // sf
  _iobuf str; // [esp+8h] [ebp-20h] BYREF
  int retval; // [esp+3Ch] [ebp+14h]

  memset(&str, 0, sizeof(str));
  if ( format == nullptr || count != 0 && string == nullptr )
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return -1;
  }
  str._flag = 66;
  str._base = (char *)string;
  str._ptr = (char *)string;
  if ( count <= 0x3FFFFFFF )
    str._cnt = 2 * count;
  else
    str._cnt = 0x7FFFFFFF;
  result = woutfn(a1: &str, a2: format, a3: plocinfo, a4: ap);
  retval = result;
  if ( string != nullptr )
  {
    if ( result >= 0 )
    {
      if ( --str._cnt >= 0 )
      {
        *str._ptr++ = 0;
LABEL_13:
        if ( --str._cnt >= 0 )
        {
          *str._ptr = 0;
          return retval;
        }
        if ( _flsbuf(ch: 0, (int)&str) != -1 )
          return retval;
        goto LABEL_17;
      }
      if ( _flsbuf(ch: 0, (int)&str) != -1 )
        goto LABEL_13;
    }
LABEL_17:
    v7 = str._cnt < 0;
    string[count - 1] = 0;
    return !v7 - 2;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102F3CA9
// Name: __vswprintf_c_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _vswprintf_c_l(
        unsigned __int16 *string,
        unsigned int count,
        const wchar_t *format,
        localeinfo_struct *plocinfo,
        char *ap)
{
  int result; // eax

  result = _vswprintf_helper(woutfn: _woutput_l, string, count, format, plocinfo, ap);
  if ( result < 0 )
    return -1;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102F3CD3
// Name: strtoxq
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned __int64 __cdecl strtoxq(
        localeinfo_struct *plocinfo,
        const char *nptr,
        const char **endptr,
        int ibase,
        int flags)
{
  char v6; // cl
  threadlocaleinfostruct *locinfo; // esi
  const char *i; // edi
  int v9; // eax
  char v10; // al
  const unsigned __int16 *pctype; // ebx
  unsigned int v12; // esi
  int v13; // eax
  char v14; // al
  _LocaleUpdate _loc_update; // [esp+4h] [ebp-3Ch] BYREF
  int v16; // [esp+18h] [ebp-28h]
  unsigned __int64 v17; // [esp+1Ch] [ebp-24h]
  unsigned __int64 maxval; // [esp+24h] [ebp-1Ch]
  unsigned __int64 number; // [esp+2Ch] [ebp-14h]
  const char *p; // [esp+38h] [ebp-8h]
  char c; // [esp+3Fh] [ebp-1h]

  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  if ( endptr != nullptr )
    *endptr = nptr;
  if ( nptr == nullptr || ibase != 0 && (ibase < 2 || ibase > 36) )
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return 0;
  }
  v6 = *nptr;
  locinfo = _loc_update.localeinfo.locinfo;
  number = 0;
  c = v6;
  for ( i = nptr + 1; ; ++i )
  {
    if ( locinfo->mb_cur_max <= 1 )
    {
      v9 = locinfo->pctype[(unsigned __int8)c] & 8;
    }
    else
    {
      v9 = _isctype_l((unsigned __int8)c, mask: 8, plocinfo: &_loc_update.localeinfo);
      locinfo = _loc_update.localeinfo.locinfo;
    }
    if ( v9 == 0 )
      break;
    c = *i;
  }
  p = i;
  if ( c == 45 )
  {
    flags |= 2u;
  }
  else if ( c != 43 )
  {
    goto LABEL_20;
  }
  v10 = *i++;
  p = i;
  c = v10;
LABEL_20:
  if ( ibase == 0 )
  {
    if ( c != 48 )
    {
      ibase = 10;
      goto LABEL_32;
    }
    if ( *i != 120 && *i != 88 )
    {
      ibase = 8;
      goto LABEL_32;
    }
    ibase = 16;
  }
  if ( ibase == 16 && c == 48 && (*i == 120 || *i == 88) )
  {
    c = i[1];
    p = i + 2;
  }
LABEL_32:
  v16 = ibase >> 31;
  pctype = locinfo->pctype;
  v17 = 0xFFFFFFFFFFFFFFFFuLL % ibase;
  maxval = 0xFFFFFFFFFFFFFFFFuLL / ibase;
  while ( 1 )
  {
    if ( (pctype[(unsigned __int8)c] & 4) != 0 )
    {
      v12 = c - 48;
    }
    else
    {
      if ( (pctype[(unsigned __int8)c] & 0x103) == 0 )
        break;
      v13 = c;
      if ( (unsigned __int8)(c - 97) <= 0x19u )
        v13 = c - 32;
      v12 = v13 - 55;
    }
    if ( v12 >= ibase )
      break;
    flags |= 8u;
    if ( number < maxval || number == maxval && v12 <= v17 )
    {
      number = v12 + __PAIR64__(v16, ibase) * number;
    }
    else
    {
      flags |= 4u;
      if ( endptr == nullptr )
        break;
    }
    v14 = *p++;
    c = v14;
  }
  --p;
  if ( (flags & 8) != 0 )
  {
    if ( (flags & 4) != 0
      || (flags & 1) == 0
      && ((flags & 2) != 0 && number > 0x8000000000000000uLL
       || (flags & 2) == 0 && (number & 0x8000000000000000uLL) != 0LL) )
    {
      *_errno() = 34;
      if ( (flags & 1) != 0 )
      {
        number = -1;
      }
      else if ( (flags & 2) != 0 )
      {
        number = 0x8000000000000000uLL;
      }
      else
      {
        number = 0x7FFFFFFFFFFFFFFFLL;
      }
    }
  }
  else
  {
    if ( endptr != nullptr )
      p = nptr;
    number = 0;
  }
  if ( endptr != nullptr )
    *endptr = p;
  if ( (flags & 2) != 0 )
    number = -(__int64)number;
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return number;
}

//------------------------------------------------------------------------------
// Address: 0x102F3F70
// Name: __strtoi64
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned __int64 __cdecl _strtoi64(const char *nptr, char **endptr, int ibase)
{
  if ( __locale_changed != 0 )
    return strtoxq(plocinfo: nullptr, nptr, (const char **)endptr, ibase, flags: 0);
  else
    return strtoxq(plocinfo: &__initiallocalestructinfo, nptr, (const char **)endptr, ibase, flags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x102F3F9B
// Name: __wtol
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _wtol(const wchar_t *nptr)
{
  return wcstol(nptr, endptr: nullptr, ibase: 10);
}

//------------------------------------------------------------------------------
// Address: 0x102F3FB1
// Name: __wtoi
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _wtoi(const wchar_t *nptr)
{
  return _wtol(nptr);
}

//------------------------------------------------------------------------------
// Address: 0x102F3FBC
// Name: vscan_fn
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall vscan_fn@<eax>(
        wchar_t *string@<esi>,
        int (__cdecl *inputfn)(_iobuf *, const wchar_t *, localeinfo_struct *, char *),
        const wchar_t *format,
        localeinfo_struct *plocinfo,
        char *arglist)
{
  unsigned int v6; // eax
  _iobuf str; // [esp+4h] [ebp-20h] BYREF

  memset(&str, 0, sizeof(str));
  if ( string != nullptr && format != nullptr )
  {
    v6 = wcslen(wcs: string);
    str._flag = 73;
    str._base = (char *)string;
    str._ptr = (char *)string;
    if ( v6 <= 0x3FFFFFFF )
      str._cnt = 2 * v6;
    else
      str._cnt = 0x7FFFFFFF;
    return inputfn(a1: &str, a2: format, a3: plocinfo, a4: arglist);
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102F4030
// Name: _swscanf
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int swscanf(wchar_t *string, const wchar_t *format, ...)
{
  va_list arglist; // [esp+14h] [ebp+10h] BYREF

  va_start(arglist, format);
  return vscan_fn(string, inputfn: _winput_l, format, plocinfo: nullptr, arglist);
}

//------------------------------------------------------------------------------
// Address: 0x102F4052
// Name: __wtof_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
long double __cdecl _wtof_l(wchar_t *nptr, localeinfo_struct *plocinfo)
{
  unsigned __int16 *v2; // esi
  long double result; // st7
  _LocaleUpdate _loc_update; // [esp+4h] [ebp-2Ch] BYREF
  _flt fltstruct; // [esp+14h] [ebp-1Ch] BYREF

  v2 = nptr;
  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  if ( nptr != nullptr )
  {
    while ( iswctype(c: *v2, mask: 8u) != 0 )
      ++v2;
    result = _wfltin2(flt: &fltstruct, str: v2, _Locale: &_loc_update.localeinfo)->dval;
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return 0.0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102F40DA
// Name: __wtof
// Source: linker_block_proximity
//------------------------------------------------------------------------------
long double __cdecl _wtof(wchar_t *nptr)
{
  return _wtof_l(nptr, plocinfo: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x102F40ED
// Name: _wcsncat
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned __int16 *__cdecl wcsncat(unsigned __int16 *front, const wchar_t *back, unsigned int count)
{
  unsigned __int16 *v3; // edx
  unsigned __int16 *result; // eax
  __int16 v5; // cx
  unsigned __int16 *v6; // edx
  __int16 v8; // cx

  v3 = front;
  result = front;
  do
    v5 = *v3++;
  while ( v5 != 0 );
  v6 = v3 - 1;
  if ( count != 0 )
  {
    while ( 1 )
    {
      v8 = *back;
      --count;
      *v6++ = *back++;
      if ( v8 == 0 )
        break;
      if ( count == 0 )
        goto LABEL_6;
    }
  }
  else
  {
LABEL_6:
    *v6 = 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102F4140
// Name: _strpbrk
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl strpbrk(unsigned __int8 *string, unsigned __int8 *control)
{
  unsigned int v2; // eax
  signed __int32 v5[8]; // [esp-20h] [ebp-24h] BYREF

  v2 = 0;
  memset(v5, 0, sizeof(v5));
  while ( 1 )
  {
    LOBYTE(v2) = *control;
    if ( *control == 0 )
      break;
    ++control;
    _bittestandset(v5, v2);
  }
  do
  {
    LOBYTE(v2) = *string;
    if ( *string == 0 )
      break;
    ++string;
  }
  while ( !_bittest(v5, v2) );
}

//------------------------------------------------------------------------------
// Address: 0x102F4180
// Name: __strnicmp_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _strnicmp_l(char *dst, char *src, unsigned int count, localeinfo_struct *plocinfo)
{
  char *v4; // esi
  unsigned int v5; // edi
  unsigned int v6; // eax
  _LocaleUpdate _loc_update; // [esp+Ch] [ebp-10h] BYREF

  if ( count != 0 )
  {
    _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
    if ( dst != nullptr && (v4 = src, src != nullptr) )
    {
      if ( count <= 0x7FFFFFFF )
      {
        if ( _loc_update.localeinfo.locinfo->lc_handle[2] != 0 )
        {
          do
          {
            v5 = _tolower_l(c: (unsigned __int8)v4[dst - src], plocinfo: &_loc_update.localeinfo);
            v6 = _tolower_l(c: (unsigned __int8)*v4++, plocinfo: &_loc_update.localeinfo);
            --count;
          }
          while ( count != 0 && v5 != 0 && v5 == v6 );
        }
        else
        {
          __ascii_strnicmp(first: (unsigned __int8 *)dst, last: (unsigned __int8 *)src, count);
        }
        if ( _loc_update.updated )
          _loc_update.ptd->_ownlocale &= ~2u;
      }
      else
      {
        *_errno() = 22;
        _invalid_parameter_noinfo();
        if ( _loc_update.updated )
          _loc_update.ptd->_ownlocale &= ~2u;
      }
    }
    else
    {
      *_errno() = 22;
      _invalid_parameter_noinfo();
      if ( _loc_update.updated )
        _loc_update.ptd->_ownlocale &= ~2u;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102F4262
// Name: __strnicmp
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _strnicmp(char *dst, char *src, unsigned int count)
{
  if ( __locale_changed != 0 )
  {
    _strnicmp_l(dst, src, count, plocinfo: nullptr);
  }
  else if ( dst != nullptr && src != nullptr && count <= 0x7FFFFFFF )
  {
    __ascii_strnicmp(first: (unsigned __int8 *)dst, last: (unsigned __int8 *)src, count);
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
  }
}

//------------------------------------------------------------------------------
// Address: 0x102F42B5
// Name: __towlower_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _towlower_l(unsigned __int16 c, localeinfo_struct *plocinfo)
{
  int result; // eax
  threadlocaleinfostruct *locinfo; // esi
  unsigned int v4; // ecx
  bool v5; // zf
  _LocaleUpdate _loc_update; // [esp+0h] [ebp-14h] BYREF
  unsigned __int16 widechar; // [esp+10h] [ebp-4h] BYREF

  result = 0xFFFF;
  if ( c != 0xFFFF )
  {
    _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
    locinfo = _loc_update.localeinfo.locinfo;
    v4 = _loc_update.localeinfo.locinfo->lc_handle[2];
    if ( v4 != 0 )
    {
      if ( c >= 0x100u )
      {
        v5 = __crtLCMapStringW(
               Locale: v4,
               dwMapFlags: 0x100u,
               lpSrcStr: &c,
               cchSrc: 1,
               lpDestStr: &widechar,
               cchDest: 1) == 0;
        result = c;
        if ( !v5 )
          result = widechar;
      }
      else
      {
        v5 = iswctype(c, mask: 1u) == 0;
        result = c;
        if ( !v5 )
          result = locinfo->pclmap[c];
      }
    }
    else
    {
      LOWORD(result) = c;
      if ( (unsigned __int16)(c - 65) <= 0x19u )
        LOWORD(result) = c + 32;
      result = (unsigned __int16)result;
    }
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102F4355
// Name: _towlower
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl towlower(unsigned __int16 c)
{
  return _towlower_l(c, plocinfo: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x102F4368
// Name: _copytlocinfo_nolock
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall copytlocinfo_nolock(threadlocaleinfostruct *ptlocid@<eax>, threadlocaleinfostruct *ptlocis@<ecx>)
{
  if ( ptlocis != nullptr && ptlocid != nullptr && ptlocid != ptlocis )
  {
    *ptlocid = *ptlocis;
    ptlocid->refcount = 0;
    __addlocaleref(ptloci: ptlocid);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102F438E
// Name: ___init_collate
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl __init_collate()
{
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x102F4391
// Name: __strcats
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void _strcats(char *outstr, unsigned int sizeInBytes, int n, ...)
{
  int v3; // edi
  const char **p_n; // esi

  v3 = 0;
  if ( n > 0 )
  {
    p_n = (const char **)&n;
    do
    {
      if ( strcat_s(_Dst: outstr, _SizeInBytes: sizeInBytes, _Src: *++p_n) != 0 )
        _invoke_watson();
      ++v3;
    }
    while ( v3 < n );
  }
}

//------------------------------------------------------------------------------
// Address: 0x102F43D2
// Name: ___lc_strtolc
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl __lc_strtolc(tagLC_STRINGS *names, char *locale)
{
  const char *v2; // esi
  unsigned int v4; // eax
  bool j; // zf
  const char *v6; // edi
  char v7; // bl
  int v8; // eax
  int i; // [esp+18h] [ebp+Ch]

  memset(dst: (unsigned __int8 *)names, value: 0, count: sizeof(tagLC_STRINGS));
  v2 = locale;
  if ( *locale == 0 )
    return 0;
  if ( *locale == 46 && locale[1] != 0 )
  {
    if ( strncpy_s(_Dst: names->szCodePage, _SizeInBytes: 0x10u, _Src: locale + 1, _Count: 0xFu) != 0 )
LABEL_7:
      _invoke_watson();
    names->szCodePage[15] = 0;
    return 0;
  }
  i = 0;
  strcspn(string: (unsigned __int8 *)locale, control: "_.,");
  for ( j = v4 == 0; !j; j = v4 == 0 )
  {
    v6 = &v2[v4];
    v7 = v2[v4];
    if ( i != 0 )
    {
      if ( i == 1 )
      {
        if ( v4 >= 0x40 || v7 == 95 )
          return -1;
        v8 = strncpy_s(_Dst: names->szCountry, _SizeInBytes: 0x40u, _Src: v2, _Count: v4);
      }
      else
      {
        if ( i != 2 || v4 >= 0x10 || v7 != 0 && v7 != 44 )
          return -1;
        v8 = strncpy_s(_Dst: names->szCodePage, _SizeInBytes: 0x10u, _Src: v2, _Count: v4);
      }
    }
    else
    {
      if ( v4 >= 0x40 || v7 == 46 )
        return -1;
      v8 = strncpy_s(_Dst: names->szLanguage, _SizeInBytes: 0x40u, _Src: v2, _Count: v4);
    }
    if ( v8 != 0 )
      goto LABEL_7;
    if ( v7 == 44 || v7 == 0 )
      return 0;
    ++i;
    v2 = v6 + 1;
    strcspn(string: (unsigned __int8 *)v6 + 1, control: "_.,");
  }
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x102F44F1
// Name: ___lc_lctostr
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl __lc_lctostr(char *locale, unsigned int sizeInBytes, const tagLC_STRINGS *names)
{
  if ( strcpy_s(_Dst: locale, _SizeInBytes: sizeInBytes, _Src: names->szLanguage) != 0 )
    _invoke_watson();
  if ( names->szCountry[0] != 0 )
    _strcats(outstr: locale, sizeInBytes, n: 2, "_", names->szCountry);
  if ( names->szCodePage[0] != 0 )
    _strcats(outstr: locale, sizeInBytes, n: 2, ".", names->szCodePage);
}

//------------------------------------------------------------------------------
// Address: 0x102F455C
// Name: _setlocale_get_all
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char *__usercall setlocale_get_all@<eax>(threadlocaleinfostruct *ploci@<esi>)
{
  char *result; // eax
  char *v2; // edi
  unsigned __int8 **v3; // eax
  int v4; // eax
  unsigned __int8 *locale; // [esp-8h] [ebp-1Ch]
  int *refcount; // [esp+4h] [ebp-10h]
  int same; // [esp+8h] [ebp-Ch]
  threadlocaleinfostruct::<unnamed_type_lc_category> *v8; // [esp+Ch] [ebp-8h]
  const $FAA2ED44176E8AD2BA02CFC02FF7315D *v9; // [esp+10h] [ebp-4h]

  same = 1;
  result = (char *)MemAlloc_Alloc(nSize: 0x355u);
  refcount = (int *)result;
  if ( result != nullptr )
  {
    v2 = result + 4;
    result[4] = 0;
    *(_DWORD *)result = 1;
    _strcats(outstr: result + 4, sizeInBytes: 0x351u, n: 3, "LC_COLLATE", "=", ploci->lc_category[1].locale);
    v9 = &__lc_category[1];
    v8 = &ploci->lc_category[1];
    do
    {
      if ( strcat_s(_Dst: v2, _SizeInBytes: 0x351u, _Src: ";") != 0 )
        _invoke_watson();
      v3 = (unsigned __int8 **)v8;
      locale = (unsigned __int8 *)v8[1].locale;
      ++v8;
      strcmp(str1: *v3, str2: locale);
      if ( v4 != 0 )
        same = 0;
      ++v9;
      _strcats(outstr: v2, sizeInBytes: 0x351u, n: 3, v9->catname, "=", v8->locale);
    }
    while ( (int)v9 < (int)&__lc_category[5] );
    if ( same != 0 )
    {
      free(pMem: refcount);
      if ( ploci->lc_category[0].refcount != nullptr
        && InterlockedDecrement(lpAddend: ploci->lc_category[0].refcount) == 0 )
      {
        free(pMem: ploci->lc_category[0].refcount);
      }
      if ( ploci->lc_category[0].wrefcount != nullptr
        && InterlockedDecrement(lpAddend: ploci->lc_category[0].wrefcount) == 0 )
      {
        free(pMem: ploci->lc_category[0].wrefcount);
      }
      result = ploci->lc_category[2].locale;
      ploci->lc_category[0].wrefcount = nullptr;
      ploci->lc_category[0].wlocale = nullptr;
      ploci->lc_category[0].refcount = nullptr;
      ploci->lc_category[0].locale = nullptr;
    }
    else
    {
      if ( ploci->lc_category[0].refcount != nullptr
        && InterlockedDecrement(lpAddend: ploci->lc_category[0].refcount) == 0 )
      {
        free(pMem: ploci->lc_category[0].refcount);
      }
      if ( ploci->lc_category[0].wrefcount != nullptr
        && InterlockedDecrement(lpAddend: ploci->lc_category[0].wrefcount) == 0 )
      {
        free(pMem: ploci->lc_category[0].wrefcount);
      }
      ploci->lc_category[0].wrefcount = nullptr;
      ploci->lc_category[0].wlocale = nullptr;
      ploci->lc_category[0].refcount = refcount;
      ploci->lc_category[0].locale = v2;
      return v2;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102F46C1
// Name: __expandlocale
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char *__cdecl _expandlocale(char *expr, char *output, unsigned int sizeInChars, tagLC_ID *id, unsigned int *cp)
{
  const char *v5; // esi
  _tiddata *v6; // eax
  tagLC_ID *p_cacheid; // ebx
  unsigned int v9; // eax
  int v10; // eax
  int v11; // eax
  unsigned int v12; // eax
  unsigned int charactersInExpression; // [esp+10h] [ebp-B0h]
  unsigned int *pcachecp; // [esp+14h] [ebp-ACh]
  unsigned __int8 *cachein; // [esp+18h] [ebp-A8h]
  unsigned __int8 *cacheout; // [esp+28h] [ebp-98h]
  tagLC_STRINGS names; // [esp+2Ch] [ebp-94h] BYREF

  v5 = expr;
  v6 = _getptd();
  pcachecp = &v6->_setloc_data._cachecp;
  p_cacheid = &v6->_setloc_data._cacheid;
  cachein = (unsigned __int8 *)v6->_setloc_data._cachein;
  cacheout = (unsigned __int8 *)v6->_setloc_data._cacheout;
  if ( expr == nullptr || output == nullptr || sizeInChars == 0 )
    return nullptr;
  if ( *expr != 67 || expr[1] != 0 )
  {
    strlen(buf: expr);
    charactersInExpression = v9;
    if ( v9 < 0x83 )
    {
      strcmp(str1: cacheout, str2: (unsigned __int8 *)expr);
      if ( v10 == 0 || (strcmp(str1: cachein, str2: (unsigned __int8 *)expr), v11 == 0) )
      {
LABEL_22:
        if ( id != nullptr )
          *id = *p_cacheid;
        if ( cp != nullptr )
          *cp = *pcachecp;
        if ( strcpy_s(_Dst: output, _SizeInBytes: sizeInChars, _Src: (const char *)cacheout) == 0 )
          return (char *)cacheout;
LABEL_12:
        _invoke_watson();
      }
    }
    if ( __lc_strtolc(&names, locale: expr) == 0
      && __get_qualified_locale(lpInStr: &names, lpOutId: p_cacheid, lpOutStr: &names) != 0 )
    {
      *pcachecp = p_cacheid->wCodePage;
      __lc_lctostr(locale: (char *)cacheout, sizeInBytes: 0x83u, &names);
      if ( *expr == 0 || (v12 = charactersInExpression, charactersInExpression >= 0x83) )
      {
        v12 = 0;
        v5 = defaultValue;
      }
      if ( strncpy_s(_Dst: (char *)cachein, _SizeInBytes: 0x83u, _Src: v5, _Count: v12 + 1) != 0 )
        goto LABEL_12;
      goto LABEL_22;
    }
    return nullptr;
  }
  if ( strcpy_s(_Dst: output, _SizeInBytes: sizeInChars, _Src: "C") != 0 )
    goto LABEL_12;
  if ( id != nullptr )
  {
    id->wLanguage = 0;
    id->wCountry = 0;
    id->wCodePage = 0;
  }
  if ( cp != nullptr )
    *cp = 0;
  return output;
}

//------------------------------------------------------------------------------
// Address: 0x102F48E2
// Name: _setlocale_set_cat
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char *__usercall setlocale_set_cat@<eax>(threadlocaleinfostruct *ploci@<esi>, int category@<ecx>, char *locale)
{
  _tiddata *v4; // edi
  char *v6; // ebx
  int v7; // eax
  int v8; // eax
  unsigned int *v9; // ecx
  unsigned int id; // ecx
  _is_ctype_compatible *Lcid_c; // eax
  unsigned int v12; // edx
  int is_clike; // edx
  _is_ctype_compatible *v14; // eax
  unsigned int j; // eax
  int v16; // edi
  char *v17; // eax
  int v18; // ecx
  char *v19; // [esp-4h] [ebp-1D4h]
  unsigned int buf2; // [esp+10h] [ebp-1C0h]
  unsigned int oldhandle; // [esp+18h] [ebp-1B8h]
  unsigned int oldcodepage; // [esp+1Ch] [ebp-1B4h]
  tagLC_ID idtemp; // [esp+20h] [ebp-1B0h] BYREF
  unsigned int *v24; // [esp+28h] [ebp-1A8h]
  unsigned int cptemp; // [esp+2Ch] [ebp-1A4h] BYREF
  _is_ctype_compatible buf1; // [esp+30h] [ebp-1A0h]
  char *oldlocale; // [esp+38h] [ebp-198h]
  char *pch; // [esp+3Ch] [ebp-194h]
  int v29; // [esp+40h] [ebp-190h]
  int i; // [esp+44h] [ebp-18Ch]
  unsigned __int16 out[128]; // [esp+48h] [ebp-188h] BYREF
  char lctemp[132]; // [esp+148h] [ebp-88h] BYREF

  v29 = category;
  oldlocale = locale;
  v4 = _getptd();
  if ( _expandlocale(expr: locale, output: lctemp, sizeInChars: 0x83u, id: &idtemp, cp: &cptemp) == nullptr )
    return nullptr;
  v6 = (char *)ploci + 16 * category;
  strcmp(str1: (unsigned __int8 *)lctemp, str2: *((unsigned __int8 **)v6 + 18));
  if ( v7 != 0 )
  {
    strlen(buf: lctemp);
    i = v8 + 5;
    pch = (char *)MemAlloc_Alloc(nSize: v8 + 5);
    if ( pch != nullptr )
    {
      oldlocale = *((char **)v6 + 18);
      v24 = &ploci->lc_handle[v29];
      oldhandle = *v24;
      buf1.is_clike = (int)&ploci->lc_id[v29];
      oldcodepage = ploci->lc_codepage;
      if ( strcpy_s(_Dst: pch + 4, _SizeInBytes: i - 4, _Src: lctemp) != 0 )
        _invoke_watson();
      v9 = v24;
      *((_DWORD *)v6 + 18) = pch + 4;
      *v9 = idtemp.wLanguage;
      *(tagLC_ID *)buf1.is_clike = idtemp;
      if ( v29 == 2 )
      {
        i = 0;
        ploci->lc_codepage = cptemp;
        id = v4->_setloc_data._Lcid_c[4].id;
        buf1.is_clike = v4->_setloc_data._Lcid_c[4].is_clike;
        Lcid_c = v4->_setloc_data._Lcid_c;
        while ( ploci->lc_codepage != Lcid_c->id )
        {
          v12 = Lcid_c->id;
          ++i;
          Lcid_c->id = id;
          buf2 = v12;
          is_clike = Lcid_c->is_clike;
          Lcid_c->is_clike = buf1.is_clike;
          id = buf2;
          ++Lcid_c;
          buf1.is_clike = is_clike;
          if ( i >= 5 )
            goto LABEL_14;
        }
        if ( i != 0 )
        {
          v14 = &v4->_setloc_data._Lcid_c[i];
          v4->_setloc_data._Lcid_c[0].id = v14->id;
          v4->_setloc_data._Lcid_c[0].is_clike = v14->is_clike;
          v14->id = id;
          v14->is_clike = buf1.is_clike;
        }
LABEL_14:
        if ( i == 5 )
        {
          if ( __crtGetStringTypeA(
                 plocinfo: nullptr,
                 dwInfoType: 1u,
                 lpSrcStr: first_127char,
                 cchSrc: 127,
                 lpCharType: out,
                 code_page: ploci->lc_codepage,
                 lcid: ploci->lc_handle[2],
                 bError: 1) != 0 )
          {
            for ( j = 0; j < 0x7F; ++j )
              out[j] &= 0x1FFu;
            v4->_setloc_data._Lcid_c[0].is_clike = memcmp(lhs: out, rhs: ctype_loc_style, siz: 0xFEu) == 0;
          }
          else
          {
            v4->_setloc_data._Lcid_c[0].is_clike = 0;
          }
          v4->_setloc_data._Lcid_c[0].id = ploci->lc_codepage;
        }
        ploci->lc_clike = v4->_setloc_data._Lcid_c[0].is_clike;
      }
      if ( v29 == 1 )
        ploci->lc_collate_cp = cptemp;
      if ( ((int (__cdecl *)())__lc_category[v29].init)() == 0 )
      {
        if ( oldlocale != __clocalestr )
        {
          v16 = 2 * (v29 + 5);
          if ( InterlockedDecrement(lpAddend: ploci->lc_category[v29].refcount) == 0 )
          {
            free(pMem: *((void **)&ploci->refcount + 2 * v16));
            free(pMem: *((void **)v6 + 21));
            *((_DWORD *)v6 + 19) = 0;
          }
        }
        v17 = pch;
        v18 = 2 * (v29 + 5);
        *(_DWORD *)pch = 1;
        *(&ploci->refcount + 2 * v18) = (int)v17;
        return *((char **)v6 + 18);
      }
      v19 = pch;
      *((_DWORD *)v6 + 18) = oldlocale;
      free(pMem: v19);
      *v24 = oldhandle;
      ploci->lc_codepage = oldcodepage;
    }
    return nullptr;
  }
  return *((char **)v6 + 18);
}

//------------------------------------------------------------------------------
// Address: 0x102F4C1C
// Name: _setlocale_nolock
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char *__fastcall setlocale_nolock(int _category, threadlocaleinfostruct *ploci, char *_locale)
{
  int v3; // ebx
  threadlocaleinfostruct *v4; // esi
  char *result; // eax
  unsigned __int8 *v6; // edi
  _BYTE *v7; // eax
  _BYTE *v8; // ebx
  unsigned int v9; // eax
  const $FAA2ED44176E8AD2BA02CFC02FF7315D *v10; // esi
  int v11; // eax
  unsigned __int8 *v12; // ebx
  unsigned int v13; // eax
  unsigned int v14; // edi
  unsigned __int8 *v15; // edi
  unsigned __int8 **lc_category; // edi
  int v17; // eax
  int i; // [esp+10h] [ebp-94h]
  unsigned int len; // [esp+14h] [ebp-90h]
  unsigned int lena; // [esp+14h] [ebp-90h]
  int fLocaleSet; // [esp+18h] [ebp-8Ch]
  char lctemp[132]; // [esp+1Ch] [ebp-88h] BYREF

  v3 = 0;
  v4 = ploci;
  if ( _category != 0 )
  {
    if ( _locale != nullptr )
      return setlocale_set_cat(ploci, category: _category, locale: _locale);
    else
      return ploci->lc_category[_category].locale;
  }
  len = 1;
  fLocaleSet = 0;
  if ( _locale == nullptr )
    return setlocale_get_all(ploci: v4);
  if ( *_locale == 76 && _locale[1] == 67 && _locale[2] == 95 )
  {
    v6 = (unsigned __int8 *)_locale;
    do
    {
      strpbrk(string: v6, control: "=;");
      v8 = v7;
      if ( v7 == nullptr )
        return nullptr;
      v9 = v7 - v6;
      lena = v9;
      if ( v9 == 0 || *v8 == 59 )
        return nullptr;
      i = 1;
      v10 = &__lc_category[1];
      while ( 1 )
      {
        if ( strncmp(first: v10->catname, last: (const char *)v6, count: v9) == 0 )
        {
          strlen(buf: (char *)v10->catname);
          if ( lena == v11 )
            break;
        }
        ++i;
        if ( (int)++v10 > (int)&__lc_category[5] )
          break;
        v9 = lena;
      }
      v12 = v8 + 1;
      strcspn(string: v12, control: ";");
      v14 = v13;
      if ( v13 == 0 && *v12 != 59 )
        return nullptr;
      if ( i <= 5 )
      {
        if ( strncpy_s(_Dst: lctemp, _SizeInBytes: 0x83u, _Src: (const char *)v12, _Count: v13) != 0 )
          _invoke_watson();
        lctemp[v14] = 0;
        if ( setlocale_set_cat(ploci, category: i, locale: lctemp) != nullptr )
          ++fLocaleSet;
      }
      v15 = &v12[v14];
      if ( *v15 == 0 )
        break;
      v6 = v15 + 1;
    }
    while ( *v6 != 0 );
    result = nullptr;
    if ( fLocaleSet == 0 )
      return result;
    v4 = ploci;
    return setlocale_get_all(ploci: v4);
  }
  result = _expandlocale(expr: _locale, output: lctemp, sizeInChars: 0x83u, id: nullptr, cp: nullptr);
  if ( result != nullptr )
  {
    lc_category = (unsigned __int8 **)v4->lc_category;
    do
    {
      if ( v3 != 0 )
      {
        strcmp(str1: (unsigned __int8 *)lctemp, str2: *lc_category);
        if ( v17 == 0 || setlocale_set_cat(ploci: v4, category: v3, locale: lctemp) != nullptr )
          ++fLocaleSet;
        else
          len = 0;
      }
      ++v3;
      lc_category += 4;
    }
    while ( v3 <= 5 );
    result = nullptr;
    if ( len != 0 || fLocaleSet != 0 )
      return setlocale_get_all(ploci: v4);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102F4E38
// Name: _setlocale
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char *__cdecl setlocale(unsigned int _category, char *_locale)
{
  _tiddata *v3; // esi
  threadlocaleinfostruct *v4; // ebx
  int v5; // eax
  char *retval; // [esp+14h] [ebp-20h]

  retval = nullptr;
  if ( _category <= 5 )
  {
    v3 = _getptd();
    __updatetlocinfo();
    v3->_ownlocale |= 0x10u;
    v4 = (threadlocaleinfostruct *)calloc(count: 0xD8u, size: 1u);
    if ( v4 != nullptr )
    {
      _lock(locknum: 12);
      copytlocinfo_nolock(ptlocid: v4, ptlocis: v3->ptlocinfo);
      _unlock(locknum: 12);
      retval = setlocale_nolock(_category, ploci: v4, _locale);
      if ( retval != nullptr )
      {
        if ( _locale != nullptr )
        {
          strcmp(str1: (unsigned __int8 *)_locale, str2: (unsigned __int8 *)__clocalestr);
          if ( v5 != 0 )
            __locale_changed = 1;
        }
        _lock(locknum: 12);
        _updatetlocinfoEx_nolock(pptlocid: &v3->ptlocinfo, ptlocis: v4);
        __removelocaleref(ptloci: v4);
        if ( (v3->_ownlocale & 2) == 0 && (__globallocalestatus & 1) == 0 )
        {
          _updatetlocinfoEx_nolock(pptlocid: &__ptlocinfo, ptlocis: v3->ptlocinfo);
          __lconv = __ptlocinfo->lconv;
          _pctype = __ptlocinfo->pctype;
          __mb_cur_max = __ptlocinfo->mb_cur_max;
        }
        _unlock(locknum: 12);
      }
      else
      {
        __removelocaleref(ptloci: v4);
        __freetlocinfo(ptloci: v4);
      }
    }
    v3->_ownlocale &= ~0x10u;
    return retval;
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102F4FAC
// Name: _wcschr
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned __int16 *__cdecl wcschr(const wchar_t *string, wchar_t ch)
{
  unsigned __int16 *result; // eax

  for ( result = (unsigned __int16 *)string; *result != 0; ++result )
  {
    if ( *result == ch )
      return result;
  }
  if ( *result != ch )
    return nullptr;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102F4FD3
// Name: __towupper_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _towupper_l(unsigned __int16 c, localeinfo_struct *plocinfo)
{
  int result; // eax
  threadlocaleinfostruct *locinfo; // esi
  unsigned int v4; // eax
  bool v5; // zf
  _LocaleUpdate _loc_update; // [esp+0h] [ebp-14h] BYREF
  unsigned __int16 widechar; // [esp+10h] [ebp-4h] BYREF

  result = 0xFFFF;
  if ( c != 0xFFFF )
  {
    _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
    locinfo = _loc_update.localeinfo.locinfo;
    v4 = _loc_update.localeinfo.locinfo->lc_handle[2];
    if ( v4 != 0 )
    {
      if ( c >= 0x100u )
      {
        v5 = __crtLCMapStringW(
               Locale: v4,
               dwMapFlags: 0x200u,
               lpSrcStr: &c,
               cchSrc: 1,
               lpDestStr: &widechar,
               cchDest: 1) == 0;
        result = c;
        if ( !v5 )
          result = widechar;
      }
      else
      {
        v5 = iswctype(c, mask: 2u) == 0;
        result = c;
        if ( !v5 )
          result = locinfo->pcumap[c];
      }
    }
    else
    {
      LOWORD(result) = c;
      if ( (unsigned __int16)(c - 97) <= 0x19u )
        LOWORD(result) = c - 32;
      result = (unsigned __int16)result;
    }
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102F5079
// Name: _towupper
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl towupper(unsigned __int16 c)
{
  return _towupper_l(c, plocinfo: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x102F508C
// Name: __forcdecpt_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _forcdecpt_l(char *buffer, localeinfo_struct *_Locale)
{
  char *v2; // esi
  bool i; // zf
  char v4; // al
  char *v5; // esi
  char v6; // cl
  char v7; // cl
  _LocaleUpdate _loc_update; // [esp+4h] [ebp-10h] BYREF

  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo: _Locale);
  v2 = buffer;
  for ( i = tolower(c: *buffer) == 101; !i; i = isdigit(c: (unsigned __int8)*v2) == 0 )
    ++v2;
  if ( tolower(c: *v2) == 120 )
    v2 += 2;
  v4 = *v2;
  *v2 = *_loc_update.localeinfo.locinfo->lconv->decimal_point;
  v5 = v2 + 1;
  do
  {
    v6 = *v5;
    *v5 = v4;
    v4 = v6;
    v7 = *v5++;
  }
  while ( v7 != 0 );
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
}

//------------------------------------------------------------------------------
// Address: 0x102F5100
// Name: __cropzeros_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _cropzeros_l(char *buf, localeinfo_struct *_Locale)
{
  char *v2; // eax
  char i; // cl
  char v4; // cl
  char *v5; // eax
  char v6; // cl
  char *v7; // edx
  char v8; // cl
  _LocaleUpdate _loc_update; // [esp+4h] [ebp-10h] BYREF

  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo: _Locale);
  v2 = buf;
  for ( i = *buf; *v2 != 0; i = *++v2 )
  {
    if ( i == *_loc_update.localeinfo.locinfo->lconv->decimal_point )
      break;
  }
  v4 = *v2;
  v5 = v2 + 1;
  if ( v4 != 0 )
  {
    while ( 1 )
    {
      v6 = *v5;
      if ( *v5 == 0 || v6 == 101 || v6 == 69 )
        break;
      ++v5;
    }
    v7 = v5;
    do
      --v5;
    while ( *v5 == 48 );
    if ( *v5 == *_loc_update.localeinfo.locinfo->lconv->decimal_point )
      --v5;
    do
    {
      v8 = *v7;
      ++v5;
      ++v7;
      *v5 = v8;
    }
    while ( v8 != 0 );
  }
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
}

//------------------------------------------------------------------------------
// Address: 0x102F5182
// Name: __positive
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __cdecl _positive(long double *arg)
{
  return *arg >= 0.0;
}

//------------------------------------------------------------------------------
// Address: 0x102F519E
// Name: __fassign_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _fassign_l(_CRT_FLOAT flag, char *argument, char *number, localeinfo_struct *plocinfo)
{
  _CRT_DOUBLE doubletemp; // [esp+0h] [ebp-8h] BYREF

  if ( LODWORD(flag.f) != 0 )
  {
    _atodbl_l(d: &doubletemp, str: number, plocinfo);
    *(_CRT_DOUBLE *)argument = doubletemp;
  }
  else
  {
    _atoflt_l(d: &flag, str: number, plocinfo);
    *(_CRT_FLOAT *)argument = flag;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102F51E0
// Name: __fassign
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _fassign(int flag, char *argument, char *number)
{
  _fassign_l((_CRT_FLOAT)flag, argument, number, plocinfo: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x102F51FA
// Name: _shift
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall shift(__m128i *s@<eax>, int dist@<edi>)
{
  int v3; // eax

  if ( dist != 0 )
  {
    strlen(buf: s->m128i_i8);
    memmove(dst: (__m128i *)((char *)s + dist), src: s, count: v3 + 1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102F5219
// Name: __forcdecpt
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _forcdecpt(char *buffer)
{
  _forcdecpt_l(buffer, _Locale: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x102F522C
// Name: __cropzeros
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _cropzeros(char *buf)
{
  _cropzeros_l(buf, _Locale: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x102F523F
// Name: _cftoe2_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall cftoe2_l@<eax>(
        char *buf@<eax>,
        unsigned int sizeInBytes,
        int ndec,
        int caps,
        _strflt *pflt,
        char g_fmt,
        localeinfo_struct *plocinfo)
{
  int *v8; // eax
  int v10; // eax
  char *v11; // esi
  threadlocaleinfostruct *locinfo; // eax
  char *v13; // esi
  unsigned int v14; // ebx
  int v15; // eax
  int v16; // [esp-4h] [ebp-1Ch]
  _LocaleUpdate _loc_update; // [esp+8h] [ebp-10h] BYREF

  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  if ( buf == nullptr || sizeInBytes == 0 )
  {
    v8 = _errno();
    v16 = 22;
LABEL_3:
    *v8 = v16;
    _invalid_parameter_noinfo();
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return v16;
  }
  if ( ndec <= 0 )
    v10 = 0;
  else
    v10 = ndec;
  if ( sizeInBytes <= v10 + 9 )
  {
    v8 = _errno();
    v16 = 34;
    goto LABEL_3;
  }
  if ( g_fmt != 0 )
    shift(s: (__m128i *)&buf[pflt->sign == 45], dist: ndec > 0);
  v11 = buf;
  if ( pflt->sign == 45 )
  {
    *buf = 45;
    v11 = buf + 1;
  }
  if ( ndec > 0 )
  {
    locinfo = _loc_update.localeinfo.locinfo;
    *v11 = v11[1];
    *++v11 = *locinfo->lconv->decimal_point;
  }
  v13 = &v11[ndec + (g_fmt == 0)];
  if ( sizeInBytes == -1 )
    v14 = -1;
  else
    v14 = sizeInBytes + buf - v13;
  if ( strcpy_s(_Dst: v13, _SizeInBytes: v14, _Src: "e+000") != 0 )
    _invoke_watson();
  if ( caps != 0 )
    *v13 = 69;
  if ( *pflt->mantissa != 48 )
  {
    v15 = pflt->decpt - 1;
    if ( v15 < 0 )
    {
      v15 = 1 - pflt->decpt;
      v13[1] = 45;
    }
    if ( v15 >= 100 )
    {
      v13[2] += v15 / 100;
      v15 %= 100;
    }
    if ( v15 >= 10 )
    {
      v13[3] += v15 / 10;
      LOBYTE(v15) = v15 % 10;
    }
    v13[4] += v15;
  }
  if ( (_outputformat & 1) != 0 && v13[2] == 48 )
    memmove(dst: (__m128i *)(v13 + 2), src: (const __m128i *)(v13 + 3), count: 3u);
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x102F53A0
// Name: __cftoe_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _cftoe_l(
        _CRT_DOUBLE *pvalue,
        char *buf,
        unsigned int sizeInBytes,
        int ndec,
        int caps,
        localeinfo_struct *plocinfo)
{
  int result; // eax
  unsigned int v7; // eax
  _strflt retstrflt; // [esp+Ch] [ebp-2Ch] BYREF
  char resstr[24]; // [esp+1Ch] [ebp-1Ch] BYREF

  _fltout2(x: *(_CRT_DOUBLE *)&pvalue->x, flt: &retstrflt, resultstr: resstr, resultsize: 0x16u);
  if ( buf != nullptr && (v7 = sizeInBytes, sizeInBytes != 0) )
  {
    if ( sizeInBytes != -1 )
      v7 = sizeInBytes - (retstrflt.sign == 45) - (ndec > 0);
    result = _fptostr(
               buf: &buf[(retstrflt.sign == 45) + (ndec > 0)],
               sizeInBytes: v7,
               digits: ndec + 1,
               pflt: &retstrflt);
    if ( result != 0 )
      *buf = 0;
    else
      return cftoe2_l(buf, sizeInBytes, ndec, caps, pflt: &retstrflt, g_fmt: 0, plocinfo);
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return 22;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102F5467
// Name: __cftoe
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _cftoe(_CRT_DOUBLE *pvalue, char *buf, unsigned int sizeInBytes, int ndec, int caps)
{
  return _cftoe_l(pvalue, buf, sizeInBytes, ndec, caps, plocinfo: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x102F5487
// Name: __cftoa_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _cftoa_l(
        _CRT_DOUBLE *pvalue,
        char *buf,
        unsigned int sizeInBytes,
        int ndec,
        int caps,
        localeinfo_struct *plocinfo)
{
  char *v6; // esi
  int *v7; // eax
  int result; // eax
  unsigned int v9; // eax
  bool v10; // zf
  _BYTE *v11; // eax
  char *v12; // esi
  char *v13; // eax
  unsigned __int8 *v14; // esi
  int x_low; // eax
  unsigned int v16; // eax
  unsigned int v17; // ecx
  char *i; // eax
  __int64 v19; // rax
  __int64 v20; // rcx
  _BYTE *v21; // esi
  _BYTE *v22; // edi
  __int64 v23; // rax
  __int64 v24; // rcx
  __int64 v25; // rax
  __int64 v26; // rcx
  __int64 v27; // rcx
  __int64 v28; // [esp-Ch] [ebp-38h]
  int v29; // [esp-4h] [ebp-30h]
  _LocaleUpdate _loc_update; // [esp+8h] [ebp-24h] BYREF
  __int64 exponent; // [esp+18h] [ebp-14h]
  unsigned __int64 mask; // [esp+20h] [ebp-Ch]
  int maskpos; // [esp+28h] [ebp-4h]
  char *pos; // [esp+38h] [ebp+Ch]

  LODWORD(exponent) = 1023;
  maskpos = 48;
  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  if ( ndec < 0 )
    ndec = 0;
  v6 = buf;
  if ( buf == nullptr || sizeInBytes == 0 )
  {
    v7 = _errno();
    v29 = 22;
LABEL_5:
    *v7 = v29;
    _invalid_parameter_noinfo();
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return v29;
  }
  *buf = 0;
  if ( sizeInBytes <= ndec + 11 )
  {
    v7 = _errno();
    v29 = 34;
    goto LABEL_5;
  }
  LODWORD(mask) = LODWORD(pvalue->x);
  if ( ((HIDWORD(pvalue->x) >> 20) & 0x7FF) == 0x7FF )
  {
    v9 = sizeInBytes;
    if ( sizeInBytes != -1 )
      v9 = sizeInBytes - 2;
    result = _cftoe(pvalue, buf: buf + 2, sizeInBytes: v9, ndec, caps: 0);
    if ( result != 0 )
    {
      v10 = !_loc_update.updated;
      *buf = 0;
      if ( !v10 )
        _loc_update.ptd->_ownlocale &= ~2u;
      return result;
    }
    if ( buf[2] == 45 )
    {
      *buf = 45;
      v6 = buf + 1;
    }
    *v6 = 48;
    v6[1] = caps == 0 ? 120 : 88;
    strrchr(string: (unsigned __int8 *)v6 + 2, chr: 0x65u);
    if ( v11 != nullptr )
    {
      *v11 = caps == 0 ? 112 : 80;
      v11[3] = 0;
    }
  }
  else
  {
    if ( (HIDWORD(pvalue->x) & 0x80000000) != 0 )
    {
      *buf = 45;
      v6 = buf + 1;
    }
    *v6 = 48;
    v6[1] = caps == 0 ? 120 : 88;
    if ( (HIDWORD(pvalue->x) & 0x7FF00000) != 0 )
    {
      v6[2] = 49;
      v12 = v6 + 3;
    }
    else
    {
      v6[2] = 48;
      v12 = v6 + 3;
      if ( (HIDWORD(pvalue->x) & 0xFFFFF | LODWORD(pvalue->x)) != 0 )
        LODWORD(exponent) = 1022;
      else
        LODWORD(exponent) = 0;
    }
    v13 = v12;
    v14 = (unsigned __int8 *)(v12 + 1);
    pos = v13;
    if ( ndec != 0 )
      *v13 = *_loc_update.localeinfo.locinfo->lconv->decimal_point;
    else
      *v13 = 0;
    x_low = LODWORD(pvalue->x);
    HIDWORD(mask) = HIDWORD(pvalue->x) & 0xFFFFF;
    if ( HIDWORD(mask) != 0 || x_low != 0 )
    {
      mask = 0xF000000000000LL;
      do
      {
        if ( ndec <= 0 )
          break;
        v16 = (unsigned __int16)(((mask & *(_QWORD *)&pvalue->x & 0xFFFFFFFFFFFFFLL) >> maskpos) + 48);
        if ( v16 > 0x39 )
          LOBYTE(v16) = (caps != 0 ? 7 : 39) + ((mask & *(_QWORD *)&pvalue->x & 0xFFFFFFFFFFFFFLL) >> maskpos) + 48;
        v17 = HIDWORD(mask);
        maskpos -= 4;
        *v14++ = v16;
        --ndec;
        mask = __PAIR64__(v17, mask) >> 4;
      }
      while ( (maskpos & 0x8000u) == 0 );
      if ( (maskpos & 0x8000u) == 0
        && (unsigned __int16)((mask & *(_QWORD *)&pvalue->x & 0xFFFFFFFFFFFFFLL) >> maskpos) > 8u )
      {
        for ( i = (char *)(v14 - 1); *i == 102 || *i == 70; --i )
          *i = 48;
        if ( i == pos )
        {
          ++*(i - 1);
        }
        else if ( *i == 57 )
        {
          *i = caps != 0 ? 65 : 97;
        }
        else
        {
          ++*i;
        }
      }
    }
    if ( ndec > 0 )
    {
      memset(dst: v14, value: 0x30u, count: ndec);
      v14 += ndec;
    }
    if ( *pos == 0 )
      v14 = (unsigned __int8 *)pos;
    *v14 = caps == 0 ? 112 : 80;
    HIDWORD(v20) = 0;
    v19 = ((*(_QWORD *)&pvalue->x >> 52) & 0x7FFLL) - (unsigned int)exponent;
    if ( v19 < 0 )
    {
      v14[1] = 45;
      v21 = v14 + 2;
      v19 = -v19;
    }
    else
    {
      v14[1] = 43;
      v21 = v14 + 2;
    }
    v22 = v21;
    *v21 = 48;
    if ( v19 >= 0 )
    {
      LODWORD(v20) = 1000;
      if ( v19 >= 1000 )
      {
        v28 = v20;
        v24 = v19 % v20;
        v23 = v19 / v28;
        *v21++ = v23 + 48;
        HIDWORD(exponent) = HIDWORD(v23);
        v19 = v24;
        if ( v21 != v22 )
          goto LABEL_60;
      }
    }
    if ( v19 >= 100 )
    {
LABEL_60:
      v26 = v19 % 100;
      v25 = v19 / 100;
      *v21 = v25 + 48;
      HIDWORD(exponent) = HIDWORD(v25);
      ++v21;
      v19 = v26;
    }
    if ( v21 != v22 || v19 >= 10 )
    {
      v27 = v19 % 10;
      *v21++ = v19 / 10 + 48;
      LOBYTE(v19) = v19 % 10;
      HIDWORD(exponent) = HIDWORD(v27);
    }
    *v21 = v19 + 48;
    v21[1] = 0;
  }
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x102F57FD
// Name: _cftof2_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall cftof2_l@<eax>(
        char *buf@<ecx>,
        _strflt *pflt@<eax>,
        unsigned int sizeInBytes,
        int ndec,
        char g_fmt,
        localeinfo_struct *plocinfo)
{
  int v8; // esi
  char *v10; // esi
  int decpt; // eax
  int v12; // eax
  char *v13; // esi
  int v14; // eax
  int v15; // edi
  int v16; // edi
  _LocaleUpdate _loc_update; // [esp+Ch] [ebp-10h] BYREF

  v8 = pflt->decpt - 1;
  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  if ( buf != nullptr && sizeInBytes != 0 )
  {
    if ( g_fmt != 0 && v8 == ndec )
      *(_WORD *)&buf[v8 + (pflt->sign == 45)] = 48;
    v10 = buf;
    if ( pflt->sign == 45 )
    {
      *buf = 45;
      v10 = buf + 1;
    }
    decpt = pflt->decpt;
    if ( decpt > 0 )
    {
      v13 = &v10[decpt];
    }
    else
    {
      strlen(buf: v10);
      memmove(dst: (__m128i *)(v10 + 1), src: (const __m128i *)v10, count: v12 + 1);
      *v10 = 48;
      v13 = v10 + 1;
    }
    if ( ndec > 0 )
    {
      strlen(buf: v13);
      memmove(dst: (__m128i *)(v13 + 1), src: (const __m128i *)v13, count: v14 + 1);
      *v13 = *_loc_update.localeinfo.locinfo->lconv->decimal_point;
      v15 = pflt->decpt;
      if ( v15 < 0 )
      {
        v16 = -v15;
        if ( g_fmt != 0 || ndec >= v16 )
          ndec = v16;
        shift(s: (__m128i *)(v13 + 1), dist: ndec);
        memset(dst: (unsigned __int8 *)v13 + 1, value: 0x30u, count: ndec);
      }
    }
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return 0;
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return 22;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102F5900
// Name: __cftof_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _cftof_l(_CRT_DOUBLE *pvalue, char *buf, unsigned int sizeInBytes, int ndec, localeinfo_struct *plocinfo)
{
  int result; // eax
  unsigned int v6; // eax
  _strflt retstrflt; // [esp+8h] [ebp-2Ch] BYREF
  char resstr[24]; // [esp+18h] [ebp-1Ch] BYREF

  _fltout2(x: *(_CRT_DOUBLE *)&pvalue->x, flt: &retstrflt, resultstr: resstr, resultsize: 0x16u);
  if ( buf != nullptr && sizeInBytes != 0 )
  {
    v6 = -1;
    if ( sizeInBytes != -1 )
      v6 = sizeInBytes - (retstrflt.sign == 45);
    result = _fptostr(
               buf: &buf[retstrflt.sign == 45],
               sizeInBytes: v6,
               digits: ndec + retstrflt.decpt,
               pflt: &retstrflt);
    if ( result != 0 )
      *buf = 0;
    else
      return cftof2_l(buf, pflt: &retstrflt, sizeInBytes, ndec, g_fmt: 0, plocinfo);
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return 22;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102F59C1
// Name: __cftog_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _cftog_l(
        _CRT_DOUBLE *pvalue,
        char *buf,
        unsigned int sizeInBytes,
        int ndec,
        int caps,
        localeinfo_struct *plocinfo)
{
  int result; // eax
  unsigned int v7; // ecx
  int v8; // ebx
  BOOL v9; // eax
  char *v10; // edi
  _strflt retstrflt; // [esp+8h] [ebp-2Ch] BYREF
  char resstr[24]; // [esp+18h] [ebp-1Ch] BYREF

  _fltout2(x: *(_CRT_DOUBLE *)&pvalue->x, flt: &retstrflt, resultstr: resstr, resultsize: 0x16u);
  if ( buf != nullptr && (v7 = sizeInBytes, sizeInBytes != 0) )
  {
    v8 = retstrflt.decpt - 1;
    v9 = retstrflt.sign == 45;
    v10 = &buf[v9];
    if ( sizeInBytes != -1 )
      v7 = sizeInBytes - v9;
    result = _fptostr(buf: v10, sizeInBytes: v7, digits: ndec, pflt: &retstrflt);
    if ( result != 0 )
    {
      *buf = 0;
    }
    else if ( retstrflt.decpt - 1 < -4 || retstrflt.decpt - 1 >= ndec )
    {
      return cftoe2_l(buf, sizeInBytes, ndec, caps, pflt: &retstrflt, g_fmt: 1, plocinfo);
    }
    else
    {
      if ( v8 < retstrflt.decpt - 1 )
        v10[strlen(v10) - 1] = 0;
      return cftof2_l(buf, pflt: &retstrflt, sizeInBytes, ndec, g_fmt: 1, plocinfo);
    }
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return 22;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102F5B7C
// Name: __setdefaultprecision
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int _setdefaultprecision()
{
  int result; // eax

  result = _controlfp_s(_CurrentState: nullptr, newctrl: 0x10000u, mask: 0x30000u);
  if ( result != 0 )
    _invoke_watson();
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102F5C20
// Name: _strcmp
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl strcmp(unsigned __int8 *str1, unsigned __int8 *str2)
{
  unsigned __int8 *v2; // edx
  unsigned __int8 *v3; // ecx
  unsigned int v4; // eax
  unsigned int v5; // eax
  __int16 v6; // ax

  v2 = str1;
  v3 = str2;
  if ( ((unsigned __int8)str1 & 3) != 0 )
  {
    if ( ((unsigned __int8)str1 & 1) == 0 )
      goto doword;
    v2 = str1 + 1;
    if ( *str1 != *str2 )
      return;
    v3 = str2 + 1;
    if ( *str1 == 0 )
      return;
    if ( ((unsigned __int8)v2 & 2) != 0 )
    {
doword:
      v6 = *(_WORD *)v2;
      v2 += 2;
      if ( (_BYTE)v6 != *v3 || (_BYTE)v6 == 0 || HIBYTE(v6) != v3[1] || HIBYTE(v6) == 0 )
        return;
      v3 += 2;
    }
  }
  do
  {
    v4 = *(_DWORD *)v2;
    if ( (unsigned __int8)*(_DWORD *)v2 != *v3 )
      break;
    if ( (_BYTE)v4 == 0 )
      break;
    if ( BYTE1(v4) != v3[1] )
      break;
    if ( BYTE1(v4) == 0 )
      break;
    v5 = HIWORD(v4);
    if ( (_BYTE)v5 != v3[2] )
      break;
    if ( (_BYTE)v5 == 0 )
      break;
    if ( BYTE1(v5) != v3[3] )
      break;
    v3 += 4;
    v2 += 4;
  }
  while ( BYTE1(v5) != 0 );
}

//------------------------------------------------------------------------------
// Address: 0x102F5CA8
// Name: _abort
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl __noreturn abort()
{
  if ( __get_sigabrt() != nullptr )
    raise(signum: 22);
  if ( (__abort_behavior & 2) != 0 )
    _call_reportfault(nDbgHookCode: 3, dwExceptionCode: 0x40000015u, dwExceptionFlags: 1u);
  _exit(code: 3);
}

//------------------------------------------------------------------------------
// Address: 0x102F5CDB
// Name: __set_abort_behavior
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl _set_abort_behavior(unsigned int flags, unsigned int mask)
{
  unsigned int result; // eax

  result = __abort_behavior;
  __abort_behavior = mask & flags | __abort_behavior & ~mask;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102F5CFC
// Name: __GET_RTERRMSG
// Source: linker_block_proximity
//------------------------------------------------------------------------------
const wchar_t *__cdecl _GET_RTERRMSG(int rterrnum)
{
  int v1; // eax

  v1 = 0;
  while ( rterrnum != rterrs[v1].rterrno )
  {
    if ( (unsigned int)++v1 >= 0x16 )
      return nullptr;
  }
  return rterrs[v1].rterrtxt;
}

//------------------------------------------------------------------------------
// Address: 0x102F5D22
// Name: __NMSG_WRITE
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _NMSG_WRITE(int rterrnum)
{
  const wchar_t *v1; // edi
  int v2; // eax
  HANDLE StdHandle; // eax
  void *v4; // esi
  unsigned int i; // eax
  DWORD v6; // eax
  unsigned int bytes_written; // [esp+Ch] [ebp-1FCh] BYREF
  char buffer[500]; // [esp+10h] [ebp-1F8h] BYREF

  v1 = _GET_RTERRMSG(rterrnum);
  bytes_written = (unsigned int)v1;
  if ( v1 != nullptr )
  {
    if ( _set_error_mode(em: 3) == 1 || _set_error_mode(em: 3) == 0 && __app_type == 1 )
    {
      StdHandle = GetStdHandle(nStdHandle: 0xFFFFFFF4);
      v4 = StdHandle;
      if ( StdHandle != nullptr && StdHandle != (HANDLE)-1 )
      {
        for ( i = 0; i < 0x1F4; ++i )
        {
          buffer[i] = v1[i];
          if ( v1[i] == 0 )
            break;
        }
        buffer[499] = 0;
        strlen(buf: buffer);
        WriteFile(
          hFile: v4,
          lpBuffer: buffer,
          nNumberOfBytesToWrite: v6,
          lpNumberOfBytesWritten: &bytes_written,
          lpOverlapped: nullptr);
      }
    }
    else if ( rterrnum != 252 )
    {
      if ( wcscpy_s(_Dst: outmsg, _SizeInWords: 0x314u, _Src: aRuntimeErrorPr) != 0
        || (outmsg[285] = 0, GetModuleFileNameW(hModule: nullptr, lpFilename: &outmsg[25], nSize: 0x104u) == 0)
        && wcscpy_s(_Dst: &outmsg[25], _SizeInWords: 0x2FBu, _Src: L"<program name unknown>") != 0
        || (unsigned int)(wcslen(wcs: &outmsg[25]) + 1) > 0x3C
        && (v2 = wcslen(wcs: &outmsg[25]),
            wcsncpy_s(
              _Dst: &_umaskval + v2,
              _SizeInWords: 763 - (&_umaskval + v2 - &outmsg[25]),
              _Src: L"...",
              _Count: 3u) != 0)
        || wcscat_s(_Dst: outmsg, _SizeInWords: 0x314u, _Src: L"\n\n") != 0
        || wcscat_s(_Dst: outmsg, _SizeInWords: 0x314u, _Src: (const wchar_t *)bytes_written) != 0 )
      {
        _invoke_watson();
      }
      __crtMessageBoxW(lpText: outmsg, lpCaption: L"Microsoft Visual C++ Runtime Library", uType: 0x12010u);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102F5ED1
// Name: __FF_MSGBANNER
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void _FF_MSGBANNER()
{
  if ( _set_error_mode(em: 3) == 1 || _set_error_mode(em: 3) == 0 && __app_type == 1 )
  {
    _NMSG_WRITE(rterrnum: 252);
    _NMSG_WRITE(rterrnum: 255);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102F5F0A
// Name: ___getlocaleinfo
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl __getlocaleinfo(
        localeinfo_struct *plocinfo,
        int lc_type,
        unsigned int localehandle,
        unsigned int fieldtype,
        void **address)
{
  unsigned __int8 *v5; // ebx
  unsigned int LocaleInfoA; // esi
  unsigned int v7; // eax
  char *v8; // eax
  char *v9; // eax
  unsigned int LocaleInfoW; // eax
  int v12; // ebx
  wchar_t *v13; // eax
  int buffersize; // [esp+Ch] [ebp-90h]
  int bufferused; // [esp+10h] [ebp-8Ch]
  unsigned int dw; // [esp+14h] [ebp-88h] BYREF
  unsigned __int8 cbuffer[128]; // [esp+18h] [ebp-84h] BYREF

  dw = (unsigned int)plocinfo;
  switch ( lc_type )
  {
    case 1:
      bufferused = 0;
      v5 = cbuffer;
      LocaleInfoA = __crtGetLocaleInfoA(
                      plocinfo,
                      Locale: localehandle,
                      LCType: fieldtype,
                      lpLCData: (char *)cbuffer,
                      cchData: 128);
      if ( LocaleInfoA == 0 )
      {
        if ( GetLastError() != 122 )
          return -1;
        v7 = __crtGetLocaleInfoA(
               plocinfo: (localeinfo_struct *)dw,
               Locale: localehandle,
               LCType: fieldtype,
               lpLCData: nullptr,
               cchData: 0);
        buffersize = v7;
        if ( v7 == 0 )
          return -1;
        v8 = (char *)calloc(count: v7, size: 1u);
        v5 = (unsigned __int8 *)v8;
        if ( v8 == nullptr )
          return -1;
        bufferused = 1;
        LocaleInfoA = __crtGetLocaleInfoA(
                        plocinfo: (localeinfo_struct *)dw,
                        Locale: localehandle,
                        LCType: fieldtype,
                        lpLCData: v8,
                        cchData: buffersize);
        if ( LocaleInfoA == 0 )
          goto LABEL_9;
      }
      v9 = (char *)calloc(count: LocaleInfoA, size: 1u);
      *address = v9;
      if ( v9 == nullptr )
      {
        if ( bufferused == 0 )
          return -1;
LABEL_9:
        free(pMem: v5);
        return -1;
      }
      if ( strncpy_s(_Dst: v9, _SizeInBytes: LocaleInfoA, _Src: (const char *)v5, _Count: LocaleInfoA - 1) != 0 )
        _invoke_watson();
      if ( bufferused != 0 )
        free(pMem: v5);
      break;
    case 2:
      *address = nullptr;
      LocaleInfoW = GetLocaleInfoW(Locale: localehandle, LCType: fieldtype, lpLCData: nullptr, cchData: 0);
      v12 = LocaleInfoW;
      if ( LocaleInfoW == 0
        || (v13 = (wchar_t *)calloc(count: LocaleInfoW, size: 2u), *address = v13, v13 == nullptr)
        || GetLocaleInfoW(Locale: localehandle, LCType: fieldtype, lpLCData: v13, cchData: v12) == 0 )
      {
        free(pMem: *address);
        *address = nullptr;
        return -1;
      }
      break;
    case 0:
      dw = 0;
      if ( GetLocaleInfoW(Locale: localehandle, LCType: fieldtype | 0x20000000, lpLCData: (LPWSTR)&dw, cchData: 2) == 0 )
        return -1;
      *(_BYTE *)address = dw;
      break;
    default:
      return -1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x102F60B6
// Name: __initp_misc_purevirt
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _initp_misc_purevirt(void *enull)
{
  __pPurecall = enull;
}

} // namespace engine_xlsp
