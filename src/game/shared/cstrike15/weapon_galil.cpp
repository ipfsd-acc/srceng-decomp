// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/shared/cstrike15/weapon_galil.cpp
// Functions: 14
// ============================================================

#include "game\shared\cstrike15\weapon_galil.h"

//------------------------------------------------------------------------------
// Address: 0x1022F1E0
// Name: public: virtual class ClientClass __near * C_WeaponGalil::GetClientClass(void)
// Source: json
//------------------------------------------------------------------------------
ClientClass *__thiscall C_WeaponGalil::GetClientClass(C_WeaponGalil *this)
{
  return &__g_C_WeaponGalilClientClass;
}

//------------------------------------------------------------------------------
// Address: 0x1022F260
// Name: public: virtual struct datamap_t __near * C_WeaponGalil::GetPredDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall C_WeaponGalil::GetPredDescMap(C_WeaponGalil *this)
{
  return &C_WeaponGalil::m_PredMap;
}

//------------------------------------------------------------------------------
// Address: 0x1022F270
// Name: public: virtual void weapon_galilPrecache::CResourcePrecacher::Cache(class IPrecacheHandler __near *,bool,struct ResourceList_t__ __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall weapon_galilPrecache::CResourcePrecacher::Cache(
        weapon_galilPrecache::CResourcePrecacher *this,
        IPrecacheHandler *pPrecacheHandler,
        BOOL bPrecache,
        struct ResourceList_t__ *hResourceList,
        bool bIgnoreConditionals)
{
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: ENTITY,
    a3: "weapon_galil",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x1022F2A0
// Name: public: virtual void C_WeaponGalil::PrimaryAttack(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_WeaponGalil::PrimaryAttack(C_WeaponGalil *this)
{
  int v2; // eax
  float v3; // xmm0_4
  const CCSWeaponInfo *CSWpnData; // eax
  C_BaseEntity *v5; // eax
  C_CSPlayer *v6; // esi
  int m_fFlags; // eax

  C_WeaponCSBase::GetPlayerOwner(this);
  if ( v2 != 0 )
  {
    if ( *(_BYTE *)(v2 + 594) == 3 )
    {
      C_WeaponCSBase::PlayEmptySound(this);
      v3 = *(float *)(gpGlobals.m_Index + 12) + 0.15;
      if ( this->m_flNextPrimaryAttack.m_Value != v3 )
        this->m_flNextPrimaryAttack.m_Value = v3;
    }
    else
    {
      CSWpnData = C_WeaponCSBase::GetCSWpnData(this);
      if ( C_WeaponCSBaseGun::CSBaseGunFire(this, flCycleTime: CSWpnData->m_flCycleTime, weaponMode: Primary_Mode) != 0 )
      {
        C_WeaponCSBase::GetPlayerOwner(this);
        v6 = (C_CSPlayer *)v5;
        if ( v5 != nullptr
          && weapon_recoil_legacy.m_pParent != nullptr
          && weapon_recoil_legacy.m_pParent->m_Value.m_nValue != 0 )
        {
          C_BaseEntity::CalcAbsoluteVelocity(this: v5);
          if ( fsqrt(
                 (float)(v6->m_vecAbsVelocity.x * v6->m_vecAbsVelocity.x)
               + (float)(v6->m_vecAbsVelocity.y * v6->m_vecAbsVelocity.y)) <= 5.0 )
          {
            m_fFlags = v6->m_fFlags;
            if ( (m_fFlags & 1) != 0 )
            {
              if ( (m_fFlags & 2) != 0 )
                C_CSPlayer::KickBack(
                  this: v6,
                  up_base: 0.60000002,
                  lateral_base: 0.30000001,
                  up_modifier: 0.2,
                  lateral_modifier: 0.0125,
                  up_max: 3.25,
                  lateral_max: 2.0,
                  direction_change: (IUniformRandomStream *)7);
              else
                C_CSPlayer::KickBack(
                  this: v6,
                  up_base: 0.64999998,
                  lateral_base: 0.34999999,
                  up_modifier: 0.25,
                  lateral_modifier: 0.015,
                  up_max: 3.5,
                  lateral_max: 2.25,
                  direction_change: (IUniformRandomStream *)7);
            }
            else
            {
              C_CSPlayer::KickBack(
                this: v6,
                up_base: 1.2,
                lateral_base: 0.5,
                up_modifier: 0.23,
                lateral_modifier: 0.15000001,
                up_max: 5.5,
                lateral_max: 3.5,
                direction_change: (IUniformRandomStream *)6);
            }
          }
          else
          {
            C_CSPlayer::KickBack(
              this: v6,
              up_base: 1.0,
              lateral_base: 0.44999999,
              up_modifier: 0.28,
              lateral_modifier: 0.045000002,
              up_max: 3.75,
              lateral_max: 3.0,
              direction_change: (IUniformRandomStream *)7);
          }
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1022F550
// Name: public: virtual enum CSWeaponID C_WeaponGalil::GetCSWeaponID(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall C_WeaponGalil::GetCSWeaponID(C_WeaponGalil *this)
{
  return 10;
}

//------------------------------------------------------------------------------
// Address: 0x1022F5D0
// Name: CC_WeaponGalilFactory
// Source: json
//------------------------------------------------------------------------------
C_BaseEntity *__cdecl CC_WeaponGalilFactory()
{
  C_WeaponCSBaseGun *v0; // eax
  _DWORD *v1; // esi

  v0 = (C_WeaponCSBaseGun *)C_BaseEntity::operator new(stAllocateBlock: 0xDB0u);
  v1 = &v0->C_WeaponCSBase::C_BaseCombatWeapon::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable;
  if ( v0 == nullptr )
    return nullptr;
  C_WeaponCSBaseGun::C_WeaponCSBaseGun(this: v0);
  *v1 = &C_WeaponGalil::`vftable'{for `IClientUnknown'};
  v1[1] = &C_WeaponGalil::`vftable'{for `IClientRenderable'};
  v1[2] = &C_WeaponGalil::`vftable'{for `IClientNetworkable'};
  v1[3] = &C_WeaponGalil::`vftable'{for `IClientThinkable'};
  v1[4] = &C_WeaponGalil::`vftable';
  return (C_BaseEntity *)v1;
}

//------------------------------------------------------------------------------
// Address: 0x10428AB0
// Name: DT_WeaponGalil::_dynamic_initializer_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
int DT_WeaponGalil::_dynamic_initializer_for__g_RecvTable__()
{
  RecvTable::RecvTable(this: &DT_WeaponGalil::g_RecvTable);
  return atexit(func: DT_WeaponGalil::_dynamic_atexit_destructor_for__g_RecvTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10428AD0
// Name: DT_WeaponGalil::_dynamic_initializer_for__g_RecvTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_WeaponGalil::_dynamic_initializer_for__g_RecvTableInit__()
{
  int result; // eax

  result = ClientClassInit<DT_WeaponGalil::ignored>();
  DT_WeaponGalil::g_RecvTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10428AE0
// Name: C_WeaponGalil_PredDataDescInit::_dynamic_initializer_for__g_PredMapHolder__
// Source: json
//------------------------------------------------------------------------------
void C_WeaponGalil_PredDataDescInit::_dynamic_initializer_for__g_PredMapHolder__()
{
  C_WeaponGalil::m_PredMap.dataNumFields = 1;
  C_WeaponGalil::m_PredMap.dataDesc = (typedescription_t *)&unk_1066B514;
}

//------------------------------------------------------------------------------
// Address: 0x10428B30
// Name: weapon_galilPrecache::_dynamic_initializer_for__s_ResourcePrecacher__
// Source: json
//------------------------------------------------------------------------------
CBaseResourcePrecacher *weapon_galilPrecache::_dynamic_initializer_for__s_ResourcePrecacher__()
{
  CBaseResourcePrecacher *result; // eax

  result = CBaseResourcePrecacher::sm_pFirst[0];
  weapon_galilPrecache::s_ResourcePrecacher.m_pNext = CBaseResourcePrecacher::sm_pFirst[0];
  CBaseResourcePrecacher::sm_pFirst[0] = &weapon_galilPrecache::s_ResourcePrecacher;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10436090
// Name: DT_WeaponGalil::_dynamic_atexit_destructor_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_WeaponGalil::_dynamic_atexit_destructor_for__g_RecvTable__()
{
  C_BaseAnimating::ShutdownBoneSetupThreadPool(this: (vgui::PropertyPage *)&DT_WeaponGalil::g_RecvTable);
}

//------------------------------------------------------------------------------
// Address: 0x1022F560
// Name: _C_WeaponGalil_CreateObject
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IClientNetworkable *__cdecl C_WeaponGalil_CreateObject(int entnum, int serialNum)
{
  C_WeaponCSBaseGun *v2; // eax
  _DWORD *v3; // esi

  v2 = (C_WeaponCSBaseGun *)C_BaseEntity::operator new(stAllocateBlock: 0xDB0u);
  v3 = &v2->C_WeaponCSBase::C_BaseCombatWeapon::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable;
  if ( v2 == nullptr )
    return nullptr;
  C_WeaponCSBaseGun::C_WeaponCSBaseGun(this: v2);
  *v3 = &C_WeaponGalil::`vftable'{for `IClientUnknown'};
  v3[1] = &C_WeaponGalil::`vftable'{for `IClientRenderable'};
  v3[2] = &C_WeaponGalil::`vftable'{for `IClientNetworkable'};
  v3[3] = &C_WeaponGalil::`vftable'{for `IClientThinkable'};
  v3[4] = &C_WeaponGalil::`vftable';
  (*(void (__thiscall **)(_DWORD *, int, int))(*v3 + 172))(a1: v3, a2: entnum, a3: serialNum);
  return (IClientNetworkable *)(v3 + 2);
}

//------------------------------------------------------------------------------
// Address: 0x10428B00
// Name: _dynamic_initializer_for__g_Cweapon_galilFoo__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_Cweapon_galilFoo__()
{
  CClassMap *ClassMap; // eax
  int result; // eax

  ClassMap = GetClassMap();
  result = ((int (__thiscall *)(CClassMap *, const char *, const char *, int, C_BaseEntity *(__cdecl *)()))ClassMap->Add)(
             a1: ClassMap,
             a2: "weapon_galil",
             a3: "C_WeaponGalil",
             a4: 3504,
             a5: CC_WeaponGalilFactory);
  __g_C_WeaponGalilClientClass.m_pMapClassname = "weapon_galil";
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10428B50
// Name: _dynamic_initializer_for____g_C_WeaponGlockClientClass__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ClientClass *dynamic_initializer_for____g_C_WeaponGlockClientClass__()
{
  ClientClass *result; // eax

  result = g_pClientClassHead;
  __g_C_WeaponGlockClientClass.m_pNext = g_pClientClassHead;
  g_pClientClassHead = &__g_C_WeaponGlockClientClass;
  return result;
}

// ============================================================
// Overlay from server (Missing functions)
// ============================================================
namespace server {

//------------------------------------------------------------------------------
// Address: 0x102EC660
// Name: public: virtual class ServerClass __near * CWeaponGalil::GetServerClass(void)
// Source: json
//------------------------------------------------------------------------------
ServerClass *__thiscall CWeaponGalil::GetServerClass(CWeaponGalil *this)
{
  return &g_CWeaponGalil_ClassReg;
}

//------------------------------------------------------------------------------
// Address: 0x102EC670
// Name: public: virtual void weapon_galilPrecache::CResourcePrecacher::Cache(class IPrecacheHandler __near *,bool,struct ResourceList_t__ __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall weapon_galilPrecache::CResourcePrecacher::Cache(
        weapon_galilPrecache::CResourcePrecacher *this,
        IPrecacheHandler *pPrecacheHandler,
        BOOL bPrecache,
        struct ResourceList_t__ *hResourceList,
        bool bIgnoreConditionals)
{
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: ENTITY,
    a3: "weapon_galil",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x102EC720
// Name: public: virtual void CWeaponGalil::PrimaryAttack(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWeaponGalil::PrimaryAttack(CWeaponGalil *this)
{
  CCSPlayer *PlayerOwner; // eax
  float v3; // xmm0_4
  edict_t *m_pPev; // ecx
  const CCSWeaponInfo *CSWpnData; // eax
  CCSPlayer *v6; // esi
  const Vector *AbsVelocity; // eax
  int m_Value; // eax
  int v9; // [esp+54h] [ebp-4h] BYREF

  PlayerOwner = CWeaponCSBase::GetPlayerOwner(this);
  if ( PlayerOwner != nullptr )
  {
    if ( PlayerOwner->m_nWaterLevel.m_Value == 3 )
    {
      CWeaponCSBase::PlayEmptySound(this);
      v3 = gpGlobals->curtime + 0.15;
      if ( this->m_flNextPrimaryAttack.m_Value != v3 )
      {
        if ( this->m_Network.m_TimerEvent.m_bRegistered )
        {
          *((_BYTE *)&this->m_Network + 76) |= 1u;
          this->m_flNextPrimaryAttack.m_Value = v3;
        }
        else
        {
          m_pPev = this->m_Network.m_pPev;
          if ( m_pPev != nullptr )
            CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x494u);
          this->m_flNextPrimaryAttack.m_Value = v3;
        }
      }
    }
    else
    {
      CSWpnData = CWeaponCSBase::GetCSWpnData(this);
      if ( CWeaponCSBaseGun::CSBaseGunFire(
             this,
             a2: (int)&v9,
             flCycleTime: CSWpnData->m_flCycleTime,
             weaponMode: Primary_Mode) != 0 )
      {
        v6 = CWeaponCSBase::GetPlayerOwner(this);
        if ( v6 != nullptr
          && weapon_recoil_legacy.m_pParent != nullptr
          && weapon_recoil_legacy.m_pParent->m_Value.m_nValue != 0 )
        {
          AbsVelocity = CBaseEntity::GetAbsVelocity(this: v6);
          if ( fsqrt((float)(AbsVelocity->x * AbsVelocity->x) + (float)(AbsVelocity->y * AbsVelocity->y)) <= 5.0 )
          {
            m_Value = v6->m_fFlags.m_Value;
            if ( (m_Value & 1) != 0 )
            {
              if ( (m_Value & 2) != 0 )
                CCSPlayer::KickBack(
                  this: v6,
                  up_base: 0.60000002,
                  lateral_base: 0.30000001,
                  up_modifier: 0.2,
                  lateral_modifier: 0.0125,
                  up_max: 3.25,
                  lateral_max: 2.0,
                  direction_change: (IUniformRandomStream *)7);
              else
                CCSPlayer::KickBack(
                  this: v6,
                  up_base: 0.64999998,
                  lateral_base: 0.34999999,
                  up_modifier: 0.25,
                  lateral_modifier: 0.015,
                  up_max: 3.5,
                  lateral_max: 2.25,
                  direction_change: (IUniformRandomStream *)7);
            }
            else
            {
              CCSPlayer::KickBack(
                this: v6,
                up_base: 1.2,
                lateral_base: 0.5,
                up_modifier: 0.23,
                lateral_modifier: 0.15000001,
                up_max: 5.5,
                lateral_max: 3.5,
                direction_change: (IUniformRandomStream *)6);
            }
          }
          else
          {
            CCSPlayer::KickBack(
              this: v6,
              up_base: 1.0,
              lateral_base: 0.44999999,
              up_modifier: 0.28,
              lateral_modifier: 0.045000002,
              up_max: 3.75,
              lateral_max: 3.0,
              direction_change: (IUniformRandomStream *)7);
          }
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102ECA00
// Name: public: virtual enum CSWeaponID CWeaponGalil::GetCSWeaponID(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CWeaponGalil::GetCSWeaponID(CWeaponGalil *this)
{
  return 10;
}

//------------------------------------------------------------------------------
// Address: 0x10412710
// Name: DT_WeaponGalil::_dynamic_initializer_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
int DT_WeaponGalil::_dynamic_initializer_for__g_SendTable__()
{
  SendTable::SendTable(this: &DT_WeaponGalil::g_SendTable);
  return atexit(func: DT_WeaponGalil::_dynamic_atexit_destructor_for__g_SendTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10412730
// Name: DT_WeaponGalil::_dynamic_initializer_for__g_SendTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_WeaponGalil::_dynamic_initializer_for__g_SendTableInit__()
{
  int result; // eax

  result = ServerClassInit<DT_WeaponGalil::ignored>();
  DT_WeaponGalil::g_SendTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10412760
// Name: weapon_galilPrecache::_dynamic_initializer_for__s_ResourcePrecacher__
// Source: json
//------------------------------------------------------------------------------
int weapon_galilPrecache::_dynamic_initializer_for__s_ResourcePrecacher__()
{
  int result; // eax

  result = dword_106DA8A4;
  weapon_galilPrecache::s_ResourcePrecacher.m_pNext = (IResourcePrecacher *)dword_106DA8A4;
  dword_106DA8A4 = (int)&weapon_galilPrecache::s_ResourcePrecacher;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10420AB0
// Name: DT_WeaponGalil::_dynamic_atexit_destructor_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_WeaponGalil::_dynamic_atexit_destructor_for__g_SendTable__()
{
  CAI_BaseNPC::OnSetSchedule(this: (vgui::Panel *)&DT_WeaponGalil::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x10412780
// Name: _dynamic_initializer_for__g_CWeaponGlock_ClassReg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ServerClass *dynamic_initializer_for__g_CWeaponGlock_ClassReg__()
{
  return ServerClass::ServerClass(
           this: &g_CWeaponGlock_ClassReg,
           pNetworkName: "CWeaponGlock",
           pTable: &DT_WeaponGlock::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x10420AC0
// Name: _ServerClassInit_DT_WeaponGalil::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ServerClassInit_DT_WeaponGalil::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__()
{
  SendProp *v0; // esi
  int i; // edi

  v0 = (SendProp *)&_S2_281;
  for ( i = 1; i >= 0; --i )
    SendProp::~SendProp(this: --v0);
}

} // namespace server
