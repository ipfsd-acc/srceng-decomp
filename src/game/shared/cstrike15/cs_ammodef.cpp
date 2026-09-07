// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/shared/cstrike15/cs_ammodef.cpp
// Functions: 98
// ============================================================

#include "game\shared\cstrike15\cs_ammodef.h"

//------------------------------------------------------------------------------
// Address: 0x101C29F0
// Name: public: void CCSAmmoDef::AddAmmoCost(char const __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSAmmoDef::AddAmmoCost(CCSAmmoDef *this, const char *name, int cost, int buySize)
{
  int v5; // eax

  v5 = CAmmoDef::Index(this, psz: name);
  if ( v5 >= 1 && v5 < this->m_nAmmoIndex )
  {
    this->m_csAmmo[v5].buySize = buySize;
    this->m_csAmmo[v5].cost = cost;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101C2A30
// Name: public: int CCSAmmoDef::GetBuySize(int)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CCSAmmoDef::GetBuySize(CCSAmmoDef *this, int index)
{
  if ( index < 1 || index >= this->m_nAmmoIndex )
    return 0;
  else
    return this->m_csAmmo[index].buySize;
}

//------------------------------------------------------------------------------
// Address: 0x101C2A60
// Name: public: int CCSAmmoDef::GetCost(int)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CCSAmmoDef::GetCost(CCSAmmoDef *this, int index)
{
  if ( index < 1 || index >= this->m_nAmmoIndex )
    return 0;
  else
    return this->m_csAmmo[index].cost;
}

//------------------------------------------------------------------------------
// Address: 0x101C2A90
// Name: public: CCSAmmoDef::CCSAmmoDef(void)
// Source: json
//------------------------------------------------------------------------------
CCSAmmoDef *__thiscall CCSAmmoDef::CCSAmmoDef(CCSAmmoDef *this)
{
  CAmmoDef::CAmmoDef(this);
  this->__vftable = (CCSAmmoDef_vtbl *)&CCSAmmoDef::`vftable';
  memset(dst: (int)this->m_csAmmo, value: nullptr, count: sizeof(this->m_csAmmo));
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101C2AC0
// Name: public: virtual CCSAmmoDef::~CCSAmmoDef(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSAmmoDef::~CCSAmmoDef(CCSAmmoDef *this)
{
  this->__vftable = (CCSAmmoDef_vtbl *)&CCSAmmoDef::`vftable';
  CAmmoDef::~CAmmoDef(this);
}

//------------------------------------------------------------------------------
// Address: 0x10422950
// Name: _dynamic_initializer_for__ammo_50AE_max__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__ammo_50AE_max__()
{
  ConVar::ConVar(this: &ammo_50AE_max, pName: "ammo_50AE_max", pDefaultValue: "35", flags: 0x2000);
  return atexit(func: dynamic_atexit_destructor_for__ammo_50AE_max__);
}

//------------------------------------------------------------------------------
// Address: 0x10422980
// Name: _dynamic_initializer_for__ammo_762mm_max__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__ammo_762mm_max__()
{
  ConVar::ConVar(this: &ammo_762mm_max, pName: "ammo_762mm_max", pDefaultValue: "90", flags: 0x2000);
  return atexit(func: dynamic_atexit_destructor_for__ammo_762mm_max__);
}

//------------------------------------------------------------------------------
// Address: 0x104229B0
// Name: _dynamic_initializer_for__ammo_556mm_max__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__ammo_556mm_max__()
{
  ConVar::ConVar(this: &ammo_556mm_max, pName: "ammo_556mm_max", pDefaultValue: "90", flags: 0x2000);
  return atexit(func: dynamic_atexit_destructor_for__ammo_556mm_max__);
}

//------------------------------------------------------------------------------
// Address: 0x104229E0
// Name: _dynamic_initializer_for__ammo_556mm_box_max__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__ammo_556mm_box_max__()
{
  ConVar::ConVar(this: &ammo_556mm_box_max, pName: "ammo_556mm_box_max", pDefaultValue: "200", flags: 0x2000);
  return atexit(func: dynamic_atexit_destructor_for__ammo_556mm_box_max__);
}

//------------------------------------------------------------------------------
// Address: 0x10422A10
// Name: _dynamic_initializer_for__ammo_338mag_max__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__ammo_338mag_max__()
{
  ConVar::ConVar(this: &ammo_338mag_max, pName: "ammo_338mag_max", pDefaultValue: "30", flags: 0x2000);
  return atexit(func: dynamic_atexit_destructor_for__ammo_338mag_max__);
}

//------------------------------------------------------------------------------
// Address: 0x10422A40
// Name: _dynamic_initializer_for__ammo_9mm_max__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__ammo_9mm_max__()
{
  ConVar::ConVar(this: &ammo_9mm_max, pName: "ammo_9mm_max", pDefaultValue: "120", flags: 0x2000);
  return atexit(func: dynamic_atexit_destructor_for__ammo_9mm_max__);
}

//------------------------------------------------------------------------------
// Address: 0x10422A70
// Name: _dynamic_initializer_for__ammo_buckshot_max__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__ammo_buckshot_max__()
{
  ConVar::ConVar(this: &ammo_buckshot_max, pName: "ammo_buckshot_max", pDefaultValue: "32", flags: 0x2000);
  return atexit(func: dynamic_atexit_destructor_for__ammo_buckshot_max__);
}

//------------------------------------------------------------------------------
// Address: 0x10422AA0
// Name: _dynamic_initializer_for__ammo_45acp_max__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__ammo_45acp_max__()
{
  ConVar::ConVar(this: &ammo_45acp_max, pName: "ammo_45acp_max", pDefaultValue: "100", flags: 0x2000);
  return atexit(func: dynamic_atexit_destructor_for__ammo_45acp_max__);
}

//------------------------------------------------------------------------------
// Address: 0x10422AD0
// Name: _dynamic_initializer_for__ammo_357sig_max__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__ammo_357sig_max__()
{
  ConVar::ConVar(this: &ammo_357sig_max, pName: "ammo_357sig_max", pDefaultValue: "52", flags: 0x2000);
  return atexit(func: dynamic_atexit_destructor_for__ammo_357sig_max__);
}

//------------------------------------------------------------------------------
// Address: 0x10422B00
// Name: _dynamic_initializer_for__ammo_57mm_max__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__ammo_57mm_max__()
{
  ConVar::ConVar(this: &ammo_57mm_max, pName: "ammo_57mm_max", pDefaultValue: "100", flags: 0x2000);
  return atexit(func: dynamic_atexit_destructor_for__ammo_57mm_max__);
}

//------------------------------------------------------------------------------
// Address: 0x10422B30
// Name: _dynamic_initializer_for__ammo_hegrenade_max__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__ammo_hegrenade_max__()
{
  ConVar::ConVar(this: &ammo_hegrenade_max, pName: "ammo_hegrenade_max", pDefaultValue: "1", flags: 0x2000);
  return atexit(func: dynamic_atexit_destructor_for__ammo_hegrenade_max__);
}

//------------------------------------------------------------------------------
// Address: 0x10422B60
// Name: _dynamic_initializer_for__ammo_flashbang_max__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__ammo_flashbang_max__()
{
  ConVar::ConVar(this: &ammo_flashbang_max, pName: "ammo_flashbang_max", pDefaultValue: "2", flags: 0x2000);
  return atexit(func: dynamic_atexit_destructor_for__ammo_flashbang_max__);
}

//------------------------------------------------------------------------------
// Address: 0x10422B90
// Name: _dynamic_initializer_for__ammo_smokegrenade_max__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__ammo_smokegrenade_max__()
{
  ConVar::ConVar(this: &ammo_smokegrenade_max, pName: "ammo_smokegrenade_max", pDefaultValue: "1", flags: 0x2000);
  return atexit(func: dynamic_atexit_destructor_for__ammo_smokegrenade_max__);
}

//------------------------------------------------------------------------------
// Address: 0x10422BC0
// Name: _dynamic_initializer_for__ammo_molotov_max__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__ammo_molotov_max__()
{
  ConVar::ConVar(this: &ammo_molotov_max, pName: "ammo_molotov_max", pDefaultValue: "1", flags: 0x2000);
  return atexit(func: dynamic_atexit_destructor_for__ammo_molotov_max__);
}

//------------------------------------------------------------------------------
// Address: 0x10422BF0
// Name: _dynamic_initializer_for__ammo_decoy_max__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__ammo_decoy_max__()
{
  ConVar::ConVar(this: &ammo_decoy_max, pName: "ammo_decoy_max", pDefaultValue: "1", flags: 0x2000);
  return atexit(func: dynamic_atexit_destructor_for__ammo_decoy_max__);
}

//------------------------------------------------------------------------------
// Address: 0x10423400
// Name: _dynamic_initializer_for__ammoDef__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__ammoDef__()
{
  CCSAmmoDef::CCSAmmoDef(this: &ammoDef);
  return atexit(func: dynamic_atexit_destructor_for__ammoDef__);
}

//------------------------------------------------------------------------------
// Address: 0x10435500
// Name: _dynamic_atexit_destructor_for__ammo_50AE_max__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__ammo_50AE_max__()
{
  ConVar::~ConVar(this: &ammo_50AE_max);
}

//------------------------------------------------------------------------------
// Address: 0x10435510
// Name: _dynamic_atexit_destructor_for__ammo_762mm_max__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__ammo_762mm_max__()
{
  ConVar::~ConVar(this: &ammo_762mm_max);
}

//------------------------------------------------------------------------------
// Address: 0x10435520
// Name: _dynamic_atexit_destructor_for__ammo_556mm_max__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__ammo_556mm_max__()
{
  ConVar::~ConVar(this: &ammo_556mm_max);
}

//------------------------------------------------------------------------------
// Address: 0x10435530
// Name: _dynamic_atexit_destructor_for__ammo_556mm_box_max__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__ammo_556mm_box_max__()
{
  ConVar::~ConVar(this: &ammo_556mm_box_max);
}

//------------------------------------------------------------------------------
// Address: 0x10435540
// Name: _dynamic_atexit_destructor_for__ammo_338mag_max__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__ammo_338mag_max__()
{
  ConVar::~ConVar(this: &ammo_338mag_max);
}

//------------------------------------------------------------------------------
// Address: 0x10435550
// Name: _dynamic_atexit_destructor_for__ammo_9mm_max__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__ammo_9mm_max__()
{
  ConVar::~ConVar(this: &ammo_9mm_max);
}

//------------------------------------------------------------------------------
// Address: 0x10435560
// Name: _dynamic_atexit_destructor_for__ammo_buckshot_max__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__ammo_buckshot_max__()
{
  ConVar::~ConVar(this: &ammo_buckshot_max);
}

//------------------------------------------------------------------------------
// Address: 0x10435570
// Name: _dynamic_atexit_destructor_for__ammo_45acp_max__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__ammo_45acp_max__()
{
  ConVar::~ConVar(this: &ammo_45acp_max);
}

//------------------------------------------------------------------------------
// Address: 0x10435580
// Name: _dynamic_atexit_destructor_for__ammo_357sig_max__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__ammo_357sig_max__()
{
  ConVar::~ConVar(this: &ammo_357sig_max);
}

//------------------------------------------------------------------------------
// Address: 0x10435590
// Name: _dynamic_atexit_destructor_for__ammo_57mm_max__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__ammo_57mm_max__()
{
  ConVar::~ConVar(this: &ammo_57mm_max);
}

//------------------------------------------------------------------------------
// Address: 0x104355A0
// Name: _dynamic_atexit_destructor_for__ammo_hegrenade_max__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__ammo_hegrenade_max__()
{
  ConVar::~ConVar(this: &ammo_hegrenade_max);
}

//------------------------------------------------------------------------------
// Address: 0x104355B0
// Name: _dynamic_atexit_destructor_for__ammo_flashbang_max__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__ammo_flashbang_max__()
{
  ConVar::~ConVar(this: &ammo_flashbang_max);
}

//------------------------------------------------------------------------------
// Address: 0x104355C0
// Name: _dynamic_atexit_destructor_for__ammo_smokegrenade_max__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__ammo_smokegrenade_max__()
{
  ConVar::~ConVar(this: &ammo_smokegrenade_max);
}

//------------------------------------------------------------------------------
// Address: 0x104355D0
// Name: _dynamic_atexit_destructor_for__ammo_molotov_max__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__ammo_molotov_max__()
{
  ConVar::~ConVar(this: &ammo_molotov_max);
}

//------------------------------------------------------------------------------
// Address: 0x104355E0
// Name: _dynamic_atexit_destructor_for__ammo_decoy_max__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__ammo_decoy_max__()
{
  ConVar::~ConVar(this: &ammo_decoy_max);
}

//------------------------------------------------------------------------------
// Address: 0x104357A0
// Name: _dynamic_atexit_destructor_for__ammoDef__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__ammoDef__()
{
  CCSAmmoDef::~CCSAmmoDef(this: &ammoDef);
}

//------------------------------------------------------------------------------
// Address: 0x10422C20
// Name: _dynamic_initializer_for__mp_buytime__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mp_buytime__()
{
  ConVar::ConVar(
    this: &mp_buytime,
    pName: "mp_buytime",
    pDefaultValue: "90",
    flags: 0x2000,
    pHelpString: "How many seconds after round start players can buy items for.",
    bMin: true,
    fMin: 0.0,
    bMax: false,
    fMax: 0.0);
  return atexit(func: dynamic_atexit_destructor_for__mp_buytime__);
}

//------------------------------------------------------------------------------
// Address: 0x10422C60
// Name: _dynamic_initializer_for__mp_gungameimmunitytime__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mp_gungameimmunitytime__()
{
  ConVar::ConVar(
    this: &mp_gungameimmunitytime,
    pName: "mp_gungameimmunitytime",
    pDefaultValue: "4.0",
    flags: 0x2000,
    pHelpString: "How many seconds after respawn immunity lasts.");
  return atexit(func: dynamic_atexit_destructor_for__mp_gungameimmunitytime__);
}

//------------------------------------------------------------------------------
// Address: 0x10422C90
// Name: _dynamic_initializer_for__mp_playerid__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mp_playerid__()
{
  ConVar::ConVar(
    this: &mp_playerid,
    pName: "mp_playerid",
    pDefaultValue: "0",
    flags: 0x2000,
    pHelpString: "Controls what information player see in the status bar: 0 all names; 1 team names; 2 no names",
    bMin: true,
    fMin: 0.0,
    bMax: true,
    fMax: 2.0);
  return atexit(func: dynamic_atexit_destructor_for__mp_playerid__);
}

//------------------------------------------------------------------------------
// Address: 0x10422CE0
// Name: _dynamic_initializer_for__mp_playerid_delay__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mp_playerid_delay__()
{
  ConVar::ConVar(
    this: &mp_playerid_delay,
    pName: "mp_playerid_delay",
    pDefaultValue: "0.5",
    flags: 0x2000,
    pHelpString: "Number of seconds to delay showing information in the status bar",
    bMin: true,
    fMin: 0.0,
    bMax: true,
    fMax: 1.0);
  return atexit(func: dynamic_atexit_destructor_for__mp_playerid_delay__);
}

//------------------------------------------------------------------------------
// Address: 0x10422D30
// Name: _dynamic_initializer_for__mp_playerid_hold__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mp_playerid_hold__()
{
  ConVar::ConVar(
    this: &mp_playerid_hold,
    pName: "mp_playerid_hold",
    pDefaultValue: "0.25",
    flags: 0x2000,
    pHelpString: "Number of seconds to keep showing old information in the status bar",
    bMin: true,
    fMin: 0.0,
    bMax: true,
    fMax: 1.0);
  return atexit(func: dynamic_atexit_destructor_for__mp_playerid_hold__);
}

//------------------------------------------------------------------------------
// Address: 0x10422D80
// Name: _dynamic_initializer_for__mp_round_restart_delay__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mp_round_restart_delay__()
{
  ConVar::ConVar(
    this: &mp_round_restart_delay,
    pName: "mp_round_restart_delay",
    pDefaultValue: "7.0",
    flags: 0x2000,
    pHelpString: "Number of seconds to delay before restarting a round after a win",
    bMin: true,
    fMin: 0.0,
    bMax: true,
    fMax: 10.0);
  return atexit(func: dynamic_atexit_destructor_for__mp_round_restart_delay__);
}

//------------------------------------------------------------------------------
// Address: 0x10422DD0
// Name: _dynamic_initializer_for__mp_ggprogressive_round_restart_delay__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mp_ggprogressive_round_restart_delay__()
{
  ConVar::ConVar(
    this: &mp_ggprogressive_round_restart_delay,
    pName: "mp_ggprogressive_round_restart_delay",
    pDefaultValue: "15.0",
    flags: 0x2000,
    pHelpString: "Number of seconds to delay before restarting a round after a win in gungame progessive",
    bMin: true,
    fMin: 0.0,
    bMax: true,
    fMax: 90.0);
  return atexit(func: dynamic_atexit_destructor_for__mp_ggprogressive_round_restart_delay__);
}

//------------------------------------------------------------------------------
// Address: 0x10422E20
// Name: _dynamic_initializer_for__mp_ggprogressive_win_panel_pct__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mp_ggprogressive_win_panel_pct__()
{
  ConVar::ConVar(
    this: &mp_ggprogressive_win_panel_pct,
    pName: "mp_ggprogressive_win_panel_pct",
    pDefaultValue: "0.33333",
    flags: 0x2000,
    pHelpString: "The percentage of time the win panel is shown between gg progressive rounds (the rest goes to the scoreboard)",
    bMin: true,
    fMin: 0.0,
    bMax: true,
    fMax: 1.0);
  return atexit(func: dynamic_atexit_destructor_for__mp_ggprogressive_win_panel_pct__);
}

//------------------------------------------------------------------------------
// Address: 0x10422E70
// Name: _dynamic_initializer_for__mp_ggselect_match_bestof_win__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mp_ggselect_match_bestof_win__()
{
  ConVar::ConVar(
    this: &mp_ggselect_match_bestof_win,
    pName: "mp_ggselect_match_bestof_win",
    pDefaultValue: "1.0",
    flags: 0x2000,
    pHelpString: "Match ends when one team wins the majority stake of this number of rounds",
    bMin: true,
    fMin: 1.0,
    bMax: true,
    fMax: 64.0);
  return atexit(func: dynamic_atexit_destructor_for__mp_ggselect_match_bestof_win__);
}

//------------------------------------------------------------------------------
// Address: 0x10422EC0
// Name: _dynamic_initializer_for__mp_ggtr_bomb_pts_for_upgrade__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mp_ggtr_bomb_pts_for_upgrade__()
{
  ConVar::ConVar(
    this: &mp_ggtr_bomb_pts_for_upgrade,
    pName: "mp_ggtr_bomb_pts_for_upgrade",
    pDefaultValue: "2.0",
    flags: 0x2000,
    pHelpString: "Kill points required to upgrade a player's weapon",
    bMin: true,
    fMin: 1.0,
    bMax: true,
    fMax: 10.0);
  return atexit(func: dynamic_atexit_destructor_for__mp_ggtr_bomb_pts_for_upgrade__);
}

//------------------------------------------------------------------------------
// Address: 0x10422F10
// Name: _dynamic_initializer_for__mp_ggtr_bomb_pts_for_he__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mp_ggtr_bomb_pts_for_he__()
{
  ConVar::ConVar(
    this: &mp_ggtr_bomb_pts_for_he,
    pName: "mp_ggtr_bomb_pts_for_he",
    pDefaultValue: "3",
    flags: 0x2000,
    pHelpString: "Kill points required in a round to get a bonus HE grenade",
    bMin: true,
    fMin: 1.0,
    bMax: true,
    fMax: 5.0);
  return atexit(func: dynamic_atexit_destructor_for__mp_ggtr_bomb_pts_for_he__);
}

//------------------------------------------------------------------------------
// Address: 0x10422F60
// Name: _dynamic_initializer_for__mp_ggtr_bomb_pts_for_flash__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mp_ggtr_bomb_pts_for_flash__()
{
  ConVar::ConVar(
    this: &mp_ggtr_bomb_pts_for_flash,
    pName: "mp_ggtr_bomb_pts_for_flash",
    pDefaultValue: "4",
    flags: 0x2000,
    pHelpString: "Kill points required in a round to get a bonus flash grenade",
    bMin: true,
    fMin: 1.0,
    bMax: true,
    fMax: 5.0);
  return atexit(func: dynamic_atexit_destructor_for__mp_ggtr_bomb_pts_for_flash__);
}

//------------------------------------------------------------------------------
// Address: 0x10422FB0
// Name: _dynamic_initializer_for__mp_ggtr_bomb_pts_for_molotov__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mp_ggtr_bomb_pts_for_molotov__()
{
  ConVar::ConVar(
    this: &mp_ggtr_bomb_pts_for_molotov,
    pName: "mp_ggtr_bomb_pts_for_molotov",
    pDefaultValue: "5",
    flags: 0x2000,
    pHelpString: "Kill points required in a round to get a bonus molotov cocktail",
    bMin: true,
    fMin: 1.0,
    bMax: true,
    fMax: 5.0);
  return atexit(func: dynamic_atexit_destructor_for__mp_ggtr_bomb_pts_for_molotov__);
}

//------------------------------------------------------------------------------
// Address: 0x10423000
// Name: _dynamic_initializer_for__mp_molotovusedelay__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mp_molotovusedelay__()
{
  ConVar::ConVar(
    this: &mp_molotovusedelay,
    pName: "mp_molotovusedelay",
    pDefaultValue: "15.0",
    flags: 0x2000,
    pHelpString: "Number of seconds to delay before the molotov can be used after acquiring it",
    bMin: true,
    fMin: 0.0,
    bMax: true,
    fMax: 30.0);
  return atexit(func: dynamic_atexit_destructor_for__mp_molotovusedelay__);
}

//------------------------------------------------------------------------------
// Address: 0x10423050
// Name: _dynamic_initializer_for__mp_ggtr_halftime_delay__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mp_ggtr_halftime_delay__()
{
  ConVar::ConVar(
    this: &mp_ggtr_halftime_delay,
    pName: "mp_ggtr_halftime_delay",
    pDefaultValue: "0.0",
    flags: 0x2000,
    pHelpString: "Number of seconds to delay during TR Mode halftime",
    bMin: true,
    fMin: 0.0,
    bMax: true,
    fMax: 30.0);
  return atexit(func: dynamic_atexit_destructor_for__mp_ggtr_halftime_delay__);
}

//------------------------------------------------------------------------------
// Address: 0x104230A0
// Name: _dynamic_initializer_for__mp_ggtr_bomb_respawn_delay__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mp_ggtr_bomb_respawn_delay__()
{
  ConVar::ConVar(
    this: &mp_ggtr_bomb_respawn_delay,
    pName: "mp_ggtr_bomb_respawn_delay",
    pDefaultValue: "0.0",
    flags: 0x2000,
    pHelpString: "Number of seconds to delay before making the bomb available to a respawner in gun game",
    bMin: true,
    fMin: 0.0,
    bMax: true,
    fMax: 30.0);
  return atexit(func: dynamic_atexit_destructor_for__mp_ggtr_bomb_respawn_delay__);
}

//------------------------------------------------------------------------------
// Address: 0x104230F0
// Name: _dynamic_initializer_for__mp_ggtr_bomb_defuse_bonus__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mp_ggtr_bomb_defuse_bonus__()
{
  ConVar::ConVar(
    this: &mp_ggtr_bomb_defuse_bonus,
    pName: "mp_ggtr_bomb_defuse_bonus",
    pDefaultValue: "1.0",
    flags: 0x2000,
    pHelpString: "Number of bonus upgrades to award the CTs when they defuse a gun game bomb",
    bMin: true,
    fMin: 1.0,
    bMax: true,
    fMax: 10.0);
  return atexit(func: dynamic_atexit_destructor_for__mp_ggtr_bomb_defuse_bonus__);
}

//------------------------------------------------------------------------------
// Address: 0x10423140
// Name: _dynamic_initializer_for__mp_ggtr_bomb_detonation_bonus__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mp_ggtr_bomb_detonation_bonus__()
{
  ConVar::ConVar(
    this: &mp_ggtr_bomb_detonation_bonus,
    pName: "mp_ggtr_bomb_detonation_bonus",
    pDefaultValue: "1.0",
    flags: 0x2000,
    pHelpString: "Number of bonus upgrades to award the Ts when they detonate a gun game bomb",
    bMin: true,
    fMin: 1.0,
    bMax: true,
    fMax: 10.0);
  return atexit(func: dynamic_atexit_destructor_for__mp_ggtr_bomb_detonation_bonus__);
}

//------------------------------------------------------------------------------
// Address: 0x10423190
// Name: _dynamic_initializer_for__mp_ggtr_rounds_per_half__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mp_ggtr_rounds_per_half__()
{
  ConVar::ConVar(
    this: &mp_ggtr_rounds_per_half,
    pName: "mp_ggtr_rounds_per_half",
    pDefaultValue: "5",
    flags: 0x2000,
    pHelpString: "Number of rounds to play in one half for gun game tr mode",
    bMin: true,
    fMin: 1.0,
    bMax: true,
    fMax: 10.0);
  return atexit(func: dynamic_atexit_destructor_for__mp_ggtr_rounds_per_half__);
}

//------------------------------------------------------------------------------
// Address: 0x104231E0
// Name: _dynamic_initializer_for__mp_match_end_restart__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mp_match_end_restart__()
{
  ConVar::ConVar(
    this: &mp_match_end_restart,
    pName: "mp_match_end_restart",
    pDefaultValue: "1",
    flags: 0x2000,
    pHelpString: "At the end of the match, perform a restart instead of loading a new map",
    bMin: true,
    fMin: 0.0,
    bMax: true,
    fMax: 1.0);
  return atexit(func: dynamic_atexit_destructor_for__mp_match_end_restart__);
}

//------------------------------------------------------------------------------
// Address: 0x10423230
// Name: _dynamic_initializer_for__mp_defuser_allocation__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mp_defuser_allocation__()
{
  ConVar::ConVar(
    this: &mp_defuser_allocation,
    pName: "mp_defuser_allocation",
    pDefaultValue: "0",
    flags: 0x2000,
    pHelpString: "How to allocate defusers to CTs at start or round: 0=none, 1=random, 2=everyone",
    bMin: true,
    fMin: 0.0,
    bMax: true,
    fMax: 2.0);
  return atexit(func: dynamic_atexit_destructor_for__mp_defuser_allocation__);
}

//------------------------------------------------------------------------------
// Address: 0x10423280
// Name: _dynamic_initializer_for__mp_death_drop_gun__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mp_death_drop_gun__()
{
  ConVar::ConVar(
    this: &mp_death_drop_gun,
    pName: "mp_death_drop_gun",
    pDefaultValue: "1",
    flags: 0x2000,
    pHelpString: "Which gun to drop on player death: 0=none, 1=best, 2=current or best",
    bMin: true,
    fMin: 0.0,
    bMax: true,
    fMax: 2.0);
  return atexit(func: dynamic_atexit_destructor_for__mp_death_drop_gun__);
}

//------------------------------------------------------------------------------
// Address: 0x104232D0
// Name: _dynamic_initializer_for__mp_death_drop_grenade__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mp_death_drop_grenade__()
{
  ConVar::ConVar(
    this: &mp_death_drop_grenade,
    pName: "mp_death_drop_grenade",
    pDefaultValue: "2",
    flags: 0x2000,
    pHelpString: "Which grenade to drop on player death: 0=none, 1=best, 2=current or best",
    bMin: true,
    fMin: 0.0,
    bMax: true,
    fMax: 2.0);
  return atexit(func: dynamic_atexit_destructor_for__mp_death_drop_grenade__);
}

//------------------------------------------------------------------------------
// Address: 0x10423320
// Name: _dynamic_initializer_for__mp_death_drop_defuser__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mp_death_drop_defuser__()
{
  ConVar::ConVar(
    this: &mp_death_drop_defuser,
    pName: "mp_death_drop_defuser",
    pDefaultValue: "1",
    flags: 0x2000,
    pHelpString: "Drop defuser on player death",
    bMin: true,
    fMin: 0.0,
    bMax: true,
    fMax: 1.0);
  return atexit(func: dynamic_atexit_destructor_for__mp_death_drop_defuser__);
}

//------------------------------------------------------------------------------
// Address: 0x10423370
// Name: _dynamic_initializer_for__mp_force_pick_time__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mp_force_pick_time__()
{
  ConVar::ConVar(
    this: &mp_force_pick_time,
    pName: "mp_force_pick_time",
    pDefaultValue: "10",
    flags: 0x2000,
    pHelpString: "The amount of time a player has on the team screen to make a selection before being auto-teamed");
  return atexit(func: dynamic_atexit_destructor_for__mp_force_pick_time__);
}

//------------------------------------------------------------------------------
// Address: 0x104233A0
// Name: _dynamic_initializer_for__cl_autowepswitch__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_autowepswitch__()
{
  ConVar::ConVar(
    this: &cl_autowepswitch,
    pName: "cl_autowepswitch",
    pDefaultValue: "1",
    flags: 33408,
    pHelpString: "Automatically switch to picked up weapons (if more powerful)");
  return atexit(func: dynamic_atexit_destructor_for__cl_autowepswitch__);
}

//------------------------------------------------------------------------------
// Address: 0x104233D0
// Name: _dynamic_initializer_for__cl_autohelp__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_autohelp__()
{
  ConVar::ConVar(this: &cl_autohelp, pName: "cl_autohelp", pDefaultValue: "1", flags: 640, pHelpString: "Auto-help");
  return atexit(func: dynamic_atexit_destructor_for__cl_autohelp__);
}

//------------------------------------------------------------------------------
// Address: 0x10423420
// Name: _dynamic_initializer_for__g_Input__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_Input__()
{
  CInput::CInput(this: &g_Input);
  g_Input.__vftable = (CCSInput_vtbl *)&CCSInput::`vftable';
  return atexit(func: dynamic_atexit_destructor_for__g_Input__);
}

//------------------------------------------------------------------------------
// Address: 0x10423440
// Name: _dynamic_initializer_for__sv_showimpacts__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_showimpacts__()
{
  ConVar::ConVar(
    this: &sv_showimpacts,
    pName: "sv_showimpacts",
    pDefaultValue: "0",
    flags: 0x2000,
    pHelpString: "Shows client (red) and server (blue) bullet impact point (1=both, 2=client-only, 3=server-only)");
  return atexit(func: dynamic_atexit_destructor_for__sv_showimpacts__);
}

//------------------------------------------------------------------------------
// Address: 0x10423470
// Name: _dynamic_initializer_for__sv_showplayerhitboxes__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_showplayerhitboxes__()
{
  ConVar::ConVar(
    this: &sv_showplayerhitboxes,
    pName: "sv_showplayerhitboxes",
    pDefaultValue: "0",
    flags: 0x2000,
    pHelpString: "Show lag compensated hitboxes for the specified player index whenever a player fires.");
  return atexit(func: dynamic_atexit_destructor_for__sv_showplayerhitboxes__);
}

//------------------------------------------------------------------------------
// Address: 0x104234A0
// Name: _dynamic_initializer_for____g_C_FootstepControlClientClass__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ClientClass *dynamic_initializer_for____g_C_FootstepControlClientClass__()
{
  ClientClass *result; // eax

  result = g_pClientClassHead;
  __g_C_FootstepControlClientClass.m_pNext = g_pClientClassHead;
  g_pClientClassHead = &__g_C_FootstepControlClientClass;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104355F0
// Name: _dynamic_atexit_destructor_for__mp_buytime__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mp_buytime__()
{
  ConVar::~ConVar(this: &mp_buytime);
}

//------------------------------------------------------------------------------
// Address: 0x10435600
// Name: _dynamic_atexit_destructor_for__mp_gungameimmunitytime__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mp_gungameimmunitytime__()
{
  ConVar::~ConVar(this: &mp_gungameimmunitytime);
}

//------------------------------------------------------------------------------
// Address: 0x10435610
// Name: _dynamic_atexit_destructor_for__mp_playerid__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mp_playerid__()
{
  ConVar::~ConVar(this: &mp_playerid);
}

//------------------------------------------------------------------------------
// Address: 0x10435620
// Name: _dynamic_atexit_destructor_for__mp_playerid_delay__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mp_playerid_delay__()
{
  ConVar::~ConVar(this: &mp_playerid_delay);
}

//------------------------------------------------------------------------------
// Address: 0x10435630
// Name: _dynamic_atexit_destructor_for__mp_playerid_hold__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mp_playerid_hold__()
{
  ConVar::~ConVar(this: &mp_playerid_hold);
}

//------------------------------------------------------------------------------
// Address: 0x10435640
// Name: _dynamic_atexit_destructor_for__mp_round_restart_delay__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mp_round_restart_delay__()
{
  ConVar::~ConVar(this: &mp_round_restart_delay);
}

//------------------------------------------------------------------------------
// Address: 0x10435650
// Name: _dynamic_atexit_destructor_for__mp_ggprogressive_round_restart_delay__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mp_ggprogressive_round_restart_delay__()
{
  ConVar::~ConVar(this: &mp_ggprogressive_round_restart_delay);
}

//------------------------------------------------------------------------------
// Address: 0x10435660
// Name: _dynamic_atexit_destructor_for__mp_ggprogressive_win_panel_pct__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mp_ggprogressive_win_panel_pct__()
{
  ConVar::~ConVar(this: &mp_ggprogressive_win_panel_pct);
}

//------------------------------------------------------------------------------
// Address: 0x10435670
// Name: _dynamic_atexit_destructor_for__mp_ggselect_match_bestof_win__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mp_ggselect_match_bestof_win__()
{
  ConVar::~ConVar(this: &mp_ggselect_match_bestof_win);
}

//------------------------------------------------------------------------------
// Address: 0x10435680
// Name: _dynamic_atexit_destructor_for__mp_ggtr_bomb_pts_for_upgrade__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mp_ggtr_bomb_pts_for_upgrade__()
{
  ConVar::~ConVar(this: &mp_ggtr_bomb_pts_for_upgrade);
}

//------------------------------------------------------------------------------
// Address: 0x10435690
// Name: _dynamic_atexit_destructor_for__mp_ggtr_bomb_pts_for_he__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mp_ggtr_bomb_pts_for_he__()
{
  ConVar::~ConVar(this: &mp_ggtr_bomb_pts_for_he);
}

//------------------------------------------------------------------------------
// Address: 0x104356A0
// Name: _dynamic_atexit_destructor_for__mp_ggtr_bomb_pts_for_flash__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mp_ggtr_bomb_pts_for_flash__()
{
  ConVar::~ConVar(this: &mp_ggtr_bomb_pts_for_flash);
}

//------------------------------------------------------------------------------
// Address: 0x104356B0
// Name: _dynamic_atexit_destructor_for__mp_ggtr_bomb_pts_for_molotov__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mp_ggtr_bomb_pts_for_molotov__()
{
  ConVar::~ConVar(this: &mp_ggtr_bomb_pts_for_molotov);
}

//------------------------------------------------------------------------------
// Address: 0x104356C0
// Name: _dynamic_atexit_destructor_for__mp_molotovusedelay__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mp_molotovusedelay__()
{
  ConVar::~ConVar(this: &mp_molotovusedelay);
}

//------------------------------------------------------------------------------
// Address: 0x104356D0
// Name: _dynamic_atexit_destructor_for__mp_ggtr_halftime_delay__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mp_ggtr_halftime_delay__()
{
  ConVar::~ConVar(this: &mp_ggtr_halftime_delay);
}

//------------------------------------------------------------------------------
// Address: 0x104356E0
// Name: _dynamic_atexit_destructor_for__mp_ggtr_bomb_respawn_delay__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mp_ggtr_bomb_respawn_delay__()
{
  ConVar::~ConVar(this: &mp_ggtr_bomb_respawn_delay);
}

//------------------------------------------------------------------------------
// Address: 0x104356F0
// Name: _dynamic_atexit_destructor_for__mp_ggtr_bomb_defuse_bonus__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mp_ggtr_bomb_defuse_bonus__()
{
  ConVar::~ConVar(this: &mp_ggtr_bomb_defuse_bonus);
}

//------------------------------------------------------------------------------
// Address: 0x10435700
// Name: _dynamic_atexit_destructor_for__mp_ggtr_bomb_detonation_bonus__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mp_ggtr_bomb_detonation_bonus__()
{
  ConVar::~ConVar(this: &mp_ggtr_bomb_detonation_bonus);
}

//------------------------------------------------------------------------------
// Address: 0x10435710
// Name: _dynamic_atexit_destructor_for__mp_ggtr_rounds_per_half__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mp_ggtr_rounds_per_half__()
{
  ConVar::~ConVar(this: &mp_ggtr_rounds_per_half);
}

//------------------------------------------------------------------------------
// Address: 0x10435720
// Name: _dynamic_atexit_destructor_for__mp_match_end_restart__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mp_match_end_restart__()
{
  ConVar::~ConVar(this: &mp_match_end_restart);
}

//------------------------------------------------------------------------------
// Address: 0x10435730
// Name: _dynamic_atexit_destructor_for__mp_defuser_allocation__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mp_defuser_allocation__()
{
  ConVar::~ConVar(this: &mp_defuser_allocation);
}

//------------------------------------------------------------------------------
// Address: 0x10435740
// Name: _dynamic_atexit_destructor_for__mp_death_drop_gun__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mp_death_drop_gun__()
{
  ConVar::~ConVar(this: &mp_death_drop_gun);
}

//------------------------------------------------------------------------------
// Address: 0x10435750
// Name: _dynamic_atexit_destructor_for__mp_death_drop_grenade__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mp_death_drop_grenade__()
{
  ConVar::~ConVar(this: &mp_death_drop_grenade);
}

//------------------------------------------------------------------------------
// Address: 0x10435760
// Name: _dynamic_atexit_destructor_for__mp_death_drop_defuser__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mp_death_drop_defuser__()
{
  ConVar::~ConVar(this: &mp_death_drop_defuser);
}

//------------------------------------------------------------------------------
// Address: 0x10435770
// Name: _dynamic_atexit_destructor_for__mp_force_pick_time__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mp_force_pick_time__()
{
  ConVar::~ConVar(this: &mp_force_pick_time);
}

//------------------------------------------------------------------------------
// Address: 0x10435780
// Name: _dynamic_atexit_destructor_for__cl_autowepswitch__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_autowepswitch__()
{
  ConVar::~ConVar(this: &cl_autowepswitch);
}

//------------------------------------------------------------------------------
// Address: 0x10435790
// Name: _dynamic_atexit_destructor_for__cl_autohelp__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_autohelp__()
{
  ConVar::~ConVar(this: &cl_autohelp);
}

//------------------------------------------------------------------------------
// Address: 0x104357B0
// Name: _dynamic_atexit_destructor_for__g_Input__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_Input__()
{
  CInput::~CInput(this: &g_Input);
}

//------------------------------------------------------------------------------
// Address: 0x104357C0
// Name: _dynamic_atexit_destructor_for__sv_showimpacts__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sv_showimpacts__()
{
  ConVar::~ConVar(this: &sv_showimpacts);
}

//------------------------------------------------------------------------------
// Address: 0x104357D0
// Name: _dynamic_atexit_destructor_for__sv_showplayerhitboxes__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sv_showplayerhitboxes__()
{
  ConVar::~ConVar(this: &sv_showplayerhitboxes);
}

// ============================================================
// Overlay from server (Missing functions)
// ============================================================
namespace server {

//------------------------------------------------------------------------------
// Address: 0x10269A30
// Name: public: void CCSAmmoDef::AddAmmoCost(char const __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSAmmoDef::AddAmmoCost(CCSAmmoDef *this, const char *name, int cost, int buySize)
{
  int v5; // eax

  v5 = CAmmoDef::Index(this, psz: name);
  if ( v5 >= 1 && v5 < this->m_nAmmoIndex )
  {
    this->m_csAmmo[v5].buySize = buySize;
    this->m_csAmmo[v5].cost = cost;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10269A70
// Name: public: int CCSAmmoDef::GetBuySize(int)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CCSAmmoDef::GetBuySize(CCSAmmoDef *this, int index)
{
  if ( index < 1 || index >= this->m_nAmmoIndex )
    return 0;
  else
    return this->m_csAmmo[index].buySize;
}

//------------------------------------------------------------------------------
// Address: 0x10269AA0
// Name: public: int CCSAmmoDef::GetCost(int)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CCSAmmoDef::GetCost(CCSAmmoDef *this, int index)
{
  if ( index < 1 || index >= this->m_nAmmoIndex )
    return 0;
  else
    return this->m_csAmmo[index].cost;
}

//------------------------------------------------------------------------------
// Address: 0x10269AD0
// Name: public: CCSAmmoDef::CCSAmmoDef(void)
// Source: json
//------------------------------------------------------------------------------
CCSAmmoDef *__thiscall CCSAmmoDef::CCSAmmoDef(CCSAmmoDef *this)
{
  CAmmoDef::CAmmoDef(this);
  this->__vftable = (CCSAmmoDef_vtbl *)&CCSAmmoDef::`vftable';
  memset(dst: (int)this->m_csAmmo, value: nullptr, count: sizeof(this->m_csAmmo));
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10269B00
// Name: public: virtual CCSAmmoDef::~CCSAmmoDef(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSAmmoDef::~CCSAmmoDef(CCSAmmoDef *this)
{
  this->__vftable = (CCSAmmoDef_vtbl *)&CCSAmmoDef::`vftable';
  CAmmoDef::~CAmmoDef(this);
}

} // namespace server
