// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/shared/cstrike15/weapon_aug.cpp
// Functions: 15
// ============================================================

#include "game\shared\cstrike15\weapon_aug.h"

//------------------------------------------------------------------------------
// Address: 0x10228DF0
// Name: public: virtual class ClientClass __near * C_WeaponAug::GetClientClass(void)
// Source: json
//------------------------------------------------------------------------------
ClientClass *__thiscall C_WeaponAug::GetClientClass(C_WeaponAug *this)
{
  return &__g_C_WeaponAugClientClass;
}

//------------------------------------------------------------------------------
// Address: 0x10228E70
// Name: public: virtual struct datamap_t __near * C_WeaponAug::GetPredDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall C_WeaponAug::GetPredDescMap(C_WeaponAug *this)
{
  return &C_WeaponAug::m_PredMap;
}

//------------------------------------------------------------------------------
// Address: 0x10228E80
// Name: public: virtual void weapon_augPrecache::CResourcePrecacher::Cache(class IPrecacheHandler __near *,bool,struct ResourceList_t__ __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall weapon_augPrecache::CResourcePrecacher::Cache(
        weapon_augPrecache::CResourcePrecacher *this,
        IPrecacheHandler *pPrecacheHandler,
        BOOL bPrecache,
        struct ResourceList_t__ *hResourceList,
        bool bIgnoreConditionals)
{
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: ENTITY,
    a3: "weapon_aug",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x10228EC0
// Name: public: virtual void C_WeaponAug::PrimaryAttack(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_WeaponAug::PrimaryAttack(C_WeaponAug *this)
{
  int v2; // eax
  int v3; // esi
  float flCycleTime; // xmm0_4
  C_BaseEntity *v5; // eax
  C_CSPlayer *v6; // esi
  int m_fFlags; // eax
  float v8; // [esp+40h] [ebp-18h]
  bool v9; // [esp+4Bh] [ebp-Dh]

  C_WeaponCSBase::GetPlayerOwner(this);
  v3 = v2;
  if ( v2 != 0 )
  {
    v8 = ((double (__thiscall *)(int))*(_DWORD *)(*(_DWORD *)v2 + 1148))(a1: v2);
    v9 = (double)(*(int (__thiscall **)(int))(*(_DWORD *)v3 + 1152))(a1: v3) > v8;
    flCycleTime = C_WeaponCSBase::GetCSWpnData(this)->m_flCycleTime;
    if ( v9 )
      flCycleTime = 0.13500001;
    if ( C_WeaponCSBaseGun::CSBaseGunFire(this, flCycleTime, weaponMode: this->m_weaponMode.m_Value) )
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
                up_base: 0.57499999,
                lateral_base: 0.32499999,
                up_modifier: 0.2,
                lateral_modifier: 0.011,
                up_max: 3.25,
                lateral_max: 2.0,
                direction_change: (IUniformRandomStream *)8);
            else
              C_CSPlayer::KickBack(
                this: v6,
                up_base: 0.625,
                lateral_base: 0.375,
                up_modifier: 0.25,
                lateral_modifier: 0.0125,
                up_max: 3.5,
                lateral_max: 2.25,
                direction_change: (IUniformRandomStream *)8);
          }
          else
          {
            C_CSPlayer::KickBack(
              this: v6,
              up_base: 1.25,
              lateral_base: 0.44999999,
              up_modifier: 0.22,
              lateral_modifier: 0.18000001,
              up_max: 5.5,
              lateral_max: 4.0,
              direction_change: (IUniformRandomStream *)5);
          }
        }
        else
        {
          C_CSPlayer::KickBack(
            this: v6,
            up_base: 1.0,
            lateral_base: 0.44999999,
            up_modifier: 0.27500001,
            lateral_modifier: 0.050000001,
            up_max: 4.0,
            lateral_max: 2.5,
            direction_change: (IUniformRandomStream *)7);
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10229140
// Name: public: virtual void C_WeaponAug::SecondaryAttack(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_WeaponAug::SecondaryAttack(C_WeaponAug *this)
{
  C_BasePlayer *v2; // eax
  C_BasePlayer *v3; // esi
  CSWeaponMode m_Value; // eax
  int v5; // eax
  float v6; // xmm0_4

  C_WeaponCSBase::GetPlayerOwner(this);
  v3 = v2;
  if ( v2 != nullptr )
  {
    m_Value = this->m_weaponMode.m_Value;
    if ( m_Value != Primary_Mode )
    {
      if ( m_Value == Secondary_Mode )
      {
        v5 = v3->GetDefaultFOV(this: v3);
        C_BasePlayer::SetFOV(this: v3, pRequester: v3, FOV: v5, zoomRate: 0.15000001, iZoomStart: 0);
        if ( this->m_weaponMode.m_Value != Primary_Mode )
          this->m_weaponMode.m_Value = Primary_Mode;
      }
    }
    else
    {
      C_BasePlayer::SetFOV(this: v3, pRequester: v3, FOV: 55, zoomRate: 0.2, iZoomStart: 0);
      if ( this->m_weaponMode.m_Value != Secondary_Mode )
        this->m_weaponMode.m_Value = Secondary_Mode;
    }
    v6 = *(float *)(gpGlobals.m_Index + 12) + 0.3;
    if ( this->m_flNextSecondaryAttack.m_Value != v6 )
      this->m_flNextSecondaryAttack.m_Value = v6;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10229270
// Name: CC_WeaponAugFactory
// Source: json
//------------------------------------------------------------------------------
C_BaseEntity *__cdecl CC_WeaponAugFactory()
{
  C_WeaponCSBaseGun *v0; // eax
  _DWORD *v1; // esi

  v0 = (C_WeaponCSBaseGun *)C_BaseEntity::operator new(stAllocateBlock: 0xDB0u);
  v1 = &v0->C_WeaponCSBase::C_BaseCombatWeapon::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable;
  if ( v0 == nullptr )
    return nullptr;
  C_WeaponCSBaseGun::C_WeaponCSBaseGun(this: v0);
  *v1 = &C_WeaponAug::`vftable'{for `IClientUnknown'};
  v1[1] = &C_WeaponAug::`vftable'{for `IClientRenderable'};
  v1[2] = &C_WeaponAug::`vftable'{for `IClientNetworkable'};
  v1[3] = &C_WeaponAug::`vftable'{for `IClientThinkable'};
  v1[4] = &C_WeaponAug::`vftable';
  return (C_BaseEntity *)v1;
}

//------------------------------------------------------------------------------
// Address: 0x10341890
// Name: public: virtual enum CSWeaponID C_WeaponAug::GetCSWeaponID(void)const
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall C_WeaponAug::GetCSWeaponID(CParticleOperatorDefinition<C_OP_ModelCull> *this)
{
  return 6;
}

//------------------------------------------------------------------------------
// Address: 0x10427BF0
// Name: DT_WeaponAug::_dynamic_initializer_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
int DT_WeaponAug::_dynamic_initializer_for__g_RecvTable__()
{
  RecvTable::RecvTable(this: &DT_WeaponAug::g_RecvTable);
  return atexit(func: DT_WeaponAug::_dynamic_atexit_destructor_for__g_RecvTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10427C10
// Name: DT_WeaponAug::_dynamic_initializer_for__g_RecvTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_WeaponAug::_dynamic_initializer_for__g_RecvTableInit__()
{
  int result; // eax

  result = ClientClassInit<DT_WeaponAug::ignored>();
  DT_WeaponAug::g_RecvTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10427C20
// Name: C_WeaponAug_PredDataDescInit::_dynamic_initializer_for__g_PredMapHolder__
// Source: json
//------------------------------------------------------------------------------
void C_WeaponAug_PredDataDescInit::_dynamic_initializer_for__g_PredMapHolder__()
{
  C_WeaponAug::m_PredMap.dataNumFields = 1;
  C_WeaponAug::m_PredMap.dataDesc = (typedescription_t *)&unk_10669F04;
}

//------------------------------------------------------------------------------
// Address: 0x10427C70
// Name: weapon_augPrecache::_dynamic_initializer_for__s_ResourcePrecacher__
// Source: json
//------------------------------------------------------------------------------
CBaseResourcePrecacher *weapon_augPrecache::_dynamic_initializer_for__s_ResourcePrecacher__()
{
  CBaseResourcePrecacher *result; // eax

  result = CBaseResourcePrecacher::sm_pFirst[0];
  weapon_augPrecache::s_ResourcePrecacher.m_pNext = CBaseResourcePrecacher::sm_pFirst[0];
  CBaseResourcePrecacher::sm_pFirst[0] = &weapon_augPrecache::s_ResourcePrecacher;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10435E20
// Name: DT_WeaponAug::_dynamic_atexit_destructor_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_WeaponAug::_dynamic_atexit_destructor_for__g_RecvTable__()
{
  C_BaseAnimating::ShutdownBoneSetupThreadPool(this: (vgui::PropertyPage *)&DT_WeaponAug::g_RecvTable);
}

//------------------------------------------------------------------------------
// Address: 0x10229200
// Name: _C_WeaponAug_CreateObject
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IClientNetworkable *__cdecl C_WeaponAug_CreateObject(int entnum, int serialNum)
{
  C_WeaponCSBaseGun *v2; // eax
  _DWORD *v3; // esi

  v2 = (C_WeaponCSBaseGun *)C_BaseEntity::operator new(stAllocateBlock: 0xDB0u);
  v3 = &v2->C_WeaponCSBase::C_BaseCombatWeapon::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable;
  if ( v2 == nullptr )
    return nullptr;
  C_WeaponCSBaseGun::C_WeaponCSBaseGun(this: v2);
  *v3 = &C_WeaponAug::`vftable'{for `IClientUnknown'};
  v3[1] = &C_WeaponAug::`vftable'{for `IClientRenderable'};
  v3[2] = &C_WeaponAug::`vftable'{for `IClientNetworkable'};
  v3[3] = &C_WeaponAug::`vftable'{for `IClientThinkable'};
  v3[4] = &C_WeaponAug::`vftable';
  (*(void (__thiscall **)(_DWORD *, int, int))(*v3 + 172))(a1: v3, a2: entnum, a3: serialNum);
  return (IClientNetworkable *)(v3 + 2);
}

//------------------------------------------------------------------------------
// Address: 0x10427C40
// Name: _dynamic_initializer_for__g_Cweapon_augFoo__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_Cweapon_augFoo__()
{
  CClassMap *ClassMap; // eax
  int result; // eax

  ClassMap = GetClassMap();
  result = ((int (__thiscall *)(CClassMap *, const char *, const char *, int, C_BaseEntity *(__cdecl *)()))ClassMap->Add)(
             a1: ClassMap,
             a2: "weapon_aug",
             a3: "C_WeaponAug",
             a4: 3504,
             a5: CC_WeaponAugFactory);
  __g_C_WeaponAugClientClass.m_pMapClassname = "weapon_aug";
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10427C90
// Name: _dynamic_initializer_for____g_C_WeaponAWPClientClass__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ClientClass *dynamic_initializer_for____g_C_WeaponAWPClientClass__()
{
  ClientClass *result; // eax

  result = g_pClientClassHead;
  __g_C_WeaponAWPClientClass.m_pNext = g_pClientClassHead;
  g_pClientClassHead = &__g_C_WeaponAWPClientClass;
  return result;
}

// ============================================================
// Overlay from server (Missing functions)
// ============================================================
namespace server {

//------------------------------------------------------------------------------
// Address: 0x102E2E30
// Name: public: virtual class ServerClass __near * CWeaponAug::GetServerClass(void)
// Source: json
//------------------------------------------------------------------------------
ServerClass *__thiscall CWeaponAug::GetServerClass(CWeaponAug *this)
{
  return &g_CWeaponAug_ClassReg;
}

//------------------------------------------------------------------------------
// Address: 0x102E2E40
// Name: public: virtual void weapon_augPrecache::CResourcePrecacher::Cache(class IPrecacheHandler __near *,bool,struct ResourceList_t__ __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall weapon_augPrecache::CResourcePrecacher::Cache(
        weapon_augPrecache::CResourcePrecacher *this,
        IPrecacheHandler *pPrecacheHandler,
        BOOL bPrecache,
        struct ResourceList_t__ *hResourceList,
        bool bIgnoreConditionals)
{
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: ENTITY,
    a3: "weapon_aug",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x102E2EF0
// Name: public: virtual void CWeaponAug::PrimaryAttack(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CWeaponAug::PrimaryAttack(CWeaponAug *this@<ecx>, int a2@<ebp>)
{
  CCSPlayer *PlayerOwner; // eax
  CBasePlayer *v4; // edi
  float flCycleTime; // xmm0_4
  CCSPlayer *v6; // esi
  int m_Value; // eax
  int FOV; // [esp+44h] [ebp-14h]
  bool v9; // [esp+4Bh] [ebp-Dh]
  _DWORD v10[2]; // [esp+4Ch] [ebp-Ch] BYREF
  _UNKNOWN *retaddr; // [esp+58h] [ebp+0h]

  v10[0] = a2;
  v10[1] = retaddr;
  PlayerOwner = CWeaponCSBase::GetPlayerOwner(this);
  v4 = PlayerOwner;
  if ( PlayerOwner != nullptr )
  {
    FOV = CBasePlayer::GetFOV(this: PlayerOwner);
    v9 = FOV < CBasePlayer::GetDefaultFOV(this: v4);
    flCycleTime = CWeaponCSBase::GetCSWpnData(this)->m_flCycleTime;
    if ( v9 )
      flCycleTime = 0.13500001;
    if ( CWeaponCSBaseGun::CSBaseGunFire(this, flCycleTime, weaponMode: this->m_weaponMode.m_Value) )
    {
      v6 = CWeaponCSBase::GetPlayerOwner(this);
      if ( v6 != nullptr
        && weapon_recoil_legacy.m_pParent != nullptr
        && weapon_recoil_legacy.m_pParent->m_Value.m_nValue != 0 )
      {
        if ( (v6->m_iEFlags & 0x1000) != 0 )
          CBaseEntity::CalcAbsoluteVelocity(this: v6, a2: (int)v10);
        if ( fsqrt(
               (float)(v6->m_vecAbsVelocity.x * v6->m_vecAbsVelocity.x)
             + (float)(v6->m_vecAbsVelocity.y * v6->m_vecAbsVelocity.y)) <= 5.0 )
        {
          m_Value = v6->m_fFlags.m_Value;
          if ( (m_Value & 1) != 0 )
          {
            if ( (m_Value & 2) != 0 )
              CCSPlayer::KickBack(
                this: v6,
                up_base: 0.57499999,
                lateral_base: 0.32499999,
                up_modifier: 0.2,
                lateral_modifier: 0.011,
                up_max: 3.25,
                lateral_max: 2.0,
                direction_change: (IUniformRandomStream *)8);
            else
              CCSPlayer::KickBack(
                this: v6,
                up_base: 0.625,
                lateral_base: 0.375,
                up_modifier: 0.25,
                lateral_modifier: 0.0125,
                up_max: 3.5,
                lateral_max: 2.25,
                direction_change: (IUniformRandomStream *)8);
          }
          else
          {
            CCSPlayer::KickBack(
              this: v6,
              up_base: 1.25,
              lateral_base: 0.44999999,
              up_modifier: 0.22,
              lateral_modifier: 0.18000001,
              up_max: 5.5,
              lateral_max: 4.0,
              direction_change: (IUniformRandomStream *)5);
          }
        }
        else
        {
          CCSPlayer::KickBack(
            this: v6,
            up_base: 1.0,
            lateral_base: 0.44999999,
            up_modifier: 0.27500001,
            lateral_modifier: 0.050000001,
            up_max: 4.0,
            lateral_max: 2.5,
            direction_change: (IUniformRandomStream *)7);
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102E3160
// Name: public: virtual void CWeaponAug::SecondaryAttack(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWeaponAug::SecondaryAttack(CWeaponAug *this)
{
  CCSPlayer *PlayerOwner; // edi
  CSWeaponMode m_Value; // eax
  int DefaultFOV; // eax
  edict_t *m_pPev; // ecx
  edict_t *v6; // ecx
  float v7; // xmm0_4
  edict_t *v8; // ecx

  PlayerOwner = CWeaponCSBase::GetPlayerOwner(this);
  if ( PlayerOwner != nullptr )
  {
    m_Value = this->m_weaponMode.m_Value;
    if ( m_Value != Primary_Mode )
    {
      if ( m_Value == Secondary_Mode )
      {
        DefaultFOV = CBasePlayer::GetDefaultFOV(this: PlayerOwner);
        CBasePlayer::SetFOV(
          this: PlayerOwner,
          pRequester: PlayerOwner,
          FOV: DefaultFOV,
          zoomRate: 0.15000001,
          iZoomStart: 0);
        if ( this->m_weaponMode.m_Value != Primary_Mode )
        {
          if ( this->m_Network.m_TimerEvent.m_bRegistered )
          {
            *((_BYTE *)&this->m_Network + 76) |= 1u;
            this->m_weaponMode.m_Value = Primary_Mode;
          }
          else
          {
            m_pPev = this->m_Network.m_pPev;
            if ( m_pPev != nullptr )
              CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x57Cu);
            this->m_weaponMode.m_Value = Primary_Mode;
          }
        }
      }
    }
    else
    {
      CBasePlayer::SetFOV(this: PlayerOwner, pRequester: PlayerOwner, FOV: 55, zoomRate: 0.2, iZoomStart: 0);
      if ( this->m_weaponMode.m_Value != Secondary_Mode )
      {
        if ( this->m_Network.m_TimerEvent.m_bRegistered )
        {
          *((_BYTE *)&this->m_Network + 76) |= 1u;
        }
        else
        {
          v6 = this->m_Network.m_pPev;
          if ( v6 != nullptr )
            CBaseEdict::StateChanged(this: &v6->CBaseEdict, offset: 0x57Cu);
        }
        this->m_weaponMode.m_Value = Secondary_Mode;
      }
    }
    v7 = gpGlobals->curtime + 0.3;
    if ( this->m_flNextSecondaryAttack.m_Value != v7 )
    {
      if ( this->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&this->m_Network + 76) |= 1u;
        this->m_flNextSecondaryAttack.m_Value = v7;
      }
      else
      {
        v8 = this->m_Network.m_pPev;
        if ( v8 != nullptr )
          CBaseEdict::StateChanged(this: &v8->CBaseEdict, offset: 0x498u);
        this->m_flNextSecondaryAttack.m_Value = v7;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102E32C0
// Name: public: virtual enum CSWeaponID CWeaponAug::GetCSWeaponID(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CWeaponAug::GetCSWeaponID(CWeaponAug *this)
{
  return 6;
}

//------------------------------------------------------------------------------
// Address: 0x10411D30
// Name: DT_WeaponAug::_dynamic_initializer_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
int DT_WeaponAug::_dynamic_initializer_for__g_SendTable__()
{
  SendTable::SendTable(this: &DT_WeaponAug::g_SendTable);
  return atexit(func: DT_WeaponAug::_dynamic_atexit_destructor_for__g_SendTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10411D50
// Name: DT_WeaponAug::_dynamic_initializer_for__g_SendTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_WeaponAug::_dynamic_initializer_for__g_SendTableInit__()
{
  int result; // eax

  result = ServerClassInit<DT_WeaponAug::ignored>();
  DT_WeaponAug::g_SendTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10411D80
// Name: weapon_augPrecache::_dynamic_initializer_for__s_ResourcePrecacher__
// Source: json
//------------------------------------------------------------------------------
int weapon_augPrecache::_dynamic_initializer_for__s_ResourcePrecacher__()
{
  int result; // eax

  result = dword_106DA8A4;
  weapon_augPrecache::s_ResourcePrecacher.m_pNext = (IResourcePrecacher *)dword_106DA8A4;
  dword_106DA8A4 = (int)&weapon_augPrecache::s_ResourcePrecacher;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10420710
// Name: DT_WeaponAug::_dynamic_atexit_destructor_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_WeaponAug::_dynamic_atexit_destructor_for__g_SendTable__()
{
  CAI_BaseNPC::OnSetSchedule(this: (vgui::Panel *)&DT_WeaponAug::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x10411DA0
// Name: _dynamic_initializer_for__g_CWeaponAWP_ClassReg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ServerClass *dynamic_initializer_for__g_CWeaponAWP_ClassReg__()
{
  return ServerClass::ServerClass(
           this: &g_CWeaponAWP_ClassReg,
           pNetworkName: "CWeaponAWP",
           pTable: &DT_WeaponAWP::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x10420720
// Name: _ServerClassInit_DT_WeaponAug::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ServerClassInit_DT_WeaponAug::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__()
{
  SendProp *v0; // esi
  int i; // edi

  v0 = (SendProp *)&_S2_267;
  for ( i = 1; i >= 0; --i )
    SendProp::~SendProp(this: --v0);
}

} // namespace server
