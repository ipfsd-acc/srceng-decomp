// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/cstrike15/item_ammo.cpp
// Functions: 208
// ============================================================

#include "game\server\cstrike15\item_ammo.h"

//------------------------------------------------------------------------------
// Address: 0x102A3B50
// Name: public: virtual bool CItemAmmo::MyTouch(class CBasePlayer __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CItemAmmo::MyTouch(CItemAmmo *this, CBasePlayer *pBasePlayer)
{
  int *v3; // esi
  CCSAmmoDef *CSAmmoDef; // eax
  int v6; // eax
  int v7; // edi
  CCSAmmoDef *v8; // eax
  int BuySize; // eax
  int v10; // [esp-Ch] [ebp-14h]
  int v11; // [esp-8h] [ebp-10h]
  const char *v12; // [esp-4h] [ebp-Ch]

  v3 = (int *)__RTDynamicCast(
                inptr: pBasePlayer,
                VfDelta: 0,
                SrcType: &CBasePlayer `RTTI Type Descriptor',
                TargetType: &CCSPlayer `RTTI Type Descriptor',
                isReference: 0);
  if ( v3 == nullptr )
    return 0;
  v12 = this->GetAmmoName(this);
  CSAmmoDef = GetCSAmmoDef();
  v6 = CAmmoDef::Index(this: CSAmmoDef, psz: v12);
  if ( v6 < 0 )
    return 0;
  v7 = *v3;
  v11 = v6;
  v10 = v6;
  v8 = GetCSAmmoDef();
  BuySize = CCSAmmoDef::GetBuySize(this: v8, index: v10);
  (*(void (__thiscall **)(int *, int, int, _DWORD))(v7 + 1076))(a1: v3, a2: BuySize, a3: v11, a4: 0);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x102A3BD0
// Name: public: virtual char const __near * CItemAmmo50AE::GetAmmoName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CItemAmmo50AE::GetAmmoName(CItemAmmo50AE *this)
{
  return "BULLET_PLAYER_50AE";
}

//------------------------------------------------------------------------------
// Address: 0x102A3BE0
// Name: public: virtual char const __near * CItemAmmo762MM::GetAmmoName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CItemAmmo762MM::GetAmmoName(CItemAmmo762MM *this)
{
  return "BULLET_PLAYER_762MM";
}

//------------------------------------------------------------------------------
// Address: 0x102A3BF0
// Name: public: virtual char const __near * CItemAmmo556MM::GetAmmoName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CItemAmmo556MM::GetAmmoName(CItemAmmo556MM *this)
{
  return "BULLET_PLAYER_556MM";
}

//------------------------------------------------------------------------------
// Address: 0x102A3C00
// Name: public: virtual char const __near * CItemAmmo556MM_BOX::GetAmmoName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CItemAmmo556MM_BOX::GetAmmoName(CItemAmmo556MM_BOX *this)
{
  return "BULLET_PLAYER_556MM_BOX";
}

//------------------------------------------------------------------------------
// Address: 0x102A3C10
// Name: public: virtual char const __near * CItemAmmo338MAG::GetAmmoName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CItemAmmo338MAG::GetAmmoName(CItemAmmo338MAG *this)
{
  return "BULLET_PLAYER_338MAG";
}

//------------------------------------------------------------------------------
// Address: 0x102A3C20
// Name: public: virtual char const __near * CItemAmmo9MM::GetAmmoName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CItemAmmo9MM::GetAmmoName(CItemAmmo9MM *this)
{
  return "BULLET_PLAYER_9MM";
}

//------------------------------------------------------------------------------
// Address: 0x102A3C30
// Name: public: virtual char const __near * CItemAmmoBuckshot::GetAmmoName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CItemAmmoBuckshot::GetAmmoName(CItemAmmoBuckshot *this)
{
  return "BULLET_PLAYER_BUCKSHOT";
}

//------------------------------------------------------------------------------
// Address: 0x102A3C40
// Name: public: virtual char const __near * CItemAmmo45ACP::GetAmmoName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CItemAmmo45ACP::GetAmmoName(CItemAmmo45ACP *this)
{
  return "BULLET_PLAYER_45ACP";
}

//------------------------------------------------------------------------------
// Address: 0x102A3C50
// Name: public: virtual char const __near * CItemAmmo357SIG::GetAmmoName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CItemAmmo357SIG::GetAmmoName(CItemAmmo357SIG *this)
{
  return "BULLET_PLAYER_357SIG";
}

//------------------------------------------------------------------------------
// Address: 0x102A3C60
// Name: public: virtual char const __near * CItemAmmo57MM::GetAmmoName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CItemAmmo57MM::GetAmmoName(CItemAmmo57MM *this)
{
  return "BULLET_PLAYER_57MM";
}

//------------------------------------------------------------------------------
// Address: 0x1040D510
// Name: _dynamic_initializer_for__ammo_50AE_max__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__ammo_50AE_max__()
{
  ConVar::ConVar(this: &ammo_50AE_max, pName: "ammo_50AE_max", pDefaultValue: "35", flags: 0x2000);
  return atexit(func: dynamic_atexit_destructor_for__ammo_50AE_max__);
}

//------------------------------------------------------------------------------
// Address: 0x1040D540
// Name: _dynamic_initializer_for__ammo_762mm_max__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__ammo_762mm_max__()
{
  ConVar::ConVar(this: &ammo_762mm_max, pName: "ammo_762mm_max", pDefaultValue: "90", flags: 0x2000);
  return atexit(func: dynamic_atexit_destructor_for__ammo_762mm_max__);
}

//------------------------------------------------------------------------------
// Address: 0x1040D570
// Name: _dynamic_initializer_for__ammo_556mm_max__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__ammo_556mm_max__()
{
  ConVar::ConVar(this: &ammo_556mm_max, pName: "ammo_556mm_max", pDefaultValue: "90", flags: 0x2000);
  return atexit(func: dynamic_atexit_destructor_for__ammo_556mm_max__);
}

//------------------------------------------------------------------------------
// Address: 0x1040D5A0
// Name: _dynamic_initializer_for__ammo_556mm_box_max__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__ammo_556mm_box_max__()
{
  ConVar::ConVar(this: &ammo_556mm_box_max, pName: "ammo_556mm_box_max", pDefaultValue: "200", flags: 0x2000);
  return atexit(func: dynamic_atexit_destructor_for__ammo_556mm_box_max__);
}

//------------------------------------------------------------------------------
// Address: 0x1040D5D0
// Name: _dynamic_initializer_for__ammo_338mag_max__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__ammo_338mag_max__()
{
  ConVar::ConVar(this: &ammo_338mag_max, pName: "ammo_338mag_max", pDefaultValue: "30", flags: 0x2000);
  return atexit(func: dynamic_atexit_destructor_for__ammo_338mag_max__);
}

//------------------------------------------------------------------------------
// Address: 0x1040D600
// Name: _dynamic_initializer_for__ammo_9mm_max__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__ammo_9mm_max__()
{
  ConVar::ConVar(this: &ammo_9mm_max, pName: "ammo_9mm_max", pDefaultValue: "120", flags: 0x2000);
  return atexit(func: dynamic_atexit_destructor_for__ammo_9mm_max__);
}

//------------------------------------------------------------------------------
// Address: 0x1040D630
// Name: _dynamic_initializer_for__ammo_buckshot_max__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__ammo_buckshot_max__()
{
  ConVar::ConVar(this: &ammo_buckshot_max, pName: "ammo_buckshot_max", pDefaultValue: "32", flags: 0x2000);
  return atexit(func: dynamic_atexit_destructor_for__ammo_buckshot_max__);
}

//------------------------------------------------------------------------------
// Address: 0x1040D660
// Name: _dynamic_initializer_for__ammo_45acp_max__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__ammo_45acp_max__()
{
  ConVar::ConVar(this: &ammo_45acp_max, pName: "ammo_45acp_max", pDefaultValue: "100", flags: 0x2000);
  return atexit(func: dynamic_atexit_destructor_for__ammo_45acp_max__);
}

//------------------------------------------------------------------------------
// Address: 0x1040D690
// Name: _dynamic_initializer_for__ammo_357sig_max__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__ammo_357sig_max__()
{
  ConVar::ConVar(this: &ammo_357sig_max, pName: "ammo_357sig_max", pDefaultValue: "52", flags: 0x2000);
  return atexit(func: dynamic_atexit_destructor_for__ammo_357sig_max__);
}

//------------------------------------------------------------------------------
// Address: 0x1040D6C0
// Name: _dynamic_initializer_for__ammo_57mm_max__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__ammo_57mm_max__()
{
  ConVar::ConVar(this: &ammo_57mm_max, pName: "ammo_57mm_max", pDefaultValue: "100", flags: 0x2000);
  return atexit(func: dynamic_atexit_destructor_for__ammo_57mm_max__);
}

//------------------------------------------------------------------------------
// Address: 0x1040D6F0
// Name: _dynamic_initializer_for__ammo_hegrenade_max__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__ammo_hegrenade_max__()
{
  ConVar::ConVar(this: &ammo_hegrenade_max, pName: "ammo_hegrenade_max", pDefaultValue: "1", flags: 0x2000);
  return atexit(func: dynamic_atexit_destructor_for__ammo_hegrenade_max__);
}

//------------------------------------------------------------------------------
// Address: 0x1040D720
// Name: _dynamic_initializer_for__ammo_flashbang_max__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__ammo_flashbang_max__()
{
  ConVar::ConVar(this: &ammo_flashbang_max, pName: "ammo_flashbang_max", pDefaultValue: "2", flags: 0x2000);
  return atexit(func: dynamic_atexit_destructor_for__ammo_flashbang_max__);
}

//------------------------------------------------------------------------------
// Address: 0x1040D750
// Name: _dynamic_initializer_for__ammo_smokegrenade_max__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__ammo_smokegrenade_max__()
{
  ConVar::ConVar(this: &ammo_smokegrenade_max, pName: "ammo_smokegrenade_max", pDefaultValue: "1", flags: 0x2000);
  return atexit(func: dynamic_atexit_destructor_for__ammo_smokegrenade_max__);
}

//------------------------------------------------------------------------------
// Address: 0x1040D780
// Name: _dynamic_initializer_for__ammo_molotov_max__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__ammo_molotov_max__()
{
  ConVar::ConVar(this: &ammo_molotov_max, pName: "ammo_molotov_max", pDefaultValue: "1", flags: 0x2000);
  return atexit(func: dynamic_atexit_destructor_for__ammo_molotov_max__);
}

//------------------------------------------------------------------------------
// Address: 0x1040D7B0
// Name: _dynamic_initializer_for__ammo_decoy_max__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__ammo_decoy_max__()
{
  ConVar::ConVar(this: &ammo_decoy_max, pName: "ammo_decoy_max", pDefaultValue: "1", flags: 0x2000);
  return atexit(func: dynamic_atexit_destructor_for__ammo_decoy_max__);
}

//------------------------------------------------------------------------------
// Address: 0x10410230
// Name: _dynamic_initializer_for__ammo_50ae__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__ammo_50ae__()
{
  CEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(CEntityFactoryDictionary *, CEntityFactory<CItemAmmo50AE> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &ammo_50ae,
           a3: "ammo_50ae");
}

//------------------------------------------------------------------------------
// Address: 0x10410250
// Name: _dynamic_initializer_for__ammo_762mm__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__ammo_762mm__()
{
  CEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(CEntityFactoryDictionary *, CEntityFactory<CItemAmmo762MM> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &ammo_762mm,
           a3: "ammo_762mm");
}

//------------------------------------------------------------------------------
// Address: 0x10410270
// Name: _dynamic_initializer_for__ammo_556mm__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__ammo_556mm__()
{
  CEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(CEntityFactoryDictionary *, CEntityFactory<CItemAmmo556MM> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &ammo_556mm,
           a3: "ammo_556mm");
}

//------------------------------------------------------------------------------
// Address: 0x10410290
// Name: _dynamic_initializer_for__ammo_556mm_box__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__ammo_556mm_box__()
{
  CEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(CEntityFactoryDictionary *, CEntityFactory<CItemAmmo556MM_BOX> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &ammo_556mm_box,
           a3: "ammo_556mm_box");
}

//------------------------------------------------------------------------------
// Address: 0x104102B0
// Name: _dynamic_initializer_for__ammo_338mag__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__ammo_338mag__()
{
  CEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(CEntityFactoryDictionary *, CEntityFactory<CItemAmmo338MAG> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &ammo_338mag,
           a3: "ammo_338mag");
}

//------------------------------------------------------------------------------
// Address: 0x104102D0
// Name: _dynamic_initializer_for__ammo_9mm__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__ammo_9mm__()
{
  CEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(CEntityFactoryDictionary *, CEntityFactory<CItemAmmo9MM> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &ammo_9mm,
           a3: "ammo_9mm");
}

//------------------------------------------------------------------------------
// Address: 0x104102F0
// Name: _dynamic_initializer_for__ammo_buckshot__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__ammo_buckshot__()
{
  CEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(CEntityFactoryDictionary *, CEntityFactory<CItemAmmoBuckshot> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &ammo_buckshot,
           a3: "ammo_buckshot");
}

//------------------------------------------------------------------------------
// Address: 0x10410310
// Name: _dynamic_initializer_for__ammo_45acp__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__ammo_45acp__()
{
  CEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(CEntityFactoryDictionary *, CEntityFactory<CItemAmmo45ACP> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &ammo_45acp,
           a3: "ammo_45acp");
}

//------------------------------------------------------------------------------
// Address: 0x10410330
// Name: _dynamic_initializer_for__ammo_357sig__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__ammo_357sig__()
{
  CEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(CEntityFactoryDictionary *, CEntityFactory<CItemAmmo357SIG> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &ammo_357sig,
           a3: "ammo_357sig");
}

//------------------------------------------------------------------------------
// Address: 0x10410350
// Name: _dynamic_initializer_for__ammo_57mm__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__ammo_57mm__()
{
  CEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(CEntityFactoryDictionary *, CEntityFactory<CItemAmmo57MM> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &ammo_57mm,
           a3: "ammo_57mm");
}

//------------------------------------------------------------------------------
// Address: 0x1041F450
// Name: _dynamic_atexit_destructor_for__ammo_50AE_max__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__ammo_50AE_max__()
{
  ConVar::~ConVar(this: &ammo_50AE_max);
}

//------------------------------------------------------------------------------
// Address: 0x1041F460
// Name: _dynamic_atexit_destructor_for__ammo_762mm_max__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__ammo_762mm_max__()
{
  ConVar::~ConVar(this: &ammo_762mm_max);
}

//------------------------------------------------------------------------------
// Address: 0x1041F470
// Name: _dynamic_atexit_destructor_for__ammo_556mm_max__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__ammo_556mm_max__()
{
  ConVar::~ConVar(this: &ammo_556mm_max);
}

//------------------------------------------------------------------------------
// Address: 0x1041F480
// Name: _dynamic_atexit_destructor_for__ammo_556mm_box_max__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__ammo_556mm_box_max__()
{
  ConVar::~ConVar(this: &ammo_556mm_box_max);
}

//------------------------------------------------------------------------------
// Address: 0x1041F490
// Name: _dynamic_atexit_destructor_for__ammo_338mag_max__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__ammo_338mag_max__()
{
  ConVar::~ConVar(this: &ammo_338mag_max);
}

//------------------------------------------------------------------------------
// Address: 0x1041F4A0
// Name: _dynamic_atexit_destructor_for__ammo_9mm_max__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__ammo_9mm_max__()
{
  ConVar::~ConVar(this: &ammo_9mm_max);
}

//------------------------------------------------------------------------------
// Address: 0x1041F4B0
// Name: _dynamic_atexit_destructor_for__ammo_buckshot_max__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__ammo_buckshot_max__()
{
  ConVar::~ConVar(this: &ammo_buckshot_max);
}

//------------------------------------------------------------------------------
// Address: 0x1041F4C0
// Name: _dynamic_atexit_destructor_for__ammo_45acp_max__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__ammo_45acp_max__()
{
  ConVar::~ConVar(this: &ammo_45acp_max);
}

//------------------------------------------------------------------------------
// Address: 0x1041F4D0
// Name: _dynamic_atexit_destructor_for__ammo_357sig_max__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__ammo_357sig_max__()
{
  ConVar::~ConVar(this: &ammo_357sig_max);
}

//------------------------------------------------------------------------------
// Address: 0x1041F4E0
// Name: _dynamic_atexit_destructor_for__ammo_57mm_max__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__ammo_57mm_max__()
{
  ConVar::~ConVar(this: &ammo_57mm_max);
}

//------------------------------------------------------------------------------
// Address: 0x1041F4F0
// Name: _dynamic_atexit_destructor_for__ammo_hegrenade_max__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__ammo_hegrenade_max__()
{
  ConVar::~ConVar(this: &ammo_hegrenade_max);
}

//------------------------------------------------------------------------------
// Address: 0x1041F500
// Name: _dynamic_atexit_destructor_for__ammo_flashbang_max__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__ammo_flashbang_max__()
{
  ConVar::~ConVar(this: &ammo_flashbang_max);
}

//------------------------------------------------------------------------------
// Address: 0x1041F510
// Name: _dynamic_atexit_destructor_for__ammo_smokegrenade_max__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__ammo_smokegrenade_max__()
{
  ConVar::~ConVar(this: &ammo_smokegrenade_max);
}

//------------------------------------------------------------------------------
// Address: 0x1041F520
// Name: _dynamic_atexit_destructor_for__ammo_molotov_max__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__ammo_molotov_max__()
{
  ConVar::~ConVar(this: &ammo_molotov_max);
}

//------------------------------------------------------------------------------
// Address: 0x1041F530
// Name: _dynamic_atexit_destructor_for__ammo_decoy_max__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__ammo_decoy_max__()
{
  ConVar::~ConVar(this: &ammo_decoy_max);
}

//------------------------------------------------------------------------------
// Address: 0x1040D7E0
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
// Address: 0x1040D820
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
// Address: 0x1040D850
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
// Address: 0x1040D8A0
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
// Address: 0x1040D8F0
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
// Address: 0x1040D940
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
// Address: 0x1040D990
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
// Address: 0x1040D9E0
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
// Address: 0x1040DA30
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
// Address: 0x1040DA80
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
// Address: 0x1040DAD0
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
// Address: 0x1040DB20
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
// Address: 0x1040DB70
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
// Address: 0x1040DBC0
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
// Address: 0x1040DC10
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
// Address: 0x1040DC60
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
// Address: 0x1040DCB0
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
// Address: 0x1040DD00
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
// Address: 0x1040DD50
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
// Address: 0x1040DDA0
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
// Address: 0x1040DDF0
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
// Address: 0x1040DE40
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
// Address: 0x1040DE90
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
// Address: 0x1040DEE0
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
// Address: 0x1040DF30
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
// Address: 0x1040DF60
// Name: _dynamic_initializer_for__g_VoiceGameMgrHelper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_VoiceGameMgrHelper__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_VoiceGameMgrHelper__);
}

