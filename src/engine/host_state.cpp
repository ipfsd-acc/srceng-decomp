// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: engine/host_state.cpp
// Functions: 31
// ============================================================

#include "engine\host_state.h"

//------------------------------------------------------------------------------
// Address: 0x10197100
// Name: void HostState_SetSpawnPoint(class Vector __near &,class QAngle __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl HostState_SetSpawnPoint(Vector *position, QAngle *angle)
{
  g_HostState.m_angLocation = *angle;
  g_HostState.m_vecLocation = *position;
  g_HostState.m_bRememberLocation = true;
}

//------------------------------------------------------------------------------
// Address: 0x10197160
// Name: bool HostState_IsTransitioningToLoad(void)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl HostState_IsTransitioningToLoad()
{
  return g_HostState.m_nextState < (unsigned int)HS_RUN;
}

//------------------------------------------------------------------------------
// Address: 0x10197180
// Name: bool HostState_GameHasShutDownAndFlushedMemory(void)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl HostState_GameHasShutDownAndFlushedMemory()
{
  return g_HostState.m_bGameHasShutDownAndFlushedMemory;
}

//------------------------------------------------------------------------------
// Address: 0x10197190
// Name: void HostState_Pre_LoadMapIntoMemory(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl HostState_Pre_LoadMapIntoMemory()
{
  g_HostState.m_bGameHasShutDownAndFlushedMemory = false;
}

//------------------------------------------------------------------------------
// Address: 0x101971A0
// Name: void HostState_Post_FlushMapFromMemory(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl HostState_Post_FlushMapFromMemory()
{
  g_HostState.m_bGameHasShutDownAndFlushedMemory = true;
}

//------------------------------------------------------------------------------
// Address: 0x101971B0
// Name: char const __near * HostState_GetNewLevel(void)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl HostState_GetNewLevel()
{
  return g_HostState.m_levelName;
}

//------------------------------------------------------------------------------
// Address: 0x101971C0
// Name: public: void CHostState::RememberLocation(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHostState::RememberLocation(CHostState *this)
{
  IClientEntityList_vtbl *v2; // edi
  CClientState *LocalClient; // eax
  int v4; // eax
  float *v5; // eax

  this->m_vecLocation = g_MainViewOrigin[0];
  VectorAngles(forward: g_MainViewForward, angles: &this->m_angLocation);
  if ( entitylist != nullptr )
  {
    v2 = entitylist->__vftable;
    LocalClient = GetLocalClient(nSlot: -1);
    v4 = (int)v2->GetClientEntity(this: entitylist, a2: LocalClient->m_nPlayerSlot + 1);
    if ( v4 != 0 )
    {
      v5 = (float *)(*(int (__thiscall **)(int))(*(_DWORD *)v4 + 40))(a1: v4);
      this->m_vecLocation.x = *v5;
      this->m_vecLocation.y = v5[1];
      this->m_vecLocation.z = v5[2];
    }
  }
  this->m_vecLocation.z = this->m_vecLocation.z - 64.0;
}

//------------------------------------------------------------------------------
// Address: 0x10197260
// Name: void HostState_RunGameInit(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl HostState_RunGameInit()
{
  materials->OnDebugEvent(this: materials, a2: "CHostState::RunGameInit");
  if ( serverGameDLL != nullptr )
    serverGameDLL->GameInit(this: serverGameDLL);
  g_ServerGlobalVariables.bMapLoadFailed = false;
  g_HostState.m_activeGame = true;
}

//------------------------------------------------------------------------------
// Address: 0x101972A0
// Name: void HostState_NewGame(char const __near *,bool,bool,bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl HostState_NewGame(const char *pMapName, bool remember_location, bool background, bool bSplitScreenConnect)
{
  char szMapName[260]; // [esp+0h] [ebp-104h] BYREF

  V_StripExtension(in: pMapName, out: szMapName, outSize: 260);
  V_strncpy(pDest: g_HostState.m_levelName, pSrc: szMapName, maxLen: 256);
  g_HostState.m_landmarkName[0] = 0;
  g_HostState.m_bRememberLocation = remember_location;
  g_HostState.m_bWaitingForConnection = true;
  g_HostState.m_bBackgroundLevel = background;
  g_HostState.m_bSplitScreenConnect = bSplitScreenConnect;
  if ( remember_location )
    CHostState::RememberLocation(this: &g_HostState);
  g_HostState.m_nextState = HS_NEW_GAME;
}

//------------------------------------------------------------------------------
// Address: 0x10197320
// Name: void HostState_LoadGame(char const __near *,bool,bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl HostState_LoadGame(const char *pSaveFileName, bool remember_location, bool bLetToolsOverrideLoadGameEnts)
{
  if ( saverestore->SaveFileExists(this: saverestore, a2: pSaveFileName) )
  {
    V_strncpy(pDest: g_HostState.m_saveName, pSrc: pSaveFileName, maxLen: 256);
    serverGameDLL->PreSaveGameLoaded(this: serverGameDLL, a2: pSaveFileName, a3: sv.m_State >= ss_active);
    g_HostState.m_bRememberLocation = remember_location;
    *(_WORD *)&g_HostState.m_bBackgroundLevel = 256;
    g_HostState.m_bSplitScreenConnect = false;
    g_HostState.m_bLetToolsOverrideLoadGameEnts = bLetToolsOverrideLoadGameEnts;
    if ( remember_location )
      CHostState::RememberLocation(this: &g_HostState);
    g_HostState.m_nextState = HS_LOAD_GAME;
  }
  else
  {
    _Warning(a1: "Save file %s can't be found!\n", pSaveFileName);
    SCR_EndLoadingPlaque();
  }
}

//------------------------------------------------------------------------------
// Address: 0x101973C0
// Name: void HostState_ChangeLevelSP(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl HostState_ChangeLevelSP(const char *pNewLevel, const char *pLandmarkName)
{
  V_strncpy(pDest: g_HostState.m_levelName, pSrc: pNewLevel, maxLen: 256);
  V_strncpy(pDest: g_HostState.m_landmarkName, pSrc: pLandmarkName, maxLen: 256);
  g_HostState.m_nextState = HS_CHANGE_LEVEL_SP;
}

//------------------------------------------------------------------------------
// Address: 0x10197400
// Name: void HostState_ChangeLevelMP(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __usercall HostState_ChangeLevelMP(int a1@<ebx>, int a2@<edi>, const char *pNewLevel, const char *pLandmarkName)
{
  CSteam3Server *v4; // eax

  v4 = Steam3Server();
  CSteam3Server::NotifyOfLevelChange(this: v4, a2: a1, a3: a2);
  V_strncpy(pDest: g_HostState.m_levelName, pSrc: pNewLevel, maxLen: 256);
  V_strncpy(pDest: g_HostState.m_landmarkName, pSrc: pLandmarkName, maxLen: 256);
  g_HostState.m_nextState = HS_CHANGE_LEVEL_MP;
}

