// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/cstrike15/te_shotgun_shot.cpp
// Functions: 70
// ============================================================

#include "game\server\cstrike15\te_shotgun_shot.h"

//------------------------------------------------------------------------------
// Address: 0x102A6420
// Name: public: virtual class ServerClass __near * CTEFireBullets::GetServerClass(void)
// Source: json
//------------------------------------------------------------------------------
ServerClass *__thiscall CTEFireBullets::GetServerClass(CTEFireBullets *this)
{
  return &g_CTEFireBullets_ClassReg;
}

//------------------------------------------------------------------------------
// Address: 0x102A6430
// Name: public: virtual class ServerClass __near * CTEPlantBomb::GetServerClass(void)
// Source: json
//------------------------------------------------------------------------------
ServerClass *__thiscall CTEPlantBomb::GetServerClass(CTEPlantBomb *this)
{
  return &g_CTEPlantBomb_ClassReg;
}

//------------------------------------------------------------------------------
// Address: 0x102A6760
// Name: void TE_FireBullets(int,class Vector const __near &,class QAngle const __near &,int,int,int,float,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TE_FireBullets(
        int iPlayerIndex,
        CNetworkVectorBase<Vector,CTEFireBullets::NetworkVar_m_vecOrigin> *vOrigin,
        CNetworkVectorBase<QAngle,CTEFireBullets::NetworkVar_m_vecAngles> *vAngles,
        int iWeaponID,
        int iMode,
        int iSeed,
        float fInaccuracy,
        float fSpread)
{
  CPASFilter filter; // [esp+4h] [ebp-20h] BYREF

  CRecipientFilter::CRecipientFilter(this: &filter);
  filter.__vftable = (CPASFilter_vtbl *)&CPASFilter::`vftable';
  CRecipientFilter::AddRecipientsByPAS(this: &filter, origin: &vOrigin->m_Value);
  CRecipientFilter::UsePredictionRules(this: &filter);
  if ( g_TEFireBullets.m_iPlayer.m_Value != iPlayerIndex - 1 )
    g_TEFireBullets.m_iPlayer.m_Value = iPlayerIndex - 1;
  if ( vOrigin->m_Value.x != g_TEFireBullets.m_vecOrigin.m_Value.x
    || vOrigin->m_Value.y != g_TEFireBullets.m_vecOrigin.m_Value.y
    || vOrigin->m_Value.z != g_TEFireBullets.m_vecOrigin.m_Value.z )
  {
    g_TEFireBullets.m_vecOrigin = *vOrigin;
  }
  if ( vAngles->m_Value.x != g_TEFireBullets.m_vecAngles.m_Value.x
    || vAngles->m_Value.y != g_TEFireBullets.m_vecAngles.m_Value.y
    || vAngles->m_Value.z != g_TEFireBullets.m_vecAngles.m_Value.z )
  {
    g_TEFireBullets.m_vecAngles = *vAngles;
  }
  if ( g_TEFireBullets.m_iSeed.m_Value != iSeed )
    g_TEFireBullets.m_iSeed.m_Value = iSeed;
  if ( g_TEFireBullets.m_fInaccuracy.m_Value != fInaccuracy )
    g_TEFireBullets.m_fInaccuracy.m_Value = fInaccuracy;
  if ( g_TEFireBullets.m_fSpread.m_Value != fSpread )
    g_TEFireBullets.m_fSpread.m_Value = fSpread;
  if ( g_TEFireBullets.m_iMode.m_Value != iMode )
    g_TEFireBullets.m_iMode.m_Value = iMode;
  if ( g_TEFireBullets.m_iWeaponID.m_Value != iWeaponID )
    g_TEFireBullets.m_iWeaponID.m_Value = iWeaponID;
  CBaseTempEntity::Create(this: &g_TEFireBullets, &filter, delay: 0.0);
  CRecipientFilter::~CRecipientFilter(this: &filter);
}

//------------------------------------------------------------------------------
// Address: 0x102A68E0
// Name: void TE_PlantBomb(int,class Vector const __near &,enum PlantBombOption_t)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TE_PlantBomb(int iPlayerIndex, const Vector *vOrigin, PlantBombOption_t option)
{
  CPASFilter filter; // [esp+4h] [ebp-20h] BYREF

  CRecipientFilter::CRecipientFilter(this: &filter);
  filter.__vftable = (CPASFilter_vtbl *)&CPASFilter::`vftable';
  CRecipientFilter::AddRecipientsByPAS(this: &filter, origin: vOrigin);
  CRecipientFilter::UsePredictionRules(this: &filter);
  if ( g_TEPlantBomb.m_iPlayer.m_Value != iPlayerIndex - 1 )
    g_TEPlantBomb.m_iPlayer.m_Value = iPlayerIndex - 1;
  if ( g_TEPlantBomb.m_option.m_Value != option )
    g_TEPlantBomb.m_option.m_Value = option;
  CBaseTempEntity::Create(this: &g_TEPlantBomb, &filter, delay: 0.0);
  CRecipientFilter::~CRecipientFilter(this: &filter);
}

