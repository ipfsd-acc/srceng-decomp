// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/shared/cstrike15/weapon_awp.cpp
// Functions: 17
// ============================================================

#include "game\shared\cstrike15\weapon_awp.h"

//------------------------------------------------------------------------------
// Address: 0x102292C0
// Name: public: virtual class ClientClass __near * C_WeaponAWP::GetClientClass(void)
// Source: json
//------------------------------------------------------------------------------
ClientClass *__thiscall C_WeaponAWP::GetClientClass(C_WeaponAWP *this)
{
  return &__g_C_WeaponAWPClientClass;
}

//------------------------------------------------------------------------------
// Address: 0x10229340
// Name: public: virtual struct datamap_t __near * C_WeaponAWP::GetPredDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall C_WeaponAWP::GetPredDescMap(C_WeaponAWP *this)
{
  return &C_WeaponAWP::m_PredMap;
}

//------------------------------------------------------------------------------
// Address: 0x10229350
// Name: public: virtual void weapon_awpPrecache::CResourcePrecacher::Cache(class IPrecacheHandler __near *,bool,struct ResourceList_t__ __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall weapon_awpPrecache::CResourcePrecacher::Cache(
        weapon_awpPrecache::CResourcePrecacher *this,
        IPrecacheHandler *pPrecacheHandler,
        BOOL bPrecache,
        struct ResourceList_t__ *hResourceList,
        bool bIgnoreConditionals)
{
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: ENTITY,
    a3: "weapon_awp",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x10229380
// Name: public: virtual void C_WeaponAWP::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_WeaponAWP::Spawn(C_WeaponAWP *this)
{
  this->Precache(this);
  C_BaseCombatWeapon::Spawn(this);
}

//------------------------------------------------------------------------------
// Address: 0x102293A0
// Name: public: virtual float C_WeaponAWP::GetMaxSpeed(void)const
// Source: json
//------------------------------------------------------------------------------
double __thiscall C_WeaponAWP::GetMaxSpeed(C_WeaponAWP *this)
{
  int v2; // eax
  int v3; // esi
  float v5; // [esp+8h] [ebp-8h]

  C_WeaponCSBase::GetPlayerOwner(this);
  v3 = v2;
  if ( v2 == 0 )
    return C_WeaponCSBase::GetMaxSpeed(this);
  v5 = ((double (__thiscall *)(int))*(_DWORD *)(*(_DWORD *)v2 + 1148))(a1: v2);
  if ( v5 == (double)(*(int (__thiscall **)(int))(*(_DWORD *)v3 + 1152))(a1: v3) )
    return C_WeaponCSBase::GetMaxSpeed(this);
  else
    return 150.0;
}

//------------------------------------------------------------------------------
// Address: 0x10229400
// Name: public: virtual void C_WeaponAWP::SecondaryAttack(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_WeaponAWP::SecondaryAttack(C_WeaponAWP *this)
{
  C_BasePlayer *v2; // eax
  C_BasePlayer *v3; // esi
  const CCSWeaponInfo *CSWpnData; // eax
  float m_Value; // xmm1_4
  float v6; // xmm0_4
  int v7; // eax
  float v8; // xmm0_4
  float v9; // [esp+10h] [ebp-8h]

  C_WeaponCSBase::GetPlayerOwner(this);
  v3 = v2;
  if ( v2 != nullptr )
  {
    v9 = v2->GetFOV(this: v2);
    if ( v9 == (double)v3->GetDefaultFOV(this: v3) )
    {
      C_BasePlayer::SetFOV(this: v3, pRequester: v3, FOV: 40, zoomRate: 0.050000001, iZoomStart: 0);
      if ( this->m_weaponMode.m_Value != Secondary_Mode )
        this->m_weaponMode.m_Value = Secondary_Mode;
      CSWpnData = C_WeaponCSBase::GetCSWpnData(this);
      m_Value = this->m_fAccuracyPenalty.m_Value;
      v6 = CSWpnData->m_fInaccuracyAltSwitch + m_Value;
      if ( m_Value != v6 )
        this->m_fAccuracyPenalty.m_Value = v6;
    }
    else if ( ((double (__thiscall *)(C_BasePlayer *))v3->GetFOV)(a1: v3) == 40.0 )
    {
      C_BasePlayer::SetFOV(this: v3, pRequester: v3, FOV: 10, zoomRate: 0.050000001, iZoomStart: 0);
      if ( this->m_weaponMode.m_Value != Secondary_Mode )
        this->m_weaponMode.m_Value = Secondary_Mode;
    }
    else
    {
      v7 = v3->GetDefaultFOV(this: v3);
      C_BasePlayer::SetFOV(this: v3, pRequester: v3, FOV: v7, zoomRate: 0.050000001, iZoomStart: 0);
      if ( this->m_weaponMode.m_Value != Primary_Mode )
        this->m_weaponMode.m_Value = Primary_Mode;
    }
    v8 = *(float *)(gpGlobals.m_Index + 12) + 0.30000001;
    if ( this->m_flNextSecondaryAttack.m_Value != v8 )
      this->m_flNextSecondaryAttack.m_Value = v8;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10229550
// Name: public: virtual void C_WeaponAWP::PrimaryAttack(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_WeaponAWP::PrimaryAttack(C_WeaponAWP *this)
{
  C_BasePlayer *v2; // eax
  C_BasePlayer *v3; // esi
  const CCSWeaponInfo *CSWpnData; // eax
  double v5; // st7
  float (__thiscall *GetFOV)(C_BasePlayer *); // eax
  double v7; // st7
  int v8; // eax
  int v9; // eax
  CSWeaponMode m_Value; // [esp+4h] [ebp-1Ch]
  QAngle angle; // [esp+10h] [ebp-10h] BYREF
  float v12; // [esp+1Ch] [ebp-4h]

  C_WeaponCSBase::GetPlayerOwner(this);
  v3 = v2;
  if ( v2 != nullptr )
  {
    m_Value = this->m_weaponMode.m_Value;
    CSWpnData = C_WeaponCSBase::GetCSWpnData(this);
    if ( C_WeaponCSBaseGun::CSBaseGunFire(this, flCycleTime: CSWpnData->m_flCycleTime, weaponMode: m_Value) )
    {
      if ( this->m_weaponMode.m_Value == Secondary_Mode )
      {
        v5 = ((double (__thiscall *)(C_BasePlayer *))v3->GetFOV)(a1: v3);
        GetFOV = v3->GetFOV;
        v12 = fabs(v5 - 40.0);
        v7 = ((double (__thiscall *)(C_BasePlayer *))GetFOV)(a1: v3);
        v8 = 40;
        if ( fabs(v7 - 10.0) <= v12 )
          v8 = 10;
        if ( v3[1].m_VarMap.m_Entries.m_pElements != (VarMapEntry_t *)v8 )
          v3[1].m_VarMap.m_Entries.m_pElements = (VarMapEntry_t *)v8;
        if ( LOBYTE(v3[1].m_VarMap.m_Entries.m_Size) != 1 )
          LOBYTE(v3[1].m_VarMap.m_Entries.m_Size) = 1;
        v9 = v3->GetDefaultFOV(this: v3);
        C_BasePlayer::SetFOV(this: v3, pRequester: v3, FOV: v9, zoomRate: 0.1, iZoomStart: 0);
        if ( this->m_weaponMode.m_Value != Primary_Mode )
          this->m_weaponMode.m_Value = Primary_Mode;
      }
      if ( weapon_recoil_legacy.m_pParent != nullptr && weapon_recoil_legacy.m_pParent->m_Value.m_nValue != 0 )
      {
        angle = *v3->GetPunchAngle(this: v3);
        angle.x = angle.x - 2.0;
        C_BasePlayer::SetPunchAngle(this: v3, &angle);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102296B0
// Name: public: virtual enum CSWeaponID C_WeaponAWP::GetCSWeaponID(void)const
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall C_WeaponAWP::GetCSWeaponID(C_INIT_CreateFromParentParticles *this)
{
  return 7;
}

//------------------------------------------------------------------------------
// Address: 0x10229730
// Name: CC_WeaponAWPFactory
// Source: json
//------------------------------------------------------------------------------
C_BaseEntity *__cdecl CC_WeaponAWPFactory()
{
  C_WeaponCSBaseGun *v0; // eax
  _DWORD *v1; // esi

  v0 = (C_WeaponCSBaseGun *)C_BaseEntity::operator new(stAllocateBlock: 0xDB0u);
  v1 = &v0->C_WeaponCSBase::C_BaseCombatWeapon::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable;
  if ( v0 == nullptr )
    return nullptr;
  C_WeaponCSBaseGun::C_WeaponCSBaseGun(this: v0);
  *v1 = &C_WeaponAWP::`vftable'{for `IClientUnknown'};
  v1[1] = &C_WeaponAWP::`vftable'{for `IClientRenderable'};
  v1[2] = &C_WeaponAWP::`vftable'{for `IClientNetworkable'};
  v1[3] = &C_WeaponAWP::`vftable'{for `IClientThinkable'};
  v1[4] = &C_WeaponAWP::`vftable';
  return (C_BaseEntity *)v1;
}

//------------------------------------------------------------------------------
// Address: 0x10427CB0
// Name: DT_WeaponAWP::_dynamic_initializer_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
int DT_WeaponAWP::_dynamic_initializer_for__g_RecvTable__()
{
  RecvTable::RecvTable(this: &DT_WeaponAWP::g_RecvTable);
  return atexit(func: DT_WeaponAWP::_dynamic_atexit_destructor_for__g_RecvTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10427CD0
// Name: DT_WeaponAWP::_dynamic_initializer_for__g_RecvTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_WeaponAWP::_dynamic_initializer_for__g_RecvTableInit__()
{
  int result; // eax

  result = ClientClassInit<DT_WeaponAWP::ignored>();
  DT_WeaponAWP::g_RecvTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10427CE0
// Name: C_WeaponAWP_PredDataDescInit::_dynamic_initializer_for__g_PredMapHolder__
// Source: json
//------------------------------------------------------------------------------
void C_WeaponAWP_PredDataDescInit::_dynamic_initializer_for__g_PredMapHolder__()
{
  C_WeaponAWP::m_PredMap.dataNumFields = 1;
  C_WeaponAWP::m_PredMap.dataDesc = (typedescription_t *)&unk_10669FDC;
}

//------------------------------------------------------------------------------
// Address: 0x10427D30
// Name: weapon_awpPrecache::_dynamic_initializer_for__s_ResourcePrecacher__
// Source: json
//------------------------------------------------------------------------------
CBaseResourcePrecacher *weapon_awpPrecache::_dynamic_initializer_for__s_ResourcePrecacher__()
{
  CBaseResourcePrecacher *result; // eax

  result = CBaseResourcePrecacher::sm_pFirst[0];
  weapon_awpPrecache::s_ResourcePrecacher.m_pNext = CBaseResourcePrecacher::sm_pFirst[0];
  CBaseResourcePrecacher::sm_pFirst[0] = &weapon_awpPrecache::s_ResourcePrecacher;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10435E30
// Name: DT_WeaponAWP::_dynamic_atexit_destructor_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_WeaponAWP::_dynamic_atexit_destructor_for__g_RecvTable__()
{
  C_BaseAnimating::ShutdownBoneSetupThreadPool(this: (vgui::PropertyPage *)&DT_WeaponAWP::g_RecvTable);
}

//------------------------------------------------------------------------------
// Address: 0x102296C0
// Name: _C_WeaponAWP_CreateObject
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IClientNetworkable *__cdecl C_WeaponAWP_CreateObject(int entnum, int serialNum)
{
  C_WeaponCSBaseGun *v2; // eax
  _DWORD *v3; // esi

  v2 = (C_WeaponCSBaseGun *)C_BaseEntity::operator new(stAllocateBlock: 0xDB0u);
  v3 = &v2->C_WeaponCSBase::C_BaseCombatWeapon::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable;
  if ( v2 == nullptr )
    return nullptr;
  C_WeaponCSBaseGun::C_WeaponCSBaseGun(this: v2);
  *v3 = &C_WeaponAWP::`vftable'{for `IClientUnknown'};
  v3[1] = &C_WeaponAWP::`vftable'{for `IClientRenderable'};
  v3[2] = &C_WeaponAWP::`vftable'{for `IClientNetworkable'};
  v3[3] = &C_WeaponAWP::`vftable'{for `IClientThinkable'};
  v3[4] = &C_WeaponAWP::`vftable';
  (*(void (__thiscall **)(_DWORD *, int, int))(*v3 + 172))(a1: v3, a2: entnum, a3: serialNum);
  return (IClientNetworkable *)(v3 + 2);
}

//------------------------------------------------------------------------------
// Address: 0x10427D00
// Name: _dynamic_initializer_for__g_Cweapon_awpFoo__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_Cweapon_awpFoo__()
{
  CClassMap *ClassMap; // eax
  int result; // eax

  ClassMap = GetClassMap();
  result = ((int (__thiscall *)(CClassMap *, const char *, const char *, int, C_BaseEntity *(__cdecl *)()))ClassMap->Add)(
             a1: ClassMap,
             a2: "weapon_awp",
             a3: "C_WeaponAWP",
             a4: 3504,
             a5: CC_WeaponAWPFactory);
  __g_C_WeaponAWPClientClass.m_pMapClassname = "weapon_awp";
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10427D50
// Name: _dynamic_initializer_for____g_C_BaseCSGrenadeClientClass__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ClientClass *dynamic_initializer_for____g_C_BaseCSGrenadeClientClass__()
{
  ClientClass *result; // eax

  result = g_pClientClassHead;
  __g_C_BaseCSGrenadeClientClass.m_pNext = g_pClientClassHead;
  g_pClientClassHead = &__g_C_BaseCSGrenadeClientClass;
  return result;
}

// ============================================================
// Overlay from server (Missing functions)
// ============================================================
namespace server {

//------------------------------------------------------------------------------
// Address: 0x102E3310
// Name: public: virtual class ServerClass __near * CWeaponAWP::GetServerClass(void)
// Source: json
//------------------------------------------------------------------------------
ServerClass *__thiscall CWeaponAWP::GetServerClass(CWeaponAWP *this)
{
  return &g_CWeaponAWP_ClassReg;
}

//------------------------------------------------------------------------------
// Address: 0x102E3320
// Name: public: virtual void weapon_awpPrecache::CResourcePrecacher::Cache(class IPrecacheHandler __near *,bool,struct ResourceList_t__ __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall weapon_awpPrecache::CResourcePrecacher::Cache(
        weapon_awpPrecache::CResourcePrecacher *this,
        IPrecacheHandler *pPrecacheHandler,
        BOOL bPrecache,
        struct ResourceList_t__ *hResourceList,
        bool bIgnoreConditionals)
{
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: ENTITY,
    a3: "weapon_awp",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x102E3350
// Name: public: virtual struct datamap_t __near * CWeaponAWP::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CWeaponAWP::GetDataDescMap(CWeaponAWP *this)
{
  return &CWeaponAWP::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x102E3360
// Name: public: virtual void CWeaponAWP::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWeaponAWP::Spawn(CWeaponAWP *this)
{
  this->Precache(this);
  CWeaponCSBase::Spawn(this);
}

//------------------------------------------------------------------------------
// Address: 0x102E3380
// Name: public: virtual float CWeaponAWP::GetMaxSpeed(void)const
// Source: json
//------------------------------------------------------------------------------
double __thiscall CWeaponAWP::GetMaxSpeed(CWeaponAWP *this)
{
  CCSPlayer *PlayerOwner; // eax
  CBasePlayer *v3; // esi
  int FOV; // ebx

  PlayerOwner = CWeaponCSBase::GetPlayerOwner(this);
  v3 = PlayerOwner;
  if ( PlayerOwner == nullptr )
    return CWeaponCSBase::GetMaxSpeed(this);
  FOV = CBasePlayer::GetFOV(this: PlayerOwner);
  if ( FOV == CBasePlayer::GetDefaultFOV(this: v3) )
    return CWeaponCSBase::GetMaxSpeed(this);
  else
    return 150.0;
}

//------------------------------------------------------------------------------
// Address: 0x102E3440
// Name: public: virtual void CWeaponAWP::SecondaryAttack(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWeaponAWP::SecondaryAttack(CWeaponAWP *this)
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
      CBasePlayer::SetFOV(this: v3, pRequester: v3, FOV: 10, zoomRate: 0.050000001, iZoomStart: 0);
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
    else
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
// Address: 0x102E36C0
// Name: public: virtual void CWeaponAWP::PrimaryAttack(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWeaponAWP::PrimaryAttack(CWeaponAWP *this)
{
  CCSPlayer *PlayerOwner; // edi
  const CCSWeaponInfo *CSWpnData; // eax
  CBaseEdict *v4; // ecx
  CBaseEdict *v5; // ecx
  CBaseEdict *v6; // ecx
  int DefaultFOV; // eax
  edict_t *m_pPev; // ecx
  CSWeaponMode m_Value; // [esp+4h] [ebp-20h]
  QAngle angle; // [esp+14h] [ebp-10h] BYREF
  float v11; // [esp+20h] [ebp-4h]

  PlayerOwner = CWeaponCSBase::GetPlayerOwner(this);
  if ( PlayerOwner != nullptr )
  {
    m_Value = this->m_weaponMode.m_Value;
    CSWpnData = CWeaponCSBase::GetCSWpnData(this);
    if ( CWeaponCSBaseGun::CSBaseGunFire(this, flCycleTime: CSWpnData->m_flCycleTime, weaponMode: m_Value) )
    {
      if ( this->m_weaponMode.m_Value == Secondary_Mode )
      {
        LODWORD(v11) = COERCE_UNSIGNED_INT((float)CBasePlayer::GetFOV(this: PlayerOwner) - 40.0) & _mask__AbsFloat_;
        if ( COERCE_FLOAT(COERCE_UNSIGNED_INT((float)CBasePlayer::GetFOV(this: PlayerOwner) - 10.0) & _mask__AbsFloat_) <= v11 )
        {
          if ( PlayerOwner->m_iLastZoom.m_Value != 10 )
          {
            if ( PlayerOwner->m_Network.m_TimerEvent.m_bRegistered )
            {
              *((_BYTE *)&PlayerOwner->m_Network + 76) |= 1u;
            }
            else
            {
              v5 = &PlayerOwner->m_Network.m_pPev->CBaseEdict;
              if ( v5 != nullptr )
                CBaseEdict::StateChanged(this: v5, offset: 0x130Cu);
            }
            PlayerOwner->m_iLastZoom.m_Value = 10;
          }
        }
        else if ( PlayerOwner->m_iLastZoom.m_Value != 40 )
        {
          if ( PlayerOwner->m_Network.m_TimerEvent.m_bRegistered )
          {
            *((_BYTE *)&PlayerOwner->m_Network + 76) |= 1u;
            PlayerOwner->m_iLastZoom.m_Value = 40;
          }
          else
          {
            v4 = &PlayerOwner->m_Network.m_pPev->CBaseEdict;
            if ( v4 != nullptr )
              CBaseEdict::StateChanged(this: v4, offset: 0x130Cu);
            PlayerOwner->m_iLastZoom.m_Value = 40;
          }
        }
        if ( !PlayerOwner->m_bResumeZoom.m_Value )
        {
          if ( PlayerOwner->m_Network.m_TimerEvent.m_bRegistered )
          {
            *((_BYTE *)&PlayerOwner->m_Network + 76) |= 1u;
          }
          else
          {
            v6 = &PlayerOwner->m_Network.m_pPev->CBaseEdict;
            if ( v6 != nullptr )
              CBaseEdict::StateChanged(this: v6, offset: 0x1308u);
          }
          PlayerOwner->m_bResumeZoom.m_Value = true;
        }
        DefaultFOV = CBasePlayer::GetDefaultFOV(this: PlayerOwner);
        CBasePlayer::SetFOV(this: PlayerOwner, pRequester: PlayerOwner, FOV: DefaultFOV, zoomRate: 0.1, iZoomStart: 0);
        if ( this->m_weaponMode.m_Value != Primary_Mode )
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
          this->m_weaponMode.m_Value = Primary_Mode;
        }
      }
      if ( weapon_recoil_legacy.m_pParent != nullptr && weapon_recoil_legacy.m_pParent->m_Value.m_nValue != 0 )
      {
        angle = CBasePlayer::GetPunchAngle(this: PlayerOwner)->m_Value;
        angle.x = angle.x - 2.0;
        CBasePlayer::SetPunchAngle(this: PlayerOwner, punchAngle: &angle);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102E3920
// Name: public: virtual enum CSWeaponID CWeaponAWP::GetCSWeaponID(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CWeaponAWP::GetCSWeaponID(CWeaponAWP *this)
{
  return 7;
}

//------------------------------------------------------------------------------
// Address: 0x10411DC0
// Name: DT_WeaponAWP::_dynamic_initializer_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
int DT_WeaponAWP::_dynamic_initializer_for__g_SendTable__()
{
  SendTable::SendTable(this: &DT_WeaponAWP::g_SendTable);
  return atexit(func: DT_WeaponAWP::_dynamic_atexit_destructor_for__g_SendTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10411DE0
// Name: DT_WeaponAWP::_dynamic_initializer_for__g_SendTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_WeaponAWP::_dynamic_initializer_for__g_SendTableInit__()
{
  int result; // eax

  result = ServerClassInit<DT_WeaponAWP::ignored>();
  DT_WeaponAWP::g_SendTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10411E10
// Name: weapon_awpPrecache::_dynamic_initializer_for__s_ResourcePrecacher__
// Source: json
//------------------------------------------------------------------------------
int weapon_awpPrecache::_dynamic_initializer_for__s_ResourcePrecacher__()
{
  int result; // eax

  result = dword_106DA8A4;
  weapon_awpPrecache::s_ResourcePrecacher.m_pNext = (IResourcePrecacher *)dword_106DA8A4;
  dword_106DA8A4 = (int)&weapon_awpPrecache::s_ResourcePrecacher;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10411E30
// Name: CWeaponAWP_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CWeaponAWP_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CWeaponAWP>(__formal: nullptr);
  CWeaponAWP_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10420740
// Name: DT_WeaponAWP::_dynamic_atexit_destructor_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_WeaponAWP::_dynamic_atexit_destructor_for__g_SendTable__()
{
  CAI_BaseNPC::OnSetSchedule(this: (vgui::Panel *)&DT_WeaponAWP::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x102E38B0
// Name: struct datamap_t __near * DataMapInit<class CWeaponAWP>(class CWeaponAWP __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CWeaponAWP>()
{
  if ( (_S3_154 & 1) == 0 )
  {
    _S3_154 |= 1u;
    nameHolder_490.m_pszBase = "CWeaponAWP";
    nameHolder_490.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_490.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_490.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_490.m_Names.m_Size = 0;
    nameHolder_490.m_Names.m_pElements = nullptr;
    nameHolder_490.m_nLenBase = 10;
    atexit(func: DataMapInit_CWeaponAWP__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CWeaponAWP::m_DataMap.baseMap = &CWeaponCSBase::m_DataMap;
  CWeaponAWP::m_DataMap.dataNumFields = 1;
  CWeaponAWP::m_DataMap.dataDesc = dataDesc_507;
  return &CWeaponAWP::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10411E40
// Name: _dynamic_initializer_for__g_CBaseCSGrenade_ClassReg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ServerClass *dynamic_initializer_for__g_CBaseCSGrenade_ClassReg__()
{
  return ServerClass::ServerClass(
           this: &g_CBaseCSGrenade_ClassReg,
           pNetworkName: "CBaseCSGrenade",
           pTable: &DT_BaseCSGrenade::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x10420750
// Name: _ServerClassInit_DT_WeaponAWP::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ServerClassInit_DT_WeaponAWP::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__()
{
  SendProp *v0; // esi
  int i; // edi

  v0 = (SendProp *)&_S2_268;
  for ( i = 1; i >= 0; --i )
    SendProp::~SendProp(this: --v0);
}

//------------------------------------------------------------------------------
// Address: 0x10420770
// Name: _DataMapInit_CWeaponAWP__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CWeaponAWP__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_490);
}

} // namespace server
