// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/cstrike15/cs_team.cpp
// Functions: 13
// ============================================================

#include "game\server\cstrike15\cs_team.h"

//------------------------------------------------------------------------------
// Address: 0x10297DC0
// Name: public: virtual class ServerClass __near * CCSTeam::GetServerClass(void)
// Source: json
//------------------------------------------------------------------------------
ServerClass *__thiscall CCSTeam::GetServerClass(CCSTeam *this)
{
  return &g_CCSTeam_ClassReg;
}

//------------------------------------------------------------------------------
// Address: 0x10297E00
// Name: public: virtual void CCSTeam::AddPlayer(class CBasePlayer __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSTeam::AddPlayer(CCSTeam *this, CBasePlayer *pPlayer)
{
  CTeam::AddPlayer(this, pPlayer);
}

//------------------------------------------------------------------------------
// Address: 0x10297E10
// Name: public: virtual void CCSTeam::RemovePlayer(class CBasePlayer __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSTeam::RemovePlayer(CCSTeam *this, CBasePlayer *pPlayer)
{
  CTeam::RemovePlayer(this, pPlayer);
}

//------------------------------------------------------------------------------
// Address: 0x10297E20
// Name: public: virtual void CCSTeam::Init(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSTeam::Init(CCSTeam *this, const char *pName, int iNumber)
{
  CTeam::Init(this, pName, iNumber);
  CServerNetworkProperty::SetUpdateInterval(this: &this->m_Network, val: (CEventRegister *)0x3F400000);
}

//------------------------------------------------------------------------------
// Address: 0x1040F420
// Name: DT_CSTeam::_dynamic_initializer_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
int DT_CSTeam::_dynamic_initializer_for__g_SendTable__()
{
  SendTable::SendTable(this: &DT_CSTeam::g_SendTable);
  return atexit(func: DT_CSTeam::_dynamic_atexit_destructor_for__g_SendTable__);
}

//------------------------------------------------------------------------------
// Address: 0x1040F440
// Name: DT_CSTeam::_dynamic_initializer_for__g_SendTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_CSTeam::_dynamic_initializer_for__g_SendTableInit__()
{
  int result; // eax

  result = ServerClassInit<DT_CSTeam::ignored>();
  DT_CSTeam::g_SendTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1041FE30
// Name: DT_CSTeam::_dynamic_atexit_destructor_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_CSTeam::_dynamic_atexit_destructor_for__g_SendTable__()
{
  CAI_BaseNPC::OnSetSchedule(this: (vgui::Panel *)&DT_CSTeam::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x1040F450
// Name: _dynamic_initializer_for__cs_team_manager__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cs_team_manager__()
{
  CEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(CEntityFactoryDictionary *, CEntityFactory<CCSTeam> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &cs_team_manager,
           a3: "cs_team_manager");
}

//------------------------------------------------------------------------------
// Address: 0x1040F470
// Name: _dynamic_initializer_for__hud_jeephint_numentries__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__hud_jeephint_numentries__()
{
  ConVar::ConVar(this: &hud_jeephint_numentries, pName: "hud_jeephint_numentries", pDefaultValue: "10", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__hud_jeephint_numentries__);
}

//------------------------------------------------------------------------------
// Address: 0x1040F4A0
// Name: _dynamic_initializer_for__g_jeepexitspeed__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_jeepexitspeed__()
{
  ConVar::ConVar(this: &g_jeepexitspeed, pName: "g_jeepexitspeed", pDefaultValue: "100", flags: 0x4000);
  return atexit(func: dynamic_atexit_destructor_for__g_jeepexitspeed__);
}

//------------------------------------------------------------------------------
// Address: 0x1041FE40
// Name: _ServerClassInit_DT_CSTeam::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ServerClassInit_DT_CSTeam::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__()
{
  SendProp *v0; // esi
  int i; // edi

  v0 = (SendProp *)&_S2_246;
  for ( i = 1; i >= 0; --i )
    SendProp::~SendProp(this: --v0);
}

//------------------------------------------------------------------------------
// Address: 0x1041FE60
// Name: _dynamic_atexit_destructor_for__hud_jeephint_numentries__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__hud_jeephint_numentries__()
{
  ConVar::~ConVar(this: &hud_jeephint_numentries);
}

//------------------------------------------------------------------------------
// Address: 0x1041FE70
// Name: _dynamic_atexit_destructor_for__g_jeepexitspeed__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_jeepexitspeed__()
{
  ConVar::~ConVar(this: &g_jeepexitspeed);
}
