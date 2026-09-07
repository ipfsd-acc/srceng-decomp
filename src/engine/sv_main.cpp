// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: engine/sv_main.cpp
// Functions: 347
// ============================================================

#include "engine\sv_main.h"

//------------------------------------------------------------------------------
// Address: 0x100FFB10
// Name: public: virtual void CFunctor2<void (*)(struct msurface2_t __near *,class Vector),struct msurface2_t __near *,class Vector,class CRefCounted1<class CFunctor,class CRefCountServiceBase<1,class CRefMT>>>::operator()(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFunctor2<void (__cdecl *)(msurface2_t *,Vector),msurface2_t *,Vector,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>>::operator()(
        CFunctor2<void (__cdecl*)(msurface2_t *,Vector),msurface2_t *,Vector,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> > > *this)
{
  ((void (__cdecl *)(msurface2_t *, _DWORD, _DWORD, _DWORD))this->m_pfnProxied)(
    a1: this->m_arg1,
    a2: LODWORD(this->m_arg2.x),
    a3: LODWORD(this->m_arg2.y),
    a4: LODWORD(this->m_arg2.z));
}

//------------------------------------------------------------------------------
// Address: 0x10124040
// Name: void SV_ForceSend(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SV_ForceSend()
{
  s_bForceSend = true;
}

//------------------------------------------------------------------------------
// Address: 0x10124050
// Name: bool SV_FlushMemoryIfMarked(void)
// Source: json
//------------------------------------------------------------------------------
char __cdecl SV_FlushMemoryIfMarked()
{
  if ( g_bFlushMemoryOnNextServer )
  {
    g_bFlushMemoryOnNextServer = false;
    g_pDataCache->Flush(this: g_pDataCache, a2: true, a3: true);
    g_pMaterialSystem->CompactMemory(this: g_pMaterialSystem);
    g_pFileSystem->AsyncFinishAll(this: g_pFileSystem, a2: 0);
    CThreadMutex::Lock(this: &g_SndMutex);
    g_pFileSystem->AsyncSuspend(this: g_pFileSystem);
    _g_pThreadPool->SuspendExecution(this: _g_pThreadPool);
    _g_pMemAlloc->CompactHeap(this: _g_pMemAlloc);
    _g_pThreadPool->ResumeExecution(this: _g_pThreadPool);
    g_pFileSystem->AsyncResume(this: g_pFileSystem);
    CThreadMutex::Unlock(this: &g_SndMutex);
    return 1;
  }
  else
  {
    _g_pMemAlloc->CompactHeap(this: _g_pMemAlloc);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10124110
// Name: void SV_InstallClientStringTableMirrors(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SV_InstallClientStringTableMirrors()
{
  int v0; // ebx
  INetworkStringTable *v1; // eax
  CAudioMixerWave *v2; // esi
  CNetworkStringTableContainer_vtbl *v3; // edi
  int v4; // eax
  int v5; // eax
  const char *v6; // eax
  int numTables; // [esp+4h] [ebp-4h]

  v0 = 0;
  numTables = networkStringTableContainerServer->GetNumTables(this: networkStringTableContainerServer);
  if ( numTables > 0 )
  {
    do
    {
      v1 = networkStringTableContainerServer->GetTable(this: networkStringTableContainerServer, a2: v0);
      v2 = (CAudioMixerWave *)v1;
      if ( v1 != nullptr )
      {
        v3 = networkStringTableContainerClient->__vftable;
        v4 = (int)v1->GetTableName(this: v1);
        v5 = (int)v3->FindTable(this: networkStringTableContainerClient, a2: (const char *)v4);
        if ( v5 != 0 )
        {
          CNetworkStringTable::SetMirrorTable(this: v2, delaySamples: v5);
        }
        else
        {
          v6 = (const char *)((int (__thiscall *)(CAudioMixerWave *))v2->MixDataToDevice)(a1: v2);
          DevMsg(a1: "SV_InstallClientStringTableMirrors! Missing client table \"%s\".\n ", v6);
        }
      }
      ++v0;
    }
    while ( v0 < numTables );
  }
}

//------------------------------------------------------------------------------
// Address: 0x101241A0
// Name: void SV_InitSendTables(class ServerClass __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SV_InitSendTables(ServerClass *pClasses)
{
  ServerClass *v1; // esi
  int i; // edi
  SendTable *pTables[1024]; // [esp+8h] [ebp-1000h] BYREF

  v1 = pClasses;
  for ( i = 0; v1 != nullptr; ++i )
  {
    if ( i >= 1024 )
      _Error(a1: "SV_BuildSendTablesArray: too many SendTables!");
    pTables[i] = v1->m_pTable;
    v1 = v1->m_pNext;
  }
  SendTable_Init(pTables, nTables: i);
}

//------------------------------------------------------------------------------
// Address: 0x10124200
// Name: void ServerDLL_Unload(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __cdecl ServerDLL_Unload()
{
  UnloadEntityDLLs();
}

//------------------------------------------------------------------------------
// Address: 0x10124210
// Name: void SV_ShutdownGameDLL(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SV_ShutdownGameDLL()
{
  CSteam3Server *v0; // eax

  if ( sv.dll_initialized )
  {
    serverGameDLL->GetAllServerClasses(this: serverGameDLL);
    SendTable_Term();
    CServerPlugin::UnloadPlugins(this: g_pServerPluginHandler);
    serverGameDLL->DLLShutdown(this: serverGameDLL);
    UnloadEntityDLLs();
    sv.dll_initialized = false;
    v0 = Steam3Server();
    CSteam3Server::Shutdown(this: v0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10124260
// Name: class ServerClass __near * SV_FindServerClass(int)
// Source: json
//------------------------------------------------------------------------------
ServerClass *__cdecl SV_FindServerClass(int index)
{
  ServerClass *result; // eax
  int i; // ecx

  result = serverGameDLL->GetAllServerClasses(this: serverGameDLL);
  for ( i = 0; i < index; ++i )
  {
    if ( result == nullptr )
      break;
    result = result->m_pNext;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10124290
// Name: public: virtual void CGameServer::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameServer::Shutdown(CGameServer *this)
{
  IGameEvent *v2; // esi
  IGameEvent *v3; // esi

  this->m_bIsLevelMainMenuBackground = false;
  v2 = g_GameEventManager->CreateEventA(this: g_GameEventManager, a2: "server_pre_shutdown", a3: 0, a4: 0);
  if ( v2 != nullptr )
  {
    v2->SetString(this: v2, a2: "reason", a3: "quit");
    g_GameEventManager->FireEvent(this: g_GameEventManager, a2: v2, a3: false);
  }
  CBaseServer::Shutdown(this);
  framesnapshotmanager->LevelChanged(this: framesnapshotmanager);
  v3 = g_GameEventManager->CreateEventA(this: g_GameEventManager, a2: "server_shutdown", a3: 0, a4: 0);
  if ( v3 != nullptr )
  {
    v3->SetString(this: v3, a2: "reason", a3: "quit");
    g_GameEventManager->FireEvent(this: g_GameEventManager, a2: v3, a3: false);
  }
  CLog::Close(this: &g_Log);
}

//------------------------------------------------------------------------------
// Address: 0x10124340
// Name: public: virtual void CGameServer::RemoveClientFromGame(class CBaseClient __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameServer::RemoveClientFromGame(CGameServer *this, CBaseClient *client)
{
  if ( *(_DWORD *)client[1].m_GUID != 0 && client->IsSpawned(this: &client->IClient) && this->IsActive(this) )
  {
    g_pServerPluginHandler->ClientDisconnect(this: g_pServerPluginHandler, a2: *(edict_t **)client[1].m_GUID);
    serverGameEnts->FreeContainingEntity(this: serverGameEnts, a2: *(edict_t **)client[1].m_GUID);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101243A0
// Name: protected: virtual class CBaseClient __near * CGameServer::CreateNewClient(int)
// Source: json
//------------------------------------------------------------------------------
CGameClient *__thiscall CGameServer::CreateNewClient(CGameServer *this, int slot)
{
  CGameClient *v3; // eax
  CGameClient *v4; // esi
  int v5; // eax
  int v6; // eax
  const char *pszValue; // [esp+4h] [ebp-4h] BYREF

  v3 = (CGameClient *)MemAlloc_Alloc(nSize: 0x21AF0u);
  if ( v3 != nullptr )
    v4 = CGameClient::CGameClient(this: v3, slot, pServer: this);
  else
    v4 = nullptr;
  pszValue = nullptr;
  if ( v4 != nullptr )
  {
    v5 = _CommandLine();
    if ( (*(int (__thiscall **)(int, const char *, const char **))(*(_DWORD *)v5 + 12))(
           a1: v5,
           a2: "-netspike",
           a3: &pszValue) != 0
      && pszValue != nullptr )
    {
      v6 = V_atoi(str: pszValue);
      CBaseClient::SetTraceThreshold(this: v4, nThreshold: v6);
    }
  }
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x10124420
// Name: SV_AddToFatPVS
// Source: json
//------------------------------------------------------------------------------
void __cdecl SV_AddToFatPVS(int nClusterIndex)
{
  int v1; // edx
  unsigned __int8 *v2; // edi
  int v3; // esi
  unsigned int v4; // ecx
  unsigned __int8 *v5; // eax
  unsigned __int8 *v6; // eax
  int v7; // esi
  unsigned __int8 dest[8192]; // [esp+8h] [ebp-2000h] BYREF

  CM_Vis(dest, destlen: 0x2000, cluster: nClusterIndex, visType: 0);
  v1 = s_FatBytes;
  v2 = s_pFatPVS;
  v3 = 0;
  if ( s_FatBytes >= 0 && (s_FatBytes & 0xFFFFFFFC) != 0 )
  {
    v4 = (((s_FatBytes & 0xFFFFFFFC) - 1) >> 2) + 1;
    v5 = s_pFatPVS;
    v3 = 4 * v4;
    do
    {
      *(_DWORD *)v5 |= *(_DWORD *)&v5[dest - v2];
      v5 += 4;
      --v4;
    }
    while ( v4 != 0 );
    v1 = s_FatBytes;
  }
  if ( v3 < v1 )
  {
    v6 = &v2[v3];
    v7 = v1 - v3;
    do
    {
      *v6 |= v6[dest - v2];
      ++v6;
      --v7;
    }
    while ( v7 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x101244B0
// Name: public: bool CGameServer::IsInPureServerMode(void)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CGameServer::IsInPureServerMode(CGameServer *this)
{
  return this->m_pPureServerWhitelist != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x101244C0
// Name: public: bool CGameServer::IsHibernating(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CGameServer::IsHibernating(CGameServer *this)
{
  return this->m_bHibernating;
}

//------------------------------------------------------------------------------
// Address: 0x101244D0
// Name: sv_ShutDown
// Source: json
//------------------------------------------------------------------------------
void __cdecl sv_ShutDown()
{
  s_bExitWhenEmpty = true;
  if ( sv.m_bHibernating )
  {
    _Warning(a1: "Server is hibernating. Shutting down right now\n");
    HostState_Shutdown();
  }
}

//------------------------------------------------------------------------------
// Address: 0x10124500
// Name: void SV_ParallelSendSnapshot(class CGameClient __near * __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SV_ParallelSendSnapshot(CGameClient **pClient)
{
  CClientFrame *SendFrame; // eax

  SendFrame = CGameClient::GetSendFrame(this: *pClient);
  if ( SendFrame != nullptr )
  {
    (*pClient)->SendSnapshot(this: *pClient, a2: SendFrame);
    (*pClient)->UpdateSendState(this: *pClient);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10124530
// Name: void SV_FrameExecuteThreadDeferred(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SV_FrameExecuteThreadDeferred()
{
  if ( g_pDeferredServerWork != nullptr )
  {
    g_pDeferredServerWork->operator()(this: g_pDeferredServerWork);
    if ( g_pDeferredServerWork != nullptr )
      ((void (__thiscall *)(CFunctor *, int))g_pDeferredServerWork->dtr_CFunctor)(a1: g_pDeferredServerWork, a2: 1);
    g_pDeferredServerWork = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10124560
// Name: void SV_ProcessVoice(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SV_ProcessVoice()
{
  CColorBalanceUIPanel::Init(this: (vgui::PropertyPage *)&sv);
}

//------------------------------------------------------------------------------
// Address: 0x10124570
// Name: public: bool CSteamID::IsValid(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CSteamID::IsValid(CSteamID *this)
{
  int m_unAll64Bits_high; // esi
  unsigned int v2; // eax

  m_unAll64Bits_high = HIDWORD(this->m_steamid.m_unAll64Bits);
  v2 = ((unsigned int)m_unAll64Bits_high >> 20) & 0xF;
  return v2 != 0
      && v2 < 0xB
      && m_unAll64Bits_high >> 24 > 0
      && m_unAll64Bits_high >> 24 < 6
      && (v2 != 1 || this->m_steamid.m_comp != 0 && (m_unAll64Bits_high & 0xFFFFF) == 1)
      && (v2 != 7 || this->m_steamid.m_comp != 0 && (m_unAll64Bits_high & 0xFFFFF) == 0);
}

//------------------------------------------------------------------------------
// Address: 0x101245D0
// Name: public: virtual float CBaseServer::GetTickInterval(void)const
// Source: json
//------------------------------------------------------------------------------
double __thiscall CBaseServer::GetTickInterval(CBaseServer *this)
{
  return this->m_flTickInterval;
}

//------------------------------------------------------------------------------
// Address: 0x101245E0
// Name: public: bool CBaseServer::IsReserved(void)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CBaseServer::IsReserved(CBaseServer *this)
{
  return this->m_nReservationCookie != 0;
}

//------------------------------------------------------------------------------
// Address: 0x10124600
// Name: SV_CheatsChanged_f
// Source: json
//------------------------------------------------------------------------------
void __cdecl SV_CheatsChanged_f(IConVar *pConVar)
{
  ConVarRef var; // [esp+0h] [ebp-8h] BYREF

  ConVarRef::ConVarRef(this: &var, pConVar);
  if ( var.m_pConVarState->m_Value.m_nValue == 0 )
  {
    g_pCVar->RevertFlaggedConVars(this: g_pCVar, a2: 0x4000);
    DevMsg(a1: "FCVAR_CHEAT cvars reverted to defaults.\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x10124640
// Name: SV_Pure_f
// Source: json
//------------------------------------------------------------------------------
void __cdecl SV_Pure_f(const CCommand *args)
{
  unsigned int v1; // esi

  v1 = -1;
  if ( args->m_nArgc == 2 )
    v1 = atoi(nptr: args->m_ppArgv[1]);
  _Msg(a1: "--------------------------------------------------------\n");
  if ( v1 <= 2 )
  {
    if ( v1 == g_sv_pure_mode )
    {
      _Msg(a1: "sv_pure value unchanged (current value is %d).\n", g_sv_pure_mode);
    }
    else
    {
      g_sv_pure_mode = v1;
      _Msg(a1: "sv_pure set to %d.\n", v1);
      if ( sv.m_State >= ss_active )
        _Msg(a1: "Note: Changes to sv_pure take effect when the next map is loaded.\n");
    }
  }
  else
  {
    _Msg(
      a1: "sv_pure:\n"
      "\n"
      "If set to 1, the server will force all client files except the whitelisted ones (in pure_server_whitelist.txt) to "
      "match the server's files. \n"
      "\n"
      "If set to 2, the server will force all client files to come from Steam (and it will not load pure_server_whitelist.txt).\n");
  }
  if ( v1 == -1 )
  {
    if ( GetBaseLocalClient()->m_nSignonState >= 2 )
    {
      _Msg(a1: "\n\n");
      CL_PrintWhitelistInfo();
      _Msg(a1: "--------------------------------------------------------\n");
      return;
    }
    _Msg(a1: "\nCurrent sv_pure value is %d.\n", g_sv_pure_mode);
  }
  _Msg(a1: "--------------------------------------------------------\n");
}

//------------------------------------------------------------------------------
// Address: 0x10124710
// Name: bool ServerDLL_Load(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl ServerDLL_Load()
{
  LoadEntityDLLs(szBaseDir: host_parms.basedir);
  return g_ServerFactory != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10124730
// Name: class ServerClass __near * SV_FindServerClass(char const __near *)
// Source: json
//------------------------------------------------------------------------------
ServerClass *__cdecl SV_FindServerClass(const char *pName)
{
  ServerClass *v1; // esi

  v1 = serverGameDLL->GetAllServerClasses(this: serverGameDLL);
  if ( v1 == nullptr )
    return nullptr;
  while ( _V_stricmp(s1: v1->m_pNetworkName, s2: pName) != 0 )
  {
    v1 = v1->m_pNext;
    if ( v1 == nullptr )
      return nullptr;
  }
  return v1;
}

//------------------------------------------------------------------------------
// Address: 0x10124780
// Name: protected: void CGameServer::ReloadWhitelist(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameServer::ReloadWhitelist(CGameServer *this, const char *pMapName)
{
  CPureServerWhitelist *m_pPureServerWhitelist; // ecx
  CPureServerWhitelist *v4; // ecx
  CPureServerWhitelist *v5; // eax
  bool v6; // zf
  CStatTime *v7; // ecx
  KeyValues *v8; // eax
  KeyValues *v9; // esi
  IBaseFileSystem *v10; // eax
  IBaseFileSystem *v11; // eax
  int v12; // esi
  CStatTime *v13; // ecx
  double v14; // st7
  char testFilename[260]; // [esp+4h] [ebp-10Ch] BYREF
  double startTime; // [esp+108h] [ebp-8h]

  m_pPureServerWhitelist = this->m_pPureServerWhitelist;
  if ( m_pPureServerWhitelist != nullptr )
  {
    CPureServerWhitelist::Release(this: m_pPureServerWhitelist);
    this->m_pPureServerWhitelist = nullptr;
  }
  if ( this->GetMaxClients(this) > 1 )
  {
    v4 = this->m_pPureServerWhitelist;
    if ( v4 != nullptr )
    {
      CPureServerWhitelist::Release(this: v4);
      this->m_pPureServerWhitelist = nullptr;
    }
    if ( g_sv_pure_mode != 0 )
    {
      v5 = CPureServerWhitelist::Create(pFileSystem: g_pFileSystem);
      v6 = g_sv_pure_mode == 2;
      this->m_pPureServerWhitelist = v5;
      if ( v6 )
      {
        CPureServerWhitelist::EnableFullyPureMode(this: v5);
        _Msg(a1: "Server using sv_pure 2.\n");
      }
      else
      {
        v8 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
        if ( v8 != nullptr )
          v9 = KeyValues::KeyValues(this: v8, setName: defaultValue);
        else
          v9 = nullptr;
        if ( g_pFileSystem != nullptr )
          v10 = &g_pFileSystem->IBaseFileSystem;
        else
          v10 = nullptr;
        if ( !KeyValues::LoadFromFile(
                this: v9,
                filesystem: v10,
                resourceName: "pure_server_whitelist.txt",
                pathID: "game",
                pfnEvaluateSymbolProc: nullptr)
          || !CPureServerWhitelist::LoadFromKeyValues(this: this->m_pPureServerWhitelist, kv: v9) )
        {
          _Warning(a1: "Can't load pure server whitelist in %s.\n", "pure_server_whitelist.txt");
        }
        strcpy(testFilename, "maps");
        memset(dst: (unsigned __int8 *)&testFilename[5], value: 0, count: 0xFFu);
        V_AppendSlash(pStr: testFilename, strSize: 260);
        V_strncat(pDest: testFilename, pSrc: pMapName, destBufferSize: 0x104u, max_chars_to_copy: -1);
        V_strncat(pDest: testFilename, pSrc: "_whitelist.txt", destBufferSize: 0x104u, max_chars_to_copy: -1);
        KeyValues::Clear(this: v9);
        if ( g_pFileSystem != nullptr )
          v11 = &g_pFileSystem->IBaseFileSystem;
        else
          v11 = nullptr;
        if ( KeyValues::LoadFromFile(
               this: v9,
               filesystem: v11,
               resourceName: testFilename,
               pathID: nullptr,
               pfnEvaluateSymbolProc: nullptr) )
        {
          CPureServerWhitelist::LoadFromKeyValues(this: this->m_pPureServerWhitelist, kv: v9);
        }
        KeyValues::deleteThis(this: v9);
      }
      startTime = _Plat_FloatTime(this: v7);
      _Msg(a1: "Caching file CRCs for pure server...\n");
      v12 = g_pFileSystem->GetWhitelistSpewFlags(this: g_pFileSystem);
      if ( sv_pure_trace.m_pParent != nullptr && sv_pure_trace.m_pParent->m_Value.m_nValue > 0 )
        g_pFileSystem->SetWhitelistSpewFlags(this: g_pFileSystem, a2: v12 | 1);
      CPureServerWhitelist::CacheFileCRCs(this: this->m_pPureServerWhitelist);
      ((void (__thiscall *)(IFileSystem *))g_pFileSystem->SetWhitelistSpewFlags)(a1: g_pFileSystem);
      v14 = _Plat_FloatTime(this: v13);
      _Msg(a1: "Finished caching file CRCs for pure server in %d seconds.\n", (int)(v14 - startTime));
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101249C0
// Name: public: void CGameServer::ExecGameTypeCfg(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameServer::ExecGameTypeCfg(CGameServer *this, const char *mapname)
{
  KeyValues *v3; // eax
  KeyValues *v4; // esi
  int Int; // eax

  v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v3 != nullptr )
    v4 = KeyValues::KeyValues(this: v3, setName: "::ExecGameTypeCfg");
  else
    v4 = nullptr;
  KeyValues::SetString(this: v4, keyName: "map/mapname", value: mapname);
  serverGameDLL->ApplyGameSettings(this: serverGameDLL, a2: v4);
  Int = KeyValues::GetInt(this: v4, keyName: "members/numSlots", defaultValue: -1);
  if ( Int >= 0 )
    this->m_numGameSlots = Int;
  if ( v4 != nullptr )
    KeyValues::deleteThis(this: v4);
}

//------------------------------------------------------------------------------
// Address: 0x10124A40
// Name: bool SV_IsSimulating(void)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl SV_IsSimulating()
{
  bool result; // al
  IEngineVGuiInternal *v1; // eax

  result = false;
  if ( sv.m_State != ss_paused )
  {
    if ( sv.m_nMaxclients > 1 )
      return true;
    if ( !g_LostVideoMemory )
    {
      if ( GetBaseLocalClient()->m_nSignonState != 6 )
        return true;
      if ( !Con_IsVisible() )
      {
        v1 = EngineVGui();
        if ( !v1->ShouldPause(this: v1) )
          return true;
      }
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10124A90
// Name: void SV_Think(bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SV_Think(BOOL bIsSimulating)
{
  int m_nValue; // eax

  if ( !sv.m_bIsDedicated || (CBaseServer::UpdateReservedState(this: &sv), !sv.m_bHibernating) )
  {
    g_ServerGlobalVariables.tickcount = sv.m_nTickCount;
    g_ServerGlobalVariables.curtime = CBaseServer::GetTime(this: &sv);
    if ( bIsSimulating )
    {
      g_ServerGlobalVariables.frametime = host_state.interval_per_tick;
      if ( sv.m_nMaxclients > 1 || GetBaseLocalClient()->m_nSignonState == 6 )
      {
        LOBYTE(bIsSimulating) = 1;
LABEL_17:
        CDebugOverlay::PurgeServerOverlays();
        g_pServerPluginHandler->GameFrame(this: g_pServerPluginHandler, a2: bIsSimulating);
        return;
      }
    }
    else
    {
      g_ServerGlobalVariables.frametime = 0.0;
    }
    LOBYTE(bIsSimulating) = 0;
    goto LABEL_17;
  }
  if ( sv_hibernate_ms.m_pParent != nullptr )
    m_nValue = sv_hibernate_ms.m_pParent->m_Value.m_nValue;
  else
    m_nValue = 0;
  if ( g_bIsVGuiBasedDedicatedServer )
  {
    if ( sv_hibernate_ms_vgui.m_pParent != nullptr )
    {
      NET_SleepUntilMessages(nMilliseconds: sv_hibernate_ms_vgui.m_pParent->m_Value.m_nValue);
      return;
    }
    m_nValue = 0;
  }
  NET_SleepUntilMessages(nMilliseconds: m_nValue);
}

//------------------------------------------------------------------------------
// Address: 0x10124B60
// Name: public: void CUtlMemory<unsigned char,int>::EnsureCapacity(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<unsigned char,int>::EnsureCapacity(CUtlMemory<unsigned char,int> *this, int num)
{
  unsigned __int8 *m_pMemory; // eax

  if ( this->m_nAllocationCount < num && this->m_nGrowSize >= 0 )
  {
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = num;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (unsigned __int8 *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: num);
    else
      this->m_pMemory = (unsigned __int8 *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: num);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10124C20
// Name: public: void CGameServer::InitMaxClients(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameServer::InitMaxClients(CGameServer *this)
{
  int v2; // eax
  int v3; // edx
  int v4; // eax
  int v5; // eax
  int m_nMinClientsLimit; // ecx
  int m_nMaxClientsLimit; // ecx
  int v8; // edi
  int defaultmaxplayers; // [esp+Ch] [ebp-Ch] BYREF
  int maxmaxplayers; // [esp+10h] [ebp-8h] BYREF
  int minmaxplayers; // [esp+14h] [ebp-4h] BYREF

  v2 = 1;
  v3 = 64;
  minmaxplayers = 1;
  maxmaxplayers = 64;
  defaultmaxplayers = 1;
  if ( serverGameClients == nullptr )
    goto LABEL_12;
  serverGameClients->GetPlayerLimits(
    this: serverGameClients,
    a2: &minmaxplayers,
    a3: &maxmaxplayers,
    a4: &defaultmaxplayers);
  v2 = minmaxplayers;
  if ( minmaxplayers >= 1 )
  {
    if ( defaultmaxplayers >= 1 )
      goto LABEL_7;
    Sys_Error(error: "GetPlayerLimits:  default maxplayers must be >= 1 (%i)", minmaxplayers);
  }
  else
  {
    Sys_Error(error: "GetPlayerLimits:  min maxplayers must be >= 1 (%i)", minmaxplayers);
  }
  v2 = minmaxplayers;
LABEL_7:
  v3 = maxmaxplayers;
  if ( v2 > maxmaxplayers || defaultmaxplayers > maxmaxplayers )
  {
    Sys_Error(error: "GetPlayerLimits:  min maxplayers %i > max %i", v2, maxmaxplayers);
    v2 = minmaxplayers;
    v3 = maxmaxplayers;
  }
  if ( v3 > 64 )
  {
    Sys_Error(error: "GetPlayerLimits:  max players limited to %i", 64);
    v2 = minmaxplayers;
    v3 = maxmaxplayers;
  }
LABEL_12:
  this->m_nMinClientsLimit = v2;
  this->m_nMaxClientsLimit = v3;
  v4 = _CommandLine();
  v5 = (*(int (__thiscall **)(int, const char *, int))(*(_DWORD *)v4 + 28))(a1: v4, a2: "-maxplayers", a3: -1);
  if ( tv_enable.m_pParent != nullptr && tv_enable.m_pParent->m_Value.m_nValue != 0 )
  {
    ++v5;
    ++this->m_nMaxClientsLimit;
  }
  if ( v5 < 1 )
  {
    v5 = defaultmaxplayers;
  }
  else
  {
    if ( v5 >= maxmaxplayers )
      v5 = maxmaxplayers;
    m_nMinClientsLimit = this->m_nMinClientsLimit;
    if ( m_nMinClientsLimit <= v5 )
      m_nMinClientsLimit = v5;
    this->m_nMaxClientsLimit = m_nMinClientsLimit;
  }
  m_nMaxClientsLimit = this->m_nMinClientsLimit;
  if ( v5 < m_nMaxClientsLimit || (m_nMaxClientsLimit = this->m_nMaxClientsLimit, v5 > m_nMaxClientsLimit) )
    v5 = m_nMaxClientsLimit;
  v8 = v5;
  if ( (CL_IsHL2Demo() || CL_IsPortalDemo()) && !this->IsDedicated(this) )
  {
    v8 = 1;
    this->m_nMinClientsLimit = 1;
    this->m_nMaxClientsLimit = 1;
  }
  this->SetMaxClients(this, a2: v8);
}

//------------------------------------------------------------------------------
// Address: 0x10124D80
// Name: void SV_InitGameDLL(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall SV_InitGameDLL(int a1@<esi>)
{
  const char *ModDirectory; // eax
  const char *v2; // eax
  int v3; // esi
  const char *v4; // eax
  CSteam3Client *v5; // eax
  CSteam3Client *v6; // eax
  const char *v7; // eax
  int v8; // eax
  ServerClass *v9; // eax
  double v10; // st7
  double v11; // st5
  int v12; // eax
  int v13; // eax
  int max_splitscreen_players; // eax
  const char *m_pchGameDir; // [esp+10h] [ebp-Ch]

  _COM_TimestampedLog(a1: "SV_InitGameDLL");
  Cbuf_Execute();
  if ( sv.dll_initialized )
    return;
  if ( CL_IsHL2Demo() && !sv.m_bIsDedicated )
  {
    ModDirectory = COM_GetModDirectory();
    if ( _V_stricmp(s1: ModDirectory, s2: "hl2") != 0 )
    {
      _Error(a1: "The HL2 demo is unable to run Mods.\n");
      return;
    }
  }
  if ( CL_IsPortalDemo() && !sv.m_bIsDedicated )
  {
    v2 = COM_GetModDirectory();
    if ( _V_stricmp(s1: v2, s2: "portal") != 0 )
    {
      _Error(a1: "The Portal demo is unable to run Mods.\n");
      return;
    }
  }
  if ( Steam3Client()->m_pSteamApps == nullptr
    || !g_pFileSystem->IsSteam(this: g_pFileSystem)
    || CL_IsHL2Demo()
    || CL_IsPortalDemo() )
  {
LABEL_22:
    if ( serverGameDLL == nullptr )
    {
      _Warning(a1: "Failed to load server binary\n");
      return;
    }
    sv.dll_initialized = true;
    _COM_TimestampedLog(a1: "serverGameDLL->DLLInit - Start");
    if ( ((int (__thiscall *)(IServerGameDLL *, void *(__cdecl *)(const char *, int *), void *(__cdecl *)(const char *, int *), void *(__cdecl *)(const char *, int *), CGlobalVars *, int))serverGameDLL->DLLInit)(
           a1: serverGameDLL,
           a2: g_GameSystemFactory,
           a3: g_AppSystemFactory,
           a4: g_AppSystemFactory,
           a5: &g_ServerGlobalVariables,
           a6: a1) == 0 )
      Sys_Error(error: "serverGameDLL->DLLInit() failed.\n");
    _COM_TimestampedLog(a1: "serverGameDLL->DLLInit - Finish");
    v8 = _CommandLine();
    if ( (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v8 + 40))(a1: v8, a2: "-NoLoadPluginsForClient") == 0 )
      CServerPlugin::LoadPlugins(this: g_pServerPluginHandler);
    Host_EnsureHostNameSet();
    sv_noclipduringpause = g_pCVar->FindVar_2(this: g_pCVar, a2: "sv_noclipduringpause");
    _COM_TimestampedLog(a1: "SV_InitSendTables");
    v9 = serverGameDLL->GetAllServerClasses(this: serverGameDLL);
    SV_InitSendTables(pClasses: v9);
    v10 = ((double (__thiscall *)(IServerGameDLL *))serverGameDLL->GetTickInterval)(a1: serverGameDLL);
    host_state.interval_per_tick = v10;
    v11 = 0.1;
    if ( v10 >= 0.001 )
    {
      if ( v10 <= 0.1 )
      {
LABEL_32:
        v12 = serverGameClients->GetMaxSplitscreenPlayers(this: serverGameClients);
        if ( v12 >= 1 )
        {
          if ( v12 > 2 )
            v12 = 2;
        }
        else
        {
          v12 = 1;
        }
        host_state.max_splitscreen_players_clientdll = v12;
        host_state.max_splitscreen_players = v12;
        v13 = _CommandLine();
        if ( (*(int (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v13 + 12))(a1: v13, a2: "-tools", a3: 0) != 0 )
        {
          _Msg(a1: "Clamping split screen users to 1 due to -tools mode\n");
          max_splitscreen_players = 1;
          host_state.max_splitscreen_players = 1;
        }
        else
        {
          max_splitscreen_players = host_state.max_splitscreen_players;
          if ( host_state.max_splitscreen_players > 1 )
          {
            _Msg(a1: "Game supporting (%d) split screen players\n", host_state.max_splitscreen_players);
            max_splitscreen_players = host_state.max_splitscreen_players;
          }
        }
        g_pCVar->SetMaxSplitScreenSlots(this: g_pCVar, a2: max_splitscreen_players);
        CGameServer::InitMaxClients(this: &sv);
        Cbuf_Execute();
        return;
      }
      v11 = 0.1;
    }
    Sys_Error(error: "GetTickInterval returned bogus tick interval (%f)[%f to %f is valid range]", v10, 0.001, v11);
    goto LABEL_32;
  }
  v3 = 0;
  while ( 1 )
  {
    m_pchGameDir = g_ModDirPermissions[v3].m_pchGameDir;
    v4 = COM_GetModDirectory();
    if ( _V_stricmp(s1: v4, s2: m_pchGameDir) == 0 )
      break;
    if ( (unsigned int)++v3 >= 0xB )
    {
      v5 = Steam3Client();
      if ( v5->m_pSteamApps->BIsSubscribedApp(this: v5->m_pSteamApps, a2: 215u) )
        goto LABEL_22;
      _Error(a1: "A Source engine game is required to run mods\n");
      return;
    }
  }
  v6 = Steam3Client();
  if ( v6->m_pSteamApps->BIsSubscribedApp(this: v6->m_pSteamApps, a2: g_ModDirPermissions[v3].m_iAppID) )
    goto LABEL_22;
  v7 = COM_GetModDirectory();
  _Error(a1: "No permissions to run '%s'\n", v7);
}

//------------------------------------------------------------------------------
// Address: 0x10125080
// Name: public: virtual bool CGameServer::IsPausable(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CGameServer::IsPausable(CGameServer *this)
{
  if ( CBaseServer::IsSinglePlayerGame(this)
    || !NET_IsDedicated()
    && sv_pausable_dev.m_pParent != nullptr
    && sv_pausable_dev.m_pParent->m_Value.m_nValue != 0
    && developer.m_pParent != nullptr
    && developer.m_pParent->m_Value.m_nValue != 0
    && CBaseServer::IsPlayingSoloAgainstBots(this)
    || NET_IsDedicated()
    && sv_pausable_dev_ds.m_pParent != nullptr
    && sv_pausable_dev_ds.m_pParent->m_Value.m_nValue != 0
    && developer.m_pParent != nullptr
    && developer.m_pParent->m_Value.m_nValue != 0
    && CBaseServer::IsPlayingSoloAgainstBots(this) )
  {
    return true;
  }
  if ( sv_pausable.m_pParent != nullptr )
    return sv_pausable.m_pParent->m_Value.m_nValue != 0;
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x10125120
// Name: void SV_ExecuteRemoteCommand(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SV_ExecuteRemoteCommand(const char *pCommand, int nClientSlot)
{
  NET_StringCmd cmdMsg; // [esp+0h] [ebp-420h] BYREF
  CEngineSingleUserFilter filter; // [esp+414h] [ebp-Ch] BYREF

  if ( sv.m_State >= ss_active && sv.m_nMaxclients > 1 )
  {
    cmdMsg.m_szCommand = pCommand;
    cmdMsg.m_bReliable = true;
    cmdMsg.m_NetChannel = nullptr;
    cmdMsg.__vftable = (NET_StringCmd_vtbl *)&NET_StringCmd::`vftable';
    if ( nClientSlot < 0 )
    {
      CBaseServer::BroadcastMessage(this: &sv, msg: &cmdMsg, onlyActive: false, reliable: false);
    }
    else
    {
      filter.m_bReliable = true;
      filter.__vftable = (CEngineSingleUserFilter_vtbl *)&CEngineSingleUserFilter::`vftable';
      filter.m_nClientIndex = nClientSlot + 1;
      CBaseServer::BroadcastMessage(this: &sv, msg: &cmdMsg, &filter);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101251B0
// Name: void SV_ResetPVS(unsigned char __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SV_ResetPVS(unsigned __int8 *pvs, int nPVSSize)
{
  int v2; // eax

  s_pFatPVS = pvs;
  v2 = (CM_NumClusters() + 7) >> 3;
  s_FatBytes = v2;
  if ( v2 > nPVSSize )
  {
    Sys_Error(error: "SV_ResetPVS:  Size %i too big for buffer %i\n", v2, nPVSSize);
    v2 = s_FatBytes;
  }
  _V_memset(dest: s_pFatPVS, fill: 0, count: v2);
  g_ClustersNetworked.m_Size = 0;
  g_AreasNetworked.m_Size = 0;
}

//------------------------------------------------------------------------------
// Address: 0x10125210
// Name: private: void CGameServer::SetHibernating(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameServer::SetHibernating(CGameServer *this, bool bHibernating)
{
  const char *v3; // eax
  vgui::PropertyPage *v4; // ecx
  int i; // ebx
  CBaseClient *v6; // esi
  bool (__thiscall *IsFakeClient)(IClient *); // eax
  IClient *v8; // esi

  if ( this->m_bHibernating != bHibernating )
  {
    this->m_bHibernating = bHibernating;
    v3 = "Server is hibernating\n";
    if ( !bHibernating )
      v3 = "Server waking up from hibernation\n";
    _Msg(a1: v3);
    if ( this->m_bHibernating )
    {
      for ( i = 0; i < this->m_Clients.m_Size; ++i )
      {
        v6 = this->m_Clients.m_Memory.m_pMemory[i];
        IsFakeClient = v6->IsFakeClient;
        v8 = &v6->IClient;
        if ( IsFakeClient(this: v8) && v8->IsConnected(this: v8) && !v8->IsSplitScreenUser(this: v8) )
          v8->Disconnect(this: v8, a2: "Punting bot, server is hibernating");
      }
      if ( s_bExitWhenEmpty )
      {
        _Warning(a1: "Server shutting down because sv_shutdown was done and a game has ended.\n");
        HostState_Shutdown();
      }
      CColorBalanceUIPanel::Init(this: v4);
      CGameServer::ExecGameTypeCfg(this, mapname: this->m_szMapname);
      CBaseServer::SetReservationCookie(this, uiCookie: 0, pchReasonFormat: "SetHibernating(true)");
      this->m_flReservationExpiryTime = 0.0;
    }
    CBaseServer::UpdateGameType(this);
    Heartbeat_f();
    ((void (__stdcall *)(bool))serverGameDLL->ServerHibernationUpdate)(a1: this->m_bHibernating);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10125330
// Name: public: void CGameServer::UpdateHibernationState(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameServer::UpdateHibernationState(CGameServer *this)
{
  int v2; // ebx
  CBaseClient *v3; // esi
  bool (__thiscall *IsConnected)(IClient *); // eax
  IClient *v5; // esi
  char v6; // bl
  CStatTime *v7; // ecx
  float m_flReservationExpiryTime; // [esp+10h] [ebp-8h]
  char v9; // [esp+17h] [ebp-1h]

  if ( this->IsDedicated(this) )
  {
    v2 = 0;
    v9 = 0;
    if ( this->m_Clients.m_Size > 0 )
    {
      while ( 1 )
      {
        v3 = this->m_Clients.m_Memory.m_pMemory[v2];
        IsConnected = v3->IsConnected;
        v5 = &v3->IClient;
        if ( IsConnected(this: v5) && (v5->IsSplitScreenUser(this: v5) || !v5->IsFakeClient(this: v5)) )
          break;
        if ( ++v2 >= this->m_Clients.m_Size )
          goto LABEL_9;
      }
      v9 = 1;
    }
LABEL_9:
    v6 = 0;
    if ( v9 != 0 )
    {
      this->m_flTimeLastClientLeft = -1.0;
    }
    else
    {
      v7 = (CStatTime *)(HIDWORD(this->m_nReservationCookie) | LODWORD(this->m_nReservationCookie));
      if ( this->m_nReservationCookie != 0 )
      {
        if ( this->m_flTimeLastClientLeft == -1.0 )
          this->m_flTimeLastClientLeft = _Plat_FloatTime(this: v7);
        if ( _Plat_FloatTime(this: v7) - this->m_flTimeLastClientLeft > sv_hibernate_postgame_delay.m_pParent->m_Value.m_fValue )
          v6 = 1;
      }
    }
    if ( this->m_nReservationCookie != 0 && v9 == 0 && v6 != 0 )
    {
      m_flReservationExpiryTime = this->m_flReservationExpiryTime;
      if ( m_flReservationExpiryTime == 0.0 || net_time > m_flReservationExpiryTime )
        CBaseServer::SetReservationCookie(
          this,
          uiCookie: 0,
          pchReasonFormat: "reserved(%s), clients(%s), reservationexpires(%.2f)",
          "yes",
          "no",
          m_flReservationExpiryTime);
    }
    if ( sv_hibernate_when_empty.m_pParent != nullptr
      && sv_hibernate_when_empty.m_pParent->m_Value.m_nValue != 0
      && this->m_nReservationCookie == 0
      && v9 == (BYTE4(this->m_nReservationCookie) | LOBYTE(this->m_nReservationCookie)) )
    {
      CGameServer::SetHibernating(this, bHibernating: true);
    }
    else
    {
      CGameServer::SetHibernating(this, bHibernating: false);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101254C0
// Name: public: virtual void CGameServer::SetMaxClients(int)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __thiscall CGameServer::SetMaxClients(CGameServer *this, int number)
{
  int m_nMinClientsLimit; // eax

  m_nMinClientsLimit = this->m_nMinClientsLimit;
  if ( number >= m_nMinClientsLimit )
  {
    m_nMinClientsLimit = this->m_nMaxClientsLimit;
    if ( number <= m_nMinClientsLimit )
      m_nMinClientsLimit = number;
  }
  this->m_nMaxclients = m_nMinClientsLimit;
  if ( tv_enable.m_pParent != nullptr && tv_enable.m_pParent->m_Value.m_nValue != 0 )
    ConMsg(a1: "maxplayers set to %i (extra slot was added for SourceTV)\n", m_nMinClientsLimit);
  else
    ConMsg(a1: "maxplayers set to %i\n", m_nMinClientsLimit);
  CLoaderMemAlloc::CrtIsValidPointer(this: (ConVar *)&deathmatch.IConVar, value: this->m_nMaxclients > 1);
}

//------------------------------------------------------------------------------
// Address: 0x10125530
// Name: void SV_WriteVoiceCodec(class bf_write __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SV_WriteVoiceCodec(bf_write *pBuf)
{
  char *m_pszString; // eax
  SVC_VoiceInit voiceinit; // [esp+0h] [ebp-11Ch] BYREF

  if ( sv.m_nMaxclients <= 1 )
    goto LABEL_5;
  if ( (sv_voicecodec.m_nFlags & 0x1000) == 0 )
  {
    m_pszString = sv_voicecodec.m_pParent->m_Value.m_pszString;
    if ( m_pszString != nullptr )
      goto LABEL_6;
LABEL_5:
    m_pszString = (char *)defaultValue;
    goto LABEL_6;
  }
  m_pszString = "FCVAR_NEVER_AS_STRING";
LABEL_6:
  voiceinit.m_bReliable = true;
  voiceinit.m_NetChannel = nullptr;
  voiceinit.__vftable = (SVC_VoiceInit_vtbl *)&SVC_VoiceInit::`vftable';
  voiceinit.m_szVoiceCodec = m_pszString;
  voiceinit.m_nQuality = 5;
  SVC_VoiceInit::WriteToBuffer(this: &voiceinit, buffer: pBuf);
}

//------------------------------------------------------------------------------
// Address: 0x101255B0
// Name: void OnTVEnablehanged(class IConVar __near *,char const __near *,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl OnTVEnablehanged(IConVar *pConVar)
{
  ConVarRef var; // [esp+0h] [ebp-8h] BYREF

  ConVarRef::ConVarRef(this: &var, pConVar);
  if ( var.m_pConVarState->m_Value.m_nValue != 0 )
    CGameServer::InitMaxClients(this: &sv);
}

//------------------------------------------------------------------------------
// Address: 0x101255E0
// Name: user
// Source: json
//------------------------------------------------------------------------------
void __cdecl user(const CCommand *args)
{
  int v1; // edi
  CBaseClient *v2; // eax
  int v3; // esi
  const char *v4; // eax
  const char *v5; // [esp-10h] [ebp-14h]
  int uid; // [esp+0h] [ebp-4h]

  if ( sv.m_State >= ss_active )
  {
    if ( args->m_nArgc == 2 )
    {
      v1 = 0;
      uid = atoi(nptr: args->m_ppArgv[1]);
      if ( sv.m_Clients.m_Size <= 0 )
      {
LABEL_13:
        ConMsg(a1: "User not in server.\n");
      }
      else
      {
        while ( 1 )
        {
          v2 = sv.m_Clients.m_Memory.m_pMemory[v1];
          v3 = v2 != nullptr ? (int)&v2->IClient : 0;
          if ( (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v3 + 124))(a1: v3) != 0 )
          {
            if ( (*(int (__thiscall **)(int))(*(_DWORD *)v3 + 56))(a1: v3) == uid )
              break;
            v5 = CCommand::operator[](this: args, nIndex: 1);
            v4 = (const char *)(*(int (__thiscall **)(int))(*(_DWORD *)v3 + 68))(a1: v3);
            if ( _V_strcmp(s1: v4, s2: v5) == 0 )
              break;
          }
          if ( ++v1 >= sv.m_Clients.m_Size )
            goto LABEL_13;
        }
        ConMsg(a1: "TODO: SV_User_f.\n");
      }
    }
    else
    {
      ConMsg(a1: "Usage: user <username / userid>\n");
    }
  }
  else
  {
    ConMsg(a1: "Can't 'user', not running a server\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x101256D0
// Name: users
// Source: json
//------------------------------------------------------------------------------
void __cdecl users()
{
  int v0; // ebx
  int i; // edi
  CBaseClient *v2; // eax
  IClient *v3; // esi
  int v4; // eax
  int v5; // eax
  int v6; // eax
  int v7; // [esp-14h] [ebp-14h]
  const char *v8; // [esp-10h] [ebp-10h]

  if ( sv.m_State >= ss_active )
  {
    v0 = 0;
    ConMsg(a1: "<slot:userid:\"name\">\n");
    for ( i = 0; i < sv.m_Clients.m_Size; ++i )
    {
      v2 = sv.m_Clients.m_Memory.m_pMemory[i];
      if ( v2 != nullptr )
        v3 = &v2->IClient;
      else
        v3 = nullptr;
      if ( v3->IsConnected(this: v3) )
      {
        v4 = (int)v3->GetClientName(this: v3);
        v5 = ((int (__thiscall *)(IClient *, int))v3->GetUserID)(a1: v3, a2: v4);
        v6 = ((int (__thiscall *)(IClient *, int))v3->GetPlayerSlot)(a1: v3, a2: v5);
        ConMsg(a1: "%i:%i:\"%s\"\n", v6, v7, v8);
        ++v0;
      }
    }
    ConMsg(a1: "%i users\n", v0);
  }
  else
  {
    ConMsg(a1: "Can't 'users', not running a server\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x10125770
// Name: maxplayers
// Source: json
//------------------------------------------------------------------------------
void __cdecl maxplayers(int args)
{
  int MaxClients; // eax
  int v2; // eax
  int defaultmaxplayers; // [esp+0h] [ebp-8h] BYREF
  int maxmaxplayers; // [esp+4h] [ebp-4h] BYREF

  if ( *(_DWORD *)args == 2 )
  {
    if ( sv.m_State < ss_active )
    {
      v2 = V_atoi(str: *(const char **)(args + 1036));
      CGameServer::SetMaxClients(this: &sv, number: v2);
    }
    else
    {
      ConMsg(a1: "Cannot change maxplayers while the server is running\n");
    }
  }
  else
  {
    MaxClients = CBaseServer::GetMaxClients(this: &sv);
    ConMsg(a1: "\"maxplayers\" is \"%u\"\n", MaxClients);
    if ( serverGameClients != nullptr )
    {
      args = 1;
      maxmaxplayers = 1;
      defaultmaxplayers = 1;
      serverGameClients->GetPlayerLimits(this: serverGameClients, a2: &args, a3: &maxmaxplayers, a4: &defaultmaxplayers);
      ConMsg(a1: "\"mininum_maxplayers\" is \"%u\"\n", args);
      ConMsg(a1: "\"absolute_maxplayers\" is \"%u\"\n", maxmaxplayers);
      ConMsg(a1: "\"default_maxplayers\" is \"%u\"\n", defaultmaxplayers);
      if ( toolframework->InToolMode(this: toolframework) )
        ConMsg(
          a1: "\"max_splitscreen_players\" is \"%u\" (limited by -tools mode)\n",
          host_state.max_splitscreen_players);
      else
        ConMsg(a1: "\"max_splitscreen_players\" is \"%u\"\n", host_state.max_splitscreen_players);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10125870
// Name: public: virtual void CGameServer::Init(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameServer::Init(CGameServer *this, bool isDedicated)
{
  CBaseServer::Init(this, bIsDedicated: isDedicated);
  CNetworkStringTable::SetTick(this: &this->m_FullSendTables, pDebugName: "m_FullSendTables");
  this->dll_initialized = false;
  if ( isDedicated )
    CGameServer::UpdateHibernationState(this);
}

//------------------------------------------------------------------------------
// Address: 0x101258B0
// Name: void SV_DetermineMulticastRecipients(bool,class Vector const __near &,class CBitVec<64> __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SV_DetermineMulticastRecipients(bool usepas, const Vector *origin, CBitVec<64> *playerbits)
{
  int v3; // eax
  int v4; // eax
  int v5; // edi
  CBaseClient *v6; // esi
  _DWORD *v7; // eax
  int v8; // eax
  int v9; // eax
  int v10; // eax
  unsigned __int8 dest[8192]; // [esp+8h] [ebp-200Ch] BYREF
  Vector v12; // [esp+2008h] [ebp-Ch] BYREF
  const unsigned __int8 *v13; // [esp+201Ch] [ebp+8h]

  v3 = CM_PointLeafnum(p: origin);
  v4 = CM_LeafCluster(leafnum: v3);
  v13 = CM_Vis(dest, destlen: 0x2000, cluster: v4, visType: usepas);
  if ( playerbits != nullptr )
  {
    playerbits->m_Ints[0] = 0;
    playerbits->m_Ints[1] = 0;
  }
  v5 = 0;
  if ( sv.m_Clients.m_Size > 0 )
  {
    while ( 1 )
    {
      v6 = sv.m_Clients.m_Memory.m_pMemory[v5];
      if ( v6->IsActive(this: &v6->IClient) )
      {
        v7 = *(_DWORD **)v6[1].m_GUID;
        if ( v7 == nullptr || (*v7 & 2) != 0 || v7[3] == 0 )
          goto LABEL_13;
        if ( v6->IsHLTV(this: &v6->IClient) )
          break;
        serverGameClients->ClientEarPosition(this: serverGameClients, a2: *(edict_t **)v6[1].m_GUID, a3: &v12);
        v8 = CM_PointLeafnum(p: &v12);
        v9 = CM_LeafCluster(leafnum: v8);
        if ( ((unsigned __int8)(1 << (v9 & 7)) & v13[v9 >> 3]) != 0 )
        {
          if ( !v6->IsSplitScreenUser(this: &v6->IClient) )
            break;
          v10 = v6->m_pAttachedTo->GetPlayerSlot(this: &v6->m_pAttachedTo->IClient);
          playerbits->m_Ints[v10 >> 5] |= 1 << (v10 & 0x1F);
        }
      }
LABEL_13:
      if ( ++v5 >= sv.m_Clients.m_Size )
        return;
    }
    playerbits->m_Ints[v5 >> 5] |= 1 << (v5 & 0x1F);
    goto LABEL_13;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10125A10
// Name: protected: virtual bool CGameServer::FinishCertificateCheck(struct netadr_s __near &,int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CGameServer::FinishCertificateCheck(
        CGameServer *this,
        netadr_s *adr,
        int nAuthProtocol,
        const char *szRawCertificate)
{
  int v6; // ebx
  CBaseClient *v7; // edi
  int nHashCount; // [esp+10h] [ebp+Ch]

  if ( nAuthProtocol == 2 )
  {
    if ( !UseCDKeyAuth() )
    {
      this->RejectConnection(this, a2: adr, a3: "#Valve_Reject_CD_Key_Auth_Invalid");
      return 0;
    }
    if ( _V_strlen(str: szRawCertificate) == 32 )
    {
      v6 = 0;
      nHashCount = 0;
      if ( this->GetClientCount(this) <= 0 )
        return 1;
      do
      {
        v7 = this->m_Clients.m_Memory.m_pMemory[v6];
        if ( v7->IsConnected(this: &v7->IClient) && V_strnicmp(s1: szRawCertificate, s2: v7->m_GUID, n: 32) == 0 )
          ++nHashCount;
        ++v6;
      }
      while ( v6 < this->GetClientCount(this) );
      if ( nHashCount < 5 )
      {
        return 1;
      }
      else
      {
        this->RejectConnection(this, a2: adr, a3: "#Valve_Reject_CD_Key_In_Use");
        return 0;
      }
    }
    else
    {
      this->RejectConnection(this, a2: adr, a3: "#Valve_Reject_Invalid_CD_Key");
      return 0;
    }
  }
  else
  {
    if ( nAuthProtocol != 3 )
    {
      this->RejectConnection(this, a2: adr, a3: "Authentication disabled!!!\n");
      return 0;
    }
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10125B10
// Name: public: void CGameServer::BroadcastSound(struct SoundInfo_t __near &,class IRecipientFilter __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameServer::BroadcastSound(CGameServer *this, SoundInfo_t *sound, IRecipientFilter *filter)
{
  CGameServer *v4; // edi
  int v5; // esi
  int v6; // esi
  CGameClient *v7; // esi
  bool v8; // al
  const char *v9; // edi
  bool v10; // zf
  const char *v11; // eax
  int num; // [esp+10h] [ebp-4h]
  int i; // [esp+20h] [ebp+Ch]

  v4 = this;
  v5 = filter->GetRecipientCount(this: filter);
  num = v5;
  if ( !v4->IsPaused(this: v4) || developer.m_pParent != nullptr && developer.m_pParent->m_Value.m_nValue != 0 )
  {
    i = 0;
    if ( v5 > 0 )
    {
      do
      {
        v6 = filter->GetRecipientIndex(this: filter, a2: i);
        if ( v6 < 1 || v6 > v4->GetClientCount(this: v4) )
        {
          v9 = "yes";
          if ( !filter->IsInitMessage(this: filter) )
            v9 = "no";
          v10 = !filter->IsReliable(this: filter);
          v11 = "yes";
          if ( v10 )
            v11 = "no";
          _Msg(
            a1: "CGameServer::BroadcastSound:  Recipient Filter for sound (reliable: %s, init: %s) with bogus client index (%"
            "i) in list of %i clients\n",
            v11,
            v9,
            v6,
            num);
          v4 = this;
        }
        else
        {
          v7 = (CGameClient *)v4->m_Clients.m_Memory.m_pMemory[v6 - 1];
          if ( v7->IsActive(this: &v7->IClient) )
          {
            v8 = filter->IsReliable(this: filter);
            CGameClient::SendSound(this: v7, sound, isReliable: v8);
          }
        }
        ++i;
      }
      while ( i < num );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10125C20
// Name: void OnHibernateWhenEmptyChanged(class IConVar __near *,char const __near *,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl OnHibernateWhenEmptyChanged()
{
  CGameServer::UpdateHibernationState(this: &sv);
}

//------------------------------------------------------------------------------
// Address: 0x10125C30
// Name: void SV_BroadcastVoiceData(class IClient __near *,int,char __near *,__int64)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SV_BroadcastVoiceData(IClient *cl, int nBytes, char *data, unsigned __int64 xuid)
{
  int (__thiscall *GetPlayerSlot)(IClient *); // eax
  int v5; // eax
  const char *v6; // eax
  CBaseClient *v7; // eax
  CBaseClient *v8; // ebx
  IClient *v9; // eax
  bool (__thiscall *IsActive)(IClient *); // edx
  IClient *v11; // esi
  int v12; // eax
  INetChannel *v13; // eax
  int m_nSignonState; // ebx
  int v15; // eax
  const char *v16; // eax
  CBaseClient *v17; // ebx
  bool v18; // al
  bool v19; // al
  int v20; // eax
  INetChannel *v21; // eax
  char *v22; // ebx
  int v23; // eax
  const char *v24; // eax
  int v25; // eax
  INetChannel *v26; // eax
  char *v27; // ebx
  int v28; // eax
  const char *v29; // eax
  const char *v30; // [esp-18h] [ebp-90h]
  const char *v31; // [esp-14h] [ebp-8Ch]
  const char *v32; // [esp-14h] [ebp-8Ch]
  const char *v33; // [esp-14h] [ebp-8Ch]
  const char *v34; // [esp-10h] [ebp-88h]
  const char *v35; // [esp-10h] [ebp-88h]
  const char *v36; // [esp-10h] [ebp-88h]
  const char *v37; // [esp-Ch] [ebp-84h]
  const char *v38; // [esp-Ch] [ebp-84h]
  const char *v39; // [esp-Ch] [ebp-84h]
  int v40; // [esp-8h] [ebp-80h]
  SVC_VoiceData voiceData; // [esp+4h] [ebp-74h] BYREF
  ConVarRef voice_verbose; // [esp+5Ch] [ebp-1Ch] BYREF
  int v43; // [esp+64h] [ebp-14h]
  char *v44; // [esp+68h] [ebp-10h]
  char *v45; // [esp+6Ch] [ebp-Ch]
  int i; // [esp+70h] [ebp-8h]
  bool bSelf; // [esp+76h] [ebp-2h]
  bool bHearsPlayer; // [esp+77h] [ebp-1h]

  ConVarRef::ConVarRef(this: &voice_verbose, pName: "voice_verbose");
  if ( sv_voiceenable.m_pParent != nullptr && sv_voiceenable.m_pParent->m_Value.m_nValue != 0 )
  {
    GetPlayerSlot = cl->GetPlayerSlot;
    voiceData.m_NetChannel = nullptr;
    voiceData.__vftable = (SVC_VoiceData_vtbl *)&SVC_VoiceData::`vftable';
    voiceData.m_DataIn.m_bOverflow = false;
    voiceData.m_DataIn.m_pDebugName = nullptr;
    voiceData.m_DataIn.m_nDataBits = -1;
    voiceData.m_DataIn.m_nDataBytes = 0;
    voiceData.m_bReliable = false;
    voiceData.m_nFromClient = GetPlayerSlot(this: cl);
    v43 = 8 * nBytes;
    voiceData.m_nLength = 8 * nBytes;
    voiceData.m_DataOut = data;
    voiceData.m_xuid = xuid;
    if ( voice_debugfeedbackfrom.m_pParent != nullptr && voice_debugfeedbackfrom.m_pParent->m_Value.m_nValue != 0 )
    {
      v5 = cl->GetPlayerSlot(this: cl);
      v6 = (const char *)((int (__thiscall *)(IClient *, int))cl->GetClientName)(a1: cl, a2: v5 + 1);
      _Msg(a1: "Sending voice from: %s - playerslot: %d\n", v6, v40);
    }
    for ( i = 0; i < sv.m_Clients.m_Size; ++i )
    {
      v7 = sv.m_Clients.m_Memory.m_pMemory[i];
      if ( v7 == nullptr || v7 == (CBaseClient *)-4 )
      {
        v8 = nullptr;
        v9 = nullptr;
      }
      else
      {
        v8 = sv.m_Clients.m_Memory.m_pMemory[i];
        v9 = &v7->IClient;
      }
      IsActive = v8->IsActive;
      v11 = &v8->IClient;
      bSelf = v9 == cl;
      if ( IsActive(this: &v8->IClient) )
      {
        if ( !v11->IsSplitScreenUser(this: &v8->IClient) )
        {
          bHearsPlayer = v11->IsHearingClient(this: &v8->IClient, a2: voiceData.m_nFromClient);
          voiceData.m_bAudible[0] = bHearsPlayer;
          voiceData.m_bProximity = v11->IsProximityHearingClient(this: &v8->IClient, a2: voiceData.m_nFromClient);
          voiceData.m_bAudible[1] = true;
          v17 = v8->m_SplitScreenUsers[1];
          if ( v17 != nullptr )
          {
            v18 = v17->IsHearingClient(this: &v17->IClient, a2: voiceData.m_nFromClient);
            bHearsPlayer |= v18;
            voiceData.m_bAudible[1] = v18;
            v19 = v17->IsProximityHearingClient(this: &v17->IClient, a2: voiceData.m_nFromClient);
            voiceData.m_bProximity |= v19;
          }
          if ( bHearsPlayer || bSelf )
          {
            voiceData.m_nLength = v43;
            if ( !bHearsPlayer )
              voiceData.m_nLength = 0;
            if ( voice_verbose.m_pConVarState->m_Value.m_nValue != 0 )
            {
              v44 = "true";
              if ( !voiceData.m_bProximity )
                v44 = "false";
              if ( v11->GetNetChannel(this: v11) != nullptr )
              {
                v25 = (int)v11->GetNetChannel(this: v11);
                v45 = (char *)(*(int (__thiscall **)(int))(*(_DWORD *)v25 + 4))(a1: v25);
              }
              else
              {
                v45 = &args.m_pArgvBuffer[228];
              }
              if ( cl->GetNetChannel(this: cl) != nullptr )
              {
                v26 = cl->GetNetChannel(this: cl);
                v27 = (char *)v26->GetAddress(this: v26);
              }
              else
              {
                v27 = &args.m_pArgvBuffer[228];
              }
              v28 = ((int (__thiscall *)(IClient *, char *, char *))v11->GetClientName)(a1: v11, a2: v45, a3: v44);
              v29 = (const char *)((int (__thiscall *)(IClient *, char *, int))cl->GetClientName)(
                                    a1: cl,
                                    a2: v27,
                                    a3: v28);
              _Msg(
                a1: "* SV_BroadcastVoiceData: Sending %d bits (%d bytes) from %s (%s) to %s (%s).  Proximity %s.\n",
                voiceData.m_nLength,
                (voiceData.m_nLength + 7) >> 3,
                v29,
                v30,
                v33,
                v36,
                v39);
            }
            v11->SendNetMsg(this: v11, a2: &voiceData, a3: false, a4: true);
          }
          else if ( voice_verbose.m_pConVarState->m_Value.m_nValue != 0 )
          {
            if ( v11->GetNetChannel(this: v11) != nullptr )
            {
              v20 = (int)v11->GetNetChannel(this: v11);
              v44 = (char *)(*(int (__thiscall **)(int))(*(_DWORD *)v20 + 4))(a1: v20);
            }
            else
            {
              v44 = &args.m_pArgvBuffer[228];
            }
            if ( cl->GetNetChannel(this: cl) != nullptr )
            {
              v21 = cl->GetNetChannel(this: cl);
              v22 = (char *)v21->GetAddress(this: v21);
            }
            else
            {
              v22 = &args.m_pArgvBuffer[228];
            }
            v23 = ((int (__thiscall *)(IClient *, char *))v11->GetClientName)(a1: v11, a2: v44);
            v24 = (const char *)((int (__thiscall *)(IClient *, char *, int))cl->GetClientName)(
                                  a1: cl,
                                  a2: v22,
                                  a3: v23);
            _Msg(
              a1: "* SV_BroadcastVoiceData:  Doesn't hear player.  Dropping %d bytes from %s (%s) to %s (%s)\n",
              voiceData.m_nLength,
              v24,
              v32,
              v35,
              v38);
          }
        }
      }
      else if ( voice_verbose.m_pConVarState->m_Value.m_nValue != 0 )
      {
        if ( v11->GetNetChannel(this: &v8->IClient) != nullptr )
        {
          v12 = (int)v11->GetNetChannel(this: &v8->IClient);
          v45 = (char *)(*(int (__thiscall **)(int))(*(_DWORD *)v12 + 4))(a1: v12);
        }
        else
        {
          v45 = &args.m_pArgvBuffer[228];
        }
        if ( cl->GetNetChannel(this: cl) != nullptr )
        {
          v13 = cl->GetNetChannel(this: cl);
          v44 = (char *)v13->GetAddress(this: v13);
        }
        else
        {
          v44 = &args.m_pArgvBuffer[228];
        }
        m_nSignonState = v8->m_nSignonState;
        v15 = ((int (__thiscall *)(IClient *, char *))v11->GetClientName)(a1: v11, a2: v45);
        v16 = (const char *)((int (__thiscall *)(IClient *, char *, int))cl->GetClientName)(a1: cl, a2: v44, a3: v15);
        _Msg(
          a1: "* SV_BroadcastVoiceData:  Not active (SignonState %d).  Dropping %d bytes from %s (%s) to %s (%s)\n",
          m_nSignonState,
          voiceData.m_nLength,
          v16,
          v31,
          v34,
          v37);
      }
    }
  }
  else if ( voice_verbose.m_pConVarState->m_Value.m_nValue != 0 )
  {
    _Msg(a1: "* SV_BroadcastVoiceData:  Dropping all voice.  sv_voiceenable is not set.\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x10126000
// Name: void SV_CreateBaseline(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SV_CreateBaseline()
{
  ServerClass *v0; // esi
  int v1; // edi
  unsigned __int8 *v2; // eax
  edict_t *edicts; // eax
  int v4; // ebx
  bool v5; // zf
  int v6; // ecx
  int v7; // eax
  ServerClass *v8; // esi
  const SendTable *v9; // ebx
  unsigned __int8 v10[96000]; // [esp+Ch] [ebp-1B77Ch] BYREF
  unsigned __int8 pData[16384]; // [esp+1770Ch] [ebp-407Ch] BYREF
  SVC_GameEventList msg; // [esp+1B70Ch] [ebp-7Ch] BYREF
  bf_write pOut; // [esp+1B760h] [ebp-28h] BYREF
  const void **v14; // [esp+1B778h] [ebp-10h]
  int v15; // [esp+1B77Ch] [ebp-Ch]
  int v16; // [esp+1B780h] [ebp-8h]
  int v17; // [esp+1B784h] [ebp-4h]

  SV_WriteVoiceCodec(pBuf: &sv.m_Signon);
  v0 = serverGameDLL->GetAllServerClasses(this: serverGameDLL);
  v1 = 0;
  if ( sv_sendtables.m_pParent == nullptr || sv_sendtables.m_pParent->m_Value.m_nValue == 0 )
    goto LABEL_13;
  if ( sv.m_FullSendTablesBuffer.m_nAllocationCount < 96000 && sv.m_FullSendTablesBuffer.m_nGrowSize >= 0 )
  {
    sv.m_FullSendTablesBuffer.m_nAllocationCount = 96000;
    if ( sv.m_FullSendTablesBuffer.m_pMemory != nullptr )
      v2 = (unsigned __int8 *)_g_pMemAlloc->Realloc_2(
                                this: _g_pMemAlloc,
                                a2: sv.m_FullSendTablesBuffer.m_pMemory,
                                a3: 96000);
    else
      v2 = (unsigned __int8 *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 96000);
    sv.m_FullSendTablesBuffer.m_pMemory = v2;
  }
  bf_write::StartWriting(
    this: &sv.m_FullSendTables,
    pData: sv.m_FullSendTablesBuffer.m_pMemory,
    nBytes: sv.m_FullSendTablesBuffer.m_nAllocationCount,
    iStartBit: 0,
    nBits: -1);
  SV_WriteSendTables(pClasses: v0, pBuf: &sv.m_FullSendTables);
  if ( sv.m_FullSendTables.m_bOverflow )
  {
    Host_Error(error: "SV_CreateBaseline: WriteSendTables overflow.\n");
    return;
  }
  SV_WriteClassInfos(pClasses: v0, pBuf: &sv.m_FullSendTables);
  if ( sv.m_FullSendTables.m_bOverflow )
  {
    Host_Error(error: "SV_CreateBaseline: WriteClassInfos overflow.\n");
  }
  else
  {
LABEL_13:
    if ( g_pLocalNetworkBackdoor == nullptr )
    {
      v17 = 0;
      v16 = 0;
      if ( sv.num_edicts > 0 )
      {
        edicts = sv.edicts;
        v4 = 0;
        v15 = 0;
        do
        {
          if ( (*(int *)((_BYTE *)&edicts->m_fStateFlags + v4) & 2) == 0 )
          {
            v5 = *(IServerUnknown **)((char *)&edicts->m_pUnk + v4) == nullptr;
            v14 = (const void **)((char *)&edicts->m_pUnk + v4);
            if ( !v5 )
            {
              v6 = *(int *)((char *)&edicts->m_pNetworkable + v4);
              if ( v6 != 0 )
              {
                v7 = (*(int (__thiscall **)(int))(*(_DWORD *)v6 + 4))(a1: v6);
                v8 = (ServerClass *)v7;
                if ( v7 != 0 && *(_DWORD *)(v7 + 16) == 0xFFFF )
                {
                  v9 = *(const SendTable **)(v7 + 4);
                  bf_write::bf_write(
                    this: &pOut,
                    pDebugName: "SV_CreateBaseline->writeBuf",
                    pData,
                    nBytes: 0x4000,
                    nBits: -1);
                  if ( !SendTable_Encode(
                          pTable: v9,
                          pStruct: *v14,
                          &pOut,
                          objectID: v1,
                          pRecipients: nullptr,
                          bNonZeroOnly: false) )
                    Host_Error(error: "SV_CreateBaseline: SendTable_Encode returned false (ent %d).\n", v1);
                  SV_EnsureInstanceBaseline(pServerClass: v8, iEdict: v1, pData, nBytes: (pOut.m_iCurBit + 7) >> 3);
                  v4 = v15;
                  v16 += (pOut.m_iCurBit + 7) >> 3;
                  ++v17;
                }
                edicts = sv.edicts;
              }
            }
          }
          ++v1;
          v4 += 16;
          v15 = v4;
        }
        while ( v1 < sv.num_edicts );
      }
      DevMsg(a1: "Created class baseline: %i classes, %i bytes.\n", v17, v16);
    }
    CGameEventManager::ReloadEventDefinitions(this: g_GameEventManager);
    msg.m_bReliable = true;
    msg.m_NetChannel = nullptr;
    msg.__vftable = (SVC_GameEventList_vtbl *)&SVC_GameEventList::`vftable';
    msg.m_DataIn.m_bOverflow = false;
    msg.m_DataIn.m_pDebugName = nullptr;
    msg.m_DataIn.m_nDataBits = -1;
    msg.m_DataIn.m_nDataBytes = 0;
    bf_write::bf_write(this: &msg.m_DataOut);
    bf_write::StartWriting(this: &msg.m_DataOut, pData: v10, nBytes: 96000, iStartBit: 0, nBits: -1);
    CGameEventManager::WriteEventList(this: g_GameEventManager, &msg);
    SVC_GameEventList::WriteToBuffer(this: &msg, buffer: &sv.m_Signon);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10126280
// Name: bool SV_ActivateServer(void)
// Source: json
//------------------------------------------------------------------------------
char __usercall SV_ActivateServer@<al>(int a1@<ebx>)
{
  IEngineVGuiInternal *v1; // eax
  bool v2; // al
  CServerPlugin_vtbl *v3; // esi
  int MaxClients; // eax
  ConVar *v5; // eax
  const char *m_pszString; // eax
  int v7; // eax
  int v8; // eax
  CHLTVServer *v9; // eax
  CHLTVServer *v10; // eax
  CBaseServer_vtbl *v11; // esi
  bool IsDedicated; // al
  CSteam3Server *v13; // eax
  CGameClient *FakeClient; // eax
  CSteam3Server *v15; // eax
  CSteam3Server *v16; // eax
  CSteam3Server *v17; // eax
  CSteam3Server *v19; // eax
  int UDPPort; // [esp-4h] [ebp-14h]
  BOOL bPrevState; // [esp+8h] [ebp-8h]
  int m_QueryPort; // [esp+Ch] [ebp-4h] BYREF

  _COM_TimestampedLog(a1: "SV_ActivateServer");
  v1 = EngineVGui();
  v1->UpdateProgressBar(this: v1, a2: PROGRESS_ACTIVATESERVER, a3: true);
  _COM_TimestampedLog(a1: "serverGameDLL->ServerActivate");
  v2 = CNetworkStringTableContainer::Lock(this: networkStringTableContainerServer, bLock: false);
  v3 = g_pServerPluginHandler->__vftable;
  LOBYTE(bPrevState) = v2;
  MaxClients = CBaseServer::GetMaxClients(this: &sv);
  v3->ServerActivate(this: g_pServerPluginHandler, a2: sv.edicts, a3: sv.num_edicts, a4: MaxClients);
  sv.m_State = ss_active;
  _COM_TimestampedLog(a1: "SV_CreateBaseline");
  SV_CreateBaseline();
  sv.allowsignonwrites = false;
  v5 = g_pCVar->FindVar_2(this: g_pCVar, a2: "sv_skyname");
  if ( v5 != nullptr )
  {
    if ( (v5->m_nFlags & 0x1000) != 0 )
    {
      V_strncpy(pDest: sv.m_szSkyname, pSrc: "FCVAR_NEVER_AS_STRING", maxLen: 64);
    }
    else
    {
      m_pszString = v5->m_pParent->m_Value.m_pszString;
      if ( m_pszString == nullptr )
        m_pszString = defaultValue;
      V_strncpy(pDest: sv.m_szSkyname, pSrc: m_pszString, maxLen: 64);
    }
  }
  else
  {
    V_strncpy(pDest: sv.m_szSkyname, pSrc: "unknown", maxLen: 64);
  }
  _COM_TimestampedLog(a1: "Send Reconnects");
  CBaseServer::ReconnectClients(this: &sv);
  if ( sv.m_nMaxclients <= 1 )
  {
    _ConDMsg(a1: "Game started\n");
  }
  else
  {
    v7 = CBaseServer::GetMaxClients(this: &sv);
    _ConDMsg(a1: "%i player server started\n", v7);
  }
  if ( tv_enable.m_pParent != nullptr && tv_enable.m_pParent->m_Value.m_nValue != 0 )
  {
    v8 = _CommandLine();
    if ( (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v8 + 40))(a1: v8, a2: "-nohltv") != 0 )
    {
      ConMsg(a1: "SourceTV is disabled on this server.\n");
    }
    else
    {
      if ( hltv == nullptr )
      {
        v9 = (CHLTVServer *)MemAlloc_Alloc(nSize: 0x89C0u);
        if ( v9 != nullptr )
          v10 = CHLTVServer::CHLTVServer(this: v9);
        else
          v10 = nullptr;
        hltv = v10;
        v11 = v10->CBaseServer::IServer::IConnectionlessPacketHandler::__vftable;
        IsDedicated = NET_IsDedicated();
        v11->Init(this: &hltv->CBaseServer, a2: IsDedicated);
      }
      UDPPort = NET_GetUDPPort(socket: 2);
      v13 = Steam3Server();
      CSteam3Server::UpdateSpectatorPort(this: v13, unSpectatorPort: UDPPort);
      if ( hltv->IsActive(this: &hltv->CBaseServer) && hltv->IsMasterProxy(this: &hltv->IHLTVServer) )
      {
        hltv->m_MasterClient->ActivatePlayer(this: hltv->m_MasterClient);
        CHLTVServer::StartMaster(this: hltv, client: hltv->m_MasterClient);
      }
      else
      {
        FakeClient = (CGameClient *)CBaseServer::CreateFakeClient(this: &sv, name: "SourceTV");
        CHLTVServer::StartMaster(this: hltv, client: FakeClient);
      }
    }
  }
  else
  {
    v15 = Steam3Server();
    CSteam3Server::UpdateSpectatorPort(this: v15, unSpectatorPort: 0);
    if ( hltv != nullptr )
      hltv->Shutdown(this: &hltv->CBaseServer);
  }
  if ( sv.m_bIsDedicated )
    modelloader->PurgeUnusedModels(this: modelloader);
  if ( sv.m_nMaxclients > 1 || serverGameDLL->ShouldPreferSteamAuth(this: serverGameDLL) )
  {
    v16 = Steam3Server();
    CSteam3Server::Activate(this: v16);
    if ( sv.m_pServerStartupTable != nullptr )
    {
      m_QueryPort = Steam3Server()->m_QueryPort;
      sv.m_pServerStartupTable->AddString(
        this: sv.m_pServerStartupTable,
        a2: true,
        a3: "QueryPort",
        a4: 4,
        a5: &m_QueryPort);
    }
    if ( serverGameDLL != nullptr )
      serverGameDLL->GameServerSteamAPIActivated(this: serverGameDLL);
  }
  CNetworkStringTableContainer::Lock(this: networkStringTableContainerServer, bLock: bPrevState);
  v17 = Steam3Server();
  CSteam3Server::SendUpdatedServerDetails(this: v17, a2: a1, a3: (int)_COM_TimestampedLog);
  if ( IsUsingMasterLegacyMode() )
  {
    g_pMaster->Heartbeat_Legacy_f(this: g_pMaster);
  }
  else
  {
    v19 = Steam3Server();
    v19->m_pSteamMasterServerUpdater->ForceHeartbeat(this: v19->m_pSteamMasterServerUpdater);
  }
  _COM_TimestampedLog(a1: "SV_ActivateServer(finished)");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101265D0
// Name: public: bool CGameServer::SpawnServer(char __near *,char __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CGameServer::SpawnServer(CGameServer *this, char *mapname, char *startspot)
{
  int v4; // eax
  void (*v5)(const char *, ...); // ebx
  IEngineVGuiInternal *v6; // eax
  bool v7; // al
  int v8; // eax
  IStaticPropMgrEngine *v9; // eax
  int v10; // edi
  int v11; // eax
  double v12; // st7
  int v13; // eax
  int v14; // eax
  model_t *v15; // eax
  unsigned int *p_clientDllCRC; // edi
  IEngineVGuiInternal *v18; // eax
  IEngineVGuiInternal *v19; // eax
  IEngineVGuiInternal *v20; // eax
  IEngineVGuiInternal *v21; // eax
  int i; // edi
  model_t *v23; // eax
  IEngineVGuiInternal *v24; // eax
  int m_nValue; // eax
  bool v26; // zf
  char *m_szMapname; // eax
  char *m_szStartspot; // eax
  IGameEvent *v29; // edi
  char *m_pszString; // eax
  IGameEvent_vtbl *v31; // ebx
  char *v32; // eax
  IGameEvent_vtbl *v33; // ebx
  int v34; // eax
  IGameEvent_vtbl *v35; // ebx
  const char *v36; // eax
  IGameEvent_vtbl *v37; // ebx
  int v38; // eax
  IGameEvent_vtbl *v39; // ebx
  bool v40; // al
  int v41; // [esp+0h] [ebp-27Ch]
  unsigned int v42; // [esp+4h] [ebp-278h]
  edict_t *v43; // [esp+4h] [ebp-278h]
  int value; // [esp+8h] [ebp-274h]
  char szNameOnDisk[260]; // [esp+Ch] [ebp-270h] BYREF
  char szModelName[260]; // [esp+110h] [ebp-16Ch] BYREF
  char szDllName[96]; // [esp+214h] [ebp-68h] BYREF
  char localmodel[8]; // [esp+274h] [ebp-8h] BYREF
  int flStartTimeOverride; // [esp+288h] [ebp+Ch]
  float flStartTimeOverridea; // [esp+288h] [ebp+Ch]

  v4 = _CommandLine();
  if ( (*(int (__thiscall **)(int))(*(_DWORD *)v4 + 40))(a1: v4) != 0 && !this->m_bLoadedPlugins )
  {
    this->m_bLoadedPlugins = true;
    CServerPlugin::LoadPlugins(this: g_pServerPluginHandler);
  }
  if ( this->IsDedicated(this) )
    CLoaderMemAlloc::CrtIsValidPointer(
      this: (ConVar *)&fps_max.IConVar,
      value: 30,
      a2: (unsigned int)"-NoLoadPluginsForClient",
      a3: v41);
  CGameServer::ReloadWhitelist(this, pMapName: mapname);
  v5 = (void (*)(const char *, ...))_COM_TimestampedLog;
  _COM_TimestampedLog(a1: "SV_SpawnServer(%s)", mapname);
  v6 = EngineVGui();
  ((void (__thiscall *)(IEngineVGuiInternal *))v6->UpdateProgressBar)(a1: v6);
  COM_SetupLogDir(mapname);
  CLog::Open(this: &g_Log, a2: mapname);
  CLog::Printf(this: &g_Log, fmt: "Loading map \"%s\"\n", mapname);
  CLog::PrintServerVars(this: &g_Log);
  if ( startspot != nullptr )
    _ConDMsg(a1: "Spawn Server: %s: [%s]\n", mapname, startspot);
  else
    _ConDMsg(a1: "Spawn Server: %s\n", mapname);
  gHostSpawnCount = ++this->m_nSpawnCount;
  v7 = this->IsMultiplayer(this);
  CLoaderMemAlloc::CrtIsValidPointer(this: (ConVar *)&deathmatch.IConVar, value: v7, a2: 2u, a3: 1);
  if ( coop.m_pParent != nullptr && coop.m_pParent->m_Value.m_nValue != 0 )
    CLoaderMemAlloc::CrtIsValidPointer(this: (ConVar *)&deathmatch.IConVar, value: 0, a2: v42, a3: value);
  v8 = current_skill <= 0 ? 0 : current_skill;
  current_skill = v8;
  if ( v8 >= 3 )
  {
    v8 = 3;
    current_skill = 3;
  }
  ConVar::SetValue(this: (ConVar *)&skill.IConVar, value: (float)v8);
  _COM_TimestampedLog(a1: "StaticPropMgr()->LevelShutdown()");
  g_pShadowMgr->LevelShutdown(this: g_pShadowMgr);
  v9 = StaticPropMgr();
  v9->LevelShutdown(this: v9);
  if ( hltv != nullptr && !hltv->IsMasterProxy(this: &hltv->IHLTVServer) )
    hltv->Shutdown(this: &hltv->CBaseServer);
  _COM_TimestampedLog(a1: "Host_FreeToLowMark");
  Host_FreeStateAndWorld(server: true);
  Host_FreeToLowMark(server: true);
  g_ServerGlobalVariables.mapversion = 0;
  _COM_TimestampedLog(a1: "sv.Clear()");
  this->Clear(this);
  _COM_TimestampedLog(a1: "framesnapshotmanager->LevelChanged()");
  framesnapshotmanager->LevelChanged(this: framesnapshotmanager);
  V_strncpy(pDest: this->m_szMapname, pSrc: mapname, maxLen: 64);
  v10 = 0;
  if ( startspot != nullptr )
    V_strncpy(pDest: this->m_szStartspot, pSrc: startspot, maxLen: 64);
  else
    this->m_szStartspot[0] = 0;
  SV_FlushMemoryIfMarked();
  g_pFileSystem->SetupPreloadData(this: g_pFileSystem);
  g_pMDLCache->InitPreloadData(this: g_pMDLCache, a2: false);
  this->max_edicts = 2048;
  g_ServerGlobalVariables.maxEntities = 2048;
  g_ServerGlobalVariables.maxClients = this->GetMaxClients(this);
  g_ClientGlobalVariables.network_protocol = GetHostVersion();
  this->num_edicts = this->GetMaxClients(this) + 1;
  _COM_TimestampedLog(a1: "SV_AllocateEdicts");
  sv.edicts = (edict_t *)Hunk_AllocName(size: 16 * sv.max_edicts, name: "edicts", bClear: true);
  ED_ClearTimes();
  sv.edictchangeinfo = (IChangeInfoAccessor *)Hunk_AllocName(
                                                size: 4 * sv.max_edicts,
                                                name: "edictchangeinfo",
                                                bClear: true);
  g_ServerGlobalVariables.pEdicts = this->edicts;
  this->allowsignonwrites = true;
  this->serverclasses = 0;
  this->serverclassbits = 0;
  CGameServer::AssignClassIds(this);
  _COM_TimestampedLog(a1: "Set up players");
  if ( this->GetClientCount(this) > 0 )
  {
    flStartTimeOverride = 0;
    do
    {
      v43 = &this->edicts[flStartTimeOverride + 1];
      *(_DWORD *)this->m_Clients.m_Memory.m_pMemory[v10][1].m_GUID = v43;
      InitializeEntityDLLFields(pEdict: v43);
      ++flStartTimeOverride;
      ++v10;
    }
    while ( v10 < this->GetClientCount(this) );
  }
  _COM_TimestampedLog(a1: "Set up players(done)");
  this->m_State = ss_loading;
  CBaseServer::SendReservationStatus(this: &sv);
  this->m_flTickInterval = host_state.interval_per_tick;
  this->m_nTickCount = 1 - (int)(-1.0 / host_state.interval_per_tick);
  v11 = _CommandLine();
  v12 = ((double (__thiscall *)(int, const char *, _DWORD))*(_DWORD *)(*(_DWORD *)v11 + 24))(
          a1: v11,
          a2: "-servertime",
          a3: -1.0);
  if ( v12 != -1.0 )
  {
    flStartTimeOverridea = v12;
    v13 = (int)(float)(flStartTimeOverridea / host_state.interval_per_tick) + 1;
    if ( v13 <= 1 )
      v13 = 1;
    this->m_nTickCount = v13;
  }
  g_ServerGlobalVariables.tickcount = this->m_nTickCount;
  g_ServerGlobalVariables.curtime = this->GetTime(this);
  host_tickcount = g_ServerGlobalVariables.tickcount;
  V_snprintf(pDest: szModelName, maxLen: 260, pFormat: "maps/%s.bsp", mapname);
  GetMapPathNameOnDisk(pDiskName: szNameOnDisk, pFullMapName: szModelName, nDiskNameSize: 0x104u);
  g_pFileSystem->AddSearchPath(this: g_pFileSystem, a2: szNameOnDisk, a3: "GAME", a4: PATH_ADD_TO_HEAD);
  g_pFileSystem->BeginMapAccess(this: g_pFileSystem);
  v14 = _CommandLine();
  if ( (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v14 + 40))(a1: v14, a2: "-allowstalezip") == 0
    && g_pFileSystem->FileExists(this: &g_pFileSystem->IBaseFileSystem, a2: "stale.txt", a3: "GAME") )
  {
    _Warning(a1: "This map is not final!!  Needs to be rebuilt without -keepstalezip and without -onlyents\n");
  }
  _COM_TimestampedLog(a1: "modelloader->GetModelForName(%s) -- Start", szModelName);
  v15 = modelloader->GetModelForName(this: modelloader, a2: szModelName, a3: 2);
  CCommonHostState::SetWorldModel(this: &host_state, pModel: v15);
  p_clientDllCRC = nullptr;
  if ( host_state.worldmodel == nullptr )
  {
    ConMsg(a1: "Couldn't spawn server %s\n", szModelName);
    this->m_State = ss_dead;
    g_pFileSystem->EndMapAccess(this: g_pFileSystem);
    return 0;
  }
  _COM_TimestampedLog(a1: "modelloader->GetModelForName(%s) -- Finished", szModelName);
  if ( this->IsMultiplayer(this) )
  {
    v18 = EngineVGui();
    v18->UpdateProgressBar(this: v18, a2: PROGRESS_CRCMAP, a3: true);
    CRC32_Init(pulCRC: &this->worldmapCRC);
    if ( !CRC_MapFile(crcvalue: &this->worldmapCRC, pszFileName: szNameOnDisk) )
    {
      ConMsg(a1: "Couldn't CRC server map: %s\n", szNameOnDisk);
      this->m_State = ss_dead;
      g_pFileSystem->EndMapAccess(this: g_pFileSystem);
      return 0;
    }
    v19 = EngineVGui();
    v19->UpdateProgressBar(this: v19, a2: PROGRESS_CRCCLIENTDLL, a3: true);
    V_snprintf(pDest: szDllName, maxLen: 96, pFormat: "bin\\client.dll");
    V_FixSlashes(pname: szDllName, separator: 92);
    p_clientDllCRC = &this->clientDllCRC;
    if ( !CRC_File(crcvalue: &this->clientDllCRC, pszFileName: szDllName) )
      *p_clientDllCRC = -1;
  }
  else
  {
    this->worldmapCRC = 0;
    this->clientDllCRC = 0;
  }
  this->m_StringTables = networkStringTableContainerServer;
  _COM_TimestampedLog(a1: "SV_CreateNetworkStringTables");
  v20 = EngineVGui();
  v20->UpdateProgressBar(this: v20, a2: PROGRESS_CREATENETWORKSTRINGTABLES, a3: true);
  SV_CreateNetworkStringTables(pchMapName: mapname);
  this->stringTableCRC = g_pStringTableDictionary->GetCRC(this: g_pStringTableDictionary);
  CGameServer::PrecacheModel(
    this,
    a2: (int)_COM_TimestampedLog,
    a3: (int)p_clientDllCRC,
    name: defaultValue,
    flags: 0,
    model: nullptr);
  CGameServer::PrecacheGeneric(this, a2: (int)_COM_TimestampedLog, a3: (int)this, name: defaultValue, flags: 0);
  CGameServer::PrecacheSound(this, a2: (int)_COM_TimestampedLog, a3: (int)this, name: defaultValue, flags: 0);
  _COM_TimestampedLog(a1: "Precache world model (%s)", szModelName);
  v21 = EngineVGui();
  v21->UpdateProgressBar(this: v21, a2: PROGRESS_PRECACHEWORLD, a3: true);
  CGameServer::PrecacheModel(
    this,
    a2: (int)_COM_TimestampedLog,
    a3: (int)p_clientDllCRC,
    name: szModelName,
    flags: 3,
    model: host_state.worldmodel);
  _COM_TimestampedLog(a1: "Precache brush models");
  for ( i = 1; i < host_state.worldbrush->numsubmodels; ++i )
  {
    V_snprintf(pDest: localmodel, maxLen: 5, pFormat: "*%i", i);
    v23 = modelloader->GetModelForName(this: modelloader, a2: localmodel, a3: 2);
    CGameServer::PrecacheModel(this, a2: (int)_COM_TimestampedLog, a3: i, name: localmodel, flags: 3, model: v23);
  }
  v24 = EngineVGui();
  v24->UpdateProgressBar(this: v24, a2: PROGRESS_CLEARWORLD, a3: true);
  _COM_TimestampedLog(a1: "SV_ClearWorld");
  SV_ClearWorld();
  _COM_TimestampedLog(a1: "InitializeEntityDLLFields");
  InitializeEntityDLLFields(pEdict: this->edicts);
  this->edicts->m_fStateFlags &= ~2u;
  if ( coop.m_pParent != nullptr )
    m_nValue = coop.m_pParent->m_Value.m_nValue;
  else
    m_nValue = 0;
  g_ServerGlobalVariables.coop = m_nValue != 0;
  if ( m_nValue != 0
    || deathmatch.m_pParent == nullptr
    || (v26 = deathmatch.m_pParent->m_Value.m_nValue == 0, g_ServerGlobalVariables.deathmatch = true, v26) )
  {
    g_ServerGlobalVariables.deathmatch = false;
  }
  m_szMapname = this->m_szMapname;
  if ( this == (CGameServer *)-16 || *m_szMapname == 0 )
    m_szMapname = nullptr;
  g_ServerGlobalVariables.mapname.pszValue = m_szMapname;
  m_szStartspot = this->m_szStartspot;
  if ( this == (CGameServer *)-457 || *m_szStartspot == 0 )
    m_szStartspot = nullptr;
  g_ServerGlobalVariables.startspot.pszValue = m_szStartspot;
  CTestScriptMgr::CheckPoint(this: &g_TestScriptMgr, pName: "map_load");
  v29 = g_GameEventManager->CreateEventA(this: g_GameEventManager, a2: "server_spawn", a3: 0, a4: 0);
  if ( v29 != nullptr )
  {
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
    v29->SetString(this: v29, a2: "hostname", a3: m_pszString);
    v31 = v29->__vftable;
    v32 = netadr_s::ToString(this: &net_local_adr, baseOnly: false);
    v31->SetString(this: v29, a2: "address", a3: v32);
    v33 = v29->__vftable;
    v34 = this->GetUDPPort(this);
    v33->SetInt(this: v29, a2: "port", a3: v34);
    v29->SetString(this: v29, a2: "game", a3: com_gamedir);
    v35 = v29->__vftable;
    v36 = this->GetMapName(this);
    v35->SetString(this: v29, a2: "mapname", a3: v36);
    v37 = v29->__vftable;
    v38 = this->GetMaxClients(this);
    v37->SetInt(this: v29, a2: "maxplayers", a3: v38);
    v29->SetInt(this: v29, a2: "password", a3: 0);
    v29->SetString(this: v29, a2: "os", a3: "WIN32");
    v39 = v29->__vftable;
    v40 = this->IsDedicated(this);
    v39->SetInt(this: v29, a2: "dedicated", a3: v40);
    g_GameEventManager->FireEvent(this: g_GameEventManager, a2: v29, a3: false);
    v5 = (void (*)(const char *, ...))_COM_TimestampedLog;
  }
  v5(a1: "SV_SpawnServer -- Finished");
  g_pFileSystem->EndMapAccess(this: g_pFileSystem);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10126EE0
// Name: protected: virtual void CGameServer::UpdateMasterServerPlayers(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameServer::UpdateMasterServerPlayers(CGameServer *this)
{
  CGameServer *v1; // ebx
  CBaseClient *v2; // esi
  IClient *v3; // edi
  CSteam3Server *v4; // eax
  ISteamGameServer *m_pSteamGameServer; // ebx
  ISteamGameServer_vtbl *v6; // esi
  int v7; // eax
  CSteamID *p_m_SteamID; // [esp+8h] [ebp-Ch]
  CPlayerState *pl; // [esp+Ch] [ebp-8h]
  int i; // [esp+10h] [ebp-4h]

  v1 = this;
  if ( Steam3Server()->m_pSteamGameServer != nullptr )
  {
    for ( i = 0; i < v1->GetClientCount(this: v1); ++i )
    {
      v2 = v1->m_Clients.m_Memory.m_pMemory[i];
      v3 = &v2->IClient;
      if ( v2->IsConnected(this: &v2->IClient) )
      {
        pl = serverGameClients->GetPlayerState(this: serverGameClients, a2: *(_DWORD *)v2[1].m_GUID);
        if ( pl != nullptr )
        {
          p_m_SteamID = &v2->m_SteamID;
          if ( CSteamID::IsValid(this: &v2->m_SteamID) )
          {
            v4 = Steam3Server();
            m_pSteamGameServer = v4->m_pSteamGameServer;
            v6 = v4->m_pSteamGameServer->__vftable;
            v7 = ((int (__thiscall *)(IClient *, int))v3->GetClientName)(a1: v3, a2: pl->frags);
            ((void (__thiscall *)(ISteamGameServer *, _DWORD, _DWORD, int))v6->BUpdateUserData)(
              a1: m_pSteamGameServer,
              a2: *(_DWORD *)&p_m_SteamID->m_steamid.m_comp,
              a3: *((_DWORD *)&p_m_SteamID->m_steamid.m_comp + 1),
              a4: v7);
            v1 = this;
          }
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10126FB0
// Name: public: virtual void CFunctor2<void (*)(bool,bool),bool,bool,class CRefCounted1<class CFunctor,class CRefCountServiceBase<1,class CRefMT>>>::operator()(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFunctor2<void (__cdecl *)(bool,bool),bool,bool,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>>::operator()(
        CFunctor2<void (__cdecl*)(bool,bool),bool,bool,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> > > *this)
{
  this->m_pfnProxied(a1: this->m_arg1, a2: this->m_arg2);
}

//------------------------------------------------------------------------------
// Address: 0x10126FE0
// Name: public: void CGameServer::CopyPureServerWhitelistToStringTable(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameServer::CopyPureServerWhitelistToStringTable(CGameServer *this)
{
  CUtlBuffer buf; // [esp+4h] [ebp-30h] BYREF

  if ( this->m_pPureServerWhitelist != nullptr )
  {
    CUtlBuffer::CUtlBuffer(this: &buf, growSize: 0, initSize: 0, nFlags: 0);
    CPureServerWhitelist::Encode(this: this->m_pPureServerWhitelist, &buf);
    this->m_pServerStartupTable->AddString(
      this: this->m_pServerStartupTable,
      a2: true,
      a3: "PureServerWhitelist",
      a4: buf.m_Put,
      a5: buf.m_Memory.m_pMemory);
    if ( buf.m_Memory.m_nGrowSize >= 0 && buf.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buf.m_Memory.m_pMemory);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10127050
// Name: public: CGameServer::CGameServer(void)
// Source: json
//------------------------------------------------------------------------------
CGameServer *__thiscall CGameServer::CGameServer(CGameServer *this)
{
  CPrecacheItem *model_precache; // edi
  int i; // ebx
  CPrecacheItem *generic_precache; // edi
  int j; // ebx
  CPrecacheItem *sound_precache; // edi
  int k; // ebx
  CPrecacheItem *decal_precache; // edi
  int m; // ebx

  CBaseServer::CBaseServer(this);
  this->__vftable = (CGameServer_vtbl *)&CGameServer::`vftable';
  this->m_TempEntities.m_Memory.m_pMemory = nullptr;
  this->m_TempEntities.m_Memory.m_nAllocationCount = 0;
  this->m_TempEntities.m_Memory.m_nGrowSize = 0;
  this->m_TempEntities.m_Size = 0;
  this->m_TempEntities.m_pElements = nullptr;
  bf_write::bf_write(this: &this->m_FullSendTables);
  this->m_FullSendTablesBuffer.m_pMemory = nullptr;
  this->m_FullSendTablesBuffer.m_nAllocationCount = 0;
  this->m_FullSendTablesBuffer.m_nGrowSize = 0;
  model_precache = this->model_precache;
  for ( i = 1023; i >= 0; --i )
    CPrecacheItem::CPrecacheItem(this: model_precache++);
  generic_precache = this->generic_precache;
  for ( j = 511; j >= 0; --j )
    CPrecacheItem::CPrecacheItem(this: generic_precache++);
  sound_precache = this->sound_precache;
  for ( k = 0x1FFF; k >= 0; --k )
    CPrecacheItem::CPrecacheItem(this: sound_precache++);
  decal_precache = this->decal_precache;
  for ( m = 511; m >= 0; --m )
    CPrecacheItem::CPrecacheItem(this: decal_precache++);
  this->m_nMinClientsLimit = 0;
  this->m_nMaxClientsLimit = 0;
  this->m_pPureServerWhitelist = nullptr;
  this->m_bHibernating = false;
  this->m_bLoadedPlugins = false;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10127130
// Name: public: virtual int CBaseServer::GetUDPPort(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBaseServer::GetUDPPort(CBaseServer *this)
{
  return NET_GetUDPPort(socket: this->m_Socket);
}

//------------------------------------------------------------------------------
// Address: 0x10127140
// Name: public: virtual int CBaseServer::GetSpawnCount(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBaseServer::GetSpawnCount(CBaseServer *this)
{
  return this->m_nSpawnCount;
}

//------------------------------------------------------------------------------
// Address: 0x10127150
// Name: public: virtual int CBaseServer::GetNumClasses(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBaseServer::GetNumClasses(CBaseServer *this)
{
  return this->serverclasses;
}

//------------------------------------------------------------------------------
// Address: 0x10127160
// Name: public: virtual int CBaseServer::GetClassBits(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBaseServer::GetClassBits(CBaseServer *this)
{
  return this->serverclassbits;
}

//------------------------------------------------------------------------------
// Address: 0x10127170
// Name: public: virtual float CBaseServer::GetCPUUsage(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CBaseServer::GetCPUUsage(CBaseServer *this)
{
  return this->m_fCPUPercent;
}

//------------------------------------------------------------------------------
// Address: 0x10127180
// Name: public: virtual bool CBaseServer::IsLoading(void)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CBaseServer::IsLoading(CBaseServer *this)
{
  return this->m_State == ss_loading;
}

//------------------------------------------------------------------------------
// Address: 0x10127190
// Name: public: virtual CGameServer::~CGameServer(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameServer::~CGameServer(CGameServer *this)
{
  CPureServerWhitelist *m_pPureServerWhitelist; // ecx

  m_pPureServerWhitelist = this->m_pPureServerWhitelist;
  this->__vftable = (CGameServer_vtbl *)&CGameServer::`vftable';
  if ( m_pPureServerWhitelist != nullptr )
    CPureServerWhitelist::Release(this: m_pPureServerWhitelist);
  if ( this->m_FullSendTablesBuffer.m_nGrowSize >= 0 )
  {
    if ( this->m_FullSendTablesBuffer.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_FullSendTablesBuffer.m_pMemory);
      this->m_FullSendTablesBuffer.m_pMemory = nullptr;
    }
    this->m_FullSendTablesBuffer.m_nAllocationCount = 0;
  }
  CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&this->m_TempEntities);
  CBaseServer::~CBaseServer(this);
}

//------------------------------------------------------------------------------
// Address: 0x10127260
// Name: class CFunctor __near * CreateFunctor<void,bool,bool,bool,bool>(void (*)(bool,bool),bool const __near &,bool const __near &)
// Source: json
//------------------------------------------------------------------------------
CFunctor *__cdecl CreateFunctor<void,bool,bool,bool,bool>(
        void (__cdecl *pfnProxied)(bool, bool),
        const bool *arg1,
        const bool *arg2)
{
  CFunctor *result; // eax

  result = (CFunctor *)MemAlloc_Alloc(nSize: 0x18u);
  if ( result == nullptr )
    return nullptr;
  result[1].m_nUserID = 1;
  result->__vftable = (CFunctor_vtbl *)&CFunctor2<void (__cdecl *)(bool,bool),bool,bool,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>>::`vftable'{for `CFunctor'};
  result[1].__vftable = (CFunctor_vtbl *)&CFunctor2<void (__cdecl *)(bool,bool),bool,bool,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>>::`vftable'{for `CRefCountServiceBase<1,CRefMT>'};
  result[2].__vftable = (CFunctor_vtbl *)pfnProxied;
  LOBYTE(result[2].m_nUserID) = *arg1;
  BYTE1(result[2].m_nUserID) = *arg2;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101272B0
// Name: public: void CGameServer::CreateEngineStringTables(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameServer::CreateEngineStringTables(CGameServer *this)
{
  INetworkStringTable *v2; // eax
  CNetworkStringTableContainer *m_StringTables; // ecx
  INetworkStringTable *v4; // eax
  CNetworkStringTableContainer *v5; // ecx
  INetworkStringTable *v6; // eax
  CNetworkStringTableContainer *v7; // ecx
  INetworkStringTable *v8; // eax
  CNetworkStringTableContainer *v9; // ecx
  INetworkStringTable *v10; // eax
  CNetworkStringTableContainer *v11; // ecx
  INetworkStringTable *v12; // eax
  CNetworkStringTableContainer *v13; // ecx
  INetworkStringTable *v14; // eax
  CNetworkStringTableContainer *v15; // ecx
  INetworkStringTable *v16; // eax
  CNetworkStringTableContainer *v17; // ecx
  INetworkStringTable *v18; // eax
  int i; // edi
  int j; // edi
  CDownloadListGenerator *v21; // eax
  INetworkStringTable *m_pDownloadableFileTable; // [esp-4h] [ebp-14h]
  char name[8]; // [esp+8h] [ebp-8h] BYREF

  CNetworkStringTableContainer::SetTick(this: this->m_StringTables, tick_count: this->m_nTickCount);
  v2 = this->m_StringTables->CreateStringTable(
         this: this->m_StringTables,
         a2: "downloadables",
         a3: 0x2000,
         a4: 0,
         a5: 0,
         a6: 1);
  m_StringTables = this->m_StringTables;
  this->m_pDownloadableFileTable = v2;
  v4 = m_StringTables->CreateStringTable(this: m_StringTables, a2: "modelprecache", a3: 1024, a4: 1, a5: 2, a6: 1);
  v5 = this->m_StringTables;
  this->m_pModelPrecacheTable = v4;
  v6 = v5->CreateStringTable(this: v5, a2: "genericprecache", a3: 512, a4: 1, a5: 2, a6: 1);
  v7 = this->m_StringTables;
  this->m_pGenericPrecacheTable = v6;
  v8 = v7->CreateStringTable(this: v7, a2: "soundprecache", a3: 0x2000, a4: 1, a5: 2, a6: 1);
  v9 = this->m_StringTables;
  this->m_pSoundPrecacheTable = v8;
  v10 = v9->CreateStringTable(this: v9, a2: "decalprecache", a3: 512, a4: 1, a5: 2, a6: 1);
  v11 = this->m_StringTables;
  this->m_pDecalPrecacheTable = v10;
  v12 = v11->CreateStringTable(this: v11, a2: "instancebaseline", a3: 1024, a4: 0, a5: 0, a6: 0);
  v13 = this->m_StringTables;
  this->m_pInstanceBaselineTable = v12;
  v14 = v13->CreateStringTable(this: v13, a2: "lightstyles", a3: 64, a4: 0, a5: 0, a6: 0);
  v15 = this->m_StringTables;
  this->m_pLightStyleTable = v14;
  v16 = v15->CreateStringTable(this: v15, a2: "userinfo", a3: 64, a4: 0, a5: 0, a6: 0);
  v17 = this->m_StringTables;
  this->m_pUserInfoTable = v16;
  v18 = v17->CreateStringTable(this: v17, a2: "server_query_info", a3: 4, a4: 0, a5: 0, a6: 0);
  this->m_pServerStartupTable = v18;
  if ( v18 != nullptr )
  {
    *(_DWORD *)&name[4] = Steam3Server()->m_QueryPort;
    this->m_pServerStartupTable->AddString(
      this: this->m_pServerStartupTable,
      a2: true,
      a3: "QueryPort",
      a4: 4,
      a5: &name[4]);
  }
  CGameServer::CopyPureServerWhitelistToStringTable(this);
  for ( i = 0; i < 64; ++i )
  {
    V_snprintf(pDest: name, maxLen: 8, pFormat: "%i", i);
    this->m_pLightStyleTable->AddString(this: this->m_pLightStyleTable, a2: true, a3: name, a4: -1, a5: nullptr);
  }
  for ( j = 0; j < 64; ++j )
  {
    V_snprintf(pDest: name, maxLen: 8, pFormat: "%i", j);
    this->m_pUserInfoTable->AddString(this: this->m_pUserInfoTable, a2: true, a3: name, a4: -1, a5: nullptr);
  }
  m_pDownloadableFileTable = this->m_pDownloadableFileTable;
  v21 = DownloadListGenerator();
  CDownloadListGenerator::SetStringTable(this: v21, pStringTable: m_pDownloadableFileTable);
}

//------------------------------------------------------------------------------
// Address: 0x101274E0
// Name: void SV_StartSound(class IRecipientFilter __near &,struct edict_t __near *,int,char const __near *,int,char const __near *,float,enum soundlevel_t,int,int,class Vector const __near *,float,int,class CUtlVector<class Vector,class CUtlMemory<class Vector,int>> __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SV_StartSound(
        IRecipientFilter *filter,
        edict_t *pSoundEmittingEntity,
        int iChannel,
        const char *pSoundEntry,
        int iSoundEntryIndex,
        char *pSample,
        float flVolume,
        soundlevel_t iSoundLevel,
        int iFlags,
        int iPitch,
        const Vector *pOrigin,
        float soundtime,
        int speakerentity,
        CUtlVector<Vector,CUtlMemory<Vector,int> > *pUtlVecOrigins,
        int nSeed)
{
  IServerUnknown *m_pUnk; // ecx
  ICollideable *v16; // eax
  double FinalTickTime; // st7
  char *v18; // eax
  char *v19; // eax
  int nSoundNum; // eax
  SoundInfo_t sound; // [esp+0h] [ebp-5Ch] BYREF
  float pSoundEmittingEntitya; // [esp+68h] [ebp+Ch]
  float soundtimea; // [esp+90h] [ebp+34h]

  memset(&sound.fDelay, 0, 16);
  sound.fVolume = 1.0;
  sound.Soundlevel = SNDLVL_NORM;
  sound.nPitch = 100;
  sound.nSpeakerEntity = -1;
  sound.nChannel = 6;
  sound.nSoundNum = 0;
  sound.nFlags = 0;
  sound.nRandomSeed = 0;
  sound.bLooping = false;
  *(_WORD *)&sound.bIsSentence = 0;
  memset(&sound, 0, 40);
  if ( pSoundEmittingEntity != nullptr )
    sound.nEntityIndex = NUM_FOR_EDICTINFO(e: pSoundEmittingEntity);
  else
    sound.nEntityIndex = 0;
  sound.nChannel = iChannel;
  sound.nPitch = iPitch;
  sound.pszName = pSoundEntry;
  sound.Soundlevel = iSoundLevel;
  sound.nFlags = iFlags;
  sound.fVolume = flVolume;
  sound.nSpeakerEntity = speakerentity;
  sound.nRandomSeed = nSeed;
  if ( pOrigin != nullptr )
  {
    sound.vOrigin = *pOrigin;
  }
  else if ( pSoundEmittingEntity != nullptr && (pSoundEmittingEntity->m_fStateFlags & 4) != 0 )
  {
    m_pUnk = pSoundEmittingEntity->m_pUnk;
    if ( m_pUnk != nullptr )
    {
      v16 = m_pUnk->GetCollideable(this: m_pUnk);
      CM_WorldSpaceCenter(pCollideable: v16, pCenter: &sound.vOrigin);
    }
  }
  if ( pUtlVecOrigins != nullptr )
    CUtlVector<Vector,CUtlMemory<Vector,int>>::InsertBefore(
      this: pUtlVecOrigins,
      elem: pUtlVecOrigins->m_Size,
      src: &sound.vOrigin);
  if ( soundtime != 0.0 )
  {
    pSoundEmittingEntitya = sv.m_flTickInterval;
    sound.fTickTime = CBaseServer::GetFinalTickTime(this: &sv);
    soundtimea = pSoundEmittingEntitya + soundtime;
    FinalTickTime = CBaseServer::GetFinalTickTime(this: &sv);
    sound.nFlags |= 0x10u;
    sound.fDelay = soundtimea - FinalTickTime;
  }
  if ( pSample != nullptr && TestSoundChar(pch: pSample, c: 33) != 0 )
  {
    sound.bIsSentence = true;
    v18 = PSkipSoundChars(pch: pSample);
    sound.nSoundNum = V_atoi(str: v18);
    if ( sound.nSoundNum >= VOX_SentenceCount() )
    {
      v19 = PSkipSoundChars(pch: pSample);
      ConMsg(a1: "SV_StartSound: invalid sentence number: %s", v19);
      return;
    }
    goto LABEL_22;
  }
  sound.bIsSentence = false;
  if ( (sound.nFlags & 0x400) != 0 )
  {
    sound.nSoundNum = iSoundEntryIndex;
LABEL_22:
    CGameServer::BroadcastSound(this: &sv, &sound, filter);
    return;
  }
  nSoundNum = CGameServer::LookupSoundIndex(this: &sv, name: pSample);
  sound.nSoundNum = nSoundNum;
  if ( nSoundNum != 0 )
  {
    if ( CGameServer::GetSound(this: &sv, index: nSoundNum) != nullptr )
      goto LABEL_22;
    nSoundNum = sound.nSoundNum;
  }
  ConMsg(a1: "SV_StartSound: %s not precached (%d)\n", pSample, nSoundNum);
}

//------------------------------------------------------------------------------
// Address: 0x10127720
// Name: void SV_ReplicateConVarChange(class ConVar const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SV_ReplicateConVarChange(const ConVar *var, const char *newValue)
{
  const char *v2; // eax
  const char *v3; // [esp-4h] [ebp-28h]
  NET_SetConVar cvarMsg; // [esp+0h] [ebp-24h] BYREF

  if ( sv.m_State >= ss_active && sv.m_nMaxclients > 1 )
  {
    v3 = Host_CleanupConVarStringValue(invalue: newValue);
    v2 = var->GetName(this: var);
    NET_SetConVar::NET_SetConVar(this: &cvarMsg, name: v2, value: v3);
    CBaseServer::BroadcastMessage(this: &sv, msg: &cvarMsg, onlyActive: false, reliable: false);
    CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&cvarMsg.m_ConVars);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10127780
// Name: void SV_AddOriginToPVS(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SV_AddOriginToPVS(const Vector *vOrigin)
{
  int v1; // ebx
  int v2; // eax
  int *m_pMemory; // edx
  int v4; // edi
  int m_Size; // eax
  int v6; // ecx
  int v7; // esi
  int v8; // eax
  int *v9; // eax
  int v10; // eax
  int *v11; // edx
  int v12; // edi
  int v13; // eax
  int v14; // ecx
  int v15; // esi
  int v16; // eax
  int *v17; // eax

  v1 = CM_PointLeafnum(p: vOrigin);
  v2 = CM_LeafCluster(leafnum: v1);
  m_pMemory = g_ClustersNetworked.m_Memory.m_pMemory;
  v4 = v2;
  m_Size = g_ClustersNetworked.m_Size;
  v6 = 0;
  if ( g_ClustersNetworked.m_Size <= 0 )
    goto LABEL_6;
  while ( g_ClustersNetworked.m_Memory.m_pMemory[v6] != v4 )
  {
    if ( ++v6 >= g_ClustersNetworked.m_Size )
      goto LABEL_6;
  }
  if ( v6 == -1 )
  {
LABEL_6:
    v7 = g_ClustersNetworked.m_Size;
    if ( g_ClustersNetworked.m_Size + 1 > g_ClustersNetworked.m_Memory.m_nAllocationCount )
    {
      CUtlMemory<INetMessage *,int>::Grow(
        this: (CUtlMemory<S3RGBA,int> *)&g_ClustersNetworked,
        num: g_ClustersNetworked.m_Size - g_ClustersNetworked.m_Memory.m_nAllocationCount + 1);
      m_Size = g_ClustersNetworked.m_Size;
      m_pMemory = g_ClustersNetworked.m_Memory.m_pMemory;
    }
    g_ClustersNetworked.m_Size = m_Size + 1;
    v8 = m_Size - v7;
    g_ClustersNetworked.m_pElements = m_pMemory;
    if ( v8 > 0 )
    {
      _V_memmove(dest: &m_pMemory[v7 + 1], src: &m_pMemory[v7], count: 4 * v8);
      m_pMemory = g_ClustersNetworked.m_Memory.m_pMemory;
    }
    v9 = &m_pMemory[v7];
    if ( v9 != nullptr )
      *v9 = v4;
    SV_AddToFatPVS(nClusterIndex: v4);
    v10 = CM_LeafArea(leafnum: v1);
    v11 = g_AreasNetworked.m_Memory.m_pMemory;
    v12 = v10;
    v13 = g_AreasNetworked.m_Size;
    v14 = 0;
    if ( g_AreasNetworked.m_Size <= 0 )
      goto LABEL_17;
    while ( g_AreasNetworked.m_Memory.m_pMemory[v14] != v12 )
    {
      if ( ++v14 >= g_AreasNetworked.m_Size )
        goto LABEL_17;
    }
    if ( v14 == -1 )
    {
LABEL_17:
      v15 = g_AreasNetworked.m_Size;
      if ( g_AreasNetworked.m_Size + 1 > g_AreasNetworked.m_Memory.m_nAllocationCount )
      {
        CUtlMemory<INetMessage *,int>::Grow(
          this: (CUtlMemory<S3RGBA,int> *)&g_AreasNetworked,
          num: g_AreasNetworked.m_Size - g_AreasNetworked.m_Memory.m_nAllocationCount + 1);
        v13 = g_AreasNetworked.m_Size;
        v11 = g_AreasNetworked.m_Memory.m_pMemory;
      }
      g_AreasNetworked.m_Size = v13 + 1;
      v16 = v13 - v15;
      g_AreasNetworked.m_pElements = v11;
      if ( v16 > 0 )
      {
        _V_memmove(dest: &v11[v15 + 1], src: &v11[v15], count: 4 * v16);
        v11 = g_AreasNetworked.m_Memory.m_pMemory;
      }
      v17 = &v11[v15];
      if ( v17 != nullptr )
        *v17 = v12;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101279F0
// Name: public: virtual void CGameServer::Clear(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameServer::Clear(CGameServer *this)
{
  ServerClass *j; // eax
  int v3; // eax
  CEventInfo *v4; // esi
  int *m_pMemory; // eax
  int i; // [esp+8h] [ebp-4h]

  this->m_pModelPrecacheTable = nullptr;
  this->m_pGenericPrecacheTable = nullptr;
  this->m_pSoundPrecacheTable = nullptr;
  this->m_pDecalPrecacheTable = nullptr;
  this->m_bIsLevelMainMenuBackground = false;
  this->m_bLoadgame = false;
  CCommonHostState::SetWorldModel(this: &host_state, pModel: nullptr);
  _V_memset(dest: this->m_szStartspot, fill: 0, count: 64);
  this->num_edicts = 0;
  this->max_edicts = 0;
  this->edicts = nullptr;
  g_ServerGlobalVariables.maxEntities = 0;
  g_ServerGlobalVariables.pEdicts = nullptr;
  if ( serverGameDLL != nullptr )
  {
    for ( j = serverGameDLL->GetAllServerClasses(this: serverGameDLL); j != nullptr; j = j->m_pNext )
      j->m_InstanceBaselineIndex = 0xFFFF;
  }
  v3 = 0;
  for ( i = 0; v3 < this->m_TempEntities.m_Size; i = v3 )
  {
    v4 = this->m_TempEntities.m_Memory.m_pMemory[v3];
    if ( v4 != nullptr )
    {
      if ( v4->pData != nullptr )
        free(pMem: v4->pData);
      v4->filter.m_Recipients.m_Size = 0;
      if ( v4->filter.m_Recipients.m_Memory.m_nGrowSize >= 0 )
      {
        if ( v4->filter.m_Recipients.m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v4->filter.m_Recipients.m_Memory.m_pMemory);
          v4->filter.m_Recipients.m_Memory.m_pMemory = nullptr;
        }
        v4->filter.m_Recipients.m_Memory.m_nAllocationCount = 0;
      }
      m_pMemory = v4->filter.m_Recipients.m_Memory.m_pMemory;
      v4->filter.m_Recipients.m_pElements = m_pMemory;
      if ( v4->filter.m_Recipients.m_Memory.m_nGrowSize >= 0 )
      {
        if ( m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
          v4->filter.m_Recipients.m_Memory.m_pMemory = nullptr;
        }
        v4->filter.m_Recipients.m_Memory.m_nAllocationCount = 0;
      }
      v4->filter.__vftable = (CEngineRecipientFilter_vtbl *)&IRecipientFilter::`vftable';
      free(pMem: v4);
      v3 = i;
    }
    ++v3;
  }
  this->m_TempEntities.m_Size = 0;
  if ( this->m_TempEntities.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_TempEntities.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_TempEntities.m_Memory.m_pMemory);
      this->m_TempEntities.m_Memory.m_pMemory = nullptr;
    }
    this->m_TempEntities.m_Memory.m_nAllocationCount = 0;
  }
  this->m_TempEntities.m_pElements = this->m_TempEntities.m_Memory.m_pMemory;
  CBaseServer::Clear(this);
}

//------------------------------------------------------------------------------
// Address: 0x10127B70
// Name: public: virtual void CGameServer::SendClientMessages(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameServer::SendClientMessages(CGameServer *this, bool bSendSnapshots)
{
  int v2; // ebx
  int (__thiscall *GetClientCount)(struct CGameServer *); // edx
  CGameClient *v5; // esi
  int v6; // eax
  const netadr_s *v7; // eax
  CFrameSnapshot *v8; // ebx
  int m_Size; // eax
  CEventInfo **v10; // eax
  signed int v11; // esi
  int v12; // edi
  CGameClient *v13; // esi
  CClientFrame *SendFrame; // eax
  const char *v15; // [esp-Ch] [ebp-130h]
  CGameClient *pReceivingClients[64]; // [esp+8h] [ebp-11Ch] BYREF
  CParallelProcessor<CGameClient *,CFuncJobItemProcessor<CGameClient *>,1> v17; // [esp+108h] [ebp-1Ch] BYREF
  int receivingClientCount; // [esp+120h] [ebp-4h]

  v2 = 0;
  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "SendClientMessages",
    a3: 0,
    a4: "Networking",
    a5: false,
    a6: 4);
  GetClientCount = this->GetClientCount;
  receivingClientCount = 0;
  if ( GetClientCount(this) > 0 )
  {
    do
    {
      v5 = (CGameClient *)this->m_Clients.m_Memory.m_pMemory[v2];
      if ( v5->ShouldSendMessages(this: v5) )
      {
        if ( bSendSnapshots && v5->IsActive(this: &v5->IClient) )
        {
          v6 = receivingClientCount;
          pReceivingClients[receivingClientCount] = v5;
          receivingClientCount = v6 + 1;
        }
        else if ( !v5->IsFakeClient(this: &v5->IClient) )
        {
          if ( NET_IsMultiplayer() && v5->m_NetChannel->GetSequenceNr(this: v5->m_NetChannel, a2: 1) == 0 )
          {
            v7 = (const netadr_s *)((int (__thiscall *)(INetChannel *, const char *, int))v5->m_NetChannel->GetRemoteAddress)(
                                     a1: v5->m_NetChannel,
                                     a2: "%c00000000000000",
                                     a3: 66);
            NET_OutOfBandPrintf(sock: this->m_Socket, adr: v7, format: v15);
          }
          v5->m_NetChannel->Transmit(this: v5->m_NetChannel, a2: false);
          v5->UpdateSendState(this: v5);
        }
      }
      else if ( v5->IsSplitScreenUser(this: &v5->IClient) )
      {
        CGameClient::WriteViewAngleUpdate(this: v5);
      }
      ++v2;
    }
    while ( v2 < this->GetClientCount(this) );
    if ( receivingClientCount != 0 )
    {
      v8 = CFrameSnapshotManager::TakeTickSnapshot(this: framesnapshotmanager, tickcount: this->m_nTickCount);
      m_Size = this->m_TempEntities.m_Size;
      if ( m_Size > 0 )
      {
        v8->m_nTempEntities = m_Size;
        v10 = (CEventInfo **)MemAlloc_Alloc(nSize: (unsigned __int64)(unsigned int)m_Size >> 30 != 0 ? -1 : 4 * m_Size);
        v8->m_pTempEntities = v10;
        _V_memcpy(dest: v10, src: this->m_TempEntities.m_Memory.m_pMemory, count: 4 * this->m_TempEntities.m_Size);
        this->m_TempEntities.m_Size = 0;
      }
      v11 = receivingClientCount;
      SV_ComputeClientPacks(clientCount: receivingClientCount, clients: pReceivingClients, snapshot: v8);
      v12 = 0;
      if ( v11 > 1
        && sv_parallel_sendsnapshot.m_pParent != nullptr
        && sv_parallel_sendsnapshot.m_pParent->m_Value.m_nValue != 0 )
      {
        v17.m_pItems.m_value = nullptr;
        v17.m_pLimit = nullptr;
        _InterlockedExchange((volatile __int32 *)&v17.m_pItems, 0);
        v17.m_ItemProcessor.m_pfnProcess = SV_ParallelSendSnapshot;
        v17.m_ItemProcessor.m_pfnBegin = nullptr;
        v17.m_ItemProcessor.m_pfnEnd = nullptr;
        CParallelProcessor<CGameClient *,CFuncJobItemProcessor<CGameClient *>,1>::Run(
          this: &v17,
          pItems: pReceivingClients,
          nItems: v11,
          nChunkSize: 1,
          nMaxParallel: 0x7FFFFFFF,
          pThreadPool: nullptr);
      }
      else if ( v11 > 0 )
      {
        do
        {
          v13 = pReceivingClients[v12];
          SendFrame = CGameClient::GetSendFrame(this: v13);
          if ( SendFrame != nullptr )
          {
            v13->SendSnapshot(this: v13, a2: SendFrame);
            v13->UpdateSendState(this: v13);
          }
          ++v12;
        }
        while ( v12 < receivingClientCount );
      }
      CFrameSnapshot::ReleaseReference(this: v8);
    }
  }
  serverGameClients->PostClientMessagesSent(this: serverGameClients);
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
}

//------------------------------------------------------------------------------
// Address: 0x10127DC0
// Name: void SV_SendClientUpdates(bool,bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SV_SendClientUpdates(BOOL bIsSimulating)
{
  bool v1; // bl
  bool v2; // al

  v1 = s_bForceSend;
  s_bForceSend = false;
  if ( serverGameDLL != nullptr )
    serverGameDLL->PreClientUpdate(this: serverGameDLL, a2: bIsSimulating);
  v2 = bIsSimulating || v1;
  CGameServer::SendClientMessages(this: &sv, bSendSnapshots: v2);
  CNetworkStringTableContainer::SetTick(this: networkStringTableContainerServer, tick_count: sv.m_nTickCount + 1);
}

//------------------------------------------------------------------------------
// Address: 0x10127E20
// Name: void SV_Frame(bool)
// Source: json
//------------------------------------------------------------------------------
void __usercall SV_Frame(int a1@<ebx>, int a2@<edi>, int finalTick)
{
  CSteam3Server *v3; // eax
  int v4; // [esp-4h] [ebp-Ch]
  int bSendDuringPause; // [esp+0h] [ebp-8h] BYREF
  BOOL bIsSimulating; // [esp+4h] [ebp-4h] BYREF

  if ( serverGameDLL != nullptr && (_BYTE)finalTick != 0 )
    ((void (__stdcall *)(int))serverGameDLL->Think)(a1: finalTick);
  if ( sv.m_State >= ss_active && Host_ShouldRun() )
  {
    v4 = a1;
    g_ServerGlobalVariables.frametime = host_state.interval_per_tick;
    LOBYTE(bIsSimulating) = SV_IsSimulating();
    LOBYTE(a1) = sv_noclipduringpause != nullptr
              && sv_noclipduringpause->m_pParent != nullptr
              && sv_noclipduringpause->m_pParent->m_Value.m_nValue != 0;
    LOBYTE(bSendDuringPause) = a1;
    CNetworkStringTableContainer::Lock(this: networkStringTableContainerServer, bLock: false);
    CBaseServer::RunFrame(this: &sv, a2: a1);
    if ( sv.m_Clients.m_Size <= 0 )
    {
      if ( sv.m_nMaxclients > 1 )
        SV_Think(bIsSimulating: false);
    }
    else
    {
      if ( serverGameDLL != nullptr
        && !serverGameDLL->IsRestoring(this: serverGameDLL)
        && (bIsSimulating || (_BYTE)a1 != 0) )
      {
        CNetworkStringTableContainer::SetTick(this: networkStringTableContainerServer, tick_count: ++sv.m_nTickCount);
      }
      SV_Think(bIsSimulating);
    }
    if ( (_BYTE)finalTick != 0 )
    {
      if ( g_bThreadedEngine && sv.m_nMaxclients <= 1 )
        g_pDeferredServerWork = CreateFunctor<void,bool,bool,bool,bool>(
                                  pfnProxied: (void (__cdecl *)(bool, bool))SV_SendClientUpdates,
                                  arg1: (const bool *)&bIsSimulating,
                                  arg2: (const bool *)&bSendDuringPause);
      else
        SV_SendClientUpdates(bIsSimulating);
    }
    CNetworkStringTableContainer::Lock(this: networkStringTableContainerServer, bLock: true);
    if ( sv.m_nMaxclients > 1 || serverGameDLL->ShouldPreferSteamAuth(this: serverGameDLL) )
    {
      v3 = Steam3Server();
      CSteam3Server::RunFrame(this: v3, a2: v4, a3: a2);
    }
  }
  else
  {
    NET_ProcessSocket(sock: 1, handler: &sv);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10127FA0
// Name: public: CUtlHash<struct CGameSaveRestoreInfo::CHashElement,class CGameSaveRestoreInfo::CHashFuncs,class CGameSaveRestoreInfo::CHashFuncs>::CUtlHash<struct CGameSaveRestoreInfo::CHashElement,class CGameSaveRestoreInfo::CHashFuncs,class CGameSaveRestoreInfo::CHashFuncs>(int,int,int,class CGameSaveRestoreInfo::CHashFuncs,class CGameSaveRestoreInfo::CHashFuncs)
// Source: json
//------------------------------------------------------------------------------
CUtlHash<CGameSaveRestoreInfo::CHashElement,CGameSaveRestoreInfo::CHashFuncs,CGameSaveRestoreInfo::CHashFuncs> *__thiscall CUtlHash<CGameSaveRestoreInfo::CHashElement,CGameSaveRestoreInfo::CHashFuncs,CGameSaveRestoreInfo::CHashFuncs>::CUtlHash<CGameSaveRestoreInfo::CHashElement,CGameSaveRestoreInfo::CHashFuncs,CGameSaveRestoreInfo::CHashFuncs>(
        CUtlHash<CGameSaveRestoreInfo::CHashElement,CGameSaveRestoreInfo::CHashFuncs,CGameSaveRestoreInfo::CHashFuncs> *this,
        int bucketCount,
        int growCount,
        int initCount,
        CGameSaveRestoreInfo::CHashFuncs compareFunc,
        CGameSaveRestoreInfo::CHashFuncs keyFunc)
{
  int v6; // esi
  int v8; // eax
  CUtlMemory<ResourceEntryInfo,int> *v9; // esi
  int m_nAllocationCount; // eax
  ResourceEntryInfo *m_pMemory; // ecx
  int v12; // eax
  bool v13; // zf
  int v15; // [esp+Ch] [ebp-8h]
  int v16; // [esp+10h] [ebp-4h]

  v6 = bucketCount;
  this->m_Buckets.m_Memory.m_pMemory = nullptr;
  this->m_Buckets.m_Memory.m_nAllocationCount = 0;
  this->m_Buckets.m_Memory.m_nGrowSize = 0;
  this->m_Buckets.m_Size = 0;
  this->m_Buckets.m_pElements = nullptr;
  if ( bucketCount >= 0x10000 )
  {
    bucketCount = 0x10000;
    v6 = 0x10000;
  }
  CUtlVector<CUtlVector<CGameSaveRestoreInfo::CHashElement,CUtlMemory<CGameSaveRestoreInfo::CHashElement,int>>,CUtlMemory<CUtlVector<CGameSaveRestoreInfo::CHashElement,CUtlMemory<CGameSaveRestoreInfo::CHashElement,int>>,int>>::RemoveAll(this: &this->m_Buckets);
  CUtlVector<CUtlVector<CSplitPacketEntry,CUtlMemory<CSplitPacketEntry,int>>,CUtlMemory<CUtlVector<CSplitPacketEntry,CUtlMemory<CSplitPacketEntry,int>>,int>>::InsertMultipleBefore(
    this: &this->m_Buckets,
    elem: this->m_Buckets.m_Size,
    num: v6);
  if ( v6 > 0 )
  {
    v8 = 0;
    v16 = 0;
    v15 = v6;
    do
    {
      v9 = (CUtlMemory<ResourceEntryInfo,int> *)((char *)this->m_Buckets.m_Memory.m_pMemory + v8);
      v9[1].m_pMemory = nullptr;
      if ( initCount != 0 )
      {
        m_nAllocationCount = v9->m_nAllocationCount;
        if ( initCount > m_nAllocationCount )
          CUtlMemory<CAsyncWavDataCache::DeadBufferEntry_t,int>::Grow(this: v9, num: initCount - m_nAllocationCount);
        v9[1].m_pMemory = (ResourceEntryInfo *)((char *)v9[1].m_pMemory + initCount);
        m_pMemory = v9->m_pMemory;
        v12 = (int)v9[1].m_pMemory - initCount;
        v9[1].m_nAllocationCount = (int)v9->m_pMemory;
        if ( v12 > 0 && initCount > 0 )
          _V_memmove(dest: &m_pMemory[initCount], src: m_pMemory, count: 8 * v12);
      }
      this->m_Buckets.m_Memory.m_pMemory[v16].m_Memory.m_nGrowSize = growCount;
      v8 = v16 * 20 + 20;
      v13 = v15-- == 1;
      ++v16;
    }
    while ( !v13 );
    v6 = bucketCount;
  }
  this->m_bPowerOfTwo = ((v6 - 1) & v6) == 0;
  this->m_ModMask = ((v6 - 1) & v6) == 0 ? v6 - 1 : 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10128080
// Name: public: CSaveRestoreData::CSaveRestoreData(void)
// Source: json
//------------------------------------------------------------------------------
CSaveRestoreData *__thiscall CSaveRestoreData::CSaveRestoreData(CSaveRestoreData *this)
{
  CGameSaveRestoreInfo *v2; // edi
  CGameSaveRestoreInfo::CHashFuncs v4; // [esp-8h] [ebp-18h] BYREF
  CGameSaveRestoreInfo::CHashFuncs v5; // [esp-4h] [ebp-14h]
  CGameSaveRestoreInfo::CHashFuncs *v6; // [esp+Ch] [ebp-4h]

  v5 = (CGameSaveRestoreInfo::CHashFuncs)this;
  this->pBaseData = nullptr;
  this->pCurrentData = nullptr;
  v4 = (CGameSaveRestoreInfo::CHashFuncs)this;
  this->size = 0;
  this->bufferSize = 0;
  v6 = &v4;
  this->tokenCount = 0;
  v2 = &this->CGameSaveRestoreInfo;
  this->pTokens = nullptr;
  this->m_nEntityDataSize = 0;
  this->tableCount = 0;
  this->pTable = nullptr;
  this->m_pCurrentEntity = nullptr;
  CUtlHash<CGameSaveRestoreInfo::CHashElement,CGameSaveRestoreInfo::CHashFuncs,CGameSaveRestoreInfo::CHashFuncs>::CUtlHash<CGameSaveRestoreInfo::CHashElement,CGameSaveRestoreInfo::CHashFuncs,CGameSaveRestoreInfo::CHashFuncs>(
    this: &this->m_EntityToIndex,
    bucketCount: 0,
    growCount: 0,
    initCount: 0,
    compareFunc: v4,
    keyFunc: v5);
  memset(dst: (unsigned __int8 *)v2, value: 0, count: 0x550u);
  v2->modelSpaceOffset.x = 0.0;
  v2->modelSpaceOffset.y = 0.0;
  v2->modelSpaceOffset.z = 0.0;
  this->bAsync = false;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10128110
// Name: public: void CGameServer::FinishRestore(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CGameServer::FinishRestore(CGameServer *this@<ecx>, int a2@<esi>)
{
  int v3; // esi
  levellist_t *levelList; // edi
  CUtlVector<CGameSaveRestoreInfo::CHashElement,CUtlMemory<CGameSaveRestoreInfo::CHashElement,int> > *m_pMemory; // eax
  int v6; // [esp-8h] [ebp-6B4h]
  int v7; // [esp-4h] [ebp-6B0h]
  CSaveRestoreData currentLevelData; // [esp+4h] [ebp-6A8h] BYREF
  char name[260]; // [esp+5A8h] [ebp-104h] BYREF

  CSaveRestoreData::CSaveRestoreData(this: &currentLevelData);
  if ( this->m_bLoadgame )
  {
    g_ServerGlobalVariables.pSaveData = &currentLevelData;
    serverGameDLL->BuildAdjacentMapList(this: serverGameDLL);
    if ( saverestore->IsXSave(this: saverestore) )
    {
      V_snprintf(pDest: name, maxLen: 260, pFormat: "%s:\\%s.HL2", host_parms.mod, this->m_szMapname);
    }
    else
    {
      v6 = ((int (__thiscall *)(ISaveRestore *, char *))saverestore->GetSaveDir)(a1: saverestore, a2: this->m_szMapname);
      V_snprintf(pDest: name, maxLen: 260, pFormat: "%s%s.HL2", v6, v7);
    }
    V_FixSlashes(pname: name, separator: 92);
    ((void (__thiscall *)(ISaveRestore *, char *, _DWORD, int))saverestore->RestoreClientState)(
      a1: saverestore,
      a2: name,
      a3: 0,
      a4: a2);
    if ( g_ServerGlobalVariables.eLoadType == MapLoad_Transition )
    {
      v3 = 0;
      if ( currentLevelData.levelInfo.connectionCount > 0 )
      {
        levelList = currentLevelData.levelInfo.levelList;
        do
        {
          saverestore->RestoreAdjacenClientState(this: saverestore, a2: (const char *)levelList);
          ++v3;
          ++levelList;
        }
        while ( v3 < currentLevelData.levelInfo.connectionCount );
      }
    }
    saverestore->OnFinishedClientRestore(this: saverestore);
    g_ServerGlobalVariables.pSaveData = nullptr;
    this->m_bLoadgame = false;
    saverestore->SetIsXSave(this: saverestore, a2: false);
    CUtlHash<DispCollPlaneIndex_t,CPlaneIndexHashFuncs,CPlaneIndexHashFuncs>::Purge(this: &currentLevelData.m_EntityToIndex);
    CUtlVector<CUtlVector<CGameSaveRestoreInfo::CHashElement,CUtlMemory<CGameSaveRestoreInfo::CHashElement,int>>,CUtlMemory<CUtlVector<CGameSaveRestoreInfo::CHashElement,CUtlMemory<CGameSaveRestoreInfo::CHashElement,int>>,int>>::RemoveAll(this: &currentLevelData.m_EntityToIndex.m_Buckets);
    m_pMemory = currentLevelData.m_EntityToIndex.m_Buckets.m_Memory.m_pMemory;
    if ( currentLevelData.m_EntityToIndex.m_Buckets.m_Memory.m_nGrowSize >= 0 )
    {
      if ( currentLevelData.m_EntityToIndex.m_Buckets.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: currentLevelData.m_EntityToIndex.m_Buckets.m_Memory.m_pMemory);
        m_pMemory = nullptr;
        currentLevelData.m_EntityToIndex.m_Buckets.m_Memory.m_pMemory = nullptr;
      }
      currentLevelData.m_EntityToIndex.m_Buckets.m_Memory.m_nAllocationCount = 0;
    }
    currentLevelData.m_EntityToIndex.m_Buckets.m_pElements = m_pMemory;
    if ( currentLevelData.m_EntityToIndex.m_Buckets.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
  }
  else
  {
    CUtlHash<DispCollPlaneIndex_t,CPlaneIndexHashFuncs,CPlaneIndexHashFuncs>::Purge(this: &currentLevelData.m_EntityToIndex);
    CUtlVector<CUtlVector<CSplitPacketEntry,CUtlMemory<CSplitPacketEntry,int>>,CUtlMemory<CUtlVector<CSplitPacketEntry,CUtlMemory<CSplitPacketEntry,int>>,int>>::~CUtlVector<CUtlVector<CSplitPacketEntry,CUtlMemory<CSplitPacketEntry,int>>,CUtlMemory<CUtlVector<CSplitPacketEntry,CUtlMemory<CSplitPacketEntry,int>>,int>>(this: &currentLevelData.m_EntityToIndex.m_Buckets);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103133A0
// Name: _dynamic_initializer_for__sv_unlockedchapters__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_unlockedchapters__()
{
  ConVar::ConVar(
    this: &sv_unlockedchapters,
    pName: "sv_unlockedchapters",
    pDefaultValue: "1",
    flags: 128,
    pHelpString: "Highest unlocked game chapter.");
  return atexit(func: dynamic_atexit_destructor_for__sv_unlockedchapters__);
}

//------------------------------------------------------------------------------
// Address: 0x103170A0
// Name: _dynamic_initializer_for__sv_multiplayer_maxtempentities__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_multiplayer_maxtempentities__()
{
  ConVar::ConVar(
    this: &sv_multiplayer_maxtempentities,
    pName: "sv_multiplayer_maxtempentities",
    pDefaultValue: "32",
    flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__sv_multiplayer_maxtempentities__);
}

//------------------------------------------------------------------------------
// Address: 0x103170D0
// Name: _dynamic_initializer_for__sv_multiplayer_maxsounds__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_multiplayer_maxsounds__()
{
  ConVar::ConVar(this: &sv_multiplayer_maxsounds, pName: "sv_multiplayer_sounds", pDefaultValue: "20", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__sv_multiplayer_maxsounds__);
}

//------------------------------------------------------------------------------
// Address: 0x10317100
// Name: _dynamic_initializer_for__sv_timeout__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_timeout__()
{
  ConVar::ConVar(
    this: &sv_timeout,
    pName: "sv_timeout",
    pDefaultValue: "65",
    flags: 0,
    pHelpString: "After this many seconds without a message from a client, the client is dropped");
  return atexit(func: dynamic_atexit_destructor_for__sv_timeout__);
}

//------------------------------------------------------------------------------
// Address: 0x10317130
// Name: _dynamic_initializer_for__sv_maxrate__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_maxrate__()
{
  ConVar::ConVar(
    this: &sv_maxrate,
    pName: "sv_maxrate",
    pDefaultValue: "0",
    flags: 532480,
    pHelpString: "Max bandwidth rate allowed on server, 0 == unlimited",
    bMin: true,
    fMin: 0.0,
    bMax: true,
    fMax: 30000.0);
  return atexit(func: dynamic_atexit_destructor_for__sv_maxrate__);
}

//------------------------------------------------------------------------------
// Address: 0x10317170
// Name: _dynamic_initializer_for__sv_minrate__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_minrate__()
{
  ConVar::ConVar(
    this: &sv_minrate,
    pName: "sv_minrate",
    pDefaultValue: "5000",
    flags: 532480,
    pHelpString: "Min bandwidth rate allowed on server, 0 == unlimited",
    bMin: true,
    fMin: 0.0,
    bMax: true,
    fMax: 30000.0);
  return atexit(func: dynamic_atexit_destructor_for__sv_minrate__);
}

//------------------------------------------------------------------------------
// Address: 0x103171B0
// Name: _dynamic_initializer_for__sv_maxupdaterate__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_maxupdaterate__()
{
  ConVar::ConVar(
    this: &sv_maxupdaterate,
    pName: "sv_maxupdaterate",
    pDefaultValue: "66",
    flags: 0x2000,
    pHelpString: "Maximum updates per second that the server will allow");
  return atexit(func: dynamic_atexit_destructor_for__sv_maxupdaterate__);
}

//------------------------------------------------------------------------------
// Address: 0x103171E0
// Name: _dynamic_initializer_for__sv_minupdaterate__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_minupdaterate__()
{
  ConVar::ConVar(
    this: &sv_minupdaterate,
    pName: "sv_minupdaterate",
    pDefaultValue: "10",
    flags: 0x2000,
    pHelpString: "Minimum updates per second that the server will allow");
  return atexit(func: dynamic_atexit_destructor_for__sv_minupdaterate__);
}

//------------------------------------------------------------------------------
// Address: 0x10317210
// Name: _dynamic_initializer_for__sv_stressbots__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_stressbots__()
{
  ConVar::ConVar(
    this: &sv_stressbots,
    pName: "sv_stressbots",
    pDefaultValue: "0",
    flags: 2,
    pHelpString: "If set to 1, the server calculates data and fills packets to bots. Used for perf testing.");
  return atexit(func: dynamic_atexit_destructor_for__sv_stressbots__);
}

//------------------------------------------------------------------------------
// Address: 0x10317240
// Name: _dynamic_initializer_for__sv_allowdownload__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_allowdownload__()
{
  ConVar::ConVar(
    this: &sv_allowdownload,
    pName: "sv_allowdownload",
    pDefaultValue: "1",
    flags: 0,
    pHelpString: "Allow clients to download files");
  return atexit(func: dynamic_atexit_destructor_for__sv_allowdownload__);
}

//------------------------------------------------------------------------------
// Address: 0x10317270
// Name: _dynamic_initializer_for__sv_allowupload__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_allowupload__()
{
  ConVar::ConVar(
    this: &sv_allowupload,
    pName: "sv_allowupload",
    pDefaultValue: "1",
    flags: 0,
    pHelpString: "Allow clients to upload customizations files");
  return atexit(func: dynamic_atexit_destructor_for__sv_allowupload__);
}

//------------------------------------------------------------------------------
// Address: 0x103172A0
// Name: _dynamic_initializer_for__sv_sendtables__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_sendtables__()
{
  ConVar::ConVar(
    this: &sv_sendtables,
    pName: "sv_sendtables",
    pDefaultValue: "0",
    flags: 2,
    pHelpString: "Force full sendtable sending path.");
  return atexit(func: dynamic_atexit_destructor_for__sv_sendtables__);
}

//------------------------------------------------------------------------------
// Address: 0x10317330
// Name: _dynamic_initializer_for__sv_maxclientframes__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_maxclientframes__()
{
  ConVar::ConVar(this: &sv_maxclientframes, pName: "sv_maxclientframes", pDefaultValue: "128", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__sv_maxclientframes__);
}

//------------------------------------------------------------------------------
// Address: 0x10317360
// Name: _dynamic_initializer_for__sv_extra_client_connect_time__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_extra_client_connect_time__()
{
  ConVar::ConVar(
    this: &sv_extra_client_connect_time,
    pName: "sv_extra_client_connect_time",
    pDefaultValue: "15.0",
    flags: 0,
    pHelpString: "Seconds after client connect during which extra frames are buffered to prevent non-delta'd update");
  return atexit(func: dynamic_atexit_destructor_for__sv_extra_client_connect_time__);
}

//------------------------------------------------------------------------------
// Address: 0x10317390
// Name: _dynamic_initializer_for__sv_sound_discardextraunreliable__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_sound_discardextraunreliable__()
{
  ConVar::ConVar(
    this: &sv_sound_discardextraunreliable,
    pName: "sv_sound_discardextraunreliable",
    pDefaultValue: "1",
    flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__sv_sound_discardextraunreliable__);
}

//------------------------------------------------------------------------------
// Address: 0x103173C0
// Name: _dynamic_initializer_for__sv_deltatime__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_deltatime__()
{
  ConVar::ConVar(
    this: &sv_deltatime,
    pName: "sv_deltatime",
    pDefaultValue: "0",
    flags: 0,
    pHelpString: "Enable profiling of CalcDelta calls");
  return atexit(func: dynamic_atexit_destructor_for__sv_deltatime__);
}

//------------------------------------------------------------------------------
// Address: 0x103173F0
// Name: _dynamic_initializer_for__sv_deltaprint__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_deltaprint__()
{
  ConVar::ConVar(
    this: &sv_deltaprint,
    pName: "sv_deltaprint",
    pDefaultValue: "0",
    flags: 0,
    pHelpString: "Print accumulated CalcDelta profiling data (only if sv_deltatime is on)");
  return atexit(func: dynamic_atexit_destructor_for__sv_deltaprint__);
}

//------------------------------------------------------------------------------
// Address: 0x10317430
// Name: _dynamic_initializer_for__sv_filterban__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_filterban__()
{
  ConVar::ConVar(
    this: &sv_filterban,
    pName: "sv_filterban",
    pDefaultValue: "1",
    flags: 0,
    pHelpString: "Set packet filtering by IP mode");
  return atexit(func: dynamic_atexit_destructor_for__sv_filterban__);
}

//------------------------------------------------------------------------------
// Address: 0x10317660
// Name: _dynamic_initializer_for__sv_creationtickcheck__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_creationtickcheck__()
{
  ConVar::ConVar(
    this: &sv_creationtickcheck,
    pName: "sv_creationtickcheck",
    pDefaultValue: "1",
    flags: 16386,
    pHelpString: "Do extended check for encoding of timestamps against tickcount");
  return atexit(func: dynamic_atexit_destructor_for__sv_creationtickcheck__);
}

//------------------------------------------------------------------------------
// Address: 0x103176B0
// Name: _dynamic_initializer_for__sv_max_queries_sec__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_max_queries_sec__()
{
  ConVar::ConVar(
    this: &sv_max_queries_sec,
    pName: "sv_max_queries_sec",
    pDefaultValue: "3.0",
    flags: 0,
    pHelpString: "Maximum queries per second to respond to from a single IP address.");
  return atexit(func: dynamic_atexit_destructor_for__sv_max_queries_sec__);
}

//------------------------------------------------------------------------------
// Address: 0x103176E0
// Name: _dynamic_initializer_for__sv_max_queries_window__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_max_queries_window__()
{
  ConVar::ConVar(
    this: &sv_max_queries_window,
    pName: "sv_max_queries_window",
    pDefaultValue: "30",
    flags: 0,
    pHelpString: "Window over which to average queries per second averages.");
  return atexit(func: dynamic_atexit_destructor_for__sv_max_queries_window__);
}

//------------------------------------------------------------------------------
// Address: 0x10317710
// Name: _dynamic_initializer_for__sv_max_queries_sec_global__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_max_queries_sec_global__()
{
  ConVar::ConVar(
    this: &sv_max_queries_sec_global,
    pName: "sv_max_queries_sec_global",
    pDefaultValue: "60",
    flags: 0,
    pHelpString: "Maximum queries per second to respond to from anywhere.");
  return atexit(func: dynamic_atexit_destructor_for__sv_max_queries_sec_global__);
}

//------------------------------------------------------------------------------
// Address: 0x10317740
// Name: _dynamic_initializer_for__sv_logblocks__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_logblocks__()
{
  ConVar::ConVar(
    this: &sv_logblocks,
    pName: "sv_logblocks",
    pDefaultValue: "0",
    flags: 0,
    pHelpString: "If true when log when a query is blocked (can cause very large log files)");
  return atexit(func: dynamic_atexit_destructor_for__sv_logblocks__);
}

//------------------------------------------------------------------------------
// Address: 0x103177D0
// Name: _dynamic_initializer_for__sv_logsdir__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_logsdir__()
{
  ConVar::ConVar(
    this: &sv_logsdir,
    pName: "sv_logsdir",
    pDefaultValue: "logs",
    flags: 128,
    pHelpString: "Folder in the game directory where server logs will be stored.");
  return atexit(func: dynamic_atexit_destructor_for__sv_logsdir__);
}

//------------------------------------------------------------------------------
// Address: 0x10317800
// Name: _dynamic_initializer_for__sv_logfile__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_logfile__()
{
  ConVar::ConVar(
    this: &sv_logfile,
    pName: "sv_logfile",
    pDefaultValue: "1",
    flags: 128,
    pHelpString: "Log server information in the log file.");
  return atexit(func: dynamic_atexit_destructor_for__sv_logfile__);
}

//------------------------------------------------------------------------------
// Address: 0x10317830
// Name: _dynamic_initializer_for__sv_logflush__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_logflush__()
{
  ConVar::ConVar(
    this: &sv_logflush,
    pName: "sv_logflush",
    pDefaultValue: "0",
    flags: 128,
    pHelpString: "Flush the log file to disk on each write (slow).");
  return atexit(func: dynamic_atexit_destructor_for__sv_logflush__);
}

//------------------------------------------------------------------------------
// Address: 0x10317860
// Name: _dynamic_initializer_for__sv_logecho__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_logecho__()
{
  ConVar::ConVar(
    this: &sv_logecho,
    pName: "sv_logecho",
    pDefaultValue: "1",
    flags: 128,
    pHelpString: "Echo log information to the console.");
  return atexit(func: dynamic_atexit_destructor_for__sv_logecho__);
}

//------------------------------------------------------------------------------
// Address: 0x10317890
// Name: _dynamic_initializer_for__sv_log_onefile__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_log_onefile__()
{
  ConVar::ConVar(
    this: &sv_log_onefile,
    pName: "sv_log_onefile",
    pDefaultValue: "0",
    flags: 128,
    pHelpString: "Log server information to only one file.");
  return atexit(func: dynamic_atexit_destructor_for__sv_log_onefile__);
}

//------------------------------------------------------------------------------
// Address: 0x103178C0
// Name: _dynamic_initializer_for__sv_logbans__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_logbans__()
{
  ConVar::ConVar(
    this: &sv_logbans,
    pName: "sv_logbans",
    pDefaultValue: "0",
    flags: 128,
    pHelpString: "Log server bans in the server logs.");
  return atexit(func: dynamic_atexit_destructor_for__sv_logbans__);
}

//------------------------------------------------------------------------------
// Address: 0x10317A30
// Name: _dynamic_initializer_for__sv_hibernate_when_empty__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_hibernate_when_empty__()
{
  ConVar::ConVar(
    this: &sv_hibernate_when_empty,
    pName: "sv_hibernate_when_empty",
    pDefaultValue: "1",
    flags: 0,
    pHelpString: "Puts the server into extremely low CPU usage mode when no clients connected",
    callback: (void (__cdecl *)(IConVar *, const char *, float))OnHibernateWhenEmptyChanged);
  return atexit(func: dynamic_atexit_destructor_for__sv_hibernate_when_empty__);
}

//------------------------------------------------------------------------------
// Address: 0x10317A60
// Name: _dynamic_initializer_for__sv_hibernate_ms__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_hibernate_ms__()
{
  ConVar::ConVar(
    this: &sv_hibernate_ms,
    pName: "sv_hibernate_ms",
    pDefaultValue: "20",
    flags: 0,
    pHelpString: "# of milliseconds to sleep per frame while hibernating");
  return atexit(func: dynamic_atexit_destructor_for__sv_hibernate_ms__);
}

//------------------------------------------------------------------------------
// Address: 0x10317A90
// Name: _dynamic_initializer_for__sv_hibernate_ms_vgui__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_hibernate_ms_vgui__()
{
  ConVar::ConVar(
    this: &sv_hibernate_ms_vgui,
    pName: "sv_hibernate_ms_vgui",
    pDefaultValue: "20",
    flags: 0,
    pHelpString: "# of milliseconds to sleep per frame while hibernating but running the vgui dedicated server frontend");
  return atexit(func: dynamic_atexit_destructor_for__sv_hibernate_ms_vgui__);
}

//------------------------------------------------------------------------------
// Address: 0x10317AC0
// Name: _dynamic_initializer_for__sv_hibernate_postgame_delay__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_hibernate_postgame_delay__()
{
  ConVar::ConVar(
    this: &sv_hibernate_postgame_delay,
    pName: "sv_hibernate_postgame_delay",
    pDefaultValue: "5",
    flags: 0,
    pHelpString: "# of seconds to wait after final client leaves before hibernating.");
  return atexit(func: dynamic_atexit_destructor_for__sv_hibernate_postgame_delay__);
}

//------------------------------------------------------------------------------
// Address: 0x10317B20
// Name: _dynamic_initializer_for__sv_pausable_dev__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_pausable_dev__()
{
  ConVar::ConVar(
    this: &sv_pausable_dev,
    pName: "sv_pausable_dev",
    pDefaultValue: "1",
    flags: 2,
    pHelpString: "Whether listen server is pausable when running -dev and playing solo against bots");
  return atexit(func: dynamic_atexit_destructor_for__sv_pausable_dev__);
}

//------------------------------------------------------------------------------
// Address: 0x10317B50
// Name: _dynamic_initializer_for__sv_pausable_dev_ds__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_pausable_dev_ds__()
{
  ConVar::ConVar(
    this: &sv_pausable_dev_ds,
    pName: "sv_pausable_dev_ds",
    pDefaultValue: "0",
    flags: 2,
    pHelpString: "Whether dedicated server is pausable when running -dev and playing solo against bots");
  return atexit(func: dynamic_atexit_destructor_for__sv_pausable_dev_ds__);
}

//------------------------------------------------------------------------------
// Address: 0x10317BA0
// Name: _dynamic_initializer_for__sv_pure__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_pure__()
{
  ConCommand::ConCommand(
    this: &sv_pure,
    pName: "sv_pure",
    callback: (void (__cdecl *)())SV_Pure_f,
    pHelpString: "Show user data.",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__sv_pure__);
}

//------------------------------------------------------------------------------
// Address: 0x10317BD0
// Name: _dynamic_initializer_for__sv_pure_kick_clients__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_pure_kick_clients__()
{
  ConVar::ConVar(
    this: &sv_pure_kick_clients,
    pName: "sv_pure_kick_clients",
    pDefaultValue: "1",
    flags: 0x80000,
    pHelpString: "If set to 1, the server will kick clients with mismatching files. Otherwise, it will issue a warning to the client.");
  return atexit(func: dynamic_atexit_destructor_for__sv_pure_kick_clients__);
}

//------------------------------------------------------------------------------
// Address: 0x10317C00
// Name: _dynamic_initializer_for__sv_pure_trace__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_pure_trace__()
{
  ConVar::ConVar(
    this: &sv_pure_trace,
    pName: "sv_pure_trace",
    pDefaultValue: "0",
    flags: 0x80000,
    pHelpString: "If set to 1, the server will print a message whenever a client is verifying a CRC for a file.");
  return atexit(func: dynamic_atexit_destructor_for__sv_pure_trace__);
}

//------------------------------------------------------------------------------
// Address: 0x10317C30
// Name: _dynamic_initializer_for__sv_cheats__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_cheats__()
{
  ConVar::ConVar(
    this: &sv_cheats,
    pName: "sv_cheats",
    pDefaultValue: "0",
    flags: 532736,
    pHelpString: "Allow cheats on server",
    callback: (void (__cdecl *)(IConVar *, const char *, float))SV_CheatsChanged_f);
  return atexit(func: dynamic_atexit_destructor_for__sv_cheats__);
}

//------------------------------------------------------------------------------
// Address: 0x10317C60
// Name: _dynamic_initializer_for__sv_lan__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_lan__()
{
  ConVar::ConVar(
    this: &sv_lan,
    pName: "sv_lan",
    pDefaultValue: "0",
    flags: 0x80000,
    pHelpString: "Server is a lan server ( no heartbeat, no authentication, no non-class C addresses )");
  return atexit(func: dynamic_atexit_destructor_for__sv_lan__);
}

//------------------------------------------------------------------------------
// Address: 0x10317C90
// Name: _dynamic_initializer_for__sv_pausable__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_pausable__()
{
  ConVar::ConVar(
    this: &sv_pausable,
    pName: "sv_pausable",
    pDefaultValue: "0",
    flags: 0x80000,
    pHelpString: "Is the server pausable.");
  return atexit(func: dynamic_atexit_destructor_for__sv_pausable__);
}

//------------------------------------------------------------------------------
// Address: 0x10317CC0
// Name: _dynamic_initializer_for__sv_contact__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_contact__()
{
  ConVar::ConVar(
    this: &sv_contact,
    pName: "sv_contact",
    pDefaultValue: defaultValue,
    flags: 524544,
    pHelpString: "Contact email for server sysop");
  return atexit(func: dynamic_atexit_destructor_for__sv_contact__);
}

//------------------------------------------------------------------------------
// Address: 0x10317CF0
// Name: _dynamic_initializer_for__sv_cacheencodedents__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_cacheencodedents__()
{
  ConVar::ConVar(
    this: &sv_cacheencodedents,
    pName: "sv_cacheencodedents",
    pDefaultValue: "1",
    flags: 0,
    pHelpString: "If set to 1, does an optimization to prevent extra SendTable_Encode calls.");
  return atexit(func: dynamic_atexit_destructor_for__sv_cacheencodedents__);
}

//------------------------------------------------------------------------------
// Address: 0x10317D20
// Name: _dynamic_initializer_for__sv_voicecodec__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_voicecodec__()
{
  ConVar::ConVar(
    this: &sv_voicecodec,
    pName: "sv_voicecodec",
    pDefaultValue: "vaudio_speex",
    flags: 0,
    pHelpString: "Specifies which voice codec DLL to use in a game. Set to the name of the DLL without the extension.");
  return atexit(func: dynamic_atexit_destructor_for__sv_voicecodec__);
}

//------------------------------------------------------------------------------
// Address: 0x10317D50
// Name: _dynamic_initializer_for__sv_voiceenable__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_voiceenable__()
{
  ConVar::ConVar(this: &sv_voiceenable, pName: "sv_voiceenable", pDefaultValue: "1", flags: 524672);
  return atexit(func: dynamic_atexit_destructor_for__sv_voiceenable__);
}

//------------------------------------------------------------------------------
// Address: 0x10317D80
// Name: _dynamic_initializer_for__sv_downloadurl__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_downloadurl__()
{
  ConVar::ConVar(
    this: &sv_downloadurl,
    pName: "sv_downloadurl",
    pDefaultValue: defaultValue,
    flags: 532480,
    pHelpString: "Location from which clients can download missing files");
  return atexit(func: dynamic_atexit_destructor_for__sv_downloadurl__);
}

//------------------------------------------------------------------------------
// Address: 0x10317DB0
// Name: _dynamic_initializer_for__sv_consistency__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_consistency__()
{
  ConVar::ConVar(
    this: &sv_consistency,
    pName: "sv_consistency",
    pDefaultValue: "0",
    flags: 532480,
    pHelpString: "Whether the server enforces file consistency for critical files");
  return atexit(func: dynamic_atexit_destructor_for__sv_consistency__);
}

//------------------------------------------------------------------------------
// Address: 0x10317DE0
// Name: _dynamic_initializer_for__sv_maxreplay__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_maxreplay__()
{
  ConVar::ConVar(
    this: &sv_maxreplay,
    pName: "sv_maxreplay",
    pDefaultValue: "0",
    flags: 0,
    pHelpString: "Maximum replay time in seconds",
    bMin: true,
    fMin: 0.0,
    bMax: true,
    fMax: 15.0);
  return atexit(func: dynamic_atexit_destructor_for__sv_maxreplay__);
}

//------------------------------------------------------------------------------
// Address: 0x10317E20
// Name: _dynamic_initializer_for__sv_mincmdrate__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_mincmdrate__()
{
  ConVar::ConVar(
    this: &sv_mincmdrate,
    pName: "sv_mincmdrate",
    pDefaultValue: "10",
    flags: 532480,
    pHelpString: "This sets the minimum value for cl_cmdrate. 0 == unlimited.");
  return atexit(func: dynamic_atexit_destructor_for__sv_mincmdrate__);
}

//------------------------------------------------------------------------------
// Address: 0x10317E50
// Name: _dynamic_initializer_for__sv_maxcmdrate__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_maxcmdrate__()
{
  ConVar::ConVar(
    this: &sv_maxcmdrate,
    pName: "sv_maxcmdrate",
    pDefaultValue: "66",
    flags: 532480,
    pHelpString: "(If sv_mincmdrate is > 0), this sets the maximum value for cl_cmdrate.");
  return atexit(func: dynamic_atexit_destructor_for__sv_maxcmdrate__);
}

//------------------------------------------------------------------------------
// Address: 0x10317E80
// Name: _dynamic_initializer_for__sv_client_cmdrate_difference__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_client_cmdrate_difference__()
{
  ConVar::ConVar(
    this: &sv_client_cmdrate_difference,
    pName: "sv_client_cmdrate_difference",
    pDefaultValue: "20",
    flags: 0x2000,
    pHelpString: "cl_cmdrate is moved to within sv_client_cmdrate_difference units of cl_updaterate before it is clamped between sv_mi"
    "ncmdrate and sv_maxcmdrate.");
  return atexit(func: dynamic_atexit_destructor_for__sv_client_cmdrate_difference__);
}

//------------------------------------------------------------------------------
// Address: 0x10317EB0
// Name: _dynamic_initializer_for__sv_client_min_interp_ratio__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_client_min_interp_ratio__()
{
  ConVar::ConVar(
    this: &sv_client_min_interp_ratio,
    pName: "sv_client_min_interp_ratio",
    pDefaultValue: "1",
    flags: 0x2000,
    pHelpString: "This can be used to limit the value of cl_interp_ratio for connected clients (only while they are connected).\n"
    "              -1 = let clients set cl_interp_ratio to anything\n"
    " any other value = set minimum value for cl_interp_ratio");
  return atexit(func: dynamic_atexit_destructor_for__sv_client_min_interp_ratio__);
}

//------------------------------------------------------------------------------
// Address: 0x10317EE0
// Name: _dynamic_initializer_for__sv_client_max_interp_ratio__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_client_max_interp_ratio__()
{
  ConVar::ConVar(
    this: &sv_client_max_interp_ratio,
    pName: "sv_client_max_interp_ratio",
    pDefaultValue: "5",
    flags: 0x2000,
    pHelpString: "This can be used to limit the value of cl_interp_ratio for connected clients (only while they are connected). If sv_"
    "client_min_interp_ratio is -1, then this cvar has no effect.");
  return atexit(func: dynamic_atexit_destructor_for__sv_client_max_interp_ratio__);
}

//------------------------------------------------------------------------------
// Address: 0x10317F10
// Name: _dynamic_initializer_for__sv_client_predict__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_client_predict__()
{
  ConVar::ConVar(
    this: &sv_client_predict,
    pName: "sv_client_predict",
    pDefaultValue: "-1",
    flags: 0x2000,
    pHelpString: "This can be used to force the value of cl_predict for connected clients (only while they are connected).\n"
    "   -1 = let clients set cl_predict to anything\n"
    "    0 = force cl_predict to 0\n"
    "    1 = force cl_predict to 1");
  return atexit(func: dynamic_atexit_destructor_for__sv_client_predict__);
}

//------------------------------------------------------------------------------
// Address: 0x10318130
// Name: _dynamic_initializer_for__sv_memlimit__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_memlimit__()
{
  ConVar::ConVar(
    this: &sv_memlimit,
    pName: "sv_memlimit",
    pDefaultValue: "0",
    flags: 0x4000,
    pHelpString: "If set, whenever a game ends, if the total memory used by the server is greater than this # of megabytes, the server will exit.");
  return atexit(func: dynamic_atexit_destructor_for__sv_memlimit__);
}

//------------------------------------------------------------------------------
// Address: 0x10318160
// Name: _dynamic_initializer_for__sv_shutdown__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_shutdown__()
{
  ConCommand::ConCommand(
    this: &sv_shutdown,
    pName: "sv_shutdown",
    callback: sv_ShutDown,
    pHelpString: "Sets the server to shutdown when all games have completed",
    flags: 0x4000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__sv_shutdown__);
}

//------------------------------------------------------------------------------
// Address: 0x10318190
// Name: _dynamic_initializer_for__sv_parallel_sendsnapshot__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_parallel_sendsnapshot__()
{
  ConVar::ConVar(this: &sv_parallel_sendsnapshot, pName: "sv_parallel_sendsnapshot", pDefaultValue: "1", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__sv_parallel_sendsnapshot__);
}

//------------------------------------------------------------------------------
// Address: 0x10318250
// Name: _dynamic_initializer_for__sv_validate_edict_change_infos__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_validate_edict_change_infos__()
{
  ConVar::ConVar(
    this: &sv_validate_edict_change_infos,
    pName: "sv_validate_edict_change_infos",
    pDefaultValue: "0",
    flags: 0,
    pHelpString: "Verify that edict changeinfos are being calculated properly (used to debug local network backdoor mode).");
  return atexit(func: dynamic_atexit_destructor_for__sv_validate_edict_change_infos__);
}

//------------------------------------------------------------------------------
// Address: 0x10318280
// Name: _dynamic_initializer_for__sv_debugmanualmode__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_debugmanualmode__()
{
  ConVar::ConVar(
    this: &sv_debugmanualmode,
    pName: "sv_debugmanualmode",
    pDefaultValue: "0",
    flags: 0,
    pHelpString: "Make sure entities correctly report whether or not their network data has changed.");
  return atexit(func: dynamic_atexit_destructor_for__sv_debugmanualmode__);
}

//------------------------------------------------------------------------------
// Address: 0x103182B0
// Name: _dynamic_initializer_for__sv_parallel_packentities__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_parallel_packentities__()
{
  ConVar::ConVar(this: &sv_parallel_packentities, pName: "sv_parallel_packentities", pDefaultValue: "1", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__sv_parallel_packentities__);
}

//------------------------------------------------------------------------------
// Address: 0x10318460
// Name: _dynamic_initializer_for__sv_forcepreload__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_forcepreload__()
{
  ConVar::ConVar(
    this: &sv_forcepreload,
    pName: "sv_forcepreload",
    pDefaultValue: "0",
    flags: 128,
    pHelpString: "Force server side preloading.");
  return atexit(func: dynamic_atexit_destructor_for__sv_forcepreload__);
}

//------------------------------------------------------------------------------
// Address: 0x10318490
// Name: _dynamic_initializer_for__sv_precacheinfo_command__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_precacheinfo_command__()
{
  ConCommand::ConCommand(
    this: &sv_precacheinfo_command,
    pName: "sv_precacheinfo",
    callback: (void (__cdecl *)())sv_precacheinfo,
    pHelpString: "Show precache info.",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__sv_precacheinfo_command__);
}

//------------------------------------------------------------------------------
// Address: 0x103185E0
// Name: _dynamic_initializer_for__sv_rcon_banpenalty__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_rcon_banpenalty__()
{
  ConVar::ConVar(
    this: &sv_rcon_banpenalty,
    pName: "sv_rcon_banpenalty",
    pDefaultValue: "0",
    flags: 0,
    pHelpString: "Number of minutes to ban users who fail rcon authentication",
    bMin: true,
    fMin: 0.0,
    bMax: false,
    fMax: 0.0);
  return atexit(func: dynamic_atexit_destructor_for__sv_rcon_banpenalty__);
}

//------------------------------------------------------------------------------
// Address: 0x10318620
// Name: _dynamic_initializer_for__sv_rcon_maxfailures__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_rcon_maxfailures__()
{
  ConVar::ConVar(
    this: &sv_rcon_maxfailures,
    pName: "sv_rcon_maxfailures",
    pDefaultValue: "10",
    flags: 0,
    pHelpString: "Max number of times a user can fail rcon authentication before being banned",
    bMin: true,
    fMin: 1.0,
    bMax: true,
    fMax: 20.0);
  return atexit(func: dynamic_atexit_destructor_for__sv_rcon_maxfailures__);
}

//------------------------------------------------------------------------------
// Address: 0x10318660
// Name: _dynamic_initializer_for__sv_rcon_minfailures__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_rcon_minfailures__()
{
  ConVar::ConVar(
    this: &sv_rcon_minfailures,
    pName: "sv_rcon_minfailures",
    pDefaultValue: "5",
    flags: 0,
    pHelpString: "Number of times a user can fail rcon authentication in sv_rcon_minfailuretime before being banned",
    bMin: true,
    fMin: 1.0,
    bMax: true,
    fMax: 20.0);
  return atexit(func: dynamic_atexit_destructor_for__sv_rcon_minfailures__);
}

//------------------------------------------------------------------------------
// Address: 0x103186A0
// Name: _dynamic_initializer_for__sv_rcon_minfailuretime__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_rcon_minfailuretime__()
{
  ConVar::ConVar(
    this: &sv_rcon_minfailuretime,
    pName: "sv_rcon_minfailuretime",
    pDefaultValue: "30",
    flags: 0,
    pHelpString: "Number of seconds to track failed rcon authentications",
    bMin: true,
    fMin: 1.0,
    bMax: false,
    fMax: 0.0);
  return atexit(func: dynamic_atexit_destructor_for__sv_rcon_minfailuretime__);
}

//------------------------------------------------------------------------------
// Address: 0x103186E0
// Name: _dynamic_initializer_for__sv_redirectto__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
void dynamic_initializer_for__sv_redirectto__()
{
  netadr_s::SetIP(this: &sv_redirectto, unIP: 0);
  netadr_s::SetPort(this: &sv_redirectto, newport: 0);
  netadr_s::SetType(this: &sv_redirectto, newtype: NA_IP);
}

//------------------------------------------------------------------------------
// Address: 0x10318740
// Name: _dynamic_initializer_for__sv_rcon_log__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_rcon_log__()
{
  ConVar::ConVar(
    this: &sv_rcon_log,
    pName: "sv_rcon_log",
    pDefaultValue: "1",
    flags: 0,
    pHelpString: "Enable/disable rcon logging.");
  return atexit(func: dynamic_atexit_destructor_for__sv_rcon_log__);
}

//------------------------------------------------------------------------------
// Address: 0x103187A0
// Name: _dynamic_initializer_for__sv_master_share_game_socket__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_master_share_game_socket__()
{
  ConVar::ConVar(
    this: &sv_master_share_game_socket,
    pName: "sv_master_share_game_socket",
    pDefaultValue: "1",
    flags: 0,
    pHelpString: "Use the game's socket to communicate to the master server. If this is 0, then it will create a socket on -steamport "
    "+ 1 to communicate to the master server on.");
  return atexit(func: dynamic_atexit_destructor_for__sv_master_share_game_socket__);
}

//------------------------------------------------------------------------------
// Address: 0x10318900
// Name: _dynamic_initializer_for__sv_region__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_region__()
{
  ConVar::ConVar(
    this: &sv_region,
    pName: "sv_region",
    pDefaultValue: "-1",
    flags: 0x80000,
    pHelpString: "The region of the world to report this server in.");
  return atexit(func: dynamic_atexit_destructor_for__sv_region__);
}

//------------------------------------------------------------------------------
// Address: 0x10318930
// Name: _dynamic_initializer_for__sv_instancebaselines__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_instancebaselines__()
{
  ConVar::ConVar(
    this: &sv_instancebaselines,
    pName: "sv_instancebaselines",
    pDefaultValue: "1",
    flags: 2,
    pHelpString: "Enable instanced baselines. Saves network overhead.");
  return atexit(func: dynamic_atexit_destructor_for__sv_instancebaselines__);
}

//------------------------------------------------------------------------------
// Address: 0x10318960
// Name: _dynamic_initializer_for__sv_stats__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_stats__()
{
  ConVar::ConVar(
    this: &sv_stats,
    pName: "sv_stats",
    pDefaultValue: "1",
    flags: 0,
    pHelpString: "Collect CPU usage stats");
  return atexit(func: dynamic_atexit_destructor_for__sv_stats__);
}

//------------------------------------------------------------------------------
// Address: 0x10318990
// Name: _dynamic_initializer_for__sv_enableoldqueries__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_enableoldqueries__()
{
  ConVar::ConVar(
    this: &sv_enableoldqueries,
    pName: "sv_enableoldqueries",
    pDefaultValue: "0",
    flags: 0,
    pHelpString: "Enable support for old style (HL1) server queries");
  return atexit(func: dynamic_atexit_destructor_for__sv_enableoldqueries__);
}

//------------------------------------------------------------------------------
// Address: 0x103189C0
// Name: _dynamic_initializer_for__sv_password__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_password__()
{
  ConVar::ConVar(
    this: &sv_password,
    pName: "sv_password",
    pDefaultValue: defaultValue,
    flags: 655648,
    pHelpString: "Server password for entry into multiplayer games",
    callback: (void (__cdecl *)(IConVar *, const char *, float))SvPasswordChangeCallback);
  return atexit(func: dynamic_atexit_destructor_for__sv_password__);
}

//------------------------------------------------------------------------------
// Address: 0x103189F0
// Name: _dynamic_initializer_for__sv_tags__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_tags__()
{
  ConVar::ConVar(
    this: &sv_tags,
    pName: "sv_tags",
    pDefaultValue: defaultValue,
    flags: 524544,
    pHelpString: "Server tags. Used to provide extra information to clients when they're browsing for servers. Separate tags with a comma.",
    callback: (void (__cdecl *)(IConVar *, const char *, float))SvTagsChangeCallback);
  return atexit(func: dynamic_atexit_destructor_for__sv_tags__);
}

//------------------------------------------------------------------------------
// Address: 0x10318A20
// Name: _dynamic_initializer_for__sv_visiblemaxplayers__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_visiblemaxplayers__()
{
  ConVar::ConVar(
    this: &sv_visiblemaxplayers,
    pName: "sv_visiblemaxplayers",
    pDefaultValue: "-1",
    flags: 0x80000,
    pHelpString: "Overrides the max players reported to prospective clients");
  return atexit(func: dynamic_atexit_destructor_for__sv_visiblemaxplayers__);
}

//------------------------------------------------------------------------------
// Address: 0x10318A50
// Name: _dynamic_initializer_for__sv_alternateticks__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_alternateticks__()
{
  ConVar::ConVar(
    this: &sv_alternateticks,
    pName: "sv_alternateticks",
    pDefaultValue: "1",
    flags: 524352,
    pHelpString: "If set, server only simulates entities on even numbered ticks.\n");
  return atexit(func: dynamic_atexit_destructor_for__sv_alternateticks__);
}

//------------------------------------------------------------------------------
// Address: 0x10318A80
// Name: _dynamic_initializer_for__sv_allow_wait_command__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_allow_wait_command__()
{
  ConVar::ConVar(
    this: &sv_allow_wait_command,
    pName: "sv_allow_wait_command",
    pDefaultValue: "1",
    flags: 532480,
    pHelpString: "Allow or disallow the wait command on clients connected to this server.");
  return atexit(func: dynamic_atexit_destructor_for__sv_allow_wait_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10318AB0
// Name: _dynamic_initializer_for__sv_allow_lobby_connect_only__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_allow_lobby_connect_only__()
{
  ConVar::ConVar(
    this: &sv_allow_lobby_connect_only,
    pName: "sv_allow_lobby_connect_only",
    pDefaultValue: "0",
    flags: 0x80000,
    pHelpString: "If set, players may only join this server from matchmaking lobby, may not connect directly.");
  return atexit(func: dynamic_atexit_destructor_for__sv_allow_lobby_connect_only__);
}

//------------------------------------------------------------------------------
// Address: 0x10318AE0
// Name: _dynamic_initializer_for__sv_reservation_timeout__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_reservation_timeout__()
{
  ConVar::ConVar(
    this: &sv_reservation_timeout,
    pName: "sv_reservation_timeout",
    pDefaultValue: "45",
    flags: 0x80000,
    pHelpString: "Time in seconds before lobby reservation expires.",
    bMin: true,
    fMin: 5.0,
    bMax: true,
    fMax: 180.0);
  return atexit(func: dynamic_atexit_destructor_for__sv_reservation_timeout__);
}

//------------------------------------------------------------------------------
// Address: 0x10318B30
// Name: _dynamic_initializer_for__sv_reservation_grace__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_reservation_grace__()
{
  ConVar::ConVar(
    this: &sv_reservation_grace,
    pName: "sv_reservation_grace",
    pDefaultValue: "5",
    flags: 0,
    pHelpString: "Time in seconds given for a lobby reservation.",
    bMin: true,
    fMin: 3.0,
    bMax: true,
    fMax: 30.0);
  return atexit(func: dynamic_atexit_destructor_for__sv_reservation_grace__);
}

//------------------------------------------------------------------------------
// Address: 0x10318B70
// Name: _dynamic_initializer_for__sv_steamgroup__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_steamgroup__()
{
  ConVar::ConVar(
    this: &sv_steamgroup,
    pName: "sv_steamgroup",
    pDefaultValue: defaultValue,
    flags: 524544,
    pHelpString: "The ID of the steam group that this server belongs to. You can find your group's ID on the admin profile page in the"
    " steam community.",
    callback: (void (__cdecl *)(IConVar *, const char *, float))SvGameDataChangeCallback);
  return atexit(func: dynamic_atexit_destructor_for__sv_steamgroup__);
}

//------------------------------------------------------------------------------
// Address: 0x10318BA0
// Name: _dynamic_initializer_for__sv_steamgroup_exclusive__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_steamgroup_exclusive__()
{
  ConVar::ConVar(
    this: &sv_steamgroup_exclusive,
    pName: "sv_steamgroup_exclusive",
    pDefaultValue: "0",
    flags: 0x80000,
    pHelpString: "If set, only members of Steam group will be able to join the server when it's empty, public people will be able to j"
    "oin the server only if it has players.");
  return atexit(func: dynamic_atexit_destructor_for__sv_steamgroup_exclusive__);
}

//------------------------------------------------------------------------------
// Address: 0x10318BD0
// Name: _dynamic_initializer_for__sv_debugtempentities__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_debugtempentities__()
{
  ConVar::ConVar(
    this: &sv_debugtempentities,
    pName: "sv_debugtempentities",
    pDefaultValue: "0",
    flags: 0,
    pHelpString: "Show temp entity bandwidth usage.");
  return atexit(func: dynamic_atexit_destructor_for__sv_debugtempentities__);
}

//------------------------------------------------------------------------------
// Address: 0x10318C00
// Name: _dynamic_initializer_for__sv_hosting_lobby__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_hosting_lobby__()
{
  ConVar::ConVar(this: &sv_hosting_lobby, pName: "sv_hosting_lobby", pDefaultValue: "0", flags: 8194);
  return atexit(func: dynamic_atexit_destructor_for__sv_hosting_lobby__);
}

//------------------------------------------------------------------------------
// Address: 0x10318C30
// Name: _dynamic_initializer_for__sv_showtags_command__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_showtags_command__()
{
  ConCommand::ConCommand(
    this: &sv_showtags_command,
    pName: "sv_showtags",
    callback: sv_showtags,
    pHelpString: "Describe current gametags.",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__sv_showtags_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10319950
// Name: _dynamic_initializer_for__sv_logdownloadlist__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_logdownloadlist__()
{
  ConVar::ConVar(this: &sv_logdownloadlist, pName: "sv_logdownloadlist", pDefaultValue: "0", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__sv_logdownloadlist__);
}

//------------------------------------------------------------------------------
// Address: 0x10319AA0
// Name: _dynamic_initializer_for__sv_new_delta_bits__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_new_delta_bits__()
{
  ConVar::ConVar(this: &sv_new_delta_bits, pName: "sv_new_delta_bits", pDefaultValue: "1", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__sv_new_delta_bits__);
}

//------------------------------------------------------------------------------
// Address: 0x1031B910
// Name: _dynamic_initializer_for__sv_autosave__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_autosave__()
{
  ConVar::ConVar(
    this: &sv_autosave,
    pName: "sv_autosave",
    pDefaultValue: "1",
    flags: 0,
    pHelpString: "Set to 1 to autosave game on level transition. Does not affect autosave triggers.");
  return atexit(func: dynamic_atexit_destructor_for__sv_autosave__);
}

//------------------------------------------------------------------------------
// Address: 0x1031CD50
// Name: _dynamic_initializer_for__sv_maxroutable__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_maxroutable__()
{
  ConVar::ConVar(
    this: &sv_maxroutable,
    pName: "sv_maxroutable",
    pDefaultValue: "1200",
    flags: 0,
    pHelpString: "Server upper bound on net_maxroutable that a client can use.",
    bMin: true,
    fMin: 576.0,
    bMax: true,
    fMax: 1200.0);
  return atexit(func: dynamic_atexit_destructor_for__sv_maxroutable__);
}

//------------------------------------------------------------------------------
// Address: 0x1031D060
// Name: _dynamic_initializer_for__sv_dumpstringtables__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_dumpstringtables__()
{
  ConVar::ConVar(this: &sv_dumpstringtables, pName: "sv_dumpstringtables", pDefaultValue: "0", flags: 0x4000);
  return atexit(func: dynamic_atexit_destructor_for__sv_dumpstringtables__);
}

//------------------------------------------------------------------------------
// Address: 0x1031D3C0
// Name: _dynamic_initializer_for__sv_useexplicitdelete__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_useexplicitdelete__()
{
  ConVar::ConVar(
    this: &sv_useexplicitdelete,
    pName: "sv_useexplicitdelete",
    pDefaultValue: "1",
    flags: 2,
    pHelpString: "Explicitly delete dormant client entities caused by AllowImmediateReuse().");
  return atexit(func: dynamic_atexit_destructor_for__sv_useexplicitdelete__);
}

//------------------------------------------------------------------------------
// Address: 0x1031DAC0
// Name: _dynamic_initializer_for__sv_master_legacy_mode__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_master_legacy_mode__()
{
  ConVar::ConVar(
    this: &sv_master_legacy_mode,
    pName: "sv_master_legacy_mode",
    pDefaultValue: "1",
    flags: 0,
    pHelpString: "Use (outside-of-Steam) code to communicate with master servers.");
  return atexit(func: dynamic_atexit_destructor_for__sv_master_legacy_mode__);
}

//------------------------------------------------------------------------------
// Address: 0x1031DAF0
// Name: _dynamic_initializer_for__sv_search_key__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_search_key__()
{
  ConVar::ConVar(
    this: &sv_search_key,
    pName: "sv_search_key",
    pDefaultValue: defaultValue,
    flags: 0x80000,
    pHelpString: "When searching for a dedicated server from lobby, restrict search to only dedicated servers having the same sv_search_key.",
    callback: (void (__cdecl *)(IConVar *, const char *, float))SvGameDataChangeCallback);
  return atexit(func: dynamic_atexit_destructor_for__sv_search_key__);
}

//------------------------------------------------------------------------------
// Address: 0x103226E0
// Name: _dynamic_atexit_destructor_for__sv_unlockedchapters__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sv_unlockedchapters__()
{
  ConVar::~ConVar(this: &sv_unlockedchapters);
}

//------------------------------------------------------------------------------
// Address: 0x10324050
// Name: _dynamic_atexit_destructor_for__sv_multiplayer_maxtempentities__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sv_multiplayer_maxtempentities__()
{
  ConVar::~ConVar(this: &sv_multiplayer_maxtempentities);
}

//------------------------------------------------------------------------------
// Address: 0x10324060
// Name: _dynamic_atexit_destructor_for__sv_multiplayer_maxsounds__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sv_multiplayer_maxsounds__()
{
  ConVar::~ConVar(this: &sv_multiplayer_maxsounds);
}

//------------------------------------------------------------------------------
// Address: 0x10324070
// Name: _dynamic_atexit_destructor_for__sv_timeout__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sv_timeout__()
{
  ConVar::~ConVar(this: &sv_timeout);
}

//------------------------------------------------------------------------------
// Address: 0x10324080
// Name: _dynamic_atexit_destructor_for__sv_maxrate__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sv_maxrate__()
{
  ConVar::~ConVar(this: &sv_maxrate);
}

//------------------------------------------------------------------------------
// Address: 0x10324090
// Name: _dynamic_atexit_destructor_for__sv_minrate__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sv_minrate__()
{
  ConVar::~ConVar(this: &sv_minrate);
}

//------------------------------------------------------------------------------
// Address: 0x103240A0
// Name: _dynamic_atexit_destructor_for__sv_maxupdaterate__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sv_maxupdaterate__()
{
  ConVar::~ConVar(this: &sv_maxupdaterate);
}

//------------------------------------------------------------------------------
// Address: 0x103240B0
// Name: _dynamic_atexit_destructor_for__sv_minupdaterate__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sv_minupdaterate__()
{
  ConVar::~ConVar(this: &sv_minupdaterate);
}

//------------------------------------------------------------------------------
// Address: 0x103240C0
// Name: _dynamic_atexit_destructor_for__sv_stressbots__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sv_stressbots__()
{
  ConVar::~ConVar(this: &sv_stressbots);
}

//------------------------------------------------------------------------------
// Address: 0x103240D0
// Name: _dynamic_atexit_destructor_for__sv_allowdownload__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sv_allowdownload__()
{
  ConVar::~ConVar(this: &sv_allowdownload);
}

//------------------------------------------------------------------------------
// Address: 0x103240E0
// Name: _dynamic_atexit_destructor_for__sv_allowupload__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sv_allowupload__()
{
  ConVar::~ConVar(this: &sv_allowupload);
}

//------------------------------------------------------------------------------
// Address: 0x103240F0
// Name: _dynamic_atexit_destructor_for__sv_sendtables__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sv_sendtables__()
{
  ConVar::~ConVar(this: &sv_sendtables);
}

//------------------------------------------------------------------------------
// Address: 0x10324120
// Name: _dynamic_atexit_destructor_for__sv_maxclientframes__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sv_maxclientframes__()
{
  ConVar::~ConVar(this: &sv_maxclientframes);
}

//------------------------------------------------------------------------------
// Address: 0x10324130
// Name: _dynamic_atexit_destructor_for__sv_extra_client_connect_time__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sv_extra_client_connect_time__()
{
  ConVar::~ConVar(this: &sv_extra_client_connect_time);
}

//------------------------------------------------------------------------------
// Address: 0x10324140
// Name: _dynamic_atexit_destructor_for__sv_sound_discardextraunreliable__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sv_sound_discardextraunreliable__()
{
  ConVar::~ConVar(this: &sv_sound_discardextraunreliable);
}

//------------------------------------------------------------------------------
// Address: 0x10324150
// Name: _dynamic_atexit_destructor_for__sv_deltatime__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sv_deltatime__()
{
  ConVar::~ConVar(this: &sv_deltatime);
}

//------------------------------------------------------------------------------
// Address: 0x10324160
// Name: _dynamic_atexit_destructor_for__sv_deltaprint__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sv_deltaprint__()
{
  ConVar::~ConVar(this: &sv_deltaprint);
}

//------------------------------------------------------------------------------
// Address: 0x103241C0
// Name: _dynamic_atexit_destructor_for__sv_filterban__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sv_filterban__()
{
  ConVar::~ConVar(this: &sv_filterban);
}

//------------------------------------------------------------------------------
// Address: 0x10324290
// Name: _dynamic_atexit_destructor_for__sv_creationtickcheck__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sv_creationtickcheck__()
{
  ConVar::~ConVar(this: &sv_creationtickcheck);
}

//------------------------------------------------------------------------------
// Address: 0x103242B0
// Name: _dynamic_atexit_destructor_for__sv_max_queries_sec__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sv_max_queries_sec__()
{
  ConVar::~ConVar(this: &sv_max_queries_sec);
}

//------------------------------------------------------------------------------
// Address: 0x103242C0
// Name: _dynamic_atexit_destructor_for__sv_max_queries_window__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sv_max_queries_window__()
{
  ConVar::~ConVar(this: &sv_max_queries_window);
}

//------------------------------------------------------------------------------
// Address: 0x103242D0
// Name: _dynamic_atexit_destructor_for__sv_max_queries_sec_global__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sv_max_queries_sec_global__()
{
  ConVar::~ConVar(this: &sv_max_queries_sec_global);
}

//------------------------------------------------------------------------------
// Address: 0x103242E0
// Name: _dynamic_atexit_destructor_for__sv_logblocks__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sv_logblocks__()
{
  ConVar::~ConVar(this: &sv_logblocks);
}

//------------------------------------------------------------------------------
// Address: 0x10324300
// Name: _dynamic_atexit_destructor_for__sv_logsdir__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sv_logsdir__()
{
  ConVar::~ConVar(this: &sv_logsdir);
}

//------------------------------------------------------------------------------
// Address: 0x10324310
// Name: _dynamic_atexit_destructor_for__sv_logfile__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sv_logfile__()
{
  ConVar::~ConVar(this: &sv_logfile);
}

//------------------------------------------------------------------------------
// Address: 0x10324320
// Name: _dynamic_atexit_destructor_for__sv_logflush__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sv_logflush__()
{
  ConVar::~ConVar(this: &sv_logflush);
}

//------------------------------------------------------------------------------
// Address: 0x10324330
// Name: _dynamic_atexit_destructor_for__sv_logecho__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sv_logecho__()
{
  ConVar::~ConVar(this: &sv_logecho);
}

//------------------------------------------------------------------------------
// Address: 0x10324340
// Name: _dynamic_atexit_destructor_for__sv_log_onefile__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sv_log_onefile__()
{
  ConVar::~ConVar(this: &sv_log_onefile);
}

//------------------------------------------------------------------------------
// Address: 0x10324350
// Name: _dynamic_atexit_destructor_for__sv_logbans__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sv_logbans__()
{
  ConVar::~ConVar(this: &sv_logbans);
}

//------------------------------------------------------------------------------
// Address: 0x103243E0
// Name: _dynamic_atexit_destructor_for__sv_hibernate_when_empty__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sv_hibernate_when_empty__()
{
  ConVar::~ConVar(this: &sv_hibernate_when_empty);
}

//------------------------------------------------------------------------------
// Address: 0x103243F0
// Name: _dynamic_atexit_destructor_for__sv_hibernate_ms__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sv_hibernate_ms__()
{
  ConVar::~ConVar(this: &sv_hibernate_ms);
}

//------------------------------------------------------------------------------
// Address: 0x10324400
// Name: _dynamic_atexit_destructor_for__sv_hibernate_ms_vgui__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sv_hibernate_ms_vgui__()
{
  ConVar::~ConVar(this: &sv_hibernate_ms_vgui);
}

//------------------------------------------------------------------------------
// Address: 0x10324410
// Name: _dynamic_atexit_destructor_for__sv_hibernate_postgame_delay__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sv_hibernate_postgame_delay__()
{
  ConVar::~ConVar(this: &sv_hibernate_postgame_delay);
}

//------------------------------------------------------------------------------
// Address: 0x10324430
// Name: _dynamic_atexit_destructor_for__sv_pausable_dev__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sv_pausable_dev__()
{
  ConVar::~ConVar(this: &sv_pausable_dev);
}

//------------------------------------------------------------------------------
// Address: 0x10324440
// Name: _dynamic_atexit_destructor_for__sv_pausable_dev_ds__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sv_pausable_dev_ds__()
{
  ConVar::~ConVar(this: &sv_pausable_dev_ds);
}

//------------------------------------------------------------------------------
// Address: 0x10324450
// Name: _dynamic_atexit_destructor_for__sv_pure__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sv_pure__()
{
  ConCommand::~ConCommand(this: &sv_pure);
}

//------------------------------------------------------------------------------
// Address: 0x10324460
// Name: _dynamic_atexit_destructor_for__sv_pure_kick_clients__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sv_pure_kick_clients__()
{
  ConVar::~ConVar(this: &sv_pure_kick_clients);
}

//------------------------------------------------------------------------------
// Address: 0x10324470
// Name: _dynamic_atexit_destructor_for__sv_pure_trace__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sv_pure_trace__()
{
  ConVar::~ConVar(this: &sv_pure_trace);
}

//------------------------------------------------------------------------------
// Address: 0x10324480
// Name: _dynamic_atexit_destructor_for__sv_cheats__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sv_cheats__()
{
  ConVar::~ConVar(this: &sv_cheats);
}

//------------------------------------------------------------------------------
// Address: 0x10324490
// Name: _dynamic_atexit_destructor_for__sv_lan__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sv_lan__()
{
  ConVar::~ConVar(this: &sv_lan);
}

//------------------------------------------------------------------------------
// Address: 0x103244A0
// Name: _dynamic_atexit_destructor_for__sv_pausable__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sv_pausable__()
{
  ConVar::~ConVar(this: &sv_pausable);
}

//------------------------------------------------------------------------------
// Address: 0x103244B0
// Name: _dynamic_atexit_destructor_for__sv_contact__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sv_contact__()
{
  ConVar::~ConVar(this: &sv_contact);
}

//------------------------------------------------------------------------------
// Address: 0x103244C0
// Name: _dynamic_atexit_destructor_for__sv_cacheencodedents__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sv_cacheencodedents__()
{
  ConVar::~ConVar(this: &sv_cacheencodedents);
}

//------------------------------------------------------------------------------
// Address: 0x103244D0
// Name: _dynamic_atexit_destructor_for__sv_voicecodec__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sv_voicecodec__()
{
  ConVar::~ConVar(this: &sv_voicecodec);
}

//------------------------------------------------------------------------------
// Address: 0x103244E0
// Name: _dynamic_atexit_destructor_for__sv_voiceenable__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sv_voiceenable__()
{
  ConVar::~ConVar(this: &sv_voiceenable);
}

//------------------------------------------------------------------------------
// Address: 0x103244F0
// Name: _dynamic_atexit_destructor_for__sv_downloadurl__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sv_downloadurl__()
{
  ConVar::~ConVar(this: &sv_downloadurl);
}

//------------------------------------------------------------------------------
// Address: 0x10324500
// Name: _dynamic_atexit_destructor_for__sv_consistency__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sv_consistency__()
{
  ConVar::~ConVar(this: &sv_consistency);
}

//------------------------------------------------------------------------------
// Address: 0x10324510
// Name: _dynamic_atexit_destructor_for__sv_maxreplay__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sv_maxreplay__()
{
  ConVar::~ConVar(this: &sv_maxreplay);
}

//------------------------------------------------------------------------------
// Address: 0x10324520
// Name: _dynamic_atexit_destructor_for__sv_mincmdrate__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sv_mincmdrate__()
{
  ConVar::~ConVar(this: &sv_mincmdrate);
}

//------------------------------------------------------------------------------
// Address: 0x10324530
// Name: _dynamic_atexit_destructor_for__sv_maxcmdrate__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sv_maxcmdrate__()
{
  ConVar::~ConVar(this: &sv_maxcmdrate);
}

//------------------------------------------------------------------------------
// Address: 0x10324540
// Name: _dynamic_atexit_destructor_for__sv_client_cmdrate_difference__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sv_client_cmdrate_difference__()
{
  ConVar::~ConVar(this: &sv_client_cmdrate_difference);
}

//------------------------------------------------------------------------------
// Address: 0x10324550
// Name: _dynamic_atexit_destructor_for__sv_client_min_interp_ratio__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sv_client_min_interp_ratio__()
{
  ConVar::~ConVar(this: &sv_client_min_interp_ratio);
}

//------------------------------------------------------------------------------
// Address: 0x10324560
// Name: _dynamic_atexit_destructor_for__sv_client_max_interp_ratio__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sv_client_max_interp_ratio__()
{
  ConVar::~ConVar(this: &sv_client_max_interp_ratio);
}

//------------------------------------------------------------------------------
// Address: 0x10324570
// Name: _dynamic_atexit_destructor_for__sv_client_predict__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sv_client_predict__()
{
  ConVar::~ConVar(this: &sv_client_predict);
}

//------------------------------------------------------------------------------
// Address: 0x103245C0
// Name: _dynamic_atexit_destructor_for__sv_memlimit__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sv_memlimit__()
{
  ConVar::~ConVar(this: &sv_memlimit);
}

//------------------------------------------------------------------------------
// Address: 0x103245D0
// Name: _dynamic_atexit_destructor_for__sv_shutdown__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sv_shutdown__()
{
  ConCommand::~ConCommand(this: &sv_shutdown);
}

//------------------------------------------------------------------------------
// Address: 0x103245E0
// Name: _dynamic_atexit_destructor_for__sv_parallel_sendsnapshot__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sv_parallel_sendsnapshot__()
{
  ConVar::~ConVar(this: &sv_parallel_sendsnapshot);
}

//------------------------------------------------------------------------------
// Address: 0x10324650
// Name: _dynamic_atexit_destructor_for__sv_validate_edict_change_infos__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sv_validate_edict_change_infos__()
{
  ConVar::~ConVar(this: &sv_validate_edict_change_infos);
}

//------------------------------------------------------------------------------
// Address: 0x10324660
// Name: _dynamic_atexit_destructor_for__sv_debugmanualmode__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sv_debugmanualmode__()
{
  ConVar::~ConVar(this: &sv_debugmanualmode);
}

//------------------------------------------------------------------------------
// Address: 0x10324670
// Name: _dynamic_atexit_destructor_for__sv_parallel_packentities__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sv_parallel_packentities__()
{
  ConVar::~ConVar(this: &sv_parallel_packentities);
}

//------------------------------------------------------------------------------
// Address: 0x10324710
// Name: _dynamic_atexit_destructor_for__sv_forcepreload__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sv_forcepreload__()
{
  ConVar::~ConVar(this: &sv_forcepreload);
}

//------------------------------------------------------------------------------
// Address: 0x10324720
// Name: _dynamic_atexit_destructor_for__sv_precacheinfo_command__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sv_precacheinfo_command__()
{
  ConCommand::~ConCommand(this: &sv_precacheinfo_command);
}

//------------------------------------------------------------------------------
// Address: 0x10324740
// Name: _dynamic_atexit_destructor_for__sv_rcon_banpenalty__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sv_rcon_banpenalty__()
{
  ConVar::~ConVar(this: &sv_rcon_banpenalty);
}

//------------------------------------------------------------------------------
// Address: 0x10324750
// Name: _dynamic_atexit_destructor_for__sv_rcon_maxfailures__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sv_rcon_maxfailures__()
{
  ConVar::~ConVar(this: &sv_rcon_maxfailures);
}

//------------------------------------------------------------------------------
// Address: 0x10324760
// Name: _dynamic_atexit_destructor_for__sv_rcon_minfailures__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sv_rcon_minfailures__()
{
  ConVar::~ConVar(this: &sv_rcon_minfailures);
}

//------------------------------------------------------------------------------
// Address: 0x10324770
// Name: _dynamic_atexit_destructor_for__sv_rcon_minfailuretime__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sv_rcon_minfailuretime__()
{
  ConVar::~ConVar(this: &sv_rcon_minfailuretime);
}

//------------------------------------------------------------------------------
// Address: 0x10324840
// Name: _dynamic_atexit_destructor_for__sv_rcon_log__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sv_rcon_log__()
{
  ConVar::~ConVar(this: &sv_rcon_log);
}

//------------------------------------------------------------------------------
// Address: 0x10324870
// Name: _dynamic_atexit_destructor_for__sv_master_share_game_socket__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sv_master_share_game_socket__()
{
  ConVar::~ConVar(this: &sv_master_share_game_socket);
}

//------------------------------------------------------------------------------
// Address: 0x10324910
// Name: _dynamic_atexit_destructor_for__sv_region__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sv_region__()
{
  ConVar::~ConVar(this: &sv_region);
}

//------------------------------------------------------------------------------
// Address: 0x10324920
// Name: _dynamic_atexit_destructor_for__sv_instancebaselines__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sv_instancebaselines__()
{
  ConVar::~ConVar(this: &sv_instancebaselines);
}

//------------------------------------------------------------------------------
// Address: 0x10324930
// Name: _dynamic_atexit_destructor_for__sv_stats__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sv_stats__()
{
  ConVar::~ConVar(this: &sv_stats);
}

//------------------------------------------------------------------------------
// Address: 0x10324940
// Name: _dynamic_atexit_destructor_for__sv_enableoldqueries__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sv_enableoldqueries__()
{
  ConVar::~ConVar(this: &sv_enableoldqueries);
}

//------------------------------------------------------------------------------
// Address: 0x10324950
// Name: _dynamic_atexit_destructor_for__sv_password__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sv_password__()
{
  ConVar::~ConVar(this: &sv_password);
}

//------------------------------------------------------------------------------
// Address: 0x10324960
// Name: _dynamic_atexit_destructor_for__sv_tags__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sv_tags__()
{
  ConVar::~ConVar(this: &sv_tags);
}

//------------------------------------------------------------------------------
// Address: 0x10324970
// Name: _dynamic_atexit_destructor_for__sv_visiblemaxplayers__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sv_visiblemaxplayers__()
{
  ConVar::~ConVar(this: &sv_visiblemaxplayers);
}

//------------------------------------------------------------------------------
// Address: 0x10324980
// Name: _dynamic_atexit_destructor_for__sv_alternateticks__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sv_alternateticks__()
{
  ConVar::~ConVar(this: &sv_alternateticks);
}

//------------------------------------------------------------------------------
// Address: 0x10324990
// Name: _dynamic_atexit_destructor_for__sv_allow_wait_command__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sv_allow_wait_command__()
{
  ConVar::~ConVar(this: &sv_allow_wait_command);
}

//------------------------------------------------------------------------------
// Address: 0x103249A0
// Name: _dynamic_atexit_destructor_for__sv_allow_lobby_connect_only__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sv_allow_lobby_connect_only__()
{
  ConVar::~ConVar(this: &sv_allow_lobby_connect_only);
}

//------------------------------------------------------------------------------
// Address: 0x103249B0
// Name: _dynamic_atexit_destructor_for__sv_reservation_timeout__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sv_reservation_timeout__()
{
  ConVar::~ConVar(this: &sv_reservation_timeout);
}

//------------------------------------------------------------------------------
// Address: 0x103249C0
// Name: _dynamic_atexit_destructor_for__sv_reservation_grace__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sv_reservation_grace__()
{
  ConVar::~ConVar(this: &sv_reservation_grace);
}

//------------------------------------------------------------------------------
// Address: 0x103249D0
// Name: _dynamic_atexit_destructor_for__sv_steamgroup__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sv_steamgroup__()
{
  ConVar::~ConVar(this: &sv_steamgroup);
}

//------------------------------------------------------------------------------
// Address: 0x103249E0
// Name: _dynamic_atexit_destructor_for__sv_steamgroup_exclusive__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sv_steamgroup_exclusive__()
{
  ConVar::~ConVar(this: &sv_steamgroup_exclusive);
}

//------------------------------------------------------------------------------
// Address: 0x103249F0
// Name: _dynamic_atexit_destructor_for__sv_debugtempentities__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sv_debugtempentities__()
{
  ConVar::~ConVar(this: &sv_debugtempentities);
}

//------------------------------------------------------------------------------
// Address: 0x10324A00
// Name: _dynamic_atexit_destructor_for__sv_hosting_lobby__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sv_hosting_lobby__()
{
  ConVar::~ConVar(this: &sv_hosting_lobby);
}

//------------------------------------------------------------------------------
// Address: 0x10324A10
// Name: _dynamic_atexit_destructor_for__sv_showtags_command__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sv_showtags_command__()
{
  ConCommand::~ConCommand(this: &sv_showtags_command);
}

//------------------------------------------------------------------------------
// Address: 0x10324EA0
// Name: _dynamic_atexit_destructor_for__sv_logdownloadlist__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sv_logdownloadlist__()
{
  ConVar::~ConVar(this: &sv_logdownloadlist);
}

//------------------------------------------------------------------------------
// Address: 0x10324F20
// Name: _dynamic_atexit_destructor_for__sv_new_delta_bits__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sv_new_delta_bits__()
{
  ConVar::~ConVar(this: &sv_new_delta_bits);
}

//------------------------------------------------------------------------------
// Address: 0x10325B30
// Name: _dynamic_atexit_destructor_for__sv_autosave__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sv_autosave__()
{
  ConVar::~ConVar(this: &sv_autosave);
}

//------------------------------------------------------------------------------
// Address: 0x10326350
// Name: _dynamic_atexit_destructor_for__sv_maxroutable__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sv_maxroutable__()
{
  ConVar::~ConVar(this: &sv_maxroutable);
}

//------------------------------------------------------------------------------
// Address: 0x10326520
// Name: _dynamic_atexit_destructor_for__sv_dumpstringtables__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sv_dumpstringtables__()
{
  ConVar::~ConVar(this: &sv_dumpstringtables);
}

//------------------------------------------------------------------------------
// Address: 0x10326620
// Name: _dynamic_atexit_destructor_for__sv_useexplicitdelete__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sv_useexplicitdelete__()
{
  ConVar::~ConVar(this: &sv_useexplicitdelete);
}

//------------------------------------------------------------------------------
// Address: 0x103268A0
// Name: _dynamic_atexit_destructor_for__sv_master_legacy_mode__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sv_master_legacy_mode__()
{
  ConVar::~ConVar(this: &sv_master_legacy_mode);
}

//------------------------------------------------------------------------------
// Address: 0x103268B0
// Name: _dynamic_atexit_destructor_for__sv_search_key__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sv_search_key__()
{
  ConVar::~ConVar(this: &sv_search_key);
}

//------------------------------------------------------------------------------
// Address: 0x103133D0
// Name: _dynamic_initializer_for__tv_nochat__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__tv_nochat__()
{
  ConVar::ConVar(
    this: &tv_nochat,
    pName: "tv_nochat",
    pDefaultValue: "0",
    flags: 640,
    pHelpString: "Don't receive chat messages from other SourceTV spectators");
  return atexit(func: dynamic_atexit_destructor_for__tv_nochat__);
}

//------------------------------------------------------------------------------
// Address: 0x103172D0
// Name: _dynamic_initializer_for__ss_voice_hearpartner__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__ss_voice_hearpartner__()
{
  ConVar::ConVar(
    this: &ss_voice_hearpartner,
    pName: "ss_voice_hearpartner",
    pDefaultValue: "0",
    flags: 0,
    pHelpString: "Route voice between splitscreen players on same system.");
  return atexit(func: dynamic_atexit_destructor_for__ss_voice_hearpartner__);
}

//------------------------------------------------------------------------------
// Address: 0x10317420
// Name: _dynamic_initializer_for__g_Tracks__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_Tracks__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_Tracks__);
}

//------------------------------------------------------------------------------
// Address: 0x10317460
// Name: _dynamic_initializer_for__g_IPFilters__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_IPFilters__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_IPFilters__);
}

//------------------------------------------------------------------------------
// Address: 0x10317470
// Name: _dynamic_initializer_for__g_UserFilters__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_UserFilters__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_UserFilters__);
}

//------------------------------------------------------------------------------
// Address: 0x10317480
// Name: _dynamic_initializer_for__addip__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__addip__()
{
  ConCommand::ConCommand(
    this: &addip,
    pName: "addip",
    callback: (void (__cdecl *)())Filter_Add_f,
    pHelpString: "Add an IP address to the ban list.",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__addip__);
}

//------------------------------------------------------------------------------
// Address: 0x103174B0
// Name: _dynamic_initializer_for__banip__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__banip__()
{
  ConCommand::ConCommand(
    this: &banip,
    pName: "banip",
    callback: (void (__cdecl *)())Filter_Add_f,
    pHelpString: "Add an IP address to the ban list.",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__banip__);
}

//------------------------------------------------------------------------------
// Address: 0x103174E0
// Name: _dynamic_initializer_for__removeip_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__removeip_command__()
{
  ConCommand::ConCommand(
    this: &removeip_command,
    pName: "removeip",
    callback: (void (__cdecl *)())removeip,
    pHelpString: "Remove an IP address from the ban list.",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__removeip_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10317510
// Name: _dynamic_initializer_for__listip_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__listip_command__()
{
  ConCommand::ConCommand(
    this: &listip_command,
    pName: "listip",
    callback: listip,
    pHelpString: "List IP addresses on the ban list.",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__listip_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10317540
// Name: _dynamic_initializer_for__writeip_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__writeip_command__()
{
  ConCommand::ConCommand(
    this: &writeip_command,
    pName: "writeip",
    callback: (void (__cdecl *)())writeip,
    pHelpString: "Save the ban list to banned_ip.cfg.",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__writeip_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10317570
// Name: _dynamic_initializer_for__writeid_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__writeid_command__()
{
  ConCommand::ConCommand(
    this: &writeid_command,
    pName: "writeid",
    callback: (void (__cdecl *)())writeid,
    pHelpString: "Writes a list of permanently-banned user IDs to banned_user.cfg.",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__writeid_command__);
}

//------------------------------------------------------------------------------
// Address: 0x103175A0
// Name: _dynamic_initializer_for__removeid_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__removeid_command__()
{
  ConCommand::ConCommand(
    this: &removeid_command,
    pName: "removeid",
    callback: (void (__cdecl *)())removeid,
    pHelpString: "Remove a user ID from the ban list.",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__removeid_command__);
}

//------------------------------------------------------------------------------
// Address: 0x103175D0
// Name: _dynamic_initializer_for__listid_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__listid_command__()
{
  ConCommand::ConCommand(
    this: &listid_command,
    pName: "listid",
    callback: listid,
    pHelpString: "Lists banned users.",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__listid_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10317600
// Name: _dynamic_initializer_for__banid_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__banid_command__()
{
  ConCommand::ConCommand(
    this: &banid_command,
    pName: "banid",
    callback: (void (__cdecl *)())banid,
    pHelpString: "Add a user ID to the ban list.",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__banid_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10317690
// Name: _dynamic_initializer_for__g_FrameSnapshotManager__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_FrameSnapshotManager__()
{
  CFrameSnapshotManager::CFrameSnapshotManager(this: &g_FrameSnapshotManager);
  return atexit(func: dynamic_atexit_destructor_for__g_FrameSnapshotManager__);
}

//------------------------------------------------------------------------------
// Address: 0x10317770
// Name: _dynamic_initializer_for__rateChecker__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__rateChecker__()
{
  rateChecker.m_IPTree.m_Elements.m_pMemory = (UtlRBTreeNode_t<CIPRateLimit::iprate_s,int> *)_g_pMemAlloc->Alloc_2(
                                                                                               this: _g_pMemAlloc,
                                                                                               a2: 7168);
  rateChecker.m_IPTree.m_Root = -1;
  rateChecker.m_IPTree.m_NumElements = 0;
  rateChecker.m_IPTree.m_FirstFree = -1;
  rateChecker.m_IPTree.m_LastAlloc.index = -1;
  rateChecker.m_IPTree.m_pElements = rateChecker.m_IPTree.m_Elements.m_pMemory;
  rateChecker.m_iGlobalCount = 0;
  rateChecker.m_lLastTime = -1;
  return atexit(func: dynamic_atexit_destructor_for__rateChecker__);
}

//------------------------------------------------------------------------------
// Address: 0x103178F0
// Name: _dynamic_initializer_for__g_Log__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_Log__()
{
  int v0; // eax

  g_Log.m_flLastLogFlush = realtime;
  v0 = _CommandLine();
  if ( (*(int (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v0 + 12))(a1: v0, a2: "-flushlog", a3: 0) != 0 )
    g_Log.m_bFlushLog = true;
  g_Log.m_nDebugID = 42;
  return atexit(func: dynamic_atexit_destructor_for__g_Log__);
}

//------------------------------------------------------------------------------
// Address: 0x10317940
// Name: _dynamic_initializer_for__log_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__log_command__()
{
  ConCommand::ConCommand(
    this: &log_command,
    pName: "log",
    callback: (void (__cdecl *)())log,
    pHelpString: "Enables logging to file, console, and udp < on | off >.",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__log_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10317970
// Name: _dynamic_initializer_for__logaddress_add_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__logaddress_add_command__()
{
  ConCommand::ConCommand(
    this: &logaddress_add_command,
    pName: "logaddress_add",
    callback: (void (__cdecl *)())logaddress_add,
    pHelpString: "Set address and port for remote host <ip:port>.",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__logaddress_add_command__);
}

//------------------------------------------------------------------------------
// Address: 0x103179A0
// Name: _dynamic_initializer_for__logaddress_delall_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__logaddress_delall_command__()
{
  ConCommand::ConCommand(
    this: &logaddress_delall_command,
    pName: "logaddress_delall",
    callback: logaddress_delall,
    pHelpString: "Remove all udp addresses being logged to",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__logaddress_delall_command__);
}

//------------------------------------------------------------------------------
// Address: 0x103179D0
// Name: _dynamic_initializer_for__logaddress_del_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__logaddress_del_command__()
{
  ConCommand::ConCommand(
    this: &logaddress_del_command,
    pName: "logaddress_del",
    callback: (void (__cdecl *)())logaddress_del,
    pHelpString: "Remove address and port for remote host <ip:port>.",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__logaddress_del_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10317A00
// Name: _dynamic_initializer_for__logaddress_list_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__logaddress_list_command__()
{
  ConCommand::ConCommand(
    this: &logaddress_list_command,
    pName: "logaddress_list",
    callback: logaddress_list,
    pHelpString: "List all addresses currently being used by logaddress.",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__logaddress_list_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10317B80
// Name: _dynamic_initializer_for__sv__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv__()
{
  CGameServer::CGameServer(this: &sv);
  return atexit(func: dynamic_atexit_destructor_for__sv__);
}

//------------------------------------------------------------------------------
// Address: 0x10317F40
// Name: _dynamic_initializer_for__tv_enable__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__tv_enable__()
{
  ConVar::ConVar(
    this: &tv_enable,
    pName: "tv_enable",
    pDefaultValue: "0",
    flags: 256,
    pHelpString: "Activates SourceTV on server.",
    callback: (void (__cdecl *)(IConVar *, const char *, float))OnTVEnablehanged);
  return atexit(func: dynamic_atexit_destructor_for__tv_enable__);
}

//------------------------------------------------------------------------------
// Address: 0x103184C0
// Name: _dynamic_initializer_for__g_RCONServer__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_RCONServer__()
{
  CSocketCreator::CSocketCreator(this: &g_RCONServer.m_Socket, pListener: &g_RCONServer);
  g_RCONServer.m_failedRcons.m_Memory.m_pMemory = nullptr;
  g_RCONServer.m_failedRcons.m_Memory.m_nAllocationCount = 0;
  g_RCONServer.m_failedRcons.m_Memory.m_nGrowSize = 0;
  g_RCONServer.m_failedRcons.m_Size = 0;
  g_RCONServer.m_failedRcons.m_pElements = nullptr;
  CUtlString::CUtlString(this: &g_RCONServer.m_Password);
  netadr_s::SetIP(this: &g_RCONServer.m_Address, unIP: 0);
  netadr_s::SetPort(this: &g_RCONServer.m_Address, newport: 0);
  netadr_s::SetType(this: &g_RCONServer.m_Address, newtype: NA_IP);
  return atexit(func: dynamic_atexit_destructor_for__g_RCONServer__);
}

//------------------------------------------------------------------------------
// Address: 0x10318530
// Name: _dynamic_initializer_for__g_RPTServer__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_RPTServer__()
{
  CSocketCreator::CSocketCreator(this: &g_RPTServer.m_Socket, pListener: &g_RPTServer);
  g_RPTServer.m_failedRcons.m_Memory.m_pMemory = nullptr;
  g_RPTServer.m_failedRcons.m_Memory.m_nAllocationCount = 0;
  g_RPTServer.m_failedRcons.m_Memory.m_nGrowSize = 0;
  g_RPTServer.m_failedRcons.m_Size = 0;
  g_RPTServer.m_failedRcons.m_pElements = nullptr;
  CUtlString::CUtlString(this: &g_RPTServer.m_Password);
  netadr_s::SetIP(this: &g_RPTServer.m_Address, unIP: 0);
  netadr_s::SetPort(this: &g_RPTServer.m_Address, newport: 0);
  netadr_s::SetType(this: &g_RPTServer.m_Address, newtype: NA_IP);
  g_RPTServer.__vftable = (CRPTServer_vtbl *)&CRPTServer::`vftable';
  return atexit(func: dynamic_atexit_destructor_for__g_RPTServer__);
}

//------------------------------------------------------------------------------
// Address: 0x10318710
// Name: _dynamic_initializer_for__g_ServerRemoteAccess__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_ServerRemoteAccess__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_ServerRemoteAccess__);
}

//------------------------------------------------------------------------------
// Address: 0x10318720
// Name: _dynamic_initializer_for____g_CreateCServerRemoteAccessIGameServerData_reg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
InterfaceReg *dynamic_initializer_for____g_CreateCServerRemoteAccessIGameServerData_reg__()
{
  return InterfaceReg::InterfaceReg(
           this: &_g_CreateCServerRemoteAccessIGameServerData_reg,
           fn: (void *(__cdecl *)())_CreateCServerRemoteAccessIGameServerData_interface,
           pName: "GameServerData001");
}

//------------------------------------------------------------------------------
// Address: 0x10319980
// Name: _dynamic_initializer_for__g_CV_DTWatchEnt__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CV_DTWatchEnt__()
{
  ConVar::ConVar(
    this: &g_CV_DTWatchEnt,
    pName: "dtwatchent",
    pDefaultValue: "-1",
    flags: 0,
    pHelpString: "Watch this entities data table encoding.");
  return atexit(func: dynamic_atexit_destructor_for__g_CV_DTWatchEnt__);
}

//------------------------------------------------------------------------------
// Address: 0x103199B0
// Name: _dynamic_initializer_for__g_CV_DTWatchVar__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CV_DTWatchVar__()
{
  ConVar::ConVar(
    this: &g_CV_DTWatchVar,
    pName: "dtwatchvar",
    pDefaultValue: defaultValue,
    flags: 0,
    pHelpString: "Watch the named variable.");
  return atexit(func: dynamic_atexit_destructor_for__g_CV_DTWatchVar__);
}

//------------------------------------------------------------------------------
// Address: 0x103199E0
// Name: _dynamic_initializer_for__g_CV_DTWarning__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CV_DTWarning__()
{
  ConVar::ConVar(
    this: &g_CV_DTWarning,
    pName: "dtwarning",
    pDefaultValue: "0",
    flags: 0,
    pHelpString: "Print data table warnings?");
  return atexit(func: dynamic_atexit_destructor_for__g_CV_DTWarning__);
}

//------------------------------------------------------------------------------
// Address: 0x10319A10
// Name: _dynamic_initializer_for__g_CV_DTWatchClass__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CV_DTWatchClass__()
{
  ConVar::ConVar(
    this: &g_CV_DTWatchClass,
    pName: "dtwatchclass",
    pDefaultValue: defaultValue,
    flags: 0,
    pHelpString: "Watch all fields encoded with this table.");
  return atexit(func: dynamic_atexit_destructor_for__g_CV_DTWatchClass__);
}

//------------------------------------------------------------------------------
// Address: 0x10319A40
// Name: _dynamic_initializer_for__g_CV_DTEncode__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CV_DTEncode__()
{
  ConVar::ConVar(
    this: &g_CV_DTEncode,
    pName: "dtwatchencode",
    pDefaultValue: "1",
    flags: 0,
    pHelpString: "When watching show encode.");
  return atexit(func: dynamic_atexit_destructor_for__g_CV_DTEncode__);
}

//------------------------------------------------------------------------------
// Address: 0x10319A70
// Name: _dynamic_initializer_for__g_CV_DTDecode__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CV_DTDecode__()
{
  ConVar::ConVar(
    this: &g_CV_DTDecode,
    pName: "dtwatchdecode",
    pDefaultValue: "1",
    flags: 0,
    pHelpString: "When watching show decode.");
  return atexit(func: dynamic_atexit_destructor_for__g_CV_DTDecode__);
}

//------------------------------------------------------------------------------
// Address: 0x10319AD0
// Name: _dynamic_initializer_for__g_DTIRecvTables__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_DTIRecvTables__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_DTIRecvTables__);
}

//------------------------------------------------------------------------------
// Address: 0x10319AE0
// Name: _dynamic_initializer_for__g_DTISendTables__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_DTISendTables__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_DTISendTables__);
}

//------------------------------------------------------------------------------
// Address: 0x1031D3F0
// Name: _dynamic_initializer_for____g_CreateCEngineUniformRandomStreamIUniformRandomStream_reg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
InterfaceReg *dynamic_initializer_for____g_CreateCEngineUniformRandomStreamIUniformRandomStream_reg__()
{
  return InterfaceReg::InterfaceReg(
           this: &_g_CreateCEngineUniformRandomStreamIUniformRandomStream_reg,
           fn: (void *(__cdecl *)())_CreateCEngineUniformRandomStreamIUniformRandomStream_interface,
           pName: "VEngineRandom001");
}

//------------------------------------------------------------------------------
// Address: 0x1031D410
// Name: _dynamic_initializer_for__g_Registry__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_Registry__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_Registry__);
}

//------------------------------------------------------------------------------
// Address: 0x1031DB20
// Name: _dynamic_initializer_for__xlsp_force_dc_name__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__xlsp_force_dc_name__()
{
  ConVar::ConVar(
    this: &xlsp_force_dc_name,
    pName: "xlsp_force_dc_name",
    pDefaultValue: defaultValue,
    flags: 0,
    pHelpString: "Restrict to xlsp datacenter by name.");
  return atexit(func: dynamic_atexit_destructor_for__xlsp_force_dc_name__);
}

//------------------------------------------------------------------------------
// Address: 0x1031DB50
// Name: _dynamic_initializer_for__mm_heartbeat_timeout__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mm_heartbeat_timeout__()
{
  ConVar::ConVar(this: &mm_heartbeat_timeout, pName: "mm_heartbeat_timeout", pDefaultValue: "10", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__mm_heartbeat_timeout__);
}

//------------------------------------------------------------------------------
// Address: 0x1031DB80
// Name: _dynamic_initializer_for__mm_heartbeat_seconds__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mm_heartbeat_seconds__()
{
  ConVar::ConVar(this: &mm_heartbeat_seconds, pName: "mm_heartbeat_seconds", pDefaultValue: "300", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__mm_heartbeat_seconds__);
}

//------------------------------------------------------------------------------
// Address: 0x1031DBB0
// Name: _dynamic_initializer_for__mm_heartbeat_seconds_xlsp__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mm_heartbeat_seconds_xlsp__()
{
  ConVar::ConVar(this: &mm_heartbeat_seconds_xlsp, pName: "mm_heartbeat_seconds_xlsp", pDefaultValue: "60", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__mm_heartbeat_seconds_xlsp__);
}

//------------------------------------------------------------------------------
// Address: 0x1031DBE0
// Name: _dynamic_initializer_for__mm_heartbeat_timeout_legacy__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mm_heartbeat_timeout_legacy__()
{
  ConVar::ConVar(
    this: &mm_heartbeat_timeout_legacy,
    pName: "mm_heartbeat_timeout_legacy",
    pDefaultValue: "15",
    flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__mm_heartbeat_timeout_legacy__);
}

//------------------------------------------------------------------------------
// Address: 0x103226F0
// Name: _dynamic_atexit_destructor_for__tv_nochat__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__tv_nochat__()
{
  ConVar::~ConVar(this: &tv_nochat);
}

//------------------------------------------------------------------------------
// Address: 0x10324100
// Name: _dynamic_atexit_destructor_for__ss_voice_hearpartner__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__ss_voice_hearpartner__()
{
  ConVar::~ConVar(this: &ss_voice_hearpartner);
}

//------------------------------------------------------------------------------
// Address: 0x10324170
// Name: _dynamic_atexit_destructor_for__g_Tracks__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_Tracks__()
{
  CUtlLinkedList<vgui::TreeNode *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int>>::RemoveAll(this: (CUtlLinkedList<vgui::TreeNode *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int> > *)&g_Tracks);
  if ( g_Tracks.m_Memory.m_nGrowSize >= 0 )
  {
    if ( g_Tracks.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: g_Tracks.m_Memory.m_pMemory);
      g_Tracks.m_Memory.m_pMemory = nullptr;
    }
    g_Tracks.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x103241D0
// Name: _dynamic_atexit_destructor_for__addip__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__addip__()
{
  ConCommand::~ConCommand(this: &addip);
}

//------------------------------------------------------------------------------
// Address: 0x103241E0
// Name: _dynamic_atexit_destructor_for__banip__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__banip__()
{
  ConCommand::~ConCommand(this: &banip);
}

//------------------------------------------------------------------------------
// Address: 0x103241F0
// Name: _dynamic_atexit_destructor_for__removeip_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__removeip_command__()
{
  ConCommand::~ConCommand(this: &removeip_command);
}

//------------------------------------------------------------------------------
// Address: 0x10324200
// Name: _dynamic_atexit_destructor_for__listip_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__listip_command__()
{
  ConCommand::~ConCommand(this: &listip_command);
}

//------------------------------------------------------------------------------
// Address: 0x10324210
// Name: _dynamic_atexit_destructor_for__writeip_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__writeip_command__()
{
  ConCommand::~ConCommand(this: &writeip_command);
}

//------------------------------------------------------------------------------
// Address: 0x10324220
// Name: _dynamic_atexit_destructor_for__writeid_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__writeid_command__()
{
  ConCommand::~ConCommand(this: &writeid_command);
}

//------------------------------------------------------------------------------
// Address: 0x10324230
// Name: _dynamic_atexit_destructor_for__removeid_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__removeid_command__()
{
  ConCommand::~ConCommand(this: &removeid_command);
}

//------------------------------------------------------------------------------
// Address: 0x10324240
// Name: _dynamic_atexit_destructor_for__listid_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__listid_command__()
{
  ConCommand::~ConCommand(this: &listid_command);
}

//------------------------------------------------------------------------------
// Address: 0x10324250
// Name: _dynamic_atexit_destructor_for__banid_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__banid_command__()
{
  ConCommand::~ConCommand(this: &banid_command);
}

//------------------------------------------------------------------------------
// Address: 0x10324260
// Name: _dynamic_atexit_destructor_for__g_IPFilters__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_IPFilters__()
{
  CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&g_IPFilters);
}

//------------------------------------------------------------------------------
// Address: 0x10324270
// Name: _dynamic_atexit_destructor_for__g_UserFilters__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_UserFilters__()
{
  CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&g_UserFilters);
}

//------------------------------------------------------------------------------
// Address: 0x103242A0
// Name: _dynamic_atexit_destructor_for__g_FrameSnapshotManager__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_FrameSnapshotManager__()
{
  CFrameSnapshotManager::~CFrameSnapshotManager(this: &g_FrameSnapshotManager);
}

//------------------------------------------------------------------------------
// Address: 0x103242F0
// Name: _dynamic_atexit_destructor_for__rateChecker__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__rateChecker__()
{
  CUtlRBTree<CIPRateLimit::iprate_s,int,bool (__cdecl *)(CIPRateLimit::iprate_s const &,CIPRateLimit::iprate_s const &),CUtlMemory<UtlRBTreeNode_t<CIPRateLimit::iprate_s,int>,int>>::~CUtlRBTree<CIPRateLimit::iprate_s,int,bool (__cdecl *)(CIPRateLimit::iprate_s const &,CIPRateLimit::iprate_s const &),CUtlMemory<UtlRBTreeNode_t<CIPRateLimit::iprate_s,int>,int>>(this: &rateChecker.m_IPTree);
}

//------------------------------------------------------------------------------
// Address: 0x10324360
// Name: _dynamic_atexit_destructor_for__log_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__log_command__()
{
  ConCommand::~ConCommand(this: &log_command);
}

//------------------------------------------------------------------------------
// Address: 0x10324370
// Name: _dynamic_atexit_destructor_for__logaddress_add_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__logaddress_add_command__()
{
  ConCommand::~ConCommand(this: &logaddress_add_command);
}

//------------------------------------------------------------------------------
// Address: 0x10324380
// Name: _dynamic_atexit_destructor_for__logaddress_delall_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__logaddress_delall_command__()
{
  ConCommand::~ConCommand(this: &logaddress_delall_command);
}

//------------------------------------------------------------------------------
// Address: 0x10324390
// Name: _dynamic_atexit_destructor_for__logaddress_del_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__logaddress_del_command__()
{
  ConCommand::~ConCommand(this: &logaddress_del_command);
}

//------------------------------------------------------------------------------
// Address: 0x103243A0
// Name: _dynamic_atexit_destructor_for__logaddress_list_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__logaddress_list_command__()
{
  ConCommand::~ConCommand(this: &logaddress_list_command);
}

//------------------------------------------------------------------------------
// Address: 0x103243B0
// Name: _dynamic_atexit_destructor_for__g_Log__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_Log__()
{
  g_Log.__vftable = (CLog_vtbl *)&CLog::`vftable';
  g_Log.m_nDebugID = 13;
  CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&g_Log.m_LogAddresses);
  g_Log.__vftable = (CLog_vtbl *)&IGameEventListener2::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x10324580
// Name: _dynamic_atexit_destructor_for__tv_enable__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__tv_enable__()
{
  ConVar::~ConVar(this: &tv_enable);
}

//------------------------------------------------------------------------------
// Address: 0x10324780
// Name: _dynamic_atexit_destructor_for__g_RCONServer__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_RCONServer__()
{
  g_RCONServer.__vftable = (CRConServer_vtbl *)&CRConServer::`vftable';
  g_RCONServer.m_Password.m_Storage.m_nActualLength = 0;
  if ( g_RCONServer.m_Password.m_Storage.m_Memory.m_nGrowSize >= 0 )
  {
    if ( g_RCONServer.m_Password.m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: g_RCONServer.m_Password.m_Storage.m_Memory.m_pMemory);
      g_RCONServer.m_Password.m_Storage.m_Memory.m_pMemory = nullptr;
    }
    g_RCONServer.m_Password.m_Storage.m_Memory.m_nAllocationCount = 0;
  }
  CUtlVector<CRConServer::FailedRCon_t,CUtlMemory<CRConServer::FailedRCon_t,int>>::~CUtlVector<CRConServer::FailedRCon_t,CUtlMemory<CRConServer::FailedRCon_t,int>>(this: &g_RCONServer.m_failedRcons);
  CSocketCreator::~CSocketCreator(this: &g_RCONServer.m_Socket);
}

//------------------------------------------------------------------------------
// Address: 0x103247E0
// Name: _dynamic_atexit_destructor_for__g_RPTServer__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_RPTServer__()
{
  g_RPTServer.__vftable = (CRPTServer_vtbl *)&CRConServer::`vftable';
  g_RPTServer.m_Password.m_Storage.m_nActualLength = 0;
  if ( g_RPTServer.m_Password.m_Storage.m_Memory.m_nGrowSize >= 0 )
  {
    if ( g_RPTServer.m_Password.m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: g_RPTServer.m_Password.m_Storage.m_Memory.m_pMemory);
      g_RPTServer.m_Password.m_Storage.m_Memory.m_pMemory = nullptr;
    }
    g_RPTServer.m_Password.m_Storage.m_Memory.m_nAllocationCount = 0;
  }
  CUtlVector<CRConServer::FailedRCon_t,CUtlMemory<CRConServer::FailedRCon_t,int>>::~CUtlVector<CRConServer::FailedRCon_t,CUtlMemory<CRConServer::FailedRCon_t,int>>(this: &g_RPTServer.m_failedRcons);
  CSocketCreator::~CSocketCreator(this: &g_RPTServer.m_Socket);
}

//------------------------------------------------------------------------------
// Address: 0x10324A20
// Name: _EngineBitBufErrorHandler_::_5_::_dynamic_atexit_destructor_for__errorNames__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl EngineBitBufErrorHandler_::_5_::_dynamic_atexit_destructor_for__errorNames__()
{
  CUtlSymbolTable *v0; // esi
  int i; // edi

  v0 = (CUtlSymbolTable *)&_S1_14;
  for ( i = 1; i >= 0; --i )
    CUtlSymbolTable::~CUtlSymbolTable(this: --v0);
}

//------------------------------------------------------------------------------
// Address: 0x10324EB0
// Name: _dynamic_atexit_destructor_for__g_DownloadListGenerator__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_DownloadListGenerator__()
{
  CUtlSymbolTable::~CUtlSymbolTable(this: &g_DownloadListGenerator.m_AlreadyWrittenFileNames);
}

//------------------------------------------------------------------------------
// Address: 0x10324EC0
// Name: _dynamic_atexit_destructor_for__g_CV_DTWatchEnt__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CV_DTWatchEnt__()
{
  ConVar::~ConVar(this: &g_CV_DTWatchEnt);
}

//------------------------------------------------------------------------------
// Address: 0x10324ED0
// Name: _dynamic_atexit_destructor_for__g_CV_DTWatchVar__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CV_DTWatchVar__()
{
  ConVar::~ConVar(this: &g_CV_DTWatchVar);
}

//------------------------------------------------------------------------------
// Address: 0x10324EE0
// Name: _dynamic_atexit_destructor_for__g_CV_DTWarning__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CV_DTWarning__()
{
  ConVar::~ConVar(this: &g_CV_DTWarning);
}

//------------------------------------------------------------------------------
// Address: 0x10324EF0
// Name: _dynamic_atexit_destructor_for__g_CV_DTWatchClass__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CV_DTWatchClass__()
{
  ConVar::~ConVar(this: &g_CV_DTWatchClass);
}

//------------------------------------------------------------------------------
// Address: 0x10324F00
// Name: _dynamic_atexit_destructor_for__g_CV_DTEncode__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CV_DTEncode__()
{
  ConVar::~ConVar(this: &g_CV_DTEncode);
}

//------------------------------------------------------------------------------
// Address: 0x10324F10
// Name: _dynamic_atexit_destructor_for__g_CV_DTDecode__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CV_DTDecode__()
{
  ConVar::~ConVar(this: &g_CV_DTDecode);
}

//------------------------------------------------------------------------------
// Address: 0x10324F30
// Name: _dynamic_atexit_destructor_for__g_DTIRecvTables__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_DTIRecvTables__()
{
  CUtlLinkedList<vgui::TreeNode *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int>>::RemoveAll(this: (CUtlLinkedList<vgui::TreeNode *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int> > *)&g_DTIRecvTables);
  if ( g_DTIRecvTables.m_Memory.m_nGrowSize >= 0 )
  {
    if ( g_DTIRecvTables.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: g_DTIRecvTables.m_Memory.m_pMemory);
      g_DTIRecvTables.m_Memory.m_pMemory = nullptr;
    }
    g_DTIRecvTables.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10324F80
// Name: _dynamic_atexit_destructor_for__g_DTISendTables__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_DTISendTables__()
{
  CUtlLinkedList<CFrameSnapshot *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CFrameSnapshot *,unsigned short>,unsigned short>>::RemoveAll(this: (CUtlLinkedList<unsigned int,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<unsigned int,unsigned short>,unsigned short> > *)&g_DTISendTables);
  if ( g_DTISendTables.m_Memory.m_nGrowSize >= 0 )
  {
    if ( g_DTISendTables.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: g_DTISendTables.m_Memory.m_pMemory);
      g_DTISendTables.m_Memory.m_pMemory = nullptr;
    }
    g_DTISendTables.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10326630
// Name: _dynamic_atexit_destructor_for__g_Registry__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_Registry__()
{
  g_Registry.__vftable = (CRegistry_vtbl *)&CRegistry::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x103268C0
// Name: _dynamic_atexit_destructor_for__xlsp_force_dc_name__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__xlsp_force_dc_name__()
{
  ConVar::~ConVar(this: &xlsp_force_dc_name);
}

//------------------------------------------------------------------------------
// Address: 0x103268D0
// Name: _dynamic_atexit_destructor_for__mm_heartbeat_timeout__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mm_heartbeat_timeout__()
{
  ConVar::~ConVar(this: &mm_heartbeat_timeout);
}

//------------------------------------------------------------------------------
// Address: 0x103268E0
// Name: _dynamic_atexit_destructor_for__mm_heartbeat_seconds__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mm_heartbeat_seconds__()
{
  ConVar::~ConVar(this: &mm_heartbeat_seconds);
}

//------------------------------------------------------------------------------
// Address: 0x103268F0
// Name: _dynamic_atexit_destructor_for__mm_heartbeat_seconds_xlsp__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mm_heartbeat_seconds_xlsp__()
{
  ConVar::~ConVar(this: &mm_heartbeat_seconds_xlsp);
}

//------------------------------------------------------------------------------
// Address: 0x10326900
// Name: _dynamic_atexit_destructor_for__mm_heartbeat_timeout_legacy__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mm_heartbeat_timeout_legacy__()
{
  ConVar::~ConVar(this: &mm_heartbeat_timeout_legacy);
}

//------------------------------------------------------------------------------
// Address: 0x10326910
// Name: _dynamic_atexit_destructor_for__pingserver_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__pingserver_command__()
{
  ConCommand::~ConCommand(this: &pingserver_command);
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x100FF9F0
// Name: public: virtual void CFunctor2<void (*)(struct msurface2_t __near *,class Vector),struct msurface2_t __near *,class Vector,class CRefCounted1<class CFunctor,class CRefCountServiceBase<1,class CRefMT>>>::operator()(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFunctor2<void (__cdecl *)(msurface2_t *,Vector),msurface2_t *,Vector,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>>::operator()(
        CFunctor2<void (__cdecl*)(msurface2_t *,Vector),msurface2_t *,Vector,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> > > *this)
{
  ((void (__cdecl *)(msurface2_t *, _DWORD, _DWORD, _DWORD))this->m_pfnProxied)(
    a1: this->m_arg1,
    a2: LODWORD(this->m_arg2.x),
    a3: LODWORD(this->m_arg2.y),
    a4: LODWORD(this->m_arg2.z));
}

//------------------------------------------------------------------------------
// Address: 0x101240E0
// Name: void SV_ForceSend(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SV_ForceSend()
{
  s_bForceSend = true;
}

//------------------------------------------------------------------------------
// Address: 0x101240F0
// Name: bool SV_FlushMemoryIfMarked(void)
// Source: json
//------------------------------------------------------------------------------
char __cdecl SV_FlushMemoryIfMarked()
{
  if ( g_bFlushMemoryOnNextServer )
  {
    g_bFlushMemoryOnNextServer = false;
    g_pDataCache->Flush(this: g_pDataCache, a2: true, a3: true);
    g_pMaterialSystem->CompactMemory(this: g_pMaterialSystem);
    g_pFileSystem->AsyncFinishAll(this: g_pFileSystem, a2: 0);
    CThreadMutex::Lock(this: &g_SndMutex);
    g_pFileSystem->AsyncSuspend(this: g_pFileSystem);
    _g_pThreadPool->SuspendExecution(this: _g_pThreadPool);
    _g_pMemAlloc->CompactHeap(this: _g_pMemAlloc);
    _g_pThreadPool->ResumeExecution(this: _g_pThreadPool);
    g_pFileSystem->AsyncResume(this: g_pFileSystem);
    CThreadMutex::Unlock(this: &g_SndMutex);
    return 1;
  }
  else
  {
    _g_pMemAlloc->CompactHeap(this: _g_pMemAlloc);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101241B0
// Name: void SV_InstallClientStringTableMirrors(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SV_InstallClientStringTableMirrors()
{
  int v0; // ebx
  INetworkStringTable *v1; // eax
  CAudioMixerWave *v2; // esi
  CNetworkStringTableContainer_vtbl *v3; // edi
  int v4; // eax
  int v5; // eax
  const char *v6; // eax
  int numTables; // [esp+4h] [ebp-4h]

  v0 = 0;
  numTables = networkStringTableContainerServer->GetNumTables(this: networkStringTableContainerServer);
  if ( numTables > 0 )
  {
    do
    {
      v1 = networkStringTableContainerServer->GetTable(this: networkStringTableContainerServer, a2: v0);
      v2 = (CAudioMixerWave *)v1;
      if ( v1 != nullptr )
      {
        v3 = networkStringTableContainerClient->__vftable;
        v4 = (int)v1->GetTableName(this: v1);
        v5 = (int)v3->FindTable(this: networkStringTableContainerClient, a2: (const char *)v4);
        if ( v5 != 0 )
        {
          CNetworkStringTable::SetMirrorTable(this: v2, delaySamples: v5);
        }
        else
        {
          v6 = (const char *)((int (__thiscall *)(CAudioMixerWave *))v2->MixDataToDevice)(a1: v2);
          DevMsg(a1: "SV_InstallClientStringTableMirrors! Missing client table \"%s\".\n ", v6);
        }
      }
      ++v0;
    }
    while ( v0 < numTables );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10124240
// Name: void SV_InitSendTables(class ServerClass __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SV_InitSendTables(ServerClass *pClasses)
{
  ServerClass *v1; // esi
  int i; // edi
  SendTable *pTables[1024]; // [esp+8h] [ebp-1000h] BYREF

  v1 = pClasses;
  for ( i = 0; v1 != nullptr; ++i )
  {
    if ( i >= 1024 )
      _Error(a1: "SV_BuildSendTablesArray: too many SendTables!");
    pTables[i] = v1->m_pTable;
    v1 = v1->m_pNext;
  }
  SendTable_Init(pTables, nTables: i);
}

//------------------------------------------------------------------------------
// Address: 0x101242A0
// Name: void ServerDLL_Unload(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __cdecl ServerDLL_Unload()
{
  UnloadEntityDLLs();
}

//------------------------------------------------------------------------------
// Address: 0x101242B0
// Name: void SV_ShutdownGameDLL(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SV_ShutdownGameDLL()
{
  CSteam3Server *v0; // eax

  if ( sv.dll_initialized )
  {
    serverGameDLL->GetAllServerClasses(this: serverGameDLL);
    SendTable_Term();
    CServerPlugin::UnloadPlugins(this: g_pServerPluginHandler);
    serverGameDLL->DLLShutdown(this: serverGameDLL);
    UnloadEntityDLLs();
    sv.dll_initialized = false;
    v0 = Steam3Server();
    CSteam3Server::Shutdown(this: v0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10124300
// Name: class ServerClass __near * SV_FindServerClass(int)
// Source: json
//------------------------------------------------------------------------------
ServerClass *__cdecl SV_FindServerClass(int index)
{
  ServerClass *result; // eax
  int i; // ecx

  result = serverGameDLL->GetAllServerClasses(this: serverGameDLL);
  for ( i = 0; i < index; ++i )
  {
    if ( result == nullptr )
      break;
    result = result->m_pNext;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10124330
// Name: public: virtual void CGameServer::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameServer::Shutdown(CGameServer *this)
{
  IGameEvent *v2; // esi
  IGameEvent *v3; // esi

  this->m_bIsLevelMainMenuBackground = false;
  v2 = g_GameEventManager->CreateEventA(this: g_GameEventManager, a2: "server_pre_shutdown", a3: 0, a4: 0);
  if ( v2 != nullptr )
  {
    v2->SetString(this: v2, a2: "reason", a3: "quit");
    g_GameEventManager->FireEvent(this: g_GameEventManager, a2: v2, a3: false);
  }
  CBaseServer::Shutdown(this);
  framesnapshotmanager->LevelChanged(this: framesnapshotmanager);
  v3 = g_GameEventManager->CreateEventA(this: g_GameEventManager, a2: "server_shutdown", a3: 0, a4: 0);
  if ( v3 != nullptr )
  {
    v3->SetString(this: v3, a2: "reason", a3: "quit");
    g_GameEventManager->FireEvent(this: g_GameEventManager, a2: v3, a3: false);
  }
  CLog::Close(this: &g_Log);
}

//------------------------------------------------------------------------------
// Address: 0x101243E0
// Name: public: virtual void CGameServer::RemoveClientFromGame(class CBaseClient __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameServer::RemoveClientFromGame(CGameServer *this, CBaseClient *client)
{
  if ( *(_DWORD *)client[1].m_GUID != 0 && client->IsSpawned(this: &client->IClient) && this->IsActive(this) )
  {
    g_pServerPluginHandler->ClientDisconnect(this: g_pServerPluginHandler, a2: *(edict_t **)client[1].m_GUID);
    serverGameEnts->FreeContainingEntity(this: serverGameEnts, a2: *(edict_t **)client[1].m_GUID);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10124440
// Name: protected: virtual class CBaseClient __near * CGameServer::CreateNewClient(int)
// Source: json
//------------------------------------------------------------------------------
CGameClient *__thiscall CGameServer::CreateNewClient(CGameServer *this, int slot)
{
  CGameClient *v3; // eax
  CGameClient *v4; // esi
  int v5; // eax
  int v6; // eax
  const char *pszValue; // [esp+4h] [ebp-4h] BYREF

  v3 = (CGameClient *)MemAlloc_Alloc(nSize: 0x21AF0u);
  if ( v3 != nullptr )
    v4 = CGameClient::CGameClient(this: v3, slot, pServer: this);
  else
    v4 = nullptr;
  pszValue = nullptr;
  if ( v4 != nullptr )
  {
    v5 = _CommandLine();
    if ( (*(int (__thiscall **)(int, const char *, const char **))(*(_DWORD *)v5 + 12))(
           a1: v5,
           a2: "-netspike",
           a3: &pszValue) != 0
      && pszValue != nullptr )
    {
      v6 = V_atoi(str: pszValue);
      CBaseClient::SetTraceThreshold(this: v4, nThreshold: v6);
    }
  }
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x10124550
// Name: public: bool CGameServer::IsInPureServerMode(void)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CGameServer::IsInPureServerMode(CGameServer *this)
{
  return this->m_pPureServerWhitelist != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x101245A0
// Name: void SV_ParallelSendSnapshot(class CGameClient __near * __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SV_ParallelSendSnapshot(CGameClient **pClient)
{
  CClientFrame *SendFrame; // eax

  SendFrame = CGameClient::GetSendFrame(this: *pClient);
  if ( SendFrame != nullptr )
  {
    (*pClient)->SendSnapshot(this: *pClient, a2: SendFrame);
    (*pClient)->UpdateSendState(this: *pClient);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10124610
// Name: public: bool CSteamID::IsValid(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CSteamID::IsValid(CSteamID *this)
{
  int m_unAll64Bits_high; // esi
  unsigned int v2; // eax

  m_unAll64Bits_high = HIDWORD(this->m_steamid.m_unAll64Bits);
  v2 = ((unsigned int)m_unAll64Bits_high >> 20) & 0xF;
  return v2 != 0
      && v2 < 0xB
      && m_unAll64Bits_high >> 24 > 0
      && m_unAll64Bits_high >> 24 < 6
      && (v2 != 1 || this->m_steamid.m_comp != 0 && (m_unAll64Bits_high & 0xFFFFF) == 1)
      && (v2 != 7 || this->m_steamid.m_comp != 0 && (m_unAll64Bits_high & 0xFFFFF) == 0);
}

//------------------------------------------------------------------------------
// Address: 0x10124670
// Name: public: virtual float CBaseServer::GetTickInterval(void)const
// Source: json
//------------------------------------------------------------------------------
double __thiscall CBaseServer::GetTickInterval(CBaseServer *this)
{
  return this->m_flTickInterval;
}

//------------------------------------------------------------------------------
// Address: 0x10124680
// Name: public: bool CBaseServer::IsReserved(void)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CBaseServer::IsReserved(CBaseServer *this)
{
  return this->m_nReservationCookie != 0;
}

//------------------------------------------------------------------------------
// Address: 0x101246A0
// Name: SV_CheatsChanged_f
// Source: json
//------------------------------------------------------------------------------
void __cdecl SV_CheatsChanged_f(IConVar *pConVar)
{
  ConVarRef var; // [esp+0h] [ebp-8h] BYREF

  ConVarRef::ConVarRef(this: &var, pConVar);
  if ( var.m_pConVarState->m_Value.m_nValue == 0 )
  {
    g_pCVar->RevertFlaggedConVars(this: g_pCVar, a2: 0x4000);
    DevMsg(a1: "FCVAR_CHEAT cvars reverted to defaults.\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x101246E0
// Name: SV_Pure_f
// Source: json
//------------------------------------------------------------------------------
void __cdecl SV_Pure_f(const CCommand *args)
{
  unsigned int v1; // esi

  v1 = -1;
  if ( args->m_nArgc == 2 )
    v1 = atoi(nptr: args->m_ppArgv[1]);
  _Msg(a1: "--------------------------------------------------------\n");
  if ( v1 <= 2 )
  {
    if ( v1 == g_sv_pure_mode )
    {
      _Msg(a1: "sv_pure value unchanged (current value is %d).\n", g_sv_pure_mode);
    }
    else
    {
      g_sv_pure_mode = v1;
      _Msg(a1: "sv_pure set to %d.\n", v1);
      if ( sv.m_State >= ss_active )
        _Msg(a1: "Note: Changes to sv_pure take effect when the next map is loaded.\n");
    }
  }
  else
  {
    _Msg(
      a1: "sv_pure:\n"
      "\n"
      "If set to 1, the server will force all client files except the whitelisted ones (in pure_server_whitelist.txt) to "
      "match the server's files. \n"
      "\n"
      "If set to 2, the server will force all client files to come from Steam (and it will not load pure_server_whitelist.txt).\n");
  }
  if ( v1 == -1 )
  {
    if ( GetBaseLocalClient()->m_nSignonState >= 2 )
    {
      _Msg(a1: "\n\n");
      CL_PrintWhitelistInfo();
      _Msg(a1: "--------------------------------------------------------\n");
      return;
    }
    _Msg(a1: "\nCurrent sv_pure value is %d.\n", g_sv_pure_mode);
  }
  _Msg(a1: "--------------------------------------------------------\n");
}

//------------------------------------------------------------------------------
// Address: 0x101247B0
// Name: bool ServerDLL_Load(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl ServerDLL_Load()
{
  LoadEntityDLLs(szBaseDir: host_parms.basedir);
  return g_ServerFactory != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x101247D0
// Name: class ServerClass __near * SV_FindServerClass(char const __near *)
// Source: json
//------------------------------------------------------------------------------
ServerClass *__cdecl SV_FindServerClass(const char *pName)
{
  ServerClass *v1; // esi

  v1 = serverGameDLL->GetAllServerClasses(this: serverGameDLL);
  if ( v1 == nullptr )
    return nullptr;
  while ( _V_stricmp(s1: v1->m_pNetworkName, s2: pName) != 0 )
  {
    v1 = v1->m_pNext;
    if ( v1 == nullptr )
      return nullptr;
  }
  return v1;
}

//------------------------------------------------------------------------------
// Address: 0x10124820
// Name: protected: void CGameServer::ReloadWhitelist(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameServer::ReloadWhitelist(CGameServer *this, const char *pMapName)
{
  CPureServerWhitelist *m_pPureServerWhitelist; // ecx
  CPureServerWhitelist *v4; // ecx
  CPureServerWhitelist *v5; // eax
  bool v6; // zf
  int v7; // ecx
  KeyValues *v8; // eax
  KeyValues *v9; // esi
  IBaseFileSystem *v10; // eax
  IBaseFileSystem *v11; // eax
  int v12; // esi
  int v13; // ecx
  double v14; // st7
  char testFilename[260]; // [esp+4h] [ebp-10Ch] BYREF
  double startTime; // [esp+108h] [ebp-8h]

  m_pPureServerWhitelist = this->m_pPureServerWhitelist;
  if ( m_pPureServerWhitelist != nullptr )
  {
    CPureServerWhitelist::Release(this: m_pPureServerWhitelist);
    this->m_pPureServerWhitelist = nullptr;
  }
  if ( this->GetMaxClients(this) > 1 )
  {
    v4 = this->m_pPureServerWhitelist;
    if ( v4 != nullptr )
    {
      CPureServerWhitelist::Release(this: v4);
      this->m_pPureServerWhitelist = nullptr;
    }
    if ( g_sv_pure_mode != 0 )
    {
      v5 = CPureServerWhitelist::Create(pFileSystem: g_pFileSystem);
      v6 = g_sv_pure_mode == 2;
      this->m_pPureServerWhitelist = v5;
      if ( v6 )
      {
        CPureServerWhitelist::EnableFullyPureMode(this: v5);
        _Msg(a1: "Server using sv_pure 2.\n");
      }
      else
      {
        v8 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
        if ( v8 != nullptr )
          v9 = KeyValues::KeyValues(this: v8, setName: defaultValue);
        else
          v9 = nullptr;
        if ( g_pFileSystem != nullptr )
          v10 = &g_pFileSystem->IBaseFileSystem;
        else
          v10 = nullptr;
        if ( !KeyValues::LoadFromFile(
                this: v9,
                filesystem: v10,
                resourceName: "pure_server_whitelist.txt",
                pathID: "game",
                pfnEvaluateSymbolProc: nullptr)
          || CPureServerWhitelist::LoadFromKeyValues(this: this->m_pPureServerWhitelist, kv: v9) == 0 )
        {
          _Warning(a1: "Can't load pure server whitelist in %s.\n", "pure_server_whitelist.txt");
        }
        strcpy(testFilename, "maps");
        memset(dst: (unsigned __int8 *)&testFilename[5], value: 0, count: 0xFFu);
        V_AppendSlash(pStr: testFilename, strSize: 260);
        V_strncat(pDest: testFilename, pSrc: pMapName, destBufferSize: 0x104u, max_chars_to_copy: -1);
        V_strncat(pDest: testFilename, pSrc: "_whitelist.txt", destBufferSize: 0x104u, max_chars_to_copy: -1);
        KeyValues::Clear(this: v9);
        if ( g_pFileSystem != nullptr )
          v11 = &g_pFileSystem->IBaseFileSystem;
        else
          v11 = nullptr;
        if ( KeyValues::LoadFromFile(
               this: v9,
               filesystem: v11,
               resourceName: testFilename,
               pathID: nullptr,
               pfnEvaluateSymbolProc: nullptr) )
        {
          CPureServerWhitelist::LoadFromKeyValues(this: this->m_pPureServerWhitelist, kv: v9);
        }
        KeyValues::deleteThis(this: v9);
      }
      startTime = _Plat_FloatTime(a1: v7);
      _Msg(a1: "Caching file CRCs for pure server...\n");
      v12 = g_pFileSystem->GetWhitelistSpewFlags(this: g_pFileSystem);
      if ( sv_pure_trace.m_pParent != nullptr && sv_pure_trace.m_pParent->m_Value.m_nValue > 0 )
        g_pFileSystem->SetWhitelistSpewFlags(this: g_pFileSystem, a2: v12 | 1);
      CPureServerWhitelist::CacheFileCRCs(this: this->m_pPureServerWhitelist);
      ((void (__thiscall *)(IFileSystem *))g_pFileSystem->SetWhitelistSpewFlags)(a1: g_pFileSystem);
      v14 = _Plat_FloatTime(a1: v13);
      _Msg(a1: "Finished caching file CRCs for pure server in %d seconds.\n", (int)(v14 - startTime));
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10124A60
// Name: public: void CGameServer::ExecGameTypeCfg(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameServer::ExecGameTypeCfg(CGameServer *this, const char *mapname)
{
  KeyValues *v3; // eax
  KeyValues *v4; // esi
  int Int; // eax

  v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v3 != nullptr )
    v4 = KeyValues::KeyValues(this: v3, setName: "::ExecGameTypeCfg");
  else
    v4 = nullptr;
  KeyValues::SetString(this: v4, keyName: "map/mapname", value: mapname);
  serverGameDLL->ApplyGameSettings(this: serverGameDLL, a2: v4);
  Int = KeyValues::GetInt(this: v4, keyName: "members/numSlots", defaultValue: -1);
  if ( Int >= 0 )
    this->m_numGameSlots = Int;
  if ( v4 != nullptr )
    KeyValues::deleteThis(this: v4);
}

//------------------------------------------------------------------------------
// Address: 0x10124AE0
// Name: bool SV_IsSimulating(void)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl SV_IsSimulating()
{
  bool result; // al
  IEngineVGuiInternal *v1; // eax

  result = false;
  if ( sv.m_State != ss_paused )
  {
    if ( sv.m_nMaxclients > 1 )
      return true;
    if ( !g_LostVideoMemory )
    {
      if ( GetBaseLocalClient()->m_nSignonState != 6 )
        return true;
      if ( !Con_IsVisible() )
      {
        v1 = EngineVGui();
        if ( !v1->ShouldPause(this: v1) )
          return true;
      }
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10124B30
// Name: void SV_Think(bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SV_Think(BOOL bIsSimulating)
{
  int m_nValue; // eax

  if ( !sv.m_bIsDedicated || (CBaseServer::UpdateReservedState(this: &sv), !sv.m_bHibernating) )
  {
    g_ServerGlobalVariables.tickcount = sv.m_nTickCount;
    g_ServerGlobalVariables.curtime = CBaseServer::GetTime(this: &sv);
    if ( bIsSimulating )
    {
      g_ServerGlobalVariables.frametime = host_state.interval_per_tick;
      if ( sv.m_nMaxclients > 1 || GetBaseLocalClient()->m_nSignonState == 6 )
      {
        LOBYTE(bIsSimulating) = 1;
LABEL_17:
        CDebugOverlay::PurgeServerOverlays();
        g_pServerPluginHandler->GameFrame(this: g_pServerPluginHandler, a2: bIsSimulating);
        return;
      }
    }
    else
    {
      g_ServerGlobalVariables.frametime = 0.0;
    }
    LOBYTE(bIsSimulating) = 0;
    goto LABEL_17;
  }
  if ( sv_hibernate_ms.m_pParent != nullptr )
    m_nValue = sv_hibernate_ms.m_pParent->m_Value.m_nValue;
  else
    m_nValue = 0;
  if ( g_bIsVGuiBasedDedicatedServer )
  {
    if ( sv_hibernate_ms_vgui.m_pParent != nullptr )
    {
      NET_SleepUntilMessages(nMilliseconds: sv_hibernate_ms_vgui.m_pParent->m_Value.m_nValue);
      return;
    }
    m_nValue = 0;
  }
  NET_SleepUntilMessages(nMilliseconds: m_nValue);
}

//------------------------------------------------------------------------------
// Address: 0x10124C00
// Name: public: void CUtlMemory<unsigned char,int>::EnsureCapacity(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<unsigned char,int>::EnsureCapacity(CUtlMemory<unsigned char,int> *this, int num)
{
  unsigned __int8 *m_pMemory; // eax

  if ( this->m_nAllocationCount < num && this->m_nGrowSize >= 0 )
  {
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = num;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (unsigned __int8 *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: num);
    else
      this->m_pMemory = (unsigned __int8 *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: num);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10124CC0
// Name: public: void CGameServer::InitMaxClients(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameServer::InitMaxClients(CGameServer *this)
{
  int v2; // eax
  int v3; // edx
  int v4; // eax
  int v5; // eax
  int m_nMinClientsLimit; // ecx
  int m_nMaxClientsLimit; // ecx
  int v8; // edi
  int defaultmaxplayers; // [esp+Ch] [ebp-Ch] BYREF
  int maxmaxplayers; // [esp+10h] [ebp-8h] BYREF
  int minmaxplayers; // [esp+14h] [ebp-4h] BYREF

  v2 = 1;
  v3 = 64;
  minmaxplayers = 1;
  maxmaxplayers = 64;
  defaultmaxplayers = 1;
  if ( serverGameClients == nullptr )
    goto LABEL_12;
  serverGameClients->GetPlayerLimits(
    this: serverGameClients,
    a2: &minmaxplayers,
    a3: &maxmaxplayers,
    a4: &defaultmaxplayers);
  v2 = minmaxplayers;
  if ( minmaxplayers >= 1 )
  {
    if ( defaultmaxplayers >= 1 )
      goto LABEL_7;
    Sys_Error(error: "GetPlayerLimits:  default maxplayers must be >= 1 (%i)", minmaxplayers);
  }
  else
  {
    Sys_Error(error: "GetPlayerLimits:  min maxplayers must be >= 1 (%i)", minmaxplayers);
  }
  v2 = minmaxplayers;
LABEL_7:
  v3 = maxmaxplayers;
  if ( v2 > maxmaxplayers || defaultmaxplayers > maxmaxplayers )
  {
    Sys_Error(error: "GetPlayerLimits:  min maxplayers %i > max %i", v2, maxmaxplayers);
    v2 = minmaxplayers;
    v3 = maxmaxplayers;
  }
  if ( v3 > 64 )
  {
    Sys_Error(error: "GetPlayerLimits:  max players limited to %i", 64);
    v2 = minmaxplayers;
    v3 = maxmaxplayers;
  }
LABEL_12:
  this->m_nMinClientsLimit = v2;
  this->m_nMaxClientsLimit = v3;
  v4 = _CommandLine();
  v5 = (*(int (__thiscall **)(int, const char *, int))(*(_DWORD *)v4 + 28))(a1: v4, a2: "-maxplayers", a3: -1);
  if ( tv_enable.m_pParent != nullptr && tv_enable.m_pParent->m_Value.m_nValue != 0 )
  {
    ++v5;
    ++this->m_nMaxClientsLimit;
  }
  if ( v5 < 1 )
  {
    v5 = defaultmaxplayers;
  }
  else
  {
    if ( v5 >= maxmaxplayers )
      v5 = maxmaxplayers;
    m_nMinClientsLimit = this->m_nMinClientsLimit;
    if ( m_nMinClientsLimit <= v5 )
      m_nMinClientsLimit = v5;
    this->m_nMaxClientsLimit = m_nMinClientsLimit;
  }
  m_nMaxClientsLimit = this->m_nMinClientsLimit;
  if ( v5 < m_nMaxClientsLimit || (m_nMaxClientsLimit = this->m_nMaxClientsLimit, v5 > m_nMaxClientsLimit) )
    v5 = m_nMaxClientsLimit;
  v8 = v5;
  if ( (CL_IsHL2Demo() || CL_IsPortalDemo()) && !this->IsDedicated(this) )
  {
    v8 = 1;
    this->m_nMinClientsLimit = 1;
    this->m_nMaxClientsLimit = 1;
  }
  this->SetMaxClients(this, a2: v8);
}

//------------------------------------------------------------------------------
// Address: 0x10124E40
// Name: void SV_InitGameDLL(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall SV_InitGameDLL(int a1@<esi>)
{
  const char *ModDirectory; // eax
  const char *v2; // eax
  int v3; // esi
  const char *v4; // eax
  CSteam3Client *v5; // eax
  CSteam3Client *v6; // eax
  const char *v7; // eax
  int v8; // eax
  ServerClass *v9; // eax
  double v10; // st7
  double v11; // st5
  int v12; // eax
  int v13; // eax
  int max_splitscreen_players; // eax
  const char *m_pchGameDir; // [esp+2Ch] [ebp-Ch]

  _COM_TimestampedLog(a1: "SV_InitGameDLL");
  Cbuf_Execute();
  if ( sv.dll_initialized )
    return;
  if ( CL_IsHL2Demo() && !sv.m_bIsDedicated )
  {
    ModDirectory = COM_GetModDirectory();
    if ( _V_stricmp(s1: ModDirectory, s2: "hl2") != 0 )
    {
      _Error(a1: "The HL2 demo is unable to run Mods.\n");
      return;
    }
  }
  if ( CL_IsPortalDemo() && !sv.m_bIsDedicated )
  {
    v2 = COM_GetModDirectory();
    if ( _V_stricmp(s1: v2, s2: "portal") != 0 )
    {
      _Error(a1: "The Portal demo is unable to run Mods.\n");
      return;
    }
  }
  if ( Steam3Client()->m_pSteamApps == nullptr
    || !g_pFileSystem->IsSteam(this: g_pFileSystem)
    || CL_IsHL2Demo()
    || CL_IsPortalDemo() )
  {
LABEL_22:
    if ( serverGameDLL == nullptr )
    {
      _Warning(a1: "Failed to load server binary\n");
      return;
    }
    sv.dll_initialized = true;
    _COM_TimestampedLog(a1: "serverGameDLL->DLLInit - Start");
    if ( ((int (__thiscall *)(IServerGameDLL *, void *(__cdecl *)(const char *, int *), void *(__cdecl *)(const char *, int *), void *(__cdecl *)(const char *, int *), CGlobalVars *, int))serverGameDLL->DLLInit)(
           a1: serverGameDLL,
           a2: g_GameSystemFactory,
           a3: g_AppSystemFactory,
           a4: g_AppSystemFactory,
           a5: &g_ServerGlobalVariables,
           a6: a1) == 0 )
      Sys_Error(error: "serverGameDLL->DLLInit() failed.\n");
    _COM_TimestampedLog(a1: "serverGameDLL->DLLInit - Finish");
    v8 = _CommandLine();
    if ( (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v8 + 40))(a1: v8, a2: "-NoLoadPluginsForClient") == 0 )
      CServerPlugin::LoadPlugins(this: g_pServerPluginHandler);
    Host_EnsureHostNameSet();
    sv_noclipduringpause = g_pCVar->FindVar_2(this: g_pCVar, a2: "sv_noclipduringpause");
    _COM_TimestampedLog(a1: "SV_InitSendTables");
    v9 = serverGameDLL->GetAllServerClasses(this: serverGameDLL);
    SV_InitSendTables(pClasses: v9);
    v10 = ((double (__thiscall *)(IServerGameDLL *))serverGameDLL->GetTickInterval)(a1: serverGameDLL);
    host_state.interval_per_tick = v10;
    v11 = 0.1;
    if ( v10 >= 0.001 )
    {
      if ( v10 <= 0.1 )
      {
LABEL_32:
        v12 = serverGameClients->GetMaxSplitscreenPlayers(this: serverGameClients);
        if ( v12 >= 1 )
        {
          if ( v12 > 2 )
            v12 = 2;
        }
        else
        {
          v12 = 1;
        }
        host_state.max_splitscreen_players_clientdll = v12;
        host_state.max_splitscreen_players = v12;
        v13 = _CommandLine();
        if ( (*(int (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v13 + 12))(a1: v13, a2: "-tools", a3: 0) != 0 )
        {
          _Msg(a1: "Clamping split screen users to 1 due to -tools mode\n");
          max_splitscreen_players = 1;
          host_state.max_splitscreen_players = 1;
        }
        else
        {
          max_splitscreen_players = host_state.max_splitscreen_players;
          if ( host_state.max_splitscreen_players > 1 )
          {
            _Msg(a1: "Game supporting (%d) split screen players\n", host_state.max_splitscreen_players);
            max_splitscreen_players = host_state.max_splitscreen_players;
          }
        }
        g_pCVar->SetMaxSplitScreenSlots(this: g_pCVar, a2: max_splitscreen_players);
        CGameServer::InitMaxClients(this: &sv);
        Cbuf_Execute();
        return;
      }
      v11 = 0.1;
    }
    Sys_Error(error: "GetTickInterval returned bogus tick interval (%f)[%f to %f is valid range]", v10, 0.001, v11);
    goto LABEL_32;
  }
  v3 = 0;
  while ( 1 )
  {
    m_pchGameDir = g_ModDirPermissions[v3].m_pchGameDir;
    v4 = COM_GetModDirectory();
    if ( _V_stricmp(s1: v4, s2: m_pchGameDir) == 0 )
      break;
    if ( (unsigned int)++v3 >= 0xB )
    {
      v5 = Steam3Client();
      if ( v5->m_pSteamApps->BIsSubscribedApp(this: v5->m_pSteamApps, a2: 215u) )
        goto LABEL_22;
      _Error(a1: "A Source engine game is required to run mods\n");
      return;
    }
  }
  v6 = Steam3Client();
  if ( v6->m_pSteamApps->BIsSubscribedApp(this: v6->m_pSteamApps, a2: g_ModDirPermissions[v3].m_iAppID) )
    goto LABEL_22;
  v7 = COM_GetModDirectory();
  _Error(a1: "No permissions to run '%s'\n", v7);
}

//------------------------------------------------------------------------------
// Address: 0x10125140
// Name: public: virtual bool CGameServer::IsPausable(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CGameServer::IsPausable(CGameServer *this)
{
  if ( CBaseServer::IsSinglePlayerGame(this)
    || !NET_IsDedicated()
    && sv_pausable_dev.m_pParent != nullptr
    && sv_pausable_dev.m_pParent->m_Value.m_nValue != 0
    && developer.m_pParent != nullptr
    && developer.m_pParent->m_Value.m_nValue != 0
    && CBaseServer::IsPlayingSoloAgainstBots(this)
    || NET_IsDedicated()
    && sv_pausable_dev_ds.m_pParent != nullptr
    && sv_pausable_dev_ds.m_pParent->m_Value.m_nValue != 0
    && developer.m_pParent != nullptr
    && developer.m_pParent->m_Value.m_nValue != 0
    && CBaseServer::IsPlayingSoloAgainstBots(this) )
  {
    return true;
  }
  if ( sv_pausable.m_pParent != nullptr )
    return sv_pausable.m_pParent->m_Value.m_nValue != 0;
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x101251E0
// Name: void SV_ExecuteRemoteCommand(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SV_ExecuteRemoteCommand(const char *pCommand, int nClientSlot)
{
  NET_StringCmd cmdMsg; // [esp+0h] [ebp-420h] BYREF
  CEngineSingleUserFilter filter; // [esp+414h] [ebp-Ch] BYREF

  if ( sv.m_State >= ss_active && sv.m_nMaxclients > 1 )
  {
    cmdMsg.m_szCommand = pCommand;
    cmdMsg.m_bReliable = true;
    cmdMsg.m_NetChannel = nullptr;
    cmdMsg.__vftable = (NET_StringCmd_vtbl *)&NET_StringCmd::`vftable';
    if ( nClientSlot < 0 )
    {
      CBaseServer::BroadcastMessage(this: &sv, msg: &cmdMsg, onlyActive: false, reliable: false);
    }
    else
    {
      filter.m_bReliable = true;
      filter.__vftable = (CEngineSingleUserFilter_vtbl *)&CEngineSingleUserFilter::`vftable';
      filter.m_nClientIndex = nClientSlot + 1;
      CBaseServer::BroadcastMessage(this: &sv, msg: &cmdMsg, &filter);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10125270
// Name: void SV_ResetPVS(unsigned char __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SV_ResetPVS(unsigned __int8 *pvs, int nPVSSize)
{
  int v2; // eax

  s_pFatPVS = pvs;
  v2 = (CM_NumClusters() + 7) >> 3;
  s_FatBytes = v2;
  if ( v2 > nPVSSize )
  {
    Sys_Error(error: "SV_ResetPVS:  Size %i too big for buffer %i\n", v2, nPVSSize);
    v2 = s_FatBytes;
  }
  _V_memset(dest: s_pFatPVS, fill: 0, count: v2);
  g_ClustersNetworked.m_Size = 0;
  g_AreasNetworked.m_Size = 0;
}

//------------------------------------------------------------------------------
// Address: 0x101252D0
// Name: private: void CGameServer::SetHibernating(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameServer::SetHibernating(CGameServer *this, bool bHibernating)
{
  const char *v3; // eax
  vgui::PropertyPage *v4; // ecx
  int i; // ebx
  CBaseClient *v6; // esi
  bool (__thiscall *IsFakeClient)(IClient *); // eax
  IClient *v8; // esi

  if ( this->m_bHibernating != bHibernating )
  {
    this->m_bHibernating = bHibernating;
    v3 = "Server is hibernating\n";
    if ( !bHibernating )
      v3 = "Server waking up from hibernation\n";
    _Msg(a1: v3);
    if ( this->m_bHibernating )
    {
      for ( i = 0; i < this->m_Clients.m_Size; ++i )
      {
        v6 = this->m_Clients.m_Memory.m_pMemory[i];
        IsFakeClient = v6->IsFakeClient;
        v8 = &v6->IClient;
        if ( IsFakeClient(this: v8) && v8->IsConnected(this: v8) && !v8->IsSplitScreenUser(this: v8) )
          v8->Disconnect(this: v8, a2: "Punting bot, server is hibernating");
      }
      if ( s_bExitWhenEmpty )
      {
        _Warning(a1: "Server shutting down because sv_shutdown was done and a game has ended.\n");
        HostState_Shutdown();
      }
      CColorBalanceUIPanel::Init(this: v4);
      CGameServer::ExecGameTypeCfg(this, mapname: this->m_szMapname);
      CBaseServer::SetReservationCookie(this, uiCookie: 0, pchReasonFormat: "SetHibernating(true)");
      this->m_flReservationExpiryTime = 0.0;
    }
    CBaseServer::UpdateGameType(this);
    Heartbeat_f();
    ((void (__stdcall *)(bool))serverGameDLL->ServerHibernationUpdate)(a1: this->m_bHibernating);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101253F0
// Name: public: void CGameServer::UpdateHibernationState(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameServer::UpdateHibernationState(CGameServer *this)
{
  int v2; // ebx
  CBaseClient *v3; // esi
  bool (__thiscall *IsConnected)(IClient *); // eax
  IClient *v5; // esi
  char v6; // bl
  int v7; // ecx
  float m_flReservationExpiryTime; // [esp+10h] [ebp-8h]
  char bHaveAnyClients; // [esp+17h] [ebp-1h]

  if ( this->IsDedicated(this) )
  {
    v2 = 0;
    bHaveAnyClients = 0;
    if ( this->m_Clients.m_Size > 0 )
    {
      while ( 1 )
      {
        v3 = this->m_Clients.m_Memory.m_pMemory[v2];
        IsConnected = v3->IsConnected;
        v5 = &v3->IClient;
        if ( IsConnected(this: v5) && (v5->IsSplitScreenUser(this: v5) || !v5->IsFakeClient(this: v5)) )
          break;
        if ( ++v2 >= this->m_Clients.m_Size )
          goto LABEL_9;
      }
      bHaveAnyClients = 1;
    }
LABEL_9:
    v6 = 0;
    if ( bHaveAnyClients != 0 )
    {
      this->m_flTimeLastClientLeft = -1.0;
    }
    else
    {
      v7 = HIDWORD(this->m_nReservationCookie) | LODWORD(this->m_nReservationCookie);
      if ( this->m_nReservationCookie != 0 )
      {
        if ( this->m_flTimeLastClientLeft == -1.0 )
          this->m_flTimeLastClientLeft = _Plat_FloatTime(a1: v7);
        if ( _Plat_FloatTime(a1: v7) - this->m_flTimeLastClientLeft > sv_hibernate_postgame_delay.m_pParent->m_Value.m_fValue )
          v6 = 1;
      }
    }
    if ( this->m_nReservationCookie != 0 && bHaveAnyClients == 0 && v6 != 0 )
    {
      m_flReservationExpiryTime = this->m_flReservationExpiryTime;
      if ( m_flReservationExpiryTime == 0.0 || net_time > m_flReservationExpiryTime )
        CBaseServer::SetReservationCookie(
          this,
          uiCookie: 0,
          pchReasonFormat: "reserved(%s), clients(%s), reservationexpires(%.2f)",
          "yes",
          "no",
          m_flReservationExpiryTime);
    }
    if ( sv_hibernate_when_empty.m_pParent != nullptr
      && sv_hibernate_when_empty.m_pParent->m_Value.m_nValue != 0
      && this->m_nReservationCookie == 0
      && bHaveAnyClients == (BYTE4(this->m_nReservationCookie) | LOBYTE(this->m_nReservationCookie)) )
    {
      CGameServer::SetHibernating(this, bHibernating: true);
    }
    else
    {
      CGameServer::SetHibernating(this, bHibernating: false);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10125580
// Name: public: virtual void CGameServer::SetMaxClients(int)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __thiscall CGameServer::SetMaxClients(CGameServer *this, int number)
{
  int m_nMinClientsLimit; // eax

  m_nMinClientsLimit = this->m_nMinClientsLimit;
  if ( number >= m_nMinClientsLimit )
  {
    m_nMinClientsLimit = this->m_nMaxClientsLimit;
    if ( number <= m_nMinClientsLimit )
      m_nMinClientsLimit = number;
  }
  this->m_nMaxclients = m_nMinClientsLimit;
  if ( tv_enable.m_pParent != nullptr && tv_enable.m_pParent->m_Value.m_nValue != 0 )
    ConMsg(a1: "maxplayers set to %i (extra slot was added for SourceTV)\n", m_nMinClientsLimit);
  else
    ConMsg(a1: "maxplayers set to %i\n", m_nMinClientsLimit);
  CLoaderMemAlloc::CrtIsValidPointer(this: (ConVar *)&deathmatch.IConVar, value: this->m_nMaxclients > 1);
}

//------------------------------------------------------------------------------
// Address: 0x101255F0
// Name: void SV_WriteVoiceCodec(class bf_write __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SV_WriteVoiceCodec(bf_write *pBuf)
{
  char *m_pszString; // eax
  SVC_VoiceInit voiceinit; // [esp+0h] [ebp-11Ch] BYREF

  if ( sv.m_nMaxclients <= 1 )
    goto LABEL_5;
  if ( (sv_voicecodec.m_nFlags & 0x1000) == 0 )
  {
    m_pszString = sv_voicecodec.m_pParent->m_Value.m_pszString;
    if ( m_pszString != nullptr )
      goto LABEL_6;
LABEL_5:
    m_pszString = (char *)defaultValue;
    goto LABEL_6;
  }
  m_pszString = "FCVAR_NEVER_AS_STRING";
LABEL_6:
  voiceinit.m_bReliable = true;
  voiceinit.m_NetChannel = nullptr;
  voiceinit.__vftable = (SVC_VoiceInit_vtbl *)&SVC_VoiceInit::`vftable';
  voiceinit.m_szVoiceCodec = m_pszString;
  voiceinit.m_nQuality = 5;
  SVC_VoiceInit::WriteToBuffer(this: &voiceinit, buffer: pBuf);
}

//------------------------------------------------------------------------------
// Address: 0x10125670
// Name: void OnTVEnablehanged(class IConVar __near *,char const __near *,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl OnTVEnablehanged(IConVar *pConVar)
{
  ConVarRef var; // [esp+0h] [ebp-8h] BYREF

  ConVarRef::ConVarRef(this: &var, pConVar);
  if ( var.m_pConVarState->m_Value.m_nValue != 0 )
    CGameServer::InitMaxClients(this: &sv);
}

//------------------------------------------------------------------------------
// Address: 0x101256A0
// Name: user
// Source: json
//------------------------------------------------------------------------------
void __cdecl user(const CCommand *args)
{
  int v1; // edi
  CBaseClient *v2; // eax
  int v3; // esi
  const char *v4; // eax
  const char *v5; // [esp-10h] [ebp-14h]
  int uid; // [esp+0h] [ebp-4h]

  if ( sv.m_State >= ss_active )
  {
    if ( args->m_nArgc == 2 )
    {
      v1 = 0;
      uid = atoi(nptr: args->m_ppArgv[1]);
      if ( sv.m_Clients.m_Size <= 0 )
      {
LABEL_13:
        ConMsg(a1: "User not in server.\n");
      }
      else
      {
        while ( 1 )
        {
          v2 = sv.m_Clients.m_Memory.m_pMemory[v1];
          v3 = v2 != nullptr ? (int)&v2->IClient : 0;
          if ( (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v3 + 124))(a1: v3) != 0 )
          {
            if ( (*(int (__thiscall **)(int))(*(_DWORD *)v3 + 56))(a1: v3) == uid )
              break;
            v5 = CCommand::operator[](this: args, nIndex: 1);
            v4 = (const char *)(*(int (__thiscall **)(int))(*(_DWORD *)v3 + 68))(a1: v3);
            if ( _V_strcmp(s1: v4, s2: v5) == 0 )
              break;
          }
          if ( ++v1 >= sv.m_Clients.m_Size )
            goto LABEL_13;
        }
        ConMsg(a1: "TODO: SV_User_f.\n");
      }
    }
    else
    {
      ConMsg(a1: "Usage: user <username / userid>\n");
    }
  }
  else
  {
    ConMsg(a1: "Can't 'user', not running a server\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x10125790
// Name: users
// Source: json
//------------------------------------------------------------------------------
void __cdecl users()
{
  int v0; // ebx
  int i; // edi
  CBaseClient *v2; // eax
  IClient *v3; // esi
  int v4; // eax
  int v5; // eax
  int v6; // eax
  int v7; // [esp-14h] [ebp-14h]
  const char *v8; // [esp-10h] [ebp-10h]

  if ( sv.m_State >= ss_active )
  {
    v0 = 0;
    ConMsg(a1: "<slot:userid:\"name\">\n");
    for ( i = 0; i < sv.m_Clients.m_Size; ++i )
    {
      v2 = sv.m_Clients.m_Memory.m_pMemory[i];
      if ( v2 != nullptr )
        v3 = &v2->IClient;
      else
        v3 = nullptr;
      if ( v3->IsConnected(this: v3) )
      {
        v4 = (int)v3->GetClientName(this: v3);
        v5 = ((int (__thiscall *)(IClient *, int))v3->GetUserID)(a1: v3, a2: v4);
        v6 = ((int (__thiscall *)(IClient *, int))v3->GetPlayerSlot)(a1: v3, a2: v5);
        ConMsg(a1: "%i:%i:\"%s\"\n", v6, v7, v8);
        ++v0;
      }
    }
    ConMsg(a1: "%i users\n", v0);
  }
  else
  {
    ConMsg(a1: "Can't 'users', not running a server\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x10125830
// Name: maxplayers
// Source: json
//------------------------------------------------------------------------------
void __cdecl maxplayers(int args)
{
  int MaxClients; // eax
  int v2; // eax
  int defaultmaxplayers; // [esp+0h] [ebp-8h] BYREF
  int maxmaxplayers; // [esp+4h] [ebp-4h] BYREF

  if ( *(_DWORD *)args == 2 )
  {
    if ( sv.m_State < ss_active )
    {
      v2 = V_atoi(str: *(const char **)(args + 1036));
      CGameServer::SetMaxClients(this: &sv, number: v2);
    }
    else
    {
      ConMsg(a1: "Cannot change maxplayers while the server is running\n");
    }
  }
  else
  {
    MaxClients = CBaseServer::GetMaxClients(this: &sv);
    ConMsg(a1: "\"maxplayers\" is \"%u\"\n", MaxClients);
    if ( serverGameClients != nullptr )
    {
      args = 1;
      maxmaxplayers = 1;
      defaultmaxplayers = 1;
      serverGameClients->GetPlayerLimits(this: serverGameClients, a2: &args, a3: &maxmaxplayers, a4: &defaultmaxplayers);
      ConMsg(a1: "\"mininum_maxplayers\" is \"%u\"\n", args);
      ConMsg(a1: "\"absolute_maxplayers\" is \"%u\"\n", maxmaxplayers);
      ConMsg(a1: "\"default_maxplayers\" is \"%u\"\n", defaultmaxplayers);
      if ( toolframework->InToolMode(this: toolframework) )
        ConMsg(
          a1: "\"max_splitscreen_players\" is \"%u\" (limited by -tools mode)\n",
          host_state.max_splitscreen_players);
      else
        ConMsg(a1: "\"max_splitscreen_players\" is \"%u\"\n", host_state.max_splitscreen_players);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10125930
// Name: public: virtual void CGameServer::Init(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameServer::Init(CGameServer *this, bool isDedicated)
{
  CBaseServer::Init(this, bIsDedicated: isDedicated);
  CNetworkStringTable::SetTick(this: &this->m_FullSendTables, pDebugName: "m_FullSendTables");
  this->dll_initialized = false;
  if ( isDedicated )
    CGameServer::UpdateHibernationState(this);
}

//------------------------------------------------------------------------------
// Address: 0x10125970
// Name: void SV_DetermineMulticastRecipients(bool,class Vector const __near &,class CBitVec<64> __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SV_DetermineMulticastRecipients(bool usepas, const Vector *origin, CBitVec<64> *playerbits)
{
  int v3; // eax
  int v4; // eax
  int v5; // edi
  CBaseClient *v6; // esi
  _DWORD *v7; // eax
  int v8; // eax
  int v9; // eax
  int v10; // eax
  unsigned __int8 dest[8192]; // [esp+8h] [ebp-200Ch] BYREF
  Vector v12; // [esp+2008h] [ebp-Ch] BYREF
  const unsigned __int8 *v13; // [esp+201Ch] [ebp+8h]

  v3 = CM_PointLeafnum(p: origin);
  v4 = CM_LeafCluster(leafnum: v3);
  v13 = CM_Vis(dest, destlen: 0x2000, cluster: v4, visType: usepas);
  if ( playerbits != nullptr )
  {
    playerbits->m_Ints[0] = 0;
    playerbits->m_Ints[1] = 0;
  }
  v5 = 0;
  if ( sv.m_Clients.m_Size > 0 )
  {
    while ( 1 )
    {
      v6 = sv.m_Clients.m_Memory.m_pMemory[v5];
      if ( v6->IsActive(this: &v6->IClient) )
      {
        v7 = *(_DWORD **)v6[1].m_GUID;
        if ( v7 == nullptr || (*v7 & 2) != 0 || v7[3] == 0 )
          goto LABEL_13;
        if ( v6->IsHLTV(this: &v6->IClient) )
          break;
        serverGameClients->ClientEarPosition(this: serverGameClients, a2: *(edict_t **)v6[1].m_GUID, a3: &v12);
        v8 = CM_PointLeafnum(p: &v12);
        v9 = CM_LeafCluster(leafnum: v8);
        if ( ((unsigned __int8)(1 << (v9 & 7)) & v13[v9 >> 3]) != 0 )
        {
          if ( !v6->IsSplitScreenUser(this: &v6->IClient) )
            break;
          v10 = v6->m_pAttachedTo->GetPlayerSlot(this: &v6->m_pAttachedTo->IClient);
          playerbits->m_Ints[v10 >> 5] |= 1 << (v10 & 0x1F);
        }
      }
LABEL_13:
      if ( ++v5 >= sv.m_Clients.m_Size )
        return;
    }
    playerbits->m_Ints[v5 >> 5] |= 1 << (v5 & 0x1F);
    goto LABEL_13;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10125AD0
// Name: protected: virtual bool CGameServer::FinishCertificateCheck(struct netadr_s __near &,int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CGameServer::FinishCertificateCheck(
        CGameServer *this,
        netadr_s *adr,
        int nAuthProtocol,
        const char *szRawCertificate)
{
  int v6; // ebx
  CBaseClient *v7; // edi
  int nHashCount; // [esp+10h] [ebp+Ch]

  if ( nAuthProtocol == 2 )
  {
    if ( !UseCDKeyAuth() )
    {
      this->RejectConnection(this, a2: adr, a3: "#Valve_Reject_CD_Key_Auth_Invalid");
      return 0;
    }
    if ( _V_strlen(str: szRawCertificate) == 32 )
    {
      v6 = 0;
      nHashCount = 0;
      if ( this->GetClientCount(this) <= 0 )
        return 1;
      do
      {
        v7 = this->m_Clients.m_Memory.m_pMemory[v6];
        if ( v7->IsConnected(this: &v7->IClient) && V_strnicmp(s1: szRawCertificate, s2: v7->m_GUID, n: 32) == 0 )
          ++nHashCount;
        ++v6;
      }
      while ( v6 < this->GetClientCount(this) );
      if ( nHashCount < 5 )
      {
        return 1;
      }
      else
      {
        this->RejectConnection(this, a2: adr, a3: "#Valve_Reject_CD_Key_In_Use");
        return 0;
      }
    }
    else
    {
      this->RejectConnection(this, a2: adr, a3: "#Valve_Reject_Invalid_CD_Key");
      return 0;
    }
  }
  else
  {
    if ( nAuthProtocol != 3 )
    {
      this->RejectConnection(this, a2: adr, a3: "Authentication disabled!!!\n");
      return 0;
    }
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10125BD0
// Name: public: void CGameServer::BroadcastSound(struct SoundInfo_t __near &,class IRecipientFilter __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameServer::BroadcastSound(CGameServer *this, SoundInfo_t *sound, IRecipientFilter *filter)
{
  CGameServer *v4; // edi
  int v5; // esi
  int v6; // esi
  CGameClient *v7; // esi
  bool v8; // al
  const char *v9; // edi
  bool v10; // zf
  const char *v11; // eax
  int num; // [esp+10h] [ebp-4h]
  int i; // [esp+20h] [ebp+Ch]

  v4 = this;
  v5 = filter->GetRecipientCount(this: filter);
  num = v5;
  if ( !v4->IsPaused(this: v4) || developer.m_pParent != nullptr && developer.m_pParent->m_Value.m_nValue != 0 )
  {
    i = 0;
    if ( v5 > 0 )
    {
      do
      {
        v6 = filter->GetRecipientIndex(this: filter, a2: i);
        if ( v6 < 1 || v6 > v4->GetClientCount(this: v4) )
        {
          v9 = "yes";
          if ( !filter->IsInitMessage(this: filter) )
            v9 = "no";
          v10 = !filter->IsReliable(this: filter);
          v11 = "yes";
          if ( v10 )
            v11 = "no";
          _Msg(
            a1: "CGameServer::BroadcastSound:  Recipient Filter for sound (reliable: %s, init: %s) with bogus client index (%"
            "i) in list of %i clients\n",
            v11,
            v9,
            v6,
            num);
          v4 = this;
        }
        else
        {
          v7 = (CGameClient *)v4->m_Clients.m_Memory.m_pMemory[v6 - 1];
          if ( v7->IsActive(this: &v7->IClient) )
          {
            v8 = filter->IsReliable(this: filter);
            CGameClient::SendSound(this: v7, sound, isReliable: v8);
          }
        }
        ++i;
      }
      while ( i < num );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10125CE0
// Name: void OnHibernateWhenEmptyChanged(class IConVar __near *,char const __near *,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl OnHibernateWhenEmptyChanged()
{
  CGameServer::UpdateHibernationState(this: &sv);
}

//------------------------------------------------------------------------------
// Address: 0x10125CF0
// Name: void SV_BroadcastVoiceData(class IClient __near *,int,char __near *,__int64)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SV_BroadcastVoiceData(IClient *cl, int nBytes, char *data, unsigned __int64 xuid)
{
  int (__thiscall *GetPlayerSlot)(IClient *); // eax
  int v5; // eax
  const char *v6; // eax
  CBaseClient *v7; // eax
  CBaseClient *v8; // ebx
  IClient *v9; // eax
  bool (__thiscall *IsActive)(IClient *); // edx
  IClient *v11; // esi
  int v12; // eax
  INetChannel *v13; // eax
  int m_nSignonState; // ebx
  int v15; // eax
  const char *v16; // eax
  CBaseClient *v17; // ebx
  bool v18; // al
  bool v19; // al
  int v20; // eax
  INetChannel *v21; // eax
  char *v22; // ebx
  int v23; // eax
  const char *v24; // eax
  int v25; // eax
  INetChannel *v26; // eax
  char *v27; // ebx
  int v28; // eax
  const char *v29; // eax
  const char *v30; // [esp-18h] [ebp-90h]
  const char *v31; // [esp-14h] [ebp-8Ch]
  const char *v32; // [esp-14h] [ebp-8Ch]
  const char *v33; // [esp-14h] [ebp-8Ch]
  const char *v34; // [esp-10h] [ebp-88h]
  const char *v35; // [esp-10h] [ebp-88h]
  const char *v36; // [esp-10h] [ebp-88h]
  const char *v37; // [esp-Ch] [ebp-84h]
  const char *v38; // [esp-Ch] [ebp-84h]
  const char *v39; // [esp-Ch] [ebp-84h]
  int v40; // [esp-8h] [ebp-80h]
  SVC_VoiceData voiceData; // [esp+4h] [ebp-74h] BYREF
  ConVarRef voice_verbose; // [esp+5Ch] [ebp-1Ch] BYREF
  int v43; // [esp+64h] [ebp-14h]
  char *v44; // [esp+68h] [ebp-10h]
  char *v45; // [esp+6Ch] [ebp-Ch]
  int i; // [esp+70h] [ebp-8h]
  bool bSelf; // [esp+76h] [ebp-2h]
  bool bHearsPlayer; // [esp+77h] [ebp-1h]

  ConVarRef::ConVarRef(this: &voice_verbose, pName: "voice_verbose");
  if ( sv_voiceenable.m_pParent != nullptr && sv_voiceenable.m_pParent->m_Value.m_nValue != 0 )
  {
    GetPlayerSlot = cl->GetPlayerSlot;
    voiceData.m_NetChannel = nullptr;
    voiceData.__vftable = (SVC_VoiceData_vtbl *)&SVC_VoiceData::`vftable';
    voiceData.m_DataIn.m_bOverflow = false;
    voiceData.m_DataIn.m_pDebugName = nullptr;
    voiceData.m_DataIn.m_nDataBits = -1;
    voiceData.m_DataIn.m_nDataBytes = 0;
    voiceData.m_bReliable = false;
    voiceData.m_nFromClient = GetPlayerSlot(this: cl);
    v43 = 8 * nBytes;
    voiceData.m_nLength = 8 * nBytes;
    voiceData.m_DataOut = data;
    voiceData.m_xuid = xuid;
    if ( voice_debugfeedbackfrom.m_pParent != nullptr && voice_debugfeedbackfrom.m_pParent->m_Value.m_nValue != 0 )
    {
      v5 = cl->GetPlayerSlot(this: cl);
      v6 = (const char *)((int (__thiscall *)(IClient *, int))cl->GetClientName)(a1: cl, a2: v5 + 1);
      _Msg(a1: "Sending voice from: %s - playerslot: %d\n", v6, v40);
    }
    for ( i = 0; i < sv.m_Clients.m_Size; ++i )
    {
      v7 = sv.m_Clients.m_Memory.m_pMemory[i];
      if ( v7 == nullptr || v7 == (CBaseClient *)-4 )
      {
        v8 = nullptr;
        v9 = nullptr;
      }
      else
      {
        v8 = sv.m_Clients.m_Memory.m_pMemory[i];
        v9 = &v7->IClient;
      }
      IsActive = v8->IsActive;
      v11 = &v8->IClient;
      bSelf = v9 == cl;
      if ( IsActive(this: &v8->IClient) )
      {
        if ( !v11->IsSplitScreenUser(this: &v8->IClient) )
        {
          bHearsPlayer = v11->IsHearingClient(this: &v8->IClient, a2: voiceData.m_nFromClient);
          voiceData.m_bAudible[0] = bHearsPlayer;
          voiceData.m_bProximity = v11->IsProximityHearingClient(this: &v8->IClient, a2: voiceData.m_nFromClient);
          voiceData.m_bAudible[1] = true;
          v17 = v8->m_SplitScreenUsers[1];
          if ( v17 != nullptr )
          {
            v18 = v17->IsHearingClient(this: &v17->IClient, a2: voiceData.m_nFromClient);
            bHearsPlayer |= v18;
            voiceData.m_bAudible[1] = v18;
            v19 = v17->IsProximityHearingClient(this: &v17->IClient, a2: voiceData.m_nFromClient);
            voiceData.m_bProximity |= v19;
          }
          if ( bHearsPlayer || bSelf )
          {
            voiceData.m_nLength = v43;
            if ( !bHearsPlayer )
              voiceData.m_nLength = 0;
            if ( voice_verbose.m_pConVarState->m_Value.m_nValue != 0 )
            {
              v44 = "true";
              if ( !voiceData.m_bProximity )
                v44 = "false";
              if ( v11->GetNetChannel(this: v11) != nullptr )
              {
                v25 = (int)v11->GetNetChannel(this: v11);
                v45 = (char *)(*(int (__thiscall **)(int))(*(_DWORD *)v25 + 4))(a1: v25);
              }
              else
              {
                v45 = &args.m_pArgvBuffer[228];
              }
              if ( cl->GetNetChannel(this: cl) != nullptr )
              {
                v26 = cl->GetNetChannel(this: cl);
                v27 = (char *)v26->GetAddress(this: v26);
              }
              else
              {
                v27 = &args.m_pArgvBuffer[228];
              }
              v28 = ((int (__thiscall *)(IClient *, char *, char *))v11->GetClientName)(a1: v11, a2: v45, a3: v44);
              v29 = (const char *)((int (__thiscall *)(IClient *, char *, int))cl->GetClientName)(
                                    a1: cl,
                                    a2: v27,
                                    a3: v28);
              _Msg(
                a1: "* SV_BroadcastVoiceData: Sending %d bits (%d bytes) from %s (%s) to %s (%s).  Proximity %s.\n",
                voiceData.m_nLength,
                (voiceData.m_nLength + 7) >> 3,
                v29,
                v30,
                v33,
                v36,
                v39);
            }
            v11->SendNetMsg(this: v11, a2: &voiceData, a3: false, a4: true);
          }
          else if ( voice_verbose.m_pConVarState->m_Value.m_nValue != 0 )
          {
            if ( v11->GetNetChannel(this: v11) != nullptr )
            {
              v20 = (int)v11->GetNetChannel(this: v11);
              v44 = (char *)(*(int (__thiscall **)(int))(*(_DWORD *)v20 + 4))(a1: v20);
            }
            else
            {
              v44 = &args.m_pArgvBuffer[228];
            }
            if ( cl->GetNetChannel(this: cl) != nullptr )
            {
              v21 = cl->GetNetChannel(this: cl);
              v22 = (char *)v21->GetAddress(this: v21);
            }
            else
            {
              v22 = &args.m_pArgvBuffer[228];
            }
            v23 = ((int (__thiscall *)(IClient *, char *))v11->GetClientName)(a1: v11, a2: v44);
            v24 = (const char *)((int (__thiscall *)(IClient *, char *, int))cl->GetClientName)(
                                  a1: cl,
                                  a2: v22,
                                  a3: v23);
            _Msg(
              a1: "* SV_BroadcastVoiceData:  Doesn't hear player.  Dropping %d bytes from %s (%s) to %s (%s)\n",
              voiceData.m_nLength,
              v24,
              v32,
              v35,
              v38);
          }
        }
      }
      else if ( voice_verbose.m_pConVarState->m_Value.m_nValue != 0 )
      {
        if ( v11->GetNetChannel(this: &v8->IClient) != nullptr )
        {
          v12 = (int)v11->GetNetChannel(this: &v8->IClient);
          v45 = (char *)(*(int (__thiscall **)(int))(*(_DWORD *)v12 + 4))(a1: v12);
        }
        else
        {
          v45 = &args.m_pArgvBuffer[228];
        }
        if ( cl->GetNetChannel(this: cl) != nullptr )
        {
          v13 = cl->GetNetChannel(this: cl);
          v44 = (char *)v13->GetAddress(this: v13);
        }
        else
        {
          v44 = &args.m_pArgvBuffer[228];
        }
        m_nSignonState = v8->m_nSignonState;
        v15 = ((int (__thiscall *)(IClient *, char *))v11->GetClientName)(a1: v11, a2: v45);
        v16 = (const char *)((int (__thiscall *)(IClient *, char *, int))cl->GetClientName)(a1: cl, a2: v44, a3: v15);
        _Msg(
          a1: "* SV_BroadcastVoiceData:  Not active (SignonState %d).  Dropping %d bytes from %s (%s) to %s (%s)\n",
          m_nSignonState,
          voiceData.m_nLength,
          v16,
          v31,
          v34,
          v37);
      }
    }
  }
  else if ( voice_verbose.m_pConVarState->m_Value.m_nValue != 0 )
  {
    _Msg(a1: "* SV_BroadcastVoiceData:  Dropping all voice.  sv_voiceenable is not set.\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x101260C0
// Name: void SV_CreateBaseline(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SV_CreateBaseline()
{
  ServerClass *v0; // esi
  int v1; // edi
  unsigned __int8 *v2; // eax
  edict_t *edicts; // eax
  int v4; // ebx
  bool v5; // zf
  int v6; // ecx
  int v7; // eax
  ServerClass *v8; // esi
  const SendTable *v9; // ebx
  _BYTE v10[96000]; // [esp+Ch] [ebp-1B77Ch] BYREF
  _BYTE pData[16384]; // [esp+1770Ch] [ebp-407Ch] BYREF
  SVC_GameEventList msg; // [esp+1B70Ch] [ebp-7Ch] BYREF
  bf_write pOut; // [esp+1B760h] [ebp-28h] BYREF
  const void **v14; // [esp+1B778h] [ebp-10h]
  int v15; // [esp+1B77Ch] [ebp-Ch]
  int v16; // [esp+1B780h] [ebp-8h]
  int v17; // [esp+1B784h] [ebp-4h]

  SV_WriteVoiceCodec(pBuf: &sv.m_Signon);
  v0 = serverGameDLL->GetAllServerClasses(this: serverGameDLL);
  v1 = 0;
  if ( sv_sendtables.m_pParent == nullptr || sv_sendtables.m_pParent->m_Value.m_nValue == 0 )
    goto LABEL_13;
  if ( sv.m_FullSendTablesBuffer.m_nAllocationCount < 96000 && sv.m_FullSendTablesBuffer.m_nGrowSize >= 0 )
  {
    sv.m_FullSendTablesBuffer.m_nAllocationCount = 96000;
    if ( sv.m_FullSendTablesBuffer.m_pMemory != nullptr )
      v2 = (unsigned __int8 *)_g_pMemAlloc->Realloc_2(
                                this: _g_pMemAlloc,
                                a2: sv.m_FullSendTablesBuffer.m_pMemory,
                                a3: 96000);
    else
      v2 = (unsigned __int8 *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 96000);
    sv.m_FullSendTablesBuffer.m_pMemory = v2;
  }
  bf_write::StartWriting(
    this: &sv.m_FullSendTables,
    pData: sv.m_FullSendTablesBuffer.m_pMemory,
    nBytes: sv.m_FullSendTablesBuffer.m_nAllocationCount,
    iStartBit: 0,
    nBits: -1);
  SV_WriteSendTables(pClasses: v0, pBuf: &sv.m_FullSendTables);
  if ( sv.m_FullSendTables.m_bOverflow )
  {
    Host_Error(error: "SV_CreateBaseline: WriteSendTables overflow.\n");
    return;
  }
  SV_WriteClassInfos(pClasses: v0, pBuf: &sv.m_FullSendTables);
  if ( sv.m_FullSendTables.m_bOverflow )
  {
    Host_Error(error: "SV_CreateBaseline: WriteClassInfos overflow.\n");
  }
  else
  {
LABEL_13:
    if ( g_pLocalNetworkBackdoor == nullptr )
    {
      v17 = 0;
      v16 = 0;
      if ( sv.num_edicts > 0 )
      {
        edicts = sv.edicts;
        v4 = 0;
        v15 = 0;
        do
        {
          if ( (*(int *)((_BYTE *)&edicts->m_fStateFlags + v4) & 2) == 0 )
          {
            v5 = *(IServerUnknown **)((char *)&edicts->m_pUnk + v4) == nullptr;
            v14 = (const void **)((char *)&edicts->m_pUnk + v4);
            if ( !v5 )
            {
              v6 = *(int *)((char *)&edicts->m_pNetworkable + v4);
              if ( v6 != 0 )
              {
                v7 = (*(int (__thiscall **)(int))(*(_DWORD *)v6 + 4))(a1: v6);
                v8 = (ServerClass *)v7;
                if ( v7 != 0 && *(_DWORD *)(v7 + 16) == 0xFFFF )
                {
                  v9 = *(const SendTable **)(v7 + 4);
                  bf_write::bf_write(
                    this: &pOut,
                    pDebugName: "SV_CreateBaseline->writeBuf",
                    pData,
                    nBytes: 0x4000,
                    nBits: -1);
                  if ( !SendTable_Encode(
                          pTable: v9,
                          pStruct: *v14,
                          &pOut,
                          objectID: v1,
                          pRecipients: nullptr,
                          bNonZeroOnly: false) )
                    Host_Error(error: "SV_CreateBaseline: SendTable_Encode returned false (ent %d).\n", v1);
                  SV_EnsureInstanceBaseline(pServerClass: v8, iEdict: v1, pData, nBytes: (pOut.m_iCurBit + 7) >> 3);
                  v4 = v15;
                  v16 += (pOut.m_iCurBit + 7) >> 3;
                  ++v17;
                }
                edicts = sv.edicts;
              }
            }
          }
          ++v1;
          v4 += 16;
          v15 = v4;
        }
        while ( v1 < sv.num_edicts );
      }
      DevMsg(a1: "Created class baseline: %i classes, %i bytes.\n", v17, v16);
    }
    CGameEventManager::ReloadEventDefinitions(this: g_GameEventManager);
    msg.m_bReliable = true;
    msg.m_NetChannel = nullptr;
    msg.__vftable = (SVC_GameEventList_vtbl *)&SVC_GameEventList::`vftable';
    msg.m_DataIn.m_bOverflow = false;
    msg.m_DataIn.m_pDebugName = nullptr;
    msg.m_DataIn.m_nDataBits = -1;
    msg.m_DataIn.m_nDataBytes = 0;
    bf_write::bf_write(this: &msg.m_DataOut);
    bf_write::StartWriting(this: &msg.m_DataOut, pData: v10, nBytes: 96000, iStartBit: 0, nBits: -1);
    CGameEventManager::WriteEventList(this: g_GameEventManager, &msg);
    SVC_GameEventList::WriteToBuffer(this: &msg, buffer: &sv.m_Signon);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10126340
// Name: bool SV_ActivateServer(void)
// Source: json
//------------------------------------------------------------------------------
char __cdecl SV_ActivateServer()
{
  IEngineVGuiInternal *v0; // eax
  bool v1; // al
  CServerPlugin_vtbl *v2; // esi
  int MaxClients; // eax
  ConVar *v4; // eax
  const char *m_pszString; // eax
  int v6; // eax
  int v7; // eax
  CHLTVServer *v8; // eax
  CHLTVServer *v9; // eax
  CBaseServer_vtbl *v10; // esi
  bool IsDedicated; // al
  CSteam3Server *v12; // eax
  CGameClient *FakeClient; // eax
  CSteam3Server *v14; // eax
  CSteam3Server *v15; // eax
  CSteam3Server *v16; // eax
  CSteam3Server *v18; // eax
  unsigned __int16 UDPPort; // [esp-4h] [ebp-14h]
  BOOL bPrevState; // [esp+8h] [ebp-8h]
  int m_QueryPort; // [esp+Ch] [ebp-4h] BYREF

  _COM_TimestampedLog(a1: "SV_ActivateServer");
  v0 = EngineVGui();
  v0->UpdateProgressBar(this: v0, a2: PROGRESS_ACTIVATESERVER, a3: true);
  _COM_TimestampedLog(a1: "serverGameDLL->ServerActivate");
  v1 = CNetworkStringTableContainer::Lock(this: networkStringTableContainerServer, bLock: false);
  v2 = g_pServerPluginHandler->__vftable;
  LOBYTE(bPrevState) = v1;
  MaxClients = CBaseServer::GetMaxClients(this: &sv);
  v2->ServerActivate(this: g_pServerPluginHandler, a2: sv.edicts, a3: sv.num_edicts, a4: MaxClients);
  sv.m_State = ss_active;
  _COM_TimestampedLog(a1: "SV_CreateBaseline");
  SV_CreateBaseline();
  sv.allowsignonwrites = false;
  v4 = g_pCVar->FindVar_2(this: g_pCVar, a2: "sv_skyname");
  if ( v4 != nullptr )
  {
    if ( (v4->m_nFlags & 0x1000) != 0 )
    {
      V_strncpy(pDest: sv.m_szSkyname, pSrc: "FCVAR_NEVER_AS_STRING", maxLen: 64);
    }
    else
    {
      m_pszString = v4->m_pParent->m_Value.m_pszString;
      if ( m_pszString == nullptr )
        m_pszString = defaultValue;
      V_strncpy(pDest: sv.m_szSkyname, pSrc: m_pszString, maxLen: 64);
    }
  }
  else
  {
    V_strncpy(pDest: sv.m_szSkyname, pSrc: "unknown", maxLen: 64);
  }
  _COM_TimestampedLog(a1: "Send Reconnects");
  CBaseServer::ReconnectClients(this: &sv);
  if ( sv.m_nMaxclients <= 1 )
  {
    _ConDMsg(a1: "Game started\n");
  }
  else
  {
    v6 = CBaseServer::GetMaxClients(this: &sv);
    _ConDMsg(a1: "%i player server started\n", v6);
  }
  if ( tv_enable.m_pParent != nullptr && tv_enable.m_pParent->m_Value.m_nValue != 0 )
  {
    v7 = _CommandLine();
    if ( (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v7 + 40))(a1: v7, a2: "-nohltv") != 0 )
    {
      ConMsg(a1: "SourceTV is disabled on this server.\n");
    }
    else
    {
      if ( hltv == nullptr )
      {
        v8 = (CHLTVServer *)MemAlloc_Alloc(nSize: 0x89C0u);
        if ( v8 != nullptr )
          v9 = CHLTVServer::CHLTVServer(this: v8);
        else
          v9 = nullptr;
        hltv = v9;
        v10 = v9->CBaseServer::IServer::IConnectionlessPacketHandler::__vftable;
        IsDedicated = NET_IsDedicated();
        v10->Init(this: &hltv->CBaseServer, a2: IsDedicated);
      }
      UDPPort = NET_GetUDPPort(socket: 2);
      v12 = Steam3Server();
      CSteam3Server::UpdateSpectatorPort(this: v12, unSpectatorPort: UDPPort);
      if ( hltv->IsActive(this: &hltv->CBaseServer) && hltv->IsMasterProxy(this: &hltv->IHLTVServer) )
      {
        hltv->m_MasterClient->ActivatePlayer(this: hltv->m_MasterClient);
        CHLTVServer::StartMaster(this: hltv, client: hltv->m_MasterClient);
      }
      else
      {
        FakeClient = (CGameClient *)CBaseServer::CreateFakeClient(this: &sv, name: "SourceTV");
        CHLTVServer::StartMaster(this: hltv, client: FakeClient);
      }
    }
  }
  else
  {
    v14 = Steam3Server();
    CSteam3Server::UpdateSpectatorPort(this: v14, unSpectatorPort: 0);
    if ( hltv != nullptr )
      hltv->Shutdown(this: &hltv->CBaseServer);
  }
  if ( sv.m_bIsDedicated )
    modelloader->PurgeUnusedModels(this: modelloader);
  if ( sv.m_nMaxclients > 1 || serverGameDLL->ShouldPreferSteamAuth(this: serverGameDLL) )
  {
    v15 = Steam3Server();
    CSteam3Server::Activate(this: v15);
    if ( sv.m_pServerStartupTable != nullptr )
    {
      m_QueryPort = Steam3Server()->m_QueryPort;
      sv.m_pServerStartupTable->AddString(
        this: sv.m_pServerStartupTable,
        a2: true,
        a3: "QueryPort",
        a4: 4,
        a5: &m_QueryPort);
    }
    if ( serverGameDLL != nullptr )
      serverGameDLL->GameServerSteamAPIActivated(this: serverGameDLL);
  }
  CNetworkStringTableContainer::Lock(this: networkStringTableContainerServer, bLock: bPrevState);
  v16 = Steam3Server();
  CSteam3Server::SendUpdatedServerDetails(this: v16);
  if ( IsUsingMasterLegacyMode() )
  {
    g_pMaster->Heartbeat_Legacy_f(this: g_pMaster);
  }
  else
  {
    v18 = Steam3Server();
    v18->m_pSteamMasterServerUpdater->ForceHeartbeat(this: v18->m_pSteamMasterServerUpdater);
  }
  _COM_TimestampedLog(a1: "SV_ActivateServer(finished)");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10126690
// Name: public: bool CGameServer::SpawnServer(char __near *,char __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CGameServer::SpawnServer(CGameServer *this, char *mapname, char *startspot)
{
  int v4; // eax
  void (*v5)(const char *, ...); // ebx
  IEngineVGuiInternal *v6; // eax
  bool v7; // al
  int v8; // eax
  CStaticPropMgr *v9; // eax
  int v10; // edi
  int v11; // eax
  double v12; // st7
  int v13; // eax
  int v14; // eax
  model_t *v15; // eax
  IEngineVGuiInternal *v17; // eax
  IEngineVGuiInternal *v18; // eax
  IEngineVGuiInternal *v19; // eax
  IEngineVGuiInternal *v20; // eax
  int i; // edi
  model_t *v22; // eax
  IEngineVGuiInternal *v23; // eax
  int m_nValue; // eax
  bool v25; // zf
  char *m_szMapname; // eax
  char *m_szStartspot; // eax
  IGameEvent *v28; // edi
  char *m_pszString; // eax
  IGameEvent_vtbl *v30; // ebx
  const char *v31; // eax
  IGameEvent_vtbl *v32; // ebx
  int v33; // eax
  IGameEvent_vtbl *v34; // ebx
  const char *v35; // eax
  IGameEvent_vtbl *v36; // ebx
  int v37; // eax
  IGameEvent_vtbl *v38; // ebx
  bool v39; // al
  edict_t *v40; // [esp+4h] [ebp-278h]
  char szNameOnDisk[260]; // [esp+Ch] [ebp-270h] BYREF
  char szModelName[260]; // [esp+110h] [ebp-16Ch] BYREF
  char szDllName[96]; // [esp+214h] [ebp-68h] BYREF
  char localmodel[8]; // [esp+274h] [ebp-8h] BYREF
  int flStartTimeOverride; // [esp+288h] [ebp+Ch]
  float flStartTimeOverridea; // [esp+288h] [ebp+Ch]

  v4 = _CommandLine();
  if ( (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v4 + 40))(a1: v4, a2: "-NoLoadPluginsForClient") != 0
    && !this->m_bLoadedPlugins )
  {
    this->m_bLoadedPlugins = true;
    CServerPlugin::LoadPlugins(this: g_pServerPluginHandler);
  }
  if ( this->IsDedicated(this) )
    CLoaderMemAlloc::CrtIsValidPointer(this: (ConVar *)&fps_max.IConVar, value: 30);
  CGameServer::ReloadWhitelist(this, pMapName: mapname);
  v5 = (void (*)(const char *, ...))_COM_TimestampedLog;
  _COM_TimestampedLog(a1: "SV_SpawnServer(%s)", mapname);
  v6 = EngineVGui();
  v6->UpdateProgressBar(this: v6, a2: PROGRESS_SPAWNSERVER, a3: true);
  COM_SetupLogDir(mapname);
  CLog::Open(this: &g_Log);
  CLog::Printf(this: &g_Log, fmt: "Loading map \"%s\"\n", mapname);
  CLog::PrintServerVars(this: &g_Log);
  if ( startspot != nullptr )
    _ConDMsg(a1: "Spawn Server: %s: [%s]\n", mapname, startspot);
  else
    _ConDMsg(a1: "Spawn Server: %s\n", mapname);
  gHostSpawnCount = ++this->m_nSpawnCount;
  v7 = this->IsMultiplayer(this);
  CLoaderMemAlloc::CrtIsValidPointer(this: (ConVar *)&deathmatch.IConVar, value: v7);
  if ( coop.m_pParent != nullptr && coop.m_pParent->m_Value.m_nValue != 0 )
    CLoaderMemAlloc::CrtIsValidPointer(this: (ConVar *)&deathmatch.IConVar, value: 0);
  v8 = current_skill <= 0 ? 0 : current_skill;
  current_skill = v8;
  if ( v8 >= 3 )
  {
    v8 = 3;
    current_skill = 3;
  }
  ConVar::SetValue(this: (ConVar *)&skill.IConVar, value: (float)v8);
  _COM_TimestampedLog(a1: "StaticPropMgr()->LevelShutdown()");
  g_pShadowMgr->LevelShutdown(this: g_pShadowMgr);
  v9 = StaticPropMgr();
  v9->LevelShutdown(this: v9);
  if ( hltv != nullptr && !hltv->IsMasterProxy(this: &hltv->IHLTVServer) )
    hltv->Shutdown(this: &hltv->CBaseServer);
  _COM_TimestampedLog(a1: "Host_FreeToLowMark");
  Host_FreeStateAndWorld(server: true);
  Host_FreeToLowMark(server: true);
  g_ServerGlobalVariables.mapversion = 0;
  _COM_TimestampedLog(a1: "sv.Clear()");
  this->Clear(this);
  _COM_TimestampedLog(a1: "framesnapshotmanager->LevelChanged()");
  framesnapshotmanager->LevelChanged(this: framesnapshotmanager);
  V_strncpy(pDest: this->m_szMapname, pSrc: mapname, maxLen: 64);
  v10 = 0;
  if ( startspot != nullptr )
    V_strncpy(pDest: this->m_szStartspot, pSrc: startspot, maxLen: 64);
  else
    this->m_szStartspot[0] = 0;
  SV_FlushMemoryIfMarked();
  g_pFileSystem->SetupPreloadData(this: g_pFileSystem);
  g_pMDLCache->InitPreloadData(this: g_pMDLCache, a2: false);
  this->max_edicts = 2048;
  g_ServerGlobalVariables.maxEntities = 2048;
  g_ServerGlobalVariables.maxClients = this->GetMaxClients(this);
  g_ClientGlobalVariables.network_protocol = GetHostVersion();
  this->num_edicts = this->GetMaxClients(this) + 1;
  _COM_TimestampedLog(a1: "SV_AllocateEdicts");
  sv.edicts = (edict_t *)Hunk_AllocName(size: 16 * sv.max_edicts, name: "edicts", bClear: true);
  ED_ClearTimes();
  sv.edictchangeinfo = (IChangeInfoAccessor *)Hunk_AllocName(
                                                size: 4 * sv.max_edicts,
                                                name: "edictchangeinfo",
                                                bClear: true);
  g_ServerGlobalVariables.pEdicts = this->edicts;
  this->allowsignonwrites = true;
  this->serverclasses = 0;
  this->serverclassbits = 0;
  CGameServer::AssignClassIds(this);
  _COM_TimestampedLog(a1: "Set up players");
  if ( this->GetClientCount(this) > 0 )
  {
    flStartTimeOverride = 0;
    do
    {
      v40 = &this->edicts[flStartTimeOverride + 1];
      *(_DWORD *)this->m_Clients.m_Memory.m_pMemory[v10][1].m_GUID = v40;
      InitializeEntityDLLFields(pEdict: v40);
      ++flStartTimeOverride;
      ++v10;
    }
    while ( v10 < this->GetClientCount(this) );
  }
  _COM_TimestampedLog(a1: "Set up players(done)");
  this->m_State = ss_loading;
  CBaseServer::SendReservationStatus(this: &sv);
  this->m_flTickInterval = host_state.interval_per_tick;
  this->m_nTickCount = 1 - (int)(-1.0 / host_state.interval_per_tick);
  v11 = _CommandLine();
  v12 = ((double (__thiscall *)(int, const char *, _DWORD))*(_DWORD *)(*(_DWORD *)v11 + 24))(
          a1: v11,
          a2: "-servertime",
          a3: -1.0);
  if ( v12 != -1.0 )
  {
    flStartTimeOverridea = v12;
    v13 = (int)(float)(flStartTimeOverridea / host_state.interval_per_tick) + 1;
    if ( v13 <= 1 )
      v13 = 1;
    this->m_nTickCount = v13;
  }
  g_ServerGlobalVariables.tickcount = this->m_nTickCount;
  g_ServerGlobalVariables.curtime = this->GetTime(this);
  host_tickcount = g_ServerGlobalVariables.tickcount;
  V_snprintf(pDest: szModelName, maxLen: 260, pFormat: "maps/%s.bsp", mapname);
  GetMapPathNameOnDisk(pDiskName: szNameOnDisk, pFullMapName: szModelName, nDiskNameSize: 0x104u);
  g_pFileSystem->AddSearchPath(this: g_pFileSystem, a2: szNameOnDisk, a3: "GAME", a4: PATH_ADD_TO_HEAD);
  g_pFileSystem->BeginMapAccess(this: g_pFileSystem);
  v14 = _CommandLine();
  if ( (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v14 + 40))(a1: v14, a2: "-allowstalezip") == 0
    && g_pFileSystem->FileExists(this: &g_pFileSystem->IBaseFileSystem, a2: "stale.txt", a3: "GAME") )
  {
    _Warning(a1: "This map is not final!!  Needs to be rebuilt without -keepstalezip and without -onlyents\n");
  }
  _COM_TimestampedLog(a1: "modelloader->GetModelForName(%s) -- Start", szModelName);
  v15 = modelloader->GetModelForName(this: modelloader, a2: szModelName, a3: 2);
  CCommonHostState::SetWorldModel(this: &host_state, pModel: v15);
  if ( host_state.worldmodel == nullptr )
  {
    ConMsg(a1: "Couldn't spawn server %s\n", szModelName);
    this->m_State = ss_dead;
    g_pFileSystem->EndMapAccess(this: g_pFileSystem);
    return 0;
  }
  _COM_TimestampedLog(a1: "modelloader->GetModelForName(%s) -- Finished", szModelName);
  if ( this->IsMultiplayer(this) )
  {
    v17 = EngineVGui();
    v17->UpdateProgressBar(this: v17, a2: PROGRESS_CRCMAP, a3: true);
    CRC32_Init(pulCRC: &this->worldmapCRC);
    if ( !CRC_MapFile(crcvalue: &this->worldmapCRC, pszFileName: szNameOnDisk) )
    {
      ConMsg(a1: "Couldn't CRC server map: %s\n", szNameOnDisk);
      this->m_State = ss_dead;
      g_pFileSystem->EndMapAccess(this: g_pFileSystem);
      return 0;
    }
    v18 = EngineVGui();
    v18->UpdateProgressBar(this: v18, a2: PROGRESS_CRCCLIENTDLL, a3: true);
    V_snprintf(pDest: szDllName, maxLen: 96, pFormat: "bin\\client.dll");
    V_FixSlashes(pname: szDllName, separator: 92);
    if ( !CRC_File(crcvalue: &this->clientDllCRC, pszFileName: szDllName) )
      this->clientDllCRC = -1;
  }
  else
  {
    this->worldmapCRC = 0;
    this->clientDllCRC = 0;
  }
  this->m_StringTables = networkStringTableContainerServer;
  _COM_TimestampedLog(a1: "SV_CreateNetworkStringTables");
  v19 = EngineVGui();
  v19->UpdateProgressBar(this: v19, a2: PROGRESS_CREATENETWORKSTRINGTABLES, a3: true);
  SV_CreateNetworkStringTables(pchMapName: mapname);
  this->stringTableCRC = g_pStringTableDictionary->GetCRC(this: g_pStringTableDictionary);
  CGameServer::PrecacheModel(this, name: defaultValue, flags: 0, model: nullptr);
  CGameServer::PrecacheGeneric(this, name: defaultValue, flags: 0);
  CGameServer::PrecacheSound(this, name: defaultValue, flags: 0);
  _COM_TimestampedLog(a1: "Precache world model (%s)", szModelName);
  v20 = EngineVGui();
  v20->UpdateProgressBar(this: v20, a2: PROGRESS_PRECACHEWORLD, a3: true);
  CGameServer::PrecacheModel(this, name: szModelName, flags: 3, model: host_state.worldmodel);
  _COM_TimestampedLog(a1: "Precache brush models");
  for ( i = 1; i < host_state.worldbrush->numsubmodels; ++i )
  {
    V_snprintf(pDest: localmodel, maxLen: 5, pFormat: "*%i", i);
    v22 = modelloader->GetModelForName(this: modelloader, a2: localmodel, a3: 2);
    CGameServer::PrecacheModel(this, name: localmodel, flags: 3, model: v22);
  }
  v23 = EngineVGui();
  v23->UpdateProgressBar(this: v23, a2: PROGRESS_CLEARWORLD, a3: true);
  _COM_TimestampedLog(a1: "SV_ClearWorld");
  SV_ClearWorld();
  _COM_TimestampedLog(a1: "InitializeEntityDLLFields");
  InitializeEntityDLLFields(pEdict: this->edicts);
  this->edicts->m_fStateFlags &= ~2u;
  if ( coop.m_pParent != nullptr )
    m_nValue = coop.m_pParent->m_Value.m_nValue;
  else
    m_nValue = 0;
  g_ServerGlobalVariables.coop = m_nValue != 0;
  if ( m_nValue != 0
    || deathmatch.m_pParent == nullptr
    || (v25 = deathmatch.m_pParent->m_Value.m_nValue == 0, g_ServerGlobalVariables.deathmatch = true, v25) )
  {
    g_ServerGlobalVariables.deathmatch = false;
  }
  m_szMapname = this->m_szMapname;
  if ( this == (CGameServer *)-16 || *m_szMapname == 0 )
    m_szMapname = nullptr;
  g_ServerGlobalVariables.mapname.pszValue = m_szMapname;
  m_szStartspot = this->m_szStartspot;
  if ( this == (CGameServer *)-457 || *m_szStartspot == 0 )
    m_szStartspot = nullptr;
  g_ServerGlobalVariables.startspot.pszValue = m_szStartspot;
  CTestScriptMgr::CheckPoint(this: &g_TestScriptMgr, pName: "map_load");
  v28 = g_GameEventManager->CreateEventA(this: g_GameEventManager, a2: "server_spawn", a3: 0, a4: 0);
  if ( v28 != nullptr )
  {
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
    v28->SetString(this: v28, a2: "hostname", a3: m_pszString);
    v30 = v28->__vftable;
    v31 = netadr_s::ToString(this: &net_local_adr, baseOnly: false);
    v30->SetString(this: v28, a2: "address", a3: v31);
    v32 = v28->__vftable;
    v33 = this->GetUDPPort(this);
    v32->SetInt(this: v28, a2: "port", a3: v33);
    v28->SetString(this: v28, a2: "game", a3: com_gamedir);
    v34 = v28->__vftable;
    v35 = this->GetMapName(this);
    v34->SetString(this: v28, a2: "mapname", a3: v35);
    v36 = v28->__vftable;
    v37 = this->GetMaxClients(this);
    v36->SetInt(this: v28, a2: "maxplayers", a3: v37);
    v28->SetInt(this: v28, a2: "password", a3: 0);
    v28->SetString(this: v28, a2: "os", a3: "WIN32");
    v38 = v28->__vftable;
    v39 = this->IsDedicated(this);
    v38->SetInt(this: v28, a2: "dedicated", a3: v39);
    g_GameEventManager->FireEvent(this: g_GameEventManager, a2: v28, a3: false);
    v5 = (void (*)(const char *, ...))_COM_TimestampedLog;
  }
  v5(a1: "SV_SpawnServer -- Finished");
  g_pFileSystem->EndMapAccess(this: g_pFileSystem);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10126FA0
// Name: protected: virtual void CGameServer::UpdateMasterServerPlayers(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameServer::UpdateMasterServerPlayers(CGameServer *this)
{
  CGameServer *v1; // ebx
  CBaseClient *v2; // esi
  IClient *v3; // edi
  CSteam3Server *v4; // eax
  ISteamGameServer *m_pSteamGameServer; // ebx
  ISteamGameServer_vtbl *v6; // esi
  int v7; // eax
  CSteamID *p_m_SteamID; // [esp+8h] [ebp-Ch]
  CPlayerState *pl; // [esp+Ch] [ebp-8h]
  int i; // [esp+10h] [ebp-4h]

  v1 = this;
  if ( Steam3Server()->m_pSteamGameServer != nullptr )
  {
    for ( i = 0; i < v1->GetClientCount(this: v1); ++i )
    {
      v2 = v1->m_Clients.m_Memory.m_pMemory[i];
      v3 = &v2->IClient;
      if ( v2->IsConnected(this: &v2->IClient) )
      {
        pl = serverGameClients->GetPlayerState(this: serverGameClients, a2: *(_DWORD *)v2[1].m_GUID);
        if ( pl != nullptr )
        {
          p_m_SteamID = &v2->m_SteamID;
          if ( CSteamID::IsValid(this: &v2->m_SteamID) )
          {
            v4 = Steam3Server();
            m_pSteamGameServer = v4->m_pSteamGameServer;
            v6 = v4->m_pSteamGameServer->__vftable;
            v7 = ((int (__thiscall *)(IClient *, int))v3->GetClientName)(a1: v3, a2: pl->frags);
            ((void (__thiscall *)(ISteamGameServer *, _DWORD, _DWORD, int))v6->BUpdateUserData)(
              a1: m_pSteamGameServer,
              a2: *(_DWORD *)&p_m_SteamID->m_steamid.m_comp,
              a3: *((_DWORD *)&p_m_SteamID->m_steamid.m_comp + 1),
              a4: v7);
            v1 = this;
          }
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10127070
// Name: public: virtual void CFunctor2<void (*)(bool,bool),bool,bool,class CRefCounted1<class CFunctor,class CRefCountServiceBase<1,class CRefMT>>>::operator()(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFunctor2<void (__cdecl *)(bool,bool),bool,bool,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>>::operator()(
        CFunctor2<void (__cdecl*)(bool,bool),bool,bool,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> > > *this)
{
  this->m_pfnProxied(a1: this->m_arg1, a2: this->m_arg2);
}

//------------------------------------------------------------------------------
// Address: 0x101270A0
// Name: public: void CGameServer::CopyPureServerWhitelistToStringTable(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameServer::CopyPureServerWhitelistToStringTable(CGameServer *this)
{
  CUtlBuffer buf; // [esp+4h] [ebp-30h] BYREF

  if ( this->m_pPureServerWhitelist != nullptr )
  {
    CUtlBuffer::CUtlBuffer(this: &buf, growSize: 0, initSize: 0, nFlags: 0);
    CPureServerWhitelist::Encode(this: this->m_pPureServerWhitelist, &buf);
    this->m_pServerStartupTable->AddString(
      this: this->m_pServerStartupTable,
      a2: true,
      a3: "PureServerWhitelist",
      a4: buf.m_Put,
      a5: buf.m_Memory.m_pMemory);
    if ( buf.m_Memory.m_nGrowSize >= 0 && buf.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buf.m_Memory.m_pMemory);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10127110
// Name: public: CGameServer::CGameServer(void)
// Source: json
//------------------------------------------------------------------------------
CGameServer *__thiscall CGameServer::CGameServer(CGameServer *this)
{
  CPrecacheItem *model_precache; // edi
  int i; // ebx
  CPrecacheItem *generic_precache; // edi
  int j; // ebx
  CPrecacheItem *sound_precache; // edi
  int k; // ebx
  CPrecacheItem *decal_precache; // edi
  int m; // ebx

  CBaseServer::CBaseServer(this);
  this->__vftable = (CGameServer_vtbl *)&CGameServer::`vftable';
  this->m_TempEntities.m_Memory.m_pMemory = nullptr;
  this->m_TempEntities.m_Memory.m_nAllocationCount = 0;
  this->m_TempEntities.m_Memory.m_nGrowSize = 0;
  this->m_TempEntities.m_Size = 0;
  this->m_TempEntities.m_pElements = nullptr;
  bf_write::bf_write(this: &this->m_FullSendTables);
  this->m_FullSendTablesBuffer.m_pMemory = nullptr;
  this->m_FullSendTablesBuffer.m_nAllocationCount = 0;
  this->m_FullSendTablesBuffer.m_nGrowSize = 0;
  model_precache = this->model_precache;
  for ( i = 1023; i >= 0; --i )
    CPrecacheItem::CPrecacheItem(this: model_precache++);
  generic_precache = this->generic_precache;
  for ( j = 511; j >= 0; --j )
    CPrecacheItem::CPrecacheItem(this: generic_precache++);
  sound_precache = this->sound_precache;
  for ( k = 0x1FFF; k >= 0; --k )
    CPrecacheItem::CPrecacheItem(this: sound_precache++);
  decal_precache = this->decal_precache;
  for ( m = 511; m >= 0; --m )
    CPrecacheItem::CPrecacheItem(this: decal_precache++);
  this->m_nMinClientsLimit = 0;
  this->m_nMaxClientsLimit = 0;
  this->m_pPureServerWhitelist = nullptr;
  this->m_bHibernating = false;
  this->m_bLoadedPlugins = false;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101271F0
// Name: public: virtual int CBaseServer::GetUDPPort(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBaseServer::GetUDPPort(CBaseServer *this)
{
  return NET_GetUDPPort(socket: this->m_Socket);
}

//------------------------------------------------------------------------------
// Address: 0x10127200
// Name: public: virtual int CBaseServer::GetSpawnCount(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBaseServer::GetSpawnCount(CBaseServer *this)
{
  return this->m_nSpawnCount;
}

//------------------------------------------------------------------------------
// Address: 0x10127210
// Name: public: virtual int CBaseServer::GetNumClasses(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBaseServer::GetNumClasses(CBaseServer *this)
{
  return this->serverclasses;
}

//------------------------------------------------------------------------------
// Address: 0x10127220
// Name: public: virtual int CBaseServer::GetClassBits(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBaseServer::GetClassBits(CBaseServer *this)
{
  return this->serverclassbits;
}

//------------------------------------------------------------------------------
// Address: 0x10127230
// Name: public: virtual float CBaseServer::GetCPUUsage(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CBaseServer::GetCPUUsage(CBaseServer *this)
{
  return this->m_fCPUPercent;
}

//------------------------------------------------------------------------------
// Address: 0x10127240
// Name: public: virtual bool CBaseServer::IsLoading(void)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CBaseServer::IsLoading(CBaseServer *this)
{
  return this->m_State == ss_loading;
}

//------------------------------------------------------------------------------
// Address: 0x10127250
// Name: public: virtual CGameServer::~CGameServer(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameServer::~CGameServer(CGameServer *this)
{
  CPureServerWhitelist *m_pPureServerWhitelist; // ecx

  m_pPureServerWhitelist = this->m_pPureServerWhitelist;
  this->__vftable = (CGameServer_vtbl *)&CGameServer::`vftable';
  if ( m_pPureServerWhitelist != nullptr )
    CPureServerWhitelist::Release(this: m_pPureServerWhitelist);
  if ( this->m_FullSendTablesBuffer.m_nGrowSize >= 0 )
  {
    if ( this->m_FullSendTablesBuffer.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_FullSendTablesBuffer.m_pMemory);
      this->m_FullSendTablesBuffer.m_pMemory = nullptr;
    }
    this->m_FullSendTablesBuffer.m_nAllocationCount = 0;
  }
  CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&this->m_TempEntities);
  CBaseServer::~CBaseServer(this);
}

//------------------------------------------------------------------------------
// Address: 0x101272C0
// Name: class CFunctor __near * CreateFunctor<void,bool,bool,bool,bool>(void (*)(bool,bool),bool const __near &,bool const __near &)
// Source: json
//------------------------------------------------------------------------------
CFunctor *__cdecl CreateFunctor<void,bool,bool,bool,bool>(
        void (__cdecl *pfnProxied)(bool, bool),
        const bool *arg1,
        const bool *arg2)
{
  CFunctor *result; // eax

  result = (CFunctor *)MemAlloc_Alloc(nSize: 0x18u);
  if ( result == nullptr )
    return nullptr;
  result[1].m_nUserID = 1;
  result->__vftable = (CFunctor_vtbl *)&CFunctor2<void (__cdecl *)(bool,bool),bool,bool,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>>::`vftable'{for `CFunctor'};
  result[1].__vftable = (CFunctor_vtbl *)&CFunctor2<void (__cdecl *)(bool,bool),bool,bool,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>>::`vftable'{for `CRefCountServiceBase<1,CRefMT>'};
  result[2].__vftable = (CFunctor_vtbl *)pfnProxied;
  LOBYTE(result[2].m_nUserID) = *arg1;
  BYTE1(result[2].m_nUserID) = *arg2;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10127310
// Name: public: void CGameServer::CreateEngineStringTables(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameServer::CreateEngineStringTables(CGameServer *this)
{
  INetworkStringTable *v2; // eax
  CNetworkStringTableContainer *m_StringTables; // ecx
  INetworkStringTable *v4; // eax
  CNetworkStringTableContainer *v5; // ecx
  INetworkStringTable *v6; // eax
  CNetworkStringTableContainer *v7; // ecx
  INetworkStringTable *v8; // eax
  CNetworkStringTableContainer *v9; // ecx
  INetworkStringTable *v10; // eax
  CNetworkStringTableContainer *v11; // ecx
  INetworkStringTable *v12; // eax
  CNetworkStringTableContainer *v13; // ecx
  INetworkStringTable *v14; // eax
  CNetworkStringTableContainer *v15; // ecx
  INetworkStringTable *v16; // eax
  CNetworkStringTableContainer *v17; // ecx
  INetworkStringTable *v18; // eax
  int i; // edi
  int j; // edi
  CDownloadListGenerator *v21; // eax
  INetworkStringTable *m_pDownloadableFileTable; // [esp-4h] [ebp-14h]
  char name[8]; // [esp+8h] [ebp-8h] BYREF

  CNetworkStringTableContainer::SetTick(this: this->m_StringTables, tick_count: this->m_nTickCount);
  v2 = this->m_StringTables->CreateStringTable(
         this: this->m_StringTables,
         a2: "downloadables",
         a3: 0x2000,
         a4: 0,
         a5: 0,
         a6: 1);
  m_StringTables = this->m_StringTables;
  this->m_pDownloadableFileTable = v2;
  v4 = m_StringTables->CreateStringTable(this: m_StringTables, a2: "modelprecache", a3: 1024, a4: 1, a5: 2, a6: 1);
  v5 = this->m_StringTables;
  this->m_pModelPrecacheTable = v4;
  v6 = v5->CreateStringTable(this: v5, a2: "genericprecache", a3: 512, a4: 1, a5: 2, a6: 1);
  v7 = this->m_StringTables;
  this->m_pGenericPrecacheTable = v6;
  v8 = v7->CreateStringTable(this: v7, a2: "soundprecache", a3: 0x2000, a4: 1, a5: 2, a6: 1);
  v9 = this->m_StringTables;
  this->m_pSoundPrecacheTable = v8;
  v10 = v9->CreateStringTable(this: v9, a2: "decalprecache", a3: 512, a4: 1, a5: 2, a6: 1);
  v11 = this->m_StringTables;
  this->m_pDecalPrecacheTable = v10;
  v12 = v11->CreateStringTable(this: v11, a2: "instancebaseline", a3: 1024, a4: 0, a5: 0, a6: 0);
  v13 = this->m_StringTables;
  this->m_pInstanceBaselineTable = v12;
  v14 = v13->CreateStringTable(this: v13, a2: "lightstyles", a3: 64, a4: 0, a5: 0, a6: 0);
  v15 = this->m_StringTables;
  this->m_pLightStyleTable = v14;
  v16 = v15->CreateStringTable(this: v15, a2: "userinfo", a3: 64, a4: 0, a5: 0, a6: 0);
  v17 = this->m_StringTables;
  this->m_pUserInfoTable = v16;
  v18 = v17->CreateStringTable(this: v17, a2: "server_query_info", a3: 4, a4: 0, a5: 0, a6: 0);
  this->m_pServerStartupTable = v18;
  if ( v18 != nullptr )
  {
    *(_DWORD *)&name[4] = Steam3Server()->m_QueryPort;
    this->m_pServerStartupTable->AddString(
      this: this->m_pServerStartupTable,
      a2: true,
      a3: "QueryPort",
      a4: 4,
      a5: &name[4]);
  }
  CGameServer::CopyPureServerWhitelistToStringTable(this);
  for ( i = 0; i < 64; ++i )
  {
    V_snprintf(pDest: name, maxLen: 8, pFormat: "%i", i);
    this->m_pLightStyleTable->AddString(this: this->m_pLightStyleTable, a2: true, a3: name, a4: -1, a5: nullptr);
  }
  for ( j = 0; j < 64; ++j )
  {
    V_snprintf(pDest: name, maxLen: 8, pFormat: "%i", j);
    this->m_pUserInfoTable->AddString(this: this->m_pUserInfoTable, a2: true, a3: name, a4: -1, a5: nullptr);
  }
  m_pDownloadableFileTable = this->m_pDownloadableFileTable;
  v21 = DownloadListGenerator();
  CDownloadListGenerator::SetStringTable(this: v21, pStringTable: m_pDownloadableFileTable);
}

//------------------------------------------------------------------------------
// Address: 0x10127540
// Name: void SV_StartSound(class IRecipientFilter __near &,struct edict_t __near *,int,char const __near *,int,char const __near *,float,enum soundlevel_t,int,int,class Vector const __near *,float,int,class CUtlVector<class Vector,class CUtlMemory<class Vector,int>> __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SV_StartSound(
        IRecipientFilter *filter,
        edict_t *pSoundEmittingEntity,
        int iChannel,
        const char *pSoundEntry,
        int iSoundEntryIndex,
        const char *pSample,
        float flVolume,
        soundlevel_t iSoundLevel,
        int iFlags,
        int iPitch,
        const Vector *pOrigin,
        float soundtime,
        int speakerentity,
        CUtlVector<Vector,CUtlMemory<Vector,int> > *pUtlVecOrigins,
        int nSeed)
{
  IServerUnknown *m_pUnk; // ecx
  ICollideable *v16; // eax
  double FinalTickTime; // st7
  const char *v18; // eax
  const char *v19; // eax
  int nSoundNum; // eax
  SoundInfo_t sound; // [esp+0h] [ebp-5Ch] BYREF
  float pSoundEmittingEntitya; // [esp+68h] [ebp+Ch]
  float soundtimea; // [esp+90h] [ebp+34h]

  memset(&sound.fDelay, 0, 16);
  sound.fVolume = 1.0;
  sound.Soundlevel = SNDLVL_NORM;
  sound.nPitch = 100;
  sound.nSpeakerEntity = -1;
  sound.nChannel = 6;
  sound.nSoundNum = 0;
  sound.nFlags = 0;
  sound.nRandomSeed = 0;
  sound.bLooping = false;
  *(_WORD *)&sound.bIsSentence = 0;
  memset(&sound, 0, 40);
  if ( pSoundEmittingEntity != nullptr )
    sound.nEntityIndex = NUM_FOR_EDICTINFO(e: pSoundEmittingEntity);
  else
    sound.nEntityIndex = 0;
  sound.nChannel = iChannel;
  sound.nPitch = iPitch;
  sound.pszName = pSoundEntry;
  sound.Soundlevel = iSoundLevel;
  sound.nFlags = iFlags;
  sound.fVolume = flVolume;
  sound.nSpeakerEntity = speakerentity;
  sound.nRandomSeed = nSeed;
  if ( pOrigin != nullptr )
  {
    sound.vOrigin = *pOrigin;
  }
  else if ( pSoundEmittingEntity != nullptr && (pSoundEmittingEntity->m_fStateFlags & 4) != 0 )
  {
    m_pUnk = pSoundEmittingEntity->m_pUnk;
    if ( m_pUnk != nullptr )
    {
      v16 = m_pUnk->GetCollideable(this: m_pUnk);
      CM_WorldSpaceCenter(pCollideable: v16, pCenter: &sound.vOrigin);
    }
  }
  if ( pUtlVecOrigins != nullptr )
    CUtlVector<Vector,CUtlMemory<Vector,int>>::InsertBefore(
      this: pUtlVecOrigins,
      elem: pUtlVecOrigins->m_Size,
      src: &sound.vOrigin);
  if ( soundtime != 0.0 )
  {
    pSoundEmittingEntitya = sv.m_flTickInterval;
    sound.fTickTime = CBaseServer::GetFinalTickTime(this: &sv);
    soundtimea = pSoundEmittingEntitya + soundtime;
    FinalTickTime = CBaseServer::GetFinalTickTime(this: &sv);
    sound.nFlags |= 0x10u;
    sound.fDelay = soundtimea - FinalTickTime;
  }
  if ( pSample != nullptr && TestSoundChar(pch: pSample, c: 33) )
  {
    sound.bIsSentence = true;
    v18 = PSkipSoundChars(pch: pSample);
    sound.nSoundNum = V_atoi(str: v18);
    if ( sound.nSoundNum >= VOX_SentenceCount() )
    {
      v19 = PSkipSoundChars(pch: pSample);
      ConMsg(a1: "SV_StartSound: invalid sentence number: %s", v19);
      return;
    }
    goto LABEL_22;
  }
  sound.bIsSentence = false;
  if ( (sound.nFlags & 0x400) != 0 )
  {
    sound.nSoundNum = iSoundEntryIndex;
LABEL_22:
    CGameServer::BroadcastSound(this: &sv, &sound, filter);
    return;
  }
  nSoundNum = CGameServer::LookupSoundIndex(this: &sv, name: pSample);
  sound.nSoundNum = nSoundNum;
  if ( nSoundNum != 0 )
  {
    if ( CGameServer::GetSound(this: &sv, index: nSoundNum) != nullptr )
      goto LABEL_22;
    nSoundNum = sound.nSoundNum;
  }
  ConMsg(a1: "SV_StartSound: %s not precached (%d)\n", pSample, nSoundNum);
}

//------------------------------------------------------------------------------
// Address: 0x101277E0
// Name: void SV_AddOriginToPVS(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SV_AddOriginToPVS(const Vector *vOrigin)
{
  int v1; // ebx
  int v2; // eax
  int *m_pMemory; // edx
  int v4; // edi
  int m_Size; // eax
  int v6; // ecx
  int v7; // esi
  int v8; // eax
  int *v9; // eax
  int v10; // eax
  int *v11; // edx
  int v12; // edi
  int v13; // eax
  int v14; // ecx
  int v15; // esi
  int v16; // eax
  int *v17; // eax

  v1 = CM_PointLeafnum(p: vOrigin);
  v2 = CM_LeafCluster(leafnum: v1);
  m_pMemory = g_ClustersNetworked.m_Memory.m_pMemory;
  v4 = v2;
  m_Size = g_ClustersNetworked.m_Size;
  v6 = 0;
  if ( g_ClustersNetworked.m_Size <= 0 )
    goto LABEL_6;
  while ( g_ClustersNetworked.m_Memory.m_pMemory[v6] != v4 )
  {
    if ( ++v6 >= g_ClustersNetworked.m_Size )
      goto LABEL_6;
  }
  if ( v6 == -1 )
  {
LABEL_6:
    v7 = g_ClustersNetworked.m_Size;
    if ( g_ClustersNetworked.m_Size + 1 > g_ClustersNetworked.m_Memory.m_nAllocationCount )
    {
      CUtlMemory<INetMessage *,int>::Grow(
        this: (CUtlMemory<S3RGBA,int> *)&g_ClustersNetworked,
        num: g_ClustersNetworked.m_Size - g_ClustersNetworked.m_Memory.m_nAllocationCount + 1);
      m_Size = g_ClustersNetworked.m_Size;
      m_pMemory = g_ClustersNetworked.m_Memory.m_pMemory;
    }
    g_ClustersNetworked.m_Size = m_Size + 1;
    v8 = m_Size - v7;
    g_ClustersNetworked.m_pElements = m_pMemory;
    if ( v8 > 0 )
    {
      _V_memmove(dest: &m_pMemory[v7 + 1], src: &m_pMemory[v7], count: 4 * v8);
      m_pMemory = g_ClustersNetworked.m_Memory.m_pMemory;
    }
    v9 = &m_pMemory[v7];
    if ( v9 != nullptr )
      *v9 = v4;
    SV_AddToFatPVS(nClusterIndex: v4);
    v10 = CM_LeafArea(leafnum: v1);
    v11 = g_AreasNetworked.m_Memory.m_pMemory;
    v12 = v10;
    v13 = g_AreasNetworked.m_Size;
    v14 = 0;
    if ( g_AreasNetworked.m_Size <= 0 )
      goto LABEL_17;
    while ( g_AreasNetworked.m_Memory.m_pMemory[v14] != v12 )
    {
      if ( ++v14 >= g_AreasNetworked.m_Size )
        goto LABEL_17;
    }
    if ( v14 == -1 )
    {
LABEL_17:
      v15 = g_AreasNetworked.m_Size;
      if ( g_AreasNetworked.m_Size + 1 > g_AreasNetworked.m_Memory.m_nAllocationCount )
      {
        CUtlMemory<INetMessage *,int>::Grow(
          this: (CUtlMemory<S3RGBA,int> *)&g_AreasNetworked,
          num: g_AreasNetworked.m_Size - g_AreasNetworked.m_Memory.m_nAllocationCount + 1);
        v13 = g_AreasNetworked.m_Size;
        v11 = g_AreasNetworked.m_Memory.m_pMemory;
      }
      g_AreasNetworked.m_Size = v13 + 1;
      v16 = v13 - v15;
      g_AreasNetworked.m_pElements = v11;
      if ( v16 > 0 )
      {
        _V_memmove(dest: &v11[v15 + 1], src: &v11[v15], count: 4 * v16);
        v11 = g_AreasNetworked.m_Memory.m_pMemory;
      }
      v17 = &v11[v15];
      if ( v17 != nullptr )
        *v17 = v12;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10127AF0
// Name: public: virtual void CGameServer::Clear(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameServer::Clear(CGameServer *this)
{
  ServerClass *j; // eax
  int v3; // eax
  CEventInfo *v4; // esi
  int *m_pMemory; // eax
  int i; // [esp+8h] [ebp-4h]

  this->m_pModelPrecacheTable = nullptr;
  this->m_pGenericPrecacheTable = nullptr;
  this->m_pSoundPrecacheTable = nullptr;
  this->m_pDecalPrecacheTable = nullptr;
  this->m_bIsLevelMainMenuBackground = false;
  this->m_bLoadgame = false;
  CCommonHostState::SetWorldModel(this: &host_state, pModel: nullptr);
  _V_memset(dest: this->m_szStartspot, fill: 0, count: 64);
  this->num_edicts = 0;
  this->max_edicts = 0;
  this->edicts = nullptr;
  g_ServerGlobalVariables.maxEntities = 0;
  g_ServerGlobalVariables.pEdicts = nullptr;
  if ( serverGameDLL != nullptr )
  {
    for ( j = serverGameDLL->GetAllServerClasses(this: serverGameDLL); j != nullptr; j = j->m_pNext )
      j->m_InstanceBaselineIndex = 0xFFFF;
  }
  v3 = 0;
  for ( i = 0; v3 < this->m_TempEntities.m_Size; i = v3 )
  {
    v4 = this->m_TempEntities.m_Memory.m_pMemory[v3];
    if ( v4 != nullptr )
    {
      if ( v4->pData != nullptr )
        free(pMem: v4->pData);
      v4->filter.m_Recipients.m_Size = 0;
      if ( v4->filter.m_Recipients.m_Memory.m_nGrowSize >= 0 )
      {
        if ( v4->filter.m_Recipients.m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v4->filter.m_Recipients.m_Memory.m_pMemory);
          v4->filter.m_Recipients.m_Memory.m_pMemory = nullptr;
        }
        v4->filter.m_Recipients.m_Memory.m_nAllocationCount = 0;
      }
      m_pMemory = v4->filter.m_Recipients.m_Memory.m_pMemory;
      v4->filter.m_Recipients.m_pElements = m_pMemory;
      if ( v4->filter.m_Recipients.m_Memory.m_nGrowSize >= 0 )
      {
        if ( m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
          v4->filter.m_Recipients.m_Memory.m_pMemory = nullptr;
        }
        v4->filter.m_Recipients.m_Memory.m_nAllocationCount = 0;
      }
      v4->filter.__vftable = (CEngineRecipientFilter_vtbl *)&IRecipientFilter::`vftable';
      free(pMem: v4);
      v3 = i;
    }
    ++v3;
  }
  this->m_TempEntities.m_Size = 0;
  if ( this->m_TempEntities.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_TempEntities.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_TempEntities.m_Memory.m_pMemory);
      this->m_TempEntities.m_Memory.m_pMemory = nullptr;
    }
    this->m_TempEntities.m_Memory.m_nAllocationCount = 0;
  }
  this->m_TempEntities.m_pElements = this->m_TempEntities.m_Memory.m_pMemory;
  CBaseServer::Clear(this);
}

//------------------------------------------------------------------------------
// Address: 0x10127C70
// Name: public: virtual void CGameServer::SendClientMessages(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameServer::SendClientMessages(CGameServer *this, bool bSendSnapshots)
{
  int v2; // ebx
  int (__thiscall *GetClientCount)(struct CGameServer *); // edx
  CGameClient *v5; // esi
  int v6; // eax
  netadr_s *v7; // eax
  CFrameSnapshot *v8; // ebx
  int m_Size; // eax
  CEventInfo **v10; // eax
  signed int v11; // esi
  int v12; // edi
  CGameClient *v13; // esi
  CClientFrame *SendFrame; // eax
  const char *v15; // [esp-Ch] [ebp-130h]
  CGameClient *pReceivingClients[64]; // [esp+8h] [ebp-11Ch] BYREF
  CParallelProcessor<CGameClient *,CFuncJobItemProcessor<CGameClient *>,1> v17; // [esp+108h] [ebp-1Ch] BYREF
  int receivingClientCount; // [esp+120h] [ebp-4h]

  v2 = 0;
  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "SendClientMessages",
    a3: 0,
    a4: "Networking",
    a5: false,
    a6: 4);
  GetClientCount = this->GetClientCount;
  receivingClientCount = 0;
  if ( GetClientCount(this) > 0 )
  {
    do
    {
      v5 = (CGameClient *)this->m_Clients.m_Memory.m_pMemory[v2];
      if ( v5->ShouldSendMessages(this: v5) )
      {
        if ( bSendSnapshots && v5->IsActive(this: &v5->IClient) )
        {
          v6 = receivingClientCount;
          pReceivingClients[receivingClientCount] = v5;
          receivingClientCount = v6 + 1;
        }
        else if ( !v5->IsFakeClient(this: &v5->IClient) )
        {
          if ( NET_IsMultiplayer() && v5->m_NetChannel->GetSequenceNr(this: v5->m_NetChannel, a2: 1) == 0 )
          {
            v7 = (netadr_s *)((int (__thiscall *)(INetChannel *, const char *, int))v5->m_NetChannel->GetRemoteAddress)(
                               a1: v5->m_NetChannel,
                               a2: "%c00000000000000",
                               a3: 66);
            NET_OutOfBandPrintf(sock: this->m_Socket, adr: v7, format: v15);
          }
          v5->m_NetChannel->Transmit(this: v5->m_NetChannel, a2: false);
          v5->UpdateSendState(this: v5);
        }
      }
      else if ( v5->IsSplitScreenUser(this: &v5->IClient) )
      {
        CGameClient::WriteViewAngleUpdate(this: v5);
      }
      ++v2;
    }
    while ( v2 < this->GetClientCount(this) );
    if ( receivingClientCount != 0 )
    {
      v8 = CFrameSnapshotManager::TakeTickSnapshot(this: framesnapshotmanager, tickcount: this->m_nTickCount);
      m_Size = this->m_TempEntities.m_Size;
      if ( m_Size > 0 )
      {
        v8->m_nTempEntities = m_Size;
        v10 = (CEventInfo **)MemAlloc_Alloc(nSize: (unsigned __int64)(unsigned int)m_Size >> 30 != 0 ? -1 : 4 * m_Size);
        v8->m_pTempEntities = v10;
        _V_memcpy(dest: v10, src: this->m_TempEntities.m_Memory.m_pMemory, count: 4 * this->m_TempEntities.m_Size);
        this->m_TempEntities.m_Size = 0;
      }
      v11 = receivingClientCount;
      SV_ComputeClientPacks(clientCount: receivingClientCount, clients: pReceivingClients, snapshot: v8);
      v12 = 0;
      if ( v11 > 1
        && sv_parallel_sendsnapshot.m_pParent != nullptr
        && sv_parallel_sendsnapshot.m_pParent->m_Value.m_nValue != 0 )
      {
        v17.m_pItems.m_value = nullptr;
        v17.m_pLimit = nullptr;
        _InterlockedExchange((volatile __int32 *)&v17.m_pItems, 0);
        v17.m_ItemProcessor.m_pfnProcess = SV_ParallelSendSnapshot;
        v17.m_ItemProcessor.m_pfnBegin = nullptr;
        v17.m_ItemProcessor.m_pfnEnd = nullptr;
        CParallelProcessor<CGameClient *,CFuncJobItemProcessor<CGameClient *>,1>::Run(
          this: &v17,
          pItems: pReceivingClients,
          nItems: v11,
          nChunkSize: 1,
          nMaxParallel: 0x7FFFFFFF,
          pThreadPool: nullptr);
      }
      else if ( v11 > 0 )
      {
        do
        {
          v13 = pReceivingClients[v12];
          SendFrame = CGameClient::GetSendFrame(this: v13);
          if ( SendFrame != nullptr )
          {
            v13->SendSnapshot(this: v13, a2: SendFrame);
            v13->UpdateSendState(this: v13);
          }
          ++v12;
        }
        while ( v12 < receivingClientCount );
      }
      CFrameSnapshot::ReleaseReference(this: v8);
    }
  }
  serverGameClients->PostClientMessagesSent(this: serverGameClients);
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
}

//------------------------------------------------------------------------------
// Address: 0x10127EC0
// Name: void SV_SendClientUpdates(bool,bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SV_SendClientUpdates(BOOL bIsSimulating)
{
  bool v1; // bl
  bool v2; // al

  v1 = s_bForceSend;
  s_bForceSend = false;
  if ( serverGameDLL != nullptr )
    serverGameDLL->PreClientUpdate(this: serverGameDLL, a2: bIsSimulating);
  v2 = bIsSimulating || v1;
  CGameServer::SendClientMessages(this: &sv, bSendSnapshots: v2);
  CNetworkStringTableContainer::SetTick(this: networkStringTableContainerServer, tick_count: sv.m_nTickCount + 1);
}

//------------------------------------------------------------------------------
// Address: 0x10127F20
// Name: void SV_Frame(bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SV_Frame(int finalTick)
{
  bool v1; // bl
  CSteam3Server *v2; // eax
  int bSendDuringPause; // [esp+0h] [ebp-8h] BYREF
  BOOL bIsSimulating; // [esp+4h] [ebp-4h] BYREF

  if ( serverGameDLL != nullptr && (_BYTE)finalTick != 0 )
    ((void (__stdcall *)(int))serverGameDLL->Think)(a1: finalTick);
  if ( sv.m_State >= ss_active && Host_ShouldRun() != 0 )
  {
    g_ServerGlobalVariables.frametime = host_state.interval_per_tick;
    LOBYTE(bIsSimulating) = SV_IsSimulating();
    v1 = sv_noclipduringpause != nullptr
      && sv_noclipduringpause->m_pParent != nullptr
      && sv_noclipduringpause->m_pParent->m_Value.m_nValue != 0;
    LOBYTE(bSendDuringPause) = v1;
    CNetworkStringTableContainer::Lock(this: networkStringTableContainerServer, bLock: false);
    CBaseServer::RunFrame(this: &sv, a2: v1);
    if ( sv.m_Clients.m_Size <= 0 )
    {
      if ( sv.m_nMaxclients > 1 )
        SV_Think(bIsSimulating: false);
    }
    else
    {
      if ( serverGameDLL != nullptr && !serverGameDLL->IsRestoring(this: serverGameDLL) && (bIsSimulating || v1) )
        CNetworkStringTableContainer::SetTick(this: networkStringTableContainerServer, tick_count: ++sv.m_nTickCount);
      SV_Think(bIsSimulating);
    }
    if ( (_BYTE)finalTick != 0 )
    {
      if ( g_bThreadedEngine && sv.m_nMaxclients <= 1 )
        g_pDeferredServerWork = CreateFunctor<void,bool,bool,bool,bool>(
                                  pfnProxied: (void (__cdecl *)(bool, bool))SV_SendClientUpdates,
                                  arg1: (const bool *)&bIsSimulating,
                                  arg2: (const bool *)&bSendDuringPause);
      else
        SV_SendClientUpdates(bIsSimulating);
    }
    CNetworkStringTableContainer::Lock(this: networkStringTableContainerServer, bLock: true);
    if ( sv.m_nMaxclients > 1 || serverGameDLL->ShouldPreferSteamAuth(this: serverGameDLL) )
    {
      v2 = Steam3Server();
      CSteam3Server::RunFrame(this: v2);
    }
  }
  else
  {
    NET_ProcessSocket(sock: 1, handler: &sv);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10128100
// Name: public: CUtlHash<struct CGameSaveRestoreInfo::CHashElement,class CGameSaveRestoreInfo::CHashFuncs,class CGameSaveRestoreInfo::CHashFuncs>::CUtlHash<struct CGameSaveRestoreInfo::CHashElement,class CGameSaveRestoreInfo::CHashFuncs,class CGameSaveRestoreInfo::CHashFuncs>(int,int,int,class CGameSaveRestoreInfo::CHashFuncs,class CGameSaveRestoreInfo::CHashFuncs)
// Source: json
//------------------------------------------------------------------------------
CUtlHash<CGameSaveRestoreInfo::CHashElement,CGameSaveRestoreInfo::CHashFuncs,CGameSaveRestoreInfo::CHashFuncs> *__thiscall CUtlHash<CGameSaveRestoreInfo::CHashElement,CGameSaveRestoreInfo::CHashFuncs,CGameSaveRestoreInfo::CHashFuncs>::CUtlHash<CGameSaveRestoreInfo::CHashElement,CGameSaveRestoreInfo::CHashFuncs,CGameSaveRestoreInfo::CHashFuncs>(
        CUtlHash<CGameSaveRestoreInfo::CHashElement,CGameSaveRestoreInfo::CHashFuncs,CGameSaveRestoreInfo::CHashFuncs> *this,
        int bucketCount,
        int growCount,
        int initCount,
        CGameSaveRestoreInfo::CHashFuncs compareFunc,
        CGameSaveRestoreInfo::CHashFuncs keyFunc)
{
  int v6; // esi
  int v8; // eax
  CUtlMemory<ResourceEntryInfo,int> *v9; // esi
  int m_nAllocationCount; // eax
  ResourceEntryInfo *m_pMemory; // ecx
  int v12; // eax
  bool v13; // zf
  int v15; // [esp+Ch] [ebp-8h]
  int v16; // [esp+10h] [ebp-4h]

  v6 = bucketCount;
  this->m_Buckets.m_Memory.m_pMemory = nullptr;
  this->m_Buckets.m_Memory.m_nAllocationCount = 0;
  this->m_Buckets.m_Memory.m_nGrowSize = 0;
  this->m_Buckets.m_Size = 0;
  this->m_Buckets.m_pElements = nullptr;
  if ( bucketCount >= 0x10000 )
  {
    bucketCount = 0x10000;
    v6 = 0x10000;
  }
  CUtlVector<CUtlVector<CGameSaveRestoreInfo::CHashElement,CUtlMemory<CGameSaveRestoreInfo::CHashElement,int>>,CUtlMemory<CUtlVector<CGameSaveRestoreInfo::CHashElement,CUtlMemory<CGameSaveRestoreInfo::CHashElement,int>>,int>>::RemoveAll(this: &this->m_Buckets);
  CUtlVector<CUtlVector<CSplitPacketEntry,CUtlMemory<CSplitPacketEntry,int>>,CUtlMemory<CUtlVector<CSplitPacketEntry,CUtlMemory<CSplitPacketEntry,int>>,int>>::InsertMultipleBefore(
    this: &this->m_Buckets,
    elem: this->m_Buckets.m_Size,
    num: v6);
  if ( v6 > 0 )
  {
    v8 = 0;
    v16 = 0;
    v15 = v6;
    do
    {
      v9 = (CUtlMemory<ResourceEntryInfo,int> *)((char *)this->m_Buckets.m_Memory.m_pMemory + v8);
      v9[1].m_pMemory = nullptr;
      if ( initCount != 0 )
      {
        m_nAllocationCount = v9->m_nAllocationCount;
        if ( initCount > m_nAllocationCount )
          CUtlMemory<CAsyncWavDataCache::DeadBufferEntry_t,int>::Grow(this: v9, num: initCount - m_nAllocationCount);
        v9[1].m_pMemory = (ResourceEntryInfo *)((char *)v9[1].m_pMemory + initCount);
        m_pMemory = v9->m_pMemory;
        v12 = (int)v9[1].m_pMemory - initCount;
        v9[1].m_nAllocationCount = (int)v9->m_pMemory;
        if ( v12 > 0 && initCount > 0 )
          _V_memmove(dest: &m_pMemory[initCount], src: m_pMemory, count: 8 * v12);
      }
      this->m_Buckets.m_Memory.m_pMemory[v16].m_Memory.m_nGrowSize = growCount;
      v8 = v16 * 20 + 20;
      v13 = v15-- == 1;
      ++v16;
    }
    while ( !v13 );
    v6 = bucketCount;
  }
  this->m_bPowerOfTwo = ((v6 - 1) & v6) == 0;
  this->m_ModMask = ((v6 - 1) & v6) == 0 ? v6 - 1 : 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101281E0
// Name: public: CSaveRestoreData::CSaveRestoreData(void)
// Source: json
//------------------------------------------------------------------------------
CSaveRestoreData *__thiscall CSaveRestoreData::CSaveRestoreData(CSaveRestoreData *this)
{
  CGameSaveRestoreInfo *v2; // edi
  CGameSaveRestoreInfo::CHashFuncs v4; // [esp-8h] [ebp-18h] BYREF
  CGameSaveRestoreInfo::CHashFuncs v5; // [esp-4h] [ebp-14h]
  CGameSaveRestoreInfo::CHashFuncs *v6; // [esp+Ch] [ebp-4h]

  v5 = (CGameSaveRestoreInfo::CHashFuncs)this;
  this->pBaseData = nullptr;
  this->pCurrentData = nullptr;
  v4 = (CGameSaveRestoreInfo::CHashFuncs)this;
  this->size = 0;
  this->bufferSize = 0;
  v6 = &v4;
  this->tokenCount = 0;
  v2 = &this->CGameSaveRestoreInfo;
  this->pTokens = nullptr;
  this->m_nEntityDataSize = 0;
  this->tableCount = 0;
  this->pTable = nullptr;
  this->m_pCurrentEntity = nullptr;
  CUtlHash<CGameSaveRestoreInfo::CHashElement,CGameSaveRestoreInfo::CHashFuncs,CGameSaveRestoreInfo::CHashFuncs>::CUtlHash<CGameSaveRestoreInfo::CHashElement,CGameSaveRestoreInfo::CHashFuncs,CGameSaveRestoreInfo::CHashFuncs>(
    this: &this->m_EntityToIndex,
    bucketCount: 0,
    growCount: 0,
    initCount: 0,
    compareFunc: v4,
    keyFunc: v5);
  memset(dst: (unsigned __int8 *)v2, value: 0, count: 0x550u);
  v2->modelSpaceOffset.x = 0.0;
  v2->modelSpaceOffset.y = 0.0;
  v2->modelSpaceOffset.z = 0.0;
  this->bAsync = false;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10128270
// Name: public: void CGameServer::FinishRestore(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CGameServer::FinishRestore(CGameServer *this@<ecx>, int a2@<esi>)
{
  int v3; // esi
  levellist_t *levelList; // edi
  CUtlVector<CGameSaveRestoreInfo::CHashElement,CUtlMemory<CGameSaveRestoreInfo::CHashElement,int> > *m_pMemory; // eax
  int v6; // [esp-8h] [ebp-6B4h]
  int v7; // [esp-4h] [ebp-6B0h]
  CSaveRestoreData currentLevelData; // [esp+4h] [ebp-6A8h] BYREF
  char name[260]; // [esp+5A8h] [ebp-104h] BYREF

  CSaveRestoreData::CSaveRestoreData(this: &currentLevelData);
  if ( this->m_bLoadgame )
  {
    g_ServerGlobalVariables.pSaveData = &currentLevelData;
    serverGameDLL->BuildAdjacentMapList(this: serverGameDLL);
    if ( saverestore->IsXSave(this: saverestore) )
    {
      V_snprintf(pDest: name, maxLen: 260, pFormat: "%s:\\%s.HL2", host_parms.mod, this->m_szMapname);
    }
    else
    {
      v6 = ((int (__thiscall *)(ISaveRestore *, char *))saverestore->GetSaveDir)(a1: saverestore, a2: this->m_szMapname);
      V_snprintf(pDest: name, maxLen: 260, pFormat: "%s%s.HL2", v6, v7);
    }
    V_FixSlashes(pname: name, separator: 92);
    ((void (__thiscall *)(ISaveRestore *, char *, _DWORD, int))saverestore->RestoreClientState)(
      a1: saverestore,
      a2: name,
      a3: 0,
      a4: a2);
    if ( g_ServerGlobalVariables.eLoadType == MapLoad_Transition )
    {
      v3 = 0;
      if ( currentLevelData.levelInfo.connectionCount > 0 )
      {
        levelList = currentLevelData.levelInfo.levelList;
        do
        {
          saverestore->RestoreAdjacenClientState(this: saverestore, a2: (const char *)levelList);
          ++v3;
          ++levelList;
        }
        while ( v3 < currentLevelData.levelInfo.connectionCount );
      }
    }
    saverestore->OnFinishedClientRestore(this: saverestore);
    g_ServerGlobalVariables.pSaveData = nullptr;
    this->m_bLoadgame = false;
    saverestore->SetIsXSave(this: saverestore, a2: false);
    CUtlHash<DispCollPlaneIndex_t,CPlaneIndexHashFuncs,CPlaneIndexHashFuncs>::Purge(this: &currentLevelData.m_EntityToIndex);
    CUtlVector<CUtlVector<CGameSaveRestoreInfo::CHashElement,CUtlMemory<CGameSaveRestoreInfo::CHashElement,int>>,CUtlMemory<CUtlVector<CGameSaveRestoreInfo::CHashElement,CUtlMemory<CGameSaveRestoreInfo::CHashElement,int>>,int>>::RemoveAll(this: &currentLevelData.m_EntityToIndex.m_Buckets);
    m_pMemory = currentLevelData.m_EntityToIndex.m_Buckets.m_Memory.m_pMemory;
    if ( currentLevelData.m_EntityToIndex.m_Buckets.m_Memory.m_nGrowSize >= 0 )
    {
      if ( currentLevelData.m_EntityToIndex.m_Buckets.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: currentLevelData.m_EntityToIndex.m_Buckets.m_Memory.m_pMemory);
        m_pMemory = nullptr;
        currentLevelData.m_EntityToIndex.m_Buckets.m_Memory.m_pMemory = nullptr;
      }
      currentLevelData.m_EntityToIndex.m_Buckets.m_Memory.m_nAllocationCount = 0;
    }
    currentLevelData.m_EntityToIndex.m_Buckets.m_pElements = m_pMemory;
    if ( currentLevelData.m_EntityToIndex.m_Buckets.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
  }
  else
  {
    CUtlHash<DispCollPlaneIndex_t,CPlaneIndexHashFuncs,CPlaneIndexHashFuncs>::Purge(this: &currentLevelData.m_EntityToIndex);
    CUtlVector<CUtlVector<CSplitPacketEntry,CUtlMemory<CSplitPacketEntry,int>>,CUtlMemory<CUtlVector<CSplitPacketEntry,CUtlMemory<CSplitPacketEntry,int>>,int>>::~CUtlVector<CUtlVector<CSplitPacketEntry,CUtlMemory<CSplitPacketEntry,int>>,CUtlMemory<CUtlVector<CSplitPacketEntry,CUtlMemory<CSplitPacketEntry,int>>,int>>(this: &currentLevelData.m_EntityToIndex.m_Buckets);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10313560
// Name: _dynamic_initializer_for__sv_unlockedchapters__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_unlockedchapters__()
{
  ConVar::ConVar(
    this: &sv_unlockedchapters,
    pName: "sv_unlockedchapters",
    pDefaultValue: "1",
    flags: 128,
    pHelpString: "Highest unlocked game chapter.");
  return atexit(func: dynamic_atexit_destructor_for__sv_unlockedchapters__);
}

//------------------------------------------------------------------------------
// Address: 0x10317300
// Name: _dynamic_initializer_for__sv_maxrate__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_maxrate__()
{
  ConVar::ConVar(
    this: &sv_maxrate,
    pName: "sv_maxrate",
    pDefaultValue: "0",
    flags: 532480,
    pHelpString: "Max bandwidth rate allowed on server, 0 == unlimited",
    bMin: true,
    fMin: 0.0,
    bMax: true,
    fMax: 30000.0);
  return atexit(func: dynamic_atexit_destructor_for__sv_maxrate__);
}

//------------------------------------------------------------------------------
// Address: 0x10317340
// Name: _dynamic_initializer_for__sv_minrate__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_minrate__()
{
  ConVar::ConVar(
    this: &sv_minrate,
    pName: "sv_minrate",
    pDefaultValue: "5000",
    flags: 532480,
    pHelpString: "Min bandwidth rate allowed on server, 0 == unlimited",
    bMin: true,
    fMin: 0.0,
    bMax: true,
    fMax: 30000.0);
  return atexit(func: dynamic_atexit_destructor_for__sv_minrate__);
}

//------------------------------------------------------------------------------
// Address: 0x10317380
// Name: _dynamic_initializer_for__sv_maxupdaterate__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_maxupdaterate__()
{
  ConVar::ConVar(
    this: &sv_maxupdaterate,
    pName: "sv_maxupdaterate",
    pDefaultValue: "66",
    flags: 0x2000,
    pHelpString: "Maximum updates per second that the server will allow");
  return atexit(func: dynamic_atexit_destructor_for__sv_maxupdaterate__);
}

//------------------------------------------------------------------------------
// Address: 0x103173B0
// Name: _dynamic_initializer_for__sv_minupdaterate__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_minupdaterate__()
{
  ConVar::ConVar(
    this: &sv_minupdaterate,
    pName: "sv_minupdaterate",
    pDefaultValue: "10",
    flags: 0x2000,
    pHelpString: "Minimum updates per second that the server will allow");
  return atexit(func: dynamic_atexit_destructor_for__sv_minupdaterate__);
}

//------------------------------------------------------------------------------
// Address: 0x103173E0
// Name: _dynamic_initializer_for__sv_stressbots__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_stressbots__()
{
  ConVar::ConVar(
    this: &sv_stressbots,
    pName: "sv_stressbots",
    pDefaultValue: "0",
    flags: 2,
    pHelpString: "If set to 1, the server calculates data and fills packets to bots. Used for perf testing.");
  return atexit(func: dynamic_atexit_destructor_for__sv_stressbots__);
}

//------------------------------------------------------------------------------
// Address: 0x10317410
// Name: _dynamic_initializer_for__sv_allowdownload__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_allowdownload__()
{
  ConVar::ConVar(
    this: &sv_allowdownload,
    pName: "sv_allowdownload",
    pDefaultValue: "1",
    flags: 0,
    pHelpString: "Allow clients to download files");
  return atexit(func: dynamic_atexit_destructor_for__sv_allowdownload__);
}

//------------------------------------------------------------------------------
// Address: 0x10317440
// Name: _dynamic_initializer_for__sv_allowupload__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_allowupload__()
{
  ConVar::ConVar(
    this: &sv_allowupload,
    pName: "sv_allowupload",
    pDefaultValue: "1",
    flags: 0,
    pHelpString: "Allow clients to upload customizations files");
  return atexit(func: dynamic_atexit_destructor_for__sv_allowupload__);
}

//------------------------------------------------------------------------------
// Address: 0x10317500
// Name: _dynamic_initializer_for__sv_maxclientframes__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_maxclientframes__()
{
  ConVar::ConVar(this: &sv_maxclientframes, pName: "sv_maxclientframes", pDefaultValue: "128", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__sv_maxclientframes__);
}

//------------------------------------------------------------------------------
// Address: 0x10317530
// Name: _dynamic_initializer_for__sv_extra_client_connect_time__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_extra_client_connect_time__()
{
  ConVar::ConVar(
    this: &sv_extra_client_connect_time,
    pName: "sv_extra_client_connect_time",
    pDefaultValue: "15.0",
    flags: 0,
    pHelpString: "Seconds after client connect during which extra frames are buffered to prevent non-delta'd update");
  return atexit(func: dynamic_atexit_destructor_for__sv_extra_client_connect_time__);
}

//------------------------------------------------------------------------------
// Address: 0x10317560
// Name: _dynamic_initializer_for__sv_sound_discardextraunreliable__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_sound_discardextraunreliable__()
{
  ConVar::ConVar(
    this: &sv_sound_discardextraunreliable,
    pName: "sv_sound_discardextraunreliable",
    pDefaultValue: "1",
    flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__sv_sound_discardextraunreliable__);
}

//------------------------------------------------------------------------------
// Address: 0x10317590
// Name: _dynamic_initializer_for__sv_deltatime__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_deltatime__()
{
  ConVar::ConVar(
    this: &sv_deltatime,
    pName: "sv_deltatime",
    pDefaultValue: "0",
    flags: 0,
    pHelpString: "Enable profiling of CalcDelta calls");
  return atexit(func: dynamic_atexit_destructor_for__sv_deltatime__);
}

//------------------------------------------------------------------------------
// Address: 0x103175C0
// Name: _dynamic_initializer_for__sv_deltaprint__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_deltaprint__()
{
  ConVar::ConVar(
    this: &sv_deltaprint,
    pName: "sv_deltaprint",
    pDefaultValue: "0",
    flags: 0,
    pHelpString: "Print accumulated CalcDelta profiling data (only if sv_deltatime is on)");
  return atexit(func: dynamic_atexit_destructor_for__sv_deltaprint__);
}

//------------------------------------------------------------------------------
// Address: 0x10317880
// Name: _dynamic_initializer_for__sv_max_queries_sec__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_max_queries_sec__()
{
  ConVar::ConVar(
    this: &sv_max_queries_sec,
    pName: "sv_max_queries_sec",
    pDefaultValue: "3.0",
    flags: 0,
    pHelpString: "Maximum queries per second to respond to from a single IP address.");
  return atexit(func: dynamic_atexit_destructor_for__sv_max_queries_sec__);
}

//------------------------------------------------------------------------------
// Address: 0x103178B0
// Name: _dynamic_initializer_for__sv_max_queries_window__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_max_queries_window__()
{
  ConVar::ConVar(
    this: &sv_max_queries_window,
    pName: "sv_max_queries_window",
    pDefaultValue: "30",
    flags: 0,
    pHelpString: "Window over which to average queries per second averages.");
  return atexit(func: dynamic_atexit_destructor_for__sv_max_queries_window__);
}

//------------------------------------------------------------------------------
// Address: 0x103178E0
// Name: _dynamic_initializer_for__sv_max_queries_sec_global__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_max_queries_sec_global__()
{
  ConVar::ConVar(
    this: &sv_max_queries_sec_global,
    pName: "sv_max_queries_sec_global",
    pDefaultValue: "60",
    flags: 0,
    pHelpString: "Maximum queries per second to respond to from anywhere.");
  return atexit(func: dynamic_atexit_destructor_for__sv_max_queries_sec_global__);
}

//------------------------------------------------------------------------------
// Address: 0x10317910
// Name: _dynamic_initializer_for__sv_logblocks__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_logblocks__()
{
  ConVar::ConVar(
    this: &sv_logblocks,
    pName: "sv_logblocks",
    pDefaultValue: "0",
    flags: 0,
    pHelpString: "If true when log when a query is blocked (can cause very large log files)");
  return atexit(func: dynamic_atexit_destructor_for__sv_logblocks__);
}

//------------------------------------------------------------------------------
// Address: 0x10317D70
// Name: _dynamic_initializer_for__sv_pure__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_pure__()
{
  ConCommand::ConCommand(
    this: &sv_pure,
    pName: "sv_pure",
    callback: (void (__cdecl *)())SV_Pure_f,
    pHelpString: "Show user data.",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__sv_pure__);
}

//------------------------------------------------------------------------------
// Address: 0x10317DA0
// Name: _dynamic_initializer_for__sv_pure_kick_clients__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_pure_kick_clients__()
{
  ConVar::ConVar(
    this: &sv_pure_kick_clients,
    pName: "sv_pure_kick_clients",
    pDefaultValue: "1",
    flags: 0x80000,
    pHelpString: "If set to 1, the server will kick clients with mismatching files. Otherwise, it will issue a warning to the client.");
  return atexit(func: dynamic_atexit_destructor_for__sv_pure_kick_clients__);
}

//------------------------------------------------------------------------------
// Address: 0x10317DD0
// Name: _dynamic_initializer_for__sv_pure_trace__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_pure_trace__()
{
  ConVar::ConVar(
    this: &sv_pure_trace,
    pName: "sv_pure_trace",
    pDefaultValue: "0",
    flags: 0x80000,
    pHelpString: "If set to 1, the server will print a message whenever a client is verifying a CRC for a file.");
  return atexit(func: dynamic_atexit_destructor_for__sv_pure_trace__);
}

//------------------------------------------------------------------------------
// Address: 0x10317E00
// Name: _dynamic_initializer_for__sv_cheats__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_cheats__()
{
  ConVar::ConVar(
    this: &sv_cheats,
    pName: "sv_cheats",
    pDefaultValue: "0",
    flags: 532736,
    pHelpString: "Allow cheats on server",
    callback: (void (__cdecl *)(IConVar *, const char *, float))SV_CheatsChanged_f);
  return atexit(func: dynamic_atexit_destructor_for__sv_cheats__);
}

//------------------------------------------------------------------------------
// Address: 0x10317E30
// Name: _dynamic_initializer_for__sv_lan__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_lan__()
{
  ConVar::ConVar(
    this: &sv_lan,
    pName: "sv_lan",
    pDefaultValue: "0",
    flags: 0x80000,
    pHelpString: "Server is a lan server ( no heartbeat, no authentication, no non-class C addresses )");
  return atexit(func: dynamic_atexit_destructor_for__sv_lan__);
}

//------------------------------------------------------------------------------
// Address: 0x10317E60
// Name: _dynamic_initializer_for__sv_pausable__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_pausable__()
{
  ConVar::ConVar(
    this: &sv_pausable,
    pName: "sv_pausable",
    pDefaultValue: "0",
    flags: 0x80000,
    pHelpString: "Is the server pausable.");
  return atexit(func: dynamic_atexit_destructor_for__sv_pausable__);
}

//------------------------------------------------------------------------------
// Address: 0x10317E90
// Name: _dynamic_initializer_for__sv_contact__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_contact__()
{
  ConVar::ConVar(
    this: &sv_contact,
    pName: "sv_contact",
    pDefaultValue: defaultValue,
    flags: 524544,
    pHelpString: "Contact email for server sysop");
  return atexit(func: dynamic_atexit_destructor_for__sv_contact__);
}

//------------------------------------------------------------------------------
// Address: 0x10317EC0
// Name: _dynamic_initializer_for__sv_cacheencodedents__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_cacheencodedents__()
{
  ConVar::ConVar(
    this: &sv_cacheencodedents,
    pName: "sv_cacheencodedents",
    pDefaultValue: "1",
    flags: 0,
    pHelpString: "If set to 1, does an optimization to prevent extra SendTable_Encode calls.");
  return atexit(func: dynamic_atexit_destructor_for__sv_cacheencodedents__);
}

//------------------------------------------------------------------------------
// Address: 0x10317EF0
// Name: _dynamic_initializer_for__sv_voicecodec__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_voicecodec__()
{
  ConVar::ConVar(
    this: &sv_voicecodec,
    pName: "sv_voicecodec",
    pDefaultValue: "vaudio_speex",
    flags: 0,
    pHelpString: "Specifies which voice codec DLL to use in a game. Set to the name of the DLL without the extension.");
  return atexit(func: dynamic_atexit_destructor_for__sv_voicecodec__);
}

//------------------------------------------------------------------------------
// Address: 0x10317F20
// Name: _dynamic_initializer_for__sv_voiceenable__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_voiceenable__()
{
  ConVar::ConVar(this: &sv_voiceenable, pName: "sv_voiceenable", pDefaultValue: "1", flags: 524672);
  return atexit(func: dynamic_atexit_destructor_for__sv_voiceenable__);
}

//------------------------------------------------------------------------------
// Address: 0x10317F50
// Name: _dynamic_initializer_for__sv_downloadurl__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_downloadurl__()
{
  ConVar::ConVar(
    this: &sv_downloadurl,
    pName: "sv_downloadurl",
    pDefaultValue: defaultValue,
    flags: 532480,
    pHelpString: "Location from which clients can download missing files");
  return atexit(func: dynamic_atexit_destructor_for__sv_downloadurl__);
}

//------------------------------------------------------------------------------
// Address: 0x10317F80
// Name: _dynamic_initializer_for__sv_consistency__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_consistency__()
{
  ConVar::ConVar(
    this: &sv_consistency,
    pName: "sv_consistency",
    pDefaultValue: "0",
    flags: 532480,
    pHelpString: "Whether the server enforces file consistency for critical files");
  return atexit(func: dynamic_atexit_destructor_for__sv_consistency__);
}

//------------------------------------------------------------------------------
// Address: 0x10317FB0
// Name: _dynamic_initializer_for__sv_maxreplay__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_maxreplay__()
{
  ConVar::ConVar(
    this: &sv_maxreplay,
    pName: "sv_maxreplay",
    pDefaultValue: "0",
    flags: 0,
    pHelpString: "Maximum replay time in seconds",
    bMin: true,
    fMin: 0.0,
    bMax: true,
    fMax: 15.0);
  return atexit(func: dynamic_atexit_destructor_for__sv_maxreplay__);
}

//------------------------------------------------------------------------------
// Address: 0x10317FF0
// Name: _dynamic_initializer_for__sv_mincmdrate__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_mincmdrate__()
{
  ConVar::ConVar(
    this: &sv_mincmdrate,
    pName: "sv_mincmdrate",
    pDefaultValue: "10",
    flags: 532480,
    pHelpString: "This sets the minimum value for cl_cmdrate. 0 == unlimited.");
  return atexit(func: dynamic_atexit_destructor_for__sv_mincmdrate__);
}

//------------------------------------------------------------------------------
// Address: 0x10318020
// Name: _dynamic_initializer_for__sv_maxcmdrate__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_maxcmdrate__()
{
  ConVar::ConVar(
    this: &sv_maxcmdrate,
    pName: "sv_maxcmdrate",
    pDefaultValue: "66",
    flags: 532480,
    pHelpString: "(If sv_mincmdrate is > 0), this sets the maximum value for cl_cmdrate.");
  return atexit(func: dynamic_atexit_destructor_for__sv_maxcmdrate__);
}

//------------------------------------------------------------------------------
// Address: 0x10318050
// Name: _dynamic_initializer_for__sv_client_cmdrate_difference__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_client_cmdrate_difference__()
{
  ConVar::ConVar(
    this: &sv_client_cmdrate_difference,
    pName: "sv_client_cmdrate_difference",
    pDefaultValue: "20",
    flags: 0x2000,
    pHelpString: "cl_cmdrate is moved to within sv_client_cmdrate_difference units of cl_updaterate before it is clamped between sv_mi"
    "ncmdrate and sv_maxcmdrate.");
  return atexit(func: dynamic_atexit_destructor_for__sv_client_cmdrate_difference__);
}

//------------------------------------------------------------------------------
// Address: 0x10318080
// Name: _dynamic_initializer_for__sv_client_min_interp_ratio__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_client_min_interp_ratio__()
{
  ConVar::ConVar(
    this: &sv_client_min_interp_ratio,
    pName: "sv_client_min_interp_ratio",
    pDefaultValue: "1",
    flags: 0x2000,
    pHelpString: "This can be used to limit the value of cl_interp_ratio for connected clients (only while they are connected).\n"
    "              -1 = let clients set cl_interp_ratio to anything\n"
    " any other value = set minimum value for cl_interp_ratio");
  return atexit(func: dynamic_atexit_destructor_for__sv_client_min_interp_ratio__);
}

//------------------------------------------------------------------------------
// Address: 0x103180B0
// Name: _dynamic_initializer_for__sv_client_max_interp_ratio__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_client_max_interp_ratio__()
{
  ConVar::ConVar(
    this: &sv_client_max_interp_ratio,
    pName: "sv_client_max_interp_ratio",
    pDefaultValue: "5",
    flags: 0x2000,
    pHelpString: "This can be used to limit the value of cl_interp_ratio for connected clients (only while they are connected). If sv_"
    "client_min_interp_ratio is -1, then this cvar has no effect.");
  return atexit(func: dynamic_atexit_destructor_for__sv_client_max_interp_ratio__);
}

//------------------------------------------------------------------------------
// Address: 0x103180E0
// Name: _dynamic_initializer_for__sv_client_predict__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_client_predict__()
{
  ConVar::ConVar(
    this: &sv_client_predict,
    pName: "sv_client_predict",
    pDefaultValue: "-1",
    flags: 0x2000,
    pHelpString: "This can be used to force the value of cl_predict for connected clients (only while they are connected).\n"
    "   -1 = let clients set cl_predict to anything\n"
    "    0 = force cl_predict to 0\n"
    "    1 = force cl_predict to 1");
  return atexit(func: dynamic_atexit_destructor_for__sv_client_predict__);
}

//------------------------------------------------------------------------------
// Address: 0x10318300
// Name: _dynamic_initializer_for__sv_memlimit__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_memlimit__()
{
  ConVar::ConVar(
    this: &sv_memlimit,
    pName: "sv_memlimit",
    pDefaultValue: "0",
    flags: 0x4000,
    pHelpString: "If set, whenever a game ends, if the total memory used by the server is greater than this # of megabytes, the server will exit.");
  return atexit(func: dynamic_atexit_destructor_for__sv_memlimit__);
}

//------------------------------------------------------------------------------
// Address: 0x10318330
// Name: _dynamic_initializer_for__sv_shutdown__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_shutdown__()
{
  ConCommand::ConCommand(
    this: &sv_shutdown,
    pName: "sv_shutdown",
    callback: sv_ShutDown,
    pHelpString: "Sets the server to shutdown when all games have completed",
    flags: 0x4000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__sv_shutdown__);
}

//------------------------------------------------------------------------------
// Address: 0x10318360
// Name: _dynamic_initializer_for__sv_parallel_sendsnapshot__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_parallel_sendsnapshot__()
{
  ConVar::ConVar(this: &sv_parallel_sendsnapshot, pName: "sv_parallel_sendsnapshot", pDefaultValue: "1", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__sv_parallel_sendsnapshot__);
}

//------------------------------------------------------------------------------
// Address: 0x10318420
// Name: _dynamic_initializer_for__sv_validate_edict_change_infos__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_validate_edict_change_infos__()
{
  ConVar::ConVar(
    this: &sv_validate_edict_change_infos,
    pName: "sv_validate_edict_change_infos",
    pDefaultValue: "0",
    flags: 0,
    pHelpString: "Verify that edict changeinfos are being calculated properly (used to debug local network backdoor mode).");
  return atexit(func: dynamic_atexit_destructor_for__sv_validate_edict_change_infos__);
}

//------------------------------------------------------------------------------
// Address: 0x10318450
// Name: _dynamic_initializer_for__sv_debugmanualmode__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_debugmanualmode__()
{
  ConVar::ConVar(
    this: &sv_debugmanualmode,
    pName: "sv_debugmanualmode",
    pDefaultValue: "0",
    flags: 0,
    pHelpString: "Make sure entities correctly report whether or not their network data has changed.");
  return atexit(func: dynamic_atexit_destructor_for__sv_debugmanualmode__);
}

//------------------------------------------------------------------------------
// Address: 0x10318480
// Name: _dynamic_initializer_for__sv_parallel_packentities__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_parallel_packentities__()
{
  ConVar::ConVar(this: &sv_parallel_packentities, pName: "sv_parallel_packentities", pDefaultValue: "1", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__sv_parallel_packentities__);
}

//------------------------------------------------------------------------------
// Address: 0x10318630
// Name: _dynamic_initializer_for__sv_forcepreload__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_forcepreload__()
{
  ConVar::ConVar(
    this: &sv_forcepreload,
    pName: "sv_forcepreload",
    pDefaultValue: "0",
    flags: 128,
    pHelpString: "Force server side preloading.");
  return atexit(func: dynamic_atexit_destructor_for__sv_forcepreload__);
}

//------------------------------------------------------------------------------
// Address: 0x103187B0
// Name: _dynamic_initializer_for__sv_rcon_banpenalty__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_rcon_banpenalty__()
{
  ConVar::ConVar(
    this: &sv_rcon_banpenalty,
    pName: "sv_rcon_banpenalty",
    pDefaultValue: "0",
    flags: 0,
    pHelpString: "Number of minutes to ban users who fail rcon authentication",
    bMin: true,
    fMin: 0.0,
    bMax: false,
    fMax: 0.0);
  return atexit(func: dynamic_atexit_destructor_for__sv_rcon_banpenalty__);
}

//------------------------------------------------------------------------------
// Address: 0x103187F0
// Name: _dynamic_initializer_for__sv_rcon_maxfailures__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_rcon_maxfailures__()
{
  ConVar::ConVar(
    this: &sv_rcon_maxfailures,
    pName: "sv_rcon_maxfailures",
    pDefaultValue: "10",
    flags: 0,
    pHelpString: "Max number of times a user can fail rcon authentication before being banned",
    bMin: true,
    fMin: 1.0,
    bMax: true,
    fMax: 20.0);
  return atexit(func: dynamic_atexit_destructor_for__sv_rcon_maxfailures__);
}

//------------------------------------------------------------------------------
// Address: 0x10318830
// Name: _dynamic_initializer_for__sv_rcon_minfailures__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_rcon_minfailures__()
{
  ConVar::ConVar(
    this: &sv_rcon_minfailures,
    pName: "sv_rcon_minfailures",
    pDefaultValue: "5",
    flags: 0,
    pHelpString: "Number of times a user can fail rcon authentication in sv_rcon_minfailuretime before being banned",
    bMin: true,
    fMin: 1.0,
    bMax: true,
    fMax: 20.0);
  return atexit(func: dynamic_atexit_destructor_for__sv_rcon_minfailures__);
}

//------------------------------------------------------------------------------
// Address: 0x10318870
// Name: _dynamic_initializer_for__sv_rcon_minfailuretime__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_rcon_minfailuretime__()
{
  ConVar::ConVar(
    this: &sv_rcon_minfailuretime,
    pName: "sv_rcon_minfailuretime",
    pDefaultValue: "30",
    flags: 0,
    pHelpString: "Number of seconds to track failed rcon authentications",
    bMin: true,
    fMin: 1.0,
    bMax: false,
    fMax: 0.0);
  return atexit(func: dynamic_atexit_destructor_for__sv_rcon_minfailuretime__);
}

//------------------------------------------------------------------------------
// Address: 0x103188B0
// Name: _dynamic_initializer_for__sv_redirectto__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
void dynamic_initializer_for__sv_redirectto__()
{
  netadr_s::SetIP(this: &sv_redirectto, unIP: 0);
  netadr_s::SetPort(this: &sv_redirectto, newport: 0);
  netadr_s::SetType(this: &sv_redirectto, newtype: NA_IP);
}

//------------------------------------------------------------------------------
// Address: 0x10318910
// Name: _dynamic_initializer_for__sv_rcon_log__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_rcon_log__()
{
  ConVar::ConVar(
    this: &sv_rcon_log,
    pName: "sv_rcon_log",
    pDefaultValue: "1",
    flags: 0,
    pHelpString: "Enable/disable rcon logging.");
  return atexit(func: dynamic_atexit_destructor_for__sv_rcon_log__);
}

//------------------------------------------------------------------------------
// Address: 0x10318970
// Name: _dynamic_initializer_for__sv_master_share_game_socket__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_master_share_game_socket__()
{
  ConVar::ConVar(
    this: &sv_master_share_game_socket,
    pName: "sv_master_share_game_socket",
    pDefaultValue: "1",
    flags: 0,
    pHelpString: "Use the game's socket to communicate to the master server. If this is 0, then it will create a socket on -steamport "
    "+ 1 to communicate to the master server on.");
  return atexit(func: dynamic_atexit_destructor_for__sv_master_share_game_socket__);
}

//------------------------------------------------------------------------------
// Address: 0x10318AD0
// Name: _dynamic_initializer_for__sv_region__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_region__()
{
  ConVar::ConVar(
    this: &sv_region,
    pName: "sv_region",
    pDefaultValue: "-1",
    flags: 0x80000,
    pHelpString: "The region of the world to report this server in.");
  return atexit(func: dynamic_atexit_destructor_for__sv_region__);
}

//------------------------------------------------------------------------------
// Address: 0x10318B00
// Name: _dynamic_initializer_for__sv_instancebaselines__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_instancebaselines__()
{
  ConVar::ConVar(
    this: &sv_instancebaselines,
    pName: "sv_instancebaselines",
    pDefaultValue: "1",
    flags: 2,
    pHelpString: "Enable instanced baselines. Saves network overhead.");
  return atexit(func: dynamic_atexit_destructor_for__sv_instancebaselines__);
}

//------------------------------------------------------------------------------
// Address: 0x10318B60
// Name: _dynamic_initializer_for__sv_enableoldqueries__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_enableoldqueries__()
{
  ConVar::ConVar(
    this: &sv_enableoldqueries,
    pName: "sv_enableoldqueries",
    pDefaultValue: "0",
    flags: 0,
    pHelpString: "Enable support for old style (HL1) server queries");
  return atexit(func: dynamic_atexit_destructor_for__sv_enableoldqueries__);
}

//------------------------------------------------------------------------------
// Address: 0x10318B90
// Name: _dynamic_initializer_for__sv_password__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_password__()
{
  ConVar::ConVar(
    this: &sv_password,
    pName: "sv_password",
    pDefaultValue: defaultValue,
    flags: 655648,
    pHelpString: "Server password for entry into multiplayer games",
    callback: (void (__cdecl *)(IConVar *, const char *, float))SvPasswordChangeCallback);
  return atexit(func: dynamic_atexit_destructor_for__sv_password__);
}

//------------------------------------------------------------------------------
// Address: 0x10318BC0
// Name: _dynamic_initializer_for__sv_tags__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_tags__()
{
  ConVar::ConVar(
    this: &sv_tags,
    pName: "sv_tags",
    pDefaultValue: defaultValue,
    flags: 524544,
    pHelpString: "Server tags. Used to provide extra information to clients when they're browsing for servers. Separate tags with a comma.",
    callback: (void (__cdecl *)(IConVar *, const char *, float))SvTagsChangeCallback);
  return atexit(func: dynamic_atexit_destructor_for__sv_tags__);
}

//------------------------------------------------------------------------------
// Address: 0x10318BF0
// Name: _dynamic_initializer_for__sv_visiblemaxplayers__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_visiblemaxplayers__()
{
  ConVar::ConVar(
    this: &sv_visiblemaxplayers,
    pName: "sv_visiblemaxplayers",
    pDefaultValue: "-1",
    flags: 0x80000,
    pHelpString: "Overrides the max players reported to prospective clients");
  return atexit(func: dynamic_atexit_destructor_for__sv_visiblemaxplayers__);
}

//------------------------------------------------------------------------------
// Address: 0x10318C20
// Name: _dynamic_initializer_for__sv_alternateticks__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_alternateticks__()
{
  ConVar::ConVar(
    this: &sv_alternateticks,
    pName: "sv_alternateticks",
    pDefaultValue: "1",
    flags: 524352,
    pHelpString: "If set, server only simulates entities on even numbered ticks.\n");
  return atexit(func: dynamic_atexit_destructor_for__sv_alternateticks__);
}

//------------------------------------------------------------------------------
// Address: 0x10318C50
// Name: _dynamic_initializer_for__sv_allow_wait_command__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_allow_wait_command__()
{
  ConVar::ConVar(
    this: &sv_allow_wait_command,
    pName: "sv_allow_wait_command",
    pDefaultValue: "1",
    flags: 532480,
    pHelpString: "Allow or disallow the wait command on clients connected to this server.");
  return atexit(func: dynamic_atexit_destructor_for__sv_allow_wait_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10318C80
// Name: _dynamic_initializer_for__sv_allow_lobby_connect_only__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_allow_lobby_connect_only__()
{
  ConVar::ConVar(
    this: &sv_allow_lobby_connect_only,
    pName: "sv_allow_lobby_connect_only",
    pDefaultValue: "0",
    flags: 0x80000,
    pHelpString: "If set, players may only join this server from matchmaking lobby, may not connect directly.");
  return atexit(func: dynamic_atexit_destructor_for__sv_allow_lobby_connect_only__);
}

//------------------------------------------------------------------------------
// Address: 0x10318CB0
// Name: _dynamic_initializer_for__sv_reservation_timeout__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_reservation_timeout__()
{
  ConVar::ConVar(
    this: &sv_reservation_timeout,
    pName: "sv_reservation_timeout",
    pDefaultValue: "45",
    flags: 0x80000,
    pHelpString: "Time in seconds before lobby reservation expires.",
    bMin: true,
    fMin: 5.0,
    bMax: true,
    fMax: 180.0);
  return atexit(func: dynamic_atexit_destructor_for__sv_reservation_timeout__);
}

//------------------------------------------------------------------------------
// Address: 0x10318D00
// Name: _dynamic_initializer_for__sv_reservation_grace__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_reservation_grace__()
{
  ConVar::ConVar(
    this: &sv_reservation_grace,
    pName: "sv_reservation_grace",
    pDefaultValue: "5",
    flags: 0,
    pHelpString: "Time in seconds given for a lobby reservation.",
    bMin: true,
    fMin: 3.0,
    bMax: true,
    fMax: 30.0);
  return atexit(func: dynamic_atexit_destructor_for__sv_reservation_grace__);
}

//------------------------------------------------------------------------------
// Address: 0x10318D40
// Name: _dynamic_initializer_for__sv_steamgroup__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_steamgroup__()
{
  ConVar::ConVar(
    this: &sv_steamgroup,
    pName: "sv_steamgroup",
    pDefaultValue: defaultValue,
    flags: 524544,
    pHelpString: "The ID of the steam group that this server belongs to. You can find your group's ID on the admin profile page in the"
    " steam community.",
    callback: (void (__cdecl *)(IConVar *, const char *, float))SvGameDataChangeCallback);
  return atexit(func: dynamic_atexit_destructor_for__sv_steamgroup__);
}

//------------------------------------------------------------------------------
// Address: 0x10318D70
// Name: _dynamic_initializer_for__sv_steamgroup_exclusive__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_steamgroup_exclusive__()
{
  ConVar::ConVar(
    this: &sv_steamgroup_exclusive,
    pName: "sv_steamgroup_exclusive",
    pDefaultValue: "0",
    flags: 0x80000,
    pHelpString: "If set, only members of Steam group will be able to join the server when it's empty, public people will be able to j"
    "oin the server only if it has players.");
  return atexit(func: dynamic_atexit_destructor_for__sv_steamgroup_exclusive__);
}

//------------------------------------------------------------------------------
// Address: 0x10318DA0
// Name: _dynamic_initializer_for__sv_debugtempentities__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_debugtempentities__()
{
  ConVar::ConVar(
    this: &sv_debugtempentities,
    pName: "sv_debugtempentities",
    pDefaultValue: "0",
    flags: 0,
    pHelpString: "Show temp entity bandwidth usage.");
  return atexit(func: dynamic_atexit_destructor_for__sv_debugtempentities__);
}

//------------------------------------------------------------------------------
// Address: 0x10318DD0
// Name: _dynamic_initializer_for__sv_hosting_lobby__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_hosting_lobby__()
{
  ConVar::ConVar(this: &sv_hosting_lobby, pName: "sv_hosting_lobby", pDefaultValue: "0", flags: 8194);
  return atexit(func: dynamic_atexit_destructor_for__sv_hosting_lobby__);
}

//------------------------------------------------------------------------------
// Address: 0x10318E00
// Name: _dynamic_initializer_for__sv_showtags_command__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_showtags_command__()
{
  ConCommand::ConCommand(
    this: &sv_showtags_command,
    pName: "sv_showtags",
    callback: sv_showtags,
    pHelpString: "Describe current gametags.",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__sv_showtags_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10319B30
// Name: _dynamic_initializer_for__sv_logdownloadlist__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_logdownloadlist__()
{
  ConVar::ConVar(this: &sv_logdownloadlist, pName: "sv_logdownloadlist", pDefaultValue: "0", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__sv_logdownloadlist__);
}

//------------------------------------------------------------------------------
// Address: 0x10319C80
// Name: _dynamic_initializer_for__sv_new_delta_bits__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_new_delta_bits__()
{
  ConVar::ConVar(this: &sv_new_delta_bits, pName: "sv_new_delta_bits", pDefaultValue: "1", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__sv_new_delta_bits__);
}

//------------------------------------------------------------------------------
// Address: 0x1031BB00
// Name: _dynamic_initializer_for__sv_autosave__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_autosave__()
{
  ConVar::ConVar(
    this: &sv_autosave,
    pName: "sv_autosave",
    pDefaultValue: "1",
    flags: 0,
    pHelpString: "Set to 1 to autosave game on level transition. Does not affect autosave triggers.");
  return atexit(func: dynamic_atexit_destructor_for__sv_autosave__);
}

//------------------------------------------------------------------------------
// Address: 0x1031CF40
// Name: _dynamic_initializer_for__sv_maxroutable__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_maxroutable__()
{
  ConVar::ConVar(
    this: &sv_maxroutable,
    pName: "sv_maxroutable",
    pDefaultValue: "1200",
    flags: 0,
    pHelpString: "Server upper bound on net_maxroutable that a client can use.",
    bMin: true,
    fMin: 576.0,
    bMax: true,
    fMax: 1200.0);
  return atexit(func: dynamic_atexit_destructor_for__sv_maxroutable__);
}

//------------------------------------------------------------------------------
// Address: 0x1031D250
// Name: _dynamic_initializer_for__sv_dumpstringtables__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_dumpstringtables__()
{
  ConVar::ConVar(this: &sv_dumpstringtables, pName: "sv_dumpstringtables", pDefaultValue: "0", flags: 0x4000);
  return atexit(func: dynamic_atexit_destructor_for__sv_dumpstringtables__);
}

//------------------------------------------------------------------------------
// Address: 0x1031D5B0
// Name: _dynamic_initializer_for__sv_useexplicitdelete__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_useexplicitdelete__()
{
  ConVar::ConVar(
    this: &sv_useexplicitdelete,
    pName: "sv_useexplicitdelete",
    pDefaultValue: "1",
    flags: 2,
    pHelpString: "Explicitly delete dormant client entities caused by AllowImmediateReuse().");
  return atexit(func: dynamic_atexit_destructor_for__sv_useexplicitdelete__);
}

//------------------------------------------------------------------------------
// Address: 0x1031DCB0
// Name: _dynamic_initializer_for__sv_master_legacy_mode__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_master_legacy_mode__()
{
  ConVar::ConVar(
    this: &sv_master_legacy_mode,
    pName: "sv_master_legacy_mode",
    pDefaultValue: "1",
    flags: 0,
    pHelpString: "Use (outside-of-Steam) code to communicate with master servers.");
  return atexit(func: dynamic_atexit_destructor_for__sv_master_legacy_mode__);
}

//------------------------------------------------------------------------------
// Address: 0x1031DCE0
// Name: _dynamic_initializer_for__sv_search_key__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_search_key__()
{
  ConVar::ConVar(
    this: &sv_search_key,
    pName: "sv_search_key",
    pDefaultValue: "L4D360-rc3",
    flags: 0x80000,
    pHelpString: "When searching for a dedicated server from lobby, restrict search to only dedicated servers having the same sv_search_key.",
    callback: (void (__cdecl *)(IConVar *, const char *, float))SvGameDataChangeCallback);
  return atexit(func: dynamic_atexit_destructor_for__sv_search_key__);
}

//------------------------------------------------------------------------------
// Address: 0x103228B0
// Name: _dynamic_atexit_destructor_for__sv_unlockedchapters__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sv_unlockedchapters__()
{
  ConVar::~ConVar(this: &sv_unlockedchapters);
}

//------------------------------------------------------------------------------
// Address: 0x10324280
// Name: _dynamic_atexit_destructor_for__sv_maxupdaterate__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sv_maxupdaterate__()
{
  ConVar::~ConVar(this: &sv_maxupdaterate);
}

//------------------------------------------------------------------------------
// Address: 0x103245F0
// Name: _dynamic_atexit_destructor_for__sv_hibernate_postgame_delay__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sv_hibernate_postgame_delay__()
{
  ConVar::~ConVar(this: &sv_hibernate_postgame_delay);
}

//------------------------------------------------------------------------------
// Address: 0x10324610
// Name: _dynamic_atexit_destructor_for__sv_pausable_dev__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sv_pausable_dev__()
{
  ConVar::~ConVar(this: &sv_pausable_dev);
}

//------------------------------------------------------------------------------
// Address: 0x10324620
// Name: _dynamic_atexit_destructor_for__sv_pausable_dev_ds__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sv_pausable_dev_ds__()
{
  ConVar::~ConVar(this: &sv_pausable_dev_ds);
}

//------------------------------------------------------------------------------
// Address: 0x10324630
// Name: _dynamic_atexit_destructor_for__sv_pure__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sv_pure__()
{
  ConCommand::~ConCommand(this: &sv_pure);
}

//------------------------------------------------------------------------------
// Address: 0x10324640
// Name: _dynamic_atexit_destructor_for__sv_pure_kick_clients__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sv_pure_kick_clients__()
{
  ConVar::~ConVar(this: &sv_pure_kick_clients);
}

//------------------------------------------------------------------------------
// Address: 0x10324680
// Name: _dynamic_atexit_destructor_for__sv_pausable__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sv_pausable__()
{
  ConVar::~ConVar(this: &sv_pausable);
}

//------------------------------------------------------------------------------
// Address: 0x10324690
// Name: _dynamic_atexit_destructor_for__sv_contact__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sv_contact__()
{
  ConVar::~ConVar(this: &sv_contact);
}

//------------------------------------------------------------------------------
// Address: 0x103246A0
// Name: _dynamic_atexit_destructor_for__sv_cacheencodedents__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sv_cacheencodedents__()
{
  ConVar::~ConVar(this: &sv_cacheencodedents);
}

//------------------------------------------------------------------------------
// Address: 0x103246B0
// Name: _dynamic_atexit_destructor_for__sv_voicecodec__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sv_voicecodec__()
{
  ConVar::~ConVar(this: &sv_voicecodec);
}

//------------------------------------------------------------------------------
// Address: 0x103246C0
// Name: _dynamic_atexit_destructor_for__sv_voiceenable__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sv_voiceenable__()
{
  ConVar::~ConVar(this: &sv_voiceenable);
}

//------------------------------------------------------------------------------
// Address: 0x103246D0
// Name: _dynamic_atexit_destructor_for__sv_downloadurl__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sv_downloadurl__()
{
  ConVar::~ConVar(this: &sv_downloadurl);
}

//------------------------------------------------------------------------------
// Address: 0x103246E0
// Name: _dynamic_atexit_destructor_for__sv_consistency__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sv_consistency__()
{
  ConVar::~ConVar(this: &sv_consistency);
}

//------------------------------------------------------------------------------
// Address: 0x103246F0
// Name: _dynamic_atexit_destructor_for__sv_maxreplay__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sv_maxreplay__()
{
  ConVar::~ConVar(this: &sv_maxreplay);
}

//------------------------------------------------------------------------------
// Address: 0x10324700
// Name: _dynamic_atexit_destructor_for__sv_mincmdrate__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sv_mincmdrate__()
{
  ConVar::~ConVar(this: &sv_mincmdrate);
}

//------------------------------------------------------------------------------
// Address: 0x10324730
// Name: _dynamic_atexit_destructor_for__sv_client_min_interp_ratio__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sv_client_min_interp_ratio__()
{
  ConVar::~ConVar(this: &sv_client_min_interp_ratio);
}

//------------------------------------------------------------------------------
// Address: 0x103247A0
// Name: _dynamic_atexit_destructor_for__sv_memlimit__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sv_memlimit__()
{
  ConVar::~ConVar(this: &sv_memlimit);
}

//------------------------------------------------------------------------------
// Address: 0x103247B0
// Name: _dynamic_atexit_destructor_for__sv_shutdown__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sv_shutdown__()
{
  ConCommand::~ConCommand(this: &sv_shutdown);
}

//------------------------------------------------------------------------------
// Address: 0x103247C0
// Name: _dynamic_atexit_destructor_for__sv_parallel_sendsnapshot__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sv_parallel_sendsnapshot__()
{
  ConVar::~ConVar(this: &sv_parallel_sendsnapshot);
}

//------------------------------------------------------------------------------
// Address: 0x10324830
// Name: _dynamic_atexit_destructor_for__sv_validate_edict_change_infos__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sv_validate_edict_change_infos__()
{
  ConVar::~ConVar(this: &sv_validate_edict_change_infos);
}

//------------------------------------------------------------------------------
// Address: 0x10324850
// Name: _dynamic_atexit_destructor_for__sv_parallel_packentities__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sv_parallel_packentities__()
{
  ConVar::~ConVar(this: &sv_parallel_packentities);
}

//------------------------------------------------------------------------------
// Address: 0x103248F0
// Name: _dynamic_atexit_destructor_for__sv_forcepreload__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sv_forcepreload__()
{
  ConVar::~ConVar(this: &sv_forcepreload);
}

//------------------------------------------------------------------------------
// Address: 0x10324900
// Name: _dynamic_atexit_destructor_for__sv_precacheinfo_command__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sv_precacheinfo_command__()
{
  ConCommand::~ConCommand(this: &sv_precacheinfo_command);
}

//------------------------------------------------------------------------------
// Address: 0x10324A50
// Name: _dynamic_atexit_destructor_for__sv_master_share_game_socket__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sv_master_share_game_socket__()
{
  ConVar::~ConVar(this: &sv_master_share_game_socket);
}

//------------------------------------------------------------------------------
// Address: 0x10324AF0
// Name: _dynamic_atexit_destructor_for__sv_region__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sv_region__()
{
  ConVar::~ConVar(this: &sv_region);
}

//------------------------------------------------------------------------------
// Address: 0x10324B00
// Name: _dynamic_atexit_destructor_for__sv_instancebaselines__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sv_instancebaselines__()
{
  ConVar::~ConVar(this: &sv_instancebaselines);
}

//------------------------------------------------------------------------------
// Address: 0x10324B10
// Name: _dynamic_atexit_destructor_for__sv_stats__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sv_stats__()
{
  ConVar::~ConVar(this: &sv_stats);
}

//------------------------------------------------------------------------------
// Address: 0x10324B20
// Name: _dynamic_atexit_destructor_for__sv_enableoldqueries__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sv_enableoldqueries__()
{
  ConVar::~ConVar(this: &sv_enableoldqueries);
}

//------------------------------------------------------------------------------
// Address: 0x10324B30
// Name: _dynamic_atexit_destructor_for__sv_password__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sv_password__()
{
  ConVar::~ConVar(this: &sv_password);
}

//------------------------------------------------------------------------------
// Address: 0x10324B40
// Name: _dynamic_atexit_destructor_for__sv_tags__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sv_tags__()
{
  ConVar::~ConVar(this: &sv_tags);
}

//------------------------------------------------------------------------------
// Address: 0x10324B50
// Name: _dynamic_atexit_destructor_for__sv_visiblemaxplayers__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sv_visiblemaxplayers__()
{
  ConVar::~ConVar(this: &sv_visiblemaxplayers);
}

//------------------------------------------------------------------------------
// Address: 0x10324B60
// Name: _dynamic_atexit_destructor_for__sv_alternateticks__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sv_alternateticks__()
{
  ConVar::~ConVar(this: &sv_alternateticks);
}

//------------------------------------------------------------------------------
// Address: 0x10324B70
// Name: _dynamic_atexit_destructor_for__sv_allow_wait_command__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sv_allow_wait_command__()
{
  ConVar::~ConVar(this: &sv_allow_wait_command);
}

//------------------------------------------------------------------------------
// Address: 0x10324B80
// Name: _dynamic_atexit_destructor_for__sv_allow_lobby_connect_only__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sv_allow_lobby_connect_only__()
{
  ConVar::~ConVar(this: &sv_allow_lobby_connect_only);
}

//------------------------------------------------------------------------------
// Address: 0x10324B90
// Name: _dynamic_atexit_destructor_for__sv_reservation_timeout__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sv_reservation_timeout__()
{
  ConVar::~ConVar(this: &sv_reservation_timeout);
}

//------------------------------------------------------------------------------
// Address: 0x10324BA0
// Name: _dynamic_atexit_destructor_for__sv_reservation_grace__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sv_reservation_grace__()
{
  ConVar::~ConVar(this: &sv_reservation_grace);
}

//------------------------------------------------------------------------------
// Address: 0x10324BB0
// Name: _dynamic_atexit_destructor_for__sv_steamgroup__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sv_steamgroup__()
{
  ConVar::~ConVar(this: &sv_steamgroup);
}

//------------------------------------------------------------------------------
// Address: 0x10324BC0
// Name: _dynamic_atexit_destructor_for__sv_steamgroup_exclusive__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sv_steamgroup_exclusive__()
{
  ConVar::~ConVar(this: &sv_steamgroup_exclusive);
}

//------------------------------------------------------------------------------
// Address: 0x10324BD0
// Name: _dynamic_atexit_destructor_for__sv_debugtempentities__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sv_debugtempentities__()
{
  ConVar::~ConVar(this: &sv_debugtempentities);
}

//------------------------------------------------------------------------------
// Address: 0x10324BE0
// Name: _dynamic_atexit_destructor_for__sv_hosting_lobby__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sv_hosting_lobby__()
{
  ConVar::~ConVar(this: &sv_hosting_lobby);
}

//------------------------------------------------------------------------------
// Address: 0x10324BF0
// Name: _dynamic_atexit_destructor_for__sv_showtags_command__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sv_showtags_command__()
{
  ConCommand::~ConCommand(this: &sv_showtags_command);
}

//------------------------------------------------------------------------------
// Address: 0x10325090
// Name: _dynamic_atexit_destructor_for__sv_logdownloadlist__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sv_logdownloadlist__()
{
  ConVar::~ConVar(this: &sv_logdownloadlist);
}

//------------------------------------------------------------------------------
// Address: 0x10325110
// Name: _dynamic_atexit_destructor_for__sv_new_delta_bits__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sv_new_delta_bits__()
{
  ConVar::~ConVar(this: &sv_new_delta_bits);
}

//------------------------------------------------------------------------------
// Address: 0x10325D20
// Name: _dynamic_atexit_destructor_for__sv_autosave__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sv_autosave__()
{
  ConVar::~ConVar(this: &sv_autosave);
}

//------------------------------------------------------------------------------
// Address: 0x10326540
// Name: _dynamic_atexit_destructor_for__sv_maxroutable__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sv_maxroutable__()
{
  ConVar::~ConVar(this: &sv_maxroutable);
}

//------------------------------------------------------------------------------
// Address: 0x10326710
// Name: _dynamic_atexit_destructor_for__sv_dumpstringtables__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sv_dumpstringtables__()
{
  ConVar::~ConVar(this: &sv_dumpstringtables);
}

//------------------------------------------------------------------------------
// Address: 0x10326810
// Name: _dynamic_atexit_destructor_for__sv_useexplicitdelete__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sv_useexplicitdelete__()
{
  ConVar::~ConVar(this: &sv_useexplicitdelete);
}

//------------------------------------------------------------------------------
// Address: 0x10326A90
// Name: _dynamic_atexit_destructor_for__sv_master_legacy_mode__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sv_master_legacy_mode__()
{
  ConVar::~ConVar(this: &sv_master_legacy_mode);
}

//------------------------------------------------------------------------------
// Address: 0x10326AA0
// Name: _dynamic_atexit_destructor_for__sv_search_key__
// Source: semantic_dyn_pfx_sv
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sv_search_key__()
{
  ConVar::~ConVar(this: &sv_search_key);
}

//------------------------------------------------------------------------------
// Address: 0x10313590
// Name: _dynamic_initializer_for__tv_nochat__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__tv_nochat__()
{
  ConVar::ConVar(
    this: &tv_nochat,
    pName: "tv_nochat",
    pDefaultValue: "0",
    flags: 640,
    pHelpString: "Don't receive chat messages from other SourceTV spectators");
  return atexit(func: dynamic_atexit_destructor_for__tv_nochat__);
}

//------------------------------------------------------------------------------
// Address: 0x103174A0
// Name: _dynamic_initializer_for__ss_voice_hearpartner__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__ss_voice_hearpartner__()
{
  ConVar::ConVar(
    this: &ss_voice_hearpartner,
    pName: "ss_voice_hearpartner",
    pDefaultValue: "0",
    flags: 0,
    pHelpString: "Route voice between splitscreen players on same system.");
  return atexit(func: dynamic_atexit_destructor_for__ss_voice_hearpartner__);
}

//------------------------------------------------------------------------------
// Address: 0x103175F0
// Name: _dynamic_initializer_for__g_Tracks__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_Tracks__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_Tracks__);
}

//------------------------------------------------------------------------------
// Address: 0x10317630
// Name: _dynamic_initializer_for__g_IPFilters__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_IPFilters__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_IPFilters__);
}

//------------------------------------------------------------------------------
// Address: 0x10317640
// Name: _dynamic_initializer_for__g_UserFilters__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_UserFilters__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_UserFilters__);
}

//------------------------------------------------------------------------------
// Address: 0x10317650
// Name: _dynamic_initializer_for__addip__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__addip__()
{
  ConCommand::ConCommand(
    this: &addip,
    pName: "addip",
    callback: (void (__cdecl *)())Filter_Add_f,
    pHelpString: "Add an IP address to the ban list.",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__addip__);
}

//------------------------------------------------------------------------------
// Address: 0x10317680
// Name: _dynamic_initializer_for__banip__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__banip__()
{
  ConCommand::ConCommand(
    this: &banip,
    pName: "banip",
    callback: (void (__cdecl *)())Filter_Add_f,
    pHelpString: "Add an IP address to the ban list.",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__banip__);
}

//------------------------------------------------------------------------------
// Address: 0x103177A0
// Name: _dynamic_initializer_for__listid_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__listid_command__()
{
  ConCommand::ConCommand(
    this: &listid_command,
    pName: "listid",
    callback: (void (__cdecl *)())listid,
    pHelpString: "Lists banned users.",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__listid_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10317B10
// Name: _dynamic_initializer_for__log_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__log_command__()
{
  ConCommand::ConCommand(
    this: &log_command,
    pName: "log",
    callback: (void (__cdecl *)())log,
    pHelpString: "Enables logging to file, console, and udp < on | off >.",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__log_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10317B40
// Name: _dynamic_initializer_for__logaddress_add_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__logaddress_add_command__()
{
  ConCommand::ConCommand(
    this: &logaddress_add_command,
    pName: "logaddress_add",
    callback: (void (__cdecl *)())logaddress_add,
    pHelpString: "Set address and port for remote host <ip:port>.",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__logaddress_add_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10317B70
// Name: _dynamic_initializer_for__logaddress_delall_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__logaddress_delall_command__()
{
  ConCommand::ConCommand(
    this: &logaddress_delall_command,
    pName: "logaddress_delall",
    callback: (void (__cdecl *)())logaddress_delall,
    pHelpString: "Remove all udp addresses being logged to",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__logaddress_delall_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10318110
// Name: _dynamic_initializer_for__tv_enable__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__tv_enable__()
{
  ConVar::ConVar(
    this: &tv_enable,
    pName: "tv_enable",
    pDefaultValue: "0",
    flags: 256,
    pHelpString: "Activates SourceTV on server.",
    callback: (void (__cdecl *)(IConVar *, const char *, float))OnTVEnablehanged);
  return atexit(func: dynamic_atexit_destructor_for__tv_enable__);
}

//------------------------------------------------------------------------------
// Address: 0x10318690
// Name: _dynamic_initializer_for__g_RCONServer__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_RCONServer__()
{
  CSocketCreator::CSocketCreator(this: &g_RCONServer.m_Socket, pListener: &g_RCONServer);
  g_RCONServer.m_failedRcons.m_Memory.m_pMemory = nullptr;
  g_RCONServer.m_failedRcons.m_Memory.m_nAllocationCount = 0;
  g_RCONServer.m_failedRcons.m_Memory.m_nGrowSize = 0;
  g_RCONServer.m_failedRcons.m_Size = 0;
  g_RCONServer.m_failedRcons.m_pElements = nullptr;
  CUtlString::CUtlString(this: &g_RCONServer.m_Password);
  netadr_s::SetIP(this: &g_RCONServer.m_Address, unIP: 0);
  netadr_s::SetPort(this: &g_RCONServer.m_Address, newport: 0);
  netadr_s::SetType(this: &g_RCONServer.m_Address, newtype: NA_IP);
  return atexit(func: dynamic_atexit_destructor_for__g_RCONServer__);
}

//------------------------------------------------------------------------------
// Address: 0x10318700
// Name: _dynamic_initializer_for__g_RPTServer__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_RPTServer__()
{
  CSocketCreator::CSocketCreator(this: &g_RPTServer.m_Socket, pListener: &g_RPTServer);
  g_RPTServer.m_failedRcons.m_Memory.m_pMemory = nullptr;
  g_RPTServer.m_failedRcons.m_Memory.m_nAllocationCount = 0;
  g_RPTServer.m_failedRcons.m_Memory.m_nGrowSize = 0;
  g_RPTServer.m_failedRcons.m_Size = 0;
  g_RPTServer.m_failedRcons.m_pElements = nullptr;
  CUtlString::CUtlString(this: &g_RPTServer.m_Password);
  netadr_s::SetIP(this: &g_RPTServer.m_Address, unIP: 0);
  netadr_s::SetPort(this: &g_RPTServer.m_Address, newport: 0);
  netadr_s::SetType(this: &g_RPTServer.m_Address, newtype: NA_IP);
  g_RPTServer.__vftable = (CRPTServer_vtbl *)&CRPTServer::`vftable';
  return atexit(func: dynamic_atexit_destructor_for__g_RPTServer__);
}

//------------------------------------------------------------------------------
// Address: 0x103188E0
// Name: _dynamic_initializer_for__g_ServerRemoteAccess__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_ServerRemoteAccess__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_ServerRemoteAccess__);
}

//------------------------------------------------------------------------------
// Address: 0x103188F0
// Name: _dynamic_initializer_for____g_CreateCServerRemoteAccessIGameServerData_reg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
InterfaceReg *dynamic_initializer_for____g_CreateCServerRemoteAccessIGameServerData_reg__()
{
  return InterfaceReg::InterfaceReg(
           this: &_g_CreateCServerRemoteAccessIGameServerData_reg,
           fn: _CreateCServerRemoteAccessIGameServerData_interface,
           pName: "GameServerData001");
}

//------------------------------------------------------------------------------
// Address: 0x10319B60
// Name: _dynamic_initializer_for__g_CV_DTWatchEnt__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CV_DTWatchEnt__()
{
  ConVar::ConVar(
    this: &g_CV_DTWatchEnt,
    pName: "dtwatchent",
    pDefaultValue: "-1",
    flags: 0,
    pHelpString: "Watch this entities data table encoding.");
  return atexit(func: dynamic_atexit_destructor_for__g_CV_DTWatchEnt__);
}

//------------------------------------------------------------------------------
// Address: 0x10319B90
// Name: _dynamic_initializer_for__g_CV_DTWatchVar__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CV_DTWatchVar__()
{
  ConVar::ConVar(
    this: &g_CV_DTWatchVar,
    pName: "dtwatchvar",
    pDefaultValue: defaultValue,
    flags: 0,
    pHelpString: "Watch the named variable.");
  return atexit(func: dynamic_atexit_destructor_for__g_CV_DTWatchVar__);
}

//------------------------------------------------------------------------------
// Address: 0x10319BC0
// Name: _dynamic_initializer_for__g_CV_DTWarning__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CV_DTWarning__()
{
  ConVar::ConVar(
    this: &g_CV_DTWarning,
    pName: "dtwarning",
    pDefaultValue: "0",
    flags: 0,
    pHelpString: "Print data table warnings?");
  return atexit(func: dynamic_atexit_destructor_for__g_CV_DTWarning__);
}

//------------------------------------------------------------------------------
// Address: 0x10319BF0
// Name: _dynamic_initializer_for__g_CV_DTWatchClass__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CV_DTWatchClass__()
{
  ConVar::ConVar(
    this: &g_CV_DTWatchClass,
    pName: "dtwatchclass",
    pDefaultValue: defaultValue,
    flags: 0,
    pHelpString: "Watch all fields encoded with this table.");
  return atexit(func: dynamic_atexit_destructor_for__g_CV_DTWatchClass__);
}

//------------------------------------------------------------------------------
// Address: 0x10319C20
// Name: _dynamic_initializer_for__g_CV_DTEncode__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CV_DTEncode__()
{
  ConVar::ConVar(
    this: &g_CV_DTEncode,
    pName: "dtwatchencode",
    pDefaultValue: "1",
    flags: 0,
    pHelpString: "When watching show encode.");
  return atexit(func: dynamic_atexit_destructor_for__g_CV_DTEncode__);
}

//------------------------------------------------------------------------------
// Address: 0x10319C50
// Name: _dynamic_initializer_for__g_CV_DTDecode__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CV_DTDecode__()
{
  ConVar::ConVar(
    this: &g_CV_DTDecode,
    pName: "dtwatchdecode",
    pDefaultValue: "1",
    flags: 0,
    pHelpString: "When watching show decode.");
  return atexit(func: dynamic_atexit_destructor_for__g_CV_DTDecode__);
}

//------------------------------------------------------------------------------
// Address: 0x10319CB0
// Name: _dynamic_initializer_for__g_DTIRecvTables__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_DTIRecvTables__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_DTIRecvTables__);
}

//------------------------------------------------------------------------------
// Address: 0x10319CC0
// Name: _dynamic_initializer_for__g_DTISendTables__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_DTISendTables__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_DTISendTables__);
}

//------------------------------------------------------------------------------
// Address: 0x1031D5E0
// Name: _dynamic_initializer_for____g_CreateCEngineUniformRandomStreamIUniformRandomStream_reg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
InterfaceReg *dynamic_initializer_for____g_CreateCEngineUniformRandomStreamIUniformRandomStream_reg__()
{
  return InterfaceReg::InterfaceReg(
           this: &_g_CreateCEngineUniformRandomStreamIUniformRandomStream_reg,
           fn: (void *(__cdecl *)())_CreateCEngineUniformRandomStreamIUniformRandomStream_interface,
           pName: "VEngineRandom001");
}

//------------------------------------------------------------------------------
// Address: 0x1031D600
// Name: _dynamic_initializer_for__g_Registry__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_Registry__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_Registry__);
}

//------------------------------------------------------------------------------
// Address: 0x1031DD10
// Name: _dynamic_initializer_for__xlsp_force_dc_name__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__xlsp_force_dc_name__()
{
  ConVar::ConVar(
    this: &xlsp_force_dc_name,
    pName: "xlsp_force_dc_name",
    pDefaultValue: defaultValue,
    flags: 0,
    pHelpString: "Restrict to xlsp datacenter by name.");
  return atexit(func: dynamic_atexit_destructor_for__xlsp_force_dc_name__);
}

//------------------------------------------------------------------------------
// Address: 0x1031DD40
// Name: _dynamic_initializer_for__mm_heartbeat_timeout__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mm_heartbeat_timeout__()
{
  ConVar::ConVar(this: &mm_heartbeat_timeout, pName: "mm_heartbeat_timeout", pDefaultValue: "10", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__mm_heartbeat_timeout__);
}

//------------------------------------------------------------------------------
// Address: 0x1031DD70
// Name: _dynamic_initializer_for__mm_heartbeat_seconds__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mm_heartbeat_seconds__()
{
  ConVar::ConVar(this: &mm_heartbeat_seconds, pName: "mm_heartbeat_seconds", pDefaultValue: "300", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__mm_heartbeat_seconds__);
}

//------------------------------------------------------------------------------
// Address: 0x1031DDA0
// Name: _dynamic_initializer_for__mm_heartbeat_seconds_xlsp__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mm_heartbeat_seconds_xlsp__()
{
  ConVar::ConVar(this: &mm_heartbeat_seconds_xlsp, pName: "mm_heartbeat_seconds_xlsp", pDefaultValue: "60", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__mm_heartbeat_seconds_xlsp__);
}

//------------------------------------------------------------------------------
// Address: 0x1031DDD0
// Name: _dynamic_initializer_for__mm_heartbeat_timeout_legacy__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mm_heartbeat_timeout_legacy__()
{
  ConVar::ConVar(
    this: &mm_heartbeat_timeout_legacy,
    pName: "mm_heartbeat_timeout_legacy",
    pDefaultValue: "15",
    flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__mm_heartbeat_timeout_legacy__);
}

//------------------------------------------------------------------------------
// Address: 0x103228C0
// Name: _dynamic_atexit_destructor_for__tv_nochat__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__tv_nochat__()
{
  ConVar::~ConVar(this: &tv_nochat);
}

//------------------------------------------------------------------------------
// Address: 0x103243C0
// Name: _dynamic_atexit_destructor_for__banip__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__banip__()
{
  ConCommand::~ConCommand(this: &banip);
}

//------------------------------------------------------------------------------
// Address: 0x103243D0
// Name: _dynamic_atexit_destructor_for__removeip_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__removeip_command__()
{
  ConCommand::~ConCommand(this: &removeip_command);
}

//------------------------------------------------------------------------------
// Address: 0x10324420
// Name: _dynamic_atexit_destructor_for__listid_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__listid_command__()
{
  ConCommand::~ConCommand(this: &listid_command);
}

//------------------------------------------------------------------------------
// Address: 0x10324590
// Name: _dynamic_atexit_destructor_for__g_Log__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_Log__()
{
  g_Log.__vftable = (CLog_vtbl *)&CLog::`vftable';
  g_Log.m_nDebugID = 13;
  CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&g_Log.m_LogAddresses);
  g_Log.__vftable = (CLog_vtbl *)&IGameEventListener2::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x10324C00
// Name: _EngineBitBufErrorHandler_::_5_::_dynamic_atexit_destructor_for__errorNames__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl EngineBitBufErrorHandler_::_5_::_dynamic_atexit_destructor_for__errorNames__()
{
  CUtlSymbolTable *v0; // esi
  int i; // edi

  v0 = (CUtlSymbolTable *)&_S1_14;
  for ( i = 1; i >= 0; --i )
    CUtlSymbolTable::~CUtlSymbolTable(this: --v0);
}

//------------------------------------------------------------------------------
// Address: 0x103250A0
// Name: _dynamic_atexit_destructor_for__g_DownloadListGenerator__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_DownloadListGenerator__()
{
  CUtlSymbolTable::~CUtlSymbolTable(this: &g_DownloadListGenerator.m_AlreadyWrittenFileNames);
}

//------------------------------------------------------------------------------
// Address: 0x103250B0
// Name: _dynamic_atexit_destructor_for__g_CV_DTWatchEnt__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CV_DTWatchEnt__()
{
  ConVar::~ConVar(this: &g_CV_DTWatchEnt);
}

//------------------------------------------------------------------------------
// Address: 0x103250C0
// Name: _dynamic_atexit_destructor_for__g_CV_DTWatchVar__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CV_DTWatchVar__()
{
  ConVar::~ConVar(this: &g_CV_DTWatchVar);
}

//------------------------------------------------------------------------------
// Address: 0x103250D0
// Name: _dynamic_atexit_destructor_for__g_CV_DTWarning__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CV_DTWarning__()
{
  ConVar::~ConVar(this: &g_CV_DTWarning);
}

//------------------------------------------------------------------------------
// Address: 0x103250E0
// Name: _dynamic_atexit_destructor_for__g_CV_DTWatchClass__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CV_DTWatchClass__()
{
  ConVar::~ConVar(this: &g_CV_DTWatchClass);
}

//------------------------------------------------------------------------------
// Address: 0x103250F0
// Name: _dynamic_atexit_destructor_for__g_CV_DTEncode__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CV_DTEncode__()
{
  ConVar::~ConVar(this: &g_CV_DTEncode);
}

//------------------------------------------------------------------------------
// Address: 0x10325100
// Name: _dynamic_atexit_destructor_for__g_CV_DTDecode__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CV_DTDecode__()
{
  ConVar::~ConVar(this: &g_CV_DTDecode);
}

//------------------------------------------------------------------------------
// Address: 0x10325120
// Name: _dynamic_atexit_destructor_for__g_DTIRecvTables__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_DTIRecvTables__()
{
  CUtlLinkedList<vgui::TreeNode *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int>>::RemoveAll(this: (CUtlLinkedList<vgui::TreeNode *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int> > *)&g_DTIRecvTables);
  if ( g_DTIRecvTables.m_Memory.m_nGrowSize >= 0 )
  {
    if ( g_DTIRecvTables.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: g_DTIRecvTables.m_Memory.m_pMemory);
      g_DTIRecvTables.m_Memory.m_pMemory = nullptr;
    }
    g_DTIRecvTables.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10325170
// Name: _dynamic_atexit_destructor_for__g_DTISendTables__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_DTISendTables__()
{
  CUtlLinkedList<CFrameSnapshot *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CFrameSnapshot *,unsigned short>,unsigned short>>::RemoveAll(this: (CUtlLinkedList<unsigned int,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<unsigned int,unsigned short>,unsigned short> > *)&g_DTISendTables);
  if ( g_DTISendTables.m_Memory.m_nGrowSize >= 0 )
  {
    if ( g_DTISendTables.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: g_DTISendTables.m_Memory.m_pMemory);
      g_DTISendTables.m_Memory.m_pMemory = nullptr;
    }
    g_DTISendTables.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10326820
// Name: _dynamic_atexit_destructor_for__g_Registry__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_Registry__()
{
  g_Registry.__vftable = (CRegistry_vtbl *)&CRegistry::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x10326AB0
// Name: _dynamic_atexit_destructor_for__xlsp_force_dc_name__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__xlsp_force_dc_name__()
{
  ConVar::~ConVar(this: &xlsp_force_dc_name);
}

//------------------------------------------------------------------------------
// Address: 0x10326AC0
// Name: _dynamic_atexit_destructor_for__mm_heartbeat_timeout__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mm_heartbeat_timeout__()
{
  ConVar::~ConVar(this: &mm_heartbeat_timeout);
}

//------------------------------------------------------------------------------
// Address: 0x10326AD0
// Name: _dynamic_atexit_destructor_for__mm_heartbeat_seconds__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mm_heartbeat_seconds__()
{
  ConVar::~ConVar(this: &mm_heartbeat_seconds);
}

//------------------------------------------------------------------------------
// Address: 0x10326AE0
// Name: _dynamic_atexit_destructor_for__mm_heartbeat_seconds_xlsp__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mm_heartbeat_seconds_xlsp__()
{
  ConVar::~ConVar(this: &mm_heartbeat_seconds_xlsp);
}

//------------------------------------------------------------------------------
// Address: 0x10326AF0
// Name: _dynamic_atexit_destructor_for__mm_heartbeat_timeout_legacy__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mm_heartbeat_timeout_legacy__()
{
  ConVar::~ConVar(this: &mm_heartbeat_timeout_legacy);
}

//------------------------------------------------------------------------------
// Address: 0x10326B00
// Name: _dynamic_atexit_destructor_for__pingserver_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__pingserver_command__()
{
  ConCommand::~ConCommand(this: &pingserver_command);
}

} // namespace engine_xlsp
