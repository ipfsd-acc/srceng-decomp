// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/shared/cstrike15/weapon_csbase.cpp
// Functions: 85
// ============================================================

#include "game\shared\cstrike15\weapon_csbase.h"

//------------------------------------------------------------------------------
// Address: 0x1022A850
// Name: bool IsAmmoType(int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl IsAmmoType(int iAmmoType, const char *pAmmoName)
{
  CCSAmmoDef *AmmoDef; // eax

  AmmoDef = GetAmmoDef();
  return CAmmoDef::Index(this: AmmoDef, psz: pAmmoName) == iAmmoType;
}

//------------------------------------------------------------------------------
// Address: 0x1022A870
// Name: char const __near * GetTranslatedWeaponAlias(char const __near *)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl GetTranslatedWeaponAlias(const char *szAlias)
{
  int v1; // esi

  v1 = 0;
  while ( _V_stricmp(s1: s_WeaponAliasTranslationInfo[v1].alias, s2: szAlias) != 0 )
  {
    if ( (unsigned int)++v1 >= 0x18 )
      return (char *)szAlias;
  }
  return s_WeaponAliasTranslationInfo[v1].translatedAlias;
}

//------------------------------------------------------------------------------
// Address: 0x1022A8B0
// Name: enum CSWeaponID AliasToWeaponID(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CSWeaponID __cdecl AliasToWeaponID(const char *szAlias)
{
  int v1; // esi

  if ( szAlias == nullptr )
    return WEAPON_NONE;
  v1 = 0;
  while ( _V_stricmp(s1: (&off_105B5664)[2 * v1], s2: szAlias) != 0 )
  {
    if ( (unsigned int)++v1 >= 0x2E )
      return WEAPON_NONE;
  }
  return s_weaponAliasInfo[v1].id;
}

//------------------------------------------------------------------------------
// Address: 0x1022A8F0
// Name: char const __near * WeaponIDToAlias(int)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl WeaponIDToAlias(int id)
{
  int v1; // eax

  v1 = 0;
  while ( s_weaponAliasInfo[v1].id != id )
  {
    if ( (unsigned int)++v1 >= 0x2E )
      return nullptr;
  }
  return (&off_105B5664)[2 * v1];
}

//------------------------------------------------------------------------------
// Address: 0x1022A920
// Name: bool IsPrimaryWeapon(enum CSWeaponID)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl IsPrimaryWeapon(CSWeaponID id)
{
  CCSWeaponInfo *WeaponInfo; // eax

  WeaponInfo = GetWeaponInfo(weaponID: id);
  return WeaponInfo != nullptr && WeaponInfo->iSlot == 0;
}

//------------------------------------------------------------------------------
// Address: 0x1022A950
// Name: bool IsSecondaryWeapon(enum CSWeaponID)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl IsSecondaryWeapon(CSWeaponID id)
{
  CCSWeaponInfo *WeaponInfo; // eax

  WeaponInfo = GetWeaponInfo(weaponID: id);
  return WeaponInfo != nullptr && WeaponInfo->iSlot == 1;
}

//------------------------------------------------------------------------------
// Address: 0x1022A980
// Name: public: virtual class ClientClass __near * C_WeaponCSBase::GetClientClass(void)
// Source: json
//------------------------------------------------------------------------------
ClientClass *__thiscall C_WeaponCSBase::GetClientClass(C_WeaponCSBase *this)
{
  return &__g_C_WeaponCSBaseClientClass;
}

//------------------------------------------------------------------------------
// Address: 0x1022AA50
// Name: public: virtual struct datamap_t __near * C_WeaponCSBase::GetPredDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall C_WeaponCSBase::GetPredDescMap(C_WeaponCSBase *this)
{
  return &C_WeaponCSBase::m_PredMap;
}

//------------------------------------------------------------------------------
// Address: 0x1022AA60
// Name: void DrawCrosshairRect(int,int,int,int,bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DrawCrosshairRect(int x0, int y0, int x1, int y1, bool bAdditive)
{
  if ( bAdditive )
    g_pVGuiSurface->DrawTexturedRect(this: g_pVGuiSurface, a2: x0, a3: y0, a4: x1, a5: y1);
  else
    g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: x0, a3: y0, a4: x1, a5: y1);
}

