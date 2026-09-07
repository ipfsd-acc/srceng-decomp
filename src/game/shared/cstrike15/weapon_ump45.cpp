// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/shared/cstrike15/weapon_ump45.cpp
// Functions: 14
// ============================================================

#include "game\shared\cstrike15\weapon_ump45.h"

//------------------------------------------------------------------------------
// Address: 0x10235350
// Name: public: virtual class ClientClass __near * C_WeaponUMP45::GetClientClass(void)
// Source: json
//------------------------------------------------------------------------------
ClientClass *__thiscall C_WeaponUMP45::GetClientClass(C_WeaponUMP45 *this)
{
  return &__g_C_WeaponUMP45ClientClass;
}

//------------------------------------------------------------------------------
// Address: 0x102353D0
// Name: public: virtual struct datamap_t __near * C_WeaponUMP45::GetPredDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall C_WeaponUMP45::GetPredDescMap(C_WeaponUMP45 *this)
{
  return &C_WeaponUMP45::m_PredMap;
}

//------------------------------------------------------------------------------
// Address: 0x102353E0
// Name: public: virtual void weapon_ump45Precache::CResourcePrecacher::Cache(class IPrecacheHandler __near *,bool,struct ResourceList_t__ __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall weapon_ump45Precache::CResourcePrecacher::Cache(
        weapon_ump45Precache::CResourcePrecacher *this,
        IPrecacheHandler *pPrecacheHandler,
        BOOL bPrecache,
        struct ResourceList_t__ *hResourceList,
        bool bIgnoreConditionals)
{
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: ENTITY,
    a3: "weapon_ump45",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x10235410
// Name: public: virtual void C_WeaponUMP45::PrimaryAttack(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_WeaponUMP45::PrimaryAttack(C_WeaponUMP45 *this)
{
  int v2; // eax
  const CCSWeaponInfo *CSWpnData; // eax
  int v4; // eax
  int v5; // esi

  C_WeaponCSBase::GetPlayerOwner(this);
  if ( v2 != 0 )
  {
    CSWpnData = C_WeaponCSBase::GetCSWpnData(this);
    if ( C_WeaponCSBaseGun::CSBaseGunFire(this, flCycleTime: CSWpnData->m_flCycleTime, weaponMode: Primary_Mode) != 0 )
    {
      C_WeaponCSBase::GetPlayerOwner(this);
      v5 = v4;
      if ( v4 != 0 && weapon_recoil_legacy.m_pParent != nullptr && weapon_recoil_legacy.m_pParent->m_Value.m_nValue != 0 )
      {
        if ( (*(_BYTE *)(v4 + 248) & 1) != 0 )
        {
          C_BaseEntity::CalcAbsoluteVelocity(this: (C_BaseEntity *)v4);
          if ( fsqrt(
                 (float)(*(float *)(v5 + 144) * *(float *)(v5 + 144))
               + (float)(*(float *)(v5 + 148) * *(float *)(v5 + 148))) <= 5.0 )
          {
            if ( (*(_BYTE *)(v5 + 248) & 2) != 0 )
              C_CSPlayer::KickBack(
                this: (C_CSPlayer *)v5,
                up_base: 0.25,
                lateral_base: 0.175,
                up_modifier: 0.125,
                lateral_modifier: 0.02,
                up_max: 2.25,
                lateral_max: 1.25,
                direction_change: (IUniformRandomStream *)0xA);
            else
              C_CSPlayer::KickBack(
                this: (C_CSPlayer *)v5,
                up_base: 0.27500001,
                lateral_base: 0.2,
                up_modifier: 0.15000001,
                lateral_modifier: 0.022500001,
                up_max: 2.5,
                lateral_max: 1.5,
                direction_change: (IUniformRandomStream *)0xA);
          }
          else
          {
            C_CSPlayer::KickBack(
              this: (C_CSPlayer *)v5,
              up_base: 0.55000001,
              lateral_base: 0.30000001,
              up_modifier: 0.22499999,
              lateral_modifier: 0.029999999,
              up_max: 3.5,
              lateral_max: 2.5,
              direction_change: (IUniformRandomStream *)0xA);
          }
        }
        else
        {
          C_CSPlayer::KickBack(
            this: (C_CSPlayer *)v4,
            up_base: 0.125,
            lateral_base: 0.64999998,
            up_modifier: 0.55000001,
            lateral_modifier: 0.047499999,
            up_max: 5.5,
            lateral_max: 4.0,
            direction_change: (IUniformRandomStream *)0xA);
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10235670
// Name: public: virtual enum CSWeaponID C_WeaponUMP45::GetCSWeaponID(void)const
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall C_WeaponUMP45::GetCSWeaponID(C_OP_SetPerChildControlPoint *this)
{
  return 15;
}

//------------------------------------------------------------------------------
// Address: 0x102356F0
// Name: CC_WeaponUMP45Factory
// Source: json
//------------------------------------------------------------------------------
C_BaseEntity *__cdecl CC_WeaponUMP45Factory()
{
  C_WeaponCSBaseGun *v0; // eax
  _DWORD *v1; // esi

  v0 = (C_WeaponCSBaseGun *)C_BaseEntity::operator new(stAllocateBlock: 0xDB0u);
  v1 = &v0->C_WeaponCSBase::C_BaseCombatWeapon::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable;
  if ( v0 == nullptr )
    return nullptr;
  C_WeaponCSBaseGun::C_WeaponCSBaseGun(this: v0);
  *v1 = &C_WeaponUMP45::`vftable'{for `IClientUnknown'};
  v1[1] = &C_WeaponUMP45::`vftable'{for `IClientRenderable'};
  v1[2] = &C_WeaponUMP45::`vftable'{for `IClientNetworkable'};
  v1[3] = &C_WeaponUMP45::`vftable'{for `IClientThinkable'};
  v1[4] = &C_WeaponUMP45::`vftable';
  return (C_BaseEntity *)v1;
}

//------------------------------------------------------------------------------
// Address: 0x10429C40
// Name: DT_WeaponUMP45::_dynamic_initializer_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
int DT_WeaponUMP45::_dynamic_initializer_for__g_RecvTable__()
{
  RecvTable::RecvTable(this: &DT_WeaponUMP45::g_RecvTable);
  return atexit(func: DT_WeaponUMP45::_dynamic_atexit_destructor_for__g_RecvTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10429C60
// Name: DT_WeaponUMP45::_dynamic_initializer_for__g_RecvTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_WeaponUMP45::_dynamic_initializer_for__g_RecvTableInit__()
{
  int result; // eax

  result = ClientClassInit<DT_WeaponUMP45::ignored>();
  DT_WeaponUMP45::g_RecvTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10429C70
// Name: C_WeaponUMP45_PredDataDescInit::_dynamic_initializer_for__g_PredMapHolder__
// Source: json
//------------------------------------------------------------------------------
void C_WeaponUMP45_PredDataDescInit::_dynamic_initializer_for__g_PredMapHolder__()
{
  C_WeaponUMP45::m_PredMap.dataNumFields = 1;
  C_WeaponUMP45::m_PredMap.dataDesc = (typedescription_t *)&unk_1066C9C4;
}

//------------------------------------------------------------------------------
// Address: 0x10429CC0
// Name: weapon_ump45Precache::_dynamic_initializer_for__s_ResourcePrecacher__
// Source: json
//------------------------------------------------------------------------------
CBaseResourcePrecacher *weapon_ump45Precache::_dynamic_initializer_for__s_ResourcePrecacher__()
{
  CBaseResourcePrecacher *result; // eax

  result = CBaseResourcePrecacher::sm_pFirst[0];
  weapon_ump45Precache::s_ResourcePrecacher.m_pNext = CBaseResourcePrecacher::sm_pFirst[0];
  CBaseResourcePrecacher::sm_pFirst[0] = &weapon_ump45Precache::s_ResourcePrecacher;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10436210
// Name: DT_WeaponUMP45::_dynamic_atexit_destructor_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_WeaponUMP45::_dynamic_atexit_destructor_for__g_RecvTable__()
{
  C_BaseAnimating::ShutdownBoneSetupThreadPool(this: (vgui::PropertyPage *)&DT_WeaponUMP45::g_RecvTable);
}

//------------------------------------------------------------------------------
// Address: 0x10235680
// Name: _C_WeaponUMP45_CreateObject
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IClientNetworkable *__cdecl C_WeaponUMP45_CreateObject(int entnum, int serialNum)
{
  C_WeaponCSBaseGun *v2; // eax
  _DWORD *v3; // esi

  v2 = (C_WeaponCSBaseGun *)C_BaseEntity::operator new(stAllocateBlock: 0xDB0u);
  v3 = &v2->C_WeaponCSBase::C_BaseCombatWeapon::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable;
  if ( v2 == nullptr )
    return nullptr;
  C_WeaponCSBaseGun::C_WeaponCSBaseGun(this: v2);
  *v3 = &C_WeaponUMP45::`vftable'{for `IClientUnknown'};
  v3[1] = &C_WeaponUMP45::`vftable'{for `IClientRenderable'};
  v3[2] = &C_WeaponUMP45::`vftable'{for `IClientNetworkable'};
  v3[3] = &C_WeaponUMP45::`vftable'{for `IClientThinkable'};
  v3[4] = &C_WeaponUMP45::`vftable';
  (*(void (__thiscall **)(_DWORD *, int, int))(*v3 + 172))(a1: v3, a2: entnum, a3: serialNum);
  return (IClientNetworkable *)(v3 + 2);
}

//------------------------------------------------------------------------------
// Address: 0x10429C90
// Name: _dynamic_initializer_for__g_Cweapon_ump45Foo__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_Cweapon_ump45Foo__()
{
  CClassMap *ClassMap; // eax
  int result; // eax

  ClassMap = GetClassMap();
  result = ((int (__thiscall *)(CClassMap *, const char *, const char *, int, C_BaseEntity *(__cdecl *)()))ClassMap->Add)(
             a1: ClassMap,
             a2: "weapon_ump45",
             a3: "C_WeaponUMP45",
             a4: 3504,
             a5: CC_WeaponUMP45Factory);
  __g_C_WeaponUMP45ClientClass.m_pMapClassname = "weapon_ump45";
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10429CE0
// Name: _dynamic_initializer_for____g_C_WeaponXM1014ClientClass__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ClientClass *dynamic_initializer_for____g_C_WeaponXM1014ClientClass__()
{
  ClientClass *result; // eax

  result = g_pClientClassHead;
  __g_C_WeaponXM1014ClientClass.m_pNext = g_pClientClassHead;
  g_pClientClassHead = &__g_C_WeaponXM1014ClientClass;
  return result;
}

// ============================================================
// Overlay from server (Missing functions)
// ============================================================
namespace server {

//------------------------------------------------------------------------------
// Address: 0x102F3360
// Name: public: virtual class ServerClass __near * CWeaponUMP45::GetServerClass(void)
// Source: json
//------------------------------------------------------------------------------
ServerClass *__thiscall CWeaponUMP45::GetServerClass(CWeaponUMP45 *this)
{
  return &g_CWeaponUMP45_ClassReg;
}

//------------------------------------------------------------------------------
// Address: 0x102F3370
// Name: public: virtual void weapon_ump45Precache::CResourcePrecacher::Cache(class IPrecacheHandler __near *,bool,struct ResourceList_t__ __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall weapon_ump45Precache::CResourcePrecacher::Cache(
        weapon_ump45Precache::CResourcePrecacher *this,
        IPrecacheHandler *pPrecacheHandler,
        BOOL bPrecache,
        struct ResourceList_t__ *hResourceList,
        bool bIgnoreConditionals)
{
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: ENTITY,
    a3: "weapon_ump45",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x102F3420
// Name: public: virtual void CWeaponUMP45::PrimaryAttack(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWeaponUMP45::PrimaryAttack(CWeaponUMP45 *this)
{
  const CCSWeaponInfo *CSWpnData; // eax
  CCSPlayer *PlayerOwner; // esi
  const Vector *AbsVelocity; // eax
  int v5; // [esp+44h] [ebp-4h] BYREF

  if ( CWeaponCSBase::GetPlayerOwner(this) != nullptr )
  {
    CSWpnData = CWeaponCSBase::GetCSWpnData(this);
    if ( CWeaponCSBaseGun::CSBaseGunFire(
           this,
           a2: (int)&v5,
           flCycleTime: CSWpnData->m_flCycleTime,
           weaponMode: Primary_Mode) != 0 )
    {
      PlayerOwner = CWeaponCSBase::GetPlayerOwner(this);
      if ( PlayerOwner != nullptr
        && weapon_recoil_legacy.m_pParent != nullptr
        && weapon_recoil_legacy.m_pParent->m_Value.m_nValue != 0 )
      {
        if ( (PlayerOwner->m_fFlags.m_Value & 1) != 0 )
        {
          AbsVelocity = CBaseEntity::GetAbsVelocity(this: PlayerOwner);
          if ( fsqrt((float)(AbsVelocity->x * AbsVelocity->x) + (float)(AbsVelocity->y * AbsVelocity->y)) <= 5.0 )
          {
            if ( (PlayerOwner->m_fFlags.m_Value & 2) != 0 )
              CCSPlayer::KickBack(
                this: PlayerOwner,
                up_base: 0.25,
                lateral_base: 0.175,
                up_modifier: 0.125,
                lateral_modifier: 0.02,
                up_max: 2.25,
                lateral_max: 1.25,
                direction_change: (IUniformRandomStream *)0xA);
            else
              CCSPlayer::KickBack(
                this: PlayerOwner,
                up_base: 0.27500001,
                lateral_base: 0.2,
                up_modifier: 0.15000001,
                lateral_modifier: 0.022500001,
                up_max: 2.5,
                lateral_max: 1.5,
                direction_change: (IUniformRandomStream *)0xA);
          }
          else
          {
            CCSPlayer::KickBack(
              this: PlayerOwner,
              up_base: 0.55000001,
              lateral_base: 0.30000001,
              up_modifier: 0.22499999,
              lateral_modifier: 0.029999999,
              up_max: 3.5,
              lateral_max: 2.5,
              direction_change: (IUniformRandomStream *)0xA);
          }
        }
        else
        {
          CCSPlayer::KickBack(
            this: PlayerOwner,
            up_base: 0.125,
            lateral_base: 0.64999998,
            up_modifier: 0.55000001,
            lateral_modifier: 0.047499999,
            up_max: 5.5,
            lateral_max: 4.0,
            direction_change: (IUniformRandomStream *)0xA);
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102F3680
// Name: public: virtual enum CSWeaponID CWeaponUMP45::GetCSWeaponID(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CWeaponUMP45::GetCSWeaponID(CWeaponUMP45 *this)
{
  return 15;
}

//------------------------------------------------------------------------------
// Address: 0x104134B0
// Name: DT_WeaponUMP45::_dynamic_initializer_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
int DT_WeaponUMP45::_dynamic_initializer_for__g_SendTable__()
{
  SendTable::SendTable(this: &DT_WeaponUMP45::g_SendTable);
  return atexit(func: DT_WeaponUMP45::_dynamic_atexit_destructor_for__g_SendTable__);
}

//------------------------------------------------------------------------------
// Address: 0x104134D0
// Name: DT_WeaponUMP45::_dynamic_initializer_for__g_SendTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_WeaponUMP45::_dynamic_initializer_for__g_SendTableInit__()
{
  int result; // eax

  result = ServerClassInit<DT_WeaponUMP45::ignored>();
  DT_WeaponUMP45::g_SendTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10413500
// Name: weapon_ump45Precache::_dynamic_initializer_for__s_ResourcePrecacher__
// Source: json
//------------------------------------------------------------------------------
int weapon_ump45Precache::_dynamic_initializer_for__s_ResourcePrecacher__()
{
  int result; // eax

  result = dword_106DA8A4;
  weapon_ump45Precache::s_ResourcePrecacher.m_pNext = (IResourcePrecacher *)dword_106DA8A4;
  dword_106DA8A4 = (int)&weapon_ump45Precache::s_ResourcePrecacher;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10420F80
// Name: DT_WeaponUMP45::_dynamic_atexit_destructor_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_WeaponUMP45::_dynamic_atexit_destructor_for__g_SendTable__()
{
  CAI_BaseNPC::OnSetSchedule(this: (vgui::Panel *)&DT_WeaponUMP45::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x10413520
// Name: _dynamic_initializer_for__g_CWeaponXM1014_ClassReg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ServerClass *dynamic_initializer_for__g_CWeaponXM1014_ClassReg__()
{
  return ServerClass::ServerClass(
           this: &g_CWeaponXM1014_ClassReg,
           pNetworkName: "CWeaponXM1014",
           pTable: &DT_WeaponXM1014::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x10420F90
// Name: _ServerClassInit_DT_WeaponUMP45::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ServerClassInit_DT_WeaponUMP45::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__()
{
  SendProp *v0; // esi
  int i; // edi

  v0 = (SendProp *)&_S2_304;
  for ( i = 1; i >= 0; --i )
    SendProp::~SendProp(this: --v0);
}

} // namespace server