//------------------------------------------------------------------------------
// Address: 0x1040DF70
// Name: _dynamic_initializer_for__mp_startmoney__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mp_startmoney__()
{
  ConVar::ConVar(
    this: &mp_startmoney,
    pName: "mp_startmoney",
    pDefaultValue: "800",
    flags: 0x2000,
    pHelpString: "amount of money each player gets when they reset",
    bMin: true,
    fMin: 0.0,
    bMax: true,
    fMax: 16000.0);
  return atexit(func: dynamic_atexit_destructor_for__mp_startmoney__);
}

//------------------------------------------------------------------------------
// Address: 0x1040DFD0
// Name: _dynamic_initializer_for__mp_roundtime__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mp_roundtime__()
{
  ConVar::ConVar(
    this: &mp_roundtime,
    pName: "mp_roundtime",
    pDefaultValue: "5",
    flags: 8448,
    pHelpString: "How many minutes each round takes.",
    bMin: true,
    fMin: 1.0,
    bMax: true,
    fMax: 10.0);
  return atexit(func: dynamic_atexit_destructor_for__mp_roundtime__);
}

//------------------------------------------------------------------------------
// Address: 0x1040E020
// Name: _dynamic_initializer_for__mp_freezetime__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mp_freezetime__()
{
  ConVar::ConVar(
    this: &mp_freezetime,
    pName: "mp_freezetime",
    pDefaultValue: "6",
    flags: 8448,
    pHelpString: "how many seconds to keep players frozen when the round starts",
    bMin: true,
    fMin: 0.0,
    bMax: true,
    fMax: 60.0);
  return atexit(func: dynamic_atexit_destructor_for__mp_freezetime__);
}

