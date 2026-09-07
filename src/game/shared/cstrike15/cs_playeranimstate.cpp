// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/shared/cstrike15/cs_playeranimstate.cpp
// Functions: 72
// ============================================================

#include "game\shared\cstrike15\cs_playeranimstate.h"

//------------------------------------------------------------------------------
// Address: 0x10009CD0
// Name: public: virtual void CBasePlayerAnimState::Release(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBasePlayerAnimState::Release(CBasePlayerAnimState *this)
{
  char *v1; // ecx

  v1 = (char *)this - 152;
  if ( v1 != nullptr )
    (**(void (__thiscall ***)(char *, int))v1)(a1: v1, a2: 1);
}

//------------------------------------------------------------------------------
// Address: 0x10009DF0
// Name: public: virtual class QAngle const __near & CBasePlayerAnimState::GetRenderAngles(void)
// Source: json
//------------------------------------------------------------------------------
const QAngle *__thiscall CBasePlayerAnimState::GetRenderAngles(CBasePlayerAnimState *this)
{
  return (const QAngle *)((char *)this - 92);
}

//------------------------------------------------------------------------------
// Address: 0x1000A870
// Name: public: virtual void CBasePlayerAnimState::Update(float,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBasePlayerAnimState::Update(CBasePlayerAnimState *this, float eyeYaw, float eyePitch)
{
  CBasePlayerAnimState *v3; // ebx
  CBasePlayerAnimState *v4; // esi
  C_BaseAnimating *m_flEyeYaw_low; // edi
  CStudioHdr *m_pStudioHdr; // edi
  int m_nValue; // edi
  C_CSPlayer *LocalPlayer; // edi
  C_BaseEntity *v9; // ebx

  v3 = this;
  v4 = (CBasePlayerAnimState *)((char *)this - 152);
  (*(void (__thiscall **)(char *))(*((_DWORD *)this - 38) + 4))(a1: (char *)this - 152);
  if ( v4->ShouldUpdateAnimState(this: v4) )
  {
    m_flEyeYaw_low = (C_BaseAnimating *)LODWORD(v3[-1].m_flEyeYaw);
    if ( m_flEyeYaw_low->m_pStudioHdr == nullptr
      && m_flEyeYaw_low->GetModel(this: &m_flEyeYaw_low->IClientRenderable) != nullptr )
    {
      C_BaseAnimating::LockStudioHdr(this: m_flEyeYaw_low);
    }
    m_pStudioHdr = m_flEyeYaw_low->m_pStudioHdr;
    if ( m_pStudioHdr == nullptr || m_pStudioHdr->m_pStudioHdr == nullptr )
      m_pStudioHdr = nullptr;
    v3[-1].m_flEyePitch = AngleNormalize(angle: eyeYaw);
    v3[-1].m_flGoalFeetYaw = AngleNormalize(angle: eyePitch);
    v4->ComputeSequences(this: v4, a2: m_pStudioHdr);
    v4->ComputePoseParam_BodyPitch(this: v4, a2: m_pStudioHdr);
    v4->ComputePoseParam_BodyYaw(this: v4);
    v4->ComputePoseParam_MoveYaw(this: v4, a2: m_pStudioHdr);
    if ( v4->m_AnimConfig.m_LegAnimType >= (unsigned int)LEGANIM_GOLDSRC )
    {
      eyePitch = v4->CalcMovementPlaybackRate(this: v4, a2: (bool *)&eyeYaw + 3);
      if ( HIBYTE(eyeYaw) != 0 )
        v4->m_pOuter->m_flPlaybackRate = eyePitch;
      else
        v4->m_pOuter->m_flPlaybackRate = 1.0;
    }
    if ( cl_showanimstate.m_pParent != nullptr )
      m_nValue = cl_showanimstate.m_pParent->m_Value.m_nValue;
    else
      m_nValue = 0;
    if ( m_nValue == (*(int (__thiscall **)(int))(*(_DWORD *)(LODWORD(v3[-1].m_flEyeYaw) + 8) + 40))(a1: LODWORD(v3[-1].m_flEyeYaw) + 8) )
    {
      CBasePlayerAnimState::AnimStateLog(
        this: v4,
        pMsg: "----------------- frame %d -----------------\n",
        *(_DWORD *)(gpGlobals.m_Index + 4));
      v4->DebugShowAnimState(this: v4, a2: 5);
      CBasePlayerAnimState::AnimStateLog(this: v4, pMsg: "--------------------------------------------\n\n");
    }
    else if ( cl_showanimstate.m_pParent != nullptr && cl_showanimstate.m_pParent->m_Value.m_nValue == -2 )
    {
      LocalPlayer = (C_CSPlayer *)C_BasePlayer::GetLocalPlayer(nSlot: -1);
      if ( LocalPlayer != nullptr
        && (LocalPlayer->GetObserverMode(this: LocalPlayer) == 4 || LocalPlayer->GetObserverMode(this: LocalPlayer) == 5) )
      {
        v9 = LocalPlayer->GetObserverTarget(this: LocalPlayer);
        if ( v9 != nullptr && v9->IsPlayer(this: v9) )
          LocalPlayer = ToBasePlayer(pEntity: v9);
        v3 = this;
      }
      if ( (C_CSPlayer *)LODWORD(v3[-1].m_flEyeYaw) == LocalPlayer )
        CBasePlayerAnimState::DebugShowAnimStateFull(this: v4, iStartLine: 6);
    }
  }
  else
  {
    (*(void (__thiscall **)(int))(*(_DWORD *)((char *)v3
                                            + *(_DWORD *)(LODWORD(v3[-1].m_AnimConfig.m_flMaxBodyYawDegrees) + 4)
                                            - 148)
                                + 8))(a1: (int)v3 + *(_DWORD *)(LODWORD(v3[-1].m_AnimConfig.m_flMaxBodyYawDegrees) + 4)
                                                  - 148);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101C83E0
// Name: protected: int CCSPlayerAnimState::CalcGrenadePrimeSequence(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CCSPlayerAnimState::CalcGrenadePrimeSequence(CCSPlayerAnimState *this)
{
  Activity m_eCurrentMainSequenceActivity; // eax
  __int32 v3; // eax
  __int32 v4; // eax

  m_eCurrentMainSequenceActivity = this->m_eCurrentMainSequenceActivity;
  if ( m_eCurrentMainSequenceActivity > ACT_PLAYER_CROUCH_FIRE )
  {
    v3 = m_eCurrentMainSequenceActivity - 484;
    if ( v3 != 0 )
    {
      v4 = v3 - 1;
      if ( v4 != 0 )
      {
        if ( v4 == 1 )
          return this->CalcSequenceIndex(this, a2: "%s_shoot_gren1", "run");
        else
          return this->CalcSequenceIndex(this, a2: "%s_shoot_gren1", "idle");
      }
      else
      {
        return this->CalcSequenceIndex(this, a2: "%s_shoot_gren1", "walk");
      }
    }
    else
    {
      return this->CalcSequenceIndex(this, a2: "%s_shoot_gren1", "crouch_walk");
    }
  }
  else
  {
    if ( m_eCurrentMainSequenceActivity != ACT_PLAYER_CROUCH_FIRE )
    {
      switch ( m_eCurrentMainSequenceActivity )
      {
        case ACT_WALK:
          return this->CalcSequenceIndex(this, a2: "%s_shoot_gren1", "walk");
        case ACT_RUN:
          return this->CalcSequenceIndex(this, a2: "%s_shoot_gren1", "run");
        case ACT_RUN_CROUCH:
          return this->CalcSequenceIndex(this, a2: "%s_shoot_gren1", "crouch_walk");
        case ACT_CROUCHIDLE:
          return this->CalcSequenceIndex(this, a2: "%s_shoot_gren1", "crouch_idle");
        default:
          return this->CalcSequenceIndex(this, a2: "%s_shoot_gren1", "idle");
      }
    }
    return this->CalcSequenceIndex(this, a2: "%s_shoot_gren1", "crouch_idle");
  }
}

//------------------------------------------------------------------------------
// Address: 0x101C84C0
// Name: protected: int CCSPlayerAnimState::CalcGrenadeThrowSequence(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CCSPlayerAnimState::CalcGrenadeThrowSequence(CCSPlayerAnimState *this)
{
  Activity m_eCurrentMainSequenceActivity; // eax
  __int32 v3; // eax
  __int32 v4; // eax

  m_eCurrentMainSequenceActivity = this->m_eCurrentMainSequenceActivity;
  if ( m_eCurrentMainSequenceActivity > ACT_PLAYER_CROUCH_FIRE )
  {
    v3 = m_eCurrentMainSequenceActivity - 484;
    if ( v3 != 0 )
    {
      v4 = v3 - 1;
      if ( v4 != 0 )
      {
        if ( v4 == 1 )
          return this->CalcSequenceIndex(this, a2: "%s_shoot_gren2", "run");
        else
          return this->CalcSequenceIndex(this, a2: "%s_shoot_gren2", "idle");
      }
      else
      {
        return this->CalcSequenceIndex(this, a2: "%s_shoot_gren2", "walk");
      }
    }
    else
    {
      return this->CalcSequenceIndex(this, a2: "%s_shoot_gren2", "crouch_walk");
    }
  }
  else
  {
    if ( m_eCurrentMainSequenceActivity != ACT_PLAYER_CROUCH_FIRE )
    {
      switch ( m_eCurrentMainSequenceActivity )
      {
        case ACT_WALK:
          return this->CalcSequenceIndex(this, a2: "%s_shoot_gren2", "walk");
        case ACT_RUN:
          return this->CalcSequenceIndex(this, a2: "%s_shoot_gren2", "run");
        case ACT_RUN_CROUCH:
          return this->CalcSequenceIndex(this, a2: "%s_shoot_gren2", "crouch_walk");
        case ACT_CROUCHIDLE:
          return this->CalcSequenceIndex(this, a2: "%s_shoot_gren2", "crouch_idle");
        default:
          return this->CalcSequenceIndex(this, a2: "%s_shoot_gren2", "idle");
      }
    }
    return this->CalcSequenceIndex(this, a2: "%s_shoot_gren2", "crouch_idle");
  }
}

//------------------------------------------------------------------------------
// Address: 0x101C85A0
// Name: protected: int CCSPlayerAnimState::CalcFireLayerSequence(enum PlayerAnimEvent_t)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CCSPlayerAnimState::CalcFireLayerSequence(CCSPlayerAnimState *this, PlayerAnimEvent_t event)
{
  C_WeaponCSBase *v3; // ebx
  C_WeaponCSBase *v5; // eax
  const CCSWeaponInfo *CSWpnData; // eax
  char *m_szAnimExtension; // edi
  Activity m_eCurrentMainSequenceActivity; // eax
  __int32 v9; // eax
  __int32 v10; // eax
  char tempsuffix[32]; // [esp+8h] [ebp-20h] BYREF

  v3 = this->m_pHelpers->CSAnim_GetActiveWeapon(this: this->m_pHelpers);
  if ( v3 == nullptr )
    return -1;
  v5 = this->m_pHelpers->CSAnim_GetActiveWeapon(this: this->m_pHelpers);
  if ( v5 == nullptr )
    return -1;
  CSWpnData = C_WeaponCSBase::GetCSWpnData(this: v5);
  m_szAnimExtension = CSWpnData->m_szAnimExtension;
  if ( CSWpnData == (const CCSWeaponInfo *)-1929 )
    return -1;
  if ( v3->GetCSWeaponID(this: v3) == WEAPON_ELITE )
  {
    V_snprintf(
      pDest: tempsuffix,
      maxLen: 0x20u,
      pFormat: "%s_%c",
      m_szAnimExtension,
      event != PLAYERANIMEVENT_FIRE_GUN_PRIMARY ? 108 : 114);
    m_szAnimExtension = tempsuffix;
  }
  if ( event == PLAYERANIMEVENT_THROW_GRENADE
    || C_WeaponCSBase::GetCSWpnData(this: v3)->m_WeaponType == WEAPONTYPE_GRENADE )
  {
    return -1;
  }
  m_eCurrentMainSequenceActivity = this->m_eCurrentMainSequenceActivity;
  if ( m_eCurrentMainSequenceActivity > ACT_PLAYER_CROUCH_FIRE )
  {
    v9 = m_eCurrentMainSequenceActivity - 484;
    if ( v9 != 0 )
    {
      v10 = v9 - 1;
      if ( v10 != 0 )
      {
        if ( v10 == 1 )
          return this->CalcSequenceIndex(this, a2: "%s%s", "run_shoot_", m_szAnimExtension);
        else
          return this->CalcSequenceIndex(this, a2: "%s%s", "idle_shoot_", m_szAnimExtension);
      }
      else
      {
        return this->CalcSequenceIndex(this, a2: "%s%s", "walk_shoot_", m_szAnimExtension);
      }
    }
    else
    {
      return this->CalcSequenceIndex(this, a2: "%s%s", "crouch_walk_shoot_", m_szAnimExtension);
    }
  }
  else
  {
    if ( m_eCurrentMainSequenceActivity != ACT_PLAYER_CROUCH_FIRE )
    {
      switch ( m_eCurrentMainSequenceActivity )
      {
        case ACT_WALK:
          return this->CalcSequenceIndex(this, a2: "%s%s", "walk_shoot_", m_szAnimExtension);
        case ACT_RUN:
          return this->CalcSequenceIndex(this, a2: "%s%s", "run_shoot_", m_szAnimExtension);
        case ACT_RUN_CROUCH:
          return this->CalcSequenceIndex(this, a2: "%s%s", "crouch_walk_shoot_", m_szAnimExtension);
        case ACT_CROUCHIDLE:
          return this->CalcSequenceIndex(this, a2: "%s%s", "crouch_idle_shoot_", m_szAnimExtension);
        default:
          return this->CalcSequenceIndex(this, a2: "%s%s", "idle_shoot_", m_szAnimExtension);
      }
    }
    return this->CalcSequenceIndex(this, a2: "%s%s", "crouch_idle_shoot_", m_szAnimExtension);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101C8760
// Name: public: virtual bool CCSPlayerAnimState::CanThePlayerMove(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CCSPlayerAnimState::CanThePlayerMove(CCSPlayerAnimState *this)
{
  return this->m_pHelpers->CSAnim_CanMove(this: this->m_pHelpers);
}

//------------------------------------------------------------------------------
// Address: 0x101C8770
// Name: public: virtual void CCSPlayerAnimState::ClearAnimationLayers(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSPlayerAnimState::ClearAnimationLayers(CCSPlayerAnimState *this)
{
  C_BaseAnimatingOverlay *m_pOuter; // ecx
  int i; // esi
  C_AnimationLayer *AnimOverlay; // eax

  m_pOuter = this->m_pOuter;
  if ( m_pOuter != nullptr )
  {
    C_BaseAnimatingOverlay::SetNumAnimOverlays(this: m_pOuter, num: 9);
    for ( i = 0; i < C_BaseAnimatingOverlay::GetNumAnimOverlays(this: this->m_pOuter); ++i )
    {
      AnimOverlay = C_BaseAnimatingOverlay::GetAnimOverlay(this: this->m_pOuter, i);
      C_AnimationLayer::SetOrder(this: AnimOverlay, order: 15);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101C87C0
// Name: protected: int CCSPlayerAnimState::CalcReloadLayerSequence(enum PlayerAnimEvent_t)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CCSPlayerAnimState::CalcReloadLayerSequence(CCSPlayerAnimState *this, PlayerAnimEvent_t event)
{
  int result; // eax
  C_WeaponCSBase *v4; // eax
  const CCSWeaponInfo *CSWpnData; // eax
  const char *m_szAnimExtension; // ebx
  Activity m_eCurrentMainSequenceActivity; // eax
  const char *v8; // ecx
  __int32 v9; // eax
  __int32 v10; // eax
  const char *v11; // edi
  char szName[512]; // [esp+4h] [ebp-204h] BYREF
  C_WeaponCSBase *pWeapon; // [esp+204h] [ebp-4h]

  if ( this->m_delayedFire != PLAYERANIMEVENT_COUNT )
    return -1;
  v4 = this->m_pHelpers->CSAnim_GetActiveWeapon(this: this->m_pHelpers);
  if ( v4 == nullptr )
    return -1;
  CSWpnData = C_WeaponCSBase::GetCSWpnData(this: v4);
  m_szAnimExtension = CSWpnData->m_szAnimExtension;
  if ( CSWpnData == (const CCSWeaponInfo *)-1929 )
    return -1;
  pWeapon = this->m_pHelpers->CSAnim_GetActiveWeapon(this: this->m_pHelpers);
  if ( pWeapon == nullptr )
    return -1;
  m_eCurrentMainSequenceActivity = this->m_eCurrentMainSequenceActivity;
  if ( m_eCurrentMainSequenceActivity > ACT_PLAYER_CROUCH_FIRE )
  {
    v9 = m_eCurrentMainSequenceActivity - 484;
    if ( v9 != 0 )
    {
      v10 = v9 - 1;
      if ( v10 != 0 )
      {
        if ( v10 == 1 )
$LN32_4:
          v8 = "run";
        else
LABEL_14:
          v8 = "idle";
      }
      else
      {
$LN33_2:
        v8 = "walk";
      }
    }
    else
    {
$LN12_18:
      v8 = "crouch_walk";
    }
  }
  else
  {
    if ( m_eCurrentMainSequenceActivity != ACT_PLAYER_CROUCH_FIRE )
    {
      switch ( m_eCurrentMainSequenceActivity )
      {
        case ACT_WALK:
          goto $LN33_2;
        case ACT_RUN:
          goto $LN32_4;
        case ACT_RUN_CROUCH:
          goto $LN12_18;
        case ACT_CROUCHIDLE:
          break;
        default:
          goto LABEL_14;
      }
    }
    v8 = "crouch_idle";
  }
  v11 = prType;
  switch ( event )
  {
    case PLAYERANIMEVENT_RELOAD_START:
      v11 = "_start";
      break;
    case PLAYERANIMEVENT_RELOAD_LOOP:
      v11 = "_loop";
      break;
    case PLAYERANIMEVENT_RELOAD_END:
      v11 = "_end";
      break;
    default:
      break;
  }
  V_snprintf(pDest: szName, maxLen: 0x200u, pFormat: "%s_reload_%s%s", v8, m_szAnimExtension, v11);
  result = C_BaseAnimating::LookupSequence(this: this->m_pOuter, label: szName);
  if ( result == -1 )
  {
    V_snprintf(pDest: szName, maxLen: 0x200u, pFormat: "reload_%s%s", m_szAnimExtension, v11);
    result = C_BaseAnimating::LookupSequence(this: this->m_pOuter, label: szName);
    if ( result == -1 )
    {
      if ( C_WeaponCSBase::GetCSWpnData(this: pWeapon)->m_WeaponType != WEAPONTYPE_PISTOL
        || (V_snprintf(pDest: szName, maxLen: 0x200u, pFormat: "reload_pistol"),
            (result = C_BaseAnimating::LookupSequence(this: this->m_pOuter, label: szName)) == -1) )
      {
        result = this->CalcSequenceIndex(this, a2: "reload_m4");
        if ( result <= 0 )
          return -1;
      }
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101C89A0
// Name: protected: bool CCSPlayerAnimState::IsOuterGrenadePrimed(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CCSPlayerAnimState::IsOuterGrenadePrimed(CCSPlayerAnimState *this)
{
  C_BaseCombatCharacter *v1; // eax
  C_BaseCombatWeapon *v2; // eax
  _BYTE *v3; // eax

  v1 = this->m_pOuter->MyCombatCharacterPointer(this: this->m_pOuter);
  if ( v1 == nullptr )
    return false;
  v2 = v1->GetActiveWeapon(this: v1);
  v3 = __RTDynamicCast(
         inptr: v2,
         VfDelta: 0,
         SrcType: &C_BaseCombatWeapon `RTTI Type Descriptor',
         TargetType: &C_BaseCSGrenade `RTTI Type Descriptor',
         isReference: 0);
  return v3 != nullptr && v3[3505] != 0;
}

//------------------------------------------------------------------------------
// Address: 0x101C89F0
// Name: public: virtual int CCSPlayerAnimState::CalcAimLayerSequence(float __near *,float __near *,bool)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CCSPlayerAnimState::CalcAimLayerSequence(
        CCSPlayerAnimState *this,
        float *flCycle,
        float *flAimSequenceWeight,
        bool bForceIdle)
{
  C_WeaponCSBase *v5; // eax
  char *m_szAnimExtension; // eax
  Activity m_eCurrentMainSequenceActivity; // ecx
  __int32 v9; // ecx
  __int32 v10; // ecx

  v5 = this->m_pHelpers->CSAnim_GetActiveWeapon(this: this->m_pHelpers);
  if ( v5 == nullptr )
    return 0;
  m_szAnimExtension = C_WeaponCSBase::GetCSWpnData(this: v5)->m_szAnimExtension;
  if ( m_szAnimExtension == nullptr )
    return 0;
  m_eCurrentMainSequenceActivity = this->m_eCurrentMainSequenceActivity;
  if ( bForceIdle )
  {
    if ( m_eCurrentMainSequenceActivity == ACT_RUN_CROUCH || m_eCurrentMainSequenceActivity == ACT_CROUCHIDLE )
      return this->CalcSequenceIndex(this, a2: "%s%s", "crouch_idle_upper_", m_szAnimExtension);
    return this->CalcSequenceIndex(this, a2: "%s%s", "idle_upper_", m_szAnimExtension);
  }
  if ( m_eCurrentMainSequenceActivity <= ACT_JUMP )
  {
    if ( m_eCurrentMainSequenceActivity != ACT_JUMP )
    {
      v9 = m_eCurrentMainSequenceActivity - 6;
      if ( v9 != 0 )
      {
        v10 = v9 - 4;
        if ( v10 != 0 )
        {
          if ( v10 == 2 )
            return this->CalcSequenceIndex(this, a2: "%s%s", "crouch_walk_upper_", m_szAnimExtension);
          return this->CalcSequenceIndex(this, a2: "%s%s", "idle_upper_", m_szAnimExtension);
        }
        return this->CalcSequenceIndex(this, a2: "%s%s", "run_upper_", m_szAnimExtension);
      }
    }
    return this->CalcSequenceIndex(this, a2: "%s%s", "walk_upper_", m_szAnimExtension);
  }
  if ( m_eCurrentMainSequenceActivity <= ACT_CROUCHIDLE )
  {
    if ( m_eCurrentMainSequenceActivity == ACT_CROUCHIDLE )
      return this->CalcSequenceIndex(this, a2: "%s%s", "crouch_idle_upper_", m_szAnimExtension);
    if ( m_eCurrentMainSequenceActivity != ACT_LEAP )
      return this->CalcSequenceIndex(this, a2: "%s%s", "idle_upper_", m_szAnimExtension);
    return this->CalcSequenceIndex(this, a2: "%s%s", "run_upper_", m_szAnimExtension);
  }
  if ( (unsigned int)(m_eCurrentMainSequenceActivity - 487) <= 1 )
    return this->CalcSequenceIndex(this, a2: "%s%s", "walk_upper_", m_szAnimExtension);
  return this->CalcSequenceIndex(this, a2: "%s%s", "idle_upper_", m_szAnimExtension);
}

//------------------------------------------------------------------------------
// Address: 0x101C8AA0
// Name: public: virtual float CCSPlayerAnimState::GetCurrentMaxGroundSpeed(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CCSPlayerAnimState::GetCurrentMaxGroundSpeed(CCSPlayerAnimState *this)
{
  int SequenceActivity; // eax
  C_BaseCombatWeapon *v4; // eax
  void *v5; // eax

  SequenceActivity = C_BaseAnimating::GetSequenceActivity(this: this->m_pOuter, iSequence: this->m_pOuter->m_nSequence);
  switch ( SequenceActivity )
  {
    case 6:
    case 29:
    case 1:
    case 30:
      return 100.0;
    case 10:
    case 31:
      if ( this->m_pPlayer != nullptr
        && (v4 = this->m_pPlayer->GetActiveWeapon(this: this->m_pPlayer)) != nullptr
        && (v5 = __RTDynamicCast(
                   inptr: v4,
                   VfDelta: 0,
                   SrcType: &C_BaseCombatWeapon `RTTI Type Descriptor',
                   TargetType: &C_WeaponCSBase `RTTI Type Descriptor',
                   isReference: 0)) != nullptr )
      {
        return (*(float (__thiscall **)(void *))(*(_DWORD *)v5 + 1488))(a1: v5);
      }
      else
      {
        return 250.0;
      }
    case 12:
      return 85.0;
    default:
      return 0.0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101C8B40
// Name: protected: bool CCSPlayerAnimState::HandleJumping(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CCSPlayerAnimState::HandleJumping(CCSPlayerAnimState *this)
{
  if ( this->_bytes_9c[0] != 0 )
  {
    if ( this->m_bFirstJumpFrame )
    {
      this->m_bFirstJumpFrame = false;
      CBasePlayerAnimState::RestartMainSequence(this);
    }
    if ( (float)(*(float *)(gpGlobals.m_Index + 12) - this->m_flJumpStartTime) > 0.2
      && (this->m_pOuter->m_fFlags & 1) != 0 )
    {
      this->m_flJumpLandTime = *(float *)(gpGlobals.m_Index + 12);
      this->_bytes_9c[0] = 0;
      CBasePlayerAnimState::RestartMainSequence(this);
    }
  }
  return this->_bytes_9c[0];
}

//------------------------------------------------------------------------------
// Address: 0x101C8BB0
// Name: public: virtual enum Activity CCSPlayerAnimState::CalcMainActivity(void)
// Source: json
//------------------------------------------------------------------------------
Activity __thiscall CCSPlayerAnimState::CalcMainActivity(CCSPlayerAnimState *this)
{
  Activity result; // eax
  float flOuterSpeed; // [esp+4h] [ebp-4h]
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  flOuterSpeed = CBasePlayerAnimState::GetOuterXYSpeed(this, a2: (int)&savedregs);
  if ( CCSPlayerAnimState::HandleJumping(this) )
  {
    if ( flOuterSpeed <= 0.5 )
    {
      return ACT_HOP;
    }
    else if ( flOuterSpeed <= 175.0 )
    {
      return ACT_JUMP;
    }
    else
    {
      return ACT_LEAP;
    }
  }
  else if ( (this->m_pOuter->m_fFlags & 4) != 0
         || post_jump_crouch.m_pParent->m_Value.m_fValue > (float)(*(float *)(gpGlobals.m_Index + 12)
                                                                 - this->m_flJumpLandTime) )
  {
    result = ACT_RUN_CROUCH;
    if ( flOuterSpeed <= 0.5 )
      return ACT_CROUCHIDLE;
  }
  else if ( flOuterSpeed <= 0.5 )
  {
    return ACT_IDLE;
  }
  else if ( flOuterSpeed <= 175.0 )
  {
    return ACT_WALK;
  }
  else
  {
    return ACT_RUN;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101C8C80
// Name: public: virtual void CCSPlayerAnimState::DebugShowAnimState(int)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CCSPlayerAnimState::DebugShowAnimState(
        CCSPlayerAnimState *this@<ecx>,
        CStudioHdr *m_pStudioHdr@<edi>,
        int iStartLine)
{
  C_BaseAnimatingOverlay *m_pOuter; // edi
  char *SequenceName; // eax
  C_BaseAnimatingOverlay *v6; // edi
  char *v7; // eax
  int savedregs; // [esp+14h] [ebp+0h] BYREF

  if ( this->m_bFiring )
  {
    m_pOuter = this->m_pOuter;
    if ( m_pOuter->m_pStudioHdr == nullptr && m_pOuter->GetModel(this: &m_pOuter->IClientRenderable) != nullptr )
      C_BaseAnimating::LockStudioHdr(this: m_pOuter);
    m_pStudioHdr = m_pOuter->m_pStudioHdr;
    if ( m_pStudioHdr == nullptr || m_pStudioHdr->m_pStudioHdr == nullptr )
      m_pStudioHdr = nullptr;
    SequenceName = GetSequenceName(pstudiohdr: m_pStudioHdr, iSequence: this->m_iFireSequence);
  }
  else
  {
    SequenceName = "[not firing]";
  }
  engine->Con_NPrintf(this: engine, a2: iStartLine, a3: "fire  : %s, cycle: %.2f\n", SequenceName, this->m_flFireCycle);
  if ( this->m_bReloading )
  {
    v6 = this->m_pOuter;
    if ( v6->m_pStudioHdr == nullptr && v6->GetModel(this: &v6->IClientRenderable) != nullptr )
      C_BaseAnimating::LockStudioHdr(this: v6);
    m_pStudioHdr = v6->m_pStudioHdr;
    if ( m_pStudioHdr == nullptr || m_pStudioHdr->m_pStudioHdr == nullptr )
      m_pStudioHdr = nullptr;
    v7 = GetSequenceName(pstudiohdr: m_pStudioHdr, iSequence: this->m_iReloadSequence);
  }
  else
  {
    v7 = "[not reloading]";
  }
  engine->Con_NPrintf(this: engine, a2: iStartLine + 1, a3: "reload: %s, cycle: %.2f\n", v7, this->m_flReloadCycle);
  CBasePlayerAnimState::DebugShowAnimState(
    this,
    a2: COERCE_FLOAT(&savedregs),
    a3: (int)m_pStudioHdr,
    a4: (int)this,
    iStartLine: iStartLine + 2);
}

//------------------------------------------------------------------------------
// Address: 0x101C8DA0
// Name: public: virtual enum Activity CCSHostageAnimState::CalcMainActivity(void)
// Source: json
//------------------------------------------------------------------------------
Activity __thiscall CCSHostageAnimState::CalcMainActivity(CCSHostageAnimState *this)
{
  Activity result; // eax
  unsigned __int8 *v3; // ecx
  CEntInfo *v4; // eax
  IHandleEntity *m_pEntity; // esi
  IHandleEntity *v6; // eax
  float flOuterSpeed; // [esp+4h] [ebp-4h]
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  flOuterSpeed = CBasePlayerAnimState::GetOuterXYSpeed(this, a2: (int)&savedregs);
  if ( CCSPlayerAnimState::HandleJumping(this) )
    return ACT_HOP;
  v3 = this->m_pOuter[1].m_pIntermediateData[46];
  if ( v3 != (unsigned __int8 *)-1
    && (v4 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)v3],
        g_pEntityList->m_EntPtrArray[(unsigned __int16)v3].m_SerialNumber == (unsigned int)v3 >> 16)
    && (m_pEntity = v4->m_pEntity, v4->m_pEntity != nullptr)
    && m_pEntity->__vftable[48].GetRefEHandle(this: m_pEntity) != nullptr )
  {
    v6 = m_pEntity;
  }
  else
  {
    v6 = nullptr;
  }
  result = v6 != nullptr ? ACT_IDLE : ACT_BUSY_QUEUE;
  if ( (this->m_pOuter->m_fFlags & 2) != 0 )
  {
    if ( flOuterSpeed <= 0.5 )
      return ACT_COVER_LOW;
    else
      return ACT_RUN_CROUCH;
  }
  else if ( flOuterSpeed > 0.5 )
  {
    result = ACT_RUN;
    if ( flOuterSpeed <= 175.0 )
      return ACT_WALK;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101C8E70
// Name: public: virtual void CCSPlayerAnimState::ClearAnimationState(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSPlayerAnimState::ClearAnimationState(CCSPlayerAnimState *this)
{
  int v1; // eax

  *((_BYTE *)this - 296) = 0;
  *((_BYTE *)this - 268) = 0;
  *((_BYTE *)this - 283) = 0;
  *((_DWORD *)this - 68) = 0;
  *((_WORD *)this - 126) = 0;
  v1 = *((_DWORD *)this - 59);
  if ( v1 != 0 )
    *((_DWORD *)this - 60) = *(_DWORD *)(v1 + 6796);
  else
    *((_DWORD *)this - 60) = 0;
  CBasePlayerAnimState::ClearAnimationState(this: (CCSPlayerAnimState *)((char *)this - 300));
}

//------------------------------------------------------------------------------
// Address: 0x101C8ED0
// Name: public: virtual void CCSPlayerAnimState::DoAnimationEvent(enum PlayerAnimEvent_t,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSPlayerAnimState::DoAnimationEvent(CCSPlayerAnimState *this, float event, int nData)
{
  IMDLCache *v3; // ebx
  int v5; // eax
  C_BaseAnimatingOverlay *v6; // ecx
  C_AnimationLayer *AnimOverlay; // eax
  C_AnimationLayer *v8; // edi
  float z; // esi
  double v10; // st7
  C_WeaponCSBase *v11; // eax
  C_WeaponCSBase *v12; // edi
  int v13; // eax
  C_WeaponCSBase *v14; // eax
  C_WeaponCSBase *v15; // ebx
  IMDLCache *cacheCriticalSection; // [esp+10h] [ebp-4h]

  v3 = mdlcache;
  cacheCriticalSection = mdlcache;
  mdlcache->BeginLock(this: mdlcache);
  switch ( LODWORD(event) )
  {
    case 0:
    case 1:
      this->m_flCurrentTorsoYaw = 0.0;
      v5 = CCSPlayerAnimState::CalcFireLayerSequence(
             this: (CCSPlayerAnimState *)((char *)this - 148),
             event: SLODWORD(event));
      *(_DWORD *)&this->m_bCurrentFeetYawInitialized = v5;
      LOBYTE(v5) = v5 != -1;
      LOBYTE(this->m_flCurrentFeetYaw) = v5;
      if ( (_BYTE)v5 != 0 && BYTE1(this->m_pOuter) != 0 )
      {
        this->m_flEyePitch = NAN;
        *(_DWORD *)&this->m_bCurrentFeetYawInitialized = -1;
        v6 = *((C_BaseAnimatingOverlay **)this - 32);
        BYTE1(this->m_pOuter) = 0;
        this->m_flLastYaw = event;
        LOBYTE(this->m_flCurrentFeetYaw) = 0;
        AnimOverlay = C_BaseAnimatingOverlay::GetAnimOverlay(this: v6, i: 7);
        v8 = AnimOverlay;
        if ( AnimOverlay != nullptr )
        {
          C_AnimationLayer::SetWeight(this: AnimOverlay, flWeight: 0.0);
          C_AnimationLayer::SetOrder(this: v8, order: 15);
        }
      }
      if ( LOBYTE(this->m_flCurrentFeetYaw) == 0 )
        goto LABEL_25;
      if ( BYTE1(this->m_pOuter) != 0 )
        goto LABEL_25;
      z = this->m_angRender.z;
      if ( z == 0.0 )
        goto LABEL_25;
      (*(void (__thiscall **)(float))(*(_DWORD *)LODWORD(z) + 828))(a1: COERCE_FLOAT(LODWORD(z)));
      v3->EndLock(this: v3);
      return;
    case 3:
      LOBYTE(this->m_AnimConfig.m_flMaxBodyYawDegrees) = 1;
      LOBYTE(this->m_pOuter) = 1;
      v10 = *(float *)(gpGlobals.m_Index + 12);
      this->m_AnimConfig.m_LegAnimType = LEGANIM_9WAY;
      *(float *)&this->m_AnimConfig.m_bUseAimSequences = v10;
      v3->EndLock(this: v3);
      return;
    case 4:
      v11 = (C_WeaponCSBase *)(**(int (__thiscall ***)(_DWORD))LODWORD(this->m_vLastMovePose.x))(a1: LODWORD(this->m_vLastMovePose.x));
      v12 = v11;
      if ( v11 == nullptr
        || C_WeaponCSBase::GetCSWpnData(this: v11)->m_WeaponType == WEAPONTYPE_SHOTGUN
        && v12->GetCSWeaponID(this: v12) != WEAPON_MAG7 )
      {
        goto LABEL_25;
      }
      v13 = CCSPlayerAnimState::CalcReloadLayerSequence(
              this: (CCSPlayerAnimState *)((char *)this - 148),
              event: PLAYERANIMEVENT_RELOAD);
      goto LABEL_15;
    case 5:
    case 6:
      this->m_flGoalFeetYaw = *(float *)(gpGlobals.m_Index + 12) + 0.75;
      goto $LN8_24;
    case 7:
$LN8_24:
      v14 = (C_WeaponCSBase *)(**(int (__thiscall ***)(_DWORD))LODWORD(this->m_vLastMovePose.x))(a1: LODWORD(this->m_vLastMovePose.x));
      v15 = v14;
      if ( v14 != nullptr
        && (C_WeaponCSBase::GetCSWpnData(this: v14)->m_WeaponType != WEAPONTYPE_SHOTGUN
         || v15->GetCSWeaponID(this: v15) == WEAPON_MAG7) )
      {
        this->m_flGoalFeetYaw = 0.0;
        cacheCriticalSection->EndLock(this: cacheCriticalSection);
      }
      else
      {
        v13 = CCSPlayerAnimState::CalcReloadLayerSequence(
                this: (CCSPlayerAnimState *)((char *)this - 148),
                event: SLODWORD(event));
        v3 = cacheCriticalSection;
LABEL_15:
        LODWORD(this->m_flEyePitch) = v13;
        if ( v13 == -1 )
        {
          BYTE1(this->m_pOuter) = 0;
        }
        else
        {
          BYTE1(this->m_pOuter) = 1;
          this->m_flEyeYaw = 0.0;
        }
LABEL_25:
        v3->EndLock(this: v3);
      }
      return;
    case 8:
      *(_DWORD *)&this->m_bCurrentFeetYawInitialized = -1;
      goto LABEL_25;
    default:
      goto LABEL_25;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101C9110
// Name: public: virtual bool CCSPlayerAnimState::IsThrowingGrenade(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CCSPlayerAnimState::IsThrowingGrenade(CCSPlayerAnimState *this)
{
  float z; // eax
  int v3; // eax

  if ( LOBYTE(this->m_flLastTurnTime) != 0 )
  {
    if ( g_flThrowGrenadeFraction <= *(float *)&this->m_nTurningInPlace )
      return 0;
  }
  else
  {
    z = this->m_angRender.z;
    if ( z == 0.0 )
      v3 = 0;
    else
      v3 = *(_DWORD *)(LODWORD(z) + 6796);
    if ( LODWORD(this->m_angRender.y) == v3
      && !CCSPlayerAnimState::IsOuterGrenadePrimed(this: (CCSPlayerAnimState *)((char *)this - 148)) )
    {
      return 0;
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101C9160
// Name: protected: void CCSPlayerAnimState::UpdateLayerSequenceGeneric(class CStudioHdr __near *,int,bool __near &,float __near &,int __near &,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSPlayerAnimState::UpdateLayerSequenceGeneric(
        CCSPlayerAnimState *this,
        CStudioHdr *pStudioHdr,
        int iLayer,
        bool *bEnabled,
        float *flCurCycle,
        int *iSequence,
        bool bWaitAtEnd)
{
  double v8; // st7
  C_AnimationLayer *AnimOverlay; // esi

  if ( *bEnabled && *iSequence >= 0 )
  {
    v8 = ((double (__thiscall *)(C_BaseAnimatingOverlay *, CStudioHdr *, _DWORD))this->m_pOuter->GetSequenceCycleRate)(
           a1: this->m_pOuter,
           a2: pStudioHdr,
           a3: *iSequence)
       * *(float *)(gpGlobals.m_Index + 16)
       + *flCurCycle;
    *flCurCycle = v8;
    if ( v8 > 1.0 )
    {
      if ( !bWaitAtEnd )
      {
        *bEnabled = false;
        *iSequence = 0;
        return;
      }
      *flCurCycle = 1.0;
    }
    AnimOverlay = C_BaseAnimatingOverlay::GetAnimOverlay(this: this->m_pOuter, i: iLayer);
    C_AnimationLayer::SetCycle(this: AnimOverlay, flCycle: *flCurCycle);
    C_AnimationLayer::SetSequence(this: AnimOverlay, nSequence: *iSequence);
    AnimOverlay->m_flPlaybackRate.m_Val = 1.0;
    C_AnimationLayer::SetWeight(this: AnimOverlay, flWeight: 1.0);
    C_AnimationLayer::SetOrder(this: AnimOverlay, order: iLayer);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101C9230
// Name: protected: void CCSPlayerAnimState::ComputeGrenadeSequence(class CStudioHdr __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSPlayerAnimState::ComputeGrenadeSequence(CCSPlayerAnimState *this, CStudioHdr *pStudioHdr)
{
  C_CSPlayer *m_pPlayer; // ecx
  C_BaseCombatWeapon *v4; // eax
  C_CSPlayer *v5; // eax
  C_CSPlayer *v6; // eax
  int m_Value; // eax
  bool v8; // bl
  float v9; // xmm0_4
  float *p_m_flGrenadeCycle; // ebx
  C_CSPlayer *v11; // eax
  int v12; // eax
  int v13; // eax
  bool *p_m_bThrowingGrenade; // [esp+4h] [ebp-Ch]
  bool *bEnabled; // [esp+8h] [ebp-8h]
  bool bThrowPending; // [esp+Fh] [ebp-1h]

  p_m_bThrowingGrenade = &this->m_bThrowingGrenade;
  if ( this->m_bThrowingGrenade )
  {
    CCSPlayerAnimState::UpdateLayerSequenceGeneric(
      this,
      pStudioHdr,
      iLayer: 8,
      bEnabled: &this->m_bThrowingGrenade,
      flCurCycle: &this->m_flGrenadeCycle,
      iSequence: &this->m_iGrenadeSequence,
      bWaitAtEnd: false);
  }
  else
  {
    m_pPlayer = this->m_pPlayer;
    if ( m_pPlayer == nullptr
      || (v4 = m_pPlayer->GetActiveWeapon(this: m_pPlayer),
          __RTDynamicCast(
            inptr: v4,
            VfDelta: 0,
            SrcType: &C_BaseCombatWeapon `RTTI Type Descriptor',
            TargetType: &C_BaseCSGrenade `RTTI Type Descriptor',
            isReference: 0) != nullptr) )
    {
      v6 = this->m_pPlayer;
      if ( v6 != nullptr )
        m_Value = v6->m_iThrowGrenadeCounter.m_Value;
      else
        m_Value = 0;
      v8 = this->m_iLastThrowGrenadeCounter != m_Value;
      bThrowPending = v8;
      if ( CCSPlayerAnimState::IsOuterGrenadePrimed(this) || v8 )
      {
        bEnabled = &this->m_bPrimingGrenade;
        if ( !this->m_bPrimingGrenade )
        {
          if ( CBasePlayerAnimState::TimeSinceLastAnimationStateClear(this) >= 0.40000001 )
            v9 = 0.0;
          else
            v9 = 1.0;
          this->m_flGrenadeCycle = v9;
          this->m_bPrimingGrenade = true;
        }
        p_m_flGrenadeCycle = &this->m_flGrenadeCycle;
        this->m_iGrenadeSequence = CCSPlayerAnimState::CalcGrenadePrimeSequence(this);
        CCSPlayerAnimState::UpdateLayerSequenceGeneric(
          this,
          pStudioHdr,
          iLayer: 8,
          bEnabled,
          flCurCycle: &this->m_flGrenadeCycle,
          iSequence: &this->m_iGrenadeSequence,
          bWaitAtEnd: true);
        if ( bThrowPending && *p_m_flGrenadeCycle == 1.0 )
        {
          v11 = this->m_pPlayer;
          if ( v11 != nullptr )
            v12 = v11->m_iThrowGrenadeCounter.m_Value;
          else
            v12 = 0;
          this->m_iLastThrowGrenadeCounter = v12;
          v13 = CCSPlayerAnimState::CalcGrenadeThrowSequence(this);
          this->m_iGrenadeSequence = v13;
          if ( v13 != -1 )
          {
            *p_m_bThrowingGrenade = true;
            *bEnabled = false;
            *p_m_flGrenadeCycle = 0.0;
          }
        }
      }
      else
      {
        this->m_bPrimingGrenade = false;
      }
    }
    else
    {
      v5 = this->m_pPlayer;
      if ( v5 != nullptr )
        this->m_iLastThrowGrenadeCounter = v5->m_iThrowGrenadeCounter.m_Value;
      else
        this->m_iLastThrowGrenadeCounter = 0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101C93D0
// Name: public: virtual void CCSPlayerAnimState::ComputeSequences(class CStudioHdr __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CCSPlayerAnimState::ComputeSequences(
        CCSPlayerAnimState *this@<ecx>,
        int a2@<edi>,
        CStudioHdr *pStudioHdr)
{
  PlayerAnimEvent_t m_delayedFire; // eax

  CBasePlayerAnimState::ComputeSequences(this, a2, pStudioHdr);
  m_delayedFire = this->m_delayedFire;
  if ( m_delayedFire != PLAYERANIMEVENT_COUNT )
  {
    (**(void (__thiscall ***)(_BYTE *, PlayerAnimEvent_t, _DWORD))this->gap94)(
      a1: this->gap94,
      a2: m_delayedFire,
      a3: 0);
    this->m_delayedFire = PLAYERANIMEVENT_COUNT;
  }
  CCSPlayerAnimState::UpdateLayerSequenceGeneric(
    this,
    pStudioHdr,
    iLayer: 6,
    bEnabled: &this->m_bFiring,
    flCurCycle: &this->m_flFireCycle,
    iSequence: &this->m_iFireSequence,
    bWaitAtEnd: false);
  CCSPlayerAnimState::UpdateLayerSequenceGeneric(
    this,
    pStudioHdr,
    iLayer: 7,
    bEnabled: &this->m_bReloading,
    flCurCycle: &this->m_flReloadCycle,
    iSequence: &this->m_iReloadSequence,
    bWaitAtEnd: this->m_flReloadHoldEndTime > *(float *)(gpGlobals.m_Index + 12));
  if ( !this->m_bReloading )
    this->m_flReloadHoldEndTime = 0.0;
  CCSPlayerAnimState::ComputeGrenadeSequence(this, pStudioHdr);
}

//------------------------------------------------------------------------------
// Address: 0x101C9490
// Name: private: void CCSPlayerAnimState::CheckCachedSequenceValidity(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSPlayerAnimState::CheckCachedSequenceValidity(CCSPlayerAnimState *this)
{
  C_BaseEntity *Id; // eax
  C_BaseEntity *v3; // eax
  C_BaseAnimating *v4; // eax
  C_BaseAnimating *v5; // eax
  C_BaseAnimating *v6; // eax
  C_BaseAnimating *v7; // eax
  C_BaseAnimating *v8; // eax
  C_BaseAnimating *v9; // eax
  C_BaseAnimating *v10; // eax
  C_BaseAnimating *v11; // eax
  C_BaseAnimating *v12; // eax

  Id = (C_BaseEntity *)CParticleOperatorDefinition<C_OP_RemapBoundingVolumetoCP>::GetId((ConCommandBase *)this);
  if ( this->m_cachedModelIndex != C_BaseEntity::GetModelIndex(this: Id) )
  {
    CUtlDict<int,int>::RemoveAll(this: &this->m_namedSequence);
    v3 = (C_BaseEntity *)CParticleOperatorDefinition<C_OP_RemapBoundingVolumetoCP>::GetId((ConCommandBase *)this);
    this->m_cachedModelIndex = C_BaseEntity::GetModelIndex(this: v3);
    memset(this->m_sequenceCache, 0xFFu, sizeof(this->m_sequenceCache));
    if ( this->m_cachedModelIndex > 0 )
    {
      v4 = (C_BaseAnimating *)CParticleOperatorDefinition<C_OP_RemapBoundingVolumetoCP>::GetId((ConCommandBase *)this);
      this->m_sequenceCache[29] = C_BaseAnimating::SelectWeightedSequence(this: v4, activity: 30);
      v5 = (C_BaseAnimating *)CParticleOperatorDefinition<C_OP_RemapBoundingVolumetoCP>::GetId((ConCommandBase *)this);
      this->m_sequenceCache[30] = C_BaseAnimating::SelectWeightedSequence(this: v5, activity: 31);
      v6 = (C_BaseAnimating *)CParticleOperatorDefinition<C_OP_RemapBoundingVolumetoCP>::GetId((ConCommandBase *)this);
      this->m_sequenceCache[28] = C_BaseAnimating::SelectWeightedSequence(this: v6, activity: 29);
      v7 = (C_BaseAnimating *)CParticleOperatorDefinition<C_OP_RemapBoundingVolumetoCP>::GetId((ConCommandBase *)this);
      this->m_sequenceCache[0] = C_BaseAnimating::SelectWeightedSequence(this: v7, activity: 1);
      v8 = (C_BaseAnimating *)CParticleOperatorDefinition<C_OP_RemapBoundingVolumetoCP>::GetId((ConCommandBase *)this);
      this->m_sequenceCache[11] = C_BaseAnimating::SelectWeightedSequence(this: v8, activity: 12);
      v9 = (C_BaseAnimating *)CParticleOperatorDefinition<C_OP_RemapBoundingVolumetoCP>::GetId((ConCommandBase *)this);
      this->m_sequenceCache[44] = C_BaseAnimating::SelectWeightedSequence(this: v9, activity: 45);
      v10 = (C_BaseAnimating *)CParticleOperatorDefinition<C_OP_RemapBoundingVolumetoCP>::GetId((ConCommandBase *)this);
      this->m_sequenceCache[9] = C_BaseAnimating::SelectWeightedSequence(this: v10, activity: 10);
      v11 = (C_BaseAnimating *)CParticleOperatorDefinition<C_OP_RemapBoundingVolumetoCP>::GetId((ConCommandBase *)this);
      this->m_sequenceCache[5] = C_BaseAnimating::SelectWeightedSequence(this: v11, activity: 6);
      v12 = (C_BaseAnimating *)CParticleOperatorDefinition<C_OP_RemapBoundingVolumetoCP>::GetId((ConCommandBase *)this);
      this->m_sequenceCache[0] = C_BaseAnimating::SelectWeightedSequence(this: v12, activity: 1);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101C95C0
// Name: public: virtual int CCSPlayerAnimState::SelectWeightedSequence(enum Activity)
// Source: json
//------------------------------------------------------------------------------
ICSPlayerAnimStateHelpers *__thiscall CCSPlayerAnimState::SelectWeightedSequence(
        CCSPlayerAnimState *this,
        Activity activity)
{
  ICSPlayerAnimStateHelpers *result; // eax
  C_BaseAnimating *v4; // eax
  C_BaseAnimating *Id; // eax

  if ( (unsigned int)(activity - 1) > 0x2C )
  {
    Id = (C_BaseAnimating *)CParticleOperatorDefinition<C_OP_RemapBoundingVolumetoCP>::GetId((ConCommandBase *)this);
    return (ICSPlayerAnimStateHelpers *)C_BaseAnimating::SelectWeightedSequence(this: Id, activity);
  }
  else
  {
    CCSPlayerAnimState::CheckCachedSequenceValidity(this);
    result = (&this->m_pHelpers)[activity];
    if ( (int)result < 0 )
    {
      v4 = (C_BaseAnimating *)CParticleOperatorDefinition<C_OP_RemapBoundingVolumetoCP>::GetId((ConCommandBase *)this);
      result = (ICSPlayerAnimStateHelpers *)C_BaseAnimating::SelectWeightedSequence(this: v4, activity);
      (&this->m_pHelpers)[activity] = result;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101C9620
// Name: public: CCSPlayerAnimState::CCSPlayerAnimState(void)
// Source: json
//------------------------------------------------------------------------------
CCSPlayerAnimState *__thiscall CCSPlayerAnimState::CCSPlayerAnimState(CCSPlayerAnimState *this, int a2)
{
  int v3; // eax
  int v4; // edx

  if ( a2 != 0 )
  {
    *(_DWORD *)this->gap4 = &CCSHostageAnimState::`vbtable'{for `CBasePlayerAnimState'};
    *(_DWORD *)&this->gap94[4] = &CCSPlayerAnimState::`vbtable'{for `ICSPlayerAnimState'};
    *(_DWORD *)&this->gap1C0[4] = &IPlayerAnimState::`vftable';
  }
  CBasePlayerAnimState::CBasePlayerAnimState(this, a2: 0);
  v3 = *(_DWORD *)&this->gap94[4];
  *(_DWORD *)this->gap94 = &ICSPlayerAnimState::`vftable'{for `ICSPlayerAnimState'};
  *(_DWORD *)&this->gap94[*(_DWORD *)(v3 + 4) + 4] = &ICSPlayerAnimState::`vftable'{for `IPlayerAnimState'};
  v4 = *(_DWORD *)this->gap4;
  this->__vftable = (CCSPlayerAnimState_vtbl *)&CCSPlayerAnimState::`vftable'{for `CBasePlayerAnimState'};
  *(_DWORD *)this->gap94 = &CCSPlayerAnimState::`vftable'{for `ICSPlayerAnimState'};
  *(_DWORD *)&this->gap4[*(_DWORD *)(v4 + 4)] = &CCSPlayerAnimState::`vftable'{for `IPlayerAnimState'};
  *(CCSPlayerAnimState_vtbl **)((char *)&this->__vftable + *(_DWORD *)(*(_DWORD *)this->gap4 + 4)) = (CCSPlayerAnimState_vtbl *)(*(_DWORD *)(*(_DWORD *)this->gap4 + 4) - 448);
  this->m_namedSequence.m_Elements.m_Tree.m_LessFunc.m_LessFunc = nullptr;
  this->m_namedSequence.m_Elements.m_Tree.m_Elements.m_pMemory = nullptr;
  this->m_namedSequence.m_Elements.m_Tree.m_Elements.m_nAllocationCount = 0;
  this->m_namedSequence.m_Elements.m_Tree.m_Elements.m_nGrowSize = 0;
  this->m_namedSequence.m_Elements.m_Tree.m_Root = -1;
  this->m_namedSequence.m_Elements.m_Tree.m_NumElements = 0;
  this->m_namedSequence.m_Elements.m_Tree.m_FirstFree = -1;
  this->m_namedSequence.m_Elements.m_Tree.m_LastAlloc.index = -1;
  this->m_namedSequence.m_Elements.m_Tree.m_pElements = this->m_namedSequence.m_Elements.m_Tree.m_Elements.m_pMemory;
  if ( this->m_namedSequence.m_Elements.m_Tree.m_LessFunc.m_LessFunc == nullptr )
    this->m_namedSequence.m_Elements.m_Tree.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))CaselessStringLessThan;
  this->m_iReloadSequence = -1;
  this->m_iFireSequence = -1;
  this->m_iGrenadeSequence = -1;
  this->m_cachedModelIndex = -1;
  this->m_pOuter = nullptr;
  this->_bytes_9c[0] = 0;
  *(_WORD *)&this->m_bFirstJumpFrame = 0;
  this->m_bFiring = false;
  *(_WORD *)&this->m_bThrowingGrenade = 0;
  this->m_iLastThrowGrenadeCounter = 0;
  this->m_pPlayer = nullptr;
  this->m_pHelpers = nullptr;
  *(_QWORD *)&this->m_flJumpLandTime = 0;
  this->m_flReloadCycle = 0.0;
  this->m_flReloadHoldEndTime = 0.0;
  this->m_flFireCycle = 0.0;
  this->m_delayedFire = PLAYERANIMEVENT_COUNT;
  this->m_flGrenadeCycle = 0.0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101C9800
// Name: class ICSPlayerAnimState __near * CreatePlayerAnimState(class C_BaseAnimatingOverlay __near *,class ICSPlayerAnimStateHelpers __near *,enum LegAnimType_t,bool)
// Source: json
//------------------------------------------------------------------------------
ICSPlayerAnimState *__cdecl CreatePlayerAnimState(
        C_BaseAnimatingOverlay *pEntity,
        ICSPlayerAnimStateHelpers *pHelpers,
        LegAnimType_t legAnimType,
        bool bUseAimSequences)
{
  CCSPlayerAnimState *v4; // eax
  CCSPlayerAnimState *v5; // esi
  C_BaseAnimatingOverlay *v6; // eax
  CModAnimConfig config; // [esp+8h] [ebp-Ch] BYREF

  v4 = (CCSPlayerAnimState *)MemAlloc_Alloc(nSize: 0x1C8u);
  if ( v4 != nullptr )
    v5 = CCSPlayerAnimState::CCSPlayerAnimState(this: v4);
  else
    v5 = nullptr;
  config.m_flMaxBodyYawDegrees = 90.0;
  config.m_LegAnimType = legAnimType;
  config.m_bUseAimSequences = bUseAimSequences;
  if ( pEntity != nullptr && pEntity->IsPlayer(this: pEntity) )
    v6 = pEntity;
  else
    v6 = nullptr;
  v5->m_pHelpers = pHelpers;
  v5->m_pPlayer = (C_CSPlayer *)v6;
  CBasePlayerAnimState::Init(this: v5, pPlayer: pEntity, &config);
  return (ICSPlayerAnimState *)v5->gap94;
}

//------------------------------------------------------------------------------
// Address: 0x101C9890
// Name: public: virtual int CCSHostageAnimState::SelectWeightedSequence(enum Activity)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CCSHostageAnimState::SelectWeightedSequence(CCSHostageAnimState *this, Activity activity)
{
  C_BaseAnimating *Id; // eax

  Id = (C_BaseAnimating *)CParticleOperatorDefinition<C_OP_RemapBoundingVolumetoCP>::GetId((ConCommandBase *)this);
  return C_BaseAnimating::SelectWeightedSequence(this: Id, activity);
}

//------------------------------------------------------------------------------
// Address: 0x101C98B0
// Name: class ICSPlayerAnimState __near * CreateHostageAnimState(class C_BaseAnimatingOverlay __near *,class ICSPlayerAnimStateHelpers __near *,enum LegAnimType_t,bool)
// Source: json
//------------------------------------------------------------------------------
ICSPlayerAnimState *__cdecl CreateHostageAnimState(
        C_BaseAnimatingOverlay *pEntity,
        ICSPlayerAnimStateHelpers *pHelpers,
        LegAnimType_t legAnimType,
        bool bUseAimSequences)
{
  CCSPlayerAnimState *v4; // eax
  CCSPlayerAnimState *v5; // esi
  int v6; // eax
  C_BaseAnimatingOverlay *v7; // eax
  CModAnimConfig config; // [esp+8h] [ebp-Ch] BYREF

  v4 = (CCSPlayerAnimState *)MemAlloc_Alloc(nSize: 0x1C8u);
  v5 = v4;
  if ( v4 != nullptr )
  {
    *(_DWORD *)v4->gap4 = &CCSHostageAnimState::`vbtable'{for `CBasePlayerAnimState'};
    *(_DWORD *)&v4->gap94[4] = &CCSPlayerAnimState::`vbtable'{for `ICSPlayerAnimState'};
    *(_DWORD *)&v4->gap1C0[4] = &IPlayerAnimState::`vftable';
    CCSPlayerAnimState::CCSPlayerAnimState(this: v4);
    v6 = *(_DWORD *)v5->gap4;
    v5->__vftable = (CCSPlayerAnimState_vtbl *)&CCSHostageAnimState::`vftable'{for `CBasePlayerAnimState'};
    *(_DWORD *)v5->gap94 = &CCSHostageAnimState::`vftable'{for `ICSPlayerAnimState'};
    *(_DWORD *)&v5->gap4[*(_DWORD *)(v6 + 4)] = &CCSHostageAnimState::`vftable'{for `IPlayerAnimState'};
    *(CCSPlayerAnimState_vtbl **)((char *)&v5->__vftable + *(_DWORD *)(*(_DWORD *)v5->gap4 + 4)) = (CCSPlayerAnimState_vtbl *)(*(_DWORD *)(*(_DWORD *)v5->gap4 + 4) - 448);
  }
  else
  {
    v5 = nullptr;
  }
  config.m_flMaxBodyYawDegrees = 90.0;
  config.m_LegAnimType = legAnimType;
  config.m_bUseAimSequences = bUseAimSequences;
  if ( pEntity != nullptr && pEntity->IsPlayer(this: pEntity) )
    v7 = pEntity;
  else
    v7 = nullptr;
  v5->m_pHelpers = pHelpers;
  v5->m_pPlayer = (C_CSPlayer *)v7;
  CBasePlayerAnimState::Init(this: v5, pPlayer: pEntity, &config);
  return (ICSPlayerAnimState *)v5->gap94;
}

//------------------------------------------------------------------------------
// Address: 0x101C9980
// Name: protected: virtual int CCSPlayerAnimState::CalcSequenceIndex(char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
int CCSPlayerAnimState::CalcSequenceIndex(CCSPlayerAnimState *this, const char *pBaseName, ...)
{
  int v2; // eax
  C_BaseAnimating *Id; // eax
  int elem; // esi
  char szFullName[512]; // [esp+8h] [ebp-208h] BYREF
  CUtlMap<char const *,int,int>::Node_t search; // [esp+208h] [ebp-8h] BYREF
  va_list params; // [esp+220h] [ebp+10h] BYREF

  va_start(params, pBaseName);
  CCSPlayerAnimState::CheckCachedSequenceValidity(this);
  V_vsnprintf(pDest: szFullName, maxLen: 0x200u, pFormat: pBaseName, params);
  search.key = szFullName;
  v2 = CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Find(
         this: &this->m_namedSequence.m_Elements.m_Tree,
         &search);
  if ( v2 == -1 )
  {
    Id = (C_BaseAnimating *)CParticleOperatorDefinition<C_OP_RemapBoundingVolumetoCP>::GetId((ConCommandBase *)this);
    elem = C_BaseAnimating::LookupSequence(this: Id, label: szFullName);
    search.elem = elem;
    CUtlDict<int,int>::Insert(this: &this->m_namedSequence, pName: szFullName, element: &search.elem);
  }
  else
  {
    elem = this->m_namedSequence.m_Elements.m_Tree.m_Elements.m_pMemory[v2].m_Data.elem;
  }
  if ( elem != -1 )
    return elem;
  if ( (_S5_140 & 1) == 0 )
  {
    _S5_140 |= 1u;
    dict_0.m_Elements.m_Tree.m_Elements.m_pMemory = nullptr;
    dict_0.m_Elements.m_Tree.m_Elements.m_nAllocationCount = 0;
    dict_0.m_Elements.m_Tree.m_Elements.m_nGrowSize = 0;
    dict_0.m_Elements.m_Tree.m_Root = -1;
    dict_0.m_Elements.m_Tree.m_NumElements = 0;
    dict_0.m_Elements.m_Tree.m_FirstFree = -1;
    dict_0.m_Elements.m_Tree.m_LastAlloc.index = -1;
    dict_0.m_Elements.m_Tree.m_pElements = nullptr;
    dict_0.m_Elements.m_Tree.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))CaselessStringLessThan;
    atexit(func: CCSPlayerAnimState::CalcSequenceIndex_::_10_::_dynamic_atexit_destructor_for__dict__);
  }
  search.key = szFullName;
  if ( CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Find(
         this: &dict_0.m_Elements.m_Tree,
         &search) == -1 )
  {
    search.elem = 0;
    CUtlDict<int,int>::Insert(this: &dict_0, pName: szFullName, element: &search.elem);
    _Warning(a1: "CalcSequenceIndex: can't find '%s'.\n", szFullName);
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10424830
// Name: _dynamic_initializer_for__player_teamplayedlast__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__player_teamplayedlast__()
{
  ConVar::ConVar(this: &player_teamplayedlast, pName: "player_teamplayedlast", pDefaultValue: "0", flags: 16810112);
  return atexit(func: dynamic_atexit_destructor_for__player_teamplayedlast__);
}

//------------------------------------------------------------------------------
// Address: 0x10424860
// Name: _dynamic_initializer_for__player_classplayedlast__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__player_classplayedlast__()
{
  ConVar::ConVar(this: &player_classplayedlast, pName: "player_classplayedlast", pDefaultValue: "0", flags: 16810112);
  return atexit(func: dynamic_atexit_destructor_for__player_classplayedlast__);
}

//------------------------------------------------------------------------------
// Address: 0x10424AA0
// Name: _dynamic_initializer_for__player_gametypelast_s__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__player_gametypelast_s__()
{
  ConVar::ConVar(this: &player_gametypelast_s, pName: "player_gametypelast_s", pDefaultValue: "0", flags: 16810112);
  return atexit(func: dynamic_atexit_destructor_for__player_gametypelast_s__);
}

//------------------------------------------------------------------------------
// Address: 0x10424AD0
// Name: _dynamic_initializer_for__player_gamemodelast_s__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__player_gamemodelast_s__()
{
  ConVar::ConVar(this: &player_gamemodelast_s, pName: "player_gamemodelast_s", pDefaultValue: "0", flags: 16810112);
  return atexit(func: dynamic_atexit_destructor_for__player_gamemodelast_s__);
}

//------------------------------------------------------------------------------
// Address: 0x10424B00
// Name: _dynamic_initializer_for__player_maplast_s__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__player_maplast_s__()
{
  ConVar::ConVar(this: &player_maplast_s, pName: "player_maplast_s", pDefaultValue: "0", flags: 16810112);
  return atexit(func: dynamic_atexit_destructor_for__player_maplast_s__);
}

//------------------------------------------------------------------------------
// Address: 0x10424B30
// Name: _dynamic_initializer_for__player_botdifflast_s__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__player_botdifflast_s__()
{
  ConVar::ConVar(this: &player_botdifflast_s, pName: "player_botdifflast_s", pDefaultValue: "0", flags: 16810112);
  return atexit(func: dynamic_atexit_destructor_for__player_botdifflast_s__);
}

//------------------------------------------------------------------------------
// Address: 0x10424B60
// Name: _dynamic_initializer_for__player_gametypelast_m__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__player_gametypelast_m__()
{
  ConVar::ConVar(this: &player_gametypelast_m, pName: "player_gametypelast_m", pDefaultValue: "0", flags: 16810112);
  return atexit(func: dynamic_atexit_destructor_for__player_gametypelast_m__);
}

//------------------------------------------------------------------------------
// Address: 0x10424B90
// Name: _dynamic_initializer_for__player_gamemodelast_m__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__player_gamemodelast_m__()
{
  ConVar::ConVar(this: &player_gamemodelast_m, pName: "player_gamemodelast_m", pDefaultValue: "0", flags: 16810112);
  return atexit(func: dynamic_atexit_destructor_for__player_gamemodelast_m__);
}

//------------------------------------------------------------------------------
// Address: 0x10424BC0
// Name: _dynamic_initializer_for__player_maplast_m__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__player_maplast_m__()
{
  ConVar::ConVar(this: &player_maplast_m, pName: "player_maplast_m", pDefaultValue: "0", flags: 16810112);
  return atexit(func: dynamic_atexit_destructor_for__player_maplast_m__);
}

//------------------------------------------------------------------------------
// Address: 0x10424BF0
// Name: _dynamic_initializer_for__player_mmprivacylast_m__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__player_mmprivacylast_m__()
{
  ConVar::ConVar(this: &player_mmprivacylast_m, pName: "player_mmprivacylast_m", pDefaultValue: "0", flags: 16810112);
  return atexit(func: dynamic_atexit_destructor_for__player_mmprivacylast_m__);
}

//------------------------------------------------------------------------------
// Address: 0x10424FD0
// Name: _dynamic_initializer_for__player_last_leaderboards_panel__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__player_last_leaderboards_panel__()
{
  ConVar::ConVar(
    this: &player_last_leaderboards_panel,
    pName: "player_last_leaderboards_panel",
    pDefaultValue: "0",
    flags: 16810112,
    pHelpString: "Last opened panel in the Leaderboards screen");
  return atexit(func: dynamic_atexit_destructor_for__player_last_leaderboards_panel__);
}

//------------------------------------------------------------------------------
// Address: 0x10425000
// Name: _dynamic_initializer_for__player_last_leaderboards_mode__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__player_last_leaderboards_mode__()
{
  ConVar::ConVar(
    this: &player_last_leaderboards_mode,
    pName: "player_last_leaderboards_mode",
    pDefaultValue: "0",
    flags: 16810112,
    pHelpString: "Last mode setting in the Leaderboards screen");
  return atexit(func: dynamic_atexit_destructor_for__player_last_leaderboards_mode__);
}

//------------------------------------------------------------------------------
// Address: 0x10425030
// Name: _dynamic_initializer_for__player_last_leaderboards_filter__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__player_last_leaderboards_filter__()
{
  ConVar::ConVar(
    this: &player_last_leaderboards_filter,
    pName: "player_last_leaderboards_filter",
    pDefaultValue: "0",
    flags: 16810112,
    pHelpString: "Last mode setting in the Leaderboards screen");
  return atexit(func: dynamic_atexit_destructor_for__player_last_leaderboards_filter__);
}

//------------------------------------------------------------------------------
// Address: 0x10425400
// Name: _dynamic_initializer_for__player_last_medalstats_panel__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__player_last_medalstats_panel__()
{
  ConVar::ConVar(
    this: &player_last_medalstats_panel,
    pName: "player_last_medalstats_panel",
    pDefaultValue: "0",
    flags: 16810112,
    pHelpString: "Last opened panel in the Medals & Stats screen");
  return atexit(func: dynamic_atexit_destructor_for__player_last_medalstats_panel__);
}

//------------------------------------------------------------------------------
// Address: 0x10425430
// Name: _dynamic_initializer_for__player_last_medalstats_category__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__player_last_medalstats_category__()
{
  ConVar::ConVar(
    this: &player_last_medalstats_category,
    pName: "player_last_medalstats_category",
    pDefaultValue: "0",
    flags: 16810112,
    pHelpString: "Last selected category on the Medals panel in the Medals & Stats screen");
  return atexit(func: dynamic_atexit_destructor_for__player_last_medalstats_category__);
}

//------------------------------------------------------------------------------
// Address: 0x10425460
// Name: _dynamic_initializer_for__player_last_medalstats_access_time1__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__player_last_medalstats_access_time1__()
{
  ConVar::ConVar(
    this: &player_last_medalstats_access_time1,
    pName: "player_last_medalstats_access_time1",
    pDefaultValue: "0",
    flags: 16810112,
    pHelpString: "Last year/month/day we accessed this screen - packed as a uint32 of year:16-month:8-day:8");
  return atexit(func: dynamic_atexit_destructor_for__player_last_medalstats_access_time1__);
}

//------------------------------------------------------------------------------
// Address: 0x10425490
// Name: _dynamic_initializer_for__player_last_medalstats_access_time2__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__player_last_medalstats_access_time2__()
{
  ConVar::ConVar(
    this: &player_last_medalstats_access_time2,
    pName: "player_last_medalstats_access_time2",
    pDefaultValue: "0",
    flags: 16810112,
    pHelpString: "Last hour/min/sec we accessed this screen - packed as a uint32 of hour:8-min:8-sec:8");
  return atexit(func: dynamic_atexit_destructor_for__player_last_medalstats_access_time2__);
}

//------------------------------------------------------------------------------
// Address: 0x1042F740
// Name: _CBasePlayerAnimState::CalcSequenceIndex_::_5_::_dynamic_atexit_destructor_for__dict__
// Source: json
//------------------------------------------------------------------------------
void __cdecl CBasePlayerAnimState::CalcSequenceIndex_::_5_::_dynamic_atexit_destructor_for__dict__()
{
  CUtlDict<int,int>::RemoveAll(this: &dict);
  CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::~CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>(this: &dict.m_Elements.m_Tree);
}

//------------------------------------------------------------------------------
// Address: 0x10435810
// Name: _CCSPlayerAnimState::CalcSequenceIndex_::_10_::_dynamic_atexit_destructor_for__dict__
// Source: json
//------------------------------------------------------------------------------
void __cdecl CCSPlayerAnimState::CalcSequenceIndex_::_10_::_dynamic_atexit_destructor_for__dict__()
{
  CUtlDict<int,int>::RemoveAll(this: &dict_0);
  CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::~CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>(this: &dict_0.m_Elements.m_Tree);
}

//------------------------------------------------------------------------------
// Address: 0x10435BE0
// Name: _dynamic_atexit_destructor_for__player_teamplayedlast__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__player_teamplayedlast__()
{
  ConVar::~ConVar(this: &player_teamplayedlast);
}

//------------------------------------------------------------------------------
// Address: 0x10435BF0
// Name: _dynamic_atexit_destructor_for__player_classplayedlast__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__player_classplayedlast__()
{
  ConVar::~ConVar(this: &player_classplayedlast);
}

//------------------------------------------------------------------------------
// Address: 0x10435C00
// Name: _dynamic_atexit_destructor_for__player_gametypelast_s__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__player_gametypelast_s__()
{
  ConVar::~ConVar(this: &player_gametypelast_s);
}

//------------------------------------------------------------------------------
// Address: 0x10435C10
// Name: _dynamic_atexit_destructor_for__player_gamemodelast_s__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__player_gamemodelast_s__()
{
  ConVar::~ConVar(this: &player_gamemodelast_s);
}

//------------------------------------------------------------------------------
// Address: 0x10435C20
// Name: _dynamic_atexit_destructor_for__player_maplast_s__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__player_maplast_s__()
{
  ConVar::~ConVar(this: &player_maplast_s);
}

//------------------------------------------------------------------------------
// Address: 0x10435C30
// Name: _dynamic_atexit_destructor_for__player_botdifflast_s__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__player_botdifflast_s__()
{
  ConVar::~ConVar(this: &player_botdifflast_s);
}

//------------------------------------------------------------------------------
// Address: 0x10435C40
// Name: _dynamic_atexit_destructor_for__player_gametypelast_m__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__player_gametypelast_m__()
{
  ConVar::~ConVar(this: &player_gametypelast_m);
}

//------------------------------------------------------------------------------
// Address: 0x10435C50
// Name: _dynamic_atexit_destructor_for__player_gamemodelast_m__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__player_gamemodelast_m__()
{
  ConVar::~ConVar(this: &player_gamemodelast_m);
}

//------------------------------------------------------------------------------
// Address: 0x10435C60
// Name: _dynamic_atexit_destructor_for__player_maplast_m__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__player_maplast_m__()
{
  ConVar::~ConVar(this: &player_maplast_m);
}

//------------------------------------------------------------------------------
// Address: 0x10435C70
// Name: _dynamic_atexit_destructor_for__player_mmprivacylast_m__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__player_mmprivacylast_m__()
{
  ConVar::~ConVar(this: &player_mmprivacylast_m);
}

//------------------------------------------------------------------------------
// Address: 0x10435C80
// Name: _dynamic_atexit_destructor_for__player_last_leaderboards_panel__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__player_last_leaderboards_panel__()
{
  ConVar::~ConVar(this: &player_last_leaderboards_panel);
}

//------------------------------------------------------------------------------
// Address: 0x10435C90
// Name: _dynamic_atexit_destructor_for__player_last_leaderboards_mode__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__player_last_leaderboards_mode__()
{
  ConVar::~ConVar(this: &player_last_leaderboards_mode);
}

//------------------------------------------------------------------------------
// Address: 0x10435CA0
// Name: _dynamic_atexit_destructor_for__player_last_leaderboards_filter__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__player_last_leaderboards_filter__()
{
  ConVar::~ConVar(this: &player_last_leaderboards_filter);
}

//------------------------------------------------------------------------------
// Address: 0x10435CB0
// Name: _dynamic_atexit_destructor_for__player_last_medalstats_panel__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__player_last_medalstats_panel__()
{
  ConVar::~ConVar(this: &player_last_medalstats_panel);
}

//------------------------------------------------------------------------------
// Address: 0x10435CC0
// Name: _dynamic_atexit_destructor_for__player_last_medalstats_category__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__player_last_medalstats_category__()
{
  ConVar::~ConVar(this: &player_last_medalstats_category);
}

//------------------------------------------------------------------------------
// Address: 0x10435CD0
// Name: _dynamic_atexit_destructor_for__player_last_medalstats_access_time1__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__player_last_medalstats_access_time1__()
{
  ConVar::~ConVar(this: &player_last_medalstats_access_time1);
}

//------------------------------------------------------------------------------
// Address: 0x10435CE0
// Name: _dynamic_atexit_destructor_for__player_last_medalstats_access_time2__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__player_last_medalstats_access_time2__()
{
  ConVar::~ConVar(this: &player_last_medalstats_access_time2);
}

//------------------------------------------------------------------------------
// Address: 0x1042F760
// Name: _DataMapInit_CBaseAchievement__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CBaseAchievement__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder);
}

//------------------------------------------------------------------------------
// Address: 0x1042F770
// Name: _DataMapInit_CFailableAchievement__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CFailableAchievement__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_0);
}

//------------------------------------------------------------------------------
// Address: 0x1042F780
// Name: _dynamic_atexit_destructor_for__cl_disable_water_render_targets__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_disable_water_render_targets__()
{
  ConVar::~ConVar(this: &cl_disable_water_render_targets);
}

//------------------------------------------------------------------------------
// Address: 0x1042F790
// Name: _dynamic_atexit_destructor_for__g_BaseClientRenderTargets__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_BaseClientRenderTargets__()
{
  CTextureReference::~CTextureReference(this: &g_BaseClientRenderTargets.m_CameraTexture);
  CTextureReference::~CTextureReference(this: &g_BaseClientRenderTargets.m_WaterRefractionTexture);
  CTextureReference::~CTextureReference(this: &g_BaseClientRenderTargets.m_WaterReflectionTexture);
}

//------------------------------------------------------------------------------
// Address: 0x1042F7B0
// Name: _dynamic_atexit_destructor_for__s_CombatCharVisCache__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_CombatCharVisCache__()
{
  CUtlRBTree<CCombatCharVisCache::VisCacheEntry_t,unsigned short,CCombatCharVisCache::CVisCacheEntryLess,CUtlMemory<UtlRBTreeNode_t<CCombatCharVisCache::VisCacheEntry_t,unsigned short>,unsigned short>>::~CUtlRBTree<CCombatCharVisCache::VisCacheEntry_t,unsigned short,CCombatCharVisCache::CVisCacheEntryLess,CUtlMemory<UtlRBTreeNode_t<CCombatCharVisCache::VisCacheEntry_t,unsigned short>,unsigned short>>(this: &s_CombatCharVisCache.m_VisCache);
  IGameSystemPerFrame::~IGameSystemPerFrame(this: &s_CombatCharVisCache);
}

//------------------------------------------------------------------------------
// Address: 0x10435830
// Name: _dynamic_atexit_destructor_for__g_Prediction__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_Prediction__()
{
  CPrediction::~CPrediction(this: &g_Prediction);
}

//------------------------------------------------------------------------------
// Address: 0x10435840
// Name: _dynamic_atexit_destructor_for__g_ViewRender__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_ViewRender__()
{
  CViewRender::~CViewRender(this: &g_ViewRender);
}

// ============================================================
// Overlay from server (Missing functions)
// ============================================================
namespace server {

//------------------------------------------------------------------------------
// Address: 0x100941C0
// Name: public: virtual void CBasePlayerAnimState::Release(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBasePlayerAnimState::Release(CBasePlayerAnimState *this)
{
  char *v1; // ecx

  v1 = (char *)this - 152;
  if ( v1 != nullptr )
    (**(void (__thiscall ***)(char *, int))v1)(a1: v1, a2: 1);
}

//------------------------------------------------------------------------------
// Address: 0x100942A0
// Name: public: virtual class QAngle const __near & CBasePlayerAnimState::GetRenderAngles(void)
// Source: json
//------------------------------------------------------------------------------
const QAngle *__thiscall CBasePlayerAnimState::GetRenderAngles(CBasePlayerAnimState *this)
{
  return (const QAngle *)((char *)this - 92);
}

//------------------------------------------------------------------------------
// Address: 0x10096740
// Name: public: virtual void CBasePlayerAnimState::Update(float,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBasePlayerAnimState::Update(CBasePlayerAnimState *this, float eyeYaw, float eyePitch)
{
  CBaseAnimating *v4; // edi
  CStudioHdr *m_pStudioHdr; // edi
  float rate; // xmm0_4
  int m_nValue; // ecx
  signed int v8; // eax

  (*(void (__thiscall **)(char *))(*((_DWORD *)this - 38) + 4))(a1: (char *)this - 152);
  if ( (*(unsigned __int8 (__thiscall **)(char *))(*((_DWORD *)this - 38) + 8))(a1: (char *)this - 152) != 0 )
  {
    v4 = *((CBaseAnimating **)this - 33);
    if ( v4->m_pStudioHdr == nullptr && CBaseEntity::GetModel(this: *((CBaseEntity **)this - 33)) != nullptr )
      CBaseAnimating::LockStudioHdr(this: v4);
    m_pStudioHdr = v4->m_pStudioHdr;
    if ( m_pStudioHdr == nullptr || m_pStudioHdr->m_pStudioHdr == nullptr )
      m_pStudioHdr = nullptr;
    *((float *)this - 32) = AngleNormalize(angle: eyeYaw);
    *((float *)this - 31) = AngleNormalize(angle: eyePitch);
    (*(void (__thiscall **)(char *, CStudioHdr *))(*((_DWORD *)this - 38) + 12))(
      a1: (char *)this - 152,
      a2: m_pStudioHdr);
    (*(void (__thiscall **)(char *, CStudioHdr *))(*((_DWORD *)this - 38) + 76))(
      a1: (char *)this - 152,
      a2: m_pStudioHdr);
    (*(void (__thiscall **)(char *))(*((_DWORD *)this - 38) + 80))(a1: (char *)this - 152);
    (*(void (__thiscall **)(char *, CStudioHdr *))(*((_DWORD *)this - 38) + 72))(
      a1: (char *)this - 152,
      a2: m_pStudioHdr);
    if ( *((_DWORD *)this - 35) >= 2u )
    {
      eyePitch = ((double (__thiscall *)(char *, char *))*(_DWORD *)(*((_DWORD *)this - 38) + 48))(
                   a1: (char *)this - 152,
                   a2: (char *)&eyeYaw + 3);
      if ( HIBYTE(eyeYaw) != 0 )
        rate = eyePitch;
      else
        rate = 1.0;
      CBaseAnimating::SetPlaybackRate(this: *((CBaseAnimating **)this - 33), rate);
    }
    if ( sv_showanimstate.m_pParent != nullptr )
      m_nValue = sv_showanimstate.m_pParent->m_Value.m_nValue;
    else
      m_nValue = 0;
    v8 = *(_DWORD *)(*((_DWORD *)this - 33) + 24);
    if ( v8 != 0 )
      v8 = (signed int)(v8 - (unsigned int)gpGlobals->pEdicts) >> 4;
    if ( m_nValue == v8 )
      (*(void (__thiscall **)(char *, int))(*((_DWORD *)this - 38) + 44))(a1: (char *)this - 152, a2: 20);
  }
  else
  {
    (*(void (__thiscall **)(char *))(*(_DWORD *)((char *)this + *(_DWORD *)(*((_DWORD *)this - 37) + 4) - 148) + 8))(a1: (char *)this + *(_DWORD *)(*((_DWORD *)this - 37) + 4) - 148);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10296060
// Name: protected: int CCSPlayerAnimState::CalcGrenadePrimeSequence(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CCSPlayerAnimState::CalcGrenadePrimeSequence(CCSPlayerAnimState *this)
{
  Activity m_eCurrentMainSequenceActivity; // eax
  __int32 v3; // eax
  __int32 v4; // eax

  m_eCurrentMainSequenceActivity = this->m_eCurrentMainSequenceActivity;
  if ( m_eCurrentMainSequenceActivity > ACT_PLAYER_CROUCH_FIRE )
  {
    v3 = m_eCurrentMainSequenceActivity - 484;
    if ( v3 != 0 )
    {
      v4 = v3 - 1;
      if ( v4 != 0 )
      {
        if ( v4 == 1 )
          return this->CalcSequenceIndex(this, a2: "%s_shoot_gren1", "run");
        else
          return this->CalcSequenceIndex(this, a2: "%s_shoot_gren1", "idle");
      }
      else
      {
        return this->CalcSequenceIndex(this, a2: "%s_shoot_gren1", "walk");
      }
    }
    else
    {
      return this->CalcSequenceIndex(this, a2: "%s_shoot_gren1", "crouch_walk");
    }
  }
  else
  {
    if ( m_eCurrentMainSequenceActivity != ACT_PLAYER_CROUCH_FIRE )
    {
      switch ( m_eCurrentMainSequenceActivity )
      {
        case ACT_WALK:
          return this->CalcSequenceIndex(this, a2: "%s_shoot_gren1", "walk");
        case ACT_RUN:
          return this->CalcSequenceIndex(this, a2: "%s_shoot_gren1", "run");
        case ACT_RUN_CROUCH:
          return this->CalcSequenceIndex(this, a2: "%s_shoot_gren1", "crouch_walk");
        case ACT_CROUCHIDLE:
          return this->CalcSequenceIndex(this, a2: "%s_shoot_gren1", "crouch_idle");
        default:
          return this->CalcSequenceIndex(this, a2: "%s_shoot_gren1", "idle");
      }
    }
    return this->CalcSequenceIndex(this, a2: "%s_shoot_gren1", "crouch_idle");
  }
}

//------------------------------------------------------------------------------
// Address: 0x10296140
// Name: protected: int CCSPlayerAnimState::CalcGrenadeThrowSequence(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CCSPlayerAnimState::CalcGrenadeThrowSequence(CCSPlayerAnimState *this)
{
  Activity m_eCurrentMainSequenceActivity; // eax
  __int32 v3; // eax
  __int32 v4; // eax

  m_eCurrentMainSequenceActivity = this->m_eCurrentMainSequenceActivity;
  if ( m_eCurrentMainSequenceActivity > ACT_PLAYER_CROUCH_FIRE )
  {
    v3 = m_eCurrentMainSequenceActivity - 484;
    if ( v3 != 0 )
    {
      v4 = v3 - 1;
      if ( v4 != 0 )
      {
        if ( v4 == 1 )
          return this->CalcSequenceIndex(this, a2: "%s_shoot_gren2", "run");
        else
          return this->CalcSequenceIndex(this, a2: "%s_shoot_gren2", "idle");
      }
      else
      {
        return this->CalcSequenceIndex(this, a2: "%s_shoot_gren2", "walk");
      }
    }
    else
    {
      return this->CalcSequenceIndex(this, a2: "%s_shoot_gren2", "crouch_walk");
    }
  }
  else
  {
    if ( m_eCurrentMainSequenceActivity != ACT_PLAYER_CROUCH_FIRE )
    {
      switch ( m_eCurrentMainSequenceActivity )
      {
        case ACT_WALK:
          return this->CalcSequenceIndex(this, a2: "%s_shoot_gren2", "walk");
        case ACT_RUN:
          return this->CalcSequenceIndex(this, a2: "%s_shoot_gren2", "run");
        case ACT_RUN_CROUCH:
          return this->CalcSequenceIndex(this, a2: "%s_shoot_gren2", "crouch_walk");
        case ACT_CROUCHIDLE:
          return this->CalcSequenceIndex(this, a2: "%s_shoot_gren2", "crouch_idle");
        default:
          return this->CalcSequenceIndex(this, a2: "%s_shoot_gren2", "idle");
      }
    }
    return this->CalcSequenceIndex(this, a2: "%s_shoot_gren2", "crouch_idle");
  }
}

//------------------------------------------------------------------------------
// Address: 0x10296220
// Name: protected: int CCSPlayerAnimState::CalcFireLayerSequence(enum PlayerAnimEvent_t)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CCSPlayerAnimState::CalcFireLayerSequence(CCSPlayerAnimState *this, PlayerAnimEvent_t event)
{
  CWeaponCSBase *v3; // ebx
  CWeaponCSBase *v5; // eax
  const CCSWeaponInfo *CSWpnData; // eax
  char *m_szAnimExtension; // edi
  Activity m_eCurrentMainSequenceActivity; // eax
  __int32 v9; // eax
  __int32 v10; // eax
  char tempsuffix[32]; // [esp+8h] [ebp-20h] BYREF

  v3 = this->m_pHelpers->CSAnim_GetActiveWeapon(this: this->m_pHelpers);
  if ( v3 == nullptr )
    return -1;
  v5 = this->m_pHelpers->CSAnim_GetActiveWeapon(this: this->m_pHelpers);
  if ( v5 == nullptr )
    return -1;
  CSWpnData = CWeaponCSBase::GetCSWpnData(this: v5);
  m_szAnimExtension = CSWpnData->m_szAnimExtension;
  if ( CSWpnData == (const CCSWeaponInfo *)-1929 )
    return -1;
  if ( v3->GetCSWeaponID(this: v3) == WEAPON_ELITE )
  {
    V_snprintf(
      pDest: tempsuffix,
      maxLen: 32,
      pFormat: "%s_%c",
      m_szAnimExtension,
      event != PLAYERANIMEVENT_FIRE_GUN_PRIMARY ? 108 : 114);
    m_szAnimExtension = tempsuffix;
  }
  if ( event == PLAYERANIMEVENT_THROW_GRENADE
    || CWeaponCSBase::GetCSWpnData(this: v3)->m_WeaponType == WEAPONTYPE_GRENADE )
  {
    return -1;
  }
  m_eCurrentMainSequenceActivity = this->m_eCurrentMainSequenceActivity;
  if ( m_eCurrentMainSequenceActivity > ACT_PLAYER_CROUCH_FIRE )
  {
    v9 = m_eCurrentMainSequenceActivity - 484;
    if ( v9 != 0 )
    {
      v10 = v9 - 1;
      if ( v10 != 0 )
      {
        if ( v10 == 1 )
          return this->CalcSequenceIndex(this, a2: "%s%s", "run_shoot_", m_szAnimExtension);
        else
          return this->CalcSequenceIndex(this, a2: "%s%s", "idle_shoot_", m_szAnimExtension);
      }
      else
      {
        return this->CalcSequenceIndex(this, a2: "%s%s", "walk_shoot_", m_szAnimExtension);
      }
    }
    else
    {
      return this->CalcSequenceIndex(this, a2: "%s%s", "crouch_walk_shoot_", m_szAnimExtension);
    }
  }
  else
  {
    if ( m_eCurrentMainSequenceActivity != ACT_PLAYER_CROUCH_FIRE )
    {
      switch ( m_eCurrentMainSequenceActivity )
      {
        case ACT_WALK:
          return this->CalcSequenceIndex(this, a2: "%s%s", "walk_shoot_", m_szAnimExtension);
        case ACT_RUN:
          return this->CalcSequenceIndex(this, a2: "%s%s", "run_shoot_", m_szAnimExtension);
        case ACT_RUN_CROUCH:
          return this->CalcSequenceIndex(this, a2: "%s%s", "crouch_walk_shoot_", m_szAnimExtension);
        case ACT_CROUCHIDLE:
          return this->CalcSequenceIndex(this, a2: "%s%s", "crouch_idle_shoot_", m_szAnimExtension);
        default:
          return this->CalcSequenceIndex(this, a2: "%s%s", "idle_shoot_", m_szAnimExtension);
      }
    }
    return this->CalcSequenceIndex(this, a2: "%s%s", "crouch_idle_shoot_", m_szAnimExtension);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102963E0
// Name: public: virtual bool CCSPlayerAnimState::CanThePlayerMove(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CCSPlayerAnimState::CanThePlayerMove(CCSPlayerAnimState *this)
{
  return this->m_pHelpers->CSAnim_CanMove(this: this->m_pHelpers);
}

//------------------------------------------------------------------------------
// Address: 0x102963F0
// Name: protected: int CCSPlayerAnimState::CalcReloadLayerSequence(enum PlayerAnimEvent_t)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CCSPlayerAnimState::CalcReloadLayerSequence(CCSPlayerAnimState *this, PlayerAnimEvent_t event)
{
  int result; // eax
  CWeaponCSBase *v4; // eax
  const CCSWeaponInfo *CSWpnData; // eax
  const char *m_szAnimExtension; // ebx
  Activity m_eCurrentMainSequenceActivity; // eax
  const char *v8; // ecx
  __int32 v9; // eax
  __int32 v10; // eax
  const char *v11; // edi
  char szName[512]; // [esp+4h] [ebp-204h] BYREF
  CWeaponCSBase *pWeapon; // [esp+204h] [ebp-4h]

  if ( this->m_delayedFire != PLAYERANIMEVENT_COUNT )
    return -1;
  v4 = this->m_pHelpers->CSAnim_GetActiveWeapon(this: this->m_pHelpers);
  if ( v4 == nullptr )
    return -1;
  CSWpnData = CWeaponCSBase::GetCSWpnData(this: v4);
  m_szAnimExtension = CSWpnData->m_szAnimExtension;
  if ( CSWpnData == (const CCSWeaponInfo *)-1929 )
    return -1;
  pWeapon = this->m_pHelpers->CSAnim_GetActiveWeapon(this: this->m_pHelpers);
  if ( pWeapon == nullptr )
    return -1;
  m_eCurrentMainSequenceActivity = this->m_eCurrentMainSequenceActivity;
  if ( m_eCurrentMainSequenceActivity > ACT_PLAYER_CROUCH_FIRE )
  {
    v9 = m_eCurrentMainSequenceActivity - 484;
    if ( v9 != 0 )
    {
      v10 = v9 - 1;
      if ( v10 != 0 )
      {
        if ( v10 == 1 )
$LN32_6:
          v8 = "run";
        else
LABEL_14:
          v8 = "idle";
      }
      else
      {
$LN33_1:
        v8 = "walk";
      }
    }
    else
    {
$LN12_19:
      v8 = "crouch_walk";
    }
  }
  else
  {
    if ( m_eCurrentMainSequenceActivity != ACT_PLAYER_CROUCH_FIRE )
    {
      switch ( m_eCurrentMainSequenceActivity )
      {
        case ACT_WALK:
          goto $LN33_1;
        case ACT_RUN:
          goto $LN32_6;
        case ACT_RUN_CROUCH:
          goto $LN12_19;
        case ACT_CROUCHIDLE:
          break;
        default:
          goto LABEL_14;
      }
    }
    v8 = "crouch_idle";
  }
  v11 = locale;
  switch ( event )
  {
    case PLAYERANIMEVENT_RELOAD_START:
      v11 = "_start";
      break;
    case PLAYERANIMEVENT_RELOAD_LOOP:
      v11 = "_loop";
      break;
    case PLAYERANIMEVENT_RELOAD_END:
      v11 = "_end";
      break;
    default:
      break;
  }
  V_snprintf(pDest: szName, maxLen: 512, pFormat: "%s_reload_%s%s", v8, m_szAnimExtension, v11);
  result = CBaseAnimating::LookupSequence(this: this->m_pOuter, label: szName);
  if ( result == -1 )
  {
    V_snprintf(pDest: szName, maxLen: 512, pFormat: "reload_%s%s", m_szAnimExtension, v11);
    result = CBaseAnimating::LookupSequence(this: this->m_pOuter, label: szName);
    if ( result == -1 )
    {
      if ( CWeaponCSBase::GetCSWpnData(this: pWeapon)->m_WeaponType != WEAPONTYPE_PISTOL
        || (V_snprintf(pDest: szName, maxLen: 512, pFormat: "reload_pistol"),
            (result = CBaseAnimating::LookupSequence(this: this->m_pOuter, label: szName)) == -1) )
      {
        result = this->CalcSequenceIndex(this, a2: "reload_m4");
        if ( result <= 0 )
          return -1;
      }
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102965D0
// Name: protected: bool CCSPlayerAnimState::IsOuterGrenadePrimed(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CCSPlayerAnimState::IsOuterGrenadePrimed(CCSPlayerAnimState *this)
{
  CBaseCombatCharacter *v1; // eax
  CBaseCombatWeapon *ActiveWeapon; // eax
  _BYTE *v3; // eax

  v1 = this->m_pOuter->MyCombatCharacterPointer(this: this->m_pOuter);
  if ( v1 == nullptr )
    return false;
  ActiveWeapon = CBaseCombatCharacter::GetActiveWeapon(this: v1);
  v3 = __RTDynamicCast(
         inptr: ActiveWeapon,
         VfDelta: 0,
         SrcType: &CBaseCombatWeapon `RTTI Type Descriptor',
         TargetType: &CBaseCSGrenade `RTTI Type Descriptor',
         isReference: 0);
  return v3 != nullptr && v3[1473] != 0;
}

//------------------------------------------------------------------------------
// Address: 0x10296620
// Name: public: virtual int CCSPlayerAnimState::CalcAimLayerSequence(float __near *,float __near *,bool)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CCSPlayerAnimState::CalcAimLayerSequence(
        CCSPlayerAnimState *this,
        float *flCycle,
        float *flAimSequenceWeight,
        bool bForceIdle)
{
  CWeaponCSBase *v5; // eax
  char *m_szAnimExtension; // eax
  Activity m_eCurrentMainSequenceActivity; // ecx
  __int32 v9; // ecx
  __int32 v10; // ecx

  v5 = this->m_pHelpers->CSAnim_GetActiveWeapon(this: this->m_pHelpers);
  if ( v5 == nullptr )
    return 0;
  m_szAnimExtension = CWeaponCSBase::GetCSWpnData(this: v5)->m_szAnimExtension;
  if ( m_szAnimExtension == nullptr )
    return 0;
  m_eCurrentMainSequenceActivity = this->m_eCurrentMainSequenceActivity;
  if ( bForceIdle )
  {
    if ( m_eCurrentMainSequenceActivity == ACT_RUN_CROUCH || m_eCurrentMainSequenceActivity == ACT_CROUCHIDLE )
      return this->CalcSequenceIndex(this, a2: "%s%s", "crouch_idle_upper_", m_szAnimExtension);
    return this->CalcSequenceIndex(this, a2: "%s%s", "idle_upper_", m_szAnimExtension);
  }
  if ( m_eCurrentMainSequenceActivity <= ACT_JUMP )
  {
    if ( m_eCurrentMainSequenceActivity != ACT_JUMP )
    {
      v9 = m_eCurrentMainSequenceActivity - 6;
      if ( v9 != 0 )
      {
        v10 = v9 - 4;
        if ( v10 != 0 )
        {
          if ( v10 == 2 )
            return this->CalcSequenceIndex(this, a2: "%s%s", "crouch_walk_upper_", m_szAnimExtension);
          return this->CalcSequenceIndex(this, a2: "%s%s", "idle_upper_", m_szAnimExtension);
        }
        return this->CalcSequenceIndex(this, a2: "%s%s", "run_upper_", m_szAnimExtension);
      }
    }
    return this->CalcSequenceIndex(this, a2: "%s%s", "walk_upper_", m_szAnimExtension);
  }
  if ( m_eCurrentMainSequenceActivity <= ACT_CROUCHIDLE )
  {
    if ( m_eCurrentMainSequenceActivity == ACT_CROUCHIDLE )
      return this->CalcSequenceIndex(this, a2: "%s%s", "crouch_idle_upper_", m_szAnimExtension);
    if ( m_eCurrentMainSequenceActivity != ACT_LEAP )
      return this->CalcSequenceIndex(this, a2: "%s%s", "idle_upper_", m_szAnimExtension);
    return this->CalcSequenceIndex(this, a2: "%s%s", "run_upper_", m_szAnimExtension);
  }
  if ( (unsigned int)(m_eCurrentMainSequenceActivity - 487) <= 1 )
    return this->CalcSequenceIndex(this, a2: "%s%s", "walk_upper_", m_szAnimExtension);
  return this->CalcSequenceIndex(this, a2: "%s%s", "idle_upper_", m_szAnimExtension);
}

//------------------------------------------------------------------------------
// Address: 0x102966D0
// Name: public: virtual void CCSPlayerAnimState::DebugShowAnimState(int)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CCSPlayerAnimState::DebugShowAnimState(
        CCSPlayerAnimState *this@<ecx>,
        CStudioHdr *m_pStudioHdr@<edi>,
        int iStartLine)
{
  CBaseAnimatingOverlay *m_pOuter; // edi
  char *SequenceName; // eax
  CBaseAnimatingOverlay *v6; // edi
  char *v7; // eax
  int savedregs; // [esp+14h] [ebp+0h] BYREF

  if ( this->m_bFiring )
  {
    m_pOuter = this->m_pOuter;
    if ( m_pOuter->m_pStudioHdr == nullptr && CBaseEntity::GetModel(this: this->m_pOuter) != nullptr )
      CBaseAnimating::LockStudioHdr(this: m_pOuter);
    m_pStudioHdr = m_pOuter->m_pStudioHdr;
    if ( m_pStudioHdr == nullptr || m_pStudioHdr->m_pStudioHdr == nullptr )
      m_pStudioHdr = nullptr;
    SequenceName = GetSequenceName(pstudiohdr: m_pStudioHdr, iSequence: this->m_iFireSequence);
  }
  else
  {
    SequenceName = "[not firing]";
  }
  engine->Con_NPrintf(this: engine, a2: iStartLine, a3: "fire  : %s, cycle: %.2f\n", SequenceName, this->m_flFireCycle);
  if ( this->m_bReloading )
  {
    v6 = this->m_pOuter;
    if ( v6->m_pStudioHdr == nullptr && CBaseEntity::GetModel(this: this->m_pOuter) != nullptr )
      CBaseAnimating::LockStudioHdr(this: v6);
    m_pStudioHdr = v6->m_pStudioHdr;
    if ( m_pStudioHdr == nullptr || m_pStudioHdr->m_pStudioHdr == nullptr )
      m_pStudioHdr = nullptr;
    v7 = GetSequenceName(pstudiohdr: m_pStudioHdr, iSequence: this->m_iReloadSequence);
  }
  else
  {
    v7 = "[not reloading]";
  }
  engine->Con_NPrintf(this: engine, a2: iStartLine + 1, a3: "reload: %s, cycle: %.2f\n", v7, this->m_flReloadCycle);
  CBasePlayerAnimState::DebugShowAnimState(
    this,
    a2: (int)&savedregs,
    a3: (int)m_pStudioHdr,
    a4: (int)this,
    iStartLine: iStartLine + 2);
}

//------------------------------------------------------------------------------
// Address: 0x102967F0
// Name: public: virtual void CCSPlayerAnimState::ClearAnimationState(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSPlayerAnimState::ClearAnimationState(CCSPlayerAnimState *this)
{
  int v1; // eax

  *((_BYTE *)this - 296) = 0;
  *((_BYTE *)this - 268) = 0;
  *((_BYTE *)this - 283) = 0;
  *((_DWORD *)this - 68) = 0;
  *((_WORD *)this - 126) = 0;
  v1 = *((_DWORD *)this - 59);
  if ( v1 != 0 )
    *((_DWORD *)this - 60) = *(_DWORD *)(v1 + 6100);
  else
    *((_DWORD *)this - 60) = 0;
  CBasePlayerAnimState::ClearAnimationState(this: (CCSPlayerAnimState *)((char *)this - 300));
}

//------------------------------------------------------------------------------
// Address: 0x10296850
// Name: public: virtual bool CCSPlayerAnimState::IsThrowingGrenade(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CCSPlayerAnimState::IsThrowingGrenade(CCSPlayerAnimState *this)
{
  float z; // eax
  int v3; // eax

  if ( LOBYTE(this->m_flLastTurnTime) != 0 )
  {
    if ( g_flThrowGrenadeFraction <= *(float *)&this->m_nTurningInPlace )
      return 0;
  }
  else
  {
    z = this->m_angRender.z;
    if ( z == 0.0 )
      v3 = 0;
    else
      v3 = *(_DWORD *)(LODWORD(z) + 6100);
    if ( LODWORD(this->m_angRender.y) == v3
      && !CCSPlayerAnimState::IsOuterGrenadePrimed(this: (CCSPlayerAnimState *)((char *)this - 148)) )
    {
      return 0;
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x102968A0
// Name: public: virtual float CCSPlayerAnimState::GetCurrentMaxGroundSpeed(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CCSPlayerAnimState::GetCurrentMaxGroundSpeed(CCSPlayerAnimState *this)
{
  int SequenceActivity; // eax
  CCSPlayer *m_pPlayer; // ecx
  CBaseCombatWeapon *ActiveWeapon; // eax
  void *v6; // eax

  SequenceActivity = CBaseAnimating::GetSequenceActivity(
                       this: this->m_pOuter,
                       iSequence: this->m_pOuter->m_nSequence.m_Value);
  switch ( SequenceActivity )
  {
    case 6:
    case 29:
    case 1:
    case 30:
      return 100.0;
    case 10:
    case 31:
      m_pPlayer = this->m_pPlayer;
      if ( m_pPlayer != nullptr
        && (ActiveWeapon = CBaseCombatCharacter::GetActiveWeapon(this: m_pPlayer)) != nullptr
        && (v6 = __RTDynamicCast(
                   inptr: ActiveWeapon,
                   VfDelta: 0,
                   SrcType: &CBaseCombatWeapon `RTTI Type Descriptor',
                   TargetType: &CWeaponCSBase `RTTI Type Descriptor',
                   isReference: 0)) != nullptr )
      {
        return (*(float (__thiscall **)(void *))(*(_DWORD *)v6 + 1516))(a1: v6);
      }
      else
      {
        return 250.0;
      }
    case 12:
      return 85.0;
    default:
      return 0.0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10296930
// Name: protected: bool CCSPlayerAnimState::HandleJumping(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CCSPlayerAnimState::HandleJumping(CCSPlayerAnimState *this)
{
  if ( this->_bytes_9c[0] != 0 )
  {
    if ( this->m_bFirstJumpFrame )
    {
      CCSGameStats::IncrementStat(
        this: &CCS_GameStats,
        pPlayer: this->m_pPlayer,
        statId: CSSTAT_TOTAL_JUMPS,
        iDelta: 1,
        bPlayerOnly: false);
      this->m_bFirstJumpFrame = false;
      CBasePlayerAnimState::RestartMainSequence(this);
    }
    if ( (float)(gpGlobals->curtime - this->m_flJumpStartTime) > 0.2 && (this->m_pOuter->m_fFlags.m_Value & 1) != 0 )
    {
      this->m_flJumpLandTime = gpGlobals->curtime;
      this->_bytes_9c[0] = 0;
      CBasePlayerAnimState::RestartMainSequence(this);
    }
  }
  return this->_bytes_9c[0];
}

//------------------------------------------------------------------------------
// Address: 0x102969C0
// Name: public: virtual enum Activity CCSPlayerAnimState::CalcMainActivity(void)
// Source: json
//------------------------------------------------------------------------------
Activity __thiscall CCSPlayerAnimState::CalcMainActivity(CCSPlayerAnimState *this)
{
  Activity result; // eax
  float flOuterSpeed; // [esp+4h] [ebp-4h]
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  flOuterSpeed = CBasePlayerAnimState::GetOuterXYSpeed(this, a2: (int)&savedregs);
  if ( CCSPlayerAnimState::HandleJumping(this) )
  {
    if ( flOuterSpeed <= 0.5 )
    {
      return ACT_HOP;
    }
    else if ( flOuterSpeed <= 175.0 )
    {
      return ACT_JUMP;
    }
    else
    {
      return ACT_LEAP;
    }
  }
  else if ( (this->m_pOuter->m_fFlags.m_Value & 4) != 0
         || post_jump_crouch.m_pParent->m_Value.m_fValue > (float)(gpGlobals->curtime - this->m_flJumpLandTime) )
  {
    result = ACT_RUN_CROUCH;
    if ( flOuterSpeed <= 0.5 )
      return ACT_CROUCHIDLE;
  }
  else if ( flOuterSpeed <= 0.5 )
  {
    return ACT_IDLE;
  }
  else if ( flOuterSpeed <= 175.0 )
  {
    return ACT_WALK;
  }
  else
  {
    return ACT_RUN;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10296A90
// Name: public: virtual enum Activity CCSHostageAnimState::CalcMainActivity(void)
// Source: json
//------------------------------------------------------------------------------
Activity __thiscall CCSHostageAnimState::CalcMainActivity(CCSHostageAnimState *this)
{
  Activity result; // eax
  float flOuterSpeed; // [esp+4h] [ebp-4h]
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  flOuterSpeed = CBasePlayerAnimState::GetOuterXYSpeed(this, a2: (int)&savedregs);
  if ( CCSPlayerAnimState::HandleJumping(this) )
    return ACT_HOP;
  result = CHostage::GetLeader(this: (CHostage *)this->m_pOuter) != nullptr ? ACT_IDLE : ACT_BUSY_QUEUE;
  if ( (this->m_pOuter->m_fFlags.m_Value & 2) != 0 )
  {
    if ( flOuterSpeed <= 0.5 )
      return ACT_COVER_LOW;
    else
      return ACT_RUN_CROUCH;
  }
  else if ( flOuterSpeed > 0.5 )
  {
    result = ACT_RUN;
    if ( flOuterSpeed <= 175.0 )
      return ACT_WALK;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10296B20
// Name: private: void CCSPlayerAnimState::CheckCachedSequenceValidity(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSPlayerAnimState::CheckCachedSequenceValidity(CCSPlayerAnimState *this)
{
  int Flags; // eax
  int v3; // eax
  CBaseAnimating *v4; // eax
  CBaseAnimating *v5; // eax
  CBaseAnimating *v6; // eax
  CBaseAnimating *v7; // eax
  CBaseAnimating *v8; // eax
  CBaseAnimating *v9; // eax
  CBaseAnimating *v10; // eax
  CBaseAnimating *v11; // eax
  CBaseAnimating *v12; // eax

  Flags = ConCommandBase::GetFlags((ConCommandBase *)this);
  if ( this->m_cachedModelIndex != (*(int (__thiscall **)(int))(*(_DWORD *)Flags + 24))(a1: Flags) )
  {
    CUtlDict<int,int>::RemoveAll(this: &this->m_namedSequence);
    v3 = ConCommandBase::GetFlags((ConCommandBase *)this);
    this->m_cachedModelIndex = (*(int (__thiscall **)(int))(*(_DWORD *)v3 + 24))(a1: v3);
    memset(this->m_sequenceCache, 0xFFu, sizeof(this->m_sequenceCache));
    if ( this->m_cachedModelIndex > 0 )
    {
      v4 = (CBaseAnimating *)ConCommandBase::GetFlags((ConCommandBase *)this);
      this->m_sequenceCache[29] = CBaseAnimating::SelectWeightedSequence(this: v4, activity: ACT_HOP);
      v5 = (CBaseAnimating *)ConCommandBase::GetFlags((ConCommandBase *)this);
      this->m_sequenceCache[30] = CBaseAnimating::SelectWeightedSequence(this: v5, activity: ACT_LEAP);
      v6 = (CBaseAnimating *)ConCommandBase::GetFlags((ConCommandBase *)this);
      this->m_sequenceCache[28] = CBaseAnimating::SelectWeightedSequence(this: v6, activity: ACT_JUMP);
      v7 = (CBaseAnimating *)ConCommandBase::GetFlags((ConCommandBase *)this);
      this->m_sequenceCache[0] = CBaseAnimating::SelectWeightedSequence(this: v7, activity: ACT_IDLE);
      v8 = (CBaseAnimating *)ConCommandBase::GetFlags((ConCommandBase *)this);
      this->m_sequenceCache[11] = CBaseAnimating::SelectWeightedSequence(this: v8, activity: ACT_RUN_CROUCH);
      v9 = (CBaseAnimating *)ConCommandBase::GetFlags((ConCommandBase *)this);
      this->m_sequenceCache[44] = CBaseAnimating::SelectWeightedSequence(this: v9, activity: ACT_CROUCHIDLE);
      v10 = (CBaseAnimating *)ConCommandBase::GetFlags((ConCommandBase *)this);
      this->m_sequenceCache[9] = CBaseAnimating::SelectWeightedSequence(this: v10, activity: ACT_RUN);
      v11 = (CBaseAnimating *)ConCommandBase::GetFlags((ConCommandBase *)this);
      this->m_sequenceCache[5] = CBaseAnimating::SelectWeightedSequence(this: v11, activity: ACT_WALK);
      v12 = (CBaseAnimating *)ConCommandBase::GetFlags((ConCommandBase *)this);
      this->m_sequenceCache[0] = CBaseAnimating::SelectWeightedSequence(this: v12, activity: ACT_IDLE);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10296C50
// Name: public: virtual int CCSPlayerAnimState::SelectWeightedSequence(enum Activity)
// Source: json
//------------------------------------------------------------------------------
ICSPlayerAnimStateHelpers *__thiscall CCSPlayerAnimState::SelectWeightedSequence(
        CCSPlayerAnimState *this,
        Activity activity)
{
  ICSPlayerAnimStateHelpers *result; // eax
  CBaseAnimating *v4; // eax
  CBaseAnimating *Flags; // eax

  if ( (unsigned int)(activity - 1) > 0x2C )
  {
    Flags = (CBaseAnimating *)ConCommandBase::GetFlags((ConCommandBase *)this);
    return (ICSPlayerAnimStateHelpers *)CBaseAnimating::SelectWeightedSequence(this: Flags, activity);
  }
  else
  {
    CCSPlayerAnimState::CheckCachedSequenceValidity(this);
    result = (&this->m_pHelpers)[activity];
    if ( (int)result < 0 )
    {
      v4 = (CBaseAnimating *)ConCommandBase::GetFlags((ConCommandBase *)this);
      result = (ICSPlayerAnimStateHelpers *)CBaseAnimating::SelectWeightedSequence(this: v4, activity);
      (&this->m_pHelpers)[activity] = result;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10296CB0
// Name: public: virtual void CCSPlayerAnimState::DoAnimationEvent(enum PlayerAnimEvent_t,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSPlayerAnimState::DoAnimationEvent(CCSPlayerAnimState *this, float event, int nData)
{
  IMDLCache *v3; // ebx
  int v5; // eax
  CBaseAnimatingOverlay *v6; // ecx
  CAnimationLayer *AnimOverlay; // eax
  CAnimationLayer *v8; // esi
  CBaseAnimatingOverlay *m_pOwnerEntity; // eax
  CBaseEdict *v10; // eax
  double curtime; // st7
  CWeaponCSBase *v12; // eax
  CWeaponCSBase *v13; // edi
  int v14; // eax
  CWeaponCSBase *v15; // eax
  CWeaponCSBase *v16; // ebx
  IMDLCache *cacheCriticalSection; // [esp+Ch] [ebp-4h]

  v3 = mdlcache;
  cacheCriticalSection = mdlcache;
  mdlcache->BeginLock(this: mdlcache);
  switch ( LODWORD(event) )
  {
    case 0:
    case 1:
      this->m_flCurrentTorsoYaw = 0.0;
      v5 = CCSPlayerAnimState::CalcFireLayerSequence(
             this: (CCSPlayerAnimState *)((char *)this - 148),
             event: SLODWORD(event));
      *(_DWORD *)&this->m_bCurrentFeetYawInitialized = v5;
      LOBYTE(v5) = v5 != -1;
      LOBYTE(this->m_flCurrentFeetYaw) = v5;
      if ( (_BYTE)v5 == 0 )
        goto LABEL_28;
      if ( BYTE1(this->m_pOuter) == 0 )
        goto LABEL_28;
      this->m_flEyePitch = NAN;
      *(_DWORD *)&this->m_bCurrentFeetYawInitialized = -1;
      v6 = *((CBaseAnimatingOverlay **)this - 32);
      BYTE1(this->m_pOuter) = 0;
      this->m_flLastYaw = event;
      LOBYTE(this->m_flCurrentFeetYaw) = 0;
      AnimOverlay = CBaseAnimatingOverlay::GetAnimOverlay(this: v6, iIndex: 7);
      v8 = AnimOverlay;
      if ( AnimOverlay == nullptr )
        goto LABEL_28;
      if ( AnimOverlay->m_flWeight.m_Value != 0.0 )
      {
        m_pOwnerEntity = AnimOverlay->m_pOwnerEntity;
        if ( m_pOwnerEntity != nullptr )
        {
          if ( m_pOwnerEntity->m_Network.m_TimerEvent.m_bRegistered )
          {
            *((_BYTE *)&m_pOwnerEntity->m_Network + 76) |= 1u;
          }
          else
          {
            v10 = &m_pOwnerEntity->m_Network.m_pPev->CBaseEdict;
            if ( v10 != nullptr )
            {
              v10->m_fStateFlags |= 0x101u;
              CBaseEdict::GetChangeAccessor(this: v10)->m_iChangeInfoSerialNumber = 0;
            }
          }
        }
        v8->m_flWeight.m_Value = 0.0;
      }
      CAnimationLayer::SetOrder(this: v8, nOrder: 15);
      v3->EndLock(this: v3);
      return;
    case 3:
      LOBYTE(this->m_AnimConfig.m_flMaxBodyYawDegrees) = 1;
      LOBYTE(this->m_pOuter) = 1;
      curtime = gpGlobals->curtime;
      this->m_AnimConfig.m_LegAnimType = LEGANIM_9WAY;
      *(float *)&this->m_AnimConfig.m_bUseAimSequences = curtime;
      v3->EndLock(this: v3);
      return;
    case 4:
      v12 = (CWeaponCSBase *)(**(int (__thiscall ***)(_DWORD))LODWORD(this->m_vLastMovePose.x))(a1: LODWORD(this->m_vLastMovePose.x));
      v13 = v12;
      if ( v12 == nullptr
        || CWeaponCSBase::GetCSWpnData(this: v12)->m_WeaponType == WEAPONTYPE_SHOTGUN
        && v13->GetCSWeaponID(this: v13) != WEAPON_MAG7 )
      {
        goto LABEL_28;
      }
      v14 = CCSPlayerAnimState::CalcReloadLayerSequence(
              this: (CCSPlayerAnimState *)((char *)this - 148),
              event: PLAYERANIMEVENT_RELOAD);
      goto LABEL_18;
    case 5:
    case 6:
      this->m_flGoalFeetYaw = gpGlobals->curtime + 0.75;
      goto $LN8_34;
    case 7:
$LN8_34:
      v15 = (CWeaponCSBase *)(**(int (__thiscall ***)(_DWORD))LODWORD(this->m_vLastMovePose.x))(a1: LODWORD(this->m_vLastMovePose.x));
      v16 = v15;
      if ( v15 != nullptr
        && (CWeaponCSBase::GetCSWpnData(this: v15)->m_WeaponType != WEAPONTYPE_SHOTGUN
         || v16->GetCSWeaponID(this: v16) == WEAPON_MAG7) )
      {
        this->m_flGoalFeetYaw = 0.0;
        cacheCriticalSection->EndLock(this: cacheCriticalSection);
      }
      else
      {
        v14 = CCSPlayerAnimState::CalcReloadLayerSequence(
                this: (CCSPlayerAnimState *)((char *)this - 148),
                event: SLODWORD(event));
        v3 = cacheCriticalSection;
LABEL_18:
        LODWORD(this->m_flEyePitch) = v14;
        if ( v14 == -1 )
        {
          BYTE1(this->m_pOuter) = 0;
        }
        else
        {
          BYTE1(this->m_pOuter) = 1;
          this->m_flEyeYaw = 0.0;
        }
LABEL_28:
        v3->EndLock(this: v3);
      }
      return;
    case 8:
      *(_DWORD *)&this->m_bCurrentFeetYawInitialized = -1;
      goto LABEL_28;
    default:
      goto LABEL_28;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10296F00
// Name: protected: void CCSPlayerAnimState::UpdateLayerSequenceGeneric(class CStudioHdr __near *,int,bool __near &,float __near &,int __near &,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSPlayerAnimState::UpdateLayerSequenceGeneric(
        CCSPlayerAnimState *this,
        CStudioHdr *pStudioHdr,
        int iLayer,
        bool *bEnabled,
        float *flCurCycle,
        int *iSequence,
        bool bWaitAtEnd)
{
  double v8; // st7
  CAnimationLayer *AnimOverlay; // eax
  float v10; // xmm0_4
  CAnimationLayer *v11; // esi
  CBaseAnimatingOverlay *m_pOwnerEntity; // eax
  CBaseEdict *v13; // eax
  int v14; // edi
  CBaseAnimatingOverlay *v15; // eax
  CBaseEdict *v16; // eax
  CBaseAnimatingOverlay *v17; // eax
  CBaseEdict *v18; // eax
  float bWaitAtEnda; // [esp+24h] [ebp+1Ch]

  if ( *bEnabled && *iSequence >= 0 )
  {
    v8 = CBaseAnimating::GetSequenceCycleRate(this: this->m_pOuter, pStudioHdr, iSequence: *iSequence)
       * gpGlobals->frametime
       + *flCurCycle;
    *flCurCycle = v8;
    if ( v8 > 1.0 )
    {
      if ( !bWaitAtEnd )
      {
        *bEnabled = false;
        *iSequence = 0;
        return;
      }
      *flCurCycle = 1.0;
    }
    AnimOverlay = CBaseAnimatingOverlay::GetAnimOverlay(this: this->m_pOuter, iIndex: iLayer);
    v10 = *flCurCycle;
    v11 = AnimOverlay;
    bWaitAtEnda = *flCurCycle;
    if ( AnimOverlay->m_flCycle.m_Value != *flCurCycle )
    {
      m_pOwnerEntity = AnimOverlay->m_pOwnerEntity;
      if ( m_pOwnerEntity != nullptr )
      {
        if ( m_pOwnerEntity->m_Network.m_TimerEvent.m_bRegistered )
        {
          *((_BYTE *)&m_pOwnerEntity->m_Network + 76) |= 1u;
        }
        else
        {
          v13 = &m_pOwnerEntity->m_Network.m_pPev->CBaseEdict;
          if ( v13 != nullptr )
          {
            v13->m_fStateFlags |= 0x101u;
            v10 = bWaitAtEnda;
            CBaseEdict::GetChangeAccessor(this: v13)->m_iChangeInfoSerialNumber = 0;
          }
        }
      }
      v11->m_flCycle.m_Value = v10;
    }
    v14 = *iSequence;
    if ( v11->m_nSequence.m_Value != *iSequence )
    {
      v15 = v11->m_pOwnerEntity;
      if ( v15 != nullptr )
      {
        if ( v15->m_Network.m_TimerEvent.m_bRegistered )
        {
          *((_BYTE *)&v15->m_Network + 76) |= 1u;
        }
        else
        {
          v16 = &v15->m_Network.m_pPev->CBaseEdict;
          if ( v16 != nullptr )
          {
            v16->m_fStateFlags |= 0x101u;
            CBaseEdict::GetChangeAccessor(this: v16)->m_iChangeInfoSerialNumber = 0;
          }
        }
      }
      v11->m_nSequence.m_Value = v14;
    }
    v11->m_flPlaybackRate = 1.0;
    if ( v11->m_flWeight.m_Value != 1.0 )
    {
      v17 = v11->m_pOwnerEntity;
      if ( v17 != nullptr )
      {
        if ( v17->m_Network.m_TimerEvent.m_bRegistered )
        {
          *((_BYTE *)&v17->m_Network + 76) |= 1u;
        }
        else
        {
          v18 = &v17->m_Network.m_pPev->CBaseEdict;
          if ( v18 != nullptr )
          {
            v18->m_fStateFlags |= 0x101u;
            CBaseEdict::GetChangeAccessor(this: v18)->m_iChangeInfoSerialNumber = 0;
          }
        }
      }
      v11->m_flWeight.m_Value = 1.0;
    }
    CAnimationLayer::SetOrder(this: v11, nOrder: iLayer);
    v11->m_fFlags |= 1u;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10297070
// Name: protected: void CCSPlayerAnimState::ComputeGrenadeSequence(class CStudioHdr __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSPlayerAnimState::ComputeGrenadeSequence(CCSPlayerAnimState *this, CStudioHdr *pStudioHdr)
{
  CCSPlayer *m_pPlayer; // ecx
  CBaseCombatWeapon *ActiveWeapon; // eax
  CCSPlayer *v5; // eax
  CCSPlayer *v6; // eax
  int m_Value; // eax
  bool v8; // bl
  float v9; // xmm0_4
  float *p_m_flGrenadeCycle; // ebx
  CCSPlayer *v11; // eax
  int v12; // eax
  int v13; // eax
  bool *p_m_bThrowingGrenade; // [esp+4h] [ebp-Ch]
  bool *bEnabled; // [esp+8h] [ebp-8h]
  bool bThrowPending; // [esp+Fh] [ebp-1h]

  p_m_bThrowingGrenade = &this->m_bThrowingGrenade;
  if ( this->m_bThrowingGrenade )
  {
    CCSPlayerAnimState::UpdateLayerSequenceGeneric(
      this,
      pStudioHdr,
      iLayer: 8,
      bEnabled: &this->m_bThrowingGrenade,
      flCurCycle: &this->m_flGrenadeCycle,
      iSequence: &this->m_iGrenadeSequence,
      bWaitAtEnd: false);
  }
  else
  {
    m_pPlayer = this->m_pPlayer;
    if ( m_pPlayer == nullptr
      || (ActiveWeapon = CBaseCombatCharacter::GetActiveWeapon(this: m_pPlayer),
          __RTDynamicCast(
            inptr: ActiveWeapon,
            VfDelta: 0,
            SrcType: &CBaseCombatWeapon `RTTI Type Descriptor',
            TargetType: &CBaseCSGrenade `RTTI Type Descriptor',
            isReference: 0) != nullptr) )
    {
      v6 = this->m_pPlayer;
      if ( v6 != nullptr )
        m_Value = v6->m_iThrowGrenadeCounter.m_Value;
      else
        m_Value = 0;
      v8 = this->m_iLastThrowGrenadeCounter != m_Value;
      bThrowPending = v8;
      if ( CCSPlayerAnimState::IsOuterGrenadePrimed(this) || v8 )
      {
        bEnabled = &this->m_bPrimingGrenade;
        if ( !this->m_bPrimingGrenade )
        {
          if ( CBasePlayerAnimState::TimeSinceLastAnimationStateClear(this) >= 0.40000001 )
            v9 = 0.0;
          else
            v9 = 1.0;
          this->m_flGrenadeCycle = v9;
          this->m_bPrimingGrenade = true;
        }
        p_m_flGrenadeCycle = &this->m_flGrenadeCycle;
        this->m_iGrenadeSequence = CCSPlayerAnimState::CalcGrenadePrimeSequence(this);
        CCSPlayerAnimState::UpdateLayerSequenceGeneric(
          this,
          pStudioHdr,
          iLayer: 8,
          bEnabled,
          flCurCycle: &this->m_flGrenadeCycle,
          iSequence: &this->m_iGrenadeSequence,
          bWaitAtEnd: true);
        if ( bThrowPending && *p_m_flGrenadeCycle == 1.0 )
        {
          v11 = this->m_pPlayer;
          if ( v11 != nullptr )
            v12 = v11->m_iThrowGrenadeCounter.m_Value;
          else
            v12 = 0;
          this->m_iLastThrowGrenadeCounter = v12;
          v13 = CCSPlayerAnimState::CalcGrenadeThrowSequence(this);
          this->m_iGrenadeSequence = v13;
          if ( v13 != -1 )
          {
            *p_m_bThrowingGrenade = true;
            *bEnabled = false;
            *p_m_flGrenadeCycle = 0.0;
          }
        }
      }
      else
      {
        this->m_bPrimingGrenade = false;
      }
    }
    else
    {
      v5 = this->m_pPlayer;
      if ( v5 != nullptr )
        this->m_iLastThrowGrenadeCounter = v5->m_iThrowGrenadeCounter.m_Value;
      else
        this->m_iLastThrowGrenadeCounter = 0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10297210
// Name: public: virtual void CCSPlayerAnimState::ClearAnimationLayers(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSPlayerAnimState::ClearAnimationLayers(CCSPlayerAnimState *this)
{
  CBaseAnimatingOverlay *m_pOuter; // ecx
  CBaseAnimatingOverlay *v3; // ecx
  int i; // edi
  CAnimationLayer *AnimOverlay; // eax
  CAnimationLayer *v6; // esi
  CBaseAnimatingOverlay *m_pOwnerEntity; // eax
  CBaseEdict *v8; // eax

  m_pOuter = this->m_pOuter;
  if ( m_pOuter != nullptr )
  {
    CBaseAnimatingOverlay::SetNumAnimOverlays(this: m_pOuter, num: 9);
    v3 = this->m_pOuter;
    for ( i = 0; i < v3->m_AnimOverlay.m_Size; ++i )
    {
      AnimOverlay = CBaseAnimatingOverlay::GetAnimOverlay(this: v3, iIndex: i);
      v6 = AnimOverlay;
      if ( AnimOverlay->m_nOrder.m_Value != 15 )
      {
        m_pOwnerEntity = AnimOverlay->m_pOwnerEntity;
        if ( m_pOwnerEntity != nullptr )
        {
          if ( m_pOwnerEntity->m_Network.m_TimerEvent.m_bRegistered )
          {
            *((_BYTE *)&m_pOwnerEntity->m_Network + 76) |= 1u;
          }
          else
          {
            v8 = &m_pOwnerEntity->m_Network.m_pPev->CBaseEdict;
            if ( v8 != nullptr )
            {
              v8->m_fStateFlags |= 0x101u;
              CBaseEdict::GetChangeAccessor(this: v8)->m_iChangeInfoSerialNumber = 0;
            }
          }
        }
        v6->m_nOrder.m_Value = 15;
      }
      CBaseAnimatingOverlay::GetAnimOverlay(this: this->m_pOuter, iIndex: i)->m_fFlags = 0;
      v3 = this->m_pOuter;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102972A0
// Name: public: CCSPlayerAnimState::CCSPlayerAnimState(void)
// Source: json
//------------------------------------------------------------------------------
CCSPlayerAnimState *__thiscall CCSPlayerAnimState::CCSPlayerAnimState(CCSPlayerAnimState *this, int a2)
{
  int v3; // eax
  int v4; // edx

  if ( a2 != 0 )
  {
    *(_DWORD *)this->gap4 = &CCSHostageAnimState::`vbtable'{for `CBasePlayerAnimState'};
    *(_DWORD *)&this->gap94[4] = &CCSPlayerAnimState::`vbtable'{for `ICSPlayerAnimState'};
    *(_DWORD *)&this->gap1C0[4] = &IPlayerAnimState::`vftable';
  }
  CBasePlayerAnimState::CBasePlayerAnimState(this, a2: 0);
  v3 = *(_DWORD *)&this->gap94[4];
  *(_DWORD *)this->gap94 = &ICSPlayerAnimState::`vftable'{for `ICSPlayerAnimState'};
  *(_DWORD *)&this->gap94[*(_DWORD *)(v3 + 4) + 4] = &ICSPlayerAnimState::`vftable'{for `IPlayerAnimState'};
  v4 = *(_DWORD *)this->gap4;
  this->__vftable = (CCSPlayerAnimState_vtbl *)&CCSPlayerAnimState::`vftable'{for `CBasePlayerAnimState'};
  *(_DWORD *)this->gap94 = &CCSPlayerAnimState::`vftable'{for `ICSPlayerAnimState'};
  *(_DWORD *)&this->gap4[*(_DWORD *)(v4 + 4)] = &CCSPlayerAnimState::`vftable'{for `IPlayerAnimState'};
  *(CCSPlayerAnimState_vtbl **)((char *)&this->__vftable + *(_DWORD *)(*(_DWORD *)this->gap4 + 4)) = (CCSPlayerAnimState_vtbl *)(*(_DWORD *)(*(_DWORD *)this->gap4 + 4) - 448);
  this->m_namedSequence.m_Elements.m_Tree.m_LessFunc.m_LessFunc = nullptr;
  this->m_namedSequence.m_Elements.m_Tree.m_Elements.m_pMemory = nullptr;
  this->m_namedSequence.m_Elements.m_Tree.m_Elements.m_nAllocationCount = 0;
  this->m_namedSequence.m_Elements.m_Tree.m_Elements.m_nGrowSize = 0;
  this->m_namedSequence.m_Elements.m_Tree.m_Root = -1;
  this->m_namedSequence.m_Elements.m_Tree.m_NumElements = 0;
  this->m_namedSequence.m_Elements.m_Tree.m_FirstFree = -1;
  this->m_namedSequence.m_Elements.m_Tree.m_LastAlloc.index = -1;
  this->m_namedSequence.m_Elements.m_Tree.m_pElements = this->m_namedSequence.m_Elements.m_Tree.m_Elements.m_pMemory;
  if ( this->m_namedSequence.m_Elements.m_Tree.m_LessFunc.m_LessFunc == nullptr )
    this->m_namedSequence.m_Elements.m_Tree.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))CaselessStringLessThan;
  this->m_iReloadSequence = -1;
  this->m_iFireSequence = -1;
  this->m_iGrenadeSequence = -1;
  this->m_cachedModelIndex = -1;
  this->m_pOuter = nullptr;
  this->_bytes_9c[0] = 0;
  *(_WORD *)&this->m_bFirstJumpFrame = 0;
  this->m_bFiring = false;
  *(_WORD *)&this->m_bThrowingGrenade = 0;
  this->m_iLastThrowGrenadeCounter = 0;
  this->m_pPlayer = nullptr;
  this->m_pHelpers = nullptr;
  *(_QWORD *)&this->m_flJumpLandTime = 0;
  this->m_flReloadCycle = 0.0;
  this->m_flReloadHoldEndTime = 0.0;
  this->m_flFireCycle = 0.0;
  this->m_delayedFire = PLAYERANIMEVENT_COUNT;
  this->m_flGrenadeCycle = 0.0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10297480
// Name: public: virtual void CCSPlayerAnimState::ComputeSequences(class CStudioHdr __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSPlayerAnimState::ComputeSequences(CCSPlayerAnimState *this, CStudioHdr *pStudioHdr)
{
  PlayerAnimEvent_t m_delayedFire; // eax

  CBasePlayerAnimState::ComputeSequences(this, pStudioHdr);
  m_delayedFire = this->m_delayedFire;
  if ( m_delayedFire != PLAYERANIMEVENT_COUNT )
  {
    (**(void (__thiscall ***)(_BYTE *, PlayerAnimEvent_t, _DWORD))this->gap94)(
      a1: this->gap94,
      a2: m_delayedFire,
      a3: 0);
    this->m_delayedFire = PLAYERANIMEVENT_COUNT;
  }
  CCSPlayerAnimState::UpdateLayerSequenceGeneric(
    this,
    pStudioHdr,
    iLayer: 6,
    bEnabled: &this->m_bFiring,
    flCurCycle: &this->m_flFireCycle,
    iSequence: &this->m_iFireSequence,
    bWaitAtEnd: false);
  CCSPlayerAnimState::UpdateLayerSequenceGeneric(
    this,
    pStudioHdr,
    iLayer: 7,
    bEnabled: &this->m_bReloading,
    flCurCycle: &this->m_flReloadCycle,
    iSequence: &this->m_iReloadSequence,
    bWaitAtEnd: this->m_flReloadHoldEndTime > gpGlobals->curtime);
  if ( !this->m_bReloading )
    this->m_flReloadHoldEndTime = 0.0;
  CCSPlayerAnimState::ComputeGrenadeSequence(this, pStudioHdr);
}

//------------------------------------------------------------------------------
// Address: 0x10297540
// Name: class ICSPlayerAnimState __near * CreatePlayerAnimState(class CBaseAnimatingOverlay __near *,class ICSPlayerAnimStateHelpers __near *,enum LegAnimType_t,bool)
// Source: json
//------------------------------------------------------------------------------
ICSPlayerAnimState *__cdecl CreatePlayerAnimState(
        CBaseAnimatingOverlay *pEntity,
        ICSPlayerAnimStateHelpers *pHelpers,
        LegAnimType_t legAnimType,
        bool bUseAimSequences)
{
  CCSPlayerAnimState *v4; // eax
  CCSPlayerAnimState *v5; // esi
  CCSPlayer *v6; // eax
  CModAnimConfig config; // [esp+8h] [ebp-Ch] BYREF

  v4 = (CCSPlayerAnimState *)operator new(nSize: 0x1C8u);
  if ( v4 != nullptr )
    v5 = CCSPlayerAnimState::CCSPlayerAnimState(this: v4, a2: 1);
  else
    v5 = nullptr;
  config.m_flMaxBodyYawDegrees = 90.0;
  config.m_LegAnimType = legAnimType;
  config.m_bUseAimSequences = bUseAimSequences;
  if ( pEntity != nullptr && pEntity->IsPlayer(this: pEntity) )
    v6 = (CCSPlayer *)__RTDynamicCast(
                        inptr: pEntity,
                        VfDelta: 0,
                        SrcType: &CBaseEntity `RTTI Type Descriptor',
                        TargetType: &CCSPlayer `RTTI Type Descriptor',
                        isReference: 0);
  else
    v6 = nullptr;
  v5->m_pHelpers = pHelpers;
  v5->m_pPlayer = v6;
  CBasePlayerAnimState::Init(this: v5, pPlayer: pEntity, &config);
  return (ICSPlayerAnimState *)v5->gap94;
}

//------------------------------------------------------------------------------
// Address: 0x102975E0
// Name: public: virtual int CCSHostageAnimState::SelectWeightedSequence(enum Activity)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CCSHostageAnimState::SelectWeightedSequence(CCSHostageAnimState *this, Activity activity)
{
  CBaseAnimating *Flags; // eax

  Flags = (CBaseAnimating *)ConCommandBase::GetFlags((ConCommandBase *)this);
  return CBaseAnimating::SelectWeightedSequence(this: Flags, activity);
}

//------------------------------------------------------------------------------
// Address: 0x10297600
// Name: class ICSPlayerAnimState __near * CreateHostageAnimState(class CBaseAnimatingOverlay __near *,class ICSPlayerAnimStateHelpers __near *,enum LegAnimType_t,bool)
// Source: json
//------------------------------------------------------------------------------
ICSPlayerAnimState *__cdecl CreateHostageAnimState(
        CBaseAnimatingOverlay *pEntity,
        ICSPlayerAnimStateHelpers *pHelpers,
        LegAnimType_t legAnimType,
        bool bUseAimSequences)
{
  CCSPlayerAnimState *v4; // eax
  CCSPlayerAnimState *v5; // esi
  int v6; // eax
  CCSPlayer *v7; // eax
  CModAnimConfig config; // [esp+8h] [ebp-Ch] BYREF

  v4 = (CCSPlayerAnimState *)operator new(nSize: 0x1C8u);
  v5 = v4;
  if ( v4 != nullptr )
  {
    *(_DWORD *)v4->gap4 = &CCSHostageAnimState::`vbtable'{for `CBasePlayerAnimState'};
    *(_DWORD *)&v4->gap94[4] = &CCSPlayerAnimState::`vbtable'{for `ICSPlayerAnimState'};
    *(_DWORD *)&v4->gap1C0[4] = &IPlayerAnimState::`vftable';
    CCSPlayerAnimState::CCSPlayerAnimState(this: v4, a2: 0);
    v6 = *(_DWORD *)v5->gap4;
    v5->__vftable = (CCSPlayerAnimState_vtbl *)&CCSHostageAnimState::`vftable'{for `CBasePlayerAnimState'};
    *(_DWORD *)v5->gap94 = &CCSHostageAnimState::`vftable'{for `ICSPlayerAnimState'};
    *(_DWORD *)&v5->gap4[*(_DWORD *)(v6 + 4)] = &CCSHostageAnimState::`vftable'{for `IPlayerAnimState'};
    *(CCSPlayerAnimState_vtbl **)((char *)&v5->__vftable + *(_DWORD *)(*(_DWORD *)v5->gap4 + 4)) = (CCSPlayerAnimState_vtbl *)(*(_DWORD *)(*(_DWORD *)v5->gap4 + 4) - 448);
  }
  else
  {
    v5 = nullptr;
  }
  config.m_flMaxBodyYawDegrees = 90.0;
  config.m_LegAnimType = legAnimType;
  config.m_bUseAimSequences = bUseAimSequences;
  if ( pEntity != nullptr && pEntity->IsPlayer(this: pEntity) )
    v7 = (CCSPlayer *)__RTDynamicCast(
                        inptr: pEntity,
                        VfDelta: 0,
                        SrcType: &CBaseEntity `RTTI Type Descriptor',
                        TargetType: &CCSPlayer `RTTI Type Descriptor',
                        isReference: 0);
  else
    v7 = nullptr;
  v5->m_pHelpers = pHelpers;
  v5->m_pPlayer = v7;
  CBasePlayerAnimState::Init(this: v5, pPlayer: pEntity, &config);
  return (ICSPlayerAnimState *)v5->gap94;
}

//------------------------------------------------------------------------------
// Address: 0x102976F0
// Name: protected: virtual int CCSPlayerAnimState::CalcSequenceIndex(char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
int CCSPlayerAnimState::CalcSequenceIndex(CCSPlayerAnimState *this, const char *pBaseName, ...)
{
  int v2; // eax
  CBaseAnimating *Flags; // eax
  int elem; // esi
  char szFullName[512]; // [esp+8h] [ebp-208h] BYREF
  CUtlMap<char const *,int,int>::Node_t search; // [esp+208h] [ebp-8h] BYREF
  va_list params; // [esp+220h] [ebp+10h] BYREF

  va_start(params, pBaseName);
  CCSPlayerAnimState::CheckCachedSequenceValidity(this);
  V_vsnprintf(pDest: szFullName, maxLen: 512, pFormat: pBaseName, params);
  search.key = szFullName;
  v2 = CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Find(
         this: &this->m_namedSequence.m_Elements.m_Tree,
         &search);
  if ( v2 == -1 )
  {
    Flags = (CBaseAnimating *)ConCommandBase::GetFlags((ConCommandBase *)this);
    elem = CBaseAnimating::LookupSequence(this: Flags, label: szFullName);
    search.elem = elem;
    CUtlDict<int,int>::Insert(this: &this->m_namedSequence, pName: szFullName, element: &search.elem);
  }
  else
  {
    elem = this->m_namedSequence.m_Elements.m_Tree.m_Elements.m_pMemory[v2].m_Data.elem;
  }
  if ( elem != -1 )
    return elem;
  if ( (_S2_245 & 1) == 0 )
  {
    _S2_245 |= 1u;
    dict_0.m_Elements.m_Tree.m_Elements.m_pMemory = nullptr;
    dict_0.m_Elements.m_Tree.m_Elements.m_nAllocationCount = 0;
    dict_0.m_Elements.m_Tree.m_Elements.m_nGrowSize = 0;
    dict_0.m_Elements.m_Tree.m_Root = -1;
    dict_0.m_Elements.m_Tree.m_NumElements = 0;
    dict_0.m_Elements.m_Tree.m_FirstFree = -1;
    dict_0.m_Elements.m_Tree.m_LastAlloc.index = -1;
    dict_0.m_Elements.m_Tree.m_pElements = nullptr;
    dict_0.m_Elements.m_Tree.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))CaselessStringLessThan;
    atexit(func: CCSPlayerAnimState::CalcSequenceIndex_::_10_::_dynamic_atexit_destructor_for__dict__);
  }
  search.key = szFullName;
  if ( CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Find(
         this: &dict_0.m_Elements.m_Tree,
         &search) == -1 )
  {
    search.elem = 0;
    CUtlDict<int,int>::Insert(this: &dict_0, pName: szFullName, element: &search.elem);
    _Warning(a1: "CalcSequenceIndex: can't find '%s'.\n", szFullName);
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10419630
// Name: _CBasePlayerAnimState::CalcSequenceIndex_::_5_::_dynamic_atexit_destructor_for__dict__
// Source: json
//------------------------------------------------------------------------------
void __cdecl CBasePlayerAnimState::CalcSequenceIndex_::_5_::_dynamic_atexit_destructor_for__dict__()
{
  CUtlDict<int,int>::RemoveAll(this: &dict);
  CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::~CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>(this: &dict.m_Elements.m_Tree);
}

//------------------------------------------------------------------------------
// Address: 0x1041FE00
// Name: _CCSPlayerAnimState::CalcSequenceIndex_::_10_::_dynamic_atexit_destructor_for__dict__
// Source: json
//------------------------------------------------------------------------------
void __cdecl CCSPlayerAnimState::CalcSequenceIndex_::_10_::_dynamic_atexit_destructor_for__dict__()
{
  CUtlDict<int,int>::RemoveAll(this: &dict_0);
  CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::~CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>(this: &dict_0.m_Elements.m_Tree);
}

//------------------------------------------------------------------------------
// Address: 0x10419650
// Name: _DataMapInit_CBaseAchievement__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CBaseAchievement__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_81);
}

//------------------------------------------------------------------------------
// Address: 0x10419660
// Name: _DataMapInit_CFailableAchievement__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CFailableAchievement__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_82);
}

//------------------------------------------------------------------------------
// Address: 0x10419670
// Name: _dynamic_atexit_destructor_for__ai_sequence_debug__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__ai_sequence_debug__()
{
  ConVar::~ConVar(this: &ai_sequence_debug);
}

//------------------------------------------------------------------------------
// Address: 0x1041FE20
// Name: _dynamic_atexit_destructor_for__g_PlayerMove__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_PlayerMove__()
{
  g_PlayerMove.__vftable = (CCSPlayerMove_vtbl *)&CPlayerMove::`vftable';
}

} // namespace server
