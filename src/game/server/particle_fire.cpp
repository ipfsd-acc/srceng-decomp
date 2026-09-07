// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/particle_fire.cpp
// Functions: 10
// ============================================================

#include "game\server\particle_fire.h"

//------------------------------------------------------------------------------
// Address: 0x103256A0
// Name: public: virtual class ServerClass __near * CParticleFire::GetServerClass(void)
// Source: json
//------------------------------------------------------------------------------
ServerClass *__thiscall CParticleFire::GetServerClass(CParticleFire *this)
{
  return &g_CParticleFire_ClassReg;
}

//------------------------------------------------------------------------------
// Address: 0x103256B0
// Name: private: virtual struct datamap_t __near * CParticleFire::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CParticleFire::GetDataDescMap(CParticleFire *this)
{
  return &CParticleFire::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10415360
// Name: DT_ParticleFire::_dynamic_initializer_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
int DT_ParticleFire::_dynamic_initializer_for__g_SendTable__()
{
  SendTable::SendTable(this: &DT_ParticleFire::g_SendTable);
  return atexit(func: DT_ParticleFire::_dynamic_atexit_destructor_for__g_SendTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10415380
// Name: DT_ParticleFire::_dynamic_initializer_for__g_SendTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_ParticleFire::_dynamic_initializer_for__g_SendTableInit__()
{
  int result; // eax

  result = ServerClassInit<DT_ParticleFire::ignored>();
  DT_ParticleFire::g_SendTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104153B0
// Name: CParticleFire_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CParticleFire_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CParticleFire>();
  CParticleFire_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10421A80
// Name: DT_ParticleFire::_dynamic_atexit_destructor_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_ParticleFire::_dynamic_atexit_destructor_for__g_SendTable__()
{
  CAI_BaseNPC::OnSetSchedule(this: (vgui::Panel *)&DT_ParticleFire::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x10415390
// Name: _dynamic_initializer_for__env_particlefire__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__env_particlefire__()
{
  CEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(CEntityFactoryDictionary *, CEntityFactory<CParticleFire> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &env_particlefire,
           a3: "env_particlefire");
}

//------------------------------------------------------------------------------
// Address: 0x104153C0
// Name: _dynamic_initializer_for__g_ParticleSmokeGrenade_ClassReg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ServerClass *dynamic_initializer_for__g_ParticleSmokeGrenade_ClassReg__()
{
  return ServerClass::ServerClass(
           this: &g_ParticleSmokeGrenade_ClassReg,
           pNetworkName: "ParticleSmokeGrenade",
           pTable: &DT_ParticleSmokeGrenade::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x10421A90
// Name: _ServerClassInit_DT_ParticleFire::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ServerClassInit_DT_ParticleFire::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__()
{
  SendProp *v0; // esi
  int i; // edi

  v0 = (SendProp *)&_S2_314;
  for ( i = 2; i >= 0; --i )
    SendProp::~SendProp(this: --v0);
}

//------------------------------------------------------------------------------
// Address: 0x10421AB0
// Name: _DataMapInit_CParticleFire__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CParticleFire__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_503);
}
