// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/te_impact.cpp
// Functions: 8
// ============================================================

#include "game\server\te_impact.h"

//------------------------------------------------------------------------------
// Address: 0x10332C30
// Name: public: virtual class ServerClass __near * CTEImpact::GetServerClass(void)
// Source: json
//------------------------------------------------------------------------------
ServerClass *__thiscall CTEImpact::GetServerClass(CTEImpact *this)
{
  return &g_CTEImpact_ClassReg;
}

//------------------------------------------------------------------------------
// Address: 0x10417030
// Name: DT_TEImpact::_dynamic_initializer_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
int DT_TEImpact::_dynamic_initializer_for__g_SendTable__()
{
  SendTable::SendTable(this: &DT_TEImpact::g_SendTable);
  return atexit(func: DT_TEImpact::_dynamic_atexit_destructor_for__g_SendTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10417050
// Name: DT_TEImpact::_dynamic_initializer_for__g_SendTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_TEImpact::_dynamic_initializer_for__g_SendTableInit__()
{
  int result; // eax

  result = ServerClassInit<DT_TEImpact::ignored>();
  DT_TEImpact::g_SendTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10422630
// Name: DT_TEImpact::_dynamic_atexit_destructor_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_TEImpact::_dynamic_atexit_destructor_for__g_SendTable__()
{
  CAI_BaseNPC::OnSetSchedule(this: (vgui::Panel *)&DT_TEImpact::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x10417060
// Name: _dynamic_initializer_for__g_TEImpact__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_TEImpact__()
{
  CBaseTempEntity::CBaseTempEntity(this: &g_TEImpact, name: "Impact");
  g_TEImpact.__vftable = (CTEImpact_vtbl *)&CTEImpact::`vftable';
  if ( g_TEImpact.m_vecOrigin.m_Value.x != 0.0
    || g_TEImpact.m_vecOrigin.m_Value.y != 0.0
    || g_TEImpact.m_vecOrigin.m_Value.z != 0.0 )
  {
    g_TEImpact.m_vecOrigin.m_Value.x = 0.0;
    g_TEImpact.m_vecOrigin.m_Value.y = 0.0;
    g_TEImpact.m_vecOrigin.m_Value.z = 0.0;
  }
  if ( g_TEImpact.m_vecNormal.m_Value.x != 0.0
    || g_TEImpact.m_vecNormal.m_Value.y != 0.0
    || g_TEImpact.m_vecNormal.m_Value.z != 0.0 )
  {
    g_TEImpact.m_vecNormal.m_Value.x = 0.0;
    g_TEImpact.m_vecNormal.m_Value.y = 0.0;
    g_TEImpact.m_vecNormal.m_Value.z = 0.0;
  }
  return atexit(func: dynamic_atexit_destructor_for__g_TEImpact__);
}

//------------------------------------------------------------------------------
// Address: 0x10417110
// Name: _dynamic_initializer_for__g_CTEKillPlayerAttachments_ClassReg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ServerClass *dynamic_initializer_for__g_CTEKillPlayerAttachments_ClassReg__()
{
  return ServerClass::ServerClass(
           this: &g_CTEKillPlayerAttachments_ClassReg,
           pNetworkName: "CTEKillPlayerAttachments",
           pTable: &DT_TEKillPlayerAttachments::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x10422640
// Name: _dynamic_atexit_destructor_for__g_TEImpact__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_TEImpact__()
{
  g_TEImpact.__vftable = (CTEImpact_vtbl *)&CTEImpact::`vftable';
  CBaseTempEntity::~CBaseTempEntity(this: &g_TEImpact);
}

//------------------------------------------------------------------------------
// Address: 0x10422660
// Name: _ServerClassInit_DT_TEImpact::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ServerClassInit_DT_TEImpact::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__()
{
  SendProp *v0; // esi
  int i; // edi

  v0 = (SendProp *)&_S2_348;
  for ( i = 4; i >= 0; --i )
    SendProp::~SendProp(this: --v0);
}
