// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/team_objectiveresource.cpp
// Functions: 8
// ============================================================

#include "game\server\team_objectiveresource.h"

//------------------------------------------------------------------------------
// Address: 0x1040AC90
// Name: DT_BaseTeamObjectiveResource::_dynamic_initializer_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
int DT_BaseTeamObjectiveResource::_dynamic_initializer_for__g_SendTable__()
{
  SendTable::SendTable(this: &DT_BaseTeamObjectiveResource::g_SendTable);
  return atexit(func: DT_BaseTeamObjectiveResource::_dynamic_atexit_destructor_for__g_SendTable__);
}

//------------------------------------------------------------------------------
// Address: 0x1040ACB0
// Name: DT_BaseTeamObjectiveResource::_dynamic_initializer_for__g_SendTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_BaseTeamObjectiveResource::_dynamic_initializer_for__g_SendTableInit__()
{
  int result; // eax

  result = ServerClassInit<DT_BaseTeamObjectiveResource::ignored>();
  DT_BaseTeamObjectiveResource::g_SendTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1040ACC0
// Name: CBaseTeamObjectiveResource_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CBaseTeamObjectiveResource_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CBaseTeamObjectiveResource>();
  CBaseTeamObjectiveResource_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1041E450
// Name: DT_BaseTeamObjectiveResource::_dynamic_atexit_destructor_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_BaseTeamObjectiveResource::_dynamic_atexit_destructor_for__g_SendTable__()
{
  CAI_BaseNPC::OnSetSchedule(this: (vgui::Panel *)&DT_BaseTeamObjectiveResource::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x1041E460
// Name: _ServerClassInit_DT_BaseTeamObjectiveResource::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ServerClassInit_DT_BaseTeamObjectiveResource::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__()
{
  SendProp *v0; // esi
  int i; // edi

  v0 = (SendProp *)&_S2_218;
  for ( i = 29; i >= 0; --i )
    SendProp::~SendProp(this: --v0);
}

//------------------------------------------------------------------------------
// Address: 0x1041E480
// Name: _DataMapInit_CBaseTeamObjectiveResource__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CBaseTeamObjectiveResource__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_411);
}

//------------------------------------------------------------------------------
// Address: 0x1041E490
// Name: _DataMapInit_CTeamSpawnPoint__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CTeamSpawnPoint__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_412);
}

//------------------------------------------------------------------------------
// Address: 0x1041E4A0
// Name: _DataMapInit_CTeamVehicleSpawnPoint__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CTeamVehicleSpawnPoint__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_413);
}
