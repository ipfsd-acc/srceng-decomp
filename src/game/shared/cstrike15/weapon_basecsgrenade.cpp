// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/shared/cstrike15/weapon_basecsgrenade.cpp
// Functions: 20
// ============================================================

#include "game\shared\cstrike15\weapon_basecsgrenade.h"

//------------------------------------------------------------------------------
// Address: 0x10229780
// Name: public: virtual class ClientClass __near * C_BaseCSGrenade::GetClientClass(void)
// Source: json
//------------------------------------------------------------------------------
ClientClass *__thiscall C_BaseCSGrenade::GetClientClass(C_BaseCSGrenade *this)
{
  return &__g_C_BaseCSGrenadeClientClass;
}

//------------------------------------------------------------------------------
// Address: 0x10229860
// Name: public: virtual struct datamap_t __near * C_BaseCSGrenade::GetPredDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall C_BaseCSGrenade::GetPredDescMap(C_BaseCSGrenade *this)
{
  return &C_BaseCSGrenade::m_PredMap;
}

//------------------------------------------------------------------------------
// Address: 0x10229870
// Name: public: virtual void C_BaseCSGrenade::Precache(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __usercall C_BaseCSGrenade::Precache(C_BaseCSGrenade *this@<ecx>, int a2@<ebx>)
{
  C_WeaponCSBase::Precache(this, a2);
}

//------------------------------------------------------------------------------
// Address: 0x10229880
// Name: public: virtual bool C_BaseCSGrenade::Deploy(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall C_BaseCSGrenade::Deploy(C_BaseCSGrenade *this)
{
  if ( this->m_bRedraw.m_Value )
    this->m_bRedraw.m_Value = false;
  if ( this->m_bPinPulled.m_Value )
    this->m_bPinPulled.m_Value = false;
  if ( this->m_fThrowTime.m_Value != 0.0 )
    this->m_fThrowTime.m_Value = 0.0;
  return C_WeaponCSBase::Deploy(this);
}

//------------------------------------------------------------------------------
// Address: 0x102298C0
// Name: public: virtual bool C_BaseCSGrenade::Holster(class C_BaseCombatWeapon __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall C_BaseCSGrenade::Holster(C_BaseCSGrenade *this, C_BaseCombatWeapon *pSwitchingTo)
{
  if ( this->m_bRedraw.m_Value )
    this->m_bRedraw.m_Value = false;
  if ( this->m_bPinPulled.m_Value )
    this->m_bPinPulled.m_Value = false;
  if ( this->m_fThrowTime.m_Value != 0.0 )
    this->m_fThrowTime.m_Value = 0.0;
  return C_WeaponCSBase::Holster(this, pSwitchingTo);
}

