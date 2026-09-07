// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/shared/baseplayer_shared.cpp
// Functions: 74
// ============================================================

#include "game\shared\baseplayer_shared.h"

//------------------------------------------------------------------------------
// Address: 0x10014D20
// Name: void UTIL_TraceHull(class Vector const __near &,class Vector const __near &,class Vector const __near &,class Vector const __near &,unsigned int,class ITraceFilter __near *,class CGameTrace __near *)
// Source: json
//------------------------------------------------------------------------------
void __usercall UTIL_TraceHull(
        int a1@<ebp>,
        int a2@<esi>,
        const Vector *vecAbsStart,
        const Vector *vecAbsEnd,
        const Vector *hullMin,
        const Vector *hullMax,
        unsigned int mask,
        ITraceFilter *pFilter,
        CGameTrace *ptr)
{
  _BYTE v9[12]; // [esp+24h] [ebp-5Ch] BYREF
  Ray_t ray; // [esp+30h] [ebp-50h]
  _UNKNOWN *retaddr; // [esp+80h] [ebp+0h]

  *(_DWORD *)&ray.m_IsRay = a1;
  *(_DWORD *)(&ray.m_IsSwept + 3) = retaddr;
  ray.m_Extents.y = 0.0;
  Ray_t::Init(this: (Ray_t *)v9, start: vecAbsStart, end: vecAbsEnd, mins: hullMin, maxs: hullMax);
  ((void (__thiscall *)(IEngineTrace *, _BYTE *, unsigned int, ITraceFilter *, CGameTrace *, int))enginetrace->TraceRay)(
    a1: enginetrace,
    a2: v9,
    a3: mask,
    a4: pFilter,
    a5: ptr,
    a6: a2);
  if ( r_visualizetraces.m_pParent != nullptr && r_visualizetraces.m_pParent->m_Value.m_nValue != 0 )
    DebugDrawLine(vecAbsStart: &ptr->startpos, vecAbsEnd: &ptr->endpos, r: 255, g: 255, b: 0, test: 1, duration: -1.0);
}

//------------------------------------------------------------------------------
// Address: 0x10017FC0
// Name: public: bool color32_s::operator!=(struct color32_s const __near &)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall color32_s::operator!=(color32_s *this, const color32_s *other)
{
  return this->r != other->r || this->g != other->g || this->b != other->b || this->a != other->a;
}

//------------------------------------------------------------------------------
// Address: 0x10018000
// Name: public: float C_BasePlayer::GetTimeBase(void)const
// Source: json
//------------------------------------------------------------------------------
double __thiscall C_BasePlayer::GetTimeBase(C_BasePlayer *this)
{
  return (double)this->m_nTickBase * *(float *)(gpGlobals.m_Index + 28);
}

//------------------------------------------------------------------------------
// Address: 0x10018010
// Name: public: virtual class QAngle const __near & C_BasePlayer::LocalEyeAngles(void)
// Source: json
//------------------------------------------------------------------------------
const QAngle *__thiscall C_BasePlayer::LocalEyeAngles(C_BasePlayer *this)
{
  return &this->pl.v_angle;
}

//------------------------------------------------------------------------------
// Address: 0x10018020
// Name: public: virtual struct surfacedata_t __near * C_BasePlayer::GetFootstepSurface(class Vector const __near &,char const __near *)
// Source: json
//------------------------------------------------------------------------------
surfacedata_t *__thiscall C_BasePlayer::GetFootstepSurface(
        C_BasePlayer *this,
        const Vector *origin,
        const char *surfaceName)
{
  IPhysicsSurfaceProps_vtbl *v3; // esi
  int v4; // eax

  v3 = physprops->__vftable;
  v4 = physprops->GetSurfaceIndex(this: physprops, a2: surfaceName);
  return v3->GetSurfaceData(this: physprops, a2: v4);
}

//------------------------------------------------------------------------------
// Address: 0x10018050
// Name: public: struct surfacedata_t __near * C_BasePlayer::GetLadderSurface(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
surfacedata_t *__thiscall C_BasePlayer::GetLadderSurface(C_BasePlayer *this, const Vector *origin)
{
  return this->GetFootstepSurface(this, a2: origin, a3: "ladder");
}

//------------------------------------------------------------------------------
// Address: 0x10018070
// Name: public: void C_BasePlayer::UpdateButtonState(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BasePlayer::UpdateButtonState(C_BasePlayer *this, int nUserCmdButtonMask)
{
  int v2; // edx

  this->m_afButtonLast = this->m_nButtons;
  v2 = nUserCmdButtonMask ^ this->m_afButtonLast;
  this->m_nButtons = nUserCmdButtonMask;
  this->m_afButtonPressed = nUserCmdButtonMask & v2;
  this->m_afButtonReleased = v2 & ~nUserCmdButtonMask;
}

//------------------------------------------------------------------------------
// Address: 0x100180B0
// Name: public: void C_BasePlayer::SetAnimationExtension(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BasePlayer::SetAnimationExtension(C_BasePlayer *this, const char *pExtension)
{
  V_strncpy(pDest: this->m_szAnimExtension, pSrc: pExtension, maxLen: 32);
}

