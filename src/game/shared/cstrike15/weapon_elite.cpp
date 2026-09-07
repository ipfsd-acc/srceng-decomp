// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/shared/cstrike15/weapon_elite.cpp
// Functions: 21
// ============================================================

#include "game\shared\cstrike15\weapon_elite.h"

//------------------------------------------------------------------------------
// Address: 0x1022DDD0
// Name: public: virtual class ClientClass __near * C_WeaponElite::GetClientClass(void)
// Source: json
//------------------------------------------------------------------------------
ClientClass *__thiscall C_WeaponElite::GetClientClass(C_WeaponElite *this)
{
  return &__g_C_WeaponEliteClientClass;
}

//------------------------------------------------------------------------------
// Address: 0x1022DE50
// Name: public: virtual struct datamap_t __near * C_WeaponElite::GetPredDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall C_WeaponElite::GetPredDescMap(C_WeaponElite *this)
{
  return &C_WeaponElite::m_PredMap;
}

//------------------------------------------------------------------------------
// Address: 0x1022DE60
// Name: public: virtual void weapon_elitePrecache::CResourcePrecacher::Cache(class IPrecacheHandler __near *,bool,struct ResourceList_t__ __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall weapon_elitePrecache::CResourcePrecacher::Cache(
        weapon_elitePrecache::CResourcePrecacher *this,
        IPrecacheHandler *pPrecacheHandler,
        BOOL bPrecache,
        struct ResourceList_t__ *hResourceList,
        bool bIgnoreConditionals)
{
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: ENTITY,
    a3: "weapon_elite",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x1022DE90
// Name: public: virtual void C_WeaponElite::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall C_WeaponElite::Spawn(C_WeaponElite *this)
{
  C_BaseCombatWeapon::Spawn(this);
}

//------------------------------------------------------------------------------
// Address: 0x1022DEA0
// Name: public: virtual void C_WeaponElite::Precache(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall C_WeaponElite::Precache(C_WeaponElite *this@<ecx>, int a2@<ebx>)
{
  const CCSWeaponInfo *CSWpnData; // eax

  this->m_inPrecache = true;
  C_WeaponCSBase::Precache(this, a2);
  C_BaseEntity::PrecacheModel(name: "models/weapons/w_eq_eholster_elite.mdl");
  C_BaseEntity::PrecacheModel(name: "models/weapons/w_eq_eholster.mdl");
  C_BaseEntity::PrecacheModel(name: "models/weapons/w_pist_elite_single.mdl");
  CSWpnData = C_WeaponCSBase::GetCSWpnData(this);
  this->m_droppedModelIndex = C_BaseEntity::PrecacheModel(name: CSWpnData->m_szDroppedModel);
  PrecacheEffect(pEffectName: "CS_MuzzleFlash");
  this->m_inPrecache = false;
}

//------------------------------------------------------------------------------
// Address: 0x1022DF00
// Name: public: virtual char const __near * C_WeaponElite::GetWorldModel(void)const
// Source: json
//------------------------------------------------------------------------------
char *__thiscall C_WeaponElite::GetWorldModel(C_WeaponElite *this)
{
  if ( C_BaseCombatWeapon::GetOwner(this) != nullptr || this->m_inPrecache )
    return C_BaseCombatWeapon::GetWorldModel(this);
  else
    return C_WeaponCSBase::GetCSWpnData(this)->m_szDroppedModel;
}

//------------------------------------------------------------------------------
// Address: 0x1022DF30
// Name: public: virtual int C_WeaponElite::GetWorldModelIndex(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall C_WeaponElite::GetWorldModelIndex(C_WeaponElite *this)
{
  if ( C_BaseCombatWeapon::GetOwner(this) != nullptr || this->m_inPrecache )
    return this->m_iWorldModelIndex.m_Value;
  else
    return this->m_droppedModelIndex;
}

//------------------------------------------------------------------------------
// Address: 0x1022DF60
// Name: public: virtual bool C_WeaponElite::SendWeaponAnim(int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall C_WeaponElite::SendWeaponAnim(C_WeaponElite *this, Activity iActivity)
{
  Activity v2; // eax

  v2 = iActivity;
  if ( iActivity == ACT_VM_PRIMARYATTACK )
  {
    if ( (this->m_iClip1.m_Value & 1) == 0 )
      return C_WeaponCSBase::SendWeaponAnim(
               this,
               iActivity: (Activity)(this->m_iClip1.m_Value <= 2 ? ACT_VM_DRYFIRE_LEFT : ACT_VM_PRIMARYATTACK));
    v2 = 2 * (this->m_iClip1.m_Value <= 2) + 191;
  }
  return C_WeaponCSBase::SendWeaponAnim(this, iActivity: v2);
}

//------------------------------------------------------------------------------
// Address: 0x1022DFC0
// Name: public: virtual void C_WeaponElite::WeaponIdle(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_WeaponElite::WeaponIdle(C_WeaponElite *this)
{
  C_WeaponElite_vtbl *v2; // edi
  const CCSWeaponInfo *CSWpnData; // eax

  if ( this->m_flTimeWeaponIdle.m_Value <= *(float *)(gpGlobals.m_Index + 12) && this->m_iClip1.m_Value >= 2 )
  {
    this->SendWeaponAnim(this, a2: 183);
    v2 = this->C_WeaponCSBaseGun::C_WeaponCSBase::C_BaseCombatWeapon::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable;
    CSWpnData = C_WeaponCSBase::GetCSWpnData(this);
    ((void (__thiscall *)(C_WeaponElite *, _DWORD))v2->SetWeaponIdleTime)(
      a1: this,
      a2: CSWpnData->m_flIdleInterval + *(float *)(gpGlobals.m_Index + 12));
  }
}

//------------------------------------------------------------------------------
// Address: 0x1022E020
// Name: public: virtual int C_WeaponElite::GetMuzzleAttachmentIndex_1stPerson(class C_BaseViewModel __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall C_WeaponElite::GetMuzzleAttachmentIndex_1stPerson(C_WeaponElite *this, C_BaseViewModel *pViewModel)
{
  char m_Value; // al
  IClientRenderable *v3; // ecx
  bool v4; // zf
  int (__thiscall *LookupAttachment)(IClientRenderable *, const char *); // eax

  m_Value = this->m_iClip1.m_Value;
  v3 = &pViewModel->IClientRenderable;
  v4 = (m_Value & 1) != 0;
  LookupAttachment = pViewModel->LookupAttachment;
  if ( v4 )
    return LookupAttachment(this: v3, a2: "2");
  else
    return LookupAttachment(this: v3, a2: "1");
}

//------------------------------------------------------------------------------
// Address: 0x1022E060
// Name: public: virtual int C_WeaponElite::GetEjectBrassAttachmentIndex_3rdPerson(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall C_WeaponElite::GetEjectBrassAttachmentIndex_3rdPerson(C_WeaponElite *this)
{
  char m_Value; // al
  IClientRenderable_vtbl *v2; // edx
  IClientRenderable *v3; // ecx
  bool v4; // zf
  int (__thiscall *LookupAttachment)(IClientRenderable *, const char *); // eax

  m_Value = this->m_iClip1.m_Value;
  v2 = this->C_WeaponCSBaseGun::C_WeaponCSBase::C_BaseCombatWeapon::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientRenderable::__vftable;
  v3 = &this->IClientRenderable;
  v4 = (m_Value & 1) != 0;
  LookupAttachment = v2->LookupAttachment;
  if ( v4 )
    return LookupAttachment(this: v3, a2: "muzzle_flash_r");
  else
    return LookupAttachment(this: v3, a2: "muzzle_flash_l");
}

//------------------------------------------------------------------------------
// Address: 0x1022E090
// Name: public: virtual void C_WeaponElite::PrimaryAttack(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_WeaponElite::PrimaryAttack(C_WeaponElite *this)
{
  C_BasePlayer *v2; // eax
  C_BasePlayer *v3; // edi
  const CCSWeaponInfo *CSWpnData; // eax
  CSWeaponMode v5; // [esp+4h] [ebp-1Ch]
  QAngle punchAngle; // [esp+10h] [ebp-10h] BYREF

  C_WeaponCSBase::GetPlayerOwner(this);
  v3 = v2;
  if ( v2 != nullptr )
  {
    v5 = (this->m_iClip1.m_Value & 1) != 0;
    CSWpnData = C_WeaponCSBase::GetCSWpnData(this);
    if ( C_WeaponCSBaseGun::CSBaseGunFire(this, flCycleTime: CSWpnData->m_flCycleTime, weaponMode: v5) != 0
      && weapon_recoil_legacy.m_pParent != nullptr
      && weapon_recoil_legacy.m_pParent->m_Value.m_nValue != 0 )
    {
      punchAngle = *v3->GetPunchAngle(this: v3);
      punchAngle.x = punchAngle.x - 2.0;
      C_BasePlayer::SetPunchAngle(this: v3, angle: &punchAngle);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1022E1A0
// Name: CC_WeaponEliteFactory
// Source: json
//------------------------------------------------------------------------------
C_WeaponCSBaseGun *__cdecl CC_WeaponEliteFactory()
{
  C_WeaponCSBaseGun *v0; // eax
  C_WeaponCSBaseGun *v1; // esi

  v0 = (C_WeaponCSBaseGun *)C_BaseEntity::operator new(stAllocateBlock: 0xDB8u);
  v1 = v0;
  if ( v0 == nullptr )
    return nullptr;
  C_WeaponCSBaseGun::C_WeaponCSBaseGun(this: v0);
  v1->C_WeaponCSBase::C_BaseCombatWeapon::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable = (C_WeaponCSBaseGun_vtbl *)&C_WeaponElite::`vftable'{for `IClientUnknown'};
  v1->C_WeaponCSBase::C_BaseCombatWeapon::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientRenderable::__vftable = (IClientRenderable_vtbl *)&C_WeaponElite::`vftable'{for `IClientRenderable'};
  v1->C_WeaponCSBase::C_BaseCombatWeapon::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientNetworkable::__vftable = (IClientNetworkable_vtbl *)&C_WeaponElite::`vftable'{for `IClientNetworkable'};
  v1->C_WeaponCSBase::C_BaseCombatWeapon::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientThinkable::__vftable = (IClientThinkable_vtbl *)&C_WeaponElite::`vftable'{for `IClientThinkable'};
  v1->C_WeaponCSBase::C_BaseCombatWeapon::C_BaseAnimating::C_BaseEntity::IClientModelRenderable::__vftable = (IClientModelRenderable_vtbl *)&C_WeaponElite::`vftable';
  LOBYTE(v1[1].C_WeaponCSBase::C_BaseCombatWeapon::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientRenderable::__vftable) = 0;
  return v1;
}

//------------------------------------------------------------------------------
// Address: 0x104286F0
// Name: DT_WeaponElite::_dynamic_initializer_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
int DT_WeaponElite::_dynamic_initializer_for__g_RecvTable__()
{
  RecvTable::RecvTable(this: &DT_WeaponElite::g_RecvTable);
  return atexit(func: DT_WeaponElite::_dynamic_atexit_destructor_for__g_RecvTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10428710
// Name: DT_WeaponElite::_dynamic_initializer_for__g_RecvTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_WeaponElite::_dynamic_initializer_for__g_RecvTableInit__()
{
  int result; // eax

  result = ClientClassInit<DT_WeaponElite::ignored>();
  DT_WeaponElite::g_RecvTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10428720
// Name: C_WeaponElite_PredDataDescInit::_dynamic_initializer_for__g_PredMapHolder__
// Source: json
//------------------------------------------------------------------------------
void C_WeaponElite_PredDataDescInit::_dynamic_initializer_for__g_PredMapHolder__()
{
  C_WeaponElite::m_PredMap.dataNumFields = 1;
  C_WeaponElite::m_PredMap.dataDesc = (typedescription_t *)&unk_1066B0A4;
}

//------------------------------------------------------------------------------
// Address: 0x10428770
// Name: weapon_elitePrecache::_dynamic_initializer_for__s_ResourcePrecacher__
// Source: json
//------------------------------------------------------------------------------
CBaseResourcePrecacher *weapon_elitePrecache::_dynamic_initializer_for__s_ResourcePrecacher__()
{
  CBaseResourcePrecacher *result; // eax

  result = CBaseResourcePrecacher::sm_pFirst[0];
  weapon_elitePrecache::s_ResourcePrecacher.m_pNext = CBaseResourcePrecacher::sm_pFirst[0];
  CBaseResourcePrecacher::sm_pFirst[0] = &weapon_elitePrecache::s_ResourcePrecacher;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10436040
// Name: DT_WeaponElite::_dynamic_atexit_destructor_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_WeaponElite::_dynamic_atexit_destructor_for__g_RecvTable__()
{
  C_BaseAnimating::ShutdownBoneSetupThreadPool(this: (vgui::PropertyPage *)&DT_WeaponElite::g_RecvTable);
}

//------------------------------------------------------------------------------
// Address: 0x1022E130
// Name: _C_WeaponElite_CreateObject
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IClientNetworkable *__cdecl C_WeaponElite_CreateObject(int entnum, int serialNum)
{
  C_WeaponCSBaseGun *v2; // eax
  C_WeaponCSBaseGun *v3; // esi

  v2 = (C_WeaponCSBaseGun *)C_BaseEntity::operator new(stAllocateBlock: 0xDB8u);
  v3 = v2;
  if ( v2 == nullptr )
    return nullptr;
  C_WeaponCSBaseGun::C_WeaponCSBaseGun(this: v2);
  v3->C_WeaponCSBase::C_BaseCombatWeapon::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable = (C_WeaponCSBaseGun_vtbl *)&C_WeaponElite::`vftable'{for `IClientUnknown'};
  v3->C_WeaponCSBase::C_BaseCombatWeapon::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientRenderable::__vftable = (IClientRenderable_vtbl *)&C_WeaponElite::`vftable'{for `IClientRenderable'};
  v3->C_WeaponCSBase::C_BaseCombatWeapon::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientNetworkable::__vftable = (IClientNetworkable_vtbl *)&C_WeaponElite::`vftable'{for `IClientNetworkable'};
  v3->C_WeaponCSBase::C_BaseCombatWeapon::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientThinkable::__vftable = (IClientThinkable_vtbl *)&C_WeaponElite::`vftable'{for `IClientThinkable'};
  v3->C_WeaponCSBase::C_BaseCombatWeapon::C_BaseAnimating::C_BaseEntity::IClientModelRenderable::__vftable = (IClientModelRenderable_vtbl *)&C_WeaponElite::`vftable';
  LOBYTE(v3[1].C_WeaponCSBase::C_BaseCombatWeapon::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientRenderable::__vftable) = 0;
  v3->Init(this: v3, a2: entnum, a3: serialNum);
  return &v3->IClientNetworkable;
}

//------------------------------------------------------------------------------
// Address: 0x10428740
// Name: _dynamic_initializer_for__g_Cweapon_eliteFoo__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_Cweapon_eliteFoo__()
{
  CClassMap *ClassMap; // eax
  int result; // eax

  ClassMap = GetClassMap();
  result = ((int (__thiscall *)(CClassMap *, const char *, const char *, int, C_WeaponCSBaseGun *(__cdecl *)()))ClassMap->Add)(
             a1: ClassMap,
             a2: "weapon_elite",
             a3: "C_WeaponElite",
             a4: 3512,
             a5: CC_WeaponEliteFactory);
  __g_C_WeaponEliteClientClass.m_pMapClassname = "weapon_elite";
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10428790
// Name: _dynamic_initializer_for____g_C_WeaponFamasClientClass__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ClientClass *dynamic_initializer_for____g_C_WeaponFamasClientClass__()
{
  ClientClass *result; // eax

  result = g_pClientClassHead;
  __g_C_WeaponFamasClientClass.m_pNext = g_pClientClassHead;
  g_pClientClassHead = &__g_C_WeaponFamasClientClass;
  return result;
}

// ============================================================
// Overlay from server (Missing functions)
// ============================================================
namespace server {

//------------------------------------------------------------------------------
// Address: 0x102EB150
// Name: public: virtual class ServerClass __near * CWeaponElite::GetServerClass(void)
// Source: json
//------------------------------------------------------------------------------
ServerClass *__thiscall CWeaponElite::GetServerClass(CWeaponElite *this)
{
  return &g_CWeaponElite_ClassReg;
}

//------------------------------------------------------------------------------
// Address: 0x102EB160
// Name: public: virtual void weapon_elitePrecache::CResourcePrecacher::Cache(class IPrecacheHandler __near *,bool,struct ResourceList_t__ __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall weapon_elitePrecache::CResourcePrecacher::Cache(
        weapon_elitePrecache::CResourcePrecacher *this,
        IPrecacheHandler *pPrecacheHandler,
        BOOL bPrecache,
        struct ResourceList_t__ *hResourceList,
        bool bIgnoreConditionals)
{
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: ENTITY,
    a3: "weapon_elite",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x102EB190
// Name: public: virtual void CWeaponElite::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall CWeaponElite::Spawn(CWeaponElite *this)
{
  CWeaponCSBase::Spawn(this);
}

//------------------------------------------------------------------------------
// Address: 0x102EB1A0
// Name: public: virtual void CWeaponElite::Precache(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CWeaponElite::Precache(CWeaponElite *this@<ecx>, bool (__cdecl *a2)(const char *)@<edi>)
{
  const CCSWeaponInfo *CSWpnData; // eax

  this->m_inPrecache = true;
  CWeaponCSBase::Precache(this);
  CBaseEntity::PrecacheModel(a1: a2, name: "models/weapons/w_eq_eholster_elite.mdl", bPreload: true);
  CBaseEntity::PrecacheModel(a1: a2, name: "models/weapons/w_eq_eholster.mdl", bPreload: true);
  CBaseEntity::PrecacheModel(a1: a2, name: "models/weapons/w_pist_elite_single.mdl", bPreload: true);
  CSWpnData = CWeaponCSBase::GetCSWpnData(this);
  this->m_droppedModelIndex = CBaseEntity::PrecacheModel(a1: a2, name: CSWpnData->m_szDroppedModel, bPreload: true);
  PrecacheEffect(pEffectName: "CS_MuzzleFlash");
  this->m_inPrecache = false;
}

//------------------------------------------------------------------------------
// Address: 0x102EB210
// Name: public: virtual char const __near * CWeaponElite::GetWorldModel(void)const
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CWeaponElite::GetWorldModel(CWeaponElite *this)
{
  if ( CBaseCombatWeapon::GetOwner(this) != nullptr || this->m_inPrecache )
    return CBaseCombatWeapon::GetWorldModel(this);
  else
    return CWeaponCSBase::GetCSWpnData(this)->m_szDroppedModel;
}

//------------------------------------------------------------------------------
// Address: 0x102EB240
// Name: public: virtual int CWeaponElite::GetWorldModelIndex(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CWeaponElite::GetWorldModelIndex(CWeaponElite *this)
{
  if ( CBaseCombatWeapon::GetOwner(this) != nullptr || this->m_inPrecache )
    return this->m_iWorldModelIndex.m_Value;
  else
    return this->m_droppedModelIndex;
}

//------------------------------------------------------------------------------
// Address: 0x102EB270
// Name: public: virtual bool CWeaponElite::SendWeaponAnim(int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CWeaponElite::SendWeaponAnim(CWeaponElite *this, Activity iActivity)
{
  Activity v2; // eax

  v2 = iActivity;
  if ( iActivity == ACT_VM_PRIMARYATTACK )
  {
    if ( (this->m_iClip1.m_Value & 1) == 0 )
      return CWeaponCSBase::SendWeaponAnim(
               this,
               iActivity: (Activity)(this->m_iClip1.m_Value <= 2 ? ACT_VM_DRYFIRE_LEFT : ACT_VM_PRIMARYATTACK));
    v2 = 2 * (this->m_iClip1.m_Value <= 2) + 191;
  }
  return CWeaponCSBase::SendWeaponAnim(this, iActivity: v2);
}

//------------------------------------------------------------------------------
// Address: 0x102EB2D0
// Name: public: virtual void CWeaponElite::WeaponIdle(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWeaponElite::WeaponIdle(CWeaponElite *this)
{
  CWeaponElite_vtbl *v2; // edi
  const CCSWeaponInfo *CSWpnData; // eax

  if ( this->m_flTimeWeaponIdle.m_Value <= gpGlobals->curtime && this->m_iClip1.m_Value >= 2 )
  {
    this->SendWeaponAnim(this, a2: 183);
    v2 = this->__vftable;
    CSWpnData = CWeaponCSBase::GetCSWpnData(this);
    ((void (__thiscall *)(CWeaponElite *, _DWORD))v2->SetWeaponIdleTime)(
      a1: this,
      a2: CSWpnData->m_flIdleInterval + gpGlobals->curtime);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102EB3C0
// Name: public: virtual void CWeaponElite::PrimaryAttack(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CWeaponElite::PrimaryAttack(CWeaponElite *this@<ecx>, int a2@<ebx>)
{
  CCSPlayer *PlayerOwner; // edi
  const CCSWeaponInfo *CSWpnData; // eax
  CSWeaponMode v5; // [esp+4h] [ebp-1Ch]
  QAngle punchAngle; // [esp+10h] [ebp-10h] BYREF

  PlayerOwner = CWeaponCSBase::GetPlayerOwner(this);
  if ( PlayerOwner != nullptr )
  {
    v5 = (this->m_iClip1.m_Value & 1) != 0;
    CSWpnData = CWeaponCSBase::GetCSWpnData(this);
    if ( CWeaponCSBaseGun::CSBaseGunFire(this, a2, flCycleTime: CSWpnData->m_flCycleTime, weaponMode: v5) != 0
      && weapon_recoil_legacy.m_pParent != nullptr
      && weapon_recoil_legacy.m_pParent->m_Value.m_nValue != 0 )
    {
      punchAngle = CBasePlayer::GetPunchAngle(this: PlayerOwner)->m_Value;
      punchAngle.x = punchAngle.x - 2.0;
      CBasePlayer::SetPunchAngle(this: PlayerOwner, &punchAngle);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10412430
// Name: DT_WeaponElite::_dynamic_initializer_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
int DT_WeaponElite::_dynamic_initializer_for__g_SendTable__()
{
  SendTable::SendTable(this: &DT_WeaponElite::g_SendTable);
  return atexit(func: DT_WeaponElite::_dynamic_atexit_destructor_for__g_SendTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10412450
// Name: DT_WeaponElite::_dynamic_initializer_for__g_SendTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_WeaponElite::_dynamic_initializer_for__g_SendTableInit__()
{
  int result; // eax

  result = ServerClassInit<DT_WeaponElite::ignored>();
  DT_WeaponElite::g_SendTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10412480
// Name: weapon_elitePrecache::_dynamic_initializer_for__s_ResourcePrecacher__
// Source: json
//------------------------------------------------------------------------------
int weapon_elitePrecache::_dynamic_initializer_for__s_ResourcePrecacher__()
{
  int result; // eax

  result = dword_106DA8A4;
  weapon_elitePrecache::s_ResourcePrecacher.m_pNext = (IResourcePrecacher *)dword_106DA8A4;
  dword_106DA8A4 = (int)&weapon_elitePrecache::s_ResourcePrecacher;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104209B0
// Name: DT_WeaponElite::_dynamic_atexit_destructor_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_WeaponElite::_dynamic_atexit_destructor_for__g_SendTable__()
{
  CAI_BaseNPC::OnSetSchedule(this: (vgui::Panel *)&DT_WeaponElite::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x104124A0
// Name: _dynamic_initializer_for__g_CWeaponFamas_ClassReg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ServerClass *dynamic_initializer_for__g_CWeaponFamas_ClassReg__()
{
  return ServerClass::ServerClass(
           this: &g_CWeaponFamas_ClassReg,
           pNetworkName: "CWeaponFamas",
           pTable: &DT_WeaponFamas::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x104209C0
// Name: _ServerClassInit_DT_WeaponElite::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ServerClassInit_DT_WeaponElite::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__()
{
  SendProp *v0; // esi
  int i; // edi

  v0 = (SendProp *)&_S2_276;
  for ( i = 1; i >= 0; --i )
    SendProp::~SendProp(this: --v0);
}

} // namespace server