//------------------------------------------------------------------------------
// Address: 0x1040E070
// Name: _dynamic_initializer_for__mp_c4timer__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mp_c4timer__()
{
  ConVar::ConVar(
    this: &mp_c4timer,
    pName: "mp_c4timer",
    pDefaultValue: "45",
    flags: 8448,
    pHelpString: "how long from when the C4 is armed until it blows",
    bMin: true,
    fMin: 10.0,
    bMax: true,
    fMax: 90.0);
  return atexit(func: dynamic_atexit_destructor_for__mp_c4timer__);
}

//------------------------------------------------------------------------------
// Address: 0x1040E0C0
// Name: _dynamic_initializer_for__mp_limitteams__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mp_limitteams__()
{
  ConVar::ConVar(
    this: &mp_limitteams,
    pName: "mp_limitteams",
    pDefaultValue: "2",
    flags: 8448,
    pHelpString: "Max # of players 1 team can have over another (0 disables check)",
    bMin: true,
    fMin: 0.0,
    bMax: true,
    fMax: 30.0);
  return atexit(func: dynamic_atexit_destructor_for__mp_limitteams__);
}

//------------------------------------------------------------------------------
// Address: 0x1040E110
// Name: _dynamic_initializer_for__mp_tkpunish__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mp_tkpunish__()
{
  ConVar::ConVar(
    this: &mp_tkpunish,
    pName: "mp_tkpunish",
    pDefaultValue: "0",
    flags: 0x2000,
    pHelpString: "Will a TK'er be punished in the next round?  {0=no,  1=yes}");
  return atexit(func: dynamic_atexit_destructor_for__mp_tkpunish__);
}

//------------------------------------------------------------------------------
// Address: 0x1040E140
// Name: _dynamic_initializer_for__mp_autokick__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mp_autokick__()
{
  ConVar::ConVar(
    this: &mp_autokick,
    pName: "mp_autokick",
    pDefaultValue: "1",
    flags: 0x2000,
    pHelpString: "Kick idle/team-killing players");
  return atexit(func: dynamic_atexit_destructor_for__mp_autokick__);
}

//------------------------------------------------------------------------------
// Address: 0x1040E170
// Name: _dynamic_initializer_for__mp_spawnprotectiontime__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mp_spawnprotectiontime__()
{
  ConVar::ConVar(
    this: &mp_spawnprotectiontime,
    pName: "mp_spawnprotectiontime",
    pDefaultValue: "5",
    flags: 0x2000,
    pHelpString: "Kick players who team-kill within this many seconds of a round restart.");
  return atexit(func: dynamic_atexit_destructor_for__mp_spawnprotectiontime__);
}

//------------------------------------------------------------------------------
// Address: 0x1040E1A0
// Name: _dynamic_initializer_for__mp_humanteam__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mp_humanteam__()
{
  ConVar::ConVar(
    this: &mp_humanteam,
    pName: "mp_humanteam",
    pDefaultValue: "any",
    flags: 0x2000,
    pHelpString: "Restricts human players to a single team {any, CT, T}");
  return atexit(func: dynamic_atexit_destructor_for__mp_humanteam__);
}

//------------------------------------------------------------------------------
// Address: 0x1040E1D0
// Name: _dynamic_initializer_for__mp_ignore_round_win_conditions__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mp_ignore_round_win_conditions__()
{
  ConVar::ConVar(
    this: &mp_ignore_round_win_conditions,
    pName: "mp_ignore_round_win_conditions",
    pDefaultValue: "0",
    flags: 0x2000,
    pHelpString: "Ignore conditions which would end the current round");
  return atexit(func: dynamic_atexit_destructor_for__mp_ignore_round_win_conditions__);
}

//------------------------------------------------------------------------------
// Address: 0x1040E200
// Name: _dynamic_initializer_for__mp_required_vote_majority__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mp_required_vote_majority__()
{
  ConVar::ConVar(
    this: &mp_required_vote_majority,
    pName: "mp_required_vote_majority",
    pDefaultValue: "0.75",
    flags: 0x2000,
    pHelpString: "The percentage of human players that need to vote yes for a vote to pass");
  return atexit(func: dynamic_atexit_destructor_for__mp_required_vote_majority__);
}

//------------------------------------------------------------------------------
// Address: 0x1040E230
// Name: _dynamic_initializer_for__mp_required_voters__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mp_required_voters__()
{
  ConVar::ConVar(
    this: &mp_required_voters,
    pName: "mp_required_voters",
    pDefaultValue: "3",
    flags: 0x2000,
    pHelpString: "The number of human players required for a vote");
  return atexit(func: dynamic_atexit_destructor_for__mp_required_voters__);
}

//------------------------------------------------------------------------------
// Address: 0x1040E260
// Name: _dynamic_initializer_for__mp_vote_time__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mp_vote_time__()
{
  ConVar::ConVar(
    this: &mp_vote_time,
    pName: "mp_vote_time",
    pDefaultValue: "30.0",
    flags: 0x2000,
    pHelpString: "The windows of time for players to cast their votes on an issue.");
  return atexit(func: dynamic_atexit_destructor_for__mp_vote_time__);
}

//------------------------------------------------------------------------------
// Address: 0x1040E290
// Name: _dynamic_initializer_for__EndRound__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__EndRound__()
{
  ConCommand::ConCommand(
    this: &EndRound,
    pName: "endround",
    callback: CCSGameRules::EndRound,
    pHelpString: "End the current round.",
    flags: 0x4000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__EndRound__);
}