//------------------------------------------------------------------------------
// Address: 0x100180D0
// Name: public: virtual bool C_BasePlayer::Weapon_Switch(class C_BaseCombatWeapon __near *,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall C_BasePlayer::Weapon_Switch(C_BasePlayer *this, C_BaseCombatWeapon *pWeapon, int viewmodelindex)
{
  C_BaseCombatWeapon *v4; // edi
  C_BasePlayer_vtbl *v5; // ebx
  C_BaseCombatWeapon *v6; // eax
  C_BasePlayer_vtbl *v7; // ebx
  int v8; // eax
  C_BaseViewModel *ViewModel; // eax

  v4 = this->GetActiveWeapon(this);
  if ( !C_BaseCombatCharacter::Weapon_Switch(this, pWeapon, viewmodelindex) )
    return 0;
  if ( v4 != nullptr )
  {
    v5 = this->C_BaseCombatCharacter::C_BaseFlex::C_BaseAnimatingOverlay::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable;
    v6 = this->GetActiveWeapon(this);
    if ( v5->Weapon_ShouldSetLast(this, a2: v4, a3: v6) )
    {
      v7 = this->C_BaseCombatCharacter::C_BaseFlex::C_BaseAnimatingOverlay::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable;
      v8 = (int)v4->GetLastWeapon(this: v4);
      v7->Weapon_SetLast(this, a2: (C_BaseCombatWeapon *)v8);
    }
  }
  ViewModel = C_BasePlayer::GetViewModel(this, index: viewmodelindex);
  if ( ViewModel != nullptr )
    ViewModel->RemoveEffects(this: ViewModel, a2: 32);
  C_BasePlayer::ResetAutoaim(this);
  this->OnSwitchWeapons(this, a2: pWeapon);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10018180
// Name: public: virtual void C_BasePlayer::AbortReload(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BasePlayer::AbortReload(C_BasePlayer *this)
{
  C_BaseCombatWeapon *v2; // eax

  if ( this->GetActiveWeapon(this) != nullptr )
  {
    v2 = this->GetActiveWeapon(this);
    v2->AbortReload(this: v2);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100181B0
// Name: public: virtual bool C_BasePlayer::Weapon_ShouldSelectItem(class C_BaseCombatWeapon __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall C_BasePlayer::Weapon_ShouldSelectItem(C_BasePlayer *this, C_BaseCombatWeapon *pWeapon)
{
  return pWeapon != this->GetActiveWeapon(this);
}

//------------------------------------------------------------------------------
// Address: 0x100181D0
// Name: public: virtual void C_BasePlayer::SelectItem(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BasePlayer::SelectItem(C_BasePlayer *this, const char *pstr, int iSubType)
{
  C_BaseCombatWeapon *v4; // edi
  C_BaseCombatWeapon *v5; // eax

  if ( pstr != nullptr )
  {
    v4 = this->Weapon_OwnsThisType(this, a2: pstr, a3: iSubType);
    if ( v4 != nullptr && this->GetObserverMode(this) == 0 && this->Weapon_ShouldSelectItem(this, a2: v4) )
    {
      if ( this->GetActiveWeapon(this) != nullptr )
      {
        v5 = this->GetActiveWeapon(this);
        if ( !v5->CanHolster(this: v5) )
          return;
        C_BasePlayer::ResetAutoaim(this);
      }
      this->Weapon_Switch(this, a2: v4, a3: 0);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10018260
// Name: public: virtual void C_BasePlayer::CalcViewModelView(class Vector const __near &,class QAngle const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BasePlayer::CalcViewModelView(C_BasePlayer *this, const Vector *eyeOrigin, const QAngle *eyeAngles)
{
  int i; // esi
  C_BaseViewModel *ViewModel; // eax

  for ( i = 0; i < 2; ++i )
  {
    ViewModel = C_BasePlayer::GetViewModel(this, index: i);
    if ( ViewModel != nullptr )
      ViewModel->CalcViewModelView(this: ViewModel, a2: this, a3: eyeOrigin, a4: eyeAngles);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100182A0
// Name: protected: virtual void C_BasePlayer::CalcObserverView(class Vector __near &,class QAngle __near &,float __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BasePlayer::CalcObserverView(C_BasePlayer *this, Vector *eyeOrigin, QAngle *eyeAngles, float *fov)
{
  switch ( this->GetObserverMode(this) )
  {
    case 1:
      this->CalcDeathCamView(this, a2: eyeOrigin, a3: eyeAngles, a4: fov);
      break;
    case 2:
      this->CalcFreezeCamView(this, a2: eyeOrigin, a3: eyeAngles, a4: fov);
      break;
    case 3:
    case 6:
      this->CalcRoamingView(this, a2: eyeOrigin, a3: eyeAngles, a4: fov);
      break;
    case 4:
      C_BasePlayer::CalcInEyeCamView(this, eyeOrigin, eyeAngles, fov);
      break;
    case 5:
      C_BasePlayer::CalcChaseCamView(this, eyeOrigin, eyeAngles, fov);
      break;
    default:
      return;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10018360
// Name: public: virtual void C_BasePlayer::DoMuzzleFlash(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BasePlayer::DoMuzzleFlash(C_BasePlayer *this)
{
  int i; // esi
  C_BaseViewModel *ViewModel; // eax

  for ( i = 0; i < 2; ++i )
  {
    ViewModel = C_BasePlayer::GetViewModel(this, index: i);
    if ( ViewModel != nullptr )
      ViewModel->DoMuzzleFlash(this: ViewModel);
  }
  C_BaseCombatCharacter::DoMuzzleFlash(this);
}

//------------------------------------------------------------------------------
// Address: 0x10018390
// Name: public: float C_BasePlayer::GetFOVDistanceAdjustFactor(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall C_BasePlayer::GetFOVDistanceAdjustFactor(C_BasePlayer *this)
{
  double v2; // st7
  float localFOV; // [esp+4h] [ebp-8h]
  float defaultFOV; // [esp+8h] [ebp-4h]

  defaultFOV = (float)this->GetDefaultFOV(this);
  v2 = ((double (__thiscall *)(C_BasePlayer *))this->GetFOV)(a1: this);
  localFOV = v2;
  if ( localFOV == defaultFOV || defaultFOV < 0.001 )
    return 1.0;
  else
    return v2 / defaultFOV;
}

//------------------------------------------------------------------------------
// Address: 0x100183F0
// Name: public: virtual void C_BasePlayer::MakeTracer(class Vector const __near &,class CGameTrace const __near &,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BasePlayer::MakeTracer(
        C_BasePlayer *this,
        const Vector *vecTracerSrc,
        const CGameTrace *tr,
        int iTracerType)
{
  C_BaseCombatWeapon *v5; // eax

  if ( this->GetActiveWeapon(this) != nullptr )
  {
    v5 = this->GetActiveWeapon(this);
    v5->MakeTracer(this: v5, a2: vecTracerSrc, a3: tr, a4: iTracerType);
  }
  else
  {
    C_BaseEntity::MakeTracer(this, vecTracerSrc, tr, iTracerType);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10018440
// Name: public: virtual char const __near * C_BasePlayer::GetTracerType(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall C_BasePlayer::GetTracerType(C_BasePlayer *this)
{
  C_BaseCombatWeapon *v2; // eax

  if ( this->GetActiveWeapon(this) == nullptr )
    return (const char *)C_TEBSPDecal::YouForgotToImplementOrDeclareClientClass((vgui::CTreeViewListControl *)this);
  v2 = this->GetActiveWeapon(this);
  return v2->GetTracerType(this: v2);
}

//------------------------------------------------------------------------------
// Address: 0x10018470
// Name: public: virtual void C_BasePlayer::SetPlayerUnderwater(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BasePlayer::SetPlayerUnderwater(C_BasePlayer *this, bool state)
{
  if ( this->m_bPlayerUnderwater != state )
  {
    this->m_bPlayerUnderwater = state;
    if ( state )
      C_BaseEntity::EmitSound(this, soundname: "Player.AmbientUnderWater", soundtime: 0.0, duration: nullptr);
    else
      C_BaseEntity::StopSound(this, soundname: "Player.AmbientUnderWater");
  }
}

//------------------------------------------------------------------------------
// Address: 0x100184B0
// Name: public: class Vector const __near & C_BasePlayer::GetPreviouslyPredictedOrigin(void)const
// Source: json
//------------------------------------------------------------------------------
const Vector *__thiscall C_BasePlayer::GetPreviouslyPredictedOrigin(C_BasePlayer *this)
{
  return &this->m_vecPreviouslyPredictedOrigin;
}

//------------------------------------------------------------------------------
// Address: 0x100184C0
// Name: public: void C_BasePlayer::IncrementEFNoInterpParity(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BasePlayer::IncrementEFNoInterpParity(C_BasePlayer *this)
{
  if ( *(_DWORD *)(gpGlobals.m_Index + 20) != 1 )
    this->m_ubEFNoInterpParity = (this->m_ubEFNoInterpParity + 1) & 3;
}

//------------------------------------------------------------------------------
// Address: 0x10018500
// Name: public: void C_BasePlayer::ForceButtons(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BasePlayer::ForceButtons(C_BasePlayer *this, int nButtons)
{
  this->m_afButtonForced |= nButtons;
}

//------------------------------------------------------------------------------
// Address: 0x10018510
// Name: public: void C_BasePlayer::UnforceButtons(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BasePlayer::UnforceButtons(C_BasePlayer *this, int nButtons)
{
  this->m_afButtonForced &= ~nButtons;
}

//------------------------------------------------------------------------------
// Address: 0x10018530
// Name: public: void C_BasePlayer::SetVCollisionState(class Vector const __near &,class Vector const __near &,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BasePlayer::SetVCollisionState(
        C_BasePlayer *this,
        const Vector *vecAbsOrigin,
        const Vector *vecAbsVelocity,
        int collisionState)
{
  IPhysicsObject *m_pShadowStand; // ecx

  m_pShadowStand = this->m_pShadowStand;
  this->m_vphysicsCollisionState = collisionState;
  if ( m_pShadowStand != nullptr )
  {
    if ( collisionState != 0 )
    {
      if ( collisionState == 1 )
      {
        this->m_pShadowCrouch->SetPosition(this: this->m_pShadowCrouch, a2: vecAbsOrigin, a3: &vec3_angle, a4: true);
        this->m_pShadowCrouch->SetVelocity(this: this->m_pShadowCrouch, a2: vecAbsVelocity, a3: nullptr);
        this->m_pShadowStand->EnableCollisions(this: this->m_pShadowStand, a2: false);
        this->m_pPhysicsController->SetObject(this: this->m_pPhysicsController, a2: this->m_pShadowCrouch);
        C_BaseEntity::VPhysicsSwapObject(this, pSwap: this->m_pShadowCrouch);
        this->m_pShadowCrouch->EnableCollisions(this: this->m_pShadowCrouch, a2: true);
      }
      else if ( collisionState == 2 )
      {
        this->m_pShadowCrouch->EnableCollisions(this: this->m_pShadowCrouch, a2: false);
        this->m_pShadowStand->EnableCollisions(this: this->m_pShadowStand, a2: false);
      }
    }
    else
    {
      m_pShadowStand->SetPosition(this: m_pShadowStand, a2: vecAbsOrigin, a3: &vec3_angle, a4: true);
      this->m_pShadowStand->SetVelocity(this: this->m_pShadowStand, a2: vecAbsVelocity, a3: nullptr);
      this->m_pShadowCrouch->EnableCollisions(this: this->m_pShadowCrouch, a2: false);
      this->m_pPhysicsController->SetObject(this: this->m_pPhysicsController, a2: this->m_pShadowStand);
      C_BaseEntity::VPhysicsSwapObject(this, pSwap: this->m_pShadowStand);
      this->m_pShadowStand->EnableCollisions(this: this->m_pShadowStand, a2: true);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10018670
// Name: public: virtual char const __near * C_BasePlayer::GetPlayerModelName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall C_BasePlayer::GetPlayerModelName(C_BasePlayer *this)
{
  return "models/player.mdl";
}

//------------------------------------------------------------------------------
// Address: 0x10018680
// Name: public: float C_BasePlayer::GetAirTime(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall C_BasePlayer::GetAirTime(C_BasePlayer *this)
{
  float m_flTimeLastTouchedGround; // xmm0_4
  float v2; // xmm1_4

  m_flTimeLastTouchedGround = this->m_flTimeLastTouchedGround;
  v2 = 0.0;
  if ( m_flTimeLastTouchedGround != 0.0 )
    return (float)(*(float *)(gpGlobals.m_Index + 12) - m_flTimeLastTouchedGround);
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x10018700
// Name: public: virtual float C_BasePlayer::GetPlayerMaxSpeed(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall C_BasePlayer::GetPlayerMaxSpeed(C_BasePlayer *this)
{
  float m_flMaxspeed; // xmm0_4
  float fMaxSpeed; // [esp+0h] [ebp-4h]

  m_flMaxspeed = this->m_flMaxspeed;
  fMaxSpeed = sv_maxspeed.m_pParent->m_Value.m_fValue;
  if ( m_flMaxspeed > 0.0 && sv_maxspeed.m_pParent->m_Value.m_fValue > m_flMaxspeed )
    return this->m_flMaxspeed;
  return fMaxSpeed;
}

//------------------------------------------------------------------------------
// Address: 0x10018740
// Name: public: virtual void C_BasePlayer::ItemPreFrame(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BasePlayer::ItemPreFrame(C_BasePlayer *this)
{
  C_BaseCombatWeapon *v2; // ebx
  int i; // edi
  C_BaseCombatWeapon *v4; // eax

  this->PlayerUse(this);
  v2 = this->GetActiveWeapon(this);
  for ( i = 0; i < 64; ++i )
  {
    v4 = this->GetWeapon(this, a2: i);
    if ( v4 != nullptr && v2 != v4 )
      v4->ItemHolsterFrame(this: v4);
  }
  if ( this->m_flNextAttack <= *(float *)(gpGlobals.m_Index + 12) && v2 != nullptr && v2->IsPredicted(this: v2) )
    v2->ItemPreFrame(this: v2);
}

//------------------------------------------------------------------------------
// Address: 0x100187D0
// Name: public: virtual class Vector const C_BasePlayer::GetPlayerMins(void)const
// Source: json
//------------------------------------------------------------------------------
const Vector *__thiscall C_BasePlayer::GetPlayerMins(C_BasePlayer *this, const Vector *result)
{
  const CViewVectors *v3; // eax
  __int64 v4; // xmm0_8
  float z; // eax
  int v7; // eax
  float v8; // edx
  int v9; // eax
  __int64 v10; // xmm0_8
  float v11; // eax

  if ( this->GetObserverMode(this) != 0 )
  {
    v3 = g_pGameRules->GetViewVectors(this: g_pGameRules);
    v4 = *(_QWORD *)&v3->m_vObsHullMin.x;
    z = v3->m_vObsHullMin.z;
    *(_QWORD *)&result->x = v4;
    result->z = z;
    return result;
  }
  else
  {
    if ( (this->m_fFlags & 2) != 0 )
    {
      v7 = ((int (*)(void))g_pGameRules->GetViewVectors)();
      v8 = *(float *)(v7 + 44);
      *(_QWORD *)&result->x = *(_QWORD *)(v7 + 36);
      result->z = v8;
    }
    else
    {
      v9 = ((int (*)(void))g_pGameRules->GetViewVectors)();
      v10 = *(_QWORD *)(v9 + 12);
      v11 = *(float *)(v9 + 20);
      *(_QWORD *)&result->x = v10;
      result->z = v11;
    }
    return result;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10018860
// Name: public: virtual class Vector const C_BasePlayer::GetPlayerMaxs(void)const
// Source: json
//------------------------------------------------------------------------------
const Vector *__thiscall C_BasePlayer::GetPlayerMaxs(C_BasePlayer *this, const Vector *result)
{
  const CViewVectors *v3; // eax
  __int64 v4; // xmm0_8
  float z; // eax
  int v7; // eax
  float v8; // edx
  int v9; // eax
  __int64 v10; // xmm0_8
  float v11; // eax

  if ( this->GetObserverMode(this) != 0 )
  {
    v3 = g_pGameRules->GetViewVectors(this: g_pGameRules);
    v4 = *(_QWORD *)&v3->m_vObsHullMax.x;
    z = v3->m_vObsHullMax.z;
    *(_QWORD *)&result->x = v4;
    result->z = z;
    return result;
  }
  else
  {
    if ( (this->m_fFlags & 2) != 0 )
    {
      v7 = ((int (*)(void))g_pGameRules->GetViewVectors)();
      v8 = *(float *)(v7 + 56);
      *(_QWORD *)&result->x = *(_QWORD *)(v7 + 48);
      result->z = v8;
    }
    else
    {
      v9 = ((int (*)(void))g_pGameRules->GetViewVectors)();
      v10 = *(_QWORD *)(v9 + 24);
      v11 = *(float *)(v9 + 32);
      *(_QWORD *)&result->x = v10;
      result->z = v11;
    }
    return result;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100188F0
// Name: public: virtual void C_BasePlayer::UpdateCollisionBounds(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BasePlayer::UpdateCollisionBounds(C_BasePlayer *this)
{
  int (*GetViewVectors)(void); // edx
  const Vector *v3; // esi
  const CViewVectors *v4; // eax
  const Vector *v5; // esi
  const CViewVectors *v6; // eax

  GetViewVectors = (int (*)(void))g_pGameRules->GetViewVectors;
  if ( (this->m_fFlags & 2) != 0 )
  {
    v3 = (const Vector *)(GetViewVectors() + 48);
    v4 = g_pGameRules->GetViewVectors(this: g_pGameRules);
    CCollisionProperty::SetCollisionBounds(this: &this->m_Collision, mins: &v4->m_vDuckHullMin, maxs: v3);
  }
  else
  {
    v5 = (const Vector *)(GetViewVectors() + 24);
    v6 = g_pGameRules->GetViewVectors(this: g_pGameRules);
    CCollisionProperty::SetCollisionBounds(this: &this->m_Collision, mins: &v6->m_vHullMin, maxs: v5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10018960
// Name: public: virtual void C_BasePlayer::UpdateStepSound(struct surfacedata_t __near *,class Vector const __near &,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __userpurge C_BasePlayer::UpdateStepSound(
        C_BasePlayer *this@<ecx>,
        float a2@<ebp>,
        int a3@<edi>,
        int a4@<esi>,
        surfacedata_t *psurface,
        const Vector *vecOrigin,
        const Vector *vecVelocity)
{
  float m_flStepSoundTime; // xmm0_4
  float v9; // xmm0_4
  unsigned __int8 m_MoveType; // cl
  float v12; // xmm0_4
  __int128 v13; // xmm1
  void (__thiscall *GetStepSoundVelocities)(C_BasePlayer *, float *, float *); // eax
  __int128 v15; // xmm0
  float y; // xmm1_4
  float z; // xmm2_4
  const Vector *(__thiscall *GetPlayerMaxs)(C_BasePlayer *, const Vector *); // edx
  int v19; // eax
  const Vector *(__thiscall *GetPlayerMins)(C_BasePlayer *, const Vector *); // edx
  int v21; // eax
  surfacedata_t *LadderSurface; // edi
  void (__thiscall *SetStepSoundTime)(C_BasePlayer *, stepsoundtimes_t, bool); // edx
  float v24; // xmm0_4
  int v25; // ecx
  IPhysicsSurfaceProps_vtbl *v26; // edi
  int v27; // eax
  int v28; // eax
  void (__thiscall *v29)(C_BasePlayer *, stepsoundtimes_t, bool); // edx
  IPhysicsSurfaceProps_vtbl *v30; // edi
  int v31; // eax
  double v32; // xmm0_8
  void (__thiscall *v33)(C_BasePlayer *, stepsoundtimes_t, bool); // edx
  double v34; // xmm0_8
  int v35; // [esp+2Ch] [ebp-6Ch]
  int v37; // [esp+30h] [ebp-68h]
  int v38; // [esp+34h] [ebp-64h]
  __int128 v39; // [esp+3Ch] [ebp-5Ch] BYREF
  __int128 v40; // [esp+4Ch] [ebp-4Ch] BYREF
  Vector v41; // [esp+60h] [ebp-38h] BYREF
  Vector feet; // [esp+6Ch] [ebp-2Ch] BYREF
  Vector knee; // [esp+78h] [ebp-20h] BYREF
  _BYTE velrun_3[5]; // [esp+87h] [ebp-11h] OVERLAPPED
  float fvol; // [esp+8Ch] [ebp-Ch]
  void *v46; // [esp+90h] [ebp-8h] OVERLAPPED
  void *retaddr; // [esp+98h] [ebp+0h]

  fvol = a2;
  v46 = retaddr;
  m_flStepSoundTime = this->m_flStepSoundTime;
  if ( m_flStepSoundTime > 0.0 )
  {
    v9 = m_flStepSoundTime - (float)(*(float *)(gpGlobals.m_Index + 16) * 1000.0);
    this->m_flStepSoundTime = v9;
    if ( v9 < 0.0 )
      this->m_flStepSoundTime = 0.0;
  }
  if ( this->m_flStepSoundTime <= 0.0 && (this->m_fFlags & 0xC0) == 0 )
  {
    m_MoveType = this->m_MoveType;
    if ( m_MoveType != 8 && m_MoveType != 10 && sv_footsteps.m_pParent->m_Value.m_fValue != 0.0 )
    {
      v12 = vecVelocity->x * vecVelocity->x;
      v13 = 0;
      *(float *)&v13 = fsqrt(
                         (float)((float)(vecVelocity->y * vecVelocity->y) + (float)(vecVelocity->z * vecVelocity->z))
                       + v12);
      v39 = v13;
      GetStepSoundVelocities = this->GetStepSoundVelocities;
      *(float *)&v13 = (float)(vecVelocity->y * vecVelocity->y) + v12;
      v15 = 0;
      *(float *)&v15 = fsqrt(*(float *)&v13);
      v40 = v15;
      velrun_3[4] = m_MoveType == 9;
      GetStepSoundVelocities(this, a2: &knee.y, a3: &knee.x);
      if ( *(float *)&v39 >= knee.y
        && (velrun_3[4] != 0 || (this->m_fFlags & 1) != 0 && *(float *)&v15 > 0.000099999997) )
      {
        velrun_3[0] = knee.x > *(float *)&v39;
        y = vecOrigin->y;
        z = vecOrigin->z;
        GetPlayerMaxs = this->GetPlayerMaxs;
        feet.x = vecOrigin->x;
        feet.y = y;
        feet.z = z;
        v41 = feet;
        v19 = ((int (__thiscall *)(C_BasePlayer *, char *, int, int))GetPlayerMaxs)(
                a1: this,
                a2: (char *)&v40 + 4,
                a3,
                a4);
        GetPlayerMins = this->GetPlayerMins;
        knee.z = *(float *)(v19 + 8);
        v21 = (int)GetPlayerMins(this, result: (const Vector *)((char *)&v39 + 4));
        feet.z = (float)(knee.z - *(float *)(v21 + 8)) * 0.2 + vecOrigin->z;
        if ( velrun_3[4] != 0 )
        {
          LadderSurface = C_BasePlayer::GetLadderSurface(this, origin: vecOrigin);
          SetStepSoundTime = this->SetStepSoundTime;
          knee.z = 0.5;
          SetStepSoundTime(this, a2: STEPSOUNDTIME_ON_LADDER, a3: *(_DWORD *)velrun_3);
          v24 = knee.z;
        }
        else if ( (enginetrace->GetPointContents(this: enginetrace, a2: &feet, a3: -1, a4: nullptr) & 0x4030) != 0 )
        {
          if ( iSkipStep == 0 )
          {
            iSkipStep = 1;
            return;
          }
          v25 = iSkipStep++;
          if ( v25 == 3 )
            iSkipStep = 0;
          v26 = physprops->__vftable;
          v27 = ((int (__thiscall *)(IPhysicsSurfaceProps *, const char *, int, int, int))physprops->GetSurfaceIndex)(
                  a1: physprops,
                  a2: "wade",
                  a3: v35,
                  a4: v37,
                  a5: v38);
          v28 = (int)v26->GetSurfaceData(this: physprops, a2: v27);
          v29 = this->SetStepSoundTime;
          LadderSurface = (surfacedata_t *)v28;
          knee.z = 0.64999998;
          v29(this, a2: STEPSOUNDTIME_WATER_KNEE, a3: *(_DWORD *)velrun_3);
          v24 = knee.z;
        }
        else if ( this->m_nWaterLevel == 1 )
        {
          v30 = physprops->__vftable;
          v31 = ((int (__thiscall *)(IPhysicsSurfaceProps *, const char *, int, int, int))physprops->GetSurfaceIndex)(
                  a1: physprops,
                  a2: "water",
                  a3: v35,
                  a4: v37,
                  a5: v38);
          LadderSurface = v30->GetSurfaceData(this: physprops, a2: v31);
          if ( velrun_3[0] != 0 )
            v32 = 0.2;
          else
            v32 = 0.5;
          v33 = this->SetStepSoundTime;
          knee.z = v32;
          v33(this, a2: STEPSOUNDTIME_WATER_FOOT, a3: *(_DWORD *)velrun_3);
          v24 = knee.z;
        }
        else
        {
          LadderSurface = psurface;
          if ( psurface == nullptr )
            return;
          ((void (__thiscall *)(C_BasePlayer *, _DWORD, _DWORD, int, int, int))this->SetStepSoundTime)(
            a1: this,
            a2: 0,
            a3: *(_DWORD *)velrun_3,
            a4: v35,
            a5: v37,
            a6: v38);
          switch ( psurface->game.material )
          {
            case 'D':
              if ( velrun_3[0] != 0 )
                v34 = 0.25;
              else
                v34 = 0.55;
              break;
            case 'V':
              if ( velrun_3[0] != 0 )
                v34 = 0.4;
              else
                v34 = 0.7;
              break;
            default:
              if ( velrun_3[0] != 0 )
                v34 = 0.2;
              else
                v34 = 0.5;
              break;
          }
          v24 = v34;
        }
        if ( (this->m_fFlags & 2) != 0 )
          v24 = v24 * 0.65;
        ((void (__thiscall *)(C_BasePlayer *, Vector *, surfacedata_t *, _DWORD, _DWORD))this->PlayStepSound)(
          a1: this,
          a2: &v41,
          a3: LadderSurface,
          a4: LODWORD(v24),
          a5: 0);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10018D70
// Name: public: virtual void C_BasePlayer::GetStepSoundVelocities(float __near *,float __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BasePlayer::GetStepSoundVelocities(C_BasePlayer *this, float *velwalk, float *velrun)
{
  if ( (this->m_fFlags & 2) != 0 || this->m_MoveType == 9 )
  {
    *velwalk = 60.0;
    *velrun = 80.0;
  }
  else
  {
    *velwalk = 90.0;
    *velrun = 220.0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10018DD0
// Name: public: virtual void C_BasePlayer::SetStepSoundTime(enum stepsoundtimes_t,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BasePlayer::SetStepSoundTime(C_BasePlayer *this, stepsoundtimes_t iStepSoundTime, bool bWalking)
{
  float v3; // xmm0_4

  switch ( iStepSoundTime )
  {
    case STEPSOUNDTIME_NORMAL:
    case STEPSOUNDTIME_WATER_FOOT:
      v3 = (float)(bWalking ? 400 : 300);
      goto LABEL_5;
    case STEPSOUNDTIME_ON_LADDER:
      v3 = 350.0;
      goto LABEL_5;
    case STEPSOUNDTIME_WATER_KNEE:
      v3 = 600.0;
LABEL_5:
      this->m_flStepSoundTime = v3;
      break;
    default:
      break;
  }
  if ( (this->m_fFlags & 2) != 0 || this->m_MoveType == 9 )
    this->m_flStepSoundTime = this->m_flStepSoundTime + 100.0;
}

//------------------------------------------------------------------------------
// Address: 0x10018E60
// Name: public: virtual void C_BasePlayer::SelectLastItem(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BasePlayer::SelectLastItem(C_BasePlayer *this)
{
  unsigned int m_Index; // ecx
  C_BaseCombatWeapon *v3; // eax
  unsigned int v4; // eax
  IHandleEntity *m_pEntity; // ecx
  C_BaseEntity *v6; // esi
  C_BasePlayer_vtbl *v7; // edi
  const char *Classname; // eax
  int v9; // [esp-Ch] [ebp-10h]

  m_Index = this->m_hLastWeapon.m_Index;
  if ( m_Index != -1
    && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index)
    && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity != nullptr )
  {
    if ( this->GetActiveWeapon(this) == nullptr || (v3 = this->GetActiveWeapon(this), v3->CanHolster(this: v3)) )
    {
      v4 = this->m_hLastWeapon.m_Index;
      if ( v4 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v4].m_SerialNumber != HIWORD(v4) )
        m_pEntity = nullptr;
      else
        m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)v4].m_pEntity;
      if ( v4 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v4].m_SerialNumber != HIWORD(v4) )
        v6 = nullptr;
      else
        v6 = (C_BaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v4].m_pEntity;
      v7 = this->C_BaseCombatCharacter::C_BaseFlex::C_BaseAnimatingOverlay::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable;
      v9 = (int)m_pEntity->__vftable[74].GetRefEHandle(this: m_pEntity);
      Classname = C_BaseEntity::GetClassname(this: v6);
      v7->SelectItem(this, a2: Classname, a3: v9);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10018F40
// Name: public: virtual float C_BasePlayer::CalcRoll(class QAngle const __near &,class Vector const __near &,float,float)
// Source: json
//------------------------------------------------------------------------------
double __thiscall C_BasePlayer::CalcRoll(
        C_BasePlayer *this,
        const QAngle *angles,
        const Vector *velocity,
        float rollangle,
        float rollspeed)
{
  float v5; // xmm0_4
  int v6; // eax
  float v7; // xmm0_4
  Vector forward; // [esp+0h] [ebp-24h] BYREF
  Vector up; // [esp+Ch] [ebp-18h] BYREF
  Vector right; // [esp+18h] [ebp-Ch] BYREF
  float sign; // [esp+2Ch] [ebp+8h]

  AngleVectors(angles, &forward, &right, &up);
  v5 = (float)((float)(velocity->y * right.y) + (float)(velocity->x * right.x)) + (float)(velocity->z * right.z);
  if ( v5 >= 0.0 )
    v6 = 1;
  else
    v6 = -1;
  LODWORD(v7) = LODWORD(v5) & _mask__AbsFloat_;
  sign = (float)v6;
  if ( rollspeed <= v7 )
    return sign * rollangle;
  else
    return sign * (float)((float)(v7 * rollangle) / rollspeed);
}

//------------------------------------------------------------------------------
// Address: 0x10018FF0
// Name: public: virtual int C_BasePlayer::GetDefaultFOV(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall C_BasePlayer::GetDefaultFOV(C_BasePlayer *this)
{
  C_BaseEntity *v2; // edi
  int m_iDefaultFOV; // esi

  if ( this->GetObserverMode(this) == 4 )
  {
    v2 = this->GetObserverTarget(this);
    if ( v2 != nullptr
      && v2->IsPlayer(this: v2)
      && v2->IClientEntity::IClientUnknown::IHandleEntity::__vftable[1].GetTeamNumber(this: v2) == 0 )
    {
      return v2->IClientEntity::IClientUnknown::IHandleEntity::__vftable[1].GetHealth(this: v2);
    }
  }
  m_iDefaultFOV = this->m_iDefaultFOV;
  if ( m_iDefaultFOV != 0 )
    return m_iDefaultFOV;
  else
    return g_pGameRules->DefaultFOV(this: g_pGameRules);
}

//------------------------------------------------------------------------------
// Address: 0x10019060
// Name: public: virtual void C_BasePlayer::AvoidPhysicsProps(class CUserCmd __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge C_BasePlayer::AvoidPhysicsProps(
        C_BasePlayer *this@<ecx>,
        C_BaseEntity *a2@<ebx>,
        int a3@<edi>,
        CUserCmd *pCmd)
{
  if ( this->m_MoveType != 0
    && this->m_MoveType != 8
    && this->m_MoveType != 10
    && this->GetObserverMode(this) == 0
    && this->IsAlive(this) )
  {
    AvoidPushawayProps(a1: a2, a2: a3, a3: (int)this, pPlayer: this, pCmd);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100190B0
// Name: public: void C_BasePlayer::UpdateUnderwaterState(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BasePlayer::UpdateUnderwaterState(C_BasePlayer *this)
{
  if ( this->m_nWaterLevel == 3 )
  {
    if ( !this->m_bPlayerUnderwater )
      this->SetPlayerUnderwater(this, a2: true);
  }
  else
  {
    if ( this->m_bPlayerUnderwater )
      this->SetPlayerUnderwater(this, a2: false);
    if ( this->m_nWaterLevel != 0 )
    {
      if ( (this->m_fFlags & 0x400) == 0 )
        C_BaseEntity::AddFlag(this, flags: 1024);
    }
    else if ( (this->m_fFlags & 0x400) != 0 )
    {
      C_BaseEntity::RemoveFlag(this, flagsToRemove: 1024);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10019130
// Name: public: void C_BasePlayer::SetPreviouslyPredictedOrigin(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BasePlayer::SetPreviouslyPredictedOrigin(C_BasePlayer *this, const Vector *vecAbsOrigin)
{
  this->m_vecPreviouslyPredictedOrigin = *vecAbsOrigin;
}

//------------------------------------------------------------------------------
// Address: 0x10019160
// Name: public: class IPhysicsObject __near * C_BasePlayer::GetGroundVPhysics(void)
// Source: json
//------------------------------------------------------------------------------
IPhysicsObject *__thiscall C_BasePlayer::GetGroundVPhysics(C_BasePlayer *this)
{
  C_BaseEntity *GroundEntity; // eax
  IPhysicsObject *m_pPhysicsObject; // esi

  GroundEntity = C_BaseEntity::GetGroundEntity(this);
  if ( GroundEntity != nullptr
    && GroundEntity->m_MoveType == 6
    && (m_pPhysicsObject = GroundEntity->m_pPhysicsObject) != nullptr
    && m_pPhysicsObject->IsMoveable(this: m_pPhysicsObject) )
  {
    return m_pPhysicsObject;
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100191A0
// Name: public: bool C_BasePlayer::IsRideablePhysics(class IPhysicsObject __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall C_BasePlayer::IsRideablePhysics(C_BasePlayer *this, IPhysicsObject *pPhysics)
{
  IPhysicsObject *m_pPhysicsObject; // esi
  double v3; // st7
  bool result; // al
  float pPhysicsa; // [esp+8h] [ebp+8h]

  result = false;
  if ( pPhysics != nullptr )
  {
    m_pPhysicsObject = this->m_pPhysicsObject;
    pPhysicsa = pPhysics->GetMass(this: pPhysics);
    v3 = ((double (__thiscall *)(IPhysicsObject *))m_pPhysicsObject->GetMass)(a1: m_pPhysicsObject);
    if ( pPhysicsa > v3 + v3 )
      return true;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100191E0
// Name: public: void C_BasePlayer::UpdateVPhysicsPosition(class Vector const __near &,class Vector const __near &,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BasePlayer::UpdateVPhysicsPosition(
        C_BasePlayer *this,
        const Vector *position,
        const Vector *velocity,
        float secondsToArrival)
{
  C_BaseEntity *GroundEntity; // eax
  IPhysicsObject *m_pPhysicsObject; // esi
  IPhysicsObject *v7; // ebx
  double v8; // st7
  int onground; // [esp+14h] [ebp-8h]
  float v10; // [esp+18h] [ebp-4h]

  if ( this->m_pPhysicsController != nullptr )
  {
    LOBYTE(onground) = this->m_fFlags & 1;
    GroundEntity = C_BaseEntity::GetGroundEntity(this);
    if ( GroundEntity == nullptr
      || GroundEntity->m_MoveType != 6
      || (m_pPhysicsObject = GroundEntity->m_pPhysicsObject) == nullptr
      || !m_pPhysicsObject->IsMoveable(this: m_pPhysicsObject)
      || (v7 = this->m_pPhysicsObject,
          v10 = m_pPhysicsObject->GetMass(this: m_pPhysicsObject),
          v8 = ((double (__thiscall *)(IPhysicsObject *))v7->GetMass)(a1: v7),
          v10 <= v8 + v8) )
    {
      m_pPhysicsObject = nullptr;
    }
    ((void (__stdcall *)(const Vector *, const Vector *, _DWORD, int, IPhysicsObject *))this->m_pPhysicsController->Update)(
      a1: position,
      a2: velocity,
      a3: LODWORD(secondsToArrival),
      a4: onground,
      a5: m_pPhysicsObject);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10019290
// Name: public: void C_BasePlayer::UpdatePhysicsShadowToPosition(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BasePlayer::UpdatePhysicsShadowToPosition(C_BasePlayer *this, const Vector *vecAbsOrigin)
{
  C_BasePlayer::UpdateVPhysicsPosition(
    this,
    position: vecAbsOrigin,
    velocity: &vec3_origin,
    secondsToArrival: *(float *)(gpGlobals.m_Index + 16));
}

//------------------------------------------------------------------------------
// Address: 0x100192C0
// Name: void UTIL_TraceHull(class Vector const __near &,class Vector const __near &,class Vector const __near &,class Vector const __near &,unsigned int,class IHandleEntity const __near *,int,class CGameTrace __near *)
// Source: json
//------------------------------------------------------------------------------
void __usercall UTIL_TraceHull(
        const IHandleEntity *a1@<ebp>,
        int a2@<esi>,
        const Vector *vecAbsStart,
        const Vector *vecAbsEnd,
        const Vector *hullMin,
        const Vector *hullMax,
        unsigned int mask,
        const IHandleEntity *ignore,
        int collisionGroup,
        CGameTrace *ptr)
{
  _BYTE v10[12]; // [esp+24h] [ebp-6Ch] BYREF
  Ray_t ray; // [esp+30h] [ebp-60h] BYREF
  CTraceFilterSimple traceFilter; // [esp+80h] [ebp-10h]
  int retaddr; // [esp+90h] [ebp+0h]

  traceFilter.m_pPassEnt = a1;
  traceFilter.m_collisionGroup = retaddr;
  ray.m_Extents.y = 0.0;
  Ray_t::Init(this: (Ray_t *)v10, start: vecAbsStart, end: vecAbsEnd, mins: hullMin, maxs: hullMax);
  CTraceFilterSimple::CTraceFilterSimple(
    this: (CTraceFilterSimple *)&ray.m_IsRay,
    passedict: ignore,
    collisionGroup,
    pExtraShouldHitFunc: nullptr);
  ((void (__thiscall *)(IEngineTrace *, _BYTE *, unsigned int, bool *, CGameTrace *, int))enginetrace->TraceRay)(
    a1: enginetrace,
    a2: v10,
    a3: mask,
    a4: &ray.m_IsRay,
    a5: ptr,
    a6: a2);
  if ( r_visualizetraces.m_pParent != nullptr && r_visualizetraces.m_pParent->m_Value.m_nValue != 0 )
    DebugDrawLine(vecAbsStart: &ptr->startpos, vecAbsEnd: &ptr->endpos, r: 255, g: 255, b: 0, test: 1, duration: -1.0);
}

//------------------------------------------------------------------------------
// Address: 0x10019370
// Name: public: class C_BaseEntity __near * C_BasePlayer::GetViewEntity(void)const
// Source: json
//------------------------------------------------------------------------------
C_BaseEntity *__thiscall C_BasePlayer::GetViewEntity(C_BasePlayer *this)
{
  unsigned int m_Index; // ecx

  m_Index = this->m_hViewEntity.m_Index;
  if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    return nullptr;
  else
    return (C_BaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
}

//------------------------------------------------------------------------------
// Address: 0x100193A0
// Name: public: bool C_BasePlayer::IsInAVehicle(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall C_BasePlayer::IsInAVehicle(C_BasePlayer *this)
{
  unsigned int m_Index; // ecx

  m_Index = this->m_hVehicle.m_Index;
  return m_Index != -1
      && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index)
      && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10019400
// Name: public: bool C_BasePlayer::UsingStandardWeaponsInVehicle(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall C_BasePlayer::UsingStandardWeaponsInVehicle(C_BasePlayer *this)
{
  unsigned int m_Index; // ecx
  CEntInfo *v3; // eax
  int v4; // esi
  int v6; // eax

  m_Index = this->m_hVehicle.m_Index;
  if ( m_Index == -1 )
    return true;
  v3 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index];
  if ( g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    return true;
  if ( v3->m_pEntity == nullptr )
    return true;
  v4 = ((int (__thiscall *)(IHandleEntity *))v3->m_pEntity->__vftable[31].dtr_IHandleEntity)(a1: v3->m_pEntity);
  if ( v4 == 0 )
    return true;
  v6 = (*(int (__thiscall **)(int, C_BasePlayer *))(*(_DWORD *)v4 + 4))(a1: v4, a2: this);
  return (*(unsigned __int8 (__thiscall **)(int, int))(*(_DWORD *)v4 + 12))(a1: v4, a2: v6) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x10019470
// Name: public: virtual void C_BasePlayer::ItemPostFrame(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BasePlayer::ItemPostFrame(C_BasePlayer *this)
{
  C_BasePlayer_vtbl *v2; // edi
  const QAngle *v3; // eax
  int v4; // eax
  unsigned int m_Index; // eax
  IHandleEntity *m_pEntity; // ecx
  unsigned int v7; // ecx
  IHandleEntity *v8; // eax
  int v9; // edi
  bool v10; // bl
  unsigned int v11; // ecx
  IHandleEntity *v12; // eax
  unsigned int v13; // ecx
  C_BaseCombatWeapon *(__thiscall *GetActiveWeapon)(C_BaseCombatCharacter *); // eax
  C_BaseCombatWeapon *v15; // eax
  C_BaseCombatWeapon *v16; // eax
  C_BaseCombatWeapon *v17; // eax
  _BYTE v18[12]; // [esp+8h] [ebp-Ch] BYREF

  v2 = this->C_BaseCombatCharacter::C_BaseFlex::C_BaseAnimatingOverlay::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable;
  v3 = this->EyeAngles(this);
  v4 = ((int (__thiscall *)(C_BasePlayer *, _BYTE *, const QAngle *))this->EyePosition)(a1: this, a2: v18, a3: v3);
  ((void (__thiscall *)(C_BasePlayer *, int))v2->CalcViewModelView)(a1: this, a2: v4);
  m_Index = this->m_hVehicle.m_Index;
  if ( m_Index == -1 )
    goto LABEL_19;
  if ( g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    goto LABEL_19;
  m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
  if ( m_pEntity == nullptr
    || ((int (__thiscall *)(IHandleEntity *))m_pEntity->__vftable[31].dtr_IHandleEntity)(a1: m_pEntity) == 0 )
  {
    goto LABEL_19;
  }
  v7 = this->m_hVehicle.m_Index;
  if ( v7 != -1
    && g_pEntityList->m_EntPtrArray[(unsigned __int16)v7].m_SerialNumber == HIWORD(v7)
    && (v8 = g_pEntityList->m_EntPtrArray[(unsigned __int16)v7].m_pEntity) != nullptr )
  {
    v9 = ((int (__thiscall *)(IHandleEntity *))v8->__vftable[31].dtr_IHandleEntity)(a1: v8);
  }
  else
  {
    v9 = 0;
  }
  v10 = C_BasePlayer::UsingStandardWeaponsInVehicle(this);
  if ( (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v9 + 44))(a1: v9) != 0 )
    (*(void (__thiscall **)(int, C_BasePlayer *))(*(_DWORD *)v9 + 28))(a1: v9, a2: this);
  if ( v10 )
  {
    v11 = this->m_hVehicle.m_Index;
    if ( v11 != -1 && g_pEntityList->m_EntPtrArray[(unsigned __int16)v11].m_SerialNumber == HIWORD(v11) )
    {
      v12 = g_pEntityList->m_EntPtrArray[(unsigned __int16)v11].m_pEntity;
      if ( v12 != nullptr && ((int (__thiscall *)(IHandleEntity *))v12->__vftable[31].dtr_IHandleEntity)(a1: v12) != 0 )
      {
LABEL_19:
        v13 = this->m_hUseEntity.m_Index;
        if ( v13 == -1
          || g_pEntityList->m_EntPtrArray[(unsigned __int16)v13].m_SerialNumber != HIWORD(v13)
          || g_pEntityList->m_EntPtrArray[(unsigned __int16)v13].m_pEntity == nullptr )
        {
          GetActiveWeapon = this->GetActiveWeapon;
          if ( this->m_flNextAttack <= *(float *)(gpGlobals.m_Index + 12) )
          {
            if ( (int)GetActiveWeapon(this) != 0
              && (!C_BasePlayer::IsInAVehicle(this) || C_BasePlayer::UsingStandardWeaponsInVehicle(this)) )
            {
              v16 = this->GetActiveWeapon(this);
              if ( v16->IsPredicted(this: v16) )
              {
                v17 = this->GetActiveWeapon(this);
                v17->ItemPostFrame(this: v17);
              }
            }
          }
          else if ( (int)GetActiveWeapon(this) != 0 )
          {
            v15 = this->GetActiveWeapon(this);
            v15->ItemBusyFrame(this: v15);
            this->m_nImpulse = 0;
            return;
          }
          this->m_nImpulse = 0;
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10019680
// Name: public: virtual class QAngle const __near & C_BasePlayer::EyeAngles(void)
// Source: json
//------------------------------------------------------------------------------
const QAngle *__thiscall C_BasePlayer::EyeAngles(C_BasePlayer *this)
{
  unsigned int m_Index; // eax
  C_BaseEntity **v2; // edx
  C_BaseEntity *v3; // esi
  unsigned int v4; // edx
  int v5; // eax
  CEntInfo *v6; // esi
  unsigned int v7; // edx
  int v8; // eax
  bool v9; // zf
  CEntInfo *v10; // eax
  const matrix3x4_t *p_m_rgflCoordinateFrame; // esi
  matrix3x4_t eyesToWorld; // [esp+8h] [ebp-60h] BYREF
  matrix3x4_t eyesToParent; // [esp+38h] [ebp-30h] BYREF

  m_Index = this->m_pMoveParent.m_Index;
  if ( m_Index != -1
    && (v2 = (C_BaseEntity **)&g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index],
        g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index))
    && (v3 = *v2, *v2 != nullptr) )
  {
    AngleMatrix(angles: &this->pl.v_angle, matrix: &eyesToParent);
    C_BaseEntity::CalcAbsolutePosition(this: v3);
    p_m_rgflCoordinateFrame = &v3->m_rgflCoordinateFrame;
    ConcatTransforms(in1: p_m_rgflCoordinateFrame, in2: &eyesToParent, out: &eyesToWorld);
    if ( (_S5_5 & 1) == 0 )
      _S5_5 |= 1u;
    MatrixAngles(a1: (int)p_m_rgflCoordinateFrame, src: (const VMatrix *)&eyesToWorld, vAngles: &angEyeWorld);
    return &angEyeWorld;
  }
  else
  {
    v4 = this->m_hViewEntity.m_Index;
    if ( v4 != -1
      && (v5 = (unsigned __int16)v4,
          v6 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)v4],
          v7 = HIWORD(v4),
          v6->m_SerialNumber == v7)
      && v6->m_pEntity != nullptr )
    {
      v8 = v5;
      v9 = g_pEntityList->m_EntPtrArray[v8].m_SerialNumber == v7;
      v10 = &g_pEntityList->m_EntPtrArray[v8];
      if ( v9 )
        return ((const QAngle *(__thiscall *)(IHandleEntity *))v10->m_pEntity->__vftable[52].SetRefEHandle)(a1: v10->m_pEntity);
      else
        return (*(const QAngle *(__thiscall **)(_DWORD))(MEMORY[0] + 628))(a1: 0);
    }
    else
    {
      return &this->pl.v_angle;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10019780
// Name: public: void C_BasePlayer::CacheVehicleView(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BasePlayer::CacheVehicleView(C_BasePlayer *this)
{
  unsigned int m_Index; // ecx
  CEntInfo *v3; // eax
  int v4; // esi
  int v5; // eax

  if ( this->m_nVehicleViewSavedFrame != *(_DWORD *)(gpGlobals.m_Index + 4) )
  {
    m_Index = this->m_hVehicle.m_Index;
    if ( m_Index != -1 )
    {
      v3 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index];
      if ( g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index)
        && v3->m_pEntity != nullptr )
      {
        v4 = ((int (__thiscall *)(IHandleEntity *))v3->m_pEntity->__vftable[31].dtr_IHandleEntity)(a1: v3->m_pEntity);
        if ( v4 != 0 )
        {
          v5 = (*(int (__thiscall **)(int, C_BasePlayer *))(*(_DWORD *)v4 + 4))(a1: v4, a2: this);
          (*(void (__thiscall **)(int, int, Vector *, QAngle *, float *))(*(_DWORD *)v4 + 8))(
            a1: v4,
            a2: v5,
            a3: &this->m_vecVehicleViewOrigin,
            a4: &this->m_vecVehicleViewAngles,
            a5: &this->m_flVehicleViewFOV);
          this->m_nVehicleViewSavedFrame = *(_DWORD *)(gpGlobals.m_Index + 4);
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10019810
// Name: public: void C_BasePlayer::EyeVectors(class Vector __near *,class Vector __near *,class Vector __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BasePlayer::EyeVectors(C_BasePlayer *this, Vector *pForward, Vector *pRight, Vector *pUp)
{
  unsigned int m_Index; // ecx
  CEntInfo *v6; // eax
  const QAngle *v7; // eax

  m_Index = this->m_hVehicle.m_Index;
  if ( m_Index != -1
    && (v6 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index],
        g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index))
    && v6->m_pEntity != nullptr
    && ((int (__thiscall *)(IHandleEntity *))v6->m_pEntity->__vftable[31].dtr_IHandleEntity)(a1: v6->m_pEntity) != 0 )
  {
    C_BasePlayer::CacheVehicleView(this);
    AngleVectors(angles: &this->m_vecVehicleViewAngles, forward: pForward, right: pRight, up: pUp);
  }
  else
  {
    v7 = this->EyeAngles(this);
    AngleVectors(angles: v7, forward: pForward, right: pRight, up: pUp);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100198A0
// Name: public: void C_BasePlayer::EyePositionAndVectors(class Vector __near *,class Vector __near *,class Vector __near *,class Vector __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BasePlayer::EyePositionAndVectors(
        C_BasePlayer *this,
        Vector *pPosition,
        Vector *pForward,
        Vector *pRight,
        Vector *pUp)
{
  unsigned int m_Index; // ecx
  CEntInfo *v7; // eax
  const QAngle *v8; // eax
  _BYTE v9[12]; // [esp+4h] [ebp-Ch] BYREF

  m_Index = this->m_hVehicle.m_Index;
  if ( m_Index != -1
    && (v7 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index],
        g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index))
    && v7->m_pEntity != nullptr
    && ((int (__thiscall *)(IHandleEntity *))v7->m_pEntity->__vftable[31].dtr_IHandleEntity)(a1: v7->m_pEntity) != 0 )
  {
    C_BasePlayer::CacheVehicleView(this);
    AngleVectors(angles: &this->m_vecVehicleViewAngles, forward: pForward, right: pRight, up: pUp);
    if ( pPosition != nullptr )
      *pPosition = this->m_vecVehicleViewOrigin;
  }
  else
  {
    *pPosition = *this->EyePosition(this, result: v9);
    v8 = this->EyeAngles(this);
    AngleVectors(angles: v8, forward: pForward, right: pRight, up: pUp);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10019980
// Name: public: void C_BasePlayer::ResetObserverMode(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BasePlayer::ResetObserverMode(C_BasePlayer *this)
{
  this->m_hObserverTarget.m_Index = -1;
  this->m_iObserverMode = 0;
  C_BaseEntity::UpdateVisibility(this);
}

//------------------------------------------------------------------------------
// Address: 0x100199A0
// Name: protected: void C_BasePlayer::CalcVehicleView(class IClientVehicle __near *,class Vector __near &,class QAngle __near &,float __near &,float __near &,float __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BasePlayer::CalcVehicleView(
        C_BasePlayer *this,
        IClientVehicle *pVehicle,
        Vector *eyeOrigin,
        QAngle *eyeAngles,
        float *zNear,
        float *zFar,
        float *fov)
{
  vgui::ToggleButton *v10; // ecx
  int v11; // eax
  CViewEffects *ViewEffects; // eax
  CViewEffects *v13; // eax
  float eyeOrigina; // [esp+34h] [ebp+Ch]
  float eyeAnglesa; // [esp+38h] [ebp+10h]
  float *fova; // [esp+44h] [ebp+1Ch]

  C_BasePlayer::CacheVehicleView(this);
  *eyeOrigin = this->m_vecVehicleViewOrigin;
  *eyeAngles = this->m_vecVehicleViewAngles;
  if ( IsPresetCurrentCostDebuggingEnabled(this: v10) )
  {
    eyeAngles->x = eyeAngles->x + vec3_angle.x;
    eyeAngles->y = eyeAngles->y + vec3_angle.y;
    eyeAngles->z = vec3_angle.z + eyeAngles->z;
    eyeOrigin->x = eyeOrigin->x + vec3_origin.x;
    eyeOrigin->y = eyeOrigin->y + vec3_origin.y;
    eyeOrigin->z = eyeOrigin->z + vec3_origin.z;
  }
  *fov = this->GetFOV(this);
  pVehicle->GetVehicleClipPlanes(this: pVehicle, a2: zNear, a3: zFar);
  if ( this->m_MoveType != 8 )
  {
    eyeOrigina = sv_rollspeed.m_pParent->m_Value.m_fValue;
    eyeAnglesa = sv_rollangle.m_pParent->m_Value.m_fValue;
    C_BaseEntity::CalcAbsoluteVelocity(this);
    fova = (float *)this->C_BaseCombatCharacter::C_BaseFlex::C_BaseAnimatingOverlay::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable;
    v11 = ((int (__thiscall *)(C_BasePlayer *, Vector *, _DWORD, _DWORD))this->GetAbsAngles)(
            a1: this,
            a2: &this->m_vecAbsVelocity,
            a3: LODWORD(eyeAnglesa),
            a4: LODWORD(eyeOrigina));
    eyeAngles->z = ((double (__thiscall *)(C_BasePlayer *, int))*((_DWORD *)fova + 243))(a1: this, a2: v11)
                 + eyeAngles->z;
  }
  eyeAngles->x = eyeAngles->x + this->m_Local.m_vecPunchAngle.m_Value.x;
  eyeAngles->y = this->m_Local.m_vecPunchAngle.m_Value.y + eyeAngles->y;
  eyeAngles->z = this->m_Local.m_vecPunchAngle.m_Value.z + eyeAngles->z;
  if ( !prediction->InPrediction(this: prediction) )
  {
    ViewEffects = GetViewEffects();
    ViewEffects->CalcShake(this: ViewEffects);
    v13 = GetViewEffects();
    ((void (__thiscall *)(CViewEffects *, Vector *, QAngle *, int))v13->ApplyShake)(
      a1: v13,
      a2: eyeOrigin,
      a3: eyeAngles,
      a4: 1065353216);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10019B70
// Name: public: virtual void C_BasePlayer::CalcViewBob(class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BasePlayer::CalcViewBob(C_BasePlayer *this, Vector *eyeOrigin)
{
  float m_flOldFallVelocity; // xmm3_4
  float v4; // xmm2_4
  int m_nValue; // edi
  float v6; // xmm0_4
  float v7; // xmm0_4
  float vecBaseEyePosition_8; // [esp+Ch] [ebp-8h]
  float landFraction; // [esp+10h] [ebp-4h]

  if ( cl_use_new_headbob.m_pParent != nullptr && cl_use_new_headbob.m_pParent->m_Value.m_nValue != 0 )
  {
    m_flOldFallVelocity = this->m_Local.m_flOldFallVelocity;
    vecBaseEyePosition_8 = eyeOrigin->z;
    if ( this->m_Local.m_flFallVelocity <= 0.1
      && m_flOldFallVelocity > 10.0
      && m_flOldFallVelocity <= 1024.0
      && !this->m_Local.m_bInLanding )
    {
      this->m_Local.m_bInLanding = true;
      this->m_Local.m_flLandingTime = *(float *)(gpGlobals.m_Index + 12);
    }
    if ( this->m_Local.m_bInLanding )
    {
      v4 = 0.0;
      if ( (float)(*(float *)(gpGlobals.m_Index + 12) - this->m_Local.m_flLandingTime) > 0.0 )
        v4 = *(float *)(gpGlobals.m_Index + 12) - this->m_Local.m_flLandingTime;
      if ( cl_headbob_land_dip_amt.m_pParent != nullptr )
        m_nValue = cl_headbob_land_dip_amt.m_pParent->m_Value.m_nValue;
      else
        m_nValue = 0;
      this->GetViewOffset(this);
      landFraction = (float)((float)((float)(v4 * 4.0) * (float)(v4 * 4.0)) * 3.0)
                   - (float)((float)((float)((float)(v4 * 4.0) * (float)(v4 * 4.0)) * 2.0) * (float)(v4 * 4.0));
      v6 = (float)((float)((float)(64 - m_nValue) - (float)((float)(1.0 / m_flOldFallVelocity) * 0.1)) * landFraction)
         + (float)((float)(1.0 - landFraction) * 64.0);
      if ( v6 > 64.0 )
      {
        v6 = 64.0;
        this->m_Local.m_bInLanding = false;
      }
      v7 = eyeOrigin->z - (float)(64.0 - v6);
      eyeOrigin->z = v7;
      if ( this->m_Local.m_bInLanding && (float)(v7 - 0.001) >= vecBaseEyePosition_8 )
        this->m_Local.m_bInLanding = false;
    }
    if ( !this->m_Local.m_bInLanding )
      this->m_Local.m_flOldFallVelocity = this->m_Local.m_flFallVelocity;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10019D10
// Name: public: bool C_BasePlayer::SetFOV(class C_BaseEntity __near *,int,float,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall C_BasePlayer::SetFOV(
        C_BasePlayer *this,
        C_BaseEntity *pRequester,
        int FOV,
        float zoomRate,
        int iZoomStart)
{
  unsigned int m_Index; // edx
  int v8; // eax
  CEntInfo *v9; // esi
  unsigned int v10; // edx
  int v11; // eax
  bool v12; // zf
  CEntInfo *v13; // eax
  C_BaseEntity *v14; // eax
  int v15; // eax
  double v16; // st7

  if ( pRequester == nullptr )
    return 0;
  m_Index = this->m_hZoomOwner.m_Index;
  if ( m_Index != -1 )
  {
    v8 = (unsigned __int16)m_Index;
    v9 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index];
    v10 = HIWORD(m_Index);
    if ( v9->m_SerialNumber == v10 && v9->m_pEntity != nullptr )
    {
      v11 = v8;
      v12 = g_pEntityList->m_EntPtrArray[v11].m_SerialNumber == v10;
      v13 = &g_pEntityList->m_EntPtrArray[v11];
      v14 = v12 ? (C_BaseEntity *)v13->m_pEntity : nullptr;
      if ( v14 != pRequester )
        return 0;
    }
  }
  if ( FOV != 0 )
    this->m_hZoomOwner.m_Index = *(_DWORD *)((int (*)(void))pRequester->GetRefEHandle)();
  else
    this->m_hZoomOwner.m_Index = -1;
  v15 = iZoomStart;
  if ( iZoomStart <= 0 )
    v15 = (int)this->GetFOV(this);
  this->m_iFOVStart = v15;
  v16 = *(float *)(gpGlobals.m_Index + 12);
  this->m_iFOV = FOV;
  this->m_flFOVTime = v16;
  this->m_Local.m_flFOVRate = zoomRate;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10019DE0
// Name: public: bool fogparams_t::operator!=(struct fogparams_t const __near &)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall fogparams_t::operator!=(fogparams_t *this, const fogparams_t *other)
{
  bool result; // al

  if ( this->enable.m_Value != other->enable.m_Value )
    return true;
  if ( this->blend.m_Value != other->blend.m_Value )
    return true;
  if ( fabs(this->dirPrimary.m_Value.x - other->dirPrimary.m_Value.x) > 0.0099999998 )
    return true;
  if ( fabs(this->dirPrimary.m_Value.y - other->dirPrimary.m_Value.y) > 0.0099999998 )
    return true;
  if ( fabs(this->dirPrimary.m_Value.z - other->dirPrimary.m_Value.z) > 0.0099999998 )
    return true;
  if ( this->colorPrimary.m_Value.r != other->colorPrimary.m_Value.r )
    return true;
  if ( this->colorPrimary.m_Value.g != other->colorPrimary.m_Value.g )
    return true;
  if ( this->colorPrimary.m_Value.b != other->colorPrimary.m_Value.b )
    return true;
  if ( this->colorPrimary.m_Value.a != other->colorPrimary.m_Value.a )
    return true;
  if ( color32_s::operator!=(this: &this->colorSecondary.m_Value, other: &other->colorSecondary.m_Value) )
    return true;
  if ( this->start.m_Value != other->start.m_Value )
    return true;
  if ( this->end.m_Value != other->end.m_Value )
    return true;
  if ( this->farz.m_Value != other->farz.m_Value )
    return true;
  if ( this->maxdensity.m_Value != other->maxdensity.m_Value )
    return true;
  if ( color32_s::operator!=(this: &this->colorPrimaryLerpTo.m_Value, other: &other->colorPrimaryLerpTo.m_Value) )
    return true;
  result = color32_s::operator!=(this: &this->colorSecondaryLerpTo.m_Value, other: &other->colorSecondaryLerpTo.m_Value);
  if ( result
    || this->startLerpTo.m_Value != other->startLerpTo.m_Value
    || this->endLerpTo.m_Value != other->endLerpTo.m_Value
    || this->maxdensityLerpTo.m_Value != other->maxdensityLerpTo.m_Value
    || this->lerptime.m_Value != other->lerptime.m_Value
    || this->duration.m_Value != other->duration.m_Value
    || this->HDRColorScale.m_Value != other->HDRColorScale.m_Value )
  {
    return true;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10019F70
// Name: public: virtual void C_BasePlayer::VPhysicsShadowUpdate(class IPhysicsObject __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge C_BasePlayer::VPhysicsShadowUpdate(C_BasePlayer *this@<ecx>, int a2@<ebx>, float pPhysics)
{
  int v4; // eax
  bool v5; // zf
  bool v6; // sf
  unsigned int m_afPhysicsFlags; // eax
  bool v8; // bl
  IPhysicsObject *GroundVPhysics; // edi
  const Vector *v10; // eax
  const Vector *v11; // eax
  const Vector *v12; // eax
  float v13; // xmm1_4
  float v14; // xmm1_4
  float v15; // xmm2_4
  unsigned int (__thiscall *PhysicsSolidMaskForEntity)(C_BaseEntity *); // eax
  const Vector *v17; // eax
  const Vector *v18; // eax
  const Vector *v19; // eax
  float z; // edx
  float v21; // xmm0_4
  unsigned int v22; // eax
  float v23; // xmm2_4
  float v24; // xmm3_4
  float v25; // xmm4_4
  float v26; // xmm0_4
  float v27; // xmm0_4
  float v28; // xmm0_4
  float v29; // xmm0_4
  float v30; // xmm1_4
  int i; // edi
  float v32; // xmm2_4
  unsigned int v33; // eax
  const Vector *v34; // eax
  const Vector *v35; // eax
  const Vector *v36; // eax
  const Vector *v37; // [esp+0h] [ebp-F0h]
  const Vector *v38; // [esp+4h] [ebp-ECh]
  const Vector *v39; // [esp+4h] [ebp-ECh]
  const Vector *v40; // [esp+8h] [ebp-E8h]
  const Vector *v41; // [esp+8h] [ebp-E8h]
  const Vector *v42; // [esp+8h] [ebp-E8h]
  unsigned int v43; // [esp+Ch] [ebp-E4h]
  unsigned int v44; // [esp+Ch] [ebp-E4h]
  unsigned int v45; // [esp+Ch] [ebp-E4h]
  unsigned int v46; // [esp+Ch] [ebp-E4h]
  Vector up; // [esp+28h] [ebp-C8h] BYREF
  CGameTrace trace; // [esp+34h] [ebp-BCh] BYREF
  float dist; // [esp+88h] [ebp-68h]
  Vector lastValidPosition; // [esp+8Ch] [ebp-64h] BYREF
  Vector wishvel; // [esp+98h] [ebp-58h]
  float deltaV; // [esp+A4h] [ebp-4Ch]
  float maxDistErrorSqr; // [esp+A8h] [ebp-48h]
  Vector right; // [esp+ACh] [ebp-44h] BYREF
  Vector forward; // [esp+B8h] [ebp-38h] BYREF
  Vector newPosition; // [esp+C4h] [ebp-2Ch] BYREF
  Vector vVel; // [esp+D0h] [ebp-20h] BYREF
  float fmove; // [esp+DCh] [ebp-14h] BYREF
  Vector newVelocity; // [esp+E0h] [ebp-10h] BYREF
  bool bCheckStuck; // [esp+EFh] [ebp-1h]

  if ( sv_turbophysics.m_pParent == nullptr || sv_turbophysics.m_pParent->m_Value.m_nValue == 0 )
  {
    v4 = ((int (__thiscall *)(IPhysicsPlayerController *, Vector *, _DWORD, int))this->m_pPhysicsController->GetShadowPosition)(
           a1: this->m_pPhysicsController,
           a2: &newPosition,
           a3: 0,
           a4: a2);
    v5 = v4 == 0;
    v6 = v4 < 0;
    m_afPhysicsFlags = this->m_afPhysicsFlags;
    v8 = !v6 && !v5;
    bCheckStuck = false;
    if ( (m_afPhysicsFlags & 0x20) != 0 )
    {
      bCheckStuck = true;
      this->m_afPhysicsFlags = m_afPhysicsFlags & 0xFFFFFFDF;
    }
    fmove = COERCE_FLOAT(this->m_pPhysicsController->GetContactState(this: this->m_pPhysicsController, a2: 4096u));
    if ( (LOBYTE(fmove) & 1) != 0 || (this->m_afPhysicsFlags & 0x10) != 0 )
      this->m_bTouchedPhysObject = true;
    if ( this->IsFollowingPhysics(this) )
      this->m_bTouchedPhysObject = true;
    if ( cl_predict_motioncontrol.m_pParent == nullptr || cl_predict_motioncontrol.m_pParent->m_Value.m_nValue == 0 )
      this->m_bTouchedPhysObject = false;
    if ( this->m_MoveType == 8 || this->pl.deadflag.m_Value )
    {
      v36 = this->GetAbsOrigin(this);
      this->m_oldOrigin.x = v36->x;
      this->m_oldOrigin.y = v36->y;
      this->m_oldOrigin.z = v36->z;
      return;
    }
    if ( v8 )
    {
      GroundVPhysics = C_BasePlayer::GetGroundVPhysics(this);
      (*(void (__thiscall **)(_DWORD, Vector *, _DWORD))(*(_DWORD *)LODWORD(pPhysics) + 192))(
        a1: LODWORD(pPhysics),
        a2: &newPosition,
        a3: 0);
      this->m_pPhysicsController->GetShadowVelocity(this: this->m_pPhysicsController, a2: &newVelocity);
      lastValidPosition = newPosition;
      if ( physicsshadowupdate_render.m_pParent != nullptr
        && physicsshadowupdate_render.m_pParent->m_Value.m_nValue != 0 )
      {
        v38 = this->WorldAlignMaxs(this);
        v37 = this->WorldAlignMins(this);
        v10 = this->GetAbsOrigin(this);
        NDebugOverlay::Box(origin: v10, mins: v37, maxs: v38, r: 255, g: 255, b: 0, a: 24, flDuration: 15.0);
        v39 = this->WorldAlignMaxs(this);
        v11 = this->WorldAlignMins(this);
        NDebugOverlay::Box(origin: &newPosition, mins: v11, maxs: v39, r: 0, g: 255, b: 255, a: 24, flDuration: 15.0);
      }
      v12 = this->GetAbsOrigin(this);
      v13 = v12->z - newPosition.z;
      if ( !this->m_bTouchedPhysObject && (this->m_fFlags & 1) == 0 )
        v13 = v13 * 0.5;
      dist = (float)((float)((float)(v12->x - newPosition.x) * (float)(v12->x - newPosition.x))
                   + (float)((float)(v12->y - newPosition.y) * (float)(v12->y - newPosition.y)))
           + (float)(v13 * v13);
      C_BaseEntity::CalcAbsoluteVelocity(this);
      v14 = (float)((float)(newVelocity.y - this->m_vecAbsVelocity.y) * (float)(newVelocity.y - this->m_vecAbsVelocity.y))
          + (float)((float)(newVelocity.x - this->m_vecAbsVelocity.x) * (float)(newVelocity.x - this->m_vecAbsVelocity.x));
      v15 = (float)(newVelocity.z - this->m_vecAbsVelocity.z) * (float)(newVelocity.z - this->m_vecAbsVelocity.z);
      maxDistErrorSqr = 4.0;
      deltaV = v14 + v15;
      pPhysics = 100.0;
      if ( C_BasePlayer::IsRideablePhysics(this, pPhysics: GroundVPhysics) )
      {
        maxDistErrorSqr = 1.0;
        pPhysics = 25.0;
      }
      if ( this->m_pPhysicsController->WasFrozen(this: this->m_pPhysicsController) )
      {
        PhysicsSolidMaskForEntity = this->PhysicsSolidMaskForEntity;
        this->m_bPhysicsWasFrozen = true;
        v43 = PhysicsSolidMaskForEntity(this);
        v40 = this->GetAbsOrigin(this);
        v17 = this->GetAbsOrigin(this);
        UTIL_TraceEntity(
          pEntity: this,
          vecAbsStart: v17,
          vecAbsEnd: v40,
          mask: v43,
          pIgnore: this,
          nCollisionGroup: 8,
          ptr: &trace);
        if ( !trace.startsolid )
          return;
        v44 = this->PhysicsSolidMaskForEntity(this);
        v18 = this->GetAbsOrigin(this);
        UTIL_TraceEntity(
          pEntity: this,
          vecAbsStart: &newPosition,
          vecAbsEnd: v18,
          mask: v44,
          pIgnore: this,
          nCollisionGroup: 8,
          ptr: &trace);
        if ( !trace.startsolid )
        {
          C_BaseEntity::SetAbsOrigin(this, absOrigin: &trace.endpos);
          C_BasePlayer::UpdateVPhysicsPosition(
            this,
            position: &trace.endpos,
            velocity: &vec3_origin,
            secondsToArrival: 0.0);
          return;
        }
      }
      if ( dist >= maxDistErrorSqr || deltaV >= pPhysics )
      {
        if ( this->m_bTouchedPhysObject )
        {
LABEL_40:
          if ( deltaV >= pPhysics && !this->m_bPhysicsWasFrozen )
          {
            if ( C_BasePlayer::IsRideablePhysics(this, pPhysics: GroundVPhysics) )
            {
              AngleVectors(angles: &g_pMoveData->m_vecViewAngles, &forward, &right, &up);
              fmove = g_pMoveData->m_flForwardMove;
              pPhysics = g_pMoveData->m_flSideMove;
              v27 = (float)((float)(forward.y + forward.x) * 0.0) - (float)(forward.z * 1.0);
              forward.x = forward.x - (float)(v27 * 0.0);
              forward.y = forward.y - (float)(v27 * 0.0);
              forward.z = forward.z - (float)(v27 * -1.0);
              VectorNormalize(vec: &forward);
              v28 = (float)((float)(right.y + right.x) * 0.0) - (float)(right.z * 1.0);
              right.x = right.x - (float)(v28 * 0.0);
              right.y = right.y - (float)(v28 * 0.0);
              right.z = right.z - (float)(v28 * -1.0);
              VectorNormalize(vec: &right);
              wishvel.x = (float)(forward.x * fmove) + (float)(right.x * pPhysics);
              wishvel.y = (float)(forward.y * fmove) + (float)(right.y * pPhysics);
              wishvel.z = (float)(forward.z * fmove) + (float)(right.z * pPhysics);
              if ( (float)((float)(wishvel.y * wishvel.y) + (float)(wishvel.x * wishvel.x)) != 0.0 )
              {
                vVel.x = -newVelocity.x;
                vVel.y = -newVelocity.y;
                vVel.z = -newVelocity.z;
                C_BaseEntity::CalcAbsoluteVelocity(this);
                v29 = (float)(this->m_vecAbsVelocity.y + wishvel.y) + vVel.y;
                v30 = (float)(this->m_vecAbsVelocity.z + wishvel.z) + vVel.z;
                vVel.x = (float)(wishvel.x + this->m_vecAbsVelocity.x) + vVel.x;
                vVel.y = v29;
                vVel.z = v30;
                for ( i = 0; i < 12; i += 4 )
                {
                  v32 = *(float *)((char *)&newVelocity.x + i);
                  pPhysics = v32 + 180.0;
                  fmove = v32 - 180.0;
                  *(float *)((char *)&vVel.x + i) = clamp<float,float,float>(
                                                      val: (const float *)((char *)&vVel.x + i),
                                                      minVal: &fmove,
                                                      maxVal: &pPhysics);
                }
                C_BaseEntity::SetAbsVelocity(this, vecAbsVelocity: &vVel);
              }
            }
            else
            {
              C_BaseEntity::CalcAbsoluteVelocity(this);
              z = this->m_vecAbsVelocity.z;
              *(_QWORD *)&vVel.x = *(_QWORD *)&this->m_vecAbsVelocity.x;
              vVel.z = z;
              pPhysics = VectorNormalize(vec: &vVel);
              v21 = (float)((float)(newVelocity.x * vVel.x) + (float)(vVel.y * newVelocity.y))
                  + (float)(vVel.z * newVelocity.z);
              if ( v21 <= pPhysics )
              {
                if ( (float)-pPhysics > v21 )
                  v21 = -pPhysics;
              }
              else
              {
                v21 = pPhysics;
              }
              v22 = this->m_afPhysicsFlags & 0x10;
              v23 = (float)((float)-v21 * vVel.x) + newVelocity.x;
              v24 = (float)(vVel.y * (float)-v21) + newVelocity.y;
              v25 = (float)(vVel.z * (float)-v21) + newVelocity.z;
              newVelocity.x = v23;
              newVelocity.y = v24;
              newVelocity.z = v25;
              if ( v22 != 0 )
              {
                v26 = (float)((float)((float)(v21 - pPhysics) * 0.1) + pPhysics) - pPhysics;
                newVelocity.x = (float)(v26 * vVel.x) + v23;
                newVelocity.y = (float)(vVel.y * v26) + v24;
                newVelocity.z = (float)(vVel.z * v26) + v25;
              }
              else if ( C_BaseEntity::IsSimulatingOnAlternateTicks() )
              {
                newVelocity.x = newVelocity.x * 0.5;
                newVelocity.y = newVelocity.y * 0.5;
                newVelocity.z = newVelocity.z * 0.5;
              }
              C_BaseEntity::ApplyAbsVelocityImpulse(this, vecImpulse: &newVelocity);
            }
          }
          v33 = this->PhysicsSolidMaskForEntity(this);
          UTIL_TraceEntity(
            pEntity: this,
            vecAbsStart: &newPosition,
            vecAbsEnd: &newPosition,
            mask: v33,
            pIgnore: this,
            nCollisionGroup: 8,
            ptr: &trace);
          if ( !trace.allsolid && !trace.startsolid )
            C_BaseEntity::SetAbsOrigin(this, absOrigin: &newPosition);
          goto LABEL_59;
        }
      }
      else if ( GroundVPhysics == nullptr || this->m_bTouchedPhysObject )
      {
        if ( this->m_bTouchedPhysObject || (LOBYTE(fmove) & 2) != 0 )
        {
          v45 = this->PhysicsSolidMaskForEntity(this);
          v41 = this->GetAbsOrigin(this);
          v19 = this->GetAbsOrigin(this);
          UTIL_TraceEntity(
            pEntity: this,
            vecAbsStart: v19,
            vecAbsEnd: v41,
            mask: v45,
            pIgnore: this,
            nCollisionGroup: 8,
            ptr: &trace);
          if ( trace.allsolid || trace.startsolid )
          {
            lastValidPosition = this->m_oldOrigin;
            C_BaseEntity::SetAbsOrigin(this, absOrigin: &newPosition);
            goto LABEL_60;
          }
        }
LABEL_59:
        if ( !bCheckStuck )
        {
LABEL_63:
          v35 = this->GetAbsOrigin(this);
          this->m_oldOrigin.x = v35->x;
          this->m_oldOrigin.y = v35->y;
          this->m_oldOrigin.z = v35->z;
          this->m_bPhysicsWasFrozen = false;
          return;
        }
LABEL_60:
        v46 = this->PhysicsSolidMaskForEntity(this);
        v42 = this->GetAbsOrigin(this);
        v34 = this->GetAbsOrigin(this);
        UTIL_TraceEntity(
          pEntity: this,
          vecAbsStart: v34,
          vecAbsEnd: v42,
          mask: v46,
          pIgnore: this,
          nCollisionGroup: 8,
          ptr: &trace);
        if ( trace.allsolid || trace.startsolid )
          C_BaseEntity::SetAbsOrigin(this, absOrigin: &lastValidPosition);
        goto LABEL_63;
      }
      if ( GroundVPhysics == nullptr )
        goto LABEL_60;
      goto LABEL_40;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001A860
// Name: public: void C_BasePlayer::PostThinkVPhysics(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall C_BasePlayer::PostThinkVPhysics(C_BasePlayer *this@<ecx>, int a2@<edi>)
{
  unsigned __int8 v3; // al
  const Vector *v4; // eax
  float z; // ecx
  float v6; // xmm0_4
  C_BaseEntity *GroundEntity; // eax
  IPhysicsObject *m_pPhysicsObject; // edi
  IPhysicsObject *v9; // ebx
  const Vector *(__thiscall *GetAbsOrigin)(IClientEntity *); // edx
  float v11; // xmm1_4
  float v12; // xmm2_4
  float *v13; // eax
  float v14; // xmm1_4
  float v15; // xmm2_4
  unsigned __int8 m_MoveType; // al
  int v17; // edi
  const Vector *v18; // eax
  float m_flMaxspeed; // xmm0_4
  CMoveData *v20; // eax
  float m_outStepHeight; // xmm0_4
  IPhysicsObject *v22; // ebx
  IPhysicsObject_vtbl *v23; // edi
  int v24; // eax
  C_BasePlayer_vtbl *v25; // edx
  unsigned int (__thiscall *PhysicsSolidMaskForEntity)(C_BaseEntity *); // eax
  unsigned int v27; // eax
  const Vector *v28; // eax
  CGameTrace trace; // [esp+18h] [ebp-7Ch] BYREF
  Vector end; // [esp+6Ch] [ebp-28h] BYREF
  Vector position; // [esp+78h] [ebp-1Ch] BYREF
  Vector newPosition; // [esp+84h] [ebp-10h]
  float frametime; // [esp+90h] [ebp-4h]

  if ( this->m_pPhysicsController != nullptr )
  {
    v4 = this->GetAbsOrigin(this);
    z = v4->z;
    *(_QWORD *)&newPosition.x = *(_QWORD *)&v4->x;
    v6 = *(float *)(gpGlobals.m_Index + 16);
    newPosition.z = z;
    frametime = v6;
    if ( v6 <= 0.0 || v6 > 0.1 )
      frametime = 0.1;
    GroundEntity = C_BaseEntity::GetGroundEntity(this);
    if ( GroundEntity != nullptr
      && GroundEntity->m_MoveType == 6
      && (m_pPhysicsObject = GroundEntity->m_pPhysicsObject) != nullptr
      && m_pPhysicsObject->IsMoveable(this: m_pPhysicsObject) )
    {
      v9 = m_pPhysicsObject;
    }
    else
    {
      v9 = nullptr;
      if ( this->m_bTouchedPhysObject && g_pMoveData->m_outStepHeight <= 0.0 && (this->m_fFlags & 1) != 0 )
      {
        GetAbsOrigin = this->GetAbsOrigin;
        v11 = (float)(this->m_oldOrigin.y + (float)(g_pMoveData->m_outWishVel.y * frametime)) * 0.5;
        v12 = (float)(this->m_oldOrigin.z + (float)(g_pMoveData->m_outWishVel.z * frametime)) * 0.5;
        position.x = (float)(this->m_oldOrigin.x + (float)(frametime * g_pMoveData->m_outWishVel.x)) * 0.5;
        position.y = v11;
        position.z = v12;
        v13 = (float *)GetAbsOrigin(this);
        v14 = (float)(v13[1] * 0.5) + v11;
        v15 = (float)(v13[2] * 0.5) + v12;
        newPosition.x = (float)(*v13 * 0.5) + position.x;
        newPosition.y = v14;
        newPosition.z = v15;
      }
    }
    m_MoveType = this->m_MoveType;
    if ( m_MoveType == 8 || m_MoveType == 10 )
      v17 = 2;
    else
      v17 = (this->m_fFlags & 2) != 0;
    if ( v17 != this->m_vphysicsCollisionState )
    {
      C_BaseEntity::CalcAbsoluteVelocity(this);
      v18 = this->GetAbsOrigin(this);
      C_BasePlayer::SetVCollisionState(
        this,
        vecAbsOrigin: v18,
        vecAbsVelocity: &this->m_vecAbsVelocity,
        collisionState: v17);
    }
    if ( !this->m_bTouchedPhysObject && v9 == nullptr )
    {
      m_flMaxspeed = this->m_flMaxspeed;
      if ( m_flMaxspeed <= 0.0 )
        m_flMaxspeed = sv_maxspeed.m_pParent->m_Value.m_fValue;
      v20 = g_pMoveData;
      g_pMoveData->m_outWishVel.x = m_flMaxspeed;
      v20->m_outWishVel.y = m_flMaxspeed;
      v20->m_outWishVel.z = m_flMaxspeed;
    }
    m_outStepHeight = g_pMoveData->m_outStepHeight;
    if ( m_outStepHeight > 0.1 )
    {
      if ( m_outStepHeight <= 4.0 )
      {
        ((void (__thiscall *)(IPhysicsObject *, Vector *, _DWORD, int))this->m_pPhysicsObject->GetPosition)(
          a1: this->m_pPhysicsObject,
          a2: &position,
          a3: 0,
          a4: a2);
        v25 = this->C_BaseCombatCharacter::C_BaseFlex::C_BaseAnimatingOverlay::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable;
        end = position;
        PhysicsSolidMaskForEntity = v25->PhysicsSolidMaskForEntity;
        end.z = g_pMoveData->m_outStepHeight + position.z;
        v27 = PhysicsSolidMaskForEntity(this);
        UTIL_TraceEntity(
          pEntity: this,
          vecAbsStart: &position,
          vecAbsEnd: &end,
          mask: v27,
          pIgnore: this,
          nCollisionGroup: 8,
          ptr: &trace);
        if ( trace.fraction < 1.0 || trace.allsolid || trace.startsolid )
          g_pMoveData->m_outStepHeight = trace.endpos.z - position.z;
        ((void (__cdecl *)(_DWORD))this->m_pPhysicsController->StepUp)(a1: LODWORD(g_pMoveData->m_outStepHeight));
      }
      else
      {
        v22 = this->m_pPhysicsObject;
        v23 = v22->__vftable;
        v24 = ((int (__thiscall *)(C_BasePlayer *, QAngle *, int))this->GetAbsOrigin)(a1: this, a2: &vec3_angle, a3: 1);
        ((void (__thiscall *)(IPhysicsObject *, int))v23->SetPosition)(a1: v22, a2: v24);
      }
      this->m_pPhysicsController->Jump(this: this->m_pPhysicsController);
    }
    g_pMoveData->m_outStepHeight = 0.0;
    this->m_vNewVPhysicsPosition = newPosition;
    this->m_vNewVPhysicsVelocity = g_pMoveData->m_outWishVel;
    v28 = this->GetAbsOrigin(this);
    this->m_oldOrigin.x = v28->x;
    this->m_oldOrigin.y = v28->y;
    this->m_oldOrigin.z = v28->z;
  }
  else if ( !physenv->IsPredicted(this: physenv) )
  {
    v3 = this->m_MoveType;
    if ( v3 == 8 || v3 == 10 )
      this->m_vphysicsCollisionState = 2;
    else
      this->m_vphysicsCollisionState = (this->m_fFlags & 2) != 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001ACA0
// Name: public: virtual class Vector C_BasePlayer::EyePosition(void)
// Source: json
//------------------------------------------------------------------------------
Vector *__thiscall C_BasePlayer::EyePosition(C_BasePlayer *this, Vector *result)
{
  unsigned int m_Index; // ecx
  IHandleEntity *v4; // eax
  int SplitScreenPlayerSlot; // eax
  unsigned int v7; // ecx
  int v8; // eax
  CEntInfo *v9; // edx
  unsigned int v10; // ecx
  int v11; // eax
  bool v12; // zf
  CEntInfo *v13; // eax
  IHandleEntity *m_pEntity; // eax

  m_Index = this->m_hVehicle.m_Index;
  if ( m_Index != -1
    && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index)
    && (v4 = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity) != nullptr
    && ((int (__thiscall *)(IHandleEntity *))v4->__vftable[31].dtr_IHandleEntity)(a1: v4) != 0 )
  {
    C_BasePlayer::CacheVehicleView(this);
    *result = this->m_vecVehicleViewOrigin;
    return result;
  }
  else if ( this->GetObserverMode(this) != 0 && this->m_iObserverMode == 5 && C_BasePlayer::IsLocalPlayer(pEntity: this) )
  {
    SplitScreenPlayerSlot = C_BasePlayer::GetSplitScreenPlayerSlot(this);
    *result = *MainViewOrigin(nSlot: SplitScreenPlayerSlot);
    return result;
  }
  else
  {
    v7 = this->m_hViewEntity.m_Index;
    if ( v7 != -1
      && (v8 = (unsigned __int16)v7,
          v9 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)v7],
          v10 = HIWORD(v7),
          v9->m_SerialNumber == v10)
      && v9->m_pEntity != nullptr )
    {
      v11 = v8;
      v12 = g_pEntityList->m_EntPtrArray[v11].m_SerialNumber == v10;
      v13 = &g_pEntityList->m_EntPtrArray[v11];
      if ( v12 )
        m_pEntity = v13->m_pEntity;
      else
        m_pEntity = nullptr;
      ((void (__thiscall *)(IHandleEntity *, Vector *))m_pEntity->__vftable[52].dtr_IHandleEntity)(
        a1: m_pEntity,
        a2: result);
      return result;
    }
    else
    {
      C_BaseEntity::EyePosition(this, result);
      return result;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001ADC0
// Name: public: virtual void C_BasePlayer::Weapon_SetLast(class C_BaseCombatWeapon __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BasePlayer::Weapon_SetLast(C_BasePlayer *this, C_BaseCombatWeapon *pWeapon)
{
  if ( pWeapon != nullptr )
    this->m_hLastWeapon.m_Index = pWeapon->GetRefEHandle(this: pWeapon)->m_Index;
  else
    this->m_hLastWeapon.m_Index = -1;
}

//------------------------------------------------------------------------------
// Address: 0x1001ADF0
// Name: public: void C_BasePlayer::RemoveFromPlayerSimulationList(class C_BaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BasePlayer::RemoveFromPlayerSimulationList(C_BasePlayer *this, C_BaseEntity *other)
{
  int v3; // eax

  if ( other != nullptr )
  {
    other = (C_BaseEntity *)other->GetRefEHandle(this: other)->m_Index;
    v3 = CUtlVector<CHandle<C_BasePlayer>,CUtlMemory<CHandle<C_BasePlayer>,int>>::Find(
           this: (CUtlVector<CHandle<C_BasePlayer>,CUtlMemory<CHandle<C_BasePlayer>,int> > *)&this->m_SimulatedByThisPlayer,
           src: (CHandle<C_BaseCombatWeapon> *)&other);
    if ( v3 != -1 )
    {
      if ( this->m_SimulatedByThisPlayer.m_Size - v3 - 1 > 0 )
        _V_memmove(
          dest: (void *)&this->m_SimulatedByThisPlayer.m_Memory.m_pMemory[v3],
          src: &this->m_SimulatedByThisPlayer.m_Memory.m_pMemory[v3 + 1],
          count: 4 * (this->m_SimulatedByThisPlayer.m_Size - v3 - 1));
      --this->m_SimulatedByThisPlayer.m_Size;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001AE50
// Name: public: void C_BasePlayer::SimulatePlayerSimulatedEntities(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BasePlayer::SimulatePlayerSimulatedEntities(C_BasePlayer *this)
{
  int i; // edi
  unsigned int m_Index; // ecx
  IHandleEntity *m_pEntity; // eax
  int j; // edi
  unsigned int v6; // ecx
  C_BaseEntity **v7; // eax
  C_BaseEntity *v8; // ebx

  for ( i = this->m_SimulatedByThisPlayer.m_Size - 1; i >= 0; --i )
  {
    m_Index = this->m_SimulatedByThisPlayer.m_Memory.m_pMemory[i].m_Index;
    if ( m_Index != -1
      && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index)
      && (m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity) != nullptr
      && BYTE1(m_pEntity[586].__vftable) != 0 )
    {
      m_pEntity->__vftable[47].GetRefEHandle(this: m_pEntity);
    }
    else
    {
      if ( this->m_SimulatedByThisPlayer.m_Size - i - 1 > 0 )
        _V_memmove(
          dest: (void *)&this->m_SimulatedByThisPlayer.m_Memory.m_pMemory[i],
          src: &this->m_SimulatedByThisPlayer.m_Memory.m_pMemory[i + 1],
          count: 4 * (this->m_SimulatedByThisPlayer.m_Size - i - 1));
      --this->m_SimulatedByThisPlayer.m_Size;
    }
  }
  for ( j = this->m_SimulatedByThisPlayer.m_Size - 1; j >= 0; --j )
  {
    v6 = this->m_SimulatedByThisPlayer.m_Memory.m_pMemory[j].m_Index;
    if ( v6 != -1
      && (v7 = (C_BaseEntity **)&g_pEntityList->m_EntPtrArray[(unsigned __int16)v6],
          g_pEntityList->m_EntPtrArray[(unsigned __int16)v6].m_SerialNumber == HIWORD(v6))
      && (v8 = *v7, *v7 != nullptr)
      && v8->m_bIsPlayerSimulated )
    {
      if ( C_BaseEntity::GetCheckUntouch(this: *v7) )
        C_BaseEntity::PhysicsCheckForEntityUntouch(this: v8);
    }
    else
    {
      if ( this->m_SimulatedByThisPlayer.m_Size - j - 1 > 0 )
        _V_memmove(
          dest: (void *)&this->m_SimulatedByThisPlayer.m_Memory.m_pMemory[j],
          src: &this->m_SimulatedByThisPlayer.m_Memory.m_pMemory[j + 1],
          count: 4 * (this->m_SimulatedByThisPlayer.m_Size - j - 1));
      --this->m_SimulatedByThisPlayer.m_Size;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001AF80
// Name: public: virtual void C_BasePlayer::ViewPunch(class QAngle const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BasePlayer::ViewPunch(C_BasePlayer *this, const QAngle *angleOffset)
{
  unsigned int m_Index; // edx
  CNetworkVectorBase<QAngle,CPlayerLocalData::NetworkVar_m_vecPunchAngleVel> *p_m_vecPunchAngleVel; // esi
  float v4; // [esp+0h] [ebp-Ch]
  float v5; // [esp+4h] [ebp-8h]
  float v6; // [esp+8h] [ebp-4h]

  if ( sv_suppress_viewpunch.m_pParent == nullptr || sv_suppress_viewpunch.m_pParent->m_Value.m_nValue == 0 )
  {
    m_Index = this->m_hVehicle.m_Index;
    if ( m_Index == -1
      || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index)
      || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity == nullptr )
    {
      p_m_vecPunchAngleVel = &this->m_Local.m_vecPunchAngleVel;
      v4 = this->m_Local.m_vecPunchAngleVel.m_Value.x + (float)(angleOffset->x * 20.0);
      v5 = this->m_Local.m_vecPunchAngleVel.m_Value.y + (float)(angleOffset->y * 20.0);
      v6 = this->m_Local.m_vecPunchAngleVel.m_Value.z + (float)(angleOffset->z * 20.0);
      if ( v4 != this->m_Local.m_vecPunchAngleVel.m_Value.x
        || (float)(this->m_Local.m_vecPunchAngleVel.m_Value.y + (float)(angleOffset->y * 20.0)) != this->m_Local.m_vecPunchAngleVel.m_Value.y
        || (float)(this->m_Local.m_vecPunchAngleVel.m_Value.z + (float)(angleOffset->z * 20.0)) != this->m_Local.m_vecPunchAngleVel.m_Value.z )
      {
        this->m_Local.NetworkStateChanged(this: &this->m_Local, a2: p_m_vecPunchAngleVel);
        p_m_vecPunchAngleVel->m_Value.x = v4;
        p_m_vecPunchAngleVel->m_Value.y = v5;
        p_m_vecPunchAngleVel->m_Value.z = v6;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001B080
// Name: public: virtual void C_BasePlayer::CalcView(class Vector __near &,class QAngle __near &,float __near &,float __near &,float __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BasePlayer::CalcView(
        C_BasePlayer *this,
        Vector *eyeOrigin,
        QAngle *eyeAngles,
        float *zNear,
        float *zFar,
        float *fov)
{
  unsigned int m_Index; // ecx
  CEntInfo *v8; // eax
  IClientVehicle *v9; // eax
  int v10; // eax
  bool v11; // zf
  C_BasePlayer_vtbl *v12; // eax
  CStudioHdr *m_pStudioHdr; // edi
  int m_nValue; // eax
  const studiohdr_t *v15; // edi
  float *v16; // eax

  m_Index = this->m_hVehicle.m_Index;
  if ( m_Index != -1
    && (v8 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index],
        g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index))
    && v8->m_pEntity != nullptr
    && (v9 = (IClientVehicle *)((int (__thiscall *)(IHandleEntity *))v8->m_pEntity->__vftable[31].dtr_IHandleEntity)(a1: v8->m_pEntity)) != nullptr )
  {
    C_BasePlayer::CalcVehicleView(this, pVehicle: v9, eyeOrigin, eyeAngles, zNear, zFar, fov);
  }
  else
  {
    v10 = this->GetObserverMode(this);
    v11 = v10 == 0;
    v12 = this->C_BaseCombatCharacter::C_BaseFlex::C_BaseAnimatingOverlay::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable;
    if ( v11 )
      v12->CalcPlayerView(this, a2: eyeOrigin, a3: eyeAngles, a4: fov);
    else
      v12->CalcObserverView(this, a2: eyeOrigin, a3: eyeAngles, a4: fov);
  }
  if ( (_S6_2 & 1) == 0 )
  {
    _S6_2 |= 1u;
    ConVarRef::ConVarRef(this: &cvFollowBoneIndexVar, pName: "cl_camera_follow_bone_index");
  }
  m_pStudioHdr = this->m_pStudioHdr;
  if ( m_pStudioHdr != nullptr )
    goto LABEL_26;
  if ( this->GetModel(this: &this->IClientRenderable) != nullptr )
    C_BaseAnimating::LockStudioHdr(this);
  m_pStudioHdr = this->m_pStudioHdr;
  if ( m_pStudioHdr != nullptr )
  {
LABEL_26:
    if ( m_pStudioHdr->m_pStudioHdr != nullptr
      && ConVarRef::IsValid(this: (SplitScreenConVarRef *)&cvFollowBoneIndexVar)
      && C_BasePlayer::GetLocalPlayer(nSlot: -1) == this )
    {
      m_nValue = cvFollowBoneIndexVar.m_pConVarState->m_Value.m_nValue;
      if ( m_nValue >= -1 )
      {
        v15 = m_pStudioHdr->m_pStudioHdr;
        if ( m_nValue < v15->numbones )
        {
          if ( m_nValue == -1 )
          {
            g_cameraFollowPos = *this->GetRenderOrigin(this: &this->IClientRenderable);
          }
          else if ( (*(int *)((_BYTE *)&v15->boneindex + 216 * m_nValue + v15->boneindex) & 0x7FF00) != 0 )
          {
            v16 = (float *)&this->m_BoneAccessor.m_pBones[m_nValue];
            g_cameraFollowPos.x = v16[3];
            g_cameraFollowPos.y = v16[7];
            g_cameraFollowPos.z = v16[11];
          }
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001B240
// Name: public: virtual void C_BasePlayer::SharedSpawn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BasePlayer::SharedSpawn(C_BasePlayer *this)
{
  int v2; // eax
  int (*GetViewVectors)(void); // edx
  const Vector *v4; // ebx
  Vector *p_m_vDuckHullMin; // eax
  IMDLCache *cacheCriticalSection; // [esp+18h] [ebp-4h]

  C_BaseEntity::SetMoveType(this, val: MOVETYPE_WALK, moveCollide: MOVECOLLIDE_DEFAULT);
  CCollisionProperty::SetSolid(this: &this->m_Collision, val: SOLID_BBOX);
  CCollisionProperty::SetSolidFlags(this: &this->m_Collision, flags: this->m_Collision.m_usSolidFlags.m_Value | 0x10);
  this->m_flFriction = 1.0;
  if ( this->pl.deadflag.m_Value )
  {
    this->pl.NetworkStateChanged(this: &this->pl, a2: &this->pl.deadflag);
    this->pl.deadflag.m_Value = false;
  }
  this->m_lifeState = 0;
  this->m_iHealth = 100;
  this->m_takedamage = 2;
  this->m_Local.m_bDrawViewmodel = true;
  this->m_Local.m_flStepSize = sv_stepsize.m_pParent->m_Value.m_fValue;
  this->m_Local.m_bAllowAutoMovement = true;
  C_BaseEntity::SetRenderFX(this, nRenderFX: kRenderFxNone, flStartTime: 3.4028235e38, flDuration: 0.0);
  this->m_flNextAttack = *(float *)(gpGlobals.m_Index + 12);
  this->m_flMaxspeed = 0.0;
  cacheCriticalSection = mdlcache;
  ((void (*)(void))mdlcache->BeginLock)();
  v2 = C_BaseAnimating::SelectWeightedSequence(this, activity: 1);
  if ( v2 < 0 )
    v2 = 0;
  C_BaseAnimating::SetSequence(this, nSequence: v2);
  GetViewVectors = (int (*)(void))g_pGameRules->GetViewVectors;
  if ( (this->m_fFlags & 2) != 0 )
  {
    v4 = (const Vector *)(GetViewVectors() + 48);
    p_m_vDuckHullMin = &g_pGameRules->GetViewVectors(this: g_pGameRules)->m_vDuckHullMin;
  }
  else
  {
    v4 = (const Vector *)(GetViewVectors() + 24);
    p_m_vDuckHullMin = &g_pGameRules->GetViewVectors(this: g_pGameRules)->m_vHullMin;
  }
  CCollisionProperty::SetCollisionBounds(this: &this->m_Collision, mins: p_m_vDuckHullMin, maxs: v4);
  this->m_Local.m_flFallVelocity = 0.0;
  C_BaseCombatCharacter::SetBloodColor(this, nBloodColor: 0);
  this->m_hUseEntity.m_Index = -1;
  cacheCriticalSection->EndLock(this: cacheCriticalSection);
}

//------------------------------------------------------------------------------
// Address: 0x1001B630
// Name: public: virtual void C_BasePlayer::PlayStepSound(class Vector __near &,struct surfacedata_t __near *,float,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BasePlayer::PlayStepSound(
        C_BasePlayer *this,
        Vector *vecOrigin,
        surfacedata_t *psurface,
        float fvol,
        bool force)
{
  int m_nStepside; // esi
  int v7; // edi
  char *v8; // esi
  CSoundParameters *v9; // esi
  CSoundParameters *p_params; // edi
  IPhysicsSurfaceProps *v11; // eax
  const char *v12; // eax
  int (__thiscall *entindex)(IClientNetworkable *); // eax
  int v14; // eax
  CSoundParameters params; // [esp+4h] [ebp-11Ch] BYREF
  C_RecipientFilter filter; // [esp+B8h] [ebp-68h] BYREF
  EmitSound_t ep; // [esp+D8h] [ebp-48h] BYREF

  if ( (*(int *)(gpGlobals.m_Index + 20) <= 1 || sv_footsteps.m_pParent->m_Value.m_fValue != 0.0)
    && (!prediction->InPrediction(this: prediction) || prediction->IsFirstTimePredicted(this: prediction))
    && psurface != nullptr )
  {
    m_nStepside = this->m_Local.m_nStepside;
    v7 = m_nStepside != 0 ? psurface->sounds.runStepLeft : psurface->sounds.runStepRight;
    if ( (_WORD)v7 != 0 )
    {
      this->m_Local.m_nStepside = m_nStepside == 0;
      CSoundParameters::CSoundParameters(this: &params);
      v8 = (char *)this + 184 * m_nStepside;
      if ( *((_WORD *)v8 + 3230) == (_WORD)v7 )
      {
        v9 = (CSoundParameters *)(v8 + 6280);
        p_params = &params;
      }
      else
      {
        v11 = IMoveHelper::sm_pSingleton->GetSurfaceProps(this: IMoveHelper::sm_pSingleton);
        v12 = v11->GetString(this: v11, a2: v7);
        if ( !C_BaseEntity::GetParametersForSound(soundname: v12, &params, actormodel: nullptr) )
          return;
        if ( params.count != 1 )
          goto LABEL_16;
        *((_WORD *)v8 + 3230) = v7;
        p_params = (CSoundParameters *)(v8 + 6280);
        v9 = &params;
      }
      qmemcpy(p_params, v9, sizeof(CSoundParameters));
LABEL_16:
      C_RecipientFilter::C_RecipientFilter(this: &filter);
      if ( prediction->InPrediction(this: prediction) )
        C_RecipientFilter::UsePredictionRules(this: &filter);
      C_RecipientFilter::AddRecipientsByPVS(this: &filter, origin: vecOrigin);
      EmitSound_t::EmitSound_t(this: &ep);
      ep.m_pSoundName = params.soundname;
      ep.m_SoundLevel = params.soundlevel;
      ep.m_nPitch = params.pitch;
      ep.m_hSoundScriptHandle = params.m_hSoundScriptHandle;
      ep.m_nSoundEntryVersion = params.m_nSoundEntryVersion;
      entindex = this->entindex;
      ep.m_nChannel = 4;
      ep.m_flVolume = fvol;
      ep.m_nFlags = 0;
      ep.m_pOrigin = vecOrigin;
      v14 = entindex(this: &this->IClientNetworkable);
      C_BaseEntity::EmitSound(&filter, iEntIndex: v14, params: &ep);
      CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>::~CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&ep.m_UtlVecSoundOrigin);
      C_RecipientFilter::~C_RecipientFilter(this: &filter);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001B7F0
// Name: public: void C_BasePlayer::AddToPlayerSimulationList(class C_BaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BasePlayer::AddToPlayerSimulationList(C_BasePlayer *this, C_BaseEntity *other)
{
  unsigned int m_Index; // ebx
  int m_nAllocationCount; // eax
  int m_Size; // edi
  CHandle<C_BaseEntity> *m_pMemory; // ecx
  int v7; // eax
  CHandle<C_BaseEntity> *v8; // eax

  if ( other != nullptr )
    m_Index = other->GetRefEHandle(this: other)->m_Index;
  else
    m_Index = -1;
  other = (C_BaseEntity *)m_Index;
  if ( CUtlVector<CHandle<C_BasePlayer>,CUtlMemory<CHandle<C_BasePlayer>,int>>::Find(
         this: (CUtlVector<CHandle<C_BasePlayer>,CUtlMemory<CHandle<C_BasePlayer>,int> > *)&this->m_SimulatedByThisPlayer,
         src: (CHandle<C_BaseCombatWeapon> *)&other) == -1 )
  {
    m_nAllocationCount = this->m_SimulatedByThisPlayer.m_Memory.m_nAllocationCount;
    m_Size = this->m_SimulatedByThisPlayer.m_Size;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<CChoreoActor *,int>::Grow(
        this: (CUtlMemory<vgui::TreeNode *,int> *)&this->m_SimulatedByThisPlayer,
        num: m_Size - m_nAllocationCount + 1);
    ++this->m_SimulatedByThisPlayer.m_Size;
    m_pMemory = this->m_SimulatedByThisPlayer.m_Memory.m_pMemory;
    v7 = this->m_SimulatedByThisPlayer.m_Size - m_Size - 1;
    this->m_SimulatedByThisPlayer.m_pElements = m_pMemory;
    if ( v7 > 0 )
      _V_memmove(dest: (void *)&m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v7);
    v8 = &this->m_SimulatedByThisPlayer.m_Memory.m_pMemory[m_Size];
    if ( v8 != nullptr )
      v8->m_Index = m_Index;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001B8A0
// Name: public: void C_BasePlayer::SmoothViewOnStairs(class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BasePlayer::SmoothViewOnStairs(C_BasePlayer *this, Vector *eyeOrigin)
{
  C_BaseEntity *GroundEntity; // edi
  const Vector *LocalOrigin; // eax
  const Vector *(__thiscall *GetViewOffset)(C_BaseEntity *); // edx
  CDiscontinuousInterpolatedVar<Vector> *OriginInterpolator; // eax
  const Vector *v7; // eax
  float z; // xmm1_4
  float m_flOldPlayerZ; // xmm0_4
  int v10; // eax
  float v11; // xmm0_4
  float v12; // xmm0_4
  float v13; // xmm0_4
  float currentTime; // [esp+0h] [ebp-54h]
  matrix3x4_t matOriginDisontinuity; // [esp+10h] [ebp-44h] BYREF
  Vector vCurrentSpaceLocalOrigin; // [esp+40h] [ebp-14h] BYREF
  float flCurrentPlayerZ; // [esp+4Ch] [ebp-8h]
  float flCurrentPlayerViewOffsetZ; // [esp+50h] [ebp-4h]

  GroundEntity = C_BaseEntity::GetGroundEntity(this);
  LocalOrigin = C_BaseEntity::GetLocalOrigin(this);
  GetViewOffset = this->GetViewOffset;
  flCurrentPlayerZ = LocalOrigin->z;
  flCurrentPlayerViewOffsetZ = GetViewOffset(this)->z;
  currentTime = C_BaseEntity::GetEffectiveInterpolationCurTime(this, currentTime: *(float *)(gpGlobals.m_Index + 12));
  OriginInterpolator = C_BaseEntity::GetOriginInterpolator(this);
  if ( CDiscontinuousInterpolatedVar<Vector>::GetDiscontinuityTransform(
         this: OriginInterpolator,
         fCurTime: currentTime,
         matOut: &matOriginDisontinuity) )
  {
    v7 = C_BaseEntity::GetLocalOrigin(this);
    VectorITransform(in1: &v7->x, in2: &matOriginDisontinuity, out: &vCurrentSpaceLocalOrigin.x);
    z = vCurrentSpaceLocalOrigin.z;
  }
  else
  {
    z = flCurrentPlayerZ;
  }
  if ( GroundEntity != nullptr
    && GroundEntity->m_MoveType == 0
    && (m_flOldPlayerZ = this->m_flOldPlayerZ, z != m_flOldPlayerZ)
    && smoothstairs.m_pParent != nullptr
    && smoothstairs.m_pParent->m_Value.m_nValue != 0
    && this->m_flOldPlayerViewOffsetZ == flCurrentPlayerViewOffsetZ )
  {
    if ( z <= m_flOldPlayerZ )
      v10 = -1;
    else
      v10 = 1;
    v11 = *(float *)(gpGlobals.m_Index + 16);
    if ( v11 < 0.0 )
      v11 = 0.0;
    v12 = (float)((float)(v11 * 150.0) * (float)v10) + this->m_flOldPlayerZ;
    this->m_flOldPlayerZ = v12;
    if ( v10 <= 0 )
    {
      if ( z > v12 )
        this->m_flOldPlayerZ = z;
      if ( (float)(z - this->m_flOldPlayerZ) < -18.0 )
        this->m_flOldPlayerZ = z + 18.0;
    }
    else
    {
      if ( v12 > z )
        this->m_flOldPlayerZ = z;
      if ( (float)(z - this->m_flOldPlayerZ) > 18.0 )
        this->m_flOldPlayerZ = z - 18.0;
    }
    eyeOrigin->z = (float)(this->m_flOldPlayerZ - z) + eyeOrigin->z;
  }
  else
  {
    v13 = flCurrentPlayerViewOffsetZ;
    this->m_flOldPlayerZ = z;
    this->m_flOldPlayerViewOffsetZ = v13;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001BA80
// Name: protected: virtual void C_BasePlayer::CalcPlayerView(class Vector __near &,class QAngle __near &,float __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BasePlayer::CalcPlayerView(C_BasePlayer *this, Vector *eyeOrigin, QAngle *eyeAngles, float *fov)
{
  vgui::ToggleButton *v5; // ecx
  bool v6; // zf
  Vector *(__thiscall *EyePosition)(C_BaseEntity *, Vector *); // edx
  float *v8; // eax
  float v9; // xmm1_4
  float v10; // xmm2_4
  Vector *v11; // ebx
  const QAngle *v12; // eax
  QAngle *v13; // edi
  float v14; // xmm1_4
  float v15; // xmm2_4
  int v16; // eax
  CViewEffects *ViewEffects; // eax
  CViewEffects *v18; // eax
  float (__thiscall *GetFOV)(C_BasePlayer *); // eax
  Vector v20; // [esp+28h] [ebp-1Ch] BYREF
  Vector vSmoothOffset; // [esp+34h] [ebp-10h] BYREF
  C_BasePlayer_vtbl *v22; // [esp+40h] [ebp-4h]
  float eyeOrigina; // [esp+4Ch] [ebp+8h]
  float eyeAnglesa; // [esp+50h] [ebp+Ch]

  if ( !prediction->InPrediction(this: prediction) )
    view->DriftPitch(this: view);
  v6 = !IsPresetCurrentCostDebuggingEnabled(this: v5);
  EyePosition = this->EyePosition;
  if ( v6 )
  {
    v11 = eyeOrigin;
    *eyeOrigin = *EyePosition(this, result: &v20);
    v13 = eyeAngles;
    *eyeAngles = *this->EyeAngles(this);
  }
  else
  {
    v8 = (float *)EyePosition(this, result: &v20);
    v9 = v8[1] + vec3_origin.y;
    v10 = v8[2] + vec3_origin.z;
    v11 = eyeOrigin;
    eyeOrigin->x = *v8 + vec3_origin.x;
    eyeOrigin->y = v9;
    eyeOrigin->z = v10;
    v12 = this->EyeAngles(this);
    v13 = eyeAngles;
    v14 = v12->y + vec3_angle.y;
    v15 = v12->z + vec3_angle.z;
    eyeAngles->x = v12->x + vec3_angle.x;
    eyeAngles->y = v14;
    eyeAngles->z = v15;
  }
  if ( !prediction->InPrediction(this: prediction) )
    C_BasePlayer::SmoothViewOnStairs(this, eyeOrigin: v11);
  this->CalcViewBob(this, a2: v11);
  if ( this->m_MoveType != 8 )
  {
    eyeOrigina = sv_rollspeed.m_pParent->m_Value.m_fValue;
    eyeAnglesa = sv_rollangle.m_pParent->m_Value.m_fValue;
    C_BaseEntity::CalcAbsoluteVelocity(this);
    v22 = this->C_BaseCombatCharacter::C_BaseFlex::C_BaseAnimatingOverlay::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable;
    v16 = ((int (__thiscall *)(C_BasePlayer *, Vector *, float, float))v22->GetAbsAngles)(
            a1: this,
            a2: &this->m_vecAbsVelocity,
            a3: COERCE_FLOAT(LODWORD(eyeAnglesa)),
            a4: COERCE_FLOAT(LODWORD(eyeOrigina)));
    v13->z = ((double (__thiscall *)(C_BasePlayer *, int))v22->CalcRoll)(a1: this, a2: v16) + v13->z;
  }
  v13->x = this->m_Local.m_vecPunchAngle.m_Value.x + v13->x;
  v13->y = this->m_Local.m_vecPunchAngle.m_Value.y + v13->y;
  v13->z = this->m_Local.m_vecPunchAngle.m_Value.z + v13->z;
  if ( !prediction->InPrediction(this: prediction) )
  {
    ViewEffects = GetViewEffects();
    ViewEffects->CalcShake(this: ViewEffects);
    v18 = GetViewEffects();
    ((void (__thiscall *)(CViewEffects *, Vector *, QAngle *, int))v18->ApplyShake)(
      a1: v18,
      a2: v11,
      a3: v13,
      a4: 1065353216);
  }
  C_BasePlayer::GetPredictionErrorSmoothingVector(this, vOffset: &vSmoothOffset);
  v11->x = v11->x + vSmoothOffset.x;
  v11->y = v11->y + vSmoothOffset.y;
  v11->z = v11->z + vSmoothOffset.z;
  GetFOV = this->GetFOV;
  this->m_flObserverChaseDistance = 0.0;
  *fov = GetFOV(this);
}

//------------------------------------------------------------------------------
// Address: 0x1001BCE0
// Name: private: void C_BasePlayer::UpdateSplitScreenAndPictureInPicturePlayerList(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BasePlayer::UpdateSplitScreenAndPictureInPicturePlayerList(C_BasePlayer *this)
{
  int v2; // eax
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CHandle<C_BasePlayer> *m_pMemory; // ecx
  int v6; // eax
  CHandle<C_BasePlayer> *v7; // eax
  int i; // [esp+8h] [ebp-8h]
  CHandle<C_BasePlayer> h; // [esp+Ch] [ebp-4h] BYREF

  this->m_hSplitScreenAndPipPlayers.m_Size = 0;
  CUtlVector<CBaseAchievement *,CUtlMemory<CBaseAchievement *,int>>::AddVectorToTail(
    this: (CUtlVector<CBaseAchievement *,CUtlMemory<CBaseAchievement *,int> > *)&this->m_hSplitScreenAndPipPlayers,
    src: (const CUtlVector<CBaseAchievement *,CUtlMemory<CBaseAchievement *,int> > *)&this->m_hSplitScreenPlayers);
  v2 = 0;
  for ( i = 0; v2 < this->m_hPipPlayers.m_Size; i = v2 )
  {
    h.m_Index = this->m_hPipPlayers.m_Memory.m_pMemory[v2].m_Index;
    if ( CUtlVector<CHandle<C_BasePlayer>,CUtlMemory<CHandle<C_BasePlayer>,int>>::Find(
           this: &this->m_hSplitScreenAndPipPlayers,
           src: (CHandle<C_BaseCombatWeapon> *)&h) == -1 )
    {
      m_Size = this->m_hSplitScreenAndPipPlayers.m_Size;
      m_nAllocationCount = this->m_hSplitScreenAndPipPlayers.m_Memory.m_nAllocationCount;
      if ( m_Size + 1 > m_nAllocationCount )
        CUtlMemory<CChoreoActor *,int>::Grow(
          this: (CUtlMemory<vgui::TreeNode *,int> *)&this->m_hSplitScreenAndPipPlayers,
          num: m_Size - m_nAllocationCount + 1);
      ++this->m_hSplitScreenAndPipPlayers.m_Size;
      m_pMemory = this->m_hSplitScreenAndPipPlayers.m_Memory.m_pMemory;
      v6 = this->m_hSplitScreenAndPipPlayers.m_Size - m_Size - 1;
      this->m_hSplitScreenAndPipPlayers.m_pElements = m_pMemory;
      if ( v6 > 0 )
        _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v6);
      v7 = &this->m_hSplitScreenAndPipPlayers.m_Memory.m_pMemory[m_Size];
      if ( v7 != nullptr )
        v7->m_Index = h.m_Index;
    }
    v2 = i + 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001BDD0
// Name: public: void C_BasePlayer::AddSplitScreenPlayer(class C_BasePlayer __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BasePlayer::AddSplitScreenPlayer(C_BasePlayer *this, C_BasePlayer *pOther)
{
  unsigned int m_Index; // ebx
  int m_nAllocationCount; // eax
  int m_Size; // edi
  CHandle<C_BasePlayer> *m_pMemory; // ecx
  int v7; // eax
  CHandle<C_BasePlayer> *v8; // eax

  if ( pOther != nullptr )
    m_Index = pOther->GetRefEHandle(this: pOther)->m_Index;
  else
    m_Index = -1;
  pOther = (C_BasePlayer *)m_Index;
  if ( CUtlVector<CHandle<C_BasePlayer>,CUtlMemory<CHandle<C_BasePlayer>,int>>::Find(
         this: &this->m_hSplitScreenPlayers,
         src: (CHandle<C_BaseCombatWeapon> *)&pOther) == -1 )
  {
    m_nAllocationCount = this->m_hSplitScreenPlayers.m_Memory.m_nAllocationCount;
    m_Size = this->m_hSplitScreenPlayers.m_Size;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<CChoreoActor *,int>::Grow(
        this: (CUtlMemory<vgui::TreeNode *,int> *)&this->m_hSplitScreenPlayers,
        num: m_Size - m_nAllocationCount + 1);
    ++this->m_hSplitScreenPlayers.m_Size;
    m_pMemory = this->m_hSplitScreenPlayers.m_Memory.m_pMemory;
    v7 = this->m_hSplitScreenPlayers.m_Size - m_Size - 1;
    this->m_hSplitScreenPlayers.m_pElements = m_pMemory;
    if ( v7 > 0 )
      _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v7);
    v8 = &this->m_hSplitScreenPlayers.m_Memory.m_pMemory[m_Size];
    if ( v8 != nullptr )
      v8->m_Index = m_Index;
  }
  C_BasePlayer::UpdateSplitScreenAndPictureInPicturePlayerList(this);
}

//------------------------------------------------------------------------------
// Address: 0x1001BE80
// Name: public: void C_BasePlayer::RemoveSplitScreenPlayer(class C_BasePlayer __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BasePlayer::RemoveSplitScreenPlayer(C_BasePlayer *this, unsigned int pOther)
{
  int v3; // eax

  if ( pOther != 0 )
    pOther = *(_DWORD *)(*(int (__thiscall **)(unsigned int))(*(_DWORD *)pOther + 8))(a1: pOther);
  else
    pOther = -1;
  v3 = CUtlVector<CHandle<C_BasePlayer>,CUtlMemory<CHandle<C_BasePlayer>,int>>::Find(
         this: &this->m_hSplitScreenPlayers,
         src: (CHandle<C_BaseCombatWeapon> *)&pOther);
  if ( v3 != -1 )
  {
    if ( this->m_hSplitScreenPlayers.m_Size - v3 - 1 > 0 )
      _V_memmove(
        dest: &this->m_hSplitScreenPlayers.m_Memory.m_pMemory[v3],
        src: &this->m_hSplitScreenPlayers.m_Memory.m_pMemory[v3 + 1],
        count: 4 * (this->m_hSplitScreenPlayers.m_Size - v3 - 1));
    --this->m_hSplitScreenPlayers.m_Size;
  }
  C_BasePlayer::UpdateSplitScreenAndPictureInPicturePlayerList(this);
}

// ============================================================
// Overlay from server (Missing functions)
// ============================================================
namespace server {

//------------------------------------------------------------------------------
// Address: 0x100D8040
// Name: public: bool color32_s::operator!=(struct color32_s const __near &)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall color32_s::operator!=(color32_s *this, const color32_s *other)
{
  return this->r != other->r || this->g != other->g || this->b != other->b || this->a != other->a;
}

//------------------------------------------------------------------------------
// Address: 0x100D8080
// Name: class CCSPlayer __near * ToCSPlayer(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
CCSPlayer *__cdecl ToCSPlayer(CBaseEntity *pEntity)
{
  if ( pEntity != nullptr && pEntity->IsPlayer(this: pEntity) )
    return (CCSPlayer *)__RTDynamicCast(
                          inptr: pEntity,
                          VfDelta: 0,
                          SrcType: &CBaseEntity `RTTI Type Descriptor',
                          TargetType: &CCSPlayer `RTTI Type Descriptor',
                          isReference: 0);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x100D80C0
// Name: public: bool CBasePlayer::UsingStandardWeaponsInVehicle(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBasePlayer::UsingStandardWeaponsInVehicle(CBasePlayer *this)
{
  IServerVehicle *v2; // esi
  int v4; // eax

  v2 = this->GetVehicle(this);
  if ( v2 == nullptr )
    return true;
  v4 = v2->GetPassengerRole(this: v2, a2: this);
  return v2->IsPassengerUsingStandardWeapons(this: v2, a2: v4);
}

//------------------------------------------------------------------------------
// Address: 0x100D8100
// Name: public: virtual class QAngle const __near & CBasePlayer::LocalEyeAngles(void)
// Source: json
//------------------------------------------------------------------------------
const QAngle *__thiscall CBasePlayer::LocalEyeAngles(CBasePlayer *this)
{
  return &this->pl.v_angle;
}

//------------------------------------------------------------------------------
// Address: 0x100D8110
// Name: public: void CBasePlayer::CacheVehicleView(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBasePlayer::CacheVehicleView(CBasePlayer *this)
{
  IServerVehicle *v2; // eax
  IServerVehicle *v3; // edi
  int v4; // eax

  if ( this->m_nVehicleViewSavedFrame != gpGlobals->framecount )
  {
    v2 = this->GetVehicle(this);
    v3 = v2;
    if ( v2 != nullptr )
    {
      v4 = v2->GetPassengerRole(this: v2, a2: this);
      v3->GetVehicleViewPosition(
        this: v3,
        a2: v4,
        a3: &this->m_vecVehicleViewOrigin,
        a4: &this->m_vecVehicleViewAngles,
        a5: &this->m_flVehicleViewFOV);
      this->m_nVehicleViewSavedFrame = gpGlobals->framecount;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D8180
// Name: public: void CBasePlayer::EyeVectors(class Vector __near *,class Vector __near *,class Vector __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBasePlayer::EyeVectors(CBasePlayer *this, Vector *pForward, Vector *pRight, Vector *pUp)
{
  const QAngle *v5; // eax

  if ( this->GetVehicle(this) != nullptr )
  {
    CBasePlayer::CacheVehicleView(this);
    AngleVectors(angles: &this->m_vecVehicleViewAngles, forward: pForward, right: pRight, up: pUp);
  }
  else
  {
    v5 = this->EyeAngles(this);
    AngleVectors(angles: v5, forward: pForward, right: pRight, up: pUp);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D81F0
// Name: public: void CBasePlayer::EyePositionAndVectors(class Vector __near *,class Vector __near *,class Vector __near *,class Vector __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBasePlayer::EyePositionAndVectors(
        CBasePlayer *this,
        Vector *pPosition,
        Vector *pForward,
        Vector *pRight,
        Vector *pUp)
{
  const QAngle *v6; // eax
  _BYTE v7[12]; // [esp+4h] [ebp-Ch] BYREF

  if ( this->GetVehicle(this) != nullptr )
  {
    CBasePlayer::CacheVehicleView(this);
    AngleVectors(angles: &this->m_vecVehicleViewAngles, forward: pForward, right: pRight, up: pUp);
    if ( pPosition != nullptr )
      *pPosition = this->m_vecVehicleViewOrigin;
  }
  else
  {
    *pPosition = *this->EyePosition(this, result: v7);
    v6 = this->EyeAngles(this);
    AngleVectors(angles: v6, forward: pForward, right: pRight, up: pUp);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D82A0
// Name: public: virtual struct surfacedata_t __near * CBasePlayer::GetLadderSurface(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
surfacedata_t *__thiscall CBasePlayer::GetLadderSurface(CBasePlayer *this, const Vector *origin)
{
  IPhysicsSurfaceProps_vtbl *v2; // esi
  int v3; // eax

  v2 = physprops->__vftable;
  v3 = physprops->GetSurfaceIndex(this: physprops, a2: "ladder");
  return v2->GetSurfaceData(this: physprops, a2: v3);
}

//------------------------------------------------------------------------------
// Address: 0x100D82D0
// Name: protected: void CBasePlayer::UpdateButtonState(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBasePlayer::UpdateButtonState(CBasePlayer *this, int nUserCmdButtonMask)
{
  int v2; // edx

  this->m_afButtonLast = this->m_nButtons;
  v2 = nUserCmdButtonMask ^ this->m_afButtonLast;
  this->m_nButtons = nUserCmdButtonMask;
  this->m_afButtonPressed = nUserCmdButtonMask & v2;
  this->m_afButtonReleased = v2 & ~nUserCmdButtonMask;
}

//------------------------------------------------------------------------------
// Address: 0x100D8310
// Name: public: void CBasePlayer::SetAnimationExtension(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBasePlayer::SetAnimationExtension(CBasePlayer *this, const char *pExtension)
{
  V_strncpy(pDest: this->m_szAnimExtension, pSrc: pExtension, maxLen: 32);
}

//------------------------------------------------------------------------------
// Address: 0x100D8330
// Name: public: virtual bool CBasePlayer::Weapon_Switch(class CBaseCombatWeapon __near *,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CBasePlayer::Weapon_Switch(CBasePlayer *this, CBaseCombatWeapon *pWeapon, int viewmodelindex)
{
  CBaseCombatWeapon *ActiveWeapon; // edi
  CBasePlayer_vtbl *v5; // ebx
  CBaseCombatWeapon *v6; // eax
  CBasePlayer_vtbl *v7; // ebx
  int v8; // eax
  CBaseViewModel *ViewModel; // eax

  ActiveWeapon = CBaseCombatCharacter::GetActiveWeapon(this);
  if ( !CBaseCombatCharacter::Weapon_Switch(this, pWeapon, viewmodelindex) )
    return 0;
  if ( ActiveWeapon != nullptr )
  {
    v5 = this->__vftable;
    v6 = CBaseCombatCharacter::GetActiveWeapon(this);
    if ( v5->Weapon_ShouldSetLast(this, a2: ActiveWeapon, a3: v6) )
    {
      v7 = this->__vftable;
      v8 = (int)ActiveWeapon->GetLastWeapon(this: ActiveWeapon);
      v7->Weapon_SetLast(this, a2: (CBaseCombatWeapon *)v8);
    }
  }
  ViewModel = CBasePlayer::GetViewModel(this, index: viewmodelindex);
  if ( ViewModel != nullptr )
    ViewModel->RemoveEffects(this: ViewModel, a2: 32);
  CBasePlayer::ResetAutoaim(this);
  this->OnSwitchWeapons(this, a2: pWeapon);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100D83D0
// Name: public: virtual bool CBasePlayer::Weapon_ShouldSelectItem(class CBaseCombatWeapon __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBasePlayer::Weapon_ShouldSelectItem(CBasePlayer *this, CBaseCombatWeapon *pWeapon)
{
  return pWeapon != CBaseCombatCharacter::GetActiveWeapon(this);
}

//------------------------------------------------------------------------------
// Address: 0x100D83F0
// Name: public: virtual void CBasePlayer::SelectItem(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBasePlayer::SelectItem(CBasePlayer *this, const char *pstr, int iSubType)
{
  CBaseCombatWeapon *v4; // edi
  CBaseCombatWeapon *ActiveWeapon; // eax

  if ( pstr != nullptr )
  {
    v4 = this->Weapon_OwnsThisType(this, a2: pstr, a3: iSubType);
    if ( v4 != nullptr && this->GetObserverMode(this) == 0 && this->Weapon_ShouldSelectItem(this, a2: v4) )
    {
      if ( CBaseCombatCharacter::GetActiveWeapon(this) != nullptr )
      {
        ActiveWeapon = CBaseCombatCharacter::GetActiveWeapon(this);
        if ( !ActiveWeapon->CanHolster(this: ActiveWeapon) )
          return;
        CBasePlayer::ResetAutoaim(this);
      }
      this->Weapon_Switch(this, a2: v4, a3: 0);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D8480
// Name: public: virtual void CBasePlayer::DoMuzzleFlash(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBasePlayer::DoMuzzleFlash(CBasePlayer *this)
{
  int i; // esi
  CBaseViewModel *ViewModel; // eax

  for ( i = 0; i < 2; ++i )
  {
    ViewModel = CBasePlayer::GetViewModel(this, index: i);
    if ( ViewModel != nullptr )
      CBaseAnimating::DoMuzzleFlash(this: ViewModel);
  }
  CBaseCombatCharacter::DoMuzzleFlash(this);
}

//------------------------------------------------------------------------------
// Address: 0x100D84B0
// Name: public: virtual char const __near * CBasePlayer::GetTracerType(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CBasePlayer::GetTracerType(CAI_BaseNPC *this)
{
  CBaseCombatWeapon *ActiveWeapon; // eax

  if ( CBaseCombatCharacter::GetActiveWeapon(this) == nullptr )
    return (const char *)CHEGrenade::YouForgotToImplementOrDeclareServerClass((vgui::CTreeViewListControl *)this);
  ActiveWeapon = CBaseCombatCharacter::GetActiveWeapon(this);
  return ActiveWeapon->GetTracerType(this: ActiveWeapon);
}

//------------------------------------------------------------------------------
// Address: 0x100D84E0
// Name: public: virtual void CBasePlayer::SetPlayerUnderwater(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBasePlayer::SetPlayerUnderwater(CBasePlayer *this, bool state)
{
  if ( this->m_bPlayerUnderwater != state )
    this->m_bPlayerUnderwater = state;
}

//------------------------------------------------------------------------------
// Address: 0x100D8500
// Name: public: void CBasePlayer::SetPreviouslyPredictedOrigin(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBasePlayer::SetPreviouslyPredictedOrigin(CBasePlayer *this, const Vector *vecAbsOrigin)
{
  this->m_vecPreviouslyPredictedOrigin = *vecAbsOrigin;
}

//------------------------------------------------------------------------------
// Address: 0x100D8530
// Name: public: class Vector const __near & CBasePlayer::GetPreviouslyPredictedOrigin(void)const
// Source: json
//------------------------------------------------------------------------------
const Vector *__thiscall CBasePlayer::GetPreviouslyPredictedOrigin(CBasePlayer *this)
{
  return &this->m_vecPreviouslyPredictedOrigin;
}

//------------------------------------------------------------------------------
// Address: 0x100D8560
// Name: public: void CBasePlayer::ForceButtons(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBasePlayer::ForceButtons(CBasePlayer *this, int nButtons)
{
  this->m_afButtonForced |= nButtons;
}

//------------------------------------------------------------------------------
// Address: 0x100D8570
// Name: public: void CBasePlayer::UnforceButtons(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBasePlayer::UnforceButtons(CBasePlayer *this, int nButtons)
{
  this->m_afButtonForced &= ~nButtons;
}

//------------------------------------------------------------------------------
// Address: 0x100D8590
// Name: public: virtual float CBasePlayer::GetHeldObjectMass(class IPhysicsObject __near *)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CBasePlayer::GetHeldObjectMass(CAI_BaseNPC *this, __int16 sHintType)
{
  return 0.0;
}

//------------------------------------------------------------------------------
// Address: 0x100D85A0
// Name: public: virtual char const __near * CBasePlayer::GetPlayerModelName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CBasePlayer::GetPlayerModelName(CBasePlayer *this)
{
  return "models/player.mdl";
}

//------------------------------------------------------------------------------
// Address: 0x100D85B0
// Name: public: float CBasePlayer::GetTimeBase(void)const
// Source: json
//------------------------------------------------------------------------------
double __thiscall CBasePlayer::GetTimeBase(CBasePlayer *this)
{
  return (double)this->m_nTickBase.m_Value * gpGlobals->interval_per_tick;
}

//------------------------------------------------------------------------------
// Address: 0x100D85C0
// Name: public: void CBasePlayer::ItemPreFrame(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBasePlayer::ItemPreFrame(CBasePlayer *this)
{
  CBaseCombatWeapon *ActiveWeapon; // ebx
  int i; // esi
  CBaseCombatWeapon *Weapon; // eax

  this->PlayerUse(this);
  ActiveWeapon = CBaseCombatCharacter::GetActiveWeapon(this);
  for ( i = 0; i < 64; ++i )
  {
    Weapon = CBaseCombatCharacter::GetWeapon(this, i);
    if ( Weapon != nullptr && ActiveWeapon != Weapon )
      Weapon->ItemHolsterFrame(this: Weapon);
  }
  if ( this->m_flNextAttack.m_Value <= gpGlobals->curtime && ActiveWeapon != nullptr )
    ActiveWeapon->ItemPreFrame(this: ActiveWeapon);
}

//------------------------------------------------------------------------------
// Address: 0x100D8630
// Name: public: int CBasePlayer::GetDefaultFOV(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBasePlayer::GetDefaultFOV(CBasePlayer *this)
{
  int result; // eax

  result = this->m_iDefaultFOV.m_Value;
  if ( result == 0 )
    return g_pGameRules->DefaultFOV(this: g_pGameRules);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100D8650
// Name: public: bool fogparams_t::operator!=(struct fogparams_t const __near &)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall fogparams_t::operator!=(fogparams_t *this, const fogparams_t *other)
{
  bool result; // al

  if ( this->enable.m_Value != other->enable.m_Value )
    return true;
  if ( this->blend.m_Value != other->blend.m_Value )
    return true;
  if ( fabs(this->dirPrimary.m_Value.x - other->dirPrimary.m_Value.x) > 0.0099999998 )
    return true;
  if ( fabs(this->dirPrimary.m_Value.y - other->dirPrimary.m_Value.y) > 0.0099999998 )
    return true;
  if ( fabs(this->dirPrimary.m_Value.z - other->dirPrimary.m_Value.z) > 0.0099999998 )
    return true;
  if ( this->colorPrimary.m_Value.r != other->colorPrimary.m_Value.r )
    return true;
  if ( this->colorPrimary.m_Value.g != other->colorPrimary.m_Value.g )
    return true;
  if ( this->colorPrimary.m_Value.b != other->colorPrimary.m_Value.b )
    return true;
  if ( this->colorPrimary.m_Value.a != other->colorPrimary.m_Value.a )
    return true;
  if ( color32_s::operator!=(this: &this->colorSecondary.m_Value, other: &other->colorSecondary.m_Value) )
    return true;
  if ( this->start.m_Value != other->start.m_Value )
    return true;
  if ( this->end.m_Value != other->end.m_Value )
    return true;
  if ( this->farz.m_Value != other->farz.m_Value )
    return true;
  if ( this->maxdensity.m_Value != other->maxdensity.m_Value )
    return true;
  if ( color32_s::operator!=(this: &this->colorPrimaryLerpTo.m_Value, other: &other->colorPrimaryLerpTo.m_Value) )
    return true;
  result = color32_s::operator!=(this: &this->colorSecondaryLerpTo.m_Value, other: &other->colorSecondaryLerpTo.m_Value);
  if ( result
    || this->startLerpTo.m_Value != other->startLerpTo.m_Value
    || this->endLerpTo.m_Value != other->endLerpTo.m_Value
    || this->maxdensityLerpTo.m_Value != other->maxdensityLerpTo.m_Value
    || this->lerptime.m_Value != other->lerptime.m_Value
    || this->duration.m_Value != other->duration.m_Value
    || this->HDRColorScale.m_Value != other->HDRColorScale.m_Value )
  {
    return true;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100D87E0
// Name: public: bool CBasePlayer::IsRideablePhysics(class IPhysicsObject __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBasePlayer::IsRideablePhysics(CBasePlayer *this, IPhysicsObject *pPhysics)
{
  IPhysicsObject *m_pPhysicsObject; // esi
  double v3; // st7
  bool result; // al
  float pPhysicsa; // [esp+8h] [ebp+8h]

  result = false;
  if ( pPhysics != nullptr )
  {
    m_pPhysicsObject = this->m_pPhysicsObject;
    pPhysicsa = pPhysics->GetMass(this: pPhysics);
    v3 = ((double (__thiscall *)(IPhysicsObject *))m_pPhysicsObject->GetMass)(a1: m_pPhysicsObject);
    if ( pPhysicsa > v3 + v3 )
      return true;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100D8820
// Name: public: class CBaseEntity __near * CBasePlayer::GetViewEntity(void)
// Source: json
//------------------------------------------------------------------------------
CBaseEntity *__thiscall CBasePlayer::GetViewEntity(CBasePlayer *this)
{
  unsigned int m_Index; // ecx

  m_Index = this->m_hViewEntity.m_Value.m_Index;
  if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    return nullptr;
  else
    return (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
}

//------------------------------------------------------------------------------
// Address: 0x100D8850
// Name: public: virtual float CBasePlayer::GetPlayerMaxSpeed(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CBasePlayer::GetPlayerMaxSpeed(CBasePlayer *this)
{
  float m_Value; // xmm0_4
  float fMaxSpeed; // [esp+0h] [ebp-4h]

  m_Value = this->m_flMaxspeed.m_Value;
  fMaxSpeed = sv_maxspeed.m_pParent->m_Value.m_fValue;
  if ( m_Value > 0.0 && sv_maxspeed.m_pParent->m_Value.m_fValue > m_Value )
    return this->m_flMaxspeed.m_Value;
  return fMaxSpeed;
}

//------------------------------------------------------------------------------
// Address: 0x100D8890
// Name: public: virtual class QAngle const __near & CBasePlayer::EyeAngles(void)
// Source: json
//------------------------------------------------------------------------------
const QAngle *__thiscall CBasePlayer::EyeAngles(CBasePlayer *this)
{
  unsigned int m_Index; // eax
  CBaseEntity **v2; // edx
  CBaseEntity *v3; // esi
  unsigned int v4; // edx
  int v5; // eax
  CEntInfo *v6; // esi
  unsigned int v7; // edx
  int v8; // eax
  bool v9; // zf
  CEntInfo *v10; // eax
  const matrix3x4_t *p_m_rgflCoordinateFrame; // esi
  matrix3x4_t eyesToWorld; // [esp+8h] [ebp-60h] BYREF
  matrix3x4_t eyesToParent; // [esp+38h] [ebp-30h] BYREF
  int savedregs; // [esp+68h] [ebp+0h] BYREF

  m_Index = this->m_hMoveParent.m_Value.m_Index;
  if ( m_Index != -1
    && (v2 = (CBaseEntity **)&g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index],
        g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index))
    && (v3 = *v2, *v2 != nullptr) )
  {
    AngleMatrix(angles: &this->pl.v_angle, matrix: &eyesToParent);
    if ( (v3->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this: v3, a2: (int)&savedregs);
    p_m_rgflCoordinateFrame = &v3->m_rgflCoordinateFrame;
    ConcatTransforms(in1: p_m_rgflCoordinateFrame, in2: &eyesToParent, out: &eyesToWorld);
    if ( (_S2_53 & 1) == 0 )
      _S2_53 |= 1u;
    MatrixAngles(a1: (int)p_m_rgflCoordinateFrame, src: (const VMatrix *)&eyesToWorld, vAngles: &angEyeWorld);
    return &angEyeWorld;
  }
  else
  {
    v4 = this->m_hViewEntity.m_Value.m_Index;
    if ( v4 != -1
      && (v5 = (unsigned __int16)v4,
          v6 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)v4],
          v7 = HIWORD(v4),
          v6->m_SerialNumber == v7)
      && v6->m_pEntity != nullptr )
    {
      v8 = v5;
      v9 = g_pEntityList->m_EntPtrArray[v8].m_SerialNumber == v7;
      v10 = &g_pEntityList->m_EntPtrArray[v8];
      if ( v9 )
        return ((const QAngle *(__thiscall *)(IHandleEntity *))v10->m_pEntity->__vftable[42].SetRefEHandle)(a1: v10->m_pEntity);
      else
        return (*(const QAngle *(__thiscall **)(_DWORD))(MEMORY[0] + 508))(a1: 0);
    }
    else
    {
      return &this->pl.v_angle;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D89A0
// Name: public: virtual class Vector CBasePlayer::EyePosition(void)
// Source: json
//------------------------------------------------------------------------------
Vector *__thiscall CBasePlayer::EyePosition(CBasePlayer *this, Vector *result)
{
  unsigned int m_Index; // ecx
  int v5; // eax
  CEntInfo *v6; // edx
  unsigned int v7; // ecx
  int v8; // eax
  bool v9; // zf
  CEntInfo *v10; // eax
  IHandleEntity *m_pEntity; // eax

  if ( this->GetVehicle(this) != nullptr )
  {
    CBasePlayer::CacheVehicleView(this);
    *result = this->m_vecVehicleViewOrigin;
    return result;
  }
  else
  {
    m_Index = this->m_hViewEntity.m_Value.m_Index;
    if ( m_Index != -1
      && (v5 = (unsigned __int16)m_Index,
          v6 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index],
          v7 = HIWORD(m_Index),
          v6->m_SerialNumber == v7)
      && v6->m_pEntity != nullptr )
    {
      v8 = v5;
      v9 = g_pEntityList->m_EntPtrArray[v8].m_SerialNumber == v7;
      v10 = &g_pEntityList->m_EntPtrArray[v8];
      if ( v9 )
        m_pEntity = v10->m_pEntity;
      else
        m_pEntity = nullptr;
      ((void (__thiscall *)(IHandleEntity *, Vector *))m_pEntity->__vftable[42].dtr_IHandleEntity)(
        a1: m_pEntity,
        a2: result);
      return result;
    }
    else
    {
      CBaseEntity::EyePosition(this, result);
      return result;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D8A50
// Name: public: virtual class Vector const CBasePlayer::GetPlayerMins(void)const
// Source: json
//------------------------------------------------------------------------------
const Vector *__thiscall CBasePlayer::GetPlayerMins(CBasePlayer *this, const Vector *result)
{
  const CViewVectors *v2; // eax
  float z; // edx
  const CViewVectors *v5; // eax
  __int64 v6; // xmm0_8
  float v7; // eax
  const CViewVectors *v8; // eax
  float v9; // edx

  if ( (this->m_afPhysicsFlags.m_Value & 8) != 0 )
  {
    v2 = g_pGameRules->GetViewVectors(this: g_pGameRules);
    z = v2->m_vObsHullMin.z;
    *(_QWORD *)&result->x = *(_QWORD *)&v2->m_vObsHullMin.x;
    result->z = z;
    return result;
  }
  else
  {
    if ( (this->m_fFlags.m_Value & 2) != 0 )
    {
      v5 = g_pGameRules->GetViewVectors(this: g_pGameRules);
      v6 = *(_QWORD *)&v5->m_vDuckHullMin.x;
      v7 = v5->m_vDuckHullMin.z;
      *(_QWORD *)&result->x = v6;
      result->z = v7;
    }
    else
    {
      v8 = g_pGameRules->GetViewVectors(this: g_pGameRules);
      v9 = v8->m_vHullMin.z;
      *(_QWORD *)&result->x = *(_QWORD *)&v8->m_vHullMin.x;
      result->z = v9;
    }
    return result;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D8AE0
// Name: public: virtual class Vector const CBasePlayer::GetPlayerMaxs(void)const
// Source: json
//------------------------------------------------------------------------------
const Vector *__thiscall CBasePlayer::GetPlayerMaxs(CBasePlayer *this, const Vector *result)
{
  const CViewVectors *v2; // eax
  float z; // edx
  const CViewVectors *v5; // eax
  __int64 v6; // xmm0_8
  float v7; // eax
  const CViewVectors *v8; // eax
  float v9; // edx

  if ( (this->m_afPhysicsFlags.m_Value & 8) != 0 )
  {
    v2 = g_pGameRules->GetViewVectors(this: g_pGameRules);
    z = v2->m_vObsHullMax.z;
    *(_QWORD *)&result->x = *(_QWORD *)&v2->m_vObsHullMax.x;
    result->z = z;
    return result;
  }
  else
  {
    if ( (this->m_fFlags.m_Value & 2) != 0 )
    {
      v5 = g_pGameRules->GetViewVectors(this: g_pGameRules);
      v6 = *(_QWORD *)&v5->m_vDuckHullMax.x;
      v7 = v5->m_vDuckHullMax.z;
      *(_QWORD *)&result->x = v6;
      result->z = v7;
    }
    else
    {
      v8 = g_pGameRules->GetViewVectors(this: g_pGameRules);
      v9 = v8->m_vHullMax.z;
      *(_QWORD *)&result->x = *(_QWORD *)&v8->m_vHullMax.x;
      result->z = v9;
    }
    return result;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D8B70
// Name: public: virtual void CBasePlayer::UpdateCollisionBounds(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBasePlayer::UpdateCollisionBounds(CBasePlayer *this)
{
  int (*GetViewVectors)(void); // edx
  const CViewVectors *v3; // eax
  const CViewVectors *v4; // eax
  const Vector *v5; // [esp-4h] [ebp-8h]
  const Vector *v6; // [esp-4h] [ebp-8h]

  GetViewVectors = (int (*)(void))g_pGameRules->GetViewVectors;
  if ( (this->m_fFlags.m_Value & 2) != 0 )
  {
    v5 = (const Vector *)(GetViewVectors() + 48);
    v3 = g_pGameRules->GetViewVectors(this: g_pGameRules);
    CBaseEntity::SetCollisionBounds(this, mins: &v3->m_vDuckHullMin, maxs: v5);
  }
  else
  {
    v6 = (const Vector *)(GetViewVectors() + 24);
    v4 = g_pGameRules->GetViewVectors(this: g_pGameRules);
    CBaseEntity::SetCollisionBounds(this, mins: &v4->m_vHullMin, maxs: v6);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D8BD0
// Name: public: virtual void CBasePlayer::UpdateStepSound(struct surfacedata_t __near *,class Vector const __near &,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __userpurge CBasePlayer::UpdateStepSound(
        CBasePlayer *this@<ecx>,
        float a2@<ebp>,
        int a3@<edi>,
        int a4@<esi>,
        surfacedata_t *psurface,
        const Vector *vecOrigin,
        const Vector *vecVelocity)
{
  float m_flStepSoundTime; // xmm0_4
  float v9; // xmm0_4
  unsigned __int8 m_Value; // cl
  float v12; // xmm0_4
  __int128 v13; // xmm1
  void (__thiscall *GetStepSoundVelocities)(CBasePlayer *, float *, float *); // eax
  __int128 v15; // xmm0
  float y; // xmm1_4
  float z; // xmm2_4
  const Vector *(__thiscall *GetPlayerMaxs)(CBasePlayer *, const Vector *); // edx
  int v19; // eax
  const Vector *(__thiscall *GetPlayerMins)(CBasePlayer *, const Vector *); // edx
  int v21; // eax
  surfacedata_t *v22; // edi
  void (__thiscall *SetStepSoundTime)(CBasePlayer *, stepsoundtimes_t, bool); // edx
  float v24; // xmm0_4
  int v25; // ecx
  IPhysicsSurfaceProps_vtbl *v26; // edi
  int v27; // eax
  int v28; // eax
  void (__thiscall *v29)(CBasePlayer *, stepsoundtimes_t, bool); // edx
  IPhysicsSurfaceProps_vtbl *v30; // edi
  int v31; // eax
  double v32; // xmm0_8
  void (__thiscall *v33)(CBasePlayer *, stepsoundtimes_t, bool); // edx
  double v34; // xmm0_8
  int v35; // [esp+2Ch] [ebp-6Ch]
  int v37; // [esp+30h] [ebp-68h]
  int v38; // [esp+34h] [ebp-64h]
  __int128 v39; // [esp+3Ch] [ebp-5Ch] BYREF
  __int128 v40; // [esp+4Ch] [ebp-4Ch] BYREF
  Vector v41; // [esp+60h] [ebp-38h] BYREF
  Vector feet; // [esp+6Ch] [ebp-2Ch] BYREF
  Vector knee; // [esp+78h] [ebp-20h] BYREF
  _BYTE velrun_3[5]; // [esp+87h] [ebp-11h] OVERLAPPED
  float fvol; // [esp+8Ch] [ebp-Ch]
  void *v46; // [esp+90h] [ebp-8h] OVERLAPPED
  void *retaddr; // [esp+98h] [ebp+0h]

  fvol = a2;
  v46 = retaddr;
  m_flStepSoundTime = this->m_flStepSoundTime;
  if ( m_flStepSoundTime > 0.0 )
  {
    v9 = m_flStepSoundTime - (float)(gpGlobals->frametime * 1000.0);
    this->m_flStepSoundTime = v9;
    if ( v9 < 0.0 )
      this->m_flStepSoundTime = 0.0;
  }
  if ( this->m_flStepSoundTime <= 0.0 && (this->m_fFlags.m_Value & 0xC0) == 0 )
  {
    m_Value = this->m_MoveType.m_Value;
    if ( m_Value != 8 && m_Value != 10 && sv_footsteps.m_pParent->m_Value.m_fValue != 0.0 )
    {
      v12 = vecVelocity->x * vecVelocity->x;
      v13 = 0;
      *(float *)&v13 = fsqrt(
                         (float)((float)(vecVelocity->y * vecVelocity->y) + (float)(vecVelocity->z * vecVelocity->z))
                       + v12);
      v39 = v13;
      GetStepSoundVelocities = this->GetStepSoundVelocities;
      *(float *)&v13 = (float)(vecVelocity->y * vecVelocity->y) + v12;
      v15 = 0;
      *(float *)&v15 = fsqrt(*(float *)&v13);
      v40 = v15;
      velrun_3[4] = m_Value == 9;
      GetStepSoundVelocities(this, a2: &knee.y, a3: &knee.x);
      if ( *(float *)&v39 >= knee.y
        && (velrun_3[4] != 0 || (this->m_fFlags.m_Value & 1) != 0 && *(float *)&v15 > 0.000099999997) )
      {
        velrun_3[0] = knee.x > *(float *)&v39;
        y = vecOrigin->y;
        z = vecOrigin->z;
        GetPlayerMaxs = this->GetPlayerMaxs;
        feet.x = vecOrigin->x;
        feet.y = y;
        feet.z = z;
        v41 = feet;
        v19 = ((int (__thiscall *)(CBasePlayer *, char *, int, int))GetPlayerMaxs)(
                a1: this,
                a2: (char *)&v40 + 4,
                a3,
                a4);
        GetPlayerMins = this->GetPlayerMins;
        knee.z = *(float *)(v19 + 8);
        v21 = (int)GetPlayerMins(this, result: (const Vector *)((char *)&v39 + 4));
        feet.z = (float)(knee.z - *(float *)(v21 + 8)) * 0.2 + vecOrigin->z;
        if ( velrun_3[4] != 0 )
        {
          v22 = this->GetLadderSurface(this, a2: vecOrigin);
          SetStepSoundTime = this->SetStepSoundTime;
          knee.z = 0.5;
          SetStepSoundTime(this, a2: STEPSOUNDTIME_ON_LADDER, a3: *(_DWORD *)velrun_3);
          v24 = knee.z;
        }
        else if ( (enginetrace->GetPointContents(this: enginetrace, a2: &feet, a3: -1, a4: nullptr) & 0x4030) != 0 )
        {
          if ( iSkipStep == 0 )
          {
            iSkipStep = 1;
            return;
          }
          v25 = iSkipStep++;
          if ( v25 == 3 )
            iSkipStep = 0;
          v26 = physprops->__vftable;
          v27 = ((int (__thiscall *)(IPhysicsSurfaceProps *, const char *, int, int, int))physprops->GetSurfaceIndex)(
                  a1: physprops,
                  a2: "wade",
                  a3: v35,
                  a4: v37,
                  a5: v38);
          v28 = (int)v26->GetSurfaceData(this: physprops, a2: v27);
          v29 = this->SetStepSoundTime;
          v22 = (surfacedata_t *)v28;
          knee.z = 0.64999998;
          v29(this, a2: STEPSOUNDTIME_WATER_KNEE, a3: *(_DWORD *)velrun_3);
          v24 = knee.z;
        }
        else if ( this->m_nWaterLevel.m_Value == 1 )
        {
          v30 = physprops->__vftable;
          v31 = ((int (__thiscall *)(IPhysicsSurfaceProps *, const char *, int, int, int))physprops->GetSurfaceIndex)(
                  a1: physprops,
                  a2: "water",
                  a3: v35,
                  a4: v37,
                  a5: v38);
          v22 = v30->GetSurfaceData(this: physprops, a2: v31);
          if ( velrun_3[0] != 0 )
            v32 = 0.2;
          else
            v32 = 0.5;
          v33 = this->SetStepSoundTime;
          knee.z = v32;
          v33(this, a2: STEPSOUNDTIME_WATER_FOOT, a3: *(_DWORD *)velrun_3);
          v24 = knee.z;
        }
        else
        {
          v22 = psurface;
          if ( psurface == nullptr )
            return;
          ((void (__thiscall *)(CBasePlayer *, _DWORD, _DWORD, int, int, int))this->SetStepSoundTime)(
            a1: this,
            a2: 0,
            a3: *(_DWORD *)velrun_3,
            a4: v35,
            a5: v37,
            a6: v38);
          switch ( psurface->game.material )
          {
            case 'D':
              if ( velrun_3[0] != 0 )
                v34 = 0.25;
              else
                v34 = 0.55;
              break;
            case 'V':
              if ( velrun_3[0] != 0 )
                v34 = 0.4;
              else
                v34 = 0.7;
              break;
            default:
              if ( velrun_3[0] != 0 )
                v34 = 0.2;
              else
                v34 = 0.5;
              break;
          }
          v24 = v34;
        }
        if ( (this->m_fFlags.m_Value & 2) != 0 )
          v24 = v24 * 0.65;
        ((void (__thiscall *)(CBasePlayer *, Vector *, surfacedata_t *, _DWORD, _DWORD))this->PlayStepSound)(
          a1: this,
          a2: &v41,
          a3: v22,
          a4: LODWORD(v24),
          a5: 0);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D8FE0
// Name: public: virtual void CBasePlayer::GetStepSoundVelocities(float __near *,float __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBasePlayer::GetStepSoundVelocities(CBasePlayer *this, float *velwalk, float *velrun)
{
  if ( (this->m_fFlags.m_Value & 2) != 0 || this->m_MoveType.m_Value == 9 )
  {
    *velwalk = 60.0;
    *velrun = 80.0;
  }
  else
  {
    *velwalk = 90.0;
    *velrun = 220.0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D9040
// Name: public: virtual void CBasePlayer::SetStepSoundTime(enum stepsoundtimes_t,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBasePlayer::SetStepSoundTime(CBasePlayer *this, stepsoundtimes_t iStepSoundTime, bool bWalking)
{
  float v3; // xmm0_4

  switch ( iStepSoundTime )
  {
    case STEPSOUNDTIME_NORMAL:
    case STEPSOUNDTIME_WATER_FOOT:
      v3 = (float)(bWalking ? 400 : 300);
      goto LABEL_5;
    case STEPSOUNDTIME_ON_LADDER:
      v3 = 350.0;
      goto LABEL_5;
    case STEPSOUNDTIME_WATER_KNEE:
      v3 = 600.0;
LABEL_5:
      this->m_flStepSoundTime = v3;
      break;
    default:
      break;
  }
  if ( (this->m_fFlags.m_Value & 2) != 0 || this->m_MoveType.m_Value == 9 )
    this->m_flStepSoundTime = this->m_flStepSoundTime + 100.0;
}

//------------------------------------------------------------------------------
// Address: 0x100D90D0
// Name: public: virtual void CBasePlayer::SelectLastItem(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBasePlayer::SelectLastItem(CBasePlayer *this)
{
  unsigned int m_Index; // eax
  CBaseCombatWeapon *ActiveWeapon; // eax
  unsigned int v4; // eax
  IHandleEntity *m_pEntity; // ecx
  IHandleEntity *v6; // edx
  const char *v7; // edi
  CBasePlayer_vtbl *v8; // esi
  int v9; // eax

  m_Index = this->m_hLastWeapon.m_Value.m_Index;
  if ( m_Index != -1
    && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index)
    && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity != nullptr )
  {
    if ( CBaseCombatCharacter::GetActiveWeapon(this) == nullptr
      || (ActiveWeapon = CBaseCombatCharacter::GetActiveWeapon(this), ActiveWeapon->CanHolster(this: ActiveWeapon)) )
    {
      v4 = this->m_hLastWeapon.m_Value.m_Index;
      if ( v4 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v4].m_SerialNumber != HIWORD(v4) )
        m_pEntity = nullptr;
      else
        m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)v4].m_pEntity;
      if ( v4 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v4].m_SerialNumber != HIWORD(v4) )
        v6 = nullptr;
      else
        v6 = g_pEntityList->m_EntPtrArray[(unsigned __int16)v4].m_pEntity;
      v7 = (const char *)v6[23].__vftable;
      if ( v7 == nullptr )
        v7 = locale;
      v8 = this->__vftable;
      v9 = ((int (__thiscall *)(IHandleEntity *))m_pEntity->__vftable[77].dtr_IHandleEntity)(a1: m_pEntity);
      v8->SelectItem(this, a2: v7, a3: v9);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D91B0
// Name: public: virtual bool CUsePushFilter::ShouldHitEntity(class IHandleEntity __near *,int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CUsePushFilter::ShouldHitEntity(CUsePushFilter *this, IHandleEntity *pHandleEntity, int contentsMask)
{
  CBaseEntity *v3; // eax

  return !staticpropmgr->IsStaticProp_2(this: staticpropmgr, a2: pHandleEntity)
      && (v3 = (CBaseEntity *)pHandleEntity->__vftable[1].GetRefEHandle(this: pHandleEntity)) != nullptr
      && v3->m_pPhysicsObject != nullptr
      && g_pGameRules->CanEntityBeUsePushed(this: g_pGameRules, a2: v3);
}

//------------------------------------------------------------------------------
// Address: 0x100D9200
// Name: public: void CBasePlayer::SmoothViewOnStairs(class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBasePlayer::SmoothViewOnStairs(CBasePlayer *this, Vector *eyeOrigin)
{
  CBaseEntity *GroundEntity; // edi
  float z; // xmm2_4
  float m_flOldPlayerZ; // xmm0_4
  float v6; // xmm1_4
  int v7; // eax
  float frametime; // xmm0_4
  float v9; // xmm0_4
  float flCurrentPlayerZ; // [esp+8h] [ebp-4h]

  GroundEntity = CBaseEntity::GetGroundEntity(this);
  flCurrentPlayerZ = this->m_vecOrigin.m_Value.z;
  z = this->GetViewOffset(this)->z;
  if ( GroundEntity == nullptr || GroundEntity->m_MoveType.m_Value != 0 )
  {
    v6 = flCurrentPlayerZ;
LABEL_23:
    this->m_flOldPlayerZ = v6;
    this->m_flOldPlayerViewOffsetZ = z;
    return;
  }
  m_flOldPlayerZ = this->m_flOldPlayerZ;
  v6 = flCurrentPlayerZ;
  if ( flCurrentPlayerZ == m_flOldPlayerZ
    || smoothstairs.m_pParent == nullptr
    || smoothstairs.m_pParent->m_Value.m_nValue == 0
    || this->m_flOldPlayerViewOffsetZ != z )
  {
    goto LABEL_23;
  }
  if ( flCurrentPlayerZ <= m_flOldPlayerZ )
    v7 = -1;
  else
    v7 = 1;
  frametime = gpGlobals->frametime;
  if ( frametime < 0.0 )
    frametime = 0.0;
  v9 = (float)((float)(frametime * 150.0) * (float)v7) + this->m_flOldPlayerZ;
  this->m_flOldPlayerZ = v9;
  if ( v7 <= 0 )
  {
    if ( flCurrentPlayerZ > v9 )
      this->m_flOldPlayerZ = flCurrentPlayerZ;
    if ( (float)(flCurrentPlayerZ - this->m_flOldPlayerZ) < -18.0 )
      this->m_flOldPlayerZ = flCurrentPlayerZ + 18.0;
  }
  else
  {
    if ( v9 > flCurrentPlayerZ )
      this->m_flOldPlayerZ = flCurrentPlayerZ;
    if ( (float)(flCurrentPlayerZ - this->m_flOldPlayerZ) > 18.0 )
      this->m_flOldPlayerZ = flCurrentPlayerZ - 18.0;
  }
  eyeOrigin->z = (float)(this->m_flOldPlayerZ - flCurrentPlayerZ) + eyeOrigin->z;
}

//------------------------------------------------------------------------------
// Address: 0x100D9380
// Name: public: void CBasePlayer::CalcViewRoll(class QAngle __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBasePlayer::CalcViewRoll(CBasePlayer *this, QAngle *eyeAngles)
{
  float v3; // [esp+Ch] [ebp-8h]
  float m_fValue; // [esp+10h] [ebp-4h]
  int savedregs; // [esp+14h] [ebp+0h] BYREF

  if ( this->m_MoveType.m_Value != 8 )
  {
    m_fValue = sv_rollspeed.m_pParent->m_Value.m_fValue;
    v3 = sv_rollangle.m_pParent->m_Value.m_fValue;
    if ( (this->m_iEFlags & 0x1000) != 0 )
      CBaseEntity::CalcAbsoluteVelocity(this, a2: (int)&savedregs);
    if ( (this->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
    eyeAngles->z = ((double (__thiscall *)(CBasePlayer *, QAngle *, Vector *, _DWORD, _DWORD))this->CalcRoll)(
                     a1: this,
                     a2: &this->m_angAbsRotation,
                     a3: &this->m_vecAbsVelocity,
                     a4: LODWORD(v3),
                     a5: LODWORD(m_fValue))
                 + eyeAngles->z;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D9420
// Name: public: void CBasePlayer::AvoidPhysicsProps(class CUserCmd __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBasePlayer::AvoidPhysicsProps(CBasePlayer *this, CUserCmd *pCmd)
{
  if ( this->m_MoveType.m_Value != 0
    && this->m_MoveType.m_Value != 8
    && this->m_MoveType.m_Value != 10
    && this->GetObserverMode(this) == 0
    && this->IsAlive(this) )
  {
    AvoidPushawayProps(pPlayer: this, pCmd);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D9470
// Name: public: void CBasePlayer::UpdateUnderwaterState(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBasePlayer::UpdateUnderwaterState(CBasePlayer *this)
{
  if ( this->m_nWaterLevel.m_Value == 3 )
  {
    if ( !this->m_bPlayerUnderwater )
      this->SetPlayerUnderwater(this, a2: true);
  }
  else
  {
    if ( this->m_bPlayerUnderwater )
      this->SetPlayerUnderwater(this, a2: false);
    if ( this->m_nWaterLevel.m_Value != 0 )
    {
      if ( (this->m_fFlags.m_Value & 0x400) == 0 )
      {
        if ( CBaseEntity::GetWaterType(this) == 32 )
          CBaseEntity::EmitSound(this, soundname: "Player.Wade", soundtime: 0.0, duration: nullptr);
        CBaseEntity::AddFlag(this, flags: 1024);
      }
    }
    else if ( (this->m_fFlags.m_Value & 0x400) != 0 )
    {
      if ( this->m_iHealth.m_Value > 0 && this->IsAlive(this) )
        CBaseEntity::EmitSound(this, soundname: "Player.Wade", soundtime: 0.0, duration: nullptr);
      CBaseEntity::RemoveFlag(this, flagsToRemove: 1024);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D9540
// Name: public: bool CBasePlayer::ClearUseEntity(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBasePlayer::ClearUseEntity(CBasePlayer *this)
{
  unsigned int m_Index; // ecx
  CBaseEntity *v3; // eax

  m_Index = this->m_hUseEntity.m_Value.m_Index;
  if ( m_Index != -1
    && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index)
    && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity != nullptr
    && this->m_bDropEnabled )
  {
    v3 = this->GetUseEntity(this);
    ((void (__thiscall *)(CBaseEntity *, CBasePlayer *, CBasePlayer *, _DWORD, _DWORD))v3->Use)(
      a1: v3,
      a2: this,
      a3: this,
      a4: 0,
      a5: 0);
  }
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x100D95B0
// Name: public: void CBasePlayer::UpdateVPhysicsPosition(class Vector const __near &,class Vector const __near &,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBasePlayer::UpdateVPhysicsPosition(
        CBasePlayer *this,
        const Vector *position,
        const Vector *velocity,
        float secondsToArrival)
{
  CBaseEntity *GroundEntity; // eax
  IPhysicsObject *m_pPhysicsObject; // esi
  IPhysicsObject *v7; // ebx
  double v8; // st7
  int onground; // [esp+14h] [ebp-8h]
  float v10; // [esp+18h] [ebp-4h]

  if ( this->m_pPhysicsController != nullptr )
  {
    LOBYTE(onground) = this->m_fFlags.m_Value & 1;
    GroundEntity = CBaseEntity::GetGroundEntity(this);
    if ( GroundEntity == nullptr
      || GroundEntity->m_MoveType.m_Value != 6
      || (m_pPhysicsObject = GroundEntity->m_pPhysicsObject) == nullptr
      || !m_pPhysicsObject->IsMoveable(this: m_pPhysicsObject)
      || (v7 = this->m_pPhysicsObject,
          v10 = m_pPhysicsObject->GetMass(this: m_pPhysicsObject),
          v8 = ((double (__thiscall *)(IPhysicsObject *))v7->GetMass)(a1: v7),
          v10 <= v8 + v8) )
    {
      m_pPhysicsObject = nullptr;
    }
    ((void (__stdcall *)(const Vector *, const Vector *, _DWORD, int, IPhysicsObject *))this->m_pPhysicsController->Update)(
      a1: position,
      a2: velocity,
      a3: LODWORD(secondsToArrival),
      a4: onground,
      a5: m_pPhysicsObject);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D9660
// Name: public: virtual void CBasePlayer::UpdatePhysicsShadowToCurrentPosition(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CBasePlayer::UpdatePhysicsShadowToCurrentPosition(CBasePlayer *this@<ecx>, int a2@<ebp>)
{
  if ( (this->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this, a2);
  CBasePlayer::UpdateVPhysicsPosition(
    this,
    position: &this->m_vecAbsOrigin,
    velocity: &vec3_origin,
    secondsToArrival: gpGlobals->frametime);
}

//------------------------------------------------------------------------------
// Address: 0x100D96A0
// Name: public: void CBasePlayer::UpdatePhysicsShadowToPosition(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBasePlayer::UpdatePhysicsShadowToPosition(CBasePlayer *this, const Vector *vecAbsOrigin)
{
  CBasePlayer::UpdateVPhysicsPosition(
    this,
    position: vecAbsOrigin,
    velocity: &vec3_origin,
    secondsToArrival: gpGlobals->frametime);
}

//------------------------------------------------------------------------------
// Address: 0x100D9760
// Name: public: class CBaseEntity const __near * CNetworkHandleBase<class CBaseEntity,class CBasePlayer::NetworkVar_m_hZoomOwner>::Set(class CBaseEntity const __near *)
// Source: json
//------------------------------------------------------------------------------
const CBaseEntity *__thiscall CNetworkHandleBase<CBaseEntity,CBasePlayer::NetworkVar_m_hZoomOwner>::Set(
        CNetworkHandleBase<CBaseEntity,CBasePlayer::NetworkVar_m_hZoomOwner> *this,
        const CBaseEntity *val)
{
  unsigned int m_Index; // eax
  const CBaseEntity *m_pEntity; // ecx
  CNetworkHandleBase<CBaseEntity,CBasePlayer::NetworkVar_m_hZoomOwner> *v5; // eax
  CBaseEdict *v6; // ecx

  m_Index = this->m_Value.m_Index;
  if ( this->m_Value.m_Index == -1
    || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
  {
    m_pEntity = nullptr;
  }
  else
  {
    m_pEntity = (const CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
  }
  if ( m_pEntity != val )
  {
    v5 = this - 794;
    if ( *((_BYTE *)this - 3092) != 0 )
    {
      LOBYTE(v5[22].m_Value.m_Index) |= 1u;
    }
    else
    {
      v6 = (CBaseEdict *)v5[6].m_Value.m_Index;
      if ( v6 != nullptr )
        CBaseEdict::StateChanged(this: v6, offset: 0xC68u);
    }
    if ( val != nullptr )
    {
      this->m_Value.m_Index = val->GetRefEHandle(this: val)->m_Index;
      return val;
    }
    this->m_Value.m_Index = -1;
  }
  return val;
}

//------------------------------------------------------------------------------
// Address: 0x100D9860
// Name: public: void CBasePlayer::RemoveFromPlayerSimulationList(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBasePlayer::RemoveFromPlayerSimulationList(CBasePlayer *this, CBaseEntity *other)
{
  int v3; // eax

  if ( other != nullptr )
  {
    other = (CBaseEntity *)other->GetRefEHandle(this: other)->m_Index;
    v3 = CUtlVector<CHandle<CSceneEntity>,CUtlMemory<CHandle<CSceneEntity>,int>>::Find(
           this: &this->m_SimulatedByThisPlayer,
           src: (CHandle<CBaseEntity> *)&other);
    if ( v3 != -1 )
    {
      if ( this->m_SimulatedByThisPlayer.m_Size - v3 - 1 > 0 )
        _V_memmove(
          dest: &this->m_SimulatedByThisPlayer.m_Memory.m_pMemory[v3],
          src: &this->m_SimulatedByThisPlayer.m_Memory.m_pMemory[v3 + 1],
          count: 4 * (this->m_SimulatedByThisPlayer.m_Size - v3 - 1));
      --this->m_SimulatedByThisPlayer.m_Size;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D98C0
// Name: public: void CBasePlayer::SimulatePlayerSimulatedEntities(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBasePlayer::SimulatePlayerSimulatedEntities(CBasePlayer *this)
{
  int i; // edi
  unsigned int m_Index; // eax
  IHandleEntity *m_pEntity; // ecx
  int j; // edi
  unsigned int v6; // eax
  IHandleEntity *v7; // ecx

  for ( i = this->m_SimulatedByThisPlayer.m_Size - 1; i >= 0; --i )
  {
    m_Index = this->m_SimulatedByThisPlayer.m_Memory.m_pMemory[i].m_Index;
    if ( m_Index != -1
      && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index)
      && (m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity) != nullptr
      && HIBYTE(m_pEntity[138].__vftable) != 0 )
    {
      ((void (__thiscall *)(IHandleEntity *))m_pEntity->__vftable[35].SetRefEHandle)(a1: m_pEntity);
    }
    else
    {
      if ( this->m_SimulatedByThisPlayer.m_Size - i - 1 > 0 )
        _V_memmove(
          dest: &this->m_SimulatedByThisPlayer.m_Memory.m_pMemory[i],
          src: &this->m_SimulatedByThisPlayer.m_Memory.m_pMemory[i + 1],
          count: 4 * (this->m_SimulatedByThisPlayer.m_Size - i - 1));
      --this->m_SimulatedByThisPlayer.m_Size;
    }
  }
  for ( j = this->m_SimulatedByThisPlayer.m_Size - 1; j >= 0; --j )
  {
    v6 = this->m_SimulatedByThisPlayer.m_Memory.m_pMemory[j].m_Index;
    if ( v6 != -1
      && g_pEntityList->m_EntPtrArray[(unsigned __int16)v6].m_SerialNumber == HIWORD(v6)
      && (v7 = g_pEntityList->m_EntPtrArray[(unsigned __int16)v6].m_pEntity) != nullptr
      && HIBYTE(v7[138].__vftable) != 0 )
    {
      if ( (HIBYTE(v7[49].__vftable) & 1) != 0 )
        CBaseEntity::PhysicsCheckForEntityUntouch(this: (CBaseEntity *)v7);
    }
    else
    {
      if ( this->m_SimulatedByThisPlayer.m_Size - j - 1 > 0 )
        _V_memmove(
          dest: &this->m_SimulatedByThisPlayer.m_Memory.m_pMemory[j],
          src: &this->m_SimulatedByThisPlayer.m_Memory.m_pMemory[j + 1],
          count: 4 * (this->m_SimulatedByThisPlayer.m_Size - j - 1));
      --this->m_SimulatedByThisPlayer.m_Size;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D99E0
// Name: public: void CBasePlayer::ClearPlayerSimulationList(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBasePlayer::ClearPlayerSimulationList(CBasePlayer *this)
{
  int i; // esi
  unsigned int m_Index; // eax
  CBaseEntity *m_pEntity; // ecx

  for ( i = this->m_SimulatedByThisPlayer.m_Size - 1; i >= 0; --i )
  {
    m_Index = this->m_SimulatedByThisPlayer.m_Memory.m_pMemory[i].m_Index;
    if ( m_Index != -1 && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index) )
    {
      m_pEntity = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
      if ( m_pEntity != nullptr )
        CBaseEntity::UnsetPlayerSimulated(this: m_pEntity);
    }
  }
  this->m_SimulatedByThisPlayer.m_Size = 0;
}

//------------------------------------------------------------------------------
// Address: 0x100D9A40
// Name: public: virtual class CBaseEntity __near * CBasePlayer::FindUseEntity(void)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
// bad sp value at call has been detected, the output may be wrong!
CBaseEntity *__usercall CBasePlayer::FindUseEntity@<eax>(
        CBasePlayer *this@<ecx>,
        float a2@<ebp>,
        int a3@<edi>,
        int a4@<esi>)
{
  IServerVehicle *(__thiscall *GetVehicle)(CBaseCombatCharacter *); // edx
  CBasePlayer_vtbl *v6; // edx
  const QAngle *(__thiscall *EyeAngles)(CBaseEntity *); // eax
  Vector *(__thiscall *EyePosition)(CBaseEntity *, Vector *); // edx
  float y; // esi
  float v10; // xmm0_4
  float v11; // edi
  int (__thiscall *v12)(_DWORD, _DWORD, _DWORD); // eax
  char v13; // al
  unsigned int v14; // ecx
  int v15; // eax
  CEntInfo *v16; // edx
  unsigned int v17; // ecx
  int v18; // eax
  bool v19; // zf
  CEntInfo *v20; // eax
  IHandleEntity *m_pEntity; // esi
  CCollisionProperty *v22; // esi
  Vector *v23; // eax
  float x; // ecx
  float v25; // xmm2_4
  float v26; // xmm2_4
  const Vector *(__thiscall *OBBMins)(struct CCollisionProperty *); // edx
  int v28; // eax
  const Vector *(__thiscall *OBBMaxs)(struct CCollisionProperty *); // edx
  float z; // xmm0_4
  float v31; // xmm0_4
  float v32; // xmm1_4
  float v33; // xmm1_4
  __int128 v34; // xmm0
  int v35; // eax
  int y_low; // esi
  const char *DebugName; // eax
  float v38; // esi
  int v39; // edi
  CBaseEntity *GroundEntity; // eax
  float v41; // esi
  const char *v42; // esi
  CBaseEntity *CurrentEntity; // esi
  float v44; // edi
  const char *pszValue; // eax
  int v46; // esi
  float v47; // ecx
  int v48; // eax
  int v49; // eax
  int v50; // edx
  int (__thiscall *v51)(_DWORD); // eax
  const Vector *v52; // eax
  const char *v53; // eax
  _DWORD v56[3]; // [esp+54h] [ebp-9C4h] BYREF
  CEntitySphereQuery sphere; // [esp+60h] [ebp-9B8h] BYREF
  CGameTrace trAllies; // [esp+868h] [ebp-1B0h] BYREF
  Vector v59; // [esp+8C4h] [ebp-154h] BYREF
  _BYTE tr[92]; // [esp+8D0h] [ebp-148h] OVERLAPPED BYREF
  _DWORD v61[3]; // [esp+930h] [ebp-E8h]
  float tangents[8]; // [esp+93Ch] [ebp-DCh] BYREF
  Vector up; // [esp+95Ch] [ebp-BCh] BYREF
  float v64; // [esp+96Ch] [ebp-ACh]
  float v65; // [esp+970h] [ebp-A8h]
  float v66; // [esp+974h] [ebp-A4h]
  unsigned int v67; // [esp+97Ch] [ebp-9Ch]
  unsigned int v68; // [esp+980h] [ebp-98h]
  unsigned int v69; // [esp+984h] [ebp-94h]
  int v70; // [esp+98Ch] [ebp-8Ch]
  int v71; // [esp+990h] [ebp-88h]
  int v72; // [esp+994h] [ebp-84h]
  int v73; // [esp+99Ch] [ebp-7Ch]
  char v74; // [esp+9A0h] [ebp-78h]
  bool v75; // [esp+9A1h] [ebp-77h]
  float v76; // [esp+9B0h] [ebp-68h]
  int v77; // [esp+9B4h] [ebp-64h]
  float v78; // [esp+9B8h] [ebp-60h]
  float v79; // [esp+9BCh] [ebp-5Ch] BYREF
  CBaseEntity *pFoundByTrace; // [esp+9C0h] [ebp-58h]
  float centerZ; // [esp+9C4h] [ebp-54h]
  Vector point; // [esp+9C8h] [ebp-50h] BYREF
  Vector v83; // [esp+9D4h] [ebp-44h] BYREF
  Vector dir; // [esp+9E0h] [ebp-38h] BYREF
  float v85; // [esp+9ECh] [ebp-2Ch]
  float nearestDist; // [esp+9F0h] [ebp-28h]
  Vector forward; // [esp+9F4h] [ebp-24h] BYREF
  CBaseEntity *pNearest; // [esp+A00h] [ebp-18h]
  Vector searchCenter; // [esp+A04h] [ebp-14h] BYREF
  float dist; // [esp+A10h] [ebp-8h]
  float retaddr; // [esp+A18h] [ebp+0h]

  searchCenter.z = a2;
  dist = retaddr;
  GetVehicle = this->GetVehicle;
  LODWORD(searchCenter.y) = this;
  if ( ((int (__cdecl *)(int, int))GetVehicle)(a1: a3, a2: a4) != 0 )
  {
    CBasePlayer::CacheVehicleView(this);
    LODWORD(searchCenter.y) = &tangents[5];
    searchCenter.x = 0.0;
    *(float *)&pNearest = COERCE_FLOAT((Vector *)&dir.z);
    LODWORD(forward.z) = &this->m_vecVehicleViewAngles;
  }
  else
  {
    v6 = this->__vftable;
    LODWORD(searchCenter.y) = &tangents[5];
    EyeAngles = v6->EyeAngles;
    searchCenter.x = 0.0;
    *(float *)&pNearest = COERCE_FLOAT((Vector *)&dir.z);
    LODWORD(forward.z) = EyeAngles(this);
  }
  AngleVectors(
    angles: (const QAngle *)LODWORD(forward.z),
    forward: (Vector *)pNearest,
    right: (Vector *)LODWORD(searchCenter.x),
    up: (Vector *)LODWORD(searchCenter.y));
  EyePosition = this->EyePosition;
  LODWORD(searchCenter.y) = &forward.y;
  ((void (__thiscall *)(CBasePlayer *))EyePosition)(a1: this);
  dir.y = 3.4028235e38;
  v61[0] = 0;
  v61[1] = 1065353216;
  v61[2] = 1058262330;
  tangents[0] = 0.36397022;
  tangents[1] = 0.26794919;
  tangents[2] = 0.17632698;
  tangents[3] = -0.17632698;
  forward.x = 0.0;
  tangents[4] = -0.26794919;
  searchCenter.x = 0.0;
  do
  {
    if ( LODWORD(searchCenter.x) != 0 )
    {
      v10 = *(float *)&v61[LODWORD(searchCenter.x)];
      v83.x = dir.z - (float)(tangents[5] * v10);
      v83.y = v85 - (float)(tangents[6] * v10);
      v83.z = nearestDist - (float)(tangents[7] * v10);
      VectorNormalize(vec: &v83);
      v65 = (float)((float)(v83.y * 72.0) + forward.z) - forward.z;
      v64 = (float)((float)(v83.x * 72.0) + forward.y) - forward.y;
      v66 = (float)((float)(v83.z * 72.0) + *(float *)&pNearest) - *(float *)&pNearest;
      v73 = 0;
      v75 = (float)((float)((float)(v65 * v65) + (float)(v64 * v64)) + (float)(v66 * v66)) != 0.0;
      y = searchCenter.y;
      v70 = 1098907648;
      v71 = 1098907648;
      v72 = 1098907648;
      v74 = 0;
      up.x = forward.y;
      up.y = forward.z;
      LODWORD(up.z) = pNearest;
      v67 = 0x80000000;
      v68 = 0x80000000;
      v69 = 0x80000000;
      CTraceFilterSimple::CTraceFilterSimple(
        this: (CTraceFilterSimple *)&trAllies.m_pEnt,
        passedict: (const IHandleEntity *)LODWORD(searchCenter.y),
        collisionGroup: 0,
        pExtraShouldHitFunc: nullptr);
      enginetrace->TraceRay(
        this: enginetrace,
        a2: (const Ray_t *)&up,
        a3: 33702027u,
        a4: (ITraceFilter *)&trAllies.m_pEnt,
        a5: (CGameTrace *)&v59);
      if ( r_visualizetraces.m_pParent != nullptr && r_visualizetraces.m_pParent->m_Value.m_nValue != 0 )
        DebugDrawLine(
          vecAbsStart: &v59,
          vecAbsEnd: (const Vector *)tr,
          r: 255,
          g: 255,
          b: 0,
          test: true,
          duration: -1.0);
    }
    else
    {
      y = searchCenter.y;
      point.y = forward.z + (float)(v85 * 1024.0);
      point.x = forward.y + (float)(dir.z * 1024.0);
      point.z = (float)(nearestDist * 1024.0) + 0.0;
      UTIL_TraceLine(
        a1: (const IHandleEntity *)&searchCenter.z,
        a2: SLODWORD(searchCenter.y),
        vecAbsStart: (Vector *)&forward.y,
        vecAbsEnd: &point,
        mask: 0x202408Bu,
        ignore: (const IHandleEntity *)LODWORD(searchCenter.y),
        collisionGroup: 0,
        ptr: (CGameTrace *)&v59);
    }
    v11 = *(float *)&tr[64];
    v12 = *(int (__thiscall **)(_DWORD, _DWORD, _DWORD))(*(_DWORD *)LODWORD(y) + 1752);
    v77 = *(_DWORD *)&tr[64];
    v13 = v12(a1: LODWORD(y), a2: *(_DWORD *)&tr[64], a3: 0);
    if ( v11 == 0.0 )
    {
LABEL_19:
      if ( v13 == 0 )
        goto LABEL_41;
    }
    else
    {
      while ( v13 == 0 )
      {
        v14 = *(_DWORD *)(LODWORD(v11) + 216);
        if ( v14 == -1 )
          goto LABEL_41;
        v15 = (unsigned __int16)v14;
        v16 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)v14];
        v17 = HIWORD(v14);
        if ( v16->m_SerialNumber != v17 || v16->m_pEntity == nullptr )
          goto LABEL_41;
        v18 = v15;
        v19 = g_pEntityList->m_EntPtrArray[v18].m_SerialNumber == v17;
        v20 = &g_pEntityList->m_EntPtrArray[v18];
        if ( v19 )
          m_pEntity = v20->m_pEntity;
        else
          m_pEntity = nullptr;
        v11 = *(float *)&m_pEntity;
        v13 = (*(int (__thiscall **)(_DWORD, IHandleEntity *, _DWORD))(*(_DWORD *)LODWORD(searchCenter.y) + 1752))(
                a1: LODWORD(searchCenter.y),
                a2: m_pEntity,
                a3: 0);
        if ( m_pEntity == nullptr )
          goto LABEL_19;
      }
    }
    v79 = *(float *)tr - v59.x;
    *(float *)&pFoundByTrace = *(float *)&tr[4] - v59.y;
    v22 = (CCollisionProperty *)(LODWORD(searchCenter.y) + 228);
    LODWORD(dir.x) = AllocTempVector();
    *(float *)&v23 = COERCE_FLOAT(AllocTempVector());
    x = dir.x;
    v23->x = (float)((float)(v22->m_vecMaxs.m_Value.x - v22->m_vecMins.m_Value.x) * 0.5) + v22->m_vecMins.m_Value.x;
    v23->y = (float)((float)(v22->m_vecMaxs.m_Value.y - v22->m_vecMins.m_Value.y) * 0.5) + v22->m_vecMins.m_Value.y;
    v25 = v22->m_vecMaxs.m_Value.z - v22->m_vecMins.m_Value.z;
    searchCenter.x = x;
    v26 = (float)(v25 * 0.5) + v22->m_vecMins.m_Value.z;
    pNearest = (CBaseEntity *)v23;
    v23->z = v26;
    CCollisionProperty::CollisionToWorldSpace(
      this: v22,
      in: (const Vector *)pNearest,
      pResult: (Vector *)LODWORD(searchCenter.x));
    OBBMins = v22->OBBMins;
    v78 = *(float *)(LODWORD(dir.x) + 8);
    v28 = (int)OBBMins(this: v22);
    OBBMaxs = v22->OBBMaxs;
    v76 = *(float *)(v28 + 8) + v78;
    z = OBBMaxs(this: v22)->z;
    v31 = z + v78;
    v32 = v76;
    if ( v76 > v31 )
    {
      v32 = v31;
      v31 = v76;
    }
    if ( v32 <= *(float *)&tr[8] )
    {
      if ( *(float *)&tr[8] <= v31 )
        v33 = 0.0;
      else
        v33 = *(float *)&tr[8] - v31;
    }
    else
    {
      v33 = v32 - *(float *)&tr[8];
    }
    dir.x = v79 * v79;
    v34 = 0;
    *(float *)&v34 = fsqrt(
                       (float)((float)(v79 * v79) + (float)(*(float *)&pFoundByTrace * *(float *)&pFoundByTrace))
                     + (float)(v33 * v33));
    *(_OWORD *)&tr[76] = v34;
    if ( *(float *)&v34 < 80.0 )
    {
      if ( sv_debug_player_use.m_pParent != nullptr && sv_debug_player_use.m_pParent->m_Value.m_nValue != 0 )
      {
        NDebugOverlay::Line(
          origin: (Vector *)&forward.y,
          target: (const Vector *)tr,
          r: 0,
          g: 255,
          b: 0,
          noDepthTest: true,
          duration: 30.0);
        NDebugOverlay::Cross3D(
          position: (const Vector *)tr,
          size: 16.0,
          r: 0,
          g: 255,
          b: 0,
          noDepthTest: true,
          flDuration: 30.0);
      }
      if ( (*(int (__thiscall **)(float))(*(_DWORD *)LODWORD(v11) + 296))(a1: COERCE_FLOAT(LODWORD(v11))) != 0 )
      {
        v35 = (*(int (__thiscall **)(float))(*(_DWORD *)LODWORD(v11) + 296))(a1: COERCE_FLOAT(LODWORD(v11)));
        y_low = LODWORD(searchCenter.y);
        if ( (*(unsigned __int8 (__thiscall **)(int, _DWORD))(*(_DWORD *)v35 + 1772))(
               a1: v35,
               a2: LODWORD(searchCenter.y)) != 0 )
          v11 = COERCE_FLOAT(
                  CBasePlayer::DoubleCheckUseNPC(
                    this: (CBasePlayer *)y_low,
                    a2: y_low,
                    pNPC: (CBaseEntity *)LODWORD(v11),
                    vecSrc: (Vector *)&forward.y,
                    vecDir: (Vector *)&dir.z));
      }
      if ( sv_debug_player_use.m_pParent != nullptr && sv_debug_player_use.m_pParent->m_Value.m_nValue != 0 )
      {
        if ( v11 == 0.0 )
          DebugName = "no usable entity found";
        else
          DebugName = CBaseEntity::GetDebugName(this: (CBaseEntity *)LODWORD(v11));
        _Msg(a1: "Trace using: %s\n", DebugName);
      }
      forward.x = v11;
      if ( LODWORD(searchCenter.x) == 0 )
        return (CBaseEntity *)LODWORD(v11);
    }
LABEL_41:
    ++LODWORD(searchCenter.x);
  }
  while ( SLODWORD(searchCenter.x) < 8 );
  v38 = searchCenter.y;
  if ( CBaseEntity::GetGroundEntity(this: (CBaseEntity *)LODWORD(searchCenter.y)) != nullptr
    && (v39 = *(_DWORD *)LODWORD(v38),
        LODWORD(searchCenter.x) = 16,
        GroundEntity = CBaseEntity::GetGroundEntity(this: (CBaseEntity *)LODWORD(v38)),
        (*(unsigned __int8 (__thiscall **)(float, CBaseEntity *, _DWORD))(v39 + 1752))(
          a1: COERCE_FLOAT(LODWORD(v38)),
          a2: GroundEntity,
          a3: LODWORD(searchCenter.x)) != 0) )
  {
    v41 = COERCE_FLOAT(CBaseEntity::GetGroundEntity(this: (CBaseEntity *)LODWORD(v38)));
    forward.x = v41;
  }
  else
  {
    v41 = forward.x;
  }
  if ( v41 != 0.0 )
  {
    CCollisionProperty::CalcNearestPoint(
      this: (CCollisionProperty *)(LODWORD(v41) + 228),
      vecWorldPt: (Vector *)&forward.y,
      pVecNearestWorldPt: (Vector *)&v79);
    dir.y = CalcDistanceToLine(
              P: (const Vector *)&v79,
              vLineA: (Vector *)&forward.y,
              vLineB: (Vector *)&dir.z,
              outT: nullptr);
    if ( sv_debug_player_use.m_pParent != nullptr && sv_debug_player_use.m_pParent->m_Value.m_nValue != 0 )
    {
      v42 = *(const char **)(LODWORD(v41) + 92);
      if ( v42 == nullptr )
        v42 = locale;
      _Msg(a1: "Trace found %s, dist %.2f\n", v42, dir.y);
    }
  }
  CEntitySphereQuery::CEntitySphereQuery(
    this: (CEntitySphereQuery *)v56,
    center: (Vector *)&forward.y,
    radius: 80.0,
    flagMask: 0);
  CurrentEntity = CEntitySphereQuery::GetCurrentEntity(this: (CEntitySphereQuery *)v56);
  if ( CurrentEntity != nullptr )
  {
    v44 = searchCenter.y;
    do
    {
      if ( (*(unsigned __int8 (__thiscall **)(float, CBaseEntity *, int))(*(_DWORD *)LODWORD(v44) + 1752))(
             a1: COERCE_FLOAT(LODWORD(v44)),
             a2: CurrentEntity,
             a3: 32) != 0 )
      {
        CCollisionProperty::CalcNearestPoint(
          this: &CurrentEntity->m_Collision,
          vecWorldPt: (Vector *)&forward.y,
          pVecNearestWorldPt: &point);
        v83.x = point.x - forward.y;
        v83.y = point.y - forward.z;
        v83.z = point.z - *(float *)&pNearest;
        VectorNormalize(vec: &v83);
        if ( (float)((float)((float)(v83.y * v85) + (float)(v83.x * dir.z)) + (float)(v83.z * nearestDist)) >= 0.8 )
        {
          searchCenter.x = CalcDistanceToLine(
                             P: &point,
                             vLineA: (Vector *)&forward.y,
                             vLineB: (Vector *)&dir.z,
                             outT: nullptr);
          if ( sv_debug_player_use.m_pParent != nullptr && sv_debug_player_use.m_pParent->m_Value.m_nValue != 0 )
          {
            pszValue = CurrentEntity->m_iClassname.pszValue;
            if ( pszValue == nullptr )
              pszValue = locale;
            _Msg(a1: "Radius found %s, dist %.2f\n", pszValue, searchCenter.x);
          }
          if ( dir.y > searchCenter.x )
          {
            UTIL_TraceLine(
              a1: (const IHandleEntity *)&searchCenter.z,
              a2: (int)CurrentEntity,
              vecAbsStart: (Vector *)&forward.y,
              vecAbsEnd: &point,
              mask: 0x202408Bu,
              ignore: (const IHandleEntity *)LODWORD(v44),
              collisionGroup: 0,
              ptr: (CGameTrace *)&sphere.m_pList[509]);
            if ( trAllies.plane.normal.z == 1.0 || *(CBaseEntity **)&trAllies.surface.surfaceProps == CurrentEntity )
            {
              LODWORD(forward.x) = CurrentEntity;
              dir.y = searchCenter.x;
            }
          }
        }
      }
      ++v56[0];
      CurrentEntity = CEntitySphereQuery::GetCurrentEntity(this: (CEntitySphereQuery *)v56);
    }
    while ( CurrentEntity != nullptr );
  }
  v11 = forward.x;
  if ( LODWORD(forward.x) != 0 )
  {
    v46 = LODWORD(searchCenter.y);
    goto LABEL_77;
  }
  v65 = (float)((float)(v85 * 80.0) + forward.z) - forward.z;
  v64 = (float)((float)(dir.z * 80.0) + forward.y) - forward.y;
  v66 = (float)((float)(nearestDist * 80.0) + *(float *)&pNearest) - *(float *)&pNearest;
  v75 = (float)((float)((float)(v65 * v65) + (float)(v64 * v64)) + (float)(v66 * v66)) != 0.0;
  v46 = LODWORD(searchCenter.y);
  v73 = 0;
  v72 = 0;
  v71 = 0;
  v70 = 0;
  v74 = 1;
  v69 = 0;
  v68 = 0;
  v67 = 0;
  up.x = forward.y;
  up.y = forward.z;
  LODWORD(up.z) = pNearest;
  CTraceFilterSimple::CTraceFilterSimple(
    this: (CTraceFilterSimple *)&tr[76],
    passedict: (const IHandleEntity *)LODWORD(searchCenter.y),
    collisionGroup: 0,
    pExtraShouldHitFunc: nullptr);
  enginetrace->TraceRay(
    this: enginetrace,
    a2: (const Ray_t *)&up,
    a3: 33570945u,
    a4: (ITraceFilter *)&tr[76],
    a5: (CGameTrace *)&sphere.m_pList[509]);
  if ( r_visualizetraces.m_pParent != nullptr && r_visualizetraces.m_pParent->m_Value.m_nValue != 0 )
    DebugDrawLine(
      vecAbsStart: (const Vector *)&sphere.m_pList[509],
      vecAbsEnd: &trAllies.startpos,
      r: 255,
      g: 0,
      b: 0,
      test: true,
      duration: -1.0);
  if ( *(_DWORD *)&trAllies.surface.surfaceProps != 0
    && (*(unsigned __int8 (__thiscall **)(int, _DWORD, _DWORD))(*(_DWORD *)v46 + 1752))(
         a1: v46,
         a2: *(_DWORD *)&trAllies.surface.surfaceProps,
         a3: 0) != 0
    && (*(int (__thiscall **)(_DWORD))(**(_DWORD **)&trAllies.surface.surfaceProps + 296))(a1: *(_DWORD *)&trAllies.surface.surfaceProps) != 0 )
  {
    v48 = (*(int (__thiscall **)(_DWORD))(**(_DWORD **)&trAllies.surface.surfaceProps + 296))(a1: *(_DWORD *)&trAllies.surface.surfaceProps);
    if ( (*(unsigned __int8 (__thiscall **)(int, int))(*(_DWORD *)v48 + 1772))(a1: v48, a2: v46) != 0 )
    {
      v11 = *(float *)&trAllies.surface.surfaceProps;
      if ( *(_DWORD *)&trAllies.surface.surfaceProps != 0 )
      {
LABEL_77:
        if ( (*(int (__thiscall **)(float))(*(_DWORD *)LODWORD(v11) + 296))(a1: COERCE_FLOAT(LODWORD(v11))) != 0 )
        {
          v49 = (*(int (__thiscall **)(float))(*(_DWORD *)LODWORD(v11) + 296))(a1: COERCE_FLOAT(LODWORD(v11)));
          if ( (*(unsigned __int8 (__thiscall **)(int, int))(*(_DWORD *)v49 + 1772))(a1: v49, a2: v46) != 0 )
            v11 = COERCE_FLOAT(
                    CBasePlayer::DoubleCheckUseNPC(
                      this: (CBasePlayer *)v46,
                      a2: v46,
                      pNPC: (CBaseEntity *)LODWORD(v11),
                      vecSrc: (Vector *)&forward.y,
                      vecDir: (Vector *)&dir.z));
        }
      }
    }
  }
  if ( sv_debug_player_use.m_pParent != nullptr )
  {
    if ( sv_debug_player_use.m_pParent->m_Value.m_nValue != 0 )
    {
      searchCenter.x = v47;
      if ( v11 == 0.0 )
      {
        NDebugOverlay::Line(
          origin: (Vector *)&forward.y,
          target: (const Vector *)tr,
          r: 255,
          g: 0,
          b: 0,
          noDepthTest: true,
          duration: 30.0);
        searchCenter.x = 30.0;
        pNearest = (CBaseEntity *)1;
        forward.z = 0.0;
        forward.y = 0.0;
        LODWORD(forward.x) = 255;
        goto LABEL_86;
      }
      if ( LODWORD(v11) == v77 )
      {
        NDebugOverlay::Line(
          origin: (Vector *)&forward.y,
          target: (const Vector *)tr,
          r: 0,
          g: 255,
          b: 0,
          noDepthTest: true,
          duration: 30.0);
        searchCenter.x = 30.0;
        pNearest = (CBaseEntity *)1;
        forward.z = 0.0;
        LODWORD(forward.y) = 255;
        forward.x = 0.0;
LABEL_86:
        NDebugOverlay::Cross3D(
          position: (const Vector *)tr,
          size: 16.0,
          r: SLODWORD(forward.x),
          g: SLODWORD(forward.y),
          b: SLODWORD(forward.z),
          noDepthTest: (bool)pNearest,
          flDuration: searchCenter.x);
      }
      else
      {
        v50 = *(_DWORD *)LODWORD(v11);
        v79 = 8.0;
        *(float *)&pFoundByTrace = 8.0;
        centerZ = 8.0;
        point.x = -8.0;
        point.y = -8.0;
        point.z = -8.0;
        searchCenter.x = 30.0;
        pNearest = (CBaseEntity *)1;
        forward.z = 0.0;
        LODWORD(forward.y) = 255;
        forward.x = 0.0;
        nearestDist = COERCE_FLOAT(&v79);
        v51 = *(int (__thiscall **)(_DWORD))(v50 + 588);
        v85 = COERCE_FLOAT(&point);
        v52 = (const Vector *)v51(a1: LODWORD(v11));
        NDebugOverlay::Box(
          origin: v52,
          mins: (const Vector *)LODWORD(v85),
          maxs: (const Vector *)LODWORD(nearestDist),
          r: SLODWORD(forward.x),
          g: SLODWORD(forward.y),
          b: SLODWORD(forward.z),
          a: (int)pNearest,
          flDuration: searchCenter.x);
      }
    }
    if ( sv_debug_player_use.m_pParent != nullptr && sv_debug_player_use.m_pParent->m_Value.m_nValue != 0 )
    {
      if ( v11 == 0.0 )
        v53 = "no usable entity found";
      else
        v53 = CBaseEntity::GetDebugName(this: (CBaseEntity *)LODWORD(v11));
      _Msg(a1: "Radial using: %s\n", v53);
    }
  }
  return (CBaseEntity *)LODWORD(v11);
}

//------------------------------------------------------------------------------
// Address: 0x100DA610
// Name: public: void CBasePlayer::ViewPunch(class QAngle const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBasePlayer::ViewPunch(CBasePlayer *this, const QAngle *angleOffset)
{
  float y; // xmm5_4
  float z; // xmm6_4
  CNetworkVectorBase<QAngle,CPlayerLocalData::NetworkVar_m_vecPunchAngleVel> *p_m_vecPunchAngleVel; // esi
  float v6; // [esp+4h] [ebp-Ch]
  float v7; // [esp+8h] [ebp-8h]
  float v8; // [esp+Ch] [ebp-4h]

  if ( (sv_suppress_viewpunch.m_pParent == nullptr || sv_suppress_viewpunch.m_pParent->m_Value.m_nValue == 0)
    && !this->IsInAVehicle(this) )
  {
    y = this->m_Local.m_vecPunchAngleVel.m_Value.y;
    z = this->m_Local.m_vecPunchAngleVel.m_Value.z;
    p_m_vecPunchAngleVel = &this->m_Local.m_vecPunchAngleVel;
    v6 = p_m_vecPunchAngleVel->m_Value.x + (float)(angleOffset->x * 20.0);
    v7 = y + (float)(angleOffset->y * 20.0);
    v8 = z + (float)(angleOffset->z * 20.0);
    if ( v6 != p_m_vecPunchAngleVel->m_Value.x
      || (float)(y + (float)(angleOffset->y * 20.0)) != y
      || (float)(z + (float)(angleOffset->z * 20.0)) != z )
    {
      (*(void (__thiscall **)(int, CNetworkVectorBase<QAngle,CPlayerLocalData::NetworkVar_m_vecPunchAngleVel> *))LODWORD(p_m_vecPunchAngleVel[-11].m_Value.z))(
        a1: (int)&p_m_vecPunchAngleVel[-11].m_Value.z,
        a2: p_m_vecPunchAngleVel);
      p_m_vecPunchAngleVel->m_Value.x = v6;
      p_m_vecPunchAngleVel->m_Value.y = v7;
      p_m_vecPunchAngleVel->m_Value.z = v8;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100DA6F0
// Name: public: void CBasePlayer::ViewPunchReset(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBasePlayer::ViewPunchReset(CBasePlayer *this, float tolerance)
{
  CNetworkVectorBase<QAngle,CPlayerLocalData::NetworkVar_m_vecPunchAngle> *p_m_vecPunchAngle; // esi

  if ( tolerance == 0.0
    || (float)((float)((float)((float)(this->m_Local.m_vecPunchAngle.m_Value.x * this->m_Local.m_vecPunchAngle.m_Value.x)
                             + (float)(this->m_Local.m_vecPunchAngle.m_Value.y * this->m_Local.m_vecPunchAngle.m_Value.y))
                     + (float)(this->m_Local.m_vecPunchAngle.m_Value.z * this->m_Local.m_vecPunchAngle.m_Value.z))
             + (float)((float)((float)(this->m_Local.m_vecPunchAngleVel.m_Value.x
                                     * this->m_Local.m_vecPunchAngleVel.m_Value.x)
                             + (float)(this->m_Local.m_vecPunchAngleVel.m_Value.y
                                     * this->m_Local.m_vecPunchAngleVel.m_Value.y))
                     + (float)(this->m_Local.m_vecPunchAngleVel.m_Value.z * this->m_Local.m_vecPunchAngleVel.m_Value.z))) <= (float)(tolerance * tolerance) )
  {
    p_m_vecPunchAngle = &this->m_Local.m_vecPunchAngle;
    if ( vec3_angle.x != this->m_Local.m_vecPunchAngle.m_Value.x
      || vec3_angle.y != this->m_Local.m_vecPunchAngle.m_Value.y
      || vec3_angle.z != this->m_Local.m_vecPunchAngle.m_Value.z )
    {
      this->m_Local.NetworkStateChanged(this: &this->m_Local, a2: &this->m_Local.m_vecPunchAngle);
      p_m_vecPunchAngle->m_Value.x = vec3_angle.x;
      this->m_Local.m_vecPunchAngle.m_Value.y = vec3_angle.y;
      this->m_Local.m_vecPunchAngle.m_Value.z = vec3_angle.z;
    }
    if ( vec3_angle.x != this->m_Local.m_vecPunchAngleVel.m_Value.x
      || vec3_angle.y != this->m_Local.m_vecPunchAngleVel.m_Value.y
      || vec3_angle.z != this->m_Local.m_vecPunchAngleVel.m_Value.z )
    {
      this->m_Local.NetworkStateChanged(this: &this->m_Local, a2: &this->m_Local.m_vecPunchAngleVel);
      this->m_Local.m_vecPunchAngleVel.m_Value = vec3_angle;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100DA860
// Name: protected: virtual void CBasePlayer::CalcPlayerView(class Vector __near &,class QAngle __near &,float __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBasePlayer::CalcPlayerView(CBasePlayer *this, Vector *eyeOrigin, QAngle *eyeAngles, float *fov)
{
  bool v5; // zf
  Vector *(__thiscall *EyePosition)(CBaseEntity *, Vector *); // edx
  float *v7; // eax
  float v8; // xmm1_4
  float v9; // xmm2_4
  Vector *v10; // ebx
  const QAngle *v11; // eax
  QAngle *v12; // edi
  float v13; // xmm1_4
  float v14; // xmm2_4
  Vector v15; // [esp+Ch] [ebp-Ch] BYREF

  v5 = !IAI_BehaviorBridge::BehaviorBridge_IsCurTaskContinuousMove((vgui::ToggleButton *)this);
  EyePosition = this->EyePosition;
  if ( v5 )
  {
    v10 = eyeOrigin;
    *eyeOrigin = *EyePosition(this, result: &v15);
    v12 = eyeAngles;
    *eyeAngles = *this->EyeAngles(this);
  }
  else
  {
    v7 = (float *)EyePosition(this, result: &v15);
    v8 = v7[1] + vec3_origin.y;
    v9 = v7[2] + vec3_origin.z;
    v10 = eyeOrigin;
    eyeOrigin->x = *v7 + vec3_origin.x;
    eyeOrigin->y = v8;
    eyeOrigin->z = v9;
    v11 = this->EyeAngles(this);
    v12 = eyeAngles;
    v13 = v11->y + vec3_angle.y;
    v14 = v11->z + vec3_angle.z;
    eyeAngles->x = v11->x + vec3_angle.x;
    eyeAngles->y = v13;
    eyeAngles->z = v14;
  }
  CBasePlayer::SmoothViewOnStairs(this, eyeOrigin: v10);
  this->CalcViewBob(this, a2: v10);
  CBasePlayer::CalcViewRoll(this, eyeAngles: v12);
  v12->x = v12->x + this->m_Local.m_vecPunchAngle.m_Value.x;
  v12->y = this->m_Local.m_vecPunchAngle.m_Value.y + v12->y;
  v12->z = this->m_Local.m_vecPunchAngle.m_Value.z + v12->z;
  *fov = (float)CBasePlayer::GetFOV(this);
}

//------------------------------------------------------------------------------
// Address: 0x100DA9B0
// Name: public: virtual void CBasePlayer::ItemPostFrame(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBasePlayer::ItemPostFrame(CBasePlayer *this)
{
  const QAngle *v2; // ebx
  int i; // edi
  CBaseViewModel *ViewModel; // eax
  IServerVehicle *v5; // edi
  bool v6; // bl
  int v7; // eax
  unsigned int m_Index; // ecx
  CBaseCombatWeapon *v9; // ecx
  CBaseCombatWeapon *ActiveWeapon; // ecx
  CBaseCombatWeapon *v11; // edi
  IServerVehicle *v12; // edx
  CBaseEdict *v13; // ecx
  int v14; // eax
  CAmmoDef *AmmoDef; // eax
  int v16; // eax
  IServerVehicle *v17; // edx
  CBaseEdict *v18; // ecx
  int v19; // eax
  CAmmoDef *v20; // eax
  int v21; // eax
  int v22; // [esp-Ch] [ebp-28h]
  int v23; // [esp-Ch] [ebp-28h]
  int v24; // [esp-4h] [ebp-20h]
  int v25; // [esp-4h] [ebp-20h]
  _BYTE v26[12]; // [esp+Ch] [ebp-10h] BYREF
  IServerVehicle *pVehicle; // [esp+18h] [ebp-4h]

  v2 = this->EyeAngles(this);
  pVehicle = (IServerVehicle *)this->EyePosition(this, result: v26);
  for ( i = 0; i < 2; ++i )
  {
    ViewModel = CBasePlayer::GetViewModel(this, index: i);
    if ( ViewModel != nullptr )
      ViewModel->CalcViewModelView(this: ViewModel, a2: this, a3: (const Vector *)pVehicle, a4: v2);
  }
  if ( this->GetVehicle(this) == nullptr
    || ((pVehicle = this->GetVehicle(this), (v5 = this->GetVehicle(this)) != nullptr)
      ? (v7 = v5->GetPassengerRole(this: v5, a2: this), v6 = v5->IsPassengerUsingStandardWeapons(this: v5, a2: v7))
      : (v6 = true),
        (pVehicle->ItemPostFrame(this: pVehicle, a2: this), v6) && this->GetVehicle(this) != nullptr) )
  {
    m_Index = this->m_hUseEntity.m_Value.m_Index;
    if ( m_Index != -1
      && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index)
      && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity != nullptr )
    {
      this->ImpulseCommands(this);
    }
    else
    {
      if ( this->m_flNextAttack.m_Value <= gpGlobals->curtime )
      {
        if ( CBaseCombatCharacter::GetActiveWeapon(this) != nullptr
          && (!this->IsInAVehicle(this) || CBasePlayer::UsingStandardWeaponsInVehicle(this)) )
        {
          ActiveWeapon = CBaseCombatCharacter::GetActiveWeapon(this);
          ActiveWeapon->ItemPostFrame(this: ActiveWeapon);
        }
      }
      else if ( CBaseCombatCharacter::GetActiveWeapon(this) != nullptr )
      {
        v9 = CBaseCombatCharacter::GetActiveWeapon(this);
        v9->ItemBusyFrame(this: v9);
      }
      this->ImpulseCommands(this);
      if ( sv_infinite_ammo.m_pParent != nullptr
        && sv_infinite_ammo.m_pParent->m_Value.m_nValue != 0
        && CBaseCombatCharacter::GetActiveWeapon(this) != nullptr )
      {
        v11 = CBaseCombatCharacter::GetActiveWeapon(this);
        v12 = (IServerVehicle *)v11->GetMaxClip1(this: v11);
        pVehicle = v12;
        if ( (IServerVehicle *)v11->m_iClip1.m_Value != v12 )
        {
          if ( v11->m_Network.m_TimerEvent.m_bRegistered )
          {
            *((_BYTE *)&v11->m_Network + 76) |= 1u;
          }
          else
          {
            v13 = &v11->m_Network.m_pPev->CBaseEdict;
            if ( v13 != nullptr )
            {
              CBaseEdict::StateChanged(this: v13, offset: 0x4B0u);
              v12 = pVehicle;
            }
          }
          v11->m_iClip1.m_Value = (int)v12;
        }
        v14 = v11->GetPrimaryAmmoType(this: v11);
        if ( v14 >= 0 )
        {
          v24 = v14;
          v22 = v14;
          AmmoDef = GetAmmoDef();
          v16 = CAmmoDef::MaxCarry(this: AmmoDef, nAmmoIndex: v22, owner: this);
          CBaseCombatCharacter::SetAmmoCount(this, iCount: v16, iAmmoIndex: v24);
        }
        v17 = (IServerVehicle *)v11->GetMaxClip2(this: v11);
        pVehicle = v17;
        if ( (IServerVehicle *)v11->m_iClip2.m_Value != v17 )
        {
          if ( v11->m_Network.m_TimerEvent.m_bRegistered )
          {
            *((_BYTE *)&v11->m_Network + 76) |= 1u;
          }
          else
          {
            v18 = &v11->m_Network.m_pPev->CBaseEdict;
            if ( v18 != nullptr )
            {
              CBaseEdict::StateChanged(this: v18, offset: 0x4B4u);
              v17 = pVehicle;
            }
          }
          v11->m_iClip2.m_Value = (int)v17;
        }
        v19 = v11->GetSecondaryAmmoType(this: v11);
        if ( v19 >= 0 )
        {
          v25 = v19;
          v23 = v19;
          v20 = GetAmmoDef();
          v21 = CAmmoDef::MaxCarry(this: v20, nAmmoIndex: v23, owner: this);
          CBaseCombatCharacter::SetAmmoCount(this, iCount: v21, iAmmoIndex: v25);
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100DAC40
// Name: public: virtual void CBasePlayer::Weapon_SetLast(class CBaseCombatWeapon __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBasePlayer::Weapon_SetLast(CBasePlayer *this, CBaseCombatWeapon *pWeapon)
{
  CNetworkVarBase<CHandle<CBaseCombatWeapon>,CBasePlayer::NetworkVar_m_hLastWeapon> *p_m_hLastWeapon; // edi
  unsigned int m_Index; // esi
  IHandleEntity *m_pEntity; // edx
  unsigned int v5; // eax
  IHandleEntity *v6; // ecx
  CNetworkVarBase<CHandle<CBaseCombatWeapon>,CBasePlayer::NetworkVar_m_hLastWeapon> *v7; // eax
  CBaseEdict *v8; // ecx

  p_m_hLastWeapon = &this->m_hLastWeapon;
  if ( pWeapon == nullptr )
  {
    m_Index = -1;
LABEL_6:
    m_pEntity = nullptr;
    goto LABEL_7;
  }
  m_Index = pWeapon->GetRefEHandle(this: pWeapon)->m_Index;
  if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    goto LABEL_6;
  m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
LABEL_7:
  v5 = p_m_hLastWeapon->m_Value.m_Index;
  if ( p_m_hLastWeapon->m_Value.m_Index == -1
    || g_pEntityList->m_EntPtrArray[(unsigned __int16)v5].m_SerialNumber != HIWORD(v5) )
  {
    v6 = nullptr;
  }
  else
  {
    v6 = g_pEntityList->m_EntPtrArray[(unsigned __int16)v5].m_pEntity;
  }
  if ( v6 != m_pEntity )
  {
    v7 = p_m_hLastWeapon - 974;
    if ( LOBYTE(p_m_hLastWeapon[-953].m_Value.m_Index) != 0 )
    {
      LOBYTE(v7[22].m_Value.m_Index) |= 1u;
      p_m_hLastWeapon->m_Value.m_Index = m_Index;
    }
    else
    {
      v8 = (CBaseEdict *)v7[6].m_Value.m_Index;
      if ( v8 != nullptr )
        CBaseEdict::StateChanged(this: v8, offset: 0xF38u);
      p_m_hLastWeapon->m_Value.m_Index = m_Index;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100DACF0
// Name: public: virtual void CBasePlayer::PlayerUse(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBasePlayer::PlayerUse(CBasePlayer *this)
{
  int m_nButtons; // eax
  int m_afButtonPressed; // ecx
  CBaseEntity *m_pEnt; // ebx
  const Vector *v5; // edi
  float *v6; // eax
  double v7; // st7
  float v8; // xmm1_4
  float m_fValue; // xmm0_4
  int v10; // ebx
  const Vector *(__thiscall *WorldSpaceCenter)(CBaseEntity *); // eax
  int v12; // edi
  int v13; // eax
  unsigned int v14; // ebx
  edict_t *m_pPev; // ecx
  CBaseEntity *GroundEntity; // ebx
  unsigned int v17; // edi
  edict_t *v18; // ecx
  int v19; // eax
  CBaseEntity *v20; // eax
  bool v21; // zf
  CBaseEntity *v22; // edi
  CCSPlayer *v23; // eax
  CCSPlayer *v24; // ebx
  CWeaponCSBase *ActiveCSWeapon; // eax
  CBaseCombatWeapon *Weapon; // eax
  CWeaponCSBase *v27; // eax
  CWeaponCSBase *v28; // edi
  CWeaponCSBase *v29; // edi
  CWeaponCSBase *v30; // eax
  CCSPlayer_vtbl *v31; // edx
  char v32; // al
  unsigned int m_Value; // eax
  CBaseEntity *v34; // edx
  edict_t *v35; // ecx
  char v36; // al
  CBaseEntity_vtbl *v37; // ebx
  variant_t soundtime; // [esp+0h] [ebp-C8h] BYREF
  int v39; // [esp+14h] [ebp-B4h]
  CGameTrace tr; // [esp+24h] [ebp-A4h] BYREF
  Vector forward; // [esp+78h] [ebp-50h] BYREF
  float v42[3]; // [esp+84h] [ebp-44h] BYREF
  variant_t __that; // [esp+90h] [ebp-38h] BYREF
  Vector searchCenter; // [esp+A4h] [ebp-24h] BYREF
  Vector vPushAway; // [esp+B0h] [ebp-18h] BYREF
  CWeaponCSBase *pC4Weapon; // [esp+BCh] [ebp-Ch]
  int i; // [esp+C0h] [ebp-8h]
  CBaseEntity *pTrain; // [esp+C4h] [ebp-4h] BYREF
  int savedregs; // [esp+C8h] [ebp+0h] BYREF

  m_nButtons = this->m_nButtons;
  m_afButtonPressed = this->m_afButtonPressed;
  if ( ((LOBYTE(this->m_afButtonReleased) | (unsigned __int8)(m_afButtonPressed | m_nButtons)) & 0x20) == 0 )
    return;
  if ( (this->m_afPhysicsFlags.m_Value & 8) != 0 )
  {
    if ( (m_afButtonPressed & 0x20) != 0 )
    {
      this->ObserverUse(this, a2: true);
    }
    else if ( (this->m_afButtonReleased & 0x20) != 0 )
    {
      this->ObserverUse(this, a2: false);
    }
    return;
  }
  if ( (m_nButtons & 0x20) != 0
    && sv_turbophysics.m_pParent != nullptr
    && sv_turbophysics.m_pParent->m_Value.m_nValue != 0 )
  {
    CBasePlayer::EyeVectors(this, pForward: &forward, pRight: nullptr, pUp: (Vector *)(&__that.rgbaVal + 2));
    this->EyePosition(this, result: &searchCenter);
    vPushAway.y = searchCenter.y + (float)(forward.y * 96.0);
    pTrain = (CBaseEntity *)&CUsePushFilter::`vftable';
    vPushAway.x = searchCenter.x + (float)(forward.x * 96.0);
    vPushAway.z = searchCenter.z + (float)(forward.z * 96.0);
    UTIL_TraceLine(
      a1: (int)&savedregs,
      a2: (int)this,
      vecAbsStart: &searchCenter,
      vecAbsEnd: &vPushAway,
      mask: 0x200400Bu,
      pFilter: (ITraceFilter *)&pTrain,
      ptr: &tr);
    m_pEnt = tr.m_pEnt;
    if ( tr.m_pEnt != nullptr )
    {
      i = (int)tr.m_pEnt->m_pPhysicsObject;
      if ( i != 0 )
      {
        v5 = this->WorldSpaceCenter(this);
        v6 = (float *)m_pEnt->WorldSpaceCenter(this: m_pEnt);
        vPushAway.x = *v6 - v5->x;
        vPushAway.y = v6[1] - v5->y;
        vPushAway.z = 0.0;
        v7 = VectorNormalize(vec: &vPushAway);
        *(float *)&pC4Weapon = v7;
        if ( v7 > 1.0 )
          v8 = *(float *)&pC4Weapon;
        else
          v8 = 1.0;
        m_fValue = sv_pushaway_force.m_pParent->m_Value.m_fValue / v8;
        if ( sv_pushaway_max_force.m_pParent->m_Value.m_fValue <= m_fValue )
          m_fValue = sv_pushaway_max_force.m_pParent->m_Value.m_fValue;
        v10 = i;
        WorldSpaceCenter = this->WorldSpaceCenter;
        v12 = *(_DWORD *)i;
        v42[0] = vPushAway.x * m_fValue;
        v42[1] = vPushAway.y * m_fValue;
        v42[2] = m_fValue * vPushAway.z;
        v13 = (int)WorldSpaceCenter(this);
        (*(void (__thiscall **)(int, float *, int))(v12 + 244))(a1: v10, a2: v42, a3: v13);
      }
    }
  }
  if ( (this->m_afButtonPressed & 0x20) != 0 )
  {
    if ( CBasePlayer::ClearUseEntity(this) )
      return;
    if ( (this->m_afPhysicsFlags.m_Value & 1) != 0 )
    {
      v14 = this->m_afPhysicsFlags.m_Value & 0xFFFFFFFE;
      if ( this->m_afPhysicsFlags.m_Value != v14 )
      {
        if ( this->m_Network.m_TimerEvent.m_bRegistered )
        {
          *((_BYTE *)&this->m_Network + 76) |= 1u;
        }
        else
        {
          m_pPev = this->m_Network.m_pPev;
          if ( m_pPev != nullptr )
            CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0xBFCu);
        }
        this->m_afPhysicsFlags.m_Value = v14;
      }
      this->m_iTrain = 192;
      return;
    }
    GroundEntity = CBaseEntity::GetGroundEntity(this);
    pTrain = GroundEntity;
    if ( GroundEntity != nullptr
      && (this->m_nButtons & 2) == 0
      && (this->m_fFlags.m_Value & 1) != 0
      && (GroundEntity->ObjectCaps(this: GroundEntity) & 8) != 0
      && GroundEntity->OnControls(this: GroundEntity, a2: this) )
    {
      v17 = this->m_afPhysicsFlags.m_Value | 1;
      if ( this->m_afPhysicsFlags.m_Value != v17 )
      {
        if ( this->m_Network.m_TimerEvent.m_bRegistered )
        {
          *((_BYTE *)&this->m_Network + 76) |= 1u;
        }
        else
        {
          v18 = this->m_Network.m_pPev;
          if ( v18 != nullptr )
            CBaseEdict::StateChanged(this: &v18->CBaseEdict, offset: 0xBFCu);
        }
        GroundEntity = pTrain;
        this->m_afPhysicsFlags.m_Value = v17;
      }
      v19 = TrainSpeed(
              iSpeed: (int)GroundEntity->m_flSpeed,
              iMax: (int)*(float *)&GroundEntity[1].m_Network.m_TimerEvent.m_pEventMgr);
      v39 = 0;
      soundtime.fieldType = FIELD_VOID;
      soundtime.eVal.m_Index = (unsigned int)"Player.UseTrain";
      this->m_iTrain = v19 | 0xC0;
      CBaseEntity::EmitSound(
        this,
        soundname: (const char *)soundtime.eVal.m_Index,
        soundtime: *(float *)&soundtime.fieldType,
        duration: (float *)v39);
      return;
    }
  }
  v20 = this->FindUseEntity(this);
  v21 = (this->m_afButtonPressed & 0x20) == 0;
  v22 = v20;
  pTrain = v20;
  if ( !v21 )
  {
    v23 = ToCSPlayer(pEntity: this);
    v24 = v23;
    if ( v23 != nullptr )
    {
      if ( !CCSPlayer::IsInBuyZone(this: v23)
        || CCSGameRules::IsPlayingGunGame(this: (CCSGameRules *)g_pGameRules)
        || v24->m_bIsControllingBot.m_Value )
      {
        if ( CCSPlayer::HasC4(this: v24)
          && v24->m_bInBombZone.m_Value
          && CCSPlayer::GetActiveCSWeapon(this: v24) != nullptr )
        {
          ActiveCSWeapon = CCSPlayer::GetActiveCSWeapon(this: v24);
          if ( ActiveCSWeapon->GetCSWeaponID(this: ActiveCSWeapon) != WEAPON_C4 )
          {
            *(float *)&pC4Weapon = 0.0;
            for ( i = 0; i < 64; ++i )
            {
              Weapon = CBaseCombatCharacter::GetWeapon(this: v24, i);
              v27 = (CWeaponCSBase *)__RTDynamicCast(
                                       inptr: Weapon,
                                       VfDelta: 0,
                                       SrcType: &CBaseCombatWeapon `RTTI Type Descriptor',
                                       TargetType: &CWeaponCSBase `RTTI Type Descriptor',
                                       isReference: 0);
              v28 = v27;
              if ( v27 != nullptr
                && v27->GetCSWeaponID(this: v27) == WEAPON_C4
                && v24->Weapon_CanSwitchTo(this: v24, a2: v28) )
              {
                pC4Weapon = v28;
              }
            }
            v29 = pC4Weapon;
            if ( *(float *)&pC4Weapon != 0.0 )
            {
              v30 = CCSPlayer::GetActiveCSWeapon(this: v24);
              v31 = v24->CBaseMultiplayerPlayer::CAI_ExpresserHost<CBasePlayer>::CBasePlayer::CBaseCombatCharacter::CBaseFlex::CBaseAnimatingOverlay::CBaseAnimating::CBaseEntity::IServerEntity::IServerUnknown::IHandleEntity::__vftable;
              v39 = 0;
              v24->m_lastWeaponBeforeC4AutoSwitch = v30;
              v31->Weapon_Switch(this: v24, a2: v29, a3: v39);
            }
            v22 = pTrain;
          }
        }
      }
      else if ( v22 == nullptr
             || __RTDynamicCast(
                  inptr: v22,
                  VfDelta: 0,
                  SrcType: &CBaseEntity `RTTI Type Descriptor',
                  TargetType: &CWeaponCSBase `RTTI Type Descriptor',
                  isReference: 0) != nullptr )
      {
        engine->ClientCommand(this: engine, a2: this->m_Network.m_pPev, a3: "buymenu\n");
        return;
      }
    }
  }
  if ( v22 != nullptr )
  {
    v32 = v22->ObjectCaps(this: v22);
    v21 = (this->m_nButtons & 0x20) == 0;
    __that.iVal = 0;
    __that.eVal.m_Index = -1;
    __that.fieldType = FIELD_VOID;
    if ( !v21 && (v32 & 2) != 0 )
      goto LABEL_67;
    if ( (this->m_afButtonPressed & 0x20) == 0 || (v32 & 5) == 0 )
    {
      if ( (this->m_afButtonReleased & 0x20) == 0 || (v22->ObjectCaps(this: v22) & 4) == 0 )
        return;
      v37 = v22->__vftable;
      v39 = 0;
LABEL_79:
      variant_t::variant_t(this: &soundtime, &__that);
      ((void (__thiscall *)(CBaseEntity *, const char *, CBasePlayer *, CBasePlayer *, int, _DWORD, _DWORD, unsigned int, _fieldtypes, int))v37->AcceptInput)(
        a1: v22,
        a2: "Use",
        a3: this,
        a4: this,
        a5: soundtime.iVal,
        a6: LODWORD(soundtime.vecVal[1]),
        a7: LODWORD(soundtime.vecVal[2]),
        a8: soundtime.eVal.m_Index,
        a9: soundtime.fieldType,
        a10: v39);
      return;
    }
    if ( (v32 & 2) != 0 )
    {
LABEL_67:
      m_Value = this->m_afPhysicsFlags.m_Value;
      v34 = (CBaseEntity *)(m_Value | 4);
      pTrain = (CBaseEntity *)(m_Value | 4);
      if ( m_Value != (m_Value | 4) )
      {
        if ( this->m_Network.m_TimerEvent.m_bRegistered )
        {
          *((_BYTE *)&this->m_Network + 76) |= 1u;
        }
        else
        {
          v35 = this->m_Network.m_pPev;
          if ( v35 != nullptr )
          {
            CBaseEdict::StateChanged(this: &v35->CBaseEdict, offset: 0xBFCu);
            v34 = pTrain;
          }
        }
        this->m_afPhysicsFlags.m_Value = (unsigned int)v34;
      }
    }
    v36 = v22->ObjectCaps(this: v22);
    v37 = v22->__vftable;
    if ( (v36 & 4) != 0 )
      v39 = 1;
    else
      v39 = 3;
    goto LABEL_79;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100DB290
// Name: public: virtual void CBasePlayer::ResetObserverMode(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBasePlayer::ResetObserverMode(CBasePlayer *this)
{
  unsigned int m_Index; // eax
  edict_t *m_pPev; // ecx
  edict_t *v4; // ecx
  unsigned int v5; // esi
  edict_t *v6; // ecx

  m_Index = this->m_hObserverTarget.m_Value.m_Index;
  if ( m_Index != -1
    && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index)
    && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity != nullptr )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0xC60u);
    }
    this->m_hObserverTarget.m_Value.m_Index = -1;
  }
  if ( this->m_iObserverMode.m_Value != 0 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v4 = this->m_Network.m_pPev;
      if ( v4 != nullptr )
        CBaseEdict::StateChanged(this: &v4->CBaseEdict, offset: 0xC48u);
    }
    this->m_iObserverMode.m_Value = 0;
  }
  this->m_iObserverLastMode = 6;
  this->m_bForcedObserverMode = false;
  v5 = this->m_afPhysicsFlags.m_Value & 0xFFFFFFF7;
  if ( this->m_afPhysicsFlags.m_Value != v5 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
      this->m_afPhysicsFlags.m_Value = v5;
    }
    else
    {
      v6 = this->m_Network.m_pPev;
      if ( v6 != nullptr )
        CBaseEdict::StateChanged(this: &v6->CBaseEdict, offset: 0xBFCu);
      this->m_afPhysicsFlags.m_Value = v5;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100DB380
// Name: public: void CBasePlayer::ClearZoomOwner(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBasePlayer::ClearZoomOwner(CBasePlayer *this)
{
  unsigned int m_Index; // eax
  CNetworkHandleBase<CBaseEntity,CBasePlayer::NetworkVar_m_hZoomOwner> *p_m_hZoomOwner; // esi
  edict_t *m_pPev; // ecx

  m_Index = this->m_hZoomOwner.m_Value.m_Index;
  p_m_hZoomOwner = &this->m_hZoomOwner;
  if ( m_Index != -1
    && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index)
    && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity != nullptr )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
      p_m_hZoomOwner->m_Value.m_Index = -1;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0xC68u);
      p_m_hZoomOwner->m_Value.m_Index = -1;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100DB3F0
// Name: public: bool CBasePlayer::SetFOV(class CBaseEntity __near *,int,float,int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBasePlayer::SetFOV(
        CBasePlayer *this,
        CBaseEntity *pRequester,
        int FOV,
        float zoomRate,
        int iZoomStart)
{
  bool result; // al
  CNetworkHandleBase<CBaseEntity,CBasePlayer::NetworkVar_m_hZoomOwner> *p_m_hZoomOwner; // esi
  unsigned int m_Index; // ecx
  int v9; // eax
  CEntInfo *v10; // edx
  unsigned int v11; // ecx
  int v12; // eax
  bool v13; // zf
  CBaseEntity **v14; // eax
  CBaseEntity *v15; // eax
  CNetworkHandleBase<CBaseEntity,CBasePlayer::NetworkVar_m_hZoomOwner> v16; // eax
  CNetworkHandleBase<CBaseEntity,CBasePlayer::NetworkVar_m_hZoomOwner> *v17; // eax
  CBaseEdict *v18; // ecx
  int v19; // edi
  edict_t *m_pPev; // ecx
  CGlobalVars *v21; // edi
  edict_t *v22; // ecx
  edict_t *v23; // ecx
  CBaseEntity *pRequestera; // [esp+10h] [ebp+8h]

  if ( pRequester == nullptr )
    return false;
  p_m_hZoomOwner = &this->m_hZoomOwner;
  m_Index = this->m_hZoomOwner.m_Value.m_Index;
  if ( m_Index == -1
    || (v9 = (unsigned __int16)m_Index,
        v10 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index],
        v11 = HIWORD(m_Index),
        v10->m_SerialNumber != v11)
    || v10->m_pEntity == nullptr
    || (g_pEntityList->m_EntPtrArray[v9].m_SerialNumber != v11
      ? (pRequestera = nullptr)
      : (pRequestera = (CBaseEntity *)g_pEntityList->m_EntPtrArray[v9].m_pEntity),
        pRequestera == pRequester) )
  {
    if ( FOV != 0 )
    {
      CNetworkHandleBase<CBaseEntity,CBasePlayer::NetworkVar_m_hZoomOwner>::Set(this: p_m_hZoomOwner, val: pRequester);
    }
    else
    {
      v16.m_Value.m_Index = p_m_hZoomOwner->m_Value.m_Index;
      if ( p_m_hZoomOwner->m_Value.m_Index != -1
        && g_pEntityList->m_EntPtrArray[LOWORD(v16.m_Value.m_Index)].m_SerialNumber == HIWORD(v16.m_Value.m_Index)
        && g_pEntityList->m_EntPtrArray[LOWORD(v16.m_Value.m_Index)].m_pEntity != nullptr )
      {
        v17 = p_m_hZoomOwner - 794;
        if ( LOBYTE(p_m_hZoomOwner[-773].m_Value.m_Index) != 0 )
        {
          LOBYTE(v17[22].m_Value.m_Index) |= 1u;
          p_m_hZoomOwner->m_Value.m_Index = -1;
        }
        else
        {
          v18 = (CBaseEdict *)v17[6].m_Value.m_Index;
          if ( v18 != nullptr )
            CBaseEdict::StateChanged(this: v18, offset: 0xC68u);
          p_m_hZoomOwner->m_Value.m_Index = -1;
        }
      }
    }
  }
  else
  {
    v12 = v9;
    v13 = g_pEntityList->m_EntPtrArray[v12].m_SerialNumber == v11;
    v14 = (CBaseEntity **)&g_pEntityList->m_EntPtrArray[v12];
    if ( v13 )
      v15 = *v14;
    else
      v15 = nullptr;
    result = CanOverrideEnvZoomOwner(pZoomOwner: v15);
    if ( !result )
      return result;
  }
  v19 = iZoomStart;
  if ( iZoomStart <= 0 )
    v19 = CBasePlayer::GetFOV(this);
  if ( this->m_iFOVStart.m_Value != v19 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0xC54u);
    }
    this->m_iFOVStart.m_Value = v19;
  }
  v21 = gpGlobals;
  if ( this->m_flFOVTime.m_Value != gpGlobals->curtime )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v22 = this->m_Network.m_pPev;
      if ( v22 != nullptr )
        CBaseEdict::StateChanged(this: &v22->CBaseEdict, offset: 0xC58u);
    }
    this->m_flFOVTime.m_Value = v21->curtime;
  }
  if ( this->m_iFOV.m_Value != FOV )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v23 = this->m_Network.m_pPev;
      if ( v23 != nullptr )
        CBaseEdict::StateChanged(this: &v23->CBaseEdict, offset: 0xC4Cu);
    }
    this->m_iFOV.m_Value = FOV;
  }
  if ( this->m_Local.m_flFOVRate.m_Value != zoomRate )
  {
    this->m_Local.NetworkStateChanged(this: &this->m_Local, a2: &this->m_Local.m_flFOVRate);
    this->m_Local.m_flFOVRate.m_Value = zoomRate;
  }
  return true;
}

//------------------------------------------------------------------------------
// Address: 0x100DB5E0
// Name: public: void CBasePlayer::IncrementEFNoInterpParity(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBasePlayer::IncrementEFNoInterpParity(CBasePlayer *this)
{
  CNetworkVarBase<int,CBasePlayer::NetworkVar_m_ubEFNoInterpParity> *p_m_ubEFNoInterpParity; // esi
  int v2; // edi
  edict_t *m_pPev; // ecx

  if ( gpGlobals->maxClients != 1 )
  {
    p_m_ubEFNoInterpParity = &this->m_ubEFNoInterpParity;
    v2 = (this->m_ubEFNoInterpParity.m_Value + 1) % 4;
    if ( this->m_ubEFNoInterpParity.m_Value != v2 )
    {
      if ( this->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&this->m_Network + 76) |= 1u;
        p_m_ubEFNoInterpParity->m_Value = v2;
      }
      else
      {
        m_pPev = this->m_Network.m_pPev;
        if ( m_pPev != nullptr )
          CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x1060u);
        p_m_ubEFNoInterpParity->m_Value = v2;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100DB640
// Name: public: virtual void CBasePlayer::VPhysicsShadowUpdate(class IPhysicsObject __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CBasePlayer::VPhysicsShadowUpdate(CBasePlayer *this@<ecx>, int a2@<edi>, float pPhysics)
{
  int v4; // eax
  bool v5; // zf
  bool v6; // sf
  unsigned __int16 (__thiscall *v7)(IPhysicsObject *); // eax
  int i; // edi
  float x; // eax
  int v10; // eax
  unsigned int m_Value; // eax
  unsigned int v12; // edi
  edict_t *m_pPev; // ecx
  CBaseEntity *GroundEntity; // eax
  float v15; // edi
  void (__thiscall *v16)(IPhysicsObject *, Vector *, QAngle *); // edx
  const Vector *v17; // ebx
  IPhysicsObject *v18; // eax
  unsigned int v19; // ecx
  const Vector *v20; // eax
  float v21; // xmm0_4
  unsigned int v22; // edx
  float v23; // xmm1_4
  float v24; // xmm2_4
  unsigned int v25; // eax
  unsigned int v26; // eax
  const Vector *v27; // eax
  const Vector *v28; // eax
  float v29; // xmm0_4
  unsigned int v30; // eax
  float v31; // xmm2_4
  float v32; // xmm3_4
  float v33; // xmm4_4
  float v34; // xmm0_4
  float v35; // xmm0_4
  float v36; // xmm0_4
  const Vector *AbsVelocity; // eax
  float v38; // xmm1_4
  float v39; // xmm2_4
  int j; // edi
  float v41; // xmm2_4
  unsigned int v42; // eax
  unsigned int v43; // eax
  const Vector *v44; // [esp+4h] [ebp-F8h]
  const Vector *AbsOrigin; // [esp+8h] [ebp-F4h]
  unsigned int v46; // [esp+Ch] [ebp-F0h]
  unsigned int v47; // [esp+Ch] [ebp-F0h]
  CGameTrace trace; // [esp+28h] [ebp-D4h] BYREF
  Vector wishvel; // [esp+7Ch] [ebp-80h]
  Vector up; // [esp+88h] [ebp-74h] BYREF
  int v51; // [esp+94h] [ebp-68h]
  int v52; // [esp+98h] [ebp-64h]
  Vector lastValidPosition; // [esp+9Ch] [ebp-60h] BYREF
  float dist; // [esp+A8h] [ebp-54h]
  float deltaV; // [esp+ACh] [ebp-50h]
  Vector forward; // [esp+B0h] [ebp-4Ch] BYREF
  Vector right; // [esp+BCh] [ebp-40h] BYREF
  Vector newPosition; // [esp+C8h] [ebp-34h] BYREF
  float fmove; // [esp+D4h] [ebp-28h] BYREF
  Vector vVel; // [esp+D8h] [ebp-24h] BYREF
  float maxDistErrorSqr; // [esp+E4h] [ebp-18h]
  bool physicsUpdated; // [esp+EBh] [ebp-11h]
  Vector newVelocity; // [esp+ECh] [ebp-10h] BYREF
  bool bCheckStuck; // [esp+FBh] [ebp-1h]
  int savedregs; // [esp+FCh] [ebp+0h] BYREF

  if ( sv_turbophysics.m_pParent != nullptr && sv_turbophysics.m_pParent->m_Value.m_nValue != 0 )
    return;
  v4 = ((int (__thiscall *)(IPhysicsPlayerController *, Vector *, _DWORD, int))this->m_pPhysicsController->GetShadowPosition)(
         a1: this->m_pPhysicsController,
         a2: &newPosition,
         a3: 0,
         a4: a2);
  v5 = v4 == 0;
  v6 = v4 < 0;
  v7 = *(unsigned __int16 (__thiscall **)(IPhysicsObject *))(*(_DWORD *)LODWORD(pPhysics) + 76);
  physicsUpdated = !v6 && !v5;
  if ( (((int (__thiscall *)(_DWORD))v7)(a1: LODWORD(pPhysics)) & 0x40) != 0 )
  {
    memset((void *)&up, 0, sizeof(up));
    v51 = 0;
    v52 = 0;
    PhysGetListOfPenetratingEntities(
      pSearch: this,
      list: (CUtlVector<CBaseEntity *,CUtlMemory<CBaseEntity *,int> > *)&up);
    for ( i = v51 - 1; i >= 0; --i )
    {
      x = up.x;
      if ( *(_BYTE *)(*(_DWORD *)(LODWORD(up.x) + 4 * i) + 214) == 6 )
        this->m_bTouchedPhysObject = true;
      v10 = (*(int (__thiscall **)(_DWORD))(**(_DWORD **)(LODWORD(x) + 4 * i) + 296))(a1: *(_DWORD *)(LODWORD(x) + 4 * i));
      if ( v10 != 0 )
        (*(void (__thiscall **)(int))(*(_DWORD *)v10 + 1484))(a1: v10);
    }
    CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&up);
  }
  v5 = (this->m_afPhysicsFlags.m_Value & 0x20) == 0;
  bCheckStuck = false;
  if ( !v5 )
  {
    m_Value = this->m_afPhysicsFlags.m_Value;
    v12 = m_Value & 0xFFFFFFDF;
    bCheckStuck = true;
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
          CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0xBFCu);
      }
      this->m_afPhysicsFlags.m_Value = v12;
    }
  }
  fmove = COERCE_FLOAT(this->m_pPhysicsController->GetContactState(this: this->m_pPhysicsController, a2: 4096u));
  if ( (LOBYTE(fmove) & 1) != 0 || (this->m_afPhysicsFlags.m_Value & 0x10) != 0 )
    this->m_bTouchedPhysObject = true;
  if ( this->IsFollowingPhysics(this) )
    this->m_bTouchedPhysObject = true;
  if ( this->m_MoveType.m_Value == 8 || this->pl.deadflag.m_Value )
  {
    if ( (this->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
    this->m_oldOrigin.x = this->m_vecAbsOrigin.x;
    this->m_oldOrigin.y = this->m_vecAbsOrigin.y;
    this->m_oldOrigin.z = this->m_vecAbsOrigin.z;
  }
  else
  {
    if ( phys_timescale.m_pParent->m_Value.m_fValue == 0.0 || !physicsUpdated )
      return;
    GroundEntity = CBaseEntity::GetGroundEntity(this);
    if ( GroundEntity == nullptr
      || GroundEntity->m_MoveType.m_Value != 6
      || (v15 = *(float *)&GroundEntity->m_pPhysicsObject) == 0.0
      || (*(unsigned __int8 (__thiscall **)(float))(*(_DWORD *)LODWORD(v15) + 40))(a1: COERCE_FLOAT(LODWORD(v15))) == 0 )
    {
      v15 = 0.0;
    }
    v16 = *(void (__thiscall **)(IPhysicsObject *, Vector *, QAngle *))(*(_DWORD *)LODWORD(pPhysics) + 192);
    maxDistErrorSqr = v15;
    v16(this: (IPhysicsObject *)LODWORD(pPhysics), a2: &newPosition, a3: nullptr);
    this->m_pPhysicsController->GetShadowVelocity(this: this->m_pPhysicsController, a2: &newVelocity);
    lastValidPosition = newPosition;
    if ( physicsshadowupdate_render.m_pParent != nullptr && physicsshadowupdate_render.m_pParent->m_Value.m_nValue != 0 )
    {
      v17 = this->m_Collision.OBBMaxs(this: &this->m_Collision);
      *(float *)&v18 = COERCE_FLOAT((int)this->m_Collision.OBBMins(this: &this->m_Collision));
      v19 = (unsigned int)this->m_iEFlags >> 11;
      pPhysics = *(float *)&v18;
      if ( (v19 & 1) != 0 )
        CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
      NDebugOverlay::Box(
        origin: &this->m_vecAbsOrigin,
        mins: (const Vector *)LODWORD(pPhysics),
        maxs: v17,
        r: 255,
        g: 0,
        b: 0,
        a: 24,
        flDuration: 15.0);
      v44 = this->m_Collision.OBBMaxs(this: &this->m_Collision);
      v20 = this->m_Collision.OBBMins(this: &this->m_Collision);
      NDebugOverlay::Box(origin: &newPosition, mins: v20, maxs: v44, r: 0, g: 0, b: 255, a: 24, flDuration: 15.0);
      v15 = maxDistErrorSqr;
    }
    if ( (this->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
    v21 = this->m_vecAbsOrigin.z - newPosition.z;
    if ( !this->m_bTouchedPhysObject && (this->m_fFlags.m_Value & 1) == 0 )
      v21 = v21 * 0.5;
    v22 = (unsigned int)this->m_iEFlags >> 12;
    dist = (float)((float)((float)(this->m_vecAbsOrigin.y - newPosition.y)
                         * (float)(this->m_vecAbsOrigin.y - newPosition.y))
                 + (float)((float)(this->m_vecAbsOrigin.x - newPosition.x)
                         * (float)(this->m_vecAbsOrigin.x - newPosition.x)))
         + (float)(v21 * v21);
    if ( (v22 & 1) != 0 )
      CBaseEntity::CalcAbsoluteVelocity(this, a2: (int)&savedregs);
    v23 = (float)((float)(newVelocity.y - this->m_vecAbsVelocity.y) * (float)(newVelocity.y - this->m_vecAbsVelocity.y))
        + (float)((float)(newVelocity.x - this->m_vecAbsVelocity.x) * (float)(newVelocity.x - this->m_vecAbsVelocity.x));
    v24 = (float)(newVelocity.z - this->m_vecAbsVelocity.z) * (float)(newVelocity.z - this->m_vecAbsVelocity.z);
    maxDistErrorSqr = 4.0;
    deltaV = v23 + v24;
    pPhysics = 100.0;
    if ( CBasePlayer::IsRideablePhysics(this, pPhysics: (IPhysicsObject *)LODWORD(v15)) )
    {
      maxDistErrorSqr = 1.0;
      pPhysics = 25.0;
    }
    if ( !this->m_pPhysicsController->WasFrozen(this: this->m_pPhysicsController) )
    {
LABEL_54:
      if ( dist >= maxDistErrorSqr || deltaV >= pPhysics )
      {
        if ( this->m_bTouchedPhysObject )
        {
LABEL_65:
          if ( deltaV >= pPhysics && !this->m_bPhysicsWasFrozen )
          {
            if ( CBasePlayer::IsRideablePhysics(this, pPhysics: (IPhysicsObject *)LODWORD(v15)) )
            {
              AngleVectors(angles: &g_pMoveData->m_vecViewAngles, &forward, &right, up: (Vector *)&up.z);
              fmove = g_pMoveData->m_flForwardMove;
              pPhysics = g_pMoveData->m_flSideMove;
              v35 = (float)((float)(forward.y + forward.x) * 0.0) - (float)(forward.z * 1.0);
              forward.x = forward.x - (float)(v35 * 0.0);
              forward.y = forward.y - (float)(v35 * 0.0);
              forward.z = forward.z - (float)(v35 * -1.0);
              VectorNormalize(vec: &forward);
              v36 = (float)((float)(right.y + right.x) * 0.0) - (float)(right.z * 1.0);
              right.x = right.x - (float)(v36 * 0.0);
              right.y = right.y - (float)(v36 * 0.0);
              right.z = right.z - (float)(v36 * -1.0);
              VectorNormalize(vec: &right);
              wishvel.x = (float)(forward.x * fmove) + (float)(right.x * pPhysics);
              wishvel.y = (float)(forward.y * fmove) + (float)(right.y * pPhysics);
              wishvel.z = (float)(forward.z * fmove) + (float)(right.z * pPhysics);
              if ( (float)((float)(wishvel.y * wishvel.y) + (float)(wishvel.x * wishvel.x)) != 0.0 )
              {
                vVel.x = -newVelocity.x;
                vVel.y = -newVelocity.y;
                vVel.z = -newVelocity.z;
                AbsVelocity = CBaseEntity::GetAbsVelocity(this);
                v38 = (float)(AbsVelocity->y + wishvel.y) + vVel.y;
                v39 = (float)(AbsVelocity->z + wishvel.z) + vVel.z;
                vVel.x = (float)(AbsVelocity->x + wishvel.x) + vVel.x;
                vVel.y = v38;
                vVel.z = v39;
                for ( j = 0; j < 12; j += 4 )
                {
                  v41 = *(float *)((char *)&newVelocity.x + j);
                  pPhysics = v41 + 180.0;
                  fmove = v41 - 180.0;
                  *(float *)((char *)&vVel.x + j) = clamp<float,float,float>(
                                                      val: (const float *)((char *)&vVel.x + j),
                                                      minVal: &fmove,
                                                      maxVal: &pPhysics);
                }
                CBaseEntity::SetAbsVelocity(this, vecAbsVelocity: &vVel);
              }
            }
            else
            {
              vVel = *CBaseEntity::GetAbsVelocity(this);
              pPhysics = VectorNormalize(vec: &vVel);
              v29 = (float)((float)(vVel.y * newVelocity.y) + (float)(newVelocity.x * vVel.x))
                  + (float)(vVel.z * newVelocity.z);
              if ( v29 <= pPhysics )
              {
                if ( (float)-pPhysics > v29 )
                  v29 = -pPhysics;
              }
              else
              {
                v29 = pPhysics;
              }
              v30 = this->m_afPhysicsFlags.m_Value & 0x10;
              v31 = (float)((float)-v29 * vVel.x) + newVelocity.x;
              v32 = (float)(vVel.y * (float)-v29) + newVelocity.y;
              v33 = (float)(vVel.z * (float)-v29) + newVelocity.z;
              newVelocity.x = v31;
              newVelocity.y = v32;
              newVelocity.z = v33;
              if ( v30 != 0 )
              {
                v34 = (float)((float)((float)(v29 - pPhysics) * 0.1) + pPhysics) - pPhysics;
                newVelocity.x = (float)(v34 * vVel.x) + v31;
                newVelocity.y = (float)(vVel.y * v34) + v32;
                newVelocity.z = (float)(vVel.z * v34) + v33;
              }
              else if ( CBaseEntity::IsSimulatingOnAlternateTicks() )
              {
                newVelocity.x = newVelocity.x * 0.5;
                newVelocity.y = newVelocity.y * 0.5;
                newVelocity.z = newVelocity.z * 0.5;
              }
              CBaseEntity::ApplyAbsVelocityImpulse(this, vecImpulse: &newVelocity);
            }
          }
          v42 = this->PhysicsSolidMaskForEntity(this);
          UTIL_TraceEntity(
            pEntity: this,
            vecAbsStart: &newPosition,
            vecAbsEnd: &newPosition,
            mask: v42,
            pIgnore: this,
            nCollisionGroup: 8,
            ptr: &trace);
          if ( !trace.allsolid && !trace.startsolid )
            CBaseEntity::SetAbsOrigin(this, absOrigin: &newPosition);
          goto LABEL_84;
        }
      }
      else if ( v15 == 0.0 || this->m_bTouchedPhysObject )
      {
        if ( this->m_bTouchedPhysObject || (LOBYTE(fmove) & 2) != 0 )
        {
          v47 = this->PhysicsSolidMaskForEntity(this);
          AbsOrigin = CBaseEntity::GetAbsOrigin(this);
          v28 = CBaseEntity::GetAbsOrigin(this);
          UTIL_TraceEntity(
            pEntity: this,
            vecAbsStart: v28,
            vecAbsEnd: AbsOrigin,
            mask: v47,
            pIgnore: this,
            nCollisionGroup: 8,
            ptr: &trace);
          if ( trace.allsolid || trace.startsolid )
          {
            lastValidPosition = this->m_oldOrigin;
            CBaseEntity::SetAbsOrigin(this, absOrigin: &newPosition);
            goto LABEL_85;
          }
        }
LABEL_84:
        if ( !bCheckStuck )
        {
LABEL_92:
          if ( (this->m_iEFlags & 0x800) != 0 )
            CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
          this->m_oldOrigin.x = this->m_vecAbsOrigin.x;
          this->m_oldOrigin.y = this->m_vecAbsOrigin.y;
          this->m_oldOrigin.z = this->m_vecAbsOrigin.z;
          this->m_bPhysicsWasFrozen = false;
          return;
        }
LABEL_85:
        if ( (this->m_iEFlags & 0x800) != 0 )
          CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
        if ( (this->m_iEFlags & 0x800) != 0 )
          CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
        v43 = this->PhysicsSolidMaskForEntity(this);
        UTIL_TraceEntity(
          pEntity: this,
          vecAbsStart: &this->m_vecAbsOrigin,
          vecAbsEnd: &this->m_vecAbsOrigin,
          mask: v43,
          pIgnore: this,
          nCollisionGroup: 8,
          ptr: &trace);
        if ( trace.allsolid || trace.startsolid )
          CBaseEntity::SetAbsOrigin(this, absOrigin: &lastValidPosition);
        goto LABEL_92;
      }
      if ( v15 == 0.0 )
        goto LABEL_85;
      goto LABEL_65;
    }
    v25 = (unsigned int)this->m_iEFlags >> 11;
    this->m_bPhysicsWasFrozen = true;
    if ( (v25 & 1) != 0 )
      CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
    if ( (this->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
    v26 = this->PhysicsSolidMaskForEntity(this);
    UTIL_TraceEntity(
      pEntity: this,
      vecAbsStart: &this->m_vecAbsOrigin,
      vecAbsEnd: &this->m_vecAbsOrigin,
      mask: v26,
      pIgnore: this,
      nCollisionGroup: 8,
      ptr: &trace);
    if ( trace.startsolid )
    {
      v46 = this->PhysicsSolidMaskForEntity(this);
      v27 = CBaseEntity::GetAbsOrigin(this);
      UTIL_TraceEntity(
        pEntity: this,
        vecAbsStart: &newPosition,
        vecAbsEnd: v27,
        mask: v46,
        pIgnore: this,
        nCollisionGroup: 8,
        ptr: &trace);
      if ( !trace.startsolid )
      {
        CBaseEntity::SetAbsOrigin(this, absOrigin: &trace.endpos);
        CBasePlayer::UpdateVPhysicsPosition(
          this,
          position: &trace.endpos,
          velocity: &vec3_origin,
          secondsToArrival: 0.0);
        return;
      }
      goto LABEL_54;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100DC0A0
// Name: public: void CBasePlayer::SetPhysicsFlag(int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBasePlayer::SetPhysicsFlag(CBasePlayer *this, int nFlag, bool bSet)
{
  CNetworkVarBase<unsigned int,CBasePlayer::NetworkVar_m_afPhysicsFlags> *p_m_afPhysicsFlags; // esi
  unsigned int v4; // edi
  edict_t *m_pPev; // ecx
  unsigned int m_Value; // eax
  CNetworkVarBase<unsigned int,CBasePlayer::NetworkVar_m_afPhysicsFlags> *v7; // edi
  int v8; // esi
  edict_t *v9; // ecx

  if ( bSet )
  {
    p_m_afPhysicsFlags = &this->m_afPhysicsFlags;
    v4 = nFlag | this->m_afPhysicsFlags.m_Value;
    if ( this->m_afPhysicsFlags.m_Value != v4 )
    {
      if ( this->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&this->m_Network + 76) |= 1u;
        p_m_afPhysicsFlags->m_Value = v4;
      }
      else
      {
        m_pPev = this->m_Network.m_pPev;
        if ( m_pPev != nullptr )
          CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0xBFCu);
        p_m_afPhysicsFlags->m_Value = v4;
      }
    }
  }
  else
  {
    m_Value = this->m_afPhysicsFlags.m_Value;
    v7 = &this->m_afPhysicsFlags;
    v8 = m_Value & ~nFlag;
    if ( m_Value != v8 )
    {
      if ( this->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&this->m_Network + 76) |= 1u;
        v7->m_Value = v8;
      }
      else
      {
        v9 = this->m_Network.m_pPev;
        if ( v9 != nullptr )
          CBaseEdict::StateChanged(this: &v9->CBaseEdict, offset: 0xBFCu);
        v7->m_Value = v8;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100DC140
// Name: public: void CBasePlayer::SetVCollisionState(class Vector const __near &,class Vector const __near &,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBasePlayer::SetVCollisionState(
        CBasePlayer *this,
        const Vector *vecAbsOrigin,
        const Vector *vecAbsVelocity,
        int collisionState)
{
  edict_t *m_pPev; // ecx

  if ( this->m_vphysicsCollisionState.m_Value != collisionState )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0xC88u);
    }
    this->m_vphysicsCollisionState.m_Value = collisionState;
  }
  if ( this->m_pShadowStand != nullptr )
  {
    if ( collisionState != 0 )
    {
      if ( collisionState == 1 )
      {
        this->m_pShadowCrouch->SetPosition(this: this->m_pShadowCrouch, a2: vecAbsOrigin, a3: &vec3_angle, a4: true);
        this->m_pShadowCrouch->SetVelocity(this: this->m_pShadowCrouch, a2: vecAbsVelocity, a3: nullptr);
        this->m_pShadowStand->EnableCollisions(this: this->m_pShadowStand, a2: false);
        this->m_pPhysicsController->SetObject(this: this->m_pPhysicsController, a2: this->m_pShadowCrouch);
        CBaseEntity::VPhysicsSwapObject(this, pSwap: this->m_pShadowCrouch);
        this->m_pShadowCrouch->EnableCollisions(this: this->m_pShadowCrouch, a2: true);
      }
      else if ( collisionState == 2 )
      {
        this->m_pShadowCrouch->EnableCollisions(this: this->m_pShadowCrouch, a2: false);
        this->m_pShadowStand->EnableCollisions(this: this->m_pShadowStand, a2: false);
      }
    }
    else
    {
      this->m_pShadowStand->SetPosition(this: this->m_pShadowStand, a2: vecAbsOrigin, a3: &vec3_angle, a4: true);
      this->m_pShadowStand->SetVelocity(this: this->m_pShadowStand, a2: vecAbsVelocity, a3: nullptr);
      this->m_pShadowCrouch->EnableCollisions(this: this->m_pShadowCrouch, a2: false);
      this->m_pPhysicsController->SetObject(this: this->m_pPhysicsController, a2: this->m_pShadowStand);
      CBaseEntity::VPhysicsSwapObject(this, pSwap: this->m_pShadowStand);
      this->m_pShadowStand->EnableCollisions(this: this->m_pShadowStand, a2: true);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100DC3B0
// Name: public: virtual void CBasePlayer::SharedSpawn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBasePlayer::SharedSpawn(CBasePlayer *this)
{
  edict_t *m_pPev; // ecx
  CGlobalVars *v3; // ebx
  edict_t *v4; // ecx
  edict_t *v5; // ecx
  IMDLCache *v6; // ebx
  int v7; // eax
  int (*GetViewVectors)(void); // edx
  Vector *p_m_vDuckHullMin; // eax
  unsigned int m_Index; // eax
  edict_t *v11; // ecx
  const Vector *flFriction; // [esp+0h] [ebp-14h]
  float m_fValue; // [esp+10h] [ebp-4h]

  CBaseEntity::SetMoveType(this, val: MOVETYPE_WALK, moveCollide: MOVECOLLIDE_DEFAULT);
  CCollisionProperty::SetSolid(this: &this->m_Collision, val: SOLID_BBOX);
  CCollisionProperty::SetSolidFlags(this: &this->m_Collision, flags: this->m_Collision.m_usSolidFlags.m_Value | 0x10);
  CBaseEntity::SetFriction(this, flFriction: 1.0);
  if ( this->pl.deadflag.m_Value )
  {
    this->pl.NetworkStateChanged(this: &this->pl, a2: &this->pl.deadflag);
    this->pl.deadflag.m_Value = false;
  }
  if ( this->m_lifeState.m_Value != 0 )
  {
    this->NetworkStateChanged_m_lifeState(this, a2: &this->m_lifeState);
    this->m_lifeState.m_Value = 0;
  }
  if ( this->m_iHealth.m_Value != 100 )
  {
    this->NetworkStateChanged_m_iHealth(this, a2: &this->m_iHealth);
    this->m_iHealth.m_Value = 100;
  }
  if ( this->m_takedamage.m_Value != 2 )
  {
    this->NetworkStateChanged_m_takedamage(this, a2: &this->m_takedamage);
    this->m_takedamage.m_Value = 2;
  }
  if ( !this->m_Local.m_bDrawViewmodel.m_Value )
  {
    this->m_Local.NetworkStateChanged(this: &this->m_Local, a2: &this->m_Local.m_bDrawViewmodel);
    this->m_Local.m_bDrawViewmodel.m_Value = true;
  }
  m_fValue = sv_stepsize.m_pParent->m_Value.m_fValue;
  if ( this->m_Local.m_flStepSize.m_Value != m_fValue )
  {
    this->m_Local.NetworkStateChanged(this: &this->m_Local, a2: &this->m_Local.m_flStepSize);
    this->m_Local.m_flStepSize.m_Value = m_fValue;
  }
  if ( !this->m_Local.m_bAllowAutoMovement.m_Value )
  {
    this->m_Local.NetworkStateChanged(this: &this->m_Local, a2: &this->m_Local.m_bAllowAutoMovement);
    this->m_Local.m_bAllowAutoMovement.m_Value = true;
  }
  if ( this->m_nRenderFX.m_Value != 0 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0xB4u);
    }
    this->m_nRenderFX.m_Value = 0;
  }
  v3 = gpGlobals;
  if ( this->m_flNextAttack.m_Value != gpGlobals->curtime )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v4 = this->m_Network.m_pPev;
      if ( v4 != nullptr )
        CBaseEdict::StateChanged(this: &v4->CBaseEdict, offset: 0x684u);
    }
    this->m_flNextAttack.m_Value = v3->curtime;
  }
  if ( this->m_flMaxspeed.m_Value != 0.0 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v5 = this->m_Network.m_pPev;
      if ( v5 != nullptr )
        CBaseEdict::StateChanged(this: &v5->CBaseEdict, offset: 0xED4u);
    }
    this->m_flMaxspeed.m_Value = 0.0;
  }
  v6 = mdlcache;
  mdlcache->BeginLock(this: mdlcache);
  v7 = CBaseAnimating::SelectWeightedSequence(this, activity: ACT_IDLE);
  if ( v7 < 0 )
    v7 = 0;
  CBaseAnimating::SetSequence(this, nSequence: v7);
  GetViewVectors = (int (*)(void))g_pGameRules->GetViewVectors;
  if ( (this->m_fFlags.m_Value & 2) != 0 )
  {
    flFriction = (const Vector *)(GetViewVectors() + 48);
    p_m_vDuckHullMin = &g_pGameRules->GetViewVectors(this: g_pGameRules)->m_vDuckHullMin;
  }
  else
  {
    flFriction = (const Vector *)(GetViewVectors() + 24);
    p_m_vDuckHullMin = &g_pGameRules->GetViewVectors(this: g_pGameRules)->m_vHullMin;
  }
  CBaseEntity::SetCollisionBounds(this, mins: p_m_vDuckHullMin, maxs: flFriction);
  if ( this->m_Local.m_flFallVelocity.m_Value != 0.0 )
  {
    this->m_Local.NetworkStateChanged(this: &this->m_Local, a2: &this->m_Local.m_flFallVelocity);
    this->m_Local.m_flFallVelocity.m_Value = 0.0;
  }
  CBaseCombatCharacter::SetBloodColor(this, nBloodColor: 0);
  m_Index = this->m_hUseEntity.m_Value.m_Index;
  if ( m_Index != -1
    && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index)
    && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity != nullptr )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v11 = this->m_Network.m_pPev;
      if ( v11 != nullptr )
        CBaseEdict::StateChanged(this: &v11->CBaseEdict, offset: 0xBF0u);
    }
    this->m_hUseEntity.m_Value.m_Index = -1;
  }
  v6->EndLock(this: v6);
}

//------------------------------------------------------------------------------
// Address: 0x100DC6E0
// Name: private: void CBasePlayer::UpdateSplitScreenAndPictureInPicturePlayerList(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBasePlayer::UpdateSplitScreenAndPictureInPicturePlayerList(CBasePlayer *this)
{
  int v2; // eax
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CHandle<CBasePlayer> *m_pMemory; // ecx
  int v6; // eax
  CHandle<CBasePlayer> *v7; // eax
  int i; // [esp+8h] [ebp-8h]
  CHandle<CBasePlayer> h; // [esp+Ch] [ebp-4h] BYREF

  this->m_hSplitScreenAndPipPlayers.m_Size = 0;
  CUtlVector<CHandle<CBasePlayer>,CUtlMemory<CHandle<CBasePlayer>,int>>::AddVectorToTail(
    this: &this->m_hSplitScreenAndPipPlayers,
    src: &this->m_hSplitScreenPlayers);
  v2 = 0;
  for ( i = 0; v2 < this->m_hPipPlayers.m_Size; i = v2 )
  {
    h.m_Index = this->m_hPipPlayers.m_Memory.m_pMemory[v2].m_Index;
    if ( CUtlVector<CHandle<CSceneEntity>,CUtlMemory<CHandle<CSceneEntity>,int>>::Find(
           this: (CUtlVector<CHandle<CBaseEntity>,CUtlMemory<CHandle<CBaseEntity>,int> > *)&this->m_hSplitScreenAndPipPlayers,
           src: (CHandle<CBaseEntity> *)&h) == -1 )
    {
      m_Size = this->m_hSplitScreenAndPipPlayers.m_Size;
      m_nAllocationCount = this->m_hSplitScreenAndPipPlayers.m_Memory.m_nAllocationCount;
      if ( m_Size + 1 > m_nAllocationCount )
        CUtlMemory<CNavLadder *,int>::Grow(
          this: (CUtlMemory<vgui::TreeNode *,int> *)&this->m_hSplitScreenAndPipPlayers,
          num: m_Size - m_nAllocationCount + 1);
      ++this->m_hSplitScreenAndPipPlayers.m_Size;
      m_pMemory = this->m_hSplitScreenAndPipPlayers.m_Memory.m_pMemory;
      v6 = this->m_hSplitScreenAndPipPlayers.m_Size - m_Size - 1;
      this->m_hSplitScreenAndPipPlayers.m_pElements = m_pMemory;
      if ( v6 > 0 )
        _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v6);
      v7 = &this->m_hSplitScreenAndPipPlayers.m_Memory.m_pMemory[m_Size];
      if ( v7 != nullptr )
        v7->m_Index = h.m_Index;
    }
    v2 = i + 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100DC7D0
// Name: public: void CBasePlayer::PostThinkVPhysics(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CBasePlayer::PostThinkVPhysics(CBasePlayer *this@<ecx>, int a2@<edi>)
{
  float z; // ecx
  float v4; // xmm0_4
  CBaseEntity *GroundEntity; // eax
  IPhysicsObject *m_pPhysicsObject; // edi
  IPhysicsObject *v7; // ebx
  float v8; // xmm1_4
  float v9; // xmm2_4
  const Vector *AbsOrigin; // eax
  float v11; // xmm1_4
  float v12; // xmm2_4
  unsigned __int8 m_Value; // al
  int v14; // edi
  float m_fValue; // xmm0_4
  CMoveData *v16; // eax
  float m_outStepHeight; // xmm0_4
  IPhysicsObject *v18; // edi
  CBasePlayer_vtbl *v19; // edx
  unsigned int (__thiscall *PhysicsSolidMaskForEntity)(CBaseEntity *); // eax
  unsigned int v21; // eax
  CGameTrace trace; // [esp+18h] [ebp-7Ch] BYREF
  Vector end; // [esp+6Ch] [ebp-28h] BYREF
  Vector position; // [esp+78h] [ebp-1Ch] BYREF
  Vector newPosition; // [esp+84h] [ebp-10h]
  float frametime; // [esp+90h] [ebp-4h]
  int savedregs; // [esp+94h] [ebp+0h] BYREF

  if ( this->m_pPhysicsController != nullptr )
  {
    if ( (this->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
    z = this->m_vecAbsOrigin.z;
    *(_QWORD *)&newPosition.x = *(_QWORD *)&this->m_vecAbsOrigin.x;
    v4 = gpGlobals->frametime;
    newPosition.z = z;
    frametime = v4;
    if ( v4 <= 0.0 || v4 > 0.1 )
      frametime = 0.1;
    GroundEntity = CBaseEntity::GetGroundEntity(this);
    if ( GroundEntity != nullptr
      && GroundEntity->m_MoveType.m_Value == 6
      && (m_pPhysicsObject = GroundEntity->m_pPhysicsObject) != nullptr
      && m_pPhysicsObject->IsMoveable(this: m_pPhysicsObject) )
    {
      v7 = m_pPhysicsObject;
    }
    else
    {
      v7 = nullptr;
      if ( this->m_bTouchedPhysObject && g_pMoveData->m_outStepHeight <= 0.0 && (this->m_fFlags.m_Value & 1) != 0 )
      {
        v8 = (float)(this->m_oldOrigin.y + (float)(g_pMoveData->m_outWishVel.y * frametime)) * 0.5;
        v9 = (float)(this->m_oldOrigin.z + (float)(g_pMoveData->m_outWishVel.z * frametime)) * 0.5;
        position.x = (float)(this->m_oldOrigin.x + (float)(g_pMoveData->m_outWishVel.x * frametime)) * 0.5;
        position.y = v8;
        position.z = v9;
        AbsOrigin = CBaseEntity::GetAbsOrigin(this);
        v11 = (float)(AbsOrigin->y * 0.5) + v8;
        v12 = (float)(AbsOrigin->z * 0.5) + v9;
        newPosition.x = (float)(AbsOrigin->x * 0.5) + position.x;
        newPosition.y = v11;
        newPosition.z = v12;
      }
    }
    m_Value = this->m_MoveType.m_Value;
    if ( m_Value == 8 || m_Value == 10 )
      v14 = 2;
    else
      v14 = (this->m_fFlags.m_Value & 2) != 0;
    if ( v14 != this->m_vphysicsCollisionState.m_Value )
    {
      if ( (this->m_iEFlags & 0x1000) != 0 )
        CBaseEntity::CalcAbsoluteVelocity(this, a2: (int)&savedregs);
      if ( (this->m_iEFlags & 0x800) != 0 )
        CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
      CBasePlayer::SetVCollisionState(
        this,
        vecAbsOrigin: &this->m_vecAbsOrigin,
        vecAbsVelocity: &this->m_vecAbsVelocity,
        collisionState: v14);
    }
    if ( !this->m_bTouchedPhysObject && v7 == nullptr )
    {
      m_fValue = this->m_flMaxspeed.m_Value;
      if ( m_fValue <= 0.0 )
        m_fValue = sv_maxspeed.m_pParent->m_Value.m_fValue;
      v16 = g_pMoveData;
      g_pMoveData->m_outWishVel.x = m_fValue;
      v16->m_outWishVel.y = m_fValue;
      v16->m_outWishVel.z = m_fValue;
    }
    m_outStepHeight = g_pMoveData->m_outStepHeight;
    if ( m_outStepHeight > 0.1 )
    {
      if ( m_outStepHeight <= 4.0 )
      {
        ((void (__thiscall *)(IPhysicsObject *, Vector *, _DWORD, int))this->m_pPhysicsObject->GetPosition)(
          a1: this->m_pPhysicsObject,
          a2: &position,
          a3: 0,
          a4: a2);
        v19 = this->__vftable;
        end = position;
        PhysicsSolidMaskForEntity = v19->PhysicsSolidMaskForEntity;
        end.z = g_pMoveData->m_outStepHeight + position.z;
        v21 = PhysicsSolidMaskForEntity(this);
        UTIL_TraceEntity(
          pEntity: this,
          vecAbsStart: &position,
          vecAbsEnd: &end,
          mask: v21,
          pIgnore: this,
          nCollisionGroup: 8,
          ptr: &trace);
        if ( trace.fraction < 1.0 || trace.allsolid || trace.startsolid )
          g_pMoveData->m_outStepHeight = trace.endpos.z - position.z;
        ((void (__cdecl *)(_DWORD))this->m_pPhysicsController->StepUp)(a1: LODWORD(g_pMoveData->m_outStepHeight));
      }
      else
      {
        v18 = this->m_pPhysicsObject;
        if ( (this->m_iEFlags & 0x800) != 0 )
          CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
        v18->SetPosition(this: v18, a2: &this->m_vecAbsOrigin, a3: &vec3_angle, a4: true);
      }
      this->m_pPhysicsController->Jump(this: this->m_pPhysicsController);
    }
    g_pMoveData->m_outStepHeight = 0.0;
    this->m_vNewVPhysicsPosition = newPosition;
    this->m_vNewVPhysicsVelocity = g_pMoveData->m_outWishVel;
    if ( (this->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
    this->m_oldOrigin.x = this->m_vecAbsOrigin.x;
    this->m_oldOrigin.y = this->m_vecAbsOrigin.y;
    this->m_oldOrigin.z = this->m_vecAbsOrigin.z;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100DCBB0
// Name: public: virtual void CBasePlayer::PlayStepSound(class Vector __near &,struct surfacedata_t __near *,float,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBasePlayer::PlayStepSound(
        CBasePlayer *this,
        Vector *vecOrigin,
        surfacedata_t *psurface,
        float fvol,
        bool force)
{
  int m_nStepside; // esi
  int v7; // edi
  char *v8; // esi
  CSoundParameters *v9; // esi
  CSoundParameters *p_params; // edi
  IPhysicsSurfaceProps *v11; // eax
  const char *v12; // eax
  edict_t *m_pPev; // eax
  CSoundParameters params; // [esp+4h] [ebp-11Ch] BYREF
  CRecipientFilter filter; // [esp+B8h] [ebp-68h] BYREF
  EmitSound_t ep; // [esp+D8h] [ebp-48h] BYREF

  if ( (gpGlobals->maxClients <= 1 || sv_footsteps.m_pParent->m_Value.m_fValue != 0.0) && psurface != nullptr )
  {
    m_nStepside = this->m_Local.m_nStepside;
    v7 = m_nStepside != 0 ? psurface->sounds.runStepLeft : psurface->sounds.runStepRight;
    if ( (_WORD)v7 != 0 )
    {
      this->m_Local.m_nStepside = m_nStepside == 0;
      CSoundParameters::CSoundParameters(this: &params);
      v8 = (char *)this + 184 * m_nStepside;
      if ( *((_WORD *)v8 + 2192) == (_WORD)v7 )
      {
        v9 = (CSoundParameters *)(v8 + 4204);
        p_params = &params;
      }
      else
      {
        v11 = IMoveHelper::sm_pSingleton->GetSurfaceProps(this: IMoveHelper::sm_pSingleton);
        v12 = v11->GetString(this: v11, a2: v7);
        if ( !CBaseEntity::GetParametersForSound(soundname: v12, &params, actormodel: nullptr) )
          return;
        if ( params.count != 1 )
          goto LABEL_14;
        *((_WORD *)v8 + 2192) = v7;
        p_params = (CSoundParameters *)(v8 + 4204);
        v9 = &params;
      }
      qmemcpy(p_params, v9, sizeof(CSoundParameters));
LABEL_14:
      CRecipientFilter::CRecipientFilter(this: &filter);
      CRecipientFilter::AddRecipientsByPAS(this: &filter, origin: vecOrigin);
      EmitSound_t::EmitSound_t(this: &ep);
      ep.m_SoundLevel = params.soundlevel;
      ep.m_nSoundEntryVersion = params.m_nSoundEntryVersion;
      m_pPev = this->m_Network.m_pPev;
      ep.m_pSoundName = params.soundname;
      ep.m_nChannel = 4;
      ep.m_flVolume = fvol;
      ep.m_nFlags = 0;
      ep.m_nPitch = params.pitch;
      ep.m_pOrigin = vecOrigin;
      ep.m_hSoundScriptHandle = params.m_hSoundScriptHandle;
      if ( m_pPev != nullptr )
        m_pPev -= (int)gpGlobals->pEdicts;
      CBaseEntity::EmitSound(&filter, iEntIndex: (int)m_pPev, params: &ep);
      CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&ep.m_UtlVecSoundOrigin);
      CRecipientFilter::~CRecipientFilter(this: &filter);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100DCD40
// Name: public: void CBasePlayer::AddSplitScreenPlayer(class CBasePlayer __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBasePlayer::AddSplitScreenPlayer(CBasePlayer *this, CBasePlayer *pOther)
{
  unsigned int m_Index; // ebx
  int m_nAllocationCount; // eax
  int m_Size; // edi
  CHandle<CBasePlayer> *m_pMemory; // ecx
  int v7; // eax
  CHandle<CBasePlayer> *v8; // eax

  if ( pOther != nullptr )
    m_Index = pOther->GetRefEHandle(this: pOther)->m_Index;
  else
    m_Index = -1;
  pOther = (CBasePlayer *)m_Index;
  if ( CUtlVector<CHandle<CSceneEntity>,CUtlMemory<CHandle<CSceneEntity>,int>>::Find(
         this: (CUtlVector<CHandle<CBaseEntity>,CUtlMemory<CHandle<CBaseEntity>,int> > *)&this->m_hSplitScreenPlayers,
         src: (CHandle<CBaseEntity> *)&pOther) == -1 )
  {
    m_nAllocationCount = this->m_hSplitScreenPlayers.m_Memory.m_nAllocationCount;
    m_Size = this->m_hSplitScreenPlayers.m_Size;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<CNavLadder *,int>::Grow(
        this: (CUtlMemory<vgui::TreeNode *,int> *)&this->m_hSplitScreenPlayers,
        num: m_Size - m_nAllocationCount + 1);
    ++this->m_hSplitScreenPlayers.m_Size;
    m_pMemory = this->m_hSplitScreenPlayers.m_Memory.m_pMemory;
    v7 = this->m_hSplitScreenPlayers.m_Size - m_Size - 1;
    this->m_hSplitScreenPlayers.m_pElements = m_pMemory;
    if ( v7 > 0 )
      _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v7);
    v8 = &this->m_hSplitScreenPlayers.m_Memory.m_pMemory[m_Size];
    if ( v8 != nullptr )
      v8->m_Index = m_Index;
  }
  CBasePlayer::UpdateSplitScreenAndPictureInPicturePlayerList(this);
}

//------------------------------------------------------------------------------
// Address: 0x100DCDF0
// Name: public: void CBasePlayer::RemoveSplitScreenPlayer(class CBasePlayer __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBasePlayer::RemoveSplitScreenPlayer(CBasePlayer *this, unsigned int pOther)
{
  int v3; // eax

  if ( pOther != 0 )
    pOther = *(_DWORD *)(*(int (__thiscall **)(unsigned int))(*(_DWORD *)pOther + 8))(a1: pOther);
  else
    pOther = -1;
  v3 = CUtlVector<CHandle<CSceneEntity>,CUtlMemory<CHandle<CSceneEntity>,int>>::Find(
         this: (CUtlVector<CHandle<CBaseEntity>,CUtlMemory<CHandle<CBaseEntity>,int> > *)&this->m_hSplitScreenPlayers,
         src: (CHandle<CBaseEntity> *)&pOther);
  if ( v3 != -1 )
  {
    if ( this->m_hSplitScreenPlayers.m_Size - v3 - 1 > 0 )
      _V_memmove(
        dest: &this->m_hSplitScreenPlayers.m_Memory.m_pMemory[v3],
        src: &this->m_hSplitScreenPlayers.m_Memory.m_pMemory[v3 + 1],
        count: 4 * (this->m_hSplitScreenPlayers.m_Size - v3 - 1));
    --this->m_hSplitScreenPlayers.m_Size;
  }
  CBasePlayer::UpdateSplitScreenAndPictureInPicturePlayerList(this);
}

//------------------------------------------------------------------------------
// Address: 0x10143EE0
// Name: public: virtual float CBasePlayer::CalcRoll(class QAngle const __near &,class Vector const __near &,float,float)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CBasePlayer::CalcRoll(
        CBasePlayer *this,
        const QAngle *angles,
        const Vector *velocity,
        float rollangle,
        float rollspeed)
{
  float v5; // xmm0_4
  int v6; // eax
  float v7; // xmm0_4
  Vector forward; // [esp+0h] [ebp-24h] BYREF
  Vector up; // [esp+Ch] [ebp-18h] BYREF
  Vector right; // [esp+18h] [ebp-Ch] BYREF
  float sign; // [esp+2Ch] [ebp+8h]

  AngleVectors(angles, &forward, &right, &up);
  v5 = (float)((float)(velocity->y * right.y) + (float)(velocity->x * right.x)) + (float)(velocity->z * right.z);
  if ( v5 >= 0.0 )
    v6 = 1;
  else
    v6 = -1;
  LODWORD(v7) = LODWORD(v5) & _mask__AbsFloat_;
  sign = (float)v6;
  if ( rollspeed <= v7 )
    return sign * rollangle;
  else
    return sign * (float)((float)(v7 * rollangle) / rollspeed);
}

} // namespace server