//------------------------------------------------------------------------------
// Address: 0x10229910
// Name: public: virtual void C_BaseCSGrenade::PrimaryAttack(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall C_BaseCSGrenade::PrimaryAttack(C_BaseCSGrenade *this@<ecx>, int a2@<ebx>, int a3@<edi>)
{
  C_BaseCombatCharacter *v4; // eax
  C_CSPlayer *v5; // edi
  CSWeaponID v6; // eax
  IMDLCache *v7; // edi
  C_BaseCSGrenade_vtbl *v8; // ebx
  double v9; // st7
  float v10; // [esp+8h] [ebp-10h]
  float v12; // [esp+14h] [ebp-4h]

  if ( !this->m_bRedraw.m_Value && !this->m_bPinPulled.m_Value && this->m_fThrowTime.m_Value <= 0.0 )
  {
    C_WeaponCSBase::GetPlayerOwner(this);
    v5 = (C_CSPlayer *)v4;
    if ( v4 != nullptr
      && C_BaseCombatCharacter::GetAmmoCount(this: v4, iAmmoIndex: this->m_iPrimaryAmmoType.m_Value) > 0 )
    {
      v6 = this->GetCSWeaponID(this);
      if ( C_CSPlayer::CanUseGrenade(this: v5, nID: v6) )
      {
        ((void (__thiscall *)(C_BaseCSGrenade *, int, int))this->SendWeaponAnim)(a1: this, a2: 189, a3);
        if ( !this->m_bPinPulled.m_Value )
          this->m_bPinPulled.m_Value = true;
        v7 = mdlcache;
        ((void (__thiscall *)(IMDLCache *, int))mdlcache->BeginLock)(a1: mdlcache, a2);
        v8 = this->C_WeaponCSBase::C_BaseCombatWeapon::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable;
        v10 = C_BaseAnimating::SequenceDuration(this) + *(float *)(gpGlobals.m_Index + 12);
        ((void (__thiscall *)(C_BaseCSGrenade *, _DWORD))v8->SetWeaponIdleTime)(a1: this, a2: LODWORD(v10));
        v9 = C_BaseAnimating::SequenceDuration(this) + *(float *)(gpGlobals.m_Index + 12);
        if ( this->m_flNextPrimaryAttack.m_Value != v9 )
        {
          v12 = v9;
          this->m_flNextPrimaryAttack.m_Value = v12;
        }
        v7->EndLock(this: v7);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10229A20
// Name: public: virtual void C_BaseCSGrenade::SecondaryAttack(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall C_BaseCSGrenade::SecondaryAttack(C_BaseCSGrenade *this@<ecx>, int a2@<edi>)
{
  int v3; // eax
  bool (__thiscall *SendWeaponAnim)(C_BaseCombatWeapon *, int); // edx
  C_BaseCSGrenade_vtbl *v5; // edi
  double v6; // st7
  float v7; // [esp+0h] [ebp-14h]
  float v9; // [esp+10h] [ebp-4h]

  if ( !this->m_bRedraw.m_Value )
  {
    C_WeaponCSBase::GetPlayerOwner(this);
    if ( v3 != 0 )
    {
      SendWeaponAnim = this->SendWeaponAnim;
      if ( (*(_BYTE *)(v3 + 248) & 2) != 0 )
        ((void (__cdecl *)(int))SendWeaponAnim)(a1: 191);
      else
        ((void (__cdecl *)(int))SendWeaponAnim)(a1: 206);
      v5 = this->C_WeaponCSBase::C_BaseCombatWeapon::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable;
      v7 = C_BaseAnimating::SequenceDuration(this) + *(float *)(gpGlobals.m_Index + 12);
      ((void (__thiscall *)(C_BaseCSGrenade *, _DWORD, int))v5->SetWeaponIdleTime)(a1: this, a2: LODWORD(v7), a3: a2);
      v6 = C_BaseAnimating::SequenceDuration(this) + *(float *)(gpGlobals.m_Index + 12);
      if ( this->m_flNextSecondaryAttack.m_Value != v6 )
      {
        v9 = v6;
        this->m_flNextSecondaryAttack.m_Value = v9;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10229AB0
// Name: public: virtual bool C_BaseCSGrenade::Reload(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall C_BaseCSGrenade::Reload(C_BaseCSGrenade *this)
{
  float v2; // xmm0_4
  double v3; // st7
  double v4; // st7
  C_BaseCSGrenade_vtbl *v5; // edi
  float v7; // [esp+4h] [ebp-10h]
  float v8; // [esp+10h] [ebp-4h]
  float v9; // [esp+10h] [ebp-4h]

  if ( this->m_bRedraw.m_Value )
  {
    v2 = *(float *)(gpGlobals.m_Index + 12);
    if ( v2 >= this->m_flNextPrimaryAttack.m_Value && v2 >= this->m_flNextSecondaryAttack.m_Value )
    {
      this->SendWeaponAnim(this, a2: 181);
      v3 = C_BaseAnimating::SequenceDuration(this) + *(float *)(gpGlobals.m_Index + 12);
      if ( this->m_flNextPrimaryAttack.m_Value != v3 )
      {
        v8 = v3;
        this->m_flNextPrimaryAttack.m_Value = v8;
      }
      v4 = C_BaseAnimating::SequenceDuration(this) + *(float *)(gpGlobals.m_Index + 12);
      if ( this->m_flNextSecondaryAttack.m_Value != v4 )
      {
        v9 = v4;
        this->m_flNextSecondaryAttack.m_Value = v9;
      }
      v5 = this->C_WeaponCSBase::C_BaseCombatWeapon::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable;
      v7 = C_BaseAnimating::SequenceDuration(this) + *(float *)(gpGlobals.m_Index + 12);
      ((void (__thiscall *)(C_BaseCSGrenade *, _DWORD))v5->SetWeaponIdleTime)(a1: this, a2: LODWORD(v7));
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10229B80
// Name: public: virtual void C_BaseCSGrenade::ItemPostFrame(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseCSGrenade::ItemPostFrame(C_BaseCSGrenade *this)
{
  C_BasePlayer *v2; // eax
  C_BasePlayer *v3; // edi
  IMDLCache *v4; // edi
  C_BaseCSGrenade_vtbl *v5; // ebx
  double v6; // st7
  float m_Value; // xmm0_4
  float v8; // [esp+4h] [ebp-14h]
  float v9; // [esp+14h] [ebp-4h]

  C_WeaponCSBase::GetPlayerOwner(this);
  v3 = v2;
  if ( v2 != nullptr && C_BasePlayer::GetViewModel(this: v2, index: this->m_nViewModelIndex.m_Value) != nullptr )
  {
    if ( !this->m_bPinPulled.m_Value || (v3->m_nButtons & 1) != 0 )
    {
      m_Value = this->m_fThrowTime.m_Value;
      if ( m_Value <= 0.0 || *(float *)(gpGlobals.m_Index + 12) <= m_Value )
      {
        if ( !this->m_bRedraw.m_Value )
          C_WeaponCSBase::ItemPostFrame(this);
      }
      else
      {
        this->ThrowGrenade(this);
      }
    }
    else
    {
      C_CSPlayer::DoAnimationEvent(this: (C_CSPlayer *)v3, event: PLAYERANIMEVENT_THROW_GRENADE, nData: 0);
      this->StartGrenadeThrow(this);
      v4 = mdlcache;
      mdlcache->BeginLock(this: mdlcache);
      if ( this->m_bPinPulled.m_Value )
        this->m_bPinPulled.m_Value = false;
      this->SendWeaponAnim(this, a2: 188);
      v5 = this->C_WeaponCSBase::C_BaseCombatWeapon::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable;
      v8 = C_BaseAnimating::SequenceDuration(this) + *(float *)(gpGlobals.m_Index + 12);
      ((void (__thiscall *)(C_BaseCSGrenade *, _DWORD))v5->SetWeaponIdleTime)(a1: this, a2: LODWORD(v8));
      v6 = C_BaseAnimating::SequenceDuration(this) + *(float *)(gpGlobals.m_Index + 12);
      if ( this->m_flNextPrimaryAttack.m_Value != v6 )
      {
        v9 = v6;
        this->m_flNextPrimaryAttack.m_Value = v9;
      }
      v4->EndLock(this: v4);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10229CC0
// Name: public: virtual void C_BaseCSGrenade::ThrowGrenade(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseCSGrenade::ThrowGrenade(C_BaseCSGrenade *this)
{
  if ( !this->m_bRedraw.m_Value )
    this->m_bRedraw.m_Value = true;
  if ( this->m_fThrowTime.m_Value != 0.0 )
    this->m_fThrowTime.m_Value = 0.0;
}

//------------------------------------------------------------------------------
// Address: 0x10229CF0
// Name: public: virtual void C_BaseCSGrenade::StartGrenadeThrow(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseCSGrenade::StartGrenadeThrow(C_BaseCSGrenade *this)
{
  float v1; // xmm0_4

  v1 = *(float *)(gpGlobals.m_Index + 12) + 0.1;
  if ( this->m_fThrowTime.m_Value != v1 )
    this->m_fThrowTime.m_Value = v1;
}

//------------------------------------------------------------------------------
// Address: 0x10229D20
// Name: public: C_BaseCSGrenade::C_BaseCSGrenade(void)
// Source: json
//------------------------------------------------------------------------------
C_BaseCSGrenade *__thiscall C_BaseCSGrenade::C_BaseCSGrenade(C_BaseCSGrenade *this)
{
  C_BaseCSGrenade *result; // eax

  C_WeaponCSBase::C_WeaponCSBase(this);
  this->C_WeaponCSBase::C_BaseCombatWeapon::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable = (C_BaseCSGrenade_vtbl *)&C_BaseCSGrenade::`vftable'{for `IClientUnknown'};
  this->C_WeaponCSBase::C_BaseCombatWeapon::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientRenderable::__vftable = (IClientRenderable_vtbl *)&C_BaseCSGrenade::`vftable'{for `IClientRenderable'};
  this->C_WeaponCSBase::C_BaseCombatWeapon::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientNetworkable::__vftable = (IClientNetworkable_vtbl *)&C_BaseCSGrenade::`vftable'{for `IClientNetworkable'};
  this->C_WeaponCSBase::C_BaseCombatWeapon::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientThinkable::__vftable = (IClientThinkable_vtbl *)&C_BaseCSGrenade::`vftable'{for `IClientThinkable'};
  this->C_WeaponCSBase::C_BaseCombatWeapon::C_BaseAnimating::C_BaseEntity::IClientModelRenderable::__vftable = (IClientModelRenderable_vtbl *)&C_BaseCSGrenade::`vftable';
  if ( this->m_bRedraw.m_Value )
    this->m_bRedraw.m_Value = false;
  if ( this->m_bPinPulled.m_Value )
    this->m_bPinPulled.m_Value = false;
  if ( this->m_fThrowTime.m_Value != 0.0 )
    this->m_fThrowTime.m_Value = 0.0;
  result = this;
  if ( this->m_bLoopingSoundPlaying.m_Value )
    this->m_bLoopingSoundPlaying.m_Value = false;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10229DF0
// Name: CC_BaseCSGrenadeFactory
// Source: json
//------------------------------------------------------------------------------
C_BaseCSGrenade *__cdecl CC_BaseCSGrenadeFactory()
{
  C_BaseCSGrenade *v0; // eax

  v0 = (C_BaseCSGrenade *)C_BaseEntity::operator new(stAllocateBlock: 0xDC0u);
  if ( v0 != nullptr )
    return C_BaseCSGrenade::C_BaseCSGrenade(this: v0);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10427D70
// Name: DT_BaseCSGrenade::_dynamic_initializer_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
int DT_BaseCSGrenade::_dynamic_initializer_for__g_RecvTable__()
{
  RecvTable::RecvTable(this: &DT_BaseCSGrenade::g_RecvTable);
  return atexit(func: DT_BaseCSGrenade::_dynamic_atexit_destructor_for__g_RecvTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10427D90
// Name: DT_BaseCSGrenade::_dynamic_initializer_for__g_RecvTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_BaseCSGrenade::_dynamic_initializer_for__g_RecvTableInit__()
{
  int result; // eax

  result = ClientClassInit<DT_BaseCSGrenade::ignored>();
  DT_BaseCSGrenade::g_RecvTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10427DA0
// Name: C_BaseCSGrenade_PredDataDescInit::_dynamic_initializer_for__g_PredMapHolder__
// Source: json
//------------------------------------------------------------------------------
void C_BaseCSGrenade_PredDataDescInit::_dynamic_initializer_for__g_PredMapHolder__()
{
  C_BaseCSGrenade::m_PredMap.dataNumFields = 2;
  C_BaseCSGrenade::m_PredMap.dataDesc = (typedescription_t *)&unk_105B53AC;
}

//------------------------------------------------------------------------------
// Address: 0x10435E40
// Name: DT_BaseCSGrenade::_dynamic_atexit_destructor_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_BaseCSGrenade::_dynamic_atexit_destructor_for__g_RecvTable__()
{
  C_BaseAnimating::ShutdownBoneSetupThreadPool(this: (vgui::PropertyPage *)&DT_BaseCSGrenade::g_RecvTable);
}

//------------------------------------------------------------------------------
// Address: 0x10229DA0
// Name: _C_BaseCSGrenade_CreateObject
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IClientNetworkable *__cdecl C_BaseCSGrenade_CreateObject(int entnum, int serialNum)
{
  C_BaseCSGrenade *v2; // eax
  C_BaseCSGrenade *v3; // eax
  C_BaseCSGrenade *v4; // esi

  v2 = (C_BaseCSGrenade *)C_BaseEntity::operator new(stAllocateBlock: 0xDC0u);
  if ( v2 == nullptr )
    return nullptr;
  v3 = C_BaseCSGrenade::C_BaseCSGrenade(this: v2);
  v4 = v3;
  if ( v3 == nullptr )
    return nullptr;
  v3->Init(this: v3, a2: entnum, a3: serialNum);
  return &v4->IClientNetworkable;
}

//------------------------------------------------------------------------------
// Address: 0x10427DC0
// Name: _dynamic_initializer_for__g_Cweapon_basecsgrenadeFoo__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_Cweapon_basecsgrenadeFoo__()
{
  CClassMap *ClassMap; // eax
  int result; // eax

  ClassMap = GetClassMap();
  result = ((int (__thiscall *)(CClassMap *, const char *, const char *, int, C_BaseCSGrenade *(__cdecl *)()))ClassMap->Add)(
             a1: ClassMap,
             a2: "weapon_basecsgrenade",
             a3: "C_BaseCSGrenade",
             a4: 3520,
             a5: CC_BaseCSGrenadeFactory);
  __g_C_BaseCSGrenadeClientClass.m_pMapClassname = "weapon_basecsgrenade";
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10427DF0
// Name: _dynamic_initializer_for____g_C_WeaponBizonClientClass__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ClientClass *dynamic_initializer_for____g_C_WeaponBizonClientClass__()
{
  ClientClass *result; // eax

  result = g_pClientClassHead;
  __g_C_WeaponBizonClientClass.m_pNext = g_pClientClassHead;
  g_pClientClassHead = &__g_C_WeaponBizonClientClass;
  return result;
}

// ============================================================
// Overlay from server (Missing functions)
// ============================================================
namespace server {

//------------------------------------------------------------------------------
// Address: 0x102E3970
// Name: public: virtual class ServerClass __near * CBaseCSGrenade::GetServerClass(void)
// Source: json
//------------------------------------------------------------------------------
ServerClass *__thiscall CBaseCSGrenade::GetServerClass(CBaseCSGrenade *this)
{
  return &g_CBaseCSGrenade_ClassReg;
}

//------------------------------------------------------------------------------
// Address: 0x102E3980
// Name: public: virtual void CBaseCSGrenade::Precache(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall CBaseCSGrenade::Precache(CBaseCSGrenade *this)
{
  CWeaponCSBase::Precache(this);
}

//------------------------------------------------------------------------------
// Address: 0x102E3990
// Name: public: virtual struct datamap_t __near * CBaseCSGrenade::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CBaseCSGrenade::GetDataDescMap(CBaseCSGrenade *this)
{
  return &CBaseCSGrenade::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x102E39A0
// Name: public: virtual int CBaseCSGrenade::CapabilitiesGet(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBaseCSGrenade::CapabilitiesGet(CBaseCSGrenade *this)
{
  return 0x2000;
}

//------------------------------------------------------------------------------
// Address: 0x102E39B0
// Name: public: virtual void CBaseCSGrenade::EmitGrenade(class Vector,class QAngle,class Vector,class Vector,class CBasePlayer __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseCSGrenade::EmitGrenade(
        CDefaultParticleSystemQuery *this,
        void *pModel,
        const matrix3x4_t *DrawMatrix,
        const matrix3x4_t *pParticles,
        CParticleCollection *nParticleNumber,
        int nBodyPart,
        int nSubModel,
        int nSkin,
        int nAnimationSequence,
        float flAnimationRate,
        float r,
        float g,
        float b,
        float a)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x102E39C0
// Name: public: void CBaseCSGrenade::DecrementAmmo(class CBaseCombatCharacter __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseCSGrenade::DecrementAmmo(CBaseCSGrenade *this, CBaseCombatCharacter *pOwner)
{
  CBaseCombatCharacter::RemoveAmmo(this: pOwner, iCount: 1, iAmmoIndex: this->m_iPrimaryAmmoType.m_Value);
}

//------------------------------------------------------------------------------
// Address: 0x102E39E0
// Name: public: virtual bool CBaseCSGrenade::AllowsAutoSwitchFrom(void)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CBaseCSGrenade::AllowsAutoSwitchFrom(CBaseCSGrenade *this)
{
  return !this->m_bPinPulled.m_Value;
}

//------------------------------------------------------------------------------
// Address: 0x102E3B10
// Name: public: virtual bool CBaseCSGrenade::Deploy(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBaseCSGrenade::Deploy(CBaseCSGrenade *this)
{
  edict_t *m_pPev; // ecx
  edict_t *v3; // ecx
  edict_t *v4; // ecx
  CCSPlayer *PlayerOwner; // esi

  if ( this->m_bRedraw.m_Value )
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
    this->m_bRedraw.m_Value = false;
  }
  if ( this->m_bPinPulled.m_Value )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v3 = this->m_Network.m_pPev;
      if ( v3 != nullptr )
        CBaseEdict::StateChanged(this: &v3->CBaseEdict, offset: 0x5C1u);
    }
    this->m_bPinPulled.m_Value = false;
  }
  if ( this->m_fThrowTime.m_Value != 0.0 )
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
    this->m_fThrowTime.m_Value = 0.0;
  }
  PlayerOwner = CWeaponCSBase::GetPlayerOwner(this);
  if ( PlayerOwner == nullptr )
    return false;
  if ( CBaseCombatCharacter::GetAmmoCount(this: PlayerOwner, iAmmoIndex: this->m_iPrimaryAmmoType.m_Value) <= 0 )
  {
    PlayerOwner->Weapon_Drop(this: PlayerOwner, a2: this, a3: nullptr, a4: nullptr);
    UTIL_Remove(oldObj: this);
    return false;
  }
  return CWeaponCSBase::Deploy(this);
}

//------------------------------------------------------------------------------
// Address: 0x102E3C10
// Name: public: virtual bool CBaseCSGrenade::Holster(class CBaseCombatWeapon __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBaseCSGrenade::Holster(CBaseCSGrenade *this, CBaseCombatWeapon *pSwitchingTo)
{
  edict_t *m_pPev; // ecx
  edict_t *v4; // ecx
  edict_t *v5; // ecx
  CCSPlayer *PlayerOwner; // esi

  if ( this->m_bRedraw.m_Value )
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
    this->m_bRedraw.m_Value = false;
  }
  if ( this->m_bPinPulled.m_Value )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v4 = this->m_Network.m_pPev;
      if ( v4 != nullptr )
        CBaseEdict::StateChanged(this: &v4->CBaseEdict, offset: 0x5C1u);
    }
    this->m_bPinPulled.m_Value = false;
  }
  if ( this->m_fThrowTime.m_Value != 0.0 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v5 = this->m_Network.m_pPev;
      if ( v5 != nullptr )
        CBaseEdict::StateChanged(this: &v5->CBaseEdict, offset: 0x5C4u);
    }
    this->m_fThrowTime.m_Value = 0.0;
  }
  PlayerOwner = CWeaponCSBase::GetPlayerOwner(this);
  if ( PlayerOwner == nullptr )
    return false;
  if ( CBaseCombatCharacter::GetAmmoCount(this: PlayerOwner, iAmmoIndex: this->m_iPrimaryAmmoType.m_Value) <= 0 )
  {
    PlayerOwner->Weapon_Drop(this: PlayerOwner, a2: this, a3: nullptr, a4: nullptr);
    UTIL_Remove(oldObj: this);
  }
  return CWeaponCSBase::Holster(this, pSwitchingTo);
}

//------------------------------------------------------------------------------
// Address: 0x102E3D20
// Name: public: virtual void CBaseCSGrenade::PrimaryAttack(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CBaseCSGrenade::PrimaryAttack(CBaseCSGrenade *this@<ecx>, int a2@<ebx>)
{
  CCSPlayer *PlayerOwner; // ebx
  CSWeaponID v4; // eax
  edict_t *m_pPev; // ecx
  IMDLCache *v6; // edi
  CBaseCSGrenade_vtbl *v7; // ebx
  double v8; // st7
  edict_t *v9; // ecx
  float v11; // [esp+8h] [ebp-10h]
  float v12; // [esp+14h] [ebp-4h]

  if ( !this->m_bRedraw.m_Value && !this->m_bPinPulled.m_Value && this->m_fThrowTime.m_Value <= 0.0 )
  {
    PlayerOwner = CWeaponCSBase::GetPlayerOwner(this);
    if ( PlayerOwner != nullptr
      && CBaseCombatCharacter::GetAmmoCount(this: PlayerOwner, iAmmoIndex: this->m_iPrimaryAmmoType.m_Value) > 0 )
    {
      v4 = this->GetCSWeaponID(this);
      if ( CCSPlayer::CanUseGrenade(this: PlayerOwner, nID: v4) )
      {
        ((void (__thiscall *)(CBaseCSGrenade *, int, int))this->SendWeaponAnim)(a1: this, a2: 189, a3: a2);
        if ( !this->m_bPinPulled.m_Value )
        {
          if ( this->m_Network.m_TimerEvent.m_bRegistered )
          {
            *((_BYTE *)&this->m_Network + 76) |= 1u;
          }
          else
          {
            m_pPev = this->m_Network.m_pPev;
            if ( m_pPev != nullptr )
              CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x5C1u);
          }
          this->m_bPinPulled.m_Value = true;
        }
        v6 = mdlcache;
        mdlcache->BeginLock(this: mdlcache);
        v7 = this->__vftable;
        v11 = CBaseAnimating::SequenceDuration(this) + gpGlobals->curtime;
        ((void (__thiscall *)(CBaseCSGrenade *, _DWORD))v7->SetWeaponIdleTime)(a1: this, a2: LODWORD(v11));
        v8 = CBaseAnimating::SequenceDuration(this) + gpGlobals->curtime;
        if ( this->m_flNextPrimaryAttack.m_Value != v8 )
        {
          if ( this->m_Network.m_TimerEvent.m_bRegistered )
          {
            *((_BYTE *)&this->m_Network + 76) |= 1u;
          }
          else
          {
            v9 = this->m_Network.m_pPev;
            if ( v9 != nullptr )
              CBaseEdict::StateChanged(this: &v9->CBaseEdict, offset: 0x494u);
          }
          v12 = v8;
          this->m_flNextPrimaryAttack.m_Value = v12;
        }
        v6->EndLock(this: v6);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102E3E70
// Name: public: virtual void CBaseCSGrenade::SecondaryAttack(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CBaseCSGrenade::SecondaryAttack(CBaseCSGrenade *this@<ecx>, int a2@<edi>)
{
  CCSPlayer *PlayerOwner; // eax
  bool (__thiscall *SendWeaponAnim)(CBaseCombatWeapon *, int); // edx
  CBaseCSGrenade_vtbl *v5; // edi
  double v6; // st7
  edict_t *m_pPev; // ecx
  float v8; // [esp+0h] [ebp-14h]
  float v10; // [esp+10h] [ebp-4h]

  if ( !this->m_bRedraw.m_Value )
  {
    PlayerOwner = CWeaponCSBase::GetPlayerOwner(this);
    if ( PlayerOwner != nullptr )
    {
      SendWeaponAnim = this->SendWeaponAnim;
      if ( (PlayerOwner->m_fFlags.m_Value & 2) != 0 )
        ((void (__cdecl *)(int))SendWeaponAnim)(a1: 191);
      else
        ((void (__cdecl *)(int))SendWeaponAnim)(a1: 206);
      v5 = this->__vftable;
      v8 = CBaseAnimating::SequenceDuration(this) + gpGlobals->curtime;
      ((void (__thiscall *)(CBaseCSGrenade *, _DWORD, int))v5->SetWeaponIdleTime)(a1: this, a2: LODWORD(v8), a3: a2);
      v6 = CBaseAnimating::SequenceDuration(this) + gpGlobals->curtime;
      v10 = v6;
      if ( this->m_flNextSecondaryAttack.m_Value != v6 )
      {
        if ( this->m_Network.m_TimerEvent.m_bRegistered )
        {
          *((_BYTE *)&this->m_Network + 76) |= 1u;
          this->m_flNextSecondaryAttack.m_Value = v10;
        }
        else
        {
          m_pPev = this->m_Network.m_pPev;
          if ( m_pPev != nullptr )
            CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x498u);
          this->m_flNextSecondaryAttack.m_Value = v10;
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102E3F40
// Name: public: virtual bool CBaseCSGrenade::Reload(void)
// Source: json
//------------------------------------------------------------------------------
char __usercall CBaseCSGrenade::Reload@<al>(CBaseCSGrenade *this@<ecx>, int a2@<ebx>)
{
  float curtime; // xmm0_4
  double v4; // st7
  edict_t *m_pPev; // ecx
  double v6; // st7
  edict_t *v7; // ecx
  CBaseCSGrenade_vtbl *v8; // edi
  float v10; // [esp+8h] [ebp-10h]
  float v11; // [esp+14h] [ebp-4h]
  float v12; // [esp+14h] [ebp-4h]

  if ( this->m_bRedraw.m_Value )
  {
    curtime = gpGlobals->curtime;
    if ( curtime >= this->m_flNextPrimaryAttack.m_Value && curtime >= this->m_flNextSecondaryAttack.m_Value )
    {
      ((void (__thiscall *)(CBaseCSGrenade *, int, int))this->SendWeaponAnim)(a1: this, a2: 181, a3: a2);
      v4 = CBaseAnimating::SequenceDuration(this) + gpGlobals->curtime;
      if ( this->m_flNextPrimaryAttack.m_Value != v4 )
      {
        if ( this->m_Network.m_TimerEvent.m_bRegistered )
        {
          *((_BYTE *)&this->m_Network + 76) |= 1u;
        }
        else
        {
          m_pPev = this->m_Network.m_pPev;
          if ( m_pPev != nullptr )
            CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x494u);
        }
        v11 = v4;
        this->m_flNextPrimaryAttack.m_Value = v11;
      }
      v6 = CBaseAnimating::SequenceDuration(this) + gpGlobals->curtime;
      if ( this->m_flNextSecondaryAttack.m_Value != v6 )
      {
        if ( this->m_Network.m_TimerEvent.m_bRegistered )
        {
          *((_BYTE *)&this->m_Network + 76) |= 1u;
        }
        else
        {
          v7 = this->m_Network.m_pPev;
          if ( v7 != nullptr )
            CBaseEdict::StateChanged(this: &v7->CBaseEdict, offset: 0x498u);
        }
        v12 = v6;
        this->m_flNextSecondaryAttack.m_Value = v12;
      }
      v8 = this->__vftable;
      v10 = CBaseAnimating::SequenceDuration(this) + gpGlobals->curtime;
      ((void (__thiscall *)(CBaseCSGrenade *, _DWORD))v8->SetWeaponIdleTime)(a1: this, a2: LODWORD(v10));
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x102E4060
// Name: public: virtual void CBaseCSGrenade::ItemPostFrame(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CBaseCSGrenade::ItemPostFrame(CBaseCSGrenade *this@<ecx>, int a2@<esi>)
{
  CCSPlayer *PlayerOwner; // ebx
  edict_t *m_pPev; // ecx
  CBaseCSGrenade_vtbl *v5; // esi
  double v6; // st7
  edict_t *v7; // ecx
  IGameEvent *v8; // esi
  const char *pszValue; // edi
  int v10; // eax
  float m_Value; // xmm0_4
  float v12; // [esp+8h] [ebp-14h]
  IMDLCache *cacheCriticalSection; // [esp+14h] [ebp-8h]
  float v14; // [esp+18h] [ebp-4h]

  PlayerOwner = CWeaponCSBase::GetPlayerOwner(this);
  if ( PlayerOwner != nullptr
    && CBasePlayer::GetViewModel(this: PlayerOwner, index: this->m_nViewModelIndex.m_Value) != nullptr )
  {
    if ( !this->m_bPinPulled.m_Value || (PlayerOwner->m_nButtons & 1) != 0 )
    {
      m_Value = this->m_fThrowTime.m_Value;
      if ( m_Value <= 0.0 || gpGlobals->curtime <= m_Value )
      {
        if ( this->m_bRedraw.m_Value )
        {
          if ( gpGlobals->curtime > this->m_flTimeWeaponIdle.m_Value )
          {
            if ( CBaseCombatCharacter::GetAmmoCount(this: PlayerOwner, iAmmoIndex: this->m_iPrimaryAmmoType.m_Value) > 0 )
            {
              CBaseCombatCharacter::SwitchToNextBestWeapon(this: PlayerOwner, pCurrent: this);
            }
            else
            {
              PlayerOwner->Weapon_Drop(this: PlayerOwner, a2: this, a3: nullptr, a4: nullptr);
              UTIL_Remove(oldObj: this);
            }
          }
        }
        else
        {
          CWeaponCSBase::ItemPostFrame(this);
        }
      }
      else
      {
        CBaseCombatCharacter::RemoveAmmo(this: PlayerOwner, iCount: 1, iAmmoIndex: this->m_iPrimaryAmmoType.m_Value);
        this->ThrowGrenade(this);
      }
    }
    else
    {
      CCSPlayer::DoAnimationEvent(this: PlayerOwner, event: PLAYERANIMEVENT_THROW_GRENADE, nData: 0);
      ((void (__thiscall *)(CBaseCSGrenade *, int))this->StartGrenadeThrow)(a1: this, a2);
      cacheCriticalSection = mdlcache;
      ((void (*)(void))mdlcache->BeginLock)();
      if ( this->m_bPinPulled.m_Value )
      {
        if ( this->m_Network.m_TimerEvent.m_bRegistered )
        {
          *((_BYTE *)&this->m_Network + 76) |= 1u;
        }
        else
        {
          m_pPev = this->m_Network.m_pPev;
          if ( m_pPev != nullptr )
            CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x5C1u);
        }
        this->m_bPinPulled.m_Value = false;
      }
      this->SendWeaponAnim(this, a2: 188);
      v5 = this->__vftable;
      v12 = CBaseAnimating::SequenceDuration(this) + gpGlobals->curtime;
      ((void (__thiscall *)(CBaseCSGrenade *, _DWORD))v5->SetWeaponIdleTime)(a1: this, a2: LODWORD(v12));
      v6 = CBaseAnimating::SequenceDuration(this) + gpGlobals->curtime;
      if ( this->m_flNextPrimaryAttack.m_Value != v6 )
      {
        if ( this->m_Network.m_TimerEvent.m_bRegistered )
        {
          *((_BYTE *)&this->m_Network + 76) |= 1u;
        }
        else
        {
          v7 = this->m_Network.m_pPev;
          if ( v7 != nullptr )
            CBaseEdict::StateChanged(this: &v7->CBaseEdict, offset: 0x494u);
        }
        v14 = v6;
        this->m_flNextPrimaryAttack.m_Value = v14;
      }
      v8 = (IGameEvent *)((int (__thiscall *)(IGameEventManager2 *, const char *, _DWORD))gameeventmanager->CreateEventA)(
                           a1: gameeventmanager,
                           a2: "weapon_fire",
                           a3: 0);
      if ( v8 != nullptr )
      {
        pszValue = this->m_iClassname.pszValue;
        if ( pszValue == nullptr )
          pszValue = locale;
        if ( strncmp(first: pszValue, last: "weapon_", count: 7u) == 0 )
          pszValue += 7;
        v10 = engine->GetPlayerUserId(this: engine, a2: PlayerOwner->m_Network.m_pPev);
        v8->SetInt(this: v8, a2: "userid", a3: v10);
        v8->SetString(this: v8, a2: "weapon", a3: pszValue);
        v8->SetBool(this: v8, a2: "silenced", a3: false);
        gameeventmanager->FireEvent(this: gameeventmanager, a2: v8, a3: false);
      }
      cacheCriticalSection->EndLock(this: cacheCriticalSection);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102E42D0
// Name: public: virtual void CBaseCSGrenade::StartGrenadeThrow(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseCSGrenade::StartGrenadeThrow(CBaseCSGrenade *this)
{
  float v1; // xmm0_4
  CNetworkVarBase<float,CBaseCSGrenade::NetworkVar_m_fThrowTime> *p_m_fThrowTime; // esi
  edict_t *m_pPev; // ecx

  v1 = gpGlobals->curtime + 0.1;
  p_m_fThrowTime = &this->m_fThrowTime;
  if ( this->m_fThrowTime.m_Value != v1 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
      p_m_fThrowTime->m_Value = v1;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x5C4u);
      p_m_fThrowTime->m_Value = v1;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102E4340
// Name: public: virtual void CBaseCSGrenade::ThrowGrenade(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseCSGrenade::ThrowGrenade(CBaseCSGrenade *this)
{
  CBaseCombatCharacter *Owner; // esi
  float x; // xmm1_4
  float v4; // xmm1_4
  float *v5; // eax
  float v6; // xmm3_4
  float v7; // xmm4_4
  float v8; // xmm5_4
  int m_iEFlags; // edx
  int (__thiscall *RandomInt)(IUniformRandomStream *, int, int); // edx
  float v11; // xmm3_4
  int v12; // eax
  void (__thiscall *EmitGrenade)(CBaseCSGrenade *, Vector, QAngle, Vector, Vector, CBasePlayer *); // edx
  edict_t *m_pPev; // ecx
  edict_t *v15; // ecx
  CCSPlayer *v16; // edi
  CBaseCombatWeapon *ActiveWeapon; // eax
  int v18; // esi
  const char *v19; // [esp-8h] [ebp-CCh]
  const char *v20; // [esp-4h] [ebp-C8h]
  CGameTrace trace; // [esp+Ch] [ebp-B8h] BYREF
  Vector vUp; // [esp+60h] [ebp-64h] BYREF
  Vector vRight; // [esp+6Ch] [ebp-58h] BYREF
  Vector vecAbsEnd; // [esp+78h] [ebp-4Ch] BYREF
  QAngle angThrow; // [esp+84h] [ebp-40h] BYREF
  Vector vForward; // [esp+90h] [ebp-34h] BYREF
  float flVel; // [esp+9Ch] [ebp-28h]
  Vector vecSrc; // [esp+A0h] [ebp-24h] BYREF
  Vector maxs; // [esp+ACh] [ebp-18h] BYREF
  Vector mins; // [esp+B8h] [ebp-Ch] BYREF
  IHandleEntity savedregs; // [esp+C4h] [ebp+0h] BYREF

  Owner = CBaseCombatWeapon::GetOwner(this);
  if ( Owner != nullptr && Owner->IsPlayer(this: Owner) )
  {
    angThrow = *Owner->LocalEyeAngles(this: Owner);
    x = angThrow.x;
    if ( angThrow.x < 0.0 )
      x = angThrow.x + 360.0;
    if ( x >= 90.0 )
      v4 = -10.0 - (float)(360.0 - x) * 0.8888888888888888;
    else
      v4 = x * 1.111111111111111 - 10.0;
    angThrow.x = v4;
    flVel = (float)(90.0 - v4) * 6.0;
    if ( flVel > 750.0 )
      flVel = 750.0;
    AngleVectors(angles: &angThrow, forward: &vForward, right: &vRight, up: &vUp);
    if ( (Owner->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this: Owner, a2: (int)&savedregs);
    v5 = (float *)Owner->GetViewOffset(this: Owner);
    v6 = *v5 + Owner->m_vecAbsOrigin.x;
    v7 = v5[1] + Owner->m_vecAbsOrigin.y;
    v8 = v5[2] + Owner->m_vecAbsOrigin.z;
    mins.x = -2.0;
    mins.y = -2.0;
    mins.z = -2.0;
    maxs.x = 2.0;
    maxs.y = 2.0;
    maxs.z = 2.0;
    vecSrc.x = v6;
    vecSrc.y = v7;
    vecSrc.z = v8;
    vecAbsEnd.x = (float)(vForward.x * 16.0) + v6;
    vecAbsEnd.y = (float)(vForward.y * 16.0) + v7;
    vecAbsEnd.z = (float)(vForward.z * 16.0) + v8;
    UTIL_TraceHull(
      a1: &savedregs,
      a2: (int)Owner,
      vecAbsStart: &vecSrc,
      &vecAbsEnd,
      hullMin: &mins,
      hullMax: &maxs,
      mask: 0x200400Bu,
      ignore: Owner,
      collisionGroup: 0,
      ptr: &trace);
    m_iEFlags = Owner->m_iEFlags;
    vecSrc = trace.endpos;
    if ( (m_iEFlags & 0x1000) != 0 )
      CBaseEntity::CalcAbsoluteVelocity(this: Owner, a2: (int)&savedregs);
    RandomInt = random->RandomInt;
    v11 = Owner->m_vecAbsVelocity.x + (float)(vForward.x * flVel);
    maxs.y = Owner->m_vecAbsVelocity.y + (float)(vForward.y * flVel);
    maxs.z = Owner->m_vecAbsVelocity.z + (float)(vForward.z * flVel);
    maxs.x = v11;
    mins.x = 600.0;
    v12 = ((int (__stdcall *)(int, int))RandomInt)(a1: -1200, a2: 1200);
    EmitGrenade = this->EmitGrenade;
    mins.y = (float)v12;
    mins.z = 0.0;
    ((void (__thiscall *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))EmitGrenade)(
      a1: this,
      a2: LODWORD(vecSrc.x),
      a3: LODWORD(vecSrc.y),
      a4: LODWORD(vecSrc.z),
      a5: LODWORD(vec3_angle.x),
      a6: LODWORD(vec3_angle.y),
      a7: LODWORD(vec3_angle.z),
      a8: LODWORD(maxs.x),
      a9: LODWORD(maxs.y),
      a10: LODWORD(maxs.z),
      a11: LODWORD(mins.x),
      a12: (float)v12,
      a13: 0,
      a14: Owner);
    if ( !this->m_bRedraw.m_Value )
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
      this->m_bRedraw.m_Value = true;
    }
    if ( this->m_fThrowTime.m_Value != 0.0 )
    {
      if ( this->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&this->m_Network + 76) |= 1u;
      }
      else
      {
        v15 = this->m_Network.m_pPev;
        if ( v15 != nullptr )
          CBaseEdict::StateChanged(this: &v15->CBaseEdict, offset: 0x5C4u);
      }
      this->m_fThrowTime.m_Value = 0.0;
    }
    if ( Owner->IsPlayer(this: Owner) )
    {
      v16 = (CCSPlayer *)__RTDynamicCast(
                           inptr: Owner,
                           VfDelta: 0,
                           SrcType: &CBaseEntity `RTTI Type Descriptor',
                           TargetType: &CCSPlayer `RTTI Type Descriptor',
                           isReference: 0);
      if ( v16 != nullptr )
      {
        ActiveWeapon = CBaseCombatCharacter::GetActiveWeapon(this: Owner);
        if ( ActiveWeapon == nullptr )
          goto LABEL_35;
        v18 = ((int (__thiscall *)(CBaseCombatWeapon *))ActiveWeapon->__vftable[1].GetModelName)(a1: ActiveWeapon);
        CCSPlayer::PlayerUsedGrenade(this: v16, nWeaponID: v18);
        if ( sv_ignoregrenaderadio.m_pParent != nullptr && sv_ignoregrenaderadio.m_pParent->m_Value.m_nValue != 0 )
          goto LABEL_35;
        switch ( v18 )
        {
          case ' ':
            CCSPlayer::Radio(
              this: v16,
              pszRadioSound: "Radio.Flashbang",
              pszRadioText: "#SFUI_TitlesTXT_Flashbang_in_the_hole");
            break;
          case '"':
            v20 = "#SFUI_TitlesTXT_Smoke_in_the_hole";
            v19 = "Radio.Smoke";
            goto LABEL_34;
          case '#':
            v20 = "#SFUI_TitlesTXT_Molotov_in_the_hole";
            v19 = "Radio.Molotov";
            goto LABEL_34;
          case '$':
            v20 = "#SFUI_TitlesTXT_Decoy_in_the_hole";
            v19 = "Radio.Decoy";
            goto LABEL_34;
          default:
            break;
        }
        v20 = "#SFUI_TitlesTXT_Fire_in_the_hole";
        v19 = "Radio.FireInTheHole";
LABEL_34:
        CCSPlayer::Radio(this: v16, pszRadioSound: v19, pszRadioText: v20);
LABEL_35:
        CCSGameStats::IncrementStat(
          this: &CCS_GameStats,
          pPlayer: v16,
          statId: CSSTAT_GRENADES_THROWN,
          iDelta: 1,
          bPlayerOnly: false);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102E4790
// Name: public: virtual void CBaseCSGrenade::DropGrenade(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseCSGrenade::DropGrenade(CBaseCSGrenade *this)
{
  CBaseCombatCharacter *Owner; // esi
  int m_iEFlags; // ecx
  float *v4; // eax
  float v5; // xmm1_4
  float v6; // xmm2_4
  unsigned int v7; // ecx
  int (__thiscall *RandomInt)(IUniformRandomStream *, int, int); // eax
  float z; // edi
  int v10; // eax
  void (__thiscall *EmitGrenade)(CBaseCSGrenade *, Vector, QAngle, Vector, Vector, CBasePlayer *); // edx
  CCSPlayer *v12; // eax
  edict_t *m_pPev; // ecx
  edict_t *v14; // ecx
  __int64 vecVel; // [esp+Ch] [ebp-30h]
  Vector vForward; // [esp+18h] [ebp-24h] BYREF
  Vector vecSrc; // [esp+24h] [ebp-18h]
  float v18; // [esp+30h] [ebp-Ch]
  float v19; // [esp+34h] [ebp-8h]
  float v20; // [esp+38h] [ebp-4h]
  int savedregs; // [esp+3Ch] [ebp+0h] BYREF

  Owner = CBaseCombatWeapon::GetOwner(this);
  if ( Owner != nullptr && Owner->IsPlayer(this: Owner) )
  {
    CBasePlayer::EyeVectors(this: (CBasePlayer *)Owner, pForward: &vForward, pRight: nullptr, pUp: nullptr);
    m_iEFlags = Owner->m_iEFlags;
    v18 = vForward.x * 16.0;
    v19 = vForward.y * 16.0;
    v20 = vForward.z * 16.0;
    if ( (m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this: Owner, a2: (int)&savedregs);
    v4 = (float *)Owner->GetViewOffset(this: Owner);
    v5 = (float)(Owner->m_vecAbsOrigin.y + v4[1]) + v19;
    v6 = (float)(Owner->m_vecAbsOrigin.z + v4[2]) + v20;
    v7 = (unsigned int)Owner->m_iEFlags >> 12;
    vecSrc.x = (float)(Owner->m_vecAbsOrigin.x + *v4) + v18;
    vecSrc.y = v5;
    vecSrc.z = v6;
    if ( (v7 & 1) != 0 )
      CBaseEntity::CalcAbsoluteVelocity(this: Owner, a2: (int)&savedregs);
    RandomInt = random->RandomInt;
    z = Owner->m_vecAbsVelocity.z;
    vecVel = *(_QWORD *)&Owner->m_vecAbsVelocity.x;
    v18 = 600.0;
    v10 = RandomInt(this: random, a2: -1200, a3: 1200);
    EmitGrenade = this->EmitGrenade;
    v19 = (float)v10;
    v20 = 0.0;
    ((void (__thiscall *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))EmitGrenade)(
      a1: this,
      a2: LODWORD(vecSrc.x),
      a3: LODWORD(vecSrc.y),
      a4: LODWORD(vecSrc.z),
      a5: LODWORD(vec3_angle.x),
      a6: LODWORD(vec3_angle.y),
      a7: LODWORD(vec3_angle.z),
      a8: vecVel,
      a9: HIDWORD(vecVel),
      a10: LODWORD(z),
      a11: LODWORD(v18),
      a12: (float)v10,
      a13: 0,
      a14: Owner);
    if ( Owner->IsPlayer(this: Owner) )
    {
      v12 = (CCSPlayer *)__RTDynamicCast(
                           inptr: Owner,
                           VfDelta: 0,
                           SrcType: &CBaseEntity `RTTI Type Descriptor',
                           TargetType: &CCSPlayer `RTTI Type Descriptor',
                           isReference: 0);
      if ( v12 != nullptr )
        CCSGameStats::IncrementStat(
          this: &CCS_GameStats,
          pPlayer: v12,
          statId: CSSTAT_GRENADES_THROWN,
          iDelta: 1,
          bPlayerOnly: false);
    }
    if ( !this->m_bRedraw.m_Value )
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
      this->m_bRedraw.m_Value = true;
    }
    if ( this->m_fThrowTime.m_Value != 0.0 )
    {
      if ( this->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&this->m_Network + 76) |= 1u;
      }
      else
      {
        v14 = this->m_Network.m_pPev;
        if ( v14 != nullptr )
          CBaseEdict::StateChanged(this: &v14->CBaseEdict, offset: 0x5C4u);
      }
      this->m_fThrowTime.m_Value = 0.0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102E49E0
// Name: public: CBaseCSGrenade::CBaseCSGrenade(void)
// Source: json
//------------------------------------------------------------------------------
CBaseCSGrenade *__thiscall CBaseCSGrenade::CBaseCSGrenade(CBaseCSGrenade *this)
{
  edict_t *m_pPev; // ecx
  edict_t *v3; // ecx
  edict_t *v4; // ecx
  CBaseCSGrenade *result; // eax
  edict_t *v6; // ecx

  CWeaponCSBase::CWeaponCSBase(this);
  this->__vftable = (CBaseCSGrenade_vtbl *)&CBaseCSGrenade::`vftable';
  if ( this->m_bRedraw.m_Value )
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
    this->m_bRedraw.m_Value = false;
  }
  if ( this->m_bPinPulled.m_Value )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v3 = this->m_Network.m_pPev;
      if ( v3 != nullptr )
        CBaseEdict::StateChanged(this: &v3->CBaseEdict, offset: 0x5C1u);
    }
    this->m_bPinPulled.m_Value = false;
  }
  if ( this->m_fThrowTime.m_Value != 0.0 )
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
    this->m_fThrowTime.m_Value = 0.0;
  }
  result = this;
  if ( this->m_bLoopingSoundPlaying.m_Value )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
      this->m_bLoopingSoundPlaying.m_Value = false;
    }
    else
    {
      v6 = this->m_Network.m_pPev;
      if ( v6 != nullptr )
        CBaseEdict::StateChanged(this: &v6->CBaseEdict, offset: 0x5C8u);
      this->m_bLoopingSoundPlaying.m_Value = false;
      return this;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103FF630
// Name: _dynamic_initializer_for__weapon_showproficiency__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__weapon_showproficiency__()
{
  ConVar::ConVar(this: &weapon_showproficiency, pName: "weapon_showproficiency", pDefaultValue: "0", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__weapon_showproficiency__);
}

//------------------------------------------------------------------------------
// Address: 0x104004E0
// Name: _dynamic_initializer_for__grenade__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__grenade__()
{
  CEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(CEntityFactoryDictionary *, CEntityFactory<CBaseGrenade> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &grenade,
           a3: "grenade");
}

//------------------------------------------------------------------------------
// Address: 0x104100A0
// Name: _dynamic_initializer_for__weapon_accuracy_logging__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__weapon_accuracy_logging__()
{
  ConVar::ConVar(this: &weapon_accuracy_logging, pName: "weapon_accuracy_logging", pDefaultValue: "0", flags: 8322);
  return atexit(func: dynamic_atexit_destructor_for__weapon_accuracy_logging__);
}

//------------------------------------------------------------------------------
// Address: 0x10411CD0
// Name: _dynamic_initializer_for__weapon_ak47__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__weapon_ak47__()
{
  CEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(CEntityFactoryDictionary *, CEntityFactory<CAK47> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &weapon_ak47,
           a3: "weapon_ak47");
}

//------------------------------------------------------------------------------
// Address: 0x10411D60
// Name: _dynamic_initializer_for__weapon_aug__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__weapon_aug__()
{
  CEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(CEntityFactoryDictionary *, CEntityFactory<CWeaponAug> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &weapon_aug,
           a3: "weapon_aug");
}

//------------------------------------------------------------------------------
// Address: 0x10411DF0
// Name: _dynamic_initializer_for__weapon_awp__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__weapon_awp__()
{
  CEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(CEntityFactoryDictionary *, CEntityFactory<CWeaponAWP> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &weapon_awp,
           a3: "weapon_awp");
}

//------------------------------------------------------------------------------
// Address: 0x10411E60
// Name: DT_BaseCSGrenade::_dynamic_initializer_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
int DT_BaseCSGrenade::_dynamic_initializer_for__g_SendTable__()
{
  SendTable::SendTable(this: &DT_BaseCSGrenade::g_SendTable);
  return atexit(func: DT_BaseCSGrenade::_dynamic_atexit_destructor_for__g_SendTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10411E80
// Name: DT_BaseCSGrenade::_dynamic_initializer_for__g_SendTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_BaseCSGrenade::_dynamic_initializer_for__g_SendTableInit__()
{
  int result; // eax

  result = ServerClassInit<DT_BaseCSGrenade::ignored>();
  DT_BaseCSGrenade::g_SendTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10411E90
// Name: _dynamic_initializer_for__weapon_basecsgrenade__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__weapon_basecsgrenade__()
{
  CEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(CEntityFactoryDictionary *, CEntityFactory<CBaseCSGrenade> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &weapon_basecsgrenade,
           a3: "weapon_basecsgrenade");
}

//------------------------------------------------------------------------------
// Address: 0x10411EE0
// Name: CBaseCSGrenade_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CBaseCSGrenade_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CBaseCSGrenade>(__formal: nullptr);
  CBaseCSGrenade_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10411F40
// Name: _dynamic_initializer_for__weapon_bizon__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__weapon_bizon__()
{
  CEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(CEntityFactoryDictionary *, CEntityFactory<CWeaponBizon> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &weapon_bizon,
           a3: "weapon_bizon");
}

//------------------------------------------------------------------------------
// Address: 0x104120F0
// Name: _dynamic_initializer_for__weapon_c4__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__weapon_c4__()
{
  CEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(CEntityFactoryDictionary *, CEntityFactory<CC4> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &weapon_c4,
           a3: "weapon_c4");
}

//------------------------------------------------------------------------------
// Address: 0x10412140
// Name: _dynamic_initializer_for__weapon_recoil_decay__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__weapon_recoil_decay__()
{
  ConVar::ConVar(
    this: &weapon_recoil_decay,
    pName: "weapon_recoil_decay",
    pDefaultValue: "3.5",
    flags: 8320,
    pHelpString: "Decay factor for weapon recoil");
  return atexit(func: dynamic_atexit_destructor_for__weapon_recoil_decay__);
}

//------------------------------------------------------------------------------
// Address: 0x10412170
// Name: _dynamic_initializer_for__weapon_recoil_legacy__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__weapon_recoil_legacy__()
{
  ConVar::ConVar(
    this: &weapon_recoil_legacy,
    pName: "weapon_recoil_legacy",
    pDefaultValue: "0",
    flags: 8320,
    pHelpString: "Use legacy recoil system");
  return atexit(func: dynamic_atexit_destructor_for__weapon_recoil_legacy__);
}

//------------------------------------------------------------------------------
// Address: 0x104121A0
// Name: _dynamic_initializer_for__weapon_recoil_extra__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__weapon_recoil_extra__()
{
  ConVar::ConVar(
    this: &weapon_recoil_extra,
    pName: "weapon_recoil_extra",
    pDefaultValue: "0.6",
    flags: 8320,
    pHelpString: "Additional recoil offset multiplier for weapons");
  return atexit(func: dynamic_atexit_destructor_for__weapon_recoil_extra__);
}

//------------------------------------------------------------------------------
// Address: 0x10412220
// Name: _dynamic_initializer_for__weapon_cs_base__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__weapon_cs_base__()
{
  CEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(CEntityFactoryDictionary *, CEntityFactory<CWeaponCSBase> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &weapon_cs_base,
           a3: "weapon_cs_base");
}

//------------------------------------------------------------------------------
// Address: 0x104122C0
// Name: _dynamic_initializer_for__weapon_csbase_gun__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__weapon_csbase_gun__()
{
  CEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(CEntityFactoryDictionary *, CEntityFactory<CWeaponCSBaseGun> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &weapon_csbase_gun,
           a3: "weapon_csbase_gun");
}

//------------------------------------------------------------------------------
// Address: 0x10412330
// Name: _dynamic_initializer_for__weapon_deagle__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__weapon_deagle__()
{
  CEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(CEntityFactoryDictionary *, CEntityFactory<CDEagle> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &weapon_deagle,
           a3: "weapon_deagle");
}

//------------------------------------------------------------------------------
// Address: 0x104123C0
// Name: _dynamic_initializer_for__weapon_decoy__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__weapon_decoy__()
{
  CEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(CEntityFactoryDictionary *, CEntityFactory<CDecoyGrenade> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &weapon_decoy,
           a3: "weapon_decoy");
}

//------------------------------------------------------------------------------
// Address: 0x10412460
// Name: _dynamic_initializer_for__weapon_elite__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__weapon_elite__()
{
  CEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(CEntityFactoryDictionary *, CEntityFactory<CWeaponElite> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &weapon_elite,
           a3: "weapon_elite");
}

//------------------------------------------------------------------------------
// Address: 0x104124F0
// Name: _dynamic_initializer_for__weapon_famas__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__weapon_famas__()
{
  CEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(CEntityFactoryDictionary *, CEntityFactory<CWeaponFamas> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &weapon_famas,
           a3: "weapon_famas");
}

//------------------------------------------------------------------------------
// Address: 0x10412580
// Name: _dynamic_initializer_for__weapon_fiveseven__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__weapon_fiveseven__()
{
  CEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(CEntityFactoryDictionary *, CEntityFactory<CWeaponFiveSeven> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &weapon_fiveseven,
           a3: "weapon_fiveseven");
}

//------------------------------------------------------------------------------
// Address: 0x10412610
// Name: _dynamic_initializer_for__weapon_flashbang__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__weapon_flashbang__()
{
  CEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(CEntityFactoryDictionary *, CEntityFactory<CFlashbang> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &weapon_flashbang,
           a3: "weapon_flashbang");
}

//------------------------------------------------------------------------------
// Address: 0x104126B0
// Name: _dynamic_initializer_for__weapon_g3sg1__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__weapon_g3sg1__()
{
  CEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(CEntityFactoryDictionary *, CEntityFactory<CWeaponG3SG1> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &weapon_g3sg1,
           a3: "weapon_g3sg1");
}

//------------------------------------------------------------------------------
// Address: 0x10412740
// Name: _dynamic_initializer_for__weapon_galil__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__weapon_galil__()
{
  CEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(CEntityFactoryDictionary *, CEntityFactory<CWeaponGalil> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &weapon_galil,
           a3: "weapon_galil");
}

//------------------------------------------------------------------------------
// Address: 0x104127D0
// Name: _dynamic_initializer_for__weapon_glock__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__weapon_glock__()
{
  CEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(CEntityFactoryDictionary *, CEntityFactory<CWeaponGlock> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &weapon_glock,
           a3: "weapon_glock");
}

//------------------------------------------------------------------------------
// Address: 0x10412860
// Name: _dynamic_initializer_for__weapon_hegrenade__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__weapon_hegrenade__()
{
  CEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(CEntityFactoryDictionary *, CEntityFactory<CHEGrenade> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &weapon_hegrenade,
           a3: "weapon_hegrenade");
}

//------------------------------------------------------------------------------
// Address: 0x10412900
// Name: _dynamic_initializer_for__weapon_hkp2000__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__weapon_hkp2000__()
{
  CEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(CEntityFactoryDictionary *, CEntityFactory<CWeaponHKP2000> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &weapon_hkp2000,
           a3: "weapon_hkp2000");
}

//------------------------------------------------------------------------------
// Address: 0x104129D0
// Name: _dynamic_initializer_for__weapon_knife__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__weapon_knife__()
{
  CEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(CEntityFactoryDictionary *, CEntityFactory<CKnife> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &weapon_knife,
           a3: "weapon_knife");
}

//------------------------------------------------------------------------------
// Address: 0x10412AA0
// Name: _dynamic_initializer_for__weapon_m249__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__weapon_m249__()
{
  CEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(CEntityFactoryDictionary *, CEntityFactory<CWeaponM249> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &weapon_m249,
           a3: "weapon_m249");
}

//------------------------------------------------------------------------------
// Address: 0x10412B30
// Name: _dynamic_initializer_for__weapon_m4a1__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__weapon_m4a1__()
{
  CEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(CEntityFactoryDictionary *, CEntityFactory<CWeaponM4A1> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &weapon_m4a1,
           a3: "weapon_m4a1");
}

//------------------------------------------------------------------------------
// Address: 0x10412BC0
// Name: _dynamic_initializer_for__weapon_mac10__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__weapon_mac10__()
{
  CEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(CEntityFactoryDictionary *, CEntityFactory<CWeaponMAC10> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &weapon_mac10,
           a3: "weapon_mac10");
}

//------------------------------------------------------------------------------
// Address: 0x10412C50
// Name: _dynamic_initializer_for__weapon_mag7__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__weapon_mag7__()
{
  CEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(CEntityFactoryDictionary *, CEntityFactory<CWeaponMag7> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &weapon_mag7,
           a3: "weapon_mag7");
}

//------------------------------------------------------------------------------
// Address: 0x10412CE0
// Name: _dynamic_initializer_for__weapon_molotov__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__weapon_molotov__()
{
  CEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(CEntityFactoryDictionary *, CEntityFactory<CMolotovGrenade> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &weapon_molotov,
           a3: "weapon_molotov");
}

//------------------------------------------------------------------------------
// Address: 0x10412D80
// Name: _dynamic_initializer_for__weapon_mp7__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__weapon_mp7__()
{
  CEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(CEntityFactoryDictionary *, CEntityFactory<CWeaponMP7> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &weapon_mp7,
           a3: "weapon_mp7");
}

//------------------------------------------------------------------------------
// Address: 0x10412E10
// Name: _dynamic_initializer_for__weapon_mp9__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__weapon_mp9__()
{
  CEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(CEntityFactoryDictionary *, CEntityFactory<CWeaponMP9> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &weapon_mp9,
           a3: "weapon_mp9");
}

//------------------------------------------------------------------------------
// Address: 0x10412EA0
// Name: _dynamic_initializer_for__weapon_negev__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__weapon_negev__()
{
  CEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(CEntityFactoryDictionary *, CEntityFactory<CWeaponNegev> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &weapon_negev,
           a3: "weapon_negev");
}

//------------------------------------------------------------------------------
// Address: 0x10412F30
// Name: _dynamic_initializer_for__weapon_nova__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__weapon_nova__()
{
  CEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(CEntityFactoryDictionary *, CEntityFactory<CWeaponNOVA> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &weapon_nova,
           a3: "weapon_nova");
}

//------------------------------------------------------------------------------
// Address: 0x10412FC0
// Name: _dynamic_initializer_for__weapon_p250__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__weapon_p250__()
{
  CEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(CEntityFactoryDictionary *, CEntityFactory<CWeaponP250> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &weapon_p250,
           a3: "weapon_p250");
}

//------------------------------------------------------------------------------
// Address: 0x10413050
// Name: _dynamic_initializer_for__weapon_p90__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__weapon_p90__()
{
  CEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(CEntityFactoryDictionary *, CEntityFactory<CWeaponP90> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &weapon_p90,
           a3: "weapon_p90");
}

//------------------------------------------------------------------------------
// Address: 0x104130E0
// Name: _dynamic_initializer_for__weapon_sawedoff__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__weapon_sawedoff__()
{
  CEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(CEntityFactoryDictionary *, CEntityFactory<CWeaponSawedoff> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &weapon_sawedoff,
           a3: "weapon_sawedoff");
}

//------------------------------------------------------------------------------
// Address: 0x10413170
// Name: _dynamic_initializer_for__weapon_scar20__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__weapon_scar20__()
{
  CEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(CEntityFactoryDictionary *, CEntityFactory<CWeaponSCAR20> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &weapon_scar20,
           a3: "weapon_scar20");
}

//------------------------------------------------------------------------------
// Address: 0x10413200
// Name: _dynamic_initializer_for__weapon_sg556__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__weapon_sg556__()
{
  CEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(CEntityFactoryDictionary *, CEntityFactory<CWeaponSG556> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &weapon_sg556,
           a3: "weapon_sg556");
}

//------------------------------------------------------------------------------
// Address: 0x10413290
// Name: _dynamic_initializer_for__weapon_smokegrenade__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__weapon_smokegrenade__()
{
  CEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(CEntityFactoryDictionary *, CEntityFactory<CSmokeGrenade> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &weapon_smokegrenade,
           a3: "weapon_smokegrenade");
}

//------------------------------------------------------------------------------
// Address: 0x10413330
// Name: _dynamic_initializer_for__weapon_ssg08__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__weapon_ssg08__()
{
  CEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(CEntityFactoryDictionary *, CEntityFactory<CWeaponSSG08> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &weapon_ssg08,
           a3: "weapon_ssg08");
}

//------------------------------------------------------------------------------
// Address: 0x104133C0
// Name: _dynamic_initializer_for__weapon_taser__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__weapon_taser__()
{
  CEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(CEntityFactoryDictionary *, CEntityFactory<CWeaponTaser> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &weapon_taser,
           a3: "weapon_taser");
}

//------------------------------------------------------------------------------
// Address: 0x10413450
// Name: _dynamic_initializer_for__weapon_tec9__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__weapon_tec9__()
{
  CEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(CEntityFactoryDictionary *, CEntityFactory<CWeaponTec9> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &weapon_tec9,
           a3: "weapon_tec9");
}

//------------------------------------------------------------------------------
// Address: 0x104134E0
// Name: _dynamic_initializer_for__weapon_ump45__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__weapon_ump45__()
{
  CEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(CEntityFactoryDictionary *, CEntityFactory<CWeaponUMP45> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &weapon_ump45,
           a3: "weapon_ump45");
}

//------------------------------------------------------------------------------
// Address: 0x10413570
// Name: _dynamic_initializer_for__weapon_xm1014__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__weapon_xm1014__()
{
  CEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(CEntityFactoryDictionary *, CEntityFactory<CWeaponXM1014> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &weapon_xm1014,
           a3: "weapon_xm1014");
}

//------------------------------------------------------------------------------
// Address: 0x10419910
// Name: _dynamic_atexit_destructor_for__weapon_showproficiency__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__weapon_showproficiency__()
{
  ConVar::~ConVar(this: &weapon_showproficiency);
}

//------------------------------------------------------------------------------
// Address: 0x1041FF50
// Name: _dynamic_atexit_destructor_for__weapon_accuracy_logging__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__weapon_accuracy_logging__()
{
  ConVar::~ConVar(this: &weapon_accuracy_logging);
}

//------------------------------------------------------------------------------
// Address: 0x10420780
// Name: DT_BaseCSGrenade::_dynamic_atexit_destructor_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_BaseCSGrenade::_dynamic_atexit_destructor_for__g_SendTable__()
{
  CAI_BaseNPC::OnSetSchedule(this: (vgui::Panel *)&DT_BaseCSGrenade::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x104208A0
// Name: _dynamic_atexit_destructor_for__weapon_recoil_decay__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__weapon_recoil_decay__()
{
  ConVar::~ConVar(this: &weapon_recoil_decay);
}

//------------------------------------------------------------------------------
// Address: 0x104208B0
// Name: _dynamic_atexit_destructor_for__weapon_recoil_legacy__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__weapon_recoil_legacy__()
{
  ConVar::~ConVar(this: &weapon_recoil_legacy);
}

//------------------------------------------------------------------------------
// Address: 0x104208C0
// Name: _dynamic_atexit_destructor_for__weapon_recoil_extra__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__weapon_recoil_extra__()
{
  ConVar::~ConVar(this: &weapon_recoil_extra);
}

//------------------------------------------------------------------------------
// Address: 0x102E4AE0
// Name: struct datamap_t __near * DataMapInit<class CBaseCSGrenade>(class CBaseCSGrenade __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CBaseCSGrenade>()
{
  if ( (_S3_155 & 1) == 0 )
  {
    _S3_155 |= 1u;
    nameHolder_491.m_pszBase = "CBaseCSGrenade";
    nameHolder_491.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_491.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_491.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_491.m_Names.m_Size = 0;
    nameHolder_491.m_Names.m_pElements = nullptr;
    nameHolder_491.m_nLenBase = 14;
    atexit(func: DataMapInit_CBaseCSGrenade__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CBaseCSGrenade::m_DataMap.baseMap = &CWeaponCSBase::m_DataMap;
  CBaseCSGrenade::m_DataMap.dataNumFields = 1;
  CBaseCSGrenade::m_DataMap.dataDesc = &dataDesc_450[1];
  return &CBaseCSGrenade::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10400500
// Name: _dynamic_initializer_for____g_CreateCServerGameTagsIServerGameTags_reg___0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
InterfaceReg *dynamic_initializer_for____g_CreateCServerGameTagsIServerGameTags_reg___0()
{
  return InterfaceReg::InterfaceReg(
           this: &_g_CreateCServerGameTagsIServerGameTags_reg_0,
           fn: (void *(__cdecl *)())_CreateCServerGameTagsIServerGameTags_interface_0,
           pName: "ServerGameTags001");
}

//------------------------------------------------------------------------------
// Address: 0x10400520
// Name: _dynamic_initializer_for__sv_allchat__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_allchat__()
{
  ConVar::ConVar(
    this: &sv_allchat,
    pName: "sv_allchat",
    pDefaultValue: "1",
    flags: 256,
    pHelpString: "Players can receive all other players' text chat, no death restrictions");
  return atexit(func: dynamic_atexit_destructor_for__sv_allchat__);
}

//------------------------------------------------------------------------------
// Address: 0x10400550
// Name: _dynamic_initializer_for__g_CBaseMultiplayerPlayer_ScriptDesc__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CBaseMultiplayerPlayer_ScriptDesc__()
{
  if ( byte_105E964C == 0 )
  {
    byte_105E964C = 1;
    g_CBaseMultiplayerPlayer_ScriptDesc.m_pszDescription = "Player";
    g_CBaseMultiplayerPlayer_ScriptDesc.m_pszScriptName = "CBaseMultiplayerPlayer";
    g_CBaseMultiplayerPlayer_ScriptDesc.m_pszClassname = "CBaseMultiplayerPlayer";
    g_CBaseMultiplayerPlayer_ScriptDesc.m_pBaseDesc = GetScriptDesc<CBasePlayer>();
    g_CBaseMultiplayerPlayer_ScriptDesc.pHelper = GetScriptInstanceHelper_CBasePlayer();
  }
  g_CBaseMultiplayerPlayer_ScriptDesc.m_pNextDesc = (ScriptClassDesc_t *)`ScriptClassDesc_t::GetDescList'::`2'::pHead;
  `ScriptClassDesc_t::GetDescList'::`2'::pHead = (int)&g_CBaseMultiplayerPlayer_ScriptDesc;
  return atexit(func: dynamic_atexit_destructor_for__g_CBaseMultiplayerPlayer_ScriptDesc__);
}

//------------------------------------------------------------------------------
// Address: 0x104005C0
// Name: _dynamic_initializer_for__tf_escort_score_rate__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__tf_escort_score_rate__()
{
  ConVar::ConVar(
    this: &tf_escort_score_rate,
    pName: "tf_escort_score_rate",
    pDefaultValue: "1",
    flags: 0x4000,
    pHelpString: "Score for escorting the train, in points per second");
  return atexit(func: dynamic_atexit_destructor_for__tf_escort_score_rate__);
}

//------------------------------------------------------------------------------
// Address: 0x104005F0
// Name: _dynamic_initializer_for__g_CBaseParticleEntity_ClassReg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ServerClass *dynamic_initializer_for__g_CBaseParticleEntity_ClassReg__()
{
  return ServerClass::ServerClass(
           this: &g_CBaseParticleEntity_ClassReg,
           pNetworkName: "CBaseParticleEntity",
           pTable: &DT_BaseParticleEntity::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x10411EB0
// Name: _dynamic_initializer_for__sv_ignoregrenaderadio__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_ignoregrenaderadio__()
{
  ConVar::ConVar(
    this: &sv_ignoregrenaderadio,
    pName: "sv_ignoregrenaderadio",
    pDefaultValue: "0",
    flags: 0,
    pHelpString: "Turn off Fire in the hole messages");
  return atexit(func: dynamic_atexit_destructor_for__sv_ignoregrenaderadio__);
}

//------------------------------------------------------------------------------
// Address: 0x10411EF0
// Name: _dynamic_initializer_for__g_CWeaponBizon_ClassReg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ServerClass *dynamic_initializer_for__g_CWeaponBizon_ClassReg__()
{
  return ServerClass::ServerClass(
           this: &g_CWeaponBizon_ClassReg,
           pNetworkName: "CWeaponBizon",
           pTable: &DT_WeaponBizon::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x104121D0
// Name: _dynamic_initializer_for__g_CWeaponCSBase_ClassReg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ServerClass *dynamic_initializer_for__g_CWeaponCSBase_ClassReg__()
{
  return ServerClass::ServerClass(
           this: &g_CWeaponCSBase_ClassReg,
           pNetworkName: "CWeaponCSBase",
           pTable: &DT_WeaponCSBase::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x104122E0
// Name: _dynamic_initializer_for__g_CDEagle_ClassReg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ServerClass *dynamic_initializer_for__g_CDEagle_ClassReg__()
{
  return ServerClass::ServerClass(
           this: &g_CDEagle_ClassReg,
           pNetworkName: "CDEagle",
           pTable: &DT_WeaponDEagle::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x10420790
// Name: _dynamic_atexit_destructor_for__sv_ignoregrenaderadio__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sv_ignoregrenaderadio__()
{
  ConVar::~ConVar(this: &sv_ignoregrenaderadio);
}

//------------------------------------------------------------------------------
// Address: 0x104207A0
// Name: _ServerClassInit_DT_BaseCSGrenade::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ServerClassInit_DT_BaseCSGrenade::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__()
{
  SendProp *v0; // esi
  int i; // edi

  v0 = (SendProp *)&_S2_269;
  for ( i = 5; i >= 0; --i )
    SendProp::~SendProp(this: --v0);
}

//------------------------------------------------------------------------------
// Address: 0x104207C0
// Name: _DataMapInit_CBaseCSGrenade__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CBaseCSGrenade__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_491);
}

} // namespace server