//------------------------------------------------------------------------------
// Address: 0x1040E2C0
// Name: _dynamic_initializer_for__score_default__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__score_default__()
{
  ConVar::ConVar(
    this: &score_default,
    pName: "score_default",
    pDefaultValue: "1000",
    flags: 128,
    pHelpString: "Default points for a new user");
  return atexit(func: dynamic_atexit_destructor_for__score_default__);
}

//------------------------------------------------------------------------------
// Address: 0x1040E2F0
// Name: _dynamic_initializer_for__score_kill_enemy_bonus__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__score_kill_enemy_bonus__()
{
  ConVar::ConVar(
    this: &score_kill_enemy_bonus,
    pName: "score_kill_enemy_bonus",
    pDefaultValue: "0",
    flags: 128,
    pHelpString: "Points awarded for killing an enemy");
  return atexit(func: dynamic_atexit_destructor_for__score_kill_enemy_bonus__);
}

//------------------------------------------------------------------------------
// Address: 0x1040E320
// Name: _dynamic_initializer_for__score_damage__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__score_damage__()
{
  ConVar::ConVar(
    this: &score_damage,
    pName: "score_damage",
    pDefaultValue: "1",
    flags: 128,
    pHelpString: "Points awarded for each point of damage to an enemy");
  return atexit(func: dynamic_atexit_destructor_for__score_damage__);
}

//------------------------------------------------------------------------------
// Address: 0x1040E350
// Name: _dynamic_initializer_for__score_ff_damage__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__score_ff_damage__()
{
  ConVar::ConVar(
    this: &score_ff_damage,
    pName: "score_ff_damage",
    pDefaultValue: "1",
    flags: 128,
    pHelpString: "Penalty awarded for each point of damage to a teammate");
  return atexit(func: dynamic_atexit_destructor_for__score_ff_damage__);
}

//------------------------------------------------------------------------------
// Address: 0x1040E380
// Name: _dynamic_initializer_for__score_team_damage_bonus__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__score_team_damage_bonus__()
{
  ConVar::ConVar(
    this: &score_team_damage_bonus,
    pName: "score_team_damage_bonus",
    pDefaultValue: "1",
    flags: 128,
    pHelpString: "Points awarded for each point of damage a nearby (in same zone) teammate does to enemies");
  return atexit(func: dynamic_atexit_destructor_for__score_team_damage_bonus__);
}

//------------------------------------------------------------------------------
// Address: 0x1040E3B0
// Name: _dynamic_initializer_for__score_planted_bomb_proximity_damage_bonus__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__score_planted_bomb_proximity_damage_bonus__()
{
  ConVar::ConVar(
    this: &score_planted_bomb_proximity_damage_bonus,
    pName: "score_planted_bomb_proximity_damage_bonus",
    pDefaultValue: "1",
    flags: 128,
    pHelpString: "Points awarded for damaging enemy near planted bomb");
  return atexit(func: dynamic_atexit_destructor_for__score_planted_bomb_proximity_damage_bonus__);
}

//------------------------------------------------------------------------------
// Address: 0x1040E3E0
// Name: _dynamic_initializer_for__score_planted_bomb_proximity_damage_radius_inner__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__score_planted_bomb_proximity_damage_radius_inner__()
{
  ConVar::ConVar(
    this: &score_planted_bomb_proximity_damage_radius_inner,
    pName: "score_planted_bomb_proximity_damage_radius_inner",
    pDefaultValue: "120",
    flags: 128,
    pHelpString: "Inner radius (full bonus) for doing damage near planted bomb");
  return atexit(func: dynamic_atexit_destructor_for__score_planted_bomb_proximity_damage_radius_inner__);
}

//------------------------------------------------------------------------------
// Address: 0x1040E410
// Name: _dynamic_initializer_for__score_planted_bomb_proximity_damage_radius_outer__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__score_planted_bomb_proximity_damage_radius_outer__()
{
  ConVar::ConVar(
    this: &score_planted_bomb_proximity_damage_radius_outer,
    pName: "score_planted_bomb_proximity_damage_radius_outer",
    pDefaultValue: "600",
    flags: 128,
    pHelpString: "Outer radius (zero bonus) for doing damage near planted bomb");
  return atexit(func: dynamic_atexit_destructor_for__score_planted_bomb_proximity_damage_radius_outer__);
}

//------------------------------------------------------------------------------
// Address: 0x1040E440
// Name: _dynamic_initializer_for__score_hostage_proximity_damage_bonus__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__score_hostage_proximity_damage_bonus__()
{
  ConVar::ConVar(
    this: &score_hostage_proximity_damage_bonus,
    pName: "score_hostage_proximity_damage_bonus",
    pDefaultValue: "1",
    flags: 128,
    pHelpString: "Points awarded for damaging enemy near live hostage");
  return atexit(func: dynamic_atexit_destructor_for__score_hostage_proximity_damage_bonus__);
}

//------------------------------------------------------------------------------
// Address: 0x1040E470
// Name: _dynamic_initializer_for__score_hostage_proximity_damage_radius_inner__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__score_hostage_proximity_damage_radius_inner__()
{
  ConVar::ConVar(
    this: &score_hostage_proximity_damage_radius_inner,
    pName: "score_hostage_proximity_damage_radius_inner",
    pDefaultValue: "120",
    flags: 128,
    pHelpString: "Inner radius (full bonus) for doing damage near hostage");
  return atexit(func: dynamic_atexit_destructor_for__score_hostage_proximity_damage_radius_inner__);
}

//------------------------------------------------------------------------------
// Address: 0x1040E4A0
// Name: _dynamic_initializer_for__score_hostage_proximity_damage_radius_outer__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__score_hostage_proximity_damage_radius_outer__()
{
  ConVar::ConVar(
    this: &score_hostage_proximity_damage_radius_outer,
    pName: "score_hostage_proximity_damage_radius_outer",
    pDefaultValue: "600",
    flags: 128,
    pHelpString: "Outer radius (zero bonus) for doing damage near hostage");
  return atexit(func: dynamic_atexit_destructor_for__score_hostage_proximity_damage_radius_outer__);
}

//------------------------------------------------------------------------------
// Address: 0x1040E4D0
// Name: _dynamic_initializer_for__score_dropped_bomb_proximity_damage_bonus__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__score_dropped_bomb_proximity_damage_bonus__()
{
  ConVar::ConVar(
    this: &score_dropped_bomb_proximity_damage_bonus,
    pName: "score_dropped_bomb_proximity_damage_bonus",
    pDefaultValue: "1",
    flags: 128,
    pHelpString: "Points awarded for damaging enemy near dropped bomb");
  return atexit(func: dynamic_atexit_destructor_for__score_dropped_bomb_proximity_damage_bonus__);
}

//------------------------------------------------------------------------------
// Address: 0x1040E500
// Name: _dynamic_initializer_for__score_dropped_bomb_proximity_damage_bonus_radius_inner__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__score_dropped_bomb_proximity_damage_bonus_radius_inner__()
{
  ConVar::ConVar(
    this: &score_dropped_bomb_proximity_damage_bonus_radius_inner,
    pName: "score_dropped_bomb_proximity_damage_bonus_radius_inner",
    pDefaultValue: "120",
    flags: 128,
    pHelpString: "Inner radius (full bonus) for doing damage near dropped bomb");
  return atexit(func: dynamic_atexit_destructor_for__score_dropped_bomb_proximity_damage_bonus_radius_inner__);
}

//------------------------------------------------------------------------------
// Address: 0x1040E530
// Name: _dynamic_initializer_for__score_dropped_bomb_proximity_damage_bonus_radius_outer__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__score_dropped_bomb_proximity_damage_bonus_radius_outer__()
{
  ConVar::ConVar(
    this: &score_dropped_bomb_proximity_damage_bonus_radius_outer,
    pName: "score_dropped_bomb_proximity_damage_bonus_radius_outer",
    pDefaultValue: "600",
    flags: 128,
    pHelpString: "Outer radius (zero bonus) for doing damage near dropped bomb");
  return atexit(func: dynamic_atexit_destructor_for__score_dropped_bomb_proximity_damage_bonus_radius_outer__);
}

//------------------------------------------------------------------------------
// Address: 0x1040E560
// Name: _dynamic_initializer_for__score_dropped_defuser_proximity_damage_bonus__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__score_dropped_defuser_proximity_damage_bonus__()
{
  ConVar::ConVar(
    this: &score_dropped_defuser_proximity_damage_bonus,
    pName: "score_dropped_defuser_proximity_damage_bonus",
    pDefaultValue: "1",
    flags: 128,
    pHelpString: "Points awarded for damaging enemy near dropped defuser");
  return atexit(func: dynamic_atexit_destructor_for__score_dropped_defuser_proximity_damage_bonus__);
}