//------------------------------------------------------------------------------
// Address: 0x10197450
// Name: void HostState_GameShutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall HostState_GameShutdown(int a1@<ebx>, int a2@<edi>)
{
  CSteam3Server *v2; // eax

  v2 = Steam3Server();
  CSteam3Server::NotifyOfLevelChange(this: v2, a2: a1, a3: a2);
  if ( g_HostState.m_currentState != HS_SHUTDOWN
    && g_HostState.m_currentState != HS_RESTART
    && g_HostState.m_currentState != HS_GAME_SHUTDOWN )
  {
    g_HostState.m_nextState = HS_GAME_SHUTDOWN;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10197480
// Name: void HostState_Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl HostState_Shutdown()
{
  g_HostState.m_nextState = HS_SHUTDOWN;
}

//------------------------------------------------------------------------------
// Address: 0x10197490
// Name: void HostState_Restart(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl HostState_Restart()
{
  g_HostState.m_nextState = HS_RESTART;
}

//------------------------------------------------------------------------------
// Address: 0x101974A0
// Name: bool HostState_IsGameShuttingDown(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl HostState_IsGameShuttingDown()
{
  return g_HostState.m_currentState == HS_GAME_SHUTDOWN || g_HostState.m_nextState == HS_GAME_SHUTDOWN;
}

//------------------------------------------------------------------------------
// Address: 0x101974C0
// Name: void HostState_OnClientDisconnected(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl HostState_OnClientDisconnected()
{
  vgui::PropertyPage *v0; // ecx

  materials->OnDebugEvent(this: materials, a2: "CHostState::OnClientDisconnected");
  if ( !sv.m_bIsDedicated )
    CColorBalanceUIPanel::Init(this: v0);
}

//------------------------------------------------------------------------------
// Address: 0x101974F0
// Name: public: void CHostState::Init(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHostState::Init(CHostState *this)
{
  if ( this->m_nextState != HS_SHUTDOWN )
  {
    this->m_currentState = HS_RUN;
    this->m_nextState = HS_RUN;
  }
  this->m_levelName[0] = 0;
  this->m_saveName[0] = 0;
  this->m_landmarkName[0] = 0;
  *(_WORD *)&this->m_activeGame = 0;
  this->m_bBackgroundLevel = false;
  *(_WORD *)&this->m_bLetToolsOverrideLoadGameEnts = 0;
  this->m_vecLocation.x = 0.0;
  this->m_vecLocation.y = 0.0;
  this->m_vecLocation.z = 0.0;
  this->m_angLocation.x = 0.0;
  this->m_angLocation.y = 0.0;
  this->m_angLocation.z = 0.0;
  this->m_bWaitingForConnection = false;
  this->m_flShortFrameTime = 1.0;
  this->m_bGameHasShutDownAndFlushedMemory = true;
}

//------------------------------------------------------------------------------
// Address: 0x10197570
// Name: public: void CHostState::State_NewGame(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHostState::State_NewGame(CHostState *this)
{
  bool m_bSplitScreenConnect; // al
  void (__thiscall *OnDebugEvent)(IMaterialSystem *, const char *); // edx
  bool bSplitScreenConnect; // [esp+8h] [ebp-4h]

  m_bSplitScreenConnect = this->m_bSplitScreenConnect;
  this->m_bSplitScreenConnect = false;
  bSplitScreenConnect = m_bSplitScreenConnect;
  materials->OnDebugEvent(this: materials, a2: "CHostState::State_NewGame");
  if ( serverGameClients != nullptr || (SV_InitGameDLL(), serverGameClients != nullptr) )
  {
    if ( modelloader->Map_IsValid(this: modelloader, a2: this->m_levelName, a3: false)
      && Host_NewGame(
           mapName: this->m_levelName,
           loadGame: false,
           bBackgroundLevel: this->m_bBackgroundLevel,
           bSplitScreenConnect,
           pszOldMap: nullptr,
           pszLandmark: nullptr) )
    {
      this->m_currentState = HS_RUN;
      this->m_nextState = HS_RUN;
      return;
    }
  }
  else
  {
    _Warning(a1: "Can't start game, no valid server.dll loaded\n");
  }
  SCR_EndLoadingPlaque();
  OnDebugEvent = materials->OnDebugEvent;
  if ( this->m_activeGame )
  {
    ((void (__stdcall *)(const char *))OnDebugEvent)(a1: "HostState::GameShutdown(active)");
    serverGameDLL->GameShutdown(this: serverGameDLL);
    this->m_activeGame = false;
  }
  else
  {
    ((void (__stdcall *)(const char *))OnDebugEvent)(a1: "HostState::GameShutdown");
  }
  this->m_currentState = HS_RUN;
  this->m_nextState = HS_RUN;
  CBaseServer::ClearReservationStatus(this: &sv);
}

//------------------------------------------------------------------------------
// Address: 0x10197670
// Name: public: void CHostState::State_LoadGame(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHostState::State_LoadGame(CHostState *this)
{
  void (__thiscall *OnDebugEvent)(IMaterialSystem *, const char *); // eax

  materials->OnDebugEvent(this: materials, a2: "CHostState::State_LoadGame");
  materials->OnDebugEvent(this: materials, a2: "CHostState::RunGameInit");
  if ( serverGameDLL != nullptr )
    serverGameDLL->GameInit(this: serverGameDLL);
  g_HostState.m_activeGame = true;
  g_ServerGlobalVariables.bMapLoadFailed = false;
  if ( ((unsigned __int8 (__stdcall *)(char *, bool))saverestore->LoadGame)(
         a1: this->m_saveName,
         a2: this->m_bLetToolsOverrideLoadGameEnts) != 0 )
  {
    CTestScriptMgr::CheckPoint(this: &g_TestScriptMgr, pName: "load_game");
    this->m_currentState = HS_RUN;
    this->m_nextState = HS_RUN;
  }
  else
  {
    SCR_EndLoadingPlaque();
    OnDebugEvent = materials->OnDebugEvent;
    if ( this->m_activeGame )
    {
      ((void (__stdcall *)(const char *))OnDebugEvent)(a1: "HostState::GameShutdown(active)");
      serverGameDLL->GameShutdown(this: serverGameDLL);
      this->m_activeGame = false;
    }
    else
    {
      ((void (__stdcall *)(const char *))OnDebugEvent)(a1: "HostState::GameShutdown");
    }
    this->m_currentState = HS_RUN;
    this->m_nextState = HS_RUN;
    if ( g_pMatchFramework->GetMatchSession(this: g_pMatchFramework) != nullptr )
      g_pMatchFramework->CloseSession(this: g_pMatchFramework);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10197760
// Name: public: void CHostState::State_ChangeLevelMP(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHostState::State_ChangeLevelMP(CHostState *this)
{
  CSteam3Server *v2; // eax
  IEngineVGuiInternal *v3; // eax

  materials->OnDebugEvent(this: materials, a2: "CHostState::State_ChangeLevelMP");
  v2 = Steam3Server();
  CSteam3Server::NotifyOfLevelChange(this: v2);
  g_pServerPluginHandler->LevelShutdown(this: g_pServerPluginHandler);
  audiosourcecache->LevelShutdown(this: audiosourcecache);
  if ( modelloader->Map_IsValid(this: modelloader, a2: this->m_levelName, a3: false) )
  {
    v3 = EngineVGui();
    v3->EnabledProgressBarForNextLoad(this: v3);
    Host_Changelevel(loadfromsavedgame: false, mapname: this->m_levelName, start: this->m_landmarkName);
  }
  else
  {
    ConMsg(a1: "Unable to change level!\n");
  }
  this->m_nextState = HS_RUN;
  this->m_currentState = HS_RUN;
}

//------------------------------------------------------------------------------
// Address: 0x10197810
// Name: public: void CHostState::State_ChangeLevelSP(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHostState::State_ChangeLevelSP(CHostState *this)
{
  materials->OnDebugEvent(this: materials, a2: "CHostState::State_ChangeLevelSP");
  if ( modelloader->Map_IsValid(this: modelloader, a2: this->m_levelName, a3: false) )
    Host_Changelevel(loadfromsavedgame: true, mapname: this->m_levelName, start: this->m_landmarkName);
  else
    ConMsg(a1: "Unable to change level!\n");
  this->m_nextState = HS_RUN;
  this->m_currentState = HS_RUN;
}

//------------------------------------------------------------------------------
// Address: 0x10197880
// Name: public: void CHostState::State_GameShutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHostState::State_GameShutdown(CHostState *this)
{
  CSteam3Server *v2; // eax
  void (__thiscall *OnDebugEvent)(IMaterialSystem *, const char *); // edx
  CEngineRecipientFilter *v4; // eax
  HOSTSTATES m_nextState; // eax

  materials->OnDebugEvent(this: materials, a2: "CHostState::State_GameShutdown");
  if ( serverGameDLL != nullptr )
  {
    v2 = Steam3Server();
    CSteam3Server::NotifyOfLevelChange(this: v2);
    g_pServerPluginHandler->LevelShutdown(this: g_pServerPluginHandler);
    audiosourcecache->LevelShutdown(this: audiosourcecache);
  }
  OnDebugEvent = materials->OnDebugEvent;
  if ( this->m_activeGame )
  {
    ((void (__stdcall *)(const char *))OnDebugEvent)(a1: "HostState::GameShutdown(active)");
    serverGameDLL->GameShutdown(this: serverGameDLL);
    this->m_activeGame = false;
  }
  else
  {
    ((void (__stdcall *)(const char *))OnDebugEvent)(a1: "HostState::GameShutdown");
  }
  saverestore->ClearSaveDir(this: saverestore);
  Host_ShutdownServer();
  v4 = (CEngineRecipientFilter *)MapReslistGenerator();
  CEngineRecipientFilter::MakeReliable(this: v4);
  m_nextState = this->m_nextState;
  switch ( m_nextState )
  {
    case HS_NEW_GAME:
    case HS_LOAD_GAME:
    case HS_SHUTDOWN:
    case HS_RESTART:
      this->m_currentState = m_nextState;
      break;
    default:
      this->m_currentState = HS_RUN;
      this->m_nextState = HS_RUN;
      break;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10197960
// Name: public: void CHostState::OnClientConnected(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CHostState::OnClientConnected(CHostState *this@<ecx>, int a2@<ebx>, int a3@<edi>)
{
  bool v4; // zf
  vgui::CTreeViewListControl *v5; // ecx
  ECommandTarget_t TraceType; // eax
  vgui::CTreeViewListControl *v7; // ecx
  ECommandTarget_t v8; // eax
  vgui::CTreeViewListControl *v9; // ecx
  ECommandTarget_t v10; // eax
  int v11; // eax
  vgui::PropertyPage *v12; // ecx
  void *v13; // ebx
  int i; // esi
  const char *CounterName; // ebx
  vgui::CTreeViewListControl *v16; // ecx
  ECommandTarget_t v17; // eax
  double z; // [esp+1Ch] [ebp-20h]
  const char *v19; // [esp+20h] [ebp-1Ch]
  const char *v20; // [esp+20h] [ebp-1Ch]
  float v21; // [esp+30h] [ebp-Ch]
  void *v22; // [esp+34h] [ebp-8h]
  float v23; // [esp+38h] [ebp-4h]

  materials->OnDebugEvent(this: materials, a2: "CHostState::OnClientConnected");
  if ( this->m_bWaitingForConnection )
  {
    v4 = !this->m_bRememberLocation;
    this->m_bWaitingForConnection = false;
    if ( !v4 )
    {
      z = this->m_vecLocation.z;
      this->m_bRememberLocation = false;
      v19 = va(format: "setpos_exact %f %f %f\n", this->m_vecLocation.x, this->m_vecLocation.y, z);
      TraceType = CTraceFilter::GetTraceType(this: v5);
      Cbuf_AddText(eTarget: TraceType, pText: v19, nTickDelay: 0);
      v20 = va(format: "setang_exact %f %f %f\n", this->m_angLocation.x, this->m_angLocation.y, this->m_angLocation.z);
      v8 = CTraceFilter::GetTraceType(this: v7);
      Cbuf_AddText(eTarget: v8, pText: v20, nTickDelay: 0);
    }
    if ( reload_materials.m_pParent != nullptr && reload_materials.m_pParent->m_Value.m_nValue != 0 )
    {
      CLoaderMemAlloc::CrtIsValidPointer(this: (ConVar *)&reload_materials.IConVar, value: 0);
      v10 = CTraceFilter::GetTraceType(this: v9);
      Cbuf_AddText(eTarget: v10, pText: "mat_reloadallmaterials\n", nTickDelay: 0);
    }
    v11 = _CommandLine();
    if ( (*(int (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v11 + 12))(
           a1: v11,
           a2: "-dumpvidmemstats",
           a3: 0) != 0 )
    {
      v13 = (void *)((int (__thiscall *)(IBaseFileSystem *, const char *, const char *, _DWORD, int, int))g_pFileSystem->Open)(
                      a1: &g_pFileSystem->IBaseFileSystem,
                      a2: "vidmemstats.txt",
                      a3: "a",
                      a4: 0,
                      a5: a3,
                      a6: a2);
      v22 = v13;
      g_pFileSystem->FPrintf(this: g_pFileSystem, a2: v13, a3: "%s:\n", g_HostState.m_levelName);
      v23 = 0.0;
      for ( i = 0; i < CVProfile::GetNumCounters(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled); ++i )
      {
        if ( CVProfile::GetCounterGroup(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled, a2: i) == COUNTER_GROUP_TEXTURE_GLOBAL )
        {
          v21 = (float)(int)CVProfile::GetCounterValue(
                              this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
                              a2: i)
              * 0.00000095367432;
          v23 = v21 + v23;
          CounterName = CVProfile::GetCounterName(
                          this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
                          a2: i);
          if ( V_strnicmp(s1: CounterName, s2: "TexGroup_Global_", n: 16) == 0 )
            CounterName += 16;
          g_pFileSystem->FPrintf(this: g_pFileSystem, a2: v22, a3: "%s: %0.3fMB\n", CounterName, v21);
          v13 = v22;
        }
      }
      g_pFileSystem->FPrintf(this: g_pFileSystem, a2: v13, a3: "vidmem total: %0.3fMB\n", v23);
      g_pFileSystem->FPrintf(this: g_pFileSystem, a2: v13, a3: "---------------------------------\n");
      g_pFileSystem->Close(this: &g_pFileSystem->IBaseFileSystem, a2: v13);
      v17 = CTraceFilter::GetTraceType(this: v16);
      Cbuf_AddText(eTarget: v17, pText: "quit\n", nTickDelay: 0);
    }
    if ( !sv.m_bIsDedicated )
      CColorBalanceUIPanel::Init(this: v12);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10197BC0
// Name: void HostState_Init(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl HostState_Init()
{
  CHostState::Init(this: &g_HostState);
}

//------------------------------------------------------------------------------
// Address: 0x10197BD0
// Name: void HostState_OnClientConnected(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall HostState_OnClientConnected(int a1@<ebx>, int a2@<edi>)
{
  CHostState::OnClientConnected(this: &g_HostState, a2: a1, a3: a2);
}

//------------------------------------------------------------------------------
// Address: 0x10197BE0
// Name: IsClientActive
// Source: json
//------------------------------------------------------------------------------
bool __cdecl IsClientActive()
{
  int v1; // esi

  if ( sv.m_State < ss_active )
    return GetBaseLocalClient()->m_nSignonState == 6;
  v1 = 0;
  if ( sv.m_Clients.m_Size <= 0 )
    return false;
  while ( !sv.m_Clients.m_Memory.m_pMemory[v1]->IsActive(this: &sv.m_Clients.m_Memory.m_pMemory[v1]->IClient) )
  {
    if ( ++v1 >= sv.m_Clients.m_Size )
      return false;
  }
  return true;
}

//------------------------------------------------------------------------------
// Address: 0x10197C30
// Name: IsClientConnected
// Source: json
//------------------------------------------------------------------------------
bool __cdecl IsClientConnected()
{
  int v1; // esi

  if ( sv.m_State < ss_active )
    return GetBaseLocalClient()->m_nSignonState >= 2;
  v1 = 0;
  if ( sv.m_Clients.m_Size <= 0 )
    return false;
  while ( !sv.m_Clients.m_Memory.m_pMemory[v1]->IsConnected(this: &sv.m_Clients.m_Memory.m_pMemory[v1]->IClient) )
  {
    if ( ++v1 >= sv.m_Clients.m_Size )
      return false;
  }
  return true;
}

//------------------------------------------------------------------------------
// Address: 0x10197C90
// Name: public: void CHostState::State_Run(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHostState::State_Run(CHostState *this, float frameTime)
{
  float m_flShortFrameTime; // xmm0_4
  float v4; // xmm0_4
  HOSTSTATES m_nextState; // eax

  if ( this->m_flShortFrameTime > 0.0 )
  {
    if ( IsClientActive() )
    {
      m_flShortFrameTime = this->m_flShortFrameTime;
      if ( m_flShortFrameTime <= frameTime )
        v4 = 0.0;
      else
        v4 = m_flShortFrameTime - frameTime;
      this->m_flShortFrameTime = v4;
    }
    if ( IsClientConnected() && host_state.interval_per_tick <= frameTime )
      frameTime = host_state.interval_per_tick;
  }
  if ( s_bFirstRunFrame )
    s_bFirstRunFrame = false;
  Host_RunFrame(time: frameTime);
  m_nextState = this->m_nextState;
  switch ( m_nextState )
  {
    case HS_NEW_GAME:
    case HS_LOAD_GAME:
      SCR_BeginLoadingPlaque(levelName: this->m_levelName);
      goto $LN3_40;
    case HS_CHANGE_LEVEL_SP:
    case HS_CHANGE_LEVEL_MP:
      this->m_currentState = m_nextState;
      break;
    case HS_RUN:
      return;
    case HS_GAME_SHUTDOWN:
    case HS_SHUTDOWN:
    case HS_RESTART:
$LN3_40:
      this->m_currentState = HS_GAME_SHUTDOWN;
      break;
    default:
      this->m_currentState = HS_RUN;
      this->m_nextState = HS_RUN;
      break;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10197D70
// Name: public: void CHostState::FrameUpdate(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHostState::FrameUpdate(CHostState *this, float time)
{
  HOSTSTATES m_currentState; // edi

  if ( _setjmp3(a1: host_abortserver, a2: 0) != 0 )
  {
    CHostState::Init(this);
  }
  else
  {
    g_bAbortServerSet = true;
    do
    {
      m_currentState = this->m_currentState;
      switch ( this->m_currentState )
      {
        case HS_NEW_GAME:
          g_pMDLCache->BeginMapLoad(this: g_pMDLCache);
          CHostState::State_NewGame(this);
          break;
        case HS_LOAD_GAME:
          g_pMDLCache->BeginMapLoad(this: g_pMDLCache);
          CHostState::State_LoadGame(this);
          break;
        case HS_CHANGE_LEVEL_SP:
          g_pMDLCache->BeginMapLoad(this: g_pMDLCache);
          this->m_flShortFrameTime = 1.5;
          CHostState::State_ChangeLevelSP(this);
          break;
        case HS_CHANGE_LEVEL_MP:
          g_pMDLCache->BeginMapLoad(this: g_pMDLCache);
          this->m_flShortFrameTime = 0.5;
          CHostState::State_ChangeLevelMP(this);
          break;
        case HS_RUN:
          CHostState::State_Run(this, frameTime: time);
          break;
        case HS_GAME_SHUTDOWN:
          CHostState::State_GameShutdown(this);
          break;
        case HS_SHUTDOWN:
          CL_EndMovie();
          eng->SetNextState(this: eng, a2: DLL_CLOSE);
          break;
        case HS_RESTART:
          g_pMDLCache->BeginMapLoad(this: g_pMDLCache);
          CL_EndMovie();
          eng->SetNextState(this: eng, a2: DLL_CLOSE);
          eng->SetNextState(this: eng, a2: DLL_RESTART);
          break;
        default:
          break;
      }
    }
    while ( m_currentState != HS_RUN && m_currentState != HS_SHUTDOWN && m_currentState != HS_RESTART );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10197EE0
// Name: void HostState_Frame(float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl HostState_Frame(float time)
{
  CHostState::FrameUpdate(this: &g_HostState, time);
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x10197530
// Name: void HostState_SetSpawnPoint(class Vector __near &,class QAngle __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl HostState_SetSpawnPoint(Vector *position, QAngle *angle)
{
  g_HostState.m_angLocation = *angle;
  g_HostState.m_vecLocation = *position;
  g_HostState.m_bRememberLocation = true;
}

//------------------------------------------------------------------------------
// Address: 0x10197590
// Name: bool HostState_IsTransitioningToLoad(void)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl HostState_IsTransitioningToLoad()
{
  return g_HostState.m_nextState < (unsigned int)HS_RUN;
}

//------------------------------------------------------------------------------
// Address: 0x101975B0
// Name: bool HostState_GameHasShutDownAndFlushedMemory(void)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl HostState_GameHasShutDownAndFlushedMemory()
{
  return g_HostState.m_bGameHasShutDownAndFlushedMemory;
}

//------------------------------------------------------------------------------
// Address: 0x101975C0
// Name: void HostState_Pre_LoadMapIntoMemory(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl HostState_Pre_LoadMapIntoMemory()
{
  g_HostState.m_bGameHasShutDownAndFlushedMemory = false;
}

//------------------------------------------------------------------------------
// Address: 0x101975D0
// Name: void HostState_Post_FlushMapFromMemory(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl HostState_Post_FlushMapFromMemory()
{
  g_HostState.m_bGameHasShutDownAndFlushedMemory = true;
}

//------------------------------------------------------------------------------
// Address: 0x101975E0
// Name: char const __near * HostState_GetNewLevel(void)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl HostState_GetNewLevel()
{
  return g_HostState.m_levelName;
}

//------------------------------------------------------------------------------
// Address: 0x101975F0
// Name: public: void CHostState::RememberLocation(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHostState::RememberLocation(CHostState *this)
{
  IClientEntityList_vtbl *v2; // edi
  CClientState *LocalClient; // eax
  int v4; // eax
  float *v5; // eax

  this->m_vecLocation = g_MainViewOrigin[0];
  VectorAngles(forward: g_MainViewForward, angles: &this->m_angLocation);
  if ( entitylist != nullptr )
  {
    v2 = entitylist->__vftable;
    LocalClient = GetLocalClient(nSlot: -1);
    v4 = (int)v2->GetClientEntity(this: entitylist, a2: LocalClient->m_nPlayerSlot + 1);
    if ( v4 != 0 )
    {
      v5 = (float *)(*(int (__thiscall **)(int))(*(_DWORD *)v4 + 40))(a1: v4);
      this->m_vecLocation.x = *v5;
      this->m_vecLocation.y = v5[1];
      this->m_vecLocation.z = v5[2];
    }
  }
  this->m_vecLocation.z = this->m_vecLocation.z - 64.0;
}

//------------------------------------------------------------------------------
// Address: 0x10197690
// Name: void HostState_RunGameInit(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl HostState_RunGameInit()
{
  materials->OnDebugEvent(this: materials, a2: "CHostState::RunGameInit");
  if ( serverGameDLL != nullptr )
    serverGameDLL->GameInit(this: serverGameDLL);
  g_ServerGlobalVariables.bMapLoadFailed = false;
  g_HostState.m_activeGame = true;
}

//------------------------------------------------------------------------------
// Address: 0x101976D0
// Name: void HostState_NewGame(char const __near *,bool,bool,bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl HostState_NewGame(const char *pMapName, bool remember_location, bool background, bool bSplitScreenConnect)
{
  char szMapName[260]; // [esp+0h] [ebp-104h] BYREF

  V_StripExtension(in: pMapName, out: szMapName, outSize: 260);
  V_strncpy(pDest: g_HostState.m_levelName, pSrc: szMapName, maxLen: 256);
  g_HostState.m_landmarkName[0] = 0;
  g_HostState.m_bRememberLocation = remember_location;
  g_HostState.m_bWaitingForConnection = true;
  g_HostState.m_bBackgroundLevel = background;
  g_HostState.m_bSplitScreenConnect = bSplitScreenConnect;
  if ( remember_location )
    CHostState::RememberLocation(this: &g_HostState);
  g_HostState.m_nextState = HS_NEW_GAME;
}

//------------------------------------------------------------------------------
// Address: 0x10197750
// Name: void HostState_LoadGame(char const __near *,bool,bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl HostState_LoadGame(const char *pSaveFileName, bool remember_location, bool bLetToolsOverrideLoadGameEnts)
{
  if ( saverestore->SaveFileExists(this: saverestore, a2: pSaveFileName) )
  {
    V_strncpy(pDest: g_HostState.m_saveName, pSrc: pSaveFileName, maxLen: 256);
    serverGameDLL->PreSaveGameLoaded(this: serverGameDLL, a2: pSaveFileName, a3: sv.m_State >= ss_active);
    g_HostState.m_bRememberLocation = remember_location;
    *(_WORD *)&g_HostState.m_bBackgroundLevel = 256;
    g_HostState.m_bSplitScreenConnect = false;
    g_HostState.m_bLetToolsOverrideLoadGameEnts = bLetToolsOverrideLoadGameEnts;
    if ( remember_location )
      CHostState::RememberLocation(this: &g_HostState);
    g_HostState.m_nextState = HS_LOAD_GAME;
  }
  else
  {
    _Warning(a1: "Save file %s can't be found!\n", pSaveFileName);
    SCR_EndLoadingPlaque();
  }
}

//------------------------------------------------------------------------------
// Address: 0x101977F0
// Name: void HostState_ChangeLevelSP(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl HostState_ChangeLevelSP(const char *pNewLevel, const char *pLandmarkName)
{
  V_strncpy(pDest: g_HostState.m_levelName, pSrc: pNewLevel, maxLen: 256);
  V_strncpy(pDest: g_HostState.m_landmarkName, pSrc: pLandmarkName, maxLen: 256);
  g_HostState.m_nextState = HS_CHANGE_LEVEL_SP;
}

//------------------------------------------------------------------------------
// Address: 0x10197830
// Name: void HostState_ChangeLevelMP(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl HostState_ChangeLevelMP(const char *pNewLevel, const char *pLandmarkName)
{
  CSteam3Server *v2; // eax

  v2 = Steam3Server();
  CSteam3Server::NotifyOfLevelChange(this: v2);
  V_strncpy(pDest: g_HostState.m_levelName, pSrc: pNewLevel, maxLen: 256);
  V_strncpy(pDest: g_HostState.m_landmarkName, pSrc: pLandmarkName, maxLen: 256);
  g_HostState.m_nextState = HS_CHANGE_LEVEL_MP;
}

//------------------------------------------------------------------------------
// Address: 0x101978B0
// Name: void HostState_Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl HostState_Shutdown()
{
  g_HostState.m_nextState = HS_SHUTDOWN;
}

//------------------------------------------------------------------------------
// Address: 0x101978C0
// Name: void HostState_Restart(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl HostState_Restart()
{
  g_HostState.m_nextState = HS_RESTART;
}

//------------------------------------------------------------------------------
// Address: 0x101978D0
// Name: bool HostState_IsGameShuttingDown(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl HostState_IsGameShuttingDown()
{
  return g_HostState.m_currentState == HS_GAME_SHUTDOWN || g_HostState.m_nextState == HS_GAME_SHUTDOWN;
}

//------------------------------------------------------------------------------
// Address: 0x101978F0
// Name: void HostState_OnClientDisconnected(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl HostState_OnClientDisconnected()
{
  vgui::PropertyPage *v0; // ecx

  materials->OnDebugEvent(this: materials, a2: "CHostState::OnClientDisconnected");
  if ( !sv.m_bIsDedicated )
    CColorBalanceUIPanel::Init(this: v0);
}

//------------------------------------------------------------------------------
// Address: 0x10197920
// Name: public: void CHostState::Init(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHostState::Init(CHostState *this)
{
  if ( this->m_nextState != HS_SHUTDOWN )
  {
    this->m_currentState = HS_RUN;
    this->m_nextState = HS_RUN;
  }
  this->m_levelName[0] = 0;
  this->m_saveName[0] = 0;
  this->m_landmarkName[0] = 0;
  *(_WORD *)&this->m_activeGame = 0;
  this->m_bBackgroundLevel = false;
  *(_WORD *)&this->m_bLetToolsOverrideLoadGameEnts = 0;
  this->m_vecLocation.x = 0.0;
  this->m_vecLocation.y = 0.0;
  this->m_vecLocation.z = 0.0;
  this->m_angLocation.x = 0.0;
  this->m_angLocation.y = 0.0;
  this->m_angLocation.z = 0.0;
  this->m_bWaitingForConnection = false;
  this->m_flShortFrameTime = 1.0;
  this->m_bGameHasShutDownAndFlushedMemory = true;
}

//------------------------------------------------------------------------------
// Address: 0x101979A0
// Name: public: void CHostState::State_NewGame(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHostState::State_NewGame(CHostState *this)
{
  bool m_bSplitScreenConnect; // al
  void (__thiscall *OnDebugEvent)(IMaterialSystem *, const char *); // edx
  bool bSplitScreenConnect; // [esp+8h] [ebp-4h]

  m_bSplitScreenConnect = this->m_bSplitScreenConnect;
  this->m_bSplitScreenConnect = false;
  bSplitScreenConnect = m_bSplitScreenConnect;
  materials->OnDebugEvent(this: materials, a2: "CHostState::State_NewGame");
  if ( serverGameClients != nullptr || (SV_InitGameDLL(), serverGameClients != nullptr) )
  {
    if ( modelloader->Map_IsValid(this: modelloader, a2: this->m_levelName, a3: false)
      && Host_NewGame(
           mapName: this->m_levelName,
           loadGame: false,
           bBackgroundLevel: this->m_bBackgroundLevel,
           bSplitScreenConnect,
           pszOldMap: nullptr,
           pszLandmark: nullptr) )
    {
      this->m_currentState = HS_RUN;
      this->m_nextState = HS_RUN;
      return;
    }
  }
  else
  {
    _Warning(a1: "Can't start game, no valid server.dll loaded\n");
  }
  SCR_EndLoadingPlaque();
  OnDebugEvent = materials->OnDebugEvent;
  if ( this->m_activeGame )
  {
    ((void (__stdcall *)(const char *))OnDebugEvent)(a1: "HostState::GameShutdown(active)");
    serverGameDLL->GameShutdown(this: serverGameDLL);
    this->m_activeGame = false;
  }
  else
  {
    ((void (__stdcall *)(const char *))OnDebugEvent)(a1: "HostState::GameShutdown");
  }
  this->m_currentState = HS_RUN;
  this->m_nextState = HS_RUN;
  CBaseServer::ClearReservationStatus(this: &sv);
}

//------------------------------------------------------------------------------
// Address: 0x10197AA0
// Name: public: void CHostState::State_LoadGame(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHostState::State_LoadGame(CHostState *this)
{
  void (__thiscall *OnDebugEvent)(IMaterialSystem *, const char *); // eax

  materials->OnDebugEvent(this: materials, a2: "CHostState::State_LoadGame");
  materials->OnDebugEvent(this: materials, a2: "CHostState::RunGameInit");
  if ( serverGameDLL != nullptr )
    serverGameDLL->GameInit(this: serverGameDLL);
  g_HostState.m_activeGame = true;
  g_ServerGlobalVariables.bMapLoadFailed = false;
  if ( ((unsigned __int8 (__stdcall *)(char *, bool))saverestore->LoadGame)(
         a1: this->m_saveName,
         a2: this->m_bLetToolsOverrideLoadGameEnts) != 0 )
  {
    CTestScriptMgr::CheckPoint(this: &g_TestScriptMgr, pName: "load_game");
    this->m_currentState = HS_RUN;
    this->m_nextState = HS_RUN;
  }
  else
  {
    SCR_EndLoadingPlaque();
    OnDebugEvent = materials->OnDebugEvent;
    if ( this->m_activeGame )
    {
      ((void (__stdcall *)(const char *))OnDebugEvent)(a1: "HostState::GameShutdown(active)");
      serverGameDLL->GameShutdown(this: serverGameDLL);
      this->m_activeGame = false;
    }
    else
    {
      ((void (__stdcall *)(const char *))OnDebugEvent)(a1: "HostState::GameShutdown");
    }
    this->m_currentState = HS_RUN;
    this->m_nextState = HS_RUN;
    if ( g_pMatchFramework->GetMatchSession(this: g_pMatchFramework) != nullptr )
      g_pMatchFramework->CloseSession(this: g_pMatchFramework);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10197B90
// Name: public: void CHostState::State_ChangeLevelMP(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CHostState::State_ChangeLevelMP(CHostState *this@<ecx>, int a2@<ebx>)
{
  CSteam3Server *v3; // eax
  IEngineVGuiInternal *v4; // eax

  materials->OnDebugEvent(this: materials, a2: "CHostState::State_ChangeLevelMP");
  v3 = Steam3Server();
  CSteam3Server::NotifyOfLevelChange(this: v3);
  g_pServerPluginHandler->LevelShutdown(this: g_pServerPluginHandler);
  audiosourcecache->LevelShutdown(this: audiosourcecache);
  if ( modelloader->Map_IsValid(this: modelloader, a2: this->m_levelName, a3: false) )
  {
    v4 = EngineVGui();
    v4->EnabledProgressBarForNextLoad(this: v4);
    Host_Changelevel(
      a1: a2,
      a2: (int)this->m_levelName,
      loadfromsavedgame: false,
      mapname: this->m_levelName,
      start: this->m_landmarkName);
  }
  else
  {
    ConMsg(a1: "Unable to change level!\n");
  }
  this->m_nextState = HS_RUN;
  this->m_currentState = HS_RUN;
}

//------------------------------------------------------------------------------
// Address: 0x10197C40
// Name: public: void CHostState::State_ChangeLevelSP(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CHostState::State_ChangeLevelSP(CHostState *this@<ecx>, int a2@<ebx>)
{
  materials->OnDebugEvent(this: materials, a2: "CHostState::State_ChangeLevelSP");
  if ( modelloader->Map_IsValid(this: modelloader, a2: this->m_levelName, a3: false) )
    Host_Changelevel(
      a1: a2,
      a2: (int)this->m_levelName,
      loadfromsavedgame: true,
      mapname: this->m_levelName,
      start: this->m_landmarkName);
  else
    ConMsg(a1: "Unable to change level!\n");
  this->m_nextState = HS_RUN;
  this->m_currentState = HS_RUN;
}

//------------------------------------------------------------------------------
// Address: 0x10197CB0
// Name: public: void CHostState::State_GameShutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHostState::State_GameShutdown(CHostState *this)
{
  CSteam3Server *v2; // eax
  void (__thiscall *OnDebugEvent)(IMaterialSystem *, const char *); // edx
  CEngineRecipientFilter *v4; // eax
  HOSTSTATES m_nextState; // eax

  materials->OnDebugEvent(this: materials, a2: "CHostState::State_GameShutdown");
  if ( serverGameDLL != nullptr )
  {
    v2 = Steam3Server();
    CSteam3Server::NotifyOfLevelChange(this: v2);
    g_pServerPluginHandler->LevelShutdown(this: g_pServerPluginHandler);
    audiosourcecache->LevelShutdown(this: audiosourcecache);
  }
  OnDebugEvent = materials->OnDebugEvent;
  if ( this->m_activeGame )
  {
    ((void (__stdcall *)(const char *))OnDebugEvent)(a1: "HostState::GameShutdown(active)");
    serverGameDLL->GameShutdown(this: serverGameDLL);
    this->m_activeGame = false;
  }
  else
  {
    ((void (__stdcall *)(const char *))OnDebugEvent)(a1: "HostState::GameShutdown");
  }
  saverestore->ClearSaveDir(this: saverestore);
  Host_ShutdownServer(a1: (int)this);
  v4 = (CEngineRecipientFilter *)MapReslistGenerator();
  CEngineRecipientFilter::MakeReliable(this: v4);
  m_nextState = this->m_nextState;
  switch ( m_nextState )
  {
    case HS_NEW_GAME:
    case HS_LOAD_GAME:
    case HS_SHUTDOWN:
    case HS_RESTART:
      this->m_currentState = m_nextState;
      break;
    default:
      this->m_currentState = HS_RUN;
      this->m_nextState = HS_RUN;
      break;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10197D90
// Name: public: void CHostState::OnClientConnected(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CHostState::OnClientConnected(CHostState *this@<ecx>, int a2@<ebx>, int a3@<edi>)
{
  bool v4; // zf
  vgui::CTreeViewListControl *v5; // ecx
  ECommandTarget_t TraceType; // eax
  vgui::CTreeViewListControl *v7; // ecx
  ECommandTarget_t v8; // eax
  vgui::CTreeViewListControl *v9; // ecx
  ECommandTarget_t v10; // eax
  int v11; // eax
  vgui::PropertyPage *v12; // ecx
  void *v13; // ebx
  int i; // esi
  const char *CounterName; // ebx
  vgui::CTreeViewListControl *v16; // ecx
  ECommandTarget_t v17; // eax
  double z; // [esp+1Ch] [ebp-20h]
  const char *v19; // [esp+20h] [ebp-1Ch]
  const char *v20; // [esp+20h] [ebp-1Ch]
  int v21; // [esp+2Ch] [ebp-10h]
  int v22; // [esp+30h] [ebp-Ch]
  float v23; // [esp+30h] [ebp-Ch]
  void *v24; // [esp+34h] [ebp-8h]
  float v25; // [esp+38h] [ebp-4h]

  ((void (__thiscall *)(IMaterialSystem *))materials->OnDebugEvent)(a1: materials);
  if ( this->m_bWaitingForConnection )
  {
    v4 = !this->m_bRememberLocation;
    this->m_bWaitingForConnection = false;
    if ( !v4 )
    {
      z = this->m_vecLocation.z;
      this->m_bRememberLocation = false;
      v19 = va(format: "setpos_exact %f %f %f\n", this->m_vecLocation.x, this->m_vecLocation.y, z);
      TraceType = CTraceFilter::GetTraceType(this: v5);
      Cbuf_AddText(eTarget: TraceType, pText: v19, nTickDelay: 0);
      v20 = va(format: "setang_exact %f %f %f\n", this->m_angLocation.x, this->m_angLocation.y, this->m_angLocation.z);
      v8 = CTraceFilter::GetTraceType(this: v7);
      Cbuf_AddText(eTarget: v8, pText: v20, nTickDelay: 0);
    }
    if ( reload_materials.m_pParent != nullptr && reload_materials.m_pParent->m_Value.m_nValue != 0 )
    {
      CLoaderMemAlloc::CrtIsValidPointer(
        this: (ConVar *)&reload_materials.IConVar,
        value: 0,
        a2: (unsigned int)"CHostState::OnClientConnected",
        a3: v21);
      v10 = CTraceFilter::GetTraceType(this: v9);
      Cbuf_AddText(eTarget: v10, pText: "mat_reloadallmaterials\n", nTickDelay: 0);
    }
    v11 = _CommandLine(a1: v22);
    if ( (*(int (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v11 + 12))(
           a1: v11,
           a2: "-dumpvidmemstats",
           a3: 0) != 0 )
    {
      v13 = (void *)((int (__thiscall *)(IBaseFileSystem *, const char *, const char *, _DWORD, int, int))g_pFileSystem->Open)(
                      a1: &g_pFileSystem->IBaseFileSystem,
                      a2: "vidmemstats.txt",
                      a3: "a",
                      a4: 0,
                      a5: a3,
                      a6: a2);
      v24 = v13;
      g_pFileSystem->FPrintf(this: g_pFileSystem, a2: v13, a3: "%s:\n", g_HostState.m_levelName);
      v25 = 0.0;
      for ( i = 0; i < CVProfile::GetNumCounters(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled); ++i )
      {
        if ( CVProfile::GetCounterGroup(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled, a2: i) == COUNTER_GROUP_TEXTURE_GLOBAL )
        {
          v23 = (float)(int)CVProfile::GetCounterValue(
                              this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
                              a2: i)
              * 0.00000095367432;
          v25 = v23 + v25;
          CounterName = CVProfile::GetCounterName(
                          this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
                          a2: i);
          if ( V_strnicmp(s1: CounterName, s2: "TexGroup_Global_", n: 16) == 0 )
            CounterName += 16;
          g_pFileSystem->FPrintf(this: g_pFileSystem, a2: v24, a3: "%s: %0.3fMB\n", CounterName, v23);
          v13 = v24;
        }
      }
      g_pFileSystem->FPrintf(this: g_pFileSystem, a2: v13, a3: "vidmem total: %0.3fMB\n", v25);
      g_pFileSystem->FPrintf(this: g_pFileSystem, a2: v13, a3: "---------------------------------\n");
      g_pFileSystem->Close(this: &g_pFileSystem->IBaseFileSystem, a2: v13);
      v17 = CTraceFilter::GetTraceType(this: v16);
      Cbuf_AddText(eTarget: v17, pText: "quit\n", nTickDelay: 0);
    }
    if ( !sv.m_bIsDedicated )
      CColorBalanceUIPanel::Init(this: v12);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10197FF0
// Name: void HostState_Init(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl HostState_Init()
{
  CHostState::Init(this: &g_HostState);
}

//------------------------------------------------------------------------------
// Address: 0x10198000
// Name: void HostState_OnClientConnected(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall HostState_OnClientConnected(int a1@<ebx>, int a2@<edi>)
{
  CHostState::OnClientConnected(this: &g_HostState, a2: a1, a3: a2);
}

//------------------------------------------------------------------------------
// Address: 0x10198010
// Name: IsClientActive
// Source: json
//------------------------------------------------------------------------------
bool __cdecl IsClientActive()
{
  int v1; // esi

  if ( sv.m_State < ss_active )
    return GetBaseLocalClient()->m_nSignonState == 6;
  v1 = 0;
  if ( sv.m_Clients.m_Size <= 0 )
    return false;
  while ( !sv.m_Clients.m_Memory.m_pMemory[v1]->IsActive(this: &sv.m_Clients.m_Memory.m_pMemory[v1]->IClient) )
  {
    if ( ++v1 >= sv.m_Clients.m_Size )
      return false;
  }
  return true;
}

//------------------------------------------------------------------------------
// Address: 0x10198060
// Name: IsClientConnected
// Source: json
//------------------------------------------------------------------------------
bool __cdecl IsClientConnected()
{
  int v1; // esi

  if ( sv.m_State < ss_active )
    return GetBaseLocalClient()->m_nSignonState >= 2;
  v1 = 0;
  if ( sv.m_Clients.m_Size <= 0 )
    return false;
  while ( !sv.m_Clients.m_Memory.m_pMemory[v1]->IsConnected(this: &sv.m_Clients.m_Memory.m_pMemory[v1]->IClient) )
  {
    if ( ++v1 >= sv.m_Clients.m_Size )
      return false;
  }
  return true;
}

//------------------------------------------------------------------------------
// Address: 0x101980C0
// Name: public: void CHostState::State_Run(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHostState::State_Run(CHostState *this, float frameTime)
{
  float m_flShortFrameTime; // xmm0_4
  float v4; // xmm0_4
  HOSTSTATES m_nextState; // eax

  if ( this->m_flShortFrameTime > 0.0 )
  {
    if ( IsClientActive() )
    {
      m_flShortFrameTime = this->m_flShortFrameTime;
      if ( m_flShortFrameTime <= frameTime )
        v4 = 0.0;
      else
        v4 = m_flShortFrameTime - frameTime;
      this->m_flShortFrameTime = v4;
    }
    if ( IsClientConnected() && host_state.interval_per_tick <= frameTime )
      frameTime = host_state.interval_per_tick;
  }
  if ( s_bFirstRunFrame )
    s_bFirstRunFrame = false;
  Host_RunFrame(time: frameTime);
  m_nextState = this->m_nextState;
  switch ( m_nextState )
  {
    case HS_NEW_GAME:
    case HS_LOAD_GAME:
      SCR_BeginLoadingPlaque(levelName: this->m_levelName);
      goto $LN3_40;
    case HS_CHANGE_LEVEL_SP:
    case HS_CHANGE_LEVEL_MP:
      this->m_currentState = m_nextState;
      break;
    case HS_RUN:
      return;
    case HS_GAME_SHUTDOWN:
    case HS_SHUTDOWN:
    case HS_RESTART:
$LN3_40:
      this->m_currentState = HS_GAME_SHUTDOWN;
      break;
    default:
      this->m_currentState = HS_RUN;
      this->m_nextState = HS_RUN;
      break;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101981A0
// Name: public: void CHostState::FrameUpdate(float)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CHostState::FrameUpdate(CHostState *this@<ecx>, int a2@<ebx>, int a3@<edi>, int a4@<esi>, float time)
{
  HOSTSTATES m_currentState; // edi
  _EXCEPTION_REGISTRATION_RECORD *frameTime; // [esp+4h] [ebp-Ch]
  int v7; // [esp+8h] [ebp-8h]
  CHostState *var4; // [esp+10h] [ebp+0h] BYREF

  if ( _setjmp3(a1: a2, a2: (int)&var4, a3, a4, a5: host_abortserver, a6: 0, a7: frameTime, a8: v7) != 0 )
  {
    CHostState::Init(this);
  }
  else
  {
    g_bAbortServerSet = true;
    do
    {
      m_currentState = this->m_currentState;
      switch ( this->m_currentState )
      {
        case HS_NEW_GAME:
          g_pMDLCache->BeginMapLoad(this: g_pMDLCache);
          CHostState::State_NewGame(this);
          break;
        case HS_LOAD_GAME:
          g_pMDLCache->BeginMapLoad(this: g_pMDLCache);
          CHostState::State_LoadGame(this);
          break;
        case HS_CHANGE_LEVEL_SP:
          g_pMDLCache->BeginMapLoad(this: g_pMDLCache);
          this->m_flShortFrameTime = 1.5;
          CHostState::State_ChangeLevelSP(this, a2);
          break;
        case HS_CHANGE_LEVEL_MP:
          g_pMDLCache->BeginMapLoad(this: g_pMDLCache);
          this->m_flShortFrameTime = 0.5;
          CHostState::State_ChangeLevelMP(this, a2);
          break;
        case HS_RUN:
          CHostState::State_Run(this, frameTime: time);
          break;
        case HS_GAME_SHUTDOWN:
          CHostState::State_GameShutdown(this);
          break;
        case HS_SHUTDOWN:
          CL_EndMovie();
          eng->SetNextState(this: eng, a2: DLL_CLOSE);
          break;
        case HS_RESTART:
          g_pMDLCache->BeginMapLoad(this: g_pMDLCache);
          CL_EndMovie();
          eng->SetNextState(this: eng, a2: DLL_CLOSE);
          eng->SetNextState(this: eng, a2: DLL_RESTART);
          break;
        default:
          break;
      }
    }
    while ( m_currentState != HS_RUN && m_currentState != HS_SHUTDOWN && m_currentState != HS_RESTART );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10198310
// Name: void HostState_Frame(float)
// Source: json
//------------------------------------------------------------------------------
void __usercall HostState_Frame(int a1@<ebx>, int a2@<edi>, int a3@<esi>, float time)
{
  CHostState::FrameUpdate(this: &g_HostState, a2: a1, a3: a2, a4: a3, time);
}

} // namespace engine_xlsp
