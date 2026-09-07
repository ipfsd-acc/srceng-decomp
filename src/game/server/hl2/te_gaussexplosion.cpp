// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/hl2/te_gaussexplosion.cpp
// Functions: 8
// ============================================================

#include "game\server\hl2\te_gaussexplosion.h"

//------------------------------------------------------------------------------
// Address: 0x10331E70
// Name: public: virtual class ServerClass __near * CTEGaussExplosion::GetServerClass(void)
// Source: json
//------------------------------------------------------------------------------
ServerClass *__thiscall CTEGaussExplosion::GetServerClass(CTEGaussExplosion *this)
{
  return &g_CTEGaussExplosion_ClassReg;
}

//------------------------------------------------------------------------------
// Address: 0x10416DC0
// Name: DT_TEGaussExplosion::_dynamic_initializer_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
int DT_TEGaussExplosion::_dynamic_initializer_for__g_SendTable__()
{
  SendTable::SendTable(this: &DT_TEGaussExplosion::g_SendTable);
  return atexit(func: DT_TEGaussExplosion::_dynamic_atexit_destructor_for__g_SendTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10416DE0
// Name: DT_TEGaussExplosion::_dynamic_initializer_for__g_SendTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_TEGaussExplosion::_dynamic_initializer_for__g_SendTableInit__()
{
  int result; // eax

  result = ServerClassInit<DT_TEGaussExplosion::ignored>();
  DT_TEGaussExplosion::g_SendTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10422550
// Name: DT_TEGaussExplosion::_dynamic_atexit_destructor_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_TEGaussExplosion::_dynamic_atexit_destructor_for__g_SendTable__()
{
  CAI_BaseNPC::OnSetSchedule(this: (vgui::Panel *)&DT_TEGaussExplosion::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x10416DF0
// Name: _dynamic_initializer_for__g_TEGaussExplosion__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_TEGaussExplosion__()
{
  CBaseTempEntity::CBaseTempEntity(this: &g_TEGaussExplosion, name: "GaussExplosion");
  g_TEGaussExplosion.m_vecOrigin.m_Value.x = 0.0;
  g_TEGaussExplosion.m_vecOrigin.m_Value.y = 0.0;
  g_TEGaussExplosion.m_vecOrigin.m_Value.z = 0.0;
  g_TEGaussExplosion.__vftable = (CTEGaussExplosion_vtbl *)&CTEGaussExplosion::`vftable';
  if ( g_TEGaussExplosion.m_nType.m_Value != 0 )
    g_TEGaussExplosion.m_nType.m_Value = 0;
  if ( g_TEGaussExplosion.m_vecDirection.m_Value.x != 0.0
    || g_TEGaussExplosion.m_vecDirection.m_Value.y != 0.0
    || g_TEGaussExplosion.m_vecDirection.m_Value.z != 0.0 )
  {
    g_TEGaussExplosion.m_vecDirection.m_Value.x = 0.0;
    g_TEGaussExplosion.m_vecDirection.m_Value.y = 0.0;
    g_TEGaussExplosion.m_vecDirection.m_Value.z = 0.0;
  }
  return atexit(func: dynamic_atexit_destructor_for__g_TEGaussExplosion__);
}

//------------------------------------------------------------------------------
// Address: 0x10416E90
// Name: _dynamic_initializer_for__g_CTEShatterSurface_ClassReg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ServerClass *dynamic_initializer_for__g_CTEShatterSurface_ClassReg__()
{
  return ServerClass::ServerClass(
           this: &g_CTEShatterSurface_ClassReg,
           pNetworkName: "CTEShatterSurface",
           pTable: &DT_TEShatterSurface::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x10422560
// Name: _dynamic_atexit_destructor_for__g_TEGaussExplosion__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_TEGaussExplosion__()
{
  g_TEGaussExplosion.__vftable = (CTEGaussExplosion_vtbl *)&CTEGaussExplosion::`vftable';
  CBaseTempEntity::~CBaseTempEntity(this: &g_TEGaussExplosion);
}

//------------------------------------------------------------------------------
// Address: 0x10422580
// Name: _ServerClassInit_DT_TEGaussExplosion::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ServerClassInit_DT_TEGaussExplosion::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__()
{
  SendProp *v0; // esi
  int i; // edi

  v0 = (SendProp *)&_S2_345;
  for ( i = 3; i >= 0; --i )
    SendProp::~SendProp(this: --v0);
}