//------------------------------------------------------------------------------
// Address: 0x1040E590
// Name: _dynamic_initializer_for__score_dropped_defuser_proximity_damage_radius_inner__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__score_dropped_defuser_proximity_damage_radius_inner__()
{
  ConVar::ConVar(
    this: &score_dropped_defuser_proximity_damage_radius_inner,
    pName: "score_dropped_defuser_proximity_damage_radius_inner",
    pDefaultValue: "120",
    flags: 128,
    pHelpString: "Inner radius (full bonus) for doing damage near dropped defuser");
  return atexit(func: dynamic_atexit_destructor_for__score_dropped_defuser_proximity_damage_radius_inner__);
}

//------------------------------------------------------------------------------
// Address: 0x1040E5C0
// Name: _dynamic_initializer_for__score_dropped_defuser_proximity_damage_radius_outer__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__score_dropped_defuser_proximity_damage_radius_outer__()
{
  ConVar::ConVar(
    this: &score_dropped_defuser_proximity_damage_radius_outer,
    pName: "score_dropped_defuser_proximity_damage_radius_outer",
    pDefaultValue: "600",
    flags: 128,
    pHelpString: "Outer radius (zero bonus) for doing damage near dropped defuser");
  return atexit(func: dynamic_atexit_destructor_for__score_dropped_defuser_proximity_damage_radius_outer__);
}

//------------------------------------------------------------------------------
// Address: 0x1040E5F0
// Name: _dynamic_initializer_for__score_bomb_plant_bonus__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__score_bomb_plant_bonus__()
{
  ConVar::ConVar(
    this: &score_bomb_plant_bonus,
    pName: "score_bomb_plant_bonus",
    pDefaultValue: "200",
    flags: 128,
    pHelpString: "Points awarded for planting or assisting with planting the bomb");
  return atexit(func: dynamic_atexit_destructor_for__score_bomb_plant_bonus__);
}

//------------------------------------------------------------------------------
// Address: 0x1040E620
// Name: _dynamic_initializer_for__score_bomb_plant_radius_inner__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__score_bomb_plant_radius_inner__()
{
  ConVar::ConVar(
    this: &score_bomb_plant_radius_inner,
    pName: "score_bomb_plant_radius_inner",
    pDefaultValue: "120",
    flags: 128,
    pHelpString: "Inner radius (full bonus) for planting or assisting with planting the bomb");
  return atexit(func: dynamic_atexit_destructor_for__score_bomb_plant_radius_inner__);
}

//------------------------------------------------------------------------------
// Address: 0x1040E650
// Name: _dynamic_initializer_for__score_bomb_plant_radius_outer__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__score_bomb_plant_radius_outer__()
{
  ConVar::ConVar(
    this: &score_bomb_plant_radius_outer,
    pName: "score_bomb_plant_radius_outer",
    pDefaultValue: "600",
    flags: 128,
    pHelpString: "Outer radius (zero bonus) for planting or assisting with planting the bomb");
  return atexit(func: dynamic_atexit_destructor_for__score_bomb_plant_radius_outer__);
}

//------------------------------------------------------------------------------
// Address: 0x1040E680
// Name: _dynamic_initializer_for__score_bomb_defuse_bonus__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__score_bomb_defuse_bonus__()
{
  ConVar::ConVar(
    this: &score_bomb_defuse_bonus,
    pName: "score_bomb_defuse_bonus",
    pDefaultValue: "400",
    flags: 128,
    pHelpString: "Points awarded for defusing or assisting with defuse of bomb");
  return atexit(func: dynamic_atexit_destructor_for__score_bomb_defuse_bonus__);
}

//------------------------------------------------------------------------------
// Address: 0x1040E6B0
// Name: _dynamic_initializer_for__score_bomb_defuse_radius_inner__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__score_bomb_defuse_radius_inner__()
{
  ConVar::ConVar(
    this: &score_bomb_defuse_radius_inner,
    pName: "score_bomb_defuse_radius_inner",
    pDefaultValue: "120",
    flags: 128,
    pHelpString: "Inner radius (full bonus) for defusing or assisting with defusing the bomb");
  return atexit(func: dynamic_atexit_destructor_for__score_bomb_defuse_radius_inner__);
}

//------------------------------------------------------------------------------
// Address: 0x1040E6E0
// Name: _dynamic_initializer_for__score_bomb_defuse_radius_outer__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__score_bomb_defuse_radius_outer__()
{
  ConVar::ConVar(
    this: &score_bomb_defuse_radius_outer,
    pName: "score_bomb_defuse_radius_outer",
    pDefaultValue: "600",
    flags: 128,
    pHelpString: "Outer radius (zero bonus) for defusing or assisting with defseing the bomb");
  return atexit(func: dynamic_atexit_destructor_for__score_bomb_defuse_radius_outer__);
}

//------------------------------------------------------------------------------
// Address: 0x1040E710
// Name: _dynamic_initializer_for__score_hostage_rescue_bonus__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__score_hostage_rescue_bonus__()
{
  ConVar::ConVar(
    this: &score_hostage_rescue_bonus,
    pName: "score_hostage_rescue_bonus",
    pDefaultValue: "100",
    flags: 128,
    pHelpString: "Points awarded for rescuing a hostage");
  return atexit(func: dynamic_atexit_destructor_for__score_hostage_rescue_bonus__);
}

//------------------------------------------------------------------------------
// Address: 0x1040E740
// Name: _dynamic_initializer_for__score_hostage_rescue_radius_inner__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__score_hostage_rescue_radius_inner__()
{
  ConVar::ConVar(
    this: &score_hostage_rescue_radius_inner,
    pName: "score_hostage_rescue_radius_inner",
    pDefaultValue: "120",
    flags: 128,
    pHelpString: "Inner radius (full bonus) for rescuing hostage");
  return atexit(func: dynamic_atexit_destructor_for__score_hostage_rescue_radius_inner__);
}

//------------------------------------------------------------------------------
// Address: 0x1040E770
// Name: _dynamic_initializer_for__score_hostage_rescue_radius_outer__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__score_hostage_rescue_radius_outer__()
{
  ConVar::ConVar(
    this: &score_hostage_rescue_radius_outer,
    pName: "score_hostage_rescue_radius_outer",
    pDefaultValue: "600",
    flags: 128,
    pHelpString: "Outer radius (zero bonus) for rescuing hostage");
  return atexit(func: dynamic_atexit_destructor_for__score_hostage_rescue_radius_outer__);
}

//------------------------------------------------------------------------------
// Address: 0x1040E7A0
// Name: _dynamic_initializer_for__score_hostage_damage_penalty__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__score_hostage_damage_penalty__()
{
  ConVar::ConVar(
    this: &score_hostage_damage_penalty,
    pName: "score_hostage_damage_penalty",
    pDefaultValue: "2",
    flags: 128,
    pHelpString: "Penalty for damaging a hostage");
  return atexit(func: dynamic_atexit_destructor_for__score_hostage_damage_penalty__);
}

//------------------------------------------------------------------------------
// Address: 0x1040E7D0
// Name: _dynamic_initializer_for__score_blind_enemy_bonus__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__score_blind_enemy_bonus__()
{
  ConVar::ConVar(
    this: &score_blind_enemy_bonus,
    pName: "score_blind_enemy_bonus",
    pDefaultValue: "10",
    flags: 128,
    pHelpString: "Bonus for blinding enemy players");
  return atexit(func: dynamic_atexit_destructor_for__score_blind_enemy_bonus__);
}

//------------------------------------------------------------------------------
// Address: 0x1040E800
// Name: _dynamic_initializer_for__score_blind_friendly_penalty__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__score_blind_friendly_penalty__()
{
  ConVar::ConVar(
    this: &score_blind_friendly_penalty,
    pName: "score_blind_friendly_penalty",
    pDefaultValue: "10",
    flags: 128,
    pHelpString: "Penalty for blinding friendly players");
  return atexit(func: dynamic_atexit_destructor_for__score_blind_friendly_penalty__);
}

//------------------------------------------------------------------------------
// Address: 0x1040E830
// Name: _dynamic_initializer_for__score_typical_good_score__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__score_typical_good_score__()
{
  ConVar::ConVar(
    this: &score_typical_good_score,
    pName: "score_typical_good_score",
    pDefaultValue: "200",
    flags: 128,
    pHelpString: "An average good score for use in funfacts");
  return atexit(func: dynamic_atexit_destructor_for__score_typical_good_score__);
}

