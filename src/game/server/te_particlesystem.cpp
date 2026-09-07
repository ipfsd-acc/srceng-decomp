// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/te_particlesystem.cpp
// Functions: 5
// ============================================================

#include "game\server\te_particlesystem.h"

//------------------------------------------------------------------------------
// Address: 0x104173A0
// Name: DT_TEParticleSystem::_dynamic_initializer_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
int DT_TEParticleSystem::_dynamic_initializer_for__g_SendTable__()
{
  SendTable::SendTable(this: &DT_TEParticleSystem::g_SendTable);
  return atexit(func: DT_TEParticleSystem::_dynamic_atexit_destructor_for__g_SendTable__);
}

//------------------------------------------------------------------------------
// Address: 0x104173C0
// Name: DT_TEParticleSystem::_dynamic_initializer_for__g_SendTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_TEParticleSystem::_dynamic_initializer_for__g_SendTableInit__()
{
  int result; // eax

  result = ServerClassInit<DT_TEParticleSystem::ignored>();
  DT_TEParticleSystem::g_SendTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10422770
// Name: DT_TEParticleSystem::_dynamic_atexit_destructor_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_TEParticleSystem::_dynamic_atexit_destructor_for__g_SendTable__()
{
  CAI_BaseNPC::OnSetSchedule(this: (vgui::Panel *)&DT_TEParticleSystem::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x104173D0
// Name: _dynamic_initializer_for__g_CTEPhysicsProp_ClassReg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ServerClass *dynamic_initializer_for__g_CTEPhysicsProp_ClassReg__()
{
  return ServerClass::ServerClass(
           this: &g_CTEPhysicsProp_ClassReg,
           pNetworkName: "CTEPhysicsProp",
           pTable: &DT_TEPhysicsProp::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x10422780
// Name: _ServerClassInit_DT_TEParticleSystem::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ServerClassInit_DT_TEParticleSystem::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__()
{
  SendProp *v0; // esi
  int i; // edi

  v0 = (SendProp *)&_S2_352;
  for ( i = 4; i >= 0; --i )
    SendProp::~SendProp(this: --v0);
}
