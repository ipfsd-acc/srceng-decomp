// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/shared/cstrike15/weapon_g3sg1.cpp
// Functions: 12
// ============================================================

#include "game\shared\cstrike15\weapon_g3sg1.h"

//------------------------------------------------------------------------------
// Address: 0x1022ED80
// Name: public: virtual class ClientClass __near * C_WeaponG3SG1::GetClientClass(void)
// Source: json
//------------------------------------------------------------------------------
ClientClass *__thiscall C_WeaponG3SG1::GetClientClass(C_WeaponG3SG1 *this)
{
  return &__g_C_WeaponG3SG1ClientClass;
}

//------------------------------------------------------------------------------
// Address: 0x1022EE00
// Name: public: virtual struct datamap_t __near * C_WeaponG3SG1::GetPredDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall C_WeaponG3SG1::GetPredDescMap(C_WeaponG3SG1 *this)
{
  return &C_WeaponG3SG1::m_PredMap;
}

//------------------------------------------------------------------------------
// Address: 0x1022EE10
// Name: public: virtual void weapon_g3sg1Precache::CResourcePrecacher::Cache(class IPrecacheHandler __near *,bool,struct ResourceList_t__ __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall weapon_g3sg1Precache::CResourcePrecacher::Cache(
        weapon_g3sg1Precache::CResourcePrecacher *this,
        IPrecacheHandler *pPrecacheHandler,
        BOOL bPrecache,
        struct ResourceList_t__ *hResourceList,
        bool bIgnoreConditionals)
{
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: ENTITY,
    a3: "weapon_g3sg1",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x1022EEA0
// Name: public: virtual void C_WeaponG3SG1::PrimaryAttack(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_WeaponG3SG1::PrimaryAttack(C_WeaponG3SG1 *this)
{
  C_BasePlayer *v2; // eax
  C_BasePlayer *v3; // esi
  const CCSWeaponInfo *CSWpnData; // eax
  CSWeaponMode m_Value; // [esp+8h] [ebp-18h]
  QAngle angle; // [esp+14h] [ebp-Ch] BYREF

  C_WeaponCSBase::GetPlayerOwner(this);
  v3 = v2;
  if ( v2 != nullptr )
  {
    m_Value = this->m_weaponMode.m_Value;
    CSWpnData = C_WeaponCSBase::GetCSWpnData(this);
    if ( C_WeaponCSBaseGun::CSBaseGunFire(this, flCycleTime: CSWpnData->m_flCycleTime, weaponMode: m_Value) != 0
      && weapon_recoil_legacy.m_pParent != nullptr
      && weapon_recoil_legacy.m_pParent->m_Value.m_nValue != 0 )
    {
      angle = *v3->GetPunchAngle(this: v3);
      angle.x = angle.x
              - (SharedRandomFloat(sharedname: "G3SG1PunchAngleX", flMinVal: 0.75, flMaxVal: 1.75, additionalSeed: 0)
               + 0.25 * angle.x);
      angle.y = SharedRandomFloat(sharedname: "G3SG1PunchAngleY", flMinVal: -0.75, flMaxVal: 0.75, additionalSeed: 0)
              + angle.y;
      C_BasePlayer::SetPunchAngle(this: v3, &angle);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1022F190
// Name: CC_WeaponG3SG1Factory
// Source: json
//------------------------------------------------------------------------------
C_BaseEntity *__cdecl CC_WeaponG3SG1Factory()
{
  C_WeaponCSBaseGun *v0; // eax
  _DWORD *v1; // esi

  v0 = (C_WeaponCSBaseGun *)C_BaseEntity::operator new(stAllocateBlock: 0xDB0u);
  v1 = &v0->C_WeaponCSBase::C_BaseCombatWeapon::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable;
  if ( v0 == nullptr )
    return nullptr;
  C_WeaponCSBaseGun::C_WeaponCSBaseGun(this: v0);
  *v1 = &C_WeaponG3SG1::`vftable'{for `IClientUnknown'};
  v1[1] = &C_WeaponG3SG1::`vftable'{for `IClientRenderable'};
  v1[2] = &C_WeaponG3SG1::`vftable'{for `IClientNetworkable'};
  v1[3] = &C_WeaponG3SG1::`vftable'{for `IClientThinkable'};
  v1[4] = &C_WeaponG3SG1::`vftable';
  return (C_BaseEntity *)v1;
}

//------------------------------------------------------------------------------
// Address: 0x104289F0
// Name: DT_WeaponG3SG1::_dynamic_initializer_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
int DT_WeaponG3SG1::_dynamic_initializer_for__g_RecvTable__()
{
  RecvTable::RecvTable(this: &DT_WeaponG3SG1::g_RecvTable);
  return atexit(func: DT_WeaponG3SG1::_dynamic_atexit_destructor_for__g_RecvTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10428A10
// Name: DT_WeaponG3SG1::_dynamic_initializer_for__g_RecvTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_WeaponG3SG1::_dynamic_initializer_for__g_RecvTableInit__()
{
  int result; // eax

  result = ClientClassInit<DT_WeaponG3SG1::ignored>();
  DT_WeaponG3SG1::g_RecvTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10428A20
// Name: C_WeaponG3SG1_PredDataDescInit::_dynamic_initializer_for__g_PredMapHolder__
// Source: json
//------------------------------------------------------------------------------
void C_WeaponG3SG1_PredDataDescInit::_dynamic_initializer_for__g_PredMapHolder__()
{
  C_WeaponG3SG1::m_PredMap.dataNumFields = 1;
  C_WeaponG3SG1::m_PredMap.dataDesc = (typedescription_t *)&unk_1066B43C;
}

//------------------------------------------------------------------------------
// Address: 0x10428A70
// Name: weapon_g3sg1Precache::_dynamic_initializer_for__s_ResourcePrecacher__
// Source: json
//------------------------------------------------------------------------------
CBaseResourcePrecacher *weapon_g3sg1Precache::_dynamic_initializer_for__s_ResourcePrecacher__()
{
  CBaseResourcePrecacher *result; // eax

  result = CBaseResourcePrecacher::sm_pFirst[0];
  weapon_g3sg1Precache::s_ResourcePrecacher.m_pNext = CBaseResourcePrecacher::sm_pFirst[0];
  CBaseResourcePrecacher::sm_pFirst[0] = &weapon_g3sg1Precache::s_ResourcePrecacher;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10436080
// Name: DT_WeaponG3SG1::_dynamic_atexit_destructor_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_WeaponG3SG1::_dynamic_atexit_destructor_for__g_RecvTable__()
{
  C_BaseAnimating::ShutdownBoneSetupThreadPool(this: (vgui::PropertyPage *)&DT_WeaponG3SG1::g_RecvTable);
}

//------------------------------------------------------------------------------
// Address: 0x10428A40
// Name: _dynamic_initializer_for__g_Cweapon_g3sg1Foo__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_Cweapon_g3sg1Foo__()
{
  CClassMap *ClassMap; // eax
  int result; // eax

  ClassMap = GetClassMap();
  result = ((int (__thiscall *)(CClassMap *, const char *, const char *, int, C_BaseEntity *(__cdecl *)()))ClassMap->Add)(
             a1: ClassMap,
             a2: "weapon_g3sg1",
             a3: "C_WeaponG3SG1",
             a4: 3504,
             a5: CC_WeaponG3SG1Factory);
  __g_C_WeaponG3SG1ClientClass.m_pMapClassname = "weapon_g3sg1";
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10428A90
// Name: _dynamic_initializer_for____g_C_WeaponGalilClientClass__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ClientClass *dynamic_initializer_for____g_C_WeaponGalilClientClass__()
{
  ClientClass *result; // eax

  result = g_pClientClassHead;
  __g_C_WeaponGalilClientClass.m_pNext = g_pClientClassHead;
  g_pClientClassHead = &__g_C_WeaponGalilClientClass;
  return result;
}

// ============================================================
// Overlay from server (Missing functions)
// ============================================================
namespace server {

//------------------------------------------------------------------------------
// Address: 0x102EC1B0
// Name: public: virtual class ServerClass __near * CWeaponG3SG1::GetServerClass(void)
// Source: json
//------------------------------------------------------------------------------
ServerClass *__thiscall CWeaponG3SG1::GetServerClass(CWeaponG3SG1 *this)
{
  return &g_CWeaponG3SG1_ClassReg;
}

//------------------------------------------------------------------------------
// Address: 0x102EC1C0
// Name: public: virtual void weapon_g3sg1Precache::CResourcePrecacher::Cache(class IPrecacheHandler __near *,bool,struct ResourceList_t__ __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall weapon_g3sg1Precache::CResourcePrecacher::Cache(
        weapon_g3sg1Precache::CResourcePrecacher *this,
        IPrecacheHandler *pPrecacheHandler,
        BOOL bPrecache,
        struct ResourceList_t__ *hResourceList,
        bool bIgnoreConditionals)
{
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: ENTITY,
    a3: "weapon_g3sg1",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x102EC270
// Name: public: virtual void CWeaponG3SG1::PrimaryAttack(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CWeaponG3SG1::PrimaryAttack(CWeaponG3SG1 *this@<ecx>, int a2@<ebx>)
{
  CCSPlayer *PlayerOwner; // edi
  const CCSWeaponInfo *CSWpnData; // eax
  CSWeaponMode m_Value; // [esp+8h] [ebp-18h]
  QAngle angle; // [esp+14h] [ebp-Ch] BYREF

  PlayerOwner = CWeaponCSBase::GetPlayerOwner(this);
  if ( PlayerOwner != nullptr )
  {
    m_Value = this->m_weaponMode.m_Value;
    CSWpnData = CWeaponCSBase::GetCSWpnData(this);
    if ( CWeaponCSBaseGun::CSBaseGunFire(this, a2, flCycleTime: CSWpnData->m_flCycleTime, weaponMode: m_Value) != 0
      && weapon_recoil_legacy.m_pParent != nullptr
      && weapon_recoil_legacy.m_pParent->m_Value.m_nValue != 0 )
    {
      angle = CBasePlayer::GetPunchAngle(this: PlayerOwner)->m_Value;
      angle.x = angle.x
              - (SharedRandomFloat(sharedname: "G3SG1PunchAngleX", flMinVal: 0.75, flMaxVal: 1.75, additionalSeed: 0)
               + 0.25 * angle.x);
      angle.y = SharedRandomFloat(sharedname: "G3SG1PunchAngleY", flMinVal: -0.75, flMaxVal: 0.75, additionalSeed: 0)
              + angle.y;
      CBasePlayer::SetPunchAngle(this: PlayerOwner, punchAngle: &angle);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102EC370
// Name: public: virtual void CWeaponG3SG1::SecondaryAttack(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWeaponG3SG1::SecondaryAttack(CWeaponG3SG1 *this)
{
  CCSPlayer *PlayerOwner; // eax
  CBasePlayer *v3; // edi
  int FOV; // esi
  edict_t *m_pPev; // ecx
  const CCSWeaponInfo *CSWpnData; // eax
  float m_Value; // xmm1_4
  float v8; // xmm0_4
  edict_t *v9; // ecx
  edict_t *v10; // ecx
  int DefaultFOV; // eax
  edict_t *v12; // ecx
  CCSPlayer *v13; // eax
  IGameEvent *v14; // esi
  int v15; // eax
  float v16; // xmm0_4
  edict_t *v17; // ecx

  PlayerOwner = CWeaponCSBase::GetPlayerOwner(this);
  v3 = PlayerOwner;
  if ( PlayerOwner != nullptr )
  {
    FOV = CBasePlayer::GetFOV(this: PlayerOwner);
    if ( FOV == CBasePlayer::GetDefaultFOV(this: v3) )
    {
      CBasePlayer::SetFOV(this: v3, pRequester: v3, FOV: 40, zoomRate: 0.050000001, iZoomStart: 0);
      if ( this->m_weaponMode.m_Value != Secondary_Mode )
      {
        if ( this->m_Network.m_TimerEvent.m_bRegistered )
        {
          *((_BYTE *)&this->m_Network + 76) |= 1u;
        }
        else
        {
          m_pPev = this->m_Network.m_pPev;
          if ( m_pPev != nullptr )
            CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x57Cu);
        }
        this->m_weaponMode.m_Value = Secondary_Mode;
      }
      CSWpnData = CWeaponCSBase::GetCSWpnData(this);
      m_Value = this->m_fAccuracyPenalty.m_Value;
      v8 = CSWpnData->m_fInaccuracyAltSwitch + m_Value;
      if ( m_Value != v8 )
      {
        if ( this->m_Network.m_TimerEvent.m_bRegistered )
        {
          *((_BYTE *)&this->m_Network + 76) |= 1u;
          this->m_fAccuracyPenalty.m_Value = v8;
        }
        else
        {
          v9 = this->m_Network.m_pPev;
          if ( v9 != nullptr )
            CBaseEdict::StateChanged(this: &v9->CBaseEdict, offset: 0x580u);
          this->m_fAccuracyPenalty.m_Value = v8;
        }
      }
    }
    else if ( CBasePlayer::GetFOV(this: v3) == 40 )
    {
      CBasePlayer::SetFOV(this: v3, pRequester: v3, FOV: 15, zoomRate: 0.050000001, iZoomStart: 0);
      if ( this->m_weaponMode.m_Value != Secondary_Mode )
      {
        if ( this->m_Network.m_TimerEvent.m_bRegistered )
        {
          *((_BYTE *)&this->m_Network + 76) |= 1u;
          this->m_weaponMode.m_Value = Secondary_Mode;
        }
        else
        {
          v10 = this->m_Network.m_pPev;
          if ( v10 != nullptr )
            CBaseEdict::StateChanged(this: &v10->CBaseEdict, offset: 0x57Cu);
          this->m_weaponMode.m_Value = Secondary_Mode;
        }
      }
    }
    else if ( CBasePlayer::GetFOV(this: v3) == 15 )
    {
      DefaultFOV = CBasePlayer::GetDefaultFOV(this: v3);
      CBasePlayer::SetFOV(this: v3, pRequester: v3, FOV: DefaultFOV, zoomRate: 0.050000001, iZoomStart: 0);
      if ( this->m_weaponMode.m_Value != Primary_Mode )
      {
        if ( this->m_Network.m_TimerEvent.m_bRegistered )
        {
          *((_BYTE *)&this->m_Network + 76) |= 1u;
        }
        else
        {
          v12 = this->m_Network.m_pPev;
          if ( v12 != nullptr )
            CBaseEdict::StateChanged(this: &v12->CBaseEdict, offset: 0x57Cu);
        }
        this->m_weaponMode.m_Value = Primary_Mode;
      }
    }
    if ( CWeaponCSBase::GetPlayerOwner(this) != nullptr )
    {
      v13 = CWeaponCSBase::GetPlayerOwner(this);
      CBaseEntity::EmitSound(this: v13, soundname: "Default.Zoom", soundtime: 0.0, duration: nullptr);
    }
    v14 = gameeventmanager->CreateEventA(this: gameeventmanager, a2: "weapon_zoom", a3: 0, a4: 0);
    if ( v14 != nullptr )
    {
      v15 = engine->GetPlayerUserId(this: engine, a2: v3->m_Network.m_pPev);
      v14->SetInt(this: v14, a2: "userid", a3: v15);
      gameeventmanager->FireEvent(this: gameeventmanager, a2: v14, a3: false);
    }
    v16 = gpGlobals->curtime + 0.30000001;
    if ( this->m_flNextSecondaryAttack.m_Value != v16 )
    {
      if ( this->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&this->m_Network + 76) |= 1u;
        this->m_flNextSecondaryAttack.m_Value = v16;
      }
      else
      {
        v17 = this->m_Network.m_pPev;
        if ( v17 != nullptr )
          CBaseEdict::StateChanged(this: &v17->CBaseEdict, offset: 0x498u);
        this->m_flNextSecondaryAttack.m_Value = v16;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102EC610
// Name: public: virtual enum CSWeaponID CWeaponG3SG1::GetCSWeaponID(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CWeaponG3SG1::GetCSWeaponID(CWeaponG3SG1 *this)
{
  return 9;
}

//------------------------------------------------------------------------------
// Address: 0x10412680
// Name: DT_WeaponG3SG1::_dynamic_initializer_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
int DT_WeaponG3SG1::_dynamic_initializer_for__g_SendTable__()
{
  SendTable::SendTable(this: &DT_WeaponG3SG1::g_SendTable);
  return atexit(func: DT_WeaponG3SG1::_dynamic_atexit_destructor_for__g_SendTable__);
}

//------------------------------------------------------------------------------
// Address: 0x104126A0
// Name: DT_WeaponG3SG1::_dynamic_initializer_for__g_SendTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_WeaponG3SG1::_dynamic_initializer_for__g_SendTableInit__()
{
  int result; // eax

  result = ServerClassInit<DT_WeaponG3SG1::ignored>();
  DT_WeaponG3SG1::g_SendTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104126D0
// Name: weapon_g3sg1Precache::_dynamic_initializer_for__s_ResourcePrecacher__
// Source: json
//------------------------------------------------------------------------------
int weapon_g3sg1Precache::_dynamic_initializer_for__s_ResourcePrecacher__()
{
  int result; // eax

  result = dword_106DA8A4;
  weapon_g3sg1Precache::s_ResourcePrecacher.m_pNext = (IResourcePrecacher *)dword_106DA8A4;
  dword_106DA8A4 = (int)&weapon_g3sg1Precache::s_ResourcePrecacher;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10420A80
// Name: DT_WeaponG3SG1::_dynamic_atexit_destructor_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_WeaponG3SG1::_dynamic_atexit_destructor_for__g_SendTable__()
{
  CAI_BaseNPC::OnSetSchedule(this: (vgui::Panel *)&DT_WeaponG3SG1::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x104126F0
// Name: _dynamic_initializer_for__g_CWeaponGalil_ClassReg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ServerClass *dynamic_initializer_for__g_CWeaponGalil_ClassReg__()
{
  return ServerClass::ServerClass(
           this: &g_CWeaponGalil_ClassReg,
           pNetworkName: "CWeaponGalil",
           pTable: &DT_WeaponGalil::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x10420A90
// Name: _ServerClassInit_DT_WeaponG3SG1::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ServerClassInit_DT_WeaponG3SG1::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__()
{
  SendProp *v0; // esi
  int i; // edi

  v0 = (SendProp *)&_S2_280;
  for ( i = 1; i >= 0; --i )
    SendProp::~SendProp(this: --v0);
}

} // namespace server