//------------------------------------------------------------------------------
// Address: 0x1040E860
// Name: _dynamic_initializer_for__contributionscore_assist__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__contributionscore_assist__()
{
  ConVar::ConVar(
    this: &contributionscore_assist,
    pName: "contributionscore_assist",
    pDefaultValue: "1",
    flags: 128,
    pHelpString: "amount of contribution score added for an assist");
  return atexit(func: dynamic_atexit_destructor_for__contributionscore_assist__);
}

//------------------------------------------------------------------------------
// Address: 0x1040E890
// Name: _dynamic_initializer_for__contributionscore_kill__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__contributionscore_kill__()
{
  ConVar::ConVar(
    this: &contributionscore_kill,
    pName: "contributionscore_kill",
    pDefaultValue: "2",
    flags: 128,
    pHelpString: "amount of contribution score added for a kill");
  return atexit(func: dynamic_atexit_destructor_for__contributionscore_kill__);
}

//------------------------------------------------------------------------------
// Address: 0x1040E8C0
// Name: _dynamic_initializer_for__contributionscore_objective_kill__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__contributionscore_objective_kill__()
{
  ConVar::ConVar(
    this: &contributionscore_objective_kill,
    pName: "contributionscore_objective_kill",
    pDefaultValue: "4",
    flags: 128,
    pHelpString: "amount of contribution score added for an objective related kill");
  return atexit(func: dynamic_atexit_destructor_for__contributionscore_objective_kill__);
}

//------------------------------------------------------------------------------
// Address: 0x1040E8F0
// Name: _dynamic_initializer_for__contributionscore_hostage_rescue__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__contributionscore_hostage_rescue__()
{
  ConVar::ConVar(
    this: &contributionscore_hostage_rescue,
    pName: "contributionscore_hostage_rescue",
    pDefaultValue: "2",
    flags: 128,
    pHelpString: "amount of contribution score added per hostage rescued");
  return atexit(func: dynamic_atexit_destructor_for__contributionscore_hostage_rescue__);
}

//------------------------------------------------------------------------------
// Address: 0x1040E920
// Name: _dynamic_initializer_for__contributionscore_bomb_defuse__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__contributionscore_bomb_defuse__()
{
  ConVar::ConVar(
    this: &contributionscore_bomb_defuse,
    pName: "contributionscore_bomb_defuse",
    pDefaultValue: "6",
    flags: 128,
    pHelpString: "amount of contribution score for defusing a bomb");
  return atexit(func: dynamic_atexit_destructor_for__contributionscore_bomb_defuse__);
}

//------------------------------------------------------------------------------
// Address: 0x1040E950
// Name: _dynamic_initializer_for__contributionscore_bomb_planted__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__contributionscore_bomb_planted__()
{
  ConVar::ConVar(
    this: &contributionscore_bomb_planted,
    pName: "contributionscore_bomb_planted",
    pDefaultValue: "2",
    flags: 128,
    pHelpString: "amount of contribution score for planting a bomb");
  return atexit(func: dynamic_atexit_destructor_for__contributionscore_bomb_planted__);
}

//------------------------------------------------------------------------------
// Address: 0x1040E980
// Name: _dynamic_initializer_for__contributionscore_suicide__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__contributionscore_suicide__()
{
  ConVar::ConVar(
    this: &contributionscore_suicide,
    pName: "contributionscore_suicide",
    pDefaultValue: "-2",
    flags: 128,
    pHelpString: "amount of contribution score for a suicide, normally negative");
  return atexit(func: dynamic_atexit_destructor_for__contributionscore_suicide__);
}

//------------------------------------------------------------------------------
// Address: 0x1040E9B0
// Name: _dynamic_initializer_for__contributionscore_team_kill__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__contributionscore_team_kill__()
{
  ConVar::ConVar(
    this: &contributionscore_team_kill,
    pName: "contributionscore_team_kill",
    pDefaultValue: "-2",
    flags: 128,
    pHelpString: "amount of contribution score for a team kill, normally negative");
  return atexit(func: dynamic_atexit_destructor_for__contributionscore_team_kill__);
}

//------------------------------------------------------------------------------
// Address: 0x1040E9E0
// Name: _dynamic_initializer_for__contributionscore_hostage_kill__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__contributionscore_hostage_kill__()
{
  ConVar::ConVar(
    this: &contributionscore_hostage_kill,
    pName: "contributionscore_hostage_kill",
    pDefaultValue: "-2",
    flags: 128,
    pHelpString: "amount of contribution score for killing a hostage, normally negative");
  return atexit(func: dynamic_atexit_destructor_for__contributionscore_hostage_kill__);
}

//------------------------------------------------------------------------------
// Address: 0x1041F540
// Name: _dynamic_atexit_destructor_for__mp_buytime__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mp_buytime__()
{
  ConVar::~ConVar(this: &mp_buytime);
}

//------------------------------------------------------------------------------
// Address: 0x1041F550
// Name: _dynamic_atexit_destructor_for__mp_gungameimmunitytime__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mp_gungameimmunitytime__()
{
  ConVar::~ConVar(this: &mp_gungameimmunitytime);
}

//------------------------------------------------------------------------------
// Address: 0x1041F560
// Name: _dynamic_atexit_destructor_for__mp_playerid__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mp_playerid__()
{
  ConVar::~ConVar(this: &mp_playerid);
}

//------------------------------------------------------------------------------
// Address: 0x1041F570
// Name: _dynamic_atexit_destructor_for__mp_playerid_delay__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mp_playerid_delay__()
{
  ConVar::~ConVar(this: &mp_playerid_delay);
}

//------------------------------------------------------------------------------
// Address: 0x1041F580
// Name: _dynamic_atexit_destructor_for__mp_playerid_hold__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mp_playerid_hold__()
{
  ConVar::~ConVar(this: &mp_playerid_hold);
}

//------------------------------------------------------------------------------
// Address: 0x1041F590
// Name: _dynamic_atexit_destructor_for__mp_round_restart_delay__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mp_round_restart_delay__()
{
  ConVar::~ConVar(this: &mp_round_restart_delay);
}

//------------------------------------------------------------------------------
// Address: 0x1041F5A0
// Name: _dynamic_atexit_destructor_for__mp_ggprogressive_round_restart_delay__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mp_ggprogressive_round_restart_delay__()
{
  ConVar::~ConVar(this: &mp_ggprogressive_round_restart_delay);
}

//------------------------------------------------------------------------------
// Address: 0x1041F5B0
// Name: _dynamic_atexit_destructor_for__mp_ggprogressive_win_panel_pct__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mp_ggprogressive_win_panel_pct__()
{
  ConVar::~ConVar(this: &mp_ggprogressive_win_panel_pct);
}

//------------------------------------------------------------------------------
// Address: 0x1041F5C0
// Name: _dynamic_atexit_destructor_for__mp_ggselect_match_bestof_win__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mp_ggselect_match_bestof_win__()
{
  ConVar::~ConVar(this: &mp_ggselect_match_bestof_win);
}

//------------------------------------------------------------------------------
// Address: 0x1041F5D0
// Name: _dynamic_atexit_destructor_for__mp_ggtr_bomb_pts_for_upgrade__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mp_ggtr_bomb_pts_for_upgrade__()
{
  ConVar::~ConVar(this: &mp_ggtr_bomb_pts_for_upgrade);
}

//------------------------------------------------------------------------------
// Address: 0x1041F5E0
// Name: _dynamic_atexit_destructor_for__mp_ggtr_bomb_pts_for_he__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mp_ggtr_bomb_pts_for_he__()
{
  ConVar::~ConVar(this: &mp_ggtr_bomb_pts_for_he);
}

//------------------------------------------------------------------------------
// Address: 0x1041F5F0
// Name: _dynamic_atexit_destructor_for__mp_ggtr_bomb_pts_for_flash__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mp_ggtr_bomb_pts_for_flash__()
{
  ConVar::~ConVar(this: &mp_ggtr_bomb_pts_for_flash);
}

//------------------------------------------------------------------------------
// Address: 0x1041F600
// Name: _dynamic_atexit_destructor_for__mp_ggtr_bomb_pts_for_molotov__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mp_ggtr_bomb_pts_for_molotov__()
{
  ConVar::~ConVar(this: &mp_ggtr_bomb_pts_for_molotov);
}

//------------------------------------------------------------------------------
// Address: 0x1041F610
// Name: _dynamic_atexit_destructor_for__mp_molotovusedelay__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mp_molotovusedelay__()
{
  ConVar::~ConVar(this: &mp_molotovusedelay);
}

//------------------------------------------------------------------------------
// Address: 0x1041F620
// Name: _dynamic_atexit_destructor_for__mp_ggtr_halftime_delay__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mp_ggtr_halftime_delay__()
{
  ConVar::~ConVar(this: &mp_ggtr_halftime_delay);
}

