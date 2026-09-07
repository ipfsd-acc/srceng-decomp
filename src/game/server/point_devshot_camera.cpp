// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/point_devshot_camera.cpp
// Functions: 11
// ============================================================

#include "game\server\point_devshot_camera.h"

//------------------------------------------------------------------------------
// Address: 0x101D1DE0
// Name: public: virtual struct datamap_t __near * CPointDevShotCamera::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CPointDevShotCamera::GetDataDescMap(CPointDevShotCamera *this)
{
  return &CPointDevShotCamera::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x101D1DF0
// Name: class CBasePlayer __near * UTIL_GetLocalPlayerOrListenServerHost(void)
// Source: json
//------------------------------------------------------------------------------
CBasePlayer *__cdecl UTIL_GetLocalPlayerOrListenServerHost()
{
  if ( gpGlobals->maxClients <= 1 )
    return UTIL_GetLocalPlayer();
  if ( engine->IsDedicatedServer(this: engine) )
    return nullptr;
  return UTIL_GetListenServerHost();
}

//------------------------------------------------------------------------------
// Address: 0x101D1E20
// Name: public: void CPointDevShotCamera::DevShotThink_PostShot(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPointDevShotCamera::DevShotThink_PostShot(CPointDevShotCamera *this)
{
  CBasePlayer *LocalPlayer; // eax
  CBasePlayer *v3; // esi

  if ( gpGlobals->maxClients <= 1 )
  {
    LocalPlayer = UTIL_GetLocalPlayer();
  }
  else
  {
    if ( engine->IsDedicatedServer(this: engine) )
      return;
    LocalPlayer = UTIL_GetListenServerHost();
  }
  v3 = LocalPlayer;
  if ( LocalPlayer != nullptr )
  {
    CBasePlayer::SetFOV(this: LocalPlayer, pRequester: this, FOV: 0, zoomRate: 0.0, iZoomStart: 0);
    if ( --g_iDevShotCameraCount == 0 )
      engine->ClientCommand(this: engine, a2: v3->m_Network.m_pPev, a3: "devshots_nextmap");
  }
}

//------------------------------------------------------------------------------
// Address: 0x101D1E90
// Name: public: virtual void CDevShotSystem::LevelInitPreEntity(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDevShotSystem::LevelInitPreEntity(CDevShotSystem *this)
{
  this->m_bIssuedNextMapCommand = false;
  g_iDevShotCameraCount = 0;
  this->m_bParsedMapFile = false;
}

//------------------------------------------------------------------------------
// Address: 0x101D1EA0
// Name: public: virtual void CDevShotSystem::SafeRemoveIfDesired(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDevShotSystem::SafeRemoveIfDesired(CDevShotSystem *this)
{
  ICommandLine *v2; // eax

  v2 = _CommandLine((CResponseRulesToEngineInterface *)this);
  if ( v2->FindParm(this: v2, a2: "-makedevshots") == 0 )
    IGameSystem::Remove(pSys: this);
}

//------------------------------------------------------------------------------
// Address: 0x101D1ED0
// Name: public: virtual void CDevShotSystem::FrameUpdatePostEntityThink(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDevShotSystem::FrameUpdatePostEntityThink(CDevShotSystem *this)
{
  bool v1; // cc
  CDevShotSystem *v2; // ebx
  const char *pszValue; // eax
  KeyValues *v4; // eax
  KeyValues *v5; // esi
  IBaseFileSystem *v6; // eax
  KeyValues *FirstSubKey; // edi
  const char *Name; // ebx
  IServerNetworkable *EntityByName; // esi
  IServerNetworkable_vtbl *v10; // ebx
  const char *String; // eax
  IServerNetworkable_vtbl *v12; // ebx
  const char *v13; // eax
  IServerNetworkable_vtbl *v14; // ebx
  const char *v15; // eax
  const char *v16; // eax
  CBasePlayer *LocalPlayerOrListenServerHost; // eax
  char szFullName[512]; // [esp+0h] [ebp-204h] BYREF
  CDevShotSystem *v19; // [esp+200h] [ebp-4h]

  v1 = gpGlobals->curtime >= 5.0;
  v2 = this;
  v19 = this;
  if ( v1 && !this->m_bIssuedNextMapCommand && !this->m_bParsedMapFile )
  {
    this->m_bParsedMapFile = true;
    pszValue = gpGlobals->mapname.pszValue;
    if ( pszValue == nullptr )
      pszValue = locale;
    V_snprintf(pDest: szFullName, maxLen: 512, pFormat: "maps/%s.txt", pszValue);
    v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v4 != nullptr )
      v5 = KeyValues::KeyValues(this: v4, setName: "MapCameras");
    else
      v5 = nullptr;
    if ( filesystem != nullptr )
      v6 = &filesystem->IBaseFileSystem;
    else
      v6 = nullptr;
    if ( KeyValues::LoadFromFile(
           this: v5,
           filesystem: v6,
           resourceName: szFullName,
           pathID: "MOD",
           pfnEvaluateSymbolProc: nullptr) )
    {
      _Warning(a1: "Devshots: Loading point_devshot_camera positions from %s. \n", szFullName);
      FirstSubKey = KeyValues::GetFirstSubKey(this: v5);
      if ( FirstSubKey != nullptr )
      {
        do
        {
          Name = KeyValues::GetName(this: FirstSubKey);
          EntityByName = CreateEntityByName(className: "point_devshot_camera", iForceEdictIndex: -1, bNotify: true);
          ((void (__thiscall *)(IServerNetworkable *, const char *, const char *))EntityByName->__vftable[3].Release)(
            a1: EntityByName,
            a2: "cameraname",
            a3: Name);
          v10 = EntityByName->__vftable;
          String = KeyValues::GetString(this: FirstSubKey, keyName: "origin", defaultValue: "0 0 0");
          ((void (__thiscall *)(IServerNetworkable *, const char *, const char *))v10[3].Release)(
            a1: EntityByName,
            a2: "origin",
            a3: String);
          v12 = EntityByName->__vftable;
          v13 = KeyValues::GetString(this: FirstSubKey, keyName: "angles", defaultValue: "0 0 0");
          ((void (__thiscall *)(IServerNetworkable *, const char *, const char *))v12[3].Release)(
            a1: EntityByName,
            a2: "angles",
            a3: v13);
          v14 = EntityByName->__vftable;
          v15 = KeyValues::GetString(this: FirstSubKey, keyName: "FOV", defaultValue: "75");
          ((void (__thiscall *)(IServerNetworkable *, const char *, const char *))v14[3].Release)(
            a1: EntityByName,
            a2: "FOV",
            a3: v15);
          DispatchSpawn(pEntity: (CBaseEntity *)EntityByName, bRunVScripts: true);
          EntityByName->__vftable[3].GetBaseNetworkable(this: EntityByName);
          FirstSubKey = KeyValues::GetNextKey(this: FirstSubKey);
        }
        while ( FirstSubKey != nullptr );
        v2 = v19;
      }
    }
    if ( g_iDevShotCameraCount == 0 )
    {
      v16 = gpGlobals->mapname.pszValue;
      if ( v16 == nullptr )
        v16 = locale;
      _Warning(a1: "Devshots: No point_devshot_camera in %s. Moving to next map.\n", v16);
      LocalPlayerOrListenServerHost = UTIL_GetLocalPlayerOrListenServerHost();
      if ( LocalPlayerOrListenServerHost != nullptr )
      {
        engine->ClientCommand(this: engine, a2: LocalPlayerOrListenServerHost->m_Network.m_pPev, a3: "devshots_nextmap");
        v2->m_bIssuedNextMapCommand = true;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101D2110
// Name: public: void CPointDevShotCamera::DevShotThink_TakeShot(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPointDevShotCamera::DevShotThink_TakeShot(CPointDevShotCamera *this)
{
  CBasePlayer *LocalPlayer; // eax
  const char *pszValue; // ecx
  edict_t *m_pPev; // esi
  IVEngineServer_vtbl *v5; // edi
  char *v6; // eax

  if ( gpGlobals->maxClients <= 1 )
  {
    LocalPlayer = UTIL_GetLocalPlayer();
  }
  else
  {
    if ( engine->IsDedicatedServer(this: engine) )
      return;
    LocalPlayer = UTIL_GetListenServerHost();
  }
  if ( LocalPlayer != nullptr )
  {
    pszValue = this->m_iszCameraName.pszValue;
    if ( pszValue == nullptr )
      pszValue = locale;
    m_pPev = LocalPlayer->m_Network.m_pPev;
    v5 = engine->__vftable;
    v6 = UTIL_VarArgs(format: "devshots_screenshot \"%s\"", pszValue);
    v5->ClientCommand(this: engine, a2: m_pPev, a3: v6);
    CBaseEntity::ThinkSet(
      this,
      func: (void (__thiscall *)(CBaseEntity *))CPointDevShotCamera::DevShotThink_PostShot,
      thinkTime: 0.0,
      szContext: nullptr);
    CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->curtime + 4.0, szContext: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101D21C0
// Name: public: void CPointDevShotCamera::DevShotThink_Setup(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPointDevShotCamera::DevShotThink_Setup(CPointDevShotCamera *this)
{
  CBasePlayer *LocalPlayer; // eax
  CBasePlayer *v3; // esi
  CBaseCombatWeapon *ActiveWeapon; // eax

  if ( gpGlobals->maxClients <= 1 )
  {
    LocalPlayer = UTIL_GetLocalPlayer();
  }
  else
  {
    if ( engine->IsDedicatedServer(this: engine) )
      return;
    LocalPlayer = UTIL_GetListenServerHost();
  }
  v3 = LocalPlayer;
  if ( LocalPlayer != nullptr )
  {
    engine->ClientCommand(this: engine, a2: LocalPlayer->m_Network.m_pPev, a3: "developer 0");
    engine->ClientCommand(this: engine, a2: v3->m_Network.m_pPev, a3: "cl_drawhud 0");
    engine->ClientCommand(this: engine, a2: v3->m_Network.m_pPev, a3: "sv_cheats 1");
    engine->ClientCommand(this: engine, a2: v3->m_Network.m_pPev, a3: "god");
    engine->ClientCommand(this: engine, a2: v3->m_Network.m_pPev, a3: "notarget");
    CCollisionProperty::SetSolidFlags(this: &v3->m_Collision, flags: v3->m_Collision.m_usSolidFlags.m_Value | 4);
    CBasePlayer::EnableControl(this: v3, fControl: false);
    CBasePlayer::SetViewEntity(this: v3, pEntity: this, bShouldDrawPlayer: true);
    CBasePlayer::SetFOV(this: v3, pRequester: this, FOV: this->m_iFOV, zoomRate: 0.0, iZoomStart: 0);
    if ( CBaseCombatCharacter::GetActiveWeapon(this: v3) != nullptr )
    {
      ActiveWeapon = CBaseCombatCharacter::GetActiveWeapon(this: v3);
      CBaseEntity::AddEffects(this: ActiveWeapon, nEffects: 32);
    }
    CBaseEntity::DispatchUpdateTransmitState(this);
    CBaseEntity::ThinkSet(
      this,
      func: (void (__thiscall *)(CBaseEntity *))CPointDevShotCamera::DevShotThink_TakeShot,
      thinkTime: 0.0,
      szContext: nullptr);
    CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->curtime, szContext: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101D2320
// Name: public: virtual void CPointDevShotCamera::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPointDevShotCamera::Spawn(CPointDevShotCamera *this)
{
  CResponseRulesToEngineInterface *v2; // ecx
  ICommandLine *v3; // eax

  CAI_BaseNPC::OnSetSchedule((vgui::Panel *)this);
  v3 = _CommandLine(this: v2);
  if ( v3->FindParm(this: v3, a2: "-makedevshots") != 0 )
  {
    CBaseEntity::ThinkSet(
      this,
      func: (void (__thiscall *)(CBaseEntity *))CPointDevShotCamera::DevShotThink_Setup,
      thinkTime: 0.0,
      szContext: nullptr);
    CBaseEntity::SetNextThink(
      this,
      thinkTime: (float)(gpGlobals->curtime + 5.0) + (float)(5 * g_iDevShotCameraCount),
      szContext: nullptr);
    ++g_iDevShotCameraCount;
  }
  else
  {
    UTIL_Remove(oldObj: this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10408650
// Name: CPointDevShotCamera_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CPointDevShotCamera_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CPointDevShotCamera>(__formal: nullptr);
  CPointDevShotCamera_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101D23A0
// Name: struct datamap_t __near * DataMapInit<class CPointDevShotCamera>(class CPointDevShotCamera __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CPointDevShotCamera>()
{
  char *Name; // eax

  if ( (_S2_176 & 1) == 0 )
  {
    _S2_176 |= 1u;
    nameHolder_336.m_pszBase = "CPointDevShotCamera";
    nameHolder_336.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_336.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_336.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_336.m_Names.m_Size = 0;
    nameHolder_336.m_Names.m_pElements = nullptr;
    nameHolder_336.m_nLenBase = 19;
    atexit(func: DataMapInit_CPointDevShotCamera__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CPointDevShotCamera::m_DataMap.baseMap = &CBaseEntity::m_DataMap;
  if ( (_S2_176 & 2) == 0 )
  {
    _S2_176 |= 2u;
    dataDesc_481[1].fieldName = CDatadescGeneratedNameHolder::GenerateName(
                                  this: &nameHolder_336,
                                  pszIdentifier: "DevShotThink_Setup");
    dataDesc_481[1].fieldOffset = 0;
    *(_DWORD *)&dataDesc_481[1].fieldSize = 2097153;
    dataDesc_481[1].externalName = nullptr;
    dataDesc_481[1].pSaveRestoreOps = nullptr;
    dataDesc_481[1].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CPointDevShotCamera::DevShotThink_Setup;
    *(_QWORD *)&dataDesc_481[1].td = 0;
    *(_QWORD *)&dataDesc_481[1].override_field = 0;
    *(_QWORD *)&dataDesc_481[1].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_481[1].flatOffset[1] = 0;
    dataDesc_481[2].fieldType = FIELD_VOID;
    dataDesc_481[2].fieldName = CDatadescGeneratedNameHolder::GenerateName(
                                  this: &nameHolder_336,
                                  pszIdentifier: "DevShotThink_TakeShot");
    dataDesc_481[2].fieldOffset = 0;
    *(_DWORD *)&dataDesc_481[2].fieldSize = 2097153;
    dataDesc_481[2].externalName = nullptr;
    dataDesc_481[2].pSaveRestoreOps = nullptr;
    dataDesc_481[2].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CPointDevShotCamera::DevShotThink_TakeShot;
    *(_QWORD *)&dataDesc_481[2].td = 0;
    *(_QWORD *)&dataDesc_481[2].override_field = 0;
    *(_QWORD *)&dataDesc_481[2].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_481[2].flatOffset[1] = 0;
    dataDesc_481[3].fieldType = FIELD_VOID;
    Name = CDatadescGeneratedNameHolder::GenerateName(this: &nameHolder_336, pszIdentifier: "DevShotThink_PostShot");
    *(_QWORD *)&dataDesc_481[3].td = 0;
    *(_QWORD *)&dataDesc_481[3].override_field = 0;
    *(_QWORD *)&dataDesc_481[3].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_481[3].flatOffset[1] = 0;
    dataDesc_481[3].fieldName = Name;
    dataDesc_481[4].fieldTolerance = 0.0;
    dataDesc_481[5].fieldTolerance = 0.0;
    dataDesc_481[3].fieldOffset = 0;
    *(_DWORD *)&dataDesc_481[3].fieldSize = 2097153;
    dataDesc_481[3].externalName = nullptr;
    dataDesc_481[3].pSaveRestoreOps = nullptr;
    dataDesc_481[3].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CPointDevShotCamera::DevShotThink_PostShot;
    dataDesc_481[4].fieldType = FIELD_STRING;
    dataDesc_481[4].fieldName = "m_iszCameraName";
    dataDesc_481[4].fieldOffset = 852;
    *(_DWORD *)&dataDesc_481[4].fieldSize = 393217;
    dataDesc_481[4].externalName = "cameraname";
    dataDesc_481[4].pSaveRestoreOps = nullptr;
    dataDesc_481[4].inputFunc = nullptr;
    dataDesc_481[4].td = nullptr;
    dataDesc_481[4].fieldSizeInBytes = 4;
    dataDesc_481[4].override_field = nullptr;
    dataDesc_481[4].override_count = 0;
    *(_QWORD *)dataDesc_481[4].flatOffset = 0;
    *(_DWORD *)&dataDesc_481[4].flatGroup = 0;
    dataDesc_481[5].fieldType = FIELD_INTEGER;
    dataDesc_481[5].fieldName = "m_iFOV";
    dataDesc_481[5].fieldOffset = 856;
    *(_DWORD *)&dataDesc_481[5].fieldSize = 393217;
    dataDesc_481[5].externalName = "FOV";
    dataDesc_481[5].pSaveRestoreOps = nullptr;
    dataDesc_481[5].inputFunc = nullptr;
    dataDesc_481[5].td = nullptr;
    dataDesc_481[5].fieldSizeInBytes = 4;
    dataDesc_481[5].override_field = nullptr;
    dataDesc_481[5].override_count = 0;
    *(_QWORD *)dataDesc_481[5].flatOffset = 0;
    *(_DWORD *)&dataDesc_481[5].flatGroup = 0;
  }
  CPointDevShotCamera::m_DataMap.dataNumFields = 5;
  CPointDevShotCamera::m_DataMap.dataDesc = &dataDesc_481[1];
  return &CPointDevShotCamera::m_DataMap;
}
