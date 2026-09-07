// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/gameinterface.cpp
// Functions: 121
// ============================================================

#include "game\server\gameinterface.h"

//------------------------------------------------------------------------------
// Address: 0x10024560
// Name: public: virtual int CRefCounted1<class CFunctor,class CRefCountServiceBase<1,class CRefMT>>::AddRef(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>::AddRef(
        CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> > *this)
{
  return _InterlockedIncrement(&this->m_iRefs);
}

//------------------------------------------------------------------------------
// Address: 0x10024570
// Name: public: virtual int CRefCounted1<class CFunctor,class CRefCountServiceBase<1,class CRefMT>>::Release(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>::Release(
        CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> > *this)
{
  CRefCountServiceBase<1,CRefMT> *v1; // esi
  int result; // eax

  v1 = &this->CRefCountServiceBase<1,CRefMT>;
  result = _InterlockedDecrement(&this->m_iRefs);
  if ( result == 0 )
  {
    if ( v1->OnFinalRelease(this: v1) )
      ((void (__thiscall *)(CRefCountServiceBase<1,CRefMT> *, int))v1->dtr_CRefCountServiceBase<1,CRefMT>)(
        a1: v1,
        a2: 1);
    return 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1013F490
// Name: public: void bf_write::WriteUBitLong(unsigned int,int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall bf_write::WriteUBitLong(bf_write *this, unsigned int curData, int numbits, bool bCheckRange)
{
  int m_iCurBit; // ecx
  int m_nDataBits; // eax
  int v7; // edx
  int v8; // ecx
  int v9; // edx

  m_iCurBit = this->m_iCurBit;
  m_nDataBits = this->m_nDataBits;
  if ( m_iCurBit + numbits <= m_nDataBits )
  {
    v7 = m_iCurBit;
    v8 = m_iCurBit & 0x1F;
    v9 = v7 >> 5;
    *(_DWORD *)&this->m_pData[4 * v9] = (curData << v8)
                                      | *(_DWORD *)&this->m_pData[4 * v9] & g_BitWriteMasks[0][32 * v8 + v8 + numbits];
    if ( 32 - v8 < numbits )
      *(_DWORD *)&this->m_pData[4 * v9 + 4] = (curData >> (32 - v8))
                                            | *(_DWORD *)&this->m_pData[4 * v9 + 4]
                                            & g_BitWriteMasks[0][numbits - (32 - v8)];
    this->m_iCurBit += numbits;
  }
  else
  {
    this->m_iCurBit = m_nDataBits;
    this->m_bOverflow = true;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1013F550
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
// Address: 0x1013F6A0
// Name: public: bool CSteamGameServerAPIContext::Init(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CSteamGameServerAPIContext::Init(CSteamGameServerAPIContext *this)
{
  int HSteamUser; // ebx
  int HSteamPipe; // esi
  ISteamGameServer *v5; // eax
  ISteamUtils *v6; // eax
  ISteamMasterServerUpdater *v7; // eax
  ISteamNetworking *v8; // eax
  ISteamGameServerStats *v9; // eax

  if ( _g_pSteamClientGameServer == nullptr )
    return false;
  HSteamUser = _SteamGameServer_GetHSteamUser();
  HSteamPipe = _SteamGameServer_GetHSteamPipe();
  v5 = _g_pSteamClientGameServer->GetISteamGameServer(
         this: _g_pSteamClientGameServer,
         a2: HSteamUser,
         a3: HSteamPipe,
         a4: "SteamGameServer010");
  this->m_pSteamGameServer = v5;
  if ( v5 == nullptr )
    return false;
  v6 = _g_pSteamClientGameServer->GetISteamUtils(this: _g_pSteamClientGameServer, a2: HSteamPipe, a3: "SteamUtils005");
  this->m_pSteamGameServerUtils = v6;
  if ( v6 == nullptr )
    return false;
  v7 = _g_pSteamClientGameServer->GetISteamMasterServerUpdater(
         this: _g_pSteamClientGameServer,
         a2: HSteamUser,
         a3: HSteamPipe,
         a4: "SteamMasterServerUpdater001");
  this->m_pSteamMasterServerUpdater = v7;
  if ( v7 == nullptr )
    return false;
  v8 = _g_pSteamClientGameServer->GetISteamNetworking(
         this: _g_pSteamClientGameServer,
         a2: HSteamUser,
         a3: HSteamPipe,
         a4: "SteamNetworking005");
  this->m_pSteamGameServerNetworking = v8;
  if ( v8 == nullptr )
    return false;
  v9 = _g_pSteamClientGameServer->GetISteamGameServerStats(
         this: _g_pSteamClientGameServer,
         a2: HSteamUser,
         a3: HSteamPipe,
         a4: "SteamGameServerStats001");
  this->m_pSteamGameServerStats = v9;
  return v9 != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1013F7C0
// Name: public: class IChangeInfoAccessor __near * CBaseEdict::GetChangeAccessor(void)
// Source: json
//------------------------------------------------------------------------------
IChangeInfoAccessor *__thiscall CBaseEdict::GetChangeAccessor(CBaseEdict *this)
{
  return engine->GetChangeAccessor(this: engine, a2: (const edict_t *)this);
}

//------------------------------------------------------------------------------
// Address: 0x1013F7E0
// Name: void ClientPutInServerOverride(class CBasePlayer __near * (*)(struct edict_t __near *,char const __near *))
// Source: json
//------------------------------------------------------------------------------
void __cdecl ClientPutInServerOverride(CBasePlayer *(__cdecl *fn)(edict_t *, const char *))
{
  g_pClientPutInServerOverride = fn;
}

//------------------------------------------------------------------------------
// Address: 0x1013F7F0
// Name: int UTIL_GetCommandClientIndex(void)
// Source: json
//------------------------------------------------------------------------------
int __cdecl UTIL_GetCommandClientIndex()
{
  return g_nCommandClientIndex + 1;
}

//------------------------------------------------------------------------------
// Address: 0x1013F800
// Name: class CBasePlayer __near * UTIL_GetCommandClient(void)
// Source: json
//------------------------------------------------------------------------------
CBasePlayer *__cdecl UTIL_GetCommandClient()
{
  if ( g_nCommandClientIndex + 1 <= 0 )
    return nullptr;
  else
    return UTIL_PlayerByIndex(playerIndex: g_nCommandClientIndex + 1);
}

//------------------------------------------------------------------------------
// Address: 0x1013F820
// Name: InitGameSystems
// Source: json
//------------------------------------------------------------------------------
char __usercall InitGameSystems@<al>(const char *a1@<ebx>, void *(__cdecl *appSystemFactory)(const char *, int *))
{
  IGameSystem *v2; // eax
  IGameSystem *v3; // eax
  CPostFrameNavigationHook *v4; // eax
  CEventLog *v5; // eax
  IGameSystem *v6; // eax
  IGameSystem *v7; // eax
  IGameSystem *v8; // eax

  v2 = GameStringSystem();
  IGameSystem::Add(pSys: v2);
  v3 = PhysicsGameSystem();
  IGameSystem::Add(pSys: v3);
  IGameSystem::Add(pSys: g_pPrecacheRegister);
  v4 = PostFrameNavigationSystem();
  IGameSystem::Add(pSys: v4);
  v5 = GameLogSystem();
  if ( v5 != nullptr )
    v6 = &v5->CBaseGameSystem;
  else
    v6 = nullptr;
  IGameSystem::Add(pSys: v6);
  v7 = HLTVDirectorSystem();
  IGameSystem::Add(pSys: v7);
  v8 = SoundEmitterSystem();
  IGameSystem::Add(pSys: v8);
  if ( enginevgui != nullptr && !VGui_Startup(appSystemFactory) )
    return 0;
  gameeventmanager->LoadEventsFromFile(this: gameeventmanager, a2: "resource/ModEvents.res");
  InstallBotControl();
  if ( !IGameSystem::InitAllSystems() || ModelSoundsCacheInit(a1) == 0 )
    return 0;
  InvalidateQueryCache();
  TheNavMesh = NavMeshFactory();
  gamestatsuploader->InitConnection(this: gamestatsuploader);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1013F900
// Name: public: virtual void CServerGameDLL::PostInit(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CServerGameDLL::PostInit(CServerGameDLL *this)
{
  IGameSystem::PostInitAllSystems();
  if ( !engine->IsDedicatedServer(this: engine) && enginevgui != nullptr )
    VGui_PostInit();
}

//------------------------------------------------------------------------------
// Address: 0x1013F930
// Name: public: virtual void CServerGameDLL::PostToolsInit(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CServerGameDLL::PostToolsInit(CServerGameDLL *this)
{
  if ( serverenginetools != nullptr )
    serverfoundry = (IServerFoundry *)serverenginetools->QueryInterface(
                                        this: serverenginetools,
                                        a2: "VSERVERFOUNDRY001");
}

//------------------------------------------------------------------------------
// Address: 0x1013F950
// Name: public: virtual void CServerGameDLL::DLLShutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CServerGameDLL::DLLShutdown(CServerGameDLL *this)
{
  ISaveRestoreBlockSet_vtbl *v1; // esi
  ISaveRestoreBlockHandler *VScriptSaveRestoreBlockHandler; // eax
  ISaveRestoreBlockSet_vtbl *v3; // esi
  ISaveRestoreBlockHandler *CommentarySaveRestoreBlockHandler; // eax
  ISaveRestoreBlockSet_vtbl *v5; // esi
  ISaveRestoreBlockHandler *EventQueueSaveRestoreBlockHandler; // eax
  ISaveRestoreBlockSet_vtbl *v7; // esi
  ISaveRestoreBlockHandler *v8; // eax
  ISaveRestoreBlockSet_vtbl *v9; // esi
  ISaveRestoreBlockHandler *TemplateSaveRestoreBlockHandler; // eax
  ISaveRestoreBlockSet_vtbl *v11; // esi
  ISaveRestoreBlockHandler *AISaveRestoreBlockHandler; // eax
  ISaveRestoreBlockSet_vtbl *v13; // esi
  ISaveRestoreBlockHandler *PhysSaveRestoreBlockHandler; // eax
  ISaveRestoreBlockSet_vtbl *v15; // esi
  ISaveRestoreBlockHandler *EntitySaveRestoreBlockHandler; // eax
  vgui::Panel *v17; // eax
  vgui::Panel *v18; // ecx

  ModelSoundsCacheShutdown();
  v1 = g_pGameSaveRestoreBlockSet->__vftable;
  VScriptSaveRestoreBlockHandler = GetVScriptSaveRestoreBlockHandler();
  v1->RemoveBlockHandler(this: g_pGameSaveRestoreBlockSet, a2: VScriptSaveRestoreBlockHandler);
  v3 = g_pGameSaveRestoreBlockSet->__vftable;
  CommentarySaveRestoreBlockHandler = GetCommentarySaveRestoreBlockHandler();
  v3->RemoveBlockHandler(this: g_pGameSaveRestoreBlockSet, a2: CommentarySaveRestoreBlockHandler);
  v5 = g_pGameSaveRestoreBlockSet->__vftable;
  EventQueueSaveRestoreBlockHandler = GetEventQueueSaveRestoreBlockHandler();
  v5->RemoveBlockHandler(this: g_pGameSaveRestoreBlockSet, a2: EventQueueSaveRestoreBlockHandler);
  v7 = g_pGameSaveRestoreBlockSet->__vftable;
  v8 = GetDefaultResponseSystemSaveRestoreBlockHandler();
  v7->RemoveBlockHandler(this: g_pGameSaveRestoreBlockSet, a2: v8);
  v9 = g_pGameSaveRestoreBlockSet->__vftable;
  TemplateSaveRestoreBlockHandler = GetTemplateSaveRestoreBlockHandler();
  v9->RemoveBlockHandler(this: g_pGameSaveRestoreBlockSet, a2: TemplateSaveRestoreBlockHandler);
  v11 = g_pGameSaveRestoreBlockSet->__vftable;
  AISaveRestoreBlockHandler = GetAISaveRestoreBlockHandler();
  v11->RemoveBlockHandler(this: g_pGameSaveRestoreBlockSet, a2: AISaveRestoreBlockHandler);
  v13 = g_pGameSaveRestoreBlockSet->__vftable;
  PhysSaveRestoreBlockHandler = GetPhysSaveRestoreBlockHandler();
  v13->RemoveBlockHandler(this: g_pGameSaveRestoreBlockSet, a2: PhysSaveRestoreBlockHandler);
  v15 = g_pGameSaveRestoreBlockSet->__vftable;
  EntitySaveRestoreBlockHandler = GetEntitySaveRestoreBlockHandler();
  v15->RemoveBlockHandler(this: g_pGameSaveRestoreBlockSet, a2: EntitySaveRestoreBlockHandler);
  v17 = CBasePlayer::ActivePlayerCombatCharacter(this: (vgui::Panel *)&g_TextStatsMgr);
  if ( v17 == nullptr || LOBYTE(v17->__vftable) == 0 )
    CTextStatsMgr::SetStatsFilename(this: &g_TextStatsMgr, sFilename: "stats.txt");
  CTextStatsMgr::WriteFile(this: &g_TextStatsMgr, pFileSys: filesystem, pFilename: nullptr);
  IGameSystem::ShutdownAllSystems();
  if ( enginevgui != nullptr )
    VGui_Shutdown();
  RemoveBotControl();
  v18 = (vgui::Panel *)TheNavMesh;
  if ( TheNavMesh != nullptr )
  {
    ((void (__thiscall *)(CNavMesh *, int))TheNavMesh->dtr_IGameEventListener2)(a1: TheNavMesh, a2: 1);
    TheNavMesh = nullptr;
  }
  s_SteamAPIContext.m_pSteamUser = nullptr;
  s_SteamAPIContext.m_pSteamFriends = nullptr;
  s_SteamAPIContext.m_pSteamUtils = nullptr;
  s_SteamAPIContext.m_pSteamMatchmaking = nullptr;
  s_SteamAPIContext.m_pSteamUserStats = nullptr;
  s_SteamAPIContext.m_pSteamApps = nullptr;
  s_SteamAPIContext.m_pSteamMatchmakingServers = nullptr;
  s_SteamAPIContext.m_pSteamNetworking = nullptr;
  s_SteamAPIContext.m_pSteamRemoteStorage = nullptr;
  s_SteamGameServerAPIContext.m_pSteamGameServer = nullptr;
  s_SteamGameServerAPIContext.m_pSteamGameServerUtils = nullptr;
  s_SteamGameServerAPIContext.m_pSteamMasterServerUpdater = nullptr;
  s_SteamGameServerAPIContext.m_pSteamGameServerNetworking = nullptr;
  s_SteamGameServerAPIContext.m_pSteamGameServerStats = nullptr;
  CAI_BaseNPC::OnSetSchedule(this: v18);
  DisconnectTier2Libraries();
  ConVar_Unregister();
  DisconnectTier1Libraries();
}

//------------------------------------------------------------------------------
// Address: 0x1013FAF0
// Name: public: virtual float CServerGameDLL::GetTickInterval(void)const
// Source: json
//------------------------------------------------------------------------------
double __thiscall CServerGameDLL::GetTickInterval(CServerGameDLL *this)
{
  return 0.033333335;
}

//------------------------------------------------------------------------------
// Address: 0x1013FB00
// Name: public: virtual bool CServerGameDLL::GameInit(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CServerGameDLL::GameInit(CServerGameDLL *this)
{
  IGameEvent *v1; // eax

  ResetGlobalState();
  engine->ServerCommand(this: engine, a2: "exec game.cfg\n");
  engine->ServerExecute(this: engine);
  CBaseEntity::sm_bAccurateTriggerBboxChecks = true;
  v1 = gameeventmanager->CreateEventA(this: gameeventmanager, a2: "game_init", a3: 0, a4: 0);
  if ( v1 != nullptr )
    gameeventmanager->FireEvent(this: gameeventmanager, a2: v1, a3: false);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1013FB60
// Name: public: virtual void CServerGameDLL::GameShutdown(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall CServerGameDLL::GameShutdown(CServerGameDLL *this)
{
  ResetGlobalState();
}

//------------------------------------------------------------------------------
// Address: 0x1013FB70
// Name: void Game_SetOneWayTransition(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Game_SetOneWayTransition()
{
  g_OneWayTransition = true;
}

//------------------------------------------------------------------------------
// Address: 0x1013FB80
// Name: public: virtual bool CServerGameDLL::IsRestoring(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CServerGameDLL::IsRestoring(CServerGameDLL *this)
{
  return g_InRestore;
}

//------------------------------------------------------------------------------
// Address: 0x1013FB90
// Name: public: virtual void CServerGameDLL::ServerActivate(struct edict_t __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __thiscall CServerGameDLL::ServerActivate(
        CServerGameDLL *this,
        edict_t *pEdictList,
        edict_t *edictCount,
        int clientMax)
{
  CBaseEntity *i; // esi
  IMDLCache *v5; // edi

  if ( !g_InRestore )
  {
    if ( CGlobalEntityList::ResetDeleteList(this: &gEntList) != 0 )
      _Msg(a1: "ERROR: Entity delete queue not empty on level start!\n");
    for ( i = CGlobalEntityList::NextEnt(this: &gEntList, pCurrentEnt: nullptr);
          i != nullptr;
          i = CGlobalEntityList::NextEnt(this: &gEntList, pCurrentEnt: i) )
    {
      if ( !CBaseEntity::IsDormant(this: i) )
      {
        v5 = mdlcache;
        mdlcache->BeginLock(this: mdlcache);
        i->Activate(this: i);
        v5->EndLock(this: v5);
      }
    }
    IGameSystem::LevelInitPostEntityAllSystems();
    CBaseEntity::SetAllowPrecache(allow: false);
    if ( g_pDeveloper->m_pParent == nullptr || g_pDeveloper->m_pParent->m_Value.m_nValue == 0 )
      CCollisionProperty::TestCollision(this: (ConVar *)&think_limit.IConVar, value: 0);
    TheNavMesh->Load(this: TheNavMesh);
    TheNavMesh->OnServerActivate(this: TheNavMesh);
    TheBots->ServerActivate(this: TheBots);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1013FC70
// Name: public: virtual void CServerGameDLL::GameServerSteamAPIActivated(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CServerGameDLL::GameServerSteamAPIActivated(CServerGameDLL *this)
{
  CSteamGameServerAPIContext::Init(this: steamgameserverapicontext);
}

//------------------------------------------------------------------------------
// Address: 0x1013FC80
// Name: public: virtual void CServerGameDLL::LevelShutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CServerGameDLL::LevelShutdown(CServerGameDLL *this)
{
  IMDLCache *v1; // esi

  v1 = mdlcache;
  mdlcache->BeginLock(this: mdlcache);
  IGameSystem::LevelShutdownPreEntityAllSystems();
  CSoundEnt::ShutdownSoundEnt();
  ClearDebugHistory();
  CGlobalEntityList::Clear(this: &gEntList);
  InvalidateQueryCache();
  IGameSystem::LevelShutdownPostEntityAllSystems();
  CBaseEntity::SetAllowPrecache(allow: false);
  if ( TheNavMesh != nullptr )
    TheNavMesh->Reset(this: TheNavMesh);
  g_nCurrentChapterIndex = -1;
  CStudioHdr::CActivityToSequenceMapping::ResetMappings();
  v1->EndLock(this: v1);
}

//------------------------------------------------------------------------------
// Address: 0x1013FCF0
// Name: public: virtual class ServerClass __near * CServerGameDLL::GetAllServerClasses(void)
// Source: json
//------------------------------------------------------------------------------
ServerClass *__thiscall CServerGameDLL::GetAllServerClasses(CServerGameDLL *this)
{
  return g_pServerClassHead;
}

//------------------------------------------------------------------------------
// Address: 0x1013FD00
// Name: public: virtual char const __near * CServerGameDLL::GetGameDescription(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
const char *__thiscall CServerGameDLL::GetGameDescription(CServerGameDLL *this)
{
  return GetGameDescription();
}

//------------------------------------------------------------------------------
// Address: 0x1013FD10
// Name: public: virtual class CSaveRestoreData __near * CServerGameDLL::SaveInit(int)
// Source: json
//------------------------------------------------------------------------------
CSaveRestoreData *__thiscall CServerGameDLL::SaveInit(CServerGameDLL *this, int size)
{
  return SaveInit(size);
}

//------------------------------------------------------------------------------
// Address: 0x1013FD30
// Name: public: virtual void CServerGameDLL::SaveGlobalState(class CSaveRestoreData __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CServerGameDLL::SaveGlobalState(CServerGameDLL *this, CSaveRestoreData *s)
{
  SaveGlobalState(pSaveData: s);
}

//------------------------------------------------------------------------------
// Address: 0x1013FD50
// Name: public: virtual void CServerGameDLL::RestoreGlobalState(class CSaveRestoreData __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CServerGameDLL::RestoreGlobalState(CServerGameDLL *this, CSaveRestoreData *s)
{
  RestoreGlobalState(pSaveData: s);
}

//------------------------------------------------------------------------------
// Address: 0x1013FD70
// Name: public: virtual bool CServerGameDLL::GetUserMessageInfo(int,char __near *,int,int __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CServerGameDLL::GetUserMessageInfo(
        CServerGameDLL *this,
        int msg_type,
        char *name,
        int maxnamelength,
        int *size)
{
  bool result; // al
  const char *UserMessageName; // eax

  result = CUserMessages::IsValidIndex(this: usermessages, index: msg_type);
  if ( result )
  {
    UserMessageName = CUserMessages::GetUserMessageName(this: usermessages, index: msg_type);
    V_strncpy(pDest: name, pSrc: UserMessageName, maxLen: maxnamelength);
    *size = CUserMessages::GetUserMessageSize(this: usermessages, index: msg_type);
    return true;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1013FDD0
// Name: public: virtual class CStandardSendProxies __near * CServerGameDLL::GetStandardSendProxies(void)
// Source: json
//------------------------------------------------------------------------------
CStandardSendProxies *__thiscall CServerGameDLL::GetStandardSendProxies(CServerGameDLL *this)
{
  return &g_StandardSendProxies;
}

//------------------------------------------------------------------------------
// Address: 0x1013FDE0
// Name: public: virtual void CServerGameDLL::PreSave(class CSaveRestoreData __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CServerGameDLL::PreSave(CServerGameDLL *this, CSaveRestoreData *s)
{
  g_pGameSaveRestoreBlockSet->PreSave(this: g_pGameSaveRestoreBlockSet, a2: s);
}

//------------------------------------------------------------------------------
// Address: 0x1013FE00
// Name: public: virtual void CServerGameDLL::GetSaveComment(char __near *,int,float,float,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CServerGameDLL::GetSaveComment(
        CServerGameDLL *this,
        char *text,
        int maxlength,
        float flMinutes,
        float flSeconds,
        bool bNoTime)
{
  const char *pszValue; // ebx
  int v7; // esi
  int i; // ecx
  char v9; // al
  int v10; // esi
  int v11; // ecx
  char comment[64]; // [esp+8h] [ebp-40h] BYREF

  pszValue = gpGlobals->mapname.pszValue;
  if ( pszValue == nullptr )
    pszValue = locale;
  v7 = 0;
  while ( V_strnicmp(s1: pszValue, s2: gTitleComments[v7].pBSPName, n: strlen(gTitleComments[v7].pBSPName)) != 0 )
  {
    if ( (unsigned int)++v7 >= 0x39 )
      goto LABEL_14;
  }
  V_strncpy(pDest: comment, pSrc: gTitleComments[v7].pTitleName, maxLen: 64);
  pszValue = comment;
  for ( i = 0; i < 64; v9 == 10 || v9 == 13 ? (comment[i] = 0) : ++i )
  {
    v9 = comment[i];
    if ( v9 == 0 )
      break;
  }
LABEL_14:
  if ( bNoTime )
  {
    V_snprintf(pDest: text, maxLen: maxlength, pFormat: "%-64.64s", pszValue);
  }
  else
  {
    v10 = (int)flMinutes;
    v11 = (int)flSeconds;
    if ( (int)flMinutes >= 1000 )
    {
      v10 = 999;
      v11 = 59;
    }
    V_snprintf(pDest: text, maxLen: maxlength, pFormat: "%-64.64s %03d:%02d", pszValue, v10 + v11 / 60, v11 % 60);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1013FF10
// Name: public: virtual void CServerGameDLL::PreSaveGameLoaded(char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CServerGameDLL::PreSaveGameLoaded(CServerGameDLL *this, const char *pSaveName, BOOL bInGame)
{
  gamestats->Event_PreSaveGameLoaded(this: gamestats, a2: pSaveName, a3: bInGame);
}

//------------------------------------------------------------------------------
// Address: 0x1013FF30
// Name: public: virtual void CServerGameDLL::ServerHibernationUpdate(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CServerGameDLL::ServerHibernationUpdate(CServerGameDLL *this, bool bHibernating)
{
  this->m_bIsHibernating = bHibernating;
}

//------------------------------------------------------------------------------
// Address: 0x1013FF40
// Name: public: virtual void CServerGameDLL::BuildAdjacentMapList(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CServerGameDLL::BuildAdjacentMapList(CServerGameDLL *this)
{
  CSaveRestoreData *pSaveData; // esi

  pSaveData = gpGlobals->pSaveData;
  if ( pSaveData != nullptr )
    pSaveData->levelInfo.connectionCount = BuildChangeList(pLevelList: pSaveData->levelInfo.levelList, maxList: 16);
}

//------------------------------------------------------------------------------
// Address: 0x1013FF60
// Name: ValidateMOTDFilename
// Source: json
//------------------------------------------------------------------------------
void __cdecl ValidateMOTDFilename(IConVar *pConVar)
{
  char *m_pszString; // esi
  ConVarRef var; // [esp+4h] [ebp-8h] BYREF

  ConVarRef::ConVarRef(this: &var, pConVar);
  m_pszString = var.m_pConVarState->m_Value.m_pszString;
  if ( m_pszString == nullptr
    || _V_strlen(str: var.m_pConVarState->m_Value.m_pszString) <= 0
    || V_IsAbsolutePath(pStr: m_pszString)
    || _V_strstr(s1: m_pszString, search: "..") != nullptr )
  {
    var.m_pConVar->SetValue_4(this: var.m_pConVar, a2: var.m_pConVarState->m_pszDefaultValue);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1013FFC0
// Name: void LoadMOTDFile(char const __near *,class ConVar __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl LoadMOTDFile(const char *stringname, ConVar *pConvarFilename)
{
  char *m_pszString; // eax
  int v3; // eax
  int v4; // esi
  char *v5; // eax
  void *v6; // eax
  void *v7; // edi
  INetworkStringTable *v8; // ecx
  char *v9; // eax
  char data[2048]; // [esp+8h] [ebp-800h] BYREF

  if ( (pConvarFilename->m_nFlags & 0x1000) != 0 )
  {
    m_pszString = "FCVAR_NEVER_AS_STRING";
  }
  else
  {
    m_pszString = pConvarFilename->m_pParent->m_Value.m_pszString;
    if ( m_pszString == nullptr )
      m_pszString = (char *)locale;
  }
  v3 = filesystem->Size(this: &filesystem->IBaseFileSystem, a2: m_pszString, a3: "GAME");
  v4 = v3;
  if ( v3 <= 0 || (unsigned int)v3 >= 0x7FF )
  {
    if ( (pConvarFilename->m_nFlags & 0x1000) != 0 )
    {
      v9 = "FCVAR_NEVER_AS_STRING";
    }
    else
    {
      v9 = pConvarFilename->m_pParent->m_Value.m_pszString;
      if ( v9 == nullptr )
        v9 = (char *)locale;
    }
    DevMsg(a1: "Invalid file size for %s\n", v9);
  }
  else
  {
    if ( (pConvarFilename->m_nFlags & 0x1000) != 0 )
    {
      v5 = "FCVAR_NEVER_AS_STRING";
    }
    else
    {
      v5 = pConvarFilename->m_pParent->m_Value.m_pszString;
      if ( v5 == nullptr )
        v5 = (char *)locale;
    }
    v6 = filesystem->Open(this: &filesystem->IBaseFileSystem, a2: v5, a3: "rb", a4: "GAME");
    v7 = v6;
    if ( v6 != nullptr )
    {
      filesystem->Read(this: &filesystem->IBaseFileSystem, a2: data, a3: v4, a4: v6);
      filesystem->Close(this: &filesystem->IBaseFileSystem, a2: v7);
      v8 = g_pStringTableInfoPanel;
      data[v4] = 0;
      v8->AddString(this: v8, a2: true, a3: stringname, a4: v4 + 1, a5: data);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101400F0
// Name: UpdateChapterRestrictions
// Source: json
//------------------------------------------------------------------------------
void __cdecl UpdateChapterRestrictions(const char *mapname)
{
  int v1; // edi
  int i; // ecx
  char v3; // al
  int v4; // eax
  _BYTE *v5; // eax
  int v6; // esi
  char *m_pszString; // eax
  char modDir[260]; // [esp+Ch] [ebp-1A4h] BYREF
  char chapterNumberPrefix[64]; // [esp+110h] [ebp-A0h] BYREF
  char chapterTitle[64]; // [esp+150h] [ebp-60h] BYREF
  char newChapter[32]; // [esp+190h] [ebp-20h] BYREF

  chapterTitle[0] = 0;
  v1 = 0;
  while ( V_strnicmp(s1: mapname, s2: gTitleComments[v1].pBSPName, n: strlen(gTitleComments[v1].pBSPName)) != 0 )
  {
    if ( (unsigned int)++v1 >= 0x39 )
      goto LABEL_12;
  }
  V_strncpy(pDest: chapterTitle, pSrc: gTitleComments[v1].pTitleName, maxLen: 64);
  for ( i = 0; i < 64; v3 == 10 || v3 == 13 ? (chapterTitle[i] = 0) : ++i )
  {
    v3 = chapterTitle[i];
    if ( v3 == 0 )
      break;
  }
LABEL_12:
  if ( chapterTitle[0] != 0 )
  {
    strlwr(string: chapterTitle);
    if ( UTIL_GetModDir(lpszTextOut: modDir, nSize: 0x104u) )
    {
      V_snprintf(pDest: chapterNumberPrefix, maxLen: 64, pFormat: "#%s_chapter", modDir);
      strstr(str1: (unsigned __int8 *)chapterTitle, str2: (unsigned __int8 *)chapterNumberPrefix);
      if ( v4 != 0 )
      {
        V_strncpy(pDest: newChapter, pSrc: (const char *)(v4 + strlen(chapterNumberPrefix)), maxLen: 32);
        strstr(str1: (unsigned __int8 *)newChapter, str2: "_title");
        if ( v5 != nullptr )
          *v5 = 0;
        v6 = atoi(nptr: newChapter);
        if ( _V_stricmp(s1: modDir, s2: "hl2") == 0 )
        {
          if ( _V_stricmp(s1: newChapter, s2: "9a") != 0 )
          {
            if ( v6 > 9 )
              ++v6;
          }
          else
          {
            v6 = 10;
          }
        }
        if ( (sv_unlockedchapters.m_nFlags & 0x1000) != 0 )
        {
          m_pszString = "FCVAR_NEVER_AS_STRING";
        }
        else
        {
          m_pszString = sv_unlockedchapters.m_pParent->m_Value.m_pszString;
          if ( m_pszString == nullptr )
            m_pszString = (char *)locale;
        }
        if ( atoi(nptr: m_pszString) < v6 )
          CCollisionProperty::TestCollision(this: (ConVar *)&sv_unlockedchapters.IConVar, value: v6);
        g_nCurrentChapterIndex = v6;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101402A0
// Name: void PrecacheMaterial(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl PrecacheMaterial(const char *pMaterialName)
{
  g_pStringTableMaterials->AddString(this: g_pStringTableMaterials, a2: true, a3: pMaterialName, a4: -1, a5: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x101402C0
// Name: int GetMaterialIndex(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl GetMaterialIndex(const char *pMaterialName)
{
  int result; // eax

  if ( pMaterialName != nullptr )
  {
    result = g_pStringTableMaterials->FindStringIndex(this: g_pStringTableMaterials, a2: pMaterialName);
    if ( result != 0xFFFF )
      return result;
    DevMsg(a1: "Warning! GetMaterialIndex: couldn't find material %s\n ", pMaterialName);
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10140300
// Name: char const __near * GetMaterialNameFromIndex(int)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl GetMaterialNameFromIndex(int nMaterialIndex)
{
  return g_pStringTableMaterials->GetString(this: g_pStringTableMaterials, a2: nMaterialIndex);
}

//------------------------------------------------------------------------------
// Address: 0x10140320
// Name: int PrecacheParticleSystem(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl PrecacheParticleSystem(const char *pParticleSystemName)
{
  return g_pStringTableParticleEffectNames->AddString(
           this: g_pStringTableParticleEffectNames,
           a2: true,
           a3: pParticleSystemName,
           a4: -1,
           a5: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x10140340
// Name: int GetParticleSystemIndex(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl GetParticleSystemIndex(const char *pParticleSystemName)
{
  int result; // eax

  if ( pParticleSystemName != nullptr )
  {
    result = g_pStringTableParticleEffectNames->FindStringIndex(
               this: g_pStringTableParticleEffectNames,
               a2: pParticleSystemName);
    if ( result != 0xFFFF )
      return result;
    DevWarning(a1: "Server: Missing precache for particle system \"%s\"!\n", pParticleSystemName);
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10140380
// Name: void PrecacheEffect(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl PrecacheEffect(const char *pEffectName)
{
  g_pStringTableEffectDispatch->AddString(
    this: g_pStringTableEffectDispatch,
    a2: true,
    a3: pEffectName,
    a4: -1,
    a5: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x101403A0
// Name: int GetEffectIndex(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl GetEffectIndex(const char *pEffectName)
{
  int result; // eax

  if ( pEffectName != nullptr )
  {
    result = g_pStringTableEffectDispatch->FindStringIndex(this: g_pStringTableEffectDispatch, a2: pEffectName);
    if ( result != 0xFFFF )
      return result;
    DevWarning(a1: "Server: Missing precache for effect \"%s\"!\n", pEffectName);
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x101403E0
// Name: void PrecacheMovie(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl PrecacheMovie(const char *pMovieName)
{
  g_pStringTableMovies->AddString(this: g_pStringTableMovies, a2: true, a3: pMovieName, a4: -1, a5: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x10140410
// Name: public: virtual void CServerGameEnts::FreeContainingEntity(struct edict_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CServerGameEnts::FreeContainingEntity(CServerGameEnts *this, edict_t *e)
{
  FreeContainingEntity(ed: e);
}

//------------------------------------------------------------------------------
// Address: 0x10140430
// Name: public: virtual class CBaseEntity __near * CServerGameEnts::EdictToBaseEntity(struct edict_t __near *)
// Source: json
//------------------------------------------------------------------------------
CBaseEntity *__thiscall CServerGameEnts::EdictToBaseEntity(CServerGameEnts *this, edict_t *pEdict)
{
  IServerUnknown *m_pUnk; // ecx

  if ( pEdict != nullptr && (m_pUnk = pEdict->m_pUnk) != nullptr )
    return m_pUnk->GetBaseEntity(this: m_pUnk);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10140460
// Name: public: virtual void CServerGameEnts::PrepareForFullUpdate(struct edict_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CServerGameEnts::PrepareForFullUpdate(CServerGameEnts *this, edict_t *pEdict)
{
  edict_t *pEdicts; // eax
  IServerUnknown *m_pUnk; // ecx
  vgui::Panel *v4; // eax

  pEdicts = pEdict;
  if ( pEdict != nullptr || gpGlobals->pEdicts != nullptr && ((pEdicts = gpGlobals->pEdicts)->m_fStateFlags & 2) == 0 )
  {
    m_pUnk = pEdicts->m_pUnk;
    if ( m_pUnk != nullptr )
    {
      v4 = (vgui::Panel *)m_pUnk->GetBaseEntity(this: m_pUnk);
      if ( v4 != nullptr )
        CAI_BaseNPC::OnSetSchedule(this: v4);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101404B0
// Name: public: virtual bool CServerGameClients::ClientConnect(struct edict_t __near *,char const __near *,char const __near *,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CServerGameClients::ClientConnect(
        CServerGameClients *this,
        edict_t *pEdict,
        const char *pszName,
        const char *pszAddress,
        char *reject,
        int maxrejectlen)
{
  return g_pGameRules != nullptr
      && g_pGameRules->ClientConnected(
           this: g_pGameRules,
           a2: pEdict,
           a3: pszName,
           a4: pszAddress,
           a5: reject,
           a6: maxrejectlen);
}

//------------------------------------------------------------------------------
// Address: 0x101404D0
// Name: public: virtual void CServerGameClients::ClientFullyConnect(struct edict_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CServerGameClients::ClientFullyConnect(CServerGameClients *this, edict_t *pEdict)
{
  CAI_BaseNPC::OnSetSchedule((vgui::Panel *)this);
}

//------------------------------------------------------------------------------
// Address: 0x101404F0
// Name: public: virtual void CServerGameClients::PostClientMessagesSent(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CServerGameClients::PostClientMessagesSent(CServerGameClients *this)
{
  CGlobalEntityList::PostClientMessagesSent(this: &gEntList);
}

//------------------------------------------------------------------------------
// Address: 0x10140500
// Name: public: virtual void CServerGameClients::SetCommandClient(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CServerGameClients::SetCommandClient(CServerGameClients *this, int index)
{
  g_nCommandClientIndex = index;
}

//------------------------------------------------------------------------------
// Address: 0x10140510
// Name: public: virtual int CServerGameClients::GetReplayDelay(struct edict_t __near *,int __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CServerGameClients::GetReplayDelay(CServerGameClients *this, edict_t *pEdict, int *entity)
{
  edict_t *pEdicts; // eax
  IServerUnknown *m_pUnk; // ecx
  int v5; // eax
  int v6; // esi

  pEdicts = pEdict;
  if ( pEdict == nullptr )
  {
    if ( gpGlobals->pEdicts == nullptr )
      return 0;
    pEdicts = gpGlobals->pEdicts;
    if ( (pEdicts->m_fStateFlags & 2) != 0 )
      return 0;
  }
  m_pUnk = pEdicts->m_pUnk;
  if ( m_pUnk == nullptr )
    return 0;
  v5 = (int)m_pUnk->GetBaseEntity(this: m_pUnk);
  v6 = v5;
  if ( v5 == 0 )
    return 0;
  *entity = (*(int (__thiscall **)(int))(*(_DWORD *)v5 + 1676))(a1: v5);
  return (*(int (__thiscall **)(int))(*(_DWORD *)v6 + 1672))(a1: v6);
}

//------------------------------------------------------------------------------
// Address: 0x10140570
// Name: public: virtual void CServerGameClients::ClientEarPosition(struct edict_t __near *,class Vector __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CServerGameClients::ClientEarPosition(CServerGameClients *this, edict_t *pEdict, Vector *pEarOrigin)
{
  edict_t *pEdicts; // eax
  IServerUnknown *m_pUnk; // ecx
  int v5; // eax
  _BYTE v6[12]; // [esp+0h] [ebp-Ch] BYREF

  pEdicts = pEdict;
  if ( (pEdict != nullptr || gpGlobals->pEdicts != nullptr && ((pEdicts = gpGlobals->pEdicts)->m_fStateFlags & 2) == 0)
    && (m_pUnk = pEdicts->m_pUnk) != nullptr
    && (v5 = (int)m_pUnk->GetBaseEntity(this: m_pUnk)) != 0 )
  {
    *pEarOrigin = *(Vector *)(*(int (__thiscall **)(int, _BYTE *))(*(_DWORD *)v5 + 516))(a1: v5, a2: v6);
  }
  else
  {
    *pEarOrigin = vec3_origin;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10140600
// Name: public: virtual class CPlayerState __near * CServerGameClients::GetPlayerState(struct edict_t __near *)
// Source: json
//------------------------------------------------------------------------------
CPlayerState *__thiscall CServerGameClients::GetPlayerState(CServerGameClients *this, edict_t *player)
{
  IServerUnknown *m_pUnk; // ecx
  int v3; // eax

  if ( player != nullptr && (m_pUnk = player->m_pUnk) != nullptr && (v3 = (int)m_pUnk->GetBaseEntity(this: m_pUnk)) != 0 )
    return (CPlayerState *)(v3 + 2900);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10140630
// Name: public: virtual void CServerGameClients::ClientVoice(struct edict_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CServerGameClients::ClientVoice(CServerGameClients *this, edict_t *pEdict)
{
  edict_t *pEdicts; // eax
  IServerUnknown *m_pUnk; // ecx
  int v4; // eax
  CBasePlayer *v5; // esi
  CPlayerVoiceListener *v6; // eax

  pEdicts = pEdict;
  if ( pEdict != nullptr || gpGlobals->pEdicts != nullptr && ((pEdicts = gpGlobals->pEdicts)->m_fStateFlags & 2) == 0 )
  {
    m_pUnk = pEdicts->m_pUnk;
    if ( m_pUnk != nullptr )
    {
      v4 = (int)m_pUnk->GetBaseEntity(this: m_pUnk);
      v5 = (CBasePlayer *)v4;
      if ( v4 != 0 )
      {
        (*(void (__thiscall **)(int))(*(_DWORD *)v4 + 1968))(a1: v4);
        v6 = PlayerVoiceListener();
        CPlayerVoiceListener::AddPlayerSpeakTime(this: v6, pPlayer: v5);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10140690
// Name: public: virtual int CServerGameClients::GetMaxHumanPlayers(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CServerGameClients::GetMaxHumanPlayers(CServerGameClients *this)
{
  if ( g_pGameRules != nullptr )
    return g_pGameRules->GetMaxHumanPlayers(this: g_pGameRules);
  else
    return -1;
}

//------------------------------------------------------------------------------
// Address: 0x101406B0
// Name: public: virtual void CServerGameClients::ClientCommandKeyValues(struct edict_t __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CServerGameClients::ClientCommandKeyValues(
        CServerGameClients *this,
        edict_t *pEntity,
        KeyValues *pKeyValues)
{
  const char *Name; // eax
  KeyValues *Copy; // eax

  if ( pKeyValues != nullptr )
  {
    g_pGameRules->ClientCommandKeyValues(this: g_pGameRules, a2: pEntity, a3: pKeyValues);
    Name = KeyValues::GetName(this: pKeyValues);
    if ( Name == "OnPlayerAward" || _V_stricmp(s1: Name, s2: "OnPlayerAward") == 0 )
    {
      Copy = KeyValues::MakeCopy(this: pKeyValues);
      UTIL_SendClientCommandKVToPlayer(pKV: Copy, pPlayer: nullptr);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10140710
// Name: void EntityMessageBegin(class CBaseEntity __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl EntityMessageBegin(CBaseEntity *entity, int reliable)
{
  edict_t *m_pPev; // eax
  signed int v3; // esi
  IVEngineServer_vtbl *v4; // edi
  int v5; // eax

  m_pPev = entity->m_Network.m_pPev;
  if ( m_pPev != nullptr )
    v3 = m_pPev - gpGlobals->pEdicts;
  else
    v3 = 0;
  v4 = engine->__vftable;
  v5 = ((int (__stdcall *)(int))entity->GetServerClass)(a1: reliable);
  g_pMsgBuffer = (bf_write *)((int (__thiscall *)(IVEngineServer *, signed int, int))v4->EntityMessageBegin)(
                               a1: engine,
                               a2: v3,
                               a3: v5);
}

//------------------------------------------------------------------------------
// Address: 0x10140760
// Name: void UserMessageBegin(class IRecipientFilter __near &,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl UserMessageBegin(IRecipientFilter *filter, const char *messagename)
{
  int v2; // esi

  v2 = CUserMessages::LookupUserMessage(this: usermessages, name: messagename);
  if ( v2 == -1 )
    _Error(this: (ISceneTokenProcessor *)&stru_1047B60C, a2: messagename);
  g_pMsgBuffer = engine->UserMessageBegin(this: engine, a2: filter, a3: v2, a4: messagename);
}

//------------------------------------------------------------------------------
// Address: 0x101407B0
// Name: void MessageEnd(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MessageEnd()
{
  engine->MessageEnd(this: engine);
  g_pMsgBuffer = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x101407D0
// Name: void MessageWriteByte(int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MessageWriteByte(unsigned int iValue)
{
  const char *savedregs; // [esp+0h] [ebp+0h]

  if ( g_pMsgBuffer == nullptr )
    _Error(this: (ISceneTokenProcessor *)&stru_1047B63C, a2: savedregs);
  bf_write::WriteByte(this: g_pMsgBuffer, val: iValue);
}

//------------------------------------------------------------------------------
// Address: 0x10140800
// Name: void MessageWriteChar(int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MessageWriteChar(int iValue)
{
  const char *savedregs; // [esp+0h] [ebp+0h]

  if ( g_pMsgBuffer == nullptr )
    _Error(this: (ISceneTokenProcessor *)&stru_1047B668, a2: savedregs);
  bf_write::WriteChar(this: g_pMsgBuffer, val: iValue);
}

//------------------------------------------------------------------------------
// Address: 0x10140830
// Name: void MessageWriteShort(int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MessageWriteShort(int iValue)
{
  const char *savedregs; // [esp+0h] [ebp+0h]

  if ( g_pMsgBuffer == nullptr )
    _Error(this: (ISceneTokenProcessor *)&stru_1047B694, a2: savedregs);
  bf_write::WriteShort(this: g_pMsgBuffer, val: iValue);
}

//------------------------------------------------------------------------------
// Address: 0x10140860
// Name: void MessageWriteLong(int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MessageWriteLong(int iValue)
{
  const char *savedregs; // [esp+0h] [ebp+0h]

  if ( g_pMsgBuffer == nullptr )
    _Error(this: (ISceneTokenProcessor *)&stru_1047B6C0, a2: savedregs);
  bf_write::WriteLong(this: g_pMsgBuffer, val: iValue);
}

//------------------------------------------------------------------------------
// Address: 0x10140890
// Name: void MessageWriteFloat(float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MessageWriteFloat(float flValue)
{
  const char *savedregs; // [esp+4h] [ebp+0h]

  if ( g_pMsgBuffer == nullptr )
    _Error(this: (ISceneTokenProcessor *)&stru_1047B6EC, a2: savedregs);
  bf_write::WriteFloat(this: g_pMsgBuffer, val: flValue);
}

//------------------------------------------------------------------------------
// Address: 0x101408D0
// Name: void MessageWriteVec3Coord(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MessageWriteVec3Coord(const Vector *rgflValue)
{
  const char *savedregs; // [esp+0h] [ebp+0h]

  if ( g_pMsgBuffer == nullptr )
    _Error(this: (ISceneTokenProcessor *)&stru_1047B718, a2: savedregs);
  bf_write::WriteBitVec3Coord(this: g_pMsgBuffer, fa: rgflValue);
}

//------------------------------------------------------------------------------
// Address: 0x10140900
// Name: void MessageWriteString(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MessageWriteString(const char *sz)
{
  const char *savedregs; // [esp+0h] [ebp+0h]

  if ( g_pMsgBuffer == nullptr )
    _Error(this: (ISceneTokenProcessor *)&stru_1047B748, a2: savedregs);
  bf_write::WriteString(this: g_pMsgBuffer, pStr: sz);
}

//------------------------------------------------------------------------------
// Address: 0x10140930
// Name: void MessageWriteUBitLong(unsigned int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MessageWriteUBitLong(unsigned int data, int numbits)
{
  const char *savedregs; // [esp+0h] [ebp+0h]

  if ( g_pMsgBuffer == nullptr )
    _Error(this: (ISceneTokenProcessor *)&stru_1047B774, a2: savedregs);
  bf_write::WriteUBitLong(this: g_pMsgBuffer, curData: data, numbits, bCheckRange: true);
}

//------------------------------------------------------------------------------
// Address: 0x10140970
// Name: void MessageWriteSBitLong(int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MessageWriteSBitLong(int data, int numbits)
{
  const char *savedregs; // [esp+0h] [ebp+0h]

  if ( g_pMsgBuffer == nullptr )
    _Error(this: (ISceneTokenProcessor *)&stru_1047B7A4, a2: savedregs);
  bf_write::WriteSBitLong(this: g_pMsgBuffer, data, numbits);
}

//------------------------------------------------------------------------------
// Address: 0x101409B0
// Name: public: virtual void CServerGameTags::GetTaggedConVarList(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CServerGameTags::GetTaggedConVarList(CServerGameTags *this, KeyValues *pCvarTagList)
{
  if ( pCvarTagList != nullptr && g_pGameRules != nullptr )
    g_pGameRules->GetTaggedConVarList(this: g_pGameRules, a2: pCvarTagList);
}

//------------------------------------------------------------------------------
// Address: 0x10140A10
// Name: public: virtual void CStringTableSaveRestoreOps::Save(struct SaveRestoreFieldInfo_t const __near &,class ISave __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CStringTableSaveRestoreOps::Save(
        CStringTableSaveRestoreOps *this,
        const SaveRestoreFieldInfo_t *fieldInfo,
        ISave *pSave)
{
  const char *v3; // edi
  int v4; // eax
  ISave *v5; // esi

  v3 = this->m_pStringTable->GetString(this: this->m_pStringTable, a2: *(_DWORD *)fieldInfo->pField);
  v4 = _V_strlen(str: v3);
  v5 = pSave;
  fieldInfo = (const SaveRestoreFieldInfo_t *)(v4 + 1);
  pSave->WriteInt_2(this: pSave, a2: (const int *)&fieldInfo, a3: 1);
  v5->WriteString_4(this: v5, a2: v3);
}

//------------------------------------------------------------------------------
// Address: 0x10140A60
// Name: public: virtual void CStringTableSaveRestoreOps::MakeEmpty(struct SaveRestoreFieldInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CStringTableSaveRestoreOps::MakeEmpty(
        CStringTableSaveRestoreOps *this,
        const SaveRestoreFieldInfo_t *fieldInfo)
{
  *(_DWORD *)fieldInfo->pField = 0xFFFF;
}

//------------------------------------------------------------------------------
// Address: 0x10140A80
// Name: public: virtual bool CStringTableSaveRestoreOps::IsEmpty(struct SaveRestoreFieldInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CStringTableSaveRestoreOps::IsEmpty(
        CStringTableSaveRestoreOps *this,
        const SaveRestoreFieldInfo_t *fieldInfo)
{
  return *(_DWORD *)fieldInfo->pField == 0xFFFF;
}

//------------------------------------------------------------------------------
// Address: 0x10140AA0
// Name: public: virtual void CStringTableSaveRestoreOps::Restore(struct SaveRestoreFieldInfo_t const __near &,class IRestore __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CStringTableSaveRestoreOps::Restore(
        CStringTableSaveRestoreOps *this,
        const SaveRestoreFieldInfo_t *fieldInfo,
        IRestore *pRestore)
{
  IRestore_vtbl *v3; // edx
  int v4; // edi
  void *v5; // esp
  _BYTE v6[12]; // [esp+0h] [ebp-10h] BYREF
  CStringTableSaveRestoreOps *v7; // [esp+Ch] [ebp-4h]
  int *pStringIndex; // [esp+18h] [ebp+8h]

  v3 = pRestore->__vftable;
  v7 = this;
  pStringIndex = (int *)fieldInfo->pField;
  v4 = v3->ReadInt(this: pRestore);
  v5 = alloca(v4);
  pRestore->ReadString_2(this: pRestore, a2: v6, a3: v4, a4: v4);
  *pStringIndex = v7->m_pStringTable->AddString(this: v7->m_pStringTable, a2: true, a3: v6, a4: -1, a5: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x10140B00
// Name: public: virtual void CServerGameDLL::GameFrame(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CServerGameDLL::GameFrame(CServerGameDLL *this, bool simulating)
{
  IMDLCache *v2; // esi
  int v3; // edi
  int i; // esi
  int v5; // eax
  int totals[3]; // [esp+0h] [ebp-10h]
  float oldframetime; // [esp+Ch] [ebp-4h]

  if ( !g_InRestore )
  {
    if ( !s_Steam3Server.m_bInitialized )
    {
      CSteamGameServerAPIContext::Init(this: &s_Steam3Server);
      s_Steam3Server.m_bInitialized = true;
      g_pGameRules->UpdateGameplayStatsFromSteam(this: g_pGameRules);
    }
    g_bIsLogging = engine->IsLogEnabled(this: engine);
    if ( CBaseEntity::IsSimulatingOnAlternateTicks() )
    {
      if ( (gpGlobals->tickcount & 1) != 0 )
      {
        UpdateAllClientData();
        return;
      }
      gpGlobals->frametime = gpGlobals->frametime * 2.0;
    }
    oldframetime = gpGlobals->frametime;
    CGlobalEntityList::CleanupDeleteList(this: &gEntList);
    HandleFoundryEntitySpawnRecords();
    v2 = mdlcache;
    mdlcache->BeginLock(this: mdlcache);
    IGameSystem::FrameUpdatePreEntityThinkAllSystems();
    GameStartFrame();
    TheNavMesh->Update(this: TheNavMesh);
    gamestatsuploader->UpdateConnection(this: gamestatsuploader);
    UpdateQueryCache();
    g_pServerBenchmark->UpdateBenchmark(this: g_pServerBenchmark);
    Physics_RunThinkFunctions(simulating);
    IGameSystem::FrameUpdatePostEntityThinkAllSystems();
    ServiceEventQueue();
    v2->EndLock(this: v2);
    CGlobalEntityList::CleanupDeleteList(this: &gEntList);
    UpdateAllClientData();
    if ( g_pGameRules != nullptr )
      g_pGameRules->EndGameFrame(this: g_pGameRules);
    if ( trace_report.m_pParent != nullptr && trace_report.m_pParent->m_Value.m_nValue != 0 )
    {
      v3 = 0;
      for ( i = 0; i < 3; ++i )
      {
        v5 = enginetrace->GetStatByIndex(this: enginetrace, a2: i, a3: true);
        totals[i] = v5;
        if ( v5 > 0 )
          v3 += v5;
      }
      if ( v3 != 0 )
        _Msg(a1: "Trace: %d, contents %d, enumerate %d\n", totals[0], totals[1], totals[2]);
    }
    CTimedEventMgr::FireEvents(this: &g_NetworkPropertyEventMgr);
    gpGlobals->frametime = oldframetime;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10140CA0
// Name: public: virtual void CServerGameDLL::CreateNetworkStringTables(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CServerGameDLL::CreateNetworkStringTables(CServerGameDLL *this)
{
  g_pStringTableExtraParticleFiles = networkstringtable->CreateStringTable(
                                       this: networkstringtable,
                                       a2: "ExtraParticleFilesTable",
                                       a3: 1024,
                                       a4: 0,
                                       a5: 0,
                                       a6: 1);
  g_pStringTableParticleEffectNames = networkstringtable->CreateStringTable(
                                        this: networkstringtable,
                                        a2: "ParticleEffectNames",
                                        a3: 1024,
                                        a4: 0,
                                        a5: 0,
                                        a6: 1);
  g_pStringTableEffectDispatch = networkstringtable->CreateStringTable(
                                   this: networkstringtable,
                                   a2: "EffectDispatch",
                                   a3: 1024,
                                   a4: 0,
                                   a5: 0,
                                   a6: 0);
  g_pStringTableVguiScreen = networkstringtable->CreateStringTable(
                               this: networkstringtable,
                               a2: "VguiScreen",
                               a3: 256,
                               a4: 0,
                               a5: 0,
                               a6: 0);
  g_pStringTableMaterials = networkstringtable->CreateStringTable(
                              this: networkstringtable,
                              a2: "Materials",
                              a3: 1024,
                              a4: 0,
                              a5: 0,
                              a6: 1);
  g_pStringTableInfoPanel = networkstringtable->CreateStringTable(
                              this: networkstringtable,
                              a2: "InfoPanel",
                              a3: 128,
                              a4: 0,
                              a5: 0,
                              a6: 0);
  g_pStringTableClientSideChoreoScenes = networkstringtable->CreateStringTable(
                                           this: networkstringtable,
                                           a2: "Scenes",
                                           a3: 0x2000,
                                           a4: 0,
                                           a5: 0,
                                           a6: 1);
  g_pStringTableMovies = networkstringtable->CreateStringTable(
                           this: networkstringtable,
                           a2: "Movies",
                           a3: 16,
                           a4: 0,
                           a5: 0,
                           a6: 1);
  g_pStringTableMaterials->AddString(
    this: g_pStringTableMaterials,
    a2: true,
    a3: "debug/debugempty",
    a4: -1,
    a5: nullptr);
  g_pStringTableParticleEffectNames->AddString(
    this: g_pStringTableParticleEffectNames,
    a2: true,
    a3: "error",
    a4: -1,
    a5: nullptr);
  g_pStringTableEffectDispatch->AddString(
    this: g_pStringTableEffectDispatch,
    a2: true,
    a3: "error",
    a4: -1,
    a5: nullptr);
  CreateNetworkStringTables_GameRules();
  g_VguiScreenStringOps.m_pStringTable = g_pStringTableVguiScreen;
}

//------------------------------------------------------------------------------
// Address: 0x10140E10
// Name: public: virtual bool CServerGameDLL::ShouldHideServer(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CServerGameDLL::ShouldHideServer(CServerGameDLL *this)
{
  ConVar *m_pParent; // eax

  return g_pcv_commentary != nullptr
      && (m_pParent = g_pcv_commentary->m_pParent) != nullptr
      && m_pParent->m_Value.m_nValue != 0
      || gpGlobals->eLoadType == MapLoad_Background;
}

//------------------------------------------------------------------------------
// Address: 0x10140E40
// Name: bool IsEngineThreaded(void)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl IsEngineThreaded()
{
  ConVar *m_pParent; // eax

  if ( g_pcv_ThreadMode == nullptr )
    return false;
  m_pParent = g_pcv_ThreadMode->m_pParent;
  return m_pParent != nullptr && m_pParent->m_Value.m_nValue != 0;
}

//------------------------------------------------------------------------------
// Address: 0x10140E70
// Name: public: virtual void CServerGameEnts::MarkEntitiesAsTouching(struct edict_t __near *,struct edict_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CServerGameEnts::MarkEntitiesAsTouching(CServerGameEnts *this, edict_t *e1, edict_t *e2)
{
  IServerUnknown *m_pUnk; // ecx
  CBaseEntity *v4; // edi
  IServerUnknown *v5; // ecx
  CBaseEntity *v6; // esi
  float v7; // xmm1_4
  float v8; // xmm2_4
  CGameTrace tr; // [esp+8h] [ebp-54h] BYREF
  int savedregs; // [esp+5Ch] [ebp+0h] BYREF

  if ( e1 != nullptr && (m_pUnk = e1->m_pUnk) != nullptr )
    v4 = m_pUnk->GetBaseEntity(this: m_pUnk);
  else
    v4 = nullptr;
  if ( e2 != nullptr && (v5 = e2->m_pUnk) != nullptr )
    v6 = v5->GetBaseEntity(this: v5);
  else
    v6 = nullptr;
  if ( v4 != nullptr && v6 != nullptr )
  {
    UTIL_ClearTrace(trace: &tr);
    if ( (v6->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this: v6, a2: (int)&savedregs);
    if ( (v4->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this: v4, a2: (int)&savedregs);
    v7 = (float)(v6->m_vecAbsOrigin.y + v4->m_vecAbsOrigin.y) * 0.5;
    v8 = (float)(v6->m_vecAbsOrigin.z + v4->m_vecAbsOrigin.z) * 0.5;
    tr.endpos.x = (float)(v6->m_vecAbsOrigin.x + v4->m_vecAbsOrigin.x) * 0.5;
    tr.endpos.y = v7;
    tr.endpos.z = v8;
    CBaseEntity::PhysicsMarkEntitiesAsTouching(this: v4, other: v6, trace: &tr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10140F60
// Name: public: virtual struct edict_t __near * CServerGameEnts::BaseEntityToEdict(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
edict_t *__thiscall CServerGameEnts::BaseEntityToEdict(CServerGameEnts *this, CBaseEntity *pEnt)
{
  if ( pEnt != nullptr )
    return pEnt->m_Network.m_pPev;
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10140F80
// Name: public: virtual void CServerGameClients::ClientPutInServer(struct edict_t __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CServerGameClients::ClientPutInServer(
        CServerGameClients *this,
        edict_t *pEntity,
        const char *playername)
{
  IServerUnknown *m_pUnk; // ecx
  CBasePlayer *v4; // esi
  signed int m_pPev; // eax
  bool v6; // cl
  CBasePlayer *v7; // eax
  signed int v8; // eax
  edict_t *v9; // eax
  IServerUnknown *v10; // eax
  signed int v11; // eax
  CrossPlayPlatform_t v12; // eax
  bool bIsSplitScreenPlayer; // [esp+10h] [ebp+Ch]

  if ( g_pClientPutInServerOverride != nullptr )
    g_pClientPutInServerOverride(a1: pEntity, a2: playername);
  else
    ClientPutInServer(pEdict: pEntity, playername);
  if ( pEntity != nullptr )
  {
    m_pUnk = pEntity->m_pUnk;
    if ( m_pUnk != nullptr )
    {
      v4 = (CBasePlayer *)m_pUnk->GetBaseEntity(this: m_pUnk);
      if ( v4 != nullptr && v4->IsPlayer(this: v4) )
      {
        m_pPev = (signed int)v4->m_Network.m_pPev;
        if ( m_pPev != 0 )
          m_pPev = (signed int)(m_pPev - (unsigned int)gpGlobals->pEdicts) >> 4;
        v6 = engine->IsSplitScreenPlayer(this: engine, a2: m_pPev);
        v7 = nullptr;
        bIsSplitScreenPlayer = v6;
        if ( v6 )
        {
          v8 = (signed int)v4->m_Network.m_pPev;
          if ( v8 != 0 )
            v8 = (signed int)(v8 - (unsigned int)gpGlobals->pEdicts) >> 4;
          v9 = engine->GetSplitScreenPlayerAttachToEdict(this: engine, a2: v8);
          if ( v9 != nullptr && (v10 = v9->m_pUnk) != nullptr )
            v7 = (CBasePlayer *)v10->GetBaseEntity(this: v10);
          else
            v7 = nullptr;
        }
        CBasePlayer::SetSplitScreenPlayer(this: v4, bSplitScreenPlayer: bIsSplitScreenPlayer, pOwner: v7);
        v11 = (signed int)v4->m_Network.m_pPev;
        if ( v11 != 0 )
          v11 = (signed int)(v11 - (unsigned int)gpGlobals->pEdicts) >> 4;
        v12 = engine->GetClientCrossPlayPlatform(this: engine, a2: v11);
        CBasePlayer::SetCrossPlayPlatform(this: v4, clientPlatform: v12);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10141090
// Name: public: virtual void CServerGameClients::ClientCommand(struct edict_t __near *,class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CServerGameClients::ClientCommand(CServerGameClients *this, edict_t *pEntity, const CCommand *args)
{
  IServerUnknown *m_pUnk; // ecx
  CBasePlayer *v4; // esi

  if ( pEntity == nullptr
    || (m_pUnk = pEntity->m_pUnk) == nullptr
    || (v4 = (CBasePlayer *)m_pUnk->GetBaseEntity(this: m_pUnk)) == nullptr
    || !v4->IsPlayer(this: v4) )
  {
    v4 = nullptr;
  }
  ClientCommand(pPlayer: v4, args);
}

//------------------------------------------------------------------------------
// Address: 0x101410E0
// Name: public: virtual void CServerGameClients::GetBugReportInfo(char __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CServerGameClients::GetBugReportInfo(CServerGameClients *this, char *buf, int buflen)
{
  char *v3; // edi
  CBasePlayer *v4; // eax
  int v5; // eax
  _DWORD *v6; // esi
  const char *v7; // eax
  const char *v8; // edx
  const char *v9; // ecx
  signed int v10; // esi
  int RecentNPCSpeech; // ebx
  char *name; // esi
  recentNPCSpeech_t speech[5]; // [esp+20h] [ebp-C94h] BYREF

  v3 = buf;
  *buf = 0;
  if ( gpGlobals->maxClients == 1 )
  {
    if ( UTIL_PlayerByIndex(playerIndex: 1) != nullptr )
    {
      v4 = UTIL_PlayerByIndex(playerIndex: 1);
      v5 = (int)v4->FindPickerEntity(this: v4);
      v6 = (_DWORD *)v5;
      if ( v5 != 0 )
      {
        v7 = *(const char **)(*(int (__thiscall **)(int, char **))(*(_DWORD *)v5 + 28))(a1: v5, a2: &buf);
        if ( v7 == nullptr )
          v7 = locale;
        v8 = (const char *)v6[51];
        if ( v8 == nullptr )
          v8 = locale;
        v9 = (const char *)v6[23];
        if ( v9 == nullptr )
          v9 = locale;
        v10 = v6[6];
        if ( v10 != 0 )
          v10 = (signed int)(v10 - (unsigned int)gpGlobals->pEdicts) >> 4;
        V_snprintf(pDest: v3, maxLen: buflen, pFormat: "Picker %i/%s - ent %s model %s\n", v10, v9, v8, v7);
      }
    }
    RecentNPCSpeech = GetRecentNPCSpeech(speech);
    if ( RecentNPCSpeech > 0 )
    {
      V_snprintf(pDest: v3, maxLen: buflen, pFormat: "%sRecent NPC speech:\n", v3);
      name = speech[0].name;
      do
      {
        V_snprintf(
          pDest: v3,
          maxLen: buflen,
          pFormat: "%s   time: %6.3f   sound name: %s   scene: %s\n",
          v3,
          *((float *)name - 1),
          name,
          name + 512);
        name += 644;
        --RecentNPCSpeech;
      }
      while ( RecentNPCSpeech != 0 );
      V_snprintf(pDest: v3, maxLen: buflen, pFormat: "%sCurrent time: %6.3f\n", v3, gpGlobals->curtime);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10141230
// Name: void MessageWriteBool(bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MessageWriteBool(bool bValue)
{
  bf_write *v1; // eax
  int m_iCurBit; // ecx
  int v3; // esi
  char v4; // bl
  unsigned __int8 *m_pData; // edi
  const char *savedregs; // [esp+0h] [ebp+0h]

  v1 = g_pMsgBuffer;
  if ( g_pMsgBuffer == nullptr )
  {
    _Error(this: (ISceneTokenProcessor *)&stru_1047BA58, a2: savedregs);
    v1 = g_pMsgBuffer;
  }
  m_iCurBit = v1->m_iCurBit;
  if ( m_iCurBit + 1 > v1->m_nDataBits )
    v1->m_bOverflow = true;
  if ( !v1->m_bOverflow )
  {
    v3 = m_iCurBit >> 3;
    v4 = 1 << (m_iCurBit & 7);
    m_pData = v1->m_pData;
    if ( bValue )
      m_pData[v3] |= v4;
    else
      m_pData[v3] &= ~v4;
    ++v1->m_iCurBit;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101412A0
// Name: public: virtual char const __near * CJob::Describe(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CJob::Describe(CJob *this)
{
  return "Job";
}

//------------------------------------------------------------------------------
// Address: 0x101412B0
// Name: private: virtual int CJob::DoAbort(bool)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CJob::DoAbort(CJob *this, bool bDiscard)
{
  return 3;
}

//------------------------------------------------------------------------------
// Address: 0x101412D0
// Name: public: virtual int CRefCounted1<class IRefCounted,class CRefCountServiceBase<1,class CRefMT>>::AddRef(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CRefCounted1<IRefCounted,CRefCountServiceBase<1,CRefMT>>::AddRef(
        CRefCounted1<IRefCounted,CRefCountServiceBase<1,CRefMT> > *this)
{
  return _InterlockedIncrement(&this->m_iRefs);
}

//------------------------------------------------------------------------------
// Address: 0x101412E0
// Name: public: virtual int CRefCounted1<class IRefCounted,class CRefCountServiceBase<1,class CRefMT>>::Release(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CRefCounted1<IRefCounted,CRefCountServiceBase<1,CRefMT>>::Release(
        CRefCounted1<IRefCounted,CRefCountServiceBase<1,CRefMT> > *this)
{
  CRefCountServiceBase<1,CRefMT> *v1; // esi
  int result; // eax

  v1 = &this->CRefCountServiceBase<1,CRefMT>;
  result = _InterlockedDecrement(&this->m_iRefs);
  if ( result == 0 )
  {
    if ( v1->OnFinalRelease(this: v1) )
      ((void (__thiscall *)(CRefCountServiceBase<1,CRefMT> *, int))v1->dtr_CRefCountServiceBase<1,CRefMT>)(
        a1: v1,
        a2: 1);
    return 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10141310
// Name: public: CFunctorJob::CFunctorJob(class CFunctor __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CFunctorJob *__thiscall CFunctorJob::CFunctorJob(CFunctorJob *this, CFunctor *pFunctor, const char *pszDescription)
{
  this->m_iRefs = 1;
  this->m_priority = JP_NORMAL;
  this->CJob::CRefCounted1<IRefCounted,CRefCountServiceBase<1,CRefMT> >::IRefCounted::__vftable = (CFunctorJob_vtbl *)&CJob::`vftable'{for `IRefCounted'};
  this->CJob::CRefCounted1<IRefCounted,CRefCountServiceBase<1,CRefMT> >::CRefCountServiceBase<1,CRefMT>::__vftable = (CRefCountServiceBase<1,CRefMT>_vtbl *)&CJob::`vftable'{for `CRefCountServiceBase<1,CRefMT>'};
  this->m_status = 4;
  this->m_mutex.m_ownerID = 0;
  this->m_mutex.m_depth = 0;
  this->m_flags = 0;
  this->m_iServicingThread = -1;
  this->m_ThreadPoolData = (ThreadPoolData_t__ *)-1;
  this->m_pThreadPool = nullptr;
  CThreadEvent::CThreadEvent(this: &this->m_CompleteEvent, a2: true);
  this->CJob::CRefCounted1<IRefCounted,CRefCountServiceBase<1,CRefMT> >::IRefCounted::__vftable = (CFunctorJob_vtbl *)&CFunctorJob::`vftable'{for `IRefCounted'};
  this->CJob::CRefCounted1<IRefCounted,CRefCountServiceBase<1,CRefMT> >::CRefCountServiceBase<1,CRefMT>::__vftable = (CRefCountServiceBase<1,CRefMT>_vtbl *)&CFunctorJob::`vftable'{for `CRefCountServiceBase<1,CRefMT>'};
  this->m_pFunctor.m_pObject = pFunctor;
  if ( pszDescription != nullptr )
    V_strncpy(pDest: this->m_szDescription, pSrc: pszDescription, maxLen: 16);
  else
    this->m_szDescription[0] = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101413C0
// Name: public: virtual int CFunctorJob::DoExecute(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CFunctorJob::DoExecute(CFunctorJob *this)
{
  this->m_pFunctor.m_pObject->operator()(this: this->m_pFunctor.m_pObject);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x101413D0
// Name: void DrawAllDebugOverlays(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DrawAllDebugOverlays()
{
  CBasePlayer *v0; // eax
  int v1; // eax
  CBaseEntity *v2; // esi
  CBasePlayer *v3; // eax
  CBasePlayer_vtbl *v4; // edx
  CAI_Link *v5; // eax
  CAI_Link *v6; // esi
  int m_iSrcID; // eax
  CAI_Node *v8; // eax
  int m_iDestID; // eax
  CAI_Node *v10; // eax
  unsigned __int8 m_LinkInfo; // al
  CAI_Node *(__thiscall *FindPickerAINode)(CBasePlayer *, int); // eax
  CAI_Node *v13; // eax
  CAI_Node *v14; // esi
  CAI_Hint *m_pHint; // eax
  const char *pszValue; // eax
  const char *HintTypeDescription; // eax
  CEntInfo *i; // edi
  IHandleEntity *m_pEntity; // esi
  IMDLCache *v20; // ebx
  CEntInfo *m_pHead; // eax
  CBaseEntity *v22; // edi
  IPhysicsObject *m_pPhysicsObject; // esi
  const char *v24; // ebx
  const char *MassEquivalent; // eax
  double v26; // st7
  double v27; // st7
  double v28; // [esp+10h] [ebp-25Ch]
  float flDuration; // [esp+18h] [ebp-254h]
  const char *flDurationa; // [esp+18h] [ebp-254h]
  NDebugOverlay *v31; // [esp+1Ch] [ebp-250h]
  NDebugOverlay *v32; // [esp+1Ch] [ebp-250h]
  char tempstr[512]; // [esp+28h] [ebp-244h] BYREF
  char v34[4]; // [esp+228h] [ebp-44h] BYREF
  Vector endPos; // [esp+22Ch] [ebp-40h] BYREF
  Vector linkDir; // [esp+238h] [ebp-34h] BYREF
  Vector vecPos; // [esp+244h] [ebp-28h] BYREF
  Vector maxs; // [esp+250h] [ebp-1Ch] BYREF
  Vector mins; // [esp+25Ch] [ebp-10h] BYREF
  const CEntInfo *pInfo; // [esp+268h] [ebp-4h]
  int savedregs; // [esp+26Ch] [ebp+0h] BYREF

  NDebugOverlay::PurgeTextOverlays(this: v31);
  if ( CBaseEntity::m_bInDebugSelect )
  {
    v0 = UTIL_PlayerByIndex(playerIndex: CBaseEntity::m_nDebugPlayer);
    if ( v0 != nullptr )
    {
      v1 = (int)v0->FindPickerEntity(this: v0);
      v2 = (CBaseEntity *)v1;
      if ( v1 != 0 )
      {
        (*(void (__thiscall **)(int))(*(_DWORD *)v1 + 168))(a1: v1);
        CBaseEntity::DrawBBoxOverlay(this: v2, flDuration: 0.0);
        CBaseEntity::SendDebugPivotOverlay(this: v2, a2: (int)&savedregs);
      }
    }
  }
  UTIL_DrawOverlayLines();
  if ( engine->IsInEditMode(this: engine) != 0 )
  {
    v3 = UTIL_PlayerByIndex(playerIndex: CBaseEntity::m_nDebugPlayer);
    if ( v3 != nullptr )
    {
      v4 = v3->__vftable;
      if ( CAI_NetworkEditTools::m_bLinkEditMode )
      {
        v5 = v4->FindPickerAILink(this: v3);
        v6 = v5;
        if ( v5 != nullptr )
        {
          m_iSrcID = v5->m_iSrcID;
          if ( m_iSrcID < 0 || m_iSrcID >= g_pBigAINet->m_iNumNodes )
          {
            ++`CAI_Network::GetNode'::`8'::warningCount;
            v8 = nullptr;
          }
          else
          {
            v8 = g_pBigAINet->m_pAInode[m_iSrcID];
          }
          CAI_Node::GetPosition(this: v8, result: &vecPos, hull: CAI_NetworkEditTools::m_iHullDrawNum);
          m_iDestID = v6->m_iDestID;
          if ( m_iDestID < 0 || m_iDestID >= g_pBigAINet->m_iNumNodes )
          {
            ++`CAI_Network::GetNode'::`8'::warningCount;
            v10 = nullptr;
          }
          else
          {
            v10 = g_pBigAINet->m_pAInode[m_iDestID];
          }
          CAI_Node::GetPosition(this: v10, result: &endPos, hull: CAI_NetworkEditTools::m_iHullDrawNum);
          linkDir.x = vecPos.x - endPos.x;
          linkDir.y = vecPos.y - endPos.y;
          linkDir.z = vecPos.z - endPos.z;
          *(float *)&pInfo = VectorNormalize(vec: &linkDir);
          m_LinkInfo = v6->m_LinkInfo;
          if ( (m_LinkInfo & 2) != 0 )
          {
            LODWORD(maxs.x) = (unsigned int)pInfo ^ _mask__NegFloat_;
            maxs.y = 4.0;
            maxs.z = 4.0;
            mins.x = -4.0;
            mins.y = -4.0;
            mins.z = -4.0;
            NDebugOverlay::BoxDirection(
              origin: &vecPos,
              &mins,
              &maxs,
              orientation: &linkDir,
              r: 0,
              g: 255,
              b: 0,
              a: 40,
              duration: 0.0);
          }
          else
          {
            LODWORD(mins.x) = (unsigned int)pInfo ^ _mask__NegFloat_;
            mins.y = 4.0;
            mins.z = 4.0;
            maxs.x = -4.0;
            maxs.y = -4.0;
            maxs.z = -4.0;
            if ( (m_LinkInfo & 0x10) != 0 )
              NDebugOverlay::BoxDirection(
                origin: &vecPos,
                mins: &maxs,
                maxs: &mins,
                orientation: &linkDir,
                r: 40,
                g: 255,
                b: 0,
                a: 40,
                duration: 0.0);
            else
              NDebugOverlay::BoxDirection(
                origin: &vecPos,
                mins: &maxs,
                maxs: &mins,
                orientation: &linkDir,
                r: 255,
                g: 0,
                b: 0,
                a: 40,
                duration: 0.0);
          }
        }
      }
      else
      {
        FindPickerAINode = v4->FindPickerAINode;
        if ( CAI_NetworkEditTools::m_bAirEditMode )
          v13 = (CAI_Node *)((int (__stdcall *)(int))FindPickerAINode)(a1: 3);
        else
          v13 = (CAI_Node *)((int (__stdcall *)(int))FindPickerAINode)(a1: 2);
        v14 = v13;
        if ( v13 != nullptr )
        {
          CAI_Node::GetPosition(this: v13, result: &vecPos, hull: CAI_NetworkEditTools::m_iHullDrawNum);
          mins.x = 8.0;
          mins.y = 8.0;
          mins.z = 8.0;
          maxs.x = -8.0;
          maxs.y = -8.0;
          maxs.z = -8.0;
          NDebugOverlay::Box(origin: &vecPos, mins: &maxs, maxs: &mins, r: 255, g: 0, b: 0, a: 40, flDuration: 0.0);
          m_pHint = v14->m_pHint;
          if ( m_pHint != nullptr )
          {
            pszValue = m_pHint->m_iName.m_Value.pszValue;
            if ( pszValue != nullptr )
            {
              mins.x = vecPos.x;
              mins.y = vecPos.y;
              mins.z = vecPos.z + 6.0;
              NDebugOverlay::Text(origin: &mins, text: pszValue, bViewCheck: false, duration: 0.0);
            }
            HintTypeDescription = GetHintTypeDescription(pHint: v14->m_pHint);
            NDebugOverlay::Text(origin: &vecPos, text: HintTypeDescription, bViewCheck: false, duration: 0.0);
          }
        }
      }
      if ( CAI_NetworkEditTools::m_bAirEditMode )
        UTIL_DrawPositioningOverlay(flCrossDistance: CAI_NetworkEditTools::m_flAirEditDistance);
      else
        NDebugOverlay::DrawGroundCrossHairOverlay(this: v32);
    }
  }
  if ( g_pAINetworkManager != nullptr )
    CAI_NetworkEditTools::DrawAINetworkOverlay(this: g_pAINetworkManager->m_pEditOps);
  if ( g_pDeveloper->m_pParent != nullptr && g_pDeveloper->m_pParent->m_Value.m_nValue != 0 )
  {
    for ( i = gEntList.m_activeList.m_pHead; i != nullptr; i = i->m_pNext )
    {
      m_pEntity = i->m_pEntity;
      if ( i->m_pEntity[201].__vftable != nullptr || m_pEntity[202].__vftable != nullptr )
      {
        v20 = mdlcache;
        mdlcache->BeginLock(this: mdlcache);
        m_pEntity->__vftable[13].GetRefEHandle(this: m_pEntity);
        v20->EndLock(this: v20);
      }
    }
  }
  if ( sv_massreport.m_pParent != nullptr && sv_massreport.m_pParent->m_Value.m_nValue != 0 )
  {
    m_pHead = gEntList.m_activeList.m_pHead;
    pInfo = gEntList.m_activeList.m_pHead;
    if ( gEntList.m_activeList.m_pHead != nullptr )
    {
      while ( 1 )
      {
        v22 = (CBaseEntity *)m_pHead->m_pEntity;
        if ( m_pHead->m_pEntity[82].__vftable != nullptr )
        {
          m_pPhysicsObject = v22->m_pPhysicsObject;
          v24 = *(const char **)((int (__thiscall *)(CBaseEntity *, char *))v22->GetModelName)(a1: v22, a2: v34);
          if ( v24 == nullptr )
            v24 = locale;
          flDuration = m_pPhysicsObject->GetMass(this: m_pPhysicsObject);
          MassEquivalent = GetMassEquivalent(flMass: flDuration);
          v26 = ((double (__thiscall *)(IPhysicsObject *, const char *))m_pPhysicsObject->GetMass)(
                  a1: m_pPhysicsObject,
                  a2: MassEquivalent);
          v27 = ((double (__thiscall *)(IPhysicsObject *, _DWORD, _DWORD))m_pPhysicsObject->GetMass)(
                  a1: m_pPhysicsObject,
                  a2: COERCE_UNSIGNED_INT64(v26 * 2.2),
                  a3: HIDWORD(COERCE_UNSIGNED_INT64(v26 * 2.2)));
          V_snprintf(
            pDest: tempstr,
            maxLen: 512,
            pFormat: "%s: Mass: %.2f kg / %.2f lb (%s)",
            v24,
            v27,
            v28,
            flDurationa);
          CBaseEntity::EntityText(
            this: v22,
            text_offset: 0,
            text: tempstr,
            duration: 0.0,
            r: 255,
            g: 255,
            b: 255,
            a: 255);
          m_pHead = (CEntInfo *)pInfo;
        }
        pInfo = m_pHead->m_pNext;
        if ( *(float *)&pInfo == 0.0 )
          break;
        m_pHead = (CEntInfo *)pInfo;
      }
    }
  }
  DrawMessageEntities();
}

//------------------------------------------------------------------------------
// Address: 0x101418C0
// Name: public: virtual void CServerGameDLL::PreClientUpdate(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CServerGameDLL::PreClientUpdate(CServerGameDLL *this, bool simulating)
{
  if ( simulating )
  {
    DrawAllDebugOverlays();
    IGameSystem::PreClientUpdateAllSystems();
  }
}

//------------------------------------------------------------------------------
// Address: 0x101418E0
// Name: public: virtual void CServerGameDLL::Think(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CServerGameDLL::Think(CServerGameDLL *this, bool finalTick)
{
  float m_fAutoSaveDangerousTime; // xmm0_4
  CBasePlayer *v4; // eax
  float m_Value; // xmm0_4

  m_fAutoSaveDangerousTime = this->m_fAutoSaveDangerousTime;
  if ( m_fAutoSaveDangerousTime != 0.0 && gpGlobals->curtime > m_fAutoSaveDangerousTime )
  {
    v4 = UTIL_PlayerByIndex(playerIndex: 1);
    if ( v4 != nullptr )
    {
      m_Value = v4->m_flDeathTime.m_Value;
      if ( (m_Value == 0.0 || m_Value > gpGlobals->curtime)
        && !v4->m_bSinglePlayerGameEnding
        && (float)v4->m_iHealth.m_Value >= this->m_fAutoSaveDangerousMinHealthToCommit )
      {
        engine->ServerCommand(this: engine, a2: "autosavedangerousissafe\n");
      }
    }
    this->m_fAutoSaveDangerousTime = 0.0;
    this->m_fAutoSaveDangerousMinHealthToCommit = 0.0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10141980
// Name: public: virtual void CServerGameEnts::CheckTransmit(class CCheckTransmitInfo __near *,unsigned short const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CServerGameEnts::CheckTransmit(
        CServerGameEnts *this,
        CCheckTransmitInfo *pInfo,
        const unsigned __int16 *pEdictIndices,
        int nEdicts)
{
  edict_t *pEdicts; // edx
  CCheckTransmitInfo *v5; // ebx
  edict_t *m_pClientEnt; // eax
  IServerUnknown *m_pUnk; // eax
  int v8; // esi
  IMDLCache *v9; // edi
  int v10; // eax
  signed int v11; // esi
  edict_t *m_pPev; // edi
  int v13; // eax
  bool v14; // zf
  int v15; // eax
  int v16; // esi
  int v17; // eax
  CServerNetworkProperty *m_pNetworkable; // edi
  CServerNetworkProperty *NetworkParent; // eax
  CBaseEntity *v20; // esi
  CServerNetworkProperty *v21; // edi
  int v22; // eax
  CServerNetworkProperty *v23; // esi
  edict_t *v24; // eax
  edict_t *v25; // edx
  int v26; // esi
  void (__thiscall *SetTransmit)(CBaseEntity *, CCheckTransmitInfo *, bool); // edx
  IMDLCache *cacheCriticalSection; // [esp+4h] [ebp-18h]
  edict_t *v29; // [esp+8h] [ebp-14h]
  int i; // [esp+Ch] [ebp-10h]
  int skyBoxArea; // [esp+10h] [ebp-Ch]
  CBaseEntity *pEnt; // [esp+14h] [ebp-8h]
  char bIsHLTV; // [esp+1Bh] [ebp-1h]

  pEdicts = gpGlobals->pEdicts;
  v5 = pInfo;
  m_pClientEnt = pInfo->m_pClientEnt;
  v29 = pEdicts;
  if ( pInfo->m_pClientEnt == nullptr )
  {
    if ( pEdicts == nullptr || (pEdicts->m_fStateFlags & 2) != 0 )
      return;
    m_pClientEnt = gpGlobals->pEdicts;
  }
  m_pUnk = m_pClientEnt->m_pUnk;
  if ( m_pUnk == nullptr )
    return;
  v8 = (int)m_pUnk->GetBaseEntity(this: m_pUnk);
  if ( v8 == 0 )
    return;
  v9 = mdlcache;
  cacheCriticalSection = mdlcache;
  mdlcache->BeginLock(this: mdlcache);
  v10 = 0;
  skyBoxArea = *(_DWORD *)(v8 + 2456);
  bIsHLTV = *(_BYTE *)(v8 + 2940);
  i = 0;
  if ( nEdicts <= 0 )
    goto LABEL_43;
  do
  {
    v11 = pEdictIndices[v10];
    m_pPev = &v29[v11];
    v13 = m_pPev->m_fStateFlags & 0x38;
    if ( (m_pPev->m_fStateFlags & 0x10) == 0 )
    {
      v14 = ((1 << (v11 & 0x1F)) & v5->m_pTransmitEdict->m_Ints[(unsigned int)v11 >> 5]) == 0;
      v5 = pInfo;
      if ( v14 )
      {
        if ( (m_pPev->m_fStateFlags & 8) != 0 )
        {
          while ( 1 )
          {
            v15 = v11 >> 5;
            v16 = 1 << (v11 & 0x1F);
            v17 = v15;
            pInfo->m_pTransmitEdict->m_Ints[v17] |= v16;
            if ( bIsHLTV != 0 )
              pInfo->m_pTransmitAlways->m_Ints[v17] |= v16;
            m_pNetworkable = (CServerNetworkProperty *)m_pPev->m_pNetworkable;
            if ( m_pNetworkable == nullptr )
              break;
            NetworkParent = CServerNetworkProperty::GetNetworkParent(this: m_pNetworkable);
            if ( NetworkParent == nullptr )
              break;
            m_pPev = NetworkParent->m_pPev;
            if ( m_pPev != nullptr )
              v11 = m_pPev - gpGlobals->pEdicts;
            else
              v11 = 0;
          }
        }
        else
        {
          v20 = (CBaseEntity *)m_pPev->m_pUnk;
          pEnt = v20;
          if ( v13 == 0 )
          {
            LOBYTE(v13) = v20->ShouldTransmit(this: v20, a2: pInfo);
            if ( (v13 & 8) != 0 )
            {
LABEL_20:
              ((void (__stdcall *)(CCheckTransmitInfo *, int))v20->SetTransmit)(a1: pInfo, a2: 1);
              goto LABEL_41;
            }
          }
          if ( (v13 & 0x20) != 0 )
          {
            v21 = (CServerNetworkProperty *)m_pPev->m_pNetworkable;
            v22 = v21->AreaNum(this: v21);
            if ( bIsHLTV != 0 )
            {
              SetTransmit = v20->SetTransmit;
              if ( v22 != skyBoxArea )
                goto LABEL_40;
              ((void (__stdcall *)(CCheckTransmitInfo *, int))SetTransmit)(a1: pInfo, a2: 1);
            }
            else
            {
              if ( v22 == skyBoxArea )
                goto LABEL_20;
              if ( CServerNetworkProperty::IsInPVS(this: v21, pInfo)
                || sv_force_transmit_ents.m_pParent != nullptr
                && sv_force_transmit_ents.m_pParent->m_Value.m_nValue != 0 )
              {
                SetTransmit = v20->SetTransmit;
LABEL_40:
                ((void (__stdcall *)(CCheckTransmitInfo *, _DWORD))SetTransmit)(a1: pInfo, a2: 0);
                goto LABEL_41;
              }
              v23 = CServerNetworkProperty::GetNetworkParent(this: v21);
              if ( v23 != nullptr )
              {
                while ( 1 )
                {
                  v24 = CServerNetworkProperty::entindex(this: v23);
                  if ( ((1 << ((unsigned __int8)v24 & 0x1F)) & pInfo->m_pTransmitEdict->m_Ints[(unsigned int)v24 >> 5]) != 0 )
                    break;
                  v25 = v23->m_pPev;
                  if ( (v25->m_fStateFlags & 0x10) != 0 )
                    goto LABEL_41;
                  if ( (v25->m_fStateFlags & 8) != 0 )
                    break;
                  if ( (v25->m_fStateFlags & 0x38) == 0 )
                  {
                    v26 = (int)v23->GetBaseEntity(this: v23);
                    if ( ((*(int (__thiscall **)(int, CCheckTransmitInfo *))(*(_DWORD *)v26 + 80))(a1: v26, a2: pInfo)
                        & 8) == 0 )
                      goto LABEL_41;
                    (*(void (__thiscall **)(int, CCheckTransmitInfo *, int))(*(_DWORD *)v26 + 88))(
                      a1: v26,
                      a2: pInfo,
                      a3: 1);
                    break;
                  }
                  if ( (v25->m_fStateFlags & 0x20) != 0 )
                  {
                    CServerNetworkProperty::RecomputePVSInformation(this: v23);
                    if ( CServerNetworkProperty::IsInPVS(this: v23, pInfo) )
                      break;
                  }
                  v23 = CServerNetworkProperty::GetNetworkParent(this: v23);
                  if ( v23 == nullptr )
                    goto LABEL_41;
                }
                ((void (__stdcall *)(CCheckTransmitInfo *, int))pEnt->SetTransmit)(a1: pInfo, a2: 1);
              }
            }
          }
        }
      }
    }
LABEL_41:
    v10 = i + 1;
    i = v10;
  }
  while ( v10 < nEdicts );
  v9 = cacheCriticalSection;
LABEL_43:
  v9->EndLock(this: v9);
}

//------------------------------------------------------------------------------
// Address: 0x10141C10
// Name: public: virtual void CServerGameClients::ClientSettingsChanged(struct edict_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CServerGameClients::ClientSettingsChanged(CServerGameClients *this@<ecx>, int a2@<esi>, float pEdict)
{
  IServerUnknown *v3; // ecx
  int v4; // eax
  CBasePlayer *v5; // esi
  int v6; // eax
  signed int v7; // eax
  const char *v8; // eax
  int v9; // eax
  bool v10; // zf
  ConVar *(__thiscall *FindVar_2)(ICvar *, const char *); // eax
  ICvar_vtbl *v12; // edx
  const ConVar *v13; // eax
  ConVar *m_pParent; // edx
  float m_fValue; // xmm1_4
  int m_nUpdateRate; // eax
  float v17; // xmm2_4
  edict_t *m_pPev; // eax
  signed int v19; // eax
  const char *v20; // eax
  edict_t *v21; // eax
  signed int v22; // eax
  const char *v23; // eax
  double v24; // st7
  edict_t *v25; // eax
  signed int v26; // eax
  const char *v27; // eax
  ICvar_vtbl *v28; // edx
  ICvar_vtbl *v29; // edx
  const ConVar *v30; // ecx
  float v31; // xmm0_4
  float v32; // xmm0_4
  float v33; // xmm0_4
  edict_t *v34; // eax
  signed int v35; // eax
  const char *v36; // eax
  bool v37; // al
  edict_t *v38; // eax
  signed int v39; // eax
  const char *v40; // eax
  edict_t *v41; // eax
  signed int v42; // eax
  const char *v43; // eax
  CUtlVector<CHandle<CBasePlayer>,CUtlMemory<CHandle<CBasePlayer>,int> > *SplitScreenPlayers; // eax
  int i; // edi
  unsigned int m_Index; // ecx
  CEntInfo *v47; // edx
  IHandleEntity *m_pEntity; // ecx
  float flLerpAmount; // [esp+4h] [ebp-Ch]
  float minVal; // [esp+8h] [ebp-8h] BYREF
  float maxVal; // [esp+Ch] [ebp-4h] BYREF

  v3 = *(IServerUnknown **)(LODWORD(pEdict) + 12);
  if ( v3 != nullptr )
  {
    v4 = (int)v3->GetBaseEntity(this: v3);
    v5 = (CBasePlayer *)v4;
    if ( v4 != 0 )
    {
      v6 = *(_DWORD *)(v4 + 24);
      if ( v6 != 0 )
        v7 = (signed int)(v6 - (unsigned int)gpGlobals->pEdicts) >> 4;
      else
        v7 = 0;
      v8 = (const char *)((int (__thiscall *)(IVEngineServer *, signed int, const char *, int))engine->GetClientConVarValue)(
                           a1: engine,
                           a2: v7,
                           a3: "cl_updaterate",
                           a4: a2);
      v9 = V_atoi(str: v8);
      v10 = (_S3_71 & 1) == 0;
      v5->m_nUpdateRate = v9;
      if ( v10 )
      {
        FindVar_2 = g_pCVar->FindVar_2;
        _S3_71 |= 1u;
        pMinUpdateRate = FindVar_2(this: g_pCVar, a2: "sv_minupdaterate");
      }
      if ( (_S3_71 & 2) != 0 )
      {
        v13 = pMaxUpdateRate;
      }
      else
      {
        v12 = g_pCVar->__vftable;
        _S3_71 |= 2u;
        v13 = v12->FindVar_2(this: g_pCVar, a2: "sv_maxupdaterate");
        pMaxUpdateRate = v13;
      }
      if ( pMinUpdateRate != nullptr && v13 != nullptr )
      {
        m_pParent = v13->m_pParent;
        m_fValue = pMinUpdateRate->m_pParent->m_Value.m_fValue;
        m_nUpdateRate = v5->m_nUpdateRate;
        v17 = m_pParent->m_Value.m_fValue;
        if ( m_fValue <= (float)m_nUpdateRate )
        {
          if ( (float)m_nUpdateRate > v17 )
            m_nUpdateRate = (int)v17;
        }
        else
        {
          m_nUpdateRate = (int)m_fValue;
        }
        v5->m_nUpdateRate = m_nUpdateRate;
      }
      m_pPev = v5->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        v19 = m_pPev - gpGlobals->pEdicts;
      else
        v19 = 0;
      v20 = engine->GetClientConVarValue(this: engine, a2: v19, a3: "cl_interpolate");
      if ( V_atoi(str: v20) != 0 )
      {
        v21 = v5->m_Network.m_pPev;
        if ( v21 != nullptr )
          v22 = v21 - gpGlobals->pEdicts;
        else
          v22 = 0;
        v23 = engine->GetClientConVarValue(this: engine, a2: v22, a3: "cl_interp_ratio");
        v24 = V_atof(str: v23);
        pEdict = v24;
        if ( v24 == 0.0 )
          pEdict = 1.0;
        v25 = v5->m_Network.m_pPev;
        if ( v25 != nullptr )
          v26 = v25 - gpGlobals->pEdicts;
        else
          v26 = 0;
        v27 = engine->GetClientConVarValue(this: engine, a2: v26, a3: "cl_interp");
        flLerpAmount = V_atof(str: v27);
        if ( (_S3_71 & 4) == 0 )
        {
          v28 = g_pCVar->__vftable;
          _S3_71 |= 4u;
          pMin = v28->FindVar_2(this: g_pCVar, a2: "sv_client_min_interp_ratio");
        }
        if ( (_S3_71 & 8) != 0 )
        {
          v30 = pMax;
        }
        else
        {
          v29 = g_pCVar->__vftable;
          _S3_71 |= 8u;
          v30 = v29->FindVar_2(this: g_pCVar, a2: "sv_client_max_interp_ratio");
          pMax = v30;
        }
        if ( pMin != nullptr && v30 != nullptr && (v31 = pMin->m_pParent->m_Value.m_fValue) != -1.0 )
        {
          maxVal = v30->m_pParent->m_Value.m_fValue;
          minVal = v31;
          pEdict = clamp<float,float,float>(val: &pEdict, &minVal, &maxVal);
          v32 = pEdict;
        }
        else
        {
          v32 = pEdict;
          if ( pEdict == 0.0 )
            v32 = 1.0;
        }
        v33 = v32 / (float)v5->m_nUpdateRate;
        if ( flLerpAmount > v33 )
          v33 = flLerpAmount;
      }
      else
      {
        v33 = 0.0;
      }
      v34 = v5->m_Network.m_pPev;
      v5->m_fLerpTime = v33;
      if ( v34 != nullptr )
        v35 = v34 - gpGlobals->pEdicts;
      else
        v35 = 0;
      v36 = engine->GetClientConVarValue(this: engine, a2: v35, a3: "cl_predict");
      v37 = V_atoi(str: v36) != 0;
      if ( v37 )
      {
        v5->m_bPredictionEnabled = v37;
        v38 = v5->m_Network.m_pPev;
        if ( v38 != nullptr )
          v39 = v38 - gpGlobals->pEdicts;
        else
          v39 = 0;
        v40 = engine->GetClientConVarValue(this: engine, a2: v39, a3: "cl_predictweapons");
        v10 = V_atoi(str: v40) == 0;
        v41 = v5->m_Network.m_pPev;
        v5->m_bPredictWeapons = !v10;
        if ( v41 != nullptr )
          v42 = v41 - gpGlobals->pEdicts;
        else
          v42 = 0;
        v43 = engine->GetClientConVarValue(this: engine, a2: v42, a3: "cl_lagcompensation");
        v5->m_bLagCompensation = V_atoi(str: v43) != 0;
      }
      else
      {
        *(_WORD *)&v5->m_bPredictWeapons = 0;
        v5->m_bLagCompensation = false;
      }
      SplitScreenPlayers = CBasePlayer::GetSplitScreenPlayers(this: v5);
      for ( i = 0; i < SplitScreenPlayers->m_Size; ++i )
      {
        m_Index = SplitScreenPlayers->m_Memory.m_pMemory[i].m_Index;
        if ( m_Index != -1 )
        {
          v47 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index];
          if ( g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index) )
          {
            m_pEntity = v47->m_pEntity;
            if ( v47->m_pEntity != nullptr )
            {
              BYTE2(m_pEntity[755].__vftable) = v5->m_bPredictionEnabled;
              BYTE1(m_pEntity[755].__vftable) = v5->m_bPredictWeapons;
              LOBYTE(m_pEntity[755].__vftable) = v5->m_bLagCompensation;
            }
          }
        }
      }
      g_pGameRules->ClientSettingsChanged(this: g_pGameRules, a2: v5);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10142040
// Name: public: virtual float CServerGameClients::ProcessUsercmds(struct edict_t __near *,class bf_read __near *,int,int,int,bool,bool)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CServerGameClients::ProcessUsercmds(
        CServerGameClients *this,
        edict_t *player,
        bf_read *buf,
        int numcmds,
        unsigned int totalcmds,
        int dropped_packets,
        bool ignore,
        int paused)
{
  int v8; // ecx
  float *p_z; // eax
  edict_t *pEdicts; // eax
  int v11; // esi
  IServerUnknown *m_pUnk; // ecx
  int v13; // edi
  int v14; // edi
  CUserCmd *v15; // eax
  CUserCmd *v16; // esi
  IMDLCache *v17; // edi
  CUserCmd *v18; // eax
  int k; // ecx
  CUserCmd *v21; // eax
  int j; // ecx
  const char *v23; // eax
  CUserCmd *p_from; // eax
  int i; // ecx
  CUserCmd move[64]; // [esp+0h] [ebp-165Ch] BYREF
  CUserCmd from; // [esp+1600h] [ebp-5Ch] BYREF
  int v28; // [esp+1658h] [ebp-4h]
  float interval_per_tick; // [esp+1678h] [ebp+1Ch]

  v8 = 63;
  p_z = &move[0].viewangles.z;
  do
  {
    *((_DWORD *)p_z - 5) = &CUserCmd::`vftable';
    *(p_z - 4) = 0.0;
    *(p_z - 3) = 0.0;
    *(p_z - 2) = 0.0;
    *(p_z - 1) = 0.0;
    *p_z = 0.0;
    p_z[1] = 0.0;
    p_z[2] = 0.0;
    p_z[3] = 0.0;
    p_z[4] = 0.0;
    *((_BYTE *)p_z + 20) = 0;
    p_z[6] = 0.0;
    p_z[7] = 0.0;
    p_z[8] = 0.0;
    *((_BYTE *)p_z + 40) = 0;
    *((_WORD *)p_z + 18) = 0;
    *((_WORD *)p_z + 19) = 0;
    p_z[11] = 0.0;
    p_z[12] = 0.0;
    p_z[13] = 0.0;
    p_z[14] = 0.0;
    p_z[15] = 0.0;
    p_z[16] = 0.0;
    p_z += 22;
    --v8;
  }
  while ( v8 >= 0 );
  pEdicts = player;
  v11 = 0;
  from.__vftable = (CUserCmd_vtbl *)&CUserCmd::`vftable';
  memset(&from.command_number, 0, 37);
  memset(&from.weaponselect, 0, 17);
  memset((void *)&from.headangles, 0, 24);
  v28 = 0;
  if ( player != nullptr || gpGlobals->pEdicts != nullptr && ((pEdicts = gpGlobals->pEdicts)->m_fStateFlags & 2) == 0 )
  {
    m_pUnk = pEdicts->m_pUnk;
    if ( m_pUnk != nullptr )
    {
      v13 = (int)m_pUnk->GetBaseEntity(this: m_pUnk);
      if ( v13 != 0 && (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v13 + 336))(a1: v13) != 0 )
      {
        v28 = v13;
        v11 = v13;
      }
    }
  }
  if ( totalcmds > 0x3E )
  {
    v23 = "unknown";
    if ( v11 != 0 )
      v23 = (const char *)(*(int (__thiscall **)(int))(*(_DWORD *)v11 + 160))(a1: v11);
    _Msg(a1: "CBasePlayer::ProcessUsercmds: too many cmds %i sent for player %s\n", totalcmds, v23);
    buf->m_bOverflow = true;
    p_from = &from;
    for ( i = 63; i >= 0; --i )
    {
      --p_from;
      p_from->__vftable = (CUserCmd_vtbl *)&CUserCmd::`vftable';
    }
    return 0.0;
  }
  else
  {
    v14 = totalcmds - 1;
    memset(&from.command_number, 0, 37);
    memset(&from.weaponselect, 0, 17);
    memset((void *)&from.headangles, 0, 24);
    v15 = &from;
    if ( (int)(totalcmds - 1) >= 0 )
    {
      v16 = &move[v14];
      do
      {
        ReadUsercmd(buf, move: v16, from: v15);
        v15 = v16;
        --v14;
        --v16;
      }
      while ( v14 >= 0 );
      v11 = v28;
    }
    if ( ignore || v11 == 0 )
    {
      v21 = &from;
      for ( j = 63; j >= 0; --j )
      {
        --v21;
        v21->__vftable = (CUserCmd_vtbl *)&CUserCmd::`vftable';
      }
      return 0.0;
    }
    else
    {
      v17 = mdlcache;
      mdlcache->BeginLock(this: mdlcache);
      (*(void (__thiscall **)(int, CUserCmd *, int, unsigned int, int, int))(*(_DWORD *)v11 + 1796))(
        a1: v11,
        a2: move,
        a3: numcmds,
        a4: totalcmds,
        a5: dropped_packets,
        a6: paused);
      interval_per_tick = gpGlobals->interval_per_tick;
      v17->EndLock(this: v17);
      v18 = &from;
      for ( k = 63; k >= 0; --k )
      {
        --v18;
        v18->__vftable = (CUserCmd_vtbl *)&CUserCmd::`vftable';
      }
      return interval_per_tick;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10142300
// Name: public: virtual void CFunctor1<void (*)(bool),bool,class CRefCounted1<class CFunctor,class CRefCountServiceBase<1,class CRefMT>>>::operator()(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFunctor1<void (__cdecl *)(bool),bool,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>>::operator()(
        CFunctor1<void (__cdecl*)(bool),bool,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> > > *this)
{
  this->m_pfnProxied(a1: this->m_arg1);
}

//------------------------------------------------------------------------------
// Address: 0x10142500
// Name: class CFunctor __near * CreateFunctor<void,bool,bool>(void (*)(bool),bool const __near &)
// Source: json
//------------------------------------------------------------------------------
CFunctor *__cdecl CreateFunctor<void,bool,bool>(void (__cdecl *pfnProxied)(bool), const bool *arg1)
{
  CFunctor *result; // eax

  result = (CFunctor *)operator new(nSize: 0x18u);
  if ( result == nullptr )
    return nullptr;
  result[1].m_nUserID = 1;
  result->__vftable = (CFunctor_vtbl *)&CFunctor1<void (__cdecl *)(bool),bool,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>>::`vftable'{for `CFunctor'};
  result[1].__vftable = (CFunctor_vtbl *)&CFunctor1<void (__cdecl *)(bool),bool,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>>::`vftable'{for `CRefCountServiceBase<1,CRefMT>'};
  result[2].__vftable = (CFunctor_vtbl *)pfnProxied;
  LOBYTE(result[2].m_nUserID) = *arg1;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10142640
// Name: public: virtual bool CServerGameDLL::DLLInit(void __near * (*)(char const __near *,int __near *),void __near * (*)(char const __near *,int __near *),void __near * (*)(char const __near *,int __near *),class CGlobalVars __near *)
// Source: json
//------------------------------------------------------------------------------
char __userpurge CServerGameDLL::DLLInit@<al>(
        CServerGameDLL *this@<ecx>,
        int a2@<esi>,
        void *(__cdecl *appSystemFactory)(const char *, int *),
        void *(__cdecl *physicsFactory)(const char *, int *),
        float fileSystemFactory,
        float pGlobals)
{
  vgui::Panel *v6; // ecx
  void *(__cdecl *v8)(const char *, int *); // ebx
  int v9; // eax
  void (__thiscall ***v10)(_DWORD, const char *, CServerGameDLL *); // eax
  int v11; // eax
  ConVar *v12; // eax
  ICvar_vtbl *v13; // edx
  ConVar *v14; // eax
  ICvar_vtbl *v15; // edx
  ISaveRestoreBlockSet_vtbl *v16; // esi
  ISaveRestoreBlockHandler *EntitySaveRestoreBlockHandler; // eax
  ISaveRestoreBlockSet_vtbl *v18; // esi
  ISaveRestoreBlockHandler *PhysSaveRestoreBlockHandler; // eax
  ISaveRestoreBlockSet_vtbl *v20; // esi
  ISaveRestoreBlockHandler *AISaveRestoreBlockHandler; // eax
  ISaveRestoreBlockSet_vtbl *v22; // esi
  ISaveRestoreBlockHandler *TemplateSaveRestoreBlockHandler; // eax
  ISaveRestoreBlockSet_vtbl *v24; // esi
  ISaveRestoreBlockHandler *v25; // eax
  ISaveRestoreBlockSet_vtbl *v26; // esi
  ISaveRestoreBlockHandler *CommentarySaveRestoreBlockHandler; // eax
  ISaveRestoreBlockSet_vtbl *v28; // esi
  ISaveRestoreBlockHandler *EventQueueSaveRestoreBlockHandler; // eax
  ISaveRestoreBlockSet_vtbl *v30; // esi
  ISaveRestoreBlockHandler *VScriptSaveRestoreBlockHandler; // eax
  CFunctorJob *v32; // esi
  CFunctor *v33; // eax
  CFunctorJob *v34; // esi
  double v35; // st7
  void (__thiscall *RefreshScreenIfNecessary)(IVEngineServer *); // eax
  int v37; // [esp+38h] [ebp-1Ch]
  factorylist_t factories; // [esp+44h] [ebp-10h] BYREF
  CServerGameDLL *v39; // [esp+50h] [ebp-4h]

  v39 = this;
  _COM_TimestampedLog(a1: "ConnectTier1/2/3Libraries - Start");
  ConnectTier1Libraries(pFactoryList: &appSystemFactory, nFactoryCount: 1);
  ConnectTier2Libraries(pFactoryList: &appSystemFactory, nFactoryCount: 1);
  CAI_BaseNPC::OnSetSchedule(this: v6);
  _COM_TimestampedLog(a1: "ConnectTier1/2/3Libraries - Finish");
  if ( cvar != nullptr )
  {
    _SteamAPI_InitSafe();
    CSteamAPIContext::Init(this: &s_SteamAPIContext);
    CSteamGameServerAPIContext::Init(this: &s_SteamGameServerAPIContext);
    _COM_TimestampedLog(a1: "Factories - Start");
    engine = (IVEngineServer *)appSystemFactory(a1: "VEngineServer022", a2: nullptr);
    if ( engine != nullptr )
    {
      g_pVoiceServer = (IVoiceServer *)appSystemFactory(a1: "VoiceServer002", a2: nullptr);
      if ( g_pVoiceServer != nullptr )
      {
        networkstringtable = (INetworkStringTableContainer *)appSystemFactory(
                                                               a1: "VEngineServerStringTable001",
                                                               a2: nullptr);
        if ( networkstringtable != nullptr )
        {
          staticpropmgr = (IStaticPropMgrServer *)appSystemFactory(a1: "StaticPropMgrServer002", a2: nullptr);
          if ( staticpropmgr != nullptr )
          {
            random = (IUniformRandomStream *)appSystemFactory(a1: "VEngineRandom001", a2: nullptr);
            if ( random != nullptr )
            {
              enginesound = (IEngineSound *)appSystemFactory(a1: "IEngineSoundServer003", a2: nullptr);
              if ( enginesound != nullptr )
              {
                partition = (ISpatialPartition *)appSystemFactory(a1: "SpatialPartition001", a2: nullptr);
                if ( partition != nullptr )
                {
                  modelinfo = (IVModelInfo *)appSystemFactory(a1: "VModelInfoServer002", a2: nullptr);
                  if ( modelinfo != nullptr )
                  {
                    enginetrace = (IEngineTrace *)appSystemFactory(a1: "EngineTraceServer004", a2: nullptr);
                    if ( enginetrace != nullptr )
                    {
                      filelogginglistener = (IFileLoggingListener *)appSystemFactory(
                                                                      a1: "FileLoggingListener001",
                                                                      a2: nullptr);
                      if ( filelogginglistener != nullptr )
                      {
                        v8 = (void *(__cdecl *)(const char *, int *))LODWORD(fileSystemFactory);
                        filesystem = (IFileSystem *)((int (__cdecl *)(const char *, _DWORD))LODWORD(fileSystemFactory))(
                                                      a1: "VFileSystem017",
                                                      a2: 0);
                        if ( filesystem != nullptr )
                        {
                          gameeventmanager = (IGameEventManager2 *)appSystemFactory(
                                                                     a1: "GAMEEVENTSMANAGER002",
                                                                     a2: nullptr);
                          if ( gameeventmanager != nullptr )
                          {
                            datacache = (IDataCache *)appSystemFactory(a1: "VDataCache003", a2: nullptr);
                            if ( datacache != nullptr )
                            {
                              soundemitterbase = (ISoundEmitterSystemBase *)appSystemFactory(
                                                                              a1: "VSoundEmitter003",
                                                                              a2: nullptr);
                              if ( soundemitterbase != nullptr )
                              {
                                gamestatsuploader = (IUploadGameStats *)appSystemFactory(
                                                                          a1: "ServerUploadGameStats001",
                                                                          a2: nullptr);
                                if ( gamestatsuploader != nullptr && mdlcache != nullptr )
                                {
                                  serverpluginhelpers = (IServerPluginHelpers *)appSystemFactory(
                                                                                  a1: "ISERVERPLUGINHELPERS001",
                                                                                  a2: nullptr);
                                  if ( serverpluginhelpers != nullptr )
                                  {
                                    scenefilecache = (ISceneFileCache *)appSystemFactory(
                                                                          a1: "SceneFileCache002",
                                                                          a2: nullptr);
                                    if ( scenefilecache != nullptr )
                                    {
                                      blackboxrecorder = (IBlackBox *)appSystemFactory(
                                                                        a1: "BlackBoxVersion001",
                                                                        a2: nullptr);
                                      if ( blackboxrecorder != nullptr )
                                      {
                                        xboxsystem = (IXboxSystem *)appSystemFactory(
                                                                      a1: "XboxSystemInterface002",
                                                                      a2: nullptr);
                                        if ( xboxsystem != nullptr )
                                        {
                                          v9 = _CommandLine();
                                          if ( (*(int (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v9 + 12))(
                                                 a1: v9,
                                                 a2: "-noscripting",
                                                 a3: 0) == 0 )
                                            scriptmanager = (IScriptManager *)appSystemFactory(
                                                                                a1: "VScriptManager009",
                                                                                a2: nullptr);
                                          g_pGameTypes = (IGameTypes *)appSystemFactory(
                                                                         a1: "VENGINE_GAMETYPES_VERSION001",
                                                                         a2: nullptr);
                                          if ( g_pGameTypes == nullptr )
                                            return 0;
                                          if ( !engine->IsDedicatedServer(this: engine) )
                                          {
                                            enginevgui = (IEngineVGui *)appSystemFactory(
                                                                          a1: "VEngineVGui001",
                                                                          a2: nullptr);
                                            if ( enginevgui == nullptr )
                                              return 0;
                                            serverenginetools = (IServerEngineTools *)appSystemFactory(
                                                                                        a1: "VSERVERENGINETOOLS001",
                                                                                        a2: nullptr);
                                            gameuifuncs = (IGameUIFuncs *)appSystemFactory(
                                                                            a1: "VENGINE_GAMEUIFUNCS_VERSION005",
                                                                            a2: nullptr);
                                          }
                                          if ( g_pMatchFramework == nullptr )
                                            return 0;
                                          v10 = (void (__thiscall ***)(_DWORD, const char *, CServerGameDLL *))((int (__thiscall *)(IMatchFramework *, int))g_pMatchFramework->GetMatchExtensions)(a1: g_pMatchFramework, a2);
                                          if ( v10 != nullptr )
                                            (**v10)(a1: v10, a2: "ServerGameDLL005", a3: v39);
                                          _COM_TimestampedLog(a1: "Factories - Finish");
                                          _COM_TimestampedLog(a1: "soundemitterbase->Connect");
                                          if ( soundemitterbase->Connect(this: soundemitterbase, a2: appSystemFactory) == 0 )
                                            return 0;
                                          v11 = _CommandLine();
                                          if ( (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v11 + 40))(
                                                 a1: v11,
                                                 a2: "-headtracking") != 0 )
                                            g_bHeadTrackingEnabled = true;
                                          gpGlobals = (CGlobalVars *)LODWORD(pGlobals);
                                          g_pSharedChangeInfo = engine->GetSharedEdictChangeInfo(this: engine);
                                          _COM_TimestampedLog(a1: "MathLib_Init");
                                          MathLib_Init(
                                            gamma: 2.2,
                                            texGamma: 2.2,
                                            brightness: 0.0,
                                            overbright: 2,
                                            bAllow3DNow: true,
                                            bAllowSSE: true,
                                            bAllowSSE2: true,
                                            bAllowMMX: true);
                                          factories.engineFactory = appSystemFactory;
                                          factories.fileSystemFactory = v8;
                                          factories.physicsFactory = physicsFactory;
                                          FactoryList_Store(sourceData: &factories);
                                          _COM_TimestampedLog(a1: "gameeventmanager->LoadEventsFromFile");
                                          gameeventmanager->LoadEventsFromFile(
                                            this: gameeventmanager,
                                            a2: "resource/gameevents.res");
                                          _COM_TimestampedLog(a1: "InitializeCvars");
                                          InitializeCvars();
                                          _COM_TimestampedLog(a1: "g_pParticleSystemMgr->Init");
                                          LOBYTE(fileSystemFactory) = !engine->IsCreatingXboxReslist(this: engine);
                                          if ( !CParticleSystemMgr::Init(
                                                  this: g_pParticleSystemMgr,
                                                  pQuery: g_pParticleSystemQuery,
                                                  bAllowPrecache: SLOBYTE(fileSystemFactory)) )
                                            return 0;
                                          sv_cheats = g_pCVar->FindVar_2(this: g_pCVar, a2: "sv_cheats");
                                          if ( sv_cheats == nullptr )
                                            return 0;
                                          v12 = (ConVar *)((int (__thiscall *)(ICvar *, const char *, int))g_pCVar->FindVar_2)(
                                                            a1: g_pCVar,
                                                            a2: "commentary",
                                                            a3: v37);
                                          v13 = g_pCVar->__vftable;
                                          g_pcv_commentary = v12;
                                          v14 = v13->FindVar_2(this: g_pCVar, a2: "host_thread_mode");
                                          v15 = g_pCVar->__vftable;
                                          g_pcv_ThreadMode = v14;
                                          sv_maxreplay = v15->FindVar_2(this: g_pCVar, a2: "sv_maxreplay");
                                          _COM_TimestampedLog(a1: "g_pGameSaveRestoreBlockSet");
                                          v16 = g_pGameSaveRestoreBlockSet->__vftable;
                                          EntitySaveRestoreBlockHandler = GetEntitySaveRestoreBlockHandler();
                                          v16->AddBlockHandler(
                                            this: g_pGameSaveRestoreBlockSet,
                                            a2: EntitySaveRestoreBlockHandler);
                                          v18 = g_pGameSaveRestoreBlockSet->__vftable;
                                          PhysSaveRestoreBlockHandler = GetPhysSaveRestoreBlockHandler();
                                          v18->AddBlockHandler(
                                            this: g_pGameSaveRestoreBlockSet,
                                            a2: PhysSaveRestoreBlockHandler);
                                          v20 = g_pGameSaveRestoreBlockSet->__vftable;
                                          AISaveRestoreBlockHandler = GetAISaveRestoreBlockHandler();
                                          v20->AddBlockHandler(
                                            this: g_pGameSaveRestoreBlockSet,
                                            a2: AISaveRestoreBlockHandler);
                                          v22 = g_pGameSaveRestoreBlockSet->__vftable;
                                          TemplateSaveRestoreBlockHandler = GetTemplateSaveRestoreBlockHandler();
                                          v22->AddBlockHandler(
                                            this: g_pGameSaveRestoreBlockSet,
                                            a2: TemplateSaveRestoreBlockHandler);
                                          v24 = g_pGameSaveRestoreBlockSet->__vftable;
                                          v25 = GetDefaultResponseSystemSaveRestoreBlockHandler();
                                          v24->AddBlockHandler(this: g_pGameSaveRestoreBlockSet, a2: v25);
                                          v26 = g_pGameSaveRestoreBlockSet->__vftable;
                                          CommentarySaveRestoreBlockHandler = GetCommentarySaveRestoreBlockHandler();
                                          v26->AddBlockHandler(
                                            this: g_pGameSaveRestoreBlockSet,
                                            a2: CommentarySaveRestoreBlockHandler);
                                          v28 = g_pGameSaveRestoreBlockSet->__vftable;
                                          EventQueueSaveRestoreBlockHandler = GetEventQueueSaveRestoreBlockHandler();
                                          v28->AddBlockHandler(
                                            this: g_pGameSaveRestoreBlockSet,
                                            a2: EventQueueSaveRestoreBlockHandler);
                                          v30 = g_pGameSaveRestoreBlockSet->__vftable;
                                          VScriptSaveRestoreBlockHandler = GetVScriptSaveRestoreBlockHandler();
                                          v30->AddBlockHandler(
                                            this: g_pGameSaveRestoreBlockSet,
                                            a2: VScriptSaveRestoreBlockHandler);
                                          if ( sv_threaded_init.m_pParent != nullptr
                                            && sv_threaded_init.m_pParent->m_Value.m_nValue != 0 )
                                          {
                                            v32 = (CFunctorJob *)operator new(nSize: 0x44u);
                                            if ( v32 != nullptr )
                                            {
                                              HIBYTE(fileSystemFactory) = 0;
                                              v33 = CreateFunctor<void,bool,bool>(
                                                      pfnProxied: ParseParticleEffects,
                                                      arg1: (const bool *)&fileSystemFactory + 3);
                                              v34 = CFunctorJob::CFunctorJob(
                                                      this: v32,
                                                      pFunctor: v33,
                                                      pszDescription: nullptr);
                                            }
                                            else
                                            {
                                              v34 = nullptr;
                                            }
                                            _g_pThreadPool->AddJob(this: _g_pThreadPool, a2: v34);
                                            InitGameSystems(a1: (const char *)v8, appSystemFactory);
                                            fileSystemFactory = -1.0;
                                            while ( !CJob::IsFinished(this: v34) )
                                            {
                                              v35 = _Plat_FloatTime();
                                              pGlobals = v35;
                                              if ( v35 - fileSystemFactory > 0.059999999 )
                                              {
                                                RefreshScreenIfNecessary = engine->RefreshScreenIfNecessary;
                                                fileSystemFactory = pGlobals;
                                                RefreshScreenIfNecessary(this: engine);
                                              }
                                              _ThreadSleep(a1: 0);
                                            }
                                            v34->Release(this: v34);
                                          }
                                          else
                                          {
                                            _COM_TimestampedLog(a1: "ParseParticleEffects");
                                            ParseParticleEffects(bLoadSheets: false);
                                            _COM_TimestampedLog(a1: "InitGameSystems - Start");
                                            InitGameSystems(a1: (const char *)v8, appSystemFactory);
                                            _COM_TimestampedLog(a1: "InitGameSystems - Finish");
                                          }
                                          debugoverlay = (IVDebugOverlay *)appSystemFactory(
                                                                             a1: "VDebugOverlay004",
                                                                             a2: nullptr);
                                          gamestatsuploader->InitConnection(this: gamestatsuploader);
                                          g_pGameTypes->Initialize(this: g_pGameTypes, a2: false);
                                          return 1;
                                        }
                                      }
                                    }
                                  }
                                }
                              }
                            }
                          }
                        }
                        return 0;
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10142CE0
// Name: void EndRestoreEntities(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl EndRestoreEntities()
{
  int i; // ebx
  unsigned int m_Index; // eax
  CBaseEntity **v2; // ecx
  CBaseEntity *v3; // edi
  IMDLCache *v4; // esi
  CHandle<CBaseEntity> *m_pMemory; // eax

  if ( g_InRestore )
  {
    for ( i = g_RestoredEntities.m_Size - 1; i >= 0; --i )
    {
      m_Index = g_RestoredEntities.m_Memory.m_pMemory[i].m_Index;
      if ( m_Index != -1 )
      {
        v2 = (CBaseEntity **)&g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index];
        if ( g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index) )
        {
          v3 = *v2;
          if ( *v2 != nullptr && !CBaseEntity::IsDormant(this: *v2) )
          {
            v4 = mdlcache;
            mdlcache->BeginLock(this: mdlcache);
            v3->OnRestore(this: v3);
            v4->EndLock(this: v4);
          }
        }
      }
    }
    m_pMemory = g_RestoredEntities.m_Memory.m_pMemory;
    g_RestoredEntities.m_Size = 0;
    if ( g_RestoredEntities.m_Memory.m_nGrowSize >= 0 )
    {
      if ( g_RestoredEntities.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: g_RestoredEntities.m_Memory.m_pMemory);
        m_pMemory = nullptr;
        g_RestoredEntities.m_Memory.m_pMemory = nullptr;
      }
      g_RestoredEntities.m_Memory.m_nAllocationCount = 0;
    }
    g_RestoredEntities.m_pElements = m_pMemory;
    IGameSystem::OnRestoreAllSystems();
    g_InRestore = false;
    CGlobalEntityList::CleanupDeleteList(this: &gEntList);
    CServerGameDLL::ServerActivate(this: &g_ServerGameDLL, pEdictList: nullptr, edictCount: nullptr, clientMax: 0);
    CBaseEntity::SetAllowPrecache(allow: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10142DD0
// Name: void BeginRestoreEntities(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl BeginRestoreEntities()
{
  CHandle<CBaseEntity> *m_pMemory; // eax

  if ( g_InRestore )
  {
    DevMsg(a1: "BeginRestoreEntities without previous EndRestoreEntities.\n");
    CGlobalEntityList::CleanupDeleteList(this: &gEntList);
  }
  m_pMemory = g_RestoredEntities.m_Memory.m_pMemory;
  g_RestoredEntities.m_Size = 0;
  if ( g_RestoredEntities.m_Memory.m_nGrowSize >= 0 )
  {
    if ( g_RestoredEntities.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: g_RestoredEntities.m_Memory.m_pMemory);
      m_pMemory = nullptr;
      g_RestoredEntities.m_Memory.m_pMemory = nullptr;
    }
    g_RestoredEntities.m_Memory.m_nAllocationCount = 0;
  }
  g_RestoredEntities.m_pElements = m_pMemory;
  g_InRestore = true;
  CBaseEntity::SetAllowPrecache(allow: true);
}

//------------------------------------------------------------------------------
// Address: 0x10142E50
// Name: public: virtual void CServerGameDLL::Save(class CSaveRestoreData __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CServerGameDLL::Save(CServerGameDLL *this, CSaveRestoreData *s)
{
  CSave saveHelper; // [esp+0h] [ebp-28h] BYREF

  CSave::CSave(this: &saveHelper, pdata: s);
  g_pGameSaveRestoreBlockSet->Save(this: g_pGameSaveRestoreBlockSet, a2: &saveHelper);
  CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&saveHelper.m_BlockStartStack);
}

//------------------------------------------------------------------------------
// Address: 0x10142E90
// Name: public: virtual void CServerGameDLL::Restore(class CSaveRestoreData __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CServerGameDLL::Restore(CServerGameDLL *this, CSaveRestoreData *s, BOOL b)
{
  CRestore restore; // [esp+0h] [ebp-28h] BYREF

  if ( engine->IsOverrideLoadGameEntsOn(this: engine) )
    FoundryHelpers_ClearEntityHighlightEffects();
  CRestore::CRestore(this: &restore, pdata: s);
  g_pGameSaveRestoreBlockSet->Restore(this: g_pGameSaveRestoreBlockSet, a2: &restore, a3: b);
  g_pGameSaveRestoreBlockSet->PostRestore(this: g_pGameSaveRestoreBlockSet);
  if ( serverfoundry != nullptr && engine->IsOverrideLoadGameEntsOn(this: engine) )
    serverfoundry->OnFinishedRestoreSavegame(this: serverfoundry);
  CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&restore.m_BlockEndStack);
}

//------------------------------------------------------------------------------
// Address: 0x10142F20
// Name: public: virtual int CServerGameDLL::CreateEntityTransitionList(class CSaveRestoreData __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CServerGameDLL::CreateEntityTransitionList(CServerGameDLL *this, CSaveRestoreData *s, int a)
{
  int ReadPos; // esi
  int EntityTransitionList; // edi
  ISaveRestoreBlockSet_vtbl *v5; // ebx
  ISaveRestoreBlockHandler *PhysSaveRestoreBlockHandler; // eax
  ISaveRestoreBlockSet_vtbl *v7; // ebx
  ISaveRestoreBlockHandler *AISaveRestoreBlockHandler; // eax
  ISaveRestoreBlockHandler *v9; // eax
  ISaveRestoreBlockHandler *v10; // eax
  CRestore restoreHelper; // [esp+8h] [ebp-28h] BYREF

  CRestore::CRestore(this: &restoreHelper, pdata: s);
  ReadPos = CRestore::GetReadPos(this: &restoreHelper);
  EntityTransitionList = CreateEntityTransitionList(pSaveData: s, levelMask: a);
  if ( EntityTransitionList != 0 )
  {
    v5 = g_pGameSaveRestoreBlockSet->__vftable;
    PhysSaveRestoreBlockHandler = GetPhysSaveRestoreBlockHandler();
    v5->CallBlockHandlerRestore(
      this: g_pGameSaveRestoreBlockSet,
      a2: PhysSaveRestoreBlockHandler,
      a3: ReadPos,
      a4: &restoreHelper,
      a5: false);
    v7 = g_pGameSaveRestoreBlockSet->__vftable;
    AISaveRestoreBlockHandler = GetAISaveRestoreBlockHandler();
    v7->CallBlockHandlerRestore(
      this: g_pGameSaveRestoreBlockSet,
      a2: AISaveRestoreBlockHandler,
      a3: ReadPos,
      a4: &restoreHelper,
      a5: false);
  }
  v9 = GetPhysSaveRestoreBlockHandler();
  v9->PostRestore(this: v9);
  v10 = GetAISaveRestoreBlockHandler();
  v10->PostRestore(this: v10);
  CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&restoreHelper.m_BlockEndStack);
  return EntityTransitionList;
}

//------------------------------------------------------------------------------
// Address: 0x10142FD0
// Name: public: virtual void CServerGameDLL::WriteSaveHeaders(class CSaveRestoreData __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CServerGameDLL::WriteSaveHeaders(CServerGameDLL *this, CSaveRestoreData *s)
{
  CSave saveHelper; // [esp+0h] [ebp-28h] BYREF

  CSave::CSave(this: &saveHelper, pdata: s);
  g_pGameSaveRestoreBlockSet->WriteSaveHeaders(this: g_pGameSaveRestoreBlockSet, a2: &saveHelper);
  g_pGameSaveRestoreBlockSet->PostSave(this: g_pGameSaveRestoreBlockSet);
  CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&saveHelper.m_BlockStartStack);
}

//------------------------------------------------------------------------------
// Address: 0x10143010
// Name: public: virtual void CServerGameDLL::ReadRestoreHeaders(class CSaveRestoreData __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CServerGameDLL::ReadRestoreHeaders(CServerGameDLL *this, CSaveRestoreData *s)
{
  CRestore restoreHelper; // [esp+0h] [ebp-28h] BYREF

  CRestore::CRestore(this: &restoreHelper, pdata: s);
  g_pGameSaveRestoreBlockSet->PreRestore(this: g_pGameSaveRestoreBlockSet);
  g_pGameSaveRestoreBlockSet->ReadRestoreHeaders(this: g_pGameSaveRestoreBlockSet, a2: &restoreHelper);
  CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&restoreHelper.m_BlockEndStack);
}

//------------------------------------------------------------------------------
// Address: 0x10143050
// Name: public: virtual void CServerGameClients::ClientActive(struct edict_t __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CServerGameClients::ClientActive(CServerGameClients *this, edict_t *pEdict, bool bLoadGame)
{
  IMDLCache *v3; // edi
  CBaseEntity *i; // esi
  edict_t *pEdicts; // eax
  IServerUnknown *m_pUnk; // ecx
  CBasePlayer *v7; // esi
  CSoundEnvelopeController *Controller; // eax

  v3 = mdlcache;
  mdlcache->BeginLock(this: mdlcache);
  ClientActive(pEdict, bLoadGame);
  EndRestoreEntities();
  if ( gpGlobals->eLoadType != MapLoad_LoadGame )
  {
    for ( i = CGlobalEntityList::NextEnt(this: &gEntList, pCurrentEnt: nullptr);
          i != nullptr;
          i = CGlobalEntityList::NextEnt(this: &gEntList, pCurrentEnt: i) )
    {
      i->PostClientActive(this: i);
    }
  }
  pEdicts = pEdict;
  if ( (pEdict != nullptr || gpGlobals->pEdicts != nullptr && ((pEdicts = gpGlobals->pEdicts)->m_fStateFlags & 2) == 0)
    && (m_pUnk = pEdicts->m_pUnk) != nullptr )
  {
    v7 = (CBasePlayer *)m_pUnk->GetBaseEntity(this: m_pUnk);
  }
  else
  {
    v7 = nullptr;
  }
  Controller = CSoundEnvelopeController::GetController();
  Controller->CheckLoopingSoundsForPlayer(this: Controller, a2: v7);
  SceneManager_ClientActive(player: v7);
  v3->EndLock(this: v3);
}

//------------------------------------------------------------------------------
// Address: 0x101431A0
// Name: void AddRestoredEntity(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl AddRestoredEntity(CBaseEntity *pEntity)
{
  unsigned int m_Index; // edi
  int m_Size; // eax
  int v3; // esi
  CHandle<CBaseEntity> *m_pMemory; // ecx
  int v5; // eax
  CHandle<CBaseEntity> *v6; // eax

  if ( pEntity != nullptr )
  {
    m_Index = pEntity->GetRefEHandle(this: pEntity)->m_Index;
    m_Size = g_RestoredEntities.m_Size;
    v3 = g_RestoredEntities.m_Size;
    if ( g_RestoredEntities.m_Size + 1 > g_RestoredEntities.m_Memory.m_nAllocationCount )
    {
      CUtlMemory<CNavLadder *,int>::Grow(
        this: (CUtlMemory<vgui::TreeNode *,int> *)&g_RestoredEntities,
        num: g_RestoredEntities.m_Size - g_RestoredEntities.m_Memory.m_nAllocationCount + 1);
      m_Size = g_RestoredEntities.m_Size;
    }
    m_pMemory = g_RestoredEntities.m_Memory.m_pMemory;
    g_RestoredEntities.m_Size = m_Size + 1;
    v5 = m_Size - v3;
    g_RestoredEntities.m_pElements = g_RestoredEntities.m_Memory.m_pMemory;
    if ( v5 > 0 )
    {
      _V_memmove(
        dest: &g_RestoredEntities.m_Memory.m_pMemory[v3 + 1],
        src: &g_RestoredEntities.m_Memory.m_pMemory[v3],
        count: 4 * v5);
      m_pMemory = g_RestoredEntities.m_Memory.m_pMemory;
    }
    v6 = &m_pMemory[v3];
    if ( v6 != nullptr )
      v6->m_Index = m_Index;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10143220
// Name: public: virtual bool CServerGameDLL::LevelInit(char const __near *,char const __near *,char const __near *,char const __near *,bool,bool)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CServerGameDLL::LevelInit(
        CServerGameDLL *this,
        const char *pMapName,
        const char *pMapEntities,
        const char *pOldLevel,
        const char *pLandmarkName,
        void **loadGame,
        bool background)
{
  CBaseEntity *v8; // eax
  CBaseEntity *v9; // esi
  UtlLinkedListElem_t<CMapEntityRef,unsigned short> *m_pMemory; // eax
  void (__thiscall *UpdateGameplayStatsFromSteam)(CGameRules *); // eax

  ResetWindspeed();
  UpdateChapterRestrictions(mapname: pMapName);
  if ( (_BYTE)loadGame != 0 )
  {
    gpGlobals->eLoadType = (pOldLevel != nullptr) + 1;
    BeginRestoreEntities();
    if ( !engine->LoadGameState(this: engine, a2: pMapName, a3: true) )
    {
      if ( pOldLevel == nullptr )
        return 0;
      MapEntity_ParseAllEntities(pMapData: pMapEntities, pFilter: nullptr, bActivateEntities: false);
    }
    if ( pOldLevel != nullptr )
      engine->LoadAdjacentEnts(this: engine, a2: pOldLevel, a3: pLandmarkName);
    if ( g_OneWayTransition )
      engine->ClearSaveDirAfterClientLoad(this: engine);
    if ( pOldLevel != nullptr
      && sv_autosave.m_pParent != nullptr
      && sv_autosave.m_pParent->m_Value.m_nValue != 0
      && gpGlobals->maxClients == 1 )
    {
      v8 = CBaseEntity::Create(
             szName: "logic_autosave",
             vecOrigin: &vec3_origin,
             vecAngles: &vec3_angle,
             pOwner: nullptr);
      v9 = v8;
      if ( v8 != nullptr )
      {
        CEventQueue::AddEvent(
          this: &g_EventQueue,
          target: v8,
          action: "Save",
          fireDelay: 1.0,
          pActivator: nullptr,
          pCaller: nullptr,
          outputID: 0);
        CEventQueue::AddEvent(
          this: &g_EventQueue,
          target: v9,
          action: "Kill",
          fireDelay: 1.1,
          pActivator: nullptr,
          pCaller: nullptr,
          outputID: 0);
      }
    }
  }
  else
  {
    gpGlobals->eLoadType = background ? MapLoad_Background : MapLoad_NewGame;
    CUtlLinkedList<CRagdollEntry,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CRagdollEntry,unsigned short>,unsigned short>>::RemoveAll(this: (CUtlLinkedList<CEnvWindShared::WindVariationEvent_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CEnvWindShared::WindVariationEvent_t,unsigned short>,unsigned short> > *)&g_MapEntityRefs);
    m_pMemory = g_MapEntityRefs.m_Memory.m_pMemory;
    if ( g_MapEntityRefs.m_Memory.m_nGrowSize >= 0 )
    {
      if ( g_MapEntityRefs.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: g_MapEntityRefs.m_Memory.m_pMemory);
        m_pMemory = nullptr;
        g_MapEntityRefs.m_Memory.m_pMemory = nullptr;
      }
      g_MapEntityRefs.m_Memory.m_nAllocationCount = 0;
    }
    g_MapEntityRefs.m_FirstFree = -1;
    *(_DWORD *)&g_MapEntityRefs.m_NumAlloced = -65536;
    g_MapEntityRefs.m_pElements = m_pMemory;
    loadGame = &CMapLoadEntityFilter::`vftable';
    MapEntity_ParseAllEntities(pMapData: pMapEntities, pFilter: (IMapEntityFilter *)&loadGame, bActivateEntities: false);
    g_pServerBenchmark->StartBenchmark(this: g_pServerBenchmark);
    CServerGameDLL::LevelInit_ParseAllEntities(this, pMapEntities);
  }
  CRagdollLowViolenceManager::SetLowViolence(this: &g_RagdollLVManager, pMapName);
  PrecachePointTemplates();
  LoadMOTDFile(stringname: "motd", pConvarFilename: &motdfile);
  LoadMOTDFile(stringname: "hostfile", pConvarFilename: &hostfile);
  CGlobalEntityList::CleanupDeleteList(this: &gEntList);
  g_AIFriendliesTalkSemaphore.m_hCurrentTalker.m_Index = -1;
  g_AIFoesTalkSemaphore.m_hCurrentTalker.m_Index = -1;
  g_AIFriendliesTalkSemaphore.m_ReleaseTime = 0.0;
  g_AIFoesTalkSemaphore.m_ReleaseTime = 0.0;
  this->m_fAutoSaveDangerousTime = 0.0;
  this->m_fAutoSaveDangerousMinHealthToCommit = 0.0;
  UpdateGameplayStatsFromSteam = g_pGameRules->UpdateGameplayStatsFromSteam;
  g_OneWayTransition = false;
  UpdateGameplayStatsFromSteam(this: g_pGameRules);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10143480
// Name: public: virtual void CServerGameDLL::SaveWriteFields(class CSaveRestoreData __near *,char const __near *,void __near *,struct datamap_t __near *,struct typedescription_t __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CServerGameDLL::SaveWriteFields(
        CServerGameDLL *this,
        CSaveRestoreData *pSaveData,
        const char *pname,
        void *pBaseData,
        datamap_t *pMap,
        typedescription_t *pFields,
        int fieldCount)
{
  CSave saveHelper; // [esp+0h] [ebp-28h] BYREF

  CSave::CSave(this: &saveHelper, pdata: pSaveData);
  CSave::WriteFields(this: &saveHelper, pname, pBaseData, pRootMap: pMap, pFields, fieldCount);
  CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&saveHelper.m_BlockStartStack);
}

//------------------------------------------------------------------------------
// Address: 0x101434C0
// Name: public: virtual void CServerGameDLL::SaveReadFields(class CSaveRestoreData __near *,char const __near *,void __near *,struct datamap_t __near *,struct typedescription_t __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CServerGameDLL::SaveReadFields(
        CServerGameDLL *this,
        CSaveRestoreData *pSaveData,
        const char *pname,
        void *pBaseData,
        datamap_t *pMap,
        typedescription_t *pFields,
        int fieldCount)
{
  CRestore restoreHelper; // [esp+0h] [ebp-28h] BYREF

  CRestore::CRestore(this: &restoreHelper, pdata: pSaveData);
  CRestore::ReadFields(this: &restoreHelper, pname, pBaseData, pRootMap: pMap, pFields, fieldCount);
  CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&restoreHelper.m_BlockEndStack);
}

//------------------------------------------------------------------------------
// Address: 0x10143500
// Name: public: virtual void CServerGameClients::ClientDisconnect(struct edict_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CServerGameClients::ClientDisconnect(CServerGameClients *this, edict_t *pEdict)
{
  edict_t *pEdicts; // eax
  IServerUnknown *m_pUnk; // ecx
  int v4; // eax
  int v5; // esi
  CBaseEdict *v6; // ecx
  int v7; // eax
  CSound *v8; // eax

  pEdicts = pEdict;
  if ( pEdict != nullptr || gpGlobals->pEdicts != nullptr && ((pEdicts = gpGlobals->pEdicts)->m_fStateFlags & 2) == 0 )
  {
    m_pUnk = pEdicts->m_pUnk;
    if ( m_pUnk != nullptr )
    {
      v4 = (int)m_pUnk->GetBaseEntity(this: m_pUnk);
      v5 = v4;
      if ( v4 != 0 )
      {
        if ( !g_fGameOver )
        {
          if ( *(float *)(v4 + 3796) != 0.0 )
          {
            if ( *(_BYTE *)(v4 + 84) != 0 )
            {
              *(_BYTE *)(v4 + 88) |= 1u;
            }
            else
            {
              v6 = *(CBaseEdict **)(v4 + 24);
              if ( v6 != nullptr )
                CBaseEdict::StateChanged(this: v6, offset: 0xED4u);
            }
            *(_DWORD *)(v5 + 3796) = 0;
          }
          v7 = CSoundEnt::ClientSoundIndex(pClient: pEdict);
          v8 = CSoundEnt::SoundPointerForIndex(iIndex: v7);
          if ( v8 != nullptr )
            CSound::Reset(this: v8);
          CBaseEntity::RemoveFlag(this: (CBaseEntity *)v5, flagsToRemove: 0x20000);
          CBaseEntity::AddFlag(this: (CBaseEntity *)v5, flags: 0x800000);
          CBaseEntity::AddFlag(this: (CBaseEntity *)v5, flags: 0x10000);
          CCollisionProperty::SetSolidFlags(
            this: (CCollisionProperty *)(v5 + 228),
            flags: *(unsigned __int16 *)(v5 + 260) | 4);
          if ( g_pGameRules != nullptr )
          {
            g_pGameRules->ClientDisconnected(this: g_pGameRules, a2: pEdict);
            gamestats->Event_PlayerDisconnected(this: gamestats, a2: (CBasePlayer *)v5);
          }
        }
        CBaseEntity::PhysicsRemoveTouchedList(ent: (CBaseEntity *)v5);
        CBaseEntity::PhysicsRemoveGroundList(ent: (CBaseEntity *)v5);
        CBasePlayer::ClearPlayerSimulationList(this: (CBasePlayer *)v5);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10143630
// Name: public: virtual void CServerGameClients::ClientSetupVisibility(struct edict_t __near *,struct edict_t __near *,unsigned char __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CServerGameClients::ClientSetupVisibility(
        CServerGameClients *this@<ecx>,
        int a2@<ebx>,
        int a3@<esi>,
        edict_t *pViewEntity,
        edict_t *pClient,
        unsigned __int8 *pvs,
        int pvssize)
{
  int v7; // edi
  IServerUnknown *m_pUnk; // ecx
  int v9; // eax
  IServerUnknown *v10; // ecx
  int v11; // eax
  CBasePlayer *v12; // esi
  CUtlVector<CHandle<CBasePlayer>,CUtlMemory<CHandle<CBasePlayer>,int> > *SplitScreenAndPictureInPicturePlayers; // edi
  int i; // ebx
  unsigned int m_Index; // eax
  IHandleEntity *m_pEntity; // ecx
  unsigned __int16 m_Head; // ax
  unsigned int v18; // edi
  UtlLinkedListElem_t<CFuncAreaPortalBase *,unsigned short> *m_pMemory; // ecx
  float v20; // xmm0_4
  int v21; // ebx
  CFuncAreaPortalBase *m_Element; // esi
  int m_portalNumber; // eax
  QAngle *v24; // eax
  int v25; // [esp+18h] [ebp-1054h]
  int v26; // [esp+1Ch] [ebp-1050h]
  _DWORD v27[512]; // [esp+24h] [ebp-1048h] BYREF
  _DWORD v28[512]; // [esp+824h] [ebp-848h] BYREF
  unsigned __int8 chAreaPortalBits[8]; // [esp+1024h] [ebp-48h] BYREF
  __int64 v30; // [esp+102Ch] [ebp-40h]
  __int64 v31; // [esp+1034h] [ebp-38h]
  _BYTE v32[12]; // [esp+103Ch] [ebp-30h] BYREF
  float FOVDistanceAdjustFactorForNetworking; // [esp+1048h] [ebp-24h]
  CUtlVector<QAngle,CUtlMemory<QAngle,int> > v34; // [esp+104Ch] [ebp-20h] BYREF
  QAngle src; // [esp+1060h] [ebp-Ch] BYREF
  CBasePlayer *v36; // [esp+1074h] [ebp+8h]

  engine->ResetPVS(this: engine, a2: pvs, a3: pvssize);
  g_pToolFrameworkServer->PreSetupVisibility(this: g_pToolFrameworkServer);
  v7 = 0;
  if ( pViewEntity != nullptr )
  {
    m_pUnk = pViewEntity->m_pUnk;
    if ( m_pUnk != nullptr )
    {
      v9 = (int)m_pUnk->GetBaseEntity(this: m_pUnk);
      v7 = v9;
      if ( v9 != 0 )
      {
        src = *(QAngle *)(*(int (__thiscall **)(int, _BYTE *))(*(_DWORD *)v9 + 504))(a1: v9, a2: v32);
        engine->AddOriginToPVS(this: engine, a2: (const Vector *)&src);
      }
    }
    else
    {
      v7 = 0;
    }
  }
  FOVDistanceAdjustFactorForNetworking = 1.0;
  memset(&v34, 0, sizeof(v34));
  if ( pClient != nullptr && (v10 = pClient->m_pUnk) != nullptr )
  {
    v11 = ((int (__thiscall *)(IServerUnknown *, int, int))v10->GetBaseEntity)(a1: v10, a2: a3, a3: a2);
    v12 = (CBasePlayer *)v11;
    v36 = (CBasePlayer *)v11;
    if ( v11 != 0 )
    {
      if ( v7 == 0 )
        src = *(QAngle *)(*(int (__thiscall **)(int, _BYTE *))(*(_DWORD *)v11 + 504))(a1: v11, a2: v32);
      ((void (__thiscall *)(CBasePlayer *, int, unsigned __int8 *, int, int, int))v12->SetupVisibility)(
        a1: v12,
        a2: v7,
        a3: pvs,
        a4: pvssize,
        a5: v25,
        a6: v26);
      UTIL_SetClientVisibilityPVS(pClient, pvs, pvssize);
      FOVDistanceAdjustFactorForNetworking = CBasePlayer::GetFOVDistanceAdjustFactorForNetworking(this: v12);
      CUtlVector<Vector,CUtlMemory<Vector,int>>::InsertBefore(this: &v34, elem: v34.m_Size, &src);
      SplitScreenAndPictureInPicturePlayers = CBasePlayer::GetSplitScreenAndPictureInPicturePlayers(this: v12);
      for ( i = 0; i < SplitScreenAndPictureInPicturePlayers->m_Size; ++i )
      {
        m_Index = SplitScreenAndPictureInPicturePlayers->m_Memory.m_pMemory[i].m_Index;
        if ( m_Index != -1 && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index) )
        {
          m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
          if ( m_pEntity != nullptr )
          {
            src = *(QAngle *)((int (__thiscall *)(IHandleEntity *, _BYTE *))m_pEntity->__vftable[42].dtr_IHandleEntity)(
                               a1: m_pEntity,
                               a2: v32);
            CUtlVector<Vector,CUtlMemory<Vector,int>>::InsertBefore(this: &v34, elem: v34.m_Size, &src);
          }
        }
      }
      goto LABEL_20;
    }
  }
  else
  {
    v36 = nullptr;
    v12 = nullptr;
  }
  _Warning(a1: "ClientSetupVisibility: No entity for edict!\n");
  CUtlVector<Vector,CUtlMemory<Vector,int>>::InsertBefore(this: &v34, elem: v34.m_Size, &src);
LABEL_20:
  m_Head = g_AreaPortals.m_Head;
  v18 = 0;
  *(_QWORD *)chAreaPortalBits = 0;
  v30 = 0;
  v31 = 0;
  if ( g_AreaPortals.m_Head == 0xFFFF )
    goto LABEL_33;
  m_pMemory = g_AreaPortals.m_Memory.m_pMemory;
  do
  {
    v20 = FOVDistanceAdjustFactorForNetworking;
    v21 = m_Head;
    m_Element = m_pMemory[v21].m_Element;
    HIBYTE(pvssize) = 1;
    v27[v18] = m_Element->m_portalNumber;
    v28[v18++] = m_Element->UpdateVisibility(
                   this: m_Element,
                   a2: (const CUtlVector<Vector,CUtlMemory<Vector,int> > *)&v34,
                   a3: COERCE_FLOAT(LODWORD(v20)),
                   a4: (bool *)&pvssize + 3);
    if ( v18 >= 0x200 )
    {
      engine->SetAreaPortalStates(this: engine, a2: v27, a3: v28, a4: v18);
      v18 = 0;
    }
    if ( m_Element->m_iPortalVersion != 0 )
    {
      if ( HIBYTE(pvssize) == 0 )
        goto LABEL_31;
    }
    else
    {
      HIBYTE(pvssize) = 1;
    }
    m_portalNumber = m_Element->m_portalNumber;
    if ( m_portalNumber >= 0 )
    {
      if ( (unsigned int)m_portalNumber < 0xC0 )
        chAreaPortalBits[m_portalNumber >> 3] |= 1 << (m_portalNumber & 7);
      else
        _Error(this: (ISceneTokenProcessor *)&stru_1047C0B0, a2: (const char *)m_Element->m_portalNumber);
    }
LABEL_31:
    m_pMemory = g_AreaPortals.m_Memory.m_pMemory;
    m_Head = g_AreaPortals.m_Memory.m_pMemory[v21].m_Next;
  }
  while ( m_Head != 0xFFFF );
  v12 = v36;
LABEL_33:
  ((void (__thiscall *)(IVEngineServer *, _DWORD *))engine->SetAreaPortalStates)(a1: engine, a2: v27);
  if ( v12 != nullptr )
    CPlayerLocalData::UpdateAreaBits(this: &v12->m_Local, pl: v12, chAreaPortalBits);
  v24 = v34.m_Memory.m_pMemory;
  v34.m_Size = 0;
  if ( v34.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v34.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)v34.m_Memory.m_pMemory);
      v24 = nullptr;
      v34.m_Memory.m_pMemory = nullptr;
    }
    v34.m_Memory.m_nAllocationCount = 0;
  }
  v34.m_pElements = v24;
  if ( v34.m_Memory.m_nGrowSize >= 0 && v24 != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)v24);
}

//------------------------------------------------------------------------------
// Address: 0x101439C0
// Name: public: virtual char const __near * CServerDLLSharedAppSystems::GetDllName(int)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CServerDLLSharedAppSystems::GetDllName(CServerDLLSharedAppSystems *this, int idx)
{
  return this->m_Systems.m_Memory.m_pMemory[idx].m_pModuleName;
}

//------------------------------------------------------------------------------
// Address: 0x101439D0
// Name: public: virtual char const __near * CServerDLLSharedAppSystems::GetInterfaceName(int)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CServerDLLSharedAppSystems::GetInterfaceName(CServerDLLSharedAppSystems *this, int idx)
{
  return this->m_Systems.m_Memory.m_pMemory[idx].m_pInterfaceName;
}

//------------------------------------------------------------------------------
// Address: 0x10143A50
// Name: public: virtual class CBaseEntity __near * CMapLoadEntityFilter::CreateNextEntity(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CBaseEntity *__thiscall CMapLoadEntityFilter::CreateNextEntity(CMapLoadEntityFilter *this, const char *pClassname)
{
  int v2; // ebx
  CBaseEntity *EntityByName; // eax
  CBaseEntity *v4; // edi
  edict_t *m_pPev; // ecx
  signed int v6; // eax
  unsigned __int16 v7; // ax
  int v8; // esi
  UtlLinkedListElem_t<CMapEntityRef,unsigned short> *v9; // eax
  int ref_4; // [esp+10h] [ebp-4h]

  v2 = -1;
  EntityByName = CreateEntityByName(className: pClassname, iForceEdictIndex: -1, bNotify: true);
  v4 = EntityByName;
  ref_4 = -1;
  if ( EntityByName != nullptr )
  {
    m_pPev = EntityByName->m_Network.m_pPev;
    v6 = m_pPev != nullptr ? m_pPev - gpGlobals->pEdicts : 0;
    v2 = v6;
    if ( m_pPev != nullptr )
      ref_4 = m_pPev->m_NetworkSerialNumber;
  }
  v7 = CUtlLinkedList<CMapEntityRef,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CMapEntityRef,unsigned short>,unsigned short>>::AllocInternal(
         this: &g_MapEntityRefs,
         multilist: false);
  v8 = v7;
  if ( v7 != 0xFFFF )
  {
    CUtlLinkedList<CMapEntityRef,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CMapEntityRef,unsigned short>,unsigned short>>::LinkBefore(
      this: &g_MapEntityRefs,
      before: 0xFFFFu,
      elem: v7);
    v9 = &g_MapEntityRefs.m_Memory.m_pMemory[v8];
    if ( v9 != nullptr )
    {
      v9->m_Element.m_iEdict = v2;
      v9->m_Element.m_iSerialNumber = ref_4;
    }
  }
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x10143AF0
// Name: public: virtual void CServerGameDLL::InvalidateMdlCache(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CServerGameDLL::InvalidateMdlCache(CServerGameDLL *this)
{
  CBaseEntity *i; // ebx
  CBaseAnimating *v2; // eax
  CBaseAnimating *v3; // edi
  CStudioHdr *m_pStudioHdr; // esi

  for ( i = CGlobalEntityList::NextEnt(this: &gEntList, pCurrentEnt: nullptr);
        i != nullptr;
        i = CGlobalEntityList::NextEnt(this: &gEntList, pCurrentEnt: i) )
  {
    v2 = (CBaseAnimating *)__RTDynamicCast(
                             inptr: i,
                             VfDelta: 0,
                             SrcType: &CBaseEntity `RTTI Type Descriptor',
                             TargetType: &CBaseAnimating `RTTI Type Descriptor',
                             isReference: 0);
    v3 = v2;
    if ( v2 != nullptr )
    {
      CBaseAnimating::UnlockStudioHdr(this: v2);
      m_pStudioHdr = v3->m_pStudioHdr;
      if ( m_pStudioHdr != nullptr )
      {
        CStudioHdr::Term(this: v3->m_pStudioHdr);
        CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&m_pStudioHdr->m_boneParent);
        CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&m_pStudioHdr->m_boneFlags);
        CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&m_pStudioHdr->m_pStudioHdrCache);
        free(pMem: m_pStudioHdr);
        v3->m_pStudioHdr = nullptr;
      }
    }
  }
  CStudioHdr::CActivityToSequenceMapping::ResetMappings();
}

//------------------------------------------------------------------------------
// Address: 0x1013F8F0
// Name: __CreateCServerGameDLLIServerGameDLL_interface
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CServerGameDLL *__cdecl _CreateCServerGameDLLIServerGameDLL_interface()
{
  return &g_ServerGameDLL;
}

//------------------------------------------------------------------------------
// Address: 0x10140400
// Name: __CreateCServerGameEntsIServerGameEnts_interface
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CServerGameEnts *__cdecl _CreateCServerGameEntsIServerGameEnts_interface()
{
  return &_g_CServerGameEnts_singleton;
}

//------------------------------------------------------------------------------
// Address: 0x101404A0
// Name: __CreateCServerGameClientsIServerGameClients_interface
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CServerGameClients *__cdecl _CreateCServerGameClientsIServerGameClients_interface()
{
  return &g_ServerGameClients;
}

//------------------------------------------------------------------------------
// Address: 0x101409A0
// Name: __CreateCServerDLLSharedAppSystemsIServerDLLSharedAppSystems_interface
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CServerDLLSharedAppSystems *__cdecl _CreateCServerDLLSharedAppSystemsIServerDLLSharedAppSystems_interface()
{
  return &_g_CServerDLLSharedAppSystems_singleton;
}