//------------------------------------------------------------------------------
// Address: 0x1041F630
// Name: _dynamic_atexit_destructor_for__mp_ggtr_bomb_respawn_delay__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mp_ggtr_bomb_respawn_delay__()
{
  ConVar::~ConVar(this: &mp_ggtr_bomb_respawn_delay);
}

//------------------------------------------------------------------------------
// Address: 0x1041F640
// Name: _dynamic_atexit_destructor_for__mp_ggtr_bomb_defuse_bonus__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mp_ggtr_bomb_defuse_bonus__()
{
  ConVar::~ConVar(this: &mp_ggtr_bomb_defuse_bonus);
}

//------------------------------------------------------------------------------
// Address: 0x1041F650
// Name: _dynamic_atexit_destructor_for__mp_ggtr_bomb_detonation_bonus__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mp_ggtr_bomb_detonation_bonus__()
{
  ConVar::~ConVar(this: &mp_ggtr_bomb_detonation_bonus);
}

//------------------------------------------------------------------------------
// Address: 0x1041F660
// Name: _dynamic_atexit_destructor_for__mp_ggtr_rounds_per_half__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mp_ggtr_rounds_per_half__()
{
  ConVar::~ConVar(this: &mp_ggtr_rounds_per_half);
}

//------------------------------------------------------------------------------
// Address: 0x1041F670
// Name: _dynamic_atexit_destructor_for__mp_match_end_restart__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mp_match_end_restart__()
{
  ConVar::~ConVar(this: &mp_match_end_restart);
}

//------------------------------------------------------------------------------
// Address: 0x1041F680
// Name: _dynamic_atexit_destructor_for__mp_defuser_allocation__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mp_defuser_allocation__()
{
  ConVar::~ConVar(this: &mp_defuser_allocation);
}

//------------------------------------------------------------------------------
// Address: 0x1041F690
// Name: _dynamic_atexit_destructor_for__mp_death_drop_gun__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mp_death_drop_gun__()
{
  ConVar::~ConVar(this: &mp_death_drop_gun);
}

//------------------------------------------------------------------------------
// Address: 0x1041F6A0
// Name: _dynamic_atexit_destructor_for__mp_death_drop_grenade__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mp_death_drop_grenade__()
{
  ConVar::~ConVar(this: &mp_death_drop_grenade);
}

//------------------------------------------------------------------------------
// Address: 0x1041F6B0
// Name: _dynamic_atexit_destructor_for__mp_death_drop_defuser__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mp_death_drop_defuser__()
{
  ConVar::~ConVar(this: &mp_death_drop_defuser);
}

//------------------------------------------------------------------------------
// Address: 0x1041F6C0
// Name: _dynamic_atexit_destructor_for__mp_force_pick_time__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mp_force_pick_time__()
{
  ConVar::~ConVar(this: &mp_force_pick_time);
}

//------------------------------------------------------------------------------
// Address: 0x1041F6D0
// Name: _dynamic_atexit_destructor_for__mp_startmoney__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mp_startmoney__()
{
  ConVar::~ConVar(this: &mp_startmoney);
}

//------------------------------------------------------------------------------
// Address: 0x1041F6E0
// Name: _dynamic_atexit_destructor_for__mp_roundtime__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mp_roundtime__()
{
  ConVar::~ConVar(this: &mp_roundtime);
}

//------------------------------------------------------------------------------
// Address: 0x1041F6F0
// Name: _dynamic_atexit_destructor_for__mp_freezetime__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mp_freezetime__()
{
  ConVar::~ConVar(this: &mp_freezetime);
}

//------------------------------------------------------------------------------
// Address: 0x1041F700
// Name: _dynamic_atexit_destructor_for__mp_c4timer__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mp_c4timer__()
{
  ConVar::~ConVar(this: &mp_c4timer);
}

//------------------------------------------------------------------------------
// Address: 0x1041F710
// Name: _dynamic_atexit_destructor_for__mp_limitteams__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mp_limitteams__()
{
  ConVar::~ConVar(this: &mp_limitteams);
}

//------------------------------------------------------------------------------
// Address: 0x1041F720
// Name: _dynamic_atexit_destructor_for__mp_tkpunish__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mp_tkpunish__()
{
  ConVar::~ConVar(this: &mp_tkpunish);
}

//------------------------------------------------------------------------------
// Address: 0x1041F730
// Name: _dynamic_atexit_destructor_for__mp_autokick__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mp_autokick__()
{
  ConVar::~ConVar(this: &mp_autokick);
}

//------------------------------------------------------------------------------
// Address: 0x1041F740
// Name: _dynamic_atexit_destructor_for__mp_spawnprotectiontime__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mp_spawnprotectiontime__()
{
  ConVar::~ConVar(this: &mp_spawnprotectiontime);
}

//------------------------------------------------------------------------------
// Address: 0x1041F750
// Name: _dynamic_atexit_destructor_for__mp_humanteam__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mp_humanteam__()
{
  ConVar::~ConVar(this: &mp_humanteam);
}

//------------------------------------------------------------------------------
// Address: 0x1041F760
// Name: _dynamic_atexit_destructor_for__mp_ignore_round_win_conditions__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mp_ignore_round_win_conditions__()
{
  ConVar::~ConVar(this: &mp_ignore_round_win_conditions);
}

//------------------------------------------------------------------------------
// Address: 0x1041F770
// Name: _dynamic_atexit_destructor_for__mp_required_vote_majority__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mp_required_vote_majority__()
{
  ConVar::~ConVar(this: &mp_required_vote_majority);
}

//------------------------------------------------------------------------------
// Address: 0x1041F780
// Name: _dynamic_atexit_destructor_for__mp_required_voters__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mp_required_voters__()
{
  ConVar::~ConVar(this: &mp_required_voters);
}

//------------------------------------------------------------------------------
// Address: 0x1041F790
// Name: _dynamic_atexit_destructor_for__mp_vote_time__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mp_vote_time__()
{
  ConVar::~ConVar(this: &mp_vote_time);
}

//------------------------------------------------------------------------------
// Address: 0x1041F7A0
// Name: _dynamic_atexit_destructor_for__EndRound__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__EndRound__()
{
  ConCommand::~ConCommand(this: &EndRound);
}

//------------------------------------------------------------------------------
// Address: 0x1041F7B0
// Name: _dynamic_atexit_destructor_for__score_default__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__score_default__()
{
  ConVar::~ConVar(this: &score_default);
}

//------------------------------------------------------------------------------
// Address: 0x1041F7C0
// Name: _dynamic_atexit_destructor_for__score_kill_enemy_bonus__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__score_kill_enemy_bonus__()
{
  ConVar::~ConVar(this: &score_kill_enemy_bonus);
}

//------------------------------------------------------------------------------
// Address: 0x1041F7D0
// Name: _dynamic_atexit_destructor_for__score_damage__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__score_damage__()
{
  ConVar::~ConVar(this: &score_damage);
}

//------------------------------------------------------------------------------
// Address: 0x1041F7E0
// Name: _dynamic_atexit_destructor_for__score_ff_damage__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__score_ff_damage__()
{
  ConVar::~ConVar(this: &score_ff_damage);
}

//------------------------------------------------------------------------------
// Address: 0x1041F7F0
// Name: _dynamic_atexit_destructor_for__score_team_damage_bonus__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__score_team_damage_bonus__()
{
  ConVar::~ConVar(this: &score_team_damage_bonus);
}

//------------------------------------------------------------------------------
// Address: 0x1041F800
// Name: _dynamic_atexit_destructor_for__score_planted_bomb_proximity_damage_bonus__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__score_planted_bomb_proximity_damage_bonus__()
{
  ConVar::~ConVar(this: &score_planted_bomb_proximity_damage_bonus);
}

//------------------------------------------------------------------------------
// Address: 0x1041F810
// Name: _dynamic_atexit_destructor_for__score_planted_bomb_proximity_damage_radius_inner__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__score_planted_bomb_proximity_damage_radius_inner__()
{
  ConVar::~ConVar(this: &score_planted_bomb_proximity_damage_radius_inner);
}

//------------------------------------------------------------------------------
// Address: 0x1041F820
// Name: _dynamic_atexit_destructor_for__score_planted_bomb_proximity_damage_radius_outer__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__score_planted_bomb_proximity_damage_radius_outer__()
{
  ConVar::~ConVar(this: &score_planted_bomb_proximity_damage_radius_outer);
}

//------------------------------------------------------------------------------
// Address: 0x1041F830
// Name: _dynamic_atexit_destructor_for__score_hostage_proximity_damage_bonus__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__score_hostage_proximity_damage_bonus__()
{
  ConVar::~ConVar(this: &score_hostage_proximity_damage_bonus);
}

