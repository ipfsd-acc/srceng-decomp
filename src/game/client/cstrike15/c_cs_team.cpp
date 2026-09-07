// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/cstrike15/c_cs_team.cpp
// Functions: 7
// ============================================================

#include "game\client\cstrike15\c_cs_team.h"

//------------------------------------------------------------------------------
// Address: 0x101BF2C0
// Name: public: virtual class ClientClass __near * C_CSTeam::GetClientClass(void)
// Source: json
//------------------------------------------------------------------------------
ClientClass *__thiscall C_CSTeam::GetClientClass(C_CSTeam *this)
{
  return &__g_C_CSTeamClientClass;
}

//------------------------------------------------------------------------------
// Address: 0x10422320
// Name: DT_CSTeam::_dynamic_initializer_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
int DT_CSTeam::_dynamic_initializer_for__g_RecvTable__()
{
  RecvTable::RecvTable(this: &DT_CSTeam::g_RecvTable);
  return atexit(func: DT_CSTeam::_dynamic_atexit_destructor_for__g_RecvTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10422340
// Name: DT_CSTeam::_dynamic_initializer_for__g_RecvTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_CSTeam::_dynamic_initializer_for__g_RecvTableInit__()
{
  int result; // eax

  result = ClientClassInit<DT_CSTeam::ignored>();
  DT_CSTeam::g_RecvTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10435300
// Name: DT_CSTeam::_dynamic_atexit_destructor_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_CSTeam::_dynamic_atexit_destructor_for__g_RecvTable__()
{
  C_BaseAnimating::ShutdownBoneSetupThreadPool(this: (vgui::PropertyPage *)&DT_CSTeam::g_RecvTable);
}

//------------------------------------------------------------------------------
// Address: 0x10422350
// Name: _dynamic_initializer_for__cl_c4dynamiclight__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_c4dynamiclight__()
{
  ConVar::ConVar(
    this: &cl_c4dynamiclight,
    pName: "cl_c4dynamiclight",
    pDefaultValue: "0",
    flags: 0,
    pHelpString: "Draw dynamic light when planted c4 flashes");
  return atexit(func: dynamic_atexit_destructor_for__cl_c4dynamiclight__);
}

//------------------------------------------------------------------------------
// Address: 0x10422380
// Name: _dynamic_initializer_for____g_C_PlantedC4ClientClass__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ClientClass *dynamic_initializer_for____g_C_PlantedC4ClientClass__()
{
  ClientClass *result; // eax

  result = g_pClientClassHead;
  __g_C_PlantedC4ClientClass.m_pNext = g_pClientClassHead;
  g_pClientClassHead = &__g_C_PlantedC4ClientClass;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10435310
// Name: _dynamic_atexit_destructor_for__cl_c4dynamiclight__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_c4dynamiclight__()
{
  ConVar::~ConVar(this: &cl_c4dynamiclight);
}
