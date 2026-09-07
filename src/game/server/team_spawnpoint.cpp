// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/team_spawnpoint.cpp
// Functions: 12
// ============================================================

#include "game\server\team_spawnpoint.h"

//------------------------------------------------------------------------------
// Address: 0x102304A0
// Name: protected: virtual struct datamap_t __near * CTeamSpawnPoint::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CTeamSpawnPoint::GetDataDescMap(CTeamSpawnPoint *this)
{
  return &CTeamSpawnPoint::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x102304B0
// Name: public: virtual void CTeamSpawnPoint::Activate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTeamSpawnPoint::Activate(CTeamSpawnPoint *this)
{
  int v2; // eax
  CTeam *GlobalTeam; // eax
  int TeamNumber; // eax

  CBaseEntity::Activate(this);
  if ( CBaseEntity::GetTeamNumber(this) <= 0 || CBaseEntity::GetTeamNumber(this) > 32 )
  {
    TeamNumber = CBaseEntity::GetTeamNumber(this);
    _Warning(a1: "info_player_teamspawn with invalid team number: %d\n", TeamNumber);
    UTIL_Remove(oldObj: this);
  }
  else
  {
    v2 = CBaseEntity::GetTeamNumber(this);
    GlobalTeam = GetGlobalTeam(iIndex: v2);
    GlobalTeam->AddSpawnpoint(this: GlobalTeam, a2: this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10230510
// Name: protected: void CTeamSpawnPoint::InputEnable(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTeamSpawnPoint::InputEnable(CTeamSpawnPoint *this, inputdata_t *inputdata)
{
  this->m_iDisabled = 0;
}

//------------------------------------------------------------------------------
// Address: 0x10230520
// Name: protected: void CTeamSpawnPoint::InputDisable(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTeamSpawnPoint::InputDisable(CTeamSpawnPoint *this, inputdata_t *inputdata)
{
  this->m_iDisabled = 1;
}

//------------------------------------------------------------------------------
// Address: 0x10230530
// Name: public: virtual struct datamap_t __near * CTeamVehicleSpawnPoint::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CTeamVehicleSpawnPoint::GetDataDescMap(CTeamVehicleSpawnPoint *this)
{
  return &CTeamVehicleSpawnPoint::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10230540
// Name: public: virtual void CTeamVehicleSpawnPoint::Activate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTeamVehicleSpawnPoint::Activate(CTeamVehicleSpawnPoint *this)
{
  int TeamNumber; // eax

  CTeamSpawnPoint::Activate(this);
  if ( CBaseEntity::GetTeamNumber(this) <= 0 || CBaseEntity::GetTeamNumber(this) > 32 )
  {
    TeamNumber = CBaseEntity::GetTeamNumber(this);
    _Warning(a1: "info_vehicle_groundspawn with invalid team number: %d\n", TeamNumber);
    UTIL_Remove(oldObj: this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10230580
// Name: public: virtual bool CTeamSpawnPoint::IsValid(class CBasePlayer __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CTeamSpawnPoint::IsValid(CTeamSpawnPoint *this, CBasePlayer *pPlayer)
{
  CBasePlayer *CurrentEntity; // esi
  CEntitySphereQuery sphere; // [esp+10h] [ebp-808h] BYREF
  int savedregs; // [esp+818h] [ebp+0h] BYREF

  if ( (this->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
  CEntitySphereQuery::CEntitySphereQuery(this: &sphere, center: &this->m_vecAbsOrigin, radius: 128.0, flagMask: 0);
  CurrentEntity = (CBasePlayer *)CEntitySphereQuery::GetCurrentEntity(this: &sphere);
  if ( CurrentEntity == nullptr )
    return 1;
  while ( !CurrentEntity->IsPlayer(this: CurrentEntity) || CurrentEntity == pPlayer )
  {
    ++sphere.m_listIndex;
    CurrentEntity = (CBasePlayer *)CEntitySphereQuery::GetCurrentEntity(this: &sphere);
    if ( CurrentEntity == nullptr )
      return 1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1040ACF0
// Name: CTeamSpawnPoint_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CTeamSpawnPoint_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CTeamSpawnPoint>();
  CTeamSpawnPoint_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1040AD20
// Name: CTeamVehicleSpawnPoint_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CTeamVehicleSpawnPoint_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CTeamVehicleSpawnPoint>();
  CTeamVehicleSpawnPoint_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1040AD30
// Name: _dynamic_initializer_for____g_GameRulesRegister_CTeamplayRules__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CGameRulesRegister *dynamic_initializer_for____g_GameRulesRegister_CTeamplayRules__()
{
  return CGameRulesRegister::CGameRulesRegister(
           this: &_g_GameRulesRegister_CTeamplayRules,
           pClassName: "CTeamplayRules",
           fn: __CreateGameRules_CTeamplayRules);
}

//------------------------------------------------------------------------------
// Address: 0x1040AD50
// Name: _dynamic_initializer_for____g_CreateCServerGameTagsIServerGameTags_reg___6
// Source: linker_block_proximity
//------------------------------------------------------------------------------
InterfaceReg *dynamic_initializer_for____g_CreateCServerGameTagsIServerGameTags_reg___6()
{
  return InterfaceReg::InterfaceReg(
           this: &_g_CreateCServerGameTagsIServerGameTags_reg_6,
           fn: (void *(__cdecl *)())_CreateCServerGameTagsIServerGameTags_interface_6,
           pName: "ServerGameTags001");
}

//------------------------------------------------------------------------------
// Address: 0x1040AD70
// Name: _dynamic_initializer_for__g_hControlPointMasters__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_hControlPointMasters__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_hControlPointMasters__);
}
