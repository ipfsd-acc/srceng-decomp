// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/cstrike15/c_te_shotgun_shot.cpp
// Functions: 19
// ============================================================

#include "game\client\cstrike15\c_te_shotgun_shot.h"

//------------------------------------------------------------------------------
// Address: 0x101BFF50
// Name: public: virtual void C_TEFireBullets::PostDataUpdate(enum DataUpdateType_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_TEFireBullets::PostDataUpdate(C_TEFireBullets *this, DataUpdateType_t updateType)
{
  int m_iMode; // eax
  CSWeaponID m_iWeaponID; // edx

  m_iMode = this->m_iMode;
  m_iWeaponID = this->m_iWeaponID;
  this->m_vecAngles.y = 0.0;
  FX_FireBullets(
    iPlayerIndex: (int)&this->m_pNextDynamic->C_BaseTempEntity::__vftable + 1,
    vOrigin: (const Vector *)&this->m_iPlayer,
    vAngles: (const QAngle *)&this->m_vecOrigin.z,
    iWeaponID: SLODWORD(this->m_vecAngles.z),
    iMode: m_iWeaponID,
    iSeed: m_iMode,
    fInaccuracy: *(float *)&this->m_iSeed,
    fSpread: this->m_fInaccuracy,
    flSoundTime: 0.0);
}

//------------------------------------------------------------------------------
// Address: 0x101BFFA0
// Name: public: virtual class ClientClass __near * C_TEFireBullets::GetClientClass(void)
// Source: json
//------------------------------------------------------------------------------
ClientClass *__thiscall C_TEFireBullets::GetClientClass(C_TEFireBullets *this)
{
  return &__g_C_TEFireBulletsClientClass;
}

//------------------------------------------------------------------------------
// Address: 0x101BFFC0
// Name: public: virtual void C_TEPlantBomb::PostDataUpdate(enum DataUpdateType_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_TEPlantBomb::PostDataUpdate(C_TEPlantBomb *this, DataUpdateType_t updateType)
{
  FX_PlantBomb(
    iPlayerIndex: (int)&this->m_pNextDynamic->C_BaseTempEntity::__vftable + 1,
    vOrigin: (const Vector *)&this->m_iPlayer,
    option: SLODWORD(this->m_vecOrigin.z));
}

//------------------------------------------------------------------------------
// Address: 0x101BFFE0
// Name: public: virtual class ClientClass __near * C_TEPlantBomb::GetClientClass(void)
// Source: json
//------------------------------------------------------------------------------
ClientClass *__thiscall C_TEPlantBomb::GetClientClass(C_TEPlantBomb *this)
{
  return &__g_C_TEPlantBombClientClass;
}

//------------------------------------------------------------------------------
// Address: 0x104224B0
// Name: DT_TEFireBullets::_dynamic_initializer_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
int DT_TEFireBullets::_dynamic_initializer_for__g_RecvTable__()
{
  RecvTable::RecvTable(this: &DT_TEFireBullets::g_RecvTable);
  return atexit(func: DT_TEFireBullets::_dynamic_atexit_destructor_for__g_RecvTable__);
}