//------------------------------------------------------------------------------
// Address: 0x1041F840
// Name: _dynamic_atexit_destructor_for__score_hostage_proximity_damage_radius_inner__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__score_hostage_proximity_damage_radius_inner__()
{
  ConVar::~ConVar(this: &score_hostage_proximity_damage_radius_inner);
}

//------------------------------------------------------------------------------
// Address: 0x1041F850
// Name: _dynamic_atexit_destructor_for__score_hostage_proximity_damage_radius_outer__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__score_hostage_proximity_damage_radius_outer__()
{
  ConVar::~ConVar(this: &score_hostage_proximity_damage_radius_outer);
}

//------------------------------------------------------------------------------
// Address: 0x1041F860
// Name: _dynamic_atexit_destructor_for__score_dropped_bomb_proximity_damage_bonus__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__score_dropped_bomb_proximity_damage_bonus__()
{
  ConVar::~ConVar(this: &score_dropped_bomb_proximity_damage_bonus);
}

//------------------------------------------------------------------------------
// Address: 0x1041F870
// Name: _dynamic_atexit_destructor_for__score_dropped_bomb_proximity_damage_bonus_radius_inner__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__score_dropped_bomb_proximity_damage_bonus_radius_inner__()
{
  ConVar::~ConVar(this: &score_dropped_bomb_proximity_damage_bonus_radius_inner);
}

//------------------------------------------------------------------------------
// Address: 0x1041F880
// Name: _dynamic_atexit_destructor_for__score_dropped_bomb_proximity_damage_bonus_radius_outer__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__score_dropped_bomb_proximity_damage_bonus_radius_outer__()
{
  ConVar::~ConVar(this: &score_dropped_bomb_proximity_damage_bonus_radius_outer);
}

//------------------------------------------------------------------------------
// Address: 0x1041F890
// Name: _dynamic_atexit_destructor_for__score_dropped_defuser_proximity_damage_bonus__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__score_dropped_defuser_proximity_damage_bonus__()
{
  ConVar::~ConVar(this: &score_dropped_defuser_proximity_damage_bonus);
}

//------------------------------------------------------------------------------
// Address: 0x1041F8A0
// Name: _dynamic_atexit_destructor_for__score_dropped_defuser_proximity_damage_radius_inner__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__score_dropped_defuser_proximity_damage_radius_inner__()
{
  ConVar::~ConVar(this: &score_dropped_defuser_proximity_damage_radius_inner);
}

//------------------------------------------------------------------------------
// Address: 0x1041F8B0
// Name: _dynamic_atexit_destructor_for__score_dropped_defuser_proximity_damage_radius_outer__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__score_dropped_defuser_proximity_damage_radius_outer__()
{
  ConVar::~ConVar(this: &score_dropped_defuser_proximity_damage_radius_outer);
}

//------------------------------------------------------------------------------
// Address: 0x1041F8C0
// Name: _dynamic_atexit_destructor_for__score_bomb_plant_bonus__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__score_bomb_plant_bonus__()
{
  ConVar::~ConVar(this: &score_bomb_plant_bonus);
}

//------------------------------------------------------------------------------
// Address: 0x1041F8D0
// Name: _dynamic_atexit_destructor_for__score_bomb_plant_radius_inner__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__score_bomb_plant_radius_inner__()
{
  ConVar::~ConVar(this: &score_bomb_plant_radius_inner);
}

//------------------------------------------------------------------------------
// Address: 0x1041F8E0
// Name: _dynamic_atexit_destructor_for__score_bomb_plant_radius_outer__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__score_bomb_plant_radius_outer__()
{
  ConVar::~ConVar(this: &score_bomb_plant_radius_outer);
}

//------------------------------------------------------------------------------
// Address: 0x1041F8F0
// Name: _dynamic_atexit_destructor_for__score_bomb_defuse_bonus__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__score_bomb_defuse_bonus__()
{
  ConVar::~ConVar(this: &score_bomb_defuse_bonus);
}

//------------------------------------------------------------------------------
// Address: 0x1041F900
// Name: _dynamic_atexit_destructor_for__score_bomb_defuse_radius_inner__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__score_bomb_defuse_radius_inner__()
{
  ConVar::~ConVar(this: &score_bomb_defuse_radius_inner);
}

//------------------------------------------------------------------------------
// Address: 0x1041F910
// Name: _dynamic_atexit_destructor_for__score_bomb_defuse_radius_outer__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__score_bomb_defuse_radius_outer__()
{
  ConVar::~ConVar(this: &score_bomb_defuse_radius_outer);
}

//------------------------------------------------------------------------------
// Address: 0x1041F920
// Name: _dynamic_atexit_destructor_for__score_hostage_rescue_bonus__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__score_hostage_rescue_bonus__()
{
  ConVar::~ConVar(this: &score_hostage_rescue_bonus);
}

//------------------------------------------------------------------------------
// Address: 0x1041F930
// Name: _dynamic_atexit_destructor_for__score_hostage_rescue_radius_inner__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__score_hostage_rescue_radius_inner__()
{
  ConVar::~ConVar(this: &score_hostage_rescue_radius_inner);
}

//------------------------------------------------------------------------------
// Address: 0x1041F940
// Name: _dynamic_atexit_destructor_for__score_hostage_rescue_radius_outer__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__score_hostage_rescue_radius_outer__()
{
  ConVar::~ConVar(this: &score_hostage_rescue_radius_outer);
}

//------------------------------------------------------------------------------
// Address: 0x1041F950
// Name: _dynamic_atexit_destructor_for__score_hostage_damage_penalty__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__score_hostage_damage_penalty__()
{
  ConVar::~ConVar(this: &score_hostage_damage_penalty);
}

//------------------------------------------------------------------------------
// Address: 0x1041F960
// Name: _dynamic_atexit_destructor_for__score_blind_enemy_bonus__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__score_blind_enemy_bonus__()
{
  ConVar::~ConVar(this: &score_blind_enemy_bonus);
}

//------------------------------------------------------------------------------
// Address: 0x1041F970
// Name: _dynamic_atexit_destructor_for__score_blind_friendly_penalty__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__score_blind_friendly_penalty__()
{
  ConVar::~ConVar(this: &score_blind_friendly_penalty);
}

//------------------------------------------------------------------------------
// Address: 0x1041F980
// Name: _dynamic_atexit_destructor_for__score_typical_good_score__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__score_typical_good_score__()
{
  ConVar::~ConVar(this: &score_typical_good_score);
}

//------------------------------------------------------------------------------
// Address: 0x1041F990
// Name: _dynamic_atexit_destructor_for__contributionscore_assist__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__contributionscore_assist__()
{
  ConVar::~ConVar(this: &contributionscore_assist);
}

//------------------------------------------------------------------------------
// Address: 0x1041F9A0
// Name: _dynamic_atexit_destructor_for__contributionscore_kill__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__contributionscore_kill__()
{
  ConVar::~ConVar(this: &contributionscore_kill);
}

//------------------------------------------------------------------------------
// Address: 0x1041F9B0
// Name: _dynamic_atexit_destructor_for__contributionscore_objective_kill__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__contributionscore_objective_kill__()
{
  ConVar::~ConVar(this: &contributionscore_objective_kill);
}

//------------------------------------------------------------------------------
// Address: 0x1041F9C0
// Name: _dynamic_atexit_destructor_for__contributionscore_hostage_rescue__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__contributionscore_hostage_rescue__()
{
  ConVar::~ConVar(this: &contributionscore_hostage_rescue);
}

//------------------------------------------------------------------------------
// Address: 0x1041F9D0
// Name: _dynamic_atexit_destructor_for__contributionscore_bomb_defuse__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__contributionscore_bomb_defuse__()
{
  ConVar::~ConVar(this: &contributionscore_bomb_defuse);
}

//------------------------------------------------------------------------------
// Address: 0x1041F9E0
// Name: _dynamic_atexit_destructor_for__contributionscore_bomb_planted__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__contributionscore_bomb_planted__()
{
  ConVar::~ConVar(this: &contributionscore_bomb_planted);
}

//------------------------------------------------------------------------------
// Address: 0x1041F9F0
// Name: _dynamic_atexit_destructor_for__contributionscore_suicide__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__contributionscore_suicide__()
{
  ConVar::~ConVar(this: &contributionscore_suicide);
}

//------------------------------------------------------------------------------
// Address: 0x1041FA00
// Name: _dynamic_atexit_destructor_for__contributionscore_team_kill__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__contributionscore_team_kill__()
{
  ConVar::~ConVar(this: &contributionscore_team_kill);
}

//------------------------------------------------------------------------------
// Address: 0x1041FA10
// Name: _dynamic_atexit_destructor_for__contributionscore_hostage_kill__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__contributionscore_hostage_kill__()
{
  ConVar::~ConVar(this: &contributionscore_hostage_kill);
}
