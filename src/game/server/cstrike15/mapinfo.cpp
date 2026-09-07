// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/cstrike15/mapinfo.cpp
// Functions: 60
// ============================================================

#include "game\server\cstrike15\mapinfo.h"

//------------------------------------------------------------------------------
// Address: 0x102A47E0
// Name: public: virtual struct datamap_t __near * CMapInfo::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CMapInfo::GetDataDescMap(CMapInfo *this)
{
  return &CMapInfo::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x102A4830
// Name: public: virtual bool CMapInfo::KeyValue(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CMapInfo::KeyValue(CMapInfo *this, const char *szKeyName, const char *szValue)
{
  float v5; // xmm0_4

  if ( szKeyName != "buying" && _V_stricmp(s1: szKeyName, s2: "buying") != 0 )
  {
    if ( szKeyName != "bombradius" && _V_stricmp(s1: szKeyName, s2: "bombradius") != 0 )
    {
      return CServerOnlyPointEntity::KeyValue((CLogicalEntity *)this, szKeyName, szValue);
    }
    else
    {
      v5 = (float)atoi(nptr: szValue);
      this->m_flBombRadius = v5;
      if ( v5 > 2048.0 )
        this->m_flBombRadius = 2048.0;
      return true;
    }
  }
  else
  {
    this->m_iBuyingStatus = atoi(nptr: szValue);
    return true;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102A48E0
// Name: public: virtual void CMapInfo::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapInfo::Spawn(CMapInfo *this)
{
  CBaseEntity::SetMoveType(this, val: MOVETYPE_NONE, moveCollide: MOVECOLLIDE_DEFAULT);
  CCollisionProperty::SetSolid(this: &this->m_Collision, val: SOLID_NONE);
  CBaseEntity::AddEffects(this, nEffects: 32);
}

//------------------------------------------------------------------------------
// Address: 0x102A4910
// Name: public: void CMapInfo::InputFireWinCondition(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapInfo::InputFireWinCondition(CMapInfo *this, inputdata_t *inputdata)
{
  const char *pszValue; // eax

  if ( inputdata->value.fieldType == FIELD_INTEGER )
    pszValue = inputdata->value.iszVal.pszValue;
  else
    pszValue = nullptr;
  CCSGameRules::TerminateRound(this: (CCSGameRules *)g_pGameRules, tmDelay: 5.0, iReason: (int)pszValue);
}

//------------------------------------------------------------------------------
// Address: 0x103FBB30
// Name: _dynamic_initializer_for__info_node_link_controller__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__info_node_link_controller__()
{
  CEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(CEntityFactoryDictionary *, CEntityFactory<CAI_DynamicLinkController> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &info_node_link_controller,
           a3: "info_node_link_controller");
}

//------------------------------------------------------------------------------
// Address: 0x103FBB60
// Name: _dynamic_initializer_for__info_node_link__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__info_node_link__()
{
  CEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(CEntityFactoryDictionary *, CEntityFactory<CAI_DynamicLink> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &info_node_link,
           a3: "info_node_link");
}

//------------------------------------------------------------------------------
// Address: 0x103FBB90
// Name: _dynamic_initializer_for__info_radial_link_controller__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__info_radial_link_controller__()
{
  CEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(CEntityFactoryDictionary *, CEntityFactory<CAI_RadialLinkController> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &info_radial_link_controller,
           a3: "info_radial_link_controller");
}

//------------------------------------------------------------------------------
// Address: 0x103FC670
// Name: _dynamic_initializer_for__info_hint__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__info_hint__()
{
  CEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(CEntityFactoryDictionary *, CEntityFactory<CNodeEnt> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &info_hint,
           a3: "info_hint");
}

//------------------------------------------------------------------------------
// Address: 0x103FC690
// Name: _dynamic_initializer_for__info_node__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__info_node__()
{
  CEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(CEntityFactoryDictionary *, CEntityFactory<CNodeEnt> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &info_node,
           a3: "info_node");
}

//------------------------------------------------------------------------------
// Address: 0x103FC6B0
// Name: _dynamic_initializer_for__info_node_hint__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__info_node_hint__()
{
  CEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(CEntityFactoryDictionary *, CEntityFactory<CNodeEnt> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &info_node_hint,
           a3: "info_node_hint");
}

//------------------------------------------------------------------------------
// Address: 0x103FC6D0
// Name: _dynamic_initializer_for__info_node_air__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__info_node_air__()
{
  CEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(CEntityFactoryDictionary *, CEntityFactory<CNodeEnt> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &info_node_air,
           a3: "info_node_air");
}

//------------------------------------------------------------------------------
// Address: 0x103FC6F0
// Name: _dynamic_initializer_for__info_node_air_hint__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__info_node_air_hint__()
{
  CEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(CEntityFactoryDictionary *, CEntityFactory<CNodeEnt> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &info_node_air_hint,
           a3: "info_node_air_hint");
}

//------------------------------------------------------------------------------
// Address: 0x103FC710
// Name: _dynamic_initializer_for__info_node_climb__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__info_node_climb__()
{
  CEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(CEntityFactoryDictionary *, CEntityFactory<CNodeEnt> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &info_node_climb,
           a3: "info_node_climb");
}

//------------------------------------------------------------------------------
// Address: 0x104007B0
// Name: _dynamic_initializer_for__info_target__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__info_target__()
{
  CEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(CEntityFactoryDictionary *, CEntityFactory<CInfoTarget> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &info_target,
           a3: "info_target");
}

//------------------------------------------------------------------------------
// Address: 0x10402800
// Name: _dynamic_initializer_for__info_target_instructor_hint__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__info_target_instructor_hint__()
{
  CEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(CEntityFactoryDictionary *, CEntityFactory<CInfoInstructorHintTarget> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &info_target_instructor_hint,
           a3: "info_target_instructor_hint");
}

//------------------------------------------------------------------------------
// Address: 0x10403F10
// Name: _dynamic_initializer_for__info_ladder_dismount__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__info_ladder_dismount__()
{
  CEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(CEntityFactoryDictionary *, CEntityFactory<CInfoLadderDismount> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &info_ladder_dismount,
           a3: "info_ladder_dismount");
}

//------------------------------------------------------------------------------
// Address: 0x104053F0
// Name: _dynamic_initializer_for__info_camera_link__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__info_camera_link__()
{
  CEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(CEntityFactoryDictionary *, CEntityFactory<CInfoCameraLink> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &info_camera_link,
           a3: "info_camera_link");
}

//------------------------------------------------------------------------------
// Address: 0x10405460
// Name: _dynamic_initializer_for__info_overlay_accessor__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__info_overlay_accessor__()
{
  CEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(CEntityFactoryDictionary *, CEntityFactory<CInfoOverlayAccessor> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &info_overlay_accessor,
           a3: "info_overlay_accessor");
}

//------------------------------------------------------------------------------
// Address: 0x104054F0
// Name: _dynamic_initializer_for__info_remarkable__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__info_remarkable__()
{
  CEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(CEntityFactoryDictionary *, CEntityFactory<CInfoRemarkable> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &info_remarkable,
           a3: "info_remarkable");
}

//------------------------------------------------------------------------------
// Address: 0x10405520
// Name: _dynamic_initializer_for__info_intermission__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__info_intermission__()
{
  CEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(CEntityFactoryDictionary *, CEntityFactory<CInfoIntermission> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &info_intermission,
           a3: "info_intermission");
}

//------------------------------------------------------------------------------
// Address: 0x10406B80
// Name: _dynamic_initializer_for__info_particle_system__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__info_particle_system__()
{
  CEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(CEntityFactoryDictionary *, CEntityFactory<CParticleSystem> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &info_particle_system,
           a3: "info_particle_system");
}

//------------------------------------------------------------------------------
// Address: 0x10406DB0
// Name: _dynamic_initializer_for__info_constraint_anchor__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__info_constraint_anchor__()
{
  CEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(CEntityFactoryDictionary *, CEntityFactory<CConstraintAnchor> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &info_constraint_anchor,
           a3: "info_constraint_anchor");
}

//------------------------------------------------------------------------------
// Address: 0x10407AE0
// Name: _dynamic_initializer_for__info_mass_center__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__info_mass_center__()
{
  CEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(CEntityFactoryDictionary *, CEntityFactory<CInfoMassCenter> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &info_mass_center,
           a3: "info_mass_center");
}

//------------------------------------------------------------------------------
// Address: 0x1040A8B0
// Name: _dynamic_initializer_for__info_null__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__info_null__()
{
  CEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(CEntityFactoryDictionary *, CEntityFactory<CNullEntity> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &info_null,
           a3: "info_null");
}

//------------------------------------------------------------------------------
// Address: 0x1040A8E0
// Name: _dynamic_initializer_for__info_player_deathmatch__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__info_player_deathmatch__()
{
  CEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(CEntityFactoryDictionary *, CEntityFactory<CBaseDMStart> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &info_player_deathmatch,
           a3: "info_player_deathmatch");
}

//------------------------------------------------------------------------------
// Address: 0x1040A900
// Name: _dynamic_initializer_for__info_player_start__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__info_player_start__()
{
  CEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(CEntityFactoryDictionary *, CEntityFactory<CPointEntity> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &info_player_start,
           a3: "info_player_start");
}

//------------------------------------------------------------------------------
// Address: 0x1040A920
// Name: _dynamic_initializer_for__info_landmark__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__info_landmark__()
{
  CEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(CEntityFactoryDictionary *, CEntityFactory<CPointEntity> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &info_landmark,
           a3: "info_landmark");
}

//------------------------------------------------------------------------------
// Address: 0x1040ACD0
// Name: _dynamic_initializer_for__info_player_teamspawn__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__info_player_teamspawn__()
{
  CEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(CEntityFactoryDictionary *, CEntityFactory<CTeamSpawnPoint> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &info_player_teamspawn,
           a3: "info_player_teamspawn");
}

//------------------------------------------------------------------------------
// Address: 0x1040AD00
// Name: _dynamic_initializer_for__info_vehicle_groundspawn__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__info_vehicle_groundspawn__()
{
  CEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(CEntityFactoryDictionary *, CEntityFactory<CTeamVehicleSpawnPoint> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &info_vehicle_groundspawn,
           a3: "info_vehicle_groundspawn");
}

//------------------------------------------------------------------------------
// Address: 0x1040BC80
// Name: _dynamic_initializer_for__info_teleport_destination__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__info_teleport_destination__()
{
  CEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(CEntityFactoryDictionary *, CEntityFactory<CPointEntity> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &info_teleport_destination,
           a3: "info_teleport_destination");
}

//------------------------------------------------------------------------------
// Address: 0x1040D0A0
// Name: _dynamic_initializer_for__info_game_event_proxy__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__info_game_event_proxy__()
{
  CEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(CEntityFactoryDictionary *, CEntityFactory<CInfoGameEventProxy> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &info_game_event_proxy,
           a3: "info_game_event_proxy");
}

//------------------------------------------------------------------------------
// Address: 0x1040D110
// Name: _dynamic_initializer_for__info_projecteddecal__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__info_projecteddecal__()
{
  CEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(CEntityFactoryDictionary *, CEntityFactory<CProjectedDecal> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &info_projecteddecal,
           a3: "info_projecteddecal");
}

//------------------------------------------------------------------------------
// Address: 0x1040D3F0
// Name: _dynamic_initializer_for__info_player_terrorist__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__info_player_terrorist__()
{
  CEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(CEntityFactoryDictionary *, CEntityFactory<CPointEntity> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &info_player_terrorist,
           a3: "info_player_terrorist");
}

//------------------------------------------------------------------------------
// Address: 0x1040D410
// Name: _dynamic_initializer_for__info_player_counterterrorist__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__info_player_counterterrorist__()
{
  CEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(CEntityFactoryDictionary *, CEntityFactory<CPointEntity> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &info_player_counterterrorist,
           a3: "info_player_counterterrorist");
}

//------------------------------------------------------------------------------
// Address: 0x1040D430
// Name: _dynamic_initializer_for__info_player_logo__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__info_player_logo__()
{
  CEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(CEntityFactoryDictionary *, CEntityFactory<CPointEntity> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &info_player_logo,
           a3: "info_player_logo");
}

//------------------------------------------------------------------------------
// Address: 0x10410210
// Name: _dynamic_initializer_for__info_view_parameters__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__info_view_parameters__()
{
  CEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(CEntityFactoryDictionary *, CEntityFactory<CInfoViewParameters> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &info_view_parameters,
           a3: "info_view_parameters");
}

//------------------------------------------------------------------------------
// Address: 0x10410440
// Name: _dynamic_initializer_for__info_map_parameters__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__info_map_parameters__()
{
  CEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(CEntityFactoryDictionary *, CEntityFactory<CMapInfo> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &info_map_parameters,
           a3: "info_map_parameters");
}

//------------------------------------------------------------------------------
// Address: 0x10410460
// Name: CMapInfo_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CMapInfo_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CMapInfo>();
  CMapInfo_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102A4950
// Name: class CMapInfo __near * _CreateEntityTemplate<class CMapInfo>(class CMapInfo __near *,char const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CMapInfo *__cdecl _CreateEntityTemplate<CMapInfo>(CMapInfo *newEnt, const char *className)
{
  CBaseEntity *v2; // eax
  CBaseEntity *v3; // esi

  v2 = (CBaseEntity *)CBaseEntity::operator new(stAllocateBlock: 0x35Cu);
  v3 = v2;
  if ( v2 != nullptr )
  {
    CBaseEntity::CBaseEntity(this: v2, bServerOnly: false);
    v3->__vftable = (CBaseEntity_vtbl *)&CMapInfo::`vftable';
    v3[1].m_pfnMoveDone = (void (__thiscall *)(CBaseEntity *))1140457472;
    v3[1].__vftable = nullptr;
    if ( g_pMapInfo != nullptr )
      _Warning(a1: "Warning: Multiple info_map_parameters entities in map!\n");
    else
      g_pMapInfo = (CMapInfo *)v3;
    v3->PostConstructor(this: v3, a2: className);
    return (CMapInfo *)v3;
  }
  else
  {
    (*(void (__thiscall **)(_DWORD, const char *))(MEMORY[0] + 112))(a1: 0, a2: className);
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x103FC730
// Name: _dynamic_initializer_for__aitesthull__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__aitesthull__()
{
  CEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(CEntityFactoryDictionary *, CEntityFactory<CAI_TestHull> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &aitesthull,
           a3: "aitesthull");
}

//------------------------------------------------------------------------------
// Address: 0x104007D0
// Name: _dynamic_initializer_for__g_CBeam_ClassReg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ServerClass *dynamic_initializer_for__g_CBeam_ClassReg__()
{
  return ServerClass::ServerClass(this: &g_CBeam_ClassReg, pNetworkName: "CBeam", pTable: &DT_Beam::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x10405410
// Name: _dynamic_initializer_for__g_CInfoOverlayAccessor_ClassReg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ServerClass *dynamic_initializer_for__g_CInfoOverlayAccessor_ClassReg__()
{
  return ServerClass::ServerClass(
           this: &g_CInfoOverlayAccessor_ClassReg,
           pNetworkName: "CInfoOverlayAccessor",
           pTable: &DT_InfoOverlayAccessor::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x10406BA0
// Name: _dynamic_initializer_for__s_LightMutex__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_LightMutex__()
{
  s_LightMutex.m_ownerID = 0;
  s_LightMutex.m_depth = 0;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10406BB0
// Name: _dynamic_initializer_for__s_BoneMutex__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_BoneMutex__()
{
  s_BoneMutex.m_ownerID = 0;
  s_BoneMutex.m_depth = 0;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10407B00
// Name: _dynamic_initializer_for____g_CreateCServerGameTagsIServerGameTags_reg___3
// Source: linker_block_proximity
//------------------------------------------------------------------------------
InterfaceReg *dynamic_initializer_for____g_CreateCServerGameTagsIServerGameTags_reg___3()
{
  return InterfaceReg::InterfaceReg(
           this: &_g_CreateCServerGameTagsIServerGameTags_reg_3,
           fn: (void *(__cdecl *)())_CreateCServerGameTagsIServerGameTags_interface_3,
           pName: "ServerGameTags001");
}

//------------------------------------------------------------------------------
// Address: 0x10407B20
// Name: _dynamic_initializer_for__autoaim_max_dist__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__autoaim_max_dist__()
{
  ConVar::ConVar(this: &autoaim_max_dist, pName: "autoaim_max_dist", pDefaultValue: "2160", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__autoaim_max_dist__);
}

//------------------------------------------------------------------------------
// Address: 0x10407B50
// Name: _dynamic_initializer_for__autoaim_max_deflect__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__autoaim_max_deflect__()
{
  ConVar::ConVar(this: &autoaim_max_deflect, pName: "autoaim_max_deflect", pDefaultValue: "0.99", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__autoaim_max_deflect__);
}

//------------------------------------------------------------------------------
// Address: 0x10407B80
// Name: _dynamic_initializer_for__spec_freeze_time__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__spec_freeze_time__()
{
  ConVar::ConVar(
    this: &spec_freeze_time,
    pName: "spec_freeze_time",
    pDefaultValue: "5.0",
    flags: 24576,
    pHelpString: "Time spend frozen in observer freeze cam.");
  return atexit(func: dynamic_atexit_destructor_for__spec_freeze_time__);
}

//------------------------------------------------------------------------------
// Address: 0x10407BB0
// Name: _dynamic_initializer_for__spec_freeze_traveltime__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__spec_freeze_traveltime__()
{
  ConVar::ConVar(
    this: &spec_freeze_traveltime,
    pName: "spec_freeze_traveltime",
    pDefaultValue: "0.7",
    flags: 24576,
    pHelpString: "Time taken to zoom in to frame a target in observer freeze cam.",
    bMin: true,
    fMin: 0.0099999998,
    bMax: false,
    fMax: 0.0);
  return atexit(func: dynamic_atexit_destructor_for__spec_freeze_traveltime__);
}

//------------------------------------------------------------------------------
// Address: 0x10407C00
// Name: _dynamic_initializer_for__sv_bonus_challenge__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_bonus_challenge__()
{
  ConVar::ConVar(
    this: &sv_bonus_challenge,
    pName: "sv_bonus_challenge",
    pDefaultValue: "0",
    flags: 0x2000,
    pHelpString: "Set to values other than 0 to select a bonus map challenge type.");
  return atexit(func: dynamic_atexit_destructor_for__sv_bonus_challenge__);
}

//------------------------------------------------------------------------------
// Address: 0x10407C30
// Name: _dynamic_initializer_for__sv_regeneration_wait_time__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_regeneration_wait_time__()
{
  ConVar::ConVar(
    this: &sv_regeneration_wait_time,
    pName: "sv_regeneration_wait_time",
    pDefaultValue: "1.0",
    flags: 0x2000);
  return atexit(func: dynamic_atexit_destructor_for__sv_regeneration_wait_time__);
}

//------------------------------------------------------------------------------
// Address: 0x10407C60
// Name: _dynamic_initializer_for__old_armor__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__old_armor__()
{
  ConVar::ConVar(this: &old_armor, pName: "player_old_armor", pDefaultValue: "0", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__old_armor__);
}

//------------------------------------------------------------------------------
// Address: 0x10407C90
// Name: _dynamic_initializer_for__sv_noclipduringpause__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_noclipduringpause__()
{
  ConVar::ConVar(
    this: &sv_noclipduringpause,
    pName: "sv_noclipduringpause",
    pDefaultValue: "0",
    flags: 24576,
    pHelpString: "If cheats are enabled, then you can noclip with the game paused (for doing screenshots, etc.).");
  return atexit(func: dynamic_atexit_destructor_for__sv_noclipduringpause__);
}

//------------------------------------------------------------------------------
// Address: 0x10407CC0
// Name: _dynamic_initializer_for__sk_player_head__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__sk_player_head__()
{
  ConVar::ConVar(this: &sk_player_head, pName: "sk_player_head", pDefaultValue: "2", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__sk_player_head__);
}

//------------------------------------------------------------------------------
// Address: 0x10407CF0
// Name: _dynamic_initializer_for__sk_player_chest__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__sk_player_chest__()
{
  ConVar::ConVar(this: &sk_player_chest, pName: "sk_player_chest", pDefaultValue: "1", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__sk_player_chest__);
}

//------------------------------------------------------------------------------
// Address: 0x10407D20
// Name: _dynamic_initializer_for__sk_player_stomach__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__sk_player_stomach__()
{
  ConVar::ConVar(this: &sk_player_stomach, pName: "sk_player_stomach", pDefaultValue: "1", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__sk_player_stomach__);
}

//------------------------------------------------------------------------------
// Address: 0x10407D50
// Name: _dynamic_initializer_for__sk_player_arm__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__sk_player_arm__()
{
  ConVar::ConVar(this: &sk_player_arm, pName: "sk_player_arm", pDefaultValue: "1", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__sk_player_arm__);
}

//------------------------------------------------------------------------------
// Address: 0x10407D80
// Name: _dynamic_initializer_for__sk_player_leg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__sk_player_leg__()
{
  ConVar::ConVar(this: &sk_player_leg, pName: "sk_player_leg", pDefaultValue: "1", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__sk_player_leg__);
}

//------------------------------------------------------------------------------
// Address: 0x1040D130
// Name: _dynamic_initializer_for__worldspawn__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__worldspawn__()
{
  CEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(CEntityFactoryDictionary *, CEntityFactory<CWorld> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &worldspawn,
           a3: "worldspawn");
}

//------------------------------------------------------------------------------
// Address: 0x1040D450
// Name: _dynamic_initializer_for____g_GameRulesRegister_CCSGameRules__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CGameRulesRegister *dynamic_initializer_for____g_GameRulesRegister_CCSGameRules__()
{
  return CGameRulesRegister::CGameRulesRegister(
           this: &_g_GameRulesRegister_CCSGameRules,
           pClassName: "CCSGameRules",
           fn: __CreateGameRules_CCSGameRules);
}