//------------------------------------------------------------------------------
// Address: 0x1022AAB0
// Name: public: class C_CSPlayer __near * C_WeaponCSBase::GetPlayerOwner(void)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_WeaponCSBase::GetPlayerOwner(C_WeaponCSBase *this)
{
  C_BaseCombatCharacter *Owner; // eax

  Owner = C_BaseCombatWeapon::GetOwner(this);
  __RTDynamicCast(
    inptr: Owner,
    VfDelta: 0,
    SrcType: &C_BaseCombatCharacter `RTTI Type Descriptor',
    TargetType: &C_CSPlayer `RTTI Type Descriptor',
    isReference: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1022AAD0
// Name: public: virtual bool C_WeaponCSBase::SendWeaponAnim(int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall C_WeaponCSBase::SendWeaponAnim(C_WeaponCSBase *this, Activity iActivity)
{
  return C_BaseCombatWeapon::SendWeaponAnim(this, iActivity);
}

//------------------------------------------------------------------------------
// Address: 0x1022AAE0
// Name: public: virtual void C_WeaponCSBase::ItemBusyFrame(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_WeaponCSBase::ItemBusyFrame(C_WeaponCSBase *this)
{
  this->UpdateAccuracyPenalty(this);
  C_BaseAnimating::ShutdownBoneSetupThreadPool((vgui::PropertyPage *)this);
}

//------------------------------------------------------------------------------
// Address: 0x1022AB00
// Name: public: class CCSWeaponInfo const __near & C_WeaponCSBase::GetCSWpnData(void)const
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
const CCSWeaponInfo *__thiscall C_WeaponCSBase::GetCSWpnData(C_WeaponCSBase *this)
{
  return (const CCSWeaponInfo *)C_BaseCombatWeapon::GetWpnData(this);
}

//------------------------------------------------------------------------------
// Address: 0x1022AB10
// Name: public: virtual char const __near * C_WeaponCSBase::GetViewModel(int)const
// Source: json
//------------------------------------------------------------------------------
char *__thiscall C_WeaponCSBase::GetViewModel(C_WeaponCSBase *this, int __formal)
{
  C_BaseCombatCharacter *Owner; // eax

  Owner = C_BaseCombatWeapon::GetOwner(this);
  if ( __RTDynamicCast(
         inptr: Owner,
         VfDelta: 0,
         SrcType: &C_BaseCombatCharacter `RTTI Type Descriptor',
         TargetType: &C_CSPlayer `RTTI Type Descriptor',
         isReference: 0) != nullptr )
    return C_BaseCombatWeapon::GetWpnData(this)->szViewModel;
  else
    return C_BaseCombatWeapon::GetViewModel(this, __formal: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1022AB50
// Name: public: virtual void C_WeaponCSBase::Precache(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall C_WeaponCSBase::Precache(C_WeaponCSBase *this@<ecx>, int a2@<ebx>)
{
  const char *v3; // eax
  const char *v4; // eax
  const char *v5; // eax
  const char *v6; // eax

  C_BaseCombatWeapon::Precache(this, a2);
  C_BaseEntity::PrecacheScriptSound(soundname: "Default.ClipEmpty_Pistol");
  C_BaseEntity::PrecacheScriptSound(soundname: "Default.ClipEmpty_Rifle");
  C_BaseEntity::PrecacheScriptSound(soundname: "Default.Zoom");
  v3 = &C_BaseCombatWeapon::GetWpnData(this)[1].aShootSounds[1][44];
  if ( v3 != nullptr && *v3 != 0 )
    PrecacheEffect(pEffectName: v3);
  v4 = &C_BaseCombatWeapon::GetWpnData(this)[1].aShootSounds[2][44];
  if ( v4 != nullptr && *v4 != 0 )
    PrecacheEffect(pEffectName: v4);
  v5 = &C_BaseCombatWeapon::GetWpnData(this)[1].aShootSounds[3][44];
  if ( v5 != nullptr && *v5 != 0 )
    PrecacheEffect(pEffectName: v5);
  v6 = &C_BaseCombatWeapon::GetWpnData(this)[1].aShootSounds[0][32];
  if ( v6 != nullptr && *v6 != 0 )
    PrecacheEffect(pEffectName: v6);
  PrecacheEffect(pEffectName: "gunshotsplash");
}

//------------------------------------------------------------------------------
// Address: 0x1022AC10
// Name: public: virtual bool C_WeaponCSBase::CanBeSelected(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall C_WeaponCSBase::CanBeSelected(C_WeaponCSBase *this)
{
  return this->VisibleInWeaponSelection(this);
}

//------------------------------------------------------------------------------
// Address: 0x1022AC20
// Name: public: virtual bool C_WeaponCSBase::Holster(class C_BaseCombatWeapon __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall C_WeaponCSBase::Holster(C_WeaponCSBase *this, C_BaseCombatWeapon *pSwitchingTo)
{
  C_BaseCombatCharacter *Owner; // eax
  C_BasePlayer *v4; // eax

  Owner = C_BaseCombatWeapon::GetOwner(this);
  v4 = (C_BasePlayer *)__RTDynamicCast(
                         inptr: Owner,
                         VfDelta: 0,
                         SrcType: &C_BaseCombatCharacter `RTTI Type Descriptor',
                         TargetType: &C_CSPlayer `RTTI Type Descriptor',
                         isReference: 0);
  if ( v4 == nullptr )
    return 0;
  C_BasePlayer::SetFOV(this: v4, pRequester: v4, FOV: 0, zoomRate: 0.0, iZoomStart: 0);
  *(_QWORD *)&this->m_gunHeat = 0;
  this->m_timeSinceLastShot = 0.0;
  return C_BaseCombatWeapon::Holster(this, pSwitchingTo);
}

//------------------------------------------------------------------------------
// Address: 0x1022ACA0
// Name: public: virtual void C_WeaponCSBase::DefaultTouch(class C_BaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_WeaponCSBase::DefaultTouch(C_WeaponCSBase *this, C_CSPlayer *pOther)
{
  C_CSPlayer *m_prevOwner; // eax

  m_prevOwner = this->m_prevOwner;
  if ( m_prevOwner == nullptr
    || pOther != m_prevOwner
    || this->m_nextPrevOwnerTouchTime <= *(float *)(gpGlobals.m_Index + 12) )
  {
    CScoreboardScaleform::SetParent((vgui::TreeView *)this, itemIndex: (int)pOther);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1022ACE0
// Name: public: bool C_WeaponCSBase::WantReticleShown(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall C_WeaponCSBase::WantReticleShown(C_WeaponCSBase *this)
{
  return C_BasePlayer::GetLocalPlayer(nSlot: -1) != nullptr
      && *(_DWORD *)&C_BaseCombatWeapon::GetWpnData(this)[1].bParsedScript != 5;
}

//------------------------------------------------------------------------------
// Address: 0x1022AD10
// Name: public: virtual void C_WeaponCSBase::OnDataChanged(enum DataUpdateType_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_WeaponCSBase::OnDataChanged(C_WeaponCSBase *this, DataUpdateType_t type)
{
  C_BaseEntity *v3; // esi

  C_BaseCombatWeapon::OnDataChanged(this, updateType: type);
  v3 = (C_WeaponCSBase *)((char *)this - 8);
  if ( C_BaseEntity::GetPredictable(this: v3) && !v3->ShouldPredict(this: v3) )
    C_BaseEntity::ShutdownPredictable(this: v3);
}

//------------------------------------------------------------------------------
// Address: 0x1022AD50
// Name: public: virtual char const __near * C_WeaponCSBase::GetMuzzleFlashEffectName_1stPerson(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall C_WeaponCSBase::GetMuzzleFlashEffectName_1stPerson(C_WeaponCSBase *this)
{
  return &C_BaseCombatWeapon::GetWpnData(this)[1].aShootSounds[1][44];
}

//------------------------------------------------------------------------------
// Address: 0x1022AD60
// Name: public: virtual char const __near * C_WeaponCSBase::GetHeatEffectName(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall C_WeaponCSBase::GetHeatEffectName(C_WeaponCSBase *this)
{
  return &C_BaseCombatWeapon::GetWpnData(this)[1].aShootSounds[0][32];
}

//------------------------------------------------------------------------------
// Address: 0x1022AD70
// Name: public: virtual char const __near * C_WeaponCSBase::GetMuzzleFlashEffectName_3rdPerson(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall C_WeaponCSBase::GetMuzzleFlashEffectName_3rdPerson(C_WeaponCSBase *this)
{
  return &C_BaseCombatWeapon::GetWpnData(this)[1].aShootSounds[2][44];
}

//------------------------------------------------------------------------------
// Address: 0x1022AD80
// Name: public: virtual char const __near * C_WeaponCSBase::GetEjectBrassEffectName(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall C_WeaponCSBase::GetEjectBrassEffectName(C_WeaponCSBase *this)
{
  return &C_BaseCombatWeapon::GetWpnData(this)[1].aShootSounds[3][44];
}

//------------------------------------------------------------------------------
// Address: 0x1022AD90
// Name: public: virtual int C_WeaponCSBase::GetMuzzleAttachmentIndex_1stPerson(class C_BaseViewModel __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall C_WeaponCSBase::GetMuzzleAttachmentIndex_1stPerson(C_WeaponCSBase *this, C_BaseViewModel *pViewModel)
{
  if ( pViewModel != nullptr )
    return pViewModel->LookupAttachment(this: &pViewModel->IClientRenderable, a2: "1");
  else
    return -1;
}

//------------------------------------------------------------------------------
// Address: 0x1022ADC0
// Name: public: virtual int C_WeaponCSBase::GetEjectBrassAttachmentIndex_1stPerson(class C_BaseViewModel __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall C_WeaponCSBase::GetEjectBrassAttachmentIndex_1stPerson(
        C_WeaponCSBase *this,
        C_BaseViewModel *pViewModel)
{
  if ( pViewModel != nullptr )
    return pViewModel->LookupAttachment(this: &pViewModel->IClientRenderable, a2: "2");
  else
    return -1;
}

//------------------------------------------------------------------------------
// Address: 0x1022ADF0
// Name: public: virtual int C_WeaponCSBase::GetEjectBrassAttachmentIndex_3rdPerson(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall C_WeaponCSBase::GetEjectBrassAttachmentIndex_3rdPerson(C_WeaponCSBase *this)
{
  return this->LookupAttachment(this: &this->IClientRenderable, a2: "muzzle_flash");
}

//------------------------------------------------------------------------------
// Address: 0x1022AE10
// Name: public: virtual bool C_WeaponCSBase::IsFullAuto(void)const
// Source: json
//------------------------------------------------------------------------------
char __thiscall C_WeaponCSBase::IsFullAuto(C_WeaponCSBase *this)
{
  return C_BaseCombatWeapon::GetWpnData(this)[1].szClassName[2];
}

//------------------------------------------------------------------------------
// Address: 0x1022AE20
// Name: public: bool C_WeaponCSBase::PlayEmptySound(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall C_WeaponCSBase::PlayEmptySound(C_WeaponCSBase *this)
{
  const Vector *v2; // edi
  const FileWeaponInfo_t *WpnData; // eax
  IClientNetworkable *v4; // ecx
  int v6; // [esp-Ch] [ebp-3Ch]
  int v7; // [esp-Ch] [ebp-3Ch]
  CPASAttenuationFilter filter; // [esp+10h] [ebp-20h] BYREF

  v2 = this->GetAbsOrigin(this);
  C_RecipientFilter::C_RecipientFilter(this: &filter);
  filter.__vftable = (CPASAttenuationFilter_vtbl *)&CPASFilter::`vftable';
  C_RecipientFilter::AddRecipientsByPVS(this: &filter, origin: v2);
  filter.__vftable = (CPASAttenuationFilter_vtbl *)&CPASAttenuationFilter::`vftable';
  C_RecipientFilter::UsePredictionRules(this: &filter);
  WpnData = C_BaseCombatWeapon::GetWpnData(this);
  v4 = &this->IClientNetworkable;
  if ( *(_DWORD *)&WpnData[1].bParsedScript == 1 )
  {
    v6 = v4->entindex(this: v4);
    C_BaseEntity::EmitSound(
      &filter,
      iEntIndex: v6,
      soundname: "Default.ClipEmpty_Pistol",
      pOrigin: nullptr,
      soundtime: 0.0,
      duration: nullptr);
  }
  else
  {
    v7 = v4->entindex(this: v4);
    C_BaseEntity::EmitSound(
      &filter,
      iEntIndex: v7,
      soundname: "Default.ClipEmpty_Rifle",
      pOrigin: nullptr,
      soundtime: 0.0,
      duration: nullptr);
  }
  C_RecipientFilter::~C_RecipientFilter(this: &filter);
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x1022AEC0
// Name: public: void C_WeaponCSBase::CallSecondaryAttack(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_WeaponCSBase::CallSecondaryAttack(C_WeaponCSBase *this)
{
  C_BaseCombatCharacter *Owner; // eax
  C_BaseCombatCharacter *v3; // edi
  int v4; // eax

  Owner = C_BaseCombatWeapon::GetOwner(this);
  v3 = (C_BaseCombatCharacter *)__RTDynamicCast(
                                  inptr: Owner,
                                  VfDelta: 0,
                                  SrcType: &C_BaseCombatCharacter `RTTI Type Descriptor',
                                  TargetType: &C_CSPlayer `RTTI Type Descriptor',
                                  isReference: 0);
  if ( v3 != nullptr )
  {
    if ( this->m_iClip2.m_Value != -1 )
    {
      v4 = this->GetSecondaryAmmoType(this);
      if ( C_BaseCombatCharacter::GetAmmoCount(this: v3, iAmmoIndex: v4) == 0 )
        this->m_bFireOnEmpty = true;
    }
    this->SecondaryAttack(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1022AF20
// Name: private: void C_WeaponCSBase::UpdateGunSmoke(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_WeaponCSBase::UpdateGunSmoke(C_WeaponCSBase *this)
{
  float v2; // xmm0_4
  float v3; // xmm0_4
  const FileWeaponInfo_t *WpnData; // eax
  bool v5; // zf
  const char *v6; // eax
  int v7; // ebx
  int v8; // edi
  unsigned int m_smokeAttachments; // eax
  C_BaseCombatCharacter *Owner; // eax
  C_BasePlayer *v11; // eax
  C_BaseViewModel *ViewModel; // eax
  const char *pszHeatEffect; // [esp+0h] [ebp-4h]

  v2 = this->m_gunHeat - (float)(*(float *)(gpGlobals.m_Index + 16) * 0.5);
  this->m_gunHeat = v2;
  if ( v2 <= 0.0 )
    this->m_gunHeat = 0.0;
  if ( this->m_smokeAttachments != 0 )
  {
    v3 = *(float *)(gpGlobals.m_Index + 16) + this->m_timeSinceLastShot;
    this->m_timeSinceLastShot = v3;
    if ( v3 > 0.5 )
    {
      WpnData = C_BaseCombatWeapon::GetWpnData(this);
      v5 = &WpnData[1].aShootSounds[0][32] == nullptr;
      v6 = &WpnData[1].aShootSounds[0][32];
      pszHeatEffect = v6;
      if ( !v5 && (int)_V_strlen(str: v6) > 0 )
      {
        v7 = 0;
        v8 = 1;
        do
        {
          m_smokeAttachments = this->m_smokeAttachments;
          if ( m_smokeAttachments == 0 )
            break;
          if ( (m_smokeAttachments & v8) != 0 )
          {
            this->m_smokeAttachments = m_smokeAttachments & ~v8;
            Owner = C_BaseCombatWeapon::GetOwner(this);
            v11 = (C_BasePlayer *)__RTDynamicCast(
                                    inptr: Owner,
                                    VfDelta: 0,
                                    SrcType: &C_BaseCombatCharacter `RTTI Type Descriptor',
                                    TargetType: &C_CSPlayer `RTTI Type Descriptor',
                                    isReference: 0);
            ViewModel = C_BasePlayer::GetViewModel(this: v11, index: 0);
            DispatchParticleEffect(
              pszParticleName: pszHeatEffect,
              iAttachType: PATTACH_POINT_FOLLOW,
              pEntity: ViewModel,
              iAttachmentPoint: v7,
              bResetAllParticlesOnEntity: false,
              nSplitScreenPlayerSlot: -1,
              filter: nullptr,
              bAllowDormantSpawn: false);
          }
          ++v7;
          v8 = __ROL4__(v8, 1);
        }
        while ( v7 < 16 );
      }
      this->m_smokeAttachments = 0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1022B040
// Name: public: virtual float C_WeaponCSBase::GetMaxSpeed(void)const
// Source: json
//------------------------------------------------------------------------------
double __thiscall C_WeaponCSBase::GetMaxSpeed(C_WeaponCSBase *this)
{
  return *(float *)&C_BaseCombatWeapon::GetWpnData(this)[1].__vftable;
}

//------------------------------------------------------------------------------
// Address: 0x1022B050
// Name: public: virtual bool C_WeaponCSBase::CanDeploy(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall C_WeaponCSBase::CanDeploy(C_WeaponCSBase *this)
{
  C_BaseCombatCharacter *Owner; // eax

  Owner = C_BaseCombatWeapon::GetOwner(this);
  return __RTDynamicCast(
           inptr: Owner,
           VfDelta: 0,
           SrcType: &C_BaseCombatCharacter `RTTI Type Descriptor',
           TargetType: &C_CSPlayer `RTTI Type Descriptor',
           isReference: 0) != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1022B080
// Name: public: int C_WeaponCSBase::GetReticleWeaponSpread(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall C_WeaponCSBase::GetReticleWeaponSpread(C_WeaponCSBase *this)
{
  C_BasePlayer *LocalPlayer; // eax
  float v4; // [esp+8h] [ebp-8h]
  float fSpreadDistance; // [esp+Ch] [ebp-4h]
  float fSpreadDistancea; // [esp+Ch] [ebp-4h]

  LocalPlayer = C_BasePlayer::GetLocalPlayer(nSlot: -1);
  if ( LocalPlayer == nullptr )
    return 0;
  v4 = tan(((double (__thiscall *)(C_BasePlayer *))LocalPlayer->GetFOV)(a1: LocalPlayer) * 0.017453292 * 0.5);
  fSpreadDistance = this->GetSpread(this);
  fSpreadDistancea = (((double (__thiscall *)(C_WeaponCSBase *))this->GetInaccuracy)(a1: this) + fSpreadDistance)
                   * 320.0
                   / v4;
  return (int)(float)((double)ScreenHeight() * 0.002083333333333333 * fSpreadDistancea);
}

//------------------------------------------------------------------------------
// Address: 0x1022B120
// Name: public: int C_WeaponCSBase::GetReticleCrosshairGap(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall C_WeaponCSBase::GetReticleCrosshairGap(C_WeaponCSBase *this)
{
  C_BasePlayer *LocalPlayer; // eax
  C_BaseEntity *v2; // esi
  int m_fFlags; // eax
  int v4; // esi
  float v5; // xmm0_4

  LocalPlayer = C_BasePlayer::GetLocalPlayer(nSlot: -1);
  v2 = LocalPlayer;
  if ( LocalPlayer == nullptr )
    return 0;
  m_fFlags = LocalPlayer->m_fFlags;
  if ( (m_fFlags & 1) != 0 )
  {
    if ( (m_fFlags & 2) != 0 )
    {
      v4 = 3;
    }
    else
    {
      C_BaseEntity::CalcAbsoluteVelocity(this: v2);
      v5 = fsqrt(
             (float)((float)(v2->m_vecAbsVelocity.x * v2->m_vecAbsVelocity.x)
                   + (float)(v2->m_vecAbsVelocity.y * v2->m_vecAbsVelocity.y))
           + (float)(v2->m_vecAbsVelocity.z * v2->m_vecAbsVelocity.z));
      v4 = 20;
      if ( v5 <= 100.0 )
        v4 = 10;
    }
  }
  else
  {
    v4 = 30;
  }
  return v4 * ScreenHeight() / 768;
}

//------------------------------------------------------------------------------
// Address: 0x1022B200
// Name: public: virtual bool C_WeaponCSBase::ShouldPredict(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall C_WeaponCSBase::ShouldPredict(C_WeaponCSBase *this)
{
  C_BaseCombatCharacter *Owner; // eax

  Owner = C_BaseCombatWeapon::GetOwner(this);
  return C_BasePlayer::IsLocalPlayer(pEntity: Owner);
}

//------------------------------------------------------------------------------
// Address: 0x1022B220
// Name: public: virtual bool C_WeaponCSBase::OnFireEvent(class C_BaseViewModel __near *,class Vector const __near &,class QAngle const __near &,int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall C_WeaponCSBase::OnFireEvent(
        C_WeaponCSBase *this,
        C_BaseViewModel *pViewModel,
        const Vector *origin,
        const QAngle *angles,
        int event,
        const char *options)
{
  C_BaseCombatCharacter *Owner; // edi
  int v9; // ebx
  const char *v10; // eax
  float v11; // xmm0_4
  C_BaseCombatCharacter *v13; // edi
  C_BaseViewModel *v14; // edi
  int v15; // eax
  int v16; // esi
  CPVSFilter filter; // [esp+40h] [ebp-30h] BYREF
  Vector org; // [esp+60h] [ebp-10h] BYREF
  float v19; // [esp+6Ch] [ebp-4h]
  const char *pszEffect; // [esp+78h] [ebp+8h]
  const char *eventa; // [esp+84h] [ebp+14h]
  float optionsa; // [esp+88h] [ebp+18h]

  if ( event == 5001 )
  {
    Owner = C_BaseCombatWeapon::GetOwner(this);
    if ( Owner == nullptr
      || !Owner->IsPlayer(this: Owner)
      || (optionsa = ((double (__thiscall *)(C_BaseCombatCharacter *))Owner->C_BaseFlex::C_BaseAnimatingOverlay::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable[1].GetObserverCamOrigin)(a1: Owner),
          (double)((int (__thiscall *)(C_BaseCombatCharacter *))Owner->C_BaseFlex::C_BaseAnimatingOverlay::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable[1].TestCollision)(a1: Owner) <= optionsa)
      || !this->HideViewModelWhenZoomed(this) )
    {
      v9 = this->GetMuzzleAttachmentIndex_1stPerson(this, a2: pViewModel);
      v10 = this->GetMuzzleFlashEffectName_1stPerson(this);
      pszEffect = v10;
      if ( v10 != nullptr && (int)_V_strlen(str: v10) > 0 && v9 >= 0 )
      {
        pViewModel->GetAttachment(this: pViewModel, a2: v9, a3: &org);
        DispatchParticleEffect(
          pszParticleName: pszEffect,
          iAttachType: PATTACH_POINT_FOLLOW,
          pEntity: pViewModel,
          iAttachmentPoint: v9,
          bResetAllParticlesOnEntity: false,
          nSplitScreenPlayerSlot: -1,
          filter: nullptr,
          bAllowDormantSpawn: false);
        C_RecipientFilter::C_RecipientFilter(this: &filter);
        filter.__vftable = (CPVSFilter_vtbl *)&CPVSFilter::`vftable';
        C_RecipientFilter::AddRecipientsByPVS(this: &filter, origin: &org);
        TE_DynamicLight(
          &filter,
          delay: 0.0,
          &org,
          r: 0xFFu,
          g: 0xC0u,
          b: 0x40u,
          exponent: 5,
          radius: 70.0,
          time: 0.050000001,
          decay: 768.0,
          nLightIndex: 0x10000000);
        v11 = *(float *)&C_BaseCombatWeapon::GetWpnData(this)[1].aShootSounds[0][28] + this->m_gunHeat;
        this->m_gunHeat = v11;
        if ( v11 > 1.0 )
        {
          this->m_gunHeat = 1.0;
          this->m_timeSinceLastShot = 0.0;
          this->m_smokeAttachments |= 1 << v9;
        }
        C_RecipientFilter::~C_RecipientFilter(this: &filter);
      }
    }
    return 1;
  }
  if ( event != 62 )
    return 0;
  v13 = C_BaseCombatWeapon::GetOwner(this);
  if ( v13 != nullptr && v13->IsPlayer(this: v13) )
  {
    v19 = ((double (__thiscall *)(C_BaseCombatCharacter *))v13->C_BaseFlex::C_BaseAnimatingOverlay::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable[1].GetObserverCamOrigin)(a1: v13);
    if ( (double)((int (__thiscall *)(C_BaseCombatCharacter *))v13->C_BaseFlex::C_BaseAnimatingOverlay::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable[1].TestCollision)(a1: v13) > v19
      && this->HideViewModelWhenZoomed(this) )
    {
      return 1;
    }
  }
  eventa = this->GetEjectBrassEffectName(this);
  if ( options != nullptr && (int)_V_strlen(str: options) > 0 )
  {
    v14 = pViewModel;
    v15 = pViewModel->LookupAttachment(this: &pViewModel->IClientRenderable, a2: options);
  }
  else
  {
    v14 = pViewModel;
    v15 = this->GetEjectBrassAttachmentIndex_1stPerson(this, a2: pViewModel);
  }
  v16 = v15;
  if ( eventa != nullptr && (int)_V_strlen(str: eventa) > 0 && v16 >= 0 )
    v14->EjectParticleBrass(this: v14, a2: eventa, a3: v16);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1022B4C0
// Name: public: struct BobState_t __near * C_WeaponCSBase::GetBobState(void)
// Source: json
//------------------------------------------------------------------------------
BobState_t *__thiscall C_WeaponCSBase::GetBobState(C_WeaponCSBase *this)
{
  C_BasePlayer *Owner; // esi
  C_BaseViewModel *ViewModel; // eax
  char *v5; // eax

  Owner = (C_BasePlayer *)C_BaseCombatWeapon::GetOwner(this);
  if ( Owner != nullptr
    && Owner->IsPlayer(this: Owner)
    && (ViewModel = C_BasePlayer::GetViewModel(this: Owner, index: this->m_nViewModelIndex.m_Value)) != nullptr
    && (v5 = (char *)__RTDynamicCast(
                       inptr: ViewModel,
                       VfDelta: 0,
                       SrcType: &C_BaseViewModel `RTTI Type Descriptor',
                       TargetType: &C_PredictedViewModel `RTTI Type Descriptor',
                       isReference: 0)) != nullptr )
  {
    return (BobState_t *)(v5 + 3420);
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1022B520
// Name: public: virtual void C_WeaponCSBase::DrawCrosshair(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall C_WeaponCSBase::DrawCrosshair(C_WeaponCSBase *this@<ecx>, int a2@<ebp>)
{
  CHud *Hud; // eax
  CHudCrosshair *Element; // eax
  C_BasePlayer *LocalPlayer; // eax
  int m_nValue; // eax
  int v6; // edi
  int v7; // esi
  int v8; // eax
  CHudIcons *v9; // eax
  CHudTexture *Icon; // eax
  double v11; // st7
  int v12; // esi
  double (__thiscall *v13)(int); // eax
  float v14; // xmm0_4
  int v15; // eax
  int v16; // xmm1_4
  float *v17; // esi
  __m128 v18; // xmm0
  double v19; // xmm0_8
  float v20; // xmm2_4
  int m_fValue_low; // xmm0_4
  int v22; // xmm0_4
  int v23; // edi
  int v24; // eax
  bool v25; // si
  int v26; // eax
  float v27; // xmm0_4
  int v28; // eax
  int v29; // edi
  int v30; // [esp-Ch] [ebp-40h]
  int v31; // [esp-Ch] [ebp-40h]
  int v32; // [esp-8h] [ebp-3Ch]
  int v33; // [esp-8h] [ebp-3Ch]
  int v34; // [esp-4h] [ebp-38h]
  int v35; // [esp-4h] [ebp-38h]
  float m_fValue; // [esp-4h] [ebp-38h]
  float v37; // [esp-4h] [ebp-38h]
  float v38; // [esp-4h] [ebp-38h]
  float v39; // [esp-4h] [ebp-38h]
  int v40; // [esp-4h] [ebp-38h]
  bool iOuterRight; // [esp+0h] [ebp-34h]
  int iOuterRighta; // [esp+0h] [ebp-34h]
  int iOuterRightb; // [esp+0h] [ebp-34h]
  int iInnerTop; // [esp+4h] [ebp-30h] BYREF
  int iInnerBottom; // [esp+8h] [ebp-2Ch]
  int iInnerLeft; // [esp+Ch] [ebp-28h]
  int iInnerRight; // [esp+10h] [ebp-24h]
  int fSpreadDistance; // [esp+14h] [ebp-20h]
  C_BaseEntity *v49; // [esp+18h] [ebp-1Ch]
  int v50; // [esp+1Ch] [ebp-18h]
  int iOuterBottom; // [esp+20h] [ebp-14h]
  int v52; // [esp+24h] [ebp-10h] BYREF
  int iOuterLeft; // [esp+28h] [ebp-Ch]
  void *v54; // [esp+2Ch] [ebp-8h]
  void *retaddr; // [esp+34h] [ebp+0h]

  iOuterLeft = a2;
  v54 = retaddr;
  iOuterBottom = (int)this;
  if ( crosshair.m_pParent == nullptr )
    return;
  if ( crosshair.m_pParent->m_Value.m_nValue == 0 )
    return;
  Hud = GetHud(nSlot: -1);
  Element = (CHudCrosshair *)CHud::FindElement(this: Hud, pName: "CHudCrosshair");
  if ( Element == nullptr )
    return;
  *(float *)&v52 = NAN;
  CHudCrosshair::SetCrosshair(this: Element, texture: nullptr, clr: (const Color *)&v52);
  LocalPlayer = C_BasePlayer::GetLocalPlayer(nSlot: -1);
  fSpreadDistance = (int)LocalPlayer;
  if ( LocalPlayer == nullptr || C_BasePlayer::IsInVGuiInputMode(this: LocalPlayer) )
    return;
  if ( cl_crosshaircolor.m_pParent != nullptr )
    m_nValue = cl_crosshaircolor.m_pParent->m_Value.m_nValue;
  else
    m_nValue = 0;
  switch ( m_nValue )
  {
    case 1:
      v6 = 50;
      v52 = 250;
      v7 = 50;
      break;
    case 2:
      v6 = 50;
      v52 = 50;
      v7 = 250;
      break;
    case 3:
      v6 = 250;
      v52 = 250;
      v7 = 50;
      break;
    case 4:
      v6 = 250;
      v52 = 50;
      v7 = 250;
      break;
    case 5:
      if ( cl_crosshaircolor_r.m_pParent != nullptr )
        v52 = cl_crosshaircolor_r.m_pParent->m_Value.m_nValue;
      else
        *(float *)&v52 = 0.0;
      if ( cl_crosshaircolor_g.m_pParent != nullptr )
        v6 = cl_crosshaircolor_g.m_pParent->m_Value.m_nValue;
      else
        v6 = 0;
      if ( cl_crosshaircolor_b.m_pParent != nullptr )
        v7 = cl_crosshaircolor_b.m_pParent->m_Value.m_nValue;
      else
        v7 = 0;
      break;
    default:
      v7 = 50;
      v6 = 250;
      v52 = 50;
      break;
  }
  if ( *(_BYTE *)(fSpreadDistance + 6836) != 0 )
  {
    v6 = 50;
    v52 = 250;
    v7 = 50;
  }
  if ( cl_crosshairalpha.m_pParent == nullptr )
  {
    v8 = 0;
    goto LABEL_31;
  }
  v8 = cl_crosshairalpha.m_pParent->m_Value.m_nValue;
  if ( v8 >= 0 )
  {
    v50 = 255;
    if ( v8 > 255 )
      goto LABEL_32;
LABEL_31:
    v50 = v8;
    goto LABEL_32;
  }
  v50 = 0;
LABEL_32:
  g_pVGuiSurface->DrawSetColor_2(this: g_pVGuiSurface, a2: v52, a3: v6, a4: v7, a5: v50);
  if ( *(_DWORD *)(iOuterBottom + 3432) == 0 )
  {
    v9 = HudIcons();
    Icon = CHudIcons::GetIcon(this: v9, szIcon: "whiteAdditive");
    if ( Icon != nullptr )
      *(_DWORD *)(iOuterBottom + 3432) = Icon->textureId;
  }
  if ( cl_crosshairusealpha.m_pParent != nullptr && cl_crosshairusealpha.m_pParent->m_Value.m_nValue != 0
    || *(_BYTE *)(fSpreadDistance + 6836) != 0 )
  {
    iOuterRight = false;
  }
  else
  {
    iOuterRight = true;
    g_pVGuiSurface->DrawSetColor_2(this: g_pVGuiSurface, a2: v52, a3: v6, a4: v7, a5: 200);
    g_pVGuiSurface->DrawSetTexture(this: g_pVGuiSurface, a2: *(_DWORD *)(iOuterBottom + 3432));
  }
  if ( *(_DWORD *)&C_BaseCombatWeapon::GetWpnData(this: (C_BaseCombatWeapon *)iOuterBottom)[1].bParsedScript != 5
    || weapon_debug_spread_show.m_pParent != nullptr && weapon_debug_spread_show.m_pParent->m_Value.m_nValue != 0 )
  {
    v11 = ((double (__thiscall *)(int))*(_DWORD *)(*(_DWORD *)fSpreadDistance + 1148))(a1: fSpreadDistance);
    v12 = iOuterBottom;
    v13 = *(double (__thiscall **)(int))(*(_DWORD *)iOuterBottom + 1572);
    *(float *)&iInnerBottom = tan(v11 * 0.017453292 * 0.5);
    *(float *)&iInnerTop = v13(a1: iOuterBottom);
    *(float *)&iInnerBottom = (((double (__thiscall *)(int))*(_DWORD *)(*(_DWORD *)v12 + 1568))(a1: v12)
                             + *(float *)&iInnerTop)
                            * 320.0
                            / *(float *)&iInnerBottom;
    *(float *)&iInnerTop = (double)ScreenHeight() * 0.002083333333333333 * *(float *)&iInnerBottom;
    v49 = (C_BaseEntity *)(int)*(float *)&iInnerTop;
    iInnerTop = *(int *)&C_BaseCombatWeapon::GetWpnData(this: (C_BaseCombatWeapon *)iOuterBottom)[1].szClassName[22];
    v14 = (float)*(int *)&C_BaseCombatWeapon::GetWpnData(this: (C_BaseCombatWeapon *)iOuterBottom)[1].szClassName[18];
    *(float *)&v52 = v14;
    if ( cl_dynamiccrosshair.m_pParent == nullptr || cl_dynamiccrosshair.m_pParent->m_Value.m_nValue == 0 )
    {
LABEL_55:
      v16 = *(int *)(iOuterBottom + 3416);
      *(_DWORD *)(iOuterBottom + 3420) = *(_DWORD *)(fSpreadDistance + 6832);
      v17 = (float *)(v12 + 3416);
      iInnerTop = v16;
      if ( *(float *)&v16 > v14 )
      {
        v18 = (__m128)*(unsigned int *)(gpGlobals.m_Index + 16);
        v18.m128_f32[0] = v18.m128_f32[0] * -2.227767;
        __libm_sse2_exp(a1: _mm_cvtps_pd(v18));
        v20 = v19;
        *v17 = (float)(v20 * (float)(*(float *)&iInnerTop - *(float *)&v52)) + *(float *)&v52;
      }
      *(float *)&iInnerTop = 25.0;
      *v17 = clamp<float,float,float>(val: v17, minVal: (const float *)&v52, maxVal: (const float *)&iInnerTop);
      *(float *)&iInnerBottom = (float)((float)ScreenHeight() * *v17) * 0.00083333335;
      iInnerTop = (int)*(float *)&iInnerBottom;
      m_fValue_low = SLODWORD(cl_crosshairsize.m_pParent->m_Value.m_fValue);
      fSpreadDistance = iInnerTop;
      iInnerTop = m_fValue_low;
      *(float *)&v22 = (float)ScreenHeight() * 0.002083333333333333 * *(float *)&m_fValue_low;
      iInnerTop = v22;
      iOuterBottom = (int)*(float *)&v22;
      iInnerTop = SLODWORD(cl_crosshairthickness.m_pParent->m_Value.m_fValue);
      *(float *)&iInnerBottom = (float)ScreenHeight() * 0.002083333333333333 * *(float *)&iInnerTop;
      iInnerTop = (int)*(float *)&iInnerBottom;
      if ( iInnerTop >= 1 )
      {
        iInnerTop = SLODWORD(cl_crosshairthickness.m_pParent->m_Value.m_fValue);
        *(float *)&iInnerBottom = (float)ScreenHeight() * 0.002083333333333333 * *(float *)&iInnerTop;
        iInnerTop = (int)*(float *)&iInnerBottom;
        v52 = iInnerTop;
      }
      else
      {
        v52 = 1;
      }
      if ( weapon_debug_spread_show.m_pParent != nullptr && weapon_debug_spread_show.m_pParent->m_Value.m_nValue == 2 )
        fSpreadDistance = (int)v49;
      v23 = ScreenWidth() / 2;
      v24 = ScreenHeight();
      iInnerLeft = v23 - v52 / 2;
      v34 = v52 + iInnerLeft - fSpreadDistance + 2 * fSpreadDistance;
      iInnerBottom = v24 / 2;
      v25 = iOuterRight;
      iInnerRight = v24 / 2 - v52 / 2;
      iInnerTop = iInnerRight + v52;
      DrawCrosshairRect(
        x0: iInnerLeft - fSpreadDistance - iOuterBottom,
        y0: iInnerRight,
        x1: iInnerLeft - fSpreadDistance,
        y1: iInnerRight + v52,
        bAdditive: iOuterRight);
      DrawCrosshairRect(x0: v34, y0: iInnerRight, x1: v34 + iOuterBottom, y1: iInnerTop, bAdditive: iOuterRight);
      v35 = v52 + iInnerRight - fSpreadDistance + 2 * fSpreadDistance;
      iOuterRighta = iInnerLeft + v52;
      DrawCrosshairRect(
        x0: iInnerLeft,
        y0: iInnerRight - fSpreadDistance - iOuterBottom,
        x1: iInnerLeft + v52,
        y1: iInnerRight - fSpreadDistance,
        bAdditive: v25);
      DrawCrosshairRect(x0: iInnerLeft, y0: v35, x1: iOuterRighta, y1: v35 + iOuterBottom, bAdditive: v25);
      if ( cl_crosshairdot.m_pParent != nullptr && cl_crosshairdot.m_pParent->m_Value.m_nValue != 0 )
        DrawCrosshairRect(x0: iInnerLeft, y0: iInnerRight, x1: iInnerLeft + v52, y1: iInnerRight + v52, bAdditive: v25);
      if ( weapon_debug_spread_show.m_pParent != nullptr && weapon_debug_spread_show.m_pParent->m_Value.m_nValue == 1 )
      {
        g_pVGuiSurface->DrawSetColor_2(this: g_pVGuiSurface, a2: 250, a3: 250, a4: 50, a5: v50);
        m_fValue = cl_crosshairthickness.m_pParent->m_Value.m_fValue;
        v37 = (float)ScreenHeight() * 0.002083333333333333 * m_fValue;
        v26 = 1;
        if ( (int)v37 >= 1 )
        {
          v38 = cl_crosshairthickness.m_pParent->m_Value.m_fValue;
          v39 = (float)ScreenHeight() * 0.002083333333333333 * v38;
          v26 = (int)v39;
        }
        iInnerLeft = v26;
        iInnerTop = (int)v49 + v23;
        iOuterRightb = v23 - (_DWORD)v49;
        v50 = v23 - (_DWORD)v49 - v26;
        v30 = (int)v49 + v23 + v26;
        iInnerRight = (int)v49 + iInnerBottom;
        v52 = iInnerBottom - (_DWORD)v49 - v26;
        v27 = (float)(int)v49 * weapon_debug_spread_gap.m_pParent->m_Value.m_fValue;
        v32 = iInnerBottom - (_DWORD)v49;
        fSpreadDistance = (int)v49 + iInnerBottom + v26;
        iOuterBottom = (int)v27;
        v40 = v23 - iOuterBottom;
        DrawCrosshairRect(x0: v50, y0: v52, x1: v23 - iOuterBottom, y1: iInnerBottom - (_DWORD)v49, bAdditive: v25);
        v28 = v23 + iOuterBottom;
        v29 = v30;
        iInnerLeft = v28;
        DrawCrosshairRect(x0: v28, y0: v52, x1: v30, y1: v32, bAdditive: v25);
        DrawCrosshairRect(x0: v50, y0: iInnerRight, x1: v40, y1: fSpreadDistance, bAdditive: v25);
        DrawCrosshairRect(x0: iInnerLeft, y0: iInnerRight, x1: v30, y1: fSpreadDistance, bAdditive: v25);
        v31 = iInnerBottom - iOuterBottom;
        DrawCrosshairRect(x0: v50, y0: v52, x1: iOuterRightb, y1: iInnerBottom - iOuterBottom, bAdditive: v25);
        v33 = iInnerBottom + iOuterBottom;
        DrawCrosshairRect(
          x0: v50,
          y0: iInnerBottom + iOuterBottom,
          x1: iOuterRightb,
          y1: fSpreadDistance,
          bAdditive: v25);
        DrawCrosshairRect(x0: iInnerTop, y0: v52, x1: v29, y1: v31, bAdditive: v25);
        DrawCrosshairRect(x0: iInnerTop, y0: v33, x1: v29, y1: fSpreadDistance, bAdditive: v25);
      }
      return;
    }
    v15 = *(_DWORD *)(fSpreadDistance + 248);
    if ( (v15 & 1) != 0 )
    {
      if ( (v15 & 2) != 0 )
      {
        v14 = v14 * 0.5;
      }
      else
      {
        C_BaseEntity::CalcAbsoluteVelocity(this: (C_BaseEntity *)fSpreadDistance);
        v14 = *(float *)&v52;
        if ( fsqrt(
               (float)((float)(*(float *)(fSpreadDistance + 144) * *(float *)(fSpreadDistance + 144))
                     + (float)(*(float *)(fSpreadDistance + 148) * *(float *)(fSpreadDistance + 148)))
             + (float)(*(float *)(fSpreadDistance + 152) * *(float *)(fSpreadDistance + 152))) <= 100.0 )
        {
LABEL_52:
          if ( *(_DWORD *)(fSpreadDistance + 6832) > *(_DWORD *)(iOuterBottom + 3420)
            && (*(_DWORD *)(fSpreadDistance + 5304) & 0x801) != 0 )
          {
            v14 = v14 + (float)iInnerTop;
            *(float *)&v52 = v14;
          }
          goto LABEL_55;
        }
        v14 = *(float *)&v52 * 1.5;
      }
    }
    else
    {
      v14 = v14 * 2.0;
    }
    *(float *)&v52 = v14;
    goto LABEL_52;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1022BD40
// Name: public: bool C_WeaponCSBase::IsUseable(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall C_WeaponCSBase::IsUseable(C_WeaponCSBase *this)
{
  C_BaseCombatCharacter *Owner; // eax
  C_BaseCombatCharacter *v3; // edi
  bool result; // al
  int v5; // eax

  Owner = C_BaseCombatWeapon::GetOwner(this);
  v3 = (C_BaseCombatCharacter *)__RTDynamicCast(
                                  inptr: Owner,
                                  VfDelta: 0,
                                  SrcType: &C_BaseCombatCharacter `RTTI Type Descriptor',
                                  TargetType: &C_CSPlayer `RTTI Type Descriptor',
                                  isReference: 0);
  result = false;
  if ( v3 != nullptr )
  {
    if ( this->m_iClip1.m_Value > 0 )
      return true;
    v5 = this->GetPrimaryAmmoType(this);
    if ( C_BaseCombatCharacter::GetAmmoCount(this: v3, iAmmoIndex: v5) > 0 || this->GetMaxClip1(this) == -1 )
      return true;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1022BDB0
// Name: float CalcViewModelBobHelper(class C_BasePlayer __near *,struct BobState_t __near *)
// Source: json
//------------------------------------------------------------------------------
double __usercall CalcViewModelBobHelper@<st0>(long double a1@<esi:edi>, C_BasePlayer *player, BobState_t *pBobState)
{
  float v3; // xmm2_4
  float v4; // xmm0_4
  float v5; // xmm2_4
  float m_flLastSpeed; // xmm1_4
  float v7; // xmm0_4
  float val; // xmm1_4
  C_CSPlayer *v9; // eax
  C_BasePlayer *v10; // edi
  C_BaseCombatWeapon *ActiveCSWeapon; // eax
  float v12; // xmm0_4
  float m_fValue; // xmm1_4
  float v14; // xmm0_4
  float v15; // xmm0_4
  float v16; // xmm0_4
  int v17; // xmm1_4
  float v18; // xmm0_4
  float v19; // xmm1_4
  float v20; // xmm1_4
  float v21; // xmm0_4
  int v22; // xmm1_4
  long double v25; // [esp+14h] [ebp-4Ch]
  float v26; // [esp+24h] [ebp-3Ch]
  float v27; // [esp+34h] [ebp-2Ch]
  float v28; // [esp+38h] [ebp-28h]
  float v29; // [esp+3Ch] [ebp-24h]
  float v30; // [esp+40h] [ebp-20h]
  float m_flOldFallVelocity; // [esp+44h] [ebp-1Ch]
  float *v32; // [esp+44h] [ebp-1Ch]
  float flDipAddAmta; // [esp+48h] [ebp-18h]
  float flDipAddAmt; // [esp+48h] [ebp-18h]
  float flRunAddAmt; // [esp+4Ch] [ebp-14h]
  float cycle; // [esp+50h] [ebp-10h]

  if ( cl_use_new_headbob.m_pParent != nullptr
    && cl_use_new_headbob.m_pParent->m_Value.m_nValue != 0
    && pBobState != nullptr
    && *(float *)(gpGlobals.m_Index + 16) != 0.0
    && player != nullptr )
  {
    v26 = fsqrt(
            (float)(player->m_vecVelocity.x * player->m_vecVelocity.x)
          + (float)(player->m_vecVelocity.y * player->m_vecVelocity.y));
    player->GetViewOffset(this: player);
    v29 = 0.0;
    v30 = 0.0;
    m_flOldFallVelocity = player->m_Local.m_flOldFallVelocity;
    if ( player->m_Local.m_bInLanding )
    {
      v3 = *(float *)(gpGlobals.m_Index + 12) - player->m_Local.m_flLandingTime;
      if ( v3 <= 0.0 )
        v3 = 0.0;
      flDipAddAmta = (float)((float)((float)(v3 * 4.0) * (float)(v3 * 4.0)) * 3.0)
                   - (float)((float)((float)((float)(v3 * 4.0) * (float)(v3 * 4.0)) * 2.0) * (float)(v3 * 4.0));
      player->GetViewOffset(this: player);
      v4 = (float)((float)(63.0 - (float)((float)(1.0 / m_flOldFallVelocity) * 10.0)) * flDipAddAmta)
         + (float)((float)(1.0 - flDipAddAmta) * 64.0);
      if ( v4 > 64.0 )
        v4 = 64.0;
      v29 = 64.0 - v4;
    }
    if ( (float)((float)(*(float *)(gpGlobals.m_Index + 12) - pBobState->m_flLastBobTime) * 620.0) >= 0.0 )
      v5 = (float)(*(float *)(gpGlobals.m_Index + 12) - pBobState->m_flLastBobTime) * 620.0;
    else
      v5 = 0.0;
    m_flLastSpeed = pBobState->m_flLastSpeed;
    v7 = m_flLastSpeed - v5;
    val = m_flLastSpeed + v5;
    if ( v7 <= v26 )
    {
      if ( v26 <= val )
        val = v26;
    }
    else
    {
      val = v7;
    }
    if ( val >= -320.0 )
    {
      if ( val > 320.0 )
        val = 320.0;
    }
    else
    {
      val = -320.0;
    }
    cycle = val;
    pBobState->m_flLastSpeed = val;
    v9 = ToBasePlayer(pEntity: player);
    v10 = v9;
    if ( v9 != nullptr && !v9->IsZoomed(this: v9) )
      v30 = cl_bob_lower_amt.m_pParent->m_Value.m_fValue * (float)(val * 0.001);
    v32 = (float *)(gpGlobals.m_Index + 12);
    flRunAddAmt = 0.5;
    pBobState->m_flBobTime = RemapVal(val, A: 0.0, B: 320.0, C: 0.0, D: 1.0) * (*v32 - pBobState->m_flLastBobTime)
                           + pBobState->m_flBobTime;
    pBobState->m_flLastBobTime = *v32;
    if ( v10 != nullptr && C_CSPlayer::GetActiveCSWeapon(this: v10) != nullptr )
    {
      ActiveCSWeapon = C_CSPlayer::GetActiveCSWeapon(this: v10);
      flRunAddAmt = (1000.0
                   - ((double (__thiscall *)(C_BaseCombatWeapon *))ActiveCSWeapon->C_BaseAnimating::C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable[1].SetRefEHandle)(a1: ActiveCSWeapon))
                  * 0.2857142857142857
                  * 0.001
                  * cl_bobcycle.m_pParent->m_Value.m_fValue;
    }
    v12 = (float)(pBobState->m_flBobTime
                - (float)((float)(int)(float)((float)(1.0 / flRunAddAmt) * pBobState->m_flBobTime) * flRunAddAmt))
        * (float)(1.0 / flRunAddAmt);
    m_fValue = cl_bobup.m_pParent->m_Value.m_fValue;
    if ( m_fValue <= v12 )
      v14 = (float)(v12 - cl_bobup.m_pParent->m_Value.m_fValue)
          * 3.141592653589793
          / (float)(1.0 - cl_bobup.m_pParent->m_Value.m_fValue)
          + 3.141592653589793;
    else
      v14 = v12 * 3.141592653589793 / m_fValue;
    flDipAddAmt = 0.0062500001;
    if ( C_BaseEntity::GetGroundEntity(this: player) == nullptr )
      flDipAddAmt = 0.00125;
    v28 = (float)(cl_bobamt_vert.m_pParent->m_Value.m_fValue * flDipAddAmt) * cycle;
    __libm_sse2_sin(x: a1);
    v15 = v14 * (v28 * 0.7) + v28 * 0.3;
    pBobState->m_flVerticalBob = v15;
    v16 = v15 - (float)(v30 + v29);
    *(float *)&v17 = -8.0;
    if ( v16 < -8.0 || (*(float *)&v17 = 4.0, v16 > 4.0) )
      v16 = *(float *)&v17;
    pBobState->m_flVerticalBob = v16;
    v18 = (float)(pBobState->m_flBobTime
                - (float)((float)((float)(int)(float)((float)((float)(1.0 / flRunAddAmt) * pBobState->m_flBobTime) * 2.0)
                                * flRunAddAmt)
                        * 2.0))
        / (float)(flRunAddAmt * 2.0);
    v19 = cl_bobup.m_pParent->m_Value.m_fValue;
    if ( v19 <= v18 )
      v20 = (float)(v18 - cl_bobup.m_pParent->m_Value.m_fValue)
          * 3.141592653589793
          / (float)(1.0 - cl_bobup.m_pParent->m_Value.m_fValue)
          + 3.141592653589793;
    else
      v20 = v18 * 3.141592653589793 / v19;
    v27 = (float)(cl_bobamt_lat.m_pParent->m_Value.m_fValue * flDipAddAmt) * cycle;
    __libm_sse2_sin(x: v25);
    v21 = v20 * (v27 * 0.7) + v27 * 0.3;
    *(float *)&v22 = -7.0;
    pBobState->m_flLateralBob = v21;
    if ( v21 < -7.0 || (*(float *)&v22 = 4.0, v21 > 4.0) )
      v21 = *(float *)&v22;
    pBobState->m_flLateralBob = v21;
  }
  return 0.0;
}

//------------------------------------------------------------------------------
// Address: 0x1022C2F0
// Name: void AddViewModelBobHelper(class Vector __near &,class QAngle __near &,struct BobState_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl AddViewModelBobHelper(Vector *origin, QAngle *angles, BobState_t *pBobState)
{
  float v3; // xmm0_4
  float v4; // xmm2_4
  float v5; // xmm0_4
  Vector right; // [esp+0h] [ebp-18h] BYREF
  Vector forward; // [esp+Ch] [ebp-Ch] BYREF

  if ( cl_use_new_headbob.m_pParent != nullptr
    && cl_use_new_headbob.m_pParent->m_Value.m_nValue != 0
    && pBobState != nullptr )
  {
    AngleVectors(angles, &forward, &right, up: nullptr);
    v3 = pBobState->m_flVerticalBob * 0.40000001;
    origin->x = (float)(forward.x * v3) + origin->x;
    v4 = (float)(v3 * forward.y) + origin->y;
    origin->z = (float)(v3 * forward.z) + origin->z;
    origin->y = v4;
    origin->z = (float)(pBobState->m_flVerticalBob * 0.1) + origin->z;
    angles->z = (float)(pBobState->m_flVerticalBob * 0.5) + angles->z;
    angles->x = angles->x - (float)(pBobState->m_flVerticalBob * 0.40000001);
    angles->y = angles->y - (float)(pBobState->m_flLateralBob * 0.30000001);
    v5 = pBobState->m_flLateralBob * 0.2;
    origin->x = (float)(right.x * v5) + origin->x;
    origin->y = (float)(right.y * v5) + origin->y;
    origin->z = (float)(right.z * v5) + origin->z;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1022C420
// Name: public: virtual float C_WeaponCSBase::CalcViewmodelBob(void)
// Source: json
//------------------------------------------------------------------------------
double __usercall C_WeaponCSBase::CalcViewmodelBob@<st0>(C_WeaponCSBase *this@<ecx>, float a2@<ebp>)
{
  long double v2; // rdi
  BobState_t *BobState; // eax
  C_BaseCombatCharacter *Owner; // esi
  float v6; // xmm1_4
  ConVar *m_pParent; // edi
  double v8; // st7
  double v9; // st6
  ConVar *v10; // esi
  float v11; // xmm1_4
  __m128 v12; // xmm0
  __m128d v13; // xmm0
  __m128 v14; // xmm1
  __m128d v15; // xmm2
  double v16; // xmm0_8
  __m128 v17; // xmm1
  float v18; // xmm0_4
  __m128d v19; // xmm1
  __m128 v20; // xmm0
  __m128d v21; // xmm3
  double v22; // xmm0_8
  float m_fValue; // [esp+34h] [ebp-1Ch] BYREF
  float v24; // [esp+38h] [ebp-18h] BYREF
  float v25; // [esp+3Ch] [ebp-14h] BYREF
  float val[3]; // [esp+40h] [ebp-10h] BYREF
  float retaddr; // [esp+50h] [ebp+0h]

  val[1] = a2;
  val[2] = retaddr;
  LODWORD(v2) = this;
  if ( cl_use_new_headbob.m_pParent != nullptr && cl_use_new_headbob.m_pParent->m_Value.m_nValue != 0 )
  {
    HIDWORD(v2) = C_BaseCombatWeapon::GetOwner(this);
    if ( HIDWORD(v2) == 0
      || (*(unsigned __int8 (__thiscall **)(_DWORD))(*(_DWORD *)HIDWORD(v2) + 584))(a1: HIDWORD(v2)) == 0 )
    {
      HIDWORD(v2) = 0;
    }
    BobState = C_WeaponCSBase::GetBobState(this: (C_WeaponCSBase *)LODWORD(v2));
    if ( BobState != nullptr )
      return CalcViewModelBobHelper(a1: v2, player: (C_BasePlayer *)HIDWORD(v2), pBobState: BobState);
  }
  else
  {
    Owner = C_BaseCombatWeapon::GetOwner(this);
    if ( Owner == nullptr || !Owner->IsPlayer(this: Owner) )
      Owner = nullptr;
    v6 = 0.0;
    if ( *(float *)(gpGlobals.m_Index + 16) != 0.0 && Owner != nullptr && cl_bobcycle.m_pParent->m_Value.m_fValue > 0.0 )
    {
      m_pParent = cl_bobup.m_pParent;
      m_fValue = cl_bobup.m_pParent->m_Value.m_fValue;
      if ( m_fValue > 0.0 && m_fValue < 1.0 )
      {
        val[0] = fsqrt(
                   (float)(Owner->m_vecVelocity.x * Owner->m_vecVelocity.x)
                 + (float)(Owner->m_vecVelocity.y * Owner->m_vecVelocity.y));
        if ( (float)((float)(*(float *)(gpGlobals.m_Index + 12) - lastbobtime) * 320.0) >= 0.0 )
          v6 = (float)(*(float *)(gpGlobals.m_Index + 12) - lastbobtime) * 320.0;
        v25 = lastspeed + v6;
        v24 = lastspeed - v6;
        val[0] = clamp<float,float,float>(val, minVal: &v24, maxVal: &v25);
        LODWORD(v24) = 320;
        v25 = NAN;
        val[0] = clamp<float,int,int>(val, minVal: (const int *)&v25, maxVal: (const int *)&v24);
        lastspeed = val[0];
        v25 = *(float *)(gpGlobals.m_Index + 12);
        v8 = RemapVal(val: val[0], A: 0.0, B: 320.0, C: 0.0, D: 1.0);
        v9 = v25 - lastbobtime;
        v10 = cl_bobcycle.m_pParent;
        lastbobtime = v25;
        v11 = 1.0 / cl_bobcycle.m_pParent->m_Value.m_fValue;
        bobtime = v8 * v9 + bobtime;
        v12 = (__m128)LODWORD(bobtime);
        v12.m128_f32[0] = (float)(bobtime
                                - (float)((float)(int)(float)(v11 * bobtime) * cl_bobcycle.m_pParent->m_Value.m_fValue))
                        * v11;
        if ( m_fValue <= v12.m128_f32[0] )
        {
          v12.m128_f32[0] = v12.m128_f32[0] - m_pParent->m_Value.m_fValue;
          v15 = _mm_cvtps_pd(v12);
          v15.m128d_f64[0] = v15.m128d_f64[0] * 3.141592653589793 / (float)(1.0 - m_pParent->m_Value.m_fValue)
                           + 3.141592653589793;
          v14 = _mm_cvtpd_ps(v15);
        }
        else
        {
          v13 = _mm_cvtps_pd(v12);
          v13.m128d_f64[0] = v13.m128d_f64[0] * 3.141592653589793 / m_fValue;
          v14 = _mm_cvtpd_ps(v13);
        }
        v25 = val[0] * 0.0049999999;
        g_verticalBob = val[0] * 0.0049999999;
        __libm_sse2_sin(X: (__m128i)_mm_cvtps_pd(v14));
        *(float *)&v16 = v16;
        *(float *)&v16 = *(float *)&v16 * (g_verticalBob * 0.7) + g_verticalBob * 0.3;
        g_verticalBob = *(float *)&v16;
        m_fValue = 4.0;
        v24 = -7.0;
        g_verticalBob = clamp<float,float,float>(val: &g_verticalBob, minVal: &v24, maxVal: &m_fValue);
        v17 = (__m128)LODWORD(bobtime);
        v17.m128_f32[0] = (float)(bobtime
                                - (float)((float)((float)(int)(float)((float)(bobtime / v10->m_Value.m_fValue) * 2.0)
                                                * v10->m_Value.m_fValue)
                                        * 2.0))
                        / (float)(v10->m_Value.m_fValue * 2.0);
        v18 = m_pParent->m_Value.m_fValue;
        if ( v18 <= v17.m128_f32[0] )
        {
          v17.m128_f32[0] = v17.m128_f32[0] - m_pParent->m_Value.m_fValue;
          v21 = _mm_cvtps_pd(v17);
          v21.m128d_f64[0] = v21.m128d_f64[0] * 3.141592653589793 / (float)(1.0 - m_pParent->m_Value.m_fValue)
                           + 3.141592653589793;
          v20 = _mm_cvtpd_ps(v21);
        }
        else
        {
          v19 = _mm_cvtps_pd(v17);
          v19.m128d_f64[0] = v19.m128d_f64[0] * 3.141592653589793 / v18;
          v20 = _mm_cvtpd_ps(v19);
        }
        g_lateralBob = v25;
        __libm_sse2_sin(X: (__m128i)_mm_cvtps_pd(v20));
        *(float *)&v22 = v22;
        *(float *)&v22 = *(float *)&v22 * (g_lateralBob * 0.7) + g_lateralBob * 0.3;
        g_lateralBob = *(float *)&v22;
        m_fValue = 4.0;
        v24 = -7.0;
        g_lateralBob = clamp<float,float,float>(val: &g_lateralBob, minVal: &v24, maxVal: &m_fValue);
      }
    }
  }
  return 0.0;
}

//------------------------------------------------------------------------------
// Address: 0x1022C870
// Name: public: virtual void C_WeaponCSBase::AddViewmodelBob(class C_BaseViewModel __near *,class Vector __near &,class QAngle __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_WeaponCSBase::AddViewmodelBob(
        C_WeaponCSBase *this,
        C_BaseViewModel *viewmodel,
        Vector *origin,
        QAngle *angles)
{
  BobState_t *BobState; // esi
  float v6; // xmm0_4
  float v7; // xmm2_4
  Vector right; // [esp+8h] [ebp-18h] BYREF
  Vector forward; // [esp+14h] [ebp-Ch] BYREF

  if ( cl_use_new_headbob.m_pParent != nullptr && cl_use_new_headbob.m_pParent->m_Value.m_nValue != 0 )
  {
    BobState = C_WeaponCSBase::GetBobState(this);
    if ( BobState != nullptr )
    {
      this->CalcViewmodelBob(this);
      AddViewModelBobHelper(origin, angles, pBobState: BobState);
    }
  }
  else
  {
    AngleVectors(angles, &forward, &right, up: nullptr);
    this->CalcViewmodelBob(this);
    v6 = g_verticalBob * 0.40000001;
    origin->x = (float)(forward.x * (float)(g_verticalBob * 0.40000001)) + origin->x;
    v7 = (float)(v6 * forward.y) + origin->y;
    origin->z = (float)(v6 * forward.z) + origin->z;
    origin->y = v7;
    origin->z = (float)(g_verticalBob * 0.1) + origin->z;
    angles->z = (float)(g_verticalBob * 0.5) + angles->z;
    angles->x = angles->x - (float)(g_verticalBob * 0.40000001);
    angles->y = angles->y - (float)(g_lateralBob * 0.30000001);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1022C9A0
// Name: public: C_WeaponCSBase::C_WeaponCSBase(void)
// Source: json
//------------------------------------------------------------------------------
C_WeaponCSBase *__thiscall C_WeaponCSBase::C_WeaponCSBase(C_WeaponCSBase *this)
{
  C_BaseCombatWeapon::C_BaseCombatWeapon(this);
  this->C_BaseCombatWeapon::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable = (C_WeaponCSBase_vtbl *)&C_WeaponCSBase::`vftable'{for `IClientUnknown'};
  this->C_BaseCombatWeapon::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientRenderable::__vftable = (IClientRenderable_vtbl *)&C_WeaponCSBase::`vftable'{for `IClientRenderable'};
  this->C_BaseCombatWeapon::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientNetworkable::__vftable = (IClientNetworkable_vtbl *)&C_WeaponCSBase::`vftable'{for `IClientNetworkable'};
  this->C_BaseCombatWeapon::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientThinkable::__vftable = (IClientThinkable_vtbl *)&C_WeaponCSBase::`vftable'{for `IClientThinkable'};
  this->C_BaseCombatWeapon::C_BaseAnimating::C_BaseEntity::IClientModelRenderable::__vftable = (IClientModelRenderable_vtbl *)&C_WeaponCSBase::`vftable';
  this->m_PriorOwners.m_Memory.m_pMemory = nullptr;
  this->m_PriorOwners.m_Memory.m_nAllocationCount = 0;
  this->m_PriorOwners.m_Memory.m_nGrowSize = 0;
  this->m_PriorOwners.m_Size = 0;
  this->m_PriorOwners.m_pElements = nullptr;
  this->m_donor.m_Index = -1;
  C_BaseEntity::SetPredictionEligible(this, canpredict: true);
  this->m_nextPrevOwnerTouchTime = 0.0;
  this->m_prevOwner = nullptr;
  CCollisionProperty::SetSolidFlags(this: &this->m_Collision, flags: this->m_Collision.m_usSolidFlags.m_Value | 8);
  this->m_iCrosshairTextureID = 0;
  if ( this->m_fAccuracyPenalty.m_Value != 0.0 )
    this->m_fAccuracyPenalty.m_Value = 0.0;
  if ( this->m_weaponMode.m_Value != Primary_Mode )
    this->m_weaponMode.m_Value = Primary_Mode;
  if ( !this->m_bWaitForNoAttack.m_Value )
    this->m_bWaitForNoAttack.m_Value = true;
  this->m_smokeAttachments = 0;
  this->m_gunHeat = 0.0;
  this->m_timeSinceLastShot = 0.0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1022CA80
// Name: public: virtual void C_WeaponCSBase::ItemPostFrame(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_WeaponCSBase::ItemPostFrame(C_WeaponCSBase *this)
{
  C_BaseCombatCharacter *Owner; // eax
  C_CSPlayer *v3; // edi
  int v4; // ebx
  int AmmoCount; // eax
  int m_Value; // ecx
  int m_nButtons; // eax
  int v8; // eax

  Owner = C_BaseCombatWeapon::GetOwner(this);
  v3 = (C_CSPlayer *)__RTDynamicCast(
                       inptr: Owner,
                       VfDelta: 0,
                       SrcType: &C_BaseCombatCharacter `RTTI Type Descriptor',
                       TargetType: &C_CSPlayer `RTTI Type Descriptor',
                       isReference: 0);
  if ( v3 != nullptr )
  {
    this->UpdateAccuracyPenalty(this);
    C_WeaponCSBase::UpdateGunSmoke(this);
    this->UpdateShieldState(this);
    if ( this->m_bInReload.m_Value && *(float *)(gpGlobals.m_Index + 12) >= v3->m_flNextAttack )
    {
      v4 = this->GetMaxClip1(this) - this->m_iClip1.m_Value;
      if ( v4 >= C_BaseCombatCharacter::GetAmmoCount(this: v3, iAmmoIndex: this->m_iPrimaryAmmoType.m_Value) )
        AmmoCount = C_BaseCombatCharacter::GetAmmoCount(this: v3, iAmmoIndex: this->m_iPrimaryAmmoType.m_Value);
      else
        AmmoCount = this->GetMaxClip1(this) - this->m_iClip1.m_Value;
      m_Value = this->m_iClip1.m_Value;
      if ( m_Value != m_Value + AmmoCount )
        this->m_iClip1.m_Value = m_Value + AmmoCount;
      C_BaseCombatCharacter::RemoveAmmo(this: v3, iCount: AmmoCount, iAmmoIndex: this->m_iPrimaryAmmoType.m_Value);
      if ( this->m_bInReload.m_Value )
        this->m_bInReload.m_Value = false;
    }
    if ( (v3->m_nButtons & 1) == 0
      && v3->m_iShotsFired.m_Value > 0
      && (!this->IsFullAuto(this) || this->m_iClip1.m_Value == 0)
      && v3->m_iShotsFired.m_Value != 0 )
    {
      v3->m_iShotsFired.m_Value = 0;
    }
    m_nButtons = v3->m_nButtons;
    if ( (m_nButtons & 1) != 0 && *(float *)(gpGlobals.m_Index + 12) >= this->m_flNextPrimaryAttack.m_Value )
    {
      if ( this->m_iClip1.m_Value == 0
        || this->GetMaxClip1(this) == -1
        && (v8 = this->GetPrimaryAmmoType(this), C_BaseCombatCharacter::GetAmmoCount(this: v3, iAmmoIndex: v8) == 0) )
      {
        this->m_bFireOnEmpty = true;
      }
      if ( !C_CSGameRules::IsFreezePeriod(this: (CBaseAchievement *)g_pGameRules)
        && !v3->m_bIsDefusing.m_Value
        && C_CSPlayer::State_Get(this: v3) == STATE_ACTIVE
        && (v3->m_iShotsFired.m_Value <= 0 || this->IsFullAuto(this) && this->m_iClip1.m_Value != 0)
        && !this->m_bWaitForNoAttack.m_Value )
      {
        this->PrimaryAttack(this);
      }
    }
    else
    {
      if ( (m_nButtons & 0x800) != 0 && *(float *)(gpGlobals.m_Index + 12) >= this->m_flNextSecondaryAttack.m_Value )
      {
        this->IsZoomOrKnife(this);
        C_WeaponCSBase::CallSecondaryAttack(this);
        v3->m_nButtons &= ~0x800u;
        return;
      }
      if ( (m_nButtons & 0x80000) == 0 || *(float *)(gpGlobals.m_Index + 12) < this->m_flNextSecondaryAttack.m_Value )
      {
        if ( (m_nButtons & 0x2000) == 0
          || this->GetMaxClip1(this) == -1
          || this->m_bInReload.m_Value
          || *(float *)(gpGlobals.m_Index + 12) <= this->m_flNextPrimaryAttack.m_Value )
        {
          if ( (v3->m_nButtons & 0x80801) != 0 )
            return;
          this->m_bFireOnEmpty = false;
          if ( this->m_bWaitForNoAttack.m_Value )
            this->m_bWaitForNoAttack.m_Value = false;
          if ( v3->m_iShotsFired.m_Value != 0 )
            v3->m_iShotsFired.m_Value = 0;
          if ( *(float *)(gpGlobals.m_Index + 12) <= this->m_flNextPrimaryAttack.m_Value
            || this->m_iClip1.m_Value != 0
            || !C_WeaponCSBase::IsUseable(this)
            || (this->GetWeaponFlags(this) & 2) != 0
            || this->m_bInReload.m_Value )
          {
            this->WeaponIdle(this);
            return;
          }
        }
        this->Reload(this);
        return;
      }
      if ( this->IsZoomOrKnife(this) )
        C_WeaponCSBase::CallSecondaryAttack(this);
      v3->m_nButtons &= ~0x80000u;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1022CDB0
// Name: public: virtual bool C_WeaponCSBase::DefaultDeploy(char __near *,char __near *,int,char __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall C_WeaponCSBase::DefaultDeploy(
        C_WeaponCSBase *this,
        char *szViewModel,
        char *szWeaponModel,
        int iActivity,
        char *szAnimExt)
{
  C_BaseCombatCharacter *Owner; // eax
  C_BasePlayer *v7; // ebx
  C_WeaponCSBase_vtbl *v9; // edi
  Activity v10; // eax
  int m_nSequence; // edi
  CStudioHdr *m_pStudioHdr; // eax
  unsigned int m_Index; // ecx
  float v14; // xmm0_4
  float v15; // xmm0_4

  Owner = C_BaseCombatWeapon::GetOwner(this);
  v7 = (C_BasePlayer *)__RTDynamicCast(
                         inptr: Owner,
                         VfDelta: 0,
                         SrcType: &C_BaseCombatCharacter `RTTI Type Descriptor',
                         TargetType: &C_CSPlayer `RTTI Type Descriptor',
                         isReference: 0);
  if ( v7 == nullptr )
    return 0;
  C_BasePlayer::SetAnimationExtension(this: v7, pExtension: szAnimExt);
  this->SetViewModel(this);
  v9 = this->C_BaseCombatWeapon::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable;
  v10 = this->GetDeployActivity(this);
  v9->SendWeaponAnim(this, a2: v10);
  m_nSequence = this->m_nSequence;
  if ( this->m_pStudioHdr == nullptr && this->GetModel(this: &this->IClientRenderable) != nullptr )
    C_BaseAnimating::LockStudioHdr(this);
  m_pStudioHdr = this->m_pStudioHdr;
  if ( m_pStudioHdr == nullptr || m_pStudioHdr->m_pStudioHdr == nullptr )
    m_pStudioHdr = nullptr;
  v7->m_flNextAttack = C_BaseAnimating::SequenceDuration(this, pStudioHdr: m_pStudioHdr, iSequence: m_nSequence)
                     + *(float *)(gpGlobals.m_Index + 12);
  m_Index = gpGlobals.m_Index;
  v14 = *(float *)(gpGlobals.m_Index + 12);
  if ( this->m_flNextPrimaryAttack.m_Value != v14 )
    this->m_flNextPrimaryAttack.m_Value = v14;
  v15 = *(float *)(m_Index + 12);
  if ( this->m_flNextSecondaryAttack.m_Value != v15 )
    this->m_flNextSecondaryAttack.m_Value = v15;
  this->SetWeaponVisible(this, a2: true);
  this->SetWeaponModelIndex(this, a2: szWeaponModel);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1022CED0
// Name: public: virtual void C_WeaponCSBase::SetWeaponModelIndex(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_WeaponCSBase::SetWeaponModelIndex(C_WeaponCSBase *this, const char *pName)
{
  int v3; // eax

  v3 = modelinfo->GetModelIndex(this: modelinfo, a2: pName);
  if ( this->m_iWorldModelIndex.m_Value != v3 )
    this->m_iWorldModelIndex.m_Value = v3;
}

//------------------------------------------------------------------------------
// Address: 0x1022CF00
// Name: protected: float C_WeaponCSBase::CalculateNextAttackTime(float)
// Source: json
//------------------------------------------------------------------------------
double __thiscall C_WeaponCSBase::CalculateNextAttackTime(C_WeaponCSBase *this, float fCycleTime)
{
  float m_Value; // xmm0_4
  float v3; // xmm1_4
  float v4; // xmm0_4
  float v5; // xmm0_4
  double result; // st7
  float fCurAttack; // [esp+0h] [ebp-4h]

  m_Value = this->m_flNextPrimaryAttack.m_Value;
  v3 = *(float *)(gpGlobals.m_Index + 12) - m_Value;
  fCurAttack = m_Value;
  if ( v3 < 0.0 || v3 > *(float *)(gpGlobals.m_Index + 28) )
  {
    m_Value = *(float *)(gpGlobals.m_Index + 12);
    fCurAttack = m_Value;
  }
  v4 = m_Value + fCycleTime;
  if ( this->m_flNextPrimaryAttack.m_Value != v4 )
    this->m_flNextPrimaryAttack.m_Value = v4;
  v5 = this->m_flNextPrimaryAttack.m_Value;
  result = fCurAttack;
  if ( this->m_flNextSecondaryAttack.m_Value != v5 )
    this->m_flNextSecondaryAttack.m_Value = v5;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1022CF80
// Name: public: virtual bool C_WeaponCSBase::Deploy(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall C_WeaponCSBase::Deploy(C_WeaponCSBase *this)
{
  this->m_iAlpha = 80;
  if ( this->m_fAccuracyPenalty.m_Value != 0.0 )
    this->m_fAccuracyPenalty.m_Value = 0.0;
  *(_QWORD *)&this->m_gunHeat = 0;
  this->m_timeSinceLastShot = 0.0;
  return C_BaseCombatWeapon::Deploy(this);
}

//------------------------------------------------------------------------------
// Address: 0x1022CFD0
// Name: public: virtual bool C_WeaponCSBase::DefaultPistolReload(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall C_WeaponCSBase::DefaultPistolReload(C_WeaponCSBase *this)
{
  C_BaseCombatCharacter *Owner; // eax
  C_BaseCombatCharacter *v3; // edi
  int v5; // eax
  const FileWeaponInfo_t *WpnData; // eax

  Owner = C_BaseCombatWeapon::GetOwner(this);
  v3 = (C_BaseCombatCharacter *)__RTDynamicCast(
                                  inptr: Owner,
                                  VfDelta: 0,
                                  SrcType: &C_BaseCombatCharacter `RTTI Type Descriptor',
                                  TargetType: &C_CSPlayer `RTTI Type Descriptor',
                                  isReference: 0);
  if ( v3 == nullptr )
    return 0;
  v5 = this->GetPrimaryAmmoType(this);
  if ( C_BaseCombatCharacter::GetAmmoCount(this: v3, iAmmoIndex: v5) > 0 )
  {
    WpnData = C_BaseCombatWeapon::GetWpnData(this);
    if ( C_BaseCombatWeapon::DefaultReload(this, iClipSize1: WpnData->iDefaultClip1, iClipSize2: 0, iActivity: 192) == 0 )
      return 0;
    if ( v3[1].m_pIntermediateData_FirstPredicted[112] != nullptr )
      v3[1].m_pIntermediateData_FirstPredicted[112] = nullptr;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1022D050
// Name: public: virtual void C_WeaponCSBase::UpdateAccuracyPenalty(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_WeaponCSBase::UpdateAccuracyPenalty(C_WeaponCSBase *this)
{
  C_BaseCombatCharacter *Owner; // eax
  C_BaseEntity *v3; // esi
  float *WpnData; // edi
  CSWeaponMode m_Value; // ecx
  float v6; // xmm1_4
  float v7; // xmm0_4
  float v8; // xmm1_4
  float v9; // xmm2_4
  float v10; // xmm2_4
  float v11; // xmm1_4
  int v12; // xmm0_4
  float v13; // xmm2_4
  unsigned __int8 m_MoveType; // al
  float v15; // xmm0_4
  float v16; // xmm0_4
  int m_fFlags; // eax
  double v18; // xmm0_8
  float v19; // xmm0_4
  double v20; // xmm0_8
  __m128 v21; // xmm1
  double v22; // xmm0_8
  float v23; // xmm0_4
  float v24; // [esp-20h] [ebp-2Ch]
  float v25; // [esp-10h] [ebp-1Ch]
  float v27; // [esp-8h] [ebp-14h]

  Owner = C_BaseCombatWeapon::GetOwner(this);
  v3 = (C_BaseEntity *)__RTDynamicCast(
                         inptr: Owner,
                         VfDelta: 0,
                         SrcType: &C_BaseCombatCharacter `RTTI Type Descriptor',
                         TargetType: &C_CSPlayer `RTTI Type Descriptor',
                         isReference: 0);
  if ( v3 != nullptr )
  {
    WpnData = (float *)C_BaseCombatWeapon::GetWpnData(this);
    C_BaseEntity::CalcAbsoluteVelocity(this: v3);
    m_Value = this->m_weaponMode.m_Value;
    v6 = WpnData[466];
    v24 = fsqrt(
            (float)(v3->m_vecAbsVelocity.x * v3->m_vecAbsVelocity.x)
          + (float)(v3->m_vecAbsVelocity.y * v3->m_vecAbsVelocity.y));
    v7 = v6 * 0.34;
    v8 = v6 * 0.94999999;
    if ( v7 == v8 )
    {
      v9 = 0.0;
      if ( (float)(v24 - v8) >= 0.0 )
        v9 = WpnData[m_Value + 586];
    }
    else
    {
      v10 = v24 - v7;
      v11 = v8 - v7;
      v12 = 0;
      v13 = v10 / v11;
      if ( v13 < 0.0 || (v12 = 1065353216, v13 > 1.0) )
        v13 = *(float *)&v12;
      v9 = v13 * WpnData[m_Value + 586];
    }
    m_MoveType = v3->m_MoveType;
    if ( m_MoveType == 9 )
    {
      v15 = WpnData[m_Value + 582] + WpnData[m_Value + 576];
      m_MoveType = v3->m_MoveType;
    }
    else if ( (v3->m_fFlags & 2) != 0 )
    {
      v15 = WpnData[m_Value + 574];
    }
    else
    {
      v15 = WpnData[m_Value + 576];
    }
    v16 = v15 + v9;
    v27 = v16;
    if ( this->m_bInReload.m_Value )
    {
      v16 = v16 + WpnData[590];
      v27 = v16;
    }
    v25 = this->m_fAccuracyPenalty.m_Value;
    if ( v16 <= v25 )
    {
      if ( m_MoveType != 9 && ((m_fFlags = v3->m_fFlags) & 1) != 0 && (m_fFlags & 2) != 0 )
      {
        __libm_sse2_log(a1: (__m128d)0x4024000000000000uLL);
        *(float *)&v18 = v18;
        v19 = *(float *)&v18 / WpnData[589];
      }
      else
      {
        __libm_sse2_log(a1: (__m128d)0x4024000000000000uLL);
        *(float *)&v20 = v20;
        v19 = *(float *)&v20 / WpnData[588];
      }
      v21 = (__m128)*(unsigned int *)(gpGlobals.m_Index + 28);
      v21.m128_f32[0] = v21.m128_f32[0] * v19;
      __libm_sse2_exp(a1: _mm_cvtps_pd(_mm_xor_ps(v21, (__m128)_mask__NegFloat_)));
      *(float *)&v22 = v22;
      v23 = (float)(*(float *)&v22 * (float)(v25 - v27)) + v27;
      if ( this->m_fAccuracyPenalty.m_Value != v23 )
        this->m_fAccuracyPenalty.m_Value = v23;
    }
    else
    {
      this->m_fAccuracyPenalty.m_Value = v16;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1022D280
// Name: public: virtual void C_WeaponCSBase::OnJump(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_WeaponCSBase::OnJump(C_WeaponCSBase *this, float fImpulse)
{
  const FileWeaponInfo_t *WpnData; // eax
  float m_Value; // xmm1_4
  float v5; // xmm0_4

  WpnData = C_BaseCombatWeapon::GetWpnData(this);
  m_Value = this->m_fAccuracyPenalty.m_Value;
  v5 = (float)(*(float *)&WpnData[1].szAIAddOn[4 * this->m_weaponMode.m_Value] * fImpulse) + m_Value;
  if ( m_Value != v5 )
    this->m_fAccuracyPenalty.m_Value = v5;
}

//------------------------------------------------------------------------------
// Address: 0x1022D2D0
// Name: public: virtual void C_WeaponCSBase::OnLand(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_WeaponCSBase::OnLand(C_WeaponCSBase *this, float fVelocity)
{
  const FileWeaponInfo_t *WpnData; // eax
  float v4; // xmm0_4
  C_BaseCombatCharacter *Owner; // eax
  C_BasePlayer *v6; // eax
  C_BasePlayer *v7; // esi
  QAngle angle; // [esp+10h] [ebp-Ch] BYREF
  float fPenalty; // [esp+24h] [ebp+8h]
  float fPenaltya; // [esp+24h] [ebp+8h]

  WpnData = C_BaseCombatWeapon::GetWpnData(this);
  v4 = this->m_fAccuracyPenalty.m_Value
     + (float)(*(float *)&WpnData[1].szAIAddOn[4 * this->m_weaponMode.m_Value + 8] * fVelocity);
  fPenalty = *(float *)&WpnData[1].szAIAddOn[4 * this->m_weaponMode.m_Value + 8] * fVelocity;
  if ( this->m_fAccuracyPenalty.m_Value != v4 )
    this->m_fAccuracyPenalty.m_Value = v4;
  Owner = C_BaseCombatWeapon::GetOwner(this);
  v6 = (C_BasePlayer *)__RTDynamicCast(
                         inptr: Owner,
                         VfDelta: 0,
                         SrcType: &C_BaseCombatCharacter `RTTI Type Descriptor',
                         TargetType: &C_CSPlayer `RTTI Type Descriptor',
                         isReference: 0);
  v7 = v6;
  if ( v6 != nullptr )
  {
    angle = *v6->GetPunchAngle(this: v6);
    __libm_sse2_asin();
    fPenaltya = (float)(fPenalty * 57.29578) * 0.2;
    angle.x = angle.x + fPenaltya;
    angle.y = SharedRandomFloat(sharedname: "LandPunchAngleYaw", flMinVal: -1.0, flMaxVal: 1.0, additionalSeed: 0)
            * fPenaltya
            * 0.1
            + angle.y;
    C_BasePlayer::SetPunchAngle(this: v7, &angle);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1022D430
// Name: CC_WeaponCSBaseFactory
// Source: json
//------------------------------------------------------------------------------
C_WeaponCSBase *__cdecl CC_WeaponCSBaseFactory()
{
  C_WeaponCSBase *v0; // eax

  v0 = (C_WeaponCSBase *)C_BaseEntity::operator new(stAllocateBlock: 0xDB0u);
  if ( v0 != nullptr )
    return C_WeaponCSBase::C_WeaponCSBase(this: v0);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10428040
// Name: DT_WeaponCSBase::_dynamic_initializer_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
int DT_WeaponCSBase::_dynamic_initializer_for__g_RecvTable__()
{
  RecvTable::RecvTable(this: &DT_WeaponCSBase::g_RecvTable);
  return atexit(func: DT_WeaponCSBase::_dynamic_atexit_destructor_for__g_RecvTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10428060
// Name: DT_WeaponCSBase::_dynamic_initializer_for__g_RecvTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_WeaponCSBase::_dynamic_initializer_for__g_RecvTableInit__()
{
  int result; // eax

  result = ClientClassInit<DT_WeaponCSBase::ignored>();
  DT_WeaponCSBase::g_RecvTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10428070
// Name: C_WeaponCSBase_PredDataDescInit::_dynamic_initializer_for__g_PredMapHolder__
// Source: json
//------------------------------------------------------------------------------
void C_WeaponCSBase_PredDataDescInit::_dynamic_initializer_for__g_PredMapHolder__()
{
  C_WeaponCSBase::m_PredMap.dataNumFields = 5;
  C_WeaponCSBase::m_PredMap.dataDesc = (typedescription_t *)&unk_105B584C;
}

//------------------------------------------------------------------------------
// Address: 0x10435EB0
// Name: DT_WeaponCSBase::_dynamic_atexit_destructor_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_WeaponCSBase::_dynamic_atexit_destructor_for__g_RecvTable__()
{
  C_BaseAnimating::ShutdownBoneSetupThreadPool(this: (vgui::PropertyPage *)&DT_WeaponCSBase::g_RecvTable);
}

//------------------------------------------------------------------------------
// Address: 0x1022D3E0
// Name: _C_WeaponCSBase_CreateObject
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IClientNetworkable *__cdecl C_WeaponCSBase_CreateObject(int entnum, int serialNum)
{
  C_WeaponCSBase *v2; // eax
  C_WeaponCSBase *v3; // eax
  C_WeaponCSBase *v4; // esi

  v2 = (C_WeaponCSBase *)C_BaseEntity::operator new(stAllocateBlock: 0xDB0u);
  if ( v2 == nullptr )
    return nullptr;
  v3 = C_WeaponCSBase::C_WeaponCSBase(this: v2);
  v4 = v3;
  if ( v3 == nullptr )
    return nullptr;
  v3->Init(this: v3, a2: entnum, a3: serialNum);
  return &v4->IClientNetworkable;
}

//------------------------------------------------------------------------------
// Address: 0x10428090
// Name: _dynamic_initializer_for__g_Cweapon_cs_baseFoo__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_Cweapon_cs_baseFoo__()
{
  CClassMap *ClassMap; // eax
  int result; // eax

  ClassMap = GetClassMap();
  result = ((int (__thiscall *)(CClassMap *, const char *, const char *, int, C_WeaponCSBase *(__cdecl *)()))ClassMap->Add)(
             a1: ClassMap,
             a2: "weapon_cs_base",
             a3: "C_WeaponCSBase",
             a4: 3504,
             a5: CC_WeaponCSBaseFactory);
  __g_C_WeaponCSBaseClientClass.m_pMapClassname = "weapon_cs_base";
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104280C0
// Name: _dynamic_initializer_for__cl_crosshaircolor__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_crosshaircolor__()
{
  ConVar::ConVar(
    this: &cl_crosshaircolor,
    pName: "cl_crosshaircolor",
    pDefaultValue: "1",
    flags: 32904,
    pHelpString: "Set crosshair color as defined in game_options.360.txt");
  return atexit(func: dynamic_atexit_destructor_for__cl_crosshaircolor__);
}

//------------------------------------------------------------------------------
// Address: 0x104280F0
// Name: _dynamic_initializer_for__cl_dynamiccrosshair__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_dynamiccrosshair__()
{
  ConVar::ConVar(this: &cl_dynamiccrosshair, pName: "cl_dynamiccrosshair", pDefaultValue: "1", flags: 32904);
  return atexit(func: dynamic_atexit_destructor_for__cl_dynamiccrosshair__);
}

//------------------------------------------------------------------------------
// Address: 0x10428120
// Name: _dynamic_initializer_for__cl_scalecrosshair__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_scalecrosshair__()
{
  ConVar::ConVar(
    this: &cl_scalecrosshair,
    pName: "cl_scalecrosshair",
    pDefaultValue: "1",
    flags: 32904,
    pHelpString: "Enable crosshair scaling (deprecated)");
  return atexit(func: dynamic_atexit_destructor_for__cl_scalecrosshair__);
}

//------------------------------------------------------------------------------
// Address: 0x10428150
// Name: _dynamic_initializer_for__cl_crosshairscale__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_crosshairscale__()
{
  ConVar::ConVar(
    this: &cl_crosshairscale,
    pName: "cl_crosshairscale",
    pDefaultValue: "0",
    flags: 32904,
    pHelpString: "Crosshair scaling factor (deprecated)");
  return atexit(func: dynamic_atexit_destructor_for__cl_crosshairscale__);
}

//------------------------------------------------------------------------------
// Address: 0x10428180
// Name: _dynamic_initializer_for__cl_crosshairalpha__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_crosshairalpha__()
{
  ConVar::ConVar(this: &cl_crosshairalpha, pName: "cl_crosshairalpha", pDefaultValue: "200", flags: 32904);
  return atexit(func: dynamic_atexit_destructor_for__cl_crosshairalpha__);
}

//------------------------------------------------------------------------------
// Address: 0x104281B0
// Name: _dynamic_initializer_for__cl_crosshairusealpha__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_crosshairusealpha__()
{
  ConVar::ConVar(this: &cl_crosshairusealpha, pName: "cl_crosshairusealpha", pDefaultValue: "1", flags: 32904);
  return atexit(func: dynamic_atexit_destructor_for__cl_crosshairusealpha__);
}

//------------------------------------------------------------------------------
// Address: 0x104281E0
// Name: _dynamic_initializer_for__cl_crosshairsize__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_crosshairsize__()
{
  ConVar::ConVar(this: &cl_crosshairsize, pName: "cl_crosshairsize", pDefaultValue: "5", flags: 32904);
  return atexit(func: dynamic_atexit_destructor_for__cl_crosshairsize__);
}

//------------------------------------------------------------------------------
// Address: 0x10428210
// Name: _dynamic_initializer_for__cl_crosshairthickness__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_crosshairthickness__()
{
  ConVar::ConVar(this: &cl_crosshairthickness, pName: "cl_crosshairthickness", pDefaultValue: "0.5", flags: 32904);
  return atexit(func: dynamic_atexit_destructor_for__cl_crosshairthickness__);
}

//------------------------------------------------------------------------------
// Address: 0x10428240
// Name: _dynamic_initializer_for__cl_crosshairdot__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_crosshairdot__()
{
  ConVar::ConVar(this: &cl_crosshairdot, pName: "cl_crosshairdot", pDefaultValue: "0", flags: 32904);
  return atexit(func: dynamic_atexit_destructor_for__cl_crosshairdot__);
}

//------------------------------------------------------------------------------
// Address: 0x10428270
// Name: _dynamic_initializer_for__cl_crosshaircolor_r__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_crosshaircolor_r__()
{
  ConVar::ConVar(this: &cl_crosshaircolor_r, pName: "cl_crosshaircolor_r", pDefaultValue: "50", flags: 32904);
  return atexit(func: dynamic_atexit_destructor_for__cl_crosshaircolor_r__);
}

//------------------------------------------------------------------------------
// Address: 0x104282A0
// Name: _dynamic_initializer_for__cl_crosshaircolor_g__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_crosshaircolor_g__()
{
  ConVar::ConVar(this: &cl_crosshaircolor_g, pName: "cl_crosshaircolor_g", pDefaultValue: "250", flags: 32904);
  return atexit(func: dynamic_atexit_destructor_for__cl_crosshaircolor_g__);
}

//------------------------------------------------------------------------------
// Address: 0x104282D0
// Name: _dynamic_initializer_for__cl_crosshaircolor_b__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_crosshaircolor_b__()
{
  ConVar::ConVar(this: &cl_crosshaircolor_b, pName: "cl_crosshaircolor_b", pDefaultValue: "50", flags: 32904);
  return atexit(func: dynamic_atexit_destructor_for__cl_crosshaircolor_b__);
}

//------------------------------------------------------------------------------
// Address: 0x10435EC0
// Name: _dynamic_atexit_destructor_for__cl_crosshaircolor__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_crosshaircolor__()
{
  ConVar::~ConVar(this: &cl_crosshaircolor);
}

//------------------------------------------------------------------------------
// Address: 0x10435ED0
// Name: _dynamic_atexit_destructor_for__cl_dynamiccrosshair__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_dynamiccrosshair__()
{
  ConVar::~ConVar(this: &cl_dynamiccrosshair);
}

//------------------------------------------------------------------------------
// Address: 0x10435EE0
// Name: _dynamic_atexit_destructor_for__cl_scalecrosshair__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_scalecrosshair__()
{
  ConVar::~ConVar(this: &cl_scalecrosshair);
}

//------------------------------------------------------------------------------
// Address: 0x10435EF0
// Name: _dynamic_atexit_destructor_for__cl_crosshairscale__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_crosshairscale__()
{
  ConVar::~ConVar(this: &cl_crosshairscale);
}

//------------------------------------------------------------------------------
// Address: 0x10435F00
// Name: _dynamic_atexit_destructor_for__cl_crosshairalpha__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_crosshairalpha__()
{
  ConVar::~ConVar(this: &cl_crosshairalpha);
}

//------------------------------------------------------------------------------
// Address: 0x10435F10
// Name: _dynamic_atexit_destructor_for__cl_crosshairusealpha__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_crosshairusealpha__()
{
  ConVar::~ConVar(this: &cl_crosshairusealpha);
}

//------------------------------------------------------------------------------
// Address: 0x10435F20
// Name: _dynamic_atexit_destructor_for__cl_crosshairsize__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_crosshairsize__()
{
  ConVar::~ConVar(this: &cl_crosshairsize);
}

//------------------------------------------------------------------------------
// Address: 0x10435F30
// Name: _dynamic_atexit_destructor_for__cl_crosshairthickness__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_crosshairthickness__()
{
  ConVar::~ConVar(this: &cl_crosshairthickness);
}

//------------------------------------------------------------------------------
// Address: 0x10435F40
// Name: _dynamic_atexit_destructor_for__cl_crosshairdot__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_crosshairdot__()
{
  ConVar::~ConVar(this: &cl_crosshairdot);
}

//------------------------------------------------------------------------------
// Address: 0x10435F50
// Name: _dynamic_atexit_destructor_for__cl_crosshaircolor_r__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_crosshaircolor_r__()
{
  ConVar::~ConVar(this: &cl_crosshaircolor_r);
}

//------------------------------------------------------------------------------
// Address: 0x10435F60
// Name: _dynamic_atexit_destructor_for__cl_crosshaircolor_g__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_crosshaircolor_g__()
{
  ConVar::~ConVar(this: &cl_crosshaircolor_g);
}

//------------------------------------------------------------------------------
// Address: 0x10435F70
// Name: _dynamic_atexit_destructor_for__cl_crosshaircolor_b__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_crosshaircolor_b__()
{
  ConVar::~ConVar(this: &cl_crosshaircolor_b);
}

// ============================================================
// Overlay from server (Missing functions)
// ============================================================
namespace server {

//------------------------------------------------------------------------------
// Address: 0x102E8090
// Name: bool IsAmmoType(int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl IsAmmoType(int iAmmoType, const char *pAmmoName)
{
  CCSAmmoDef *AmmoDef; // eax

  AmmoDef = GetAmmoDef();
  return CAmmoDef::Index(this: AmmoDef, psz: pAmmoName) == iAmmoType;
}

//------------------------------------------------------------------------------
// Address: 0x102E80B0
// Name: char const __near * GetTranslatedWeaponAlias(char const __near *)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl GetTranslatedWeaponAlias(const char *szAlias)
{
  int v1; // esi

  v1 = 0;
  while ( _V_stricmp(s1: s_WeaponAliasTranslationInfo[v1].alias, s2: szAlias) != 0 )
  {
    if ( (unsigned int)++v1 >= 0x18 )
      return (char *)szAlias;
  }
  return s_WeaponAliasTranslationInfo[v1].translatedAlias;
}

//------------------------------------------------------------------------------
// Address: 0x102E80F0
// Name: enum CSWeaponID AliasToWeaponID(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CSWeaponID __cdecl AliasToWeaponID(const char *szAlias)
{
  int v1; // esi

  if ( szAlias == nullptr )
    return WEAPON_NONE;
  v1 = 0;
  while ( _V_stricmp(s1: (&off_105CE31C)[2 * v1], s2: szAlias) != 0 )
  {
    if ( (unsigned int)++v1 >= 0x2E )
      return WEAPON_NONE;
  }
  return s_weaponAliasInfo[v1].id;
}

//------------------------------------------------------------------------------
// Address: 0x102E8130
// Name: char const __near * WeaponIDToAlias(int)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl WeaponIDToAlias(int id)
{
  int v1; // eax

  v1 = 0;
  while ( s_weaponAliasInfo[v1].id != id )
  {
    if ( (unsigned int)++v1 >= 0x2E )
      return nullptr;
  }
  return (&off_105CE31C)[2 * v1];
}

//------------------------------------------------------------------------------
// Address: 0x102E8160
// Name: bool IsPrimaryWeapon(enum CSWeaponID)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl IsPrimaryWeapon(CSWeaponID id)
{
  CCSWeaponInfo *WeaponInfo; // eax

  WeaponInfo = GetWeaponInfo(weaponID: id);
  return WeaponInfo != nullptr && WeaponInfo->iSlot == 0;
}

//------------------------------------------------------------------------------
// Address: 0x102E8190
// Name: bool IsSecondaryWeapon(enum CSWeaponID)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl IsSecondaryWeapon(CSWeaponID id)
{
  CCSWeaponInfo *WeaponInfo; // eax

  WeaponInfo = GetWeaponInfo(weaponID: id);
  return WeaponInfo != nullptr && WeaponInfo->iSlot == 1;
}

//------------------------------------------------------------------------------
// Address: 0x102E81C0
// Name: public: virtual class ServerClass __near * CWeaponCSBase::GetServerClass(void)
// Source: json
//------------------------------------------------------------------------------
ServerClass *__thiscall CWeaponCSBase::GetServerClass(CWeaponCSBase *this)
{
  return &g_CWeaponCSBase_ClassReg;
}

//------------------------------------------------------------------------------
// Address: 0x102E81D0
// Name: public: virtual struct datamap_t __near * CWeaponCSBase::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CWeaponCSBase::GetDataDescMap(CWeaponCSBase *this)
{
  return &CWeaponCSBase::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x102E81F0
// Name: public: class CCSPlayer __near * CWeaponCSBase::GetPlayerOwner(void)const
// Source: json
//------------------------------------------------------------------------------
CCSPlayer *__thiscall CWeaponCSBase::GetPlayerOwner(CWeaponCSBase *this)
{
  CBaseCombatCharacter *Owner; // eax

  Owner = CBaseCombatWeapon::GetOwner(this);
  return (CCSPlayer *)__RTDynamicCast(
                        inptr: Owner,
                        VfDelta: 0,
                        SrcType: &CBaseCombatCharacter `RTTI Type Descriptor',
                        TargetType: &CCSPlayer `RTTI Type Descriptor',
                        isReference: 0);
}

//------------------------------------------------------------------------------
// Address: 0x102E8210
// Name: public: virtual bool CWeaponCSBase::SendWeaponAnim(int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CWeaponCSBase::SendWeaponAnim(CWeaponCSBase *this, Activity iActivity)
{
  return CBaseCombatWeapon::SendWeaponAnim(this, iActivity);
}

//------------------------------------------------------------------------------
// Address: 0x102E8220
// Name: public: virtual void CWeaponCSBase::ItemBusyFrame(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWeaponCSBase::ItemBusyFrame(CWeaponCSBase *this)
{
  this->UpdateAccuracyPenalty(this);
  CAI_BaseNPC::OnSetSchedule((vgui::Panel *)this);
}

//------------------------------------------------------------------------------
// Address: 0x102E8240
// Name: public: class CCSWeaponInfo const __near & CWeaponCSBase::GetCSWpnData(void)const
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
const CCSWeaponInfo *__thiscall CWeaponCSBase::GetCSWpnData(CWeaponCSBase *this)
{
  return (const CCSWeaponInfo *)CBaseCombatWeapon::GetWpnData(this);
}

//------------------------------------------------------------------------------
// Address: 0x102E8250
// Name: public: virtual char const __near * CWeaponCSBase::GetViewModel(int)const
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CWeaponCSBase::GetViewModel(CWeaponCSBase *this, int __formal)
{
  CBaseCombatCharacter *Owner; // eax
  vgui::ToggleButton *v4; // eax

  Owner = CBaseCombatWeapon::GetOwner(this);
  v4 = (vgui::ToggleButton *)__RTDynamicCast(
                               inptr: Owner,
                               VfDelta: 0,
                               SrcType: &CBaseCombatCharacter `RTTI Type Descriptor',
                               TargetType: &CCSPlayer `RTTI Type Descriptor',
                               isReference: 0);
  if ( v4 == nullptr )
    return CBaseCombatWeapon::GetViewModel(this, __formal: 0);
  if ( IAI_BehaviorBridge::BehaviorBridge_IsCurTaskContinuousMove(this: v4)
    && CBaseCombatWeapon::GetWpnData(this)[1].szClassName[26] != 0 )
  {
    return &CBaseCombatWeapon::GetWpnData(this)[1].szClassName[75];
  }
  return CBaseCombatWeapon::GetWpnData(this)->szViewModel;
}

//------------------------------------------------------------------------------
// Address: 0x102E82C0
// Name: public: virtual enum Activity CWeaponCSBase::GetDeployActivity(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CWeaponCSBase::GetDeployActivity(CBaseCombatWeapon *this)
{
  return 181;
}

//------------------------------------------------------------------------------
// Address: 0x102E82D0
// Name: public: virtual void CWeaponCSBase::UpdateShieldState(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWeaponCSBase::UpdateShieldState(CWeaponCSBase *this)
{
  CBaseCombatCharacter *Owner; // eax
  vgui::ToggleButton *v2; // eax
  vgui::TreeView *v3; // esi

  Owner = CBaseCombatWeapon::GetOwner(this);
  v2 = (vgui::ToggleButton *)__RTDynamicCast(
                               inptr: Owner,
                               VfDelta: 0,
                               SrcType: &CBaseCombatCharacter `RTTI Type Descriptor',
                               TargetType: &CCSPlayer `RTTI Type Descriptor',
                               isReference: 0);
  v3 = (vgui::TreeView *)v2;
  if ( v2 != nullptr && !IAI_BehaviorBridge::BehaviorBridge_IsCurTaskContinuousMove(this: v2) )
    CNavMesh::SaveCustomData(this: v3, itemIndex: 0);
}

//------------------------------------------------------------------------------
// Address: 0x102E8310
// Name: public: virtual bool CWeaponCSBase::CanBeSelected(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CWeaponCSBase::CanBeSelected(CWeaponCSBase *this)
{
  return this->VisibleInWeaponSelection(this);
}

//------------------------------------------------------------------------------
// Address: 0x102E8320
// Name: public: virtual bool CWeaponCSBase::Holster(class CBaseCombatWeapon __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CWeaponCSBase::Holster(CWeaponCSBase *this, CBaseCombatWeapon *pSwitchingTo)
{
  CBaseCombatCharacter *Owner; // eax
  CBasePlayer *v4; // eax
  vgui::TreeView *v5; // edi

  Owner = CBaseCombatWeapon::GetOwner(this);
  v4 = (CBasePlayer *)__RTDynamicCast(
                        inptr: Owner,
                        VfDelta: 0,
                        SrcType: &CBaseCombatCharacter `RTTI Type Descriptor',
                        TargetType: &CCSPlayer `RTTI Type Descriptor',
                        isReference: 0);
  v5 = (vgui::TreeView *)v4;
  if ( v4 == nullptr )
    return 0;
  CBasePlayer::SetFOV(this: v4, pRequester: v4, FOV: 0, zoomRate: 0.0, iZoomStart: 0);
  CNavMesh::SaveCustomData(this: v5, itemIndex: 0);
  *(_QWORD *)&this->m_gunHeat = 0;
  this->m_timeSinceLastShot = 0.0;
  return CBaseCombatWeapon::Holster(this, pSwitchingTo);
}

//------------------------------------------------------------------------------
// Address: 0x102E83A0
// Name: public: virtual void CWeaponCSBase::DefaultTouch(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWeaponCSBase::DefaultTouch(CWeaponCSBase *this, CBasePlayer *pOther)
{
  CCSPlayer *m_prevOwner; // eax

  m_prevOwner = this->m_prevOwner;
  if ( m_prevOwner == nullptr || pOther != m_prevOwner || this->m_nextPrevOwnerTouchTime <= gpGlobals->curtime )
    CBaseCombatWeapon::DefaultTouch(this, pOther);
}

//------------------------------------------------------------------------------
// Address: 0x102E83E0
// Name: public: virtual class Vector const __near & CWeaponCSBase::GetBulletSpread(void)
// Source: json
//------------------------------------------------------------------------------
const Vector *__thiscall CWeaponCSBase::GetBulletSpread(CWeaponCSBase *this)
{
  if ( (_S4_73 & 1) == 0 )
  {
    _S4_73 |= 1u;
    cone_0.x = 0.069760002;
    cone_0.y = 0.069760002;
    cone_0.z = 0.069760002;
  }
  return &cone_0;
}

//------------------------------------------------------------------------------
// Address: 0x102E8420
// Name: public: virtual bool CWeaponCSBase::ShouldRemoveOnRoundRestart(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CWeaponCSBase::ShouldRemoveOnRoundRestart(CWeaponCSBase *this)
{
  CBaseCombatCharacter *Owner; // eax

  Owner = CBaseCombatWeapon::GetOwner(this);
  return __RTDynamicCast(
           inptr: Owner,
           VfDelta: 0,
           SrcType: &CBaseCombatCharacter `RTTI Type Descriptor',
           TargetType: &CCSPlayer `RTTI Type Descriptor',
           isReference: 0) == nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x102E8450
// Name: public: virtual bool CWeaponCSBase::KeyValue(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CWeaponCSBase::KeyValue(CWeaponCSBase *this, char *szKeyName, const char *szValue)
{
  int v4; // eax

  if ( CBaseEntity::KeyValue(this, szKeyName, szValue)
    || szKeyName != "ammo" && _V_stricmp(s1: szKeyName, s2: "ammo") != 0 )
  {
    return 0;
  }
  v4 = atoi(nptr: szValue);
  if ( v4 < 0 )
    return 0;
  this->m_iDefaultExtraAmmo = v4;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x102E84B0
// Name: public: bool CWeaponCSBase::IsPistol(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CWeaponCSBase::IsPistol(CWeaponCSBase *this)
{
  return *(_DWORD *)&CBaseCombatWeapon::GetWpnData(this)[1].bParsedScript == 1;
}

//------------------------------------------------------------------------------
// Address: 0x102E84D0
// Name: public: virtual bool CWeaponCSBase::IsFullAuto(void)const
// Source: json
//------------------------------------------------------------------------------
char __thiscall CWeaponCSBase::IsFullAuto(CWeaponCSBase *this)
{
  return CBaseCombatWeapon::GetWpnData(this)[1].szClassName[2];
}

//------------------------------------------------------------------------------
// Address: 0x102E84E0
// Name: public: bool CWeaponCSBase::PlayEmptySound(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CWeaponCSBase::PlayEmptySound(CWeaponCSBase *this)
{
  const Vector *v2; // edi
  Vector *(__thiscall *GetSoundEmissionOrigin)(CBaseEntity *, Vector *); // edx
  const Vector *v4; // eax
  const FileWeaponInfo_t *WpnData; // eax
  edict_t *m_pPev; // esi
  CPASAttenuationFilter filter; // [esp+18h] [ebp-2Ch] BYREF
  float attenuation[3]; // [esp+38h] [ebp-Ch] BYREF
  int savedregs; // [esp+44h] [ebp+0h] BYREF

  v2 = (const Vector *)((int (__thiscall *)(CWeaponCSBase *))this->GetSoundEmissionOrigin)(a1: this);
  CRecipientFilter::CRecipientFilter(this: &filter);
  filter.__vftable = (CPASAttenuationFilter_vtbl *)&CPASFilter::`vftable';
  CRecipientFilter::AddRecipientsByPAS(this: &filter, origin: v2);
  GetSoundEmissionOrigin = this->GetSoundEmissionOrigin;
  filter.__vftable = (CPASAttenuationFilter_vtbl *)&CPASAttenuationFilter::`vftable';
  v4 = (const Vector *)((int (__thiscall *)(CWeaponCSBase *, float *, int))GetSoundEmissionOrigin)(
                         a1: this,
                         a2: attenuation,
                         a3: 1061997773);
  CPASAttenuationFilter::Filter(this: &filter, a2: (int)&savedregs, origin: v4, attenuation: COERCE_FLOAT(attenuation));
  CRecipientFilter::UsePredictionRules(this: &filter);
  WpnData = CBaseCombatWeapon::GetWpnData(this);
  m_pPev = this->m_Network.m_pPev;
  if ( *(_DWORD *)&WpnData[1].bParsedScript == 1 )
  {
    if ( m_pPev != nullptr )
      m_pPev -= (int)gpGlobals->pEdicts;
    CBaseEntity::EmitSound(
      &filter,
      iEntIndex: (int)m_pPev,
      soundname: "Default.ClipEmpty_Pistol",
      pOrigin: nullptr,
      soundtime: 0.0,
      duration: nullptr);
  }
  else
  {
    if ( m_pPev != nullptr )
      m_pPev -= (int)gpGlobals->pEdicts;
    CBaseEntity::EmitSound(
      &filter,
      iEntIndex: (int)m_pPev,
      soundname: "Default.ClipEmpty_Rifle",
      pOrigin: nullptr,
      soundtime: 0.0,
      duration: nullptr);
  }
  CRecipientFilter::~CRecipientFilter(this: &filter);
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x102E85D0
// Name: public: virtual float CWeaponCSBase::GetMaxSpeed(void)const
// Source: json
//------------------------------------------------------------------------------
double __thiscall CWeaponCSBase::GetMaxSpeed(CWeaponCSBase *this)
{
  return *(float *)&CBaseCombatWeapon::GetWpnData(this)[1].__vftable;
}

//------------------------------------------------------------------------------
// Address: 0x102E85E0
// Name: public: virtual void CWeaponCSBase::Precache(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWeaponCSBase::Precache(CWeaponCSBase *this)
{
  const char *v2; // eax
  const char *v3; // eax
  const char *v4; // eax
  const char *v5; // eax

  CBaseCombatWeapon::Precache(this);
  CBaseEntity::PrecacheScriptSound(soundname: "Default.ClipEmpty_Pistol");
  CBaseEntity::PrecacheScriptSound(soundname: "Default.ClipEmpty_Rifle");
  CBaseEntity::PrecacheScriptSound(soundname: "Default.Zoom");
  v2 = &CBaseCombatWeapon::GetWpnData(this)[1].aShootSounds[1][44];
  if ( v2 != nullptr && *v2 != 0 )
    PrecacheEffect(pEffectName: v2);
  v3 = &CBaseCombatWeapon::GetWpnData(this)[1].aShootSounds[2][44];
  if ( v3 != nullptr && *v3 != 0 )
    PrecacheEffect(pEffectName: v3);
  v4 = &CBaseCombatWeapon::GetWpnData(this)[1].aShootSounds[3][44];
  if ( v4 != nullptr && *v4 != 0 )
    PrecacheEffect(pEffectName: v4);
  v5 = &CBaseCombatWeapon::GetWpnData(this)[1].aShootSounds[0][32];
  if ( v5 != nullptr && *v5 != 0 )
    PrecacheEffect(pEffectName: v5);
  PrecacheEffect(pEffectName: "gunshotsplash");
}

//------------------------------------------------------------------------------
// Address: 0x102E8690
// Name: public: virtual bool CWeaponCSBase::CanDeploy(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CWeaponCSBase::CanDeploy(CWeaponCSBase *this)
{
  CBaseCombatCharacter *Owner; // eax
  vgui::ToggleButton *v3; // eax

  Owner = CBaseCombatWeapon::GetOwner(this);
  v3 = (vgui::ToggleButton *)__RTDynamicCast(
                               inptr: Owner,
                               VfDelta: 0,
                               SrcType: &CBaseCombatCharacter `RTTI Type Descriptor',
                               TargetType: &CCSPlayer `RTTI Type Descriptor',
                               isReference: 0);
  return v3 != nullptr
      && (!IAI_BehaviorBridge::BehaviorBridge_IsCurTaskContinuousMove(this: v3)
       || CBaseCombatWeapon::GetWpnData(this)[1].szClassName[26] != 0);
}

//------------------------------------------------------------------------------
// Address: 0x102E86E0
// Name: public: virtual bool CWeaponCSBase::IsRemoveable(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CWeaponCSBase::IsRemoveable(CWeaponCSBase *this)
{
  bool result; // al

  result = this->m_bRemoveable;
  if ( result )
    return this->m_nextPrevOwnerTouchTime <= gpGlobals->curtime;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102E8710
// Name: public: virtual class CBaseEntity __near * CWeaponCSBase::Respawn(void)
// Source: json
//------------------------------------------------------------------------------
CBaseEntity *__thiscall CWeaponCSBase::Respawn(CWeaponCSBase *this)
{
  const char *pszValue; // edi
  const Vector *v3; // eax
  CBaseEntity *v4; // eax
  CBaseEntity *v5; // edi
  const char *v7; // esi
  float thinkTime; // [esp+Ch] [ebp-1Ch]
  CBaseCombatCharacter *Owner; // [esp+10h] [ebp-18h]
  _BYTE v10[12]; // [esp+1Ch] [ebp-Ch] BYREF
  int savedregs; // [esp+28h] [ebp+0h] BYREF

  if ( (this->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
  pszValue = this->m_iClassname.pszValue;
  if ( pszValue == nullptr )
    pszValue = locale;
  Owner = CBaseCombatWeapon::GetOwner(this);
  v3 = g_pGameRules->VecWeaponRespawnSpot(this: g_pGameRules, result: v10, a3: this);
  v4 = CBaseEntity::Create(szName: pszValue, vecOrigin: v3, vecAngles: &this->m_angAbsRotation, pOwner: Owner);
  v5 = v4;
  if ( v4 != nullptr )
  {
    CBaseEntity::AddEffects(this: v4, nEffects: 32);
    v5->m_pfnTouch = nullptr;
    CBaseEntity::ThinkSet(
      this: v5,
      func: (void (__thiscall *)(CBaseEntity *))CBaseCombatWeapon::AttemptToMaterialize,
      thinkTime: 0.0,
      szContext: nullptr);
    UTIL_DropToFloor(pEntity: this, mask: 0x200400Bu, pIgnore: nullptr);
    thinkTime = ((double (__thiscall *)(CGameRules *, CWeaponCSBase *))g_pGameRules->FlWeaponRespawnTime)(
                  a1: g_pGameRules,
                  a2: this)
              + gpGlobals->curtime;
    CBaseEntity::SetNextThink(this: v5, thinkTime, szContext: nullptr);
    return v5;
  }
  else
  {
    v7 = this->m_iClassname.pszValue;
    if ( v7 == nullptr )
      v7 = locale;
    _Msg(a1: "Respawn failed to create %s!\n", v7);
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102E8800
// Name: public: virtual void CWeaponCSBase::Use(class CBaseEntity __near *,class CBaseEntity __near *,enum USE_TYPE,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWeaponCSBase::Use(
        CWeaponCSBase *this,
        CBaseEntity *pActivator,
        CBaseEntity *pCaller,
        USE_TYPE useType,
        float value)
{
  if ( pActivator != nullptr && pActivator->IsPlayer(this: pActivator) )
    COutputEvent::FireOutput(this: &this->m_OnPlayerUse, pActivator, pCaller, fDelay: 0.0);
}

//------------------------------------------------------------------------------
// Address: 0x102E8840
// Name: public: void CWeaponCSBase::SendReloadEvents(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWeaponCSBase::SendReloadEvents(CWeaponCSBase *this)
{
  CBaseCombatCharacter *Owner; // eax
  CCSPlayer *v2; // esi
  signed int m_pPev; // eax
  CPASFilter filter; // [esp+4h] [ebp-20h] BYREF
  int savedregs; // [esp+24h] [ebp+0h] BYREF

  Owner = CBaseCombatWeapon::GetOwner(this);
  v2 = (CCSPlayer *)__RTDynamicCast(
                      inptr: Owner,
                      VfDelta: 0,
                      SrcType: &CBaseCombatCharacter `RTTI Type Descriptor',
                      TargetType: &CCSPlayer `RTTI Type Descriptor',
                      isReference: 0);
  if ( v2 != nullptr )
  {
    if ( (v2->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this: v2, a2: (int)&savedregs);
    CRecipientFilter::CRecipientFilter(this: &filter);
    filter.__vftable = (CPASFilter_vtbl *)&CPASFilter::`vftable';
    CRecipientFilter::AddRecipientsByPAS(this: &filter, origin: &v2->m_vecAbsOrigin);
    CRecipientFilter::RemoveRecipient(this: &filter, player: (signed int)v2);
    UserMessageBegin(&filter, messagename: "ReloadEffect");
    m_pPev = (signed int)v2->m_Network.m_pPev;
    if ( m_pPev != 0 )
      m_pPev = (signed int)(m_pPev - (unsigned int)gpGlobals->pEdicts) >> 4;
    MessageWriteShort(iValue: m_pPev);
    MessageEnd();
    CCSPlayer::DoAnimationEvent(this: v2, event: PLAYERANIMEVENT_RELOAD, nData: 0);
    CRecipientFilter::~CRecipientFilter(this: &filter);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102E8900
// Name: public: virtual bool CWeaponCSBase::PhysicsSplash(class Vector const __near &,class Vector const __near &,float,float)
// Source: json
//------------------------------------------------------------------------------
// bad sp value at call has been detected, the output may be wrong!
char __thiscall CWeaponCSBase::PhysicsSplash(
        CWeaponCSBase *this,
        const Vector *centerPoint,
        const Vector *normal,
        float rawSpeed,
        float scaledSpeed)
{
  float v6; // xmm3_4
  float v7; // xmm1_4
  CEffectData data; // [esp+Ch] [ebp-68h] BYREF
  float size; // [esp+70h] [ebp-4h]

  if ( rawSpeed <= 20.0 )
    return 0;
  size = 4.0;
  if ( *(_DWORD *)&CBaseCombatWeapon::GetWpnData(this)[1].bParsedScript == 1 )
    v6 = size;
  else
    v6 = 6.0;
  v7 = rawSpeed * 0.0024999999;
  if ( (float)(rawSpeed * 0.0024999999) >= 0.0 )
  {
    if ( v7 > 1.0 )
      v7 = 1.0;
  }
  else
  {
    v7 = 0.0;
  }
  memset((void *)&data.m_vStart, 0, sizeof(data.m_vStart));
  memset((void *)&data.m_vAngles, 0, 20);
  memset(&data.m_flMagnitude, 0, 14);
  memset(&data.m_nMaterial, 0, 17);
  data.m_vOrigin = *centerPoint;
  data.m_vNormal.x = normal->x;
  data.m_vNormal.y = normal->y;
  data.m_flScale = ((double (__thiscall *)(IUniformRandomStream *, _DWORD, _DWORD))random->RandomFloat)(
                     a1: random,
                     a2: (float)(v7 * 3.0) + v6,
                     a3: (float)((float)(v7 * 3.0) + v6) + 1.0);
  if ( (CBaseEntity::GetWaterType(this) & 0x10) != 0 )
    data.m_fFlags |= 1u;
  DispatchEffect(pName: "gunshotsplash", &data);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x102E8B90
// Name: public: virtual bool CWeaponCSBase::DefaultReload(int,int,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CWeaponCSBase::DefaultReload(CWeaponCSBase *this, int iClipSize1, int iClipSize2, int iActivity)
{
  if ( CBaseCombatWeapon::DefaultReload(this, iClipSize1, (CMDLCacheCriticalSection)iClipSize2, iActivity) == 0 )
    return 0;
  CWeaponCSBase::SendReloadEvents(this);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x102E8BD0
// Name: public: bool CWeaponCSBase::IsUseable(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CWeaponCSBase::IsUseable(CWeaponCSBase *this)
{
  CBaseCombatCharacter *Owner; // eax
  CBaseCombatCharacter *v3; // edi
  bool result; // al
  int v5; // eax

  Owner = CBaseCombatWeapon::GetOwner(this);
  v3 = (CBaseCombatCharacter *)__RTDynamicCast(
                                 inptr: Owner,
                                 VfDelta: 0,
                                 SrcType: &CBaseCombatCharacter `RTTI Type Descriptor',
                                 TargetType: &CCSPlayer `RTTI Type Descriptor',
                                 isReference: 0);
  result = false;
  if ( v3 != nullptr )
  {
    if ( this->m_iClip1.m_Value > 0 )
      return true;
    v5 = this->GetPrimaryAmmoType(this);
    if ( CBaseCombatCharacter::GetAmmoCount(this: v3, iAmmoIndex: v5) > 0 || this->GetMaxClip1(this) == -1 )
      return true;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102E8C40
// Name: public: bool CWeaponCSBase::IsAPriorOwner(class CCSPlayer __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CWeaponCSBase::IsAPriorOwner(CWeaponCSBase *this, CCSPlayer *pPlayer)
{
  int m_Size; // edx
  int v3; // eax
  CCSPlayer **m_pMemory; // ecx

  m_Size = this->m_PriorOwners.m_Size;
  v3 = 0;
  if ( m_Size <= 0 )
  {
LABEL_5:
    v3 = -1;
  }
  else
  {
    m_pMemory = this->m_PriorOwners.m_Memory.m_pMemory;
    while ( *m_pMemory != pPlayer )
    {
      ++v3;
      ++m_pMemory;
      if ( v3 >= m_Size )
        goto LABEL_5;
    }
  }
  return v3 != -1;
}

//------------------------------------------------------------------------------
// Address: 0x102E8C80
// Name: public: CWeaponCSBase::CWeaponCSBase(void)
// Source: json
//------------------------------------------------------------------------------
CWeaponCSBase *__thiscall CWeaponCSBase::CWeaponCSBase(CWeaponCSBase *this)
{
  edict_t *m_pPev; // ecx
  edict_t *v3; // ecx
  edict_t *v4; // ecx

  CBaseCombatWeapon::CBaseCombatWeapon(this);
  this->__vftable = (CWeaponCSBase_vtbl *)&CWeaponCSBase::`vftable';
  this->m_PriorOwners.m_Memory.m_pMemory = nullptr;
  this->m_PriorOwners.m_Memory.m_nAllocationCount = 0;
  this->m_PriorOwners.m_Memory.m_nGrowSize = 0;
  this->m_PriorOwners.m_Size = 0;
  this->m_PriorOwners.m_pElements = nullptr;
  this->m_donor.m_Index = -1;
  CNavMesh::SaveCustomData((vgui::TreeView *)this, itemIndex: 1);
  this->m_nextPrevOwnerTouchTime = 0.0;
  this->m_prevOwner = nullptr;
  CCollisionProperty::SetSolidFlags(this: &this->m_Collision, flags: this->m_Collision.m_usSolidFlags.m_Value | 8);
  this->m_iDefaultExtraAmmo = 0;
  this->m_bFiredOutOfAmmoEvent = false;
  if ( this->m_fAccuracyPenalty.m_Value != 0.0 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x580u);
    }
    this->m_fAccuracyPenalty.m_Value = 0.0;
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
  if ( !this->m_bWaitForNoAttack.m_Value )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v4 = this->m_Network.m_pPev;
      if ( v4 != nullptr )
        CBaseEdict::StateChanged(this: &v4->CBaseEdict, offset: 0x5ADu);
    }
    this->m_bWaitForNoAttack.m_Value = true;
  }
  this->m_smokeAttachments = 0;
  this->m_gunHeat = 0.0;
  this->m_timeSinceLastShot = 0.0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x102E8DC0
// Name: public: virtual void CWeaponCSBase::SecondaryAttack(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWeaponCSBase::SecondaryAttack(CWeaponCSBase *this)
{
  CBaseCombatCharacter *Owner; // eax
  vgui::ToggleButton *v3; // eax
  vgui::ToggleButton *v4; // esi
  bool IsCurTaskContinuousMove; // al
  bool v6; // zf
  bool (__thiscall *SendWeaponAnim)(CBaseCombatWeapon *, int); // eax
  float v8; // xmm0_4
  edict_t *m_pPev; // ecx
  float v10; // xmm0_4
  edict_t *v11; // ecx

  Owner = CBaseCombatWeapon::GetOwner(this);
  v3 = (vgui::ToggleButton *)__RTDynamicCast(
                               inptr: Owner,
                               VfDelta: 0,
                               SrcType: &CBaseCombatCharacter `RTTI Type Descriptor',
                               TargetType: &CCSPlayer `RTTI Type Descriptor',
                               isReference: 0);
  v4 = v3;
  if ( v3 != nullptr && IAI_BehaviorBridge::BehaviorBridge_IsCurTaskContinuousMove(this: v3) )
  {
    IsCurTaskContinuousMove = IAI_BehaviorBridge::BehaviorBridge_IsCurTaskContinuousMove(this: v4);
    CNavMesh::SaveCustomData(this: (vgui::TreeView *)v4, itemIndex: !IsCurTaskContinuousMove);
    v6 = !IAI_BehaviorBridge::BehaviorBridge_IsCurTaskContinuousMove(this: v4);
    SendWeaponAnim = this->SendWeaponAnim;
    if ( v6 )
      ((void (__stdcall *)(int))SendWeaponAnim)(a1: 445);
    else
      ((void (__stdcall *)(int))SendWeaponAnim)(a1: 444);
    v8 = gpGlobals->curtime + 0.4;
    if ( this->m_flNextSecondaryAttack.m_Value != v8 )
    {
      if ( this->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&this->m_Network + 76) |= 1u;
      }
      else
      {
        m_pPev = this->m_Network.m_pPev;
        if ( m_pPev != nullptr )
          CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x498u);
      }
      this->m_flNextSecondaryAttack.m_Value = v8;
    }
    v10 = gpGlobals->curtime + 0.4;
    if ( this->m_flNextPrimaryAttack.m_Value != v10 )
    {
      if ( this->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&this->m_Network + 76) |= 1u;
        this->m_flNextPrimaryAttack.m_Value = v10;
      }
      else
      {
        v11 = this->m_Network.m_pPev;
        if ( v11 != nullptr )
          CBaseEdict::StateChanged(this: &v11->CBaseEdict, offset: 0x494u);
        this->m_flNextPrimaryAttack.m_Value = v10;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102E8F10
// Name: public: void CWeaponCSBase::CallSecondaryAttack(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWeaponCSBase::CallSecondaryAttack(CWeaponCSBase *this)
{
  CBaseCombatCharacter *Owner; // eax
  CBaseCombatCharacter *v3; // edi
  int v4; // eax

  Owner = CBaseCombatWeapon::GetOwner(this);
  v3 = (CBaseCombatCharacter *)__RTDynamicCast(
                                 inptr: Owner,
                                 VfDelta: 0,
                                 SrcType: &CBaseCombatCharacter `RTTI Type Descriptor',
                                 TargetType: &CCSPlayer `RTTI Type Descriptor',
                                 isReference: 0);
  if ( v3 != nullptr )
  {
    if ( this->m_iClip2.m_Value != -1 )
    {
      v4 = this->GetSecondaryAmmoType(this);
      if ( CBaseCombatCharacter::GetAmmoCount(this: v3, iAmmoIndex: v4) == 0 )
        this->m_bFireOnEmpty = true;
    }
    if ( IAI_BehaviorBridge::BehaviorBridge_IsCurTaskContinuousMove(this: (vgui::ToggleButton *)v3) )
      CWeaponCSBase::SecondaryAttack(this);
    else
      this->SecondaryAttack(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102E8F80
// Name: public: virtual void CWeaponCSBase::ItemPostFrame(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CWeaponCSBase::ItemPostFrame(CWeaponCSBase *this@<ecx>, int a2@<edi>)
{
  CBaseCombatCharacter *Owner; // eax
  CCSPlayer *v4; // ebx
  int AmmoCount; // ebx
  int m_Value; // eax
  int v7; // edx
  edict_t *m_pPev; // ecx
  edict_t *v9; // ecx
  CBaseEdict *v10; // ecx
  int m_nButtons; // eax
  int v12; // eax
  bool v13; // zf
  const char *v14; // eax
  IGameEvent *v15; // edi
  const char *pszValue; // ebx
  IGameEvent_vtbl *v17; // ebx
  int UserID; // eax
  IGameEvent_vtbl *v19; // ebx
  bool v20; // al
  IGameEvent *v21; // eax
  IGameEvent *v22; // esi
  IGameEvent_vtbl *v23; // edi
  int v24; // eax
  edict_t *v25; // ecx
  CBaseEdict *v26; // ecx
  int v27; // eax
  IGameEvent *v28; // edi
  int v29; // eax
  const char *weaponNameb; // [esp+8h] [ebp-8h]
  const char *weaponName; // [esp+8h] [ebp-8h]
  const char *weaponNamea; // [esp+8h] [ebp-8h]
  const char *weaponNamec; // [esp+8h] [ebp-8h]
  CCSPlayer *pPlayer; // [esp+Ch] [ebp-4h]

  Owner = CBaseCombatWeapon::GetOwner(this);
  v4 = (CCSPlayer *)__RTDynamicCast(
                      inptr: Owner,
                      VfDelta: 0,
                      SrcType: &CBaseCombatCharacter `RTTI Type Descriptor',
                      TargetType: &CCSPlayer `RTTI Type Descriptor',
                      isReference: 0);
  pPlayer = v4;
  if ( v4 == nullptr )
    return;
  this->UpdateAccuracyPenalty(this);
  this->UpdateShieldState(this);
  if ( !this->m_bInReload.m_Value )
    goto LABEL_19;
  if ( gpGlobals->curtime >= v4->m_flNextAttack.m_Value )
  {
    weaponNameb = (const char *)(this->GetMaxClip1(this) - this->m_iClip1.m_Value);
    if ( (int)weaponNameb >= CBaseCombatCharacter::GetAmmoCount(this: v4, iAmmoIndex: this->m_iPrimaryAmmoType.m_Value) )
      AmmoCount = CBaseCombatCharacter::GetAmmoCount(this: v4, iAmmoIndex: this->m_iPrimaryAmmoType.m_Value);
    else
      AmmoCount = this->GetMaxClip1(this) - this->m_iClip1.m_Value;
    m_Value = this->m_iClip1.m_Value;
    v7 = m_Value + AmmoCount;
    weaponName = (const char *)(m_Value + AmmoCount);
    if ( m_Value != m_Value + AmmoCount )
    {
      if ( this->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&this->m_Network + 76) |= 1u;
      }
      else
      {
        m_pPev = this->m_Network.m_pPev;
        if ( m_pPev != nullptr )
        {
          CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x4B0u);
          v7 = (int)weaponName;
        }
      }
      this->m_iClip1.m_Value = v7;
    }
    CBaseCombatCharacter::RemoveAmmo(this: pPlayer, iCount: AmmoCount, iAmmoIndex: this->m_iPrimaryAmmoType.m_Value);
    if ( this->m_bInReload.m_Value )
    {
      if ( this->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&this->m_Network + 76) |= 1u;
      }
      else
      {
        v9 = this->m_Network.m_pPev;
        if ( v9 != nullptr )
          CBaseEdict::StateChanged(this: &v9->CBaseEdict, offset: 0x4E5u);
      }
      this->m_bInReload.m_Value = false;
    }
LABEL_19:
    v4 = pPlayer;
  }
  if ( (v4->m_nButtons & 1) == 0
    && v4->m_iShotsFired.m_Value > 0
    && (!this->IsFullAuto(this) || this->m_iClip1.m_Value == 0)
    && v4->m_iShotsFired.m_Value != 0 )
  {
    if ( v4->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&v4->m_Network + 76) |= 1u;
    }
    else
    {
      v10 = &v4->m_Network.m_pPev->CBaseEdict;
      if ( v10 != nullptr )
        CBaseEdict::StateChanged(this: v10, offset: 0x1788u);
    }
    v4->m_iShotsFired.m_Value = 0;
  }
  m_nButtons = v4->m_nButtons;
  if ( (m_nButtons & 1) != 0 && gpGlobals->curtime >= this->m_flNextPrimaryAttack.m_Value )
  {
    if ( this->m_iClip1.m_Value == 0
      || this->GetMaxClip1(this) == -1
      && (v12 = this->GetPrimaryAmmoType(this), CBaseCombatCharacter::GetAmmoCount(this: v4, iAmmoIndex: v12) == 0) )
    {
      this->m_bFireOnEmpty = true;
    }
    if ( !CCSGameRules::IsFreezePeriod(this: (CCSGameRules *)g_pGameRules)
      && !v4->m_bIsDefusing.m_Value
      && v4->m_iPlayerState.m_Value == STATE_ACTIVE
      && !IAI_BehaviorBridge::BehaviorBridge_IsCurTaskContinuousMove(this: (vgui::ToggleButton *)v4)
      && (v4->m_iShotsFired.m_Value <= 0 || this->IsFullAuto(this) && this->m_iClip1.m_Value != 0)
      && !this->m_bWaitForNoAttack.m_Value )
    {
      this->m_bFiredOutOfAmmoEvent = false;
      if ( *(_DWORD *)&CBaseCombatWeapon::GetWpnData(this)[1].bParsedScript != 8 )
      {
        v13 = ((unsigned __int8 (__thiscall *)(CWeaponCSBase *, int))this->HasAmmo)(a1: this, a2) == 0;
        v14 = "weapon_fire";
        if ( v13 )
          v14 = "weapon_fire_on_empty";
        v15 = (IGameEvent *)((int (__thiscall *)(IGameEventManager2 *, const char *, _DWORD))gameeventmanager->CreateEventA)(
                              a1: gameeventmanager,
                              a2: v14,
                              a3: 0);
        if ( v15 != nullptr )
        {
          if ( this->m_iClassname.pszValue != nullptr )
          {
            pszValue = this->m_iClassname.pszValue;
            weaponNamea = pszValue;
          }
          else
          {
            pszValue = locale;
            weaponNamea = locale;
          }
          if ( strncmp(first: pszValue, last: "weapon_", count: 7u) == 0 )
            weaponNamea = pszValue + 7;
          v17 = v15->__vftable;
          UserID = CBasePlayer::GetUserID(this: pPlayer);
          v17->SetInt(this: v15, a2: "userid", a3: UserID);
          v15->SetString(this: v15, a2: "weapon", a3: weaponNamea);
          v19 = v15->__vftable;
          v20 = this->IsSilenced(this);
          v19->SetBool(this: v15, a2: "silenced", a3: v20);
          gameeventmanager->FireEvent(this: gameeventmanager, a2: v15, a3: false);
        }
      }
      this->PrimaryAttack(this);
    }
  }
  else if ( (m_nButtons & 0x800) != 0 && gpGlobals->curtime >= this->m_flNextSecondaryAttack.m_Value )
  {
    this->IsZoomOrKnife(this);
    CWeaponCSBase::CallSecondaryAttack(this);
    v4->m_nButtons &= ~0x800u;
  }
  else if ( (m_nButtons & 0x80000) != 0 && gpGlobals->curtime >= this->m_flNextSecondaryAttack.m_Value )
  {
    if ( this->IsZoomOrKnife(this) )
      CWeaponCSBase::CallSecondaryAttack(this);
    v4->m_nButtons &= ~0x80000u;
  }
  else if ( (m_nButtons & 0x2000) == 0
         || this->GetMaxClip1(this) == -1
         || this->m_bInReload.m_Value
         || gpGlobals->curtime <= this->m_flNextPrimaryAttack.m_Value )
  {
    if ( (v4->m_nButtons & 0x80801) == 0 )
    {
      this->m_bFireOnEmpty = false;
      if ( this->m_bWaitForNoAttack.m_Value )
      {
        if ( this->m_Network.m_TimerEvent.m_bRegistered )
        {
          *((_BYTE *)&this->m_Network + 76) |= 1u;
        }
        else
        {
          v25 = this->m_Network.m_pPev;
          if ( v25 != nullptr )
            CBaseEdict::StateChanged(this: &v25->CBaseEdict, offset: 0x5ADu);
        }
        this->m_bWaitForNoAttack.m_Value = false;
      }
      if ( v4->m_iShotsFired.m_Value != 0 )
      {
        if ( v4->m_Network.m_TimerEvent.m_bRegistered )
        {
          *((_BYTE *)&v4->m_Network + 76) |= 1u;
        }
        else
        {
          v26 = &v4->m_Network.m_pPev->CBaseEdict;
          if ( v26 != nullptr )
            CBaseEdict::StateChanged(this: v26, offset: 0x1788u);
        }
        v4->m_iShotsFired.m_Value = 0;
      }
      if ( g_pGameRules != nullptr
        && CCSGameRules::IsPlayingTraining(this: (CCSGameRules *)g_pGameRules)
        && !this->m_bFiredOutOfAmmoEvent
        && this->m_iClip1.m_Value == 0
        && !this->m_bInReload.m_Value )
      {
        v27 = this->GetPrimaryAmmoType(this);
        if ( CBaseCombatCharacter::GetAmmoCount(this: v4, iAmmoIndex: v27) == 0 )
        {
          v28 = gameeventmanager->CreateEventA(this: gameeventmanager, a2: "weapon_outofammo", a3: 0, a4: 0);
          if ( v28 != nullptr )
          {
            this->m_bFiredOutOfAmmoEvent = true;
            weaponNamec = (const char *)v28->__vftable;
            v29 = CBasePlayer::GetUserID(this: v4);
            (*((void (__thiscall **)(IGameEvent *, const char *, int))weaponNamec + 11))(a1: v28, a2: "userid", a3: v29);
            gameeventmanager->FireEvent(this: gameeventmanager, a2: v28, a3: false);
          }
        }
      }
      if ( gpGlobals->curtime <= this->m_flNextPrimaryAttack.m_Value
        || this->m_iClip1.m_Value != 0
        || !CWeaponCSBase::IsUseable(this)
        || (this->GetWeaponFlags(this) & 2) != 0
        || this->m_bInReload.m_Value )
      {
        this->WeaponIdle(this);
      }
      else
      {
        this->Reload(this);
        v4->m_hasReloaded = true;
      }
    }
  }
  else if ( !IAI_BehaviorBridge::BehaviorBridge_IsCurTaskContinuousMove(this: (vgui::ToggleButton *)v4)
         && this->Reload(this) )
  {
    v4->m_hasReloaded = true;
    v21 = gameeventmanager->CreateEventA(this: gameeventmanager, a2: "weapon_reload", a3: 0, a4: 0);
    v22 = v21;
    if ( v21 != nullptr )
    {
      v23 = v21->__vftable;
      v24 = CBasePlayer::GetUserID(this: v4);
      v23->SetInt(this: v22, a2: "userid", a3: v24);
      gameeventmanager->FireEvent(this: gameeventmanager, a2: v22, a3: false);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102E95A0
// Name: public: virtual bool CWeaponCSBase::DefaultDeploy(char __near *,char __near *,int,char __near *)
// Source: json
//------------------------------------------------------------------------------
char __userpurge CWeaponCSBase::DefaultDeploy@<al>(
        CWeaponCSBase *this@<ecx>,
        int a2@<edi>,
        char *szViewModel,
        char *szWeaponModel,
        int iActivity,
        char *szAnimExt)
{
  CBaseCombatCharacter *Owner; // eax
  CCSPlayer *v8; // ebx
  CWeaponCSBase_vtbl *v10; // edi
  Activity v11; // eax
  int m_Value; // edi
  CStudioHdr *m_pStudioHdr; // eax
  float v14; // xmm0_4
  CBaseEdict *v15; // ecx
  CGlobalVars *v16; // ebx
  edict_t *m_pPev; // ecx
  CGlobalVars *v18; // ebx
  edict_t *v19; // ecx
  bool IsCurTaskContinuousMove; // zf
  void (__thiscall *SetWeaponModelIndex)(CWeaponCSBase *, const char *); // edx
  CCSPlayer *pOwner; // [esp+8h] [ebp-4h]
  float szAnimExtb; // [esp+20h] [ebp+14h]
  float szAnimExta; // [esp+20h] [ebp+14h]

  Owner = CBaseCombatWeapon::GetOwner(this);
  v8 = (CCSPlayer *)__RTDynamicCast(
                      inptr: Owner,
                      VfDelta: 0,
                      SrcType: &CBaseCombatCharacter `RTTI Type Descriptor',
                      TargetType: &CCSPlayer `RTTI Type Descriptor',
                      isReference: 0);
  pOwner = v8;
  if ( v8 == nullptr )
    return 0;
  CBasePlayer::SetAnimationExtension(this: v8, pExtension: szAnimExt);
  ((void (__thiscall *)(CWeaponCSBase *, int))this->SetViewModel)(a1: this, a2);
  v10 = this->__vftable;
  v11 = this->GetDeployActivity(this);
  v10->SendWeaponAnim(this, a2: v11);
  m_Value = this->m_nSequence.m_Value;
  if ( this->m_pStudioHdr == nullptr && CBaseEntity::GetModel(this) != nullptr )
    CBaseAnimating::LockStudioHdr(this);
  m_pStudioHdr = this->m_pStudioHdr;
  if ( m_pStudioHdr == nullptr || m_pStudioHdr->m_pStudioHdr == nullptr )
    m_pStudioHdr = nullptr;
  szAnimExtb = CBaseAnimating::SequenceDuration(this, pStudioHdr: m_pStudioHdr, iSequence: m_Value);
  szAnimExta = gpGlobals->curtime + szAnimExtb;
  v14 = szAnimExta;
  if ( v8->m_flNextAttack.m_Value != szAnimExta )
  {
    if ( v8->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&v8->m_Network + 76) |= 1u;
    }
    else
    {
      v15 = &v8->m_Network.m_pPev->CBaseEdict;
      if ( v15 != nullptr )
      {
        CBaseEdict::StateChanged(this: v15, offset: 0x684u);
        v14 = szAnimExta;
      }
    }
    v8->m_flNextAttack.m_Value = v14;
  }
  v16 = gpGlobals;
  if ( this->m_flNextPrimaryAttack.m_Value != gpGlobals->curtime )
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
    this->m_flNextPrimaryAttack.m_Value = v16->curtime;
  }
  v18 = gpGlobals;
  if ( this->m_flNextSecondaryAttack.m_Value != gpGlobals->curtime )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v19 = this->m_Network.m_pPev;
      if ( v19 != nullptr )
        CBaseEdict::StateChanged(this: &v19->CBaseEdict, offset: 0x498u);
    }
    this->m_flNextSecondaryAttack.m_Value = v18->curtime;
  }
  this->SetWeaponVisible(this, a2: true);
  CNavMesh::SaveCustomData(this: (vgui::TreeView *)pOwner, itemIndex: 0);
  IsCurTaskContinuousMove = IAI_BehaviorBridge::BehaviorBridge_IsCurTaskContinuousMove(this: (vgui::ToggleButton *)pOwner);
  SetWeaponModelIndex = this->SetWeaponModelIndex;
  if ( IsCurTaskContinuousMove )
    SetWeaponModelIndex(this, a2: "models/weapons/w_shield.mdl");
  else
    SetWeaponModelIndex(this, a2: szWeaponModel);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x102E9780
// Name: public: virtual void CWeaponCSBase::SetWeaponModelIndex(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWeaponCSBase::SetWeaponModelIndex(CWeaponCSBase *this, const char *pName)
{
  int v3; // edi
  edict_t *m_pPev; // ecx

  v3 = modelinfo->GetModelIndex(this: modelinfo, a2: pName);
  if ( this->m_iWorldModelIndex.m_Value != v3 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
      this->m_iWorldModelIndex.m_Value = v3;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x4A0u);
      this->m_iWorldModelIndex.m_Value = v3;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102E97E0
// Name: protected: float CWeaponCSBase::CalculateNextAttackTime(float)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CWeaponCSBase::CalculateNextAttackTime(CWeaponCSBase *this, float fCycleTime)
{
  float curtime; // xmm2_4
  float m_Value; // xmm0_4
  float v5; // xmm0_4
  edict_t *m_pPev; // ecx
  edict_t *v7; // ecx
  float fCurAttack; // [esp+0h] [ebp-4h]

  curtime = gpGlobals->curtime;
  m_Value = this->m_flNextPrimaryAttack.m_Value;
  fCurAttack = m_Value;
  if ( (float)(curtime - m_Value) < 0.0 || (float)(curtime - m_Value) > gpGlobals->interval_per_tick )
  {
    m_Value = gpGlobals->curtime;
    fCurAttack = m_Value;
  }
  v5 = m_Value + fCycleTime;
  if ( this->m_flNextPrimaryAttack.m_Value != v5 )
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
    this->m_flNextPrimaryAttack.m_Value = v5;
  }
  if ( this->m_flNextSecondaryAttack.m_Value != this->m_flNextPrimaryAttack.m_Value )
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
    this->m_flNextSecondaryAttack.m_Value = this->m_flNextPrimaryAttack.m_Value;
  }
  return fCurAttack;
}

//------------------------------------------------------------------------------
// Address: 0x102E98C0
// Name: public: virtual bool CWeaponCSBase::Deploy(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CWeaponCSBase::Deploy(CWeaponCSBase *this)
{
  CBaseCombatCharacter *Owner; // eax
  CBaseEdict **v3; // eax
  CBasePlayer *v4; // edi
  CBaseEdict *v5; // ecx
  CBaseEdict *v6; // ecx
  CBaseEdict *v7; // ecx
  edict_t *m_pPev; // ecx

  Owner = CBaseCombatWeapon::GetOwner(this);
  v3 = (CBaseEdict **)__RTDynamicCast(
                        inptr: Owner,
                        VfDelta: 0,
                        SrcType: &CBaseCombatCharacter `RTTI Type Descriptor',
                        TargetType: &CCSPlayer `RTTI Type Descriptor',
                        isReference: 0);
  v4 = (CBasePlayer *)v3;
  if ( v3 != nullptr )
  {
    if ( v3[1506] != nullptr )
    {
      if ( *((_BYTE *)v3 + 84) != 0 )
      {
        *((_BYTE *)v3 + 88) |= 1u;
      }
      else
      {
        v5 = v3[6];
        if ( v5 != nullptr )
          CBaseEdict::StateChanged(this: v5, offset: 0x1788u);
      }
      v4[1].m_flexWeight.m_Value[28] = 0.0;
    }
    if ( LOBYTE(v4[1].m_ResponseContexts.m_Memory.m_nGrowSize) != 0 )
    {
      if ( v4->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&v4->m_Network + 76) |= 1u;
      }
      else
      {
        v6 = &v4->m_Network.m_pPev->CBaseEdict;
        if ( v6 != nullptr )
          CBaseEdict::StateChanged(this: v6, offset: 0x1308u);
      }
      LOBYTE(v4[1].m_ResponseContexts.m_Memory.m_nGrowSize) = 0;
    }
    if ( v4[1].m_ResponseContexts.m_Size != 0 )
    {
      if ( v4->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&v4->m_Network + 76) |= 1u;
      }
      else
      {
        v7 = &v4->m_Network.m_pPev->CBaseEdict;
        if ( v7 != nullptr )
          CBaseEdict::StateChanged(this: v7, offset: 0x130Cu);
      }
      v4[1].m_ResponseContexts.m_Size = 0;
    }
    CBasePlayer::SetFOV(this: v4, pRequester: v4, FOV: 0, zoomRate: 0.0, iZoomStart: 0);
  }
  if ( this->m_fAccuracyPenalty.m_Value != 0.0 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x580u);
    }
    this->m_fAccuracyPenalty.m_Value = 0.0;
  }
  this->m_gunHeat = 0.0;
  this->m_smokeAttachments = 0;
  this->m_timeSinceLastShot = 0.0;
  return CBaseCombatWeapon::Deploy(this);
}

//------------------------------------------------------------------------------
// Address: 0x102E9A10
// Name: public: virtual void CWeaponCSBase::OnRoundRestart(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWeaponCSBase::OnRoundRestart(CWeaponCSBase *this)
{
  CNetworkVarBase<bool,CWeaponCSBase::NetworkVar_m_bWaitForNoAttack> *p_m_bWaitForNoAttack; // esi
  edict_t *m_pPev; // ecx

  p_m_bWaitForNoAttack = &this->m_bWaitForNoAttack;
  this->m_PriorOwners.m_Size = 0;
  if ( !this->m_bWaitForNoAttack.m_Value )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
      p_m_bWaitForNoAttack->m_Value = true;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x5ADu);
      p_m_bWaitForNoAttack->m_Value = true;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102E9A60
// Name: public: virtual bool CWeaponCSBase::Reload(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CWeaponCSBase::Reload(CWeaponCSBase *this)
{
  CBaseCombatCharacter *Owner; // eax
  char *v3; // eax
  _DWORD *v5; // esi
  CBaseEdict *v6; // ecx

  Owner = CBaseCombatWeapon::GetOwner(this);
  v3 = (char *)__RTDynamicCast(
                 inptr: Owner,
                 VfDelta: 0,
                 SrcType: &CBaseCombatCharacter `RTTI Type Descriptor',
                 TargetType: &CCSPlayer `RTTI Type Descriptor',
                 isReference: 0);
  if ( v3 == nullptr )
    return 0;
  v5 = v3 + 6024;
  if ( *((_DWORD *)v3 + 1506) != 0 )
  {
    if ( v3[84] != 0 )
    {
      v3[88] |= 1u;
    }
    else
    {
      v6 = *((CBaseEdict **)v3 + 6);
      if ( v6 != nullptr )
        CBaseEdict::StateChanged(this: v6, offset: 0x1788u);
    }
    *v5 = 0;
  }
  this->m_bFiredOutOfAmmoEvent = false;
  return CBaseCombatWeapon::Reload(this);
}

//------------------------------------------------------------------------------
// Address: 0x102E9AE0
// Name: public: virtual void CWeaponCSBase::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWeaponCSBase::Spawn(CWeaponCSBase *this)
{
  edict_t *m_pPev; // ecx

  CBaseCombatWeapon::Spawn(this);
  CCollisionProperty::UseTriggerBounds(this: &this->m_Collision, bEnable: true, flBloat: 30.0);
  CBaseEntity::SetCollisionGroup(this, collisionGroup: 11);
  this->m_iExtraPrimaryAmmo = this->m_iDefaultExtraAmmo;
  *(_QWORD *)&this->m_gunHeat = 0;
  this->m_timeSinceLastShot = 0.0;
  *(_QWORD *)&this->m_nextPrevOwnerTouchTime = 0;
  this->m_donor.m_Index = -1;
  this->m_donated = false;
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
  VisibilityMonitor_AddEntity(pEntity: this, flMinDist: 400.0, pfnCallback: nullptr, pfnEvaluator: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x102E9BB0
// Name: public: virtual bool CWeaponCSBase::DefaultPistolReload(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CWeaponCSBase::DefaultPistolReload(CWeaponCSBase *this)
{
  CBaseCombatCharacter *Owner; // eax
  CBaseCombatCharacter *v3; // edi
  int v5; // eax
  const FileWeaponInfo_t *WpnData; // eax
  CBaseEdict *v7; // ecx

  Owner = CBaseCombatWeapon::GetOwner(this);
  v3 = (CBaseCombatCharacter *)__RTDynamicCast(
                                 inptr: Owner,
                                 VfDelta: 0,
                                 SrcType: &CBaseCombatCharacter `RTTI Type Descriptor',
                                 TargetType: &CCSPlayer `RTTI Type Descriptor',
                                 isReference: 0);
  if ( v3 == nullptr )
    return 0;
  v5 = this->GetPrimaryAmmoType(this);
  if ( CBaseCombatCharacter::GetAmmoCount(this: v3, iAmmoIndex: v5) > 0 )
  {
    WpnData = CBaseCombatWeapon::GetWpnData(this);
    if ( !this->DefaultReload(this, a2: WpnData->iDefaultClip1, a3: 0, a4: 192) )
      return 0;
    if ( LODWORD(v3[2].m_flexWeight.m_Value[68]) != 0 )
    {
      if ( v3->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&v3->m_Network + 76) |= 1u;
        v3[2].m_flexWeight.m_Value[68] = 0.0;
        return 1;
      }
      v7 = &v3->m_Network.m_pPev->CBaseEdict;
      if ( v7 != nullptr )
        CBaseEdict::StateChanged(this: v7, offset: 0x1788u);
      v3[2].m_flexWeight.m_Value[68] = 0.0;
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x102E9C60
// Name: public: virtual void CWeaponCSBase::UpdateAccuracyPenalty(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CWeaponCSBase::UpdateAccuracyPenalty(CWeaponCSBase *this@<ecx>, int a2@<ebp>)
{
  CBaseCombatCharacter *Owner; // eax
  CBaseEntity *v4; // esi
  float *WpnData; // edi
  CSWeaponMode m_Value; // ecx
  float v7; // xmm1_4
  float v8; // xmm0_4
  float v9; // xmm1_4
  float v10; // xmm2_4
  float v11; // xmm2_4
  float v12; // xmm1_4
  int v13; // xmm0_4
  float v14; // xmm2_4
  unsigned __int8 v15; // al
  float v16; // xmm0_4
  float v17; // xmm0_4
  float v18; // xmm1_4
  CNetworkVarBase<float,CWeaponCSBase::NetworkVar_m_fAccuracyPenalty> *p_m_fAccuracyPenalty; // edx
  CNetworkVarBase<float,CWeaponCSBase::NetworkVar_m_fAccuracyPenalty> *v20; // eax
  CBaseEdict *v21; // ecx
  int v22; // eax
  double v23; // xmm0_8
  float v24; // xmm0_4
  double v25; // xmm0_8
  __m128 interval_per_tick_low; // xmm1
  double v27; // xmm0_8
  float v28; // xmm0_4
  CNetworkVarBase<float,CWeaponCSBase::NetworkVar_m_fAccuracyPenalty> *v29; // eax
  CBaseEdict *m_Value_low; // ecx
  float v31; // [esp-20h] [ebp-2Ch]
  float v32; // [esp-Ch] [ebp-18h]
  CNetworkVarBase<float,CWeaponCSBase::NetworkVar_m_fAccuracyPenalty> *v34; // [esp-8h] [ebp-14h]
  float v35; // [esp-4h] [ebp-10h]
  _DWORD v36[2]; // [esp+0h] [ebp-Ch] BYREF
  _UNKNOWN *retaddr; // [esp+Ch] [ebp+0h]

  v36[0] = a2;
  v36[1] = retaddr;
  Owner = CBaseCombatWeapon::GetOwner(this);
  v4 = (CBaseEntity *)__RTDynamicCast(
                        inptr: Owner,
                        VfDelta: 0,
                        SrcType: &CBaseCombatCharacter `RTTI Type Descriptor',
                        TargetType: &CCSPlayer `RTTI Type Descriptor',
                        isReference: 0);
  if ( v4 != nullptr )
  {
    WpnData = (float *)CBaseCombatWeapon::GetWpnData(this);
    if ( (v4->m_iEFlags & 0x1000) != 0 )
      CBaseEntity::CalcAbsoluteVelocity(this: v4, a2: (int)v36);
    m_Value = this->m_weaponMode.m_Value;
    v7 = WpnData[466];
    v31 = fsqrt(
            (float)(v4->m_vecAbsVelocity.x * v4->m_vecAbsVelocity.x)
          + (float)(v4->m_vecAbsVelocity.y * v4->m_vecAbsVelocity.y));
    v8 = v7 * 0.34;
    v9 = v7 * 0.94999999;
    if ( v8 == v9 )
    {
      v10 = 0.0;
      if ( (float)(v31 - v9) >= 0.0 )
        v10 = WpnData[m_Value + 586];
    }
    else
    {
      v11 = v31 - v8;
      v12 = v9 - v8;
      v13 = 0;
      v14 = v11 / v12;
      if ( v14 < 0.0 || (v13 = 1065353216, v14 > 1.0) )
        v14 = *(float *)&v13;
      v10 = v14 * WpnData[m_Value + 586];
    }
    v15 = v4->m_MoveType.m_Value;
    if ( v15 == 9 )
    {
      v16 = WpnData[m_Value + 582] + WpnData[m_Value + 576];
    }
    else if ( (v4->m_fFlags.m_Value & 2) != 0 )
    {
      v16 = WpnData[m_Value + 574];
    }
    else
    {
      v16 = WpnData[m_Value + 576];
    }
    v17 = v16 + v10;
    v35 = v17;
    if ( this->m_bInReload.m_Value )
    {
      v17 = v17 + WpnData[590];
      v35 = v17;
    }
    v18 = this->m_fAccuracyPenalty.m_Value;
    p_m_fAccuracyPenalty = &this->m_fAccuracyPenalty;
    v34 = &this->m_fAccuracyPenalty;
    v32 = v18;
    if ( v17 <= v18 )
    {
      if ( v15 != 9 && ((v22 = v4->m_fFlags.m_Value) & 1) != 0 && (v22 & 2) != 0 )
      {
        __libm_sse2_log(a1: (__m128d)0x4024000000000000uLL);
        *(float *)&v23 = v23;
        v24 = *(float *)&v23 / WpnData[589];
      }
      else
      {
        __libm_sse2_log(a1: (__m128d)0x4024000000000000uLL);
        *(float *)&v25 = v25;
        v24 = *(float *)&v25 / WpnData[588];
      }
      interval_per_tick_low = (__m128)LODWORD(gpGlobals->interval_per_tick);
      interval_per_tick_low.m128_f32[0] = interval_per_tick_low.m128_f32[0] * v24;
      __libm_sse2_exp(a1: _mm_cvtps_pd(_mm_xor_ps(interval_per_tick_low, (__m128)_mask__NegFloat_)));
      *(float *)&v27 = v27;
      v28 = (float)(*(float *)&v27 * (float)(v32 - v35)) + v35;
      if ( v34->m_Value != v28 )
      {
        v29 = v34 - 352;
        if ( LOBYTE(v34[-331].m_Value) != 0 )
        {
          LOBYTE(v29[22].m_Value) |= 1u;
          v34->m_Value = v28;
        }
        else
        {
          m_Value_low = (CBaseEdict *)LODWORD(v29[6].m_Value);
          if ( m_Value_low != nullptr )
            CBaseEdict::StateChanged(this: m_Value_low, offset: 0x580u);
          v34->m_Value = v28;
        }
      }
    }
    else
    {
      v20 = p_m_fAccuracyPenalty - 352;
      if ( LOBYTE(p_m_fAccuracyPenalty[-331].m_Value) != 0 )
      {
        LOBYTE(v20[22].m_Value) |= 1u;
        p_m_fAccuracyPenalty->m_Value = v17;
      }
      else
      {
        v21 = (CBaseEdict *)LODWORD(v20[6].m_Value);
        if ( v21 != nullptr )
        {
          CBaseEdict::StateChanged(this: v21, offset: 0x580u);
          v17 = v35;
          p_m_fAccuracyPenalty = v34;
        }
        p_m_fAccuracyPenalty->m_Value = v17;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102E9F00
// Name: public: virtual void CWeaponCSBase::OnJump(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWeaponCSBase::OnJump(CWeaponCSBase *this, float fImpulse)
{
  const FileWeaponInfo_t *WpnData; // eax
  float m_Value; // xmm1_4
  float v5; // xmm0_4
  edict_t *m_pPev; // ecx

  WpnData = CBaseCombatWeapon::GetWpnData(this);
  m_Value = this->m_fAccuracyPenalty.m_Value;
  v5 = (float)(*(float *)&WpnData[1].szAIAddOn[4 * this->m_weaponMode.m_Value] * fImpulse) + m_Value;
  if ( m_Value != v5 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
      this->m_fAccuracyPenalty.m_Value = v5;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x580u);
      this->m_fAccuracyPenalty.m_Value = v5;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102E9F90
// Name: public: virtual void CWeaponCSBase::OnLand(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWeaponCSBase::OnLand(CWeaponCSBase *this, float fVelocity)
{
  const FileWeaponInfo_t *WpnData; // eax
  float m_Value; // xmm2_4
  float v5; // xmm0_4
  edict_t *m_pPev; // ecx
  CBaseCombatCharacter *Owner; // eax
  CBasePlayer *v8; // eax
  CBasePlayer *v9; // esi
  QAngle angle; // [esp+14h] [ebp-10h] BYREF
  float fPenalty; // [esp+20h] [ebp-4h]
  float fVKick; // [esp+2Ch] [ebp+8h]

  WpnData = CBaseCombatWeapon::GetWpnData(this);
  m_Value = this->m_fAccuracyPenalty.m_Value;
  v5 = m_Value + (float)(*(float *)&WpnData[1].szAIAddOn[4 * this->m_weaponMode.m_Value + 8] * fVelocity);
  fPenalty = *(float *)&WpnData[1].szAIAddOn[4 * this->m_weaponMode.m_Value + 8] * fVelocity;
  if ( m_Value != v5 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x580u);
    }
    this->m_fAccuracyPenalty.m_Value = v5;
  }
  Owner = CBaseCombatWeapon::GetOwner(this);
  v8 = (CBasePlayer *)__RTDynamicCast(
                        inptr: Owner,
                        VfDelta: 0,
                        SrcType: &CBaseCombatCharacter `RTTI Type Descriptor',
                        TargetType: &CCSPlayer `RTTI Type Descriptor',
                        isReference: 0);
  v9 = v8;
  if ( v8 != nullptr )
  {
    angle = CBasePlayer::GetPunchAngle(this: v8)->m_Value;
    __libm_sse2_asin();
    fVKick = (float)(fPenalty * 57.29578) * 0.2;
    angle.x = angle.x + fVKick;
    angle.y = SharedRandomFloat(sharedname: "LandPunchAngleYaw", flMinVal: -1.0, flMaxVal: 1.0, additionalSeed: 0)
            * fVKick
            * 0.1
            + angle.y;
    CBasePlayer::SetPunchAngle(this: v9, punchAngle: &angle);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102EA0D0
// Name: public: void CWeaponCSBase::AddToPriorOwnerList(class CCSPlayer __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWeaponCSBase::AddToPriorOwnerList(CWeaponCSBase *this, CCSPlayer *pPlayer)
{
  CUtlMemory<vgui::TreeNode *,int> *p_m_PriorOwners; // esi
  int m_Size; // ecx
  int v4; // eax
  CCSPlayer **m_pMemory; // edx
  int m_nAllocationCount; // eax
  int v7; // edi
  vgui::TreeNode **v8; // ecx
  int v9; // eax
  vgui::TreeNode **v10; // eax

  p_m_PriorOwners = (CUtlMemory<vgui::TreeNode *,int> *)&this->m_PriorOwners;
  m_Size = this->m_PriorOwners.m_Size;
  v4 = 0;
  if ( m_Size <= 0 )
    goto LABEL_7;
  m_pMemory = (CCSPlayer **)p_m_PriorOwners->m_pMemory;
  while ( *m_pMemory != pPlayer )
  {
    ++v4;
    ++m_pMemory;
    if ( v4 >= m_Size )
      goto LABEL_7;
  }
  if ( v4 == -1 )
  {
LABEL_7:
    m_nAllocationCount = p_m_PriorOwners->m_nAllocationCount;
    v7 = m_Size;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<CNavLadder *,int>::Grow(this: p_m_PriorOwners, num: m_Size - m_nAllocationCount + 1);
    ++p_m_PriorOwners[1].m_pMemory;
    v8 = p_m_PriorOwners->m_pMemory;
    v9 = (int)p_m_PriorOwners[1].m_pMemory - v7 - 1;
    p_m_PriorOwners[1].m_nAllocationCount = (int)p_m_PriorOwners->m_pMemory;
    if ( v9 > 0 )
      _V_memmove(dest: &v8[v7 + 1], src: &v8[v7], count: 4 * v9);
    v10 = &p_m_PriorOwners->m_pMemory[v7];
    if ( v10 != nullptr )
      *v10 = (vgui::TreeNode *)pPlayer;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102EA160
// Name: public: virtual void CWeaponCSBase::Drop(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CWeaponCSBase::Drop(CWeaponCSBase *this@<ecx>, int a2@<edi>, const Vector *vecVelocity)
{
  edict_t *m_pPev; // ecx
  edict_t *v5; // ecx
  int m_Value; // eax
  unsigned int v7; // ebx
  edict_t *v8; // ecx
  edict_t *v9; // ecx
  CBaseCombatCharacter *Owner; // eax
  IPhysicsObject *m_pPhysicsObject; // ecx
  void (__thiscall *AddVelocity)(IPhysicsObject *, const Vector *, const Vector *); // edx
  Vector angImp; // [esp+10h] [ebp-Ch] BYREF

  this->m_bRemoveable = true;
  if ( this->m_flPlaybackRate.m_Value != 0.0 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x37Cu);
    }
    this->m_flPlaybackRate.m_Value = 0.0;
  }
  CBaseEntity::StopFollowingEntity(this);
  CBaseEntity::SetMoveType(this, val: MOVETYPE_FLYGRAVITY, moveCollide: MOVECOLLIDE_DEFAULT);
  this->m_flGravity = 1.0;
  if ( this->m_iState.m_Value != 0 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v5 = this->m_Network.m_pPev;
      if ( v5 != nullptr )
        CBaseEdict::StateChanged(this: &v5->CBaseEdict, offset: 0x4A4u);
    }
    this->m_iState.m_Value = 0;
  }
  m_Value = this->m_fEffects.m_Value;
  v7 = m_Value & 0xFFFFFFDF;
  if ( m_Value != (m_Value & 0xFFFFFFDF) )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v8 = this->m_Network.m_pPev;
      if ( v8 != nullptr )
        CBaseEdict::StateChanged(this: &v8->CBaseEdict, offset: 0xA4u);
    }
    this->m_fEffects.m_Value = v7;
  }
  if ( this->m_Network.m_pPev != nullptr )
    this->m_Network.m_pPev->m_fStateFlags |= 0x80u;
  CBaseEntity::DispatchUpdateTransmitState(this);
  ((void (__thiscall *)(CWeaponCSBase *, int))this->FallInit)(a1: this, a2);
  CBaseEntity::SetGroundEntity(this, ground: nullptr);
  if ( this->m_bInReload.m_Value )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v9 = this->m_Network.m_pPev;
      if ( v9 != nullptr )
        CBaseEdict::StateChanged(this: &v9->CBaseEdict, offset: 0x4E5u);
    }
    this->m_bInReload.m_Value = false;
  }
  CBaseEntity::ThinkSet(this, func: nullptr, thinkTime: 0.0, szContext: nullptr);
  this->m_nextPrevOwnerTouchTime = gpGlobals->curtime + 1.5;
  Owner = CBaseCombatWeapon::GetOwner(this);
  this->m_prevOwner = (CCSPlayer *)__RTDynamicCast(
                                     inptr: Owner,
                                     VfDelta: 0,
                                     SrcType: &CBaseCombatCharacter `RTTI Type Descriptor',
                                     TargetType: &CCSPlayer `RTTI Type Descriptor',
                                     isReference: 0);
  if ( CCSGameRules::IsPlayingGunGameProgressive(this: (CCSGameRules *)g_pGameRules)
    || CCSGameRules::IsPlayingGunGameTRBomb(this: (CCSGameRules *)g_pGameRules) )
  {
    this->m_pfnTouch = this->GetCSWeaponID(this) == WEAPON_C4
                     ? (void (__thiscall *)(CBaseEntity *, CBaseEntity *)) __thiscall CWeaponCSBase::`vcall'{964,{flat}}
                     : nullptr;
  }
  else
  {
    this->m_pfnTouch = (void (__thiscall *)(CBaseEntity *, CBaseEntity *)) __thiscall CWeaponCSBase::`vcall'{964,{flat}};
  }
  m_pPhysicsObject = this->m_pPhysicsObject;
  if ( m_pPhysicsObject != nullptr )
  {
    AddVelocity = m_pPhysicsObject->AddVelocity;
    angImp.x = 200.0;
    angImp.y = 200.0;
    angImp.z = 200.0;
    AddVelocity(this: m_pPhysicsObject, a2: vecVelocity, a3: &angImp);
  }
  else
  {
    CBaseEntity::SetAbsVelocity(this, vecAbsVelocity: vecVelocity);
  }
  CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->curtime, szContext: nullptr);
  this->SetOwnerEntity(this, a2: nullptr);
  CBaseCombatWeapon::SetOwner(this, owner: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x102EA3C0
// Name: public: virtual void CWeaponCSBase::Materialize(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWeaponCSBase::Materialize(CWeaponCSBase *this)
{
  int m_Value; // eax
  unsigned int v3; // ebx
  edict_t *m_pPev; // ecx

  if ( (this->m_fEffects.m_Value & 0x20) != 0 )
  {
    m_Value = this->m_fEffects.m_Value;
    v3 = m_Value & 0xFFFFFFDF;
    if ( m_Value != (m_Value & 0xFFFFFFDF) )
    {
      if ( this->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&this->m_Network + 76) |= 1u;
      }
      else
      {
        m_pPev = this->m_Network.m_pPev;
        if ( m_pPev != nullptr )
          CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0xA4u);
      }
      this->m_fEffects.m_Value = v3;
    }
    if ( this->m_Network.m_pPev != nullptr )
      this->m_Network.m_pPev->m_fStateFlags |= 0x80u;
    CBaseEntity::DispatchUpdateTransmitState(this);
    CBaseAnimating::DoMuzzleFlash(this);
  }
  CCollisionProperty::SetSolidFlags(this: &this->m_Collision, flags: this->m_Collision.m_usSolidFlags.m_Value | 8);
  CBaseEntity::ThinkSet(this, func: nullptr, thinkTime: 0.0, szContext: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x102EA460
// Name: public: virtual void CWeaponCSBase::OnPickedUp(class CBaseCombatCharacter __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWeaponCSBase::OnPickedUp(CWeaponCSBase *this, CBaseCombatCharacter *pNewOwner)
{
  unsigned int v3; // esi
  edict_t *m_pPev; // ecx
  CBaseCombatCharacter *v5; // esi
  int v6; // edi
  CBasePlayer *v7; // eax
  CBasePlayer *v8; // esi
  signed int v9; // eax
  edict_t *v10; // ecx
  CRecipientFilter filter; // [esp+14h] [ebp-20h] BYREF

  v3 = this->m_fEffects.m_Value & 0xFFFFFEFF;
  if ( this->m_fEffects.m_Value != v3 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0xA4u);
    }
    this->m_fEffects.m_Value = v3;
  }
  v5 = pNewOwner;
  if ( pNewOwner->IsPlayer(this: pNewOwner) && pNewOwner->IsAlive(this: pNewOwner) )
  {
    COutputEvent::FireOutput(this: &this->m_OnPlayerPickup, pActivator: pNewOwner, pCaller: this, fDelay: 0.0);
    CRecipientFilter::CRecipientFilter(this: &filter);
    v6 = 0;
    if ( gpGlobals->maxClients > 0 )
    {
      do
      {
        v7 = UTIL_PlayerByIndex(playerIndex: v6);
        v8 = v7;
        if ( v7 != nullptr && !v7->IsAlive(this: v7) && v8->GetObserverMode(this: v8) == 4 )
          CRecipientFilter::AddRecipient(this: &filter, player: v8);
        ++v6;
      }
      while ( v6 < gpGlobals->maxClients );
      v5 = pNewOwner;
    }
    if ( ConCommandBase::GetFlags(this: (ConCommandBase *)&filter) != 0 )
    {
      v9 = (signed int)v5->m_Network.m_pPev;
      if ( v9 != 0 )
        v9 = (signed int)(v9 - (unsigned int)gpGlobals->pEdicts) >> 4;
      CBaseEntity::EmitSound(
        &filter,
        iEntIndex: v9,
        soundname: "Player.PickupWeapon",
        pOrigin: nullptr,
        soundtime: 0.0,
        duration: nullptr);
    }
    this->m_bFiredOutOfAmmoEvent = false;
    if ( this->m_iName.m_Value.pszValue != nullptr )
    {
      if ( this->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&this->m_Network + 76) |= 1u;
      }
      else
      {
        v10 = this->m_Network.m_pPev;
        if ( v10 != nullptr )
          CBaseEdict::StateChanged(this: &v10->CBaseEdict, offset: 0xCCu);
      }
      this->m_iName.m_Value.pszValue = nullptr;
    }
    CGlobalEntityList::UpdateName(this: &gEntList, pEnt: this);
    CRecipientFilter::~CRecipientFilter(this: &filter);
  }
  this->m_bRemoveable = false;
}

//------------------------------------------------------------------------------
// Address: 0x104121F0
// Name: DT_WeaponCSBase::_dynamic_initializer_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
int DT_WeaponCSBase::_dynamic_initializer_for__g_SendTable__()
{
  SendTable::SendTable(this: &DT_WeaponCSBase::g_SendTable);
  return atexit(func: DT_WeaponCSBase::_dynamic_atexit_destructor_for__g_SendTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10412210
// Name: DT_WeaponCSBase::_dynamic_initializer_for__g_SendTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_WeaponCSBase::_dynamic_initializer_for__g_SendTableInit__()
{
  int result; // eax

  result = ServerClassInit<DT_WeaponCSBase::ignored>();
  DT_WeaponCSBase::g_SendTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10412240
// Name: CWeaponCSBase_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CWeaponCSBase_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CWeaponCSBase>();
  CWeaponCSBase_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104208D0
// Name: DT_WeaponCSBase::_dynamic_atexit_destructor_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_WeaponCSBase::_dynamic_atexit_destructor_for__g_SendTable__()
{
  CAI_BaseNPC::OnSetSchedule(this: (vgui::Panel *)&DT_WeaponCSBase::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x102E81E0
// Name: __CreateCServerGameTagsIServerGameTags_interface_53
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CServerGameTags *__cdecl _CreateCServerGameTagsIServerGameTags_interface_53()
{
  return &_g_CServerGameTags_singleton_53;
}

//------------------------------------------------------------------------------
// Address: 0x10412250
// Name: _dynamic_initializer_for____g_CreateCServerGameTagsIServerGameTags_reg___53
// Source: linker_block_proximity
//------------------------------------------------------------------------------
InterfaceReg *dynamic_initializer_for____g_CreateCServerGameTagsIServerGameTags_reg___53()
{
  return InterfaceReg::InterfaceReg(
           this: &_g_CreateCServerGameTagsIServerGameTags_reg_53,
           fn: (void *(__cdecl *)())_CreateCServerGameTagsIServerGameTags_interface_53,
           pName: "ServerGameTags001");
}

//------------------------------------------------------------------------------
// Address: 0x10412270
// Name: _dynamic_initializer_for__g_CWeaponCSBaseGun_ClassReg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ServerClass *dynamic_initializer_for__g_CWeaponCSBaseGun_ClassReg__()
{
  return ServerClass::ServerClass(
           this: &g_CWeaponCSBaseGun_ClassReg,
           pNetworkName: "CWeaponCSBaseGun",
           pTable: &DT_WeaponCSBaseGun::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x104208E0
// Name: _ServerClassInit_DT_WeaponCSBase::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ServerClassInit_DT_WeaponCSBase::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__()
{
  SendProp *v0; // esi
  int i; // edi

  v0 = (SendProp *)&_S2_272;
  for ( i = 6; i >= 0; --i )
    SendProp::~SendProp(this: --v0);
}

//------------------------------------------------------------------------------
// Address: 0x10420900
// Name: _DataMapInit_CWeaponCSBase__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CWeaponCSBase__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_494);
}

} // namespace server
