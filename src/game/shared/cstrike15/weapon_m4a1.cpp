// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/shared/cstrike15/weapon_m4a1.cpp
// Functions: 29
// ============================================================

#include "game\shared\cstrike15\weapon_m4a1.h"

//------------------------------------------------------------------------------
// Address: 0x102312C0
// Name: public: virtual class ClientClass __near * C_WeaponM4A1::GetClientClass(void)
// Source: json
//------------------------------------------------------------------------------
ClientClass *__thiscall C_WeaponM4A1::GetClientClass(C_WeaponM4A1 *this)
{
  return &__g_C_WeaponM4A1ClientClass;
}

//------------------------------------------------------------------------------
// Address: 0x10231370
// Name: public: virtual struct datamap_t __near * C_WeaponM4A1::GetPredDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall C_WeaponM4A1::GetPredDescMap(C_WeaponM4A1 *this)
{
  return &C_WeaponM4A1::m_PredMap;
}

//------------------------------------------------------------------------------
// Address: 0x10231380
// Name: public: virtual void weapon_m4a1Precache::CResourcePrecacher::Cache(class IPrecacheHandler __near *,bool,struct ResourceList_t__ __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall weapon_m4a1Precache::CResourcePrecacher::Cache(
        weapon_m4a1Precache::CResourcePrecacher *this,
        IPrecacheHandler *pPrecacheHandler,
        BOOL bPrecache,
        struct ResourceList_t__ *hResourceList,
        bool bIgnoreConditionals)
{
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: ENTITY,
    a3: "weapon_m4a1",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x102313B0
// Name: public: virtual void C_WeaponM4A1::Precache(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall C_WeaponM4A1::Precache(C_WeaponM4A1 *this@<ecx>, int a2@<ebx>)
{
  const CCSWeaponInfo *CSWpnData; // eax

  this->m_inPrecache = true;
  C_WeaponCSBase::Precache(this, a2);
  CSWpnData = C_WeaponCSBase::GetCSWpnData(this);
  this->m_silencedModelIndex = C_BaseEntity::PrecacheModel(name: CSWpnData->m_szSilencerModel);
  this->m_inPrecache = false;
}

//------------------------------------------------------------------------------
// Address: 0x102313F0
// Name: public: virtual enum Activity C_WeaponM4A1::GetDeployActivity(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall C_WeaponM4A1::GetDeployActivity(C_WeaponM4A1 *this)
{
  return this->IsSilenced(this) ? 475 : 181;
}

//------------------------------------------------------------------------------
// Address: 0x10231410
// Name: public: virtual int C_WeaponM4A1::GetWorldModelIndex(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall C_WeaponM4A1::GetWorldModelIndex(C_WeaponM4A1 *this)
{
  if ( !this->m_bSilencerOn.m_Value || this->m_inPrecache )
    return C_BaseCombatWeapon::GetWorldModelIndex(this);
  else
    return this->m_silencedModelIndex;
}

//------------------------------------------------------------------------------
// Address: 0x10231430
// Name: public: virtual char const __near * C_WeaponM4A1::GetMuzzleFlashEffectName_1stPerson(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall C_WeaponM4A1::GetMuzzleFlashEffectName_1stPerson(C_WeaponM4A1 *this)
{
  if ( this->m_bSilencerOn.m_Value )
    return (char *)prType;
  else
    return C_WeaponCSBase::GetCSWpnData(this)->m_szMuzzleFlashEffectName_1stPerson;
}

//------------------------------------------------------------------------------
// Address: 0x10231450
// Name: public: virtual char const __near * C_WeaponM4A1::GetMuzzleFlashEffectName_3rdPerson(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall C_WeaponM4A1::GetMuzzleFlashEffectName_3rdPerson(C_WeaponM4A1 *this)
{
  if ( this->m_bSilencerOn.m_Value )
    return (char *)prType;
  else
    return C_WeaponCSBase::GetCSWpnData(this)->m_szMuzzleFlashEffectName_3rdPerson;
}

//------------------------------------------------------------------------------
// Address: 0x10231470
// Name: public: virtual char const __near * C_WeaponM4A1::GetWorldModel(void)const
// Source: json
//------------------------------------------------------------------------------
char *__thiscall C_WeaponM4A1::GetWorldModel(C_WeaponM4A1 *this)
{
  if ( !this->m_bSilencerOn.m_Value || this->m_inPrecache )
    return C_BaseCombatWeapon::GetWorldModel(this);
  else
    return C_WeaponCSBase::GetCSWpnData(this)->m_szSilencerModel;
}

//------------------------------------------------------------------------------
// Address: 0x102314A0
// Name: private: virtual void C_WeaponM4A1::DoFireEffects(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_WeaponM4A1::DoFireEffects(C_WeaponM4A1 *this)
{
  int v1; // eax

  if ( !this->m_bSilencerOn.m_Value )
  {
    C_WeaponCSBase::GetPlayerOwner(this);
    if ( v1 != 0 )
      (*(void (__thiscall **)(int))(*(_DWORD *)v1 + 824))(a1: v1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102314C0
// Name: public: virtual void C_WeaponM4A1::WeaponIdle(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_WeaponM4A1::WeaponIdle(C_WeaponM4A1 *this)
{
  C_WeaponM4A1_vtbl *v2; // edi
  const CCSWeaponInfo *CSWpnData; // eax
  bool (__thiscall *SendWeaponAnim)(C_BaseCombatWeapon *, int); // edx

  if ( this->m_flTimeWeaponIdle.m_Value <= *(float *)(gpGlobals.m_Index + 12) && this->m_iClip1.m_Value != 0 )
  {
    v2 = this->C_WeaponCSBaseGun::C_WeaponCSBase::C_BaseCombatWeapon::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable;
    CSWpnData = C_WeaponCSBase::GetCSWpnData(this);
    ((void (__thiscall *)(C_WeaponM4A1 *, _DWORD))v2->SetWeaponIdleTime)(
      a1: this,
      a2: CSWpnData->m_flIdleInterval + *(float *)(gpGlobals.m_Index + 12));
    SendWeaponAnim = this->SendWeaponAnim;
    if ( this->m_bSilencerOn.m_Value )
      SendWeaponAnim(this, a2: 474);
    else
      SendWeaponAnim(this, a2: 183);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10231530
// Name: public: virtual void C_WeaponM4A1::PrimaryAttack(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_WeaponM4A1::PrimaryAttack(C_WeaponM4A1 *this)
{
  int v2; // eax
  const CCSWeaponInfo *CSWpnData; // eax
  C_BaseEntity *v4; // eax
  C_CSPlayer *v5; // esi
  int m_fFlags; // eax
  CSWeaponMode m_Value; // [esp+1Ch] [ebp-30h]

  C_WeaponCSBase::GetPlayerOwner(this);
  if ( v2 != 0 )
  {
    m_Value = this->m_weaponMode.m_Value;
    CSWpnData = C_WeaponCSBase::GetCSWpnData(this);
    if ( C_WeaponCSBaseGun::CSBaseGunFire(this, flCycleTime: CSWpnData->m_flCycleTime, weaponMode: m_Value) != 0 )
    {
      if ( this->m_bSilencerOn.m_Value )
        this->SendWeaponAnim(this, a2: 471);
      C_WeaponCSBase::GetPlayerOwner(this);
      v5 = (C_CSPlayer *)v4;
      if ( v4 != nullptr
        && weapon_recoil_legacy.m_pParent != nullptr
        && weapon_recoil_legacy.m_pParent->m_Value.m_nValue != 0 )
      {
        C_BaseEntity::CalcAbsoluteVelocity(this: v4);
        if ( fsqrt(
               (float)(v5->m_vecAbsVelocity.x * v5->m_vecAbsVelocity.x)
             + (float)(v5->m_vecAbsVelocity.y * v5->m_vecAbsVelocity.y)) <= 5.0 )
        {
          m_fFlags = v5->m_fFlags;
          if ( (m_fFlags & 1) != 0 )
          {
            if ( (m_fFlags & 2) != 0 )
              C_CSPlayer::KickBack(
                this: v5,
                up_base: 0.60000002,
                lateral_base: 0.30000001,
                up_modifier: 0.2,
                lateral_modifier: 0.0125,
                up_max: 3.25,
                lateral_max: 2.0,
                direction_change: (IUniformRandomStream *)7);
            else
              C_CSPlayer::KickBack(
                this: v5,
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
              this: v5,
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
            this: v5,
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

//------------------------------------------------------------------------------
// Address: 0x102317B0
// Name: public: virtual void C_WeaponM4A1::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_WeaponM4A1::Spawn(C_WeaponM4A1 *this)
{
  C_BaseCombatWeapon::Spawn(this);
  if ( this->m_bSilencerOn.m_Value )
    this->m_bSilencerOn.m_Value = false;
  if ( this->m_weaponMode.m_Value != Primary_Mode )
    this->m_weaponMode.m_Value = Primary_Mode;
  if ( this->m_flDoneSwitchingSilencer.m_Value != 0.0 )
    this->m_flDoneSwitchingSilencer.m_Value = 0.0;
}

//------------------------------------------------------------------------------
// Address: 0x10231800
// Name: public: virtual bool C_WeaponM4A1::Deploy(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall C_WeaponM4A1::Deploy(C_WeaponM4A1 *this)
{
  bool result; // al

  result = C_WeaponCSBase::Deploy(this);
  if ( this->m_flDoneSwitchingSilencer.m_Value != 0.0 )
    this->m_flDoneSwitchingSilencer.m_Value = 0.0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10231830
// Name: public: virtual bool C_WeaponM4A1::Holster(class C_BaseCombatWeapon __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall C_WeaponM4A1::Holster(C_WeaponM4A1 *this, C_BaseCombatWeapon *pSwitchingTo)
{
  bool v2; // al
  CSWeaponMode m_Value; // eax

  if ( this->m_flDoneSwitchingSilencer.m_Value > *(float *)(gpGlobals.m_Index + 12) )
  {
    v2 = !this->m_bSilencerOn.m_Value;
    if ( this->m_bSilencerOn.m_Value != v2 )
      this->m_bSilencerOn.m_Value = v2;
    m_Value = this->m_bSilencerOn.m_Value;
    if ( this->m_weaponMode.m_Value != m_Value )
      this->m_weaponMode.m_Value = m_Value;
  }
  return C_WeaponCSBase::Holster(this, pSwitchingTo);
}

//------------------------------------------------------------------------------
// Address: 0x10231880
// Name: public: virtual void C_WeaponM4A1::Drop(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_WeaponM4A1::Drop(C_WeaponM4A1 *this, C_BaseCombatCharacter *vecVelocity)
{
  bool v2; // al
  CSWeaponMode m_Value; // eax

  if ( this->m_flDoneSwitchingSilencer.m_Value > *(float *)(gpGlobals.m_Index + 12) )
  {
    v2 = !this->m_bSilencerOn.m_Value;
    if ( this->m_bSilencerOn.m_Value != v2 )
      this->m_bSilencerOn.m_Value = v2;
    m_Value = this->m_bSilencerOn.m_Value;
    if ( this->m_weaponMode.m_Value != m_Value )
      this->m_weaponMode.m_Value = m_Value;
  }
  C_C4::OnPickedUp((C_C4 *)this, pNewOwner: vecVelocity);
}

//------------------------------------------------------------------------------
// Address: 0x102318D0
// Name: public: virtual void C_WeaponM4A1::SecondaryAttack(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_WeaponM4A1::SecondaryAttack(C_WeaponM4A1 *this)
{
  C_CSPlayer *v2; // eax
  C_CSPlayer *v3; // ebx
  IGameEvent *v4; // eax
  IGameEvent *v5; // edi
  IGameEvent_vtbl *v6; // ebx
  int UserID; // eax
  float *v8; // ecx
  float v9; // xmm0_4
  float v10; // xmm0_4
  float v11; // xmm0_4
  C_CSPlayer *pPlayer; // [esp+30h] [ebp-4h]

  C_WeaponCSBase::GetPlayerOwner(this);
  v3 = v2;
  pPlayer = v2;
  if ( this->m_bSilencerOn.m_Value )
  {
    this->m_bSilencerOn.m_Value = false;
    if ( this->m_weaponMode.m_Value != Primary_Mode )
      this->m_weaponMode.m_Value = Primary_Mode;
    this->SendWeaponAnim(this, a2: 219);
    v4 = gameeventmanager->CreateEventA(this: gameeventmanager, a2: "silencer_off", a3: 0, a4: 0);
    v5 = v4;
    if ( v4 != nullptr && v3 != nullptr )
    {
LABEL_13:
      v6 = v4->__vftable;
      UserID = C_BasePlayer::GetUserID(this: pPlayer);
      v6->SetInt(this: v5, a2: "userid", a3: UserID);
      gameeventmanager->FireEvent(this: gameeventmanager, a2: v5, a3: false);
    }
  }
  else
  {
    if ( !this->m_bSilencerOn.m_Value )
      this->m_bSilencerOn.m_Value = true;
    if ( this->m_weaponMode.m_Value != Secondary_Mode )
      this->m_weaponMode.m_Value = Secondary_Mode;
    this->SendWeaponAnim(this, a2: 218);
    v4 = gameeventmanager->CreateEventA(this: gameeventmanager, a2: "silencer_on", a3: 0, a4: 0);
    v5 = v4;
    if ( v4 != nullptr && v3 != nullptr )
      goto LABEL_13;
  }
  v8 = (float *)(gpGlobals.m_Index + 12);
  v9 = *(float *)(gpGlobals.m_Index + 12) + 2.0;
  if ( this->m_flDoneSwitchingSilencer.m_Value != v9 )
    this->m_flDoneSwitchingSilencer.m_Value = v9;
  v10 = *v8 + 2.0;
  if ( this->m_flNextSecondaryAttack.m_Value != v10 )
    this->m_flNextSecondaryAttack.m_Value = v10;
  v11 = *v8 + 2.0;
  if ( this->m_flNextPrimaryAttack.m_Value != v11 )
    this->m_flNextPrimaryAttack.m_Value = v11;
  ((void (__thiscall *)(C_WeaponM4A1 *, _DWORD))this->SetWeaponIdleTime)(a1: this, a2: *v8 + 2.0);
}

//------------------------------------------------------------------------------
// Address: 0x10231A80
// Name: public: virtual bool C_WeaponM4A1::Reload(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall C_WeaponM4A1::Reload(C_WeaponM4A1 *this)
{
  C_BaseCombatCharacter *v2; // eax
  C_BaseCombatCharacter *v3; // edi
  int v5; // eax
  int v6; // eax
  int v7; // [esp-8h] [ebp-10h]
  int v8; // [esp-4h] [ebp-Ch]

  C_WeaponCSBase::GetPlayerOwner(this);
  v3 = v2;
  if ( v2 == nullptr )
    return 0;
  v5 = this->GetPrimaryAmmoType(this);
  if ( C_BaseCombatCharacter::GetAmmoCount(this: v3, iAmmoIndex: v5) <= 0 )
    return 0;
  v8 = this->m_bSilencerOn.m_Value ? 472 : 192;
  v7 = ((int (__fastcall *)(C_WeaponM4A1 *))this->GetMaxClip2)(a1: this);
  v6 = this->GetMaxClip1(this);
  if ( C_BaseCombatWeapon::DefaultReload(this, iClipSize1: v6, iClipSize2: v7, iActivity: v8) == 0 )
    return 0;
  ((void (__thiscall *)(C_BaseCombatCharacter *, int))v3->C_BaseFlex::C_BaseAnimatingOverlay::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable[1].ObjectCaps)(
    a1: v3,
    a2: 7);
  if ( v3[1].m_pIntermediateData_FirstPredicted[112] != nullptr )
    v3[1].m_pIntermediateData_FirstPredicted[112] = nullptr;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10231B10
// Name: public: C_WeaponM4A1::C_WeaponM4A1(void)
// Source: json
//------------------------------------------------------------------------------
C_WeaponM4A1 *__thiscall C_WeaponM4A1::C_WeaponM4A1(C_WeaponM4A1 *this)
{
  C_WeaponM4A1 *result; // eax

  C_WeaponCSBaseGun::C_WeaponCSBaseGun(this);
  this->C_WeaponCSBaseGun::C_WeaponCSBase::C_BaseCombatWeapon::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable = (C_WeaponM4A1_vtbl *)&C_WeaponM4A1::`vftable'{for `IClientUnknown'};
  this->C_WeaponCSBaseGun::C_WeaponCSBase::C_BaseCombatWeapon::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientRenderable::__vftable = (IClientRenderable_vtbl *)&C_WeaponM4A1::`vftable'{for `IClientRenderable'};
  this->C_WeaponCSBaseGun::C_WeaponCSBase::C_BaseCombatWeapon::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientNetworkable::__vftable = (IClientNetworkable_vtbl *)&C_WeaponM4A1::`vftable'{for `IClientNetworkable'};
  this->C_WeaponCSBaseGun::C_WeaponCSBase::C_BaseCombatWeapon::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientThinkable::__vftable = (IClientThinkable_vtbl *)&C_WeaponM4A1::`vftable'{for `IClientThinkable'};
  this->C_WeaponCSBaseGun::C_WeaponCSBase::C_BaseCombatWeapon::C_BaseAnimating::C_BaseEntity::IClientModelRenderable::__vftable = (IClientModelRenderable_vtbl *)&C_WeaponM4A1::`vftable';
  if ( this->m_bSilencerOn.m_Value )
    this->m_bSilencerOn.m_Value = false;
  result = this;
  if ( this->m_flDoneSwitchingSilencer.m_Value != 0.0 )
    this->m_flDoneSwitchingSilencer.m_Value = 0.0;
  this->m_inPrecache = false;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10231B80
// Name: public: virtual bool C_WeaponM4A1::IsSilenced(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall C_WeaponM4A1::IsSilenced(C_WeaponM4A1 *this)
{
  return this->m_bSilencerOn.m_Value;
}

//------------------------------------------------------------------------------
// Address: 0x10231BE0
// Name: CC_WeaponM4A1Factory
// Source: json
//------------------------------------------------------------------------------
C_WeaponM4A1 *__cdecl CC_WeaponM4A1Factory()
{
  C_WeaponM4A1 *v0; // eax

  v0 = (C_WeaponM4A1 *)C_BaseEntity::operator new(stAllocateBlock: 0xDC0u);
  if ( v0 != nullptr )
    return C_WeaponM4A1::C_WeaponM4A1(this: v0);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10428F60
// Name: DT_WeaponM4A1::_dynamic_initializer_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
int DT_WeaponM4A1::_dynamic_initializer_for__g_RecvTable__()
{
  RecvTable::RecvTable(this: &DT_WeaponM4A1::g_RecvTable);
  return atexit(func: DT_WeaponM4A1::_dynamic_atexit_destructor_for__g_RecvTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10428F80
// Name: DT_WeaponM4A1::_dynamic_initializer_for__g_RecvTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_WeaponM4A1::_dynamic_initializer_for__g_RecvTableInit__()
{
  int result; // eax

  result = ClientClassInit<DT_WeaponM4A1::ignored>();
  DT_WeaponM4A1::g_RecvTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10428F90
// Name: C_WeaponM4A1_PredDataDescInit::_dynamic_initializer_for__g_PredMapHolder__
// Source: json
//------------------------------------------------------------------------------
void C_WeaponM4A1_PredDataDescInit::_dynamic_initializer_for__g_PredMapHolder__()
{
  C_WeaponM4A1::m_PredMap.dataNumFields = 1;
  C_WeaponM4A1::m_PredMap.dataDesc = (typedescription_t *)&unk_1066BB6C;
}

//------------------------------------------------------------------------------
// Address: 0x10428FE0
// Name: weapon_m4a1Precache::_dynamic_initializer_for__s_ResourcePrecacher__
// Source: json
//------------------------------------------------------------------------------
CBaseResourcePrecacher *weapon_m4a1Precache::_dynamic_initializer_for__s_ResourcePrecacher__()
{
  CBaseResourcePrecacher *result; // eax

  result = CBaseResourcePrecacher::sm_pFirst[0];
  weapon_m4a1Precache::s_ResourcePrecacher.m_pNext = CBaseResourcePrecacher::sm_pFirst[0];
  CBaseResourcePrecacher::sm_pFirst[0] = &weapon_m4a1Precache::s_ResourcePrecacher;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10436100
// Name: DT_WeaponM4A1::_dynamic_atexit_destructor_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_WeaponM4A1::_dynamic_atexit_destructor_for__g_RecvTable__()
{
  C_BaseAnimating::ShutdownBoneSetupThreadPool(this: (vgui::PropertyPage *)&DT_WeaponM4A1::g_RecvTable);
}

//------------------------------------------------------------------------------
// Address: 0x10231B90
// Name: _C_WeaponM4A1_CreateObject
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IClientNetworkable *__cdecl C_WeaponM4A1_CreateObject(int entnum, int serialNum)
{
  C_WeaponM4A1 *v2; // eax
  C_WeaponM4A1 *v3; // eax
  C_WeaponM4A1 *v4; // esi

  v2 = (C_WeaponM4A1 *)C_BaseEntity::operator new(stAllocateBlock: 0xDC0u);
  if ( v2 == nullptr )
    return nullptr;
  v3 = C_WeaponM4A1::C_WeaponM4A1(this: v2);
  v4 = v3;
  if ( v3 == nullptr )
    return nullptr;
  v3->Init(this: v3, a2: entnum, a3: serialNum);
  return &v4->IClientNetworkable;
}

//------------------------------------------------------------------------------
// Address: 0x10428FB0
// Name: _dynamic_initializer_for__g_Cweapon_m4a1Foo__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_Cweapon_m4a1Foo__()
{
  CClassMap *ClassMap; // eax
  int result; // eax

  ClassMap = GetClassMap();
  result = ((int (__thiscall *)(CClassMap *, const char *, const char *, int, C_WeaponM4A1 *(__cdecl *)()))ClassMap->Add)(
             a1: ClassMap,
             a2: "weapon_m4a1",
             a3: "C_WeaponM4A1",
             a4: 3520,
             a5: CC_WeaponM4A1Factory);
  __g_C_WeaponM4A1ClientClass.m_pMapClassname = "weapon_m4a1";
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10429000
// Name: _dynamic_initializer_for____g_C_WeaponMAC10ClientClass__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ClientClass *dynamic_initializer_for____g_C_WeaponMAC10ClientClass__()
{
  ClientClass *result; // eax

  result = g_pClientClassHead;
  __g_C_WeaponMAC10ClientClass.m_pNext = g_pClientClassHead;
  g_pClientClassHead = &__g_C_WeaponMAC10ClientClass;
  return result;
}

// ============================================================
// Overlay from server (Missing functions)
// ============================================================
namespace server {

//------------------------------------------------------------------------------
// Address: 0x102EEE50
// Name: public: virtual class ServerClass __near * CWeaponM4A1::GetServerClass(void)
// Source: json
//------------------------------------------------------------------------------
ServerClass *__thiscall CWeaponM4A1::GetServerClass(CWeaponM4A1 *this)
{
  return &g_CWeaponM4A1_ClassReg;
}

//------------------------------------------------------------------------------
// Address: 0x102EEE60
// Name: public: virtual void weapon_m4a1Precache::CResourcePrecacher::Cache(class IPrecacheHandler __near *,bool,struct ResourceList_t__ __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall weapon_m4a1Precache::CResourcePrecacher::Cache(
        weapon_m4a1Precache::CResourcePrecacher *this,
        IPrecacheHandler *pPrecacheHandler,
        BOOL bPrecache,
        struct ResourceList_t__ *hResourceList,
        bool bIgnoreConditionals)
{
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: ENTITY,
    a3: "weapon_m4a1",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x102EEE90
// Name: public: virtual void CWeaponM4A1::Precache(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CWeaponM4A1::Precache(CWeaponM4A1 *this@<ecx>, bool (__cdecl *a2)(const char *)@<edi>)
{
  const CCSWeaponInfo *CSWpnData; // eax

  this->m_inPrecache = true;
  CWeaponCSBase::Precache(this);
  CSWpnData = CWeaponCSBase::GetCSWpnData(this);
  this->m_silencedModelIndex = CBaseEntity::PrecacheModel(a1: a2, name: CSWpnData->m_szSilencerModel, bPreload: true);
  this->m_inPrecache = false;
}

//------------------------------------------------------------------------------
// Address: 0x102EEED0
// Name: public: virtual enum Activity CWeaponM4A1::GetDeployActivity(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CWeaponM4A1::GetDeployActivity(CWeaponM4A1 *this)
{
  return this->IsSilenced(this) ? 475 : 181;
}

//------------------------------------------------------------------------------
// Address: 0x102EEEF0
// Name: public: virtual char const __near * CWeaponM4A1::GetWorldModel(void)const
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CWeaponM4A1::GetWorldModel(CWeaponM4A1 *this)
{
  if ( !this->m_bSilencerOn.m_Value || this->m_inPrecache )
    return CBaseCombatWeapon::GetWorldModel(this);
  else
    return CWeaponCSBase::GetCSWpnData(this)->m_szSilencerModel;
}

//------------------------------------------------------------------------------
// Address: 0x102EEF20
// Name: private: virtual void CWeaponM4A1::DoFireEffects(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWeaponM4A1::DoFireEffects(CWeaponM4A1 *this)
{
  CCSPlayer *PlayerOwner; // eax

  if ( !this->m_bSilencerOn.m_Value )
  {
    PlayerOwner = CWeaponCSBase::GetPlayerOwner(this);
    if ( PlayerOwner != nullptr )
      PlayerOwner->DoMuzzleFlash(this: PlayerOwner);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102EEF40
// Name: public: virtual void CWeaponM4A1::WeaponIdle(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWeaponM4A1::WeaponIdle(CWeaponM4A1 *this)
{
  CWeaponM4A1_vtbl *v2; // edi
  const CCSWeaponInfo *CSWpnData; // eax
  bool (__thiscall *SendWeaponAnim)(CBaseCombatWeapon *, int); // edx

  if ( this->m_flTimeWeaponIdle.m_Value <= gpGlobals->curtime && this->m_iClip1.m_Value != 0 )
  {
    v2 = this->__vftable;
    CSWpnData = CWeaponCSBase::GetCSWpnData(this);
    ((void (__thiscall *)(CWeaponM4A1 *, _DWORD))v2->SetWeaponIdleTime)(
      a1: this,
      a2: CSWpnData->m_flIdleInterval + gpGlobals->curtime);
    SendWeaponAnim = this->SendWeaponAnim;
    if ( this->m_bSilencerOn.m_Value )
      SendWeaponAnim(this, a2: 474);
    else
      SendWeaponAnim(this, a2: 183);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102EF080
// Name: public: virtual void CWeaponM4A1::PrimaryAttack(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CWeaponM4A1::PrimaryAttack(CWeaponM4A1 *this@<ecx>, int a2@<ebp>)
{
  const CCSWeaponInfo *CSWpnData; // eax
  CCSPlayer *PlayerOwner; // esi
  int v5; // eax
  CSWeaponMode m_Value; // [esp+1Ch] [ebp-30h]
  _DWORD v7[2]; // [esp+40h] [ebp-Ch] BYREF
  int v8; // [esp+48h] [ebp-4h] BYREF
  _UNKNOWN *retaddr; // [esp+4Ch] [ebp+0h]

  v7[0] = a2;
  v7[1] = retaddr;
  if ( CWeaponCSBase::GetPlayerOwner(this) != nullptr )
  {
    m_Value = this->m_weaponMode.m_Value;
    CSWpnData = CWeaponCSBase::GetCSWpnData(this);
    if ( CWeaponCSBaseGun::CSBaseGunFire(this, a2: (int)&v8, flCycleTime: CSWpnData->m_flCycleTime, weaponMode: m_Value) != 0 )
    {
      if ( this->m_bSilencerOn.m_Value )
        this->SendWeaponAnim(this, a2: 471);
      PlayerOwner = CWeaponCSBase::GetPlayerOwner(this);
      if ( PlayerOwner != nullptr
        && weapon_recoil_legacy.m_pParent != nullptr
        && weapon_recoil_legacy.m_pParent->m_Value.m_nValue != 0 )
      {
        if ( (PlayerOwner->m_iEFlags & 0x1000) != 0 )
          CBaseEntity::CalcAbsoluteVelocity(this: PlayerOwner, a2: (int)v7);
        if ( fsqrt(
               (float)(PlayerOwner->m_vecAbsVelocity.x * PlayerOwner->m_vecAbsVelocity.x)
             + (float)(PlayerOwner->m_vecAbsVelocity.y * PlayerOwner->m_vecAbsVelocity.y)) <= 5.0 )
        {
          v5 = PlayerOwner->m_fFlags.m_Value;
          if ( (v5 & 1) != 0 )
          {
            if ( (v5 & 2) != 0 )
              CCSPlayer::KickBack(
                this: PlayerOwner,
                up_base: 0.60000002,
                lateral_base: 0.30000001,
                up_modifier: 0.2,
                lateral_modifier: 0.0125,
                up_max: 3.25,
                lateral_max: 2.0,
                direction_change: (IUniformRandomStream *)7);
            else
              CCSPlayer::KickBack(
                this: PlayerOwner,
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
              this: PlayerOwner,
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
            this: PlayerOwner,
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

//------------------------------------------------------------------------------
// Address: 0x102EF310
// Name: public: virtual void CWeaponM4A1::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWeaponM4A1::Spawn(CWeaponM4A1 *this)
{
  edict_t *m_pPev; // ecx
  edict_t *v3; // ecx
  edict_t *v4; // ecx

  CWeaponCSBase::Spawn(this);
  if ( this->m_bSilencerOn.m_Value )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x5C0u);
    }
    this->m_bSilencerOn.m_Value = false;
  }
  if ( this->m_weaponMode.m_Value != Primary_Mode )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v3 = this->m_Network.m_pPev;
      if ( v3 != nullptr )
        CBaseEdict::StateChanged(this: &v3->CBaseEdict, offset: 0x57Cu);
    }
    this->m_weaponMode.m_Value = Primary_Mode;
  }
  if ( this->m_flDoneSwitchingSilencer.m_Value != 0.0 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
      this->m_flDoneSwitchingSilencer.m_Value = 0.0;
    }
    else
    {
      v4 = this->m_Network.m_pPev;
      if ( v4 != nullptr )
        CBaseEdict::StateChanged(this: &v4->CBaseEdict, offset: 0x5C4u);
      this->m_flDoneSwitchingSilencer.m_Value = 0.0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102EF3E0
// Name: public: virtual bool CWeaponM4A1::Deploy(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CWeaponM4A1::Deploy(CWeaponM4A1 *this)
{
  bool v2; // bl
  edict_t *m_pPev; // ecx

  v2 = CWeaponCSBase::Deploy(this);
  if ( this->m_flDoneSwitchingSilencer.m_Value != 0.0 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x5C4u);
    }
    this->m_flDoneSwitchingSilencer.m_Value = 0.0;
  }
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x102EF440
// Name: public: virtual bool CWeaponM4A1::Holster(class CBaseCombatWeapon __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CWeaponM4A1::Holster(CWeaponM4A1 *this, CBaseCombatWeapon *pSwitchingTo)
{
  CNetworkVarBase<bool,CWeaponM4A1::NetworkVar_m_bSilencerOn> *p_m_bSilencerOn; // esi
  bool v3; // bl
  edict_t *m_pPev; // ecx
  CSWeaponMode m_Value; // edi
  CBaseEdict *v6; // ecx
  CWeaponM4A1 *v8; // [esp+0h] [ebp-4h]

  v8 = this;
  if ( this->m_flDoneSwitchingSilencer.m_Value > gpGlobals->curtime )
  {
    p_m_bSilencerOn = &this->m_bSilencerOn;
    v3 = !this->m_bSilencerOn.m_Value;
    if ( this->m_bSilencerOn.m_Value != v3 )
    {
      if ( this->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&this->m_Network + 76) |= 1u;
      }
      else
      {
        m_pPev = this->m_Network.m_pPev;
        if ( m_pPev != nullptr )
          CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x5C0u);
      }
      p_m_bSilencerOn->m_Value = v3;
    }
    m_Value = p_m_bSilencerOn->m_Value;
    if ( v8->m_weaponMode.m_Value != m_Value )
    {
      if ( v8->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&v8->m_Network + 76) |= 1u;
      }
      else
      {
        v6 = &v8->m_Network.m_pPev->CBaseEdict;
        if ( v6 != nullptr )
          CBaseEdict::StateChanged(this: v6, offset: 0x57Cu);
      }
      v8->m_weaponMode.m_Value = m_Value;
    }
    this = v8;
  }
  return CWeaponCSBase::Holster(this, pSwitchingTo);
}

//------------------------------------------------------------------------------
// Address: 0x102EF4F0
// Name: public: virtual void CWeaponM4A1::Drop(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CWeaponM4A1::Drop(CWeaponM4A1 *this@<ecx>, int a2@<edi>, const Vector *vecVelocity)
{
  CNetworkVarBase<bool,CWeaponM4A1::NetworkVar_m_bSilencerOn> *p_m_bSilencerOn; // esi
  bool v4; // bl
  edict_t *m_pPev; // ecx
  CSWeaponMode m_Value; // edi
  CBaseEdict *v7; // ecx
  int v8; // [esp-Ch] [ebp-10h]
  CWeaponM4A1 *v9; // [esp+0h] [ebp-4h]

  v9 = this;
  if ( this->m_flDoneSwitchingSilencer.m_Value > gpGlobals->curtime )
  {
    p_m_bSilencerOn = &this->m_bSilencerOn;
    v4 = !this->m_bSilencerOn.m_Value;
    v8 = a2;
    if ( this->m_bSilencerOn.m_Value != v4 )
    {
      if ( this->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&this->m_Network + 76) |= 1u;
      }
      else
      {
        m_pPev = this->m_Network.m_pPev;
        if ( m_pPev != nullptr )
          CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x5C0u);
      }
      p_m_bSilencerOn->m_Value = v4;
    }
    m_Value = p_m_bSilencerOn->m_Value;
    if ( v9->m_weaponMode.m_Value != m_Value )
    {
      if ( v9->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&v9->m_Network + 76) |= 1u;
      }
      else
      {
        v7 = &v9->m_Network.m_pPev->CBaseEdict;
        if ( v7 != nullptr )
          CBaseEdict::StateChanged(this: v7, offset: 0x57Cu);
      }
      v9->m_weaponMode.m_Value = m_Value;
    }
    a2 = v8;
    this = v9;
  }
  CWeaponCSBase::Drop(this, a2, vecVelocity);
}

//------------------------------------------------------------------------------
// Address: 0x102EF5A0
// Name: public: virtual void CWeaponM4A1::SecondaryAttack(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWeaponM4A1::SecondaryAttack(CWeaponM4A1 *this)
{
  CCSPlayer *PlayerOwner; // ebx
  edict_t *m_pPev; // ecx
  edict_t *v4; // ecx
  IGameEvent *v5; // eax
  edict_t *v6; // ecx
  edict_t *v7; // ecx
  IGameEvent *v8; // esi
  int v9; // eax
  float v10; // xmm0_4
  edict_t *v11; // ecx
  float v12; // xmm0_4
  edict_t *v13; // ecx
  float v14; // xmm0_4
  edict_t *v15; // ecx

  PlayerOwner = CWeaponCSBase::GetPlayerOwner(this);
  if ( this->m_bSilencerOn.m_Value )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x5C0u);
    }
    this->m_bSilencerOn.m_Value = false;
    if ( this->m_weaponMode.m_Value != Primary_Mode )
    {
      if ( this->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&this->m_Network + 76) |= 1u;
      }
      else
      {
        v4 = this->m_Network.m_pPev;
        if ( v4 != nullptr )
          CBaseEdict::StateChanged(this: &v4->CBaseEdict, offset: 0x57Cu);
      }
      this->m_weaponMode.m_Value = Primary_Mode;
    }
    this->SendWeaponAnim(this, a2: 219);
    v5 = gameeventmanager->CreateEventA(this: gameeventmanager, a2: "silencer_off", a3: 0, a4: 0);
  }
  else
  {
    if ( !this->m_bSilencerOn.m_Value )
    {
      if ( this->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&this->m_Network + 76) |= 1u;
      }
      else
      {
        v6 = this->m_Network.m_pPev;
        if ( v6 != nullptr )
          CBaseEdict::StateChanged(this: &v6->CBaseEdict, offset: 0x5C0u);
      }
      this->m_bSilencerOn.m_Value = true;
    }
    if ( this->m_weaponMode.m_Value != Secondary_Mode )
    {
      if ( this->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&this->m_Network + 76) |= 1u;
      }
      else
      {
        v7 = this->m_Network.m_pPev;
        if ( v7 != nullptr )
          CBaseEdict::StateChanged(this: &v7->CBaseEdict, offset: 0x57Cu);
      }
      this->m_weaponMode.m_Value = Secondary_Mode;
    }
    this->SendWeaponAnim(this, a2: 218);
    v5 = gameeventmanager->CreateEventA(this: gameeventmanager, a2: "silencer_on", a3: 0, a4: 0);
  }
  v8 = v5;
  if ( v5 != nullptr && PlayerOwner != nullptr )
  {
    v9 = engine->GetPlayerUserId(this: engine, a2: PlayerOwner->m_Network.m_pPev);
    v8->SetInt(this: v8, a2: "userid", a3: v9);
    gameeventmanager->FireEvent(this: gameeventmanager, a2: v8, a3: false);
  }
  v10 = gpGlobals->curtime + 2.0;
  if ( this->m_flDoneSwitchingSilencer.m_Value != v10 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v11 = this->m_Network.m_pPev;
      if ( v11 != nullptr )
        CBaseEdict::StateChanged(this: &v11->CBaseEdict, offset: 0x5C4u);
    }
    this->m_flDoneSwitchingSilencer.m_Value = v10;
  }
  v12 = gpGlobals->curtime + 2.0;
  if ( this->m_flNextSecondaryAttack.m_Value != v12 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v13 = this->m_Network.m_pPev;
      if ( v13 != nullptr )
        CBaseEdict::StateChanged(this: &v13->CBaseEdict, offset: 0x498u);
    }
    this->m_flNextSecondaryAttack.m_Value = v12;
  }
  v14 = gpGlobals->curtime + 2.0;
  if ( this->m_flNextPrimaryAttack.m_Value != v14 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v15 = this->m_Network.m_pPev;
      if ( v15 != nullptr )
        CBaseEdict::StateChanged(this: &v15->CBaseEdict, offset: 0x494u);
    }
    this->m_flNextPrimaryAttack.m_Value = v14;
  }
  ((void (__thiscall *)(CWeaponM4A1 *, _DWORD))this->SetWeaponIdleTime)(a1: this, a2: gpGlobals->curtime + 2.0);
}

//------------------------------------------------------------------------------
// Address: 0x102EF840
// Name: public: virtual bool CWeaponM4A1::Reload(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CWeaponM4A1::Reload(CWeaponM4A1 *this)
{
  CCSPlayer *PlayerOwner; // edi
  int v4; // eax
  CWeaponM4A1_vtbl *v5; // ebx
  int (__thiscall *GetMaxClip2)(CBaseCombatWeapon *); // eax
  int v7; // eax
  int v8; // eax
  CBaseEdict *v9; // ecx

  PlayerOwner = CWeaponCSBase::GetPlayerOwner(this);
  if ( PlayerOwner == nullptr )
    return 0;
  v4 = this->GetPrimaryAmmoType(this);
  if ( CBaseCombatCharacter::GetAmmoCount(this: PlayerOwner, iAmmoIndex: v4) <= 0 )
    return 0;
  v5 = this->__vftable;
  GetMaxClip2 = this->GetMaxClip2;
  v7 = this->m_bSilencerOn.m_Value
     ? ((int (__stdcall *)(int))GetMaxClip2)(a1: 472)
     : ((int (__stdcall *)(int))GetMaxClip2)(a1: 192);
  v8 = ((int (__thiscall *)(CWeaponM4A1 *, int))this->GetMaxClip1)(a1: this, a2: v7);
  if ( ((unsigned __int8 (__thiscall *)(CWeaponM4A1 *, int))v5->DefaultReload)(a1: this, a2: v8) == 0 )
    return 0;
  PlayerOwner->SetAnimation(this: PlayerOwner, a2: PLAYER_RELOAD);
  if ( PlayerOwner->m_iShotsFired.m_Value != 0 )
  {
    if ( PlayerOwner->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&PlayerOwner->m_Network + 76) |= 1u;
      PlayerOwner->m_iShotsFired.m_Value = 0;
      return 1;
    }
    v9 = &PlayerOwner->m_Network.m_pPev->CBaseEdict;
    if ( v9 != nullptr )
      CBaseEdict::StateChanged(this: v9, offset: 0x1788u);
    PlayerOwner->m_iShotsFired.m_Value = 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x102EF910
// Name: public: CWeaponM4A1::CWeaponM4A1(void)
// Source: json
//------------------------------------------------------------------------------
CWeaponM4A1 *__thiscall CWeaponM4A1::CWeaponM4A1(CWeaponM4A1 *this)
{
  edict_t *m_pPev; // ecx
  CWeaponM4A1 *result; // eax
  edict_t *v4; // ecx

  CWeaponCSBaseGun::CWeaponCSBaseGun(this);
  this->__vftable = (CWeaponM4A1_vtbl *)&CWeaponM4A1::`vftable';
  if ( this->m_bSilencerOn.m_Value )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x5C0u);
    }
    this->m_bSilencerOn.m_Value = false;
  }
  result = this;
  if ( this->m_flDoneSwitchingSilencer.m_Value != 0.0 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v4 = this->m_Network.m_pPev;
      if ( v4 != nullptr )
        CBaseEdict::StateChanged(this: &v4->CBaseEdict, offset: 0x5C4u);
    }
    this->m_flDoneSwitchingSilencer.m_Value = 0.0;
    result = this;
  }
  this->m_inPrecache = false;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102EF9B0
// Name: public: virtual enum CSWeaponID CWeaponM4A1::GetCSWeaponID(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CWeaponM4A1::GetCSWeaponID(CWeaponM4A1 *this)
{
  return 12;
}

//------------------------------------------------------------------------------
// Address: 0x102EF9C0
// Name: public: virtual bool CWeaponM4A1::IsSilenced(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CWeaponM4A1::IsSilenced(CWeaponM4A1 *this)
{
  return this->m_bSilencerOn.m_Value;
}

//------------------------------------------------------------------------------
// Address: 0x10412B00
// Name: DT_WeaponM4A1::_dynamic_initializer_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
int DT_WeaponM4A1::_dynamic_initializer_for__g_SendTable__()
{
  SendTable::SendTable(this: &DT_WeaponM4A1::g_SendTable);
  return atexit(func: DT_WeaponM4A1::_dynamic_atexit_destructor_for__g_SendTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10412B20
// Name: DT_WeaponM4A1::_dynamic_initializer_for__g_SendTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_WeaponM4A1::_dynamic_initializer_for__g_SendTableInit__()
{
  int result; // eax

  result = ServerClassInit<DT_WeaponM4A1::ignored>();
  DT_WeaponM4A1::g_SendTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10412B50
// Name: weapon_m4a1Precache::_dynamic_initializer_for__s_ResourcePrecacher__
// Source: json
//------------------------------------------------------------------------------
int weapon_m4a1Precache::_dynamic_initializer_for__s_ResourcePrecacher__()
{
  int result; // eax

  result = dword_106DA8A4;
  weapon_m4a1Precache::s_ResourcePrecacher.m_pNext = (IResourcePrecacher *)dword_106DA8A4;
  dword_106DA8A4 = (int)&weapon_m4a1Precache::s_ResourcePrecacher;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10420C30
// Name: DT_WeaponM4A1::_dynamic_atexit_destructor_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_WeaponM4A1::_dynamic_atexit_destructor_for__g_SendTable__()
{
  CAI_BaseNPC::OnSetSchedule(this: (vgui::Panel *)&DT_WeaponM4A1::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x10412B70
// Name: _dynamic_initializer_for__g_CWeaponMAC10_ClassReg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ServerClass *dynamic_initializer_for__g_CWeaponMAC10_ClassReg__()
{
  return ServerClass::ServerClass(
           this: &g_CWeaponMAC10_ClassReg,
           pNetworkName: "CWeaponMAC10",
           pTable: &DT_WeaponMAC10::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x10420C40
// Name: _ServerClassInit_DT_WeaponM4A1::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ServerClassInit_DT_WeaponM4A1::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__()
{
  SendProp *v0; // esi
  int i; // edi

  v0 = (SendProp *)&_S2_287;
  for ( i = 3; i >= 0; --i )
    SendProp::~SendProp(this: --v0);
}

} // namespace server