//------------------------------------------------------------------------------
// Address: 0x10410620
// Name: DT_TEFireBullets::_dynamic_initializer_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
int DT_TEFireBullets::_dynamic_initializer_for__g_SendTable__()
{
  SendTable::SendTable(this: &DT_TEFireBullets::g_SendTable);
  return atexit(func: DT_TEFireBullets::_dynamic_atexit_destructor_for__g_SendTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10410640
// Name: DT_TEFireBullets::_dynamic_initializer_for__g_SendTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_TEFireBullets::_dynamic_initializer_for__g_SendTableInit__()
{
  int result; // eax

  result = ServerClassInit<DT_TEFireBullets::ignored>();
  DT_TEFireBullets::g_SendTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104106A0
// Name: DT_TEPlantBomb::_dynamic_initializer_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
int DT_TEPlantBomb::_dynamic_initializer_for__g_SendTable__()
{
  SendTable::SendTable(this: &DT_TEPlantBomb::g_SendTable);
  return atexit(func: DT_TEPlantBomb::_dynamic_atexit_destructor_for__g_SendTable__);
}

//------------------------------------------------------------------------------
// Address: 0x104106C0
// Name: DT_TEPlantBomb::_dynamic_initializer_for__g_SendTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_TEPlantBomb::_dynamic_initializer_for__g_SendTableInit__()
{
  int result; // eax

  result = ServerClassInit<DT_TEPlantBomb::ignored>();
  DT_TEPlantBomb::g_SendTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104200D0
// Name: DT_TEFireBullets::_dynamic_atexit_destructor_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_TEFireBullets::_dynamic_atexit_destructor_for__g_SendTable__()
{
  CAI_BaseNPC::OnSetSchedule(this: (vgui::Panel *)&DT_TEFireBullets::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x10420100
// Name: DT_TEPlantBomb::_dynamic_atexit_destructor_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_TEPlantBomb::_dynamic_atexit_destructor_for__g_SendTable__()
{
  CAI_BaseNPC::OnSetSchedule(this: (vgui::Panel *)&DT_TEPlantBomb::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x102A6950
// Name: __CreateCServerGameTagsIServerGameTags_interface_13
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CServerGameTags *__cdecl _CreateCServerGameTagsIServerGameTags_interface_13()
{
  return &_g_CServerGameTags_singleton_13;
}

//------------------------------------------------------------------------------
// Address: 0x10410650
// Name: _dynamic_initializer_for__g_TEFireBullets__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_TEFireBullets__()
{
  CBaseTempEntity::CBaseTempEntity(this: &g_TEFireBullets, name: "Shotgun Shot");
  g_TEFireBullets.__vftable = (CTEFireBullets_vtbl *)&CTEFireBullets::`vftable';
  return atexit(func: dynamic_atexit_destructor_for__g_TEFireBullets__);
}

//------------------------------------------------------------------------------
// Address: 0x10410680
// Name: _dynamic_initializer_for__g_CTEPlantBomb_ClassReg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ServerClass *dynamic_initializer_for__g_CTEPlantBomb_ClassReg__()
{
  return ServerClass::ServerClass(
           this: &g_CTEPlantBomb_ClassReg,
           pNetworkName: "CTEPlantBomb",
           pTable: &DT_TEPlantBomb::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x104106D0
// Name: _dynamic_initializer_for__g_TEPlantBomb__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_TEPlantBomb__()
{
  CBaseTempEntity::CBaseTempEntity(this: &g_TEPlantBomb, name: "Bomb Plant");
  g_TEPlantBomb.__vftable = (CTEPlantBomb_vtbl *)&CTEPlantBomb::`vftable';
  return atexit(func: dynamic_atexit_destructor_for__g_TEPlantBomb__);
}

//------------------------------------------------------------------------------
// Address: 0x10410700
// Name: _dynamic_initializer_for____g_CreateCServerGameTagsIServerGameTags_reg___13
// Source: linker_block_proximity
//------------------------------------------------------------------------------
InterfaceReg *dynamic_initializer_for____g_CreateCServerGameTagsIServerGameTags_reg___13()
{
  return InterfaceReg::InterfaceReg(
           this: &_g_CreateCServerGameTagsIServerGameTags_reg_13,
           fn: (void *(__cdecl *)())_CreateCServerGameTagsIServerGameTags_interface_13,
           pName: "ServerGameTags001");
}

//------------------------------------------------------------------------------
// Address: 0x10410720
// Name: _dynamic_initializer_for__cs_bot__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cs_bot__()
{
  CEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(CEntityFactoryDictionary *, CEntityFactory<CCSBot> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &cs_bot,
           a3: "cs_bot");
}

//------------------------------------------------------------------------------
// Address: 0x104200E0
// Name: _dynamic_atexit_destructor_for__g_TEFireBullets__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_TEFireBullets__()
{
  g_TEFireBullets.__vftable = (CTEFireBullets_vtbl *)&CTEFireBullets::`vftable';
  CBaseTempEntity::~CBaseTempEntity(this: &g_TEFireBullets);
}

//------------------------------------------------------------------------------
// Address: 0x10420110
// Name: _ServerClassInit_DT_TEPlantBomb::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ServerClassInit_DT_TEPlantBomb::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__()
{
  SendProp *v0; // esi
  int i; // edi

  v0 = (SendProp *)&_S3_151;
  for ( i = 3; i >= 0; --i )
    SendProp::~SendProp(this: --v0);
}

//------------------------------------------------------------------------------
// Address: 0x10420130
// Name: _dynamic_atexit_destructor_for__g_TEPlantBomb__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_TEPlantBomb__()
{
  g_TEPlantBomb.__vftable = (CTEPlantBomb_vtbl *)&CTEPlantBomb::`vftable';
  CBaseTempEntity::~CBaseTempEntity(this: &g_TEPlantBomb);
}

//------------------------------------------------------------------------------
// Address: 0x10420150
// Name: _ServerClassInit_DT_TEFireBullets::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ServerClassInit_DT_TEFireBullets::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__()
{
  SendProp *v0; // esi
  int i; // edi

  v0 = (SendProp *)&_S2_260;
  for ( i = 9; i >= 0; --i )
    SendProp::~SendProp(this: --v0);
}

//------------------------------------------------------------------------------
// Address: 0x10420170
// Name: _DataMapInit_CCSBot__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CCSBot__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_487);
}

//------------------------------------------------------------------------------
// Address: 0x10420180
// Name: _dynamic_atexit_destructor_for__cv_bot_traceview__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cv_bot_traceview__()
{
  ConVar::~ConVar(this: &cv_bot_traceview);
}

//------------------------------------------------------------------------------
// Address: 0x10420190
// Name: _dynamic_atexit_destructor_for__cv_bot_stop__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cv_bot_stop__()
{
  ConVar::~ConVar(this: &cv_bot_stop);
}

//------------------------------------------------------------------------------
// Address: 0x104201A0
// Name: _dynamic_atexit_destructor_for__cv_bot_show_nav__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cv_bot_show_nav__()
{
  ConVar::~ConVar(this: &cv_bot_show_nav);
}

//------------------------------------------------------------------------------
// Address: 0x104201B0
// Name: _dynamic_atexit_destructor_for__cv_bot_walk__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cv_bot_walk__()
{
  ConVar::~ConVar(this: &cv_bot_walk);
}

//------------------------------------------------------------------------------
// Address: 0x104201C0
// Name: _dynamic_atexit_destructor_for__cv_bot_difficulty__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cv_bot_difficulty__()
{
  ConVar::~ConVar(this: &cv_bot_difficulty);
}

//------------------------------------------------------------------------------
// Address: 0x104201D0
// Name: _dynamic_atexit_destructor_for__cv_bot_debug__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cv_bot_debug__()
{
  ConVar::~ConVar(this: &cv_bot_debug);
}

//------------------------------------------------------------------------------
// Address: 0x104201E0
// Name: _dynamic_atexit_destructor_for__cv_bot_debug_target__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cv_bot_debug_target__()
{
  ConVar::~ConVar(this: &cv_bot_debug_target);
}

//------------------------------------------------------------------------------
// Address: 0x104201F0
// Name: _dynamic_atexit_destructor_for__cv_bot_quota__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cv_bot_quota__()
{
  ConVar::~ConVar(this: &cv_bot_quota);
}

//------------------------------------------------------------------------------
// Address: 0x10420200
// Name: _dynamic_atexit_destructor_for__cv_bot_quota_mode__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cv_bot_quota_mode__()
{
  ConVar::~ConVar(this: &cv_bot_quota_mode);
}

//------------------------------------------------------------------------------
// Address: 0x10420210
// Name: _dynamic_atexit_destructor_for__cv_bot_prefix__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cv_bot_prefix__()
{
  ConVar::~ConVar(this: &cv_bot_prefix);
}

//------------------------------------------------------------------------------
// Address: 0x10420220
// Name: _dynamic_atexit_destructor_for__cv_bot_allow_rogues__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cv_bot_allow_rogues__()
{
  ConVar::~ConVar(this: &cv_bot_allow_rogues);
}

//------------------------------------------------------------------------------
// Address: 0x10420230
// Name: _dynamic_atexit_destructor_for__cv_bot_allow_pistols__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cv_bot_allow_pistols__()
{
  ConVar::~ConVar(this: &cv_bot_allow_pistols);
}

//------------------------------------------------------------------------------
// Address: 0x10420240
// Name: _dynamic_atexit_destructor_for__cv_bot_allow_shotguns__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cv_bot_allow_shotguns__()
{
  ConVar::~ConVar(this: &cv_bot_allow_shotguns);
}

//------------------------------------------------------------------------------
// Address: 0x10420250
// Name: _dynamic_atexit_destructor_for__cv_bot_allow_sub_machine_guns__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cv_bot_allow_sub_machine_guns__()
{
  ConVar::~ConVar(this: &cv_bot_allow_sub_machine_guns);
}

//------------------------------------------------------------------------------
// Address: 0x10420260
// Name: _dynamic_atexit_destructor_for__cv_bot_allow_rifles__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cv_bot_allow_rifles__()
{
  ConVar::~ConVar(this: &cv_bot_allow_rifles);
}

//------------------------------------------------------------------------------
// Address: 0x10420270
// Name: _dynamic_atexit_destructor_for__cv_bot_allow_machine_guns__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cv_bot_allow_machine_guns__()
{
  ConVar::~ConVar(this: &cv_bot_allow_machine_guns);
}

//------------------------------------------------------------------------------
// Address: 0x10420280
// Name: _dynamic_atexit_destructor_for__cv_bot_allow_grenades__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cv_bot_allow_grenades__()
{
  ConVar::~ConVar(this: &cv_bot_allow_grenades);
}

//------------------------------------------------------------------------------
// Address: 0x10420290
// Name: _dynamic_atexit_destructor_for__cv_bot_allow_snipers__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cv_bot_allow_snipers__()
{
  ConVar::~ConVar(this: &cv_bot_allow_snipers);
}

//------------------------------------------------------------------------------
// Address: 0x104202A0
// Name: _dynamic_atexit_destructor_for__cv_bot_join_team__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cv_bot_join_team__()
{
  ConVar::~ConVar(this: &cv_bot_join_team);
}

//------------------------------------------------------------------------------
// Address: 0x104202B0
// Name: _dynamic_atexit_destructor_for__cv_bot_join_after_player__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cv_bot_join_after_player__()
{
  ConVar::~ConVar(this: &cv_bot_join_after_player);
}

//------------------------------------------------------------------------------
// Address: 0x104202C0
// Name: _dynamic_atexit_destructor_for__cv_bot_auto_vacate__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cv_bot_auto_vacate__()
{
  ConVar::~ConVar(this: &cv_bot_auto_vacate);
}

//------------------------------------------------------------------------------
// Address: 0x104202D0
// Name: _dynamic_atexit_destructor_for__cv_bot_zombie__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cv_bot_zombie__()
{
  ConVar::~ConVar(this: &cv_bot_zombie);
}

//------------------------------------------------------------------------------
// Address: 0x104202E0
// Name: _dynamic_atexit_destructor_for__cv_bot_defer_to_human__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cv_bot_defer_to_human__()
{
  ConVar::~ConVar(this: &cv_bot_defer_to_human);
}

//------------------------------------------------------------------------------
// Address: 0x104202F0
// Name: _dynamic_atexit_destructor_for__cv_bot_chatter__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cv_bot_chatter__()
{
  ConVar::~ConVar(this: &cv_bot_chatter);
}

//------------------------------------------------------------------------------
// Address: 0x10420300
// Name: _dynamic_atexit_destructor_for__cv_bot_profile_db__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cv_bot_profile_db__()
{
  ConVar::~ConVar(this: &cv_bot_profile_db);
}

//------------------------------------------------------------------------------
// Address: 0x10420310
// Name: _dynamic_atexit_destructor_for__cv_bot_dont_shoot__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cv_bot_dont_shoot__()
{
  ConVar::~ConVar(this: &cv_bot_dont_shoot);
}

//------------------------------------------------------------------------------
// Address: 0x10420320
// Name: _dynamic_atexit_destructor_for__cv_bot_eco_limit__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cv_bot_eco_limit__()
{
  ConVar::~ConVar(this: &cv_bot_eco_limit);
}

//------------------------------------------------------------------------------
// Address: 0x10420330
// Name: _dynamic_atexit_destructor_for__cv_bot_auto_follow__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cv_bot_auto_follow__()
{
  ConVar::~ConVar(this: &cv_bot_auto_follow);
}

//------------------------------------------------------------------------------
// Address: 0x10420340
// Name: _dynamic_atexit_destructor_for__cv_bot_flipout__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cv_bot_flipout__()
{
  ConVar::~ConVar(this: &cv_bot_flipout);
}

//------------------------------------------------------------------------------
// Address: 0x10420350
// Name: _dynamic_atexit_destructor_for__cv_bot_controllable__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cv_bot_controllable__()
{
  ConVar::~ConVar(this: &cv_bot_controllable);
}

//------------------------------------------------------------------------------
// Address: 0x10420360
// Name: _dynamic_atexit_destructor_for__bot_show_occupy_time__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__bot_show_occupy_time__()
{
  ConVar::~ConVar(this: &bot_show_occupy_time);
}

//------------------------------------------------------------------------------
// Address: 0x10420370
// Name: _dynamic_atexit_destructor_for__bot_show_battlefront__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__bot_show_battlefront__()
{
  ConVar::~ConVar(this: &bot_show_battlefront);
}

//------------------------------------------------------------------------------
// Address: 0x10420380
// Name: _dynamic_atexit_destructor_for__bot_join_delay__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__bot_join_delay__()
{
  ConVar::~ConVar(this: &bot_join_delay);
}

//------------------------------------------------------------------------------
// Address: 0x10420390
// Name: _dynamic_atexit_destructor_for__bot_add_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__bot_add_command__()
{
  ConCommand::~ConCommand(this: &bot_add_command);
}

//------------------------------------------------------------------------------
// Address: 0x104203A0
// Name: _dynamic_atexit_destructor_for__bot_add_t_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__bot_add_t_command__()
{
  ConCommand::~ConCommand(this: &bot_add_t_command);
}

//------------------------------------------------------------------------------
// Address: 0x104203B0
// Name: _dynamic_atexit_destructor_for__bot_add_ct_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__bot_add_ct_command__()
{
  ConCommand::~ConCommand(this: &bot_add_ct_command);
}

//------------------------------------------------------------------------------
// Address: 0x104203C0
// Name: _dynamic_atexit_destructor_for__bot_kill_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__bot_kill_command__()
{
  ConCommand::~ConCommand(this: &bot_kill_command);
}

//------------------------------------------------------------------------------
// Address: 0x104203D0
// Name: _dynamic_atexit_destructor_for__bot_kick_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__bot_kick_command__()
{
  ConCommand::~ConCommand(this: &bot_kick_command);
}

//------------------------------------------------------------------------------
// Address: 0x104203E0
// Name: _dynamic_atexit_destructor_for__bot_knives_only_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__bot_knives_only_command__()
{
  ConCommand::~ConCommand(this: &bot_knives_only_command);
}

//------------------------------------------------------------------------------
// Address: 0x104203F0
// Name: _dynamic_atexit_destructor_for__bot_pistols_only_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__bot_pistols_only_command__()
{
  ConCommand::~ConCommand(this: &bot_pistols_only_command);
}

//------------------------------------------------------------------------------
// Address: 0x10420400
// Name: _dynamic_atexit_destructor_for__bot_snipers_only_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__bot_snipers_only_command__()
{
  ConCommand::~ConCommand(this: &bot_snipers_only_command);
}

//------------------------------------------------------------------------------
// Address: 0x10420410
// Name: _dynamic_atexit_destructor_for__bot_all_weapons_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__bot_all_weapons_command__()
{
  ConCommand::~ConCommand(this: &bot_all_weapons_command);
}

//------------------------------------------------------------------------------
// Address: 0x10420420
// Name: _dynamic_atexit_destructor_for__bot_goto_mark_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__bot_goto_mark_command__()
{
  ConCommand::~ConCommand(this: &bot_goto_mark_command);
}

//------------------------------------------------------------------------------
// Address: 0x10420430
// Name: _dynamic_atexit_destructor_for__bot_goto_selected_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__bot_goto_selected_command__()
{
  ConCommand::~ConCommand(this: &bot_goto_selected_command);
}

//------------------------------------------------------------------------------
// Address: 0x10420440
// Name: _dynamic_atexit_destructor_for__nav_check_connectivity_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__nav_check_connectivity_command__()
{
  ConCommand::~ConCommand(this: &nav_check_connectivity_command);
}

//------------------------------------------------------------------------------
// Address: 0x10420450
// Name: _dynamic_atexit_destructor_for__bot_loadout__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__bot_loadout__()
{
  ConVar::~ConVar(this: &bot_loadout);
}

//------------------------------------------------------------------------------
// Address: 0x10420460
// Name: _dynamic_atexit_destructor_for__bot_randombuy__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__bot_randombuy__()
{
  ConVar::~ConVar(this: &bot_randombuy);
}

//------------------------------------------------------------------------------
// Address: 0x10420470
// Name: _dynamic_atexit_destructor_for__bot_gungameselect_weapons_t__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__bot_gungameselect_weapons_t__()
{
  ConVar::~ConVar(this: &bot_gungameselect_weapons_t);
}

//------------------------------------------------------------------------------
// Address: 0x10420480
// Name: _dynamic_atexit_destructor_for__bot_gungameselect_weapons_ct__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__bot_gungameselect_weapons_ct__()
{
  ConVar::~ConVar(this: &bot_gungameselect_weapons_ct);
}
