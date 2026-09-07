// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/movie_explosion.cpp
// Functions: 7
// ============================================================

#include "game\server\movie_explosion.h"

//------------------------------------------------------------------------------
// Address: 0x103255D0
// Name: public: virtual class ServerClass __near * MovieExplosion::GetServerClass(void)
// Source: json
//------------------------------------------------------------------------------
ServerClass *__thiscall MovieExplosion::GetServerClass(MovieExplosion *this)
{
  return &g_MovieExplosion_ClassReg;
}

//------------------------------------------------------------------------------
// Address: 0x104152F0
// Name: DT_MovieExplosion::_dynamic_initializer_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
int DT_MovieExplosion::_dynamic_initializer_for__g_SendTable__()
{
  SendTable::SendTable(this: &DT_MovieExplosion::g_SendTable);
  return atexit(func: DT_MovieExplosion::_dynamic_atexit_destructor_for__g_SendTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10415310
// Name: DT_MovieExplosion::_dynamic_initializer_for__g_SendTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_MovieExplosion::_dynamic_initializer_for__g_SendTableInit__()
{
  int result; // eax

  result = ServerClassInit<DT_MovieExplosion::ignored>();
  DT_MovieExplosion::g_SendTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10421A50
// Name: DT_MovieExplosion::_dynamic_atexit_destructor_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_MovieExplosion::_dynamic_atexit_destructor_for__g_SendTable__()
{
  CAI_BaseNPC::OnSetSchedule(this: (vgui::Panel *)&DT_MovieExplosion::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x10415320
// Name: _dynamic_initializer_for__env_movieexplosion__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__env_movieexplosion__()
{
  CEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(CEntityFactoryDictionary *, CEntityFactory<MovieExplosion> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &env_movieexplosion,
           a3: "env_movieexplosion");
}

//------------------------------------------------------------------------------
// Address: 0x10415340
// Name: _dynamic_initializer_for__g_CParticleFire_ClassReg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ServerClass *dynamic_initializer_for__g_CParticleFire_ClassReg__()
{
  return ServerClass::ServerClass(
           this: &g_CParticleFire_ClassReg,
           pNetworkName: "CParticleFire",
           pTable: &DT_ParticleFire::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x10421A60
// Name: _ServerClassInit_DT_MovieExplosion::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ServerClassInit_DT_MovieExplosion::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__()
{
  SendProp *v0; // esi
  int i; // edi

  v0 = (SendProp *)&_S2_313;
  for ( i = 1; i >= 0; --i )
    SendProp::~SendProp(this: --v0);
}