//------------------------------------------------------------------------------
// Address: 0x104224D0
// Name: DT_TEFireBullets::_dynamic_initializer_for__g_RecvTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_TEFireBullets::_dynamic_initializer_for__g_RecvTableInit__()
{
  int result; // eax

  result = ClientClassInit<DT_TEFireBullets::ignored>();
  DT_TEFireBullets::g_RecvTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10422530
// Name: DT_TEPlantBomb::_dynamic_initializer_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
int DT_TEPlantBomb::_dynamic_initializer_for__g_RecvTable__()
{
  RecvTable::RecvTable(this: &DT_TEPlantBomb::g_RecvTable);
  return atexit(func: DT_TEPlantBomb::_dynamic_atexit_destructor_for__g_RecvTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10422550
// Name: DT_TEPlantBomb::_dynamic_initializer_for__g_RecvTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_TEPlantBomb::_dynamic_initializer_for__g_RecvTableInit__()
{
  int result; // eax

  result = ClientClassInit<DT_TEPlantBomb::ignored>();
  DT_TEPlantBomb::g_RecvTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10435370
// Name: DT_TEFireBullets::_dynamic_atexit_destructor_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_TEFireBullets::_dynamic_atexit_destructor_for__g_RecvTable__()
{
  C_BaseAnimating::ShutdownBoneSetupThreadPool(this: (vgui::PropertyPage *)&DT_TEFireBullets::g_RecvTable);
}

//------------------------------------------------------------------------------
// Address: 0x10435380
// Name: DT_TEPlantBomb::_dynamic_atexit_destructor_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_TEPlantBomb::_dynamic_atexit_destructor_for__g_RecvTable__()
{
  C_BaseAnimating::ShutdownBoneSetupThreadPool(this: (vgui::PropertyPage *)&DT_TEPlantBomb::g_RecvTable);
}

//------------------------------------------------------------------------------
// Address: 0x101BFFB0
// Name: _C_TEFireBullets_CreateObject
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IClientNetworkable *__cdecl C_TEFireBullets_CreateObject()
{
  return &_g_C_TEFireBullets.IClientNetworkable;
}

//------------------------------------------------------------------------------
// Address: 0x101BFFF0
// Name: _C_TEPlantBomb_CreateObject
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IClientNetworkable *__cdecl C_TEPlantBomb_CreateObject()
{
  return &_g_C_TEPlantBomb.IClientNetworkable;
}

//------------------------------------------------------------------------------
// Address: 0x104224E0
// Name: _dynamic_initializer_for____g_C_TEPlantBomb__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for____g_C_TEPlantBomb__()
{
  C_BaseTempEntity::C_BaseTempEntity(this: &_g_C_TEPlantBomb);
  _g_C_TEPlantBomb.C_BaseTempEntity::IClientUnknown::IHandleEntity::__vftable = (C_TEPlantBomb_vtbl *)&C_TEPlantBomb::`vftable'{for `IClientUnknown'};
  _g_C_TEPlantBomb.C_BaseTempEntity::IClientNetworkable::__vftable = (IClientNetworkable_vtbl *)&C_TEPlantBomb::`vftable'{for `IClientNetworkable'};
  return atexit(func: dynamic_atexit_destructor_for____g_C_TEPlantBomb__);
}

//------------------------------------------------------------------------------
// Address: 0x10422510
// Name: _dynamic_initializer_for____g_C_TEPlantBombClientClass__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ClientClass *dynamic_initializer_for____g_C_TEPlantBombClientClass__()
{
  ClientClass *result; // eax

  result = g_pClientClassHead;
  __g_C_TEPlantBombClientClass.m_pNext = g_pClientClassHead;
  g_pClientClassHead = &__g_C_TEPlantBombClientClass;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10422560
// Name: _dynamic_initializer_for__default_fov__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__default_fov__()
{
  ConVar::ConVar(this: &default_fov, pName: "default_fov", pDefaultValue: "90", flags: 0x4000);
  return atexit(func: dynamic_atexit_destructor_for__default_fov__);
}

//------------------------------------------------------------------------------
// Address: 0x10422590
// Name: _dynamic_initializer_for____g_C_WeaponCyclerClientClass__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ClientClass *dynamic_initializer_for____g_C_WeaponCyclerClientClass__()
{
  ClientClass *result; // eax

  result = g_pClientClassHead;
  __g_C_WeaponCyclerClientClass.m_pNext = g_pClientClassHead;
  g_pClientClassHead = &__g_C_WeaponCyclerClientClass;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10435390
// Name: _dynamic_atexit_destructor_for____g_C_TEFireBullets__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for____g_C_TEFireBullets__()
{
  C_BaseTempEntity::~C_BaseTempEntity(this: &_g_C_TEFireBullets);
}

//------------------------------------------------------------------------------
// Address: 0x104353A0
// Name: _dynamic_atexit_destructor_for____g_C_TEPlantBomb__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for____g_C_TEPlantBomb__()
{
  C_BaseTempEntity::~C_BaseTempEntity(this: &_g_C_TEPlantBomb);
}

//------------------------------------------------------------------------------
// Address: 0x104353B0
// Name: _dynamic_atexit_destructor_for__default_fov__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__default_fov__()
{
  ConVar::~ConVar(this: &default_fov);
}
